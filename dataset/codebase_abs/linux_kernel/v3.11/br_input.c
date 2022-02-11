static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
F_5 ( & V_9 -> V_11 ) ;
V_9 -> V_12 ++ ;
V_9 -> V_13 += V_2 -> V_14 ;
F_6 ( & V_9 -> V_11 ) ;
if ( ! ( V_5 -> V_15 & V_16 ) &&
! F_7 ( V_7 , F_8 ( V_7 ) , V_2 ) ) {
F_9 ( V_2 ) ;
return V_17 ;
}
V_2 = F_10 ( V_7 , F_8 ( V_7 ) , V_2 ) ;
if ( ! V_2 )
return V_17 ;
V_4 = V_2 -> V_18 ;
V_2 -> V_18 = V_5 ;
return F_11 ( V_19 , V_20 , V_2 , V_4 , NULL ,
V_21 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
const unsigned char * V_22 = F_13 ( V_2 ) -> V_23 ;
struct V_24 * V_25 = F_14 ( V_2 -> V_18 ) ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_1 * V_30 ;
bool V_31 = true ;
T_1 V_32 = 0 ;
if ( ! V_25 || V_25 -> V_33 == V_34 )
goto V_35;
if ( ! F_15 ( V_25 -> V_7 , F_16 ( V_25 ) , V_2 , & V_32 ) )
goto V_35;
V_7 = V_25 -> V_7 ;
if ( V_25 -> V_15 & V_36 )
F_17 ( V_7 , V_25 , F_13 ( V_2 ) -> V_37 , V_32 ) ;
if ( ! F_18 ( V_22 ) && F_19 ( V_22 ) &&
F_20 ( V_7 , V_25 , V_2 ) )
goto V_35;
if ( V_25 -> V_33 == V_38 )
goto V_35;
F_2 ( V_2 ) -> V_5 = V_7 -> V_18 ;
V_30 = NULL ;
if ( V_7 -> V_18 -> V_15 & V_16 )
V_30 = V_2 ;
V_27 = NULL ;
if ( F_18 ( V_22 ) ) {
V_30 = V_2 ;
V_31 = false ;
} else if ( F_19 ( V_22 ) ) {
V_29 = F_21 ( V_7 , V_2 , V_32 ) ;
if ( ( V_29 || F_22 ( V_2 ) ) &&
F_23 ( V_7 , F_13 ( V_2 ) ) ) {
if ( ( V_29 && V_29 -> V_39 ) ||
F_24 ( V_7 ) )
V_30 = V_2 ;
F_25 ( V_29 , V_2 , V_30 ) ;
V_2 = NULL ;
if ( ! V_30 )
goto V_40;
} else
V_30 = V_2 ;
V_31 = false ;
V_7 -> V_18 -> V_10 . V_41 ++ ;
} else if ( ( V_27 = F_26 ( V_7 , V_22 , V_32 ) ) &&
V_27 -> V_42 ) {
V_30 = V_2 ;
V_2 = NULL ;
}
if ( V_2 ) {
if ( V_27 ) {
V_27 -> V_43 = V_44 ;
F_27 ( V_27 -> V_27 , V_2 , V_30 ) ;
} else
F_28 ( V_7 , V_2 , V_30 , V_31 ) ;
}
if ( V_30 )
return F_1 ( V_30 ) ;
V_40:
return 0 ;
V_35:
F_9 ( V_2 ) ;
goto V_40;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_14 ( V_2 -> V_18 ) ;
T_1 V_32 = 0 ;
F_30 ( V_2 , & V_32 ) ;
if ( V_25 -> V_15 & V_36 )
F_17 ( V_25 -> V_7 , V_25 , F_13 ( V_2 ) -> V_37 , V_32 ) ;
return 0 ;
}
T_2 F_31 ( struct V_1 * * V_45 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 = * V_45 ;
const unsigned char * V_22 = F_13 ( V_2 ) -> V_23 ;
T_3 * V_46 ;
if ( F_32 ( V_2 -> V_47 == V_48 ) )
return V_49 ;
if ( ! F_33 ( F_13 ( V_2 ) -> V_37 ) )
goto V_35;
V_2 = F_34 ( V_2 , V_50 ) ;
if ( ! V_2 )
return V_51 ;
V_25 = F_14 ( V_2 -> V_18 ) ;
if ( F_32 ( F_35 ( V_22 ) ) ) {
switch ( V_22 [ 5 ] ) {
case 0x00 :
if ( V_25 -> V_7 -> V_52 == V_53 )
goto V_54;
break;
case 0x01 :
goto V_35;
default:
if ( V_25 -> V_7 -> V_55 & ( 1u << V_22 [ 5 ] ) )
goto V_54;
}
if ( F_11 ( V_19 , V_20 , V_2 , V_2 -> V_18 ,
NULL , F_29 ) ) {
return V_51 ;
} else {
* V_45 = V_2 ;
return V_49 ;
}
}
V_54:
switch ( V_25 -> V_33 ) {
case V_56 :
V_46 = F_36 ( V_57 ) ;
if ( V_46 ) {
if ( (* V_46)( V_2 ) ) {
* V_45 = V_2 ;
return V_49 ;
}
V_22 = F_13 ( V_2 ) -> V_23 ;
}
case V_38 :
if ( F_37 ( V_25 -> V_7 -> V_18 -> V_58 , V_22 ) )
V_2 -> V_47 = V_59 ;
F_11 ( V_19 , V_60 , V_2 , V_2 -> V_18 , NULL ,
F_12 ) ;
break;
default:
V_35:
F_9 ( V_2 ) ;
}
return V_51 ;
}
