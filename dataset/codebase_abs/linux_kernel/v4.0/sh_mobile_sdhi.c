static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
switch ( F_2 ( V_2 , V_5 ) ) {
case 0x490C :
V_4 = ( V_3 == 32 ) ? 0x0001 : 0x0000 ;
break;
case 0xCB0D :
V_4 = ( V_3 == 32 ) ? 0x0000 : 0x0001 ;
break;
default:
return;
}
F_3 ( V_2 , V_6 , V_4 ) ;
}
static int F_4 ( struct V_7 * V_8 , unsigned int * V_9 )
{
struct V_10 * V_11 = F_5 ( V_8 ) ;
struct V_1 * V_2 = F_6 ( V_11 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_14 = F_8 ( V_13 -> V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_9 = F_9 ( V_13 -> V_15 ) ;
F_1 ( V_2 , 16 ) ;
return 0 ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_8 ) ;
struct V_1 * V_2 = F_6 ( V_11 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
F_11 ( V_13 -> V_15 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_16 = 1000 ;
while ( -- V_16 && ! ( F_2 ( V_2 , V_17 ) & ( 1 << 13 ) ) )
F_13 ( 1 ) ;
if ( ! V_16 ) {
F_14 ( & V_2 -> V_8 -> V_18 , L_1 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_20 )
{
switch ( V_20 )
{
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
return F_12 ( V_2 ) ;
}
return 0 ;
}
static int F_16 ( struct V_29 * V_30 ,
unsigned int V_31 , int V_32 )
{
if ( ( V_31 == V_33 ) &&
V_32 == 2 )
return 1 ;
return V_32 ;
}
static void F_17 ( struct V_1 * V_2 , bool V_34 )
{
F_3 ( V_2 , V_28 , V_34 ? 2 : 0 ) ;
F_1 ( V_2 , V_34 ? 32 : 16 ) ;
}
static int F_18 ( struct V_7 * V_8 )
{
const struct V_35 * V_36 =
F_19 ( V_37 , & V_8 -> V_18 ) ;
struct V_12 * V_13 ;
struct V_38 * V_39 ;
struct V_40 * V_41 = V_8 -> V_18 . V_42 ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_45 , V_14 , V_46 = 0 ;
bool V_47 = true ;
struct V_48 * V_49 ;
V_44 = F_20 ( V_8 , V_50 , 0 ) ;
if ( ! V_44 )
return - V_51 ;
V_13 = F_21 ( & V_8 -> V_18 , sizeof( struct V_12 ) , V_52 ) ;
if ( V_13 == NULL ) {
F_22 ( & V_8 -> V_18 , L_2 ) ;
return - V_53 ;
}
V_39 = & V_13 -> V_39 ;
V_49 = & V_13 -> V_49 ;
V_13 -> V_15 = F_23 ( & V_8 -> V_18 , NULL ) ;
if ( F_24 ( V_13 -> V_15 ) ) {
V_14 = F_25 ( V_13 -> V_15 ) ;
F_22 ( & V_8 -> V_18 , L_3 , V_14 ) ;
goto V_54;
}
V_2 = F_26 ( V_8 ) ;
if ( ! V_2 ) {
V_14 = - V_53 ;
goto V_54;
}
V_2 -> V_55 = V_49 ;
V_2 -> V_56 = F_15 ;
V_2 -> V_57 = F_4 ;
V_2 -> V_58 = F_10 ;
V_2 -> V_59 = F_16 ;
if ( F_27 ( V_44 ) > 0x100 )
V_2 -> V_60 = 1 ;
else
V_2 -> V_60 = 0 ;
V_39 -> V_61 = V_62 ;
if ( V_41 ) {
V_39 -> V_63 = V_41 -> V_64 ;
V_39 -> V_65 = V_41 -> V_66 ;
V_39 -> V_61 |= V_41 -> V_67 ;
V_39 -> V_68 |= V_41 -> V_69 ;
V_39 -> V_70 = V_41 -> V_70 ;
if ( V_41 -> V_71 > 0 && V_41 -> V_72 > 0 ) {
V_49 -> V_73 = ( void * ) V_41 -> V_71 ;
V_49 -> V_74 = ( void * ) V_41 -> V_72 ;
V_49 -> V_75 = V_41 -> V_71 ;
V_49 -> V_76 = V_41 -> V_72 ;
}
}
V_49 -> V_77 = V_78 ;
V_49 -> V_34 = F_17 ;
V_39 -> V_79 = 1 ;
V_39 -> V_63 |= V_80 ;
V_39 -> V_63 |= V_81 ;
V_39 -> V_63 |= V_82 ;
V_39 -> V_63 |= V_83 ;
if ( V_36 && V_36 -> V_84 ) {
const struct V_85 * V_86 = V_36 -> V_84 ;
V_39 -> V_63 |= V_86 -> V_64 ;
V_39 -> V_61 |= V_86 -> V_61 ;
V_39 -> V_68 |= V_86 -> V_68 ;
V_39 -> V_87 = V_86 -> V_87 ;
V_49 -> V_88 = V_86 -> V_88 ;
}
V_14 = F_28 ( V_2 , V_39 ) ;
if ( V_14 < 0 )
goto V_89;
V_45 = F_29 ( V_8 , V_90 ) ;
if ( V_45 >= 0 ) {
V_47 = false ;
V_14 = F_30 ( & V_8 -> V_18 , V_45 , V_91 , 0 ,
F_31 ( & V_8 -> V_18 ) , V_2 ) ;
if ( V_14 )
goto V_92;
}
V_45 = F_29 ( V_8 , V_93 ) ;
if ( V_45 >= 0 ) {
V_47 = false ;
V_14 = F_30 ( & V_8 -> V_18 , V_45 , V_94 , 0 ,
F_31 ( & V_8 -> V_18 ) , V_2 ) ;
if ( V_14 )
goto V_92;
}
V_45 = F_29 ( V_8 , V_95 ) ;
if ( V_45 >= 0 ) {
V_47 = false ;
V_14 = F_30 ( & V_8 -> V_18 , V_45 , V_96 , 0 ,
F_31 ( & V_8 -> V_18 ) , V_2 ) ;
if ( V_14 )
goto V_92;
} else if ( ! V_47 ) {
F_22 ( & V_8 -> V_18 ,
L_4 ) ;
V_14 = V_45 ;
goto V_92;
}
if ( V_47 ) {
while ( 1 ) {
V_45 = F_32 ( V_8 , V_46 ) ;
if ( V_45 < 0 )
break;
V_46 ++ ;
V_14 = F_30 ( & V_8 -> V_18 , V_45 , V_97 , 0 ,
F_31 ( & V_8 -> V_18 ) , V_2 ) ;
if ( V_14 )
goto V_92;
}
if ( ! V_46 ) {
V_14 = V_45 ;
goto V_92;
}
}
F_33 ( & V_8 -> V_18 , L_5 ,
F_34 ( V_2 -> V_11 ) , ( unsigned long )
( F_20 ( V_8 , V_50 , 0 ) -> V_98 ) ,
V_2 -> V_11 -> V_99 / 1000000 ) ;
return V_14 ;
V_92:
F_35 ( V_2 ) ;
V_89:
F_36 ( V_2 ) ;
V_54:
return V_14 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_8 ) ;
struct V_1 * V_2 = F_6 ( V_11 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
