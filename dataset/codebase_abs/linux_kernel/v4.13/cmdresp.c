void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
unsigned long V_4 ;
if ( V_2 -> V_5 != V_6 )
return;
F_2 ( 1000 ) ;
if ( V_2 -> V_7 -> V_8 == V_9 )
F_3 ( V_2 , V_3 ) ;
F_4 ( V_2 -> V_10 ) ;
F_5 ( V_2 -> V_10 ) ;
F_6 ( & V_2 -> V_11 , V_4 ) ;
F_7 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = 0 ;
F_8 ( & V_2 -> V_11 , V_4 ) ;
V_2 -> V_5 = V_14 ;
if ( V_2 -> V_15 != V_16 ) {
F_9 ( L_1 ) ;
F_10 ( V_2 , V_17 , false ) ;
}
}
int F_11 ( struct V_1 * V_2 , T_1 * V_18 , T_2 V_19 )
{
T_3 V_20 , V_21 ;
struct V_22 * V_23 ;
int V_24 = 0 ;
unsigned long V_4 ;
T_3 V_25 ;
F_12 ( & V_2 -> V_26 ) ;
F_6 ( & V_2 -> V_11 , V_4 ) ;
if ( ! V_2 -> V_27 ) {
F_13 ( L_2 ) ;
V_24 = - 1 ;
F_8 ( & V_2 -> V_11 , V_4 ) ;
goto V_28;
}
V_23 = ( void * ) V_18 ;
V_21 = F_14 ( V_2 -> V_27 -> V_29 -> V_30 ) ;
V_20 = F_14 ( V_23 -> V_30 ) ;
V_25 = F_14 ( V_23 -> V_25 ) ;
F_9 ( L_3 ,
V_20 , F_14 ( V_23 -> V_31 ) , V_19 ) ;
F_15 ( V_32 , L_4 , ( void * ) V_23 , V_19 ) ;
if ( V_23 -> V_31 != V_2 -> V_27 -> V_29 -> V_31 ) {
F_16 ( V_2 -> V_10 ,
L_5 ,
F_14 ( V_23 -> V_31 ) ,
F_14 ( V_2 -> V_27 -> V_29 -> V_31 ) ) ;
F_8 ( & V_2 -> V_11 , V_4 ) ;
V_24 = - 1 ;
goto V_28;
}
if ( V_20 != F_17 ( V_21 ) &&
V_20 != V_33 && V_21 != V_34 ) {
F_16 ( V_2 -> V_10 , L_6 ,
V_20 , V_21 ) ;
F_8 ( & V_2 -> V_11 , V_4 ) ;
V_24 = - 1 ;
goto V_28;
}
if ( V_23 -> V_25 == F_18 ( 0x0004 ) ) {
F_16 ( V_2 -> V_10 ,
L_7 ,
F_14 ( V_23 -> V_30 ) ) ;
F_8 ( & V_2 -> V_11 , V_4 ) ;
V_24 = - 1 ;
goto V_28;
}
F_19 ( & V_2 -> V_35 ) ;
V_2 -> V_36 = 0 ;
if ( V_20 == F_17 ( V_37 ) ) {
struct V_38 * V_39 = ( void * ) V_23 ;
T_4 V_40 = F_14 ( V_39 -> V_40 ) ;
F_13 (
L_8 ,
V_25 , V_40 ) ;
if ( V_25 ) {
F_13 ( L_9 ,
V_25 ) ;
if ( V_2 -> V_7 -> V_8 == V_41 &&
V_40 == V_42 )
V_2 -> V_39 = V_43 ;
} else if ( V_40 == V_42 ) {
V_2 -> V_44 = 0 ;
V_2 -> V_15 = V_45 ;
F_13 ( L_10 ) ;
if ( V_2 -> V_5 != V_6 ) {
F_13 (
L_11 ) ;
F_8 ( & V_2 -> V_11 , V_4 ) ;
F_20 ( & V_2 -> V_26 ) ;
F_10 ( V_2 , V_17 ,
false ) ;
F_12 ( & V_2 -> V_26 ) ;
F_6 ( & V_2 -> V_11 , V_4 ) ;
}
} else if ( V_40 == V_17 ) {
V_2 -> V_44 = 0 ;
V_2 -> V_15 = V_16 ;
F_13 ( L_12 ) ;
} else {
F_13 ( L_13 , V_40 ) ;
}
F_21 ( V_2 , V_2 -> V_27 , V_25 ) ;
F_8 ( & V_2 -> V_11 , V_4 ) ;
V_24 = 0 ;
goto V_28;
}
if ( ( V_25 != 0 || ! ( V_20 & 0x8000 ) ) ) {
F_13 ( L_14 ,
V_25 , V_20 ) ;
switch ( V_20 ) {
case F_17 ( V_46 ) :
case F_17 ( V_47 ) :
F_13 ( L_15 ) ;
break;
}
F_21 ( V_2 , V_2 -> V_27 , V_25 ) ;
F_8 ( & V_2 -> V_11 , V_4 ) ;
V_24 = - 1 ;
goto V_28;
}
F_8 ( & V_2 -> V_11 , V_4 ) ;
if ( V_2 -> V_27 && V_2 -> V_27 -> V_48 ) {
V_24 = V_2 -> V_27 -> V_48 ( V_2 , V_2 -> V_27 -> V_49 ,
V_23 ) ;
}
F_6 ( & V_2 -> V_11 , V_4 ) ;
if ( V_2 -> V_27 ) {
F_21 ( V_2 , V_2 -> V_27 , V_25 ) ;
}
F_8 ( & V_2 -> V_11 , V_4 ) ;
V_28:
F_20 ( & V_2 -> V_26 ) ;
return V_24 ;
}
int F_22 ( struct V_1 * V_2 , T_2 V_50 )
{
int V_24 = 0 ;
struct V_22 V_51 ;
switch ( V_50 ) {
case V_52 :
F_9 ( L_16 ) ;
break;
case V_53 :
F_9 ( L_17 ) ;
F_1 ( V_2 , false ) ;
break;
case V_54 :
F_9 ( L_18 ) ;
F_1 ( V_2 , false ) ;
break;
case V_55 :
F_9 ( L_19 ) ;
F_1 ( V_2 , true ) ;
break;
case V_56 :
F_9 ( L_20 ) ;
if ( V_2 -> V_15 == V_16 ) {
F_9 (
L_21 ) ;
break;
}
if ( ! F_23 ( & V_2 -> V_57 ) ) {
F_9 ( L_22 ) ;
break;
}
V_2 -> V_15 = V_58 ;
F_24 ( V_2 ) ;
break;
case V_59 :
F_9 ( L_23 ) ;
if ( V_2 -> V_60 )
V_2 -> V_60 ( V_2 ) ;
V_2 -> V_61 = 0 ;
F_25 ( V_2 , V_62 , & V_51 ,
sizeof( V_51 ) ) ;
V_2 -> V_63 = 0 ;
F_26 ( & V_2 -> V_64 ) ;
break;
case V_65 :
if ( V_2 -> V_60 )
V_2 -> V_60 ( V_2 ) ;
F_9 ( L_24 ) ;
V_2 -> V_61 = 0 ;
V_2 -> V_66 = 0 ;
F_26 ( & V_2 -> V_67 ) ;
break;
case V_68 :
F_9 ( L_25 ) ;
if ( V_2 -> V_15 == V_16 ) {
F_9 (
L_26 ) ;
break;
}
V_2 -> V_15 = V_45 ;
if ( V_2 -> V_44 ) {
F_9 ( L_27 ) ;
F_10 ( V_2 , V_17 , false ) ;
}
break;
case V_69 :
F_9 ( L_28 ) ;
F_27 ( V_2 , V_50 ) ;
break;
case V_70 :
F_9 ( L_29 ) ;
F_27 ( V_2 , V_50 ) ;
break;
case V_71 :
F_9 ( L_30 ) ;
break;
case V_72 :
F_9 ( L_31 ) ;
break;
case V_73 :
F_9 ( L_32 ) ;
break;
case V_74 :
F_28 ( V_2 -> V_10 , L_33 ) ;
break;
case V_75 :
F_28 ( V_2 -> V_10 , L_34 ) ;
break;
case V_76 :
F_28 ( V_2 -> V_10 , L_35 ) ;
break;
case V_77 :
F_28 ( V_2 -> V_10 , L_36 ) ;
break;
case V_78 :
F_28 ( V_2 -> V_10 , L_37 ) ;
break;
case V_79 :
F_16 ( V_2 -> V_10 , L_38 ) ;
break;
default:
F_28 ( V_2 -> V_10 , L_39 , V_50 ) ;
break;
}
return V_24 ;
}
