static struct V_1 T_1 * F_1 ( int V_2 , int V_3 )
{
struct V_1 * V_4 ;
F_2 (info, &pci_root_infos, list)
if ( V_4 -> V_2 == V_2 && V_4 -> V_3 == V_3 )
return V_4 ;
return NULL ;
}
static void T_1 F_3 ( int V_5 , int V_6 , int V_2 )
{
#ifdef F_4
int V_7 ;
for ( V_7 = V_5 ; V_7 <= V_6 ; V_7 ++ )
F_5 ( V_7 , V_2 ) ;
#endif
}
static int T_1 F_6 ( void )
{
int V_8 ;
unsigned V_9 ;
unsigned V_10 ;
int V_2 ;
int V_3 ;
int V_11 ;
int V_12 ;
struct V_1 * V_4 ;
T_2 V_13 ;
T_3 V_14 ;
T_3 V_15 ;
struct V_16 V_16 [ V_17 ] ;
T_3 V_18 ;
T_2 V_19 ;
bool V_20 ;
struct V_21 V_22 , * V_23 ;
T_3 V_24 ;
T_3 V_25 ;
if ( ! F_7 () )
return - 1 ;
V_20 = false ;
for ( V_8 = 0 ; V_8 < F_8 ( V_26 ) ; V_8 ++ ) {
T_2 V_27 ;
T_4 V_28 ;
T_4 V_29 ;
V_9 = V_26 [ V_8 ] . V_9 ;
V_10 = V_26 [ V_8 ] . V_10 ;
V_27 = F_9 ( V_9 , V_10 , 0 , V_30 ) ;
V_29 = V_27 & 0xffff ;
V_28 = ( V_27 >> 16 ) & 0xffff ;
if ( V_26 [ V_8 ] . V_29 == V_29 &&
V_26 [ V_8 ] . V_28 == V_28 ) {
V_20 = true ;
break;
}
}
if ( ! V_20 )
return 0 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
int V_5 ;
int V_6 ;
V_13 = F_9 ( V_9 , V_10 , 1 , 0xe0 + ( V_8 << 2 ) ) ;
if ( ( V_13 & 7 ) != 3 )
continue;
V_5 = ( V_13 >> 16 ) & 0xff ;
V_6 = ( V_13 >> 24 ) & 0xff ;
V_2 = ( V_13 >> 4 ) & 0x07 ;
F_3 ( V_5 , V_6 , V_2 ) ;
V_3 = ( V_13 >> 8 ) & 0x03 ;
V_4 = F_10 ( V_5 , V_6 , V_2 , V_3 ) ;
}
V_13 = F_9 ( V_9 , V_10 , 0 , 0x60 ) ;
V_11 = ( V_13 >> 8 ) & 0x07 ;
V_13 = F_9 ( V_9 , V_10 , 0 , 0x64 ) ;
V_12 = ( V_13 >> 8 ) & 0x03 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
F_11 ( V_16 , V_17 , 0 , 0 , 0xffff + 1 ) ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_13 = F_9 ( V_9 , V_10 , 1 , 0xc0 + ( V_8 << 3 ) ) ;
if ( ! ( V_13 & 3 ) )
continue;
V_14 = V_13 & 0xfff000 ;
V_13 = F_9 ( V_9 , V_10 , 1 , 0xc4 + ( V_8 << 3 ) ) ;
V_2 = V_13 & 0x07 ;
V_3 = ( V_13 >> 4 ) & 0x03 ;
V_15 = ( V_13 & 0xfff000 ) | 0xfff ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ! V_4 )
continue;
F_12 ( V_31 L_1 ,
V_2 , V_3 , V_14 , V_15 ) ;
if ( V_15 > 0xffff )
V_15 = 0xffff ;
F_13 ( V_4 , V_14 , V_15 , V_32 , 1 ) ;
F_14 ( V_16 , V_17 , V_14 , V_15 + 1 ) ;
}
V_4 = F_1 ( V_11 , V_12 ) ;
if ( V_4 ) {
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ ) {
if ( ! V_16 [ V_8 ] . V_15 )
continue;
F_13 ( V_4 , V_16 [ V_8 ] . V_14 , V_16 [ V_8 ] . V_15 - 1 ,
V_32 , 1 ) ;
}
}
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_15 = F_15 ( ( 0xfdULL << 32 ) - 1 ) ;
V_15 ++ ;
F_11 ( V_16 , V_17 , 0 , 0 , V_15 ) ;
V_19 = V_33 ;
F_16 ( V_19 , V_18 ) ;
V_15 = ( V_18 & 0xffffff800000ULL ) ;
F_12 ( V_34 L_2 , V_15 , V_15 >> 20 ) ;
if ( V_15 < ( 1ULL << 32 ) )
F_14 ( V_16 , V_17 , 0 , V_15 ) ;
V_23 = F_17 ( & V_22 ) ;
if ( V_23 ) {
F_12 ( V_31 L_3 , V_23 ) ;
V_24 = V_23 -> V_14 ;
V_25 = V_23 -> V_15 ;
F_14 ( V_16 , V_17 , V_24 ,
V_25 + 1 ) ;
} else {
V_24 = 0 ;
V_25 = 0 ;
}
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_13 = F_9 ( V_9 , V_10 , 1 , 0x80 + ( V_8 << 3 ) ) ;
if ( ! ( V_13 & 3 ) )
continue;
V_14 = V_13 & 0xffffff00 ;
V_14 <<= 8 ;
V_13 = F_9 ( V_9 , V_10 , 1 , 0x84 + ( V_8 << 3 ) ) ;
V_2 = V_13 & 0x07 ;
V_3 = ( V_13 >> 4 ) & 0x03 ;
V_15 = ( V_13 & 0xffffff00 ) ;
V_15 <<= 8 ;
V_15 |= 0xffff ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ! V_4 )
continue;
F_12 ( V_31 L_4 ,
V_2 , V_3 , V_14 , V_15 ) ;
if ( V_25 ) {
int V_35 = 0 ;
T_3 V_36 = 0 ;
if ( V_14 >= V_24 &&
V_14 <= V_25 ) {
V_14 = V_25 + 1 ;
V_35 = 1 ;
}
if ( V_15 >= V_24 &&
V_15 <= V_25 ) {
V_15 = V_24 - 1 ;
V_35 = 1 ;
}
if ( V_14 < V_24 &&
V_15 > V_25 ) {
V_36 = V_24 - 1 ;
F_13 ( V_4 , V_14 , V_36 , V_37 , 0 ) ;
F_14 ( V_16 , V_17 , V_14 ,
V_36 + 1 ) ;
F_12 ( V_38 L_5 , V_14 , V_36 ) ;
V_14 = V_25 + 1 ;
V_35 = 1 ;
}
if ( V_35 ) {
if ( V_14 <= V_15 ) {
F_12 ( V_38 L_6 , V_36 ? L_7 : L_8 , V_14 , V_15 ) ;
} else {
F_12 ( V_38 L_9 , V_36 ? L_10 : L_11 ) ;
continue;
}
}
}
F_13 ( V_4 , F_15 ( V_14 ) , F_15 ( V_15 ) ,
V_37 , 1 ) ;
F_14 ( V_16 , V_17 , V_14 , V_15 + 1 ) ;
F_12 ( V_38 L_12 ) ;
}
V_19 = V_39 ;
F_16 ( V_19 , V_18 ) ;
if ( V_18 & ( 1 << 21 ) ) {
V_19 = V_40 ;
F_16 ( V_19 , V_18 ) ;
V_15 = ( V_18 & 0xffffff800000ULL ) ;
F_12 ( V_34 L_13 , V_15 , V_15 >> 20 ) ;
F_14 ( V_16 , V_17 , 1ULL << 32 , V_15 ) ;
}
V_4 = F_1 ( V_11 , V_12 ) ;
if ( V_4 ) {
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ ) {
if ( ! V_16 [ V_8 ] . V_15 )
continue;
F_13 ( V_4 , F_15 ( V_16 [ V_8 ] . V_14 ) ,
F_15 ( V_16 [ V_8 ] . V_15 - 1 ) ,
V_37 , 1 ) ;
}
}
F_2 (info, &pci_root_infos, list) {
int V_41 ;
struct V_42 * V_43 ;
V_41 = V_4 -> V_44 . V_14 ;
F_12 ( V_31 L_14 ,
& V_4 -> V_44 , V_4 -> V_2 , V_4 -> V_3 ) ;
F_2 (root_res, &info->resources, list)
F_12 ( V_31 L_15 ,
V_41 , & V_43 -> V_45 ) ;
}
return 0 ;
}
static void T_5 F_18 ( void * V_46 )
{
T_3 V_13 ;
F_16 ( V_47 , V_13 ) ;
if ( ! ( V_13 & V_48 ) ) {
V_13 |= V_48 ;
F_19 ( V_47 , V_13 ) ;
}
}
static int T_5 F_20 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_52 )
{
int V_53 = ( long ) V_52 ;
switch ( V_51 ) {
case V_54 :
case V_55 :
F_21 ( V_53 , F_18 , NULL , 0 ) ;
break;
default:
break;
}
return V_56 ;
}
static void T_1 F_22 ( void )
{
#ifdef F_23
unsigned int V_8 , V_57 ;
for ( V_57 = V_8 = 0 ; ! V_57 && V_58 [ V_8 ] . V_59 ; ++ V_8 ) {
T_6 V_9 = V_58 [ V_8 ] . V_9 ;
T_6 V_10 = V_58 [ V_8 ] . V_60 ;
T_6 V_61 = V_58 [ V_8 ] . V_59 ;
for (; V_10 < V_61 ; ++ V_10 ) {
T_2 V_18 = F_9 ( V_9 , V_10 , 3 , 0 ) ;
if ( ! F_24 ( V_18 ) )
continue;
V_18 = F_9 ( V_9 , V_10 , 3 , 0x8c ) ;
if ( ! ( V_18 & ( V_48 >> 32 ) ) ) {
V_18 |= V_48 >> 32 ;
F_25 ( V_9 , V_10 , 3 , 0x8c , V_18 ) ;
}
++ V_57 ;
}
}
#endif
}
static int T_1 F_26 ( void )
{
int V_53 ;
if ( V_62 . V_63 < 0x10 )
return 0 ;
if ( F_7 () )
F_22 () ;
F_27 ( & V_64 ) ;
F_28 (cpu)
F_20 ( & V_64 , ( unsigned long ) V_54 ,
( void * ) ( long ) V_53 ) ;
V_65 |= V_66 ;
return 0 ;
}
static int T_1 F_29 ( void )
{
if ( V_62 . V_67 != V_68 )
return 0 ;
F_6 () ;
F_26 () ;
return 0 ;
}
