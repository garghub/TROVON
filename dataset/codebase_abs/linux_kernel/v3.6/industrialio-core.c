const struct V_1
* F_1 ( struct V_2 * V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ )
if ( V_3 -> V_7 [ V_5 ] . V_8 == V_4 )
return & V_3 -> V_7 [ V_5 ] ;
return NULL ;
}
T_1 F_2 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
return sprintf ( V_13 , L_1 , F_3 ( V_12 ) -> string ) ;
}
static int T_2 F_4 ( void )
{
int V_14 ;
V_14 = F_5 ( & V_15 ) ;
if ( V_14 < 0 ) {
F_6 ( V_16
L_2 ,
__FILE__ ) ;
goto V_17;
}
V_14 = F_7 ( & V_18 , 0 , V_19 , L_3 ) ;
if ( V_14 < 0 ) {
F_6 ( V_16 L_4 ,
__FILE__ ) ;
goto V_20;
}
V_21 = F_8 ( L_3 , NULL ) ;
return 0 ;
V_20:
F_9 ( & V_15 ) ;
V_17:
return V_14 ;
}
static void T_3 F_10 ( void )
{
if ( V_18 )
F_11 ( V_18 , V_19 ) ;
F_9 ( & V_15 ) ;
F_12 ( V_21 ) ;
}
static T_1 F_13 ( struct V_22 * V_22 , char T_4 * V_23 ,
T_5 V_24 , T_6 * V_25 )
{
struct V_2 * V_3 = V_22 -> V_26 ;
char V_13 [ 20 ] ;
unsigned V_27 = 0 ;
T_1 V_28 ;
int V_14 ;
V_14 = V_3 -> V_29 -> V_30 ( V_3 ,
V_3 -> V_31 ,
0 , & V_27 ) ;
if ( V_14 )
F_14 ( V_3 -> V_10 . V_32 , L_5 , V_33 ) ;
V_28 = snprintf ( V_13 , sizeof( V_13 ) , L_6 , V_27 ) ;
return F_15 ( V_23 , V_24 , V_25 , V_13 , V_28 ) ;
}
static T_1 F_16 ( struct V_22 * V_22 ,
const char T_4 * V_23 , T_5 V_24 , T_6 * V_25 )
{
struct V_2 * V_3 = V_22 -> V_26 ;
unsigned V_34 , V_27 ;
char V_13 [ 80 ] ;
int V_14 ;
V_24 = F_17 ( T_5 , V_24 , ( sizeof( V_13 ) - 1 ) ) ;
if ( F_18 ( V_13 , V_23 , V_24 ) )
return - V_35 ;
V_13 [ V_24 ] = 0 ;
V_14 = sscanf ( V_13 , L_7 , & V_34 , & V_27 ) ;
switch ( V_14 ) {
case 1 :
V_3 -> V_31 = V_34 ;
break;
case 2 :
V_3 -> V_31 = V_34 ;
V_14 = V_3 -> V_29 -> V_30 ( V_3 , V_34 ,
V_27 , NULL ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 , L_8 ,
V_33 ) ;
return V_14 ;
}
break;
default:
return - V_36 ;
}
return V_24 ;
}
static void F_19 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_37 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_38 * V_39 ;
if ( V_3 -> V_29 -> V_30 == NULL )
return 0 ;
if ( ! V_21 )
return 0 ;
V_3 -> V_37 =
F_8 ( F_22 ( & V_3 -> V_10 ) ,
V_21 ) ;
if ( V_3 -> V_37 == NULL ) {
F_23 ( V_3 -> V_10 . V_32 ,
L_9 ) ;
return - V_35 ;
}
V_39 = F_24 ( L_10 , 0644 ,
V_3 -> V_37 ,
V_3 , & V_40 ) ;
if ( ! V_39 ) {
F_19 ( V_3 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_19 ( struct V_2 * V_3 )
{
}
static T_1 F_25 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_42 * V_43 = F_27 ( V_12 ) ;
const struct V_44 * V_45 ;
V_45 = & V_43 -> V_46 -> V_45 [ V_43 -> V_47 ] ;
return V_45 -> V_48 ( V_3 , V_45 -> V_49 , V_43 -> V_46 , V_13 ) ;
}
static T_1 F_28 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_42 * V_43 = F_27 ( V_12 ) ;
const struct V_44 * V_45 ;
V_45 = & V_43 -> V_46 -> V_45 [ V_43 -> V_47 ] ;
return V_45 -> V_50 ( V_3 , V_45 -> V_49 ,
V_43 -> V_46 , V_13 , V_28 ) ;
}
T_1 F_29 ( struct V_2 * V_3 ,
T_7 V_51 , const struct V_1 * V_52 , char * V_13 )
{
const struct V_53 * V_54 = ( const struct V_53 * ) V_51 ;
unsigned int V_5 ;
T_5 V_28 = 0 ;
if ( ! V_54 -> V_55 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_54 -> V_55 ; ++ V_5 )
V_28 += F_30 ( V_13 + V_28 , V_56 - V_28 , L_11 , V_54 -> V_57 [ V_5 ] ) ;
V_13 [ V_28 - 1 ] = '\n' ;
return V_28 ;
}
T_1 F_31 ( struct V_2 * V_3 ,
T_7 V_51 , const struct V_1 * V_52 , char * V_13 )
{
const struct V_53 * V_54 = ( const struct V_53 * ) V_51 ;
int V_5 ;
if ( ! V_54 -> V_58 )
return - V_36 ;
V_5 = V_54 -> V_58 ( V_3 , V_52 ) ;
if ( V_5 < 0 )
return V_5 ;
else if ( V_5 >= V_54 -> V_55 )
return - V_36 ;
return sprintf ( V_13 , L_1 , V_54 -> V_57 [ V_5 ] ) ;
}
T_1 F_32 ( struct V_2 * V_3 ,
T_7 V_51 , const struct V_1 * V_52 , const char * V_13 ,
T_5 V_28 )
{
const struct V_53 * V_54 = ( const struct V_53 * ) V_51 ;
unsigned int V_5 ;
int V_14 ;
if ( ! V_54 -> V_59 )
return - V_36 ;
for ( V_5 = 0 ; V_5 < V_54 -> V_55 ; V_5 ++ ) {
if ( F_33 ( V_13 , V_54 -> V_57 [ V_5 ] ) )
break;
}
if ( V_5 == V_54 -> V_55 )
return - V_36 ;
V_14 = V_54 -> V_59 ( V_3 , V_52 , V_5 ) ;
return V_14 ? V_14 : V_28 ;
}
static T_1 F_34 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_42 * V_43 = F_27 ( V_12 ) ;
int V_27 , V_60 ;
bool V_61 = false ;
int V_14 = V_3 -> V_29 -> V_62 ( V_3 , V_43 -> V_46 ,
& V_27 , & V_60 , V_43 -> V_47 ) ;
if ( V_14 < 0 )
return V_14 ;
switch ( V_14 ) {
case V_63 :
return sprintf ( V_13 , L_12 , V_27 ) ;
case V_64 :
V_61 = true ;
case V_65 :
if ( V_60 < 0 )
return sprintf ( V_13 , L_13 , V_27 , - V_60 ,
V_61 ? L_14 : L_15 ) ;
else
return sprintf ( V_13 , L_16 , V_27 , V_60 ,
V_61 ? L_14 : L_15 ) ;
case V_66 :
if ( V_60 < 0 )
return sprintf ( V_13 , L_17 , V_27 , - V_60 ) ;
else
return sprintf ( V_13 , L_18 , V_27 , V_60 ) ;
default:
return 0 ;
}
}
static T_1 F_35 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_42 * V_43 = F_27 ( V_12 ) ;
int V_14 , integer = 0 , V_67 = 0 , V_68 = 100000 ;
bool V_69 = true , V_70 = false ;
if ( ! V_3 -> V_29 -> V_71 )
return - V_36 ;
if ( V_3 -> V_29 -> V_72 )
switch ( V_3 -> V_29 -> V_72 ( V_3 ,
V_43 -> V_46 , V_43 -> V_47 ) ) {
case V_65 :
V_68 = 100000 ;
break;
case V_66 :
V_68 = 100000000 ;
break;
default:
return - V_36 ;
}
if ( V_13 [ 0 ] == '-' ) {
V_70 = true ;
V_13 ++ ;
}
while ( * V_13 ) {
if ( '0' <= * V_13 && * V_13 <= '9' ) {
if ( V_69 )
integer = integer * 10 + * V_13 - '0' ;
else {
V_67 += V_68 * ( * V_13 - '0' ) ;
if ( V_68 == 1 )
break;
V_68 /= 10 ;
}
} else if ( * V_13 == '\n' ) {
if ( * ( V_13 + 1 ) == '\0' )
break;
else
return - V_36 ;
} else if ( * V_13 == '.' ) {
V_69 = false ;
} else {
return - V_36 ;
}
V_13 ++ ;
}
if ( V_70 ) {
if ( integer )
integer = - integer ;
else
V_67 = - V_67 ;
}
V_14 = V_3 -> V_29 -> V_71 ( V_3 , V_43 -> V_46 ,
integer , V_67 , V_43 -> V_47 ) ;
if ( V_14 )
return V_14 ;
return V_28 ;
}
static
int F_36 ( struct V_11 * V_73 ,
const char * V_74 ,
struct V_1 const * V_52 ,
T_1 (* F_37)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_38)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 ) ,
bool V_75 )
{
int V_14 ;
char * V_76 , * V_77 ;
F_39 ( & V_73 -> V_12 ) ;
if ( V_52 -> V_78 && ! V_75 ) {
if ( V_52 -> V_79 )
V_77 = F_40 ( V_80 , L_19 ,
V_81 [ V_52
-> V_82 ] ,
V_52 -> V_79 ,
V_74 ) ;
else
V_77 = F_40 ( V_80 , L_20 ,
V_81 [ V_52
-> V_82 ] ,
V_74 ) ;
} else {
if ( V_52 -> V_79 == NULL )
V_77 = F_41 ( V_74 , V_80 ) ;
else
V_77 = F_40 ( V_80 ,
L_20 ,
V_52 -> V_79 ,
V_74 ) ;
}
if ( V_77 == NULL ) {
V_14 = - V_41 ;
goto V_83;
}
if ( V_52 -> V_84 ) {
if ( V_75 )
V_76
= F_40 ( V_80 , L_21 ,
V_85 [ V_52 -> V_86 ] ,
V_87 [ V_52 -> type ] ,
V_87 [ V_52 -> type ] ,
V_77 ) ;
else if ( V_52 -> V_88 )
V_76
= F_40 ( V_80 , L_22 ,
V_85 [ V_52 -> V_86 ] ,
V_87 [ V_52 -> type ] ,
V_52 -> V_89 ,
V_87 [ V_52 -> type ] ,
V_52 -> V_82 ,
V_77 ) ;
else {
F_42 ( L_23 ) ;
V_14 = - V_36 ;
goto V_90;
}
} else {
if ( V_75 )
V_76
= F_40 ( V_80 , L_19 ,
V_85 [ V_52 -> V_86 ] ,
V_87 [ V_52 -> type ] ,
V_77 ) ;
else if ( V_52 -> V_88 )
V_76
= F_40 ( V_80 , L_24 ,
V_85 [ V_52 -> V_86 ] ,
V_87 [ V_52 -> type ] ,
V_52 -> V_89 ,
V_77 ) ;
else
V_76
= F_40 ( V_80 , L_19 ,
V_85 [ V_52 -> V_86 ] ,
V_87 [ V_52 -> type ] ,
V_77 ) ;
}
if ( V_76 == NULL ) {
V_14 = - V_41 ;
goto V_90;
}
V_73 -> V_12 . V_91 = F_40 ( V_80 ,
V_76 ,
V_52 -> V_89 ,
V_52 -> V_82 ) ;
if ( V_73 -> V_12 . V_91 == NULL ) {
V_14 = - V_41 ;
goto V_92;
}
if ( F_37 ) {
V_73 -> V_12 . V_93 |= V_94 ;
V_73 -> V_95 = F_37 ;
}
if ( F_38 ) {
V_73 -> V_12 . V_93 |= V_96 ;
V_73 -> V_97 = F_38 ;
}
F_43 ( V_76 ) ;
F_43 ( V_77 ) ;
return 0 ;
V_92:
F_43 ( V_76 ) ;
V_90:
F_43 ( V_77 ) ;
V_83:
return V_14 ;
}
static void F_44 ( struct V_11 * V_73 )
{
F_43 ( V_73 -> V_12 . V_91 ) ;
}
int F_45 ( const char * V_74 ,
struct V_1 const * V_52 ,
T_1 (* F_37)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_38)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 ) ,
T_8 V_98 ,
bool V_75 ,
struct V_9 * V_10 ,
struct V_99 * V_100 )
{
int V_14 ;
struct V_42 * V_101 , * V_102 ;
V_101 = F_46 ( sizeof *V_101 , V_80 ) ;
if ( V_101 == NULL ) {
V_14 = - V_41 ;
goto V_83;
}
V_14 = F_36 ( & V_101 -> V_73 ,
V_74 , V_52 ,
F_37 , F_38 , V_75 ) ;
if ( V_14 )
goto V_103;
V_101 -> V_46 = V_52 ;
V_101 -> V_47 = V_98 ;
F_47 (t, attr_list, l)
if ( strcmp ( V_102 -> V_73 . V_12 . V_91 ,
V_101 -> V_73 . V_12 . V_91 ) == 0 ) {
if ( ! V_75 )
F_14 ( V_10 , L_25 ,
V_102 -> V_73 . V_12 . V_91 ) ;
V_14 = - V_104 ;
goto V_105;
}
F_48 ( & V_101 -> V_106 , V_100 ) ;
return 0 ;
V_105:
F_44 ( & V_101 -> V_73 ) ;
V_103:
F_43 ( V_101 ) ;
V_83:
return V_14 ;
}
static int F_49 ( struct V_2 * V_3 ,
struct V_1 const * V_52 )
{
int V_14 , V_107 = 0 ;
int V_5 ;
const struct V_44 * V_45 ;
if ( V_52 -> V_89 < 0 )
return 0 ;
F_50 (i, &chan->info_mask, sizeof(long)*8 ) {
V_14 = F_45 ( V_108 [ V_5 / 2 ] ,
V_52 ,
& F_34 ,
& F_35 ,
V_5 / 2 ,
! ( V_5 % 2 ) ,
& V_3 -> V_10 ,
& V_3 -> V_109 ) ;
if ( V_14 == - V_104 && ( V_5 % 2 == 0 ) ) {
V_14 = 0 ;
continue;
}
if ( V_14 < 0 )
goto V_83;
V_107 ++ ;
}
if ( V_52 -> V_45 ) {
unsigned int V_5 = 0 ;
for ( V_45 = V_52 -> V_45 ; V_45 -> V_91 ; V_45 ++ ) {
V_14 = F_45 ( V_45 -> V_91 ,
V_52 ,
V_45 -> V_48 ?
& F_25 : NULL ,
V_45 -> V_50 ?
& F_28 : NULL ,
V_5 ,
V_45 -> V_110 ,
& V_3 -> V_10 ,
& V_3 -> V_109 ) ;
V_5 ++ ;
if ( V_14 == - V_104 && V_45 -> V_110 )
continue;
if ( V_14 )
goto V_83;
V_107 ++ ;
}
}
V_14 = V_107 ;
V_83:
return V_14 ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_42 * V_111 )
{
F_43 ( V_111 -> V_73 . V_12 . V_91 ) ;
F_43 ( V_111 ) ;
}
static T_1 F_52 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_3 -> V_91 ) ;
}
static int F_53 ( struct V_2 * V_3 )
{
int V_5 , V_14 = 0 , V_107 , V_112 , V_113 = 0 ;
struct V_42 * V_111 , * V_114 ;
struct V_115 * * V_12 ;
if ( V_3 -> V_29 -> V_116 ) {
V_12 = V_3 -> V_29 -> V_116 -> V_116 ;
while ( * V_12 ++ != NULL )
V_113 ++ ;
}
V_107 = V_113 ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_14 = F_49 ( V_3 ,
& V_3
-> V_7 [ V_5 ] ) ;
if ( V_14 < 0 )
goto V_117;
V_107 += V_14 ;
}
if ( V_3 -> V_91 )
V_107 ++ ;
V_3 -> V_118 . V_116 = F_54 ( V_107 + 1 ,
sizeof( V_3 -> V_118 . V_116 [ 0 ] ) ,
V_80 ) ;
if ( V_3 -> V_118 . V_116 == NULL ) {
V_14 = - V_41 ;
goto V_117;
}
if ( V_3 -> V_29 -> V_116 )
memcpy ( V_3 -> V_118 . V_116 ,
V_3 -> V_29 -> V_116 -> V_116 ,
sizeof( V_3 -> V_118 . V_116 [ 0 ] )
* V_113 ) ;
V_112 = V_113 ;
F_47 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_118 . V_116 [ V_112 ++ ] = & V_111 -> V_73 . V_12 ;
if ( V_3 -> V_91 )
V_3 -> V_118 . V_116 [ V_112 ++ ] = & V_119 . V_12 ;
V_3 -> V_120 [ V_3 -> V_121 ++ ] =
& V_3 -> V_118 ;
return 0 ;
V_117:
F_55 (p, n,
&indio_dev->channel_attr_list, l) {
F_56 ( & V_111 -> V_106 ) ;
F_51 ( V_3 , V_111 ) ;
}
return V_14 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_42 * V_111 , * V_114 ;
F_55 (p, n, &indio_dev->channel_attr_list, l) {
F_56 ( & V_111 -> V_106 ) ;
F_51 ( V_3 , V_111 ) ;
}
F_43 ( V_3 -> V_118 . V_116 ) ;
}
static void F_58 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_26 ( V_9 ) ;
if ( V_3 -> V_122 . V_10 )
F_59 ( & V_3 -> V_122 ) ;
if ( V_3 -> V_123 & V_124 )
F_60 ( V_3 ) ;
F_61 ( V_3 ) ;
F_57 ( V_3 ) ;
F_19 ( V_3 ) ;
F_62 ( & V_125 , V_3 -> V_126 ) ;
F_43 ( V_3 ) ;
}
struct V_2 * F_63 ( int V_127 )
{
struct V_2 * V_10 ;
T_5 V_128 ;
V_128 = sizeof( struct V_2 ) ;
if ( V_127 ) {
V_128 = F_64 ( V_128 , V_129 ) ;
V_128 += V_127 ;
}
V_128 += V_129 - 1 ;
V_10 = F_46 ( V_128 , V_80 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_120 = V_10 -> V_120 ;
V_10 -> V_10 . type = & V_130 ;
V_10 -> V_10 . V_131 = & V_15 ;
F_65 ( & V_10 -> V_10 ) ;
F_66 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_67 ( & V_10 -> V_132 ) ;
F_67 ( & V_10 -> V_133 ) ;
F_68 ( & V_10 -> V_109 ) ;
V_10 -> V_126 = F_69 ( & V_125 , 0 , 0 , V_80 ) ;
if ( V_10 -> V_126 < 0 ) {
F_6 ( V_16 L_26 ) ;
F_43 ( V_10 ) ;
return NULL ;
}
F_70 ( & V_10 -> V_10 , L_27 , V_10 -> V_126 ) ;
}
return V_10 ;
}
void F_71 ( struct V_2 * V_10 )
{
if ( V_10 )
F_72 ( & V_10 -> V_10 ) ;
}
static int F_73 ( struct V_134 * V_134 , struct V_22 * V_135 )
{
struct V_2 * V_3 = F_74 ( V_134 -> V_136 ,
struct V_2 , V_122 ) ;
if ( F_75 ( V_137 , & V_3 -> V_138 ) )
return - V_104 ;
V_135 -> V_26 = V_3 ;
return 0 ;
}
static int F_76 ( struct V_134 * V_134 , struct V_22 * V_135 )
{
struct V_2 * V_3 = F_74 ( V_134 -> V_136 ,
struct V_2 , V_122 ) ;
F_77 ( V_137 , & V_3 -> V_138 ) ;
return 0 ;
}
static long F_78 ( struct V_22 * V_135 , unsigned int V_139 , unsigned long V_140 )
{
struct V_2 * V_3 = V_135 -> V_26 ;
int T_4 * V_141 = ( int T_4 * ) V_140 ;
int V_142 ;
if ( V_139 == V_143 ) {
V_142 = F_79 ( V_3 ) ;
if ( F_80 ( V_141 , & V_142 , sizeof( V_142 ) ) )
return - V_35 ;
return 0 ;
}
return - V_36 ;
}
int F_81 ( struct V_2 * V_3 )
{
int V_14 ;
V_3 -> V_10 . V_144 = F_82 ( F_83 ( V_18 ) , V_3 -> V_126 ) ;
V_14 = F_21 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_28 ) ;
goto V_83;
}
V_14 = F_53 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_29 ) ;
goto V_145;
}
V_14 = F_84 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_30 ) ;
goto V_146;
}
if ( V_3 -> V_123 & V_124 )
F_85 ( V_3 ) ;
if ( ( V_3 -> V_123 & V_147 ) &&
V_3 -> V_148 == NULL )
V_3 -> V_148 = & V_149 ;
V_14 = F_86 ( & V_3 -> V_10 ) ;
if ( V_14 < 0 )
goto V_150;
F_87 ( & V_3 -> V_122 , & V_151 ) ;
V_3 -> V_122 . V_152 = V_3 -> V_29 -> V_153 ;
V_14 = F_88 ( & V_3 -> V_122 , V_3 -> V_10 . V_144 , 1 ) ;
if ( V_14 < 0 )
goto V_154;
return 0 ;
V_154:
F_89 ( & V_3 -> V_10 ) ;
V_150:
F_61 ( V_3 ) ;
V_146:
F_57 ( V_3 ) ;
V_145:
F_19 ( V_3 ) ;
V_83:
return V_14 ;
}
void F_90 ( struct V_2 * V_3 )
{
F_91 ( & V_3 -> V_133 ) ;
V_3 -> V_29 = NULL ;
F_92 ( & V_3 -> V_133 ) ;
F_89 ( & V_3 -> V_10 ) ;
}
