static void F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_5 )
F_2 ( & V_4 -> V_4 ) ;
if ( V_2 )
F_3 ( V_4 ) ;
}
void F_4 ( struct V_3 * V_4 )
{
const struct V_6 * V_7 = & V_4 -> V_4 . V_8 -> V_9 ;
struct V_10 * V_11 = V_4 -> V_12 -> V_13 ;
struct V_14 V_15 = {
. V_16 = V_7 -> V_17 ,
. V_18 = V_7 -> V_19 ,
. V_20 = F_1 ,
. V_21 = V_4 ,
} ;
struct V_22 V_8 = {
. V_8 = {
. V_4 = & V_4 -> V_4 ,
. V_23 = 0 ,
. V_24 = 0 ,
. V_25 = V_7 -> V_17 ,
. V_26 = V_7 -> V_19 ,
. V_27 = 0 ,
. V_28 = 0 ,
. V_29 = V_7 -> V_17 << 16 ,
. V_30 = V_7 -> V_19 << 16 ,
. V_31 = 0 ,
} ,
. V_32 = F_5 ( V_33 ) ,
. V_34 = V_35 ,
. V_36 = 255 ,
. V_37 = 0 ,
} ;
if ( V_11 -> V_38 -> V_39 >= 3 )
V_8 . V_40 = ( V_4 -> V_41 % 2 ) ? 2 : 0 ;
else
V_8 . V_40 = V_4 -> V_41 % 2 ;
F_6 ( V_4 -> V_12 , & V_8 ) ;
V_4 -> V_12 -> V_42 = true ;
F_7 ( V_4 -> V_43 -> V_43 , V_4 -> V_44 , & V_15 ) ;
}
void F_8 ( struct V_3 * V_4 )
{
F_7 ( V_4 -> V_43 -> V_43 , V_4 -> V_44 , NULL ) ;
}
void F_9 ( struct V_3 * V_4 )
{
F_10 ( V_4 -> V_43 -> V_43 , V_4 -> V_44 ) ;
}
void F_11 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_43 -> V_43 , V_4 -> V_44 ) ;
}
static void F_13 ( struct V_45 * V_46 )
{
struct V_47 * V_8 =
F_14 ( V_46 -> V_46 . V_8 ) ;
struct V_3 * V_4 = F_15 ( V_8 -> V_8 . V_4 ) ;
struct V_48 * V_49 = V_46 -> V_46 . V_8 -> V_49 ;
struct V_50 V_15 = {
. V_51 = 0 ,
. V_52 = V_49 -> V_53 [ 0 ] ,
. V_36 = V_8 -> V_36 ,
. V_31 = V_8 -> V_8 . V_31 ,
} ;
unsigned int V_54 ;
V_15 . V_55 . V_56 = V_8 -> V_8 . V_27 >> 16 ;
V_15 . V_55 . V_57 = V_8 -> V_8 . V_28 >> 16 ;
V_15 . V_55 . V_16 = V_8 -> V_8 . V_29 >> 16 ;
V_15 . V_55 . V_18 = V_8 -> V_8 . V_30 >> 16 ;
V_15 . V_58 . V_56 = V_8 -> V_8 . V_23 ;
V_15 . V_58 . V_57 = V_8 -> V_8 . V_24 ;
V_15 . V_58 . V_16 = V_8 -> V_8 . V_25 ;
V_15 . V_58 . V_18 = V_8 -> V_8 . V_26 ;
for ( V_54 = 0 ; V_54 < V_8 -> V_32 -> V_59 ; ++ V_54 )
V_15 . V_60 [ V_54 ] = F_16 ( V_8 -> V_61 [ V_54 ] . V_62 )
+ V_49 -> V_63 [ V_54 ] ;
for ( V_54 = 0 ; V_54 < F_17 ( V_64 ) ; ++ V_54 ) {
if ( V_64 [ V_54 ] == V_8 -> V_32 -> V_65 ) {
V_15 . V_51 = V_66 [ V_54 ] ;
break;
}
}
F_18 ( V_46 -> V_43 -> V_43 , V_4 -> V_44 ,
V_46 -> V_41 , & V_15 ) ;
}
static int F_19 ( struct V_67 * V_46 ,
struct V_68 * V_8 )
{
struct V_47 * V_69 = F_14 ( V_8 ) ;
struct V_70 * V_43 = F_20 ( V_46 ) -> V_43 ;
struct V_10 * V_11 = V_43 -> V_13 ;
unsigned int V_54 ;
int V_71 ;
if ( ! V_8 -> V_49 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_69 -> V_32 -> V_59 ; ++ V_54 ) {
struct V_72 * V_73 =
F_21 ( V_8 -> V_49 , V_54 ) ;
struct V_74 * V_75 = & V_69 -> V_61 [ V_54 ] ;
V_71 = F_22 ( V_11 -> V_13 , V_75 , V_73 -> V_76 , V_73 -> V_77 ,
V_73 -> V_78 . V_79 ) ;
if ( V_71 )
goto V_80;
V_71 = F_23 ( V_43 -> V_43 , V_75 ) ;
if ( ! V_71 ) {
F_24 ( V_75 ) ;
V_71 = - V_81 ;
goto V_80;
}
}
return 0 ;
V_80:
while ( V_54 -- ) {
struct V_74 * V_75 = & V_69 -> V_61 [ V_54 ] ;
F_25 ( V_43 -> V_43 , V_75 ) ;
F_24 ( V_75 ) ;
}
return V_71 ;
}
static void F_26 ( struct V_67 * V_46 ,
struct V_68 * V_8 )
{
struct V_47 * V_69 = F_14 ( V_8 ) ;
struct V_70 * V_43 = F_20 ( V_46 ) -> V_43 ;
unsigned int V_54 ;
if ( ! V_8 -> V_49 )
return;
for ( V_54 = 0 ; V_54 < V_69 -> V_32 -> V_59 ; ++ V_54 ) {
struct V_74 * V_75 = & V_69 -> V_61 [ V_54 ] ;
F_25 ( V_43 -> V_43 , V_75 ) ;
F_24 ( V_75 ) ;
}
}
static int F_27 ( struct V_67 * V_46 ,
struct V_68 * V_8 )
{
struct V_47 * V_69 = F_14 ( V_8 ) ;
struct V_45 * V_82 = F_20 ( V_46 ) ;
struct V_10 * V_11 = V_82 -> V_43 -> V_13 ;
if ( ! V_8 -> V_49 || ! V_8 -> V_4 ) {
V_69 -> V_32 = NULL ;
return 0 ;
}
if ( V_8 -> V_29 >> 16 != V_8 -> V_25 ||
V_8 -> V_30 >> 16 != V_8 -> V_26 ) {
F_28 ( V_11 -> V_13 , L_1 , V_83 ) ;
return - V_84 ;
}
V_69 -> V_32 = F_5 ( V_8 -> V_49 -> V_32 -> V_32 ) ;
if ( V_69 -> V_32 == NULL ) {
F_28 ( V_11 -> V_13 , L_2 , V_83 ,
V_8 -> V_49 -> V_32 -> V_32 ) ;
return - V_84 ;
}
return 0 ;
}
static void F_29 ( struct V_67 * V_46 ,
struct V_68 * V_85 )
{
struct V_45 * V_82 = F_20 ( V_46 ) ;
struct V_3 * V_4 = F_15 ( V_85 -> V_4 ) ;
if ( V_46 -> V_8 -> V_4 )
F_13 ( V_82 ) ;
else
F_18 ( V_82 -> V_43 -> V_43 , V_4 -> V_44 ,
V_82 -> V_41 , NULL ) ;
}
static struct V_68 *
F_30 ( struct V_67 * V_46 )
{
struct V_47 * V_8 ;
struct V_47 * V_86 ;
if ( F_31 ( ! V_46 -> V_8 ) )
return NULL ;
V_8 = F_14 ( V_46 -> V_8 ) ;
V_86 = F_32 ( V_8 , sizeof( * V_8 ) , V_87 ) ;
if ( V_86 == NULL )
return NULL ;
F_33 ( V_46 , & V_86 -> V_8 ) ;
return & V_86 -> V_8 ;
}
static void F_34 ( struct V_67 * V_46 ,
struct V_68 * V_8 )
{
F_35 ( V_8 ) ;
F_36 ( F_14 ( V_8 ) ) ;
}
static void F_37 ( struct V_67 * V_46 )
{
struct V_47 * V_8 ;
if ( V_46 -> V_8 ) {
F_34 ( V_46 , V_46 -> V_8 ) ;
V_46 -> V_8 = NULL ;
}
V_8 = F_38 ( sizeof( * V_8 ) , V_87 ) ;
if ( V_8 == NULL )
return;
V_8 -> V_36 = 255 ;
V_8 -> V_8 . V_31 = V_46 -> type == V_88 ? 0 : 1 ;
V_46 -> V_8 = & V_8 -> V_8 ;
V_46 -> V_8 -> V_46 = V_46 ;
}
static int F_39 ( struct V_67 * V_46 ,
struct V_68 * V_8 , struct V_89 * V_90 ,
T_1 V_91 )
{
struct V_47 * V_69 = F_14 ( V_8 ) ;
struct V_10 * V_11 = F_20 ( V_46 ) -> V_43 -> V_13 ;
if ( V_90 == V_11 -> V_92 . V_36 )
V_69 -> V_36 = V_91 ;
else
return - V_84 ;
return 0 ;
}
static int F_40 ( struct V_67 * V_46 ,
const struct V_68 * V_8 , struct V_89 * V_90 ,
T_1 * V_91 )
{
const struct V_47 * V_69 =
F_41 ( V_8 , const struct V_47 , V_8 ) ;
struct V_10 * V_11 = F_20 ( V_46 ) -> V_43 -> V_13 ;
if ( V_90 == V_11 -> V_92 . V_36 )
* V_91 = V_69 -> V_36 ;
else
return - V_84 ;
return 0 ;
}
int F_42 ( struct V_70 * V_43 , struct V_93 * V_94 ,
unsigned int V_95 )
{
struct V_10 * V_11 = V_43 -> V_13 ;
struct V_96 * V_97 ;
unsigned int V_98 = F_43 ( V_95 ) ;
unsigned int V_54 ;
int V_71 ;
V_97 = F_44 ( V_94 ) ;
if ( ! V_97 )
return - V_99 ;
V_43 -> V_43 = & V_97 -> V_13 ;
V_71 = F_45 ( V_43 -> V_43 ) ;
if ( V_71 < 0 )
return V_71 ;
V_43 -> V_100 = V_11 -> V_38 -> V_39 >= 3 ? 5 : 4 ;
V_43 -> V_59 = F_46 ( V_11 -> V_13 , V_43 -> V_100 ,
sizeof( * V_43 -> V_59 ) , V_87 ) ;
if ( ! V_43 -> V_59 )
return - V_81 ;
for ( V_54 = 0 ; V_54 < V_43 -> V_100 ; ++ V_54 ) {
enum V_101 type = V_54 < V_98
? V_88
: V_102 ;
struct V_45 * V_46 = & V_43 -> V_59 [ V_54 ] ;
V_46 -> V_43 = V_43 ;
V_46 -> V_41 = V_54 ;
V_71 = F_47 ( V_11 -> V_103 , & V_46 -> V_46 , V_95 ,
& V_104 ,
V_64 ,
F_17 ( V_64 ) ,
NULL , type , NULL ) ;
if ( V_71 < 0 )
return V_71 ;
F_48 ( & V_46 -> V_46 ,
& V_105 ) ;
if ( type == V_88 )
continue;
F_49 ( & V_46 -> V_46 . V_78 ,
V_11 -> V_92 . V_36 , 255 ) ;
F_50 ( & V_46 -> V_46 , 1 , 1 ,
V_43 -> V_100 - 1 ) ;
}
return 0 ;
}
