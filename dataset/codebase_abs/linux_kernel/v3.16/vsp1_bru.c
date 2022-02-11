static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_2 -> V_4 . V_5 , V_3 , V_6 ) ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_7 )
{
return F_6 ( & V_2 -> V_4 . V_8 [ V_7 ] ) != NULL ;
}
static int F_7 ( struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
struct V_12 * V_13 ;
unsigned int V_14 ;
if ( ! V_11 )
return 0 ;
V_13 = & V_2 -> V_4 . V_15 [ V_16 ] ;
F_3 ( V_2 , V_17 , 0 ) ;
F_3 ( V_2 , V_18 ,
( V_13 -> V_19 << V_20 ) |
( V_13 -> V_21 << V_22 ) ) ;
F_3 ( V_2 , V_23 , 0 ) ;
F_3 ( V_2 , V_24 ,
0xff << V_25 ) ;
F_3 ( V_2 , V_26 , F_9 ( 1 ) |
F_10 ( V_27 ) |
F_11 ( V_27 ) ) ;
for ( V_14 = 0 ; V_14 < 4 ; ++ V_14 ) {
T_1 V_28 = 0 ;
if ( F_5 ( V_2 , V_14 ) )
V_28 |= V_29 ;
else
V_28 |= F_12 ( V_27 )
| F_13 ( V_27 ) ;
if ( V_14 == 0 )
V_28 |= V_30 ;
if ( V_14 != 1 )
V_28 |= F_14 ( V_14 ) ;
F_3 ( V_2 , F_15 ( V_14 ) , V_28 ) ;
F_3 ( V_2 , F_16 ( V_14 ) ,
V_31 |
V_32 |
V_33 |
V_34 |
( 0xff << V_35 ) ) ;
}
return 0 ;
}
static int F_17 ( struct V_9 * V_10 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
static const unsigned int V_40 [] = {
V_41 ,
V_42 ,
} ;
struct V_12 * V_13 ;
if ( V_39 -> V_43 == F_18 ( 0 ) ) {
if ( V_39 -> V_44 >= F_19 ( V_40 ) )
return - V_45 ;
V_39 -> V_39 = V_40 [ V_39 -> V_44 ] ;
} else {
if ( V_39 -> V_44 )
return - V_45 ;
V_13 = F_20 ( V_37 , F_18 ( 0 ) ) ;
V_39 -> V_39 = V_13 -> V_39 ;
}
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
struct V_36 * V_37 ,
struct V_46 * V_47 )
{
if ( V_47 -> V_44 )
return - V_45 ;
if ( V_47 -> V_39 != V_41 &&
V_47 -> V_39 != V_42 )
return - V_45 ;
V_47 -> V_48 = V_49 ;
V_47 -> V_50 = V_51 ;
V_47 -> V_52 = V_49 ;
V_47 -> V_53 = V_51 ;
return 0 ;
}
static struct V_54 * F_22 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
unsigned int V_43 , T_1 V_55 )
{
switch ( V_55 ) {
case V_56 :
return F_23 ( V_37 , V_43 ) ;
case V_57 :
return & V_2 -> V_58 [ V_43 ] ;
default:
return NULL ;
}
}
static int F_24 ( struct V_9 * V_10 , struct V_36 * V_37 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
V_60 -> V_13 = * F_25 ( & V_2 -> V_4 , V_37 , V_60 -> V_43 ,
V_60 -> V_55 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_36 * V_37 ,
unsigned int V_43 , struct V_12 * V_60 ,
enum V_61 V_55 )
{
struct V_12 * V_13 ;
switch ( V_43 ) {
case F_18 ( 0 ) :
if ( V_60 -> V_39 != V_41 &&
V_60 -> V_39 != V_42 )
V_60 -> V_39 = V_42 ;
break;
default:
V_13 = F_25 ( & V_2 -> V_4 , V_37 ,
F_18 ( 0 ) , V_55 ) ;
V_60 -> V_39 = V_13 -> V_39 ;
break;
}
V_60 -> V_19 = F_27 ( V_60 -> V_19 , V_49 , V_51 ) ;
V_60 -> V_21 = F_27 ( V_60 -> V_21 , V_49 , V_51 ) ;
V_60 -> V_62 = V_63 ;
V_60 -> V_64 = V_65 ;
}
static int F_28 ( struct V_9 * V_10 , struct V_36 * V_37 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
struct V_12 * V_13 ;
F_26 ( V_2 , V_37 , V_60 -> V_43 , & V_60 -> V_13 , V_60 -> V_55 ) ;
V_13 = F_25 ( & V_2 -> V_4 , V_37 , V_60 -> V_43 ,
V_60 -> V_55 ) ;
* V_13 = V_60 -> V_13 ;
if ( V_60 -> V_43 != V_16 ) {
struct V_54 * V_58 ;
V_58 = F_22 ( V_2 , V_37 , V_60 -> V_43 , V_60 -> V_55 ) ;
V_58 -> V_66 = 0 ;
V_58 -> V_67 = 0 ;
V_58 -> V_19 = V_13 -> V_19 ;
V_58 -> V_21 = V_13 -> V_21 ;
}
if ( V_60 -> V_43 == F_18 ( 0 ) ) {
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 <= V_16 ; ++ V_14 ) {
V_13 = F_25 ( & V_2 -> V_4 , V_37 ,
V_14 , V_60 -> V_55 ) ;
V_13 -> V_39 = V_60 -> V_13 . V_39 ;
}
}
return 0 ;
}
static int F_29 ( struct V_9 * V_10 ,
struct V_36 * V_37 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
if ( V_69 -> V_43 == V_16 )
return - V_45 ;
switch ( V_69 -> V_70 ) {
case V_71 :
V_69 -> V_72 . V_66 = 0 ;
V_69 -> V_72 . V_67 = 0 ;
V_69 -> V_72 . V_19 = V_51 ;
V_69 -> V_72 . V_21 = V_51 ;
return 0 ;
case V_73 :
V_69 -> V_72 = * F_22 ( V_2 , V_37 , V_69 -> V_43 , V_69 -> V_55 ) ;
return 0 ;
default:
return - V_45 ;
}
}
static int F_30 ( struct V_9 * V_10 ,
struct V_36 * V_37 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
struct V_12 * V_13 ;
struct V_54 * V_58 ;
if ( V_69 -> V_43 == V_16 )
return - V_45 ;
if ( V_69 -> V_70 != V_73 )
return - V_45 ;
V_13 = F_25 ( & V_2 -> V_4 , V_37 , V_16 ,
V_69 -> V_55 ) ;
V_69 -> V_72 . V_66 = F_31 (unsigned int, sel->r.left, 0 , format->width - 1 ) ;
V_69 -> V_72 . V_67 = F_31 (unsigned int, sel->r.top, 0 , format->height - 1 ) ;
V_13 = F_25 ( & V_2 -> V_4 , V_37 , V_69 -> V_43 ,
V_69 -> V_55 ) ;
V_69 -> V_72 . V_19 = V_13 -> V_19 ;
V_69 -> V_72 . V_21 = V_13 -> V_21 ;
V_58 = F_22 ( V_2 , V_37 , V_69 -> V_43 , V_69 -> V_55 ) ;
* V_58 = V_69 -> V_72 ;
return 0 ;
}
struct V_1 * F_32 ( struct V_74 * V_5 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
int V_75 ;
V_2 = F_33 ( V_5 -> V_76 , sizeof( * V_2 ) , V_77 ) ;
if ( V_2 == NULL )
return F_34 ( - V_78 ) ;
V_2 -> V_4 . type = V_79 ;
V_75 = F_35 ( V_5 , & V_2 -> V_4 , 5 ) ;
if ( V_75 < 0 )
return F_34 ( V_75 ) ;
V_10 = & V_2 -> V_4 . V_10 ;
F_36 ( V_10 , & V_80 ) ;
V_10 -> V_4 . V_81 = & V_82 ;
V_10 -> V_83 = & V_84 ;
snprintf ( V_10 -> V_85 , sizeof( V_10 -> V_85 ) , L_1 ,
F_37 ( V_5 -> V_76 ) ) ;
F_38 ( V_10 , V_2 ) ;
V_10 -> V_86 |= V_87 ;
F_39 ( V_10 , NULL ) ;
return V_2 ;
}
