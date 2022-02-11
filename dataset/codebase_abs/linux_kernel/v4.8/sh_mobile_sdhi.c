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
static int F_16 ( struct V_11 * V_12 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_31 * V_32 ;
int V_15 ;
switch ( V_30 -> V_33 ) {
case V_34 :
V_32 = V_14 -> V_35 ;
break;
case V_36 :
V_32 = V_14 -> V_37 ;
break;
default:
return - V_38 ;
}
if ( F_18 ( V_14 -> V_39 ) || F_18 ( V_32 ) )
return V_30 -> V_33 ==
V_34 ? 0 : - V_38 ;
V_15 = F_19 ( V_2 -> V_12 , V_30 ) ;
if ( V_15 )
return V_15 ;
return F_20 ( V_14 -> V_39 , V_32 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_40 = 1000 ;
while ( -- V_40 && ! ( F_22 ( V_2 , V_41 )
& V_42 ) )
F_23 ( 1 ) ;
if ( ! V_40 ) {
F_24 ( & V_2 -> V_43 -> V_44 , L_1 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_46 )
{
switch ( V_46 )
{
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_10 :
return F_21 ( V_2 ) ;
}
return 0 ;
}
static int F_26 ( struct V_55 * V_56 ,
unsigned int V_57 , int V_58 )
{
if ( ( V_57 == V_59 ) &&
V_58 == 2 )
return 1 ;
return V_58 ;
}
static void F_27 ( struct V_1 * V_2 , bool V_60 )
{
F_3 ( V_2 , V_54 , V_60 ? 2 : 0 ) ;
F_1 ( V_2 , V_60 ? 32 : 16 ) ;
}
static int F_28 ( struct V_61 * V_43 )
{
const struct V_62 * V_63 =
F_29 ( V_64 , & V_43 -> V_44 ) ;
struct V_13 * V_14 ;
struct V_65 * V_66 ;
struct V_65 * V_67 = V_43 -> V_44 . V_68 ;
struct V_1 * V_2 ;
struct V_69 * V_70 ;
int V_71 , V_15 , V_24 = 0 ;
struct V_72 * V_73 ;
V_70 = F_30 ( V_43 , V_74 , 0 ) ;
if ( ! V_70 )
return - V_38 ;
V_14 = F_31 ( & V_43 -> V_44 , sizeof( struct V_13 ) , V_75 ) ;
if ( ! V_14 )
return - V_76 ;
V_66 = & V_14 -> V_66 ;
V_73 = & V_14 -> V_73 ;
V_14 -> V_16 = F_32 ( & V_43 -> V_44 , NULL ) ;
if ( F_18 ( V_14 -> V_16 ) ) {
V_15 = F_33 ( V_14 -> V_16 ) ;
F_34 ( & V_43 -> V_44 , L_2 , V_15 ) ;
goto V_77;
}
V_14 -> V_39 = F_35 ( & V_43 -> V_44 ) ;
if ( ! F_18 ( V_14 -> V_39 ) ) {
V_14 -> V_35 = F_36 ( V_14 -> V_39 ,
V_78 ) ;
V_14 -> V_37 = F_36 ( V_14 -> V_39 ,
L_3 ) ;
}
V_2 = F_37 ( V_43 ) ;
if ( ! V_2 ) {
V_15 = - V_76 ;
goto V_77;
}
if ( V_63 && V_63 -> V_79 ) {
const struct V_80 * V_81 = V_63 -> V_79 ;
V_66 -> V_26 |= V_81 -> V_82 ;
V_66 -> V_83 |= V_81 -> V_83 ;
V_66 -> V_84 |= V_81 -> V_84 ;
V_66 -> V_85 = V_81 -> V_85 ;
V_73 -> V_86 = V_81 -> V_86 ;
V_2 -> V_87 = V_81 -> V_87 ;
}
V_2 -> V_88 = V_73 ;
V_2 -> V_89 = F_25 ;
V_2 -> V_90 = F_4 ;
V_2 -> V_91 = F_10 ;
V_2 -> V_92 = F_14 ;
V_2 -> V_93 = F_26 ;
V_2 -> V_94 = F_16 ;
if ( ! V_2 -> V_87 && F_38 ( V_70 ) > 0x100 )
V_2 -> V_87 = 1 ;
if ( V_67 )
* V_66 = * V_67 ;
V_73 -> V_95 = V_96 ;
V_73 -> V_60 = F_27 ;
V_66 -> V_97 = 1 ;
V_66 -> V_83 |= V_98 ;
V_66 -> V_26 |= V_99 ;
V_66 -> V_26 |= V_100 ;
V_66 -> V_26 |= V_101 ;
V_66 -> V_26 |= V_102 ;
V_15 = F_39 ( V_2 , V_66 ) ;
if ( V_15 < 0 )
goto V_103;
while ( 1 ) {
V_71 = F_40 ( V_43 , V_24 ) ;
if ( V_71 < 0 )
break;
V_24 ++ ;
V_15 = F_41 ( & V_43 -> V_44 , V_71 , V_104 , 0 ,
F_42 ( & V_43 -> V_44 ) , V_2 ) ;
if ( V_15 )
goto V_105;
}
if ( ! V_24 ) {
V_15 = V_71 ;
goto V_105;
}
F_43 ( & V_43 -> V_44 , L_4 ,
F_44 ( V_2 -> V_12 ) , ( unsigned long )
( F_30 ( V_43 , V_74 , 0 ) -> V_106 ) ,
V_2 -> V_12 -> V_17 / 1000000 ) ;
return V_15 ;
V_105:
F_45 ( V_2 ) ;
V_103:
F_46 ( V_2 ) ;
V_77:
return V_15 ;
}
static int F_47 ( struct V_61 * V_43 )
{
struct V_11 * V_12 = F_48 ( V_43 ) ;
struct V_1 * V_2 = F_17 ( V_12 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
