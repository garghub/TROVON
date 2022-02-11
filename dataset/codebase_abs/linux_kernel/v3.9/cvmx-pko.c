void F_1 ( void )
{
int V_1 ;
T_1 V_2 = 8 ;
union V_3 V_4 ;
V_4 . V_5 = 0 ;
V_4 . V_6 . V_7 = V_8 ;
V_4 . V_6 . V_9 = V_10 / 8 - 1 ;
F_2 ( V_11 , V_4 . V_5 ) ;
for ( V_1 = 0 ; V_1 < V_12 ; V_1 ++ )
F_3 ( V_13 , V_1 , 1 ,
& V_2 ) ;
if ( F_4 ( V_14 ) || F_4 ( V_15 )
|| F_4 ( V_16 )
|| F_4 ( V_17 ) ) {
int V_18 = F_5 () ;
int V_19 =
F_6 ( V_18 - 1 ) ;
int V_20 =
F_7 ( V_19 ) +
F_8 ( V_19 ) ;
if ( F_4 ( V_14 ) ) {
if ( V_20 <= 32 )
F_2 ( V_21 , 2 ) ;
else if ( V_20 <= 64 )
F_2 ( V_21 , 1 ) ;
} else {
if ( V_20 <= 64 )
F_2 ( V_21 , 2 ) ;
else if ( V_20 <= 128 )
F_2 ( V_21 , 1 ) ;
}
}
}
int F_9 ( void )
{
return 0 ;
}
void F_10 ( void )
{
union V_22 V_23 ;
V_23 . V_5 = F_11 ( V_24 ) ;
if ( V_23 . V_6 . V_25 )
F_12
( L_1 ) ;
V_23 . V_6 . V_26 = 1 ;
V_23 . V_6 . V_25 = 1 ;
V_23 . V_6 . V_27 = 1 ;
F_2 ( V_24 , V_23 . V_5 ) ;
}
void F_13 ( void )
{
union V_22 V_28 ;
V_28 . V_5 = F_11 ( V_24 ) ;
V_28 . V_6 . V_25 = 0 ;
F_2 ( V_24 , V_28 . V_5 ) ;
}
static void F_14 ( void )
{
union V_22 V_28 ;
V_28 . V_5 = F_11 ( V_24 ) ;
V_28 . V_6 . V_29 = 1 ;
F_2 ( V_24 , V_28 . V_5 ) ;
}
void F_15 ( void )
{
union V_30 V_4 ;
int V_31 ;
F_13 () ;
for ( V_31 = 0 ; V_31 < V_12 ; V_31 ++ ) {
V_4 . V_5 = 0 ;
V_4 . V_6 . V_32 = 1 ;
V_4 . V_6 . V_33 = 0 ;
V_4 . V_6 . V_34 = V_13 ;
V_4 . V_6 . V_31 = V_31 & 0x7f ;
V_4 . V_6 . V_35 = 0 ;
V_4 . V_6 . V_36 = 0 ;
if ( ! F_4 ( V_37 ) ) {
union V_38 V_39 ;
V_39 . V_5 = 0 ;
V_39 . V_6 . V_40 = V_31 >> 7 ;
F_2 ( V_41 , V_39 . V_5 ) ;
}
F_2 ( V_42 , V_4 . V_5 ) ;
F_16 ( F_17 ( V_31 ) ) ;
}
F_14 () ;
}
T_2 F_3 ( T_1 V_34 , T_1 V_43 ,
T_1 V_44 ,
const T_1 V_2 [] )
{
T_2 V_45 ;
T_1 V_31 ;
union V_30 V_4 ;
union V_38 V_39 ;
int V_46 = - 1 ;
int V_47 = - 1 ;
if ( ( V_34 >= V_48 )
&& ( V_34 != V_13 ) ) {
F_12 ( L_2 ,
( unsigned long long ) V_34 ) ;
return V_49 ;
}
if ( V_43 + V_44 > V_12 ) {
F_12
( L_3 ,
( unsigned long long ) ( V_43 + V_44 ) ) ;
return V_50 ;
}
if ( V_34 != V_13 ) {
for ( V_31 = 0 ; V_31 < V_44 ; V_31 ++ ) {
if ( V_46 == - 1
&& V_2 [ V_31 ] ==
V_51 )
V_46 = V_31 ;
if ( V_46 != - 1
&& V_47 == - 1
&& V_2 [ V_31 ] != V_51
&& V_31 )
V_47 = V_31 - 1 ;
else if ( V_46 != - 1
&& V_47 == - 1
&& V_31 == V_44 - 1 )
V_47 = V_31 ;
if ( V_47 != - 1
&& ( int ) V_31 > V_47
&& V_2 [ V_31 ] ==
V_51 ) {
F_12 ( L_4
L_5
L_6
L_7 ,
( int ) V_31 , V_47 ) ;
return V_52 ;
}
}
if ( V_46 > 0 ) {
F_12 ( L_8
L_9
L_10 ,
V_46 ) ;
return V_52 ;
}
#if 0
cvmx_dprintf("Port %d: Static priority queue base: %d, "
"end: %d\n", port,
static_priority_base, static_priority_end);
#endif
}
V_45 = V_53 ;
#ifdef F_18
F_12 ( L_11 , V_44 ,
V_54 ,
V_55 ) ;
#endif
for ( V_31 = 0 ; V_31 < V_44 ; V_31 ++ ) {
T_1 * V_36 = NULL ;
V_39 . V_5 = 0 ;
V_39 . V_6 . V_56 = V_31 >> 3 ;
V_39 . V_6 . V_40 = ( V_43 + V_31 ) >> 7 ;
V_4 . V_5 = 0 ;
V_4 . V_6 . V_32 = V_31 == ( V_44 - 1 ) ;
V_4 . V_6 . V_33 = V_31 ;
V_4 . V_6 . V_34 = V_34 ;
V_4 . V_6 . V_31 = V_43 + V_31 ;
if ( ! F_19 () ) {
V_4 . V_6 . V_57 = V_46 >= 0 ;
V_4 . V_6 . V_58 = ( int ) V_31 <= V_47 ;
V_4 . V_6 . V_59 = ( int ) V_31 == V_47 ;
}
switch ( ( int ) V_2 [ V_31 ] ) {
case 0 :
V_4 . V_6 . V_35 = 0x00 ;
break;
case 1 :
V_4 . V_6 . V_35 = 0x01 ;
break;
case 2 :
V_4 . V_6 . V_35 = 0x11 ;
break;
case 3 :
V_4 . V_6 . V_35 = 0x49 ;
break;
case 4 :
V_4 . V_6 . V_35 = 0x55 ;
break;
case 5 :
V_4 . V_6 . V_35 = 0x57 ;
break;
case 6 :
V_4 . V_6 . V_35 = 0x77 ;
break;
case 7 :
V_4 . V_6 . V_35 = 0x7f ;
break;
case 8 :
V_4 . V_6 . V_35 = 0xff ;
break;
case V_51 :
if ( ! F_19 () ) {
V_4 . V_6 . V_35 = 0xff ;
break;
}
default:
F_12 ( L_12
L_13 ,
( unsigned long long ) V_2 [ V_31 ] ) ;
V_4 . V_6 . V_35 = 0xff ;
V_45 = V_52 ;
break;
}
if ( V_34 != V_13 ) {
T_3 V_60 =
F_20 ( F_17
( V_43 + V_31 ) ,
V_61 ,
V_8 ,
V_10
-
V_62
* 8 ) ;
if ( V_60 != V_63 ) {
switch ( V_60 ) {
case V_64 :
F_12 ( L_14
L_15
L_16
L_17 ) ;
return V_65 ;
case V_66 :
F_12
( L_18 ) ;
return V_67 ;
case V_68 :
default:
F_12
( L_19 ) ;
return V_69 ;
}
}
V_36 =
( T_1 * )
F_21 ( F_17
( V_43 + V_31 ) ) ;
V_4 . V_6 . V_36 = F_22 ( V_36 ) ;
} else
V_4 . V_6 . V_36 = 0 ;
V_70 ;
if ( ! F_4 ( V_37 ) )
F_2 ( V_41 , V_39 . V_5 ) ;
F_2 ( V_42 , V_4 . V_5 ) ;
}
return V_45 ;
}
void F_23 ()
{
int V_71 , V_34 ;
int V_72 = 36 ;
F_12 ( L_20 ) ;
for ( V_34 = 0 ; V_34 < V_72 ; V_34 ++ )
F_12 ( L_21 , V_34 ) ;
F_12 ( L_22 ) ;
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
F_12 ( L_23 , V_71 ) ;
for ( V_34 = 0 ; V_34 < V_72 ; V_34 ++ ) {
F_12 ( L_21 ,
F_24 ( V_34 ,
V_71 ) ) ;
}
}
F_12 ( L_22 ) ;
}
int F_25 ( int V_34 , int V_74 , int V_75 )
{
union V_76 V_77 ;
union V_78 V_79 ;
V_77 . V_5 = 0 ;
V_77 . V_6 . V_80 = V_34 ;
V_77 . V_6 . V_81 =
F_26 () -> V_82 / V_74 / 16 ;
V_77 . V_6 . V_83 = 0 ;
V_79 . V_5 = 0 ;
V_79 . V_6 . V_80 = V_34 ;
V_79 . V_6 . V_84 =
( ( T_1 ) V_77 . V_6 . V_81 * V_75 ) >> 8 ;
F_2 ( V_85 , V_77 . V_5 ) ;
F_2 ( V_86 , V_79 . V_5 ) ;
return 0 ;
}
int F_27 ( int V_34 , T_1 V_87 , int V_75 )
{
union V_76 V_77 ;
union V_78 V_79 ;
T_1 V_88 = F_26 () -> V_82 ;
T_1 V_89 = V_88 * 16 / V_87 ;
V_77 . V_5 = 0 ;
V_77 . V_6 . V_80 = V_34 ;
V_77 . V_6 . V_81 = ( 12 + 8 + 4 ) * 8 * V_89 / 256 ;
V_77 . V_6 . V_83 = 64 * V_89 ;
V_79 . V_5 = 0 ;
V_79 . V_6 . V_80 = V_34 ;
V_79 . V_6 . V_84 = V_89 * V_75 / 256 ;
F_2 ( V_85 , V_77 . V_5 ) ;
F_2 ( V_86 , V_79 . V_5 ) ;
return 0 ;
}
