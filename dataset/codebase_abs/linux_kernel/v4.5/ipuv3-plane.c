int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 -> V_2 , V_1 -> V_3 ,
V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
unsigned long V_7 , V_8 ;
V_7 = V_6 -> V_7 ;
V_8 = V_6 -> V_8 ;
if ( ! V_7 || ! V_8 )
return 60 ;
return F_4 ( V_6 -> clock * 1000 , V_8 * V_7 ) ;
}
static inline int F_5 ( int V_9 , int V_10 , unsigned int V_11 )
{
return V_9 * V_10 * V_11 ;
}
int F_6 ( struct V_1 * V_1 , struct V_12 * V_13 ,
int V_14 , int V_15 )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
int V_19 ;
V_17 = F_7 ( V_13 , 0 ) ;
if ( ! V_17 ) {
F_8 ( L_1 ) ;
return - V_20 ;
}
F_9 ( V_1 -> V_21 . V_22 -> V_22 , L_2 ,
& V_17 -> V_23 , V_14 , V_15 ) ;
V_18 = V_17 -> V_23 + V_13 -> V_24 [ 0 ] +
V_13 -> V_25 [ 0 ] * V_15 + ( V_13 -> V_26 >> 3 ) * V_14 ;
if ( V_1 -> V_27 ) {
V_19 = F_10 ( V_1 -> V_3 ) ;
F_11 ( V_1 -> V_3 , ! V_19 , V_18 ) ;
F_12 ( V_1 -> V_3 , ! V_19 ) ;
} else {
F_11 ( V_1 -> V_3 , 0 , V_18 ) ;
F_11 ( V_1 -> V_3 , 1 , V_18 ) ;
}
V_1 -> V_14 = V_14 ;
V_1 -> V_15 = V_15 ;
return 0 ;
}
int F_13 ( struct V_1 * V_1 , struct V_28 * V_29 ,
struct V_5 * V_6 ,
struct V_12 * V_13 , int V_30 , int V_31 ,
unsigned int V_32 , unsigned int V_33 ,
T_1 V_34 , T_1 V_35 ,
T_1 V_36 , T_1 V_37 , bool V_38 )
{
struct V_39 * V_22 = V_1 -> V_21 . V_22 -> V_22 ;
int V_40 ;
if ( V_36 != V_32 || V_37 != V_33 )
return - V_41 ;
if ( V_30 < 0 ) {
if ( - V_30 > V_32 )
return - V_41 ;
V_34 += - V_30 ;
V_36 -= - V_30 ;
V_32 -= - V_30 ;
V_30 = 0 ;
}
if ( V_31 < 0 ) {
if ( - V_31 > V_33 )
return - V_41 ;
V_35 += - V_31 ;
V_37 -= - V_31 ;
V_33 -= - V_31 ;
V_31 = 0 ;
}
if ( V_30 + V_32 > V_6 -> V_42 ) {
if ( V_30 > V_6 -> V_42 )
return - V_41 ;
V_32 = V_6 -> V_42 - V_30 ;
V_36 = V_32 ;
}
if ( V_31 + V_33 > V_6 -> V_43 ) {
if ( V_31 > V_6 -> V_43 )
return - V_41 ;
V_33 = V_6 -> V_43 - V_31 ;
V_37 = V_33 ;
}
if ( V_32 < 13 && ( V_1 -> V_44 != V_45 ) )
return - V_41 ;
if ( V_33 < 2 )
return - V_41 ;
if ( V_1 -> V_27 ) {
if ( V_36 != V_1 -> V_46 || V_37 != V_1 -> V_47 ||
V_13 -> V_48 != V_1 -> V_21 . V_13 -> V_48 )
return - V_41 ;
return F_6 ( V_1 , V_13 , V_34 , V_35 ) ;
}
switch ( V_1 -> V_44 ) {
case V_49 :
V_40 = F_14 ( V_1 -> V_50 ,
V_51 ,
V_51 ) ;
if ( V_40 ) {
F_15 ( V_22 ,
L_3 ,
V_40 ) ;
return V_40 ;
}
F_16 ( V_1 -> V_50 , true , 0 , true ) ;
break;
case V_45 :
F_14 ( V_1 -> V_50 ,
F_17 ( V_13 -> V_48 ) ,
V_52 ) ;
F_18 ( V_1 -> V_50 , V_30 , V_31 ) ;
switch ( V_13 -> V_48 ) {
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
F_16 ( V_1 -> V_50 , false , 0 , false ) ;
break;
default:
break;
}
}
V_40 = F_19 ( V_1 -> V_62 , V_32 ) ;
if ( V_40 ) {
F_15 ( V_22 , L_4 , V_40 ) ;
return V_40 ;
}
V_40 = F_20 ( V_1 -> V_62 ,
F_5 ( V_32 , V_33 ,
F_3 ( V_6 ) ) , 64 ) ;
if ( V_40 ) {
F_15 ( V_22 , L_5 , V_40 ) ;
return V_40 ;
}
F_21 ( V_1 -> V_3 ) ;
F_22 ( V_1 -> V_3 , V_36 , V_37 ) ;
V_40 = F_23 ( V_1 -> V_3 , V_13 -> V_48 ) ;
if ( V_40 < 0 ) {
F_15 ( V_22 , L_6 ,
V_13 -> V_48 ) ;
return V_40 ;
}
F_24 ( V_1 -> V_3 ) ;
F_25 ( V_1 -> V_3 , 1 ) ;
F_26 ( V_1 -> V_3 , V_13 -> V_25 [ 0 ] ) ;
V_40 = F_6 ( V_1 , V_13 , V_34 , V_35 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_38 )
F_27 ( V_1 -> V_3 , V_13 -> V_25 [ 0 ] ) ;
V_1 -> V_46 = V_36 ;
V_1 -> V_47 = V_37 ;
return 0 ;
}
void F_28 ( struct V_1 * V_1 )
{
if ( ! F_29 ( V_1 -> V_50 ) )
F_30 ( V_1 -> V_50 ) ;
if ( ! F_29 ( V_1 -> V_62 ) )
F_31 ( V_1 -> V_62 ) ;
if ( ! F_29 ( V_1 -> V_3 ) )
F_32 ( V_1 -> V_3 ) ;
}
int F_33 ( struct V_1 * V_1 )
{
int V_40 ;
V_1 -> V_3 = F_34 ( V_1 -> V_2 , V_1 -> V_63 ) ;
if ( F_35 ( V_1 -> V_3 ) ) {
V_40 = F_36 ( V_1 -> V_3 ) ;
F_37 ( L_7 , V_40 ) ;
return V_40 ;
}
V_1 -> V_62 = F_38 ( V_1 -> V_2 , V_1 -> V_63 ) ;
if ( F_35 ( V_1 -> V_62 ) ) {
V_40 = F_36 ( V_1 -> V_62 ) ;
F_37 ( L_8 , V_40 ) ;
goto V_64;
}
if ( V_1 -> V_44 >= 0 ) {
V_1 -> V_50 = F_39 ( V_1 -> V_2 , V_1 -> V_44 ) ;
if ( F_35 ( V_1 -> V_50 ) ) {
V_40 = F_36 ( V_1 -> V_50 ) ;
F_37 ( L_9 , V_40 ) ;
goto V_64;
}
}
return 0 ;
V_64:
F_28 ( V_1 ) ;
return V_40 ;
}
void F_40 ( struct V_1 * V_1 )
{
if ( V_1 -> V_50 )
F_41 ( V_1 -> V_2 ) ;
F_42 ( V_1 -> V_62 ) ;
F_43 ( V_1 -> V_3 ) ;
if ( V_1 -> V_50 )
F_44 ( V_1 -> V_50 ) ;
V_1 -> V_27 = true ;
}
void F_45 ( struct V_1 * V_1 )
{
V_1 -> V_27 = false ;
F_46 ( V_1 -> V_3 , 50 ) ;
if ( V_1 -> V_50 )
F_47 ( V_1 -> V_50 ) ;
F_48 ( V_1 -> V_3 ) ;
F_49 ( V_1 -> V_62 ) ;
if ( V_1 -> V_50 )
F_50 ( V_1 -> V_2 ) ;
}
static int F_51 ( struct V_65 * V_66 , struct V_28 * V_29 ,
struct V_12 * V_13 , int V_30 , int V_31 ,
unsigned int V_32 , unsigned int V_33 ,
T_1 V_34 , T_1 V_35 ,
T_1 V_36 , T_1 V_37 )
{
struct V_1 * V_1 = F_52 ( V_66 ) ;
int V_40 = 0 ;
F_8 ( L_10 , V_66 ) ;
if ( ! V_1 -> V_27 )
V_40 = F_33 ( V_1 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_13 ( V_1 , V_29 , & V_29 -> V_67 , V_13 ,
V_30 , V_31 , V_32 , V_33 ,
V_34 >> 16 , V_35 >> 16 , V_36 >> 16 , V_37 >> 16 ,
false ) ;
if ( V_40 < 0 ) {
F_28 ( V_1 ) ;
return V_40 ;
}
if ( V_29 != V_66 -> V_29 )
F_53 ( V_66 -> V_22 -> V_22 , L_11 ,
V_66 -> V_29 , V_29 ) ;
V_66 -> V_29 = V_29 ;
if ( ! V_1 -> V_27 )
F_40 ( V_1 ) ;
return 0 ;
}
static int F_54 ( struct V_65 * V_66 )
{
struct V_1 * V_1 = F_52 ( V_66 ) ;
F_8 ( L_12 , __LINE__ , V_68 ) ;
if ( V_1 -> V_27 )
F_45 ( V_1 ) ;
F_28 ( V_1 ) ;
return 0 ;
}
static void F_55 ( struct V_65 * V_66 )
{
struct V_1 * V_1 = F_52 ( V_66 ) ;
F_8 ( L_12 , __LINE__ , V_68 ) ;
F_54 ( V_66 ) ;
F_56 ( V_66 ) ;
F_57 ( V_1 ) ;
}
struct V_1 * F_58 ( struct V_69 * V_22 , struct V_70 * V_2 ,
int V_63 , int V_50 , unsigned int V_71 ,
enum V_72 type )
{
struct V_1 * V_1 ;
int V_40 ;
F_8 ( L_13 ,
V_63 , V_50 , V_71 ) ;
V_1 = F_59 ( sizeof( * V_1 ) , V_73 ) ;
if ( ! V_1 ) {
F_37 ( L_14 ) ;
return F_60 ( - V_74 ) ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_63 = V_63 ;
V_1 -> V_44 = V_50 ;
V_40 = F_61 ( V_22 , & V_1 -> V_21 , V_71 ,
& V_75 , V_76 ,
F_62 ( V_76 ) , type ,
NULL ) ;
if ( V_40 ) {
F_37 ( L_15 ) ;
F_57 ( V_1 ) ;
return F_60 ( V_40 ) ;
}
return V_1 ;
}
