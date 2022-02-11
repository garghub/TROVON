int F_1 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_4 ) {
F_2 ( V_5 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_8 ;
if ( ! V_1 -> V_3 -> V_9 )
return 1 ;
V_2 = V_1 -> V_3 -> V_9 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_3 ( T_1 * V_1 ,
unsigned char * V_11 , T_2 * V_12 ,
const unsigned char * V_13 , T_2 V_14 )
{
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_4 ) {
F_2 ( V_15 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_8 ) {
F_2 ( V_15 , V_16 ) ;
return - 1 ;
}
F_4 (ctx, sig, siglen, EVP_F_EVP_PKEY_SIGN)
return V_1 -> V_3 -> V_4 ( V_1 , V_11 , V_12 , V_13 , V_14 ) ;
}
int F_5 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_17 ) {
F_2 ( V_18 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_19 ;
if ( ! V_1 -> V_3 -> V_20 )
return 1 ;
V_2 = V_1 -> V_3 -> V_20 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_6 ( T_1 * V_1 ,
const unsigned char * V_11 , T_2 V_12 ,
const unsigned char * V_13 , T_2 V_14 )
{
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_17 ) {
F_2 ( V_21 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_19 ) {
F_2 ( V_21 , V_16 ) ;
return - 1 ;
}
return V_1 -> V_3 -> V_17 ( V_1 , V_11 , V_12 , V_13 , V_14 ) ;
}
int F_7 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_22 ) {
F_2 ( V_23 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_24 ;
if ( ! V_1 -> V_3 -> V_25 )
return 1 ;
V_2 = V_1 -> V_3 -> V_25 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_8 ( T_1 * V_1 ,
unsigned char * V_26 , T_2 * V_27 ,
const unsigned char * V_11 , T_2 V_12 )
{
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_22 ) {
F_2 ( V_28 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_24 ) {
F_2 ( V_28 , V_16 ) ;
return - 1 ;
}
F_4 (ctx, rout, routlen, EVP_F_EVP_PKEY_VERIFY_RECOVER)
return V_1 -> V_3 -> V_22 ( V_1 , V_26 , V_27 , V_11 , V_12 ) ;
}
int F_9 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_29 ) {
F_2 ( V_30 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_31 ;
if ( ! V_1 -> V_3 -> V_32 )
return 1 ;
V_2 = V_1 -> V_3 -> V_32 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_10 ( T_1 * V_1 ,
unsigned char * V_33 , T_2 * V_34 ,
const unsigned char * V_35 , T_2 V_36 )
{
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_29 ) {
F_2 ( V_37 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_31 ) {
F_2 ( V_37 , V_16 ) ;
return - 1 ;
}
F_4 (ctx, out, outlen, EVP_F_EVP_PKEY_ENCRYPT)
return V_1 -> V_3 -> V_29 ( V_1 , V_33 , V_34 , V_35 , V_36 ) ;
}
int F_11 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_38 ) {
F_2 ( V_39 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_40 ;
if ( ! V_1 -> V_3 -> V_41 )
return 1 ;
V_2 = V_1 -> V_3 -> V_41 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_12 ( T_1 * V_1 ,
unsigned char * V_33 , T_2 * V_34 ,
const unsigned char * V_35 , T_2 V_36 )
{
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_38 ) {
F_2 ( V_42 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_40 ) {
F_2 ( V_42 , V_16 ) ;
return - 1 ;
}
F_4 (ctx, out, outlen, EVP_F_EVP_PKEY_DECRYPT)
return V_1 -> V_3 -> V_38 ( V_1 , V_33 , V_34 , V_35 , V_36 ) ;
}
int F_13 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_43 ) {
F_2 ( V_44 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_45 ;
if ( ! V_1 -> V_3 -> V_46 )
return 1 ;
V_2 = V_1 -> V_3 -> V_46 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_14 ( T_1 * V_1 , T_3 * V_47 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3
|| ! ( V_1 -> V_3 -> V_43 || V_1 -> V_3 -> V_29 || V_1 -> V_3 -> V_38 )
|| ! V_1 -> V_3 -> V_48 ) {
F_2 ( V_49 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_45
&& V_1 -> V_7 != V_31
&& V_1 -> V_7 != V_40 ) {
F_2 ( V_49 ,
V_16 ) ;
return - 1 ;
}
V_2 = V_1 -> V_3 -> V_48 ( V_1 , V_50 , 0 , V_47 ) ;
if ( V_2 <= 0 )
return V_2 ;
if ( V_2 == 2 )
return 1 ;
if ( ! V_1 -> V_51 ) {
F_2 ( V_49 , V_52 ) ;
return - 1 ;
}
if ( V_1 -> V_51 -> type != V_47 -> type ) {
F_2 ( V_49 , V_53 ) ;
return - 1 ;
}
if ( ! F_15 ( V_47 ) &&
! F_16 ( V_1 -> V_51 , V_47 ) ) {
F_2 ( V_49 , V_54 ) ;
return - 1 ;
}
F_17 ( V_1 -> V_55 ) ;
V_1 -> V_55 = V_47 ;
V_2 = V_1 -> V_3 -> V_48 ( V_1 , V_50 , 1 , V_47 ) ;
if ( V_2 <= 0 ) {
V_1 -> V_55 = NULL ;
return V_2 ;
}
F_18 ( V_47 ) ;
return 1 ;
}
int F_19 ( T_1 * V_1 , unsigned char * V_56 , T_2 * V_57 )
{
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_43 ) {
F_2 ( V_58 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_45 ) {
F_2 ( V_58 , V_16 ) ;
return - 1 ;
}
F_4 (ctx, key, pkeylen, EVP_F_EVP_PKEY_DERIVE)
return V_1 -> V_3 -> V_43 ( V_1 , V_56 , V_57 ) ;
}
