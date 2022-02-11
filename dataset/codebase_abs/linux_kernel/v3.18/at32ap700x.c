static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_2 [ V_1 -> V_3 ] ;
}
static unsigned long F_2 ( struct V_1 * V_1 , unsigned long V_4 )
{
unsigned long div , V_5 , V_6 ;
div = F_3 ( V_7 , V_4 ) + 1 ;
V_5 = F_3 ( V_8 , V_4 ) + 1 ;
V_6 = V_1 -> V_9 -> V_10 ( V_1 -> V_9 ) ;
V_6 = ( V_6 + div / 2 ) / div ;
V_6 *= V_5 ;
return V_6 ;
}
static long F_4 ( struct V_1 * V_1 , unsigned long V_6 ,
T_1 * V_11 )
{
unsigned long V_5 ;
unsigned long V_12 = 0 ;
unsigned long div ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_15 = 0 ;
unsigned long V_16 ;
unsigned long V_17 ;
unsigned long V_18 = 0 ;
unsigned long V_19 ;
unsigned long V_20 = ~ 0UL ;
T_1 V_21 ;
if ( V_6 < 80000000UL || V_6 > 200000000UL )
return - V_22 ;
V_21 = F_5 ( V_23 , 4 ) ;
V_16 = V_1 -> V_9 -> V_10 ( V_1 -> V_9 ) ;
V_13 = F_6 ( V_16 , 32000000UL ) ;
V_14 = V_16 / 6000000UL ;
if ( V_14 < V_13 )
return - V_22 ;
for ( div = V_13 ; div <= V_14 ; div ++ ) {
V_17 = ( V_16 + div / 2 ) / div ;
V_5 = ( V_6 + V_17 / 2 ) / V_17 ;
if ( V_5 == 0 )
continue;
V_18 = V_17 * V_5 ;
V_19 = abs ( V_18 - V_6 ) ;
if ( V_19 < V_20 ) {
V_12 = V_5 ;
V_15 = div ;
V_20 = V_19 ;
}
if ( V_19 == 0 )
break;
}
if ( V_15 == 0 )
return - V_22 ;
V_21 |= F_5 ( V_8 , V_12 - 1 ) ;
V_21 |= F_5 ( V_7 , V_15 - 1 ) ;
V_21 |= F_5 ( V_24 , 16 ) ;
if ( V_1 -> V_9 == & V_25 )
V_21 |= F_7 ( V_26 ) ;
* V_11 = V_21 ;
return V_18 ;
}
static unsigned long F_8 ( struct V_1 * V_1 )
{
T_1 V_4 ;
V_4 = F_9 ( V_27 ) ;
return F_2 ( V_1 , V_4 ) ;
}
static void F_10 ( struct V_1 * V_1 , int V_28 )
{
unsigned long V_29 ;
T_1 V_30 ;
T_1 V_21 ;
V_21 = F_9 ( V_31 ) ;
if ( V_28 ) {
if ( ! F_3 ( V_8 , V_21 ) && ! F_3 ( V_7 , V_21 ) ) {
F_11 ( L_1 ,
V_1 -> V_32 ) ;
return;
}
V_21 |= F_7 ( V_33 ) ;
F_12 ( V_31 , V_21 ) ;
for ( V_29 = 10000 ; V_29 ; V_29 -- ) {
V_30 = F_9 ( V_34 ) ;
if ( V_30 & F_7 ( V_35 ) )
break;
F_13 ( 10 ) ;
}
if ( ! ( V_30 & F_7 ( V_35 ) ) )
F_14 ( V_36 L_2 ,
V_1 -> V_32 ) ;
} else {
V_21 &= ~ F_7 ( V_33 ) ;
F_12 ( V_31 , V_21 ) ;
}
}
static unsigned long F_15 ( struct V_1 * V_1 )
{
T_1 V_4 ;
V_4 = F_9 ( V_31 ) ;
return F_2 ( V_1 , V_4 ) ;
}
static long F_16 ( struct V_1 * V_1 , unsigned long V_6 , int V_37 )
{
T_1 V_21 = 0 ;
unsigned long V_38 ;
V_38 = F_4 ( V_1 , V_6 , & V_21 ) ;
if ( V_37 ) {
if ( V_38 != V_6 )
return - V_22 ;
if ( V_1 -> V_39 > 0 )
return - V_40 ;
F_11 ( V_41 L_3 ,
V_1 -> V_32 , V_6 , V_38 ) ;
F_12 ( V_31 , V_21 ) ;
}
return V_38 ;
}
static int F_17 ( struct V_1 * V_1 , struct V_1 * V_9 )
{
T_1 V_21 ;
if ( V_1 -> V_39 > 0 )
return - V_40 ;
V_21 = F_9 ( V_31 ) ;
F_18 ( V_21 & F_7 ( V_33 ) ) ;
if ( V_9 == & V_42 )
V_21 &= ~ F_7 ( V_26 ) ;
else if ( V_9 == & V_25 )
V_21 |= F_7 ( V_26 ) ;
else
return - V_22 ;
F_12 ( V_31 , V_21 ) ;
V_1 -> V_9 = V_9 ;
return 0 ;
}
static unsigned long F_19 ( struct V_1 * V_1 , unsigned int V_43 )
{
return V_44 -> V_10 ( V_44 ) >> V_43 ;
}
static void F_20 ( struct V_1 * V_1 , int V_28 )
{
unsigned long V_45 ;
T_1 V_46 ;
F_21 ( & V_47 , V_45 ) ;
V_46 = F_9 ( V_48 ) ;
if ( V_28 )
V_46 |= 1 << V_1 -> V_3 ;
else
V_46 &= ~ ( 1 << V_1 -> V_3 ) ;
F_12 ( V_48 , V_46 ) ;
F_22 ( & V_47 , V_45 ) ;
}
static unsigned long F_23 ( struct V_1 * V_1 )
{
unsigned long V_49 , V_43 = 0 ;
V_49 = F_9 ( V_50 ) ;
if ( V_49 & F_7 ( V_51 ) )
V_43 = F_3 ( V_52 , V_49 ) + 1 ;
return F_19 ( V_1 , V_43 ) ;
}
static long F_24 ( struct V_1 * V_1 , unsigned long V_6 , int V_37 )
{
T_1 V_4 ;
unsigned long V_53 , V_54 , V_38 , div ;
V_53 = V_1 -> V_9 -> V_10 ( V_1 -> V_9 ) ;
V_4 = F_9 ( V_50 ) ;
if ( V_4 & F_7 ( V_55 ) )
V_54 = 1 << ( F_3 ( V_56 , V_4 ) + 1 ) ;
else
V_54 = 1 ;
if ( V_6 > 3 * ( V_53 / 4 ) || V_54 == 1 ) {
V_38 = V_53 ;
V_4 &= ~ F_7 ( V_51 ) ;
} else {
unsigned int V_57 ;
div = ( V_53 + V_6 / 2 ) / V_6 ;
if ( div > V_54 )
div = V_54 ;
V_57 = ( div > 1 ) ? ( F_25 ( div ) - 2 ) : 0 ;
V_4 = F_7 ( V_51 ) | F_26 ( V_52 , V_57 , V_4 ) ;
V_38 = V_53 / ( 1 << ( V_57 + 1 ) ) ;
}
F_11 ( L_3 ,
V_1 -> V_32 , V_6 , V_38 ) ;
if ( V_37 )
F_12 ( V_50 , V_4 ) ;
return V_38 ;
}
static void F_27 ( struct V_1 * V_1 , int V_28 )
{
unsigned long V_45 ;
T_1 V_46 ;
F_21 ( & V_47 , V_45 ) ;
V_46 = F_9 ( V_58 ) ;
if ( V_28 )
V_46 |= 1 << V_1 -> V_3 ;
else
V_46 &= ~ ( 1 << V_1 -> V_3 ) ;
F_12 ( V_58 , V_46 ) ;
F_22 ( & V_47 , V_45 ) ;
}
static unsigned long F_28 ( struct V_1 * V_1 )
{
unsigned long V_49 , V_43 = 0 ;
V_49 = F_9 ( V_50 ) ;
if ( V_49 & F_7 ( V_55 ) )
V_43 = F_3 ( V_56 , V_49 ) + 1 ;
return F_19 ( V_1 , V_43 ) ;
}
void F_29 ( struct V_1 * V_1 , int V_28 )
{
unsigned long V_45 ;
T_1 V_46 ;
F_21 ( & V_47 , V_45 ) ;
V_46 = F_9 ( V_59 ) ;
if ( V_28 )
V_46 |= 1 << V_1 -> V_3 ;
else
V_46 &= ~ ( 1 << V_1 -> V_3 ) ;
F_12 ( V_59 , V_46 ) ;
F_22 ( & V_47 , V_45 ) ;
}
unsigned long F_30 ( struct V_1 * V_1 )
{
unsigned long V_49 , V_43 = 0 ;
V_49 = F_9 ( V_50 ) ;
if ( V_49 & F_7 ( V_60 ) )
V_43 = F_3 ( V_61 , V_49 ) + 1 ;
return F_19 ( V_1 , V_43 ) ;
}
static void F_31 ( struct V_1 * V_1 , int V_28 )
{
unsigned long V_45 ;
T_1 V_46 ;
F_21 ( & V_47 , V_45 ) ;
V_46 = F_9 ( V_62 ) ;
if ( V_28 )
V_46 |= 1 << V_1 -> V_3 ;
else
V_46 &= ~ ( 1 << V_1 -> V_3 ) ;
F_12 ( V_62 , V_46 ) ;
F_22 ( & V_47 , V_45 ) ;
}
static unsigned long F_32 ( struct V_1 * V_1 )
{
unsigned long V_49 , V_43 = 0 ;
V_49 = F_9 ( V_50 ) ;
if ( V_49 & F_7 ( V_63 ) )
V_43 = F_3 ( V_64 , V_49 ) + 1 ;
return F_19 ( V_1 , V_43 ) ;
}
static void F_33 ( struct V_1 * V_1 , int V_28 )
{
T_1 V_4 ;
V_4 = F_9 ( F_34 ( V_1 -> V_3 ) ) ;
if ( V_28 )
V_4 |= F_7 ( V_65 ) ;
else
V_4 &= ~ F_7 ( V_65 ) ;
F_12 ( F_34 ( V_1 -> V_3 ) , V_4 ) ;
}
static unsigned long F_35 ( struct V_1 * V_1 )
{
T_1 V_4 ;
unsigned long div = 1 ;
V_4 = F_9 ( F_34 ( V_1 -> V_3 ) ) ;
if ( V_4 & F_7 ( V_66 ) )
div = 2 * ( F_3 ( DIV , V_4 ) + 1 ) ;
return V_1 -> V_9 -> V_10 ( V_1 -> V_9 ) / div ;
}
static long F_36 ( struct V_1 * V_1 , unsigned long V_6 , int V_37 )
{
T_1 V_4 ;
unsigned long V_53 , V_38 , div ;
V_53 = V_1 -> V_9 -> V_10 ( V_1 -> V_9 ) ;
V_4 = F_9 ( F_34 ( V_1 -> V_3 ) ) ;
if ( V_6 > 3 * V_53 / 4 ) {
V_38 = V_53 ;
V_4 &= ~ F_7 ( V_66 ) ;
} else {
div = ( V_53 + V_6 ) / ( 2 * V_6 ) - 1 ;
V_4 = F_26 ( DIV , div , V_4 ) | F_7 ( V_66 ) ;
V_38 = V_53 / ( 2 * ( div + 1 ) ) ;
}
F_37 ( V_1 -> V_67 , L_3 ,
V_1 -> V_32 , V_6 , V_38 ) ;
if ( V_37 )
F_12 ( F_34 ( V_1 -> V_3 ) , V_4 ) ;
return V_38 ;
}
int F_38 ( struct V_1 * V_1 , struct V_1 * V_9 )
{
T_1 V_4 ;
F_37 ( V_1 -> V_67 , L_4 ,
V_1 -> V_32 , V_9 -> V_32 , V_1 -> V_9 -> V_32 ) ;
V_4 = F_9 ( F_34 ( V_1 -> V_3 ) ) ;
if ( V_9 == & V_25 || V_9 == & V_68 )
V_4 |= F_7 ( V_69 ) ;
else if ( V_9 == & V_42 || V_9 == & V_70 )
V_4 &= ~ F_7 ( V_69 ) ;
else
return - V_22 ;
if ( V_9 == & V_70 || V_9 == & V_68 )
V_4 |= F_7 ( V_71 ) ;
else
V_4 &= ~ F_7 ( V_71 ) ;
F_12 ( F_34 ( V_1 -> V_3 ) , V_4 ) ;
V_1 -> V_9 = V_9 ;
return 0 ;
}
static void T_2 F_39 ( struct V_1 * V_1 )
{
T_1 V_4 ;
struct V_1 * V_9 ;
F_40 ( V_1 -> V_3 > 7 ) ;
V_4 = F_9 ( F_34 ( V_1 -> V_3 ) ) ;
if ( V_4 & F_7 ( V_69 ) )
V_9 = ( V_4 & F_7 ( V_71 ) ) ? & V_68 : & V_25 ;
else
V_9 = ( V_4 & F_7 ( V_71 ) ) ? & V_70 : & V_42 ;
V_1 -> V_9 = V_9 ;
}
static inline void F_41 ( T_1 V_46 )
{
F_42 ( V_72 , V_46 ) ;
}
static int T_2 F_43 ( void )
{
F_44 ( & V_73 ) ;
F_44 ( & V_74 ) ;
F_44 ( & V_75 ) ;
F_44 ( & V_76 ) ;
F_44 ( & V_77 ) ;
F_44 ( & V_78 ) ;
F_44 ( & V_79 ) ;
F_44 ( & V_80 ) ;
F_44 ( & V_81 ) ;
F_44 ( & V_82 ) ;
F_44 ( & V_83 ) ;
F_44 ( & V_84 ) ;
F_44 ( & V_85 ) ;
F_44 ( & V_86 ) ;
F_44 ( & V_87 ) ;
return 0 ;
}
struct V_88 * T_2 F_45 ( unsigned int V_89 )
{
struct V_88 * V_90 ;
T_1 V_91 ;
if ( ! ( V_89 == 0 || V_89 == 1 ) )
return NULL ;
V_90 = F_46 ( L_5 , V_89 ) ;
if ( ! V_90 )
return NULL ;
switch ( V_89 ) {
case 0 :
V_91 = ( 1 << 8 ) | ( 1 << 9 ) ;
if ( F_47 ( V_90 , V_92 ,
F_48 ( V_92 ) ) )
goto V_93;
V_94 . V_67 = & V_90 -> V_67 ;
F_49 ( V_95 , V_91 , V_96 , 0 ) ;
break;
case 1 :
V_91 = ( 1 << 11 ) | ( 1 << 12 ) ;
if ( F_47 ( V_90 , V_97 ,
F_48 ( V_97 ) ) )
goto V_93;
V_98 . V_67 = & V_90 -> V_67 ;
F_49 ( V_99 , V_91 , V_96 , 0 ) ;
break;
default:
return NULL ;
}
F_50 ( V_90 ) ;
return V_90 ;
V_93:
F_51 ( V_90 ) ;
return NULL ;
}
static inline void F_52 ( int V_45 )
{
T_1 V_91 = ( 1 << 8 ) | ( 1 << 9 ) ;
if ( V_45 & V_100 ) V_91 |= ( 1 << 6 ) ;
if ( V_45 & V_101 ) V_91 |= ( 1 << 7 ) ;
if ( V_45 & V_102 ) V_91 |= ( 1 << 10 ) ;
F_49 ( V_95 , V_91 , V_103 , V_104 ) ;
}
static inline void F_53 ( int V_45 )
{
T_1 V_91 = ( 1 << 17 ) | ( 1 << 18 ) ;
if ( V_45 & V_100 ) V_91 |= ( 1 << 19 ) ;
if ( V_45 & V_101 ) V_91 |= ( 1 << 20 ) ;
if ( V_45 & V_102 ) V_91 |= ( 1 << 16 ) ;
F_49 ( V_95 , V_91 , V_96 , V_104 ) ;
}
static inline void F_54 ( int V_45 )
{
T_1 V_91 = ( 1 << 26 ) | ( 1 << 27 ) ;
if ( V_45 & V_100 ) V_91 |= ( 1 << 30 ) ;
if ( V_45 & V_101 ) V_91 |= ( 1 << 29 ) ;
if ( V_45 & V_102 ) V_91 |= ( 1 << 28 ) ;
F_49 ( V_99 , V_91 , V_103 , V_104 ) ;
}
static inline void F_55 ( int V_45 )
{
T_1 V_91 = ( 1 << 18 ) | ( 1 << 17 ) ;
if ( V_45 & V_100 ) V_91 |= ( 1 << 16 ) ;
if ( V_45 & V_101 ) V_91 |= ( 1 << 15 ) ;
if ( V_45 & V_102 ) V_91 |= ( 1 << 19 ) ;
F_49 ( V_99 , V_91 , V_103 , V_104 ) ;
}
void T_2 F_56 ( unsigned int V_105 , unsigned int line , int V_45 )
{
struct V_88 * V_90 ;
struct V_106 * V_107 ;
switch ( V_105 ) {
case 0 :
V_90 = & V_108 ;
F_52 ( V_45 ) ;
break;
case 1 :
V_90 = & V_109 ;
F_53 ( V_45 ) ;
break;
case 2 :
V_90 = & V_110 ;
F_54 ( V_45 ) ;
break;
case 3 :
V_90 = & V_111 ;
F_55 ( V_45 ) ;
break;
default:
return;
}
if ( F_57 ( V_90 -> V_112 [ 0 ] . V_113 ) == V_114 ) {
struct V_106 * V_115 = V_90 -> V_67 . V_116 ;
V_115 -> V_117 = ( void V_118 * ) V_90 -> V_112 [ 0 ] . V_113 ;
}
V_90 -> V_89 = line ;
V_107 = V_90 -> V_67 . V_116 ;
V_107 -> V_119 = line ;
V_120 [ line ] = V_90 ;
}
struct V_88 * T_2 F_58 ( unsigned int V_89 )
{
F_44 ( V_120 [ V_89 ] ) ;
return V_120 [ V_89 ] ;
}
void T_2 F_59 ( unsigned int V_121 )
{
#ifdef F_60
V_122 = V_120 [ V_121 ] ;
#endif
}
struct V_88 * T_2
F_61 ( unsigned int V_89 , struct V_123 * V_115 )
{
struct V_88 * V_90 ;
T_1 V_91 ;
switch ( V_89 ) {
case 0 :
V_90 = & V_124 ;
V_91 = ( 1 << 3 ) ;
V_91 |= ( 1 << 4 ) ;
V_91 |= ( 1 << 7 ) ;
V_91 |= ( 1 << 8 ) ;
V_91 |= ( 1 << 9 ) ;
V_91 |= ( 1 << 10 ) ;
V_91 |= ( 1 << 13 ) ;
V_91 |= ( 1 << 15 ) ;
V_91 |= ( 1 << 16 ) ;
V_91 |= ( 1 << 17 ) ;
if ( ! V_115 -> V_125 ) {
V_91 |= ( 1 << 0 ) ;
V_91 |= ( 1 << 1 ) ;
V_91 |= ( 1 << 2 ) ;
V_91 |= ( 1 << 5 ) ;
V_91 |= ( 1 << 6 ) ;
V_91 |= ( 1 << 11 ) ;
V_91 |= ( 1 << 12 ) ;
V_91 |= ( 1 << 14 ) ;
#ifndef F_62
V_91 |= ( 1 << 18 ) ;
#endif
}
F_49 ( V_126 , V_91 , V_96 , 0 ) ;
break;
case 1 :
V_90 = & V_127 ;
V_91 = ( 1 << 13 ) ;
V_91 |= ( 1 << 14 ) ;
V_91 |= ( 1 << 11 ) ;
V_91 |= ( 1 << 12 ) ;
V_91 |= ( 1 << 10 ) ;
V_91 |= ( 1 << 6 ) ;
V_91 |= ( 1 << 5 ) ;
V_91 |= ( 1 << 4 ) ;
V_91 |= ( 1 << 3 ) ;
V_91 |= ( 1 << 2 ) ;
#ifndef F_62
if ( ! V_115 -> V_125 )
V_91 |= ( 1 << 15 ) ;
#endif
F_49 ( V_128 , V_91 , V_103 , 0 ) ;
if ( ! V_115 -> V_125 ) {
V_91 = ( 1 << 19 ) ;
V_91 |= ( 1 << 23 ) ;
V_91 |= ( 1 << 26 ) ;
V_91 |= ( 1 << 27 ) ;
V_91 |= ( 1 << 28 ) ;
V_91 |= ( 1 << 29 ) ;
V_91 |= ( 1 << 30 ) ;
V_91 |= ( 1 << 24 ) ;
F_49 ( V_126 , V_91 , V_103 , 0 ) ;
}
break;
default:
return NULL ;
}
memcpy ( V_90 -> V_67 . V_116 , V_115 , sizeof( struct V_123 ) ) ;
F_44 ( V_90 ) ;
return V_90 ;
}
void T_2
F_63 ( unsigned int V_129 , struct V_130 * V_131 , unsigned int V_132 )
{
static T_3 T_4 V_133 [] [ 4 ] = {
{ F_64 ( 3 ) , F_64 ( 4 ) ,
F_64 ( 5 ) , F_64 ( 20 ) } ,
{ F_65 ( 2 ) , F_65 ( 3 ) ,
F_65 ( 4 ) , F_64 ( 27 ) } ,
} ;
unsigned int V_134 , V_135 ;
if ( V_129 > 1 )
return;
for (; V_132 ; V_132 -- , V_131 ++ ) {
V_131 -> V_129 = V_129 ;
if ( V_131 -> V_136 >= 4 )
continue;
V_134 = ( unsigned ) V_131 -> V_137 ;
if ( ! V_134 ) {
V_134 = V_133 [ V_129 ] [ V_131 -> V_136 ] ;
V_131 -> V_137 = ( void * ) V_134 ;
}
V_135 = V_138 ;
if ( ! ( V_131 -> V_135 & V_139 ) )
V_135 |= V_140 ;
F_66 ( V_134 , V_135 ) ;
}
}
struct V_88 * T_2
F_67 ( unsigned int V_89 , struct V_130 * V_131 , unsigned int V_132 )
{
struct V_88 * V_90 ;
T_1 V_91 ;
switch ( V_89 ) {
case 0 :
V_90 = & V_141 ;
V_91 = ( 1 << 1 ) | ( 1 << 2 ) ;
F_49 ( V_95 , ( 1 << 0 ) , V_96 , V_104 ) ;
F_49 ( V_95 , V_91 , V_96 , 0 ) ;
F_63 ( 0 , V_131 , V_132 ) ;
break;
case 1 :
V_90 = & V_142 ;
V_91 = ( 1 << 1 ) | ( 1 << 5 ) ;
F_49 ( V_99 , ( 1 << 0 ) , V_103 , V_104 ) ;
F_49 ( V_99 , V_91 , V_103 , 0 ) ;
F_63 ( 1 , V_131 , V_132 ) ;
break;
default:
return NULL ;
}
F_68 ( V_131 , V_132 ) ;
F_44 ( V_90 ) ;
return V_90 ;
}
struct V_88 * T_2 F_69 ( unsigned int V_89 ,
struct V_143 * V_131 ,
unsigned int V_132 )
{
struct V_88 * V_90 ;
T_1 V_91 ;
if ( V_89 != 0 )
return NULL ;
V_90 = F_46 ( L_6 , V_89 ) ;
if ( ! V_90 )
return NULL ;
if ( F_47 ( V_90 , V_144 ,
F_48 ( V_144 ) ) )
goto V_93;
V_91 = ( 1 << 6 ) | ( 1 << 7 ) ;
F_49 ( V_95 , V_91 , V_96 , 0 ) ;
V_145 . V_67 = & V_90 -> V_67 ;
if ( V_131 )
F_70 ( V_89 , V_131 , V_132 ) ;
F_50 ( V_90 ) ;
return V_90 ;
V_93:
F_51 ( V_90 ) ;
return NULL ;
}
struct V_88 * T_2
F_71 ( unsigned int V_89 , struct V_146 * V_115 )
{
struct V_88 * V_90 ;
struct V_147 * V_148 ;
T_1 V_149 ;
T_1 V_150 ;
if ( V_89 != 0 || ! V_115 )
return NULL ;
if ( ! V_115 -> V_151 [ 0 ] . V_152 && ! V_115 -> V_151 [ 1 ] . V_152 )
return NULL ;
V_90 = F_46 ( L_7 , V_89 ) ;
if ( ! V_90 )
goto V_153;
if ( F_47 ( V_90 , V_154 ,
F_48 ( V_154 ) ) )
goto V_153;
V_148 = F_72 ( sizeof( struct V_147 ) , V_155 ) ;
if ( ! V_148 )
goto V_153;
V_148 -> V_156 . V_157 = & V_80 . V_67 ;
V_148 -> V_156 . V_158 = 0 ;
V_148 -> V_156 . V_159 = 1 ;
V_148 -> V_156 . V_160 = 1 ;
V_148 -> V_156 . V_161 = 0 ;
V_115 -> V_162 = V_148 ;
if ( F_73 ( V_90 , V_115 ,
sizeof( struct V_146 ) ) )
goto V_163;
V_149 = 1 << 10 ;
switch ( V_115 -> V_151 [ 0 ] . V_152 ) {
case 4 :
V_149 |= 1 << 13 ;
V_149 |= 1 << 14 ;
V_149 |= 1 << 15 ;
case 1 :
V_149 |= 1 << 11 ;
V_149 |= 1 << 12 ;
if ( F_74 ( V_115 -> V_151 [ 0 ] . V_164 ) )
F_66 ( V_115 -> V_151 [ 0 ] . V_164 , 0 ) ;
if ( F_74 ( V_115 -> V_151 [ 0 ] . V_165 ) )
F_66 ( V_115 -> V_151 [ 0 ] . V_165 , 0 ) ;
break;
case 0 :
break;
default:
goto V_163;
}
F_49 ( V_95 , V_149 , V_96 , 0 ) ;
V_150 = 0 ;
switch ( V_115 -> V_151 [ 1 ] . V_152 ) {
case 4 :
V_150 |= 1 << 8 ;
V_150 |= 1 << 9 ;
V_150 |= 1 << 10 ;
case 1 :
V_150 |= 1 << 6 ;
V_150 |= 1 << 7 ;
F_49 ( V_99 , V_150 , V_103 , 0 ) ;
if ( F_74 ( V_115 -> V_151 [ 1 ] . V_164 ) )
F_66 ( V_115 -> V_151 [ 1 ] . V_164 , 0 ) ;
if ( F_74 ( V_115 -> V_151 [ 1 ] . V_165 ) )
F_66 ( V_115 -> V_151 [ 1 ] . V_165 , 0 ) ;
break;
case 0 :
break;
default:
if ( ! V_115 -> V_151 [ 0 ] . V_152 )
goto V_163;
V_115 -> V_151 [ 1 ] . V_152 = 0 ;
break;
}
V_166 . V_67 = & V_90 -> V_67 ;
F_50 ( V_90 ) ;
return V_90 ;
V_163:
F_75 ( V_148 ) ;
V_153:
V_115 -> V_162 = NULL ;
F_51 ( V_90 ) ;
return NULL ;
}
struct V_88 * T_2
F_76 ( unsigned int V_89 , struct V_167 * V_115 ,
unsigned long V_168 , unsigned long V_169 ,
T_5 V_91 )
{
struct V_88 * V_90 ;
struct V_167 * V_170 ;
struct V_171 * V_172 ;
struct V_173 * V_174 ;
unsigned int V_175 ;
T_1 V_176 , V_177 , V_178 ;
V_172 = F_77 ( V_115 -> V_179 ,
sizeof( struct V_171 ) , V_155 ) ;
if ( ! V_172 )
return NULL ;
V_175 = sizeof( struct V_173 ) * V_172 -> V_180 ;
V_174 = F_77 ( V_172 -> V_174 , V_175 , V_155 ) ;
if ( ! V_174 )
goto V_181;
V_172 -> V_174 = V_174 ;
switch ( V_89 ) {
case 0 :
V_90 = & V_182 ;
if ( V_91 == 0ULL )
V_91 = V_183 | V_184 ;
V_176 = V_91 & 0xfff80000 ;
F_49 ( V_126 , V_176 , V_96 , 0 ) ;
V_177 = V_91 & 0x0003ffff ;
F_49 ( V_128 , V_177 , V_96 , 0 ) ;
V_178 = ( V_91 >> 32 ) & 0x0007ffff ;
F_49 ( V_185 , V_178 , V_103 , 0 ) ;
F_78 ( & V_186 , & V_70 ) ;
F_79 ( & V_186 , F_80 ( & V_70 ) ) ;
break;
default:
goto V_187;
}
if ( V_169 ) {
V_90 -> V_112 [ 2 ] . V_113 = V_168 ;
V_90 -> V_112 [ 2 ] . V_188 = V_168 + V_169 - 1 ;
V_90 -> V_112 [ 2 ] . V_45 = V_189 ;
}
V_170 = V_90 -> V_67 . V_116 ;
memcpy ( V_170 , V_115 , sizeof( struct V_167 ) ) ;
V_170 -> V_179 = V_172 ;
V_90 -> V_32 = L_8 ;
F_44 ( V_90 ) ;
return V_90 ;
V_187:
F_75 ( V_174 ) ;
V_181:
F_75 ( V_172 ) ;
return NULL ;
}
struct V_88 * T_2 F_81 ( T_1 V_46 )
{
struct V_88 * V_90 ;
T_1 V_91 ;
if ( ! V_46 )
return NULL ;
V_90 = F_46 ( L_9 , 0 ) ;
if ( ! V_90 )
return NULL ;
if ( F_47 ( V_90 , V_190 ,
F_48 ( V_190 ) ) )
goto V_191;
V_91 = 0 ;
if ( V_46 & ( 1 << 0 ) )
V_91 |= ( 1 << 28 ) ;
if ( V_46 & ( 1 << 1 ) )
V_91 |= ( 1 << 29 ) ;
if ( V_91 > 0 )
F_49 ( V_95 , V_91 , V_96 , 0 ) ;
V_91 = 0 ;
if ( V_46 & ( 1 << 2 ) )
V_91 |= ( 1 << 21 ) ;
if ( V_46 & ( 1 << 3 ) )
V_91 |= ( 1 << 22 ) ;
if ( V_91 > 0 )
F_49 ( V_95 , V_91 , V_103 , 0 ) ;
V_192 . V_67 = & V_90 -> V_67 ;
F_50 ( V_90 ) ;
return V_90 ;
V_191:
F_51 ( V_90 ) ;
return NULL ;
}
struct V_88 * T_2
F_82 ( unsigned int V_89 , unsigned int V_45 )
{
struct V_88 * V_90 ;
T_1 V_91 = 0 ;
switch ( V_89 ) {
case 0 :
V_90 = & V_193 ;
if ( V_45 & V_194 )
V_91 |= ( 1 << 21 ) ;
if ( V_45 & V_195 )
V_91 |= ( 1 << 22 ) ;
if ( V_45 & V_196 )
V_91 |= ( 1 << 23 ) ;
if ( V_45 & V_197 )
V_91 |= ( 1 << 24 ) ;
if ( V_45 & V_198 )
V_91 |= ( 1 << 25 ) ;
if ( V_45 & V_199 )
V_91 |= ( 1 << 26 ) ;
if ( V_91 > 0 )
F_49 ( V_95 , V_91 , V_96 , 0 ) ;
break;
case 1 :
V_90 = & V_200 ;
if ( V_45 & V_194 )
V_91 |= ( 1 << 0 ) ;
if ( V_45 & V_195 )
V_91 |= ( 1 << 1 ) ;
if ( V_45 & V_196 )
V_91 |= ( 1 << 2 ) ;
if ( V_45 & V_197 )
V_91 |= ( 1 << 3 ) ;
if ( V_45 & V_198 )
V_91 |= ( 1 << 4 ) ;
if ( V_45 & V_199 )
V_91 |= ( 1 << 5 ) ;
if ( V_91 > 0 )
F_49 ( V_95 , V_91 , V_103 , 0 ) ;
break;
case 2 :
V_90 = & V_201 ;
if ( V_45 & V_198 )
V_91 |= ( 1 << 13 ) ;
if ( V_45 & V_199 )
V_91 |= ( 1 << 14 ) ;
if ( V_45 & V_196 )
V_91 |= ( 1 << 15 ) ;
if ( V_45 & V_197 )
V_91 |= ( 1 << 16 ) ;
if ( V_45 & V_194 )
V_91 |= ( 1 << 17 ) ;
if ( V_45 & V_195 )
V_91 |= ( 1 << 18 ) ;
if ( V_91 > 0 )
F_49 ( V_99 , V_91 , V_96 , 0 ) ;
break;
default:
return NULL ;
}
F_44 ( V_90 ) ;
return V_90 ;
}
struct V_88 * T_2
F_83 ( unsigned int V_89 , struct V_202 * V_115 )
{
struct {
struct V_202 V_107 ;
struct V_203 V_204 [ 7 ] ;
} V_205 ;
struct V_88 * V_90 ;
if ( V_89 != 0 )
return NULL ;
V_90 = F_46 ( L_10 , 0 ) ;
if ( ! V_90 )
return NULL ;
if ( F_47 ( V_90 , V_206 ,
F_48 ( V_206 ) ) )
goto V_191;
if ( V_115 ) {
V_205 . V_107 . V_207 = V_115 -> V_207 ;
V_205 . V_107 . V_208 = V_115 -> V_208 ;
} else {
V_205 . V_107 . V_207 = - V_22 ;
V_205 . V_107 . V_208 = - V_22 ;
}
V_115 = & V_205 . V_107 ;
V_115 -> V_209 = F_48 ( V_210 ) ;
memcpy ( V_115 -> V_204 , V_210 , sizeof( V_210 ) ) ;
if ( F_73 ( V_90 , V_115 , sizeof( V_205 ) ) )
goto V_191;
if ( F_74 ( V_115 -> V_207 ) )
F_66 ( V_115 -> V_207 , 0 ) ;
V_211 . V_67 = & V_90 -> V_67 ;
V_212 . V_67 = & V_90 -> V_67 ;
F_50 ( V_90 ) ;
return V_90 ;
V_191:
F_51 ( V_90 ) ;
return NULL ;
}
static int T_2 F_84 ( struct V_88 * V_90 ,
unsigned int V_213 , unsigned int V_214 )
{
static unsigned int V_215 [ 4 ] T_4 = {
( 1 << 25 ) ,
( 1 << 26 ) ,
( 1 << 27 ) ,
( 1 << 28 ) ,
} ;
static bool T_6 T_4 = false ;
unsigned int V_216 ;
int V_217 ;
T_1 V_91 ;
if ( V_214 >= F_48 ( V_215 ) )
return - V_22 ;
V_216 = V_215 [ V_214 ] ;
switch ( V_213 ) {
case 4 :
V_217 = F_47 ( V_90 ,
V_218 ,
F_48 ( V_218 ) ) ;
if ( V_217 )
return V_217 ;
F_49 ( V_185 , ( 1 << 21 ) , V_96 , 0 ) ;
F_42 ( V_72 , V_219 ) ;
break;
case 5 :
V_217 = F_47 ( V_90 ,
V_220 ,
F_48 ( V_220 ) ) ;
if ( V_217 )
return V_217 ;
F_49 ( V_185 , ( 1 << 22 ) , V_96 , 0 ) ;
F_42 ( V_72 , V_221 ) ;
break;
default:
return - V_22 ;
}
if ( ! T_6 ) {
V_91 = ( 1 << 19 ) ;
V_91 |= ( 1 << 20 ) ;
V_91 |= ( 1 << 23 ) ;
V_91 |= ( 1 << 24 ) ;
F_49 ( V_185 , V_91 , V_96 , 0 ) ;
T_6 = true ;
}
F_49 ( V_99 , V_216 , V_96 , V_222 ) ;
V_90 -> V_112 [ 1 ] . V_113 = V_223 + V_214 ;
V_90 -> V_112 [ 1 ] . V_188 = V_90 -> V_112 [ 1 ] . V_113 ;
return 0 ;
}
struct V_88 * T_2
F_85 ( unsigned int V_89 , unsigned int V_214 ,
struct V_224 * V_115 )
{
struct V_88 * V_90 ;
V_90 = F_46 ( L_11 , V_89 ) ;
if ( ! V_90 )
goto V_153;
if ( F_73 ( V_90 , V_115 ,
sizeof( struct V_224 ) ) )
goto V_153;
if ( F_84 ( V_90 , V_115 -> V_213 , V_214 ) )
goto V_153;
F_50 ( V_90 ) ;
return V_90 ;
V_153:
F_51 ( V_90 ) ;
return NULL ;
}
struct V_88 * T_2
F_86 ( unsigned int V_89 , unsigned int V_214 ,
struct V_225 * V_115 )
{
struct V_88 * V_90 ;
V_90 = F_46 ( L_12 , V_89 ) ;
if ( ! V_90 )
goto V_153;
if ( F_73 ( V_90 , V_115 ,
sizeof( struct V_225 ) ) )
goto V_153;
if ( F_84 ( V_90 , V_115 -> V_213 , V_214 ) )
goto V_153;
if ( F_74 ( V_115 -> V_164 ) )
F_66 ( V_115 -> V_164 , V_222 ) ;
if ( F_74 ( V_115 -> V_226 ) )
F_66 ( V_115 -> V_226 , 0 ) ;
if ( F_74 ( V_115 -> V_227 ) )
F_66 ( V_115 -> V_227 , 0 ) ;
F_50 ( V_90 ) ;
return V_90 ;
V_153:
F_51 ( V_90 ) ;
return NULL ;
}
struct V_88 * T_2
F_87 ( unsigned int V_89 , struct V_228 * V_115 )
{
struct V_88 * V_90 ;
if ( V_89 != 0 || ! V_115 )
return NULL ;
V_90 = F_46 ( L_13 , V_89 ) ;
if ( ! V_90 )
goto V_153;
if ( F_47 ( V_90 , V_229 ,
F_48 ( V_229 ) ) )
goto V_153;
V_115 -> V_230 = true ;
if ( F_73 ( V_90 , V_115 ,
sizeof( struct V_228 ) ) )
goto V_153;
F_42 ( V_72 , V_231 ) ;
if ( V_115 -> V_232 )
F_66 ( V_115 -> V_232 ,
V_138 | V_140 ) ;
if ( V_115 -> V_233 )
F_66 ( V_115 -> V_233 , 0 ) ;
if ( V_115 -> V_234 )
F_66 ( V_115 -> V_234 , 0 ) ;
F_50 ( V_90 ) ;
return V_90 ;
V_153:
F_51 ( V_90 ) ;
return NULL ;
}
struct V_88 * T_2
F_88 ( unsigned int V_89 , struct V_235 * V_115 ,
unsigned int V_45 )
{
struct V_88 * V_90 ;
struct V_236 * V_237 ;
struct V_236 * V_238 ;
struct V_235 V_239 ;
T_1 V_91 ;
if ( V_89 != 0 )
return NULL ;
V_90 = F_46 ( L_14 , V_89 ) ;
if ( ! V_90 )
return NULL ;
if ( F_47 ( V_90 , V_240 ,
F_48 ( V_240 ) ) )
goto V_241;
if ( ! V_115 ) {
V_115 = & V_239 ;
memset ( V_115 , 0 , sizeof( struct V_235 ) ) ;
V_115 -> V_226 = - V_242 ;
}
V_237 = & V_115 -> V_237 ;
V_238 = & V_115 -> V_238 ;
if ( V_45 & V_243 ) {
V_237 -> V_157 = & V_80 . V_67 ;
V_237 -> V_158 = 3 ;
V_237 -> V_160 = 0 ;
V_237 -> V_161 = 1 ;
}
if ( V_45 & V_244 ) {
V_238 -> V_157 = & V_80 . V_67 ;
V_238 -> V_159 = 4 ;
V_238 -> V_160 = 0 ;
V_238 -> V_161 = 1 ;
}
if ( F_73 ( V_90 , V_115 ,
sizeof( struct V_235 ) ) )
goto V_241;
V_91 = ( 1 << 20 ) | ( 1 << 21 ) | ( 1 << 22 ) | ( 1 << 23 ) ;
F_49 ( V_99 , V_91 , V_103 , 0 ) ;
if ( F_74 ( V_115 -> V_226 ) )
F_66 ( V_115 -> V_226 , V_138
| V_140 ) ;
V_245 . V_67 = & V_90 -> V_67 ;
F_50 ( V_90 ) ;
return V_90 ;
V_241:
F_51 ( V_90 ) ;
return NULL ;
}
struct V_88 * T_2
F_89 ( unsigned int V_89 , struct V_246 * V_115 )
{
struct V_88 * V_90 ;
struct V_236 * V_247 ;
T_1 V_91 ;
if ( V_89 != 0 || ! V_115 )
return NULL ;
V_90 = F_46 ( L_15 , V_89 ) ;
if ( ! V_90 )
return NULL ;
if ( F_47 ( V_90 , V_248 ,
F_48 ( V_248 ) ) )
goto V_241;
V_247 = & V_115 -> V_247 ;
V_247 -> V_157 = & V_80 . V_67 ;
V_247 -> V_159 = 2 ;
V_247 -> V_160 = 0 ;
V_247 -> V_161 = 1 ;
if ( F_73 ( V_90 , V_115 ,
sizeof( struct V_246 ) ) )
goto V_241;
V_91 = ( 1 << 20 ) | ( 1 << 22 ) ;
V_91 |= ( 1 << 21 ) | ( 1 << 23 ) ;
F_49 ( V_99 , V_91 , V_96 , 0 ) ;
V_249 . V_67 = & V_90 -> V_67 ;
V_250 . V_67 = & V_90 -> V_67 ;
F_50 ( V_90 ) ;
return V_90 ;
V_241:
F_51 ( V_90 ) ;
return NULL ;
}
void T_2 F_90 ( void )
{
T_1 V_251 = 0 , V_252 = 0 , V_253 = 0 , V_254 = 0 ;
int V_255 ;
if ( F_9 ( V_256 ) & F_7 ( V_71 ) ) {
V_44 = & V_70 ;
V_257 . V_9 = & V_70 ;
} else {
V_44 = & V_42 ;
V_257 . V_9 = & V_42 ;
}
if ( F_9 ( V_27 ) & F_7 ( V_26 ) )
V_70 . V_9 = & V_25 ;
if ( F_9 ( V_31 ) & F_7 ( V_26 ) )
V_68 . V_9 = & V_25 ;
F_39 ( & V_258 ) ;
F_39 ( & V_259 ) ;
F_39 ( & V_260 ) ;
F_39 ( & V_261 ) ;
F_39 ( & V_262 ) ;
#if F_91 ( V_263 ) || F_91 ( V_264 )
F_39 ( & V_186 ) ;
#endif
F_39 ( & V_250 ) ;
for ( V_255 = 0 ; V_255 < F_48 ( V_265 ) ; V_255 ++ ) {
struct V_1 * V_1 = V_265 [ V_255 ] ;
F_92 ( V_1 ) ;
if ( V_1 -> V_39 == 0 )
continue;
if ( V_1 -> V_135 == & F_20 )
V_251 |= 1 << V_1 -> V_3 ;
else if ( V_1 -> V_135 == & F_27 )
V_252 |= 1 << V_1 -> V_3 ;
else if ( V_1 -> V_135 == & F_29 )
V_253 |= 1 << V_1 -> V_3 ;
else if ( V_1 -> V_135 == & F_31 )
V_254 |= 1 << V_1 -> V_3 ;
}
F_12 ( V_48 , V_251 ) ;
F_12 ( V_58 , V_252 ) ;
F_12 ( V_59 , V_253 ) ;
F_12 ( V_62 , V_254 ) ;
F_93 ( & V_83 ) ;
F_93 ( & V_84 ) ;
F_93 ( & V_85 ) ;
F_93 ( & V_86 ) ;
F_93 ( & V_87 ) ;
}
static int T_2 F_94 ( void )
{
struct V_266 * V_267 ;
V_267 = F_95 ( 10 , - 1 ) ;
if ( ! V_267 )
goto V_153;
if ( F_96 ( V_267 , 0x24000000 , 0x8000 , - 1 ) )
goto V_268;
V_269 = V_267 ;
return 0 ;
V_268:
F_97 ( V_267 ) ;
V_153:
F_98 ( L_16 ) ;
return - V_270 ;
}
