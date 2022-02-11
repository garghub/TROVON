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
struct V_9 * V_10 ;
struct V_33 * V_12 ;
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
struct V_7 * V_8 ;
int V_34 , V_13 , V_35 = 0 ;
bool V_36 = true ;
V_10 = F_20 ( sizeof( struct V_9 ) , V_37 ) ;
if ( V_10 == NULL ) {
F_21 ( & V_2 -> V_6 , L_2 ) ;
return - V_38 ;
}
V_12 = & V_10 -> V_12 ;
if ( V_17 ) {
V_17 -> V_11 = V_12 ;
if ( V_17 -> V_39 ) {
V_13 = V_17 -> V_39 ( V_2 , & V_40 ) ;
if ( V_13 )
goto V_41;
}
}
V_10 -> V_14 = F_22 ( & V_2 -> V_6 , NULL ) ;
if ( F_23 ( V_10 -> V_14 ) ) {
V_13 = F_24 ( V_10 -> V_14 ) ;
F_21 ( & V_2 -> V_6 , L_3 , V_13 ) ;
goto V_42;
}
V_12 -> F_5 = F_1 ;
V_12 -> F_8 = F_7 ;
V_12 -> V_43 = V_44 ;
if ( V_17 ) {
V_12 -> V_45 = V_17 -> V_46 ;
if ( V_12 -> V_45 & V_47 )
V_12 -> V_48 = F_15 ;
V_12 -> V_49 = V_17 -> V_50 ;
V_12 -> V_43 |= V_17 -> V_51 ;
V_12 -> V_52 |= V_17 -> V_53 ;
V_12 -> V_54 = V_17 -> V_54 ;
if ( V_17 -> V_19 )
V_12 -> V_19 = F_9 ;
if ( V_17 -> V_20 )
V_12 -> V_20 = F_10 ;
if ( V_17 -> V_55 > 0 && V_17 -> V_56 > 0 ) {
V_10 -> V_57 . V_58 . V_59 = V_17 -> V_55 ;
V_10 -> V_60 . V_58 . V_59 = V_17 -> V_56 ;
V_10 -> V_61 . V_62 = & V_10 -> V_57 . V_58 ;
V_10 -> V_61 . V_63 = & V_10 -> V_60 . V_58 ;
V_10 -> V_61 . V_64 = 1 ;
V_12 -> V_65 = & V_10 -> V_61 ;
}
}
V_12 -> V_45 |= V_66 ;
V_12 -> V_45 |= V_67 ;
V_13 = F_25 ( & V_8 , V_2 , V_12 ) ;
if ( V_13 < 0 )
goto V_68;
V_34 = F_26 ( V_2 , V_69 ) ;
if ( V_34 >= 0 ) {
V_36 = false ;
V_13 = F_27 ( V_34 , V_70 , 0 ,
F_28 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_71;
}
V_34 = F_26 ( V_2 , V_72 ) ;
if ( V_34 >= 0 ) {
V_36 = false ;
V_13 = F_27 ( V_34 , V_73 , 0 ,
F_28 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_74;
}
V_34 = F_26 ( V_2 , V_75 ) ;
if ( V_34 >= 0 ) {
V_36 = false ;
V_13 = F_27 ( V_34 , V_76 , 0 ,
F_28 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_77;
} else if ( ! V_36 ) {
F_21 ( & V_2 -> V_6 ,
L_4 ) ;
V_13 = V_34 ;
goto V_77;
}
if ( V_36 ) {
while ( 1 ) {
V_34 = F_29 ( V_2 , V_35 ) ;
if ( V_34 < 0 )
break;
V_35 ++ ;
V_13 = F_27 ( V_34 , V_78 , 0 ,
F_28 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_79;
}
if ( ! V_35 )
goto V_79;
}
F_30 ( & V_2 -> V_6 , L_5 ,
F_31 ( V_8 -> V_5 ) , ( unsigned long )
( F_32 ( V_2 , V_80 , 0 ) -> V_81 ) ,
V_8 -> V_5 -> V_82 / 1000000 ) ;
return V_13 ;
V_79:
while ( V_35 -- ) {
V_34 = F_29 ( V_2 , V_35 ) ;
F_33 ( V_34 , V_8 ) ;
}
V_77:
V_34 = F_26 ( V_2 , V_72 ) ;
if ( V_34 >= 0 )
F_33 ( V_34 , V_8 ) ;
V_74:
V_34 = F_26 ( V_2 , V_69 ) ;
if ( V_34 >= 0 )
F_33 ( V_34 , V_8 ) ;
V_71:
F_34 ( V_8 ) ;
V_68:
F_35 ( V_10 -> V_14 ) ;
V_42:
if ( V_17 && V_17 -> V_83 )
V_17 -> V_83 ( V_2 ) ;
V_41:
F_36 ( V_10 ) ;
return V_13 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_38 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_9 * V_10 = F_4 ( V_8 -> V_11 , struct V_9 , V_12 ) ;
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
int V_35 = 0 , V_34 ;
if ( V_17 )
V_17 -> V_11 = NULL ;
F_34 ( V_8 ) ;
while ( 1 ) {
V_34 = F_29 ( V_2 , V_35 ++ ) ;
if ( V_34 < 0 )
break;
F_33 ( V_34 , V_8 ) ;
}
F_35 ( V_10 -> V_14 ) ;
if ( V_17 && V_17 -> V_83 )
V_17 -> V_83 ( V_2 ) ;
F_36 ( V_10 ) ;
return 0 ;
}
