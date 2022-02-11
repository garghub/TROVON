static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_6 , unsigned int V_3 ,
unsigned int V_7 )
{
F_4 ( V_7 , V_6 -> V_4 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_8 )
{
T_1 V_9 [ 4 ] ;
T_1 V_10 [ 4 ] ;
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_9 [ V_11 ] = ( V_8 -> V_13 [ V_11 ] & 0xF0 ) >> 4 ;
V_10 [ V_11 ] = V_8 -> V_13 [ V_11 ] & 0x0F ;
if ( F_6 ( V_9 [ V_11 ] > 7 ) )
return - V_14 ;
if ( F_6 ( V_10 [ V_11 ] > F_7 ( V_15 ) ) )
return - V_14 ;
}
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
int V_16 ;
int V_17 ;
V_16 = V_9 [ V_11 ] ;
V_17 = V_10 [ V_11 ] ;
V_12 = V_15 [ V_17 ] ;
if ( V_12 == 0 )
return - V_14 ;
switch ( V_17 ) {
case 0 :
V_8 -> V_18 = V_12 ;
V_8 -> V_19 = V_16 ;
break;
case 1 :
V_8 -> V_20 = V_12 ;
V_8 -> V_21 = V_16 ;
break;
case 2 :
V_8 -> V_22 = V_12 ;
V_8 -> V_23 = V_16 ;
break;
case 3 :
V_8 -> V_24 = V_12 ;
V_8 -> V_25 = V_16 ;
break;
}
}
return 0 ;
}
static void F_8 ( struct V_1 * V_8 )
{
unsigned int V_26 ;
int V_11 ;
int V_27 , V_28 , V_29 ;
T_1 V_30 ;
V_26 = V_31 |
V_32 | V_8 -> V_18 ;
switch ( V_8 -> V_33 ) {
case 4 :
V_26 |= F_9 ( V_8 -> V_23 ) | V_8 -> V_20 ;
break;
case 5 :
V_26 |= V_8 -> V_24 |
V_34 | V_8 -> V_20 |
V_8 -> V_22 ;
break;
case 8 :
V_26 |= F_9 ( V_8 -> V_23 ) | V_8 -> V_20 ;
break;
}
V_29 = V_8 -> V_35 * 2 + 2 ;
V_28 = V_36 - V_29 ;
V_27 = V_28 + V_29 ;
for ( V_11 = V_27 - V_8 -> V_35 ; V_11 < V_27 ; V_11 ++ ) {
F_3 ( V_8 , F_10 ( V_11 ) , V_26 ) ;
F_3 ( V_8 , F_11 ( V_11 ) , V_37 ) ;
}
V_26 = 0 ;
V_26 = V_31 |
V_32 | V_8 -> V_24 |
V_38 ;
switch ( V_8 -> V_33 ) {
case 4 :
V_26 |= V_8 -> V_22 | F_9 ( V_8 -> V_19 ) ;
break;
case 5 :
V_26 |= V_8 -> V_18 | V_34 |
V_39 | V_40 ;
break;
case 8 :
V_26 |= V_8 -> V_22 | F_9 ( V_8 -> V_19 ) ;
break;
}
V_27 = V_28 + V_8 -> V_35 ;
for ( V_11 = V_28 ; V_11 < V_27 ; V_11 ++ ) {
F_3 ( V_8 , F_10 ( V_11 ) , V_26 ) ;
F_3 ( V_8 , F_11 ( V_11 ) , V_37 ) ;
}
V_26 = F_1 ( V_8 , V_41 ) ;
F_3 ( V_8 , V_42 , V_26 ) ;
F_3 ( V_8 , V_43 , V_8 -> V_44 ) ;
V_26 = V_31 |
V_32 | V_8 -> V_22 |
V_8 -> V_20 | V_38 |
F_9 ( V_8 -> V_19 ) ;
F_3 ( V_8 , F_10 ( V_27 ) , V_26 ) ;
F_3 ( V_8 , F_11 ( V_27 ) ,
V_37 ) ;
V_27 ++ ;
V_26 |= F_9 ( V_8 -> V_25 ) ;
F_3 ( V_8 , F_10 ( V_27 ) , V_26 ) ;
F_3 ( V_8 , F_11 ( V_27 ) ,
V_37 ) ;
V_30 = 1 ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ )
V_30 |= 1 << ( V_28 + V_11 + 1 ) ;
V_8 -> V_45 = V_30 ;
F_12 ( V_8 -> V_4 , V_8 -> V_45 ) ;
}
static int F_13 ( const void * V_46 , const void * V_47 )
{
return * ( int * ) V_46 - * ( int * ) V_47 ;
}
static void F_14 ( struct V_1 * V_8 ,
T_1 * V_48 , T_1 * V_49 , T_1 * V_50 , T_1 * V_51 )
{
unsigned int V_52 [ 7 ] , V_53 [ 7 ] ;
unsigned int V_11 , V_54 = 0 , V_55 = 0 ;
unsigned int V_56 = V_8 -> V_35 ;
for ( V_11 = 0 ; V_11 < V_56 ; V_11 ++ ) {
V_52 [ V_11 ] = F_1 ( V_8 , V_57 ) ;
V_52 [ V_11 ] &= 0xfff ;
}
* V_50 = F_1 ( V_8 , V_57 ) ;
* V_50 &= 0xfff ;
* V_51 = F_1 ( V_8 , V_57 ) ;
* V_51 &= 0xfff ;
for ( V_11 = 0 ; V_11 < V_56 ; V_11 ++ ) {
V_53 [ V_11 ] = F_1 ( V_8 , V_57 ) ;
V_53 [ V_11 ] &= 0xfff ;
}
if ( V_56 <= 3 ) {
for ( V_11 = 0 ; V_11 < V_56 ; V_11 ++ ) {
V_55 += V_52 [ V_11 ] ;
V_54 += V_53 [ V_11 ] ;
}
V_55 /= V_56 ;
V_54 /= V_56 ;
} else {
F_15 ( V_52 , V_56 , sizeof( unsigned int ) ,
F_13 , NULL ) ;
F_15 ( V_53 , V_56 , sizeof( unsigned int ) ,
F_13 , NULL ) ;
for ( V_11 = 1 ; V_11 < V_56 - 1 ; V_11 ++ ) {
V_55 += V_52 [ V_11 ] ;
V_54 += V_53 [ V_11 ] ;
}
V_55 /= V_56 - 2 ;
V_54 /= V_56 - 2 ;
}
* V_49 = V_55 ;
* V_48 = V_54 ;
}
static T_2 F_16 ( int V_58 , void * V_59 )
{
struct V_1 * V_8 = V_59 ;
struct V_60 * V_60 = V_8 -> V_61 ;
unsigned int V_62 , V_63 , V_64 = 0 ;
unsigned int V_48 = 0 , V_49 = 0 ;
unsigned int V_50 , V_51 , V_65 ;
V_63 = F_1 ( V_8 , V_66 ) ;
if ( V_63 & V_67 ) {
V_8 -> V_68 = true ;
V_64 |= V_67 ;
}
if ( V_63 & V_69 ) {
V_62 = F_1 ( V_8 , V_70 ) ;
if ( V_62 == V_71 ) {
V_8 -> V_68 = false ;
F_17 ( V_60 , V_72 , 0 ) ;
F_18 ( V_60 , V_73 , 0 ) ;
F_19 ( V_60 ) ;
} else {
V_8 -> V_68 = true ;
}
V_64 |= V_69 ;
}
if ( V_63 & V_74 )
V_64 |= V_74 ;
if ( V_63 & V_75 ) {
F_14 ( V_8 , & V_48 , & V_49 , & V_50 , & V_51 ) ;
if ( V_8 -> V_68 && V_50 != 0 && V_51 != 0 ) {
V_65 = V_50 - V_51 ;
V_65 *= V_48 ;
V_65 *= V_8 -> V_76 ;
V_65 /= V_51 ;
V_65 = ( V_65 + 2047 ) >> 12 ;
if ( V_65 <= V_77 ) {
F_18 ( V_60 , V_78 , V_48 ) ;
F_18 ( V_60 , V_79 , V_49 ) ;
F_18 ( V_60 , V_73 , V_65 ) ;
F_17 ( V_60 , V_72 , 1 ) ;
F_19 ( V_60 ) ;
}
}
V_64 |= V_75 ;
}
if ( V_64 ) {
F_3 ( V_8 , V_80 , V_64 ) ;
if ( V_63 & V_74 )
F_12 ( V_8 -> V_4 ,
V_8 -> V_45 ) ;
return V_81 ;
}
return V_82 ;
}
static int F_20 ( struct V_83 * V_84 ,
struct V_1 * V_8 )
{
struct V_85 * V_86 = V_84 -> V_59 . V_87 ;
int V_88 ;
if ( ! V_86 )
return - V_14 ;
V_88 = F_21 ( V_86 , L_1 , & V_8 -> V_33 ) ;
if ( V_88 < 0 )
return V_88 ;
switch ( V_8 -> V_33 ) {
case 4 :
case 5 :
case 8 :
break;
default:
return - V_14 ;
}
V_88 = F_21 ( V_86 , L_2 ,
& V_8 -> V_76 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = F_21 ( V_86 , L_3 ,
& V_8 -> V_35 ) ;
if ( V_88 < 0 ) {
F_22 ( & V_84 -> V_59 , L_4 ) ;
V_88 = F_21 ( V_86 , L_5 ,
& V_8 -> V_35 ) ;
}
if ( V_88 < 0 )
return V_88 ;
if ( V_8 -> V_35 <= 0 ) {
F_22 ( & V_84 -> V_59 ,
L_6 ) ;
V_8 -> V_35 = 5 ;
}
V_88 = F_21 ( V_86 , L_7 ,
& V_8 -> V_44 ) ;
if ( V_88 < 0 ) {
V_8 -> V_44 = V_89 ;
F_22 ( & V_84 -> V_59 , L_8 ) ;
}
return F_23 ( V_86 , L_9 ,
V_8 -> V_13 , F_7 ( V_8 -> V_13 ) ) ;
}
static int F_24 ( struct V_83 * V_84 )
{
struct V_1 * V_8 ;
struct V_60 * V_60 ;
struct V_90 * V_91 = F_25 ( V_84 ) ;
int V_88 ;
V_8 = F_26 ( sizeof( * V_8 ) , V_92 ) ;
V_60 = F_27 () ;
if ( ! V_8 || ! V_60 ) {
F_28 ( & V_84 -> V_59 , L_10 ) ;
V_88 = - V_93 ;
goto V_94;
}
V_91 -> V_6 = V_8 ;
V_8 -> V_4 = V_91 ;
V_8 -> V_61 = V_60 ;
V_8 -> V_58 = V_91 -> V_58 ;
V_88 = F_20 ( V_84 , V_8 ) ;
if ( V_88 ) {
F_28 ( & V_84 -> V_59 , L_11 ) ;
goto V_94;
}
V_88 = F_29 ( V_8 -> V_58 , F_16 ,
V_95 , V_84 -> V_59 . V_96 -> V_97 , V_8 ) ;
if ( V_88 ) {
F_28 ( & V_84 -> V_59 , L_12 ) ;
goto V_94;
}
F_3 ( V_8 , V_98 , V_75 ) ;
F_3 ( V_8 , V_98 , V_74 ) ;
V_88 = F_5 ( V_8 ) ;
if ( V_88 ) {
F_28 ( & V_84 -> V_59 , L_13 ) ;
goto V_99;
}
F_8 ( V_8 ) ;
F_3 ( V_8 , V_100 ,
V_8 -> V_35 * 2 + 2 - 1 ) ;
V_60 -> V_97 = L_14 ;
V_60 -> V_59 . V_101 = & V_84 -> V_59 ;
V_60 -> V_102 [ 0 ] = F_30 ( V_103 ) | F_30 ( V_104 ) ;
V_60 -> V_105 [ F_31 ( V_72 ) ] = F_30 ( V_72 ) ;
F_32 ( V_60 , V_78 , 0 , V_77 , 0 , 0 ) ;
F_32 ( V_60 , V_79 , 0 , V_77 , 0 , 0 ) ;
F_32 ( V_60 , V_73 , 0 , V_77 , 0 , 0 ) ;
V_88 = F_33 ( V_60 ) ;
if ( V_88 )
goto V_99;
F_34 ( V_84 , V_8 ) ;
return 0 ;
V_99:
F_35 ( V_8 -> V_58 , V_8 ) ;
V_94:
F_36 ( V_60 ) ;
F_37 ( V_8 ) ;
return V_88 ;
}
static int F_38 ( struct V_83 * V_84 )
{
struct V_1 * V_8 = F_39 ( V_84 ) ;
T_1 V_106 ;
F_35 ( V_8 -> V_58 , V_8 ) ;
V_106 = 2 * V_8 -> V_35 + 2 ;
V_106 = ( 1 << V_106 ) - 1 ;
F_40 ( V_8 -> V_4 , V_106 ) ;
F_41 ( V_8 -> V_61 ) ;
F_37 ( V_8 ) ;
return 0 ;
}
static int T_3 F_42 ( struct V_107 * V_59 )
{
struct V_1 * V_8 = F_43 ( V_59 ) ;
struct V_90 * V_91 ;
unsigned int V_108 ;
V_91 = F_25 ( F_44 ( V_59 ) ) ;
if ( F_45 ( V_91 -> V_59 ) ) {
V_108 = F_1 ( V_8 , V_98 ) ;
F_3 ( V_8 , V_98 ,
( V_108 | V_67 ) ) ;
F_3 ( V_8 , V_109 , V_110 ) ;
}
return 0 ;
}
static int T_3 F_46 ( struct V_107 * V_59 )
{
struct V_1 * V_8 = F_43 ( V_59 ) ;
struct V_90 * V_91 ;
V_91 = F_25 ( F_44 ( V_59 ) ) ;
if ( F_45 ( V_91 -> V_59 ) ) {
F_3 ( V_8 , V_109 ,
0x00 ) ;
F_3 ( V_8 , V_111 , V_67 ) ;
}
F_8 ( V_8 ) ;
F_3 ( V_8 , V_100 ,
V_8 -> V_35 * 2 + 2 - 1 ) ;
return 0 ;
}
