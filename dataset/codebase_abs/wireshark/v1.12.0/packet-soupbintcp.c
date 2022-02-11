static void
F_1 (
T_1 * V_1 ,
T_2 V_2 )
{
F_2 ( V_1 , V_3 ,
L_1 ,
F_3 ( V_2 , V_4 , L_2 ) ,
( char ) ( V_2 & 0xff ) ) ;
}
static void
F_4 (
T_1 * V_1 ,
T_2 V_2 )
{
F_2 ( V_1 , V_3 ,
L_1 ,
F_3 ( V_2 , V_5 , L_3 ) ,
( char ) ( V_2 & 0xff ) ) ;
}
static void
F_5 (
T_3 * V_6 ,
T_4 * V_7 ,
T_5 * V_8 )
{
struct V_9 * V_9 ;
struct V_10 * V_10 ;
const char * V_11 ;
const char * V_12 ;
T_6 * V_13 ;
T_5 * V_14 = NULL ;
T_7 * V_15 = NULL ;
T_8 V_16 ;
T_9 V_17 ;
T_10 V_18 = 0 ;
T_11 V_19 = 0 , V_20 ;
T_12 * V_21 ;
V_16 = F_6 ( V_6 , 0 ) ;
V_17 = F_7 ( V_6 , 2 ) ;
V_11 = F_3 ( V_17 , V_4 , L_4 ) ;
F_8 ( V_7 -> V_22 , V_23 , L_5 ) ;
F_9 ( V_7 -> V_22 , V_24 , V_11 ) ;
if ( V_17 == 'A' && ! F_10 ( V_7 ) ) {
V_12 = F_11 ( F_12 () , V_6 , 13 , 20 ) ;
V_20 = atoi ( V_12 ) ;
V_15 = F_13 ( F_14 ( V_7 ) ,
& V_7 -> V_25 ,
& V_7 -> V_26 ,
V_7 -> V_27 ,
V_7 -> V_28 ,
V_7 -> V_29 ,
0 ) ;
V_9 = (struct V_9 * ) F_15 ( F_16 () , sizeof( struct V_9 ) ) ;
V_9 -> V_20 = V_20 ;
F_17 ( V_15 , V_30 , V_9 ) ;
}
if ( V_17 == 'S' ) {
if ( ! F_10 ( V_7 ) ) {
V_15 = F_18 ( F_14 ( V_7 ) ,
& V_7 -> V_25 ,
& V_7 -> V_26 ,
V_7 -> V_27 ,
V_7 -> V_28 ,
V_7 -> V_29 ,
0 ) ;
if ( ! V_15 ) {
V_19 = 0 ;
} else {
V_9 = (struct V_9 * ) F_19 ( V_15 ,
V_30 ) ;
if ( V_9 ) {
V_19 = V_9 -> V_20 ++ ;
} else {
V_19 = 0 ;
}
V_10 = (struct V_10 * ) F_15 (
F_16 () ,
sizeof( struct V_10 ) ) ;
V_10 -> V_31 = V_19 ;
F_20 ( F_16 () , V_7 , V_30 , 0 , V_10 ) ;
}
} else {
V_10 = (struct V_10 * ) F_21 ( F_16 () , V_7 , V_30 , 0 ) ;
if ( V_10 ) {
V_19 = V_10 -> V_31 ;
} else {
V_19 = 0 ;
}
}
F_22 ( V_7 -> V_22 , V_24 , L_6 , V_19 ) ;
}
if ( V_8 ) {
V_13 = F_23 ( V_8 ,
V_30 ,
V_6 , 0 , - 1 , V_32 ) ;
V_14 = F_24 ( V_13 , V_33 ) ;
F_25 ( V_13 , L_7 , V_11 ) ;
F_23 ( V_14 ,
V_34 ,
V_6 , V_18 , 2 , V_35 ) ;
V_18 += 2 ;
F_23 ( V_14 ,
V_36 ,
V_6 , V_18 , 1 , V_35 ) ;
V_18 += 1 ;
switch ( V_17 ) {
case '+' :
F_23 ( V_14 ,
V_37 ,
V_6 , V_18 , V_16 - 1 , V_38 | V_32 ) ;
break;
case 'A' :
F_23 ( V_14 ,
V_39 ,
V_6 , V_18 , 10 , V_38 | V_32 ) ;
V_18 += 10 ;
V_12 = F_11 ( F_12 () , V_6 , V_18 , 20 ) ;
F_26 ( V_14 ,
V_40 ,
V_6 , V_18 , 20 ,
L_8 , L_9 , atoi ( V_12 ) ) ;
break;
case 'J' :
F_23 ( V_14 ,
V_41 ,
V_6 , V_18 , 1 , V_35 ) ;
break;
case 'U' :
break;
case 'S' :
F_25 ( V_13 , L_10 , V_19 ) ;
F_26 ( V_14 ,
V_42 ,
V_6 , V_18 , 0 ,
L_8 ,
L_11 ,
V_19 ) ;
break;
case 'L' :
F_23 ( V_14 ,
V_43 ,
V_6 , V_18 , 6 , V_38 | V_32 ) ;
V_18 += 6 ;
F_23 ( V_14 ,
V_44 ,
V_6 , V_18 , 10 , V_38 | V_32 ) ;
V_18 += 10 ;
F_23 ( V_14 ,
V_39 ,
V_6 , V_18 , 10 , V_38 | V_32 ) ;
V_18 += 10 ;
V_12 = F_11 ( F_12 () , V_6 , V_18 , 20 ) ;
F_26 ( V_14 ,
V_45 ,
V_6 , V_18 , 20 ,
L_8 , L_9 , atoi ( V_12 ) ) ;
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
F_23 ( V_8 ,
V_46 ,
V_6 , V_18 , - 1 , V_38 | V_32 ) ;
break;
}
}
if ( V_17 == 'S' || V_17 == 'U' ) {
T_3 * V_47 ;
V_47 = F_27 ( V_6 , 3 ) ;
#if 0
if (try_conversation_dissector(&pinfo->dst, &pinfo->src, pinfo->ptype,
pinfo->srcport, pinfo->destport,
sub_tvb, pinfo, tree, NULL)) {
return;
}
#endif
if ( F_28 ( V_48 ,
V_47 ,
V_7 ,
V_8 ,
& V_21 ,
NULL ) ) {
return;
}
if ( V_8 ) {
F_23 ( V_14 ,
V_46 ,
V_47 , 0 , - 1 ,
V_38 | V_32 ) ;
}
}
}
static T_11
F_29 (
T_4 * V_7 V_49 ,
T_3 * V_6 ,
int V_18 )
{
return ( T_11 ) F_6 ( V_6 , V_18 ) + 2 ;
}
static int
F_30 (
T_3 * V_6 ,
T_4 * V_7 ,
T_5 * V_8 ,
void * T_13 V_49 )
{
F_5 ( V_6 , V_7 , V_8 ) ;
return F_31 ( V_6 ) ;
}
static int
F_32 (
T_3 * V_6 ,
T_4 * V_7 ,
T_5 * V_8 ,
void * T_13 )
{
F_33 ( V_6 , V_7 , V_8 ,
V_50 , 2 ,
F_29 ,
F_30 , T_13 ) ;
return F_31 ( V_6 ) ;
}
static void
F_34 ( void )
{
F_35 ( L_12 , V_51 , V_52 ) ;
F_36 ( V_51 ) ;
V_51 = F_37 ( V_53 ) ;
F_38 ( L_12 , V_51 , V_52 ) ;
}
void
F_39 ( void )
{
static T_14 V_54 [] = {
{ & V_34 ,
{ L_13 , L_14 ,
V_55 , V_56 , NULL , 0x0 ,
L_15 ,
V_57 } } ,
{ & V_36 ,
{ L_16 , L_17 ,
V_58 , V_59 , F_1 , 0x0 ,
L_18 ,
V_57 } } ,
{ & V_41 ,
{ L_19 , L_20 ,
V_58 , V_59 , F_4 , 0x0 ,
L_21 ,
V_57 } } ,
{ & V_46 ,
{ L_22 , L_23 ,
V_60 , V_61 , NULL , 0x0 ,
L_24 ,
V_57 } } ,
{ & V_37 ,
{ L_25 , L_26 ,
V_62 , V_61 , NULL , 0x0 ,
L_27 ,
V_57 } } ,
{ & V_43 ,
{ L_28 , L_29 ,
V_62 , V_61 , NULL , 0x0 ,
L_30 ,
V_57 } } ,
{ & V_44 ,
{ L_31 , L_32 ,
V_62 , V_61 , NULL , 0x0 ,
L_33 ,
V_57 } } ,
{ & V_39 ,
{ L_34 , L_35 ,
V_62 , V_61 , NULL , 0x0 ,
L_36
L_37 ,
V_57 } } ,
{ & V_42 ,
{ L_38 , L_39 ,
V_62 , V_61 , NULL , 0x0 ,
L_40 ,
V_57 } } ,
{ & V_40 ,
{ L_41 , L_42 ,
V_62 , V_61 , NULL , 0x0 ,
L_43 ,
V_57 } } ,
{ & V_45 ,
{ L_44 , L_45 ,
V_62 , V_61 , NULL , 0x0 ,
L_46
L_47
L_48 ,
V_57 } }
} ;
static T_10 * V_63 [] = {
& V_33
} ;
T_15 * V_64 ;
V_30
= F_40 ( L_5 , L_5 , L_49 ) ;
F_41 ( V_30 , V_54 , F_42 ( V_54 ) ) ;
F_43 ( V_63 , F_42 ( V_63 ) ) ;
V_64
= F_44 ( V_30 ,
F_34 ) ;
F_45 (
V_64 ,
L_50 ,
L_51 ,
L_52
L_53 ,
& V_50 ) ;
F_46 (
V_64 ,
L_12 ,
L_54 ,
L_55 ,
& V_53 ,
65535 ) ;
V_51 = F_47 () ;
F_48 ( L_49 , & V_48 ) ;
}
void
F_49 ( void )
{
V_52 = F_50 ( F_32 ,
V_30 ) ;
F_51 ( L_12 , V_52 ) ;
}
