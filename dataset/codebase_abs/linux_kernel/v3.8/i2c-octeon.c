static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 )
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
F_5 ( V_2 , 0x40 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_11 ;
F_9 ( V_2 -> V_12 , L_1 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 9 ; V_11 ++ ) {
F_5 ( V_2 , 0x0 ) ;
F_10 ( 5 ) ;
F_5 ( V_2 , 0x200 ) ;
F_10 ( 5 ) ;
}
F_5 ( V_2 , 0x300 ) ;
F_10 ( 5 ) ;
F_5 ( V_2 , 0x100 ) ;
F_10 ( 5 ) ;
F_5 ( V_2 , 0x0 ) ;
}
static T_3 F_11 ( int V_14 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
F_7 ( V_2 ) ;
F_12 ( & V_2 -> V_16 ) ;
return V_17 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return ( F_4 ( V_2 , V_18 ) & V_19 ) != 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_20 ;
F_6 ( V_2 ) ;
V_20 = F_15 ( V_2 -> V_16 ,
F_13 ( V_2 ) ,
V_2 -> V_21 . V_22 ) ;
F_7 ( V_2 ) ;
if ( V_20 < 0 ) {
F_9 ( V_2 -> V_12 , L_2 , V_13 ) ;
return V_20 ;
} else if ( V_20 == 0 ) {
F_9 ( V_2 -> V_12 , L_3 , V_13 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_20 ;
F_1 ( V_2 , V_18 ,
V_24 | V_25 ) ;
V_20 = F_14 ( V_2 ) ;
if ( V_20 ) {
if ( F_4 ( V_2 , V_26 ) == V_27 ) {
F_8 ( V_2 ) ;
F_1 ( V_2 , V_18 ,
V_24 | V_25 ) ;
V_20 = F_14 ( V_2 ) ;
}
if ( V_20 )
return V_20 ;
}
V_4 = F_4 ( V_2 , V_26 ) ;
if ( ( V_4 != V_28 ) && ( V_4 != V_29 ) ) {
F_17 ( V_2 -> V_12 , L_4 , V_13 , V_4 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_2 V_4 ;
F_1 ( V_2 , V_18 ,
V_24 | V_31 ) ;
V_4 = F_4 ( V_2 , V_26 ) ;
if ( V_4 != V_27 ) {
F_17 ( V_2 -> V_12 , L_5 , V_13 , V_4 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_32 ,
const T_2 * V_4 , int V_33 )
{
int V_11 , V_20 ;
T_2 V_5 ;
V_20 = F_16 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_2 , V_34 , V_32 << 1 ) ;
F_1 ( V_2 , V_18 , V_24 ) ;
V_20 = F_14 ( V_2 ) ;
if ( V_20 )
return V_20 ;
for ( V_11 = 0 ; V_11 < V_33 ; V_11 ++ ) {
V_5 = F_4 ( V_2 , V_26 ) ;
if ( ( V_5 != V_35 ) && ( V_5 != V_36 ) ) {
F_17 ( V_2 -> V_12 ,
L_6 ,
V_13 , V_5 ) ;
return - V_30 ;
}
F_1 ( V_2 , V_34 , V_4 [ V_11 ] ) ;
F_1 ( V_2 , V_18 , V_24 ) ;
V_20 = F_14 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_32 ,
T_2 * V_4 , int V_33 )
{
int V_11 , V_20 ;
T_2 V_5 ;
if ( V_33 < 1 )
return - V_37 ;
V_20 = F_16 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_2 , V_34 , ( V_32 << 1 ) | 1 ) ;
F_1 ( V_2 , V_18 , V_24 ) ;
V_20 = F_14 ( V_2 ) ;
if ( V_20 )
return V_20 ;
for ( V_11 = 0 ; V_11 < V_33 ; V_11 ++ ) {
V_5 = F_4 ( V_2 , V_26 ) ;
if ( ( V_5 != V_38 ) && ( V_5 != V_39 ) ) {
F_17 ( V_2 -> V_12 ,
L_7 ,
V_13 , V_5 ) ;
return - V_30 ;
}
if ( V_11 + 1 < V_33 )
F_1 ( V_2 , V_18 ,
V_24 | V_40 ) ;
else
F_1 ( V_2 , V_18 ,
V_24 ) ;
V_20 = F_14 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_4 [ V_11 ] = F_4 ( V_2 , V_34 ) ;
}
return 0 ;
}
static int F_21 ( struct V_41 * V_21 ,
struct V_42 * V_43 ,
int V_44 )
{
struct V_42 * V_45 ;
int V_11 ;
int V_46 = 0 ;
struct V_1 * V_2 = F_22 ( V_21 ) ;
for ( V_11 = 0 ; V_46 == 0 && V_11 < V_44 ; V_11 ++ ) {
V_45 = & V_43 [ V_11 ] ;
F_9 ( V_2 -> V_12 ,
L_8 ,
V_45 -> V_47 & V_48 ? L_9 : L_10 ,
V_45 -> V_49 , V_45 -> V_50 , V_11 + 1 , V_44 ) ;
if ( V_45 -> V_47 & V_48 )
V_46 = F_20 ( V_2 , V_45 -> V_50 , V_45 -> V_51 ,
V_45 -> V_49 ) ;
else
V_46 = F_19 ( V_2 , V_45 -> V_50 , V_45 -> V_51 ,
V_45 -> V_49 ) ;
}
F_18 ( V_2 ) ;
return ( V_46 != 0 ) ? V_46 : V_44 ;
}
static T_4 F_23 ( struct V_41 * V_21 )
{
return V_52 | V_53 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_54 , V_55 , V_56 , V_57 , V_58 , V_59 , V_60 , V_61 ;
int V_62 = 0x18 , V_63 = 2 , V_64 = 0 , V_65 = 1000000 ;
for ( V_59 = 0 ; V_59 < 8 && V_65 != 0 ; V_59 ++ ) {
for ( V_58 = 15 ; V_58 >= 2 && V_65 != 0 ; V_58 -- ) {
V_54 = V_2 -> V_66 * ( V_58 + 1 ) * 10 ;
V_54 *= ( 1 << V_59 ) ;
V_55 = ( V_2 -> V_67 / ( V_54 * 2 ) ) - 1 ;
for ( V_56 = 0 ; V_56 <= 1 ; V_56 ++ ) {
V_57 = V_55 + V_56 ;
if ( V_57 < 5 || V_57 > 0xff )
continue;
V_60 = V_2 -> V_67 / ( 2 * ( V_57 + 1 ) ) ;
V_60 = V_60 / ( 1 << V_59 ) ;
V_60 = V_60 / ( V_58 + 1 ) / 10 ;
V_61 = abs ( V_60 - V_2 -> V_66 ) ;
if ( V_61 < V_65 ) {
V_65 = V_61 ;
V_62 = V_57 ;
V_63 = V_58 ;
V_64 = V_59 ;
}
}
}
}
F_1 ( V_2 , V_68 , V_62 ) ;
F_1 ( V_2 , V_69 , ( V_63 << 3 ) | V_64 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_70 ;
int V_71 ;
F_1 ( V_2 , V_18 , V_24 ) ;
F_1 ( V_2 , V_72 , 0 ) ;
for ( V_71 = 10 ; V_71 ; V_71 -- ) {
F_10 ( 1 ) ;
V_70 = F_4 ( V_2 , V_26 ) ;
if ( V_70 == V_27 )
return 0 ;
}
F_17 ( V_2 -> V_12 , L_11 , V_13 , V_70 ) ;
return - V_30 ;
}
static int F_26 ( struct V_73 * V_74 )
{
int V_14 , V_20 = 0 ;
struct V_1 * V_2 ;
struct V_75 * V_76 ;
V_14 = F_27 ( V_74 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_2 = F_28 ( & V_74 -> V_12 , sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 ) {
F_17 ( & V_74 -> V_12 , L_12 ) ;
V_20 = - V_78 ;
goto V_79;
}
V_2 -> V_12 = & V_74 -> V_12 ;
V_76 = F_29 ( V_74 , V_80 , 0 ) ;
if ( V_76 == NULL ) {
F_17 ( V_2 -> V_12 , L_13 ) ;
V_20 = - V_81 ;
goto V_79;
}
V_2 -> V_82 = V_76 -> V_83 ;
V_2 -> V_84 = F_30 ( V_76 ) ;
if ( F_31 ( V_74 -> V_12 . V_85 ,
L_14 , & V_2 -> V_66 ) &&
F_31 ( V_74 -> V_12 . V_85 ,
L_15 , & V_2 -> V_66 ) ) {
F_17 ( V_2 -> V_12 ,
L_16 ) ;
V_20 = - V_81 ;
goto V_79;
}
V_2 -> V_67 = F_32 () ;
if ( ! F_33 ( & V_74 -> V_12 , V_2 -> V_82 , V_2 -> V_84 ,
V_76 -> V_86 ) ) {
F_17 ( V_2 -> V_12 , L_17 ) ;
goto V_79;
}
V_2 -> V_7 = F_34 ( & V_74 -> V_12 , V_2 -> V_82 , V_2 -> V_84 ) ;
F_35 ( & V_2 -> V_16 ) ;
V_2 -> V_14 = V_14 ;
V_20 = F_36 ( & V_74 -> V_12 , V_2 -> V_14 ,
F_11 , 0 , V_87 , V_2 ) ;
if ( V_20 < 0 ) {
F_17 ( V_2 -> V_12 , L_18 ) ;
goto V_79;
}
V_20 = F_25 ( V_2 ) ;
if ( V_20 ) {
F_17 ( V_2 -> V_12 , L_19 ) ;
goto V_79;
}
V_20 = F_24 ( V_2 ) ;
if ( V_20 ) {
F_17 ( V_2 -> V_12 , L_20 ) ;
goto V_79;
}
V_2 -> V_21 = V_88 ;
V_2 -> V_21 . V_12 . V_89 = & V_74 -> V_12 ;
V_2 -> V_21 . V_12 . V_85 = V_74 -> V_12 . V_85 ;
F_37 ( & V_2 -> V_21 , V_2 ) ;
F_38 ( V_74 , V_2 ) ;
V_20 = F_39 ( & V_2 -> V_21 ) ;
if ( V_20 < 0 ) {
F_17 ( V_2 -> V_12 , L_21 ) ;
goto V_90;
}
F_40 ( V_2 -> V_12 , L_22 , V_91 ) ;
F_41 ( & V_2 -> V_21 ) ;
return 0 ;
V_90:
F_38 ( V_74 , NULL ) ;
V_79:
return V_20 ;
}
static int F_42 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_43 ( V_74 ) ;
F_44 ( & V_2 -> V_21 ) ;
F_38 ( V_74 , NULL ) ;
return 0 ;
}
