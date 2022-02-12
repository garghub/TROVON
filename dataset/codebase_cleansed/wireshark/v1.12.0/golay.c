static guint weight12(guint vector)
{
guint w=0;
guint i;
for( i=0; i<12; i++ )
if( vector & 1<<i )
w++;
return w;
}
static guint golay_coding(guint w)
{
guint out=0;
guint i;
for( i = 0; i<12; i++ ) {
if( w & 1<<i )
out ^= golay_encode_matrix[i];
}
return out;
}
guint32 golay_encode(guint w)
{
return ((guint32)w) | ((guint32)golay_coding(w))<<12;
}
static guint golay_decoding(guint w)
{
guint out=0;
guint i;
for( i = 0; i<12; i++ ) {
if( w & 1<<(i) )
out ^= golay_decode_matrix[i];
}
return out;
}
gint32 golay_errors(guint32 codeword)
{
guint received_data, received_parity;
guint syndrome;
guint w,i;
guint inv_syndrome = 0;
received_parity = (guint)(codeword>>12);
received_data = (guint)codeword & 0xfff;
syndrome = received_parity ^ (golay_coding(received_data));
w = weight12(syndrome);
if( w <= 3 ) {
return ((gint32) syndrome)<<12;
}
for( i = 0; i<12; i++ ) {
guint error = 1<<i;
guint coding_error = golay_encode_matrix[i];
if( weight12(syndrome^coding_error) <= 2 ) {
return (gint32)((((guint32)(syndrome^coding_error))<<12) | (guint32)error) ;
}
}
inv_syndrome = golay_decoding(syndrome);
w = weight12(inv_syndrome);
if( w <=3 ) {
return (gint32)inv_syndrome;
}
for( i = 0; i<12; i++ ) {
guint error = 1<<i;
guint coding_error = golay_decode_matrix[i];
if( weight12(inv_syndrome^coding_error) <= 2 ) {
guint32 error_word = ((guint32)(inv_syndrome^coding_error)) | ((guint32)error)<<12;
return (gint32)error_word;
}
}
return -1;
}
gint golay_decode(guint32 w)
{
guint data = (guint)w & 0xfff;
gint32 errors = golay_errors(w);
guint data_errors;
if( errors == -1 )
return -1;
data_errors = (guint)errors & 0xfff;
return (gint)(data ^ data_errors);
}
