static struct V_1 T_1 * F_1 ( int V_2 , int V_3 )
{
struct V_1 * V_4 ;
F_2 (info, &pci_root_infos, list)
if ( V_4 -> V_2 == V_2 && V_4 -> V_3 == V_3 )
return V_4 ;
return NULL ;
}
static int T_1 F_3 ( void )
{
int V_5 ;
unsigned V_6 ;
unsigned V_7 ;
int V_2 ;
int V_3 ;
int V_8 ;
int V_9 ;
struct V_1 * V_4 ;
T_2 V_10 ;
T_3 V_11 ;
T_3 V_12 ;
struct V_13 V_13 [ V_14 ] ;
T_3 V_15 ;
T_2 V_16 ;
bool V_17 ;
struct V_18 V_19 , * V_20 ;
T_3 V_21 ;
T_3 V_22 ;
if ( ! F_4 () )
return - 1 ;
V_17 = false ;
for ( V_5 = 0 ; V_5 < F_5 ( V_23 ) ; V_5 ++ ) {
T_2 V_24 ;
T_4 V_25 ;
T_4 V_26 ;
V_6 = V_23 [ V_5 ] . V_6 ;
V_7 = V_23 [ V_5 ] . V_7 ;
V_24 = F_6 ( V_6 , V_7 , 0 , V_27 ) ;
V_26 = V_24 & 0xffff ;
V_25 = ( V_24 >> 16 ) & 0xffff ;
if ( V_26 != V_28 )
continue;
if ( V_23 [ V_5 ] . V_25 == V_25 ) {
V_17 = true ;
break;
}
}
if ( ! V_17 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
int V_30 ;
int V_31 ;
V_10 = F_6 ( V_6 , V_7 , 1 ,
V_32 + ( V_5 << 2 ) ) ;
if ( ( V_10 & 7 ) != 3 )
continue;
V_30 = ( V_10 >> 16 ) & 0xff ;
V_31 = ( V_10 >> 24 ) & 0xff ;
V_2 = ( V_10 >> 4 ) & 0x07 ;
V_3 = ( V_10 >> 8 ) & 0x03 ;
V_4 = F_7 ( V_30 , V_31 , V_2 , V_3 ) ;
}
if ( V_33 . V_34 > 0x11 )
return 0 ;
V_10 = F_6 ( V_6 , V_7 , 0 , V_35 ) ;
V_8 = ( V_10 >> 8 ) & 0x07 ;
V_10 = F_6 ( V_6 , V_7 , 0 , V_36 ) ;
V_9 = ( V_10 >> 8 ) & 0x03 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
F_8 ( V_13 , V_14 , 0 , 0 , 0xffff + 1 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_10 = F_6 ( V_6 , V_7 , 1 , 0xc0 + ( V_5 << 3 ) ) ;
if ( ! ( V_10 & 3 ) )
continue;
V_11 = V_10 & 0xfff000 ;
V_10 = F_6 ( V_6 , V_7 , 1 , 0xc4 + ( V_5 << 3 ) ) ;
V_2 = V_10 & 0x07 ;
V_3 = ( V_10 >> 4 ) & 0x03 ;
V_12 = ( V_10 & 0xfff000 ) | 0xfff ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ! V_4 )
continue;
F_9 ( V_37 L_1 ,
V_2 , V_3 , V_11 , V_12 ) ;
if ( V_12 > 0xffff )
V_12 = 0xffff ;
F_10 ( V_4 , V_11 , V_12 , V_38 , 1 ) ;
F_11 ( V_13 , V_14 , V_11 , V_12 + 1 ) ;
}
V_4 = F_1 ( V_8 , V_9 ) ;
if ( V_4 ) {
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
if ( ! V_13 [ V_5 ] . V_12 )
continue;
F_10 ( V_4 , V_13 [ V_5 ] . V_11 , V_13 [ V_5 ] . V_12 - 1 ,
V_38 , 1 ) ;
}
}
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_12 = F_12 ( ( 0xfdULL << 32 ) - 1 ) ;
V_12 ++ ;
F_8 ( V_13 , V_14 , 0 , 0 , V_12 ) ;
V_16 = V_39 ;
F_13 ( V_16 , V_15 ) ;
V_12 = ( V_15 & 0xffffff800000ULL ) ;
F_9 ( V_40 L_2 , V_12 , V_12 >> 20 ) ;
if ( V_12 < ( 1ULL << 32 ) )
F_11 ( V_13 , V_14 , 0 , V_12 ) ;
V_20 = F_14 ( & V_19 ) ;
if ( V_20 ) {
F_9 ( V_37 L_3 , V_20 ) ;
V_21 = V_20 -> V_11 ;
V_22 = V_20 -> V_12 ;
F_11 ( V_13 , V_14 , V_21 ,
V_22 + 1 ) ;
} else {
V_21 = 0 ;
V_22 = 0 ;
}
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_10 = F_6 ( V_6 , V_7 , 1 , 0x80 + ( V_5 << 3 ) ) ;
if ( ! ( V_10 & 3 ) )
continue;
V_11 = V_10 & 0xffffff00 ;
V_11 <<= 8 ;
V_10 = F_6 ( V_6 , V_7 , 1 , 0x84 + ( V_5 << 3 ) ) ;
V_2 = V_10 & 0x07 ;
V_3 = ( V_10 >> 4 ) & 0x03 ;
V_12 = ( V_10 & 0xffffff00 ) ;
V_12 <<= 8 ;
V_12 |= 0xffff ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ! V_4 )
continue;
F_9 ( V_37 L_4 ,
V_2 , V_3 , V_11 , V_12 ) ;
if ( V_22 ) {
int V_41 = 0 ;
T_3 V_42 = 0 ;
if ( V_11 >= V_21 &&
V_11 <= V_22 ) {
V_11 = V_22 + 1 ;
V_41 = 1 ;
}
if ( V_12 >= V_21 &&
V_12 <= V_22 ) {
V_12 = V_21 - 1 ;
V_41 = 1 ;
}
if ( V_11 < V_21 &&
V_12 > V_22 ) {
V_42 = V_21 - 1 ;
F_10 ( V_4 , V_11 , V_42 , V_43 , 0 ) ;
F_11 ( V_13 , V_14 , V_11 ,
V_42 + 1 ) ;
F_9 ( V_44 L_5 , V_11 , V_42 ) ;
V_11 = V_22 + 1 ;
V_41 = 1 ;
}
if ( V_41 ) {
if ( V_11 <= V_12 ) {
F_9 ( V_44 L_6 , V_42 ? L_7 : L_8 , V_11 , V_12 ) ;
} else {
F_9 ( V_44 L_9 , V_42 ? L_10 : L_11 ) ;
continue;
}
}
}
F_10 ( V_4 , F_12 ( V_11 ) , F_12 ( V_12 ) ,
V_43 , 1 ) ;
F_11 ( V_13 , V_14 , V_11 , V_12 + 1 ) ;
F_9 ( V_44 L_12 ) ;
}
V_16 = V_45 ;
F_13 ( V_16 , V_15 ) ;
if ( V_15 & ( 1 << 21 ) ) {
V_16 = V_46 ;
F_13 ( V_16 , V_15 ) ;
V_12 = ( V_15 & 0xffffff800000ULL ) ;
F_9 ( V_40 L_13 , V_12 , V_12 >> 20 ) ;
F_11 ( V_13 , V_14 , 1ULL << 32 , V_12 ) ;
}
V_4 = F_1 ( V_8 , V_9 ) ;
if ( V_4 ) {
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
if ( ! V_13 [ V_5 ] . V_12 )
continue;
F_10 ( V_4 , F_12 ( V_13 [ V_5 ] . V_11 ) ,
F_12 ( V_13 [ V_5 ] . V_12 - 1 ) ,
V_43 , 1 ) ;
}
}
F_2 (info, &pci_root_infos, list) {
int V_47 ;
struct V_48 * V_49 ;
V_47 = V_4 -> V_50 . V_11 ;
F_9 ( V_37 L_14 ,
& V_4 -> V_50 , V_4 -> V_2 , V_4 -> V_3 ) ;
F_2 (root_res, &info->resources, list)
F_9 ( V_37 L_15 ,
V_47 , & V_49 -> V_51 ) ;
}
return 0 ;
}
static void F_15 ( void * V_52 )
{
T_3 V_10 ;
F_13 ( V_53 , V_10 ) ;
if ( ! ( V_10 & V_54 ) ) {
V_10 |= V_54 ;
F_16 ( V_53 , V_10 ) ;
}
}
static int F_17 ( struct V_55 * V_56 , unsigned long V_57 ,
void * V_58 )
{
int V_59 = ( long ) V_58 ;
switch ( V_57 ) {
case V_60 :
case V_61 :
F_18 ( V_59 , F_15 , NULL , 0 ) ;
break;
default:
break;
}
return V_62 ;
}
static void T_1 F_19 ( void )
{
#ifdef F_20
unsigned int V_5 , V_63 ;
for ( V_63 = V_5 = 0 ; ! V_63 && V_64 [ V_5 ] . V_65 ; ++ V_5 ) {
T_5 V_6 = V_64 [ V_5 ] . V_6 ;
T_5 V_7 = V_64 [ V_5 ] . V_66 ;
T_5 V_67 = V_64 [ V_5 ] . V_65 ;
for (; V_7 < V_67 ; ++ V_7 ) {
T_2 V_15 = F_6 ( V_6 , V_7 , 3 , 0 ) ;
if ( ! F_21 ( V_15 ) )
continue;
V_15 = F_6 ( V_6 , V_7 , 3 , 0x8c ) ;
if ( ! ( V_15 & ( V_54 >> 32 ) ) ) {
V_15 |= V_54 >> 32 ;
F_22 ( V_6 , V_7 , 3 , 0x8c , V_15 ) ;
}
++ V_63 ;
}
}
#endif
}
static int T_1 F_23 ( void )
{
int V_59 ;
if ( V_33 . V_34 < 0x10 )
return 0 ;
if ( F_4 () )
F_19 () ;
F_24 () ;
F_25 (cpu)
F_17 ( & V_68 , ( unsigned long ) V_60 ,
( void * ) ( long ) V_59 ) ;
F_26 ( & V_68 ) ;
F_27 () ;
V_69 |= V_70 ;
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( V_33 . V_71 != V_72 )
return 0 ;
F_3 () ;
F_23 () ;
return 0 ;
}
