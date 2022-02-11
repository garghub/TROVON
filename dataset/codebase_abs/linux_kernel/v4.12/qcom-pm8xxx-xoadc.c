static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( & V_6 -> F_3 ) ;
return V_7 ;
}
static struct V_8 *
F_4 ( struct V_5 * V_6 , T_2 V_9 )
{
struct V_8 * V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
V_10 = & V_6 -> V_13 [ V_11 ] ;
if ( V_10 -> V_14 -> V_15 == V_9 )
break;
}
if ( V_11 == V_6 -> V_12 )
return NULL ;
return V_10 ;
}
static int F_5 ( struct V_5 * V_6 ,
const struct V_8 * V_10 ,
T_2 V_16 , T_3 * V_17 ,
bool V_18 )
{
int V_19 ;
unsigned int V_20 ;
T_2 V_21 , V_22 ;
T_2 V_23 , V_24 ;
F_6 ( V_6 -> V_25 , L_1 ,
V_10 -> V_26 , V_10 -> V_14 -> V_15 , V_10 -> V_14 -> V_27 , V_16 ) ;
F_7 ( & V_6 -> V_28 ) ;
V_20 = V_10 -> V_14 -> V_15 << V_29 ;
V_20 |= V_10 -> V_14 -> V_27 << V_30 ;
V_19 = F_8 ( V_6 -> V_31 , V_32 , V_20 ) ;
if ( V_19 )
goto V_33;
V_21 = ( V_34 | V_35 |
V_36 | V_37 ) ;
if ( V_6 -> V_38 -> V_39 && ! V_18 ) {
if ( V_10 -> V_14 -> V_15 == V_40 )
V_22 = V_41 ;
else
V_22 = V_42 ;
} else {
if ( V_16 == 0xff )
V_22 = ( V_10 -> V_43 << V_44 ) |
V_45 ;
else
V_22 = ( V_16 << V_44 ) |
V_45 ;
}
V_19 = F_9 ( V_6 -> V_31 ,
V_46 ,
~ V_21 ,
V_22 ) ;
if ( V_19 )
goto V_33;
V_19 = F_8 ( V_6 -> V_31 , V_47 ,
V_48 ) ;
if ( V_19 )
goto V_33;
V_19 = F_8 ( V_6 -> V_31 , V_49 ,
V_50 |
V_51 |
V_10 -> V_52 << V_53 ) ;
if ( V_19 )
goto V_33;
V_19 = F_8 ( V_6 -> V_31 , V_47 ,
V_54 ) ;
if ( V_19 )
goto V_33;
V_19 = F_8 ( V_6 -> V_31 , V_55 ,
V_56 ) ;
if ( V_19 )
goto V_33;
V_19 = F_8 ( V_6 -> V_31 , V_55 ,
V_56 ) ;
if ( V_19 )
goto V_33;
F_10 ( & V_6 -> F_3 ) ;
V_19 = F_8 ( V_6 -> V_31 , V_55 ,
V_56 |
V_57 ) ;
if ( V_19 )
goto V_33;
V_19 = F_11 ( & V_6 -> F_3 ,
V_58 ) ;
if ( ! V_19 ) {
F_12 ( V_6 -> V_25 , L_2 ) ;
V_19 = - V_59 ;
goto V_33;
}
V_19 = F_13 ( V_6 -> V_31 , V_60 , & V_20 ) ;
if ( V_19 )
goto V_33;
V_23 = V_20 ;
V_19 = F_13 ( V_6 -> V_31 , V_61 , & V_20 ) ;
if ( V_19 )
goto V_33;
V_24 = V_20 ;
* V_17 = ( V_24 << 8 ) | V_23 ;
V_19 = F_8 ( V_6 -> V_31 , V_55 , 0 ) ;
if ( V_19 )
goto V_33;
V_19 = F_8 ( V_6 -> V_31 , V_55 , 0 ) ;
if ( V_19 )
goto V_33;
V_33:
F_14 ( & V_6 -> V_28 ) ;
return V_19 ;
}
static int F_15 ( struct V_5 * V_6 ,
const struct V_8 * V_10 ,
T_3 * V_17 )
{
return F_5 ( V_6 , V_10 , 0xff , V_17 , false ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
const struct V_8 * V_10 ;
T_3 V_62 ;
T_3 V_63 ;
T_3 V_64 ;
T_3 V_65 ;
int V_19 ;
V_6 -> V_66 [ V_67 ] . V_68 = V_69 ;
V_6 -> V_66 [ V_70 ] . V_68 = V_71 ;
V_10 = F_4 ( V_6 , V_72 ) ;
if ( ! V_10 )
return - V_73 ;
V_19 = F_15 ( V_6 , V_10 , & V_62 ) ;
if ( V_19 ) {
F_12 ( V_6 -> V_25 , L_3 ) ;
return - V_73 ;
}
V_10 = F_4 ( V_6 , V_74 ) ;
if ( ! V_10 )
return - V_73 ;
V_19 = F_15 ( V_6 , V_10 , & V_63 ) ;
if ( V_19 ) {
F_12 ( V_6 -> V_25 , L_4 ) ;
return - V_73 ;
}
if ( V_62 == V_63 ) {
F_12 ( V_6 -> V_25 , L_5 ) ;
return - V_73 ;
}
V_6 -> V_66 [ V_67 ] . V_75 = V_62 - V_63 ;
V_6 -> V_66 [ V_67 ] . V_76 = V_63 ;
F_17 ( V_6 -> V_25 , L_6 ,
V_69 , V_6 -> V_66 [ V_67 ] . V_75 ) ;
V_10 = F_4 ( V_6 , V_40 ) ;
if ( ! V_10 )
return - V_73 ;
V_19 = F_5 ( V_6 , V_10 , V_77 ,
& V_64 , true ) ;
if ( V_19 ) {
F_12 ( V_6 -> V_25 , L_7 ) ;
return - V_73 ;
}
V_19 = F_5 ( V_6 , V_10 , V_78 ,
& V_65 , true ) ;
if ( V_19 ) {
F_12 ( V_6 -> V_25 , L_7 ) ;
return - V_73 ;
}
V_6 -> V_66 [ V_70 ] . V_75 =
V_64 - V_65 ;
V_6 -> V_66 [ V_70 ] . V_76 = V_65 ;
F_17 ( V_6 -> V_25 , L_8 ,
V_71 ,
V_6 -> V_66 [ V_70 ] . V_75 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_79 const * V_9 ,
int * V_20 , int * V_80 , long V_81 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
const struct V_8 * V_10 ;
T_3 V_17 ;
int V_19 ;
switch ( V_81 ) {
case V_82 :
V_10 = F_4 ( V_6 , V_9 -> V_83 ) ;
if ( ! V_10 ) {
F_12 ( V_6 -> V_25 , L_9 ,
V_9 -> V_83 ) ;
return - V_84 ;
}
V_19 = F_15 ( V_6 , V_10 , & V_17 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_19 ( V_10 -> V_14 -> V_85 ,
& V_6 -> V_66 [ V_10 -> V_86 ] ,
& V_10 -> V_14 -> V_87 ,
( V_10 -> V_86 == V_67 ) ,
V_17 , V_20 ) ;
if ( V_19 )
return V_19 ;
return V_88 ;
case V_89 :
V_10 = F_4 ( V_6 , V_9 -> V_83 ) ;
if ( ! V_10 ) {
F_12 ( V_6 -> V_25 , L_9 ,
V_9 -> V_83 ) ;
return - V_84 ;
}
V_19 = F_15 ( V_6 , V_10 , & V_17 ) ;
if ( V_19 )
return V_19 ;
* V_20 = ( int ) V_17 ;
return V_88 ;
default:
return - V_84 ;
}
}
static int F_20 ( struct V_3 * V_4 ,
const struct V_90 * V_91 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_27 ;
T_2 V_15 ;
unsigned int V_11 ;
if ( V_91 -> V_92 != 2 ) {
F_12 ( & V_4 -> V_25 , L_10 ,
V_91 -> V_93 -> V_26 ,
V_91 -> V_92 ) ;
return - V_84 ;
}
V_27 = ( T_2 ) V_91 -> args [ 0 ] ;
V_15 = ( T_2 ) V_91 -> args [ 1 ] ;
F_6 ( & V_4 -> V_25 , L_11 ,
V_27 , V_15 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ )
if ( V_6 -> V_13 [ V_11 ] . V_14 -> V_27 == V_27 &&
V_6 -> V_13 [ V_11 ] . V_14 -> V_15 == V_15 )
return V_11 ;
return - V_84 ;
}
static int F_21 ( struct V_94 * V_25 ,
struct V_95 * V_93 ,
const struct V_96 * V_97 ,
struct V_79 * V_98 ,
struct V_8 * V_10 )
{
const char * V_26 = V_93 -> V_26 ;
const struct V_96 * V_14 ;
T_4 V_27 , V_15 ;
T_4 V_16 , V_99 ;
int V_19 ;
int V_100 ;
V_19 = F_22 ( V_93 , L_12 , 0 , & V_27 ) ;
if ( V_19 ) {
F_12 ( V_25 , L_13 , V_26 ) ;
return V_19 ;
}
V_19 = F_22 ( V_93 , L_12 , 1 , & V_15 ) ;
if ( V_19 ) {
F_12 ( V_25 , L_14 , V_26 ) ;
return V_19 ;
}
V_100 = 0 ;
V_14 = & V_97 [ 0 ] ;
while ( V_14 && V_14 -> V_101 ) {
if ( V_14 -> V_27 == V_27 &&
V_14 -> V_15 == V_15 )
break;
V_14 ++ ;
V_100 ++ ;
}
if ( ! V_14 -> V_101 ) {
F_12 ( V_25 , L_15 ,
V_27 , V_15 ) ;
return - V_84 ;
}
V_10 -> V_26 = V_26 ;
V_10 -> V_14 = V_14 ;
V_10 -> V_86 = V_67 ;
V_10 -> V_52 = V_102 ;
if ( ! F_23 ( V_93 , L_16 , & V_16 ) ) {
V_10 -> V_86 = V_70 ;
if ( V_16 > V_103 ) {
F_12 ( V_25 , L_17 , V_26 , V_16 ) ;
return - V_84 ;
}
if ( V_16 == V_104 ) {
F_12 ( V_25 , L_18 , V_26 , V_16 ) ;
return - V_84 ;
}
}
V_19 = F_23 ( V_93 , L_19 , & V_99 ) ;
if ( ! V_19 ) {
V_19 = F_24 ( V_99 ) ;
if ( V_19 < 0 ) {
F_12 ( V_25 , L_20 ,
V_26 , V_99 ) ;
return V_19 ;
}
V_10 -> V_52 = V_19 ;
}
V_98 -> V_105 = V_100 ;
V_98 -> V_83 = V_14 -> V_15 ;
V_98 -> V_101 = V_14 -> V_101 ;
V_98 -> type = V_14 -> type ;
V_98 -> V_106 = F_25 ( V_89 ) |
F_25 ( V_82 ) ;
V_98 -> V_107 = 1 ;
F_6 ( V_25 , L_21
L_22
L_23 ,
V_14 -> V_27 , V_14 -> V_15 , V_10 -> V_26 ,
V_10 -> V_43 , V_10 -> V_52 , V_14 -> V_87 . V_108 ,
V_14 -> V_87 . V_109 , V_14 -> V_85 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_95 * V_93 )
{
struct V_95 * V_110 ;
struct V_8 * V_10 ;
int V_19 ;
int V_11 ;
V_6 -> V_12 = F_27 ( V_93 ) ;
if ( ! V_6 -> V_12 ) {
F_12 ( V_6 -> V_25 , L_24 ) ;
return - V_73 ;
}
F_6 ( V_6 -> V_25 , L_25 , V_6 -> V_12 ) ;
V_6 -> V_111 = F_28 ( V_6 -> V_25 , V_6 -> V_12 ,
sizeof( * V_6 -> V_111 ) , V_112 ) ;
if ( ! V_6 -> V_111 )
return - V_113 ;
V_6 -> V_13 = F_28 ( V_6 -> V_25 , V_6 -> V_12 ,
sizeof( * V_6 -> V_13 ) , V_112 ) ;
if ( ! V_6 -> V_13 )
return - V_113 ;
V_11 = 0 ;
F_29 (np, child) {
V_10 = & V_6 -> V_13 [ V_11 ] ;
V_19 = F_21 ( V_6 -> V_25 , V_110 ,
V_6 -> V_38 -> V_114 ,
& V_6 -> V_111 [ V_11 ] ,
V_10 ) ;
if ( V_19 ) {
F_30 ( V_110 ) ;
return V_19 ;
}
V_11 ++ ;
}
V_10 = F_4 ( V_6 , V_72 ) ;
if ( ! V_10 ) {
F_12 ( V_6 -> V_25 , L_26 ) ;
return - V_73 ;
}
V_10 = F_4 ( V_6 , V_74 ) ;
if ( ! V_10 ) {
F_12 ( V_6 -> V_25 , L_27 ) ;
return - V_73 ;
}
V_10 = F_4 ( V_6 , V_40 ) ;
if ( ! V_10 ) {
F_12 ( V_6 -> V_25 , L_28 ) ;
return - V_73 ;
}
return 0 ;
}
static int F_31 ( struct V_115 * V_116 )
{
const struct V_117 * V_38 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_95 * V_93 = V_116 -> V_25 . V_118 ;
struct V_119 * V_31 ;
struct V_94 * V_25 = & V_116 -> V_25 ;
int V_19 ;
V_38 = F_32 ( V_25 ) ;
if ( ! V_38 )
return - V_73 ;
V_4 = F_33 ( V_25 , sizeof( * V_6 ) ) ;
if ( ! V_4 )
return - V_113 ;
F_34 ( V_116 , V_4 ) ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_25 = V_25 ;
V_6 -> V_38 = V_38 ;
F_35 ( & V_6 -> F_3 ) ;
F_36 ( & V_6 -> V_28 ) ;
V_19 = F_26 ( V_6 , V_93 ) ;
if ( V_19 )
return V_19 ;
V_31 = F_37 ( V_25 -> V_120 , NULL ) ;
if ( ! V_31 ) {
F_12 ( V_25 , L_29 ) ;
return - V_121 ;
}
V_6 -> V_31 = V_31 ;
V_6 -> V_122 = F_38 ( V_25 , L_30 ) ;
if ( F_39 ( V_6 -> V_122 ) ) {
F_12 ( V_25 , L_31 ) ;
return F_40 ( V_6 -> V_122 ) ;
}
V_19 = F_41 ( V_6 -> V_122 ) ;
if ( V_19 ) {
F_12 ( V_25 , L_32 ) ;
return V_19 ;
}
V_19 = F_42 ( V_25 , F_43 ( V_116 , 0 ) ,
F_1 , NULL , 0 , V_38 -> V_26 , V_4 ) ;
if ( V_19 ) {
F_12 ( V_25 , L_33 ) ;
goto V_123;
}
V_4 -> V_25 . V_120 = V_25 ;
V_4 -> V_25 . V_118 = V_93 ;
V_4 -> V_26 = V_38 -> V_26 ;
V_4 -> V_124 = V_125 ;
V_4 -> V_126 = & V_127 ;
V_4 -> V_114 = V_6 -> V_111 ;
V_4 -> V_128 = V_6 -> V_12 ;
V_19 = F_44 ( V_4 ) ;
if ( V_19 )
goto V_123;
V_19 = F_16 ( V_6 ) ;
if ( V_19 )
goto V_129;
F_17 ( V_25 , L_34 , V_38 -> V_26 ) ;
return 0 ;
V_129:
F_45 ( V_4 ) ;
V_123:
F_46 ( V_6 -> V_122 ) ;
return V_19 ;
}
static int F_47 ( struct V_115 * V_116 )
{
struct V_3 * V_4 = F_48 ( V_116 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_45 ( V_4 ) ;
F_46 ( V_6 -> V_122 ) ;
return 0 ;
}
