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
F_9 () ;
V_4 = F_10 () ;
V_26 = F_11 ( V_23 ) ;
if ( V_4 -> V_10 == V_26 -> V_10 &&
F_12 ( V_26 -> V_27 , V_4 -> V_27 ) )
goto V_28;
if ( F_13 ( V_26 -> V_10 , V_29 ) )
goto V_28;
V_25 = - V_12 ;
V_28:
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
F_12 ( V_26 -> V_27 , V_4 -> V_27 ) )
goto V_28;
if ( F_16 ( V_14 , V_26 -> V_10 , V_29 ) )
goto V_28;
V_25 = - V_12 ;
V_28:
F_14 () ;
return V_25 ;
}
int F_17 ( struct V_22 * V_30 , T_1 * V_31 ,
T_1 * V_32 , T_1 * V_33 )
{
const struct V_4 * V_4 ;
F_9 () ;
V_4 = F_11 ( V_30 ) ;
* V_31 = V_4 -> V_11 ;
* V_32 = V_4 -> V_34 ;
* V_33 = V_4 -> V_27 ;
F_14 () ;
return 0 ;
}
static inline int F_18 ( void )
{
if ( F_3 ( F_10 () , F_10 () -> V_10 ,
V_35 , V_36 ) == 0 )
return 0 ;
return 1 ;
}
int F_19 ( struct V_4 * V_37 ,
const struct V_4 * V_38 ,
const T_1 * V_31 ,
const T_1 * V_32 ,
const T_1 * V_33 )
{
if ( F_18 () &&
! F_12 ( * V_32 ,
F_20 ( V_38 -> V_34 ,
V_38 -> V_27 ) ) )
return - V_12 ;
if ( ! F_12 ( * V_32 ,
F_20 ( V_38 -> V_34 ,
V_38 -> V_39 ) ) )
return - V_12 ;
if ( ! F_12 ( * V_33 , V_38 -> V_27 ) )
return - V_12 ;
if ( ! F_12 ( * V_31 , * V_33 ) )
return - V_12 ;
V_37 -> V_11 = * V_31 ;
V_37 -> V_34 = * V_32 ;
V_37 -> V_27 = * V_33 ;
V_37 -> V_40 = F_21 ( V_37 -> V_40 ,
F_21 ( * V_33 ,
* V_32 ) ) ;
if ( F_22 ( ! F_23 ( V_37 ) ) )
return - V_41 ;
return 0 ;
}
static inline void F_24 ( struct V_42 * V_43 )
{
F_25 ( V_43 -> V_4 -> V_27 ) ;
V_43 -> V_11 = false ;
}
int F_26 ( struct V_44 * V_44 )
{
struct V_45 * V_45 = F_27 ( V_44 ) ;
int error ;
if ( ! V_45 -> V_46 -> V_47 )
return 0 ;
error = V_45 -> V_46 -> V_47 ( V_44 , V_48 , NULL , 0 ) ;
if ( error <= 0 )
return 0 ;
return 1 ;
}
int F_28 ( struct V_44 * V_44 )
{
struct V_45 * V_45 = F_27 ( V_44 ) ;
if ( ! V_45 -> V_46 -> V_49 )
return 0 ;
return V_45 -> V_46 -> V_49 ( V_44 , V_48 ) ;
}
static inline int F_29 ( struct V_50 * V_51 ,
struct V_42 * V_43 ,
bool * V_31 ,
bool * V_52 )
{
struct V_4 * V_37 = V_43 -> V_4 ;
unsigned V_53 ;
int V_25 = 0 ;
if ( V_51 -> V_54 & V_55 )
* V_31 = true ;
if ( V_51 -> V_54 & V_56 )
* V_52 = true ;
F_30 (i) {
T_2 V_33 = V_51 -> V_33 . V_7 [ V_53 ] ;
T_2 V_32 = V_51 -> V_32 . V_7 [ V_53 ] ;
V_37 -> V_27 . V_7 [ V_53 ] =
( V_37 -> V_39 . V_7 [ V_53 ] & V_33 ) |
( V_37 -> V_34 . V_7 [ V_53 ] & V_32 ) ;
if ( V_33 & ~ V_37 -> V_27 . V_7 [ V_53 ] )
V_25 = - V_12 ;
}
return * V_31 ? V_25 : 0 ;
}
int F_31 ( const struct V_44 * V_44 , struct V_50 * V_57 )
{
struct V_45 * V_45 = F_27 ( V_44 ) ;
T_2 V_54 ;
unsigned V_58 , V_53 ;
int V_59 ;
struct V_60 V_51 ;
memset ( V_57 , 0 , sizeof( struct V_50 ) ) ;
if ( ! V_45 || ! V_45 -> V_46 -> V_47 )
return - V_61 ;
V_59 = V_45 -> V_46 -> V_47 ( (struct V_44 * ) V_44 , V_48 , & V_51 ,
V_62 ) ;
if ( V_59 == - V_61 || V_59 == - V_63 )
return - V_61 ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 < sizeof( V_54 ) )
return - V_41 ;
V_57 -> V_54 = V_54 = F_32 ( V_51 . V_54 ) ;
switch ( V_54 & V_56 ) {
case V_64 :
if ( V_59 != V_65 )
return - V_41 ;
V_58 = V_66 ;
break;
case V_67 :
if ( V_59 != V_68 )
return - V_41 ;
V_58 = V_69 ;
break;
default:
return - V_41 ;
}
F_30 (i) {
if ( V_53 >= V_58 )
break;
V_57 -> V_33 . V_7 [ V_53 ] = F_32 ( V_51 . V_70 [ V_53 ] . V_33 ) ;
V_57 -> V_32 . V_7 [ V_53 ] = F_32 ( V_51 . V_70 [ V_53 ] . V_32 ) ;
}
V_57 -> V_33 . V_7 [ V_71 ] &= V_72 ;
V_57 -> V_32 . V_7 [ V_71 ] &= V_72 ;
return 0 ;
}
static int F_33 ( struct V_42 * V_43 , bool * V_31 , bool * V_52 )
{
int V_73 = 0 ;
struct V_50 V_74 ;
F_24 ( V_43 ) ;
if ( ! V_75 )
return 0 ;
if ( V_43 -> V_76 -> V_77 . V_78 -> V_79 & V_80 )
return 0 ;
V_73 = F_31 ( V_43 -> V_76 -> V_77 . V_44 , & V_74 ) ;
if ( V_73 < 0 ) {
if ( V_73 == - V_41 )
F_2 ( V_81 L_4 ,
V_82 , V_73 , V_43 -> V_83 ) ;
else if ( V_73 == - V_61 )
V_73 = 0 ;
goto V_28;
}
V_73 = F_29 ( & V_74 , V_43 , V_31 , V_52 ) ;
if ( V_73 == - V_41 )
F_2 ( V_81 L_5 ,
V_82 , V_73 , V_43 -> V_83 ) ;
V_28:
if ( V_73 )
F_24 ( V_43 ) ;
return V_73 ;
}
int F_34 ( struct V_42 * V_43 )
{
const struct V_4 * V_38 = F_10 () ;
struct V_4 * V_37 = V_43 -> V_4 ;
bool V_31 , V_52 = false , V_84 ;
int V_25 ;
T_3 V_85 ;
if ( F_22 ( ! F_23 ( V_38 ) ) )
return - V_12 ;
V_31 = false ;
V_25 = F_33 ( V_43 , & V_31 , & V_52 ) ;
if ( V_25 < 0 )
return V_25 ;
V_85 = F_35 ( V_37 -> V_10 , 0 ) ;
if ( ! F_36 ( V_86 ) ) {
if ( V_52 && ! F_5 ( V_37 -> V_87 , V_85 ) && F_5 ( V_37 -> V_16 , V_85 ) ) {
F_1 ( V_43 -> V_83 ) ;
goto V_88;
}
if ( F_5 ( V_37 -> V_16 , V_85 ) || F_5 ( V_37 -> V_87 , V_85 ) ) {
V_37 -> V_27 = F_20 ( V_38 -> V_39 ,
V_38 -> V_34 ) ;
}
if ( F_5 ( V_37 -> V_16 , V_85 ) )
V_31 = true ;
}
V_88:
if ( ! F_12 ( V_37 -> V_27 , V_38 -> V_27 ) )
V_43 -> V_89 |= V_90 ;
V_84 = ! F_5 ( V_37 -> V_16 , V_38 -> V_87 ) || ! F_37 ( V_37 -> V_91 , V_38 -> V_92 ) ;
if ( ( V_84 ||
! F_12 ( V_37 -> V_27 , V_38 -> V_27 ) ) &&
V_43 -> V_93 & ~ V_94 ) {
if ( ! F_7 ( V_95 ) ||
( V_43 -> V_93 & V_96 ) ) {
V_37 -> V_16 = V_37 -> V_87 ;
V_37 -> V_91 = V_37 -> V_92 ;
}
V_37 -> V_27 = F_21 ( V_37 -> V_27 ,
V_38 -> V_27 ) ;
}
V_37 -> V_97 = V_37 -> V_98 = V_37 -> V_16 ;
V_37 -> V_99 = V_37 -> V_100 = V_37 -> V_91 ;
if ( V_52 || V_84 )
F_25 ( V_37 -> V_40 ) ;
V_37 -> V_27 = F_20 ( V_37 -> V_27 , V_37 -> V_40 ) ;
if ( V_31 )
V_37 -> V_11 = V_37 -> V_27 ;
else
V_37 -> V_11 = V_37 -> V_40 ;
if ( F_22 ( ! F_23 ( V_37 ) ) )
return - V_12 ;
V_43 -> V_11 = V_31 ;
if ( ! F_12 ( V_37 -> V_11 , V_37 -> V_40 ) ) {
if ( ! F_12 ( V_101 , V_37 -> V_11 ) ||
! F_5 ( V_37 -> V_16 , V_85 ) || ! F_5 ( V_37 -> V_87 , V_85 ) ||
F_36 ( V_86 ) ) {
V_25 = F_38 ( V_43 , V_37 , V_38 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
V_37 -> V_102 &= ~ F_39 ( V_103 ) ;
if ( F_22 ( ! F_23 ( V_37 ) ) )
return - V_12 ;
return 0 ;
}
int F_40 ( struct V_42 * V_43 )
{
const struct V_4 * V_4 = F_10 () ;
T_3 V_85 = F_35 ( V_4 -> V_10 , 0 ) ;
if ( ! F_5 ( V_4 -> V_87 , V_85 ) ) {
if ( V_43 -> V_11 )
return 1 ;
if ( ! F_12 ( V_4 -> V_27 , V_4 -> V_40 ) )
return 1 ;
}
return ( ! F_5 ( V_4 -> V_16 , V_4 -> V_87 ) ||
! F_37 ( V_4 -> V_91 , V_4 -> V_92 ) ) ;
}
int F_41 ( struct V_44 * V_44 , const char * V_104 ,
const void * V_105 , T_4 V_59 , int V_106 )
{
if ( ! strcmp ( V_104 , V_48 ) ) {
if ( ! F_7 ( V_107 ) )
return - V_12 ;
return 0 ;
}
if ( ! strncmp ( V_104 , V_108 ,
sizeof( V_108 ) - 1 ) &&
! F_7 ( V_109 ) )
return - V_12 ;
return 0 ;
}
int F_42 ( struct V_44 * V_44 , const char * V_104 )
{
if ( ! strcmp ( V_104 , V_48 ) ) {
if ( ! F_7 ( V_107 ) )
return - V_12 ;
return 0 ;
}
if ( ! strncmp ( V_104 , V_108 ,
sizeof( V_108 ) - 1 ) &&
! F_7 ( V_109 ) )
return - V_12 ;
return 0 ;
}
static inline void F_43 ( struct V_4 * V_37 , const struct V_4 * V_38 )
{
T_3 V_85 = F_35 ( V_38 -> V_10 , 0 ) ;
if ( ( F_5 ( V_38 -> V_87 , V_85 ) ||
F_5 ( V_38 -> V_16 , V_85 ) ||
F_5 ( V_38 -> V_97 , V_85 ) ) &&
( ! F_5 ( V_37 -> V_87 , V_85 ) &&
! F_5 ( V_37 -> V_16 , V_85 ) &&
! F_5 ( V_37 -> V_97 , V_85 ) ) ) {
if ( ! F_36 ( V_103 ) ) {
F_25 ( V_37 -> V_27 ) ;
F_25 ( V_37 -> V_11 ) ;
}
F_25 ( V_37 -> V_40 ) ;
}
if ( F_5 ( V_38 -> V_16 , V_85 ) && ! F_5 ( V_37 -> V_16 , V_85 ) )
F_25 ( V_37 -> V_11 ) ;
if ( ! F_5 ( V_38 -> V_16 , V_85 ) && F_5 ( V_37 -> V_16 , V_85 ) )
V_37 -> V_11 = V_37 -> V_27 ;
}
int F_44 ( struct V_4 * V_37 , const struct V_4 * V_38 , int V_106 )
{
switch ( V_106 ) {
case V_110 :
case V_111 :
case V_112 :
if ( ! F_36 ( V_113 ) )
F_43 ( V_37 , V_38 ) ;
break;
case V_114 :
if ( ! F_36 ( V_113 ) ) {
T_3 V_85 = F_35 ( V_38 -> V_10 , 0 ) ;
if ( F_5 ( V_38 -> V_98 , V_85 ) && ! F_5 ( V_37 -> V_98 , V_85 ) )
V_37 -> V_11 =
F_45 ( V_37 -> V_11 ) ;
if ( ! F_5 ( V_38 -> V_98 , V_85 ) && F_5 ( V_37 -> V_98 , V_85 ) )
V_37 -> V_11 =
F_46 ( V_37 -> V_11 ,
V_37 -> V_27 ) ;
}
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_47 ( struct V_22 * V_115 )
{
int V_116 , V_25 = 0 ;
F_9 () ;
V_116 = F_12 ( F_11 ( V_115 ) -> V_27 ,
F_10 () -> V_27 ) ;
if ( ! V_116 && ! F_13 ( F_11 ( V_115 ) -> V_10 , V_117 ) )
V_25 = - V_12 ;
F_14 () ;
return V_25 ;
}
int F_48 ( struct V_22 * V_115 )
{
return F_47 ( V_115 ) ;
}
int F_49 ( struct V_22 * V_115 , int V_118 )
{
return F_47 ( V_115 ) ;
}
int F_50 ( struct V_22 * V_115 , int V_119 )
{
return F_47 ( V_115 ) ;
}
static int F_51 ( unsigned long V_7 )
{
struct V_4 * V_37 ;
if ( ! F_13 ( F_52 () , V_35 ) )
return - V_12 ;
if ( ! F_53 ( V_7 ) )
return - V_41 ;
V_37 = F_54 () ;
if ( ! V_37 )
return - V_120 ;
F_55 ( V_37 -> V_39 , V_7 ) ;
return F_56 ( V_37 ) ;
}
int F_57 ( int V_121 , unsigned long V_122 , unsigned long V_123 ,
unsigned long V_124 , unsigned long V_125 )
{
const struct V_4 * V_38 = F_10 () ;
struct V_4 * V_37 ;
switch ( V_121 ) {
case V_126 :
if ( ! F_53 ( V_122 ) )
return - V_41 ;
return ! ! F_4 ( V_38 -> V_39 , V_122 ) ;
case V_127 :
return F_51 ( V_122 ) ;
case V_128 :
if ( ( ( ( V_38 -> V_102 & V_129 ) >> 1 )
& ( V_38 -> V_102 ^ V_122 ) )
|| ( ( V_38 -> V_102 & V_129 & ~ V_122 ) )
|| ( V_122 & ~ ( V_129 | V_130 ) )
|| ( F_3 ( F_10 () ,
F_10 () -> V_10 , V_35 ,
V_36 ) != 0 )
)
return - V_12 ;
V_37 = F_54 () ;
if ( ! V_37 )
return - V_120 ;
V_37 -> V_102 = V_122 ;
return F_56 ( V_37 ) ;
case V_131 :
return V_38 -> V_102 ;
case V_132 :
return ! ! F_36 ( V_103 ) ;
case V_133 :
if ( V_122 > 1 )
return - V_41 ;
if ( F_36 ( V_134 ) )
return - V_12 ;
V_37 = F_54 () ;
if ( ! V_37 )
return - V_120 ;
if ( V_122 )
V_37 -> V_102 |= F_39 ( V_103 ) ;
else
V_37 -> V_102 &= ~ F_39 ( V_103 ) ;
return F_56 ( V_37 ) ;
case V_135 :
if ( V_122 == V_136 ) {
if ( V_123 | V_124 | V_125 )
return - V_41 ;
V_37 = F_54 () ;
if ( ! V_37 )
return - V_120 ;
F_25 ( V_37 -> V_40 ) ;
return F_56 ( V_37 ) ;
}
if ( ( ( ! F_53 ( V_123 ) ) | V_124 | V_125 ) )
return - V_41 ;
if ( V_122 == V_137 ) {
return ! ! F_4 ( F_10 () -> V_40 , V_123 ) ;
} else if ( V_122 != V_138 &&
V_122 != V_139 ) {
return - V_41 ;
} else {
if ( V_122 == V_138 &&
( ! F_4 ( F_10 () -> V_27 , V_123 ) ||
! F_4 ( F_10 () -> V_34 ,
V_123 ) ||
F_36 ( V_140 ) ) )
return - V_12 ;
V_37 = F_54 () ;
if ( ! V_37 )
return - V_120 ;
if ( V_122 == V_138 )
F_58 ( V_37 -> V_40 , V_123 ) ;
else
F_55 ( V_37 -> V_40 , V_123 ) ;
return F_56 ( V_37 ) ;
}
default:
return - V_141 ;
}
}
int F_59 ( struct V_142 * V_143 , long V_144 )
{
int V_145 = 0 ;
if ( F_3 ( F_10 () , & V_13 , V_109 ,
V_146 ) == 0 )
V_145 = 1 ;
return V_145 ;
}
int F_60 ( unsigned long V_147 )
{
int V_25 = 0 ;
if ( V_147 < V_148 ) {
V_25 = F_3 ( F_10 () , & V_13 , V_149 ,
V_36 ) ;
if ( V_25 == 0 )
V_150 -> V_106 |= V_151 ;
}
return V_25 ;
}
int F_61 ( struct V_76 * V_76 , unsigned long V_152 ,
unsigned long V_153 , unsigned long V_106 )
{
return 0 ;
}
void T_5 F_62 ( void )
{
F_63 ( V_154 , F_64 ( V_154 ) ) ;
}
