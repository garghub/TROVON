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
error = F_28 ( V_46 , V_47 , V_48 , NULL , 0 ) ;
return error > 0 ;
}
int F_29 ( struct V_46 * V_46 )
{
int error ;
error = F_30 ( V_46 , V_48 ) ;
if ( error == - V_49 )
error = 0 ;
return error ;
}
static inline int F_31 ( struct V_50 * V_51 ,
struct V_44 * V_45 ,
bool * V_33 ,
bool * V_52 )
{
struct V_4 * V_39 = V_45 -> V_4 ;
unsigned V_53 ;
int V_25 = 0 ;
if ( V_51 -> V_54 & V_55 )
* V_33 = true ;
if ( V_51 -> V_54 & V_56 )
* V_52 = true ;
F_32 (i) {
T_2 V_35 = V_51 -> V_35 . V_7 [ V_53 ] ;
T_2 V_34 = V_51 -> V_34 . V_7 [ V_53 ] ;
V_39 -> V_29 . V_7 [ V_53 ] =
( V_39 -> V_41 . V_7 [ V_53 ] & V_35 ) |
( V_39 -> V_36 . V_7 [ V_53 ] & V_34 ) ;
if ( V_35 & ~ V_39 -> V_29 . V_7 [ V_53 ] )
V_25 = - V_12 ;
}
return * V_33 ? V_25 : 0 ;
}
int F_33 ( const struct V_46 * V_46 , struct V_50 * V_57 )
{
struct V_47 * V_47 = F_27 ( V_46 ) ;
T_2 V_54 ;
unsigned V_58 , V_53 ;
int V_59 ;
struct V_60 V_51 ;
memset ( V_57 , 0 , sizeof( struct V_50 ) ) ;
if ( ! V_47 )
return - V_61 ;
V_59 = F_28 ( (struct V_46 * ) V_46 , V_47 ,
V_48 , & V_51 , V_62 ) ;
if ( V_59 == - V_61 || V_59 == - V_49 )
return - V_61 ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 < sizeof( V_54 ) )
return - V_43 ;
V_57 -> V_54 = V_54 = F_34 ( V_51 . V_54 ) ;
switch ( V_54 & V_56 ) {
case V_63 :
if ( V_59 != V_64 )
return - V_43 ;
V_58 = V_65 ;
break;
case V_66 :
if ( V_59 != V_67 )
return - V_43 ;
V_58 = V_68 ;
break;
default:
return - V_43 ;
}
F_32 (i) {
if ( V_53 >= V_58 )
break;
V_57 -> V_35 . V_7 [ V_53 ] = F_34 ( V_51 . V_69 [ V_53 ] . V_35 ) ;
V_57 -> V_34 . V_7 [ V_53 ] = F_34 ( V_51 . V_69 [ V_53 ] . V_34 ) ;
}
V_57 -> V_35 . V_7 [ V_70 ] &= V_71 ;
V_57 -> V_34 . V_7 [ V_70 ] &= V_71 ;
return 0 ;
}
static int F_35 ( struct V_44 * V_45 , bool * V_33 , bool * V_52 )
{
int V_72 = 0 ;
struct V_50 V_73 ;
F_24 ( V_45 ) ;
if ( ! V_74 )
return 0 ;
if ( ! F_36 ( V_45 -> V_75 -> V_76 . V_77 ) )
return 0 ;
if ( ! F_37 ( V_45 -> V_75 -> V_76 . V_77 -> V_78 -> V_79 ) )
return 0 ;
V_72 = F_33 ( V_45 -> V_75 -> V_76 . V_46 , & V_73 ) ;
if ( V_72 < 0 ) {
if ( V_72 == - V_43 )
F_2 ( V_80 L_4 ,
V_81 , V_72 , V_45 -> V_82 ) ;
else if ( V_72 == - V_61 )
V_72 = 0 ;
goto V_30;
}
V_72 = F_31 ( & V_73 , V_45 , V_33 , V_52 ) ;
if ( V_72 == - V_43 )
F_2 ( V_80 L_5 ,
V_81 , V_72 , V_45 -> V_82 ) ;
V_30:
if ( V_72 )
F_24 ( V_45 ) ;
return V_72 ;
}
int F_38 ( struct V_44 * V_45 )
{
const struct V_4 * V_40 = F_10 () ;
struct V_4 * V_39 = V_45 -> V_4 ;
bool V_33 , V_52 = false , V_83 ;
int V_25 ;
T_3 V_84 ;
if ( F_22 ( ! F_23 ( V_40 ) ) )
return - V_12 ;
V_33 = false ;
V_25 = F_35 ( V_45 , & V_33 , & V_52 ) ;
if ( V_25 < 0 )
return V_25 ;
V_84 = F_39 ( V_39 -> V_10 , 0 ) ;
if ( ! F_40 ( V_85 ) ) {
if ( V_52 && ! F_5 ( V_39 -> V_86 , V_84 ) && F_5 ( V_39 -> V_16 , V_84 ) ) {
F_1 ( V_45 -> V_82 ) ;
goto V_87;
}
if ( F_5 ( V_39 -> V_16 , V_84 ) || F_5 ( V_39 -> V_86 , V_84 ) ) {
V_39 -> V_29 = F_20 ( V_40 -> V_41 ,
V_40 -> V_36 ) ;
}
if ( F_5 ( V_39 -> V_16 , V_84 ) )
V_33 = true ;
}
V_87:
if ( ! F_12 ( V_39 -> V_29 , V_40 -> V_29 ) )
V_45 -> V_88 |= V_89 ;
V_83 = ! F_5 ( V_39 -> V_16 , V_40 -> V_86 ) || ! F_41 ( V_39 -> V_90 , V_40 -> V_91 ) ;
if ( ( V_83 ||
! F_12 ( V_39 -> V_29 , V_40 -> V_29 ) ) &&
V_45 -> V_92 & ~ V_93 ) {
if ( ! F_7 ( V_94 ) ||
( V_45 -> V_92 & V_95 ) ) {
V_39 -> V_16 = V_39 -> V_86 ;
V_39 -> V_90 = V_39 -> V_91 ;
}
V_39 -> V_29 = F_21 ( V_39 -> V_29 ,
V_40 -> V_29 ) ;
}
V_39 -> V_96 = V_39 -> V_97 = V_39 -> V_16 ;
V_39 -> V_98 = V_39 -> V_99 = V_39 -> V_90 ;
if ( V_52 || V_83 )
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
if ( ! F_12 ( V_100 , V_39 -> V_11 ) ||
! F_5 ( V_39 -> V_16 , V_84 ) || ! F_5 ( V_39 -> V_86 , V_84 ) ||
F_40 ( V_85 ) ) {
V_25 = F_42 ( V_45 , V_39 , V_40 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
V_39 -> V_101 &= ~ F_43 ( V_102 ) ;
if ( F_22 ( ! F_23 ( V_39 ) ) )
return - V_12 ;
return 0 ;
}
int F_44 ( struct V_44 * V_45 )
{
const struct V_4 * V_4 = F_10 () ;
T_3 V_84 = F_39 ( V_4 -> V_10 , 0 ) ;
if ( ! F_5 ( V_4 -> V_86 , V_84 ) ) {
if ( V_45 -> V_11 )
return 1 ;
if ( ! F_12 ( V_4 -> V_29 , V_4 -> V_42 ) )
return 1 ;
}
return ( ! F_5 ( V_4 -> V_16 , V_4 -> V_86 ) ||
! F_41 ( V_4 -> V_90 , V_4 -> V_91 ) ) ;
}
int F_45 ( struct V_46 * V_46 , const char * V_103 ,
const void * V_104 , T_4 V_59 , int V_105 )
{
if ( ! strcmp ( V_103 , V_48 ) ) {
if ( ! F_7 ( V_106 ) )
return - V_12 ;
return 0 ;
}
if ( ! strncmp ( V_103 , V_107 ,
sizeof( V_107 ) - 1 ) &&
! F_7 ( V_108 ) )
return - V_12 ;
return 0 ;
}
int F_46 ( struct V_46 * V_46 , const char * V_103 )
{
if ( ! strcmp ( V_103 , V_48 ) ) {
if ( ! F_7 ( V_106 ) )
return - V_12 ;
return 0 ;
}
if ( ! strncmp ( V_103 , V_107 ,
sizeof( V_107 ) - 1 ) &&
! F_7 ( V_108 ) )
return - V_12 ;
return 0 ;
}
static inline void F_47 ( struct V_4 * V_39 , const struct V_4 * V_40 )
{
T_3 V_84 = F_39 ( V_40 -> V_10 , 0 ) ;
if ( ( F_5 ( V_40 -> V_86 , V_84 ) ||
F_5 ( V_40 -> V_16 , V_84 ) ||
F_5 ( V_40 -> V_96 , V_84 ) ) &&
( ! F_5 ( V_39 -> V_86 , V_84 ) &&
! F_5 ( V_39 -> V_16 , V_84 ) &&
! F_5 ( V_39 -> V_96 , V_84 ) ) ) {
if ( ! F_40 ( V_102 ) ) {
F_25 ( V_39 -> V_29 ) ;
F_25 ( V_39 -> V_11 ) ;
}
F_25 ( V_39 -> V_42 ) ;
}
if ( F_5 ( V_40 -> V_16 , V_84 ) && ! F_5 ( V_39 -> V_16 , V_84 ) )
F_25 ( V_39 -> V_11 ) ;
if ( ! F_5 ( V_40 -> V_16 , V_84 ) && F_5 ( V_39 -> V_16 , V_84 ) )
V_39 -> V_11 = V_39 -> V_29 ;
}
int F_48 ( struct V_4 * V_39 , const struct V_4 * V_40 , int V_105 )
{
switch ( V_105 ) {
case V_109 :
case V_110 :
case V_111 :
if ( ! F_40 ( V_112 ) )
F_47 ( V_39 , V_40 ) ;
break;
case V_113 :
if ( ! F_40 ( V_112 ) ) {
T_3 V_84 = F_39 ( V_40 -> V_10 , 0 ) ;
if ( F_5 ( V_40 -> V_97 , V_84 ) && ! F_5 ( V_39 -> V_97 , V_84 ) )
V_39 -> V_11 =
F_49 ( V_39 -> V_11 ) ;
if ( ! F_5 ( V_40 -> V_97 , V_84 ) && F_5 ( V_39 -> V_97 , V_84 ) )
V_39 -> V_11 =
F_50 ( V_39 -> V_11 ,
V_39 -> V_29 ) ;
}
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_51 ( struct V_22 * V_114 )
{
int V_115 , V_25 = 0 ;
F_9 () ;
V_115 = F_12 ( F_11 ( V_114 ) -> V_29 ,
F_10 () -> V_29 ) ;
if ( ! V_115 && ! F_13 ( F_11 ( V_114 ) -> V_10 , V_116 ) )
V_25 = - V_12 ;
F_14 () ;
return V_25 ;
}
int F_52 ( struct V_22 * V_114 )
{
return F_51 ( V_114 ) ;
}
int F_53 ( struct V_22 * V_114 , int V_117 )
{
return F_51 ( V_114 ) ;
}
int F_54 ( struct V_22 * V_114 , int V_118 )
{
return F_51 ( V_114 ) ;
}
static int F_55 ( unsigned long V_7 )
{
struct V_4 * V_39 ;
if ( ! F_13 ( F_56 () , V_37 ) )
return - V_12 ;
if ( ! F_57 ( V_7 ) )
return - V_43 ;
V_39 = F_58 () ;
if ( ! V_39 )
return - V_119 ;
F_59 ( V_39 -> V_41 , V_7 ) ;
return F_60 ( V_39 ) ;
}
int F_61 ( int V_120 , unsigned long V_121 , unsigned long V_122 ,
unsigned long V_123 , unsigned long V_124 )
{
const struct V_4 * V_40 = F_10 () ;
struct V_4 * V_39 ;
switch ( V_120 ) {
case V_125 :
if ( ! F_57 ( V_121 ) )
return - V_43 ;
return ! ! F_4 ( V_40 -> V_41 , V_121 ) ;
case V_126 :
return F_55 ( V_121 ) ;
case V_127 :
if ( ( ( ( V_40 -> V_101 & V_128 ) >> 1 )
& ( V_40 -> V_101 ^ V_121 ) )
|| ( ( V_40 -> V_101 & V_128 & ~ V_121 ) )
|| ( V_121 & ~ ( V_128 | V_129 ) )
|| ( F_3 ( F_10 () ,
F_10 () -> V_10 , V_37 ,
V_38 ) != 0 )
)
return - V_12 ;
V_39 = F_58 () ;
if ( ! V_39 )
return - V_119 ;
V_39 -> V_101 = V_121 ;
return F_60 ( V_39 ) ;
case V_130 :
return V_40 -> V_101 ;
case V_131 :
return ! ! F_40 ( V_102 ) ;
case V_132 :
if ( V_121 > 1 )
return - V_43 ;
if ( F_40 ( V_133 ) )
return - V_12 ;
V_39 = F_58 () ;
if ( ! V_39 )
return - V_119 ;
if ( V_121 )
V_39 -> V_101 |= F_43 ( V_102 ) ;
else
V_39 -> V_101 &= ~ F_43 ( V_102 ) ;
return F_60 ( V_39 ) ;
case V_134 :
if ( V_121 == V_135 ) {
if ( V_122 | V_123 | V_124 )
return - V_43 ;
V_39 = F_58 () ;
if ( ! V_39 )
return - V_119 ;
F_25 ( V_39 -> V_42 ) ;
return F_60 ( V_39 ) ;
}
if ( ( ( ! F_57 ( V_122 ) ) | V_123 | V_124 ) )
return - V_43 ;
if ( V_121 == V_136 ) {
return ! ! F_4 ( F_10 () -> V_42 , V_122 ) ;
} else if ( V_121 != V_137 &&
V_121 != V_138 ) {
return - V_43 ;
} else {
if ( V_121 == V_137 &&
( ! F_4 ( F_10 () -> V_29 , V_122 ) ||
! F_4 ( F_10 () -> V_36 ,
V_122 ) ||
F_40 ( V_139 ) ) )
return - V_12 ;
V_39 = F_58 () ;
if ( ! V_39 )
return - V_119 ;
if ( V_121 == V_137 )
F_62 ( V_39 -> V_42 , V_122 ) ;
else
F_59 ( V_39 -> V_42 , V_122 ) ;
return F_60 ( V_39 ) ;
}
default:
return - V_140 ;
}
}
int F_63 ( struct V_141 * V_142 , long V_143 )
{
int V_144 = 0 ;
if ( F_3 ( F_10 () , & V_13 , V_108 ,
V_145 ) == 0 )
V_144 = 1 ;
return V_144 ;
}
int F_64 ( unsigned long V_146 )
{
int V_25 = 0 ;
if ( V_146 < V_147 ) {
V_25 = F_3 ( F_10 () , & V_13 , V_148 ,
V_38 ) ;
if ( V_25 == 0 )
V_149 -> V_105 |= V_150 ;
}
return V_25 ;
}
int F_65 ( struct V_75 * V_75 , unsigned long V_151 ,
unsigned long V_152 , unsigned long V_105 )
{
return 0 ;
}
void T_5 F_66 ( void )
{
F_67 ( V_153 , F_68 ( V_153 ) ) ;
}
