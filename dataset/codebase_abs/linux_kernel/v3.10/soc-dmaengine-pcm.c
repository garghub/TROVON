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
switch ( F_4 ( V_9 ) ) {
case V_14 :
V_13 = V_15 ;
break;
case V_16 :
V_13 = V_17 ;
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_13 = V_22 ;
break;
default:
return - V_23 ;
}
if ( V_3 -> V_24 == V_25 ) {
V_11 -> V_26 = V_27 ;
V_11 -> V_28 = V_13 ;
} else {
V_11 -> V_26 = V_29 ;
V_11 -> V_30 = V_13 ;
}
V_11 -> V_31 = false ;
return 0 ;
}
void F_5 (
const struct V_2 * V_3 ,
const struct V_32 * V_33 ,
struct V_10 * V_11 )
{
if ( V_3 -> V_24 == V_25 ) {
V_11 -> V_34 = V_33 -> V_35 ;
V_11 -> V_36 = V_33 -> V_37 ;
if ( V_33 -> V_38 != V_39 )
V_11 -> V_28 = V_33 -> V_38 ;
} else {
V_11 -> V_40 = V_33 -> V_35 ;
V_11 -> V_41 = V_33 -> V_37 ;
if ( V_33 -> V_38 != V_39 )
V_11 -> V_30 = V_33 -> V_38 ;
}
V_11 -> V_42 = V_33 -> V_42 ;
}
static void F_6 ( void * V_43 )
{
struct V_2 * V_3 = V_43 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_44 += F_7 ( V_3 ) ;
if ( V_7 -> V_44 >= F_8 ( V_3 ) )
V_7 -> V_44 = 0 ;
F_9 ( V_3 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_45 = V_7 -> V_6 ;
struct V_46 * V_47 ;
enum V_48 V_26 ;
unsigned long V_49 = V_50 ;
V_26 = F_11 ( V_3 ) ;
if ( ! V_3 -> V_4 -> V_51 )
V_49 |= V_52 ;
V_7 -> V_44 = 0 ;
V_47 = F_12 ( V_45 ,
V_3 -> V_4 -> V_53 ,
F_8 ( V_3 ) ,
F_7 ( V_3 ) , V_26 , V_49 ) ;
if ( ! V_47 )
return - V_54 ;
V_47 -> V_55 = F_6 ;
V_47 -> V_56 = V_3 ;
V_7 -> V_57 = F_13 ( V_47 ) ;
return 0 ;
}
int F_14 ( struct V_2 * V_3 , int V_58 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_59 ;
switch ( V_58 ) {
case V_60 :
V_59 = F_10 ( V_3 ) ;
if ( V_59 )
return V_59 ;
F_15 ( V_7 -> V_6 ) ;
break;
case V_61 :
case V_62 :
F_16 ( V_7 -> V_6 ) ;
break;
case V_63 :
case V_64 :
F_17 ( V_7 -> V_6 ) ;
break;
case V_65 :
F_18 ( V_7 -> V_6 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
T_1 F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_20 ( V_3 -> V_4 , V_7 -> V_44 ) ;
}
T_1 F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_66 V_67 ;
enum V_68 V_69 ;
unsigned int V_70 ;
unsigned int V_44 = 0 ;
V_69 = F_22 ( V_7 -> V_6 , V_7 -> V_57 , & V_67 ) ;
if ( V_69 == V_71 || V_69 == V_72 ) {
V_70 = F_8 ( V_3 ) ;
if ( V_67 . V_73 > 0 && V_67 . V_73 <= V_70 )
V_44 = V_70 - V_67 . V_73 ;
}
return F_20 ( V_3 -> V_4 , V_44 ) ;
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
struct V_6 * V_45 )
{
struct V_1 * V_7 ;
int V_59 ;
if ( ! V_45 )
return - V_79 ;
V_59 = F_28 ( V_3 -> V_4 ,
V_80 ) ;
if ( V_59 < 0 )
return V_59 ;
V_7 = F_29 ( sizeof( * V_7 ) , V_81 ) ;
if ( ! V_7 )
return - V_54 ;
V_7 -> V_6 = V_45 ;
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
