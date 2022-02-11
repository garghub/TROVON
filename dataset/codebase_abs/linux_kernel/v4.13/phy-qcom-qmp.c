static inline void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + V_2 ) ;
V_4 |= V_3 ;
F_3 ( V_4 , V_1 + V_2 ) ;
F_2 ( V_1 + V_2 ) ;
}
static inline void F_4 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + V_2 ) ;
V_4 &= ~ V_3 ;
F_3 ( V_4 , V_1 + V_2 ) ;
F_2 ( V_1 + V_2 ) ;
}
static void F_5 ( void T_1 * V_1 ,
const unsigned int * V_5 ,
const struct V_6 V_7 [] ,
int V_8 )
{
int V_9 ;
const struct V_6 * V_10 = V_7 ;
if ( ! V_10 )
return;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ , V_10 ++ ) {
if ( V_10 -> V_11 )
F_3 ( V_10 -> V_3 , V_1 + V_5 [ V_10 -> V_2 ] ) ;
else
F_3 ( V_10 -> V_3 , V_1 + V_10 -> V_2 ) ;
}
}
static int F_6 ( struct V_12 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_16 ;
int V_8 = V_16 -> V_17 -> V_18 ;
int V_19 ;
F_8 ( & V_12 -> V_20 , L_1 ) ;
V_19 = F_9 ( V_8 , V_16 -> V_21 ) ;
if ( V_19 ) {
F_10 ( V_16 -> V_20 , L_2 , V_19 ) ;
return V_19 ;
}
V_19 = F_11 ( V_14 -> V_22 ) ;
if ( V_19 ) {
F_10 ( V_16 -> V_20 , L_3 , V_19 ) ;
F_12 ( V_8 , V_16 -> V_21 ) ;
return V_19 ;
}
return 0 ;
}
static int F_13 ( struct V_12 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_16 ;
F_14 ( V_14 -> V_22 ) ;
F_12 ( V_16 -> V_17 -> V_18 , V_16 -> V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 )
{
const struct V_23 * V_17 = V_16 -> V_17 ;
void T_1 * V_24 = V_16 -> V_24 ;
int V_19 , V_9 ;
F_16 ( & V_16 -> V_25 ) ;
if ( V_16 -> V_26 ++ ) {
F_17 ( & V_16 -> V_25 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < V_17 -> V_27 ; V_9 ++ ) {
V_19 = F_18 ( V_16 -> V_28 [ V_9 ] ) ;
if ( V_19 ) {
F_10 ( V_16 -> V_20 , L_4 ,
V_16 -> V_17 -> V_29 [ V_9 ] ) ;
while ( -- V_9 >= 0 )
F_19 ( V_16 -> V_28 [ V_9 ] ) ;
goto V_30;
}
}
if ( V_17 -> V_31 )
F_1 ( V_24 , V_17 -> V_5 [ V_32 ] ,
V_33 ) ;
F_5 ( V_24 , V_17 -> V_5 , V_17 -> V_34 ,
V_17 -> V_35 ) ;
if ( V_17 -> V_31 ) {
void T_1 * V_36 ;
unsigned int V_37 , V_3 ;
F_4 ( V_24 , V_17 -> V_5 [ V_38 ] , V_39 ) ;
F_1 ( V_24 , V_17 -> V_5 [ V_40 ] ,
V_41 | V_42 ) ;
V_36 = V_24 + V_17 -> V_5 [ V_43 ] ;
V_37 = V_17 -> V_44 ;
V_19 = F_20 ( V_36 , V_3 , ( V_3 & V_37 ) , 10 ,
V_45 ) ;
if ( V_19 ) {
F_10 ( V_16 -> V_20 ,
L_5 ) ;
goto V_46;
}
}
F_17 ( & V_16 -> V_25 ) ;
return 0 ;
V_46:
while ( -- V_9 >= 0 )
F_19 ( V_16 -> V_28 [ V_9 ] ) ;
V_30:
F_17 ( & V_16 -> V_25 ) ;
return V_19 ;
}
static int F_21 ( struct V_15 * V_16 )
{
const struct V_23 * V_17 = V_16 -> V_17 ;
void T_1 * V_24 = V_16 -> V_24 ;
int V_9 = V_17 -> V_27 ;
F_16 ( & V_16 -> V_25 ) ;
if ( -- V_16 -> V_26 ) {
F_17 ( & V_16 -> V_25 ) ;
return 0 ;
}
if ( V_17 -> V_31 ) {
F_1 ( V_24 , V_17 -> V_5 [ V_40 ] ,
V_41 | V_42 ) ;
F_4 ( V_24 , V_17 -> V_5 [ V_38 ] ,
V_39 ) ;
F_1 ( V_24 , V_17 -> V_5 [ V_32 ] ,
V_33 ) ;
}
while ( -- V_9 >= 0 )
F_19 ( V_16 -> V_28 [ V_9 ] ) ;
F_17 ( & V_16 -> V_25 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_16 ;
const struct V_23 * V_17 = V_16 -> V_17 ;
void T_1 * V_47 = V_14 -> V_47 ;
void T_1 * V_48 = V_14 -> V_48 ;
void T_1 * V_49 = V_14 -> V_49 ;
void T_1 * V_36 ;
unsigned int V_37 , V_3 ;
int V_19 , V_9 ;
F_8 ( V_16 -> V_20 , L_6 ) ;
for ( V_9 = 0 ; V_9 < V_16 -> V_17 -> V_50 ; V_9 ++ ) {
V_19 = F_11 ( V_16 -> V_51 [ V_9 ] ) ;
if ( V_19 ) {
F_10 ( V_16 -> V_20 , L_7 ,
V_16 -> V_17 -> V_52 [ V_9 ] , V_19 ) ;
while ( -- V_9 >= 0 )
F_14 ( V_16 -> V_51 [ V_9 ] ) ;
}
}
V_19 = F_15 ( V_16 ) ;
if ( V_19 )
goto V_46;
if ( V_17 -> V_53 ) {
V_19 = F_18 ( V_14 -> V_54 ) ;
if ( V_19 ) {
F_10 ( V_16 -> V_20 , L_8 ,
V_14 -> V_55 ) ;
goto V_56;
}
}
F_5 ( V_47 , V_17 -> V_5 , V_17 -> V_57 , V_17 -> V_58 ) ;
F_5 ( V_48 , V_17 -> V_5 , V_17 -> V_59 , V_17 -> V_60 ) ;
F_5 ( V_49 , V_17 -> V_5 , V_17 -> V_61 , V_17 -> V_62 ) ;
F_1 ( V_49 , V_63 , V_17 -> V_64 ) ;
if ( V_17 -> V_65 )
F_23 ( V_17 -> V_66 , V_17 -> V_67 ) ;
F_1 ( V_49 , V_17 -> V_5 [ V_68 ] , V_17 -> V_69 ) ;
F_4 ( V_49 , V_17 -> V_5 [ V_70 ] , V_39 ) ;
V_36 = V_49 + V_17 -> V_5 [ V_71 ] ;
V_37 = V_17 -> V_72 ;
V_19 = F_20 ( V_36 , V_3 , ! ( V_3 & V_37 ) , 1 ,
V_45 ) ;
if ( V_19 ) {
F_10 ( V_16 -> V_20 , L_9 ) ;
goto V_73;
}
return V_19 ;
V_73:
if ( V_17 -> V_53 )
F_19 ( V_14 -> V_54 ) ;
V_56:
F_21 ( V_16 ) ;
V_46:
while ( -- V_9 >= 0 )
F_14 ( V_16 -> V_51 [ V_9 ] ) ;
return V_19 ;
}
static int F_24 ( struct V_12 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_16 ;
const struct V_23 * V_17 = V_16 -> V_17 ;
int V_9 = V_17 -> V_50 ;
F_1 ( V_14 -> V_49 , V_17 -> V_5 [ V_70 ] , V_39 ) ;
F_4 ( V_14 -> V_49 , V_17 -> V_5 [ V_68 ] , V_17 -> V_69 ) ;
F_4 ( V_14 -> V_49 , V_63 , V_17 -> V_64 ) ;
if ( V_17 -> V_53 )
F_19 ( V_14 -> V_54 ) ;
F_21 ( V_16 ) ;
while ( -- V_9 >= 0 )
F_14 ( V_16 -> V_51 [ V_9 ] ) ;
return 0 ;
}
static int F_25 ( struct V_74 * V_20 )
{
struct V_15 * V_16 = F_26 ( V_20 ) ;
int V_8 = V_16 -> V_17 -> V_18 ;
int V_9 ;
V_16 -> V_21 = F_27 ( V_20 , V_8 , sizeof( * V_16 -> V_21 ) , V_75 ) ;
if ( ! V_16 -> V_21 )
return - V_76 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_16 -> V_21 [ V_9 ] . V_77 = V_16 -> V_17 -> V_78 [ V_9 ] ;
return F_28 ( V_20 , V_8 , V_16 -> V_21 ) ;
}
static int F_29 ( struct V_74 * V_20 )
{
struct V_15 * V_16 = F_26 ( V_20 ) ;
int V_9 ;
V_16 -> V_28 = F_27 ( V_20 , V_16 -> V_17 -> V_27 ,
sizeof( * V_16 -> V_28 ) , V_75 ) ;
if ( ! V_16 -> V_28 )
return - V_76 ;
for ( V_9 = 0 ; V_9 < V_16 -> V_17 -> V_27 ; V_9 ++ ) {
struct V_79 * V_80 ;
const char * V_81 = V_16 -> V_17 -> V_29 [ V_9 ] ;
V_80 = F_30 ( V_20 , V_81 ) ;
if ( F_31 ( V_80 ) ) {
F_10 ( V_20 , L_10 , V_81 ) ;
return F_32 ( V_80 ) ;
}
V_16 -> V_28 [ V_9 ] = V_80 ;
}
return 0 ;
}
static int F_33 ( struct V_74 * V_20 )
{
struct V_15 * V_16 = F_26 ( V_20 ) ;
int V_19 , V_9 ;
V_16 -> V_51 = F_27 ( V_20 , V_16 -> V_17 -> V_50 ,
sizeof( * V_16 -> V_51 ) , V_75 ) ;
if ( ! V_16 -> V_51 )
return - V_76 ;
for ( V_9 = 0 ; V_9 < V_16 -> V_17 -> V_50 ; V_9 ++ ) {
struct V_82 * V_83 ;
const char * V_81 = V_16 -> V_17 -> V_52 [ V_9 ] ;
V_83 = F_34 ( V_20 , V_81 ) ;
if ( F_31 ( V_83 ) ) {
V_19 = F_32 ( V_83 ) ;
if ( V_19 != - V_84 )
F_10 ( V_20 , L_11 ,
V_81 , V_19 ) ;
return V_19 ;
}
V_16 -> V_51 [ V_9 ] = V_83 ;
}
return 0 ;
}
static int F_35 ( struct V_15 * V_16 , int V_85 )
{
char V_81 [ 24 ] ;
struct V_86 * V_87 ;
struct V_88 V_89 = { } ;
switch ( V_16 -> V_17 -> type ) {
case V_90 :
snprintf ( V_81 , sizeof( V_81 ) , L_12 ) ;
break;
case V_91 :
snprintf ( V_81 , sizeof( V_81 ) , L_13 , V_85 ) ;
break;
default:
return 0 ;
}
V_87 = F_36 ( V_16 -> V_20 , sizeof( * V_87 ) , V_75 ) ;
if ( ! V_87 )
return - V_76 ;
V_89 . V_81 = V_81 ;
V_89 . V_92 = & V_93 ;
V_87 -> V_94 = 125000000 ;
V_87 -> V_95 . V_89 = & V_89 ;
return F_37 ( V_16 -> V_20 , & V_87 -> V_95 ) ;
}
static
int F_38 ( struct V_74 * V_20 , struct V_96 * V_97 , int V_85 )
{
struct V_15 * V_16 = F_26 ( V_20 ) ;
struct V_12 * V_98 ;
struct V_13 * V_14 ;
char V_99 [ V_100 ] ;
int V_19 ;
V_14 = F_36 ( V_20 , sizeof( * V_14 ) , V_75 ) ;
if ( ! V_14 )
return - V_76 ;
V_14 -> V_47 = F_39 ( V_97 , 0 ) ;
if ( ! V_14 -> V_47 )
return - V_76 ;
V_14 -> V_48 = F_39 ( V_97 , 1 ) ;
if ( ! V_14 -> V_48 )
return - V_76 ;
V_14 -> V_49 = F_39 ( V_97 , 2 ) ;
if ( ! V_14 -> V_49 )
return - V_76 ;
snprintf ( V_99 , sizeof( V_99 ) , L_14 , V_85 ) ;
V_14 -> V_22 = F_40 ( V_97 , V_99 ) ;
if ( F_31 ( V_14 -> V_22 ) ) {
if ( V_16 -> V_17 -> type == V_91 ||
V_16 -> V_17 -> type == V_90 ) {
V_19 = F_32 ( V_14 -> V_22 ) ;
if ( V_19 != - V_84 )
F_10 ( V_20 ,
L_15 ,
V_85 , V_19 ) ;
return V_19 ;
}
V_14 -> V_22 = NULL ;
}
if ( V_16 -> V_17 -> V_53 ) {
snprintf ( V_99 , sizeof( V_99 ) , L_16 , V_85 ) ;
V_14 -> V_54 = F_41 ( V_97 , V_99 ) ;
if ( F_31 ( V_14 -> V_54 ) ) {
F_10 ( V_20 , L_17 , V_85 ) ;
return F_32 ( V_14 -> V_54 ) ;
}
}
V_98 = F_42 ( V_20 , V_97 , & V_101 ) ;
if ( F_31 ( V_98 ) ) {
V_19 = F_32 ( V_98 ) ;
F_10 ( V_20 , L_18 , V_19 ) ;
return V_19 ;
}
V_14 -> V_12 = V_98 ;
V_14 -> V_55 = V_85 ;
V_14 -> V_16 = V_16 ;
V_16 -> V_102 [ V_85 ] = V_14 ;
F_43 ( V_98 , V_14 ) ;
return 0 ;
}
static int F_44 ( struct V_103 * V_104 )
{
struct V_15 * V_16 ;
struct V_74 * V_20 = & V_104 -> V_20 ;
struct V_105 * V_106 ;
struct V_96 * V_107 ;
struct V_108 * V_108 ;
void T_1 * V_1 ;
int V_8 , V_85 ;
int V_19 ;
V_16 = F_36 ( V_20 , sizeof( * V_16 ) , V_75 ) ;
if ( ! V_16 )
return - V_76 ;
V_16 -> V_20 = V_20 ;
F_45 ( V_20 , V_16 ) ;
V_106 = F_46 ( V_104 , V_109 , 0 ) ;
V_1 = F_47 ( V_20 , V_106 ) ;
if ( F_31 ( V_1 ) )
return F_32 ( V_1 ) ;
V_16 -> V_24 = V_1 ;
F_48 ( & V_16 -> V_25 ) ;
V_16 -> V_17 = F_49 ( V_20 ) ;
V_19 = F_33 ( V_20 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_29 ( V_20 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_25 ( V_20 ) ;
if ( V_19 ) {
F_10 ( V_20 , L_19 ) ;
return V_19 ;
}
V_8 = F_50 ( V_20 -> V_110 ) ;
if ( V_8 > V_16 -> V_17 -> V_111 )
return - V_112 ;
V_16 -> V_102 = F_27 ( V_20 , V_8 , sizeof( * V_16 -> V_102 ) , V_75 ) ;
if ( ! V_16 -> V_102 )
return - V_76 ;
V_85 = 0 ;
F_51 (dev->of_node, child) {
V_19 = F_38 ( V_20 , V_107 , V_85 ) ;
if ( V_19 ) {
F_10 ( V_20 , L_20 ,
V_85 , V_19 ) ;
return V_19 ;
}
V_19 = F_35 ( V_16 , V_85 ) ;
if ( V_19 ) {
F_10 ( V_16 -> V_20 ,
L_21 ) ;
return V_19 ;
}
V_85 ++ ;
}
V_108 = F_52 ( V_20 , V_113 ) ;
if ( ! F_31 ( V_108 ) )
F_53 ( V_20 , L_22 ) ;
return F_54 ( V_108 ) ;
}
