void F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = & V_2 -> V_2 . V_5 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
struct V_11 V_5 = {
. V_5 = {
. V_2 = & V_2 -> V_2 ,
. V_12 = 0 ,
. V_13 = 0 ,
. V_14 = V_4 -> V_15 ,
. V_16 = V_4 -> V_17 ,
. V_18 = 0 ,
. V_19 = 0 ,
. V_20 = V_4 -> V_15 << 16 ,
. V_21 = V_4 -> V_17 << 16 ,
} ,
. V_22 = F_2 ( V_23 ) ,
. V_24 = V_25 ,
. V_26 = 255 ,
. V_27 = 0 ,
. V_28 = 0 ,
} ;
if ( V_8 -> V_29 -> V_30 >= 3 )
V_5 . V_31 = ( V_2 -> V_32 % 2 ) ? 2 : 0 ;
else
V_5 . V_31 = V_2 -> V_32 % 2 ;
F_3 ( V_2 -> V_9 , & V_5 ) ;
V_2 -> V_9 -> V_33 = true ;
F_4 ( V_2 -> V_34 -> V_34 , V_4 -> V_15 , V_4 -> V_17 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_34 -> V_34 , 0 , 0 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_34 -> V_34 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_34 -> V_34 ) ;
}
static void F_10 ( struct V_35 * V_36 )
{
struct V_37 * V_5 =
F_11 ( V_36 -> V_36 . V_5 ) ;
struct V_38 * V_39 = V_36 -> V_36 . V_5 -> V_39 ;
struct V_40 V_41 ;
struct V_40 V_42 ;
T_1 V_43 [ 2 ] = { 0 , } ;
T_2 V_44 = 0 ;
unsigned int V_45 ;
V_41 . V_46 = V_5 -> V_5 . V_18 >> 16 ;
V_41 . V_47 = V_5 -> V_5 . V_19 >> 16 ;
V_41 . V_48 = V_5 -> V_5 . V_20 >> 16 ;
V_41 . V_49 = V_5 -> V_5 . V_21 >> 16 ;
V_42 . V_46 = V_5 -> V_5 . V_12 ;
V_42 . V_47 = V_5 -> V_5 . V_13 ;
V_42 . V_48 = V_5 -> V_5 . V_14 ;
V_42 . V_49 = V_5 -> V_5 . V_16 ;
for ( V_45 = 0 ; V_45 < V_5 -> V_22 -> V_50 ; ++ V_45 ) {
struct V_51 * V_52 ;
V_52 = F_12 ( V_39 , V_45 ) ;
V_43 [ V_45 ] = V_52 -> V_43 + V_39 -> V_53 [ V_45 ] ;
}
for ( V_45 = 0 ; V_45 < F_13 ( V_54 ) ; ++ V_45 ) {
if ( V_54 [ V_45 ] == V_5 -> V_22 -> V_55 ) {
V_44 = V_56 [ V_45 ] ;
break;
}
}
F_14 ( ! V_44 ) ;
F_15 ( V_36 -> V_34 -> V_34 , V_36 -> V_32 , V_44 ,
V_39 -> V_57 [ 0 ] , V_43 , & V_41 , & V_42 ) ;
}
static int F_16 ( struct V_58 * V_36 ,
struct V_59 * V_5 )
{
struct V_37 * V_60 = F_11 ( V_5 ) ;
struct V_35 * V_61 = F_17 ( V_36 ) ;
struct V_7 * V_8 = V_61 -> V_34 -> V_10 ;
if ( ! V_5 -> V_39 || ! V_5 -> V_2 ) {
V_60 -> V_22 = NULL ;
return 0 ;
}
if ( V_5 -> V_20 >> 16 != V_5 -> V_14 ||
V_5 -> V_21 >> 16 != V_5 -> V_16 ) {
F_18 ( V_8 -> V_10 , L_1 , V_62 ) ;
return - V_63 ;
}
V_60 -> V_22 = F_2 ( V_5 -> V_39 -> V_64 ) ;
if ( V_60 -> V_22 == NULL ) {
F_18 ( V_8 -> V_10 , L_2 , V_62 ,
V_5 -> V_39 -> V_64 ) ;
return - V_63 ;
}
return 0 ;
}
static void F_19 ( struct V_58 * V_36 ,
struct V_59 * V_65 )
{
struct V_35 * V_61 = F_17 ( V_36 ) ;
if ( V_36 -> V_5 -> V_2 )
F_10 ( V_61 ) ;
else
F_15 ( V_61 -> V_34 -> V_34 , V_61 -> V_32 , 0 , 0 , 0 ,
NULL , NULL ) ;
}
static struct V_59 *
F_20 ( struct V_58 * V_36 )
{
struct V_37 * V_5 ;
struct V_37 * V_66 ;
if ( F_14 ( ! V_36 -> V_5 ) )
return NULL ;
V_5 = F_11 ( V_36 -> V_5 ) ;
V_66 = F_21 ( V_5 , sizeof( * V_5 ) , V_67 ) ;
if ( V_66 == NULL )
return NULL ;
F_22 ( V_36 , & V_66 -> V_5 ) ;
return & V_66 -> V_5 ;
}
static void F_23 ( struct V_58 * V_36 ,
struct V_59 * V_5 )
{
F_24 ( V_36 , V_5 ) ;
F_25 ( F_11 ( V_5 ) ) ;
}
static void F_26 ( struct V_58 * V_36 )
{
struct V_37 * V_5 ;
if ( V_36 -> V_5 ) {
F_23 ( V_36 , V_36 -> V_5 ) ;
V_36 -> V_5 = NULL ;
}
V_5 = F_27 ( sizeof( * V_5 ) , V_67 ) ;
if ( V_5 == NULL )
return;
V_5 -> V_26 = 255 ;
V_36 -> V_5 = & V_5 -> V_5 ;
V_36 -> V_5 -> V_36 = V_36 ;
}
static int F_28 ( struct V_58 * V_36 ,
struct V_59 * V_5 , struct V_68 * V_69 ,
T_3 V_70 )
{
struct V_37 * V_60 = F_11 ( V_5 ) ;
struct V_7 * V_8 = F_17 ( V_36 ) -> V_34 -> V_10 ;
if ( V_69 == V_8 -> V_71 . V_26 )
V_60 -> V_26 = V_70 ;
else
return - V_63 ;
return 0 ;
}
static int F_29 ( struct V_58 * V_36 ,
const struct V_59 * V_5 , struct V_68 * V_69 ,
T_3 * V_70 )
{
const struct V_37 * V_60 =
F_30 ( V_5 , const struct V_37 , V_5 ) ;
struct V_7 * V_8 = F_17 ( V_36 ) -> V_34 -> V_10 ;
if ( V_69 == V_8 -> V_71 . V_26 )
* V_70 = V_60 -> V_26 ;
else
return - V_63 ;
return 0 ;
}
int F_31 ( struct V_72 * V_34 )
{
struct V_7 * V_8 = V_34 -> V_10 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
unsigned int V_45 ;
int V_77 ;
V_76 = F_32 ( V_8 -> V_10 -> V_78 , L_3 , V_34 -> V_32 ) ;
if ( ! V_76 ) {
F_33 ( V_8 -> V_10 , L_4 ) ;
return - V_79 ;
}
V_74 = F_34 ( V_76 ) ;
F_35 ( V_76 ) ;
if ( ! V_74 )
return - V_79 ;
V_34 -> V_34 = & V_74 -> V_10 ;
V_77 = F_36 ( V_34 -> V_34 ) ;
if ( V_77 < 0 )
return V_77 ;
V_34 -> V_80 = V_8 -> V_29 -> V_30 >= 3 ? 5 : 4 ;
V_34 -> V_50 = F_37 ( V_8 -> V_10 , V_34 -> V_80 ,
sizeof( * V_34 -> V_50 ) , V_67 ) ;
if ( ! V_34 -> V_50 )
return - V_81 ;
for ( V_45 = 0 ; V_45 < V_34 -> V_80 ; ++ V_45 ) {
enum V_82 type = V_45 ? V_83
: V_84 ;
struct V_35 * V_36 = & V_34 -> V_50 [ V_45 ] ;
V_36 -> V_34 = V_34 ;
V_36 -> V_32 = V_45 ;
V_77 = F_38 ( V_8 -> V_85 , & V_36 -> V_36 ,
1 << V_34 -> V_32 ,
& V_86 ,
V_54 ,
F_13 ( V_54 ) , type ,
NULL ) ;
if ( V_77 < 0 )
return V_77 ;
F_39 ( & V_36 -> V_36 ,
& V_87 ) ;
if ( type == V_84 )
continue;
F_40 ( & V_36 -> V_36 . V_88 ,
V_8 -> V_71 . V_26 , 255 ) ;
}
return 0 ;
}
