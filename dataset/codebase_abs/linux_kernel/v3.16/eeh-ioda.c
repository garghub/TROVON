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
T_3 V_16 ;
T_4 V_30 ;
struct V_10 * V_11 = V_28 -> V_13 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_28 -> V_31 < 0 || V_28 -> V_31 >= V_13 -> V_32 . V_33 ) {
F_17 ( L_5
L_6 ,
V_19 , V_28 -> V_31 , V_13 -> V_32 . V_33 ,
V_11 -> V_34 ) ;
return - V_35 ;
}
V_30 = V_28 -> V_31 ;
switch ( V_29 ) {
case V_36 :
V_16 = - V_37 ;
break;
case V_38 :
V_16 = 0 ;
break;
case V_39 :
V_16 = F_21 ( V_13 -> V_40 , V_30 ,
V_41 ) ;
if ( V_16 ) {
F_22 ( L_7
L_8 ,
V_19 , V_11 -> V_34 , V_30 , V_16 ) ;
return - V_42 ;
}
break;
case V_43 :
V_16 = F_21 ( V_13 -> V_40 , V_30 ,
V_44 ) ;
if ( V_16 ) {
F_22 ( L_9
L_8 ,
V_19 , V_11 -> V_34 , V_30 , V_16 ) ;
return - V_42 ;
}
break;
default:
F_22 ( L_10 , V_19 , V_29 ) ;
return - V_35 ;
}
return V_16 ;
}
static void F_23 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
long V_45 ;
V_45 = F_24 ( V_13 -> V_40 , V_13 -> V_46 . V_47 ,
V_48 ) ;
if ( V_45 != V_49 ) {
F_22 ( L_11 ,
V_19 , V_11 -> V_34 , V_45 ) ;
return;
}
F_25 ( V_11 , V_13 -> V_46 . V_47 ) ;
}
static int F_26 ( struct V_27 * V_28 )
{
T_3 V_16 = 0 ;
T_5 V_50 ;
T_6 V_51 ;
T_4 V_30 ;
int V_52 ;
struct V_10 * V_11 = V_28 -> V_13 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_28 -> V_31 < 0 || V_28 -> V_31 >= V_13 -> V_32 . V_33 ) {
F_17 ( L_5
L_6 ,
V_19 , V_28 -> V_31 , V_13 -> V_32 . V_33 ,
V_11 -> V_34 ) ;
return V_53 ;
}
if ( ! ( V_28 -> type & V_54 ) &&
( V_28 -> V_55 & V_56 ) ) {
V_52 = ( V_57 |
V_58 |
V_59 |
V_60 ) ;
return V_52 ;
}
V_30 = V_28 -> V_31 ;
V_16 = F_27 ( V_13 -> V_40 , V_30 ,
& V_50 , & V_51 , NULL ) ;
if ( V_16 ) {
F_17 ( L_12
L_13 ,
V_19 , V_11 -> V_34 , V_30 , V_16 ) ;
return V_53 ;
}
if ( V_28 -> type & V_54 ) {
V_52 = 0 ;
V_52 &= ~ V_61 ;
if ( F_28 ( V_51 ) != V_62 ) {
V_52 |= V_57 ;
V_52 |= V_58 ;
V_52 |= V_59 ;
V_52 |= V_60 ;
} else if ( ! ( V_28 -> V_55 & V_63 ) ) {
F_29 ( V_28 , V_63 ) ;
F_23 ( V_11 ) ;
}
return V_52 ;
}
V_52 = 0 ;
switch ( V_50 ) {
case V_64 :
V_52 &= ~ V_61 ;
V_52 |= V_57 ;
V_52 |= V_58 ;
V_52 |= V_59 ;
V_52 |= V_60 ;
break;
case V_65 :
V_52 &= ~ V_61 ;
V_52 |= V_58 ;
V_52 |= V_60 ;
break;
case V_66 :
V_52 &= ~ V_61 ;
V_52 |= V_57 ;
V_52 |= V_59 ;
break;
case V_67 :
V_52 &= ~ V_61 ;
break;
case V_68 :
V_52 |= V_61 ;
break;
case V_69 :
V_52 |= V_70 ;
break;
case V_71 :
V_52 |= V_53 ;
break;
default:
F_22 ( L_14
L_15 ,
V_19 , V_50 , V_11 -> V_34 , V_30 ) ;
}
if ( V_52 != V_53 &&
( V_52 & ( V_57 | V_58 ) ) !=
( V_57 | V_58 ) &&
! ( V_28 -> V_55 & V_63 ) ) {
F_29 ( V_28 , V_63 ) ;
F_23 ( V_11 ) ;
}
return V_52 ;
}
static T_3 F_30 ( struct V_12 * V_13 )
{
T_3 V_45 = V_72 ;
while ( 1 ) {
V_45 = F_31 ( V_13 -> V_40 ) ;
if ( V_45 <= 0 )
break;
if ( V_73 < V_74 )
F_32 ( 1000 * V_45 ) ;
else
F_33 ( V_45 ) ;
}
return V_45 ;
}
int F_34 ( struct V_10 * V_11 , int V_29 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
T_3 V_45 = V_72 ;
F_35 ( L_16 ,
V_19 , V_11 -> V_34 , V_29 ) ;
if ( V_29 == V_75 ||
V_29 == V_76 )
V_45 = F_36 ( V_13 -> V_40 ,
V_77 ,
V_78 ) ;
else if ( V_29 == V_79 )
V_45 = F_36 ( V_13 -> V_40 ,
V_77 ,
V_80 ) ;
if ( V_45 < 0 )
goto V_81;
V_45 = F_30 ( V_13 ) ;
if ( V_29 == V_79 ) {
if ( V_73 < V_74 )
F_32 ( 1000 * V_82 ) ;
else
F_33 ( V_82 ) ;
}
V_81:
if ( V_45 != V_49 )
return - V_42 ;
return 0 ;
}
static int F_37 ( struct V_10 * V_11 , int V_29 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
T_3 V_45 = V_49 ;
F_35 ( L_16 ,
V_19 , V_11 -> V_34 , V_29 ) ;
if ( V_29 == V_75 )
V_45 = F_36 ( V_13 -> V_40 ,
V_83 ,
V_78 ) ;
else if ( V_29 == V_76 )
V_45 = F_36 ( V_13 -> V_40 ,
V_84 ,
V_78 ) ;
else if ( V_29 == V_79 )
V_45 = F_36 ( V_13 -> V_40 ,
V_84 ,
V_80 ) ;
if ( V_45 < 0 )
goto V_81;
V_45 = F_30 ( V_13 ) ;
if ( V_29 == V_79 )
F_33 ( V_82 ) ;
V_81:
if ( V_45 != V_49 )
return - V_42 ;
return 0 ;
}
static int F_38 ( struct V_85 * V_86 , int V_29 )
{
struct V_87 * V_88 = F_39 ( V_86 ) ;
struct V_89 * V_90 = F_40 ( V_88 ) ;
int V_91 = V_90 ? V_90 -> V_92 : 0 ;
T_4 V_93 ;
F_35 ( L_17 ,
V_19 , F_41 ( V_86 -> V_94 ) ,
V_86 -> V_94 -> V_95 , V_29 ) ;
switch ( V_29 ) {
case V_75 :
case V_76 :
if ( V_91 ) {
V_96 -> V_97 ( V_88 , V_91 + V_98 ,
4 , & V_93 ) ;
V_93 |= V_99 ;
V_96 -> V_100 ( V_88 , V_91 + V_98 ,
4 , V_93 ) ;
}
V_96 -> V_97 ( V_88 , V_101 , 2 , & V_93 ) ;
V_93 |= V_102 ;
V_96 -> V_100 ( V_88 , V_101 , 2 , V_93 ) ;
F_33 ( V_103 ) ;
break;
case V_79 :
V_96 -> V_97 ( V_88 , V_101 , 2 , & V_93 ) ;
V_93 &= ~ V_102 ;
V_96 -> V_100 ( V_88 , V_101 , 2 , V_93 ) ;
F_33 ( V_82 ) ;
if ( V_91 ) {
V_96 -> V_97 ( V_88 , V_91 + V_98 ,
4 , & V_93 ) ;
V_93 &= ~ V_99 ;
V_96 -> V_100 ( V_88 , V_91 + V_98 ,
4 , V_93 ) ;
}
break;
}
return 0 ;
}
void F_42 ( struct V_85 * V_86 )
{
struct V_10 * V_11 ;
if ( F_43 ( V_86 -> V_94 ) ) {
V_11 = F_44 ( V_86 -> V_94 ) ;
F_37 ( V_11 , V_76 ) ;
F_37 ( V_11 , V_79 ) ;
} else {
F_38 ( V_86 , V_76 ) ;
F_38 ( V_86 , V_79 ) ;
}
}
static int F_45 ( struct V_27 * V_28 , int V_29 )
{
struct V_10 * V_11 = V_28 -> V_13 ;
struct V_104 * V_94 ;
int V_16 ;
if ( V_28 -> type & V_54 ) {
V_16 = F_34 ( V_11 , V_29 ) ;
} else {
V_94 = F_46 ( V_28 ) ;
if ( F_43 ( V_94 ) ||
F_43 ( V_94 -> V_105 ) )
V_16 = F_37 ( V_11 , V_29 ) ;
else
V_16 = F_38 ( V_94 -> V_106 , V_29 ) ;
}
return V_16 ;
}
static int F_47 ( struct V_27 * V_28 )
{
return 0 ;
}
static void F_48 ( struct V_107 * V_7 )
{
F_49 ( L_18 , V_7 -> V_108 ) ;
F_49 ( L_19 , V_7 -> V_109 ) ;
F_49 ( L_20 , V_7 -> V_110 ) ;
F_49 ( L_21 , V_7 -> V_111 ) ;
F_49 ( L_22 , V_7 -> V_112 ) ;
F_49 ( L_23 , V_7 -> V_113 ) ;
F_49 ( L_24 , V_7 -> V_114 ) ;
F_49 ( L_25 , V_7 -> V_115 ) ;
F_49 ( L_26 , V_7 -> V_116 ) ;
F_49 ( L_27 , V_7 -> V_117 ) ;
}
static void F_50 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_107 * V_7 = & V_13 -> V_46 . V_118 ;
long V_45 ;
V_45 = F_51 ( V_13 -> V_119 , V_7 , sizeof( * V_7 ) ) ;
if ( V_45 != V_49 ) {
F_22 ( L_28 ,
V_19 , V_13 -> V_119 , V_45 ) ;
return;
}
switch ( V_7 -> type ) {
case V_120 :
F_49 ( L_29 ) ;
F_48 ( V_7 ) ;
F_49 ( L_30 , V_7 -> V_121 . V_122 ) ;
F_49 ( L_31 , V_7 -> V_121 . V_123 ) ;
break;
case V_124 :
F_49 ( L_32 ,
V_7 -> V_125 . V_126 ? L_33 : L_34 ) ;
F_48 ( V_7 ) ;
F_49 ( L_35 , V_7 -> V_125 . V_127 ) ;
F_49 ( L_36 , V_7 -> V_125 . V_128 ) ;
F_49 ( L_37 , V_7 -> V_125 . V_129 ) ;
F_49 ( L_38 , V_7 -> V_125 . V_130 ) ;
break;
case V_131 :
F_49 ( L_39 ,
V_7 -> V_132 . V_133 ) ;
F_48 ( V_7 ) ;
F_49 ( L_40 , V_7 -> V_132 . V_134 ) ;
F_49 ( L_41 , V_7 -> V_132 . V_135 ) ;
break;
case V_136 :
F_49 ( L_42 ) ;
F_48 ( V_7 ) ;
break;
case V_137 :
F_49 ( L_43 ) ;
F_48 ( V_7 ) ;
break;
default:
F_22 ( L_44 ,
V_19 , V_13 -> V_119 , V_7 -> type ) ;
}
}
static int F_52 ( struct V_10 * V_11 ,
T_7 V_30 , struct V_27 * * V_28 )
{
struct V_27 * V_138 , * V_139 ;
struct V_89 V_86 ;
V_138 = F_53 ( V_11 ) ;
if ( ! V_138 )
return - V_37 ;
memset ( & V_86 , 0 , sizeof( struct V_89 ) ) ;
V_86 . V_13 = V_11 ;
V_86 . V_140 = V_30 ;
V_139 = F_54 ( & V_86 ) ;
if ( ! V_139 ) return - V_37 ;
* V_28 = V_139 ;
return 0 ;
}
static int F_55 ( struct V_27 * * V_28 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_27 * V_138 , * V_141 ;
T_8 V_142 ;
T_6 V_143 , V_144 ;
int V_145 = ( V_57 | V_58 ) ;
long V_45 ;
int V_55 , V_16 = V_146 ;
F_56 ( NULL , false ) ;
F_4 ( V_6 , 0x0ul ) ;
F_57 (hose, &hose_list, list_node) {
V_13 = V_11 -> V_14 ;
V_138 = F_53 ( V_11 ) ;
if ( ! V_138 || ( V_138 -> V_55 & V_63 ) )
continue;
V_45 = F_58 ( V_13 -> V_40 ,
& V_142 , & V_143 , & V_144 ) ;
if ( V_45 != V_49 ) {
F_59 ( L_45
L_46 ,
V_19 , V_11 -> V_34 , V_45 ) ;
continue;
}
if ( F_28 ( V_143 ) == V_147 ||
F_28 ( V_144 ) == V_148 ) {
F_59 ( L_47 ,
V_19 , V_11 -> V_34 ) ;
continue;
}
F_59 ( L_48 ,
V_19 , F_28 ( V_143 ) , F_28 ( V_144 ) ,
F_60 ( V_142 ) , V_11 -> V_34 ) ;
switch ( F_28 ( V_143 ) ) {
case V_149 :
if ( F_28 ( V_144 ) == V_150 ) {
F_17 ( L_49 ) ;
V_16 = V_151 ;
} else if ( F_28 ( V_144 ) == V_152 ) {
F_49 ( L_50
L_51 ) ;
F_50 ( V_11 ) ;
V_16 = V_146 ;
}
break;
case V_62 :
if ( F_28 ( V_144 ) == V_153 ) {
* V_28 = V_138 ;
F_17 ( L_52
L_53 ,
V_11 -> V_34 ,
F_61 ( V_138 ) ) ;
V_16 = V_154 ;
} else if ( F_28 ( V_144 ) ==
V_155 ) {
* V_28 = V_138 ;
F_17 ( L_54
L_53 ,
V_11 -> V_34 ,
F_61 ( V_138 ) ) ;
V_16 = V_156 ;
} else if ( F_28 ( V_144 ) == V_152 ) {
F_49 ( L_55
L_56 ,
V_11 -> V_34 ,
F_61 ( V_138 ) ) ;
F_23 ( V_11 ) ;
V_16 = V_146 ;
}
break;
case V_157 :
if ( F_52 ( V_11 ,
F_60 ( V_142 ) , V_28 ) ) {
F_49 ( L_57 ,
V_11 -> V_34 , V_142 ) ;
F_49 ( L_58 ,
F_61 ( V_138 ) ) ;
F_21 ( V_13 -> V_40 , V_142 ,
V_158 ) ;
V_16 = V_146 ;
} else if ( ( * V_28 ) -> V_55 & V_63 ) {
V_16 = V_146 ;
} else {
F_17 ( L_59 ,
( * V_28 ) -> V_31 , ( * V_28 ) -> V_13 -> V_34 ) ;
F_17 ( L_60 ,
F_61 ( * V_28 ) , F_61 ( V_138 ) ) ;
V_16 = V_159 ;
}
break;
default:
F_62 ( L_61 ,
V_19 , F_28 ( V_143 ) ) ;
}
if ( ( V_16 == V_159 ||
V_16 == V_156 ) &&
! ( ( * V_28 ) -> V_55 & V_63 ) ) {
F_29 ( * V_28 , V_63 ) ;
F_23 ( V_11 ) ;
}
if ( V_16 == V_159 ) {
V_141 = ( * V_28 ) -> V_105 ;
while ( V_141 ) {
if ( V_141 -> type & V_54 )
break;
V_55 = F_26 ( V_141 ) ;
if ( V_55 > 0 &&
( V_55 & V_145 ) != V_145 )
* V_28 = V_141 ;
V_141 = V_141 -> V_105 ;
}
F_29 ( * V_28 , V_63 ) ;
}
if ( V_16 > V_160 )
break;
}
return V_16 ;
}
