int mpi_invm(MPI x, const MPI a, const MPI n)
{
MPI u = NULL, v = NULL;
MPI u1 = NULL, u2 = NULL, u3 = NULL;
MPI v1 = NULL, v2 = NULL, v3 = NULL;
MPI t1 = NULL, t2 = NULL, t3 = NULL;
unsigned k;
int sign;
int odd = 0;
int rc = -ENOMEM;
if (mpi_copy(&u, a) < 0)
goto cleanup;
if (mpi_copy(&v, n) < 0)
goto cleanup;
for (k = 0; !mpi_test_bit(u, 0) && !mpi_test_bit(v, 0); k++) {
if (mpi_rshift(u, u, 1) < 0)
goto cleanup;
if (mpi_rshift(v, v, 1) < 0)
goto cleanup;
}
odd = mpi_test_bit(v, 0);
u1 = mpi_alloc_set_ui(1);
if (!u1)
goto cleanup;
if (!odd) {
u2 = mpi_alloc_set_ui(0);
if (!u2)
goto cleanup;
}
if (mpi_copy(&u3, u) < 0)
goto cleanup;
if (mpi_copy(&v1, v) < 0)
goto cleanup;
if (!odd) {
v2 = mpi_alloc(mpi_get_nlimbs(u));
if (!v2)
goto cleanup;
if (mpi_sub(v2, u1, u) < 0)
goto cleanup;
}
if (mpi_copy(&v3, v) < 0)
goto cleanup;
if (mpi_test_bit(u, 0)) {
t1 = mpi_alloc_set_ui(0);
if (!t1)
goto cleanup;
if (!odd) {
t2 = mpi_alloc_set_ui(1);
if (!t2)
goto cleanup;
t2->sign = 1;
}
if (mpi_copy(&t3, v) < 0)
goto cleanup;
t3->sign = !t3->sign;
goto Y4;
} else {
t1 = mpi_alloc_set_ui(1);
if (!t1)
goto cleanup;
if (!odd) {
t2 = mpi_alloc_set_ui(0);
if (!t2)
goto cleanup;
}
if (mpi_copy(&t3, u) < 0)
goto cleanup;
}
do {
do {
if (!odd) {
if (mpi_test_bit(t1, 0) || mpi_test_bit(t2, 0)) {
if (mpi_add(t1, t1, v) < 0)
goto cleanup;
if (mpi_sub(t2, t2, u) < 0)
goto cleanup;
}
if (mpi_rshift(t1, t1, 1) < 0)
goto cleanup;
if (mpi_rshift(t2, t2, 1) < 0)
goto cleanup;
if (mpi_rshift(t3, t3, 1) < 0)
goto cleanup;
} else {
if (mpi_test_bit(t1, 0))
if (mpi_add(t1, t1, v) < 0)
goto cleanup;
if (mpi_rshift(t1, t1, 1) < 0)
goto cleanup;
if (mpi_rshift(t3, t3, 1) < 0)
goto cleanup;
}
Y4:
;
} while (!mpi_test_bit(t3, 0));
if (!t3->sign) {
if (mpi_set(u1, t1) < 0)
goto cleanup;
if (!odd)
if (mpi_set(u2, t2) < 0)
goto cleanup;
if (mpi_set(u3, t3) < 0)
goto cleanup;
} else {
if (mpi_sub(v1, v, t1) < 0)
goto cleanup;
sign = u->sign;
u->sign = !u->sign;
if (!odd)
if (mpi_sub(v2, u, t2) < 0)
goto cleanup;
u->sign = sign;
sign = t3->sign;
t3->sign = !t3->sign;
if (mpi_set(v3, t3) < 0)
goto cleanup;
t3->sign = sign;
}
if (mpi_sub(t1, u1, v1) < 0)
goto cleanup;
if (!odd)
if (mpi_sub(t2, u2, v2) < 0)
goto cleanup;
if (mpi_sub(t3, u3, v3) < 0)
goto cleanup;
if (t1->sign) {
if (mpi_add(t1, t1, v) < 0)
goto cleanup;
if (!odd)
if (mpi_sub(t2, t2, u) < 0)
goto cleanup;
}
} while (mpi_cmp_ui(t3, 0));
rc = mpi_set(x, u1);
cleanup:
mpi_free(u1);
mpi_free(v1);
mpi_free(t1);
if (!odd) {
mpi_free(u2);
mpi_free(v2);
mpi_free(t2);
}
mpi_free(u3);
mpi_free(v3);
mpi_free(t3);
mpi_free(u);
mpi_free(v);
return rc;
}
