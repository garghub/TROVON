static bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_4 ;
if ( ! V_2 -> V_5 )
return false ;
for ( V_4 = 0 ; V_4 < 0xff ; V_4 ++ ) {
if ( ! V_2 -> V_5 [ V_4 ] )
return false ;
if ( V_3 == V_2 -> V_5 [ V_4 ] )
return true ;
}
return false ;
}
int F_2 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_6 )
{
if ( ! V_2 -> V_5 )
return - V_7 ;
if ( ! F_1 ( V_2 , V_3 ) )
return - V_8 ;
return F_3 ( V_2 , V_3 , V_6 , 1 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_9 , T_2 V_10 )
{
int V_11 ;
F_4 ( & V_2 -> V_12 ) ;
V_11 = V_2 -> V_13 ( V_2 , V_3 , V_9 , V_10 ) ;
F_5 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_6 ( void * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , bool V_19 )
{
struct V_20 * V_21 = F_7 ( V_16 , 0 ) ;
struct V_22 * V_23 = V_21 -> V_24 . V_23 ;
struct V_25 V_26 ;
void * V_27 = V_21 -> V_28 ;
int V_11 = 0 ;
if ( V_23 ) {
V_11 = F_8 ( V_23 -> V_29 ,
V_30 ) ;
if ( V_11 )
return V_11 ;
}
switch ( V_16 -> V_31 -> V_31 ) {
case V_32 :
if ( V_19 )
F_9 ( V_14 , V_27 , V_16 , V_18 ) ;
else
F_10 ( V_14 , V_27 , V_16 , V_18 ) ;
break;
case V_33 :
F_11 ( V_14 , V_27 , V_16 , V_18 , V_19 ) ;
break;
default:
F_12 ( V_16 -> V_34 -> V_34 , L_1 ,
F_13 ( V_16 -> V_31 -> V_31 ,
& V_26 ) ) ;
return - V_8 ;
}
if ( V_23 )
V_11 = F_14 ( V_23 -> V_29 ,
V_30 ) ;
return V_11 ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 ,
struct V_17 * V_39 ,
unsigned int V_40 )
{
struct V_20 * V_21 = F_7 ( V_16 , 0 ) ;
struct V_41 * V_42 = V_16 -> V_34 -> V_43 ;
struct V_1 * V_2 = F_16 ( V_42 ) ;
bool V_19 = V_2 -> V_44 ;
struct V_17 V_18 ;
int V_11 = 0 ;
bool V_45 ;
void * V_46 ;
F_4 ( & V_42 -> V_47 ) ;
if ( ! V_2 -> V_48 )
goto V_49;
if ( V_42 -> V_50 . V_51 . V_16 != V_16 )
goto V_49;
V_45 = F_17 ( & V_18 , V_39 , V_40 , V_37 ,
V_16 -> V_52 , V_16 -> V_53 ) ;
F_18 ( L_2 , V_16 -> V_24 . V_54 ,
V_18 . V_55 , V_18 . V_56 , V_18 . y1 , V_18 . V_57 ) ;
if ( ! V_2 -> V_58 || ! V_45 || V_19 ||
V_16 -> V_31 -> V_31 == V_33 ) {
V_46 = V_2 -> V_59 ;
V_11 = F_6 ( V_2 -> V_59 , V_16 , & V_18 , V_19 ) ;
if ( V_11 )
goto V_49;
} else {
V_46 = V_21 -> V_28 ;
}
F_19 ( V_2 , V_60 ,
( V_18 . V_55 >> 8 ) & 0xFF , V_18 . V_55 & 0xFF ,
( V_18 . V_56 >> 8 ) & 0xFF , ( V_18 . V_56 - 1 ) & 0xFF ) ;
F_19 ( V_2 , V_61 ,
( V_18 . y1 >> 8 ) & 0xFF , V_18 . y1 & 0xFF ,
( V_18 . V_57 >> 8 ) & 0xFF , ( V_18 . V_57 - 1 ) & 0xFF ) ;
V_11 = F_3 ( V_2 , V_62 , V_46 ,
( V_18 . V_56 - V_18 . V_55 ) * ( V_18 . V_57 - V_18 . y1 ) * 2 ) ;
V_49:
F_5 ( & V_42 -> V_47 ) ;
if ( V_11 )
F_12 ( V_16 -> V_34 -> V_34 , L_3 ,
V_11 ) ;
return V_11 ;
}
void F_20 ( struct V_63 * V_50 ,
struct V_64 * V_65 )
{
struct V_41 * V_42 = F_21 ( V_50 ) ;
struct V_1 * V_2 = F_16 ( V_42 ) ;
struct V_15 * V_16 = V_50 -> V_51 . V_16 ;
F_22 ( L_4 ) ;
V_2 -> V_48 = true ;
if ( V_16 )
V_16 -> V_66 -> V_67 ( V_16 , NULL , 0 , 0 , NULL , 0 ) ;
F_23 ( V_2 -> V_68 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = V_2 -> V_71 . V_70 ;
T_3 V_53 = V_70 -> V_72 . V_73 ;
T_3 V_52 = V_70 -> V_72 . V_74 ;
T_2 V_10 = V_52 * V_53 * 2 ;
memset ( V_2 -> V_59 , 0 , V_10 ) ;
F_19 ( V_2 , V_60 , 0 , 0 ,
( V_52 >> 8 ) & 0xFF , ( V_52 - 1 ) & 0xFF ) ;
F_19 ( V_2 , V_61 , 0 , 0 ,
( V_53 >> 8 ) & 0xFF , ( V_53 - 1 ) & 0xFF ) ;
F_3 ( V_2 , V_62 ,
( T_1 * ) V_2 -> V_59 , V_10 ) ;
}
void F_25 ( struct V_63 * V_50 )
{
struct V_41 * V_42 = F_21 ( V_50 ) ;
struct V_1 * V_2 = F_16 ( V_42 ) ;
F_22 ( L_4 ) ;
V_2 -> V_48 = false ;
if ( V_2 -> V_68 )
F_26 ( V_2 -> V_68 ) ;
else
F_24 ( V_2 ) ;
}
int F_27 ( struct V_75 * V_34 , struct V_1 * V_2 ,
const struct V_76 * V_77 ,
struct V_78 * V_79 ,
const struct V_80 * V_81 , unsigned int V_82 )
{
T_2 V_83 = V_81 -> V_84 * V_81 -> V_85 * sizeof( T_3 ) ;
struct V_41 * V_42 = & V_2 -> V_71 ;
int V_11 ;
if ( ! V_2 -> V_13 )
return - V_8 ;
F_28 ( & V_2 -> V_12 ) ;
V_2 -> V_59 = F_29 ( V_34 , V_83 , V_86 ) ;
if ( ! V_2 -> V_59 )
return - V_87 ;
V_11 = F_30 ( V_34 , V_42 , & V_88 , V_79 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_31 ( V_42 , V_77 ,
V_89 ,
V_90 ,
F_32 ( V_90 ) , V_81 ,
V_82 ) ;
if ( V_11 )
return V_11 ;
V_42 -> V_70 -> V_72 . V_91 = 16 ;
V_2 -> V_82 = V_82 ;
F_33 ( V_42 -> V_70 ) ;
F_22 ( L_5 ,
V_42 -> V_70 -> V_72 . V_91 , V_82 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_92 )
return;
F_35 ( V_2 -> V_92 , 0 ) ;
F_36 ( 20 ) ;
F_35 ( V_2 -> V_92 , 1 ) ;
F_36 ( 120 ) ;
}
bool F_37 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_2 ( V_2 , V_93 , & V_6 ) )
return false ;
V_6 &= ~ V_94 ;
if ( V_6 != ( V_95 |
V_96 | V_97 ) )
return false ;
F_38 ( L_6 ) ;
return true ;
}
static T_4 F_39 ( struct V_98 * V_99 , T_2 V_10 )
{
if ( V_10 > 64 )
return 0 ;
return F_40 ( T_4 , 10000000 , V_99 -> V_100 ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_58 ,
const void * V_101 , T_2 V_10 ,
unsigned int V_102 )
{
bool V_44 = ( V_102 == 16 && F_42 () ) ;
T_2 V_103 , V_104 = V_2 -> V_105 ;
struct V_98 * V_99 = V_2 -> V_99 ;
struct V_106 V_46 = {
. V_59 = V_2 -> V_107 ,
. V_108 = 8 ,
} ;
struct V_109 V_110 ;
const T_1 * V_27 = V_101 ;
int V_4 , V_11 ;
T_1 * V_14 ;
if ( V_111 & V_112 )
F_43 ( L_7 ,
V_113 , V_58 , V_104 ) ;
V_46 . V_114 = F_39 ( V_99 , V_10 ) ;
F_44 ( & V_110 , & V_46 , 1 ) ;
if ( ! V_58 ) {
if ( F_45 ( V_10 != 1 ) )
return - V_8 ;
V_14 = V_2 -> V_107 ;
memset ( V_14 , 0 , 9 ) ;
V_14 [ 8 ] = * V_27 ;
V_46 . V_10 = 9 ;
F_46 ( V_99 , & V_110 ) ;
return F_47 ( V_99 , & V_110 ) ;
}
V_104 = V_104 / 9 * 8 ;
V_104 = F_48 ( V_104 , V_10 ) ;
V_104 = F_49 ( T_2 , 8 , V_104 & ~ 0x7 ) ;
while ( V_10 ) {
T_2 V_115 = 0 ;
V_103 = F_48 ( V_10 , V_104 ) ;
V_10 -= V_103 ;
V_14 = V_2 -> V_107 ;
if ( V_103 < 8 ) {
T_1 V_6 , V_116 = 0 ;
memset ( V_14 , 0 , 9 ) ;
if ( V_44 ) {
for ( V_4 = 1 ; V_4 < ( V_103 + 1 ) ; V_4 ++ ) {
V_6 = V_27 [ 1 ] ;
* V_14 ++ = V_116 | F_50 ( 8 - V_4 ) | ( V_6 >> V_4 ) ;
V_116 = V_6 << ( 8 - V_4 ) ;
V_4 ++ ;
V_6 = V_27 [ 0 ] ;
* V_14 ++ = V_116 | F_50 ( 8 - V_4 ) | ( V_6 >> V_4 ) ;
V_116 = V_6 << ( 8 - V_4 ) ;
V_27 += 2 ;
}
* V_14 ++ = V_116 ;
} else {
for ( V_4 = 1 ; V_4 < ( V_103 + 1 ) ; V_4 ++ ) {
V_6 = * V_27 ++ ;
* V_14 ++ = V_116 | F_50 ( 8 - V_4 ) | ( V_6 >> V_4 ) ;
V_116 = V_6 << ( 8 - V_4 ) ;
}
* V_14 ++ = V_116 ;
}
V_103 = 8 ;
V_115 = 1 ;
} else {
for ( V_4 = 0 ; V_4 < V_103 ; V_4 += 8 ) {
if ( V_44 ) {
* V_14 ++ = F_50 ( 7 ) | ( V_27 [ 1 ] >> 1 ) ;
* V_14 ++ = ( V_27 [ 1 ] << 7 ) | F_50 ( 6 ) | ( V_27 [ 0 ] >> 2 ) ;
* V_14 ++ = ( V_27 [ 0 ] << 6 ) | F_50 ( 5 ) | ( V_27 [ 3 ] >> 3 ) ;
* V_14 ++ = ( V_27 [ 3 ] << 5 ) | F_50 ( 4 ) | ( V_27 [ 2 ] >> 4 ) ;
* V_14 ++ = ( V_27 [ 2 ] << 4 ) | F_50 ( 3 ) | ( V_27 [ 5 ] >> 5 ) ;
* V_14 ++ = ( V_27 [ 5 ] << 3 ) | F_50 ( 2 ) | ( V_27 [ 4 ] >> 6 ) ;
* V_14 ++ = ( V_27 [ 4 ] << 2 ) | F_50 ( 1 ) | ( V_27 [ 7 ] >> 7 ) ;
* V_14 ++ = ( V_27 [ 7 ] << 1 ) | F_50 ( 0 ) ;
* V_14 ++ = V_27 [ 6 ] ;
} else {
* V_14 ++ = F_50 ( 7 ) | ( V_27 [ 0 ] >> 1 ) ;
* V_14 ++ = ( V_27 [ 0 ] << 7 ) | F_50 ( 6 ) | ( V_27 [ 1 ] >> 2 ) ;
* V_14 ++ = ( V_27 [ 1 ] << 6 ) | F_50 ( 5 ) | ( V_27 [ 2 ] >> 3 ) ;
* V_14 ++ = ( V_27 [ 2 ] << 5 ) | F_50 ( 4 ) | ( V_27 [ 3 ] >> 4 ) ;
* V_14 ++ = ( V_27 [ 3 ] << 4 ) | F_50 ( 3 ) | ( V_27 [ 4 ] >> 5 ) ;
* V_14 ++ = ( V_27 [ 4 ] << 3 ) | F_50 ( 2 ) | ( V_27 [ 5 ] >> 6 ) ;
* V_14 ++ = ( V_27 [ 5 ] << 2 ) | F_50 ( 1 ) | ( V_27 [ 6 ] >> 7 ) ;
* V_14 ++ = ( V_27 [ 6 ] << 1 ) | F_50 ( 0 ) ;
* V_14 ++ = V_27 [ 7 ] ;
}
V_27 += 8 ;
V_115 ++ ;
}
}
V_46 . V_10 = V_103 + V_115 ;
F_46 ( V_99 , & V_110 ) ;
V_11 = F_47 ( V_99 , & V_110 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , int V_58 ,
const void * V_101 , T_2 V_10 ,
unsigned int V_102 )
{
struct V_98 * V_99 = V_2 -> V_99 ;
struct V_106 V_46 = {
. V_108 = 9 ,
} ;
const T_3 * V_117 = V_101 ;
const T_1 * V_118 = V_101 ;
struct V_109 V_110 ;
T_2 V_104 ;
T_3 * V_119 ;
int V_11 ;
if ( ! F_52 ( V_99 , 9 ) )
return F_41 ( V_2 , V_58 , V_101 , V_10 , V_102 ) ;
V_46 . V_114 = F_39 ( V_99 , V_10 ) ;
V_104 = V_2 -> V_105 ;
V_119 = V_2 -> V_107 ;
if ( V_111 & V_112 )
F_43 ( L_7 ,
V_113 , V_58 , V_104 ) ;
V_104 = F_48 ( V_104 / 2 , V_10 ) ;
F_44 ( & V_110 , & V_46 , 1 ) ;
V_46 . V_59 = V_119 ;
while ( V_10 ) {
T_2 V_103 = F_48 ( V_10 , V_104 ) ;
unsigned int V_4 ;
if ( V_102 == 16 && F_42 () ) {
for ( V_4 = 0 ; V_4 < ( V_103 * 2 ) ; V_4 += 2 ) {
V_119 [ V_4 ] = * V_117 >> 8 ;
V_119 [ V_4 + 1 ] = * V_117 ++ & 0xFF ;
if ( V_58 ) {
V_119 [ V_4 ] |= 0x0100 ;
V_119 [ V_4 + 1 ] |= 0x0100 ;
}
}
} else {
for ( V_4 = 0 ; V_4 < V_103 ; V_4 ++ ) {
V_119 [ V_4 ] = * V_118 ++ ;
if ( V_58 )
V_119 [ V_4 ] |= 0x0100 ;
}
}
V_46 . V_10 = V_103 ;
V_10 -= V_103 ;
F_46 ( V_99 , & V_110 ) ;
V_11 = F_47 ( V_99 , & V_110 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_120 , T_2 V_121 )
{
unsigned int V_102 = ( V_3 == V_62 ) ? 16 : 8 ;
int V_11 ;
if ( F_1 ( V_2 , V_3 ) )
return - V_122 ;
F_54 ( V_3 , V_120 , V_121 ) ;
V_11 = F_51 ( V_2 , 0 , & V_3 , 1 , 8 ) ;
if ( V_11 || ! V_121 )
return V_11 ;
return F_51 ( V_2 , 1 , V_120 , V_121 , V_102 ) ;
}
static int F_55 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_9 , T_2 V_10 )
{
struct V_98 * V_99 = V_2 -> V_99 ;
T_4 V_114 = F_40 ( T_4 , V_123 ,
V_99 -> V_100 / 2 ) ;
struct V_106 V_46 [ 2 ] = {
{
. V_114 = V_114 ,
. V_59 = & V_3 ,
. V_10 = 1 ,
} , {
. V_114 = V_114 ,
. V_10 = V_10 ,
} ,
} ;
struct V_109 V_110 ;
T_1 * V_101 ;
int V_11 ;
if ( ! V_10 )
return - V_8 ;
if ( V_3 == V_124 ||
V_3 == V_125 ) {
if ( ! ( V_10 == 3 || V_10 == 4 ) )
return - V_8 ;
V_46 [ 1 ] . V_10 = V_10 + 1 ;
}
V_101 = F_56 ( V_46 [ 1 ] . V_10 , V_86 ) ;
if ( ! V_101 )
return - V_87 ;
V_46 [ 1 ] . V_126 = V_101 ;
F_35 ( V_2 -> V_58 , 0 ) ;
F_44 ( & V_110 , V_46 , F_32 ( V_46 ) ) ;
V_11 = F_47 ( V_99 , & V_110 ) ;
if ( V_11 )
goto V_127;
F_46 ( V_99 , & V_110 ) ;
if ( V_46 [ 1 ] . V_10 == V_10 ) {
memcpy ( V_9 , V_101 , V_10 ) ;
} else {
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ )
V_9 [ V_4 ] = ( V_101 [ V_4 ] << 1 ) | ! ! ( V_101 [ V_4 + 1 ] & F_50 ( 7 ) ) ;
}
F_54 ( V_3 , V_9 , V_10 ) ;
V_127:
F_57 ( V_101 ) ;
return V_11 ;
}
static int F_58 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_128 , T_2 V_121 )
{
struct V_98 * V_99 = V_2 -> V_99 ;
unsigned int V_102 = 8 ;
T_4 V_114 ;
int V_11 ;
if ( F_1 ( V_2 , V_3 ) )
return F_55 ( V_2 , V_3 , V_128 , V_121 ) ;
F_54 ( V_3 , V_128 , V_121 ) ;
F_35 ( V_2 -> V_58 , 0 ) ;
V_114 = F_39 ( V_99 , 1 ) ;
V_11 = F_59 ( V_99 , V_114 , NULL , 8 , & V_3 , 1 ) ;
if ( V_11 || ! V_121 )
return V_11 ;
if ( V_3 == V_62 && ! V_2 -> V_44 )
V_102 = 16 ;
F_35 ( V_2 -> V_58 , 1 ) ;
V_114 = F_39 ( V_99 , V_121 ) ;
return F_59 ( V_99 , V_114 , NULL , V_102 , V_128 , V_121 ) ;
}
int F_60 ( struct V_98 * V_99 , struct V_1 * V_2 ,
struct V_129 * V_58 ,
const struct V_76 * V_77 ,
struct V_78 * V_79 ,
const struct V_80 * V_81 ,
unsigned int V_82 )
{
T_2 V_130 = F_61 ( V_99 , 0 ) ;
struct V_75 * V_34 = & V_99 -> V_34 ;
int V_11 ;
if ( V_130 < 16 ) {
F_62 ( L_8 , V_130 ) ;
return - V_8 ;
}
if ( ! V_34 -> V_131 ) {
V_11 = F_63 ( V_34 , F_64 ( 32 ) ) ;
if ( V_11 ) {
F_65 ( V_34 , L_9 , V_11 ) ;
return V_11 ;
}
}
V_2 -> V_99 = V_99 ;
V_2 -> V_5 = V_132 ;
if ( V_58 ) {
V_2 -> V_13 = F_58 ;
V_2 -> V_58 = V_58 ;
if ( F_42 () &&
! F_52 ( V_99 , 16 ) )
V_2 -> V_44 = true ;
} else {
V_2 -> V_13 = F_53 ;
V_2 -> V_105 = V_130 ;
V_2 -> V_107 = F_29 ( V_34 , V_130 , V_86 ) ;
if ( ! V_2 -> V_107 )
return - V_87 ;
}
return F_27 ( V_34 , V_2 , V_77 , V_79 , V_81 , V_82 ) ;
}
static T_5 F_66 ( struct V_133 * V_133 ,
const char T_6 * V_134 ,
T_2 V_135 , T_7 * V_136 )
{
struct V_137 * V_110 = V_133 -> V_138 ;
struct V_1 * V_2 = V_110 -> V_139 ;
T_1 V_6 , V_3 = 0 , V_120 [ 64 ] ;
char * V_101 , * V_140 , * V_141 ;
unsigned int V_4 ;
int V_11 ;
V_101 = F_67 ( V_134 , V_135 ) ;
if ( F_68 ( V_101 ) )
return F_69 ( V_101 ) ;
for ( V_4 = V_135 - 1 ; V_4 > 0 ; V_4 -- )
if ( isspace ( V_101 [ V_4 ] ) )
V_101 [ V_4 ] = '\0' ;
else
break;
V_4 = 0 ;
V_140 = V_101 ;
while ( V_140 ) {
V_141 = F_70 ( & V_140 , L_10 ) ;
if ( ! V_141 ) {
V_11 = - V_8 ;
goto V_127;
}
V_11 = F_71 ( V_141 , 16 , & V_6 ) ;
if ( V_11 < 0 )
goto V_127;
if ( V_141 == V_101 )
V_3 = V_6 ;
else
V_120 [ V_4 ++ ] = V_6 ;
if ( V_4 == 64 ) {
V_11 = - V_142 ;
goto V_127;
}
}
V_11 = F_3 ( V_2 , V_3 , V_120 , V_4 ) ;
V_127:
F_57 ( V_101 ) ;
return V_11 < 0 ? V_11 : V_135 ;
}
static int F_72 ( struct V_137 * V_110 , void * V_143 )
{
struct V_1 * V_2 = V_110 -> V_139 ;
T_1 V_3 , V_6 [ 4 ] ;
T_2 V_10 ;
int V_11 ;
for ( V_3 = 0 ; V_3 < 255 ; V_3 ++ ) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
switch ( V_3 ) {
case V_144 :
case V_145 :
V_10 = 2 ;
break;
case V_124 :
V_10 = 3 ;
break;
case V_125 :
V_10 = 4 ;
break;
default:
V_10 = 1 ;
break;
}
F_73 ( V_110 , L_11 , V_3 ) ;
V_11 = F_3 ( V_2 , V_3 , V_6 , V_10 ) ;
if ( V_11 ) {
F_74 ( V_110 , L_12 ) ;
continue;
}
F_73 ( V_110 , L_13 , ( int ) V_10 , V_6 ) ;
}
return 0 ;
}
static int F_75 ( struct V_146 * V_146 ,
struct V_133 * V_133 )
{
return F_76 ( V_133 , F_72 ,
V_146 -> V_147 ) ;
}
int F_77 ( struct V_148 * V_149 )
{
struct V_41 * V_42 = V_149 -> V_34 -> V_43 ;
struct V_1 * V_2 = F_16 ( V_42 ) ;
T_8 V_81 = V_150 | V_151 ;
if ( V_2 -> V_5 )
V_81 |= V_152 ;
F_78 ( L_14 , V_81 , V_149 -> V_153 , V_2 ,
& V_154 ) ;
return F_79 ( V_155 ,
F_32 ( V_155 ) ,
V_149 -> V_153 , V_149 ) ;
}
