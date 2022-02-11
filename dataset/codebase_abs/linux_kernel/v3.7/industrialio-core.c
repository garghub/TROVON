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
unsigned long long V_60 ;
int V_27 , V_61 ;
bool V_62 = false ;
int V_14 = V_3 -> V_29 -> V_63 ( V_3 , V_43 -> V_46 ,
& V_27 , & V_61 , V_43 -> V_47 ) ;
if ( V_14 < 0 )
return V_14 ;
switch ( V_14 ) {
case V_64 :
return sprintf ( V_13 , L_12 , V_27 ) ;
case V_65 :
V_62 = true ;
case V_66 :
if ( V_61 < 0 )
return sprintf ( V_13 , L_13 , V_27 , - V_61 ,
V_62 ? L_14 : L_15 ) ;
else
return sprintf ( V_13 , L_16 , V_27 , V_61 ,
V_62 ? L_14 : L_15 ) ;
case V_67 :
if ( V_61 < 0 )
return sprintf ( V_13 , L_17 , V_27 , - V_61 ) ;
else
return sprintf ( V_13 , L_18 , V_27 , V_61 ) ;
case V_68 :
V_60 = F_35 ( ( V_69 ) V_27 * 1000000000LL , V_61 ) ;
V_61 = F_36 ( V_60 , 1000000000LL ) ;
V_27 = V_60 ;
return sprintf ( V_13 , L_18 , V_27 , V_61 ) ;
default:
return 0 ;
}
}
static T_1 F_37 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_42 * V_43 = F_27 ( V_12 ) ;
int V_14 , integer = 0 , V_70 = 0 , V_71 = 100000 ;
bool V_72 = true , V_73 = false ;
if ( ! V_3 -> V_29 -> V_74 )
return - V_36 ;
if ( V_3 -> V_29 -> V_75 )
switch ( V_3 -> V_29 -> V_75 ( V_3 ,
V_43 -> V_46 , V_43 -> V_47 ) ) {
case V_66 :
V_71 = 100000 ;
break;
case V_67 :
V_71 = 100000000 ;
break;
default:
return - V_36 ;
}
if ( V_13 [ 0 ] == '-' ) {
V_73 = true ;
V_13 ++ ;
}
while ( * V_13 ) {
if ( '0' <= * V_13 && * V_13 <= '9' ) {
if ( V_72 )
integer = integer * 10 + * V_13 - '0' ;
else {
V_70 += V_71 * ( * V_13 - '0' ) ;
if ( V_71 == 1 )
break;
V_71 /= 10 ;
}
} else if ( * V_13 == '\n' ) {
if ( * ( V_13 + 1 ) == '\0' )
break;
else
return - V_36 ;
} else if ( * V_13 == '.' ) {
V_72 = false ;
} else {
return - V_36 ;
}
V_13 ++ ;
}
if ( V_73 ) {
if ( integer )
integer = - integer ;
else
V_70 = - V_70 ;
}
V_14 = V_3 -> V_29 -> V_74 ( V_3 , V_43 -> V_46 ,
integer , V_70 , V_43 -> V_47 ) ;
if ( V_14 )
return V_14 ;
return V_28 ;
}
static
int F_38 ( struct V_11 * V_76 ,
const char * V_77 ,
struct V_1 const * V_52 ,
T_1 (* F_39)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_40)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 ) ,
bool V_78 )
{
int V_14 ;
char * V_79 , * V_80 ;
F_41 ( & V_76 -> V_12 ) ;
if ( V_52 -> V_81 && ! V_78 ) {
if ( V_52 -> V_82 )
V_80 = F_42 ( V_83 , L_19 ,
V_84 [ V_52
-> V_85 ] ,
V_52 -> V_82 ,
V_77 ) ;
else
V_80 = F_42 ( V_83 , L_20 ,
V_84 [ V_52
-> V_85 ] ,
V_77 ) ;
} else {
if ( V_52 -> V_82 == NULL )
V_80 = F_43 ( V_77 , V_83 ) ;
else
V_80 = F_42 ( V_83 ,
L_20 ,
V_52 -> V_82 ,
V_77 ) ;
}
if ( V_80 == NULL ) {
V_14 = - V_41 ;
goto V_86;
}
if ( V_52 -> V_87 ) {
if ( V_78 )
V_79
= F_42 ( V_83 , L_21 ,
V_88 [ V_52 -> V_89 ] ,
V_90 [ V_52 -> type ] ,
V_90 [ V_52 -> type ] ,
V_80 ) ;
else if ( V_52 -> V_91 )
V_79
= F_42 ( V_83 , L_22 ,
V_88 [ V_52 -> V_89 ] ,
V_90 [ V_52 -> type ] ,
V_52 -> V_92 ,
V_90 [ V_52 -> type ] ,
V_52 -> V_85 ,
V_80 ) ;
else {
F_44 ( L_23 ) ;
V_14 = - V_36 ;
goto V_93;
}
} else {
if ( V_78 )
V_79
= F_42 ( V_83 , L_19 ,
V_88 [ V_52 -> V_89 ] ,
V_90 [ V_52 -> type ] ,
V_80 ) ;
else if ( V_52 -> V_91 )
V_79
= F_42 ( V_83 , L_24 ,
V_88 [ V_52 -> V_89 ] ,
V_90 [ V_52 -> type ] ,
V_52 -> V_92 ,
V_80 ) ;
else
V_79
= F_42 ( V_83 , L_19 ,
V_88 [ V_52 -> V_89 ] ,
V_90 [ V_52 -> type ] ,
V_80 ) ;
}
if ( V_79 == NULL ) {
V_14 = - V_41 ;
goto V_93;
}
V_76 -> V_12 . V_94 = F_42 ( V_83 ,
V_79 ,
V_52 -> V_92 ,
V_52 -> V_85 ) ;
if ( V_76 -> V_12 . V_94 == NULL ) {
V_14 = - V_41 ;
goto V_95;
}
if ( F_39 ) {
V_76 -> V_12 . V_96 |= V_97 ;
V_76 -> V_98 = F_39 ;
}
if ( F_40 ) {
V_76 -> V_12 . V_96 |= V_99 ;
V_76 -> V_100 = F_40 ;
}
F_45 ( V_79 ) ;
F_45 ( V_80 ) ;
return 0 ;
V_95:
F_45 ( V_79 ) ;
V_93:
F_45 ( V_80 ) ;
V_86:
return V_14 ;
}
static void F_46 ( struct V_11 * V_76 )
{
F_45 ( V_76 -> V_12 . V_94 ) ;
}
int F_47 ( const char * V_77 ,
struct V_1 const * V_52 ,
T_1 (* F_39)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_40)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 ) ,
T_8 V_101 ,
bool V_78 ,
struct V_9 * V_10 ,
struct V_102 * V_103 )
{
int V_14 ;
struct V_42 * V_104 , * V_105 ;
V_104 = F_48 ( sizeof *V_104 , V_83 ) ;
if ( V_104 == NULL ) {
V_14 = - V_41 ;
goto V_86;
}
V_14 = F_38 ( & V_104 -> V_76 ,
V_77 , V_52 ,
F_39 , F_40 , V_78 ) ;
if ( V_14 )
goto V_106;
V_104 -> V_46 = V_52 ;
V_104 -> V_47 = V_101 ;
F_49 (t, attr_list, l)
if ( strcmp ( V_105 -> V_76 . V_12 . V_94 ,
V_104 -> V_76 . V_12 . V_94 ) == 0 ) {
if ( ! V_78 )
F_14 ( V_10 , L_25 ,
V_105 -> V_76 . V_12 . V_94 ) ;
V_14 = - V_107 ;
goto V_108;
}
F_50 ( & V_104 -> V_109 , V_103 ) ;
return 0 ;
V_108:
F_46 ( & V_104 -> V_76 ) ;
V_106:
F_45 ( V_104 ) ;
V_86:
return V_14 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_1 const * V_52 )
{
int V_14 , V_110 = 0 ;
int V_5 ;
const struct V_44 * V_45 ;
if ( V_52 -> V_92 < 0 )
return 0 ;
F_52 (i, &chan->info_mask, sizeof(long)*8 ) {
V_14 = F_47 ( V_111 [ V_5 / 2 ] ,
V_52 ,
& F_34 ,
& F_37 ,
V_5 / 2 ,
! ( V_5 % 2 ) ,
& V_3 -> V_10 ,
& V_3 -> V_112 ) ;
if ( V_14 == - V_107 && ( V_5 % 2 == 0 ) ) {
V_14 = 0 ;
continue;
}
if ( V_14 < 0 )
goto V_86;
V_110 ++ ;
}
if ( V_52 -> V_45 ) {
unsigned int V_5 = 0 ;
for ( V_45 = V_52 -> V_45 ; V_45 -> V_94 ; V_45 ++ ) {
V_14 = F_47 ( V_45 -> V_94 ,
V_52 ,
V_45 -> V_48 ?
& F_25 : NULL ,
V_45 -> V_50 ?
& F_28 : NULL ,
V_5 ,
V_45 -> V_113 ,
& V_3 -> V_10 ,
& V_3 -> V_112 ) ;
V_5 ++ ;
if ( V_14 == - V_107 && V_45 -> V_113 )
continue;
if ( V_14 )
goto V_86;
V_110 ++ ;
}
}
V_14 = V_110 ;
V_86:
return V_14 ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_42 * V_114 )
{
F_45 ( V_114 -> V_76 . V_12 . V_94 ) ;
F_45 ( V_114 ) ;
}
static T_1 F_54 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_3 -> V_94 ) ;
}
static int F_55 ( struct V_2 * V_3 )
{
int V_5 , V_14 = 0 , V_110 , V_115 , V_116 = 0 ;
struct V_42 * V_114 , * V_117 ;
struct V_118 * * V_12 ;
if ( V_3 -> V_29 -> V_119 ) {
V_12 = V_3 -> V_29 -> V_119 -> V_119 ;
while ( * V_12 ++ != NULL )
V_116 ++ ;
}
V_110 = V_116 ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_14 = F_51 ( V_3 ,
& V_3
-> V_7 [ V_5 ] ) ;
if ( V_14 < 0 )
goto V_120;
V_110 += V_14 ;
}
if ( V_3 -> V_94 )
V_110 ++ ;
V_3 -> V_121 . V_119 = F_56 ( V_110 + 1 ,
sizeof( V_3 -> V_121 . V_119 [ 0 ] ) ,
V_83 ) ;
if ( V_3 -> V_121 . V_119 == NULL ) {
V_14 = - V_41 ;
goto V_120;
}
if ( V_3 -> V_29 -> V_119 )
memcpy ( V_3 -> V_121 . V_119 ,
V_3 -> V_29 -> V_119 -> V_119 ,
sizeof( V_3 -> V_121 . V_119 [ 0 ] )
* V_116 ) ;
V_115 = V_116 ;
F_49 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_121 . V_119 [ V_115 ++ ] = & V_114 -> V_76 . V_12 ;
if ( V_3 -> V_94 )
V_3 -> V_121 . V_119 [ V_115 ++ ] = & V_122 . V_12 ;
V_3 -> V_123 [ V_3 -> V_124 ++ ] =
& V_3 -> V_121 ;
return 0 ;
V_120:
F_57 (p, n,
&indio_dev->channel_attr_list, l) {
F_58 ( & V_114 -> V_109 ) ;
F_53 ( V_3 , V_114 ) ;
}
return V_14 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_42 * V_114 , * V_117 ;
F_57 (p, n, &indio_dev->channel_attr_list, l) {
F_58 ( & V_114 -> V_109 ) ;
F_53 ( V_3 , V_114 ) ;
}
F_45 ( V_3 -> V_121 . V_119 ) ;
}
static void F_60 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_26 ( V_9 ) ;
if ( V_3 -> V_125 . V_10 )
F_61 ( & V_3 -> V_125 ) ;
if ( V_3 -> V_126 & V_127 )
F_62 ( V_3 ) ;
F_63 ( V_3 ) ;
F_59 ( V_3 ) ;
F_19 ( V_3 ) ;
F_64 ( & V_128 , V_3 -> V_129 ) ;
F_45 ( V_3 ) ;
}
struct V_2 * F_65 ( int V_130 )
{
struct V_2 * V_10 ;
T_5 V_131 ;
V_131 = sizeof( struct V_2 ) ;
if ( V_130 ) {
V_131 = F_66 ( V_131 , V_132 ) ;
V_131 += V_130 ;
}
V_131 += V_132 - 1 ;
V_10 = F_48 ( V_131 , V_83 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_123 = V_10 -> V_123 ;
V_10 -> V_10 . type = & V_133 ;
V_10 -> V_10 . V_134 = & V_15 ;
F_67 ( & V_10 -> V_10 ) ;
F_68 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_69 ( & V_10 -> V_135 ) ;
F_69 ( & V_10 -> V_136 ) ;
F_70 ( & V_10 -> V_112 ) ;
V_10 -> V_129 = F_71 ( & V_128 , 0 , 0 , V_83 ) ;
if ( V_10 -> V_129 < 0 ) {
F_6 ( V_16 L_26 ) ;
F_45 ( V_10 ) ;
return NULL ;
}
F_72 ( & V_10 -> V_10 , L_27 , V_10 -> V_129 ) ;
}
return V_10 ;
}
void F_73 ( struct V_2 * V_10 )
{
if ( V_10 )
F_74 ( & V_10 -> V_10 ) ;
}
static int F_75 ( struct V_137 * V_137 , struct V_22 * V_138 )
{
struct V_2 * V_3 = F_76 ( V_137 -> V_139 ,
struct V_2 , V_125 ) ;
if ( F_77 ( V_140 , & V_3 -> V_141 ) )
return - V_107 ;
V_138 -> V_26 = V_3 ;
return 0 ;
}
static int F_78 ( struct V_137 * V_137 , struct V_22 * V_138 )
{
struct V_2 * V_3 = F_76 ( V_137 -> V_139 ,
struct V_2 , V_125 ) ;
F_79 ( V_140 , & V_3 -> V_141 ) ;
return 0 ;
}
static long F_80 ( struct V_22 * V_138 , unsigned int V_142 , unsigned long V_143 )
{
struct V_2 * V_3 = V_138 -> V_26 ;
int T_4 * V_144 = ( int T_4 * ) V_143 ;
int V_145 ;
if ( V_142 == V_146 ) {
V_145 = F_81 ( V_3 ) ;
if ( F_82 ( V_144 , & V_145 , sizeof( V_145 ) ) )
return - V_35 ;
return 0 ;
}
return - V_36 ;
}
int F_83 ( struct V_2 * V_3 )
{
int V_14 ;
V_3 -> V_10 . V_147 = F_84 ( F_85 ( V_18 ) , V_3 -> V_129 ) ;
V_14 = F_21 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_28 ) ;
goto V_86;
}
V_14 = F_55 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_29 ) ;
goto V_148;
}
V_14 = F_86 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_30 ) ;
goto V_149;
}
if ( V_3 -> V_126 & V_127 )
F_87 ( V_3 ) ;
if ( ( V_3 -> V_126 & V_150 ) &&
V_3 -> V_151 == NULL )
V_3 -> V_151 = & V_152 ;
V_14 = F_88 ( & V_3 -> V_10 ) ;
if ( V_14 < 0 )
goto V_153;
F_89 ( & V_3 -> V_125 , & V_154 ) ;
V_3 -> V_125 . V_155 = V_3 -> V_29 -> V_156 ;
V_14 = F_90 ( & V_3 -> V_125 , V_3 -> V_10 . V_147 , 1 ) ;
if ( V_14 < 0 )
goto V_157;
return 0 ;
V_157:
F_91 ( & V_3 -> V_10 ) ;
V_153:
F_63 ( V_3 ) ;
V_149:
F_59 ( V_3 ) ;
V_148:
F_19 ( V_3 ) ;
V_86:
return V_14 ;
}
void F_92 ( struct V_2 * V_3 )
{
F_93 ( & V_3 -> V_136 ) ;
V_3 -> V_29 = NULL ;
F_94 ( & V_3 -> V_136 ) ;
F_91 ( & V_3 -> V_10 ) ;
}
