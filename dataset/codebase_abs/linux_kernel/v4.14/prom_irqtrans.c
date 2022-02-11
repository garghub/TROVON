static unsigned long F_1 ( unsigned long V_1 )
{
unsigned int V_2 = ( V_1 & 0x10 ) >> 4 ;
unsigned int V_3 = ( V_1 & 0x0c ) >> 2 ;
if ( V_2 == 0 )
return V_4 + ( V_3 * 8 ) ;
else
return V_5 + ( V_3 * 8 ) ;
}
static unsigned int F_2 ( struct V_6 * V_7 ,
unsigned int V_1 ,
void * V_8 )
{
unsigned long V_9 = ( unsigned long ) V_8 ;
unsigned long V_10 , V_11 ;
unsigned long V_12 , V_13 ;
int V_14 = 0 ;
V_1 &= 0x3f ;
if ( V_1 < V_15 ) {
V_12 = F_1 ( V_1 ) ;
} else {
V_12 = F_3 ( V_1 ) ;
}
V_10 = V_9 + V_12 ;
V_13 = F_4 ( V_1 ) ;
V_11 = V_9 + V_13 ;
if ( ( V_1 & 0x20 ) == 0 )
V_14 = V_1 & 0x03 ;
return F_5 ( V_14 , V_11 , V_10 ) ;
}
static void T_1 F_6 ( struct V_6 * V_7 )
{
const struct V_16 * V_17 ;
V_7 -> V_18 = F_7 ( sizeof( struct V_19 ) ) ;
V_7 -> V_18 -> V_20 = F_2 ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
V_7 -> V_18 -> V_21 = ( void * ) V_17 [ 2 ] . V_22 ;
}
static void F_9 ( unsigned int V_1 , void * V_23 , void * V_24 )
{
unsigned int V_25 = ( unsigned int ) ( unsigned long ) V_23 ;
struct V_26 * V_27 = V_24 ;
unsigned long V_9 = V_27 -> V_9 ;
unsigned long V_28 = V_9 + V_29 ;
unsigned long V_30 = V_9 + V_31 ;
unsigned int V_2 , V_32 ;
T_2 V_33 ;
V_30 = F_10 ( V_30 ) ;
V_2 = ( V_25 >> 16 ) & 0xff ;
V_32 = ( V_25 >> 8 ) & 0xff ;
V_30 |= F_11 ( V_2 , V_32 , 0x00 ) ;
__asm__ __volatile__("membar #Sync\n\t"
"lduha [%1] %2, %0\n\t"
"membar #Sync"
: "=r" (_unused)
: "r" ((u16 *) config_space),
"i" (ASI_PHYS_BYPASS_EC_E_L)
: "memory");
F_12 ( V_28 ) ;
}
static unsigned long F_13 ( unsigned long V_1 )
{
unsigned int V_2 = ( V_1 & 0x10 ) >> 4 ;
unsigned int V_3 = ( V_1 & 0x0c ) >> 2 ;
if ( V_2 == 0 )
return V_34 + ( V_3 * 8 ) ;
else
return V_35 + ( V_3 * 8 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_6 * V_36 = V_7 -> V_36 ;
const char * V_37 , * V_38 ;
while ( V_36 ) {
if ( ! strcmp ( V_36 -> type , L_2 ) )
break;
V_36 = V_36 -> V_36 ;
}
if ( ! V_36 )
return 0 ;
V_37 = F_8 ( V_36 ,
L_3 , NULL ) ;
if ( V_37 &&
( ! strcmp ( V_37 , L_4 ) ||
! strcmp ( V_37 , L_5 ) ) )
return 0 ;
V_38 = F_8 ( V_36 ,
L_6 , NULL ) ;
if ( V_38 &&
( ! strcmp ( V_38 , L_7 ) ||
! strcmp ( V_38 , L_8 ) ) )
return 0 ;
return 1 ;
}
static unsigned int F_15 ( struct V_6 * V_7 ,
unsigned int V_1 ,
void * V_8 )
{
struct V_26 * V_27 = V_8 ;
unsigned long V_9 = V_27 -> V_9 ;
const struct V_39 * V_17 ;
unsigned long V_10 , V_11 ;
unsigned long V_12 , V_13 ;
int V_14 = 0 ;
int V_40 ;
V_1 &= 0x3f ;
if ( V_1 < V_41 ) {
V_12 = F_13 ( V_1 ) ;
} else {
V_12 = F_16 ( V_1 ) ;
}
V_10 = V_9 + V_12 ;
V_13 = F_17 ( V_1 ) ;
V_11 = V_9 + V_13 ;
if ( ( V_1 & 0x20 ) == 0 )
V_14 = V_1 & 0x03 ;
V_40 = F_5 ( V_14 , V_11 , V_10 ) ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
if ( V_17 && F_14 ( V_7 ) ) {
F_18 ( V_40 ,
F_9 ,
( void * ) ( long ) V_17 -> V_25 ,
( void * ) V_27 ) ;
}
return V_40 ;
}
static void T_1 F_19 ( struct V_6 * V_7 )
{
const struct V_16 * V_17 ;
struct V_26 * V_27 ;
const T_3 * V_42 ;
V_7 -> V_18 = F_7 ( sizeof( struct V_19 ) ) ;
V_7 -> V_18 -> V_20 = F_15 ;
V_27 = F_7 ( sizeof( struct V_26 ) ) ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
V_27 -> V_9 = V_17 [ 0 ] . V_22 ;
V_42 = F_8 ( V_7 , L_9 , NULL ) ;
V_27 -> V_43 = V_42 [ 0 ] ;
V_7 -> V_18 -> V_21 = V_27 ;
}
static unsigned long F_20 ( unsigned long V_1 )
{
return V_44 + ( V_1 * 8UL ) ;
}
static unsigned long F_21 ( unsigned long V_1 )
{
return V_45 + ( V_1 * 8UL ) ;
}
static unsigned long F_22 ( unsigned long V_46 ,
unsigned int V_1 )
{
return V_46 + F_21 ( V_1 ) ;
}
static unsigned long F_23 ( unsigned long V_46 ,
unsigned int V_1 )
{
return V_46 + F_20 ( V_1 ) ;
}
static void F_24 ( unsigned int V_1 , void * V_23 , void * V_24 )
{
unsigned long V_28 = ( unsigned long ) V_24 ;
T_4 V_47 = 1UL << ( V_1 & V_48 ) ;
T_4 V_49 ;
int V_50 ;
F_25 ( V_28 , V_47 ) ;
V_50 = 100000 ;
V_49 = 0 ;
while ( -- V_50 ) {
V_49 = F_26 ( V_28 ) ;
if ( ! ( V_49 & V_47 ) )
break;
}
if ( V_50 <= 0 ) {
F_27 ( L_10 ,
V_49 , V_47 ) ;
}
if ( V_23 ) {
static unsigned char V_51 [ 64 ]
V_52 ( ( F_28 ( 64 ) ) ) ;
__asm__ __volatile__("rd %%fprs, %0\n\t"
"or %0, %4, %1\n\t"
"wr %1, 0x0, %%fprs\n\t"
"stda %%f0, [%5] %6\n\t"
"wr %0, 0x0, %%fprs\n\t"
"membar #Sync"
: "=&r" (mask), "=&r" (val)
: "0" (mask), "1" (val),
"i" (FPRS_FEF), "r" (&cacheline[0]),
"i" (ASI_BLK_COMMIT_P));
}
}
static unsigned int F_29 ( struct V_6 * V_7 ,
unsigned int V_1 ,
void * V_8 )
{
struct V_53 * V_27 = V_8 ;
unsigned long V_46 = V_27 -> V_46 ;
unsigned long V_10 , V_11 ;
int V_54 ;
int V_40 ;
int V_55 ;
V_1 &= 0x3f ;
V_10 = F_23 ( V_46 , V_1 ) ;
V_11 = F_22 ( V_46 , V_1 ) ;
V_54 = 0 ;
V_55 = ( V_27 -> V_28 != 0UL ) ;
if ( V_55 ) {
if ( V_27 -> V_56 & 1 )
V_54 = ( 1 << 6 ) ;
}
V_40 = F_5 ( V_54 , V_11 , V_10 ) ;
if ( V_55 ) {
F_18 ( V_40 ,
F_24 ,
( ( V_27 -> V_57 <= 4 ) ?
( void * ) 1 : ( void * ) 0 ) ,
( void * ) V_27 -> V_28 ) ;
}
return V_40 ;
}
static void T_1 F_30 ( struct V_6 * V_7 ,
int V_55 )
{
const struct V_16 * V_17 ;
struct V_53 * V_27 ;
V_7 -> V_18 = F_7 ( sizeof( struct V_19 ) ) ;
V_7 -> V_18 -> V_20 = F_29 ;
V_27 = F_7 ( sizeof( struct V_53 ) ) ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
V_7 -> V_18 -> V_21 = V_27 ;
V_27 -> V_46 = V_17 [ 0 ] . V_22 ;
if ( V_55 )
V_27 -> V_28 = V_17 [ 3 ] . V_22 + 0x1a18UL ;
else
V_27 -> V_28 = 0UL ;
V_27 -> V_56 = F_31 ( V_7 , L_11 , 0 ) ;
V_27 -> V_57 = F_31 ( V_7 , L_12 , 0 ) ;
}
static void T_1 F_32 ( struct V_6 * V_7 )
{
F_30 ( V_7 , 0 ) ;
}
static void T_1 F_33 ( struct V_6 * V_7 )
{
F_30 ( V_7 , 1 ) ;
}
static unsigned int F_34 ( struct V_6 * V_7 ,
unsigned int V_58 ,
void * V_8 )
{
T_3 V_59 = ( T_3 ) ( unsigned long ) V_8 ;
return F_35 ( V_59 , V_58 ) ;
}
static void T_1 F_36 ( struct V_6 * V_7 )
{
const struct V_16 * V_17 ;
V_7 -> V_18 = F_7 ( sizeof( struct V_19 ) ) ;
V_7 -> V_18 -> V_20 = F_34 ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
V_7 -> V_18 -> V_21 = ( void * ) ( unsigned long )
( ( V_17 -> V_22 >> 32UL ) & 0x0fffffff ) ;
}
static unsigned long F_37 ( unsigned long V_1 )
{
return V_60 + ( V_1 * 8UL ) ;
}
static unsigned long F_38 ( unsigned long V_1 )
{
return V_61 + ( V_1 * 8UL ) ;
}
static unsigned long F_39 ( unsigned long V_46 ,
unsigned int V_1 )
{
return V_46 + F_38 ( V_1 ) ;
}
static unsigned long F_40 ( unsigned long V_46 ,
unsigned int V_1 )
{
return V_46 + F_37 ( V_1 ) ;
}
static unsigned int F_41 ( struct V_6 * V_7 ,
unsigned int V_1 ,
void * V_8 )
{
struct V_62 * V_27 = V_8 ;
unsigned long V_46 = V_27 -> V_46 ;
unsigned long V_10 , V_11 ;
unsigned long V_63 ;
V_1 &= 0x3f ;
V_10 = F_40 ( V_46 , V_1 ) ;
V_11 = F_39 ( V_46 , V_1 ) ;
V_63 = 1 << 6 ;
F_42 ( V_63 , V_10 ) ;
V_1 |= ( V_27 -> V_56 << 6 ) ;
V_1 -= V_63 ;
return F_5 ( V_1 , V_11 , V_10 ) ;
}
static void T_1 F_43 ( struct V_6 * V_7 )
{
const struct V_16 * V_17 ;
struct V_62 * V_27 ;
V_7 -> V_18 = F_7 ( sizeof( struct V_19 ) ) ;
V_7 -> V_18 -> V_20 = F_41 ;
V_27 = F_7 ( sizeof( struct V_62 ) ) ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
V_7 -> V_18 -> V_21 = V_27 ;
V_27 -> V_46 = V_17 [ 0 ] . V_22 ;
V_27 -> V_56 = F_31 ( V_7 , L_11 , 0 ) ;
}
static unsigned long F_44 ( unsigned long V_10 )
{
unsigned long V_64 = V_65 - V_66 ;
return V_10 + V_64 ;
}
static unsigned int F_45 ( struct V_6 * V_7 ,
unsigned int V_1 ,
void * V_8 )
{
unsigned long V_67 = ( unsigned long ) V_8 ;
const struct V_68 * V_17 ;
unsigned long V_10 , V_11 ;
int V_69 = 0 ;
int V_70 = 0 ;
V_1 &= 0x3f ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
if ( V_17 )
V_69 = V_17 -> V_71 ;
if ( V_1 < 0x20 )
V_1 += ( V_69 * 8 ) ;
V_10 = V_72 [ V_1 ] ;
if ( V_10 == ( ( unsigned long ) - 1 ) ) {
F_46 ( L_13 ,
V_1 ) ;
F_47 () ;
}
V_10 += V_67 ;
if ( V_1 >= 0x20 ) {
V_11 = F_44 ( V_10 ) ;
} else {
V_70 = V_1 & 0x7 ;
switch( V_69 ) {
case 0 :
V_11 = V_67 + V_73 ;
break;
case 1 :
V_11 = V_67 + V_74 ;
break;
case 2 :
V_11 = V_67 + V_75 ;
break;
default:
case 3 :
V_11 = V_67 + V_76 ;
break;
}
V_11 += ( ( unsigned long ) V_70 - 1UL ) * 8UL ;
}
return F_5 ( V_70 , V_11 , V_10 ) ;
}
static void T_1 F_48 ( struct V_6 * V_7 )
{
const struct V_16 * V_17 ;
V_7 -> V_18 = F_7 ( sizeof( struct V_19 ) ) ;
V_7 -> V_18 -> V_20 = F_45 ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
V_7 -> V_18 -> V_21 = ( void * ) ( unsigned long ) V_17 -> V_22 ;
}
static unsigned int F_49 ( struct V_6 * V_7 ,
unsigned int V_1 ,
void * V_8 )
{
struct V_6 * V_77 = V_8 ;
struct V_78 * V_79 = F_50 ( V_77 ) ;
struct V_80 * V_81 ;
unsigned long V_10 , V_11 ;
T_3 V_82 ;
if ( ! strcmp ( V_7 -> V_83 , L_14 ) ) {
V_81 = & V_79 -> V_80 [ 5 ] ;
} else if ( ! strcmp ( V_7 -> V_83 , L_15 ) ) {
V_81 = & V_79 -> V_80 [ 4 ] ;
} else if ( ! strcmp ( V_7 -> V_83 , L_16 ) ) {
V_81 = & V_79 -> V_80 [ 3 ] ;
} else {
return V_1 ;
}
V_10 = V_81 -> V_84 + 0x00UL ;
V_11 = V_81 -> V_84 + 0x10UL ;
F_51 ( 0 , V_11 ) ;
F_52 ( V_11 ) ;
V_82 = F_52 ( V_10 ) ;
V_82 &= ~ 0x80000000 ;
F_51 ( V_82 , V_10 ) ;
return F_5 ( 0 , V_11 , V_10 ) ;
}
static void T_1 F_53 ( struct V_6 * V_7 )
{
V_7 -> V_18 = F_7 ( sizeof( struct V_19 ) ) ;
V_7 -> V_18 -> V_20 = F_49 ;
V_7 -> V_18 -> V_21 = V_7 ;
}
static unsigned int F_54 ( struct V_6 * V_7 ,
unsigned int V_58 ,
void * V_8 )
{
T_3 V_59 = ( T_3 ) ( unsigned long ) V_8 ;
return F_35 ( V_59 , V_58 ) ;
}
static void T_1 F_55 ( struct V_6 * V_7 )
{
const struct V_16 * V_17 ;
V_7 -> V_18 = F_7 ( sizeof( struct V_19 ) ) ;
V_7 -> V_18 -> V_20 = F_54 ;
V_17 = F_8 ( V_7 , L_1 , NULL ) ;
V_7 -> V_18 -> V_21 = ( void * ) ( unsigned long )
( ( V_17 -> V_22 >> 32UL ) & 0x0fffffff ) ;
}
void T_1 F_56 ( struct V_6 * V_7 )
{
#ifdef F_57
const char * V_85 ;
int V_86 ;
#endif
#ifdef F_57
V_85 = F_8 ( V_7 , L_3 , NULL ) ;
if ( ! V_85 )
V_85 = F_8 ( V_7 , L_6 , NULL ) ;
if ( V_85 ) {
for ( V_86 = 0 ; V_86 < F_58 ( V_87 ) ; V_86 ++ ) {
struct V_18 * V_88 = & V_87 [ V_86 ] ;
if ( ! strcmp ( V_85 , V_88 -> V_83 ) ) {
V_88 -> V_89 ( V_7 ) ;
return;
}
}
}
#endif
#ifdef F_59
if ( ! strcmp ( V_7 -> V_83 , L_17 ) ||
! strcmp ( V_7 -> V_83 , L_18 ) ) {
F_48 ( V_7 ) ;
return;
}
#endif
if ( ! strcmp ( V_7 -> V_83 , L_19 ) &&
! strcmp ( V_7 -> V_36 -> V_83 , L_20 ) ) {
F_53 ( V_7 ) ;
return;
}
if ( ! strcmp ( V_7 -> V_83 , L_21 ) ||
! strcmp ( V_7 -> V_83 , L_22 ) ) {
F_55 ( V_7 ) ;
return;
}
}
