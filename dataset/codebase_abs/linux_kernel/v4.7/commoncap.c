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
if ( V_9 == & V_13 )
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
static inline void F_24 ( struct V_44 * V_45 )
{
F_25 ( V_45 -> V_4 -> V_29 ) ;
V_45 -> V_11 = false ;
}
int F_26 ( struct V_46 * V_46 )
{
struct V_47 * V_47 = F_27 ( V_46 ) ;
int error ;
if ( ! V_47 -> V_48 -> V_49 )
return 0 ;
error = V_47 -> V_48 -> V_49 ( V_46 , V_47 , V_50 , NULL , 0 ) ;
if ( error <= 0 )
return 0 ;
return 1 ;
}
int F_28 ( struct V_46 * V_46 )
{
struct V_47 * V_47 = F_27 ( V_46 ) ;
if ( ! V_47 -> V_48 -> V_51 )
return 0 ;
return V_47 -> V_48 -> V_51 ( V_46 , V_50 ) ;
}
static inline int F_29 ( struct V_52 * V_53 ,
struct V_44 * V_45 ,
bool * V_33 ,
bool * V_54 )
{
struct V_4 * V_39 = V_45 -> V_4 ;
unsigned V_55 ;
int V_25 = 0 ;
if ( V_53 -> V_56 & V_57 )
* V_33 = true ;
if ( V_53 -> V_56 & V_58 )
* V_54 = true ;
F_30 (i) {
T_2 V_35 = V_53 -> V_35 . V_7 [ V_55 ] ;
T_2 V_34 = V_53 -> V_34 . V_7 [ V_55 ] ;
V_39 -> V_29 . V_7 [ V_55 ] =
( V_39 -> V_41 . V_7 [ V_55 ] & V_35 ) |
( V_39 -> V_36 . V_7 [ V_55 ] & V_34 ) ;
if ( V_35 & ~ V_39 -> V_29 . V_7 [ V_55 ] )
V_25 = - V_12 ;
}
return * V_33 ? V_25 : 0 ;
}
int F_31 ( const struct V_46 * V_46 , struct V_52 * V_59 )
{
struct V_47 * V_47 = F_27 ( V_46 ) ;
T_2 V_56 ;
unsigned V_60 , V_55 ;
int V_61 ;
struct V_62 V_53 ;
memset ( V_59 , 0 , sizeof( struct V_52 ) ) ;
if ( ! V_47 || ! V_47 -> V_48 -> V_49 )
return - V_63 ;
V_61 = V_47 -> V_48 -> V_49 ( (struct V_46 * ) V_46 , V_47 ,
V_50 , & V_53 , V_64 ) ;
if ( V_61 == - V_63 || V_61 == - V_65 )
return - V_63 ;
if ( V_61 < 0 )
return V_61 ;
if ( V_61 < sizeof( V_56 ) )
return - V_43 ;
V_59 -> V_56 = V_56 = F_32 ( V_53 . V_56 ) ;
switch ( V_56 & V_58 ) {
case V_66 :
if ( V_61 != V_67 )
return - V_43 ;
V_60 = V_68 ;
break;
case V_69 :
if ( V_61 != V_70 )
return - V_43 ;
V_60 = V_71 ;
break;
default:
return - V_43 ;
}
F_30 (i) {
if ( V_55 >= V_60 )
break;
V_59 -> V_35 . V_7 [ V_55 ] = F_32 ( V_53 . V_72 [ V_55 ] . V_35 ) ;
V_59 -> V_34 . V_7 [ V_55 ] = F_32 ( V_53 . V_72 [ V_55 ] . V_34 ) ;
}
V_59 -> V_35 . V_7 [ V_73 ] &= V_74 ;
V_59 -> V_34 . V_7 [ V_73 ] &= V_74 ;
return 0 ;
}
static int F_33 ( struct V_44 * V_45 , bool * V_33 , bool * V_54 )
{
int V_75 = 0 ;
struct V_52 V_76 ;
F_24 ( V_45 ) ;
if ( ! V_77 )
return 0 ;
if ( V_45 -> V_78 -> V_79 . V_80 -> V_81 & V_82 )
return 0 ;
V_75 = F_31 ( V_45 -> V_78 -> V_79 . V_46 , & V_76 ) ;
if ( V_75 < 0 ) {
if ( V_75 == - V_43 )
F_2 ( V_83 L_4 ,
V_84 , V_75 , V_45 -> V_85 ) ;
else if ( V_75 == - V_63 )
V_75 = 0 ;
goto V_30;
}
V_75 = F_29 ( & V_76 , V_45 , V_33 , V_54 ) ;
if ( V_75 == - V_43 )
F_2 ( V_83 L_5 ,
V_84 , V_75 , V_45 -> V_85 ) ;
V_30:
if ( V_75 )
F_24 ( V_45 ) ;
return V_75 ;
}
int F_34 ( struct V_44 * V_45 )
{
const struct V_4 * V_40 = F_10 () ;
struct V_4 * V_39 = V_45 -> V_4 ;
bool V_33 , V_54 = false , V_86 ;
int V_25 ;
T_3 V_87 ;
if ( F_22 ( ! F_23 ( V_40 ) ) )
return - V_12 ;
V_33 = false ;
V_25 = F_33 ( V_45 , & V_33 , & V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
V_87 = F_35 ( V_39 -> V_10 , 0 ) ;
if ( ! F_36 ( V_88 ) ) {
if ( V_54 && ! F_5 ( V_39 -> V_89 , V_87 ) && F_5 ( V_39 -> V_16 , V_87 ) ) {
F_1 ( V_45 -> V_85 ) ;
goto V_90;
}
if ( F_5 ( V_39 -> V_16 , V_87 ) || F_5 ( V_39 -> V_89 , V_87 ) ) {
V_39 -> V_29 = F_20 ( V_40 -> V_41 ,
V_40 -> V_36 ) ;
}
if ( F_5 ( V_39 -> V_16 , V_87 ) )
V_33 = true ;
}
V_90:
if ( ! F_12 ( V_39 -> V_29 , V_40 -> V_29 ) )
V_45 -> V_91 |= V_92 ;
V_86 = ! F_5 ( V_39 -> V_16 , V_40 -> V_89 ) || ! F_37 ( V_39 -> V_93 , V_40 -> V_94 ) ;
if ( ( V_86 ||
! F_12 ( V_39 -> V_29 , V_40 -> V_29 ) ) &&
V_45 -> V_95 & ~ V_96 ) {
if ( ! F_7 ( V_97 ) ||
( V_45 -> V_95 & V_98 ) ) {
V_39 -> V_16 = V_39 -> V_89 ;
V_39 -> V_93 = V_39 -> V_94 ;
}
V_39 -> V_29 = F_21 ( V_39 -> V_29 ,
V_40 -> V_29 ) ;
}
V_39 -> V_99 = V_39 -> V_100 = V_39 -> V_16 ;
V_39 -> V_101 = V_39 -> V_102 = V_39 -> V_93 ;
if ( V_54 || V_86 )
F_25 ( V_39 -> V_42 ) ;
V_39 -> V_29 = F_20 ( V_39 -> V_29 , V_39 -> V_42 ) ;
if ( V_33 )
V_39 -> V_11 = V_39 -> V_29 ;
else
V_39 -> V_11 = V_39 -> V_42 ;
if ( F_22 ( ! F_23 ( V_39 ) ) )
return - V_12 ;
V_45 -> V_11 = V_33 ;
if ( ! F_12 ( V_39 -> V_11 , V_39 -> V_42 ) ) {
if ( ! F_12 ( V_103 , V_39 -> V_11 ) ||
! F_5 ( V_39 -> V_16 , V_87 ) || ! F_5 ( V_39 -> V_89 , V_87 ) ||
F_36 ( V_88 ) ) {
V_25 = F_38 ( V_45 , V_39 , V_40 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
V_39 -> V_104 &= ~ F_39 ( V_105 ) ;
if ( F_22 ( ! F_23 ( V_39 ) ) )
return - V_12 ;
return 0 ;
}
int F_40 ( struct V_44 * V_45 )
{
const struct V_4 * V_4 = F_10 () ;
T_3 V_87 = F_35 ( V_4 -> V_10 , 0 ) ;
if ( ! F_5 ( V_4 -> V_89 , V_87 ) ) {
if ( V_45 -> V_11 )
return 1 ;
if ( ! F_12 ( V_4 -> V_29 , V_4 -> V_42 ) )
return 1 ;
}
return ( ! F_5 ( V_4 -> V_16 , V_4 -> V_89 ) ||
! F_37 ( V_4 -> V_93 , V_4 -> V_94 ) ) ;
}
int F_41 ( struct V_46 * V_46 , const char * V_106 ,
const void * V_107 , T_4 V_61 , int V_108 )
{
if ( ! strcmp ( V_106 , V_50 ) ) {
if ( ! F_7 ( V_109 ) )
return - V_12 ;
return 0 ;
}
if ( ! strncmp ( V_106 , V_110 ,
sizeof( V_110 ) - 1 ) &&
! F_7 ( V_111 ) )
return - V_12 ;
return 0 ;
}
int F_42 ( struct V_46 * V_46 , const char * V_106 )
{
if ( ! strcmp ( V_106 , V_50 ) ) {
if ( ! F_7 ( V_109 ) )
return - V_12 ;
return 0 ;
}
if ( ! strncmp ( V_106 , V_110 ,
sizeof( V_110 ) - 1 ) &&
! F_7 ( V_111 ) )
return - V_12 ;
return 0 ;
}
static inline void F_43 ( struct V_4 * V_39 , const struct V_4 * V_40 )
{
T_3 V_87 = F_35 ( V_40 -> V_10 , 0 ) ;
if ( ( F_5 ( V_40 -> V_89 , V_87 ) ||
F_5 ( V_40 -> V_16 , V_87 ) ||
F_5 ( V_40 -> V_99 , V_87 ) ) &&
( ! F_5 ( V_39 -> V_89 , V_87 ) &&
! F_5 ( V_39 -> V_16 , V_87 ) &&
! F_5 ( V_39 -> V_99 , V_87 ) ) ) {
if ( ! F_36 ( V_105 ) ) {
F_25 ( V_39 -> V_29 ) ;
F_25 ( V_39 -> V_11 ) ;
}
F_25 ( V_39 -> V_42 ) ;
}
if ( F_5 ( V_40 -> V_16 , V_87 ) && ! F_5 ( V_39 -> V_16 , V_87 ) )
F_25 ( V_39 -> V_11 ) ;
if ( ! F_5 ( V_40 -> V_16 , V_87 ) && F_5 ( V_39 -> V_16 , V_87 ) )
V_39 -> V_11 = V_39 -> V_29 ;
}
int F_44 ( struct V_4 * V_39 , const struct V_4 * V_40 , int V_108 )
{
switch ( V_108 ) {
case V_112 :
case V_113 :
case V_114 :
if ( ! F_36 ( V_115 ) )
F_43 ( V_39 , V_40 ) ;
break;
case V_116 :
if ( ! F_36 ( V_115 ) ) {
T_3 V_87 = F_35 ( V_40 -> V_10 , 0 ) ;
if ( F_5 ( V_40 -> V_100 , V_87 ) && ! F_5 ( V_39 -> V_100 , V_87 ) )
V_39 -> V_11 =
F_45 ( V_39 -> V_11 ) ;
if ( ! F_5 ( V_40 -> V_100 , V_87 ) && F_5 ( V_39 -> V_100 , V_87 ) )
V_39 -> V_11 =
F_46 ( V_39 -> V_11 ,
V_39 -> V_29 ) ;
}
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_47 ( struct V_22 * V_117 )
{
int V_118 , V_25 = 0 ;
F_9 () ;
V_118 = F_12 ( F_11 ( V_117 ) -> V_29 ,
F_10 () -> V_29 ) ;
if ( ! V_118 && ! F_13 ( F_11 ( V_117 ) -> V_10 , V_119 ) )
V_25 = - V_12 ;
F_14 () ;
return V_25 ;
}
int F_48 ( struct V_22 * V_117 )
{
return F_47 ( V_117 ) ;
}
int F_49 ( struct V_22 * V_117 , int V_120 )
{
return F_47 ( V_117 ) ;
}
int F_50 ( struct V_22 * V_117 , int V_121 )
{
return F_47 ( V_117 ) ;
}
static int F_51 ( unsigned long V_7 )
{
struct V_4 * V_39 ;
if ( ! F_13 ( F_52 () , V_37 ) )
return - V_12 ;
if ( ! F_53 ( V_7 ) )
return - V_43 ;
V_39 = F_54 () ;
if ( ! V_39 )
return - V_122 ;
F_55 ( V_39 -> V_41 , V_7 ) ;
return F_56 ( V_39 ) ;
}
int F_57 ( int V_123 , unsigned long V_124 , unsigned long V_125 ,
unsigned long V_126 , unsigned long V_127 )
{
const struct V_4 * V_40 = F_10 () ;
struct V_4 * V_39 ;
switch ( V_123 ) {
case V_128 :
if ( ! F_53 ( V_124 ) )
return - V_43 ;
return ! ! F_4 ( V_40 -> V_41 , V_124 ) ;
case V_129 :
return F_51 ( V_124 ) ;
case V_130 :
if ( ( ( ( V_40 -> V_104 & V_131 ) >> 1 )
& ( V_40 -> V_104 ^ V_124 ) )
|| ( ( V_40 -> V_104 & V_131 & ~ V_124 ) )
|| ( V_124 & ~ ( V_131 | V_132 ) )
|| ( F_3 ( F_10 () ,
F_10 () -> V_10 , V_37 ,
V_38 ) != 0 )
)
return - V_12 ;
V_39 = F_54 () ;
if ( ! V_39 )
return - V_122 ;
V_39 -> V_104 = V_124 ;
return F_56 ( V_39 ) ;
case V_133 :
return V_40 -> V_104 ;
case V_134 :
return ! ! F_36 ( V_105 ) ;
case V_135 :
if ( V_124 > 1 )
return - V_43 ;
if ( F_36 ( V_136 ) )
return - V_12 ;
V_39 = F_54 () ;
if ( ! V_39 )
return - V_122 ;
if ( V_124 )
V_39 -> V_104 |= F_39 ( V_105 ) ;
else
V_39 -> V_104 &= ~ F_39 ( V_105 ) ;
return F_56 ( V_39 ) ;
case V_137 :
if ( V_124 == V_138 ) {
if ( V_125 | V_126 | V_127 )
return - V_43 ;
V_39 = F_54 () ;
if ( ! V_39 )
return - V_122 ;
F_25 ( V_39 -> V_42 ) ;
return F_56 ( V_39 ) ;
}
if ( ( ( ! F_53 ( V_125 ) ) | V_126 | V_127 ) )
return - V_43 ;
if ( V_124 == V_139 ) {
return ! ! F_4 ( F_10 () -> V_42 , V_125 ) ;
} else if ( V_124 != V_140 &&
V_124 != V_141 ) {
return - V_43 ;
} else {
if ( V_124 == V_140 &&
( ! F_4 ( F_10 () -> V_29 , V_125 ) ||
! F_4 ( F_10 () -> V_36 ,
V_125 ) ||
F_36 ( V_142 ) ) )
return - V_12 ;
V_39 = F_54 () ;
if ( ! V_39 )
return - V_122 ;
if ( V_124 == V_140 )
F_58 ( V_39 -> V_42 , V_125 ) ;
else
F_55 ( V_39 -> V_42 , V_125 ) ;
return F_56 ( V_39 ) ;
}
default:
return - V_143 ;
}
}
int F_59 ( struct V_144 * V_145 , long V_146 )
{
int V_147 = 0 ;
if ( F_3 ( F_10 () , & V_13 , V_111 ,
V_148 ) == 0 )
V_147 = 1 ;
return V_147 ;
}
int F_60 ( unsigned long V_149 )
{
int V_25 = 0 ;
if ( V_149 < V_150 ) {
V_25 = F_3 ( F_10 () , & V_13 , V_151 ,
V_38 ) ;
if ( V_25 == 0 )
V_152 -> V_108 |= V_153 ;
}
return V_25 ;
}
int F_61 ( struct V_78 * V_78 , unsigned long V_154 ,
unsigned long V_155 , unsigned long V_108 )
{
return 0 ;
}
void T_5 F_62 ( void )
{
F_63 ( V_156 , F_64 ( V_156 ) ) ;
}
