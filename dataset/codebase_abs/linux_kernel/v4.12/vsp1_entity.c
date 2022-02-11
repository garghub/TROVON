static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
void F_3 ( struct V_1 * V_3 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 ;
struct V_1 * V_10 ;
if ( V_3 -> type == V_11 ) {
T_1 V_12 ;
V_9 = F_1 ( V_3 -> V_13 [ 0 ] ) ;
V_12 = ( V_6 -> V_14 -> V_3 . V_15 << V_16 )
| ( V_9 -> V_17 -> V_14 << V_18 ) ;
F_4 ( V_8 , V_19 , V_12 ) ;
return;
} else if ( V_3 -> type == V_20 ) {
T_1 V_12 ;
V_9 = F_1 ( V_3 -> V_13 [ 0 ] ) ;
V_12 = ( V_6 -> V_14 -> V_3 . V_15 << V_16 )
| ( V_9 -> V_17 -> V_14 << V_18 ) ;
F_4 ( V_8 , V_21 , V_12 ) ;
return;
}
V_9 = V_3 ;
if ( V_9 -> V_17 -> V_22 == 0 )
return;
V_10 = F_1 ( V_9 -> V_10 ) ;
F_4 ( V_8 , V_9 -> V_17 -> V_22 ,
V_10 -> V_17 -> V_23 [ V_9 -> V_24 ] ) ;
}
struct V_25 *
F_5 ( struct V_1 * V_3 ,
struct V_25 * V_26 ,
enum V_27 V_28 )
{
switch ( V_28 ) {
case V_29 :
return V_3 -> V_30 ;
case V_31 :
default:
return V_26 ;
}
}
struct V_32 *
F_6 ( struct V_1 * V_3 ,
struct V_25 * V_26 ,
unsigned int V_33 )
{
return F_7 ( & V_3 -> V_4 , V_26 , V_33 ) ;
}
struct V_34 *
F_8 ( struct V_1 * V_3 ,
struct V_25 * V_26 ,
unsigned int V_33 , unsigned int V_35 )
{
switch ( V_35 ) {
case V_36 :
return F_9 ( & V_3 -> V_4 , V_26 , V_33 ) ;
case V_37 :
return F_10 ( & V_3 -> V_4 , V_26 , V_33 ) ;
default:
return NULL ;
}
}
int F_11 ( struct V_38 * V_4 ,
struct V_25 * V_26 )
{
struct V_39 V_40 ;
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < V_4 -> V_3 . V_41 - 1 ; ++ V_33 ) {
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_33 = V_33 ;
V_40 . V_28 = V_26 ? V_31
: V_29 ;
F_12 ( V_4 , V_33 , V_42 , V_26 , & V_40 ) ;
}
return 0 ;
}
int F_13 ( struct V_38 * V_4 ,
struct V_25 * V_26 ,
struct V_39 * V_43 )
{
struct V_1 * V_3 = F_14 ( V_4 ) ;
struct V_25 * V_30 ;
V_30 = F_5 ( V_3 , V_26 , V_43 -> V_28 ) ;
if ( ! V_30 )
return - V_44 ;
F_15 ( & V_3 -> V_45 ) ;
V_43 -> V_40 = * F_6 ( V_3 , V_30 , V_43 -> V_33 ) ;
F_16 ( & V_3 -> V_45 ) ;
return 0 ;
}
int F_17 ( struct V_38 * V_4 ,
struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned int * V_48 , unsigned int V_49 )
{
struct V_1 * V_3 = F_14 ( V_4 ) ;
if ( V_47 -> V_33 == 0 ) {
if ( V_47 -> V_15 >= V_49 )
return - V_44 ;
V_47 -> V_47 = V_48 [ V_47 -> V_15 ] ;
} else {
struct V_25 * V_30 ;
struct V_32 * V_40 ;
if ( V_47 -> V_15 )
return - V_44 ;
V_30 = F_5 ( V_3 , V_26 , V_47 -> V_28 ) ;
if ( ! V_30 )
return - V_44 ;
F_15 ( & V_3 -> V_45 ) ;
V_40 = F_6 ( V_3 , V_30 , 0 ) ;
V_47 -> V_47 = V_40 -> V_47 ;
F_16 ( & V_3 -> V_45 ) ;
}
return 0 ;
}
int F_18 ( struct V_38 * V_4 ,
struct V_25 * V_26 ,
struct V_50 * V_51 ,
unsigned int V_52 , unsigned int V_53 ,
unsigned int V_54 , unsigned int V_55 )
{
struct V_1 * V_3 = F_14 ( V_4 ) ;
struct V_25 * V_30 ;
struct V_32 * V_40 ;
int V_56 = 0 ;
V_30 = F_5 ( V_3 , V_26 , V_51 -> V_28 ) ;
if ( ! V_30 )
return - V_44 ;
V_40 = F_6 ( V_3 , V_30 , V_51 -> V_33 ) ;
F_15 ( & V_3 -> V_45 ) ;
if ( V_51 -> V_15 || V_51 -> V_47 != V_40 -> V_47 ) {
V_56 = - V_44 ;
goto V_57;
}
if ( V_51 -> V_33 == 0 ) {
V_51 -> V_52 = V_52 ;
V_51 -> V_54 = V_54 ;
V_51 -> V_53 = V_53 ;
V_51 -> V_55 = V_55 ;
} else {
V_51 -> V_52 = V_40 -> V_58 ;
V_51 -> V_54 = V_40 -> V_58 ;
V_51 -> V_53 = V_40 -> V_59 ;
V_51 -> V_55 = V_40 -> V_59 ;
}
V_57:
F_16 ( & V_3 -> V_45 ) ;
return V_56 ;
}
static int F_19 ( const struct V_60 * V_61 ,
const struct V_60 * V_24 ,
T_1 V_62 )
{
struct V_1 * V_9 ;
V_9 = F_1 ( V_61 -> V_3 ) ;
if ( ! V_9 -> V_17 )
return 0 ;
if ( V_62 & V_63 ) {
struct V_1 * V_10
= F_1 ( V_24 -> V_3 ) ;
if ( V_10 -> type != V_11 &&
V_10 -> type != V_20 ) {
if ( V_9 -> V_10 )
return - V_64 ;
V_9 -> V_10 = V_24 -> V_3 ;
V_9 -> V_24 = V_24 -> V_15 ;
}
} else {
V_9 -> V_10 = NULL ;
V_9 -> V_24 = 0 ;
}
return 0 ;
}
static int F_20 ( const struct V_60 * V_61 ,
const struct V_60 * V_24 ,
T_1 V_62 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_24 -> V_3 ) ;
if ( V_62 & V_63 ) {
if ( V_10 -> V_13 [ V_24 -> V_15 ] )
return - V_64 ;
V_10 -> V_13 [ V_24 -> V_15 ] = V_61 -> V_3 ;
} else {
V_10 -> V_13 [ V_24 -> V_15 ] = NULL ;
}
return 0 ;
}
int F_21 ( struct V_2 * V_3 ,
const struct V_60 * V_65 ,
const struct V_60 * V_66 , T_1 V_62 )
{
if ( V_65 -> V_62 & V_67 )
return F_19 ( V_65 , V_66 , V_62 ) ;
else
return F_20 ( V_66 , V_65 , V_62 ) ;
}
struct V_60 * F_22 ( struct V_60 * V_33 )
{
struct V_68 * V_69 ;
F_23 (link, &pad->entity->links, list) {
struct V_1 * V_3 ;
if ( ! ( V_69 -> V_62 & V_63 ) )
continue;
if ( V_69 -> V_10 == V_33 )
return V_69 -> V_9 ;
if ( V_69 -> V_9 != V_33 )
continue;
if ( ! F_24 ( V_69 -> V_10 -> V_3 ) )
return V_69 -> V_10 ;
V_3 = F_1 ( V_69 -> V_10 -> V_3 ) ;
if ( V_3 -> type != V_11 &&
V_3 -> type != V_20 )
return V_69 -> V_10 ;
}
return NULL ;
}
int F_25 ( struct V_70 * V_71 , struct V_1 * V_3 ,
const char * V_72 , unsigned int V_41 ,
const struct V_73 * V_74 , T_1 V_75 )
{
struct V_38 * V_4 ;
unsigned int V_76 ;
int V_56 ;
for ( V_76 = 0 ; V_76 < F_26 ( V_77 ) ; ++ V_76 ) {
if ( V_77 [ V_76 ] . type == V_3 -> type &&
V_77 [ V_76 ] . V_15 == V_3 -> V_15 ) {
V_3 -> V_17 = & V_77 [ V_76 ] ;
break;
}
}
if ( V_76 == F_26 ( V_77 ) )
return - V_44 ;
F_27 ( & V_3 -> V_45 ) ;
V_3 -> V_71 = V_71 ;
V_3 -> V_61 = V_41 - 1 ;
V_3 -> V_78 = F_28 ( V_71 -> V_79 , V_41 * sizeof( * V_3 -> V_78 ) ,
V_80 ) ;
if ( V_3 -> V_78 == NULL )
return - V_81 ;
for ( V_76 = 0 ; V_76 < V_41 - 1 ; ++ V_76 )
V_3 -> V_78 [ V_76 ] . V_62 = V_82 ;
V_3 -> V_13 = F_29 ( V_71 -> V_79 , F_30 ( V_41 - 1 , 1U ) ,
sizeof( * V_3 -> V_13 ) , V_80 ) ;
if ( V_3 -> V_13 == NULL )
return - V_81 ;
V_3 -> V_78 [ V_41 - 1 ] . V_62 = V_41 > 1 ? V_67
: V_82 ;
V_56 = F_31 ( & V_3 -> V_4 . V_3 , V_41 ,
V_3 -> V_78 ) ;
if ( V_56 < 0 )
return V_56 ;
V_4 = & V_3 -> V_4 ;
F_32 ( V_4 , V_74 ) ;
V_4 -> V_3 . V_75 = V_75 ;
V_4 -> V_3 . V_74 = & V_71 -> V_83 ;
V_4 -> V_62 |= V_84 ;
snprintf ( V_4 -> V_72 , sizeof( V_4 -> V_72 ) , L_1 ,
F_33 ( V_71 -> V_79 ) , V_72 ) ;
F_11 ( V_4 , NULL ) ;
V_3 -> V_30 = F_34 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_30 == NULL ) {
F_35 ( & V_3 -> V_4 . V_3 ) ;
return - V_81 ;
}
return 0 ;
}
void F_36 ( struct V_1 * V_3 )
{
if ( V_3 -> V_74 && V_3 -> V_74 -> V_85 )
V_3 -> V_74 -> V_85 ( V_3 ) ;
if ( V_3 -> V_4 . V_86 )
F_37 ( V_3 -> V_4 . V_86 ) ;
F_38 ( V_3 -> V_30 ) ;
F_35 ( & V_3 -> V_4 . V_3 ) ;
}
