static void F_1 ( const char * V_1 )
{
static int V_2 ;
if ( ! V_2 ) {
F_2 ( V_3 L_1
L_2
L_3 , V_1 ) ;
V_2 = 1 ;
}
}
int F_3 ( const struct V_4 * V_4 , struct V_5 * V_6 ,
int V_7 , int V_8 )
{
struct V_5 * V_9 = V_6 ;
for (; ; ) {
if ( V_9 == V_4 -> V_10 )
return F_4 ( V_4 -> V_11 , V_7 ) ? 0 : - V_12 ;
if ( V_9 -> V_13 <= V_4 -> V_10 -> V_13 )
return - V_12 ;
if ( ( V_9 -> V_14 == V_4 -> V_10 ) && F_5 ( V_9 -> V_15 , V_4 -> V_16 ) )
return 0 ;
V_9 = V_9 -> V_14 ;
}
}
int F_6 ( const struct V_17 * V_18 , const struct V_19 * V_20 )
{
if ( ! F_7 ( V_21 ) )
return - V_12 ;
return 0 ;
}
int F_8 ( struct V_22 * V_23 , unsigned int V_24 )
{
int V_25 = 0 ;
const struct V_4 * V_4 , * V_26 ;
const T_1 * V_27 ;
F_9 () ;
V_4 = F_10 () ;
V_26 = F_11 ( V_23 ) ;
if ( V_24 & V_28 )
V_27 = & V_4 -> V_11 ;
else
V_27 = & V_4 -> V_29 ;
if ( V_4 -> V_10 == V_26 -> V_10 &&
F_12 ( V_26 -> V_29 , * V_27 ) )
goto V_30;
if ( F_13 ( V_26 -> V_10 , V_31 ) )
goto V_30;
V_25 = - V_12 ;
V_30:
F_14 () ;
return V_25 ;
}
int F_15 ( struct V_22 * V_14 )
{
int V_25 = 0 ;
const struct V_4 * V_4 , * V_26 ;
F_9 () ;
V_4 = F_11 ( V_14 ) ;
V_26 = F_10 () ;
if ( V_4 -> V_10 == V_26 -> V_10 &&
F_12 ( V_26 -> V_29 , V_4 -> V_29 ) )
goto V_30;
if ( F_16 ( V_14 , V_26 -> V_10 , V_31 ) )
goto V_30;
V_25 = - V_12 ;
V_30:
F_14 () ;
return V_25 ;
}
int F_17 ( struct V_22 * V_32 , T_1 * V_33 ,
T_1 * V_34 , T_1 * V_35 )
{
const struct V_4 * V_4 ;
F_9 () ;
V_4 = F_11 ( V_32 ) ;
* V_33 = V_4 -> V_11 ;
* V_34 = V_4 -> V_36 ;
* V_35 = V_4 -> V_29 ;
F_14 () ;
return 0 ;
}
static inline int F_18 ( void )
{
if ( F_3 ( F_10 () , F_10 () -> V_10 ,
V_37 , V_38 ) == 0 )
return 0 ;
return 1 ;
}
int F_19 ( struct V_4 * V_39 ,
const struct V_4 * V_40 ,
const T_1 * V_33 ,
const T_1 * V_34 ,
const T_1 * V_35 )
{
if ( F_18 () &&
! F_12 ( * V_34 ,
F_20 ( V_40 -> V_36 ,
V_40 -> V_29 ) ) )
return - V_12 ;
if ( ! F_12 ( * V_34 ,
F_20 ( V_40 -> V_36 ,
V_40 -> V_41 ) ) )
return - V_12 ;
if ( ! F_12 ( * V_35 , V_40 -> V_29 ) )
return - V_12 ;
if ( ! F_12 ( * V_33 , * V_35 ) )
return - V_12 ;
V_39 -> V_11 = * V_33 ;
V_39 -> V_36 = * V_34 ;
V_39 -> V_29 = * V_35 ;
V_39 -> V_42 = F_21 ( V_39 -> V_42 ,
F_21 ( * V_35 ,
* V_34 ) ) ;
if ( F_22 ( ! F_23 ( V_39 ) ) )
return - V_43 ;
return 0 ;
}
int F_24 ( struct V_44 * V_44 )
{
struct V_45 * V_45 = F_25 ( V_44 ) ;
int error ;
error = F_26 ( V_44 , V_45 , V_46 , NULL , 0 ) ;
return error > 0 ;
}
int F_27 ( struct V_44 * V_44 )
{
int error ;
error = F_28 ( V_44 , V_46 ) ;
if ( error == - V_47 )
error = 0 ;
return error ;
}
static bool F_29 ( T_2 V_48 )
{
struct V_5 * V_9 ;
if ( ! F_30 ( V_48 ) )
return false ;
for ( V_9 = F_31 () ; ; V_9 = V_9 -> V_14 ) {
if ( F_32 ( V_9 , V_48 ) == 0 )
return true ;
if ( V_9 == & V_49 )
break;
}
return false ;
}
static T_3 F_33 ( T_3 V_50 )
{
return V_50 & ~ V_51 ;
}
static bool F_34 ( T_4 V_52 , T_5 V_53 )
{
T_3 V_50 = F_35 ( V_53 ) ;
if ( V_52 != V_54 )
return false ;
return F_33 ( V_50 ) == V_55 ;
}
static bool F_36 ( T_4 V_52 , T_5 V_53 )
{
T_3 V_50 = F_35 ( V_53 ) ;
if ( V_52 != V_56 )
return false ;
return F_33 ( V_50 ) == V_57 ;
}
int F_37 ( struct V_45 * V_45 , const char * V_58 , void * * V_59 ,
bool V_60 )
{
int V_52 , V_25 ;
T_2 V_48 ;
T_6 V_61 , V_62 ;
char * V_63 = NULL ;
struct V_64 * V_7 ;
struct V_65 * V_66 ;
struct V_44 * V_44 ;
struct V_5 * V_67 ;
if ( strcmp ( V_58 , L_4 ) != 0 )
return - V_47 ;
V_44 = F_38 ( V_45 ) ;
if ( ! V_44 )
return - V_43 ;
V_52 = sizeof( struct V_65 ) ;
V_25 = ( int ) F_39 ( V_44 , V_46 ,
& V_63 , V_52 , V_68 ) ;
F_40 ( V_44 ) ;
if ( V_25 < 0 )
return V_25 ;
V_67 = V_45 -> V_69 -> V_70 ;
V_7 = (struct V_64 * ) V_63 ;
if ( F_34 ( ( T_4 ) V_25 , V_7 -> V_71 ) ) {
if ( V_60 )
* V_59 = V_63 ;
else
F_41 ( V_63 ) ;
return V_25 ;
} else if ( ! F_36 ( ( T_4 ) V_25 , V_7 -> V_71 ) ) {
F_41 ( V_63 ) ;
return - V_43 ;
}
V_66 = (struct V_65 * ) V_63 ;
V_61 = F_35 ( V_66 -> V_72 ) ;
V_48 = F_42 ( V_67 , V_61 ) ;
V_62 = F_32 ( F_31 () , V_48 ) ;
if ( V_62 != ( T_6 ) - 1 && V_62 != ( T_6 ) 0 ) {
if ( V_60 ) {
* V_59 = V_63 ;
V_66 -> V_72 = F_43 ( V_62 ) ;
} else
F_41 ( V_63 ) ;
return V_52 ;
}
if ( ! F_29 ( V_48 ) ) {
F_41 ( V_63 ) ;
return - V_47 ;
}
V_52 = sizeof( struct V_64 ) ;
if ( V_60 ) {
* V_59 = F_44 ( V_52 , V_73 ) ;
if ( * V_59 ) {
struct V_64 * V_7 = * V_59 ;
T_5 V_74 , V_53 ;
V_53 = V_55 ;
V_74 = F_35 ( V_66 -> V_71 ) ;
if ( V_74 & V_51 )
V_53 |= V_51 ;
memcpy ( & V_7 -> V_75 , & V_66 -> V_75 , sizeof( T_5 ) * 2 * V_76 ) ;
V_7 -> V_71 = F_43 ( V_53 ) ;
}
}
F_41 ( V_63 ) ;
return V_52 ;
}
static T_2 F_45 ( const void * V_77 , T_4 V_52 ,
struct V_5 * V_78 )
{
const struct V_65 * V_66 = V_77 ;
T_6 V_72 = 0 ;
if ( V_52 == V_56 )
V_72 = F_35 ( V_66 -> V_72 ) ;
return F_42 ( V_78 , V_72 ) ;
}
static bool F_46 ( T_4 V_52 , T_5 V_53 )
{
return F_34 ( V_52 , V_53 ) || F_36 ( V_52 , V_53 ) ;
}
int F_47 ( struct V_44 * V_44 , void * * V_79 , T_4 V_52 )
{
struct V_65 * V_66 ;
T_6 V_80 ;
const struct V_64 * V_7 = * V_79 ;
T_3 V_53 , V_74 ;
struct V_45 * V_45 = F_25 ( V_44 ) ;
struct V_5 * V_78 = F_31 () ,
* V_67 = V_45 -> V_69 -> V_70 ;
T_2 V_72 ;
T_4 V_81 ;
if ( ! * V_79 )
return - V_43 ;
if ( ! F_46 ( V_52 , V_7 -> V_71 ) )
return - V_43 ;
if ( ! F_48 ( V_45 , V_82 ) )
return - V_12 ;
if ( V_52 == V_54 )
if ( F_13 ( V_45 -> V_69 -> V_70 , V_82 ) )
return V_52 ;
V_72 = F_45 ( * V_79 , V_52 , V_78 ) ;
if ( ! F_30 ( V_72 ) )
return - V_43 ;
V_80 = F_32 ( V_67 , V_72 ) ;
if ( V_80 == - 1 )
return - V_43 ;
V_81 = sizeof( struct V_65 ) ;
V_66 = F_44 ( V_81 , V_73 ) ;
if ( ! V_66 )
return - V_83 ;
V_66 -> V_72 = F_43 ( V_80 ) ;
V_74 = V_57 ;
V_53 = F_35 ( V_7 -> V_71 ) ;
if ( V_53 & V_51 )
V_74 |= V_51 ;
V_66 -> V_71 = F_43 ( V_74 ) ;
memcpy ( & V_66 -> V_75 , & V_7 -> V_75 , sizeof( T_5 ) * 2 * V_76 ) ;
F_49 ( * V_79 ) ;
* V_79 = V_66 ;
return V_81 ;
}
static inline int F_50 ( struct V_84 * V_85 ,
struct V_86 * V_87 ,
bool * V_33 ,
bool * V_88 )
{
struct V_4 * V_39 = V_87 -> V_4 ;
unsigned V_89 ;
int V_25 = 0 ;
if ( V_85 -> V_71 & V_51 )
* V_33 = true ;
if ( V_85 -> V_71 & V_90 )
* V_88 = true ;
F_51 (i) {
T_3 V_35 = V_85 -> V_35 . V_7 [ V_89 ] ;
T_3 V_34 = V_85 -> V_34 . V_7 [ V_89 ] ;
V_39 -> V_29 . V_7 [ V_89 ] =
( V_39 -> V_41 . V_7 [ V_89 ] & V_35 ) |
( V_39 -> V_36 . V_7 [ V_89 ] & V_34 ) ;
if ( V_35 & ~ V_39 -> V_29 . V_7 [ V_89 ] )
V_25 = - V_12 ;
}
return * V_33 ? V_25 : 0 ;
}
int F_52 ( const struct V_44 * V_44 , struct V_84 * V_91 )
{
struct V_45 * V_45 = F_25 ( V_44 ) ;
T_3 V_71 ;
unsigned V_92 , V_89 ;
int V_52 ;
struct V_65 V_75 , * V_93 = & V_75 ;
struct V_64 * V_85 = (struct V_64 * ) & V_75 ;
T_2 V_94 ;
struct V_5 * V_67 ;
memset ( V_91 , 0 , sizeof( struct V_84 ) ) ;
if ( ! V_45 )
return - V_95 ;
V_67 = V_45 -> V_69 -> V_70 ;
V_52 = F_26 ( (struct V_44 * ) V_44 , V_45 ,
V_46 , & V_75 , V_96 ) ;
if ( V_52 == - V_95 || V_52 == - V_47 )
return - V_95 ;
if ( V_52 < 0 )
return V_52 ;
if ( V_52 < sizeof( V_71 ) )
return - V_43 ;
V_91 -> V_71 = V_71 = F_35 ( V_85 -> V_71 ) ;
V_94 = F_42 ( V_67 , 0 ) ;
switch ( V_71 & V_90 ) {
case V_97 :
if ( V_52 != V_98 )
return - V_43 ;
V_92 = V_99 ;
break;
case V_55 :
if ( V_52 != V_54 )
return - V_43 ;
V_92 = V_100 ;
break;
case V_57 :
if ( V_52 != V_56 )
return - V_43 ;
V_92 = V_101 ;
V_94 = F_42 ( V_67 , F_35 ( V_93 -> V_72 ) ) ;
break;
default:
return - V_43 ;
}
if ( ! F_29 ( V_94 ) )
return - V_95 ;
F_51 (i) {
if ( V_89 >= V_92 )
break;
V_91 -> V_35 . V_7 [ V_89 ] = F_35 ( V_85 -> V_75 [ V_89 ] . V_35 ) ;
V_91 -> V_34 . V_7 [ V_89 ] = F_35 ( V_85 -> V_75 [ V_89 ] . V_34 ) ;
}
V_91 -> V_35 . V_7 [ V_102 ] &= V_103 ;
V_91 -> V_34 . V_7 [ V_102 ] &= V_103 ;
return 0 ;
}
static int F_53 ( struct V_86 * V_87 , bool * V_33 , bool * V_88 )
{
int V_104 = 0 ;
struct V_84 V_105 ;
F_54 ( V_87 -> V_4 -> V_29 ) ;
if ( ! V_106 )
return 0 ;
if ( ! F_55 ( V_87 -> V_107 -> V_108 . V_109 ) )
return 0 ;
if ( ! F_56 ( V_87 -> V_107 -> V_108 . V_109 -> V_110 -> V_70 ) )
return 0 ;
V_104 = F_52 ( V_87 -> V_107 -> V_108 . V_44 , & V_105 ) ;
if ( V_104 < 0 ) {
if ( V_104 == - V_43 )
F_2 ( V_111 L_5 ,
V_87 -> V_112 ) ;
else if ( V_104 == - V_95 )
V_104 = 0 ;
goto V_30;
}
V_104 = F_50 ( & V_105 , V_87 , V_33 , V_88 ) ;
if ( V_104 == - V_43 )
F_2 ( V_111 L_6 ,
V_113 , V_104 , V_87 -> V_112 ) ;
V_30:
if ( V_104 )
F_54 ( V_87 -> V_4 -> V_29 ) ;
return V_104 ;
}
int F_57 ( struct V_86 * V_87 )
{
const struct V_4 * V_40 = F_10 () ;
struct V_4 * V_39 = V_87 -> V_4 ;
bool V_33 , V_88 = false , V_114 ;
int V_25 ;
T_2 V_115 ;
if ( F_22 ( ! F_23 ( V_40 ) ) )
return - V_12 ;
V_33 = false ;
V_25 = F_53 ( V_87 , & V_33 , & V_88 ) ;
if ( V_25 < 0 )
return V_25 ;
V_115 = F_42 ( V_39 -> V_10 , 0 ) ;
if ( ! F_58 ( V_116 ) ) {
if ( V_88 && ! F_5 ( V_39 -> V_117 , V_115 ) && F_5 ( V_39 -> V_16 , V_115 ) ) {
F_1 ( V_87 -> V_112 ) ;
goto V_118;
}
if ( F_5 ( V_39 -> V_16 , V_115 ) || F_5 ( V_39 -> V_117 , V_115 ) ) {
V_39 -> V_29 = F_20 ( V_40 -> V_41 ,
V_40 -> V_36 ) ;
}
if ( F_5 ( V_39 -> V_16 , V_115 ) )
V_33 = true ;
}
V_118:
if ( ! F_12 ( V_39 -> V_29 , V_40 -> V_29 ) )
V_87 -> V_119 |= V_120 ;
V_114 = ! F_5 ( V_39 -> V_16 , V_40 -> V_117 ) || ! F_59 ( V_39 -> V_121 , V_40 -> V_122 ) ;
if ( ( V_114 ||
! F_12 ( V_39 -> V_29 , V_40 -> V_29 ) ) &&
( ( V_87 -> V_123 & ~ V_124 ) ||
! F_60 ( V_125 , V_39 -> V_10 ) ) ) {
if ( ! F_13 ( V_39 -> V_10 , V_126 ) ||
( V_87 -> V_123 & V_127 ) ) {
V_39 -> V_16 = V_39 -> V_117 ;
V_39 -> V_121 = V_39 -> V_122 ;
}
V_39 -> V_29 = F_21 ( V_39 -> V_29 ,
V_40 -> V_29 ) ;
}
V_39 -> V_128 = V_39 -> V_129 = V_39 -> V_16 ;
V_39 -> V_130 = V_39 -> V_131 = V_39 -> V_121 ;
if ( V_88 || V_114 )
F_54 ( V_39 -> V_42 ) ;
V_39 -> V_29 = F_20 ( V_39 -> V_29 , V_39 -> V_42 ) ;
if ( V_33 )
V_39 -> V_11 = V_39 -> V_29 ;
else
V_39 -> V_11 = V_39 -> V_42 ;
if ( F_22 ( ! F_23 ( V_39 ) ) )
return - V_12 ;
if ( ! F_12 ( V_39 -> V_11 , V_39 -> V_42 ) ) {
if ( ! F_12 ( V_132 , V_39 -> V_11 ) ||
! F_5 ( V_39 -> V_16 , V_115 ) || ! F_5 ( V_39 -> V_117 , V_115 ) ||
F_58 ( V_116 ) ) {
V_25 = F_61 ( V_87 , V_39 , V_40 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
V_39 -> V_133 &= ~ F_62 ( V_134 ) ;
if ( F_22 ( ! F_23 ( V_39 ) ) )
return - V_12 ;
V_87 -> V_135 = 0 ;
if ( V_114 ) {
V_87 -> V_135 = 1 ;
} else if ( ! F_5 ( V_39 -> V_117 , V_115 ) ) {
if ( V_33 ||
! F_12 ( V_39 -> V_29 , V_39 -> V_42 ) )
V_87 -> V_135 = 1 ;
}
return 0 ;
}
int F_63 ( struct V_44 * V_44 , const char * V_58 ,
const void * V_77 , T_4 V_52 , int V_136 )
{
if ( strncmp ( V_58 , V_137 ,
sizeof( V_137 ) - 1 ) != 0 )
return 0 ;
if ( strcmp ( V_58 , V_46 ) == 0 )
return 0 ;
if ( ! F_7 ( V_138 ) )
return - V_12 ;
return 0 ;
}
int F_64 ( struct V_44 * V_44 , const char * V_58 )
{
if ( strncmp ( V_58 , V_137 ,
sizeof( V_137 ) - 1 ) != 0 )
return 0 ;
if ( strcmp ( V_58 , V_46 ) == 0 ) {
struct V_45 * V_45 = F_25 ( V_44 ) ;
if ( ! V_45 )
return - V_43 ;
if ( ! F_48 ( V_45 , V_82 ) )
return - V_12 ;
return 0 ;
}
if ( ! F_7 ( V_138 ) )
return - V_12 ;
return 0 ;
}
static inline void F_65 ( struct V_4 * V_39 , const struct V_4 * V_40 )
{
T_2 V_115 = F_42 ( V_40 -> V_10 , 0 ) ;
if ( ( F_5 ( V_40 -> V_117 , V_115 ) ||
F_5 ( V_40 -> V_16 , V_115 ) ||
F_5 ( V_40 -> V_128 , V_115 ) ) &&
( ! F_5 ( V_39 -> V_117 , V_115 ) &&
! F_5 ( V_39 -> V_16 , V_115 ) &&
! F_5 ( V_39 -> V_128 , V_115 ) ) ) {
if ( ! F_58 ( V_134 ) ) {
F_54 ( V_39 -> V_29 ) ;
F_54 ( V_39 -> V_11 ) ;
}
F_54 ( V_39 -> V_42 ) ;
}
if ( F_5 ( V_40 -> V_16 , V_115 ) && ! F_5 ( V_39 -> V_16 , V_115 ) )
F_54 ( V_39 -> V_11 ) ;
if ( ! F_5 ( V_40 -> V_16 , V_115 ) && F_5 ( V_39 -> V_16 , V_115 ) )
V_39 -> V_11 = V_39 -> V_29 ;
}
int F_66 ( struct V_4 * V_39 , const struct V_4 * V_40 , int V_136 )
{
switch ( V_136 ) {
case V_139 :
case V_140 :
case V_141 :
if ( ! F_58 ( V_142 ) )
F_65 ( V_39 , V_40 ) ;
break;
case V_143 :
if ( ! F_58 ( V_142 ) ) {
T_2 V_115 = F_42 ( V_40 -> V_10 , 0 ) ;
if ( F_5 ( V_40 -> V_129 , V_115 ) && ! F_5 ( V_39 -> V_129 , V_115 ) )
V_39 -> V_11 =
F_67 ( V_39 -> V_11 ) ;
if ( ! F_5 ( V_40 -> V_129 , V_115 ) && F_5 ( V_39 -> V_129 , V_115 ) )
V_39 -> V_11 =
F_68 ( V_39 -> V_11 ,
V_39 -> V_29 ) ;
}
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_69 ( struct V_22 * V_144 )
{
int V_145 , V_25 = 0 ;
F_9 () ;
V_145 = F_12 ( F_11 ( V_144 ) -> V_29 ,
F_10 () -> V_29 ) ;
if ( ! V_145 && ! F_13 ( F_11 ( V_144 ) -> V_10 , V_146 ) )
V_25 = - V_12 ;
F_14 () ;
return V_25 ;
}
int F_70 ( struct V_22 * V_144 )
{
return F_69 ( V_144 ) ;
}
int F_71 ( struct V_22 * V_144 , int V_147 )
{
return F_69 ( V_144 ) ;
}
int F_72 ( struct V_22 * V_144 , int V_148 )
{
return F_69 ( V_144 ) ;
}
static int F_73 ( unsigned long V_7 )
{
struct V_4 * V_39 ;
if ( ! F_13 ( F_31 () , V_37 ) )
return - V_12 ;
if ( ! F_74 ( V_7 ) )
return - V_43 ;
V_39 = F_75 () ;
if ( ! V_39 )
return - V_83 ;
F_76 ( V_39 -> V_41 , V_7 ) ;
return F_77 ( V_39 ) ;
}
int F_78 ( int V_149 , unsigned long V_150 , unsigned long V_151 ,
unsigned long V_152 , unsigned long V_153 )
{
const struct V_4 * V_40 = F_10 () ;
struct V_4 * V_39 ;
switch ( V_149 ) {
case V_154 :
if ( ! F_74 ( V_150 ) )
return - V_43 ;
return ! ! F_4 ( V_40 -> V_41 , V_150 ) ;
case V_155 :
return F_73 ( V_150 ) ;
case V_156 :
if ( ( ( ( V_40 -> V_133 & V_157 ) >> 1 )
& ( V_40 -> V_133 ^ V_150 ) )
|| ( ( V_40 -> V_133 & V_157 & ~ V_150 ) )
|| ( V_150 & ~ ( V_157 | V_158 ) )
|| ( F_3 ( F_10 () ,
F_10 () -> V_10 , V_37 ,
V_38 ) != 0 )
)
return - V_12 ;
V_39 = F_75 () ;
if ( ! V_39 )
return - V_83 ;
V_39 -> V_133 = V_150 ;
return F_77 ( V_39 ) ;
case V_159 :
return V_40 -> V_133 ;
case V_160 :
return ! ! F_58 ( V_134 ) ;
case V_161 :
if ( V_150 > 1 )
return - V_43 ;
if ( F_58 ( V_162 ) )
return - V_12 ;
V_39 = F_75 () ;
if ( ! V_39 )
return - V_83 ;
if ( V_150 )
V_39 -> V_133 |= F_62 ( V_134 ) ;
else
V_39 -> V_133 &= ~ F_62 ( V_134 ) ;
return F_77 ( V_39 ) ;
case V_163 :
if ( V_150 == V_164 ) {
if ( V_151 | V_152 | V_153 )
return - V_43 ;
V_39 = F_75 () ;
if ( ! V_39 )
return - V_83 ;
F_54 ( V_39 -> V_42 ) ;
return F_77 ( V_39 ) ;
}
if ( ( ( ! F_74 ( V_151 ) ) | V_152 | V_153 ) )
return - V_43 ;
if ( V_150 == V_165 ) {
return ! ! F_4 ( F_10 () -> V_42 , V_151 ) ;
} else if ( V_150 != V_166 &&
V_150 != V_167 ) {
return - V_43 ;
} else {
if ( V_150 == V_166 &&
( ! F_4 ( F_10 () -> V_29 , V_151 ) ||
! F_4 ( F_10 () -> V_36 ,
V_151 ) ||
F_58 ( V_168 ) ) )
return - V_12 ;
V_39 = F_75 () ;
if ( ! V_39 )
return - V_83 ;
if ( V_150 == V_166 )
F_79 ( V_39 -> V_42 , V_151 ) ;
else
F_76 ( V_39 -> V_42 , V_151 ) ;
return F_77 ( V_39 ) ;
}
default:
return - V_169 ;
}
}
int F_80 ( struct V_170 * V_171 , long V_172 )
{
int V_173 = 0 ;
if ( F_3 ( F_10 () , & V_49 , V_138 ,
V_174 ) == 0 )
V_173 = 1 ;
return V_173 ;
}
int F_81 ( unsigned long V_175 )
{
int V_25 = 0 ;
if ( V_175 < V_176 ) {
V_25 = F_3 ( F_10 () , & V_49 , V_177 ,
V_38 ) ;
if ( V_25 == 0 )
V_125 -> V_136 |= V_178 ;
}
return V_25 ;
}
int F_82 ( struct V_107 * V_107 , unsigned long V_179 ,
unsigned long V_180 , unsigned long V_136 )
{
return 0 ;
}
void T_7 F_83 ( void )
{
F_84 ( V_181 , F_85 ( V_181 ) ,
L_4 ) ;
}
