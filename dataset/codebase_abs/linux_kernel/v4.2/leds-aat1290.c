static struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , int V_5 , int V_6 )
{
int V_7 ;
F_4 ( V_4 -> V_8 , 0 ) ;
F_4 ( V_4 -> V_9 , 0 ) ;
F_5 ( V_10 ) ;
for ( V_7 = 0 ; V_7 < V_5 ; ++ V_7 ) {
F_5 ( V_11 ) ;
F_4 ( V_4 -> V_9 , 0 ) ;
F_5 ( V_11 ) ;
F_4 ( V_4 -> V_9 , 1 ) ;
}
F_6 ( V_12 , V_13 ) ;
for ( V_7 = 0 ; V_7 < V_6 ; ++ V_7 ) {
F_5 ( V_11 ) ;
F_4 ( V_4 -> V_9 , 0 ) ;
F_5 ( V_11 ) ;
F_4 ( V_4 -> V_9 , 1 ) ;
}
F_6 ( V_12 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_4 ,
unsigned int V_14 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_15 * V_16 = & V_3 -> V_17 ;
int V_18 = V_19 -
( V_14 / V_16 -> V_20 ) + 1 ;
F_3 ( V_4 , V_21 ,
V_18 ) ;
}
static void F_8 ( struct V_1 * V_4 ,
enum V_22 V_23 )
{
F_9 ( & V_4 -> V_24 ) ;
if ( V_23 == 0 ) {
F_4 ( V_4 -> V_8 , 0 ) ;
F_4 ( V_4 -> V_9 , 0 ) ;
V_4 -> V_25 = false ;
} else {
if ( ! V_4 -> V_25 ) {
F_3 ( V_4 ,
V_26 ,
V_27 ) ;
V_4 -> V_25 = true ;
}
F_3 ( V_4 , V_28 ,
V_29 - V_23 ) ;
F_3 ( V_4 , V_30 ,
V_31 ) ;
}
F_10 ( & V_4 -> V_24 ) ;
}
static void F_11 ( struct V_32 * V_33 )
{
struct V_1 * V_4 =
F_2 ( V_33 , struct V_1 , V_34 ) ;
F_8 ( V_4 , V_4 -> V_35 ) ;
}
static void F_12 ( struct V_36 * V_37 ,
enum V_22 V_23 )
{
struct V_2 * V_3 = F_13 ( V_37 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_35 = V_23 ;
F_14 ( & V_4 -> V_34 ) ;
}
static int F_15 ( struct V_36 * V_37 ,
enum V_22 V_23 )
{
struct V_2 * V_3 = F_13 ( V_37 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_8 ( V_4 , V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
bool V_38 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_36 * V_37 = & V_3 -> V_37 ;
struct V_15 * V_17 = & V_3 -> V_17 ;
F_9 ( & V_4 -> V_24 ) ;
if ( V_38 ) {
F_7 ( V_4 , V_17 -> V_39 ) ;
F_4 ( V_4 -> V_8 , 1 ) ;
} else {
F_4 ( V_4 -> V_8 , 0 ) ;
F_4 ( V_4 -> V_9 , 0 ) ;
}
V_37 -> V_23 = 0 ;
V_4 -> V_25 = false ;
F_10 ( & V_4 -> V_24 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
T_1 V_17 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_4 ,
struct V_40 * V_41 ,
struct V_42 * * V_43 )
{
struct V_36 * V_37 = & V_4 -> V_3 . V_37 ;
struct V_44 * V_45 = & V_4 -> V_46 -> V_45 ;
struct V_42 * V_47 ;
#if F_19 ( V_48 )
struct V_49 * V_49 ;
#endif
int V_50 = 0 ;
V_4 -> V_8 = F_20 ( V_45 , L_1 , V_51 ) ;
if ( F_21 ( V_4 -> V_8 ) ) {
V_50 = F_22 ( V_4 -> V_8 ) ;
F_23 ( V_45 , L_2 ) ;
return V_50 ;
}
V_4 -> V_9 = F_20 ( V_45 , L_3 , V_51 ) ;
if ( F_21 ( V_4 -> V_9 ) ) {
V_50 = F_22 ( V_4 -> V_9 ) ;
F_23 ( V_45 , L_4 ) ;
return V_50 ;
}
#if F_19 ( V_48 )
V_49 = F_24 ( & V_4 -> V_46 -> V_45 ) ;
if ( F_21 ( V_49 ) ) {
V_41 -> V_52 = false ;
F_25 ( V_45 ,
L_5 ) ;
} else {
V_41 -> V_52 = true ;
}
#endif
V_47 = F_26 ( V_45 -> V_53 , NULL ) ;
if ( ! V_47 ) {
F_23 ( V_45 , L_6 ) ;
return - V_54 ;
}
V_37 -> V_55 = F_27 ( V_47 , L_7 , NULL ) ? :
V_47 -> V_55 ;
V_50 = F_28 ( V_47 , L_8 ,
& V_41 -> V_56 ) ;
if ( V_50 < 0 )
F_29 ( V_45 ,
L_9 ) ;
V_50 = F_28 ( V_47 , L_10 ,
& V_41 -> V_57 ) ;
if ( V_50 < 0 ) {
F_23 ( V_45 ,
L_11 ) ;
return V_50 ;
}
V_50 = F_28 ( V_47 , L_12 ,
& V_41 -> V_58 ) ;
if ( V_50 < 0 ) {
F_23 ( V_45 ,
L_13 ) ;
return V_50 ;
}
F_30 ( V_47 ) ;
* V_43 = V_47 ;
return V_50 ;
}
static void F_31 ( struct V_1 * V_4 ,
struct V_40 * V_41 )
{
int V_7 , V_59 = 0 , V_60 = V_61 ;
while ( V_60 - V_59 > 1 ) {
V_7 = V_59 + ( V_60 - V_59 ) / 2 ;
if ( V_41 -> V_56 < V_4 -> V_62 [ V_7 ] )
V_60 = V_7 ;
else
V_59 = V_7 ;
}
V_41 -> V_56 = V_4 -> V_62 [ V_59 ] ;
V_41 -> V_63 = V_59 + 1 ;
}
int F_32 ( struct V_1 * V_4 ,
struct V_40 * V_41 )
{
int V_64 [] = { 20 , 22 , 25 , 28 , 32 , 36 , 40 , 45 , 50 , 56 ,
63 , 71 , 79 , 89 , 100 } ;
int V_7 , V_56 =
F_33 ( V_41 -> V_57 ) ;
V_4 -> V_62 = F_34 ( & V_4 -> V_46 -> V_45 ,
sizeof( V_64 ) ,
V_65 ) ;
if ( ! V_4 -> V_62 )
return - V_66 ;
for ( V_7 = 0 ; V_7 < V_61 ; ++ V_7 )
V_4 -> V_62 [ V_7 ] = V_56 *
V_64 [ V_7 ] / 100 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_4 ,
struct V_40 * V_41 ,
struct V_42 * * V_43 )
{
int V_50 ;
V_50 = F_18 ( V_4 , V_41 , V_43 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_32 ( V_4 , V_41 ) ;
if ( V_50 < 0 )
return V_50 ;
F_31 ( V_4 , V_41 ) ;
#if F_19 ( V_48 )
#else
F_36 ( & V_4 -> V_46 -> V_45 , V_4 -> V_62 ) ;
#endif
return 0 ;
}
static void F_37 ( struct V_1 * V_4 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_15 * V_67 ;
V_67 = & V_3 -> V_17 ;
V_67 -> V_68 = V_41 -> V_58 / V_19 ;
V_67 -> V_69 = V_41 -> V_58 ;
V_67 -> V_20 = V_67 -> V_68 ;
V_67 -> V_39 = V_67 -> V_69 ;
}
static enum V_22 F_38 (
struct V_70 * V_70 ,
T_2 V_71 )
{
struct V_2 * V_3 = V_70 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
for ( V_7 = V_61 - 1 ; V_7 >= 0 ; -- V_7 )
if ( V_71 >= V_4 -> V_62 [ V_7 ] )
return V_7 + 1 ;
return 1 ;
}
static T_2 F_39 ( struct V_70 * V_70 ,
enum V_22 V_23 )
{
struct V_2 * V_3 = V_70 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return V_4 -> V_62 [ V_23 - 1 ] ;
}
static int F_40 ( struct V_70 * V_70 ,
bool V_72 )
{
struct V_1 * V_4 = F_1 ( V_70 -> V_3 ) ;
struct V_2 * V_3 = V_70 -> V_3 ;
struct V_36 * V_37 = & V_3 -> V_37 ;
struct V_49 * V_49 ;
F_4 ( V_4 -> V_8 , 0 ) ;
F_4 ( V_4 -> V_9 , 0 ) ;
V_4 -> V_25 = false ;
V_37 -> V_23 = 0 ;
V_49 = F_41 ( & V_4 -> V_46 -> V_45 ,
V_72 ? L_14 : L_15 ) ;
if ( F_21 ( V_49 ) ) {
F_29 ( & V_4 -> V_46 -> V_45 , L_16 ) ;
return F_22 ( V_49 ) ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_4 ,
struct V_40 * V_73 ,
struct V_74 * V_75 )
{
struct V_36 * V_37 = & V_4 -> V_3 . V_37 ;
struct V_15 * V_76 ;
F_43 ( V_75 -> V_77 , V_37 -> V_55 ,
sizeof( V_75 -> V_77 ) ) ;
V_76 = & V_75 -> V_78 ;
V_76 -> V_68 = V_4 -> V_62 [ 0 ] ;
V_76 -> V_69 = V_73 -> V_56 ;
V_76 -> V_20 = 1 ;
V_76 -> V_39 = V_76 -> V_69 ;
V_75 -> V_52 = V_73 -> V_52 ;
}
static inline void F_42 ( struct V_1 * V_4 ,
struct V_40 * V_73 ,
struct V_74 * V_75 )
{
}
static int F_44 ( struct V_79 * V_46 )
{
struct V_44 * V_45 = & V_46 -> V_45 ;
struct V_42 * V_43 = NULL ;
struct V_1 * V_4 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
struct V_40 V_73 = {} ;
struct V_74 V_75 = {} ;
int V_50 ;
V_4 = F_34 ( V_45 , sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 )
return - V_66 ;
V_4 -> V_46 = V_46 ;
F_45 ( V_46 , V_4 ) ;
V_3 = & V_4 -> V_3 ;
V_3 -> V_80 = & V_81 ;
V_37 = & V_3 -> V_37 ;
V_50 = F_35 ( V_4 , & V_73 , & V_43 ) ;
if ( V_50 < 0 )
return V_50 ;
F_46 ( & V_4 -> V_24 ) ;
V_37 -> V_82 = F_12 ;
V_37 -> V_83 = F_15 ;
V_37 -> V_63 = V_73 . V_63 ;
V_37 -> V_84 |= V_85 ;
F_47 ( & V_4 -> V_34 , F_11 ) ;
F_37 ( V_4 , & V_73 ) ;
V_50 = F_48 ( & V_46 -> V_45 , V_3 ) ;
if ( V_50 < 0 )
goto V_86;
F_42 ( V_4 , & V_73 , & V_75 ) ;
V_4 -> V_70 = F_49 ( V_45 , V_43 , V_3 , NULL ,
& V_87 , & V_75 ) ;
if ( F_21 ( V_4 -> V_70 ) ) {
V_50 = F_22 ( V_4 -> V_70 ) ;
goto V_88;
}
return 0 ;
V_88:
F_50 ( V_3 ) ;
V_86:
F_51 ( & V_4 -> V_24 ) ;
return V_50 ;
}
static int F_52 ( struct V_79 * V_46 )
{
struct V_1 * V_4 = F_53 ( V_46 ) ;
F_54 ( V_4 -> V_70 ) ;
F_50 ( & V_4 -> V_3 ) ;
F_55 ( & V_4 -> V_34 ) ;
F_51 ( & V_4 -> V_24 ) ;
return 0 ;
}
