void F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
V_2 -> V_3 = V_3 + 1 ;
V_2 -> V_4 = V_2 -> V_3 + ( V_3 [ 0 ] >> 16 ) ;
}
int F_2 ( struct V_1 * V_2 , int * V_5 , int * V_6 )
{
* V_5 = * V_2 -> V_3 >> 24 ;
* V_6 = * V_2 -> V_3 & 0xffffff ;
return V_2 -> V_3 ++ < V_2 -> V_4 ;
}
static const T_1 * F_3 ( const T_1 * V_7 , int V_8 )
{
struct V_1 V_2 ;
int V_9 = 0 , V_5 , V_6 ;
F_1 ( & V_2 , V_7 ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
if ( V_9 == V_8 &&
V_5 == ( V_10 | V_11 ) )
return V_2 . V_3 - 1 + V_6 ;
V_9 = V_5 ;
}
return NULL ;
}
static int F_4 ( const T_1 * V_12 , char * V_13 , T_2 V_14 )
{
unsigned int V_15 , V_16 ;
char V_17 ;
if ( ! V_14 || ! V_13 )
return - V_18 ;
V_15 = F_5 ( V_12 [ 0 ] >> 16 , 256U ) ;
if ( V_15 < 2 )
return - V_19 ;
if ( V_12 [ 1 ] != 0 || V_12 [ 2 ] != 0 )
return - V_19 ;
V_12 += 3 ;
V_15 -= 2 ;
for ( V_16 = 0 ; V_16 < V_15 * 4 && V_16 < V_14 - 1 ; V_16 ++ ) {
V_17 = V_12 [ V_16 / 4 ] >> ( 24 - 8 * ( V_16 % 4 ) ) ;
if ( V_17 == '\0' )
break;
V_13 [ V_16 ] = V_17 ;
}
V_13 [ V_16 ] = '\0' ;
return V_16 ;
}
int F_6 ( const T_1 * V_7 , int V_5 , char * V_13 , T_2 V_14 )
{
const T_1 * V_20 = F_3 ( V_7 , V_5 ) ;
if ( ! V_20 )
return - V_21 ;
return F_4 ( V_20 , V_13 , V_14 ) ;
}
static void F_7 ( const T_1 * V_7 , int * V_22 )
{
struct V_1 V_2 ;
int V_5 , V_6 ;
F_1 ( & V_2 , V_7 ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
switch ( V_5 ) {
case V_23 : V_22 [ 0 ] = V_6 ; break;
case V_24 : V_22 [ 1 ] = V_6 ; break;
case V_25 : V_22 [ 2 ] = V_6 ; break;
case V_26 : V_22 [ 3 ] = V_6 ; break;
}
}
}
static void F_8 ( struct V_27 * V_28 , int * V_22 )
{
F_7 ( & F_9 ( V_28 ) -> V_29 [ 5 ] , V_22 ) ;
F_7 ( V_28 -> V_7 , V_22 ) ;
}
static bool F_10 ( const struct V_30 * V_31 , int * V_22 )
{
int V_32 = 0 ;
if ( V_22 [ 0 ] == V_31 -> V_33 )
V_32 |= V_34 ;
if ( V_22 [ 1 ] == V_31 -> V_35 )
V_32 |= V_36 ;
if ( V_22 [ 2 ] == V_31 -> V_37 )
V_32 |= V_38 ;
if ( V_22 [ 3 ] == V_31 -> V_39 )
V_32 |= V_40 ;
return ( V_32 & V_31 -> V_41 ) == V_31 -> V_41 ;
}
static int F_11 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
const struct V_30 * V_31 =
F_12 ( V_45 , struct V_46 , V_47 ) -> V_31 ;
int V_22 [] = { 0 , 0 , 0 , 0 } ;
if ( ! F_13 ( V_43 ) )
return 0 ;
F_8 ( V_27 ( V_43 ) , V_22 ) ;
for (; V_31 -> V_41 != 0 ; V_31 ++ )
if ( F_10 ( V_31 , V_22 ) )
return 1 ;
return 0 ;
}
static int F_14 ( struct V_27 * V_28 , char * V_48 , T_2 V_49 )
{
int V_22 [] = { 0 , 0 , 0 , 0 } ;
F_8 ( V_28 , V_22 ) ;
return snprintf ( V_48 , V_49 ,
L_1 ,
V_22 [ 0 ] , V_22 [ 1 ] , V_22 [ 2 ] , V_22 [ 3 ] ) ;
}
static int F_15 ( struct V_42 * V_43 , struct V_50 * V_51 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
char V_52 [ 64 ] ;
F_14 ( V_28 , V_52 , sizeof( V_52 ) ) ;
if ( F_16 ( V_51 , L_2 , V_52 ) )
return - V_53 ;
return 0 ;
}
int F_17 ( struct V_54 * V_42 )
{
int V_55 = V_42 -> V_55 ;
F_18 () ;
return V_42 -> V_56 -> V_47 -> V_57 ( V_42 -> V_56 ,
V_42 -> V_58 ,
V_55 ) ;
}
static T_3 F_19 ( struct V_42 * V_43 ,
struct V_59 * V_60 , char * V_13 )
{
struct V_61 * V_62 =
F_12 ( V_60 , struct V_61 , V_62 ) ;
struct V_1 V_2 ;
const T_1 * V_63 ;
int V_5 , V_6 , V_64 = - V_21 ;
F_20 ( & V_65 ) ;
if ( F_13 ( V_43 ) )
V_63 = V_27 ( V_43 ) -> V_7 ;
else
V_63 = V_54 ( V_43 ) -> V_29 + 5 ;
F_1 ( & V_2 , V_63 ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) )
if ( V_62 -> V_5 == V_5 ) {
V_64 = snprintf ( V_13 , V_13 ? V_66 : 0 ,
L_3 , V_6 ) ;
break;
}
F_21 ( & V_65 ) ;
return V_64 ;
}
static T_3 F_22 ( struct V_42 * V_43 ,
struct V_59 * V_60 , char * V_13 )
{
struct V_61 * V_62 =
F_12 ( V_60 , struct V_61 , V_62 ) ;
const T_1 * V_63 ;
T_2 V_67 ;
char V_68 [ 2 ] ;
int V_64 ;
F_20 ( & V_65 ) ;
if ( F_13 ( V_43 ) )
V_63 = V_27 ( V_43 ) -> V_7 ;
else
V_63 = V_54 ( V_43 ) -> V_29 + 5 ;
if ( V_13 ) {
V_67 = V_66 - 1 ;
} else {
V_13 = V_68 ;
V_67 = 1 ;
}
V_64 = F_6 ( V_63 , V_62 -> V_5 , V_13 , V_67 ) ;
if ( V_64 >= 0 ) {
while ( V_64 > 0 && isspace ( V_13 [ V_64 - 1 ] ) )
V_64 -- ;
strcpy ( V_13 + V_64 , L_4 ) ;
V_64 ++ ;
}
F_21 ( & V_65 ) ;
return V_64 ;
}
static void F_23 ( struct V_42 * V_43 ,
struct V_59 * V_69 ,
struct V_70 * V_71 )
{
struct V_59 * V_62 ;
int V_16 , V_72 ;
for ( V_72 = 0 ; V_69 [ V_72 ] . V_62 . V_73 != NULL ; V_72 ++ )
V_71 -> V_69 [ V_72 ] = & V_69 [ V_72 ] . V_62 ;
for ( V_16 = 0 ; V_16 < F_24 ( V_74 ) ; V_16 ++ ) {
V_62 = & V_74 [ V_16 ] . V_62 ;
if ( V_62 -> V_75 ( V_43 , V_62 , NULL ) < 0 )
continue;
V_71 -> V_69 [ V_72 ++ ] = & V_62 -> V_62 ;
}
V_71 -> V_69 [ V_72 ] = NULL ;
V_71 -> V_76 [ 0 ] = & V_71 -> V_71 ;
V_71 -> V_76 [ 1 ] = NULL ;
V_71 -> V_71 . V_69 = V_71 -> V_69 ;
V_43 -> V_76 = ( const struct V_77 * * ) V_71 -> V_76 ;
}
static T_3 F_25 ( struct V_42 * V_43 ,
struct V_59 * V_62 , char * V_13 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
int V_78 ;
V_78 = F_14 ( V_28 , V_13 , V_66 ) ;
strcpy ( V_13 + V_78 , L_4 ) ;
return V_78 + 1 ;
}
static T_3 F_26 ( struct V_42 * V_43 ,
struct V_59 * V_62 , char * V_13 )
{
struct V_54 * V_42 = V_54 ( V_43 -> V_79 ) ;
struct V_27 * V_28 = V_27 ( V_43 ) ;
return snprintf ( V_13 , V_66 , L_5 ,
( int ) ( V_28 -> V_7 - V_42 -> V_29 ) ) ;
}
static T_3 F_27 ( struct V_42 * V_43 ,
struct V_59 * V_62 , char * V_13 )
{
struct V_54 * V_42 = V_54 ( V_43 ) ;
T_2 V_78 ;
F_20 ( & V_65 ) ;
V_78 = V_42 -> V_80 * 4 ;
memcpy ( V_13 , V_42 -> V_29 , V_78 ) ;
F_21 ( & V_65 ) ;
return V_78 ;
}
static T_3 F_28 ( struct V_42 * V_43 ,
struct V_59 * V_62 , char * V_13 )
{
struct V_54 * V_42 = V_54 ( V_43 ) ;
int V_64 ;
F_20 ( & V_65 ) ;
V_64 = snprintf ( V_13 , V_66 , L_6 ,
V_42 -> V_29 [ 3 ] , V_42 -> V_29 [ 4 ] ) ;
F_21 ( & V_65 ) ;
return V_64 ;
}
static int F_29 ( char * V_13 , const T_1 * V_7 )
{
struct V_1 V_2 ;
int V_5 , V_6 ;
int V_37 = 0 ;
int V_39 = 0 ;
F_1 ( & V_2 , V_7 ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
switch ( V_5 ) {
case V_25 :
V_37 = V_6 ;
break;
case V_26 :
V_39 = V_6 ;
break;
}
}
return sprintf ( V_13 , L_7 , V_37 , V_39 ) ;
}
static T_3 F_30 ( struct V_42 * V_43 ,
struct V_59 * V_62 , char * V_13 )
{
struct V_54 * V_42 = V_54 ( V_43 ) ;
struct V_1 V_2 ;
int V_5 , V_6 , V_16 = 0 ;
F_20 ( & V_65 ) ;
F_1 ( & V_2 , & V_42 -> V_29 [ 5 ] ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
if ( V_5 != ( V_81 | V_82 ) )
continue;
V_16 += F_29 ( & V_13 [ V_16 ] , V_2 . V_3 + V_6 - 1 ) ;
if ( V_16 >= V_66 - ( 8 + 1 + 8 + 1 ) )
break;
}
F_21 ( & V_65 ) ;
if ( V_16 )
V_13 [ V_16 - 1 ] = '\n' ;
return V_16 ;
}
static int F_31 ( struct V_54 * V_42 ,
int V_55 , int V_83 , T_1 * V_84 )
{
T_4 V_85 = ( V_86 | V_87 ) + V_83 * 4 ;
int V_16 , V_88 ;
F_18 () ;
for ( V_16 = 10 ; V_16 < 100 ; V_16 += 10 ) {
V_88 = F_32 ( V_42 -> V_56 ,
V_89 , V_42 -> V_58 ,
V_55 , V_42 -> V_90 , V_85 , V_84 , 4 ) ;
if ( V_88 != V_91 )
break;
F_33 ( V_16 ) ;
}
F_34 ( V_84 ) ;
return V_88 ;
}
static int F_35 ( struct V_54 * V_42 , int V_55 )
{
struct V_92 * V_56 = V_42 -> V_56 ;
const T_1 * V_93 , * V_94 ;
T_1 * V_95 , * V_96 ;
T_1 V_97 , V_5 ;
int V_16 , V_4 , V_78 , V_64 ;
V_95 = F_36 ( sizeof( * V_95 ) * V_98 +
sizeof( * V_96 ) * V_98 , V_99 ) ;
if ( V_95 == NULL )
return - V_53 ;
V_96 = & V_95 [ V_98 ] ;
memset ( V_95 , 0 , sizeof( * V_95 ) * V_98 ) ;
V_42 -> V_90 = V_100 ;
for ( V_16 = 0 ; V_16 < 5 ; V_16 ++ ) {
V_64 = F_31 ( V_42 , V_55 , V_16 , & V_95 [ V_16 ] ) ;
if ( V_64 != V_101 )
goto V_102;
if ( V_16 == 0 && V_95 [ V_16 ] == 0 ) {
V_64 = V_91 ;
goto V_102;
}
}
V_42 -> V_90 = V_42 -> V_103 -> V_90 ;
if ( ( V_95 [ 2 ] & 0x7 ) < V_42 -> V_90 ||
V_42 -> V_90 == V_104 ||
V_56 -> V_105 ) {
T_1 V_106 ;
if ( V_42 -> V_90 == V_104 )
V_42 -> V_90 = V_56 -> V_107 ;
while ( V_42 -> V_90 > V_100 ) {
if ( F_31 ( V_42 , V_55 , 0 , & V_106 ) ==
V_101 )
break;
V_42 -> V_90 -- ;
}
}
V_78 = V_16 ;
V_97 = 0 ;
V_96 [ V_97 ++ ] = 0xc0000005 ;
while ( V_97 > 0 ) {
V_5 = V_96 [ -- V_97 ] ;
V_16 = V_5 & 0xffffff ;
if ( F_37 ( V_16 >= V_98 ) ) {
V_64 = - V_108 ;
goto V_102;
}
V_64 = F_31 ( V_42 , V_55 , V_16 , & V_95 [ V_16 ] ) ;
if ( V_64 != V_101 )
goto V_102;
V_4 = V_16 + ( V_95 [ V_16 ] >> 16 ) + 1 ;
if ( V_4 > V_98 ) {
F_38 ( V_56 , L_8 ,
V_95 [ V_16 ] ,
V_16 * 4 | V_86 | V_87 ) ;
V_95 [ V_16 ] = 0 ;
V_4 = V_16 ;
}
V_16 ++ ;
for (; V_16 < V_4 ; V_16 ++ ) {
V_64 = F_31 ( V_42 , V_55 , V_16 , & V_95 [ V_16 ] ) ;
if ( V_64 != V_101 )
goto V_102;
if ( ( V_5 >> 30 ) != 3 || ( V_95 [ V_16 ] >> 30 ) < 2 )
continue;
if ( V_16 + ( V_95 [ V_16 ] & 0xffffff ) >= V_98 ) {
F_38 ( V_56 ,
L_9 ,
V_95 [ V_16 ] ,
V_16 * 4 | V_86 | V_87 ) ;
V_95 [ V_16 ] = 0 ;
continue;
}
V_96 [ V_97 ++ ] = V_16 + V_95 [ V_16 ] ;
}
if ( V_78 < V_16 )
V_78 = V_16 ;
}
V_93 = V_42 -> V_29 ;
V_94 = F_39 ( V_95 , V_78 * 4 , V_99 ) ;
if ( V_94 == NULL ) {
V_64 = - V_53 ;
goto V_102;
}
F_40 ( & V_65 ) ;
V_42 -> V_29 = V_94 ;
V_42 -> V_80 = V_78 ;
F_41 ( & V_65 ) ;
F_42 ( V_93 ) ;
V_64 = V_101 ;
V_42 -> V_109 = V_95 [ 2 ] >> 12 & 0xf ;
V_42 -> V_110 = V_95 [ 2 ] >> 30 & 1 ;
V_42 -> V_111 = V_95 [ 2 ] >> 31 & 1 ;
V_102:
F_42 ( V_95 ) ;
return V_64 ;
}
static void F_43 ( struct V_42 * V_43 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
F_44 ( F_9 ( V_28 ) ) ;
F_42 ( V_28 ) ;
}
static bool F_13 ( struct V_42 * V_43 )
{
return V_43 -> type == & V_112 ;
}
static void F_45 ( struct V_54 * V_42 )
{
struct V_1 V_2 ;
struct V_27 * V_28 ;
int V_5 , V_6 , V_16 ;
V_16 = 0 ;
F_1 ( & V_2 , & V_42 -> V_29 [ 5 ] ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
if ( V_5 != ( V_81 | V_82 ) )
continue;
V_28 = F_46 ( sizeof( * V_28 ) , V_99 ) ;
if ( V_28 == NULL ) {
F_38 ( V_42 -> V_56 , L_10 ) ;
continue;
}
V_28 -> V_7 = V_2 . V_3 + V_6 - 1 ;
V_28 -> V_42 . V_113 = & V_114 ;
V_28 -> V_42 . type = & V_112 ;
V_28 -> V_42 . V_79 = & V_42 -> V_42 ;
F_47 ( & V_28 -> V_42 , L_11 , F_48 ( & V_42 -> V_42 ) , V_16 ++ ) ;
F_49 ( F_24 ( V_28 -> V_77 . V_69 ) <
F_24 ( V_115 ) +
F_24 ( V_74 ) ) ;
F_23 ( & V_28 -> V_42 ,
V_115 ,
& V_28 -> V_77 ) ;
if ( F_50 ( & V_28 -> V_42 ) < 0 )
goto V_116;
F_51 ( V_42 ) ;
continue;
V_116:
F_42 ( V_28 ) ;
}
}
static int F_52 ( struct V_42 * V_42 , void * V_84 )
{
F_53 ( V_42 ) ;
return 0 ;
}
struct V_54 * F_54 ( T_5 V_117 )
{
struct V_54 * V_42 ;
F_20 ( & V_65 ) ;
V_42 = F_55 ( & V_118 , F_56 ( V_117 ) ) ;
if ( V_42 )
F_51 ( V_42 ) ;
F_21 ( & V_65 ) ;
return V_42 ;
}
static void F_57 ( struct V_54 * V_42 ,
unsigned long V_119 )
{
F_58 ( V_120 , & V_42 -> V_121 , V_119 ) ;
}
static void F_59 ( struct V_122 * V_121 )
{
struct V_54 * V_42 =
F_12 ( V_121 , struct V_54 , V_121 . V_121 ) ;
int V_123 = F_56 ( V_42 -> V_42 . V_117 ) ;
if ( F_60 ( F_61 () ,
V_42 -> V_56 -> V_124 + V_125 )
&& ! F_62 ( & V_42 -> V_56 -> V_126 ) ) {
F_57 ( V_42 , V_125 ) ;
return;
}
if ( F_63 ( & V_42 -> V_127 ,
V_128 ,
V_129 ) != V_128 )
return;
F_64 ( V_42 ) ;
F_65 ( & V_42 -> V_42 , NULL , F_52 ) ;
F_53 ( & V_42 -> V_42 ) ;
F_40 ( & V_65 ) ;
F_66 ( & V_118 , V_123 ) ;
F_41 ( & V_65 ) ;
F_44 ( V_42 ) ;
}
static void F_67 ( struct V_42 * V_43 )
{
struct V_54 * V_42 = V_54 ( V_43 ) ;
struct V_92 * V_56 = V_42 -> V_56 ;
unsigned long V_130 ;
F_68 ( & V_56 -> V_131 , V_130 ) ;
V_42 -> V_103 -> V_84 = NULL ;
F_69 ( & V_56 -> V_131 , V_130 ) ;
F_70 ( V_42 -> V_103 ) ;
F_42 ( V_42 -> V_29 ) ;
F_42 ( V_42 ) ;
F_71 ( V_56 ) ;
}
static bool F_72 ( struct V_42 * V_43 )
{
return V_43 -> type == & V_132 ;
}
static int F_73 ( struct V_42 * V_43 , void * V_84 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
struct V_46 * V_47 = (struct V_46 * ) V_43 -> V_47 ;
if ( F_13 ( V_43 ) && V_47 != NULL && V_47 -> V_133 != NULL ) {
F_74 ( V_43 ) ;
V_47 -> V_133 ( V_28 ) ;
F_75 ( V_43 ) ;
}
return 0 ;
}
static void F_76 ( struct V_122 * V_121 )
{
struct V_54 * V_42 =
F_12 ( V_121 , struct V_54 , V_121 . V_121 ) ;
F_77 ( V_42 ) ;
F_65 ( & V_42 -> V_42 , NULL , F_73 ) ;
}
static int F_78 ( struct V_42 * V_43 , void * V_84 )
{
struct V_54 * V_134 = V_54 ( V_43 ) ;
struct V_54 * V_135 = V_84 ;
struct V_92 * V_56 = V_135 -> V_56 ;
int V_32 = 0 ;
if ( ! F_72 ( V_43 ) )
return 0 ;
F_20 ( & V_65 ) ;
F_79 ( & V_56 -> V_131 ) ;
if ( memcmp ( V_134 -> V_29 , V_135 -> V_29 , 6 * 4 ) == 0 &&
F_63 ( & V_134 -> V_127 ,
V_128 ,
V_136 ) == V_128 ) {
struct V_137 * V_138 = V_135 -> V_103 ;
struct V_137 * V_139 = V_134 -> V_103 ;
V_135 -> V_103 = V_139 ;
V_135 -> V_103 -> V_84 = V_135 ;
V_134 -> V_103 = V_138 ;
V_134 -> V_103 -> V_84 = V_134 ;
V_134 -> V_90 = V_135 -> V_90 ;
V_134 -> V_58 = V_138 -> V_58 ;
F_80 () ;
V_134 -> V_55 = V_56 -> V_55 ;
V_134 -> V_140 = 0 ;
F_81 ( V_56 , L_12 , F_48 ( V_43 ) ) ;
F_82 ( & V_134 -> V_121 , F_76 ) ;
F_57 ( V_134 , 0 ) ;
if ( V_138 == V_56 -> V_141 )
F_83 ( V_56 , 0 ) ;
V_32 = 1 ;
}
F_84 ( & V_56 -> V_131 ) ;
F_21 ( & V_65 ) ;
return V_32 ;
}
static void F_85 ( struct V_54 * V_42 , int V_55 )
{
struct V_92 * V_56 = V_42 -> V_56 ;
T_6 V_84 ;
int V_88 ;
if ( ! V_56 -> V_142 )
return;
if ( ! V_42 -> V_111 || V_42 -> V_109 < 8 )
return;
if ( V_42 -> V_143 == V_144 ) {
V_88 = F_32 ( V_56 , V_89 ,
V_42 -> V_58 , V_55 , V_42 -> V_90 ,
V_86 + V_145 ,
& V_84 , 4 ) ;
switch ( V_88 ) {
case V_101 :
if ( V_84 & F_86 ( 1 << 31 ) ) {
V_42 -> V_143 = V_146 ;
break;
}
case V_147 :
V_42 -> V_143 = V_148 ;
}
}
if ( V_42 -> V_143 == V_146 ) {
V_84 = F_86 ( V_149 |
V_150 ) ;
F_32 ( V_56 , V_151 ,
V_42 -> V_58 , V_55 , V_42 -> V_90 ,
V_86 + V_145 ,
& V_84 , 4 ) ;
}
}
int F_87 ( struct V_42 * V_43 , void * V_152 )
{
if ( F_72 ( V_43 ) )
F_85 ( V_54 ( V_43 ) , ( long ) V_152 ) ;
return 0 ;
}
static void F_88 ( struct V_122 * V_121 )
{
struct V_54 * V_42 =
F_12 ( V_121 , struct V_54 , V_121 . V_121 ) ;
struct V_92 * V_56 = V_42 -> V_56 ;
struct V_42 * V_153 ;
int V_123 , V_64 ;
V_64 = F_35 ( V_42 , V_42 -> V_55 ) ;
if ( V_64 != V_101 ) {
if ( V_42 -> V_140 < V_154 &&
F_89 ( & V_42 -> V_127 ) == V_155 ) {
V_42 -> V_140 ++ ;
F_57 ( V_42 , V_156 ) ;
} else {
if ( V_42 -> V_103 -> V_157 )
F_81 ( V_56 , L_13 ,
V_42 -> V_58 ,
F_90 ( V_64 ) ) ;
if ( V_42 -> V_103 == V_56 -> V_141 )
F_83 ( V_56 , 0 ) ;
F_67 ( & V_42 -> V_42 ) ;
}
return;
}
V_153 = F_91 ( V_56 -> V_42 ,
V_42 , F_78 ) ;
if ( V_153 ) {
F_92 ( V_153 ) ;
F_67 ( & V_42 -> V_42 ) ;
return;
}
F_93 ( & V_42 -> V_42 ) ;
F_51 ( V_42 ) ;
F_40 ( & V_65 ) ;
V_64 = F_94 ( & V_118 , V_99 ) ?
F_95 ( & V_118 , V_42 , & V_123 ) :
- V_53 ;
F_41 ( & V_65 ) ;
if ( V_64 < 0 )
goto error;
V_42 -> V_42 . V_113 = & V_114 ;
V_42 -> V_42 . type = & V_132 ;
V_42 -> V_42 . V_79 = V_56 -> V_42 ;
V_42 -> V_42 . V_117 = F_96 ( V_158 , V_123 ) ;
F_47 ( & V_42 -> V_42 , L_14 , V_123 ) ;
F_49 ( F_24 ( V_42 -> V_77 . V_69 ) <
F_24 ( V_159 ) +
F_24 ( V_74 ) ) ;
F_23 ( & V_42 -> V_42 ,
V_159 ,
& V_42 -> V_77 ) ;
if ( F_97 ( & V_42 -> V_42 ) ) {
F_38 ( V_56 , L_15 ) ;
goto V_160;
}
F_45 ( V_42 ) ;
if ( F_63 ( & V_42 -> V_127 ,
V_155 ,
V_136 ) == V_128 ) {
F_82 ( & V_42 -> V_121 , F_59 ) ;
F_57 ( V_42 , V_125 ) ;
} else {
F_81 ( V_56 , L_16 ,
F_48 ( & V_42 -> V_42 ) ,
V_42 -> V_29 [ 3 ] , V_42 -> V_29 [ 4 ] ,
1 << V_42 -> V_90 ) ;
V_42 -> V_140 = 0 ;
F_85 ( V_42 , V_42 -> V_55 ) ;
}
if ( V_42 -> V_103 == V_56 -> V_141 )
F_83 ( V_56 , 0 ) ;
return;
V_160:
F_40 ( & V_65 ) ;
F_66 ( & V_118 , V_123 ) ;
F_41 ( & V_65 ) ;
error:
F_44 ( V_42 ) ;
F_92 ( & V_42 -> V_42 ) ;
}
static int F_98 ( struct V_54 * V_42 , int V_55 ,
bool * V_161 )
{
T_1 V_162 ;
int V_16 , V_88 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
V_88 = F_31 ( V_42 , V_55 , V_16 , & V_162 ) ;
if ( V_88 != V_101 )
return V_88 ;
if ( V_16 == 0 && V_162 == 0 )
return V_91 ;
if ( V_162 != V_42 -> V_29 [ V_16 ] ) {
* V_161 = true ;
return V_101 ;
}
}
* V_161 = false ;
return V_101 ;
}
static void F_99 ( struct V_122 * V_121 )
{
struct V_54 * V_42 =
F_12 ( V_121 , struct V_54 , V_121 . V_121 ) ;
struct V_92 * V_56 = V_42 -> V_56 ;
int V_64 , V_58 = V_42 -> V_58 ;
bool V_161 ;
V_64 = F_98 ( V_42 , V_42 -> V_55 , & V_161 ) ;
if ( V_64 != V_101 )
goto V_163;
if ( ! V_161 ) {
if ( F_63 ( & V_42 -> V_127 ,
V_155 ,
V_136 ) == V_128 )
goto V_164;
F_76 ( V_121 ) ;
V_42 -> V_140 = 0 ;
goto V_102;
}
F_65 ( & V_42 -> V_42 , NULL , F_52 ) ;
V_64 = F_35 ( V_42 , V_42 -> V_55 ) ;
if ( V_64 != V_101 )
goto V_163;
F_77 ( V_42 ) ;
F_45 ( V_42 ) ;
F_100 ( & V_42 -> V_42 . V_165 , V_166 ) ;
if ( F_63 ( & V_42 -> V_127 ,
V_155 ,
V_136 ) == V_128 )
goto V_164;
F_81 ( V_56 , L_17 , F_48 ( & V_42 -> V_42 ) ) ;
V_42 -> V_140 = 0 ;
goto V_102;
V_163:
if ( V_42 -> V_140 < V_154 &&
F_89 ( & V_42 -> V_127 ) == V_155 ) {
V_42 -> V_140 ++ ;
F_57 ( V_42 , V_156 ) ;
return;
}
F_81 ( V_56 , L_18 ,
F_48 ( & V_42 -> V_42 ) , F_90 ( V_64 ) ) ;
V_164:
F_101 ( & V_42 -> V_127 , V_128 ) ;
F_82 ( & V_42 -> V_121 , F_59 ) ;
F_57 ( V_42 , V_125 ) ;
V_102:
if ( V_58 == V_56 -> V_141 -> V_58 )
F_83 ( V_56 , 0 ) ;
}
void F_102 ( struct V_92 * V_56 , struct V_137 * V_103 , int V_167 )
{
struct V_54 * V_42 ;
switch ( V_167 ) {
case V_168 :
V_169:
V_42 = F_46 ( sizeof( * V_42 ) , V_170 ) ;
if ( V_42 == NULL )
break;
F_101 ( & V_42 -> V_127 , V_155 ) ;
V_42 -> V_56 = F_103 ( V_56 ) ;
V_42 -> V_103 = F_104 ( V_103 ) ;
V_42 -> V_58 = V_103 -> V_58 ;
V_42 -> V_55 = V_56 -> V_55 ;
V_42 -> V_171 = V_103 == V_56 -> V_172 ;
F_105 ( & V_42 -> V_173 ) ;
F_106 ( & V_42 -> V_174 ) ;
V_103 -> V_84 = V_42 ;
F_107 ( & V_42 -> V_121 , F_88 ) ;
F_57 ( V_42 , V_175 ) ;
break;
case V_176 :
case V_177 :
V_42 = V_103 -> V_84 ;
if ( V_42 == NULL )
goto V_169;
V_42 -> V_58 = V_103 -> V_58 ;
F_80 () ;
V_42 -> V_55 = V_56 -> V_55 ;
if ( F_63 ( & V_42 -> V_127 ,
V_136 ,
V_155 ) == V_136 ) {
F_82 ( & V_42 -> V_121 , F_99 ) ;
F_57 ( V_42 ,
V_42 -> V_171 ? 0 : V_175 ) ;
}
break;
case V_178 :
V_42 = V_103 -> V_84 ;
if ( V_42 == NULL )
break;
V_42 -> V_58 = V_103 -> V_58 ;
F_80 () ;
V_42 -> V_55 = V_56 -> V_55 ;
if ( F_89 ( & V_42 -> V_127 ) == V_136 ) {
F_82 ( & V_42 -> V_121 , F_76 ) ;
F_57 ( V_42 , 0 ) ;
}
break;
case V_179 :
case V_180 :
if ( ! V_103 -> V_84 )
break;
V_42 = V_103 -> V_84 ;
if ( F_108 ( & V_42 -> V_127 ,
V_128 ) == V_136 ) {
F_82 ( & V_42 -> V_121 , F_59 ) ;
F_57 ( V_42 ,
F_62 ( & V_56 -> V_126 ) ? 0 : V_125 ) ;
}
break;
}
}
