static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static int F_5 ( int V_6 , int V_7 , int V_8 )
{
return ( V_6 << 5 ) | ( ( V_7 & 0x3 ) << 3 ) | ( V_8 & 0x7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_4 ,
int V_9 , int V_10 )
{
T_1 V_3 ;
V_3 = 0x100 << F_7 ( V_9 ) ;
if ( V_10 )
V_3 |= 1 << F_7 ( V_9 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_9 )
{
F_6 ( V_2 , F_9 ( V_2 , V_9 ) , V_9 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_9 )
{
F_6 ( V_2 , F_9 ( V_2 , V_9 ) , V_9 , 0 ) ;
}
static int F_11 ( struct V_11 * V_12 , unsigned V_13 )
{
return F_12 ( V_13 ) ;
}
static void F_13 ( struct V_11 * V_12 , unsigned V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
F_15 ( V_13 ) ;
F_10 ( V_2 , V_13 ) ;
}
static void F_16 ( struct V_11 * V_12 , unsigned V_13 , int V_10 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
F_6 ( V_2 , F_17 ( V_2 , V_13 ) , V_13 , V_10 ) ;
}
static int F_18 ( struct V_11 * V_12 , unsigned V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
int V_14 = F_19 ( F_7 ( V_13 ) ) ;
if ( F_3 ( V_2 , F_20 ( V_2 , V_13 ) ) & V_14 )
return ! ! ( F_3 ( V_2 , F_21 ( V_2 , V_13 ) ) & V_14 ) ;
return ! ! ( F_3 ( V_2 , F_22 ( V_2 , V_13 ) ) & V_14 ) ;
}
static int F_23 ( struct V_11 * V_12 , unsigned V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
F_6 ( V_2 , F_24 ( V_2 , V_13 ) , V_13 , 0 ) ;
F_8 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_25 ( struct V_11 * V_12 , unsigned V_13 ,
int V_10 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
F_16 ( V_12 , V_13 , V_10 ) ;
F_6 ( V_2 , F_24 ( V_2 , V_13 ) , V_13 , 1 ) ;
F_8 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 , unsigned V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
T_1 V_15 = F_19 ( F_7 ( V_13 ) ) ;
T_1 V_16 , V_17 ;
V_16 = F_3 ( V_2 , F_27 ( V_2 , V_13 ) ) ;
if ( ! ( V_16 & V_15 ) )
return - V_18 ;
V_17 = F_3 ( V_2 , F_20 ( V_2 , V_13 ) ) ;
return ( V_17 & V_15 ) ? V_19 : V_20 ;
}
static int F_28 ( struct V_11 * V_12 , unsigned int V_13 ,
unsigned int V_21 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
struct V_22 * V_6 = & V_2 -> V_23 [ F_29 ( V_13 ) ] ;
unsigned int V_24 = F_30 ( V_21 , 1000 ) ;
unsigned long V_25 ;
int V_7 ;
if ( ! V_24 ) {
F_6 ( V_2 , F_31 ( V_2 , V_13 ) ,
V_13 , 0 ) ;
return 0 ;
}
V_24 = F_32 ( V_24 , 255U ) ;
V_7 = F_33 ( V_13 ) ;
F_34 ( & V_6 -> V_26 [ V_7 ] , V_25 ) ;
if ( V_6 -> V_27 [ V_7 ] < V_24 ) {
F_1 ( V_2 , V_24 , F_35 ( V_2 , V_13 ) ) ;
V_6 -> V_27 [ V_7 ] = V_24 ;
}
F_36 ( & V_6 -> V_26 [ V_7 ] , V_25 ) ;
F_6 ( V_2 , F_31 ( V_2 , V_13 ) , V_13 , 1 ) ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 , unsigned V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
return F_38 ( V_2 -> V_28 , V_13 ) ;
}
static void F_39 ( struct V_29 * V_30 )
{
struct V_22 * V_6 = F_40 ( V_30 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
int V_9 = V_30 -> V_31 ;
F_1 ( V_2 , 1 << F_7 ( V_9 ) , F_41 ( V_2 , V_9 ) ) ;
}
static void F_42 ( struct V_29 * V_30 )
{
struct V_22 * V_6 = F_40 ( V_30 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
int V_9 = V_30 -> V_31 ;
F_6 ( V_2 , F_43 ( V_2 , V_9 ) , V_9 , 0 ) ;
}
static void F_44 ( struct V_29 * V_30 )
{
struct V_22 * V_6 = F_40 ( V_30 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
int V_9 = V_30 -> V_31 ;
F_6 ( V_2 , F_43 ( V_2 , V_9 ) , V_9 , 1 ) ;
}
static int F_45 ( struct V_29 * V_30 , unsigned int type )
{
int V_9 = V_30 -> V_31 ;
struct V_22 * V_6 = F_40 ( V_30 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
int V_7 = F_33 ( V_9 ) ;
int V_32 ;
int V_3 ;
unsigned long V_25 ;
int V_33 ;
switch ( type & V_34 ) {
case V_35 :
V_32 = V_36 ;
break;
case V_37 :
V_32 = V_38 ;
break;
case V_39 :
V_32 = V_40 ;
break;
case V_41 :
V_32 = V_42 ;
break;
case V_43 :
V_32 = V_44 ;
break;
default:
return - V_18 ;
}
V_33 = F_46 ( & V_2 -> V_45 , V_9 ) ;
if ( V_33 ) {
F_47 ( V_2 -> V_46 ,
L_1 , V_9 ) ;
return V_33 ;
}
F_34 ( & V_6 -> V_47 [ V_7 ] , V_25 ) ;
V_3 = F_3 ( V_2 , F_48 ( V_2 , V_9 ) ) ;
V_3 &= ~ ( V_48 << F_7 ( V_9 ) ) ;
V_3 |= V_32 << F_7 ( V_9 ) ;
F_1 ( V_2 , V_3 , F_48 ( V_2 , V_9 ) ) ;
F_36 ( & V_6 -> V_47 [ V_7 ] , V_25 ) ;
F_6 ( V_2 , F_24 ( V_2 , V_9 ) , V_9 , 0 ) ;
F_8 ( V_2 , V_9 ) ;
if ( type & ( V_43 | V_41 ) )
F_49 ( V_30 , V_49 ) ;
else if ( type & ( V_37 | V_35 ) )
F_49 ( V_30 , V_50 ) ;
return 0 ;
}
static void F_50 ( struct V_29 * V_30 )
{
struct V_22 * V_6 = F_40 ( V_30 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
int V_9 = V_30 -> V_31 ;
F_51 ( & V_2 -> V_45 , V_9 ) ;
}
static void F_52 ( struct V_51 * V_52 )
{
int V_7 ;
int V_53 ;
int V_54 = 0 ;
int V_9 ;
T_1 V_55 ;
unsigned long V_56 ;
struct V_57 * V_12 = F_53 ( V_52 ) ;
struct V_22 * V_6 = F_54 ( V_52 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_55 ( V_12 , V_52 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_9 = F_5 ( V_6 -> V_6 , V_7 , 0 ) ;
V_56 = F_3 ( V_2 , F_56 ( V_2 , V_9 ) ) &
F_3 ( V_2 , F_57 ( V_2 , V_9 ) ) ;
V_55 = F_3 ( V_2 , F_48 ( V_2 , V_9 ) ) ;
F_58 (pin, &sta, 8 ) {
F_1 ( V_2 , 1 << V_53 ,
F_41 ( V_2 , V_9 ) ) ;
if ( V_55 & ( 0x100 << V_53 ) ) {
V_54 = 1 ;
F_59 ( V_12 , V_52 ) ;
}
F_60 ( F_61 ( V_9 + V_53 ) ) ;
}
}
if ( ! V_54 )
F_59 ( V_12 , V_52 ) ;
}
static int F_62 ( struct V_58 * V_46 )
{
struct V_59 * V_60 = F_63 ( V_46 ) ;
struct V_1 * V_2 = F_64 ( V_60 ) ;
unsigned long V_25 ;
int V_61 ;
int V_62 ;
F_65 ( V_25 ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_63 ; V_61 ++ ) {
struct V_22 * V_6 = & V_2 -> V_23 [ V_61 ] ;
for ( V_62 = 0 ; V_62 < F_66 ( V_6 -> V_17 ) ; V_62 ++ ) {
unsigned int V_9 = ( V_61 << 5 ) | ( V_62 << 3 ) ;
F_1 ( V_2 , V_6 -> V_16 [ V_62 ] ,
F_27 ( V_2 , V_9 ) ) ;
if ( V_2 -> V_64 -> V_65 ) {
F_1 ( V_2 , V_6 -> V_27 [ V_62 ] ,
F_35 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_66 [ V_62 ] ,
F_31 ( V_2 , V_9 ) ) ;
}
F_1 ( V_2 , V_6 -> V_67 [ V_62 ] ,
F_21 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_17 [ V_62 ] ,
F_20 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_68 [ V_62 ] ,
F_48 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_69 [ V_62 ] ,
F_57 ( V_2 , V_9 ) ) ;
}
}
F_67 ( V_25 ) ;
return 0 ;
}
static int F_68 ( struct V_58 * V_46 )
{
struct V_59 * V_60 = F_63 ( V_46 ) ;
struct V_1 * V_2 = F_64 ( V_60 ) ;
unsigned long V_25 ;
int V_61 ;
int V_62 ;
F_65 ( V_25 ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_63 ; V_61 ++ ) {
struct V_22 * V_6 = & V_2 -> V_23 [ V_61 ] ;
for ( V_62 = 0 ; V_62 < F_66 ( V_6 -> V_17 ) ; V_62 ++ ) {
unsigned int V_9 = ( V_61 << 5 ) | ( V_62 << 3 ) ;
V_6 -> V_16 [ V_62 ] = F_3 ( V_2 ,
F_27 ( V_2 , V_9 ) ) ;
V_6 -> V_67 [ V_62 ] = F_3 ( V_2 ,
F_21 ( V_2 , V_9 ) ) ;
V_6 -> V_17 [ V_62 ] = F_3 ( V_2 ,
F_20 ( V_2 , V_9 ) ) ;
if ( V_2 -> V_64 -> V_65 ) {
V_6 -> V_66 [ V_62 ] = F_3 ( V_2 ,
F_31 ( V_2 , V_9 ) ) ;
V_6 -> V_66 [ V_62 ] = ( V_6 -> V_66 [ V_62 ] << 8 ) |
V_6 -> V_66 [ V_62 ] ;
}
V_6 -> V_69 [ V_62 ] = F_3 ( V_2 ,
F_57 ( V_2 , V_9 ) ) ;
V_6 -> V_68 [ V_62 ] = F_3 ( V_2 ,
F_48 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_70 [ V_62 ] ,
F_57 ( V_2 , V_9 ) ) ;
}
}
F_67 ( V_25 ) ;
return 0 ;
}
static int F_69 ( struct V_29 * V_30 , unsigned int V_71 )
{
struct V_22 * V_6 = F_40 ( V_30 ) ;
int V_9 = V_30 -> V_31 ;
T_1 V_7 , V_8 , V_72 ;
V_7 = F_33 ( V_9 ) ;
V_8 = F_7 ( V_9 ) ;
V_72 = F_19 ( V_8 ) ;
if ( V_71 )
V_6 -> V_70 [ V_7 ] |= V_72 ;
else
V_6 -> V_70 [ V_7 ] &= ~ V_72 ;
return F_70 ( V_6 -> V_73 , V_71 ) ;
}
static int F_71 ( struct V_74 * V_75 , void * V_76 )
{
struct V_1 * V_2 = V_75 -> V_77 ;
int V_78 ;
int V_79 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_63 ; V_78 ++ ) {
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
int V_9 = F_5 ( V_78 , V_79 , 0 ) ;
F_72 ( V_75 ,
L_2 ,
V_78 , V_79 ,
F_3 ( V_2 , F_27 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_20 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_21 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_22 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_56 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_57 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_48 ( V_2 , V_9 ) ) ) ;
}
}
return 0 ;
}
static int F_73 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_74 ( V_81 , F_71 , V_80 -> V_82 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
( void ) F_76 ( L_3 , V_83 ,
NULL , V_2 , & V_84 ) ;
}
static inline void F_75 ( struct V_1 * V_2 )
{
}
static int F_77 ( struct V_59 * V_60 )
{
const struct V_85 * V_86 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
struct V_22 * V_6 ;
int V_33 ;
int V_9 ;
int V_78 ;
int V_79 ;
V_86 = F_78 ( & V_60 -> V_46 ) ;
if ( ! V_86 ) {
F_47 ( & V_60 -> V_46 , L_4 ) ;
return - V_89 ;
}
V_2 = F_79 ( & V_60 -> V_46 , sizeof( * V_2 ) , V_90 ) ;
if ( ! V_2 )
return - V_89 ;
V_2 -> V_64 = V_86 ;
V_2 -> V_46 = & V_60 -> V_46 ;
for (; ; ) {
V_88 = F_80 ( V_60 , V_91 ,
V_2 -> V_63 ) ;
if ( ! V_88 )
break;
V_2 -> V_63 ++ ;
}
if ( ! V_2 -> V_63 ) {
F_47 ( & V_60 -> V_46 , L_5 ) ;
return - V_89 ;
}
V_2 -> V_45 . V_92 = L_6 ;
V_2 -> V_45 . V_93 = F_11 ;
V_2 -> V_45 . free = F_13 ;
V_2 -> V_45 . V_94 = F_23 ;
V_2 -> V_45 . V_95 = F_18 ;
V_2 -> V_45 . V_96 = F_25 ;
V_2 -> V_45 . V_97 = F_16 ;
V_2 -> V_45 . V_98 = F_26 ;
V_2 -> V_45 . V_99 = F_37 ;
V_2 -> V_45 . V_100 = 0 ;
V_2 -> V_45 . V_101 = V_2 -> V_63 * 32 ;
V_2 -> V_45 . V_102 = & V_60 -> V_46 ;
V_2 -> V_45 . V_103 = V_60 -> V_46 . V_103 ;
V_2 -> V_104 . V_105 = L_7 ;
V_2 -> V_104 . V_106 = F_39 ;
V_2 -> V_104 . V_107 = F_42 ;
V_2 -> V_104 . V_108 = F_44 ;
V_2 -> V_104 . V_109 = F_45 ;
V_2 -> V_104 . V_110 = F_50 ;
#ifdef F_81
V_2 -> V_104 . V_111 = F_69 ;
#endif
F_82 ( V_60 , V_2 ) ;
if ( V_86 -> V_65 )
V_2 -> V_45 . V_112 = F_28 ;
V_2 -> V_23 = F_79 ( & V_60 -> V_46 , V_2 -> V_63 *
sizeof( * V_2 -> V_23 ) , V_90 ) ;
if ( ! V_2 -> V_23 )
return - V_89 ;
V_2 -> V_28 = F_83 ( V_60 -> V_46 . V_103 ,
V_2 -> V_45 . V_101 ,
& V_113 , NULL ) ;
if ( ! V_2 -> V_28 )
return - V_89 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_63 ; V_78 ++ ) {
V_88 = F_80 ( V_60 , V_91 , V_78 ) ;
if ( ! V_88 ) {
F_47 ( & V_60 -> V_46 , L_5 ) ;
return - V_89 ;
}
V_6 = & V_2 -> V_23 [ V_78 ] ;
V_6 -> V_6 = V_78 ;
V_6 -> V_73 = V_88 -> V_114 ;
V_6 -> V_2 = V_2 ;
}
V_88 = F_80 ( V_60 , V_115 , 0 ) ;
V_2 -> V_5 = F_84 ( & V_60 -> V_46 , V_88 ) ;
if ( F_85 ( V_2 -> V_5 ) )
return F_86 ( V_2 -> V_5 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_63 ; V_78 ++ ) {
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
int V_9 = F_5 ( V_78 , V_79 , 0 ) ;
F_1 ( V_2 , 0x00 , F_57 ( V_2 , V_9 ) ) ;
}
}
V_33 = F_87 ( & V_60 -> V_46 , & V_2 -> V_45 , V_2 ) ;
if ( V_33 < 0 ) {
F_88 ( V_2 -> V_28 ) ;
return V_33 ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_45 . V_101 ; V_9 ++ ) {
int V_73 = F_89 ( V_2 -> V_28 , V_9 ) ;
V_6 = & V_2 -> V_23 [ F_29 ( V_9 ) ] ;
F_90 ( V_73 , & V_116 ) ;
F_91 ( V_73 , V_6 ) ;
F_92 ( V_73 , & V_2 -> V_104 , V_117 ) ;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_63 ; V_78 ++ ) {
V_6 = & V_2 -> V_23 [ V_78 ] ;
F_93 ( V_6 -> V_73 ,
F_52 , V_6 ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ ) {
F_94 ( & V_6 -> V_47 [ V_79 ] ) ;
F_94 ( & V_6 -> V_26 [ V_79 ] ) ;
}
}
F_75 ( V_2 ) ;
return 0 ;
}
static int T_2 F_95 ( void )
{
return F_96 ( & V_118 ) ;
}
