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
static int T_1 F_19 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_33 * V_12 ;
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
struct V_7 * V_8 ;
char V_34 [ 8 ] ;
int V_35 , V_13 , V_36 = 0 ;
bool V_37 = true ;
V_10 = F_20 ( sizeof( struct V_9 ) , V_38 ) ;
if ( V_10 == NULL ) {
F_21 ( & V_2 -> V_6 , L_2 ) ;
return - V_39 ;
}
V_12 = & V_10 -> V_12 ;
if ( V_17 ) {
V_17 -> V_11 = V_12 ;
if ( V_17 -> V_40 ) {
V_13 = V_17 -> V_40 ( V_2 , & V_41 ) ;
if ( V_13 )
goto V_42;
}
}
snprintf ( V_34 , sizeof( V_34 ) , L_3 , V_2 -> V_43 ) ;
V_10 -> V_14 = F_22 ( & V_2 -> V_6 , V_34 ) ;
if ( F_23 ( V_10 -> V_14 ) ) {
F_21 ( & V_2 -> V_6 , L_4 , V_34 ) ;
V_13 = F_24 ( V_10 -> V_14 ) ;
goto V_44;
}
V_12 -> F_5 = F_1 ;
V_12 -> F_8 = F_7 ;
V_12 -> V_45 = V_46 ;
if ( V_17 ) {
V_12 -> V_47 = V_17 -> V_48 ;
if ( V_12 -> V_47 & V_49 )
V_12 -> V_50 = F_15 ;
V_12 -> V_51 = V_17 -> V_52 ;
V_12 -> V_45 |= V_17 -> V_53 ;
V_12 -> V_54 |= V_17 -> V_55 ;
V_12 -> V_56 = V_17 -> V_56 ;
if ( V_17 -> V_19 )
V_12 -> V_19 = F_9 ;
if ( V_17 -> V_20 )
V_12 -> V_20 = F_10 ;
if ( V_17 -> V_57 > 0 && V_17 -> V_58 > 0 ) {
V_10 -> V_59 . V_60 . V_61 = V_17 -> V_57 ;
V_10 -> V_62 . V_60 . V_61 = V_17 -> V_58 ;
V_10 -> V_63 . V_64 = & V_10 -> V_59 . V_60 ;
V_10 -> V_63 . V_65 = & V_10 -> V_62 . V_60 ;
V_10 -> V_63 . V_66 = 1 ;
V_12 -> V_67 = & V_10 -> V_63 ;
}
}
V_12 -> V_47 |= V_68 ;
V_12 -> V_47 |= V_69 ;
V_13 = F_25 ( & V_8 , V_2 , V_12 ) ;
if ( V_13 < 0 )
goto V_70;
V_35 = F_26 ( V_2 , V_71 ) ;
if ( V_35 >= 0 ) {
V_37 = false ;
V_13 = F_27 ( V_35 , V_72 , 0 ,
F_28 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_73;
}
V_35 = F_26 ( V_2 , V_74 ) ;
if ( V_35 >= 0 ) {
V_37 = false ;
V_13 = F_27 ( V_35 , V_75 , 0 ,
F_28 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_76;
}
V_35 = F_26 ( V_2 , V_77 ) ;
if ( V_35 >= 0 ) {
V_37 = false ;
V_13 = F_27 ( V_35 , V_78 , 0 ,
F_28 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_79;
} else if ( ! V_37 ) {
F_21 ( & V_2 -> V_6 ,
L_5 ) ;
V_13 = V_35 ;
goto V_79;
}
if ( V_37 ) {
while ( 1 ) {
V_35 = F_29 ( V_2 , V_36 ) ;
if ( V_35 < 0 )
break;
V_36 ++ ;
V_13 = F_27 ( V_35 , V_80 , 0 ,
F_28 ( & V_2 -> V_6 ) , V_8 ) ;
if ( V_13 )
goto V_81;
}
if ( ! V_36 )
goto V_81;
}
F_30 ( & V_2 -> V_6 , L_6 ,
F_31 ( V_8 -> V_5 ) , ( unsigned long )
( F_32 ( V_2 , V_82 , 0 ) -> V_83 ) ,
V_12 -> V_84 / 1000000 ) ;
return V_13 ;
V_81:
while ( V_36 -- ) {
V_35 = F_29 ( V_2 , V_36 ) ;
F_33 ( V_35 , V_8 ) ;
}
V_79:
V_35 = F_26 ( V_2 , V_74 ) ;
if ( V_35 >= 0 )
F_33 ( V_35 , V_8 ) ;
V_76:
V_35 = F_26 ( V_2 , V_71 ) ;
if ( V_35 >= 0 )
F_33 ( V_35 , V_8 ) ;
V_73:
F_34 ( V_8 ) ;
V_70:
F_35 ( V_10 -> V_14 ) ;
V_44:
if ( V_17 && V_17 -> V_85 )
V_17 -> V_85 ( V_2 ) ;
V_42:
F_36 ( V_10 ) ;
return V_13 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_38 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_9 * V_10 = F_4 ( V_8 -> V_11 , struct V_9 , V_12 ) ;
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
int V_36 = 0 , V_35 ;
if ( V_17 )
V_17 -> V_11 = NULL ;
F_34 ( V_8 ) ;
while ( 1 ) {
V_35 = F_29 ( V_2 , V_36 ++ ) ;
if ( V_35 < 0 )
break;
F_33 ( V_35 , V_8 ) ;
}
F_35 ( V_10 -> V_14 ) ;
if ( V_17 && V_17 -> V_85 )
V_17 -> V_85 ( V_2 ) ;
F_36 ( V_10 ) ;
return 0 ;
}
