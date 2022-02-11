static void
F_1 (
T_1 * V_1 ,
T_2 V_2 )
{
T_1 * V_3 ;
V_3 = F_2 ( NULL , V_2 , V_4 , L_1 ) ;
F_3 ( V_1 , V_5 ,
L_2 , V_3 , ( char ) ( V_2 & 0xff ) ) ;
F_4 ( NULL , V_3 ) ;
}
static void
F_5 (
T_1 * V_1 ,
T_2 V_2 )
{
T_1 * V_3 ;
V_3 = F_2 ( NULL , V_2 , V_6 , L_3 ) ;
F_3 ( V_1 , V_5 ,
L_2 , V_3 , ( char ) ( V_2 & 0xff ) ) ;
F_4 ( NULL , V_3 ) ;
}
static void
F_6 (
T_3 * V_7 ,
T_4 * V_8 ,
T_5 * V_9 )
{
struct V_10 * V_10 ;
struct V_11 * V_11 ;
const char * V_12 ;
const char * V_13 ;
T_6 * V_14 ;
T_5 * V_15 = NULL ;
T_7 * V_16 = NULL ;
T_8 V_17 ;
T_9 V_18 ;
T_10 V_19 = 0 ;
T_11 V_20 = 0 , V_21 , V_22 ;
T_12 * V_23 ;
V_22 = ( T_11 ) F_7 ( V_7 ) ;
V_17 = F_8 ( V_7 , 0 ) ;
V_18 = F_9 ( V_7 , 2 ) ;
V_12 = F_10 ( V_18 , V_4 , L_4 ) ;
F_11 ( V_8 -> V_24 , V_25 , L_5 ) ;
F_12 ( V_8 -> V_24 , V_26 , V_12 ) ;
if ( V_18 == 'A' && ! F_13 ( V_8 ) ) {
V_13 = F_14 ( F_15 () , V_7 , 13 , 20 , V_27 ) ;
V_21 = atoi ( V_13 ) ;
V_16 = F_16 ( F_17 ( V_8 ) ,
& V_8 -> V_28 ,
& V_8 -> V_29 ,
V_8 -> V_30 ,
V_8 -> V_31 ,
V_8 -> V_32 ,
0 ) ;
V_10 = (struct V_10 * ) F_18 ( F_19 () , sizeof( struct V_10 ) ) ;
V_10 -> V_21 = V_21 ;
F_20 ( V_16 , V_33 , V_10 ) ;
}
if ( V_18 == 'S' ) {
if ( ! F_13 ( V_8 ) ) {
V_16 = F_21 ( F_17 ( V_8 ) ,
& V_8 -> V_28 ,
& V_8 -> V_29 ,
V_8 -> V_30 ,
V_8 -> V_31 ,
V_8 -> V_32 ,
0 ) ;
if ( ! V_16 ) {
V_20 = 0 ;
} else {
V_10 = (struct V_10 * ) F_22 ( V_16 ,
V_33 ) ;
if ( V_10 ) {
V_20 = V_10 -> V_21 ++ ;
} else {
V_20 = 0 ;
}
V_11 = (struct V_11 * ) F_18 (
F_19 () ,
sizeof( struct V_11 ) ) ;
V_11 -> V_34 = V_20 ;
F_23 ( F_19 () , V_8 , V_33 , V_22 , V_11 ) ;
}
} else {
V_11 = (struct V_11 * ) F_24 ( F_19 () , V_8 , V_33 , V_22 ) ;
if ( V_11 ) {
V_20 = V_11 -> V_34 ;
} else {
V_20 = 0 ;
}
}
F_25 ( V_8 -> V_24 , V_26 , L_6 , V_20 ) ;
}
if ( V_9 ) {
V_14 = F_26 ( V_9 ,
V_33 ,
V_7 , 0 , - 1 , V_35 ) ;
V_15 = F_27 ( V_14 , V_36 ) ;
F_28 ( V_14 , L_7 , V_12 ) ;
F_26 ( V_15 ,
V_37 ,
V_7 , V_19 , 2 , V_38 ) ;
V_19 += 2 ;
F_26 ( V_15 ,
V_39 ,
V_7 , V_19 , 1 , V_38 ) ;
V_19 += 1 ;
switch ( V_18 ) {
case '+' :
F_26 ( V_15 ,
V_40 ,
V_7 , V_19 , V_17 - 1 , V_27 | V_35 ) ;
break;
case 'A' :
F_26 ( V_15 ,
V_41 ,
V_7 , V_19 , 10 , V_27 | V_35 ) ;
V_19 += 10 ;
V_13 = F_14 ( F_15 () , V_7 , V_19 , 20 , V_27 ) ;
F_29 ( V_15 ,
V_42 ,
V_7 , V_19 , 20 ,
L_8 , L_9 , atoi ( V_13 ) ) ;
break;
case 'J' :
F_26 ( V_15 ,
V_43 ,
V_7 , V_19 , 1 , V_38 ) ;
break;
case 'U' :
break;
case 'S' :
F_28 ( V_14 , L_10 , V_20 ) ;
F_29 ( V_15 ,
V_44 ,
V_7 , V_19 , 0 ,
L_8 ,
L_11 ,
V_20 ) ;
break;
case 'L' :
F_26 ( V_15 ,
V_45 ,
V_7 , V_19 , 6 , V_27 | V_35 ) ;
V_19 += 6 ;
F_26 ( V_15 ,
V_46 ,
V_7 , V_19 , 10 , V_27 | V_35 ) ;
V_19 += 10 ;
F_26 ( V_15 ,
V_41 ,
V_7 , V_19 , 10 , V_27 | V_35 ) ;
V_19 += 10 ;
V_13 = F_14 ( F_15 () , V_7 , V_19 , 20 , V_27 ) ;
F_29 ( V_15 ,
V_47 ,
V_7 , V_19 , 20 ,
L_8 , L_9 , atoi ( V_13 ) ) ;
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
F_26 ( V_9 ,
V_48 ,
V_7 , V_19 , - 1 , V_35 ) ;
break;
}
}
if ( V_18 == 'S' || V_18 == 'U' ) {
T_3 * V_49 ;
V_49 = F_30 ( V_7 , 3 ) ;
#if 0
if (try_conversation_dissector(&pinfo->dst, &pinfo->src, pinfo->ptype,
pinfo->srcport, pinfo->destport,
sub_tvb, pinfo, tree, NULL)) {
return;
}
#endif
if ( F_31 ( V_50 ,
V_49 ,
V_8 ,
V_9 ,
& V_23 ,
NULL ) ) {
return;
}
if ( V_9 ) {
F_26 ( V_15 ,
V_48 ,
V_49 , 0 , - 1 ,
V_35 ) ;
}
}
}
static T_11
F_32 (
T_4 * V_8 V_51 ,
T_3 * V_7 ,
int V_19 ,
void * T_13 V_51 )
{
return ( T_11 ) F_8 ( V_7 , V_19 ) + 2 ;
}
static int
F_33 (
T_3 * V_7 ,
T_4 * V_8 ,
T_5 * V_9 ,
void * T_13 V_51 )
{
F_6 ( V_7 , V_8 , V_9 ) ;
return F_34 ( V_7 ) ;
}
static int
F_35 (
T_3 * V_7 ,
T_4 * V_8 ,
T_5 * V_9 ,
void * T_13 )
{
F_36 ( V_7 , V_8 , V_9 ,
V_52 , 2 ,
F_32 ,
F_33 , T_13 ) ;
return F_34 ( V_7 ) ;
}
static void
F_37 ( void )
{
F_38 ( L_12 , V_53 , V_54 ) ;
F_39 ( V_53 ) ;
V_53 = F_40 ( V_55 ) ;
F_41 ( L_12 , V_53 , V_54 ) ;
}
void
F_42 ( void )
{
static T_14 V_56 [] = {
{ & V_37 ,
{ L_13 , L_14 ,
V_57 , V_58 , NULL , 0x0 ,
L_15 ,
V_59 } } ,
{ & V_39 ,
{ L_16 , L_17 ,
V_60 , V_61 , F_43 ( F_1 ) , 0x0 ,
L_18 ,
V_59 } } ,
{ & V_43 ,
{ L_19 , L_20 ,
V_60 , V_61 , F_43 ( F_5 ) , 0x0 ,
L_21 ,
V_59 } } ,
{ & V_48 ,
{ L_22 , L_23 ,
V_62 , V_63 , NULL , 0x0 ,
L_24 ,
V_59 } } ,
{ & V_40 ,
{ L_25 , L_26 ,
V_64 , V_63 , NULL , 0x0 ,
L_27 ,
V_59 } } ,
{ & V_45 ,
{ L_28 , L_29 ,
V_64 , V_63 , NULL , 0x0 ,
L_30 ,
V_59 } } ,
{ & V_46 ,
{ L_31 , L_32 ,
V_64 , V_63 , NULL , 0x0 ,
L_33 ,
V_59 } } ,
{ & V_41 ,
{ L_34 , L_35 ,
V_64 , V_63 , NULL , 0x0 ,
L_36
L_37 ,
V_59 } } ,
{ & V_44 ,
{ L_38 , L_39 ,
V_64 , V_63 , NULL , 0x0 ,
L_40 ,
V_59 } } ,
{ & V_42 ,
{ L_41 , L_42 ,
V_64 , V_63 , NULL , 0x0 ,
L_43 ,
V_59 } } ,
{ & V_47 ,
{ L_44 , L_45 ,
V_64 , V_63 , NULL , 0x0 ,
L_46
L_47
L_48 ,
V_59 } }
} ;
static T_10 * V_65 [] = {
& V_36
} ;
T_15 * V_66 ;
V_33
= F_44 ( L_5 , L_5 , L_49 ) ;
F_45 ( V_33 , V_56 , F_46 ( V_56 ) ) ;
F_47 ( V_65 , F_46 ( V_65 ) ) ;
V_66
= F_48 ( V_33 ,
F_37 ) ;
F_49 (
V_66 ,
L_50 ,
L_51 ,
L_52
L_53 ,
& V_52 ) ;
F_50 (
V_66 ,
L_12 ,
L_54 ,
L_55 ,
& V_55 ,
65535 ) ;
V_53 = F_51 () ;
V_50 = F_52 ( L_49 ) ;
}
void
F_53 ( void )
{
V_54 = F_54 ( F_35 ,
V_33 ) ;
F_55 ( L_12 , V_54 ) ;
}
