static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
struct V_5 * F_3 ( struct V_6 * V_7 , int V_8 )
{
struct V_5 * V_9 ;
V_9 = F_4 ( V_7 , V_10 ) ;
if ( V_9 ) {
if ( V_8 )
V_9 -> V_11 = V_8 ;
else
V_9 -> V_11 = V_12 ;
V_9 -> V_13 = F_5 ( V_9 -> V_11 , V_10 ) ;
if ( ! V_9 -> V_13 ) {
F_6 ( V_7 , V_9 ) ;
V_9 = NULL ;
}
}
return V_9 ;
}
void F_7 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
F_8 ( V_9 -> V_13 ) ;
F_6 ( V_7 , V_9 ) ;
}
static void F_9 ( struct V_14 * V_15 , struct V_6 * V_7 )
{
int V_16 ;
if ( V_7 -> V_17 ) {
V_16 = F_10 ( V_7 ) ;
if ( V_16 < 0 )
F_11 ( V_15 , L_1 ,
V_7 -> V_18 , V_16 ) ;
V_7 -> V_17 = NULL ;
}
}
void F_12 ( struct V_14 * V_15 ,
struct V_6 * V_19 , struct V_6 * V_20 ,
struct V_6 * V_21 , struct V_6 * V_22 )
{
F_9 ( V_15 , V_19 ) ;
F_9 ( V_15 , V_20 ) ;
if ( V_21 )
F_9 ( V_15 , V_21 ) ;
if ( V_22 )
F_9 ( V_15 , V_22 ) ;
}
static int
F_13 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
struct V_14 * V_15 = V_24 -> V_15 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_26 ;
int V_27 ;
V_26 = F_14 ( V_24 , V_3 ) ;
if ( V_26 < 0 )
return V_26 ;
V_28 . V_29 = V_26 ;
V_30 . V_29 = V_26 ;
V_25 -> V_31 = F_15 ( V_15 -> V_32 , & V_33 ) ;
if ( ! V_25 -> V_31 ) {
V_34:
ERROR ( V_15 , L_2 ,
V_3 -> V_18 , V_15 -> V_32 -> V_18 ) ;
return - V_35 ;
}
V_25 -> V_31 -> V_17 = V_15 ;
V_25 -> V_36 = F_15 ( V_15 -> V_32 , & V_37 ) ;
if ( ! V_25 -> V_36 )
goto V_34;
V_25 -> V_36 -> V_17 = V_15 ;
if ( V_38 < 1 )
V_38 = 1 ;
if ( V_38 > 16 )
V_38 = 16 ;
if ( V_39 > 2 )
V_39 = 2 ;
if ( V_40 > 15 )
V_40 = 15 ;
V_41 . V_42 = V_43 > 1023 ?
1023 : V_43 ;
V_41 . V_44 = V_38 ;
V_45 . V_42 = V_43 > 1023 ?
1023 : V_43 ;
V_45 . V_44 = V_38 ;
V_25 -> V_46 = F_15 ( V_15 -> V_32 , & V_41 ) ;
if ( ! V_25 -> V_46 )
goto V_47;
V_25 -> V_46 -> V_17 = V_15 ;
V_25 -> V_48 = F_15 ( V_15 -> V_32 , & V_45 ) ;
if ( V_25 -> V_48 ) {
V_25 -> V_48 -> V_17 = V_15 ;
} else {
V_25 -> V_46 -> V_17 = NULL ;
V_25 -> V_46 = NULL ;
V_47:
V_49 [ V_50 ] = NULL ;
V_51 [ V_52 ] = NULL ;
V_53 [ V_54 ] = NULL ;
}
if ( V_43 > 1024 )
V_43 = 1024 ;
V_55 . V_56 = V_33 . V_56 ;
V_57 . V_56 = V_37 . V_56 ;
V_58 . V_42 = V_43 ;
V_58 . V_42 |= V_39 << 11 ;
V_58 . V_44 = V_38 ;
V_58 . V_56 =
V_41 . V_56 ;
V_59 . V_42 = V_43 ;
V_59 . V_42 |= V_39 << 11 ;
V_59 . V_44 = V_38 ;
V_59 . V_56 = V_45 . V_56 ;
V_60 . V_56 =
V_33 . V_56 ;
V_61 . V_56 =
V_37 . V_56 ;
V_62 . V_42 = V_43 ;
V_62 . V_44 = V_38 ;
V_63 . V_64 = V_39 ;
V_63 . V_65 = V_40 ;
V_63 . V_66 =
V_43 * ( V_39 + 1 ) * ( V_40 + 1 ) ;
V_62 . V_56 =
V_41 . V_56 ;
V_67 . V_42 = V_43 ;
V_67 . V_44 = V_38 ;
V_68 . V_64 = V_39 ;
V_68 . V_65 = V_40 ;
V_68 . V_66 =
V_43 * ( V_39 + 1 ) * ( V_40 + 1 ) ;
V_67 . V_56 = V_45 . V_56 ;
V_27 = F_16 ( V_3 , V_49 ,
V_51 , V_53 ) ;
if ( V_27 )
return V_27 ;
F_11 ( V_15 , L_3 ,
( F_17 ( V_24 -> V_15 -> V_32 ) ? L_4 :
( F_18 ( V_24 -> V_15 -> V_32 ) ? L_5 : L_6 ) ) ,
V_3 -> V_18 , V_25 -> V_31 -> V_18 , V_25 -> V_36 -> V_18 ,
V_25 -> V_46 ? V_25 -> V_46 -> V_18 : L_7 ,
V_25 -> V_48 ? V_25 -> V_48 -> V_18 : L_7 ) ;
return 0 ;
}
static void
F_19 ( struct V_2 * V_3 )
{
F_20 ( V_3 ) ;
F_8 ( F_1 ( V_3 ) ) ;
}
static int F_21 ( struct V_1 * V_25 , struct V_5 * V_9 )
{
unsigned V_69 ;
T_1 * V_13 = V_9 -> V_13 ;
struct V_14 * V_15 = V_25 -> V_4 . V_70 -> V_15 ;
if ( V_71 == 2 )
return 0 ;
for ( V_69 = 0 ; V_69 < V_9 -> V_72 ; V_69 ++ , V_13 ++ ) {
switch ( V_71 ) {
case 0 :
if ( * V_13 == 0 )
continue;
break;
case 1 :
if ( * V_13 == ( T_1 ) ( V_69 % 63 ) )
continue;
break;
}
ERROR ( V_15 , L_8 , V_69 , * V_13 ) ;
F_22 ( V_25 -> V_36 ) ;
return - V_73 ;
}
return 0 ;
}
static void F_23 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
unsigned V_69 ;
T_1 * V_13 = V_9 -> V_13 ;
switch ( V_71 ) {
case 0 :
memset ( V_9 -> V_13 , 0 , V_9 -> V_11 ) ;
break;
case 1 :
for ( V_69 = 0 ; V_69 < V_9 -> V_11 ; V_69 ++ )
* V_13 ++ = ( T_1 ) ( V_69 % 63 ) ;
break;
case 2 :
break;
}
}
static void F_24 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
struct V_14 * V_15 ;
struct V_1 * V_25 = V_7 -> V_17 ;
int V_74 = V_9 -> V_74 ;
if ( ! V_25 )
return;
V_15 = V_25 -> V_4 . V_70 -> V_15 ;
switch ( V_74 ) {
case 0 :
if ( V_7 == V_25 -> V_36 ) {
F_21 ( V_25 , V_9 ) ;
if ( V_71 != 2 )
memset ( V_9 -> V_13 , 0x55 , V_9 -> V_11 ) ;
}
break;
case - V_75 :
case - V_76 :
case - V_77 :
F_25 ( V_15 , L_9 , V_7 -> V_18 , V_74 ,
V_9 -> V_72 , V_9 -> V_11 ) ;
if ( V_7 == V_25 -> V_36 )
F_21 ( V_25 , V_9 ) ;
F_7 ( V_7 , V_9 ) ;
return;
case - V_78 :
default:
#if 1
F_11 ( V_15 , L_10 , V_7 -> V_18 ,
V_74 , V_9 -> V_72 , V_9 -> V_11 ) ;
#endif
case - V_79 :
break;
}
V_74 = F_26 ( V_7 , V_9 , V_10 ) ;
if ( V_74 ) {
ERROR ( V_15 , L_11 ,
V_7 -> V_18 , V_9 -> V_11 , V_74 ) ;
F_22 ( V_7 ) ;
}
}
static int F_27 ( struct V_1 * V_25 , bool V_80 ,
bool V_81 , int V_82 )
{
struct V_6 * V_7 ;
struct V_5 * V_9 ;
int V_69 , V_83 , V_74 ;
for ( V_69 = 0 ; V_69 < 8 ; V_69 ++ ) {
if ( V_81 ) {
switch ( V_82 ) {
case V_84 :
V_83 = V_43 * ( V_39 + 1 ) *
( V_40 + 1 ) ;
break;
case V_85 :
V_83 = V_43 * ( V_39 + 1 ) ;
break;
default:
V_83 = V_43 > 1023 ?
1023 : V_43 ;
break;
}
V_7 = V_80 ? V_25 -> V_46 : V_25 -> V_48 ;
V_9 = F_3 ( V_7 , V_83 ) ;
} else {
V_7 = V_80 ? V_25 -> V_31 : V_25 -> V_36 ;
V_9 = F_3 ( V_7 , 0 ) ;
}
if ( ! V_9 )
return - V_86 ;
V_9 -> V_87 = F_24 ;
if ( V_80 )
F_23 ( V_7 , V_9 ) ;
else if ( V_71 != 2 )
memset ( V_9 -> V_13 , 0x55 , V_9 -> V_11 ) ;
V_74 = F_26 ( V_7 , V_9 , V_10 ) ;
if ( V_74 ) {
struct V_14 * V_15 ;
V_15 = V_25 -> V_4 . V_70 -> V_15 ;
ERROR ( V_15 , L_12 ,
V_81 ? L_13 : L_14 , V_80 ? L_15 : L_16 ,
V_7 -> V_18 , V_74 ) ;
F_7 ( V_7 , V_9 ) ;
}
if ( ! V_81 )
break;
}
return V_74 ;
}
static void F_28 ( struct V_1 * V_25 )
{
struct V_14 * V_15 ;
V_15 = V_25 -> V_4 . V_70 -> V_15 ;
F_12 ( V_15 , V_25 -> V_31 , V_25 -> V_36 , V_25 -> V_46 ,
V_25 -> V_48 ) ;
F_25 ( V_15 , L_17 , V_25 -> V_4 . V_18 ) ;
}
static int
F_29 ( struct V_14 * V_15 , struct V_1 * V_25 ,
int V_88 )
{
int V_89 = 0 ;
int V_82 = V_15 -> V_32 -> V_82 ;
struct V_6 * V_7 ;
V_7 = V_25 -> V_31 ;
V_89 = F_30 ( V_15 -> V_32 , & ( V_25 -> V_4 ) , V_7 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_31 ( V_7 ) ;
if ( V_89 < 0 )
return V_89 ;
V_7 -> V_17 = V_25 ;
V_89 = F_27 ( V_25 , true , false , V_82 ) ;
if ( V_89 < 0 ) {
V_90:
V_7 = V_25 -> V_31 ;
F_10 ( V_7 ) ;
V_7 -> V_17 = NULL ;
return V_89 ;
}
V_7 = V_25 -> V_36 ;
V_89 = F_30 ( V_15 -> V_32 , & ( V_25 -> V_4 ) , V_7 ) ;
if ( V_89 )
goto V_90;
V_89 = F_31 ( V_7 ) ;
if ( V_89 < 0 )
goto V_90;
V_7 -> V_17 = V_25 ;
V_89 = F_27 ( V_25 , false , false , V_82 ) ;
if ( V_89 < 0 ) {
V_91:
V_7 = V_25 -> V_36 ;
F_10 ( V_7 ) ;
V_7 -> V_17 = NULL ;
goto V_90;
}
if ( V_88 == 0 )
goto V_20;
V_7 = V_25 -> V_46 ;
if ( V_7 ) {
V_89 = F_30 ( V_15 -> V_32 , & ( V_25 -> V_4 ) , V_7 ) ;
if ( V_89 )
goto V_91;
V_89 = F_31 ( V_7 ) ;
if ( V_89 < 0 )
goto V_91;
V_7 -> V_17 = V_25 ;
V_89 = F_27 ( V_25 , true , true , V_82 ) ;
if ( V_89 < 0 ) {
V_92:
V_7 = V_25 -> V_46 ;
if ( V_7 ) {
F_10 ( V_7 ) ;
V_7 -> V_17 = NULL ;
}
goto V_91;
}
}
V_7 = V_25 -> V_48 ;
if ( V_7 ) {
V_89 = F_30 ( V_15 -> V_32 , & ( V_25 -> V_4 ) , V_7 ) ;
if ( V_89 )
goto V_92;
V_89 = F_31 ( V_7 ) ;
if ( V_89 < 0 )
goto V_92;
V_7 -> V_17 = V_25 ;
V_89 = F_27 ( V_25 , false , true , V_82 ) ;
if ( V_89 < 0 ) {
F_10 ( V_7 ) ;
V_7 -> V_17 = NULL ;
goto V_92;
}
}
V_20:
V_25 -> V_93 = V_88 ;
F_11 ( V_15 , L_18 , V_25 -> V_4 . V_18 , V_88 ) ;
return V_89 ;
}
static int F_32 ( struct V_2 * V_3 ,
unsigned V_94 , unsigned V_88 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_70 -> V_15 ;
if ( V_25 -> V_31 -> V_17 )
F_28 ( V_25 ) ;
return F_29 ( V_15 , V_25 , V_88 ) ;
}
static int F_33 ( struct V_2 * V_3 , unsigned V_94 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
return V_25 -> V_93 ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_28 ( V_25 ) ;
}
static int F_35 ( struct V_2 * V_3 ,
const struct V_95 * V_96 )
{
struct V_23 * V_24 = V_3 -> V_70 ;
struct V_5 * V_9 = V_24 -> V_15 -> V_9 ;
int V_16 = - V_97 ;
T_2 V_98 = F_36 ( V_96 -> V_99 ) ;
T_2 V_100 = F_36 ( V_96 -> V_101 ) ;
T_2 V_102 = F_36 ( V_96 -> V_103 ) ;
V_9 -> V_11 = V_104 ;
switch ( V_96 -> V_105 ) {
case 0x5b :
if ( V_96 -> V_106 != ( V_107 | V_108 ) )
goto V_109;
if ( V_100 || V_98 )
break;
if ( V_102 > V_9 -> V_11 )
break;
V_16 = V_102 ;
break;
case 0x5c :
if ( V_96 -> V_106 != ( V_110 | V_108 ) )
goto V_109;
if ( V_100 || V_98 )
break;
if ( V_102 > V_9 -> V_11 )
break;
V_16 = V_102 ;
break;
default:
V_109:
F_25 ( V_24 -> V_15 ,
L_19 ,
V_96 -> V_106 , V_96 -> V_105 ,
V_100 , V_98 , V_102 ) ;
}
if ( V_16 >= 0 ) {
F_25 ( V_24 -> V_15 , L_20 ,
V_96 -> V_106 , V_96 -> V_105 ,
V_100 , V_98 , V_102 ) ;
V_9 -> V_111 = 0 ;
V_9 -> V_11 = V_16 ;
V_16 = F_26 ( V_24 -> V_15 -> V_32 -> V_112 , V_9 , V_10 ) ;
if ( V_16 < 0 )
ERROR ( V_24 -> V_15 , L_21 ,
V_16 ) ;
}
return V_16 ;
}
static struct V_2 * F_37 (
struct V_113 * V_114 )
{
struct V_1 * V_25 ;
struct V_115 * V_116 ;
V_25 = F_38 ( sizeof( * V_25 ) , V_117 ) ;
if ( ! V_25 )
return NULL ;
V_116 = F_2 ( V_114 , struct V_115 , V_118 ) ;
V_71 = V_116 -> V_71 ;
V_38 = V_116 -> V_38 ;
V_43 = V_116 -> V_43 ;
V_39 = V_116 -> V_39 ;
V_40 = V_116 -> V_40 ;
V_12 = V_116 -> V_119 ;
V_25 -> V_4 . V_18 = L_22 ;
V_25 -> V_4 . V_120 = F_13 ;
V_25 -> V_4 . V_121 = F_32 ;
V_25 -> V_4 . V_122 = F_33 ;
V_25 -> V_4 . V_123 = F_34 ;
V_25 -> V_4 . V_124 = F_35 ;
V_25 -> V_4 . V_125 = V_126 ;
V_25 -> V_4 . V_127 = F_19 ;
return & V_25 -> V_4 ;
}
static void F_39 ( struct V_113 * V_114 )
{
struct V_115 * V_116 ;
V_116 = F_2 ( V_114 , struct V_115 , V_118 ) ;
F_8 ( V_116 ) ;
}
static struct V_113 * F_40 ( void )
{
struct V_115 * V_116 ;
V_116 = F_38 ( sizeof( * V_116 ) , V_117 ) ;
if ( ! V_116 )
return F_41 ( - V_86 ) ;
V_116 -> V_118 . V_128 = F_39 ;
return & V_116 -> V_118 ;
}
static int T_3 F_42 ( void )
{
int V_27 ;
V_27 = F_43 ( & V_129 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_44 () ;
if ( V_27 )
F_45 ( & V_129 ) ;
return V_27 ;
}
static void T_4 F_46 ( void )
{
F_45 ( & V_129 ) ;
F_47 () ;
}
