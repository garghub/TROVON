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
. V_22 = 0 ,
} ,
. V_23 = F_2 ( V_24 ) ,
. V_25 = V_26 ,
. V_27 = 255 ,
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
struct V_40 V_41 = {
. V_42 = 0 ,
. V_43 = V_39 -> V_44 [ 0 ] ,
. V_27 = V_5 -> V_27 ,
. V_22 = V_5 -> V_5 . V_22 ,
} ;
unsigned int V_45 ;
V_41 . V_46 . V_47 = V_5 -> V_5 . V_18 >> 16 ;
V_41 . V_46 . V_48 = V_5 -> V_5 . V_19 >> 16 ;
V_41 . V_46 . V_49 = V_5 -> V_5 . V_20 >> 16 ;
V_41 . V_46 . V_50 = V_5 -> V_5 . V_21 >> 16 ;
V_41 . V_51 . V_47 = V_5 -> V_5 . V_12 ;
V_41 . V_51 . V_48 = V_5 -> V_5 . V_13 ;
V_41 . V_51 . V_49 = V_5 -> V_5 . V_14 ;
V_41 . V_51 . V_50 = V_5 -> V_5 . V_16 ;
for ( V_45 = 0 ; V_45 < V_5 -> V_23 -> V_52 ; ++ V_45 ) {
struct V_53 * V_54 ;
V_54 = F_12 ( V_39 , V_45 ) ;
V_41 . V_55 [ V_45 ] = V_54 -> V_56 + V_39 -> V_57 [ V_45 ] ;
}
for ( V_45 = 0 ; V_45 < F_13 ( V_58 ) ; ++ V_45 ) {
if ( V_58 [ V_45 ] == V_5 -> V_23 -> V_59 ) {
V_41 . V_42 = V_60 [ V_45 ] ;
break;
}
}
F_14 ( V_36 -> V_34 -> V_34 , V_36 -> V_32 , & V_41 ) ;
}
static int F_15 ( struct V_61 * V_36 ,
struct V_62 * V_5 )
{
struct V_37 * V_63 = F_11 ( V_5 ) ;
struct V_35 * V_64 = F_16 ( V_36 ) ;
struct V_7 * V_8 = V_64 -> V_34 -> V_10 ;
if ( ! V_5 -> V_39 || ! V_5 -> V_2 ) {
V_63 -> V_23 = NULL ;
return 0 ;
}
if ( V_5 -> V_20 >> 16 != V_5 -> V_14 ||
V_5 -> V_21 >> 16 != V_5 -> V_16 ) {
F_17 ( V_8 -> V_10 , L_1 , V_65 ) ;
return - V_66 ;
}
V_63 -> V_23 = F_2 ( V_5 -> V_39 -> V_67 ) ;
if ( V_63 -> V_23 == NULL ) {
F_17 ( V_8 -> V_10 , L_2 , V_65 ,
V_5 -> V_39 -> V_67 ) ;
return - V_66 ;
}
return 0 ;
}
static void F_18 ( struct V_61 * V_36 ,
struct V_62 * V_68 )
{
struct V_35 * V_64 = F_16 ( V_36 ) ;
if ( V_36 -> V_5 -> V_2 )
F_10 ( V_64 ) ;
else
F_14 ( V_64 -> V_34 -> V_34 , V_64 -> V_32 , NULL ) ;
}
static struct V_62 *
F_19 ( struct V_61 * V_36 )
{
struct V_37 * V_5 ;
struct V_37 * V_69 ;
if ( F_20 ( ! V_36 -> V_5 ) )
return NULL ;
V_5 = F_11 ( V_36 -> V_5 ) ;
V_69 = F_21 ( V_5 , sizeof( * V_5 ) , V_70 ) ;
if ( V_69 == NULL )
return NULL ;
F_22 ( V_36 , & V_69 -> V_5 ) ;
return & V_69 -> V_5 ;
}
static void F_23 ( struct V_61 * V_36 ,
struct V_62 * V_5 )
{
F_24 ( V_5 ) ;
F_25 ( F_11 ( V_5 ) ) ;
}
static void F_26 ( struct V_61 * V_36 )
{
struct V_37 * V_5 ;
if ( V_36 -> V_5 ) {
F_23 ( V_36 , V_36 -> V_5 ) ;
V_36 -> V_5 = NULL ;
}
V_5 = F_27 ( sizeof( * V_5 ) , V_70 ) ;
if ( V_5 == NULL )
return;
V_5 -> V_27 = 255 ;
V_5 -> V_5 . V_22 = V_36 -> type == V_71 ? 0 : 1 ;
V_36 -> V_5 = & V_5 -> V_5 ;
V_36 -> V_5 -> V_36 = V_36 ;
}
static int F_28 ( struct V_61 * V_36 ,
struct V_62 * V_5 , struct V_72 * V_73 ,
T_1 V_74 )
{
struct V_37 * V_63 = F_11 ( V_5 ) ;
struct V_7 * V_8 = F_16 ( V_36 ) -> V_34 -> V_10 ;
if ( V_73 == V_8 -> V_75 . V_27 )
V_63 -> V_27 = V_74 ;
else
return - V_66 ;
return 0 ;
}
static int F_29 ( struct V_61 * V_36 ,
const struct V_62 * V_5 , struct V_72 * V_73 ,
T_1 * V_74 )
{
const struct V_37 * V_63 =
F_30 ( V_5 , const struct V_37 , V_5 ) ;
struct V_7 * V_8 = F_16 ( V_36 ) -> V_34 -> V_10 ;
if ( V_73 == V_8 -> V_75 . V_27 )
* V_74 = V_63 -> V_27 ;
else
return - V_66 ;
return 0 ;
}
int F_31 ( struct V_76 * V_34 )
{
struct V_7 * V_8 = V_34 -> V_10 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
unsigned int V_45 ;
int V_81 ;
V_80 = F_32 ( V_8 -> V_10 -> V_82 , L_3 , V_34 -> V_32 ) ;
if ( ! V_80 ) {
F_33 ( V_8 -> V_10 , L_4 ) ;
return - V_83 ;
}
V_78 = F_34 ( V_80 ) ;
F_35 ( V_80 ) ;
if ( ! V_78 )
return - V_83 ;
V_34 -> V_34 = & V_78 -> V_10 ;
V_81 = F_36 ( V_34 -> V_34 ) ;
if ( V_81 < 0 )
return V_81 ;
V_34 -> V_84 = V_8 -> V_29 -> V_30 >= 3 ? 5 : 4 ;
V_34 -> V_52 = F_37 ( V_8 -> V_10 , V_34 -> V_84 ,
sizeof( * V_34 -> V_52 ) , V_70 ) ;
if ( ! V_34 -> V_52 )
return - V_85 ;
for ( V_45 = 0 ; V_45 < V_34 -> V_84 ; ++ V_45 ) {
enum V_86 type = V_45 ? V_87
: V_71 ;
struct V_35 * V_36 = & V_34 -> V_52 [ V_45 ] ;
V_36 -> V_34 = V_34 ;
V_36 -> V_32 = V_45 ;
V_81 = F_38 ( V_8 -> V_88 , & V_36 -> V_36 ,
1 << V_34 -> V_32 ,
& V_89 ,
V_58 ,
F_13 ( V_58 ) , type ,
NULL ) ;
if ( V_81 < 0 )
return V_81 ;
F_39 ( & V_36 -> V_36 ,
& V_90 ) ;
if ( type == V_71 )
continue;
F_40 ( & V_36 -> V_36 . V_91 ,
V_8 -> V_75 . V_27 , 255 ) ;
F_41 ( & V_36 -> V_36 , 1 , 1 ,
V_34 -> V_84 - 1 ) ;
}
return 0 ;
}
