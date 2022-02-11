int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
V_2 -> V_4 = F_2 ( V_4 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = F_3 ( - 1 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_9 , V_10 , ( unsigned long ) V_2 ) ;
V_2 -> V_11 = 0 ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( F_8 ( V_2 ) ) ;
F_9 ( & V_2 -> V_8 ) ;
F_10 ( V_2 -> V_4 ) ;
}
void F_11 ( struct V_1 * V_2 ,
unsigned int V_12 ,
unsigned int V_13 ,
unsigned int V_14 )
{
static const unsigned int V_15 [] = {
[ V_16 ] = 32000 ,
[ V_17 ] = 44100 ,
[ V_18 ] = 48000 ,
[ V_19 ] = 88200 ,
[ V_20 ] = 96000 ,
[ V_21 ] = 176400 ,
[ V_22 ] = 192000 ,
} ;
unsigned int V_23 ;
if ( F_7 ( F_8 ( V_2 ) ) )
return;
for ( V_23 = 0 ; V_23 < V_24 ; ++ V_23 )
if ( V_15 [ V_23 ] == V_12 )
goto V_25;
F_7 ( 1 ) ;
return;
V_25:
V_2 -> V_26 = ( V_2 -> V_6 & V_27 ) && V_23 > V_20 ;
if ( V_2 -> V_26 ) {
V_23 -= 2 ;
V_12 /= 2 ;
V_13 *= 2 ;
}
V_2 -> V_23 = V_23 ;
V_2 -> V_28 = V_13 + F_12 ( V_14 , 8 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_29 = V_30 [ V_23 ] ;
V_2 -> V_31 = V_32 - V_33 ;
if ( V_2 -> V_6 & V_34 )
V_2 -> V_31 += V_35 * V_2 -> V_29 / V_12 ;
}
unsigned int F_13 ( struct V_1 * V_2 )
{
return 8 + V_2 -> V_29 * V_2 -> V_28 * 4 ;
}
void F_14 ( struct V_1 * V_2 ,
T_1 V_36 )
{
if ( F_7 ( F_8 ( V_2 ) ) )
return;
switch ( V_36 ) {
default:
F_7 ( 1 ) ;
case V_37 :
if ( V_2 -> V_26 )
V_2 -> V_38 = V_39 ;
else
V_2 -> V_38 = V_40 ;
break;
case V_41 :
if ( V_2 -> V_26 )
V_2 -> V_38 = V_42 ;
else
V_2 -> V_38 = V_43 ;
break;
}
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_9 ) ;
V_2 -> V_44 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = true ;
}
static unsigned int F_17 ( struct V_1 * V_2 )
{
unsigned int V_47 , V_48 ;
if ( ! F_18 ( V_2 -> V_23 ) ) {
V_48 = V_2 -> V_49 ;
} else {
V_47 = V_2 -> V_49 ;
if ( V_2 -> V_23 == V_17 )
V_48 = 5 + ( ( V_47 & 1 ) ^
( V_47 == 0 || V_47 >= 40 ) ) ;
else
V_48 = 11 * ( V_2 -> V_23 >> 1 ) + ( V_47 == 0 ) ;
if ( ++ V_47 >= ( 80 >> ( V_2 -> V_23 >> 1 ) ) )
V_47 = 0 ;
V_2 -> V_49 = V_47 ;
}
return V_48 ;
}
static unsigned int F_19 ( struct V_1 * V_2 ,
unsigned int V_50 )
{
unsigned int V_51 , V_47 , V_52 , V_53 ;
if ( V_2 -> V_54 < V_33 ) {
if ( ! F_18 ( V_2 -> V_23 ) )
V_51 = V_2 -> V_54 + V_2 -> V_55 ;
else {
V_47 = V_2 -> V_55 ;
V_52 = V_47 % 13 ;
V_51 = V_2 -> V_54 ;
V_51 += 1386 + ( ( V_52 && ! ( V_52 & 3 ) ) ||
V_47 == 146 ) ;
if ( ++ V_47 >= 147 )
V_47 = 0 ;
V_2 -> V_55 = V_47 ;
}
} else
V_51 = V_2 -> V_54 - V_33 ;
V_2 -> V_54 = V_51 ;
if ( V_51 < V_33 ) {
V_51 += V_2 -> V_31 ;
V_53 = ( V_50 + V_51 / V_33 ) << 12 ;
V_53 += V_51 % V_33 ;
return V_53 & 0xffff ;
} else {
return 0xffff ;
}
}
static void V_43 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
T_2 * V_58 , unsigned int V_59 )
{
struct V_60 * V_61 = V_57 -> V_61 ;
unsigned int V_62 , V_63 , V_64 , V_65 , V_66 ;
const T_3 * V_67 ;
V_62 = V_2 -> V_13 ;
V_67 = ( void * ) V_61 -> V_68 +
F_20 ( V_61 , V_2 -> V_44 ) ;
V_63 = V_61 -> V_69 - V_2 -> V_44 ;
V_64 = V_2 -> V_28 - V_62 ;
for ( V_65 = 0 ; V_65 < V_59 ; ++ V_65 ) {
for ( V_66 = 0 ; V_66 < V_62 ; ++ V_66 ) {
* V_58 = F_21 ( ( * V_67 >> 8 ) | 0x40000000 ) ;
V_67 ++ ;
V_58 ++ ;
}
V_58 += V_64 ;
if ( -- V_63 == 0 )
V_67 = ( void * ) V_61 -> V_68 ;
}
}
static void V_40 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
T_2 * V_58 , unsigned int V_59 )
{
struct V_60 * V_61 = V_57 -> V_61 ;
unsigned int V_62 , V_63 , V_64 , V_65 , V_66 ;
const T_4 * V_67 ;
V_62 = V_2 -> V_13 ;
V_67 = ( void * ) V_61 -> V_68 +
F_20 ( V_61 , V_2 -> V_44 ) ;
V_63 = V_61 -> V_69 - V_2 -> V_44 ;
V_64 = V_2 -> V_28 - V_62 ;
for ( V_65 = 0 ; V_65 < V_59 ; ++ V_65 ) {
for ( V_66 = 0 ; V_66 < V_62 ; ++ V_66 ) {
* V_58 = F_21 ( ( * V_67 << 8 ) | 0x40000000 ) ;
V_67 ++ ;
V_58 ++ ;
}
V_58 += V_64 ;
if ( -- V_63 == 0 )
V_67 = ( void * ) V_61 -> V_68 ;
}
}
static void V_42 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
T_2 * V_58 , unsigned int V_59 )
{
struct V_60 * V_61 = V_57 -> V_61 ;
unsigned int V_62 , V_70 , V_71 , V_65 , V_66 ;
const T_3 * V_67 ;
V_62 = V_2 -> V_13 ;
V_67 = ( void * ) V_61 -> V_68 +
V_2 -> V_44 * ( V_61 -> V_72 / 8 ) ;
V_70 = V_62 - 1 ;
V_71 = 1 - ( V_2 -> V_28 - V_62 ) ;
V_62 /= 2 ;
for ( V_65 = 0 ; V_65 < V_59 ; ++ V_65 ) {
for ( V_66 = 0 ; V_66 < V_62 ; ++ V_66 ) {
* V_58 = F_21 ( ( * V_67 >> 8 ) | 0x40000000 ) ;
V_67 ++ ;
V_58 += 2 ;
}
V_58 -= V_70 ;
for ( V_66 = 0 ; V_66 < V_62 ; ++ V_66 ) {
* V_58 = F_21 ( ( * V_67 >> 8 ) | 0x40000000 ) ;
V_67 ++ ;
V_58 += 2 ;
}
V_58 -= V_71 ;
}
}
static void V_39 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
T_2 * V_58 , unsigned int V_59 )
{
struct V_60 * V_61 = V_57 -> V_61 ;
unsigned int V_62 , V_70 , V_71 , V_65 , V_66 ;
const T_4 * V_67 ;
V_62 = V_2 -> V_13 ;
V_67 = ( void * ) V_61 -> V_68 +
V_2 -> V_44 * ( V_61 -> V_72 / 8 ) ;
V_70 = V_62 - 1 ;
V_71 = 1 - ( V_2 -> V_28 - V_62 ) ;
V_62 /= 2 ;
for ( V_65 = 0 ; V_65 < V_59 ; ++ V_65 ) {
for ( V_66 = 0 ; V_66 < V_62 ; ++ V_66 ) {
* V_58 = F_21 ( ( * V_67 << 8 ) | 0x40000000 ) ;
V_67 ++ ;
V_58 += 2 ;
}
V_58 -= V_70 ;
for ( V_66 = 0 ; V_66 < V_62 ; ++ V_66 ) {
* V_58 = F_21 ( ( * V_67 << 8 ) | 0x40000000 ) ;
V_67 ++ ;
V_58 += 2 ;
}
V_58 -= V_71 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
T_2 * V_58 , unsigned int V_59 )
{
unsigned int V_65 , V_66 ;
for ( V_65 = 0 ; V_65 < V_59 ; ++ V_65 ) {
for ( V_66 = 0 ; V_66 < V_2 -> V_13 ; ++ V_66 )
V_58 [ V_66 ] = F_21 ( 0x40000000 ) ;
V_58 += V_2 -> V_28 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
T_2 * V_58 , unsigned int V_59 )
{
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_59 ; ++ V_65 )
V_58 [ V_2 -> V_13 + V_65 * V_2 -> V_28 ] =
F_21 ( 0x80000000 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_50 )
{
T_2 * V_58 ;
unsigned int V_52 , V_48 , V_53 , V_73 ;
struct V_56 * V_57 ;
struct V_74 V_75 ;
int V_76 ;
if ( V_2 -> V_11 < 0 )
return;
V_52 = V_2 -> V_11 ;
V_53 = F_19 ( V_2 , V_50 ) ;
if ( ! ( V_2 -> V_6 & V_34 ) )
V_48 = F_17 ( V_2 ) ;
else if ( V_53 != 0xffff )
V_48 = V_2 -> V_29 ;
else
V_48 = 0 ;
V_58 = V_2 -> V_58 . V_77 [ V_52 ] . V_58 ;
V_58 [ 0 ] = F_21 ( F_25 ( V_2 -> V_78 ) |
( V_2 -> V_28 << 16 ) |
V_2 -> V_79 ) ;
V_58 [ 1 ] = F_21 ( V_80 | V_81 | V_82 |
( V_2 -> V_23 << V_83 ) | V_53 ) ;
V_58 += 2 ;
V_57 = F_25 ( V_2 -> V_57 ) ;
if ( V_57 )
V_2 -> V_38 ( V_2 , V_57 , V_58 , V_48 ) ;
else
F_22 ( V_2 , V_58 , V_48 ) ;
if ( V_2 -> V_14 )
F_23 ( V_2 , V_58 , V_48 ) ;
V_2 -> V_79 = ( V_2 -> V_79 + V_48 ) & 0xff ;
V_75 . V_84 = 8 + V_48 * 4 * V_2 -> V_28 ;
V_75 . V_85 = F_26 ( V_52 + 1 , V_86 ) ;
V_75 . V_87 = 0 ;
V_75 . V_88 = V_89 ;
V_75 . V_90 = 0 ;
V_75 . V_91 = 0 ;
V_76 = F_27 ( V_2 -> V_7 , & V_75 , & V_2 -> V_58 . V_92 ,
V_2 -> V_58 . V_77 [ V_52 ] . V_93 ) ;
if ( V_76 < 0 ) {
F_28 ( & V_2 -> V_4 -> V_94 , L_1 , V_76 ) ;
V_2 -> V_11 = - 1 ;
F_29 ( V_2 ) ;
return;
}
if ( ++ V_52 >= V_95 )
V_52 = 0 ;
V_2 -> V_11 = V_52 ;
if ( V_57 ) {
if ( V_2 -> V_26 )
V_48 *= 2 ;
V_73 = V_2 -> V_44 + V_48 ;
if ( V_73 >= V_57 -> V_61 -> V_69 )
V_73 -= V_57 -> V_61 -> V_69 ;
F_25 ( V_2 -> V_44 ) = V_73 ;
V_2 -> V_45 += V_48 ;
if ( V_2 -> V_45 >= V_57 -> V_61 -> V_96 ) {
V_2 -> V_45 -= V_57 -> V_61 -> V_96 ;
V_2 -> V_46 = false ;
F_30 ( & V_2 -> V_9 ) ;
}
}
}
static void V_10 ( unsigned long V_97 )
{
struct V_1 * V_2 = ( void * ) V_97 ;
struct V_56 * V_57 = F_25 ( V_2 -> V_57 ) ;
if ( V_57 )
F_31 ( V_57 ) ;
}
static void F_32 ( struct V_98 * V_7 , T_3 V_50 ,
T_5 V_91 , void * V_99 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
unsigned int V_65 , V_77 = V_91 / 4 ;
V_50 += V_95 - V_77 ;
for ( V_65 = 0 ; V_65 < V_77 ; ++ V_65 )
F_24 ( V_2 , ++ V_50 ) ;
F_33 ( V_2 -> V_7 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_74 V_100 = {
. V_87 = 1 ,
} ;
unsigned int V_65 ;
int V_76 ;
for ( V_65 = 0 ; V_65 < V_95 ; ++ V_65 ) {
V_100 . V_85 = F_26 ( V_2 -> V_11 + 1 ,
V_86 ) ;
V_76 = F_27 ( V_2 -> V_7 , & V_100 , NULL , 0 ) ;
if ( V_76 < 0 )
return V_76 ;
if ( ++ V_2 -> V_11 >= V_95 )
V_2 -> V_11 = 0 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 , int V_101 , int V_102 )
{
static const struct {
unsigned int V_103 ;
unsigned int V_51 ;
} V_104 [] = {
[ V_16 ] = { 4 , 3072 } ,
[ V_18 ] = { 6 , 1024 } ,
[ V_20 ] = { 12 , 1024 } ,
[ V_22 ] = { 24 , 1024 } ,
[ V_17 ] = { 0 , 67 } ,
[ V_19 ] = { 0 , 67 } ,
[ V_21 ] = { 0 , 67 } ,
} ;
int V_76 ;
F_36 ( & V_2 -> V_8 ) ;
if ( F_7 ( F_8 ( V_2 ) ||
( ! V_2 -> V_13 && ! V_2 -> V_14 ) ) ) {
V_76 = - V_105 ;
goto V_106;
}
V_2 -> V_49 = V_104 [ V_2 -> V_23 ] . V_103 ;
V_2 -> V_55 = V_104 [ V_2 -> V_23 ] . V_51 ;
V_2 -> V_54 = V_33 ;
V_76 = F_37 ( & V_2 -> V_58 , V_2 -> V_4 , V_95 ,
F_13 ( V_2 ) ,
V_107 ) ;
if ( V_76 < 0 )
goto V_106;
V_2 -> V_7 = F_38 ( F_39 ( V_2 -> V_4 ) -> V_108 ,
V_109 ,
V_101 , V_102 , 0 ,
F_32 , V_2 ) ;
if ( F_40 ( V_2 -> V_7 ) ) {
V_76 = F_41 ( V_2 -> V_7 ) ;
if ( V_76 == - V_110 )
F_28 ( & V_2 -> V_4 -> V_94 ,
L_2 ) ;
goto V_111;
}
F_42 ( V_2 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_79 = 0 ;
V_76 = F_34 ( V_2 ) ;
if ( V_76 < 0 )
goto V_112;
V_76 = F_43 ( V_2 -> V_7 , - 1 , 0 , 0 ) ;
if ( V_76 < 0 )
goto V_112;
F_44 ( & V_2 -> V_8 ) ;
return 0 ;
V_112:
F_45 ( V_2 -> V_7 ) ;
V_2 -> V_7 = F_3 ( - 1 ) ;
V_111:
F_46 ( & V_2 -> V_58 , V_2 -> V_4 ) ;
V_106:
F_44 ( & V_2 -> V_8 ) ;
return V_76 ;
}
unsigned long F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 )
F_48 ( V_2 -> V_7 ) ;
else
V_2 -> V_46 = true ;
return F_25 ( V_2 -> V_44 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_78 ) =
( F_39 ( V_2 -> V_4 ) -> V_108 -> V_113 & 0x3f ) << 24 ;
}
void F_49 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_8 ) ;
if ( ! F_8 ( V_2 ) ) {
F_44 ( & V_2 -> V_8 ) ;
return;
}
F_16 ( & V_2 -> V_9 ) ;
F_50 ( V_2 -> V_7 ) ;
F_45 ( V_2 -> V_7 ) ;
V_2 -> V_7 = F_3 ( - 1 ) ;
F_46 ( & V_2 -> V_58 , V_2 -> V_4 ) ;
F_44 ( & V_2 -> V_8 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
V_57 = F_25 ( V_2 -> V_57 ) ;
if ( V_57 ) {
F_51 ( V_57 ) ;
if ( F_52 ( V_57 ) )
F_53 ( V_57 , V_114 ) ;
F_54 ( V_57 ) ;
}
}
