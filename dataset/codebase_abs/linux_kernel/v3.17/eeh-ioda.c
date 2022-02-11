static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
T_1 V_5 = ( T_1 ) V_4 ;
if ( ! ( V_5 & V_6 ) ||
! ( V_3 & V_6 ) )
return 0 ;
if ( F_2 () )
F_3 ( NULL ) ;
else
F_4 ( V_6 , 0x0ul ) ;
return 0 ;
}
static int F_5 ( void * V_7 , int V_8 , T_2 V_9 )
{
struct V_10 * V_11 = V_7 ;
struct V_12 * V_13 = V_11 -> V_14 ;
F_6 ( V_13 -> V_15 + V_8 , V_9 ) ;
return 0 ;
}
static int F_7 ( void * V_7 , int V_8 , T_2 * V_9 )
{
struct V_10 * V_11 = V_7 ;
struct V_12 * V_13 = V_11 -> V_14 ;
* V_9 = F_8 ( V_13 -> V_15 + V_8 ) ;
return 0 ;
}
static int F_9 ( void * V_7 , T_2 V_9 )
{
return F_5 ( V_7 , 0xD10 , V_9 ) ;
}
static int F_10 ( void * V_7 , T_2 * V_9 )
{
return F_7 ( V_7 , 0xD10 , V_9 ) ;
}
static int F_11 ( void * V_7 , T_2 V_9 )
{
return F_5 ( V_7 , 0xD90 , V_9 ) ;
}
static int F_12 ( void * V_7 , T_2 * V_9 )
{
return F_7 ( V_7 , 0xD90 , V_9 ) ;
}
static int F_13 ( void * V_7 , T_2 V_9 )
{
return F_5 ( V_7 , 0xE10 , V_9 ) ;
}
static int F_14 ( void * V_7 , T_2 * V_9 )
{
return F_7 ( V_7 , 0xE10 , V_9 ) ;
}
static int F_15 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_16 ;
if ( ! V_17 ) {
V_16 = F_16 ( & V_18 ) ;
if ( V_16 ) {
F_17 ( L_1 ,
V_19 , V_16 ) ;
return V_16 ;
}
V_17 = 1 ;
}
#ifdef F_18
if ( ! V_13 -> V_20 && V_13 -> V_21 ) {
V_13 -> V_20 = 1 ;
F_19 ( L_2 , 0600 ,
V_13 -> V_21 , V_11 ,
& V_22 ) ;
F_19 ( L_3 , 0600 ,
V_13 -> V_21 , V_11 ,
& V_23 ) ;
F_19 ( L_4 , 0600 ,
V_13 -> V_21 , V_11 ,
& V_24 ) ;
}
#endif
if ( F_2 () )
V_13 -> V_25 |= V_26 ;
else
V_13 -> V_25 &= ~ V_26 ;
return 0 ;
}
static int F_20 ( struct V_27 * V_28 , int V_29 )
{
struct V_10 * V_11 = V_28 -> V_13 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_30 , V_16 = 0 ;
T_3 V_31 ;
if ( V_28 -> V_32 < 0 || V_28 -> V_32 >= V_13 -> V_33 . V_34 ) {
F_17 ( L_5
L_6 ,
V_19 , V_28 -> V_32 , V_13 -> V_33 . V_34 ,
V_11 -> V_35 ) ;
return - V_36 ;
}
switch ( V_29 ) {
case V_37 :
return - V_38 ;
case V_39 :
return 0 ;
case V_40 :
V_30 = V_41 ;
break;
case V_42 :
V_30 = V_43 ;
break;
default:
F_21 ( L_7 ,
V_19 , V_29 ) ;
return - V_36 ;
}
if ( V_13 -> V_44 ) {
V_16 = V_13 -> V_44 ( V_13 , V_28 -> V_32 , V_30 ) ;
} else {
V_31 = F_22 ( V_13 -> V_45 ,
V_28 -> V_32 ,
V_30 ) ;
if ( V_31 != V_46 ) {
F_21 ( L_8 ,
V_19 , V_31 , V_29 , V_13 -> V_11 -> V_35 ,
V_28 -> V_32 ) ;
V_16 = - V_47 ;
}
}
return V_16 ;
}
static void F_23 ( struct V_27 * V_28 )
{
struct V_12 * V_13 = V_28 -> V_13 -> V_14 ;
long V_31 ;
V_31 = F_24 ( V_13 -> V_45 , V_28 -> V_7 ,
V_48 ) ;
if ( V_31 != V_46 )
F_21 ( L_9 ,
V_19 , V_28 -> V_13 -> V_35 , V_31 ) ;
}
static int F_25 ( struct V_27 * V_28 )
{
struct V_12 * V_13 = V_28 -> V_13 -> V_14 ;
T_4 V_49 ;
T_5 V_50 ;
T_3 V_31 ;
int V_51 = 0 ;
V_31 = F_26 ( V_13 -> V_45 ,
V_28 -> V_32 ,
& V_49 ,
& V_50 ,
NULL ) ;
if ( V_31 != V_46 ) {
F_21 ( L_10 ,
V_19 , V_31 , V_13 -> V_11 -> V_35 ) ;
return V_52 ;
}
if ( F_27 ( V_50 ) != V_53 ) {
V_51 = ( V_54 |
V_55 |
V_56 |
V_57 ) ;
} else if ( ! ( V_28 -> V_58 & V_59 ) ) {
F_28 ( V_28 , V_59 ) ;
F_23 ( V_28 ) ;
}
return V_51 ;
}
static int F_29 ( struct V_27 * V_28 )
{
struct V_12 * V_13 = V_28 -> V_13 -> V_14 ;
T_4 V_49 ;
T_5 V_50 ;
T_3 V_31 ;
int V_51 ;
if ( V_28 -> V_58 & V_60 ) {
V_51 = ( V_54 |
V_55 |
V_56 |
V_57 ) ;
return V_51 ;
}
if ( V_13 -> V_61 ) {
V_49 = V_13 -> V_61 ( V_13 , V_28 -> V_32 ) ;
} else {
V_31 = F_26 ( V_13 -> V_45 ,
V_28 -> V_32 ,
& V_49 ,
& V_50 ,
NULL ) ;
if ( V_31 != V_46 ) {
F_21 ( L_11 ,
V_19 , V_31 , V_13 -> V_11 -> V_35 , V_28 -> V_32 ) ;
return V_52 ;
}
}
switch ( V_49 ) {
case V_62 :
V_51 = ( V_54 |
V_55 |
V_56 |
V_57 ) ;
break;
case V_63 :
V_51 = ( V_55 |
V_57 ) ;
break;
case V_64 :
V_51 = ( V_54 |
V_56 ) ;
break;
case V_65 :
V_51 = 0 ;
break;
case V_66 :
V_51 = V_67 ;
break;
case V_68 :
V_51 = V_69 ;
break;
case V_70 :
V_51 = V_52 ;
break;
default:
V_51 = V_52 ;
F_21 ( L_12 ,
V_19 , V_13 -> V_11 -> V_35 ,
V_28 -> V_32 , V_49 ) ;
}
if ( ! ( V_51 & V_52 ) &&
! ( V_51 & V_69 ) &&
! ( V_51 & V_54 ) &&
! ( V_51 & V_55 ) &&
! ( V_28 -> V_58 & V_59 ) ) {
if ( V_13 -> V_71 )
V_13 -> V_71 ( V_13 , V_28 -> V_32 ) ;
F_28 ( V_28 , V_59 ) ;
F_23 ( V_28 ) ;
}
return V_51 ;
}
static int F_30 ( struct V_27 * V_28 )
{
struct V_12 * V_13 = V_28 -> V_13 -> V_14 ;
if ( V_28 -> V_32 < 0 ||
V_28 -> V_32 >= V_13 -> V_33 . V_34 ) {
F_21 ( L_13 ,
V_19 , V_13 -> V_11 -> V_35 ,
V_28 -> V_32 , V_13 -> V_33 . V_34 ) ;
return V_52 ;
}
if ( V_28 -> type & V_72 )
return F_25 ( V_28 ) ;
return F_29 ( V_28 ) ;
}
static T_3 F_31 ( struct V_12 * V_13 )
{
T_3 V_31 = V_73 ;
while ( 1 ) {
V_31 = F_32 ( V_13 -> V_45 ) ;
if ( V_31 <= 0 )
break;
if ( V_74 < V_75 )
F_33 ( 1000 * V_31 ) ;
else
F_34 ( V_31 ) ;
}
return V_31 ;
}
int F_35 ( struct V_10 * V_11 , int V_29 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
T_3 V_31 = V_73 ;
F_36 ( L_14 ,
V_19 , V_11 -> V_35 , V_29 ) ;
if ( V_29 == V_76 ||
V_29 == V_77 )
V_31 = F_37 ( V_13 -> V_45 ,
V_78 ,
V_79 ) ;
else if ( V_29 == V_80 )
V_31 = F_37 ( V_13 -> V_45 ,
V_78 ,
V_81 ) ;
if ( V_31 < 0 )
goto V_82;
V_31 = F_31 ( V_13 ) ;
if ( V_29 == V_80 ) {
if ( V_74 < V_75 )
F_33 ( 1000 * V_83 ) ;
else
F_34 ( V_83 ) ;
}
V_82:
if ( V_31 != V_46 )
return - V_47 ;
return 0 ;
}
static int F_38 ( struct V_10 * V_11 , int V_29 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
T_3 V_31 = V_46 ;
F_36 ( L_14 ,
V_19 , V_11 -> V_35 , V_29 ) ;
if ( V_29 == V_76 )
V_31 = F_37 ( V_13 -> V_45 ,
V_84 ,
V_79 ) ;
else if ( V_29 == V_77 )
V_31 = F_37 ( V_13 -> V_45 ,
V_85 ,
V_79 ) ;
else if ( V_29 == V_80 )
V_31 = F_37 ( V_13 -> V_45 ,
V_85 ,
V_81 ) ;
if ( V_31 < 0 )
goto V_82;
V_31 = F_31 ( V_13 ) ;
if ( V_29 == V_80 )
F_34 ( V_83 ) ;
V_82:
if ( V_31 != V_46 )
return - V_47 ;
return 0 ;
}
static int F_39 ( struct V_86 * V_87 , int V_29 )
{
struct V_88 * V_89 = F_40 ( V_87 ) ;
struct V_90 * V_91 = F_41 ( V_89 ) ;
int V_92 = V_91 ? V_91 -> V_93 : 0 ;
T_6 V_94 ;
F_36 ( L_15 ,
V_19 , F_42 ( V_87 -> V_95 ) ,
V_87 -> V_95 -> V_96 , V_29 ) ;
switch ( V_29 ) {
case V_76 :
case V_77 :
if ( V_92 ) {
V_97 -> V_98 ( V_89 , V_92 + V_99 ,
4 , & V_94 ) ;
V_94 |= V_100 ;
V_97 -> V_101 ( V_89 , V_92 + V_99 ,
4 , V_94 ) ;
}
V_97 -> V_98 ( V_89 , V_102 , 2 , & V_94 ) ;
V_94 |= V_103 ;
V_97 -> V_101 ( V_89 , V_102 , 2 , V_94 ) ;
F_34 ( V_104 ) ;
break;
case V_80 :
V_97 -> V_98 ( V_89 , V_102 , 2 , & V_94 ) ;
V_94 &= ~ V_103 ;
V_97 -> V_101 ( V_89 , V_102 , 2 , V_94 ) ;
F_34 ( V_83 ) ;
if ( V_92 ) {
V_97 -> V_98 ( V_89 , V_92 + V_99 ,
4 , & V_94 ) ;
V_94 &= ~ V_100 ;
V_97 -> V_101 ( V_89 , V_92 + V_99 ,
4 , V_94 ) ;
}
break;
}
return 0 ;
}
void F_43 ( struct V_86 * V_87 )
{
struct V_10 * V_11 ;
if ( F_44 ( V_87 -> V_95 ) ) {
V_11 = F_45 ( V_87 -> V_95 ) ;
F_38 ( V_11 , V_77 ) ;
F_38 ( V_11 , V_80 ) ;
} else {
F_39 ( V_87 , V_77 ) ;
F_39 ( V_87 , V_80 ) ;
}
}
static int F_46 ( struct V_27 * V_28 , int V_29 )
{
struct V_10 * V_11 = V_28 -> V_13 ;
struct V_105 * V_95 ;
int V_16 ;
if ( V_28 -> type & V_72 ) {
V_16 = F_35 ( V_11 , V_29 ) ;
} else {
V_95 = F_47 ( V_28 ) ;
if ( F_44 ( V_95 ) ||
F_44 ( V_95 -> V_106 ) )
V_16 = F_38 ( V_11 , V_29 ) ;
else
V_16 = F_39 ( V_95 -> V_107 , V_29 ) ;
}
return V_16 ;
}
int F_48 ( struct V_27 * V_28 , int V_108 ,
char * V_109 , unsigned long V_110 )
{
F_49 ( V_28 -> V_13 , V_28 -> V_7 ) ;
return 0 ;
}
static int F_50 ( struct V_27 * V_28 )
{
return 0 ;
}
static void F_51 ( struct V_111 * V_7 )
{
if ( V_7 -> V_112 || V_7 -> V_113 ||
V_7 -> V_114 || V_7 -> V_115 || V_7 -> V_116 )
F_52 ( L_16 ,
F_53 ( V_7 -> V_112 ) ,
F_53 ( V_7 -> V_113 ) ,
F_53 ( V_7 -> V_114 ) ,
F_53 ( V_7 -> V_115 ) ,
F_53 ( V_7 -> V_116 ) ) ;
if ( V_7 -> V_117 || V_7 -> V_118 ||
V_7 -> V_119 || V_7 -> V_120 || V_7 -> V_121 )
F_52 ( L_17 ,
F_53 ( V_7 -> V_117 ) ,
F_53 ( V_7 -> V_118 ) ,
F_53 ( V_7 -> V_119 ) ,
F_53 ( V_7 -> V_120 ) ,
F_53 ( V_7 -> V_121 ) ) ;
}
static void F_54 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_111 * V_7 = & V_13 -> V_122 . V_123 ;
long V_31 ;
V_31 = F_55 ( V_13 -> V_124 , V_7 , sizeof( * V_7 ) ) ;
if ( V_31 != V_46 ) {
F_21 ( L_18 ,
V_19 , V_13 -> V_124 , V_31 ) ;
return;
}
switch ( V_7 -> type ) {
case V_125 :
F_52 ( L_19 ) ;
F_51 ( V_7 ) ;
if ( V_7 -> V_126 . V_127 || V_7 -> V_126 . V_128 )
F_52 ( L_20 ,
F_53 ( V_7 -> V_126 . V_127 ) ,
F_53 ( V_7 -> V_126 . V_128 ) ) ;
break;
case V_129 :
F_52 ( L_21 ,
V_7 -> V_130 . V_131 ? L_22 : L_23 ) ;
F_51 ( V_7 ) ;
if ( V_7 -> V_130 . V_132 || V_7 -> V_130 . V_133 ||
V_7 -> V_130 . V_134 || V_7 -> V_130 . V_135 )
F_52 ( L_24 ,
F_53 ( V_7 -> V_130 . V_132 ) ,
F_53 ( V_7 -> V_130 . V_133 ) ,
F_53 ( V_7 -> V_130 . V_134 ) ,
F_53 ( V_7 -> V_130 . V_135 ) ) ;
break;
case V_136 :
F_52 ( L_25 ,
V_7 -> V_137 . V_138 ) ;
F_51 ( V_7 ) ;
if ( V_7 -> V_137 . V_139 || V_7 -> V_137 . V_140 )
F_52 ( L_26 ,
F_53 ( V_7 -> V_137 . V_139 ) ,
F_53 ( V_7 -> V_137 . V_140 ) ) ;
break;
case V_141 :
F_52 ( L_27 ) ;
F_51 ( V_7 ) ;
break;
case V_142 :
F_52 ( L_28 ) ;
F_51 ( V_7 ) ;
break;
default:
F_21 ( L_29 ,
V_19 , V_13 -> V_124 , V_7 -> type ) ;
}
}
static int F_56 ( struct V_10 * V_11 ,
T_7 V_143 , struct V_27 * * V_28 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_144 * V_145 ;
struct V_27 * V_146 ;
struct V_90 V_91 ;
if ( V_13 -> V_61 ) {
V_145 = & V_13 -> V_33 . V_147 [ V_143 ] ;
if ( V_145 -> V_25 & V_148 ) {
V_145 = V_145 -> V_149 ;
F_57 ( ! V_145 ||
! ( V_145 -> V_25 & V_150 ) ) ;
V_143 = V_145 -> V_151 ;
}
}
memset ( & V_91 , 0 , sizeof( struct V_90 ) ) ;
V_91 . V_13 = V_11 ;
V_91 . V_152 = V_143 ;
V_146 = F_58 ( & V_91 ) ;
if ( ! V_146 )
return - V_153 ;
* V_28 = V_146 ;
if ( V_13 -> V_71 &&
! ( V_146 -> V_58 & V_59 ) )
V_13 -> V_71 ( V_13 , V_143 ) ;
return 0 ;
}
static int F_59 ( struct V_27 * * V_28 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_27 * V_154 , * V_155 ;
T_8 V_156 ;
T_5 V_157 , V_108 ;
int V_158 = ( V_54 | V_55 ) ;
long V_31 ;
int V_58 , V_16 = V_159 ;
F_60 ( NULL , false ) ;
F_4 ( V_6 , 0x0ul ) ;
F_61 (hose, &hose_list, list_node) {
V_13 = V_11 -> V_14 ;
V_154 = F_62 ( V_11 ) ;
if ( ! V_154 || ( V_154 -> V_58 & V_59 ) )
continue;
V_31 = F_63 ( V_13 -> V_45 ,
& V_156 , & V_157 , & V_108 ) ;
if ( V_31 != V_46 ) {
F_64 ( L_30
L_31 ,
V_19 , V_11 -> V_35 , V_31 ) ;
continue;
}
if ( F_27 ( V_157 ) == V_160 ||
F_27 ( V_108 ) == V_161 ) {
F_64 ( L_32 ,
V_19 , V_11 -> V_35 ) ;
continue;
}
F_64 ( L_33 ,
V_19 , F_27 ( V_157 ) , F_27 ( V_108 ) ,
F_53 ( V_156 ) , V_11 -> V_35 ) ;
switch ( F_27 ( V_157 ) ) {
case V_162 :
if ( F_27 ( V_108 ) == V_163 ) {
F_17 ( L_34 ) ;
V_16 = V_164 ;
} else if ( F_27 ( V_108 ) == V_165 ) {
F_52 ( L_35
L_36 ) ;
F_54 ( V_11 ) ;
V_16 = V_159 ;
}
break;
case V_53 :
if ( F_27 ( V_108 ) == V_166 ) {
* V_28 = V_154 ;
F_17 ( L_37
L_38 ,
V_11 -> V_35 ,
F_65 ( V_154 ) ) ;
V_16 = V_167 ;
} else if ( F_27 ( V_108 ) ==
V_168 ) {
* V_28 = V_154 ;
F_17 ( L_39
L_38 ,
V_11 -> V_35 ,
F_65 ( V_154 ) ) ;
V_16 = V_169 ;
} else if ( F_27 ( V_108 ) == V_165 ) {
F_52 ( L_40
L_41 ,
V_11 -> V_35 ,
F_65 ( V_154 ) ) ;
F_23 ( V_154 ) ;
F_49 ( V_11 , V_154 -> V_7 ) ;
V_16 = V_159 ;
}
break;
case V_170 :
if ( F_56 ( V_11 ,
F_53 ( V_156 ) , V_28 ) ) {
F_52 ( L_42 ,
V_11 -> V_35 , V_156 ) ;
F_52 ( L_43 ,
F_65 ( V_154 ) ) ;
F_22 ( V_13 -> V_45 , V_156 ,
V_171 ) ;
V_16 = V_159 ;
} else if ( ( * V_28 ) -> V_58 & V_59 ||
F_66 ( * V_28 ) ) {
V_16 = V_159 ;
} else {
F_17 ( L_44 ,
( * V_28 ) -> V_32 , ( * V_28 ) -> V_13 -> V_35 ) ;
F_17 ( L_45 ,
F_65 ( * V_28 ) , F_65 ( V_154 ) ) ;
V_16 = V_172 ;
}
break;
default:
F_21 ( L_46 ,
V_19 , F_27 ( V_157 ) ) ;
}
if ( ( V_16 == V_172 ||
V_16 == V_169 ) &&
! ( ( * V_28 ) -> V_58 & V_59 ) ) {
F_28 ( * V_28 , V_59 ) ;
F_23 ( * V_28 ) ;
}
if ( V_16 == V_172 ) {
V_155 = ( * V_28 ) -> V_106 ;
while ( V_155 ) {
if ( V_155 -> type & V_72 )
break;
V_58 = F_30 ( V_155 ) ;
if ( V_58 > 0 &&
( V_58 & V_158 ) != V_158 )
* V_28 = V_155 ;
V_155 = V_155 -> V_106 ;
}
F_28 ( * V_28 , V_59 ) ;
}
if ( V_16 > V_173 )
break;
}
return V_16 ;
}
