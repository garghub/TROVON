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
int F_3 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
return 0 ;
}
int F_4 ( const struct V_8 * V_8 , struct V_9 * V_10 ,
int V_11 , int V_12 )
{
struct V_9 * V_13 = V_10 ;
for (; ; ) {
if ( V_13 == V_8 -> V_14 )
return F_5 ( V_8 -> V_15 , V_11 ) ? 0 : - V_16 ;
if ( V_13 == & V_17 )
return - V_16 ;
if ( ( V_13 -> V_18 == V_8 -> V_14 ) && F_6 ( V_13 -> V_19 , V_8 -> V_20 ) )
return 0 ;
V_13 = V_13 -> V_18 ;
}
}
int F_7 ( const struct V_21 * V_22 , const struct V_23 * V_24 )
{
if ( ! F_8 ( V_25 ) )
return - V_16 ;
return 0 ;
}
int F_9 ( struct V_26 * V_27 , unsigned int V_28 )
{
int V_29 = 0 ;
const struct V_8 * V_8 , * V_30 ;
F_10 () ;
V_8 = F_11 () ;
V_30 = F_12 ( V_27 ) ;
if ( V_8 -> V_14 == V_30 -> V_14 &&
F_13 ( V_30 -> V_31 , V_8 -> V_31 ) )
goto V_32;
if ( F_14 ( V_30 -> V_14 , V_33 ) )
goto V_32;
V_29 = - V_16 ;
V_32:
F_15 () ;
return V_29 ;
}
int F_16 ( struct V_26 * V_18 )
{
int V_29 = 0 ;
const struct V_8 * V_8 , * V_30 ;
F_10 () ;
V_8 = F_12 ( V_18 ) ;
V_30 = F_11 () ;
if ( V_8 -> V_14 == V_30 -> V_14 &&
F_13 ( V_30 -> V_31 , V_8 -> V_31 ) )
goto V_32;
if ( F_17 ( V_18 , V_30 -> V_14 , V_33 ) )
goto V_32;
V_29 = - V_16 ;
V_32:
F_15 () ;
return V_29 ;
}
int F_18 ( struct V_26 * V_34 , T_1 * V_35 ,
T_1 * V_36 , T_1 * V_37 )
{
const struct V_8 * V_8 ;
F_10 () ;
V_8 = F_12 ( V_34 ) ;
* V_35 = V_8 -> V_15 ;
* V_36 = V_8 -> V_38 ;
* V_37 = V_8 -> V_31 ;
F_15 () ;
return 0 ;
}
static inline int F_19 ( void )
{
if ( F_4 ( F_11 () , F_11 () -> V_14 ,
V_39 , V_40 ) == 0 )
return 0 ;
return 1 ;
}
int F_20 ( struct V_8 * V_41 ,
const struct V_8 * V_42 ,
const T_1 * V_35 ,
const T_1 * V_36 ,
const T_1 * V_37 )
{
if ( F_19 () &&
! F_13 ( * V_36 ,
F_21 ( V_42 -> V_38 ,
V_42 -> V_31 ) ) )
return - V_16 ;
if ( ! F_13 ( * V_36 ,
F_21 ( V_42 -> V_38 ,
V_42 -> V_43 ) ) )
return - V_16 ;
if ( ! F_13 ( * V_37 , V_42 -> V_31 ) )
return - V_16 ;
if ( ! F_13 ( * V_35 , * V_37 ) )
return - V_16 ;
V_41 -> V_15 = * V_35 ;
V_41 -> V_38 = * V_36 ;
V_41 -> V_31 = * V_37 ;
return 0 ;
}
static inline void F_22 ( struct V_44 * V_45 )
{
F_23 ( V_45 -> V_8 -> V_31 ) ;
V_45 -> V_15 = false ;
}
int F_24 ( struct V_46 * V_46 )
{
struct V_47 * V_47 = V_46 -> V_48 ;
int error ;
if ( ! V_47 -> V_49 -> V_50 )
return 0 ;
error = V_47 -> V_49 -> V_50 ( V_46 , V_51 , NULL , 0 ) ;
if ( error <= 0 )
return 0 ;
return 1 ;
}
int F_25 ( struct V_46 * V_46 )
{
struct V_47 * V_47 = V_46 -> V_48 ;
if ( ! V_47 -> V_49 -> V_52 )
return 0 ;
return V_47 -> V_49 -> V_52 ( V_46 , V_51 ) ;
}
static inline int F_26 ( struct V_53 * V_54 ,
struct V_44 * V_45 ,
bool * V_35 ,
bool * V_55 )
{
struct V_8 * V_41 = V_45 -> V_8 ;
unsigned V_56 ;
int V_29 = 0 ;
if ( V_54 -> V_57 & V_58 )
* V_35 = true ;
if ( V_54 -> V_57 & V_59 )
* V_55 = true ;
F_27 (i) {
T_2 V_37 = V_54 -> V_37 . V_11 [ V_56 ] ;
T_2 V_36 = V_54 -> V_36 . V_11 [ V_56 ] ;
V_41 -> V_31 . V_11 [ V_56 ] =
( V_41 -> V_43 . V_11 [ V_56 ] & V_37 ) |
( V_41 -> V_38 . V_11 [ V_56 ] & V_36 ) ;
if ( V_37 & ~ V_41 -> V_31 . V_11 [ V_56 ] )
V_29 = - V_16 ;
}
return * V_35 ? V_29 : 0 ;
}
int F_28 ( const struct V_46 * V_46 , struct V_53 * V_60 )
{
struct V_47 * V_47 = V_46 -> V_48 ;
T_2 V_57 ;
unsigned V_61 , V_56 ;
int V_62 ;
struct V_63 V_54 ;
memset ( V_60 , 0 , sizeof( struct V_53 ) ) ;
if ( ! V_47 || ! V_47 -> V_49 -> V_50 )
return - V_64 ;
V_62 = V_47 -> V_49 -> V_50 ( (struct V_46 * ) V_46 , V_51 , & V_54 ,
V_65 ) ;
if ( V_62 == - V_64 || V_62 == - V_66 )
return - V_64 ;
if ( V_62 < 0 )
return V_62 ;
if ( V_62 < sizeof( V_57 ) )
return - V_67 ;
V_60 -> V_57 = V_57 = F_29 ( V_54 . V_57 ) ;
switch ( V_57 & V_59 ) {
case V_68 :
if ( V_62 != V_69 )
return - V_67 ;
V_61 = V_70 ;
break;
case V_71 :
if ( V_62 != V_72 )
return - V_67 ;
V_61 = V_73 ;
break;
default:
return - V_67 ;
}
F_27 (i) {
if ( V_56 >= V_61 )
break;
V_60 -> V_37 . V_11 [ V_56 ] = F_29 ( V_54 . V_74 [ V_56 ] . V_37 ) ;
V_60 -> V_36 . V_11 [ V_56 ] = F_29 ( V_54 . V_74 [ V_56 ] . V_36 ) ;
}
V_60 -> V_37 . V_11 [ V_75 ] &= V_76 ;
V_60 -> V_36 . V_11 [ V_75 ] &= V_76 ;
return 0 ;
}
static int F_30 ( struct V_44 * V_45 , bool * V_35 , bool * V_55 )
{
struct V_46 * V_46 ;
int V_77 = 0 ;
struct V_53 V_78 ;
F_22 ( V_45 ) ;
if ( ! V_79 )
return 0 ;
if ( V_45 -> V_80 -> V_81 . V_82 -> V_83 & V_84 )
return 0 ;
V_46 = F_31 ( V_45 -> V_80 -> V_85 ) ;
V_77 = F_28 ( V_46 , & V_78 ) ;
if ( V_77 < 0 ) {
if ( V_77 == - V_67 )
F_2 ( V_86 L_4 ,
V_87 , V_77 , V_45 -> V_88 ) ;
else if ( V_77 == - V_64 )
V_77 = 0 ;
goto V_32;
}
V_77 = F_26 ( & V_78 , V_45 , V_35 , V_55 ) ;
if ( V_77 == - V_67 )
F_2 ( V_86 L_5 ,
V_87 , V_77 , V_45 -> V_88 ) ;
V_32:
F_32 ( V_46 ) ;
if ( V_77 )
F_22 ( V_45 ) ;
return V_77 ;
}
int F_33 ( struct V_44 * V_45 )
{
const struct V_8 * V_42 = F_11 () ;
struct V_8 * V_41 = V_45 -> V_8 ;
bool V_35 , V_55 = false ;
int V_29 ;
T_3 V_89 ;
V_35 = false ;
V_29 = F_30 ( V_45 , & V_35 , & V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
V_89 = F_34 ( V_41 -> V_14 , 0 ) ;
if ( ! F_35 ( V_90 ) ) {
if ( V_55 && ! F_6 ( V_41 -> V_91 , V_89 ) && F_6 ( V_41 -> V_20 , V_89 ) ) {
F_1 ( V_45 -> V_88 ) ;
goto V_92;
}
if ( F_6 ( V_41 -> V_20 , V_89 ) || F_6 ( V_41 -> V_91 , V_89 ) ) {
V_41 -> V_31 = F_21 ( V_42 -> V_43 ,
V_42 -> V_38 ) ;
}
if ( F_6 ( V_41 -> V_20 , V_89 ) )
V_35 = true ;
}
V_92:
if ( ! F_13 ( V_41 -> V_31 , V_42 -> V_31 ) )
V_45 -> V_93 |= V_94 ;
if ( ( ! F_6 ( V_41 -> V_20 , V_42 -> V_91 ) ||
! F_36 ( V_41 -> V_95 , V_42 -> V_96 ) ||
! F_13 ( V_41 -> V_31 , V_42 -> V_31 ) ) &&
V_45 -> V_97 & ~ V_98 ) {
if ( ! F_8 ( V_99 ) ||
( V_45 -> V_97 & V_100 ) ) {
V_41 -> V_20 = V_41 -> V_91 ;
V_41 -> V_95 = V_41 -> V_96 ;
}
V_41 -> V_31 = F_37 ( V_41 -> V_31 ,
V_42 -> V_31 ) ;
}
V_41 -> V_101 = V_41 -> V_102 = V_41 -> V_20 ;
V_41 -> V_103 = V_41 -> V_104 = V_41 -> V_95 ;
if ( V_35 )
V_41 -> V_15 = V_41 -> V_31 ;
else
F_23 ( V_41 -> V_15 ) ;
V_45 -> V_15 = V_35 ;
if ( ! F_38 ( V_41 -> V_15 ) ) {
if ( ! F_13 ( V_105 , V_41 -> V_15 ) ||
! F_6 ( V_41 -> V_20 , V_89 ) || ! F_6 ( V_41 -> V_91 , V_89 ) ||
F_35 ( V_90 ) ) {
V_29 = F_39 ( V_45 , V_41 , V_42 ) ;
if ( V_29 < 0 )
return V_29 ;
}
}
V_41 -> V_106 &= ~ F_40 ( V_107 ) ;
return 0 ;
}
int F_41 ( struct V_44 * V_45 )
{
const struct V_8 * V_8 = F_11 () ;
T_3 V_89 = F_34 ( V_8 -> V_14 , 0 ) ;
if ( ! F_6 ( V_8 -> V_91 , V_89 ) ) {
if ( V_45 -> V_15 )
return 1 ;
if ( ! F_38 ( V_8 -> V_31 ) )
return 1 ;
}
return ( ! F_6 ( V_8 -> V_20 , V_8 -> V_91 ) ||
! F_36 ( V_8 -> V_95 , V_8 -> V_96 ) ) ;
}
int F_42 ( struct V_46 * V_46 , const char * V_108 ,
const void * V_109 , T_4 V_62 , int V_110 )
{
if ( ! strcmp ( V_108 , V_51 ) ) {
if ( ! F_8 ( V_111 ) )
return - V_16 ;
return 0 ;
}
if ( ! strncmp ( V_108 , V_112 ,
sizeof( V_112 ) - 1 ) &&
! F_8 ( V_113 ) )
return - V_16 ;
return 0 ;
}
int F_43 ( struct V_46 * V_46 , const char * V_108 )
{
if ( ! strcmp ( V_108 , V_51 ) ) {
if ( ! F_8 ( V_111 ) )
return - V_16 ;
return 0 ;
}
if ( ! strncmp ( V_108 , V_112 ,
sizeof( V_112 ) - 1 ) &&
! F_8 ( V_113 ) )
return - V_16 ;
return 0 ;
}
static inline void F_44 ( struct V_8 * V_41 , const struct V_8 * V_42 )
{
T_3 V_89 = F_34 ( V_42 -> V_14 , 0 ) ;
if ( ( F_6 ( V_42 -> V_91 , V_89 ) ||
F_6 ( V_42 -> V_20 , V_89 ) ||
F_6 ( V_42 -> V_101 , V_89 ) ) &&
( ! F_6 ( V_41 -> V_91 , V_89 ) &&
! F_6 ( V_41 -> V_20 , V_89 ) &&
! F_6 ( V_41 -> V_101 , V_89 ) ) &&
! F_35 ( V_107 ) ) {
F_23 ( V_41 -> V_31 ) ;
F_23 ( V_41 -> V_15 ) ;
}
if ( F_6 ( V_42 -> V_20 , V_89 ) && ! F_6 ( V_41 -> V_20 , V_89 ) )
F_23 ( V_41 -> V_15 ) ;
if ( ! F_6 ( V_42 -> V_20 , V_89 ) && F_6 ( V_41 -> V_20 , V_89 ) )
V_41 -> V_15 = V_41 -> V_31 ;
}
int F_45 ( struct V_8 * V_41 , const struct V_8 * V_42 , int V_110 )
{
switch ( V_110 ) {
case V_114 :
case V_115 :
case V_116 :
if ( ! F_35 ( V_117 ) )
F_44 ( V_41 , V_42 ) ;
break;
case V_118 :
if ( ! F_35 ( V_117 ) ) {
T_3 V_89 = F_34 ( V_42 -> V_14 , 0 ) ;
if ( F_6 ( V_42 -> V_102 , V_89 ) && ! F_6 ( V_41 -> V_102 , V_89 ) )
V_41 -> V_15 =
F_46 ( V_41 -> V_15 ) ;
if ( ! F_6 ( V_42 -> V_102 , V_89 ) && F_6 ( V_41 -> V_102 , V_89 ) )
V_41 -> V_15 =
F_47 ( V_41 -> V_15 ,
V_41 -> V_31 ) ;
}
break;
default:
return - V_67 ;
}
return 0 ;
}
static int F_48 ( struct V_26 * V_119 )
{
int V_120 , V_29 = 0 ;
F_10 () ;
V_120 = F_13 ( F_12 ( V_119 ) -> V_31 ,
F_11 () -> V_31 ) ;
if ( ! V_120 && ! F_14 ( F_12 ( V_119 ) -> V_14 , V_121 ) )
V_29 = - V_16 ;
F_15 () ;
return V_29 ;
}
int F_49 ( struct V_26 * V_119 )
{
return F_48 ( V_119 ) ;
}
int F_50 ( struct V_26 * V_119 , int V_122 )
{
return F_48 ( V_119 ) ;
}
int F_51 ( struct V_26 * V_119 , int V_123 )
{
return F_48 ( V_119 ) ;
}
static int F_52 ( unsigned long V_11 )
{
struct V_8 * V_41 ;
if ( ! F_14 ( F_53 () , V_39 ) )
return - V_16 ;
if ( ! F_54 ( V_11 ) )
return - V_67 ;
V_41 = F_55 () ;
if ( ! V_41 )
return - V_124 ;
F_56 ( V_41 -> V_43 , V_11 ) ;
return F_57 ( V_41 ) ;
}
int F_58 ( int V_125 , unsigned long V_126 , unsigned long V_127 ,
unsigned long V_128 , unsigned long V_129 )
{
const struct V_8 * V_42 = F_11 () ;
struct V_8 * V_41 ;
switch ( V_125 ) {
case V_130 :
if ( ! F_54 ( V_126 ) )
return - V_67 ;
return ! ! F_5 ( V_42 -> V_43 , V_126 ) ;
case V_131 :
return F_52 ( V_126 ) ;
case V_132 :
if ( ( ( ( V_42 -> V_106 & V_133 ) >> 1 )
& ( V_42 -> V_106 ^ V_126 ) )
|| ( ( V_42 -> V_106 & V_133 & ~ V_126 ) )
|| ( V_126 & ~ ( V_133 | V_134 ) )
|| ( F_4 ( F_11 () ,
F_11 () -> V_14 , V_39 ,
V_40 ) != 0 )
)
return - V_16 ;
V_41 = F_55 () ;
if ( ! V_41 )
return - V_124 ;
V_41 -> V_106 = V_126 ;
return F_57 ( V_41 ) ;
case V_135 :
return V_42 -> V_106 ;
case V_136 :
return ! ! F_35 ( V_107 ) ;
case V_137 :
if ( V_126 > 1 )
return - V_67 ;
if ( F_35 ( V_138 ) )
return - V_16 ;
V_41 = F_55 () ;
if ( ! V_41 )
return - V_124 ;
if ( V_126 )
V_41 -> V_106 |= F_40 ( V_107 ) ;
else
V_41 -> V_106 &= ~ F_40 ( V_107 ) ;
return F_57 ( V_41 ) ;
default:
return - V_139 ;
}
}
int F_59 ( struct V_140 * V_141 , long V_142 )
{
int V_143 = 0 ;
if ( F_4 ( F_11 () , & V_17 , V_113 ,
V_144 ) == 0 )
V_143 = 1 ;
return F_60 ( V_141 , V_142 , V_143 ) ;
}
int F_61 ( unsigned long V_145 )
{
int V_29 = 0 ;
if ( V_145 < V_146 ) {
V_29 = F_4 ( F_11 () , & V_17 , V_147 ,
V_40 ) ;
if ( V_29 == 0 )
V_148 -> V_110 |= V_149 ;
}
return V_29 ;
}
int F_62 ( struct V_80 * V_80 , unsigned long V_150 ,
unsigned long V_151 , unsigned long V_110 )
{
return 0 ;
}
