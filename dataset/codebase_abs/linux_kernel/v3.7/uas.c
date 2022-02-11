static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 ;
struct V_6 V_7 ;
unsigned long V_8 ;
int V_9 ;
F_2 ( & V_10 ) ;
F_3 ( & V_11 , & V_7 ) ;
F_4 ( & V_10 ) ;
F_5 (cmdinfo, temp, &list, list) {
struct V_12 * V_13 = ( void * ) V_4 ;
struct V_14 * V_15 = F_6 ( V_13 ,
struct V_14 , V_16 ) ;
struct V_17 * V_18 = ( void * ) V_15 -> V_19 -> V_20 ;
F_7 ( & V_18 -> V_21 , V_8 ) ;
V_9 = F_8 ( V_15 , V_15 -> V_19 -> V_20 , V_22 ) ;
F_9 ( & V_18 -> V_21 , V_8 ) ;
if ( V_9 ) {
F_10 ( & V_4 -> V_7 ) ;
F_2 ( & V_10 ) ;
F_11 ( & V_4 -> V_7 , & V_11 ) ;
F_4 ( & V_10 ) ;
F_12 ( & V_23 ) ;
}
}
}
static void F_13 ( struct V_24 * V_24 , struct V_14 * V_15 )
{
struct V_25 * V_25 = V_24 -> V_26 ;
struct V_27 * V_28 = V_15 -> V_19 ;
if ( V_24 -> V_29 > 16 ) {
unsigned V_30 = F_14 ( & V_25 -> V_30 ) ;
if ( V_30 + 16 != V_24 -> V_29 ) {
int V_31 = F_15 ( V_30 + 16 , V_24 -> V_29 ) - 16 ;
if ( V_31 < 0 )
V_31 = 0 ;
F_16 ( V_32 , V_28 , L_1
L_2
L_3 , V_33 ,
V_24 -> V_29 , V_30 , V_31 ) ;
V_30 = V_31 ;
}
memcpy ( V_15 -> V_34 , V_25 -> V_35 , V_30 ) ;
}
V_15 -> V_36 = V_25 -> V_37 ;
}
static void F_17 ( struct V_24 * V_24 , struct V_14 * V_15 )
{
struct V_38 * V_25 = V_24 -> V_26 ;
struct V_27 * V_28 = V_15 -> V_19 ;
if ( V_24 -> V_29 > 8 ) {
unsigned V_30 = F_14 ( & V_25 -> V_30 ) - 2 ;
if ( V_30 + 8 != V_24 -> V_29 ) {
int V_31 = F_15 ( V_30 + 8 , V_24 -> V_29 ) - 8 ;
if ( V_31 < 0 )
V_31 = 0 ;
F_16 ( V_32 , V_28 , L_1
L_2
L_3 , V_33 ,
V_24 -> V_29 , V_30 , V_31 ) ;
V_30 = V_31 ;
}
memcpy ( V_15 -> V_34 , V_25 -> V_35 , V_30 ) ;
}
V_15 -> V_36 = V_25 -> V_37 ;
}
static void F_18 ( struct V_14 * V_15 , const char * V_39 )
{
struct V_3 * V_40 = ( void * ) & V_15 -> V_16 ;
F_19 ( V_32 , V_15 , L_4
L_5 ,
V_39 , V_15 , V_15 -> V_41 -> V_42 ,
( V_40 -> V_43 & V_44 ) ? L_6 : L_7 ,
( V_40 -> V_43 & V_45 ) ? L_8 : L_7 ,
( V_40 -> V_43 & V_46 ) ? L_9 : L_7 ,
( V_40 -> V_43 & V_47 ) ? L_10 : L_7 ,
( V_40 -> V_43 & V_48 ) ? L_11 : L_7 ,
( V_40 -> V_43 & V_49 ) ? L_12 : L_7 ,
( V_40 -> V_43 & V_50 ) ? L_13 : L_7 ,
( V_40 -> V_43 & V_51 ) ? L_14 : L_7 ,
( V_40 -> V_43 & V_52 ) ? L_15 : L_7 ,
( V_40 -> V_43 & V_53 ) ? L_16 : L_7 ,
( V_40 -> V_43 & V_54 ) ? L_17 : L_7 ,
( V_40 -> V_43 & V_55 ) ? L_18 : L_7 ) ;
}
static int F_20 ( struct V_14 * V_15 , const char * V_39 )
{
struct V_3 * V_4 = ( void * ) & V_15 -> V_16 ;
struct V_17 * V_18 = ( void * ) V_15 -> V_19 -> V_20 ;
F_21 ( ! F_22 ( & V_18 -> V_21 ) ) ;
if ( V_4 -> V_43 & ( V_51 |
V_52 |
V_53 ) )
return - V_56 ;
F_23 ( V_4 -> V_43 & V_54 ) ;
V_4 -> V_43 |= V_54 ;
F_24 ( V_4 -> V_57 ) ;
F_24 ( V_4 -> V_58 ) ;
if ( V_4 -> V_43 & V_55 ) {
F_19 ( V_32 , V_15 , L_19 ) ;
V_15 -> V_36 = V_59 << 16 ;
}
V_15 -> V_60 ( V_15 ) ;
return 0 ;
}
static void F_25 ( struct V_24 * V_24 , struct V_14 * V_15 ,
unsigned V_61 )
{
struct V_3 * V_4 = ( void * ) & V_15 -> V_16 ;
int V_9 ;
V_4 -> V_43 |= V_61 | V_44 ;
V_9 = F_8 ( V_15 , V_15 -> V_19 -> V_20 , V_22 ) ;
if ( V_9 ) {
F_26 ( & V_10 ) ;
F_11 ( & V_4 -> V_7 , & V_11 ) ;
F_27 ( & V_10 ) ;
F_12 ( & V_23 ) ;
}
}
static void F_28 ( struct V_24 * V_24 )
{
struct V_62 * V_62 = V_24 -> V_26 ;
struct V_63 * V_64 = V_24 -> V_65 ;
struct V_17 * V_18 = ( void * ) V_64 -> V_20 [ 0 ] ;
struct V_14 * V_15 ;
struct V_3 * V_4 ;
unsigned long V_8 ;
T_1 V_42 ;
if ( V_24 -> V_37 ) {
F_29 ( & V_24 -> V_66 -> V_66 , L_20 , V_24 -> V_37 ) ;
F_24 ( V_24 ) ;
return;
}
if ( V_18 -> V_67 ) {
F_24 ( V_24 ) ;
return;
}
F_7 ( & V_18 -> V_21 , V_8 ) ;
V_42 = F_14 ( & V_62 -> V_42 ) - 1 ;
if ( V_42 == 0 )
V_15 = V_18 -> V_15 ;
else
V_15 = F_30 ( V_64 , V_42 - 1 ) ;
if ( ! V_15 ) {
if ( V_62 -> V_68 == V_69 ) {
memcpy ( & V_18 -> V_70 , V_62 , sizeof( V_18 -> V_70 ) ) ;
}
F_24 ( V_24 ) ;
F_9 ( & V_18 -> V_21 , V_8 ) ;
return;
}
V_4 = ( void * ) & V_15 -> V_16 ;
switch ( V_62 -> V_68 ) {
case V_71 :
if ( V_18 -> V_15 == V_15 )
V_18 -> V_15 = NULL ;
if ( V_24 -> V_29 < 16 )
V_18 -> F_17 = 1 ;
if ( V_18 -> F_17 )
F_17 ( V_24 , V_15 ) ;
else
F_13 ( V_24 , V_15 ) ;
if ( V_15 -> V_36 != 0 ) {
if ( V_4 -> V_43 & V_52 ) {
F_9 ( & V_18 -> V_21 , V_8 ) ;
F_31 ( V_4 -> V_57 ) ;
F_7 ( & V_18 -> V_21 , V_8 ) ;
}
if ( V_4 -> V_43 & V_53 ) {
F_9 ( & V_18 -> V_21 , V_8 ) ;
F_31 ( V_4 -> V_58 ) ;
F_7 ( & V_18 -> V_21 , V_8 ) ;
}
}
V_4 -> V_43 &= ~ V_51 ;
F_20 ( V_15 , V_33 ) ;
break;
case V_72 :
F_25 ( V_24 , V_15 , V_46 ) ;
break;
case V_73 :
F_25 ( V_24 , V_15 , V_48 ) ;
break;
default:
F_19 ( V_74 , V_15 ,
L_21 , V_62 -> V_68 ) ;
}
F_24 ( V_24 ) ;
F_9 ( & V_18 -> V_21 , V_8 ) ;
}
static void F_32 ( struct V_24 * V_24 )
{
struct V_14 * V_15 = V_24 -> V_65 ;
struct V_3 * V_4 = ( void * ) & V_15 -> V_16 ;
struct V_17 * V_18 = ( void * ) V_15 -> V_19 -> V_20 ;
struct V_75 * V_76 = NULL ;
unsigned long V_8 ;
F_7 ( & V_18 -> V_21 , V_8 ) ;
if ( V_4 -> V_57 == V_24 ) {
V_76 = F_33 ( V_15 ) ;
V_4 -> V_43 &= ~ V_52 ;
} else if ( V_4 -> V_58 == V_24 ) {
V_76 = F_34 ( V_15 ) ;
V_4 -> V_43 &= ~ V_53 ;
}
F_23 ( V_76 == NULL ) ;
if ( V_24 -> V_37 ) {
V_76 -> V_77 = V_76 -> V_78 ;
} else {
V_76 -> V_77 = V_76 -> V_78 - V_24 -> V_29 ;
}
F_20 ( V_15 , V_33 ) ;
F_9 ( & V_18 -> V_21 , V_8 ) ;
}
static struct V_24 * F_35 ( struct V_17 * V_18 , T_2 V_79 ,
unsigned int V_80 , T_1 V_81 ,
struct V_14 * V_15 ,
enum V_82 V_83 )
{
struct V_84 * V_85 = V_18 -> V_85 ;
struct V_24 * V_24 = F_36 ( 0 , V_79 ) ;
struct V_75 * V_76 = ( V_83 == V_86 )
? F_33 ( V_15 ) : F_34 ( V_15 ) ;
if ( ! V_24 )
goto V_87;
F_37 ( V_24 , V_85 , V_80 , NULL , V_76 -> V_78 ,
F_32 , V_15 ) ;
if ( V_18 -> V_88 )
V_24 -> V_81 = V_81 ;
V_24 -> V_89 = V_85 -> V_90 -> V_91 ? V_76 -> V_92 . V_93 : 0 ;
V_24 -> V_94 = V_76 -> V_92 . V_95 ;
V_87:
return V_24 ;
}
static struct V_24 * F_38 ( struct V_17 * V_18 , T_2 V_79 ,
struct V_63 * V_64 , T_1 V_81 )
{
struct V_84 * V_85 = V_18 -> V_85 ;
struct V_24 * V_24 = F_36 ( 0 , V_79 ) ;
struct V_25 * V_62 ;
if ( ! V_24 )
goto V_87;
V_62 = F_39 ( sizeof( * V_62 ) , V_79 ) ;
if ( ! V_62 )
goto free;
F_37 ( V_24 , V_85 , V_18 -> V_96 , V_62 , sizeof( * V_62 ) ,
F_28 , V_64 ) ;
V_24 -> V_81 = V_81 ;
V_24 -> V_97 |= V_98 ;
V_87:
return V_24 ;
free:
F_24 ( V_24 ) ;
return NULL ;
}
static struct V_24 * F_40 ( struct V_17 * V_18 , T_2 V_79 ,
struct V_14 * V_15 , T_1 V_81 )
{
struct V_84 * V_85 = V_18 -> V_85 ;
struct V_27 * V_28 = V_15 -> V_19 ;
struct V_24 * V_24 = F_36 ( 0 , V_79 ) ;
struct V_99 * V_62 ;
int V_30 ;
if ( ! V_24 )
goto V_87;
V_30 = V_15 -> V_100 - 16 ;
if ( V_30 < 0 )
V_30 = 0 ;
V_30 = F_41 ( V_30 , 4 ) ;
V_62 = F_39 ( sizeof( * V_62 ) + V_30 , V_79 ) ;
if ( ! V_62 )
goto free;
V_62 -> V_68 = V_101 ;
if ( F_42 ( V_15 -> V_41 ) )
V_62 -> V_42 = F_43 ( V_15 -> V_41 -> V_42 + 2 ) ;
else
V_62 -> V_42 = F_43 ( 1 ) ;
V_62 -> V_102 = V_103 ;
V_62 -> V_30 = V_30 ;
F_44 ( V_28 -> V_104 , & V_62 -> V_104 ) ;
memcpy ( V_62 -> V_105 , V_15 -> V_15 , V_15 -> V_100 ) ;
F_37 ( V_24 , V_85 , V_18 -> V_106 , V_62 , sizeof( * V_62 ) + V_30 ,
F_24 , NULL ) ;
V_24 -> V_97 |= V_98 ;
V_87:
return V_24 ;
free:
F_24 ( V_24 ) ;
return NULL ;
}
static int F_45 ( struct V_14 * V_15 , T_2 V_79 ,
T_3 V_107 , T_1 V_81 )
{
struct V_17 * V_18 = ( void * ) V_15 -> V_19 -> V_20 ;
struct V_84 * V_85 = V_18 -> V_85 ;
struct V_24 * V_24 = F_36 ( 0 , V_79 ) ;
struct V_108 * V_62 ;
int V_9 = - V_109 ;
if ( ! V_24 )
goto V_9;
V_62 = F_39 ( sizeof( * V_62 ) , V_79 ) ;
if ( ! V_62 )
goto V_9;
V_62 -> V_68 = V_110 ;
V_62 -> V_42 = F_43 ( V_81 ) ;
F_44 ( V_15 -> V_19 -> V_104 , & V_62 -> V_104 ) ;
V_62 -> V_107 = V_107 ;
switch ( V_107 ) {
case V_111 :
if ( F_42 ( V_15 -> V_41 ) )
V_62 -> V_112 = F_43 ( V_15 -> V_41 -> V_42 + 2 ) ;
else
V_62 -> V_112 = F_43 ( 1 ) ;
break;
}
F_37 ( V_24 , V_85 , V_18 -> V_106 , V_62 , sizeof( * V_62 ) ,
F_24 , NULL ) ;
V_24 -> V_97 |= V_98 ;
V_9 = F_46 ( V_24 , V_79 ) ;
if ( V_9 )
goto V_9;
F_47 ( V_24 , & V_18 -> V_113 ) ;
return 0 ;
V_9:
F_24 ( V_24 ) ;
return V_9 ;
}
static int F_48 ( struct V_63 * V_64 ,
T_2 V_79 , unsigned int V_114 )
{
struct V_17 * V_18 = ( void * ) V_64 -> V_20 [ 0 ] ;
struct V_24 * V_24 ;
V_24 = F_38 ( V_18 , V_79 , V_64 , V_114 ) ;
if ( ! V_24 )
return V_115 ;
if ( F_46 ( V_24 , V_79 ) ) {
F_49 ( V_32 , V_64 ,
L_22 ) ;
F_24 ( V_24 ) ;
return V_115 ;
}
F_47 ( V_24 , & V_18 -> V_116 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 ,
struct V_17 * V_18 , T_2 V_79 )
{
struct V_3 * V_4 = ( void * ) & V_15 -> V_16 ;
int V_9 ;
F_21 ( ! F_22 ( & V_18 -> V_21 ) ) ;
if ( V_4 -> V_43 & V_44 ) {
V_9 = F_48 ( V_15 -> V_19 -> V_117 , V_79 ,
V_4 -> V_114 ) ;
if ( V_9 ) {
return V_9 ;
}
V_4 -> V_43 &= ~ V_44 ;
}
if ( V_4 -> V_43 & V_45 ) {
V_4 -> V_57 = F_35 ( V_18 , V_79 ,
V_18 -> V_118 , V_4 -> V_114 ,
V_15 , V_86 ) ;
if ( ! V_4 -> V_57 )
return V_115 ;
V_4 -> V_43 &= ~ V_45 ;
}
if ( V_4 -> V_43 & V_46 ) {
if ( F_46 ( V_4 -> V_57 , V_79 ) ) {
F_19 ( V_32 , V_15 ,
L_23 ) ;
return V_115 ;
}
V_4 -> V_43 &= ~ V_46 ;
V_4 -> V_43 |= V_52 ;
F_47 ( V_4 -> V_57 , & V_18 -> V_119 ) ;
}
if ( V_4 -> V_43 & V_47 ) {
V_4 -> V_58 = F_35 ( V_18 , V_79 ,
V_18 -> V_120 , V_4 -> V_114 ,
V_15 , V_121 ) ;
if ( ! V_4 -> V_58 )
return V_115 ;
V_4 -> V_43 &= ~ V_47 ;
}
if ( V_4 -> V_43 & V_48 ) {
if ( F_46 ( V_4 -> V_58 , V_79 ) ) {
F_19 ( V_32 , V_15 ,
L_24 ) ;
return V_115 ;
}
V_4 -> V_43 &= ~ V_48 ;
V_4 -> V_43 |= V_53 ;
F_47 ( V_4 -> V_58 , & V_18 -> V_119 ) ;
}
if ( V_4 -> V_43 & V_49 ) {
V_4 -> V_122 = F_40 ( V_18 , V_79 , V_15 ,
V_4 -> V_114 ) ;
if ( ! V_4 -> V_122 )
return V_115 ;
V_4 -> V_43 &= ~ V_49 ;
}
if ( V_4 -> V_43 & V_50 ) {
F_50 ( V_4 -> V_122 ) ;
if ( F_46 ( V_4 -> V_122 , V_79 ) ) {
F_19 ( V_32 , V_15 ,
L_25 ) ;
return V_115 ;
}
F_47 ( V_4 -> V_122 , & V_18 -> V_113 ) ;
F_51 ( V_4 -> V_122 ) ;
V_4 -> V_122 = NULL ;
V_4 -> V_43 &= ~ V_50 ;
V_4 -> V_43 |= V_51 ;
}
return 0 ;
}
static int F_52 ( struct V_14 * V_15 ,
void (* F_53)( struct V_14 * ) )
{
struct V_27 * V_28 = V_15 -> V_19 ;
struct V_17 * V_18 = V_28 -> V_20 ;
struct V_3 * V_4 = ( void * ) & V_15 -> V_16 ;
unsigned long V_8 ;
int V_9 ;
F_54 ( sizeof( struct V_3 ) > sizeof( struct V_12 ) ) ;
F_7 ( & V_18 -> V_21 , V_8 ) ;
if ( V_18 -> V_15 ) {
F_9 ( & V_18 -> V_21 , V_8 ) ;
return V_115 ;
}
if ( F_42 ( V_15 -> V_41 ) ) {
V_4 -> V_114 = V_15 -> V_41 -> V_42 + 2 ;
} else {
V_18 -> V_15 = V_15 ;
V_4 -> V_114 = 1 ;
}
V_15 -> V_60 = F_53 ;
V_4 -> V_43 = V_44 |
V_49 | V_50 ;
switch ( V_15 -> V_123 ) {
case V_86 :
V_4 -> V_43 |= V_45 | V_46 ;
break;
case V_124 :
V_4 -> V_43 |= V_45 | V_46 ;
case V_121 :
V_4 -> V_43 |= V_47 | V_48 ;
case V_125 :
break;
}
if ( ! V_18 -> V_88 ) {
V_4 -> V_43 &= ~ ( V_46 | V_48 ) ;
V_4 -> V_114 = 0 ;
}
V_9 = F_8 ( V_15 , V_18 , V_22 ) ;
if ( V_9 ) {
if ( V_4 -> V_43 & V_44 ) {
F_9 ( & V_18 -> V_21 , V_8 ) ;
return V_115 ;
}
F_26 ( & V_10 ) ;
F_11 ( & V_4 -> V_7 , & V_11 ) ;
F_27 ( & V_10 ) ;
F_12 ( & V_23 ) ;
}
F_9 ( & V_18 -> V_21 , V_8 ) ;
return 0 ;
}
int F_55 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = ( void * ) & V_15 -> V_16 ;
struct V_17 * V_18 = ( void * ) V_15 -> V_19 -> V_20 ;
unsigned long V_8 ;
int V_126 ;
F_18 ( V_15 , V_33 ) ;
F_7 ( & V_18 -> V_21 , V_8 ) ;
V_4 -> V_43 |= V_55 ;
F_9 ( & V_18 -> V_21 , V_8 ) ;
V_126 = F_56 ( V_15 , L_26 , V_111 ) ;
return V_126 ;
}
static int F_57 ( struct V_14 * V_15 )
{
F_16 ( V_32 , V_15 -> V_19 , L_27 , V_33 ) ;
return F_56 ( V_15 , L_28 ,
V_127 ) ;
}
static int F_58 ( struct V_14 * V_15 )
{
struct V_27 * V_28 = V_15 -> V_19 ;
struct V_17 * V_18 = V_28 -> V_20 ;
struct V_84 * V_85 = V_18 -> V_85 ;
int V_9 ;
V_18 -> V_67 = 1 ;
F_59 ( & V_18 -> V_113 ) ;
F_59 ( & V_18 -> V_116 ) ;
F_59 ( & V_18 -> V_119 ) ;
V_9 = F_60 ( V_85 ) ;
V_18 -> V_67 = 0 ;
if ( V_9 ) {
F_49 ( V_32 , V_28 -> V_117 , L_29 , V_33 ) ;
return V_128 ;
}
F_49 ( V_32 , V_28 -> V_117 , L_30 , V_33 ) ;
return V_129 ;
}
static int F_61 ( struct V_27 * V_28 )
{
V_28 -> V_20 = ( void * ) V_28 -> V_117 -> V_20 [ 0 ] ;
return 0 ;
}
static int F_62 ( struct V_27 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_20 ;
F_63 ( V_28 , V_130 ) ;
F_64 ( V_28 , V_18 -> V_131 - 3 ) ;
return 0 ;
}
static int F_65 ( struct V_132 * V_133 )
{
return ( V_133 -> V_134 . V_135 == V_136 &&
V_133 -> V_134 . V_137 == V_138 &&
V_133 -> V_134 . V_139 == V_140 ) ;
}
static int F_66 ( struct V_84 * V_85 )
{
struct V_141 * V_142 = F_67 ( V_85 -> V_90 ) ;
F_68 ( & V_85 -> V_66 , L_31
L_32 ,
V_142 -> V_143 -> V_144 ) ;
F_68 ( & V_85 -> V_66 , L_33
L_34 ) ;
return - V_145 ;
}
static int F_69 ( struct V_84 * V_85 ,
struct V_146 * V_133 )
{
int V_147 ;
int V_148 = V_85 -> V_90 -> V_91 != 0 ;
for ( V_147 = 0 ; V_147 < V_133 -> V_149 ; V_147 ++ ) {
struct V_132 * V_150 = & V_133 -> V_151 [ V_147 ] ;
if ( F_65 ( V_150 ) ) {
if ( ! V_148 )
return F_66 ( V_85 ) ;
return F_70 ( V_85 ,
V_150 -> V_134 . V_152 ,
V_150 -> V_134 . V_153 ) ;
}
}
return - V_145 ;
}
static void F_71 ( struct V_17 * V_18 )
{
struct V_154 * V_155 [ 4 ] = { } ;
struct V_146 * V_133 = V_18 -> V_133 ;
struct V_84 * V_85 = V_18 -> V_85 ;
struct V_154 * V_156 = V_133 -> V_157 -> V_156 ;
unsigned V_147 , V_158 = V_133 -> V_157 -> V_134 . V_159 ;
V_18 -> F_17 = 0 ;
V_18 -> V_15 = NULL ;
for ( V_147 = 0 ; V_147 < V_158 ; V_147 ++ ) {
unsigned char * V_160 = V_156 [ V_147 ] . V_160 ;
int V_30 = V_156 [ V_147 ] . V_161 ;
while ( V_30 > 1 ) {
if ( V_160 [ 1 ] == V_162 ) {
unsigned V_163 = V_160 [ 2 ] ;
if ( V_163 > 0 && V_163 < 5 )
V_155 [ V_163 - 1 ] = & V_156 [ V_147 ] ;
break;
}
V_30 -= V_160 [ 0 ] ;
V_160 += V_160 [ 0 ] ;
}
}
if ( ! V_155 [ 0 ] ) {
V_18 -> V_106 = F_72 ( V_85 , 1 ) ;
V_18 -> V_96 = F_73 ( V_85 , 1 ) ;
V_18 -> V_118 = F_73 ( V_85 , 2 ) ;
V_18 -> V_120 = F_72 ( V_85 , 2 ) ;
V_155 [ 1 ] = F_74 ( V_85 , V_18 -> V_96 ) ;
V_155 [ 2 ] = F_74 ( V_85 , V_18 -> V_118 ) ;
V_155 [ 3 ] = F_74 ( V_85 , V_18 -> V_120 ) ;
} else {
V_18 -> V_106 = F_72 ( V_85 ,
V_155 [ 0 ] -> V_134 . V_164 ) ;
V_18 -> V_96 = F_73 ( V_85 ,
V_155 [ 1 ] -> V_134 . V_164 ) ;
V_18 -> V_118 = F_73 ( V_85 ,
V_155 [ 2 ] -> V_134 . V_164 ) ;
V_18 -> V_120 = F_72 ( V_85 ,
V_155 [ 3 ] -> V_134 . V_164 ) ;
}
V_18 -> V_131 = F_75 ( V_18 -> V_133 , V_155 + 1 , 3 , 256 ,
V_165 ) ;
if ( V_18 -> V_131 < 0 ) {
V_18 -> V_131 = 256 ;
V_18 -> V_88 = 0 ;
} else {
V_18 -> V_88 = 1 ;
}
}
static void F_76 ( struct V_17 * V_18 )
{
struct V_84 * V_85 = V_18 -> V_85 ;
struct V_154 * V_155 [ 3 ] ;
V_155 [ 0 ] = F_74 ( V_85 , V_18 -> V_96 ) ;
V_155 [ 1 ] = F_74 ( V_85 , V_18 -> V_118 ) ;
V_155 [ 2 ] = F_74 ( V_85 , V_18 -> V_120 ) ;
F_77 ( V_18 -> V_133 , V_155 , 3 , V_165 ) ;
}
static int F_78 ( struct V_146 * V_133 , const struct V_166 * V_167 )
{
int V_36 ;
struct V_63 * V_64 ;
struct V_17 * V_18 ;
struct V_84 * V_85 = F_79 ( V_133 ) ;
if ( F_69 ( V_85 , V_133 ) )
return - V_145 ;
V_18 = F_80 ( sizeof( struct V_17 ) , V_165 ) ;
if ( ! V_18 )
return - V_109 ;
V_36 = - V_109 ;
V_64 = F_81 ( & V_168 , sizeof( void * ) ) ;
if ( ! V_64 )
goto free;
V_64 -> V_169 = 16 + 252 ;
V_64 -> V_170 = 1 ;
V_64 -> V_91 = V_85 -> V_90 -> V_91 ;
V_18 -> V_133 = V_133 ;
V_18 -> V_85 = V_85 ;
V_18 -> V_67 = 0 ;
F_82 ( & V_18 -> V_113 ) ;
F_82 ( & V_18 -> V_116 ) ;
F_82 ( & V_18 -> V_119 ) ;
F_83 ( & V_18 -> V_21 ) ;
F_71 ( V_18 ) ;
V_36 = F_84 ( V_64 , V_18 -> V_131 - 3 ) ;
if ( V_36 )
goto free;
V_36 = F_85 ( V_64 , & V_133 -> V_66 ) ;
if ( V_36 )
goto V_171;
V_64 -> V_20 [ 0 ] = ( unsigned long ) V_18 ;
F_86 ( V_64 ) ;
F_87 ( V_133 , V_64 ) ;
return V_36 ;
V_171:
F_76 ( V_18 ) ;
free:
F_88 ( V_18 ) ;
if ( V_64 )
F_89 ( V_64 ) ;
return V_36 ;
}
static int F_90 ( struct V_146 * V_133 )
{
return 0 ;
}
static int F_91 ( struct V_146 * V_133 )
{
return 0 ;
}
static void F_92 ( struct V_146 * V_133 )
{
struct V_63 * V_64 = F_93 ( V_133 ) ;
struct V_17 * V_18 = ( void * ) V_64 -> V_20 [ 0 ] ;
F_94 ( V_64 ) ;
F_59 ( & V_18 -> V_113 ) ;
F_59 ( & V_18 -> V_116 ) ;
F_59 ( & V_18 -> V_119 ) ;
F_76 ( V_18 ) ;
F_88 ( V_18 ) ;
}
