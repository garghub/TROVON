static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 + V_2 -> V_7 . V_8 * V_9 , V_6 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_10 )
{
F_1 ( V_2 , V_4 , V_11 ,
V_10 << V_12 ) ;
}
static unsigned int F_4 ( unsigned int V_13 , unsigned int V_14 )
{
if ( V_14 > 4096 ) {
unsigned int V_15 ;
V_15 = V_14 / 4096 ;
V_15 = V_15 < 4 ? 1 : ( V_15 < 8 ? 2 : 4 ) ;
return ( V_13 - 1 ) / V_15 * V_15 * 4096 / V_14 + 1 ;
} else {
return ( V_13 - 1 ) * 4096 / V_14 + 1 ;
}
}
static void F_5 ( unsigned int V_13 ,
unsigned int * V_16 , unsigned int * V_17 )
{
* V_16 = F_6 ( F_4 ( V_13 , V_18 ) , V_19 ) ;
* V_17 = F_7 ( F_4 ( V_13 , V_20 ) , V_21 ) ;
}
static unsigned int F_8 ( unsigned int V_14 )
{
if ( V_14 >= 4096 ) {
unsigned int V_15 ;
V_15 = V_14 / 4096 ;
V_15 = V_15 < 4 ? 1 : ( V_15 < 8 ? 2 : 4 ) ;
return 64 * 4096 * V_15 / V_14 ;
} else {
return 64 ;
}
}
static unsigned int F_9 ( unsigned int V_13 , unsigned int V_22 )
{
return ( V_13 - 1 ) * 4096 / ( V_22 - 1 ) ;
}
static int F_10 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_27 * V_28 )
{
static const unsigned int V_29 [] = {
V_30 ,
V_31 ,
} ;
return F_11 ( V_24 , V_26 , V_28 , V_29 ,
F_12 ( V_29 ) ) ;
}
static int F_13 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
struct V_25 * V_34 ;
struct V_35 * V_36 ;
V_34 = F_15 ( & V_2 -> V_7 , V_26 , V_33 -> V_37 ) ;
if ( ! V_34 )
return - V_38 ;
V_36 = F_16 ( & V_2 -> V_7 , V_34 ,
V_39 ) ;
if ( V_33 -> V_8 || V_33 -> V_28 != V_36 -> V_28 )
return - V_38 ;
if ( V_33 -> V_40 == V_39 ) {
V_33 -> V_41 = V_19 ;
V_33 -> V_42 = V_21 ;
V_33 -> V_43 = V_19 ;
V_33 -> V_44 = V_21 ;
} else {
F_5 ( V_36 -> V_45 , & V_33 -> V_41 ,
& V_33 -> V_42 ) ;
F_5 ( V_36 -> V_46 , & V_33 -> V_43 ,
& V_33 -> V_44 ) ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_25 * V_34 ,
unsigned int V_40 , struct V_35 * V_47 )
{
struct V_35 * V_36 ;
unsigned int V_16 ;
unsigned int V_17 ;
switch ( V_40 ) {
case V_39 :
if ( V_47 -> V_28 != V_30 &&
V_47 -> V_28 != V_31 )
V_47 -> V_28 = V_31 ;
V_47 -> V_45 = F_18 ( V_47 -> V_45 , V_19 , V_21 ) ;
V_47 -> V_46 = F_18 ( V_47 -> V_46 , V_19 , V_21 ) ;
break;
case V_48 :
V_36 = F_16 ( & V_2 -> V_7 , V_34 ,
V_39 ) ;
V_47 -> V_28 = V_36 -> V_28 ;
F_5 ( V_36 -> V_45 , & V_16 , & V_17 ) ;
V_47 -> V_45 = F_18 ( V_47 -> V_45 , V_16 , V_17 ) ;
F_5 ( V_36 -> V_46 , & V_16 , & V_17 ) ;
V_47 -> V_46 = F_18 ( V_47 -> V_46 , V_16 , V_17 ) ;
break;
}
V_47 -> V_49 = V_50 ;
V_47 -> V_51 = V_52 ;
}
static int F_19 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_53 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
struct V_25 * V_34 ;
struct V_35 * V_36 ;
V_34 = F_15 ( & V_2 -> V_7 , V_26 , V_47 -> V_37 ) ;
if ( ! V_34 )
return - V_38 ;
F_17 ( V_2 , V_34 , V_47 -> V_40 , & V_47 -> V_36 ) ;
V_36 = F_16 ( & V_2 -> V_7 , V_34 , V_47 -> V_40 ) ;
* V_36 = V_47 -> V_36 ;
if ( V_47 -> V_40 == V_39 ) {
V_36 = F_16 ( & V_2 -> V_7 , V_34 ,
V_48 ) ;
* V_36 = V_47 -> V_36 ;
F_17 ( V_2 , V_34 , V_48 , V_36 ) ;
}
return 0 ;
}
static void F_20 ( struct V_54 * V_7 ,
struct V_55 * V_56 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_14 ( & V_7 -> V_24 ) ;
const struct V_35 * V_22 ;
const struct V_35 * V_13 ;
unsigned int V_57 ;
unsigned int V_58 ;
bool V_59 ;
V_13 = F_16 ( & V_2 -> V_7 , V_2 -> V_7 . V_34 ,
V_39 ) ;
V_22 = F_16 ( & V_2 -> V_7 , V_2 -> V_7 . V_34 ,
V_48 ) ;
V_57 = F_9 ( V_13 -> V_45 , V_22 -> V_45 ) ;
V_58 = F_9 ( V_13 -> V_46 , V_22 -> V_46 ) ;
F_21 ( V_2 -> V_7 . V_60 -> V_61 , L_1 , V_57 , V_58 ) ;
if ( V_2 -> V_62 && ( V_57 >= 8192 || V_58 >= 8192 ) )
V_59 = false ;
else
V_59 = true ;
F_1 ( V_2 , V_4 , V_63 ,
( V_2 -> V_62 ? V_64 : 0 ) |
( V_59 ? V_65 : 0 ) ) ;
F_1 ( V_2 , V_4 , V_66 ,
( F_8 ( V_57 )
<< V_67 ) |
( F_8 ( V_58 )
<< V_68 ) ) ;
F_1 ( V_2 , V_4 , V_69 ,
( V_57 << V_70 ) |
( V_58 << V_71 ) ) ;
F_1 ( V_2 , V_4 , V_72 ,
( V_22 -> V_45 << V_73 ) |
( V_22 -> V_46 << V_74 ) ) ;
}
struct V_1 * F_22 ( struct V_75 * V_60 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_76 [ 6 ] ;
int V_77 ;
V_2 = F_23 ( V_60 -> V_61 , sizeof( * V_2 ) , V_78 ) ;
if ( V_2 == NULL )
return F_24 ( - V_79 ) ;
V_2 -> V_7 . V_80 = & V_81 ;
V_2 -> V_7 . type = V_82 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_76 , L_2 , V_8 ) ;
V_77 = F_25 ( V_60 , & V_2 -> V_7 , V_76 , 2 , & V_83 ) ;
if ( V_77 < 0 )
return F_24 ( V_77 ) ;
return V_2 ;
}
