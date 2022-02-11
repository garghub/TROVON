int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
int V_5 ;
V_4 -> V_6 = NULL ;
switch ( V_4 -> type ) {
case V_7 :
V_4 -> V_6 = & V_8 ;
break;
case V_9 :
V_4 -> V_6 = & V_10 ;
break;
case V_11 :
#ifdef F_2
V_4 -> V_6 = & V_12 ;
#endif
break;
case V_13 :
#ifdef F_3
V_4 -> V_6 = & V_14 ;
#endif
break;
case V_15 :
#ifdef F_4
V_4 -> V_6 = & V_16 ;
#endif
break;
case V_17 :
#ifdef F_5
V_4 -> V_6 = & V_18 ;
#endif
break;
}
if ( F_6 ( ! V_4 -> V_6 ) )
return - V_19 ;
V_5 = V_4 -> V_6 -> V_20 ( V_2 ) ;
if ( V_5 )
V_4 -> V_6 = NULL ;
return V_5 ;
}
void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_4 . V_6 -> free ( V_2 ) ;
V_2 -> V_4 . V_6 = NULL ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
const struct V_21 * V_6 = V_4 -> V_6 ;
int V_5 ;
V_4 -> V_22 = V_6 -> V_23 ( V_2 ) ;
V_6 -> V_24 ( V_2 , false ) ;
V_5 = V_6 -> V_25 ( V_2 ) ;
if ( V_5 ) {
F_9 ( V_2 -> V_26 , L_1 ) ;
goto V_27;
}
V_5 = F_10 ( V_2 , V_6 -> V_23 ( V_2 ) ) ;
if ( V_5 ) {
F_9 ( V_2 -> V_26 , L_2 ) ;
goto V_28;
}
return 0 ;
V_28:
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
V_27:
V_6 -> V_24 ( V_2 , true ) ;
return V_5 ;
}
void F_11 ( struct V_1 * V_2 )
{
const struct V_21 * V_6 = V_2 -> V_4 . V_6 ;
V_6 -> V_24 ( V_2 , true ) ;
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
}
bool F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_29 )
return 0 ;
if ( ! V_2 -> V_4 . V_6 -> V_30 )
return 0 ;
return V_2 -> V_4 . V_6 -> V_30 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
T_1 V_31 ;
#if V_32
F_6 ( V_2 -> V_4 . V_33 ) ;
V_2 -> V_4 . V_33 = 1 ;
#endif
V_31 = F_14 ( V_2 , V_34 ) ;
V_31 |= V_35 ;
F_15 ( V_2 , V_34 , V_31 ) ;
F_14 ( V_2 , V_34 ) ;
F_16 ( 10 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
T_1 V_31 ;
#if V_32
F_6 ( ! V_2 -> V_4 . V_33 ) ;
V_2 -> V_4 . V_33 = 0 ;
#endif
F_18 ( V_2 , V_36 ) ;
V_31 = F_14 ( V_2 , V_34 ) ;
V_31 &= ~ V_35 ;
F_15 ( V_2 , V_34 , V_31 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
#if V_32
F_6 ( V_2 -> V_4 . V_37 ) ;
V_2 -> V_4 . V_37 = 1 ;
#endif
F_6 ( V_2 -> V_2 -> V_38 < 3 ) ;
if ( ! F_20 ( V_2 -> V_26 , V_39 ) )
F_21 ( V_2 , V_40 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
#if V_32
F_6 ( ! V_2 -> V_4 . V_37 ) ;
V_2 -> V_4 . V_37 = 0 ;
#endif
F_6 ( V_2 -> V_2 -> V_38 < 3 ) ;
if ( ! F_20 ( V_2 -> V_26 , V_39 ) )
F_21 ( V_2 , 0 ) ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
if ( ! V_32 )
return;
if ( ( F_24 ( V_2 ) >= V_41 ) &&
( V_2 -> V_42 <= 0 ) ) {
F_25 ( V_2 -> V_26 , L_3
L_4 ) ;
F_26 () ;
}
}
T_2 F_27 ( struct V_1 * V_2 , T_2 V_43 )
{
F_23 ( V_2 ) ;
return V_2 -> V_4 . V_6 -> V_44 ( V_2 , V_43 ) ;
}
void F_28 ( struct V_1 * V_2 , T_2 V_43 , T_2 V_45 )
{
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_46 ( V_2 , V_43 , V_45 ) ;
}
void F_29 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 )
{
F_30 ( V_2 , V_47 ,
F_31 ( V_2 , V_47 ) & V_48 ) ;
}
void F_32 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_49 )
{
F_30 ( V_2 , V_47 ,
F_31 ( V_2 , V_47 ) | V_49 ) ;
}
void F_33 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 , T_2 V_49 )
{
F_30 ( V_2 , V_47 ,
( F_31 ( V_2 , V_47 ) & V_48 ) | V_49 ) ;
}
T_2 F_34 ( struct V_1 * V_2 , T_2 V_43 )
{
F_23 ( V_2 ) ;
V_2 -> V_4 . V_50 = 0 ;
return V_2 -> V_4 . V_6 -> V_51 ( V_2 , V_43 ) ;
}
void F_35 ( struct V_1 * V_2 , T_2 V_43 , T_2 V_45 )
{
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_52 ( V_2 , V_43 , V_45 ) ;
if ( ++ V_2 -> V_4 . V_50 == V_53 ) {
F_18 ( V_2 , V_36 ) ;
V_2 -> V_4 . V_50 = 0 ;
}
}
void F_36 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_55 )
{
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_52 ( V_2 , V_54 ,
V_2 -> V_4 . V_6 -> V_51 ( V_2 , V_55 ) ) ;
}
void F_37 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 )
{
if ( V_2 -> V_4 . V_6 -> V_56 ) {
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_56 ( V_2 , V_47 , V_48 , 0 ) ;
} else {
F_35 ( V_2 , V_47 ,
F_34 ( V_2 , V_47 ) & V_48 ) ;
}
}
void F_38 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_49 )
{
if ( V_2 -> V_4 . V_6 -> V_56 ) {
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_56 ( V_2 , V_47 , 0xFFFF , V_49 ) ;
} else {
F_35 ( V_2 , V_47 ,
F_34 ( V_2 , V_47 ) | V_49 ) ;
}
}
void F_39 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 , T_2 V_49 )
{
if ( V_2 -> V_4 . V_6 -> V_56 ) {
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_56 ( V_2 , V_47 , V_48 , V_49 ) ;
} else {
F_35 ( V_2 , V_47 ,
( F_34 ( V_2 , V_47 ) & V_48 ) | V_49 ) ;
}
}
int F_10 ( struct V_1 * V_2 , unsigned int V_57 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
T_2 V_58 , V_59 ;
int V_5 ;
if ( V_57 == V_60 )
V_57 = V_4 -> V_6 -> V_23 ( V_2 ) ;
V_58 = V_57 ;
if ( F_40 ( V_2 -> V_26 ) == V_61 )
V_58 |= V_62 ;
if ( 0 )
V_58 |= V_63 ;
V_59 = F_41 ( V_2 , V_64 , V_65 ) ;
F_42 ( V_2 , V_64 , V_65 , V_58 ) ;
V_5 = V_4 -> V_6 -> V_66 ( V_2 , V_57 ) ;
if ( V_5 )
goto V_67;
V_2 -> V_4 . V_22 = V_57 ;
F_43 ( 8 ) ;
return 0 ;
V_67:
F_42 ( V_2 , V_64 ,
V_65 , V_59 ) ;
return V_5 ;
}
void F_44 ( struct V_1 * V_2 , bool V_68 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_45 ( V_2 ) ;
V_4 -> V_6 -> V_24 ( V_2 , V_68 ) ;
V_4 -> V_69 = ! V_68 ;
F_46 ( V_2 ) ;
}
void F_47 ( struct V_70 * V_71 )
{
struct V_72 * V_26 = F_48 ( V_71 , struct V_72 ,
V_73 ) ;
struct V_1 * V_2 ;
F_49 ( & V_26 -> V_74 ) ;
V_2 = V_26 -> V_75 ;
if ( F_50 ( V_2 && ( F_24 ( V_2 ) >= V_76 ) ) )
V_2 -> V_4 . V_6 -> V_77 ( V_2 ) ;
F_51 ( & V_26 -> V_74 ) ;
}
void F_52 ( struct V_1 * V_2 , unsigned int V_78 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_79 = V_80 ;
enum V_81 V_82 ;
if ( ! ( V_78 & V_83 ) ) {
if ( F_53 ( V_79 , V_4 -> V_84 ) )
return;
}
V_4 -> V_84 = F_54 ( V_79 + ( V_85 * 2 ) ) ;
if ( ( V_2 -> V_2 -> V_86 == V_87 ) &&
( V_2 -> V_2 -> V_88 == V_89 ) )
return;
V_82 = V_4 -> V_6 -> V_90 ( V_2 , ! ! ( V_78 & V_91 ) ) ;
if ( V_82 == V_92 )
return;
F_6 ( V_82 != V_93 ) ;
F_6 ( V_4 -> V_6 -> V_77 == NULL ) ;
F_55 ( V_2 -> V_26 -> V_94 , & V_2 -> V_26 -> V_73 ) ;
}
int F_56 ( struct V_1 * V_2 , T_2 V_95 )
{
const bool V_96 = ( V_95 != V_97 ) ;
unsigned int V_98 , V_99 , V_100 , V_101 ;
unsigned int V_102 ;
T_1 V_103 ;
V_103 = F_57 ( V_2 , V_64 , V_95 ) ;
V_98 = V_103 & 0xFF ;
V_99 = ( V_103 >> 8 ) & 0xFF ;
V_100 = ( V_103 >> 16 ) & 0xFF ;
V_101 = ( V_103 >> 24 ) & 0xFF ;
if ( V_98 == 0 || V_98 == V_104 ||
V_99 == 0 || V_99 == V_104 ||
V_100 == 0 || V_100 == V_104 ||
V_101 == 0 || V_101 == V_104 )
return - V_105 ;
V_103 = V_104 | ( V_104 << 8 ) |
( V_104 << 16 ) | ( V_104 << 24 ) ;
F_58 ( V_2 , V_64 , V_95 , V_103 ) ;
if ( V_96 ) {
V_98 = ( V_98 + 32 ) & 0x3F ;
V_99 = ( V_99 + 32 ) & 0x3F ;
V_100 = ( V_100 + 32 ) & 0x3F ;
V_101 = ( V_101 + 32 ) & 0x3F ;
}
V_102 = ( V_98 + V_99 + V_100 + V_101 + 2 ) / 4 ;
if ( V_96 ) {
if ( F_41 ( V_2 , V_64 , V_106 )
& V_107 )
V_102 = ( V_102 >= 13 ) ? ( V_102 - 13 ) : 0 ;
}
return V_102 ;
}
void F_59 ( struct V_1 * V_2 , bool V_108 )
{
F_60 ( V_2 , V_109 , V_108 ? 0 : 0xF4 ) ;
}
bool F_61 ( enum V_110 V_111 )
{
return ( V_111 == V_112 ||
V_111 == V_113 ) ;
}
struct V_114 F_62 ( int V_115 )
{
static const T_1 V_116 [] = {
2949120 , 1740967 , 919879 , 466945 , 234379 , 117304 ,
58666 , 29335 , 14668 , 7334 , 3667 , 1833 ,
917 , 458 , 229 , 115 , 57 , 29 ,
} ;
T_3 V_117 ;
T_4 V_103 ;
T_5 V_118 = 1 ;
T_1 V_119 = 0 ;
struct V_114 V_120 = { . V_117 = 39797 , . V_121 = 0 , } ;
while ( V_115 > ( 180 << 16 ) )
V_115 -= ( 360 << 16 ) ;
while ( V_115 < - ( 180 << 16 ) )
V_115 += ( 360 << 16 ) ;
if ( V_115 > ( 90 << 16 ) ) {
V_115 -= ( 180 << 16 ) ;
V_118 = - 1 ;
} else if ( V_115 < - ( 90 << 16 ) ) {
V_115 += ( 180 << 16 ) ;
V_118 = - 1 ;
}
for ( V_117 = 0 ; V_117 <= 17 ; V_117 ++ ) {
if ( V_115 > V_119 ) {
V_103 = V_120 . V_117 - ( V_120 . V_121 >> V_117 ) ;
V_120 . V_121 += V_120 . V_117 >> V_117 ;
V_120 . V_117 = V_103 ;
V_119 += V_116 [ V_117 ] ;
} else {
V_103 = V_120 . V_117 + ( V_120 . V_121 >> V_117 ) ;
V_120 . V_121 -= V_120 . V_117 >> V_117 ;
V_120 . V_117 = V_103 ;
V_119 -= V_116 [ V_117 ] ;
}
}
V_120 . V_117 *= V_118 ;
V_120 . V_121 *= V_118 ;
return V_120 ;
}
