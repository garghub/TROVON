static void F_1 ( enum V_1 V_2 )
{
static void T_1 * V_3 ;
V_3 = F_2 ( V_4 , 0 ) ;
if ( ! V_3 ) {
F_3 ( L_1 , V_5 ) ;
goto exit;
}
switch ( V_2 ) {
case V_6 :
F_4 ( V_3 + V_7 , V_8 ) ;
break;
case V_9 :
F_5 ( V_3 + V_7 , 0x01 << 8 ) ;
F_5 ( V_3 + V_7 , 0x01 << 4 ) ;
F_5 ( V_3 + V_7 , V_10 ) ;
break;
default:
F_3 ( L_2 , V_5 , V_2 ) ;
}
F_6 ( V_3 ) ;
exit:
F_7 ( V_4 ) ;
}
static void F_8 ( unsigned int V_11 )
{
struct V_12 * V_13 ;
void T_1 * V_14 ;
unsigned long V_15 ;
T_2 V_16 ;
T_3 V_17 ;
V_13 = F_9 ( NULL , NULL , L_3 ) ;
if ( ! V_13 ) {
F_3 ( L_4 ,
V_5 ) ;
return;
}
V_14 = F_2 ( V_13 , 0 ) ;
F_7 ( V_13 ) ;
if ( ! V_14 ) {
F_3 ( L_5 ,
V_5 ) ;
return;
}
V_16 = 1000000000000ULL ;
F_10 ( V_16 , V_11 ) ;
V_15 = V_16 ;
V_17 = F_11 ( F_12 () , V_15 ) ;
V_17 = F_13 ( T_3 , V_17 , 2 , 255 ) ;
F_14 ( V_14 + V_18 ,
V_19 | V_20 | V_21 ) ;
F_15 ( V_14 + V_18 , V_19 | ( V_17 << 16 ) ) ;
F_6 ( V_14 ) ;
}
static enum V_1
F_16 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_6 :
case V_9 :
return V_2 ;
default:
return V_6 ;
}
}
static int T_4 F_17 ( void )
{
V_4 = F_9 ( NULL , NULL , L_6 ) ;
if ( ! V_4 )
return 0 ;
V_22 . V_23 = F_1 ;
V_22 . V_24 = F_8 ;
V_22 . V_25 = F_16 ;
return 0 ;
}
