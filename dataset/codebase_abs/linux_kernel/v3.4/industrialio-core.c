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
static int F_13 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
if ( V_22 -> V_24 )
V_23 -> V_25 = V_22 -> V_24 ;
return 0 ;
}
static T_1 F_14 ( struct V_23 * V_23 , char T_4 * V_26 ,
T_5 V_27 , T_6 * V_28 )
{
struct V_2 * V_3 = V_23 -> V_25 ;
char V_13 [ 20 ] ;
unsigned V_29 = 0 ;
T_1 V_30 ;
int V_14 ;
V_14 = V_3 -> V_31 -> V_32 ( V_3 ,
V_3 -> V_33 ,
0 , & V_29 ) ;
if ( V_14 )
F_15 ( V_3 -> V_10 . V_34 , L_5 , V_35 ) ;
V_30 = snprintf ( V_13 , sizeof( V_13 ) , L_6 , V_29 ) ;
return F_16 ( V_26 , V_27 , V_28 , V_13 , V_30 ) ;
}
static T_1 F_17 ( struct V_23 * V_23 ,
const char T_4 * V_26 , T_5 V_27 , T_6 * V_28 )
{
struct V_2 * V_3 = V_23 -> V_25 ;
unsigned V_36 , V_29 ;
char V_13 [ 80 ] ;
int V_14 ;
V_27 = F_18 ( T_5 , V_27 , ( sizeof( V_13 ) - 1 ) ) ;
if ( F_19 ( V_13 , V_26 , V_27 ) )
return - V_37 ;
V_13 [ V_27 ] = 0 ;
V_14 = sscanf ( V_13 , L_7 , & V_36 , & V_29 ) ;
switch ( V_14 ) {
case 1 :
V_3 -> V_33 = V_36 ;
break;
case 2 :
V_3 -> V_33 = V_36 ;
V_14 = V_3 -> V_31 -> V_32 ( V_3 , V_36 ,
V_29 , NULL ) ;
if ( V_14 ) {
F_15 ( V_3 -> V_10 . V_34 , L_8 ,
V_35 ) ;
return V_14 ;
}
break;
default:
return - V_38 ;
}
return V_27 ;
}
static void F_20 ( struct V_2 * V_3 )
{
F_21 ( V_3 -> V_39 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_40 * V_41 ;
if ( V_3 -> V_31 -> V_32 == NULL )
return 0 ;
if ( F_23 ( V_21 ) )
return 0 ;
V_3 -> V_39 =
F_8 ( F_24 ( & V_3 -> V_10 ) ,
V_21 ) ;
if ( F_23 ( V_3 -> V_39 ) )
return F_25 ( V_3 -> V_39 ) ;
if ( V_3 -> V_39 == NULL ) {
F_26 ( V_3 -> V_10 . V_34 ,
L_9 ) ;
return - V_37 ;
}
V_41 = F_27 ( L_10 , 0644 ,
V_3 -> V_39 ,
V_3 , & V_42 ) ;
if ( ! V_41 ) {
F_20 ( V_3 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_20 ( struct V_2 * V_3 )
{
}
static T_1 F_28 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_29 ( V_10 ) ;
struct V_44 * V_45 = F_30 ( V_12 ) ;
const struct V_46 * V_47 ;
V_47 = & V_45 -> V_48 -> V_47 [ V_45 -> V_49 ] ;
return V_47 -> V_50 ( V_3 , V_45 -> V_48 , V_13 ) ;
}
static T_1 F_31 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_30 )
{
struct V_2 * V_3 = F_29 ( V_10 ) ;
struct V_44 * V_45 = F_30 ( V_12 ) ;
const struct V_46 * V_47 ;
V_47 = & V_45 -> V_48 -> V_47 [ V_45 -> V_49 ] ;
return V_47 -> V_51 ( V_3 , V_45 -> V_48 , V_13 , V_30 ) ;
}
static T_1 F_32 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_29 ( V_10 ) ;
struct V_44 * V_45 = F_30 ( V_12 ) ;
int V_29 , V_52 ;
int V_14 = V_3 -> V_31 -> V_53 ( V_3 , V_45 -> V_48 ,
& V_29 , & V_52 , V_45 -> V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == V_54 )
return sprintf ( V_13 , L_11 , V_29 ) ;
else if ( V_14 == V_55 ) {
if ( V_52 < 0 )
return sprintf ( V_13 , L_12 , V_29 , - V_52 ) ;
else
return sprintf ( V_13 , L_13 , V_29 , V_52 ) ;
} else if ( V_14 == V_56 ) {
if ( V_52 < 0 )
return sprintf ( V_13 , L_14 , V_29 , - V_52 ) ;
else
return sprintf ( V_13 , L_15 , V_29 , V_52 ) ;
} else
return 0 ;
}
static T_1 F_33 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_30 )
{
struct V_2 * V_3 = F_29 ( V_10 ) ;
struct V_44 * V_45 = F_30 ( V_12 ) ;
int V_14 , integer = 0 , V_57 = 0 , V_58 = 100000 ;
bool V_59 = true , V_60 = false ;
if ( ! V_3 -> V_31 -> V_61 )
return - V_38 ;
if ( V_3 -> V_31 -> V_62 )
switch ( V_3 -> V_31 -> V_62 ( V_3 ,
V_45 -> V_48 , V_45 -> V_49 ) ) {
case V_55 :
V_58 = 100000 ;
break;
case V_56 :
V_58 = 100000000 ;
break;
default:
return - V_38 ;
}
if ( V_13 [ 0 ] == '-' ) {
V_60 = true ;
V_13 ++ ;
}
while ( * V_13 ) {
if ( '0' <= * V_13 && * V_13 <= '9' ) {
if ( V_59 )
integer = integer * 10 + * V_13 - '0' ;
else {
V_57 += V_58 * ( * V_13 - '0' ) ;
if ( V_58 == 1 )
break;
V_58 /= 10 ;
}
} else if ( * V_13 == '\n' ) {
if ( * ( V_13 + 1 ) == '\0' )
break;
else
return - V_38 ;
} else if ( * V_13 == '.' ) {
V_59 = false ;
} else {
return - V_38 ;
}
V_13 ++ ;
}
if ( V_60 ) {
if ( integer )
integer = - integer ;
else
V_57 = - V_57 ;
}
V_14 = V_3 -> V_31 -> V_61 ( V_3 , V_45 -> V_48 ,
integer , V_57 , V_45 -> V_49 ) ;
if ( V_14 )
return V_14 ;
return V_30 ;
}
static
int F_34 ( struct V_11 * V_63 ,
const char * V_64 ,
struct V_1 const * V_65 ,
T_1 (* F_35)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_36)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_30 ) ,
bool V_66 )
{
int V_14 ;
char * V_67 , * V_68 ;
F_37 ( & V_63 -> V_12 ) ;
if ( V_65 -> V_69 && ! V_66 ) {
if ( V_65 -> V_70 )
V_68 = F_38 ( V_71 , L_16 ,
V_72 [ V_65
-> V_73 ] ,
V_65 -> V_70 ,
V_64 ) ;
else
V_68 = F_38 ( V_71 , L_17 ,
V_72 [ V_65
-> V_73 ] ,
V_64 ) ;
} else {
if ( V_65 -> V_70 == NULL )
V_68 = F_39 ( V_64 , V_71 ) ;
else
V_68 = F_38 ( V_71 ,
L_17 ,
V_65 -> V_70 ,
V_64 ) ;
}
if ( V_68 == NULL ) {
V_14 = - V_43 ;
goto V_74;
}
if ( V_65 -> V_75 ) {
if ( V_66 )
V_67
= F_38 ( V_71 , L_18 ,
V_76 [ V_65 -> V_77 ] ,
V_78 [ V_65 -> type ] ,
V_78 [ V_65 -> type ] ,
V_68 ) ;
else if ( V_65 -> V_79 )
V_67
= F_38 ( V_71 , L_19 ,
V_76 [ V_65 -> V_77 ] ,
V_78 [ V_65 -> type ] ,
V_65 -> V_80 ,
V_78 [ V_65 -> type ] ,
V_65 -> V_73 ,
V_68 ) ;
else {
F_40 ( L_20 ) ;
V_14 = - V_38 ;
goto V_81;
}
} else {
if ( V_66 )
V_67
= F_38 ( V_71 , L_16 ,
V_76 [ V_65 -> V_77 ] ,
V_78 [ V_65 -> type ] ,
V_68 ) ;
else if ( V_65 -> V_79 )
V_67
= F_38 ( V_71 , L_21 ,
V_76 [ V_65 -> V_77 ] ,
V_78 [ V_65 -> type ] ,
V_65 -> V_80 ,
V_68 ) ;
else
V_67
= F_38 ( V_71 , L_16 ,
V_76 [ V_65 -> V_77 ] ,
V_78 [ V_65 -> type ] ,
V_68 ) ;
}
if ( V_67 == NULL ) {
V_14 = - V_43 ;
goto V_81;
}
V_63 -> V_12 . V_82 = F_38 ( V_71 ,
V_67 ,
V_65 -> V_80 ,
V_65 -> V_73 ) ;
if ( V_63 -> V_12 . V_82 == NULL ) {
V_14 = - V_43 ;
goto V_83;
}
if ( F_35 ) {
V_63 -> V_12 . V_84 |= V_85 ;
V_63 -> V_86 = F_35 ;
}
if ( F_36 ) {
V_63 -> V_12 . V_84 |= V_87 ;
V_63 -> V_88 = F_36 ;
}
F_41 ( V_67 ) ;
F_41 ( V_68 ) ;
return 0 ;
V_83:
F_41 ( V_67 ) ;
V_81:
F_41 ( V_68 ) ;
V_74:
return V_14 ;
}
static void F_42 ( struct V_11 * V_63 )
{
F_41 ( V_63 -> V_12 . V_82 ) ;
}
int F_43 ( const char * V_64 ,
struct V_1 const * V_65 ,
T_1 (* F_35)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_36)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_30 ) ,
T_7 V_89 ,
bool V_66 ,
struct V_9 * V_10 ,
struct V_90 * V_91 )
{
int V_14 ;
struct V_44 * V_92 , * V_93 ;
V_92 = F_44 ( sizeof *V_92 , V_71 ) ;
if ( V_92 == NULL ) {
V_14 = - V_43 ;
goto V_74;
}
V_14 = F_34 ( & V_92 -> V_63 ,
V_64 , V_65 ,
F_35 , F_36 , V_66 ) ;
if ( V_14 )
goto V_94;
V_92 -> V_48 = V_65 ;
V_92 -> V_49 = V_89 ;
F_45 (t, attr_list, l)
if ( strcmp ( V_93 -> V_63 . V_12 . V_82 ,
V_92 -> V_63 . V_12 . V_82 ) == 0 ) {
if ( ! V_66 )
F_15 ( V_10 , L_22 ,
V_93 -> V_63 . V_12 . V_82 ) ;
V_14 = - V_95 ;
goto V_96;
}
F_46 ( & V_92 -> V_97 , V_91 ) ;
return 0 ;
V_96:
F_42 ( & V_92 -> V_63 ) ;
V_94:
F_41 ( V_92 ) ;
V_74:
return V_14 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_1 const * V_65 )
{
int V_14 , V_5 , V_98 = 0 ;
const struct V_46 * V_47 ;
if ( V_65 -> V_80 < 0 )
return 0 ;
V_14 = F_43 ( V_99 [ V_65 -> V_100 ] ,
V_65 ,
& F_32 ,
( V_65 -> V_77 ?
& F_33 : NULL ) ,
0 ,
0 ,
& V_3 -> V_10 ,
& V_3 -> V_101 ) ;
if ( V_14 )
goto V_74;
V_98 ++ ;
F_48 (i, &chan->info_mask, sizeof(long)*8 ) {
V_14 = F_43 ( V_102 [ V_5 / 2 ] ,
V_65 ,
& F_32 ,
& F_33 ,
V_5 / 2 ,
! ( V_5 % 2 ) ,
& V_3 -> V_10 ,
& V_3 -> V_101 ) ;
if ( V_14 == - V_95 && ( V_5 % 2 == 0 ) ) {
V_14 = 0 ;
continue;
}
if ( V_14 < 0 )
goto V_74;
V_98 ++ ;
}
if ( V_65 -> V_47 ) {
unsigned int V_5 = 0 ;
for ( V_47 = V_65 -> V_47 ; V_47 -> V_82 ; V_47 ++ ) {
V_14 = F_43 ( V_47 -> V_82 ,
V_65 ,
V_47 -> V_50 ?
& F_28 : NULL ,
V_47 -> V_51 ?
& F_31 : NULL ,
V_5 ,
V_47 -> V_103 ,
& V_3 -> V_10 ,
& V_3 -> V_101 ) ;
V_5 ++ ;
if ( V_14 == - V_95 && V_47 -> V_103 )
continue;
if ( V_14 )
goto V_74;
V_98 ++ ;
}
}
V_14 = V_98 ;
V_74:
return V_14 ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_44 * V_104 )
{
F_41 ( V_104 -> V_63 . V_12 . V_82 ) ;
F_41 ( V_104 ) ;
}
static T_1 F_50 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_29 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_3 -> V_82 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
int V_5 , V_14 = 0 , V_98 , V_105 , V_106 = 0 ;
struct V_44 * V_104 , * V_107 ;
struct V_108 * * V_12 ;
if ( V_3 -> V_31 -> V_109 ) {
V_12 = V_3 -> V_31 -> V_109 -> V_109 ;
while ( * V_12 ++ != NULL )
V_106 ++ ;
}
V_98 = V_106 ;
F_52 ( & V_3 -> V_101 ) ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_14 = F_47 ( V_3 ,
& V_3
-> V_7 [ V_5 ] ) ;
if ( V_14 < 0 )
goto V_110;
V_98 += V_14 ;
}
if ( V_3 -> V_82 )
V_98 ++ ;
V_3 -> V_111 . V_109 = F_53 ( V_98 + 1 ,
sizeof( V_3 -> V_111 . V_109 [ 0 ] ) ,
V_71 ) ;
if ( V_3 -> V_111 . V_109 == NULL ) {
V_14 = - V_43 ;
goto V_110;
}
if ( V_3 -> V_31 -> V_109 )
memcpy ( V_3 -> V_111 . V_109 ,
V_3 -> V_31 -> V_109 -> V_109 ,
sizeof( V_3 -> V_111 . V_109 [ 0 ] )
* V_106 ) ;
V_105 = V_106 ;
F_45 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_111 . V_109 [ V_105 ++ ] = & V_104 -> V_63 . V_12 ;
if ( V_3 -> V_82 )
V_3 -> V_111 . V_109 [ V_105 ++ ] = & V_112 . V_12 ;
V_3 -> V_113 [ V_3 -> V_114 ++ ] =
& V_3 -> V_111 ;
return 0 ;
V_110:
F_54 (p, n,
&indio_dev->channel_attr_list, l) {
F_55 ( & V_104 -> V_97 ) ;
F_49 ( V_3 , V_104 ) ;
}
return V_14 ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_44 * V_104 , * V_107 ;
F_54 (p, n, &indio_dev->channel_attr_list, l) {
F_55 ( & V_104 -> V_97 ) ;
F_49 ( V_3 , V_104 ) ;
}
F_41 ( V_3 -> V_111 . V_109 ) ;
}
static void F_57 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_58 ( V_9 , struct V_2 , V_10 ) ;
F_59 ( & V_3 -> V_115 ) ;
if ( V_3 -> V_116 & V_117 )
F_60 ( V_3 ) ;
F_61 ( V_3 ) ;
F_56 ( V_3 ) ;
F_20 ( V_3 ) ;
}
struct V_2 * F_62 ( int V_118 )
{
struct V_2 * V_10 ;
T_5 V_119 ;
V_119 = sizeof( struct V_2 ) ;
if ( V_118 ) {
V_119 = F_63 ( V_119 , V_120 ) ;
V_119 += V_118 ;
}
V_119 += V_120 - 1 ;
V_10 = F_44 ( V_119 , V_71 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_113 = V_10 -> V_113 ;
V_10 -> V_10 . type = & V_121 ;
V_10 -> V_10 . V_122 = & V_15 ;
F_64 ( & V_10 -> V_10 ) ;
F_65 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_66 ( & V_10 -> V_123 ) ;
F_66 ( & V_10 -> V_124 ) ;
V_10 -> V_125 = F_67 ( & V_126 , 0 , 0 , V_71 ) ;
if ( V_10 -> V_125 < 0 ) {
F_6 ( V_16 L_23 ) ;
F_41 ( V_10 ) ;
return NULL ;
}
F_68 ( & V_10 -> V_10 , L_24 , V_10 -> V_125 ) ;
}
return V_10 ;
}
void F_69 ( struct V_2 * V_10 )
{
if ( V_10 ) {
F_70 ( & V_126 , V_10 -> V_125 ) ;
F_41 ( V_10 ) ;
}
}
static int F_71 ( struct V_22 * V_22 , struct V_23 * V_127 )
{
struct V_2 * V_3 = F_58 ( V_22 -> V_128 ,
struct V_2 , V_115 ) ;
if ( F_72 ( V_129 , & V_3 -> V_130 ) )
return - V_95 ;
V_127 -> V_25 = V_3 ;
return 0 ;
}
static int F_73 ( struct V_22 * V_22 , struct V_23 * V_127 )
{
struct V_2 * V_3 = F_58 ( V_22 -> V_128 ,
struct V_2 , V_115 ) ;
F_74 ( V_129 , & V_3 -> V_130 ) ;
return 0 ;
}
static long F_75 ( struct V_23 * V_127 , unsigned int V_131 , unsigned long V_132 )
{
struct V_2 * V_3 = V_127 -> V_25 ;
int T_4 * V_133 = ( int T_4 * ) V_132 ;
int V_134 ;
if ( V_131 == V_135 ) {
V_134 = F_76 ( V_3 ) ;
if ( F_77 ( V_133 , & V_134 , sizeof( V_134 ) ) )
return - V_37 ;
return 0 ;
}
return - V_38 ;
}
int F_78 ( struct V_2 * V_3 )
{
int V_14 ;
V_3 -> V_10 . V_136 = F_79 ( F_80 ( V_18 ) , V_3 -> V_125 ) ;
V_14 = F_22 ( V_3 ) ;
if ( V_14 ) {
F_15 ( V_3 -> V_10 . V_34 ,
L_25 ) ;
goto V_74;
}
V_14 = F_51 ( V_3 ) ;
if ( V_14 ) {
F_15 ( V_3 -> V_10 . V_34 ,
L_26 ) ;
goto V_137;
}
V_14 = F_81 ( V_3 ) ;
if ( V_14 ) {
F_15 ( V_3 -> V_10 . V_34 ,
L_27 ) ;
goto V_138;
}
if ( V_3 -> V_116 & V_117 )
F_82 ( V_3 ) ;
if ( ( V_3 -> V_116 & V_139 ) &&
V_3 -> V_140 == NULL )
V_3 -> V_140 = & V_141 ;
V_14 = F_83 ( & V_3 -> V_10 ) ;
if ( V_14 < 0 )
goto V_142;
F_84 ( & V_3 -> V_115 , & V_143 ) ;
V_3 -> V_115 . V_144 = V_3 -> V_31 -> V_145 ;
V_14 = F_85 ( & V_3 -> V_115 , V_3 -> V_10 . V_136 , 1 ) ;
if ( V_14 < 0 )
goto V_146;
return 0 ;
V_146:
F_86 ( & V_3 -> V_10 ) ;
V_142:
F_61 ( V_3 ) ;
V_138:
F_56 ( V_3 ) ;
V_137:
F_20 ( V_3 ) ;
V_74:
return V_14 ;
}
void F_87 ( struct V_2 * V_3 )
{
F_88 ( & V_3 -> V_124 ) ;
V_3 -> V_31 = NULL ;
F_89 ( & V_3 -> V_124 ) ;
F_90 ( & V_3 -> V_10 ) ;
}
