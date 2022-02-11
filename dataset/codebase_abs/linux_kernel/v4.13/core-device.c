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
static const struct V_30 * F_11 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
const struct V_30 * V_31 =
F_12 ( V_45 , struct V_46 , V_47 ) -> V_31 ;
int V_22 [] = { 0 , 0 , 0 , 0 } ;
F_8 ( V_27 ( V_43 ) , V_22 ) ;
for (; V_31 -> V_41 != 0 ; V_31 ++ )
if ( F_10 ( V_31 , V_22 ) )
return V_31 ;
return NULL ;
}
static int F_13 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
return F_14 ( V_43 ) && F_11 ( V_43 , V_45 ) != NULL ;
}
static int F_15 ( struct V_42 * V_43 )
{
struct V_46 * V_47 =
F_12 ( V_43 -> V_47 , struct V_46 , V_47 ) ;
return V_47 -> V_48 ( V_27 ( V_43 ) , F_11 ( V_43 , V_43 -> V_47 ) ) ;
}
static int F_16 ( struct V_42 * V_43 )
{
struct V_46 * V_47 =
F_12 ( V_43 -> V_47 , struct V_46 , V_47 ) ;
return V_47 -> remove ( V_27 ( V_43 ) ) , 0 ;
}
static int F_17 ( struct V_27 * V_28 , char * V_49 , T_2 V_50 )
{
int V_22 [] = { 0 , 0 , 0 , 0 } ;
F_8 ( V_28 , V_22 ) ;
return snprintf ( V_49 , V_50 ,
L_1 ,
V_22 [ 0 ] , V_22 [ 1 ] , V_22 [ 2 ] , V_22 [ 3 ] ) ;
}
static int F_18 ( struct V_42 * V_43 , struct V_51 * V_52 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
char V_53 [ 64 ] ;
F_17 ( V_28 , V_53 , sizeof( V_53 ) ) ;
if ( F_19 ( V_52 , L_2 , V_53 ) )
return - V_54 ;
return 0 ;
}
int F_20 ( struct V_55 * V_42 )
{
int V_56 = V_42 -> V_56 ;
F_21 () ;
return V_42 -> V_57 -> V_47 -> V_58 ( V_42 -> V_57 ,
V_42 -> V_59 ,
V_56 ) ;
}
static T_3 F_22 ( struct V_42 * V_43 ,
struct V_60 * V_61 , char * V_13 )
{
struct V_62 * V_63 =
F_12 ( V_61 , struct V_62 , V_63 ) ;
struct V_1 V_2 ;
const T_1 * V_64 ;
int V_5 , V_6 , V_65 = - V_21 ;
F_23 ( & V_66 ) ;
if ( F_14 ( V_43 ) )
V_64 = V_27 ( V_43 ) -> V_7 ;
else
V_64 = V_55 ( V_43 ) -> V_29 + 5 ;
F_1 ( & V_2 , V_64 ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) )
if ( V_63 -> V_5 == V_5 ) {
V_65 = snprintf ( V_13 , V_13 ? V_67 : 0 ,
L_3 , V_6 ) ;
break;
}
F_24 ( & V_66 ) ;
return V_65 ;
}
static T_3 F_25 ( struct V_42 * V_43 ,
struct V_60 * V_61 , char * V_13 )
{
struct V_62 * V_63 =
F_12 ( V_61 , struct V_62 , V_63 ) ;
const T_1 * V_64 ;
T_2 V_68 ;
char V_69 [ 2 ] ;
int V_65 ;
F_23 ( & V_66 ) ;
if ( F_14 ( V_43 ) )
V_64 = V_27 ( V_43 ) -> V_7 ;
else
V_64 = V_55 ( V_43 ) -> V_29 + 5 ;
if ( V_13 ) {
V_68 = V_67 - 1 ;
} else {
V_13 = V_69 ;
V_68 = 1 ;
}
V_65 = F_6 ( V_64 , V_63 -> V_5 , V_13 , V_68 ) ;
if ( V_65 >= 0 ) {
while ( V_65 > 0 && isspace ( V_13 [ V_65 - 1 ] ) )
V_65 -- ;
strcpy ( V_13 + V_65 , L_4 ) ;
V_65 ++ ;
}
F_24 ( & V_66 ) ;
return V_65 ;
}
static void F_26 ( struct V_42 * V_43 ,
struct V_60 * V_70 ,
struct V_71 * V_72 )
{
struct V_60 * V_63 ;
int V_16 , V_73 ;
for ( V_73 = 0 ; V_70 [ V_73 ] . V_63 . V_74 != NULL ; V_73 ++ )
V_72 -> V_70 [ V_73 ] = & V_70 [ V_73 ] . V_63 ;
for ( V_16 = 0 ; V_16 < F_27 ( V_75 ) ; V_16 ++ ) {
V_63 = & V_75 [ V_16 ] . V_63 ;
if ( V_63 -> V_76 ( V_43 , V_63 , NULL ) < 0 )
continue;
V_72 -> V_70 [ V_73 ++ ] = & V_63 -> V_63 ;
}
V_72 -> V_70 [ V_73 ] = NULL ;
V_72 -> V_77 [ 0 ] = & V_72 -> V_72 ;
V_72 -> V_77 [ 1 ] = NULL ;
V_72 -> V_72 . V_70 = V_72 -> V_70 ;
V_43 -> V_77 = ( const struct V_78 * * ) V_72 -> V_77 ;
}
static T_3 F_28 ( struct V_42 * V_43 ,
struct V_60 * V_63 , char * V_13 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
int V_79 ;
V_79 = F_17 ( V_28 , V_13 , V_67 ) ;
strcpy ( V_13 + V_79 , L_4 ) ;
return V_79 + 1 ;
}
static T_3 F_29 ( struct V_42 * V_43 ,
struct V_60 * V_63 , char * V_13 )
{
struct V_55 * V_42 = V_55 ( V_43 -> V_80 ) ;
struct V_27 * V_28 = V_27 ( V_43 ) ;
return snprintf ( V_13 , V_67 , L_5 ,
( int ) ( V_28 -> V_7 - V_42 -> V_29 ) ) ;
}
static T_3 F_30 ( struct V_42 * V_43 ,
struct V_60 * V_63 , char * V_13 )
{
struct V_55 * V_42 = V_55 ( V_43 ) ;
T_2 V_79 ;
F_23 ( & V_66 ) ;
V_79 = V_42 -> V_81 * 4 ;
memcpy ( V_13 , V_42 -> V_29 , V_79 ) ;
F_24 ( & V_66 ) ;
return V_79 ;
}
static T_3 F_31 ( struct V_42 * V_43 ,
struct V_60 * V_63 , char * V_13 )
{
struct V_55 * V_42 = V_55 ( V_43 ) ;
int V_65 ;
F_23 ( & V_66 ) ;
V_65 = snprintf ( V_13 , V_67 , L_6 ,
V_42 -> V_29 [ 3 ] , V_42 -> V_29 [ 4 ] ) ;
F_24 ( & V_66 ) ;
return V_65 ;
}
static T_3 F_32 ( struct V_42 * V_43 ,
struct V_60 * V_63 , char * V_13 )
{
struct V_55 * V_42 = V_55 ( V_43 ) ;
return sprintf ( V_13 , L_7 , V_42 -> V_82 ) ;
}
static int F_33 ( char * V_13 , const T_1 * V_7 )
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
static T_3 F_34 ( struct V_42 * V_43 ,
struct V_60 * V_63 , char * V_13 )
{
struct V_55 * V_42 = V_55 ( V_43 ) ;
struct V_1 V_2 ;
int V_5 , V_6 , V_16 = 0 ;
F_23 ( & V_66 ) ;
F_1 ( & V_2 , & V_42 -> V_29 [ 5 ] ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
if ( V_5 != ( V_83 | V_84 ) )
continue;
V_16 += F_33 ( & V_13 [ V_16 ] , V_2 . V_3 + V_6 - 1 ) ;
if ( V_16 >= V_67 - ( 8 + 1 + 8 + 1 ) )
break;
}
F_24 ( & V_66 ) ;
if ( V_16 )
V_13 [ V_16 - 1 ] = '\n' ;
return V_16 ;
}
static int F_35 ( struct V_55 * V_42 ,
int V_56 , int V_85 , T_1 * V_86 )
{
T_4 V_87 = ( V_88 | V_89 ) + V_85 * 4 ;
int V_16 , V_90 ;
F_21 () ;
for ( V_16 = 10 ; V_16 < 100 ; V_16 += 10 ) {
V_90 = F_36 ( V_42 -> V_57 ,
V_91 , V_42 -> V_59 ,
V_56 , V_42 -> V_92 , V_87 , V_86 , 4 ) ;
if ( V_90 != V_93 )
break;
F_37 ( V_16 ) ;
}
F_38 ( V_86 ) ;
return V_90 ;
}
static int F_39 ( struct V_55 * V_42 , int V_56 )
{
struct V_94 * V_57 = V_42 -> V_57 ;
const T_1 * V_95 , * V_96 ;
T_1 * V_97 , * V_98 ;
T_1 V_99 , V_5 ;
int V_16 , V_4 , V_79 , V_65 ;
V_97 = F_40 ( sizeof( * V_97 ) * V_100 +
sizeof( * V_98 ) * V_100 , V_101 ) ;
if ( V_97 == NULL )
return - V_54 ;
V_98 = & V_97 [ V_100 ] ;
memset ( V_97 , 0 , sizeof( * V_97 ) * V_100 ) ;
V_42 -> V_92 = V_102 ;
for ( V_16 = 0 ; V_16 < 5 ; V_16 ++ ) {
V_65 = F_35 ( V_42 , V_56 , V_16 , & V_97 [ V_16 ] ) ;
if ( V_65 != V_103 )
goto V_104;
if ( V_16 == 0 && V_97 [ V_16 ] == 0 ) {
V_65 = V_93 ;
goto V_104;
}
}
V_42 -> V_92 = V_42 -> V_105 -> V_92 ;
if ( ( V_97 [ 2 ] & 0x7 ) < V_42 -> V_92 ||
V_42 -> V_92 == V_106 ||
V_57 -> V_107 ) {
T_1 V_108 ;
if ( V_42 -> V_92 == V_106 )
V_42 -> V_92 = V_57 -> V_109 ;
while ( V_42 -> V_92 > V_102 ) {
if ( F_35 ( V_42 , V_56 , 0 , & V_108 ) ==
V_103 )
break;
V_42 -> V_92 -- ;
}
}
V_79 = V_16 ;
V_99 = 0 ;
V_98 [ V_99 ++ ] = 0xc0000005 ;
while ( V_99 > 0 ) {
V_5 = V_98 [ -- V_99 ] ;
V_16 = V_5 & 0xffffff ;
if ( F_41 ( V_16 >= V_100 ) ) {
V_65 = - V_110 ;
goto V_104;
}
V_65 = F_35 ( V_42 , V_56 , V_16 , & V_97 [ V_16 ] ) ;
if ( V_65 != V_103 )
goto V_104;
V_4 = V_16 + ( V_97 [ V_16 ] >> 16 ) + 1 ;
if ( V_4 > V_100 ) {
F_42 ( V_57 , L_9 ,
V_97 [ V_16 ] ,
V_16 * 4 | V_88 | V_89 ) ;
V_97 [ V_16 ] = 0 ;
V_4 = V_16 ;
}
V_16 ++ ;
for (; V_16 < V_4 ; V_16 ++ ) {
V_65 = F_35 ( V_42 , V_56 , V_16 , & V_97 [ V_16 ] ) ;
if ( V_65 != V_103 )
goto V_104;
if ( ( V_5 >> 30 ) != 3 || ( V_97 [ V_16 ] >> 30 ) < 2 )
continue;
if ( V_16 + ( V_97 [ V_16 ] & 0xffffff ) >= V_100 ) {
F_42 ( V_57 ,
L_10 ,
V_97 [ V_16 ] ,
V_16 * 4 | V_88 | V_89 ) ;
V_97 [ V_16 ] = 0 ;
continue;
}
V_98 [ V_99 ++ ] = V_16 + V_97 [ V_16 ] ;
}
if ( V_79 < V_16 )
V_79 = V_16 ;
}
V_95 = V_42 -> V_29 ;
V_96 = F_43 ( V_97 , V_79 * 4 , V_101 ) ;
if ( V_96 == NULL ) {
V_65 = - V_54 ;
goto V_104;
}
F_44 ( & V_66 ) ;
V_42 -> V_29 = V_96 ;
V_42 -> V_81 = V_79 ;
F_45 ( & V_66 ) ;
F_46 ( V_95 ) ;
V_65 = V_103 ;
V_42 -> V_111 = V_97 [ 2 ] >> 12 & 0xf ;
V_42 -> V_112 = V_97 [ 2 ] >> 30 & 1 ;
V_42 -> V_113 = V_97 [ 2 ] >> 31 & 1 ;
V_104:
F_46 ( V_97 ) ;
return V_65 ;
}
static void F_47 ( struct V_42 * V_43 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
F_48 ( F_9 ( V_28 ) ) ;
F_46 ( V_28 ) ;
}
static bool F_14 ( struct V_42 * V_43 )
{
return V_43 -> type == & V_114 ;
}
static void F_49 ( struct V_55 * V_42 )
{
struct V_1 V_2 ;
struct V_27 * V_28 ;
int V_5 , V_6 , V_16 ;
V_16 = 0 ;
F_1 ( & V_2 , & V_42 -> V_29 [ 5 ] ) ;
while ( F_2 ( & V_2 , & V_5 , & V_6 ) ) {
if ( V_5 != ( V_83 | V_84 ) )
continue;
V_28 = F_50 ( sizeof( * V_28 ) , V_101 ) ;
if ( V_28 == NULL )
continue;
V_28 -> V_7 = V_2 . V_3 + V_6 - 1 ;
V_28 -> V_42 . V_115 = & V_116 ;
V_28 -> V_42 . type = & V_114 ;
V_28 -> V_42 . V_80 = & V_42 -> V_42 ;
F_51 ( & V_28 -> V_42 , L_11 , F_52 ( & V_42 -> V_42 ) , V_16 ++ ) ;
F_53 ( F_27 ( V_28 -> V_78 . V_70 ) <
F_27 ( V_117 ) +
F_27 ( V_75 ) ) ;
F_26 ( & V_28 -> V_42 ,
V_117 ,
& V_28 -> V_78 ) ;
if ( F_54 ( & V_28 -> V_42 ) < 0 )
goto V_118;
F_55 ( V_42 ) ;
continue;
V_118:
F_46 ( V_28 ) ;
}
}
static int F_56 ( struct V_42 * V_42 , void * V_86 )
{
F_57 ( V_42 ) ;
return 0 ;
}
struct V_55 * F_58 ( T_5 V_119 )
{
struct V_55 * V_42 ;
F_23 ( & V_66 ) ;
V_42 = F_59 ( & V_120 , F_60 ( V_119 ) ) ;
if ( V_42 )
F_55 ( V_42 ) ;
F_24 ( & V_66 ) ;
return V_42 ;
}
static void F_61 ( struct V_55 * V_42 ,
unsigned long V_121 )
{
F_62 ( V_122 , & V_42 -> V_123 , V_121 ) ;
}
static void F_63 ( struct V_124 * V_123 )
{
struct V_55 * V_42 =
F_12 ( V_123 , struct V_55 , V_123 . V_123 ) ;
int V_125 = F_60 ( V_42 -> V_42 . V_119 ) ;
if ( F_64 ( F_65 () ,
V_42 -> V_57 -> V_126 + V_127 )
&& ! F_66 ( & V_42 -> V_57 -> V_128 ) ) {
F_61 ( V_42 , V_127 ) ;
return;
}
if ( F_67 ( & V_42 -> V_129 ,
V_130 ,
V_131 ) != V_130 )
return;
F_68 ( V_42 ) ;
F_69 ( & V_42 -> V_42 , NULL , F_56 ) ;
F_57 ( & V_42 -> V_42 ) ;
F_44 ( & V_66 ) ;
F_70 ( & V_120 , V_125 ) ;
F_45 ( & V_66 ) ;
F_48 ( V_42 ) ;
}
static void F_71 ( struct V_42 * V_43 )
{
struct V_55 * V_42 = V_55 ( V_43 ) ;
struct V_94 * V_57 = V_42 -> V_57 ;
unsigned long V_132 ;
F_72 ( & V_57 -> V_133 , V_132 ) ;
V_42 -> V_105 -> V_86 = NULL ;
F_73 ( & V_57 -> V_133 , V_132 ) ;
F_74 ( V_42 -> V_105 ) ;
F_46 ( V_42 -> V_29 ) ;
F_46 ( V_42 ) ;
F_75 ( V_57 ) ;
}
static bool F_76 ( struct V_42 * V_43 )
{
return V_43 -> type == & V_134 ;
}
static int F_77 ( struct V_42 * V_43 , void * V_86 )
{
struct V_27 * V_28 = V_27 ( V_43 ) ;
struct V_46 * V_47 = (struct V_46 * ) V_43 -> V_47 ;
if ( F_14 ( V_43 ) && V_47 != NULL && V_47 -> V_135 != NULL ) {
F_78 ( V_43 ) ;
V_47 -> V_135 ( V_28 ) ;
F_79 ( V_43 ) ;
}
return 0 ;
}
static void F_80 ( struct V_124 * V_123 )
{
struct V_55 * V_42 =
F_12 ( V_123 , struct V_55 , V_123 . V_123 ) ;
F_81 ( V_42 ) ;
F_69 ( & V_42 -> V_42 , NULL , F_77 ) ;
}
static int F_82 ( struct V_42 * V_43 , void * V_86 )
{
struct V_55 * V_136 = V_55 ( V_43 ) ;
struct V_55 * V_137 = V_86 ;
struct V_94 * V_57 = V_137 -> V_57 ;
int V_32 = 0 ;
if ( ! F_76 ( V_43 ) )
return 0 ;
F_23 ( & V_66 ) ;
F_83 ( & V_57 -> V_133 ) ;
if ( memcmp ( V_136 -> V_29 , V_137 -> V_29 , 6 * 4 ) == 0 &&
F_67 ( & V_136 -> V_129 ,
V_130 ,
V_138 ) == V_130 ) {
struct V_139 * V_140 = V_137 -> V_105 ;
struct V_139 * V_141 = V_136 -> V_105 ;
V_137 -> V_105 = V_141 ;
V_137 -> V_105 -> V_86 = V_137 ;
V_136 -> V_105 = V_140 ;
V_136 -> V_105 -> V_86 = V_136 ;
V_136 -> V_92 = V_137 -> V_92 ;
V_136 -> V_59 = V_140 -> V_59 ;
F_84 () ;
V_136 -> V_56 = V_57 -> V_56 ;
V_136 -> V_142 = 0 ;
F_85 ( V_57 , L_12 , F_52 ( V_43 ) ) ;
V_136 -> V_143 = F_80 ;
F_61 ( V_136 , 0 ) ;
if ( V_140 == V_57 -> V_144 )
F_86 ( V_57 , 0 ) ;
V_32 = 1 ;
}
F_87 ( & V_57 -> V_133 ) ;
F_24 ( & V_66 ) ;
return V_32 ;
}
static void F_88 ( struct V_55 * V_42 , int V_56 )
{
struct V_94 * V_57 = V_42 -> V_57 ;
T_6 V_86 ;
int V_90 ;
if ( ! V_57 -> V_145 )
return;
if ( ! V_42 -> V_113 || V_42 -> V_111 < 8 )
return;
if ( V_42 -> V_146 == V_147 ) {
V_90 = F_36 ( V_57 , V_91 ,
V_42 -> V_59 , V_56 , V_42 -> V_92 ,
V_88 + V_148 ,
& V_86 , 4 ) ;
switch ( V_90 ) {
case V_103 :
if ( V_86 & F_89 ( 1 << 31 ) ) {
V_42 -> V_146 = V_149 ;
break;
}
case V_150 :
V_42 -> V_146 = V_151 ;
}
}
if ( V_42 -> V_146 == V_149 ) {
V_86 = F_89 ( V_152 |
V_153 ) ;
F_36 ( V_57 , V_154 ,
V_42 -> V_59 , V_56 , V_42 -> V_92 ,
V_88 + V_148 ,
& V_86 , 4 ) ;
}
}
int F_90 ( struct V_42 * V_43 , void * V_155 )
{
if ( F_76 ( V_43 ) )
F_88 ( V_55 ( V_43 ) , ( long ) V_155 ) ;
return 0 ;
}
static void F_91 ( struct V_124 * V_123 )
{
struct V_55 * V_42 =
F_12 ( V_123 , struct V_55 , V_123 . V_123 ) ;
struct V_94 * V_57 = V_42 -> V_57 ;
struct V_42 * V_156 ;
int V_125 , V_65 ;
V_65 = F_39 ( V_42 , V_42 -> V_56 ) ;
if ( V_65 != V_103 ) {
if ( V_42 -> V_142 < V_157 &&
F_92 ( & V_42 -> V_129 ) == V_158 ) {
V_42 -> V_142 ++ ;
F_61 ( V_42 , V_159 ) ;
} else {
if ( V_42 -> V_105 -> V_160 )
F_85 ( V_57 , L_13 ,
V_42 -> V_59 ,
F_93 ( V_65 ) ) ;
if ( V_42 -> V_105 == V_57 -> V_144 )
F_86 ( V_57 , 0 ) ;
F_71 ( & V_42 -> V_42 ) ;
}
return;
}
V_156 = F_94 ( V_57 -> V_42 ,
V_42 , F_82 ) ;
if ( V_156 ) {
F_95 ( V_156 ) ;
F_71 ( & V_42 -> V_42 ) ;
return;
}
F_96 ( & V_42 -> V_42 ) ;
F_55 ( V_42 ) ;
F_44 ( & V_66 ) ;
V_125 = F_97 ( & V_120 , V_42 , 0 , 1 << V_161 ,
V_101 ) ;
F_45 ( & V_66 ) ;
if ( V_125 < 0 )
goto error;
V_42 -> V_42 . V_115 = & V_116 ;
V_42 -> V_42 . type = & V_134 ;
V_42 -> V_42 . V_80 = V_57 -> V_42 ;
V_42 -> V_42 . V_119 = F_98 ( V_162 , V_125 ) ;
F_51 ( & V_42 -> V_42 , L_14 , V_125 ) ;
F_53 ( F_27 ( V_42 -> V_78 . V_70 ) <
F_27 ( V_163 ) +
F_27 ( V_75 ) ) ;
F_26 ( & V_42 -> V_42 ,
V_163 ,
& V_42 -> V_78 ) ;
if ( F_99 ( & V_42 -> V_42 ) ) {
F_42 ( V_57 , L_15 ) ;
goto V_164;
}
F_49 ( V_42 ) ;
if ( F_67 ( & V_42 -> V_129 ,
V_158 ,
V_138 ) == V_130 ) {
V_42 -> V_143 = F_63 ;
F_61 ( V_42 , V_127 ) ;
} else {
F_85 ( V_57 , L_16 ,
F_52 ( & V_42 -> V_42 ) ,
V_42 -> V_29 [ 3 ] , V_42 -> V_29 [ 4 ] ,
1 << V_42 -> V_92 ) ;
V_42 -> V_142 = 0 ;
F_88 ( V_42 , V_42 -> V_56 ) ;
F_100 ( & V_42 -> V_29 [ 3 ] , 8 ) ;
}
if ( V_42 -> V_105 == V_57 -> V_144 )
F_86 ( V_57 , 0 ) ;
return;
V_164:
F_44 ( & V_66 ) ;
F_70 ( & V_120 , V_125 ) ;
F_45 ( & V_66 ) ;
error:
F_48 ( V_42 ) ;
F_95 ( & V_42 -> V_42 ) ;
}
static int F_101 ( struct V_55 * V_42 , int V_56 ,
bool * V_165 )
{
T_1 V_166 ;
int V_16 , V_90 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
V_90 = F_35 ( V_42 , V_56 , V_16 , & V_166 ) ;
if ( V_90 != V_103 )
return V_90 ;
if ( V_16 == 0 && V_166 == 0 )
return V_93 ;
if ( V_166 != V_42 -> V_29 [ V_16 ] ) {
* V_165 = true ;
return V_103 ;
}
}
* V_165 = false ;
return V_103 ;
}
static void F_102 ( struct V_124 * V_123 )
{
struct V_55 * V_42 =
F_12 ( V_123 , struct V_55 , V_123 . V_123 ) ;
struct V_94 * V_57 = V_42 -> V_57 ;
int V_65 , V_59 = V_42 -> V_59 ;
bool V_165 ;
V_65 = F_101 ( V_42 , V_42 -> V_56 , & V_165 ) ;
if ( V_65 != V_103 )
goto V_167;
if ( ! V_165 ) {
if ( F_67 ( & V_42 -> V_129 ,
V_158 ,
V_138 ) == V_130 )
goto V_168;
F_80 ( V_123 ) ;
V_42 -> V_142 = 0 ;
goto V_104;
}
F_69 ( & V_42 -> V_42 , NULL , F_56 ) ;
V_65 = F_39 ( V_42 , V_42 -> V_56 ) ;
if ( V_65 != V_103 )
goto V_167;
F_81 ( V_42 ) ;
F_49 ( V_42 ) ;
F_103 ( & V_42 -> V_42 . V_169 , V_170 ) ;
if ( F_67 ( & V_42 -> V_129 ,
V_158 ,
V_138 ) == V_130 )
goto V_168;
F_85 ( V_57 , L_17 , F_52 ( & V_42 -> V_42 ) ) ;
V_42 -> V_142 = 0 ;
goto V_104;
V_167:
if ( V_42 -> V_142 < V_157 &&
F_92 ( & V_42 -> V_129 ) == V_158 ) {
V_42 -> V_142 ++ ;
F_61 ( V_42 , V_159 ) ;
return;
}
F_85 ( V_57 , L_18 ,
F_52 ( & V_42 -> V_42 ) , F_93 ( V_65 ) ) ;
V_168:
F_104 ( & V_42 -> V_129 , V_130 ) ;
V_42 -> V_143 = F_63 ;
F_61 ( V_42 , V_127 ) ;
V_104:
if ( V_59 == V_57 -> V_144 -> V_59 )
F_86 ( V_57 , 0 ) ;
}
static void F_105 ( struct V_124 * V_123 )
{
struct V_55 * V_42 = F_12 ( F_106 ( V_123 ) ,
struct V_55 , V_123 ) ;
V_42 -> V_143 ( V_123 ) ;
}
void F_107 ( struct V_94 * V_57 , struct V_139 * V_105 , int V_171 )
{
struct V_55 * V_42 ;
switch ( V_171 ) {
case V_172 :
V_173:
V_42 = F_50 ( sizeof( * V_42 ) , V_174 ) ;
if ( V_42 == NULL )
break;
F_104 ( & V_42 -> V_129 , V_158 ) ;
V_42 -> V_57 = F_108 ( V_57 ) ;
V_42 -> V_105 = F_109 ( V_105 ) ;
V_42 -> V_59 = V_105 -> V_59 ;
V_42 -> V_56 = V_57 -> V_56 ;
V_42 -> V_82 = V_105 == V_57 -> V_175 ;
F_110 ( & V_42 -> V_176 ) ;
F_111 ( & V_42 -> V_177 ) ;
V_105 -> V_86 = V_42 ;
V_42 -> V_143 = F_91 ;
F_112 ( & V_42 -> V_123 , F_105 ) ;
F_61 ( V_42 , V_178 ) ;
break;
case V_179 :
case V_180 :
V_42 = V_105 -> V_86 ;
if ( V_42 == NULL )
goto V_173;
V_42 -> V_59 = V_105 -> V_59 ;
F_84 () ;
V_42 -> V_56 = V_57 -> V_56 ;
if ( F_67 ( & V_42 -> V_129 ,
V_138 ,
V_158 ) == V_138 ) {
V_42 -> V_143 = F_102 ;
F_61 ( V_42 ,
V_42 -> V_82 ? 0 : V_178 ) ;
}
break;
case V_181 :
V_42 = V_105 -> V_86 ;
if ( V_42 == NULL )
break;
V_42 -> V_59 = V_105 -> V_59 ;
F_84 () ;
V_42 -> V_56 = V_57 -> V_56 ;
if ( F_92 ( & V_42 -> V_129 ) == V_138 ) {
V_42 -> V_143 = F_80 ;
F_61 ( V_42 , 0 ) ;
}
break;
case V_182 :
case V_183 :
if ( ! V_105 -> V_86 )
break;
V_42 = V_105 -> V_86 ;
if ( F_113 ( & V_42 -> V_129 ,
V_130 ) == V_138 ) {
V_42 -> V_143 = F_63 ;
F_61 ( V_42 ,
F_66 ( & V_57 -> V_128 ) ? 0 : V_127 ) ;
}
break;
}
}
