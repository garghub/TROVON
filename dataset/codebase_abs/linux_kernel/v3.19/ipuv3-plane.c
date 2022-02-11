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
T_1 V_36 , T_1 V_37 )
{
struct V_38 * V_22 = V_1 -> V_21 . V_22 -> V_22 ;
int V_39 ;
if ( V_36 != V_32 || V_37 != V_33 )
return - V_40 ;
if ( V_30 < 0 ) {
if ( - V_30 > V_32 )
return - V_40 ;
V_34 += - V_30 ;
V_36 -= - V_30 ;
V_32 -= - V_30 ;
V_30 = 0 ;
}
if ( V_31 < 0 ) {
if ( - V_31 > V_33 )
return - V_40 ;
V_35 += - V_31 ;
V_37 -= - V_31 ;
V_33 -= - V_31 ;
V_31 = 0 ;
}
if ( V_30 + V_32 > V_6 -> V_41 ) {
if ( V_30 > V_6 -> V_41 )
return - V_40 ;
V_32 = V_6 -> V_41 - V_30 ;
V_36 = V_32 ;
}
if ( V_31 + V_33 > V_6 -> V_42 ) {
if ( V_31 > V_6 -> V_42 )
return - V_40 ;
V_33 = V_6 -> V_42 - V_31 ;
V_37 = V_33 ;
}
if ( V_32 < 13 && ( V_1 -> V_43 != V_44 ) )
return - V_40 ;
if ( V_33 < 2 )
return - V_40 ;
if ( V_1 -> V_27 ) {
if ( V_36 != V_1 -> V_45 || V_37 != V_1 -> V_46 ||
V_13 -> V_47 != V_1 -> V_21 . V_13 -> V_47 )
return - V_40 ;
return F_6 ( V_1 , V_13 , V_34 , V_35 ) ;
}
switch ( V_1 -> V_43 ) {
case V_48 :
V_39 = F_14 ( V_1 -> V_49 ,
V_50 ,
V_50 ) ;
if ( V_39 ) {
F_15 ( V_22 ,
L_3 ,
V_39 ) ;
return V_39 ;
}
F_16 ( V_1 -> V_49 , true , 0 , true ) ;
break;
case V_44 :
F_14 ( V_1 -> V_49 ,
F_17 ( V_13 -> V_47 ) ,
V_51 ) ;
F_18 ( V_1 -> V_49 , V_30 , V_31 ) ;
switch ( V_13 -> V_47 ) {
case V_52 :
case V_53 :
F_16 ( V_1 -> V_49 , false , 0 , false ) ;
break;
default:
break;
}
}
V_39 = F_19 ( V_1 -> V_54 , V_32 ) ;
if ( V_39 ) {
F_15 ( V_22 , L_4 , V_39 ) ;
return V_39 ;
}
V_39 = F_20 ( V_1 -> V_54 ,
F_5 ( V_32 , V_33 ,
F_3 ( V_6 ) ) , 64 ) ;
if ( V_39 ) {
F_15 ( V_22 , L_5 , V_39 ) ;
return V_39 ;
}
F_21 ( V_1 -> V_3 ) ;
F_22 ( V_1 -> V_3 , V_36 , V_37 ) ;
V_39 = F_23 ( V_1 -> V_3 , V_13 -> V_47 ) ;
if ( V_39 < 0 ) {
F_15 ( V_22 , L_6 ,
V_13 -> V_47 ) ;
return V_39 ;
}
F_24 ( V_1 -> V_3 ) ;
F_25 ( V_1 -> V_3 , 1 ) ;
F_26 ( V_1 -> V_3 , V_13 -> V_25 [ 0 ] ) ;
V_39 = F_6 ( V_1 , V_13 , V_34 , V_35 ) ;
if ( V_39 < 0 )
return V_39 ;
V_1 -> V_45 = V_36 ;
V_1 -> V_46 = V_37 ;
return 0 ;
}
void F_27 ( struct V_1 * V_1 )
{
if ( ! F_28 ( V_1 -> V_49 ) )
F_29 ( V_1 -> V_49 ) ;
if ( ! F_28 ( V_1 -> V_54 ) )
F_30 ( V_1 -> V_54 ) ;
if ( ! F_28 ( V_1 -> V_3 ) )
F_31 ( V_1 -> V_3 ) ;
}
int F_32 ( struct V_1 * V_1 )
{
int V_39 ;
V_1 -> V_3 = F_33 ( V_1 -> V_2 , V_1 -> V_55 ) ;
if ( F_34 ( V_1 -> V_3 ) ) {
V_39 = F_35 ( V_1 -> V_3 ) ;
F_36 ( L_7 , V_39 ) ;
return V_39 ;
}
V_1 -> V_54 = F_37 ( V_1 -> V_2 , V_1 -> V_55 ) ;
if ( F_34 ( V_1 -> V_54 ) ) {
V_39 = F_35 ( V_1 -> V_54 ) ;
F_36 ( L_8 , V_39 ) ;
goto V_56;
}
if ( V_1 -> V_43 >= 0 ) {
V_1 -> V_49 = F_38 ( V_1 -> V_2 , V_1 -> V_43 ) ;
if ( F_34 ( V_1 -> V_49 ) ) {
V_39 = F_35 ( V_1 -> V_49 ) ;
F_36 ( L_9 , V_39 ) ;
goto V_56;
}
}
return 0 ;
V_56:
F_27 ( V_1 ) ;
return V_39 ;
}
void F_39 ( struct V_1 * V_1 )
{
if ( V_1 -> V_49 )
F_40 ( V_1 -> V_2 ) ;
F_41 ( V_1 -> V_54 ) ;
F_42 ( V_1 -> V_3 ) ;
if ( V_1 -> V_49 )
F_43 ( V_1 -> V_49 ) ;
V_1 -> V_27 = true ;
}
void F_44 ( struct V_1 * V_1 )
{
V_1 -> V_27 = false ;
F_45 ( V_1 -> V_3 , 50 ) ;
if ( V_1 -> V_49 )
F_46 ( V_1 -> V_49 ) ;
F_47 ( V_1 -> V_3 ) ;
F_48 ( V_1 -> V_54 ) ;
if ( V_1 -> V_49 )
F_49 ( V_1 -> V_2 ) ;
}
static int F_50 ( struct V_57 * V_58 , struct V_28 * V_29 ,
struct V_12 * V_13 , int V_30 , int V_31 ,
unsigned int V_32 , unsigned int V_33 ,
T_1 V_34 , T_1 V_35 ,
T_1 V_36 , T_1 V_37 )
{
struct V_1 * V_1 = F_51 ( V_58 ) ;
int V_39 = 0 ;
F_8 ( L_10 , V_58 ) ;
if ( ! V_1 -> V_27 )
V_39 = F_32 ( V_1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_13 ( V_1 , V_29 , & V_29 -> V_59 , V_13 ,
V_30 , V_31 , V_32 , V_33 ,
V_34 >> 16 , V_35 >> 16 , V_36 >> 16 , V_37 >> 16 ) ;
if ( V_39 < 0 ) {
F_27 ( V_1 ) ;
return V_39 ;
}
if ( V_29 != V_58 -> V_29 )
F_52 ( V_58 -> V_22 -> V_22 , L_11 ,
V_58 -> V_29 , V_29 ) ;
V_58 -> V_29 = V_29 ;
if ( ! V_1 -> V_27 )
F_39 ( V_1 ) ;
return 0 ;
}
static int F_53 ( struct V_57 * V_58 )
{
struct V_1 * V_1 = F_51 ( V_58 ) ;
F_8 ( L_12 , __LINE__ , V_60 ) ;
if ( V_1 -> V_27 )
F_44 ( V_1 ) ;
F_27 ( V_1 ) ;
return 0 ;
}
static void F_54 ( struct V_57 * V_58 )
{
struct V_1 * V_1 = F_51 ( V_58 ) ;
F_8 ( L_12 , __LINE__ , V_60 ) ;
F_53 ( V_58 ) ;
F_55 ( V_58 ) ;
F_56 ( V_1 ) ;
}
struct V_1 * F_57 ( struct V_61 * V_22 , struct V_62 * V_2 ,
int V_55 , int V_49 , unsigned int V_63 ,
bool V_64 )
{
struct V_1 * V_1 ;
int V_39 ;
F_8 ( L_13 ,
V_55 , V_49 , V_63 ) ;
V_1 = F_58 ( sizeof( * V_1 ) , V_65 ) ;
if ( ! V_1 ) {
F_36 ( L_14 ) ;
return F_59 ( - V_66 ) ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_55 = V_55 ;
V_1 -> V_43 = V_49 ;
V_39 = F_60 ( V_22 , & V_1 -> V_21 , V_63 ,
& V_67 , V_68 ,
F_61 ( V_68 ) ,
V_64 ) ;
if ( V_39 ) {
F_36 ( L_15 ) ;
F_56 ( V_1 ) ;
return F_59 ( V_39 ) ;
}
return V_1 ;
}
