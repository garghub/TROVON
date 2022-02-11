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
F_5 ( & V_27 -> V_29 . V_30 , V_35 ) ;
}
static inline enum V_37 F_9 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
struct V_40 * * V_41 )
{
struct V_40 * V_42 ;
V_42 = F_10 ( V_27 -> V_43 . V_44 ) ;
* V_41 = V_42 ;
if ( ! V_42 || V_42 -> V_45 == V_46 )
return V_39 ? V_47 : V_48 ;
if ( V_42 -> V_45 == V_49 )
return V_50 ;
if ( V_42 -> V_45 == V_51 )
return V_52 ;
return V_39 ? V_53 : V_48 ;
}
static inline void F_11 ( struct V_26 * V_27 )
{
V_27 -> V_29 . V_54 = V_27 -> V_55 . V_54 ;
V_27 -> V_29 . V_56 = V_27 -> V_55 . V_56 ;
}
static inline enum V_37 F_12 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
struct V_40 * V_42 )
{
T_2 V_57 ;
V_57 = F_13 ( V_39 -> V_58 , V_42 -> V_59 ) ;
if ( V_57 > 0 ) {
if ( V_42 -> V_45 == V_60 ) {
if ( V_42 -> V_61 & V_62 )
return V_63 ;
F_11 ( V_27 ) ;
return V_50 ;
} else {
return V_47 ;
}
}
V_57 = F_13 ( V_39 -> V_58 , V_27 -> V_29 . V_58 ) ;
if ( V_57 < 0 ) {
if ( V_39 -> V_58 == V_42 -> V_59 )
return V_64 ;
else
return V_47 ;
} else if ( ( V_57 > 0 ) && ( V_42 -> V_61 & V_62 ) ) {
return V_63 ;
} else {
return V_65 ;
}
}
static inline enum V_37 F_14 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
struct V_40 * V_42 )
{
unsigned int V_61 = V_39 -> V_61 ;
T_1 V_66 ;
switch ( V_27 -> V_29 . V_4 ) {
case - 1 :
if ( ! ( V_61 & V_67 ) )
return V_52 ;
break;
case V_68 :
case V_69 :
if ( V_39 -> V_4 != V_69 &&
V_39 -> V_4 != V_70 ) {
return V_52 ;
}
break;
default:
F_15 ( 1 ) ;
}
switch ( V_39 -> V_4 ) {
case V_68 :
case V_70 :
case V_71 :
V_66 = F_16 ( V_39 ) ;
if ( ( V_66 & V_72 ) != V_73 )
return V_52 ;
case V_69 :
if ( V_42 -> V_74 . V_4 != V_11 &&
V_42 -> V_74 . V_4 != V_20 ) {
return V_52 ;
}
F_11 ( V_27 ) ;
return V_75 ;
case V_76 :
V_66 = F_16 ( V_39 ) ;
if ( ( V_66 & V_72 ) != V_73 )
return V_52 ;
if ( V_42 -> V_74 . V_4 != V_13 &&
V_42 -> V_74 . V_4 != V_15 )
return V_52 ;
F_11 ( V_27 ) ;
return V_77 ;
case V_78 :
V_66 = F_16 ( V_39 ) ;
switch ( V_66 & V_72 ) {
case V_73 :
F_11 ( V_27 ) ;
return V_79 ;
case V_80 :
return V_81 ;
case V_82 :
switch ( V_66 ) {
case V_83 :
if ( F_13 ( V_39 -> V_58 , V_27 -> V_29 . V_58 ) > 0 ) {
V_27 -> V_29 . V_58 = V_39 -> V_58 ;
if ( V_27 -> V_84 . V_85 ) {
V_27 -> V_84 . V_85 = 0 ;
F_5 ( & V_27 -> V_84 . V_30 , 1 ) ;
}
}
return V_63 ;
case V_86 :
V_42 -> V_87 = V_88 ;
return V_52 ;
case V_89 :
V_42 -> V_87 = V_90 ;
return V_52 ;
case V_91 :
V_42 -> V_87 = V_92 ;
return V_52 ;
default:
F_17 ( L_1 , V_66 ) ;
V_42 -> V_87 = V_92 ;
return V_52 ;
}
default:
return V_52 ;
}
break;
default:
F_17 ( L_2 ) ;
}
return V_52 ;
}
static inline enum V_37 F_18 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
struct V_40 * V_42 )
{
struct V_31 * V_32 = F_19 ( V_27 -> V_93 . V_94 ) ;
int V_95 ;
V_95 = F_20 ( V_32 , V_27 -> V_96 , V_97 ,
& V_42 -> V_98 , F_21 ( V_39 ) ,
F_22 ( V_39 ) , V_99 , NULL ) ;
if ( V_95 )
return V_52 ;
if ( V_42 -> V_98 . V_100 == 0 && ( V_39 -> V_61 & V_101 ) )
return V_64 ;
else
return V_102 ;
}
static inline enum V_37 F_23 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
struct V_40 * V_42 )
{
struct V_31 * V_32 = F_19 ( V_27 -> V_93 . V_94 ) ;
int V_95 ;
T_3 V_103 = F_24 ( V_39 ) ;
V_95 = F_20 ( V_32 , V_27 -> V_96 , V_97 ,
& V_42 -> V_98 , & V_103 ,
sizeof( T_3 ) , V_99 , NULL ) ;
if ( V_95 )
return V_52 ;
else
return V_64 ;
}
static void F_25 ( struct V_26 * V_27 , struct V_40 * V_42 ,
struct V_104 * V_105 )
{
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
if ( ! V_27 -> V_106 ) {
struct V_107 * V_108 = & V_105 -> V_109 ;
V_108 -> V_110 = V_42 -> V_74 . V_110 ;
V_108 -> V_87 = V_42 -> V_87 ;
V_108 -> V_4 = F_3 ( V_42 -> V_74 . V_4 ) ;
if ( V_42 -> V_74 . V_4 == V_7 ||
V_42 -> V_74 . V_4 == V_10 )
V_108 -> V_111 = V_112 ;
V_108 -> V_113 = V_42 -> V_98 . V_114 ;
V_108 -> V_27 = & V_27 -> V_93 ;
} else {
struct V_115 * V_116 = & V_105 -> V_117 ;
V_116 -> V_110 = V_42 -> V_74 . V_110 ;
V_116 -> V_87 = V_42 -> V_87 ;
V_116 -> V_4 = F_3 ( V_42 -> V_74 . V_4 ) ;
if ( V_42 -> V_74 . V_4 == V_7 ||
V_42 -> V_74 . V_4 == V_10 )
V_116 -> V_111 = V_112 ;
V_116 -> V_113 = V_42 -> V_98 . V_114 ;
V_116 -> V_118 = V_27 -> V_93 . V_118 ;
}
}
static void F_26 ( struct V_26 * V_27 , struct V_40 * V_42 )
{
struct V_104 V_105 ;
if ( ( V_27 -> V_119 == V_120 ) ||
( V_42 -> V_74 . V_121 & V_122 ) ||
( V_27 -> V_84 . V_45 == V_123 ) ) {
F_25 ( V_27 , V_42 , & V_105 ) ;
F_27 ( V_27 -> V_124 , & V_105 , 0 ) ;
}
F_28 ( V_27 -> V_43 . V_44 ) ;
if ( V_27 -> V_84 . V_125 ) {
V_27 -> V_84 . V_125 = 0 ;
F_5 ( & V_27 -> V_84 . V_30 , 1 ) ;
}
}
static inline enum V_37 F_29 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
struct V_40 * V_42 )
{
unsigned long V_126 ;
if ( V_42 -> V_127 ) {
V_42 -> V_127 = 0 ;
F_30 ( & V_27 -> V_84 . V_128 ) ;
if ( V_27 -> V_84 . V_129 ) {
V_27 -> V_29 . V_130 = 0 ;
V_27 -> V_84 . V_129 = 0 ;
F_5 ( & V_27 -> V_84 . V_30 , 1 ) ;
}
}
if ( F_31 ( V_27 -> V_84 . V_45 == V_131 ) ) {
F_32 ( & V_27 -> V_132 , V_126 ) ;
if ( ( V_27 -> V_84 . V_45 == V_131 ) &&
( V_27 -> V_29 . V_58 == V_27 -> V_84 . V_58 ) ) {
V_27 -> V_84 . V_45 = V_133 ;
F_33 ( & V_27 -> V_132 , V_126 ) ;
if ( V_27 -> V_93 . V_134 ) {
struct V_135 V_136 ;
V_136 . V_94 = V_27 -> V_93 . V_94 ;
V_136 . V_137 . V_27 = & V_27 -> V_93 ;
V_136 . V_138 = V_139 ;
V_27 -> V_93 . V_134 ( & V_136 ,
V_27 -> V_93 . V_140 ) ;
}
} else {
F_33 ( & V_27 -> V_132 , V_126 ) ;
}
}
F_26 ( V_27 , V_42 ) ;
if ( F_13 ( V_39 -> V_58 , V_27 -> V_29 . V_58 ) >= 0 )
return V_102 ;
else
return V_47 ;
}
static inline enum V_37 F_34 ( struct V_26 * V_27 ,
struct V_38 * V_39 ,
struct V_40 * V_42 )
{
V_27 -> V_29 . V_4 = - 1 ;
if ( V_39 ) {
if ( F_13 ( V_39 -> V_58 , V_27 -> V_29 . V_58 ) >= 0 )
V_27 -> V_29 . V_58 = ( V_39 -> V_58 + 1 ) & V_141 ;
if ( V_27 -> V_84 . V_85 ) {
V_27 -> V_84 . V_85 = 0 ;
F_5 ( & V_27 -> V_84 . V_30 , 1 ) ;
}
}
F_26 ( V_27 , V_42 ) ;
return V_142 ;
}
int F_35 ( void * V_143 )
{
struct V_26 * V_27 = (struct V_26 * ) V_143 ;
struct V_40 * V_42 = V_42 ;
struct V_33 * V_34 = NULL ;
struct V_38 * V_39 = NULL ;
enum V_37 V_45 ;
if ( ! V_27 -> V_28 ) {
while ( ( V_34 = F_36 ( & V_27 -> V_36 ) ) ) {
F_37 ( V_27 ) ;
F_38 ( V_34 ) ;
}
V_34 = NULL ;
V_39 = NULL ;
while ( F_10 ( V_27 -> V_43 . V_44 ) )
F_28 ( V_27 -> V_43 . V_44 ) ;
goto exit;
}
if ( V_27 -> V_84 . V_45 == V_123 ) {
while ( ( V_34 = F_36 ( & V_27 -> V_36 ) ) ) {
F_37 ( V_27 ) ;
F_38 ( V_34 ) ;
}
V_34 = NULL ;
V_39 = NULL ;
while ( ( V_42 = F_10 ( V_27 -> V_43 . V_44 ) ) ) {
V_42 -> V_87 = V_144 ;
F_26 ( V_27 , V_42 ) ;
}
goto exit;
}
if ( V_27 -> V_84 . V_45 == V_145 ) {
while ( ( V_34 = F_36 ( & V_27 -> V_36 ) ) ) {
F_37 ( V_27 ) ;
F_38 ( V_34 ) ;
}
V_34 = NULL ;
V_39 = NULL ;
while ( F_10 ( V_27 -> V_43 . V_44 ) )
F_28 ( V_27 -> V_43 . V_44 ) ;
goto exit;
}
if ( V_27 -> V_29 . V_1 ) {
V_27 -> V_29 . V_130 = 1 ;
V_27 -> V_29 . V_1 = 0 ;
} else {
V_27 -> V_29 . V_130 = 0 ;
}
if ( V_27 -> V_84 . V_146 )
goto exit;
V_45 = V_147 ;
while ( 1 ) {
F_39 ( L_3 , V_148 [ V_45 ] ) ;
switch ( V_45 ) {
case V_147 :
V_34 = F_36 ( & V_27 -> V_36 ) ;
if ( V_34 ) {
V_39 = F_40 ( V_34 ) ;
V_27 -> V_29 . V_130 = 0 ;
}
V_45 = V_142 ;
break;
case V_142 :
V_45 = F_9 ( V_27 , V_39 , & V_42 ) ;
break;
case V_53 :
V_45 = F_12 ( V_27 , V_39 , V_42 ) ;
break;
case V_65 :
V_45 = F_14 ( V_27 , V_39 , V_42 ) ;
break;
case V_75 :
V_45 = F_18 ( V_27 , V_39 , V_42 ) ;
break;
case V_77 :
V_45 = F_23 ( V_27 , V_39 , V_42 ) ;
break;
case V_79 :
if ( V_42 -> V_45 == V_60 &&
V_42 -> V_59 == V_39 -> V_58 )
V_45 = V_64 ;
else
V_45 = V_102 ;
break;
case V_64 :
V_45 = F_29 ( V_27 , V_39 , V_42 ) ;
break;
case V_50 :
V_45 = F_34 ( V_27 , V_39 , V_42 ) ;
break;
case V_102 :
if ( V_39 -> V_61 & V_101 )
V_27 -> V_29 . V_4 = - 1 ;
else
V_27 -> V_29 . V_4 = V_39 -> V_4 ;
if ( F_13 ( V_39 -> V_58 , V_27 -> V_29 . V_58 ) >= 0 )
V_27 -> V_29 . V_58 = ( V_39 -> V_58 + 1 ) & V_141 ;
if ( V_27 -> V_84 . V_85 ) {
V_27 -> V_84 . V_85 = 0 ;
F_5 ( & V_27 -> V_84 . V_30 , 1 ) ;
}
V_45 = V_47 ;
break;
case V_47 :
if ( V_39 ) {
F_37 ( V_39 -> V_27 ) ;
F_38 ( V_34 ) ;
}
goto V_149;
case V_48 :
if ( V_27 -> V_29 . V_130 && V_42 ) {
V_45 = V_63 ;
break;
}
if ( ( F_41 ( V_27 ) == V_150 ) &&
( V_27 -> V_84 . V_45 == V_151 ) &&
( F_13 ( V_27 -> V_84 . V_58 , V_27 -> V_29 . V_58 ) > 0 ) &&
V_27 -> V_152 )
F_42 ( & V_27 -> V_153 ,
V_154 + V_27 -> V_152 ) ;
goto exit;
case V_63 :
if ( ! V_42 || ( V_42 -> V_45 == V_46 ) )
goto exit;
if ( V_27 -> V_29 . V_54 > 0 ) {
if ( V_27 -> V_29 . V_54 != 7 )
V_27 -> V_29 . V_54 -- ;
if ( F_13 ( V_27 -> V_84 . V_58 ,
V_27 -> V_29 . V_58 ) > 0 ) {
V_27 -> V_84 . V_146 = 1 ;
F_5 ( & V_27 -> V_84 . V_30 , 1 ) ;
}
if ( V_39 ) {
F_37 ( V_39 -> V_27 ) ;
F_38 ( V_34 ) ;
}
goto exit;
} else {
V_42 -> V_87 = V_155 ;
V_45 = V_52 ;
}
break;
case V_81 :
if ( V_27 -> V_29 . V_56 > 0 ) {
if ( V_27 -> V_29 . V_56 != 7 )
V_27 -> V_29 . V_56 -- ;
V_27 -> V_84 . V_146 = 1 ;
F_39 ( L_4 ) ;
F_42 ( & V_27 -> V_156 ,
V_154 + F_1 ( F_16 ( V_39 )
& ~ V_72 ) ) ;
goto exit;
} else {
V_42 -> V_87 = V_157 ;
V_45 = V_52 ;
}
break;
case V_52 :
F_26 ( V_27 , V_42 ) ;
F_43 ( V_27 ) ;
if ( V_39 ) {
F_37 ( V_39 -> V_27 ) ;
F_38 ( V_34 ) ;
}
goto exit;
}
}
exit:
return - V_158 ;
V_149:
return 0 ;
}
