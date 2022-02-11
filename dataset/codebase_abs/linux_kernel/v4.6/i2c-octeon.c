static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
T_1 V_5 ;
F_2 ( V_6 | V_3 | V_4 , V_2 -> V_7 + V_8 ) ;
do {
V_5 = F_3 ( V_2 -> V_7 + V_8 ) ;
} while ( ( V_5 & V_6 ) != 0 );
}
static T_2 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_5 ;
F_2 ( V_6 | V_3 | V_9 , V_2 -> V_7 + V_8 ) ;
do {
V_5 = F_3 ( V_2 -> V_7 + V_8 ) ;
} while ( ( V_5 & V_6 ) != 0 );
return V_5 & 0xFF ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_7 + V_10 ) ;
F_3 ( V_2 -> V_7 + V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_12 ;
F_9 ( V_2 -> V_13 , L_1 , V_14 ) ;
for ( V_12 = 0 ; V_12 < 9 ; V_12 ++ ) {
F_5 ( V_2 , 0 ) ;
F_10 ( 5 ) ;
F_5 ( V_2 , V_15 ) ;
F_10 ( 5 ) ;
}
F_5 ( V_2 , V_16 | V_15 ) ;
F_10 ( 5 ) ;
F_5 ( V_2 , V_16 ) ;
F_10 ( 5 ) ;
F_5 ( V_2 , 0 ) ;
}
static T_3 F_11 ( int V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
F_7 ( V_2 ) ;
F_12 ( & V_2 -> V_19 ) ;
return V_20 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return ( F_4 ( V_2 , V_21 ) & V_22 ) != 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
long V_23 ;
F_6 ( V_2 ) ;
V_23 = F_15 ( V_2 -> V_19 , F_13 ( V_2 ) ,
V_2 -> V_24 . V_25 ) ;
F_7 ( V_2 ) ;
if ( ! V_23 ) {
F_9 ( V_2 -> V_13 , L_2 , V_14 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_27 ;
T_2 V_4 ;
F_1 ( V_2 , V_21 ,
V_28 | V_29 ) ;
V_27 = F_14 ( V_2 ) ;
if ( V_27 ) {
if ( F_4 ( V_2 , V_30 ) == V_31 ) {
F_8 ( V_2 ) ;
F_1 ( V_2 , V_21 ,
V_28 | V_29 ) ;
V_27 = F_14 ( V_2 ) ;
}
if ( V_27 )
return V_27 ;
}
V_4 = F_4 ( V_2 , V_30 ) ;
if ( ( V_4 != V_32 ) && ( V_4 != V_33 ) ) {
F_17 ( V_2 -> V_13 , L_3 , V_14 , V_4 ) ;
return - V_34 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_21 ,
V_28 | V_35 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_36 ,
const T_2 * V_4 , int V_37 )
{
int V_12 , V_27 ;
T_2 V_5 ;
V_27 = F_16 ( V_2 ) ;
if ( V_27 )
return V_27 ;
F_1 ( V_2 , V_38 , V_36 << 1 ) ;
F_1 ( V_2 , V_21 , V_28 ) ;
V_27 = F_14 ( V_2 ) ;
if ( V_27 )
return V_27 ;
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ ) {
V_5 = F_4 ( V_2 , V_30 ) ;
if ( ( V_5 != V_39 ) && ( V_5 != V_40 ) ) {
F_17 ( V_2 -> V_13 ,
L_4 ,
V_14 , V_5 ) ;
return - V_34 ;
}
F_1 ( V_2 , V_38 , V_4 [ V_12 ] ) ;
F_1 ( V_2 , V_21 , V_28 ) ;
V_27 = F_14 ( V_2 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_36 ,
T_2 * V_4 , T_4 * V_41 , bool V_42 )
{
int V_12 , V_27 , V_37 = * V_41 ;
T_2 V_5 ;
if ( V_37 < 1 )
return - V_43 ;
V_27 = F_16 ( V_2 ) ;
if ( V_27 )
return V_27 ;
F_1 ( V_2 , V_38 , ( V_36 << 1 ) | 1 ) ;
F_1 ( V_2 , V_21 , V_28 ) ;
V_27 = F_14 ( V_2 ) ;
if ( V_27 )
return V_27 ;
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ ) {
V_5 = F_4 ( V_2 , V_30 ) ;
if ( ( V_5 != V_44 ) && ( V_5 != V_45 ) ) {
F_17 ( V_2 -> V_13 ,
L_5 ,
V_14 , V_5 ) ;
return - V_34 ;
}
if ( V_12 + 1 < V_37 )
F_1 ( V_2 , V_21 ,
V_28 | V_46 ) ;
else
F_1 ( V_2 , V_21 ,
V_28 ) ;
V_27 = F_14 ( V_2 ) ;
if ( V_27 )
return V_27 ;
V_4 [ V_12 ] = F_4 ( V_2 , V_38 ) ;
if ( V_42 && V_12 == 0 ) {
if ( V_4 [ V_12 ] > V_47 + 1 ) {
F_17 ( V_2 -> V_13 ,
L_6 ,
V_14 , V_4 [ V_12 ] ) ;
return - V_48 ;
}
V_37 += V_4 [ V_12 ] ;
}
}
* V_41 = V_37 ;
return 0 ;
}
static int F_21 ( struct V_49 * V_24 , struct V_50 * V_51 ,
int V_52 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_12 , V_53 = 0 ;
for ( V_12 = 0 ; V_53 == 0 && V_12 < V_52 ; V_12 ++ ) {
struct V_50 * V_54 = & V_51 [ V_12 ] ;
F_9 ( V_2 -> V_13 ,
L_7 ,
V_54 -> V_55 & V_56 ? L_8 : L_9 ,
V_54 -> V_57 , V_54 -> V_58 , V_12 + 1 , V_52 ) ;
if ( V_54 -> V_55 & V_56 )
V_53 = F_20 ( V_2 , V_54 -> V_58 , V_54 -> V_59 ,
& V_54 -> V_57 , V_54 -> V_55 & V_60 ) ;
else
V_53 = F_19 ( V_2 , V_54 -> V_58 , V_54 -> V_59 ,
V_54 -> V_57 ) ;
}
F_18 ( V_2 ) ;
return ( V_53 != 0 ) ? V_53 : V_52 ;
}
static T_5 F_23 ( struct V_49 * V_24 )
{
return V_61 | V_62 |
V_63 | V_64 ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_65 , V_66 , V_67 , V_68 , V_69 , V_70 , V_71 , V_72 ;
int V_73 = 0x18 , V_74 = 2 , V_75 = 0 , V_76 = 1000000 ;
for ( V_70 = 0 ; V_70 < 8 && V_76 != 0 ; V_70 ++ ) {
for ( V_69 = 15 ; V_69 >= 2 && V_76 != 0 ; V_69 -- ) {
V_65 = V_2 -> V_77 * ( V_69 + 1 ) * 10 ;
V_65 *= ( 1 << V_70 ) ;
V_66 = ( V_2 -> V_78 / ( V_65 * 2 ) ) - 1 ;
for ( V_67 = 0 ; V_67 <= 1 ; V_67 ++ ) {
V_68 = V_66 + V_67 ;
if ( V_68 < 5 || V_68 > 0xff )
continue;
V_71 = V_2 -> V_78 / ( 2 * ( V_68 + 1 ) ) ;
V_71 = V_71 / ( 1 << V_70 ) ;
V_71 = V_71 / ( V_69 + 1 ) / 10 ;
V_72 = abs ( V_71 - V_2 -> V_77 ) ;
if ( V_72 < V_76 ) {
V_76 = V_72 ;
V_73 = V_68 ;
V_74 = V_69 ;
V_75 = V_70 ;
}
}
}
}
F_1 ( V_2 , V_79 , V_73 ) ;
F_1 ( V_2 , V_80 , ( V_74 << 3 ) | V_75 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_81 ;
int V_82 ;
F_1 ( V_2 , V_21 , V_28 ) ;
F_1 ( V_2 , V_83 , 0 ) ;
for ( V_82 = 10 ; V_82 ; V_82 -- ) {
F_10 ( 1 ) ;
V_81 = F_4 ( V_2 , V_30 ) ;
if ( V_81 == V_31 )
return 0 ;
}
F_17 ( V_2 -> V_13 , L_10 , V_14 , V_81 ) ;
return - V_34 ;
}
static int F_26 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = V_85 -> V_13 . V_88 ;
struct V_89 * V_90 ;
struct V_1 * V_2 ;
int V_17 , V_27 = 0 ;
V_17 = F_27 ( V_85 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_2 = F_28 ( & V_85 -> V_13 , sizeof( * V_2 ) , V_91 ) ;
if ( ! V_2 ) {
V_27 = - V_92 ;
goto V_93;
}
V_2 -> V_13 = & V_85 -> V_13 ;
V_90 = F_29 ( V_85 , V_94 , 0 ) ;
V_2 -> V_7 = F_30 ( & V_85 -> V_13 , V_90 ) ;
if ( F_31 ( V_2 -> V_7 ) ) {
V_27 = F_32 ( V_2 -> V_7 ) ;
goto V_93;
}
if ( F_33 ( V_87 , L_11 , & V_2 -> V_77 ) &&
F_33 ( V_87 , L_12 , & V_2 -> V_77 ) ) {
F_17 ( V_2 -> V_13 ,
L_13 ) ;
V_27 = - V_95 ;
goto V_93;
}
V_2 -> V_78 = F_34 () ;
F_35 ( & V_2 -> V_19 ) ;
V_2 -> V_17 = V_17 ;
V_27 = F_36 ( & V_85 -> V_13 , V_2 -> V_17 ,
F_11 , 0 , V_96 , V_2 ) ;
if ( V_27 < 0 ) {
F_17 ( V_2 -> V_13 , L_14 ) ;
goto V_93;
}
V_27 = F_25 ( V_2 ) ;
if ( V_27 ) {
F_17 ( V_2 -> V_13 , L_15 ) ;
goto V_93;
}
F_24 ( V_2 ) ;
V_2 -> V_24 = V_97 ;
V_2 -> V_24 . V_13 . V_98 = & V_85 -> V_13 ;
V_2 -> V_24 . V_13 . V_88 = V_87 ;
F_37 ( & V_2 -> V_24 , V_2 ) ;
F_38 ( V_85 , V_2 ) ;
V_27 = F_39 ( & V_2 -> V_24 ) ;
if ( V_27 < 0 ) {
F_17 ( V_2 -> V_13 , L_16 ) ;
goto V_93;
}
F_40 ( V_2 -> V_13 , L_17 ) ;
return 0 ;
V_93:
return V_27 ;
}
static int F_41 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_42 ( V_85 ) ;
F_43 ( & V_2 -> V_24 ) ;
return 0 ;
}
