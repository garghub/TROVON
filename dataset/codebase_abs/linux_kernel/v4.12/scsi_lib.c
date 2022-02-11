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
V_59 -> V_54 = V_54 ;
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
V_11 = V_59 -> V_43 ;
V_65:
F_34 ( V_57 ) ;
return V_11 ;
}
static void F_35 ( struct V_17 * V_18 )
{
V_18 -> V_72 = 0 ;
F_36 ( V_18 , 0 ) ;
memset ( V_18 -> V_7 , 0 , V_13 ) ;
if ( V_18 -> V_66 == 0 )
V_18 -> V_66 = F_37 ( V_18 -> V_73 ) ;
}
void F_18 ( struct V_22 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_20 ;
struct V_23 * V_24 = V_23 ( V_35 ) ;
unsigned long V_41 ;
F_38 ( & V_3 -> V_74 ) ;
if ( V_24 -> V_75 > 0 )
F_38 ( & V_24 -> V_76 ) ;
if ( F_32 ( F_39 ( V_3 ) &&
( V_3 -> V_77 || V_3 -> V_78 ) ) ) {
F_19 ( V_3 -> V_79 , V_41 ) ;
F_40 ( V_3 ) ;
F_22 ( V_3 -> V_79 , V_41 ) ;
}
F_38 ( & V_35 -> V_80 ) ;
}
static void F_41 ( struct V_39 * V_40 )
{
if ( V_40 -> V_44 )
F_42 ( V_40 ) ;
else
F_43 ( V_40 ) ;
}
static void F_44 ( struct V_22 * V_81 )
{
struct V_2 * V_3 = V_81 -> V_20 ;
struct V_22 * V_35 , * V_82 ;
struct V_23 * V_24 = V_23 ( V_81 ) ;
unsigned long V_41 ;
F_19 ( V_3 -> V_79 , V_41 ) ;
V_24 -> V_83 = NULL ;
F_22 ( V_3 -> V_79 , V_41 ) ;
F_41 ( V_81 -> V_39 ) ;
F_19 ( V_3 -> V_79 , V_41 ) ;
if ( V_24 -> V_83 )
goto V_65;
F_45 (sdev, tmp, &starget->devices,
same_target_siblings) {
if ( V_35 == V_81 )
continue;
if ( F_46 ( V_35 ) )
continue;
F_22 ( V_3 -> V_79 , V_41 ) ;
F_41 ( V_35 -> V_39 ) ;
F_19 ( V_3 -> V_79 , V_41 ) ;
F_47 ( V_35 ) ;
}
V_65:
F_22 ( V_3 -> V_79 , V_41 ) ;
}
static inline bool F_48 ( struct V_22 * V_35 )
{
if ( F_49 ( & V_35 -> V_80 ) >= V_35 -> V_84 )
return true ;
if ( F_49 ( & V_35 -> V_30 ) > 0 )
return true ;
return false ;
}
static inline bool F_50 ( struct V_23 * V_24 )
{
if ( V_24 -> V_75 > 0 ) {
if ( F_49 ( & V_24 -> V_76 ) >= V_24 -> V_75 )
return true ;
if ( F_49 ( & V_24 -> V_33 ) > 0 )
return true ;
}
return false ;
}
static inline bool F_51 ( struct V_2 * V_3 )
{
if ( V_3 -> V_75 > 0 &&
F_49 ( & V_3 -> V_74 ) >= V_3 -> V_75 )
return true ;
if ( F_49 ( & V_3 -> V_26 ) > 0 )
return true ;
if ( V_3 -> V_85 )
return true ;
return false ;
}
static void F_52 ( struct V_2 * V_3 )
{
F_53 ( V_86 ) ;
struct V_22 * V_35 ;
unsigned long V_41 ;
F_19 ( V_3 -> V_79 , V_41 ) ;
F_54 ( & V_3 -> V_86 , & V_86 ) ;
while ( ! F_55 ( & V_86 ) ) {
struct V_39 * V_87 ;
if ( F_51 ( V_3 ) )
break;
V_35 = F_56 ( V_86 . V_88 ,
struct V_22 , V_89 ) ;
F_57 ( & V_35 -> V_89 ) ;
if ( F_50 ( V_23 ( V_35 ) ) ) {
F_58 ( & V_35 -> V_89 ,
& V_3 -> V_86 ) ;
continue;
}
V_87 = V_35 -> V_39 ;
if ( ! F_59 ( V_87 ) )
continue;
F_22 ( V_3 -> V_79 , V_41 ) ;
F_41 ( V_87 ) ;
F_60 ( V_87 ) ;
F_19 ( V_3 -> V_79 , V_41 ) ;
}
F_61 ( & V_86 , & V_3 -> V_86 ) ;
F_22 ( V_3 -> V_79 , V_41 ) ;
}
static void F_62 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
if ( V_23 ( V_35 ) -> V_91 )
F_44 ( V_35 ) ;
if ( ! F_55 ( & V_35 -> V_20 -> V_86 ) )
F_52 ( V_35 -> V_20 ) ;
if ( V_40 -> V_44 )
F_63 ( V_40 , false ) ;
else
F_43 ( V_40 ) ;
}
void F_64 ( struct V_92 * V_93 )
{
struct V_22 * V_35 ;
struct V_39 * V_40 ;
V_35 = F_65 ( V_93 , struct V_22 , V_46 ) ;
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
V_57 -> V_94 = NULL ;
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
struct V_95 * V_96 = F_73 ( V_18 ) ;
if ( V_96 -> V_97 )
V_96 -> V_97 ( V_18 ) ;
}
}
static void F_74 ( struct V_17 * V_18 )
{
struct V_98 * V_99 ;
if ( V_18 -> V_99 . V_100 . V_101 )
F_75 ( & V_18 -> V_99 . V_100 , true ) ;
if ( V_18 -> V_36 -> V_102 ) {
V_99 = V_18 -> V_36 -> V_102 -> V_94 ;
if ( V_99 )
F_75 ( & V_99 -> V_100 , true ) ;
}
if ( F_76 ( V_18 ) )
F_75 ( & V_18 -> V_103 -> V_100 , true ) ;
}
static void F_77 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_2 * V_3 = V_35 -> V_20 ;
unsigned long V_41 ;
F_74 ( V_18 ) ;
F_71 ( V_18 ) ;
if ( V_3 -> V_104 ) {
F_78 ( F_55 ( & V_18 -> V_105 ) ) ;
F_19 ( & V_35 -> V_106 , V_41 ) ;
F_57 ( & V_18 -> V_105 ) ;
F_22 ( & V_35 -> V_106 , V_41 ) ;
}
}
static void F_79 ( struct V_17 * V_18 )
{
if ( V_18 -> V_99 . V_100 . V_101 )
F_75 ( & V_18 -> V_99 . V_100 , false ) ;
memset ( & V_18 -> V_99 , 0 , sizeof( V_18 -> V_99 ) ) ;
if ( F_76 ( V_18 ) )
F_75 ( & V_18 -> V_103 -> V_100 , false ) ;
}
static void F_80 ( struct V_17 * V_18 )
{
struct V_98 * V_107 = V_18 -> V_36 -> V_102 -> V_94 ;
F_75 ( & V_107 -> V_100 , false ) ;
F_3 ( V_108 , V_107 ) ;
V_18 -> V_36 -> V_102 -> V_94 = NULL ;
}
static bool F_81 ( struct V_36 * V_57 , int error ,
unsigned int V_109 , unsigned int V_110 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_39 * V_40 = V_35 -> V_39 ;
if ( F_82 ( V_57 , error , V_109 ) )
return true ;
if ( F_32 ( V_110 ) &&
F_82 ( V_57 -> V_102 , error , V_110 ) )
return true ;
if ( F_83 ( V_40 ) )
F_84 ( V_57 -> V_111 ) ;
if ( V_57 -> V_112 ) {
F_77 ( V_18 ) ;
F_85 ( V_57 , error ) ;
if ( V_23 ( V_35 ) -> V_91 ||
! F_55 ( & V_35 -> V_20 -> V_86 ) )
F_21 ( & V_35 -> V_46 ) ;
else
F_63 ( V_40 , true ) ;
} else {
unsigned long V_41 ;
if ( V_110 )
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
case V_113 :
error = - V_114 ;
break;
case V_115 :
F_89 ( V_18 , V_116 ) ;
error = - V_117 ;
break;
case V_118 :
F_89 ( V_18 , V_116 ) ;
error = - V_119 ;
break;
case V_120 :
F_89 ( V_18 , V_116 ) ;
error = - V_121 ;
break;
case V_122 :
F_89 ( V_18 , V_116 ) ;
error = - V_123 ;
break;
default:
error = - V_124 ;
break;
}
return error ;
}
void F_90 ( struct V_17 * V_18 , unsigned int V_125 )
{
int V_43 = V_18 -> V_43 ;
struct V_39 * V_40 = V_18 -> V_21 -> V_39 ;
struct V_36 * V_57 = V_18 -> V_36 ;
int error = 0 ;
struct V_51 V_52 ;
bool V_126 = false ;
int V_127 = 0 , V_128 = 0 ;
enum { V_129 , V_130 , V_131 ,
V_132 } V_133 ;
unsigned long V_134 = ( V_18 -> V_135 + 1 ) * V_57 -> V_53 ;
if ( V_43 ) {
V_126 = F_91 ( V_18 , & V_52 ) ;
if ( V_126 )
V_127 = F_92 ( & V_52 ) ;
}
if ( F_72 ( V_57 ) ) {
if ( V_43 ) {
if ( V_126 ) {
F_27 ( V_57 ) -> V_71 =
F_93 ( 8 + V_18 -> V_7 [ 7 ] ,
V_13 ) ;
}
if ( ! V_127 )
error = F_87 ( V_18 , V_43 ) ;
}
F_27 ( V_57 ) -> V_43 = V_18 -> V_43 ;
F_27 ( V_57 ) -> V_70 = F_94 ( V_18 ) ;
if ( F_95 ( V_18 ) ) {
F_27 ( V_57 -> V_102 ) -> V_70 = F_96 ( V_18 ) -> V_56 ;
if ( F_81 ( V_57 , 0 , F_97 ( V_57 ) ,
F_97 ( V_57 -> V_102 ) ) )
F_98 () ;
return;
}
} else if ( F_97 ( V_57 ) == 0 && V_43 && ! V_127 ) {
error = F_87 ( V_18 , V_43 ) ;
}
F_78 ( F_99 ( V_57 ) ) ;
F_100 ( 1 , F_17 ( V_42 , V_18 ,
L_4 ,
F_101 ( V_57 ) , V_125 ) ) ;
if ( V_126 && ( V_52 . V_136 == V_137 ) ) {
if ( ( V_52 . V_138 == 0x0 ) && ( V_52 . V_139 == 0x1d ) )
;
else if ( ! ( V_57 -> V_55 & V_68 ) )
F_102 ( V_18 ) ;
V_43 = 0 ;
error = 0 ;
}
if ( ! ( F_97 ( V_57 ) == 0 && error ) &&
! F_81 ( V_57 , error , V_125 , 0 ) )
return;
if ( error && F_103 ( V_18 ) ) {
if ( F_81 ( V_57 , error , F_97 ( V_57 ) , 0 ) )
F_98 () ;
return;
}
if ( V_43 == 0 )
goto V_140;
error = F_87 ( V_18 , V_43 ) ;
if ( F_88 ( V_43 ) == V_141 ) {
V_133 = V_131 ;
} else if ( V_126 && ! V_127 ) {
switch ( V_52 . V_136 ) {
case V_142 :
if ( V_18 -> V_21 -> V_143 ) {
V_18 -> V_21 -> V_144 = 1 ;
V_133 = V_129 ;
} else {
V_133 = V_131 ;
}
break;
case V_145 :
if ( ( V_18 -> V_21 -> V_146 &&
V_52 . V_138 == 0x20 && V_52 . V_139 == 0x00 ) &&
( V_18 -> V_73 [ 0 ] == V_147 ||
V_18 -> V_73 [ 0 ] == V_148 ) ) {
V_18 -> V_21 -> V_146 = 0 ;
V_133 = V_130 ;
} else if ( V_52 . V_138 == 0x10 ) {
V_133 = V_129 ;
error = - V_149 ;
} else if ( V_52 . V_138 == 0x20 || V_52 . V_138 == 0x24 ) {
V_133 = V_129 ;
error = - V_117 ;
} else
V_133 = V_129 ;
break;
case V_150 :
V_133 = V_129 ;
if ( V_52 . V_138 == 0x10 )
error = - V_149 ;
break;
case V_151 :
if ( V_52 . V_138 == 0x04 ) {
switch ( V_52 . V_139 ) {
case 0x01 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x14 :
V_133 = V_132 ;
break;
default:
V_133 = V_129 ;
break;
}
} else
V_133 = V_129 ;
break;
case V_152 :
V_133 = V_129 ;
break;
default:
V_133 = V_129 ;
break;
}
} else
V_133 = V_129 ;
if ( V_133 != V_129 &&
F_104 ( V_18 -> V_153 + V_134 , V_154 ) )
V_133 = V_129 ;
switch ( V_133 ) {
case V_129 :
if ( ! ( V_57 -> V_55 & V_68 ) ) {
static F_105 ( V_155 ,
V_156 ,
V_157 ) ;
if ( F_32 ( V_158 ) )
V_128 = F_106 ( V_159 ,
V_160 ) ;
if ( ! V_128 && F_107 ( & V_155 ) ) {
F_108 ( V_18 , NULL , V_161 ) ;
if ( F_109 ( V_43 ) & V_162 )
F_102 ( V_18 ) ;
F_110 ( V_18 ) ;
}
}
if ( ! F_81 ( V_57 , error , F_111 ( V_57 ) , 0 ) )
return;
case V_130 :
V_140:
if ( V_40 -> V_44 ) {
V_18 -> V_36 -> V_55 &= ~ V_163 ;
F_77 ( V_18 ) ;
F_12 ( V_18 ) ;
} else {
F_79 ( V_18 ) ;
F_66 ( V_40 , V_18 ) ;
}
break;
case V_131 :
F_15 ( V_18 , V_29 , 0 ) ;
break;
case V_132 :
F_15 ( V_18 , V_28 , 0 ) ;
break;
}
}
static int F_112 ( struct V_36 * V_57 , struct V_98 * V_99 )
{
int V_164 ;
if ( F_32 ( F_113 ( & V_99 -> V_100 ,
F_114 ( V_57 ) , V_99 -> V_100 . V_165 ) ) )
return V_166 ;
V_164 = F_115 ( V_57 -> V_40 , V_57 , V_99 -> V_100 . V_165 ) ;
F_78 ( V_164 > V_99 -> V_100 . V_101 ) ;
V_99 -> V_100 . V_101 = V_164 ;
V_99 -> V_167 = F_116 ( V_57 ) ;
return V_168 ;
}
int F_117 ( struct V_17 * V_18 )
{
struct V_22 * V_35 = V_18 -> V_21 ;
struct V_36 * V_59 = V_18 -> V_36 ;
bool V_169 = ( V_59 -> V_112 != NULL ) ;
int error = V_170 ;
if ( F_118 ( ! F_114 ( V_59 ) ) )
goto V_171;
error = F_112 ( V_59 , & V_18 -> V_99 ) ;
if ( error )
goto V_171;
if ( F_99 ( V_59 ) ) {
if ( ! V_59 -> V_40 -> V_44 ) {
struct V_98 * V_107 =
F_119 ( V_108 , V_172 ) ;
if ( ! V_107 ) {
error = V_166 ;
goto V_171;
}
V_59 -> V_102 -> V_94 = V_107 ;
}
error = F_112 ( V_59 -> V_102 , V_59 -> V_102 -> V_94 ) ;
if ( error )
goto V_171;
}
if ( F_120 ( V_59 ) ) {
struct V_98 * V_103 = V_18 -> V_103 ;
int V_173 , V_164 ;
if ( V_103 == NULL ) {
F_118 ( 1 ) ;
error = V_170 ;
goto V_171;
}
V_173 = F_121 ( V_59 -> V_40 , V_59 -> V_174 ) ;
if ( F_113 ( & V_103 -> V_100 , V_173 ,
V_103 -> V_100 . V_165 ) ) {
error = V_166 ;
goto V_171;
}
V_164 = F_122 ( V_59 -> V_40 , V_59 -> V_174 ,
V_103 -> V_100 . V_165 ) ;
F_78 ( F_32 ( V_164 > V_173 ) ) ;
F_78 ( F_32 ( V_164 > F_123 ( V_59 -> V_40 ) ) ) ;
V_18 -> V_103 = V_103 ;
V_18 -> V_103 -> V_100 . V_101 = V_164 ;
}
return V_168 ;
V_171:
if ( V_169 ) {
F_74 ( V_18 ) ;
} else {
F_79 ( V_18 ) ;
V_18 -> V_36 -> V_94 = NULL ;
F_68 ( V_18 ) ;
F_14 ( & V_35 -> V_37 ) ;
}
return error ;
}
void F_124 ( struct V_22 * V_175 , struct V_17 * V_18 )
{
void * V_176 = V_18 -> V_7 ;
void * V_177 = V_18 -> V_103 ;
unsigned long V_41 ;
memset ( ( char * ) V_18 + sizeof( V_18 -> V_57 ) , 0 ,
sizeof( * V_18 ) - sizeof( V_18 -> V_57 ) + V_175 -> V_20 -> V_178 -> V_179 ) ;
V_18 -> V_21 = V_175 ;
V_18 -> V_7 = V_176 ;
V_18 -> V_103 = V_177 ;
F_125 ( & V_18 -> V_180 , V_181 ) ;
V_18 -> V_153 = V_154 ;
F_19 ( & V_175 -> V_106 , V_41 ) ;
F_126 ( & V_18 -> V_105 , & V_175 -> V_182 ) ;
F_22 ( & V_175 -> V_106 , V_41 ) ;
}
static int F_127 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
if ( V_57 -> V_174 ) {
int V_11 = F_117 ( V_18 ) ;
if ( F_32 ( V_11 ) )
return V_11 ;
} else {
F_78 ( F_97 ( V_57 ) ) ;
memset ( & V_18 -> V_99 , 0 , sizeof( V_18 -> V_99 ) ) ;
}
V_18 -> V_66 = F_27 ( V_57 ) -> V_66 ;
V_18 -> V_73 = F_27 ( V_57 ) -> V_18 ;
V_18 -> V_183 = F_97 ( V_57 ) ;
V_18 -> V_135 = F_27 ( V_57 ) -> V_54 ;
return V_168 ;
}
static int F_128 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
if ( F_32 ( V_35 -> V_184 && V_35 -> V_184 -> V_185 ) ) {
int V_11 = V_35 -> V_184 -> V_185 ( V_35 , V_57 ) ;
if ( V_11 != V_168 )
return V_11 ;
}
V_18 -> V_73 = F_27 ( V_57 ) -> V_18 = F_27 ( V_57 ) -> V_186 ;
memset ( V_18 -> V_73 , 0 , V_187 ) ;
return F_73 ( V_18 ) -> F_129 ( V_18 ) ;
}
static int F_130 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
struct V_17 * V_18 = V_57 -> V_94 ;
if ( ! F_97 ( V_57 ) )
V_18 -> V_188 = V_189 ;
else if ( F_131 ( V_57 ) == V_190 )
V_18 -> V_188 = V_61 ;
else
V_18 -> V_188 = V_191 ;
if ( F_132 ( V_57 ) )
return F_127 ( V_35 , V_57 ) ;
else
return F_128 ( V_35 , V_57 ) ;
}
static int
F_133 ( struct V_22 * V_35 , struct V_36 * V_57 )
{
int V_11 = V_168 ;
if ( F_32 ( V_35 -> V_192 != V_193 ) ) {
switch ( V_35 -> V_192 ) {
case V_194 :
case V_195 :
F_134 ( V_196 , V_35 ,
L_5 ) ;
V_11 = V_170 ;
break;
case V_197 :
F_134 ( V_196 , V_35 ,
L_6 ) ;
V_11 = V_170 ;
break;
case V_198 :
case V_199 :
V_11 = V_166 ;
break;
case V_200 :
if ( ! ( V_57 -> V_55 & V_69 ) )
V_11 = V_166 ;
break;
default:
if ( ! ( V_57 -> V_55 & V_69 ) )
V_11 = V_170 ;
break;
}
}
return V_11 ;
}
static int
F_135 ( struct V_39 * V_40 , struct V_36 * V_57 , int V_11 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
switch ( V_11 ) {
case V_170 :
case V_201 :
F_27 ( V_57 ) -> V_43 = V_202 << 16 ;
if ( V_57 -> V_94 ) {
struct V_17 * V_18 = V_57 -> V_94 ;
F_79 ( V_18 ) ;
F_68 ( V_18 ) ;
F_14 ( & V_35 -> V_37 ) ;
V_57 -> V_94 = NULL ;
}
break;
case V_166 :
if ( F_49 ( & V_35 -> V_80 ) == 0 )
F_136 ( V_40 , V_203 ) ;
break;
default:
V_57 -> V_55 |= V_163 ;
}
return V_11 ;
}
static int F_137 ( struct V_39 * V_40 , struct V_36 * V_57 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
struct V_17 * V_18 = F_138 ( V_57 ) ;
int V_11 ;
V_11 = F_133 ( V_35 , V_57 ) ;
if ( V_11 != V_168 )
goto V_65;
if ( ! V_57 -> V_94 ) {
if ( F_32 ( ! F_139 ( & V_35 -> V_37 ) ) ) {
V_11 = V_166 ;
goto V_65;
}
F_124 ( V_35 , V_18 ) ;
V_57 -> V_94 = V_18 ;
}
V_18 -> V_204 = V_57 -> V_204 ;
V_18 -> V_36 = V_57 ;
V_18 -> V_205 = V_206 ;
V_11 = F_130 ( V_35 , V_57 ) ;
V_65:
return F_135 ( V_40 , V_57 , V_11 ) ;
}
static void F_140 ( struct V_39 * V_40 , struct V_36 * V_57 )
{
F_71 ( V_57 -> V_94 ) ;
}
static inline int F_141 ( struct V_39 * V_40 ,
struct V_22 * V_35 )
{
unsigned int V_207 ;
V_207 = F_142 ( & V_35 -> V_80 ) - 1 ;
if ( F_49 ( & V_35 -> V_30 ) ) {
if ( V_207 )
goto V_208;
if ( F_143 ( & V_35 -> V_30 ) > 0 ) {
if ( ! V_40 -> V_44 )
F_136 ( V_40 , V_203 ) ;
goto V_208;
}
F_16 ( 3 , F_134 ( V_42 , V_35 ,
L_7 ) ) ;
}
if ( V_207 >= V_35 -> V_84 )
goto V_208;
return 1 ;
V_208:
F_38 ( & V_35 -> V_80 ) ;
return 0 ;
}
static inline int F_144 ( struct V_2 * V_3 ,
struct V_22 * V_35 )
{
struct V_23 * V_24 = V_23 ( V_35 ) ;
unsigned int V_207 ;
if ( V_24 -> V_91 ) {
F_145 ( V_3 -> V_79 ) ;
if ( V_24 -> V_83 &&
V_24 -> V_83 != V_35 ) {
F_146 ( V_3 -> V_79 ) ;
return 0 ;
}
V_24 -> V_83 = V_35 ;
F_146 ( V_3 -> V_79 ) ;
}
if ( V_24 -> V_75 <= 0 )
return 1 ;
V_207 = F_142 ( & V_24 -> V_76 ) - 1 ;
if ( F_49 ( & V_24 -> V_33 ) > 0 ) {
if ( V_207 )
goto V_209;
if ( F_143 ( & V_24 -> V_33 ) > 0 )
goto V_208;
F_16 ( 3 , F_147 ( V_42 , V_24 ,
L_8 ) ) ;
}
if ( V_207 >= V_24 -> V_75 )
goto V_209;
return 1 ;
V_209:
F_145 ( V_3 -> V_79 ) ;
F_58 ( & V_35 -> V_89 , & V_3 -> V_86 ) ;
F_146 ( V_3 -> V_79 ) ;
V_208:
if ( V_24 -> V_75 > 0 )
F_38 ( & V_24 -> V_76 ) ;
return 0 ;
}
static inline int F_148 ( struct V_39 * V_40 ,
struct V_2 * V_3 ,
struct V_22 * V_35 )
{
unsigned int V_207 ;
if ( F_39 ( V_3 ) )
return 0 ;
V_207 = F_142 ( & V_3 -> V_74 ) - 1 ;
if ( F_49 ( & V_3 -> V_26 ) > 0 ) {
if ( V_207 )
goto V_209;
if ( F_143 ( & V_3 -> V_26 ) > 0 )
goto V_208;
F_16 ( 3 ,
F_149 ( V_42 , V_3 ,
L_9 ) ) ;
}
if ( V_3 -> V_75 > 0 && V_207 >= V_3 -> V_75 )
goto V_209;
if ( V_3 -> V_85 )
goto V_209;
if ( ! F_55 ( & V_35 -> V_89 ) ) {
F_145 ( V_3 -> V_79 ) ;
if ( ! F_55 ( & V_35 -> V_89 ) )
F_57 ( & V_35 -> V_89 ) ;
F_146 ( V_3 -> V_79 ) ;
}
return 1 ;
V_209:
F_145 ( V_3 -> V_79 ) ;
if ( F_55 ( & V_35 -> V_89 ) )
F_126 ( & V_35 -> V_89 , & V_3 -> V_86 ) ;
F_146 ( V_3 -> V_79 ) ;
V_208:
F_38 ( & V_3 -> V_74 ) ;
return 0 ;
}
static int F_150 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
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
struct V_17 * V_18 = V_57 -> V_94 ;
struct V_22 * V_35 ;
struct V_23 * V_24 ;
struct V_2 * V_3 ;
F_153 ( V_57 ) ;
F_17 ( V_42 , V_18 , L_10 ) ;
V_35 = V_18 -> V_21 ;
V_24 = V_23 ( V_35 ) ;
V_3 = V_35 -> V_20 ;
F_35 ( V_18 ) ;
V_18 -> V_43 = V_202 << 16 ;
F_154 ( & V_18 -> V_21 -> V_210 ) ;
F_154 ( & V_35 -> V_80 ) ;
F_154 ( & V_3 -> V_74 ) ;
if ( V_24 -> V_75 > 0 )
F_154 ( & V_24 -> V_76 ) ;
F_155 ( V_57 ) ;
}
static void F_156 ( struct V_36 * V_59 )
{
struct V_17 * V_18 = V_59 -> V_94 ;
unsigned long V_134 = ( V_18 -> V_135 + 1 ) * V_59 -> V_53 ;
int V_211 ;
F_157 ( & V_18 -> V_212 ) ;
F_154 ( & V_18 -> V_21 -> V_213 ) ;
if ( V_18 -> V_43 )
F_154 ( & V_18 -> V_21 -> V_214 ) ;
V_211 = F_158 ( V_18 ) ;
if ( V_211 != V_215 &&
F_104 ( V_18 -> V_153 + V_134 , V_154 ) ) {
F_134 ( V_196 , V_18 -> V_21 ,
L_11 ,
V_134 / V_216 ) ;
V_211 = V_215 ;
}
F_159 ( V_18 , V_211 ) ;
switch ( V_211 ) {
case V_215 :
F_160 ( V_18 ) ;
break;
case V_217 :
F_23 ( V_18 , V_29 ) ;
break;
case V_218 :
F_23 ( V_18 , V_28 ) ;
break;
default:
F_161 ( V_18 ) ;
break;
}
}
static int F_162 ( struct V_17 * V_18 )
{
struct V_2 * V_20 = V_18 -> V_21 -> V_20 ;
int V_219 = 0 ;
F_154 ( & V_18 -> V_21 -> V_210 ) ;
if ( F_32 ( V_18 -> V_21 -> V_192 == V_197 ) ) {
V_18 -> V_43 = V_202 << 16 ;
goto V_220;
}
if ( F_32 ( F_163 ( V_18 -> V_21 ) ) ) {
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_12 ) ) ;
return V_28 ;
}
if ( V_18 -> V_21 -> V_221 )
V_18 -> V_73 [ 1 ] = ( V_18 -> V_73 [ 1 ] & 0x1f ) |
( V_18 -> V_21 -> V_222 << 5 & 0xe0 ) ;
F_164 ( V_18 ) ;
if ( V_18 -> V_66 > V_18 -> V_21 -> V_20 -> V_223 ) {
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_13
L_14 ,
V_18 -> V_66 , V_18 -> V_21 -> V_20 -> V_223 ) ) ;
V_18 -> V_43 = ( V_224 << 16 ) ;
goto V_220;
}
if ( F_32 ( V_20 -> V_225 == V_226 ) ) {
V_18 -> V_43 = ( V_202 << 16 ) ;
goto V_220;
}
F_165 ( V_18 ) ;
V_219 = V_20 -> V_178 -> V_227 ( V_20 , V_18 ) ;
if ( V_219 ) {
F_166 ( V_18 , V_219 ) ;
if ( V_219 != V_28 &&
V_219 != V_32 )
V_219 = V_25 ;
F_16 ( 3 , F_17 ( V_42 , V_18 ,
L_15 ) ) ;
}
return V_219 ;
V_220:
V_18 -> V_228 ( V_18 ) ;
return 0 ;
}
static void V_228 ( struct V_17 * V_18 )
{
F_167 ( V_18 ) ;
F_155 ( V_18 -> V_36 ) ;
}
static void F_168 ( struct V_39 * V_40 )
__releases( V_40 -> V_45 )
__acquires( V_40 -> V_45 )
{
struct V_22 * V_35 = V_40 -> V_90 ;
struct V_2 * V_3 ;
struct V_17 * V_18 ;
struct V_36 * V_57 ;
V_3 = V_35 -> V_20 ;
for (; ; ) {
int V_219 ;
V_57 = F_169 ( V_40 ) ;
if ( ! V_57 )
break;
if ( F_32 ( ! F_170 ( V_35 ) ) ) {
F_134 ( V_196 , V_35 ,
L_5 ) ;
F_152 ( V_57 , V_40 ) ;
continue;
}
if ( ! F_141 ( V_40 , V_35 ) )
break;
if ( ! ( F_171 ( V_40 ) && ! F_172 ( V_40 , V_57 ) ) )
F_153 ( V_57 ) ;
F_146 ( V_40 -> V_45 ) ;
V_18 = V_57 -> V_94 ;
if ( F_32 ( V_18 == NULL ) ) {
F_173 ( V_229 L_16
L_17
L_18 ,
V_230 ) ;
F_174 ( V_57 , L_19 ) ;
F_98 () ;
}
if ( F_171 ( V_40 ) && ! ( V_57 -> V_55 & V_231 ) ) {
F_145 ( V_3 -> V_79 ) ;
if ( F_55 ( & V_35 -> V_89 ) )
F_126 ( & V_35 -> V_89 ,
& V_3 -> V_86 ) ;
F_146 ( V_3 -> V_79 ) ;
goto V_232;
}
if ( ! F_144 ( V_3 , V_35 ) )
goto V_232;
if ( ! F_148 ( V_40 , V_3 , V_35 ) )
goto V_233;
if ( V_35 -> V_234 )
V_18 -> V_41 |= V_235 ;
else
V_18 -> V_41 &= ~ V_235 ;
F_35 ( V_18 ) ;
V_18 -> V_228 = V_228 ;
V_219 = F_162 ( V_18 ) ;
if ( V_219 ) {
F_23 ( V_18 , V_219 ) ;
F_145 ( V_40 -> V_45 ) ;
goto V_236;
}
F_145 ( V_40 -> V_45 ) ;
}
return;
V_233:
if ( V_23 ( V_35 ) -> V_75 > 0 )
F_38 ( & V_23 ( V_35 ) -> V_76 ) ;
V_232:
F_145 ( V_40 -> V_45 ) ;
F_20 ( V_40 , V_57 ) ;
F_38 ( & V_35 -> V_80 ) ;
V_236:
if ( ! F_49 ( & V_35 -> V_80 ) && ! F_163 ( V_35 ) )
F_136 ( V_40 , V_203 ) ;
}
static inline int F_175 ( int V_11 )
{
switch ( V_11 ) {
case V_168 :
return V_237 ;
case V_166 :
return V_238 ;
default:
return V_239 ;
}
}
static int F_176 ( struct V_36 * V_57 )
{
struct V_17 * V_18 = F_138 ( V_57 ) ;
struct V_22 * V_35 = V_57 -> V_40 -> V_90 ;
struct V_2 * V_3 = V_35 -> V_20 ;
unsigned char * V_240 = V_18 -> V_7 ;
struct V_241 * V_242 ;
memset ( ( char * ) V_18 + sizeof( V_18 -> V_57 ) , 0 ,
sizeof( * V_18 ) - sizeof( V_18 -> V_57 ) + V_3 -> V_178 -> V_179 ) ;
V_57 -> V_94 = V_18 ;
V_18 -> V_36 = V_57 ;
V_18 -> V_21 = V_35 ;
V_18 -> V_7 = V_240 ;
V_18 -> V_204 = V_57 -> V_204 ;
V_18 -> V_205 = V_206 ;
F_157 ( & V_18 -> V_105 ) ;
F_125 ( & V_18 -> V_180 , V_181 ) ;
V_18 -> V_153 = V_154 ;
if ( V_3 -> V_104 ) {
F_145 ( & V_35 -> V_106 ) ;
F_126 ( & V_18 -> V_105 , & V_35 -> V_182 ) ;
F_146 ( & V_35 -> V_106 ) ;
}
V_242 = ( void * ) V_18 + sizeof( struct V_17 ) + V_3 -> V_178 -> V_179 ;
V_18 -> V_99 . V_100 . V_165 = V_242 ;
if ( F_177 ( V_3 ) ) {
V_18 -> V_103 = ( void * ) V_242 +
F_178 (unsigned int,
shost->sg_tablesize, SG_CHUNK_SIZE) *
sizeof( struct V_241 ) ;
memset ( V_18 -> V_103 , 0 , sizeof( struct V_98 ) ) ;
V_18 -> V_103 -> V_100 . V_165 =
(struct V_241 * ) ( V_18 -> V_103 + 1 ) ;
}
if ( F_99 ( V_57 ) ) {
struct V_36 * V_102 = V_57 -> V_102 ;
struct V_98 * V_107 = F_138 ( V_102 ) ;
memset ( V_107 , 0 , sizeof( struct V_98 ) ) ;
V_107 -> V_100 . V_165 =
(struct V_241 * ) ( V_107 + 1 ) ;
V_102 -> V_94 = V_107 ;
}
F_179 ( V_57 ) ;
return F_130 ( V_35 , V_57 ) ;
}
static void F_180 ( struct V_17 * V_18 )
{
F_167 ( V_18 ) ;
F_181 ( V_18 -> V_36 ) ;
}
static int F_182 ( struct V_243 * V_244 ,
const struct V_245 * V_246 )
{
struct V_36 * V_57 = V_246 -> V_59 ;
struct V_39 * V_40 = V_57 -> V_40 ;
struct V_22 * V_35 = V_40 -> V_90 ;
struct V_2 * V_3 = V_35 -> V_20 ;
struct V_17 * V_18 = F_138 ( V_57 ) ;
int V_11 ;
int V_19 ;
V_11 = F_175 ( F_133 ( V_35 , V_57 ) ) ;
if ( V_11 != V_237 )
goto V_65;
V_11 = V_238 ;
if ( ! F_139 ( & V_35 -> V_37 ) )
goto V_65;
if ( ! F_141 ( V_40 , V_35 ) )
goto V_247;
if ( ! F_144 ( V_3 , V_35 ) )
goto V_248;
if ( ! F_148 ( V_40 , V_3 , V_35 ) )
goto V_249;
if ( ! ( V_57 -> V_55 & V_163 ) ) {
V_11 = F_175 ( F_176 ( V_57 ) ) ;
if ( V_11 != V_237 )
goto V_250;
V_57 -> V_55 |= V_163 ;
} else {
F_179 ( V_57 ) ;
}
if ( V_35 -> V_234 )
V_18 -> V_41 |= V_235 ;
else
V_18 -> V_41 &= ~ V_235 ;
F_35 ( V_18 ) ;
V_18 -> V_228 = F_180 ;
V_19 = F_162 ( V_18 ) ;
if ( V_19 ) {
F_10 ( V_18 , V_19 ) ;
V_11 = V_238 ;
goto V_250;
}
return V_237 ;
V_250:
F_38 ( & V_3 -> V_74 ) ;
V_249:
if ( V_23 ( V_35 ) -> V_75 > 0 )
F_38 ( & V_23 ( V_35 ) -> V_76 ) ;
V_248:
F_38 ( & V_35 -> V_80 ) ;
V_247:
F_14 ( & V_35 -> V_37 ) ;
V_65:
switch ( V_11 ) {
case V_238 :
if ( F_49 ( & V_35 -> V_80 ) == 0 &&
! F_163 ( V_35 ) )
F_183 ( V_244 , V_203 ) ;
break;
case V_239 :
if ( V_57 -> V_55 & V_163 )
F_77 ( V_18 ) ;
break;
default:
break;
}
return V_11 ;
}
static enum V_251 F_184 ( struct V_36 * V_57 ,
bool V_252 )
{
if ( V_252 )
return V_253 ;
return F_185 ( V_57 ) ;
}
static int F_186 ( struct V_254 * V_255 , struct V_36 * V_59 ,
unsigned int V_256 , unsigned int V_9 )
{
struct V_2 * V_3 = V_255 -> V_257 ;
struct V_17 * V_18 = F_138 ( V_59 ) ;
V_18 -> V_7 =
F_4 ( V_3 , V_258 , V_9 ) ;
if ( ! V_18 -> V_7 )
return - V_16 ;
V_18 -> V_57 . V_50 = V_18 -> V_7 ;
return 0 ;
}
static void F_187 ( struct V_254 * V_255 , struct V_36 * V_59 ,
unsigned int V_256 )
{
struct V_2 * V_3 = V_255 -> V_257 ;
struct V_17 * V_18 = F_138 ( V_59 ) ;
F_2 ( V_3 , V_18 -> V_7 ) ;
}
static int F_188 ( struct V_254 * V_255 )
{
struct V_2 * V_3 = F_65 ( V_255 , struct V_2 , V_259 ) ;
if ( V_3 -> V_178 -> V_260 )
return V_3 -> V_178 -> V_260 ( V_3 ) ;
return F_189 ( V_255 ) ;
}
static T_2 F_190 ( struct V_2 * V_3 )
{
struct V_21 * V_261 ;
T_2 V_262 = 0xffffffff ;
if ( V_3 -> V_4 )
return V_263 ;
if ( ! V_264 )
return V_265 ;
V_261 = F_191 ( V_3 ) ;
if ( V_261 && V_261 -> V_266 )
V_262 = ( T_2 ) F_192 ( V_261 ) << V_267 ;
return V_262 ;
}
void F_193 ( struct V_2 * V_3 , struct V_39 * V_40 )
{
struct V_21 * V_175 = V_3 -> V_268 ;
F_194 ( V_40 , F_178 (unsigned short, shost->sg_tablesize,
SG_MAX_SEGMENTS) ) ;
if ( F_195 ( V_3 ) ) {
V_3 -> V_269 =
F_196 ( V_3 -> V_269 ,
( unsigned short ) V_270 ) ;
F_78 ( V_3 -> V_269 < V_3 -> V_271 ) ;
F_197 ( V_40 , V_3 -> V_269 ) ;
}
F_198 ( V_40 , V_3 -> V_272 ) ;
F_199 ( V_40 , F_190 ( V_3 ) ) ;
F_200 ( V_40 , V_3 -> V_273 ) ;
F_201 ( V_175 , V_3 -> V_273 ) ;
F_202 ( V_40 , F_203 ( V_175 ) ) ;
if ( ! V_3 -> V_274 )
V_40 -> V_275 . V_276 = 0 ;
F_204 ( V_40 , 0x03 ) ;
}
static int F_205 ( struct V_39 * V_40 , struct V_36 * V_59 , T_1 V_277 )
{
struct V_2 * V_3 = V_40 -> V_278 ;
struct V_17 * V_18 = F_138 ( V_59 ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_7 = F_4 ( V_3 , V_277 , V_279 ) ;
if ( ! V_18 -> V_7 )
goto V_280;
V_18 -> V_57 . V_50 = V_18 -> V_7 ;
if ( F_177 ( V_3 ) >= V_281 ) {
V_18 -> V_103 = F_119 ( V_108 , V_277 ) ;
if ( ! V_18 -> V_103 )
goto V_282;
}
return 0 ;
V_282:
F_2 ( V_3 , V_18 -> V_7 ) ;
V_280:
return - V_16 ;
}
static void F_206 ( struct V_39 * V_40 , struct V_36 * V_59 )
{
struct V_2 * V_3 = V_40 -> V_278 ;
struct V_17 * V_18 = F_138 ( V_59 ) ;
if ( V_18 -> V_103 )
F_3 ( V_108 , V_18 -> V_103 ) ;
F_2 ( V_3 , V_18 -> V_7 ) ;
}
struct V_39 * F_207 ( struct V_22 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_20 ;
struct V_39 * V_40 ;
V_40 = F_208 ( V_258 , V_279 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_179 = sizeof( struct V_17 ) + V_3 -> V_178 -> V_179 ;
V_40 -> V_278 = V_3 ;
V_40 -> V_283 = F_168 ;
V_40 -> V_284 = F_205 ;
V_40 -> V_285 = F_206 ;
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
V_35 -> V_39 = F_217 ( & V_35 -> V_20 -> V_259 ) ;
if ( F_26 ( V_35 -> V_39 ) )
return NULL ;
V_35 -> V_39 -> V_90 = V_35 ;
F_193 ( V_35 -> V_20 , V_35 -> V_39 ) ;
return V_35 -> V_39 ;
}
int F_218 ( struct V_2 * V_3 )
{
unsigned int V_179 , V_286 , V_287 ;
V_287 = V_3 -> V_271 ;
if ( V_287 > V_288 )
V_287 = V_288 ;
V_286 = V_287 * sizeof( struct V_241 ) ;
V_179 = sizeof( struct V_17 ) + V_3 -> V_178 -> V_179 + V_286 ;
if ( F_177 ( V_3 ) )
V_179 += sizeof( struct V_98 ) + V_286 ;
memset ( & V_3 -> V_259 , 0 , sizeof( V_3 -> V_259 ) ) ;
V_3 -> V_259 . V_289 = & V_290 ;
V_3 -> V_259 . V_291 = V_3 -> V_291 ? : 1 ;
V_3 -> V_259 . V_84 = V_3 -> V_75 ;
V_3 -> V_259 . V_179 = V_179 ;
V_3 -> V_259 . V_9 = V_279 ;
V_3 -> V_259 . V_41 = V_292 | V_293 ;
V_3 -> V_259 . V_41 |=
F_219 ( V_3 -> V_178 -> V_294 ) ;
V_3 -> V_259 . V_257 = V_3 ;
return F_220 ( & V_3 -> V_259 ) ;
}
void F_221 ( struct V_2 * V_3 )
{
F_222 ( & V_3 -> V_259 ) ;
}
struct V_22 * F_223 ( struct V_39 * V_40 )
{
struct V_22 * V_35 = NULL ;
if ( V_40 -> V_44 ) {
if ( V_40 -> V_44 == & V_290 )
V_35 = V_40 -> V_90 ;
} else if ( V_40 -> V_283 == F_168 )
V_35 = V_40 -> V_90 ;
if ( ! V_35 || ! F_139 ( & V_35 -> V_37 ) )
V_35 = NULL ;
return V_35 ;
}
void F_224 ( struct V_2 * V_3 )
{
V_3 -> V_85 = 1 ;
}
void F_225 ( struct V_2 * V_3 )
{
V_3 -> V_85 = 0 ;
F_69 ( V_3 ) ;
}
int T_4 F_226 ( void )
{
V_108 = F_8 ( L_20 ,
sizeof( struct V_98 ) ,
0 , 0 , NULL ) ;
if ( ! V_108 ) {
F_173 ( V_196 L_21 ) ;
return - V_16 ;
}
return 0 ;
}
void F_227 ( void )
{
F_228 ( V_6 ) ;
F_228 ( V_5 ) ;
F_228 ( V_108 ) ;
}
int
F_229 ( struct V_22 * V_35 , int V_295 , int V_296 , int V_297 ,
unsigned char * V_48 , int V_298 , int V_53 , int V_54 ,
struct V_299 * V_300 , struct V_51 * V_52 )
{
unsigned char V_18 [ 10 ] ;
unsigned char * V_301 ;
int V_11 ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 1 ] = ( V_295 ? 0x10 : 0 ) | ( V_296 ? 0x01 : 0 ) ;
if ( V_35 -> V_302 ) {
if ( V_298 > 65535 )
return - V_303 ;
V_301 = F_230 ( 8 + V_298 , V_258 ) ;
if ( ! V_301 )
return - V_16 ;
memcpy ( V_301 + 8 , V_48 , V_298 ) ;
V_298 += 8 ;
V_301 [ 0 ] = 0 ;
V_301 [ 1 ] = 0 ;
V_301 [ 2 ] = V_300 -> V_304 ;
V_301 [ 3 ] = V_300 -> V_305 ;
V_301 [ 4 ] = V_300 -> V_306 ? 0x01 : 0 ;
V_301 [ 5 ] = 0 ;
V_301 [ 6 ] = V_300 -> V_307 >> 8 ;
V_301 [ 7 ] = V_300 -> V_307 ;
V_18 [ 0 ] = V_308 ;
V_18 [ 7 ] = V_298 >> 8 ;
V_18 [ 8 ] = V_298 ;
} else {
if ( V_298 > 255 || V_300 -> V_307 > 255 ||
V_300 -> V_306 )
return - V_303 ;
V_301 = F_230 ( 4 + V_298 , V_258 ) ;
if ( ! V_301 )
return - V_16 ;
memcpy ( V_301 + 4 , V_48 , V_298 ) ;
V_298 += 4 ;
V_301 [ 0 ] = 0 ;
V_301 [ 1 ] = V_300 -> V_304 ;
V_301 [ 2 ] = V_300 -> V_305 ;
V_301 [ 3 ] = V_300 -> V_307 ;
V_18 [ 0 ] = V_309 ;
V_18 [ 4 ] = V_298 ;
}
V_11 = F_231 ( V_35 , V_18 , V_61 , V_301 , V_298 ,
V_52 , V_53 , V_54 , NULL ) ;
F_232 ( V_301 ) ;
return V_11 ;
}
int
F_233 ( struct V_22 * V_35 , int V_310 , int V_297 ,
unsigned char * V_48 , int V_298 , int V_53 , int V_54 ,
struct V_299 * V_300 , struct V_51 * V_52 )
{
unsigned char V_18 [ 12 ] ;
int V_302 ;
int V_311 ;
int V_43 , V_312 = V_54 ;
struct V_51 V_313 ;
memset ( V_300 , 0 , sizeof( * V_300 ) ) ;
memset ( & V_18 [ 0 ] , 0 , 12 ) ;
V_18 [ 1 ] = V_310 & 0x18 ;
V_18 [ 2 ] = V_297 ;
if ( ! V_52 )
V_52 = & V_313 ;
V_314:
V_302 = V_35 -> V_302 ;
if ( V_302 ) {
if ( V_298 < 8 )
V_298 = 8 ;
V_18 [ 0 ] = V_315 ;
V_18 [ 8 ] = V_298 ;
V_311 = 8 ;
} else {
if ( V_298 < 4 )
V_298 = 4 ;
V_18 [ 0 ] = V_316 ;
V_18 [ 4 ] = V_298 ;
V_311 = 4 ;
}
memset ( V_48 , 0 , V_298 ) ;
V_43 = F_231 ( V_35 , V_18 , V_191 , V_48 , V_298 ,
V_52 , V_53 , V_54 , NULL ) ;
if ( V_302 && ! F_234 ( V_43 ) &&
( F_109 ( V_43 ) & V_162 ) ) {
if ( F_235 ( V_52 ) ) {
if ( ( V_52 -> V_136 == V_145 ) &&
( V_52 -> V_138 == 0x20 ) && ( V_52 -> V_139 == 0 ) ) {
V_35 -> V_302 = 0 ;
goto V_314;
}
}
}
if( F_234 ( V_43 ) ) {
if ( F_32 ( V_48 [ 0 ] == 0x86 && V_48 [ 1 ] == 0x0b &&
( V_297 == 6 || V_297 == 8 ) ) ) {
V_311 = 0 ;
V_300 -> V_167 = 13 ;
V_300 -> V_304 = 0 ;
V_300 -> V_305 = 0 ;
V_300 -> V_306 = 0 ;
V_300 -> V_307 = 0 ;
} else if( V_302 ) {
V_300 -> V_167 = V_48 [ 0 ] * 256 + V_48 [ 1 ] + 2 ;
V_300 -> V_304 = V_48 [ 2 ] ;
V_300 -> V_305 = V_48 [ 3 ] ;
V_300 -> V_306 = V_48 [ 4 ] & 0x01 ;
V_300 -> V_307 = V_48 [ 6 ] * 256
+ V_48 [ 7 ] ;
} else {
V_300 -> V_167 = V_48 [ 0 ] + 1 ;
V_300 -> V_304 = V_48 [ 1 ] ;
V_300 -> V_305 = V_48 [ 2 ] ;
V_300 -> V_307 = V_48 [ 3 ] ;
}
V_300 -> V_311 = V_311 ;
} else if ( ( F_236 ( V_43 ) == V_317 ) &&
F_235 ( V_52 ) &&
V_52 -> V_136 == V_142 && V_312 ) {
V_312 -- ;
goto V_314;
}
return V_43 ;
}
int
F_237 ( struct V_22 * V_35 , int V_53 , int V_54 ,
struct V_51 * V_52 )
{
char V_18 [] = {
V_318 , 0 , 0 , 0 , 0 , 0 ,
} ;
int V_43 ;
do {
V_43 = F_231 ( V_35 , V_18 , V_189 , NULL , 0 , V_52 ,
V_53 , V_54 , NULL ) ;
if ( V_35 -> V_143 && F_235 ( V_52 ) &&
V_52 -> V_136 == V_142 )
V_35 -> V_144 = 1 ;
} while ( F_235 ( V_52 ) &&
V_52 -> V_136 == V_142 && -- V_54 );
return V_43 ;
}
int
F_238 ( struct V_22 * V_35 , enum V_319 V_320 )
{
enum V_319 V_321 = V_35 -> V_192 ;
if ( V_320 == V_321 )
return 0 ;
switch ( V_320 ) {
case V_322 :
switch ( V_321 ) {
case V_199 :
break;
default:
goto V_323;
}
break;
case V_193 :
switch ( V_321 ) {
case V_322 :
case V_194 :
case V_195 :
case V_200 :
case V_198 :
break;
default:
goto V_323;
}
break;
case V_200 :
switch ( V_321 ) {
case V_193 :
case V_194 :
case V_195 :
break;
default:
goto V_323;
}
break;
case V_194 :
case V_195 :
switch ( V_321 ) {
case V_322 :
case V_193 :
case V_200 :
case V_198 :
break;
default:
goto V_323;
}
break;
case V_198 :
switch ( V_321 ) {
case V_193 :
case V_199 :
break;
default:
goto V_323;
}
break;
case V_199 :
switch ( V_321 ) {
case V_322 :
break;
default:
goto V_323;
}
break;
case V_324 :
switch ( V_321 ) {
case V_322 :
case V_193 :
case V_200 :
case V_194 :
case V_195 :
case V_198 :
break;
default:
goto V_323;
}
break;
case V_197 :
switch ( V_321 ) {
case V_322 :
case V_193 :
case V_194 :
case V_195 :
case V_324 :
case V_199 :
break;
default:
goto V_323;
}
break;
}
V_35 -> V_192 = V_320 ;
return 0 ;
V_323:
F_239 ( 1 ,
F_134 ( V_196 , V_35 ,
L_22 ,
F_240 ( V_321 ) ,
F_240 ( V_320 ) )
) ;
return - V_303 ;
}
static void F_241 ( struct V_22 * V_35 , struct V_325 * V_326 )
{
int V_327 = 0 ;
char * V_328 [ 3 ] ;
switch ( V_326 -> V_329 ) {
case V_330 :
V_328 [ V_327 ++ ] = L_23 ;
break;
case V_331 :
F_242 ( & V_35 -> V_37 ) ;
V_328 [ V_327 ++ ] = L_24 ;
break;
case V_332 :
V_328 [ V_327 ++ ] = L_25 ;
break;
case V_333 :
V_328 [ V_327 ++ ] = L_26 ;
break;
case V_334 :
V_328 [ V_327 ++ ] = L_27 ;
break;
case V_335 :
V_328 [ V_327 ++ ] = L_28 ;
break;
case V_336 :
V_328 [ V_327 ++ ] = L_29 ;
break;
default:
break;
}
V_328 [ V_327 ++ ] = NULL ;
F_243 ( & V_35 -> V_37 . V_337 , V_338 , V_328 ) ;
}
void F_244 ( struct V_92 * V_93 )
{
struct V_22 * V_35 ;
enum V_339 V_329 ;
F_53 ( V_340 ) ;
V_35 = F_65 ( V_93 , struct V_22 , V_341 ) ;
for ( V_329 = V_342 ; V_329 <= V_343 ; V_329 ++ )
if ( F_245 ( V_329 , V_35 -> V_344 ) )
F_246 ( V_35 , V_329 , V_258 ) ;
while ( 1 ) {
struct V_325 * V_326 ;
struct V_345 * V_346 , * V_82 ;
unsigned long V_41 ;
F_19 ( & V_35 -> V_106 , V_41 ) ;
F_54 ( & V_35 -> V_340 , & V_340 ) ;
F_22 ( & V_35 -> V_106 , V_41 ) ;
if ( F_55 ( & V_340 ) )
break;
F_247 (this, tmp, &event_list) {
V_326 = F_56 ( V_346 , struct V_325 , V_347 ) ;
F_248 ( & V_326 -> V_347 ) ;
F_241 ( V_35 , V_326 ) ;
F_232 ( V_326 ) ;
}
}
}
void F_249 ( struct V_22 * V_35 , struct V_325 * V_326 )
{
unsigned long V_41 ;
#if 0
if (!test_bit(evt->evt_type, sdev->supported_events)) {
kfree(evt);
return;
}
#endif
F_19 ( & V_35 -> V_106 , V_41 ) ;
F_126 ( & V_326 -> V_347 , & V_35 -> V_340 ) ;
F_250 ( & V_35 -> V_341 ) ;
F_22 ( & V_35 -> V_106 , V_41 ) ;
}
struct V_325 * F_251 ( enum V_339 V_329 ,
T_1 V_348 )
{
struct V_325 * V_326 = F_252 ( sizeof( struct V_325 ) , V_348 ) ;
if ( ! V_326 )
return NULL ;
V_326 -> V_329 = V_329 ;
F_157 ( & V_326 -> V_347 ) ;
switch ( V_329 ) {
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
default:
break;
}
return V_326 ;
}
void F_246 ( struct V_22 * V_35 ,
enum V_339 V_329 , T_1 V_348 )
{
struct V_325 * V_326 = F_251 ( V_329 , V_348 ) ;
if ( ! V_326 ) {
F_134 ( V_196 , V_35 , L_30 ,
V_329 ) ;
return;
}
F_249 ( V_35 , V_326 ) ;
}
static int F_253 ( struct V_22 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
int V_349 ;
F_118 ( V_35 -> V_20 -> V_350 ) ;
F_145 ( V_40 -> V_45 ) ;
V_349 = V_40 -> V_349 ;
F_146 ( V_40 -> V_45 ) ;
return V_349 ;
}
static void F_254 ( struct V_22 * V_35 )
{
F_118 ( V_35 -> V_20 -> V_350 ) ;
while ( F_253 ( V_35 ) )
F_255 ( 20 ) ;
}
int
F_256 ( struct V_22 * V_35 )
{
int V_351 = F_238 ( V_35 , V_200 ) ;
if ( V_351 )
return V_351 ;
F_62 ( V_35 -> V_39 ) ;
while ( F_49 ( & V_35 -> V_80 ) ) {
F_257 ( 200 ) ;
F_62 ( V_35 -> V_39 ) ;
}
return 0 ;
}
void F_258 ( struct V_22 * V_35 )
{
if ( V_35 -> V_192 != V_200 ||
F_238 ( V_35 , V_193 ) )
return;
F_62 ( V_35 -> V_39 ) ;
}
static void
F_259 ( struct V_22 * V_35 , void * V_300 )
{
F_256 ( V_35 ) ;
}
void
F_260 ( struct V_23 * V_24 )
{
F_261 ( V_24 , NULL , F_259 ) ;
}
static void
F_262 ( struct V_22 * V_35 , void * V_300 )
{
F_258 ( V_35 ) ;
}
void
F_263 ( struct V_23 * V_24 )
{
F_261 ( V_24 , NULL , F_262 ) ;
}
int
F_264 ( struct V_22 * V_35 , bool V_352 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
unsigned long V_41 ;
int V_351 = 0 ;
V_351 = F_238 ( V_35 , V_198 ) ;
if ( V_351 ) {
V_351 = F_238 ( V_35 , V_199 ) ;
if ( V_351 )
return V_351 ;
}
if ( V_40 -> V_44 ) {
if ( V_352 )
F_265 ( V_40 ) ;
else
F_266 ( V_40 ) ;
} else {
F_19 ( V_40 -> V_45 , V_41 ) ;
F_267 ( V_40 ) ;
F_22 ( V_40 -> V_45 , V_41 ) ;
if ( V_352 )
F_254 ( V_35 ) ;
}
return 0 ;
}
int
F_268 ( struct V_22 * V_35 ,
enum V_319 V_353 )
{
struct V_39 * V_40 = V_35 -> V_39 ;
unsigned long V_41 ;
if ( ( V_35 -> V_192 == V_198 ) ||
( V_35 -> V_192 == V_195 ) )
V_35 -> V_192 = V_353 ;
else if ( V_35 -> V_192 == V_199 ) {
if ( V_353 == V_195 ||
V_353 == V_194 )
V_35 -> V_192 = V_353 ;
else
V_35 -> V_192 = V_322 ;
} else if ( V_35 -> V_192 != V_324 &&
V_35 -> V_192 != V_194 )
return - V_303 ;
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
F_271 ( struct V_22 * V_35 , void * V_300 )
{
F_264 ( V_35 , true ) ;
}
static int
F_272 ( struct V_21 * V_175 , void * V_300 )
{
if ( F_273 ( V_175 ) )
F_261 ( F_274 ( V_175 ) , NULL ,
F_271 ) ;
return 0 ;
}
void
F_275 ( struct V_21 * V_175 )
{
if ( F_273 ( V_175 ) )
F_261 ( F_274 ( V_175 ) , NULL ,
F_271 ) ;
else
F_276 ( V_175 , NULL , F_272 ) ;
}
static void
F_277 ( struct V_22 * V_35 , void * V_300 )
{
F_268 ( V_35 , * (enum V_319 * ) V_300 ) ;
}
static int
F_278 ( struct V_21 * V_175 , void * V_300 )
{
if ( F_273 ( V_175 ) )
F_261 ( F_274 ( V_175 ) , V_300 ,
F_277 ) ;
return 0 ;
}
void
F_279 ( struct V_21 * V_175 , enum V_319 V_353 )
{
if ( F_273 ( V_175 ) )
F_261 ( F_274 ( V_175 ) , & V_353 ,
F_277 ) ;
else
F_276 ( V_175 , & V_353 , F_278 ) ;
}
void * F_280 ( struct V_241 * V_165 , int V_354 ,
T_5 * V_355 , T_5 * V_298 )
{
int V_356 ;
T_5 V_357 = 0 , V_358 = 0 ;
struct V_241 * V_242 ;
struct V_359 * V_359 ;
F_281 ( ! F_282 () ) ;
F_283 (sgl, sg, sg_count, i) {
V_358 = V_357 ;
V_357 += V_242 -> V_167 ;
if ( V_357 > * V_355 )
break;
}
if ( F_32 ( V_356 == V_354 ) ) {
F_173 ( V_196 L_31
L_32 ,
V_230 , V_357 , * V_355 , V_354 ) ;
F_281 ( 1 ) ;
return NULL ;
}
* V_355 = * V_355 - V_358 + V_242 -> V_355 ;
V_359 = F_284 ( F_285 ( V_242 ) , ( * V_355 >> V_267 ) ) ;
* V_355 &= ~ V_360 ;
V_357 = V_361 - * V_355 ;
if ( * V_298 > V_357 )
* V_298 = V_357 ;
return F_286 ( V_359 ) ;
}
void F_287 ( void * V_362 )
{
F_288 ( V_362 ) ;
}
void F_289 ( struct V_22 * V_35 )
{
F_154 ( & V_35 -> V_363 ) ;
}
void F_290 ( struct V_22 * V_35 )
{
if ( F_118 ( F_49 ( & V_35 -> V_363 ) <= 0 ) )
return;
F_38 ( & V_35 -> V_363 ) ;
}
int F_291 ( struct V_22 * V_35 , char * V_364 , T_5 V_365 )
{
T_6 V_366 = 0xff ;
T_6 V_367 = 0 ;
unsigned char * V_368 , * V_369 ;
unsigned char T_7 * V_370 ;
int V_371 = - V_303 ;
F_292 () ;
V_370 = F_293 ( V_35 -> V_370 ) ;
if ( ! V_370 ) {
F_294 () ;
return - V_372 ;
}
if ( V_365 < 21 ) {
F_294 () ;
return - V_303 ;
}
memset ( V_364 , 0 , V_365 ) ;
V_368 = V_370 + 4 ;
while ( V_368 < V_370 + V_35 -> V_373 ) {
if ( ( V_368 [ 1 ] & 0x30 ) != 0x00 )
goto V_374;
switch ( V_368 [ 1 ] & 0xf ) {
case 0x1 :
if ( V_367 > V_368 [ 3 ] )
break;
if ( V_366 > 0x01 && V_366 != 0xff )
break;
V_367 = V_368 [ 3 ] ;
if ( V_367 + 4 > V_365 )
V_367 = V_365 - 4 ;
V_369 = V_368 + 4 ;
V_366 = V_368 [ 1 ] & 0xf ;
V_371 = snprintf ( V_364 , V_365 , L_33 ,
V_367 , V_369 ) ;
break;
case 0x2 :
if ( V_367 > V_368 [ 3 ] )
break;
if ( V_366 == 0x3 &&
V_367 == V_368 [ 3 ] )
break;
V_367 = V_368 [ 3 ] ;
V_369 = V_368 + 4 ;
V_366 = V_368 [ 1 ] & 0xf ;
switch ( V_367 ) {
case 8 :
V_371 = snprintf ( V_364 , V_365 ,
L_34 ,
V_369 ) ;
break;
case 12 :
V_371 = snprintf ( V_364 , V_365 ,
L_35 ,
V_369 ) ;
break;
case 16 :
V_371 = snprintf ( V_364 , V_365 ,
L_36 ,
V_369 ) ;
break;
default:
V_367 = 0 ;
break;
}
break;
case 0x3 :
if ( V_367 > V_368 [ 3 ] )
break;
V_367 = V_368 [ 3 ] ;
V_369 = V_368 + 4 ;
V_366 = V_368 [ 1 ] & 0xf ;
switch ( V_367 ) {
case 8 :
V_371 = snprintf ( V_364 , V_365 ,
L_37 ,
V_369 ) ;
break;
case 16 :
V_371 = snprintf ( V_364 , V_365 ,
L_38 ,
V_369 ) ;
break;
default:
V_367 = 0 ;
break;
}
break;
case 0x8 :
if ( V_367 + 4 > V_368 [ 3 ] )
break;
if ( V_367 && V_368 [ 3 ] > V_365 )
break;
V_367 = V_371 = V_368 [ 3 ] ;
V_369 = V_368 + 4 ;
V_366 = V_368 [ 1 ] & 0xf ;
if ( V_367 >= V_365 )
V_367 = V_365 - 1 ;
memcpy ( V_364 , V_369 , V_367 ) ;
if ( V_367 != V_371 )
V_367 = 6 ;
break;
default:
break;
}
V_374:
V_368 += V_368 [ 3 ] + 4 ;
}
F_294 () ;
return V_371 ;
}
int F_295 ( struct V_22 * V_35 , int * V_375 )
{
unsigned char * V_368 ;
unsigned char T_7 * V_370 ;
int V_376 = - V_377 , V_378 = - 1 ;
F_292 () ;
V_370 = F_293 ( V_35 -> V_370 ) ;
if ( ! V_370 ) {
F_294 () ;
return - V_372 ;
}
V_368 = V_35 -> V_370 + 4 ;
while ( V_368 < V_35 -> V_370 + V_35 -> V_373 ) {
switch ( V_368 [ 1 ] & 0xf ) {
case 0x4 :
V_378 = F_296 ( & V_368 [ 6 ] ) ;
break;
case 0x5 :
V_376 = F_296 ( & V_368 [ 6 ] ) ;
break;
default:
break;
}
V_368 += V_368 [ 3 ] + 4 ;
}
F_294 () ;
if ( V_376 >= 0 && V_375 && V_378 != - 1 )
* V_375 = V_378 ;
return V_376 ;
}
