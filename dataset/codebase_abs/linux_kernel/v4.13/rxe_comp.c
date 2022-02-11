static inline unsigned long F_1 ( T_1 V_1 )
{
return F_2 (unsigned long,
usecs_to_jiffies(rnrnak_usec[timeout]), 1 ) ;
}
static enum V_2 F_3 ( enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 : return V_6 ;
case V_7 : return V_6 ;
case V_8 : return V_9 ;
case V_10 : return V_9 ;
case V_11 : return V_12 ;
case V_13 : return V_14 ;
case V_15 : return V_16 ;
case V_17 : return V_18 ;
case V_19 : return V_9 ;
case V_20 : return V_12 ;
case V_21 : return V_22 ;
case V_23 : return V_24 ;
default:
return 0xff ;
}
}
void F_4 ( unsigned long V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_25 ;
if ( V_27 -> V_28 ) {
V_27 -> V_29 . V_1 = 1 ;
F_5 ( & V_27 -> V_29 . V_30 , 1 ) ;
}
}
void F_6 ( struct V_31 * V_32 , struct V_26 * V_27 ,
struct V_33 * V_34 )
{
int V_35 ;
F_7 ( & V_27 -> V_36 , V_34 ) ;
V_35 = F_8 ( & V_27 -> V_36 ) > 1 ;
if ( V_35 != 0 )
F_9 ( V_32 , V_37 ) ;
F_5 ( & V_27 -> V_29 . V_30 , V_35 ) ;
}
static inline enum V_38 F_10 ( struct V_26 * V_27 ,
struct V_39 * V_40 ,
struct V_41 * * V_42 )
{
struct V_41 * V_43 ;
V_43 = F_11 ( V_27 -> V_44 . V_45 ) ;
* V_42 = V_43 ;
if ( ! V_43 || V_43 -> V_46 == V_47 )
return V_40 ? V_48 : V_49 ;
if ( V_43 -> V_46 == V_50 )
return V_51 ;
if ( V_43 -> V_46 == V_52 )
return V_53 ;
return V_40 ? V_54 : V_49 ;
}
static inline void F_12 ( struct V_26 * V_27 )
{
V_27 -> V_29 . V_55 = V_27 -> V_56 . V_55 ;
V_27 -> V_29 . V_57 = V_27 -> V_56 . V_57 ;
}
static inline enum V_38 F_13 ( struct V_26 * V_27 ,
struct V_39 * V_40 ,
struct V_41 * V_43 )
{
T_2 V_58 ;
V_58 = F_14 ( V_40 -> V_59 , V_43 -> V_60 ) ;
if ( V_58 > 0 ) {
if ( V_43 -> V_46 == V_61 ) {
if ( V_43 -> V_62 & V_63 )
return V_64 ;
F_12 ( V_27 ) ;
return V_51 ;
} else {
return V_48 ;
}
}
V_58 = F_14 ( V_40 -> V_59 , V_27 -> V_29 . V_59 ) ;
if ( V_58 < 0 ) {
if ( V_40 -> V_59 == V_43 -> V_60 )
return V_65 ;
else
return V_48 ;
} else if ( ( V_58 > 0 ) && ( V_43 -> V_62 & V_63 ) ) {
return V_48 ;
} else {
return V_66 ;
}
}
static inline enum V_38 F_15 ( struct V_26 * V_27 ,
struct V_39 * V_40 ,
struct V_41 * V_43 )
{
unsigned int V_62 = V_40 -> V_62 ;
T_1 V_67 ;
struct V_31 * V_32 = F_16 ( V_27 -> V_68 . V_69 ) ;
switch ( V_27 -> V_29 . V_4 ) {
case - 1 :
if ( ! ( V_62 & V_70 ) )
return V_53 ;
break;
case V_71 :
case V_72 :
if ( V_40 -> V_4 != V_72 &&
V_40 -> V_4 != V_73 ) {
return V_53 ;
}
break;
default:
F_17 ( 1 ) ;
}
switch ( V_40 -> V_4 ) {
case V_71 :
case V_73 :
case V_74 :
V_67 = F_18 ( V_40 ) ;
if ( ( V_67 & V_75 ) != V_76 )
return V_53 ;
case V_72 :
if ( V_43 -> V_77 . V_4 != V_11 &&
V_43 -> V_77 . V_4 != V_20 ) {
return V_53 ;
}
F_12 ( V_27 ) ;
return V_78 ;
case V_79 :
V_67 = F_18 ( V_40 ) ;
if ( ( V_67 & V_75 ) != V_76 )
return V_53 ;
if ( V_43 -> V_77 . V_4 != V_13 &&
V_43 -> V_77 . V_4 != V_15 )
return V_53 ;
F_12 ( V_27 ) ;
return V_80 ;
case V_81 :
V_67 = F_18 ( V_40 ) ;
switch ( V_67 & V_75 ) {
case V_76 :
F_12 ( V_27 ) ;
return V_82 ;
case V_83 :
F_9 ( V_32 , V_84 ) ;
return V_85 ;
case V_86 :
switch ( V_67 ) {
case V_87 :
if ( F_14 ( V_40 -> V_59 , V_27 -> V_29 . V_59 ) > 0 ) {
F_9 ( V_32 ,
V_88 ) ;
V_27 -> V_29 . V_59 = V_40 -> V_59 ;
if ( V_27 -> V_89 . V_90 ) {
V_27 -> V_89 . V_90 = 0 ;
F_5 ( & V_27 -> V_89 . V_30 , 1 ) ;
}
}
return V_64 ;
case V_91 :
V_43 -> V_92 = V_93 ;
return V_53 ;
case V_94 :
V_43 -> V_92 = V_95 ;
return V_53 ;
case V_96 :
V_43 -> V_92 = V_97 ;
return V_53 ;
default:
F_19 ( L_1 , V_67 ) ;
V_43 -> V_92 = V_97 ;
return V_53 ;
}
default:
return V_53 ;
}
break;
default:
F_19 ( L_2 ) ;
}
return V_53 ;
}
static inline enum V_38 F_20 ( struct V_26 * V_27 ,
struct V_39 * V_40 ,
struct V_41 * V_43 )
{
struct V_31 * V_32 = F_16 ( V_27 -> V_68 . V_69 ) ;
int V_98 ;
V_98 = F_21 ( V_32 , V_27 -> V_99 , V_100 ,
& V_43 -> V_101 , F_22 ( V_40 ) ,
F_23 ( V_40 ) , V_102 , NULL ) ;
if ( V_98 )
return V_53 ;
if ( V_43 -> V_101 . V_103 == 0 && ( V_40 -> V_62 & V_104 ) )
return V_65 ;
else
return V_105 ;
}
static inline enum V_38 F_24 ( struct V_26 * V_27 ,
struct V_39 * V_40 ,
struct V_41 * V_43 )
{
struct V_31 * V_32 = F_16 ( V_27 -> V_68 . V_69 ) ;
int V_98 ;
T_3 V_106 = F_25 ( V_40 ) ;
V_98 = F_21 ( V_32 , V_27 -> V_99 , V_100 ,
& V_43 -> V_101 , & V_106 ,
sizeof( T_3 ) , V_102 , NULL ) ;
if ( V_98 )
return V_53 ;
else
return V_65 ;
}
static void F_26 ( struct V_26 * V_27 , struct V_41 * V_43 ,
struct V_107 * V_108 )
{
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
if ( ! V_27 -> V_109 ) {
struct V_110 * V_111 = & V_108 -> V_112 ;
V_111 -> V_113 = V_43 -> V_77 . V_113 ;
V_111 -> V_92 = V_43 -> V_92 ;
V_111 -> V_4 = F_3 ( V_43 -> V_77 . V_4 ) ;
if ( V_43 -> V_77 . V_4 == V_7 ||
V_43 -> V_77 . V_4 == V_10 )
V_111 -> V_114 = V_115 ;
V_111 -> V_116 = V_43 -> V_101 . V_117 ;
V_111 -> V_27 = & V_27 -> V_68 ;
} else {
struct V_118 * V_119 = & V_108 -> V_120 ;
V_119 -> V_113 = V_43 -> V_77 . V_113 ;
V_119 -> V_92 = V_43 -> V_92 ;
V_119 -> V_4 = F_3 ( V_43 -> V_77 . V_4 ) ;
if ( V_43 -> V_77 . V_4 == V_7 ||
V_43 -> V_77 . V_4 == V_10 )
V_119 -> V_114 = V_115 ;
V_119 -> V_116 = V_43 -> V_101 . V_117 ;
V_119 -> V_121 = V_27 -> V_68 . V_121 ;
}
}
static void F_27 ( struct V_26 * V_27 , struct V_41 * V_43 )
{
struct V_107 V_108 ;
if ( ( V_27 -> V_122 == V_123 ) ||
( V_43 -> V_77 . V_124 & V_125 ) ||
V_43 -> V_92 != V_126 ) {
F_26 ( V_27 , V_43 , & V_108 ) ;
F_28 ( V_27 -> V_44 . V_45 ) ;
F_29 ( V_27 -> V_127 , & V_108 , 0 ) ;
} else {
F_28 ( V_27 -> V_44 . V_45 ) ;
}
if ( V_27 -> V_89 . V_128 ) {
V_27 -> V_89 . V_128 = 0 ;
F_5 ( & V_27 -> V_89 . V_30 , 1 ) ;
}
}
static inline enum V_38 F_30 ( struct V_26 * V_27 ,
struct V_39 * V_40 ,
struct V_41 * V_43 )
{
unsigned long V_129 ;
if ( V_43 -> V_130 ) {
V_43 -> V_130 = 0 ;
F_31 ( & V_27 -> V_89 . V_131 ) ;
if ( V_27 -> V_89 . V_132 ) {
V_27 -> V_29 . V_133 = 0 ;
V_27 -> V_89 . V_132 = 0 ;
F_5 ( & V_27 -> V_89 . V_30 , 1 ) ;
}
}
if ( F_32 ( V_27 -> V_89 . V_46 == V_134 ) ) {
F_33 ( & V_27 -> V_135 , V_129 ) ;
if ( ( V_27 -> V_89 . V_46 == V_134 ) &&
( V_27 -> V_29 . V_59 == V_27 -> V_89 . V_59 ) ) {
V_27 -> V_89 . V_46 = V_136 ;
F_34 ( & V_27 -> V_135 , V_129 ) ;
if ( V_27 -> V_68 . V_137 ) {
struct V_138 V_139 ;
V_139 . V_69 = V_27 -> V_68 . V_69 ;
V_139 . V_140 . V_27 = & V_27 -> V_68 ;
V_139 . V_141 = V_142 ;
V_27 -> V_68 . V_137 ( & V_139 ,
V_27 -> V_68 . V_143 ) ;
}
} else {
F_34 ( & V_27 -> V_135 , V_129 ) ;
}
}
F_27 ( V_27 , V_43 ) ;
if ( F_14 ( V_40 -> V_59 , V_27 -> V_29 . V_59 ) >= 0 )
return V_105 ;
else
return V_48 ;
}
static inline enum V_38 F_35 ( struct V_26 * V_27 ,
struct V_39 * V_40 ,
struct V_41 * V_43 )
{
V_27 -> V_29 . V_4 = - 1 ;
if ( V_40 ) {
if ( F_14 ( V_40 -> V_59 , V_27 -> V_29 . V_59 ) >= 0 )
V_27 -> V_29 . V_59 = ( V_40 -> V_59 + 1 ) & V_144 ;
if ( V_27 -> V_89 . V_90 ) {
V_27 -> V_89 . V_90 = 0 ;
F_5 ( & V_27 -> V_89 . V_30 , 1 ) ;
}
}
F_27 ( V_27 , V_43 ) ;
return V_145 ;
}
static void F_36 ( struct V_26 * V_27 , bool V_146 )
{
struct V_33 * V_34 ;
struct V_41 * V_43 ;
while ( ( V_34 = F_37 ( & V_27 -> V_36 ) ) ) {
F_38 ( V_27 ) ;
F_39 ( V_34 ) ;
}
while ( ( V_43 = F_11 ( V_27 -> V_44 . V_45 ) ) ) {
if ( V_146 ) {
V_43 -> V_92 = V_147 ;
F_27 ( V_27 , V_43 ) ;
} else {
F_28 ( V_27 -> V_44 . V_45 ) ;
}
}
}
int F_40 ( void * V_148 )
{
struct V_26 * V_27 = (struct V_26 * ) V_148 ;
struct V_31 * V_32 = F_16 ( V_27 -> V_68 . V_69 ) ;
struct V_41 * V_43 = V_43 ;
struct V_33 * V_34 = NULL ;
struct V_39 * V_40 = NULL ;
enum V_38 V_46 ;
F_41 ( V_27 ) ;
if ( ! V_27 -> V_28 || V_27 -> V_89 . V_46 == V_149 ||
V_27 -> V_89 . V_46 == V_150 ) {
F_36 ( V_27 , V_27 -> V_28 &&
V_27 -> V_89 . V_46 == V_149 ) ;
goto exit;
}
if ( V_27 -> V_29 . V_1 ) {
V_27 -> V_29 . V_133 = 1 ;
V_27 -> V_29 . V_1 = 0 ;
} else {
V_27 -> V_29 . V_133 = 0 ;
}
if ( V_27 -> V_89 . V_151 )
goto exit;
V_46 = V_152 ;
while ( 1 ) {
F_42 ( L_3 , V_121 ( V_27 ) ,
V_153 [ V_46 ] ) ;
switch ( V_46 ) {
case V_152 :
V_34 = F_37 ( & V_27 -> V_36 ) ;
if ( V_34 ) {
V_40 = F_43 ( V_34 ) ;
V_27 -> V_29 . V_133 = 0 ;
}
V_46 = V_145 ;
break;
case V_145 :
V_46 = F_10 ( V_27 , V_40 , & V_43 ) ;
break;
case V_54 :
V_46 = F_13 ( V_27 , V_40 , V_43 ) ;
break;
case V_66 :
V_46 = F_15 ( V_27 , V_40 , V_43 ) ;
break;
case V_78 :
V_46 = F_20 ( V_27 , V_40 , V_43 ) ;
break;
case V_80 :
V_46 = F_24 ( V_27 , V_40 , V_43 ) ;
break;
case V_82 :
if ( V_43 -> V_46 == V_61 &&
V_43 -> V_60 == V_40 -> V_59 )
V_46 = V_65 ;
else
V_46 = V_105 ;
break;
case V_65 :
V_46 = F_30 ( V_27 , V_40 , V_43 ) ;
break;
case V_51 :
V_46 = F_35 ( V_27 , V_40 , V_43 ) ;
break;
case V_105 :
if ( V_40 -> V_62 & V_104 )
V_27 -> V_29 . V_4 = - 1 ;
else
V_27 -> V_29 . V_4 = V_40 -> V_4 ;
if ( F_14 ( V_40 -> V_59 , V_27 -> V_29 . V_59 ) >= 0 )
V_27 -> V_29 . V_59 = ( V_40 -> V_59 + 1 ) & V_144 ;
if ( V_27 -> V_89 . V_90 ) {
V_27 -> V_89 . V_90 = 0 ;
F_5 ( & V_27 -> V_89 . V_30 , 1 ) ;
}
V_46 = V_48 ;
break;
case V_48 :
if ( V_40 ) {
F_38 ( V_40 -> V_27 ) ;
F_39 ( V_34 ) ;
V_34 = NULL ;
}
goto V_154;
case V_49 :
if ( V_27 -> V_29 . V_133 && V_43 ) {
V_46 = V_64 ;
break;
}
if ( ( F_44 ( V_27 ) == V_155 ) &&
( V_27 -> V_89 . V_46 == V_156 ) &&
( F_14 ( V_27 -> V_89 . V_59 , V_27 -> V_29 . V_59 ) > 0 ) &&
V_27 -> V_157 )
F_45 ( & V_27 -> V_158 ,
V_159 + V_27 -> V_157 ) ;
F_17 ( V_34 ) ;
goto exit;
case V_64 :
if ( ! V_43 || ( V_43 -> V_46 == V_47 ) ) {
F_17 ( V_34 ) ;
goto exit;
}
if ( V_27 -> V_29 . V_55 > 0 ) {
if ( V_27 -> V_29 . V_55 != 7 )
V_27 -> V_29 . V_55 -- ;
if ( F_14 ( V_27 -> V_89 . V_59 ,
V_27 -> V_29 . V_59 ) > 0 ) {
F_9 ( V_32 ,
V_160 ) ;
V_27 -> V_89 . V_151 = 1 ;
F_5 ( & V_27 -> V_89 . V_30 , 1 ) ;
}
if ( V_40 ) {
F_38 ( V_40 -> V_27 ) ;
F_39 ( V_34 ) ;
V_34 = NULL ;
}
F_17 ( V_34 ) ;
goto exit;
} else {
F_9 ( V_32 , V_161 ) ;
V_43 -> V_92 = V_162 ;
V_46 = V_53 ;
}
break;
case V_85 :
if ( V_27 -> V_29 . V_57 > 0 ) {
if ( V_27 -> V_29 . V_57 != 7 )
V_27 -> V_29 . V_57 -- ;
V_27 -> V_89 . V_151 = 1 ;
F_42 ( L_4 ,
V_121 ( V_27 ) ) ;
F_45 ( & V_27 -> V_163 ,
V_159 + F_1 ( F_18 ( V_40 )
& ~ V_75 ) ) ;
F_38 ( V_40 -> V_27 ) ;
F_39 ( V_34 ) ;
V_34 = NULL ;
goto exit;
} else {
F_9 ( V_32 ,
V_164 ) ;
V_43 -> V_92 = V_165 ;
V_46 = V_53 ;
}
break;
case V_53 :
F_17 ( V_43 -> V_92 == V_126 ) ;
F_27 ( V_27 , V_43 ) ;
F_46 ( V_27 ) ;
if ( V_40 ) {
F_38 ( V_40 -> V_27 ) ;
F_39 ( V_34 ) ;
V_34 = NULL ;
}
F_17 ( V_34 ) ;
goto exit;
}
}
exit:
F_17 ( V_34 ) ;
F_38 ( V_27 ) ;
return - V_166 ;
V_154:
F_17 ( V_34 ) ;
F_38 ( V_27 ) ;
return 0 ;
}
