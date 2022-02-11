static void F_1 ( struct V_1 * V_2 ,
struct V_3
* V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_6 ) ;
F_3 ( V_6 , V_7 , & V_4 -> V_8 ) ;
if ( V_4 -> V_8 & V_9 )
F_4 ( V_6 , V_7 ,
V_9 ,
V_9 ) ;
if ( V_4 -> V_8 & V_10 )
F_4 ( V_6 , V_7 ,
V_10 ,
V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct
V_3
* V_4 , int V_11 )
{
int V_12 = 0 ;
T_1 V_13 , V_14 , V_15 ;
V_13 = ( V_4 -> V_8 & 0xfffff000 ) ;
V_14 = V_13 >> V_16 ;
V_15 = V_13 - ( V_14 << V_16 ) ;
if ( V_4 -> V_8 & V_9 ) {
V_12 = 1 ;
if ( V_11 )
F_6 ( V_17 , V_2 , 1 ,
V_14 , V_15 , 0 ,
F_7 ( V_2 , V_14 ) ,
0 , - 1 , V_2 -> V_18 , L_1 ) ;
}
if ( V_4 -> V_8 & V_10 ) {
V_12 = 1 ;
if ( V_11 )
F_6 ( V_19 , V_2 , 1 ,
V_14 , V_15 , 0 ,
F_7 ( V_2 , V_14 ) ,
0 , - 1 , V_2 -> V_18 , L_1 ) ;
}
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_9 ( 1 , L_2 , V_2 -> V_20 ) ;
F_1 ( V_2 , & V_4 ) ;
F_5 ( V_2 , & V_4 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_21 V_22 ,
enum V_23 V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 ;
T_2 V_30 , V_31 ;
T_1 V_32 , V_33 , V_34 ;
F_11 ( V_6 , V_35 , & V_31 ) ;
V_34 = 0 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_36 ; V_29 ++ ) {
V_26 = V_2 -> V_37 [ V_29 ] ;
V_28 = V_26 -> V_38 [ 0 ] -> V_28 ;
F_11 ( V_6 , V_39 + V_29 , & V_30 ) ;
F_9 ( 1 , L_3 ,
V_2 -> V_20 , V_29 , V_30 ) ;
V_33 = ( ( T_1 ) V_30 << 23 ) ;
F_9 ( 1 , L_4 ,
V_2 -> V_20 , V_29 , V_33 ,
V_34 ) ;
if ( V_34 && ! V_33 )
V_33 = 1UL << 31 ;
if ( V_33 == V_34 )
continue;
V_32 = V_34 ;
V_26 -> V_40 = V_32 >> V_16 ;
V_26 -> V_41 = ( V_33 >> V_16 ) - 1 ;
V_28 -> V_42 = V_26 -> V_41 - V_26 -> V_40 + 1 ;
V_28 -> V_43 = 1 << 12 ;
V_28 -> V_24 = V_24 ;
V_28 -> V_44 = V_45 ;
V_28 -> V_22 = V_22 ;
V_34 = V_33 ;
}
}
static int F_12 ( struct V_5 * V_6 , int V_46 )
{
struct V_1 * V_2 ;
struct V_47 V_48 [ 2 ] ;
T_2 V_31 ;
T_1 V_49 , V_50 ;
enum V_23 V_24 ;
enum V_21 V_22 ;
F_9 ( 0 , L_5 ) ;
if ( F_3 ( V_6 , V_51 , & V_49 ) )
return - V_52 ;
V_48 [ 0 ] . type = V_53 ;
V_48 [ 0 ] . V_54 = V_55 ;
V_48 [ 0 ] . V_56 = true ;
V_48 [ 1 ] . type = V_57 ;
V_48 [ 1 ] . V_54 = V_58 ;
V_48 [ 1 ] . V_56 = false ;
V_2 = F_13 ( 0 , F_14 ( V_48 ) , V_48 , 0 ) ;
if ( V_2 == NULL )
return - V_59 ;
F_9 ( 0 , L_6 , V_2 ) ;
V_2 -> V_6 = & V_6 -> V_60 ;
V_2 -> V_61 = V_62 | V_63 | V_64 ;
V_2 -> V_65 = V_66 | V_67 | V_68 ;
F_11 ( V_6 , V_35 , & V_31 ) ;
switch ( ( V_31 >> V_69 ) & ( F_15 ( 0 ) | F_15 ( 1 ) ) ) {
case V_70 :
V_24 = V_71 ;
break;
case V_72 :
V_24 = V_73 ;
break;
case V_74 :
V_24 = V_75 ;
break;
default:
F_9 ( 0 , L_7 ) ;
V_24 = - V_76 ;
}
if ( ( V_24 == V_73 ) || ( V_24 == V_75 ) )
V_2 -> V_77 = V_2 -> V_65 ;
else
V_2 -> V_77 = V_66 ;
V_2 -> V_78 = V_79 ;
F_3 ( V_6 , V_51 , & V_49 ) ;
V_50 = ( ( V_49 >> V_80 ) &
( F_15 ( 0 ) | F_15 ( 1 ) ) ) ;
V_2 -> V_81 = ( V_50 == V_82 )
? V_83 : V_84 ;
switch ( V_50 ) {
case V_85 :
V_22 = V_86 ;
break;
case V_87 :
V_22 = V_88 ;
break;
case V_89 :
case V_82 :
V_22 = V_90 ;
break;
default:
F_9 ( 0 , L_8 ) ;
V_22 = V_91 ;
break;
}
F_10 ( V_2 , V_6 , V_22 , V_24 ) ;
F_4 ( V_6 , V_7 ,
( V_9 |
V_10 ) ,
( V_9 |
V_10 ) ) ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 = V_95 ;
V_2 -> V_18 = L_9 ;
V_2 -> V_96 = F_16 ( V_6 ) ;
V_2 -> V_97 = F_8 ;
V_2 -> V_98 = NULL ;
if ( F_17 ( V_2 ) ) {
F_9 ( 3 , L_10 ) ;
goto V_99;
}
V_100 = F_18 ( & V_6 -> V_60 , V_93 ) ;
if ( ! V_100 ) {
F_19 ( V_101
L_11 ,
V_102 ) ;
F_19 ( V_101
L_12 ,
V_102 ) ;
}
F_9 ( 3 , L_13 ) ;
return 0 ;
V_99:
F_20 ( V_2 ) ;
return - V_103 ;
}
static int F_21 ( struct V_5 * V_6 ,
const struct V_104 * V_105 )
{
int V_106 ;
F_9 ( 0 , L_5 ) ;
V_106 = F_12 ( V_6 , V_105 -> V_107 ) ;
if ( V_108 == NULL )
V_108 = F_22 ( V_6 ) ;
return V_106 ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_9 ( 0 , L_14 ) ;
if ( V_100 )
F_24 ( V_100 ) ;
if ( ( V_2 = F_25 ( & V_6 -> V_60 ) ) == NULL )
return;
F_20 ( V_2 ) ;
}
static int T_3 F_26 ( void )
{
int V_109 ;
F_27 () ;
V_109 = F_28 ( & V_110 ) ;
if ( V_109 < 0 )
goto V_111;
if ( V_108 == NULL ) {
const struct V_104 * V_112 = & V_113 [ 0 ] ;
int V_114 = 0 ;
V_115 = 0 ;
while ( V_108 == NULL && V_112 -> V_116 != 0 ) {
V_108 = F_29 ( V_112 -> V_116 ,
V_112 -> V_117 , NULL ) ;
V_114 ++ ;
V_112 = & V_113 [ V_114 ] ;
}
if ( ! V_108 ) {
F_9 ( 0 , L_15 ) ;
V_109 = - V_103 ;
goto V_118;
}
V_109 = F_21 ( V_108 , V_113 ) ;
if ( V_109 < 0 ) {
F_9 ( 0 , L_16 ) ;
V_109 = - V_103 ;
goto V_118;
}
}
return 0 ;
V_118:
F_30 ( & V_110 ) ;
V_111:
F_31 ( V_108 ) ;
return V_109 ;
}
static void T_4 F_32 ( void )
{
F_30 ( & V_110 ) ;
if ( ! V_115 )
F_23 ( V_108 ) ;
F_31 ( V_108 ) ;
}
