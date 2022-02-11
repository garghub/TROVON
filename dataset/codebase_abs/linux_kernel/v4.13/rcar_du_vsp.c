static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 ) ;
}
void F_3 ( struct V_2 * V_3 )
{
const struct V_4 * V_5 = & V_3 -> V_3 . V_6 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_10 -> V_11 ;
struct V_12 V_13 = {
. V_14 = V_5 -> V_15 ,
. V_16 = V_5 -> V_17 ,
. V_18 = F_1 ,
. V_19 = V_3 ,
} ;
struct V_20 V_6 = {
. V_6 = {
. V_3 = & V_3 -> V_3 ,
. V_21 = 0 ,
. V_22 = 0 ,
. V_23 = V_5 -> V_15 ,
. V_24 = V_5 -> V_17 ,
. V_25 = 0 ,
. V_26 = 0 ,
. V_27 = V_5 -> V_15 << 16 ,
. V_28 = V_5 -> V_17 << 16 ,
. V_29 = 0 ,
} ,
. V_30 = F_4 ( V_31 ) ,
. V_32 = V_33 ,
. V_34 = 255 ,
. V_35 = 0 ,
} ;
if ( V_9 -> V_36 -> V_37 >= 3 )
V_6 . V_38 = ( V_3 -> V_39 % 2 ) ? 2 : 0 ;
else
V_6 . V_38 = V_3 -> V_39 % 2 ;
F_5 ( V_3 -> V_10 , & V_6 ) ;
V_3 -> V_10 -> V_40 = true ;
F_6 ( V_3 -> V_41 -> V_41 , & V_13 ) ;
}
void F_7 ( struct V_2 * V_3 )
{
F_6 ( V_3 -> V_41 -> V_41 , NULL ) ;
}
void F_8 ( struct V_2 * V_3 )
{
F_9 ( V_3 -> V_41 -> V_41 ) ;
}
void F_10 ( struct V_2 * V_3 )
{
F_11 ( V_3 -> V_41 -> V_41 ) ;
}
static void F_12 ( struct V_42 * V_43 )
{
struct V_44 * V_6 =
F_13 ( V_43 -> V_43 . V_6 ) ;
struct V_45 * V_46 = V_43 -> V_43 . V_6 -> V_46 ;
struct V_47 V_13 = {
. V_48 = 0 ,
. V_49 = V_46 -> V_50 [ 0 ] ,
. V_34 = V_6 -> V_34 ,
. V_29 = V_6 -> V_6 . V_29 ,
} ;
unsigned int V_51 ;
V_13 . V_52 . V_53 = V_6 -> V_6 . V_25 >> 16 ;
V_13 . V_52 . V_54 = V_6 -> V_6 . V_26 >> 16 ;
V_13 . V_52 . V_14 = V_6 -> V_6 . V_27 >> 16 ;
V_13 . V_52 . V_16 = V_6 -> V_6 . V_28 >> 16 ;
V_13 . V_55 . V_53 = V_6 -> V_6 . V_21 ;
V_13 . V_55 . V_54 = V_6 -> V_6 . V_22 ;
V_13 . V_55 . V_14 = V_6 -> V_6 . V_23 ;
V_13 . V_55 . V_16 = V_6 -> V_6 . V_24 ;
for ( V_51 = 0 ; V_51 < V_6 -> V_30 -> V_56 ; ++ V_51 )
V_13 . V_57 [ V_51 ] = F_14 ( V_6 -> V_58 [ V_51 ] . V_59 )
+ V_46 -> V_60 [ V_51 ] ;
for ( V_51 = 0 ; V_51 < F_15 ( V_61 ) ; ++ V_51 ) {
if ( V_61 [ V_51 ] == V_6 -> V_30 -> V_62 ) {
V_13 . V_48 = V_63 [ V_51 ] ;
break;
}
}
F_16 ( V_43 -> V_41 -> V_41 , V_43 -> V_39 , & V_13 ) ;
}
static int F_17 ( struct V_64 * V_43 ,
struct V_65 * V_6 )
{
struct V_44 * V_66 = F_13 ( V_6 ) ;
struct V_67 * V_41 = F_18 ( V_43 ) -> V_41 ;
struct V_8 * V_9 = V_41 -> V_11 ;
unsigned int V_51 ;
int V_68 ;
if ( ! V_6 -> V_46 )
return 0 ;
for ( V_51 = 0 ; V_51 < V_66 -> V_30 -> V_56 ; ++ V_51 ) {
struct V_69 * V_70 =
F_19 ( V_6 -> V_46 , V_51 ) ;
struct V_71 * V_72 = & V_66 -> V_58 [ V_51 ] ;
V_68 = F_20 ( V_9 -> V_11 , V_72 , V_70 -> V_73 , V_70 -> V_74 ,
V_70 -> V_75 . V_76 ) ;
if ( V_68 )
goto V_77;
V_68 = F_21 ( V_41 -> V_41 , V_72 ) ;
if ( ! V_68 ) {
F_22 ( V_72 ) ;
V_68 = - V_78 ;
goto V_77;
}
}
return 0 ;
V_77:
while ( V_51 -- ) {
struct V_71 * V_72 = & V_66 -> V_58 [ V_51 ] ;
F_23 ( V_41 -> V_41 , V_72 ) ;
F_22 ( V_72 ) ;
}
return V_68 ;
}
static void F_24 ( struct V_64 * V_43 ,
struct V_65 * V_6 )
{
struct V_44 * V_66 = F_13 ( V_6 ) ;
struct V_67 * V_41 = F_18 ( V_43 ) -> V_41 ;
unsigned int V_51 ;
if ( ! V_6 -> V_46 )
return;
for ( V_51 = 0 ; V_51 < V_66 -> V_30 -> V_56 ; ++ V_51 ) {
struct V_71 * V_72 = & V_66 -> V_58 [ V_51 ] ;
F_23 ( V_41 -> V_41 , V_72 ) ;
F_22 ( V_72 ) ;
}
}
static int F_25 ( struct V_64 * V_43 ,
struct V_65 * V_6 )
{
struct V_44 * V_66 = F_13 ( V_6 ) ;
struct V_42 * V_79 = F_18 ( V_43 ) ;
struct V_8 * V_9 = V_79 -> V_41 -> V_11 ;
if ( ! V_6 -> V_46 || ! V_6 -> V_3 ) {
V_66 -> V_30 = NULL ;
return 0 ;
}
if ( V_6 -> V_27 >> 16 != V_6 -> V_23 ||
V_6 -> V_28 >> 16 != V_6 -> V_24 ) {
F_26 ( V_9 -> V_11 , L_1 , V_80 ) ;
return - V_81 ;
}
V_66 -> V_30 = F_4 ( V_6 -> V_46 -> V_30 -> V_30 ) ;
if ( V_66 -> V_30 == NULL ) {
F_26 ( V_9 -> V_11 , L_2 , V_80 ,
V_6 -> V_46 -> V_30 -> V_30 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_27 ( struct V_64 * V_43 ,
struct V_65 * V_82 )
{
struct V_42 * V_79 = F_18 ( V_43 ) ;
if ( V_43 -> V_6 -> V_3 )
F_12 ( V_79 ) ;
else
F_16 ( V_79 -> V_41 -> V_41 , V_79 -> V_39 , NULL ) ;
}
static struct V_65 *
F_28 ( struct V_64 * V_43 )
{
struct V_44 * V_6 ;
struct V_44 * V_83 ;
if ( F_29 ( ! V_43 -> V_6 ) )
return NULL ;
V_6 = F_13 ( V_43 -> V_6 ) ;
V_83 = F_30 ( V_6 , sizeof( * V_6 ) , V_84 ) ;
if ( V_83 == NULL )
return NULL ;
F_31 ( V_43 , & V_83 -> V_6 ) ;
return & V_83 -> V_6 ;
}
static void F_32 ( struct V_64 * V_43 ,
struct V_65 * V_6 )
{
F_33 ( V_6 ) ;
F_34 ( F_13 ( V_6 ) ) ;
}
static void F_35 ( struct V_64 * V_43 )
{
struct V_44 * V_6 ;
if ( V_43 -> V_6 ) {
F_32 ( V_43 , V_43 -> V_6 ) ;
V_43 -> V_6 = NULL ;
}
V_6 = F_36 ( sizeof( * V_6 ) , V_84 ) ;
if ( V_6 == NULL )
return;
V_6 -> V_34 = 255 ;
V_6 -> V_6 . V_29 = V_43 -> type == V_85 ? 0 : 1 ;
V_43 -> V_6 = & V_6 -> V_6 ;
V_43 -> V_6 -> V_43 = V_43 ;
}
static int F_37 ( struct V_64 * V_43 ,
struct V_65 * V_6 , struct V_86 * V_87 ,
T_1 V_88 )
{
struct V_44 * V_66 = F_13 ( V_6 ) ;
struct V_8 * V_9 = F_18 ( V_43 ) -> V_41 -> V_11 ;
if ( V_87 == V_9 -> V_89 . V_34 )
V_66 -> V_34 = V_88 ;
else
return - V_81 ;
return 0 ;
}
static int F_38 ( struct V_64 * V_43 ,
const struct V_65 * V_6 , struct V_86 * V_87 ,
T_1 * V_88 )
{
const struct V_44 * V_66 =
F_39 ( V_6 , const struct V_44 , V_6 ) ;
struct V_8 * V_9 = F_18 ( V_43 ) -> V_41 -> V_11 ;
if ( V_87 == V_9 -> V_89 . V_34 )
* V_88 = V_66 -> V_34 ;
else
return - V_81 ;
return 0 ;
}
int F_40 ( struct V_67 * V_41 )
{
struct V_8 * V_9 = V_41 -> V_11 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
unsigned int V_51 ;
int V_68 ;
V_93 = F_41 ( V_9 -> V_11 -> V_94 , L_3 , V_41 -> V_39 ) ;
if ( ! V_93 ) {
F_42 ( V_9 -> V_11 , L_4 ) ;
return - V_95 ;
}
V_91 = F_43 ( V_93 ) ;
F_44 ( V_93 ) ;
if ( ! V_91 )
return - V_95 ;
V_41 -> V_41 = & V_91 -> V_11 ;
V_68 = F_45 ( V_41 -> V_41 ) ;
if ( V_68 < 0 )
return V_68 ;
V_41 -> V_96 = V_9 -> V_36 -> V_37 >= 3 ? 5 : 4 ;
V_41 -> V_56 = F_46 ( V_9 -> V_11 , V_41 -> V_96 ,
sizeof( * V_41 -> V_56 ) , V_84 ) ;
if ( ! V_41 -> V_56 )
return - V_78 ;
for ( V_51 = 0 ; V_51 < V_41 -> V_96 ; ++ V_51 ) {
enum V_97 type = V_51 ? V_98
: V_85 ;
struct V_42 * V_43 = & V_41 -> V_56 [ V_51 ] ;
V_43 -> V_41 = V_41 ;
V_43 -> V_39 = V_51 ;
V_68 = F_47 ( V_9 -> V_99 , & V_43 -> V_43 ,
1 << V_41 -> V_39 ,
& V_100 ,
V_61 ,
F_15 ( V_61 ) , type ,
NULL ) ;
if ( V_68 < 0 )
return V_68 ;
F_48 ( & V_43 -> V_43 ,
& V_101 ) ;
if ( type == V_85 )
continue;
F_49 ( & V_43 -> V_43 . V_75 ,
V_9 -> V_89 . V_34 , 255 ) ;
F_50 ( & V_43 -> V_43 , 1 , 1 ,
V_41 -> V_96 - 1 ) ;
}
return 0 ;
}
