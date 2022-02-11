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
static int T_1 F_8 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
struct V_11 * V_12 ;
char V_30 [ 8 ] ;
int V_31 , V_32 , V_33 = 0 ;
bool V_34 = true ;
V_27 = F_9 ( sizeof( struct V_26 ) , V_35 ) ;
if ( V_27 == NULL ) {
F_10 ( & V_2 -> V_6 , L_2 ) ;
return - V_36 ;
}
V_29 = & V_27 -> V_29 ;
V_5 -> V_15 = V_29 ;
snprintf ( V_30 , sizeof( V_30 ) , L_3 , V_2 -> V_37 ) ;
V_27 -> V_38 = F_11 ( & V_2 -> V_6 , V_30 ) ;
if ( F_12 ( V_27 -> V_38 ) ) {
F_10 ( & V_2 -> V_6 , L_4 , V_30 ) ;
V_32 = F_13 ( V_27 -> V_38 ) ;
goto V_39;
}
F_14 ( V_27 -> V_38 ) ;
V_29 -> V_40 = F_15 ( V_27 -> V_38 ) ;
V_29 -> V_8 = F_1 ;
V_29 -> V_9 = F_2 ;
V_29 -> V_41 = V_42 ;
if ( V_5 ) {
V_29 -> V_43 = V_5 -> V_44 ;
if ( V_29 -> V_43 & V_45 )
V_29 -> V_46 = F_7 ;
V_29 -> V_47 = V_5 -> V_48 ;
V_29 -> V_41 |= V_5 -> V_49 ;
if ( V_5 -> V_50 > 0 && V_5 -> V_51 > 0 ) {
V_27 -> V_52 . V_53 = V_5 -> V_50 ;
V_27 -> V_54 . V_53 = V_5 -> V_51 ;
V_27 -> V_55 . V_56 = & V_27 -> V_52 ;
V_27 -> V_55 . V_57 = & V_27 -> V_54 ;
V_27 -> V_55 . V_58 = 1 ;
V_29 -> V_59 = & V_27 -> V_55 ;
}
}
V_29 -> V_43 |= V_60 ;
V_29 -> V_43 |= V_61 ;
V_32 = F_16 ( & V_12 , V_2 , V_29 ) ;
if ( V_32 < 0 )
goto V_62;
V_31 = F_17 ( V_2 , V_63 ) ;
if ( V_31 >= 0 ) {
V_34 = false ;
V_32 = F_18 ( V_31 , V_64 , 0 ,
F_19 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_32 )
goto V_65;
}
V_31 = F_17 ( V_2 , V_66 ) ;
if ( V_31 >= 0 ) {
V_34 = false ;
V_32 = F_18 ( V_31 , V_67 , 0 ,
F_19 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_32 )
goto V_68;
}
V_31 = F_17 ( V_2 , V_69 ) ;
if ( V_31 >= 0 ) {
V_34 = false ;
V_32 = F_18 ( V_31 , V_70 , 0 ,
F_19 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_32 )
goto V_71;
} else if ( ! V_34 ) {
F_10 ( & V_2 -> V_6 ,
L_5 ) ;
V_32 = V_31 ;
goto V_71;
}
if ( V_34 ) {
while ( 1 ) {
V_31 = F_20 ( V_2 , V_33 ) ;
if ( V_31 < 0 )
break;
V_33 ++ ;
V_32 = F_18 ( V_31 , V_72 , 0 ,
F_19 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_32 )
goto V_73;
}
if ( ! V_33 )
goto V_73;
}
F_21 ( & V_2 -> V_6 , L_6 ,
F_22 ( V_12 -> V_74 ) , ( unsigned long )
( F_23 ( V_2 , V_75 , 0 ) -> V_76 ) ,
V_29 -> V_40 / 1000000 ) ;
return V_32 ;
V_73:
while ( V_33 -- ) {
V_31 = F_20 ( V_2 , V_33 ) ;
F_24 ( V_31 , V_12 ) ;
}
V_71:
V_31 = F_17 ( V_2 , V_66 ) ;
if ( V_31 >= 0 )
F_24 ( V_31 , V_12 ) ;
V_68:
V_31 = F_17 ( V_2 , V_63 ) ;
if ( V_31 >= 0 )
F_24 ( V_31 , V_12 ) ;
V_65:
F_25 ( V_12 ) ;
V_62:
F_26 ( V_27 -> V_38 ) ;
F_27 ( V_27 -> V_38 ) ;
V_39:
F_28 ( V_27 ) ;
return V_32 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_77 * V_74 = F_30 ( V_2 ) ;
struct V_11 * V_12 = F_31 ( V_74 ) ;
struct V_26 * V_27 = F_32 ( V_12 -> V_15 , struct V_26 , V_29 ) ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
int V_33 = 0 , V_31 ;
V_5 -> V_15 = NULL ;
F_25 ( V_12 ) ;
while ( 1 ) {
V_31 = F_20 ( V_2 , V_33 ++ ) ;
if ( V_31 < 0 )
break;
F_24 ( V_31 , V_12 ) ;
}
F_26 ( V_27 -> V_38 ) ;
F_27 ( V_27 -> V_38 ) ;
F_28 ( V_27 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_78 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_78 ) ;
}
