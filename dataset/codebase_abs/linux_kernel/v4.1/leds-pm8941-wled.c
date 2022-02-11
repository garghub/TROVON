static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 = 0 ;
T_2 V_8 ;
int V_9 ;
int V_10 ;
V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( V_4 != 0 )
V_7 = V_11 ;
V_8 = V_4 * V_12 / V_13 ;
V_9 = F_3 ( V_6 -> V_14 ,
V_6 -> V_15 + V_16 ,
V_17 , V_7 ) ;
if ( V_9 )
return V_9 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_18 . V_19 ; ++ V_10 ) {
T_1 V_20 [ 2 ] = { V_8 & 0xff , ( V_8 >> 8 ) & 0xf } ;
V_9 = F_4 ( V_6 -> V_14 ,
V_6 -> V_15 + V_21 + 2 * V_10 ,
V_20 , 2 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_3 ( V_6 -> V_14 ,
V_6 -> V_15 + V_22 ,
V_23 , V_24 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_6 -> V_14 ,
V_6 -> V_15 + V_22 ,
V_23 , V_25 ) ;
return V_9 ;
}
static void F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( F_1 ( V_2 , V_4 ) ) {
F_6 ( V_2 -> V_26 , L_1 ) ;
return;
}
V_2 -> V_27 = V_4 ;
}
static int F_7 ( struct V_5 * V_6 )
{
int V_9 ;
int V_10 ;
V_9 = F_3 ( V_6 -> V_14 ,
V_6 -> V_15 + V_28 ,
V_29 , V_6 -> V_18 . V_30 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_6 -> V_14 ,
V_6 -> V_15 + V_31 ,
V_32 , V_6 -> V_18 . V_33 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_6 -> V_14 ,
V_6 -> V_15 + V_34 ,
V_35 , V_6 -> V_18 . V_36 ) ;
if ( V_9 )
return V_9 ;
if ( V_6 -> V_18 . V_37 ) {
T_1 V_38 = ( F_8 ( V_6 -> V_18 . V_19 ) - 1 )
<< V_39 ;
V_9 = F_3 ( V_6 -> V_14 ,
V_6 -> V_15 + V_40 ,
V_41 , V_38 ) ;
if ( V_9 )
return V_9 ;
}
for ( V_10 = 0 ; V_10 < V_6 -> V_18 . V_19 ; ++ V_10 ) {
T_2 V_15 = V_6 -> V_15 + V_42 * V_10 ;
V_9 = F_3 ( V_6 -> V_14 ,
V_15 + V_43 ,
V_44 ,
V_45 ) ;
if ( V_9 )
return V_9 ;
if ( V_6 -> V_18 . V_46 ) {
V_9 = F_3 ( V_6 -> V_14 ,
V_15 + V_47 ,
V_48 ,
V_49 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_3 ( V_6 -> V_14 ,
V_15 + V_50 ,
V_51 ,
V_6 -> V_18 . V_52 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_6 -> V_14 ,
V_15 + V_53 ,
V_54 ,
V_6 -> V_18 . V_55 ?
V_56 : 0 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static T_3 F_9 ( T_3 V_57 )
{
return V_57 + 1 ;
}
static T_3 F_10 ( T_3 V_57 )
{
return 19200 / ( 2 * ( 1 + V_57 ) ) ;
}
static T_3 F_11 ( const struct V_58 * V_18 , T_3 V_57 )
{
if ( V_57 >= V_18 -> V_59 )
return V_60 ;
if ( V_18 -> V_61 )
return V_18 -> V_61 ( V_57 ) ;
if ( V_18 -> V_62 )
return V_18 -> V_62 [ V_57 ] ;
return V_57 ;
}
static int F_12 ( struct V_5 * V_6 , struct V_63 * V_26 )
{
struct V_64 * V_18 = & V_6 -> V_18 ;
T_3 V_8 ;
int V_9 ;
T_3 V_65 ;
int V_10 ;
int V_66 ;
const struct {
const char * V_67 ;
T_3 * V_68 ;
const struct V_58 * V_18 ;
} V_69 [] = {
{
L_2 ,
& V_18 -> V_33 ,
. V_18 = & V_70 ,
} ,
{
L_3 ,
& V_18 -> V_52 ,
. V_18 = & V_71 ,
} ,
{
L_4 ,
& V_18 -> V_30 ,
. V_18 = & V_72 ,
} ,
{
L_5 ,
& V_18 -> V_36 ,
. V_18 = & V_73 ,
} ,
{
L_6 ,
& V_18 -> V_19 ,
. V_18 = & V_74 ,
} ,
} ;
const struct {
const char * V_67 ;
bool * V_68 ;
} V_75 [] = {
{ L_7 , & V_18 -> V_37 , } ,
{ L_8 , & V_18 -> V_46 , } ,
{ L_9 , & V_18 -> V_55 , } ,
} ;
V_9 = F_13 ( V_26 -> V_76 , L_10 , & V_8 ) ;
if ( V_9 || V_8 > 0xffff ) {
F_6 ( V_26 , L_11 ) ;
return V_9 ? V_9 : - V_77 ;
}
V_6 -> V_15 = V_8 ;
V_9 = F_14 ( V_26 -> V_76 , L_12 , & V_6 -> V_2 . V_67 ) ;
if ( V_9 )
V_6 -> V_2 . V_67 = V_26 -> V_76 -> V_67 ;
V_6 -> V_2 . V_78 = F_15 ( V_26 -> V_76 ,
L_13 , NULL ) ;
* V_18 = V_79 ;
for ( V_10 = 0 ; V_10 < F_16 ( V_69 ) ; ++ V_10 ) {
V_9 = F_13 ( V_26 -> V_76 , V_69 [ V_10 ] . V_67 , & V_8 ) ;
if ( V_9 == - V_77 ) {
continue;
} else if ( V_9 ) {
F_6 ( V_26 , L_14 , V_69 [ V_10 ] . V_67 ) ;
return V_9 ;
}
V_65 = V_60 ;
for ( V_66 = 0 ; V_65 != V_8 ; V_66 ++ ) {
V_65 = F_11 ( V_69 [ V_10 ] . V_18 , V_66 ) ;
if ( V_65 == V_60 ) {
F_6 ( V_26 , L_15 ,
V_69 [ V_10 ] . V_67 ) ;
return - V_77 ;
}
}
F_17 ( V_26 , L_16 , V_69 [ V_10 ] . V_67 , V_65 ) ;
* V_69 [ V_10 ] . V_68 = V_66 ;
}
for ( V_10 = 0 ; V_10 < F_16 ( V_75 ) ; ++ V_10 ) {
if ( F_18 ( V_26 -> V_76 , V_75 [ V_10 ] . V_67 ) )
* V_75 [ V_10 ] . V_68 = true ;
}
V_18 -> V_19 = V_18 -> V_19 + 1 ;
return 0 ;
}
static int F_19 ( struct V_80 * V_81 )
{
struct V_5 * V_6 ;
struct V_14 * V_14 ;
int V_9 ;
V_14 = F_20 ( V_81 -> V_26 . V_82 , NULL ) ;
if ( ! V_14 ) {
F_6 ( & V_81 -> V_26 , L_17 ) ;
return - V_77 ;
}
V_6 = F_21 ( & V_81 -> V_26 , sizeof( * V_6 ) , V_83 ) ;
if ( ! V_6 )
return - V_84 ;
V_6 -> V_14 = V_14 ;
V_9 = F_12 ( V_6 , & V_81 -> V_26 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_7 ( V_6 ) ;
if ( V_9 )
return V_9 ;
V_6 -> V_2 . V_85 = F_5 ;
V_9 = F_22 ( & V_81 -> V_26 , & V_6 -> V_2 ) ;
if ( V_9 )
return V_9 ;
F_23 ( V_81 , V_6 ) ;
return 0 ;
}
