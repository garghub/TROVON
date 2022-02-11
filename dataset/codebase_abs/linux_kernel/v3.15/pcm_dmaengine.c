static inline struct V_1 * F_1 (
const struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
struct V_6 * F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_6 ;
}
int F_3 ( const struct V_2 * V_3 ,
const struct V_8 * V_9 ,
struct V_10 * V_11 )
{
enum V_12 V_13 ;
int V_14 ;
V_14 = F_4 ( F_5 ( V_9 ) ) ;
if ( V_14 < 8 || V_14 > 64 )
return - V_15 ;
else if ( V_14 == 8 )
V_13 = V_16 ;
else if ( V_14 == 16 )
V_13 = V_17 ;
else if ( V_14 <= 32 )
V_13 = V_18 ;
else
V_13 = V_19 ;
if ( V_3 -> V_20 == V_21 ) {
V_11 -> V_22 = V_23 ;
V_11 -> V_24 = V_13 ;
} else {
V_11 -> V_22 = V_25 ;
V_11 -> V_26 = V_13 ;
}
V_11 -> V_27 = false ;
return 0 ;
}
void F_6 (
const struct V_2 * V_3 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 )
{
if ( V_3 -> V_20 == V_21 ) {
V_11 -> V_30 = V_29 -> V_31 ;
V_11 -> V_32 = V_29 -> V_33 ;
if ( V_29 -> V_34 != V_35 )
V_11 -> V_24 = V_29 -> V_34 ;
} else {
V_11 -> V_36 = V_29 -> V_31 ;
V_11 -> V_37 = V_29 -> V_33 ;
if ( V_29 -> V_34 != V_35 )
V_11 -> V_26 = V_29 -> V_34 ;
}
V_11 -> V_38 = V_29 -> V_38 ;
}
static void F_7 ( void * V_39 )
{
struct V_2 * V_3 = V_39 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_40 += F_8 ( V_3 ) ;
if ( V_7 -> V_40 >= F_9 ( V_3 ) )
V_7 -> V_40 = 0 ;
F_10 ( V_3 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_41 = V_7 -> V_6 ;
struct V_42 * V_43 ;
enum V_44 V_22 ;
unsigned long V_45 = V_46 ;
V_22 = F_12 ( V_3 ) ;
if ( ! V_3 -> V_4 -> V_47 )
V_45 |= V_48 ;
V_7 -> V_40 = 0 ;
V_43 = F_13 ( V_41 ,
V_3 -> V_4 -> V_49 ,
F_9 ( V_3 ) ,
F_8 ( V_3 ) , V_22 , V_45 ) ;
if ( ! V_43 )
return - V_50 ;
V_43 -> V_51 = F_7 ;
V_43 -> V_52 = V_3 ;
V_7 -> V_53 = F_14 ( V_43 ) ;
return 0 ;
}
int F_15 ( struct V_2 * V_3 , int V_54 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_55 * V_4 = V_3 -> V_4 ;
int V_56 ;
switch ( V_54 ) {
case V_57 :
V_56 = F_11 ( V_3 ) ;
if ( V_56 )
return V_56 ;
F_16 ( V_7 -> V_6 ) ;
break;
case V_58 :
case V_59 :
F_17 ( V_7 -> V_6 ) ;
break;
case V_60 :
if ( V_4 -> V_61 & V_62 )
F_18 ( V_7 -> V_6 ) ;
else
F_19 ( V_7 -> V_6 ) ;
break;
case V_63 :
F_18 ( V_7 -> V_6 ) ;
break;
case V_64 :
F_19 ( V_7 -> V_6 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
T_1 F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_21 ( V_3 -> V_4 , V_7 -> V_40 ) ;
}
T_1 F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_65 V_66 ;
enum V_67 V_68 ;
unsigned int V_69 ;
unsigned int V_40 = 0 ;
V_68 = F_23 ( V_7 -> V_6 , V_7 -> V_53 , & V_66 ) ;
if ( V_68 == V_70 || V_68 == V_71 ) {
V_69 = F_9 ( V_3 ) ;
if ( V_66 . V_72 > 0 && V_66 . V_72 <= V_69 )
V_40 = V_69 - V_66 . V_72 ;
}
return F_21 ( V_3 -> V_4 , V_40 ) ;
}
struct V_6 * F_24 ( T_2 V_73 ,
void * V_74 )
{
T_3 V_75 ;
F_25 ( V_75 ) ;
F_26 ( V_76 , V_75 ) ;
F_26 ( V_77 , V_75 ) ;
return F_27 ( V_75 , V_73 , V_74 ) ;
}
int F_28 ( struct V_2 * V_3 ,
struct V_6 * V_41 )
{
struct V_1 * V_7 ;
int V_56 ;
if ( ! V_41 )
return - V_78 ;
V_56 = F_29 ( V_3 -> V_4 ,
V_79 ) ;
if ( V_56 < 0 )
return V_56 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_80 ) ;
if ( ! V_7 )
return - V_50 ;
V_7 -> V_6 = V_41 ;
V_3 -> V_4 -> V_5 = V_7 ;
return 0 ;
}
int F_31 ( struct V_2 * V_3 ,
T_2 V_73 , void * V_74 )
{
return F_28 ( V_3 ,
F_24 ( V_73 , V_74 ) ) ;
}
int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_33 ( V_7 ) ;
return 0 ;
}
int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_35 ( V_7 -> V_6 ) ;
return F_32 ( V_3 ) ;
}
