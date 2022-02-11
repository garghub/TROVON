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
static T_1 F_29 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_42 * V_43 = F_27 ( V_12 ) ;
int V_27 , V_51 ;
bool V_52 = false ;
int V_14 = V_3 -> V_29 -> V_53 ( V_3 , V_43 -> V_46 ,
& V_27 , & V_51 , V_43 -> V_47 ) ;
if ( V_14 < 0 )
return V_14 ;
switch ( V_14 ) {
case V_54 :
return sprintf ( V_13 , L_11 , V_27 ) ;
case V_55 :
V_52 = true ;
case V_56 :
if ( V_51 < 0 )
return sprintf ( V_13 , L_12 , V_27 , - V_51 ,
V_52 ? L_13 : L_14 ) ;
else
return sprintf ( V_13 , L_15 , V_27 , V_51 ,
V_52 ? L_13 : L_14 ) ;
case V_57 :
if ( V_51 < 0 )
return sprintf ( V_13 , L_16 , V_27 , - V_51 ) ;
else
return sprintf ( V_13 , L_17 , V_27 , V_51 ) ;
default:
return 0 ;
}
}
static T_1 F_30 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_42 * V_43 = F_27 ( V_12 ) ;
int V_14 , integer = 0 , V_58 = 0 , V_59 = 100000 ;
bool V_60 = true , V_61 = false ;
if ( ! V_3 -> V_29 -> V_62 )
return - V_36 ;
if ( V_3 -> V_29 -> V_63 )
switch ( V_3 -> V_29 -> V_63 ( V_3 ,
V_43 -> V_46 , V_43 -> V_47 ) ) {
case V_56 :
V_59 = 100000 ;
break;
case V_57 :
V_59 = 100000000 ;
break;
default:
return - V_36 ;
}
if ( V_13 [ 0 ] == '-' ) {
V_61 = true ;
V_13 ++ ;
}
while ( * V_13 ) {
if ( '0' <= * V_13 && * V_13 <= '9' ) {
if ( V_60 )
integer = integer * 10 + * V_13 - '0' ;
else {
V_58 += V_59 * ( * V_13 - '0' ) ;
if ( V_59 == 1 )
break;
V_59 /= 10 ;
}
} else if ( * V_13 == '\n' ) {
if ( * ( V_13 + 1 ) == '\0' )
break;
else
return - V_36 ;
} else if ( * V_13 == '.' ) {
V_60 = false ;
} else {
return - V_36 ;
}
V_13 ++ ;
}
if ( V_61 ) {
if ( integer )
integer = - integer ;
else
V_58 = - V_58 ;
}
V_14 = V_3 -> V_29 -> V_62 ( V_3 , V_43 -> V_46 ,
integer , V_58 , V_43 -> V_47 ) ;
if ( V_14 )
return V_14 ;
return V_28 ;
}
static
int F_31 ( struct V_11 * V_64 ,
const char * V_65 ,
struct V_1 const * V_66 ,
T_1 (* F_32)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_33)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 ) ,
bool V_67 )
{
int V_14 ;
char * V_68 , * V_69 ;
F_34 ( & V_64 -> V_12 ) ;
if ( V_66 -> V_70 && ! V_67 ) {
if ( V_66 -> V_71 )
V_69 = F_35 ( V_72 , L_18 ,
V_73 [ V_66
-> V_74 ] ,
V_66 -> V_71 ,
V_65 ) ;
else
V_69 = F_35 ( V_72 , L_19 ,
V_73 [ V_66
-> V_74 ] ,
V_65 ) ;
} else {
if ( V_66 -> V_71 == NULL )
V_69 = F_36 ( V_65 , V_72 ) ;
else
V_69 = F_35 ( V_72 ,
L_19 ,
V_66 -> V_71 ,
V_65 ) ;
}
if ( V_69 == NULL ) {
V_14 = - V_41 ;
goto V_75;
}
if ( V_66 -> V_76 ) {
if ( V_67 )
V_68
= F_35 ( V_72 , L_20 ,
V_77 [ V_66 -> V_78 ] ,
V_79 [ V_66 -> type ] ,
V_79 [ V_66 -> type ] ,
V_69 ) ;
else if ( V_66 -> V_80 )
V_68
= F_35 ( V_72 , L_21 ,
V_77 [ V_66 -> V_78 ] ,
V_79 [ V_66 -> type ] ,
V_66 -> V_81 ,
V_79 [ V_66 -> type ] ,
V_66 -> V_74 ,
V_69 ) ;
else {
F_37 ( L_22 ) ;
V_14 = - V_36 ;
goto V_82;
}
} else {
if ( V_67 )
V_68
= F_35 ( V_72 , L_18 ,
V_77 [ V_66 -> V_78 ] ,
V_79 [ V_66 -> type ] ,
V_69 ) ;
else if ( V_66 -> V_80 )
V_68
= F_35 ( V_72 , L_23 ,
V_77 [ V_66 -> V_78 ] ,
V_79 [ V_66 -> type ] ,
V_66 -> V_81 ,
V_69 ) ;
else
V_68
= F_35 ( V_72 , L_18 ,
V_77 [ V_66 -> V_78 ] ,
V_79 [ V_66 -> type ] ,
V_69 ) ;
}
if ( V_68 == NULL ) {
V_14 = - V_41 ;
goto V_82;
}
V_64 -> V_12 . V_83 = F_35 ( V_72 ,
V_68 ,
V_66 -> V_81 ,
V_66 -> V_74 ) ;
if ( V_64 -> V_12 . V_83 == NULL ) {
V_14 = - V_41 ;
goto V_84;
}
if ( F_32 ) {
V_64 -> V_12 . V_85 |= V_86 ;
V_64 -> V_87 = F_32 ;
}
if ( F_33 ) {
V_64 -> V_12 . V_85 |= V_88 ;
V_64 -> V_89 = F_33 ;
}
F_38 ( V_68 ) ;
F_38 ( V_69 ) ;
return 0 ;
V_84:
F_38 ( V_68 ) ;
V_82:
F_38 ( V_69 ) ;
V_75:
return V_14 ;
}
static void F_39 ( struct V_11 * V_64 )
{
F_38 ( V_64 -> V_12 . V_83 ) ;
}
int F_40 ( const char * V_65 ,
struct V_1 const * V_66 ,
T_1 (* F_32)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_33)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_28 ) ,
T_7 V_90 ,
bool V_67 ,
struct V_9 * V_10 ,
struct V_91 * V_92 )
{
int V_14 ;
struct V_42 * V_93 , * V_94 ;
V_93 = F_41 ( sizeof *V_93 , V_72 ) ;
if ( V_93 == NULL ) {
V_14 = - V_41 ;
goto V_75;
}
V_14 = F_31 ( & V_93 -> V_64 ,
V_65 , V_66 ,
F_32 , F_33 , V_67 ) ;
if ( V_14 )
goto V_95;
V_93 -> V_46 = V_66 ;
V_93 -> V_47 = V_90 ;
F_42 (t, attr_list, l)
if ( strcmp ( V_94 -> V_64 . V_12 . V_83 ,
V_93 -> V_64 . V_12 . V_83 ) == 0 ) {
if ( ! V_67 )
F_14 ( V_10 , L_24 ,
V_94 -> V_64 . V_12 . V_83 ) ;
V_14 = - V_96 ;
goto V_97;
}
F_43 ( & V_93 -> V_98 , V_92 ) ;
return 0 ;
V_97:
F_39 ( & V_93 -> V_64 ) ;
V_95:
F_38 ( V_93 ) ;
V_75:
return V_14 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_1 const * V_66 )
{
int V_14 , V_99 = 0 ;
int V_5 ;
const struct V_44 * V_45 ;
if ( V_66 -> V_81 < 0 )
return 0 ;
F_45 (i, &chan->info_mask, sizeof(long)*8 ) {
V_14 = F_40 ( V_100 [ V_5 / 2 ] ,
V_66 ,
& F_29 ,
& F_30 ,
V_5 / 2 ,
! ( V_5 % 2 ) ,
& V_3 -> V_10 ,
& V_3 -> V_101 ) ;
if ( V_14 == - V_96 && ( V_5 % 2 == 0 ) ) {
V_14 = 0 ;
continue;
}
if ( V_14 < 0 )
goto V_75;
V_99 ++ ;
}
if ( V_66 -> V_45 ) {
unsigned int V_5 = 0 ;
for ( V_45 = V_66 -> V_45 ; V_45 -> V_83 ; V_45 ++ ) {
V_14 = F_40 ( V_45 -> V_83 ,
V_66 ,
V_45 -> V_48 ?
& F_25 : NULL ,
V_45 -> V_50 ?
& F_28 : NULL ,
V_5 ,
V_45 -> V_102 ,
& V_3 -> V_10 ,
& V_3 -> V_101 ) ;
V_5 ++ ;
if ( V_14 == - V_96 && V_45 -> V_102 )
continue;
if ( V_14 )
goto V_75;
V_99 ++ ;
}
}
V_14 = V_99 ;
V_75:
return V_14 ;
}
static void F_46 ( struct V_2 * V_3 ,
struct V_42 * V_103 )
{
F_38 ( V_103 -> V_64 . V_12 . V_83 ) ;
F_38 ( V_103 ) ;
}
static T_1 F_47 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_3 -> V_83 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
int V_5 , V_14 = 0 , V_99 , V_104 , V_105 = 0 ;
struct V_42 * V_103 , * V_106 ;
struct V_107 * * V_12 ;
if ( V_3 -> V_29 -> V_108 ) {
V_12 = V_3 -> V_29 -> V_108 -> V_108 ;
while ( * V_12 ++ != NULL )
V_105 ++ ;
}
V_99 = V_105 ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_14 = F_44 ( V_3 ,
& V_3
-> V_7 [ V_5 ] ) ;
if ( V_14 < 0 )
goto V_109;
V_99 += V_14 ;
}
if ( V_3 -> V_83 )
V_99 ++ ;
V_3 -> V_110 . V_108 = F_49 ( V_99 + 1 ,
sizeof( V_3 -> V_110 . V_108 [ 0 ] ) ,
V_72 ) ;
if ( V_3 -> V_110 . V_108 == NULL ) {
V_14 = - V_41 ;
goto V_109;
}
if ( V_3 -> V_29 -> V_108 )
memcpy ( V_3 -> V_110 . V_108 ,
V_3 -> V_29 -> V_108 -> V_108 ,
sizeof( V_3 -> V_110 . V_108 [ 0 ] )
* V_105 ) ;
V_104 = V_105 ;
F_42 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_110 . V_108 [ V_104 ++ ] = & V_103 -> V_64 . V_12 ;
if ( V_3 -> V_83 )
V_3 -> V_110 . V_108 [ V_104 ++ ] = & V_111 . V_12 ;
V_3 -> V_112 [ V_3 -> V_113 ++ ] =
& V_3 -> V_110 ;
return 0 ;
V_109:
F_50 (p, n,
&indio_dev->channel_attr_list, l) {
F_51 ( & V_103 -> V_98 ) ;
F_46 ( V_3 , V_103 ) ;
}
return V_14 ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_42 * V_103 , * V_106 ;
F_50 (p, n, &indio_dev->channel_attr_list, l) {
F_51 ( & V_103 -> V_98 ) ;
F_46 ( V_3 , V_103 ) ;
}
F_38 ( V_3 -> V_110 . V_108 ) ;
}
static void F_53 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_26 ( V_9 ) ;
if ( V_3 -> V_114 . V_10 )
F_54 ( & V_3 -> V_114 ) ;
if ( V_3 -> V_115 & V_116 )
F_55 ( V_3 ) ;
F_56 ( V_3 ) ;
F_52 ( V_3 ) ;
F_19 ( V_3 ) ;
F_57 ( & V_117 , V_3 -> V_118 ) ;
F_38 ( V_3 ) ;
}
struct V_2 * F_58 ( int V_119 )
{
struct V_2 * V_10 ;
T_5 V_120 ;
V_120 = sizeof( struct V_2 ) ;
if ( V_119 ) {
V_120 = F_59 ( V_120 , V_121 ) ;
V_120 += V_119 ;
}
V_120 += V_121 - 1 ;
V_10 = F_41 ( V_120 , V_72 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_112 = V_10 -> V_112 ;
V_10 -> V_10 . type = & V_122 ;
V_10 -> V_10 . V_123 = & V_15 ;
F_60 ( & V_10 -> V_10 ) ;
F_61 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_62 ( & V_10 -> V_124 ) ;
F_62 ( & V_10 -> V_125 ) ;
F_63 ( & V_10 -> V_101 ) ;
V_10 -> V_118 = F_64 ( & V_117 , 0 , 0 , V_72 ) ;
if ( V_10 -> V_118 < 0 ) {
F_6 ( V_16 L_25 ) ;
F_38 ( V_10 ) ;
return NULL ;
}
F_65 ( & V_10 -> V_10 , L_26 , V_10 -> V_118 ) ;
}
return V_10 ;
}
void F_66 ( struct V_2 * V_10 )
{
if ( V_10 )
F_67 ( & V_10 -> V_10 ) ;
}
static int F_68 ( struct V_126 * V_126 , struct V_22 * V_127 )
{
struct V_2 * V_3 = F_69 ( V_126 -> V_128 ,
struct V_2 , V_114 ) ;
if ( F_70 ( V_129 , & V_3 -> V_130 ) )
return - V_96 ;
V_127 -> V_26 = V_3 ;
return 0 ;
}
static int F_71 ( struct V_126 * V_126 , struct V_22 * V_127 )
{
struct V_2 * V_3 = F_69 ( V_126 -> V_128 ,
struct V_2 , V_114 ) ;
F_72 ( V_129 , & V_3 -> V_130 ) ;
return 0 ;
}
static long F_73 ( struct V_22 * V_127 , unsigned int V_131 , unsigned long V_132 )
{
struct V_2 * V_3 = V_127 -> V_26 ;
int T_4 * V_133 = ( int T_4 * ) V_132 ;
int V_134 ;
if ( V_131 == V_135 ) {
V_134 = F_74 ( V_3 ) ;
if ( F_75 ( V_133 , & V_134 , sizeof( V_134 ) ) )
return - V_35 ;
return 0 ;
}
return - V_36 ;
}
int F_76 ( struct V_2 * V_3 )
{
int V_14 ;
V_3 -> V_10 . V_136 = F_77 ( F_78 ( V_18 ) , V_3 -> V_118 ) ;
V_14 = F_21 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_27 ) ;
goto V_75;
}
V_14 = F_48 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_28 ) ;
goto V_137;
}
V_14 = F_79 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_32 ,
L_29 ) ;
goto V_138;
}
if ( V_3 -> V_115 & V_116 )
F_80 ( V_3 ) ;
if ( ( V_3 -> V_115 & V_139 ) &&
V_3 -> V_140 == NULL )
V_3 -> V_140 = & V_141 ;
V_14 = F_81 ( & V_3 -> V_10 ) ;
if ( V_14 < 0 )
goto V_142;
F_82 ( & V_3 -> V_114 , & V_143 ) ;
V_3 -> V_114 . V_144 = V_3 -> V_29 -> V_145 ;
V_14 = F_83 ( & V_3 -> V_114 , V_3 -> V_10 . V_136 , 1 ) ;
if ( V_14 < 0 )
goto V_146;
return 0 ;
V_146:
F_84 ( & V_3 -> V_10 ) ;
V_142:
F_56 ( V_3 ) ;
V_138:
F_52 ( V_3 ) ;
V_137:
F_19 ( V_3 ) ;
V_75:
return V_14 ;
}
void F_85 ( struct V_2 * V_3 )
{
F_86 ( & V_3 -> V_125 ) ;
V_3 -> V_29 = NULL ;
F_87 ( & V_3 -> V_125 ) ;
F_84 ( & V_3 -> V_10 ) ;
}
