static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 ) ;
}
static inline struct V_2 * F_3 (
struct V_6 * V_7 )
{
return F_4 ( V_7 , struct V_2 , V_4 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 ) ;
F_11 ( V_3 ) ;
F_12 ( V_3 ) ;
F_13 ( V_3 ) ;
F_14 ( V_3 ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
int V_8 = 0 ;
while ( F_16 ( V_3 ) != 0 ) {
V_8 ++ ;
if ( V_9 < V_8 ) {
F_17 ( V_3 -> V_10 , L_1 ) ;
return - V_11 ;
}
F_18 ( 10 , 11 ) ;
}
return 0 ;
}
static unsigned char F_19 ( unsigned char * V_12 )
{
int V_13 ;
unsigned char V_14 = 0 ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ )
V_14 = V_14 + V_12 [ V_13 ] ;
return V_14 ;
}
static int F_20 ( struct V_2 * V_3 )
{
unsigned char V_16 [ V_15 * 2 ] ;
unsigned int V_17 = 0 ;
unsigned char V_14 ;
unsigned char V_18 ;
int V_19 ;
V_19 = F_21 ( V_3 , V_20 ,
V_21 ,
& V_17 ) ;
if ( V_19 )
return V_19 ;
if ( V_17 > 0 ) {
F_22 ( V_3 -> V_10 , L_2 ) ;
V_19 = F_23 ( V_3 , V_20 ,
V_22 ,
V_15 ,
& V_16 [ V_22 ] ) ;
if ( V_19 != 0 ) {
F_17 ( V_3 -> V_10 , L_3 ) ;
return - V_23 ;
}
V_14 = F_19 ( V_16 ) ;
if ( V_14 != 0 ) {
F_17 ( V_3 -> V_10 , L_4 ) ;
return - V_23 ;
}
V_19 = F_23 ( V_3 ,
V_20 ,
V_15 ,
V_15 ,
& V_16 [ V_15 ] ) ;
if ( V_19 != 0 ) {
F_17 ( V_3 -> V_10 , L_3 ) ;
return - V_23 ;
}
V_14 = F_19 ( & V_16 [ V_15 ] ) ;
if ( V_14 != 0 ) {
F_17 ( V_3 -> V_10 , L_4 ) ;
return - V_23 ;
}
F_24 ( V_3 , V_24 ,
& V_18 ) ;
if ( V_18 & V_25 ) {
F_25 ( V_3 ,
V_26 ,
V_16 [ V_15 + V_27 ] ) ;
F_25 ( V_3 ,
V_28 ,
V_29 ) ;
}
} else {
F_26 ( V_3 -> V_10 , L_5 ) ;
V_19 = F_23 ( V_3 ,
V_20 ,
V_22 ,
V_15 ,
& V_16 [ V_22 ] ) ;
if ( V_19 != 0 ) {
F_17 ( V_3 -> V_10 , L_3 ) ;
return - V_23 ;
}
V_14 = F_19 ( V_16 ) ;
if ( V_14 != 0 ) {
F_17 ( V_3 -> V_10 , L_4 ) ;
return - V_23 ;
}
F_24 ( V_3 ,
V_24 ,
& V_18 ) ;
if ( V_18 & V_25 ) {
F_25 ( V_3 ,
V_26 ,
V_16 [ V_27 ] ) ;
F_25 ( V_3 ,
V_28 ,
V_29 ) ;
}
}
F_22 ( V_3 -> V_10 , L_6 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
T_1 V_30 [ 12 ] ;
int V_13 ;
int V_19 ;
V_19 = F_28 ( V_3 , V_31 ,
12 , V_30 ) ;
if ( V_19 )
return V_19 ;
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_19 = F_20 ( V_3 ) ;
if ( ! V_19 )
break;
}
return V_19 ;
}
static void F_29 ( struct V_2 * V_3 ,
bool V_32 )
{
T_1 V_33 ;
F_24 ( V_3 , V_34 , & V_33 ) ;
if ( V_32 )
F_25 ( V_3 , V_34 ,
V_35 |
F_30 ( V_33 ) ) ;
else
F_25 ( V_3 , V_34 ,
F_30 ( V_33 ) ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
T_1 V_33 ;
int V_19 ;
F_24 ( V_3 , V_36 , & V_33 ) ;
V_19 = F_32 ( V_33 ) ;
return V_19 ;
}
static void F_33 ( struct V_2 * V_3 )
{
T_1 V_33 ;
V_33 = F_31 ( V_3 ) ;
F_29 ( V_3 , V_33 ) ;
F_34 ( V_3 , V_33 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
F_36 ( V_3 , V_37 ) ;
F_25 ( V_3 ,
V_38 ,
V_39 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
int V_40 , int V_41 )
{
switch ( V_41 ) {
case 0 :
F_38 ( V_3 , V_40 ) ;
break;
case 1 :
F_39 ( V_3 , V_40 ) ;
break;
case 2 :
F_40 ( V_3 , V_40 ) ;
break;
case 3 :
F_41 ( V_3 , V_40 ) ;
break;
}
}
static int F_42 ( struct V_2 * V_3 )
{
T_1 V_30 [ 4 ] ;
int V_41 , V_42 , V_43 , V_19 ;
V_42 = V_3 -> V_44 . V_42 ;
V_3 -> V_44 . V_45 = V_46 ;
V_3 -> V_44 . V_47 = 0 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
V_3 -> V_44 . V_48 [ V_41 ] = 0 ;
F_43 ( V_3 , V_3 -> V_44 . V_49 ) ;
F_44 ( V_3 , V_3 -> V_44 . V_42 ) ;
V_30 [ 0 ] = V_3 -> V_44 . V_49 ;
V_30 [ 1 ] = V_3 -> V_44 . V_42 ;
V_19 = F_45 ( V_3 , V_50 ,
2 , V_30 ) ;
if ( V_19 )
return V_19 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
F_37 ( V_3 ,
V_51 , V_41 ) ;
V_43 = 0 ;
while ( F_46 ( V_3 ) == V_52 ) {
if ( V_43 == V_9 ) {
F_17 ( V_3 -> V_10 , L_7 ) ;
return - V_11 ;
}
V_43 ++ ;
F_18 ( 90 , 120 ) ;
}
F_36 ( V_3 , V_53 ) ;
V_19 = F_25 ( V_3 ,
V_38 ,
V_54 | V_55 ) ;
if ( V_19 )
return V_19 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
V_30 [ V_41 ] = V_56 |
V_57 ;
V_19 = F_45 ( V_3 , V_58 ,
V_42 , V_30 ) ;
return V_19 ;
}
static unsigned char F_47 ( T_1 V_59 [ 2 ] , int V_41 )
{
int V_60 = ( V_41 & 1 ) * 4 ;
T_1 V_61 = V_59 [ V_41 >> 1 ] ;
return ( V_61 >> V_60 ) & 0xf ;
}
static int F_48 ( T_1 V_59 [ 2 ] , int V_42 )
{
int V_41 ;
T_1 V_62 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_62 = F_47 ( V_59 , V_41 ) ;
if ( ( V_62 & V_63 ) == 0 )
return - V_64 ;
}
return 0 ;
}
static int F_49 ( T_1 V_59 [ 2 ] , T_1 V_65 ,
int V_42 )
{
int V_41 ;
T_1 V_62 ;
if ( ( V_65 & V_66 ) == 0 )
return - V_64 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_62 = F_47 ( V_59 , V_41 ) ;
V_62 &= V_67 ;
if ( V_62 != V_67 )
return - V_64 ;
}
return 0 ;
}
static unsigned char F_50 ( T_1 V_68 [ 2 ] ,
int V_41 )
{
int V_60 = ( V_41 & 1 ) * 4 ;
T_1 V_61 = V_68 [ V_41 >> 1 ] ;
return ( V_61 >> V_60 ) & 0x3 ;
}
static unsigned char F_51 (
T_1 V_68 [ 2 ] ,
int V_41 )
{
int V_60 = ( V_41 & 1 ) * 4 ;
T_1 V_61 = V_68 [ V_41 >> 1 ] ;
return ( ( V_61 >> V_60 ) & 0xc ) >> 2 ;
}
static void F_52 ( struct V_2 * V_3 ,
T_1 V_69 , int V_41 )
{
switch ( V_41 ) {
case 0 :
F_53 ( V_3 , V_69 ) ;
break;
case 1 :
F_54 ( V_3 , V_69 ) ;
break;
case 2 :
F_55 ( V_3 , V_69 ) ;
break;
case 3 :
F_56 ( V_3 , V_69 ) ;
break;
}
}
static unsigned int F_57 (
struct V_2 * V_3 ,
int V_41 )
{
T_2 V_70 ;
switch ( V_41 ) {
case 0 :
V_70 = F_58 ( V_3 ) ;
break;
case 1 :
V_70 = F_59 ( V_3 ) ;
break;
case 2 :
V_70 = F_60 ( V_3 ) ;
break;
case 3 :
V_70 = F_61 ( V_3 ) ;
break;
default:
F_62 ( 1 ) ;
return 0 ;
}
return V_70 ;
}
static void F_63 ( struct V_2 * V_3 )
{
F_35 ( V_3 ) ;
F_33 ( V_3 ) ;
V_3 -> V_44 . V_45 = V_71 ;
}
static void F_64 ( struct V_2 * V_3 ,
T_1 V_68 [ 2 ] )
{
int V_41 , V_42 ;
T_1 V_72 , V_40 , V_73 ;
V_42 = V_3 -> V_44 . V_42 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_72 = F_50 (
V_68 , V_41 ) ;
V_40 = F_51 (
V_68 , V_41 ) ;
V_73 = F_65 ( V_72 ) |
F_66 ( V_40 ) ;
if ( V_72 == V_74 )
V_73 |= V_75 ;
if ( V_40 == V_76 )
V_73 |= V_77 ;
V_3 -> V_44 . V_73 [ V_41 ] = V_73 ;
}
}
static int F_67 ( struct V_2 * V_3 )
{
int V_41 , V_42 , V_19 ;
T_1 V_72 , V_40 , V_73 ;
T_1 V_59 [ 2 ] , V_68 [ 2 ] ;
F_18 ( 100 , 101 ) ;
V_42 = V_3 -> V_44 . V_42 ;
V_19 = F_28 ( V_3 ,
V_78 , 2 , V_59 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_28 ( V_3 ,
V_79 , 2 , V_68 ) ;
if ( V_19 )
return V_19 ;
if ( F_48 ( V_59 , V_42 ) == 0 ) {
F_36 ( V_3 , V_80 ) ;
V_19 = F_25 ( V_3 ,
V_38 ,
V_54 |
V_81 ) ;
if ( V_19 )
return V_19 ;
F_26 ( V_3 -> V_10 , L_8 ) ;
V_3 -> V_44 . V_45 = V_82 ;
} else {
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_73 = F_57 (
V_3 , V_41 ) ;
V_72 = F_50 (
V_68 , V_41 ) ;
V_40 = F_51 (
V_68 , V_41 ) ;
if ( F_68 ( V_73 ) ==
V_72 &&
F_69 ( V_73 ) ==
V_40 )
V_3 -> V_44 . V_48 [ V_41 ] ++ ;
if ( V_3 -> V_44 . V_48 [ V_41 ] == V_83 ||
V_72 == V_74 ||
V_40 == V_76 ) {
F_17 ( V_3 -> V_10 , L_9 ,
V_3 -> V_44 . V_48 [ V_41 ] ,
V_72 , V_40 ) ;
F_63 ( V_3 ) ;
return - V_23 ;
}
}
}
F_64 ( V_3 , V_68 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
F_52 ( V_3 ,
V_3 -> V_44 . V_73 [ V_41 ] , V_41 ) ;
V_19 = F_45 ( V_3 ,
V_58 , V_42 ,
V_3 -> V_44 . V_73 ) ;
if ( V_19 )
return V_19 ;
return V_19 ;
}
static int F_70 ( struct V_2 * V_3 )
{
int V_41 , V_42 , V_19 ;
T_2 V_70 ;
T_1 V_65 , V_59 [ 2 ] , V_68 [ 2 ] ;
F_18 ( 400 , 401 ) ;
V_42 = V_3 -> V_44 . V_42 ;
V_19 = F_28 ( V_3 ,
V_78 , 2 , V_59 ) ;
if ( V_19 )
return V_19 ;
if ( F_48 ( V_59 , V_42 ) ) {
F_63 ( V_3 ) ;
return - V_23 ;
}
V_19 = F_28 ( V_3 ,
V_79 , 2 , V_68 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_24 ( V_3 ,
V_84 , & V_65 ) ;
if ( V_19 )
return V_19 ;
F_64 ( V_3 , V_68 ) ;
if ( ! F_49 ( V_59 , V_65 , V_42 ) ) {
F_35 ( V_3 ) ;
F_26 ( V_3 -> V_10 , L_10 ) ;
F_71 ( V_3 , & V_70 ) ;
V_3 -> V_44 . V_49 = V_70 ;
F_22 ( V_3 -> V_10 , L_11 ,
V_3 -> V_44 . V_49 ) ;
F_72 ( V_3 , & V_70 ) ;
V_3 -> V_44 . V_42 = V_70 ;
F_22 ( V_3 -> V_10 , L_12 ,
V_3 -> V_44 . V_42 ) ;
F_33 ( V_3 ) ;
V_3 -> V_44 . V_45 = V_85 ;
return 0 ;
}
V_3 -> V_44 . V_47 ++ ;
if ( V_3 -> V_44 . V_47 > V_86 ) {
F_17 ( V_3 -> V_10 , L_13 ) ;
F_63 ( V_3 ) ;
return - V_23 ;
}
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
F_52 ( V_3 ,
V_3 -> V_44 . V_73 [ V_41 ] , V_41 ) ;
V_19 = F_45 ( V_3 , V_58 ,
V_42 , V_3 -> V_44 . V_73 ) ;
return V_19 ;
}
static void F_73 ( struct V_2 * V_3 ,
T_1 * V_87 )
{
T_1 V_33 ;
F_24 ( V_3 , V_88 , & V_33 ) ;
* V_87 = V_33 ;
}
static void F_74 ( struct V_2 * V_3 ,
T_1 * V_42 )
{
T_1 V_33 ;
F_24 ( V_3 , V_36 , & V_33 ) ;
* V_42 = F_75 ( V_33 ) ;
}
static void F_76 ( struct V_2 * V_3 ,
enum V_89 V_90 ,
enum V_91 V_92 )
{
F_77 ( V_3 ) ;
F_73 ( V_3 , & V_3 -> V_44 . V_49 ) ;
F_74 ( V_3 , & V_3 -> V_44 . V_42 ) ;
if ( ( V_3 -> V_44 . V_49 != V_93 ) &&
( V_3 -> V_44 . V_49 != V_94 ) ) {
F_17 ( V_3 -> V_10 , L_14 ,
V_3 -> V_44 . V_49 ) ;
V_3 -> V_44 . V_49 = V_93 ;
}
if ( V_3 -> V_44 . V_42 == 0 ) {
F_17 ( V_3 -> V_10 , L_15 ,
V_3 -> V_44 . V_42 ) ;
V_3 -> V_44 . V_42 = ( T_1 ) V_95 ;
}
if ( V_3 -> V_44 . V_42 > V_90 )
V_3 -> V_44 . V_42 = V_90 ;
if ( V_3 -> V_44 . V_49 > V_92 )
V_3 -> V_44 . V_49 = V_92 ;
F_78 ( V_3 , V_96 , 0 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_19 = 0 , V_97 = 0 ;
V_3 -> V_44 . V_45 = V_98 ;
while ( ! V_19 && ! V_97 ) {
switch ( V_3 -> V_44 . V_45 ) {
case V_98 :
V_19 = F_42 ( V_3 ) ;
if ( V_19 )
F_17 ( V_3 -> V_10 , L_16 ) ;
break;
case V_46 :
V_19 = F_67 ( V_3 ) ;
if ( V_19 )
F_17 ( V_3 -> V_10 , L_17 ) ;
break;
case V_82 :
V_19 = F_70 ( V_3 ) ;
if ( V_19 )
F_17 ( V_3 -> V_10 , L_18 ) ;
break;
case V_85 :
V_97 = 1 ;
break;
case V_71 :
return - V_99 ;
}
}
if ( V_19 )
F_17 ( V_3 -> V_10 , L_19 , V_19 ) ;
return V_19 ;
}
static int F_80 ( struct V_2 * V_3 ,
T_2 V_100 ,
T_2 V_101 )
{
int V_13 ;
int V_19 ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ ) {
F_76 ( V_3 , V_100 , V_101 ) ;
V_19 = F_79 ( V_3 ) ;
if ( V_19 == 0 )
break;
F_18 ( 100 , 110 ) ;
}
return V_19 ;
}
static int F_81 ( struct V_2 * V_3 )
{
int V_19 = 0 ;
int V_8 = 0 ;
int V_102 = 0 ;
F_82 ( V_3 ) ;
F_83 ( V_3 ) ;
if ( F_46 ( V_3 ) == V_52 ) {
F_17 ( V_3 -> V_10 , L_20 ) ;
return - V_64 ;
}
for (; ; ) {
V_8 ++ ;
if ( F_84 ( V_3 ) == 0 )
break;
if ( V_9 < V_8 ) {
F_17 ( V_3 -> V_10 , L_21 ) ;
return - V_11 ;
}
F_18 ( 1 , 2 ) ;
}
F_85 ( V_3 , V_103 , 0 , 0 ) ;
F_86 ( V_3 , V_104 ) ;
F_87 ( V_3 , 0 ) ;
F_88 ( V_3 , 0 ) ;
V_8 = 0 ;
for (; ; ) {
V_8 ++ ;
if ( F_89 ( V_3 ) == 0 ) {
V_102 ++ ;
if ( V_102 > 10 )
break;
} else if ( V_102 ) {
V_102 = 0 ;
}
if ( V_9 < V_8 ) {
F_17 ( V_3 -> V_10 , L_21 ) ;
return - V_11 ;
}
F_18 ( 1000 , 1001 ) ;
}
if ( V_19 != 0 )
F_17 ( V_3 -> V_10 , L_22 ) ;
return V_19 ;
}
static void F_90 ( struct V_2 * V_3 , bool V_32 )
{
T_1 V_33 ;
if ( V_32 ) {
F_91 ( V_3 ) ;
F_24 ( V_3 ,
V_38 ,
& V_33 ) ;
F_25 ( V_3 ,
V_38 ,
( T_1 ) ( V_33 & ~ V_54 ) ) ;
} else {
F_92 ( V_3 ) ;
F_24 ( V_3 ,
V_38 ,
& V_33 ) ;
F_25 ( V_3 ,
V_38 ,
( T_1 ) ( V_33 | V_54 ) ) ;
}
}
static T_3 F_93 ( int V_105 , void * V_106 )
{
struct V_2 * V_3 = V_106 ;
enum V_107 V_108 ;
V_108 = F_94 ( V_3 ) ;
switch ( V_108 ) {
case V_109 :
F_22 ( V_3 -> V_10 , L_23 ) ;
F_95 ( & V_3 -> V_110 ) ;
F_96 ( V_3 ) ;
break;
case V_111 :
F_22 ( V_3 -> V_10 , L_24 ) ;
F_96 ( V_3 ) ;
break;
case V_112 :
F_22 ( V_3 -> V_10 , L_25 ) ;
F_96 ( V_3 ) ;
break;
default:
F_17 ( V_3 -> V_10 , L_26 ) ;
break;
}
return V_113 ;
}
static void F_97 ( struct V_114 * V_115 )
{
struct V_2 * V_3 ;
V_3 = F_4 ( V_115 , struct V_2 , V_110 ) ;
if ( V_3 -> V_116 )
F_98 ( V_3 -> V_116 ) ;
}
static void F_99 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_3 ( V_4 ) ;
int V_117 ;
if ( V_3 -> V_118 ) {
if ( F_100 ( V_3 -> V_118 ) )
F_101 ( L_27 ) ;
}
V_117 = F_15 ( V_3 ) ;
if ( V_117 ) {
return;
}
V_117 = F_27 ( V_3 ) ;
if ( V_117 ) {
F_17 ( V_3 -> V_10 , L_28 ) ;
return;
}
V_117 = F_80 ( V_3 , V_3 -> V_119 -> V_42 ,
V_3 -> V_119 -> V_49 ) ;
if ( V_117 ) {
F_17 ( V_3 -> V_10 , L_29 ) ;
return;
}
F_90 ( V_3 , 1 ) ;
F_29 ( V_3 , 1 ) ;
F_34 ( V_3 , 1 ) ;
F_44 ( V_3 , V_3 -> V_119 -> V_42 ) ;
F_43 ( V_3 , V_3 -> V_119 -> V_49 ) ;
F_102 ( V_3 ) ;
V_117 = F_81 ( V_3 ) ;
if ( V_117 )
F_17 ( V_3 -> V_10 , L_30 ) ;
if ( V_3 -> V_118 ) {
if ( F_103 ( V_3 -> V_118 ) )
F_101 ( L_31 ) ;
}
F_104 ( V_3 ) ;
}
static enum V_120 F_105 (
struct V_121 * V_122 , bool V_123 )
{
return V_124 ;
}
static void F_106 ( struct V_121 * V_122 )
{
F_107 ( V_122 ) ;
F_108 ( V_122 ) ;
}
static int F_109 ( struct V_121 * V_122 )
{
struct V_2 * V_3 = F_110 ( V_122 ) ;
struct V_125 * V_126 ;
if ( V_3 -> V_118 )
return F_111 ( V_3 -> V_118 ) ;
V_126 = F_112 ( V_122 -> V_10 ) ;
if ( ! V_126 ) {
F_101 ( L_32 ) ;
return 0 ;
}
F_113 ( & V_3 -> V_127 . V_128 , V_126 ) ;
V_126 -> V_129 = V_3 -> V_127 . V_129 ;
V_126 -> V_130 = V_3 -> V_127 . V_130 ;
V_122 -> V_131 . V_129 = V_126 -> V_129 ;
V_122 -> V_131 . V_130 = V_126 -> V_130 ;
V_126 -> type = V_132 | V_133 ;
F_114 ( V_126 ) ;
F_115 ( V_122 , V_126 ) ;
return 1 ;
}
static struct V_6 * F_116 (
struct V_121 * V_122 )
{
struct V_2 * V_3 = F_110 ( V_122 ) ;
return & V_3 -> V_4 ;
}
static int F_117 ( struct V_2 * V_3 ,
struct V_6 * V_4 )
{
int V_117 ;
V_4 -> V_134 -> V_135 = V_3 -> V_136 ;
V_3 -> V_136 -> V_4 = V_4 ;
V_117 = F_118 ( V_4 -> V_10 , V_3 -> V_136 ) ;
if ( V_117 ) {
F_101 ( L_33 ) ;
return V_117 ;
}
return 0 ;
}
static int F_119 ( struct V_137 * V_134 )
{
struct V_2 * V_3 = V_134 -> V_138 ;
struct V_6 * V_4 = & V_3 -> V_4 ;
struct V_121 * V_122 = & V_3 -> V_122 ;
int V_117 ;
if ( V_3 -> V_136 ) {
V_117 = F_117 ( V_3 , V_4 ) ;
if ( ! V_117 )
return 0 ;
}
V_122 -> V_139 = V_140 ;
V_117 = F_120 ( V_3 -> V_116 , V_122 ,
& V_141 , V_142 ) ;
if ( V_117 ) {
F_101 ( L_34 ) ;
return V_117 ;
}
F_121 ( V_122 , & V_143 ) ;
F_122 ( V_122 ) ;
F_123 ( V_122 , V_4 ) ;
if ( V_3 -> V_118 )
V_117 = F_124 ( V_3 -> V_118 , & V_3 -> V_122 ) ;
return V_117 ;
}
static void F_125 ( struct V_137 * V_134 )
{
struct V_2 * V_3 = V_134 -> V_138 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_3 -> V_144 == V_145 )
return;
F_126 ( V_3 -> V_10 ) ;
if ( V_3 -> V_118 ) {
if ( F_127 ( V_3 -> V_118 ) ) {
F_101 ( L_35 ) ;
return;
}
}
if ( V_5 -> V_146 -> V_147 )
V_5 -> V_146 -> V_147 ( F_1 ( V_3 ) , true ) ;
F_128 ( V_3 -> V_148 ) ;
F_5 ( V_3 ) ;
F_129 ( V_3 -> V_105 ) ;
F_99 ( & V_3 -> V_4 ) ;
V_3 -> V_144 = V_145 ;
}
static void F_130 ( struct V_137 * V_134 )
{
struct V_2 * V_3 = V_134 -> V_138 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_3 -> V_144 != V_145 )
return;
if ( V_3 -> V_118 ) {
if ( F_100 ( V_3 -> V_118 ) ) {
F_101 ( L_27 ) ;
return;
}
}
F_131 ( V_3 -> V_105 ) ;
F_132 ( & V_3 -> V_110 ) ;
F_133 ( V_3 -> V_148 ) ;
if ( V_5 -> V_146 -> V_147 )
V_5 -> V_146 -> V_147 ( F_1 ( V_3 ) , false ) ;
if ( V_3 -> V_118 ) {
if ( F_134 ( V_3 -> V_118 ) )
F_101 ( L_36 ) ;
}
F_135 ( V_3 -> V_10 ) ;
V_3 -> V_144 = V_149 ;
}
static void F_136 ( struct V_137 * V_134 )
{
}
static int F_137 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_3 ( V_4 ) ;
struct V_150 * V_116 = V_3 -> V_116 ;
struct V_137 * V_134 ;
int V_117 ;
V_134 = F_138 ( V_116 -> V_10 , sizeof( * V_134 ) , V_151 ) ;
if ( ! V_134 ) {
F_101 ( L_37 ) ;
return - V_152 ;
}
V_3 -> V_134 = V_134 ;
V_4 -> V_134 = V_134 ;
V_134 -> V_138 = V_3 ;
V_134 -> V_4 = V_4 ;
V_134 -> V_153 = & V_154 ;
V_117 = F_118 ( V_116 , V_134 ) ;
if ( V_117 ) {
F_101 ( L_38 ) ;
return - V_64 ;
}
return 0 ;
}
static bool F_139 ( struct V_6 * V_4 ,
const struct V_125 * V_126 ,
struct V_125 * V_155 )
{
return true ;
}
static void F_140 ( struct V_6 * V_4 ,
struct V_125 * V_126 ,
struct V_125 * V_155 )
{
}
static void F_141 ( struct V_6 * V_4 )
{
}
static void F_142 ( struct V_6 * V_4 )
{
}
static struct V_119 * F_143 ( struct V_156 * V_10 )
{
struct V_157 * V_158 = V_10 -> V_159 ;
struct V_119 * V_160 ;
V_160 = F_138 ( V_10 ,
sizeof( * V_160 ) , V_151 ) ;
if ( ! V_160 )
return F_144 ( - V_152 ) ;
V_160 -> V_161 =
F_145 ( V_158 , L_39 ) ;
V_160 -> V_162 =
F_145 ( V_158 , L_40 ) ;
V_160 -> V_163 =
F_145 ( V_158 , L_41 ) ;
if ( F_146 ( V_158 , L_42 ,
& V_160 -> V_164 ) ) {
F_17 ( V_10 , L_43 ) ;
return F_144 ( - V_64 ) ;
}
if ( F_146 ( V_158 , L_44 ,
& V_160 -> V_165 ) ) {
F_17 ( V_10 , L_45 ) ;
return F_144 ( - V_64 ) ;
}
if ( F_146 ( V_158 , L_46 ,
& V_160 -> V_166 ) ) {
F_17 ( V_10 , L_47 ) ;
return F_144 ( - V_64 ) ;
}
if ( F_146 ( V_158 , L_48 ,
& V_160 -> V_167 ) ) {
F_17 ( V_10 , L_49 ) ;
return F_144 ( - V_64 ) ;
}
if ( F_146 ( V_158 , L_50 ,
& V_160 -> V_49 ) ) {
F_17 ( V_10 , L_51 ) ;
return F_144 ( - V_64 ) ;
}
if ( F_146 ( V_158 , L_52 ,
& V_160 -> V_42 ) ) {
F_17 ( V_10 , L_53 ) ;
return F_144 ( - V_64 ) ;
}
return V_160 ;
}
static int F_147 ( struct V_2 * V_3 )
{
int V_117 ;
V_117 = F_148 ( V_3 -> V_10 -> V_159 , & V_3 -> V_127 . V_128 ,
V_168 ) ;
if ( V_117 ) {
F_101 ( L_54 , V_117 ) ;
return V_117 ;
}
return 0 ;
}
static int F_149 ( struct V_156 * V_10 , struct V_156 * V_169 , void * V_33 )
{
struct V_2 * V_3 = F_150 ( V_10 ) ;
struct V_170 * V_171 = F_151 ( V_10 ) ;
struct V_150 * V_116 = V_33 ;
struct V_6 * V_4 = & V_3 -> V_4 ;
struct V_172 * V_173 ;
unsigned int V_174 ;
int V_175 , V_117 = 0 ;
V_3 -> V_10 = & V_171 -> V_10 ;
V_3 -> V_144 = V_149 ;
V_3 -> V_119 = F_143 ( & V_171 -> V_10 ) ;
if ( F_152 ( V_3 -> V_119 ) )
return F_153 ( V_3 -> V_119 ) ;
V_3 -> V_148 = F_154 ( V_3 -> V_10 , L_55 ) ;
if ( F_152 ( V_3 -> V_148 ) ) {
F_17 ( V_3 -> V_10 , L_56 ) ;
V_117 = F_153 ( V_3 -> V_148 ) ;
if ( V_117 ) {
if ( V_117 == - V_176 || V_117 == - V_177 )
V_3 -> V_148 = NULL ;
else
return V_117 ;
}
}
if ( ! V_3 -> V_118 && ! V_3 -> V_136 ) {
V_117 = F_147 ( V_3 ) ;
if ( V_117 )
return V_117 ;
}
V_3 -> clock = F_155 ( & V_171 -> V_10 , L_55 ) ;
if ( F_152 ( V_3 -> clock ) ) {
F_17 ( & V_171 -> V_10 , L_57 ) ;
return F_153 ( V_3 -> clock ) ;
}
F_156 ( V_3 -> clock ) ;
V_173 = F_157 ( V_171 , V_178 , 0 ) ;
V_3 -> V_179 = F_158 ( & V_171 -> V_10 , V_173 ) ;
if ( F_152 ( V_3 -> V_179 ) )
return F_153 ( V_3 -> V_179 ) ;
V_3 -> V_180 = F_159 ( V_10 -> V_159 , L_58 , 0 ) ;
if ( F_160 ( V_3 -> V_180 ) ) {
V_117 = F_161 ( & V_171 -> V_10 , V_3 -> V_180 , V_181 ,
L_59 ) ;
if ( V_117 ) {
F_17 ( & V_171 -> V_10 , L_60 ) ;
return V_117 ;
}
V_3 -> V_105 = F_162 ( V_3 -> V_180 ) ;
V_174 = V_182 | V_183 ;
} else {
V_3 -> V_180 = - V_177 ;
V_3 -> V_105 = F_163 ( V_171 , 0 ) ;
V_174 = 0 ;
}
if ( V_3 -> V_105 == - V_184 ) {
F_17 ( & V_171 -> V_10 , L_61 ) ;
return - V_177 ;
}
F_164 ( & V_3 -> V_110 , F_97 ) ;
V_117 = F_165 ( & V_171 -> V_10 , V_3 -> V_105 , F_93 ,
V_174 , L_62 , V_3 ) ;
if ( V_117 ) {
F_17 ( & V_171 -> V_10 , L_63 ) ;
return V_117 ;
}
F_131 ( V_3 -> V_105 ) ;
V_3 -> V_116 = V_116 ;
V_175 = F_166 ( V_116 ,
V_185 ) ;
if ( V_175 < 0 )
return V_175 ;
V_4 -> V_186 = 1 << V_175 ;
F_167 ( L_64 , V_4 -> V_186 ) ;
F_168 ( V_116 , V_4 , & V_187 ,
V_188 , NULL ) ;
F_169 ( V_4 , & V_189 ) ;
V_117 = F_137 ( V_4 ) ;
if ( V_117 ) {
F_101 ( L_65 , V_117 ) ;
F_170 ( V_4 ) ;
return V_117 ;
}
return 0 ;
}
static void F_171 ( struct V_156 * V_10 , struct V_156 * V_169 ,
void * V_33 )
{
struct V_2 * V_3 = F_150 ( V_10 ) ;
F_142 ( & V_3 -> V_4 ) ;
}
static int F_172 ( struct V_170 * V_171 )
{
struct V_156 * V_10 = & V_171 -> V_10 ;
struct V_157 * V_190 = NULL , * V_191 = NULL ;
struct V_2 * V_3 ;
int V_117 ;
V_3 = F_138 ( & V_171 -> V_10 , sizeof( struct V_2 ) ,
V_151 ) ;
if ( ! V_3 )
return - V_152 ;
F_173 ( V_171 , V_3 ) ;
V_190 = F_174 ( V_10 -> V_159 , L_66 , 0 ) ;
if ( V_190 ) {
V_3 -> V_118 = F_175 ( V_190 ) ;
F_176 ( V_190 ) ;
if ( ! V_3 -> V_118 )
return - V_192 ;
goto V_193;
}
V_191 = F_177 ( V_10 -> V_159 , NULL ) ;
if ( V_191 ) {
V_190 = F_178 ( V_191 ) ;
if ( V_190 ) {
V_3 -> V_118 = F_175 ( V_190 ) ;
if ( ! V_3 -> V_118 ) {
V_3 -> V_136 = F_179 ( V_190 ) ;
if ( ! V_3 -> V_136 ) {
F_176 ( V_190 ) ;
return - V_192 ;
}
}
F_176 ( V_190 ) ;
} else {
F_101 ( L_67 ) ;
return - V_64 ;
}
} else {
F_101 ( L_68 ) ;
return - V_64 ;
}
V_193:
F_180 ( V_10 ) ;
V_117 = F_181 ( & V_171 -> V_10 , & V_194 ) ;
if ( V_117 )
goto V_195;
return V_117 ;
V_195:
F_182 ( V_10 ) ;
return V_117 ;
}
static int F_183 ( struct V_170 * V_171 )
{
F_182 ( & V_171 -> V_10 ) ;
F_184 ( & V_171 -> V_10 , & V_194 ) ;
return 0 ;
}
static int F_185 ( struct V_156 * V_10 )
{
struct V_2 * V_3 = F_150 ( V_10 ) ;
F_186 ( V_3 -> clock ) ;
return 0 ;
}
static int F_187 ( struct V_156 * V_10 )
{
struct V_2 * V_3 = F_150 ( V_10 ) ;
int V_117 ;
V_117 = F_156 ( V_3 -> clock ) ;
if ( V_117 < 0 ) {
F_101 ( L_69 , V_117 ) ;
return V_117 ;
}
return 0 ;
}
