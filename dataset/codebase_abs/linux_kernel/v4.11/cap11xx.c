static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case F_2 ( 0 ) :
case F_2 ( 1 ) :
case F_2 ( 2 ) :
case F_2 ( 3 ) :
case F_2 ( 4 ) :
case F_2 ( 5 ) :
case V_6 :
case V_7 :
case V_8 :
return true ;
}
return false ;
}
static T_1 F_3 ( int V_9 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
unsigned int V_13 ;
int V_14 , V_15 ;
V_14 = F_4 ( V_12 -> V_16 , V_4 , 1 , 0 ) ;
if ( V_14 < 0 )
goto V_17;
V_14 = F_5 ( V_12 -> V_16 , V_5 , & V_13 ) ;
if ( V_14 < 0 )
goto V_17;
for ( V_15 = 0 ; V_15 < V_12 -> V_18 -> V_19 ; V_15 ++ )
F_6 ( V_12 -> V_18 , V_12 -> V_20 [ V_15 ] ,
V_13 & ( 1 << V_15 ) ) ;
F_7 ( V_12 -> V_18 ) ;
V_17:
return V_21 ;
}
static int F_8 ( struct V_11 * V_12 , bool V_22 )
{
if ( F_9 ( V_23 ) && V_12 -> V_24 )
return 0 ;
return F_4 ( V_12 -> V_16 , V_4 ,
V_25 ,
V_22 ? V_25 : 0 ) ;
}
static int F_10 ( struct V_26 * V_18 )
{
struct V_11 * V_12 = F_11 ( V_18 ) ;
return F_8 ( V_12 , false ) ;
}
static void F_12 ( struct V_26 * V_18 )
{
struct V_11 * V_12 = F_11 ( V_18 ) ;
F_8 ( V_12 , true ) ;
}
static void F_13 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_14 ( V_28 , struct V_29 , V_28 ) ;
struct V_11 * V_12 = V_30 -> V_12 ;
int V_31 = V_30 -> V_32 ;
F_4 ( V_12 -> V_16 , V_33 ,
F_15 ( V_30 -> V_3 ) , V_31 ? F_15 ( V_30 -> V_3 ) : 0 ) ;
}
static void F_16 ( struct V_34 * V_35 ,
enum V_36 V_31 )
{
struct V_29 * V_30 = F_14 ( V_35 , struct V_29 , V_35 ) ;
if ( V_30 -> V_32 == V_31 )
return;
V_30 -> V_32 = V_31 ;
F_17 ( & V_30 -> V_28 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_11 * V_12 , int V_24 )
{
struct V_37 * V_38 = V_2 -> V_39 , * V_40 ;
struct V_29 * V_30 ;
int V_41 = F_19 ( V_38 ) ;
int error ;
if ( ! V_24 || ! V_41 )
return 0 ;
if ( V_41 > V_24 )
return - V_42 ;
V_30 = F_20 ( V_2 , V_41 , sizeof( struct V_29 ) , V_43 ) ;
if ( ! V_30 )
return - V_44 ;
V_12 -> V_45 = V_30 ;
error = F_4 ( V_12 -> V_16 ,
V_33 , 0xff , 0 ) ;
if ( error )
return error ;
error = F_4 ( V_12 -> V_16 , V_46 ,
V_47 ,
V_48 <<
V_49 ) ;
if ( error )
return error ;
F_21 (node, child) {
T_2 V_3 ;
V_30 -> V_35 . V_50 =
F_22 ( V_40 , L_1 , NULL ) ? : V_40 -> V_50 ;
V_30 -> V_35 . V_51 =
F_22 ( V_40 , L_2 , NULL ) ;
V_30 -> V_35 . V_52 = 0 ;
V_30 -> V_35 . V_53 = F_16 ;
V_30 -> V_35 . V_54 = 1 ;
V_30 -> V_35 . V_55 = V_56 ;
error = F_23 ( V_40 , L_3 , & V_3 ) ;
if ( error != 0 || V_3 >= V_24 ) {
F_24 ( V_40 ) ;
return - V_42 ;
}
V_30 -> V_3 = V_3 ;
V_30 -> V_12 = V_12 ;
F_25 ( & V_30 -> V_28 , F_13 ) ;
error = F_26 ( V_2 , & V_30 -> V_35 ) ;
if ( error ) {
F_24 ( V_40 ) ;
return error ;
}
V_12 -> V_24 ++ ;
V_30 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_11 * V_12 , int V_24 )
{
return 0 ;
}
static int F_27 ( struct V_57 * V_57 ,
const struct V_58 * V_59 )
{
struct V_1 * V_2 = & V_57 -> V_2 ;
struct V_11 * V_12 ;
struct V_37 * V_38 ;
const struct V_60 * V_61 ;
int V_15 , error , V_62 , V_63 = 0 ;
unsigned int V_64 , V_65 ;
T_2 V_66 ;
if ( V_59 -> V_67 >= F_28 ( V_68 ) ) {
F_29 ( V_2 , L_4 , V_59 -> V_67 ) ;
return - V_42 ;
}
V_61 = & V_68 [ V_59 -> V_67 ] ;
if ( ! V_61 || ! V_61 -> V_69 ) {
F_29 ( V_2 , L_5 ) ;
return - V_42 ;
}
V_12 = F_30 ( V_2 ,
sizeof( * V_12 ) +
V_61 -> V_69 * sizeof( V_12 -> V_20 [ 0 ] ) ,
V_43 ) ;
if ( ! V_12 )
return - V_44 ;
V_12 -> V_16 = F_31 ( V_57 , & V_70 ) ;
if ( F_32 ( V_12 -> V_16 ) )
return F_33 ( V_12 -> V_16 ) ;
error = F_5 ( V_12 -> V_16 , V_6 , & V_64 ) ;
if ( error )
return error ;
if ( V_64 != V_61 -> V_71 ) {
F_29 ( V_2 , L_6 ,
V_64 , V_61 -> V_71 ) ;
return - V_72 ;
}
error = F_5 ( V_12 -> V_16 , V_7 , & V_64 ) ;
if ( error )
return error ;
if ( V_64 != V_73 ) {
F_29 ( V_2 , L_7 ,
V_64 , V_73 ) ;
return - V_72 ;
}
error = F_5 ( V_12 -> V_16 , V_8 , & V_65 ) ;
if ( error < 0 )
return error ;
F_34 ( V_2 , L_8 , V_65 ) ;
V_38 = V_2 -> V_39 ;
if ( ! F_23 ( V_38 , L_9 , & V_66 ) ) {
if ( F_35 ( V_66 ) && V_66 <= 8 )
V_63 = F_36 ( V_66 ) ;
else
F_29 ( V_2 , L_10 , V_66 ) ;
}
if ( F_37 ( V_38 , L_11 ) ) {
error = F_4 ( V_12 -> V_16 , V_74 ,
V_75 , 0 ) ;
if ( error )
return error ;
}
for ( V_15 = 0 ; V_15 < V_61 -> V_69 ; V_15 ++ )
V_12 -> V_20 [ V_15 ] = V_76 + V_15 ;
F_38 ( V_38 , L_12 ,
V_12 -> V_20 , V_61 -> V_69 ) ;
error = F_4 ( V_12 -> V_16 , V_4 ,
V_77 ,
V_63 << V_78 ) ;
if ( error )
return error ;
error = F_39 ( V_12 -> V_16 , V_79 , 0 ) ;
if ( error )
return error ;
V_12 -> V_18 = F_40 ( V_2 ) ;
if ( ! V_12 -> V_18 )
return - V_44 ;
V_12 -> V_18 -> V_50 = L_13 ;
V_12 -> V_18 -> V_59 . V_80 = V_81 ;
V_12 -> V_18 -> V_82 [ 0 ] = F_41 ( V_83 ) ;
if ( F_37 ( V_38 , L_14 ) )
F_42 ( V_84 , V_12 -> V_18 -> V_82 ) ;
for ( V_15 = 0 ; V_15 < V_61 -> V_69 ; V_15 ++ )
F_42 ( V_12 -> V_20 [ V_15 ] , V_12 -> V_18 -> V_85 ) ;
F_43 ( V_86 , V_12 -> V_18 -> V_85 ) ;
V_12 -> V_18 -> V_87 = V_12 -> V_20 ;
V_12 -> V_18 -> V_88 = sizeof( V_12 -> V_20 [ 0 ] ) ;
V_12 -> V_18 -> V_19 = V_61 -> V_69 ;
V_12 -> V_18 -> V_59 . V_89 = V_73 ;
V_12 -> V_18 -> V_59 . V_90 = V_61 -> V_71 ;
V_12 -> V_18 -> V_59 . V_91 = V_65 ;
V_12 -> V_18 -> V_92 = F_10 ;
V_12 -> V_18 -> V_93 = F_12 ;
error = F_18 ( V_2 , V_12 , V_61 -> V_24 ) ;
if ( error )
return error ;
F_44 ( V_12 -> V_18 , V_12 ) ;
F_8 ( V_12 , true ) ;
error = F_45 ( V_12 -> V_18 ) ;
if ( error )
return error ;
V_62 = F_46 ( V_38 , 0 ) ;
if ( ! V_62 ) {
F_29 ( V_2 , L_15 ) ;
return - V_72 ;
}
error = F_47 ( V_2 , V_62 , NULL , F_3 ,
V_94 , F_48 ( V_2 ) , V_12 ) ;
if ( error )
return error ;
return 0 ;
}
