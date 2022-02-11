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
V_16 = F_16 ( V_8 -> V_28 ,
& V_8 -> V_29 ,
& V_8 -> V_30 ,
V_8 -> V_31 ,
V_8 -> V_32 ,
V_8 -> V_33 ,
0 ) ;
V_10 = (struct V_10 * ) F_17 ( F_18 () , sizeof( struct V_10 ) ) ;
V_10 -> V_21 = V_21 ;
F_19 ( V_16 , V_34 , V_10 ) ;
}
if ( V_18 == 'S' ) {
if ( ! F_13 ( V_8 ) ) {
V_16 = F_20 ( V_8 -> V_28 ,
& V_8 -> V_29 ,
& V_8 -> V_30 ,
V_8 -> V_31 ,
V_8 -> V_32 ,
V_8 -> V_33 ,
0 ) ;
if ( ! V_16 ) {
V_20 = 0 ;
} else {
V_10 = (struct V_10 * ) F_21 ( V_16 ,
V_34 ) ;
if ( V_10 ) {
V_20 = V_10 -> V_21 ++ ;
} else {
V_20 = 0 ;
}
V_11 = (struct V_11 * ) F_17 (
F_18 () ,
sizeof( struct V_11 ) ) ;
V_11 -> V_35 = V_20 ;
F_22 ( F_18 () , V_8 , V_34 , V_22 , V_11 ) ;
}
} else {
V_11 = (struct V_11 * ) F_23 ( F_18 () , V_8 , V_34 , V_22 ) ;
if ( V_11 ) {
V_20 = V_11 -> V_35 ;
} else {
V_20 = 0 ;
}
}
F_24 ( V_8 -> V_24 , V_26 , L_6 , V_20 ) ;
}
if ( V_9 ) {
V_14 = F_25 ( V_9 ,
V_34 ,
V_7 , 0 , - 1 , V_36 ) ;
V_15 = F_26 ( V_14 , V_37 ) ;
F_27 ( V_14 , L_7 , V_12 ) ;
F_25 ( V_15 ,
V_38 ,
V_7 , V_19 , 2 , V_39 ) ;
V_19 += 2 ;
F_25 ( V_15 ,
V_40 ,
V_7 , V_19 , 1 , V_39 ) ;
V_19 += 1 ;
switch ( V_18 ) {
case '+' :
F_25 ( V_15 ,
V_41 ,
V_7 , V_19 , V_17 - 1 , V_27 | V_36 ) ;
break;
case 'A' :
F_25 ( V_15 ,
V_42 ,
V_7 , V_19 , 10 , V_27 | V_36 ) ;
V_19 += 10 ;
V_13 = F_14 ( F_15 () , V_7 , V_19 , 20 , V_27 ) ;
F_28 ( V_15 ,
V_43 ,
V_7 , V_19 , 20 ,
L_8 , L_9 , atoi ( V_13 ) ) ;
break;
case 'J' :
F_25 ( V_15 ,
V_44 ,
V_7 , V_19 , 1 , V_39 ) ;
break;
case 'U' :
break;
case 'S' :
F_27 ( V_14 , L_10 , V_20 ) ;
F_28 ( V_15 ,
V_45 ,
V_7 , V_19 , 0 ,
L_8 ,
L_11 ,
V_20 ) ;
break;
case 'L' :
F_25 ( V_15 ,
V_46 ,
V_7 , V_19 , 6 , V_27 | V_36 ) ;
V_19 += 6 ;
F_25 ( V_15 ,
V_47 ,
V_7 , V_19 , 10 , V_27 | V_36 ) ;
V_19 += 10 ;
F_25 ( V_15 ,
V_42 ,
V_7 , V_19 , 10 , V_27 | V_36 ) ;
V_19 += 10 ;
V_13 = F_14 ( F_15 () , V_7 , V_19 , 20 , V_27 ) ;
F_28 ( V_15 ,
V_48 ,
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
F_25 ( V_9 ,
V_49 ,
V_7 , V_19 , - 1 , V_36 ) ;
break;
}
}
if ( V_18 == 'S' || V_18 == 'U' ) {
T_3 * V_50 ;
V_50 = F_29 ( V_7 , 3 ) ;
#if 0
if (try_conversation_dissector(&pinfo->dst, &pinfo->src, pinfo->ptype,
pinfo->srcport, pinfo->destport,
sub_tvb, pinfo, tree, NULL)) {
return;
}
#endif
if ( F_30 ( V_51 ,
V_50 ,
V_8 ,
V_9 ,
& V_23 ,
NULL ) ) {
return;
}
if ( V_9 ) {
F_25 ( V_15 ,
V_49 ,
V_50 , 0 , - 1 ,
V_36 ) ;
}
}
}
static T_11
F_31 (
T_4 * V_8 V_52 ,
T_3 * V_7 ,
int V_19 ,
void * T_13 V_52 )
{
return ( T_11 ) F_8 ( V_7 , V_19 ) + 2 ;
}
static int
F_32 (
T_3 * V_7 ,
T_4 * V_8 ,
T_5 * V_9 ,
void * T_13 V_52 )
{
F_6 ( V_7 , V_8 , V_9 ) ;
return F_33 ( V_7 ) ;
}
static int
F_34 (
T_3 * V_7 ,
T_4 * V_8 ,
T_5 * V_9 ,
void * T_13 )
{
F_35 ( V_7 , V_8 , V_9 ,
V_53 , 2 ,
F_31 ,
F_32 , T_13 ) ;
return F_33 ( V_7 ) ;
}
static void
F_36 ( void )
{
F_37 ( L_12 , V_54 , V_55 ) ;
F_38 ( V_54 ) ;
V_54 = F_39 ( V_56 ) ;
F_40 ( L_12 , V_54 , V_55 ) ;
}
void
F_41 ( void )
{
static T_14 V_57 [] = {
{ & V_38 ,
{ L_13 , L_14 ,
V_58 , V_59 , NULL , 0x0 ,
L_15 ,
V_60 } } ,
{ & V_40 ,
{ L_16 , L_17 ,
V_61 , V_62 , F_42 ( F_1 ) , 0x0 ,
L_18 ,
V_60 } } ,
{ & V_44 ,
{ L_19 , L_20 ,
V_61 , V_62 , F_42 ( F_5 ) , 0x0 ,
L_21 ,
V_60 } } ,
{ & V_49 ,
{ L_22 , L_23 ,
V_63 , V_64 , NULL , 0x0 ,
L_24 ,
V_60 } } ,
{ & V_41 ,
{ L_25 , L_26 ,
V_65 , V_64 , NULL , 0x0 ,
L_27 ,
V_60 } } ,
{ & V_46 ,
{ L_28 , L_29 ,
V_65 , V_64 , NULL , 0x0 ,
L_30 ,
V_60 } } ,
{ & V_47 ,
{ L_31 , L_32 ,
V_65 , V_64 , NULL , 0x0 ,
L_33 ,
V_60 } } ,
{ & V_42 ,
{ L_34 , L_35 ,
V_65 , V_64 , NULL , 0x0 ,
L_36
L_37 ,
V_60 } } ,
{ & V_45 ,
{ L_38 , L_39 ,
V_65 , V_64 , NULL , 0x0 ,
L_40 ,
V_60 } } ,
{ & V_43 ,
{ L_41 , L_42 ,
V_65 , V_64 , NULL , 0x0 ,
L_43 ,
V_60 } } ,
{ & V_48 ,
{ L_44 , L_45 ,
V_65 , V_64 , NULL , 0x0 ,
L_46
L_47
L_48 ,
V_60 } }
} ;
static T_10 * V_66 [] = {
& V_37
} ;
T_15 * V_67 ;
V_34
= F_43 ( L_5 , L_5 , L_49 ) ;
F_44 ( V_34 , V_57 , F_45 ( V_57 ) ) ;
F_46 ( V_66 , F_45 ( V_66 ) ) ;
V_67
= F_47 ( V_34 ,
F_36 ) ;
F_48 (
V_67 ,
L_50 ,
L_51 ,
L_52
L_53 ,
& V_53 ) ;
F_49 (
V_67 ,
L_12 ,
L_54 ,
L_55 ,
& V_56 ,
65535 ) ;
V_54 = F_50 () ;
V_51 = F_51 ( L_49 , V_34 ) ;
}
void
F_52 ( void )
{
V_55 = F_53 ( F_34 ,
V_34 ) ;
F_54 ( L_12 , V_55 ) ;
}
