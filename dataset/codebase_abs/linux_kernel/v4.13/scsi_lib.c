static inline struct V_1 *
F_1 ( bool V_2 )
{
return V_2 ? V_3 : V_4 ;
}
static void F_2 ( bool V_2 ,
unsigned char * V_5 )
{
F_3 ( F_1 ( V_2 ) ,
V_5 ) ;
}
static unsigned char * F_4 ( bool V_2 ,
T_1 V_6 , int V_7 )
{
return F_5 ( F_1 ( V_2 ) ,
V_6 , V_7 ) ;
}
int F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_10 ;
int V_11 = 0 ;
V_10 = F_1 ( V_9 -> V_2 ) ;
if ( V_10 )
return 0 ;
F_7 ( & V_12 ) ;
if ( V_9 -> V_2 ) {
V_3 =
F_8 ( L_1 ,
V_13 , 0 ,
V_14 | V_15 , NULL ) ;
if ( ! V_3 )
V_11 = - V_16 ;
} else {
V_4 =
F_8 ( L_2 ,
V_13 , 0 , V_14 , NULL ) ;
if ( ! V_4 )
V_11 = - V_16 ;
}
F_9 ( & V_12 ) ;
return V_11 ;
}
static void
F_10 ( struct V_17 * V_18 , int V_19 )
{
struct V_8 * V_20 = V_18 -> V_21 -> V_20 ;
struct V_22 * V_21 = V_18 -> V_21 ;
struct V_23 * V_24 = V_23 ( V_21 ) ;
switch ( V_19 ) {
case V_25 :
F_11 ( & V_20 -> V_26 , V_20 -> V_27 ) ;
break;
case V_28 :
case V_29 :
F_11 ( & V_21 -> V_30 ,
V_21 -> V_31 ) ;
break;
case V_32 :
F_11 ( & V_24 -> V_33 ,
V_24 -> V_34 ) ;
break;
}
}
static void F_12 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
F_13 ( V_18 -> V_36 , true ) ;
F_14 ( & V_35 -> V_37 ) ;
}
static void F_15 ( struct V_17 * V_18 , int V_19 , int V_38 )
{
struct V_22 * V_21 = V_18 -> V_21 ;
struct V_39 * V_40 = V_21 -> V_39 ;
unsigned long V_41 ;
F_16 ( 1 , F_17 ( V_42 , V_18 ,
L_3 , V_18 ) ) ;
F_10 ( V_18 , V_19 ) ;
if ( V_38 )
F_18 ( V_21 ) ;
V_18 -> V_43 = 0 ;
if ( V_40 -> V_44 ) {
F_12 ( V_18 ) ;
return;
}
F_19 ( V_40 -> V_45 , V_41 ) ;
F_20 ( V_40 , V_18 -> V_36 ) ;
F_21 ( & V_21 -> V_46 ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
}
void F_23 ( struct V_17 * V_18 , int V_19 )
{
F_15 ( V_18 , V_19 , 1 ) ;
}
int F_24 ( struct V_22 * V_35 , const unsigned char * V_18 ,
int V_47 , void * V_48 , unsigned V_49 ,
unsigned char * V_50 , struct V_51 * V_52 ,
int V_53 , int V_54 , T_2 V_41 , T_3 V_55 ,
int * V_56 )
{
struct V_36 * V_57 ;
struct V_58 * V_59 ;
int V_11 = V_60 << 24 ;
V_57 = F_25 ( V_35 -> V_39 ,
V_47 == V_61 ?
V_62 : V_63 , V_64 ) ;
if ( F_26 ( V_57 ) )
return V_11 ;
V_59 = F_27 ( V_57 ) ;
if ( V_49 && F_28 ( V_35 -> V_39 , V_57 ,
V_48 , V_49 , V_64 ) )
goto V_65;
V_59 -> V_66 = F_29 ( V_18 [ 0 ] ) ;
memcpy ( V_59 -> V_18 , V_18 , V_59 -> V_66 ) ;
V_59 -> V_54 = V_54 ;
V_57 -> V_53 = V_53 ;
V_57 -> V_67 |= V_41 ;
V_57 -> V_55 |= V_55 | V_68 | V_69 ;
F_30 ( V_57 -> V_40 , NULL , V_57 , 1 ) ;
if ( F_31 ( V_59 -> V_70 > 0 && V_59 -> V_70 <= V_49 ) )
memset ( V_48 + ( V_49 - V_59 -> V_70 ) , 0 , V_59 -> V_70 ) ;
if ( V_56 )
* V_56 = V_59 -> V_70 ;
if ( V_50 && V_59 -> V_71 )
memcpy ( V_50 , V_59 -> V_50 , V_13 ) ;
if ( V_52 )
F_32 ( V_59 -> V_50 , V_59 -> V_71 , V_52 ) ;
V_11 = V_59 -> V_43 ;
V_65:
F_33 ( V_57 ) ;
return V_11 ;
}
static void F_34 ( struct V_17 * V_18 )
{
V_18 -> V_72 = 0 ;
F_35 ( V_18 , 0 ) ;
memset ( V_18 -> V_5 , 0 , V_13 ) ;
if ( V_18 -> V_66 == 0 )
V_18 -> V_66 = F_36 ( V_18 -> V_73 ) ;
}
void F_18 ( struct V_22 * V_35 )
{
struct V_8 * V_9 = V_35 -> V_20 ;
struct V_23 * V_24 = V_23 ( V_35 ) ;
unsigned long V_41 ;
F_37 ( & V_9 -> V_74 ) ;
if ( V_24 -> V_75 > 0 )
F_37 ( & V_24 -> V_76 ) ;
if ( F_31 ( F_38 ( V_9 ) &&
( V_9 -> V_77 || V_9 -> V_78 ) ) ) {
F_19 ( V_9 -> V_79 , V_41 ) ;
F_39 ( V_9 ) ;
F_22 ( V_9 -> V_79 , V_41 ) ;
}
F_37 ( & V_35 -> V_80 ) ;
}
static void F_40 ( struct V_39 * V_40 )
{
if ( V_40 -> V_44 )
F_41 ( V_40 ) ;
else
F_42 ( V_40 ) ;
}
static void F_43 ( struct V_22 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_20 ;
struct V_22 * V_35 , * V_82 ;
struct V_23 * V_24 = V_23 ( V_81 ) ;
unsigned long V_41 ;
F_19 ( V_9 -> V_79 , V_41 ) ;
V_24 -> V_83 = NULL ;
F_22 ( V_9 -> V_79 , V_41 ) ;
F_40 ( V_81 -> V_39 ) ;
F_19 ( V_9 -> V_79 , V_41 ) ;
if ( V_24 -> V_83 )
goto V_65;
F_44 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_35 == V_81 )
continue;
if ( F_45 ( V_35 ) )
continue;
F_22 ( V_9 -> V_79 , V_41 ) ;
F_40 ( V_35 -> V_39 ) ;
F_19 ( V_9 -> V_79 , V_41 ) ;
F_46 ( V_35 ) ;
}
V_65:
F_22 ( V_9 -> V_79 , V_41 ) ;
}
static inline bool F_47 ( struct V_22 * V_35 )
{
if ( F_48 ( & V_35 -> V_80 ) >= V_35 -> V_84 )
return true ;
if ( F_48 ( & V_35 -> V_30 ) > 0 )
return true ;
return false ;
}
static inline bool F_49 ( struct V_23 * V_24 )
{
if ( V_24 -> V_75 > 0 ) {
if ( F_48 ( & V_24 -> V_76 ) >= V_24 -> V_75 )
return true ;
if ( F_48 ( & V_24 -> V_33 ) > 0 )
return true ;
}
return false ;
}
static inline bool F_50 ( struct V_8 * V_9 )
{
if ( V_9 -> V_75 > 0 &&
F_48 ( & V_9 -> V_74 ) >= V_9 -> V_75 )
return true ;
if ( F_48 ( & V_9 -> V_26 ) > 0 )
return true ;
if ( V_9 -> V_85 )
return true ;
return false ;
}
static void F_51 ( struct V_8 * V_9 )
{
F_52 ( V_86 ) ;
struct V_22 * V_35 ;
unsigned long V_41 ;
F_19 ( V_9 -> V_79 , V_41 ) ;
F_53 ( & V_9 -> V_86 , & V_86 ) ;
while ( ! F_54 ( & V_86 ) ) {
struct V_39 * V_87 ;
if ( F_50 ( V_9 ) )
break;
V_35 = F_55 ( V_86 . V_88 ,
struct V_22 , V_89 ) ;
F_56 ( & V_35 -> V_89 ) ;
if ( F_49 ( V_23 ( V_35 ) ) ) {
F_57 ( & V_35 -> V_89 ,
& V_9 -> V_86 ) ;
continue;
}
V_87 = V_35 -> V_39 ;
if ( ! F_58 ( V_87 ) )
continue;
F_22 ( V_9 -> V_79 , V_41 ) ;
F_40 ( V_87 ) ;
F_59 ( V_87 ) ;
F_19 ( V_9 -> V_79 , V_41 ) ;
}
F_60 ( & V_86 , & V_9 -> V_86 ) ;
F_22 ( V_9 -> V_79 , V_41 ) ;
}
static void F_61 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
if ( V_23 ( V_35 ) -> V_91 )
F_43 ( V_35 ) ;
if ( ! F_54 ( & V_35 -> V_20 -> V_86 ) )
F_51 ( V_35 -> V_20 ) ;
if ( V_40 -> V_44 )
F_62 ( V_40 , false ) ;
else
F_42 ( V_40 ) ;
}
void F_63 ( struct V_92 * V_93 )
{
struct V_22 * V_35 ;
struct V_39 * V_40 ;
V_35 = F_64 ( V_93 , struct V_22 , V_46 ) ;
V_40 = V_35 -> V_39 ;
F_61 ( V_40 ) ;
}
static void F_65 ( struct V_39 * V_40 , struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_36 * V_57 = V_18 -> V_36 ;
unsigned long V_41 ;
F_19 ( V_40 -> V_45 , V_41 ) ;
F_66 ( V_57 ) ;
V_57 -> V_94 = NULL ;
F_67 ( V_18 ) ;
F_20 ( V_40 , V_57 ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
F_61 ( V_40 ) ;
F_14 ( & V_35 -> V_37 ) ;
}
void F_68 ( struct V_8 * V_9 )
{
struct V_22 * V_35 ;
F_69 (sdev, shost)
F_61 ( V_35 -> V_39 ) ;
}
static void F_70 ( struct V_17 * V_18 )
{
if ( ! F_71 ( V_18 -> V_36 ) ) {
struct V_95 * V_96 = F_72 ( V_18 ) ;
if ( V_96 -> V_97 )
V_96 -> V_97 ( V_18 ) ;
}
}
static void F_73 ( struct V_17 * V_18 )
{
struct V_98 * V_99 ;
if ( V_18 -> V_99 . V_100 . V_101 )
F_74 ( & V_18 -> V_99 . V_100 , true ) ;
if ( V_18 -> V_36 -> V_102 ) {
V_99 = V_18 -> V_36 -> V_102 -> V_94 ;
if ( V_99 )
F_74 ( & V_99 -> V_100 , true ) ;
}
if ( F_75 ( V_18 ) )
F_74 ( & V_18 -> V_103 -> V_100 , true ) ;
}
static void F_76 ( struct V_17 * V_18 )
{
F_73 ( V_18 ) ;
F_70 ( V_18 ) ;
F_77 ( V_18 ) ;
}
static void F_78 ( struct V_17 * V_18 )
{
if ( V_18 -> V_99 . V_100 . V_101 )
F_74 ( & V_18 -> V_99 . V_100 , false ) ;
memset ( & V_18 -> V_99 , 0 , sizeof( V_18 -> V_99 ) ) ;
if ( F_75 ( V_18 ) )
F_74 ( & V_18 -> V_103 -> V_100 , false ) ;
}
static void F_79 ( struct V_17 * V_18 )
{
struct V_98 * V_104 = V_18 -> V_36 -> V_102 -> V_94 ;
F_74 ( & V_104 -> V_100 , false ) ;
F_3 ( V_105 , V_104 ) ;
V_18 -> V_36 -> V_102 -> V_94 = NULL ;
}
static bool F_80 ( struct V_36 * V_57 , T_4 error ,
unsigned int V_106 , unsigned int V_107 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_39 * V_40 = V_35 -> V_39 ;
if ( F_81 ( V_57 , error , V_106 ) )
return true ;
if ( F_31 ( V_107 ) &&
F_81 ( V_57 -> V_102 , error , V_107 ) )
return true ;
if ( F_82 ( V_40 ) )
F_83 ( V_57 -> V_108 ) ;
if ( V_57 -> V_109 ) {
F_76 ( V_18 ) ;
F_84 ( V_57 , error ) ;
if ( V_23 ( V_35 ) -> V_91 ||
! F_54 ( & V_35 -> V_20 -> V_86 ) )
F_21 ( & V_35 -> V_46 ) ;
else
F_62 ( V_40 , true ) ;
} else {
unsigned long V_41 ;
if ( V_107 )
F_79 ( V_18 ) ;
F_78 ( V_18 ) ;
F_67 ( V_18 ) ;
F_19 ( V_40 -> V_45 , V_41 ) ;
F_85 ( V_57 , error ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
F_61 ( V_40 ) ;
}
F_14 ( & V_35 -> V_37 ) ;
return false ;
}
static T_4 F_86 ( struct V_17 * V_18 ,
int V_43 )
{
switch ( F_87 ( V_43 ) ) {
case V_110 :
return V_111 ;
case V_112 :
F_88 ( V_18 , V_113 ) ;
return V_114 ;
case V_115 :
return V_116 ;
case V_117 :
F_88 ( V_18 , V_113 ) ;
return V_118 ;
case V_119 :
F_88 ( V_18 , V_113 ) ;
return V_120 ;
default:
return V_121 ;
}
}
void F_89 ( struct V_17 * V_18 , unsigned int V_122 )
{
int V_43 = V_18 -> V_43 ;
struct V_39 * V_40 = V_18 -> V_21 -> V_39 ;
struct V_36 * V_57 = V_18 -> V_36 ;
T_4 error = V_123 ;
struct V_51 V_52 ;
bool V_124 = false ;
int V_125 = 0 , V_126 = 0 ;
enum { V_127 , V_128 , V_129 ,
V_130 } V_131 ;
unsigned long V_132 = ( V_18 -> V_133 + 1 ) * V_57 -> V_53 ;
if ( V_43 ) {
V_124 = F_90 ( V_18 , & V_52 ) ;
if ( V_124 )
V_125 = F_91 ( & V_52 ) ;
}
if ( F_71 ( V_57 ) ) {
if ( V_43 ) {
if ( V_124 ) {
F_27 ( V_57 ) -> V_71 =
F_92 ( 8 + V_18 -> V_5 [ 7 ] ,
V_13 ) ;
}
if ( ! V_125 )
error = F_86 ( V_18 , V_43 ) ;
}
F_27 ( V_57 ) -> V_43 = V_18 -> V_43 ;
F_27 ( V_57 ) -> V_70 = F_93 ( V_18 ) ;
if ( F_94 ( V_18 ) ) {
F_27 ( V_57 -> V_102 ) -> V_70 = F_95 ( V_18 ) -> V_56 ;
if ( F_80 ( V_57 , V_123 , F_96 ( V_57 ) ,
F_96 ( V_57 -> V_102 ) ) )
F_97 () ;
return;
}
} else if ( F_96 ( V_57 ) == 0 && V_43 && ! V_125 ) {
error = F_86 ( V_18 , V_43 ) ;
}
F_98 ( F_99 ( V_57 ) ) ;
F_100 ( 1 , F_17 ( V_42 , V_18 ,
L_4 ,
F_101 ( V_57 ) , V_122 ) ) ;
if ( V_124 && ( V_52 . V_134 == V_135 ) ) {
if ( ( V_52 . V_136 == 0x0 ) && ( V_52 . V_137 == 0x1d ) )
;
else if ( ! ( V_57 -> V_55 & V_68 ) )
F_102 ( V_18 ) ;
V_43 = 0 ;
error = V_123 ;
}
if ( ! ( F_96 ( V_57 ) == 0 && error ) &&
! F_80 ( V_57 , error , V_122 , 0 ) )
return;
if ( error && F_103 ( V_18 ) ) {
if ( F_80 ( V_57 , error , F_96 ( V_57 ) , 0 ) )
F_97 () ;
return;
}
if ( V_43 == 0 )
goto V_138;
error = F_86 ( V_18 , V_43 ) ;
if ( F_87 ( V_43 ) == V_139 ) {
V_131 = V_129 ;
} else if ( V_124 && ! V_125 ) {
switch ( V_52 . V_134 ) {
case V_140 :
if ( V_18 -> V_21 -> V_141 ) {
V_18 -> V_21 -> V_142 = 1 ;
V_131 = V_127 ;
} else {
V_131 = V_129 ;
}
break;
case V_143 :
if ( ( V_18 -> V_21 -> V_144 &&
V_52 . V_136 == 0x20 && V_52 . V_137 == 0x00 ) &&
( V_18 -> V_73 [ 0 ] == V_145 ||
V_18 -> V_73 [ 0 ] == V_146 ) ) {
V_18 -> V_21 -> V_144 = 0 ;
V_131 = V_128 ;
} else if ( V_52 . V_136 == 0x10 ) {
V_131 = V_127 ;
error = V_147 ;
} else if ( V_52 . V_136 == 0x20 || V_52 . V_136 == 0x24 ) {
V_131 = V_127 ;
error = V_114 ;
} else
V_131 = V_127 ;
break;
case V_148 :
V_131 = V_127 ;
if ( V_52 . V_136 == 0x10 )
error = V_147 ;
break;
case V_149 :
if ( V_52 . V_136 == 0x04 ) {
switch ( V_52 . V_137 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_131 = V_130 ;
break;
default:
V_131 = V_127 ;
break;
}
} else
V_131 = V_127 ;
break;
case V_150 :
V_131 = V_127 ;
break;
default:
V_131 = V_127 ;
break;
}
} else
V_131 = V_127 ;
if ( V_131 != V_127 &&
F_104 ( V_18 -> V_151 + V_132 , V_152 ) )
V_131 = V_127 ;
switch ( V_131 ) {
case V_127 :
if ( ! ( V_57 -> V_55 & V_68 ) ) {
static F_105 ( V_153 ,
V_154 ,
V_155 ) ;
if ( F_31 ( V_156 ) )
V_126 = F_106 ( V_157 ,
V_158 ) ;
if ( ! V_126 && F_107 ( & V_153 ) ) {
F_108 ( V_18 , NULL , V_159 ) ;
if ( F_109 ( V_43 ) & V_160 )
F_102 ( V_18 ) ;
F_110 ( V_18 ) ;
}
}
if ( ! F_80 ( V_57 , error , F_111 ( V_57 ) , 0 ) )
return;
case V_128 :
V_138:
if ( V_40 -> V_44 ) {
V_18 -> V_36 -> V_55 &= ~ V_161 ;
F_76 ( V_18 ) ;
F_12 ( V_18 ) ;
} else {
F_78 ( V_18 ) ;
F_65 ( V_40 , V_18 ) ;
}
break;
case V_129 :
F_15 ( V_18 , V_29 , 0 ) ;
break;
case V_130 :
F_15 ( V_18 , V_28 , 0 ) ;
break;
}
}
static int F_112 ( struct V_36 * V_57 , struct V_98 * V_99 )
{
int V_162 ;
if ( F_31 ( F_113 ( & V_99 -> V_100 ,
F_114 ( V_57 ) , V_99 -> V_100 . V_163 ) ) )
return V_164 ;
V_162 = F_115 ( V_57 -> V_40 , V_57 , V_99 -> V_100 . V_163 ) ;
F_98 ( V_162 > V_99 -> V_100 . V_101 ) ;
V_99 -> V_100 . V_101 = V_162 ;
V_99 -> V_165 = F_116 ( V_57 ) ;
return V_166 ;
}
int F_117 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_36 * V_59 = V_18 -> V_36 ;
bool V_167 = ( V_59 -> V_109 != NULL ) ;
int error = V_168 ;
if ( F_118 ( ! F_114 ( V_59 ) ) )
goto V_169;
error = F_112 ( V_59 , & V_18 -> V_99 ) ;
if ( error )
goto V_169;
if ( F_99 ( V_59 ) ) {
if ( ! V_59 -> V_40 -> V_44 ) {
struct V_98 * V_104 =
F_119 ( V_105 , V_170 ) ;
if ( ! V_104 ) {
error = V_164 ;
goto V_169;
}
V_59 -> V_102 -> V_94 = V_104 ;
}
error = F_112 ( V_59 -> V_102 , V_59 -> V_102 -> V_94 ) ;
if ( error )
goto V_169;
}
if ( F_120 ( V_59 ) ) {
struct V_98 * V_103 = V_18 -> V_103 ;
int V_171 , V_162 ;
if ( V_103 == NULL ) {
F_118 ( 1 ) ;
error = V_168 ;
goto V_169;
}
V_171 = F_121 ( V_59 -> V_40 , V_59 -> V_172 ) ;
if ( F_113 ( & V_103 -> V_100 , V_171 ,
V_103 -> V_100 . V_163 ) ) {
error = V_164 ;
goto V_169;
}
V_162 = F_122 ( V_59 -> V_40 , V_59 -> V_172 ,
V_103 -> V_100 . V_163 ) ;
F_98 ( F_31 ( V_162 > V_171 ) ) ;
F_98 ( F_31 ( V_162 > F_123 ( V_59 -> V_40 ) ) ) ;
V_18 -> V_103 = V_103 ;
V_18 -> V_103 -> V_100 . V_101 = V_162 ;
}
return V_166 ;
V_169:
if ( V_167 ) {
F_73 ( V_18 ) ;
} else {
F_78 ( V_18 ) ;
V_18 -> V_36 -> V_94 = NULL ;
F_67 ( V_18 ) ;
F_14 ( & V_35 -> V_37 ) ;
}
return error ;
}
void F_124 ( struct V_36 * V_59 )
{
struct V_17 * V_18 = F_125 ( V_59 ) ;
F_126 ( & V_18 -> V_57 ) ;
}
void F_127 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_8 * V_9 = V_35 -> V_20 ;
unsigned long V_41 ;
if ( V_9 -> V_173 ) {
F_19 ( & V_35 -> V_174 , V_41 ) ;
F_128 ( & V_18 -> V_175 , & V_35 -> V_176 ) ;
F_22 ( & V_35 -> V_174 , V_41 ) ;
}
}
void F_77 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_8 * V_9 = V_35 -> V_20 ;
unsigned long V_41 ;
if ( V_9 -> V_173 ) {
F_19 ( & V_35 -> V_174 , V_41 ) ;
F_98 ( F_54 ( & V_18 -> V_175 ) ) ;
F_56 ( & V_18 -> V_175 ) ;
F_22 ( & V_35 -> V_174 , V_41 ) ;
}
}
void F_129 ( struct V_22 * V_177 , struct V_17 * V_18 )
{
void * V_178 = V_18 -> V_5 ;
void * V_179 = V_18 -> V_103 ;
unsigned int V_2 = V_18 -> V_41 & V_180 ;
memset ( ( char * ) V_18 + sizeof( V_18 -> V_57 ) , 0 ,
sizeof( * V_18 ) - sizeof( V_18 -> V_57 ) + V_177 -> V_20 -> V_181 -> V_182 ) ;
V_18 -> V_21 = V_177 ;
V_18 -> V_5 = V_178 ;
V_18 -> V_103 = V_179 ;
V_18 -> V_41 = V_2 ;
F_130 ( & V_18 -> V_183 , V_184 ) ;
V_18 -> V_151 = V_152 ;
F_127 ( V_18 ) ;
}
static int F_131 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
if ( V_57 -> V_172 ) {
int V_11 = F_117 ( V_18 ) ;
if ( F_31 ( V_11 ) )
return V_11 ;
} else {
F_98 ( F_96 ( V_57 ) ) ;
memset ( & V_18 -> V_99 , 0 , sizeof( V_18 -> V_99 ) ) ;
}
V_18 -> V_66 = F_27 ( V_57 ) -> V_66 ;
V_18 -> V_73 = F_27 ( V_57 ) -> V_18 ;
V_18 -> V_185 = F_96 ( V_57 ) ;
V_18 -> V_133 = F_27 ( V_57 ) -> V_54 ;
return V_166 ;
}
static int F_132 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
if ( F_31 ( V_35 -> V_186 && V_35 -> V_186 -> V_187 ) ) {
int V_11 = V_35 -> V_186 -> V_187 ( V_35 , V_57 ) ;
if ( V_11 != V_166 )
return V_11 ;
}
V_18 -> V_73 = F_27 ( V_57 ) -> V_18 = F_27 ( V_57 ) -> V_188 ;
memset ( V_18 -> V_73 , 0 , V_189 ) ;
return F_72 ( V_18 ) -> F_133 ( V_18 ) ;
}
static int F_134 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
if ( ! F_96 ( V_57 ) )
V_18 -> V_190 = V_191 ;
else if ( F_135 ( V_57 ) == V_192 )
V_18 -> V_190 = V_61 ;
else
V_18 -> V_190 = V_193 ;
if ( F_136 ( V_57 ) )
return F_131 ( V_35 , V_57 ) ;
else
return F_132 ( V_35 , V_57 ) ;
}
static int
F_137 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
int V_11 = V_166 ;
if ( F_31 ( V_35 -> V_194 != V_195 ) ) {
switch ( V_35 -> V_194 ) {
case V_196 :
case V_197 :
F_138 ( V_198 , V_35 ,
L_5 ) ;
V_11 = V_168 ;
break;
case V_199 :
F_138 ( V_198 , V_35 ,
L_6 ) ;
V_11 = V_168 ;
break;
case V_200 :
case V_201 :
V_11 = V_164 ;
break;
case V_202 :
if ( ! ( V_57 -> V_55 & V_69 ) )
V_11 = V_164 ;
break;
default:
if ( ! ( V_57 -> V_55 & V_69 ) )
V_11 = V_168 ;
break;
}
}
return V_11 ;
}
static int
F_139 ( struct V_39 * V_40 , struct V_36 * V_57 , int V_11 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
switch ( V_11 ) {
case V_168 :
case V_203 :
F_27 ( V_57 ) -> V_43 = V_204 << 16 ;
if ( V_57 -> V_94 ) {
struct V_17 * V_18 = V_57 -> V_94 ;
F_78 ( V_18 ) ;
F_67 ( V_18 ) ;
F_14 ( & V_35 -> V_37 ) ;
V_57 -> V_94 = NULL ;
}
break;
case V_164 :
if ( F_48 ( & V_35 -> V_80 ) == 0 )
F_140 ( V_40 , V_205 ) ;
break;
default:
V_57 -> V_55 |= V_161 ;
}
return V_11 ;
}
static int F_141 ( struct V_39 * V_40 , struct V_36 * V_57 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
struct V_17 * V_18 = F_125 ( V_57 ) ;
int V_11 ;
V_11 = F_137 ( V_35 , V_57 ) ;
if ( V_11 != V_166 )
goto V_65;
if ( ! V_57 -> V_94 ) {
if ( F_31 ( ! F_142 ( & V_35 -> V_37 ) ) ) {
V_11 = V_164 ;
goto V_65;
}
F_129 ( V_35 , V_18 ) ;
V_57 -> V_94 = V_18 ;
}
V_18 -> V_206 = V_57 -> V_206 ;
V_18 -> V_36 = V_57 ;
V_18 -> V_207 = V_208 ;
V_11 = F_134 ( V_35 , V_57 ) ;
V_65:
return F_139 ( V_40 , V_57 , V_11 ) ;
}
static void F_143 ( struct V_39 * V_40 , struct V_36 * V_57 )
{
F_70 ( V_57 -> V_94 ) ;
}
static inline int F_144 ( struct V_39 * V_40 ,
struct V_22 * V_35 )
{
unsigned int V_209 ;
V_209 = F_145 ( & V_35 -> V_80 ) - 1 ;
if ( F_48 ( & V_35 -> V_30 ) ) {
if ( V_209 )
goto V_210;
if ( F_146 ( & V_35 -> V_30 ) > 0 ) {
if ( ! V_40 -> V_44 )
F_140 ( V_40 , V_205 ) ;
goto V_210;
}
F_16 ( 3 , F_138 ( V_42 , V_35 ,
L_7 ) ) ;
}
if ( V_209 >= V_35 -> V_84 )
goto V_210;
return 1 ;
V_210:
F_37 ( & V_35 -> V_80 ) ;
return 0 ;
}
static inline int F_147 ( struct V_8 * V_9 ,
struct V_22 * V_35 )
{
struct V_23 * V_24 = V_23 ( V_35 ) ;
unsigned int V_209 ;
if ( V_24 -> V_91 ) {
F_148 ( V_9 -> V_79 ) ;
if ( V_24 -> V_83 &&
V_24 -> V_83 != V_35 ) {
F_149 ( V_9 -> V_79 ) ;
return 0 ;
}
V_24 -> V_83 = V_35 ;
F_149 ( V_9 -> V_79 ) ;
}
if ( V_24 -> V_75 <= 0 )
return 1 ;
V_209 = F_145 ( & V_24 -> V_76 ) - 1 ;
if ( F_48 ( & V_24 -> V_33 ) > 0 ) {
if ( V_209 )
goto V_211;
if ( F_146 ( & V_24 -> V_33 ) > 0 )
goto V_210;
F_16 ( 3 , F_150 ( V_42 , V_24 ,
L_8 ) ) ;
}
if ( V_209 >= V_24 -> V_75 )
goto V_211;
return 1 ;
V_211:
F_148 ( V_9 -> V_79 ) ;
F_57 ( & V_35 -> V_89 , & V_9 -> V_86 ) ;
F_149 ( V_9 -> V_79 ) ;
V_210:
if ( V_24 -> V_75 > 0 )
F_37 ( & V_24 -> V_76 ) ;
return 0 ;
}
static inline int F_151 ( struct V_39 * V_40 ,
struct V_8 * V_9 ,
struct V_22 * V_35 )
{
unsigned int V_209 ;
if ( F_38 ( V_9 ) )
return 0 ;
V_209 = F_145 ( & V_9 -> V_74 ) - 1 ;
if ( F_48 ( & V_9 -> V_26 ) > 0 ) {
if ( V_209 )
goto V_211;
if ( F_146 ( & V_9 -> V_26 ) > 0 )
goto V_210;
F_16 ( 3 ,
F_152 ( V_42 , V_9 ,
L_9 ) ) ;
}
if ( V_9 -> V_75 > 0 && V_209 >= V_9 -> V_75 )
goto V_211;
if ( V_9 -> V_85 )
goto V_211;
if ( ! F_54 ( & V_35 -> V_89 ) ) {
F_148 ( V_9 -> V_79 ) ;
if ( ! F_54 ( & V_35 -> V_89 ) )
F_56 ( & V_35 -> V_89 ) ;
F_149 ( V_9 -> V_79 ) ;
}
return 1 ;
V_211:
F_148 ( V_9 -> V_79 ) ;
if ( F_54 ( & V_35 -> V_89 ) )
F_128 ( & V_35 -> V_89 , & V_9 -> V_86 ) ;
F_149 ( V_9 -> V_79 ) ;
V_210:
F_37 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_153 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
struct V_8 * V_9 ;
if ( F_154 ( V_40 ) )
return 0 ;
V_9 = V_35 -> V_20 ;
if ( F_38 ( V_9 ) || F_47 ( V_35 ) )
return 1 ;
return 0 ;
}
static void F_155 ( struct V_36 * V_57 , struct V_39 * V_40 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
struct V_22 * V_35 ;
struct V_23 * V_24 ;
struct V_8 * V_9 ;
F_156 ( V_57 ) ;
F_17 ( V_42 , V_18 , L_10 ) ;
V_35 = V_18 -> V_21 ;
V_24 = V_23 ( V_35 ) ;
V_9 = V_35 -> V_20 ;
F_34 ( V_18 ) ;
V_18 -> V_43 = V_204 << 16 ;
F_157 ( & V_18 -> V_21 -> V_212 ) ;
F_157 ( & V_35 -> V_80 ) ;
F_157 ( & V_9 -> V_74 ) ;
if ( V_24 -> V_75 > 0 )
F_157 ( & V_24 -> V_76 ) ;
F_158 ( V_57 ) ;
}
static void F_159 ( struct V_36 * V_59 )
{
struct V_17 * V_18 = V_59 -> V_94 ;
unsigned long V_132 = ( V_18 -> V_133 + 1 ) * V_59 -> V_53 ;
int V_213 ;
F_160 ( & V_18 -> V_214 ) ;
F_157 ( & V_18 -> V_21 -> V_215 ) ;
if ( V_18 -> V_43 )
F_157 ( & V_18 -> V_21 -> V_216 ) ;
V_213 = F_161 ( V_18 ) ;
if ( V_213 != V_217 &&
F_104 ( V_18 -> V_151 + V_132 , V_152 ) ) {
F_138 ( V_198 , V_18 -> V_21 ,
L_11 ,
V_132 / V_218 ) ;
V_213 = V_217 ;
}
F_162 ( V_18 , V_213 ) ;
switch ( V_213 ) {
case V_217 :
F_163 ( V_18 ) ;
break;
case V_219 :
F_23 ( V_18 , V_29 ) ;
break;
case V_220 :
F_23 ( V_18 , V_28 ) ;
break;
default:
F_164 ( V_18 ) ;
break;
}
}
static int F_165 ( struct V_17 * V_18 )
{
struct V_8 * V_20 = V_18 -> V_21 -> V_20 ;
int V_221 = 0 ;
F_157 ( & V_18 -> V_21 -> V_212 ) ;
if ( F_31 ( V_18 -> V_21 -> V_194 == V_199 ) ) {
V_18 -> V_43 = V_204 << 16 ;
goto V_222;
}
if ( F_31 ( F_166 ( V_18 -> V_21 ) ) ) {
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_12 ) ) ;
return V_28 ;
}
if ( V_18 -> V_21 -> V_223 )
V_18 -> V_73 [ 1 ] = ( V_18 -> V_73 [ 1 ] & 0x1f ) |
( V_18 -> V_21 -> V_224 << 5 & 0xe0 ) ;
F_167 ( V_18 ) ;
if ( V_18 -> V_66 > V_18 -> V_21 -> V_20 -> V_225 ) {
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_13
L_14 ,
V_18 -> V_66 , V_18 -> V_21 -> V_20 -> V_225 ) ) ;
V_18 -> V_43 = ( V_226 << 16 ) ;
goto V_222;
}
if ( F_31 ( V_20 -> V_227 == V_228 ) ) {
V_18 -> V_43 = ( V_204 << 16 ) ;
goto V_222;
}
F_168 ( V_18 ) ;
V_221 = V_20 -> V_181 -> V_229 ( V_20 , V_18 ) ;
if ( V_221 ) {
F_169 ( V_18 , V_221 ) ;
if ( V_221 != V_28 &&
V_221 != V_32 )
V_221 = V_25 ;
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_15 ) ) ;
}
return V_221 ;
V_222:
V_18 -> V_230 ( V_18 ) ;
return 0 ;
}
static void V_230 ( struct V_17 * V_18 )
{
F_170 ( V_18 ) ;
F_158 ( V_18 -> V_36 ) ;
}
static void F_171 ( struct V_39 * V_40 )
__releases( V_40 -> V_45 )
__acquires( V_40 -> V_45 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
struct V_8 * V_9 ;
struct V_17 * V_18 ;
struct V_36 * V_57 ;
V_9 = V_35 -> V_20 ;
for (; ; ) {
int V_221 ;
V_57 = F_172 ( V_40 ) ;
if ( ! V_57 )
break;
if ( F_31 ( ! F_173 ( V_35 ) ) ) {
F_138 ( V_198 , V_35 ,
L_5 ) ;
F_155 ( V_57 , V_40 ) ;
continue;
}
if ( ! F_144 ( V_40 , V_35 ) )
break;
if ( ! ( F_174 ( V_40 ) && ! F_175 ( V_40 , V_57 ) ) )
F_156 ( V_57 ) ;
F_149 ( V_40 -> V_45 ) ;
V_18 = V_57 -> V_94 ;
if ( F_31 ( V_18 == NULL ) ) {
F_176 ( V_231 L_16
L_17
L_18 ,
V_232 ) ;
F_177 ( V_57 , L_19 ) ;
F_97 () ;
}
if ( F_174 ( V_40 ) && ! ( V_57 -> V_55 & V_233 ) ) {
F_148 ( V_9 -> V_79 ) ;
if ( F_54 ( & V_35 -> V_89 ) )
F_128 ( & V_35 -> V_89 ,
& V_9 -> V_86 ) ;
F_149 ( V_9 -> V_79 ) ;
goto V_234;
}
if ( ! F_147 ( V_9 , V_35 ) )
goto V_234;
if ( ! F_151 ( V_40 , V_9 , V_35 ) )
goto V_235;
if ( V_35 -> V_236 )
V_18 -> V_41 |= V_237 ;
else
V_18 -> V_41 &= ~ V_237 ;
F_34 ( V_18 ) ;
V_18 -> V_230 = V_230 ;
V_221 = F_165 ( V_18 ) ;
if ( V_221 ) {
F_23 ( V_18 , V_221 ) ;
F_148 ( V_40 -> V_45 ) ;
goto V_238;
}
F_148 ( V_40 -> V_45 ) ;
}
return;
V_235:
if ( V_23 ( V_35 ) -> V_75 > 0 )
F_37 ( & V_23 ( V_35 ) -> V_76 ) ;
V_234:
F_148 ( V_40 -> V_45 ) ;
F_20 ( V_40 , V_57 ) ;
F_37 ( & V_35 -> V_80 ) ;
V_238:
if ( ! F_48 ( & V_35 -> V_80 ) && ! F_166 ( V_35 ) )
F_140 ( V_40 , V_205 ) ;
}
static inline T_4 F_178 ( int V_11 )
{
switch ( V_11 ) {
case V_166 :
return V_123 ;
case V_164 :
return V_239 ;
default:
return V_121 ;
}
}
static unsigned int F_179 ( struct V_8 * V_9 )
{
return F_180 (unsigned int, shost->sg_tablesize, SG_CHUNK_SIZE) *
sizeof( struct V_240 ) ;
}
static int F_181 ( struct V_36 * V_57 )
{
struct V_17 * V_18 = F_125 ( V_57 ) ;
struct V_22 * V_35 = V_57 -> V_40 -> V_90 ;
struct V_8 * V_9 = V_35 -> V_20 ;
struct V_240 * V_241 ;
F_129 ( V_35 , V_18 ) ;
V_57 -> V_94 = V_18 ;
V_18 -> V_36 = V_57 ;
V_18 -> V_206 = V_57 -> V_206 ;
V_18 -> V_207 = V_208 ;
V_241 = ( void * ) V_18 + sizeof( struct V_17 ) + V_9 -> V_181 -> V_182 ;
V_18 -> V_99 . V_100 . V_163 = V_241 ;
if ( F_182 ( V_9 ) ) {
memset ( V_18 -> V_103 , 0 , sizeof( struct V_98 ) ) ;
V_18 -> V_103 -> V_100 . V_163 =
(struct V_240 * ) ( V_18 -> V_103 + 1 ) ;
}
if ( F_99 ( V_57 ) ) {
struct V_36 * V_102 = V_57 -> V_102 ;
struct V_98 * V_104 = F_125 ( V_102 ) ;
memset ( V_104 , 0 , sizeof( struct V_98 ) ) ;
V_104 -> V_100 . V_163 =
(struct V_240 * ) ( V_104 + 1 ) ;
V_102 -> V_94 = V_104 ;
}
F_183 ( V_57 ) ;
return F_134 ( V_35 , V_57 ) ;
}
static void F_184 ( struct V_17 * V_18 )
{
F_170 ( V_18 ) ;
F_185 ( V_18 -> V_36 ) ;
}
static T_4 F_186 ( struct V_242 * V_243 ,
const struct V_244 * V_245 )
{
struct V_36 * V_57 = V_245 -> V_59 ;
struct V_39 * V_40 = V_57 -> V_40 ;
struct V_22 * V_35 = V_40 -> V_90 ;
struct V_8 * V_9 = V_35 -> V_20 ;
struct V_17 * V_18 = F_125 ( V_57 ) ;
T_4 V_11 ;
int V_19 ;
V_11 = F_178 ( F_137 ( V_35 , V_57 ) ) ;
if ( V_11 != V_123 )
goto V_65;
V_11 = V_239 ;
if ( ! F_142 ( & V_35 -> V_37 ) )
goto V_65;
if ( ! F_144 ( V_40 , V_35 ) )
goto V_246;
if ( ! F_147 ( V_9 , V_35 ) )
goto V_247;
if ( ! F_151 ( V_40 , V_9 , V_35 ) )
goto V_248;
if ( ! ( V_57 -> V_55 & V_161 ) ) {
V_11 = F_178 ( F_181 ( V_57 ) ) ;
if ( V_11 != V_123 )
goto V_249;
V_57 -> V_55 |= V_161 ;
} else {
F_183 ( V_57 ) ;
}
if ( V_35 -> V_236 )
V_18 -> V_41 |= V_237 ;
else
V_18 -> V_41 &= ~ V_237 ;
F_34 ( V_18 ) ;
V_18 -> V_230 = F_184 ;
V_19 = F_165 ( V_18 ) ;
if ( V_19 ) {
F_10 ( V_18 , V_19 ) ;
V_11 = V_239 ;
goto V_249;
}
return V_123 ;
V_249:
F_37 ( & V_9 -> V_74 ) ;
V_248:
if ( V_23 ( V_35 ) -> V_75 > 0 )
F_37 ( & V_23 ( V_35 ) -> V_76 ) ;
V_247:
F_37 ( & V_35 -> V_80 ) ;
V_246:
F_14 ( & V_35 -> V_37 ) ;
V_65:
switch ( V_11 ) {
case V_123 :
break;
case V_239 :
if ( F_48 ( & V_35 -> V_80 ) == 0 &&
! F_166 ( V_35 ) )
F_187 ( V_243 , V_205 ) ;
break;
default:
if ( V_57 -> V_55 & V_161 )
F_76 ( V_18 ) ;
break;
}
return V_11 ;
}
static enum V_250 F_188 ( struct V_36 * V_57 ,
bool V_251 )
{
if ( V_251 )
return V_252 ;
return F_189 ( V_57 ) ;
}
static int F_190 ( struct V_253 * V_254 , struct V_36 * V_59 ,
unsigned int V_255 , unsigned int V_7 )
{
struct V_8 * V_9 = V_254 -> V_256 ;
const bool V_2 = V_9 -> V_2 ;
struct V_17 * V_18 = F_125 ( V_59 ) ;
struct V_240 * V_241 ;
if ( V_2 )
V_18 -> V_41 |= V_180 ;
V_18 -> V_5 = F_4 ( V_2 ,
V_257 , V_7 ) ;
if ( ! V_18 -> V_5 )
return - V_16 ;
V_18 -> V_57 . V_50 = V_18 -> V_5 ;
if ( F_182 ( V_9 ) ) {
V_241 = ( void * ) V_18 + sizeof( struct V_17 ) +
V_9 -> V_181 -> V_182 ;
V_18 -> V_103 = ( void * ) V_241 + F_179 ( V_9 ) ;
}
return 0 ;
}
static void F_191 ( struct V_253 * V_254 , struct V_36 * V_59 ,
unsigned int V_255 )
{
struct V_17 * V_18 = F_125 ( V_59 ) ;
F_2 ( V_18 -> V_41 & V_180 ,
V_18 -> V_5 ) ;
}
static int F_192 ( struct V_253 * V_254 )
{
struct V_8 * V_9 = F_64 ( V_254 , struct V_8 , V_258 ) ;
if ( V_9 -> V_181 -> V_259 )
return V_9 -> V_181 -> V_259 ( V_9 ) ;
return F_193 ( V_254 ) ;
}
static T_2 F_194 ( struct V_8 * V_9 )
{
struct V_21 * V_260 ;
T_2 V_261 = 0xffffffff ;
if ( V_9 -> V_2 )
return V_262 ;
if ( ! V_263 )
return V_264 ;
V_260 = F_195 ( V_9 ) ;
if ( V_260 && V_260 -> V_265 )
V_261 = ( T_2 ) F_196 ( V_260 ) << V_266 ;
return V_261 ;
}
void F_197 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
struct V_21 * V_177 = V_9 -> V_267 ;
F_198 ( V_268 , V_40 ) ;
F_199 ( V_40 , F_180 (unsigned short, shost->sg_tablesize,
SG_MAX_SEGMENTS) ) ;
if ( F_200 ( V_9 ) ) {
V_9 -> V_269 =
F_201 ( V_9 -> V_269 ,
( unsigned short ) V_270 ) ;
F_98 ( V_9 -> V_269 < V_9 -> V_271 ) ;
F_202 ( V_40 , V_9 -> V_269 ) ;
}
F_203 ( V_40 , V_9 -> V_272 ) ;
F_204 ( V_40 , F_194 ( V_9 ) ) ;
F_205 ( V_40 , V_9 -> V_273 ) ;
F_206 ( V_177 , V_9 -> V_273 ) ;
F_207 ( V_40 , F_208 ( V_177 ) ) ;
if ( ! V_9 -> V_274 )
V_40 -> V_275 . V_276 = 0 ;
F_209 ( V_40 , 0x03 ) ;
}
static int F_210 ( struct V_39 * V_40 , struct V_36 * V_59 , T_1 V_277 )
{
struct V_8 * V_9 = V_40 -> V_278 ;
const bool V_2 = V_9 -> V_2 ;
struct V_17 * V_18 = F_125 ( V_59 ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
if ( V_2 )
V_18 -> V_41 |= V_180 ;
V_18 -> V_5 = F_4 ( V_2 , V_277 ,
V_279 ) ;
if ( ! V_18 -> V_5 )
goto V_280;
V_18 -> V_57 . V_50 = V_18 -> V_5 ;
if ( F_182 ( V_9 ) >= V_281 ) {
V_18 -> V_103 = F_119 ( V_105 , V_277 ) ;
if ( ! V_18 -> V_103 )
goto V_282;
}
return 0 ;
V_282:
F_2 ( V_2 , V_18 -> V_5 ) ;
V_280:
return - V_16 ;
}
static void F_211 ( struct V_39 * V_40 , struct V_36 * V_59 )
{
struct V_17 * V_18 = F_125 ( V_59 ) ;
if ( V_18 -> V_103 )
F_3 ( V_105 , V_18 -> V_103 ) ;
F_2 ( V_18 -> V_41 & V_180 ,
V_18 -> V_5 ) ;
}
struct V_39 * F_212 ( struct V_22 * V_35 )
{
struct V_8 * V_9 = V_35 -> V_20 ;
struct V_39 * V_40 ;
V_40 = F_213 ( V_257 , V_279 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_182 = sizeof( struct V_17 ) + V_9 -> V_181 -> V_182 ;
V_40 -> V_278 = V_9 ;
V_40 -> V_283 = F_171 ;
V_40 -> V_284 = F_210 ;
V_40 -> V_285 = F_211 ;
V_40 -> V_286 = F_124 ;
if ( F_214 ( V_40 ) < 0 ) {
F_215 ( V_40 ) ;
return NULL ;
}
F_197 ( V_9 , V_40 ) ;
F_216 ( V_40 , F_141 ) ;
F_217 ( V_40 , F_143 ) ;
F_218 ( V_40 , F_159 ) ;
F_219 ( V_40 , F_189 ) ;
F_220 ( V_40 , F_153 ) ;
return V_40 ;
}
struct V_39 * F_221 ( struct V_22 * V_35 )
{
V_35 -> V_39 = F_222 ( & V_35 -> V_20 -> V_258 ) ;
if ( F_26 ( V_35 -> V_39 ) )
return NULL ;
V_35 -> V_39 -> V_90 = V_35 ;
F_197 ( V_35 -> V_20 , V_35 -> V_39 ) ;
return V_35 -> V_39 ;
}
int F_223 ( struct V_8 * V_9 )
{
unsigned int V_182 , V_287 ;
V_287 = F_179 ( V_9 ) ;
V_182 = sizeof( struct V_17 ) + V_9 -> V_181 -> V_182 + V_287 ;
if ( F_182 ( V_9 ) )
V_182 += sizeof( struct V_98 ) + V_287 ;
memset ( & V_9 -> V_258 , 0 , sizeof( V_9 -> V_258 ) ) ;
V_9 -> V_258 . V_288 = & V_289 ;
V_9 -> V_258 . V_290 = V_9 -> V_290 ? : 1 ;
V_9 -> V_258 . V_84 = V_9 -> V_75 ;
V_9 -> V_258 . V_182 = V_182 ;
V_9 -> V_258 . V_7 = V_279 ;
V_9 -> V_258 . V_41 = V_291 | V_292 ;
V_9 -> V_258 . V_41 |=
F_224 ( V_9 -> V_181 -> V_293 ) ;
V_9 -> V_258 . V_256 = V_9 ;
return F_225 ( & V_9 -> V_258 ) ;
}
void F_226 ( struct V_8 * V_9 )
{
F_227 ( & V_9 -> V_258 ) ;
}
struct V_22 * F_228 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = NULL ;
if ( V_40 -> V_44 ) {
if ( V_40 -> V_44 == & V_289 )
V_35 = V_40 -> V_90 ;
} else if ( V_40 -> V_283 == F_171 )
V_35 = V_40 -> V_90 ;
if ( ! V_35 || ! F_142 ( & V_35 -> V_37 ) )
V_35 = NULL ;
return V_35 ;
}
void F_229 ( struct V_8 * V_9 )
{
V_9 -> V_85 = 1 ;
}
void F_230 ( struct V_8 * V_9 )
{
V_9 -> V_85 = 0 ;
F_68 ( V_9 ) ;
}
int T_5 F_231 ( void )
{
V_105 = F_8 ( L_20 ,
sizeof( struct V_98 ) ,
0 , 0 , NULL ) ;
if ( ! V_105 ) {
F_176 ( V_198 L_21 ) ;
return - V_16 ;
}
return 0 ;
}
void F_232 ( void )
{
F_233 ( V_4 ) ;
F_233 ( V_3 ) ;
F_233 ( V_105 ) ;
}
int
F_234 ( struct V_22 * V_35 , int V_294 , int V_295 , int V_296 ,
unsigned char * V_48 , int V_297 , int V_53 , int V_54 ,
struct V_298 * V_299 , struct V_51 * V_52 )
{
unsigned char V_18 [ 10 ] ;
unsigned char * V_300 ;
int V_11 ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 1 ] = ( V_294 ? 0x10 : 0 ) | ( V_295 ? 0x01 : 0 ) ;
if ( V_35 -> V_301 ) {
if ( V_297 > 65535 )
return - V_302 ;
V_300 = F_235 ( 8 + V_297 , V_257 ) ;
if ( ! V_300 )
return - V_16 ;
memcpy ( V_300 + 8 , V_48 , V_297 ) ;
V_297 += 8 ;
V_300 [ 0 ] = 0 ;
V_300 [ 1 ] = 0 ;
V_300 [ 2 ] = V_299 -> V_303 ;
V_300 [ 3 ] = V_299 -> V_304 ;
V_300 [ 4 ] = V_299 -> V_305 ? 0x01 : 0 ;
V_300 [ 5 ] = 0 ;
V_300 [ 6 ] = V_299 -> V_306 >> 8 ;
V_300 [ 7 ] = V_299 -> V_306 ;
V_18 [ 0 ] = V_307 ;
V_18 [ 7 ] = V_297 >> 8 ;
V_18 [ 8 ] = V_297 ;
} else {
if ( V_297 > 255 || V_299 -> V_306 > 255 ||
V_299 -> V_305 )
return - V_302 ;
V_300 = F_235 ( 4 + V_297 , V_257 ) ;
if ( ! V_300 )
return - V_16 ;
memcpy ( V_300 + 4 , V_48 , V_297 ) ;
V_297 += 4 ;
V_300 [ 0 ] = 0 ;
V_300 [ 1 ] = V_299 -> V_303 ;
V_300 [ 2 ] = V_299 -> V_304 ;
V_300 [ 3 ] = V_299 -> V_306 ;
V_18 [ 0 ] = V_308 ;
V_18 [ 4 ] = V_297 ;
}
V_11 = F_236 ( V_35 , V_18 , V_61 , V_300 , V_297 ,
V_52 , V_53 , V_54 , NULL ) ;
F_237 ( V_300 ) ;
return V_11 ;
}
int
F_238 ( struct V_22 * V_35 , int V_309 , int V_296 ,
unsigned char * V_48 , int V_297 , int V_53 , int V_54 ,
struct V_298 * V_299 , struct V_51 * V_52 )
{
unsigned char V_18 [ 12 ] ;
int V_301 ;
int V_310 ;
int V_43 , V_311 = V_54 ;
struct V_51 V_312 ;
memset ( V_299 , 0 , sizeof( * V_299 ) ) ;
memset ( & V_18 [ 0 ] , 0 , 12 ) ;
V_18 [ 1 ] = V_309 & 0x18 ;
V_18 [ 2 ] = V_296 ;
if ( ! V_52 )
V_52 = & V_312 ;
V_313:
V_301 = V_35 -> V_301 ;
if ( V_301 ) {
if ( V_297 < 8 )
V_297 = 8 ;
V_18 [ 0 ] = V_314 ;
V_18 [ 8 ] = V_297 ;
V_310 = 8 ;
} else {
if ( V_297 < 4 )
V_297 = 4 ;
V_18 [ 0 ] = V_315 ;
V_18 [ 4 ] = V_297 ;
V_310 = 4 ;
}
memset ( V_48 , 0 , V_297 ) ;
V_43 = F_236 ( V_35 , V_18 , V_193 , V_48 , V_297 ,
V_52 , V_53 , V_54 , NULL ) ;
if ( V_301 && ! F_239 ( V_43 ) &&
( F_109 ( V_43 ) & V_160 ) ) {
if ( F_240 ( V_52 ) ) {
if ( ( V_52 -> V_134 == V_143 ) &&
( V_52 -> V_136 == 0x20 ) && ( V_52 -> V_137 == 0 ) ) {
V_35 -> V_301 = 0 ;
goto V_313;
}
}
}
if( F_239 ( V_43 ) ) {
if ( F_31 ( V_48 [ 0 ] == 0x86 && V_48 [ 1 ] == 0x0b &&
( V_296 == 6 || V_296 == 8 ) ) ) {
V_310 = 0 ;
V_299 -> V_165 = 13 ;
V_299 -> V_303 = 0 ;
V_299 -> V_304 = 0 ;
V_299 -> V_305 = 0 ;
V_299 -> V_306 = 0 ;
} else if( V_301 ) {
V_299 -> V_165 = V_48 [ 0 ] * 256 + V_48 [ 1 ] + 2 ;
V_299 -> V_303 = V_48 [ 2 ] ;
V_299 -> V_304 = V_48 [ 3 ] ;
V_299 -> V_305 = V_48 [ 4 ] & 0x01 ;
V_299 -> V_306 = V_48 [ 6 ] * 256
+ V_48 [ 7 ] ;
} else {
V_299 -> V_165 = V_48 [ 0 ] + 1 ;
V_299 -> V_303 = V_48 [ 1 ] ;
V_299 -> V_304 = V_48 [ 2 ] ;
V_299 -> V_306 = V_48 [ 3 ] ;
}
V_299 -> V_310 = V_310 ;
} else if ( ( F_241 ( V_43 ) == V_316 ) &&
F_240 ( V_52 ) &&
V_52 -> V_134 == V_140 && V_311 ) {
V_311 -- ;
goto V_313;
}
return V_43 ;
}
int
F_242 ( struct V_22 * V_35 , int V_53 , int V_54 ,
struct V_51 * V_52 )
{
char V_18 [] = {
V_317 , 0 , 0 , 0 , 0 , 0 ,
} ;
int V_43 ;
do {
V_43 = F_236 ( V_35 , V_18 , V_191 , NULL , 0 , V_52 ,
V_53 , V_54 , NULL ) ;
if ( V_35 -> V_141 && F_240 ( V_52 ) &&
V_52 -> V_134 == V_140 )
V_35 -> V_142 = 1 ;
} while ( F_240 ( V_52 ) &&
V_52 -> V_134 == V_140 && -- V_54 );
return V_43 ;
}
int
F_243 ( struct V_22 * V_35 , enum V_318 V_319 )
{
enum V_318 V_320 = V_35 -> V_194 ;
if ( V_319 == V_320 )
return 0 ;
switch ( V_319 ) {
case V_321 :
switch ( V_320 ) {
case V_201 :
break;
default:
goto V_322;
}
break;
case V_195 :
switch ( V_320 ) {
case V_321 :
case V_196 :
case V_197 :
case V_202 :
case V_200 :
break;
default:
goto V_322;
}
break;
case V_202 :
switch ( V_320 ) {
case V_195 :
case V_196 :
case V_197 :
break;
default:
goto V_322;
}
break;
case V_196 :
case V_197 :
switch ( V_320 ) {
case V_321 :
case V_195 :
case V_202 :
case V_200 :
break;
default:
goto V_322;
}
break;
case V_200 :
switch ( V_320 ) {
case V_195 :
case V_201 :
break;
default:
goto V_322;
}
break;
case V_201 :
switch ( V_320 ) {
case V_321 :
break;
default:
goto V_322;
}
break;
case V_323 :
switch ( V_320 ) {
case V_321 :
case V_195 :
case V_202 :
case V_196 :
case V_197 :
break;
default:
goto V_322;
}
break;
case V_199 :
switch ( V_320 ) {
case V_321 :
case V_195 :
case V_196 :
case V_197 :
case V_323 :
case V_200 :
case V_201 :
break;
default:
goto V_322;
}
break;
}
V_35 -> V_194 = V_319 ;
return 0 ;
V_322:
F_244 ( 1 ,
F_138 ( V_198 , V_35 ,
L_22 ,
F_245 ( V_320 ) ,
F_245 ( V_319 ) )
) ;
return - V_302 ;
}
static void F_246 ( struct V_22 * V_35 , struct V_324 * V_325 )
{
int V_326 = 0 ;
char * V_327 [ 3 ] ;
switch ( V_325 -> V_328 ) {
case V_329 :
V_327 [ V_326 ++ ] = L_23 ;
break;
case V_330 :
F_247 ( & V_35 -> V_37 ) ;
V_327 [ V_326 ++ ] = L_24 ;
break;
case V_331 :
V_327 [ V_326 ++ ] = L_25 ;
break;
case V_332 :
V_327 [ V_326 ++ ] = L_26 ;
break;
case V_333 :
V_327 [ V_326 ++ ] = L_27 ;
break;
case V_334 :
V_327 [ V_326 ++ ] = L_28 ;
break;
case V_335 :
V_327 [ V_326 ++ ] = L_29 ;
break;
default:
break;
}
V_327 [ V_326 ++ ] = NULL ;
F_248 ( & V_35 -> V_37 . V_336 , V_337 , V_327 ) ;
}
void F_249 ( struct V_92 * V_93 )
{
struct V_22 * V_35 ;
enum V_338 V_328 ;
F_52 ( V_339 ) ;
V_35 = F_64 ( V_93 , struct V_22 , V_340 ) ;
for ( V_328 = V_341 ; V_328 <= V_342 ; V_328 ++ )
if ( F_250 ( V_328 , V_35 -> V_343 ) )
F_251 ( V_35 , V_328 , V_257 ) ;
while ( 1 ) {
struct V_324 * V_325 ;
struct V_344 * V_345 , * V_82 ;
unsigned long V_41 ;
F_19 ( & V_35 -> V_174 , V_41 ) ;
F_53 ( & V_35 -> V_339 , & V_339 ) ;
F_22 ( & V_35 -> V_174 , V_41 ) ;
if ( F_54 ( & V_339 ) )
break;
F_252 (this, tmp, &event_list) {
V_325 = F_55 ( V_345 , struct V_324 , V_346 ) ;
F_253 ( & V_325 -> V_346 ) ;
F_246 ( V_35 , V_325 ) ;
F_237 ( V_325 ) ;
}
}
}
void F_254 ( struct V_22 * V_35 , struct V_324 * V_325 )
{
unsigned long V_41 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_19 ( & V_35 -> V_174 , V_41 ) ;
F_128 ( & V_325 -> V_346 , & V_35 -> V_339 ) ;
F_255 ( & V_35 -> V_340 ) ;
F_22 ( & V_35 -> V_174 , V_41 ) ;
}
struct V_324 * F_256 ( enum V_338 V_328 ,
T_1 V_347 )
{
struct V_324 * V_325 = F_257 ( sizeof( struct V_324 ) , V_347 ) ;
if ( ! V_325 )
return NULL ;
V_325 -> V_328 = V_328 ;
F_160 ( & V_325 -> V_346 ) ;
switch ( V_328 ) {
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
default:
break;
}
return V_325 ;
}
void F_251 ( struct V_22 * V_35 ,
enum V_338 V_328 , T_1 V_347 )
{
struct V_324 * V_325 = F_256 ( V_328 , V_347 ) ;
if ( ! V_325 ) {
F_138 ( V_198 , V_35 , L_30 ,
V_328 ) ;
return;
}
F_254 ( V_35 , V_325 ) ;
}
static int F_258 ( struct V_22 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
int V_348 ;
F_118 ( V_35 -> V_20 -> V_349 ) ;
F_148 ( V_40 -> V_45 ) ;
V_348 = V_40 -> V_348 ;
F_149 ( V_40 -> V_45 ) ;
return V_348 ;
}
static void F_259 ( struct V_22 * V_35 )
{
F_118 ( V_35 -> V_20 -> V_349 ) ;
while ( F_258 ( V_35 ) )
F_260 ( 20 ) ;
}
int
F_261 ( struct V_22 * V_35 )
{
int V_350 ;
F_7 ( & V_35 -> V_351 ) ;
V_350 = F_243 ( V_35 , V_202 ) ;
F_9 ( & V_35 -> V_351 ) ;
if ( V_350 )
return V_350 ;
F_61 ( V_35 -> V_39 ) ;
while ( F_48 ( & V_35 -> V_80 ) ) {
F_262 ( 200 ) ;
F_61 ( V_35 -> V_39 ) ;
}
return 0 ;
}
void F_263 ( struct V_22 * V_35 )
{
F_7 ( & V_35 -> V_351 ) ;
if ( V_35 -> V_194 == V_202 &&
F_243 ( V_35 , V_195 ) == 0 )
F_61 ( V_35 -> V_39 ) ;
F_9 ( & V_35 -> V_351 ) ;
}
static void
F_264 ( struct V_22 * V_35 , void * V_299 )
{
F_261 ( V_35 ) ;
}
void
F_265 ( struct V_23 * V_24 )
{
F_266 ( V_24 , NULL , F_264 ) ;
}
static void
F_267 ( struct V_22 * V_35 , void * V_299 )
{
F_263 ( V_35 ) ;
}
void
F_268 ( struct V_23 * V_24 )
{
F_266 ( V_24 , NULL , F_267 ) ;
}
int F_269 ( struct V_22 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
unsigned long V_41 ;
int V_350 = 0 ;
V_350 = F_243 ( V_35 , V_200 ) ;
if ( V_350 ) {
V_350 = F_243 ( V_35 , V_201 ) ;
if ( V_350 )
return V_350 ;
}
if ( V_40 -> V_44 ) {
F_270 ( V_40 ) ;
} else {
F_19 ( V_40 -> V_45 , V_41 ) ;
F_271 ( V_40 ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
}
return 0 ;
}
static int F_272 ( struct V_22 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
int V_350 ;
F_7 ( & V_35 -> V_351 ) ;
V_350 = F_269 ( V_35 ) ;
if ( V_350 == 0 ) {
if ( V_40 -> V_44 )
F_273 ( V_40 ) ;
else
F_259 ( V_35 ) ;
}
F_9 ( & V_35 -> V_351 ) ;
return V_350 ;
}
void F_274 ( struct V_22 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
unsigned long V_41 ;
if ( V_40 -> V_44 ) {
F_275 ( V_40 ) ;
} else {
F_19 ( V_40 -> V_45 , V_41 ) ;
F_276 ( V_40 ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
}
}
int F_277 ( struct V_22 * V_35 ,
enum V_318 V_352 )
{
if ( ( V_35 -> V_194 == V_200 ) ||
( V_35 -> V_194 == V_197 ) )
V_35 -> V_194 = V_352 ;
else if ( V_35 -> V_194 == V_201 ) {
if ( V_352 == V_197 ||
V_352 == V_196 )
V_35 -> V_194 = V_352 ;
else
V_35 -> V_194 = V_321 ;
} else if ( V_35 -> V_194 != V_323 &&
V_35 -> V_194 != V_196 )
return - V_302 ;
F_274 ( V_35 ) ;
return 0 ;
}
static int F_278 ( struct V_22 * V_35 ,
enum V_318 V_352 )
{
int V_11 ;
F_7 ( & V_35 -> V_351 ) ;
V_11 = F_277 ( V_35 , V_352 ) ;
F_9 ( & V_35 -> V_351 ) ;
return V_11 ;
}
static void
F_279 ( struct V_22 * V_35 , void * V_299 )
{
F_272 ( V_35 ) ;
}
static int
F_280 ( struct V_21 * V_177 , void * V_299 )
{
if ( F_281 ( V_177 ) )
F_266 ( F_282 ( V_177 ) , NULL ,
F_279 ) ;
return 0 ;
}
void
F_283 ( struct V_21 * V_177 )
{
if ( F_281 ( V_177 ) )
F_266 ( F_282 ( V_177 ) , NULL ,
F_279 ) ;
else
F_284 ( V_177 , NULL , F_280 ) ;
}
static void
F_285 ( struct V_22 * V_35 , void * V_299 )
{
F_278 ( V_35 , * (enum V_318 * ) V_299 ) ;
}
static int
F_286 ( struct V_21 * V_177 , void * V_299 )
{
if ( F_281 ( V_177 ) )
F_266 ( F_282 ( V_177 ) , V_299 ,
F_285 ) ;
return 0 ;
}
void
F_287 ( struct V_21 * V_177 , enum V_318 V_352 )
{
if ( F_281 ( V_177 ) )
F_266 ( F_282 ( V_177 ) , & V_352 ,
F_285 ) ;
else
F_284 ( V_177 , & V_352 , F_286 ) ;
}
void * F_288 ( struct V_240 * V_163 , int V_353 ,
T_6 * V_354 , T_6 * V_297 )
{
int V_355 ;
T_6 V_356 = 0 , V_357 = 0 ;
struct V_240 * V_241 ;
struct V_358 * V_358 ;
F_289 ( ! F_290 () ) ;
F_291 (sgl, sg, sg_count, i) {
V_357 = V_356 ;
V_356 += V_241 -> V_165 ;
if ( V_356 > * V_354 )
break;
}
if ( F_31 ( V_355 == V_353 ) ) {
F_176 ( V_198 L_31
L_32 ,
V_232 , V_356 , * V_354 , V_353 ) ;
F_289 ( 1 ) ;
return NULL ;
}
* V_354 = * V_354 - V_357 + V_241 -> V_354 ;
V_358 = F_292 ( F_293 ( V_241 ) , ( * V_354 >> V_266 ) ) ;
* V_354 &= ~ V_359 ;
V_356 = V_360 - * V_354 ;
if ( * V_297 > V_356 )
* V_297 = V_356 ;
return F_294 ( V_358 ) ;
}
void F_295 ( void * V_361 )
{
F_296 ( V_361 ) ;
}
void F_297 ( struct V_22 * V_35 )
{
F_157 ( & V_35 -> V_362 ) ;
}
void F_298 ( struct V_22 * V_35 )
{
if ( F_118 ( F_48 ( & V_35 -> V_362 ) <= 0 ) )
return;
F_37 ( & V_35 -> V_362 ) ;
}
int F_299 ( struct V_22 * V_35 , char * V_363 , T_6 V_364 )
{
T_7 V_365 = 0xff ;
T_7 V_366 = 0 ;
unsigned char * V_367 , * V_368 ;
unsigned char T_8 * V_369 ;
int V_370 = - V_302 ;
F_300 () ;
V_369 = F_301 ( V_35 -> V_369 ) ;
if ( ! V_369 ) {
F_302 () ;
return - V_371 ;
}
if ( V_364 < 21 ) {
F_302 () ;
return - V_302 ;
}
memset ( V_363 , 0 , V_364 ) ;
V_367 = V_369 + 4 ;
while ( V_367 < V_369 + V_35 -> V_372 ) {
if ( ( V_367 [ 1 ] & 0x30 ) != 0x00 )
goto V_373;
switch ( V_367 [ 1 ] & 0xf ) {
case 0x1 :
if ( V_366 > V_367 [ 3 ] )
break;
if ( V_365 > 0x01 && V_365 != 0xff )
break;
V_366 = V_367 [ 3 ] ;
if ( V_366 + 4 > V_364 )
V_366 = V_364 - 4 ;
V_368 = V_367 + 4 ;
V_365 = V_367 [ 1 ] & 0xf ;
V_370 = snprintf ( V_363 , V_364 , L_33 ,
V_366 , V_368 ) ;
break;
case 0x2 :
if ( V_366 > V_367 [ 3 ] )
break;
if ( V_365 == 0x3 &&
V_366 == V_367 [ 3 ] )
break;
V_366 = V_367 [ 3 ] ;
V_368 = V_367 + 4 ;
V_365 = V_367 [ 1 ] & 0xf ;
switch ( V_366 ) {
case 8 :
V_370 = snprintf ( V_363 , V_364 ,
L_34 ,
V_368 ) ;
break;
case 12 :
V_370 = snprintf ( V_363 , V_364 ,
L_35 ,
V_368 ) ;
break;
case 16 :
V_370 = snprintf ( V_363 , V_364 ,
L_36 ,
V_368 ) ;
break;
default:
V_366 = 0 ;
break;
}
break;
case 0x3 :
if ( V_366 > V_367 [ 3 ] )
break;
V_366 = V_367 [ 3 ] ;
V_368 = V_367 + 4 ;
V_365 = V_367 [ 1 ] & 0xf ;
switch ( V_366 ) {
case 8 :
V_370 = snprintf ( V_363 , V_364 ,
L_37 ,
V_368 ) ;
break;
case 16 :
V_370 = snprintf ( V_363 , V_364 ,
L_38 ,
V_368 ) ;
break;
default:
V_366 = 0 ;
break;
}
break;
case 0x8 :
if ( V_366 + 4 > V_367 [ 3 ] )
break;
if ( V_366 && V_367 [ 3 ] > V_364 )
break;
V_366 = V_370 = V_367 [ 3 ] ;
V_368 = V_367 + 4 ;
V_365 = V_367 [ 1 ] & 0xf ;
if ( V_366 >= V_364 )
V_366 = V_364 - 1 ;
memcpy ( V_363 , V_368 , V_366 ) ;
if ( V_366 != V_370 )
V_366 = 6 ;
break;
default:
break;
}
V_373:
V_367 += V_367 [ 3 ] + 4 ;
}
F_302 () ;
return V_370 ;
}
int F_303 ( struct V_22 * V_35 , int * V_374 )
{
unsigned char * V_367 ;
unsigned char T_8 * V_369 ;
int V_375 = - V_376 , V_377 = - 1 ;
F_300 () ;
V_369 = F_301 ( V_35 -> V_369 ) ;
if ( ! V_369 ) {
F_302 () ;
return - V_371 ;
}
V_367 = V_35 -> V_369 + 4 ;
while ( V_367 < V_35 -> V_369 + V_35 -> V_372 ) {
switch ( V_367 [ 1 ] & 0xf ) {
case 0x4 :
V_377 = F_304 ( & V_367 [ 6 ] ) ;
break;
case 0x5 :
V_375 = F_304 ( & V_367 [ 6 ] ) ;
break;
default:
break;
}
V_367 += V_367 [ 3 ] + 4 ;
}
F_302 () ;
if ( V_375 >= 0 && V_374 && V_377 != - 1 )
* V_374 = V_377 ;
return V_375 ;
}
