static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 + V_2 -> V_7 . V_8 * V_9 , V_6 ) ;
}
void F_3 ( struct V_10 * V_7 , struct V_3 * V_4 ,
unsigned int V_11 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_12 ) ;
F_1 ( V_2 , V_4 , V_13 ,
V_11 << V_14 ) ;
}
static unsigned int F_5 ( unsigned int V_15 , unsigned int V_16 )
{
if ( V_16 > 4096 ) {
unsigned int V_17 ;
V_17 = V_16 / 4096 ;
V_17 = V_17 < 4 ? 1 : ( V_17 < 8 ? 2 : 4 ) ;
return ( V_15 - 1 ) / V_17 * V_17 * 4096 / V_16 + 1 ;
} else {
return ( V_15 - 1 ) * 4096 / V_16 + 1 ;
}
}
static void F_6 ( unsigned int V_15 ,
unsigned int * V_18 , unsigned int * V_19 )
{
* V_18 = F_7 ( F_5 ( V_15 , V_20 ) , V_21 ) ;
* V_19 = F_8 ( F_5 ( V_15 , V_22 ) , V_23 ) ;
}
static unsigned int F_9 ( unsigned int V_16 )
{
if ( V_16 >= 4096 ) {
unsigned int V_17 ;
V_17 = V_16 / 4096 ;
V_17 = V_17 < 4 ? 1 : ( V_17 < 8 ? 2 : 4 ) ;
return 64 * 4096 * V_17 / V_16 ;
} else {
return 64 ;
}
}
static unsigned int F_10 ( unsigned int V_15 , unsigned int V_24 )
{
return ( V_15 - 1 ) * 4096 / ( V_24 - 1 ) ;
}
static int F_11 ( struct V_25 * V_12 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
static const unsigned int V_30 [] = {
V_31 ,
V_32 ,
} ;
return F_12 ( V_12 , V_27 , V_29 , V_30 ,
F_13 ( V_30 ) ) ;
}
static int F_14 ( struct V_25 * V_12 ,
struct V_26 * V_27 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_26 * V_35 ;
struct V_36 * V_37 ;
V_35 = F_15 ( & V_2 -> V_7 , V_27 , V_34 -> V_38 ) ;
if ( ! V_35 )
return - V_39 ;
V_37 = F_16 ( & V_2 -> V_7 , V_35 ,
V_40 ) ;
if ( V_34 -> V_8 || V_34 -> V_29 != V_37 -> V_29 )
return - V_39 ;
if ( V_34 -> V_41 == V_40 ) {
V_34 -> V_42 = V_21 ;
V_34 -> V_43 = V_23 ;
V_34 -> V_44 = V_21 ;
V_34 -> V_45 = V_23 ;
} else {
F_6 ( V_37 -> V_46 , & V_34 -> V_42 ,
& V_34 -> V_43 ) ;
F_6 ( V_37 -> V_47 , & V_34 -> V_44 ,
& V_34 -> V_45 ) ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_26 * V_35 ,
unsigned int V_41 , struct V_36 * V_48 )
{
struct V_36 * V_37 ;
unsigned int V_18 ;
unsigned int V_19 ;
switch ( V_41 ) {
case V_40 :
if ( V_48 -> V_29 != V_31 &&
V_48 -> V_29 != V_32 )
V_48 -> V_29 = V_32 ;
V_48 -> V_46 = F_18 ( V_48 -> V_46 , V_21 , V_23 ) ;
V_48 -> V_47 = F_18 ( V_48 -> V_47 , V_21 , V_23 ) ;
break;
case V_49 :
V_37 = F_16 ( & V_2 -> V_7 , V_35 ,
V_40 ) ;
V_48 -> V_29 = V_37 -> V_29 ;
F_6 ( V_37 -> V_46 , & V_18 , & V_19 ) ;
V_48 -> V_46 = F_18 ( V_48 -> V_46 , V_18 , V_19 ) ;
F_6 ( V_37 -> V_47 , & V_18 , & V_19 ) ;
V_48 -> V_47 = F_18 ( V_48 -> V_47 , V_18 , V_19 ) ;
break;
}
V_48 -> V_50 = V_51 ;
V_48 -> V_52 = V_53 ;
}
static int F_19 ( struct V_25 * V_12 ,
struct V_26 * V_27 ,
struct V_54 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_26 * V_35 ;
struct V_36 * V_37 ;
V_35 = F_15 ( & V_2 -> V_7 , V_27 , V_48 -> V_38 ) ;
if ( ! V_35 )
return - V_39 ;
F_17 ( V_2 , V_35 , V_48 -> V_41 , & V_48 -> V_37 ) ;
V_37 = F_16 ( & V_2 -> V_7 , V_35 , V_48 -> V_41 ) ;
* V_37 = V_48 -> V_37 ;
if ( V_48 -> V_41 == V_40 ) {
V_37 = F_16 ( & V_2 -> V_7 , V_35 ,
V_49 ) ;
* V_37 = V_48 -> V_37 ;
F_17 ( V_2 , V_35 , V_49 , V_37 ) ;
}
return 0 ;
}
static void F_20 ( struct V_10 * V_7 ,
struct V_55 * V_56 ,
struct V_3 * V_4 , bool V_57 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_12 ) ;
const struct V_36 * V_24 ;
const struct V_36 * V_15 ;
unsigned int V_58 ;
unsigned int V_59 ;
bool V_60 ;
if ( ! V_57 )
return;
V_15 = F_16 ( & V_2 -> V_7 , V_2 -> V_7 . V_35 ,
V_40 ) ;
V_24 = F_16 ( & V_2 -> V_7 , V_2 -> V_7 . V_35 ,
V_49 ) ;
V_58 = F_10 ( V_15 -> V_46 , V_24 -> V_46 ) ;
V_59 = F_10 ( V_15 -> V_47 , V_24 -> V_47 ) ;
F_21 ( V_2 -> V_7 . V_61 -> V_62 , L_1 , V_58 , V_59 ) ;
if ( V_2 -> V_63 && ( V_58 >= 8192 || V_59 >= 8192 ) )
V_60 = false ;
else
V_60 = true ;
F_1 ( V_2 , V_4 , V_64 ,
( V_2 -> V_63 ? V_65 : 0 ) |
( V_60 ? V_66 : 0 ) ) ;
F_1 ( V_2 , V_4 , V_67 ,
( F_9 ( V_58 )
<< V_68 ) |
( F_9 ( V_59 )
<< V_69 ) ) ;
F_1 ( V_2 , V_4 , V_70 ,
( V_58 << V_71 ) |
( V_59 << V_72 ) ) ;
F_1 ( V_2 , V_4 , V_73 ,
( V_24 -> V_46 << V_74 ) |
( V_24 -> V_47 << V_75 ) ) ;
}
struct V_1 * F_22 ( struct V_76 * V_61 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_77 [ 6 ] ;
int V_78 ;
V_2 = F_23 ( V_61 -> V_62 , sizeof( * V_2 ) , V_79 ) ;
if ( V_2 == NULL )
return F_24 ( - V_80 ) ;
V_2 -> V_7 . V_81 = & V_82 ;
V_2 -> V_7 . type = V_83 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_77 , L_2 , V_8 ) ;
V_78 = F_25 ( V_61 , & V_2 -> V_7 , V_77 , 2 , & V_84 ,
V_85 ) ;
if ( V_78 < 0 )
return F_24 ( V_78 ) ;
return V_2 ;
}
