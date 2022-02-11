static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int T_1
F_3 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_10 ;
int V_11 ;
V_10 = F_4 ( V_6 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_12 . V_13 = V_10 ;
V_14 . V_13 = V_10 ;
V_9 -> V_15 = F_5 ( V_8 -> V_16 , & V_17 ) ;
if ( ! V_9 -> V_15 ) {
V_18:
ERROR ( V_8 , L_1 ,
V_3 -> V_19 , V_8 -> V_16 -> V_19 ) ;
return - V_20 ;
}
V_9 -> V_15 -> V_21 = V_8 ;
V_9 -> V_22 = F_5 ( V_8 -> V_16 , & V_23 ) ;
if ( ! V_9 -> V_22 )
goto V_18;
V_9 -> V_22 -> V_21 = V_8 ;
if ( V_24 < 1 )
V_24 = 1 ;
if ( V_24 > 16 )
V_24 = 16 ;
if ( V_25 > 2 )
V_25 = 2 ;
if ( V_26 > 15 )
V_26 = 15 ;
V_27 . V_28 = V_29 > 1023 ?
1023 : V_29 ;
V_27 . V_30 = V_24 ;
V_31 . V_28 = V_29 > 1023 ?
1023 : V_29 ;
V_31 . V_30 = V_24 ;
V_9 -> V_32 = F_5 ( V_8 -> V_16 , & V_27 ) ;
if ( ! V_9 -> V_32 )
goto V_33;
V_9 -> V_32 -> V_21 = V_8 ;
V_9 -> V_34 = F_5 ( V_8 -> V_16 , & V_31 ) ;
if ( V_9 -> V_34 ) {
V_9 -> V_34 -> V_21 = V_8 ;
} else {
V_9 -> V_32 -> V_21 = NULL ;
V_9 -> V_32 = NULL ;
V_33:
V_35 [ V_36 ] = NULL ;
V_37 [ V_38 ] = NULL ;
V_39 [ V_40 ] = NULL ;
}
if ( V_29 > 1024 )
V_29 = 1024 ;
V_41 . V_42 = V_17 . V_42 ;
V_43 . V_42 = V_23 . V_42 ;
V_44 . V_28 = V_29 ;
V_44 . V_28 |= V_25 << 11 ;
V_44 . V_30 = V_24 ;
V_44 . V_42 =
V_27 . V_42 ;
V_45 . V_28 = V_29 ;
V_45 . V_28 |= V_25 << 11 ;
V_45 . V_30 = V_24 ;
V_45 . V_42 = V_31 . V_42 ;
V_46 . V_42 =
V_17 . V_42 ;
V_47 . V_42 =
V_23 . V_42 ;
V_48 . V_28 = V_29 ;
V_48 . V_30 = V_24 ;
V_49 . V_50 = V_25 ;
V_49 . V_51 = V_26 ;
V_49 . V_52 =
V_29 * ( V_25 + 1 ) * ( V_26 + 1 ) ;
V_48 . V_42 =
V_27 . V_42 ;
V_53 . V_28 = V_29 ;
V_53 . V_30 = V_24 ;
V_54 . V_50 = V_25 ;
V_54 . V_51 = V_26 ;
V_54 . V_52 =
V_29 * ( V_25 + 1 ) * ( V_26 + 1 ) ;
V_53 . V_42 = V_31 . V_42 ;
V_11 = F_6 ( V_3 , V_35 ,
V_37 , V_39 ) ;
if ( V_11 )
return V_11 ;
F_7 ( V_8 , L_2 ,
( F_8 ( V_6 -> V_8 -> V_16 ) ? L_3 :
( F_9 ( V_6 -> V_8 -> V_16 ) ? L_4 : L_5 ) ) ,
V_3 -> V_19 , V_9 -> V_15 -> V_19 , V_9 -> V_22 -> V_19 ,
V_9 -> V_32 ? V_9 -> V_32 -> V_19 : L_6 ,
V_9 -> V_34 ? V_9 -> V_34 -> V_19 : L_6 ) ;
return 0 ;
}
static void
F_10 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
F_12 ( F_1 ( V_3 ) ) ;
}
static int F_13 ( struct V_1 * V_9 , struct V_55 * V_56 )
{
unsigned V_57 ;
T_2 * V_58 = V_56 -> V_58 ;
struct V_7 * V_8 = V_9 -> V_4 . V_59 -> V_8 ;
if ( V_60 == 2 )
return 0 ;
for ( V_57 = 0 ; V_57 < V_56 -> V_61 ; V_57 ++ , V_58 ++ ) {
switch ( V_60 ) {
case 0 :
if ( * V_58 == 0 )
continue;
break;
case 1 :
if ( * V_58 == ( T_2 ) ( V_57 % 63 ) )
continue;
break;
}
ERROR ( V_8 , L_7 , V_57 , * V_58 ) ;
F_14 ( V_9 -> V_22 ) ;
return - V_62 ;
}
return 0 ;
}
static void F_15 ( struct V_63 * V_64 , struct V_55 * V_56 )
{
unsigned V_57 ;
T_2 * V_58 = V_56 -> V_58 ;
switch ( V_60 ) {
case 0 :
memset ( V_56 -> V_58 , 0 , V_56 -> V_65 ) ;
break;
case 1 :
for ( V_57 = 0 ; V_57 < V_56 -> V_65 ; V_57 ++ )
* V_58 ++ = ( T_2 ) ( V_57 % 63 ) ;
break;
case 2 :
break;
}
}
static void F_16 ( struct V_63 * V_64 , struct V_55 * V_56 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 = V_64 -> V_21 ;
int V_66 = V_56 -> V_66 ;
if ( ! V_9 )
return;
V_8 = V_9 -> V_4 . V_59 -> V_8 ;
switch ( V_66 ) {
case 0 :
if ( V_64 == V_9 -> V_22 ) {
F_13 ( V_9 , V_56 ) ;
if ( V_60 != 2 )
memset ( V_56 -> V_58 , 0x55 , V_56 -> V_65 ) ;
} else
F_15 ( V_64 , V_56 ) ;
break;
case - V_67 :
case - V_68 :
case - V_69 :
F_17 ( V_8 , L_8 , V_64 -> V_19 , V_66 ,
V_56 -> V_61 , V_56 -> V_65 ) ;
if ( V_64 == V_9 -> V_22 )
F_13 ( V_9 , V_56 ) ;
F_18 ( V_64 , V_56 ) ;
return;
case - V_70 :
default:
#if 1
F_7 ( V_8 , L_9 , V_64 -> V_19 ,
V_66 , V_56 -> V_61 , V_56 -> V_65 ) ;
#endif
case - V_71 :
break;
}
V_66 = F_19 ( V_64 , V_56 , V_72 ) ;
if ( V_66 ) {
ERROR ( V_8 , L_10 ,
V_64 -> V_19 , V_56 -> V_65 , V_66 ) ;
F_14 ( V_64 ) ;
}
}
static int F_20 ( struct V_1 * V_9 , bool V_73 ,
bool V_74 , int V_75 )
{
struct V_63 * V_64 ;
struct V_55 * V_56 ;
int V_57 , V_76 , V_66 ;
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
if ( V_74 ) {
switch ( V_75 ) {
case V_77 :
V_76 = V_29 * ( V_25 + 1 ) *
( V_26 + 1 ) ;
break;
case V_78 :
V_76 = V_29 * ( V_25 + 1 ) ;
break;
default:
V_76 = V_29 > 1023 ?
1023 : V_29 ;
break;
}
V_64 = V_73 ? V_9 -> V_32 : V_9 -> V_34 ;
V_56 = F_21 ( V_64 , V_76 ) ;
} else {
V_64 = V_73 ? V_9 -> V_15 : V_9 -> V_22 ;
V_56 = F_21 ( V_64 , 0 ) ;
}
if ( ! V_56 )
return - V_79 ;
V_56 -> V_80 = F_16 ;
if ( V_73 )
F_15 ( V_64 , V_56 ) ;
else if ( V_60 != 2 )
memset ( V_56 -> V_58 , 0x55 , V_56 -> V_65 ) ;
V_66 = F_19 ( V_64 , V_56 , V_72 ) ;
if ( V_66 ) {
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_59 -> V_8 ;
ERROR ( V_8 , L_11 ,
V_74 ? L_12 : L_13 , V_73 ? L_14 : L_15 ,
V_64 -> V_19 , V_66 ) ;
F_18 ( V_64 , V_56 ) ;
}
if ( ! V_74 )
break;
}
return V_66 ;
}
static void F_22 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_59 -> V_8 ;
F_23 ( V_8 , V_9 -> V_15 , V_9 -> V_22 , V_9 -> V_32 ,
V_9 -> V_34 ) ;
F_17 ( V_8 , L_16 , V_9 -> V_4 . V_19 ) ;
}
static int
F_24 ( struct V_7 * V_8 , struct V_1 * V_9 ,
int V_81 )
{
int V_82 = 0 ;
int V_75 = V_8 -> V_16 -> V_75 ;
struct V_63 * V_64 ;
V_64 = V_9 -> V_15 ;
V_82 = F_25 ( V_8 -> V_16 , & ( V_9 -> V_4 ) , V_64 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_26 ( V_64 ) ;
if ( V_82 < 0 )
return V_82 ;
V_64 -> V_21 = V_9 ;
V_82 = F_20 ( V_9 , true , false , V_75 ) ;
if ( V_82 < 0 ) {
V_83:
V_64 = V_9 -> V_15 ;
F_27 ( V_64 ) ;
V_64 -> V_21 = NULL ;
return V_82 ;
}
V_64 = V_9 -> V_22 ;
V_82 = F_25 ( V_8 -> V_16 , & ( V_9 -> V_4 ) , V_64 ) ;
if ( V_82 )
goto V_83;
V_82 = F_26 ( V_64 ) ;
if ( V_82 < 0 )
goto V_83;
V_64 -> V_21 = V_9 ;
V_82 = F_20 ( V_9 , false , false , V_75 ) ;
if ( V_82 < 0 ) {
V_84:
V_64 = V_9 -> V_22 ;
F_27 ( V_64 ) ;
V_64 -> V_21 = NULL ;
goto V_83;
}
if ( V_81 == 0 )
goto V_85;
V_64 = V_9 -> V_32 ;
if ( V_64 ) {
V_82 = F_25 ( V_8 -> V_16 , & ( V_9 -> V_4 ) , V_64 ) ;
if ( V_82 )
goto V_84;
V_82 = F_26 ( V_64 ) ;
if ( V_82 < 0 )
goto V_84;
V_64 -> V_21 = V_9 ;
V_82 = F_20 ( V_9 , true , true , V_75 ) ;
if ( V_82 < 0 ) {
V_86:
V_64 = V_9 -> V_32 ;
if ( V_64 ) {
F_27 ( V_64 ) ;
V_64 -> V_21 = NULL ;
}
goto V_84;
}
}
V_64 = V_9 -> V_34 ;
if ( V_64 ) {
V_82 = F_25 ( V_8 -> V_16 , & ( V_9 -> V_4 ) , V_64 ) ;
if ( V_82 )
goto V_86;
V_82 = F_26 ( V_64 ) ;
if ( V_82 < 0 )
goto V_86;
V_64 -> V_21 = V_9 ;
V_82 = F_20 ( V_9 , false , true , V_75 ) ;
if ( V_82 < 0 ) {
F_27 ( V_64 ) ;
V_64 -> V_21 = NULL ;
goto V_86;
}
}
V_85:
V_9 -> V_87 = V_81 ;
F_7 ( V_8 , L_17 , V_9 -> V_4 . V_19 , V_81 ) ;
return V_82 ;
}
static int F_28 ( struct V_2 * V_3 ,
unsigned V_88 , unsigned V_81 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_59 -> V_8 ;
if ( V_9 -> V_15 -> V_21 )
F_22 ( V_9 ) ;
return F_24 ( V_8 , V_9 , V_81 ) ;
}
static int F_29 ( struct V_2 * V_3 , unsigned V_88 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return V_9 -> V_87 ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_22 ( V_9 ) ;
}
static int T_1 F_31 ( struct V_5 * V_6 )
{
struct V_1 * V_9 ;
int V_66 ;
V_9 = F_32 ( sizeof *V_9 , V_89 ) ;
if ( ! V_9 )
return - V_79 ;
V_9 -> V_4 . V_19 = L_18 ;
V_9 -> V_4 . V_90 = F_3 ;
V_9 -> V_4 . V_91 = F_10 ;
V_9 -> V_4 . V_92 = F_28 ;
V_9 -> V_4 . V_93 = F_29 ;
V_9 -> V_4 . V_94 = F_30 ;
V_66 = F_33 ( V_6 , & V_9 -> V_4 ) ;
if ( V_66 )
F_12 ( V_9 ) ;
return V_66 ;
}
static int F_34 ( struct V_5 * V_6 ,
const struct V_95 * V_96 )
{
struct V_55 * V_56 = V_6 -> V_8 -> V_56 ;
int V_97 = - V_98 ;
T_3 V_99 = F_35 ( V_96 -> V_100 ) ;
T_3 V_101 = F_35 ( V_96 -> V_102 ) ;
T_3 V_103 = F_35 ( V_96 -> V_104 ) ;
V_56 -> V_65 = V_105 ;
switch ( V_96 -> V_106 ) {
case 0x5b :
if ( V_96 -> V_107 != ( V_108 | V_109 ) )
goto V_110;
if ( V_101 || V_99 )
break;
if ( V_103 > V_56 -> V_65 )
break;
V_97 = V_103 ;
break;
case 0x5c :
if ( V_96 -> V_107 != ( V_111 | V_109 ) )
goto V_110;
if ( V_101 || V_99 )
break;
if ( V_103 > V_56 -> V_65 )
break;
V_97 = V_103 ;
break;
default:
V_110:
F_17 ( V_6 -> V_8 ,
L_19 ,
V_96 -> V_107 , V_96 -> V_106 ,
V_101 , V_99 , V_103 ) ;
}
if ( V_97 >= 0 ) {
F_17 ( V_6 -> V_8 , L_20 ,
V_96 -> V_107 , V_96 -> V_106 ,
V_101 , V_99 , V_103 ) ;
V_56 -> V_112 = 0 ;
V_56 -> V_65 = V_97 ;
V_97 = F_19 ( V_6 -> V_8 -> V_16 -> V_113 , V_56 , V_72 ) ;
if ( V_97 < 0 )
ERROR ( V_6 -> V_8 , L_21 ,
V_97 ) ;
}
return V_97 ;
}
int T_1 F_36 ( struct V_7 * V_8 , bool V_114 )
{
int V_10 ;
V_10 = F_37 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_115 [ 0 ] . V_10 = V_10 ;
V_12 . V_116 = V_10 ;
V_14 . V_116 = V_10 ;
V_117 . V_118 = V_10 ;
if ( V_114 )
V_117 . V_50 |= V_119 ;
if ( F_38 ( V_8 -> V_16 ) ) {
V_117 . V_120 = V_121 ;
V_117 . V_50 |= V_119 ;
}
return F_39 ( V_8 , & V_117 , F_31 ) ;
}
