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
F_9 ( & V_2 -> V_27 ) ;
while ( V_16 > 0 ) {
V_26 = ( V_16 < 0x60 ) ? V_16 : 0x60 ;
V_16 -= V_26 ;
V_24 = F_6 ( V_2 , V_26 ) ;
if ( V_24 )
break;
V_26 <<= 2 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 += 4 )
F_2 ( * V_23 ++ , V_28 + V_25 ) ;
( void ) F_3 ( V_28 + V_25 - 4 ) ;
}
F_10 ( & V_2 -> V_27 ) ;
return V_24 ;
}
static T_2 F_11 ( int V_29 , int V_30 )
{
if ( V_29 < 0 )
return ( V_30 < 0 ) ? V_31 :
V_32 ;
else
return ( V_30 < 0 ) ? V_33 :
V_34 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_35 , T_1 V_36 ,
T_1 V_37 , T_1 V_38 ,
T_1 V_39 , T_1 V_40 ,
T_3 V_41 , T_3 V_42 ,
T_3 V_43 , T_3 V_44 ,
T_3 V_45 , T_3 V_46 )
{
T_1 V_47 ;
T_1 V_48 [ 10 ] ;
T_1 * V_49 ;
T_1 V_50 ;
V_49 = V_48 ;
V_50 =
F_11 ( V_41 - V_43 , V_42 - V_44 ) ;
if ( V_50 == V_31 ||
V_50 == V_32 ) {
V_41 += V_45 - 1 ;
V_43 += V_45 - 1 ;
}
if ( V_50 == V_31 ||
V_50 == V_33 ) {
V_42 += V_46 - 1 ;
V_44 += V_46 - 1 ;
}
V_47 =
V_51 |
V_52 |
V_53 |
V_54 |
V_55 | V_56 | V_50 ;
* V_49 ++ = V_57 ;
* V_49 ++ =
V_58 | V_40 | ( V_39 <<
V_59 ) ;
* V_49 ++ = V_38 ;
* V_49 ++ =
V_60 | V_37 | ( V_36 <<
V_61 ) ;
* V_49 ++ = V_35 ;
* V_49 ++ =
V_62 | ( V_41 << V_63 ) |
( V_42 << V_64 ) ;
* V_49 ++ = V_47 ;
* V_49 ++ =
( V_43 << V_65 ) | ( V_44 <<
V_66 ) ;
* V_49 ++ =
( V_45 << V_67 ) | ( V_46 <<
V_68 ) ;
* V_49 ++ = V_69 ;
return F_8 ( V_2 , V_48 , V_49 - V_48 ) ;
}
static void F_13 ( struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
struct V_74 * V_75 = V_71 -> V_76 ;
struct V_77 * V_78 = & V_75 -> V_79 ;
struct V_80 * V_81 = V_78 -> V_82 . V_81 ;
struct V_83 * V_84 = V_75 -> V_85 . V_84 ;
struct V_1 * V_2 = V_81 -> V_86 ;
T_1 V_87 ;
T_1 V_88 ;
T_1 V_37 ;
T_1 V_40 ;
if ( ! V_84 )
return;
V_87 = V_78 -> V_13 -> V_87 ;
V_88 = V_84 -> V_89 ;
switch ( V_84 -> V_90 ) {
case 8 :
V_37 = V_91 ;
V_40 = V_92 ;
break;
case 15 :
V_37 = V_93 ;
V_40 = V_94 ;
break;
case 16 :
V_37 = V_95 ;
V_40 = V_96 ;
break;
case 24 :
case 32 :
V_37 = V_97 ;
V_40 = V_98 ;
break;
default:
F_14 ( V_71 , V_73 ) ;
return;
}
if ( ! F_15 ( V_81 , false ) ) {
F_14 ( V_71 , V_73 ) ;
return;
}
F_12 ( V_2 ,
V_87 , V_88 , V_37 ,
V_87 , V_88 , V_40 ,
V_73 -> V_99 , V_73 -> V_100 , V_73 -> V_101 , V_73 -> V_102 , V_73 -> V_103 , V_73 -> V_104 ) ;
F_16 ( V_81 ) ;
}
void F_17 ( struct V_70 * V_71 ,
const struct V_72 * V_105 )
{
if ( F_18 ( V_71 -> V_106 != V_107 ) )
return;
if ( V_105 -> V_103 == 8 || V_105 -> V_104 == 8 ||
( V_71 -> V_108 & V_109 ) )
return F_14 ( V_71 , V_105 ) ;
F_13 ( V_71 , V_105 ) ;
}
int F_19 ( struct V_70 * V_71 )
{
struct V_74 * V_75 = V_71 -> V_76 ;
struct V_77 * V_78 = & V_75 -> V_79 ;
struct V_80 * V_81 = V_78 -> V_82 . V_81 ;
struct V_1 * V_2 = V_81 -> V_86 ;
unsigned long V_110 = V_20 + V_111 ;
int V_112 = 0 ;
F_9 ( & V_2 -> V_27 ) ;
if ( ( F_3 ( V_18 ) == V_113 ) &&
( ( F_3 ( V_114 ) & V_115 ) == 0 ) )
goto V_116;
do {
V_112 = ( F_3 ( V_18 ) != V_113 ) ;
F_20 () ;
} while ( V_112 && ! F_21 ( V_20 , V_110 ) );
if ( V_112 )
V_112 = ( F_3 ( V_18 ) != V_113 ) ;
if ( V_112 )
goto V_116;
do {
V_112 = ( ( F_3 ( V_114 ) &
V_115 ) != 0 ) ;
F_20 () ;
} while ( V_112 && ! F_21 ( V_20 , V_110 ) );
if ( V_112 )
V_112 = ( ( F_3 ( V_114 ) &
V_115 ) != 0 ) ;
V_116:
F_10 ( & V_2 -> V_27 ) ;
return ( V_112 ) ? - V_117 : 0 ;
}
int F_22 ( struct V_80 * V_81 , void * V_118 , struct V_119 * V_120 )
{
struct V_1 * V_2 = V_81 -> V_86 ;
struct V_121 * V_122 = V_118 ;
T_2 * V_123 = & V_122 -> V_124 [ 0 ] ;
int V_25 ;
struct V_125 * V_126 ;
struct V_127 * V_13 ;
int V_128 = - V_129 ;
if ( ! V_2 -> V_130 -> V_131 )
return - V_132 ;
if ( V_122 -> V_16 > V_133 )
return - V_129 ;
V_126 = F_23 ( V_81 , V_120 , V_122 -> V_134 ) ;
if ( V_126 == NULL )
return - V_135 ;
V_13 = F_24 ( V_126 , struct V_127 , V_136 ) ;
if ( F_25 ( V_13 ) < 0 )
goto V_137;
for ( V_25 = 0 ; V_25 < V_122 -> V_16 ; V_25 ++ , V_123 ++ ) {
T_2 V_138 = * V_123 & 0xF0000000 ;
if ( V_138 == V_60 ||
V_138 == V_58 ||
V_138 == V_139 ||
V_138 == V_140 ) {
V_25 ++ ;
V_123 ++ ;
if ( V_25 == V_122 -> V_16 )
goto V_141;
if ( * V_123 )
goto V_141;
* V_123 = V_13 -> V_87 ;
continue;
}
}
F_8 ( V_2 , V_122 -> V_124 , V_122 -> V_16 ) ;
V_128 = 0 ;
V_141:
F_26 ( V_13 ) ;
V_137:
F_27 ( V_126 ) ;
return V_128 ;
}
