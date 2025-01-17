/*
 * Copyright (c) 2021 Linaro
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ztest.h>

/* tests_meas.c */
extern void test_mes_check_header(void);
extern void test_mes_check_payload(void);
extern void test_mes_check_sample_count(void);
extern void test_mes_check_payload_sz(void);

/* tests_filter.c */
extern void test_filter_evaluate_fc_null(void);
extern void test_filter_evaluate_mes_null(void);
extern void test_filter_evaluate_fc_len(void);
extern void test_filter_evaluate_fc_bad_op0(void);
extern void test_filter_evaluate_match_good(void);
extern void test_filter_evaluate_match_bad(void);

/* tests_proc.c */
extern void test_proc_reg_limit(void);
extern void test_proc_manual(void);
extern void test_proc_manual_non_alloc(void);
extern void test_proc_thread(void);
extern void test_proc_get_node(void);

/* tests_sample_pool.c */
extern void test_sp_alloc(void);
extern void test_sp_alloc_limit(void);
extern void test_sp_fifo(void);

void test_main(void)
{
	ztest_test_suite(step_tests,
		ztest_unit_test(test_mes_check_header),
		ztest_unit_test(test_mes_check_payload),
		ztest_unit_test(test_mes_check_sample_count),
		ztest_unit_test(test_mes_check_payload_sz),

		ztest_unit_test(test_filter_evaluate_fc_null),
		ztest_unit_test(test_filter_evaluate_mes_null),
		ztest_unit_test(test_filter_evaluate_fc_len),
		ztest_unit_test(test_filter_evaluate_fc_bad_op0),
		ztest_unit_test(test_filter_evaluate_match_good),
		ztest_unit_test(test_filter_evaluate_match_bad),

		ztest_unit_test(test_proc_reg_limit),
		ztest_unit_test(test_proc_manual),
		ztest_unit_test(test_proc_manual_non_alloc),
		ztest_unit_test(test_proc_thread),
		ztest_unit_test(test_proc_get_node),
		
		ztest_unit_test(test_sp_alloc),
		ztest_unit_test(test_sp_alloc_limit),
		ztest_unit_test(test_sp_fifo)
	);

	/* Test suites. */
	ztest_run_test_suite(step_tests);
}
