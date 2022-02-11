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
struct V_16 T_1 * V_17 ;
struct V_18 * V_19 ;
V_19 = F_7 ( V_13 , 0 ) ;
if ( ! V_19 ) {
F_8 ( L_1 ) ;
return - V_20 ;
}
F_9 ( V_1 -> V_21 . V_22 -> V_22 , L_2 ,
V_19 -> V_23 , V_14 , V_15 ) ;
V_17 = F_10 ( V_1 -> V_3 ) ;
F_11 ( V_17 , V_13 -> V_24 [ 0 ] ) ;
F_12 ( V_17 , 0 , V_19 -> V_23 + V_13 -> V_25 [ 0 ] +
V_13 -> V_24 [ 0 ] * V_15 + V_14 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_1 , struct V_26 * V_27 ,
struct V_5 * V_6 ,
struct V_12 * V_13 , int V_28 , int V_29 ,
unsigned int V_30 , unsigned int V_31 ,
T_2 V_32 , T_2 V_33 ,
T_2 V_34 , T_2 V_35 )
{
struct V_16 T_1 * V_17 ;
struct V_36 * V_22 = V_1 -> V_21 . V_22 -> V_22 ;
int V_37 ;
if ( V_34 != V_30 || V_35 != V_31 )
return - V_38 ;
if ( V_28 < 0 ) {
if ( - V_28 > V_30 )
return - V_38 ;
V_32 += - V_28 ;
V_34 -= - V_28 ;
V_30 -= - V_28 ;
V_28 = 0 ;
}
if ( V_29 < 0 ) {
if ( - V_29 > V_31 )
return - V_38 ;
V_33 += - V_29 ;
V_35 -= - V_29 ;
V_31 -= - V_29 ;
V_29 = 0 ;
}
if ( V_28 + V_30 > V_6 -> V_39 ) {
if ( V_28 > V_6 -> V_39 )
return - V_38 ;
V_30 = V_6 -> V_39 - V_28 ;
V_34 = V_30 ;
}
if ( V_29 + V_31 > V_6 -> V_40 ) {
if ( V_29 > V_6 -> V_40 )
return - V_38 ;
V_31 = V_6 -> V_40 - V_29 ;
V_35 = V_31 ;
}
if ( V_30 < 13 && ( V_1 -> V_41 != V_42 ) )
return - V_38 ;
if ( V_31 < 2 )
return - V_38 ;
switch ( V_1 -> V_41 ) {
case V_43 :
V_37 = F_14 ( V_1 -> V_44 ,
V_45 ,
V_45 ) ;
if ( V_37 ) {
F_15 ( V_22 ,
L_3 ,
V_37 ) ;
return V_37 ;
}
F_16 ( V_1 -> V_44 , 1 , 0 , 1 ) ;
break;
case V_42 :
F_14 ( V_1 -> V_44 ,
F_17 ( V_13 -> V_46 ) ,
V_47 ) ;
F_18 ( V_1 -> V_44 , V_28 , V_29 ) ;
break;
}
V_37 = F_19 ( V_1 -> V_48 , V_30 ) ;
if ( V_37 ) {
F_15 ( V_22 , L_4 , V_37 ) ;
return V_37 ;
}
V_37 = F_20 ( V_1 -> V_48 ,
F_5 ( V_30 , V_31 ,
F_3 ( V_6 ) ) , 64 ) ;
if ( V_37 ) {
F_15 ( V_22 , L_5 , V_37 ) ;
return V_37 ;
}
V_17 = F_10 ( V_1 -> V_3 ) ;
F_21 ( V_17 ) ;
F_22 ( V_17 , V_34 , V_35 ) ;
V_37 = F_23 ( V_17 , V_13 -> V_46 ) ;
if ( V_37 < 0 ) {
F_15 ( V_22 , L_6 ,
V_13 -> V_46 ) ;
return V_37 ;
}
F_24 ( V_1 -> V_3 ) ;
V_37 = F_6 ( V_1 , V_13 , V_32 , V_33 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
void F_25 ( struct V_1 * V_1 )
{
if ( ! F_26 ( V_1 -> V_44 ) )
F_27 ( V_1 -> V_44 ) ;
if ( ! F_26 ( V_1 -> V_48 ) )
F_28 ( V_1 -> V_48 ) ;
if ( ! F_26 ( V_1 -> V_3 ) )
F_29 ( V_1 -> V_3 ) ;
}
int F_30 ( struct V_1 * V_1 )
{
int V_37 ;
V_1 -> V_3 = F_31 ( V_1 -> V_2 , V_1 -> V_49 ) ;
if ( F_32 ( V_1 -> V_3 ) ) {
V_37 = F_33 ( V_1 -> V_3 ) ;
F_34 ( L_7 , V_37 ) ;
return V_37 ;
}
V_1 -> V_48 = F_35 ( V_1 -> V_2 , V_1 -> V_49 ) ;
if ( F_32 ( V_1 -> V_48 ) ) {
V_37 = F_33 ( V_1 -> V_48 ) ;
F_34 ( L_8 , V_37 ) ;
goto V_50;
}
if ( V_1 -> V_41 >= 0 ) {
V_1 -> V_44 = F_36 ( V_1 -> V_2 , V_1 -> V_41 ) ;
if ( F_32 ( V_1 -> V_44 ) ) {
V_37 = F_33 ( V_1 -> V_44 ) ;
F_34 ( L_9 , V_37 ) ;
goto V_50;
}
}
return 0 ;
V_50:
F_25 ( V_1 ) ;
return V_37 ;
}
void F_37 ( struct V_1 * V_1 )
{
F_38 ( V_1 -> V_48 ) ;
F_39 ( V_1 -> V_3 ) ;
if ( V_1 -> V_44 )
F_40 ( V_1 -> V_44 ) ;
V_1 -> V_51 = true ;
}
void F_41 ( struct V_1 * V_1 )
{
V_1 -> V_51 = false ;
F_42 ( V_1 -> V_3 , 50 ) ;
if ( V_1 -> V_44 )
F_43 ( V_1 -> V_44 ) ;
F_44 ( V_1 -> V_3 ) ;
F_45 ( V_1 -> V_48 ) ;
}
static void F_46 ( struct V_1 * V_1 , int V_6 )
{
bool V_52 ;
F_47 ( L_10 , V_6 ) ;
V_52 = ( V_6 == V_53 ) ;
if ( V_52 == V_1 -> V_51 )
return;
if ( V_52 ) {
F_37 ( V_1 ) ;
} else {
F_41 ( V_1 ) ;
F_29 ( V_1 -> V_3 ) ;
F_28 ( V_1 -> V_48 ) ;
F_27 ( V_1 -> V_44 ) ;
}
}
static int F_48 ( struct V_54 * V_55 , struct V_26 * V_27 ,
struct V_12 * V_13 , int V_28 , int V_29 ,
unsigned int V_30 , unsigned int V_31 ,
T_2 V_32 , T_2 V_33 ,
T_2 V_34 , T_2 V_35 )
{
struct V_1 * V_1 = F_49 ( V_55 ) ;
int V_37 = 0 ;
F_47 ( L_11 , V_55 ) ;
if ( ! V_1 -> V_51 )
V_37 = F_30 ( V_1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_13 ( V_1 , V_27 , & V_27 -> V_56 , V_13 ,
V_28 , V_29 , V_30 , V_31 ,
V_32 >> 16 , V_33 >> 16 , V_34 >> 16 , V_35 >> 16 ) ;
if ( V_37 < 0 ) {
F_25 ( V_1 ) ;
return V_37 ;
}
if ( V_27 != V_55 -> V_27 )
F_50 ( V_55 -> V_22 -> V_22 , L_12 ,
V_55 -> V_27 , V_27 ) ;
V_55 -> V_27 = V_27 ;
F_46 ( V_1 , V_53 ) ;
return 0 ;
}
static int F_51 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_49 ( V_55 ) ;
F_47 ( L_13 , __LINE__ , V_57 ) ;
F_46 ( V_1 , V_58 ) ;
F_25 ( V_1 ) ;
return 0 ;
}
static void F_52 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_49 ( V_55 ) ;
F_47 ( L_13 , __LINE__ , V_57 ) ;
F_51 ( V_55 ) ;
F_53 ( V_55 ) ;
F_54 ( V_1 ) ;
}
struct V_1 * F_55 ( struct V_59 * V_22 , struct V_60 * V_2 ,
int V_49 , int V_44 , unsigned int V_61 ,
bool V_62 )
{
struct V_1 * V_1 ;
int V_37 ;
F_47 ( L_14 ,
V_49 , V_44 , V_61 ) ;
V_1 = F_56 ( sizeof( * V_1 ) , V_63 ) ;
if ( ! V_1 ) {
F_34 ( L_15 ) ;
return F_57 ( - V_64 ) ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_49 = V_49 ;
V_1 -> V_41 = V_44 ;
V_37 = F_58 ( V_22 , & V_1 -> V_21 , V_61 ,
& V_65 , V_66 ,
F_59 ( V_66 ) ,
V_62 ) ;
if ( V_37 ) {
F_34 ( L_16 ) ;
F_54 ( V_1 ) ;
return F_57 ( V_37 ) ;
}
return V_1 ;
}
