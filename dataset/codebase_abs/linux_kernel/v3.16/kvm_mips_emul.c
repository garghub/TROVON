unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned int V_4 ;
union V_5 V_6 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
long V_9 = V_3 ;
long V_10 = V_11 ;
if ( V_9 & 3 )
goto V_12;
V_6 . V_13 = F_2 ( ( V_14 * ) V_9 , V_2 ) ;
if ( V_6 . V_13 == V_11 )
return V_11 ;
switch ( V_6 . V_15 . V_16 ) {
case V_17 :
switch ( V_6 . V_18 . V_19 ) {
case V_20 :
V_8 -> V_21 [ V_6 . V_18 . V_22 ] = V_9 + 8 ;
case V_23 :
V_10 = V_8 -> V_21 [ V_6 . V_18 . V_24 ] ;
break;
}
break;
case V_25 :
switch ( V_6 . V_15 . V_26 ) {
case V_27 :
case V_28 :
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] < 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_30 :
case V_31 :
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] >= 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_32 :
case V_33 :
V_8 -> V_21 [ 31 ] = V_9 + 8 ;
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] < 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_34 :
case V_35 :
V_8 -> V_21 [ 31 ] = V_9 + 8 ;
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] >= 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_36 :
if ( ! V_37 )
goto V_38;
V_4 = F_3 ( 0x01 ) ;
if ( V_4 >= 32 ) {
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
} else
V_9 += 8 ;
V_10 = V_9 ;
break;
}
break;
case V_39 :
V_8 -> V_21 [ 31 ] = V_3 + 8 ;
case V_40 :
V_9 += 4 ;
V_9 >>= 28 ;
V_9 <<= 28 ;
V_9 |= ( V_6 . V_41 . V_42 << 2 ) ;
V_10 = V_9 ;
break;
case V_43 :
case V_44 :
if ( V_8 -> V_21 [ V_6 . V_15 . V_24 ] ==
V_8 -> V_21 [ V_6 . V_15 . V_26 ] )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_45 :
case V_46 :
if ( V_8 -> V_21 [ V_6 . V_15 . V_24 ] !=
V_8 -> V_21 [ V_6 . V_15 . V_26 ] )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_47 :
case V_48 :
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] <= 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_49 :
case V_50 :
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] > 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_51 :
F_4 ( L_1 , V_52 ) ;
break;
}
return V_10 ;
V_12:
F_4 ( L_2 , V_52 ) ;
return V_10 ;
V_38:
F_4 ( L_3 , V_52 ) ;
return V_10 ;
}
enum V_53 F_5 ( struct V_1 * V_2 , V_14 V_54 )
{
unsigned long V_55 ;
enum V_53 V_56 = V_57 ;
if ( V_54 & V_58 ) {
V_55 = F_1 ( V_2 , V_2 -> V_8 . V_59 ) ;
if ( V_55 == V_11 ) {
V_56 = V_60 ;
} else {
V_2 -> V_8 . V_59 = V_55 ;
F_6 ( L_4 , V_2 -> V_8 . V_59 ) ;
}
} else
V_2 -> V_8 . V_59 += 4 ;
F_6 ( L_5 , V_2 -> V_8 . V_59 ) ;
return V_56 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
return ( V_2 -> V_8 . V_63 & V_64 ) ||
( F_8 ( V_62 ) & V_65 ) ;
}
static V_14 F_9 ( struct V_1 * V_2 , T_1 V_66 )
{
T_2 V_67 , V_68 ;
T_3 V_69 ;
V_67 = F_10 ( V_66 ) ;
V_69 = V_67 + V_2 -> V_8 . V_70 ;
if ( V_69 >= V_2 -> V_8 . V_71 ) {
V_68 = F_11 ( V_67 , V_2 -> V_8 . V_71 ) ;
V_2 -> V_8 . V_70 = - V_68 * V_2 -> V_8 . V_71 ;
V_69 = V_67 + V_2 -> V_8 . V_70 ;
}
return F_12 ( V_69 * V_2 -> V_8 . V_72 , V_73 ) ;
}
static inline T_1 F_13 ( struct V_1 * V_2 )
{
if ( F_14 ( V_2 -> V_8 . V_63 & V_64 ) )
return V_2 -> V_8 . V_74 ;
return F_15 () ;
}
static V_14 F_16 ( struct V_1 * V_2 , T_1 V_66 )
{
T_1 V_75 ;
int V_76 ;
V_75 = F_17 ( & V_2 -> V_8 . V_77 ) ;
if ( F_18 ( V_66 , V_75 ) >= 0 ) {
V_76 = F_19 ( & V_2 -> V_8 . V_77 ) ;
V_78 -> V_79 ( V_2 ) ;
if ( V_76 ) {
V_75 = F_20 ( V_75 ,
V_2 -> V_8 . V_71 ) ;
F_21 ( & V_2 -> V_8 . V_77 , V_75 ,
V_80 ) ;
}
}
return V_2 -> V_8 . V_81 + F_9 ( V_2 , V_66 ) ;
}
V_14 F_22 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
if ( F_7 ( V_2 ) )
return F_23 ( V_62 ) ;
return F_16 ( V_2 , F_15 () ) ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
V_14 * V_82 )
{
T_1 V_66 ;
F_19 ( & V_2 -> V_8 . V_77 ) ;
V_66 = F_15 () ;
* V_82 = F_16 ( V_2 , V_66 ) ;
return V_66 ;
}
static void F_25 ( struct V_1 * V_2 ,
T_1 V_66 , V_14 V_82 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
V_14 V_83 ;
T_3 V_69 ;
T_1 V_84 ;
V_83 = F_26 ( V_62 ) ;
V_69 = ( T_3 ) ( V_14 ) ( V_83 - V_82 - 1 ) + 1 ;
V_69 = F_12 ( V_69 * V_73 , V_2 -> V_8 . V_72 ) ;
V_84 = F_20 ( V_66 , V_69 ) ;
F_19 ( & V_2 -> V_8 . V_77 ) ;
F_21 ( & V_2 -> V_8 . V_77 , V_84 , V_80 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_66 ;
V_14 V_82 ;
V_66 = F_24 ( V_2 , & V_82 ) ;
F_25 ( V_2 , V_66 , V_82 ) ;
}
void F_28 ( struct V_1 * V_2 , V_14 V_82 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
T_1 V_66 ;
V_66 = F_13 ( V_2 ) ;
V_2 -> V_8 . V_81 = V_82 - F_9 ( V_2 , V_66 ) ;
if ( F_7 ( V_2 ) )
F_29 ( V_62 , V_82 ) ;
else
F_25 ( V_2 , V_66 , V_82 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_72 = 100 * 1000 * 1000 ;
V_2 -> V_8 . V_71 = F_12 ( ( T_3 ) V_73 << 32 ,
V_2 -> V_8 . V_72 ) ;
V_2 -> V_8 . V_70 = 0 ;
F_28 ( V_2 , 0 ) ;
}
int F_31 ( struct V_1 * V_2 , T_2 V_72 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
int V_85 ;
T_1 V_66 ;
T_4 V_82 ;
if ( V_72 <= 0 || V_72 > V_73 )
return - V_86 ;
if ( V_2 -> V_8 . V_72 == V_72 )
return 0 ;
V_85 = F_7 ( V_2 ) ;
if ( V_85 ) {
V_66 = F_13 ( V_2 ) ;
V_82 = F_23 ( V_62 ) ;
} else {
V_66 = F_24 ( V_2 , & V_82 ) ;
}
V_2 -> V_8 . V_72 = V_72 ;
V_2 -> V_8 . V_71 = F_12 ( ( T_3 ) V_73 << 32 , V_72 ) ;
V_2 -> V_8 . V_70 = 0 ;
V_2 -> V_8 . V_81 = V_82 - F_9 ( V_2 , V_66 ) ;
if ( ! V_85 )
F_25 ( V_2 , V_66 , V_82 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 , V_14 V_83 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
if ( F_26 ( V_62 ) == V_83 )
return;
F_33 ( V_62 , V_83 ) ;
if ( ! F_7 ( V_2 ) )
F_27 ( V_2 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
V_14 V_82 ;
T_1 V_66 ;
F_19 ( & V_2 -> V_8 . V_77 ) ;
V_66 = F_15 () ;
V_82 = F_16 ( V_2 , V_66 ) ;
F_29 ( V_62 , V_82 ) ;
return V_66 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
F_36 ( V_62 , V_65 ) ;
if ( ! ( V_2 -> V_8 . V_63 & V_64 ) )
F_34 ( V_2 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
V_14 V_82 ;
F_38 ( V_62 , V_65 ) ;
V_82 = F_23 ( V_62 ) ;
F_28 ( V_2 , V_82 ) ;
}
int F_39 ( struct V_1 * V_2 , T_2 V_63 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
T_2 V_87 = V_63 ^ V_2 -> V_8 . V_63 ;
T_2 V_69 ;
T_1 V_84 , V_66 ;
V_14 V_82 , V_83 ;
if ( V_87 & ~ ( T_2 ) ( V_64 ) )
return - V_86 ;
V_2 -> V_8 . V_63 = V_63 ;
if ( V_87 & V_64 ) {
if ( F_8 ( V_62 ) & V_65 ) {
if ( V_63 & V_64 )
V_2 -> V_8 . V_74 = F_15 () ;
} else if ( V_63 & V_64 ) {
V_2 -> V_8 . V_74 = F_34 ( V_2 ) ;
} else {
V_82 = F_23 ( V_62 ) ;
V_83 = F_26 ( V_62 ) ;
V_69 = ( T_3 ) ( V_14 ) ( V_83 - V_82 - 1 ) + 1 ;
V_69 = F_12 ( V_69 * V_73 ,
V_2 -> V_8 . V_72 ) ;
V_84 = F_20 ( V_2 -> V_8 . V_74 , V_69 ) ;
V_66 = F_15 () ;
if ( F_18 ( V_66 , V_84 ) >= 0 )
V_78 -> V_79 ( V_2 ) ;
V_82 = F_16 ( V_2 , V_66 ) ;
F_25 ( V_2 , V_66 , V_82 ) ;
}
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 , T_2 V_74 )
{
if ( V_74 < 0 || V_74 > F_10 ( F_15 () ) )
return - V_86 ;
V_2 -> V_8 . V_74 = F_41 ( V_74 ) ;
return 0 ;
}
enum V_88 F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_8 . V_77 ,
V_2 -> V_8 . V_71 ) ;
return V_89 ;
}
enum V_53 F_44 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_57 ;
if ( F_45 ( V_62 ) & V_90 ) {
F_6 ( L_6 , V_2 -> V_8 . V_59 ,
F_46 ( V_62 ) ) ;
F_47 ( V_62 , V_90 ) ;
V_2 -> V_8 . V_59 = F_46 ( V_62 ) ;
} else if ( F_45 ( V_62 ) & V_91 ) {
F_47 ( V_62 , V_91 ) ;
V_2 -> V_8 . V_59 = F_48 ( V_62 ) ;
} else {
F_4 ( L_7 ,
V_2 -> V_8 . V_59 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53 F_49 ( struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
F_6 ( L_8 , V_2 -> V_8 . V_59 ,
V_2 -> V_8 . V_92 ) ;
++ V_2 -> V_93 . V_94 ;
F_50 ( V_2 , V_95 ) ;
if ( ! V_2 -> V_8 . V_92 ) {
V_2 -> V_8 . V_96 = 1 ;
F_51 ( V_2 ) ;
if ( F_52 ( V_97 , V_2 ) ) {
F_53 ( V_97 , & V_2 -> V_98 ) ;
V_2 -> V_99 -> V_100 = V_101 ;
}
}
return V_56 ;
}
enum V_53 F_54 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_60 ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
F_4 ( L_9 , V_59 , F_55 ( V_62 ) ) ;
return V_56 ;
}
enum V_53 F_56 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
int V_102 = F_55 ( V_62 ) ;
enum V_53 V_56 = V_57 ;
struct V_103 * V_104 = NULL ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
if ( V_102 < 0 || V_102 >= V_105 ) {
F_4 ( L_10 , V_52 , V_102 ) ;
F_4
( L_11 ,
V_59 , V_102 , F_57 ( V_62 ) ,
F_58 ( V_62 ) ,
F_59 ( V_62 ) ,
F_60 ( V_62 ) ) ;
V_102 = ( V_102 & ~ 0x80000000 ) % V_105 ;
}
V_104 = & V_2 -> V_8 . V_106 [ V_102 ] ;
#if 1
F_61 ( V_2 , V_104 -> V_107 ) ;
#endif
V_104 -> V_108 = F_60 ( V_62 ) ;
V_104 -> V_107 = F_57 ( V_62 ) ;
V_104 -> V_109 = F_58 ( V_62 ) ;
V_104 -> V_110 = F_59 ( V_62 ) ;
F_6
( L_11 ,
V_59 , V_102 , F_57 ( V_62 ) ,
F_58 ( V_62 ) , F_59 ( V_62 ) ,
F_60 ( V_62 ) ) ;
return V_56 ;
}
enum V_53 F_62 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_57 ;
struct V_103 * V_104 = NULL ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
int V_102 ;
#if 1
F_63 ( & V_102 , sizeof( V_102 ) ) ;
V_102 &= ( V_105 - 1 ) ;
#else
V_102 = V_111 % V_105 ;
#endif
if ( V_102 < 0 || V_102 >= V_105 ) {
F_4 ( L_10 , V_52 , V_102 ) ;
return V_60 ;
}
V_104 = & V_2 -> V_8 . V_106 [ V_102 ] ;
#if 1
F_61 ( V_2 , V_104 -> V_107 ) ;
#endif
V_104 -> V_108 = F_60 ( V_62 ) ;
V_104 -> V_107 = F_57 ( V_62 ) ;
V_104 -> V_109 = F_58 ( V_62 ) ;
V_104 -> V_110 = F_59 ( V_62 ) ;
F_6
( L_12 ,
V_59 , V_102 , F_57 ( V_62 ) ,
F_58 ( V_62 ) ,
F_59 ( V_62 ) ) ;
return V_56 ;
}
enum V_53 F_64 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
long V_112 = F_57 ( V_62 ) ;
enum V_53 V_56 = V_57 ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
int V_102 = - 1 ;
V_102 = F_65 ( V_2 , V_112 ) ;
F_66 ( V_62 , V_102 ) ;
F_6 ( L_13 , V_59 , V_112 ,
V_102 ) ;
return V_56 ;
}
enum V_53
F_67 ( V_14 V_113 , V_14 * V_114 , V_14 V_54 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_57 ;
T_5 V_26 , V_22 , V_116 , V_117 , V_118 , V_119 ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
unsigned long V_120 ;
V_120 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 ) {
return V_56 ;
}
V_116 = ( V_113 >> 21 ) & 0x1f ;
V_26 = ( V_113 >> 16 ) & 0x1f ;
V_22 = ( V_113 >> 11 ) & 0x1f ;
V_117 = V_113 & 0x7 ;
V_118 = ( V_113 >> 25 ) & 1 ;
if ( V_118 ) {
V_119 = ( V_113 ) & 0xff ;
switch ( V_119 ) {
case V_121 :
V_56 = F_54 ( V_2 ) ;
break;
case V_122 :
V_56 = F_56 ( V_2 ) ;
break;
case V_123 :
V_56 = F_62 ( V_2 ) ;
break;
case V_124 :
V_56 = F_64 ( V_2 ) ;
break;
case V_125 :
F_4 ( L_14 ) ;
break;
case V_126 :
V_56 = F_44 ( V_2 ) ;
goto V_127;
break;
case V_128 :
V_56 = F_49 ( V_2 ) ;
break;
}
} else {
switch ( V_116 ) {
case V_129 :
#ifdef F_68
V_62 -> V_93 [ V_22 ] [ V_117 ] ++ ;
#endif
if ( ( V_22 == V_130 ) && ( V_117 == 0 ) ) {
V_2 -> V_8 . V_21 [ V_26 ] = F_22 ( V_2 ) ;
} else if ( ( V_22 == V_131 ) && ( V_117 == 0 ) ) {
V_2 -> V_8 . V_21 [ V_26 ] = 0x0 ;
#ifdef F_69
F_70 ( V_113 , V_114 , V_2 ) ;
#endif
}
else {
V_2 -> V_8 . V_21 [ V_26 ] = V_62 -> V_132 [ V_22 ] [ V_117 ] ;
#ifdef F_69
F_70 ( V_113 , V_114 , V_2 ) ;
#endif
}
F_6
( L_15 ,
V_59 , V_22 , V_117 , V_26 , V_2 -> V_8 . V_21 [ V_26 ] ) ;
break;
case V_133 :
V_2 -> V_8 . V_21 [ V_26 ] = V_62 -> V_132 [ V_22 ] [ V_117 ] ;
break;
case V_134 :
#ifdef F_68
V_62 -> V_93 [ V_22 ] [ V_117 ] ++ ;
#endif
if ( ( V_22 == V_135 )
&& ( V_2 -> V_8 . V_21 [ V_26 ] >=
V_105 ) ) {
F_4 ( L_16 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_56 = V_60 ;
break;
}
#define F_71 0xff
if ( ( V_22 == V_136 ) && ( V_117 == 1 ) ) {
F_72 ( V_62 ,
~ ( F_71 ) ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
F_4 ( L_17 ,
F_73 ( V_62 ) ) ;
} else if ( V_22 == V_137 && V_117 == 0 ) {
V_14 V_138 =
V_2 -> V_8 . V_21 [ V_26 ] & V_139 ;
if ( ( F_74 ( V_2 -> V_8 . V_21 [ V_26 ] ) != V_140 )
&&
( ( F_57 ( V_62 ) &
V_139 ) != V_138 ) ) {
F_6
( L_18 ,
F_57 ( V_62 ) &
V_139 ,
V_2 -> V_8 . V_21 [ V_26 ] & V_139 ) ;
F_75 ( 1 ) ;
}
F_76 ( V_62 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
}
else if ( ( V_22 == V_130 ) && ( V_117 == 0 ) ) {
F_28 ( V_2 , V_2 -> V_8 . V_21 [ V_26 ] ) ;
goto V_141;
} else if ( ( V_22 == V_142 ) && ( V_117 == 0 ) ) {
F_6 ( L_19 ,
V_59 , F_26 ( V_62 ) ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_78 -> V_143 ( V_2 ) ;
F_32 ( V_2 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
} else if ( ( V_22 == V_144 ) && ( V_117 == 0 ) ) {
F_77 ( V_62 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
F_47 ( V_62 ,
( V_145 | V_146 ) ) ;
#ifdef F_69
F_78 ( V_113 , V_114 , V_2 ) ;
#endif
} else if ( ( V_22 == V_147 ) && ( V_117 == 0 ) ) {
V_14 V_148 , V_149 ;
V_148 = F_8 ( V_62 ) ;
V_149 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_79 ( V_62 , 0x08800300 ,
V_149 ) ;
if ( ( V_148 ^ V_149 ) & V_65 ) {
if ( V_149 & V_65 )
F_35 ( V_2 ) ;
else
F_37 ( V_2 ) ;
}
} else {
V_62 -> V_132 [ V_22 ] [ V_117 ] = V_2 -> V_8 . V_21 [ V_26 ] ;
#ifdef F_69
F_78 ( V_113 , V_114 , V_2 ) ;
#endif
}
F_6 ( L_20 , V_59 ,
V_22 , V_117 , V_62 -> V_132 [ V_22 ] [ V_117 ] ) ;
break;
case V_150 :
F_4
( L_21 ,
V_2 -> V_8 . V_59 , V_26 , V_22 , V_117 ) ;
V_56 = V_60 ;
break;
case V_151 :
#ifdef F_80
V_62 -> V_93 [ V_144 ] [ 0 ] ++ ;
#endif
if ( V_26 != 0 ) {
V_2 -> V_8 . V_21 [ V_26 ] =
F_45 ( V_62 ) ;
}
if ( V_113 & 0x20 ) {
F_6 ( L_22 ,
V_2 -> V_8 . V_59 ) ;
F_81 ( V_62 , V_152 ) ;
} else {
F_6 ( L_23 ,
V_2 -> V_8 . V_59 ) ;
F_47 ( V_62 , V_152 ) ;
}
break;
case V_153 :
{
V_14 V_154 =
V_62 -> V_132 [ V_144 ] [ 2 ] & 0xf ;
V_14 V_155 =
( V_62 -> V_132 [ V_144 ] [ 2 ] >> 6 ) & 0xf ;
if ( V_154 || V_155 ) {
V_56 = V_60 ;
break;
}
F_6 ( L_24 , V_155 , V_22 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_2 -> V_8 . V_21 [ V_22 ] = V_2 -> V_8 . V_21 [ V_26 ] ;
}
break;
default:
F_4
( L_25 ,
V_2 -> V_8 . V_59 , V_116 ) ;
V_56 = V_60 ;
break;
}
}
V_141:
if ( V_56 == V_60 ) {
V_2 -> V_8 . V_59 = V_120 ;
}
V_127:
return V_56 ;
}
enum V_53
F_82 ( V_14 V_113 , V_14 V_54 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_156 ;
T_5 V_119 , V_157 , V_26 , V_158 ;
V_14 V_159 ;
void * V_160 = V_99 -> V_161 . V_160 ;
unsigned long V_120 ;
V_120 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 )
return V_56 ;
V_26 = ( V_113 >> 16 ) & 0x1f ;
V_157 = ( V_113 >> 21 ) & 0x1f ;
V_158 = V_113 & 0xffff ;
V_119 = ( V_113 >> 26 ) & 0x3f ;
switch ( V_119 ) {
case V_162 :
V_159 = 1 ;
if ( V_159 > sizeof( V_99 -> V_161 . V_160 ) ) {
F_83 ( L_26 , V_52 ,
V_99 -> V_161 . V_163 ) ;
}
V_99 -> V_161 . V_164 =
V_78 -> V_165 ( V_2 -> V_8 .
V_166 ) ;
if ( V_99 -> V_161 . V_164 == V_167 ) {
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_163 = V_159 ;
V_99 -> V_161 . V_168 = 1 ;
V_2 -> V_169 = 1 ;
V_2 -> V_170 = 1 ;
* ( V_171 * ) V_160 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_27 ,
V_2 -> V_8 . V_166 , V_2 -> V_8 . V_21 [ V_26 ] ,
* ( V_172 * ) V_160 ) ;
break;
case V_173 :
V_159 = 4 ;
if ( V_159 > sizeof( V_99 -> V_161 . V_160 ) ) {
F_83 ( L_26 , V_52 ,
V_99 -> V_161 . V_163 ) ;
}
V_99 -> V_161 . V_164 =
V_78 -> V_165 ( V_2 -> V_8 .
V_166 ) ;
if ( V_99 -> V_161 . V_164 == V_167 ) {
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_163 = V_159 ;
V_99 -> V_161 . V_168 = 1 ;
V_2 -> V_169 = 1 ;
V_2 -> V_170 = 1 ;
* ( V_14 * ) V_160 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_28 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_166 ,
V_2 -> V_8 . V_21 [ V_26 ] , * ( V_14 * ) V_160 ) ;
break;
case V_174 :
V_159 = 2 ;
if ( V_159 > sizeof( V_99 -> V_161 . V_160 ) ) {
F_83 ( L_26 , V_52 ,
V_99 -> V_161 . V_163 ) ;
}
V_99 -> V_161 . V_164 =
V_78 -> V_165 ( V_2 -> V_8 .
V_166 ) ;
if ( V_99 -> V_161 . V_164 == V_167 ) {
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_163 = V_159 ;
V_99 -> V_161 . V_168 = 1 ;
V_2 -> V_169 = 1 ;
V_2 -> V_170 = 1 ;
* ( V_175 * ) V_160 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_29 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_166 ,
V_2 -> V_8 . V_21 [ V_26 ] , * ( V_14 * ) V_160 ) ;
break;
default:
F_4 ( L_30 ) ;
V_56 = V_60 ;
break;
}
if ( V_56 == V_60 ) {
V_2 -> V_8 . V_59 = V_120 ;
}
return V_56 ;
}
enum V_53
F_84 ( V_14 V_113 , V_14 V_54 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_156 ;
T_5 V_119 , V_157 , V_26 , V_158 ;
V_14 V_159 ;
V_26 = ( V_113 >> 16 ) & 0x1f ;
V_157 = ( V_113 >> 21 ) & 0x1f ;
V_158 = V_113 & 0xffff ;
V_119 = ( V_113 >> 26 ) & 0x3f ;
V_2 -> V_8 . V_176 = V_54 ;
V_2 -> V_8 . V_177 = V_26 ;
switch ( V_119 ) {
case V_178 :
V_159 = 4 ;
if ( V_159 > sizeof( V_99 -> V_161 . V_160 ) ) {
F_83 ( L_26 , V_52 ,
V_99 -> V_161 . V_163 ) ;
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_164 =
V_78 -> V_165 ( V_2 -> V_8 .
V_166 ) ;
if ( V_99 -> V_161 . V_164 == V_167 ) {
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_163 = V_159 ;
V_99 -> V_161 . V_168 = 0 ;
V_2 -> V_169 = 1 ;
V_2 -> V_170 = 0 ;
break;
case V_179 :
case V_180 :
V_159 = 2 ;
if ( V_159 > sizeof( V_99 -> V_161 . V_160 ) ) {
F_83 ( L_26 , V_52 ,
V_99 -> V_161 . V_163 ) ;
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_164 =
V_78 -> V_165 ( V_2 -> V_8 .
V_166 ) ;
if ( V_99 -> V_161 . V_164 == V_167 ) {
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_163 = V_159 ;
V_99 -> V_161 . V_168 = 0 ;
V_2 -> V_169 = 1 ;
V_2 -> V_170 = 0 ;
if ( V_119 == V_179 )
V_2 -> V_169 = 2 ;
else
V_2 -> V_169 = 1 ;
break;
case V_181 :
case V_182 :
V_159 = 1 ;
if ( V_159 > sizeof( V_99 -> V_161 . V_160 ) ) {
F_83 ( L_26 , V_52 ,
V_99 -> V_161 . V_163 ) ;
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_164 =
V_78 -> V_165 ( V_2 -> V_8 .
V_166 ) ;
if ( V_99 -> V_161 . V_164 == V_167 ) {
V_56 = V_60 ;
break;
}
V_99 -> V_161 . V_163 = V_159 ;
V_99 -> V_161 . V_168 = 0 ;
V_2 -> V_170 = 0 ;
if ( V_119 == V_182 )
V_2 -> V_169 = 2 ;
else
V_2 -> V_169 = 1 ;
break;
default:
F_4 ( L_31 ) ;
V_56 = V_60 ;
break;
}
return V_56 ;
}
int F_85 ( unsigned long V_183 , struct V_1 * V_2 )
{
unsigned long V_158 = ( V_183 & ~ V_184 ) ;
struct V_185 * V_185 = V_2 -> V_185 ;
unsigned long V_186 ;
T_6 V_187 ;
T_7 V_188 ;
V_187 = V_183 >> V_189 ;
if ( V_187 >= V_185 -> V_8 . V_190 ) {
F_4 ( L_32 , V_52 , V_187 ) ;
F_86 () ;
F_87 ( V_2 ) ;
return - 1 ;
}
V_188 = V_185 -> V_8 . V_191 [ V_187 ] ;
V_186 = ( V_188 << V_189 ) | V_158 ;
F_4 ( L_33 , V_52 , V_183 , F_88 ( V_186 ) ) ;
F_89 ( F_88 ( V_186 ) , 32 ) ;
return 0 ;
}
enum V_53
F_90 ( V_14 V_113 , V_14 * V_114 , V_14 V_54 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
extern void (* F_91) ( void );
extern void (* F_92) ( void );
enum V_53 V_56 = V_57 ;
T_5 V_158 , V_192 , V_193 , V_119 , V_157 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned long V_183 ;
unsigned long V_120 ;
V_120 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 )
return V_56 ;
V_157 = ( V_113 >> 21 ) & 0x1f ;
V_193 = ( V_113 >> 16 ) & 0x1f ;
V_158 = V_113 & 0xffff ;
V_192 = ( V_113 >> 16 ) & 0x3 ;
V_119 = ( V_113 >> 18 ) & 0x7 ;
V_183 = V_8 -> V_21 [ V_157 ] + V_158 ;
F_6 ( L_34 ,
V_192 , V_119 , V_157 , V_8 -> V_21 [ V_157 ] , V_158 ) ;
if ( V_119 == V_194 ) {
F_6
( L_35 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_21 [ 31 ] , V_192 , V_119 , V_157 ,
V_8 -> V_21 [ V_157 ] , V_158 ) ;
if ( V_192 == V_195 )
F_91 () ;
else if ( V_192 == V_196 )
F_92 () ;
else {
F_4 ( L_36 ,
V_52 ) ;
return V_60 ;
}
#ifdef F_69
F_93 ( V_113 , V_114 , V_2 ) ;
#endif
goto V_141;
}
F_94 () ;
if ( F_95 ( V_183 ) == V_197 ) {
if ( F_96 ( V_2 , V_183 ) < 0 ) {
F_97 ( V_183 , V_2 ) ;
}
} else if ( ( F_95 ( V_183 ) < V_197 ) ||
F_95 ( V_183 ) == V_198 ) {
int V_102 ;
if ( F_96 ( V_2 , V_183 ) >= 0 ) {
goto V_199;
}
V_102 = F_65 ( V_2 , ( V_183 & V_200 ) |
( F_57
( V_62 ) & V_139 ) ) ;
if ( V_102 < 0 ) {
V_2 -> V_8 . V_201 = ( V_183 & V_200 ) ;
V_2 -> V_8 . V_166 = V_183 ;
V_56 = F_98 ( V_54 , NULL , V_99 ,
V_2 ) ;
F_99 () ;
goto V_127;
} else {
struct V_103 * V_104 = & V_2 -> V_8 . V_106 [ V_102 ] ;
if ( ! F_100 ( * V_104 , V_183 ) ) {
V_56 = F_101 ( V_54 , NULL ,
V_99 , V_2 ) ;
F_99 () ;
goto V_127;
} else {
F_102 ( V_2 , V_104 ,
NULL ,
NULL ) ;
}
}
} else {
F_4
( L_37 ,
V_192 , V_119 , V_157 , V_8 -> V_21 [ V_157 ] , V_158 ) ;
V_56 = V_60 ;
F_99 () ;
goto V_127;
}
V_199:
if ( V_192 == V_195
&& ( V_119 == V_202
|| V_119 == V_203 ) ) {
F_103 ( V_183 ) ;
#ifdef F_69
F_104 ( V_113 , V_114 , V_2 ) ;
#endif
} else if ( V_119 == V_203 && V_192 == V_196 ) {
F_103 ( V_183 ) ;
F_105 ( V_183 ) ;
#ifdef F_69
F_104 ( V_113 , V_114 , V_2 ) ;
#endif
} else {
F_4
( L_38 ,
V_192 , V_119 , V_157 , V_8 -> V_21 [ V_157 ] , V_158 ) ;
V_56 = V_60 ;
F_99 () ;
goto V_127;
}
F_99 () ;
V_127:
V_2 -> V_8 . V_59 = V_120 ;
V_141:
return V_56 ;
}
enum V_53
F_106 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
V_14 V_113 ;
if ( V_54 & V_58 ) {
V_114 += 1 ;
}
V_113 = F_2 ( V_114 , V_2 ) ;
switch ( ( (union V_5 ) V_113 ) . V_18 . V_16 ) {
case V_204 :
V_56 = F_67 ( V_113 , V_114 , V_54 , V_99 , V_2 ) ;
break;
case V_162 :
case V_174 :
case V_173 :
V_56 = F_82 ( V_113 , V_54 , V_99 , V_2 ) ;
break;
case V_182 :
case V_181 :
case V_180 :
case V_179 :
case V_178 :
V_56 = F_84 ( V_113 , V_54 , V_99 , V_2 ) ;
break;
case V_205 :
++ V_2 -> V_93 . V_206 ;
F_50 ( V_2 , V_207 ) ;
V_56 = F_90 ( V_113 , V_114 , V_54 , V_99 , V_2 ) ;
break;
default:
F_4 ( L_39 , V_114 ,
V_113 ) ;
F_87 ( V_2 ) ;
V_56 = V_60 ;
break;
}
return V_56 ;
}
enum V_53
F_107 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_6 ( L_40 , V_8 -> V_59 ) ;
F_79 ( V_62 , ( 0xff ) ,
( V_208 << V_209 ) ) ;
V_8 -> V_59 = V_197 + 0x180 ;
} else {
F_4 ( L_41 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_98 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_112 = ( V_2 -> V_8 . V_166 & V_200 ) |
( F_57 ( V_62 ) & V_139 ) ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_6 ( L_42 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x0 ;
} else {
F_6 ( L_43 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x180 ;
}
F_79 ( V_62 , ( 0xff ) ,
( V_210 << V_209 ) ) ;
F_109 ( V_62 , V_2 -> V_8 . V_166 ) ;
F_76 ( V_62 , V_112 ) ;
F_75 ( 1 ) ;
return V_56 ;
}
enum V_53
F_101 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_112 =
( V_2 -> V_8 . V_166 & V_200 ) |
( F_57 ( V_62 ) & V_139 ) ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_6 ( L_44 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x180 ;
} else {
F_6 ( L_43 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x180 ;
}
F_79 ( V_62 , ( 0xff ) ,
( V_210 << V_209 ) ) ;
F_109 ( V_62 , V_2 -> V_8 . V_166 ) ;
F_76 ( V_62 , V_112 ) ;
F_75 ( 1 ) ;
return V_56 ;
}
enum V_53
F_110 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_112 = ( V_2 -> V_8 . V_166 & V_200 ) |
( F_57 ( V_62 ) & V_139 ) ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_6 ( L_45 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x0 ;
} else {
F_6 ( L_46 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x180 ;
}
F_79 ( V_62 , ( 0xff ) ,
( V_211 << V_209 ) ) ;
F_109 ( V_62 , V_2 -> V_8 . V_166 ) ;
F_76 ( V_62 , V_112 ) ;
F_75 ( 1 ) ;
return V_56 ;
}
enum V_53
F_111 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_112 = ( V_2 -> V_8 . V_166 & V_200 ) |
( F_57 ( V_62 ) & V_139 ) ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_6 ( L_45 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x180 ;
} else {
F_6 ( L_46 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x180 ;
}
F_79 ( V_62 , ( 0xff ) ,
( V_211 << V_209 ) ) ;
F_109 ( V_62 , V_2 -> V_8 . V_166 ) ;
F_76 ( V_62 , V_112 ) ;
F_75 ( 1 ) ;
return V_56 ;
}
enum V_53
F_112 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
#ifdef F_113
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
unsigned long V_112 = ( V_2 -> V_8 . V_166 & V_200 ) |
( F_57 ( V_62 ) & V_139 ) ;
int V_102 ;
V_102 = F_65 ( V_2 , V_112 ) ;
if ( V_102 < 0 ) {
F_61 ( V_2 , V_2 -> V_8 . V_166 ) ;
F_83 ( L_47 ,
V_52 , V_112 ) ;
F_114 ( V_2 ) ;
F_86 () ;
return V_60 ;
}
#endif
V_56 = F_115 ( V_54 , V_114 , V_99 , V_2 ) ;
return V_56 ;
}
enum V_53
F_115 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
unsigned long V_112 = ( V_2 -> V_8 . V_166 & V_200 ) |
( F_57 ( V_62 ) & V_139 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_6 ( L_48 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x180 ;
} else {
F_6 ( L_49 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_197 + 0x180 ;
}
F_79 ( V_62 , ( 0xff ) , ( V_212 << V_209 ) ) ;
F_109 ( V_62 , V_2 -> V_8 . V_166 ) ;
F_76 ( V_62 , V_112 ) ;
F_75 ( 1 ) ;
return V_56 ;
}
enum V_53
F_116 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
}
V_8 -> V_59 = V_197 + 0x180 ;
F_79 ( V_62 , ( 0xff ) ,
( V_213 << V_209 ) ) ;
F_79 ( V_62 , ( V_214 ) , ( 0x1 << V_215 ) ) ;
return V_56 ;
}
enum V_53
F_117 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_6 ( L_50 , V_8 -> V_59 ) ;
F_79 ( V_62 , ( 0xff ) ,
( V_216 << V_209 ) ) ;
V_8 -> V_59 = V_197 + 0x180 ;
} else {
F_83 ( L_51 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_118 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_6 ( L_52 , V_8 -> V_59 ) ;
F_79 ( V_62 , ( 0xff ) ,
( V_217 << V_209 ) ) ;
V_8 -> V_59 = V_197 + 0x180 ;
} else {
F_4 ( L_53 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_119 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_120 ;
V_14 V_113 ;
V_120 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 )
return V_56 ;
if ( V_54 & V_58 )
V_114 += 1 ;
V_113 = F_2 ( V_114 , V_2 ) ;
if ( V_113 == V_11 ) {
F_4 ( L_54 , V_52 , V_114 ) ;
return V_60 ;
}
if ( ( V_113 & V_218 ) == V_219 && ( V_113 & V_220 ) == V_221 ) {
int V_222 = ! F_120 ( V_2 ) ;
int V_22 = ( V_113 & V_223 ) >> 11 ;
int V_26 = ( V_113 & V_224 ) >> 16 ;
if ( V_222 && ! ( F_121 ( V_62 ) & F_122 ( V_22 ) ) ) {
F_6 ( L_55 ,
V_22 , V_114 ) ;
goto V_225;
}
switch ( V_22 ) {
case 0 :
V_8 -> V_21 [ V_26 ] = 0 ;
break;
case 1 :
V_8 -> V_21 [ V_26 ] = F_123 ( V_226 . V_227 . V_228 ,
V_226 . V_229 . V_228 ) ;
break;
case 2 :
V_8 -> V_21 [ V_26 ] = F_22 ( V_2 ) ;
break;
case 3 :
switch ( V_226 . V_230 ) {
case V_231 :
case V_232 :
V_8 -> V_21 [ V_26 ] = 1 ;
break;
default:
V_8 -> V_21 [ V_26 ] = 2 ;
}
break;
case 29 :
V_8 -> V_21 [ V_26 ] = F_124 ( V_62 ) ;
break;
default:
F_6 ( L_56 , V_22 , V_114 ) ;
goto V_225;
}
} else {
F_6 ( L_57 , V_114 , V_113 ) ;
goto V_225;
}
return V_57 ;
V_225:
V_2 -> V_8 . V_59 = V_120 ;
return F_117 ( V_54 , V_114 , V_99 , V_2 ) ;
}
enum V_53
F_125 ( struct V_1 * V_2 , struct V_115 * V_99 )
{
unsigned long * V_233 = & V_2 -> V_8 . V_21 [ V_2 -> V_8 . V_177 ] ;
enum V_53 V_56 = V_57 ;
unsigned long V_120 ;
if ( V_99 -> V_161 . V_163 > sizeof( * V_233 ) ) {
F_4 ( L_58 , V_99 -> V_161 . V_163 ) ;
V_56 = V_60 ;
goto V_141;
}
V_120 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_2 -> V_8 . V_176 ) ;
if ( V_56 == V_60 )
return V_56 ;
switch ( V_99 -> V_161 . V_163 ) {
case 4 :
* V_233 = * ( T_5 * ) V_99 -> V_161 . V_160 ;
break;
case 2 :
if ( V_2 -> V_169 == 2 )
* V_233 = * ( V_234 * ) V_99 -> V_161 . V_160 ;
else
* V_233 = * ( V_234 * ) V_99 -> V_161 . V_160 ;
break;
case 1 :
if ( V_2 -> V_169 == 2 )
* V_233 = * ( V_235 * ) V_99 -> V_161 . V_160 ;
else
* V_233 = * ( V_171 * ) V_99 -> V_161 . V_160 ;
break;
}
if ( V_2 -> V_8 . V_176 & V_58 )
F_6
( L_59 ,
V_2 -> V_8 . V_59 , V_99 -> V_161 . V_163 , V_2 -> V_8 . V_177 , * V_233 ,
V_2 -> V_169 ) ;
V_141:
return V_56 ;
}
static enum V_53
F_126 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
V_14 V_236 = ( V_54 >> V_209 ) & 0x1f ;
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_45 ( V_62 ) & V_90 ) == 0 ) {
F_108 ( V_62 , V_8 -> V_59 ) ;
F_81 ( V_62 , V_90 ) ;
if ( V_54 & V_58 )
F_36 ( V_62 , V_58 ) ;
else
F_38 ( V_62 , V_58 ) ;
F_79 ( V_62 , ( 0xff ) ,
( V_236 << V_209 ) ) ;
V_8 -> V_59 = V_197 + 0x180 ;
F_109 ( V_62 , V_2 -> V_8 . V_166 ) ;
F_6 ( L_60 ,
V_236 , F_46 ( V_62 ) ,
F_127 ( V_62 ) ) ;
} else {
F_4 ( L_61 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_128 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
V_14 V_236 = ( V_54 >> V_209 ) & 0x1f ;
unsigned long V_237 = V_2 -> V_8 . V_166 ;
int V_222 = ! F_120 ( V_2 ) ;
if ( V_222 ) {
switch ( V_236 ) {
case V_238 :
case V_208 :
case V_217 :
case V_216 :
break;
case V_213 :
if ( ( ( V_54 & V_214 ) >> V_215 ) == 0 )
V_56 = V_239 ;
break;
case V_212 :
break;
case V_210 :
if ( V_237 >= ( unsigned long ) V_197 ) {
F_4 ( L_62 , V_52 ,
V_237 ) ;
V_54 &= ~ 0xff ;
V_54 |= ( V_240 << V_209 ) ;
V_56 = V_239 ;
}
break;
case V_211 :
if ( V_237 >= ( unsigned long ) V_197 ) {
F_4 ( L_63 , V_52 ,
V_237 ) ;
V_54 &= ~ 0xff ;
V_54 |= ( V_241 << V_209 ) ;
V_56 = V_239 ;
}
break;
case V_241 :
F_4 ( L_64 , V_52 ,
V_237 ) ;
if ( ( V_237 & V_184 ) == V_242 ) {
V_54 &= ~ 0xff ;
V_54 |= ( V_211 << V_209 ) ;
}
V_56 = V_239 ;
break;
case V_240 :
F_4 ( L_65 , V_52 ,
V_237 ) ;
if ( ( V_237 & V_184 ) == V_242 ) {
V_54 &= ~ 0xff ;
V_54 |= ( V_210 << V_209 ) ;
}
V_56 = V_239 ;
break;
default:
V_56 = V_239 ;
break;
}
}
if ( V_56 == V_239 ) {
F_126 ( V_54 , V_114 , V_99 , V_2 ) ;
}
return V_56 ;
}
enum V_53
F_129 ( unsigned long V_54 , V_14 * V_114 ,
struct V_115 * V_99 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
V_14 V_236 = ( V_54 >> V_209 ) & 0x1f ;
unsigned long V_183 = V_2 -> V_8 . V_166 ;
int V_102 ;
F_6 ( L_66 ,
V_2 -> V_8 . V_166 , V_2 -> V_8 . V_201 ) ;
V_102 = F_65 ( V_2 ,
( V_183 & V_200 ) |
( F_57
( V_2 -> V_8 . V_62 ) & V_139 ) ) ;
if ( V_102 < 0 ) {
if ( V_236 == V_210 ) {
V_56 = F_98 ( V_54 , V_114 , V_99 , V_2 ) ;
} else if ( V_236 == V_211 ) {
V_56 = F_110 ( V_54 , V_114 , V_99 , V_2 ) ;
} else {
F_4 ( L_67 , V_52 , V_236 ) ;
V_56 = V_60 ;
}
} else {
struct V_103 * V_104 = & V_2 -> V_8 . V_106 [ V_102 ] ;
if ( ! F_100 ( * V_104 , V_183 ) ) {
if ( V_236 == V_210 ) {
V_56 = F_101 ( V_54 , V_114 , V_99 ,
V_2 ) ;
} else if ( V_236 == V_211 ) {
V_56 = F_111 ( V_54 , V_114 , V_99 ,
V_2 ) ;
} else {
F_4 ( L_67 , V_52 ,
V_236 ) ;
V_56 = V_60 ;
}
} else {
F_6
( L_68 ,
V_104 -> V_107 , V_104 -> V_109 , V_104 -> V_110 ) ;
F_102 ( V_2 , V_104 , NULL ,
NULL ) ;
}
}
return V_56 ;
}
