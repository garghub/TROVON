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
static int F_14 ( struct V_27 * V_28 ,
unsigned int V_29 , int V_30 )
{
if ( ( V_29 == V_31 ) &&
V_30 == 2 )
return 1 ;
return V_30 ;
}
static void F_15 ( const struct V_1 * V_2 )
{
F_16 ( F_2 ( V_2 ) , F_17 ( 100 ) ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 =
F_19 ( V_34 , & V_2 -> V_16 ) ;
struct V_8 * V_9 ;
struct V_35 * V_11 ;
struct V_36 * V_37 = V_2 -> V_16 . V_38 ;
struct V_6 * V_7 ;
struct V_39 * V_40 ;
int V_41 , V_12 , V_42 = 0 ;
bool V_43 = true ;
struct V_44 * V_45 ;
T_1 V_46 ;
V_40 = F_20 ( V_2 , V_47 , 0 ) ;
if ( ! V_40 )
return - V_48 ;
V_9 = F_21 ( & V_2 -> V_16 , sizeof( struct V_8 ) , V_49 ) ;
if ( V_9 == NULL ) {
F_22 ( & V_2 -> V_16 , L_2 ) ;
return - V_50 ;
}
V_11 = & V_9 -> V_11 ;
V_45 = & V_9 -> V_45 ;
if ( V_37 ) {
if ( V_37 -> V_51 ) {
V_12 = V_37 -> V_51 ( V_2 , & V_52 ) ;
if ( V_12 )
return V_12 ;
}
}
V_9 -> V_13 = F_23 ( & V_2 -> V_16 , NULL ) ;
if ( F_24 ( V_9 -> V_13 ) ) {
V_12 = F_25 ( V_9 -> V_13 ) ;
F_22 ( & V_2 -> V_16 , L_3 , V_12 ) ;
goto V_53;
}
V_11 -> V_54 = F_1 ;
V_11 -> V_55 = F_7 ;
V_11 -> V_56 = V_57 ;
V_11 -> V_58 = F_13 ;
V_11 -> V_59 = F_14 ;
if ( V_37 ) {
V_11 -> V_60 = V_37 -> V_61 ;
V_11 -> V_62 = V_37 -> V_63 ;
V_11 -> V_56 |= V_37 -> V_64 ;
V_11 -> V_65 |= V_37 -> V_66 ;
V_11 -> V_67 = V_37 -> V_67 ;
if ( V_37 -> V_68 > 0 && V_37 -> V_69 > 0 ) {
V_45 -> V_70 = ( void * ) V_37 -> V_68 ;
V_45 -> V_71 = ( void * ) V_37 -> V_69 ;
V_45 -> V_72 = V_37 -> V_68 ;
V_45 -> V_73 = V_37 -> V_69 ;
}
}
V_45 -> V_74 = 1 ;
V_45 -> V_75 = V_76 ;
V_11 -> V_77 = V_45 ;
V_11 -> V_60 |= V_78 ;
V_11 -> V_60 |= V_79 ;
V_11 -> V_60 |= V_80 ;
V_11 -> V_60 |= V_81 ;
V_11 -> V_60 |= V_82 ;
if ( V_33 && V_33 -> V_83 ) {
const struct V_84 * V_85 = V_33 -> V_83 ;
V_11 -> V_60 |= V_85 -> V_61 ;
V_11 -> V_56 |= V_85 -> V_56 ;
V_11 -> V_65 |= V_85 -> V_65 ;
V_45 -> V_86 = V_85 -> V_86 ;
}
V_11 -> V_87 = F_26 ( V_40 ) >> 9 ;
V_12 = F_27 ( & V_7 , V_2 , V_11 ) ;
if ( V_12 < 0 )
goto V_88;
V_46 = F_10 ( V_7 , V_89 ) ;
if ( V_46 == 0xCB0D )
F_28 ( V_7 , V_90 , 1 ) ;
V_41 = F_29 ( V_2 , V_91 ) ;
if ( V_41 >= 0 ) {
V_43 = false ;
V_12 = F_30 ( & V_2 -> V_16 , V_41 , V_92 , 0 ,
F_31 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_93;
}
V_41 = F_29 ( V_2 , V_94 ) ;
if ( V_41 >= 0 ) {
V_43 = false ;
V_12 = F_30 ( & V_2 -> V_16 , V_41 , V_95 , 0 ,
F_31 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_93;
}
V_41 = F_29 ( V_2 , V_96 ) ;
if ( V_41 >= 0 ) {
V_43 = false ;
V_12 = F_30 ( & V_2 -> V_16 , V_41 , V_97 , 0 ,
F_31 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_93;
} else if ( ! V_43 ) {
F_22 ( & V_2 -> V_16 ,
L_4 ) ;
V_12 = V_41 ;
goto V_93;
}
if ( V_43 ) {
while ( 1 ) {
V_41 = F_32 ( V_2 , V_42 ) ;
if ( V_41 < 0 )
break;
V_42 ++ ;
V_12 = F_30 ( & V_2 -> V_16 , V_41 , V_98 , 0 ,
F_31 ( & V_2 -> V_16 ) , V_7 ) ;
if ( V_12 )
goto V_93;
}
if ( ! V_42 ) {
V_12 = V_41 ;
goto V_93;
}
}
F_33 ( & V_2 -> V_16 , L_5 ,
F_34 ( V_7 -> V_5 ) , ( unsigned long )
( F_20 ( V_2 , V_47 , 0 ) -> V_99 ) ,
V_7 -> V_5 -> V_100 / 1000000 ) ;
return V_12 ;
V_93:
F_35 ( V_7 ) ;
V_88:
V_53:
if ( V_37 && V_37 -> V_101 )
V_37 -> V_101 ( V_2 ) ;
return V_12 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_36 * V_37 = V_2 -> V_16 . V_38 ;
F_35 ( V_7 ) ;
if ( V_37 && V_37 -> V_101 )
V_37 -> V_101 ( V_2 ) ;
return 0 ;
}
