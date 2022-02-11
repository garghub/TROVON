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
return 0 ;
}
static inline void F_21 ( struct V_40 * V_41 )
{
F_22 ( V_41 -> V_4 -> V_27 ) ;
V_41 -> V_11 = false ;
}
int F_23 ( struct V_42 * V_42 )
{
struct V_43 * V_43 = F_24 ( V_42 ) ;
int error ;
if ( ! V_43 -> V_44 -> V_45 )
return 0 ;
error = V_43 -> V_44 -> V_45 ( V_42 , V_46 , NULL , 0 ) ;
if ( error <= 0 )
return 0 ;
return 1 ;
}
int F_25 ( struct V_42 * V_42 )
{
struct V_43 * V_43 = F_24 ( V_42 ) ;
if ( ! V_43 -> V_44 -> V_47 )
return 0 ;
return V_43 -> V_44 -> V_47 ( V_42 , V_46 ) ;
}
static inline int F_26 ( struct V_48 * V_49 ,
struct V_40 * V_41 ,
bool * V_31 ,
bool * V_50 )
{
struct V_4 * V_37 = V_41 -> V_4 ;
unsigned V_51 ;
int V_25 = 0 ;
if ( V_49 -> V_52 & V_53 )
* V_31 = true ;
if ( V_49 -> V_52 & V_54 )
* V_50 = true ;
F_27 (i) {
T_2 V_33 = V_49 -> V_33 . V_7 [ V_51 ] ;
T_2 V_32 = V_49 -> V_32 . V_7 [ V_51 ] ;
V_37 -> V_27 . V_7 [ V_51 ] =
( V_37 -> V_39 . V_7 [ V_51 ] & V_33 ) |
( V_37 -> V_34 . V_7 [ V_51 ] & V_32 ) ;
if ( V_33 & ~ V_37 -> V_27 . V_7 [ V_51 ] )
V_25 = - V_12 ;
}
return * V_31 ? V_25 : 0 ;
}
int F_28 ( const struct V_42 * V_42 , struct V_48 * V_55 )
{
struct V_43 * V_43 = F_24 ( V_42 ) ;
T_2 V_52 ;
unsigned V_56 , V_51 ;
int V_57 ;
struct V_58 V_49 ;
memset ( V_55 , 0 , sizeof( struct V_48 ) ) ;
if ( ! V_43 || ! V_43 -> V_44 -> V_45 )
return - V_59 ;
V_57 = V_43 -> V_44 -> V_45 ( (struct V_42 * ) V_42 , V_46 , & V_49 ,
V_60 ) ;
if ( V_57 == - V_59 || V_57 == - V_61 )
return - V_59 ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 < sizeof( V_52 ) )
return - V_62 ;
V_55 -> V_52 = V_52 = F_29 ( V_49 . V_52 ) ;
switch ( V_52 & V_54 ) {
case V_63 :
if ( V_57 != V_64 )
return - V_62 ;
V_56 = V_65 ;
break;
case V_66 :
if ( V_57 != V_67 )
return - V_62 ;
V_56 = V_68 ;
break;
default:
return - V_62 ;
}
F_27 (i) {
if ( V_51 >= V_56 )
break;
V_55 -> V_33 . V_7 [ V_51 ] = F_29 ( V_49 . V_69 [ V_51 ] . V_33 ) ;
V_55 -> V_32 . V_7 [ V_51 ] = F_29 ( V_49 . V_69 [ V_51 ] . V_32 ) ;
}
V_55 -> V_33 . V_7 [ V_70 ] &= V_71 ;
V_55 -> V_32 . V_7 [ V_70 ] &= V_71 ;
return 0 ;
}
static int F_30 ( struct V_40 * V_41 , bool * V_31 , bool * V_50 )
{
int V_72 = 0 ;
struct V_48 V_73 ;
F_21 ( V_41 ) ;
if ( ! V_74 )
return 0 ;
if ( V_41 -> V_75 -> V_76 . V_77 -> V_78 & V_79 )
return 0 ;
V_72 = F_28 ( V_41 -> V_75 -> V_76 . V_42 , & V_73 ) ;
if ( V_72 < 0 ) {
if ( V_72 == - V_62 )
F_2 ( V_80 L_4 ,
V_81 , V_72 , V_41 -> V_82 ) ;
else if ( V_72 == - V_59 )
V_72 = 0 ;
goto V_28;
}
V_72 = F_26 ( & V_73 , V_41 , V_31 , V_50 ) ;
if ( V_72 == - V_62 )
F_2 ( V_80 L_5 ,
V_81 , V_72 , V_41 -> V_82 ) ;
V_28:
if ( V_72 )
F_21 ( V_41 ) ;
return V_72 ;
}
int F_31 ( struct V_40 * V_41 )
{
const struct V_4 * V_38 = F_10 () ;
struct V_4 * V_37 = V_41 -> V_4 ;
bool V_31 , V_50 = false ;
int V_25 ;
T_3 V_83 ;
V_31 = false ;
V_25 = F_30 ( V_41 , & V_31 , & V_50 ) ;
if ( V_25 < 0 )
return V_25 ;
V_83 = F_32 ( V_37 -> V_10 , 0 ) ;
if ( ! F_33 ( V_84 ) ) {
if ( V_50 && ! F_5 ( V_37 -> V_85 , V_83 ) && F_5 ( V_37 -> V_16 , V_83 ) ) {
F_1 ( V_41 -> V_82 ) ;
goto V_86;
}
if ( F_5 ( V_37 -> V_16 , V_83 ) || F_5 ( V_37 -> V_85 , V_83 ) ) {
V_37 -> V_27 = F_20 ( V_38 -> V_39 ,
V_38 -> V_34 ) ;
}
if ( F_5 ( V_37 -> V_16 , V_83 ) )
V_31 = true ;
}
V_86:
if ( ! F_12 ( V_37 -> V_27 , V_38 -> V_27 ) )
V_41 -> V_87 |= V_88 ;
if ( ( ! F_5 ( V_37 -> V_16 , V_38 -> V_85 ) ||
! F_34 ( V_37 -> V_89 , V_38 -> V_90 ) ||
! F_12 ( V_37 -> V_27 , V_38 -> V_27 ) ) &&
V_41 -> V_91 & ~ V_92 ) {
if ( ! F_7 ( V_93 ) ||
( V_41 -> V_91 & V_94 ) ) {
V_37 -> V_16 = V_37 -> V_85 ;
V_37 -> V_89 = V_37 -> V_90 ;
}
V_37 -> V_27 = F_35 ( V_37 -> V_27 ,
V_38 -> V_27 ) ;
}
V_37 -> V_95 = V_37 -> V_96 = V_37 -> V_16 ;
V_37 -> V_97 = V_37 -> V_98 = V_37 -> V_89 ;
if ( V_31 )
V_37 -> V_11 = V_37 -> V_27 ;
else
F_22 ( V_37 -> V_11 ) ;
V_41 -> V_11 = V_31 ;
if ( ! F_36 ( V_37 -> V_11 ) ) {
if ( ! F_12 ( V_99 , V_37 -> V_11 ) ||
! F_5 ( V_37 -> V_16 , V_83 ) || ! F_5 ( V_37 -> V_85 , V_83 ) ||
F_33 ( V_84 ) ) {
V_25 = F_37 ( V_41 , V_37 , V_38 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
V_37 -> V_100 &= ~ F_38 ( V_101 ) ;
return 0 ;
}
int F_39 ( struct V_40 * V_41 )
{
const struct V_4 * V_4 = F_10 () ;
T_3 V_83 = F_32 ( V_4 -> V_10 , 0 ) ;
if ( ! F_5 ( V_4 -> V_85 , V_83 ) ) {
if ( V_41 -> V_11 )
return 1 ;
if ( ! F_36 ( V_4 -> V_27 ) )
return 1 ;
}
return ( ! F_5 ( V_4 -> V_16 , V_4 -> V_85 ) ||
! F_34 ( V_4 -> V_89 , V_4 -> V_90 ) ) ;
}
int F_40 ( struct V_42 * V_42 , const char * V_102 ,
const void * V_103 , T_4 V_57 , int V_104 )
{
if ( ! strcmp ( V_102 , V_46 ) ) {
if ( ! F_7 ( V_105 ) )
return - V_12 ;
return 0 ;
}
if ( ! strncmp ( V_102 , V_106 ,
sizeof( V_106 ) - 1 ) &&
! F_7 ( V_107 ) )
return - V_12 ;
return 0 ;
}
int F_41 ( struct V_42 * V_42 , const char * V_102 )
{
if ( ! strcmp ( V_102 , V_46 ) ) {
if ( ! F_7 ( V_105 ) )
return - V_12 ;
return 0 ;
}
if ( ! strncmp ( V_102 , V_106 ,
sizeof( V_106 ) - 1 ) &&
! F_7 ( V_107 ) )
return - V_12 ;
return 0 ;
}
static inline void F_42 ( struct V_4 * V_37 , const struct V_4 * V_38 )
{
T_3 V_83 = F_32 ( V_38 -> V_10 , 0 ) ;
if ( ( F_5 ( V_38 -> V_85 , V_83 ) ||
F_5 ( V_38 -> V_16 , V_83 ) ||
F_5 ( V_38 -> V_95 , V_83 ) ) &&
( ! F_5 ( V_37 -> V_85 , V_83 ) &&
! F_5 ( V_37 -> V_16 , V_83 ) &&
! F_5 ( V_37 -> V_95 , V_83 ) ) &&
! F_33 ( V_101 ) ) {
F_22 ( V_37 -> V_27 ) ;
F_22 ( V_37 -> V_11 ) ;
}
if ( F_5 ( V_38 -> V_16 , V_83 ) && ! F_5 ( V_37 -> V_16 , V_83 ) )
F_22 ( V_37 -> V_11 ) ;
if ( ! F_5 ( V_38 -> V_16 , V_83 ) && F_5 ( V_37 -> V_16 , V_83 ) )
V_37 -> V_11 = V_37 -> V_27 ;
}
int F_43 ( struct V_4 * V_37 , const struct V_4 * V_38 , int V_104 )
{
switch ( V_104 ) {
case V_108 :
case V_109 :
case V_110 :
if ( ! F_33 ( V_111 ) )
F_42 ( V_37 , V_38 ) ;
break;
case V_112 :
if ( ! F_33 ( V_111 ) ) {
T_3 V_83 = F_32 ( V_38 -> V_10 , 0 ) ;
if ( F_5 ( V_38 -> V_96 , V_83 ) && ! F_5 ( V_37 -> V_96 , V_83 ) )
V_37 -> V_11 =
F_44 ( V_37 -> V_11 ) ;
if ( ! F_5 ( V_38 -> V_96 , V_83 ) && F_5 ( V_37 -> V_96 , V_83 ) )
V_37 -> V_11 =
F_45 ( V_37 -> V_11 ,
V_37 -> V_27 ) ;
}
break;
default:
return - V_62 ;
}
return 0 ;
}
static int F_46 ( struct V_22 * V_113 )
{
int V_114 , V_25 = 0 ;
F_9 () ;
V_114 = F_12 ( F_11 ( V_113 ) -> V_27 ,
F_10 () -> V_27 ) ;
if ( ! V_114 && ! F_13 ( F_11 ( V_113 ) -> V_10 , V_115 ) )
V_25 = - V_12 ;
F_14 () ;
return V_25 ;
}
int F_47 ( struct V_22 * V_113 )
{
return F_46 ( V_113 ) ;
}
int F_48 ( struct V_22 * V_113 , int V_116 )
{
return F_46 ( V_113 ) ;
}
int F_49 ( struct V_22 * V_113 , int V_117 )
{
return F_46 ( V_113 ) ;
}
static int F_50 ( unsigned long V_7 )
{
struct V_4 * V_37 ;
if ( ! F_13 ( F_51 () , V_35 ) )
return - V_12 ;
if ( ! F_52 ( V_7 ) )
return - V_62 ;
V_37 = F_53 () ;
if ( ! V_37 )
return - V_118 ;
F_54 ( V_37 -> V_39 , V_7 ) ;
return F_55 ( V_37 ) ;
}
int F_56 ( int V_119 , unsigned long V_120 , unsigned long V_121 ,
unsigned long V_122 , unsigned long V_123 )
{
const struct V_4 * V_38 = F_10 () ;
struct V_4 * V_37 ;
switch ( V_119 ) {
case V_124 :
if ( ! F_52 ( V_120 ) )
return - V_62 ;
return ! ! F_4 ( V_38 -> V_39 , V_120 ) ;
case V_125 :
return F_50 ( V_120 ) ;
case V_126 :
if ( ( ( ( V_38 -> V_100 & V_127 ) >> 1 )
& ( V_38 -> V_100 ^ V_120 ) )
|| ( ( V_38 -> V_100 & V_127 & ~ V_120 ) )
|| ( V_120 & ~ ( V_127 | V_128 ) )
|| ( F_3 ( F_10 () ,
F_10 () -> V_10 , V_35 ,
V_36 ) != 0 )
)
return - V_12 ;
V_37 = F_53 () ;
if ( ! V_37 )
return - V_118 ;
V_37 -> V_100 = V_120 ;
return F_55 ( V_37 ) ;
case V_129 :
return V_38 -> V_100 ;
case V_130 :
return ! ! F_33 ( V_101 ) ;
case V_131 :
if ( V_120 > 1 )
return - V_62 ;
if ( F_33 ( V_132 ) )
return - V_12 ;
V_37 = F_53 () ;
if ( ! V_37 )
return - V_118 ;
if ( V_120 )
V_37 -> V_100 |= F_38 ( V_101 ) ;
else
V_37 -> V_100 &= ~ F_38 ( V_101 ) ;
return F_55 ( V_37 ) ;
default:
return - V_133 ;
}
}
int F_57 ( struct V_134 * V_135 , long V_136 )
{
int V_137 = 0 ;
if ( F_3 ( F_10 () , & V_13 , V_107 ,
V_138 ) == 0 )
V_137 = 1 ;
return V_137 ;
}
int F_58 ( unsigned long V_139 )
{
int V_25 = 0 ;
if ( V_139 < V_140 ) {
V_25 = F_3 ( F_10 () , & V_13 , V_141 ,
V_36 ) ;
if ( V_25 == 0 )
V_142 -> V_104 |= V_143 ;
}
return V_25 ;
}
int F_59 ( struct V_75 * V_75 , unsigned long V_144 ,
unsigned long V_145 , unsigned long V_104 )
{
return 0 ;
}
void T_5 F_60 ( void )
{
F_61 ( V_146 , F_62 ( V_146 ) ) ;
}
