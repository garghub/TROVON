static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_7 ;
V_2 -> V_8 . V_9 = V_10 ;
if ( V_4 -> V_11 )
V_2 -> V_8 . V_9 = V_12 ;
V_7 = V_4 -> V_7 ;
if ( V_7 ) {
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
if ( ( V_7 >> V_6 ) & 0x1 )
break;
}
V_2 -> V_13 = V_6 ;
} else
V_2 -> V_13 = 0 ;
F_2 ( & V_2 -> V_14 -> V_15 , V_4 -> V_11 ) ;
F_3 ( & V_2 -> V_14 -> V_15 , V_2 -> V_13 ) ;
V_2 -> V_16 ( V_2 -> V_14 -> V_17 , V_2 -> V_8 . V_9 ) ;
}
static void
F_4 ( struct V_1 * V_2 , int V_5 )
{
V_2 -> V_8 . V_9 = V_18 ;
F_2 ( & V_2 -> V_14 -> V_15 , V_18 ) ;
V_2 -> V_16 ( V_2 -> V_14 -> V_17 , V_18 ) ;
}
static inline int
F_5 ( struct V_19 * V_8 )
{
int V_20 = 0 ;
if ( V_8 -> type == V_21 )
V_20 = ( ( V_8 -> V_22 & V_23 ) &&
( V_8 -> V_22 & V_24 ) &&
( V_8 -> V_22 & V_25 ) ) ;
else
V_20 = ( ( V_8 -> V_22 & V_23 ) &&
( V_8 -> V_22 & V_24 ) &&
! ( V_8 -> V_22 & V_25 ) ) ;
return V_20 ;
}
static void
F_6 ( struct V_19 * V_8 )
{
V_8 -> V_22 |= V_25 ;
if ( F_5 ( V_8 ) )
F_7 ( V_8 , V_26 ) ;
}
static void
F_8 ( struct V_19 * V_8 )
{
int V_27 = F_9 ( V_8 ) ;
V_8 -> V_22 &= ~ V_25 ;
if ( V_27 )
F_7 ( V_8 , V_28 ) ;
}
static int
F_10 ( T_1 V_29 )
{
switch ( V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
return 1 ;
default:
return 0 ;
}
}
static void
F_11 ( struct V_14 * V_14 , struct V_34 * V_35 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_35 ) ;
switch ( V_4 -> V_36 . V_29 ) {
case V_31 :
F_1 ( & V_14 -> V_2 , V_4 , V_4 -> V_37 ) ;
break;
case V_30 :
F_4 ( & V_14 -> V_2 , V_4 -> V_37 ) ;
break;
case V_32 :
F_6 ( & V_14 -> V_2 . V_8 ) ;
break;
case V_33 :
F_8 ( & V_14 -> V_2 . V_8 ) ;
break;
default:
break;
}
}
static void
F_12 ( void * V_38 , struct V_34 * V_35 )
{
struct V_14 * V_14 = (struct V_14 * ) ( V_38 ) ;
struct V_39 * V_40 = (struct V_39 * ) ( V_35 ) ;
struct V_41 * V_42 , * V_43 ;
struct V_44 * V_45 = NULL ;
int V_46 = 0 ;
T_1 V_4 = 0 ;
char V_47 [ V_48 ] ;
V_4 = F_10 ( V_40 -> V_36 . V_29 ) ;
if ( ! V_4 ) {
V_45 = F_13 ( & V_14 -> V_49 . V_50 ) ;
V_42 = (struct V_41 * ) ( & V_45 -> V_51 . V_35 [ 0 ] ) ;
V_43 = (struct V_41 * ) ( & V_40 -> V_36 ) ;
if ( ( F_14 ( V_42 -> V_29 ) == V_43 -> V_29 ) &&
( V_42 -> V_52 . V_53 == V_43 -> V_52 . V_53 ) ) {
F_15 ( & V_45 -> V_54 ) ;
V_14 -> V_49 . V_55 -- ;
if ( F_16 ( & V_14 -> V_49 . V_50 ) )
V_14 -> V_49 . V_56 = V_57 ;
else
V_46 = 1 ;
if ( V_45 -> V_58 )
V_45 -> V_58 ( V_45 -> V_59 , V_40 -> error ) ;
if ( V_46 ) {
V_45 = F_13 ( & V_14 -> V_49 . V_50 ) ;
F_17 ( & V_14 -> V_60 . V_61 ,
& V_45 -> V_51 ) ;
}
} else {
snprintf ( V_47 , V_48 ,
L_1 ,
V_40 -> V_36 . V_62 , V_40 -> V_36 . V_29 ,
V_40 -> V_36 . V_52 . V_53 ) ;
F_18 ( L_2 , V_47 ) ;
}
} else
F_11 ( V_14 , V_35 ) ;
}
static void
F_19 ( struct V_14 * V_14 , T_2 V_63 )
{
T_2 V_64 ;
if ( V_63 & V_65 ) {
V_64 = F_20 ( V_14 -> V_60 . V_61 . V_66 . V_67 ) ;
V_64 &= ~ V_68 ;
F_21 ( V_64 , V_14 -> V_60 . V_61 . V_66 . V_67 ) ;
}
F_22 ( & V_14 -> V_60 . V_61 ) ;
}
void
F_23 ( struct V_14 * V_14 , T_2 V_63 )
{
if ( F_24 ( V_63 ) ) {
F_19 ( V_14 , V_63 ) ;
return;
}
if ( F_25 ( V_63 ) )
F_26 ( & V_14 -> V_60 . V_61 ) ;
}
void
F_27 ( struct V_14 * V_14 , struct V_44 * V_69 )
{
struct V_41 * V_36 ;
V_36 = (struct V_41 * ) ( & V_69 -> V_51 . V_35 [ 0 ] ) ;
V_36 -> V_52 . V_53 = F_28 ( V_14 -> V_49 . V_70 ) ;
V_14 -> V_49 . V_70 ++ ;
V_14 -> V_49 . V_55 ++ ;
if ( V_14 -> V_49 . V_56 == V_57 ) {
F_29 ( & V_69 -> V_54 , & V_14 -> V_49 . V_50 ) ;
F_17 ( & V_14 -> V_60 . V_61 , & V_69 -> V_51 ) ;
V_14 -> V_49 . V_56 = V_71 ;
} else {
F_29 ( & V_69 -> V_54 , & V_14 -> V_49 . V_50 ) ;
}
}
static void
F_30 ( struct V_14 * V_14 , struct V_72 * V_73 )
{
struct V_44 * V_45 = NULL ;
struct V_72 * V_74 ;
void (* V_58)( void * V_75 , int V_5 );
void * V_59 ;
V_74 = & V_14 -> V_49 . V_50 ;
while ( ! F_16 ( V_74 ) ) {
F_31 ( V_74 , & V_45 ) ;
V_58 = V_45 -> V_58 ;
V_59 = V_45 -> V_59 ;
F_32 ( V_45 ) ;
V_14 -> V_49 . V_55 -- ;
if ( V_58 )
V_58 ( V_59 , V_76 ) ;
}
V_14 -> V_49 . V_56 = V_57 ;
}
static void
F_33 ( struct V_77 * V_49 )
{
}
static void
F_34 ( struct V_77 * V_49 )
{
F_30 ( V_49 -> V_14 , & V_49 -> V_50 ) ;
}
static void
F_35 ( struct V_77 * V_49 , struct V_14 * V_14 )
{
F_36 ( & V_14 -> V_60 . V_61 , V_78 , F_12 , V_14 ) ;
V_49 -> V_56 = V_57 ;
V_49 -> V_70 = V_49 -> V_55 = 0 ;
F_37 ( & V_49 -> V_50 ) ;
V_49 -> V_14 = V_14 ;
}
static void
F_38 ( struct V_77 * V_49 )
{
V_49 -> V_14 = NULL ;
}
static void
F_39 ( struct V_19 * V_8 )
{
V_8 -> V_14 -> V_2 . V_16 ( ( V_8 ) -> V_14 -> V_17 , V_18 ) ;
F_40 ( V_8 , V_79 ) ;
}
static void
F_41 ( struct V_19 * V_8 ,
enum V_80 V_81 )
{
switch ( V_81 ) {
case V_82 :
F_42 ( V_8 , V_83 ) ;
break;
case V_84 :
F_40 ( V_8 , V_79 ) ;
break;
case V_85 :
break;
case V_28 :
break;
case V_86 :
case V_87 :
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_44 ( struct V_19 * V_8 )
{
F_45 ( ( V_8 ) -> V_14 -> V_17 , V_18 ) ;
}
static void
V_83 ( struct V_19 * V_8 ,
enum V_80 V_81 )
{
switch ( V_81 ) {
case V_84 :
F_42 ( V_8 , F_41 ) ;
break;
case V_85 :
F_42 ( V_8 , F_41 ) ;
break;
case V_26 :
F_42 ( V_8 , V_88 ) ;
F_46 ( V_8 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_47 ( struct V_19 * V_8 )
{
F_48 ( ! F_5 ( V_8 ) ) ;
}
static void
V_88 ( struct V_19 * V_8 ,
enum V_80 V_81 )
{
switch ( V_81 ) {
case V_84 :
F_42 ( V_8 , V_89 ) ;
break;
case V_85 :
F_42 ( V_8 , F_41 ) ;
break;
case V_28 :
F_42 ( V_8 , V_90 ) ;
break;
case V_86 :
F_42 ( V_8 , V_91 ) ;
break;
case V_92 :
F_42 ( V_8 , V_83 ) ;
break;
case V_87 :
F_46 ( V_8 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_49 ( struct V_19 * V_8 )
{
}
static void
V_90 ( struct V_19 * V_8 ,
enum V_80 V_81 )
{
switch ( V_81 ) {
case V_84 :
F_42 ( V_8 , V_89 ) ;
break;
case V_85 :
F_42 ( V_8 , F_41 ) ;
break;
case V_26 :
F_42 ( V_8 , V_88 ) ;
break;
case V_86 :
F_50 ( V_8 ) ;
break;
case V_92 :
case V_87 :
F_42 ( V_8 , V_83 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_51 ( struct V_19 * V_8 )
{
}
static void
V_91 ( struct V_19 * V_8 ,
enum V_80 V_81 )
{
switch ( V_81 ) {
case V_84 :
F_42 ( V_8 , V_89 ) ;
F_50 ( V_8 ) ;
break;
case V_85 :
F_42 ( V_8 , F_41 ) ;
break;
case V_28 :
F_42 ( V_8 , V_90 ) ;
F_50 ( V_8 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_52 ( struct V_19 * V_8 )
{
}
static void
V_89 ( struct V_19 * V_8 ,
enum V_80 V_81 )
{
switch ( V_81 ) {
case V_85 :
F_42 ( V_8 , F_41 ) ;
break;
case V_28 :
break;
case V_86 :
F_50 ( V_8 ) ;
break;
case V_92 :
case V_87 :
F_42 ( V_8 , F_41 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_53 ( struct V_19 * V_8 )
{
struct V_93 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_36 . V_62 = V_78 ;
V_94 . V_36 . V_29 = V_95 ;
V_94 . V_36 . V_52 . V_96 . V_97 = 0 ;
V_94 . V_98 = V_99 ;
F_54 ( & V_8 -> V_69 , & V_94 , sizeof( V_94 ) ,
V_100 , V_8 ) ;
F_27 ( V_8 -> V_14 , & V_8 -> V_69 ) ;
}
static void
F_46 ( struct V_19 * V_8 )
{
if ( V_8 -> type == V_21 )
F_53 ( V_8 ) ;
}
static void
V_100 ( void * V_75 , int V_5 )
{
struct V_19 * V_8 = (struct V_19 * ) V_75 ;
F_32 ( & V_8 -> V_69 . V_54 ) ;
if ( V_5 == V_101 ) {
if ( V_8 -> type == V_21 )
V_8 -> V_22 &= ~ V_25 ;
else
V_8 -> V_22 &= ~ V_23 ;
F_7 ( V_8 , V_92 ) ;
} else
F_7 ( V_8 , V_86 ) ;
}
static void
F_55 ( struct V_19 * V_8 )
{
struct V_93 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_36 . V_62 = V_78 ;
V_94 . V_36 . V_29 = V_95 ;
V_94 . V_36 . V_52 . V_96 . V_97 = 0 ;
V_94 . V_98 = V_102 ;
F_54 ( & V_8 -> V_69 , & V_94 , sizeof( V_94 ) ,
V_103 , V_8 ) ;
F_27 ( V_8 -> V_14 , & V_8 -> V_69 ) ;
}
static void
F_50 ( struct V_19 * V_8 )
{
if ( V_8 -> type == V_21 )
F_55 ( V_8 ) ;
}
static void
V_103 ( void * V_75 , int V_5 )
{
struct V_19 * V_8 = (struct V_19 * ) V_75 ;
F_32 ( & V_8 -> V_69 . V_54 ) ;
F_7 ( V_8 , V_87 ) ;
}
static void
F_56 ( struct V_1 * V_2 ,
enum V_104 V_5 )
{
F_57 ( & V_2 -> V_105 ) ;
}
static void
F_58 ( struct V_19 * V_8 , struct V_14 * V_14 )
{
V_8 -> V_22 |= V_23 ;
V_8 -> V_22 |= V_25 ;
V_8 -> type = V_21 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_9 = V_18 ;
V_8 -> V_106 = 0 ;
V_8 -> V_107 = NULL ;
F_32 ( & V_8 -> V_69 . V_54 ) ;
F_42 ( V_8 , F_41 ) ;
}
static void
F_59 ( struct V_19 * V_8 )
{
V_8 -> V_22 &= ~ V_23 ;
V_8 -> V_22 &= ~ V_25 ;
V_8 -> V_14 = NULL ;
}
static void
F_60 ( struct V_19 * V_8 )
{
F_7 ( V_8 , V_82 ) ;
}
static void
F_61 ( struct V_19 * V_8 )
{
V_8 -> V_107 = F_56 ;
F_7 ( V_8 , V_84 ) ;
}
static void
F_62 ( struct V_19 * V_8 )
{
V_8 -> V_22 |= V_25 ;
F_7 ( V_8 , V_85 ) ;
}
static int
F_63 ( struct V_19 * V_8 )
{
return F_64 ( V_108 , V_8 -> V_109 ) ;
}
void
F_65 ( struct V_19 * V_8 )
{
V_8 -> V_106 ++ ;
if ( V_8 -> V_106 == 1 ) {
V_8 -> V_22 |= V_24 ;
if ( F_5 ( V_8 ) )
F_7 ( V_8 , V_26 ) ;
}
}
void
F_66 ( struct V_19 * V_8 )
{
int V_27 = F_9 ( V_8 ) ;
V_8 -> V_106 -- ;
if ( V_8 -> V_106 == 0 ) {
V_8 -> V_22 &= ~ V_24 ;
if ( V_27 )
F_7 ( V_8 , V_28 ) ;
}
}
static void
F_67 ( struct V_1 * V_2 )
{
F_68 ( V_2 , V_79 ) ;
F_69 ( V_2 , V_79 ) ;
F_70 ( V_2 , V_79 ) ;
}
static void
F_71 ( struct V_1 * V_2 , enum V_110 V_81 )
{
switch ( V_81 ) {
case V_111 :
F_42 ( V_2 , V_112 ) ;
break;
case V_113 :
F_70 ( V_2 , V_79 ) ;
break;
case V_114 :
break;
case V_115 :
F_68 ( V_2 , V_79 ) ;
break;
case V_116 :
F_69 ( V_2 , V_79 ) ;
break;
case V_117 :
break;
case V_118 :
case V_119 :
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_72 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
}
static void
V_112 ( struct V_1 * V_2 , enum V_110 V_81 )
{
switch ( V_81 ) {
case V_113 :
F_42 ( V_2 , V_120 ) ;
break;
case V_114 :
F_42 ( V_2 , F_71 ) ;
break;
case V_115 :
break;
case V_116 :
V_2 -> V_22 |= V_121 ;
break;
case V_119 :
if ( V_2 -> V_22 & V_121 ) {
V_2 -> V_22 &= ~ V_121 ;
F_73 ( V_2 ) ;
} else {
F_42 ( V_2 , V_122 ) ;
}
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_74 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
}
static void
V_122 ( struct V_1 * V_2 ,
enum V_110 V_81 )
{
switch ( V_81 ) {
case V_113 :
F_42 ( V_2 , V_120 ) ;
break;
case V_114 :
F_42 ( V_2 , F_71 ) ;
break;
case V_115 :
V_2 -> V_22 |= V_123 ;
break;
case V_116 :
V_2 -> V_22 |= V_121 ;
break;
case V_118 :
if ( V_2 -> V_22 & V_123 ) {
V_2 -> V_22 &= ~ V_123 ;
F_75 ( V_2 ) ;
} else if ( V_2 -> V_22 & V_121 ) {
V_2 -> V_22 &= ~ V_121 ;
F_42 ( V_2 , V_112 ) ;
} else {
F_42 ( V_2 , V_124 ) ;
F_76 ( V_2 ) ;
}
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_77 ( struct V_1 * V_2 )
{
}
static void
V_120 ( struct V_1 * V_2 ,
enum V_110 V_81 )
{
switch ( V_81 ) {
case V_114 :
case V_118 :
case V_119 :
F_42 ( V_2 , F_71 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_78 ( struct V_1 * V_2 )
{
F_68 ( V_2 , V_79 ) ;
F_69 ( V_2 , V_79 ) ;
}
static void
V_124 ( struct V_1 * V_2 ,
enum V_110 V_81 )
{
switch ( V_81 ) {
case V_113 :
F_42 ( V_2 , V_125 ) ;
break;
case V_114 :
F_42 ( V_2 , F_71 ) ;
F_79 ( V_2 ) ;
break;
case V_115 :
F_42 ( V_2 , V_126 ) ;
break;
case V_116 :
F_42 ( V_2 , V_127 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_80 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
}
static void
V_126 ( struct V_1 * V_2 ,
enum V_110 V_81 )
{
switch ( V_81 ) {
case V_114 :
F_42 ( V_2 , F_71 ) ;
F_79 ( V_2 ) ;
break;
case V_118 :
F_42 ( V_2 , V_124 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_81 ( struct V_1 * V_2 )
{
F_82 ( V_2 ) ;
}
static void
V_127 ( struct V_1 * V_2 ,
enum V_110 V_81 )
{
switch ( V_81 ) {
case V_114 :
F_42 ( V_2 , F_71 ) ;
F_79 ( V_2 ) ;
break;
case V_117 :
F_42 ( V_2 , V_128 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_83 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
}
static void
V_128 ( struct V_1 * V_2 , enum V_110 V_81 )
{
switch ( V_81 ) {
case V_114 :
F_42 ( V_2 , F_71 ) ;
F_79 ( V_2 ) ;
break;
case V_119 :
F_42 ( V_2 , V_124 ) ;
F_84 ( V_2 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_85 ( struct V_1 * V_2 )
{
F_86 ( V_2 ) ;
}
static void
V_125 ( struct V_1 * V_2 ,
enum V_110 V_81 )
{
switch ( V_81 ) {
case V_114 :
F_42 ( V_2 , F_71 ) ;
F_79 ( V_2 ) ;
break;
case V_117 :
F_42 ( V_2 , F_71 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_75 ( struct V_1 * V_2 )
{
struct V_129 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_36 . V_62 = V_78 ;
V_94 . V_36 . V_29 = V_130 ;
V_94 . V_36 . V_52 . V_96 . V_97 = 0 ;
V_94 . V_131 = V_2 -> V_132 . V_131 ;
V_94 . V_133 = V_2 -> V_132 . V_133 ;
F_54 ( & V_2 -> V_69 , & V_94 , sizeof( V_94 ) ,
V_134 , V_2 ) ;
F_27 ( V_2 -> V_14 , & V_2 -> V_69 ) ;
}
static void
V_134 ( void * V_75 , int V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_32 ( & V_2 -> V_69 . V_54 ) ;
F_7 ( V_2 , V_118 ) ;
}
void
F_73 ( struct V_1 * V_2 )
{
struct V_135 V_94 ;
F_87 ( V_94 . V_36 , V_78 , V_136 , 0 ) ;
V_94 . V_137 = F_28 ( ( V_138 ) V_2 -> V_137 ) ;
F_54 ( & V_2 -> V_69 , & V_94 , sizeof( V_94 ) ,
V_139 , V_2 ) ;
F_27 ( V_2 -> V_14 , & V_2 -> V_69 ) ;
}
void
V_139 ( void * V_75 , int V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_32 ( & V_2 -> V_69 . V_54 ) ;
F_7 ( V_2 , V_119 ) ;
}
static void
F_88 ( void * V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_7 ( V_2 , V_117 ) ;
}
static void
F_89 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
V_2 -> V_14 = V_14 ;
V_2 -> V_22 = 0 ;
V_2 -> V_137 = 0 ;
V_2 -> type = V_21 ;
V_2 -> V_16 = F_45 ;
V_2 -> V_105 . V_140 = F_88 ;
V_2 -> V_105 . V_141 = V_2 ;
V_2 -> V_105 . V_142 = 0 ;
V_2 -> V_107 = NULL ;
V_2 -> V_143 = NULL ;
V_2 -> V_144 = NULL ;
V_2 -> V_145 = NULL ;
F_32 ( & V_2 -> V_69 . V_54 ) ;
F_42 ( V_2 , F_71 ) ;
F_58 ( & V_2 -> V_8 , V_14 ) ;
}
static void
F_90 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_8 ) ;
V_2 -> V_22 = 0 ;
V_2 -> V_14 = NULL ;
}
static int
F_91 ( struct V_1 * V_2 )
{
return F_64 ( V_146 , V_2 -> V_109 ) ;
}
static void
F_92 ( struct V_1 * V_2 )
{
V_2 -> V_22 |= V_147 ;
if ( V_2 -> V_22 & V_148 )
F_7 ( V_2 , V_111 ) ;
}
static void
F_93 ( struct V_1 * V_2 )
{
V_2 -> V_107 = V_149 ;
V_2 -> V_143 = & V_2 -> V_14 -> V_60 ;
V_2 -> V_22 &= ~ V_147 ;
F_7 ( V_2 , V_113 ) ;
}
static void
F_94 ( struct V_1 * V_2 )
{
V_2 -> V_22 &= ~ V_147 ;
F_7 ( V_2 , V_114 ) ;
}
void
F_95 ( struct V_1 * V_2 , enum V_104 V_5 )
{
F_57 ( & V_2 -> V_105 ) ;
}
void
F_96 ( struct V_1 * V_2 , enum V_104 V_5 )
{
F_57 ( & V_2 -> V_105 ) ;
}
int
F_97 ( struct V_1 * V_2 )
{
return V_2 -> V_137 ;
}
void
F_98 ( struct V_1 * V_2 )
{
if ( V_2 -> V_109 != ( V_150 ) F_71 )
return;
V_2 -> V_22 |= V_148 ;
if ( V_2 -> V_22 & V_147 )
F_7 ( V_2 , V_111 ) ;
}
void
F_99 ( struct V_1 * V_2 , enum V_151 type ,
void (* V_58)( void * , enum V_104 ) )
{
if ( type == V_152 ) {
(* V_58)( V_2 -> V_14 -> V_17 , V_79 ) ;
return;
}
V_2 -> V_107 = V_58 ;
V_2 -> V_143 = V_2 -> V_14 -> V_17 ;
V_2 -> V_22 &= ~ V_148 ;
F_7 ( V_2 , V_113 ) ;
}
void
F_100 ( struct V_1 * V_2 ,
struct V_153 * V_132 ,
void (* V_58)( struct V_17 * , enum V_104 ) )
{
V_2 -> V_132 = * V_132 ;
V_2 -> V_144 = V_58 ;
F_7 ( V_2 , V_115 ) ;
}
void
F_101 ( struct V_1 * V_2 , int V_137 ,
void (* V_58)( struct V_17 * , enum V_104 ) )
{
V_2 -> V_137 = V_137 ;
V_2 -> V_145 = V_58 ;
F_7 ( V_2 , V_116 ) ;
}
void
F_102 ( struct V_1 * V_2 , T_3 * V_154 )
{
* V_154 = F_103 ( & V_2 -> V_14 -> V_60 . V_61 ) ;
}
static void
F_104 ( struct V_155 * V_60 )
{
if ( V_60 -> V_107 )
V_60 -> V_107 ( V_60 -> V_143 , V_79 ) ;
V_60 -> V_107 = NULL ;
V_60 -> V_143 = NULL ;
}
static void
F_105 ( struct V_155 * V_60 ,
enum V_156 V_81 )
{
switch ( V_81 ) {
case V_157 :
if ( V_60 -> V_158 == V_159 )
F_106 ( V_60 ) ;
F_107 ( & V_60 -> V_61 ) ;
F_42 ( V_60 , V_160 ) ;
break;
case V_161 :
F_42 ( V_60 , F_105 ) ;
break;
case V_162 :
F_108 ( V_60 ) ;
break;
case V_163 :
F_42 ( V_60 , V_164 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_109 ( struct V_155 * V_60 )
{
}
static void
V_160 ( struct V_155 * V_60 ,
enum V_156 V_81 )
{
switch ( V_81 ) {
case V_161 :
if ( V_60 -> V_165 )
V_60 -> V_165 ( V_60 -> V_166 ,
V_167 ) ;
V_60 -> V_165 = NULL ;
V_60 -> V_166 = NULL ;
F_42 ( V_60 , V_168 ) ;
break;
case V_169 :
F_42 ( V_60 , V_170 ) ;
break;
case V_163 :
F_42 ( V_60 , V_164 ) ;
break;
case V_162 :
F_108 ( V_60 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_110 ( struct V_155 * V_60 )
{
F_33 ( & V_60 -> V_14 -> V_49 ) ;
F_92 ( & V_60 -> V_14 -> V_2 ) ;
if ( V_60 -> V_165 )
V_60 -> V_165 ( V_60 -> V_166 ,
V_79 ) ;
V_60 -> V_165 = NULL ;
V_60 -> V_166 = NULL ;
}
static void
V_170 ( struct V_155 * V_60 , enum V_156 V_81 )
{
switch ( V_81 ) {
case V_161 :
F_42 ( V_60 , V_171 ) ;
break;
case V_163 :
F_42 ( V_60 , V_164 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_111 ( struct V_155 * V_60 )
{
F_93 ( & V_60 -> V_14 -> V_2 ) ;
}
static void
V_171 ( struct V_155 * V_60 ,
enum V_156 V_81 )
{
switch ( V_81 ) {
case V_172 :
F_34 ( & V_60 -> V_14 -> V_49 ) ;
F_42 ( V_60 , V_168 ) ;
break;
case V_163 :
F_112 ( V_60 ) ;
F_94 ( & V_60 -> V_14 -> V_2 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_113 ( struct V_155 * V_60 )
{
F_114 ( & V_60 -> V_61 ) ;
}
static void
V_168 ( struct V_155 * V_60 ,
enum V_156 V_81 )
{
switch ( V_81 ) {
case V_173 :
F_112 ( V_60 ) ;
F_42 ( V_60 , F_105 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_115 ( struct V_155 * V_60 )
{
F_112 ( V_60 ) ;
F_94 ( & V_60 -> V_14 -> V_2 ) ;
F_34 ( & V_60 -> V_14 -> V_49 ) ;
if ( V_60 -> V_165 )
V_60 -> V_165 ( V_60 -> V_166 ,
V_174 ) ;
V_60 -> V_165 = NULL ;
V_60 -> V_166 = NULL ;
}
static void
V_164 ( struct V_155 * V_60 ,
enum V_156 V_81 )
{
switch ( V_81 ) {
case V_161 :
F_42 ( V_60 , V_168 ) ;
break;
case V_162 :
F_108 ( V_60 ) ;
F_42 ( V_60 , V_160 ) ;
break;
default:
F_43 ( V_81 ) ;
}
}
static void
F_116 ( void * V_175 , enum V_176 error )
{
struct V_155 * V_60 = (struct V_155 * ) V_175 ;
if ( error )
F_7 ( V_60 , V_163 ) ;
else
F_7 ( V_60 , V_169 ) ;
}
static void
F_117 ( void * V_175 )
{
struct V_155 * V_60 = (struct V_155 * ) V_175 ;
F_7 ( V_60 , V_173 ) ;
}
static void
F_118 ( void * V_175 )
{
struct V_155 * V_60 = (struct V_155 * ) V_175 ;
F_7 ( V_60 , V_163 ) ;
}
static void
F_119 ( void * V_175 )
{
struct V_155 * V_60 = (struct V_155 * ) V_175 ;
F_7 ( V_60 , V_162 ) ;
}
static void
F_120 ( struct V_155 * V_60 , struct V_14 * V_14 ,
struct V_177 * V_178 )
{
T_1 * V_179 ;
T_4 V_180 ;
V_60 -> V_14 = V_14 ;
V_179 = V_178 [ V_181 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ;
F_121 (
& V_178 [ V_185 ] . V_182 . V_183 . V_184 [ 0 ] . V_180 , V_180 ) ;
V_179 = V_178 [ V_185 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ;
F_122 ( & V_14 -> V_186 , & V_60 -> V_61 , V_14 ) ;
F_123 ( & V_14 -> V_186 , V_179 , V_180 ) ;
V_179 += F_124 () ;
V_180 += F_124 () ;
}
static void
F_125 ( struct V_155 * V_60 , struct V_14 * V_14 ,
struct V_177 * V_178 )
{
T_4 V_180 ;
V_60 -> V_14 = V_14 ;
F_126 ( & V_60 -> V_61 , V_60 , & V_187 ) ;
F_127 ( & V_60 -> V_61 , & V_14 -> V_188 , V_78 ) ;
F_121 (
& V_178 [ V_189 ] . V_182 . V_183 . V_184 [ 0 ] . V_180 , V_180 ) ;
F_128 ( & V_60 -> V_61 ,
V_178 [ V_189 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ,
V_180 ) ;
F_120 ( V_60 , V_14 , V_178 ) ;
V_60 -> V_158 =
V_178 [ V_190 ] . V_182 . V_191 . V_158 ;
V_60 -> V_192 =
V_178 [ V_190 ] . V_182 . V_191 . V_193 [ 0 ] . V_192 ;
F_35 ( & V_14 -> V_49 , V_14 ) ;
V_60 -> V_165 = V_60 -> V_107 = NULL ;
V_60 -> V_166 = V_60 -> V_143 = NULL ;
F_42 ( V_60 , F_105 ) ;
}
static void
F_129 ( struct V_155 * V_60 )
{
F_38 ( & V_60 -> V_14 -> V_49 ) ;
F_130 ( & V_60 -> V_61 ) ;
V_60 -> V_14 = NULL ;
}
static void
V_149 ( void * V_75 , enum V_104 V_5 )
{
struct V_155 * V_60 = (struct V_155 * ) V_75 ;
F_7 ( V_60 , V_172 ) ;
}
static int
F_131 ( struct V_155 * V_60 )
{
return V_60 -> V_109 == ( V_194 ) V_170 ;
}
void
F_132 ( struct V_155 * V_60 )
{
if ( V_60 -> V_109 != ( V_194 ) F_105 ) {
F_133 ( V_60 -> V_14 -> V_17 , V_195 ) ;
return;
}
V_60 -> V_165 = F_133 ;
V_60 -> V_166 = V_60 -> V_14 -> V_17 ;
F_7 ( V_60 , V_157 ) ;
}
void
F_134 ( struct V_155 * V_60 , enum V_151 type )
{
if ( type == V_152 ) {
F_135 ( V_60 -> V_14 -> V_17 , V_79 ) ;
return;
}
V_60 -> V_107 = F_135 ;
V_60 -> V_143 = V_60 -> V_14 -> V_17 ;
F_7 ( V_60 , V_161 ) ;
}
static int
F_136 ( struct V_155 * V_60 )
{
return F_64 ( V_196 , V_60 -> V_109 ) ;
}
static void
F_137 ( struct V_177 * V_178 )
{
V_178 [ V_185 ] . V_197 = V_198 ;
V_178 [ V_185 ] . V_182 . V_183 . V_199 = V_200 ;
V_178 [ V_185 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_185 ] . V_182 . V_183 . V_202 = F_138 (
F_124 () , V_203 ) ;
V_178 [ V_181 ] . V_197 = V_198 ;
V_178 [ V_181 ] . V_182 . V_183 . V_199 = V_204 ;
V_178 [ V_181 ] . V_182 . V_183 . V_201 = 0 ;
V_178 [ V_181 ] . V_182 . V_183 . V_202 = 0 ;
V_178 [ V_205 ] . V_197 = V_198 ;
V_178 [ V_205 ] . V_182 . V_183 . V_199 = V_200 ;
V_178 [ V_205 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_205 ] . V_182 . V_183 . V_202 =
F_138 ( V_206 , V_203 ) ;
V_178 [ V_207 ] . V_197 = V_198 ;
V_178 [ V_207 ] . V_182 . V_183 . V_199 = V_204 ;
V_178 [ V_207 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_207 ] . V_182 . V_183 . V_202 =
sizeof( struct V_208 ) ;
}
static void
F_139 ( struct V_14 * V_14 , struct V_208 * V_209 )
{
struct V_210 * V_211 ;
struct V_212 * V_213 ;
struct V_214 * V_215 ;
struct V_216 * V_217 ;
struct V_72 * V_54 ;
struct V_72 * V_218 ;
struct V_72 * V_219 ;
struct V_72 * V_220 ;
int V_6 ;
V_209 -> V_221 = F_136 ( & V_14 -> V_60 ) ;
V_209 -> V_222 = F_91 ( & V_14 -> V_2 ) ;
V_209 -> V_223 = V_14 -> V_2 . V_22 ;
V_209 -> V_224 = F_63 ( & V_14 -> V_2 . V_8 ) ;
V_209 -> V_13 = V_14 -> V_2 . V_13 ;
V_6 = 0 ;
F_140 (qe, &bna->tx_mod.tx_active_q) {
V_211 = (struct V_210 * ) V_54 ;
V_209 -> V_225 [ V_6 ] . V_226 = F_141 ( V_211 ) ;
V_209 -> V_225 [ V_6 ] . V_227 = V_211 -> V_22 ;
V_209 -> V_225 [ V_6 ] . V_228 = 0 ;
V_209 -> V_225 [ V_6 ] . V_229 [ 0 ] = 0 ;
V_209 -> V_225 [ V_6 ] . V_229 [ 1 ] = 0 ;
F_140 (txq_qe, &tx->txq_q) {
V_213 = (struct V_212 * ) V_218 ;
if ( V_213 -> V_230 < 32 )
V_209 -> V_225 [ V_6 ] . V_229 [ 0 ] |=
( ( T_2 ) 1 << V_213 -> V_230 ) ;
else
V_209 -> V_225 [ V_6 ] . V_229 [ 1 ] |=
( ( T_2 )
1 << ( V_213 -> V_230 - 32 ) ) ;
V_209 -> V_225 [ V_6 ] . V_228 ++ ;
}
V_209 -> V_225 [ V_6 ] . V_231 = V_211 -> V_232 . V_231 ;
V_6 ++ ;
}
V_209 -> V_233 = V_6 ;
V_6 = 0 ;
F_140 (qe, &bna->rx_mod.rx_active_q) {
V_215 = (struct V_214 * ) V_54 ;
V_209 -> V_234 [ V_6 ] . V_235 = F_142 ( V_215 ) ;
V_209 -> V_234 [ V_6 ] . V_236 = V_215 -> V_236 ;
V_209 -> V_234 [ V_6 ] . V_237 = 0 ;
V_209 -> V_234 [ V_6 ] . V_238 = 0 ;
V_209 -> V_234 [ V_6 ] . V_239 [ 0 ] = 0 ;
V_209 -> V_234 [ V_6 ] . V_239 [ 1 ] = 0 ;
V_209 -> V_234 [ V_6 ] . V_240 [ 0 ] = 0 ;
V_209 -> V_234 [ V_6 ] . V_240 [ 1 ] = 0 ;
F_140 (rxp_qe, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_219 ;
V_209 -> V_234 [ V_6 ] . V_238 += 1 ;
if ( V_217 -> type == V_241 ) {
if ( V_217 -> V_242 . V_243 . V_244 -> V_245 < 32 ) {
V_209 -> V_234 [ V_6 ] . V_239 [ 0 ] |=
( ( T_2 ) 1 <<
V_217 -> V_242 . V_243 . V_244 -> V_245 ) ;
} else {
V_209 -> V_234 [ V_6 ] . V_239 [ 1 ] |=
( ( T_2 ) 1 <<
( V_217 -> V_242 . V_243 . V_244 -> V_245 - 32 ) ) ;
}
} else {
if ( V_217 -> V_242 . V_246 . V_247 -> V_245 < 32 ) {
V_209 -> V_234 [ V_6 ] . V_239 [ 0 ] |=
( ( T_2 ) 1 <<
V_217 -> V_242 . V_246 . V_247 -> V_245 ) ;
} else {
V_209 -> V_234 [ V_6 ] . V_239 [ 1 ] |=
( ( T_2 ) 1 <<
( V_217 -> V_242 . V_246 . V_247 -> V_245 - 32 ) ) ;
}
if ( V_217 -> V_242 . V_246 . V_248 -> V_245 < 32 ) {
V_209 -> V_234 [ V_6 ] . V_239 [ 0 ] |=
( ( T_2 ) 1 <<
V_217 -> V_242 . V_246 . V_248 -> V_245 ) ;
} else {
V_209 -> V_234 [ V_6 ] . V_239 [ 1 ] |=
( ( T_2 ) 1 <<
( V_217 -> V_242 . V_246 . V_248 -> V_245 - 32 ) ) ;
}
V_209 -> V_234 [ V_6 ] . V_238 += 1 ;
}
if ( V_217 -> V_249 . V_250 < 32 )
V_209 -> V_234 [ V_6 ] . V_240 [ 0 ] |=
( 1 << V_217 -> V_249 . V_250 ) ;
else
V_209 -> V_234 [ V_6 ] . V_240 [ 1 ] |=
( 1 << ( V_217 -> V_249 . V_250 - 32 ) ) ;
V_209 -> V_234 [ V_6 ] . V_237 ++ ;
}
V_209 -> V_234 [ V_6 ] . V_251 = V_215 -> V_252 . V_251 ;
V_209 -> V_234 [ V_6 ] . V_253 = F_143 ( & V_215 -> V_252 ) ;
V_209 -> V_234 [ V_6 ] . V_254 = V_215 -> V_252 . V_254 ;
V_209 -> V_234 [ V_6 ] . V_255 = 0 ;
if ( V_215 -> V_252 . V_256 )
V_209 -> V_234 [ V_6 ] . V_255 ++ ;
F_140 (mac_qe, &rx->rxf.ucast_active_q)
V_209 -> V_234 [ V_6 ] . V_255 ++ ;
V_209 -> V_234 [ V_6 ] . V_257 = 0 ;
F_140 (mac_qe, &rx->rxf.mcast_active_q)
V_209 -> V_234 [ V_6 ] . V_257 ++ ;
V_209 -> V_234 [ V_6 ] . V_258 = V_215 -> V_252 . V_258 ;
V_209 -> V_234 [ V_6 ] . V_259 =
V_215 -> V_252 . V_259 ;
memcpy ( V_209 -> V_234 [ V_6 ] . V_260 ,
V_215 -> V_252 . V_260 ,
sizeof( T_2 ) * ( ( V_261 + 1 ) / 32 ) ) ;
V_209 -> V_234 [ V_6 ] . V_262 = V_215 -> V_252 . V_262 ;
V_209 -> V_234 [ V_6 ] . V_263 = V_215 -> V_252 . V_263 ;
V_6 ++ ;
}
V_209 -> V_264 = V_6 ;
}
static void
F_144 ( void * V_75 , int V_5 )
{
struct V_14 * V_14 = (struct V_14 * ) V_75 ;
T_4 * V_265 ;
int V_6 , V_266 ;
int V_267 , V_268 ;
T_4 V_269 , V_270 ;
F_32 ( & V_14 -> V_69 . V_54 ) ;
if ( V_5 == 0 ) {
V_265 = ( T_4 * ) V_14 -> V_271 . V_272 ;
V_266 = sizeof( struct V_273 ) / sizeof( T_4 ) ;
for ( V_6 = 0 ; V_6 < V_266 ; V_6 ++ )
V_265 [ V_6 ] = F_145 ( V_265 [ V_6 ] ) ;
V_267 = 0 ;
V_269 = ( T_4 ) V_14 -> V_271 . V_269 [ 0 ] |
( ( T_4 ) V_14 -> V_271 . V_269 [ 1 ] << 32 ) ;
for ( V_6 = 0 ; V_6 < V_274 ; V_6 ++ )
if ( V_269 & ( ( T_4 ) 1 << V_6 ) )
V_267 ++ ;
V_268 = 0 ;
V_270 = ( T_4 ) V_14 -> V_271 . V_270 [ 0 ] |
( ( T_4 ) V_14 -> V_271 . V_270 [ 1 ] << 32 ) ;
for ( V_6 = 0 ; V_6 < V_275 ; V_6 ++ )
if ( V_270 & ( ( T_4 ) 1 << V_6 ) )
V_268 ++ ;
V_265 = ( T_4 * ) & V_14 -> V_271 . V_272 -> V_276 [ 0 ] +
( ( V_267 * sizeof( struct V_277 ) +
V_268 * sizeof( struct V_278 ) ) /
sizeof( T_4 ) ) ;
for ( V_6 = ( V_275 - 1 ) ; V_6 >= 0 ; V_6 -- )
if ( V_270 & ( ( T_4 ) 1 << V_6 ) ) {
V_265 -= sizeof( struct V_278 ) /
sizeof( T_4 ) ;
memcpy ( & V_14 -> V_271 . V_272 -> V_279 [ V_6 ] ,
V_265 ,
sizeof( struct V_278 ) ) ;
}
for ( V_6 = ( V_274 - 1 ) ; V_6 >= 0 ; V_6 -- )
if ( V_269 & ( ( T_4 ) 1 << V_6 ) ) {
V_265 -= sizeof( struct V_277 ) /
sizeof( T_4 ) ;
memcpy ( & V_14 -> V_271 . V_272 -> V_276 [ V_6 ] ,
V_265 ,
sizeof( struct V_277 ) ) ;
}
F_139 ( V_14 , V_14 -> V_271 . V_209 ) ;
F_146 ( V_14 -> V_17 , V_79 , & V_14 -> V_271 ) ;
} else
F_146 ( V_14 -> V_17 , V_174 , & V_14 -> V_271 ) ;
}
static void
F_147 ( struct V_14 * V_14 )
{
struct V_280 V_94 ;
F_87 ( V_94 . V_36 , V_78 , V_281 , 0 ) ;
V_94 . V_282 = F_28 ( V_283 ) ;
V_94 . V_284 [ 0 ] = F_148 ( V_14 -> V_285 . V_269 [ 0 ] ) ;
V_94 . V_284 [ 1 ] = F_148 ( V_14 -> V_285 . V_269 [ 1 ] ) ;
V_94 . V_286 [ 0 ] = F_148 ( V_14 -> V_15 . V_270 [ 0 ] ) ;
V_94 . V_286 [ 1 ] = F_148 ( V_14 -> V_15 . V_270 [ 1 ] ) ;
V_94 . V_287 . V_288 . V_289 = V_14 -> V_290 . V_291 ;
V_94 . V_287 . V_288 . V_292 = V_14 -> V_290 . V_293 ;
F_54 ( & V_14 -> V_69 , & V_94 , sizeof( V_94 ) ,
F_144 , V_14 ) ;
F_27 ( V_14 , & V_14 -> V_69 ) ;
V_14 -> V_271 . V_269 [ 0 ] = V_14 -> V_285 . V_269 [ 0 ] ;
V_14 -> V_271 . V_269 [ 1 ] = V_14 -> V_285 . V_269 [ 1 ] ;
V_14 -> V_271 . V_270 [ 0 ] = V_14 -> V_15 . V_270 [ 0 ] ;
V_14 -> V_271 . V_270 [ 1 ] = V_14 -> V_15 . V_270 [ 1 ] ;
}
void
F_149 ( struct V_14 * V_14 )
{
if ( F_131 ( & V_14 -> V_60 ) )
F_147 ( V_14 ) ;
else
F_146 ( V_14 -> V_17 , V_174 , & V_14 -> V_271 ) ;
}
static void
F_150 ( struct V_294 * V_295 , T_1 V_296 )
{
V_295 -> V_297 . V_296 = V_296 ;
if ( V_295 -> V_298 )
V_295 -> V_299 . V_300 = F_151 (
( T_2 ) V_295 -> V_297 . V_296 , 0 ) ;
}
void
F_152 ( struct V_301 * V_252 ,
struct V_214 * V_215 ,
struct V_302 * V_303 )
{
switch ( V_303 -> V_304 ) {
case V_241 :
break;
case V_305 :
V_252 -> V_306 |= V_307 ;
break;
case V_308 :
V_252 -> V_309 . V_310 = V_303 -> V_311 . V_310 ;
V_252 -> V_309 . V_312 =
V_303 -> V_311 . V_312 ;
V_252 -> V_313 = 0 ;
break;
default:
break;
}
if ( V_303 -> V_262 == V_99 ) {
V_252 -> V_306 |= V_314 ;
V_252 -> V_315 . V_316 = V_303 -> V_317 . V_316 ;
V_252 -> V_315 . V_318 = V_303 -> V_317 . V_318 ;
memcpy ( & V_252 -> V_315 . V_319 [ 0 ] ,
& V_303 -> V_317 . V_319 [ 0 ] ,
sizeof( V_252 -> V_315 . V_319 ) ) ;
}
}
static void
F_153 ( struct V_301 * V_252 , T_1 V_51 , enum V_320 V_5 )
{
struct V_321 V_322 ;
F_87 ( V_322 . V_36 , V_78 , V_51 , 0 ) ;
V_322 . V_251 = V_252 -> V_251 ;
V_322 . V_323 = V_5 ;
F_54 ( & V_252 -> V_69 , & V_322 , sizeof( V_322 ) ,
V_324 , V_252 ) ;
F_27 ( V_252 -> V_215 -> V_14 , & V_252 -> V_69 ) ;
}
int
F_154 ( struct V_301 * V_252 )
{
struct V_325 * V_154 = NULL ;
struct V_72 * V_54 ;
if ( ! F_16 ( & V_252 -> V_326 ) ) {
F_31 ( & V_252 -> V_326 , & V_54 ) ;
F_32 ( V_54 ) ;
V_154 = (struct V_325 * ) V_54 ;
F_155 ( V_252 , V_327 , V_154 ) ;
F_29 ( & V_154 -> V_54 , & V_252 -> V_328 ) ;
return 1 ;
}
if ( ! F_16 ( & V_252 -> V_329 ) ) {
F_31 ( & V_252 -> V_329 , & V_54 ) ;
F_32 ( V_54 ) ;
V_154 = (struct V_325 * ) V_54 ;
F_155 ( V_252 , V_330 , V_154 ) ;
F_156 ( & V_252 -> V_215 -> V_14 -> V_331 , V_154 ) ;
return 1 ;
}
return 0 ;
}
int
F_157 ( struct V_301 * V_252 )
{
struct V_14 * V_14 = V_252 -> V_215 -> V_14 ;
if ( F_158 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_159 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 |= V_334 ;
F_160 ( V_252 , V_102 ) ;
F_153 ( V_252 , V_335 ,
V_99 ) ;
return 1 ;
} else if ( F_161 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_159 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_334 ;
V_14 -> V_336 = V_337 ;
F_160 ( V_252 , V_252 -> V_259 ) ;
F_153 ( V_252 , V_335 ,
V_102 ) ;
return 1 ;
}
return 0 ;
}
int
F_162 ( struct V_301 * V_252 )
{
if ( F_163 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_164 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 |= V_338 ;
F_153 ( V_252 , V_339 ,
V_99 ) ;
return 1 ;
} else if ( F_165 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_164 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_338 ;
F_153 ( V_252 , V_339 ,
V_102 ) ;
return 1 ;
}
return 0 ;
}
int
F_166 ( struct V_301 * V_252 )
{
struct V_325 * V_154 = NULL ;
struct V_72 * V_54 ;
if ( ! F_16 ( & V_252 -> V_329 ) ) {
F_31 ( & V_252 -> V_329 , & V_54 ) ;
F_32 ( V_54 ) ;
V_154 = (struct V_325 * ) V_54 ;
F_155 ( V_252 , V_330 , V_154 ) ;
F_156 ( & V_252 -> V_215 -> V_14 -> V_331 , V_154 ) ;
return 1 ;
}
if ( ! F_16 ( & V_252 -> V_328 ) ) {
F_31 ( & V_252 -> V_328 , & V_54 ) ;
F_32 ( V_54 ) ;
V_154 = (struct V_325 * ) V_54 ;
F_155 ( V_252 , V_330 , V_154 ) ;
F_29 ( & V_154 -> V_54 , & V_252 -> V_326 ) ;
return 1 ;
}
return 0 ;
}
int
F_167 ( struct V_301 * V_252 )
{
struct V_14 * V_14 = V_252 -> V_215 -> V_14 ;
if ( F_161 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_159 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_334 ;
V_14 -> V_336 = V_337 ;
F_160 ( V_252 , V_252 -> V_259 ) ;
F_153 ( V_252 , V_335 ,
V_102 ) ;
return 1 ;
}
if ( V_252 -> V_258 & V_334 ) {
F_168 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_334 ;
F_160 ( V_252 , V_252 -> V_259 ) ;
F_153 ( V_252 , V_335 ,
V_102 ) ;
return 1 ;
}
return 0 ;
}
int
F_169 ( struct V_301 * V_252 )
{
if ( F_165 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_164 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_338 ;
F_153 ( V_252 , V_339 ,
V_102 ) ;
return 1 ;
}
if ( V_252 -> V_258 & V_338 ) {
F_170 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_338 ;
F_153 ( V_252 , V_339 ,
V_102 ) ;
return 1 ;
}
return 0 ;
}
void
F_171 ( struct V_301 * V_252 )
{
struct V_72 * V_54 ;
struct V_325 * V_154 ;
while ( ! F_16 ( & V_252 -> V_328 ) ) {
F_31 ( & V_252 -> V_328 , & V_54 ) ;
F_32 ( V_54 ) ;
F_29 ( V_54 , & V_252 -> V_326 ) ;
}
while ( ! F_16 ( & V_252 -> V_329 ) ) {
F_31 ( & V_252 -> V_329 , & V_54 ) ;
F_32 ( V_54 ) ;
V_154 = (struct V_325 * ) V_54 ;
F_156 ( & V_252 -> V_215 -> V_14 -> V_331 , V_154 ) ;
}
}
void
F_172 ( struct V_301 * V_252 )
{
struct V_14 * V_14 = V_252 -> V_215 -> V_14 ;
if ( F_161 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_159 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_334 ;
V_14 -> V_336 = V_337 ;
}
if ( V_252 -> V_258 & V_334 ) {
F_168 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_334 ;
}
}
void
F_173 ( struct V_301 * V_252 )
{
if ( F_165 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_164 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_338 ;
}
if ( V_252 -> V_258 & V_338 ) {
F_170 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_252 -> V_258 &= ~ V_338 ;
}
}
static int
F_174 ( struct V_301 * V_252 )
{
struct V_14 * V_14 = V_252 -> V_215 -> V_14 ;
int V_340 = 0 ;
if ( F_158 ( V_252 -> V_332 ,
V_252 -> V_333 ) ||
( V_252 -> V_258 & V_334 ) ) {
} else {
F_168 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_14 -> V_336 = V_252 -> V_251 ;
V_340 = 1 ;
}
return V_340 ;
}
static int
F_175 ( struct V_301 * V_252 )
{
struct V_14 * V_14 = V_252 -> V_215 -> V_14 ;
int V_340 = 0 ;
if ( F_158 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_159 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_14 -> V_336 = V_337 ;
} else if ( V_252 -> V_258 & V_334 ) {
F_176 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_340 = 1 ;
} else {
}
return V_340 ;
}
static int
F_177 ( struct V_301 * V_252 )
{
int V_340 = 0 ;
if ( F_163 ( V_252 -> V_332 ,
V_252 -> V_333 ) ||
( V_252 -> V_258 & V_338 ) ) {
} else {
F_170 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_340 = 1 ;
}
return V_340 ;
}
static int
F_178 ( struct V_301 * V_252 )
{
int V_340 = 0 ;
if ( F_163 ( V_252 -> V_332 ,
V_252 -> V_333 ) ) {
F_164 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
} else if ( V_252 -> V_258 & V_338 ) {
F_179 ( V_252 -> V_332 ,
V_252 -> V_333 ) ;
V_340 = 1 ;
}
return V_340 ;
}
enum V_104
F_180 ( struct V_214 * V_215 , enum V_341 V_342 ,
enum V_341 V_343 ,
void (* V_58)( struct V_17 * , struct V_214 * ,
enum V_104 ) )
{
struct V_301 * V_252 = & V_215 -> V_252 ;
int V_344 = 0 ;
if ( F_158 ( V_342 , V_343 ) ) {
if ( ( V_215 -> V_14 -> V_336 != V_337 ) &&
( V_215 -> V_14 -> V_336 != V_252 -> V_251 ) )
goto V_345;
if ( F_174 ( V_252 ) )
V_344 = 1 ;
} else if ( F_161 ( V_342 , V_343 ) ) {
if ( F_175 ( V_252 ) )
V_344 = 1 ;
}
if ( F_163 ( V_342 , V_343 ) ) {
if ( F_177 ( V_252 ) )
V_344 = 1 ;
} else if ( F_165 ( V_342 , V_343 ) ) {
if ( F_178 ( V_252 ) )
V_344 = 1 ;
}
if ( V_344 ) {
V_252 -> V_346 = V_58 ;
V_252 -> V_347 = V_215 -> V_14 -> V_17 ;
F_7 ( V_252 , V_348 ) ;
} else if ( V_58 )
(* V_58)( V_215 -> V_14 -> V_17 , V_215 , V_79 ) ;
return V_79 ;
V_345:
return V_174 ;
}
void
F_181 ( struct V_214 * V_215 )
{
struct V_301 * V_252 = & V_215 -> V_252 ;
if ( V_252 -> V_259 == V_102 ) {
V_252 -> V_349 |= V_350 ;
V_252 -> V_259 = V_99 ;
F_7 ( V_252 , V_348 ) ;
}
}
void
F_182 ( struct V_214 * V_215 , int V_296 )
{
struct V_216 * V_217 ;
struct V_72 * V_54 ;
F_140 (qe, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_54 ;
V_217 -> V_249 . V_351 -> V_352 = V_296 ;
F_150 ( V_217 -> V_249 . V_295 , V_296 ) ;
}
}
void
F_183 ( struct V_14 * V_14 , const T_2 V_192 [] [ V_353 ] )
{
int V_6 , V_354 ;
for ( V_6 = 0 ; V_6 < V_355 ; V_6 ++ )
for ( V_354 = 0 ; V_354 < V_353 ; V_354 ++ )
V_14 -> V_285 . V_356 [ V_6 ] [ V_354 ] = V_192 [ V_6 ] [ V_354 ] ;
}
void
F_184 ( struct V_357 * V_351 )
{
struct V_14 * V_14 = V_351 -> V_249 -> V_215 -> V_14 ;
T_2 V_358 , V_359 ;
T_2 V_360 , V_361 , V_362 ;
T_1 V_296 ;
if ( ( V_351 -> V_363 . V_364 == 0 ) &&
( V_351 -> V_363 . V_365 == 0 ) )
return;
V_361 = V_351 -> V_363 . V_364 ;
V_362 = V_351 -> V_363 . V_365 ;
V_360 = V_361 + V_362 ;
if ( V_360 < V_366 )
V_358 = V_367 ;
else if ( V_360 < V_368 )
V_358 = V_369 ;
else if ( V_360 < V_370 )
V_358 = V_371 ;
else if ( V_360 < V_372 )
V_358 = V_373 ;
else if ( V_360 < V_374 )
V_358 = V_375 ;
else if ( V_360 < V_376 )
V_358 = V_377 ;
else if ( V_360 < V_378 )
V_358 = V_379 ;
else
V_358 = V_380 ;
if ( V_361 > ( V_362 << 1 ) )
V_359 = 0 ;
else
V_359 = 1 ;
V_351 -> V_363 . V_364 = 0 ;
V_351 -> V_363 . V_365 = 0 ;
V_296 = V_14 -> V_285 . V_356 [ V_358 ] [ V_359 ] ;
V_351 -> V_352 = V_296 ;
F_150 ( V_351 -> V_249 -> V_295 , V_296 ) ;
}
void
F_185 ( struct V_210 * V_211 , int V_296 )
{
struct V_212 * V_213 ;
struct V_72 * V_54 ;
F_140 (qe, &tx->txq_q) {
V_213 = (struct V_212 * ) V_54 ;
F_150 ( V_213 -> V_295 , V_296 ) ;
}
}
static void
F_186 ( struct V_381 * V_331 , struct V_14 * V_14 ,
struct V_177 * V_178 )
{
int V_6 ;
V_331 -> V_382 = (struct V_325 * )
V_178 [ V_383 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ;
F_37 ( & V_331 -> V_384 ) ;
for ( V_6 = 0 ; V_6 < V_385 ; V_6 ++ ) {
F_32 ( & V_331 -> V_382 [ V_6 ] . V_54 ) ;
F_29 ( & V_331 -> V_382 [ V_6 ] . V_54 , & V_331 -> V_384 ) ;
}
V_331 -> V_14 = V_14 ;
}
static void
F_187 ( struct V_381 * V_331 )
{
struct V_72 * V_54 ;
int V_6 = 0 ;
F_140 (qe, &ucam_mod->free_q)
V_6 ++ ;
V_331 -> V_14 = NULL ;
}
static void
F_188 ( struct V_386 * V_387 , struct V_14 * V_14 ,
struct V_177 * V_178 )
{
int V_6 ;
V_387 -> V_388 = (struct V_325 * )
V_178 [ V_389 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ;
F_37 ( & V_387 -> V_384 ) ;
for ( V_6 = 0 ; V_6 < V_390 ; V_6 ++ ) {
F_32 ( & V_387 -> V_388 [ V_6 ] . V_54 ) ;
F_29 ( & V_387 -> V_388 [ V_6 ] . V_54 , & V_387 -> V_384 ) ;
}
V_387 -> V_14 = V_14 ;
}
static void
F_189 ( struct V_386 * V_387 )
{
struct V_72 * V_54 ;
int V_6 = 0 ;
F_140 (qe, &mcam_mod->free_q)
V_6 ++ ;
V_387 -> V_14 = NULL ;
}
static void
F_190 ( struct V_391 * V_392 ,
struct V_177 * V_178 )
{
int V_6 ;
int V_354 ;
int V_266 ;
int V_393 ;
V_392 -> V_394 = (struct V_395 * )
V_178 [ V_396 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ;
V_392 -> V_397 = (struct V_398 * )
V_178 [ V_399 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ;
V_266 = 0 ;
V_393 = 0 ;
for ( V_6 = 0 ; V_6 < V_400 ; V_6 ++ ) {
F_37 ( & V_392 -> V_401 [ V_6 ] ) ;
for ( V_354 = 0 ; V_354 < V_402 [ V_6 ] . V_403 ; V_354 ++ ) {
F_32 ( & V_392 -> V_397 [ V_266 ] . V_54 ) ;
V_392 -> V_397 [ V_266 ] . V_404 =
V_402 [ V_6 ] . V_405 ;
V_392 -> V_397 [ V_266 ] . V_406 = V_393 ;
V_392 -> V_397 [ V_266 ] . V_394 =
& V_392 -> V_394 [ V_393 ] ;
F_29 ( & V_392 -> V_397 [ V_266 ] . V_54 ,
& V_392 -> V_401 [ V_6 ] ) ;
V_266 ++ ;
V_393 += V_402 [ V_6 ] . V_405 ;
}
}
}
void
F_191 ( struct V_177 * V_178 )
{
F_137 ( V_178 ) ;
V_178 [ V_189 ] . V_197 = V_198 ;
V_178 [ V_189 ] . V_182 . V_183 . V_199 = V_200 ;
V_178 [ V_189 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_189 ] . V_182 . V_183 . V_202 =
F_138 ( F_192 () , V_203 ) ;
V_178 [ V_407 ] . V_197 = V_198 ;
V_178 [ V_407 ] . V_182 . V_183 . V_199 = V_200 ;
V_178 [ V_407 ] . V_182 . V_183 . V_202 =
V_408 * V_409 ;
V_178 [ V_407 ] . V_182 . V_183 . V_201 = V_410 ;
V_178 [ V_411 ] . V_197 = V_198 ;
V_178 [ V_411 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_411 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_411 ] . V_182 . V_183 . V_202 =
V_410 * sizeof( struct V_294 ) ;
V_178 [ V_412 ] . V_197 = V_198 ;
V_178 [ V_412 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_412 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_412 ] . V_182 . V_183 . V_202 =
V_410 * sizeof( struct V_413 ) ;
V_178 [ V_414 ] . V_197 = V_198 ;
V_178 [ V_414 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_414 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_414 ] . V_182 . V_183 . V_202 =
V_415 * sizeof( struct V_416 ) ;
V_178 [ V_417 ] . V_197 = V_198 ;
V_178 [ V_417 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_417 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_417 ] . V_182 . V_183 . V_202 =
V_418 * sizeof( struct V_210 ) ;
V_178 [ V_419 ] . V_197 = V_198 ;
V_178 [ V_419 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_419 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_419 ] . V_182 . V_183 . V_202 =
V_418 * sizeof( struct V_212 ) ;
V_178 [ V_420 ] . V_197 = V_198 ;
V_178 [ V_420 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_420 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_420 ] . V_182 . V_183 . V_202 =
V_421 * sizeof( struct V_214 ) ;
V_178 [ V_422 ] . V_197 = V_198 ;
V_178 [ V_422 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_422 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_422 ] . V_182 . V_183 . V_202 =
V_421 * sizeof( struct V_216 ) ;
V_178 [ V_423 ] . V_197 = V_198 ;
V_178 [ V_423 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_423 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_423 ] . V_182 . V_183 . V_202 =
V_421 * sizeof( struct V_424 ) ;
V_178 [ V_383 ] . V_197 = V_198 ;
V_178 [ V_383 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_383 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_383 ] . V_182 . V_183 . V_202 =
V_385 * sizeof( struct V_325 ) ;
V_178 [ V_389 ] . V_197 = V_198 ;
V_178 [ V_389 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_389 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_389 ] . V_182 . V_183 . V_202 =
V_390 * sizeof( struct V_325 ) ;
V_178 [ V_396 ] . V_197 = V_198 ;
V_178 [ V_396 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_396 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_396 ] . V_182 . V_183 . V_202 =
V_425 * sizeof( struct V_395 ) ;
V_178 [ V_399 ] . V_197 = V_198 ;
V_178 [ V_399 ] . V_182 . V_183 . V_199 =
V_204 ;
V_178 [ V_399 ] . V_182 . V_183 . V_201 = 1 ;
V_178 [ V_399 ] . V_182 . V_183 . V_202 =
V_426 * sizeof( struct V_398 ) ;
V_178 [ V_190 ] . V_197 = V_427 ;
V_178 [ V_190 ] . V_182 . V_191 . V_158 =
V_159 ;
V_178 [ V_190 ] . V_182 . V_191 . V_201 = 1 ;
}
void
F_193 ( struct V_14 * V_14 , struct V_17 * V_17 , struct V_428 * V_188 ,
struct V_177 * V_178 )
{
V_14 -> V_17 = V_17 ;
V_14 -> V_188 = * V_188 ;
V_14 -> V_271 . V_272 = (struct V_273 * )
V_178 [ V_205 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ;
V_14 -> V_290 . V_291 =
V_178 [ V_205 ] . V_182 . V_183 . V_184 [ 0 ] . V_180 . V_291 ;
V_14 -> V_290 . V_293 =
V_178 [ V_205 ] . V_182 . V_183 . V_184 [ 0 ] . V_180 . V_293 ;
V_14 -> V_271 . V_209 = (struct V_208 * )
V_178 [ V_207 ] . V_182 . V_183 . V_184 [ 0 ] . V_179 ;
V_14 -> V_429 . V_430 = V_14 -> V_188 . V_431 +
V_432 [ V_14 -> V_188 . V_433 ] . V_430 ;
V_14 -> V_429 . V_434 = V_14 -> V_188 . V_431 +
V_432 [ V_14 -> V_188 . V_433 ] . V_434 ;
V_14 -> V_429 . V_435 = V_14 -> V_188 . V_431 +
V_432 [ V_14 -> V_188 . V_433 ] . V_435 ;
if ( V_14 -> V_188 . V_433 < 3 )
V_14 -> V_436 = 0 ;
else
V_14 -> V_436 = 1 ;
F_125 ( & V_14 -> V_60 , V_14 , V_178 ) ;
F_89 ( & V_14 -> V_2 , V_14 ) ;
F_194 ( & V_14 -> V_15 , V_14 , V_178 ) ;
F_195 ( & V_14 -> V_285 , V_14 , V_178 ) ;
F_196 ( & V_14 -> V_437 , V_14 , V_178 ) ;
F_190 ( & V_14 -> V_392 , V_178 ) ;
F_186 ( & V_14 -> V_331 , V_14 , V_178 ) ;
F_188 ( & V_14 -> V_387 , V_14 , V_178 ) ;
V_14 -> V_336 = V_337 ;
F_32 ( & V_14 -> V_69 . V_54 ) ;
}
void
F_197 ( struct V_14 * V_14 )
{
F_189 ( & V_14 -> V_387 ) ;
F_187 ( & V_14 -> V_331 ) ;
F_198 ( & V_14 -> V_437 ) ;
F_199 ( & V_14 -> V_285 ) ;
F_200 ( & V_14 -> V_15 ) ;
F_90 ( & V_14 -> V_2 ) ;
F_129 ( & V_14 -> V_60 ) ;
V_14 -> V_17 = NULL ;
}
struct V_325 *
F_201 ( struct V_381 * V_331 )
{
struct V_72 * V_54 ;
if ( F_16 ( & V_331 -> V_384 ) )
return NULL ;
F_31 ( & V_331 -> V_384 , & V_54 ) ;
return (struct V_325 * ) V_54 ;
}
void
F_156 ( struct V_381 * V_331 , struct V_325 * V_154 )
{
F_29 ( & V_154 -> V_54 , & V_331 -> V_384 ) ;
}
struct V_325 *
F_202 ( struct V_386 * V_387 )
{
struct V_72 * V_54 ;
if ( F_16 ( & V_387 -> V_384 ) )
return NULL ;
F_31 ( & V_387 -> V_384 , & V_54 ) ;
return (struct V_325 * ) V_54 ;
}
void
F_203 ( struct V_386 * V_387 , struct V_325 * V_154 )
{
F_29 ( & V_154 -> V_54 , & V_387 -> V_384 ) ;
}
int
F_204 ( struct V_391 * V_392 , int V_438 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_400 ; V_6 ++ ) {
if ( V_438 <= V_402 [ V_6 ] . V_405 )
break;
}
if ( V_6 == V_400 )
return 0 ;
if ( F_16 ( & V_392 -> V_401 [ V_6 ] ) )
return 0 ;
return 1 ;
}
struct V_398 *
F_205 ( struct V_391 * V_392 , int V_438 )
{
struct V_398 * V_439 ;
struct V_72 * V_54 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_400 ; V_6 ++ ) {
if ( V_438 <= V_402 [ V_6 ] . V_405 )
break;
}
if ( V_6 == V_400 )
return NULL ;
if ( F_16 ( & V_392 -> V_401 [ V_6 ] ) )
return NULL ;
F_31 ( & V_392 -> V_401 [ V_6 ] , & V_54 ) ;
V_439 = (struct V_398 * ) V_54 ;
F_32 ( & V_439 -> V_54 ) ;
V_439 -> V_440 = V_438 ;
return V_439 ;
}
void
F_206 ( struct V_391 * V_392 ,
struct V_398 * V_439 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_400 ; V_6 ++ ) {
if ( V_439 -> V_404 == V_402 [ V_6 ] . V_405 )
break;
}
V_439 -> V_440 = 0 ;
F_29 ( & V_439 -> V_54 , & V_392 -> V_401 [ V_6 ] ) ;
}
