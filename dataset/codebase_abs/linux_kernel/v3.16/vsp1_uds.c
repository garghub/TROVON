static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 ,
V_3 + V_2 -> V_4 . V_6 * V_7 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
F_4 ( V_2 -> V_4 . V_5 ,
V_3 + V_2 -> V_4 . V_6 * V_7 , V_8 ) ;
}
static unsigned int F_5 ( unsigned int V_9 , unsigned int V_10 )
{
if ( V_10 > 4096 ) {
unsigned int V_11 ;
V_11 = V_10 / 4096 ;
V_11 = V_11 < 4 ? 1 : ( V_11 < 8 ? 2 : 4 ) ;
return ( V_9 - 1 ) / V_11 * V_11 * 4096 / V_10 + 1 ;
} else {
return ( V_9 - 1 ) * 4096 / V_10 + 1 ;
}
}
static void F_6 ( unsigned int V_9 ,
unsigned int * V_12 , unsigned int * V_13 )
{
* V_12 = F_7 ( F_5 ( V_9 , V_14 ) , V_15 ) ;
* V_13 = F_8 ( F_5 ( V_9 , V_16 ) , V_17 ) ;
}
static unsigned int F_9 ( unsigned int V_10 )
{
if ( V_10 >= 4096 ) {
unsigned int V_11 ;
V_11 = V_10 / 4096 ;
V_11 = V_11 < 4 ? 1 : ( V_11 < 8 ? 2 : 4 ) ;
return 64 * 4096 * V_11 / V_10 ;
} else {
return 64 ;
}
}
static unsigned int F_10 ( unsigned int V_9 , unsigned int V_18 )
{
return ( V_9 - 1 ) * 4096 / ( V_18 - 1 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = & V_2 -> V_4 . V_20 [ V_21 ] ;
struct V_19 * V_18 =
& V_2 -> V_4 . V_20 [ V_22 ] ;
V_2 -> V_23 = F_10 ( V_9 -> V_24 , V_18 -> V_24 ) ;
V_2 -> V_25 = F_10 ( V_9 -> V_26 , V_18 -> V_26 ) ;
F_12 ( V_2 -> V_4 . V_5 -> V_27 , L_1 ,
V_2 -> V_23 , V_2 -> V_25 ) ;
}
static int F_13 ( struct V_28 * V_29 , int V_30 )
{
const struct V_19 * V_31 ;
struct V_1 * V_2 = F_14 ( V_29 ) ;
if ( ! V_30 )
return 0 ;
F_3 ( V_2 , V_32 , V_33 | V_34 ) ;
F_3 ( V_2 , V_35 ,
( F_9 ( V_2 -> V_23 )
<< V_36 ) |
( F_9 ( V_2 -> V_25 )
<< V_37 ) ) ;
V_31 = & V_2 -> V_4 . V_20 [ V_22 ] ;
F_3 ( V_2 , V_38 ,
( V_2 -> V_23 << V_39 ) |
( V_2 -> V_25 << V_40 ) ) ;
F_3 ( V_2 , V_41 ,
( V_31 -> V_24 << V_42 ) |
( V_31 -> V_26 << V_43 ) ) ;
return 0 ;
}
static int F_15 ( struct V_28 * V_29 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
static const unsigned int V_48 [] = {
V_49 ,
V_50 ,
} ;
if ( V_47 -> V_51 == V_21 ) {
if ( V_47 -> V_6 >= F_16 ( V_48 ) )
return - V_52 ;
V_47 -> V_47 = V_48 [ V_47 -> V_6 ] ;
} else {
struct V_19 * V_31 ;
if ( V_47 -> V_6 )
return - V_52 ;
V_31 = F_17 ( V_45 , V_21 ) ;
V_47 -> V_47 = V_31 -> V_47 ;
}
return 0 ;
}
static int F_18 ( struct V_28 * V_29 ,
struct V_44 * V_45 ,
struct V_53 * V_54 )
{
struct V_19 * V_31 ;
V_31 = F_17 ( V_45 , V_21 ) ;
if ( V_54 -> V_6 || V_54 -> V_47 != V_31 -> V_47 )
return - V_52 ;
if ( V_54 -> V_51 == V_21 ) {
V_54 -> V_55 = V_15 ;
V_54 -> V_56 = V_17 ;
V_54 -> V_57 = V_15 ;
V_54 -> V_58 = V_17 ;
} else {
F_6 ( V_31 -> V_24 , & V_54 -> V_55 ,
& V_54 -> V_56 ) ;
F_6 ( V_31 -> V_26 , & V_54 -> V_57 ,
& V_54 -> V_58 ) ;
}
return 0 ;
}
static int F_19 ( struct V_28 * V_29 , struct V_44 * V_45 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
V_60 -> V_31 = * F_20 ( & V_2 -> V_4 , V_45 , V_60 -> V_51 ,
V_60 -> V_61 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_44 * V_45 ,
unsigned int V_51 , struct V_19 * V_60 ,
enum V_62 V_61 )
{
struct V_19 * V_31 ;
unsigned int V_12 ;
unsigned int V_13 ;
switch ( V_51 ) {
case V_21 :
if ( V_60 -> V_47 != V_49 &&
V_60 -> V_47 != V_50 )
V_60 -> V_47 = V_50 ;
V_60 -> V_24 = F_22 ( V_60 -> V_24 , V_15 , V_17 ) ;
V_60 -> V_26 = F_22 ( V_60 -> V_26 , V_15 , V_17 ) ;
break;
case V_22 :
V_31 = F_20 ( & V_2 -> V_4 , V_45 ,
V_21 , V_61 ) ;
V_60 -> V_47 = V_31 -> V_47 ;
F_6 ( V_31 -> V_24 , & V_12 , & V_13 ) ;
V_60 -> V_24 = F_22 ( V_60 -> V_24 , V_12 , V_13 ) ;
F_6 ( V_31 -> V_26 , & V_12 , & V_13 ) ;
V_60 -> V_26 = F_22 ( V_60 -> V_26 , V_12 , V_13 ) ;
break;
}
V_60 -> V_63 = V_64 ;
V_60 -> V_65 = V_66 ;
}
static int F_23 ( struct V_28 * V_29 , struct V_44 * V_45 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
struct V_19 * V_31 ;
F_21 ( V_2 , V_45 , V_60 -> V_51 , & V_60 -> V_31 , V_60 -> V_61 ) ;
V_31 = F_20 ( & V_2 -> V_4 , V_45 , V_60 -> V_51 ,
V_60 -> V_61 ) ;
* V_31 = V_60 -> V_31 ;
if ( V_60 -> V_51 == V_21 ) {
V_31 = F_20 ( & V_2 -> V_4 , V_45 ,
V_22 , V_60 -> V_61 ) ;
* V_31 = V_60 -> V_31 ;
F_21 ( V_2 , V_45 , V_22 , V_31 , V_60 -> V_61 ) ;
}
if ( V_60 -> V_61 == V_67 )
F_11 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_24 ( struct V_68 * V_5 , unsigned int V_6 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 ;
int V_69 ;
V_2 = F_25 ( V_5 -> V_27 , sizeof( * V_2 ) , V_70 ) ;
if ( V_2 == NULL )
return F_26 ( - V_71 ) ;
V_2 -> V_4 . type = V_72 ;
V_2 -> V_4 . V_6 = V_6 ;
V_69 = F_27 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_69 < 0 )
return F_26 ( V_69 ) ;
V_29 = & V_2 -> V_4 . V_29 ;
F_28 ( V_29 , & V_73 ) ;
V_29 -> V_4 . V_74 = & V_75 ;
V_29 -> V_76 = & V_77 ;
snprintf ( V_29 -> V_78 , sizeof( V_29 -> V_78 ) , L_2 ,
F_29 ( V_5 -> V_27 ) , V_6 ) ;
F_30 ( V_29 , V_2 ) ;
V_29 -> V_79 |= V_80 ;
F_31 ( V_29 , NULL ) ;
return V_2 ;
}
