static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_9 * V_10 = F_4 ( V_8 -> V_11 , struct V_9 , V_12 ) ;
int V_13 = F_5 ( V_10 -> V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_3 = F_6 ( V_10 -> V_14 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_9 * V_10 = F_4 ( V_8 -> V_11 , struct V_9 , V_12 ) ;
F_8 ( V_10 -> V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_15 )
{
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
V_17 -> V_19 ( V_2 , V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
return V_17 -> V_20 ( V_2 ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
int V_21 = 1000 ;
while ( -- V_21 && ! ( F_12 ( V_8 , V_22 ) & ( 1 << 13 ) ) )
F_13 ( 1 ) ;
if ( ! V_21 ) {
F_14 ( V_8 -> V_11 -> V_6 , L_1 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 , int V_24 )
{
switch ( V_24 )
{
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return F_11 ( V_8 ) ;
}
return 0 ;
}
static void F_16 ( const struct V_1 * V_2 )
{
F_17 ( F_2 ( & V_2 -> V_6 ) , F_18 ( 100 ) ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 =
F_20 ( V_35 , & V_2 -> V_6 ) ;
struct V_9 * V_10 ;
struct V_36 * V_12 ;
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
struct V_7 * V_8 ;
int V_37 , V_13 , V_38 = 0 ;
bool V_39 = true ;
V_10 = F_21 ( & V_2 -> V_6 , sizeof( struct V_9 ) , V_40 ) ;
if ( V_10 == NULL ) {
F_22 ( & V_2 -> V_6 , L_2 ) ;
return - V_41 ;
}
V_12 = & V_10 -> V_12 ;
if ( V_17 ) {
if ( V_17 -> V_42 ) {
V_13 = V_17 -> V_42 ( V_2 , & V_43 ) ;
if ( V_13 )
return V_13 ;
}
}
V_10 -> V_14 = F_23 ( & V_2 -> V_6 , NULL ) ;
if ( F_24 ( V_10 -> V_14 ) ) {
V_13 = F_25 ( V_10 -> V_14 ) ;
F_22 ( & V_2 -> V_6 , L_3 , V_13 ) ;
goto V_44;
}
V_12 -> F_5 = F_1 ;
V_12 -> F_8 = F_7 ;
V_12 -> V_45 = V_46 ;
V_12 -> V_47 = F_15 ;
if ( V_17 ) {
V_12 -> V_48 = V_17 -> V_49 ;
V_12 -> V_50 = V_17 -> V_51 ;
V_12 -> V_45 |= V_17 -> V_52 ;
V_12 -> V_53 |= V_17 -> V_54 ;
V_12 -> V_55 = V_17 -> V_55 ;
if ( V_17 -> V_19 )
V_12 -> V_19 = F_9 ;
if ( V_17 -> V_20 )
V_12 -> V_20 = F_10 ;
if ( V_17 -> V_56 > 0 && V_17 -> V_57 > 0 ) {
V_10 -> V_58 . V_59 . V_60 = V_17 -> V_56 ;
V_10 -> V_61 . V_59 . V_60 = V_17 -> V_57 ;
V_10 -> V_62 . V_63 = & V_10 -> V_58 . V_59 ;
V_10 -> V_62 . V_64 = & V_10 -> V_61 . V_59 ;
V_10 -> V_62 . V_65 = 1 ;
V_12 -> V_66 = & V_10 -> V_62 ;
}
}
V_12 -> V_48 |= V_67 ;
V_12 -> V_48 |= V_68 ;
if ( V_34 && V_34 -> V_69 ) {
const struct V_70 * V_71 = V_34 -> V_69 ;
V_12 -> V_48 |= V_71 -> V_49 ;
}
V_13 = F_26 ( & V_8 , V_2 , V_12 ) ;
if ( V_13 < 0 )
goto V_72;
V_37 = F_27 ( V_2 , V_73 ) ;
if ( V_37 >= 0 ) {
V_39 = false ;
V_13 = F_28 ( & V_2 -> V_6 , V_37 , V_74 , 0 ,
F_29 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_75;
}
V_37 = F_27 ( V_2 , V_76 ) ;
if ( V_37 >= 0 ) {
V_39 = false ;
V_13 = F_28 ( & V_2 -> V_6 , V_37 , V_77 , 0 ,
F_29 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_75;
}
V_37 = F_27 ( V_2 , V_78 ) ;
if ( V_37 >= 0 ) {
V_39 = false ;
V_13 = F_28 ( & V_2 -> V_6 , V_37 , V_79 , 0 ,
F_29 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_75;
} else if ( ! V_39 ) {
F_22 ( & V_2 -> V_6 ,
L_4 ) ;
V_13 = V_37 ;
goto V_75;
}
if ( V_39 ) {
while ( 1 ) {
V_37 = F_30 ( V_2 , V_38 ) ;
if ( V_37 < 0 )
break;
V_38 ++ ;
V_13 = F_28 ( & V_2 -> V_6 , V_37 , V_80 , 0 ,
F_29 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_75;
}
if ( ! V_38 )
goto V_75;
}
F_31 ( & V_2 -> V_6 , L_5 ,
F_32 ( V_8 -> V_5 ) , ( unsigned long )
( F_33 ( V_2 , V_81 , 0 ) -> V_82 ) ,
V_8 -> V_5 -> V_83 / 1000000 ) ;
return V_13 ;
V_75:
F_34 ( V_8 ) ;
V_72:
V_44:
if ( V_17 && V_17 -> V_84 )
V_17 -> V_84 ( V_2 ) ;
return V_13 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_36 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
F_34 ( V_8 ) ;
if ( V_17 && V_17 -> V_84 )
V_17 -> V_84 ( V_2 ) ;
return 0 ;
}
