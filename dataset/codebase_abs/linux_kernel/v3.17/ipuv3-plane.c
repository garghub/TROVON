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
unsigned long V_20 ;
V_19 = F_7 ( V_13 , 0 ) ;
if ( ! V_19 ) {
F_8 ( L_1 ) ;
return - V_21 ;
}
F_9 ( V_1 -> V_22 . V_23 -> V_23 , L_2 ,
& V_19 -> V_24 , V_14 , V_15 ) ;
V_17 = F_10 ( V_1 -> V_3 ) ;
F_11 ( V_17 , V_13 -> V_25 [ 0 ] ) ;
V_20 = V_19 -> V_24 + V_13 -> V_26 [ 0 ] +
V_13 -> V_25 [ 0 ] * V_15 + ( V_13 -> V_27 >> 3 ) * V_14 ;
F_12 ( V_17 , 0 , V_20 ) ;
F_12 ( V_17 , 1 , V_20 ) ;
V_1 -> V_14 = V_14 ;
V_1 -> V_15 = V_15 ;
return 0 ;
}
int F_13 ( struct V_1 * V_1 , struct V_28 * V_29 ,
struct V_5 * V_6 ,
struct V_12 * V_13 , int V_30 , int V_31 ,
unsigned int V_32 , unsigned int V_33 ,
T_2 V_34 , T_2 V_35 ,
T_2 V_36 , T_2 V_37 )
{
struct V_16 T_1 * V_17 ;
struct V_38 * V_23 = V_1 -> V_22 . V_23 -> V_23 ;
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
switch ( V_1 -> V_43 ) {
case V_45 :
V_39 = F_14 ( V_1 -> V_46 ,
V_47 ,
V_47 ) ;
if ( V_39 ) {
F_15 ( V_23 ,
L_3 ,
V_39 ) ;
return V_39 ;
}
F_16 ( V_1 -> V_46 , 1 , 0 , 1 ) ;
break;
case V_44 :
F_14 ( V_1 -> V_46 ,
F_17 ( V_13 -> V_48 ) ,
V_49 ) ;
F_18 ( V_1 -> V_46 , V_30 , V_31 ) ;
break;
}
V_39 = F_19 ( V_1 -> V_50 , V_32 ) ;
if ( V_39 ) {
F_15 ( V_23 , L_4 , V_39 ) ;
return V_39 ;
}
V_39 = F_20 ( V_1 -> V_50 ,
F_5 ( V_32 , V_33 ,
F_3 ( V_6 ) ) , 64 ) ;
if ( V_39 ) {
F_15 ( V_23 , L_5 , V_39 ) ;
return V_39 ;
}
V_17 = F_10 ( V_1 -> V_3 ) ;
F_21 ( V_17 ) ;
F_22 ( V_17 , V_36 , V_37 ) ;
V_39 = F_23 ( V_17 , V_13 -> V_48 ) ;
if ( V_39 < 0 ) {
F_15 ( V_23 , L_6 ,
V_13 -> V_48 ) ;
return V_39 ;
}
F_24 ( V_1 -> V_3 ) ;
V_39 = F_6 ( V_1 , V_13 , V_34 , V_35 ) ;
if ( V_39 < 0 )
return V_39 ;
return 0 ;
}
void F_25 ( struct V_1 * V_1 )
{
if ( ! F_26 ( V_1 -> V_46 ) )
F_27 ( V_1 -> V_46 ) ;
if ( ! F_26 ( V_1 -> V_50 ) )
F_28 ( V_1 -> V_50 ) ;
if ( ! F_26 ( V_1 -> V_3 ) )
F_29 ( V_1 -> V_3 ) ;
}
int F_30 ( struct V_1 * V_1 )
{
int V_39 ;
V_1 -> V_3 = F_31 ( V_1 -> V_2 , V_1 -> V_51 ) ;
if ( F_32 ( V_1 -> V_3 ) ) {
V_39 = F_33 ( V_1 -> V_3 ) ;
F_34 ( L_7 , V_39 ) ;
return V_39 ;
}
V_1 -> V_50 = F_35 ( V_1 -> V_2 , V_1 -> V_51 ) ;
if ( F_32 ( V_1 -> V_50 ) ) {
V_39 = F_33 ( V_1 -> V_50 ) ;
F_34 ( L_8 , V_39 ) ;
goto V_52;
}
if ( V_1 -> V_43 >= 0 ) {
V_1 -> V_46 = F_36 ( V_1 -> V_2 , V_1 -> V_43 ) ;
if ( F_32 ( V_1 -> V_46 ) ) {
V_39 = F_33 ( V_1 -> V_46 ) ;
F_34 ( L_9 , V_39 ) ;
goto V_52;
}
}
return 0 ;
V_52:
F_25 ( V_1 ) ;
return V_39 ;
}
void F_37 ( struct V_1 * V_1 )
{
if ( V_1 -> V_46 )
F_38 ( V_1 -> V_2 ) ;
F_39 ( V_1 -> V_50 ) ;
F_40 ( V_1 -> V_3 ) ;
if ( V_1 -> V_46 )
F_41 ( V_1 -> V_46 ) ;
V_1 -> V_53 = true ;
}
void F_42 ( struct V_1 * V_1 )
{
V_1 -> V_53 = false ;
F_43 ( V_1 -> V_3 , 50 ) ;
if ( V_1 -> V_46 )
F_44 ( V_1 -> V_46 ) ;
F_45 ( V_1 -> V_3 ) ;
F_46 ( V_1 -> V_50 ) ;
if ( V_1 -> V_46 )
F_47 ( V_1 -> V_2 ) ;
}
static void F_48 ( struct V_1 * V_1 , int V_6 )
{
bool V_54 ;
F_8 ( L_10 , V_6 ) ;
V_54 = ( V_6 == V_55 ) ;
if ( V_54 == V_1 -> V_53 )
return;
if ( V_54 ) {
F_37 ( V_1 ) ;
} else {
F_42 ( V_1 ) ;
F_29 ( V_1 -> V_3 ) ;
F_28 ( V_1 -> V_50 ) ;
if ( V_1 -> V_46 )
F_27 ( V_1 -> V_46 ) ;
}
}
static int F_49 ( struct V_56 * V_57 , struct V_28 * V_29 ,
struct V_12 * V_13 , int V_30 , int V_31 ,
unsigned int V_32 , unsigned int V_33 ,
T_2 V_34 , T_2 V_35 ,
T_2 V_36 , T_2 V_37 )
{
struct V_1 * V_1 = F_50 ( V_57 ) ;
int V_39 = 0 ;
F_8 ( L_11 , V_57 ) ;
if ( ! V_1 -> V_53 )
V_39 = F_30 ( V_1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_13 ( V_1 , V_29 , & V_29 -> V_58 , V_13 ,
V_30 , V_31 , V_32 , V_33 ,
V_34 >> 16 , V_35 >> 16 , V_36 >> 16 , V_37 >> 16 ) ;
if ( V_39 < 0 ) {
F_25 ( V_1 ) ;
return V_39 ;
}
if ( V_29 != V_57 -> V_29 )
F_51 ( V_57 -> V_23 -> V_23 , L_12 ,
V_57 -> V_29 , V_29 ) ;
V_57 -> V_29 = V_29 ;
F_48 ( V_1 , V_55 ) ;
return 0 ;
}
static int F_52 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = F_50 ( V_57 ) ;
F_8 ( L_13 , __LINE__ , V_59 ) ;
F_48 ( V_1 , V_60 ) ;
F_25 ( V_1 ) ;
return 0 ;
}
static void F_53 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = F_50 ( V_57 ) ;
F_8 ( L_13 , __LINE__ , V_59 ) ;
F_52 ( V_57 ) ;
F_54 ( V_57 ) ;
F_55 ( V_1 ) ;
}
struct V_1 * F_56 ( struct V_61 * V_23 , struct V_62 * V_2 ,
int V_51 , int V_46 , unsigned int V_63 ,
bool V_64 )
{
struct V_1 * V_1 ;
int V_39 ;
F_8 ( L_14 ,
V_51 , V_46 , V_63 ) ;
V_1 = F_57 ( sizeof( * V_1 ) , V_65 ) ;
if ( ! V_1 ) {
F_34 ( L_15 ) ;
return F_58 ( - V_66 ) ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_51 = V_51 ;
V_1 -> V_43 = V_46 ;
V_39 = F_59 ( V_23 , & V_1 -> V_22 , V_63 ,
& V_67 , V_68 ,
F_60 ( V_68 ) ,
V_64 ) ;
if ( V_39 ) {
F_34 ( L_16 ) ;
F_55 ( V_1 ) ;
return F_58 ( V_39 ) ;
}
return V_1 ;
}
