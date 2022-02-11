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
static T_3 F_29 ( struct V_42 * V_43 ,
struct V_59 * V_62 , char * V_13 )
{
struct V_54 * V_42 = V_54 ( V_43 ) ;
return sprintf ( V_13 , L_7 , V_42 -> V_81 ) ;
}
static int F_30 ( char * V_13 , const T_1 * V_7 )
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
return sprintf ( V_13 , L_8 , V_37 , V_39 ) ;
}
static T_3 F_31 ( struct V_42 * V_43 ,
struct V_59 * V_62 , char * V_13 )
{
struct V_54 * V_42 = V_54 ( V_43 ) ;
struct V_1 V_2 ;
int V_5 , V_6 , V_16 = 0 ;
F_20 ( & V_65 ) ;
F_1 ( & V_2 , & V_42 -> V_29 [ 5 ] ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
if ( V_5 != ( V_82 | V_83 ) )
continue;
V_16 += F_30 ( & V_13 [ V_16 ] , V_2 . V_3 + V_6 - 1 ) ;
if ( V_16 >= V_66 - ( 8 + 1 + 8 + 1 ) )
break;
}
F_21 ( & V_65 ) ;
if ( V_16 )
V_13 [ V_16 - 1 ] = '\n' ;
return V_16 ;
}
static int F_32 ( struct V_54 * V_42 ,
int V_55 , int V_84 , T_1 * V_85 )
{
T_4 V_86 = ( V_87 | V_88 ) + V_84 * 4 ;
int V_16 , V_89 ;
F_18 () ;
for ( V_16 = 10 ; V_16 < 100 ; V_16 += 10 ) {
V_89 = F_33 ( V_42 -> V_56 ,
V_90 , V_42 -> V_58 ,
V_55 , V_42 -> V_91 , V_86 , V_85 , 4 ) ;
if ( V_89 != V_92 )
break;
F_34 ( V_16 ) ;
}
F_35 ( V_85 ) ;
return V_89 ;
}
static int F_36 ( struct V_54 * V_42 , int V_55 )
{
struct V_93 * V_56 = V_42 -> V_56 ;
const T_1 * V_94 , * V_95 ;
T_1 * V_96 , * V_97 ;
T_1 V_98 , V_5 ;
int V_16 , V_4 , V_78 , V_64 ;
V_96 = F_37 ( sizeof( * V_96 ) * V_99 +
sizeof( * V_97 ) * V_99 , V_100 ) ;
if ( V_96 == NULL )
return - V_53 ;
V_97 = & V_96 [ V_99 ] ;
memset ( V_96 , 0 , sizeof( * V_96 ) * V_99 ) ;
V_42 -> V_91 = V_101 ;
for ( V_16 = 0 ; V_16 < 5 ; V_16 ++ ) {
V_64 = F_32 ( V_42 , V_55 , V_16 , & V_96 [ V_16 ] ) ;
if ( V_64 != V_102 )
goto V_103;
if ( V_16 == 0 && V_96 [ V_16 ] == 0 ) {
V_64 = V_92 ;
goto V_103;
}
}
V_42 -> V_91 = V_42 -> V_104 -> V_91 ;
if ( ( V_96 [ 2 ] & 0x7 ) < V_42 -> V_91 ||
V_42 -> V_91 == V_105 ||
V_56 -> V_106 ) {
T_1 V_107 ;
if ( V_42 -> V_91 == V_105 )
V_42 -> V_91 = V_56 -> V_108 ;
while ( V_42 -> V_91 > V_101 ) {
if ( F_32 ( V_42 , V_55 , 0 , & V_107 ) ==
V_102 )
break;
V_42 -> V_91 -- ;
}
}
V_78 = V_16 ;
V_98 = 0 ;
V_97 [ V_98 ++ ] = 0xc0000005 ;
while ( V_98 > 0 ) {
V_5 = V_97 [ -- V_98 ] ;
V_16 = V_5 & 0xffffff ;
if ( F_38 ( V_16 >= V_99 ) ) {
V_64 = - V_109 ;
goto V_103;
}
V_64 = F_32 ( V_42 , V_55 , V_16 , & V_96 [ V_16 ] ) ;
if ( V_64 != V_102 )
goto V_103;
V_4 = V_16 + ( V_96 [ V_16 ] >> 16 ) + 1 ;
if ( V_4 > V_99 ) {
F_39 ( V_56 , L_9 ,
V_96 [ V_16 ] ,
V_16 * 4 | V_87 | V_88 ) ;
V_96 [ V_16 ] = 0 ;
V_4 = V_16 ;
}
V_16 ++ ;
for (; V_16 < V_4 ; V_16 ++ ) {
V_64 = F_32 ( V_42 , V_55 , V_16 , & V_96 [ V_16 ] ) ;
if ( V_64 != V_102 )
goto V_103;
if ( ( V_5 >> 30 ) != 3 || ( V_96 [ V_16 ] >> 30 ) < 2 )
continue;
if ( V_16 + ( V_96 [ V_16 ] & 0xffffff ) >= V_99 ) {
F_39 ( V_56 ,
L_10 ,
V_96 [ V_16 ] ,
V_16 * 4 | V_87 | V_88 ) ;
V_96 [ V_16 ] = 0 ;
continue;
}
V_97 [ V_98 ++ ] = V_16 + V_96 [ V_16 ] ;
}
if ( V_78 < V_16 )
V_78 = V_16 ;
}
V_94 = V_42 -> V_29 ;
V_95 = F_40 ( V_96 , V_78 * 4 , V_100 ) ;
if ( V_95 == NULL ) {
V_64 = - V_53 ;
goto V_103;
}
F_41 ( & V_65 ) ;
V_42 -> V_29 = V_95 ;
V_42 -> V_80 = V_78 ;
F_42 ( & V_65 ) ;
F_43 ( V_94 ) ;
V_64 = V_102 ;
V_42 -> V_110 = V_96 [ 2 ] >> 12 & 0xf ;
V_42 -> V_111 = V_96 [ 2 ] >> 30 & 1 ;
V_42 -> V_112 = V_96 [ 2 ] >> 31 & 1 ;
V_103:
F_43 ( V_96 ) ;
return V_64 ;
}
static void F_44 ( struct V_42 * V_43 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
F_45 ( F_9 ( V_28 ) ) ;
F_43 ( V_28 ) ;
}
static bool F_13 ( struct V_42 * V_43 )
{
return V_43 -> type == & V_113 ;
}
static void F_46 ( struct V_54 * V_42 )
{
struct V_1 V_2 ;
struct V_27 * V_28 ;
int V_5 , V_6 , V_16 ;
V_16 = 0 ;
F_1 ( & V_2 , & V_42 -> V_29 [ 5 ] ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
if ( V_5 != ( V_82 | V_83 ) )
continue;
V_28 = F_47 ( sizeof( * V_28 ) , V_100 ) ;
if ( V_28 == NULL ) {
F_39 ( V_42 -> V_56 , L_11 ) ;
continue;
}
V_28 -> V_7 = V_2 . V_3 + V_6 - 1 ;
V_28 -> V_42 . V_114 = & V_115 ;
V_28 -> V_42 . type = & V_113 ;
V_28 -> V_42 . V_79 = & V_42 -> V_42 ;
F_48 ( & V_28 -> V_42 , L_12 , F_49 ( & V_42 -> V_42 ) , V_16 ++ ) ;
F_50 ( F_24 ( V_28 -> V_77 . V_69 ) <
F_24 ( V_116 ) +
F_24 ( V_74 ) ) ;
F_23 ( & V_28 -> V_42 ,
V_116 ,
& V_28 -> V_77 ) ;
if ( F_51 ( & V_28 -> V_42 ) < 0 )
goto V_117;
F_52 ( V_42 ) ;
continue;
V_117:
F_43 ( V_28 ) ;
}
}
static int F_53 ( struct V_42 * V_42 , void * V_85 )
{
F_54 ( V_42 ) ;
return 0 ;
}
struct V_54 * F_55 ( T_5 V_118 )
{
struct V_54 * V_42 ;
F_20 ( & V_65 ) ;
V_42 = F_56 ( & V_119 , F_57 ( V_118 ) ) ;
if ( V_42 )
F_52 ( V_42 ) ;
F_21 ( & V_65 ) ;
return V_42 ;
}
static void F_58 ( struct V_54 * V_42 ,
unsigned long V_120 )
{
F_59 ( V_121 , & V_42 -> V_122 , V_120 ) ;
}
static void F_60 ( struct V_123 * V_122 )
{
struct V_54 * V_42 =
F_12 ( V_122 , struct V_54 , V_122 . V_122 ) ;
int V_124 = F_57 ( V_42 -> V_42 . V_118 ) ;
if ( F_61 ( F_62 () ,
V_42 -> V_56 -> V_125 + V_126 )
&& ! F_63 ( & V_42 -> V_56 -> V_127 ) ) {
F_58 ( V_42 , V_126 ) ;
return;
}
if ( F_64 ( & V_42 -> V_128 ,
V_129 ,
V_130 ) != V_129 )
return;
F_65 ( V_42 ) ;
F_66 ( & V_42 -> V_42 , NULL , F_53 ) ;
F_54 ( & V_42 -> V_42 ) ;
F_41 ( & V_65 ) ;
F_67 ( & V_119 , V_124 ) ;
F_42 ( & V_65 ) ;
F_45 ( V_42 ) ;
}
static void F_68 ( struct V_42 * V_43 )
{
struct V_54 * V_42 = V_54 ( V_43 ) ;
struct V_93 * V_56 = V_42 -> V_56 ;
unsigned long V_131 ;
F_69 ( & V_56 -> V_132 , V_131 ) ;
V_42 -> V_104 -> V_85 = NULL ;
F_70 ( & V_56 -> V_132 , V_131 ) ;
F_71 ( V_42 -> V_104 ) ;
F_43 ( V_42 -> V_29 ) ;
F_43 ( V_42 ) ;
F_72 ( V_56 ) ;
}
static bool F_73 ( struct V_42 * V_43 )
{
return V_43 -> type == & V_133 ;
}
static int F_74 ( struct V_42 * V_43 , void * V_85 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
struct V_46 * V_47 = (struct V_46 * ) V_43 -> V_47 ;
if ( F_13 ( V_43 ) && V_47 != NULL && V_47 -> V_134 != NULL ) {
F_75 ( V_43 ) ;
V_47 -> V_134 ( V_28 ) ;
F_76 ( V_43 ) ;
}
return 0 ;
}
static void F_77 ( struct V_123 * V_122 )
{
struct V_54 * V_42 =
F_12 ( V_122 , struct V_54 , V_122 . V_122 ) ;
F_78 ( V_42 ) ;
F_66 ( & V_42 -> V_42 , NULL , F_74 ) ;
}
static int F_79 ( struct V_42 * V_43 , void * V_85 )
{
struct V_54 * V_135 = V_54 ( V_43 ) ;
struct V_54 * V_136 = V_85 ;
struct V_93 * V_56 = V_136 -> V_56 ;
int V_32 = 0 ;
if ( ! F_73 ( V_43 ) )
return 0 ;
F_20 ( & V_65 ) ;
F_80 ( & V_56 -> V_132 ) ;
if ( memcmp ( V_135 -> V_29 , V_136 -> V_29 , 6 * 4 ) == 0 &&
F_64 ( & V_135 -> V_128 ,
V_129 ,
V_137 ) == V_129 ) {
struct V_138 * V_139 = V_136 -> V_104 ;
struct V_138 * V_140 = V_135 -> V_104 ;
V_136 -> V_104 = V_140 ;
V_136 -> V_104 -> V_85 = V_136 ;
V_135 -> V_104 = V_139 ;
V_135 -> V_104 -> V_85 = V_135 ;
V_135 -> V_91 = V_136 -> V_91 ;
V_135 -> V_58 = V_139 -> V_58 ;
F_81 () ;
V_135 -> V_55 = V_56 -> V_55 ;
V_135 -> V_141 = 0 ;
F_82 ( V_56 , L_13 , F_49 ( V_43 ) ) ;
F_83 ( & V_135 -> V_122 , F_77 ) ;
F_58 ( V_135 , 0 ) ;
if ( V_139 == V_56 -> V_142 )
F_84 ( V_56 , 0 ) ;
V_32 = 1 ;
}
F_85 ( & V_56 -> V_132 ) ;
F_21 ( & V_65 ) ;
return V_32 ;
}
static void F_86 ( struct V_54 * V_42 , int V_55 )
{
struct V_93 * V_56 = V_42 -> V_56 ;
T_6 V_85 ;
int V_89 ;
if ( ! V_56 -> V_143 )
return;
if ( ! V_42 -> V_112 || V_42 -> V_110 < 8 )
return;
if ( V_42 -> V_144 == V_145 ) {
V_89 = F_33 ( V_56 , V_90 ,
V_42 -> V_58 , V_55 , V_42 -> V_91 ,
V_87 + V_146 ,
& V_85 , 4 ) ;
switch ( V_89 ) {
case V_102 :
if ( V_85 & F_87 ( 1 << 31 ) ) {
V_42 -> V_144 = V_147 ;
break;
}
case V_148 :
V_42 -> V_144 = V_149 ;
}
}
if ( V_42 -> V_144 == V_147 ) {
V_85 = F_87 ( V_150 |
V_151 ) ;
F_33 ( V_56 , V_152 ,
V_42 -> V_58 , V_55 , V_42 -> V_91 ,
V_87 + V_146 ,
& V_85 , 4 ) ;
}
}
int F_88 ( struct V_42 * V_43 , void * V_153 )
{
if ( F_73 ( V_43 ) )
F_86 ( V_54 ( V_43 ) , ( long ) V_153 ) ;
return 0 ;
}
static void F_89 ( struct V_123 * V_122 )
{
struct V_54 * V_42 =
F_12 ( V_122 , struct V_54 , V_122 . V_122 ) ;
struct V_93 * V_56 = V_42 -> V_56 ;
struct V_42 * V_154 ;
int V_124 , V_64 ;
V_64 = F_36 ( V_42 , V_42 -> V_55 ) ;
if ( V_64 != V_102 ) {
if ( V_42 -> V_141 < V_155 &&
F_90 ( & V_42 -> V_128 ) == V_156 ) {
V_42 -> V_141 ++ ;
F_58 ( V_42 , V_157 ) ;
} else {
if ( V_42 -> V_104 -> V_158 )
F_82 ( V_56 , L_14 ,
V_42 -> V_58 ,
F_91 ( V_64 ) ) ;
if ( V_42 -> V_104 == V_56 -> V_142 )
F_84 ( V_56 , 0 ) ;
F_68 ( & V_42 -> V_42 ) ;
}
return;
}
V_154 = F_92 ( V_56 -> V_42 ,
V_42 , F_79 ) ;
if ( V_154 ) {
F_93 ( V_154 ) ;
F_68 ( & V_42 -> V_42 ) ;
return;
}
F_94 ( & V_42 -> V_42 ) ;
F_52 ( V_42 ) ;
F_41 ( & V_65 ) ;
V_124 = F_95 ( & V_119 , V_42 , 0 , 1 << V_159 ,
V_100 ) ;
F_42 ( & V_65 ) ;
if ( V_124 < 0 )
goto error;
V_42 -> V_42 . V_114 = & V_115 ;
V_42 -> V_42 . type = & V_133 ;
V_42 -> V_42 . V_79 = V_56 -> V_42 ;
V_42 -> V_42 . V_118 = F_96 ( V_160 , V_124 ) ;
F_48 ( & V_42 -> V_42 , L_15 , V_124 ) ;
F_50 ( F_24 ( V_42 -> V_77 . V_69 ) <
F_24 ( V_161 ) +
F_24 ( V_74 ) ) ;
F_23 ( & V_42 -> V_42 ,
V_161 ,
& V_42 -> V_77 ) ;
if ( F_97 ( & V_42 -> V_42 ) ) {
F_39 ( V_56 , L_16 ) ;
goto V_162;
}
F_46 ( V_42 ) ;
if ( F_64 ( & V_42 -> V_128 ,
V_156 ,
V_137 ) == V_129 ) {
F_83 ( & V_42 -> V_122 , F_60 ) ;
F_58 ( V_42 , V_126 ) ;
} else {
F_82 ( V_56 , L_17 ,
F_49 ( & V_42 -> V_42 ) ,
V_42 -> V_29 [ 3 ] , V_42 -> V_29 [ 4 ] ,
1 << V_42 -> V_91 ) ;
V_42 -> V_141 = 0 ;
F_86 ( V_42 , V_42 -> V_55 ) ;
F_98 ( & V_42 -> V_29 [ 3 ] , 8 ) ;
}
if ( V_42 -> V_104 == V_56 -> V_142 )
F_84 ( V_56 , 0 ) ;
return;
V_162:
F_41 ( & V_65 ) ;
F_67 ( & V_119 , V_124 ) ;
F_42 ( & V_65 ) ;
error:
F_45 ( V_42 ) ;
F_93 ( & V_42 -> V_42 ) ;
}
static int F_99 ( struct V_54 * V_42 , int V_55 ,
bool * V_163 )
{
T_1 V_164 ;
int V_16 , V_89 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
V_89 = F_32 ( V_42 , V_55 , V_16 , & V_164 ) ;
if ( V_89 != V_102 )
return V_89 ;
if ( V_16 == 0 && V_164 == 0 )
return V_92 ;
if ( V_164 != V_42 -> V_29 [ V_16 ] ) {
* V_163 = true ;
return V_102 ;
}
}
* V_163 = false ;
return V_102 ;
}
static void F_100 ( struct V_123 * V_122 )
{
struct V_54 * V_42 =
F_12 ( V_122 , struct V_54 , V_122 . V_122 ) ;
struct V_93 * V_56 = V_42 -> V_56 ;
int V_64 , V_58 = V_42 -> V_58 ;
bool V_163 ;
V_64 = F_99 ( V_42 , V_42 -> V_55 , & V_163 ) ;
if ( V_64 != V_102 )
goto V_165;
if ( ! V_163 ) {
if ( F_64 ( & V_42 -> V_128 ,
V_156 ,
V_137 ) == V_129 )
goto V_166;
F_77 ( V_122 ) ;
V_42 -> V_141 = 0 ;
goto V_103;
}
F_66 ( & V_42 -> V_42 , NULL , F_53 ) ;
V_64 = F_36 ( V_42 , V_42 -> V_55 ) ;
if ( V_64 != V_102 )
goto V_165;
F_78 ( V_42 ) ;
F_46 ( V_42 ) ;
F_101 ( & V_42 -> V_42 . V_167 , V_168 ) ;
if ( F_64 ( & V_42 -> V_128 ,
V_156 ,
V_137 ) == V_129 )
goto V_166;
F_82 ( V_56 , L_18 , F_49 ( & V_42 -> V_42 ) ) ;
V_42 -> V_141 = 0 ;
goto V_103;
V_165:
if ( V_42 -> V_141 < V_155 &&
F_90 ( & V_42 -> V_128 ) == V_156 ) {
V_42 -> V_141 ++ ;
F_58 ( V_42 , V_157 ) ;
return;
}
F_82 ( V_56 , L_19 ,
F_49 ( & V_42 -> V_42 ) , F_91 ( V_64 ) ) ;
V_166:
F_102 ( & V_42 -> V_128 , V_129 ) ;
F_83 ( & V_42 -> V_122 , F_60 ) ;
F_58 ( V_42 , V_126 ) ;
V_103:
if ( V_58 == V_56 -> V_142 -> V_58 )
F_84 ( V_56 , 0 ) ;
}
void F_103 ( struct V_93 * V_56 , struct V_138 * V_104 , int V_169 )
{
struct V_54 * V_42 ;
switch ( V_169 ) {
case V_170 :
V_171:
V_42 = F_47 ( sizeof( * V_42 ) , V_172 ) ;
if ( V_42 == NULL )
break;
F_102 ( & V_42 -> V_128 , V_156 ) ;
V_42 -> V_56 = F_104 ( V_56 ) ;
V_42 -> V_104 = F_105 ( V_104 ) ;
V_42 -> V_58 = V_104 -> V_58 ;
V_42 -> V_55 = V_56 -> V_55 ;
V_42 -> V_81 = V_104 == V_56 -> V_173 ;
F_106 ( & V_42 -> V_174 ) ;
F_107 ( & V_42 -> V_175 ) ;
V_104 -> V_85 = V_42 ;
F_108 ( & V_42 -> V_122 , F_89 ) ;
F_58 ( V_42 , V_176 ) ;
break;
case V_177 :
case V_178 :
V_42 = V_104 -> V_85 ;
if ( V_42 == NULL )
goto V_171;
V_42 -> V_58 = V_104 -> V_58 ;
F_81 () ;
V_42 -> V_55 = V_56 -> V_55 ;
if ( F_64 ( & V_42 -> V_128 ,
V_137 ,
V_156 ) == V_137 ) {
F_83 ( & V_42 -> V_122 , F_100 ) ;
F_58 ( V_42 ,
V_42 -> V_81 ? 0 : V_176 ) ;
}
break;
case V_179 :
V_42 = V_104 -> V_85 ;
if ( V_42 == NULL )
break;
V_42 -> V_58 = V_104 -> V_58 ;
F_81 () ;
V_42 -> V_55 = V_56 -> V_55 ;
if ( F_90 ( & V_42 -> V_128 ) == V_137 ) {
F_83 ( & V_42 -> V_122 , F_77 ) ;
F_58 ( V_42 , 0 ) ;
}
break;
case V_180 :
case V_181 :
if ( ! V_104 -> V_85 )
break;
V_42 = V_104 -> V_85 ;
if ( F_109 ( & V_42 -> V_128 ,
V_129 ) == V_137 ) {
F_83 ( & V_42 -> V_122 , F_60 ) ;
F_58 ( V_42 ,
F_63 ( & V_56 -> V_127 ) ? 0 : V_126 ) ;
}
break;
}
}
