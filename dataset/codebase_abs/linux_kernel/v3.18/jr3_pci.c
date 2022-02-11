static struct V_1 F_1 ( int V_2 , int V_3 )
{
struct V_1 V_4 ;
V_4 . V_2 = V_2 ;
V_4 . V_3 = V_3 ;
return V_4 ;
}
static int F_2 ( struct V_5 T_1 * V_6 )
{
return F_3 ( & V_6 -> V_7 ) == 0 ;
}
static void F_4 ( struct V_5 T_1 * V_6 ,
struct V_8 V_9 , short V_10 )
{
int V_11 ;
V_10 &= 0x000f ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
F_5 ( & V_6 -> V_12 [ V_10 ] . V_13 [ V_11 ] . V_14 ,
V_9 . V_13 [ V_11 ] . V_14 ) ;
F_6 ( 1 ) ;
F_7 ( & V_6 -> V_12 [ V_10 ] . V_13 [ V_11 ] . V_15 ,
V_9 . V_13 [ V_11 ] . V_15 ) ;
F_6 ( 1 ) ;
if ( V_9 . V_13 [ V_11 ] . V_14 == V_16 )
break;
}
}
static void F_8 ( struct V_5 T_1 * V_6 ,
short V_17 )
{
F_7 ( & V_6 -> V_7 , 0x0500 + ( V_17 & 0x000f ) ) ;
}
static void F_9 ( struct V_5 T_1 * V_6 , short V_18 )
{
F_7 ( & V_6 -> V_7 , 0x0600 + ( V_18 & 0x000f ) ) ;
}
static void F_10 ( struct V_5 T_1 * V_6 )
{
F_7 ( & V_6 -> V_7 , 0x0700 ) ;
}
static void F_11 ( struct V_5 T_1 * V_6 ,
struct V_19 V_20 )
{
F_7 ( & V_6 -> V_20 . V_21 , V_20 . V_21 ) ;
F_7 ( & V_6 -> V_20 . V_22 , V_20 . V_22 ) ;
F_7 ( & V_6 -> V_20 . V_23 , V_20 . V_23 ) ;
F_7 ( & V_6 -> V_20 . V_24 , V_20 . V_24 ) ;
F_7 ( & V_6 -> V_20 . V_25 , V_20 . V_25 ) ;
F_7 ( & V_6 -> V_20 . V_26 , V_20 . V_26 ) ;
F_7 ( & V_6 -> V_7 , 0x0a00 ) ;
}
static struct V_19 F_12 ( struct V_5 T_1
* V_6 )
{
struct V_19 V_4 ;
V_4 . V_21 = F_3 ( & V_6 -> V_27 . V_21 ) ;
V_4 . V_22 = F_3 ( & V_6 -> V_27 . V_22 ) ;
V_4 . V_23 = F_3 ( & V_6 -> V_27 . V_23 ) ;
V_4 . V_24 = F_3 ( & V_6 -> V_27 . V_24 ) ;
V_4 . V_25 = F_3 ( & V_6 -> V_27 . V_25 ) ;
V_4 . V_26 = F_3 ( & V_6 -> V_27 . V_26 ) ;
return V_4 ;
}
static struct V_19 F_13 ( struct V_5 T_1
* V_6 )
{
struct V_19 V_4 ;
V_4 . V_21 = F_3 ( & V_6 -> V_28 . V_21 ) ;
V_4 . V_22 = F_3 ( & V_6 -> V_28 . V_22 ) ;
V_4 . V_23 = F_3 ( & V_6 -> V_28 . V_23 ) ;
V_4 . V_24 = F_3 ( & V_6 -> V_28 . V_24 ) ;
V_4 . V_25 = F_3 ( & V_6 -> V_28 . V_25 ) ;
V_4 . V_26 = F_3 ( & V_6 -> V_28 . V_26 ) ;
return V_4 ;
}
static unsigned int F_14 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int V_33 )
{
struct V_34 * V_35 = V_32 -> V_36 ;
unsigned int V_37 = 0 ;
if ( V_35 -> V_38 != V_39 )
return 0 ;
if ( V_33 < 56 ) {
unsigned int V_40 = V_33 % 8 ;
unsigned V_41 = V_33 / 8 ;
switch ( V_40 ) {
case 0 :
V_37 = F_3 ( & V_35 -> V_6 -> V_41 [ V_41 ] . V_21 ) ;
break;
case 1 :
V_37 = F_3 ( & V_35 -> V_6 -> V_41 [ V_41 ] . V_22 ) ;
break;
case 2 :
V_37 = F_3 ( & V_35 -> V_6 -> V_41 [ V_41 ] . V_23 ) ;
break;
case 3 :
V_37 = F_3 ( & V_35 -> V_6 -> V_41 [ V_41 ] . V_24 ) ;
break;
case 4 :
V_37 = F_3 ( & V_35 -> V_6 -> V_41 [ V_41 ] . V_25 ) ;
break;
case 5 :
V_37 = F_3 ( & V_35 -> V_6 -> V_41 [ V_41 ] . V_26 ) ;
break;
case 6 :
V_37 = F_3 ( & V_35 -> V_6 -> V_41 [ V_41 ] . V_42 ) ;
break;
case 7 :
V_37 = F_3 ( & V_35 -> V_6 -> V_41 [ V_41 ] . V_43 ) ;
break;
}
V_37 += 0x4000 ;
} else if ( V_33 == 56 ) {
V_37 = F_15 ( & V_35 -> V_6 -> V_44 ) ;
} else if ( V_33 == 57 ) {
V_37 = F_15 ( & V_35 -> V_6 -> V_45 ) ;
}
return V_37 ;
}
static int F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
struct V_34 * V_35 = V_32 -> V_36 ;
unsigned int V_33 = F_17 ( V_47 -> V_49 ) ;
T_2 V_50 ;
int V_11 ;
if ( ! V_35 )
return - V_51 ;
V_50 = F_15 ( & V_35 -> V_6 -> V_50 ) ;
if ( V_35 -> V_38 != V_39 ||
( V_50 & ( V_52 | V_53 | V_54 ) ) ) {
if ( V_35 -> V_38 == V_39 ) {
V_35 -> V_38 = V_55 ;
}
return - V_56 ;
}
for ( V_11 = 0 ; V_11 < V_47 -> V_57 ; V_11 ++ )
V_48 [ V_11 ] = F_14 ( V_30 , V_32 , V_33 ) ;
return V_47 -> V_57 ;
}
static int F_18 ( struct V_29 * V_30 )
{
struct V_34 * V_35 ;
struct V_31 * V_32 ;
int V_11 ;
F_19 ( V_30 -> V_58 , L_1 ) ;
for ( V_11 = 0 ; V_11 < V_30 -> V_59 ; V_11 ++ ) {
V_32 = & V_30 -> V_60 [ V_11 ] ;
V_35 = V_32 -> V_36 ;
if ( V_35 )
F_19 ( V_30 -> V_58 , L_2 ,
V_35 , V_35 -> V_45 , V_32 -> V_61 ) ;
}
return 0 ;
}
static int F_20 ( const T_3 * V_48 , T_4 V_62 , int * V_63 ,
unsigned int * V_37 )
{
int V_4 = 0 ;
int V_64 ;
if ( V_63 && V_37 ) {
for (; * V_63 < V_62 && ! isxdigit ( V_48 [ * V_63 ] ) ; ( * V_63 ) ++ )
;
* V_37 = 0 ;
for (; * V_63 < V_62 ; ( * V_63 ) ++ ) {
V_64 = F_21 ( V_48 [ * V_63 ] ) ;
if ( V_64 >= 0 ) {
V_4 = 1 ;
* V_37 = ( * V_37 << 4 ) + V_64 ;
} else {
break;
}
}
}
return V_4 ;
}
static int F_22 ( struct V_29 * V_30 ,
const T_3 * V_48 , T_4 V_62 )
{
int V_65 = 1 ;
int V_63 = 0 ;
while ( V_65 ) {
unsigned int V_66 = 0 ;
unsigned int V_67 = 0 ;
V_65 = V_65 && F_20 ( V_48 , V_62 , & V_63 , & V_66 ) ;
if ( V_65 && V_66 == 0xffff )
return 0 ;
V_65 = V_65 && F_20 ( V_48 , V_62 , & V_63 , & V_67 ) ;
while ( V_65 && V_66 > 0 ) {
unsigned int V_68 = 0 ;
V_65 = V_65 && F_20 ( V_48 , V_62 , & V_63 , & V_68 ) ;
V_66 -- ;
}
}
return - V_69 ;
}
static void F_23 ( struct V_29 * V_30 ,
int V_70 , const T_3 * V_48 , T_4 V_62 )
{
struct V_71 * V_72 = V_30 -> V_36 ;
struct V_73 T_1 * V_74 = V_72 -> V_74 ;
T_5 T_1 * V_75 ;
T_5 T_1 * V_76 ;
int V_65 = 1 ;
int V_63 = 0 ;
while ( V_65 ) {
unsigned int V_66 = 0 ;
unsigned int V_67 = 0 ;
V_65 = V_65 && F_20 ( V_48 , V_62 , & V_63 , & V_66 ) ;
if ( V_65 && V_66 == 0xffff )
return;
V_65 = V_65 && F_20 ( V_48 , V_62 , & V_63 , & V_67 ) ;
F_19 ( V_30 -> V_58 , L_3 ,
V_70 , V_66 , V_67 ) ;
while ( V_65 && V_66 > 0 ) {
if ( V_67 & 0x4000 ) {
unsigned int V_77 = 0 ;
V_65 = V_65 &&
F_20 ( V_48 , V_62 , & V_63 , & V_77 ) ;
V_66 -- ;
} else {
unsigned int V_77 = 0 ;
unsigned int V_78 = 0 ;
V_75 = & V_74 -> V_6 [ V_70 ] . V_79 [ V_67 ] ;
V_76 = & V_74 -> V_6 [ V_70 ] . V_80 [ V_67 ] ;
V_65 = V_65 &&
F_20 ( V_48 , V_62 , & V_63 , & V_77 ) ;
V_65 = V_65 &&
F_20 ( V_48 , V_62 , & V_63 , & V_78 ) ;
V_66 -= 2 ;
if ( V_65 ) {
F_5 ( V_75 , V_77 ) ;
F_6 ( 1 ) ;
F_5 ( V_76 , V_78 ) ;
F_6 ( 1 ) ;
}
}
V_67 ++ ;
}
}
}
static int F_24 ( struct V_29 * V_30 ,
const T_3 * V_48 , T_4 V_62 ,
unsigned long V_81 )
{
int V_70 ;
int V_82 ;
V_82 = F_22 ( V_30 , V_48 , V_62 ) ;
if ( V_82 )
return V_82 ;
for ( V_70 = 0 ; V_70 < V_30 -> V_59 ; V_70 ++ )
F_23 ( V_30 , V_70 , V_48 , V_62 ) ;
return 0 ;
}
static struct V_1 F_25 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = V_32 -> V_36 ;
struct V_1 V_4 = F_1 ( 1000 , 2000 ) ;
struct V_5 T_1 * V_6 ;
T_2 V_44 ;
T_2 V_45 ;
int V_50 ;
int V_11 ;
if ( ! V_35 )
return V_4 ;
V_6 = V_35 -> V_6 ;
V_50 = F_15 ( & V_6 -> V_50 ) ;
if ( V_50 != V_35 -> V_50 )
V_35 -> V_50 = V_50 ;
if ( V_50 & ( V_52 | V_53 | V_54 ) )
V_35 -> V_38 = V_55 ;
switch ( V_35 -> V_38 ) {
case V_55 :
V_44 = F_15 ( & V_6 -> V_44 ) ;
V_45 = F_15 ( & V_6 -> V_45 ) ;
if ( ( V_50 & ( V_52 | V_53 ) ) ||
V_44 == 0 || V_45 == 0 ) {
} else {
V_35 -> V_83 = 0 ;
V_35 -> V_38 = V_84 ;
}
break;
case V_84 :
V_35 -> V_83 ++ ;
if ( V_35 -> V_83 < 10 ) {
} else {
struct V_8 V_9 ;
V_35 -> V_44 = F_15 ( & V_6 -> V_44 ) ;
V_35 -> V_45 = F_15 ( & V_6 -> V_45 ) ;
for ( V_11 = 0 ; V_11 < F_26 ( V_9 . V_13 ) ; V_11 ++ ) {
V_9 . V_13 [ V_11 ] . V_14 = (enum V_85 ) 0 ;
V_9 . V_13 [ V_11 ] . V_15 = 0 ;
}
F_4 ( V_6 , V_9 , 0 ) ;
F_8 ( V_6 , 0 ) ;
V_35 -> V_38 = V_86 ;
V_4 = F_1 ( 20 , 100 ) ;
}
break;
case V_86 :
if ( ! F_2 ( V_6 ) ) {
V_4 = F_1 ( 20 , 100 ) ;
} else {
struct V_19 V_27 ;
struct V_19 V_28 ;
V_27 = F_12 ( V_6 ) ;
V_28 = F_13 ( V_6 ) ;
F_11 ( V_6 , V_28 ) ;
V_35 -> V_38 = V_87 ;
V_4 = F_1 ( 20 , 100 ) ;
}
break;
case V_87 :
if ( ! F_2 ( V_6 ) ) {
V_4 = F_1 ( 20 , 100 ) ;
} else {
struct V_88 T_1 * V_89 = & V_6 -> V_20 ;
V_35 -> V_90 [ 0 ] . V_90 . V_2 = - F_3 ( & V_89 -> V_21 ) * 1000 ;
V_35 -> V_90 [ 0 ] . V_90 . V_3 = F_3 ( & V_89 -> V_21 ) * 1000 ;
V_35 -> V_90 [ 1 ] . V_90 . V_2 = - F_3 ( & V_89 -> V_22 ) * 1000 ;
V_35 -> V_90 [ 1 ] . V_90 . V_3 = F_3 ( & V_89 -> V_22 ) * 1000 ;
V_35 -> V_90 [ 2 ] . V_90 . V_2 = - F_3 ( & V_89 -> V_23 ) * 1000 ;
V_35 -> V_90 [ 2 ] . V_90 . V_3 = F_3 ( & V_89 -> V_23 ) * 1000 ;
V_35 -> V_90 [ 3 ] . V_90 . V_2 = - F_3 ( & V_89 -> V_24 ) * 100 ;
V_35 -> V_90 [ 3 ] . V_90 . V_3 = F_3 ( & V_89 -> V_24 ) * 100 ;
V_35 -> V_90 [ 4 ] . V_90 . V_2 = - F_3 ( & V_89 -> V_25 ) * 100 ;
V_35 -> V_90 [ 4 ] . V_90 . V_3 = F_3 ( & V_89 -> V_25 ) * 100 ;
V_35 -> V_90 [ 5 ] . V_90 . V_2 = - F_3 ( & V_89 -> V_26 ) * 100 ;
V_35 -> V_90 [ 5 ] . V_90 . V_3 = F_3 ( & V_89 -> V_26 ) * 100 ;
V_35 -> V_90 [ 6 ] . V_90 . V_2 = - F_3 ( & V_89 -> V_42 ) * 100 ;
V_35 -> V_90 [ 6 ] . V_90 . V_3 = F_3 ( & V_89 -> V_42 ) * 100 ;
V_35 -> V_90 [ 7 ] . V_90 . V_2 = - F_3 ( & V_89 -> V_43 ) * 100 ;
V_35 -> V_90 [ 7 ] . V_90 . V_3 = F_3 ( & V_89 -> V_43 ) * 100 ;
V_35 -> V_90 [ 8 ] . V_90 . V_2 = 0 ;
V_35 -> V_90 [ 8 ] . V_90 . V_3 = 65535 ;
F_9 ( V_6 , 0 ) ;
V_35 -> V_38 = V_91 ;
V_4 = F_1 ( 40 , 100 ) ;
}
break;
case V_91 :
if ( ! F_2 ( V_6 ) ) {
V_4 = F_1 ( 20 , 100 ) ;
} else {
F_7 ( & V_6 -> V_92 . V_21 , 0 ) ;
F_7 ( & V_6 -> V_92 . V_22 , 0 ) ;
F_7 ( & V_6 -> V_92 . V_23 , 0 ) ;
F_7 ( & V_6 -> V_92 . V_24 , 0 ) ;
F_7 ( & V_6 -> V_92 . V_25 , 0 ) ;
F_7 ( & V_6 -> V_92 . V_26 , 0 ) ;
F_10 ( V_6 ) ;
V_35 -> V_38 = V_39 ;
}
break;
case V_39 :
V_4 = F_1 ( 10000 , 20000 ) ;
break;
default:
break;
}
return V_4 ;
}
static void F_27 ( unsigned long V_48 )
{
struct V_29 * V_30 = (struct V_29 * ) V_48 ;
struct V_71 * V_72 = V_30 -> V_36 ;
struct V_34 * V_35 ;
struct V_31 * V_32 ;
unsigned long V_93 ;
unsigned long V_94 ;
int V_95 ;
int V_11 ;
F_28 ( & V_30 -> V_96 , V_93 ) ;
V_95 = 1000 ;
V_94 = V_97 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_59 ; V_11 ++ ) {
V_32 = & V_30 -> V_60 [ V_11 ] ;
V_35 = V_32 -> V_36 ;
if ( V_94 > V_35 -> V_98 ) {
struct V_1 V_99 ;
V_99 = F_25 ( V_32 ) ;
V_35 -> V_98 = V_97 +
F_29 ( V_99 . V_2 ) ;
V_35 -> V_100 = V_97 +
F_29 ( V_99 . V_3 ) ;
if ( V_99 . V_3 && V_99 . V_3 < V_95 )
V_95 = V_99 . V_3 ;
}
}
F_30 ( & V_30 -> V_96 , V_93 ) ;
V_72 -> V_101 . V_102 = V_97 + F_29 ( V_95 ) ;
F_31 ( & V_72 -> V_101 ) ;
}
static struct V_34 *
F_32 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_71 * V_72 = V_30 -> V_36 ;
struct V_34 * V_35 ;
int V_103 ;
int V_104 ;
V_35 = F_33 ( V_32 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_6 = & V_72 -> V_74 -> V_6 [ V_32 -> V_61 ] . V_48 ;
for ( V_103 = 0 ; V_103 < 8 ; V_103 ++ ) {
V_35 -> V_90 [ V_103 ] . V_105 = 1 ;
V_35 -> V_90 [ V_103 ] . V_90 . V_2 = - 1000000 ;
V_35 -> V_90 [ V_103 ] . V_90 . V_3 = 1000000 ;
for ( V_104 = 0 ; V_104 < 7 ; V_104 ++ ) {
V_35 -> V_106 [ V_103 + V_104 * 8 ] =
(struct V_107 * ) & V_35 -> V_90 [ V_103 ] ;
V_35 -> V_108 [ V_103 + V_104 * 8 ] = 0x7fff ;
}
}
V_35 -> V_90 [ 8 ] . V_105 = 1 ;
V_35 -> V_90 [ 8 ] . V_90 . V_2 = 0 ;
V_35 -> V_90 [ 8 ] . V_90 . V_3 = 65536 ;
V_35 -> V_106 [ 56 ] = (struct V_107 * ) & V_35 -> V_90 [ 8 ] ;
V_35 -> V_106 [ 57 ] = (struct V_107 * ) & V_35 -> V_90 [ 8 ] ;
V_35 -> V_108 [ 56 ] = 0xffff ;
V_35 -> V_108 [ 57 ] = 0xffff ;
F_19 ( V_30 -> V_58 , L_4 ,
V_35 -> V_6 , V_72 -> V_74 ,
( ( char T_1 * ) V_35 -> V_6 -
( char T_1 * ) V_72 -> V_74 ) ) ;
return V_35 ;
}
static int F_34 ( struct V_29 * V_30 ,
unsigned long V_81 )
{
struct V_109 * V_110 = F_35 ( V_30 ) ;
static const struct V_111 * V_112 ;
struct V_71 * V_72 ;
struct V_34 * V_35 ;
struct V_31 * V_32 ;
int V_82 ;
int V_11 ;
if ( sizeof( struct V_5 ) != 0xc00 ) {
F_36 ( V_30 -> V_58 ,
L_5 ,
( unsigned ) sizeof( struct V_5 ) , 0xc00 ) ;
return - V_51 ;
}
if ( V_81 < F_26 ( V_113 ) )
V_112 = & V_113 [ V_81 ] ;
if ( ! V_112 )
return - V_114 ;
V_30 -> V_115 = V_112 ;
V_30 -> V_116 = V_112 -> V_117 ;
V_72 = F_37 ( V_30 , sizeof( * V_72 ) ) ;
if ( ! V_72 )
return - V_118 ;
F_38 ( & V_72 -> V_101 ) ;
V_82 = F_39 ( V_30 ) ;
if ( V_82 )
return V_82 ;
V_72 -> V_74 = F_40 ( V_110 , 0 ) ;
if ( ! V_72 -> V_74 )
return - V_118 ;
V_82 = F_41 ( V_30 , V_112 -> V_119 ) ;
if ( V_82 )
return V_82 ;
V_30 -> V_120 = F_18 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_59 ; V_11 ++ ) {
V_32 = & V_30 -> V_60 [ V_11 ] ;
V_32 -> type = V_121 ;
V_32 -> V_122 = V_123 | V_124 ;
V_32 -> V_125 = 8 * 7 + 2 ;
V_32 -> V_126 = F_16 ;
V_35 = F_32 ( V_30 , V_32 ) ;
if ( V_35 ) {
V_32 -> V_106 = V_35 -> V_106 ;
V_32 -> V_108 = V_35 -> V_108 ;
}
}
F_42 ( 0 , & V_72 -> V_74 -> V_6 [ 0 ] . V_127 ) ;
V_82 = F_43 ( V_30 , & F_35 ( V_30 ) -> V_30 ,
L_6 ,
F_24 , 0 ) ;
F_19 ( V_30 -> V_58 , L_7 , V_82 ) ;
if ( V_82 < 0 )
return V_82 ;
F_44 ( 25 ) ;
for ( V_11 = 0 ; V_11 < 0x18 ; V_11 ++ ) {
F_19 ( V_30 -> V_58 , L_8 ,
F_15 ( & V_72 -> V_74 -> V_6 [ 0 ] .
V_48 . V_128 [ V_11 ] ) >> 8 ) ;
}
for ( V_11 = 0 ; V_11 < V_30 -> V_59 ; V_11 ++ ) {
V_32 = & V_30 -> V_60 [ V_11 ] ;
V_35 = V_32 -> V_36 ;
V_35 -> V_98 = V_97 + F_29 ( 500 ) ;
V_35 -> V_100 = V_97 + F_29 ( 2000 ) ;
}
V_72 -> V_101 . V_48 = ( unsigned long ) V_30 ;
V_72 -> V_101 . V_129 = F_27 ;
V_72 -> V_101 . V_102 = V_97 + F_29 ( 1000 ) ;
F_31 ( & V_72 -> V_101 ) ;
return 0 ;
}
static void F_45 ( struct V_29 * V_30 )
{
struct V_71 * V_72 = V_30 -> V_36 ;
if ( V_72 ) {
F_46 ( & V_72 -> V_101 ) ;
if ( V_72 -> V_74 )
F_47 ( V_72 -> V_74 ) ;
}
F_48 ( V_30 ) ;
}
static int F_49 ( struct V_109 * V_30 ,
const struct V_130 * V_131 )
{
return F_50 ( V_30 , & V_132 , V_131 -> V_133 ) ;
}
