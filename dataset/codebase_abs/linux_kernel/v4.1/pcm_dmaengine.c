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
V_14 = F_4 ( V_9 ) ;
if ( V_14 < 8 || V_14 > 64 )
return - V_15 ;
else if ( V_14 == 8 )
V_13 = V_16 ;
else if ( V_14 == 16 )
V_13 = V_17 ;
else if ( V_14 == 24 )
V_13 = V_18 ;
else if ( V_14 <= 32 )
V_13 = V_19 ;
else
V_13 = V_20 ;
if ( V_3 -> V_21 == V_22 ) {
V_11 -> V_23 = V_24 ;
V_11 -> V_25 = V_13 ;
} else {
V_11 -> V_23 = V_26 ;
V_11 -> V_27 = V_13 ;
}
V_11 -> V_28 = false ;
return 0 ;
}
void F_5 (
const struct V_2 * V_3 ,
const struct V_29 * V_30 ,
struct V_10 * V_11 )
{
if ( V_3 -> V_21 == V_22 ) {
V_11 -> V_31 = V_30 -> V_32 ;
V_11 -> V_33 = V_30 -> V_34 ;
if ( V_30 -> V_35 != V_36 )
V_11 -> V_25 = V_30 -> V_35 ;
} else {
V_11 -> V_37 = V_30 -> V_32 ;
V_11 -> V_38 = V_30 -> V_34 ;
if ( V_30 -> V_35 != V_36 )
V_11 -> V_27 = V_30 -> V_35 ;
}
V_11 -> V_39 = V_30 -> V_39 ;
}
static void F_6 ( void * V_40 )
{
struct V_2 * V_3 = V_40 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_41 += F_7 ( V_3 ) ;
if ( V_7 -> V_41 >= F_8 ( V_3 ) )
V_7 -> V_41 = 0 ;
F_9 ( V_3 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_42 = V_7 -> V_6 ;
struct V_43 * V_44 ;
enum V_45 V_23 ;
unsigned long V_46 = V_47 ;
V_23 = F_11 ( V_3 ) ;
if ( ! V_3 -> V_4 -> V_48 )
V_46 |= V_49 ;
V_7 -> V_41 = 0 ;
V_44 = F_12 ( V_42 ,
V_3 -> V_4 -> V_50 ,
F_8 ( V_3 ) ,
F_7 ( V_3 ) , V_23 , V_46 ) ;
if ( ! V_44 )
return - V_51 ;
V_44 -> V_52 = F_6 ;
V_44 -> V_53 = V_3 ;
V_7 -> V_54 = F_13 ( V_44 ) ;
return 0 ;
}
int F_14 ( struct V_2 * V_3 , int V_55 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_56 * V_4 = V_3 -> V_4 ;
int V_57 ;
switch ( V_55 ) {
case V_58 :
V_57 = F_10 ( V_3 ) ;
if ( V_57 )
return V_57 ;
F_15 ( V_7 -> V_6 ) ;
break;
case V_59 :
case V_60 :
F_16 ( V_7 -> V_6 ) ;
break;
case V_61 :
if ( V_4 -> V_62 & V_63 )
F_17 ( V_7 -> V_6 ) ;
else
F_18 ( V_7 -> V_6 ) ;
break;
case V_64 :
F_17 ( V_7 -> V_6 ) ;
break;
case V_65 :
F_18 ( V_7 -> V_6 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
T_1 F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_20 ( V_3 -> V_4 , V_7 -> V_41 ) ;
}
T_1 F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_66 V_67 ;
enum V_68 V_69 ;
unsigned int V_70 ;
unsigned int V_41 = 0 ;
V_69 = F_22 ( V_7 -> V_6 , V_7 -> V_54 , & V_67 ) ;
if ( V_69 == V_71 || V_69 == V_72 ) {
V_70 = F_8 ( V_3 ) ;
if ( V_67 . V_73 > 0 && V_67 . V_73 <= V_70 )
V_41 = V_70 - V_67 . V_73 ;
}
return F_20 ( V_3 -> V_4 , V_41 ) ;
}
struct V_6 * F_23 ( T_2 V_74 ,
void * V_75 )
{
T_3 V_76 ;
F_24 ( V_76 ) ;
F_25 ( V_77 , V_76 ) ;
F_25 ( V_78 , V_76 ) ;
return F_26 ( V_76 , V_74 , V_75 ) ;
}
int F_27 ( struct V_2 * V_3 ,
struct V_6 * V_42 )
{
struct V_1 * V_7 ;
int V_57 ;
if ( ! V_42 )
return - V_79 ;
V_57 = F_28 ( V_3 -> V_4 ,
V_80 ) ;
if ( V_57 < 0 )
return V_57 ;
V_7 = F_29 ( sizeof( * V_7 ) , V_81 ) ;
if ( ! V_7 )
return - V_51 ;
V_7 -> V_6 = V_42 ;
V_3 -> V_4 -> V_5 = V_7 ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 ,
T_2 V_74 , void * V_75 )
{
return F_27 ( V_3 ,
F_23 ( V_74 , V_75 ) ) ;
}
int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_32 ( V_7 ) ;
return 0 ;
}
int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_34 ( V_7 -> V_6 ) ;
return F_31 ( V_3 ) ;
}
