static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
F_2 ( V_2 -> V_3 [ V_4 ] , ( V_3 >> V_4 ) & 1 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_7 ; V_4 ++ )
F_2 ( V_2 -> V_6 [ V_4 ] , ( V_6 >> V_4 ) & 1 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_8 , 0 ) ;
F_2 ( V_2 -> V_8 , 1 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
int V_3 , int V_9 )
{
unsigned long V_10 ;
F_6 ( & V_11 , V_10 ) ;
F_1 ( V_2 , V_3 ) ;
F_3 ( V_2 , V_9 ) ;
F_4 ( V_2 ) ;
F_7 ( & V_11 , V_10 ) ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
int V_14 ;
int V_15 ;
if ( F_9 ( ! V_2 ) )
return - V_16 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_5 ; V_15 ++ ) {
V_14 = F_10 ( & V_13 -> V_17 , V_2 -> V_3 [ V_15 ] ,
V_18 ,
L_1 ) ;
if ( V_14 )
return V_14 ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_7 ; V_15 ++ ) {
V_14 = F_10 ( & V_13 -> V_17 , V_2 -> V_6 [ V_15 ] ,
V_18 ,
L_2 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_10 ( & V_13 -> V_17 , V_2 -> V_8 ,
V_18 ,
L_3 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_11 ( enum V_19 * V_20 ,
unsigned long V_21 ,
unsigned long V_22 ,
struct V_23 * V_24 ,
int V_25 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ ) {
if ( V_24 [ V_15 ] . V_21 == V_21 &&
V_24 [ V_15 ] . V_22 == V_22 ) {
* V_20 = V_24 [ V_15 ] . V_20 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_12 ( struct V_26 * V_27 ,
unsigned long * V_21 ,
unsigned long * V_22 )
{
struct V_28 * V_29 =
F_13 ( V_27 , struct V_28 , V_30 ) ;
enum V_19 V_20 ;
int V_31 ;
int V_32 ;
V_32 = F_11 ( & V_20 , * V_21 , * V_22 ,
V_29 -> V_24 , V_29 -> V_25 ) ;
if ( V_32 < 0 )
return V_32 ;
V_31 = V_29 -> V_31 [ V_20 ] ;
if ( V_31 == V_33 )
return - V_16 ;
F_14 ( & V_29 -> V_34 ) ;
F_5 ( V_29 -> V_2 , V_29 -> V_35 , V_31 ) ;
V_29 -> V_20 = V_20 ;
F_15 ( & V_29 -> V_34 ) ;
return 0 ;
}
static void F_16 ( struct V_26 * V_27 ,
enum V_36 V_9 )
{
struct V_28 * V_29 =
F_13 ( V_27 , struct V_28 , V_30 ) ;
enum V_19 V_20 ;
int V_31 ;
int V_37 = 1 ;
unsigned long V_10 ;
F_6 ( & V_29 -> V_34 , V_10 ) ;
if ( V_9 == V_38 ) {
V_20 = V_39 ;
V_37 = 0 ;
} else {
if ( V_29 -> V_40 )
V_20 = V_41 ;
else if ( V_29 -> V_20 == V_39 )
V_20 = V_42 ;
else
V_20 = V_29 -> V_20 ;
}
V_31 = V_29 -> V_31 [ V_20 ] ;
F_5 ( V_29 -> V_2 , V_29 -> V_35 , V_31 ) ;
V_29 -> V_20 = V_20 ;
if ( V_37 )
F_5 ( V_29 -> V_2 ,
V_29 -> V_43 , V_9 ) ;
F_7 ( & V_29 -> V_34 , V_10 ) ;
}
static T_1 F_17 ( struct V_44 * V_17 ,
struct V_45 * V_46 ,
const char * V_47 , T_2 V_48 )
{
struct V_26 * V_27 = F_18 ( V_17 ) ;
struct V_28 * V_29 =
F_13 ( V_27 , struct V_28 , V_30 ) ;
unsigned long V_8 ;
enum V_19 V_20 ;
int V_31 ;
int V_32 ;
V_32 = F_19 ( V_47 , 10 , & V_8 ) ;
if ( V_32 < 0 )
return V_32 ;
V_8 = ! ! V_8 ;
F_14 ( & V_29 -> V_34 ) ;
if ( V_29 -> V_40 == V_8 ) {
V_32 = V_48 ;
goto V_49;
}
if ( V_29 -> V_20 != V_42 &&
V_29 -> V_20 != V_41 )
V_20 = V_29 -> V_20 ;
else if ( V_8 )
V_20 = V_41 ;
else
V_20 = V_42 ;
V_31 = V_29 -> V_31 [ V_20 ] ;
if ( V_31 == V_33 ) {
V_32 = - V_16 ;
goto V_49;
}
F_5 ( V_29 -> V_2 , V_29 -> V_35 , V_31 ) ;
V_29 -> V_20 = V_20 ;
V_29 -> V_40 = V_8 ;
V_32 = V_48 ;
V_49:
F_15 ( & V_29 -> V_34 ) ;
return V_32 ;
}
static T_1 F_20 ( struct V_44 * V_17 ,
struct V_45 * V_46 , char * V_50 )
{
struct V_26 * V_27 = F_18 ( V_17 ) ;
struct V_28 * V_29 =
F_13 ( V_27 , struct V_28 , V_30 ) ;
return sprintf ( V_50 , L_4 , V_29 -> V_40 ) ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_51 * V_52 ,
struct V_28 * V_29 ,
const struct V_53 * V_54 )
{
F_22 ( & V_29 -> V_34 ) ;
V_29 -> V_2 = V_52 -> V_2 ;
V_29 -> V_30 . V_55 = V_54 -> V_55 ;
V_29 -> V_30 . V_56 = V_54 -> V_56 ;
V_29 -> V_30 . V_57 = F_12 ;
V_29 -> V_30 . V_58 = F_16 ;
V_29 -> V_40 = 0 ;
V_29 -> V_30 . V_59 = V_38 ;
V_29 -> V_30 . V_60 = V_54 -> V_61 ;
V_29 -> V_30 . V_10 |= V_62 ;
V_29 -> V_35 = V_54 -> V_35 ;
V_29 -> V_31 = V_54 -> V_31 ;
V_29 -> V_43 = V_54 -> V_43 ;
V_29 -> V_24 = V_52 -> V_24 ;
V_29 -> V_25 = V_52 -> V_25 ;
if ( V_29 -> V_31 [ V_41 ] != V_33 )
V_29 -> V_30 . V_63 = V_64 ;
return F_23 ( & V_13 -> V_17 , & V_29 -> V_30 ) ;
}
static int F_24 ( struct V_44 * V_17 , struct V_65 * V_66 ,
struct V_1 * V_2 )
{
int * V_3 , * V_6 ;
int V_5 , V_7 ;
int V_32 ;
int V_15 ;
V_32 = F_25 ( V_66 , L_5 ) ;
if ( V_32 < 0 ) {
F_26 ( V_17 ,
L_6 ) ;
return V_32 ;
}
V_5 = V_32 ;
V_3 = F_27 ( V_17 , V_5 * sizeof( * V_3 ) , V_67 ) ;
if ( ! V_3 )
return - V_68 ;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ ) {
V_32 = F_28 ( V_66 , L_5 , V_15 ) ;
if ( V_32 < 0 )
return V_32 ;
V_3 [ V_15 ] = V_32 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
V_32 = F_25 ( V_66 , L_7 ) ;
if ( V_32 < 0 ) {
F_26 ( V_17 ,
L_8 ) ;
return V_32 ;
}
V_7 = V_32 ;
V_6 = F_27 ( V_17 , V_7 * sizeof( * V_6 ) , V_67 ) ;
if ( ! V_6 )
return - V_68 ;
for ( V_15 = 0 ; V_15 < V_7 ; V_15 ++ ) {
V_32 = F_28 ( V_66 , L_7 , V_15 ) ;
if ( V_32 < 0 )
return V_32 ;
V_6 [ V_15 ] = V_32 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
V_32 = F_28 ( V_66 , L_9 , 0 ) ;
if ( V_32 < 0 ) {
F_26 ( V_17 ,
L_10 ) ;
return V_32 ;
}
V_2 -> V_8 = V_32 ;
return 0 ;
}
static int F_29 ( struct V_44 * V_17 ,
struct V_51 * V_52 )
{
struct V_65 * V_66 = V_17 -> V_69 ;
struct V_65 * V_70 ;
struct V_65 * V_71 ;
struct V_1 * V_2 ;
struct V_23 * V_72 ;
struct V_53 * V_73 , * V_74 ;
int V_75 ;
int V_76 = 0 ;
int V_32 ;
int V_15 ;
V_70 = F_30 ( V_66 , L_11 , 0 ) ;
if ( ! V_70 ) {
F_26 ( V_17 , L_12 ) ;
return - V_16 ;
}
V_2 = F_27 ( V_17 , sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
V_32 = F_24 ( V_17 , V_70 , V_2 ) ;
if ( V_32 )
return V_32 ;
F_31 ( V_70 ) ;
V_52 -> V_2 = V_2 ;
V_32 = F_32 ( V_66 , L_13 ) ;
if ( V_32 > 0 ) {
if ( V_32 % 3 )
return - V_16 ;
V_75 = V_32 / 3 ;
V_72 = F_27 ( V_17 , V_75 * sizeof( * V_72 ) ,
V_67 ) ;
if ( ! V_72 )
return - V_68 ;
for ( V_15 = 0 ; V_15 < V_75 ; V_15 ++ ) {
T_3 V_77 ;
F_33 ( V_66 , L_13 , 3 * V_15 ,
& V_72 [ V_15 ] . V_20 ) ;
if ( V_72 [ V_15 ] . V_20 >= V_78 )
return - V_16 ;
F_33 ( V_66 , L_13 ,
3 * V_15 + 1 , & V_77 ) ;
V_72 [ V_15 ] . V_21 = V_77 ;
F_33 ( V_66 , L_13 ,
3 * V_15 + 2 , & V_77 ) ;
V_72 [ V_15 ] . V_22 = V_77 ;
}
V_52 -> V_24 = V_72 ;
V_52 -> V_25 = V_75 ;
}
V_76 = F_34 ( V_66 ) ;
if ( ! V_76 ) {
F_26 ( V_17 , L_14 ) ;
return - V_79 ;
}
V_73 = F_27 ( V_17 , V_76 * sizeof( * V_73 ) , V_67 ) ;
if ( ! V_73 )
return - V_68 ;
V_74 = V_73 ;
F_35 (np, child) {
const char * string ;
int * V_31 ;
int V_80 ;
V_32 = F_36 ( V_71 , L_15 ,
& V_74 -> V_35 ) ;
if ( V_32 )
goto V_81;
V_32 = F_36 ( V_71 , L_16 ,
& V_74 -> V_43 ) ;
if ( V_32 )
goto V_81;
V_32 = F_36 ( V_71 , L_17 ,
& V_74 -> V_61 ) ;
if ( V_32 )
goto V_81;
V_31 =
F_27 ( V_17 ,
V_78 * sizeof( * V_31 ) ,
V_67 ) ;
if ( ! V_31 ) {
V_32 = - V_68 ;
goto V_81;
}
for ( V_15 = 0 ; V_15 < V_78 ; V_15 ++ )
V_31 [ V_15 ] = V_33 ;
V_32 = F_32 ( V_71 , L_18 ) ;
if ( V_32 < 0 || V_32 % 2 ) {
V_32 = - V_16 ;
goto V_81;
}
V_80 = V_32 / 2 ;
if ( V_80 > V_78 ) {
V_32 = - V_16 ;
goto V_81;
}
for ( V_15 = 0 ; V_15 < V_80 ; V_15 ++ ) {
int V_20 ;
int V_82 ;
F_33 ( V_71 ,
L_18 , 2 * V_15 , & V_20 ) ;
F_33 ( V_71 ,
L_18 , 2 * V_15 + 1 , & V_82 ) ;
if ( V_20 >= V_78 ) {
V_32 = - V_16 ;
goto V_81;
}
V_31 [ V_20 ] = V_82 ;
}
V_74 -> V_31 = V_31 ;
if ( ! F_37 ( V_71 , L_19 , & string ) )
V_74 -> V_55 = string ;
else
V_74 -> V_55 = V_71 -> V_55 ;
if ( ! F_37 ( V_71 ,
L_20 , & string ) )
V_74 -> V_56 = string ;
V_74 ++ ;
}
V_52 -> V_73 = V_73 ;
V_52 -> V_76 = V_76 ;
return 0 ;
V_81:
F_31 ( V_71 ) ;
return V_32 ;
}
static inline int
F_29 ( struct V_44 * V_17 ,
struct V_51 * V_52 )
{
return - V_79 ;
}
static int F_38 ( struct V_12 * V_13 )
{
struct V_51 * V_52 = F_39 ( & V_13 -> V_17 ) ;
struct V_28 * V_83 ;
int V_15 ;
int V_32 ;
if ( ! V_52 ) {
V_52 = F_27 ( & V_13 -> V_17 , sizeof( * V_52 ) , V_67 ) ;
if ( ! V_52 )
return - V_68 ;
V_32 = F_29 ( & V_13 -> V_17 , V_52 ) ;
if ( V_32 )
return V_32 ;
}
V_83 = F_27 ( & V_13 -> V_17 ,
V_52 -> V_76 * sizeof( * V_83 ) ,
V_67 ) ;
if ( ! V_83 )
return - V_68 ;
V_32 = F_8 ( V_13 , V_52 -> V_2 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_15 = 0 ; V_15 < V_52 -> V_76 ; V_15 ++ ) {
V_32 = F_21 ( V_13 , V_52 ,
& V_83 [ V_15 ] , & V_52 -> V_73 [ V_15 ] ) ;
if ( V_32 < 0 )
return V_32 ;
}
return 0 ;
}
