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
struct V_34 * V_35 ;
int V_36 , V_12 , V_37 = 0 ;
bool V_38 = true ;
struct V_39 * V_40 ;
T_1 V_41 ;
V_35 = F_19 ( V_2 , V_42 , 0 ) ;
if ( ! V_35 )
return - V_43 ;
V_9 = F_20 ( & V_2 -> V_16 , sizeof( struct V_8 ) , V_44 ) ;
if ( V_9 == NULL ) {
F_21 ( & V_2 -> V_16 , L_2 ) ;
return - V_45 ;
}
V_11 = & V_9 -> V_11 ;
V_40 = & V_9 -> V_40 ;
if ( V_32 ) {
if ( V_32 -> V_46 ) {
V_12 = V_32 -> V_46 ( V_2 , & V_47 ) ;
if ( V_12 )
return V_12 ;
}
}
V_9 -> V_13 = F_22 ( & V_2 -> V_16 , NULL ) ;
if ( F_23 ( V_9 -> V_13 ) ) {
V_12 = F_24 ( V_9 -> V_13 ) ;
F_21 ( & V_2 -> V_16 , L_3 , V_12 ) ;
goto V_48;
}
V_11 -> V_49 = F_1 ;
V_11 -> V_50 = F_7 ;
V_11 -> V_51 = V_52 ;
V_11 -> V_53 = F_13 ;
if ( V_32 ) {
V_11 -> V_54 = V_32 -> V_55 ;
V_11 -> V_56 = V_32 -> V_57 ;
V_11 -> V_51 |= V_32 -> V_58 ;
V_11 -> V_59 |= V_32 -> V_60 ;
V_11 -> V_61 = V_32 -> V_61 ;
if ( V_32 -> V_62 > 0 && V_32 -> V_63 > 0 ) {
V_40 -> V_64 = ( void * ) V_32 -> V_62 ;
V_40 -> V_65 = ( void * ) V_32 -> V_63 ;
V_40 -> V_66 = V_32 -> V_62 ;
V_40 -> V_67 = V_32 -> V_63 ;
}
}
V_40 -> V_68 = 1 ;
V_40 -> V_69 = V_70 ;
V_11 -> V_71 = V_40 ;
V_11 -> V_54 |= V_72 ;
V_11 -> V_54 |= V_73 ;
if ( V_28 && V_28 -> V_74 ) {
const struct V_75 * V_76 = V_28 -> V_74 ;
V_11 -> V_54 |= V_76 -> V_55 ;
V_11 -> V_51 |= V_76 -> V_51 ;
V_11 -> V_59 |= V_76 -> V_59 ;
}
V_11 -> V_77 = F_25 ( V_35 ) >> 9 ;
V_12 = F_26 ( & V_7 , V_2 , V_11 ) ;
if ( V_12 < 0 )
goto V_78;
V_41 = F_10 ( V_7 , V_79 ) ;
if ( V_41 == 0xCB0D )
F_27 ( V_7 , V_80 , 1 ) ;
V_36 = F_28 ( V_2 , V_81 ) ;
if ( V_36 >= 0 ) {
V_38 = false ;
V_12 = F_29 ( & V_2 -> V_16 , V_36 , V_82 , 0 ,
F_30 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_83;
}
V_36 = F_28 ( V_2 , V_84 ) ;
if ( V_36 >= 0 ) {
V_38 = false ;
V_12 = F_29 ( & V_2 -> V_16 , V_36 , V_85 , 0 ,
F_30 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_83;
}
V_36 = F_28 ( V_2 , V_86 ) ;
if ( V_36 >= 0 ) {
V_38 = false ;
V_12 = F_29 ( & V_2 -> V_16 , V_36 , V_87 , 0 ,
F_30 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_83;
} else if ( ! V_38 ) {
F_21 ( & V_2 -> V_16 ,
L_4 ) ;
V_12 = V_36 ;
goto V_83;
}
if ( V_38 ) {
while ( 1 ) {
V_36 = F_31 ( V_2 , V_37 ) ;
if ( V_36 < 0 )
break;
V_37 ++ ;
V_12 = F_29 ( & V_2 -> V_16 , V_36 , V_88 , 0 ,
F_30 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_83;
}
if ( ! V_37 ) {
V_12 = V_36 ;
goto V_83;
}
}
F_32 ( & V_2 -> V_16 , L_5 ,
F_33 ( V_7 -> V_5 ) , ( unsigned long )
( F_19 ( V_2 , V_42 , 0 ) -> V_89 ) ,
V_7 -> V_5 -> V_90 / 1000000 ) ;
return V_12 ;
V_83:
F_34 ( V_7 ) ;
V_78:
V_48:
if ( V_32 && V_32 -> V_91 )
V_32 -> V_91 ( V_2 ) ;
return V_12 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_31 * V_32 = V_2 -> V_16 . V_33 ;
F_34 ( V_7 ) ;
if ( V_32 && V_32 -> V_91 )
V_32 -> V_91 ( V_2 ) ;
return 0 ;
}
