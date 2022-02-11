static inline T_1
F_1 ( int V_1 )
{
if ( V_1 == 0 )
return V_2 ;
if ( V_1 == 1 )
return V_3 ;
if ( V_1 == 2 )
return V_4 ;
F_2 () ;
}
static inline T_1
F_3 ( int V_1 )
{
if ( V_1 == 0 )
return V_5 ;
if ( V_1 == 1 )
return V_6 ;
if ( V_1 == 2 )
return V_7 ;
F_2 () ;
}
static inline T_1
F_4 ( int V_1 )
{
if ( V_1 == 0 )
return V_8 ;
if ( V_1 == 1 )
return V_9 ;
if ( V_1 == 2 )
return V_10 ;
F_2 () ;
}
static inline T_1
F_5 ( int V_1 )
{
if ( V_1 == 0 )
return V_11 ;
if ( V_1 == 1 )
return V_12 ;
if ( V_1 == 2 )
return V_13 ;
F_2 () ;
}
void
F_6 ( struct V_14 * V_15 , int V_1 , T_1 V_16 )
{
if ( ( V_15 -> V_17 [ V_1 ] & V_16 ) != V_16 ) {
T_1 V_18 = F_1 ( V_1 ) ;
V_15 -> V_17 [ V_1 ] |= V_16 ;
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_20 = F_8 ( V_18 ) ;
V_20 |= ( V_16 | ( V_16 >> 16 ) ) ;
F_9 ( V_20 , V_18 ) ;
( void ) F_8 ( V_18 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
}
void
F_11 ( struct V_14 * V_15 , int V_1 , T_1 V_16 )
{
if ( ( V_15 -> V_17 [ V_1 ] & V_16 ) != 0 ) {
T_1 V_18 = F_1 ( V_1 ) ;
V_15 -> V_17 [ V_1 ] &= ~ V_16 ;
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_20 = F_8 ( V_18 ) ;
V_20 &= ~ V_16 ;
F_9 ( V_20 , V_18 ) ;
( void ) F_8 ( V_18 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
}
static void F_12 ( struct V_14 * V_15 , int V_1 )
{
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_21 = F_3 ( V_1 ) ;
V_15 -> V_22 |= V_21 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
static void F_13 ( struct V_14 * V_15 , int V_1 )
{
if ( V_15 -> V_17 [ V_1 ] == 0 ) {
if ( F_7 ( V_15 -> V_19 , false ) ) {
T_1 V_21 = F_3 ( V_1 ) ;
V_15 -> V_22 &= ~ V_21 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_10 ( V_15 -> V_19 ) ;
}
}
}
static void F_14 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_2 V_27 = 0 ;
T_2 V_28 = F_1 ( V_1 ) ;
T_2 V_29 = V_15 -> V_17 [ V_1 ] ;
T_2 V_30 = V_15 -> V_17 [ V_1 ] >> 16 ;
T_2 V_31 ;
T_2 V_32 = 0 ;
F_15 ( & V_15 -> V_33 ) ;
V_27 = F_8 ( V_28 ) ;
V_27 &= V_29 | V_30 ;
V_27 &= V_27 >> 16 ;
F_16 ( & V_15 -> V_33 ) ;
for ( V_32 = 0 ; V_32 < 0xffff ; V_32 ++ ) {
F_9 ( F_8 ( V_28 ) , V_28 ) ;
V_31 = F_8 ( V_28 ) & V_30 ;
if ( V_31 == 0 )
break;
}
if ( V_31 )
F_17 ( V_19 -> V_19 ,
L_1 ,
V_34 , V_1 , F_8 ( V_28 ) ) ;
if ( V_27 & V_35 )
F_18 ( V_19 , V_1 ) ;
if ( V_27 & V_36 )
F_18 ( V_19 , V_1 ) ;
}
static void F_19 ( struct V_25 * V_19 , T_2 V_37 )
{
if ( V_37 & V_38 )
F_20 ( V_19 ) ;
if ( V_37 & V_8 )
F_14 ( V_19 , 0 ) ;
if ( V_37 & V_9 )
F_14 ( V_19 , 1 ) ;
}
static void F_21 ( struct V_25 * V_19 , T_1 V_39 , T_1 V_40 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
T_1 V_41 , V_42 ;
int error = false ;
if ( V_39 & V_43 )
V_41 = F_22 ( V_44 ) ;
if ( V_40 & V_45 ) {
V_41 = F_22 ( V_46 ) ;
V_42 = F_22 ( V_47 ) ;
if ( V_41 ) {
if ( V_41 & V_48 )
F_23 ( L_2 ) ;
else
F_23 ( L_3 ) ;
if ( V_41 & V_49 )
F_23 ( L_4 ) ;
if ( V_41 & V_50 )
F_23 ( L_5 ) ;
if ( V_41 & V_51 )
F_23 ( L_6 ) ;
if ( V_41 & V_52 )
F_23 ( L_7 ) ;
if ( V_41 & V_53 )
F_23 ( L_8 ) ;
if ( V_41 & V_54 )
F_23 ( L_9 ) ;
if ( V_41 & V_55 )
F_23 ( L_10 ) ;
if ( V_41 & V_56 )
F_23 ( L_11 ) ;
if ( V_41 & V_57 )
F_23 ( L_12 ) ;
F_23 ( L_13 ,
( unsigned int ) V_42 ) ;
error = true ;
}
}
F_24 ( V_39 , V_58 ) ;
F_24 ( V_40 , V_59 ) ;
F_22 ( V_59 ) ;
}
T_3 F_25 ( int V_60 , void * V_61 )
{
struct V_25 * V_19 = V_61 ;
struct V_14 * V_15 = V_19 -> V_26 ;
T_2 V_37 , V_62 = 0 , V_63 = 0 , V_64 = 0 ;
T_1 V_65 , V_66 ;
int V_67 = 0 ;
F_15 ( & V_15 -> V_33 ) ;
V_37 = F_8 ( V_68 ) ;
if ( V_37 & ( V_69 | V_38 ) )
V_62 = 1 ;
if ( V_37 & V_70 )
V_63 = 1 ;
if ( V_37 & V_71 )
V_64 = 1 ;
V_37 &= V_15 -> V_22 ;
F_16 ( & V_15 -> V_33 ) ;
if ( V_62 && F_26 ( V_19 ) ) {
F_19 ( V_19 , V_37 ) ;
V_67 = 1 ;
}
if ( V_63 ) {
V_65 = F_22 ( V_72 ) ;
V_66 = F_22 ( V_73 ) ;
F_21 ( V_19 , V_65 , V_66 ) ;
V_67 = 1 ;
}
if ( V_64 && V_15 -> V_74 -> V_75 ) {
V_67 = V_15 -> V_74 -> V_75 ( V_19 ) ;
F_27 ( V_76 , F_28 ( V_76 ) ) ;
}
F_9 ( V_37 , V_68 ) ;
( void ) F_8 ( V_68 ) ;
F_29 () ;
if ( ! V_67 )
return V_77 ;
return V_78 ;
}
void F_30 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_79 ;
F_31 ( & V_15 -> V_33 , V_79 ) ;
if ( F_26 ( V_19 ) ) {
F_9 ( 0xFFFFFFFF , V_80 ) ;
F_9 ( 0x00000000 , V_23 ) ;
F_9 ( 0x00000000 , V_24 ) ;
F_24 ( 0x00000000 , V_81 ) ;
F_22 ( V_81 ) ;
}
if ( V_19 -> V_82 [ 0 ] . V_83 )
V_15 -> V_22 |= V_8 ;
if ( V_19 -> V_82 [ 1 ] . V_83 )
V_15 -> V_22 |= V_9 ;
if ( V_15 -> V_74 -> V_75 )
V_15 -> V_22 |= V_71 ;
V_15 -> V_22 |= V_38 | V_70 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
}
int F_33 ( struct V_25 * V_19 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_79 ;
F_31 ( & V_15 -> V_33 , V_79 ) ;
F_24 ( V_45 , V_84 ) ;
F_24 ( V_43 , V_81 ) ;
F_22 ( V_81 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_9 ( 0xFFFFFFFF , V_80 ) ;
if ( V_19 -> V_82 [ 0 ] . V_83 )
F_6 ( V_15 , 0 , V_85 ) ;
else
F_11 ( V_15 , 0 , V_85 ) ;
if ( V_19 -> V_82 [ 1 ] . V_83 )
F_6 ( V_15 , 1 , V_85 ) ;
else
F_11 ( V_15 , 1 , V_85 ) ;
if ( V_19 -> V_82 [ 2 ] . V_83 )
F_6 ( V_15 , 2 , V_85 ) ;
else
F_11 ( V_15 , 2 , V_85 ) ;
if ( V_15 -> V_74 -> V_86 )
V_15 -> V_74 -> V_86 ( V_19 , true ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
return 0 ;
}
void F_34 ( struct V_25 * V_19 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_79 ;
F_31 ( & V_15 -> V_33 , V_79 ) ;
if ( V_15 -> V_74 -> V_86 )
V_15 -> V_74 -> V_86 ( V_19 , false ) ;
F_9 ( 0xFFFFFFFF , V_80 ) ;
if ( V_19 -> V_82 [ 0 ] . V_83 )
F_11 ( V_15 , 0 , V_85 ) ;
if ( V_19 -> V_82 [ 1 ] . V_83 )
F_11 ( V_15 , 1 , V_85 ) ;
if ( V_19 -> V_82 [ 2 ] . V_83 )
F_11 ( V_15 , 2 , V_85 ) ;
V_15 -> V_22 &= V_70 |
V_87 |
V_88 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_35 () ;
F_9 ( F_8 ( V_68 ) , V_68 ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
}
void F_36 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_1 V_89 ;
T_1 V_90 ;
if ( F_7 ( V_19 , false ) ) {
F_9 ( 1 << 31 , V_91 ) ;
V_89 = F_8 ( V_91 ) ;
F_9 ( 1 << 31 , V_92 ) ;
V_89 = F_8 ( V_92 ) ;
F_9 ( 0x80010100 , V_93 ) ;
V_90 = F_8 ( V_93 ) ;
F_9 ( V_90 | V_94
| V_95 ,
V_93 ) ;
V_90 = F_8 ( V_93 ) ;
F_6 ( V_15 , 0 , V_96 ) ;
V_89 = F_8 ( V_92 ) ;
F_9 ( V_89 | V_97 ,
V_92 ) ;
V_90 = F_8 ( V_93 ) ;
F_9 ( V_90 | 0x80010100 | V_94 ,
V_93 ) ;
F_10 ( V_19 ) ;
}
}
int F_37 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_79 ;
F_31 ( & V_15 -> V_33 , V_79 ) ;
F_12 ( V_15 , 0 ) ;
F_36 ( V_19 ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
return 0 ;
}
void F_38 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
T_1 V_89 ;
T_1 V_90 ;
if ( F_7 ( V_19 , false ) ) {
F_9 ( 0x00000000 , V_92 ) ;
V_89 = F_8 ( V_92 ) ;
F_11 ( V_15 , 0 , V_96 ) ;
V_90 = F_8 ( V_93 ) ;
F_9 ( V_90 & ~ V_95 ,
V_93 ) ;
V_90 = F_8 ( V_93 ) ;
F_10 ( V_19 ) ;
}
}
int F_39 ( struct V_25 * V_19 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_79 ;
F_31 ( & V_15 -> V_33 , V_79 ) ;
F_13 ( V_15 , 0 ) ;
F_38 ( V_19 ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
return 0 ;
}
int F_40 ( struct V_25 * V_19 , unsigned int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_79 ;
T_2 V_98 = 0 ;
T_2 V_99 = F_5 ( V_1 ) ;
if ( F_41 ( V_19 ) )
return F_42 ( V_19 , V_1 ) ;
if ( F_7 ( V_19 , false ) ) {
V_98 = F_28 ( V_99 ) ;
F_10 ( V_19 ) ;
}
if ( ! ( V_98 & V_100 ) )
return - V_101 ;
F_31 ( & V_15 -> V_33 , V_79 ) ;
if ( V_1 == 0 )
V_15 -> V_22 |= V_8 ;
else if ( V_1 == 1 )
V_15 -> V_22 |= V_9 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_6 ( V_15 , V_1 , V_85 ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
return 0 ;
}
void F_43 ( struct V_25 * V_19 , unsigned int V_1 )
{
struct V_14 * V_15 = V_19 -> V_26 ;
unsigned long V_79 ;
if ( F_41 ( V_19 ) )
F_44 ( V_19 , V_1 ) ;
F_31 ( & V_15 -> V_33 , V_79 ) ;
if ( V_1 == 0 )
V_15 -> V_22 &= ~ V_8 ;
else if ( V_1 == 1 )
V_15 -> V_22 &= ~ V_9 ;
F_9 ( ~ V_15 -> V_22 , V_23 ) ;
F_9 ( V_15 -> V_22 , V_24 ) ;
F_11 ( V_15 , V_1 , V_85 ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
}
int F_42 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_79 ;
T_2 V_98 = 0 ;
T_2 V_99 = F_5 ( V_1 ) ;
if ( F_7 ( V_19 , false ) ) {
V_98 = F_28 ( V_99 ) ;
F_10 ( V_19 ) ;
}
if ( ! ( V_98 & V_100 ) )
return - V_101 ;
F_31 ( & V_15 -> V_33 , V_79 ) ;
F_12 ( V_15 , V_1 ) ;
F_6 ( V_15 , V_1 , V_102 ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
return 0 ;
}
void F_44 ( struct V_25 * V_19 , int V_1 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_19 -> V_26 ;
unsigned long V_79 ;
if ( ! V_15 -> V_103 )
return;
F_31 ( & V_15 -> V_33 , V_79 ) ;
F_13 ( V_15 , V_1 ) ;
F_11 ( V_15 , V_1 , V_102 ) ;
F_32 ( & V_15 -> V_33 , V_79 ) ;
}
T_1 F_45 ( struct V_25 * V_19 , unsigned int V_1 )
{
T_2 V_104 = V_105 ;
T_2 V_106 = V_107 ;
T_2 V_99 = V_11 ;
T_2 V_98 = 0 ;
T_2 V_108 = 0 , V_109 = 0 , V_110 = 0 , V_111 = 0 ;
switch ( V_1 ) {
case 0 :
break;
case 1 :
V_104 = V_112 ;
V_106 = V_113 ;
V_99 = V_12 ;
break;
case 2 :
V_104 = V_114 ;
V_106 = V_115 ;
V_99 = V_13 ;
break;
default:
F_17 ( V_19 -> V_19 , L_14 , V_34 ) ;
return 0 ;
}
if ( ! F_7 ( V_19 , false ) )
return 0 ;
V_98 = F_28 ( V_99 ) ;
if ( ! ( V_98 & V_100 ) ) {
F_17 ( V_19 -> V_19 , L_15 ,
V_1 ) ;
goto V_116;
}
do {
V_108 = ( ( F_28 ( V_104 ) & V_117 ) >>
V_118 ) ;
V_110 = ( ( F_28 ( V_106 ) & V_119 ) >>
V_120 ) ;
V_109 = ( ( F_28 ( V_104 ) & V_117 ) >>
V_118 ) ;
} while ( V_108 != V_109 );
V_111 = ( V_108 << 8 ) | V_110 ;
V_116:
F_10 ( V_19 ) ;
return V_111 ;
}
