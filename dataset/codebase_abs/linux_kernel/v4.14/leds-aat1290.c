static struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_2 * F_3 (
struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_2 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_6 , int V_7 , int V_8 )
{
int V_9 ;
F_5 ( V_6 -> V_10 , 0 ) ;
F_5 ( V_6 -> V_11 , 0 ) ;
F_6 ( V_12 ) ;
for ( V_9 = 0 ; V_9 < V_7 ; ++ V_9 ) {
F_6 ( V_13 ) ;
F_5 ( V_6 -> V_11 , 0 ) ;
F_6 ( V_13 ) ;
F_5 ( V_6 -> V_11 , 1 ) ;
}
F_7 ( V_14 , V_15 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
F_6 ( V_13 ) ;
F_5 ( V_6 -> V_11 , 0 ) ;
F_6 ( V_13 ) ;
F_5 ( V_6 -> V_11 , 1 ) ;
}
F_7 ( V_14 , V_15 ) ;
}
static void F_8 ( struct V_1 * V_6 ,
unsigned int V_16 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_17 * V_18 = & V_3 -> V_19 ;
int V_20 = V_21 -
( V_16 / V_18 -> V_22 ) + 1 ;
F_4 ( V_6 , V_23 ,
V_20 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
enum V_24 V_25 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_10 ( & V_6 -> V_26 ) ;
if ( V_25 == 0 ) {
F_5 ( V_6 -> V_10 , 0 ) ;
F_5 ( V_6 -> V_11 , 0 ) ;
V_6 -> V_27 = false ;
} else {
if ( ! V_6 -> V_27 ) {
F_4 ( V_6 ,
V_28 ,
V_29 ) ;
V_6 -> V_27 = true ;
}
F_4 ( V_6 , V_30 ,
V_31 - V_25 ) ;
F_4 ( V_6 , V_32 ,
V_33 ) ;
}
F_11 ( & V_6 -> V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 ,
bool V_34 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_17 * V_19 = & V_3 -> V_19 ;
F_10 ( & V_6 -> V_26 ) ;
if ( V_34 ) {
F_8 ( V_6 , V_19 -> V_35 ) ;
F_5 ( V_6 -> V_10 , 1 ) ;
} else {
F_5 ( V_6 -> V_10 , 0 ) ;
F_5 ( V_6 -> V_11 , 0 ) ;
}
V_5 -> V_25 = 0 ;
V_6 -> V_27 = false ;
F_11 ( & V_6 -> V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
T_1 V_19 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_6 ,
struct V_36 * V_37 ,
struct V_38 * * V_39 )
{
struct V_4 * V_5 = & V_6 -> V_3 . V_5 ;
struct V_40 * V_41 = & V_6 -> V_42 -> V_41 ;
struct V_38 * V_43 ;
#if F_15 ( V_44 )
struct V_45 * V_45 ;
#endif
int V_46 = 0 ;
V_6 -> V_10 = F_16 ( V_41 , L_1 , V_47 ) ;
if ( F_17 ( V_6 -> V_10 ) ) {
V_46 = F_18 ( V_6 -> V_10 ) ;
F_19 ( V_41 , L_2 ) ;
return V_46 ;
}
V_6 -> V_11 = F_16 ( V_41 , L_3 , V_47 ) ;
if ( F_17 ( V_6 -> V_11 ) ) {
V_46 = F_18 ( V_6 -> V_11 ) ;
F_19 ( V_41 , L_4 ) ;
return V_46 ;
}
#if F_15 ( V_44 )
V_45 = F_20 ( & V_6 -> V_42 -> V_41 ) ;
if ( F_17 ( V_45 ) ) {
V_37 -> V_48 = false ;
F_21 ( V_41 ,
L_5 ) ;
} else {
V_37 -> V_48 = true ;
}
#endif
V_43 = F_22 ( V_41 -> V_49 , NULL ) ;
if ( ! V_43 ) {
F_19 ( V_41 , L_6 ) ;
return - V_50 ;
}
V_5 -> V_51 = F_23 ( V_43 , L_7 , NULL ) ? :
V_43 -> V_51 ;
V_46 = F_24 ( V_43 , L_8 ,
& V_37 -> V_52 ) ;
if ( V_46 < 0 )
F_25 ( V_41 ,
L_9 ) ;
V_46 = F_24 ( V_43 , L_10 ,
& V_37 -> V_53 ) ;
if ( V_46 < 0 ) {
F_19 ( V_41 ,
L_11 ) ;
goto V_54;
}
V_46 = F_24 ( V_43 , L_12 ,
& V_37 -> V_55 ) ;
if ( V_46 < 0 ) {
F_19 ( V_41 ,
L_13 ) ;
goto V_54;
}
* V_39 = V_43 ;
V_54:
F_26 ( V_43 ) ;
return V_46 ;
}
static void F_27 ( struct V_1 * V_6 ,
struct V_36 * V_37 )
{
int V_9 , V_56 = 0 , V_57 = V_58 ;
while ( V_57 - V_56 > 1 ) {
V_9 = V_56 + ( V_57 - V_56 ) / 2 ;
if ( V_37 -> V_52 < V_6 -> V_59 [ V_9 ] )
V_57 = V_9 ;
else
V_56 = V_9 ;
}
V_37 -> V_52 = V_6 -> V_59 [ V_56 ] ;
V_37 -> V_60 = V_56 + 1 ;
}
static int F_28 ( struct V_1 * V_6 ,
struct V_36 * V_37 )
{
static const int V_61 [] = {
20 , 22 , 25 , 28 , 32 , 36 , 40 , 45 , 50 , 56 ,
63 , 71 , 79 , 89 , 100
} ;
int V_9 , V_52 =
F_29 ( V_37 -> V_53 ) ;
V_6 -> V_59 = F_30 ( & V_6 -> V_42 -> V_41 ,
sizeof( V_61 ) ,
V_62 ) ;
if ( ! V_6 -> V_59 )
return - V_63 ;
for ( V_9 = 0 ; V_9 < V_58 ; ++ V_9 )
V_6 -> V_59 [ V_9 ] = V_52 *
V_61 [ V_9 ] / 100 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_6 ,
struct V_36 * V_37 ,
struct V_38 * * V_39 )
{
int V_46 ;
V_46 = F_14 ( V_6 , V_37 , V_39 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_28 ( V_6 , V_37 ) ;
if ( V_46 < 0 )
return V_46 ;
F_27 ( V_6 , V_37 ) ;
#if F_15 ( V_44 )
#else
F_32 ( & V_6 -> V_42 -> V_41 , V_6 -> V_59 ) ;
#endif
return 0 ;
}
static void F_33 ( struct V_1 * V_6 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_17 * V_64 ;
V_64 = & V_3 -> V_19 ;
V_64 -> V_65 = V_37 -> V_55 / V_21 ;
V_64 -> V_66 = V_37 -> V_55 ;
V_64 -> V_22 = V_64 -> V_65 ;
V_64 -> V_35 = V_64 -> V_66 ;
}
static enum V_24 F_34 (
struct V_67 * V_67 ,
T_2 V_68 )
{
struct V_2 * V_3 = V_67 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_9 ;
for ( V_9 = V_58 - 1 ; V_9 >= 0 ; -- V_9 )
if ( V_68 >= V_6 -> V_59 [ V_9 ] )
return V_9 + 1 ;
return 1 ;
}
static T_2 F_35 ( struct V_67 * V_67 ,
enum V_24 V_25 )
{
struct V_2 * V_3 = V_67 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
return V_6 -> V_59 [ V_25 - 1 ] ;
}
static int F_36 ( struct V_67 * V_67 ,
bool V_69 )
{
struct V_1 * V_6 = F_1 ( V_67 -> V_3 ) ;
struct V_2 * V_3 = V_67 -> V_3 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_45 * V_45 ;
F_5 ( V_6 -> V_10 , 0 ) ;
F_5 ( V_6 -> V_11 , 0 ) ;
V_6 -> V_27 = false ;
V_5 -> V_25 = 0 ;
V_45 = F_37 ( & V_6 -> V_42 -> V_41 ,
V_69 ? L_14 : L_15 ) ;
if ( F_17 ( V_45 ) ) {
F_25 ( & V_6 -> V_42 -> V_41 , L_16 ) ;
return F_18 ( V_45 ) ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_6 ,
struct V_36 * V_70 ,
struct V_71 * V_72 )
{
struct V_4 * V_5 = & V_6 -> V_3 . V_5 ;
struct V_17 * V_73 ;
F_39 ( V_72 -> V_74 , V_5 -> V_51 ,
sizeof( V_72 -> V_74 ) ) ;
V_73 = & V_72 -> V_68 ;
V_73 -> V_65 = V_6 -> V_59 [ 0 ] ;
V_73 -> V_66 = V_70 -> V_52 ;
V_73 -> V_22 = 1 ;
V_73 -> V_35 = V_73 -> V_66 ;
V_72 -> V_48 = V_70 -> V_48 ;
}
static inline void F_38 ( struct V_1 * V_6 ,
struct V_36 * V_70 ,
struct V_71 * V_72 )
{
}
static int F_40 ( struct V_75 * V_42 )
{
struct V_40 * V_41 = & V_42 -> V_41 ;
struct V_38 * V_39 = NULL ;
struct V_1 * V_6 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
struct V_36 V_70 = {} ;
struct V_71 V_72 = {} ;
int V_46 ;
V_6 = F_30 ( V_41 , sizeof( * V_6 ) , V_62 ) ;
if ( ! V_6 )
return - V_63 ;
V_6 -> V_42 = V_42 ;
F_41 ( V_42 , V_6 ) ;
V_3 = & V_6 -> V_3 ;
V_3 -> V_76 = & V_77 ;
V_5 = & V_3 -> V_5 ;
V_46 = F_31 ( V_6 , & V_70 , & V_39 ) ;
if ( V_46 < 0 )
return V_46 ;
F_42 ( & V_6 -> V_26 ) ;
V_5 -> V_78 = F_9 ;
V_5 -> V_60 = V_70 . V_60 ;
V_5 -> V_79 |= V_80 ;
F_33 ( V_6 , & V_70 ) ;
V_46 = F_43 ( & V_42 -> V_41 , V_3 ) ;
if ( V_46 < 0 )
goto V_81;
F_38 ( V_6 , & V_70 , & V_72 ) ;
V_6 -> V_67 = F_44 ( V_41 , F_45 ( V_39 ) ,
V_3 , & V_82 ,
& V_72 ) ;
if ( F_17 ( V_6 -> V_67 ) ) {
V_46 = F_18 ( V_6 -> V_67 ) ;
goto V_83;
}
return 0 ;
V_83:
F_46 ( V_3 ) ;
V_81:
F_47 ( & V_6 -> V_26 ) ;
return V_46 ;
}
static int F_48 ( struct V_75 * V_42 )
{
struct V_1 * V_6 = F_49 ( V_42 ) ;
F_50 ( V_6 -> V_67 ) ;
F_46 ( & V_6 -> V_3 ) ;
F_47 ( & V_6 -> V_26 ) ;
return 0 ;
}
