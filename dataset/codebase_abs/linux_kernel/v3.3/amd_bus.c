static int T_1 F_1 ( void )
{
int V_1 ;
int V_2 ;
unsigned V_3 ;
unsigned V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
int V_8 ;
struct V_9 * V_10 ;
T_2 V_11 ;
struct V_12 * V_13 ;
T_3 V_14 ;
T_3 V_15 ;
struct V_16 V_16 [ V_17 ] ;
T_3 V_18 ;
T_2 V_19 ;
bool V_20 ;
struct V_12 V_21 , * V_22 ;
T_3 V_23 ;
T_3 V_24 ;
if ( ! F_2 () )
return - 1 ;
V_20 = false ;
for ( V_1 = 0 ; V_1 < F_3 ( V_25 ) ; V_1 ++ ) {
T_2 V_26 ;
T_4 V_27 ;
T_4 V_28 ;
V_3 = V_25 [ V_1 ] . V_3 ;
V_4 = V_25 [ V_1 ] . V_4 ;
V_26 = F_4 ( V_3 , V_4 , 0 , V_29 ) ;
V_28 = V_26 & 0xffff ;
V_27 = ( V_26 >> 16 ) & 0xffff ;
if ( V_25 [ V_1 ] . V_28 == V_28 &&
V_25 [ V_1 ] . V_27 == V_27 ) {
V_20 = true ;
break;
}
}
if ( ! V_20 )
return 0 ;
V_30 = 0 ;
for ( V_1 = 0 ; V_1 < 4 ; V_1 ++ ) {
int V_31 ;
int V_32 ;
V_11 = F_4 ( V_3 , V_4 , 1 , 0xe0 + ( V_1 << 2 ) ) ;
if ( ( V_11 & 7 ) != 3 )
continue;
V_31 = ( V_11 >> 16 ) & 0xff ;
V_32 = ( V_11 >> 24 ) & 0xff ;
V_5 = ( V_11 >> 4 ) & 0x07 ;
#ifdef F_5
for ( V_2 = V_31 ; V_2 <= V_32 ; V_2 ++ )
F_6 ( V_2 , V_5 ) ;
#endif
V_6 = ( V_11 >> 8 ) & 0x03 ;
V_10 = & V_9 [ V_30 ] ;
V_10 -> V_33 = V_31 ;
V_10 -> V_34 = V_32 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = V_6 ;
sprintf ( V_10 -> V_35 , L_1 , V_31 ) ;
V_30 ++ ;
}
V_11 = F_4 ( V_3 , V_4 , 0 , 0x60 ) ;
V_7 = ( V_11 >> 8 ) & 0x07 ;
V_11 = F_4 ( V_3 , V_4 , 0 , 0x64 ) ;
V_8 = ( V_11 >> 8 ) & 0x03 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
F_7 ( V_16 , V_17 , 0 , 0 , 0xffff + 1 ) ;
for ( V_1 = 0 ; V_1 < 4 ; V_1 ++ ) {
V_11 = F_4 ( V_3 , V_4 , 1 , 0xc0 + ( V_1 << 3 ) ) ;
if ( ! ( V_11 & 3 ) )
continue;
V_14 = V_11 & 0xfff000 ;
V_11 = F_4 ( V_3 , V_4 , 1 , 0xc4 + ( V_1 << 3 ) ) ;
V_5 = V_11 & 0x07 ;
V_6 = ( V_11 >> 4 ) & 0x03 ;
V_15 = ( V_11 & 0xfff000 ) | 0xfff ;
for ( V_2 = 0 ; V_2 < V_30 ; V_2 ++ ) {
V_10 = & V_9 [ V_2 ] ;
if ( V_10 -> V_5 == V_5 && V_10 -> V_6 == V_6 )
break;
}
if ( V_2 == V_30 )
continue;
V_10 = & V_9 [ V_2 ] ;
F_8 ( V_36 L_2 ,
V_5 , V_6 , V_14 , V_15 ) ;
if ( V_15 > 0xffff )
V_15 = 0xffff ;
F_9 ( V_10 , V_14 , V_15 , V_37 , 1 ) ;
F_10 ( V_16 , V_17 , V_14 , V_15 + 1 ) ;
}
for ( V_2 = 0 ; V_2 < V_30 ; V_2 ++ ) {
V_10 = & V_9 [ V_2 ] ;
if ( V_10 -> V_5 == V_7 && V_10 -> V_6 == V_8 )
break;
}
if ( V_2 < V_30 ) {
V_10 = & V_9 [ V_2 ] ;
for ( V_1 = 0 ; V_1 < V_17 ; V_1 ++ ) {
if ( ! V_16 [ V_1 ] . V_15 )
continue;
F_9 ( V_10 , V_16 [ V_1 ] . V_14 , V_16 [ V_1 ] . V_15 - 1 ,
V_37 , 1 ) ;
}
}
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_15 = F_11 ( ( 0xfdULL << 32 ) - 1 ) ;
V_15 ++ ;
F_7 ( V_16 , V_17 , 0 , 0 , V_15 ) ;
V_19 = V_38 ;
F_12 ( V_19 , V_18 ) ;
V_15 = ( V_18 & 0xffffff800000ULL ) ;
F_8 ( V_39 L_3 , V_15 , V_15 >> 20 ) ;
if ( V_15 < ( 1ULL << 32 ) )
F_10 ( V_16 , V_17 , 0 , V_15 ) ;
V_22 = F_13 ( & V_21 ) ;
if ( V_22 ) {
F_8 ( V_36 L_4 , V_22 ) ;
V_23 = V_22 -> V_14 ;
V_24 = V_22 -> V_15 ;
F_10 ( V_16 , V_17 , V_23 ,
V_24 + 1 ) ;
} else {
V_23 = 0 ;
V_24 = 0 ;
}
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
V_11 = F_4 ( V_3 , V_4 , 1 , 0x80 + ( V_1 << 3 ) ) ;
if ( ! ( V_11 & 3 ) )
continue;
V_14 = V_11 & 0xffffff00 ;
V_14 <<= 8 ;
V_11 = F_4 ( V_3 , V_4 , 1 , 0x84 + ( V_1 << 3 ) ) ;
V_5 = V_11 & 0x07 ;
V_6 = ( V_11 >> 4 ) & 0x03 ;
V_15 = ( V_11 & 0xffffff00 ) ;
V_15 <<= 8 ;
V_15 |= 0xffff ;
for ( V_2 = 0 ; V_2 < V_30 ; V_2 ++ ) {
V_10 = & V_9 [ V_2 ] ;
if ( V_10 -> V_5 == V_5 && V_10 -> V_6 == V_6 )
break;
}
if ( V_2 == V_30 )
continue;
V_10 = & V_9 [ V_2 ] ;
F_8 ( V_36 L_5 ,
V_5 , V_6 , V_14 , V_15 ) ;
if ( V_24 ) {
int V_40 = 0 ;
T_3 V_41 = 0 ;
if ( V_14 >= V_23 &&
V_14 <= V_24 ) {
V_14 = V_24 + 1 ;
V_40 = 1 ;
}
if ( V_15 >= V_23 &&
V_15 <= V_24 ) {
V_15 = V_23 - 1 ;
V_40 = 1 ;
}
if ( V_14 < V_23 &&
V_15 > V_24 ) {
V_41 = V_23 - 1 ;
F_9 ( V_10 , V_14 , V_41 , V_42 , 0 ) ;
F_10 ( V_16 , V_17 , V_14 ,
V_41 + 1 ) ;
F_8 ( V_43 L_6 , V_14 , V_41 ) ;
V_14 = V_24 + 1 ;
V_40 = 1 ;
}
if ( V_40 ) {
if ( V_14 <= V_15 ) {
F_8 ( V_43 L_7 , V_41 ? L_8 : L_9 , V_14 , V_15 ) ;
} else {
F_8 ( V_43 L_10 , V_41 ? L_11 : L_12 ) ;
continue;
}
}
}
F_9 ( V_10 , F_11 ( V_14 ) , F_11 ( V_15 ) ,
V_42 , 1 ) ;
F_10 ( V_16 , V_17 , V_14 , V_15 + 1 ) ;
F_8 ( V_43 L_13 ) ;
}
V_19 = V_44 ;
F_12 ( V_19 , V_18 ) ;
if ( V_18 & ( 1 << 21 ) ) {
V_19 = V_45 ;
F_12 ( V_19 , V_18 ) ;
V_15 = ( V_18 & 0xffffff800000ULL ) ;
F_8 ( V_39 L_14 , V_15 , V_15 >> 20 ) ;
F_10 ( V_16 , V_17 , 1ULL << 32 , V_15 ) ;
}
for ( V_2 = 0 ; V_2 < V_30 ; V_2 ++ ) {
V_10 = & V_9 [ V_2 ] ;
if ( V_10 -> V_5 == V_7 && V_10 -> V_6 == V_8 )
break;
}
if ( V_2 < V_30 ) {
V_10 = & V_9 [ V_2 ] ;
for ( V_1 = 0 ; V_1 < V_17 ; V_1 ++ ) {
if ( ! V_16 [ V_1 ] . V_15 )
continue;
F_9 ( V_10 , F_11 ( V_16 [ V_1 ] . V_14 ) ,
F_11 ( V_16 [ V_1 ] . V_15 - 1 ) ,
V_42 , 1 ) ;
}
}
for ( V_1 = 0 ; V_1 < V_30 ; V_1 ++ ) {
int V_46 ;
int V_47 ;
V_10 = & V_9 [ V_1 ] ;
V_46 = V_10 -> V_46 ;
V_47 = V_10 -> V_33 ;
F_8 ( V_36 L_15 ,
V_10 -> V_33 , V_10 -> V_34 , V_10 -> V_5 , V_10 -> V_6 ) ;
for ( V_2 = 0 ; V_2 < V_46 ; V_2 ++ ) {
V_13 = & V_10 -> V_13 [ V_2 ] ;
F_8 ( V_36 L_16 ,
V_47 , V_2 , V_13 ) ;
}
}
return 0 ;
}
static void T_5 F_14 ( void * V_48 )
{
T_3 V_11 ;
F_12 ( V_49 , V_11 ) ;
if ( ! ( V_11 & V_50 ) ) {
V_11 |= V_50 ;
F_15 ( V_49 , V_11 ) ;
}
}
static int T_5 F_16 ( struct V_51 * V_52 ,
unsigned long V_53 , void * V_54 )
{
int V_55 = ( long ) V_54 ;
switch ( V_53 ) {
case V_56 :
case V_57 :
F_17 ( V_55 , F_14 , NULL , 0 ) ;
break;
default:
break;
}
return V_58 ;
}
static void T_1 F_18 ( void )
{
#ifdef F_19
unsigned int V_1 , V_59 ;
for ( V_59 = V_1 = 0 ; ! V_59 && V_60 [ V_1 ] . V_61 ; ++ V_1 ) {
T_6 V_3 = V_60 [ V_1 ] . V_3 ;
T_6 V_4 = V_60 [ V_1 ] . V_62 ;
T_6 V_63 = V_60 [ V_1 ] . V_61 ;
for (; V_4 < V_63 ; ++ V_4 ) {
T_2 V_18 = F_4 ( V_3 , V_4 , 3 , 0 ) ;
if ( ! F_20 ( V_18 ) )
continue;
V_18 = F_4 ( V_3 , V_4 , 3 , 0x8c ) ;
if ( ! ( V_18 & ( V_50 >> 32 ) ) ) {
V_18 |= V_50 >> 32 ;
F_21 ( V_3 , V_4 , 3 , 0x8c , V_18 ) ;
}
++ V_59 ;
}
}
#endif
}
static int T_1 F_22 ( void )
{
int V_55 ;
if ( V_64 . V_65 < 0x10 )
return 0 ;
if ( F_2 () )
F_18 () ;
F_23 ( & V_66 ) ;
F_24 (cpu)
F_16 ( & V_66 , ( unsigned long ) V_56 ,
( void * ) ( long ) V_55 ) ;
V_67 |= V_68 ;
return 0 ;
}
static int T_1 F_25 ( void )
{
if ( V_64 . V_69 != V_70 )
return 0 ;
F_1 () ;
F_22 () ;
return 0 ;
}
