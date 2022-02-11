static void
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 )
{
struct V_4 * V_4 ;
struct V_5 * V_5 ;
const char * V_6 ;
T_4 V_7 ;
T_5 V_8 ;
T_6 * V_9 ;
T_3 * V_10 = NULL ;
T_7 * V_11 = NULL ;
T_8 V_12 ;
T_9 V_13 ;
T_10 V_14 = 0 ;
T_11 V_15 = 0 , V_16 = 0 , V_17 ;
T_12 * V_18 ;
T_6 * V_19 ;
V_17 = ( T_11 ) F_2 ( V_1 ) ;
V_12 = F_3 ( V_1 , 0 ) ;
V_13 = F_4 ( V_1 , 2 ) ;
V_6 = F_5 ( V_13 , V_20 , L_1 ) ;
F_6 ( V_2 -> V_21 , V_22 , L_2 ) ;
F_7 ( V_2 -> V_21 , V_23 , V_6 ) ;
if ( V_13 == 'A' && ! F_8 ( V_2 ) ) {
F_9 ( F_10 ( F_11 () , V_1 , 13 , 20 , V_24 ) ,
NULL , & V_16 ) ;
V_11 = F_12 ( V_2 -> V_25 ,
& V_2 -> V_26 ,
& V_2 -> V_27 ,
V_2 -> V_28 ,
V_2 -> V_29 ,
V_2 -> V_30 ,
0 ) ;
V_4 = (struct V_4 * ) F_13 ( F_14 () , sizeof( struct V_4 ) ) ;
V_4 -> V_16 = V_16 ;
F_15 ( V_11 , V_31 , V_4 ) ;
}
if ( V_13 == 'S' ) {
if ( ! F_8 ( V_2 ) ) {
V_11 = F_16 ( V_2 -> V_25 ,
& V_2 -> V_26 ,
& V_2 -> V_27 ,
V_2 -> V_28 ,
V_2 -> V_29 ,
V_2 -> V_30 ,
0 ) ;
if ( ! V_11 ) {
V_15 = 0 ;
} else {
V_4 = (struct V_4 * ) F_17 ( V_11 ,
V_31 ) ;
if ( V_4 ) {
V_15 = V_4 -> V_16 ++ ;
} else {
V_15 = 0 ;
}
V_5 = (struct V_5 * ) F_13 (
F_14 () ,
sizeof( struct V_5 ) ) ;
V_5 -> V_7 = V_15 ;
F_18 ( F_14 () , V_2 , V_31 , V_17 , V_5 ) ;
}
} else {
V_5 = (struct V_5 * ) F_19 ( F_14 () , V_2 , V_31 , V_17 ) ;
if ( V_5 ) {
V_15 = V_5 -> V_7 ;
} else {
V_15 = 0 ;
}
}
F_20 ( V_2 -> V_21 , V_23 , L_3 , V_15 ) ;
}
if ( V_3 ) {
V_9 = F_21 ( V_3 ,
V_31 ,
V_1 , 0 , - 1 , V_32 ) ;
V_10 = F_22 ( V_9 , V_33 ) ;
F_23 ( V_9 , L_4 , V_6 ) ;
F_21 ( V_10 ,
V_34 ,
V_1 , V_14 , 2 , V_35 ) ;
V_14 += 2 ;
F_21 ( V_10 ,
V_36 ,
V_1 , V_14 , 1 , V_24 | V_32 ) ;
V_14 += 1 ;
switch ( V_13 ) {
case '+' :
F_21 ( V_10 ,
V_37 ,
V_1 , V_14 , V_12 - 1 , V_24 | V_32 ) ;
break;
case 'A' :
F_21 ( V_10 ,
V_38 ,
V_1 , V_14 , 10 , V_24 | V_32 ) ;
V_14 += 10 ;
V_8 = F_24 ( F_10 ( F_11 () ,
V_1 , V_14 , 20 , V_24 ) , NULL , & V_7 ) ;
V_19 = F_25 ( V_10 ,
V_39 ,
V_1 , V_14 , 20 ,
L_5 , L_6 , V_7 ) ;
if ( ! V_8 )
F_26 ( V_2 , V_19 , & V_40 ) ;
break;
case 'J' :
F_21 ( V_10 ,
V_41 ,
V_1 , V_14 , 1 , V_24 | V_32 ) ;
break;
case 'U' :
break;
case 'S' :
F_23 ( V_9 , L_7 , V_15 ) ;
F_25 ( V_10 ,
V_42 ,
V_1 , V_14 , 0 ,
L_5 ,
L_8 ,
V_15 ) ;
break;
case 'L' :
F_21 ( V_10 ,
V_43 ,
V_1 , V_14 , 6 , V_24 | V_32 ) ;
V_14 += 6 ;
F_21 ( V_10 ,
V_44 ,
V_1 , V_14 , 10 , V_24 | V_32 ) ;
V_14 += 10 ;
F_21 ( V_10 ,
V_38 ,
V_1 , V_14 , 10 , V_24 | V_32 ) ;
V_14 += 10 ;
V_8 = F_24 ( F_10 ( F_11 () ,
V_1 , V_14 , 20 , V_24 ) , NULL , & V_7 ) ;
V_19 = F_25 ( V_10 ,
V_45 ,
V_1 , V_14 , 20 ,
L_5 , L_6 , V_7 ) ;
if ( ! V_8 )
F_26 ( V_2 , V_19 , & V_46 ) ;
break;
case 'H' :
break;
case 'O' :
break;
case 'R' :
break;
case 'Z' :
break;
default:
F_21 ( V_3 ,
V_47 ,
V_1 , V_14 , - 1 , V_32 ) ;
break;
}
}
if ( V_13 == 'S' || V_13 == 'U' ) {
T_1 * V_48 ;
V_48 = F_27 ( V_1 , 3 ) ;
#if 0
if (try_conversation_dissector(&pinfo->dst, &pinfo->src, pinfo->ptype,
pinfo->srcport, pinfo->destport,
sub_tvb, pinfo, tree, NULL)) {
return;
}
#endif
if ( F_28 ( V_49 ,
V_48 ,
V_2 ,
V_3 ,
& V_18 ,
NULL ) ) {
return;
}
if ( V_3 ) {
F_21 ( V_10 ,
V_47 ,
V_48 , 0 , - 1 ,
V_32 ) ;
}
}
}
static T_11
F_29 (
T_2 * V_2 V_50 ,
T_1 * V_1 ,
int V_14 ,
void * T_13 V_50 )
{
return ( T_11 ) F_3 ( V_1 , V_14 ) + 2 ;
}
static int
F_30 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_13 V_50 )
{
F_1 ( V_1 , V_2 , V_3 ) ;
return F_31 ( V_1 ) ;
}
static int
F_32 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_13 )
{
F_33 ( V_1 , V_2 , V_3 ,
V_51 , 2 ,
F_29 ,
F_30 , T_13 ) ;
return F_31 ( V_1 ) ;
}
void
F_34 ( void )
{
T_14 * V_52 ;
static T_15 V_53 [] = {
{ & V_34 ,
{ L_9 , L_10 ,
V_54 , V_55 , NULL , 0x0 ,
L_11 ,
V_56 } } ,
{ & V_36 ,
{ L_12 , L_13 ,
V_57 , V_58 , F_35 ( V_20 ) , 0x0 ,
L_14 ,
V_56 } } ,
{ & V_41 ,
{ L_15 , L_16 ,
V_57 , V_58 , F_35 ( V_59 ) , 0x0 ,
L_17 ,
V_56 } } ,
{ & V_47 ,
{ L_18 , L_19 ,
V_60 , V_61 , NULL , 0x0 ,
L_20 ,
V_56 } } ,
{ & V_37 ,
{ L_21 , L_22 ,
V_62 , V_61 , NULL , 0x0 ,
L_23 ,
V_56 } } ,
{ & V_43 ,
{ L_24 , L_25 ,
V_62 , V_61 , NULL , 0x0 ,
L_26 ,
V_56 } } ,
{ & V_44 ,
{ L_27 , L_28 ,
V_62 , V_61 , NULL , 0x0 ,
L_29 ,
V_56 } } ,
{ & V_38 ,
{ L_30 , L_31 ,
V_62 , V_61 , NULL , 0x0 ,
L_32
L_33 ,
V_56 } } ,
{ & V_42 ,
{ L_34 , L_35 ,
V_62 , V_61 , NULL , 0x0 ,
L_36 ,
V_56 } } ,
{ & V_39 ,
{ L_37 , L_38 ,
V_62 , V_61 , NULL , 0x0 ,
L_39 ,
V_56 } } ,
{ & V_45 ,
{ L_40 , L_41 ,
V_62 , V_61 , NULL , 0x0 ,
L_42
L_43
L_44 ,
V_56 } }
} ;
static T_10 * V_63 [] = {
& V_33
} ;
static T_16 V_64 [] = {
{ & V_46 , { L_45 , V_65 , V_66 ,
L_46 , V_67 } } ,
{ & V_40 , { L_47 , V_65 , V_66 ,
L_48 , V_67 } }
} ;
T_17 * V_68 ;
V_31 = F_36 ( L_2 , L_2 , L_49 ) ;
F_37 ( V_31 , V_53 , F_38 ( V_53 ) ) ;
F_39 ( V_63 , F_38 ( V_63 ) ) ;
V_68 = F_40 ( V_31 , NULL ) ;
F_41 (
V_68 ,
L_50 ,
L_51 ,
L_52
L_53 ,
& V_51 ) ;
V_49 = F_42 ( L_49 , V_31 ) ;
V_52 = F_43 ( V_31 ) ;
F_44 ( V_52 , V_64 , F_38 ( V_64 ) ) ;
}
void
F_45 ( void )
{
V_69 = F_46 ( F_32 , V_31 ) ;
F_47 ( L_54 , L_55 , V_69 ) ;
}
