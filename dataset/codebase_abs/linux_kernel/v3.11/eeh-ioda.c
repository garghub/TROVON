static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
T_1 V_5 = ( T_1 ) V_4 ;
if ( ( V_5 & V_6 ) &&
( V_3 & V_6 ) )
F_2 ( NULL ) ;
return 0 ;
}
static int F_3 ( void * V_7 , T_2 V_8 )
{
struct V_9 * V_10 = V_7 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_4 ( V_12 -> V_14 + 0xD10 , V_8 ) ;
return 0 ;
}
static int F_5 ( void * V_7 , T_2 * V_8 )
{
struct V_9 * V_10 = V_7 ;
struct V_11 * V_12 = V_10 -> V_13 ;
* V_8 = F_6 ( V_12 -> V_14 + 0xD10 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_15 ;
if ( ! V_16 ) {
V_15 = F_8 ( & V_17 ) ;
if ( V_15 ) {
F_9 ( L_1 ,
V_18 , V_15 ) ;
return V_15 ;
}
V_16 = 1 ;
}
if ( V_12 -> type == V_19 ) {
if ( ! V_20 ) {
V_20 = ( char * ) F_10 ( V_21 |
V_22 ) ;
if ( ! V_20 ) {
F_9 ( L_2 ,
V_18 ) ;
return - V_23 ;
}
}
#ifdef F_11
if ( V_12 -> V_24 )
F_12 ( L_3 , 0600 ,
V_12 -> V_24 , V_10 ,
& V_25 ) ;
#endif
V_12 -> V_26 |= V_27 ;
}
return 0 ;
}
static int F_13 ( struct V_28 * V_29 , int V_30 )
{
T_3 V_15 ;
T_4 V_31 ;
struct V_9 * V_10 = V_29 -> V_12 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_29 -> V_32 < 0 || V_29 -> V_32 >= V_12 -> V_33 . V_34 ) {
F_9 ( L_4
L_5 ,
V_18 , V_29 -> V_32 , V_12 -> V_33 . V_34 ,
V_10 -> V_35 ) ;
return - V_36 ;
}
V_31 = V_29 -> V_32 ;
switch ( V_30 ) {
case V_37 :
V_15 = - V_38 ;
break;
case V_39 :
V_15 = 0 ;
break;
case V_40 :
V_15 = F_14 ( V_12 -> V_41 , V_31 ,
V_42 ) ;
if ( V_15 ) {
F_15 ( L_6
L_7 ,
V_18 , V_10 -> V_35 , V_31 , V_15 ) ;
return - V_43 ;
}
break;
case V_44 :
V_15 = F_14 ( V_12 -> V_41 , V_31 ,
V_45 ) ;
if ( V_15 ) {
F_15 ( L_8
L_7 ,
V_18 , V_10 -> V_35 , V_31 , V_15 ) ;
return - V_43 ;
}
break;
default:
F_15 ( L_9 , V_18 , V_30 ) ;
return - V_36 ;
}
return V_15 ;
}
static int F_16 ( struct V_28 * V_29 )
{
T_3 V_15 = 0 ;
T_5 V_46 ;
T_6 V_47 ;
T_4 V_31 ;
int V_48 ;
struct V_9 * V_10 = V_29 -> V_12 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_29 -> V_32 < 0 || V_29 -> V_32 >= V_12 -> V_33 . V_34 ) {
F_9 ( L_4
L_5 ,
V_18 , V_29 -> V_32 , V_12 -> V_33 . V_34 ,
V_10 -> V_35 ) ;
return V_49 ;
}
V_31 = V_29 -> V_32 ;
V_15 = F_17 ( V_12 -> V_41 , V_31 ,
& V_46 , & V_47 , NULL ) ;
if ( V_15 ) {
F_9 ( L_10
L_11 ,
V_18 , V_10 -> V_35 , V_31 , V_15 ) ;
return V_49 ;
}
if ( V_29 -> type & V_50 ) {
V_48 = 0 ;
V_48 &= ~ V_51 ;
if ( V_47 != V_52 ) {
V_48 |= V_53 ;
V_48 |= V_54 ;
V_48 |= V_55 ;
V_48 |= V_56 ;
}
return V_48 ;
}
V_48 = 0 ;
switch ( V_46 ) {
case V_57 :
V_48 &= ~ V_51 ;
V_48 |= V_53 ;
V_48 |= V_54 ;
V_48 |= V_55 ;
V_48 |= V_56 ;
break;
case V_58 :
V_48 &= ~ V_51 ;
V_48 |= V_54 ;
V_48 |= V_56 ;
break;
case V_59 :
V_48 &= ~ V_51 ;
V_48 |= V_53 ;
V_48 |= V_55 ;
break;
case V_60 :
V_48 &= ~ V_51 ;
break;
case V_61 :
V_48 |= V_51 ;
break;
case V_62 :
V_48 |= V_63 ;
break;
case V_64 :
V_48 |= V_49 ;
break;
default:
F_15 ( L_12
L_13 ,
V_18 , V_46 , V_10 -> V_35 , V_31 ) ;
}
return V_48 ;
}
static int F_18 ( struct V_28 * V_29 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
T_4 V_31 ;
T_5 V_46 ;
T_6 V_47 ;
T_3 V_15 ;
V_31 = V_29 -> V_32 ;
V_10 = V_29 -> V_12 ;
V_12 = V_29 -> V_12 -> V_13 ;
V_15 = F_14 ( V_12 -> V_41 ,
V_31 , V_65 ) ;
if ( V_15 ) {
F_9 ( L_14
L_7 ,
V_18 , V_10 -> V_35 , V_31 , V_15 ) ;
return - V_43 ;
}
V_15 = F_17 ( V_12 -> V_41 , V_31 ,
& V_46 , & V_47 , NULL ) ;
if ( V_15 ) {
F_9 ( L_10
L_11 ,
V_18 , V_10 -> V_35 , V_31 , V_15 ) ;
return - V_43 ;
}
if ( V_46 != V_57 ) {
F_9 ( L_15
L_16 ,
V_18 , V_10 -> V_35 , V_31 , V_46 ) ;
return - V_43 ;
}
return 0 ;
}
static T_3 F_19 ( struct V_11 * V_12 )
{
T_3 V_66 = V_67 ;
while ( 1 ) {
V_66 = F_20 ( V_12 -> V_41 ) ;
if ( V_66 <= 0 )
break;
F_21 ( V_66 ) ;
}
return V_66 ;
}
static int F_22 ( struct V_9 * V_10 , int V_30 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_3 V_66 = V_67 ;
F_23 ( L_17 ,
V_18 , V_10 -> V_35 , V_30 ) ;
if ( V_30 == V_68 ||
V_30 == V_69 )
V_66 = F_24 ( V_12 -> V_41 ,
V_70 ,
V_71 ) ;
else if ( V_30 == V_72 )
V_66 = F_24 ( V_12 -> V_41 ,
V_70 ,
V_73 ) ;
if ( V_66 < 0 )
goto V_74;
V_66 = F_19 ( V_12 ) ;
V_74:
if ( V_66 != V_75 )
return - V_43 ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 , int V_30 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_3 V_66 = V_75 ;
F_23 ( L_17 ,
V_18 , V_10 -> V_35 , V_30 ) ;
if ( V_30 == V_68 )
V_66 = F_24 ( V_12 -> V_41 ,
V_76 ,
V_71 ) ;
else if ( V_30 == V_69 )
V_66 = F_24 ( V_12 -> V_41 ,
V_77 ,
V_71 ) ;
else if ( V_30 == V_72 )
V_66 = F_24 ( V_12 -> V_41 ,
V_77 ,
V_73 ) ;
if ( V_66 < 0 )
goto V_74;
V_66 = F_19 ( V_12 ) ;
V_74:
if ( V_66 != V_75 )
return - V_43 ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
struct V_78 * V_79 , int V_30 )
{
T_6 V_80 ;
F_23 ( L_18 ,
V_18 , V_10 -> V_35 , V_79 -> V_81 -> V_82 ,
F_27 ( V_79 -> V_83 ) , F_28 ( V_79 -> V_83 ) , V_30 ) ;
switch ( V_30 ) {
case V_68 :
case V_69 :
F_29 ( V_79 , V_84 , & V_80 ) ;
V_80 |= V_85 ;
F_30 ( V_79 , V_84 , V_80 ) ;
break;
case V_72 :
F_29 ( V_79 , V_84 , & V_80 ) ;
V_80 &= ~ V_85 ;
F_30 ( V_79 , V_84 , V_80 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_28 * V_29 , int V_30 )
{
struct V_9 * V_10 = V_29 -> V_12 ;
struct V_86 * V_87 ;
struct V_78 * V_79 ;
int V_15 ;
if ( ! ( V_29 -> type & V_50 ) &&
( V_30 == V_69 ||
V_30 == V_68 ) ) {
V_15 = F_18 ( V_29 ) ;
if ( V_15 )
return - V_43 ;
}
if ( V_29 -> type & V_50 ) {
V_15 = F_22 ( V_10 , V_30 ) ;
} else {
if ( V_29 -> type & V_88 ) {
V_87 = F_32 ( & V_29 -> V_89 ,
struct V_86 , V_90 ) ;
V_79 = F_33 ( V_87 ) ;
V_79 = V_79 -> V_81 -> V_91 ;
} else {
V_79 = V_29 -> V_81 -> V_91 ;
}
if ( V_79 -> V_81 -> V_82 == 0 )
V_15 = F_25 ( V_10 , V_30 ) ;
else
V_15 = F_26 ( V_10 , V_79 , V_30 ) ;
}
return V_15 ;
}
static int F_34 ( struct V_28 * V_29 , int V_92 ,
char * V_93 , unsigned long V_94 )
{
T_3 V_15 ;
unsigned long V_95 ;
struct V_9 * V_10 = V_29 -> V_12 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_35 ( & V_12 -> V_96 , V_95 ) ;
V_15 = F_36 ( V_12 -> V_41 ,
V_12 -> V_97 . V_98 , V_99 ) ;
if ( V_15 ) {
F_37 ( & V_12 -> V_96 , V_95 ) ;
F_15 ( L_19 ,
V_18 , V_10 -> V_35 , V_29 -> V_32 ) ;
return - V_43 ;
}
F_37 ( & V_12 -> V_96 , V_95 ) ;
return 0 ;
}
static int F_38 ( struct V_28 * V_29 )
{
return 0 ;
}
static void F_39 ( struct V_100 * V_7 )
{
F_40 ( L_20 , V_7 -> V_101 ) ;
F_40 ( L_21 , V_7 -> V_102 ) ;
F_40 ( L_22 , V_7 -> V_103 ) ;
F_40 ( L_23 , V_7 -> V_104 ) ;
F_40 ( L_24 , V_7 -> V_105 ) ;
F_40 ( L_25 , V_7 -> V_106 ) ;
F_40 ( L_26 , V_7 -> V_107 ) ;
F_40 ( L_27 , V_7 -> V_108 ) ;
F_40 ( L_28 , V_7 -> V_109 ) ;
F_40 ( L_29 , V_7 -> V_110 ) ;
}
static void F_41 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_100 * V_7 ;
long V_66 ;
V_7 = (struct V_100 * ) F_41 ;
V_66 = F_42 ( V_12 -> V_111 , V_7 , V_112 ) ;
if ( V_66 != V_75 ) {
F_15 ( L_30 ,
V_18 , V_12 -> V_111 , V_66 ) ;
return;
}
switch ( V_7 -> type ) {
case V_113 :
F_40 ( L_31 ) ;
F_39 ( V_7 ) ;
F_40 ( L_32 , V_7 -> V_114 . V_115 ) ;
F_40 ( L_33 , V_7 -> V_114 . V_116 ) ;
break;
case V_117 :
F_40 ( L_34 ,
V_7 -> V_118 . V_119 ? L_35 : L_36 ) ;
F_39 ( V_7 ) ;
F_40 ( L_37 , V_7 -> V_118 . V_120 ) ;
F_40 ( L_38 , V_7 -> V_118 . V_121 ) ;
F_40 ( L_39 , V_7 -> V_118 . V_122 ) ;
F_40 ( L_40 , V_7 -> V_118 . V_123 ) ;
break;
case V_124 :
F_40 ( L_41 ,
V_7 -> V_125 . V_126 ) ;
F_39 ( V_7 ) ;
F_40 ( L_42 , V_7 -> V_125 . V_127 ) ;
F_40 ( L_43 , V_7 -> V_125 . V_128 ) ;
break;
case V_129 :
F_40 ( L_44 ) ;
F_39 ( V_7 ) ;
break;
case V_130 :
F_40 ( L_45 ) ;
F_39 ( V_7 ) ;
break;
default:
F_15 ( L_46 ,
V_18 , V_12 -> V_111 , V_7 -> type ) ;
}
}
static void F_43 ( struct V_9 * V_10 ,
struct V_131 * V_132 )
{
struct V_133 * V_7 ;
int V_134 ;
V_7 = (struct V_133 * ) V_132 ;
F_40 ( L_47 ,
V_10 -> V_35 , V_132 -> V_135 ) ;
F_40 ( L_48 , V_7 -> V_136 ) ;
F_40 ( L_49 , V_7 -> V_137 ) ;
F_40 ( L_50 , V_7 -> V_138 ) ;
F_40 ( L_51 , V_7 -> V_139 ) ;
F_40 ( L_52 , V_7 -> V_140 ) ;
F_40 ( L_53 , V_7 -> V_141 ) ;
F_40 ( L_54 , V_7 -> V_142 ) ;
F_40 ( L_55 , V_7 -> V_143 ) ;
F_40 ( L_56 , V_7 -> V_144 ) ;
F_40 ( L_57 , V_7 -> V_145 ) ;
F_40 ( L_58 , V_7 -> V_146 ) ;
F_40 ( L_59 , V_7 -> V_147 ) ;
F_40 ( L_60 , V_7 -> V_148 ) ;
F_40 ( L_61 , V_7 -> V_149 ) ;
F_40 ( L_62 , V_7 -> V_150 ) ;
F_40 ( L_63 , V_7 -> V_151 ) ;
F_40 ( L_64 , V_7 -> V_152 ) ;
F_40 ( L_65 , V_7 -> V_153 ) ;
F_40 ( L_66 , V_7 -> V_154 ) ;
F_40 ( L_67 , V_7 -> V_155 ) ;
F_40 ( L_68 , V_7 -> V_156 ) ;
F_40 ( L_69 , V_7 -> V_106 ) ;
F_40 ( L_70 , V_7 -> V_157 ) ;
F_40 ( L_71 , V_7 -> V_158 ) ;
F_40 ( L_72 , V_7 -> V_159 ) ;
F_40 ( L_73 , V_7 -> V_160 ) ;
F_40 ( L_74 , V_7 -> V_161 ) ;
F_40 ( L_75 , V_7 -> V_162 ) ;
F_40 ( L_76 , V_7 -> V_163 ) ;
F_40 ( L_77 , V_7 -> V_164 ) ;
F_40 ( L_78 , V_7 -> V_165 ) ;
F_40 ( L_79 , V_7 -> V_166 ) ;
F_40 ( L_80 , V_7 -> V_167 ) ;
F_40 ( L_81 , V_7 -> V_168 ) ;
F_40 ( L_82 , V_7 -> V_169 ) ;
F_40 ( L_83 , V_7 -> V_170 ) ;
F_40 ( L_84 , V_7 -> V_171 ) ;
F_40 ( L_85 , V_7 -> V_172 ) ;
F_40 ( L_86 , V_7 -> V_173 ) ;
F_40 ( L_87 , V_7 -> V_174 ) ;
for ( V_134 = 0 ; V_134 < V_175 ; V_134 ++ ) {
if ( ( V_7 -> V_176 [ V_134 ] >> 63 ) == 0 &&
( V_7 -> V_177 [ V_134 ] >> 63 ) == 0 )
continue;
F_40 ( L_88 , V_134 , V_7 -> V_176 [ V_134 ] ) ;
F_40 ( L_89 , V_7 -> V_177 [ V_134 ] ) ;
}
}
static void F_44 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_131 * V_132 ;
long V_66 ;
V_132 = (struct V_131 * ) V_12 -> V_97 . V_98 ;
V_66 = F_36 ( V_12 -> V_41 , V_132 , V_112 ) ;
if ( V_66 != V_75 ) {
F_15 ( L_90 ,
V_18 , V_10 -> V_35 , V_66 ) ;
return;
}
switch ( V_132 -> V_178 ) {
case V_179 :
F_43 ( V_10 , V_132 ) ;
break;
default:
F_15 ( L_91 ,
V_18 , V_132 -> V_178 ) ;
}
}
static int F_45 ( struct V_9 * V_10 ,
struct V_28 * * V_29 )
{
struct V_28 * V_180 ;
V_180 = F_46 ( V_10 ) ;
if ( ! V_180 ) {
F_15 ( L_92 ,
V_18 , V_10 -> V_35 ) ;
return - V_38 ;
}
* V_29 = V_180 ;
return 0 ;
}
static int F_47 ( struct V_9 * V_10 ,
T_6 V_31 , struct V_28 * * V_29 )
{
struct V_28 * V_180 , * V_181 ;
struct V_86 V_79 ;
if ( F_45 ( V_10 , & V_180 ) )
return - V_38 ;
memset ( & V_79 , 0 , sizeof( struct V_86 ) ) ;
V_79 . V_12 = V_10 ;
V_79 . V_182 = V_31 ;
V_181 = F_48 ( & V_79 ) ;
if ( ! V_181 ) {
F_15 ( L_93 ,
V_18 , V_10 -> V_35 , V_31 ) ;
return - V_38 ;
}
* V_29 = V_181 ;
return 0 ;
}
static int F_49 ( struct V_28 * * V_29 )
{
struct V_9 * V_10 , * V_183 ;
struct V_11 * V_12 ;
T_2 V_184 ;
T_6 V_185 , V_92 ;
long V_66 ;
int V_15 = 1 ;
F_50 ( NULL ) ;
F_51 ( V_6 , 0x0ul ) ;
F_52 (hose, tmp, &hose_list, list_node) {
V_12 = V_10 -> V_13 ;
if ( V_12 -> V_26 & V_186 )
continue;
V_66 = F_53 ( V_12 -> V_41 ,
& V_184 , & V_185 , & V_92 ) ;
if ( V_66 != V_75 ) {
F_54 ( L_94
L_95 ,
V_18 , V_10 -> V_35 , V_66 ) ;
continue;
}
if ( V_185 == V_187 ||
V_92 == V_188 ) {
F_54 ( L_96 ,
V_18 , V_10 -> V_35 ) ;
continue;
}
F_54 ( L_97 ,
V_185 , V_92 , V_31 , V_10 -> V_35 ) ;
switch ( V_185 ) {
case V_189 :
if ( V_92 == V_190 ) {
F_52 (hose, tmp,
&hose_list, list_node) {
V_12 = V_10 -> V_13 ;
V_12 -> V_26 |= V_186 ;
}
F_9 ( L_98 ) ;
V_15 = 4 ;
goto V_74;
} else if ( V_92 == V_191 ) {
F_40 ( L_99
L_100 ) ;
F_41 ( V_10 ) ;
}
break;
case V_52 :
if ( V_92 == V_192 ) {
if ( F_45 ( V_10 , V_29 ) )
break;
F_9 ( L_101 ,
V_10 -> V_35 ) ;
V_12 -> V_26 |= V_186 ;
V_15 = 3 ;
goto V_74;
} else if ( V_92 == V_193 ) {
if ( F_45 ( V_10 , V_29 ) )
break;
F_9 ( L_102 ,
V_10 -> V_35 ) ;
V_15 = 2 ;
goto V_74;
} else if ( V_92 == V_191 ) {
F_40 ( L_103
L_100 ,
V_10 -> V_35 ) ;
F_44 ( V_10 ) ;
}
break;
case V_194 :
if ( F_47 ( V_10 , V_184 , V_29 ) )
break;
F_9 ( L_104 ,
( * V_29 ) -> V_32 , ( * V_29 ) -> V_12 -> V_35 ) ;
V_15 = 1 ;
goto V_74;
}
}
V_15 = 0 ;
V_74:
return V_15 ;
}
