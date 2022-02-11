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
struct V_47 * V_47 = F_25 ( V_46 ) ;
int error ;
if ( ! V_47 -> V_48 -> V_49 )
return 0 ;
error = V_47 -> V_48 -> V_49 ( V_46 , V_50 , NULL , 0 ) ;
if ( error <= 0 )
return 0 ;
return 1 ;
}
int F_26 ( struct V_46 * V_46 )
{
struct V_47 * V_47 = F_25 ( V_46 ) ;
if ( ! V_47 -> V_48 -> V_51 )
return 0 ;
return V_47 -> V_48 -> V_51 ( V_46 , V_50 ) ;
}
static inline int F_27 ( struct V_52 * V_53 ,
struct V_44 * V_45 ,
bool * V_35 ,
bool * V_54 )
{
struct V_8 * V_41 = V_45 -> V_8 ;
unsigned V_55 ;
int V_29 = 0 ;
if ( V_53 -> V_56 & V_57 )
* V_35 = true ;
if ( V_53 -> V_56 & V_58 )
* V_54 = true ;
F_28 (i) {
T_2 V_37 = V_53 -> V_37 . V_11 [ V_55 ] ;
T_2 V_36 = V_53 -> V_36 . V_11 [ V_55 ] ;
V_41 -> V_31 . V_11 [ V_55 ] =
( V_41 -> V_43 . V_11 [ V_55 ] & V_37 ) |
( V_41 -> V_38 . V_11 [ V_55 ] & V_36 ) ;
if ( V_37 & ~ V_41 -> V_31 . V_11 [ V_55 ] )
V_29 = - V_16 ;
}
return * V_35 ? V_29 : 0 ;
}
int F_29 ( const struct V_46 * V_46 , struct V_52 * V_59 )
{
struct V_47 * V_47 = F_25 ( V_46 ) ;
T_2 V_56 ;
unsigned V_60 , V_55 ;
int V_61 ;
struct V_62 V_53 ;
memset ( V_59 , 0 , sizeof( struct V_52 ) ) ;
if ( ! V_47 || ! V_47 -> V_48 -> V_49 )
return - V_63 ;
V_61 = V_47 -> V_48 -> V_49 ( (struct V_46 * ) V_46 , V_50 , & V_53 ,
V_64 ) ;
if ( V_61 == - V_63 || V_61 == - V_65 )
return - V_63 ;
if ( V_61 < 0 )
return V_61 ;
if ( V_61 < sizeof( V_56 ) )
return - V_66 ;
V_59 -> V_56 = V_56 = F_30 ( V_53 . V_56 ) ;
switch ( V_56 & V_58 ) {
case V_67 :
if ( V_61 != V_68 )
return - V_66 ;
V_60 = V_69 ;
break;
case V_70 :
if ( V_61 != V_71 )
return - V_66 ;
V_60 = V_72 ;
break;
default:
return - V_66 ;
}
F_28 (i) {
if ( V_55 >= V_60 )
break;
V_59 -> V_37 . V_11 [ V_55 ] = F_30 ( V_53 . V_73 [ V_55 ] . V_37 ) ;
V_59 -> V_36 . V_11 [ V_55 ] = F_30 ( V_53 . V_73 [ V_55 ] . V_36 ) ;
}
V_59 -> V_37 . V_11 [ V_74 ] &= V_75 ;
V_59 -> V_36 . V_11 [ V_74 ] &= V_75 ;
return 0 ;
}
static int F_31 ( struct V_44 * V_45 , bool * V_35 , bool * V_54 )
{
int V_76 = 0 ;
struct V_52 V_77 ;
F_22 ( V_45 ) ;
if ( ! V_78 )
return 0 ;
if ( V_45 -> V_79 -> V_80 . V_81 -> V_82 & V_83 )
return 0 ;
V_76 = F_29 ( V_45 -> V_79 -> V_80 . V_46 , & V_77 ) ;
if ( V_76 < 0 ) {
if ( V_76 == - V_66 )
F_2 ( V_84 L_4 ,
V_85 , V_76 , V_45 -> V_86 ) ;
else if ( V_76 == - V_63 )
V_76 = 0 ;
goto V_32;
}
V_76 = F_27 ( & V_77 , V_45 , V_35 , V_54 ) ;
if ( V_76 == - V_66 )
F_2 ( V_84 L_5 ,
V_85 , V_76 , V_45 -> V_86 ) ;
V_32:
if ( V_76 )
F_22 ( V_45 ) ;
return V_76 ;
}
int F_32 ( struct V_44 * V_45 )
{
const struct V_8 * V_42 = F_11 () ;
struct V_8 * V_41 = V_45 -> V_8 ;
bool V_35 , V_54 = false ;
int V_29 ;
T_3 V_87 ;
V_35 = false ;
V_29 = F_31 ( V_45 , & V_35 , & V_54 ) ;
if ( V_29 < 0 )
return V_29 ;
V_87 = F_33 ( V_41 -> V_14 , 0 ) ;
if ( ! F_34 ( V_88 ) ) {
if ( V_54 && ! F_6 ( V_41 -> V_89 , V_87 ) && F_6 ( V_41 -> V_20 , V_87 ) ) {
F_1 ( V_45 -> V_86 ) ;
goto V_90;
}
if ( F_6 ( V_41 -> V_20 , V_87 ) || F_6 ( V_41 -> V_89 , V_87 ) ) {
V_41 -> V_31 = F_21 ( V_42 -> V_43 ,
V_42 -> V_38 ) ;
}
if ( F_6 ( V_41 -> V_20 , V_87 ) )
V_35 = true ;
}
V_90:
if ( ! F_13 ( V_41 -> V_31 , V_42 -> V_31 ) )
V_45 -> V_91 |= V_92 ;
if ( ( ! F_6 ( V_41 -> V_20 , V_42 -> V_89 ) ||
! F_35 ( V_41 -> V_93 , V_42 -> V_94 ) ||
! F_13 ( V_41 -> V_31 , V_42 -> V_31 ) ) &&
V_45 -> V_95 & ~ V_96 ) {
if ( ! F_8 ( V_97 ) ||
( V_45 -> V_95 & V_98 ) ) {
V_41 -> V_20 = V_41 -> V_89 ;
V_41 -> V_93 = V_41 -> V_94 ;
}
V_41 -> V_31 = F_36 ( V_41 -> V_31 ,
V_42 -> V_31 ) ;
}
V_41 -> V_99 = V_41 -> V_100 = V_41 -> V_20 ;
V_41 -> V_101 = V_41 -> V_102 = V_41 -> V_93 ;
if ( V_35 )
V_41 -> V_15 = V_41 -> V_31 ;
else
F_23 ( V_41 -> V_15 ) ;
V_45 -> V_15 = V_35 ;
if ( ! F_37 ( V_41 -> V_15 ) ) {
if ( ! F_13 ( V_103 , V_41 -> V_15 ) ||
! F_6 ( V_41 -> V_20 , V_87 ) || ! F_6 ( V_41 -> V_89 , V_87 ) ||
F_34 ( V_88 ) ) {
V_29 = F_38 ( V_45 , V_41 , V_42 ) ;
if ( V_29 < 0 )
return V_29 ;
}
}
V_41 -> V_104 &= ~ F_39 ( V_105 ) ;
return 0 ;
}
int F_40 ( struct V_44 * V_45 )
{
const struct V_8 * V_8 = F_11 () ;
T_3 V_87 = F_33 ( V_8 -> V_14 , 0 ) ;
if ( ! F_6 ( V_8 -> V_89 , V_87 ) ) {
if ( V_45 -> V_15 )
return 1 ;
if ( ! F_37 ( V_8 -> V_31 ) )
return 1 ;
}
return ( ! F_6 ( V_8 -> V_20 , V_8 -> V_89 ) ||
! F_35 ( V_8 -> V_93 , V_8 -> V_94 ) ) ;
}
int F_41 ( struct V_46 * V_46 , const char * V_106 ,
const void * V_107 , T_4 V_61 , int V_108 )
{
if ( ! strcmp ( V_106 , V_50 ) ) {
if ( ! F_8 ( V_109 ) )
return - V_16 ;
return 0 ;
}
if ( ! strncmp ( V_106 , V_110 ,
sizeof( V_110 ) - 1 ) &&
! F_8 ( V_111 ) )
return - V_16 ;
return 0 ;
}
int F_42 ( struct V_46 * V_46 , const char * V_106 )
{
if ( ! strcmp ( V_106 , V_50 ) ) {
if ( ! F_8 ( V_109 ) )
return - V_16 ;
return 0 ;
}
if ( ! strncmp ( V_106 , V_110 ,
sizeof( V_110 ) - 1 ) &&
! F_8 ( V_111 ) )
return - V_16 ;
return 0 ;
}
static inline void F_43 ( struct V_8 * V_41 , const struct V_8 * V_42 )
{
T_3 V_87 = F_33 ( V_42 -> V_14 , 0 ) ;
if ( ( F_6 ( V_42 -> V_89 , V_87 ) ||
F_6 ( V_42 -> V_20 , V_87 ) ||
F_6 ( V_42 -> V_99 , V_87 ) ) &&
( ! F_6 ( V_41 -> V_89 , V_87 ) &&
! F_6 ( V_41 -> V_20 , V_87 ) &&
! F_6 ( V_41 -> V_99 , V_87 ) ) &&
! F_34 ( V_105 ) ) {
F_23 ( V_41 -> V_31 ) ;
F_23 ( V_41 -> V_15 ) ;
}
if ( F_6 ( V_42 -> V_20 , V_87 ) && ! F_6 ( V_41 -> V_20 , V_87 ) )
F_23 ( V_41 -> V_15 ) ;
if ( ! F_6 ( V_42 -> V_20 , V_87 ) && F_6 ( V_41 -> V_20 , V_87 ) )
V_41 -> V_15 = V_41 -> V_31 ;
}
int F_44 ( struct V_8 * V_41 , const struct V_8 * V_42 , int V_108 )
{
switch ( V_108 ) {
case V_112 :
case V_113 :
case V_114 :
if ( ! F_34 ( V_115 ) )
F_43 ( V_41 , V_42 ) ;
break;
case V_116 :
if ( ! F_34 ( V_115 ) ) {
T_3 V_87 = F_33 ( V_42 -> V_14 , 0 ) ;
if ( F_6 ( V_42 -> V_100 , V_87 ) && ! F_6 ( V_41 -> V_100 , V_87 ) )
V_41 -> V_15 =
F_45 ( V_41 -> V_15 ) ;
if ( ! F_6 ( V_42 -> V_100 , V_87 ) && F_6 ( V_41 -> V_100 , V_87 ) )
V_41 -> V_15 =
F_46 ( V_41 -> V_15 ,
V_41 -> V_31 ) ;
}
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_47 ( struct V_26 * V_117 )
{
int V_118 , V_29 = 0 ;
F_10 () ;
V_118 = F_13 ( F_12 ( V_117 ) -> V_31 ,
F_11 () -> V_31 ) ;
if ( ! V_118 && ! F_14 ( F_12 ( V_117 ) -> V_14 , V_119 ) )
V_29 = - V_16 ;
F_15 () ;
return V_29 ;
}
int F_48 ( struct V_26 * V_117 )
{
return F_47 ( V_117 ) ;
}
int F_49 ( struct V_26 * V_117 , int V_120 )
{
return F_47 ( V_117 ) ;
}
int F_50 ( struct V_26 * V_117 , int V_121 )
{
return F_47 ( V_117 ) ;
}
static int F_51 ( unsigned long V_11 )
{
struct V_8 * V_41 ;
if ( ! F_14 ( F_52 () , V_39 ) )
return - V_16 ;
if ( ! F_53 ( V_11 ) )
return - V_66 ;
V_41 = F_54 () ;
if ( ! V_41 )
return - V_122 ;
F_55 ( V_41 -> V_43 , V_11 ) ;
return F_56 ( V_41 ) ;
}
int F_57 ( int V_123 , unsigned long V_124 , unsigned long V_125 ,
unsigned long V_126 , unsigned long V_127 )
{
const struct V_8 * V_42 = F_11 () ;
struct V_8 * V_41 ;
switch ( V_123 ) {
case V_128 :
if ( ! F_53 ( V_124 ) )
return - V_66 ;
return ! ! F_5 ( V_42 -> V_43 , V_124 ) ;
case V_129 :
return F_51 ( V_124 ) ;
case V_130 :
if ( ( ( ( V_42 -> V_104 & V_131 ) >> 1 )
& ( V_42 -> V_104 ^ V_124 ) )
|| ( ( V_42 -> V_104 & V_131 & ~ V_124 ) )
|| ( V_124 & ~ ( V_131 | V_132 ) )
|| ( F_4 ( F_11 () ,
F_11 () -> V_14 , V_39 ,
V_40 ) != 0 )
)
return - V_16 ;
V_41 = F_54 () ;
if ( ! V_41 )
return - V_122 ;
V_41 -> V_104 = V_124 ;
return F_56 ( V_41 ) ;
case V_133 :
return V_42 -> V_104 ;
case V_134 :
return ! ! F_34 ( V_105 ) ;
case V_135 :
if ( V_124 > 1 )
return - V_66 ;
if ( F_34 ( V_136 ) )
return - V_16 ;
V_41 = F_54 () ;
if ( ! V_41 )
return - V_122 ;
if ( V_124 )
V_41 -> V_104 |= F_39 ( V_105 ) ;
else
V_41 -> V_104 &= ~ F_39 ( V_105 ) ;
return F_56 ( V_41 ) ;
default:
return - V_137 ;
}
}
int F_58 ( struct V_138 * V_139 , long V_140 )
{
int V_141 = 0 ;
if ( F_4 ( F_11 () , & V_17 , V_111 ,
V_142 ) == 0 )
V_141 = 1 ;
return F_59 ( V_139 , V_140 , V_141 ) ;
}
int F_60 ( unsigned long V_143 )
{
int V_29 = 0 ;
if ( V_143 < V_144 ) {
V_29 = F_4 ( F_11 () , & V_17 , V_145 ,
V_40 ) ;
if ( V_29 == 0 )
V_146 -> V_108 |= V_147 ;
}
return V_29 ;
}
int F_61 ( struct V_79 * V_79 , unsigned long V_148 ,
unsigned long V_149 , unsigned long V_108 )
{
return 0 ;
}
