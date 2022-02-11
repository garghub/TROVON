static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ?
V_5 : V_6 ;
}
static void F_2 ( struct V_2 * V_3 ,
unsigned char * V_7 )
{
F_3 ( F_1 ( V_3 ) , V_7 ) ;
}
static unsigned char * F_4 ( struct V_2 * V_3 ,
T_1 V_8 , int V_9 )
{
return F_5 ( F_1 ( V_3 ) , V_8 ,
V_9 ) ;
}
int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_10 ;
int V_11 = 0 ;
V_10 = F_1 ( V_3 ) ;
if ( V_10 )
return 0 ;
F_7 ( & V_12 ) ;
if ( V_3 -> V_4 ) {
V_5 =
F_8 ( L_1 ,
V_13 , 0 ,
V_14 | V_15 , NULL ) ;
if ( ! V_5 )
V_11 = - V_16 ;
} else {
V_6 =
F_8 ( L_2 ,
V_13 , 0 , V_14 , NULL ) ;
if ( ! V_6 )
V_11 = - V_16 ;
}
F_9 ( & V_12 ) ;
return V_11 ;
}
static void
F_10 ( struct V_17 * V_18 , int V_19 )
{
struct V_2 * V_20 = V_18 -> V_21 -> V_20 ;
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
F_28 ( V_57 ) ;
if ( V_49 && F_29 ( V_35 -> V_39 , V_57 ,
V_48 , V_49 , V_64 ) )
goto V_65;
V_59 -> V_66 = F_30 ( V_18 [ 0 ] ) ;
memcpy ( V_59 -> V_18 , V_18 , V_59 -> V_66 ) ;
V_57 -> V_54 = V_54 ;
V_57 -> V_53 = V_53 ;
V_57 -> V_67 |= V_41 ;
V_57 -> V_55 |= V_55 | V_68 | V_69 ;
F_31 ( V_57 -> V_40 , NULL , V_57 , 1 ) ;
if ( F_32 ( V_59 -> V_70 > 0 && V_59 -> V_70 <= V_49 ) )
memset ( V_48 + ( V_49 - V_59 -> V_70 ) , 0 , V_59 -> V_70 ) ;
if ( V_56 )
* V_56 = V_59 -> V_70 ;
if ( V_50 && V_59 -> V_71 )
memcpy ( V_50 , V_59 -> V_50 , V_13 ) ;
if ( V_52 )
F_33 ( V_59 -> V_50 , V_59 -> V_71 , V_52 ) ;
V_11 = V_57 -> V_72 ;
V_65:
F_34 ( V_57 ) ;
return V_11 ;
}
static void F_35 ( struct V_17 * V_18 )
{
V_18 -> V_73 = 0 ;
F_36 ( V_18 , 0 ) ;
memset ( V_18 -> V_7 , 0 , V_13 ) ;
if ( V_18 -> V_66 == 0 )
V_18 -> V_66 = F_37 ( V_18 -> V_74 ) ;
}
void F_18 ( struct V_22 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_20 ;
struct V_23 * V_24 = V_23 ( V_35 ) ;
unsigned long V_41 ;
F_38 ( & V_3 -> V_75 ) ;
if ( V_24 -> V_76 > 0 )
F_38 ( & V_24 -> V_77 ) ;
if ( F_32 ( F_39 ( V_3 ) &&
( V_3 -> V_78 || V_3 -> V_79 ) ) ) {
F_19 ( V_3 -> V_80 , V_41 ) ;
F_40 ( V_3 ) ;
F_22 ( V_3 -> V_80 , V_41 ) ;
}
F_38 ( & V_35 -> V_81 ) ;
}
static void F_41 ( struct V_39 * V_40 )
{
if ( V_40 -> V_44 )
F_42 ( V_40 ) ;
else
F_43 ( V_40 ) ;
}
static void F_44 ( struct V_22 * V_82 )
{
struct V_2 * V_3 = V_82 -> V_20 ;
struct V_22 * V_35 , * V_83 ;
struct V_23 * V_24 = V_23 ( V_82 ) ;
unsigned long V_41 ;
F_19 ( V_3 -> V_80 , V_41 ) ;
V_24 -> V_84 = NULL ;
F_22 ( V_3 -> V_80 , V_41 ) ;
F_41 ( V_82 -> V_39 ) ;
F_19 ( V_3 -> V_80 , V_41 ) ;
if ( V_24 -> V_84 )
goto V_65;
F_45 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_35 == V_82 )
continue;
if ( F_46 ( V_35 ) )
continue;
F_22 ( V_3 -> V_80 , V_41 ) ;
F_41 ( V_35 -> V_39 ) ;
F_19 ( V_3 -> V_80 , V_41 ) ;
F_47 ( V_35 ) ;
}
V_65:
F_22 ( V_3 -> V_80 , V_41 ) ;
}
static inline bool F_48 ( struct V_22 * V_35 )
{
if ( F_49 ( & V_35 -> V_81 ) >= V_35 -> V_85 )
return true ;
if ( F_49 ( & V_35 -> V_30 ) > 0 )
return true ;
return false ;
}
static inline bool F_50 ( struct V_23 * V_24 )
{
if ( V_24 -> V_76 > 0 ) {
if ( F_49 ( & V_24 -> V_77 ) >= V_24 -> V_76 )
return true ;
if ( F_49 ( & V_24 -> V_33 ) > 0 )
return true ;
}
return false ;
}
static inline bool F_51 ( struct V_2 * V_3 )
{
if ( V_3 -> V_76 > 0 &&
F_49 ( & V_3 -> V_75 ) >= V_3 -> V_76 )
return true ;
if ( F_49 ( & V_3 -> V_26 ) > 0 )
return true ;
if ( V_3 -> V_86 )
return true ;
return false ;
}
static void F_52 ( struct V_2 * V_3 )
{
F_53 ( V_87 ) ;
struct V_22 * V_35 ;
unsigned long V_41 ;
F_19 ( V_3 -> V_80 , V_41 ) ;
F_54 ( & V_3 -> V_87 , & V_87 ) ;
while ( ! F_55 ( & V_87 ) ) {
struct V_39 * V_88 ;
if ( F_51 ( V_3 ) )
break;
V_35 = F_56 ( V_87 . V_89 ,
struct V_22 , V_90 ) ;
F_57 ( & V_35 -> V_90 ) ;
if ( F_50 ( V_23 ( V_35 ) ) ) {
F_58 ( & V_35 -> V_90 ,
& V_3 -> V_87 ) ;
continue;
}
V_88 = V_35 -> V_39 ;
if ( ! F_59 ( V_88 ) )
continue;
F_22 ( V_3 -> V_80 , V_41 ) ;
F_41 ( V_88 ) ;
F_60 ( V_88 ) ;
F_19 ( V_3 -> V_80 , V_41 ) ;
}
F_61 ( & V_87 , & V_3 -> V_87 ) ;
F_22 ( V_3 -> V_80 , V_41 ) ;
}
static void F_62 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = V_40 -> V_91 ;
if ( V_23 ( V_35 ) -> V_92 )
F_44 ( V_35 ) ;
if ( ! F_55 ( & V_35 -> V_20 -> V_87 ) )
F_52 ( V_35 -> V_20 ) ;
if ( V_40 -> V_44 )
F_63 ( V_40 , false ) ;
else
F_43 ( V_40 ) ;
}
void F_64 ( struct V_93 * V_94 )
{
struct V_22 * V_35 ;
struct V_39 * V_40 ;
V_35 = F_65 ( V_94 , struct V_22 , V_46 ) ;
V_40 = V_35 -> V_39 ;
F_62 ( V_40 ) ;
}
static void F_66 ( struct V_39 * V_40 , struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_36 * V_57 = V_18 -> V_36 ;
unsigned long V_41 ;
F_19 ( V_40 -> V_45 , V_41 ) ;
F_67 ( V_57 ) ;
V_57 -> V_95 = NULL ;
F_68 ( V_18 ) ;
F_20 ( V_40 , V_57 ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
F_62 ( V_40 ) ;
F_14 ( & V_35 -> V_37 ) ;
}
void F_69 ( struct V_2 * V_3 )
{
struct V_22 * V_35 ;
F_70 (sdev, shost)
F_62 ( V_35 -> V_39 ) ;
}
static void F_71 ( struct V_17 * V_18 )
{
if ( ! F_72 ( V_18 -> V_36 ) ) {
struct V_96 * V_97 = F_73 ( V_18 ) ;
if ( V_97 -> V_98 )
V_97 -> V_98 ( V_18 ) ;
}
}
static void F_74 ( struct V_17 * V_18 )
{
struct V_99 * V_100 ;
if ( V_18 -> V_100 . V_101 . V_102 )
F_75 ( & V_18 -> V_100 . V_101 , true ) ;
if ( V_18 -> V_36 -> V_103 ) {
V_100 = V_18 -> V_36 -> V_103 -> V_95 ;
if ( V_100 )
F_75 ( & V_100 -> V_101 , true ) ;
}
if ( F_76 ( V_18 ) )
F_75 ( & V_18 -> V_104 -> V_101 , true ) ;
}
static void F_77 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_2 * V_3 = V_35 -> V_20 ;
unsigned long V_41 ;
F_74 ( V_18 ) ;
F_71 ( V_18 ) ;
if ( V_3 -> V_105 ) {
F_78 ( F_55 ( & V_18 -> V_106 ) ) ;
F_19 ( & V_35 -> V_107 , V_41 ) ;
F_57 ( & V_18 -> V_106 ) ;
F_22 ( & V_35 -> V_107 , V_41 ) ;
}
}
static void F_79 ( struct V_17 * V_18 )
{
if ( V_18 -> V_100 . V_101 . V_102 )
F_75 ( & V_18 -> V_100 . V_101 , false ) ;
memset ( & V_18 -> V_100 , 0 , sizeof( V_18 -> V_100 ) ) ;
if ( F_76 ( V_18 ) )
F_75 ( & V_18 -> V_104 -> V_101 , false ) ;
}
static void F_80 ( struct V_17 * V_18 )
{
struct V_99 * V_108 = V_18 -> V_36 -> V_103 -> V_95 ;
F_75 ( & V_108 -> V_101 , false ) ;
F_3 ( V_109 , V_108 ) ;
V_18 -> V_36 -> V_103 -> V_95 = NULL ;
}
static bool F_81 ( struct V_36 * V_57 , int error ,
unsigned int V_110 , unsigned int V_111 )
{
struct V_17 * V_18 = V_57 -> V_95 ;
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_39 * V_40 = V_35 -> V_39 ;
if ( F_82 ( V_57 , error , V_110 ) )
return true ;
if ( F_32 ( V_111 ) &&
F_82 ( V_57 -> V_103 , error , V_111 ) )
return true ;
if ( F_83 ( V_40 ) )
F_84 ( V_57 -> V_112 ) ;
if ( V_57 -> V_113 ) {
F_77 ( V_18 ) ;
F_85 ( V_57 , error ) ;
if ( V_23 ( V_35 ) -> V_92 ||
! F_55 ( & V_35 -> V_20 -> V_87 ) )
F_21 ( & V_35 -> V_46 ) ;
else
F_63 ( V_40 , true ) ;
} else {
unsigned long V_41 ;
if ( V_111 )
F_80 ( V_18 ) ;
F_79 ( V_18 ) ;
F_68 ( V_18 ) ;
F_19 ( V_40 -> V_45 , V_41 ) ;
F_86 ( V_57 , error ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
F_62 ( V_40 ) ;
}
F_14 ( & V_35 -> V_37 ) ;
return false ;
}
static int F_87 ( struct V_17 * V_18 , int V_43 )
{
int error = 0 ;
switch( F_88 ( V_43 ) ) {
case V_114 :
error = - V_115 ;
break;
case V_116 :
F_89 ( V_18 , V_117 ) ;
error = - V_118 ;
break;
case V_119 :
F_89 ( V_18 , V_117 ) ;
error = - V_120 ;
break;
case V_121 :
F_89 ( V_18 , V_117 ) ;
error = - V_122 ;
break;
case V_123 :
F_89 ( V_18 , V_117 ) ;
error = - V_124 ;
break;
default:
error = - V_125 ;
break;
}
return error ;
}
void F_90 ( struct V_17 * V_18 , unsigned int V_126 )
{
int V_43 = V_18 -> V_43 ;
struct V_39 * V_40 = V_18 -> V_21 -> V_39 ;
struct V_36 * V_57 = V_18 -> V_36 ;
int error = 0 ;
struct V_51 V_52 ;
bool V_127 = false ;
int V_128 = 0 , V_129 = 0 ;
enum { V_130 , V_131 , V_132 ,
V_133 } V_134 ;
unsigned long V_135 = ( V_18 -> V_136 + 1 ) * V_57 -> V_53 ;
if ( V_43 ) {
V_127 = F_91 ( V_18 , & V_52 ) ;
if ( V_127 )
V_128 = F_92 ( & V_52 ) ;
}
if ( F_72 ( V_57 ) ) {
if ( V_43 ) {
if ( V_127 ) {
F_27 ( V_57 ) -> V_71 =
F_93 ( 8 + V_18 -> V_7 [ 7 ] ,
V_13 ) ;
}
if ( ! V_128 )
error = F_87 ( V_18 , V_43 ) ;
}
V_57 -> V_72 = V_18 -> V_43 ;
F_27 ( V_57 ) -> V_70 = F_94 ( V_18 ) ;
if ( F_95 ( V_18 ) ) {
F_27 ( V_57 -> V_103 ) -> V_70 = F_96 ( V_18 ) -> V_56 ;
if ( F_81 ( V_57 , 0 , F_97 ( V_57 ) ,
F_97 ( V_57 -> V_103 ) ) )
F_98 () ;
return;
}
} else if ( F_97 ( V_57 ) == 0 && V_43 && ! V_128 ) {
error = F_87 ( V_18 , V_43 ) ;
}
F_78 ( F_99 ( V_57 ) ) ;
F_100 ( 1 , F_17 ( V_42 , V_18 ,
L_4 ,
F_101 ( V_57 ) , V_126 ) ) ;
if ( V_127 && ( V_52 . V_137 == V_138 ) ) {
if ( ( V_52 . V_139 == 0x0 ) && ( V_52 . V_140 == 0x1d ) )
;
else if ( ! ( V_57 -> V_55 & V_68 ) )
F_102 ( V_18 ) ;
V_43 = 0 ;
error = 0 ;
}
if ( ! ( F_97 ( V_57 ) == 0 && error ) &&
! F_81 ( V_57 , error , V_126 , 0 ) )
return;
if ( error && F_103 ( V_18 ) ) {
if ( F_81 ( V_57 , error , F_97 ( V_57 ) , 0 ) )
F_98 () ;
return;
}
if ( V_43 == 0 )
goto V_141;
error = F_87 ( V_18 , V_43 ) ;
if ( F_88 ( V_43 ) == V_142 ) {
V_134 = V_132 ;
} else if ( V_127 && ! V_128 ) {
switch ( V_52 . V_137 ) {
case V_143 :
if ( V_18 -> V_21 -> V_144 ) {
V_18 -> V_21 -> V_145 = 1 ;
V_134 = V_130 ;
} else {
V_134 = V_132 ;
}
break;
case V_146 :
if ( ( V_18 -> V_21 -> V_147 &&
V_52 . V_139 == 0x20 && V_52 . V_140 == 0x00 ) &&
( V_18 -> V_74 [ 0 ] == V_148 ||
V_18 -> V_74 [ 0 ] == V_149 ) ) {
V_18 -> V_21 -> V_147 = 0 ;
V_134 = V_131 ;
} else if ( V_52 . V_139 == 0x10 ) {
V_134 = V_130 ;
error = - V_150 ;
} else if ( V_52 . V_139 == 0x20 || V_52 . V_139 == 0x24 ) {
V_134 = V_130 ;
error = - V_118 ;
} else
V_134 = V_130 ;
break;
case V_151 :
V_134 = V_130 ;
if ( V_52 . V_139 == 0x10 )
error = - V_150 ;
break;
case V_152 :
if ( V_52 . V_139 == 0x04 ) {
switch ( V_52 . V_140 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_134 = V_133 ;
break;
default:
V_134 = V_130 ;
break;
}
} else
V_134 = V_130 ;
break;
case V_153 :
V_134 = V_130 ;
break;
default:
V_134 = V_130 ;
break;
}
} else
V_134 = V_130 ;
if ( V_134 != V_130 &&
F_104 ( V_18 -> V_154 + V_135 , V_155 ) )
V_134 = V_130 ;
switch ( V_134 ) {
case V_130 :
if ( ! ( V_57 -> V_55 & V_68 ) ) {
static F_105 ( V_156 ,
V_157 ,
V_158 ) ;
if ( F_32 ( V_159 ) )
V_129 = F_106 ( V_160 ,
V_161 ) ;
if ( ! V_129 && F_107 ( & V_156 ) ) {
F_108 ( V_18 , NULL , V_162 ) ;
if ( F_109 ( V_43 ) & V_163 )
F_102 ( V_18 ) ;
F_110 ( V_18 ) ;
}
}
if ( ! F_81 ( V_57 , error , F_111 ( V_57 ) , 0 ) )
return;
case V_131 :
V_141:
if ( V_40 -> V_44 ) {
V_18 -> V_36 -> V_55 &= ~ V_164 ;
F_77 ( V_18 ) ;
F_12 ( V_18 ) ;
} else {
F_79 ( V_18 ) ;
F_66 ( V_40 , V_18 ) ;
}
break;
case V_132 :
F_15 ( V_18 , V_29 , 0 ) ;
break;
case V_133 :
F_15 ( V_18 , V_28 , 0 ) ;
break;
}
}
static int F_112 ( struct V_36 * V_57 , struct V_99 * V_100 )
{
int V_165 ;
if ( F_32 ( F_113 ( & V_100 -> V_101 ,
F_114 ( V_57 ) , V_100 -> V_101 . V_166 ) ) )
return V_167 ;
V_165 = F_115 ( V_57 -> V_40 , V_57 , V_100 -> V_101 . V_166 ) ;
F_78 ( V_165 > V_100 -> V_101 . V_102 ) ;
V_100 -> V_101 . V_102 = V_165 ;
V_100 -> V_168 = F_116 ( V_57 ) ;
return V_169 ;
}
int F_117 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_36 * V_59 = V_18 -> V_36 ;
bool V_170 = ( V_59 -> V_113 != NULL ) ;
int error = V_171 ;
if ( F_118 ( ! F_114 ( V_59 ) ) )
goto V_172;
error = F_112 ( V_59 , & V_18 -> V_100 ) ;
if ( error )
goto V_172;
if ( F_99 ( V_59 ) ) {
if ( ! V_59 -> V_40 -> V_44 ) {
struct V_99 * V_108 =
F_119 ( V_109 , V_173 ) ;
if ( ! V_108 ) {
error = V_167 ;
goto V_172;
}
V_59 -> V_103 -> V_95 = V_108 ;
}
error = F_112 ( V_59 -> V_103 , V_59 -> V_103 -> V_95 ) ;
if ( error )
goto V_172;
}
if ( F_120 ( V_59 ) ) {
struct V_99 * V_104 = V_18 -> V_104 ;
int V_174 , V_165 ;
if ( V_104 == NULL ) {
F_118 ( 1 ) ;
error = V_171 ;
goto V_172;
}
V_174 = F_121 ( V_59 -> V_40 , V_59 -> V_175 ) ;
if ( F_113 ( & V_104 -> V_101 , V_174 ,
V_104 -> V_101 . V_166 ) ) {
error = V_167 ;
goto V_172;
}
V_165 = F_122 ( V_59 -> V_40 , V_59 -> V_175 ,
V_104 -> V_101 . V_166 ) ;
F_78 ( F_32 ( V_165 > V_174 ) ) ;
F_78 ( F_32 ( V_165 > F_123 ( V_59 -> V_40 ) ) ) ;
V_18 -> V_104 = V_104 ;
V_18 -> V_104 -> V_101 . V_102 = V_165 ;
}
return V_169 ;
V_172:
if ( V_170 ) {
F_74 ( V_18 ) ;
} else {
F_79 ( V_18 ) ;
V_18 -> V_36 -> V_95 = NULL ;
F_68 ( V_18 ) ;
F_14 ( & V_35 -> V_37 ) ;
}
return error ;
}
void F_124 ( struct V_22 * V_176 , struct V_17 * V_18 )
{
void * V_177 = V_18 -> V_7 ;
void * V_178 = V_18 -> V_104 ;
unsigned long V_41 ;
memset ( ( char * ) V_18 + sizeof( V_18 -> V_57 ) , 0 ,
sizeof( * V_18 ) - sizeof( V_18 -> V_57 ) + V_176 -> V_20 -> V_179 -> V_180 ) ;
V_18 -> V_21 = V_176 ;
V_18 -> V_7 = V_177 ;
V_18 -> V_104 = V_178 ;
F_125 ( & V_18 -> V_181 , V_182 ) ;
V_18 -> V_154 = V_155 ;
F_19 ( & V_176 -> V_107 , V_41 ) ;
F_126 ( & V_18 -> V_106 , & V_176 -> V_183 ) ;
F_22 ( & V_176 -> V_107 , V_41 ) ;
}
static int F_127 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_95 ;
if ( V_57 -> V_175 ) {
int V_11 = F_117 ( V_18 ) ;
if ( F_32 ( V_11 ) )
return V_11 ;
} else {
F_78 ( F_97 ( V_57 ) ) ;
memset ( & V_18 -> V_100 , 0 , sizeof( V_18 -> V_100 ) ) ;
}
V_18 -> V_66 = F_27 ( V_57 ) -> V_66 ;
V_18 -> V_74 = F_27 ( V_57 ) -> V_18 ;
V_18 -> V_184 = F_97 ( V_57 ) ;
V_18 -> V_136 = V_57 -> V_54 ;
return V_169 ;
}
static int F_128 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_95 ;
if ( F_32 ( V_35 -> V_185 && V_35 -> V_185 -> V_186 ) ) {
int V_11 = V_35 -> V_185 -> V_186 ( V_35 , V_57 ) ;
if ( V_11 != V_169 )
return V_11 ;
}
V_18 -> V_74 = F_27 ( V_57 ) -> V_18 = F_27 ( V_57 ) -> V_187 ;
memset ( V_18 -> V_74 , 0 , V_188 ) ;
return F_73 ( V_18 ) -> F_129 ( V_18 ) ;
}
static int F_130 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_95 ;
if ( ! F_97 ( V_57 ) )
V_18 -> V_189 = V_190 ;
else if ( F_131 ( V_57 ) == V_191 )
V_18 -> V_189 = V_61 ;
else
V_18 -> V_189 = V_192 ;
if ( F_132 ( V_57 ) )
return F_127 ( V_35 , V_57 ) ;
else
return F_128 ( V_35 , V_57 ) ;
}
static int
F_133 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
int V_11 = V_169 ;
if ( F_32 ( V_35 -> V_193 != V_194 ) ) {
switch ( V_35 -> V_193 ) {
case V_195 :
case V_196 :
F_134 ( V_197 , V_35 ,
L_5 ) ;
V_11 = V_171 ;
break;
case V_198 :
F_134 ( V_197 , V_35 ,
L_6 ) ;
V_11 = V_171 ;
break;
case V_199 :
case V_200 :
V_11 = V_167 ;
break;
case V_201 :
if ( ! ( V_57 -> V_55 & V_69 ) )
V_11 = V_167 ;
break;
default:
if ( ! ( V_57 -> V_55 & V_69 ) )
V_11 = V_171 ;
break;
}
}
return V_11 ;
}
static int
F_135 ( struct V_39 * V_40 , struct V_36 * V_57 , int V_11 )
{
struct V_22 * V_35 = V_40 -> V_91 ;
switch ( V_11 ) {
case V_171 :
case V_202 :
V_57 -> V_72 = V_203 << 16 ;
if ( V_57 -> V_95 ) {
struct V_17 * V_18 = V_57 -> V_95 ;
F_79 ( V_18 ) ;
F_68 ( V_18 ) ;
F_14 ( & V_35 -> V_37 ) ;
V_57 -> V_95 = NULL ;
}
break;
case V_167 :
if ( F_49 ( & V_35 -> V_81 ) == 0 )
F_136 ( V_40 , V_204 ) ;
break;
default:
V_57 -> V_55 |= V_164 ;
}
return V_11 ;
}
static int F_137 ( struct V_39 * V_40 , struct V_36 * V_57 )
{
struct V_22 * V_35 = V_40 -> V_91 ;
struct V_17 * V_18 = F_138 ( V_57 ) ;
int V_11 ;
V_11 = F_133 ( V_35 , V_57 ) ;
if ( V_11 != V_169 )
goto V_65;
if ( ! V_57 -> V_95 ) {
if ( F_32 ( ! F_139 ( & V_35 -> V_37 ) ) ) {
V_11 = V_167 ;
goto V_65;
}
F_124 ( V_35 , V_18 ) ;
V_57 -> V_95 = V_18 ;
}
V_18 -> V_205 = V_57 -> V_205 ;
V_18 -> V_36 = V_57 ;
V_18 -> V_206 = V_207 ;
V_11 = F_130 ( V_35 , V_57 ) ;
V_65:
return F_135 ( V_40 , V_57 , V_11 ) ;
}
static void F_140 ( struct V_39 * V_40 , struct V_36 * V_57 )
{
F_71 ( V_57 -> V_95 ) ;
}
static inline int F_141 ( struct V_39 * V_40 ,
struct V_22 * V_35 )
{
unsigned int V_208 ;
V_208 = F_142 ( & V_35 -> V_81 ) - 1 ;
if ( F_49 ( & V_35 -> V_30 ) ) {
if ( V_208 )
goto V_209;
if ( F_143 ( & V_35 -> V_30 ) > 0 ) {
if ( ! V_40 -> V_44 )
F_136 ( V_40 , V_204 ) ;
goto V_209;
}
F_16 ( 3 , F_134 ( V_42 , V_35 ,
L_7 ) ) ;
}
if ( V_208 >= V_35 -> V_85 )
goto V_209;
return 1 ;
V_209:
F_38 ( & V_35 -> V_81 ) ;
return 0 ;
}
static inline int F_144 ( struct V_2 * V_3 ,
struct V_22 * V_35 )
{
struct V_23 * V_24 = V_23 ( V_35 ) ;
unsigned int V_208 ;
if ( V_24 -> V_92 ) {
F_145 ( V_3 -> V_80 ) ;
if ( V_24 -> V_84 &&
V_24 -> V_84 != V_35 ) {
F_146 ( V_3 -> V_80 ) ;
return 0 ;
}
V_24 -> V_84 = V_35 ;
F_146 ( V_3 -> V_80 ) ;
}
if ( V_24 -> V_76 <= 0 )
return 1 ;
V_208 = F_142 ( & V_24 -> V_77 ) - 1 ;
if ( F_49 ( & V_24 -> V_33 ) > 0 ) {
if ( V_208 )
goto V_210;
if ( F_143 ( & V_24 -> V_33 ) > 0 )
goto V_209;
F_16 ( 3 , F_147 ( V_42 , V_24 ,
L_8 ) ) ;
}
if ( V_208 >= V_24 -> V_76 )
goto V_210;
return 1 ;
V_210:
F_145 ( V_3 -> V_80 ) ;
F_58 ( & V_35 -> V_90 , & V_3 -> V_87 ) ;
F_146 ( V_3 -> V_80 ) ;
V_209:
if ( V_24 -> V_76 > 0 )
F_38 ( & V_24 -> V_77 ) ;
return 0 ;
}
static inline int F_148 ( struct V_39 * V_40 ,
struct V_2 * V_3 ,
struct V_22 * V_35 )
{
unsigned int V_208 ;
if ( F_39 ( V_3 ) )
return 0 ;
V_208 = F_142 ( & V_3 -> V_75 ) - 1 ;
if ( F_49 ( & V_3 -> V_26 ) > 0 ) {
if ( V_208 )
goto V_210;
if ( F_143 ( & V_3 -> V_26 ) > 0 )
goto V_209;
F_16 ( 3 ,
F_149 ( V_42 , V_3 ,
L_9 ) ) ;
}
if ( V_3 -> V_76 > 0 && V_208 >= V_3 -> V_76 )
goto V_210;
if ( V_3 -> V_86 )
goto V_210;
if ( ! F_55 ( & V_35 -> V_90 ) ) {
F_145 ( V_3 -> V_80 ) ;
if ( ! F_55 ( & V_35 -> V_90 ) )
F_57 ( & V_35 -> V_90 ) ;
F_146 ( V_3 -> V_80 ) ;
}
return 1 ;
V_210:
F_145 ( V_3 -> V_80 ) ;
if ( F_55 ( & V_35 -> V_90 ) )
F_126 ( & V_35 -> V_90 , & V_3 -> V_87 ) ;
F_146 ( V_3 -> V_80 ) ;
V_209:
F_38 ( & V_3 -> V_75 ) ;
return 0 ;
}
static int F_150 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = V_40 -> V_91 ;
struct V_2 * V_3 ;
if ( F_151 ( V_40 ) )
return 0 ;
V_3 = V_35 -> V_20 ;
if ( F_39 ( V_3 ) || F_48 ( V_35 ) )
return 1 ;
return 0 ;
}
static void F_152 ( struct V_36 * V_57 , struct V_39 * V_40 )
{
struct V_17 * V_18 = V_57 -> V_95 ;
struct V_22 * V_35 ;
struct V_23 * V_24 ;
struct V_2 * V_3 ;
F_153 ( V_57 ) ;
F_17 ( V_42 , V_18 , L_10 ) ;
V_35 = V_18 -> V_21 ;
V_24 = V_23 ( V_35 ) ;
V_3 = V_35 -> V_20 ;
F_35 ( V_18 ) ;
V_18 -> V_43 = V_203 << 16 ;
F_154 ( & V_18 -> V_21 -> V_211 ) ;
F_154 ( & V_35 -> V_81 ) ;
F_154 ( & V_3 -> V_75 ) ;
if ( V_24 -> V_76 > 0 )
F_154 ( & V_24 -> V_77 ) ;
F_155 ( V_57 ) ;
}
static void F_156 ( struct V_36 * V_59 )
{
struct V_17 * V_18 = V_59 -> V_95 ;
unsigned long V_135 = ( V_18 -> V_136 + 1 ) * V_59 -> V_53 ;
int V_212 ;
F_157 ( & V_18 -> V_213 ) ;
F_154 ( & V_18 -> V_21 -> V_214 ) ;
if ( V_18 -> V_43 )
F_154 ( & V_18 -> V_21 -> V_215 ) ;
V_212 = F_158 ( V_18 ) ;
if ( V_212 != V_216 &&
F_104 ( V_18 -> V_154 + V_135 , V_155 ) ) {
F_134 ( V_197 , V_18 -> V_21 ,
L_11 ,
V_135 / V_217 ) ;
V_212 = V_216 ;
}
F_159 ( V_18 , V_212 ) ;
switch ( V_212 ) {
case V_216 :
F_160 ( V_18 ) ;
break;
case V_218 :
F_23 ( V_18 , V_29 ) ;
break;
case V_219 :
F_23 ( V_18 , V_28 ) ;
break;
default:
if ( ! F_161 ( V_18 , 0 ) )
F_160 ( V_18 ) ;
}
}
static int F_162 ( struct V_17 * V_18 )
{
struct V_2 * V_20 = V_18 -> V_21 -> V_20 ;
int V_220 = 0 ;
F_154 ( & V_18 -> V_21 -> V_211 ) ;
if ( F_32 ( V_18 -> V_21 -> V_193 == V_198 ) ) {
V_18 -> V_43 = V_203 << 16 ;
goto V_221;
}
if ( F_32 ( F_163 ( V_18 -> V_21 ) ) ) {
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_12 ) ) ;
return V_28 ;
}
if ( V_18 -> V_21 -> V_222 )
V_18 -> V_74 [ 1 ] = ( V_18 -> V_74 [ 1 ] & 0x1f ) |
( V_18 -> V_21 -> V_223 << 5 & 0xe0 ) ;
F_164 ( V_18 ) ;
if ( V_18 -> V_66 > V_18 -> V_21 -> V_20 -> V_224 ) {
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_13
L_14 ,
V_18 -> V_66 , V_18 -> V_21 -> V_20 -> V_224 ) ) ;
V_18 -> V_43 = ( V_225 << 16 ) ;
goto V_221;
}
if ( F_32 ( V_20 -> V_226 == V_227 ) ) {
V_18 -> V_43 = ( V_203 << 16 ) ;
goto V_221;
}
F_165 ( V_18 ) ;
V_220 = V_20 -> V_179 -> V_228 ( V_20 , V_18 ) ;
if ( V_220 ) {
F_166 ( V_18 , V_220 ) ;
if ( V_220 != V_28 &&
V_220 != V_32 )
V_220 = V_25 ;
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_15 ) ) ;
}
return V_220 ;
V_221:
V_18 -> V_229 ( V_18 ) ;
return 0 ;
}
static void V_229 ( struct V_17 * V_18 )
{
F_167 ( V_18 ) ;
F_155 ( V_18 -> V_36 ) ;
}
static void F_168 ( struct V_39 * V_40 )
__releases( V_40 -> V_45 )
__acquires( V_40 -> V_45 )
{
struct V_22 * V_35 = V_40 -> V_91 ;
struct V_2 * V_3 ;
struct V_17 * V_18 ;
struct V_36 * V_57 ;
V_3 = V_35 -> V_20 ;
for (; ; ) {
int V_220 ;
V_57 = F_169 ( V_40 ) ;
if ( ! V_57 )
break;
if ( F_32 ( ! F_170 ( V_35 ) ) ) {
F_134 ( V_197 , V_35 ,
L_5 ) ;
F_152 ( V_57 , V_40 ) ;
continue;
}
if ( ! F_141 ( V_40 , V_35 ) )
break;
if ( ! ( F_171 ( V_40 ) && ! F_172 ( V_40 , V_57 ) ) )
F_153 ( V_57 ) ;
F_146 ( V_40 -> V_45 ) ;
V_18 = V_57 -> V_95 ;
if ( F_32 ( V_18 == NULL ) ) {
F_173 ( V_230 L_16
L_17
L_18 ,
V_231 ) ;
F_174 ( V_57 , L_19 ) ;
F_98 () ;
}
if ( F_171 ( V_40 ) && ! ( V_57 -> V_55 & V_232 ) ) {
F_145 ( V_3 -> V_80 ) ;
if ( F_55 ( & V_35 -> V_90 ) )
F_126 ( & V_35 -> V_90 ,
& V_3 -> V_87 ) ;
F_146 ( V_3 -> V_80 ) ;
goto V_233;
}
if ( ! F_144 ( V_3 , V_35 ) )
goto V_233;
if ( ! F_148 ( V_40 , V_3 , V_35 ) )
goto V_234;
if ( V_35 -> V_235 )
V_18 -> V_41 |= V_236 ;
else
V_18 -> V_41 &= ~ V_236 ;
F_35 ( V_18 ) ;
V_18 -> V_229 = V_229 ;
V_220 = F_162 ( V_18 ) ;
if ( V_220 ) {
F_23 ( V_18 , V_220 ) ;
F_145 ( V_40 -> V_45 ) ;
goto V_237;
}
F_145 ( V_40 -> V_45 ) ;
}
return;
V_234:
if ( V_23 ( V_35 ) -> V_76 > 0 )
F_38 ( & V_23 ( V_35 ) -> V_77 ) ;
V_233:
F_145 ( V_40 -> V_45 ) ;
F_20 ( V_40 , V_57 ) ;
F_38 ( & V_35 -> V_81 ) ;
V_237:
if ( ! F_49 ( & V_35 -> V_81 ) && ! F_163 ( V_35 ) )
F_136 ( V_40 , V_204 ) ;
}
static inline int F_175 ( int V_11 )
{
switch ( V_11 ) {
case V_169 :
return V_238 ;
case V_167 :
return V_239 ;
default:
return V_240 ;
}
}
static int F_176 ( struct V_36 * V_57 )
{
struct V_17 * V_18 = F_138 ( V_57 ) ;
struct V_22 * V_35 = V_57 -> V_40 -> V_91 ;
struct V_2 * V_3 = V_35 -> V_20 ;
unsigned char * V_241 = V_18 -> V_7 ;
struct V_242 * V_243 ;
memset ( ( char * ) V_18 + sizeof( V_18 -> V_57 ) , 0 ,
sizeof( * V_18 ) - sizeof( V_18 -> V_57 ) ) ;
V_57 -> V_95 = V_18 ;
V_18 -> V_36 = V_57 ;
V_18 -> V_21 = V_35 ;
V_18 -> V_7 = V_241 ;
V_18 -> V_205 = V_57 -> V_205 ;
V_18 -> V_206 = V_207 ;
F_157 ( & V_18 -> V_106 ) ;
F_125 ( & V_18 -> V_181 , V_182 ) ;
V_18 -> V_154 = V_155 ;
if ( V_3 -> V_105 ) {
F_145 ( & V_35 -> V_107 ) ;
F_126 ( & V_18 -> V_106 , & V_35 -> V_183 ) ;
F_146 ( & V_35 -> V_107 ) ;
}
V_243 = ( void * ) V_18 + sizeof( struct V_17 ) + V_3 -> V_179 -> V_180 ;
V_18 -> V_100 . V_101 . V_166 = V_243 ;
if ( F_177 ( V_3 ) ) {
V_18 -> V_104 = ( void * ) V_243 +
F_178 (unsigned int,
shost->sg_tablesize, SG_CHUNK_SIZE) *
sizeof( struct V_242 ) ;
memset ( V_18 -> V_104 , 0 , sizeof( struct V_99 ) ) ;
V_18 -> V_104 -> V_101 . V_166 =
(struct V_242 * ) ( V_18 -> V_104 + 1 ) ;
}
if ( F_99 ( V_57 ) ) {
struct V_36 * V_103 = V_57 -> V_103 ;
struct V_99 * V_108 = F_138 ( V_103 ) ;
memset ( V_108 , 0 , sizeof( struct V_99 ) ) ;
V_108 -> V_101 . V_166 =
(struct V_242 * ) ( V_108 + 1 ) ;
V_103 -> V_95 = V_108 ;
}
F_179 ( V_57 ) ;
return F_130 ( V_35 , V_57 ) ;
}
static void F_180 ( struct V_17 * V_18 )
{
F_167 ( V_18 ) ;
F_181 ( V_18 -> V_36 , V_18 -> V_36 -> V_72 ) ;
}
static int F_182 ( struct V_244 * V_245 ,
const struct V_246 * V_247 )
{
struct V_36 * V_57 = V_247 -> V_59 ;
struct V_39 * V_40 = V_57 -> V_40 ;
struct V_22 * V_35 = V_40 -> V_91 ;
struct V_2 * V_3 = V_35 -> V_20 ;
struct V_17 * V_18 = F_138 ( V_57 ) ;
int V_11 ;
int V_19 ;
V_11 = F_175 ( F_133 ( V_35 , V_57 ) ) ;
if ( V_11 != V_238 )
goto V_65;
V_11 = V_239 ;
if ( ! F_139 ( & V_35 -> V_37 ) )
goto V_65;
if ( ! F_141 ( V_40 , V_35 ) )
goto V_248;
if ( ! F_144 ( V_3 , V_35 ) )
goto V_249;
if ( ! F_148 ( V_40 , V_3 , V_35 ) )
goto V_250;
if ( ! ( V_57 -> V_55 & V_164 ) ) {
V_11 = F_175 ( F_176 ( V_57 ) ) ;
if ( V_11 != V_238 )
goto V_251;
V_57 -> V_55 |= V_164 ;
} else {
F_179 ( V_57 ) ;
}
if ( V_35 -> V_235 )
V_18 -> V_41 |= V_236 ;
else
V_18 -> V_41 &= ~ V_236 ;
F_35 ( V_18 ) ;
V_18 -> V_229 = F_180 ;
V_19 = F_162 ( V_18 ) ;
if ( V_19 ) {
F_10 ( V_18 , V_19 ) ;
V_11 = V_239 ;
goto V_251;
}
return V_238 ;
V_251:
F_38 ( & V_3 -> V_75 ) ;
V_250:
if ( V_23 ( V_35 ) -> V_76 > 0 )
F_38 ( & V_23 ( V_35 ) -> V_77 ) ;
V_249:
F_38 ( & V_35 -> V_81 ) ;
V_248:
F_14 ( & V_35 -> V_37 ) ;
V_65:
switch ( V_11 ) {
case V_239 :
if ( F_49 ( & V_35 -> V_81 ) == 0 &&
! F_163 ( V_35 ) )
F_183 ( V_245 , V_204 ) ;
break;
case V_240 :
if ( V_57 -> V_55 & V_164 )
F_77 ( V_18 ) ;
break;
default:
break;
}
return V_11 ;
}
static enum V_252 F_184 ( struct V_36 * V_57 ,
bool V_253 )
{
if ( V_253 )
return V_254 ;
return F_185 ( V_57 ) ;
}
static int F_186 ( void * V_255 , struct V_36 * V_59 ,
unsigned int V_256 , unsigned int V_257 ,
unsigned int V_9 )
{
struct V_2 * V_3 = V_255 ;
struct V_17 * V_18 = F_138 ( V_59 ) ;
V_18 -> V_7 =
F_4 ( V_3 , V_258 , V_9 ) ;
if ( ! V_18 -> V_7 )
return - V_16 ;
V_18 -> V_57 . V_50 = V_18 -> V_7 ;
return 0 ;
}
static void F_187 ( void * V_255 , struct V_36 * V_59 ,
unsigned int V_256 , unsigned int V_257 )
{
struct V_2 * V_3 = V_255 ;
struct V_17 * V_18 = F_138 ( V_59 ) ;
F_2 ( V_3 , V_18 -> V_7 ) ;
}
static int F_188 ( struct V_259 * V_260 )
{
struct V_2 * V_3 = F_65 ( V_260 , struct V_2 , V_261 ) ;
if ( V_3 -> V_179 -> V_262 )
return V_3 -> V_179 -> V_262 ( V_3 ) ;
return F_189 ( V_260 ) ;
}
static T_2 F_190 ( struct V_2 * V_3 )
{
struct V_21 * V_263 ;
T_2 V_264 = 0xffffffff ;
if ( V_3 -> V_4 )
return V_265 ;
if ( ! V_266 )
return V_267 ;
V_263 = F_191 ( V_3 ) ;
if ( V_263 && V_263 -> V_268 )
V_264 = ( T_2 ) F_192 ( V_263 ) << V_269 ;
return V_264 ;
}
void F_193 ( struct V_2 * V_3 , struct V_39 * V_40 )
{
struct V_21 * V_176 = V_3 -> V_270 ;
F_194 ( V_40 , F_178 (unsigned short, shost->sg_tablesize,
SG_MAX_SEGMENTS) ) ;
if ( F_195 ( V_3 ) ) {
V_3 -> V_271 =
F_196 ( V_3 -> V_271 ,
( unsigned short ) V_272 ) ;
F_78 ( V_3 -> V_271 < V_3 -> V_273 ) ;
F_197 ( V_40 , V_3 -> V_271 ) ;
}
F_198 ( V_40 , V_3 -> V_274 ) ;
F_199 ( V_40 , F_190 ( V_3 ) ) ;
F_200 ( V_40 , V_3 -> V_275 ) ;
F_201 ( V_176 , V_3 -> V_275 ) ;
F_202 ( V_40 , F_203 ( V_176 ) ) ;
if ( ! V_3 -> V_276 )
V_40 -> V_277 . V_278 = 0 ;
F_204 ( V_40 , 0x03 ) ;
}
static int F_205 ( struct V_39 * V_40 , struct V_36 * V_59 , T_1 V_279 )
{
struct V_2 * V_3 = V_40 -> V_280 ;
struct V_17 * V_18 = F_138 ( V_59 ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_7 = F_4 ( V_3 , V_279 , V_281 ) ;
if ( ! V_18 -> V_7 )
goto V_282;
V_18 -> V_57 . V_50 = V_18 -> V_7 ;
if ( F_177 ( V_3 ) >= V_283 ) {
V_18 -> V_104 = F_119 ( V_109 , V_279 ) ;
if ( ! V_18 -> V_104 )
goto V_284;
}
return 0 ;
V_284:
F_2 ( V_3 , V_18 -> V_7 ) ;
V_282:
return - V_16 ;
}
static void F_206 ( struct V_39 * V_40 , struct V_36 * V_59 )
{
struct V_2 * V_3 = V_40 -> V_280 ;
struct V_17 * V_18 = F_138 ( V_59 ) ;
if ( V_18 -> V_104 )
F_3 ( V_109 , V_18 -> V_104 ) ;
F_2 ( V_3 , V_18 -> V_7 ) ;
}
struct V_39 * F_207 ( struct V_22 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_20 ;
struct V_39 * V_40 ;
V_40 = F_208 ( V_258 , V_281 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_180 = sizeof( struct V_17 ) + V_3 -> V_179 -> V_180 ;
V_40 -> V_280 = V_3 ;
V_40 -> V_285 = F_168 ;
V_40 -> V_286 = F_205 ;
V_40 -> V_287 = F_206 ;
if ( F_209 ( V_40 ) < 0 ) {
F_210 ( V_40 ) ;
return NULL ;
}
F_193 ( V_3 , V_40 ) ;
F_211 ( V_40 , F_137 ) ;
F_212 ( V_40 , F_140 ) ;
F_213 ( V_40 , F_156 ) ;
F_214 ( V_40 , F_185 ) ;
F_215 ( V_40 , F_150 ) ;
return V_40 ;
}
struct V_39 * F_216 ( struct V_22 * V_35 )
{
V_35 -> V_39 = F_217 ( & V_35 -> V_20 -> V_261 ) ;
if ( F_26 ( V_35 -> V_39 ) )
return NULL ;
V_35 -> V_39 -> V_91 = V_35 ;
F_193 ( V_35 -> V_20 , V_35 -> V_39 ) ;
return V_35 -> V_39 ;
}
int F_218 ( struct V_2 * V_3 )
{
unsigned int V_180 , V_288 , V_289 ;
V_289 = V_3 -> V_273 ;
if ( V_289 > V_290 )
V_289 = V_290 ;
V_288 = V_289 * sizeof( struct V_242 ) ;
V_180 = sizeof( struct V_17 ) + V_3 -> V_179 -> V_180 + V_288 ;
if ( F_177 ( V_3 ) )
V_180 += sizeof( struct V_99 ) + V_288 ;
memset ( & V_3 -> V_261 , 0 , sizeof( V_3 -> V_261 ) ) ;
V_3 -> V_261 . V_291 = & V_292 ;
V_3 -> V_261 . V_293 = V_3 -> V_293 ? : 1 ;
V_3 -> V_261 . V_85 = V_3 -> V_76 ;
V_3 -> V_261 . V_180 = V_180 ;
V_3 -> V_261 . V_9 = V_281 ;
V_3 -> V_261 . V_41 = V_294 | V_295 ;
V_3 -> V_261 . V_41 |=
F_219 ( V_3 -> V_179 -> V_296 ) ;
V_3 -> V_261 . V_297 = V_3 ;
return F_220 ( & V_3 -> V_261 ) ;
}
void F_221 ( struct V_2 * V_3 )
{
F_222 ( & V_3 -> V_261 ) ;
}
struct V_22 * F_223 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = NULL ;
if ( V_40 -> V_44 ) {
if ( V_40 -> V_44 == & V_292 )
V_35 = V_40 -> V_91 ;
} else if ( V_40 -> V_285 == F_168 )
V_35 = V_40 -> V_91 ;
if ( ! V_35 || ! F_139 ( & V_35 -> V_37 ) )
V_35 = NULL ;
return V_35 ;
}
void F_224 ( struct V_2 * V_3 )
{
V_3 -> V_86 = 1 ;
}
void F_225 ( struct V_2 * V_3 )
{
V_3 -> V_86 = 0 ;
F_69 ( V_3 ) ;
}
int T_4 F_226 ( void )
{
V_109 = F_8 ( L_20 ,
sizeof( struct V_99 ) ,
0 , 0 , NULL ) ;
if ( ! V_109 ) {
F_173 ( V_197 L_21 ) ;
return - V_16 ;
}
return 0 ;
}
void F_227 ( void )
{
F_228 ( V_6 ) ;
F_228 ( V_5 ) ;
F_228 ( V_109 ) ;
}
int
F_229 ( struct V_22 * V_35 , int V_298 , int V_299 , int V_300 ,
unsigned char * V_48 , int V_301 , int V_53 , int V_54 ,
struct V_302 * V_255 , struct V_51 * V_52 )
{
unsigned char V_18 [ 10 ] ;
unsigned char * V_303 ;
int V_11 ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 1 ] = ( V_298 ? 0x10 : 0 ) | ( V_299 ? 0x01 : 0 ) ;
if ( V_35 -> V_304 ) {
if ( V_301 > 65535 )
return - V_305 ;
V_303 = F_230 ( 8 + V_301 , V_258 ) ;
if ( ! V_303 )
return - V_16 ;
memcpy ( V_303 + 8 , V_48 , V_301 ) ;
V_301 += 8 ;
V_303 [ 0 ] = 0 ;
V_303 [ 1 ] = 0 ;
V_303 [ 2 ] = V_255 -> V_306 ;
V_303 [ 3 ] = V_255 -> V_307 ;
V_303 [ 4 ] = V_255 -> V_308 ? 0x01 : 0 ;
V_303 [ 5 ] = 0 ;
V_303 [ 6 ] = V_255 -> V_309 >> 8 ;
V_303 [ 7 ] = V_255 -> V_309 ;
V_18 [ 0 ] = V_310 ;
V_18 [ 7 ] = V_301 >> 8 ;
V_18 [ 8 ] = V_301 ;
} else {
if ( V_301 > 255 || V_255 -> V_309 > 255 ||
V_255 -> V_308 )
return - V_305 ;
V_303 = F_230 ( 4 + V_301 , V_258 ) ;
if ( ! V_303 )
return - V_16 ;
memcpy ( V_303 + 4 , V_48 , V_301 ) ;
V_301 += 4 ;
V_303 [ 0 ] = 0 ;
V_303 [ 1 ] = V_255 -> V_306 ;
V_303 [ 2 ] = V_255 -> V_307 ;
V_303 [ 3 ] = V_255 -> V_309 ;
V_18 [ 0 ] = V_311 ;
V_18 [ 4 ] = V_301 ;
}
V_11 = F_231 ( V_35 , V_18 , V_61 , V_303 , V_301 ,
V_52 , V_53 , V_54 , NULL ) ;
F_232 ( V_303 ) ;
return V_11 ;
}
int
F_233 ( struct V_22 * V_35 , int V_312 , int V_300 ,
unsigned char * V_48 , int V_301 , int V_53 , int V_54 ,
struct V_302 * V_255 , struct V_51 * V_52 )
{
unsigned char V_18 [ 12 ] ;
int V_304 ;
int V_313 ;
int V_43 , V_314 = V_54 ;
struct V_51 V_315 ;
memset ( V_255 , 0 , sizeof( * V_255 ) ) ;
memset ( & V_18 [ 0 ] , 0 , 12 ) ;
V_18 [ 1 ] = V_312 & 0x18 ;
V_18 [ 2 ] = V_300 ;
if ( ! V_52 )
V_52 = & V_315 ;
V_316:
V_304 = V_35 -> V_304 ;
if ( V_304 ) {
if ( V_301 < 8 )
V_301 = 8 ;
V_18 [ 0 ] = V_317 ;
V_18 [ 8 ] = V_301 ;
V_313 = 8 ;
} else {
if ( V_301 < 4 )
V_301 = 4 ;
V_18 [ 0 ] = V_318 ;
V_18 [ 4 ] = V_301 ;
V_313 = 4 ;
}
memset ( V_48 , 0 , V_301 ) ;
V_43 = F_231 ( V_35 , V_18 , V_192 , V_48 , V_301 ,
V_52 , V_53 , V_54 , NULL ) ;
if ( V_304 && ! F_234 ( V_43 ) &&
( F_109 ( V_43 ) & V_163 ) ) {
if ( F_235 ( V_52 ) ) {
if ( ( V_52 -> V_137 == V_146 ) &&
( V_52 -> V_139 == 0x20 ) && ( V_52 -> V_140 == 0 ) ) {
V_35 -> V_304 = 0 ;
goto V_316;
}
}
}
if( F_234 ( V_43 ) ) {
if ( F_32 ( V_48 [ 0 ] == 0x86 && V_48 [ 1 ] == 0x0b &&
( V_300 == 6 || V_300 == 8 ) ) ) {
V_313 = 0 ;
V_255 -> V_168 = 13 ;
V_255 -> V_306 = 0 ;
V_255 -> V_307 = 0 ;
V_255 -> V_308 = 0 ;
V_255 -> V_309 = 0 ;
} else if( V_304 ) {
V_255 -> V_168 = V_48 [ 0 ] * 256 + V_48 [ 1 ] + 2 ;
V_255 -> V_306 = V_48 [ 2 ] ;
V_255 -> V_307 = V_48 [ 3 ] ;
V_255 -> V_308 = V_48 [ 4 ] & 0x01 ;
V_255 -> V_309 = V_48 [ 6 ] * 256
+ V_48 [ 7 ] ;
} else {
V_255 -> V_168 = V_48 [ 0 ] + 1 ;
V_255 -> V_306 = V_48 [ 1 ] ;
V_255 -> V_307 = V_48 [ 2 ] ;
V_255 -> V_309 = V_48 [ 3 ] ;
}
V_255 -> V_313 = V_313 ;
} else if ( ( F_236 ( V_43 ) == V_319 ) &&
F_235 ( V_52 ) &&
V_52 -> V_137 == V_143 && V_314 ) {
V_314 -- ;
goto V_316;
}
return V_43 ;
}
int
F_237 ( struct V_22 * V_35 , int V_53 , int V_54 ,
struct V_51 * V_52 )
{
char V_18 [] = {
V_320 , 0 , 0 , 0 , 0 , 0 ,
} ;
int V_43 ;
do {
V_43 = F_231 ( V_35 , V_18 , V_190 , NULL , 0 , V_52 ,
V_53 , V_54 , NULL ) ;
if ( V_35 -> V_144 && F_235 ( V_52 ) &&
V_52 -> V_137 == V_143 )
V_35 -> V_145 = 1 ;
} while ( F_235 ( V_52 ) &&
V_52 -> V_137 == V_143 && -- V_54 );
return V_43 ;
}
int
F_238 ( struct V_22 * V_35 , enum V_321 V_322 )
{
enum V_321 V_323 = V_35 -> V_193 ;
if ( V_322 == V_323 )
return 0 ;
switch ( V_322 ) {
case V_324 :
switch ( V_323 ) {
case V_200 :
break;
default:
goto V_325;
}
break;
case V_194 :
switch ( V_323 ) {
case V_324 :
case V_195 :
case V_196 :
case V_201 :
case V_199 :
break;
default:
goto V_325;
}
break;
case V_201 :
switch ( V_323 ) {
case V_194 :
case V_195 :
case V_196 :
break;
default:
goto V_325;
}
break;
case V_195 :
case V_196 :
switch ( V_323 ) {
case V_324 :
case V_194 :
case V_201 :
case V_199 :
break;
default:
goto V_325;
}
break;
case V_199 :
switch ( V_323 ) {
case V_194 :
case V_200 :
break;
default:
goto V_325;
}
break;
case V_200 :
switch ( V_323 ) {
case V_324 :
break;
default:
goto V_325;
}
break;
case V_326 :
switch ( V_323 ) {
case V_324 :
case V_194 :
case V_201 :
case V_195 :
case V_196 :
case V_199 :
break;
default:
goto V_325;
}
break;
case V_198 :
switch ( V_323 ) {
case V_324 :
case V_194 :
case V_195 :
case V_196 :
case V_326 :
case V_200 :
break;
default:
goto V_325;
}
break;
}
V_35 -> V_193 = V_322 ;
return 0 ;
V_325:
F_239 ( 1 ,
F_134 ( V_197 , V_35 ,
L_22 ,
F_240 ( V_323 ) ,
F_240 ( V_322 ) )
) ;
return - V_305 ;
}
static void F_241 ( struct V_22 * V_35 , struct V_327 * V_328 )
{
int V_329 = 0 ;
char * V_330 [ 3 ] ;
switch ( V_328 -> V_331 ) {
case V_332 :
V_330 [ V_329 ++ ] = L_23 ;
break;
case V_333 :
F_242 ( & V_35 -> V_37 ) ;
V_330 [ V_329 ++ ] = L_24 ;
break;
case V_334 :
V_330 [ V_329 ++ ] = L_25 ;
break;
case V_335 :
V_330 [ V_329 ++ ] = L_26 ;
break;
case V_336 :
V_330 [ V_329 ++ ] = L_27 ;
break;
case V_337 :
V_330 [ V_329 ++ ] = L_28 ;
break;
case V_338 :
V_330 [ V_329 ++ ] = L_29 ;
break;
default:
break;
}
V_330 [ V_329 ++ ] = NULL ;
F_243 ( & V_35 -> V_37 . V_339 , V_340 , V_330 ) ;
}
void F_244 ( struct V_93 * V_94 )
{
struct V_22 * V_35 ;
enum V_341 V_331 ;
F_53 ( V_342 ) ;
V_35 = F_65 ( V_94 , struct V_22 , V_343 ) ;
for ( V_331 = V_344 ; V_331 <= V_345 ; V_331 ++ )
if ( F_245 ( V_331 , V_35 -> V_346 ) )
F_246 ( V_35 , V_331 , V_258 ) ;
while ( 1 ) {
struct V_327 * V_328 ;
struct V_347 * V_348 , * V_83 ;
unsigned long V_41 ;
F_19 ( & V_35 -> V_107 , V_41 ) ;
F_54 ( & V_35 -> V_342 , & V_342 ) ;
F_22 ( & V_35 -> V_107 , V_41 ) ;
if ( F_55 ( & V_342 ) )
break;
F_247 (this, tmp, &event_list) {
V_328 = F_56 ( V_348 , struct V_327 , V_349 ) ;
F_248 ( & V_328 -> V_349 ) ;
F_241 ( V_35 , V_328 ) ;
F_232 ( V_328 ) ;
}
}
}
void F_249 ( struct V_22 * V_35 , struct V_327 * V_328 )
{
unsigned long V_41 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_19 ( & V_35 -> V_107 , V_41 ) ;
F_126 ( & V_328 -> V_349 , & V_35 -> V_342 ) ;
F_250 ( & V_35 -> V_343 ) ;
F_22 ( & V_35 -> V_107 , V_41 ) ;
}
struct V_327 * F_251 ( enum V_341 V_331 ,
T_1 V_350 )
{
struct V_327 * V_328 = F_252 ( sizeof( struct V_327 ) , V_350 ) ;
if ( ! V_328 )
return NULL ;
V_328 -> V_331 = V_331 ;
F_157 ( & V_328 -> V_349 ) ;
switch ( V_331 ) {
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
default:
break;
}
return V_328 ;
}
void F_246 ( struct V_22 * V_35 ,
enum V_341 V_331 , T_1 V_350 )
{
struct V_327 * V_328 = F_251 ( V_331 , V_350 ) ;
if ( ! V_328 ) {
F_134 ( V_197 , V_35 , L_30 ,
V_331 ) ;
return;
}
F_249 ( V_35 , V_328 ) ;
}
static int F_253 ( struct V_22 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
int V_351 ;
F_118 ( V_35 -> V_20 -> V_352 ) ;
F_145 ( V_40 -> V_45 ) ;
V_351 = V_40 -> V_351 ;
F_146 ( V_40 -> V_45 ) ;
return V_351 ;
}
static void F_254 ( struct V_22 * V_35 )
{
F_118 ( V_35 -> V_20 -> V_352 ) ;
while ( F_253 ( V_35 ) )
F_255 ( 20 ) ;
}
int
F_256 ( struct V_22 * V_35 )
{
int V_353 = F_238 ( V_35 , V_201 ) ;
if ( V_353 )
return V_353 ;
F_62 ( V_35 -> V_39 ) ;
while ( F_49 ( & V_35 -> V_81 ) ) {
F_257 ( 200 ) ;
F_62 ( V_35 -> V_39 ) ;
}
return 0 ;
}
void F_258 ( struct V_22 * V_35 )
{
if ( V_35 -> V_193 != V_201 ||
F_238 ( V_35 , V_194 ) )
return;
F_62 ( V_35 -> V_39 ) ;
}
static void
F_259 ( struct V_22 * V_35 , void * V_255 )
{
F_256 ( V_35 ) ;
}
void
F_260 ( struct V_23 * V_24 )
{
F_261 ( V_24 , NULL , F_259 ) ;
}
static void
F_262 ( struct V_22 * V_35 , void * V_255 )
{
F_258 ( V_35 ) ;
}
void
F_263 ( struct V_23 * V_24 )
{
F_261 ( V_24 , NULL , F_262 ) ;
}
int
F_264 ( struct V_22 * V_35 , bool V_354 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
unsigned long V_41 ;
int V_353 = 0 ;
V_353 = F_238 ( V_35 , V_199 ) ;
if ( V_353 ) {
V_353 = F_238 ( V_35 , V_200 ) ;
if ( V_353 )
return V_353 ;
}
if ( V_40 -> V_44 ) {
if ( V_354 )
F_265 ( V_40 ) ;
else
F_266 ( V_40 ) ;
} else {
F_19 ( V_40 -> V_45 , V_41 ) ;
F_267 ( V_40 ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
if ( V_354 )
F_254 ( V_35 ) ;
}
return 0 ;
}
int
F_268 ( struct V_22 * V_35 ,
enum V_321 V_355 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
unsigned long V_41 ;
if ( ( V_35 -> V_193 == V_199 ) ||
( V_35 -> V_193 == V_196 ) )
V_35 -> V_193 = V_355 ;
else if ( V_35 -> V_193 == V_200 ) {
if ( V_355 == V_196 ||
V_355 == V_195 )
V_35 -> V_193 = V_355 ;
else
V_35 -> V_193 = V_324 ;
} else if ( V_35 -> V_193 != V_326 &&
V_35 -> V_193 != V_195 )
return - V_305 ;
if ( V_40 -> V_44 ) {
F_269 ( V_40 , false ) ;
} else {
F_19 ( V_40 -> V_45 , V_41 ) ;
F_270 ( V_40 ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
}
return 0 ;
}
static void
F_271 ( struct V_22 * V_35 , void * V_255 )
{
F_264 ( V_35 , true ) ;
}
static int
F_272 ( struct V_21 * V_176 , void * V_255 )
{
if ( F_273 ( V_176 ) )
F_261 ( F_274 ( V_176 ) , NULL ,
F_271 ) ;
return 0 ;
}
void
F_275 ( struct V_21 * V_176 )
{
if ( F_273 ( V_176 ) )
F_261 ( F_274 ( V_176 ) , NULL ,
F_271 ) ;
else
F_276 ( V_176 , NULL , F_272 ) ;
}
static void
F_277 ( struct V_22 * V_35 , void * V_255 )
{
F_268 ( V_35 , * (enum V_321 * ) V_255 ) ;
}
static int
F_278 ( struct V_21 * V_176 , void * V_255 )
{
if ( F_273 ( V_176 ) )
F_261 ( F_274 ( V_176 ) , V_255 ,
F_277 ) ;
return 0 ;
}
void
F_279 ( struct V_21 * V_176 , enum V_321 V_355 )
{
if ( F_273 ( V_176 ) )
F_261 ( F_274 ( V_176 ) , & V_355 ,
F_277 ) ;
else
F_276 ( V_176 , & V_355 , F_278 ) ;
}
void * F_280 ( struct V_242 * V_166 , int V_356 ,
T_5 * V_357 , T_5 * V_301 )
{
int V_358 ;
T_5 V_359 = 0 , V_360 = 0 ;
struct V_242 * V_243 ;
struct V_361 * V_361 ;
F_281 ( ! F_282 () ) ;
F_283 (sgl, sg, sg_count, i) {
V_360 = V_359 ;
V_359 += V_243 -> V_168 ;
if ( V_359 > * V_357 )
break;
}
if ( F_32 ( V_358 == V_356 ) ) {
F_173 ( V_197 L_31
L_32 ,
V_231 , V_359 , * V_357 , V_356 ) ;
F_281 ( 1 ) ;
return NULL ;
}
* V_357 = * V_357 - V_360 + V_243 -> V_357 ;
V_361 = F_284 ( F_285 ( V_243 ) , ( * V_357 >> V_269 ) ) ;
* V_357 &= ~ V_362 ;
V_359 = V_363 - * V_357 ;
if ( * V_301 > V_359 )
* V_301 = V_359 ;
return F_286 ( V_361 ) ;
}
void F_287 ( void * V_364 )
{
F_288 ( V_364 ) ;
}
void F_289 ( struct V_22 * V_35 )
{
F_154 ( & V_35 -> V_365 ) ;
}
void F_290 ( struct V_22 * V_35 )
{
if ( F_118 ( F_49 ( & V_35 -> V_365 ) <= 0 ) )
return;
F_38 ( & V_35 -> V_365 ) ;
}
int F_291 ( struct V_22 * V_35 , char * V_366 , T_5 V_367 )
{
T_6 V_368 = 0xff ;
T_6 V_369 = 0 ;
unsigned char * V_370 , * V_371 ;
unsigned char T_7 * V_372 ;
int V_373 = - V_305 ;
F_292 () ;
V_372 = F_293 ( V_35 -> V_372 ) ;
if ( ! V_372 ) {
F_294 () ;
return - V_374 ;
}
if ( V_367 < 21 ) {
F_294 () ;
return - V_305 ;
}
memset ( V_366 , 0 , V_367 ) ;
V_370 = V_372 + 4 ;
while ( V_370 < V_372 + V_35 -> V_375 ) {
if ( ( V_370 [ 1 ] & 0x30 ) != 0x00 )
goto V_376;
switch ( V_370 [ 1 ] & 0xf ) {
case 0x1 :
if ( V_369 > V_370 [ 3 ] )
break;
if ( V_368 > 0x01 && V_368 != 0xff )
break;
V_369 = V_370 [ 3 ] ;
if ( V_369 + 4 > V_367 )
V_369 = V_367 - 4 ;
V_371 = V_370 + 4 ;
V_368 = V_370 [ 1 ] & 0xf ;
V_373 = snprintf ( V_366 , V_367 , L_33 ,
V_369 , V_371 ) ;
break;
case 0x2 :
if ( V_369 > V_370 [ 3 ] )
break;
if ( V_368 == 0x3 &&
V_369 == V_370 [ 3 ] )
break;
V_369 = V_370 [ 3 ] ;
V_371 = V_370 + 4 ;
V_368 = V_370 [ 1 ] & 0xf ;
switch ( V_369 ) {
case 8 :
V_373 = snprintf ( V_366 , V_367 ,
L_34 ,
V_371 ) ;
break;
case 12 :
V_373 = snprintf ( V_366 , V_367 ,
L_35 ,
V_371 ) ;
break;
case 16 :
V_373 = snprintf ( V_366 , V_367 ,
L_36 ,
V_371 ) ;
break;
default:
V_369 = 0 ;
break;
}
break;
case 0x3 :
if ( V_369 > V_370 [ 3 ] )
break;
V_369 = V_370 [ 3 ] ;
V_371 = V_370 + 4 ;
V_368 = V_370 [ 1 ] & 0xf ;
switch ( V_369 ) {
case 8 :
V_373 = snprintf ( V_366 , V_367 ,
L_37 ,
V_371 ) ;
break;
case 16 :
V_373 = snprintf ( V_366 , V_367 ,
L_38 ,
V_371 ) ;
break;
default:
V_369 = 0 ;
break;
}
break;
case 0x8 :
if ( V_369 + 4 > V_370 [ 3 ] )
break;
if ( V_369 && V_370 [ 3 ] > V_367 )
break;
V_369 = V_373 = V_370 [ 3 ] ;
V_371 = V_370 + 4 ;
V_368 = V_370 [ 1 ] & 0xf ;
if ( V_369 >= V_367 )
V_369 = V_367 - 1 ;
memcpy ( V_366 , V_371 , V_369 ) ;
if ( V_369 != V_373 )
V_369 = 6 ;
break;
default:
break;
}
V_376:
V_370 += V_370 [ 3 ] + 4 ;
}
F_294 () ;
return V_373 ;
}
int F_295 ( struct V_22 * V_35 , int * V_377 )
{
unsigned char * V_370 ;
unsigned char T_7 * V_372 ;
int V_378 = - V_379 , V_380 = - 1 ;
F_292 () ;
V_372 = F_293 ( V_35 -> V_372 ) ;
if ( ! V_372 ) {
F_294 () ;
return - V_374 ;
}
V_370 = V_35 -> V_372 + 4 ;
while ( V_370 < V_35 -> V_372 + V_35 -> V_375 ) {
switch ( V_370 [ 1 ] & 0xf ) {
case 0x4 :
V_380 = F_296 ( & V_370 [ 6 ] ) ;
break;
case 0x5 :
V_378 = F_296 ( & V_370 [ 6 ] ) ;
break;
default:
break;
}
V_370 += V_370 [ 3 ] + 4 ;
}
F_294 () ;
if ( V_378 >= 0 && V_377 && V_380 != - 1 )
* V_377 = V_380 ;
return V_378 ;
}
