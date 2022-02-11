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
int F_4 ( struct V_6 * V_7 , int V_8 )
{
if ( ! F_5 ( F_6 () , V_8 ) )
return - V_9 ;
return 0 ;
}
int F_7 ( struct V_10 * V_11 , const struct V_12 * V_12 ,
struct V_13 * V_14 , int V_8 , int V_15 )
{
for (; ; ) {
if ( V_14 != & V_16 && V_14 -> V_17 == V_12 -> V_18 )
return 0 ;
if ( V_14 == V_12 -> V_18 -> V_19 )
return F_5 ( V_12 -> V_20 , V_8 ) ? 0 : - V_9 ;
if ( V_14 == & V_16 )
return - V_9 ;
V_14 = V_14 -> V_17 -> V_19 ;
}
}
int F_8 ( const struct V_21 * V_22 , const struct V_23 * V_24 )
{
if ( ! F_9 ( V_25 ) )
return - V_9 ;
return 0 ;
}
int F_10 ( struct V_10 * V_26 , unsigned int V_27 )
{
int V_28 = 0 ;
const struct V_12 * V_12 , * V_29 ;
F_11 () ;
V_12 = F_12 () ;
V_29 = F_13 ( V_26 ) ;
if ( V_12 -> V_18 -> V_19 == V_29 -> V_18 -> V_19 &&
F_14 ( V_29 -> V_30 , V_12 -> V_30 ) )
goto V_31;
if ( F_15 ( V_29 -> V_18 -> V_19 , V_32 ) )
goto V_31;
V_28 = - V_9 ;
V_31:
F_16 () ;
return V_28 ;
}
int F_17 ( struct V_10 * V_33 )
{
int V_28 = 0 ;
const struct V_12 * V_12 , * V_29 ;
F_11 () ;
V_12 = F_13 ( V_33 ) ;
V_29 = F_12 () ;
if ( V_12 -> V_18 -> V_19 == V_29 -> V_18 -> V_19 &&
F_14 ( V_29 -> V_30 , V_12 -> V_30 ) )
goto V_31;
if ( F_18 ( V_33 , V_29 -> V_18 -> V_19 , V_32 ) )
goto V_31;
V_28 = - V_9 ;
V_31:
F_16 () ;
return V_28 ;
}
int F_19 ( struct V_10 * V_34 , T_1 * V_35 ,
T_1 * V_36 , T_1 * V_37 )
{
const struct V_12 * V_12 ;
F_11 () ;
V_12 = F_13 ( V_34 ) ;
* V_35 = V_12 -> V_20 ;
* V_36 = V_12 -> V_38 ;
* V_37 = V_12 -> V_30 ;
F_16 () ;
return 0 ;
}
static inline int F_20 ( void )
{
if ( F_7 ( V_39 , F_12 () ,
F_12 () -> V_18 -> V_19 , V_40 ,
V_41 ) == 0 )
return 0 ;
return 1 ;
}
int F_21 ( struct V_12 * V_42 ,
const struct V_12 * V_43 ,
const T_1 * V_35 ,
const T_1 * V_36 ,
const T_1 * V_37 )
{
if ( F_20 () &&
! F_14 ( * V_36 ,
F_22 ( V_43 -> V_38 ,
V_43 -> V_30 ) ) )
return - V_9 ;
if ( ! F_14 ( * V_36 ,
F_22 ( V_43 -> V_38 ,
V_43 -> V_44 ) ) )
return - V_9 ;
if ( ! F_14 ( * V_37 , V_43 -> V_30 ) )
return - V_9 ;
if ( ! F_14 ( * V_35 , * V_37 ) )
return - V_9 ;
V_42 -> V_20 = * V_35 ;
V_42 -> V_38 = * V_36 ;
V_42 -> V_30 = * V_37 ;
return 0 ;
}
static inline void F_23 ( struct V_45 * V_46 )
{
F_24 ( V_46 -> V_12 -> V_30 ) ;
V_46 -> V_20 = false ;
}
int F_25 ( struct V_47 * V_47 )
{
struct V_48 * V_48 = V_47 -> V_49 ;
int error ;
if ( ! V_48 -> V_50 -> V_51 )
return 0 ;
error = V_48 -> V_50 -> V_51 ( V_47 , V_52 , NULL , 0 ) ;
if ( error <= 0 )
return 0 ;
return 1 ;
}
int F_26 ( struct V_47 * V_47 )
{
struct V_48 * V_48 = V_47 -> V_49 ;
if ( ! V_48 -> V_50 -> V_53 )
return 0 ;
return V_48 -> V_50 -> V_53 ( V_47 , V_52 ) ;
}
static inline int F_27 ( struct V_54 * V_55 ,
struct V_45 * V_46 ,
bool * V_35 ,
bool * V_56 )
{
struct V_12 * V_42 = V_46 -> V_12 ;
unsigned V_57 ;
int V_28 = 0 ;
if ( V_55 -> V_58 & V_59 )
* V_35 = true ;
if ( V_55 -> V_58 & V_60 )
* V_56 = true ;
F_28 (i) {
T_2 V_37 = V_55 -> V_37 . V_8 [ V_57 ] ;
T_2 V_36 = V_55 -> V_36 . V_8 [ V_57 ] ;
V_42 -> V_30 . V_8 [ V_57 ] =
( V_42 -> V_44 . V_8 [ V_57 ] & V_37 ) |
( V_42 -> V_38 . V_8 [ V_57 ] & V_36 ) ;
if ( V_37 & ~ V_42 -> V_30 . V_8 [ V_57 ] )
V_28 = - V_9 ;
}
return * V_35 ? V_28 : 0 ;
}
int F_29 ( const struct V_47 * V_47 , struct V_54 * V_61 )
{
struct V_48 * V_48 = V_47 -> V_49 ;
T_2 V_58 ;
unsigned V_62 , V_57 ;
int V_63 ;
struct V_64 V_55 ;
memset ( V_61 , 0 , sizeof( struct V_54 ) ) ;
if ( ! V_48 || ! V_48 -> V_50 -> V_51 )
return - V_65 ;
V_63 = V_48 -> V_50 -> V_51 ( (struct V_47 * ) V_47 , V_52 , & V_55 ,
V_66 ) ;
if ( V_63 == - V_65 || V_63 == - V_67 )
return - V_65 ;
if ( V_63 < 0 )
return V_63 ;
if ( V_63 < sizeof( V_58 ) )
return - V_68 ;
V_61 -> V_58 = V_58 = F_30 ( V_55 . V_58 ) ;
switch ( V_58 & V_60 ) {
case V_69 :
if ( V_63 != V_70 )
return - V_68 ;
V_62 = V_71 ;
break;
case V_72 :
if ( V_63 != V_73 )
return - V_68 ;
V_62 = V_74 ;
break;
default:
return - V_68 ;
}
F_28 (i) {
if ( V_57 >= V_62 )
break;
V_61 -> V_37 . V_8 [ V_57 ] = F_30 ( V_55 . V_75 [ V_57 ] . V_37 ) ;
V_61 -> V_36 . V_8 [ V_57 ] = F_30 ( V_55 . V_75 [ V_57 ] . V_36 ) ;
}
return 0 ;
}
static int F_31 ( struct V_45 * V_46 , bool * V_35 , bool * V_56 )
{
struct V_47 * V_47 ;
int V_76 = 0 ;
struct V_54 V_77 ;
F_23 ( V_46 ) ;
if ( ! V_78 )
return 0 ;
if ( V_46 -> V_79 -> V_80 -> V_81 & V_82 )
return 0 ;
V_47 = F_32 ( V_46 -> V_79 -> V_83 ) ;
V_76 = F_29 ( V_47 , & V_77 ) ;
if ( V_76 < 0 ) {
if ( V_76 == - V_68 )
F_2 ( V_84 L_4 ,
V_85 , V_76 , V_46 -> V_86 ) ;
else if ( V_76 == - V_65 )
V_76 = 0 ;
goto V_31;
}
V_76 = F_27 ( & V_77 , V_46 , V_35 , V_56 ) ;
if ( V_76 == - V_68 )
F_2 ( V_84 L_5 ,
V_85 , V_76 , V_46 -> V_86 ) ;
V_31:
F_33 ( V_47 ) ;
if ( V_76 )
F_23 ( V_46 ) ;
return V_76 ;
}
int F_34 ( struct V_45 * V_46 )
{
const struct V_12 * V_43 = F_12 () ;
struct V_12 * V_42 = V_46 -> V_12 ;
bool V_35 , V_56 = false ;
int V_28 ;
V_35 = false ;
V_28 = F_31 ( V_46 , & V_35 , & V_56 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ! F_35 ( V_87 ) ) {
if ( V_56 && V_42 -> V_88 != 0 && V_42 -> V_89 == 0 ) {
F_1 ( V_46 -> V_86 ) ;
goto V_90;
}
if ( V_42 -> V_89 == 0 || V_42 -> V_88 == 0 ) {
V_42 -> V_30 = F_22 ( V_43 -> V_44 ,
V_43 -> V_38 ) ;
}
if ( V_42 -> V_89 == 0 )
V_35 = true ;
}
V_90:
if ( ( V_42 -> V_89 != V_43 -> V_88 ||
V_42 -> V_91 != V_43 -> V_92 ||
! F_14 ( V_42 -> V_30 , V_43 -> V_30 ) ) &&
V_46 -> V_93 & ~ V_94 ) {
if ( ! F_9 ( V_95 ) ) {
V_42 -> V_89 = V_42 -> V_88 ;
V_42 -> V_91 = V_42 -> V_92 ;
}
V_42 -> V_30 = F_36 ( V_42 -> V_30 ,
V_43 -> V_30 ) ;
}
V_42 -> V_96 = V_42 -> V_97 = V_42 -> V_89 ;
V_42 -> V_98 = V_42 -> V_99 = V_42 -> V_91 ;
if ( V_35 )
V_42 -> V_20 = V_42 -> V_30 ;
else
F_24 ( V_42 -> V_20 ) ;
V_46 -> V_20 = V_35 ;
if ( ! F_37 ( V_42 -> V_20 ) ) {
if ( ! F_14 ( V_100 , V_42 -> V_20 ) ||
V_42 -> V_89 != 0 || V_42 -> V_88 != 0 ||
F_35 ( V_87 ) ) {
V_28 = F_38 ( V_46 , V_42 , V_43 ) ;
if ( V_28 < 0 )
return V_28 ;
}
}
V_42 -> V_101 &= ~ F_39 ( V_102 ) ;
return 0 ;
}
int F_40 ( struct V_45 * V_46 )
{
const struct V_12 * V_12 = F_12 () ;
if ( V_12 -> V_88 != 0 ) {
if ( V_46 -> V_20 )
return 1 ;
if ( ! F_37 ( V_12 -> V_30 ) )
return 1 ;
}
return ( V_12 -> V_89 != V_12 -> V_88 ||
V_12 -> V_91 != V_12 -> V_92 ) ;
}
int F_41 ( struct V_47 * V_47 , const char * V_103 ,
const void * V_104 , T_3 V_63 , int V_105 )
{
if ( ! strcmp ( V_103 , V_52 ) ) {
if ( ! F_9 ( V_106 ) )
return - V_9 ;
return 0 ;
}
if ( ! strncmp ( V_103 , V_107 ,
sizeof( V_107 ) - 1 ) &&
! F_9 ( V_108 ) )
return - V_9 ;
return 0 ;
}
int F_42 ( struct V_47 * V_47 , const char * V_103 )
{
if ( ! strcmp ( V_103 , V_52 ) ) {
if ( ! F_9 ( V_106 ) )
return - V_9 ;
return 0 ;
}
if ( ! strncmp ( V_103 , V_107 ,
sizeof( V_107 ) - 1 ) &&
! F_9 ( V_108 ) )
return - V_9 ;
return 0 ;
}
static inline void F_43 ( struct V_12 * V_42 , const struct V_12 * V_43 )
{
if ( ( V_43 -> V_88 == 0 || V_43 -> V_89 == 0 || V_43 -> V_96 == 0 ) &&
( V_42 -> V_88 != 0 && V_42 -> V_89 != 0 && V_42 -> V_96 != 0 ) &&
! F_35 ( V_102 ) ) {
F_24 ( V_42 -> V_30 ) ;
F_24 ( V_42 -> V_20 ) ;
}
if ( V_43 -> V_89 == 0 && V_42 -> V_89 != 0 )
F_24 ( V_42 -> V_20 ) ;
if ( V_43 -> V_89 != 0 && V_42 -> V_89 == 0 )
V_42 -> V_20 = V_42 -> V_30 ;
}
int F_44 ( struct V_12 * V_42 , const struct V_12 * V_43 , int V_105 )
{
switch ( V_105 ) {
case V_109 :
case V_110 :
case V_111 :
if ( ! F_35 ( V_112 ) )
F_43 ( V_42 , V_43 ) ;
break;
case V_113 :
if ( ! F_35 ( V_112 ) ) {
if ( V_43 -> V_97 == 0 && V_42 -> V_97 != 0 )
V_42 -> V_20 =
F_45 ( V_42 -> V_20 ) ;
if ( V_43 -> V_97 != 0 && V_42 -> V_97 == 0 )
V_42 -> V_20 =
F_46 ( V_42 -> V_20 ,
V_42 -> V_30 ) ;
}
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_47 ( struct V_10 * V_114 )
{
int V_115 ;
F_11 () ;
V_115 = F_14 ( F_13 ( V_114 ) -> V_30 ,
F_12 () -> V_30 ) ;
F_16 () ;
if ( ! V_115 && ! F_9 ( V_116 ) )
return - V_9 ;
return 0 ;
}
int F_48 ( struct V_10 * V_114 )
{
return F_47 ( V_114 ) ;
}
int F_49 ( struct V_10 * V_114 , int V_117 )
{
return F_47 ( V_114 ) ;
}
int F_50 ( struct V_10 * V_114 , int V_118 )
{
return F_47 ( V_114 ) ;
}
static long F_51 ( struct V_12 * V_42 , unsigned long V_8 )
{
if ( ! F_9 ( V_40 ) )
return - V_9 ;
if ( ! F_52 ( V_8 ) )
return - V_68 ;
F_53 ( V_42 -> V_44 , V_8 ) ;
return 0 ;
}
int F_54 ( int V_119 , unsigned long V_120 , unsigned long V_121 ,
unsigned long V_122 , unsigned long V_123 )
{
struct V_12 * V_42 ;
long error = 0 ;
V_42 = F_55 () ;
if ( ! V_42 )
return - V_124 ;
switch ( V_119 ) {
case V_125 :
error = - V_68 ;
if ( ! F_52 ( V_120 ) )
goto error;
error = ! ! F_5 ( V_42 -> V_44 , V_120 ) ;
goto V_126;
case V_127 :
error = F_51 ( V_42 , V_120 ) ;
if ( error < 0 )
goto error;
goto V_128;
case V_129 :
error = - V_9 ;
if ( ( ( ( V_42 -> V_101 & V_130 ) >> 1 )
& ( V_42 -> V_101 ^ V_120 ) )
|| ( ( V_42 -> V_101 & V_130 & ~ V_120 ) )
|| ( V_120 & ~ ( V_130 | V_131 ) )
|| ( F_7 ( V_39 , F_12 () ,
F_12 () -> V_18 -> V_19 , V_40 ,
V_41 ) != 0 )
)
goto error;
V_42 -> V_101 = V_120 ;
goto V_128;
case V_132 :
error = V_42 -> V_101 ;
goto V_126;
case V_133 :
if ( F_35 ( V_102 ) )
error = 1 ;
goto V_126;
case V_134 :
error = - V_68 ;
if ( V_120 > 1 )
goto error;
error = - V_9 ;
if ( F_35 ( V_135 ) )
goto error;
if ( V_120 )
V_42 -> V_101 |= F_39 ( V_102 ) ;
else
V_42 -> V_101 &= ~ F_39 ( V_102 ) ;
goto V_128;
default:
error = - V_136 ;
goto error;
}
V_128:
return F_56 ( V_42 ) ;
V_126:
error:
F_57 ( V_42 ) ;
return error ;
}
int F_58 ( struct V_137 * V_138 , long V_139 )
{
int V_140 = 0 ;
if ( F_7 ( V_39 , F_12 () , & V_16 , V_108 ,
V_141 ) == 0 )
V_140 = 1 ;
return F_59 ( V_138 , V_139 , V_140 ) ;
}
int F_60 ( struct V_79 * V_79 , unsigned long V_142 ,
unsigned long V_143 , unsigned long V_105 ,
unsigned long V_144 , unsigned long V_145 )
{
int V_28 = 0 ;
if ( V_144 < V_146 ) {
V_28 = F_7 ( V_39 , F_12 () , & V_16 , V_147 ,
V_41 ) ;
if ( V_28 == 0 )
V_39 -> V_105 |= V_148 ;
}
return V_28 ;
}
