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
int V_77 = 0 ;
struct V_53 V_78 ;
F_22 ( V_45 ) ;
if ( ! V_79 )
return 0 ;
if ( V_45 -> V_80 -> V_81 . V_82 -> V_83 & V_84 )
return 0 ;
V_77 = F_28 ( V_45 -> V_80 -> V_81 . V_46 , & V_78 ) ;
if ( V_77 < 0 ) {
if ( V_77 == - V_67 )
F_2 ( V_85 L_4 ,
V_86 , V_77 , V_45 -> V_87 ) ;
else if ( V_77 == - V_64 )
V_77 = 0 ;
goto V_32;
}
V_77 = F_26 ( & V_78 , V_45 , V_35 , V_55 ) ;
if ( V_77 == - V_67 )
F_2 ( V_85 L_5 ,
V_86 , V_77 , V_45 -> V_87 ) ;
V_32:
if ( V_77 )
F_22 ( V_45 ) ;
return V_77 ;
}
int F_31 ( struct V_44 * V_45 )
{
const struct V_8 * V_42 = F_11 () ;
struct V_8 * V_41 = V_45 -> V_8 ;
bool V_35 , V_55 = false ;
int V_29 ;
T_3 V_88 ;
V_35 = false ;
V_29 = F_30 ( V_45 , & V_35 , & V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
V_88 = F_32 ( V_41 -> V_14 , 0 ) ;
if ( ! F_33 ( V_89 ) ) {
if ( V_55 && ! F_6 ( V_41 -> V_90 , V_88 ) && F_6 ( V_41 -> V_20 , V_88 ) ) {
F_1 ( V_45 -> V_87 ) ;
goto V_91;
}
if ( F_6 ( V_41 -> V_20 , V_88 ) || F_6 ( V_41 -> V_90 , V_88 ) ) {
V_41 -> V_31 = F_21 ( V_42 -> V_43 ,
V_42 -> V_38 ) ;
}
if ( F_6 ( V_41 -> V_20 , V_88 ) )
V_35 = true ;
}
V_91:
if ( ! F_13 ( V_41 -> V_31 , V_42 -> V_31 ) )
V_45 -> V_92 |= V_93 ;
if ( ( ! F_6 ( V_41 -> V_20 , V_42 -> V_90 ) ||
! F_34 ( V_41 -> V_94 , V_42 -> V_95 ) ||
! F_13 ( V_41 -> V_31 , V_42 -> V_31 ) ) &&
V_45 -> V_96 & ~ V_97 ) {
if ( ! F_8 ( V_98 ) ||
( V_45 -> V_96 & V_99 ) ) {
V_41 -> V_20 = V_41 -> V_90 ;
V_41 -> V_94 = V_41 -> V_95 ;
}
V_41 -> V_31 = F_35 ( V_41 -> V_31 ,
V_42 -> V_31 ) ;
}
V_41 -> V_100 = V_41 -> V_101 = V_41 -> V_20 ;
V_41 -> V_102 = V_41 -> V_103 = V_41 -> V_94 ;
if ( V_35 )
V_41 -> V_15 = V_41 -> V_31 ;
else
F_23 ( V_41 -> V_15 ) ;
V_45 -> V_15 = V_35 ;
if ( ! F_36 ( V_41 -> V_15 ) ) {
if ( ! F_13 ( V_104 , V_41 -> V_15 ) ||
! F_6 ( V_41 -> V_20 , V_88 ) || ! F_6 ( V_41 -> V_90 , V_88 ) ||
F_33 ( V_89 ) ) {
V_29 = F_37 ( V_45 , V_41 , V_42 ) ;
if ( V_29 < 0 )
return V_29 ;
}
}
V_41 -> V_105 &= ~ F_38 ( V_106 ) ;
return 0 ;
}
int F_39 ( struct V_44 * V_45 )
{
const struct V_8 * V_8 = F_11 () ;
T_3 V_88 = F_32 ( V_8 -> V_14 , 0 ) ;
if ( ! F_6 ( V_8 -> V_90 , V_88 ) ) {
if ( V_45 -> V_15 )
return 1 ;
if ( ! F_36 ( V_8 -> V_31 ) )
return 1 ;
}
return ( ! F_6 ( V_8 -> V_20 , V_8 -> V_90 ) ||
! F_34 ( V_8 -> V_94 , V_8 -> V_95 ) ) ;
}
int F_40 ( struct V_46 * V_46 , const char * V_107 ,
const void * V_108 , T_4 V_62 , int V_109 )
{
if ( ! strcmp ( V_107 , V_51 ) ) {
if ( ! F_8 ( V_110 ) )
return - V_16 ;
return 0 ;
}
if ( ! strncmp ( V_107 , V_111 ,
sizeof( V_111 ) - 1 ) &&
! F_8 ( V_112 ) )
return - V_16 ;
return 0 ;
}
int F_41 ( struct V_46 * V_46 , const char * V_107 )
{
if ( ! strcmp ( V_107 , V_51 ) ) {
if ( ! F_8 ( V_110 ) )
return - V_16 ;
return 0 ;
}
if ( ! strncmp ( V_107 , V_111 ,
sizeof( V_111 ) - 1 ) &&
! F_8 ( V_112 ) )
return - V_16 ;
return 0 ;
}
static inline void F_42 ( struct V_8 * V_41 , const struct V_8 * V_42 )
{
T_3 V_88 = F_32 ( V_42 -> V_14 , 0 ) ;
if ( ( F_6 ( V_42 -> V_90 , V_88 ) ||
F_6 ( V_42 -> V_20 , V_88 ) ||
F_6 ( V_42 -> V_100 , V_88 ) ) &&
( ! F_6 ( V_41 -> V_90 , V_88 ) &&
! F_6 ( V_41 -> V_20 , V_88 ) &&
! F_6 ( V_41 -> V_100 , V_88 ) ) &&
! F_33 ( V_106 ) ) {
F_23 ( V_41 -> V_31 ) ;
F_23 ( V_41 -> V_15 ) ;
}
if ( F_6 ( V_42 -> V_20 , V_88 ) && ! F_6 ( V_41 -> V_20 , V_88 ) )
F_23 ( V_41 -> V_15 ) ;
if ( ! F_6 ( V_42 -> V_20 , V_88 ) && F_6 ( V_41 -> V_20 , V_88 ) )
V_41 -> V_15 = V_41 -> V_31 ;
}
int F_43 ( struct V_8 * V_41 , const struct V_8 * V_42 , int V_109 )
{
switch ( V_109 ) {
case V_113 :
case V_114 :
case V_115 :
if ( ! F_33 ( V_116 ) )
F_42 ( V_41 , V_42 ) ;
break;
case V_117 :
if ( ! F_33 ( V_116 ) ) {
T_3 V_88 = F_32 ( V_42 -> V_14 , 0 ) ;
if ( F_6 ( V_42 -> V_101 , V_88 ) && ! F_6 ( V_41 -> V_101 , V_88 ) )
V_41 -> V_15 =
F_44 ( V_41 -> V_15 ) ;
if ( ! F_6 ( V_42 -> V_101 , V_88 ) && F_6 ( V_41 -> V_101 , V_88 ) )
V_41 -> V_15 =
F_45 ( V_41 -> V_15 ,
V_41 -> V_31 ) ;
}
break;
default:
return - V_67 ;
}
return 0 ;
}
static int F_46 ( struct V_26 * V_118 )
{
int V_119 , V_29 = 0 ;
F_10 () ;
V_119 = F_13 ( F_12 ( V_118 ) -> V_31 ,
F_11 () -> V_31 ) ;
if ( ! V_119 && ! F_14 ( F_12 ( V_118 ) -> V_14 , V_120 ) )
V_29 = - V_16 ;
F_15 () ;
return V_29 ;
}
int F_47 ( struct V_26 * V_118 )
{
return F_46 ( V_118 ) ;
}
int F_48 ( struct V_26 * V_118 , int V_121 )
{
return F_46 ( V_118 ) ;
}
int F_49 ( struct V_26 * V_118 , int V_122 )
{
return F_46 ( V_118 ) ;
}
static int F_50 ( unsigned long V_11 )
{
struct V_8 * V_41 ;
if ( ! F_14 ( F_51 () , V_39 ) )
return - V_16 ;
if ( ! F_52 ( V_11 ) )
return - V_67 ;
V_41 = F_53 () ;
if ( ! V_41 )
return - V_123 ;
F_54 ( V_41 -> V_43 , V_11 ) ;
return F_55 ( V_41 ) ;
}
int F_56 ( int V_124 , unsigned long V_125 , unsigned long V_126 ,
unsigned long V_127 , unsigned long V_128 )
{
const struct V_8 * V_42 = F_11 () ;
struct V_8 * V_41 ;
switch ( V_124 ) {
case V_129 :
if ( ! F_52 ( V_125 ) )
return - V_67 ;
return ! ! F_5 ( V_42 -> V_43 , V_125 ) ;
case V_130 :
return F_50 ( V_125 ) ;
case V_131 :
if ( ( ( ( V_42 -> V_105 & V_132 ) >> 1 )
& ( V_42 -> V_105 ^ V_125 ) )
|| ( ( V_42 -> V_105 & V_132 & ~ V_125 ) )
|| ( V_125 & ~ ( V_132 | V_133 ) )
|| ( F_4 ( F_11 () ,
F_11 () -> V_14 , V_39 ,
V_40 ) != 0 )
)
return - V_16 ;
V_41 = F_53 () ;
if ( ! V_41 )
return - V_123 ;
V_41 -> V_105 = V_125 ;
return F_55 ( V_41 ) ;
case V_134 :
return V_42 -> V_105 ;
case V_135 :
return ! ! F_33 ( V_106 ) ;
case V_136 :
if ( V_125 > 1 )
return - V_67 ;
if ( F_33 ( V_137 ) )
return - V_16 ;
V_41 = F_53 () ;
if ( ! V_41 )
return - V_123 ;
if ( V_125 )
V_41 -> V_105 |= F_38 ( V_106 ) ;
else
V_41 -> V_105 &= ~ F_38 ( V_106 ) ;
return F_55 ( V_41 ) ;
default:
return - V_138 ;
}
}
int F_57 ( struct V_139 * V_140 , long V_141 )
{
int V_142 = 0 ;
if ( F_4 ( F_11 () , & V_17 , V_112 ,
V_143 ) == 0 )
V_142 = 1 ;
return F_58 ( V_140 , V_141 , V_142 ) ;
}
int F_59 ( unsigned long V_144 )
{
int V_29 = 0 ;
if ( V_144 < V_145 ) {
V_29 = F_4 ( F_11 () , & V_17 , V_146 ,
V_40 ) ;
if ( V_29 == 0 )
V_147 -> V_109 |= V_148 ;
}
return V_29 ;
}
int F_60 ( struct V_80 * V_80 , unsigned long V_149 ,
unsigned long V_150 , unsigned long V_109 )
{
return 0 ;
}
