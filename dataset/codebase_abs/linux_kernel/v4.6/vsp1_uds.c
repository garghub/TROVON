static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_2 -> V_5 . V_6 ,
V_3 + V_2 -> V_5 . V_7 * V_8 , V_4 ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_9 )
{
F_1 ( V_2 , V_10 , V_9 << V_11 ) ;
}
static unsigned int F_4 ( unsigned int V_12 , unsigned int V_13 )
{
if ( V_13 > 4096 ) {
unsigned int V_14 ;
V_14 = V_13 / 4096 ;
V_14 = V_14 < 4 ? 1 : ( V_14 < 8 ? 2 : 4 ) ;
return ( V_12 - 1 ) / V_14 * V_14 * 4096 / V_13 + 1 ;
} else {
return ( V_12 - 1 ) * 4096 / V_13 + 1 ;
}
}
static void F_5 ( unsigned int V_12 ,
unsigned int * V_15 , unsigned int * V_16 )
{
* V_15 = F_6 ( F_4 ( V_12 , V_17 ) , V_18 ) ;
* V_16 = F_7 ( F_4 ( V_12 , V_19 ) , V_20 ) ;
}
static unsigned int F_8 ( unsigned int V_13 )
{
if ( V_13 >= 4096 ) {
unsigned int V_14 ;
V_14 = V_13 / 4096 ;
V_14 = V_14 < 4 ? 1 : ( V_14 < 8 ? 2 : 4 ) ;
return 64 * 4096 * V_14 / V_13 ;
} else {
return 64 ;
}
}
static unsigned int F_9 ( unsigned int V_12 , unsigned int V_21 )
{
return ( V_12 - 1 ) * 4096 / ( V_21 - 1 ) ;
}
static int F_10 ( struct V_22 * V_23 , int V_24 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
const struct V_25 * V_21 ;
const struct V_25 * V_12 ;
unsigned int V_26 ;
unsigned int V_27 ;
bool V_28 ;
if ( ! V_24 )
return 0 ;
V_12 = & V_2 -> V_5 . V_29 [ V_30 ] ;
V_21 = & V_2 -> V_5 . V_29 [ V_31 ] ;
V_26 = F_9 ( V_12 -> V_32 , V_21 -> V_32 ) ;
V_27 = F_9 ( V_12 -> V_33 , V_21 -> V_33 ) ;
F_12 ( V_2 -> V_5 . V_6 -> V_34 , L_1 , V_26 , V_27 ) ;
if ( V_2 -> V_35 && ( V_26 >= 8192 || V_27 >= 8192 ) )
V_28 = false ;
else
V_28 = true ;
F_1 ( V_2 , V_36 ,
( V_2 -> V_35 ? V_37 : 0 ) |
( V_28 ? V_38 : 0 ) ) ;
F_1 ( V_2 , V_39 ,
( F_8 ( V_26 )
<< V_40 ) |
( F_8 ( V_27 )
<< V_41 ) ) ;
F_1 ( V_2 , V_42 ,
( V_26 << V_43 ) |
( V_27 << V_44 ) ) ;
F_1 ( V_2 , V_45 ,
( V_21 -> V_32 << V_46 ) |
( V_21 -> V_33 << V_47 ) ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_48 * V_49 ,
struct V_50 * V_51 )
{
static const unsigned int V_52 [] = {
V_53 ,
V_54 ,
} ;
struct V_1 * V_2 = F_11 ( V_23 ) ;
if ( V_51 -> V_55 == V_30 ) {
if ( V_51 -> V_7 >= F_14 ( V_52 ) )
return - V_56 ;
V_51 -> V_51 = V_52 [ V_51 -> V_7 ] ;
} else {
struct V_25 * V_57 ;
if ( V_51 -> V_7 )
return - V_56 ;
V_57 = F_15 ( & V_2 -> V_5 , V_49 ,
V_30 , V_51 -> V_58 ) ;
V_51 -> V_51 = V_57 -> V_51 ;
}
return 0 ;
}
static int F_16 ( struct V_22 * V_23 ,
struct V_48 * V_49 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
struct V_25 * V_57 ;
V_57 = F_15 ( & V_2 -> V_5 , V_49 ,
V_30 , V_60 -> V_58 ) ;
if ( V_60 -> V_7 || V_60 -> V_51 != V_57 -> V_51 )
return - V_56 ;
if ( V_60 -> V_55 == V_30 ) {
V_60 -> V_61 = V_18 ;
V_60 -> V_62 = V_20 ;
V_60 -> V_63 = V_18 ;
V_60 -> V_64 = V_20 ;
} else {
F_5 ( V_57 -> V_32 , & V_60 -> V_61 ,
& V_60 -> V_62 ) ;
F_5 ( V_57 -> V_33 , & V_60 -> V_63 ,
& V_60 -> V_64 ) ;
}
return 0 ;
}
static int F_17 ( struct V_22 * V_23 , struct V_48 * V_49 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
V_66 -> V_57 = * F_15 ( & V_2 -> V_5 , V_49 , V_66 -> V_55 ,
V_66 -> V_58 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_48 * V_49 ,
unsigned int V_55 , struct V_25 * V_66 ,
enum V_67 V_58 )
{
struct V_25 * V_57 ;
unsigned int V_15 ;
unsigned int V_16 ;
switch ( V_55 ) {
case V_30 :
if ( V_66 -> V_51 != V_53 &&
V_66 -> V_51 != V_54 )
V_66 -> V_51 = V_54 ;
V_66 -> V_32 = F_19 ( V_66 -> V_32 , V_18 , V_20 ) ;
V_66 -> V_33 = F_19 ( V_66 -> V_33 , V_18 , V_20 ) ;
break;
case V_31 :
V_57 = F_15 ( & V_2 -> V_5 , V_49 ,
V_30 , V_58 ) ;
V_66 -> V_51 = V_57 -> V_51 ;
F_5 ( V_57 -> V_32 , & V_15 , & V_16 ) ;
V_66 -> V_32 = F_19 ( V_66 -> V_32 , V_15 , V_16 ) ;
F_5 ( V_57 -> V_33 , & V_15 , & V_16 ) ;
V_66 -> V_33 = F_19 ( V_66 -> V_33 , V_15 , V_16 ) ;
break;
}
V_66 -> V_68 = V_69 ;
V_66 -> V_70 = V_71 ;
}
static int F_20 ( struct V_22 * V_23 , struct V_48 * V_49 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
struct V_25 * V_57 ;
F_18 ( V_2 , V_49 , V_66 -> V_55 , & V_66 -> V_57 , V_66 -> V_58 ) ;
V_57 = F_15 ( & V_2 -> V_5 , V_49 , V_66 -> V_55 ,
V_66 -> V_58 ) ;
* V_57 = V_66 -> V_57 ;
if ( V_66 -> V_55 == V_30 ) {
V_57 = F_15 ( & V_2 -> V_5 , V_49 ,
V_31 , V_66 -> V_58 ) ;
* V_57 = V_66 -> V_57 ;
F_18 ( V_2 , V_49 , V_31 , V_57 , V_66 -> V_58 ) ;
}
return 0 ;
}
struct V_1 * F_21 ( struct V_72 * V_6 , unsigned int V_7 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
int V_73 ;
V_2 = F_22 ( V_6 -> V_34 , sizeof( * V_2 ) , V_74 ) ;
if ( V_2 == NULL )
return F_23 ( - V_75 ) ;
V_2 -> V_5 . type = V_76 ;
V_2 -> V_5 . V_7 = V_7 ;
V_73 = F_24 ( V_6 , & V_2 -> V_5 , 2 ) ;
if ( V_73 < 0 )
return F_23 ( V_73 ) ;
V_23 = & V_2 -> V_5 . V_23 ;
F_25 ( V_23 , & V_77 ) ;
V_23 -> V_5 . V_78 = & V_6 -> V_79 ;
V_23 -> V_80 = & V_81 ;
snprintf ( V_23 -> V_82 , sizeof( V_23 -> V_82 ) , L_2 ,
F_26 ( V_6 -> V_34 ) , V_7 ) ;
F_27 ( V_23 , V_2 ) ;
V_23 -> V_83 |= V_84 ;
F_28 ( V_23 , NULL ) ;
return V_2 ;
}
