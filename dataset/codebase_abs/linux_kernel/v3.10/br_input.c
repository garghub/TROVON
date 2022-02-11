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
T_1 V_31 = 0 ;
if ( ! V_25 || V_25 -> V_32 == V_33 )
goto V_34;
if ( ! F_15 ( V_25 -> V_7 , F_16 ( V_25 ) , V_2 , & V_31 ) )
goto V_34;
V_7 = V_25 -> V_7 ;
F_17 ( V_7 , V_25 , F_13 ( V_2 ) -> V_35 , V_31 ) ;
if ( ! F_18 ( V_22 ) && F_19 ( V_22 ) &&
F_20 ( V_7 , V_25 , V_2 ) )
goto V_34;
if ( V_25 -> V_32 == V_36 )
goto V_34;
F_2 ( V_2 ) -> V_5 = V_7 -> V_18 ;
V_30 = NULL ;
if ( V_7 -> V_18 -> V_15 & V_16 )
V_30 = V_2 ;
V_27 = NULL ;
if ( F_18 ( V_22 ) )
V_30 = V_2 ;
else if ( F_19 ( V_22 ) ) {
V_29 = F_21 ( V_7 , V_2 , V_31 ) ;
if ( V_29 || F_22 ( V_2 ) ) {
if ( ( V_29 && V_29 -> V_37 ) ||
F_23 ( V_7 ) )
V_30 = V_2 ;
F_24 ( V_29 , V_2 , V_30 ) ;
V_2 = NULL ;
if ( ! V_30 )
goto V_38;
} else
V_30 = V_2 ;
V_7 -> V_18 -> V_10 . V_39 ++ ;
} else if ( ( V_27 = F_25 ( V_7 , V_22 , V_31 ) ) &&
V_27 -> V_40 ) {
V_30 = V_2 ;
V_2 = NULL ;
}
if ( V_2 ) {
if ( V_27 ) {
V_27 -> V_41 = V_42 ;
F_26 ( V_27 -> V_27 , V_2 , V_30 ) ;
} else
F_27 ( V_7 , V_2 , V_30 ) ;
}
if ( V_30 )
return F_1 ( V_30 ) ;
V_38:
return 0 ;
V_34:
F_9 ( V_2 ) ;
goto V_38;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_14 ( V_2 -> V_18 ) ;
T_1 V_31 = 0 ;
F_29 ( V_2 , & V_31 ) ;
F_17 ( V_25 -> V_7 , V_25 , F_13 ( V_2 ) -> V_35 , V_31 ) ;
return 0 ;
}
T_2 F_30 ( struct V_1 * * V_43 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 = * V_43 ;
const unsigned char * V_22 = F_13 ( V_2 ) -> V_23 ;
T_3 * V_44 ;
if ( F_31 ( V_2 -> V_45 == V_46 ) )
return V_47 ;
if ( ! F_32 ( F_13 ( V_2 ) -> V_35 ) )
goto V_34;
V_2 = F_33 ( V_2 , V_48 ) ;
if ( ! V_2 )
return V_49 ;
V_25 = F_14 ( V_2 -> V_18 ) ;
if ( F_31 ( F_34 ( V_22 ) ) ) {
switch ( V_22 [ 5 ] ) {
case 0x00 :
if ( V_25 -> V_7 -> V_50 == V_51 )
goto V_52;
break;
case 0x01 :
goto V_34;
default:
if ( V_25 -> V_7 -> V_53 & ( 1u << V_22 [ 5 ] ) )
goto V_52;
}
if ( F_11 ( V_19 , V_20 , V_2 , V_2 -> V_18 ,
NULL , F_28 ) ) {
return V_49 ;
} else {
* V_43 = V_2 ;
return V_47 ;
}
}
V_52:
switch ( V_25 -> V_32 ) {
case V_54 :
V_44 = F_35 ( V_55 ) ;
if ( V_44 ) {
if ( (* V_44)( V_2 ) ) {
* V_43 = V_2 ;
return V_47 ;
}
V_22 = F_13 ( V_2 ) -> V_23 ;
}
case V_36 :
if ( F_36 ( V_25 -> V_7 -> V_18 -> V_56 , V_22 ) )
V_2 -> V_45 = V_57 ;
F_11 ( V_19 , V_58 , V_2 , V_2 -> V_18 , NULL ,
F_12 ) ;
break;
default:
V_34:
F_9 ( V_2 ) ;
}
return V_49 ;
}
