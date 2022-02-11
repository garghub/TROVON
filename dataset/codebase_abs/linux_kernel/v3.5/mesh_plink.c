static inline
void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 . V_5 . V_6 ) ;
F_3 ( V_2 ) ;
}
static inline
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_3 . V_4 . V_5 . V_6 ) ;
F_3 ( V_2 ) ;
}
static inline void F_6 ( struct V_7 * V_8 )
{
V_8 -> V_9 = V_10 ;
V_8 -> V_11 = V_8 -> V_12 = V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
}
static struct V_7 * F_7 ( struct V_1 * V_2 ,
T_1 * V_15 )
{
struct V_7 * V_8 ;
if ( V_2 -> V_16 -> V_17 >= V_18 )
return NULL ;
V_8 = F_8 ( V_2 , V_15 , V_19 ) ;
if ( ! V_8 )
return NULL ;
F_9 ( V_8 , V_20 ) ;
F_9 ( V_8 , V_21 ) ;
F_9 ( V_8 , V_22 ) ;
F_10 ( V_8 , V_23 ) ;
return V_8 ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_24 * V_16 = V_2 -> V_16 ;
struct V_7 * V_8 ;
T_2 V_25 = 0 ;
T_3 V_26 ;
bool V_27 = false , V_28 = false ;
if ( V_16 -> V_29 == V_30 )
return 0 ;
F_12 () ;
F_13 (sta, &local->sta_list, list) {
if ( V_2 != V_8 -> V_2 ||
V_8 -> V_9 != V_31 )
continue;
switch ( V_8 -> V_32 ) {
case V_30 :
F_14 ( L_1 ,
V_2 -> V_33 . V_34 , V_8 -> V_8 . V_34 ) ;
V_27 = true ;
goto V_35;
case V_36 :
F_14 ( L_2 ,
V_2 -> V_33 . V_34 , V_8 -> V_8 . V_34 ) ;
V_28 = true ;
default:
break;
}
}
V_35:
F_15 () ;
if ( V_27 )
V_26 = V_37 ;
else if ( V_28 && V_16 -> V_29 > V_36 )
V_26 = V_38 ;
else
V_26 = V_39 ;
if ( V_2 -> V_33 . V_40 . V_41 != V_26 ) {
V_2 -> V_33 . V_40 . V_41 = V_26 ;
V_2 -> V_3 . V_4 . V_42 . V_26 = V_26 ;
V_25 = V_43 ;
F_14 ( L_3 ,
V_2 -> V_33 . V_34 , V_26 ) ;
}
return V_25 ;
}
static bool F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_44 = false ;
if ( V_8 -> V_9 == V_31 ) {
F_4 ( V_2 ) ;
V_44 = true ;
}
V_8 -> V_9 = V_45 ;
F_17 ( V_8 ) ;
return V_44 ;
}
void F_18 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_44 ;
F_19 ( & V_8 -> V_46 ) ;
V_44 = F_16 ( V_8 ) ;
V_8 -> V_13 = F_20 ( V_47 ) ;
F_21 ( V_2 , V_48 ,
V_8 -> V_8 . V_34 , V_8 -> V_11 , V_8 -> V_12 ,
V_8 -> V_13 ) ;
F_22 ( & V_8 -> V_46 ) ;
if ( V_44 )
F_23 ( V_2 , V_49 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_50 V_51 ,
T_1 * V_52 , T_4 V_11 , T_4 V_12 , T_4 V_13 ) {
struct V_24 * V_16 = V_2 -> V_16 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
bool V_57 = false ;
T_3 V_58 = 0 ;
T_1 * V_59 , V_60 = 4 ;
int V_61 = F_24 ( struct V_55 , V_3 . V_51 . V_3 . V_62 ) +
sizeof( V_56 -> V_3 . V_51 . V_3 . V_62 ) ;
V_54 = F_25 ( V_16 -> V_63 +
V_61 +
2 +
2 +
2 + 8 +
2 + ( V_64 - 8 ) +
2 + V_2 -> V_3 . V_4 . V_65 +
2 + sizeof( struct V_66 ) +
2 + sizeof( struct V_67 ) +
2 + sizeof( struct V_68 ) +
2 + 8 +
V_2 -> V_3 . V_4 . V_60 ) ;
if ( ! V_54 )
return - 1 ;
F_26 ( V_54 , V_16 -> V_63 ) ;
V_56 = (struct V_55 * ) F_27 ( V_54 , V_61 ) ;
memset ( V_56 , 0 , V_61 ) ;
V_56 -> V_69 = F_20 ( V_70 |
V_71 ) ;
memcpy ( V_56 -> V_52 , V_52 , V_72 ) ;
memcpy ( V_56 -> V_73 , V_2 -> V_33 . V_34 , V_72 ) ;
memcpy ( V_56 -> V_74 , V_2 -> V_33 . V_34 , V_72 ) ;
V_56 -> V_3 . V_51 . V_75 = V_76 ;
V_56 -> V_3 . V_51 . V_3 . V_62 . V_77 = V_51 ;
if ( V_51 != V_48 ) {
V_59 = F_27 ( V_54 , 2 ) ;
memset ( V_59 , 0 , 2 ) ;
if ( V_51 == V_78 ) {
V_59 = F_27 ( V_54 , 2 ) ;
memcpy ( V_59 + 2 , & V_12 , 2 ) ;
}
if ( F_28 ( & V_2 -> V_33 , V_54 , true ) ||
F_29 ( & V_2 -> V_33 , V_54 , true ) ||
F_30 ( V_54 , V_2 ) ||
F_31 ( V_54 , V_2 ) ||
F_32 ( V_54 , V_2 ) )
return - 1 ;
} else {
if ( F_31 ( V_54 , V_2 ) )
return - 1 ;
}
switch ( V_51 ) {
case V_79 :
break;
case V_78 :
V_60 += 2 ;
V_57 = true ;
break;
case V_48 :
if ( V_12 ) {
V_60 += 2 ;
V_57 = true ;
}
V_60 += 2 ;
break;
default:
return - V_80 ;
}
if ( F_33 ( F_34 ( V_54 ) < 2 + V_60 ) )
return - V_81 ;
V_59 = F_27 ( V_54 , 2 + V_60 ) ;
* V_59 ++ = V_82 ;
* V_59 ++ = V_60 ;
memcpy ( V_59 , & V_58 , 2 ) ;
V_59 += 2 ;
memcpy ( V_59 , & V_11 , 2 ) ;
V_59 += 2 ;
if ( V_57 ) {
memcpy ( V_59 , & V_12 , 2 ) ;
V_59 += 2 ;
}
if ( V_51 == V_48 ) {
memcpy ( V_59 , & V_13 , 2 ) ;
V_59 += 2 ;
}
if ( V_51 != V_48 ) {
if ( F_35 ( V_54 , V_2 ) ||
F_36 ( V_54 , V_2 ) )
return - 1 ;
}
if ( F_37 ( V_54 , V_2 ) )
return - 1 ;
F_38 ( V_2 , V_54 ) ;
return 0 ;
}
static struct V_7 * F_39 ( struct V_1 * V_2 ,
T_1 * V_34 ,
struct V_83 * V_84 )
{
struct V_24 * V_16 = V_2 -> V_16 ;
enum V_85 V_86 = V_16 -> V_87 -> V_86 ;
struct V_88 * V_89 ;
T_2 V_90 , V_91 = 0 ;
struct V_7 * V_8 ;
bool V_92 = false ;
V_89 = V_16 -> V_93 . V_94 -> V_95 [ V_86 ] ;
V_90 = F_40 ( V_16 , V_84 , V_86 , & V_91 ) ;
V_8 = F_41 ( V_2 , V_34 ) ;
if ( ! V_8 ) {
if ( V_2 -> V_3 . V_4 . V_96 & V_97 ) {
F_42 ( V_2 -> V_98 , V_34 ,
V_84 -> V_99 ,
V_84 -> V_100 ,
V_101 ) ;
return NULL ;
}
V_8 = F_7 ( V_2 , V_34 ) ;
if ( ! V_8 )
return NULL ;
V_92 = true ;
}
F_19 ( & V_8 -> V_46 ) ;
V_8 -> V_102 = V_103 ;
V_8 -> V_8 . V_104 [ V_86 ] = V_90 ;
if ( V_84 -> V_105 &&
V_2 -> V_16 -> V_29 != V_30 )
F_43 ( V_2 , V_89 ,
V_84 -> V_105 ,
& V_8 -> V_8 . V_106 ) ;
else
memset ( & V_8 -> V_8 . V_106 , 0 , sizeof( V_8 -> V_8 . V_106 ) ) ;
if ( V_84 -> V_107 ) {
if ( ! ( V_84 -> V_107 -> V_108 &
V_109 ) )
V_8 -> V_8 . V_106 . V_110 &=
~ V_111 ;
V_8 -> V_32 =
F_44 ( V_84 -> V_107 ) ;
}
F_45 ( V_8 ) ;
F_22 ( & V_8 -> V_46 ) ;
if ( V_92 && F_46 ( V_8 ) )
return NULL ;
return V_8 ;
}
void F_47 ( struct V_1 * V_2 ,
T_1 * V_15 ,
struct V_83 * V_84 )
{
struct V_7 * V_8 ;
F_12 () ;
V_8 = F_39 ( V_2 , V_15 , V_84 ) ;
if ( ! V_8 )
goto V_35;
if ( F_48 ( V_84 ) &&
V_8 -> V_9 == V_10 &&
V_2 -> V_3 . V_4 . V_112 &&
V_2 -> V_3 . V_4 . V_42 . V_113 &&
F_49 ( V_8 , V_2 ) )
F_50 ( V_8 ) ;
V_35:
F_15 () ;
}
static void F_51 ( unsigned long V_114 )
{
struct V_7 * V_8 ;
T_4 V_11 , V_12 , V_13 ;
struct V_1 * V_2 ;
V_8 = (struct V_7 * ) V_114 ;
if ( V_8 -> V_2 -> V_16 -> V_115 ) {
V_8 -> V_116 = true ;
return;
}
F_19 ( & V_8 -> V_46 ) ;
if ( V_8 -> V_117 ) {
V_8 -> V_117 = false ;
F_22 ( & V_8 -> V_46 ) ;
return;
}
F_14 ( L_4 ,
V_8 -> V_8 . V_34 , V_8 -> V_9 ) ;
V_13 = 0 ;
V_11 = V_8 -> V_11 ;
V_12 = V_8 -> V_12 ;
V_2 = V_8 -> V_2 ;
switch ( V_8 -> V_9 ) {
case V_118 :
case V_119 :
if ( V_8 -> V_14 < F_52 ( V_2 ) ) {
T_2 rand ;
F_14 ( L_5 ,
V_8 -> V_8 . V_34 , V_8 -> V_14 ,
V_8 -> V_120 ) ;
F_53 ( & rand , sizeof( T_2 ) ) ;
V_8 -> V_120 = V_8 -> V_120 +
rand % V_8 -> V_120 ;
++ V_8 -> V_14 ;
F_54 ( V_8 , V_8 -> V_120 ) ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 , V_79 ,
V_8 -> V_8 . V_34 , V_11 , 0 , 0 ) ;
break;
}
V_13 = F_20 ( V_121 ) ;
case V_122 :
if ( ! V_13 )
V_13 = F_20 ( V_123 ) ;
V_8 -> V_9 = V_124 ;
F_54 ( V_8 , F_55 ( V_2 ) ) ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 , V_48 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , V_13 ) ;
break;
case V_124 :
F_56 ( & V_8 -> V_125 ) ;
F_6 ( V_8 ) ;
F_22 ( & V_8 -> V_46 ) ;
break;
default:
F_22 ( & V_8 -> V_46 ) ;
break;
}
}
void F_57 ( struct V_7 * V_8 )
{
if ( F_58 ( & V_8 -> V_125 ) )
V_8 -> V_116 = true ;
}
void F_59 ( struct V_7 * V_8 )
{
if ( V_8 -> V_116 ) {
F_60 ( & V_8 -> V_125 ) ;
V_8 -> V_116 = false ;
}
}
static inline void F_61 ( struct V_7 * V_8 , int V_126 )
{
V_8 -> V_125 . V_127 = V_103 + ( V_128 * V_126 / 1000 ) ;
V_8 -> V_125 . V_114 = ( unsigned long ) V_8 ;
V_8 -> V_125 . V_129 = F_51 ;
V_8 -> V_120 = V_126 ;
F_60 ( & V_8 -> V_125 ) ;
}
int F_50 ( struct V_7 * V_8 )
{
T_4 V_11 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_62 ( V_8 , V_130 ) )
return - V_131 ;
F_19 ( & V_8 -> V_46 ) ;
F_53 ( & V_11 , 2 ) ;
V_8 -> V_11 = V_11 ;
if ( V_8 -> V_9 != V_10 ) {
F_22 ( & V_8 -> V_46 ) ;
return - V_132 ;
}
V_8 -> V_9 = V_119 ;
F_61 ( V_8 , F_63 ( V_2 ) ) ;
F_22 ( & V_8 -> V_46 ) ;
F_14 ( L_6 ,
V_8 -> V_8 . V_34 ) ;
return F_21 ( V_2 , V_79 ,
V_8 -> V_8 . V_34 , V_11 , 0 , 0 ) ;
}
void F_64 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_44 ;
F_19 ( & V_8 -> V_46 ) ;
V_44 = F_16 ( V_8 ) ;
V_8 -> V_9 = V_45 ;
F_22 ( & V_8 -> V_46 ) ;
if ( V_44 )
F_23 ( V_2 , V_49 ) ;
}
void F_65 ( struct V_1 * V_2 , struct V_55 * V_56 ,
T_5 V_133 , struct V_134 * V_135 )
{
struct V_83 V_84 ;
struct V_7 * V_8 ;
enum V_136 V_137 ;
enum V_50 V_138 ;
T_5 V_139 ;
bool V_140 = true ;
T_1 V_60 ;
T_1 * V_141 ;
T_2 V_25 = 0 ;
T_4 V_12 , V_11 , V_13 ;
#ifdef F_66
static const char * V_142 [] = {
[ V_10 ] = L_7 ,
[ V_119 ] = L_8 ,
[ V_118 ] = L_9 ,
[ V_122 ] = L_10 ,
[ V_31 ] = L_11 ,
[ V_124 ] = L_12 ,
[ V_45 ] = L_13
} ;
#endif
if ( V_133 < V_143 + 3 )
return;
if ( F_67 ( V_56 -> V_52 ) ) {
F_14 ( L_14 ) ;
return;
}
V_141 = V_56 -> V_3 . V_51 . V_3 . V_62 . V_144 ;
V_139 = ( T_1 * ) V_56 -> V_3 . V_51 . V_3 . V_62 . V_144 - ( T_1 * ) V_56 ;
if ( V_56 -> V_3 . V_51 . V_3 . V_62 . V_77 ==
V_78 ) {
V_141 += 4 ;
V_139 += 4 ;
}
F_68 ( V_141 , V_133 - V_139 , & V_84 ) ;
if ( ! V_84 . V_145 ) {
F_14 ( L_15 ) ;
return;
}
if ( V_84 . V_146 &&
V_2 -> V_3 . V_4 . V_96 == V_147 ) {
F_14 ( L_16 ) ;
return;
}
V_138 = V_56 -> V_3 . V_51 . V_3 . V_62 . V_77 ;
V_60 = V_84 . V_148 ;
if ( ( V_138 == V_79 && V_60 != 4 ) ||
( V_138 == V_78 && V_60 != 6 ) ||
( V_138 == V_48 && V_60 != 6
&& V_60 != 8 ) ) {
F_14 ( L_17 ,
V_138 , V_60 ) ;
return;
}
if ( V_138 != V_48 &&
( ! V_84 . V_149 || ! V_84 . V_150 ) ) {
F_14 ( L_18 ) ;
return;
}
memcpy ( & V_12 , F_69 ( V_84 . V_145 ) , 2 ) ;
if ( V_138 == V_78 ||
( V_138 == V_48 && V_60 == 8 ) )
memcpy ( & V_11 , F_70 ( V_84 . V_145 ) , 2 ) ;
F_12 () ;
V_8 = F_41 ( V_2 , V_56 -> V_73 ) ;
if ( ! V_8 && V_138 != V_79 ) {
F_14 ( L_19 ) ;
F_15 () ;
return;
}
if ( V_138 == V_79 &&
! F_49 ( V_8 , V_2 ) ) {
F_14 ( L_20 ,
V_56 -> V_73 ) ;
F_15 () ;
return;
}
if ( V_8 && ! F_62 ( V_8 , V_130 ) ) {
F_14 ( L_21 ) ;
F_15 () ;
return;
}
if ( V_8 && V_8 -> V_9 == V_45 ) {
F_15 () ;
return;
}
V_137 = V_151 ;
if ( V_138 != V_48 &&
! F_71 ( V_2 , & V_84 ) ) {
V_140 = false ;
switch ( V_138 ) {
case V_79 :
V_137 = V_152 ;
break;
case V_78 :
V_137 = V_153 ;
break;
default:
break;
}
}
if ( ! V_8 && ! V_140 ) {
F_15 () ;
V_13 = F_20 ( V_154 ) ;
V_11 = 0 ;
F_21 ( V_2 , V_48 ,
V_56 -> V_73 , V_11 , V_12 , V_13 ) ;
return;
} else if ( ! V_8 ) {
if ( ! F_72 ( V_2 ) ) {
F_14 ( L_22 ) ;
F_15 () ;
return;
}
V_137 = V_155 ;
} else if ( V_140 ) {
switch ( V_138 ) {
case V_79 :
if ( ! F_72 ( V_2 ) ||
( V_8 -> V_12 && V_8 -> V_12 != V_12 ) )
V_137 = V_156 ;
else
V_137 = V_155 ;
break;
case V_78 :
if ( ! F_72 ( V_2 ) ||
( V_8 -> V_11 != V_11 || V_8 -> V_12 != V_12 ) )
V_137 = V_157 ;
else
V_137 = V_158 ;
break;
case V_48 :
if ( V_8 -> V_9 == V_31 )
V_137 = V_159 ;
else if ( V_8 -> V_12 != V_12 )
V_137 = V_160 ;
else if ( V_60 == 7 && V_8 -> V_11 != V_11 )
V_137 = V_160 ;
else
V_137 = V_159 ;
break;
default:
F_14 ( L_23 ) ;
F_15 () ;
return;
}
}
if ( V_137 == V_155 ) {
V_8 = F_39 ( V_2 , V_56 -> V_73 , & V_84 ) ;
if ( ! V_8 ) {
F_14 ( L_24 ) ;
F_15 () ;
return;
}
}
F_14 ( L_25 ,
V_56 -> V_73 , V_142 [ V_8 -> V_9 ] ,
F_73 ( V_8 -> V_11 ) , F_73 ( V_8 -> V_12 ) ,
V_137 ) ;
V_13 = 0 ;
F_19 ( & V_8 -> V_46 ) ;
switch ( V_8 -> V_9 ) {
case V_10 :
switch ( V_137 ) {
case V_159 :
F_6 ( V_8 ) ;
F_22 ( & V_8 -> V_46 ) ;
break;
case V_155 :
V_8 -> V_9 = V_118 ;
V_8 -> V_12 = V_12 ;
F_53 ( & V_11 , 2 ) ;
V_8 -> V_11 = V_11 ;
F_61 ( V_8 , F_63 ( V_2 ) ) ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 ,
V_79 ,
V_8 -> V_8 . V_34 , V_11 , 0 , 0 ) ;
F_21 ( V_2 ,
V_78 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , 0 ) ;
break;
default:
F_22 ( & V_8 -> V_46 ) ;
break;
}
break;
case V_119 :
switch ( V_137 ) {
case V_152 :
case V_153 :
V_13 = F_20 ( V_154 ) ;
case V_159 :
if ( ! V_13 )
V_13 = F_20 ( V_161 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_124 ;
if ( ! F_54 ( V_8 ,
F_55 ( V_2 ) ) )
V_8 -> V_117 = true ;
V_11 = V_8 -> V_11 ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 ,
V_48 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , V_13 ) ;
break;
case V_155 :
V_8 -> V_9 = V_118 ;
V_8 -> V_12 = V_12 ;
V_11 = V_8 -> V_11 ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 ,
V_78 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , 0 ) ;
break;
case V_158 :
V_8 -> V_9 = V_122 ;
if ( ! F_54 ( V_8 ,
F_74 ( V_2 ) ) )
V_8 -> V_117 = true ;
F_22 ( & V_8 -> V_46 ) ;
break;
default:
F_22 ( & V_8 -> V_46 ) ;
break;
}
break;
case V_118 :
switch ( V_137 ) {
case V_152 :
case V_153 :
V_13 = F_20 ( V_154 ) ;
case V_159 :
if ( ! V_13 )
V_13 = F_20 ( V_161 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_124 ;
if ( ! F_54 ( V_8 ,
F_55 ( V_2 ) ) )
V_8 -> V_117 = true ;
V_11 = V_8 -> V_11 ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 , V_48 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , V_13 ) ;
break;
case V_155 :
V_11 = V_8 -> V_11 ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 ,
V_78 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , 0 ) ;
break;
case V_158 :
F_56 ( & V_8 -> V_125 ) ;
V_8 -> V_9 = V_31 ;
F_22 ( & V_8 -> V_46 ) ;
F_1 ( V_2 ) ;
V_25 |= F_11 ( V_2 ) ;
V_25 |= V_49 ;
F_14 ( L_26 ,
V_8 -> V_8 . V_34 ) ;
break;
default:
F_22 ( & V_8 -> V_46 ) ;
break;
}
break;
case V_122 :
switch ( V_137 ) {
case V_152 :
case V_153 :
V_13 = F_20 ( V_154 ) ;
case V_159 :
if ( ! V_13 )
V_13 = F_20 ( V_161 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_124 ;
if ( ! F_54 ( V_8 ,
F_55 ( V_2 ) ) )
V_8 -> V_117 = true ;
V_11 = V_8 -> V_11 ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 ,
V_48 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , V_13 ) ;
break;
case V_155 :
F_56 ( & V_8 -> V_125 ) ;
V_8 -> V_9 = V_31 ;
F_22 ( & V_8 -> V_46 ) ;
F_1 ( V_2 ) ;
V_25 |= F_11 ( V_2 ) ;
V_25 |= V_49 ;
F_14 ( L_26 ,
V_8 -> V_8 . V_34 ) ;
F_21 ( V_2 ,
V_78 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , 0 ) ;
break;
default:
F_22 ( & V_8 -> V_46 ) ;
break;
}
break;
case V_31 :
switch ( V_137 ) {
case V_159 :
V_13 = F_20 ( V_161 ) ;
V_8 -> V_13 = V_13 ;
F_16 ( V_8 ) ;
V_8 -> V_9 = V_124 ;
V_11 = V_8 -> V_11 ;
F_54 ( V_8 , F_55 ( V_2 ) ) ;
F_22 ( & V_8 -> V_46 ) ;
V_25 |= F_11 ( V_2 ) ;
V_25 |= V_49 ;
F_21 ( V_2 , V_48 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , V_13 ) ;
break;
case V_155 :
V_11 = V_8 -> V_11 ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 ,
V_78 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , 0 ) ;
break;
default:
F_22 ( & V_8 -> V_46 ) ;
break;
}
break;
case V_124 :
switch ( V_137 ) {
case V_159 :
if ( F_56 ( & V_8 -> V_125 ) )
V_8 -> V_117 = 1 ;
F_6 ( V_8 ) ;
F_22 ( & V_8 -> V_46 ) ;
break;
case V_155 :
case V_158 :
case V_152 :
case V_153 :
V_11 = V_8 -> V_11 ;
V_13 = V_8 -> V_13 ;
F_22 ( & V_8 -> V_46 ) ;
F_21 ( V_2 , V_48 ,
V_8 -> V_8 . V_34 , V_11 , V_12 , V_13 ) ;
break;
default:
F_22 ( & V_8 -> V_46 ) ;
}
break;
default:
F_22 ( & V_8 -> V_46 ) ;
break;
}
F_15 () ;
if ( V_25 )
F_23 ( V_2 , V_25 ) ;
}
