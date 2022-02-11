void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_7 ;
T_1 V_8 ;
if ( V_2 -> type == V_9 ) {
T_1 V_10 ;
V_7 = V_2 -> V_11 [ 0 ] ;
V_10 = ( V_4 -> V_12 -> V_2 . V_13 << V_14 )
| ( V_7 -> V_8 -> V_12 << V_15 ) ;
F_2 ( V_6 , V_16 , V_10 ) ;
return;
} else if ( V_2 -> type == V_17 ) {
T_1 V_10 ;
V_7 = V_2 -> V_11 [ 0 ] ;
V_10 = ( V_4 -> V_12 -> V_2 . V_13 << V_14 )
| ( V_7 -> V_8 -> V_12 << V_15 ) ;
F_2 ( V_6 , V_18 , V_10 ) ;
return;
}
V_7 = V_2 ;
if ( V_7 -> V_8 -> V_19 == 0 )
return;
V_8 = V_7 -> V_20 -> V_8 -> V_21 [ V_7 -> V_22 ] ;
if ( V_7 -> type == V_23 )
V_8 |= V_24 ;
F_2 ( V_6 , V_7 -> V_8 -> V_19 , V_8 ) ;
}
struct V_25 *
F_3 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
enum V_27 V_28 )
{
switch ( V_28 ) {
case V_29 :
return V_2 -> V_30 ;
case V_31 :
default:
return V_26 ;
}
}
struct V_32 *
F_4 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
unsigned int V_33 )
{
return F_5 ( & V_2 -> V_34 , V_26 , V_33 ) ;
}
struct V_35 *
F_6 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
unsigned int V_33 , unsigned int V_36 )
{
switch ( V_36 ) {
case V_37 :
return F_7 ( & V_2 -> V_34 , V_26 , V_33 ) ;
case V_38 :
return F_8 ( & V_2 -> V_34 , V_26 , V_33 ) ;
default:
return NULL ;
}
}
int F_9 ( struct V_39 * V_34 ,
struct V_25 * V_26 )
{
struct V_40 V_41 ;
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 -> V_2 . V_42 - 1 ; ++ V_33 ) {
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_33 = V_33 ;
V_41 . V_28 = V_26 ? V_31
: V_29 ;
F_10 ( V_34 , V_33 , V_43 , V_26 , & V_41 ) ;
}
return 0 ;
}
int F_11 ( struct V_39 * V_34 ,
struct V_25 * V_26 ,
struct V_40 * V_44 )
{
struct V_1 * V_2 = F_12 ( V_34 ) ;
struct V_25 * V_30 ;
V_30 = F_3 ( V_2 , V_26 , V_44 -> V_28 ) ;
if ( ! V_30 )
return - V_45 ;
F_13 ( & V_2 -> V_46 ) ;
V_44 -> V_41 = * F_4 ( V_2 , V_30 , V_44 -> V_33 ) ;
F_14 ( & V_2 -> V_46 ) ;
return 0 ;
}
int F_15 ( struct V_39 * V_34 ,
struct V_25 * V_26 ,
struct V_47 * V_48 ,
const unsigned int * V_49 , unsigned int V_50 )
{
struct V_1 * V_2 = F_12 ( V_34 ) ;
if ( V_48 -> V_33 == 0 ) {
if ( V_48 -> V_13 >= V_50 )
return - V_45 ;
V_48 -> V_48 = V_49 [ V_48 -> V_13 ] ;
} else {
struct V_25 * V_30 ;
struct V_32 * V_41 ;
if ( V_48 -> V_13 )
return - V_45 ;
V_30 = F_3 ( V_2 , V_26 , V_48 -> V_28 ) ;
if ( ! V_30 )
return - V_45 ;
F_13 ( & V_2 -> V_46 ) ;
V_41 = F_4 ( V_2 , V_30 , 0 ) ;
V_48 -> V_48 = V_41 -> V_48 ;
F_14 ( & V_2 -> V_46 ) ;
}
return 0 ;
}
int F_16 ( struct V_39 * V_34 ,
struct V_25 * V_26 ,
struct V_51 * V_52 ,
unsigned int V_53 , unsigned int V_54 ,
unsigned int V_55 , unsigned int V_56 )
{
struct V_1 * V_2 = F_12 ( V_34 ) ;
struct V_25 * V_30 ;
struct V_32 * V_41 ;
int V_57 = 0 ;
V_30 = F_3 ( V_2 , V_26 , V_52 -> V_28 ) ;
if ( ! V_30 )
return - V_45 ;
V_41 = F_4 ( V_2 , V_30 , V_52 -> V_33 ) ;
F_13 ( & V_2 -> V_46 ) ;
if ( V_52 -> V_13 || V_52 -> V_48 != V_41 -> V_48 ) {
V_57 = - V_45 ;
goto V_58;
}
if ( V_52 -> V_33 == 0 ) {
V_52 -> V_53 = V_53 ;
V_52 -> V_55 = V_55 ;
V_52 -> V_54 = V_54 ;
V_52 -> V_56 = V_56 ;
} else {
V_52 -> V_53 = V_41 -> V_59 ;
V_52 -> V_55 = V_41 -> V_59 ;
V_52 -> V_54 = V_41 -> V_60 ;
V_52 -> V_56 = V_41 -> V_60 ;
}
V_58:
F_14 ( & V_2 -> V_46 ) ;
return V_57 ;
}
static inline struct V_1 *
F_17 ( struct V_61 * V_2 )
{
return F_18 ( V_2 , struct V_1 , V_34 . V_2 ) ;
}
static int F_19 ( const struct V_62 * V_63 ,
const struct V_62 * V_22 ,
T_1 V_64 )
{
struct V_1 * V_7 ;
V_7 = F_17 ( V_63 -> V_2 ) ;
if ( ! V_7 -> V_8 )
return 0 ;
if ( V_64 & V_65 ) {
struct V_1 * V_20
= F_17 ( V_22 -> V_2 ) ;
if ( V_20 -> type != V_9 &&
V_20 -> type != V_17 ) {
if ( V_7 -> V_20 )
return - V_66 ;
V_7 -> V_20 = V_20 ;
V_7 -> V_22 = V_22 -> V_13 ;
}
} else {
V_7 -> V_20 = NULL ;
V_7 -> V_22 = 0 ;
}
return 0 ;
}
static int F_20 ( const struct V_62 * V_63 ,
const struct V_62 * V_22 ,
T_1 V_64 )
{
struct V_1 * V_20 ;
struct V_1 * V_7 ;
V_20 = F_17 ( V_22 -> V_2 ) ;
V_7 = F_17 ( V_63 -> V_2 ) ;
if ( V_64 & V_65 ) {
if ( V_20 -> V_11 [ V_22 -> V_13 ] )
return - V_66 ;
V_20 -> V_11 [ V_22 -> V_13 ] = V_7 ;
} else {
V_20 -> V_11 [ V_22 -> V_13 ] = NULL ;
}
return 0 ;
}
int F_21 ( struct V_61 * V_2 ,
const struct V_62 * V_67 ,
const struct V_62 * V_68 , T_1 V_64 )
{
if ( V_67 -> V_64 & V_69 )
return F_19 ( V_67 , V_68 , V_64 ) ;
else
return F_20 ( V_68 , V_67 , V_64 ) ;
}
struct V_62 * F_22 ( struct V_62 * V_33 )
{
struct V_70 * V_71 ;
F_23 (link, &pad->entity->links, list) {
struct V_1 * V_2 ;
if ( ! ( V_71 -> V_64 & V_65 ) )
continue;
if ( V_71 -> V_20 == V_33 )
return V_71 -> V_7 ;
if ( V_71 -> V_7 != V_33 )
continue;
if ( ! F_24 ( V_71 -> V_20 -> V_2 ) )
return V_71 -> V_20 ;
V_2 = F_17 ( V_71 -> V_20 -> V_2 ) ;
if ( V_2 -> type != V_9 &&
V_2 -> type != V_17 )
return V_71 -> V_20 ;
}
return NULL ;
}
int F_25 ( struct V_72 * V_73 , struct V_1 * V_2 ,
const char * V_74 , unsigned int V_42 ,
const struct V_75 * V_76 , T_1 V_77 )
{
struct V_39 * V_34 ;
unsigned int V_78 ;
int V_57 ;
for ( V_78 = 0 ; V_78 < F_26 ( V_79 ) ; ++ V_78 ) {
if ( V_79 [ V_78 ] . type == V_2 -> type &&
V_79 [ V_78 ] . V_13 == V_2 -> V_13 ) {
V_2 -> V_8 = & V_79 [ V_78 ] ;
break;
}
}
if ( V_78 == F_26 ( V_79 ) )
return - V_45 ;
F_27 ( & V_2 -> V_46 ) ;
V_2 -> V_73 = V_73 ;
V_2 -> V_63 = V_42 - 1 ;
V_2 -> V_80 = F_28 ( V_73 -> V_81 , V_42 * sizeof( * V_2 -> V_80 ) ,
V_82 ) ;
if ( V_2 -> V_80 == NULL )
return - V_83 ;
for ( V_78 = 0 ; V_78 < V_42 - 1 ; ++ V_78 )
V_2 -> V_80 [ V_78 ] . V_64 = V_84 ;
V_2 -> V_11 = F_29 ( V_73 -> V_81 , F_30 ( V_42 - 1 , 1U ) ,
sizeof( * V_2 -> V_11 ) , V_82 ) ;
if ( V_2 -> V_11 == NULL )
return - V_83 ;
V_2 -> V_80 [ V_42 - 1 ] . V_64 = V_42 > 1 ? V_69
: V_84 ;
V_57 = F_31 ( & V_2 -> V_34 . V_2 , V_42 ,
V_2 -> V_80 ) ;
if ( V_57 < 0 )
return V_57 ;
V_34 = & V_2 -> V_34 ;
F_32 ( V_34 , V_76 ) ;
V_34 -> V_2 . V_77 = V_77 ;
V_34 -> V_2 . V_76 = & V_73 -> V_85 ;
V_34 -> V_64 |= V_86 ;
snprintf ( V_34 -> V_74 , sizeof( V_34 -> V_74 ) , L_1 ,
F_33 ( V_73 -> V_81 ) , V_74 ) ;
F_9 ( V_34 , NULL ) ;
V_2 -> V_30 = F_34 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_30 == NULL ) {
F_35 ( & V_2 -> V_34 . V_2 ) ;
return - V_83 ;
}
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_76 && V_2 -> V_76 -> V_87 )
V_2 -> V_76 -> V_87 ( V_2 ) ;
if ( V_2 -> V_34 . V_88 )
F_37 ( V_2 -> V_34 . V_88 ) ;
F_38 ( V_2 -> V_30 ) ;
F_35 ( & V_2 -> V_34 . V_2 ) ;
}
