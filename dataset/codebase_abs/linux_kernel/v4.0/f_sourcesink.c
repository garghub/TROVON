static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 , int V_8 )
{
return F_4 ( V_7 , V_8 , V_9 ) ;
}
void F_5 ( struct V_6 * V_7 , struct V_5 * V_10 )
{
F_6 ( V_10 -> V_11 ) ;
F_7 ( V_7 , V_10 ) ;
}
static void F_8 ( struct V_12 * V_13 , struct V_6 * V_7 )
{
int V_14 ;
if ( V_7 -> V_15 ) {
V_14 = F_9 ( V_7 ) ;
if ( V_14 < 0 )
F_10 ( V_13 , L_1 ,
V_7 -> V_16 , V_14 ) ;
V_7 -> V_15 = NULL ;
}
}
void F_11 ( struct V_12 * V_13 ,
struct V_6 * V_17 , struct V_6 * V_18 ,
struct V_6 * V_19 , struct V_6 * V_20 )
{
F_8 ( V_13 , V_17 ) ;
F_8 ( V_13 , V_18 ) ;
if ( V_19 )
F_8 ( V_13 , V_19 ) ;
if ( V_20 )
F_8 ( V_13 , V_20 ) ;
}
static int
F_12 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
struct V_12 * V_13 = V_22 -> V_13 ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
int V_24 ;
int V_25 ;
V_24 = F_13 ( V_22 , V_3 ) ;
if ( V_24 < 0 )
return V_24 ;
V_26 . V_27 = V_24 ;
V_28 . V_27 = V_24 ;
V_23 -> V_29 = F_14 ( V_13 -> V_30 , & V_31 ) ;
if ( ! V_23 -> V_29 ) {
V_32:
ERROR ( V_13 , L_2 ,
V_3 -> V_16 , V_13 -> V_30 -> V_16 ) ;
return - V_33 ;
}
V_23 -> V_29 -> V_15 = V_13 ;
V_23 -> V_34 = F_14 ( V_13 -> V_30 , & V_35 ) ;
if ( ! V_23 -> V_34 )
goto V_32;
V_23 -> V_34 -> V_15 = V_13 ;
if ( V_36 < 1 )
V_36 = 1 ;
if ( V_36 > 16 )
V_36 = 16 ;
if ( V_37 > 2 )
V_37 = 2 ;
if ( V_38 > 15 )
V_38 = 15 ;
V_39 . V_40 = V_41 > 1023 ?
1023 : V_41 ;
V_39 . V_42 = V_36 ;
V_43 . V_40 = V_41 > 1023 ?
1023 : V_41 ;
V_43 . V_42 = V_36 ;
V_23 -> V_44 = F_14 ( V_13 -> V_30 , & V_39 ) ;
if ( ! V_23 -> V_44 )
goto V_45;
V_23 -> V_44 -> V_15 = V_13 ;
V_23 -> V_46 = F_14 ( V_13 -> V_30 , & V_43 ) ;
if ( V_23 -> V_46 ) {
V_23 -> V_46 -> V_15 = V_13 ;
} else {
V_23 -> V_44 -> V_15 = NULL ;
V_23 -> V_44 = NULL ;
V_45:
V_47 [ V_48 ] = NULL ;
V_49 [ V_50 ] = NULL ;
V_51 [ V_52 ] = NULL ;
}
if ( V_41 > 1024 )
V_41 = 1024 ;
V_53 . V_54 = V_31 . V_54 ;
V_55 . V_54 = V_35 . V_54 ;
V_56 . V_40 = V_41 ;
V_56 . V_40 |= V_37 << 11 ;
V_56 . V_42 = V_36 ;
V_56 . V_54 =
V_39 . V_54 ;
V_57 . V_40 = V_41 ;
V_57 . V_40 |= V_37 << 11 ;
V_57 . V_42 = V_36 ;
V_57 . V_54 = V_43 . V_54 ;
V_58 . V_54 =
V_31 . V_54 ;
V_59 . V_54 =
V_35 . V_54 ;
V_60 . V_40 = V_41 ;
V_60 . V_42 = V_36 ;
V_61 . V_62 = V_37 ;
V_61 . V_63 = V_38 ;
V_61 . V_64 =
V_41 * ( V_37 + 1 ) * ( V_38 + 1 ) ;
V_60 . V_54 =
V_39 . V_54 ;
V_65 . V_40 = V_41 ;
V_65 . V_42 = V_36 ;
V_66 . V_62 = V_37 ;
V_66 . V_63 = V_38 ;
V_66 . V_64 =
V_41 * ( V_37 + 1 ) * ( V_38 + 1 ) ;
V_65 . V_54 = V_43 . V_54 ;
V_25 = F_15 ( V_3 , V_47 ,
V_49 , V_51 ) ;
if ( V_25 )
return V_25 ;
F_10 ( V_13 , L_3 ,
( F_16 ( V_22 -> V_13 -> V_30 ) ? L_4 :
( F_17 ( V_22 -> V_13 -> V_30 ) ? L_5 : L_6 ) ) ,
V_3 -> V_16 , V_23 -> V_29 -> V_16 , V_23 -> V_34 -> V_16 ,
V_23 -> V_44 ? V_23 -> V_44 -> V_16 : L_7 ,
V_23 -> V_46 ? V_23 -> V_46 -> V_16 : L_7 ) ;
return 0 ;
}
static void
F_18 ( struct V_2 * V_3 )
{
struct V_67 * V_68 ;
V_68 = F_2 ( V_3 -> V_69 , struct V_67 , V_70 ) ;
F_19 ( & V_68 -> V_71 ) ;
V_68 -> V_72 -- ;
F_20 ( & V_68 -> V_71 ) ;
F_21 ( V_3 ) ;
F_6 ( F_1 ( V_3 ) ) ;
}
static int F_22 ( struct V_1 * V_23 , struct V_5 * V_10 )
{
unsigned V_73 ;
T_1 * V_11 = V_10 -> V_11 ;
struct V_12 * V_13 = V_23 -> V_4 . V_74 -> V_13 ;
if ( V_75 == 2 )
return 0 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_76 ; V_73 ++ , V_11 ++ ) {
switch ( V_75 ) {
case 0 :
if ( * V_11 == 0 )
continue;
break;
case 1 :
if ( * V_11 == ( T_1 ) ( V_73 % 63 ) )
continue;
break;
}
ERROR ( V_13 , L_8 , V_73 , * V_11 ) ;
F_23 ( V_23 -> V_34 ) ;
return - V_77 ;
}
return 0 ;
}
static void F_24 ( struct V_6 * V_7 , struct V_5 * V_10 )
{
unsigned V_73 ;
T_1 * V_11 = V_10 -> V_11 ;
switch ( V_75 ) {
case 0 :
memset ( V_10 -> V_11 , 0 , V_10 -> V_78 ) ;
break;
case 1 :
for ( V_73 = 0 ; V_73 < V_10 -> V_78 ; V_73 ++ )
* V_11 ++ = ( T_1 ) ( V_73 % 63 ) ;
break;
case 2 :
break;
}
}
static void F_25 ( struct V_6 * V_7 , struct V_5 * V_10 )
{
struct V_12 * V_13 ;
struct V_1 * V_23 = V_7 -> V_15 ;
int V_79 = V_10 -> V_79 ;
if ( ! V_23 )
return;
V_13 = V_23 -> V_4 . V_74 -> V_13 ;
switch ( V_79 ) {
case 0 :
if ( V_7 == V_23 -> V_34 ) {
F_22 ( V_23 , V_10 ) ;
if ( V_75 != 2 )
memset ( V_10 -> V_11 , 0x55 , V_10 -> V_78 ) ;
}
break;
case - V_80 :
case - V_81 :
case - V_82 :
F_26 ( V_13 , L_9 , V_7 -> V_16 , V_79 ,
V_10 -> V_76 , V_10 -> V_78 ) ;
if ( V_7 == V_23 -> V_34 )
F_22 ( V_23 , V_10 ) ;
F_5 ( V_7 , V_10 ) ;
return;
case - V_83 :
default:
#if 1
F_10 ( V_13 , L_10 , V_7 -> V_16 ,
V_79 , V_10 -> V_76 , V_10 -> V_78 ) ;
#endif
case - V_84 :
break;
}
V_79 = F_27 ( V_7 , V_10 , V_85 ) ;
if ( V_79 ) {
ERROR ( V_13 , L_11 ,
V_7 -> V_16 , V_10 -> V_78 , V_79 ) ;
F_23 ( V_7 ) ;
}
}
static int F_28 ( struct V_1 * V_23 , bool V_86 ,
bool V_87 , int V_88 )
{
struct V_6 * V_7 ;
struct V_5 * V_10 ;
int V_73 , V_89 , V_79 ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ ) {
if ( V_87 ) {
switch ( V_88 ) {
case V_90 :
V_89 = V_41 * ( V_37 + 1 ) *
( V_38 + 1 ) ;
break;
case V_91 :
V_89 = V_41 * ( V_37 + 1 ) ;
break;
default:
V_89 = V_41 > 1023 ?
1023 : V_41 ;
break;
}
V_7 = V_86 ? V_23 -> V_44 : V_23 -> V_46 ;
V_10 = F_3 ( V_7 , V_89 ) ;
} else {
V_7 = V_86 ? V_23 -> V_29 : V_23 -> V_34 ;
V_10 = F_3 ( V_7 , 0 ) ;
}
if ( ! V_10 )
return - V_92 ;
V_10 -> V_93 = F_25 ;
if ( V_86 )
F_24 ( V_7 , V_10 ) ;
else if ( V_75 != 2 )
memset ( V_10 -> V_11 , 0x55 , V_10 -> V_78 ) ;
V_79 = F_27 ( V_7 , V_10 , V_85 ) ;
if ( V_79 ) {
struct V_12 * V_13 ;
V_13 = V_23 -> V_4 . V_74 -> V_13 ;
ERROR ( V_13 , L_12 ,
V_87 ? L_13 : L_14 , V_86 ? L_15 : L_16 ,
V_7 -> V_16 , V_79 ) ;
F_5 ( V_7 , V_10 ) ;
}
if ( ! V_87 )
break;
}
return V_79 ;
}
static void F_29 ( struct V_1 * V_23 )
{
struct V_12 * V_13 ;
V_13 = V_23 -> V_4 . V_74 -> V_13 ;
F_11 ( V_13 , V_23 -> V_29 , V_23 -> V_34 , V_23 -> V_44 ,
V_23 -> V_46 ) ;
F_26 ( V_13 , L_17 , V_23 -> V_4 . V_16 ) ;
}
static int
F_30 ( struct V_12 * V_13 , struct V_1 * V_23 ,
int V_94 )
{
int V_95 = 0 ;
int V_88 = V_13 -> V_30 -> V_88 ;
struct V_6 * V_7 ;
V_7 = V_23 -> V_29 ;
V_95 = F_31 ( V_13 -> V_30 , & ( V_23 -> V_4 ) , V_7 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_32 ( V_7 ) ;
if ( V_95 < 0 )
return V_95 ;
V_7 -> V_15 = V_23 ;
V_95 = F_28 ( V_23 , true , false , V_88 ) ;
if ( V_95 < 0 ) {
V_96:
V_7 = V_23 -> V_29 ;
F_9 ( V_7 ) ;
V_7 -> V_15 = NULL ;
return V_95 ;
}
V_7 = V_23 -> V_34 ;
V_95 = F_31 ( V_13 -> V_30 , & ( V_23 -> V_4 ) , V_7 ) ;
if ( V_95 )
goto V_96;
V_95 = F_32 ( V_7 ) ;
if ( V_95 < 0 )
goto V_96;
V_7 -> V_15 = V_23 ;
V_95 = F_28 ( V_23 , false , false , V_88 ) ;
if ( V_95 < 0 ) {
V_97:
V_7 = V_23 -> V_34 ;
F_9 ( V_7 ) ;
V_7 -> V_15 = NULL ;
goto V_96;
}
if ( V_94 == 0 )
goto V_18;
V_7 = V_23 -> V_44 ;
if ( V_7 ) {
V_95 = F_31 ( V_13 -> V_30 , & ( V_23 -> V_4 ) , V_7 ) ;
if ( V_95 )
goto V_97;
V_95 = F_32 ( V_7 ) ;
if ( V_95 < 0 )
goto V_97;
V_7 -> V_15 = V_23 ;
V_95 = F_28 ( V_23 , true , true , V_88 ) ;
if ( V_95 < 0 ) {
V_98:
V_7 = V_23 -> V_44 ;
if ( V_7 ) {
F_9 ( V_7 ) ;
V_7 -> V_15 = NULL ;
}
goto V_97;
}
}
V_7 = V_23 -> V_46 ;
if ( V_7 ) {
V_95 = F_31 ( V_13 -> V_30 , & ( V_23 -> V_4 ) , V_7 ) ;
if ( V_95 )
goto V_98;
V_95 = F_32 ( V_7 ) ;
if ( V_95 < 0 )
goto V_98;
V_7 -> V_15 = V_23 ;
V_95 = F_28 ( V_23 , false , true , V_88 ) ;
if ( V_95 < 0 ) {
F_9 ( V_7 ) ;
V_7 -> V_15 = NULL ;
goto V_98;
}
}
V_18:
V_23 -> V_99 = V_94 ;
F_10 ( V_13 , L_18 , V_23 -> V_4 . V_16 , V_94 ) ;
return V_95 ;
}
static int F_33 ( struct V_2 * V_3 ,
unsigned V_100 , unsigned V_94 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_3 -> V_74 -> V_13 ;
if ( V_23 -> V_29 -> V_15 )
F_29 ( V_23 ) ;
return F_30 ( V_13 , V_23 , V_94 ) ;
}
static int F_34 ( struct V_2 * V_3 , unsigned V_100 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
return V_23 -> V_99 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_29 ( V_23 ) ;
}
static int F_36 ( struct V_2 * V_3 ,
const struct V_101 * V_102 )
{
struct V_21 * V_22 = V_3 -> V_74 ;
struct V_5 * V_10 = V_22 -> V_13 -> V_10 ;
int V_14 = - V_103 ;
T_2 V_104 = F_37 ( V_102 -> V_105 ) ;
T_2 V_106 = F_37 ( V_102 -> V_107 ) ;
T_2 V_108 = F_37 ( V_102 -> V_109 ) ;
V_10 -> V_78 = V_110 ;
switch ( V_102 -> V_111 ) {
case 0x5b :
if ( V_102 -> V_112 != ( V_113 | V_114 ) )
goto V_115;
if ( V_106 || V_104 )
break;
if ( V_108 > V_10 -> V_78 )
break;
V_14 = V_108 ;
break;
case 0x5c :
if ( V_102 -> V_112 != ( V_116 | V_114 ) )
goto V_115;
if ( V_106 || V_104 )
break;
if ( V_108 > V_10 -> V_78 )
break;
V_14 = V_108 ;
break;
default:
V_115:
F_26 ( V_22 -> V_13 ,
L_19 ,
V_102 -> V_112 , V_102 -> V_111 ,
V_106 , V_104 , V_108 ) ;
}
if ( V_14 >= 0 ) {
F_26 ( V_22 -> V_13 , L_20 ,
V_102 -> V_112 , V_102 -> V_111 ,
V_106 , V_104 , V_108 ) ;
V_10 -> V_117 = 0 ;
V_10 -> V_78 = V_14 ;
V_14 = F_27 ( V_22 -> V_13 -> V_30 -> V_118 , V_10 , V_85 ) ;
if ( V_14 < 0 )
ERROR ( V_22 -> V_13 , L_21 ,
V_14 ) ;
}
return V_14 ;
}
static struct V_2 * F_38 (
struct V_119 * V_69 )
{
struct V_1 * V_23 ;
struct V_67 * V_120 ;
V_23 = F_39 ( sizeof( * V_23 ) , V_121 ) ;
if ( ! V_23 )
return NULL ;
V_120 = F_2 ( V_69 , struct V_67 , V_70 ) ;
F_19 ( & V_120 -> V_71 ) ;
V_120 -> V_72 ++ ;
F_20 ( & V_120 -> V_71 ) ;
V_75 = V_120 -> V_75 ;
V_36 = V_120 -> V_36 ;
V_41 = V_120 -> V_41 ;
V_37 = V_120 -> V_37 ;
V_38 = V_120 -> V_38 ;
V_9 = V_120 -> V_122 ;
V_23 -> V_4 . V_16 = L_22 ;
V_23 -> V_4 . V_123 = F_12 ;
V_23 -> V_4 . V_124 = F_33 ;
V_23 -> V_4 . V_125 = F_34 ;
V_23 -> V_4 . V_126 = F_35 ;
V_23 -> V_4 . V_127 = F_36 ;
V_23 -> V_4 . V_128 = V_129 ;
V_23 -> V_4 . V_130 = F_18 ;
return & V_23 -> V_4 ;
}
static inline struct V_67 * F_40 ( struct V_131 * V_132 )
{
return F_2 ( F_41 ( V_132 ) , struct V_67 ,
V_70 . V_133 ) ;
}
static void F_42 ( struct V_131 * V_132 )
{
struct V_67 * V_120 = F_40 ( V_132 ) ;
F_43 ( & V_120 -> V_70 ) ;
}
static T_3 F_44 ( struct V_67 * V_68 , char * V_134 )
{
int V_95 ;
F_19 ( & V_68 -> V_71 ) ;
V_95 = sprintf ( V_134 , L_23 , V_68 -> V_75 ) ;
F_20 ( & V_68 -> V_71 ) ;
return V_95 ;
}
static T_3 F_45 ( struct V_67 * V_68 ,
const char * V_134 , T_4 V_8 )
{
int V_25 ;
T_1 V_135 ;
F_19 ( & V_68 -> V_71 ) ;
if ( V_68 -> V_72 ) {
V_25 = - V_136 ;
goto V_137;
}
V_25 = F_46 ( V_134 , 0 , & V_135 ) ;
if ( V_25 )
goto V_137;
if ( V_135 != 0 && V_135 != 1 && V_135 != 2 ) {
V_25 = - V_77 ;
goto V_137;
}
V_68 -> V_75 = V_135 ;
V_25 = V_8 ;
V_137:
F_20 ( & V_68 -> V_71 ) ;
return V_25 ;
}
static T_3 F_47 ( struct V_67 * V_68 , char * V_134 )
{
int V_95 ;
F_19 ( & V_68 -> V_71 ) ;
V_95 = sprintf ( V_134 , L_23 , V_68 -> V_36 ) ;
F_20 ( & V_68 -> V_71 ) ;
return V_95 ;
}
static T_3 F_48 ( struct V_67 * V_68 ,
const char * V_134 , T_4 V_8 )
{
int V_25 ;
T_1 V_135 ;
F_19 ( & V_68 -> V_71 ) ;
if ( V_68 -> V_72 ) {
V_25 = - V_136 ;
goto V_137;
}
V_25 = F_46 ( V_134 , 0 , & V_135 ) ;
if ( V_25 )
goto V_137;
if ( V_135 > 16 ) {
V_25 = - V_77 ;
goto V_137;
}
V_68 -> V_36 = V_135 ;
V_25 = V_8 ;
V_137:
F_20 ( & V_68 -> V_71 ) ;
return V_25 ;
}
static T_3 F_49 ( struct V_67 * V_68 , char * V_134 )
{
int V_95 ;
F_19 ( & V_68 -> V_71 ) ;
V_95 = sprintf ( V_134 , L_23 , V_68 -> V_41 ) ;
F_20 ( & V_68 -> V_71 ) ;
return V_95 ;
}
static T_3 F_50 ( struct V_67 * V_68 ,
const char * V_134 , T_4 V_8 )
{
int V_25 ;
T_2 V_135 ;
F_19 ( & V_68 -> V_71 ) ;
if ( V_68 -> V_72 ) {
V_25 = - V_136 ;
goto V_137;
}
V_25 = F_51 ( V_134 , 0 , & V_135 ) ;
if ( V_25 )
goto V_137;
if ( V_135 > 1024 ) {
V_25 = - V_77 ;
goto V_137;
}
V_68 -> V_41 = V_135 ;
V_25 = V_8 ;
V_137:
F_20 ( & V_68 -> V_71 ) ;
return V_25 ;
}
static T_3 F_52 ( struct V_67 * V_68 , char * V_134 )
{
int V_95 ;
F_19 ( & V_68 -> V_71 ) ;
V_95 = sprintf ( V_134 , L_23 , V_68 -> V_37 ) ;
F_20 ( & V_68 -> V_71 ) ;
return V_95 ;
}
static T_3 F_53 ( struct V_67 * V_68 ,
const char * V_134 , T_4 V_8 )
{
int V_25 ;
T_1 V_135 ;
F_19 ( & V_68 -> V_71 ) ;
if ( V_68 -> V_72 ) {
V_25 = - V_136 ;
goto V_137;
}
V_25 = F_46 ( V_134 , 0 , & V_135 ) ;
if ( V_25 )
goto V_137;
if ( V_135 > 2 ) {
V_25 = - V_77 ;
goto V_137;
}
V_68 -> V_37 = V_135 ;
V_25 = V_8 ;
V_137:
F_20 ( & V_68 -> V_71 ) ;
return V_25 ;
}
static T_3 F_54 ( struct V_67 * V_68 , char * V_134 )
{
int V_95 ;
F_19 ( & V_68 -> V_71 ) ;
V_95 = sprintf ( V_134 , L_23 , V_68 -> V_38 ) ;
F_20 ( & V_68 -> V_71 ) ;
return V_95 ;
}
static T_3 F_55 ( struct V_67 * V_68 ,
const char * V_134 , T_4 V_8 )
{
int V_25 ;
T_1 V_135 ;
F_19 ( & V_68 -> V_71 ) ;
if ( V_68 -> V_72 ) {
V_25 = - V_136 ;
goto V_137;
}
V_25 = F_46 ( V_134 , 0 , & V_135 ) ;
if ( V_25 )
goto V_137;
if ( V_135 > 15 ) {
V_25 = - V_77 ;
goto V_137;
}
V_68 -> V_38 = V_135 ;
V_25 = V_8 ;
V_137:
F_20 ( & V_68 -> V_71 ) ;
return V_25 ;
}
static T_3 F_56 ( struct V_67 * V_68 , char * V_134 )
{
int V_95 ;
F_19 ( & V_68 -> V_71 ) ;
V_95 = sprintf ( V_134 , L_23 , V_68 -> V_122 ) ;
F_20 ( & V_68 -> V_71 ) ;
return V_95 ;
}
static T_3 F_57 ( struct V_67 * V_68 ,
const char * V_134 , T_4 V_8 )
{
int V_25 ;
T_5 V_135 ;
F_19 ( & V_68 -> V_71 ) ;
if ( V_68 -> V_72 ) {
V_25 = - V_136 ;
goto V_137;
}
V_25 = F_58 ( V_134 , 0 , & V_135 ) ;
if ( V_25 )
goto V_137;
V_68 -> V_122 = V_135 ;
V_25 = V_8 ;
V_137:
F_20 ( & V_68 -> V_71 ) ;
return V_25 ;
}
static void F_59 ( struct V_119 * V_69 )
{
struct V_67 * V_120 ;
V_120 = F_2 ( V_69 , struct V_67 , V_70 ) ;
F_6 ( V_120 ) ;
}
static struct V_119 * F_60 ( void )
{
struct V_67 * V_120 ;
V_120 = F_39 ( sizeof( * V_120 ) , V_121 ) ;
if ( ! V_120 )
return F_61 ( - V_92 ) ;
F_62 ( & V_120 -> V_71 ) ;
V_120 -> V_70 . V_138 = F_59 ;
V_120 -> V_36 = V_139 ;
V_120 -> V_41 = V_140 ;
V_120 -> V_122 = V_141 ;
F_63 ( & V_120 -> V_70 . V_133 , L_14 ,
& V_142 ) ;
return & V_120 -> V_70 ;
}
static int T_6 F_64 ( void )
{
int V_25 ;
V_25 = F_65 ( & V_143 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_66 () ;
if ( V_25 )
F_67 ( & V_143 ) ;
return V_25 ;
}
static void T_7 F_68 ( void )
{
F_67 ( & V_143 ) ;
F_69 () ;
}
