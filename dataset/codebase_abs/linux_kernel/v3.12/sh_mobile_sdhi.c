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
static int F_9 ( struct V_6 * V_7 )
{
int V_14 = 1000 ;
while ( -- V_14 && ! ( F_10 ( V_7 , V_15 ) & ( 1 << 13 ) ) )
F_11 ( 1 ) ;
if ( ! V_14 ) {
F_12 ( V_7 -> V_10 -> V_16 , L_1 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , int V_18 )
{
switch ( V_18 )
{
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
return F_9 ( V_7 ) ;
}
return 0 ;
}
static void F_14 ( const struct V_1 * V_2 )
{
F_15 ( F_2 ( V_2 ) , F_16 ( 100 ) ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
const struct V_27 * V_28 =
F_18 ( V_29 , & V_2 -> V_16 ) ;
struct V_8 * V_9 ;
struct V_30 * V_11 ;
struct V_31 * V_32 = V_2 -> V_16 . V_33 ;
struct V_6 * V_7 ;
int V_34 , V_12 , V_35 = 0 ;
bool V_36 = true ;
struct V_37 * V_38 ;
V_9 = F_19 ( & V_2 -> V_16 , sizeof( struct V_8 ) , V_39 ) ;
if ( V_9 == NULL ) {
F_20 ( & V_2 -> V_16 , L_2 ) ;
return - V_40 ;
}
V_11 = & V_9 -> V_11 ;
V_38 = & V_9 -> V_38 ;
if ( V_32 ) {
if ( V_32 -> V_41 ) {
V_12 = V_32 -> V_41 ( V_2 , & V_42 ) ;
if ( V_12 )
return V_12 ;
}
}
V_9 -> V_13 = F_21 ( & V_2 -> V_16 , NULL ) ;
if ( F_22 ( V_9 -> V_13 ) ) {
V_12 = F_23 ( V_9 -> V_13 ) ;
F_20 ( & V_2 -> V_16 , L_3 , V_12 ) ;
goto V_43;
}
V_11 -> F_5 = F_1 ;
V_11 -> F_8 = F_7 ;
V_11 -> V_44 = V_45 ;
V_11 -> V_46 = F_13 ;
if ( V_32 ) {
V_11 -> V_47 = V_32 -> V_48 ;
V_11 -> V_49 = V_32 -> V_50 ;
V_11 -> V_44 |= V_32 -> V_51 ;
V_11 -> V_52 |= V_32 -> V_53 ;
V_11 -> V_54 = V_32 -> V_54 ;
if ( V_32 -> V_55 > 0 && V_32 -> V_56 > 0 ) {
V_38 -> V_57 = ( void * ) V_32 -> V_55 ;
V_38 -> V_58 = ( void * ) V_32 -> V_56 ;
V_38 -> V_59 = V_32 -> V_55 ;
V_38 -> V_60 = V_32 -> V_56 ;
}
}
V_38 -> V_61 = 1 ;
V_38 -> V_62 = V_63 ;
V_11 -> V_64 = V_38 ;
V_11 -> V_47 |= V_65 ;
V_11 -> V_47 |= V_66 ;
if ( V_28 && V_28 -> V_67 ) {
const struct V_68 * V_69 = V_28 -> V_67 ;
V_11 -> V_47 |= V_69 -> V_48 ;
}
V_12 = F_24 ( & V_7 , V_2 , V_11 ) ;
if ( V_12 < 0 )
goto V_70;
V_34 = F_25 ( V_2 , V_71 ) ;
if ( V_34 >= 0 ) {
V_36 = false ;
V_12 = F_26 ( & V_2 -> V_16 , V_34 , V_72 , 0 ,
F_27 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_73;
}
V_34 = F_25 ( V_2 , V_74 ) ;
if ( V_34 >= 0 ) {
V_36 = false ;
V_12 = F_26 ( & V_2 -> V_16 , V_34 , V_75 , 0 ,
F_27 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_73;
}
V_34 = F_25 ( V_2 , V_76 ) ;
if ( V_34 >= 0 ) {
V_36 = false ;
V_12 = F_26 ( & V_2 -> V_16 , V_34 , V_77 , 0 ,
F_27 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_73;
} else if ( ! V_36 ) {
F_20 ( & V_2 -> V_16 ,
L_4 ) ;
V_12 = V_34 ;
goto V_73;
}
if ( V_36 ) {
while ( 1 ) {
V_34 = F_28 ( V_2 , V_35 ) ;
if ( V_34 < 0 )
break;
V_35 ++ ;
V_12 = F_26 ( & V_2 -> V_16 , V_34 , V_78 , 0 ,
F_27 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_73;
}
if ( ! V_35 ) {
V_12 = V_34 ;
goto V_73;
}
}
F_29 ( & V_2 -> V_16 , L_5 ,
F_30 ( V_7 -> V_5 ) , ( unsigned long )
( F_31 ( V_2 , V_79 , 0 ) -> V_80 ) ,
V_7 -> V_5 -> V_81 / 1000000 ) ;
return V_12 ;
V_73:
F_32 ( V_7 ) ;
V_70:
V_43:
if ( V_32 && V_32 -> V_82 )
V_32 -> V_82 ( V_2 ) ;
return V_12 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_31 * V_32 = V_2 -> V_16 . V_33 ;
F_32 ( V_7 ) ;
if ( V_32 && V_32 -> V_82 )
V_32 -> V_82 ( V_2 ) ;
return 0 ;
}
