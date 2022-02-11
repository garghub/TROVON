static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 = NULL ;
F_2 ( & V_4 ) ;
F_3 (map, &rc_map_list, list) {
if ( ! strcmp ( V_2 , V_3 -> V_3 . V_2 ) ) {
F_4 ( & V_4 ) ;
return V_3 ;
}
}
F_4 ( & V_4 ) ;
return NULL ;
}
struct V_5 * F_5 ( const char * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( V_2 ) ;
#ifdef F_6
if ( ! V_3 ) {
int V_6 = F_7 ( L_1 , V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( L_2 , V_2 ) ;
return NULL ;
}
F_9 ( 20 ) ;
V_3 = F_1 ( V_2 ) ;
}
#endif
if ( ! V_3 ) {
F_8 ( L_3 , V_2 ) ;
return NULL ;
}
F_10 ( V_7 L_4 , V_3 -> V_3 . V_2 ) ;
return & V_3 -> V_3 ;
}
int F_11 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
F_12 ( & V_3 -> V_8 , & V_1 ) ;
F_4 ( & V_4 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
F_14 ( & V_3 -> V_8 ) ;
F_4 ( & V_4 ) ;
}
static int F_15 ( struct V_5 * V_5 ,
const char * V_2 , T_1 V_9 , T_2 V_10 )
{
V_5 -> V_2 = F_16 ( V_2 , V_11 ) ;
if ( ! V_5 -> V_2 )
return - V_12 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_13 = F_17 ( V_10 * sizeof( struct V_14 ) ) ;
V_5 -> V_10 = V_5 -> V_13 / sizeof( struct V_14 ) ;
V_5 -> V_15 = F_18 ( V_5 -> V_13 , V_11 ) ;
if ( ! V_5 -> V_15 ) {
F_19 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
return - V_12 ;
}
F_20 ( 1 , L_5 ,
V_5 -> V_10 , V_5 -> V_13 ) ;
return 0 ;
}
static void F_21 ( struct V_5 * V_5 )
{
V_5 -> V_10 = 0 ;
F_19 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
F_19 ( V_5 -> V_15 ) ;
V_5 -> V_15 = NULL ;
}
static int F_22 ( struct V_5 * V_5 , T_3 V_16 )
{
unsigned int V_17 = V_5 -> V_13 ;
unsigned int V_18 = V_17 ;
struct V_14 * V_19 = V_5 -> V_15 ;
struct V_14 * V_20 ;
if ( V_5 -> V_10 == V_5 -> V_21 ) {
if ( V_5 -> V_13 >= V_22 )
return - V_12 ;
V_18 *= 2 ;
F_20 ( 1 , L_6 , V_18 ) ;
}
if ( ( V_5 -> V_21 * 3 < V_5 -> V_10 ) && ( V_17 > V_23 ) ) {
V_18 /= 2 ;
F_20 ( 1 , L_7 , V_18 ) ;
}
if ( V_18 == V_17 )
return 0 ;
V_20 = F_18 ( V_18 , V_16 ) ;
if ( ! V_20 ) {
F_20 ( 1 , L_8 , V_18 ) ;
return - V_12 ;
}
memcpy ( V_20 , V_5 -> V_15 , V_5 -> V_21 * sizeof( struct V_14 ) ) ;
V_5 -> V_15 = V_20 ;
V_5 -> V_13 = V_18 ;
V_5 -> V_10 = V_5 -> V_13 / sizeof( struct V_14 ) ;
F_19 ( V_19 ) ;
return 0 ;
}
static unsigned int F_23 ( struct V_24 * V_25 ,
struct V_5 * V_5 ,
unsigned int V_26 ,
unsigned int V_27 )
{
int V_28 = V_5 -> V_15 [ V_26 ] . V_29 ;
int V_30 ;
if ( V_27 == V_31 || V_27 == V_32 ) {
F_20 ( 1 , L_9 ,
V_26 , V_5 -> V_15 [ V_26 ] . V_33 ) ;
V_5 -> V_21 -- ;
memmove ( & V_5 -> V_15 [ V_26 ] , & V_5 -> V_15 [ V_26 + 1 ] ,
( V_5 -> V_21 - V_26 ) * sizeof( struct V_14 ) ) ;
} else {
F_20 ( 1 , L_10 ,
V_26 ,
V_28 == V_31 ? L_11 : L_12 ,
V_5 -> V_15 [ V_26 ] . V_33 , V_27 ) ;
V_5 -> V_15 [ V_26 ] . V_29 = V_27 ;
F_24 ( V_27 , V_25 -> V_34 -> V_35 ) ;
}
if ( V_28 != V_31 ) {
F_25 ( V_28 , V_25 -> V_34 -> V_35 ) ;
for ( V_30 = 0 ; V_30 < V_5 -> V_21 ; V_30 ++ ) {
if ( V_5 -> V_15 [ V_30 ] . V_29 == V_28 ) {
F_24 ( V_28 , V_25 -> V_34 -> V_35 ) ;
break;
}
}
F_22 ( V_5 , V_36 ) ;
}
return V_28 ;
}
static unsigned int F_26 ( struct V_24 * V_25 ,
struct V_5 * V_5 ,
unsigned int V_33 ,
bool V_37 )
{
unsigned int V_30 ;
if ( V_25 -> V_38 )
V_33 &= V_25 -> V_38 ;
for ( V_30 = 0 ; V_30 < V_5 -> V_21 ; V_30 ++ ) {
if ( V_5 -> V_15 [ V_30 ] . V_33 == V_33 )
return V_30 ;
if ( V_5 -> V_15 [ V_30 ] . V_33 >= V_33 )
break;
}
if ( V_5 -> V_10 == V_5 -> V_21 ) {
if ( ! V_37 || F_22 ( V_5 , V_36 ) )
return - 1U ;
}
if ( V_30 < V_5 -> V_21 )
memmove ( & V_5 -> V_15 [ V_30 + 1 ] , & V_5 -> V_15 [ V_30 ] ,
( V_5 -> V_21 - V_30 ) * sizeof( struct V_14 ) ) ;
V_5 -> V_15 [ V_30 ] . V_33 = V_33 ;
V_5 -> V_15 [ V_30 ] . V_29 = V_31 ;
V_5 -> V_21 ++ ;
return V_30 ;
}
static int F_27 ( struct V_34 * V_39 ,
const struct V_40 * V_41 ,
unsigned int * V_28 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
struct V_5 * V_5 = & V_42 -> V_5 ;
unsigned int V_26 ;
unsigned int V_33 ;
int V_43 = 0 ;
unsigned long V_44 ;
F_29 ( & V_5 -> V_45 , V_44 ) ;
if ( V_41 -> V_44 & V_46 ) {
V_26 = V_41 -> V_26 ;
if ( V_26 >= V_5 -> V_21 ) {
V_43 = - V_47 ;
goto V_48;
}
} else {
V_43 = F_30 ( V_41 , & V_33 ) ;
if ( V_43 )
goto V_48;
V_26 = F_26 ( V_42 , V_5 , V_33 , true ) ;
if ( V_26 >= V_5 -> V_21 ) {
V_43 = - V_12 ;
goto V_48;
}
}
* V_28 = F_23 ( V_42 , V_5 , V_26 , V_41 -> V_29 ) ;
V_48:
F_31 ( & V_5 -> V_45 , V_44 ) ;
return V_43 ;
}
static int F_32 ( struct V_24 * V_25 ,
const struct V_5 * V_49 )
{
struct V_5 * V_5 = & V_25 -> V_5 ;
unsigned int V_30 , V_26 ;
int V_6 ;
V_6 = F_15 ( V_5 , V_49 -> V_2 ,
V_49 -> V_9 , V_49 -> V_10 ) ;
if ( V_6 )
return V_6 ;
F_20 ( 1 , L_5 ,
V_5 -> V_10 , V_5 -> V_13 ) ;
for ( V_30 = 0 ; V_30 < V_49 -> V_10 ; V_30 ++ ) {
V_26 = F_26 ( V_25 , V_5 ,
V_49 -> V_15 [ V_30 ] . V_33 , false ) ;
if ( V_26 >= V_5 -> V_21 ) {
V_6 = - V_12 ;
break;
}
F_23 ( V_25 , V_5 , V_26 ,
V_49 -> V_15 [ V_30 ] . V_29 ) ;
}
if ( V_6 )
F_21 ( V_5 ) ;
return V_6 ;
}
static unsigned int F_33 ( const struct V_5 * V_5 ,
unsigned int V_33 )
{
int V_50 = 0 ;
int V_51 = V_5 -> V_21 - 1 ;
int V_52 ;
while ( V_50 <= V_51 ) {
V_52 = ( V_50 + V_51 ) / 2 ;
if ( V_5 -> V_15 [ V_52 ] . V_33 < V_33 )
V_50 = V_52 + 1 ;
else if ( V_5 -> V_15 [ V_52 ] . V_33 > V_33 )
V_51 = V_52 - 1 ;
else
return V_52 ;
}
return - 1U ;
}
static int F_34 ( struct V_34 * V_39 ,
struct V_40 * V_41 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
struct V_5 * V_5 = & V_42 -> V_5 ;
struct V_14 * V_53 ;
unsigned long V_44 ;
unsigned int V_26 ;
unsigned int V_33 ;
int V_43 ;
F_29 ( & V_5 -> V_45 , V_44 ) ;
if ( V_41 -> V_44 & V_46 ) {
V_26 = V_41 -> V_26 ;
} else {
V_43 = F_30 ( V_41 , & V_33 ) ;
if ( V_43 )
goto V_48;
V_26 = F_33 ( V_5 , V_33 ) ;
}
if ( V_26 < V_5 -> V_21 ) {
V_53 = & V_5 -> V_15 [ V_26 ] ;
V_41 -> V_26 = V_26 ;
V_41 -> V_29 = V_53 -> V_29 ;
V_41 -> V_21 = sizeof( V_53 -> V_33 ) ;
memcpy ( V_41 -> V_33 , & V_53 -> V_33 , sizeof( V_53 -> V_33 ) ) ;
} else if ( ! ( V_41 -> V_44 & V_46 ) ) {
V_41 -> V_26 = V_26 ;
V_41 -> V_29 = V_31 ;
} else {
V_43 = - V_47 ;
goto V_48;
}
V_43 = 0 ;
V_48:
F_31 ( & V_5 -> V_45 , V_44 ) ;
return V_43 ;
}
T_4 F_35 ( struct V_24 * V_25 , T_4 V_33 )
{
struct V_5 * V_5 = & V_25 -> V_5 ;
unsigned int V_29 ;
unsigned int V_26 ;
unsigned long V_44 ;
F_29 ( & V_5 -> V_45 , V_44 ) ;
V_26 = F_33 ( V_5 , V_33 ) ;
V_29 = V_26 < V_5 -> V_21 ?
V_5 -> V_15 [ V_26 ] . V_29 : V_31 ;
F_31 ( & V_5 -> V_45 , V_44 ) ;
if ( V_29 != V_31 )
F_20 ( 1 , L_13 ,
V_25 -> V_54 , V_33 , V_29 ) ;
return V_29 ;
}
static void F_36 ( struct V_24 * V_25 , bool V_55 )
{
if ( ! V_25 -> V_56 )
return;
F_20 ( 1 , L_14 , V_25 -> V_57 ) ;
F_37 ( V_25 -> V_34 , V_25 -> V_57 , 0 ) ;
F_38 ( V_58 , V_59 ) ;
if ( V_55 )
F_39 ( V_25 -> V_34 ) ;
V_25 -> V_56 = false ;
}
void F_40 ( struct V_24 * V_25 )
{
unsigned long V_44 ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_36 ( V_25 , true ) ;
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
static void F_41 ( unsigned long V_61 )
{
struct V_24 * V_25 = (struct V_24 * ) V_61 ;
unsigned long V_44 ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
if ( F_42 ( V_25 -> V_62 ) )
F_36 ( V_25 , true ) ;
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
void F_43 ( struct V_24 * V_25 )
{
unsigned long V_44 ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_44 ( V_25 -> V_34 , V_63 , V_64 , V_25 -> V_65 ) ;
F_39 ( V_25 -> V_34 ) ;
if ( ! V_25 -> V_56 )
goto V_48;
V_25 -> V_62 = V_66 + F_45 ( V_67 ) ;
F_46 ( & V_25 -> V_68 , V_25 -> V_62 ) ;
V_48:
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
static void F_47 ( struct V_24 * V_25 , enum V_9 V_69 ,
T_4 V_33 , T_4 V_29 , T_5 V_70 )
{
bool V_71 = ( ! V_25 -> V_56 ||
V_25 -> V_72 != V_69 ||
V_25 -> V_65 != V_33 ||
V_25 -> V_73 != V_70 ) ;
if ( V_71 && V_25 -> V_56 )
F_36 ( V_25 , false ) ;
F_44 ( V_25 -> V_34 , V_63 , V_64 , V_33 ) ;
if ( V_71 && V_29 != V_31 ) {
V_25 -> V_56 = true ;
V_25 -> V_72 = V_69 ;
V_25 -> V_65 = V_33 ;
V_25 -> V_73 = V_70 ;
V_25 -> V_57 = V_29 ;
F_20 ( 1 , L_15 ,
V_25 -> V_54 , V_29 , V_69 , V_33 ) ;
F_37 ( V_25 -> V_34 , V_29 , 1 ) ;
F_38 ( V_58 , V_74 ) ;
}
F_39 ( V_25 -> V_34 ) ;
}
void F_48 ( struct V_24 * V_25 , enum V_9 V_69 , T_4 V_33 , T_5 V_70 )
{
unsigned long V_44 ;
T_4 V_29 = F_35 ( V_25 , V_33 ) ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_47 ( V_25 , V_69 , V_33 , V_29 , V_70 ) ;
if ( V_25 -> V_56 ) {
V_25 -> V_62 = V_66 + F_45 ( V_67 ) ;
F_46 ( & V_25 -> V_68 , V_25 -> V_62 ) ;
}
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
void F_49 ( struct V_24 * V_25 , enum V_9 V_69 ,
T_4 V_33 , T_5 V_70 )
{
unsigned long V_44 ;
T_4 V_29 = F_35 ( V_25 , V_33 ) ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_47 ( V_25 , V_69 , V_33 , V_29 , V_70 ) ;
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
static int F_50 ( struct V_24 * V_25 ,
struct V_75 * V_76 )
{
static T_4 V_77 [] = {
[ V_78 ] = 0x1f7f ,
[ V_79 ] = 0x1f7f3f ,
[ V_80 ] = 0x2fff ,
[ V_81 ] = 0x1f007f ,
[ V_82 ] = 0xff007f ,
[ V_83 ] = 0x1fff7f ,
[ V_84 ] = 0xffff ,
[ V_85 ] = 0xffff ,
[ V_86 ] = 0xffffff ,
[ V_87 ] = 0xffffffff ,
[ V_88 ] = 0x1fffff ,
[ V_89 ] = 0xffff ,
[ V_90 ] = 0x1fffff ,
[ V_91 ] = 0xffff ,
[ V_92 ] = 0xfffff ,
[ V_93 ] = 0xffffff ,
[ V_94 ] = 0xffffffff ,
[ V_95 ] = 0xffff7fff ,
[ V_96 ] = 0x1fff ,
} ;
T_4 V_97 = V_76 -> V_98 ;
enum V_9 V_69 = V_25 -> V_99 ;
switch ( V_69 ) {
case V_86 :
if ( ( ( ( V_97 >> 16 ) ^ ~ ( V_97 >> 8 ) ) & 0xff ) == 0 )
return - V_47 ;
break;
case V_87 :
if ( ( ( ( V_97 >> 24 ) ^ ~ ( V_97 >> 16 ) ) & 0xff ) == 0 )
return - V_47 ;
break;
case V_95 :
if ( ( V_97 & 0xffff0000 ) != 0x800f0000 )
return - V_47 ;
break;
case V_94 :
if ( ( V_97 & 0xffff0000 ) == 0x800f0000 )
return - V_47 ;
break;
default:
break;
}
V_76 -> V_98 &= V_77 [ V_69 ] ;
V_76 -> V_100 &= V_77 [ V_69 ] ;
if ( V_25 -> V_101 &&
V_76 -> V_100 != 0 && V_76 -> V_100 != V_77 [ V_69 ] )
return - V_47 ;
return 0 ;
}
int F_51 ( struct V_24 * V_42 )
{
int V_102 = 0 ;
if ( ! V_42 )
return - V_47 ;
F_52 ( & V_42 -> V_45 ) ;
if ( ! V_42 -> V_103 ++ && V_42 -> V_104 != NULL )
V_102 = V_42 -> V_104 ( V_42 ) ;
if ( V_102 )
V_42 -> V_103 -- ;
F_53 ( & V_42 -> V_45 ) ;
return V_102 ;
}
static int F_54 ( struct V_34 * V_39 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
return F_51 ( V_42 ) ;
}
void F_55 ( struct V_24 * V_42 )
{
if ( V_42 ) {
F_52 ( & V_42 -> V_45 ) ;
if ( ! -- V_42 -> V_103 && V_42 -> V_105 != NULL )
V_42 -> V_105 ( V_42 ) ;
F_53 ( & V_42 -> V_45 ) ;
}
}
static void F_56 ( struct V_34 * V_39 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
F_55 ( V_42 ) ;
}
static char * F_57 ( struct V_106 * V_25 , T_6 * V_107 )
{
return F_58 ( V_11 , L_16 , F_59 ( V_25 ) ) ;
}
static bool F_60 ( void )
{
#if F_61 ( V_108 )
struct V_109 * V_110 ;
F_52 ( & V_111 ) ;
V_110 = F_62 ( L_17 ) ;
F_53 ( & V_111 ) ;
return V_110 ? true : false ;
#elif F_61 ( V_112 )
return true ;
#else
return false ;
#endif
}
static T_7 F_63 ( struct V_106 * V_106 ,
struct V_113 * V_114 , char * V_115 )
{
struct V_24 * V_25 = F_64 ( V_106 ) ;
T_1 V_116 , V_117 ;
char * V_118 = V_115 ;
int V_30 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_119 ) )
return - V_120 ;
F_52 ( & V_25 -> V_45 ) ;
V_117 = V_25 -> V_121 ;
V_116 = V_25 -> V_122 ;
if ( V_25 -> V_123 && ! V_116 )
V_116 = F_66 () ;
F_53 ( & V_25 -> V_45 ) ;
F_20 ( 1 , L_18 ,
V_124 , ( long long ) V_116 , ( long long ) V_117 ) ;
for ( V_30 = 0 ; V_30 < F_67 ( V_125 ) ; V_30 ++ ) {
if ( V_116 & V_117 & V_125 [ V_30 ] . type )
V_118 += sprintf ( V_118 , L_19 , V_125 [ V_30 ] . V_2 ) ;
else if ( V_116 & V_125 [ V_30 ] . type )
V_118 += sprintf ( V_118 , L_20 , V_125 [ V_30 ] . V_2 ) ;
if ( V_116 & V_125 [ V_30 ] . type )
V_116 &= ~ V_125 [ V_30 ] . type ;
}
if ( V_25 -> V_126 == V_127 && F_60 () )
V_118 += sprintf ( V_118 , L_21 ) ;
if ( V_118 != V_115 )
V_118 -- ;
* V_118 = '\n' ;
return V_118 + 1 - V_115 ;
}
static int F_68 ( T_1 * V_128 , const char * V_115 )
{
const char * V_118 ;
unsigned V_129 = 0 ;
bool V_130 , V_131 ;
T_1 V_100 ;
int V_30 ;
while ( ( V_118 = F_69 ( ( char * * ) & V_115 , L_22 ) ) != NULL ) {
if ( ! * V_118 )
break;
if ( * V_118 == '+' ) {
V_130 = true ;
V_131 = false ;
V_118 ++ ;
} else if ( * V_118 == '-' ) {
V_130 = false ;
V_131 = true ;
V_118 ++ ;
} else {
V_130 = false ;
V_131 = false ;
}
for ( V_30 = 0 ; V_30 < F_67 ( V_125 ) ; V_30 ++ ) {
if ( ! strcasecmp ( V_118 , V_125 [ V_30 ] . V_2 ) ) {
V_100 = V_125 [ V_30 ] . type ;
break;
}
}
if ( V_30 == F_67 ( V_125 ) ) {
if ( ! strcasecmp ( V_118 , L_23 ) )
V_100 = 0 ;
else {
F_20 ( 1 , L_24 , V_118 ) ;
return - V_47 ;
}
}
V_129 ++ ;
if ( V_130 )
* V_128 |= V_100 ;
else if ( V_131 )
* V_128 &= ~ V_100 ;
else
* V_128 = V_100 ;
}
if ( ! V_129 ) {
F_20 ( 1 , L_25 ) ;
return - V_47 ;
}
return V_129 ;
}
static void F_70 ( T_1 * V_128 )
{
T_1 V_132 ;
int V_30 , V_133 ;
for ( V_30 = 0 ; V_30 < F_67 ( V_125 ) ; V_30 ++ ) {
if ( V_125 [ V_30 ] . type == V_134 ||
V_125 [ V_30 ] . type & ( V_135 | V_136 ) )
continue;
V_132 = F_66 () ;
if ( ! ( * V_128 & V_125 [ V_30 ] . type & ~ V_132 ) )
continue;
if ( ! V_125 [ V_30 ] . V_137 ) {
F_8 ( L_26 ,
V_125 [ V_30 ] . V_2 ) ;
* V_128 &= ~ V_125 [ V_30 ] . type ;
continue;
}
V_133 = F_7 ( L_1 , V_125 [ V_30 ] . V_137 ) ;
if ( V_133 < 0 ) {
F_8 ( L_27 ,
V_125 [ V_30 ] . V_137 ) ;
* V_128 &= ~ V_125 [ V_30 ] . type ;
continue;
}
F_9 ( 20 ) ;
V_132 = F_66 () ;
if ( ! ( * V_128 & V_125 [ V_30 ] . type & ~ V_132 ) )
continue;
F_8 ( L_28 ,
V_125 [ V_30 ] . V_137 ,
V_125 [ V_30 ] . V_2 ) ;
* V_128 &= ~ V_125 [ V_30 ] . type ;
}
}
static T_7 F_71 ( struct V_106 * V_106 ,
struct V_113 * V_114 ,
const char * V_115 , T_2 V_21 )
{
struct V_24 * V_25 = F_64 ( V_106 ) ;
T_1 * V_138 ;
struct V_75 * V_76 ;
T_1 V_139 , V_140 ;
T_7 V_6 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_119 ) )
return - V_120 ;
F_20 ( 1 , L_29 ) ;
V_138 = & V_25 -> V_121 ;
V_76 = & V_25 -> V_141 ;
if ( ! V_25 -> V_142 ) {
F_20 ( 1 , L_30 ) ;
return - V_47 ;
}
F_52 ( & V_25 -> V_45 ) ;
V_139 = * V_138 ;
V_140 = V_139 ;
V_6 = F_68 ( & V_140 , V_115 ) ;
if ( V_6 < 0 )
goto V_48;
V_6 = V_25 -> V_142 ( V_25 , & V_140 ) ;
if ( V_6 < 0 ) {
F_20 ( 1 , L_31 ,
( long long ) V_140 ) ;
goto V_48;
}
if ( V_25 -> V_126 == V_127 )
F_70 ( & V_140 ) ;
if ( V_140 != V_139 ) {
* V_138 = V_140 ;
F_20 ( 1 , L_32 ,
( long long ) V_140 ) ;
}
if ( V_25 -> V_143 && V_76 -> V_100 ) {
if ( V_140 )
V_6 = V_25 -> V_143 ( V_25 , V_76 ) ;
else
V_6 = - 1 ;
if ( V_6 < 0 ) {
V_76 -> V_98 = 0 ;
V_76 -> V_100 = 0 ;
V_25 -> V_143 ( V_25 , V_76 ) ;
}
}
V_6 = V_21 ;
V_48:
F_53 ( & V_25 -> V_45 ) ;
return V_6 ;
}
static T_7 F_72 ( struct V_106 * V_106 ,
struct V_113 * V_144 ,
char * V_115 )
{
struct V_24 * V_25 = F_64 ( V_106 ) ;
struct V_145 * V_146 = F_73 ( V_144 ) ;
struct V_75 * V_76 ;
T_4 V_147 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_119 ) )
return - V_120 ;
F_52 ( & V_25 -> V_45 ) ;
if ( V_146 -> type == V_148 )
V_76 = & V_25 -> V_141 ;
else
V_76 = & V_25 -> V_149 ;
if ( V_146 -> V_100 )
V_147 = V_76 -> V_100 ;
else
V_147 = V_76 -> V_98 ;
F_53 ( & V_25 -> V_45 ) ;
return sprintf ( V_115 , L_33 , V_147 ) ;
}
static T_7 F_74 ( struct V_106 * V_106 ,
struct V_113 * V_144 ,
const char * V_115 , T_2 V_21 )
{
struct V_24 * V_25 = F_64 ( V_106 ) ;
struct V_145 * V_146 = F_73 ( V_144 ) ;
struct V_75 V_150 , * V_76 ;
int V_133 ;
unsigned long V_147 ;
int (* F_75)( struct V_24 * V_25 , struct V_75 * V_76 );
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_119 ) )
return - V_120 ;
V_133 = F_76 ( V_115 , 0 , & V_147 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_146 -> type == V_148 ) {
F_75 = V_25 -> V_143 ;
V_76 = & V_25 -> V_141 ;
} else {
F_75 = V_25 -> V_151 ;
V_76 = & V_25 -> V_149 ;
}
if ( ! F_75 )
return - V_47 ;
F_52 ( & V_25 -> V_45 ) ;
V_150 = * V_76 ;
if ( V_146 -> V_100 )
V_150 . V_100 = V_147 ;
else
V_150 . V_98 = V_147 ;
if ( V_146 -> type == V_152 ) {
if ( V_25 -> V_99 != V_153 )
V_133 = F_50 ( V_25 , & V_150 ) ;
else
V_133 = - V_47 ;
if ( V_133 != 0 )
goto V_154;
}
if ( V_146 -> type == V_148 && ! V_25 -> V_121 &&
V_147 ) {
V_133 = - V_47 ;
goto V_154;
}
V_133 = F_75 ( V_25 , & V_150 ) ;
if ( V_133 < 0 )
goto V_154;
* V_76 = V_150 ;
V_154:
F_53 ( & V_25 -> V_45 ) ;
return ( V_133 < 0 ) ? V_133 : V_21 ;
}
static T_7 F_77 ( struct V_106 * V_106 ,
struct V_113 * V_114 ,
char * V_115 )
{
struct V_24 * V_25 = F_64 ( V_106 ) ;
T_1 V_116 ;
enum V_9 V_117 ;
char * V_118 = V_115 ;
int V_30 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_119 ) )
return - V_120 ;
F_52 ( & V_25 -> V_45 ) ;
V_116 = V_25 -> V_155 ;
V_117 = V_25 -> V_99 ;
F_53 ( & V_25 -> V_45 ) ;
F_20 ( 1 , L_34 ,
V_124 , ( long long ) V_116 , V_117 ) ;
for ( V_30 = 0 ; V_30 < F_67 ( V_156 ) ; V_30 ++ ) {
if ( V_116 & ( 1ULL << V_30 ) ) {
if ( V_30 == V_117 )
V_118 += sprintf ( V_118 , L_19 ,
V_156 [ V_30 ] ) ;
else
V_118 += sprintf ( V_118 , L_20 ,
V_156 [ V_30 ] ) ;
}
}
if ( V_118 != V_115 )
V_118 -- ;
* V_118 = '\n' ;
return V_118 + 1 - V_115 ;
}
static T_7 F_78 ( struct V_106 * V_106 ,
struct V_113 * V_114 ,
const char * V_115 , T_2 V_21 )
{
struct V_24 * V_25 = F_64 ( V_106 ) ;
enum V_9 V_69 ;
T_7 V_6 ;
T_1 V_116 ;
int V_30 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_119 ) )
return - V_120 ;
F_52 ( & V_25 -> V_45 ) ;
V_116 = V_25 -> V_155 ;
if ( F_79 ( V_115 , L_35 ) ) {
V_69 = V_153 ;
} else {
for ( V_30 = 0 ; V_30 < F_67 ( V_156 ) ; V_30 ++ ) {
if ( ( V_116 & ( 1ULL << V_30 ) ) &&
F_79 ( V_115 , V_156 [ V_30 ] ) ) {
V_69 = V_30 ;
break;
}
}
if ( V_30 == F_67 ( V_156 ) ) {
V_6 = - V_47 ;
goto V_48;
}
if ( V_25 -> V_101 ) {
T_1 V_100 = 1ULL << V_69 ;
F_70 ( & V_100 ) ;
if ( ! V_100 ) {
V_6 = - V_47 ;
goto V_48;
}
}
}
if ( V_25 -> V_99 != V_69 ) {
V_25 -> V_99 = V_69 ;
F_20 ( 1 , L_36 , V_69 ) ;
if ( V_69 == V_95 )
V_25 -> V_149 . V_98 = 0x800f0000 ;
else
V_25 -> V_149 . V_98 = 0 ;
V_25 -> V_149 . V_100 = 0 ;
V_6 = V_25 -> V_151 ( V_25 , & V_25 -> V_149 ) ;
if ( V_6 == 0 )
V_6 = V_21 ;
} else {
V_6 = V_21 ;
}
V_48:
F_53 ( & V_25 -> V_45 ) ;
return V_6 ;
}
static void F_80 ( struct V_106 * V_106 )
{
struct V_24 * V_25 = F_64 ( V_106 ) ;
F_19 ( V_25 ) ;
}
static int F_81 ( struct V_106 * V_106 , struct V_157 * V_158 )
{
struct V_24 * V_25 = F_64 ( V_106 ) ;
if ( V_25 -> V_5 . V_2 )
F_82 ( L_37 , V_25 -> V_5 . V_2 ) ;
if ( V_25 -> V_159 )
F_82 ( L_38 , V_25 -> V_159 ) ;
return 0 ;
}
struct V_24 * F_83 ( enum V_160 type )
{
struct V_24 * V_25 ;
V_25 = F_84 ( sizeof( * V_25 ) , V_11 ) ;
if ( ! V_25 )
return NULL ;
if ( type != V_161 ) {
V_25 -> V_34 = F_85 () ;
if ( ! V_25 -> V_34 ) {
F_19 ( V_25 ) ;
return NULL ;
}
V_25 -> V_34 -> V_162 = F_34 ;
V_25 -> V_34 -> V_163 = F_27 ;
F_86 ( V_25 -> V_34 , V_25 ) ;
F_87 ( & V_25 -> V_68 , F_41 ,
( unsigned long ) V_25 ) ;
F_88 ( & V_25 -> V_5 . V_45 ) ;
F_88 ( & V_25 -> V_60 ) ;
}
F_89 ( & V_25 -> V_45 ) ;
V_25 -> V_25 . type = & V_164 ;
V_25 -> V_25 . V_165 = & V_166 ;
F_90 ( & V_25 -> V_25 ) ;
V_25 -> V_126 = type ;
F_91 ( V_167 ) ;
return V_25 ;
}
void F_92 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_93 ( V_25 -> V_34 ) ;
F_94 ( & V_25 -> V_25 ) ;
F_95 ( V_167 ) ;
}
static void F_96 ( struct V_106 * V_25 , void * V_168 )
{
F_92 ( * (struct V_24 * * ) V_168 ) ;
}
struct V_24 * F_97 ( struct V_106 * V_25 ,
enum V_160 type )
{
struct V_24 * * V_169 , * V_6 ;
V_169 = F_98 ( F_96 , sizeof( * V_169 ) , V_11 ) ;
if ( ! V_169 )
return NULL ;
V_6 = F_83 ( type ) ;
if ( ! V_6 ) {
F_99 ( V_169 ) ;
return NULL ;
}
V_6 -> V_25 . V_170 = V_25 ;
V_6 -> V_171 = true ;
* V_169 = V_6 ;
F_100 ( V_25 , V_169 ) ;
return V_6 ;
}
static int F_101 ( struct V_24 * V_25 )
{
int V_6 ;
struct V_5 * V_5 ;
T_1 V_9 ;
if ( ! V_25 -> V_172 )
return - V_47 ;
V_5 = F_5 ( V_25 -> V_172 ) ;
if ( ! V_5 )
V_5 = F_5 ( V_173 ) ;
if ( ! V_5 || ! V_5 -> V_15 || V_5 -> V_10 == 0 )
return - V_47 ;
V_6 = F_32 ( V_25 , V_5 ) ;
if ( V_6 )
return V_6 ;
V_9 = F_102 ( V_5 -> V_9 ) ;
if ( V_25 -> V_142 ) {
V_6 = V_25 -> V_142 ( V_25 , & V_9 ) ;
if ( V_6 < 0 )
goto V_174;
V_25 -> V_121 = V_9 ;
}
if ( V_25 -> V_126 == V_127 )
F_70 ( & V_9 ) ;
F_103 ( V_175 , V_25 -> V_34 -> V_176 ) ;
F_103 ( V_177 , V_25 -> V_34 -> V_176 ) ;
F_103 ( V_63 , V_25 -> V_34 -> V_176 ) ;
F_103 ( V_64 , V_25 -> V_34 -> V_178 ) ;
if ( V_25 -> V_104 )
V_25 -> V_34 -> V_104 = F_54 ;
if ( V_25 -> V_105 )
V_25 -> V_34 -> V_105 = F_56 ;
V_25 -> V_34 -> V_179 [ V_180 ] = 500 ;
V_25 -> V_34 -> V_179 [ V_181 ] = 125 ;
V_25 -> V_34 -> V_25 . V_170 = & V_25 -> V_25 ;
memcpy ( & V_25 -> V_34 -> V_182 , & V_25 -> V_183 , sizeof( V_25 -> V_183 ) ) ;
V_25 -> V_34 -> V_184 = V_25 -> V_185 ;
V_25 -> V_34 -> V_2 = V_25 -> V_54 ;
V_6 = F_104 ( V_25 -> V_34 ) ;
if ( V_6 )
goto V_174;
return 0 ;
V_174:
F_21 ( & V_25 -> V_5 ) ;
return V_6 ;
}
static void F_105 ( struct V_24 * V_25 )
{
if ( ! V_25 || V_25 -> V_126 == V_161 )
return;
F_21 ( & V_25 -> V_5 ) ;
F_106 ( V_25 -> V_34 ) ;
V_25 -> V_34 = NULL ;
}
int F_107 ( struct V_24 * V_25 )
{
static bool V_186 ;
const char * V_187 ;
int V_144 = 0 ;
int V_188 ;
int V_6 ;
if ( ! V_25 )
return - V_47 ;
V_188 = F_108 ( & V_189 , 0 , V_190 , V_11 ) ;
if ( V_188 < 0 )
return V_188 ;
V_25 -> V_188 = V_188 ;
F_109 ( & V_25 -> V_25 , L_39 , V_25 -> V_188 ) ;
F_110 ( & V_25 -> V_25 , V_25 ) ;
F_111 ( & V_25 -> V_119 , 0 ) ;
V_25 -> V_25 . V_191 = V_25 -> V_192 ;
if ( V_25 -> V_126 != V_161 )
V_25 -> V_192 [ V_144 ++ ] = & V_193 ;
if ( V_25 -> V_143 )
V_25 -> V_192 [ V_144 ++ ] = & V_194 ;
if ( V_25 -> V_151 )
V_25 -> V_192 [ V_144 ++ ] = & V_195 ;
V_25 -> V_192 [ V_144 ++ ] = NULL ;
V_6 = F_112 ( & V_25 -> V_25 ) ;
if ( V_6 )
goto V_196;
V_187 = F_113 ( & V_25 -> V_25 . V_197 , V_11 ) ;
F_114 ( & V_25 -> V_25 , L_40 ,
V_25 -> V_54 ? : L_41 , V_187 ? : L_42 ) ;
F_19 ( V_187 ) ;
if ( V_25 -> V_126 == V_127 ||
V_25 -> V_126 == V_161 ) {
if ( ! V_186 ) {
F_115 ( L_43 ) ;
V_186 = true ;
}
V_6 = F_116 ( V_25 ) ;
if ( V_6 < 0 )
goto V_198;
}
if ( V_25 -> V_126 != V_161 ) {
V_6 = F_101 ( V_25 ) ;
if ( V_6 )
goto V_199;
}
F_111 ( & V_25 -> V_119 , 1 ) ;
F_20 ( 1 , L_44 ,
V_25 -> V_188 ,
V_25 -> V_159 ? V_25 -> V_159 : L_45 ) ;
return 0 ;
V_199:
F_117 ( V_25 ) ;
V_198:
F_118 ( & V_25 -> V_25 ) ;
V_196:
F_119 ( & V_189 , V_188 ) ;
return V_6 ;
}
static void F_120 ( struct V_106 * V_25 , void * V_168 )
{
F_121 ( * (struct V_24 * * ) V_168 ) ;
}
int F_122 ( struct V_106 * V_170 , struct V_24 * V_25 )
{
struct V_24 * * V_169 ;
int V_133 ;
V_169 = F_98 ( F_120 , sizeof( * V_169 ) , V_11 ) ;
if ( ! V_169 )
return - V_12 ;
V_133 = F_107 ( V_25 ) ;
if ( V_133 ) {
F_99 ( V_169 ) ;
return V_133 ;
}
* V_169 = V_25 ;
F_100 ( V_170 , V_169 ) ;
return 0 ;
}
void F_121 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_123 ( & V_25 -> V_68 ) ;
if ( V_25 -> V_126 == V_127 )
F_117 ( V_25 ) ;
F_105 ( V_25 ) ;
F_118 ( & V_25 -> V_25 ) ;
F_119 ( & V_189 , V_25 -> V_188 ) ;
if ( ! V_25 -> V_171 )
F_92 ( V_25 ) ;
}
static int T_8 F_124 ( void )
{
int V_6 = F_125 ( & V_166 ) ;
if ( V_6 ) {
F_8 ( L_46 ) ;
return V_6 ;
}
F_126 ( L_47 , & V_58 ) ;
F_11 ( & V_200 ) ;
return 0 ;
}
static void T_9 F_127 ( void )
{
F_128 ( & V_166 ) ;
F_129 ( V_58 ) ;
F_13 ( & V_200 ) ;
}
