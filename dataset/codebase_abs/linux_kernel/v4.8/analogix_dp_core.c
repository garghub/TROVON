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
while ( V_3 < V_4 ) {
if ( F_12 ( V_2 ) == 0 )
return 0 ;
V_3 ++ ;
F_13 ( 10 , 11 ) ;
}
if ( ! V_2 -> V_5 )
return - V_6 ;
F_14 ( V_2 -> V_7 , L_1 ) ;
F_15 ( V_2 ) ;
if ( F_12 ( V_2 ) != 0 ) {
F_16 ( V_2 -> V_7 , L_2 ) ;
return - V_8 ;
}
F_14 ( V_2 -> V_7 , L_3 ) ;
return 0 ;
}
static unsigned char F_17 ( unsigned char * V_9 )
{
int V_10 ;
unsigned char V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ )
V_11 = V_11 + V_9 [ V_10 ] ;
return V_11 ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned char * V_13 = V_2 -> V_13 ;
unsigned int V_14 = 0 ;
unsigned char V_11 ;
unsigned char V_15 ;
int V_16 ;
V_16 = F_19 ( V_2 , V_17 ,
V_18 ,
& V_14 ) ;
if ( V_16 )
return V_16 ;
if ( V_14 > 0 ) {
F_14 ( V_2 -> V_7 , L_4 ) ;
V_16 = F_20 ( V_2 ,
V_17 ,
V_19 ,
V_12 ,
& V_13 [ V_19 ] ) ;
if ( V_16 != 0 ) {
F_16 ( V_2 -> V_7 , L_5 ) ;
return - V_20 ;
}
V_11 = F_17 ( V_13 ) ;
if ( V_11 != 0 ) {
F_16 ( V_2 -> V_7 , L_6 ) ;
return - V_20 ;
}
V_16 = F_20 ( V_2 ,
V_17 ,
V_12 ,
V_12 ,
& V_13 [ V_12 ] ) ;
if ( V_16 != 0 ) {
F_16 ( V_2 -> V_7 , L_5 ) ;
return - V_20 ;
}
V_11 = F_17 ( & V_13 [ V_12 ] ) ;
if ( V_11 != 0 ) {
F_16 ( V_2 -> V_7 , L_6 ) ;
return - V_20 ;
}
F_21 ( V_2 , V_21 ,
& V_15 ) ;
if ( V_15 & V_22 ) {
F_22 ( V_2 ,
V_23 ,
V_13 [ V_12 + V_24 ] ) ;
F_22 ( V_2 ,
V_25 ,
V_26 ) ;
}
} else {
F_23 ( V_2 -> V_7 , L_7 ) ;
V_16 = F_20 ( V_2 ,
V_17 , V_19 ,
V_12 , & V_13 [ V_19 ] ) ;
if ( V_16 != 0 ) {
F_16 ( V_2 -> V_7 , L_5 ) ;
return - V_20 ;
}
V_11 = F_17 ( V_13 ) ;
if ( V_11 != 0 ) {
F_16 ( V_2 -> V_7 , L_6 ) ;
return - V_20 ;
}
F_21 ( V_2 , V_21 ,
& V_15 ) ;
if ( V_15 & V_22 ) {
F_22 ( V_2 ,
V_23 , V_13 [ V_24 ] ) ;
F_22 ( V_2 ,
V_25 , V_26 ) ;
}
}
F_14 ( V_2 -> V_7 , L_8 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_1 V_27 [ 12 ] ;
int V_10 ;
int V_16 ;
V_16 = F_25 ( V_2 , V_28 , 12 , V_27 ) ;
if ( V_16 )
return V_16 ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
V_16 = F_18 ( V_2 ) ;
if ( ! V_16 )
break;
}
return V_16 ;
}
static void
F_26 ( struct V_1 * V_2 ,
bool V_29 )
{
T_1 V_30 ;
F_21 ( V_2 , V_31 , & V_30 ) ;
if ( V_29 )
F_22 ( V_2 , V_31 ,
V_32 |
F_27 ( V_30 ) ) ;
else
F_22 ( V_2 , V_31 ,
F_27 ( V_30 ) ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_30 ;
int V_16 ;
F_21 ( V_2 , V_33 , & V_30 ) ;
V_16 = F_29 ( V_30 ) ;
return V_16 ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_30 ;
V_30 = F_28 ( V_2 ) ;
F_26 ( V_2 , V_30 ) ;
F_31 ( V_2 , V_30 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_34 ) ;
F_22 ( V_2 , V_35 ,
V_36 ) ;
}
static void
F_34 ( struct V_1 * V_2 ,
int V_37 , int V_38 )
{
switch ( V_38 ) {
case 0 :
F_35 ( V_2 , V_37 ) ;
break;
case 1 :
F_36 ( V_2 , V_37 ) ;
break;
case 2 :
F_37 ( V_2 , V_37 ) ;
break;
case 3 :
F_38 ( V_2 , V_37 ) ;
break;
}
}
static int F_39 ( struct V_1 * V_2 )
{
T_1 V_27 [ 4 ] ;
int V_38 , V_39 , V_40 , V_16 ;
V_39 = V_2 -> V_41 . V_39 ;
V_2 -> V_41 . V_42 = V_43 ;
V_2 -> V_41 . V_44 = 0 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
V_2 -> V_41 . V_45 [ V_38 ] = 0 ;
F_40 ( V_2 , V_2 -> V_41 . V_46 ) ;
F_41 ( V_2 , V_2 -> V_41 . V_39 ) ;
V_27 [ 0 ] = V_2 -> V_41 . V_46 ;
V_27 [ 1 ] = V_2 -> V_41 . V_39 ;
V_16 = F_42 ( V_2 , V_47 , 2 , V_27 ) ;
if ( V_16 )
return V_16 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
F_34 ( V_2 ,
V_48 , V_38 ) ;
V_40 = 0 ;
while ( F_43 ( V_2 ) == V_49 ) {
if ( V_40 == V_4 ) {
F_16 ( V_2 -> V_7 , L_9 ) ;
return - V_6 ;
}
V_40 ++ ;
F_13 ( 90 , 120 ) ;
}
F_33 ( V_2 , V_50 ) ;
V_16 = F_22 ( V_2 ,
V_35 ,
V_51 | V_52 ) ;
if ( V_16 )
return V_16 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
V_27 [ V_38 ] = V_53 |
V_54 ;
V_16 = F_42 ( V_2 , V_55 ,
V_39 , V_27 ) ;
return V_16 ;
}
static unsigned char F_44 ( T_1 V_56 [ 2 ] , int V_38 )
{
int V_57 = ( V_38 & 1 ) * 4 ;
T_1 V_58 = V_56 [ V_38 >> 1 ] ;
return ( V_58 >> V_57 ) & 0xf ;
}
static int F_45 ( T_1 V_56 [ 2 ] , int V_39 )
{
int V_38 ;
T_1 V_59 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_59 = F_44 ( V_56 , V_38 ) ;
if ( ( V_59 & V_60 ) == 0 )
return - V_8 ;
}
return 0 ;
}
static int F_46 ( T_1 V_56 [ 2 ] , T_1 V_61 ,
int V_39 )
{
int V_38 ;
T_1 V_59 ;
if ( ( V_61 & V_62 ) == 0 )
return - V_8 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_59 = F_44 ( V_56 , V_38 ) ;
V_59 &= V_63 ;
if ( V_59 != V_63 )
return - V_8 ;
}
return 0 ;
}
static unsigned char
F_47 ( T_1 V_64 [ 2 ] , int V_38 )
{
int V_57 = ( V_38 & 1 ) * 4 ;
T_1 V_58 = V_64 [ V_38 >> 1 ] ;
return ( V_58 >> V_57 ) & 0x3 ;
}
static unsigned char F_48 (
T_1 V_64 [ 2 ] ,
int V_38 )
{
int V_57 = ( V_38 & 1 ) * 4 ;
T_1 V_58 = V_64 [ V_38 >> 1 ] ;
return ( ( V_58 >> V_57 ) & 0xc ) >> 2 ;
}
static void F_49 ( struct V_1 * V_2 ,
T_1 V_65 , int V_38 )
{
switch ( V_38 ) {
case 0 :
F_50 ( V_2 , V_65 ) ;
break;
case 1 :
F_51 ( V_2 , V_65 ) ;
break;
case 2 :
F_52 ( V_2 , V_65 ) ;
break;
case 3 :
F_53 ( V_2 , V_65 ) ;
break;
}
}
static unsigned int
F_54 ( struct V_1 * V_2 ,
int V_38 )
{
T_2 V_66 ;
switch ( V_38 ) {
case 0 :
V_66 = F_55 ( V_2 ) ;
break;
case 1 :
V_66 = F_56 ( V_2 ) ;
break;
case 2 :
V_66 = F_57 ( V_2 ) ;
break;
case 3 :
V_66 = F_58 ( V_2 ) ;
break;
default:
F_59 ( 1 ) ;
return 0 ;
}
return V_66 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
F_30 ( V_2 ) ;
V_2 -> V_41 . V_42 = V_67 ;
}
static void F_61 ( struct V_1 * V_2 ,
T_1 V_64 [ 2 ] )
{
int V_38 , V_39 ;
T_1 V_68 , V_37 , V_69 ;
V_39 = V_2 -> V_41 . V_39 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_68 = F_47 (
V_64 , V_38 ) ;
V_37 = F_48 (
V_64 , V_38 ) ;
V_69 = F_62 ( V_68 ) |
F_63 ( V_37 ) ;
if ( V_68 == V_70 )
V_69 |= V_71 ;
if ( V_37 == V_72 )
V_69 |= V_73 ;
V_2 -> V_41 . V_69 [ V_38 ] = V_69 ;
}
}
static int F_64 ( struct V_1 * V_2 )
{
int V_38 , V_39 , V_16 ;
T_1 V_68 , V_37 , V_69 ;
T_1 V_56 [ 2 ] , V_64 [ 2 ] ;
F_13 ( 100 , 101 ) ;
V_39 = V_2 -> V_41 . V_39 ;
V_16 = F_25 ( V_2 ,
V_74 , 2 , V_56 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_25 ( V_2 ,
V_75 , 2 , V_64 ) ;
if ( V_16 )
return V_16 ;
if ( F_45 ( V_56 , V_39 ) == 0 ) {
F_33 ( V_2 , V_76 ) ;
V_16 = F_22 ( V_2 ,
V_35 ,
V_51 |
V_77 ) ;
if ( V_16 )
return V_16 ;
F_23 ( V_2 -> V_7 , L_10 ) ;
V_2 -> V_41 . V_42 = V_78 ;
} else {
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_69 = F_54 (
V_2 , V_38 ) ;
V_68 = F_47 (
V_64 , V_38 ) ;
V_37 = F_48 (
V_64 , V_38 ) ;
if ( F_65 ( V_69 ) ==
V_68 &&
F_66 ( V_69 ) ==
V_37 )
V_2 -> V_41 . V_45 [ V_38 ] ++ ;
if ( V_2 -> V_41 . V_45 [ V_38 ] == V_79 ||
V_68 == V_70 ||
V_37 == V_72 ) {
F_16 ( V_2 -> V_7 , L_11 ,
V_2 -> V_41 . V_45 [ V_38 ] ,
V_68 , V_37 ) ;
F_60 ( V_2 ) ;
return - V_20 ;
}
}
}
F_61 ( V_2 , V_64 ) ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
F_49 ( V_2 ,
V_2 -> V_41 . V_69 [ V_38 ] , V_38 ) ;
V_16 = F_42 ( V_2 ,
V_55 , V_39 ,
V_2 -> V_41 . V_69 ) ;
if ( V_16 )
return V_16 ;
return V_16 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_38 , V_39 , V_16 ;
T_2 V_66 ;
T_1 V_61 , V_56 [ 2 ] , V_64 [ 2 ] ;
F_13 ( 400 , 401 ) ;
V_39 = V_2 -> V_41 . V_39 ;
V_16 = F_25 ( V_2 ,
V_74 , 2 , V_56 ) ;
if ( V_16 )
return V_16 ;
if ( F_45 ( V_56 , V_39 ) ) {
F_60 ( V_2 ) ;
return - V_20 ;
}
V_16 = F_25 ( V_2 ,
V_75 , 2 , V_64 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_21 ( V_2 ,
V_80 , & V_61 ) ;
if ( V_16 )
return V_16 ;
F_61 ( V_2 , V_64 ) ;
if ( ! F_46 ( V_56 , V_61 , V_39 ) ) {
F_32 ( V_2 ) ;
F_23 ( V_2 -> V_7 , L_12 ) ;
F_68 ( V_2 , & V_66 ) ;
V_2 -> V_41 . V_46 = V_66 ;
F_14 ( V_2 -> V_7 , L_13 ,
V_2 -> V_41 . V_46 ) ;
F_69 ( V_2 , & V_66 ) ;
V_2 -> V_41 . V_39 = V_66 ;
F_14 ( V_2 -> V_7 , L_14 ,
V_2 -> V_41 . V_39 ) ;
F_30 ( V_2 ) ;
V_2 -> V_41 . V_42 = V_81 ;
return 0 ;
}
V_2 -> V_41 . V_44 ++ ;
if ( V_2 -> V_41 . V_44 > V_82 ) {
F_16 ( V_2 -> V_7 , L_15 ) ;
F_60 ( V_2 ) ;
return - V_20 ;
}
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
F_49 ( V_2 ,
V_2 -> V_41 . V_69 [ V_38 ] , V_38 ) ;
V_16 = F_42 ( V_2 , V_55 ,
V_39 , V_2 -> V_41 . V_69 ) ;
return V_16 ;
}
static void F_70 ( struct V_1 * V_2 ,
T_1 * V_83 )
{
T_1 V_30 ;
F_21 ( V_2 , V_84 , & V_30 ) ;
* V_83 = V_30 ;
}
static void F_71 ( struct V_1 * V_2 ,
T_1 * V_39 )
{
T_1 V_30 ;
F_21 ( V_2 , V_33 , & V_30 ) ;
* V_39 = F_72 ( V_30 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
enum V_85 V_86 ,
int V_87 )
{
F_74 ( V_2 ) ;
F_70 ( V_2 , & V_2 -> V_41 . V_46 ) ;
F_71 ( V_2 , & V_2 -> V_41 . V_39 ) ;
if ( ( V_2 -> V_41 . V_46 != V_88 ) &&
( V_2 -> V_41 . V_46 != V_89 ) &&
( V_2 -> V_41 . V_46 != V_90 ) ) {
F_16 ( V_2 -> V_7 , L_16 ,
V_2 -> V_41 . V_46 ) ;
V_2 -> V_41 . V_46 = V_88 ;
}
if ( V_2 -> V_41 . V_39 == 0 ) {
F_16 ( V_2 -> V_7 , L_17 ,
V_2 -> V_41 . V_39 ) ;
V_2 -> V_41 . V_39 = ( T_1 ) V_91 ;
}
if ( V_2 -> V_41 . V_39 > V_86 )
V_2 -> V_41 . V_39 = V_86 ;
if ( V_2 -> V_41 . V_46 > V_87 )
V_2 -> V_41 . V_46 = V_87 ;
F_75 ( V_2 , V_92 , 0 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_16 = 0 , V_93 = 0 ;
V_2 -> V_41 . V_42 = V_94 ;
while ( ! V_16 && ! V_93 ) {
switch ( V_2 -> V_41 . V_42 ) {
case V_94 :
V_16 = F_39 ( V_2 ) ;
if ( V_16 )
F_16 ( V_2 -> V_7 , L_18 ) ;
break;
case V_43 :
V_16 = F_64 ( V_2 ) ;
if ( V_16 )
F_16 ( V_2 -> V_7 , L_19 ) ;
break;
case V_78 :
V_16 = F_67 ( V_2 ) ;
if ( V_16 )
F_16 ( V_2 -> V_7 , L_20 ) ;
break;
case V_81 :
V_93 = 1 ;
break;
case V_67 :
return - V_95 ;
}
}
if ( V_16 )
F_16 ( V_2 -> V_7 , L_21 , V_16 ) ;
return V_16 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_2 V_96 , T_2 V_97 )
{
int V_10 ;
int V_16 ;
for ( V_10 = 0 ; V_10 < V_4 ; V_10 ++ ) {
F_73 ( V_2 , V_96 , V_97 ) ;
V_16 = F_76 ( V_2 ) ;
if ( V_16 == 0 )
break;
F_13 ( 100 , 110 ) ;
}
return V_16 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
int V_3 = 0 ;
int V_98 = 0 ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
if ( F_43 ( V_2 ) == V_49 ) {
F_16 ( V_2 -> V_7 , L_22 ) ;
return - V_8 ;
}
for (; ; ) {
V_3 ++ ;
if ( F_81 ( V_2 ) == 0 )
break;
if ( V_3 > V_4 ) {
F_16 ( V_2 -> V_7 , L_23 ) ;
return - V_6 ;
}
F_13 ( 1 , 2 ) ;
}
F_82 ( V_2 , V_99 , 0 , 0 ) ;
F_83 ( V_2 , V_100 ) ;
F_84 ( V_2 , 0 ) ;
F_85 ( V_2 , 0 ) ;
V_3 = 0 ;
for (; ; ) {
V_3 ++ ;
if ( F_86 ( V_2 ) == 0 ) {
V_98 ++ ;
if ( V_98 > 10 )
break;
} else if ( V_98 ) {
V_98 = 0 ;
}
if ( V_3 > V_4 ) {
F_16 ( V_2 -> V_7 , L_23 ) ;
return - V_6 ;
}
F_13 ( 1000 , 1001 ) ;
}
if ( V_16 != 0 )
F_16 ( V_2 -> V_7 , L_24 ) ;
return V_16 ;
}
static void F_87 ( struct V_1 * V_2 ,
bool V_29 )
{
T_1 V_30 ;
if ( V_29 ) {
F_88 ( V_2 ) ;
F_21 ( V_2 , V_35 ,
& V_30 ) ;
F_22 ( V_2 ,
V_35 ,
( T_1 ) ( V_30 & ~ V_51 ) ) ;
} else {
F_89 ( V_2 ) ;
F_21 ( V_2 , V_35 ,
& V_30 ) ;
F_22 ( V_2 ,
V_35 ,
( T_1 ) ( V_30 | V_51 ) ) ;
}
}
static T_3 F_90 ( int V_101 , void * V_102 )
{
struct V_1 * V_2 = V_102 ;
T_3 V_103 = V_104 ;
enum V_105 V_106 ;
V_106 = F_91 ( V_2 ) ;
if ( V_106 != V_107 ) {
F_92 ( V_2 ) ;
V_103 = V_108 ;
}
return V_103 ;
}
static T_3 F_93 ( int V_101 , void * V_102 )
{
struct V_1 * V_2 = V_102 ;
enum V_105 V_106 ;
V_106 = F_91 ( V_2 ) ;
if ( V_106 & V_109 ||
V_106 & V_110 ) {
F_14 ( V_2 -> V_7 , L_25 ) ;
if ( V_2 -> V_111 )
F_94 ( V_2 -> V_111 ) ;
}
if ( V_106 != V_107 ) {
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
}
return V_112 ;
}
static void F_97 ( struct V_1 * V_2 )
{
int V_103 ;
if ( V_2 -> V_113 -> V_114 ) {
if ( F_98 ( V_2 -> V_113 -> V_114 ) )
F_99 ( L_26 ) ;
}
V_103 = F_77 ( V_2 , V_2 -> V_115 . V_116 ,
V_2 -> V_115 . V_117 ) ;
if ( V_103 ) {
F_16 ( V_2 -> V_7 , L_27 ) ;
return;
}
F_87 ( V_2 , 1 ) ;
F_26 ( V_2 , 1 ) ;
F_31 ( V_2 , 1 ) ;
F_100 ( V_2 ) ;
V_103 = F_78 ( V_2 ) ;
if ( V_103 )
F_16 ( V_2 -> V_7 , L_28 ) ;
if ( V_2 -> V_113 -> V_114 ) {
if ( F_101 ( V_2 -> V_113 -> V_114 ) )
F_99 ( L_29 ) ;
}
F_102 ( V_2 ) ;
}
int F_103 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_104 ( V_119 ) ;
struct V_13 * V_13 = (struct V_13 * ) V_2 -> V_13 ;
int V_120 = 0 ;
if ( F_24 ( V_2 ) == 0 ) {
F_105 ( & V_2 -> V_119 , V_13 ) ;
V_120 += F_106 ( & V_2 -> V_119 , V_13 ) ;
}
if ( V_2 -> V_113 -> V_114 )
V_120 += F_107 ( V_2 -> V_113 -> V_114 ) ;
if ( V_2 -> V_113 -> V_121 )
V_120 += V_2 -> V_113 -> V_121 ( V_2 -> V_113 , V_119 ) ;
return V_120 ;
}
static struct V_122 *
F_108 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_104 ( V_119 ) ;
return V_2 -> V_123 ;
}
enum V_124
F_109 ( struct V_118 * V_119 , bool V_125 )
{
struct V_1 * V_2 = F_104 ( V_119 ) ;
if ( F_11 ( V_2 ) )
return V_126 ;
return V_127 ;
}
static void F_110 ( struct V_118 * V_119 )
{
F_111 ( V_119 ) ;
F_112 ( V_119 ) ;
}
static int F_113 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_130 ;
struct V_122 * V_123 = V_2 -> V_123 ;
struct V_118 * V_119 = & V_2 -> V_119 ;
int V_103 ;
if ( ! V_129 -> V_123 ) {
F_99 ( L_30 ) ;
return - V_131 ;
}
V_119 -> V_132 = V_133 ;
V_103 = F_114 ( V_2 -> V_111 , V_119 ,
& V_134 ,
V_135 ) ;
if ( V_103 ) {
F_99 ( L_31 ) ;
return V_103 ;
}
F_115 ( V_119 ,
& V_136 ) ;
F_116 ( V_119 , V_123 ) ;
if ( V_2 -> V_113 -> V_137 ) {
V_103 = V_2 -> V_113 -> V_137 ( V_2 -> V_113 , V_129 , V_119 ) ;
if ( V_103 ) {
F_99 ( L_32 ) ;
return V_103 ;
}
}
if ( V_2 -> V_113 -> V_114 ) {
V_103 = F_117 ( V_2 -> V_113 -> V_114 , & V_2 -> V_119 ) ;
if ( V_103 ) {
F_99 ( L_33 ) ;
return V_103 ;
}
}
return 0 ;
}
static void F_118 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_130 ;
if ( V_2 -> V_138 == V_139 )
return;
F_119 ( V_2 -> V_7 ) ;
if ( V_2 -> V_113 -> V_140 )
V_2 -> V_113 -> V_140 ( V_2 -> V_113 ) ;
F_120 ( V_2 -> V_141 ) ;
F_1 ( V_2 ) ;
F_121 ( V_2 -> V_101 ) ;
F_97 ( V_2 ) ;
V_2 -> V_138 = V_139 ;
}
static void F_122 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_130 ;
if ( V_2 -> V_138 != V_139 )
return;
if ( V_2 -> V_113 -> V_114 ) {
if ( F_98 ( V_2 -> V_113 -> V_114 ) ) {
F_99 ( L_26 ) ;
return;
}
}
F_123 ( V_2 -> V_101 ) ;
F_124 ( V_2 -> V_141 ) ;
if ( V_2 -> V_113 -> V_142 )
V_2 -> V_113 -> V_142 ( V_2 -> V_113 ) ;
F_125 ( V_2 -> V_7 ) ;
V_2 -> V_138 = V_143 ;
}
static void F_126 ( struct V_128 * V_129 ,
struct V_144 * V_145 ,
struct V_144 * V_146 )
{
struct V_1 * V_2 = V_129 -> V_130 ;
struct V_147 * V_148 = & V_2 -> V_119 . V_148 ;
struct V_115 * V_149 = & V_2 -> V_115 ;
struct V_150 * V_151 = V_2 -> V_7 -> V_152 ;
int V_153 ;
V_149 -> V_154 = ! ! ( V_146 -> V_155 & V_156 ) ;
V_149 -> V_157 = ! ! ( V_146 -> V_155 & V_158 ) ;
V_149 -> V_159 = ! ! ( V_146 -> V_155 & V_160 ) ;
V_153 = F_127 ( V_146 ) ;
if ( ( V_153 == 6 ) || ( V_153 == 7 ) || ( V_153 == 21 ) || ( V_153 == 22 ) ||
( V_153 == 2 ) || ( V_153 == 3 ) || ( V_153 == 17 ) || ( V_153 == 18 ) ) {
V_149 -> V_161 = V_162 ;
V_149 -> V_163 = V_164 ;
} else if ( V_153 ) {
V_149 -> V_161 = V_162 ;
V_149 -> V_163 = V_165 ;
} else {
V_149 -> V_161 = V_166 ;
V_149 -> V_163 = V_165 ;
}
switch ( V_148 -> V_167 ) {
case 12 :
V_149 -> V_168 = V_169 ;
break;
case 10 :
V_149 -> V_168 = V_170 ;
break;
case 8 :
V_149 -> V_168 = V_171 ;
break;
case 6 :
V_149 -> V_168 = V_172 ;
break;
default:
V_149 -> V_168 = V_171 ;
break;
}
if ( V_148 -> V_173 & V_174 )
V_149 -> V_175 = V_176 ;
else if ( V_148 -> V_173 & V_177 )
V_149 -> V_175 = V_178 ;
else if ( V_148 -> V_173 & V_179 )
V_149 -> V_175 = V_180 ;
else
V_149 -> V_175 = V_180 ;
F_128 ( V_151 , L_34 ,
& V_149 -> V_175 ) ;
F_128 ( V_151 , L_35 ,
& V_149 -> V_161 ) ;
F_128 ( V_151 , L_36 ,
& V_149 -> V_163 ) ;
F_128 ( V_151 , L_37 ,
& V_149 -> V_168 ) ;
if ( F_129 ( V_151 , L_38 ) )
V_149 -> V_159 = true ;
if ( F_129 ( V_151 , L_39 ) )
V_149 -> V_157 = true ;
if ( F_129 ( V_151 , L_40 ) )
V_149 -> V_154 = true ;
}
static void F_130 ( struct V_128 * V_129 )
{
}
static int F_131 ( struct V_181 * V_111 ,
struct V_1 * V_2 )
{
struct V_128 * V_129 ;
int V_103 ;
V_129 = F_132 ( V_111 -> V_7 , sizeof( * V_129 ) , V_182 ) ;
if ( ! V_129 ) {
F_99 ( L_41 ) ;
return - V_183 ;
}
V_2 -> V_129 = V_129 ;
V_2 -> V_123 -> V_129 = V_129 ;
V_129 -> V_130 = V_2 ;
V_129 -> V_123 = V_2 -> V_123 ;
V_129 -> V_184 = & V_185 ;
V_103 = F_133 ( V_111 , V_129 ) ;
if ( V_103 ) {
F_99 ( L_42 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_150 * V_151 = V_2 -> V_7 -> V_152 ;
struct V_115 * V_115 = & V_2 -> V_115 ;
switch ( V_2 -> V_113 -> V_186 ) {
case V_187 :
case V_188 :
V_115 -> V_117 = 0x0A ;
V_115 -> V_116 = 0x04 ;
break;
case V_189 :
F_128 ( V_151 , L_43 ,
& V_115 -> V_117 ) ;
F_128 ( V_151 , L_44 ,
& V_115 -> V_116 ) ;
break;
}
return 0 ;
}
int F_135 ( struct V_190 * V_7 , struct V_181 * V_111 ,
struct V_191 * V_113 )
{
struct V_192 * V_193 = F_136 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_194 * V_195 ;
unsigned int V_196 ;
int V_103 ;
if ( ! V_113 ) {
F_16 ( V_7 , L_45 ) ;
return - V_8 ;
}
V_2 = F_132 ( V_7 , sizeof( struct V_1 ) , V_182 ) ;
if ( ! V_2 )
return - V_183 ;
F_137 ( V_7 , V_2 ) ;
V_2 -> V_7 = & V_193 -> V_7 ;
V_2 -> V_138 = V_143 ;
V_2 -> V_113 = V_113 ;
V_103 = F_134 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_2 -> V_141 = F_138 ( V_2 -> V_7 , L_46 ) ;
if ( F_139 ( V_2 -> V_141 ) ) {
F_16 ( V_2 -> V_7 , L_47 ) ;
V_103 = F_140 ( V_2 -> V_141 ) ;
if ( V_103 ) {
if ( V_103 == - V_197 || V_103 == - V_131 )
V_2 -> V_141 = NULL ;
else
return V_103 ;
}
}
V_2 -> clock = F_141 ( & V_193 -> V_7 , L_46 ) ;
if ( F_139 ( V_2 -> clock ) ) {
F_16 ( & V_193 -> V_7 , L_48 ) ;
return F_140 ( V_2 -> clock ) ;
}
F_142 ( V_2 -> clock ) ;
V_195 = F_143 ( V_193 , V_198 , 0 ) ;
V_2 -> V_199 = F_144 ( & V_193 -> V_7 , V_195 ) ;
if ( F_139 ( V_2 -> V_199 ) )
return F_140 ( V_2 -> V_199 ) ;
V_2 -> V_5 = F_129 ( V_7 -> V_152 , L_49 ) ;
V_2 -> V_200 = F_145 ( V_7 -> V_152 , L_50 , 0 ) ;
if ( ! F_146 ( V_2 -> V_200 ) )
V_2 -> V_200 = F_145 ( V_7 -> V_152 ,
L_51 , 0 ) ;
if ( F_146 ( V_2 -> V_200 ) ) {
V_103 = F_147 ( & V_193 -> V_7 , V_2 -> V_200 , V_201 ,
L_52 ) ;
if ( V_103 ) {
F_16 ( & V_193 -> V_7 , L_53 ) ;
return V_103 ;
}
V_2 -> V_101 = F_148 ( V_2 -> V_200 ) ;
V_196 = V_202 | V_203 ;
} else {
V_2 -> V_200 = - V_131 ;
V_2 -> V_101 = F_149 ( V_193 , 0 ) ;
V_196 = 0 ;
}
if ( V_2 -> V_101 == - V_204 ) {
F_16 ( & V_193 -> V_7 , L_54 ) ;
return - V_131 ;
}
F_150 ( V_7 ) ;
F_120 ( V_2 -> V_141 ) ;
if ( V_2 -> V_113 -> V_114 ) {
if ( F_151 ( V_2 -> V_113 -> V_114 ) ) {
F_99 ( L_55 ) ;
return - V_205 ;
}
}
F_1 ( V_2 ) ;
V_103 = F_152 ( & V_193 -> V_7 , V_2 -> V_101 ,
F_90 ,
F_93 ,
V_196 , L_56 , V_2 ) ;
if ( V_103 ) {
F_16 ( & V_193 -> V_7 , L_57 ) ;
goto V_206;
}
F_123 ( V_2 -> V_101 ) ;
V_2 -> V_111 = V_111 ;
V_2 -> V_123 = V_2 -> V_113 -> V_123 ;
V_103 = F_131 ( V_111 , V_2 ) ;
if ( V_103 ) {
F_99 ( L_58 , V_103 ) ;
F_153 ( V_2 -> V_123 ) ;
goto V_206;
}
return 0 ;
V_206:
F_154 ( V_7 ) ;
return V_103 ;
}
void F_155 ( struct V_190 * V_7 , struct V_190 * V_207 ,
void * V_30 )
{
struct V_1 * V_2 = F_156 ( V_7 ) ;
F_122 ( V_2 -> V_129 ) ;
if ( V_2 -> V_113 -> V_114 ) {
if ( F_157 ( V_2 -> V_113 -> V_114 ) )
F_99 ( L_59 ) ;
}
F_154 ( V_7 ) ;
}
int F_158 ( struct V_190 * V_7 )
{
struct V_1 * V_2 = F_156 ( V_7 ) ;
F_159 ( V_2 -> clock ) ;
if ( V_2 -> V_113 -> V_114 ) {
if ( F_157 ( V_2 -> V_113 -> V_114 ) )
F_99 ( L_59 ) ;
}
return 0 ;
}
int F_160 ( struct V_190 * V_7 )
{
struct V_1 * V_2 = F_156 ( V_7 ) ;
int V_103 ;
V_103 = F_142 ( V_2 -> clock ) ;
if ( V_103 < 0 ) {
F_99 ( L_60 , V_103 ) ;
return V_103 ;
}
if ( V_2 -> V_113 -> V_114 ) {
if ( F_151 ( V_2 -> V_113 -> V_114 ) ) {
F_99 ( L_55 ) ;
return - V_205 ;
}
}
return 0 ;
}
