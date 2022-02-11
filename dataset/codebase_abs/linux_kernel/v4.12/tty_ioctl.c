int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
return V_2 -> V_3 -> V_4 ( V_2 ) ;
else
return 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_5 )
return V_2 -> V_3 -> V_5 ( V_2 ) ;
return 2048 ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_6 )
V_2 -> V_3 -> V_6 ( V_2 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 ) ;
if ( ! F_6 ( V_8 , & V_2 -> V_9 ) &&
V_2 -> V_3 -> V_10 )
V_2 -> V_3 -> V_10 ( V_2 ) ;
V_2 -> V_11 = 0 ;
F_7 ( & V_2 -> V_7 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 ) ;
if ( F_9 ( V_8 , & V_2 -> V_9 ) &&
V_2 -> V_3 -> V_12 )
V_2 -> V_3 -> V_12 ( V_2 ) ;
V_2 -> V_11 = 0 ;
F_7 ( & V_2 -> V_7 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_11 ( & V_2 -> V_14 ) ;
if ( ! F_12 ( V_2 ) ) {
if ( V_2 -> V_11 != V_15 )
V_13 = 1 ;
else {
F_13 ( V_8 , & V_2 -> V_9 ) ;
if ( V_2 -> V_3 -> V_10 )
V_2 -> V_3 -> V_10 ( V_2 ) ;
}
}
F_14 ( & V_2 -> V_14 ) ;
return V_13 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_11 ( & V_2 -> V_14 ) ;
if ( F_12 ( V_2 ) ) {
if ( V_2 -> V_11 != V_16 )
V_13 = 1 ;
else {
F_16 ( V_8 , & V_2 -> V_9 ) ;
if ( V_2 -> V_3 -> V_12 )
V_2 -> V_3 -> V_12 ( V_2 ) ;
}
}
F_14 ( & V_2 -> V_14 ) ;
return V_13 ;
}
void F_17 ( struct V_1 * V_2 , long V_17 )
{
F_18 ( V_2 , L_1 , V_17 ) ;
if ( ! V_17 )
V_17 = V_18 ;
V_17 = F_19 ( V_2 -> V_19 ,
! F_1 ( V_2 ) , V_17 ) ;
if ( V_17 <= 0 )
return;
if ( V_17 == V_18 )
V_17 = 0 ;
if ( V_2 -> V_3 -> V_20 )
V_2 -> V_3 -> V_20 ( V_2 , V_17 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_21 * V_23 = & V_2 -> V_23 ;
struct V_21 * V_24 = & V_2 -> V_25 ;
int V_26 ;
#define F_21 ( T_1 , T_2 , T_3 ) (x = ((x) & ~(z)) | ((y) & (z)))
F_21 ( V_23 -> V_27 , V_22 -> V_27 , V_24 -> V_27 ) ;
F_21 ( V_23 -> V_28 , V_22 -> V_28 , V_24 -> V_28 ) ;
F_21 ( V_23 -> V_29 , V_22 -> V_29 , V_24 -> V_29 ) ;
F_21 ( V_23 -> V_30 , V_22 -> V_30 , V_24 -> V_30 ) ;
V_23 -> V_31 = V_24 -> V_31 ? V_22 -> V_31 : V_23 -> V_31 ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ )
V_23 -> V_33 [ V_26 ] = V_24 -> V_33 [ V_26 ] ?
V_22 -> V_33 [ V_26 ] : V_23 -> V_33 [ V_26 ] ;
}
void F_22 ( struct V_21 * V_34 , struct V_21 * V_22 )
{
V_34 -> V_29 &= V_35 | V_36 | V_37 ;
V_34 -> V_29 |= V_22 -> V_29 & ~ ( V_35 | V_36 | V_37 ) ;
V_34 -> V_38 = V_22 -> V_38 ;
V_34 -> V_39 = V_22 -> V_39 ;
}
int F_23 ( struct V_21 * V_40 , struct V_21 * V_41 )
{
if ( V_40 -> V_38 != V_41 -> V_38 || V_40 -> V_39 != V_41 -> V_39 )
return 1 ;
if ( ( V_40 -> V_29 ^ V_41 -> V_29 ) & ~ ( V_35 | V_36 | V_37 ) )
return 1 ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , struct V_21 * V_42 )
{
struct V_21 V_43 ;
struct V_44 * V_45 ;
F_25 ( V_2 -> V_46 -> type == V_47 &&
V_2 -> V_46 -> V_48 == V_49 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_43 = V_2 -> V_23 ;
V_2 -> V_23 = * V_42 ;
F_20 ( V_2 , & V_43 ) ;
if ( V_2 -> V_3 -> V_50 )
V_2 -> V_3 -> V_50 ( V_2 , & V_43 ) ;
else
F_22 ( & V_2 -> V_23 , & V_43 ) ;
V_45 = F_26 ( V_2 ) ;
if ( V_45 != NULL ) {
if ( V_45 -> V_3 -> V_50 )
V_45 -> V_3 -> V_50 ( V_2 , & V_43 ) ;
F_27 ( V_45 ) ;
}
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int V_50 ( struct V_1 * V_2 , void T_4 * V_51 , int V_52 )
{
struct V_21 V_53 ;
struct V_44 * V_45 ;
int V_54 = F_28 ( V_2 ) ;
if ( V_54 )
return V_54 ;
F_29 ( & V_2 -> V_7 ) ;
V_53 = V_2 -> V_23 ;
F_30 ( & V_2 -> V_7 ) ;
if ( V_52 & V_55 ) {
if ( F_31 ( & V_53 ,
(struct V_56 T_4 * ) V_51 ) )
return - V_57 ;
#ifdef F_32
} else if ( V_52 & V_58 ) {
if ( F_33 ( & V_53 ,
(struct V_23 T_4 * ) V_51 ) )
return - V_57 ;
} else {
if ( F_34 ( & V_53 ,
(struct V_59 T_4 * ) V_51 ) )
return - V_57 ;
}
#else
}
void F_35 ( struct V_1 * V_2 , struct V_21 * V_60 )
{
F_29 ( & V_2 -> V_7 ) ;
* V_60 = V_2 -> V_23 ;
F_30 ( & V_2 -> V_7 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_21 * V_60 )
{
F_29 ( & V_2 -> V_7 ) ;
* V_60 = V_2 -> V_25 ;
F_30 ( & V_2 -> V_7 ) ;
}
static int F_37 ( struct V_1 * V_2 , struct V_56 T_4 * V_56 )
{
struct V_21 V_60 ;
F_35 ( V_2 , & V_60 ) ;
if ( F_38 ( V_56 , & V_60 ) )
return - V_57 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , void T_4 * V_51 , int V_52 )
{
struct V_61 V_62 ;
struct V_44 * V_45 ;
if ( V_2 -> V_61 == NULL )
return - V_63 ;
if ( F_40 ( & V_62 , V_51 , sizeof( struct V_61 ) ) )
return - V_57 ;
V_45 = F_26 ( V_2 ) ;
if ( V_45 != NULL ) {
if ( ( V_52 & V_64 ) && V_45 -> V_3 -> V_6 )
V_45 -> V_3 -> V_6 ( V_2 ) ;
F_27 ( V_45 ) ;
}
if ( V_52 & V_65 ) {
F_17 ( V_2 , 0 ) ;
if ( F_41 ( V_66 ) )
return - V_67 ;
}
F_5 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 -> F_39 )
V_2 -> V_3 -> F_39 ( V_2 , & V_62 ) ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( ! F_43 ( V_2 ) ) {
if ( F_44 ( V_2 ) )
V_9 |= 0x02 ;
else
V_9 |= 0x20 ;
}
if ( F_45 ( V_2 ) )
V_9 |= 0x08 ;
if ( F_46 ( V_2 ) )
if ( F_47 ( V_2 ) )
V_9 |= 0x10 ;
return V_9 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_68 T_4 * V_68 )
{
struct V_68 V_69 ;
F_29 ( & V_2 -> V_7 ) ;
V_69 . V_70 = V_2 -> V_23 . V_38 ;
V_69 . V_71 = V_2 -> V_23 . V_39 ;
V_69 . V_72 = V_2 -> V_23 . V_33 [ V_73 ] ;
V_69 . V_74 = V_2 -> V_23 . V_33 [ V_75 ] ;
V_69 . V_76 = F_42 ( V_2 ) ;
F_30 ( & V_2 -> V_7 ) ;
return F_49 ( V_68 , & V_69 , sizeof( V_69 ) ) ? - V_57 : 0 ;
}
static void F_50 ( struct V_21 * V_23 , int V_9 )
{
V_23 -> V_27 = V_77 | V_78 ;
V_23 -> V_28 = 0 ;
V_23 -> V_30 = V_79 | V_80 ;
if ( V_9 & 0x02 ) {
V_23 -> V_27 = 0 ;
V_23 -> V_30 &= ~ V_80 ;
}
if ( V_9 & 0x08 ) {
V_23 -> V_30 |= V_81 | V_82 | V_83 |
V_84 | V_85 | V_86 ;
}
if ( V_9 & 0x10 ) {
V_23 -> V_28 |= V_87 | V_88 ;
}
if ( V_9 & 0x20 ) {
V_23 -> V_27 = 0 ;
V_23 -> V_30 &= ~ ( V_79 | V_80 ) ;
}
if ( ! ( V_23 -> V_30 & V_80 ) ) {
V_23 -> V_33 [ V_89 ] = 1 ;
V_23 -> V_33 [ V_90 ] = 0 ;
}
}
static int F_51 ( struct V_1 * V_2 , struct V_68 T_4 * V_68 )
{
int V_54 ;
struct V_68 V_69 ;
struct V_21 V_23 ;
V_54 = F_28 ( V_2 ) ;
if ( V_54 )
return V_54 ;
if ( F_40 ( & V_69 , V_68 , sizeof( V_69 ) ) )
return - V_57 ;
F_5 ( & V_2 -> V_7 ) ;
V_23 = V_2 -> V_23 ;
V_23 . V_33 [ V_73 ] = V_69 . V_72 ;
V_23 . V_33 [ V_75 ] = V_69 . V_74 ;
F_50 ( & V_23 , V_69 . V_76 ) ;
#ifdef F_52
F_53 ( & V_23 , V_23 . V_38 ,
V_23 . V_39 ) ;
#endif
F_7 ( & V_2 -> V_7 ) ;
F_24 ( V_2 , & V_23 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_91 T_4 * V_91 )
{
struct V_91 V_69 ;
F_29 ( & V_2 -> V_7 ) ;
V_69 . V_92 = V_2 -> V_23 . V_33 [ V_93 ] ;
V_69 . V_94 = V_2 -> V_23 . V_33 [ V_95 ] ;
V_69 . V_96 = V_2 -> V_23 . V_33 [ V_97 ] ;
V_69 . V_98 = V_2 -> V_23 . V_33 [ V_99 ] ;
V_69 . V_100 = V_2 -> V_23 . V_33 [ V_101 ] ;
V_69 . V_102 = V_2 -> V_23 . V_33 [ V_103 ] ;
F_30 ( & V_2 -> V_7 ) ;
return F_49 ( V_91 , & V_69 , sizeof( V_69 ) ) ? - V_57 : 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_91 T_4 * V_91 )
{
struct V_91 V_69 ;
if ( F_40 ( & V_69 , V_91 , sizeof( V_69 ) ) )
return - V_57 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_23 . V_33 [ V_93 ] = V_69 . V_92 ;
V_2 -> V_23 . V_33 [ V_95 ] = V_69 . V_94 ;
V_2 -> V_23 . V_33 [ V_97 ] = V_69 . V_96 ;
V_2 -> V_23 . V_33 [ V_99 ] = V_69 . V_98 ;
V_2 -> V_23 . V_33 [ V_101 ] = V_69 . V_100 ;
V_2 -> V_23 . V_33 [ V_103 ] = V_69 . V_102 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_104 T_4 * V_104 )
{
struct V_104 V_69 ;
F_29 ( & V_2 -> V_7 ) ;
V_69 . V_105 = V_2 -> V_23 . V_33 [ V_106 ] ;
V_69 . V_107 = V_2 -> V_23 . V_33 [ V_106 ] ;
V_69 . V_108 = V_2 -> V_23 . V_33 [ V_109 ] ;
V_69 . V_110 = V_2 -> V_23 . V_33 [ V_103 ] ;
V_69 . V_111 = V_2 -> V_23 . V_33 [ V_112 ] ;
V_69 . V_113 = V_2 -> V_23 . V_33 [ V_114 ] ;
F_30 ( & V_2 -> V_7 ) ;
return F_49 ( V_104 , & V_69 , sizeof( V_69 ) ) ? - V_57 : 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_104 T_4 * V_104 )
{
struct V_104 V_69 ;
if ( F_40 ( & V_69 , V_104 , sizeof( V_69 ) ) )
return - V_57 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_23 . V_33 [ V_106 ] = V_69 . V_105 ;
V_2 -> V_23 . V_33 [ V_103 ] = V_69 . V_107 ;
V_2 -> V_23 . V_33 [ V_109 ] = V_69 . V_108 ;
V_2 -> V_23 . V_33 [ V_103 ] = V_69 . V_110 ;
V_2 -> V_23 . V_33 [ V_112 ] = V_69 . V_111 ;
V_2 -> V_23 . V_33 [ V_114 ] = V_69 . V_113 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , int V_51 )
{
int V_13 = 0 ;
int V_115 = V_51 ? V_37 : 0 ;
struct V_21 V_22 ;
F_5 ( & V_2 -> V_7 ) ;
V_22 = V_2 -> V_23 ;
V_2 -> V_23 . V_29 &= ~ V_37 ;
V_2 -> V_23 . V_29 |= V_115 ;
if ( V_2 -> V_3 -> V_50 )
V_2 -> V_3 -> V_50 ( V_2 , & V_22 ) ;
if ( F_59 ( V_2 ) != V_115 )
V_13 = - V_63 ;
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
int F_60 ( struct V_1 * V_2 , struct V_116 * V_116 ,
unsigned int V_117 , unsigned long V_51 )
{
struct V_1 * V_118 ;
void T_4 * V_119 = ( void T_4 * ) V_51 ;
int V_13 = 0 ;
struct V_21 V_60 ;
F_61 ( V_116 == NULL ) ;
if ( V_2 -> V_46 -> type == V_47 &&
V_2 -> V_46 -> V_48 == V_49 )
V_118 = V_2 -> V_120 ;
else
V_118 = V_2 ;
switch ( V_117 ) {
#ifdef F_62
case F_62 :
return F_48 ( V_118 , (struct V_68 T_4 * ) V_51 ) ;
case V_121 :
case V_122 :
return F_51 ( V_118 , (struct V_68 T_4 * ) V_51 ) ;
#endif
#ifdef F_63
case F_63 :
return F_54 ( V_118 , V_119 ) ;
case V_123 :
return F_55 ( V_118 , V_119 ) ;
#endif
#ifdef F_64
case F_64 :
return F_56 ( V_118 , V_119 ) ;
case V_124 :
return F_57 ( V_118 , V_119 ) ;
#endif
case V_125 :
return V_50 ( V_118 , V_119 , V_64 | V_65 | V_58 ) ;
case V_126 :
return V_50 ( V_118 , V_119 , V_65 | V_58 ) ;
case V_127 :
return V_50 ( V_118 , V_119 , V_58 ) ;
#ifndef F_32
case V_128 :
F_35 ( V_118 , & V_60 ) ;
if ( F_65 ( (struct V_23 T_4 * ) V_51 , & V_60 ) )
V_13 = - V_57 ;
return V_13 ;
#else
case V_128 :
F_35 ( V_118 , & V_60 ) ;
if ( F_66 ( (struct V_23 T_4 * ) V_51 , & V_60 ) )
V_13 = - V_57 ;
return V_13 ;
case F_32 :
F_35 ( V_118 , & V_60 ) ;
if ( F_65 ( (struct V_59 T_4 * ) V_51 , & V_60 ) )
V_13 = - V_57 ;
return V_13 ;
case V_129 :
return V_50 ( V_118 , V_119 , V_64 | V_65 ) ;
case V_130 :
return V_50 ( V_118 , V_119 , V_65 ) ;
case V_131 :
return V_50 ( V_118 , V_119 , 0 ) ;
#endif
case V_132 :
return F_37 ( V_118 , V_119 ) ;
case V_133 :
return V_50 ( V_118 , V_119 , V_64 | V_65 | V_55 ) ;
case V_134 :
return V_50 ( V_118 , V_119 , V_65 | V_55 ) ;
case V_135 :
return V_50 ( V_118 , V_119 , V_55 ) ;
#ifndef F_32
case V_136 :
F_36 ( V_118 , & V_60 ) ;
if ( F_65 ( (struct V_23 T_4 * ) V_51 , & V_60 ) )
V_13 = - V_57 ;
return V_13 ;
case V_137 :
if ( ! F_67 ( V_138 ) )
return - V_139 ;
F_36 ( V_118 , & V_60 ) ;
if ( F_34 ( & V_60 ,
(struct V_23 T_4 * ) V_51 ) )
return - V_57 ;
F_5 ( & V_118 -> V_7 ) ;
V_118 -> V_25 = V_60 ;
F_7 ( & V_118 -> V_7 ) ;
return 0 ;
#else
case V_136 :
F_36 ( V_118 , & V_60 ) ;
if ( F_66 ( (struct V_23 T_4 * ) V_51 , & V_60 ) )
V_13 = - V_57 ;
return V_13 ;
case V_137 :
if ( ! F_67 ( V_138 ) )
return - V_139 ;
F_36 ( V_118 , & V_60 ) ;
if ( F_33 ( & V_60 ,
(struct V_23 T_4 * ) V_51 ) )
return - V_57 ;
F_5 ( & V_118 -> V_7 ) ;
V_118 -> V_25 = V_60 ;
F_7 ( & V_118 -> V_7 ) ;
return V_13 ;
#endif
#ifdef F_68
case F_68 : {
struct V_61 V_140 ;
if ( V_118 -> V_61 == NULL )
return - V_63 ;
F_29 ( & V_118 -> V_7 ) ;
memcpy ( & V_140 , V_118 -> V_61 , sizeof( struct V_61 ) ) ;
F_30 ( & V_118 -> V_7 ) ;
if ( F_49 ( V_119 , & V_140 , sizeof( struct V_61 ) ) )
V_13 = - V_57 ;
return V_13 ;
}
case V_141 :
return F_39 ( V_118 , V_119 , 0 ) ;
case V_142 :
return F_39 ( V_118 , V_119 , V_65 ) ;
case V_143 :
return F_39 ( V_118 , V_119 , V_64 ) ;
#endif
case V_144 :
F_35 ( V_118 , & V_60 ) ;
V_13 = F_69 ( ( V_60 . V_29 & V_37 ) ? 1 : 0 ,
( int T_4 * ) V_51 ) ;
return V_13 ;
case V_145 :
if ( F_70 ( V_51 , ( unsigned int T_4 * ) V_51 ) )
return - V_57 ;
return F_58 ( V_118 , V_51 ) ;
default:
return - V_146 ;
}
}
static int F_71 ( struct V_1 * V_2 , unsigned long V_51 )
{
struct V_44 * V_45 = V_2 -> V_147 ;
switch ( V_51 ) {
case V_148 :
if ( V_45 && V_45 -> V_3 -> V_6 ) {
V_45 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
break;
case V_149 :
if ( V_45 && V_45 -> V_3 -> V_6 ) {
V_45 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
case V_150 :
F_3 ( V_2 ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_2 , unsigned long V_51 )
{
struct V_44 * V_45 ;
int V_54 = F_28 ( V_2 ) ;
if ( V_54 )
return V_54 ;
V_45 = F_73 ( V_2 ) ;
V_54 = F_71 ( V_2 , V_51 ) ;
if ( V_45 )
F_27 ( V_45 ) ;
return V_54 ;
}
int F_74 ( struct V_1 * V_2 , struct V_116 * V_116 ,
unsigned int V_117 , unsigned long V_51 )
{
int V_54 ;
switch ( V_117 ) {
case V_151 :
V_54 = F_28 ( V_2 ) ;
if ( V_54 )
return V_54 ;
switch ( V_51 ) {
case V_152 :
F_75 ( & V_2 -> V_153 ) ;
if ( ! V_2 -> V_154 ) {
V_2 -> V_154 = 1 ;
F_76 ( V_2 ) ;
}
F_77 ( & V_2 -> V_153 ) ;
break;
case V_155 :
F_75 ( & V_2 -> V_153 ) ;
if ( V_2 -> V_154 ) {
V_2 -> V_154 = 0 ;
F_78 ( V_2 ) ;
}
F_77 ( & V_2 -> V_153 ) ;
break;
case V_156 :
if ( F_79 ( V_2 ) != V_157 )
V_54 = F_80 ( V_2 , F_79 ( V_2 ) ) ;
break;
case V_158 :
if ( F_81 ( V_2 ) != V_157 )
V_54 = F_80 ( V_2 , F_81 ( V_2 ) ) ;
break;
default:
return - V_63 ;
}
return V_54 ;
case V_159 :
V_54 = F_28 ( V_2 ) ;
if ( V_54 )
return V_54 ;
return F_71 ( V_2 , V_51 ) ;
default:
return F_60 ( V_2 , V_116 , V_117 , V_51 ) ;
}
}
long F_82 ( struct V_1 * V_2 , struct V_116 * V_116 ,
unsigned int V_117 , unsigned long V_51 )
{
switch ( V_117 ) {
case V_136 :
case V_137 :
return F_60 ( V_2 , V_116 , V_117 , ( unsigned long ) F_83 ( V_51 ) ) ;
default:
return - V_146 ;
}
}
