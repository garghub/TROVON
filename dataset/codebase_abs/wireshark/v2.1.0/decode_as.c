void F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
F_2 ( V_1 -> V_3 ) ;
F_2 ( V_1 -> V_4 ) ;
F_2 ( V_1 -> V_5 ) ;
V_2 = F_3 ( V_1 -> V_6 ) ;
if ( V_2 != NULL )
{
if ( ( F_4 ( V_2 ) != V_7 ) &&
( F_5 ( V_2 ) != V_8 ) )
{
fprintf ( V_9 , L_1 , V_1 -> V_6 ) ;
if ( getenv ( L_2 ) != NULL )
abort () ;
}
}
V_10 = F_6 ( V_10 , V_1 ) ;
}
static void
F_7 ( const T_3 * V_6 , T_4 V_11 , T_4 V_12 )
{
struct V_13 * V_14 = (struct V_13 * ) V_12 ;
const T_3 * V_15 ;
T_5 V_16 ;
T_6 V_17 ;
V_17 = ( T_6 ) V_11 ;
V_15 = F_8 ( V_17 ) ;
V_16 = F_9 ( V_17 ) ;
if ( V_16 >= 0 && ! F_10 ( F_11 ( V_16 ) ) )
return;
V_14 -> V_18 ( V_6 , V_15 , V_11 , V_14 -> V_19 ) ;
}
void F_12 ( const T_3 * V_6 , T_7 V_18 , T_4 V_19 )
{
struct V_13 V_14 ;
V_14 . V_18 = V_18 ;
V_14 . V_19 = V_19 ;
F_13 ( V_6 , F_7 , & V_14 ) ;
}
T_8 F_14 ( const T_3 * V_20 , T_9 V_21 )
{
switch ( F_15 ( V_20 ) ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
F_16 ( V_20 , F_17 ( V_21 ) ) ;
return TRUE ;
case V_7 :
case V_26 :
case V_27 :
case V_28 :
F_18 ( V_20 , ( ! V_21 ) ? L_3 : ( T_3 * ) V_21 ) ;
return TRUE ;
default:
return FALSE ;
} ;
return TRUE ;
}
T_8 F_19 ( const T_3 * V_20 , T_9 V_21 , T_4 V_17 , T_3 * T_10 V_29 )
{
T_6 * V_30 = ( T_6 * ) V_17 ;
if ( V_30 != NULL ) {
switch ( F_15 ( V_20 ) ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
F_20 ( V_20 , F_17 ( V_21 ) , * V_30 ) ;
return TRUE ;
case V_7 :
case V_26 :
case V_27 :
case V_28 :
F_21 ( V_20 , ( ! V_21 ) ? L_3 : ( T_3 * ) V_21 , * V_30 ) ;
return TRUE ;
default:
return FALSE ;
} ;
return FALSE ;
}
return TRUE ;
}
