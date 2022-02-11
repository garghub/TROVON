static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
F_5 ( & V_9 -> V_11 ) ;
V_9 -> V_12 ++ ;
V_9 -> V_13 += V_2 -> V_14 ;
F_6 ( & V_9 -> V_11 ) ;
V_4 = V_2 -> V_15 ;
V_2 -> V_15 = V_5 ;
return F_7 ( V_16 , V_17 , V_2 , V_4 , NULL ,
V_18 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
const unsigned char * V_19 = F_9 ( V_2 ) -> V_20 ;
struct V_21 * V_22 = F_10 ( V_2 -> V_15 ) ;
struct V_6 * V_7 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_1 * V_27 ;
if ( ! V_22 || V_22 -> V_28 == V_29 )
goto V_30;
V_7 = V_22 -> V_7 ;
F_11 ( V_7 , V_22 , F_9 ( V_2 ) -> V_31 ) ;
if ( ! F_12 ( V_19 ) && F_13 ( V_19 ) &&
F_14 ( V_7 , V_22 , V_2 ) )
goto V_30;
if ( V_22 -> V_28 == V_32 )
goto V_30;
F_2 ( V_2 ) -> V_5 = V_7 -> V_15 ;
V_27 = NULL ;
if ( V_7 -> V_15 -> V_33 & V_34 )
V_27 = V_2 ;
V_24 = NULL ;
if ( F_12 ( V_19 ) )
V_27 = V_2 ;
else if ( F_13 ( V_19 ) ) {
V_26 = F_15 ( V_7 , V_2 ) ;
if ( V_26 || F_16 ( V_2 ) ) {
if ( ( V_26 && V_26 -> V_35 ) ||
F_17 ( V_7 ) )
V_27 = V_2 ;
F_18 ( V_26 , V_2 , V_27 ) ;
V_2 = NULL ;
if ( ! V_27 )
goto V_36;
} else
V_27 = V_2 ;
V_7 -> V_15 -> V_10 . V_37 ++ ;
} else if ( ( V_24 = F_19 ( V_7 , V_19 ) ) && V_24 -> V_38 ) {
V_27 = V_2 ;
V_2 = NULL ;
}
if ( V_2 ) {
if ( V_24 ) {
V_24 -> V_39 = V_40 ;
F_20 ( V_24 -> V_24 , V_2 , V_27 ) ;
} else
F_21 ( V_7 , V_2 , V_27 ) ;
}
if ( V_27 )
return F_1 ( V_27 ) ;
V_36:
return 0 ;
V_30:
F_22 ( V_2 ) ;
goto V_36;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_10 ( V_2 -> V_15 ) ;
F_11 ( V_22 -> V_7 , V_22 , F_9 ( V_2 ) -> V_31 ) ;
return 0 ;
}
static inline int F_24 ( const unsigned char * V_19 )
{
T_1 * V_41 = ( T_1 * ) V_19 ;
static const T_1 * V_42 = ( const T_1 * ) V_43 ;
static const T_1 V_44 = F_25 ( 0xfff0 ) ;
return ( ( V_41 [ 0 ] ^ V_42 [ 0 ] ) | ( V_41 [ 1 ] ^ V_42 [ 1 ] ) | ( ( V_41 [ 2 ] ^ V_42 [ 2 ] ) & V_44 ) ) == 0 ;
}
T_2 F_26 ( struct V_1 * * V_45 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 = * V_45 ;
const unsigned char * V_19 = F_9 ( V_2 ) -> V_20 ;
T_3 * V_46 ;
if ( F_27 ( V_2 -> V_47 == V_48 ) )
return V_49 ;
if ( ! F_28 ( F_9 ( V_2 ) -> V_31 ) )
goto V_30;
V_2 = F_29 ( V_2 , V_50 ) ;
if ( ! V_2 )
return V_51 ;
V_22 = F_10 ( V_2 -> V_15 ) ;
if ( F_27 ( F_24 ( V_19 ) ) ) {
switch ( V_19 [ 5 ] ) {
case 0x00 :
if ( V_22 -> V_7 -> V_52 == V_53 )
goto V_54;
break;
case 0x01 :
goto V_30;
default:
if ( V_22 -> V_7 -> V_55 & ( 1u << V_19 [ 5 ] ) )
goto V_54;
}
if ( F_7 ( V_16 , V_17 , V_2 , V_2 -> V_15 ,
NULL , F_23 ) ) {
return V_51 ;
} else {
* V_45 = V_2 ;
return V_49 ;
}
}
V_54:
switch ( V_22 -> V_28 ) {
case V_56 :
V_46 = F_30 ( V_57 ) ;
if ( V_46 ) {
if ( (* V_46)( V_2 ) ) {
* V_45 = V_2 ;
return V_49 ;
}
V_19 = F_9 ( V_2 ) -> V_20 ;
}
case V_32 :
if ( ! F_31 ( V_22 -> V_7 -> V_15 -> V_58 , V_19 ) )
V_2 -> V_47 = V_59 ;
F_7 ( V_16 , V_60 , V_2 , V_2 -> V_15 , NULL ,
F_8 ) ;
break;
default:
V_30:
F_22 ( V_2 ) ;
}
return V_51 ;
}
