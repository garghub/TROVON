static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = V_2 -> V_6 . V_7 ;
T_2 V_8 = 0 ;
int V_9 ;
int V_10 ;
if ( V_2 -> V_6 . V_11 != V_12 ||
V_2 -> V_6 . V_13 != V_12 ||
V_2 -> V_6 . V_14 & V_15 )
V_5 = 0 ;
if ( V_5 != 0 )
V_8 = V_16 ;
V_9 = F_3 ( V_4 -> V_17 ,
V_4 -> V_18 + V_19 ,
V_20 , V_8 ) ;
if ( V_9 )
return V_9 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_21 . V_22 ; ++ V_10 ) {
T_2 V_23 [ 2 ] = { V_5 & 0xff , ( V_5 >> 8 ) & 0xf } ;
V_9 = F_4 ( V_4 -> V_17 ,
V_4 -> V_18 + V_24 + 2 * V_10 ,
V_23 , 2 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_3 ( V_4 -> V_17 ,
V_4 -> V_18 + V_25 ,
V_26 , V_27 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_4 -> V_17 ,
V_4 -> V_18 + V_25 ,
V_26 , V_28 ) ;
return V_9 ;
}
static int F_5 ( struct V_3 * V_4 )
{
int V_9 ;
int V_10 ;
V_9 = F_3 ( V_4 -> V_17 ,
V_4 -> V_18 + V_29 ,
V_30 , V_4 -> V_21 . V_31 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_4 -> V_17 ,
V_4 -> V_18 + V_32 ,
V_33 , V_4 -> V_21 . V_34 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_4 -> V_17 ,
V_4 -> V_18 + V_35 ,
V_36 , V_4 -> V_21 . V_37 ) ;
if ( V_9 )
return V_9 ;
if ( V_4 -> V_21 . V_38 ) {
T_2 V_39 = ( F_6 ( V_4 -> V_21 . V_22 ) - 1 )
<< V_40 ;
V_9 = F_3 ( V_4 -> V_17 ,
V_4 -> V_18 + V_41 ,
V_42 , V_39 ) ;
if ( V_9 )
return V_9 ;
}
for ( V_10 = 0 ; V_10 < V_4 -> V_21 . V_22 ; ++ V_10 ) {
T_1 V_18 = V_4 -> V_18 + V_43 * V_10 ;
V_9 = F_3 ( V_4 -> V_17 ,
V_18 + V_44 ,
V_45 ,
V_46 ) ;
if ( V_9 )
return V_9 ;
if ( V_4 -> V_21 . V_47 ) {
V_9 = F_3 ( V_4 -> V_17 ,
V_18 + V_48 ,
V_49 ,
V_50 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_3 ( V_4 -> V_17 ,
V_18 + V_51 ,
V_52 ,
V_4 -> V_21 . V_53 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_4 -> V_17 ,
V_18 + V_54 ,
V_55 ,
V_4 -> V_21 . V_56 ?
V_57 : 0 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static T_3 F_7 ( T_3 V_58 )
{
return V_58 + 1 ;
}
static T_3 F_8 ( T_3 V_58 )
{
return 19200 / ( 2 * ( 1 + V_58 ) ) ;
}
static T_3 F_9 ( const struct V_59 * V_21 , T_3 V_58 )
{
if ( V_58 >= V_21 -> V_60 )
return V_61 ;
if ( V_21 -> V_62 )
return V_21 -> V_62 ( V_58 ) ;
if ( V_21 -> V_63 )
return V_21 -> V_63 [ V_58 ] ;
return V_58 ;
}
static int F_10 ( struct V_3 * V_4 , struct V_64 * V_65 )
{
struct V_66 * V_21 = & V_4 -> V_21 ;
T_3 V_5 ;
int V_9 ;
T_3 V_67 ;
int V_10 ;
int V_68 ;
const struct {
const char * V_69 ;
T_3 * V_70 ;
const struct V_59 * V_21 ;
} V_71 [] = {
{
L_1 ,
& V_21 -> V_34 ,
. V_21 = & V_72 ,
} ,
{
L_2 ,
& V_21 -> V_53 ,
. V_21 = & V_73 ,
} ,
{
L_3 ,
& V_21 -> V_31 ,
. V_21 = & V_74 ,
} ,
{
L_4 ,
& V_21 -> V_37 ,
. V_21 = & V_75 ,
} ,
{
L_5 ,
& V_21 -> V_22 ,
. V_21 = & V_76 ,
} ,
} ;
const struct {
const char * V_69 ;
bool * V_70 ;
} V_77 [] = {
{ L_6 , & V_21 -> V_38 , } ,
{ L_7 , & V_21 -> V_47 , } ,
{ L_8 , & V_21 -> V_56 , } ,
} ;
V_9 = F_11 ( V_65 -> V_78 , L_9 , & V_5 ) ;
if ( V_9 || V_5 > 0xffff ) {
F_12 ( V_65 , L_10 ) ;
return V_9 ? V_9 : - V_79 ;
}
V_4 -> V_18 = V_5 ;
V_9 = F_13 ( V_65 -> V_78 , L_11 , & V_4 -> V_69 ) ;
if ( V_9 )
V_4 -> V_69 = V_65 -> V_78 -> V_69 ;
* V_21 = V_80 ;
for ( V_10 = 0 ; V_10 < F_14 ( V_71 ) ; ++ V_10 ) {
V_9 = F_11 ( V_65 -> V_78 , V_71 [ V_10 ] . V_69 , & V_5 ) ;
if ( V_9 == - V_79 ) {
continue;
} else if ( V_9 ) {
F_12 ( V_65 , L_12 , V_71 [ V_10 ] . V_69 ) ;
return V_9 ;
}
V_67 = V_61 ;
for ( V_68 = 0 ; V_67 != V_5 ; V_68 ++ ) {
V_67 = F_9 ( V_71 [ V_10 ] . V_21 , V_68 ) ;
if ( V_67 == V_61 ) {
F_12 ( V_65 , L_13 ,
V_71 [ V_10 ] . V_69 ) ;
return - V_79 ;
}
}
F_15 ( V_65 , L_14 , V_71 [ V_10 ] . V_69 , V_67 ) ;
* V_71 [ V_10 ] . V_70 = V_68 ;
}
for ( V_10 = 0 ; V_10 < F_14 ( V_77 ) ; ++ V_10 ) {
if ( F_16 ( V_65 -> V_78 , V_77 [ V_10 ] . V_69 ) )
* V_77 [ V_10 ] . V_70 = true ;
}
V_21 -> V_22 = V_21 -> V_22 + 1 ;
return 0 ;
}
static int F_17 ( struct V_81 * V_82 )
{
struct V_83 V_6 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_17 * V_17 ;
T_3 V_5 ;
int V_9 ;
V_17 = F_18 ( V_82 -> V_65 . V_84 , NULL ) ;
if ( ! V_17 ) {
F_12 ( & V_82 -> V_65 , L_15 ) ;
return - V_79 ;
}
V_4 = F_19 ( & V_82 -> V_65 , sizeof( * V_4 ) , V_85 ) ;
if ( ! V_4 )
return - V_86 ;
V_4 -> V_17 = V_17 ;
V_9 = F_10 ( V_4 , & V_82 -> V_65 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_5 = V_87 ;
F_11 ( V_82 -> V_65 . V_78 , L_16 , & V_5 ) ;
memset ( & V_6 , 0 , sizeof( struct V_83 ) ) ;
V_6 . type = V_88 ;
V_6 . V_7 = V_5 ;
V_6 . V_89 = V_90 ;
V_2 = F_20 ( & V_82 -> V_65 , V_4 -> V_69 ,
& V_82 -> V_65 , V_4 ,
& V_91 , & V_6 ) ;
return F_21 ( V_2 ) ;
}
