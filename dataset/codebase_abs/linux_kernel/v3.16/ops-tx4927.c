static void T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 T_2 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
if ( V_6 [ V_5 ] . V_2 == V_2 ) {
V_6 [ V_5 ] . V_4 = V_4 ;
return;
}
}
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
if ( ! V_6 [ V_5 ] . V_2 ) {
V_6 [ V_5 ] . V_2 = V_2 ;
V_6 [ V_5 ] . V_4 = V_4 ;
return;
}
}
F_3 () ;
}
struct V_3 T_2 * F_4 (
struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
if ( V_6 [ V_5 ] . V_2 == V_2 )
return V_6 [ V_5 ] . V_4 ;
}
return NULL ;
}
static int F_5 ( struct V_7 * V_8 , unsigned int V_9 , int V_10 ,
struct V_3 T_2 * V_4 )
{
if ( V_8 -> V_11 == NULL &&
V_9 >= F_6 ( V_12 , 0 ) )
return - 1 ;
F_7 ( ( ( V_8 -> V_13 & 0xff ) << 0x10 )
| ( ( V_9 & 0xff ) << 0x08 ) | ( V_10 & 0xfc )
| ( V_8 -> V_11 ? 1 : 0 ) ,
& V_4 -> V_14 ) ;
F_7 ( ( F_8 ( & V_4 -> V_15 ) & 0x0000ffff )
| ( V_16 << 16 ) ,
& V_4 -> V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_3 T_2 * V_4 )
{
int V_17 = V_18 ;
while ( F_8 ( & V_4 -> V_19 ) & V_20 )
;
if ( F_8 ( & V_4 -> V_15 )
& ( V_16 << 16 ) ) {
F_7 ( ( F_8 ( & V_4 -> V_15 ) & 0x0000ffff )
| ( V_16 << 16 ) ,
& V_4 -> V_15 ) ;
F_10 () ;
V_17 = V_21 ;
}
return V_17 ;
}
static T_3 F_11 ( int V_22 , struct V_3 T_2 * V_4 )
{
#ifdef F_12
V_22 ^= 3 ;
#endif
return F_13 ( ( void T_2 * ) & V_4 -> V_23 + V_22 ) ;
}
static T_4 F_14 ( int V_22 , struct V_3 T_2 * V_4 )
{
#ifdef F_12
V_22 ^= 2 ;
#endif
return F_15 ( ( void T_2 * ) & V_4 -> V_23 + V_22 ) ;
}
static T_5 F_16 ( struct V_3 T_2 * V_4 )
{
return F_8 ( & V_4 -> V_23 ) ;
}
static void F_17 ( T_3 V_24 , int V_22 ,
struct V_3 T_2 * V_4 )
{
#ifdef F_12
V_22 ^= 3 ;
#endif
F_18 ( V_24 , ( void T_2 * ) & V_4 -> V_23 + V_22 ) ;
}
static void F_19 ( T_4 V_24 , int V_22 ,
struct V_3 T_2 * V_4 )
{
#ifdef F_12
V_22 ^= 2 ;
#endif
F_20 ( V_24 , ( void T_2 * ) & V_4 -> V_23 + V_22 ) ;
}
static void F_21 ( T_5 V_24 , struct V_3 T_2 * V_4 )
{
F_7 ( V_24 , & V_4 -> V_23 ) ;
}
static struct V_3 T_2 * F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_25 ;
return F_4 ( V_2 ) ;
}
static int F_23 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_10 , int V_26 , T_5 * V_24 )
{
struct V_3 T_2 * V_4 = F_22 ( V_8 ) ;
if ( F_5 ( V_8 , V_9 , V_10 , V_4 ) ) {
* V_24 = 0xffffffff ;
return - 1 ;
}
switch ( V_26 ) {
case 1 :
* V_24 = F_11 ( V_10 & 3 , V_4 ) ;
break;
case 2 :
* V_24 = F_14 ( V_10 & 3 , V_4 ) ;
break;
default:
* V_24 = F_16 ( V_4 ) ;
}
return F_9 ( V_4 ) ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_10 , int V_26 , T_5 V_24 )
{
struct V_3 T_2 * V_4 = F_22 ( V_8 ) ;
if ( F_5 ( V_8 , V_9 , V_10 , V_4 ) )
return - 1 ;
switch ( V_26 ) {
case 1 :
F_17 ( V_24 , V_10 & 3 , V_4 ) ;
break;
case 2 :
F_19 ( V_24 , V_10 & 3 , V_4 ) ;
break;
default:
F_21 ( V_24 , V_4 ) ;
}
return F_9 ( V_4 ) ;
}
char * F_25 ( char * V_27 )
{
unsigned long V_24 ;
if ( ! strncmp ( V_27 , L_1 , 7 ) ) {
T_3 V_24 = 0 ;
if ( F_26 ( V_27 + 7 , 0 , & V_24 ) == 0 )
V_28 . V_29 = V_24 ;
return NULL ;
}
if ( ! strncmp ( V_27 , L_2 , 8 ) ) {
T_3 V_24 = 0 ;
if ( F_26 ( V_27 + 8 , 0 , & V_24 ) == 0 )
V_28 . V_30 = V_24 ;
return NULL ;
}
if ( ! strncmp ( V_27 , L_3 , 5 ) ) {
T_4 V_24 ;
if ( F_27 ( V_27 + 5 , 0 , & V_24 ) == 0 )
V_28 . V_31 = V_24 ;
return NULL ;
}
return V_27 ;
}
void T_1 F_28 ( struct V_3 T_2 * V_4 ,
struct V_1 * V_2 , int V_32 )
{
int V_5 ;
unsigned long V_33 ;
F_1 ( V_2 , V_4 ) ;
if ( ! V_2 -> V_34 )
F_29 ( V_35
L_4 ,
F_8 ( & V_4 -> V_36 ) >> 16 ,
F_8 ( & V_4 -> V_36 ) & 0xffff ,
F_8 ( & V_4 -> V_37 ) & 0xff ,
V_32 ? L_5 : L_6 ) ;
V_2 -> V_34 = & V_38 ;
F_30 ( V_33 ) ;
F_7 ( F_8 ( & V_4 -> V_39 )
& ~ ( F_31 ( 0 )
| F_31 ( 1 )
| F_31 ( 2 )
| V_40 ) ,
& V_4 -> V_39 ) ;
F_7 ( ( V_2 -> V_41 -> V_42 - V_2 -> V_41 -> V_43 )
>> 4 ,
& V_4 -> V_44 ) ;
F_32 ((channel->io_resource->start +
channel->io_map_base - IO_BASE) |
#ifdef F_12
TX4927_PCIC_G2PIOGBASE_ECHG
#else
TX4927_PCIC_G2PIOGBASE_BSDIS
#endif
, &pcicptr->g2piogbase) ;
F_32 ( V_2 -> V_41 -> V_43 - V_2 -> V_45 ,
& V_4 -> V_46 ) ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
F_7 ( 0 , & V_4 -> V_47 [ V_5 ] ) ;
F_32 ( 0 , & V_4 -> V_48 [ V_5 ] ) ;
F_32 ( 0 , & V_4 -> V_49 [ V_5 ] ) ;
}
if ( V_2 -> V_50 -> V_42 ) {
F_7 ( ( V_2 -> V_50 -> V_42
- V_2 -> V_50 -> V_43 ) >> 4 ,
& V_4 -> V_47 [ 0 ] ) ;
F_32 (channel->mem_resource->start |
#ifdef F_12
TX4927_PCIC_G2PMnGBASE_ECHG
#else
TX4927_PCIC_G2PMnGBASE_BSDIS
#endif
, &pcicptr->g2pmgbase[0]) ;
F_32 ( V_2 -> V_50 -> V_43 -
V_2 -> V_51 ,
& V_4 -> V_49 [ 0 ] ) ;
}
F_7 ( 0 , & V_4 -> V_52 ) ;
F_32 ( 0 , & V_4 -> V_53 ) ;
F_7 ( 0 , & V_4 -> V_54 ) ;
F_7 ( 0 , & V_4 -> V_55 ) ;
F_32 (TX4927_PCIC_P2GMnGBASE_TMEMEN |
#ifdef F_12
TX4927_PCIC_P2GMnGBASE_TECHG
#else
TX4927_PCIC_P2GMnGBASE_TBSDIS
#endif
, &pcicptr->p2gmgbase[0]) ;
F_7 ( 0xffffffff , & V_4 -> V_56 ) ;
F_7 ( 0xffffffff , & V_4 -> V_57 ) ;
F_32 ( 0 , & V_4 -> V_58 [ 1 ] ) ;
F_7 ( 0xffffffff , & V_4 -> V_59 ) ;
F_32 ( 0 , & V_4 -> V_58 [ 2 ] ) ;
F_7 ( ( V_28 . V_31 << 16 )
& V_60 ,
& V_4 -> V_39 ) ;
if ( V_2 -> V_50 -> V_42 )
F_7 ( F_8 ( & V_4 -> V_39 )
| F_31 ( 0 ) ,
& V_4 -> V_39 ) ;
if ( V_2 -> V_41 -> V_42 )
F_7 ( F_8 ( & V_4 -> V_39 )
| V_40 ,
& V_4 -> V_39 ) ;
F_7 ( F_8 ( & V_4 -> V_39 )
| V_61 | V_62 ,
& V_4 -> V_39 ) ;
F_7 ( 0 , & V_4 -> V_63 ) ;
F_7 ( ( F_8 ( & V_4 -> V_64 ) & ~ 0xffff )
| ( V_28 . V_29 & 0xff )
| ( ( V_28 . V_30 & 0xff ) << 8 ) ,
& V_4 -> V_64 ) ;
F_7 ( V_65 , & V_4 -> V_19 ) ;
F_7 ( V_65 , & V_4 -> V_66 ) ;
F_7 ( V_67 , & V_4 -> V_68 ) ;
F_7 ( V_67 , & V_4 -> V_69 ) ;
F_7 ( ( F_8 ( & V_4 -> V_15 ) & 0x0000ffff )
| ( V_70 << 16 ) ,
& V_4 -> V_15 ) ;
F_7 ( V_70 , & V_4 -> V_71 ) ;
if ( ! V_32 ) {
F_7 ( V_72 , & V_4 -> V_73 ) ;
F_7 ( 0 , & V_4 -> V_74 ) ;
F_7 ( V_75 , & V_4 -> V_73 ) ;
}
F_7 ( V_76 | V_77
| V_78 | V_79 ,
& V_4 -> V_15 ) ;
F_33 ( V_33 ) ;
F_29 ( V_80
L_7
L_8 ,
F_8 ( & V_4 -> V_15 ) & 0xffff ,
F_8 ( & V_4 -> V_71 ) & 0xffff ,
F_8 ( & V_4 -> V_64 ) & 0xff ,
( F_8 ( & V_4 -> V_64 ) & 0xff00 ) >> 8 ,
( F_8 ( & V_4 -> V_39 ) >> 16 ) & 0xfff ) ;
}
static void F_34 ( struct V_3 T_2 * V_4 )
{
T_6 V_15 = ( T_6 ) ( F_8 ( & V_4 -> V_15 ) >> 16 ) ;
T_7 V_68 = F_8 ( & V_4 -> V_68 ) ;
T_7 V_19 = F_8 ( & V_4 -> V_19 ) ;
static struct {
T_7 V_81 ;
const char * V_27 ;
} V_82 [] = {
{ V_83 , L_9 } ,
{ V_84 , L_10 } ,
{ V_16 , L_11 } ,
{ V_85 , L_12 } ,
{ V_86 , L_13 } ,
{ V_87 , L_14 } ,
} , V_88 [] = {
{ V_89 , L_15 } ,
{ V_90 , L_16 } ,
} , V_91 [] = {
{ V_92 , L_17 } ,
{ V_93 , L_18 } ,
{ V_94 , L_19 } ,
{ V_95 , L_20 } ,
{ V_96 , L_21 } ,
{ V_97 , L_22 } ,
{ V_98 , L_23 } ,
{ V_20 , L_24 } ,
} ;
int V_5 , V_99 ;
F_29 ( V_100 L_25 ) ;
if ( V_15 & V_70 ) {
F_29 ( V_101 L_26 , V_15 ) ;
for ( V_5 = 0 , V_99 = 0 ; V_5 < F_2 ( V_82 ) ; V_5 ++ )
if ( V_15 & V_82 [ V_5 ] . V_81 )
F_29 ( V_101 L_27 ,
V_99 ++ ? L_28 : L_25 , V_82 [ V_5 ] . V_27 ) ;
F_29 ( V_101 L_29 ) ;
}
if ( V_68 & V_67 ) {
F_29 ( V_101 L_30 , V_68 ) ;
for ( V_5 = 0 , V_99 = 0 ; V_5 < F_2 ( V_88 ) ; V_5 ++ )
if ( V_68 & V_88 [ V_5 ] . V_81 )
F_29 ( V_101 L_27 ,
V_99 ++ ? L_28 : L_25 , V_88 [ V_5 ] . V_27 ) ;
F_29 ( V_101 L_29 ) ;
}
if ( V_19 & V_65 ) {
F_29 ( V_101 L_31 , V_19 ) ;
for ( V_5 = 0 , V_99 = 0 ; V_5 < F_2 ( V_91 ) ; V_5 ++ )
if ( V_19 & V_91 [ V_5 ] . V_81 )
F_29 ( V_101 L_27 ,
V_99 ++ ? L_28 : L_25 , V_91 [ V_5 ] . V_27 ) ;
F_29 ( V_101 L_32 ) ;
}
F_29 ( V_101 L_33 ) ;
}
void F_35 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
if ( V_6 [ V_5 ] . V_4 )
F_34 ( V_6 [ V_5 ] . V_4 ) ;
}
}
static void F_36 ( struct V_3 T_2 * V_4 )
{
int V_5 ;
T_7 T_2 * V_102 = ( T_7 T_2 * ) V_4 ;
F_29 ( V_35 L_34 , V_4 ) ;
for ( V_5 = 0 ; V_5 < sizeof( struct V_3 ) ; V_5 += 4 , V_102 ++ ) {
if ( V_5 % 32 == 0 ) {
F_29 ( V_101 L_33 ) ;
F_29 ( V_35 L_35 , V_5 ) ;
}
if ( V_5 == F_37 ( struct V_3 , V_103 )
|| V_5 == F_37 ( struct V_3 , V_104 )
|| V_5 == F_37 ( struct V_3 , V_14 )
|| V_5 == F_37 ( struct V_3 , V_23 ) ) {
F_29 ( V_101 L_36 ) ;
continue;
}
F_29 ( V_101 L_37 , F_8 ( V_102 ) ) ;
}
F_29 ( V_101 L_33 ) ;
}
void F_38 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
if ( V_6 [ V_5 ] . V_4 )
F_36 ( V_6 [ V_5 ] . V_4 ) ;
}
}
T_8 F_39 ( int V_105 , void * V_106 )
{
struct V_107 * V_108 = F_40 () ;
struct V_3 T_2 * V_4 =
(struct V_3 T_2 * ) ( unsigned long ) V_106 ;
if ( V_109 != V_110 ) {
F_29 ( V_111 L_38 ,
( int ) ( 2 * sizeof( unsigned long ) ) , V_108 -> V_112 ) ;
F_34 ( V_4 ) ;
}
if ( V_109 != V_113 ) {
F_7 ( ( F_8 ( & V_4 -> V_15 ) & 0x0000ffff )
| ( V_70 << 16 ) ,
& V_4 -> V_15 ) ;
F_7 ( V_67 , & V_4 -> V_68 ) ;
F_7 ( V_114 , & V_4 -> V_115 ) ;
F_7 ( V_65 , & V_4 -> V_19 ) ;
return V_116 ;
}
F_41 () ;
F_36 ( V_4 ) ;
F_42 ( L_39 ) ;
}
static void F_43 ( struct V_117 * V_118 )
{
struct V_3 T_2 * V_4 = F_22 ( V_118 -> V_8 ) ;
if ( ! V_4 )
return;
if ( F_8 ( & V_4 -> V_73 ) & V_75 ) {
F_7 ( V_72 , & V_4 -> V_73 ) ;
F_7 ( 0x72543610 , & V_4 -> V_119 ) ;
F_7 ( 0 , & V_4 -> V_74 ) ;
F_7 ( V_120 , & V_4 -> V_73 ) ;
F_7 ( V_120 |
V_75 ,
& V_4 -> V_73 ) ;
F_29 ( V_35 L_40 ,
F_8 ( & V_4 -> V_119 ) ) ;
}
}
