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
if ( V_10 != & V_13 && F_5 ( V_10 -> V_14 , V_8 -> V_15 ) )
return 0 ;
if ( V_10 == V_8 -> V_16 )
return F_6 ( V_8 -> V_17 , V_11 ) ? 0 : - V_18 ;
if ( V_10 == & V_13 )
return - V_18 ;
V_10 = V_10 -> V_19 ;
}
}
int F_7 ( const struct V_20 * V_21 , const struct V_22 * V_23 )
{
if ( ! F_8 ( V_24 ) )
return - V_18 ;
return 0 ;
}
int F_9 ( struct V_25 * V_26 , unsigned int V_27 )
{
int V_28 = 0 ;
const struct V_8 * V_8 , * V_29 ;
F_10 () ;
V_8 = F_11 () ;
V_29 = F_12 ( V_26 ) ;
if ( V_8 -> V_16 == V_29 -> V_16 &&
F_13 ( V_29 -> V_30 , V_8 -> V_30 ) )
goto V_31;
if ( F_14 ( V_29 -> V_16 , V_32 ) )
goto V_31;
V_28 = - V_18 ;
V_31:
F_15 () ;
return V_28 ;
}
int F_16 ( struct V_25 * V_19 )
{
int V_28 = 0 ;
const struct V_8 * V_8 , * V_29 ;
F_10 () ;
V_8 = F_12 ( V_19 ) ;
V_29 = F_11 () ;
if ( V_8 -> V_16 == V_29 -> V_16 &&
F_13 ( V_29 -> V_30 , V_8 -> V_30 ) )
goto V_31;
if ( F_17 ( V_19 , V_29 -> V_16 , V_32 ) )
goto V_31;
V_28 = - V_18 ;
V_31:
F_15 () ;
return V_28 ;
}
int F_18 ( struct V_25 * V_33 , T_1 * V_34 ,
T_1 * V_35 , T_1 * V_36 )
{
const struct V_8 * V_8 ;
F_10 () ;
V_8 = F_12 ( V_33 ) ;
* V_34 = V_8 -> V_17 ;
* V_35 = V_8 -> V_37 ;
* V_36 = V_8 -> V_30 ;
F_15 () ;
return 0 ;
}
static inline int F_19 ( void )
{
if ( F_4 ( F_11 () , F_11 () -> V_16 ,
V_38 , V_39 ) == 0 )
return 0 ;
return 1 ;
}
int F_20 ( struct V_8 * V_40 ,
const struct V_8 * V_41 ,
const T_1 * V_34 ,
const T_1 * V_35 ,
const T_1 * V_36 )
{
if ( F_19 () &&
! F_13 ( * V_35 ,
F_21 ( V_41 -> V_37 ,
V_41 -> V_30 ) ) )
return - V_18 ;
if ( ! F_13 ( * V_35 ,
F_21 ( V_41 -> V_37 ,
V_41 -> V_42 ) ) )
return - V_18 ;
if ( ! F_13 ( * V_36 , V_41 -> V_30 ) )
return - V_18 ;
if ( ! F_13 ( * V_34 , * V_36 ) )
return - V_18 ;
V_40 -> V_17 = * V_34 ;
V_40 -> V_37 = * V_35 ;
V_40 -> V_30 = * V_36 ;
return 0 ;
}
static inline void F_22 ( struct V_43 * V_44 )
{
F_23 ( V_44 -> V_8 -> V_30 ) ;
V_44 -> V_17 = false ;
}
int F_24 ( struct V_45 * V_45 )
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
int F_25 ( struct V_45 * V_45 )
{
struct V_46 * V_46 = V_45 -> V_47 ;
if ( ! V_46 -> V_48 -> V_51 )
return 0 ;
return V_46 -> V_48 -> V_51 ( V_45 , V_50 ) ;
}
static inline int F_26 ( struct V_52 * V_53 ,
struct V_43 * V_44 ,
bool * V_34 ,
bool * V_54 )
{
struct V_8 * V_40 = V_44 -> V_8 ;
unsigned V_55 ;
int V_28 = 0 ;
if ( V_53 -> V_56 & V_57 )
* V_34 = true ;
if ( V_53 -> V_56 & V_58 )
* V_54 = true ;
F_27 (i) {
T_2 V_36 = V_53 -> V_36 . V_11 [ V_55 ] ;
T_2 V_35 = V_53 -> V_35 . V_11 [ V_55 ] ;
V_40 -> V_30 . V_11 [ V_55 ] =
( V_40 -> V_42 . V_11 [ V_55 ] & V_36 ) |
( V_40 -> V_37 . V_11 [ V_55 ] & V_35 ) ;
if ( V_36 & ~ V_40 -> V_30 . V_11 [ V_55 ] )
V_28 = - V_18 ;
}
return * V_34 ? V_28 : 0 ;
}
int F_28 ( const struct V_45 * V_45 , struct V_52 * V_59 )
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
V_59 -> V_56 = V_56 = F_29 ( V_53 . V_56 ) ;
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
F_27 (i) {
if ( V_55 >= V_60 )
break;
V_59 -> V_36 . V_11 [ V_55 ] = F_29 ( V_53 . V_73 [ V_55 ] . V_36 ) ;
V_59 -> V_35 . V_11 [ V_55 ] = F_29 ( V_53 . V_73 [ V_55 ] . V_35 ) ;
}
return 0 ;
}
static int F_30 ( struct V_43 * V_44 , bool * V_34 , bool * V_54 )
{
struct V_45 * V_45 ;
int V_74 = 0 ;
struct V_52 V_75 ;
F_22 ( V_44 ) ;
if ( ! V_76 )
return 0 ;
if ( V_44 -> V_77 -> V_78 -> V_79 & V_80 )
return 0 ;
V_45 = F_31 ( V_44 -> V_77 -> V_81 ) ;
V_74 = F_28 ( V_45 , & V_75 ) ;
if ( V_74 < 0 ) {
if ( V_74 == - V_66 )
F_2 ( V_82 L_4 ,
V_83 , V_74 , V_44 -> V_84 ) ;
else if ( V_74 == - V_63 )
V_74 = 0 ;
goto V_31;
}
V_74 = F_26 ( & V_75 , V_44 , V_34 , V_54 ) ;
if ( V_74 == - V_66 )
F_2 ( V_82 L_5 ,
V_83 , V_74 , V_44 -> V_84 ) ;
V_31:
F_32 ( V_45 ) ;
if ( V_74 )
F_22 ( V_44 ) ;
return V_74 ;
}
int F_33 ( struct V_43 * V_44 )
{
const struct V_8 * V_41 = F_11 () ;
struct V_8 * V_40 = V_44 -> V_8 ;
bool V_34 , V_54 = false ;
int V_28 ;
T_3 V_85 ;
V_34 = false ;
V_28 = F_30 ( V_44 , & V_34 , & V_54 ) ;
if ( V_28 < 0 )
return V_28 ;
V_85 = F_34 ( V_40 -> V_16 , 0 ) ;
if ( ! F_35 ( V_86 ) ) {
if ( V_54 && ! F_5 ( V_40 -> V_87 , V_85 ) && F_5 ( V_40 -> V_15 , V_85 ) ) {
F_1 ( V_44 -> V_84 ) ;
goto V_88;
}
if ( F_5 ( V_40 -> V_15 , V_85 ) || F_5 ( V_40 -> V_87 , V_85 ) ) {
V_40 -> V_30 = F_21 ( V_41 -> V_42 ,
V_41 -> V_37 ) ;
}
if ( F_5 ( V_40 -> V_15 , V_85 ) )
V_34 = true ;
}
V_88:
if ( ! F_13 ( V_40 -> V_30 , V_41 -> V_30 ) )
V_44 -> V_89 |= V_90 ;
if ( ( ! F_5 ( V_40 -> V_15 , V_41 -> V_87 ) ||
! F_36 ( V_40 -> V_91 , V_41 -> V_92 ) ||
! F_13 ( V_40 -> V_30 , V_41 -> V_30 ) ) &&
V_44 -> V_93 & ~ V_94 ) {
if ( ! F_8 ( V_95 ) ||
( V_44 -> V_93 & V_96 ) ) {
V_40 -> V_15 = V_40 -> V_87 ;
V_40 -> V_91 = V_40 -> V_92 ;
}
V_40 -> V_30 = F_37 ( V_40 -> V_30 ,
V_41 -> V_30 ) ;
}
V_40 -> V_97 = V_40 -> V_98 = V_40 -> V_15 ;
V_40 -> V_99 = V_40 -> V_100 = V_40 -> V_91 ;
if ( V_34 )
V_40 -> V_17 = V_40 -> V_30 ;
else
F_23 ( V_40 -> V_17 ) ;
V_44 -> V_17 = V_34 ;
if ( ! F_38 ( V_40 -> V_17 ) ) {
if ( ! F_13 ( V_101 , V_40 -> V_17 ) ||
! F_5 ( V_40 -> V_15 , V_85 ) || ! F_5 ( V_40 -> V_87 , V_85 ) ||
F_35 ( V_86 ) ) {
V_28 = F_39 ( V_44 , V_40 , V_41 ) ;
if ( V_28 < 0 )
return V_28 ;
}
}
V_40 -> V_102 &= ~ F_40 ( V_103 ) ;
return 0 ;
}
int F_41 ( struct V_43 * V_44 )
{
const struct V_8 * V_8 = F_11 () ;
T_3 V_85 = F_34 ( V_8 -> V_16 , 0 ) ;
if ( ! F_5 ( V_8 -> V_87 , V_85 ) ) {
if ( V_44 -> V_17 )
return 1 ;
if ( ! F_38 ( V_8 -> V_30 ) )
return 1 ;
}
return ( ! F_5 ( V_8 -> V_15 , V_8 -> V_87 ) ||
! F_36 ( V_8 -> V_91 , V_8 -> V_92 ) ) ;
}
int F_42 ( struct V_45 * V_45 , const char * V_104 ,
const void * V_105 , T_4 V_61 , int V_106 )
{
if ( ! strcmp ( V_104 , V_50 ) ) {
if ( ! F_8 ( V_107 ) )
return - V_18 ;
return 0 ;
}
if ( ! strncmp ( V_104 , V_108 ,
sizeof( V_108 ) - 1 ) &&
! F_8 ( V_109 ) )
return - V_18 ;
return 0 ;
}
int F_43 ( struct V_45 * V_45 , const char * V_104 )
{
if ( ! strcmp ( V_104 , V_50 ) ) {
if ( ! F_8 ( V_107 ) )
return - V_18 ;
return 0 ;
}
if ( ! strncmp ( V_104 , V_108 ,
sizeof( V_108 ) - 1 ) &&
! F_8 ( V_109 ) )
return - V_18 ;
return 0 ;
}
static inline void F_44 ( struct V_8 * V_40 , const struct V_8 * V_41 )
{
T_3 V_85 = F_34 ( V_41 -> V_16 , 0 ) ;
if ( ( F_5 ( V_41 -> V_87 , V_85 ) ||
F_5 ( V_41 -> V_15 , V_85 ) ||
F_5 ( V_41 -> V_97 , V_85 ) ) &&
( ! F_5 ( V_40 -> V_87 , V_85 ) &&
! F_5 ( V_40 -> V_15 , V_85 ) &&
! F_5 ( V_40 -> V_97 , V_85 ) ) &&
! F_35 ( V_103 ) ) {
F_23 ( V_40 -> V_30 ) ;
F_23 ( V_40 -> V_17 ) ;
}
if ( F_5 ( V_41 -> V_15 , V_85 ) && ! F_5 ( V_40 -> V_15 , V_85 ) )
F_23 ( V_40 -> V_17 ) ;
if ( ! F_5 ( V_41 -> V_15 , V_85 ) && F_5 ( V_40 -> V_15 , V_85 ) )
V_40 -> V_17 = V_40 -> V_30 ;
}
int F_45 ( struct V_8 * V_40 , const struct V_8 * V_41 , int V_106 )
{
switch ( V_106 ) {
case V_110 :
case V_111 :
case V_112 :
if ( ! F_35 ( V_113 ) )
F_44 ( V_40 , V_41 ) ;
break;
case V_114 :
if ( ! F_35 ( V_113 ) ) {
T_3 V_85 = F_34 ( V_41 -> V_16 , 0 ) ;
if ( F_5 ( V_41 -> V_98 , V_85 ) && ! F_5 ( V_40 -> V_98 , V_85 ) )
V_40 -> V_17 =
F_46 ( V_40 -> V_17 ) ;
if ( ! F_5 ( V_41 -> V_98 , V_85 ) && F_5 ( V_40 -> V_98 , V_85 ) )
V_40 -> V_17 =
F_47 ( V_40 -> V_17 ,
V_40 -> V_30 ) ;
}
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_48 ( struct V_25 * V_115 )
{
int V_116 ;
F_10 () ;
V_116 = F_13 ( F_12 ( V_115 ) -> V_30 ,
F_11 () -> V_30 ) ;
F_15 () ;
if ( ! V_116 && ! F_8 ( V_117 ) )
return - V_18 ;
return 0 ;
}
int F_49 ( struct V_25 * V_115 )
{
return F_48 ( V_115 ) ;
}
int F_50 ( struct V_25 * V_115 , int V_118 )
{
return F_48 ( V_115 ) ;
}
int F_51 ( struct V_25 * V_115 , int V_119 )
{
return F_48 ( V_115 ) ;
}
static long F_52 ( struct V_8 * V_40 , unsigned long V_11 )
{
if ( ! F_8 ( V_38 ) )
return - V_18 ;
if ( ! F_53 ( V_11 ) )
return - V_66 ;
F_54 ( V_40 -> V_42 , V_11 ) ;
return 0 ;
}
int F_55 ( int V_120 , unsigned long V_121 , unsigned long V_122 ,
unsigned long V_123 , unsigned long V_124 )
{
struct V_8 * V_40 ;
long error = 0 ;
V_40 = F_56 () ;
if ( ! V_40 )
return - V_125 ;
switch ( V_120 ) {
case V_126 :
error = - V_66 ;
if ( ! F_53 ( V_121 ) )
goto error;
error = ! ! F_6 ( V_40 -> V_42 , V_121 ) ;
goto V_127;
case V_128 :
error = F_52 ( V_40 , V_121 ) ;
if ( error < 0 )
goto error;
goto V_129;
case V_130 :
error = - V_18 ;
if ( ( ( ( V_40 -> V_102 & V_131 ) >> 1 )
& ( V_40 -> V_102 ^ V_121 ) )
|| ( ( V_40 -> V_102 & V_131 & ~ V_121 ) )
|| ( V_121 & ~ ( V_131 | V_132 ) )
|| ( F_4 ( F_11 () ,
F_11 () -> V_16 , V_38 ,
V_39 ) != 0 )
)
goto error;
V_40 -> V_102 = V_121 ;
goto V_129;
case V_133 :
error = V_40 -> V_102 ;
goto V_127;
case V_134 :
if ( F_35 ( V_103 ) )
error = 1 ;
goto V_127;
case V_135 :
error = - V_66 ;
if ( V_121 > 1 )
goto error;
error = - V_18 ;
if ( F_35 ( V_136 ) )
goto error;
if ( V_121 )
V_40 -> V_102 |= F_40 ( V_103 ) ;
else
V_40 -> V_102 &= ~ F_40 ( V_103 ) ;
goto V_129;
default:
error = - V_137 ;
goto error;
}
V_129:
return F_57 ( V_40 ) ;
V_127:
error:
F_58 ( V_40 ) ;
return error ;
}
int F_59 ( struct V_138 * V_139 , long V_140 )
{
int V_141 = 0 ;
if ( F_4 ( F_11 () , & V_13 , V_109 ,
V_142 ) == 0 )
V_141 = 1 ;
return F_60 ( V_139 , V_140 , V_141 ) ;
}
int F_61 ( unsigned long V_143 )
{
int V_28 = 0 ;
if ( V_143 < V_144 ) {
V_28 = F_4 ( F_11 () , & V_13 , V_145 ,
V_39 ) ;
if ( V_28 == 0 )
V_146 -> V_106 |= V_147 ;
}
return V_28 ;
}
int F_62 ( struct V_77 * V_77 , unsigned long V_148 ,
unsigned long V_149 , unsigned long V_106 )
{
return 0 ;
}
