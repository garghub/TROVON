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
case 0xCC10 :
case 0xCD10 :
if ( V_3 == 64 )
V_4 = 0x0000 ;
else if ( V_3 == 32 )
V_4 = 0x0101 ;
else
V_4 = 0x0001 ;
break;
default:
return;
}
F_3 ( V_2 , V_6 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_5 ( V_2 ) ;
int V_11 = F_6 ( V_10 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! V_8 -> V_13 )
V_8 -> V_13 = F_7 ( V_10 -> V_12 ) ;
V_8 -> V_14 = F_8 ( F_9 ( V_10 -> V_12 , 1 ) / 512 , 1L ) ;
F_1 ( V_2 , 16 ) ;
return 0 ;
}
static unsigned int F_10 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
unsigned int V_16 , V_17 , V_18 = 0 , V_19 = ~ 0 ;
int V_20 , V_11 ;
if ( ! ( V_2 -> V_21 -> V_22 & V_23 ) )
return F_7 ( V_10 -> V_12 ) ;
for ( V_20 = F_11 ( 9 , F_12 ( V_24 / V_15 ) ) ; V_20 >= 0 ; V_20 -- ) {
V_16 = F_9 ( V_10 -> V_12 , V_15 << V_20 ) ;
if ( V_16 > ( V_15 << V_20 ) ) {
V_16 = F_9 ( V_10 -> V_12 ,
( V_15 << V_20 ) / 4 * 3 ) ;
if ( V_16 > ( V_15 << V_20 ) )
continue;
}
V_17 = V_15 - ( V_16 >> V_20 ) ;
if ( V_17 <= V_19 ) {
V_18 = V_16 ;
V_19 = V_17 ;
}
}
V_11 = F_13 ( V_10 -> V_12 , V_18 ) ;
return V_11 == 0 ? V_18 : F_7 ( V_10 -> V_12 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
F_15 ( V_10 -> V_12 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 = F_17 ( V_8 ) ;
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_27 * V_28 ;
int V_11 ;
switch ( V_26 -> V_29 ) {
case V_30 :
V_28 = V_10 -> V_31 ;
break;
case V_32 :
V_28 = V_10 -> V_33 ;
break;
default:
return - V_34 ;
}
if ( F_18 ( V_10 -> V_35 ) || F_18 ( V_28 ) )
return V_26 -> V_29 ==
V_30 ? 0 : - V_34 ;
V_11 = F_19 ( V_2 -> V_8 , V_26 ) ;
if ( V_11 )
return V_11 ;
return F_20 ( V_10 -> V_35 , V_28 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_36 = 1000 ;
while ( -- V_36 && ! ( F_22 ( V_2 , V_37 )
& V_38 ) )
F_23 ( 1 ) ;
if ( ! V_36 ) {
F_24 ( & V_2 -> V_39 -> V_40 , L_1 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_42 )
{
switch ( V_42 )
{
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_6 :
return F_21 ( V_2 ) ;
}
return 0 ;
}
static int F_26 ( struct V_51 * V_52 ,
unsigned int V_53 , int V_54 )
{
if ( ( V_53 == V_55 ) &&
V_54 == 2 )
return 1 ;
return V_54 ;
}
static void F_27 ( struct V_1 * V_2 , bool V_56 )
{
F_3 ( V_2 , V_50 , V_56 ? 2 : 0 ) ;
F_1 ( V_2 , V_56 ? 32 : 16 ) ;
}
static int F_28 ( struct V_57 * V_39 )
{
const struct V_58 * V_59 =
F_29 ( V_60 , & V_39 -> V_40 ) ;
struct V_9 * V_10 ;
struct V_61 * V_62 ;
struct V_61 * V_63 = V_39 -> V_40 . V_64 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
int V_67 , V_11 , V_20 = 0 ;
struct V_68 * V_69 ;
V_66 = F_30 ( V_39 , V_70 , 0 ) ;
if ( ! V_66 )
return - V_34 ;
V_10 = F_31 ( & V_39 -> V_40 , sizeof( struct V_9 ) , V_71 ) ;
if ( ! V_10 )
return - V_72 ;
V_62 = & V_10 -> V_62 ;
V_69 = & V_10 -> V_69 ;
V_10 -> V_12 = F_32 ( & V_39 -> V_40 , NULL ) ;
if ( F_18 ( V_10 -> V_12 ) ) {
V_11 = F_33 ( V_10 -> V_12 ) ;
F_34 ( & V_39 -> V_40 , L_2 , V_11 ) ;
goto V_73;
}
V_10 -> V_35 = F_35 ( & V_39 -> V_40 ) ;
if ( ! F_18 ( V_10 -> V_35 ) ) {
V_10 -> V_31 = F_36 ( V_10 -> V_35 ,
V_74 ) ;
V_10 -> V_33 = F_36 ( V_10 -> V_35 ,
L_3 ) ;
}
V_2 = F_37 ( V_39 ) ;
if ( ! V_2 ) {
V_11 = - V_72 ;
goto V_73;
}
if ( V_59 && V_59 -> V_75 ) {
const struct V_76 * V_77 = V_59 -> V_75 ;
V_62 -> V_22 |= V_77 -> V_78 ;
V_62 -> V_79 |= V_77 -> V_79 ;
V_62 -> V_80 |= V_77 -> V_80 ;
V_62 -> V_81 = V_77 -> V_81 ;
V_69 -> V_82 = V_77 -> V_82 ;
V_2 -> V_83 = V_77 -> V_83 ;
}
V_2 -> V_84 = V_69 ;
V_2 -> V_85 = F_25 ;
V_2 -> V_86 = F_4 ;
V_2 -> V_87 = F_10 ;
V_2 -> V_88 = F_14 ;
V_2 -> V_89 = F_26 ;
V_2 -> V_90 = F_16 ;
if ( ! V_2 -> V_83 && F_38 ( V_66 ) > 0x100 )
V_2 -> V_83 = 1 ;
if ( V_63 )
* V_62 = * V_63 ;
V_69 -> V_91 = V_92 ;
V_69 -> V_56 = F_27 ;
V_62 -> V_93 = 1 ;
V_62 -> V_79 |= V_94 ;
V_62 -> V_22 |= V_95 ;
V_62 -> V_22 |= V_96 ;
V_62 -> V_22 |= V_97 ;
V_62 -> V_22 |= V_98 ;
V_11 = F_39 ( V_2 , V_62 ) ;
if ( V_11 < 0 )
goto V_99;
while ( 1 ) {
V_67 = F_40 ( V_39 , V_20 ) ;
if ( V_67 < 0 )
break;
V_20 ++ ;
V_11 = F_41 ( & V_39 -> V_40 , V_67 , V_100 , 0 ,
F_42 ( & V_39 -> V_40 ) , V_2 ) ;
if ( V_11 )
goto V_101;
}
if ( ! V_20 ) {
V_11 = V_67 ;
goto V_101;
}
F_43 ( & V_39 -> V_40 , L_4 ,
F_44 ( V_2 -> V_8 ) , ( unsigned long )
( F_30 ( V_39 , V_70 , 0 ) -> V_102 ) ,
V_2 -> V_8 -> V_13 / 1000000 ) ;
return V_11 ;
V_101:
F_45 ( V_2 ) ;
V_99:
F_46 ( V_2 ) ;
V_73:
return V_11 ;
}
static int F_47 ( struct V_57 * V_39 )
{
struct V_7 * V_8 = F_48 ( V_39 ) ;
struct V_1 * V_2 = F_17 ( V_8 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
