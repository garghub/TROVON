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
}
if ( F_4 ( ! V_4 -> V_6 ) )
return - V_15 ;
V_5 = V_4 -> V_6 -> V_16 ( V_2 ) ;
if ( V_5 )
V_4 -> V_6 = NULL ;
return V_5 ;
}
void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_4 . V_6 -> free ( V_2 ) ;
V_2 -> V_4 . V_6 = NULL ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
const struct V_17 * V_6 = V_4 -> V_6 ;
int V_5 ;
V_4 -> V_18 = V_6 -> V_19 ( V_2 ) ;
V_6 -> V_20 ( V_2 , false ) ;
V_5 = V_6 -> V_21 ( V_2 ) ;
if ( V_5 ) {
F_7 ( V_2 -> V_22 , L_1 ) ;
goto V_23;
}
V_5 = F_8 ( V_2 , V_6 -> V_19 ( V_2 ) ) ;
if ( V_5 ) {
F_7 ( V_2 -> V_22 , L_2 ) ;
goto V_24;
}
return 0 ;
V_24:
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
V_23:
V_6 -> V_20 ( V_2 , true ) ;
return V_5 ;
}
void F_9 ( struct V_1 * V_2 )
{
const struct V_17 * V_6 = V_2 -> V_4 . V_6 ;
V_6 -> V_20 ( V_2 , true ) ;
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
}
bool F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_25 )
return 0 ;
if ( ! V_2 -> V_4 . V_6 -> V_26 )
return 0 ;
return V_2 -> V_4 . V_6 -> V_26 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_27 ;
#if V_28
F_4 ( V_2 -> V_4 . V_29 ) ;
V_2 -> V_4 . V_29 = 1 ;
#endif
V_27 = F_12 ( V_2 , V_30 ) ;
V_27 |= V_31 ;
F_13 ( V_2 , V_30 , V_27 ) ;
F_12 ( V_2 , V_30 ) ;
F_14 ( 10 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
T_1 V_27 ;
#if V_28
F_4 ( ! V_2 -> V_4 . V_29 ) ;
V_2 -> V_4 . V_29 = 0 ;
#endif
F_16 ( V_2 , V_32 ) ;
V_27 = F_12 ( V_2 , V_30 ) ;
V_27 &= ~ V_31 ;
F_13 ( V_2 , V_30 , V_27 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
#if V_28
F_4 ( V_2 -> V_4 . V_33 ) ;
V_2 -> V_4 . V_33 = 1 ;
#endif
F_4 ( V_2 -> V_34 -> V_35 . V_36 < 3 ) ;
if ( ! F_18 ( V_2 -> V_22 , V_37 ) )
F_19 ( V_2 , V_38 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
#if V_28
F_4 ( ! V_2 -> V_4 . V_33 ) ;
V_2 -> V_4 . V_33 = 0 ;
#endif
F_4 ( V_2 -> V_34 -> V_35 . V_36 < 3 ) ;
if ( ! F_18 ( V_2 -> V_22 , V_37 ) )
F_19 ( V_2 , 0 ) ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
if ( ! V_28 )
return;
if ( ( F_22 ( V_2 ) >= V_39 ) &&
( V_2 -> V_40 <= 0 ) ) {
F_23 ( V_2 -> V_22 , L_3
L_4 ) ;
F_24 () ;
}
}
T_2 F_25 ( struct V_1 * V_2 , T_2 V_41 )
{
F_21 ( V_2 ) ;
return V_2 -> V_4 . V_6 -> V_42 ( V_2 , V_41 ) ;
}
void F_26 ( struct V_1 * V_2 , T_2 V_41 , T_2 V_43 )
{
F_21 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_44 ( V_2 , V_41 , V_43 ) ;
}
void F_27 ( struct V_1 * V_2 , T_2 V_45 , T_2 V_46 )
{
F_28 ( V_2 , V_45 ,
F_29 ( V_2 , V_45 ) & V_46 ) ;
}
void F_30 ( struct V_1 * V_2 , T_2 V_45 , T_2 V_47 )
{
F_28 ( V_2 , V_45 ,
F_29 ( V_2 , V_45 ) | V_47 ) ;
}
void F_31 ( struct V_1 * V_2 , T_2 V_45 , T_2 V_46 , T_2 V_47 )
{
F_28 ( V_2 , V_45 ,
( F_29 ( V_2 , V_45 ) & V_46 ) | V_47 ) ;
}
T_2 F_32 ( struct V_1 * V_2 , T_2 V_41 )
{
F_21 ( V_2 ) ;
V_2 -> V_4 . V_48 = 0 ;
return V_2 -> V_4 . V_6 -> V_49 ( V_2 , V_41 ) ;
}
void F_33 ( struct V_1 * V_2 , T_2 V_41 , T_2 V_43 )
{
F_21 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_50 ( V_2 , V_41 , V_43 ) ;
if ( ++ V_2 -> V_4 . V_48 == V_51 ) {
F_16 ( V_2 , V_32 ) ;
V_2 -> V_4 . V_48 = 0 ;
}
}
void F_34 ( struct V_1 * V_2 , T_2 V_52 , T_2 V_53 )
{
F_21 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_50 ( V_2 , V_52 ,
V_2 -> V_4 . V_6 -> V_49 ( V_2 , V_53 ) ) ;
}
void F_35 ( struct V_1 * V_2 , T_2 V_45 , T_2 V_46 )
{
if ( V_2 -> V_4 . V_6 -> V_54 ) {
F_21 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_54 ( V_2 , V_45 , V_46 , 0 ) ;
} else {
F_33 ( V_2 , V_45 ,
F_32 ( V_2 , V_45 ) & V_46 ) ;
}
}
void F_36 ( struct V_1 * V_2 , T_2 V_45 , T_2 V_47 )
{
if ( V_2 -> V_4 . V_6 -> V_54 ) {
F_21 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_54 ( V_2 , V_45 , 0xFFFF , V_47 ) ;
} else {
F_33 ( V_2 , V_45 ,
F_32 ( V_2 , V_45 ) | V_47 ) ;
}
}
void F_37 ( struct V_1 * V_2 , T_2 V_45 , T_2 V_46 , T_2 V_47 )
{
if ( V_2 -> V_4 . V_6 -> V_54 ) {
F_21 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_54 ( V_2 , V_45 , V_46 , V_47 ) ;
} else {
F_33 ( V_2 , V_45 ,
( F_32 ( V_2 , V_45 ) & V_46 ) | V_47 ) ;
}
}
int F_8 ( struct V_1 * V_2 , unsigned int V_55 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
T_2 V_56 , V_57 ;
int V_5 ;
if ( V_55 == V_58 )
V_55 = V_4 -> V_6 -> V_19 ( V_2 ) ;
V_56 = V_55 ;
if ( F_38 ( V_2 -> V_22 ) == V_59 )
V_56 |= V_60 ;
if ( 0 )
V_56 |= V_61 ;
V_57 = F_39 ( V_2 , V_62 , V_63 ) ;
F_40 ( V_2 , V_62 , V_63 , V_56 ) ;
V_5 = V_4 -> V_6 -> V_64 ( V_2 , V_55 ) ;
if ( V_5 )
goto V_65;
V_2 -> V_4 . V_18 = V_55 ;
F_41 ( 8 ) ;
return 0 ;
V_65:
F_40 ( V_2 , V_62 ,
V_63 , V_57 ) ;
return V_5 ;
}
void F_42 ( struct V_1 * V_2 , bool V_66 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_43 ( V_2 ) ;
V_4 -> V_6 -> V_20 ( V_2 , V_66 ) ;
V_4 -> V_67 = ! V_66 ;
F_44 ( V_2 ) ;
}
void F_45 ( struct V_68 * V_69 )
{
struct V_70 * V_22 = F_46 ( V_69 , struct V_70 ,
V_71 ) ;
struct V_1 * V_2 ;
F_47 ( & V_22 -> V_72 ) ;
V_2 = V_22 -> V_73 ;
if ( F_48 ( V_2 && ( F_22 ( V_2 ) >= V_74 ) ) )
V_2 -> V_4 . V_6 -> V_75 ( V_2 ) ;
F_49 ( & V_22 -> V_72 ) ;
}
void F_50 ( struct V_1 * V_2 , unsigned int V_76 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_77 = V_78 ;
enum V_79 V_80 ;
if ( ! ( V_76 & V_81 ) ) {
if ( F_51 ( V_77 , V_4 -> V_82 ) )
return;
}
V_4 -> V_82 = F_52 ( V_77 + ( V_83 * 2 ) ) ;
if ( ( V_2 -> V_34 -> V_84 -> V_85 . V_86 == V_87 ) &&
( V_2 -> V_34 -> V_84 -> V_85 . type == V_88 ) )
return;
V_80 = V_4 -> V_6 -> V_89 ( V_2 , ! ! ( V_76 & V_90 ) ) ;
if ( V_80 == V_91 )
return;
F_4 ( V_80 != V_92 ) ;
F_4 ( V_4 -> V_6 -> V_75 == NULL ) ;
F_53 ( V_2 -> V_22 -> V_93 , & V_2 -> V_22 -> V_71 ) ;
}
int F_54 ( struct V_1 * V_2 , T_2 V_94 )
{
const bool V_95 = ( V_94 != V_96 ) ;
unsigned int V_97 , V_98 , V_99 , V_100 ;
unsigned int V_101 ;
T_1 V_102 ;
V_102 = F_55 ( V_2 , V_62 , V_94 ) ;
V_97 = V_102 & 0xFF ;
V_98 = ( V_102 >> 8 ) & 0xFF ;
V_99 = ( V_102 >> 16 ) & 0xFF ;
V_100 = ( V_102 >> 24 ) & 0xFF ;
if ( V_97 == 0 || V_97 == V_103 ||
V_98 == 0 || V_98 == V_103 ||
V_99 == 0 || V_99 == V_103 ||
V_100 == 0 || V_100 == V_103 )
return - V_104 ;
V_102 = V_103 | ( V_103 << 8 ) |
( V_103 << 16 ) | ( V_103 << 24 ) ;
F_56 ( V_2 , V_62 , V_94 , V_102 ) ;
if ( V_95 ) {
V_97 = ( V_97 + 32 ) & 0x3F ;
V_98 = ( V_98 + 32 ) & 0x3F ;
V_99 = ( V_99 + 32 ) & 0x3F ;
V_100 = ( V_100 + 32 ) & 0x3F ;
}
V_101 = ( V_97 + V_98 + V_99 + V_100 + 2 ) / 4 ;
if ( V_95 ) {
if ( F_39 ( V_2 , V_62 , V_105 )
& V_106 )
V_101 = ( V_101 >= 13 ) ? ( V_101 - 13 ) : 0 ;
}
return V_101 ;
}
void F_57 ( struct V_1 * V_2 , bool V_107 )
{
F_58 ( V_2 , V_108 , V_107 ? 0 : 0xF4 ) ;
}
bool F_59 ( enum V_109 V_110 )
{
return ( V_110 == V_111 ||
V_110 == V_112 ) ;
}
struct V_113 F_60 ( int V_114 )
{
static const T_1 V_115 [] = {
2949120 , 1740967 , 919879 , 466945 , 234379 , 117304 ,
58666 , 29335 , 14668 , 7334 , 3667 , 1833 ,
917 , 458 , 229 , 115 , 57 , 29 ,
} ;
T_3 V_116 ;
T_4 V_102 ;
T_5 V_117 = 1 ;
T_1 V_118 = 0 ;
struct V_113 V_119 = { . V_116 = 39797 , . V_120 = 0 , } ;
while ( V_114 > ( 180 << 16 ) )
V_114 -= ( 360 << 16 ) ;
while ( V_114 < - ( 180 << 16 ) )
V_114 += ( 360 << 16 ) ;
if ( V_114 > ( 90 << 16 ) ) {
V_114 -= ( 180 << 16 ) ;
V_117 = - 1 ;
} else if ( V_114 < - ( 90 << 16 ) ) {
V_114 += ( 180 << 16 ) ;
V_117 = - 1 ;
}
for ( V_116 = 0 ; V_116 <= 17 ; V_116 ++ ) {
if ( V_114 > V_118 ) {
V_102 = V_119 . V_116 - ( V_119 . V_120 >> V_116 ) ;
V_119 . V_120 += V_119 . V_116 >> V_116 ;
V_119 . V_116 = V_102 ;
V_118 += V_115 [ V_116 ] ;
} else {
V_102 = V_119 . V_116 + ( V_119 . V_120 >> V_116 ) ;
V_119 . V_120 -= V_119 . V_116 >> V_116 ;
V_119 . V_116 = V_102 ;
V_118 -= V_115 [ V_116 ] ;
}
}
V_119 . V_116 *= V_117 ;
V_119 . V_120 *= V_117 ;
return V_119 ;
}
