static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
switch ( F_2 ( V_2 , V_5 ) ) {
case V_6 :
V_4 = ( V_3 == 32 ) ? 0x0001 : 0x0000 ;
break;
case V_7 :
V_4 = ( V_3 == 32 ) ? 0x0000 : 0x0001 ;
break;
case V_8 :
case V_9 :
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
F_3 ( V_2 , V_10 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
int V_15 = F_6 ( V_14 -> V_16 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! V_12 -> V_17 )
V_12 -> V_17 = F_7 ( V_14 -> V_16 ) ;
V_12 -> V_18 = F_8 ( F_9 ( V_14 -> V_16 , 1 ) / 512 , 1L ) ;
F_1 ( V_2 , 16 ) ;
return 0 ;
}
static unsigned int F_10 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
unsigned int V_20 , V_21 , V_22 = 0 , V_23 = ~ 0 ;
int V_24 , V_15 ;
if ( ! ( V_2 -> V_25 -> V_26 & V_27 ) )
return F_7 ( V_14 -> V_16 ) ;
for ( V_24 = F_11 ( 9 , F_12 ( V_28 / V_19 ) ) ; V_24 >= 0 ; V_24 -- ) {
V_20 = F_9 ( V_14 -> V_16 , V_19 << V_24 ) ;
if ( V_20 > ( V_19 << V_24 ) ) {
V_20 = F_9 ( V_14 -> V_16 ,
( V_19 << V_24 ) / 4 * 3 ) ;
if ( V_20 > ( V_19 << V_24 ) )
continue;
}
V_21 = V_19 - ( V_20 >> V_24 ) ;
if ( V_21 <= V_23 ) {
V_22 = V_20 ;
V_23 = V_21 ;
}
}
V_15 = F_13 ( V_14 -> V_16 , V_22 ) ;
return V_15 == 0 ? V_22 : F_7 ( V_14 -> V_16 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
F_15 ( V_14 -> V_16 ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
return ! ( F_18 ( V_2 , V_29 ) & V_30 ) ;
}
static int F_19 ( struct V_11 * V_12 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_33 * V_34 ;
int V_15 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_34 = V_14 -> V_37 ;
break;
case V_38 :
V_34 = V_14 -> V_39 ;
break;
default:
return - V_40 ;
}
if ( F_20 ( V_14 -> V_41 ) || F_20 ( V_34 ) )
return V_32 -> V_35 ==
V_36 ? 0 : - V_40 ;
V_15 = F_21 ( V_2 -> V_12 , V_32 ) ;
if ( V_15 )
return V_15 ;
return F_22 ( V_14 -> V_41 , V_34 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_42 = 1000 ;
while ( -- V_42 && ! ( F_18 ( V_2 , V_29 )
& V_43 ) )
F_24 ( 1 ) ;
if ( ! V_42 ) {
F_25 ( & V_2 -> V_44 -> V_45 , L_1 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_47 )
{
switch ( V_47 )
{
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_10 :
return F_23 ( V_2 ) ;
}
return 0 ;
}
static int F_27 ( struct V_56 * V_57 ,
unsigned int V_58 , int V_59 )
{
if ( ( V_58 == V_60 ) &&
V_59 == 2 )
return 1 ;
return V_59 ;
}
static void F_28 ( struct V_1 * V_2 , bool V_61 )
{
F_3 ( V_2 , V_55 , V_61 ? 2 : 0 ) ;
F_1 ( V_2 , V_61 ? 32 : 16 ) ;
}
static int F_29 ( struct V_62 * V_44 )
{
const struct V_63 * V_64 =
F_30 ( V_65 , & V_44 -> V_45 ) ;
struct V_13 * V_14 ;
struct V_66 * V_67 ;
struct V_66 * V_68 = V_44 -> V_45 . V_69 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
int V_72 , V_15 , V_24 = 0 ;
struct V_73 * V_74 ;
V_71 = F_31 ( V_44 , V_75 , 0 ) ;
if ( ! V_71 )
return - V_40 ;
V_14 = F_32 ( & V_44 -> V_45 , sizeof( struct V_13 ) , V_76 ) ;
if ( ! V_14 )
return - V_77 ;
V_67 = & V_14 -> V_67 ;
V_74 = & V_14 -> V_74 ;
V_14 -> V_16 = F_33 ( & V_44 -> V_45 , NULL ) ;
if ( F_20 ( V_14 -> V_16 ) ) {
V_15 = F_34 ( V_14 -> V_16 ) ;
F_35 ( & V_44 -> V_45 , L_2 , V_15 ) ;
goto V_78;
}
V_14 -> V_41 = F_36 ( & V_44 -> V_45 ) ;
if ( ! F_20 ( V_14 -> V_41 ) ) {
V_14 -> V_37 = F_37 ( V_14 -> V_41 ,
V_79 ) ;
V_14 -> V_39 = F_37 ( V_14 -> V_41 ,
L_3 ) ;
}
V_2 = F_38 ( V_44 ) ;
if ( ! V_2 ) {
V_15 = - V_77 ;
goto V_78;
}
if ( V_64 && V_64 -> V_80 ) {
const struct V_81 * V_82 = V_64 -> V_80 ;
V_67 -> V_26 |= V_82 -> V_83 ;
V_67 -> V_84 |= V_82 -> V_84 ;
V_67 -> V_85 |= V_82 -> V_85 ;
V_67 -> V_86 = V_82 -> V_86 ;
V_74 -> V_87 = V_82 -> V_87 ;
V_2 -> V_88 = V_82 -> V_88 ;
}
V_2 -> V_89 = V_74 ;
V_2 -> V_90 = F_26 ;
V_2 -> V_91 = F_4 ;
V_2 -> V_92 = F_10 ;
V_2 -> V_93 = F_14 ;
V_2 -> V_94 = F_27 ;
if ( V_67 -> V_26 & V_27 ) {
V_2 -> V_95 = F_16 ;
V_2 -> V_96 =
F_19 ;
}
if ( ! V_2 -> V_88 && F_39 ( V_71 ) > 0x100 )
V_2 -> V_88 = 1 ;
if ( V_68 )
* V_67 = * V_68 ;
V_74 -> V_97 = V_98 ;
V_74 -> V_61 = F_28 ;
V_67 -> V_99 = 1 ;
V_67 -> V_84 |= V_100 ;
V_67 -> V_26 |= V_101 ;
V_67 -> V_26 |= V_102 ;
V_67 -> V_26 |= V_103 ;
V_67 -> V_26 |= V_104 ;
V_15 = F_40 ( V_2 , V_67 ) ;
if ( V_15 < 0 )
goto V_105;
while ( 1 ) {
V_72 = F_41 ( V_44 , V_24 ) ;
if ( V_72 < 0 )
break;
V_24 ++ ;
V_15 = F_42 ( & V_44 -> V_45 , V_72 , V_106 , 0 ,
F_43 ( & V_44 -> V_45 ) , V_2 ) ;
if ( V_15 )
goto V_107;
}
if ( ! V_24 ) {
V_15 = V_72 ;
goto V_107;
}
F_44 ( & V_44 -> V_45 , L_4 ,
F_45 ( V_2 -> V_12 ) , ( unsigned long )
( F_31 ( V_44 , V_75 , 0 ) -> V_108 ) ,
V_2 -> V_12 -> V_17 / 1000000 ) ;
return V_15 ;
V_107:
F_46 ( V_2 ) ;
V_105:
F_47 ( V_2 ) ;
V_78:
return V_15 ;
}
static int F_48 ( struct V_62 * V_44 )
{
struct V_11 * V_12 = F_49 ( V_44 ) ;
struct V_1 * V_2 = F_17 ( V_12 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
