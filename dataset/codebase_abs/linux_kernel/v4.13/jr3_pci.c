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
const struct V_8 * V_9 , short V_10 )
{
int V_11 ;
V_10 &= 0x000f ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
F_5 ( & V_6 -> V_12 [ V_10 ] . V_13 [ V_11 ] . V_14 ,
V_9 -> V_13 [ V_11 ] . V_14 ) ;
F_6 ( 1 ) ;
F_7 ( & V_6 -> V_12 [ V_10 ] . V_13 [ V_11 ] . V_15 ,
V_9 -> V_13 [ V_11 ] . V_15 ) ;
F_6 ( 1 ) ;
if ( V_9 -> V_13 [ V_11 ] . V_14 == V_16 )
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
static struct V_19 F_12 ( struct V_5 T_1 * V_6 )
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
static struct V_19 F_13 ( struct V_5 T_1 * V_6 )
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
unsigned int V_41 = V_33 / 8 ;
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
V_50 = F_15 ( & V_35 -> V_6 -> V_50 ) ;
if ( V_35 -> V_38 != V_39 ||
( V_50 & ( V_51 | V_52 | V_53 ) ) ) {
if ( V_35 -> V_38 == V_39 ) {
V_35 -> V_38 = V_54 ;
}
return - V_55 ;
}
for ( V_11 = 0 ; V_11 < V_47 -> V_56 ; V_11 ++ )
V_48 [ V_11 ] = F_14 ( V_30 , V_32 , V_33 ) ;
return V_47 -> V_56 ;
}
static int F_18 ( struct V_29 * V_30 )
{
struct V_34 * V_35 ;
struct V_31 * V_32 ;
int V_11 ;
F_19 ( V_30 -> V_57 , L_1 ) ;
for ( V_11 = 0 ; V_11 < V_30 -> V_58 ; V_11 ++ ) {
V_32 = & V_30 -> V_59 [ V_11 ] ;
V_35 = V_32 -> V_36 ;
F_19 ( V_30 -> V_57 , L_2 , V_32 -> V_60 ,
V_35 -> V_45 ) ;
}
return 0 ;
}
static int F_20 ( const T_3 * V_48 , T_4 V_61 , int * V_62 ,
unsigned int * V_37 )
{
int V_4 = 0 ;
int V_63 ;
if ( V_62 && V_37 ) {
for (; * V_62 < V_61 && ! isxdigit ( V_48 [ * V_62 ] ) ; ( * V_62 ) ++ )
;
* V_37 = 0 ;
for (; * V_62 < V_61 ; ( * V_62 ) ++ ) {
V_63 = F_21 ( V_48 [ * V_62 ] ) ;
if ( V_63 >= 0 ) {
V_4 = 1 ;
* V_37 = ( * V_37 << 4 ) + V_63 ;
} else {
break;
}
}
}
return V_4 ;
}
static int F_22 ( struct V_29 * V_30 ,
const T_3 * V_48 , T_4 V_61 )
{
int V_64 = 1 ;
int V_62 = 0 ;
while ( V_64 ) {
unsigned int V_65 = 0 ;
unsigned int V_66 = 0 ;
V_64 = V_64 && F_20 ( V_48 , V_61 , & V_62 , & V_65 ) ;
if ( V_64 && V_65 == 0xffff )
return 0 ;
V_64 = V_64 && F_20 ( V_48 , V_61 , & V_62 , & V_66 ) ;
while ( V_64 && V_65 > 0 ) {
unsigned int V_67 = 0 ;
V_64 = V_64 && F_20 ( V_48 , V_61 , & V_62 , & V_67 ) ;
V_65 -- ;
}
}
return - V_68 ;
}
static void F_23 ( struct V_29 * V_30 ,
int V_69 , const T_3 * V_48 , T_4 V_61 )
{
struct V_70 T_1 * V_71 = V_30 -> V_72 ;
T_5 T_1 * V_73 ;
T_5 T_1 * V_74 ;
int V_64 = 1 ;
int V_62 = 0 ;
while ( V_64 ) {
unsigned int V_65 = 0 ;
unsigned int V_66 = 0 ;
V_64 = V_64 && F_20 ( V_48 , V_61 , & V_62 , & V_65 ) ;
if ( V_64 && V_65 == 0xffff )
return;
V_64 = V_64 && F_20 ( V_48 , V_61 , & V_62 , & V_66 ) ;
F_19 ( V_30 -> V_57 , L_3 ,
V_69 , V_65 , V_66 ) ;
while ( V_64 && V_65 > 0 ) {
if ( V_66 & 0x4000 ) {
unsigned int V_75 = 0 ;
V_64 = V_64 &&
F_20 ( V_48 , V_61 , & V_62 , & V_75 ) ;
V_65 -- ;
} else {
unsigned int V_75 = 0 ;
unsigned int V_76 = 0 ;
V_73 = & V_71 [ V_69 ] . V_77 [ V_66 ] ;
V_74 = & V_71 [ V_69 ] . V_78 [ V_66 ] ;
V_64 = V_64 &&
F_20 ( V_48 , V_61 , & V_62 , & V_75 ) ;
V_64 = V_64 &&
F_20 ( V_48 , V_61 , & V_62 , & V_76 ) ;
V_65 -= 2 ;
if ( V_64 ) {
F_5 ( V_73 , V_75 ) ;
F_6 ( 1 ) ;
F_5 ( V_74 , V_76 ) ;
F_6 ( 1 ) ;
}
}
V_66 ++ ;
}
}
}
static int F_24 ( struct V_29 * V_30 ,
const T_3 * V_48 , T_4 V_61 ,
unsigned long V_79 )
{
int V_69 ;
int V_80 ;
V_80 = F_22 ( V_30 , V_48 , V_61 ) ;
if ( V_80 )
return V_80 ;
for ( V_69 = 0 ; V_69 < V_30 -> V_58 ; V_69 ++ )
F_23 ( V_30 , V_69 , V_48 , V_61 ) ;
return 0 ;
}
static struct V_1
F_25 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = V_32 -> V_36 ;
struct V_1 V_4 = F_1 ( 1000 , 2000 ) ;
struct V_5 T_1 * V_6 ;
T_2 V_44 ;
T_2 V_45 ;
int V_50 ;
int V_11 ;
V_6 = V_35 -> V_6 ;
V_50 = F_15 ( & V_6 -> V_50 ) ;
if ( V_50 != V_35 -> V_50 )
V_35 -> V_50 = V_50 ;
if ( V_50 & ( V_51 | V_52 | V_53 ) )
V_35 -> V_38 = V_54 ;
switch ( V_35 -> V_38 ) {
case V_54 :
V_44 = F_15 ( & V_6 -> V_44 ) ;
V_45 = F_15 ( & V_6 -> V_45 ) ;
if ( ( V_50 & ( V_51 | V_52 ) ) ||
V_44 == 0 || V_45 == 0 ) {
} else {
V_35 -> V_81 = 0 ;
V_35 -> V_38 = V_82 ;
}
break;
case V_82 :
V_35 -> V_81 ++ ;
if ( V_35 -> V_81 < 10 ) {
} else {
struct V_8 V_9 ;
V_35 -> V_44 = F_15 ( & V_6 -> V_44 ) ;
V_35 -> V_45 = F_15 ( & V_6 -> V_45 ) ;
for ( V_11 = 0 ; V_11 < F_26 ( V_9 . V_13 ) ; V_11 ++ ) {
V_9 . V_13 [ V_11 ] . V_14 = (enum V_83 ) 0 ;
V_9 . V_13 [ V_11 ] . V_15 = 0 ;
}
F_4 ( V_6 , & V_9 , 0 ) ;
F_8 ( V_6 , 0 ) ;
V_35 -> V_38 = V_84 ;
V_4 = F_1 ( 20 , 100 ) ;
}
break;
case V_84 :
if ( ! F_2 ( V_6 ) ) {
V_4 = F_1 ( 20 , 100 ) ;
} else {
struct V_19 V_27 ;
struct V_19 V_28 ;
V_27 = F_12 ( V_6 ) ;
V_28 = F_13 ( V_6 ) ;
F_11 ( V_6 , V_28 ) ;
V_35 -> V_38 = V_85 ;
V_4 = F_1 ( 20 , 100 ) ;
}
break;
case V_85 :
if ( ! F_2 ( V_6 ) ) {
V_4 = F_1 ( 20 , 100 ) ;
} else {
struct V_86 T_1 * V_87 = & V_6 -> V_20 ;
union V_88 * V_89 = V_35 -> V_90 ;
V_89 [ 0 ] . V_91 . V_90 [ 0 ] . V_2 = - F_3 ( & V_87 -> V_21 ) * 1000 ;
V_89 [ 0 ] . V_91 . V_90 [ 0 ] . V_3 = F_3 ( & V_87 -> V_21 ) * 1000 ;
V_89 [ 1 ] . V_91 . V_90 [ 0 ] . V_2 = - F_3 ( & V_87 -> V_22 ) * 1000 ;
V_89 [ 1 ] . V_91 . V_90 [ 0 ] . V_3 = F_3 ( & V_87 -> V_22 ) * 1000 ;
V_89 [ 2 ] . V_91 . V_90 [ 0 ] . V_2 = - F_3 ( & V_87 -> V_23 ) * 1000 ;
V_89 [ 2 ] . V_91 . V_90 [ 0 ] . V_3 = F_3 ( & V_87 -> V_23 ) * 1000 ;
V_89 [ 3 ] . V_91 . V_90 [ 0 ] . V_2 = - F_3 ( & V_87 -> V_24 ) * 100 ;
V_89 [ 3 ] . V_91 . V_90 [ 0 ] . V_3 = F_3 ( & V_87 -> V_24 ) * 100 ;
V_89 [ 4 ] . V_91 . V_90 [ 0 ] . V_2 = - F_3 ( & V_87 -> V_25 ) * 100 ;
V_89 [ 4 ] . V_91 . V_90 [ 0 ] . V_3 = F_3 ( & V_87 -> V_25 ) * 100 ;
V_89 [ 5 ] . V_91 . V_90 [ 0 ] . V_2 = - F_3 ( & V_87 -> V_26 ) * 100 ;
V_89 [ 5 ] . V_91 . V_90 [ 0 ] . V_3 = F_3 ( & V_87 -> V_26 ) * 100 ;
V_89 [ 6 ] . V_91 . V_90 [ 0 ] . V_2 = - F_3 ( & V_87 -> V_42 ) * 100 ;
V_89 [ 6 ] . V_91 . V_90 [ 0 ] . V_3 = F_3 ( & V_87 -> V_42 ) * 100 ;
V_89 [ 7 ] . V_91 . V_90 [ 0 ] . V_2 = - F_3 ( & V_87 -> V_43 ) * 100 ;
V_89 [ 7 ] . V_91 . V_90 [ 0 ] . V_3 = F_3 ( & V_87 -> V_43 ) * 100 ;
V_89 [ 8 ] . V_91 . V_90 [ 0 ] . V_2 = 0 ;
V_89 [ 8 ] . V_91 . V_90 [ 0 ] . V_3 = 65535 ;
F_9 ( V_6 , 0 ) ;
V_35 -> V_38 = V_92 ;
V_4 = F_1 ( 40 , 100 ) ;
}
break;
case V_92 :
if ( ! F_2 ( V_6 ) ) {
V_4 = F_1 ( 20 , 100 ) ;
} else {
F_7 ( & V_6 -> V_93 . V_21 , 0 ) ;
F_7 ( & V_6 -> V_93 . V_22 , 0 ) ;
F_7 ( & V_6 -> V_93 . V_23 , 0 ) ;
F_7 ( & V_6 -> V_93 . V_24 , 0 ) ;
F_7 ( & V_6 -> V_93 . V_25 , 0 ) ;
F_7 ( & V_6 -> V_93 . V_26 , 0 ) ;
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
struct V_94 * V_95 = V_30 -> V_36 ;
struct V_34 * V_35 ;
struct V_31 * V_32 ;
unsigned long V_96 ;
unsigned long V_97 ;
int V_98 ;
int V_11 ;
F_28 ( & V_30 -> V_99 , V_96 ) ;
V_98 = 1000 ;
V_97 = V_100 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_58 ; V_11 ++ ) {
V_32 = & V_30 -> V_59 [ V_11 ] ;
V_35 = V_32 -> V_36 ;
if ( F_29 ( V_97 , V_35 -> V_101 ) ) {
struct V_1 V_102 ;
V_102 = F_25 ( V_32 ) ;
V_35 -> V_101 = V_100 +
F_30 ( V_102 . V_2 ) ;
if ( V_102 . V_3 && V_102 . V_3 < V_98 )
V_98 = V_102 . V_3 ;
}
}
F_31 ( & V_30 -> V_99 , V_96 ) ;
V_95 -> V_103 . V_104 = V_100 + F_30 ( V_98 ) ;
F_32 ( & V_95 -> V_103 ) ;
}
static struct V_34 *
F_33 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_70 T_1 * V_71 = V_30 -> V_72 ;
struct V_34 * V_35 ;
int V_105 ;
int V_106 ;
V_35 = F_34 ( V_32 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_6 = & V_71 [ V_32 -> V_60 ] . V_6 ;
for ( V_105 = 0 ; V_105 < 8 ; V_105 ++ ) {
V_35 -> V_90 [ V_105 ] . V_91 . V_107 = 1 ;
V_35 -> V_90 [ V_105 ] . V_91 . V_90 [ 0 ] . V_2 = - 1000000 ;
V_35 -> V_90 [ V_105 ] . V_91 . V_90 [ 0 ] . V_3 = 1000000 ;
for ( V_106 = 0 ; V_106 < 7 ; V_106 ++ ) {
V_35 -> V_108 [ V_105 + V_106 * 8 ] = & V_35 -> V_90 [ V_105 ] . V_91 ;
V_35 -> V_109 [ V_105 + V_106 * 8 ] = 0x7fff ;
}
}
V_35 -> V_90 [ 8 ] . V_91 . V_107 = 1 ;
V_35 -> V_90 [ 8 ] . V_91 . V_90 [ 0 ] . V_2 = 0 ;
V_35 -> V_90 [ 8 ] . V_91 . V_90 [ 0 ] . V_3 = 65535 ;
V_35 -> V_108 [ 56 ] = & V_35 -> V_90 [ 8 ] . V_91 ;
V_35 -> V_108 [ 57 ] = & V_35 -> V_90 [ 8 ] . V_91 ;
V_35 -> V_109 [ 56 ] = 0xffff ;
V_35 -> V_109 [ 57 ] = 0xffff ;
return V_35 ;
}
static void F_35 ( struct V_29 * V_30 )
{
struct V_70 T_1 * V_71 = V_30 -> V_72 ;
struct V_5 T_1 * V_110 = & V_71 [ 0 ] . V_6 ;
char V_111 [ F_26 ( V_110 -> V_112 ) + 1 ] ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_26 ( V_110 -> V_112 ) ; V_11 ++ )
V_111 [ V_11 ] = ( char ) ( F_15 ( & V_110 -> V_112 [ V_11 ] ) >> 8 ) ;
V_111 [ V_11 ] = '\0' ;
F_19 ( V_30 -> V_57 , L_4 , V_111 ) ;
}
static int F_36 ( struct V_29 * V_30 ,
unsigned long V_79 )
{
struct V_113 * V_114 = F_37 ( V_30 ) ;
static const struct V_115 * V_116 ;
struct V_94 * V_95 ;
struct V_34 * V_35 ;
struct V_70 T_1 * V_71 ;
struct V_31 * V_32 ;
int V_80 ;
int V_11 ;
F_38 ( sizeof( struct V_70 ) != 0x80000 ) ;
if ( V_79 < F_26 ( V_117 ) )
V_116 = & V_117 [ V_79 ] ;
if ( ! V_116 )
return - V_118 ;
V_30 -> V_119 = V_116 ;
V_30 -> V_120 = V_116 -> V_121 ;
V_95 = F_39 ( V_30 , sizeof( * V_95 ) ) ;
if ( ! V_95 )
return - V_122 ;
V_80 = F_40 ( V_30 ) ;
if ( V_80 )
return V_80 ;
if ( F_41 ( V_114 , 0 ) < V_116 -> V_123 * sizeof( * V_71 ) )
return - V_124 ;
V_30 -> V_72 = F_42 ( V_114 , 0 ) ;
if ( ! V_30 -> V_72 )
return - V_122 ;
V_71 = V_30 -> V_72 ;
V_80 = F_43 ( V_30 , V_116 -> V_123 ) ;
if ( V_80 )
return V_80 ;
V_30 -> V_125 = F_18 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_58 ; V_11 ++ ) {
V_32 = & V_30 -> V_59 [ V_11 ] ;
V_32 -> type = V_126 ;
V_32 -> V_127 = V_128 | V_129 ;
V_32 -> V_130 = 8 * 7 + 2 ;
V_32 -> V_131 = F_16 ;
V_35 = F_33 ( V_30 , V_32 ) ;
if ( ! V_35 )
return - V_122 ;
V_32 -> V_108 = V_35 -> V_108 ;
V_32 -> V_109 = V_35 -> V_109 ;
}
for ( V_11 = 0 ; V_11 < V_30 -> V_58 ; V_11 ++ )
F_44 ( 0 , & V_71 [ V_11 ] . V_132 ) ;
V_80 = F_45 ( V_30 , & F_37 ( V_30 ) -> V_30 ,
L_5 ,
F_24 , 0 ) ;
F_19 ( V_30 -> V_57 , L_6 , V_80 ) ;
if ( V_80 < 0 )
return V_80 ;
F_46 ( 25 ) ;
F_35 ( V_30 ) ;
for ( V_11 = 0 ; V_11 < V_30 -> V_58 ; V_11 ++ ) {
V_32 = & V_30 -> V_59 [ V_11 ] ;
V_35 = V_32 -> V_36 ;
V_35 -> V_101 = V_100 + F_30 ( 500 ) ;
}
F_47 ( & V_95 -> V_103 , F_27 , ( unsigned long ) V_30 ) ;
V_95 -> V_103 . V_104 = V_100 + F_30 ( 1000 ) ;
F_32 ( & V_95 -> V_103 ) ;
return 0 ;
}
static void F_48 ( struct V_29 * V_30 )
{
struct V_94 * V_95 = V_30 -> V_36 ;
if ( V_95 )
F_49 ( & V_95 -> V_103 ) ;
F_50 ( V_30 ) ;
}
static int F_51 ( struct V_113 * V_30 ,
const struct V_133 * V_134 )
{
return F_52 ( V_30 , & V_135 , V_134 -> V_136 ) ;
}
