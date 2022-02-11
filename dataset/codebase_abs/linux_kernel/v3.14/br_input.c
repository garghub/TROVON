static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
struct V_11 * V_12 ;
F_5 ( & V_9 -> V_13 ) ;
V_9 -> V_14 ++ ;
V_9 -> V_15 += V_2 -> V_16 ;
F_6 ( & V_9 -> V_13 ) ;
V_12 = F_7 ( V_7 ) ;
if ( ! ( V_5 -> V_17 & V_18 ) &&
! F_8 ( V_7 , V_12 , V_2 ) ) {
F_9 ( V_2 ) ;
return V_19 ;
}
V_4 = V_2 -> V_20 ;
V_2 -> V_20 = V_5 ;
V_2 = F_10 ( V_7 , V_12 , V_2 ) ;
if ( ! V_2 )
return V_19 ;
return F_11 ( V_21 , V_22 , V_2 , V_4 , NULL ,
V_23 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
const unsigned char * V_24 = F_13 ( V_2 ) -> V_25 ;
struct V_26 * V_27 = F_14 ( V_2 -> V_20 ) ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_1 * V_32 ;
bool V_33 = true ;
T_1 V_34 = 0 ;
if ( ! V_27 || V_27 -> V_35 == V_36 )
goto V_37;
if ( ! F_15 ( V_27 -> V_7 , F_16 ( V_27 ) , V_2 , & V_34 ) )
goto V_37;
V_7 = V_27 -> V_7 ;
if ( V_27 -> V_17 & V_38 )
F_17 ( V_7 , V_27 , F_13 ( V_2 ) -> V_39 , V_34 , false ) ;
if ( ! F_18 ( V_24 ) && F_19 ( V_24 ) &&
F_20 ( V_7 , V_27 , V_2 , V_34 ) )
goto V_37;
if ( V_27 -> V_35 == V_40 )
goto V_37;
F_2 ( V_2 ) -> V_5 = V_7 -> V_20 ;
V_32 = NULL ;
if ( V_7 -> V_20 -> V_17 & V_18 )
V_32 = V_2 ;
V_29 = NULL ;
if ( F_18 ( V_24 ) ) {
V_32 = V_2 ;
V_33 = false ;
} else if ( F_19 ( V_24 ) ) {
V_31 = F_21 ( V_7 , V_2 , V_34 ) ;
if ( ( V_31 || F_22 ( V_2 ) ) &&
F_23 ( V_7 , F_13 ( V_2 ) ) ) {
if ( ( V_31 && V_31 -> V_41 ) ||
F_24 ( V_7 ) )
V_32 = V_2 ;
F_25 ( V_31 , V_2 , V_32 ) ;
V_2 = NULL ;
if ( ! V_32 )
goto V_42;
} else
V_32 = V_2 ;
V_33 = false ;
V_7 -> V_20 -> V_10 . V_43 ++ ;
} else if ( ( V_29 = F_26 ( V_7 , V_24 , V_34 ) ) &&
V_29 -> V_44 ) {
V_32 = V_2 ;
V_2 = NULL ;
}
if ( V_2 ) {
if ( V_29 ) {
V_29 -> V_45 = V_46 ;
F_27 ( V_29 -> V_29 , V_2 , V_32 ) ;
} else
F_28 ( V_7 , V_2 , V_32 , V_33 ) ;
}
if ( V_32 )
return F_1 ( V_32 ) ;
V_42:
return 0 ;
V_37:
F_9 ( V_2 ) ;
goto V_42;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_14 ( V_2 -> V_20 ) ;
T_1 V_34 = 0 ;
F_30 ( V_2 , & V_34 ) ;
if ( V_27 -> V_17 & V_38 )
F_17 ( V_27 -> V_7 , V_27 , F_13 ( V_2 ) -> V_39 , V_34 , false ) ;
return 0 ;
}
T_2 F_31 ( struct V_1 * * V_47 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 = * V_47 ;
const unsigned char * V_24 = F_13 ( V_2 ) -> V_25 ;
T_3 * V_48 ;
if ( F_32 ( V_2 -> V_49 == V_50 ) )
return V_51 ;
if ( ! F_33 ( F_13 ( V_2 ) -> V_39 ) )
goto V_37;
V_2 = F_34 ( V_2 , V_52 ) ;
if ( ! V_2 )
return V_53 ;
V_27 = F_14 ( V_2 -> V_20 ) ;
if ( F_32 ( F_35 ( V_24 ) ) ) {
switch ( V_24 [ 5 ] ) {
case 0x00 :
if ( V_27 -> V_7 -> V_54 == V_55 )
goto V_56;
break;
case 0x01 :
goto V_37;
default:
if ( V_27 -> V_7 -> V_57 & ( 1u << V_24 [ 5 ] ) )
goto V_56;
}
if ( F_11 ( V_21 , V_22 , V_2 , V_2 -> V_20 ,
NULL , F_29 ) ) {
return V_53 ;
} else {
* V_47 = V_2 ;
return V_51 ;
}
}
V_56:
switch ( V_27 -> V_35 ) {
case V_58 :
V_48 = F_36 ( V_59 ) ;
if ( V_48 ) {
if ( (* V_48)( V_2 ) ) {
* V_47 = V_2 ;
return V_51 ;
}
V_24 = F_13 ( V_2 ) -> V_25 ;
}
case V_40 :
if ( F_37 ( V_27 -> V_7 -> V_20 -> V_60 , V_24 ) )
V_2 -> V_49 = V_61 ;
F_11 ( V_21 , V_62 , V_2 , V_2 -> V_20 , NULL ,
F_12 ) ;
break;
default:
V_37:
F_9 ( V_2 ) ;
}
return V_53 ;
}
