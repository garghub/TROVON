static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 -> V_10 , struct V_8 , V_11 ) ;
int V_12 = F_5 ( V_9 -> V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_3 = F_6 ( V_9 -> V_13 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 -> V_10 , struct V_8 , V_11 ) ;
F_8 ( V_9 -> V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 . V_18 ;
V_16 -> V_19 ( V_2 , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 . V_18 ;
return V_16 -> V_20 ( V_2 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
int V_21 = 1000 ;
while ( -- V_21 && ! ( F_12 ( V_7 , V_22 ) & ( 1 << 13 ) ) )
F_13 ( 1 ) ;
if ( ! V_21 ) {
F_14 ( V_7 -> V_10 -> V_17 , L_1 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , int V_24 )
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
return F_11 ( V_7 ) ;
}
return 0 ;
}
static void F_16 ( const struct V_1 * V_2 )
{
F_17 ( F_2 ( V_2 ) , F_18 ( 100 ) ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 =
F_20 ( V_35 , & V_2 -> V_17 ) ;
struct V_8 * V_9 ;
struct V_36 * V_11 ;
struct V_15 * V_16 = V_2 -> V_17 . V_18 ;
struct V_6 * V_7 ;
int V_37 , V_12 , V_38 = 0 ;
bool V_39 = true ;
struct V_40 * V_41 ;
V_9 = F_21 ( & V_2 -> V_17 , sizeof( struct V_8 ) , V_42 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_2 -> V_17 , L_2 ) ;
return - V_43 ;
}
V_11 = & V_9 -> V_11 ;
V_41 = & V_9 -> V_41 ;
if ( V_16 ) {
if ( V_16 -> V_44 ) {
V_12 = V_16 -> V_44 ( V_2 , & V_45 ) ;
if ( V_12 )
return V_12 ;
}
}
V_9 -> V_13 = F_23 ( & V_2 -> V_17 , NULL ) ;
if ( F_24 ( V_9 -> V_13 ) ) {
V_12 = F_25 ( V_9 -> V_13 ) ;
F_22 ( & V_2 -> V_17 , L_3 , V_12 ) ;
goto V_46;
}
V_11 -> F_5 = F_1 ;
V_11 -> F_8 = F_7 ;
V_11 -> V_47 = V_48 ;
V_11 -> V_49 = F_15 ;
if ( V_16 ) {
V_11 -> V_50 = V_16 -> V_51 ;
V_11 -> V_52 = V_16 -> V_53 ;
V_11 -> V_47 |= V_16 -> V_54 ;
V_11 -> V_55 |= V_16 -> V_56 ;
V_11 -> V_57 = V_16 -> V_57 ;
if ( V_16 -> V_19 )
V_11 -> V_19 = F_9 ;
if ( V_16 -> V_20 )
V_11 -> V_20 = F_10 ;
if ( V_16 -> V_58 > 0 && V_16 -> V_59 > 0 ) {
V_41 -> V_60 = ( void * ) V_16 -> V_58 ;
V_41 -> V_61 = ( void * ) V_16 -> V_59 ;
V_41 -> V_62 = V_16 -> V_58 ;
V_41 -> V_63 = V_16 -> V_59 ;
}
}
V_41 -> V_64 = 1 ;
V_41 -> V_65 = V_66 ;
V_11 -> V_67 = V_41 ;
V_11 -> V_50 |= V_68 ;
V_11 -> V_50 |= V_69 ;
if ( V_34 && V_34 -> V_70 ) {
const struct V_71 * V_72 = V_34 -> V_70 ;
V_11 -> V_50 |= V_72 -> V_51 ;
}
V_12 = F_26 ( & V_7 , V_2 , V_11 ) ;
if ( V_12 < 0 )
goto V_73;
V_37 = F_27 ( V_2 , V_74 ) ;
if ( V_37 >= 0 ) {
V_39 = false ;
V_12 = F_28 ( & V_2 -> V_17 , V_37 , V_75 , 0 ,
F_29 ( & V_2 -> V_17 ) , V_7 ) ;
if ( V_12 )
goto V_76;
}
V_37 = F_27 ( V_2 , V_77 ) ;
if ( V_37 >= 0 ) {
V_39 = false ;
V_12 = F_28 ( & V_2 -> V_17 , V_37 , V_78 , 0 ,
F_29 ( & V_2 -> V_17 ) , V_7 ) ;
if ( V_12 )
goto V_76;
}
V_37 = F_27 ( V_2 , V_79 ) ;
if ( V_37 >= 0 ) {
V_39 = false ;
V_12 = F_28 ( & V_2 -> V_17 , V_37 , V_80 , 0 ,
F_29 ( & V_2 -> V_17 ) , V_7 ) ;
if ( V_12 )
goto V_76;
} else if ( ! V_39 ) {
F_22 ( & V_2 -> V_17 ,
L_4 ) ;
V_12 = V_37 ;
goto V_76;
}
if ( V_39 ) {
while ( 1 ) {
V_37 = F_30 ( V_2 , V_38 ) ;
if ( V_37 < 0 )
break;
V_38 ++ ;
V_12 = F_28 ( & V_2 -> V_17 , V_37 , V_81 , 0 ,
F_29 ( & V_2 -> V_17 ) , V_7 ) ;
if ( V_12 )
goto V_76;
}
if ( ! V_38 ) {
V_12 = V_37 ;
goto V_76;
}
}
F_31 ( & V_2 -> V_17 , L_5 ,
F_32 ( V_7 -> V_5 ) , ( unsigned long )
( F_33 ( V_2 , V_82 , 0 ) -> V_83 ) ,
V_7 -> V_5 -> V_84 / 1000000 ) ;
return V_12 ;
V_76:
F_34 ( V_7 ) ;
V_73:
V_46:
if ( V_16 && V_16 -> V_85 )
V_16 -> V_85 ( V_2 ) ;
return V_12 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_15 * V_16 = V_2 -> V_17 . V_18 ;
F_34 ( V_7 ) ;
if ( V_16 && V_16 -> V_85 )
V_16 -> V_85 ( V_2 ) ;
return 0 ;
}
