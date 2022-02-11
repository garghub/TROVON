void F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = & V_2 -> V_2 . V_5 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
struct V_11 V_12 = {
. V_13 = V_4 -> V_14 ,
. V_15 = V_4 -> V_16 ,
} ;
struct V_17 V_5 = {
. V_5 = {
. V_2 = & V_2 -> V_2 ,
. V_18 = 0 ,
. V_19 = 0 ,
. V_20 = V_4 -> V_14 ,
. V_21 = V_4 -> V_16 ,
. V_22 = 0 ,
. V_23 = 0 ,
. V_24 = V_4 -> V_14 << 16 ,
. V_25 = V_4 -> V_16 << 16 ,
. V_26 = 0 ,
} ,
. V_27 = F_2 ( V_28 ) ,
. V_29 = V_30 ,
. V_31 = 255 ,
. V_32 = 0 ,
} ;
if ( V_8 -> V_33 -> V_34 >= 3 )
V_5 . V_35 = ( V_2 -> V_36 % 2 ) ? 2 : 0 ;
else
V_5 . V_35 = V_2 -> V_36 % 2 ;
F_3 ( V_2 -> V_9 , & V_5 ) ;
V_2 -> V_9 -> V_37 = true ;
F_4 ( V_2 -> V_38 -> V_38 , & V_12 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_38 -> V_38 , NULL ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_38 -> V_38 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_38 -> V_38 ) ;
}
static void F_10 ( struct V_39 * V_40 )
{
struct V_41 * V_5 =
F_11 ( V_40 -> V_40 . V_5 ) ;
struct V_42 * V_43 = V_40 -> V_40 . V_5 -> V_43 ;
struct V_44 V_12 = {
. V_45 = 0 ,
. V_46 = V_43 -> V_47 [ 0 ] ,
. V_31 = V_5 -> V_31 ,
. V_26 = V_5 -> V_5 . V_26 ,
} ;
unsigned int V_48 ;
V_12 . V_49 . V_50 = V_5 -> V_5 . V_22 >> 16 ;
V_12 . V_49 . V_51 = V_5 -> V_5 . V_23 >> 16 ;
V_12 . V_49 . V_13 = V_5 -> V_5 . V_24 >> 16 ;
V_12 . V_49 . V_15 = V_5 -> V_5 . V_25 >> 16 ;
V_12 . V_52 . V_50 = V_5 -> V_5 . V_18 ;
V_12 . V_52 . V_51 = V_5 -> V_5 . V_19 ;
V_12 . V_52 . V_13 = V_5 -> V_5 . V_20 ;
V_12 . V_52 . V_15 = V_5 -> V_5 . V_21 ;
for ( V_48 = 0 ; V_48 < V_5 -> V_27 -> V_53 ; ++ V_48 ) {
struct V_54 * V_55 ;
V_55 = F_12 ( V_43 , V_48 ) ;
V_12 . V_56 [ V_48 ] = V_55 -> V_57 + V_43 -> V_58 [ V_48 ] ;
}
for ( V_48 = 0 ; V_48 < F_13 ( V_59 ) ; ++ V_48 ) {
if ( V_59 [ V_48 ] == V_5 -> V_27 -> V_60 ) {
V_12 . V_45 = V_61 [ V_48 ] ;
break;
}
}
F_14 ( V_40 -> V_38 -> V_38 , V_40 -> V_36 , & V_12 ) ;
}
static int F_15 ( struct V_62 * V_40 ,
struct V_63 * V_5 )
{
struct V_41 * V_64 = F_11 ( V_5 ) ;
struct V_39 * V_65 = F_16 ( V_40 ) ;
struct V_7 * V_8 = V_65 -> V_38 -> V_10 ;
if ( ! V_5 -> V_43 || ! V_5 -> V_2 ) {
V_64 -> V_27 = NULL ;
return 0 ;
}
if ( V_5 -> V_24 >> 16 != V_5 -> V_20 ||
V_5 -> V_25 >> 16 != V_5 -> V_21 ) {
F_17 ( V_8 -> V_10 , L_1 , V_66 ) ;
return - V_67 ;
}
V_64 -> V_27 = F_2 ( V_5 -> V_43 -> V_27 -> V_27 ) ;
if ( V_64 -> V_27 == NULL ) {
F_17 ( V_8 -> V_10 , L_2 , V_66 ,
V_5 -> V_43 -> V_27 -> V_27 ) ;
return - V_67 ;
}
return 0 ;
}
static void F_18 ( struct V_62 * V_40 ,
struct V_63 * V_68 )
{
struct V_39 * V_65 = F_16 ( V_40 ) ;
if ( V_40 -> V_5 -> V_2 )
F_10 ( V_65 ) ;
else
F_14 ( V_65 -> V_38 -> V_38 , V_65 -> V_36 , NULL ) ;
}
static struct V_63 *
F_19 ( struct V_62 * V_40 )
{
struct V_41 * V_5 ;
struct V_41 * V_69 ;
if ( F_20 ( ! V_40 -> V_5 ) )
return NULL ;
V_5 = F_11 ( V_40 -> V_5 ) ;
V_69 = F_21 ( V_5 , sizeof( * V_5 ) , V_70 ) ;
if ( V_69 == NULL )
return NULL ;
F_22 ( V_40 , & V_69 -> V_5 ) ;
return & V_69 -> V_5 ;
}
static void F_23 ( struct V_62 * V_40 ,
struct V_63 * V_5 )
{
F_24 ( V_5 ) ;
F_25 ( F_11 ( V_5 ) ) ;
}
static void F_26 ( struct V_62 * V_40 )
{
struct V_41 * V_5 ;
if ( V_40 -> V_5 ) {
F_23 ( V_40 , V_40 -> V_5 ) ;
V_40 -> V_5 = NULL ;
}
V_5 = F_27 ( sizeof( * V_5 ) , V_70 ) ;
if ( V_5 == NULL )
return;
V_5 -> V_31 = 255 ;
V_5 -> V_5 . V_26 = V_40 -> type == V_71 ? 0 : 1 ;
V_40 -> V_5 = & V_5 -> V_5 ;
V_40 -> V_5 -> V_40 = V_40 ;
}
static int F_28 ( struct V_62 * V_40 ,
struct V_63 * V_5 , struct V_72 * V_73 ,
T_1 V_74 )
{
struct V_41 * V_64 = F_11 ( V_5 ) ;
struct V_7 * V_8 = F_16 ( V_40 ) -> V_38 -> V_10 ;
if ( V_73 == V_8 -> V_75 . V_31 )
V_64 -> V_31 = V_74 ;
else
return - V_67 ;
return 0 ;
}
static int F_29 ( struct V_62 * V_40 ,
const struct V_63 * V_5 , struct V_72 * V_73 ,
T_1 * V_74 )
{
const struct V_41 * V_64 =
F_30 ( V_5 , const struct V_41 , V_5 ) ;
struct V_7 * V_8 = F_16 ( V_40 ) -> V_38 -> V_10 ;
if ( V_73 == V_8 -> V_75 . V_31 )
* V_74 = V_64 -> V_31 ;
else
return - V_67 ;
return 0 ;
}
int F_31 ( struct V_76 * V_38 )
{
struct V_7 * V_8 = V_38 -> V_10 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
unsigned int V_48 ;
int V_81 ;
V_80 = F_32 ( V_8 -> V_10 -> V_82 , L_3 , V_38 -> V_36 ) ;
if ( ! V_80 ) {
F_33 ( V_8 -> V_10 , L_4 ) ;
return - V_83 ;
}
V_78 = F_34 ( V_80 ) ;
F_35 ( V_80 ) ;
if ( ! V_78 )
return - V_83 ;
V_38 -> V_38 = & V_78 -> V_10 ;
V_81 = F_36 ( V_38 -> V_38 ) ;
if ( V_81 < 0 )
return V_81 ;
V_38 -> V_84 = V_8 -> V_33 -> V_34 >= 3 ? 5 : 4 ;
V_38 -> V_53 = F_37 ( V_8 -> V_10 , V_38 -> V_84 ,
sizeof( * V_38 -> V_53 ) , V_70 ) ;
if ( ! V_38 -> V_53 )
return - V_85 ;
for ( V_48 = 0 ; V_48 < V_38 -> V_84 ; ++ V_48 ) {
enum V_86 type = V_48 ? V_87
: V_71 ;
struct V_39 * V_40 = & V_38 -> V_53 [ V_48 ] ;
V_40 -> V_38 = V_38 ;
V_40 -> V_36 = V_48 ;
V_81 = F_38 ( V_8 -> V_88 , & V_40 -> V_40 ,
1 << V_38 -> V_36 ,
& V_89 ,
V_59 ,
F_13 ( V_59 ) , type ,
NULL ) ;
if ( V_81 < 0 )
return V_81 ;
F_39 ( & V_40 -> V_40 ,
& V_90 ) ;
if ( type == V_71 )
continue;
F_40 ( & V_40 -> V_40 . V_91 ,
V_8 -> V_75 . V_31 , 255 ) ;
F_41 ( & V_40 -> V_40 , 1 , 1 ,
V_38 -> V_84 - 1 ) ;
}
return 0 ;
}
