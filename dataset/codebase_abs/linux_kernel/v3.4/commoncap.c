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
for (; ; ) {
if ( V_10 != & V_13 && V_10 -> V_14 == V_8 -> V_15 )
return 0 ;
if ( V_10 == V_8 -> V_15 -> V_16 )
return F_5 ( V_8 -> V_17 , V_11 ) ? 0 : - V_18 ;
if ( V_10 == & V_13 )
return - V_18 ;
V_10 = V_10 -> V_14 -> V_16 ;
}
}
int F_6 ( const struct V_19 * V_20 , const struct V_21 * V_22 )
{
if ( ! F_7 ( V_23 ) )
return - V_18 ;
return 0 ;
}
int F_8 ( struct V_24 * V_25 , unsigned int V_26 )
{
int V_27 = 0 ;
const struct V_8 * V_8 , * V_28 ;
F_9 () ;
V_8 = F_10 () ;
V_28 = F_11 ( V_25 ) ;
if ( V_8 -> V_15 -> V_16 == V_28 -> V_15 -> V_16 &&
F_12 ( V_28 -> V_29 , V_8 -> V_29 ) )
goto V_30;
if ( F_13 ( V_28 -> V_15 -> V_16 , V_31 ) )
goto V_30;
V_27 = - V_18 ;
V_30:
F_14 () ;
return V_27 ;
}
int F_15 ( struct V_24 * V_32 )
{
int V_27 = 0 ;
const struct V_8 * V_8 , * V_28 ;
F_9 () ;
V_8 = F_11 ( V_32 ) ;
V_28 = F_10 () ;
if ( V_8 -> V_15 -> V_16 == V_28 -> V_15 -> V_16 &&
F_12 ( V_28 -> V_29 , V_8 -> V_29 ) )
goto V_30;
if ( F_16 ( V_32 , V_28 -> V_15 -> V_16 , V_31 ) )
goto V_30;
V_27 = - V_18 ;
V_30:
F_14 () ;
return V_27 ;
}
int F_17 ( struct V_24 * V_33 , T_1 * V_34 ,
T_1 * V_35 , T_1 * V_36 )
{
const struct V_8 * V_8 ;
F_9 () ;
V_8 = F_11 ( V_33 ) ;
* V_34 = V_8 -> V_17 ;
* V_35 = V_8 -> V_37 ;
* V_36 = V_8 -> V_29 ;
F_14 () ;
return 0 ;
}
static inline int F_18 ( void )
{
if ( F_4 ( F_10 () , F_10 () -> V_15 -> V_16 ,
V_38 , V_39 ) == 0 )
return 0 ;
return 1 ;
}
int F_19 ( struct V_8 * V_40 ,
const struct V_8 * V_41 ,
const T_1 * V_34 ,
const T_1 * V_35 ,
const T_1 * V_36 )
{
if ( F_18 () &&
! F_12 ( * V_35 ,
F_20 ( V_41 -> V_37 ,
V_41 -> V_29 ) ) )
return - V_18 ;
if ( ! F_12 ( * V_35 ,
F_20 ( V_41 -> V_37 ,
V_41 -> V_42 ) ) )
return - V_18 ;
if ( ! F_12 ( * V_36 , V_41 -> V_29 ) )
return - V_18 ;
if ( ! F_12 ( * V_34 , * V_36 ) )
return - V_18 ;
V_40 -> V_17 = * V_34 ;
V_40 -> V_37 = * V_35 ;
V_40 -> V_29 = * V_36 ;
return 0 ;
}
static inline void F_21 ( struct V_43 * V_44 )
{
F_22 ( V_44 -> V_8 -> V_29 ) ;
V_44 -> V_17 = false ;
}
int F_23 ( struct V_45 * V_45 )
{
struct V_46 * V_46 = V_45 -> V_47 ;
int error ;
if ( ! V_46 -> V_48 -> V_49 )
return 0 ;
error = V_46 -> V_48 -> V_49 ( V_45 , V_50 , NULL , 0 ) ;
if ( error <= 0 )
return 0 ;
return 1 ;
}
int F_24 ( struct V_45 * V_45 )
{
struct V_46 * V_46 = V_45 -> V_47 ;
if ( ! V_46 -> V_48 -> V_51 )
return 0 ;
return V_46 -> V_48 -> V_51 ( V_45 , V_50 ) ;
}
static inline int F_25 ( struct V_52 * V_53 ,
struct V_43 * V_44 ,
bool * V_34 ,
bool * V_54 )
{
struct V_8 * V_40 = V_44 -> V_8 ;
unsigned V_55 ;
int V_27 = 0 ;
if ( V_53 -> V_56 & V_57 )
* V_34 = true ;
if ( V_53 -> V_56 & V_58 )
* V_54 = true ;
F_26 (i) {
T_2 V_36 = V_53 -> V_36 . V_11 [ V_55 ] ;
T_2 V_35 = V_53 -> V_35 . V_11 [ V_55 ] ;
V_40 -> V_29 . V_11 [ V_55 ] =
( V_40 -> V_42 . V_11 [ V_55 ] & V_36 ) |
( V_40 -> V_37 . V_11 [ V_55 ] & V_35 ) ;
if ( V_36 & ~ V_40 -> V_29 . V_11 [ V_55 ] )
V_27 = - V_18 ;
}
return * V_34 ? V_27 : 0 ;
}
int F_27 ( const struct V_45 * V_45 , struct V_52 * V_59 )
{
struct V_46 * V_46 = V_45 -> V_47 ;
T_2 V_56 ;
unsigned V_60 , V_55 ;
int V_61 ;
struct V_62 V_53 ;
memset ( V_59 , 0 , sizeof( struct V_52 ) ) ;
if ( ! V_46 || ! V_46 -> V_48 -> V_49 )
return - V_63 ;
V_61 = V_46 -> V_48 -> V_49 ( (struct V_45 * ) V_45 , V_50 , & V_53 ,
V_64 ) ;
if ( V_61 == - V_63 || V_61 == - V_65 )
return - V_63 ;
if ( V_61 < 0 )
return V_61 ;
if ( V_61 < sizeof( V_56 ) )
return - V_66 ;
V_59 -> V_56 = V_56 = F_28 ( V_53 . V_56 ) ;
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
F_26 (i) {
if ( V_55 >= V_60 )
break;
V_59 -> V_36 . V_11 [ V_55 ] = F_28 ( V_53 . V_73 [ V_55 ] . V_36 ) ;
V_59 -> V_35 . V_11 [ V_55 ] = F_28 ( V_53 . V_73 [ V_55 ] . V_35 ) ;
}
return 0 ;
}
static int F_29 ( struct V_43 * V_44 , bool * V_34 , bool * V_54 )
{
struct V_45 * V_45 ;
int V_74 = 0 ;
struct V_52 V_75 ;
F_21 ( V_44 ) ;
if ( ! V_76 )
return 0 ;
if ( V_44 -> V_77 -> V_78 -> V_79 & V_80 )
return 0 ;
V_45 = F_30 ( V_44 -> V_77 -> V_81 ) ;
V_74 = F_27 ( V_45 , & V_75 ) ;
if ( V_74 < 0 ) {
if ( V_74 == - V_66 )
F_2 ( V_82 L_4 ,
V_83 , V_74 , V_44 -> V_84 ) ;
else if ( V_74 == - V_63 )
V_74 = 0 ;
goto V_30;
}
V_74 = F_25 ( & V_75 , V_44 , V_34 , V_54 ) ;
if ( V_74 == - V_66 )
F_2 ( V_82 L_5 ,
V_83 , V_74 , V_44 -> V_84 ) ;
V_30:
F_31 ( V_45 ) ;
if ( V_74 )
F_21 ( V_44 ) ;
return V_74 ;
}
int F_32 ( struct V_43 * V_44 )
{
const struct V_8 * V_41 = F_10 () ;
struct V_8 * V_40 = V_44 -> V_8 ;
bool V_34 , V_54 = false ;
int V_27 ;
V_34 = false ;
V_27 = F_29 ( V_44 , & V_34 , & V_54 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! F_33 ( V_85 ) ) {
if ( V_54 && V_40 -> V_86 != 0 && V_40 -> V_87 == 0 ) {
F_1 ( V_44 -> V_84 ) ;
goto V_88;
}
if ( V_40 -> V_87 == 0 || V_40 -> V_86 == 0 ) {
V_40 -> V_29 = F_20 ( V_41 -> V_42 ,
V_41 -> V_37 ) ;
}
if ( V_40 -> V_87 == 0 )
V_34 = true ;
}
V_88:
if ( ! F_12 ( V_40 -> V_29 , V_41 -> V_29 ) )
V_44 -> V_89 |= V_90 ;
if ( ( V_40 -> V_87 != V_41 -> V_86 ||
V_40 -> V_91 != V_41 -> V_92 ||
! F_12 ( V_40 -> V_29 , V_41 -> V_29 ) ) &&
V_44 -> V_93 & ~ V_94 ) {
if ( ! F_7 ( V_95 ) ) {
V_40 -> V_87 = V_40 -> V_86 ;
V_40 -> V_91 = V_40 -> V_92 ;
}
V_40 -> V_29 = F_34 ( V_40 -> V_29 ,
V_41 -> V_29 ) ;
}
V_40 -> V_96 = V_40 -> V_97 = V_40 -> V_87 ;
V_40 -> V_98 = V_40 -> V_99 = V_40 -> V_91 ;
if ( V_34 )
V_40 -> V_17 = V_40 -> V_29 ;
else
F_22 ( V_40 -> V_17 ) ;
V_44 -> V_17 = V_34 ;
if ( ! F_35 ( V_40 -> V_17 ) ) {
if ( ! F_12 ( V_100 , V_40 -> V_17 ) ||
V_40 -> V_87 != 0 || V_40 -> V_86 != 0 ||
F_33 ( V_85 ) ) {
V_27 = F_36 ( V_44 , V_40 , V_41 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
V_40 -> V_101 &= ~ F_37 ( V_102 ) ;
return 0 ;
}
int F_38 ( struct V_43 * V_44 )
{
const struct V_8 * V_8 = F_10 () ;
if ( V_8 -> V_86 != 0 ) {
if ( V_44 -> V_17 )
return 1 ;
if ( ! F_35 ( V_8 -> V_29 ) )
return 1 ;
}
return ( V_8 -> V_87 != V_8 -> V_86 ||
V_8 -> V_91 != V_8 -> V_92 ) ;
}
int F_39 ( struct V_45 * V_45 , const char * V_103 ,
const void * V_104 , T_3 V_61 , int V_105 )
{
if ( ! strcmp ( V_103 , V_50 ) ) {
if ( ! F_7 ( V_106 ) )
return - V_18 ;
return 0 ;
}
if ( ! strncmp ( V_103 , V_107 ,
sizeof( V_107 ) - 1 ) &&
! F_7 ( V_108 ) )
return - V_18 ;
return 0 ;
}
int F_40 ( struct V_45 * V_45 , const char * V_103 )
{
if ( ! strcmp ( V_103 , V_50 ) ) {
if ( ! F_7 ( V_106 ) )
return - V_18 ;
return 0 ;
}
if ( ! strncmp ( V_103 , V_107 ,
sizeof( V_107 ) - 1 ) &&
! F_7 ( V_108 ) )
return - V_18 ;
return 0 ;
}
static inline void F_41 ( struct V_8 * V_40 , const struct V_8 * V_41 )
{
if ( ( V_41 -> V_86 == 0 || V_41 -> V_87 == 0 || V_41 -> V_96 == 0 ) &&
( V_40 -> V_86 != 0 && V_40 -> V_87 != 0 && V_40 -> V_96 != 0 ) &&
! F_33 ( V_102 ) ) {
F_22 ( V_40 -> V_29 ) ;
F_22 ( V_40 -> V_17 ) ;
}
if ( V_41 -> V_87 == 0 && V_40 -> V_87 != 0 )
F_22 ( V_40 -> V_17 ) ;
if ( V_41 -> V_87 != 0 && V_40 -> V_87 == 0 )
V_40 -> V_17 = V_40 -> V_29 ;
}
int F_42 ( struct V_8 * V_40 , const struct V_8 * V_41 , int V_105 )
{
switch ( V_105 ) {
case V_109 :
case V_110 :
case V_111 :
if ( ! F_33 ( V_112 ) )
F_41 ( V_40 , V_41 ) ;
break;
case V_113 :
if ( ! F_33 ( V_112 ) ) {
if ( V_41 -> V_97 == 0 && V_40 -> V_97 != 0 )
V_40 -> V_17 =
F_43 ( V_40 -> V_17 ) ;
if ( V_41 -> V_97 != 0 && V_40 -> V_97 == 0 )
V_40 -> V_17 =
F_44 ( V_40 -> V_17 ,
V_40 -> V_29 ) ;
}
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_45 ( struct V_24 * V_114 )
{
int V_115 ;
F_9 () ;
V_115 = F_12 ( F_11 ( V_114 ) -> V_29 ,
F_10 () -> V_29 ) ;
F_14 () ;
if ( ! V_115 && ! F_7 ( V_116 ) )
return - V_18 ;
return 0 ;
}
int F_46 ( struct V_24 * V_114 )
{
return F_45 ( V_114 ) ;
}
int F_47 ( struct V_24 * V_114 , int V_117 )
{
return F_45 ( V_114 ) ;
}
int F_48 ( struct V_24 * V_114 , int V_118 )
{
return F_45 ( V_114 ) ;
}
static long F_49 ( struct V_8 * V_40 , unsigned long V_11 )
{
if ( ! F_7 ( V_38 ) )
return - V_18 ;
if ( ! F_50 ( V_11 ) )
return - V_66 ;
F_51 ( V_40 -> V_42 , V_11 ) ;
return 0 ;
}
int F_52 ( int V_119 , unsigned long V_120 , unsigned long V_121 ,
unsigned long V_122 , unsigned long V_123 )
{
struct V_8 * V_40 ;
long error = 0 ;
V_40 = F_53 () ;
if ( ! V_40 )
return - V_124 ;
switch ( V_119 ) {
case V_125 :
error = - V_66 ;
if ( ! F_50 ( V_120 ) )
goto error;
error = ! ! F_5 ( V_40 -> V_42 , V_120 ) ;
goto V_126;
case V_127 :
error = F_49 ( V_40 , V_120 ) ;
if ( error < 0 )
goto error;
goto V_128;
case V_129 :
error = - V_18 ;
if ( ( ( ( V_40 -> V_101 & V_130 ) >> 1 )
& ( V_40 -> V_101 ^ V_120 ) )
|| ( ( V_40 -> V_101 & V_130 & ~ V_120 ) )
|| ( V_120 & ~ ( V_130 | V_131 ) )
|| ( F_4 ( F_10 () ,
F_10 () -> V_15 -> V_16 , V_38 ,
V_39 ) != 0 )
)
goto error;
V_40 -> V_101 = V_120 ;
goto V_128;
case V_132 :
error = V_40 -> V_101 ;
goto V_126;
case V_133 :
if ( F_33 ( V_102 ) )
error = 1 ;
goto V_126;
case V_134 :
error = - V_66 ;
if ( V_120 > 1 )
goto error;
error = - V_18 ;
if ( F_33 ( V_135 ) )
goto error;
if ( V_120 )
V_40 -> V_101 |= F_37 ( V_102 ) ;
else
V_40 -> V_101 &= ~ F_37 ( V_102 ) ;
goto V_128;
default:
error = - V_136 ;
goto error;
}
V_128:
return F_54 ( V_40 ) ;
V_126:
error:
F_55 ( V_40 ) ;
return error ;
}
int F_56 ( struct V_137 * V_138 , long V_139 )
{
int V_140 = 0 ;
if ( F_4 ( F_10 () , & V_13 , V_108 ,
V_141 ) == 0 )
V_140 = 1 ;
return F_57 ( V_138 , V_139 , V_140 ) ;
}
int F_58 ( struct V_77 * V_77 , unsigned long V_142 ,
unsigned long V_143 , unsigned long V_105 ,
unsigned long V_144 , unsigned long V_145 )
{
int V_27 = 0 ;
if ( V_144 < V_146 ) {
V_27 = F_4 ( F_10 () , & V_13 , V_147 ,
V_39 ) ;
if ( V_27 == 0 )
V_148 -> V_105 |= V_149 ;
}
return V_27 ;
}
