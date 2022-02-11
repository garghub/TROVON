static void F_1 ( const char * V_1 ,
struct V_2 * V_3 )
{
int V_4 , V_5 ;
const char * V_6 = NULL ;
V_5 = ( V_3 -> V_5 & ~ V_3 -> V_7 ) ;
for ( V_4 = 0 ; V_4 < 32 ; V_4 ++ ) {
if ( ! ( V_5 & ( 1 << V_4 ) ) )
continue;
if ( V_3 -> V_8 == V_9 )
V_6 = V_4 < F_2 ( V_10 ) ?
V_10 [ V_4 ] : NULL ;
else
V_6 = V_4 < F_2 ( V_11 ) ?
V_11 [ V_4 ] : NULL ;
if ( V_6 )
F_3 ( L_1 [ % 2d ] % - 22s % V_12 \ V_13 L_2 ( V_14 ) L_3 ) ;
else
F_3 ( L_1 [%2d] Unknown Error Bit%s\nL_4 (First)L_3 ) ;
}
}
static int F_4 ( int V_15 )
{
switch ( V_15 ) {
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
default:
return V_9 ;
}
}
void F_5 ( const char * V_1 , int V_15 ,
struct V_20 * V_21 )
{
int V_22 , V_23 , V_24 , V_25 , V_26 = 0 ;
T_1 V_5 , V_7 ;
const char * * V_27 ;
V_22 = F_4 ( V_15 ) ;
if ( V_22 == V_9 ) {
V_5 = V_21 -> V_28 ;
V_7 = V_21 -> V_29 ;
V_27 = V_10 ;
V_25 = F_2 ( V_10 ) ;
} else {
V_5 = V_21 -> V_30 ;
V_7 = V_21 -> V_31 ;
V_27 = V_11 ;
V_25 = F_2 ( V_11 ) ;
V_26 = V_5 & V_32 ;
}
V_23 = F_6 ( V_22 , V_5 ) ;
V_24 = F_7 ( V_22 , V_5 ) ;
F_3 ( L_1aer_status: 0x%08x , aer_mask: 0x%08x\nL_5%sL_6aer_layer=%s, aer_agent=%s\nL_7%sL_6aer_uncor_severity: 0x%08x\nL_8%sL_6aer_tlp_header:L_9 %02x%02x%02x%02x %02x%02x%02x%02x L_9 %02x%02x%02x%02x %02x%02x%02x%02x\n"
