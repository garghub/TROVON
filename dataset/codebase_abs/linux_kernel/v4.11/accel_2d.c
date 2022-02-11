void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 | V_4 |
V_5 | V_6 |
V_7 | V_8 |
V_9 , V_10 ) ;
F_3 ( V_10 ) ;
F_4 ( 1 ) ;
F_2 ( 0 , V_10 ) ;
F_5 () ;
F_2 ( F_3 ( V_11 ) | V_12 ,
V_11 ) ;
F_5 () ;
( void ) F_3 ( V_11 ) ;
F_4 ( 1 ) ;
F_2 ( F_3 ( V_11 ) & ~ V_12 ,
V_11 ) ;
( void ) F_3 ( V_11 ) ;
F_2 ( V_2 -> V_13 . V_14 , V_15 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_16 )
{
T_1 V_17 = F_3 ( V_18 ) ;
unsigned long V_19 = V_20 + V_21 ;
while ( V_17 < V_16 ) {
V_17 = F_3 ( V_18 ) ;
if ( F_7 ( V_20 , V_19 ) ) {
F_1 ( V_2 ) ;
return - V_22 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_23 ,
unsigned V_16 )
{
int V_24 = 0 ;
int V_25 ;
unsigned V_26 ;
unsigned long V_27 ;
F_9 ( & V_2 -> V_28 , V_27 ) ;
while ( V_16 > 0 ) {
V_26 = ( V_16 < 0x60 ) ? V_16 : 0x60 ;
V_16 -= V_26 ;
V_24 = F_6 ( V_2 , V_26 ) ;
if ( V_24 )
break;
V_26 <<= 2 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 += 4 )
F_2 ( * V_23 ++ , V_29 + V_25 ) ;
( void ) F_3 ( V_29 + V_25 - 4 ) ;
}
F_10 ( & V_2 -> V_28 , V_27 ) ;
return V_24 ;
}
static T_2 F_11 ( int V_30 , int V_31 )
{
if ( V_30 < 0 )
return ( V_31 < 0 ) ? V_32 :
V_33 ;
else
return ( V_31 < 0 ) ? V_34 :
V_35 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_36 , T_1 V_37 ,
T_1 V_38 , T_1 V_39 ,
T_1 V_40 , T_1 V_41 ,
T_3 V_42 , T_3 V_43 ,
T_3 V_44 , T_3 V_45 ,
T_3 V_46 , T_3 V_47 )
{
T_1 V_48 ;
T_1 V_49 [ 10 ] ;
T_1 * V_50 ;
T_1 V_51 ;
V_50 = V_49 ;
V_51 =
F_11 ( V_42 - V_44 , V_43 - V_45 ) ;
if ( V_51 == V_32 ||
V_51 == V_33 ) {
V_42 += V_46 - 1 ;
V_44 += V_46 - 1 ;
}
if ( V_51 == V_32 ||
V_51 == V_34 ) {
V_43 += V_47 - 1 ;
V_45 += V_47 - 1 ;
}
V_48 =
V_52 |
V_53 |
V_54 |
V_55 |
V_56 | V_57 | V_51 ;
* V_50 ++ = V_58 ;
* V_50 ++ =
V_59 | V_41 | ( V_40 <<
V_60 ) ;
* V_50 ++ = V_39 ;
* V_50 ++ =
V_61 | V_38 | ( V_37 <<
V_62 ) ;
* V_50 ++ = V_36 ;
* V_50 ++ =
V_63 | ( V_42 << V_64 ) |
( V_43 << V_65 ) ;
* V_50 ++ = V_48 ;
* V_50 ++ =
( V_44 << V_66 ) | ( V_45 <<
V_67 ) ;
* V_50 ++ =
( V_46 << V_68 ) | ( V_47 <<
V_69 ) ;
* V_50 ++ = V_70 ;
return F_8 ( V_2 , V_49 , V_50 - V_49 ) ;
}
static void F_13 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_75 * V_76 = V_72 -> V_77 ;
struct V_78 * V_79 = & V_76 -> V_80 ;
struct V_81 * V_82 = V_79 -> V_83 . V_82 ;
struct V_84 * V_85 = V_76 -> V_86 . V_85 ;
struct V_1 * V_2 = V_82 -> V_87 ;
T_1 V_88 ;
T_1 V_89 ;
T_1 V_38 ;
T_1 V_41 ;
if ( ! V_85 )
return;
V_88 = V_79 -> V_13 -> V_88 ;
V_89 = V_85 -> V_90 [ 0 ] ;
switch ( V_85 -> V_91 -> V_92 ) {
case 8 :
V_38 = V_93 ;
V_41 = V_94 ;
break;
case 15 :
V_38 = V_95 ;
V_41 = V_96 ;
break;
case 16 :
V_38 = V_97 ;
V_41 = V_98 ;
break;
case 24 :
case 32 :
V_38 = V_99 ;
V_41 = V_100 ;
break;
default:
F_14 ( V_72 , V_74 ) ;
return;
}
if ( ! F_15 ( V_82 , false ) ) {
F_14 ( V_72 , V_74 ) ;
return;
}
F_12 ( V_2 ,
V_88 , V_89 , V_38 ,
V_88 , V_89 , V_41 ,
V_74 -> V_101 , V_74 -> V_102 , V_74 -> V_103 , V_74 -> V_104 , V_74 -> V_105 , V_74 -> V_106 ) ;
F_16 ( V_82 ) ;
}
void F_17 ( struct V_71 * V_72 ,
const struct V_73 * V_107 )
{
if ( F_18 ( V_72 -> V_108 != V_109 ) )
return;
if ( V_107 -> V_105 == 8 || V_107 -> V_106 == 8 ||
( V_72 -> V_27 & V_110 ) )
return F_14 ( V_72 , V_107 ) ;
F_13 ( V_72 , V_107 ) ;
}
int F_19 ( struct V_71 * V_72 )
{
struct V_75 * V_76 = V_72 -> V_77 ;
struct V_78 * V_79 = & V_76 -> V_80 ;
struct V_81 * V_82 = V_79 -> V_83 . V_82 ;
struct V_1 * V_2 = V_82 -> V_87 ;
unsigned long V_111 = V_20 + V_21 ;
int V_112 = 0 ;
unsigned long V_27 ;
F_9 ( & V_2 -> V_28 , V_27 ) ;
if ( ( F_3 ( V_18 ) == V_113 ) &&
( ( F_3 ( V_114 ) & V_115 ) == 0 ) )
goto V_116;
do {
V_112 = ( F_3 ( V_18 ) != V_113 ) ;
F_20 () ;
} while ( V_112 && ! F_21 ( V_20 , V_111 ) );
if ( V_112 )
V_112 = ( F_3 ( V_18 ) != V_113 ) ;
if ( V_112 )
goto V_116;
do {
V_112 = ( ( F_3 ( V_114 ) &
V_115 ) != 0 ) ;
F_20 () ;
} while ( V_112 && ! F_21 ( V_20 , V_111 ) );
if ( V_112 )
V_112 = ( ( F_3 ( V_114 ) &
V_115 ) != 0 ) ;
V_116:
F_10 ( & V_2 -> V_28 , V_27 ) ;
return ( V_112 ) ? - V_117 : 0 ;
}
