static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_5 && V_5 -> V_8 )
V_5 -> V_8 ( V_2 , V_3 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_5 && V_5 -> V_9 )
return V_5 -> V_9 ( V_2 ) ;
else
return - V_10 ;
}
static int F_3 ( struct V_11 * V_12 )
{
int V_13 = 1000 ;
while ( -- V_13 && ! ( F_4 ( V_12 , V_14 ) & ( 1 << 13 ) ) )
F_5 ( 1 ) ;
if ( ! V_13 ) {
F_6 ( V_12 -> V_15 -> V_6 , L_1 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_11 * V_12 , int V_17 )
{
switch ( V_17 )
{
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return F_3 ( V_12 ) ;
}
return 0 ;
}
static void F_8 ( const struct V_1 * V_2 )
{
F_9 ( F_10 ( & V_2 -> V_6 ) , F_11 ( 100 ) ) ;
}
static int T_1 F_12 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
struct V_11 * V_12 ;
char V_30 [ 8 ] ;
int V_31 , V_32 , V_33 = 0 ;
bool V_34 = true ;
V_27 = F_13 ( sizeof( struct V_26 ) , V_35 ) ;
if ( V_27 == NULL ) {
F_14 ( & V_2 -> V_6 , L_2 ) ;
return - V_36 ;
}
V_29 = & V_27 -> V_29 ;
V_5 -> V_15 = V_29 ;
if ( V_5 -> V_37 ) {
V_32 = V_5 -> V_37 ( V_2 , & V_38 ) ;
if ( V_32 )
goto V_39;
}
snprintf ( V_30 , sizeof( V_30 ) , L_3 , V_2 -> V_40 ) ;
V_27 -> V_41 = F_15 ( & V_2 -> V_6 , V_30 ) ;
if ( F_16 ( V_27 -> V_41 ) ) {
F_14 ( & V_2 -> V_6 , L_4 , V_30 ) ;
V_32 = F_17 ( V_27 -> V_41 ) ;
goto V_42;
}
V_29 -> V_43 = F_18 ( V_27 -> V_41 ) ;
V_29 -> V_8 = F_1 ;
V_29 -> V_9 = F_2 ;
V_29 -> V_44 = V_45 ;
if ( V_5 ) {
V_29 -> V_46 = V_5 -> V_47 ;
if ( V_29 -> V_46 & V_48 )
V_29 -> V_49 = F_7 ;
V_29 -> V_50 = V_5 -> V_51 ;
V_29 -> V_44 |= V_5 -> V_52 ;
V_29 -> V_53 = V_5 -> V_53 ;
if ( V_5 -> V_54 > 0 && V_5 -> V_55 > 0 ) {
V_27 -> V_56 . V_57 = V_5 -> V_54 ;
V_27 -> V_58 . V_57 = V_5 -> V_55 ;
V_27 -> V_59 . V_60 = & V_27 -> V_56 ;
V_27 -> V_59 . V_61 = & V_27 -> V_58 ;
V_27 -> V_59 . V_62 = 1 ;
V_29 -> V_63 = & V_27 -> V_59 ;
}
}
V_29 -> V_46 |= V_64 ;
V_29 -> V_46 |= V_65 ;
V_32 = F_19 ( & V_12 , V_2 , V_29 ) ;
if ( V_32 < 0 )
goto V_66;
V_31 = F_20 ( V_2 , V_67 ) ;
if ( V_31 >= 0 ) {
V_34 = false ;
V_32 = F_21 ( V_31 , V_68 , 0 ,
F_22 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_32 )
goto V_69;
}
V_31 = F_20 ( V_2 , V_70 ) ;
if ( V_31 >= 0 ) {
V_34 = false ;
V_32 = F_21 ( V_31 , V_71 , 0 ,
F_22 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_32 )
goto V_72;
}
V_31 = F_20 ( V_2 , V_73 ) ;
if ( V_31 >= 0 ) {
V_34 = false ;
V_32 = F_21 ( V_31 , V_74 , 0 ,
F_22 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_32 )
goto V_75;
} else if ( ! V_34 ) {
F_14 ( & V_2 -> V_6 ,
L_5 ) ;
V_32 = V_31 ;
goto V_75;
}
if ( V_34 ) {
while ( 1 ) {
V_31 = F_23 ( V_2 , V_33 ) ;
if ( V_31 < 0 )
break;
V_33 ++ ;
V_32 = F_21 ( V_31 , V_76 , 0 ,
F_22 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_32 )
goto V_77;
}
if ( ! V_33 )
goto V_77;
}
F_24 ( & V_2 -> V_6 , L_6 ,
F_25 ( V_12 -> V_78 ) , ( unsigned long )
( F_26 ( V_2 , V_79 , 0 ) -> V_80 ) ,
V_29 -> V_43 / 1000000 ) ;
return V_32 ;
V_77:
while ( V_33 -- ) {
V_31 = F_23 ( V_2 , V_33 ) ;
F_27 ( V_31 , V_12 ) ;
}
V_75:
V_31 = F_20 ( V_2 , V_70 ) ;
if ( V_31 >= 0 )
F_27 ( V_31 , V_12 ) ;
V_72:
V_31 = F_20 ( V_2 , V_67 ) ;
if ( V_31 >= 0 )
F_27 ( V_31 , V_12 ) ;
V_69:
F_28 ( V_12 ) ;
V_66:
F_29 ( V_27 -> V_41 ) ;
V_42:
if ( V_5 -> V_81 )
V_5 -> V_81 ( V_2 ) ;
V_39:
F_30 ( V_27 ) ;
return V_32 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_82 * V_78 = F_32 ( V_2 ) ;
struct V_11 * V_12 = F_33 ( V_78 ) ;
struct V_26 * V_27 = F_34 ( V_12 -> V_15 , struct V_26 , V_29 ) ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
int V_33 = 0 , V_31 ;
V_5 -> V_15 = NULL ;
F_28 ( V_12 ) ;
while ( 1 ) {
V_31 = F_23 ( V_2 , V_33 ++ ) ;
if ( V_31 < 0 )
break;
F_27 ( V_31 , V_12 ) ;
}
F_29 ( V_27 -> V_41 ) ;
if ( V_5 -> V_81 )
V_5 -> V_81 ( V_2 ) ;
F_30 ( V_27 ) ;
return 0 ;
}
