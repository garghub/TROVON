static T_1 F_1 ( struct V_1 * V_2 )
{
const T_2 * V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_2 , 0 , 1 , & V_4 ) ;
if ( ! V_3 )
return F_3 ( 0 ) ;
switch ( * V_3 >> 4 ) {
case 4 :
return F_3 ( V_5 ) ;
case 6 :
return F_3 ( V_6 ) ;
}
return F_3 ( 0 ) ;
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
if ( F_5 ( V_8 -> V_11 ) )
F_6 ( V_10 ) ;
}
static void F_7 ( struct V_12 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_13 ;
if ( V_11 -> V_14 == V_15 ) {
struct V_9 * V_10 = V_8 -> V_10 ;
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
}
}
static int F_10 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
int V_16 = 0 ;
T_1 V_17 = F_1 ( V_2 ) ;
if ( ! V_17 ) {
V_16 = - V_18 ;
goto V_19;
}
if ( F_11 ( V_2 ) & 3 ) {
struct V_1 * V_20 , * V_21 ;
int V_22 = 0 ;
V_20 = F_12 ( V_10 , 0 ) ;
if ( ! V_20 ) {
V_16 = - V_23 ;
goto V_19;
}
F_13 ( V_20 ) -> V_24 = V_2 ;
V_20 -> V_25 += V_2 -> V_25 ;
V_20 -> V_26 += V_20 -> V_25 ;
V_20 -> V_27 += V_20 -> V_25 ;
F_14 (skb, fs)
V_22 += V_21 -> V_25 ;
V_2 -> V_28 = F_13 ( V_2 ) -> V_24 ;
F_15 ( V_2 ) ;
V_2 -> V_25 -= V_22 ;
V_2 -> V_26 -= V_22 ;
V_2 -> V_27 -= V_22 ;
V_2 = V_20 ;
}
V_2 -> V_17 = V_17 ;
F_16 ( V_2 ) ;
V_2 -> V_10 = V_10 ;
if ( F_17 ( V_10 -> V_29 & V_30 ) ) {
V_10 -> V_31 . V_32 ++ ;
V_10 -> V_31 . V_33 += V_2 -> V_25 ;
F_18 ( V_2 ) ;
V_2 = NULL ;
} else
V_16 = - V_34 ;
V_19:
if ( V_2 ) {
F_19 ( V_2 ) ;
V_10 -> V_31 . V_35 ++ ;
}
return V_16 ;
}
static void F_20 ( struct V_12 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_13 ;
struct V_1 * V_2 ;
while ( ( V_2 = F_21 ( V_11 ) ) != NULL ) {
F_22 ( V_2 ) ;
F_10 ( V_8 , V_2 ) ;
}
}
static void F_23 ( struct V_12 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_13 ;
if ( F_24 ( V_8 -> V_10 ) )
F_4 ( V_8 ) ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = F_26 ( V_10 ) ;
F_4 ( V_8 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
F_8 ( V_10 ) ;
return 0 ;
}
static T_3 F_28 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_7 * V_8 = F_26 ( V_10 ) ;
struct V_12 * V_11 = V_8 -> V_11 ;
int V_25 , V_16 ;
switch ( V_2 -> V_17 ) {
case F_3 ( V_5 ) :
case F_3 ( V_6 ) :
break;
default:
F_19 ( V_2 ) ;
return V_36 ;
}
F_22 ( V_2 ) ;
F_29 ( V_2 , V_11 ) ;
V_25 = V_2 -> V_25 ;
V_16 = F_30 ( V_11 , V_2 ) ;
if ( V_16 ) {
F_31 ( L_1 , V_10 -> V_37 , V_16 ) ;
V_10 -> V_31 . V_38 ++ ;
V_10 -> V_31 . V_39 ++ ;
} else {
V_10 -> V_31 . V_40 ++ ;
V_10 -> V_31 . V_41 += V_25 ;
}
F_8 ( V_10 ) ;
if ( F_5 ( V_11 ) )
F_6 ( V_10 ) ;
return V_36 ;
}
static void F_32 ( struct V_9 * V_10 )
{
V_10 -> V_42 = V_43 ;
V_10 -> type = V_44 ;
V_10 -> V_29 = V_45 | V_46 ;
V_10 -> V_47 = V_48 ;
V_10 -> V_49 = 576 ;
V_10 -> V_50 = ( V_51 - 11 ) ;
V_10 -> V_52 = 0 ;
V_10 -> V_53 = 0 ;
V_10 -> V_54 = 10 ;
V_10 -> V_55 = & V_56 ;
V_10 -> V_57 = V_58 ;
}
int F_33 ( struct V_12 * V_11 )
{
static const char V_59 [] = L_2 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_16 ;
if ( F_34 ( V_11 -> V_60 == V_61 ) )
return - V_18 ;
V_10 = F_35 ( sizeof( * V_8 ) , V_59 , V_62 , F_32 ) ;
if ( ! V_10 )
return - V_63 ;
V_8 = F_26 ( V_10 ) ;
V_8 -> V_11 = V_11 ;
V_8 -> V_10 = V_10 ;
F_8 ( V_10 ) ;
V_16 = F_36 ( V_10 ) ;
if ( V_16 ) {
V_58 ( V_10 ) ;
return V_16 ;
}
F_37 ( V_11 ) ;
if ( F_34 ( V_11 -> V_13 ) ) {
V_16 = - V_64 ;
goto V_65;
}
if ( F_34 ( ( 1 << V_11 -> V_14 & ( V_66 | V_67 ) ) ||
F_38 ( V_11 , V_68 ) ) ) {
V_16 = - V_18 ;
goto V_65;
}
V_11 -> V_13 = V_8 ;
V_8 -> V_69 = V_11 -> V_70 ;
V_8 -> V_71 = V_11 -> V_72 ;
V_8 -> V_73 = V_11 -> V_74 ;
V_11 -> V_70 = F_7 ;
V_11 -> V_72 = F_20 ;
V_11 -> V_74 = F_23 ;
F_39 ( V_11 ) ;
F_40 ( V_11 ) ;
F_41 ( V_75 L_3 , V_10 -> V_37 ) ;
return V_10 -> V_76 ;
V_65:
F_39 ( V_11 ) ;
F_42 ( V_10 ) ;
return V_16 ;
}
void F_43 ( struct V_12 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_13 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_37 ( V_11 ) ;
V_11 -> V_13 = NULL ;
V_11 -> V_70 = V_8 -> V_69 ;
V_11 -> V_72 = V_8 -> V_71 ;
V_11 -> V_74 = V_8 -> V_73 ;
F_39 ( V_11 ) ;
F_41 ( V_75 L_4 , V_10 -> V_37 ) ;
F_42 ( V_10 ) ;
F_44 ( V_11 ) ;
}
