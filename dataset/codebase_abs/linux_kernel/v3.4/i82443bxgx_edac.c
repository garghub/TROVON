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
F_6 ( V_2 , V_15 , V_16 ,
0 , F_7 ( V_2 , V_15 ) , 0 ,
V_2 -> V_18 ) ;
}
if ( V_4 -> V_9 & V_11 ) {
V_13 = 1 ;
if ( V_12 )
F_8 ( V_2 , V_15 , V_16 ,
F_7 ( V_2 , V_15 ) ,
V_2 -> V_18 ) ;
}
return V_13 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_10 ( L_1 , V_2 -> V_19 , __FILE__ , V_20 ) ;
F_1 ( V_2 , & V_4 ) ;
F_5 ( V_2 , & V_4 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_21 V_22 ,
enum V_23 V_24 )
{
struct V_25 * V_26 ;
int V_27 ;
T_2 V_28 , V_29 ;
T_1 V_30 , V_31 , V_32 ;
F_12 ( V_6 , V_33 , & V_29 ) ;
V_32 = 0 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_34 ; V_27 ++ ) {
V_26 = & V_2 -> V_35 [ V_27 ] ;
F_12 ( V_6 , V_36 + V_27 , & V_28 ) ;
F_10 ( L_2 ,
V_2 -> V_19 , __FILE__ , V_20 , V_27 , V_28 ) ;
V_31 = ( ( T_1 ) V_28 << 23 ) ;
F_10 ( L_3
L_4 ,
V_2 -> V_19 , __FILE__ , V_20 , V_27 , V_31 ,
V_32 ) ;
if ( V_32 && ! V_31 )
V_31 = 1UL << 31 ;
if ( V_31 == V_32 )
continue;
V_30 = V_32 ;
V_26 -> V_37 = V_30 >> V_17 ;
V_26 -> V_38 = ( V_31 >> V_17 ) - 1 ;
V_26 -> V_39 = V_26 -> V_38 - V_26 -> V_37 + 1 ;
V_26 -> V_40 = 1 << 12 ;
V_26 -> V_24 = V_24 ;
V_26 -> V_41 = V_42 ;
V_26 -> V_22 = V_22 ;
V_32 = V_31 ;
}
}
static int F_13 ( struct V_5 * V_6 , int V_43 )
{
struct V_1 * V_2 ;
T_2 V_29 ;
T_1 V_44 , V_45 ;
enum V_23 V_24 ;
enum V_21 V_22 ;
F_14 ( L_5 , __FILE__ , V_20 ) ;
if ( F_3 ( V_6 , V_46 , & V_44 ) )
return - V_47 ;
V_2 = F_15 ( 0 , V_48 , V_49 , 0 ) ;
if ( V_2 == NULL )
return - V_50 ;
F_14 ( L_6 , __FILE__ , V_20 , V_2 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_51 = V_52 | V_53 | V_54 ;
V_2 -> V_55 = V_56 | V_57 | V_58 ;
F_12 ( V_6 , V_33 , & V_29 ) ;
switch ( ( V_29 >> V_59 ) & ( F_16 ( 0 ) | F_16 ( 1 ) ) ) {
case V_60 :
V_24 = V_61 ;
break;
case V_62 :
V_24 = V_63 ;
break;
case V_64 :
V_24 = V_65 ;
break;
default:
F_14 ( L_7
L_8 ) ;
V_24 = - V_66 ;
}
if ( ( V_24 == V_63 ) || ( V_24 == V_65 ) )
V_2 -> V_67 = V_2 -> V_55 ;
else
V_2 -> V_67 = V_56 ;
V_2 -> V_68 = V_69 ;
F_3 ( V_6 , V_46 , & V_44 ) ;
V_45 = ( ( V_44 >> V_70 ) &
( F_16 ( 0 ) | F_16 ( 1 ) ) ) ;
V_2 -> V_71 = ( V_45 == V_72 )
? V_73 : V_74 ;
switch ( V_45 ) {
case V_75 :
V_22 = V_76 ;
break;
case V_77 :
V_22 = V_78 ;
break;
case V_79 :
case V_72 :
V_22 = V_80 ;
break;
default:
F_14 ( L_9
L_10 , V_20 ) ;
V_22 = V_81 ;
break;
}
F_11 ( V_2 , V_6 , V_22 , V_24 ) ;
F_4 ( V_6 , V_8 ,
( V_10 |
V_11 ) ,
( V_10 |
V_11 ) ) ;
V_2 -> V_82 = V_83 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_18 = L_11 ;
V_2 -> V_86 = F_17 ( V_6 ) ;
V_2 -> V_87 = F_9 ;
V_2 -> V_88 = NULL ;
if ( F_18 ( V_2 ) ) {
F_19 ( L_12 , V_20 ) ;
goto V_89;
}
V_90 = F_20 ( & V_6 -> V_7 , V_83 ) ;
if ( ! V_90 ) {
F_21 ( V_91
L_13 ,
V_20 ) ;
F_21 ( V_91
L_14 ,
V_20 ) ;
}
F_19 ( L_15 , __FILE__ , V_20 ) ;
return 0 ;
V_89:
F_22 ( V_2 ) ;
return - V_92 ;
}
static int T_3 F_23 ( struct V_5 * V_6 ,
const struct V_93 * V_94 )
{
int V_95 ;
F_14 ( L_5 , __FILE__ , V_20 ) ;
V_95 = F_13 ( V_6 , V_94 -> V_96 ) ;
if ( V_97 == NULL )
V_97 = F_24 ( V_6 ) ;
return V_95 ;
}
static void T_4 F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_14 ( L_16 , __FILE__ , V_20 ) ;
if ( V_90 )
F_26 ( V_90 ) ;
if ( ( V_2 = F_27 ( & V_6 -> V_7 ) ) == NULL )
return;
F_22 ( V_2 ) ;
}
static int T_5 F_28 ( void )
{
int V_98 ;
F_29 () ;
V_98 = F_30 ( & V_99 ) ;
if ( V_98 < 0 )
goto V_100;
if ( V_97 == NULL ) {
const struct V_93 * V_101 = & V_102 [ 0 ] ;
int V_103 = 0 ;
V_104 = 0 ;
while ( V_97 == NULL && V_101 -> V_105 != 0 ) {
V_97 = F_31 ( V_101 -> V_105 ,
V_101 -> V_106 , NULL ) ;
V_103 ++ ;
V_101 = & V_102 [ V_103 ] ;
}
if ( ! V_97 ) {
F_14 ( L_17 ) ;
V_98 = - V_92 ;
goto V_107;
}
V_98 = F_23 ( V_97 , V_102 ) ;
if ( V_98 < 0 ) {
F_14 ( L_18 ) ;
V_98 = - V_92 ;
goto V_107;
}
}
return 0 ;
V_107:
F_32 ( & V_99 ) ;
V_100:
if ( V_97 != NULL )
F_33 ( V_97 ) ;
return V_98 ;
}
static void T_6 F_34 ( void )
{
F_32 ( & V_99 ) ;
if ( ! V_104 )
F_25 ( V_97 ) ;
if ( V_97 )
F_33 ( V_97 ) ;
}
