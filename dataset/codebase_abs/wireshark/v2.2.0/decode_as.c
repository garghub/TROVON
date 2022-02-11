void F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
F_2 ( V_1 -> V_3 ) ;
F_2 ( V_1 -> V_4 ) ;
F_2 ( V_1 -> V_5 ) ;
V_2 = F_3 ( V_1 -> V_6 ) ;
if ( V_2 != NULL )
{
F_4 ( V_2 ) ;
}
V_7 = F_5 ( V_7 , V_1 ) ;
}
static void
F_6 ( const T_3 * V_6 , T_4 V_8 , T_4 V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
const T_3 * V_12 ;
T_5 V_13 ;
T_6 V_14 ;
V_14 = ( T_6 ) V_8 ;
V_12 = F_7 ( V_14 ) ;
V_13 = F_8 ( V_14 ) ;
if ( V_13 >= 0 && ! F_9 ( F_10 ( V_13 ) ) )
return;
V_11 -> V_15 ( V_6 , V_12 , V_8 , V_11 -> V_16 ) ;
}
void F_11 ( const T_3 * V_6 , T_7 V_15 , T_4 V_16 )
{
struct V_10 V_11 ;
V_11 . V_15 = V_15 ;
V_11 . V_16 = V_16 ;
F_12 ( V_6 , F_6 , & V_11 ) ;
}
T_8 F_13 ( const T_3 * V_17 , T_9 V_18 )
{
switch ( F_14 ( V_17 ) ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_15 ( V_17 , F_16 ( V_18 ) ) ;
return TRUE ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
F_17 ( V_17 , ( ! V_18 ) ? L_1 : ( T_3 * ) V_18 ) ;
return TRUE ;
default:
return FALSE ;
} ;
return TRUE ;
}
T_8 F_18 ( const T_3 * V_17 , T_9 V_18 , T_4 V_14 , T_3 * T_10 V_27 )
{
T_6 * V_28 = ( T_6 * ) V_14 ;
if ( V_28 != NULL ) {
switch ( F_14 ( V_17 ) ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_19 ( V_17 , F_16 ( V_18 ) , * V_28 ) ;
return TRUE ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
F_20 ( V_17 , ( ! V_18 ) ? L_1 : ( T_3 * ) V_18 , * V_28 ) ;
return TRUE ;
default:
return FALSE ;
} ;
return FALSE ;
}
return TRUE ;
}
