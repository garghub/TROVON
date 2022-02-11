static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( V_5 -> V_8 ) ;
}
static void F_3 ( struct V_2 * V_3 , bool V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_10 * V_13 = V_12 -> V_14 ;
if ( V_13 )
F_5 ( & V_12 -> V_15 , V_13 ) ;
F_6 ( V_11 ) ;
V_12 -> V_16 . V_14 = V_11 ;
V_12 -> V_14 = V_11 ;
if ( ! V_9 ) {
F_7 ( F_1 ( V_3 ) , & V_12 -> V_17 ) ;
}
}
static void F_8 ( struct V_2 * V_3 , bool V_18 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_20 * V_21 ;
unsigned long V_22 ;
F_9 ( & V_6 -> V_23 , V_22 ) ;
V_21 = V_12 -> V_21 ;
if ( V_21 ) {
V_12 -> V_21 = NULL ;
if ( V_18 )
V_21 -> V_16 . V_24 ( & V_21 -> V_16 ) ;
else
F_10 ( V_6 , V_12 -> V_25 , V_21 ) ;
}
F_11 ( & V_6 -> V_23 , V_22 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_26 = 0 ;
V_26 |= F_13 ( F_14 ( V_12 -> V_27 ) ) ;
V_26 |= F_15 ( V_12 -> V_28 ) ;
F_16 ( L_1 , V_12 -> V_29 , V_26 ) ;
F_17 ( V_1 , V_30 , V_26 ) ;
}
static void F_18 ( struct V_31 * V_32 )
{
struct V_12 * V_12 =
F_19 ( V_32 , struct V_12 , V_33 ) ;
struct V_2 * V_3 = & V_12 -> V_16 ;
F_20 ( V_12 -> V_27 , V_3 -> V_14 ) ;
F_12 ( V_3 ) ;
F_7 ( F_1 ( V_3 ) , & V_12 -> V_17 ) ;
}
static void F_21 ( struct V_34 * V_32 , void * V_35 )
{
struct V_12 * V_12 =
F_19 ( V_32 , struct V_12 , V_15 ) ;
struct V_19 * V_6 = V_12 -> V_16 . V_6 ;
F_22 ( & V_6 -> V_36 . V_37 ) ;
F_23 ( V_35 ) ;
F_24 ( & V_6 -> V_36 . V_37 ) ;
}
static void F_25 ( struct V_34 * V_32 , void * V_35 )
{
struct V_12 * V_12 =
F_19 ( V_32 , struct V_12 , V_38 ) ;
struct V_1 * V_1 = F_1 ( & V_12 -> V_16 ) ;
F_26 ( V_35 , V_1 -> V_25 ) ;
F_27 ( V_35 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
V_12 -> V_27 -> V_39 -> V_24 ( V_12 -> V_27 ) ;
F_29 ( V_3 ) ;
F_30 ( & V_12 -> V_15 ) ;
F_30 ( & V_12 -> V_38 ) ;
F_31 ( V_12 ) ;
}
static void F_32 ( struct V_2 * V_3 , int V_40 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_41 = ( V_40 == V_42 ) ;
F_16 ( L_2 , V_12 -> V_29 , V_40 ) ;
if ( V_41 != V_12 -> V_41 ) {
if ( V_41 ) {
F_33 ( V_1 ) ;
F_7 ( V_1 , & V_12 -> V_43 ) ;
} else {
F_34 ( V_1 , & V_12 -> V_43 ) ;
F_35 ( V_1 ) ;
}
V_12 -> V_41 = V_41 ;
}
}
static bool F_36 ( struct V_2 * V_3 ,
const struct V_44 * V_40 ,
struct V_44 * V_45 )
{
return true ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_46 , V_28 = V_12 -> V_28 ;
T_1 V_47 = 0 ;
F_17 ( V_1 , F_38 ( V_28 ) , 0 ) ;
F_17 ( V_1 , F_39 ( V_28 ) , 0 ) ;
F_17 ( V_1 , F_40 ( V_28 ) , 0 ) ;
F_17 ( V_1 , F_41 ( V_28 ) , 0 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
F_17 ( V_1 , F_42 ( V_28 , V_46 ) , 0 ) ;
F_17 ( V_1 , F_43 ( V_28 , V_46 ) , 0 ) ;
F_17 ( V_1 , F_44 ( V_28 , V_46 ) ,
F_45 ( V_48 ) |
F_46 ( V_49 ) ) ;
F_17 ( V_1 , F_47 ( V_28 , V_46 ) , 0 ) ;
F_17 ( V_1 , F_48 ( V_28 , V_46 ) , 0 ) ;
F_17 ( V_1 , F_49 ( V_28 , V_46 ) , 0 ) ;
F_17 ( V_1 , F_50 ( V_28 , V_46 ) , 0 ) ;
F_17 ( V_1 , F_51 ( V_28 , V_46 ) , 0 ) ;
}
switch ( F_14 ( V_12 -> V_27 ) ) {
case V_50 :
V_47 = F_52 ( V_51 ) |
F_53 ( V_12 -> V_52 == 1 , V_53 ) ;
break;
case V_54 :
V_47 = F_54 ( V_51 ) |
F_53 ( V_12 -> V_52 == 1 , V_55 ) ;
break;
case V_56 :
V_47 = F_55 ( V_51 ) |
F_53 ( V_12 -> V_52 == 1 , V_57 ) ;
break;
case V_58 :
V_47 = F_56 ( V_51 ) |
F_53 ( V_12 -> V_52 == 1 , V_59 ) ;
break;
case V_60 :
V_47 = F_57 ( V_51 ) |
F_53 ( V_12 -> V_52 == 1 , V_61 ) ;
break;
case V_62 :
V_47 = F_58 ( V_51 ) |
F_53 ( V_12 -> V_52 == 1 , V_63 ) ;
break;
case V_64 :
V_47 = F_59 ( V_51 ) |
F_53 ( V_12 -> V_52 == 1 , V_65 ) ;
break;
default:
F_60 ( L_3 ) ;
break;
}
F_17 ( V_1 , V_66 , V_47 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_44 * V_40 ,
struct V_44 * V_45 ,
int V_67 , int V_68 ,
struct V_10 * V_13 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_69 V_70 = V_12 -> V_70 ;
int V_71 , V_28 = V_12 -> V_28 ;
V_40 = V_45 ;
F_16 ( L_4 ,
V_12 -> V_29 , V_40 -> V_16 . V_25 , V_40 -> V_29 ,
V_40 -> V_72 , V_40 -> clock ,
V_40 -> V_73 , V_40 -> V_74 ,
V_40 -> V_75 , V_40 -> V_76 ,
V_40 -> V_77 , V_40 -> V_78 ,
V_40 -> V_79 , V_40 -> V_80 ,
V_40 -> type , V_40 -> V_22 ) ;
F_17 ( V_1 , F_62 ( V_70 ) ,
F_63 ( V_40 -> V_73 ) |
F_64 ( V_40 -> V_77 ) ) ;
F_17 ( V_1 , F_65 ( V_70 ) , 0 ) ;
F_17 ( V_1 , F_66 ( V_70 ) ,
V_3 -> V_14 -> V_81 [ 0 ] ) ;
F_17 ( V_1 , F_67 ( V_70 ) ,
F_68 ( 0 ) |
F_69 ( 0 ) ) ;
F_17 ( V_1 , F_70 ( V_28 ) , 0 ) ;
F_17 ( V_1 , F_71 ( V_28 ) ,
F_72 ( V_40 -> V_73 ) |
F_73 ( V_40 -> V_77 ) ) ;
F_17 ( V_1 , F_74 ( V_28 ) ,
V_3 -> V_14 -> V_81 [ 0 ] ) ;
F_17 ( V_1 , F_75 ( V_28 ) , 1 ) ;
F_3 ( V_3 , false , V_3 -> V_14 ) ;
V_71 = F_76 ( V_12 -> V_27 , V_3 , V_3 -> V_14 ,
0 , 0 , V_40 -> V_73 , V_40 -> V_77 ,
V_67 << 16 , V_68 << 16 ,
V_40 -> V_73 << 16 , V_40 -> V_77 << 16 ) ;
if ( V_71 ) {
F_77 ( V_3 -> V_6 -> V_6 , L_5 ,
V_12 -> V_29 , V_71 ) ;
return V_71 ;
}
if ( V_70 == V_82 ) {
F_17 ( V_1 , F_78 ( 0 ) , 0x00ff0000 ) ;
F_17 ( V_1 , F_78 ( 1 ) , 0x00ff0000 ) ;
F_17 ( V_1 , F_78 ( 2 ) , 0x00ff0000 ) ;
}
return 0 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
F_16 ( L_6 , V_12 -> V_29 ) ;
F_33 ( F_1 ( V_3 ) ) ;
F_32 ( V_3 , V_83 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
F_32 ( V_3 , V_42 ) ;
F_12 ( V_3 ) ;
F_35 ( F_1 ( V_3 ) ) ;
}
static int F_81 ( struct V_2 * V_3 , int V_67 , int V_68 ,
struct V_10 * V_13 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_84 * V_27 = V_12 -> V_27 ;
struct V_44 * V_40 = & V_3 -> V_40 ;
F_3 ( V_3 , false , V_3 -> V_14 ) ;
return F_76 ( V_27 , V_3 , V_3 -> V_14 ,
0 , 0 , V_40 -> V_73 , V_40 -> V_77 ,
V_67 << 16 , V_68 << 16 ,
V_40 -> V_73 << 16 , V_40 -> V_77 << 16 ) ;
}
static void F_82 ( struct V_2 * V_3 )
{
}
static int F_83 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_20 * V_21 ,
T_1 V_85 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_86 * V_87 ;
if ( V_12 -> V_21 ) {
F_77 ( V_6 -> V_6 , L_7 ) ;
return - V_88 ;
}
V_87 = F_84 ( V_11 , 0 ) ;
V_12 -> V_21 = V_21 ;
F_3 ( V_3 , true , V_11 ) ;
return F_85 ( V_87 ,
& V_12 -> V_33 ) ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_89 * V_90 , T_2 V_35 )
{
return - V_91 ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
enum V_69 V_70 = V_12 -> V_70 ;
unsigned long V_22 ;
F_9 ( & V_12 -> V_92 . V_93 , V_22 ) ;
if ( V_12 -> V_92 . V_94 ) {
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_86 * V_95 = V_12 -> V_92 . V_95 ;
struct V_86 * V_96 = V_12 -> V_92 . V_97 ;
T_1 V_98 = V_12 -> V_92 . V_99 ;
if ( V_95 ) {
F_88 ( V_95 ) ;
F_89 ( V_95 , V_1 -> V_25 , & V_98 ) ;
F_17 ( V_1 , F_90 ( V_70 ) ,
F_91 ( V_12 -> V_92 . V_100 ) |
F_92 ( V_12 -> V_92 . V_101 ) ) ;
F_17 ( V_1 , F_93 ( V_70 ) , V_98 ) ;
F_17 ( V_1 , F_94 ( V_70 ) ,
F_95 ( V_102 ) |
V_103 ) ;
} else {
F_17 ( V_1 , F_93 ( V_70 ) , 0 ) ;
F_17 ( V_1 , F_94 ( V_70 ) ,
F_95 ( V_102 ) ) ;
}
if ( V_96 )
F_5 ( & V_12 -> V_38 , V_96 ) ;
V_12 -> V_92 . V_97 = V_95 ;
V_12 -> V_92 . V_94 = false ;
}
F_11 ( & V_12 -> V_92 . V_93 , V_22 ) ;
}
static int F_96 ( struct V_2 * V_3 ,
struct V_104 * V_105 , T_1 V_106 ,
T_1 V_100 , T_1 V_101 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_86 * V_107 , * V_108 ;
unsigned long V_22 ;
T_1 V_98 ;
int V_71 ;
if ( ( V_100 > V_109 ) || ( V_101 > V_110 ) ) {
F_77 ( V_6 -> V_6 , L_8 , V_100 , V_101 ) ;
return - V_91 ;
}
if ( V_106 ) {
V_107 = F_97 ( V_6 , V_105 , V_106 ) ;
if ( ! V_107 )
return - V_111 ;
} else {
V_107 = NULL ;
}
if ( V_107 ) {
V_71 = F_98 ( V_107 , V_1 -> V_25 , & V_98 ) ;
if ( V_71 )
goto V_112;
} else {
V_98 = 0 ;
}
F_9 ( & V_12 -> V_92 . V_93 , V_22 ) ;
V_108 = V_12 -> V_92 . V_95 ;
V_12 -> V_92 . V_95 = V_107 ;
V_12 -> V_92 . V_99 = V_98 ;
V_12 -> V_92 . V_100 = V_100 ;
V_12 -> V_92 . V_101 = V_101 ;
V_12 -> V_92 . V_94 = true ;
F_11 ( & V_12 -> V_92 . V_93 , V_22 ) ;
if ( V_108 ) {
F_26 ( V_108 , V_1 -> V_25 ) ;
F_27 ( V_108 ) ;
}
return 0 ;
V_112:
F_27 ( V_107 ) ;
return V_71 ;
}
static int F_99 ( struct V_2 * V_3 , int V_67 , int V_68 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_69 V_70 = V_12 -> V_70 ;
F_17 ( V_1 , F_100 ( V_70 ) ,
F_101 ( V_67 ) |
F_102 ( V_68 ) ) ;
return 0 ;
}
static void F_103 ( struct V_113 * V_114 , T_1 V_115 )
{
struct V_12 * V_12 = F_19 ( V_114 , struct V_12 , V_17 ) ;
struct V_2 * V_3 = & V_12 -> V_16 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
F_87 ( V_3 ) ;
F_8 ( V_3 , false ) ;
F_34 ( F_1 ( V_3 ) , & V_12 -> V_17 ) ;
F_104 ( & V_12 -> V_15 , V_5 -> V_116 ) ;
F_104 ( & V_12 -> V_38 , V_5 -> V_116 ) ;
}
static void F_105 ( struct V_113 * V_114 , T_1 V_115 )
{
struct V_12 * V_12 = F_19 ( V_114 , struct V_12 , V_43 ) ;
struct V_2 * V_3 = & V_12 -> V_16 ;
F_16 ( L_9 , V_12 -> V_29 , V_115 ) ;
F_12 ( V_3 ) ;
}
T_1 F_106 ( struct V_2 * V_3 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
return V_12 -> V_17 . V_117 ;
}
void F_107 ( struct V_2 * V_3 )
{
F_8 ( V_3 , true ) ;
}
void F_108 ( struct V_2 * V_3 , T_1 V_118 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_17 ( V_1 , F_109 ( V_12 -> V_70 ) , V_118 ) ;
}
void F_110 ( struct V_2 * V_3 , enum V_119 V_120 )
{
struct V_12 * V_12 = F_4 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_121 ;
V_121 = F_111 ( V_1 , V_122 ) ;
switch ( V_12 -> V_70 ) {
case V_123 :
V_121 &= ~ V_124 ;
V_121 |= F_112 ( V_120 ) ;
break;
case V_125 :
V_121 &= ~ V_126 ;
V_121 |= F_113 ( V_120 ) ;
break;
case V_82 :
V_121 &= ~ V_127 ;
V_121 |= F_114 ( V_120 ) ;
break;
}
if ( V_120 == V_128 ) {
V_121 &= ~ V_129 ;
V_121 |= V_130 ;
V_12 -> V_52 = 0 ;
} else if ( V_120 == V_131 ) {
V_121 &= ~ V_130 ;
V_121 |= V_129 ;
V_12 -> V_52 = 0 ;
} else if ( V_120 == V_132 ) {
V_12 -> V_52 = 1 ;
}
F_37 ( V_3 ) ;
F_16 ( L_10 , V_12 -> V_29 , V_121 ) ;
F_17 ( V_1 , V_122 , V_121 ) ;
}
struct V_2 * F_115 ( struct V_19 * V_6 ,
struct V_84 * V_27 , int V_25 , int V_133 ,
enum V_69 V_134 )
{
struct V_2 * V_3 = NULL ;
struct V_12 * V_12 ;
int V_71 ;
V_12 = F_116 ( sizeof( * V_12 ) , V_135 ) ;
if ( ! V_12 ) {
V_71 = - V_136 ;
goto V_112;
}
V_3 = & V_12 -> V_16 ;
V_12 -> V_27 = V_27 ;
V_12 -> V_27 -> V_3 = V_3 ;
V_12 -> V_28 = V_133 ;
V_12 -> V_70 = V_134 ;
V_12 -> V_17 . V_117 = F_117 ( V_12 -> V_70 ) ;
V_12 -> V_17 . V_114 = F_103 ;
V_12 -> V_43 . V_117 = F_118 ( V_12 -> V_70 ) ;
V_12 -> V_43 . V_114 = F_105 ;
snprintf ( V_12 -> V_29 , sizeof( V_12 -> V_29 ) , L_11 ,
V_137 [ V_134 ] , V_133 ) ;
F_119 ( & V_12 -> V_92 . V_93 ) ;
V_71 = F_120 ( & V_12 -> V_15 , 16 ,
L_12 , F_21 ) ;
if ( V_71 )
goto V_112;
V_71 = F_120 ( & V_12 -> V_38 , 64 ,
L_13 , F_25 ) ;
F_121 ( & V_12 -> V_33 , F_18 ) ;
F_122 ( V_6 , V_3 , & V_138 ) ;
F_123 ( V_3 , & V_139 ) ;
F_124 ( V_12 -> V_27 , & V_3 -> V_16 ) ;
return V_3 ;
V_112:
if ( V_3 )
F_28 ( V_3 ) ;
return F_125 ( V_71 ) ;
}
