struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_4 + V_3 -> V_6 + V_3 -> V_7 ,
V_8 ) ;
if ( V_5 )
F_3 ( V_5 , V_3 -> V_6 ) ;
return V_5 ;
}
void F_4 ( struct V_1 * V_5 , T_1 V_9 , T_2 V_10 ,
T_3 V_11 , T_3 V_12 )
{
T_2 V_13 ;
V_13 = V_9 ( V_10 , V_5 -> V_14 , V_5 -> V_4 ) ;
if ( V_11 )
V_13 = ~ V_13 ;
if ( V_12 )
V_13 = F_5 ( V_13 ) ;
* F_6 ( V_5 , 1 ) = V_13 & 0xFF ;
* F_6 ( V_5 , 1 ) = ( V_13 >> 8 ) & 0xFF ;
}
int F_7 ( struct V_1 * V_5 , T_1 V_9 ,
T_2 V_15 , T_3 V_11 , T_3 V_12 )
{
int V_16 ;
T_2 V_13 ;
if ( V_5 -> V_4 <= 2 )
return - V_17 ;
V_13 = V_9 ( V_15 , V_5 -> V_14 , V_5 -> V_4 - 2 ) ;
if ( V_11 )
V_13 = ~ V_13 ;
if ( V_12 )
V_13 = F_8 ( V_13 ) ;
V_16 = ( V_5 -> V_14 [ V_5 -> V_4 - 2 ] - ( V_13 & 0xFF ) ) +
( V_5 -> V_14 [ V_5 -> V_4 - 1 ] - ( ( V_13 >> 8 ) & 0xFF ) ) ;
if ( V_16 )
return - V_17 ;
F_9 ( V_5 , V_5 -> V_4 - 2 ) ;
return 0 ;
}
static inline void F_10 ( struct V_2 * V_3 , bool V_18 )
{
V_3 -> V_19 -> V_20 ( V_3 , V_18 ) ;
}
static inline void F_11 ( struct V_2 * V_3 )
{
V_3 -> V_19 -> V_21 ( V_3 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_2 * V_3 = F_13 ( V_23 ,
struct V_2 ,
V_26 ) ;
F_14 ( & V_3 -> V_27 ) ;
V_25 = F_15 ( & V_3 -> V_28 , struct V_24 ,
V_29 ) ;
if ( ! V_25 ) {
F_16 ( & V_3 -> V_27 ) ;
return;
}
F_17 ( & V_25 -> V_29 ) ;
F_16 ( & V_3 -> V_27 ) ;
if ( ! F_18 ( V_25 -> V_30 ) )
F_19 ( L_1 , V_31 , 16 , 1 ,
V_25 -> V_30 -> V_14 , V_25 -> V_30 -> V_4 , false ) ;
V_25 -> V_32 ( V_3 , V_25 -> V_33 , V_25 -> V_30 ) ;
F_20 ( V_25 -> V_34 ) ;
F_20 ( V_25 ) ;
F_21 ( & V_3 -> V_35 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
void * V_36 , struct V_1 * V_30 )
{
struct V_24 * V_25 = V_36 ;
V_25 -> V_30 = V_30 ;
F_21 ( & V_3 -> V_26 ) ;
}
static void F_23 ( struct V_22 * V_23 )
{
int V_16 ;
struct V_24 * V_25 ;
struct V_37 * V_38 ;
struct V_2 * V_3 = F_13 ( V_23 ,
struct V_2 ,
V_35 ) ;
F_14 ( & V_3 -> V_27 ) ;
V_25 = F_15 ( & V_3 -> V_28 , struct V_24 ,
V_29 ) ;
if ( ! V_25 || V_25 -> V_39 ) {
F_16 ( & V_3 -> V_27 ) ;
return;
}
F_16 ( & V_3 -> V_27 ) ;
if ( V_25 -> V_40 )
F_19 ( L_2 , V_31 , 16 , 1 ,
V_25 -> V_40 -> V_14 , V_25 -> V_40 -> V_4 , false ) ;
switch ( V_25 -> type ) {
case V_41 :
V_16 = V_3 -> V_19 -> V_42 ( V_3 , V_25 -> V_40 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
case V_44 :
V_16 = V_3 -> V_19 -> V_45 ( V_3 , V_25 -> V_40 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
case V_46 :
V_16 = V_3 -> V_19 -> V_47 ( V_3 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
case V_48 :
V_38 = V_25 -> V_34 ;
V_16 = V_3 -> V_19 -> V_49 ( V_3 , V_38 , V_25 -> V_43 ,
F_22 , V_25 ) ;
break;
default:
F_24 ( L_3 , V_25 -> type ) ;
return;
}
if ( ! V_16 )
return;
F_24 ( L_4 , V_16 ) ;
F_14 ( & V_3 -> V_27 ) ;
F_17 ( & V_25 -> V_29 ) ;
F_16 ( & V_3 -> V_27 ) ;
F_25 ( V_25 -> V_40 ) ;
F_20 ( V_25 -> V_34 ) ;
F_20 ( V_25 ) ;
F_21 ( & V_3 -> V_35 ) ;
}
int F_26 ( struct V_2 * V_3 , T_3 V_50 ,
struct V_1 * V_5 , struct V_37 * V_38 ,
T_2 V_43 , T_4 V_32 ,
void * V_33 )
{
struct V_24 * V_25 ;
V_25 = F_27 ( sizeof( struct V_24 ) , V_8 ) ;
if ( ! V_25 )
return - V_51 ;
V_25 -> type = V_50 ;
V_25 -> V_43 = V_43 ;
V_25 -> V_40 = V_5 ;
V_25 -> V_34 = V_38 ;
V_25 -> V_32 = V_32 ;
V_25 -> V_33 = V_33 ;
F_28 ( & V_25 -> V_29 ) ;
F_14 ( & V_3 -> V_27 ) ;
F_29 ( & V_25 -> V_29 , & V_3 -> V_28 ) ;
F_16 ( & V_3 -> V_27 ) ;
F_21 ( & V_3 -> V_35 ) ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 , int type , int V_52 )
{
int V_16 ;
V_16 = V_3 -> V_19 -> V_53 ( V_3 , type , V_52 ) ;
if ( V_16 )
F_24 ( L_5 , V_16 ) ;
return V_16 ;
}
int F_31 ( struct V_2 * V_3 , int type , int V_52 )
{
int V_16 ;
V_16 = V_3 -> V_19 -> V_54 ( V_3 , type , V_52 ) ;
if ( V_16 )
F_24 ( L_6 , V_16 ) ;
return V_16 ;
}
static int F_32 ( struct V_2 * V_3 , T_3 V_55 )
{
struct V_37 * V_38 ;
V_38 = F_27 ( sizeof( struct V_37 ) , V_8 ) ;
if ( ! V_38 )
return - V_51 ;
V_38 -> V_56 = V_57 ;
F_33 ( V_38 -> V_58 , sizeof( V_38 -> V_58 ) ) ;
V_38 -> V_59 = V_60 ;
V_38 -> V_61 [ 0 ] = V_62 ;
V_38 -> V_61 [ 1 ] = V_63 ;
F_33 ( V_38 -> V_61 + 2 , V_64 - 2 ) ;
V_38 -> V_65 = V_66 ;
return F_26 ( V_3 , V_48 , NULL , V_38 ,
500 , V_67 , NULL ) ;
}
int F_34 ( struct V_2 * V_3 ,
struct V_68 * V_69 , T_3 V_70 )
{
int V_16 ;
T_3 V_71 ;
T_3 V_55 ;
int (* F_35)( struct V_1 * V_5 );
void (* F_36)( struct V_1 * V_5 );
V_55 = V_3 -> V_72 [ V_3 -> V_73 ] . V_55 ;
switch ( V_70 ) {
case V_74 :
V_71 = V_75 ;
F_35 = V_76 ;
F_36 = V_77 ;
break;
case V_78 :
V_71 = V_79 ;
F_35 = V_80 ;
F_36 = V_81 ;
break;
case V_82 :
V_71 = V_83 ;
F_35 = V_84 ;
F_36 = V_85 ;
break;
case V_86 :
if ( V_55 == V_87 ) {
V_71 = V_88 ;
F_35 = V_80 ;
F_36 = V_81 ;
} else {
V_71 = V_89 ;
F_35 = V_84 ;
F_36 = V_85 ;
}
break;
default:
F_24 ( L_7 , V_70 ) ;
return - V_90 ;
}
F_37 ( L_8 , V_55 , V_70 ) ;
V_3 -> V_91 = V_55 ;
V_3 -> V_92 = V_70 ;
if ( F_38 ( V_3 ) ) {
V_3 -> V_93 = V_94 ;
V_3 -> V_95 = V_96 ;
} else {
V_3 -> V_93 = F_36 ;
V_3 -> V_95 = F_35 ;
}
V_16 = F_30 ( V_3 , V_97 , V_71 ) ;
if ( V_16 )
return V_16 ;
V_69 -> V_98 = ( 1 << V_70 ) ;
V_16 = F_39 ( V_3 -> V_99 , V_69 , 1 ) ;
if ( V_16 )
return V_16 ;
V_3 -> V_100 = 0 ;
return 0 ;
}
void F_40 ( struct V_2 * V_3 )
{
F_10 ( V_3 , 0 ) ;
F_14 ( & V_3 -> V_101 ) ;
if ( ! V_3 -> V_100 ) {
F_16 ( & V_3 -> V_101 ) ;
return;
}
V_3 -> V_73 = ( V_3 -> V_73 + 1 ) %
V_3 -> V_100 ;
F_16 ( & V_3 -> V_101 ) ;
F_21 ( & V_3 -> V_102 ) ;
}
static void F_41 ( struct V_22 * V_23 )
{
int V_16 ;
struct V_103 * V_104 ;
struct V_2 * V_3 = F_13 ( V_23 ,
struct V_2 ,
V_102 ) ;
F_14 ( & V_3 -> V_101 ) ;
if ( ! V_3 -> V_100 ) {
F_16 ( & V_3 -> V_101 ) ;
return;
}
V_104 = & V_3 -> V_72 [ V_3 -> V_73 ] ;
F_16 ( & V_3 -> V_101 ) ;
V_16 = V_104 -> V_105 ( V_3 , V_104 -> V_55 ) ;
if ( V_16 )
F_40 ( V_3 ) ;
}
static void F_42 ( struct V_2 * V_3 , T_3 V_55 ,
T_5 V_105 )
{
struct V_103 * V_104 ;
if ( V_3 -> V_100 >= V_106 )
return;
V_104 = & V_3 -> V_72 [ V_3 -> V_100 ++ ] ;
V_104 -> V_55 = V_55 ;
V_104 -> V_105 = V_105 ;
}
static int F_43 ( struct V_99 * V_99 , T_6 V_107 ,
T_6 V_108 )
{
struct V_2 * V_3 = F_44 ( V_99 ) ;
T_7 V_109 , V_110 ;
F_37 ( L_9 , V_107 ,
V_108 , V_3 -> V_111 ) ;
V_109 = V_3 -> V_111 & V_107 ;
V_110 = V_3 -> V_111 & V_108 ;
if ( ! V_109 && ! V_110 ) {
F_24 ( L_10 ) ;
return - V_90 ;
}
if ( V_3 -> V_100 ) {
F_24 ( L_11 ) ;
return - V_112 ;
}
if ( V_3 -> V_92 ) {
F_24 ( L_12 ) ;
return - V_112 ;
}
V_3 -> V_100 = 0 ;
V_3 -> V_73 = 0 ;
if ( V_109 & V_113 )
F_42 ( V_3 , V_87 ,
V_114 ) ;
if ( V_107 & V_115 ) {
F_42 ( V_3 , V_116 ,
V_117 ) ;
F_42 ( V_3 , V_118 ,
V_117 ) ;
}
if ( V_108 & V_119 ) {
if ( V_3 -> V_19 -> V_49 ) {
F_42 ( V_3 , 0 ,
F_32 ) ;
} else {
F_42 ( V_3 , V_87 ,
V_120 ) ;
F_42 ( V_3 , V_116 ,
V_121 ) ;
F_42 ( V_3 , V_118 ,
V_121 ) ;
}
}
if ( ! V_3 -> V_100 ) {
F_24 ( L_13 ,
V_109 , V_110 ) ;
return - V_90 ;
}
F_21 ( & V_3 -> V_102 ) ;
return 0 ;
}
static void F_45 ( struct V_99 * V_99 )
{
struct V_2 * V_3 = F_44 ( V_99 ) ;
F_14 ( & V_3 -> V_101 ) ;
if ( ! V_3 -> V_100 ) {
F_24 ( L_14 ) ;
F_16 ( & V_3 -> V_101 ) ;
return;
}
V_3 -> V_100 = 0 ;
F_16 ( & V_3 -> V_101 ) ;
F_46 ( & V_3 -> V_102 ) ;
F_11 ( V_3 ) ;
}
static int F_47 ( struct V_99 * V_99 )
{
struct V_2 * V_3 = F_44 ( V_99 ) ;
F_10 ( V_3 , 1 ) ;
return 0 ;
}
static int F_48 ( struct V_99 * V_99 )
{
struct V_2 * V_3 = F_44 ( V_99 ) ;
F_10 ( V_3 , 0 ) ;
return 0 ;
}
static int F_49 ( struct V_99 * V_99 ,
struct V_68 * V_69 ,
T_8 V_122 , T_8 * V_123 , T_9 V_124 )
{
struct V_2 * V_3 = F_44 ( V_99 ) ;
return F_50 ( V_3 , V_69 , V_122 , V_123 , V_124 ) ;
}
static int F_51 ( struct V_99 * V_99 )
{
struct V_2 * V_3 = F_44 ( V_99 ) ;
V_3 -> V_92 = 0 ;
return 0 ;
}
static int F_52 ( struct V_99 * V_99 ,
struct V_68 * V_69 , T_6 V_70 )
{
return 0 ;
}
static void F_53 ( struct V_99 * V_99 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_44 ( V_99 ) ;
V_3 -> V_92 = 0 ;
}
static int F_54 ( struct V_99 * V_125 , struct V_1 * V_5 )
{
struct V_2 * V_3 = F_44 ( V_125 ) ;
return F_55 ( V_3 , V_5 ) ;
}
static void F_56 ( struct V_2 * V_3 , void * V_36 ,
struct V_1 * V_30 )
{
struct V_126 * V_127 = V_36 ;
int V_16 ;
if ( F_18 ( V_30 ) ) {
V_16 = F_57 ( V_30 ) ;
goto V_128;
}
if ( V_3 -> V_92 == V_78 )
V_16 = F_58 ( V_30 ) ;
else
V_16 = V_3 -> V_95 ( V_30 ) ;
if ( V_16 ) {
F_25 ( V_30 ) ;
V_30 = NULL ;
}
V_128:
V_127 -> V_129 ( V_127 -> V_33 , V_30 , V_16 ) ;
F_20 ( V_127 ) ;
}
static int F_59 ( struct V_99 * V_99 , struct V_68 * V_69 ,
struct V_1 * V_5 , T_10 V_129 ,
void * V_33 )
{
struct V_2 * V_3 = F_44 ( V_99 ) ;
struct V_126 * V_127 ;
V_127 = F_27 ( sizeof( struct V_126 ) , V_8 ) ;
if ( ! V_127 ) {
F_24 ( L_15 ) ;
return - V_51 ;
}
V_127 -> V_129 = V_129 ;
V_127 -> V_33 = V_33 ;
if ( V_3 -> V_92 == V_86 )
return F_60 ( V_3 , V_69 , V_5 , V_127 ) ;
V_3 -> V_93 ( V_5 ) ;
return F_61 ( V_3 , V_5 , 500 , F_56 ,
V_127 ) ;
}
struct V_2 * F_62 ( struct V_130 * V_19 ,
T_6 V_98 ,
T_6 V_131 ,
int V_6 , int V_7 )
{
struct V_2 * V_3 ;
if ( ! V_19 -> V_53 || ! V_19 -> V_42 || ! V_19 -> V_47 ||
! V_19 -> V_54 || ! V_19 -> V_45 || ! V_19 -> V_21 ||
! V_19 -> V_20 )
return NULL ;
V_3 = F_27 ( sizeof( struct V_2 ) , V_8 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_131 = V_131 ;
V_3 -> V_19 = V_19 ;
F_63 ( & V_3 -> V_27 ) ;
F_28 ( & V_3 -> V_28 ) ;
F_64 ( & V_3 -> V_35 , F_23 ) ;
F_64 ( & V_3 -> V_26 , F_12 ) ;
F_63 ( & V_3 -> V_101 ) ;
F_64 ( & V_3 -> V_102 , F_41 ) ;
if ( V_98 & V_132 )
V_3 -> V_111 |= V_132 ;
if ( V_98 & V_133 )
V_3 -> V_111 |= V_133 ;
if ( V_98 & V_134 )
V_3 -> V_111 |= V_134 ;
if ( V_98 & V_119 )
V_3 -> V_111 |= V_119 ;
V_3 -> V_6 = V_6 + V_135 ;
V_3 -> V_7 = V_7 + V_136 ;
V_3 -> V_99 = F_65 ( & V_137 , V_3 -> V_111 ,
V_3 -> V_6 ,
V_3 -> V_7 ) ;
if ( ! V_3 -> V_99 ) {
F_24 ( L_16 ) ;
goto V_138;
}
F_66 ( V_3 -> V_99 , V_3 ) ;
return V_3 ;
V_138:
F_20 ( V_3 ) ;
return NULL ;
}
void F_67 ( struct V_2 * V_3 )
{
F_68 ( V_3 -> V_99 ) ;
F_20 ( V_3 ) ;
}
int F_69 ( struct V_2 * V_3 )
{
return F_70 ( V_3 -> V_99 ) ;
}
void F_71 ( struct V_2 * V_3 )
{
struct V_24 * V_25 , * V_139 ;
F_72 ( V_3 -> V_99 ) ;
F_14 ( & V_3 -> V_101 ) ;
V_3 -> V_100 = 0 ;
F_16 ( & V_3 -> V_101 ) ;
F_46 ( & V_3 -> V_102 ) ;
F_46 ( & V_3 -> V_35 ) ;
F_46 ( & V_3 -> V_26 ) ;
F_73 (cmd, n, &ddev->cmd_queue, queue) {
F_17 ( & V_25 -> V_29 ) ;
F_20 ( V_25 -> V_34 ) ;
F_20 ( V_25 ) ;
}
}
