static inline struct V_1 * F_1 (
const struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
void F_2 ( struct V_2 * V_3 , void * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_6 = V_6 ;
}
void * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_6 ;
}
struct V_8 * F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_8 ;
}
int F_5 ( const struct V_2 * V_3 ,
const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
enum V_13 V_14 ;
switch ( F_6 ( V_10 ) ) {
case V_15 :
V_14 = V_16 ;
break;
case V_17 :
V_14 = V_18 ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_14 = V_23 ;
break;
default:
return - V_24 ;
}
if ( V_3 -> V_25 == V_26 ) {
V_12 -> V_27 = V_28 ;
V_12 -> V_29 = V_14 ;
} else {
V_12 -> V_27 = V_30 ;
V_12 -> V_31 = V_14 ;
}
return 0 ;
}
static void F_7 ( void * V_32 )
{
struct V_2 * V_3 = V_32 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_33 += F_8 ( V_3 ) ;
if ( V_7 -> V_33 >= F_9 ( V_3 ) )
V_7 -> V_33 = 0 ;
F_10 ( V_3 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_34 = V_7 -> V_8 ;
struct V_35 * V_36 ;
enum V_37 V_27 ;
unsigned long V_38 = V_39 ;
V_27 = F_12 ( V_3 ) ;
if ( ! V_3 -> V_4 -> V_40 )
V_38 |= V_41 ;
V_7 -> V_33 = 0 ;
V_36 = F_13 ( V_34 ,
V_3 -> V_4 -> V_42 ,
F_9 ( V_3 ) ,
F_8 ( V_3 ) , V_27 , V_38 ) ;
if ( ! V_36 )
return - V_43 ;
V_36 -> V_44 = F_7 ;
V_36 -> V_45 = V_3 ;
V_7 -> V_46 = F_14 ( V_36 ) ;
return 0 ;
}
int F_15 ( struct V_2 * V_3 , int V_47 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_48 ;
switch ( V_47 ) {
case V_49 :
V_48 = F_11 ( V_3 ) ;
if ( V_48 )
return V_48 ;
F_16 ( V_7 -> V_8 ) ;
break;
case V_50 :
case V_51 :
F_17 ( V_7 -> V_8 ) ;
break;
case V_52 :
case V_53 :
F_18 ( V_7 -> V_8 ) ;
break;
case V_54 :
F_19 ( V_7 -> V_8 ) ;
break;
default:
return - V_24 ;
}
return 0 ;
}
T_1 F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_21 ( V_3 -> V_4 , V_7 -> V_33 ) ;
}
T_1 F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_55 V_56 ;
enum V_57 V_58 ;
unsigned int V_59 ;
unsigned int V_33 = 0 ;
V_58 = F_23 ( V_7 -> V_8 , V_7 -> V_46 , & V_56 ) ;
if ( V_58 == V_60 || V_58 == V_61 ) {
V_59 = F_9 ( V_3 ) ;
if ( V_56 . V_62 > 0 && V_56 . V_62 <= V_59 )
V_33 = V_59 - V_56 . V_62 ;
}
return F_21 ( V_3 -> V_4 , V_33 ) ;
}
static int F_24 ( struct V_1 * V_7 ,
T_2 V_63 , void * V_64 )
{
T_3 V_65 ;
F_25 ( V_65 ) ;
F_26 ( V_66 , V_65 ) ;
F_26 ( V_67 , V_65 ) ;
V_7 -> V_8 = F_27 ( V_65 , V_63 , V_64 ) ;
if ( ! V_7 -> V_8 )
return - V_68 ;
return 0 ;
}
int F_28 ( struct V_2 * V_3 ,
T_2 V_63 , void * V_64 )
{
struct V_1 * V_7 ;
int V_48 ;
V_48 = F_29 ( V_3 -> V_4 ,
V_69 ) ;
if ( V_48 < 0 )
return V_48 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_70 ) ;
if ( ! V_7 )
return - V_43 ;
V_48 = F_24 ( V_7 , V_63 , V_64 ) ;
if ( V_48 < 0 ) {
F_31 ( V_7 ) ;
return V_48 ;
}
V_3 -> V_4 -> V_5 = V_7 ;
return 0 ;
}
int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_33 ( V_7 -> V_8 ) ;
F_31 ( V_7 ) ;
return 0 ;
}
