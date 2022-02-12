static void decc_init(void)
{
char *openssl_debug_decc_init;
int verbose = 0;
int feat_index;
int feat_value;
int feat_value_max;
int feat_value_min;
int i;
int sts;
openssl_debug_decc_init = getenv("OPENSSL_DEBUG_DECC_INIT");
if (openssl_debug_decc_init != NULL) {
verbose = strtol(openssl_debug_decc_init, NULL, 10);
if (verbose <= 0) {
verbose = 1;
}
}
decc_init_done = 1;
for (i = 0; decc_feat_array[i].name != NULL; i++) {
feat_index = decc$feature_get_index(decc_feat_array[i].name);
if (feat_index >= 0) {
feat_value = decc$feature_get_value(feat_index, 1);
feat_value_min = decc$feature_get_value(feat_index, 2);
feat_value_max = decc$feature_get_value(feat_index, 3);
if ((decc_feat_array[i].value >= feat_value_min) &&
(decc_feat_array[i].value <= feat_value_max)) {
if (feat_value != decc_feat_array[i].value) {
sts = decc$feature_set_value(feat_index,
1, decc_feat_array[i].value);
if (verbose > 1) {
fprintf(stderr, " %s = %d, sts = %d.\n",
decc_feat_array[i].name,
decc_feat_array[i].value, sts);
}
}
} else {
fprintf(stderr,
" INVALID DECC$FEATURE VALUE, %d: %d <= %s <= %d.\n",
feat_value,
feat_value_min, decc_feat_array[i].name,
feat_value_max);
}
} else {
fprintf(stderr,
" UNKNOWN DECC$FEATURE: %s.\n", decc_feat_array[i].name);
}
}
if (verbose > 0) {
fprintf(stderr, " DECC_INIT complete.\n");
}
}
