static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , F_3 ( V_2 -> V_3 , 0 ) ,
V_4 , V_5 ,
0 , 0 , NULL , 0 , 100 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_6 ;
int V_7 ;
V_6 = F_2 ( V_2 -> V_3 , F_5 ( V_2 -> V_3 , 0 ) ,
V_8 , V_9 ,
0 , 0 , & V_2 -> V_10 , sizeof( V_2 -> V_10 ) , 100 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_10 = F_6 ( V_2 -> V_10 ) ;
V_7 = V_2 -> V_10 & V_11 ;
if ( V_7 != 0x02 ) {
F_7 ( & V_2 -> V_3 -> V_12 , L_1 , V_7 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 )
{
T_1 V_16 ;
int V_6 ;
V_16 = ( V_2 -> V_16 & ~ V_14 ) | V_15 ;
V_6 = F_2 ( V_2 -> V_3 , F_3 ( V_2 -> V_3 , 0 ) ,
V_17 , V_18 ,
V_16 , 0 , NULL , 0 , 100 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_16 = V_16 ;
return 0 ;
}
static void F_9 ( struct V_19 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_21 , V_22 ;
if ( V_19 -> V_21 < 0 )
return;
V_21 = V_2 -> V_23 -> V_21 ;
V_22 = V_2 -> V_22 ;
V_2 -> V_22 = V_21 ;
if ( ! F_10 ( V_24 , & V_2 -> V_25 )
&& F_11 ( V_26 , & V_2 -> V_25 )
&& V_21 & V_27 ) {
F_12 ( V_2 -> V_28 ) ;
}
if ( ( V_21 ^ V_22 ) & V_29 )
F_13 ( V_2 -> V_28 , F_14 ( 100 ) ) ;
if ( ! F_11 ( V_26 , & V_2 -> V_25 ) )
F_15 ( V_24 , & V_2 -> V_25 ) ;
F_16 ( V_2 -> V_30 , V_31 ) ;
}
static void F_17 ( struct V_19 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
if ( V_19 -> V_21 != 0 ) {
F_18 ( V_2 -> V_32 ) ;
F_18 ( V_2 -> V_33 ) ;
}
}
static void F_19 ( struct V_19 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
if ( V_19 -> V_21 != 0 )
F_18 ( V_2 -> V_33 ) ;
}
static void F_20 ( struct V_19 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_34 * V_35 = V_2 -> V_36 ;
int V_21 ;
V_21 = V_2 -> V_37 -> V_21 ;
if ( V_19 -> V_21 != 0 ) {
V_35 -> V_38 -> error = V_19 -> V_21 ;
} else if ( V_21 & V_39 ) {
if ( V_21 & V_40 )
V_35 -> V_38 -> error = - V_41 ;
else
V_35 -> V_38 -> error = - V_42 ;
}
if ( V_35 -> V_43 ) {
if ( V_21 & V_44 ) {
if ( V_21 & V_40 )
V_35 -> V_43 -> error = - V_41 ;
else
V_35 -> V_43 -> error = - V_42 ;
V_35 -> V_43 -> V_45 = 0 ;
} else {
V_35 -> V_43 -> V_45 = V_35 -> V_43 -> V_46 * V_35 -> V_43 -> V_47 ;
}
}
V_35 -> V_38 -> V_48 [ 0 ] = F_6 ( V_2 -> V_37 -> V_49 ) ;
F_21 ( V_2 -> V_28 , V_35 ) ;
}
static void F_22 ( struct V_50 * V_28 , struct V_34 * V_35 )
{
struct V_1 * V_2 = F_23 ( V_28 ) ;
int V_6 ;
unsigned long V_25 ;
F_24 ( & V_2 -> V_51 , V_25 ) ;
if ( F_11 ( V_52 , & V_2 -> V_25 ) ) {
V_6 = - V_53 ;
goto V_54;
}
if ( V_35 -> V_38 -> V_25 & V_55 ) {
V_6 = - V_13 ;
goto V_54;
}
if ( V_35 -> V_43 && V_2 -> V_56 < 6000000 ) {
V_6 = - V_13 ;
goto V_54;
}
V_2 -> V_36 = V_35 ;
V_2 -> V_57 -> V_58 = F_25 ( V_35 -> V_38 -> V_59 ) ;
if ( V_35 -> V_43 )
V_2 -> V_57 -> V_60 = F_25 ( V_35 -> V_43 -> V_46 ) ;
else
V_2 -> V_57 -> V_60 = 0 ;
V_2 -> V_57 -> V_61 = F_26 ( V_35 -> V_38 -> V_61 ) ;
V_6 = F_16 ( V_2 -> V_62 , V_31 ) ;
if ( V_6 < 0 )
goto V_54;
if ( V_35 -> V_43 ) {
struct V_63 * V_43 = V_35 -> V_43 ;
int V_64 ;
if ( V_43 -> V_25 & V_65 )
V_64 = F_27 ( V_2 -> V_3 , 6 ) ;
else
V_64 = F_28 ( V_2 -> V_3 , 2 ) ;
F_29 ( V_2 -> V_32 , V_2 -> V_3 , V_64 ,
F_30 ( V_43 -> V_66 ) , V_43 -> V_66 -> V_67 ,
F_19 , V_2 ) ;
V_6 = F_16 ( V_2 -> V_32 , V_31 ) ;
if ( V_6 < 0 )
goto V_54;
}
V_6 = F_16 ( V_2 -> V_33 , V_31 ) ;
if ( V_6 < 0 )
goto V_54;
V_54:
F_31 ( & V_2 -> V_51 , V_25 ) ;
if ( V_6 < 0 ) {
F_18 ( V_2 -> V_62 ) ;
F_18 ( V_2 -> V_32 ) ;
V_35 -> V_38 -> error = V_6 ;
F_21 ( V_28 , V_35 ) ;
}
}
static int F_32 ( struct V_1 * V_2 , unsigned char V_68 )
{
T_1 V_69 ;
switch ( V_68 ) {
case V_70 :
V_69 = V_71 ;
break;
case V_72 :
case V_73 :
V_69 = V_74 ;
break;
default:
return - V_13 ;
}
return F_2 ( V_2 -> V_3 , F_3 ( V_2 -> V_3 , 0 ) ,
V_75 , V_76 ,
V_69 , 0 , NULL , 0 , 100 ) ;
}
static int F_33 ( struct V_1 * V_2 , int V_77 )
{
return F_8 ( V_2 , V_78 ,
V_77 == 4 ? V_78 : 0 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_79 , bool V_80 )
{
int V_6 ;
if ( V_79 == 0 )
V_79 = 400000 ;
V_6 = F_8 ( V_2 , V_81 ,
V_80 ? V_81 : 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_2 ( V_2 -> V_3 , F_3 ( V_2 -> V_3 , 0 ) ,
V_82 , V_83 ,
V_79 & 0xffff , ( V_79 >> 16 ) & 0xffff , NULL , 0 , 100 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_56 = V_79 ;
return 0 ;
}
static void F_35 ( struct V_50 * V_28 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_23 ( V_28 ) ;
F_32 ( V_2 , V_85 -> V_68 ) ;
F_33 ( V_2 , 1 << V_85 -> V_77 ) ;
F_34 ( V_2 , V_85 -> clock , V_85 -> V_86 == V_87 ) ;
}
static int F_36 ( struct V_50 * V_28 )
{
struct V_1 * V_2 = F_23 ( V_28 ) ;
return ! ! ( V_2 -> V_22 & V_29 ) ;
}
static void F_37 ( struct V_50 * V_28 , int V_88 )
{
struct V_1 * V_2 = F_23 ( V_28 ) ;
if ( V_88 )
F_15 ( V_26 , & V_2 -> V_25 ) ;
else
F_38 ( V_26 , & V_2 -> V_25 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 -> V_30 ) ;
F_40 ( V_2 -> V_33 ) ;
F_40 ( V_2 -> V_32 ) ;
F_40 ( V_2 -> V_62 ) ;
F_41 ( V_2 -> V_23 ) ;
F_41 ( V_2 -> V_57 ) ;
F_41 ( V_2 -> V_37 ) ;
F_42 ( V_2 -> V_28 ) ;
}
static int F_43 ( struct V_89 * V_90 , const struct V_91 * V_92 )
{
struct V_93 * V_3 = F_44 ( V_90 ) ;
struct V_50 * V_28 ;
struct V_1 * V_2 ;
int V_6 ;
V_28 = F_45 ( sizeof( struct V_1 ) , & V_90 -> V_12 ) ;
if ( V_28 == NULL )
return - V_94 ;
V_2 = F_23 ( V_28 ) ;
F_46 ( V_90 , V_2 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = V_28 ;
F_47 ( & V_2 -> V_51 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
goto V_95;
V_6 = F_4 ( V_2 ) ;
if ( V_6 < 0 )
goto V_95;
V_28 -> V_96 = & V_97 ;
V_28 -> V_98 = 400000 ;
V_28 -> V_99 = 50000000 ;
V_28 -> V_100 = V_101 | V_102 ;
V_28 -> V_10 = V_103 | V_104 ;
V_28 -> V_10 |= ( V_2 -> V_10 & V_105 ) ? V_106 : 0 ;
V_28 -> V_107 = 512 * 511 ;
V_28 -> V_108 = 1 ;
V_28 -> V_109 = 512 * 511 ;
V_28 -> V_110 = 512 ;
V_28 -> V_111 = 511 ;
V_2 -> V_30 = F_48 ( 0 , V_112 ) ;
if ( V_2 -> V_30 == NULL ) {
V_6 = - V_94 ;
goto V_95;
}
V_2 -> V_23 = F_49 ( sizeof( struct V_113 ) , V_112 ) ;
if ( V_2 -> V_23 == NULL ) {
V_6 = - V_94 ;
goto V_95;
}
F_50 ( V_2 -> V_30 , V_2 -> V_3 ,
F_51 ( V_3 ,
V_90 -> V_114 -> V_115 [ 0 ] . V_116 . V_117 ) ,
V_2 -> V_23 , sizeof( struct V_113 ) ,
F_9 , V_2 ,
V_90 -> V_114 -> V_115 [ 0 ] . V_116 . V_118 ) ;
V_2 -> V_62 = F_48 ( 0 , V_112 ) ;
if ( V_2 -> V_62 == NULL ) {
V_6 = - V_94 ;
goto V_95;
}
V_2 -> V_57 = F_49 ( sizeof( struct V_119 ) , V_112 ) ;
if ( V_2 -> V_57 == NULL ) {
V_6 = - V_94 ;
goto V_95;
}
V_2 -> V_57 -> V_120 = V_121 ;
F_29 ( V_2 -> V_62 , V_2 -> V_3 , F_28 ( V_3 , 2 ) ,
V_2 -> V_57 , sizeof( struct V_119 ) ,
F_17 , V_2 ) ;
V_2 -> V_32 = F_48 ( 0 , V_112 ) ;
if ( V_2 -> V_32 == NULL ) {
V_6 = - V_94 ;
goto V_95;
}
V_2 -> V_33 = F_48 ( 0 , V_112 ) ;
if ( V_2 -> V_33 == NULL ) {
V_6 = - V_94 ;
goto V_95;
}
V_2 -> V_37 = F_49 ( sizeof( struct V_119 ) , V_112 ) ;
if ( V_2 -> V_37 == NULL ) {
V_6 = - V_94 ;
goto V_95;
}
F_29 ( V_2 -> V_33 , V_2 -> V_3 , F_27 ( V_3 , 6 ) ,
V_2 -> V_37 , sizeof( struct V_122 ) ,
F_20 , V_2 ) ;
V_6 = F_52 ( V_2 -> V_28 ) ;
if ( V_6 )
goto V_95;
V_6 = F_16 ( V_2 -> V_30 , V_112 ) ;
if ( V_6 < 0 ) {
F_53 ( V_2 -> V_28 ) ;
goto V_95;
}
return 0 ;
V_95:
F_39 ( V_2 ) ;
return V_6 ;
}
static void F_54 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_55 ( V_90 ) ;
F_56 ( & V_2 -> V_51 ) ;
F_15 ( V_52 , & V_2 -> V_25 ) ;
F_57 ( & V_2 -> V_51 ) ;
F_58 ( V_2 -> V_30 ) ;
F_58 ( V_2 -> V_62 ) ;
F_58 ( V_2 -> V_32 ) ;
F_58 ( V_2 -> V_33 ) ;
F_53 ( V_2 -> V_28 ) ;
F_39 ( V_2 ) ;
}
static int T_3 F_59 ( void )
{
return F_60 ( & V_123 ) ;
}
static void T_4 F_61 ( void )
{
F_62 ( & V_123 ) ;
}
