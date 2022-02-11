static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
while ( F_12 ( V_2 ) != 0 ) {
V_3 ++ ;
if ( V_4 < V_3 ) {
F_13 ( V_2 -> V_5 , L_1 ) ;
return - V_6 ;
}
F_14 ( 10 , 11 ) ;
}
return 0 ;
}
static unsigned char F_15 ( unsigned char * V_7 )
{
int V_8 ;
unsigned char V_9 = 0 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
V_9 = V_9 + V_7 [ V_8 ] ;
return V_9 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned char V_11 [ V_10 * 2 ] ;
unsigned int V_12 = 0 ;
unsigned char V_9 ;
unsigned char V_13 ;
int V_14 ;
V_14 = F_17 ( V_2 , V_15 ,
V_16 ,
& V_12 ) ;
if ( V_14 )
return V_14 ;
if ( V_12 > 0 ) {
F_18 ( V_2 -> V_5 , L_2 ) ;
V_14 = F_19 ( V_2 , V_15 ,
V_17 ,
V_10 ,
& V_11 [ V_17 ] ) ;
if ( V_14 != 0 ) {
F_13 ( V_2 -> V_5 , L_3 ) ;
return - V_18 ;
}
V_9 = F_15 ( V_11 ) ;
if ( V_9 != 0 ) {
F_13 ( V_2 -> V_5 , L_4 ) ;
return - V_18 ;
}
V_14 = F_19 ( V_2 ,
V_15 ,
V_10 ,
V_10 ,
& V_11 [ V_10 ] ) ;
if ( V_14 != 0 ) {
F_13 ( V_2 -> V_5 , L_3 ) ;
return - V_18 ;
}
V_9 = F_15 ( & V_11 [ V_10 ] ) ;
if ( V_9 != 0 ) {
F_13 ( V_2 -> V_5 , L_4 ) ;
return - V_18 ;
}
F_20 ( V_2 , V_19 ,
& V_13 ) ;
if ( V_13 & V_20 ) {
F_21 ( V_2 ,
V_21 ,
V_11 [ V_10 + V_22 ] ) ;
F_21 ( V_2 ,
V_23 ,
V_24 ) ;
}
} else {
F_22 ( V_2 -> V_5 , L_5 ) ;
V_14 = F_19 ( V_2 ,
V_15 ,
V_17 ,
V_10 ,
& V_11 [ V_17 ] ) ;
if ( V_14 != 0 ) {
F_13 ( V_2 -> V_5 , L_3 ) ;
return - V_18 ;
}
V_9 = F_15 ( V_11 ) ;
if ( V_9 != 0 ) {
F_13 ( V_2 -> V_5 , L_4 ) ;
return - V_18 ;
}
F_20 ( V_2 ,
V_19 ,
& V_13 ) ;
if ( V_13 & V_20 ) {
F_21 ( V_2 ,
V_21 ,
V_11 [ V_22 ] ) ;
F_21 ( V_2 ,
V_23 ,
V_24 ) ;
}
}
F_13 ( V_2 -> V_5 , L_6 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_25 [ 12 ] ;
int V_8 ;
int V_14 ;
V_14 = F_24 ( V_2 , V_26 ,
12 , V_25 ) ;
if ( V_14 )
return V_14 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
V_14 = F_16 ( V_2 ) ;
if ( ! V_14 )
break;
}
return V_14 ;
}
static void F_25 ( struct V_1 * V_2 ,
bool V_27 )
{
T_1 V_28 ;
F_20 ( V_2 , V_29 , & V_28 ) ;
if ( V_27 )
F_21 ( V_2 , V_29 ,
V_30 |
F_26 ( V_28 ) ) ;
else
F_21 ( V_2 , V_29 ,
F_26 ( V_28 ) ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 V_28 ;
int V_14 ;
F_20 ( V_2 , V_31 , & V_28 ) ;
V_14 = F_28 ( V_28 ) ;
return V_14 ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_28 ;
V_28 = F_27 ( V_2 ) ;
F_25 ( V_2 , V_28 ) ;
F_30 ( V_2 , V_28 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 , V_32 ) ;
F_21 ( V_2 ,
V_33 ,
V_34 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
int V_35 , int V_36 )
{
switch ( V_36 ) {
case 0 :
F_34 ( V_2 , V_35 ) ;
break;
case 1 :
F_35 ( V_2 , V_35 ) ;
break;
case 2 :
F_36 ( V_2 , V_35 ) ;
break;
case 3 :
F_37 ( V_2 , V_35 ) ;
break;
}
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_25 [ 4 ] ;
int V_36 , V_37 , V_38 , V_14 ;
V_37 = V_2 -> V_39 . V_37 ;
V_2 -> V_39 . V_40 = V_41 ;
V_2 -> V_39 . V_42 = 0 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_2 -> V_39 . V_43 [ V_36 ] = 0 ;
F_39 ( V_2 , V_2 -> V_39 . V_44 ) ;
F_40 ( V_2 , V_2 -> V_39 . V_37 ) ;
V_25 [ 0 ] = V_2 -> V_39 . V_44 ;
V_25 [ 1 ] = V_2 -> V_39 . V_37 ;
V_14 = F_41 ( V_2 , V_45 ,
2 , V_25 ) ;
if ( V_14 )
return V_14 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_33 ( V_2 ,
V_46 , V_36 ) ;
V_38 = 0 ;
while ( F_42 ( V_2 ) == V_47 ) {
if ( V_38 == V_4 ) {
F_13 ( V_2 -> V_5 , L_7 ) ;
return - V_6 ;
}
V_38 ++ ;
F_14 ( 90 , 120 ) ;
}
F_32 ( V_2 , V_48 ) ;
V_14 = F_21 ( V_2 ,
V_33 ,
V_49 | V_50 ) ;
if ( V_14 )
return V_14 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_25 [ V_36 ] = V_51 |
V_52 ;
V_14 = F_41 ( V_2 , V_53 ,
V_37 , V_25 ) ;
return V_14 ;
}
static unsigned char F_43 ( T_1 V_54 [ 2 ] , int V_36 )
{
int V_55 = ( V_36 & 1 ) * 4 ;
T_1 V_56 = V_54 [ V_36 >> 1 ] ;
return ( V_56 >> V_55 ) & 0xf ;
}
static int F_44 ( T_1 V_54 [ 2 ] , int V_37 )
{
int V_36 ;
T_1 V_57 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_57 = F_43 ( V_54 , V_36 ) ;
if ( ( V_57 & V_58 ) == 0 )
return - V_59 ;
}
return 0 ;
}
static int F_45 ( T_1 V_54 [ 2 ] , T_1 V_60 ,
int V_37 )
{
int V_36 ;
T_1 V_57 ;
if ( ( V_60 & V_61 ) == 0 )
return - V_59 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_57 = F_43 ( V_54 , V_36 ) ;
V_57 &= V_62 ;
if ( V_57 != V_62 )
return - V_59 ;
}
return 0 ;
}
static unsigned char F_46 ( T_1 V_63 [ 2 ] ,
int V_36 )
{
int V_55 = ( V_36 & 1 ) * 4 ;
T_1 V_56 = V_63 [ V_36 >> 1 ] ;
return ( V_56 >> V_55 ) & 0x3 ;
}
static unsigned char F_47 (
T_1 V_63 [ 2 ] ,
int V_36 )
{
int V_55 = ( V_36 & 1 ) * 4 ;
T_1 V_56 = V_63 [ V_36 >> 1 ] ;
return ( ( V_56 >> V_55 ) & 0xc ) >> 2 ;
}
static void F_48 ( struct V_1 * V_2 ,
T_1 V_64 , int V_36 )
{
switch ( V_36 ) {
case 0 :
F_49 ( V_2 , V_64 ) ;
break;
case 1 :
F_50 ( V_2 , V_64 ) ;
break;
case 2 :
F_51 ( V_2 , V_64 ) ;
break;
case 3 :
F_52 ( V_2 , V_64 ) ;
break;
}
}
static unsigned int F_53 (
struct V_1 * V_2 ,
int V_36 )
{
T_2 V_65 ;
switch ( V_36 ) {
case 0 :
V_65 = F_54 ( V_2 ) ;
break;
case 1 :
V_65 = F_55 ( V_2 ) ;
break;
case 2 :
V_65 = F_56 ( V_2 ) ;
break;
case 3 :
V_65 = F_57 ( V_2 ) ;
break;
default:
F_58 ( 1 ) ;
return 0 ;
}
return V_65 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
F_29 ( V_2 ) ;
V_2 -> V_39 . V_40 = V_66 ;
}
static void F_60 ( struct V_1 * V_2 ,
T_1 V_63 [ 2 ] )
{
int V_36 , V_37 ;
T_1 V_67 , V_35 , V_68 ;
V_37 = V_2 -> V_39 . V_37 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_67 = F_46 (
V_63 , V_36 ) ;
V_35 = F_47 (
V_63 , V_36 ) ;
V_68 = F_61 ( V_67 ) |
F_62 ( V_35 ) ;
if ( V_67 == V_69 )
V_68 |= V_70 ;
if ( V_35 == V_71 )
V_68 |= V_72 ;
V_2 -> V_39 . V_68 [ V_36 ] = V_68 ;
}
}
static int F_63 ( struct V_1 * V_2 )
{
int V_36 , V_37 , V_14 ;
T_1 V_67 , V_35 , V_68 ;
T_1 V_54 [ 2 ] , V_63 [ 2 ] ;
F_14 ( 100 , 101 ) ;
V_37 = V_2 -> V_39 . V_37 ;
V_14 = F_24 ( V_2 ,
V_73 , 2 , V_54 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_24 ( V_2 ,
V_74 , 2 , V_63 ) ;
if ( V_14 )
return V_14 ;
if ( F_44 ( V_54 , V_37 ) == 0 ) {
F_32 ( V_2 , V_75 ) ;
V_14 = F_21 ( V_2 ,
V_33 ,
V_49 |
V_76 ) ;
if ( V_14 )
return V_14 ;
F_22 ( V_2 -> V_5 , L_8 ) ;
V_2 -> V_39 . V_40 = V_77 ;
} else {
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_68 = F_53 (
V_2 , V_36 ) ;
V_67 = F_46 (
V_63 , V_36 ) ;
V_35 = F_47 (
V_63 , V_36 ) ;
if ( F_64 ( V_68 ) ==
V_67 &&
F_65 ( V_68 ) ==
V_35 )
V_2 -> V_39 . V_43 [ V_36 ] ++ ;
if ( V_2 -> V_39 . V_43 [ V_36 ] == V_78 ||
V_67 == V_69 ||
V_35 == V_71 ) {
F_13 ( V_2 -> V_5 , L_9 ,
V_2 -> V_39 . V_43 [ V_36 ] ,
V_67 , V_35 ) ;
F_59 ( V_2 ) ;
return - V_18 ;
}
}
}
F_60 ( V_2 , V_63 ) ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_48 ( V_2 ,
V_2 -> V_39 . V_68 [ V_36 ] , V_36 ) ;
V_14 = F_41 ( V_2 ,
V_53 , V_37 ,
V_2 -> V_39 . V_68 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_36 , V_37 , V_14 ;
T_2 V_65 ;
T_1 V_60 , V_54 [ 2 ] , V_63 [ 2 ] ;
F_14 ( 400 , 401 ) ;
V_37 = V_2 -> V_39 . V_37 ;
V_14 = F_24 ( V_2 ,
V_73 , 2 , V_54 ) ;
if ( V_14 )
return V_14 ;
if ( F_44 ( V_54 , V_37 ) ) {
F_59 ( V_2 ) ;
return - V_18 ;
}
V_14 = F_24 ( V_2 ,
V_74 , 2 , V_63 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_20 ( V_2 ,
V_79 , & V_60 ) ;
if ( V_14 )
return V_14 ;
F_60 ( V_2 , V_63 ) ;
if ( ! F_45 ( V_54 , V_60 , V_37 ) ) {
F_31 ( V_2 ) ;
F_22 ( V_2 -> V_5 , L_10 ) ;
F_67 ( V_2 , & V_65 ) ;
V_2 -> V_39 . V_44 = V_65 ;
F_18 ( V_2 -> V_5 , L_11 ,
V_2 -> V_39 . V_44 ) ;
F_68 ( V_2 , & V_65 ) ;
V_2 -> V_39 . V_37 = V_65 ;
F_18 ( V_2 -> V_5 , L_12 ,
V_2 -> V_39 . V_37 ) ;
F_29 ( V_2 ) ;
V_2 -> V_39 . V_40 = V_80 ;
return 0 ;
}
V_2 -> V_39 . V_42 ++ ;
if ( V_2 -> V_39 . V_42 > V_81 ) {
F_13 ( V_2 -> V_5 , L_13 ) ;
F_59 ( V_2 ) ;
return - V_18 ;
}
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_48 ( V_2 ,
V_2 -> V_39 . V_68 [ V_36 ] , V_36 ) ;
V_14 = F_41 ( V_2 , V_53 ,
V_37 , V_2 -> V_39 . V_68 ) ;
return V_14 ;
}
static void F_69 ( struct V_1 * V_2 ,
T_1 * V_82 )
{
T_1 V_28 ;
F_20 ( V_2 , V_83 , & V_28 ) ;
* V_82 = V_28 ;
}
static void F_70 ( struct V_1 * V_2 ,
T_1 * V_37 )
{
T_1 V_28 ;
F_20 ( V_2 , V_31 , & V_28 ) ;
* V_37 = F_71 ( V_28 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
enum V_84 V_85 ,
enum V_86 V_87 )
{
F_73 ( V_2 ) ;
F_69 ( V_2 , & V_2 -> V_39 . V_44 ) ;
F_70 ( V_2 , & V_2 -> V_39 . V_37 ) ;
if ( ( V_2 -> V_39 . V_44 != V_88 ) &&
( V_2 -> V_39 . V_44 != V_89 ) ) {
F_13 ( V_2 -> V_5 , L_14 ,
V_2 -> V_39 . V_44 ) ;
V_2 -> V_39 . V_44 = V_88 ;
}
if ( V_2 -> V_39 . V_37 == 0 ) {
F_13 ( V_2 -> V_5 , L_15 ,
V_2 -> V_39 . V_37 ) ;
V_2 -> V_39 . V_37 = ( T_1 ) V_90 ;
}
if ( V_2 -> V_39 . V_37 > V_85 )
V_2 -> V_39 . V_37 = V_85 ;
if ( V_2 -> V_39 . V_44 > V_87 )
V_2 -> V_39 . V_44 = V_87 ;
F_74 ( V_2 , V_91 , 0 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_14 = 0 , V_92 = 0 ;
V_2 -> V_39 . V_40 = V_93 ;
while ( ! V_14 && ! V_92 ) {
switch ( V_2 -> V_39 . V_40 ) {
case V_93 :
V_14 = F_38 ( V_2 ) ;
if ( V_14 )
F_13 ( V_2 -> V_5 , L_16 ) ;
break;
case V_41 :
V_14 = F_63 ( V_2 ) ;
if ( V_14 )
F_13 ( V_2 -> V_5 , L_17 ) ;
break;
case V_77 :
V_14 = F_66 ( V_2 ) ;
if ( V_14 )
F_13 ( V_2 -> V_5 , L_18 ) ;
break;
case V_80 :
V_92 = 1 ;
break;
case V_66 :
return - V_94 ;
}
}
if ( V_14 )
F_13 ( V_2 -> V_5 , L_19 , V_14 ) ;
return V_14 ;
}
static int F_76 ( struct V_1 * V_2 ,
T_2 V_95 ,
T_2 V_96 )
{
int V_8 ;
int V_14 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
F_72 ( V_2 , V_95 , V_96 ) ;
V_14 = F_75 ( V_2 ) ;
if ( V_14 == 0 )
break;
F_14 ( 100 , 110 ) ;
}
return V_14 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
int V_3 = 0 ;
int V_97 = 0 ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
if ( F_42 ( V_2 ) == V_47 ) {
F_13 ( V_2 -> V_5 , L_20 ) ;
return - V_59 ;
}
for (; ; ) {
V_3 ++ ;
if ( F_80 ( V_2 ) == 0 )
break;
if ( V_4 < V_3 ) {
F_13 ( V_2 -> V_5 , L_21 ) ;
return - V_6 ;
}
F_14 ( 1 , 2 ) ;
}
F_81 ( V_2 , V_98 , 0 , 0 ) ;
F_82 ( V_2 , V_99 ) ;
F_83 ( V_2 , 0 ) ;
F_84 ( V_2 , 0 ) ;
F_85 ( V_2 ) ;
V_3 = 0 ;
for (; ; ) {
V_3 ++ ;
if ( F_86 ( V_2 ) == 0 ) {
V_97 ++ ;
if ( V_97 > 10 )
break;
} else if ( V_97 ) {
V_97 = 0 ;
}
if ( V_4 < V_3 ) {
F_13 ( V_2 -> V_5 , L_21 ) ;
return - V_6 ;
}
F_14 ( 1000 , 1001 ) ;
}
if ( V_14 != 0 )
F_13 ( V_2 -> V_5 , L_22 ) ;
return V_14 ;
}
static void F_87 ( struct V_1 * V_2 , bool V_27 )
{
T_1 V_28 ;
if ( V_27 ) {
F_88 ( V_2 ) ;
F_20 ( V_2 ,
V_33 ,
& V_28 ) ;
F_21 ( V_2 ,
V_33 ,
( T_1 ) ( V_28 & ~ V_49 ) ) ;
} else {
F_89 ( V_2 ) ;
F_20 ( V_2 ,
V_33 ,
& V_28 ) ;
F_21 ( V_2 ,
V_33 ,
( T_1 ) ( V_28 | V_49 ) ) ;
}
}
static T_3 F_90 ( int V_100 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
enum V_102 V_103 ;
V_103 = F_91 ( V_2 ) ;
switch ( V_103 ) {
case V_104 :
F_18 ( V_2 -> V_5 , L_23 ) ;
F_92 ( & V_2 -> V_105 ) ;
F_93 ( V_2 ) ;
break;
case V_106 :
F_18 ( V_2 -> V_5 , L_24 ) ;
F_93 ( V_2 ) ;
break;
case V_107 :
F_18 ( V_2 -> V_5 , L_25 ) ;
F_93 ( V_2 ) ;
break;
default:
F_13 ( V_2 -> V_5 , L_26 ) ;
break;
}
return V_108 ;
}
static void F_94 ( struct V_109 * V_110 )
{
struct V_1 * V_2 ;
V_2 = F_95 ( V_110 , struct V_1 , V_105 ) ;
if ( V_2 -> V_111 )
F_96 ( V_2 -> V_111 ) ;
}
static void F_97 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_114 ;
int V_115 ;
if ( V_2 -> V_116 ) {
if ( F_98 ( V_2 -> V_116 ) )
F_99 ( L_27 ) ;
}
V_115 = F_11 ( V_2 ) ;
if ( V_115 ) {
return;
}
V_115 = F_23 ( V_2 ) ;
if ( V_115 ) {
F_13 ( V_2 -> V_5 , L_28 ) ;
return;
}
V_115 = F_76 ( V_2 , V_2 -> V_117 -> V_37 ,
V_2 -> V_117 -> V_44 ) ;
if ( V_115 ) {
F_13 ( V_2 -> V_5 , L_29 ) ;
return;
}
F_87 ( V_2 , 1 ) ;
F_25 ( V_2 , 1 ) ;
F_30 ( V_2 , 1 ) ;
F_40 ( V_2 , V_2 -> V_117 -> V_37 ) ;
F_39 ( V_2 , V_2 -> V_117 -> V_44 ) ;
F_100 ( V_2 ) ;
V_115 = F_77 ( V_2 ) ;
if ( V_115 )
F_13 ( V_2 -> V_5 , L_30 ) ;
if ( V_2 -> V_116 ) {
if ( F_101 ( V_2 -> V_116 ) )
F_99 ( L_31 ) ;
}
}
static enum V_118 F_102 (
struct V_119 * V_120 , bool V_121 )
{
return V_122 ;
}
static void F_103 ( struct V_119 * V_120 )
{
F_104 ( V_120 ) ;
F_105 ( V_120 ) ;
}
static int F_106 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_107 ( V_120 ) ;
struct V_123 * V_124 ;
if ( V_2 -> V_116 )
return F_108 ( V_2 -> V_116 ) ;
V_124 = F_109 ( V_120 -> V_5 ) ;
if ( ! V_124 ) {
F_99 ( L_32 ) ;
return 0 ;
}
F_110 ( & V_2 -> V_125 . V_126 , V_124 ) ;
V_124 -> V_127 = V_2 -> V_125 . V_127 ;
V_124 -> V_128 = V_2 -> V_125 . V_128 ;
V_120 -> V_129 . V_127 = V_124 -> V_127 ;
V_120 -> V_129 . V_128 = V_124 -> V_128 ;
V_124 -> type = V_130 | V_131 ;
F_111 ( V_124 ) ;
F_112 ( V_120 , V_124 ) ;
return 1 ;
}
static struct V_132 * F_113 (
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_107 ( V_120 ) ;
return V_2 -> V_133 ;
}
static bool F_114 ( const char * V_134 , struct V_135 * V_136 )
{
V_136 -> V_137 = NULL ;
V_136 -> V_138 = F_115 ( NULL , NULL , V_134 ) ;
if ( ! V_136 -> V_138 )
return false ;
V_136 -> V_137 = F_116 ( V_136 -> V_138 ) ;
if ( ! V_136 -> V_137 )
return false ;
return true ;
}
static int F_117 ( struct V_139 * V_5 ,
struct V_132 * V_133 )
{
struct V_135 V_136 ;
int V_115 ;
if ( F_114 ( L_33 , & V_136 ) ) {
V_115 = F_118 ( V_5 , V_133 , V_136 . V_137 , V_136 . V_138 ) ;
if ( ! V_115 )
return 1 ;
}
return 0 ;
}
static int F_119 ( struct V_112 * V_113 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = V_113 -> V_114 ;
struct V_119 * V_120 = & V_2 -> V_120 ;
int V_115 ;
V_2 -> V_133 = V_133 ;
V_115 = F_117 ( V_2 -> V_111 , V_133 ) ;
if ( V_115 )
return 0 ;
V_120 -> V_140 = V_141 ;
V_115 = F_120 ( V_2 -> V_111 , V_120 ,
& V_142 , V_143 ) ;
if ( V_115 ) {
F_99 ( L_34 ) ;
return V_115 ;
}
F_121 ( V_120 , & V_144 ) ;
F_122 ( V_120 ) ;
F_123 ( V_120 , V_133 ) ;
if ( V_2 -> V_116 )
V_115 = F_124 ( V_2 -> V_116 , & V_2 -> V_120 ) ;
return V_115 ;
}
static void F_125 ( struct V_1 * V_2 )
{
if ( V_2 -> V_145 ) {
F_126 ( V_2 -> V_145 ) ;
} else if ( V_2 -> V_146 ) {
T_2 V_65 ;
V_65 = F_127 ( V_2 -> V_146 ) ;
V_65 |= V_2 -> V_147 ;
F_128 ( V_65 , V_2 -> V_146 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
if ( V_2 -> V_145 ) {
F_130 ( V_2 -> V_145 ) ;
} else if ( V_2 -> V_146 ) {
T_2 V_65 ;
V_65 = F_127 ( V_2 -> V_146 ) ;
V_65 &= ~ ( V_2 -> V_147 ) ;
F_128 ( V_65 , V_2 -> V_146 ) ;
}
}
static void F_131 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_114 ;
if ( V_2 -> V_148 == V_149 )
return;
if ( V_2 -> V_116 ) {
if ( F_132 ( V_2 -> V_116 ) ) {
F_99 ( L_35 ) ;
return;
}
}
F_133 ( V_2 -> clock ) ;
F_125 ( V_2 ) ;
F_1 ( V_2 ) ;
F_134 ( V_2 -> V_100 ) ;
F_97 ( V_113 ) ;
}
static void F_135 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_114 ;
if ( V_2 -> V_148 != V_149 )
return;
if ( V_2 -> V_116 ) {
if ( F_98 ( V_2 -> V_116 ) ) {
F_99 ( L_27 ) ;
return;
}
}
F_136 ( V_2 -> V_100 ) ;
F_137 ( & V_2 -> V_105 ) ;
F_129 ( V_2 ) ;
F_138 ( V_2 -> clock ) ;
if ( V_2 -> V_116 ) {
if ( F_139 ( V_2 -> V_116 ) )
F_99 ( L_36 ) ;
}
}
static void F_140 ( struct V_112 * V_113 , int V_124 )
{
struct V_1 * V_2 = V_113 -> V_114 ;
switch ( V_124 ) {
case V_149 :
F_131 ( V_113 ) ;
break;
case V_150 :
case V_151 :
case V_152 :
F_135 ( V_113 ) ;
break;
default:
break;
}
V_2 -> V_148 = V_124 ;
}
static struct V_117 * F_141 ( struct V_153 * V_5 )
{
struct V_154 * V_155 = V_5 -> V_156 ;
struct V_117 * V_157 ;
V_157 = F_142 ( V_5 ,
sizeof( * V_157 ) , V_158 ) ;
if ( ! V_157 )
return F_143 ( - V_159 ) ;
V_157 -> V_160 =
F_144 ( V_155 , L_37 ) ;
V_157 -> V_161 =
F_144 ( V_155 , L_38 ) ;
V_157 -> V_162 =
F_144 ( V_155 , L_39 ) ;
if ( F_145 ( V_155 , L_40 ,
& V_157 -> V_163 ) ) {
F_13 ( V_5 , L_41 ) ;
return F_143 ( - V_59 ) ;
}
if ( F_145 ( V_155 , L_42 ,
& V_157 -> V_164 ) ) {
F_13 ( V_5 , L_43 ) ;
return F_143 ( - V_59 ) ;
}
if ( F_145 ( V_155 , L_44 ,
& V_157 -> V_165 ) ) {
F_13 ( V_5 , L_45 ) ;
return F_143 ( - V_59 ) ;
}
if ( F_145 ( V_155 , L_46 ,
& V_157 -> V_166 ) ) {
F_13 ( V_5 , L_47 ) ;
return F_143 ( - V_59 ) ;
}
if ( F_145 ( V_155 , L_48 ,
& V_157 -> V_44 ) ) {
F_13 ( V_5 , L_49 ) ;
return F_143 ( - V_59 ) ;
}
if ( F_145 ( V_155 , L_50 ,
& V_157 -> V_37 ) ) {
F_13 ( V_5 , L_51 ) ;
return F_143 ( - V_59 ) ;
}
return V_157 ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_154 * V_167 = F_147 ( V_2 -> V_5 -> V_156 ) ;
T_2 V_168 ;
int V_115 = 0 ;
V_167 = F_148 ( V_167 , L_52 ) ;
if ( ! V_167 ) {
V_2 -> V_145 = F_149 ( V_2 -> V_5 , L_53 ) ;
return F_150 ( V_2 -> V_145 ) ;
}
if ( F_145 ( V_167 , L_54 , & V_168 ) ) {
F_13 ( V_2 -> V_5 , L_55 ) ;
V_115 = - V_59 ;
goto V_169;
}
if ( F_145 ( V_167 , L_56 ,
& V_2 -> V_147 ) ) {
F_13 ( V_2 -> V_5 , L_57 ) ;
V_115 = - V_59 ;
goto V_169;
}
V_2 -> V_146 = F_151 ( V_168 , V_170 ) ;
if ( ! V_2 -> V_146 ) {
F_13 ( V_2 -> V_5 , L_58 ) ;
V_115 = - V_159 ;
goto V_169;
}
V_169:
F_152 ( V_167 ) ;
return V_115 ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_115 ;
V_115 = F_154 ( V_2 -> V_5 -> V_156 , & V_2 -> V_125 . V_126 ,
V_171 ) ;
if ( V_115 ) {
F_99 ( L_59 , V_115 ) ;
return V_115 ;
}
return 0 ;
}
static int F_155 ( struct V_153 * V_5 , struct V_153 * V_172 , void * V_28 )
{
struct V_173 * V_174 = F_156 ( V_5 ) ;
struct V_139 * V_111 = V_28 ;
struct V_175 * V_176 ;
struct V_1 * V_2 = V_177 . V_114 ;
unsigned int V_178 ;
int V_115 = 0 ;
V_2 -> V_5 = & V_174 -> V_5 ;
V_2 -> V_148 = V_152 ;
V_2 -> V_117 = F_141 ( & V_174 -> V_5 ) ;
if ( F_157 ( V_2 -> V_117 ) )
return F_158 ( V_2 -> V_117 ) ;
V_115 = F_146 ( V_2 ) ;
if ( V_115 )
return V_115 ;
if ( ! V_2 -> V_116 ) {
V_115 = F_153 ( V_2 ) ;
if ( V_115 )
return V_115 ;
}
V_2 -> clock = F_159 ( & V_174 -> V_5 , L_53 ) ;
if ( F_157 ( V_2 -> clock ) ) {
F_13 ( & V_174 -> V_5 , L_60 ) ;
return F_158 ( V_2 -> clock ) ;
}
F_133 ( V_2 -> clock ) ;
V_176 = F_160 ( V_174 , V_179 , 0 ) ;
V_2 -> V_180 = F_161 ( & V_174 -> V_5 , V_176 ) ;
if ( F_157 ( V_2 -> V_180 ) )
return F_158 ( V_2 -> V_180 ) ;
V_2 -> V_181 = F_162 ( V_5 -> V_156 , L_61 , 0 ) ;
if ( F_163 ( V_2 -> V_181 ) ) {
V_115 = F_164 ( & V_174 -> V_5 , V_2 -> V_181 , V_182 ,
L_62 ) ;
if ( V_115 ) {
F_13 ( & V_174 -> V_5 , L_63 ) ;
return V_115 ;
}
V_2 -> V_100 = F_165 ( V_2 -> V_181 ) ;
V_178 = V_183 | V_184 ;
} else {
V_2 -> V_181 = - V_185 ;
V_2 -> V_100 = F_166 ( V_174 , 0 ) ;
V_178 = 0 ;
}
if ( V_2 -> V_100 == - V_186 ) {
F_13 ( & V_174 -> V_5 , L_64 ) ;
return - V_185 ;
}
F_167 ( & V_2 -> V_105 , F_94 ) ;
F_125 ( V_2 ) ;
F_1 ( V_2 ) ;
V_115 = F_168 ( & V_174 -> V_5 , V_2 -> V_100 , F_90 ,
V_178 , L_65 , V_2 ) ;
if ( V_115 ) {
F_13 ( & V_174 -> V_5 , L_66 ) ;
return V_115 ;
}
F_136 ( V_2 -> V_100 ) ;
V_2 -> V_111 = V_111 ;
F_169 ( V_174 , & V_177 ) ;
return F_170 ( V_111 , & V_177 ) ;
}
static void F_171 ( struct V_153 * V_5 , struct V_153 * V_172 ,
void * V_28 )
{
struct V_112 * V_113 = F_172 ( V_5 ) ;
F_140 ( V_113 , V_152 ) ;
}
static int F_173 ( struct V_173 * V_174 )
{
struct V_153 * V_5 = & V_174 -> V_5 ;
struct V_154 * V_187 ;
struct V_1 * V_2 ;
int V_115 ;
V_115 = F_174 ( & V_174 -> V_5 , V_188 ,
V_177 . type ) ;
if ( V_115 )
return V_115 ;
V_2 = F_142 ( & V_174 -> V_5 , sizeof( struct V_1 ) ,
V_158 ) ;
if ( ! V_2 )
return - V_159 ;
V_187 = F_175 ( V_5 -> V_156 , L_67 , 0 ) ;
if ( V_187 ) {
V_2 -> V_116 = F_176 ( V_187 ) ;
F_152 ( V_187 ) ;
if ( ! V_2 -> V_116 )
return - V_189 ;
}
V_177 . V_114 = V_2 ;
V_115 = F_177 ( & V_174 -> V_5 , & V_190 ) ;
if ( V_115 )
F_178 ( & V_174 -> V_5 ,
V_188 ) ;
return V_115 ;
}
static int F_179 ( struct V_173 * V_174 )
{
F_180 ( & V_174 -> V_5 , & V_190 ) ;
F_178 ( & V_174 -> V_5 , V_188 ) ;
return 0 ;
}
static int F_181 ( struct V_153 * V_5 )
{
struct V_173 * V_174 = F_156 ( V_5 ) ;
struct V_112 * V_113 = F_182 ( V_174 ) ;
F_140 ( V_113 , V_152 ) ;
return 0 ;
}
static int F_183 ( struct V_153 * V_5 )
{
struct V_173 * V_174 = F_156 ( V_5 ) ;
struct V_112 * V_113 = F_182 ( V_174 ) ;
F_140 ( V_113 , V_149 ) ;
return 0 ;
}
