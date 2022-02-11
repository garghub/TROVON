static int F_1 ( int V_1 , int V_2 )
{
switch ( V_1 ) {
case 0 :
return V_2 ;
case 1 :
return 4 ;
case 2 :
return V_2 + 0x08 ;
case 3 :
return V_2 + 0x0c ;
case 4 :
return V_2 + 0x10 ;
case 5 :
return 0x1c ;
case 6 :
return 0x1d ;
case 7 :
return 0x1e ;
case 8 :
return 0x1f ;
default:
return - 1 ;
}
}
static void F_2 ( int V_3 )
{
int V_4 ;
const int V_5 = 1 ;
const int V_6 = V_3 ;
const int V_7 = 1 ;
const int V_8 = 1 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
union V_9 V_10 ;
T_1 V_11 ;
T_2 * V_12 ;
V_10 . V_13 = 0 ;
V_10 . V_14 . V_2 = V_4 ;
V_10 . V_14 . V_15 = V_6 + V_4 ;
V_10 . V_14 . V_16 = V_3 ;
V_10 . V_14 . V_17 = ( V_4 == ( V_5 - 1 ) ) ;
V_10 . V_14 . V_18 = ( V_4 == V_7 ) ;
V_10 . V_14 . V_19 = ( V_8 >= 0 ) ;
V_10 . V_14 . V_20 = ( V_4 <= V_7 ) ;
V_10 . V_14 . V_21 = 0xff ;
V_11 = F_3 (
F_4 ( V_6 + V_4 ) ,
V_22 ,
V_23 ,
( V_24 -
V_25 * 8 ) ) ;
F_5 ( V_11 ,
L_1 ,
V_26 , ( int ) V_11 , V_3 , V_6 ,
V_5 , V_4 ) ;
V_12 = ( T_2 * ) F_6 (
F_4 ( V_6 + V_4 ) ) ;
V_10 . V_14 . V_12 = F_7 ( V_12 ) >> 7 ;
V_27 ;
F_8 ( V_28 , V_10 . V_13 ) ;
}
}
static void F_9 ( void )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < 48 ; V_29 ++ )
F_2 ( V_29 ) ;
}
static void F_10 ( void )
{
int V_29 ;
int V_1 , V_2 ;
T_3 V_30 ;
union V_31 V_10 ;
V_10 . V_13 = 0 ;
V_10 . V_14 . V_32 = 31 ;
for ( V_29 = 0 ; V_29 < 128 ; V_29 ++ ) {
V_10 . V_14 . V_16 = V_29 ;
F_8 ( V_33 , V_10 . V_13 ) ;
}
for ( V_29 = 0 ; V_29 < 48 ; V_29 ++ ) {
V_1 = F_11 ( V_29 ) ;
V_2 = F_12 ( V_29 ) ;
V_30 = F_13 ( V_1 ) ;
if ( V_30 == V_34 )
continue;
V_10 . V_14 . V_16 = V_29 ;
V_10 . V_14 . V_21 = 0xff ;
V_10 . V_14 . V_35 = 1 ;
V_10 . V_14 . V_36 = 1 ;
V_10 . V_14 . V_37 = F_1 ( V_1 , V_2 ) ;
V_10 . V_14 . V_32 = V_10 . V_14 . V_37 ;
V_10 . V_14 . V_38 = ( V_30 == V_39 ) ?
V_2 : V_29 ;
F_8 ( V_33 , V_10 . V_13 ) ;
}
}
static void F_14 ( void )
{
int V_40 ;
if ( F_15 ( V_41 ) ) {
F_10 () ;
F_9 () ;
return;
}
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ ) {
const T_2 V_43 = 8 ;
F_16 ( V_44 , V_40 , 1 ,
& V_43 ) ;
}
}
void F_17 ( void )
{
union V_45 V_10 ;
V_10 . V_13 = 0 ;
V_10 . V_14 . V_46 = V_23 ;
V_10 . V_14 . V_47 = V_24 / 8 - 1 ;
F_8 ( V_48 , V_10 . V_13 ) ;
F_14 () ;
if ( F_15 ( V_49 ) || F_15 ( V_50 )
|| F_15 ( V_51 )
|| F_15 ( V_52 ) ) {
int V_53 = F_18 () ;
int V_54 =
F_19 ( V_53 - 1 ) ;
int V_55 =
F_20 ( V_54 ) +
F_21 ( V_54 ) ;
if ( F_15 ( V_49 ) ) {
if ( V_55 <= 32 )
F_8 ( V_56 , 2 ) ;
else if ( V_55 <= 64 )
F_8 ( V_56 , 1 ) ;
} else {
if ( V_55 <= 64 )
F_8 ( V_56 , 2 ) ;
else if ( V_55 <= 128 )
F_8 ( V_56 , 1 ) ;
}
}
}
int F_22 ( void )
{
return 0 ;
}
void F_23 ( void )
{
union V_57 V_58 ;
V_58 . V_13 = F_24 ( V_59 ) ;
if ( V_58 . V_14 . V_60 )
F_25
( L_2 ) ;
V_58 . V_14 . V_61 = 1 ;
V_58 . V_14 . V_60 = 1 ;
V_58 . V_14 . V_62 = 1 ;
F_8 ( V_59 , V_58 . V_13 ) ;
}
void F_26 ( void )
{
union V_57 V_63 ;
V_63 . V_13 = F_24 ( V_59 ) ;
V_63 . V_14 . V_60 = 0 ;
F_8 ( V_59 , V_63 . V_13 ) ;
}
static void F_27 ( void )
{
union V_57 V_63 ;
V_63 . V_13 = F_24 ( V_59 ) ;
V_63 . V_14 . V_64 = 1 ;
F_8 ( V_59 , V_63 . V_13 ) ;
}
void F_28 ( void )
{
union V_65 V_10 ;
int V_4 ;
F_26 () ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ ) {
V_10 . V_13 = 0 ;
V_10 . V_14 . V_17 = 1 ;
V_10 . V_14 . V_2 = 0 ;
V_10 . V_14 . V_29 = V_44 ;
V_10 . V_14 . V_4 = V_4 & 0x7f ;
V_10 . V_14 . V_21 = 0 ;
V_10 . V_14 . V_12 = 0 ;
if ( ! F_15 ( V_66 ) ) {
union V_67 V_68 ;
V_68 . V_13 = 0 ;
V_68 . V_14 . V_69 = V_4 >> 7 ;
F_8 ( V_70 , V_68 . V_13 ) ;
}
F_8 ( V_71 , V_10 . V_13 ) ;
F_29 ( F_4 ( V_4 ) ) ;
}
F_27 () ;
}
T_4 F_16 ( T_2 V_29 , T_2 V_6 ,
T_2 V_5 ,
const T_2 V_43 [] )
{
T_4 V_72 ;
T_2 V_4 ;
union V_65 V_10 ;
union V_67 V_68 ;
int V_8 = - 1 ;
int V_7 = - 1 ;
if ( F_15 ( V_41 ) )
return V_73 ;
if ( ( V_29 >= V_74 )
&& ( V_29 != V_44 ) ) {
F_25 ( L_3 ,
( unsigned long long ) V_29 ) ;
return V_75 ;
}
if ( V_6 + V_5 > V_42 ) {
F_25
( L_4 ,
( unsigned long long ) ( V_6 + V_5 ) ) ;
return V_76 ;
}
if ( V_29 != V_44 ) {
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_8 == - 1
&& V_43 [ V_4 ] ==
V_77 )
V_8 = V_4 ;
if ( V_8 != - 1
&& V_7 == - 1
&& V_43 [ V_4 ] != V_77
&& V_4 )
V_7 = V_4 - 1 ;
else if ( V_8 != - 1
&& V_7 == - 1
&& V_4 == V_5 - 1 )
V_7 = V_4 ;
if ( V_7 != - 1
&& ( int ) V_4 > V_7
&& V_43 [ V_4 ] ==
V_77 ) {
F_25 ( L_5
L_6
L_7
L_8 ,
( int ) V_4 , V_7 ) ;
return V_78 ;
}
}
if ( V_8 > 0 ) {
F_25 ( L_9
L_10
L_11 ,
V_8 ) ;
return V_78 ;
}
#if 0
cvmx_dprintf("Port %d: Static priority queue base: %d, "
"end: %d\n", port,
static_priority_base, static_priority_end);
#endif
}
V_72 = V_73 ;
#ifdef F_30
F_25 ( L_12 , V_5 ,
V_79 ,
V_80 ) ;
#endif
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
T_2 * V_12 = NULL ;
V_68 . V_13 = 0 ;
V_68 . V_14 . V_81 = V_4 >> 3 ;
V_68 . V_14 . V_69 = ( V_6 + V_4 ) >> 7 ;
V_10 . V_13 = 0 ;
V_10 . V_14 . V_17 = V_4 == ( V_5 - 1 ) ;
V_10 . V_14 . V_2 = V_4 ;
V_10 . V_14 . V_29 = V_29 ;
V_10 . V_14 . V_4 = V_6 + V_4 ;
if ( ! F_31 () ) {
V_10 . V_14 . V_19 = V_8 >= 0 ;
V_10 . V_14 . V_20 = ( int ) V_4 <= V_7 ;
V_10 . V_14 . V_18 = ( int ) V_4 == V_7 ;
}
switch ( ( int ) V_43 [ V_4 ] ) {
case 0 :
V_10 . V_14 . V_21 = 0x00 ;
break;
case 1 :
V_10 . V_14 . V_21 = 0x01 ;
break;
case 2 :
V_10 . V_14 . V_21 = 0x11 ;
break;
case 3 :
V_10 . V_14 . V_21 = 0x49 ;
break;
case 4 :
V_10 . V_14 . V_21 = 0x55 ;
break;
case 5 :
V_10 . V_14 . V_21 = 0x57 ;
break;
case 6 :
V_10 . V_14 . V_21 = 0x77 ;
break;
case 7 :
V_10 . V_14 . V_21 = 0x7f ;
break;
case 8 :
V_10 . V_14 . V_21 = 0xff ;
break;
case V_77 :
if ( ! F_31 () ) {
V_10 . V_14 . V_21 = 0xff ;
break;
}
default:
F_25 ( L_13
L_14 ,
( unsigned long long ) V_43 [ V_4 ] ) ;
V_10 . V_14 . V_21 = 0xff ;
V_72 = V_78 ;
break;
}
if ( V_29 != V_44 ) {
T_1 V_11 =
F_3 ( F_4
( V_6 + V_4 ) ,
V_22 ,
V_23 ,
V_24
-
V_25
* 8 ) ;
if ( V_11 != V_82 ) {
switch ( V_11 ) {
case V_83 :
F_25 ( L_15
L_16
L_17
L_18 ) ;
return V_84 ;
case V_85 :
F_25
( L_19 ) ;
return V_86 ;
case V_87 :
default:
F_25
( L_20 ) ;
return V_88 ;
}
}
V_12 =
( T_2 * )
F_6 ( F_4
( V_6 + V_4 ) ) ;
V_10 . V_14 . V_12 = F_7 ( V_12 ) ;
} else
V_10 . V_14 . V_12 = 0 ;
V_27 ;
if ( ! F_15 ( V_66 ) )
F_8 ( V_70 , V_68 . V_13 ) ;
F_8 ( V_71 , V_10 . V_13 ) ;
}
return V_72 ;
}
void F_32 ()
{
int V_89 , V_29 ;
int V_90 = 36 ;
F_25 ( L_21 ) ;
for ( V_29 = 0 ; V_29 < V_90 ; V_29 ++ )
F_25 ( L_22 , V_29 ) ;
F_25 ( L_23 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
F_25 ( L_24 , V_89 ) ;
for ( V_29 = 0 ; V_29 < V_90 ; V_29 ++ ) {
F_25 ( L_22 ,
F_33 ( V_29 ,
V_89 ) ) ;
}
}
F_25 ( L_23 ) ;
}
int F_34 ( int V_29 , int V_92 , int V_93 )
{
union V_94 V_95 ;
union V_96 V_97 ;
V_95 . V_13 = 0 ;
V_95 . V_14 . V_98 = V_29 ;
V_95 . V_14 . V_99 =
F_35 () -> V_100 / V_92 / 16 ;
V_95 . V_14 . V_101 = 0 ;
V_97 . V_13 = 0 ;
V_97 . V_14 . V_98 = V_29 ;
V_97 . V_14 . V_102 =
( ( T_2 ) V_95 . V_14 . V_99 * V_93 ) >> 8 ;
F_8 ( V_103 , V_95 . V_13 ) ;
F_8 ( V_104 , V_97 . V_13 ) ;
return 0 ;
}
int F_36 ( int V_29 , T_2 V_105 , int V_93 )
{
union V_94 V_95 ;
union V_96 V_97 ;
T_2 V_106 = F_35 () -> V_100 ;
T_2 V_107 = V_106 * 16 / V_105 ;
V_95 . V_13 = 0 ;
V_95 . V_14 . V_98 = V_29 ;
V_95 . V_14 . V_99 = ( 12 + 8 + 4 ) * 8 * V_107 / 256 ;
V_95 . V_14 . V_101 = 64 * V_107 ;
V_97 . V_13 = 0 ;
V_97 . V_14 . V_98 = V_29 ;
V_97 . V_14 . V_102 = V_107 * V_93 / 256 ;
F_8 ( V_103 , V_95 . V_13 ) ;
F_8 ( V_104 , V_97 . V_13 ) ;
return 0 ;
}
