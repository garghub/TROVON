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
T_1 F_24 ( struct V_1 * * V_41 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 = * V_41 ;
const unsigned char * V_19 = F_9 ( V_2 ) -> V_20 ;
T_2 * V_42 ;
if ( F_25 ( V_2 -> V_43 == V_44 ) )
return V_45 ;
if ( ! F_26 ( F_9 ( V_2 ) -> V_31 ) )
goto V_30;
V_2 = F_27 ( V_2 , V_46 ) ;
if ( ! V_2 )
return V_47 ;
V_22 = F_10 ( V_2 -> V_15 ) ;
if ( F_25 ( F_28 ( V_19 ) ) ) {
switch ( V_19 [ 5 ] ) {
case 0x00 :
if ( V_22 -> V_7 -> V_48 == V_49 )
goto V_50;
break;
case 0x01 :
goto V_30;
default:
if ( V_22 -> V_7 -> V_51 & ( 1u << V_19 [ 5 ] ) )
goto V_50;
}
if ( F_7 ( V_16 , V_17 , V_2 , V_2 -> V_15 ,
NULL , F_23 ) ) {
return V_47 ;
} else {
* V_41 = V_2 ;
return V_45 ;
}
}
V_50:
switch ( V_22 -> V_28 ) {
case V_52 :
V_42 = F_29 ( V_53 ) ;
if ( V_42 ) {
if ( (* V_42)( V_2 ) ) {
* V_41 = V_2 ;
return V_45 ;
}
V_19 = F_9 ( V_2 ) -> V_20 ;
}
case V_32 :
if ( F_30 ( V_22 -> V_7 -> V_15 -> V_54 , V_19 ) )
V_2 -> V_43 = V_55 ;
F_7 ( V_16 , V_56 , V_2 , V_2 -> V_15 , NULL ,
F_8 ) ;
break;
default:
V_30:
F_22 ( V_2 ) ;
}
return V_47 ;
}
