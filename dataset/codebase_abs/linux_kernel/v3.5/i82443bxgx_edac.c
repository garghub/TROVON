static void F_1 ( struct V_1 * V_2 ,
struct V_3
* V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_6 , V_8 , & V_4 -> V_9 ) ;
if ( V_4 -> V_9 & V_10 )
F_4 ( V_6 , V_8 ,
V_10 ,
V_10 ) ;
if ( V_4 -> V_9 & V_11 )
F_4 ( V_6 , V_8 ,
V_11 ,
V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct
V_3
* V_4 , int V_12 )
{
int V_13 = 0 ;
T_1 V_14 , V_15 , V_16 ;
V_14 = ( V_4 -> V_9 & 0xfffff000 ) ;
V_15 = V_14 >> V_17 ;
V_16 = V_14 - ( V_15 << V_17 ) ;
if ( V_4 -> V_9 & V_10 ) {
V_13 = 1 ;
if ( V_12 )
F_6 ( V_18 , V_2 ,
V_15 , V_16 , 0 ,
F_7 ( V_2 , V_15 ) ,
0 , - 1 , V_2 -> V_19 , L_1 , NULL ) ;
}
if ( V_4 -> V_9 & V_11 ) {
V_13 = 1 ;
if ( V_12 )
F_6 ( V_20 , V_2 ,
V_15 , V_16 , 0 ,
F_7 ( V_2 , V_15 ) ,
0 , - 1 , V_2 -> V_19 , L_1 , NULL ) ;
}
return V_13 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_9 ( L_2 , V_2 -> V_21 , __FILE__ , V_22 ) ;
F_1 ( V_2 , & V_4 ) ;
F_5 ( V_2 , & V_4 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_23 V_24 ,
enum V_25 V_26 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_31 ;
T_2 V_32 , V_33 ;
T_1 V_34 , V_35 , V_36 ;
F_11 ( V_6 , V_37 , & V_33 ) ;
V_36 = 0 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_38 ; V_31 ++ ) {
V_28 = & V_2 -> V_39 [ V_31 ] ;
V_30 = V_28 -> V_40 [ 0 ] . V_30 ;
F_11 ( V_6 , V_41 + V_31 , & V_32 ) ;
F_9 ( L_3 ,
V_2 -> V_21 , __FILE__ , V_22 , V_31 , V_32 ) ;
V_35 = ( ( T_1 ) V_32 << 23 ) ;
F_9 ( L_4
L_5 ,
V_2 -> V_21 , __FILE__ , V_22 , V_31 , V_35 ,
V_36 ) ;
if ( V_36 && ! V_35 )
V_35 = 1UL << 31 ;
if ( V_35 == V_36 )
continue;
V_34 = V_36 ;
V_28 -> V_42 = V_34 >> V_17 ;
V_28 -> V_43 = ( V_35 >> V_17 ) - 1 ;
V_30 -> V_44 = V_28 -> V_43 - V_28 -> V_42 + 1 ;
V_30 -> V_45 = 1 << 12 ;
V_30 -> V_26 = V_26 ;
V_30 -> V_46 = V_47 ;
V_30 -> V_24 = V_24 ;
V_36 = V_35 ;
}
}
static int F_12 ( struct V_5 * V_6 , int V_48 )
{
struct V_1 * V_2 ;
struct V_49 V_50 [ 2 ] ;
T_2 V_33 ;
T_1 V_51 , V_52 ;
enum V_25 V_26 ;
enum V_23 V_24 ;
F_13 ( L_6 , __FILE__ , V_22 ) ;
if ( F_3 ( V_6 , V_53 , & V_51 ) )
return - V_54 ;
V_50 [ 0 ] . type = V_55 ;
V_50 [ 0 ] . V_56 = V_57 ;
V_50 [ 0 ] . V_58 = true ;
V_50 [ 1 ] . type = V_59 ;
V_50 [ 1 ] . V_56 = V_60 ;
V_50 [ 1 ] . V_58 = false ;
V_2 = F_14 ( 0 , F_15 ( V_50 ) , V_50 , 0 ) ;
if ( V_2 == NULL )
return - V_61 ;
F_13 ( L_7 , __FILE__ , V_22 , V_2 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_62 = V_63 | V_64 | V_65 ;
V_2 -> V_66 = V_67 | V_68 | V_69 ;
F_11 ( V_6 , V_37 , & V_33 ) ;
switch ( ( V_33 >> V_70 ) & ( F_16 ( 0 ) | F_16 ( 1 ) ) ) {
case V_71 :
V_26 = V_72 ;
break;
case V_73 :
V_26 = V_74 ;
break;
case V_75 :
V_26 = V_76 ;
break;
default:
F_13 ( L_8
L_9 ) ;
V_26 = - V_77 ;
}
if ( ( V_26 == V_74 ) || ( V_26 == V_76 ) )
V_2 -> V_78 = V_2 -> V_66 ;
else
V_2 -> V_78 = V_67 ;
V_2 -> V_79 = V_80 ;
F_3 ( V_6 , V_53 , & V_51 ) ;
V_52 = ( ( V_51 >> V_81 ) &
( F_16 ( 0 ) | F_16 ( 1 ) ) ) ;
V_2 -> V_82 = ( V_52 == V_83 )
? V_84 : V_85 ;
switch ( V_52 ) {
case V_86 :
V_24 = V_87 ;
break;
case V_88 :
V_24 = V_89 ;
break;
case V_90 :
case V_83 :
V_24 = V_91 ;
break;
default:
F_13 ( L_10
L_11 , V_22 ) ;
V_24 = V_92 ;
break;
}
F_10 ( V_2 , V_6 , V_24 , V_26 ) ;
F_4 ( V_6 , V_8 ,
( V_10 |
V_11 ) ,
( V_10 |
V_11 ) ) ;
V_2 -> V_93 = V_94 ;
V_2 -> V_95 = V_96 ;
V_2 -> V_19 = L_12 ;
V_2 -> V_97 = F_17 ( V_6 ) ;
V_2 -> V_98 = F_8 ;
V_2 -> V_99 = NULL ;
if ( F_18 ( V_2 ) ) {
F_19 ( L_13 , V_22 ) ;
goto V_100;
}
V_101 = F_20 ( & V_6 -> V_7 , V_94 ) ;
if ( ! V_101 ) {
F_21 ( V_102
L_14 ,
V_22 ) ;
F_21 ( V_102
L_15 ,
V_22 ) ;
}
F_19 ( L_16 , __FILE__ , V_22 ) ;
return 0 ;
V_100:
F_22 ( V_2 ) ;
return - V_103 ;
}
static int T_3 F_23 ( struct V_5 * V_6 ,
const struct V_104 * V_105 )
{
int V_106 ;
F_13 ( L_6 , __FILE__ , V_22 ) ;
V_106 = F_12 ( V_6 , V_105 -> V_107 ) ;
if ( V_108 == NULL )
V_108 = F_24 ( V_6 ) ;
return V_106 ;
}
static void T_4 F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_13 ( L_17 , __FILE__ , V_22 ) ;
if ( V_101 )
F_26 ( V_101 ) ;
if ( ( V_2 = F_27 ( & V_6 -> V_7 ) ) == NULL )
return;
F_22 ( V_2 ) ;
}
static int T_5 F_28 ( void )
{
int V_109 ;
F_29 () ;
V_109 = F_30 ( & V_110 ) ;
if ( V_109 < 0 )
goto V_111;
if ( V_108 == NULL ) {
const struct V_104 * V_112 = & V_113 [ 0 ] ;
int V_114 = 0 ;
V_115 = 0 ;
while ( V_108 == NULL && V_112 -> V_116 != 0 ) {
V_108 = F_31 ( V_112 -> V_116 ,
V_112 -> V_117 , NULL ) ;
V_114 ++ ;
V_112 = & V_113 [ V_114 ] ;
}
if ( ! V_108 ) {
F_13 ( L_18 ) ;
V_109 = - V_103 ;
goto V_118;
}
V_109 = F_23 ( V_108 , V_113 ) ;
if ( V_109 < 0 ) {
F_13 ( L_19 ) ;
V_109 = - V_103 ;
goto V_118;
}
}
return 0 ;
V_118:
F_32 ( & V_110 ) ;
V_111:
if ( V_108 != NULL )
F_33 ( V_108 ) ;
return V_109 ;
}
static void T_6 F_34 ( void )
{
F_32 ( & V_110 ) ;
if ( ! V_115 )
F_25 ( V_108 ) ;
if ( V_108 )
F_33 ( V_108 ) ;
}
