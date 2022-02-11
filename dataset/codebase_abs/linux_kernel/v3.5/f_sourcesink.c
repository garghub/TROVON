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
V_10 = F_4 ( V_6 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_11 . V_12 = V_10 ;
V_13 . V_12 = V_10 ;
V_9 -> V_14 = F_5 ( V_8 -> V_15 , & V_16 ) ;
if ( ! V_9 -> V_14 ) {
V_17:
ERROR ( V_8 , L_1 ,
V_3 -> V_18 , V_8 -> V_15 -> V_18 ) ;
return - V_19 ;
}
V_9 -> V_14 -> V_20 = V_8 ;
V_9 -> V_21 = F_5 ( V_8 -> V_15 , & V_22 ) ;
if ( ! V_9 -> V_21 )
goto V_17;
V_9 -> V_21 -> V_20 = V_8 ;
if ( V_23 < 1 )
V_23 = 1 ;
if ( V_23 > 16 )
V_23 = 16 ;
if ( V_24 > 2 )
V_24 = 2 ;
if ( V_25 > 15 )
V_25 = 15 ;
V_26 . V_27 = V_28 > 1023 ?
1023 : V_28 ;
V_26 . V_29 = V_23 ;
V_30 . V_27 = V_28 > 1023 ?
1023 : V_28 ;
V_30 . V_29 = V_23 ;
V_9 -> V_31 = F_5 ( V_8 -> V_15 , & V_26 ) ;
if ( ! V_9 -> V_31 )
goto V_32;
V_9 -> V_31 -> V_20 = V_8 ;
V_9 -> V_33 = F_5 ( V_8 -> V_15 , & V_30 ) ;
if ( V_9 -> V_33 ) {
V_9 -> V_33 -> V_20 = V_8 ;
} else {
V_9 -> V_31 -> V_20 = NULL ;
V_9 -> V_31 = NULL ;
V_32:
V_34 [ V_35 ] = NULL ;
V_36 [ V_37 ] = NULL ;
V_38 [ V_39 ] = NULL ;
}
if ( V_28 > 1024 )
V_28 = 1024 ;
if ( F_6 ( V_6 -> V_8 -> V_15 ) ) {
V_40 . V_41 =
V_16 . V_41 ;
V_42 . V_41 =
V_22 . V_41 ;
V_43 . V_27 = V_28 ;
V_43 . V_27 |= V_24 << 11 ;
V_43 . V_29 = V_23 ;
V_43 . V_41 =
V_26 . V_41 ;
V_44 . V_27 = V_28 ;
V_44 . V_27 |= V_24 << 11 ;
V_44 . V_29 = V_23 ;
V_44 . V_41 =
V_30 . V_41 ;
V_3 -> V_45 = V_36 ;
}
if ( F_7 ( V_6 -> V_8 -> V_15 ) ) {
V_46 . V_41 =
V_16 . V_41 ;
V_47 . V_41 =
V_22 . V_41 ;
V_48 . V_27 = V_28 ;
V_48 . V_29 = V_23 ;
V_49 . V_50 = V_24 ;
V_49 . V_51 = V_25 ;
V_49 . V_52 =
V_28 * ( V_24 + 1 ) * ( V_25 + 1 ) ;
V_48 . V_41 =
V_26 . V_41 ;
V_53 . V_27 = V_28 ;
V_53 . V_29 = V_23 ;
V_54 . V_50 = V_24 ;
V_54 . V_51 = V_25 ;
V_54 . V_52 =
V_28 * ( V_24 + 1 ) * ( V_25 + 1 ) ;
V_53 . V_41 =
V_30 . V_41 ;
V_3 -> V_55 = V_38 ;
}
F_8 ( V_8 , L_2 ,
( F_7 ( V_6 -> V_8 -> V_15 ) ? L_3 :
( F_6 ( V_6 -> V_8 -> V_15 ) ? L_4 : L_5 ) ) ,
V_3 -> V_18 , V_9 -> V_14 -> V_18 , V_9 -> V_21 -> V_18 ,
V_9 -> V_31 ? V_9 -> V_31 -> V_18 : L_6 ,
V_9 -> V_33 ? V_9 -> V_33 -> V_18 : L_6 ) ;
return 0 ;
}
static void
F_9 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
F_10 ( F_1 ( V_3 ) ) ;
}
static int F_11 ( struct V_1 * V_9 , struct V_56 * V_57 )
{
unsigned V_58 ;
T_2 * V_59 = V_57 -> V_59 ;
struct V_7 * V_8 = V_9 -> V_4 . V_60 -> V_8 ;
if ( V_61 == 2 )
return 0 ;
for ( V_58 = 0 ; V_58 < V_57 -> V_62 ; V_58 ++ , V_59 ++ ) {
switch ( V_61 ) {
case 0 :
if ( * V_59 == 0 )
continue;
break;
case 1 :
if ( * V_59 == ( T_2 ) ( V_58 % 63 ) )
continue;
break;
}
ERROR ( V_8 , L_7 , V_58 , * V_59 ) ;
F_12 ( V_9 -> V_21 ) ;
return - V_63 ;
}
return 0 ;
}
static void F_13 ( struct V_64 * V_65 , struct V_56 * V_57 )
{
unsigned V_58 ;
T_2 * V_59 = V_57 -> V_59 ;
switch ( V_61 ) {
case 0 :
memset ( V_57 -> V_59 , 0 , V_57 -> V_66 ) ;
break;
case 1 :
for ( V_58 = 0 ; V_58 < V_57 -> V_66 ; V_58 ++ )
* V_59 ++ = ( T_2 ) ( V_58 % 63 ) ;
break;
case 2 :
break;
}
}
static void F_14 ( struct V_64 * V_65 , struct V_56 * V_57 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 = V_65 -> V_20 ;
int V_67 = V_57 -> V_67 ;
if ( ! V_9 )
return;
V_8 = V_9 -> V_4 . V_60 -> V_8 ;
switch ( V_67 ) {
case 0 :
if ( V_65 == V_9 -> V_21 ) {
F_11 ( V_9 , V_57 ) ;
if ( V_61 != 2 )
memset ( V_57 -> V_59 , 0x55 , V_57 -> V_66 ) ;
} else
F_13 ( V_65 , V_57 ) ;
break;
case - V_68 :
case - V_69 :
case - V_70 :
F_15 ( V_8 , L_8 , V_65 -> V_18 , V_67 ,
V_57 -> V_62 , V_57 -> V_66 ) ;
if ( V_65 == V_9 -> V_21 )
F_11 ( V_9 , V_57 ) ;
F_16 ( V_65 , V_57 ) ;
return;
case - V_71 :
default:
#if 1
F_8 ( V_8 , L_9 , V_65 -> V_18 ,
V_67 , V_57 -> V_62 , V_57 -> V_66 ) ;
#endif
case - V_72 :
break;
}
V_67 = F_17 ( V_65 , V_57 , V_73 ) ;
if ( V_67 ) {
ERROR ( V_8 , L_10 ,
V_65 -> V_18 , V_57 -> V_66 , V_67 ) ;
F_12 ( V_65 ) ;
}
}
static int F_18 ( struct V_1 * V_9 , bool V_74 ,
bool V_75 , int V_76 )
{
struct V_64 * V_65 ;
struct V_56 * V_57 ;
int V_58 , V_77 , V_67 ;
for ( V_58 = 0 ; V_58 < 8 ; V_58 ++ ) {
if ( V_75 ) {
switch ( V_76 ) {
case V_78 :
V_77 = V_28 * ( V_24 + 1 ) *
( V_25 + 1 ) ;
break;
case V_79 :
V_77 = V_28 * ( V_24 + 1 ) ;
break;
default:
V_77 = V_28 > 1023 ?
1023 : V_28 ;
break;
}
V_65 = V_74 ? V_9 -> V_31 : V_9 -> V_33 ;
V_57 = F_19 ( V_65 , V_77 ) ;
} else {
V_65 = V_74 ? V_9 -> V_14 : V_9 -> V_21 ;
V_57 = F_19 ( V_65 , 0 ) ;
}
if ( ! V_57 )
return - V_80 ;
V_57 -> V_81 = F_14 ;
if ( V_74 )
F_13 ( V_65 , V_57 ) ;
else if ( V_61 != 2 )
memset ( V_57 -> V_59 , 0x55 , V_57 -> V_66 ) ;
V_67 = F_17 ( V_65 , V_57 , V_73 ) ;
if ( V_67 ) {
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_60 -> V_8 ;
ERROR ( V_8 , L_11 ,
V_75 ? L_12 : L_13 , V_74 ? L_14 : L_15 ,
V_65 -> V_18 , V_67 ) ;
F_16 ( V_65 , V_57 ) ;
}
if ( ! V_75 )
break;
}
return V_67 ;
}
static void F_20 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_60 -> V_8 ;
F_21 ( V_8 , V_9 -> V_14 , V_9 -> V_21 , V_9 -> V_31 ,
V_9 -> V_33 ) ;
F_15 ( V_8 , L_16 , V_9 -> V_4 . V_18 ) ;
}
static int
F_22 ( struct V_7 * V_8 , struct V_1 * V_9 ,
int V_82 )
{
int V_83 = 0 ;
int V_76 = V_8 -> V_15 -> V_76 ;
struct V_64 * V_65 ;
V_65 = V_9 -> V_14 ;
V_83 = F_23 ( V_8 -> V_15 , & ( V_9 -> V_4 ) , V_65 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_24 ( V_65 ) ;
if ( V_83 < 0 )
return V_83 ;
V_65 -> V_20 = V_9 ;
V_83 = F_18 ( V_9 , true , false , V_76 ) ;
if ( V_83 < 0 ) {
V_84:
V_65 = V_9 -> V_14 ;
F_25 ( V_65 ) ;
V_65 -> V_20 = NULL ;
return V_83 ;
}
V_65 = V_9 -> V_21 ;
V_83 = F_23 ( V_8 -> V_15 , & ( V_9 -> V_4 ) , V_65 ) ;
if ( V_83 )
goto V_84;
V_83 = F_24 ( V_65 ) ;
if ( V_83 < 0 )
goto V_84;
V_65 -> V_20 = V_9 ;
V_83 = F_18 ( V_9 , false , false , V_76 ) ;
if ( V_83 < 0 ) {
V_85:
V_65 = V_9 -> V_21 ;
F_25 ( V_65 ) ;
V_65 -> V_20 = NULL ;
goto V_84;
}
if ( V_82 == 0 )
goto V_86;
V_65 = V_9 -> V_31 ;
if ( V_65 ) {
V_83 = F_23 ( V_8 -> V_15 , & ( V_9 -> V_4 ) , V_65 ) ;
if ( V_83 )
goto V_85;
V_83 = F_24 ( V_65 ) ;
if ( V_83 < 0 )
goto V_85;
V_65 -> V_20 = V_9 ;
V_83 = F_18 ( V_9 , true , true , V_76 ) ;
if ( V_83 < 0 ) {
V_87:
V_65 = V_9 -> V_31 ;
if ( V_65 ) {
F_25 ( V_65 ) ;
V_65 -> V_20 = NULL ;
}
goto V_85;
}
}
V_65 = V_9 -> V_33 ;
if ( V_65 ) {
V_83 = F_23 ( V_8 -> V_15 , & ( V_9 -> V_4 ) , V_65 ) ;
if ( V_83 )
goto V_87;
V_83 = F_24 ( V_65 ) ;
if ( V_83 < 0 )
goto V_87;
V_65 -> V_20 = V_9 ;
V_83 = F_18 ( V_9 , false , true , V_76 ) ;
if ( V_83 < 0 ) {
F_25 ( V_65 ) ;
V_65 -> V_20 = NULL ;
goto V_87;
}
}
V_86:
V_9 -> V_88 = V_82 ;
F_8 ( V_8 , L_17 , V_9 -> V_4 . V_18 , V_82 ) ;
return V_83 ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned V_89 , unsigned V_82 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_60 -> V_8 ;
if ( V_9 -> V_14 -> V_20 )
F_20 ( V_9 ) ;
return F_22 ( V_8 , V_9 , V_82 ) ;
}
static int F_27 ( struct V_2 * V_3 , unsigned V_89 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return V_9 -> V_88 ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_20 ( V_9 ) ;
}
static int T_1 F_29 ( struct V_5 * V_6 )
{
struct V_1 * V_9 ;
int V_67 ;
V_9 = F_30 ( sizeof *V_9 , V_90 ) ;
if ( ! V_9 )
return - V_80 ;
V_9 -> V_4 . V_18 = L_18 ;
V_9 -> V_4 . V_91 = V_34 ;
V_9 -> V_4 . V_92 = F_3 ;
V_9 -> V_4 . V_93 = F_9 ;
V_9 -> V_4 . V_94 = F_26 ;
V_9 -> V_4 . V_95 = F_27 ;
V_9 -> V_4 . V_96 = F_28 ;
V_67 = F_31 ( V_6 , & V_9 -> V_4 ) ;
if ( V_67 )
F_10 ( V_9 ) ;
return V_67 ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_97 * V_98 )
{
struct V_56 * V_57 = V_6 -> V_8 -> V_57 ;
int V_99 = - V_100 ;
T_3 V_101 = F_33 ( V_98 -> V_102 ) ;
T_3 V_103 = F_33 ( V_98 -> V_104 ) ;
T_3 V_105 = F_33 ( V_98 -> V_106 ) ;
V_57 -> V_66 = V_107 ;
switch ( V_98 -> V_108 ) {
case 0x5b :
if ( V_98 -> V_109 != ( V_110 | V_111 ) )
goto V_112;
if ( V_103 || V_101 )
break;
if ( V_105 > V_57 -> V_66 )
break;
V_99 = V_105 ;
break;
case 0x5c :
if ( V_98 -> V_109 != ( V_113 | V_111 ) )
goto V_112;
if ( V_103 || V_101 )
break;
if ( V_105 > V_57 -> V_66 )
break;
V_99 = V_105 ;
break;
default:
V_112:
F_15 ( V_6 -> V_8 ,
L_19 ,
V_98 -> V_109 , V_98 -> V_108 ,
V_103 , V_101 , V_105 ) ;
}
if ( V_99 >= 0 ) {
F_15 ( V_6 -> V_8 , L_20 ,
V_98 -> V_109 , V_98 -> V_108 ,
V_103 , V_101 , V_105 ) ;
V_57 -> V_114 = 0 ;
V_57 -> V_66 = V_99 ;
V_99 = F_17 ( V_6 -> V_8 -> V_15 -> V_115 , V_57 , V_73 ) ;
if ( V_99 < 0 )
ERROR ( V_6 -> V_8 , L_21 ,
V_99 ) ;
}
return V_99 ;
}
int T_1 F_34 ( struct V_7 * V_8 , bool V_116 )
{
int V_10 ;
V_10 = F_35 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_117 [ 0 ] . V_10 = V_10 ;
V_11 . V_118 = V_10 ;
V_13 . V_118 = V_10 ;
V_119 . V_120 = V_10 ;
if ( V_116 )
V_119 . V_50 |= V_121 ;
if ( F_36 ( V_8 -> V_15 ) ) {
V_119 . V_91 = V_122 ;
V_119 . V_50 |= V_121 ;
}
return F_37 ( V_8 , & V_119 , F_29 ) ;
}
