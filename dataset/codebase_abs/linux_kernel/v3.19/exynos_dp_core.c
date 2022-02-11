static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 )
{
F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
F_9 ( V_5 ) ;
F_10 ( V_5 ) ;
F_11 ( V_5 ) ;
F_12 ( V_5 ) ;
}
static int F_13 ( struct V_1 * V_5 )
{
int V_6 = 0 ;
while ( F_14 ( V_5 ) != 0 ) {
V_6 ++ ;
if ( V_7 < V_6 ) {
F_15 ( V_5 -> V_8 , L_1 ) ;
return - V_9 ;
}
F_16 ( 10 , 11 ) ;
}
return 0 ;
}
static unsigned char F_17 ( unsigned char * V_10 )
{
int V_11 ;
unsigned char V_12 = 0 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_12 = V_12 + V_10 [ V_11 ] ;
return V_12 ;
}
static int F_18 ( struct V_1 * V_5 )
{
unsigned char V_14 [ V_13 * 2 ] ;
unsigned int V_15 = 0 ;
unsigned char V_12 ;
unsigned char V_16 ;
int V_17 ;
V_17 = F_19 ( V_5 , V_18 ,
V_19 ,
& V_15 ) ;
if ( V_17 )
return V_17 ;
if ( V_15 > 0 ) {
F_20 ( V_5 -> V_8 , L_2 ) ;
V_17 = F_21 ( V_5 , V_18 ,
V_20 ,
V_13 ,
& V_14 [ V_20 ] ) ;
if ( V_17 != 0 ) {
F_15 ( V_5 -> V_8 , L_3 ) ;
return - V_21 ;
}
V_12 = F_17 ( V_14 ) ;
if ( V_12 != 0 ) {
F_15 ( V_5 -> V_8 , L_4 ) ;
return - V_21 ;
}
V_17 = F_21 ( V_5 ,
V_18 ,
V_13 ,
V_13 ,
& V_14 [ V_13 ] ) ;
if ( V_17 != 0 ) {
F_15 ( V_5 -> V_8 , L_3 ) ;
return - V_21 ;
}
V_12 = F_17 ( & V_14 [ V_13 ] ) ;
if ( V_12 != 0 ) {
F_15 ( V_5 -> V_8 , L_4 ) ;
return - V_21 ;
}
F_22 ( V_5 , V_22 ,
& V_16 ) ;
if ( V_16 & V_23 ) {
F_23 ( V_5 ,
V_24 ,
V_14 [ V_13 + V_25 ] ) ;
F_23 ( V_5 ,
V_26 ,
V_27 ) ;
}
} else {
F_24 ( V_5 -> V_8 , L_5 ) ;
V_17 = F_21 ( V_5 ,
V_18 ,
V_20 ,
V_13 ,
& V_14 [ V_20 ] ) ;
if ( V_17 != 0 ) {
F_15 ( V_5 -> V_8 , L_3 ) ;
return - V_21 ;
}
V_12 = F_17 ( V_14 ) ;
if ( V_12 != 0 ) {
F_15 ( V_5 -> V_8 , L_4 ) ;
return - V_21 ;
}
F_22 ( V_5 ,
V_22 ,
& V_16 ) ;
if ( V_16 & V_23 ) {
F_23 ( V_5 ,
V_24 ,
V_14 [ V_25 ] ) ;
F_23 ( V_5 ,
V_26 ,
V_27 ) ;
}
}
F_15 ( V_5 -> V_8 , L_6 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_5 )
{
T_1 V_28 [ 12 ] ;
int V_11 ;
int V_17 ;
V_17 = F_26 ( V_5 , V_29 ,
12 , V_28 ) ;
if ( V_17 )
return V_17 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_17 = F_18 ( V_5 ) ;
if ( ! V_17 )
break;
}
return V_17 ;
}
static void F_27 ( struct V_1 * V_5 ,
bool V_30 )
{
T_1 V_31 ;
F_22 ( V_5 , V_32 , & V_31 ) ;
if ( V_30 )
F_23 ( V_5 , V_32 ,
V_33 |
F_28 ( V_31 ) ) ;
else
F_23 ( V_5 , V_32 ,
F_28 ( V_31 ) ) ;
}
static int F_29 ( struct V_1 * V_5 )
{
T_1 V_31 ;
int V_17 ;
F_22 ( V_5 , V_34 , & V_31 ) ;
V_17 = F_30 ( V_31 ) ;
return V_17 ;
}
static void F_31 ( struct V_1 * V_5 )
{
T_1 V_31 ;
V_31 = F_29 ( V_5 ) ;
F_27 ( V_5 , V_31 ) ;
F_32 ( V_5 , V_31 ) ;
}
static void F_33 ( struct V_1 * V_5 )
{
F_34 ( V_5 , V_35 ) ;
F_23 ( V_5 ,
V_36 ,
V_37 ) ;
}
static void F_35 ( struct V_1 * V_5 ,
int V_38 , int V_39 )
{
switch ( V_39 ) {
case 0 :
F_36 ( V_5 , V_38 ) ;
break;
case 1 :
F_37 ( V_5 , V_38 ) ;
break;
case 2 :
F_38 ( V_5 , V_38 ) ;
break;
case 3 :
F_39 ( V_5 , V_38 ) ;
break;
}
}
static int F_40 ( struct V_1 * V_5 )
{
T_1 V_28 [ 4 ] ;
int V_39 , V_40 , V_41 , V_17 ;
V_40 = V_5 -> V_42 . V_40 ;
V_5 -> V_42 . V_43 = V_44 ;
V_5 -> V_42 . V_45 = 0 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
V_5 -> V_42 . V_46 [ V_39 ] = 0 ;
F_41 ( V_5 , V_5 -> V_42 . V_47 ) ;
F_42 ( V_5 , V_5 -> V_42 . V_40 ) ;
V_28 [ 0 ] = V_5 -> V_42 . V_47 ;
V_28 [ 1 ] = V_5 -> V_42 . V_40 ;
V_17 = F_43 ( V_5 , V_48 ,
2 , V_28 ) ;
if ( V_17 )
return V_17 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_35 ( V_5 ,
V_49 , V_39 ) ;
V_41 = 0 ;
while ( F_44 ( V_5 ) == V_50 ) {
if ( V_41 == V_7 ) {
F_15 ( V_5 -> V_8 , L_7 ) ;
return - V_9 ;
}
V_41 ++ ;
F_16 ( 90 , 120 ) ;
}
F_34 ( V_5 , V_51 ) ;
V_17 = F_23 ( V_5 ,
V_36 ,
V_52 | V_53 ) ;
if ( V_17 )
return V_17 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
V_28 [ V_39 ] = V_54 |
V_55 ;
V_17 = F_43 ( V_5 , V_56 ,
V_40 , V_28 ) ;
return V_17 ;
}
static unsigned char F_45 ( T_1 V_57 [ 2 ] , int V_39 )
{
int V_58 = ( V_39 & 1 ) * 4 ;
T_1 V_59 = V_57 [ V_39 >> 1 ] ;
return ( V_59 >> V_58 ) & 0xf ;
}
static int F_46 ( T_1 V_57 [ 2 ] , int V_40 )
{
int V_39 ;
T_1 V_60 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_60 = F_45 ( V_57 , V_39 ) ;
if ( ( V_60 & V_61 ) == 0 )
return - V_62 ;
}
return 0 ;
}
static int F_47 ( T_1 V_57 [ 2 ] , T_1 V_63 ,
int V_40 )
{
int V_39 ;
T_1 V_60 ;
if ( ( V_63 & V_64 ) == 0 )
return - V_62 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_60 = F_45 ( V_57 , V_39 ) ;
V_60 &= V_65 ;
if ( V_60 != V_65 )
return - V_62 ;
}
return 0 ;
}
static unsigned char F_48 ( T_1 V_66 [ 2 ] ,
int V_39 )
{
int V_58 = ( V_39 & 1 ) * 4 ;
T_1 V_59 = V_66 [ V_39 >> 1 ] ;
return ( V_59 >> V_58 ) & 0x3 ;
}
static unsigned char F_49 (
T_1 V_66 [ 2 ] ,
int V_39 )
{
int V_58 = ( V_39 & 1 ) * 4 ;
T_1 V_59 = V_66 [ V_39 >> 1 ] ;
return ( ( V_59 >> V_58 ) & 0xc ) >> 2 ;
}
static void F_50 ( struct V_1 * V_5 ,
T_1 V_67 , int V_39 )
{
switch ( V_39 ) {
case 0 :
F_51 ( V_5 , V_67 ) ;
break;
case 1 :
F_52 ( V_5 , V_67 ) ;
break;
case 2 :
F_53 ( V_5 , V_67 ) ;
break;
case 3 :
F_54 ( V_5 , V_67 ) ;
break;
}
}
static unsigned int F_55 (
struct V_1 * V_5 ,
int V_39 )
{
T_2 V_68 ;
switch ( V_39 ) {
case 0 :
V_68 = F_56 ( V_5 ) ;
break;
case 1 :
V_68 = F_57 ( V_5 ) ;
break;
case 2 :
V_68 = F_58 ( V_5 ) ;
break;
case 3 :
V_68 = F_59 ( V_5 ) ;
break;
default:
F_60 ( 1 ) ;
return 0 ;
}
return V_68 ;
}
static void F_61 ( struct V_1 * V_5 )
{
F_33 ( V_5 ) ;
F_31 ( V_5 ) ;
V_5 -> V_42 . V_43 = V_69 ;
}
static void F_62 ( struct V_1 * V_5 ,
T_1 V_66 [ 2 ] )
{
int V_39 , V_40 ;
T_1 V_70 , V_38 , V_71 ;
V_40 = V_5 -> V_42 . V_40 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_70 = F_48 (
V_66 , V_39 ) ;
V_38 = F_49 (
V_66 , V_39 ) ;
V_71 = F_63 ( V_70 ) |
F_64 ( V_38 ) ;
if ( V_70 == V_72 )
V_71 |= V_73 ;
if ( V_38 == V_74 )
V_71 |= V_75 ;
V_5 -> V_42 . V_71 [ V_39 ] = V_71 ;
}
}
static int F_65 ( struct V_1 * V_5 )
{
int V_39 , V_40 , V_17 ;
T_1 V_70 , V_38 , V_71 ;
T_1 V_57 [ 2 ] , V_66 [ 2 ] ;
F_16 ( 100 , 101 ) ;
V_40 = V_5 -> V_42 . V_40 ;
V_17 = F_26 ( V_5 ,
V_76 , 2 , V_57 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_26 ( V_5 ,
V_77 , 2 , V_66 ) ;
if ( V_17 )
return V_17 ;
if ( F_46 ( V_57 , V_40 ) == 0 ) {
F_34 ( V_5 , V_78 ) ;
V_17 = F_23 ( V_5 ,
V_36 ,
V_52 |
V_79 ) ;
if ( V_17 )
return V_17 ;
F_24 ( V_5 -> V_8 , L_8 ) ;
V_5 -> V_42 . V_43 = V_80 ;
} else {
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_71 = F_55 (
V_5 , V_39 ) ;
V_70 = F_48 (
V_66 , V_39 ) ;
V_38 = F_49 (
V_66 , V_39 ) ;
if ( F_66 ( V_71 ) ==
V_70 &&
F_67 ( V_71 ) ==
V_38 )
V_5 -> V_42 . V_46 [ V_39 ] ++ ;
if ( V_5 -> V_42 . V_46 [ V_39 ] == V_81 ||
V_70 == V_72 ||
V_38 == V_74 ) {
F_15 ( V_5 -> V_8 , L_9 ,
V_5 -> V_42 . V_46 [ V_39 ] ,
V_70 , V_38 ) ;
F_61 ( V_5 ) ;
return - V_21 ;
}
}
}
F_62 ( V_5 , V_66 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_50 ( V_5 ,
V_5 -> V_42 . V_71 [ V_39 ] , V_39 ) ;
V_17 = F_43 ( V_5 ,
V_56 , V_40 ,
V_5 -> V_42 . V_71 ) ;
if ( V_17 )
return V_17 ;
return V_17 ;
}
static int F_68 ( struct V_1 * V_5 )
{
int V_39 , V_40 , V_17 ;
T_2 V_68 ;
T_1 V_63 , V_57 [ 2 ] , V_66 [ 2 ] ;
F_16 ( 400 , 401 ) ;
V_40 = V_5 -> V_42 . V_40 ;
V_17 = F_26 ( V_5 ,
V_76 , 2 , V_57 ) ;
if ( V_17 )
return V_17 ;
if ( F_46 ( V_57 , V_40 ) ) {
F_61 ( V_5 ) ;
return - V_21 ;
}
V_17 = F_26 ( V_5 ,
V_77 , 2 , V_66 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_22 ( V_5 ,
V_82 , & V_63 ) ;
if ( V_17 )
return V_17 ;
F_62 ( V_5 , V_66 ) ;
if ( ! F_47 ( V_57 , V_63 , V_40 ) ) {
F_33 ( V_5 ) ;
F_24 ( V_5 -> V_8 , L_10 ) ;
F_69 ( V_5 , & V_68 ) ;
V_5 -> V_42 . V_47 = V_68 ;
F_20 ( V_5 -> V_8 , L_11 ,
V_5 -> V_42 . V_47 ) ;
F_70 ( V_5 , & V_68 ) ;
V_5 -> V_42 . V_40 = V_68 ;
F_20 ( V_5 -> V_8 , L_12 ,
V_5 -> V_42 . V_40 ) ;
F_31 ( V_5 ) ;
V_5 -> V_42 . V_43 = V_83 ;
return 0 ;
}
V_5 -> V_42 . V_45 ++ ;
if ( V_5 -> V_42 . V_45 > V_84 ) {
F_15 ( V_5 -> V_8 , L_13 ) ;
F_61 ( V_5 ) ;
return - V_21 ;
}
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_50 ( V_5 ,
V_5 -> V_42 . V_71 [ V_39 ] , V_39 ) ;
V_17 = F_43 ( V_5 , V_56 ,
V_40 , V_5 -> V_42 . V_71 ) ;
return V_17 ;
}
static void F_71 ( struct V_1 * V_5 ,
T_1 * V_85 )
{
T_1 V_31 ;
F_22 ( V_5 , V_86 , & V_31 ) ;
* V_85 = V_31 ;
}
static void F_72 ( struct V_1 * V_5 ,
T_1 * V_40 )
{
T_1 V_31 ;
F_22 ( V_5 , V_34 , & V_31 ) ;
* V_40 = F_73 ( V_31 ) ;
}
static void F_74 ( struct V_1 * V_5 ,
enum V_87 V_88 ,
enum V_89 V_90 )
{
F_75 ( V_5 ) ;
F_71 ( V_5 , & V_5 -> V_42 . V_47 ) ;
F_72 ( V_5 , & V_5 -> V_42 . V_40 ) ;
if ( ( V_5 -> V_42 . V_47 != V_91 ) &&
( V_5 -> V_42 . V_47 != V_92 ) ) {
F_15 ( V_5 -> V_8 , L_14 ,
V_5 -> V_42 . V_47 ) ;
V_5 -> V_42 . V_47 = V_91 ;
}
if ( V_5 -> V_42 . V_40 == 0 ) {
F_15 ( V_5 -> V_8 , L_15 ,
V_5 -> V_42 . V_40 ) ;
V_5 -> V_42 . V_40 = ( T_1 ) V_93 ;
}
if ( V_5 -> V_42 . V_40 > V_88 )
V_5 -> V_42 . V_40 = V_88 ;
if ( V_5 -> V_42 . V_47 > V_90 )
V_5 -> V_42 . V_47 = V_90 ;
F_76 ( V_5 , V_94 , 0 ) ;
}
static int F_77 ( struct V_1 * V_5 )
{
int V_17 = 0 , V_95 = 0 ;
V_5 -> V_42 . V_43 = V_96 ;
while ( ! V_17 && ! V_95 ) {
switch ( V_5 -> V_42 . V_43 ) {
case V_96 :
V_17 = F_40 ( V_5 ) ;
if ( V_17 )
F_15 ( V_5 -> V_8 , L_16 ) ;
break;
case V_44 :
V_17 = F_65 ( V_5 ) ;
if ( V_17 )
F_15 ( V_5 -> V_8 , L_17 ) ;
break;
case V_80 :
V_17 = F_68 ( V_5 ) ;
if ( V_17 )
F_15 ( V_5 -> V_8 , L_18 ) ;
break;
case V_83 :
V_95 = 1 ;
break;
case V_69 :
return - V_97 ;
}
}
if ( V_17 )
F_15 ( V_5 -> V_8 , L_19 , V_17 ) ;
return V_17 ;
}
static int F_78 ( struct V_1 * V_5 ,
T_2 V_98 ,
T_2 V_99 )
{
int V_11 ;
int V_17 ;
for ( V_11 = 0 ; V_11 < V_7 ; V_11 ++ ) {
F_74 ( V_5 , V_98 , V_99 ) ;
V_17 = F_77 ( V_5 ) ;
if ( V_17 == 0 )
break;
F_16 ( 100 , 110 ) ;
}
return V_17 ;
}
static int F_79 ( struct V_1 * V_5 )
{
int V_17 = 0 ;
int V_6 = 0 ;
int V_100 = 0 ;
F_80 ( V_5 ) ;
F_81 ( V_5 ) ;
if ( F_44 ( V_5 ) == V_50 ) {
F_15 ( V_5 -> V_8 , L_20 ) ;
return - V_62 ;
}
for (; ; ) {
V_6 ++ ;
if ( F_82 ( V_5 ) == 0 )
break;
if ( V_7 < V_6 ) {
F_15 ( V_5 -> V_8 , L_21 ) ;
return - V_9 ;
}
F_16 ( 1 , 2 ) ;
}
F_83 ( V_5 , V_101 , 0 , 0 ) ;
F_84 ( V_5 , V_102 ) ;
F_85 ( V_5 , 0 ) ;
F_86 ( V_5 , 0 ) ;
F_87 ( V_5 ) ;
V_6 = 0 ;
for (; ; ) {
V_6 ++ ;
if ( F_88 ( V_5 ) == 0 ) {
V_100 ++ ;
if ( V_100 > 10 )
break;
} else if ( V_100 ) {
V_100 = 0 ;
}
if ( V_7 < V_6 ) {
F_15 ( V_5 -> V_8 , L_21 ) ;
return - V_9 ;
}
F_16 ( 1000 , 1001 ) ;
}
if ( V_17 != 0 )
F_15 ( V_5 -> V_8 , L_22 ) ;
return V_17 ;
}
static void F_89 ( struct V_1 * V_5 , bool V_30 )
{
T_1 V_31 ;
if ( V_30 ) {
F_90 ( V_5 ) ;
F_22 ( V_5 ,
V_36 ,
& V_31 ) ;
F_23 ( V_5 ,
V_36 ,
( T_1 ) ( V_31 & ~ V_52 ) ) ;
} else {
F_91 ( V_5 ) ;
F_22 ( V_5 ,
V_36 ,
& V_31 ) ;
F_23 ( V_5 ,
V_36 ,
( T_1 ) ( V_31 | V_52 ) ) ;
}
}
static T_3 F_92 ( int V_103 , void * V_104 )
{
struct V_1 * V_5 = V_104 ;
enum V_105 V_106 ;
V_106 = F_93 ( V_5 ) ;
switch ( V_106 ) {
case V_107 :
F_20 ( V_5 -> V_8 , L_23 ) ;
F_94 ( & V_5 -> V_108 ) ;
F_95 ( V_5 ) ;
break;
case V_109 :
F_20 ( V_5 -> V_8 , L_24 ) ;
F_95 ( V_5 ) ;
break;
case V_110 :
F_20 ( V_5 -> V_8 , L_25 ) ;
F_95 ( V_5 ) ;
break;
default:
F_15 ( V_5 -> V_8 , L_26 ) ;
break;
}
return V_111 ;
}
static void F_96 ( struct V_112 * V_113 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_113 , struct V_1 , V_108 ) ;
if ( V_5 -> V_114 )
F_97 ( V_5 -> V_114 ) ;
}
static void F_98 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_115 ;
if ( V_5 -> V_116 ) {
if ( F_99 ( V_5 -> V_116 ) )
F_100 ( L_27 ) ;
}
V_115 = F_13 ( V_5 ) ;
if ( V_115 ) {
return;
}
V_115 = F_25 ( V_5 ) ;
if ( V_115 ) {
F_15 ( V_5 -> V_8 , L_28 ) ;
return;
}
V_115 = F_78 ( V_5 , V_5 -> V_117 -> V_40 ,
V_5 -> V_117 -> V_47 ) ;
if ( V_115 ) {
F_15 ( V_5 -> V_8 , L_29 ) ;
return;
}
F_89 ( V_5 , 1 ) ;
F_27 ( V_5 , 1 ) ;
F_32 ( V_5 , 1 ) ;
F_42 ( V_5 , V_5 -> V_117 -> V_40 ) ;
F_41 ( V_5 , V_5 -> V_117 -> V_47 ) ;
F_101 ( V_5 ) ;
V_115 = F_79 ( V_5 ) ;
if ( V_115 )
F_15 ( V_5 -> V_8 , L_30 ) ;
if ( V_5 -> V_116 ) {
if ( F_102 ( V_5 -> V_116 ) )
F_100 ( L_31 ) ;
}
}
static enum V_118 F_103 (
struct V_119 * V_120 , bool V_121 )
{
return V_122 ;
}
static void F_104 ( struct V_119 * V_120 )
{
F_105 ( V_120 ) ;
F_106 ( V_120 ) ;
}
static int F_107 ( struct V_119 * V_120 )
{
struct V_1 * V_5 = F_108 ( V_120 ) ;
struct V_123 * V_124 ;
if ( V_5 -> V_116 )
return F_109 ( V_5 -> V_116 ) ;
V_124 = F_110 ( V_120 -> V_8 ) ;
if ( ! V_124 ) {
F_100 ( L_32 ) ;
return 0 ;
}
F_111 ( & V_5 -> V_125 . V_126 , V_124 ) ;
V_124 -> V_127 = V_5 -> V_125 . V_127 ;
V_124 -> V_128 = V_5 -> V_125 . V_128 ;
V_120 -> V_129 . V_127 = V_124 -> V_127 ;
V_120 -> V_129 . V_128 = V_124 -> V_128 ;
V_124 -> type = V_130 | V_131 ;
F_112 ( V_124 ) ;
F_113 ( V_120 , V_124 ) ;
return 1 ;
}
static struct V_132 * F_114 (
struct V_119 * V_120 )
{
struct V_1 * V_5 = F_108 ( V_120 ) ;
return V_5 -> V_133 ;
}
static bool F_115 ( const char * V_134 , struct V_135 * V_136 )
{
V_136 -> V_137 = NULL ;
V_136 -> V_138 = F_116 ( NULL , NULL , V_134 ) ;
if ( ! V_136 -> V_138 )
return false ;
V_136 -> V_137 = F_117 ( V_136 -> V_138 ) ;
if ( ! V_136 -> V_137 )
return false ;
return true ;
}
static int F_118 ( struct V_139 * V_8 ,
struct V_132 * V_133 )
{
struct V_135 V_136 ;
int V_115 ;
if ( F_115 ( L_33 , & V_136 ) ) {
V_115 = F_119 ( V_8 , V_133 , V_136 . V_137 , V_136 . V_138 ) ;
if ( ! V_115 )
return 1 ;
}
return 0 ;
}
static int F_120 ( struct V_2 * V_4 ,
struct V_132 * V_133 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_119 * V_120 = & V_5 -> V_120 ;
int V_115 ;
V_5 -> V_133 = V_133 ;
V_115 = F_118 ( V_5 -> V_114 , V_133 ) ;
if ( V_115 )
return 0 ;
V_120 -> V_140 = V_141 ;
V_115 = F_121 ( V_5 -> V_114 , V_120 ,
& V_142 , V_143 ) ;
if ( V_115 ) {
F_100 ( L_34 ) ;
return V_115 ;
}
F_122 ( V_120 , & V_144 ) ;
F_123 ( V_120 ) ;
F_124 ( V_120 , V_133 ) ;
if ( V_5 -> V_116 )
V_115 = F_125 ( V_5 -> V_116 , & V_5 -> V_120 ) ;
return V_115 ;
}
static void F_126 ( struct V_1 * V_5 )
{
if ( V_5 -> V_145 )
F_127 ( V_5 -> V_145 ) ;
}
static void F_128 ( struct V_1 * V_5 )
{
if ( V_5 -> V_145 )
F_129 ( V_5 -> V_145 ) ;
}
static void F_130 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_5 -> V_146 == V_147 )
return;
if ( V_5 -> V_116 ) {
if ( F_131 ( V_5 -> V_116 ) ) {
F_100 ( L_35 ) ;
return;
}
}
F_132 ( V_5 -> clock ) ;
F_126 ( V_5 ) ;
F_3 ( V_5 ) ;
F_133 ( V_5 -> V_103 ) ;
F_98 ( V_4 ) ;
}
static void F_134 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_5 -> V_146 != V_147 )
return;
if ( V_5 -> V_116 ) {
if ( F_99 ( V_5 -> V_116 ) ) {
F_100 ( L_27 ) ;
return;
}
}
F_135 ( V_5 -> V_103 ) ;
F_136 ( & V_5 -> V_108 ) ;
F_128 ( V_5 ) ;
F_137 ( V_5 -> clock ) ;
if ( V_5 -> V_116 ) {
if ( F_138 ( V_5 -> V_116 ) )
F_100 ( L_36 ) ;
}
}
static void F_139 ( struct V_2 * V_4 , int V_124 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_124 ) {
case V_147 :
F_130 ( V_4 ) ;
break;
case V_148 :
case V_149 :
case V_150 :
F_134 ( V_4 ) ;
break;
default:
break;
}
V_5 -> V_146 = V_124 ;
}
static struct V_117 * F_140 ( struct V_151 * V_8 )
{
struct V_152 * V_153 = V_8 -> V_154 ;
struct V_117 * V_155 ;
V_155 = F_141 ( V_8 ,
sizeof( * V_155 ) , V_156 ) ;
if ( ! V_155 )
return F_142 ( - V_157 ) ;
V_155 -> V_158 =
F_143 ( V_153 , L_37 ) ;
V_155 -> V_159 =
F_143 ( V_153 , L_38 ) ;
V_155 -> V_160 =
F_143 ( V_153 , L_39 ) ;
if ( F_144 ( V_153 , L_40 ,
& V_155 -> V_161 ) ) {
F_15 ( V_8 , L_41 ) ;
return F_142 ( - V_62 ) ;
}
if ( F_144 ( V_153 , L_42 ,
& V_155 -> V_162 ) ) {
F_15 ( V_8 , L_43 ) ;
return F_142 ( - V_62 ) ;
}
if ( F_144 ( V_153 , L_44 ,
& V_155 -> V_163 ) ) {
F_15 ( V_8 , L_45 ) ;
return F_142 ( - V_62 ) ;
}
if ( F_144 ( V_153 , L_46 ,
& V_155 -> V_164 ) ) {
F_15 ( V_8 , L_47 ) ;
return F_142 ( - V_62 ) ;
}
if ( F_144 ( V_153 , L_48 ,
& V_155 -> V_47 ) ) {
F_15 ( V_8 , L_49 ) ;
return F_142 ( - V_62 ) ;
}
if ( F_144 ( V_153 , L_50 ,
& V_155 -> V_40 ) ) {
F_15 ( V_8 , L_51 ) ;
return F_142 ( - V_62 ) ;
}
return V_155 ;
}
static int F_145 ( struct V_1 * V_5 )
{
int V_115 ;
V_115 = F_146 ( V_5 -> V_8 -> V_154 , & V_5 -> V_125 . V_126 ,
V_165 ) ;
if ( V_115 ) {
F_100 ( L_52 , V_115 ) ;
return V_115 ;
}
return 0 ;
}
static int F_147 ( struct V_151 * V_8 , struct V_151 * V_166 , void * V_31 )
{
struct V_1 * V_5 = F_148 ( V_8 ) ;
struct V_167 * V_168 = F_149 ( V_8 ) ;
struct V_139 * V_114 = V_31 ;
struct V_169 * V_170 ;
unsigned int V_171 ;
int V_115 = 0 ;
V_5 -> V_8 = & V_168 -> V_8 ;
V_5 -> V_146 = V_150 ;
V_5 -> V_117 = F_140 ( & V_168 -> V_8 ) ;
if ( F_150 ( V_5 -> V_117 ) )
return F_151 ( V_5 -> V_117 ) ;
V_5 -> V_145 = F_152 ( V_5 -> V_8 , L_53 ) ;
if ( F_150 ( V_5 -> V_145 ) ) {
F_15 ( V_5 -> V_8 , L_54 ) ;
V_115 = F_151 ( V_5 -> V_145 ) ;
if ( V_115 ) {
if ( V_115 == - V_172 || V_115 == - V_173 )
V_5 -> V_145 = NULL ;
else
return V_115 ;
}
}
if ( ! V_5 -> V_116 ) {
V_115 = F_145 ( V_5 ) ;
if ( V_115 )
return V_115 ;
}
V_5 -> clock = F_153 ( & V_168 -> V_8 , L_53 ) ;
if ( F_150 ( V_5 -> clock ) ) {
F_15 ( & V_168 -> V_8 , L_55 ) ;
return F_151 ( V_5 -> clock ) ;
}
F_132 ( V_5 -> clock ) ;
V_170 = F_154 ( V_168 , V_174 , 0 ) ;
V_5 -> V_175 = F_155 ( & V_168 -> V_8 , V_170 ) ;
if ( F_150 ( V_5 -> V_175 ) )
return F_151 ( V_5 -> V_175 ) ;
V_5 -> V_176 = F_156 ( V_8 -> V_154 , L_56 , 0 ) ;
if ( F_157 ( V_5 -> V_176 ) ) {
V_115 = F_158 ( & V_168 -> V_8 , V_5 -> V_176 , V_177 ,
L_57 ) ;
if ( V_115 ) {
F_15 ( & V_168 -> V_8 , L_58 ) ;
return V_115 ;
}
V_5 -> V_103 = F_159 ( V_5 -> V_176 ) ;
V_171 = V_178 | V_179 ;
} else {
V_5 -> V_176 = - V_173 ;
V_5 -> V_103 = F_160 ( V_168 , 0 ) ;
V_171 = 0 ;
}
if ( V_5 -> V_103 == - V_180 ) {
F_15 ( & V_168 -> V_8 , L_59 ) ;
return - V_173 ;
}
F_161 ( & V_5 -> V_108 , F_96 ) ;
F_126 ( V_5 ) ;
F_3 ( V_5 ) ;
V_115 = F_162 ( & V_168 -> V_8 , V_5 -> V_103 , F_92 ,
V_171 , L_60 , V_5 ) ;
if ( V_115 ) {
F_15 ( & V_168 -> V_8 , L_61 ) ;
return V_115 ;
}
F_135 ( V_5 -> V_103 ) ;
V_5 -> V_114 = V_114 ;
return F_163 ( V_114 , & V_5 -> V_4 ) ;
}
static void F_164 ( struct V_151 * V_8 , struct V_151 * V_166 ,
void * V_31 )
{
struct V_1 * V_5 = F_148 ( V_8 ) ;
F_139 ( & V_5 -> V_4 , V_150 ) ;
}
static int F_165 ( struct V_167 * V_168 )
{
struct V_151 * V_8 = & V_168 -> V_8 ;
struct V_152 * V_181 ;
struct V_1 * V_5 ;
int V_115 ;
V_5 = F_141 ( & V_168 -> V_8 , sizeof( struct V_1 ) ,
V_156 ) ;
if ( ! V_5 )
return - V_157 ;
V_5 -> V_4 . type = V_182 ;
V_5 -> V_4 . V_183 = & V_184 ;
F_166 ( V_168 , V_5 ) ;
V_115 = F_167 ( & V_168 -> V_8 , V_185 ,
V_5 -> V_4 . type ) ;
if ( V_115 )
return V_115 ;
V_181 = F_168 ( V_8 -> V_154 , L_62 , 0 ) ;
if ( V_181 ) {
V_5 -> V_116 = F_169 ( V_181 ) ;
F_170 ( V_181 ) ;
if ( ! V_5 -> V_116 )
return - V_186 ;
}
V_115 = F_171 ( & V_168 -> V_8 , & V_187 ) ;
if ( V_115 )
F_172 ( & V_168 -> V_8 ,
V_185 ) ;
return V_115 ;
}
static int F_173 ( struct V_167 * V_168 )
{
F_174 ( & V_168 -> V_8 , & V_187 ) ;
F_172 ( & V_168 -> V_8 , V_185 ) ;
return 0 ;
}
static int F_175 ( struct V_151 * V_8 )
{
struct V_1 * V_5 = F_148 ( V_8 ) ;
F_139 ( & V_5 -> V_4 , V_150 ) ;
return 0 ;
}
static int F_176 ( struct V_151 * V_8 )
{
struct V_1 * V_5 = F_148 ( V_8 ) ;
F_139 ( & V_5 -> V_4 , V_147 ) ;
return 0 ;
}
