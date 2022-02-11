static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 -> V_5 ) ;
}
static inline struct V_2 *
F_3 ( struct V_6 * V_7 )
{
return F_4 ( V_7 , struct V_2 , V_8 ) ;
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
int V_9 = 0 ;
while ( F_16 ( V_3 ) != 0 ) {
V_9 ++ ;
if ( V_10 < V_9 ) {
F_17 ( V_3 -> V_11 , L_1 ) ;
return - V_12 ;
}
F_18 ( 10 , 11 ) ;
}
return 0 ;
}
static unsigned char F_19 ( unsigned char * V_13 )
{
int V_14 ;
unsigned char V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ )
V_15 = V_15 + V_13 [ V_14 ] ;
return V_15 ;
}
static int F_20 ( struct V_2 * V_3 )
{
unsigned char V_17 [ V_16 * 2 ] ;
unsigned int V_18 = 0 ;
unsigned char V_15 ;
unsigned char V_19 ;
int V_20 ;
V_20 = F_21 ( V_3 , V_21 ,
V_22 ,
& V_18 ) ;
if ( V_20 )
return V_20 ;
if ( V_18 > 0 ) {
F_22 ( V_3 -> V_11 , L_2 ) ;
V_20 = F_23 ( V_3 , V_21 ,
V_23 ,
V_16 ,
& V_17 [ V_23 ] ) ;
if ( V_20 != 0 ) {
F_17 ( V_3 -> V_11 , L_3 ) ;
return - V_24 ;
}
V_15 = F_19 ( V_17 ) ;
if ( V_15 != 0 ) {
F_17 ( V_3 -> V_11 , L_4 ) ;
return - V_24 ;
}
V_20 = F_23 ( V_3 ,
V_21 ,
V_16 ,
V_16 ,
& V_17 [ V_16 ] ) ;
if ( V_20 != 0 ) {
F_17 ( V_3 -> V_11 , L_3 ) ;
return - V_24 ;
}
V_15 = F_19 ( & V_17 [ V_16 ] ) ;
if ( V_15 != 0 ) {
F_17 ( V_3 -> V_11 , L_4 ) ;
return - V_24 ;
}
F_24 ( V_3 , V_25 ,
& V_19 ) ;
if ( V_19 & V_26 ) {
F_25 ( V_3 ,
V_27 ,
V_17 [ V_16 + V_28 ] ) ;
F_25 ( V_3 ,
V_29 ,
V_30 ) ;
}
} else {
F_26 ( V_3 -> V_11 , L_5 ) ;
V_20 = F_23 ( V_3 ,
V_21 ,
V_23 ,
V_16 ,
& V_17 [ V_23 ] ) ;
if ( V_20 != 0 ) {
F_17 ( V_3 -> V_11 , L_3 ) ;
return - V_24 ;
}
V_15 = F_19 ( V_17 ) ;
if ( V_15 != 0 ) {
F_17 ( V_3 -> V_11 , L_4 ) ;
return - V_24 ;
}
F_24 ( V_3 ,
V_25 ,
& V_19 ) ;
if ( V_19 & V_26 ) {
F_25 ( V_3 ,
V_27 ,
V_17 [ V_28 ] ) ;
F_25 ( V_3 ,
V_29 ,
V_30 ) ;
}
}
F_22 ( V_3 -> V_11 , L_6 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
T_1 V_31 [ 12 ] ;
int V_14 ;
int V_20 ;
V_20 = F_28 ( V_3 , V_32 ,
12 , V_31 ) ;
if ( V_20 )
return V_20 ;
for ( V_14 = 0 ; V_14 < 3 ; V_14 ++ ) {
V_20 = F_20 ( V_3 ) ;
if ( ! V_20 )
break;
}
return V_20 ;
}
static void F_29 ( struct V_2 * V_3 ,
bool V_33 )
{
T_1 V_34 ;
F_24 ( V_3 , V_35 , & V_34 ) ;
if ( V_33 )
F_25 ( V_3 , V_35 ,
V_36 |
F_30 ( V_34 ) ) ;
else
F_25 ( V_3 , V_35 ,
F_30 ( V_34 ) ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
T_1 V_34 ;
int V_20 ;
F_24 ( V_3 , V_37 , & V_34 ) ;
V_20 = F_32 ( V_34 ) ;
return V_20 ;
}
static void F_33 ( struct V_2 * V_3 )
{
T_1 V_34 ;
V_34 = F_31 ( V_3 ) ;
F_29 ( V_3 , V_34 ) ;
F_34 ( V_3 , V_34 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
F_36 ( V_3 , V_38 ) ;
F_25 ( V_3 ,
V_39 ,
V_40 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
int V_41 , int V_42 )
{
switch ( V_42 ) {
case 0 :
F_38 ( V_3 , V_41 ) ;
break;
case 1 :
F_39 ( V_3 , V_41 ) ;
break;
case 2 :
F_40 ( V_3 , V_41 ) ;
break;
case 3 :
F_41 ( V_3 , V_41 ) ;
break;
}
}
static int F_42 ( struct V_2 * V_3 )
{
T_1 V_31 [ 4 ] ;
int V_42 , V_43 , V_44 , V_20 ;
V_43 = V_3 -> V_45 . V_43 ;
V_3 -> V_45 . V_46 = V_47 ;
V_3 -> V_45 . V_48 = 0 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
V_3 -> V_45 . V_49 [ V_42 ] = 0 ;
F_43 ( V_3 , V_3 -> V_45 . V_50 ) ;
F_44 ( V_3 , V_3 -> V_45 . V_43 ) ;
V_31 [ 0 ] = V_3 -> V_45 . V_50 ;
V_31 [ 1 ] = V_3 -> V_45 . V_43 ;
V_20 = F_45 ( V_3 , V_51 ,
2 , V_31 ) ;
if ( V_20 )
return V_20 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
F_37 ( V_3 ,
V_52 , V_42 ) ;
V_44 = 0 ;
while ( F_46 ( V_3 ) == V_53 ) {
if ( V_44 == V_10 ) {
F_17 ( V_3 -> V_11 , L_7 ) ;
return - V_12 ;
}
V_44 ++ ;
F_18 ( 90 , 120 ) ;
}
F_36 ( V_3 , V_54 ) ;
V_20 = F_25 ( V_3 ,
V_39 ,
V_55 | V_56 ) ;
if ( V_20 )
return V_20 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
V_31 [ V_42 ] = V_57 |
V_58 ;
V_20 = F_45 ( V_3 , V_59 ,
V_43 , V_31 ) ;
return V_20 ;
}
static unsigned char F_47 ( T_1 V_60 [ 2 ] , int V_42 )
{
int V_61 = ( V_42 & 1 ) * 4 ;
T_1 V_62 = V_60 [ V_42 >> 1 ] ;
return ( V_62 >> V_61 ) & 0xf ;
}
static int F_48 ( T_1 V_60 [ 2 ] , int V_43 )
{
int V_42 ;
T_1 V_63 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_63 = F_47 ( V_60 , V_42 ) ;
if ( ( V_63 & V_64 ) == 0 )
return - V_65 ;
}
return 0 ;
}
static int F_49 ( T_1 V_60 [ 2 ] , T_1 V_66 ,
int V_43 )
{
int V_42 ;
T_1 V_63 ;
if ( ( V_66 & V_67 ) == 0 )
return - V_65 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_63 = F_47 ( V_60 , V_42 ) ;
V_63 &= V_68 ;
if ( V_63 != V_68 )
return - V_65 ;
}
return 0 ;
}
static unsigned char F_50 ( T_1 V_69 [ 2 ] ,
int V_42 )
{
int V_61 = ( V_42 & 1 ) * 4 ;
T_1 V_62 = V_69 [ V_42 >> 1 ] ;
return ( V_62 >> V_61 ) & 0x3 ;
}
static unsigned char F_51 (
T_1 V_69 [ 2 ] ,
int V_42 )
{
int V_61 = ( V_42 & 1 ) * 4 ;
T_1 V_62 = V_69 [ V_42 >> 1 ] ;
return ( ( V_62 >> V_61 ) & 0xc ) >> 2 ;
}
static void F_52 ( struct V_2 * V_3 ,
T_1 V_70 , int V_42 )
{
switch ( V_42 ) {
case 0 :
F_53 ( V_3 , V_70 ) ;
break;
case 1 :
F_54 ( V_3 , V_70 ) ;
break;
case 2 :
F_55 ( V_3 , V_70 ) ;
break;
case 3 :
F_56 ( V_3 , V_70 ) ;
break;
}
}
static unsigned int F_57 (
struct V_2 * V_3 ,
int V_42 )
{
T_2 V_71 ;
switch ( V_42 ) {
case 0 :
V_71 = F_58 ( V_3 ) ;
break;
case 1 :
V_71 = F_59 ( V_3 ) ;
break;
case 2 :
V_71 = F_60 ( V_3 ) ;
break;
case 3 :
V_71 = F_61 ( V_3 ) ;
break;
default:
F_62 ( 1 ) ;
return 0 ;
}
return V_71 ;
}
static void F_63 ( struct V_2 * V_3 )
{
F_35 ( V_3 ) ;
F_33 ( V_3 ) ;
V_3 -> V_45 . V_46 = V_72 ;
}
static void F_64 ( struct V_2 * V_3 ,
T_1 V_69 [ 2 ] )
{
int V_42 , V_43 ;
T_1 V_73 , V_41 , V_74 ;
V_43 = V_3 -> V_45 . V_43 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_73 = F_50 (
V_69 , V_42 ) ;
V_41 = F_51 (
V_69 , V_42 ) ;
V_74 = F_65 ( V_73 ) |
F_66 ( V_41 ) ;
if ( V_73 == V_75 )
V_74 |= V_76 ;
if ( V_41 == V_77 )
V_74 |= V_78 ;
V_3 -> V_45 . V_74 [ V_42 ] = V_74 ;
}
}
static int F_67 ( struct V_2 * V_3 )
{
int V_42 , V_43 , V_20 ;
T_1 V_73 , V_41 , V_74 ;
T_1 V_60 [ 2 ] , V_69 [ 2 ] ;
F_18 ( 100 , 101 ) ;
V_43 = V_3 -> V_45 . V_43 ;
V_20 = F_28 ( V_3 ,
V_79 , 2 , V_60 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_28 ( V_3 ,
V_80 , 2 , V_69 ) ;
if ( V_20 )
return V_20 ;
if ( F_48 ( V_60 , V_43 ) == 0 ) {
F_36 ( V_3 , V_81 ) ;
V_20 = F_25 ( V_3 ,
V_39 ,
V_55 |
V_82 ) ;
if ( V_20 )
return V_20 ;
F_26 ( V_3 -> V_11 , L_8 ) ;
V_3 -> V_45 . V_46 = V_83 ;
} else {
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_74 = F_57 (
V_3 , V_42 ) ;
V_73 = F_50 (
V_69 , V_42 ) ;
V_41 = F_51 (
V_69 , V_42 ) ;
if ( F_68 ( V_74 ) ==
V_73 &&
F_69 ( V_74 ) ==
V_41 )
V_3 -> V_45 . V_49 [ V_42 ] ++ ;
if ( V_3 -> V_45 . V_49 [ V_42 ] == V_84 ||
V_73 == V_75 ||
V_41 == V_77 ) {
F_17 ( V_3 -> V_11 , L_9 ,
V_3 -> V_45 . V_49 [ V_42 ] ,
V_73 , V_41 ) ;
F_63 ( V_3 ) ;
return - V_24 ;
}
}
}
F_64 ( V_3 , V_69 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
F_52 ( V_3 ,
V_3 -> V_45 . V_74 [ V_42 ] , V_42 ) ;
V_20 = F_45 ( V_3 ,
V_59 , V_43 ,
V_3 -> V_45 . V_74 ) ;
if ( V_20 )
return V_20 ;
return V_20 ;
}
static int F_70 ( struct V_2 * V_3 )
{
int V_42 , V_43 , V_20 ;
T_2 V_71 ;
T_1 V_66 , V_60 [ 2 ] , V_69 [ 2 ] ;
F_18 ( 400 , 401 ) ;
V_43 = V_3 -> V_45 . V_43 ;
V_20 = F_28 ( V_3 ,
V_79 , 2 , V_60 ) ;
if ( V_20 )
return V_20 ;
if ( F_48 ( V_60 , V_43 ) ) {
F_63 ( V_3 ) ;
return - V_24 ;
}
V_20 = F_28 ( V_3 ,
V_80 , 2 , V_69 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_24 ( V_3 ,
V_85 , & V_66 ) ;
if ( V_20 )
return V_20 ;
F_64 ( V_3 , V_69 ) ;
if ( ! F_49 ( V_60 , V_66 , V_43 ) ) {
F_35 ( V_3 ) ;
F_26 ( V_3 -> V_11 , L_10 ) ;
F_71 ( V_3 , & V_71 ) ;
V_3 -> V_45 . V_50 = V_71 ;
F_22 ( V_3 -> V_11 , L_11 ,
V_3 -> V_45 . V_50 ) ;
F_72 ( V_3 , & V_71 ) ;
V_3 -> V_45 . V_43 = V_71 ;
F_22 ( V_3 -> V_11 , L_12 ,
V_3 -> V_45 . V_43 ) ;
F_33 ( V_3 ) ;
V_3 -> V_45 . V_46 = V_86 ;
return 0 ;
}
V_3 -> V_45 . V_48 ++ ;
if ( V_3 -> V_45 . V_48 > V_87 ) {
F_17 ( V_3 -> V_11 , L_13 ) ;
F_63 ( V_3 ) ;
return - V_24 ;
}
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
F_52 ( V_3 ,
V_3 -> V_45 . V_74 [ V_42 ] , V_42 ) ;
V_20 = F_45 ( V_3 , V_59 ,
V_43 , V_3 -> V_45 . V_74 ) ;
return V_20 ;
}
static void F_73 ( struct V_2 * V_3 ,
T_1 * V_88 )
{
T_1 V_34 ;
F_24 ( V_3 , V_89 , & V_34 ) ;
* V_88 = V_34 ;
}
static void F_74 ( struct V_2 * V_3 ,
T_1 * V_43 )
{
T_1 V_34 ;
F_24 ( V_3 , V_37 , & V_34 ) ;
* V_43 = F_75 ( V_34 ) ;
}
static void F_76 ( struct V_2 * V_3 ,
enum V_90 V_91 ,
enum V_92 V_93 )
{
F_77 ( V_3 ) ;
F_73 ( V_3 , & V_3 -> V_45 . V_50 ) ;
F_74 ( V_3 , & V_3 -> V_45 . V_43 ) ;
if ( ( V_3 -> V_45 . V_50 != V_94 ) &&
( V_3 -> V_45 . V_50 != V_95 ) ) {
F_17 ( V_3 -> V_11 , L_14 ,
V_3 -> V_45 . V_50 ) ;
V_3 -> V_45 . V_50 = V_94 ;
}
if ( V_3 -> V_45 . V_43 == 0 ) {
F_17 ( V_3 -> V_11 , L_15 ,
V_3 -> V_45 . V_43 ) ;
V_3 -> V_45 . V_43 = ( T_1 ) V_96 ;
}
if ( V_3 -> V_45 . V_43 > V_91 )
V_3 -> V_45 . V_43 = V_91 ;
if ( V_3 -> V_45 . V_50 > V_93 )
V_3 -> V_45 . V_50 = V_93 ;
F_78 ( V_3 , V_97 , 0 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_20 = 0 , V_98 = 0 ;
V_3 -> V_45 . V_46 = V_99 ;
while ( ! V_20 && ! V_98 ) {
switch ( V_3 -> V_45 . V_46 ) {
case V_99 :
V_20 = F_42 ( V_3 ) ;
if ( V_20 )
F_17 ( V_3 -> V_11 , L_16 ) ;
break;
case V_47 :
V_20 = F_67 ( V_3 ) ;
if ( V_20 )
F_17 ( V_3 -> V_11 , L_17 ) ;
break;
case V_83 :
V_20 = F_70 ( V_3 ) ;
if ( V_20 )
F_17 ( V_3 -> V_11 , L_18 ) ;
break;
case V_86 :
V_98 = 1 ;
break;
case V_72 :
return - V_100 ;
}
}
if ( V_20 )
F_17 ( V_3 -> V_11 , L_19 , V_20 ) ;
return V_20 ;
}
static int F_80 ( struct V_2 * V_3 ,
T_2 V_101 ,
T_2 V_102 )
{
int V_14 ;
int V_20 ;
for ( V_14 = 0 ; V_14 < V_10 ; V_14 ++ ) {
F_76 ( V_3 , V_101 , V_102 ) ;
V_20 = F_79 ( V_3 ) ;
if ( V_20 == 0 )
break;
F_18 ( 100 , 110 ) ;
}
return V_20 ;
}
static int F_81 ( struct V_2 * V_3 )
{
int V_20 = 0 ;
int V_9 = 0 ;
int V_103 = 0 ;
F_82 ( V_3 ) ;
F_83 ( V_3 ) ;
if ( F_46 ( V_3 ) == V_53 ) {
F_17 ( V_3 -> V_11 , L_20 ) ;
return - V_65 ;
}
for (; ; ) {
V_9 ++ ;
if ( F_84 ( V_3 ) == 0 )
break;
if ( V_10 < V_9 ) {
F_17 ( V_3 -> V_11 , L_21 ) ;
return - V_12 ;
}
F_18 ( 1 , 2 ) ;
}
F_85 ( V_3 , V_104 , 0 , 0 ) ;
F_86 ( V_3 , V_105 ) ;
F_87 ( V_3 , 0 ) ;
F_88 ( V_3 , 0 ) ;
F_89 ( V_3 ) ;
V_9 = 0 ;
for (; ; ) {
V_9 ++ ;
if ( F_90 ( V_3 ) == 0 ) {
V_103 ++ ;
if ( V_103 > 10 )
break;
} else if ( V_103 ) {
V_103 = 0 ;
}
if ( V_10 < V_9 ) {
F_17 ( V_3 -> V_11 , L_21 ) ;
return - V_12 ;
}
F_18 ( 1000 , 1001 ) ;
}
if ( V_20 != 0 )
F_17 ( V_3 -> V_11 , L_22 ) ;
return V_20 ;
}
static void F_91 ( struct V_2 * V_3 , bool V_33 )
{
T_1 V_34 ;
if ( V_33 ) {
F_92 ( V_3 ) ;
F_24 ( V_3 ,
V_39 ,
& V_34 ) ;
F_25 ( V_3 ,
V_39 ,
( T_1 ) ( V_34 & ~ V_55 ) ) ;
} else {
F_93 ( V_3 ) ;
F_24 ( V_3 ,
V_39 ,
& V_34 ) ;
F_25 ( V_3 ,
V_39 ,
( T_1 ) ( V_34 | V_55 ) ) ;
}
}
static T_3 F_94 ( int V_106 , void * V_107 )
{
struct V_2 * V_3 = V_107 ;
enum V_108 V_109 ;
V_109 = F_95 ( V_3 ) ;
switch ( V_109 ) {
case V_110 :
F_22 ( V_3 -> V_11 , L_23 ) ;
F_96 ( & V_3 -> V_111 ) ;
F_97 ( V_3 ) ;
break;
case V_112 :
F_22 ( V_3 -> V_11 , L_24 ) ;
F_97 ( V_3 ) ;
break;
case V_113 :
F_22 ( V_3 -> V_11 , L_25 ) ;
F_97 ( V_3 ) ;
break;
default:
F_17 ( V_3 -> V_11 , L_26 ) ;
break;
}
return V_114 ;
}
static void F_98 ( struct V_115 * V_116 )
{
struct V_2 * V_3 ;
V_3 = F_4 ( V_116 , struct V_2 , V_111 ) ;
if ( V_3 -> V_117 )
F_99 ( V_3 -> V_117 ) ;
}
static void F_100 ( struct V_6 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
int V_118 ;
if ( V_3 -> V_119 ) {
if ( F_101 ( V_3 -> V_119 ) )
F_102 ( L_27 ) ;
}
V_118 = F_15 ( V_3 ) ;
if ( V_118 ) {
return;
}
V_118 = F_27 ( V_3 ) ;
if ( V_118 ) {
F_17 ( V_3 -> V_11 , L_28 ) ;
return;
}
V_118 = F_80 ( V_3 , V_3 -> V_120 -> V_43 ,
V_3 -> V_120 -> V_50 ) ;
if ( V_118 ) {
F_17 ( V_3 -> V_11 , L_29 ) ;
return;
}
F_91 ( V_3 , 1 ) ;
F_29 ( V_3 , 1 ) ;
F_34 ( V_3 , 1 ) ;
F_44 ( V_3 , V_3 -> V_120 -> V_43 ) ;
F_43 ( V_3 , V_3 -> V_120 -> V_50 ) ;
F_103 ( V_3 ) ;
V_118 = F_81 ( V_3 ) ;
if ( V_118 )
F_17 ( V_3 -> V_11 , L_30 ) ;
if ( V_3 -> V_119 ) {
if ( F_104 ( V_3 -> V_119 ) )
F_102 ( L_31 ) ;
}
}
static enum V_121 F_105 (
struct V_122 * V_123 , bool V_124 )
{
return V_125 ;
}
static void F_106 ( struct V_122 * V_123 )
{
F_107 ( V_123 ) ;
F_108 ( V_123 ) ;
}
static int F_109 ( struct V_122 * V_123 )
{
struct V_2 * V_3 = F_110 ( V_123 ) ;
struct V_126 * V_127 ;
if ( V_3 -> V_119 )
return F_111 ( V_3 -> V_119 ) ;
V_127 = F_112 ( V_123 -> V_11 ) ;
if ( ! V_127 ) {
F_102 ( L_32 ) ;
return 0 ;
}
F_113 ( & V_3 -> V_128 . V_129 , V_127 ) ;
V_127 -> V_130 = V_3 -> V_128 . V_130 ;
V_127 -> V_131 = V_3 -> V_128 . V_131 ;
V_123 -> V_132 . V_130 = V_127 -> V_130 ;
V_123 -> V_132 . V_131 = V_127 -> V_131 ;
V_127 -> type = V_133 | V_134 ;
F_114 ( V_127 ) ;
F_115 ( V_123 , V_127 ) ;
return 1 ;
}
static struct V_135 * F_116 (
struct V_122 * V_123 )
{
struct V_2 * V_3 = F_110 ( V_123 ) ;
return V_3 -> V_4 ;
}
static int F_117 ( struct V_2 * V_3 ,
struct V_135 * V_4 )
{
int V_118 ;
V_4 -> V_136 = V_3 -> V_136 ;
V_3 -> V_136 -> V_4 = V_4 ;
V_118 = F_118 ( V_4 -> V_11 , V_3 -> V_136 ) ;
if ( V_118 ) {
F_102 ( L_33 ) ;
return V_118 ;
}
return 0 ;
}
static int F_119 ( struct V_6 * V_8 ,
struct V_135 * V_4 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_122 * V_123 = & V_3 -> V_123 ;
int V_118 ;
V_3 -> V_4 = V_4 ;
if ( V_3 -> V_136 ) {
V_118 = F_117 ( V_3 , V_4 ) ;
if ( ! V_118 )
return 0 ;
}
V_123 -> V_137 = V_138 ;
V_118 = F_120 ( V_3 -> V_117 , V_123 ,
& V_139 , V_140 ) ;
if ( V_118 ) {
F_102 ( L_34 ) ;
return V_118 ;
}
F_121 ( V_123 , & V_141 ) ;
F_122 ( V_123 ) ;
F_123 ( V_123 , V_4 ) ;
if ( V_3 -> V_119 )
V_118 = F_124 ( V_3 -> V_119 , & V_3 -> V_123 ) ;
return V_118 ;
}
static void F_125 ( struct V_2 * V_3 )
{
if ( V_3 -> V_142 )
F_126 ( V_3 -> V_142 ) ;
}
static void F_127 ( struct V_2 * V_3 )
{
if ( V_3 -> V_142 )
F_128 ( V_3 -> V_142 ) ;
}
static void F_129 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_3 -> V_143 == V_144 )
return;
if ( V_3 -> V_119 ) {
if ( F_130 ( V_3 -> V_119 ) ) {
F_102 ( L_35 ) ;
return;
}
}
if ( V_5 -> V_145 -> V_146 )
V_5 -> V_145 -> V_146 ( F_1 ( V_3 ) , true ) ;
F_131 ( V_3 -> clock ) ;
F_125 ( V_3 ) ;
F_5 ( V_3 ) ;
F_132 ( V_3 -> V_106 ) ;
F_100 ( & V_3 -> V_8 ) ;
}
static void F_133 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_3 -> V_143 != V_144 )
return;
if ( V_3 -> V_119 ) {
if ( F_101 ( V_3 -> V_119 ) ) {
F_102 ( L_27 ) ;
return;
}
}
F_134 ( V_3 -> V_106 ) ;
F_135 ( & V_3 -> V_111 ) ;
F_127 ( V_3 ) ;
F_136 ( V_3 -> clock ) ;
if ( V_5 -> V_145 -> V_146 )
V_5 -> V_145 -> V_146 ( F_1 ( V_3 ) , false ) ;
if ( V_3 -> V_119 ) {
if ( F_137 ( V_3 -> V_119 ) )
F_102 ( L_36 ) ;
}
}
static void F_138 ( struct V_6 * V_8 , int V_127 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
switch ( V_127 ) {
case V_144 :
F_129 ( V_3 ) ;
break;
case V_147 :
case V_148 :
case V_149 :
F_133 ( V_3 ) ;
break;
default:
break;
}
V_3 -> V_143 = V_127 ;
}
static struct V_120 * F_139 ( struct V_150 * V_11 )
{
struct V_151 * V_152 = V_11 -> V_153 ;
struct V_120 * V_154 ;
V_154 = F_140 ( V_11 ,
sizeof( * V_154 ) , V_155 ) ;
if ( ! V_154 )
return F_141 ( - V_156 ) ;
V_154 -> V_157 =
F_142 ( V_152 , L_37 ) ;
V_154 -> V_158 =
F_142 ( V_152 , L_38 ) ;
V_154 -> V_159 =
F_142 ( V_152 , L_39 ) ;
if ( F_143 ( V_152 , L_40 ,
& V_154 -> V_160 ) ) {
F_17 ( V_11 , L_41 ) ;
return F_141 ( - V_65 ) ;
}
if ( F_143 ( V_152 , L_42 ,
& V_154 -> V_161 ) ) {
F_17 ( V_11 , L_43 ) ;
return F_141 ( - V_65 ) ;
}
if ( F_143 ( V_152 , L_44 ,
& V_154 -> V_162 ) ) {
F_17 ( V_11 , L_45 ) ;
return F_141 ( - V_65 ) ;
}
if ( F_143 ( V_152 , L_46 ,
& V_154 -> V_163 ) ) {
F_17 ( V_11 , L_47 ) ;
return F_141 ( - V_65 ) ;
}
if ( F_143 ( V_152 , L_48 ,
& V_154 -> V_50 ) ) {
F_17 ( V_11 , L_49 ) ;
return F_141 ( - V_65 ) ;
}
if ( F_143 ( V_152 , L_50 ,
& V_154 -> V_43 ) ) {
F_17 ( V_11 , L_51 ) ;
return F_141 ( - V_65 ) ;
}
return V_154 ;
}
static int F_144 ( struct V_2 * V_3 )
{
int V_118 ;
V_118 = F_145 ( V_3 -> V_11 -> V_153 , & V_3 -> V_128 . V_129 ,
V_164 ) ;
if ( V_118 ) {
F_102 ( L_52 , V_118 ) ;
return V_118 ;
}
return 0 ;
}
static int F_146 ( struct V_150 * V_11 , struct V_150 * V_165 , void * V_34 )
{
struct V_2 * V_3 = F_147 ( V_11 ) ;
struct V_166 * V_167 = F_148 ( V_11 ) ;
struct V_168 * V_117 = V_34 ;
struct V_169 * V_170 ;
unsigned int V_171 ;
int V_118 = 0 ;
V_3 -> V_11 = & V_167 -> V_11 ;
V_3 -> V_143 = V_149 ;
V_3 -> V_120 = F_139 ( & V_167 -> V_11 ) ;
if ( F_149 ( V_3 -> V_120 ) )
return F_150 ( V_3 -> V_120 ) ;
V_3 -> V_142 = F_151 ( V_3 -> V_11 , L_53 ) ;
if ( F_149 ( V_3 -> V_142 ) ) {
F_17 ( V_3 -> V_11 , L_54 ) ;
V_118 = F_150 ( V_3 -> V_142 ) ;
if ( V_118 ) {
if ( V_118 == - V_172 || V_118 == - V_173 )
V_3 -> V_142 = NULL ;
else
return V_118 ;
}
}
if ( ! V_3 -> V_119 && ! V_3 -> V_136 ) {
V_118 = F_144 ( V_3 ) ;
if ( V_118 )
return V_118 ;
}
V_3 -> clock = F_152 ( & V_167 -> V_11 , L_53 ) ;
if ( F_149 ( V_3 -> clock ) ) {
F_17 ( & V_167 -> V_11 , L_55 ) ;
return F_150 ( V_3 -> clock ) ;
}
F_131 ( V_3 -> clock ) ;
V_170 = F_153 ( V_167 , V_174 , 0 ) ;
V_3 -> V_175 = F_154 ( & V_167 -> V_11 , V_170 ) ;
if ( F_149 ( V_3 -> V_175 ) )
return F_150 ( V_3 -> V_175 ) ;
V_3 -> V_176 = F_155 ( V_11 -> V_153 , L_56 , 0 ) ;
if ( F_156 ( V_3 -> V_176 ) ) {
V_118 = F_157 ( & V_167 -> V_11 , V_3 -> V_176 , V_177 ,
L_57 ) ;
if ( V_118 ) {
F_17 ( & V_167 -> V_11 , L_58 ) ;
return V_118 ;
}
V_3 -> V_106 = F_158 ( V_3 -> V_176 ) ;
V_171 = V_178 | V_179 ;
} else {
V_3 -> V_176 = - V_173 ;
V_3 -> V_106 = F_159 ( V_167 , 0 ) ;
V_171 = 0 ;
}
if ( V_3 -> V_106 == - V_180 ) {
F_17 ( & V_167 -> V_11 , L_59 ) ;
return - V_173 ;
}
F_160 ( & V_3 -> V_111 , F_98 ) ;
F_125 ( V_3 ) ;
F_5 ( V_3 ) ;
V_118 = F_161 ( & V_167 -> V_11 , V_3 -> V_106 , F_94 ,
V_171 , L_60 , V_3 ) ;
if ( V_118 ) {
F_17 ( & V_167 -> V_11 , L_61 ) ;
return V_118 ;
}
F_134 ( V_3 -> V_106 ) ;
V_3 -> V_117 = V_117 ;
return F_162 ( V_117 , & V_3 -> V_8 ) ;
}
static void F_163 ( struct V_150 * V_11 , struct V_150 * V_165 ,
void * V_34 )
{
struct V_2 * V_3 = F_147 ( V_11 ) ;
F_138 ( & V_3 -> V_8 , V_149 ) ;
}
static int F_164 ( struct V_166 * V_167 )
{
struct V_150 * V_11 = & V_167 -> V_11 ;
struct V_151 * V_181 , * V_182 , * V_183 ;
struct V_2 * V_3 ;
int V_118 ;
V_3 = F_140 ( & V_167 -> V_11 , sizeof( struct V_2 ) ,
V_155 ) ;
if ( ! V_3 )
return - V_156 ;
V_3 -> V_8 . type = V_184 ;
V_3 -> V_8 . V_145 = & V_185 ;
F_165 ( V_167 , V_3 ) ;
V_118 = F_166 ( & V_167 -> V_11 , V_186 ,
V_3 -> V_8 . type ) ;
if ( V_118 )
return V_118 ;
V_181 = F_167 ( V_11 -> V_153 , L_62 , 0 ) ;
if ( V_181 ) {
V_3 -> V_119 = F_168 ( V_181 ) ;
F_169 ( V_181 ) ;
if ( ! V_3 -> V_119 )
return - V_187 ;
}
V_183 = F_170 ( V_11 -> V_153 , NULL ) ;
if ( V_183 ) {
V_182 = F_171 ( V_183 ) ;
if ( V_182 ) {
V_3 -> V_136 = F_172 ( V_182 ) ;
F_169 ( V_182 ) ;
if ( ! V_3 -> V_136 )
return - V_187 ;
} else
return - V_187 ;
}
V_118 = F_173 ( & V_167 -> V_11 , & V_188 ) ;
if ( V_118 )
F_174 ( & V_167 -> V_11 ,
V_186 ) ;
return V_118 ;
}
static int F_175 ( struct V_166 * V_167 )
{
F_176 ( & V_167 -> V_11 , & V_188 ) ;
F_174 ( & V_167 -> V_11 , V_186 ) ;
return 0 ;
}
static int F_177 ( struct V_150 * V_11 )
{
struct V_2 * V_3 = F_147 ( V_11 ) ;
F_138 ( & V_3 -> V_8 , V_149 ) ;
return 0 ;
}
static int F_178 ( struct V_150 * V_11 )
{
struct V_2 * V_3 = F_147 ( V_11 ) ;
F_138 ( & V_3 -> V_8 , V_144 ) ;
return 0 ;
}
