static void F_1 ( T_1 * V_1 , T_2 * V_2 , int * V_3 ,
int type , int V_4 , int V_5 , int V_6 )
{
T_3 * V_7 ;
T_2 * V_8 ;
T_4 V_9 ;
V_7 = F_2 ( V_2 , V_10 , V_1 , * V_3 , V_6 , V_11 ) ;
V_8 = F_3 ( V_7 , V_12 ) ;
switch ( type ) {
case V_13 :
F_2 ( V_8 , V_14 , V_1 , * V_3 ,
V_6 , V_11 ) ;
break;
case V_15 :
if ( V_4 == V_16 ) {
F_2 ( V_8 , V_17 , V_1 , * V_3 ,
4 , V_18 ) ;
for ( V_9 = 1 ; V_9 <= V_5 ; V_9 ++ ) {
F_2 ( V_8 , V_19 , V_1 ,
* V_3 + V_9 * 4 , 4 , V_18 ) ;
}
} else {
F_2 ( V_8 , V_20 , V_1 , * V_3 ,
8 , V_18 ) ;
for ( V_9 = 1 ; V_9 <= V_5 ; V_9 ++ )
F_2 ( V_8 , V_21 , V_1 ,
* V_3 + V_9 * 8 , 8 , V_18 ) ;
}
break;
case V_22 :
if ( V_4 == V_16 ) {
F_2 ( V_8 , V_17 , V_1 , * V_3 , 4 ,
V_18 ) ;
} else {
F_2 ( V_8 , V_20 , V_1 , * V_3 , 8 ,
V_18 ) ;
}
break;
case V_23 :
if ( V_6 > 0 ) {
F_2 ( V_8 , V_14 , V_1 , * V_3 ,
V_6 , V_11 ) ;
}
break;
default:
F_4 () ;
break;
}
( * V_3 ) += V_6 ;
}
static T_5 F_5 ( T_1 * V_1 , T_6 * V_24 , T_2 * V_2 ,
int * V_3 , T_7 V_25 , T_7 V_26 )
{
T_3 * V_27 ;
T_2 * V_28 ;
T_5 V_29 ;
T_7 type ;
V_27 = F_2 ( V_2 , V_30 , V_1 , * V_3 , 4 , V_11 ) ;
V_28 = F_3 ( V_27 , V_31 ) ;
if ( V_25 != V_26 ) {
F_6 ( V_24 , V_28 , & V_32 ,
L_1
L_2 , V_25 , V_26 ) ;
}
type = ( V_26 & 0x30 ) >> 4 ;
F_2 ( V_28 , V_33 , V_1 ,
* V_3 , 1 , V_11 ) ;
F_2 ( V_28 , V_34 , V_1 ,
* V_3 , 1 , V_11 ) ;
F_2 ( V_28 , V_35 , V_1 ,
* V_3 , 1 , V_11 ) ;
F_2 ( V_28 , V_36 , V_1 ,
* V_3 , 1 , V_11 ) ;
( * V_3 ) ++ ;
if ( type != V_23 ) {
F_2 ( V_28 , V_37 , V_1 ,
* V_3 , 1 , V_11 ) ;
} else {
F_2 ( V_28 , V_38 , V_1 ,
* V_3 , 1 , V_11 ) ;
}
if ( type != V_23 ) {
F_2 ( V_28 , V_39 , V_1 ,
* V_3 , 1 , V_11 ) ;
}
( * V_3 ) ++ ;
F_2 ( V_28 , V_40 , V_1 , * V_3 , 2 , V_18 ) ;
F_2 ( V_28 , V_41 , V_1 , * V_3 , 2 , V_18 ) ;
V_29 = ( F_7 ( V_1 , * V_3 ) & 0x8000 ) != 0 ;
( * V_3 ) += 2 ;
return V_29 ;
}
static T_5 F_8 ( T_1 * V_1 , T_6 * V_24 , T_2 * V_2 ,
int * V_3 , T_7 V_25 , int V_9 )
{
T_5 V_29 ;
T_8 V_5 ;
T_8 V_4 ;
T_8 V_6 ;
T_2 * V_42 ;
T_7 V_26 ;
int type ;
V_26 = F_9 ( V_1 , * V_3 ) ;
V_5 = F_7 ( V_1 , * V_3 + 2 ) & 0x0FFF ;
V_4 = ( 1 + ( ( V_26 & 0x40 ) >> 6 ) ) ;
type = ( V_26 & 0x30 ) >> 4 ;
switch ( type ) {
case V_13 :
V_6 = 4 * V_4 * V_5 ;
break;
case V_15 :
V_6 = 4 * V_4 * ( V_5 + 1 ) ;
break;
case V_22 :
V_6 = 4 * V_4 ;
break;
case V_23 :
V_6 = 4 * V_4 * V_5 ;
break;
default:
F_4 () ;
break;
}
V_42 = F_10 ( V_2 , V_1 , * V_3 ,
V_43 + V_6 , V_44 , NULL , L_3 , V_9 ) ;
V_29 = F_5 ( V_1 , V_24 , V_42 , V_3 , V_25 , V_26 ) ;
F_1 ( V_1 , V_42 , V_3 , type , V_4 , V_5 , V_6 ) ;
return V_29 ;
}
static int F_11 ( T_1 * V_1 , T_6 * V_24 , T_2 * V_2 , void * T_9 V_45 )
{
T_7 type ;
T_3 * V_46 ;
T_2 * V_47 ;
T_8 V_3 ;
int V_9 = 1 ;
T_7 V_25 ;
T_7 V_48 ;
T_8 V_5 ;
F_12 ( V_24 -> V_49 , V_50 , L_4 ) ;
F_13 ( V_24 -> V_49 , V_51 ) ;
V_25 = F_9 ( V_1 , 0 ) ;
V_48 = V_25 & 0x0F ;
type = ( V_25 & 0x30 ) >> 4 ;
V_5 = F_7 ( V_1 , 2 ) & 0x0FFF ;
F_14 ( V_24 -> V_49 , V_51 , L_5 ,
F_15 ( type , V_52 , L_6 ) , V_48 , V_5 ) ;
if ( V_5 == 1 ) {
if ( type == V_22 || type == V_15 ) {
F_16 ( V_24 -> V_49 , V_51 , L_7 , F_17 ( V_1 , 4 ) ) ;
}
if ( type == V_15 ) {
F_16 ( V_24 -> V_49 , V_51 , L_8 , F_17 ( V_1 , 8 ) ) ;
}
}
V_3 = 0 ;
V_46 = F_2 ( V_2 , V_53 , V_1 , 0 , - 1 , V_11 ) ;
V_47 = F_3 ( V_46 , V_54 ) ;
while ( ! F_8 ( V_1 , V_24 , V_47 , & V_3 , V_25 , V_9 ) ) {
V_9 ++ ;
}
return F_18 ( V_1 ) ;
}
void F_19 ( void )
{
T_10 * V_55 ;
T_11 * V_56 ;
static T_12 V_57 [] = {
{ & V_30 ,
{ L_9 , L_10 ,
V_58 , V_59 ,
NULL , 0x00 ,
NULL , V_60 }
} ,
{ & V_33 ,
{ L_11 , L_12 ,
V_61 , V_62 ,
NULL , 0x0F ,
NULL , V_60 }
} ,
{ & V_34 ,
{ L_13 , L_14 ,
V_61 , V_63 ,
F_20 ( V_52 ) , 0x30 ,
NULL , V_60 }
} ,
{ & V_35 ,
{ L_15 , L_16 ,
V_61 , V_63 ,
F_20 ( V_64 ) , 0x40 ,
NULL , V_60 }
} ,
{ & V_36 ,
{ L_17 , L_18 ,
V_65 , 8 ,
F_21 ( & V_66 ) , 0x80 ,
NULL , V_60 }
} ,
{ & V_37 ,
{ L_19 , L_20 ,
V_61 , V_62 ,
F_20 ( V_67 ) , 0xF0 ,
NULL , V_60 }
} ,
{ & V_39 ,
{ L_21 , L_22 ,
V_61 , V_62 ,
F_20 ( V_67 ) , 0x0F ,
NULL , V_60 }
} ,
{ & V_38 ,
{ L_23 , L_24 ,
V_61 , V_62 ,
F_20 ( V_68 ) , 0xF0 ,
NULL , V_60 }
} ,
{ & V_40 ,
{ L_25 , L_26 ,
V_69 , V_63 ,
NULL , 0x0FFF ,
NULL , V_60 }
} ,
{ & V_41 ,
{ L_27 , L_28 ,
V_65 , 16 ,
NULL , 0x8000 ,
NULL , V_60 }
} ,
{ & V_10 ,
{ L_29 , L_30 ,
V_58 , V_59 ,
NULL , 0x00 ,
NULL , V_60 }
} ,
{ & V_17 ,
{ L_31 , L_32 ,
V_70 , V_62 ,
NULL , 0x0 ,
NULL , V_60 }
} ,
{ & V_20 ,
{ L_31 , L_33 ,
V_71 , V_62 ,
NULL , 0x0 ,
NULL , V_60 }
} ,
{ & V_19 ,
{ L_34 , L_35 ,
V_70 , V_62 ,
NULL , 0x0 ,
NULL , V_60 }
} ,
{ & V_21 ,
{ L_34 , L_36 ,
V_71 , V_62 ,
NULL , 0x0 ,
NULL , V_60 }
} ,
{ & V_14 ,
{ L_37 , L_38 ,
V_72 , V_59 ,
NULL , 0x0 ,
NULL , V_60 }
}
} ;
static T_13 V_73 [] = {
{ & V_32 , { L_39 , V_74 , V_75 , L_40 , V_76 } }
} ;
static T_4 * V_77 [] = {
& V_54 ,
& V_44 ,
& V_31 ,
& V_12 ,
} ;
V_53 = F_22 (
L_41 ,
L_4 ,
L_42
) ;
F_23 ( V_53 , V_57 , F_24 ( V_57 ) ) ;
F_25 ( V_77 , F_24 ( V_77 ) ) ;
V_55 = F_26 ( V_53 ) ;
F_27 ( V_55 , V_73 , F_24 ( V_73 ) ) ;
F_28 ( & V_78 , V_79 , V_80 ) ;
V_56 = F_29 ( V_53 , V_81 ) ;
F_30 ( V_56 ,
L_43 ,
L_44 ,
L_45 V_79 L_46 ,
& V_78 , V_80 ) ;
F_31 ( V_56 ,
L_47 ,
L_48 ,
L_49 ,
10 , & V_82 ) ;
}
void V_81 ( void )
{
static T_14 V_83 ;
static T_5 V_84 = FALSE ;
static T_15 * V_85 ;
static T_4 V_86 ;
if ( ! V_84 ) {
V_83 = F_32 ( F_11 , V_53 ) ;
F_33 ( L_50 , V_83 ) ;
V_84 = TRUE ;
} else {
F_34 ( L_51 , V_86 , V_83 ) ;
F_35 ( L_52 , V_85 , V_83 ) ;
F_36 ( V_85 ) ;
}
V_85 = F_37 ( V_78 ) ;
V_86 = V_82 ;
F_38 ( L_51 , V_86 , V_83 ) ;
F_39 ( L_52 , V_85 , V_83 ) ;
}
