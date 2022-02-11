void F_1 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_2 ) ;
F_2 ( V_1 -> V_3 ) ;
F_2 ( V_1 -> V_4 ) ;
V_5 = F_3 ( V_5 , V_1 ) ;
}
static void
F_4 ( const T_2 * V_6 , T_3 V_7 , T_3 V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_8 ;
const T_2 * V_11 ;
T_4 V_12 ;
T_5 V_13 ;
V_13 = ( T_5 ) V_7 ;
V_11 = F_5 ( V_13 ) ;
V_12 = F_6 ( V_13 ) ;
if ( V_12 >= 0 && ! F_7 ( F_8 ( V_12 ) ) )
return;
V_10 -> V_14 ( V_6 , V_11 , V_7 , V_10 -> V_15 ) ;
}
void F_9 ( const T_2 * V_6 , T_6 V_14 , T_3 V_15 )
{
struct V_9 V_10 ;
V_10 . V_14 = V_14 ;
V_10 . V_15 = V_15 ;
F_10 ( V_6 , F_4 , & V_10 ) ;
}
T_7 F_11 ( const char * V_16 , const T_3 V_17 )
{
switch ( F_12 ( V_16 ) ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
F_13 ( V_16 , F_14 ( V_17 ) ) ;
return TRUE ;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
F_15 ( V_16 , ( ! V_17 ) ? L_1 : ( T_2 * ) V_17 ) ;
return TRUE ;
default:
return FALSE ;
} ;
return TRUE ;
}
T_7 F_16 ( const char * V_16 , const T_3 V_17 , T_3 V_13 , T_2 * T_8 V_26 )
{
T_5 * V_27 = ( T_5 * ) V_13 ;
if ( V_27 != NULL ) {
switch ( F_12 ( V_16 ) ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
F_17 ( V_16 , F_14 ( V_17 ) , * V_27 ) ;
return TRUE ;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
F_18 ( V_16 , ( ! V_17 ) ? L_1 : ( T_2 * ) V_17 , * V_27 ) ;
return TRUE ;
default:
return FALSE ;
} ;
return FALSE ;
}
return TRUE ;
}
