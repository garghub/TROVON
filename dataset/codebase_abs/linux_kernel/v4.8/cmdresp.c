void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
unsigned long V_4 ;
if ( V_2 -> V_5 != V_6 )
return;
F_2 ( V_7 ) ;
F_3 ( 1000 ) ;
if ( V_2 -> V_8 -> V_9 == V_10 )
F_4 ( V_2 , V_3 ) ;
F_5 ( V_2 -> V_11 ) ;
F_6 ( V_2 -> V_11 ) ;
F_7 ( & V_2 -> V_12 , V_4 ) ;
F_8 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = 0 ;
F_9 ( & V_2 -> V_12 , V_4 ) ;
V_2 -> V_5 = V_15 ;
if ( V_2 -> V_16 != V_17 ) {
F_10 ( L_1 ) ;
F_11 ( V_2 , V_18 , false ) ;
}
F_12 ( V_7 ) ;
}
int F_13 ( struct V_1 * V_2 , T_1 * V_19 , T_2 V_20 )
{
T_3 V_21 , V_22 ;
struct V_23 * V_24 ;
int V_25 = 0 ;
unsigned long V_4 ;
T_3 V_26 ;
F_2 ( V_27 ) ;
F_14 ( & V_2 -> V_28 ) ;
F_7 ( & V_2 -> V_12 , V_4 ) ;
if ( ! V_2 -> V_29 ) {
F_15 ( L_2 ) ;
V_25 = - 1 ;
F_9 ( & V_2 -> V_12 , V_4 ) ;
goto V_30;
}
V_24 = ( void * ) V_19 ;
V_22 = F_16 ( V_2 -> V_29 -> V_31 -> V_32 ) ;
V_21 = F_16 ( V_24 -> V_32 ) ;
V_26 = F_16 ( V_24 -> V_26 ) ;
F_10 ( L_3 ,
V_21 , F_16 ( V_24 -> V_33 ) , V_20 ) ;
F_17 ( V_34 , L_4 , ( void * ) V_24 , V_20 ) ;
if ( V_24 -> V_33 != V_2 -> V_29 -> V_31 -> V_33 ) {
F_18 ( V_2 -> V_11 ,
L_5 ,
F_16 ( V_24 -> V_33 ) ,
F_16 ( V_2 -> V_29 -> V_31 -> V_33 ) ) ;
F_9 ( & V_2 -> V_12 , V_4 ) ;
V_25 = - 1 ;
goto V_30;
}
if ( V_21 != F_19 ( V_22 ) &&
V_21 != V_35 && V_22 != V_36 ) {
F_18 ( V_2 -> V_11 , L_6 ,
V_21 , V_22 ) ;
F_9 ( & V_2 -> V_12 , V_4 ) ;
V_25 = - 1 ;
goto V_30;
}
if ( V_24 -> V_26 == F_20 ( 0x0004 ) ) {
F_18 ( V_2 -> V_11 ,
L_7 ,
F_16 ( V_24 -> V_32 ) ) ;
F_9 ( & V_2 -> V_12 , V_4 ) ;
V_25 = - 1 ;
goto V_30;
}
F_21 ( & V_2 -> V_37 ) ;
V_2 -> V_38 = 0 ;
if ( V_21 == F_19 ( V_39 ) ) {
struct V_40 * V_41 = ( void * ) V_24 ;
T_4 V_42 = F_16 ( V_41 -> V_42 ) ;
F_15 (
L_8 ,
V_26 , V_42 ) ;
if ( V_26 ) {
F_15 ( L_9 ,
V_26 ) ;
if ( V_2 -> V_8 -> V_9 == V_43 &&
V_42 == V_44 )
V_2 -> V_41 = V_45 ;
} else if ( V_42 == V_44 ) {
V_2 -> V_46 = 0 ;
V_2 -> V_16 = V_47 ;
F_15 ( L_10 ) ;
if ( V_2 -> V_5 != V_6 ) {
F_15 (
L_11 ) ;
F_9 ( & V_2 -> V_12 , V_4 ) ;
F_22 ( & V_2 -> V_28 ) ;
F_11 ( V_2 , V_18 ,
false ) ;
F_14 ( & V_2 -> V_28 ) ;
F_7 ( & V_2 -> V_12 , V_4 ) ;
}
} else if ( V_42 == V_18 ) {
V_2 -> V_46 = 0 ;
V_2 -> V_16 = V_17 ;
F_15 ( L_12 ) ;
} else {
F_15 ( L_13 , V_42 ) ;
}
F_23 ( V_2 , V_2 -> V_29 , V_26 ) ;
F_9 ( & V_2 -> V_12 , V_4 ) ;
V_25 = 0 ;
goto V_30;
}
if ( ( V_26 != 0 || ! ( V_21 & 0x8000 ) ) ) {
F_15 ( L_14 ,
V_26 , V_21 ) ;
switch ( V_21 ) {
case F_19 ( V_48 ) :
case F_19 ( V_49 ) :
F_15 ( L_15 ) ;
break;
}
F_23 ( V_2 , V_2 -> V_29 , V_26 ) ;
F_9 ( & V_2 -> V_12 , V_4 ) ;
V_25 = - 1 ;
goto V_30;
}
F_9 ( & V_2 -> V_12 , V_4 ) ;
if ( V_2 -> V_29 && V_2 -> V_29 -> V_50 ) {
V_25 = V_2 -> V_29 -> V_50 ( V_2 , V_2 -> V_29 -> V_51 ,
V_24 ) ;
}
F_7 ( & V_2 -> V_12 , V_4 ) ;
if ( V_2 -> V_29 ) {
F_23 ( V_2 , V_2 -> V_29 , V_26 ) ;
}
F_9 ( & V_2 -> V_12 , V_4 ) ;
V_30:
F_22 ( & V_2 -> V_28 ) ;
F_24 ( V_27 , L_16 , V_25 ) ;
return V_25 ;
}
int F_25 ( struct V_1 * V_2 , T_2 V_52 )
{
int V_25 = 0 ;
struct V_23 V_53 ;
F_2 ( V_34 ) ;
switch ( V_52 ) {
case V_54 :
F_10 ( L_17 ) ;
break;
case V_55 :
F_10 ( L_18 ) ;
F_1 ( V_2 , false ) ;
break;
case V_56 :
F_10 ( L_19 ) ;
F_1 ( V_2 , false ) ;
break;
case V_57 :
F_10 ( L_20 ) ;
F_1 ( V_2 , true ) ;
break;
case V_58 :
F_10 ( L_21 ) ;
if ( V_2 -> V_16 == V_17 ) {
F_10 (
L_22 ) ;
break;
}
if ( ! F_26 ( & V_2 -> V_59 ) ) {
F_10 ( L_23 ) ;
break;
}
V_2 -> V_16 = V_60 ;
F_27 ( V_2 ) ;
break;
case V_61 :
F_10 ( L_24 ) ;
if ( V_2 -> V_62 )
V_2 -> V_62 ( V_2 ) ;
V_2 -> V_63 = 0 ;
F_28 ( V_2 , V_64 , & V_53 ,
sizeof( V_53 ) ) ;
V_2 -> V_65 = 0 ;
F_29 ( & V_2 -> V_66 ) ;
break;
case V_67 :
if ( V_2 -> V_62 )
V_2 -> V_62 ( V_2 ) ;
F_10 ( L_25 ) ;
V_2 -> V_63 = 0 ;
V_2 -> V_68 = 0 ;
F_29 ( & V_2 -> V_69 ) ;
break;
case V_70 :
F_10 ( L_26 ) ;
if ( V_2 -> V_16 == V_17 ) {
F_10 (
L_27 ) ;
break;
}
V_2 -> V_16 = V_47 ;
if ( V_2 -> V_46 ) {
F_10 ( L_28 ) ;
F_11 ( V_2 , V_18 , false ) ;
}
break;
case V_71 :
F_10 ( L_29 ) ;
F_30 ( V_2 , V_52 ) ;
break;
case V_72 :
F_10 ( L_30 ) ;
F_30 ( V_2 , V_52 ) ;
break;
case V_73 :
F_10 ( L_31 ) ;
break;
case V_74 :
F_10 ( L_32 ) ;
break;
case V_75 :
F_10 ( L_33 ) ;
break;
case V_76 :
F_31 ( V_2 -> V_11 , L_34 ) ;
break;
case V_77 :
F_31 ( V_2 -> V_11 , L_35 ) ;
break;
case V_78 :
F_31 ( V_2 -> V_11 , L_36 ) ;
break;
case V_79 :
F_31 ( V_2 -> V_11 , L_37 ) ;
break;
case V_80 :
F_31 ( V_2 -> V_11 , L_38 ) ;
break;
case V_81 :
F_18 ( V_2 -> V_11 , L_39 ) ;
break;
default:
F_31 ( V_2 -> V_11 , L_40 , V_52 ) ;
break;
}
F_24 ( V_34 , L_16 , V_25 ) ;
return V_25 ;
}
