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
int V_38 = 0 ;
V_35 = F_15 ( & V_2 -> V_7 , V_27 , V_34 -> V_39 ) ;
if ( ! V_35 )
return - V_40 ;
V_37 = F_16 ( & V_2 -> V_7 , V_35 ,
V_41 ) ;
F_17 ( & V_2 -> V_7 . V_42 ) ;
if ( V_34 -> V_8 || V_34 -> V_29 != V_37 -> V_29 ) {
V_38 = - V_40 ;
goto V_43;
}
if ( V_34 -> V_44 == V_41 ) {
V_34 -> V_45 = V_21 ;
V_34 -> V_46 = V_23 ;
V_34 -> V_47 = V_21 ;
V_34 -> V_48 = V_23 ;
} else {
F_6 ( V_37 -> V_49 , & V_34 -> V_45 ,
& V_34 -> V_46 ) ;
F_6 ( V_37 -> V_50 , & V_34 -> V_47 ,
& V_34 -> V_48 ) ;
}
V_43:
F_18 ( & V_2 -> V_7 . V_42 ) ;
return V_38 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_26 * V_35 ,
unsigned int V_44 , struct V_36 * V_51 )
{
struct V_36 * V_37 ;
unsigned int V_18 ;
unsigned int V_19 ;
switch ( V_44 ) {
case V_41 :
if ( V_51 -> V_29 != V_31 &&
V_51 -> V_29 != V_32 )
V_51 -> V_29 = V_32 ;
V_51 -> V_49 = F_20 ( V_51 -> V_49 , V_21 , V_23 ) ;
V_51 -> V_50 = F_20 ( V_51 -> V_50 , V_21 , V_23 ) ;
break;
case V_52 :
V_37 = F_16 ( & V_2 -> V_7 , V_35 ,
V_41 ) ;
V_51 -> V_29 = V_37 -> V_29 ;
F_6 ( V_37 -> V_49 , & V_18 , & V_19 ) ;
V_51 -> V_49 = F_20 ( V_51 -> V_49 , V_18 , V_19 ) ;
F_6 ( V_37 -> V_50 , & V_18 , & V_19 ) ;
V_51 -> V_50 = F_20 ( V_51 -> V_50 , V_18 , V_19 ) ;
break;
}
V_51 -> V_53 = V_54 ;
V_51 -> V_55 = V_56 ;
}
static int F_21 ( struct V_25 * V_12 ,
struct V_26 * V_27 ,
struct V_57 * V_51 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_26 * V_35 ;
struct V_36 * V_37 ;
int V_38 = 0 ;
F_17 ( & V_2 -> V_7 . V_42 ) ;
V_35 = F_15 ( & V_2 -> V_7 , V_27 , V_51 -> V_39 ) ;
if ( ! V_35 ) {
V_38 = - V_40 ;
goto V_43;
}
F_19 ( V_2 , V_35 , V_51 -> V_44 , & V_51 -> V_37 ) ;
V_37 = F_16 ( & V_2 -> V_7 , V_35 , V_51 -> V_44 ) ;
* V_37 = V_51 -> V_37 ;
if ( V_51 -> V_44 == V_41 ) {
V_37 = F_16 ( & V_2 -> V_7 , V_35 ,
V_52 ) ;
* V_37 = V_51 -> V_37 ;
F_19 ( V_2 , V_35 , V_52 , V_37 ) ;
}
V_43:
F_18 ( & V_2 -> V_7 . V_42 ) ;
return V_38 ;
}
static void F_22 ( struct V_10 * V_7 ,
struct V_58 * V_59 ,
struct V_3 * V_4 ,
enum V_60 V_61 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_12 ) ;
const struct V_36 * V_24 ;
const struct V_36 * V_15 ;
unsigned int V_62 ;
unsigned int V_63 ;
bool V_64 ;
if ( V_61 == V_65 ) {
const struct V_66 * V_67 = & V_59 -> V_68 ;
F_1 ( V_2 , V_4 , V_69 ,
( V_67 -> V_49 << V_70 ) |
( V_67 -> V_50 << V_71 ) ) ;
return;
}
if ( V_61 != V_72 )
return;
V_15 = F_16 ( & V_2 -> V_7 , V_2 -> V_7 . V_35 ,
V_41 ) ;
V_24 = F_16 ( & V_2 -> V_7 , V_2 -> V_7 . V_35 ,
V_52 ) ;
V_62 = F_10 ( V_15 -> V_49 , V_24 -> V_49 ) ;
V_63 = F_10 ( V_15 -> V_50 , V_24 -> V_50 ) ;
F_23 ( V_2 -> V_7 . V_73 -> V_74 , L_1 , V_62 , V_63 ) ;
if ( V_2 -> V_75 && ( V_62 >= 8192 || V_63 >= 8192 ) )
V_64 = false ;
else
V_64 = true ;
F_1 ( V_2 , V_4 , V_76 ,
( V_2 -> V_75 ? V_77 : 0 ) |
( V_64 ? V_78 : 0 ) ) ;
F_1 ( V_2 , V_4 , V_79 ,
( F_9 ( V_62 )
<< V_80 ) |
( F_9 ( V_63 )
<< V_81 ) ) ;
F_1 ( V_2 , V_4 , V_82 ,
( V_62 << V_83 ) |
( V_63 << V_84 ) ) ;
}
static unsigned int F_24 ( struct V_10 * V_7 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_12 ) ;
const struct V_36 * V_24 ;
const struct V_36 * V_15 ;
unsigned int V_62 ;
V_15 = F_16 ( & V_2 -> V_7 , V_2 -> V_7 . V_35 ,
V_41 ) ;
V_24 = F_16 ( & V_2 -> V_7 , V_2 -> V_7 . V_35 ,
V_52 ) ;
V_62 = V_24 -> V_49 / V_15 -> V_49 ;
if ( V_62 <= 2 )
return 256 ;
else if ( V_62 <= 4 )
return 512 ;
else if ( V_62 <= 8 )
return 1024 ;
else
return 2048 ;
}
struct V_1 * F_25 ( struct V_85 * V_73 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_86 [ 6 ] ;
int V_38 ;
V_2 = F_26 ( V_73 -> V_74 , sizeof( * V_2 ) , V_87 ) ;
if ( V_2 == NULL )
return F_27 ( - V_88 ) ;
V_2 -> V_7 . V_89 = & V_90 ;
V_2 -> V_7 . type = V_91 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_86 , L_2 , V_8 ) ;
V_38 = F_28 ( V_73 , & V_2 -> V_7 , V_86 , 2 , & V_92 ,
V_93 ) ;
if ( V_38 < 0 )
return F_27 ( V_38 ) ;
return V_2 ;
}
