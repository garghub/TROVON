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
V_8 -> V_20 | V_8 -> V_22 ;
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
V_26 = F_1 ( V_8 , V_39 ) ;
F_3 ( V_8 , V_40 , V_26 ) ;
F_3 ( V_8 , V_41 , V_8 -> V_42 ) ;
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
V_8 -> V_43 = V_30 ;
F_12 ( V_8 -> V_4 , V_8 -> V_43 ) ;
}
static int F_13 ( const void * V_44 , const void * V_45 )
{
return * ( int * ) V_44 - * ( int * ) V_45 ;
}
static void F_14 ( struct V_1 * V_8 ,
T_1 * V_46 , T_1 * V_47 , T_1 * V_48 , T_1 * V_49 )
{
unsigned int V_50 [ 7 ] , V_51 [ 7 ] ;
unsigned int V_11 , V_52 = 0 , V_53 = 0 ;
unsigned int V_54 = V_8 -> V_35 ;
for ( V_11 = 0 ; V_11 < V_54 ; V_11 ++ ) {
V_50 [ V_11 ] = F_1 ( V_8 , V_55 ) ;
V_50 [ V_11 ] &= 0xfff ;
}
* V_48 = F_1 ( V_8 , V_55 ) ;
* V_48 &= 0xfff ;
* V_49 = F_1 ( V_8 , V_55 ) ;
* V_49 &= 0xfff ;
for ( V_11 = 0 ; V_11 < V_54 ; V_11 ++ ) {
V_51 [ V_11 ] = F_1 ( V_8 , V_55 ) ;
V_51 [ V_11 ] &= 0xfff ;
}
if ( V_54 <= 3 ) {
for ( V_11 = 0 ; V_11 < V_54 ; V_11 ++ ) {
V_53 += V_50 [ V_11 ] ;
V_52 += V_51 [ V_11 ] ;
}
V_53 /= V_54 ;
V_52 /= V_54 ;
} else {
F_15 ( V_50 , V_54 , sizeof( unsigned int ) ,
F_13 , NULL ) ;
F_15 ( V_51 , V_54 , sizeof( unsigned int ) ,
F_13 , NULL ) ;
for ( V_11 = 1 ; V_11 < V_54 - 1 ; V_11 ++ ) {
V_53 += V_50 [ V_11 ] ;
V_52 += V_51 [ V_11 ] ;
}
V_53 /= V_54 - 2 ;
V_52 /= V_54 - 2 ;
}
* V_47 = V_53 ;
* V_46 = V_52 ;
}
static T_2 F_16 ( int V_56 , void * V_57 )
{
struct V_1 * V_8 = V_57 ;
struct V_58 * V_58 = V_8 -> V_59 ;
unsigned int V_60 , V_61 , V_62 = 0 ;
unsigned int V_46 = 0 , V_47 = 0 ;
unsigned int V_48 , V_49 , V_63 ;
V_61 = F_1 ( V_8 , V_64 ) ;
if ( V_61 & V_65 ) {
V_8 -> V_66 = true ;
V_62 |= V_65 ;
}
if ( V_61 & V_67 ) {
V_60 = F_1 ( V_8 , V_68 ) ;
if ( V_60 == V_69 ) {
V_8 -> V_66 = false ;
F_17 ( V_58 , V_70 , 0 ) ;
F_18 ( V_58 , V_71 , 0 ) ;
F_19 ( V_58 ) ;
} else {
V_8 -> V_66 = true ;
}
V_62 |= V_67 ;
}
if ( V_61 & V_72 )
V_62 |= V_72 ;
if ( V_61 & V_73 ) {
F_14 ( V_8 , & V_46 , & V_47 , & V_48 , & V_49 ) ;
if ( V_8 -> V_66 && V_48 != 0 && V_49 != 0 ) {
V_63 = V_48 - V_49 ;
V_63 *= V_46 ;
V_63 *= V_8 -> V_74 ;
V_63 /= V_49 ;
V_63 = ( V_63 + 2047 ) >> 12 ;
if ( V_63 <= V_75 ) {
F_18 ( V_58 , V_76 , V_46 ) ;
F_18 ( V_58 , V_77 , V_47 ) ;
F_18 ( V_58 , V_71 , V_63 ) ;
F_17 ( V_58 , V_70 , 1 ) ;
F_19 ( V_58 ) ;
}
}
V_62 |= V_73 ;
}
if ( V_62 ) {
F_3 ( V_8 , V_78 , V_62 ) ;
if ( V_61 & V_72 )
F_12 ( V_8 -> V_4 ,
V_8 -> V_43 ) ;
return V_79 ;
}
return V_80 ;
}
static int F_20 ( struct V_81 * V_82 ,
struct V_1 * V_8 )
{
struct V_83 * V_84 = V_82 -> V_57 . V_85 ;
int V_86 ;
if ( ! V_84 )
return - V_14 ;
V_86 = F_21 ( V_84 , L_1 , & V_8 -> V_33 ) ;
if ( V_86 < 0 )
return V_86 ;
switch ( V_8 -> V_33 ) {
case 4 :
case 5 :
case 8 :
break;
default:
return - V_14 ;
}
V_86 = F_21 ( V_84 , L_2 ,
& V_8 -> V_74 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_21 ( V_84 , L_3 ,
& V_8 -> V_35 ) ;
if ( V_86 < 0 ) {
F_22 ( & V_82 -> V_57 , L_4 ) ;
V_86 = F_21 ( V_84 , L_5 ,
& V_8 -> V_35 ) ;
}
if ( V_86 < 0 )
return V_86 ;
if ( V_8 -> V_35 <= 0 ) {
F_22 ( & V_82 -> V_57 ,
L_6 ) ;
V_8 -> V_35 = 5 ;
}
V_86 = F_21 ( V_84 , L_7 ,
& V_8 -> V_42 ) ;
if ( V_86 < 0 ) {
V_8 -> V_42 = V_87 ;
F_22 ( & V_82 -> V_57 , L_8 ) ;
}
return F_23 ( V_84 , L_9 ,
V_8 -> V_13 , F_7 ( V_8 -> V_13 ) ) ;
}
static int F_24 ( struct V_81 * V_82 )
{
struct V_1 * V_8 ;
struct V_58 * V_58 ;
struct V_88 * V_89 = F_25 ( V_82 ) ;
int V_86 ;
V_8 = F_26 ( sizeof( * V_8 ) , V_90 ) ;
V_58 = F_27 () ;
if ( ! V_8 || ! V_58 ) {
F_28 ( & V_82 -> V_57 , L_10 ) ;
V_86 = - V_91 ;
goto V_92;
}
V_89 -> V_6 = V_8 ;
V_8 -> V_4 = V_89 ;
V_8 -> V_59 = V_58 ;
V_8 -> V_56 = V_89 -> V_56 ;
V_86 = F_20 ( V_82 , V_8 ) ;
if ( V_86 ) {
F_28 ( & V_82 -> V_57 , L_11 ) ;
goto V_92;
}
V_86 = F_29 ( V_8 -> V_56 , F_16 ,
V_93 , V_82 -> V_57 . V_94 -> V_95 , V_8 ) ;
if ( V_86 ) {
F_28 ( & V_82 -> V_57 , L_12 ) ;
goto V_92;
}
F_3 ( V_8 , V_96 , V_73 ) ;
F_3 ( V_8 , V_96 , V_72 ) ;
V_86 = F_5 ( V_8 ) ;
if ( V_86 ) {
F_28 ( & V_82 -> V_57 , L_13 ) ;
goto V_97;
}
F_8 ( V_8 ) ;
F_3 ( V_8 , V_98 ,
V_8 -> V_35 * 2 + 2 - 1 ) ;
V_58 -> V_95 = L_14 ;
V_58 -> V_57 . V_99 = & V_82 -> V_57 ;
V_58 -> V_100 [ 0 ] = F_30 ( V_101 ) | F_30 ( V_102 ) ;
V_58 -> V_103 [ F_31 ( V_70 ) ] = F_30 ( V_70 ) ;
F_32 ( V_58 , V_76 , 0 , V_75 , 0 , 0 ) ;
F_32 ( V_58 , V_77 , 0 , V_75 , 0 , 0 ) ;
F_32 ( V_58 , V_71 , 0 , V_75 , 0 , 0 ) ;
V_86 = F_33 ( V_58 ) ;
if ( V_86 )
goto V_97;
F_34 ( V_82 , V_8 ) ;
return 0 ;
V_97:
F_35 ( V_8 -> V_56 , V_8 ) ;
V_92:
F_36 ( V_58 ) ;
F_37 ( V_8 ) ;
return V_86 ;
}
static int F_38 ( struct V_81 * V_82 )
{
struct V_1 * V_8 = F_39 ( V_82 ) ;
T_1 V_104 ;
F_35 ( V_8 -> V_56 , V_8 ) ;
V_104 = 2 * V_8 -> V_35 + 2 ;
V_104 = ( 1 << V_104 ) - 1 ;
F_40 ( V_8 -> V_4 , V_104 ) ;
F_41 ( V_8 -> V_59 ) ;
F_37 ( V_8 ) ;
return 0 ;
}
static int T_3 F_42 ( struct V_105 * V_57 )
{
struct V_1 * V_8 = F_43 ( V_57 ) ;
struct V_88 * V_89 ;
unsigned int V_106 ;
V_89 = F_25 ( F_44 ( V_57 ) ) ;
if ( F_45 ( V_89 -> V_57 ) ) {
V_106 = F_1 ( V_8 , V_96 ) ;
F_3 ( V_8 , V_96 ,
( V_106 | V_65 ) ) ;
F_3 ( V_8 , V_107 , V_108 ) ;
}
return 0 ;
}
static int T_3 F_46 ( struct V_105 * V_57 )
{
struct V_1 * V_8 = F_43 ( V_57 ) ;
struct V_88 * V_89 ;
V_89 = F_25 ( F_44 ( V_57 ) ) ;
if ( F_45 ( V_89 -> V_57 ) ) {
F_3 ( V_8 , V_107 ,
0x00 ) ;
F_3 ( V_8 , V_109 , V_65 ) ;
}
F_8 ( V_8 ) ;
F_3 ( V_8 , V_98 ,
V_8 -> V_35 * 2 + 2 - 1 ) ;
return 0 ;
}
