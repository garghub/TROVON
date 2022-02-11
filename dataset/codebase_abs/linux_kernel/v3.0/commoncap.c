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
bool * V_35 )
{
struct V_12 * V_42 = V_46 -> V_12 ;
unsigned V_56 ;
int V_28 = 0 ;
if ( V_55 -> V_57 & V_58 )
* V_35 = true ;
F_28 (i) {
T_2 V_37 = V_55 -> V_37 . V_8 [ V_56 ] ;
T_2 V_36 = V_55 -> V_36 . V_8 [ V_56 ] ;
V_42 -> V_30 . V_8 [ V_56 ] =
( V_42 -> V_44 . V_8 [ V_56 ] & V_37 ) |
( V_42 -> V_38 . V_8 [ V_56 ] & V_36 ) ;
if ( V_37 & ~ V_42 -> V_30 . V_8 [ V_56 ] )
V_28 = - V_9 ;
}
return * V_35 ? V_28 : 0 ;
}
int F_29 ( const struct V_47 * V_47 , struct V_54 * V_59 )
{
struct V_48 * V_48 = V_47 -> V_49 ;
T_2 V_57 ;
unsigned V_60 , V_56 ;
int V_61 ;
struct V_62 V_55 ;
memset ( V_59 , 0 , sizeof( struct V_54 ) ) ;
if ( ! V_48 || ! V_48 -> V_50 -> V_51 )
return - V_63 ;
V_61 = V_48 -> V_50 -> V_51 ( (struct V_47 * ) V_47 , V_52 , & V_55 ,
V_64 ) ;
if ( V_61 == - V_63 || V_61 == - V_65 )
return - V_63 ;
if ( V_61 < 0 )
return V_61 ;
if ( V_61 < sizeof( V_57 ) )
return - V_66 ;
V_59 -> V_57 = V_57 = F_30 ( V_55 . V_57 ) ;
switch ( V_57 & V_67 ) {
case V_68 :
if ( V_61 != V_69 )
return - V_66 ;
V_60 = V_70 ;
break;
case V_71 :
if ( V_61 != V_72 )
return - V_66 ;
V_60 = V_73 ;
break;
default:
return - V_66 ;
}
F_28 (i) {
if ( V_56 >= V_60 )
break;
V_59 -> V_37 . V_8 [ V_56 ] = F_30 ( V_55 . V_74 [ V_56 ] . V_37 ) ;
V_59 -> V_36 . V_8 [ V_56 ] = F_30 ( V_55 . V_74 [ V_56 ] . V_36 ) ;
}
return 0 ;
}
static int F_31 ( struct V_45 * V_46 , bool * V_35 )
{
struct V_47 * V_47 ;
int V_75 = 0 ;
struct V_54 V_76 ;
F_23 ( V_46 ) ;
if ( ! V_77 )
return 0 ;
if ( V_46 -> V_78 -> V_79 -> V_80 & V_81 )
return 0 ;
V_47 = F_32 ( V_46 -> V_78 -> V_82 ) ;
V_75 = F_29 ( V_47 , & V_76 ) ;
if ( V_75 < 0 ) {
if ( V_75 == - V_66 )
F_2 ( V_83 L_4 ,
V_84 , V_75 , V_46 -> V_85 ) ;
else if ( V_75 == - V_63 )
V_75 = 0 ;
goto V_31;
}
V_75 = F_27 ( & V_76 , V_46 , V_35 ) ;
if ( V_75 == - V_66 )
F_2 ( V_83 L_5 ,
V_84 , V_75 , V_46 -> V_85 ) ;
V_31:
F_33 ( V_47 ) ;
if ( V_75 )
F_23 ( V_46 ) ;
return V_75 ;
}
int F_34 ( struct V_45 * V_46 )
{
const struct V_12 * V_43 = F_12 () ;
struct V_12 * V_42 = V_46 -> V_12 ;
bool V_35 ;
int V_28 ;
V_35 = false ;
V_28 = F_31 ( V_46 , & V_35 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ! F_35 ( V_86 ) ) {
if ( V_35 && V_42 -> V_87 != 0 && V_42 -> V_88 == 0 ) {
F_1 ( V_46 -> V_85 ) ;
goto V_89;
}
if ( V_42 -> V_88 == 0 || V_42 -> V_87 == 0 ) {
V_42 -> V_30 = F_22 ( V_43 -> V_44 ,
V_43 -> V_38 ) ;
}
if ( V_42 -> V_88 == 0 )
V_35 = true ;
}
V_89:
if ( ( V_42 -> V_88 != V_43 -> V_87 ||
V_42 -> V_90 != V_43 -> V_91 ||
! F_14 ( V_42 -> V_30 , V_43 -> V_30 ) ) &&
V_46 -> V_92 & ~ V_93 ) {
if ( ! F_9 ( V_94 ) ) {
V_42 -> V_88 = V_42 -> V_87 ;
V_42 -> V_90 = V_42 -> V_91 ;
}
V_42 -> V_30 = F_36 ( V_42 -> V_30 ,
V_43 -> V_30 ) ;
}
V_42 -> V_95 = V_42 -> V_96 = V_42 -> V_88 ;
V_42 -> V_97 = V_42 -> V_98 = V_42 -> V_90 ;
if ( V_35 )
V_42 -> V_20 = V_42 -> V_30 ;
else
F_24 ( V_42 -> V_20 ) ;
V_46 -> V_20 = V_35 ;
if ( ! F_37 ( V_42 -> V_20 ) ) {
if ( ! F_14 ( V_99 , V_42 -> V_20 ) ||
V_42 -> V_88 != 0 || V_42 -> V_87 != 0 ||
F_35 ( V_86 ) ) {
V_28 = F_38 ( V_46 , V_42 , V_43 ) ;
if ( V_28 < 0 )
return V_28 ;
}
}
V_42 -> V_100 &= ~ F_39 ( V_101 ) ;
return 0 ;
}
int F_40 ( struct V_45 * V_46 )
{
const struct V_12 * V_12 = F_12 () ;
if ( V_12 -> V_87 != 0 ) {
if ( V_46 -> V_20 )
return 1 ;
if ( ! F_37 ( V_12 -> V_30 ) )
return 1 ;
}
return ( V_12 -> V_88 != V_12 -> V_87 ||
V_12 -> V_90 != V_12 -> V_91 ) ;
}
int F_41 ( struct V_47 * V_47 , const char * V_102 ,
const void * V_103 , T_3 V_61 , int V_104 )
{
if ( ! strcmp ( V_102 , V_52 ) ) {
if ( ! F_9 ( V_105 ) )
return - V_9 ;
return 0 ;
}
if ( ! strncmp ( V_102 , V_106 ,
sizeof( V_106 ) - 1 ) &&
! F_9 ( V_107 ) )
return - V_9 ;
return 0 ;
}
int F_42 ( struct V_47 * V_47 , const char * V_102 )
{
if ( ! strcmp ( V_102 , V_52 ) ) {
if ( ! F_9 ( V_105 ) )
return - V_9 ;
return 0 ;
}
if ( ! strncmp ( V_102 , V_106 ,
sizeof( V_106 ) - 1 ) &&
! F_9 ( V_107 ) )
return - V_9 ;
return 0 ;
}
static inline void F_43 ( struct V_12 * V_42 , const struct V_12 * V_43 )
{
if ( ( V_43 -> V_87 == 0 || V_43 -> V_88 == 0 || V_43 -> V_95 == 0 ) &&
( V_42 -> V_87 != 0 && V_42 -> V_88 != 0 && V_42 -> V_95 != 0 ) &&
! F_35 ( V_101 ) ) {
F_24 ( V_42 -> V_30 ) ;
F_24 ( V_42 -> V_20 ) ;
}
if ( V_43 -> V_88 == 0 && V_42 -> V_88 != 0 )
F_24 ( V_42 -> V_20 ) ;
if ( V_43 -> V_88 != 0 && V_42 -> V_88 == 0 )
V_42 -> V_20 = V_42 -> V_30 ;
}
int F_44 ( struct V_12 * V_42 , const struct V_12 * V_43 , int V_104 )
{
switch ( V_104 ) {
case V_108 :
case V_109 :
case V_110 :
if ( ! F_35 ( V_111 ) )
F_43 ( V_42 , V_43 ) ;
break;
case V_112 :
if ( ! F_35 ( V_111 ) ) {
if ( V_43 -> V_96 == 0 && V_42 -> V_96 != 0 )
V_42 -> V_20 =
F_45 ( V_42 -> V_20 ) ;
if ( V_43 -> V_96 != 0 && V_42 -> V_96 == 0 )
V_42 -> V_20 =
F_46 ( V_42 -> V_20 ,
V_42 -> V_30 ) ;
}
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_47 ( struct V_10 * V_113 )
{
int V_114 ;
F_11 () ;
V_114 = F_14 ( F_13 ( V_113 ) -> V_30 ,
F_12 () -> V_30 ) ;
F_16 () ;
if ( ! V_114 && ! F_9 ( V_115 ) )
return - V_9 ;
return 0 ;
}
int F_48 ( struct V_10 * V_113 )
{
return F_47 ( V_113 ) ;
}
int F_49 ( struct V_10 * V_113 , int V_116 )
{
return F_47 ( V_113 ) ;
}
int F_50 ( struct V_10 * V_113 , int V_117 )
{
return F_47 ( V_113 ) ;
}
static long F_51 ( struct V_12 * V_42 , unsigned long V_8 )
{
if ( ! F_9 ( V_40 ) )
return - V_9 ;
if ( ! F_52 ( V_8 ) )
return - V_66 ;
F_53 ( V_42 -> V_44 , V_8 ) ;
return 0 ;
}
int F_54 ( int V_118 , unsigned long V_119 , unsigned long V_120 ,
unsigned long V_121 , unsigned long V_122 )
{
struct V_12 * V_42 ;
long error = 0 ;
V_42 = F_55 () ;
if ( ! V_42 )
return - V_123 ;
switch ( V_118 ) {
case V_124 :
error = - V_66 ;
if ( ! F_52 ( V_119 ) )
goto error;
error = ! ! F_5 ( V_42 -> V_44 , V_119 ) ;
goto V_125;
case V_126 :
error = F_51 ( V_42 , V_119 ) ;
if ( error < 0 )
goto error;
goto V_127;
case V_128 :
error = - V_9 ;
if ( ( ( ( V_42 -> V_100 & V_129 ) >> 1 )
& ( V_42 -> V_100 ^ V_119 ) )
|| ( ( V_42 -> V_100 & V_129 & ~ V_119 ) )
|| ( V_119 & ~ ( V_129 | V_130 ) )
|| ( F_7 ( V_39 , F_12 () ,
F_12 () -> V_18 -> V_19 , V_40 ,
V_41 ) != 0 )
)
goto error;
V_42 -> V_100 = V_119 ;
goto V_127;
case V_131 :
error = V_42 -> V_100 ;
goto V_125;
case V_132 :
if ( F_35 ( V_101 ) )
error = 1 ;
goto V_125;
case V_133 :
error = - V_66 ;
if ( V_119 > 1 )
goto error;
error = - V_9 ;
if ( F_35 ( V_134 ) )
goto error;
if ( V_119 )
V_42 -> V_100 |= F_39 ( V_101 ) ;
else
V_42 -> V_100 &= ~ F_39 ( V_101 ) ;
goto V_127;
default:
error = - V_135 ;
goto error;
}
V_127:
return F_56 ( V_42 ) ;
V_125:
error:
F_57 ( V_42 ) ;
return error ;
}
int F_58 ( struct V_136 * V_137 , long V_138 )
{
int V_139 = 0 ;
if ( F_7 ( V_39 , F_12 () , & V_16 , V_107 ,
V_140 ) == 0 )
V_139 = 1 ;
return F_59 ( V_137 , V_138 , V_139 ) ;
}
int F_60 ( struct V_78 * V_78 , unsigned long V_141 ,
unsigned long V_142 , unsigned long V_104 ,
unsigned long V_143 , unsigned long V_144 )
{
int V_28 = 0 ;
if ( V_143 < V_145 ) {
V_28 = F_7 ( V_39 , F_12 () , & V_16 , V_146 ,
V_41 ) ;
if ( V_28 == 0 )
V_39 -> V_104 |= V_147 ;
}
return V_28 ;
}
