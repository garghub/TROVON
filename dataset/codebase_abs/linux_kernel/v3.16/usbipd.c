static void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( int V_2 )
{
struct V_3 V_4 ;
struct V_5 V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
int V_13 = 0 ;
int error = 0 ;
int V_14 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_14 = F_3 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
if ( V_14 < 0 ) {
F_4 ( L_2 ) ;
return - 1 ;
}
F_5 ( 0 , & V_4 ) ;
F_6 (i, &host_driver->edev_list) {
V_8 = F_7 ( V_12 , struct V_7 , V_15 ) ;
if ( ! strncmp ( V_4 . V_16 , V_8 -> V_17 . V_16 , V_18 ) ) {
F_8 ( L_3 , V_4 . V_16 ) ;
V_13 = 1 ;
break;
}
}
if ( V_13 ) {
F_9 ( V_2 ) ;
V_14 = F_10 ( V_8 , V_2 ) ;
if ( V_14 < 0 )
error = 1 ;
} else {
F_8 ( L_4 , V_4 . V_16 ) ;
error = 1 ;
}
V_14 = F_11 ( V_2 , V_19 ,
( ! error ? V_20 : V_21 ) ) ;
if ( V_14 < 0 ) {
F_4 ( L_5 , V_19 ) ;
return - 1 ;
}
if ( error ) {
F_4 ( L_6 , V_4 . V_16 ) ;
return - 1 ;
}
memcpy ( & V_10 , & V_8 -> V_17 , sizeof( V_10 ) ) ;
F_12 ( 1 , & V_10 ) ;
V_14 = F_13 ( V_2 , & V_10 , sizeof( V_10 ) ) ;
if ( V_14 < 0 ) {
F_4 ( L_7 ) ;
return - 1 ;
}
F_4 ( L_8 , V_4 . V_16 ) ;
return 0 ;
}
static int F_14 ( int V_22 )
{
struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_23 V_24 ;
struct V_25 V_6 ;
struct V_11 * V_26 ;
int V_14 , V_12 ;
V_6 . V_27 = 0 ;
F_6 (j, &host_driver->edev_list) {
V_6 . V_27 += 1 ;
}
F_8 ( L_9 , V_6 . V_27 ) ;
V_14 = F_11 ( V_22 , V_28 , V_20 ) ;
if ( V_14 < 0 ) {
F_4 ( L_5 , V_28 ) ;
return - 1 ;
}
F_15 ( 1 , & V_6 ) ;
V_14 = F_13 ( V_22 , & V_6 , sizeof( V_6 ) ) ;
if ( V_14 < 0 ) {
F_4 ( L_10 , V_28 ) ;
return - 1 ;
}
F_6 (j, &host_driver->edev_list) {
V_8 = F_7 ( V_26 , struct V_7 , V_15 ) ;
F_16 ( & V_8 -> V_17 ) ;
memcpy ( & V_10 , & V_8 -> V_17 , sizeof( V_10 ) ) ;
F_12 ( 1 , & V_10 ) ;
V_14 = F_13 ( V_22 , & V_10 , sizeof( V_10 ) ) ;
if ( V_14 < 0 ) {
F_4 ( L_11 ) ;
return - 1 ;
}
for ( V_12 = 0 ; V_12 < V_8 -> V_17 . V_29 ; V_12 ++ ) {
F_17 ( & V_8 -> V_30 [ V_12 ] ) ;
memcpy ( & V_24 , & V_8 -> V_30 [ V_12 ] , sizeof( V_24 ) ) ;
F_18 ( 1 , & V_24 ) ;
V_14 = F_13 ( V_22 , & V_24 ,
sizeof( V_24 ) ) ;
if ( V_14 < 0 ) {
F_19 ( L_12 ) ;
return - 1 ;
}
}
}
return 0 ;
}
static int F_20 ( int V_22 )
{
struct V_31 V_4 ;
int V_14 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_14 = F_3 ( V_22 , & V_4 , sizeof( V_4 ) ) ;
if ( V_14 < 0 ) {
F_4 ( L_13 ) ;
return - 1 ;
}
V_14 = F_14 ( V_22 ) ;
if ( V_14 < 0 ) {
F_4 ( L_14 ) ;
return - 1 ;
}
return 0 ;
}
static int F_21 ( int V_22 )
{
T_1 V_32 = V_33 ;
int V_34 ;
V_34 = F_22 ( V_22 , & V_32 ) ;
if ( V_34 < 0 ) {
F_4 ( L_15 , V_32 ) ;
return - 1 ;
}
V_34 = F_23 () ;
if ( V_34 < 0 ) {
F_4 ( L_16 , V_34 ) ;
return - 1 ;
}
F_8 ( L_17 , V_32 , V_22 ) ;
switch ( V_32 ) {
case V_35 :
V_34 = F_20 ( V_22 ) ;
break;
case V_36 :
V_34 = F_2 ( V_22 ) ;
break;
case V_37 :
case V_38 :
default:
F_19 ( L_18 , V_32 ) ;
V_34 = - 1 ;
}
if ( V_34 == 0 )
F_8 ( L_19 , V_32 , V_22 ) ;
else
F_8 ( L_20 , V_32 , V_22 ) ;
return V_34 ;
}
static int F_24 ( int V_22 )
{
struct V_39 V_40 ;
int V_14 ;
F_25 ( & V_40 , V_41 , V_42 , V_43 , V_22 , 0 ) ;
F_26 ( & V_40 ) ;
V_14 = F_27 ( & V_40 ) ;
if ( V_14 == 0 )
return - 1 ;
return 0 ;
}
static int F_28 ( int V_44 )
{
int V_22 ;
struct V_45 V_46 ;
T_2 V_47 = sizeof( V_46 ) ;
char V_48 [ V_49 ] , V_50 [ V_51 ] ;
int V_14 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_22 = F_29 ( V_44 , (struct V_52 * ) & V_46 , & V_47 ) ;
if ( V_22 < 0 ) {
F_19 ( L_21 ) ;
return - 1 ;
}
V_14 = F_30 ( (struct V_52 * ) & V_46 , V_47 , V_48 , sizeof( V_48 ) ,
V_50 , sizeof( V_50 ) , V_53 | V_54 ) ;
if ( V_14 )
F_19 ( L_22 , F_31 ( V_14 ) ) ;
#ifdef F_32
V_14 = F_24 ( V_22 ) ;
if ( V_14 < 0 ) {
F_8 ( L_23 , V_48 ) ;
F_33 ( V_22 ) ;
return - 1 ;
}
#endif
F_8 ( L_24 , V_48 , V_50 ) ;
return V_22 ;
}
int F_34 ( int V_44 )
{
T_3 V_55 ;
int V_22 ;
V_22 = F_28 ( V_44 ) ;
if ( V_22 < 0 )
return - 1 ;
V_55 = F_35 () ;
if ( V_55 == 0 ) {
F_33 ( V_44 ) ;
F_21 ( V_22 ) ;
exit ( 0 ) ;
}
F_33 ( V_22 ) ;
return 0 ;
}
static void F_36 ( struct V_56 * V_57 , char V_58 [] ,
const T_4 V_59 )
{
char V_60 [ V_49 ] ;
char V_61 [ V_51 ] ;
int V_14 ;
V_58 [ 0 ] = '\0' ;
V_14 = F_30 ( V_57 -> V_62 , V_57 -> V_63 , V_60 , sizeof( V_60 ) ,
V_61 , sizeof( V_61 ) , V_53 | V_54 ) ;
if ( V_14 )
F_19 ( L_22 , F_31 ( V_14 ) ) ;
snprintf ( V_58 , V_59 , L_25 , V_60 , V_61 ) ;
}
static int F_37 ( struct V_56 * V_64 , int V_65 [] ,
int V_66 )
{
struct V_56 * V_57 ;
int V_34 , V_67 = 0 ;
const T_4 V_68 = V_49 + V_51 + 2 ;
char V_69 [ V_68 ] ;
for ( V_57 = V_64 ; V_57 && V_67 < V_66 ; V_57 = V_57 -> V_70 ) {
int V_71 ;
F_36 ( V_57 , V_69 , V_68 ) ;
F_4 ( L_26 , V_69 ) ;
V_71 = F_38 ( V_57 -> V_72 , V_57 -> V_73 , V_57 -> V_74 ) ;
if ( V_71 < 0 ) {
F_19 ( L_27 ,
V_69 , V_75 , strerror ( V_75 ) ) ;
continue;
}
F_39 ( V_71 ) ;
F_9 ( V_71 ) ;
F_40 ( V_71 ) ;
if ( V_71 >= V_76 ) {
F_19 ( L_28 ,
V_69 , V_71 , V_76 ) ;
F_33 ( V_71 ) ;
continue;
}
V_34 = F_41 ( V_71 , V_57 -> V_62 , V_57 -> V_63 ) ;
if ( V_34 < 0 ) {
F_19 ( L_29 ,
V_69 , V_75 , strerror ( V_75 ) ) ;
F_33 ( V_71 ) ;
continue;
}
V_34 = F_42 ( V_71 , V_77 ) ;
if ( V_34 < 0 ) {
F_19 ( L_30 ,
V_69 , V_75 , strerror ( V_75 ) ) ;
F_33 ( V_71 ) ;
continue;
}
F_8 ( L_31 , V_69 ) ;
V_65 [ V_67 ++ ] = V_71 ;
}
return V_67 ;
}
static struct V_56 * F_43 ( char * V_48 , int V_72 )
{
struct V_56 V_78 , * V_64 ;
int V_14 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_72 = V_72 ;
V_78 . V_73 = V_79 ;
V_78 . V_80 = V_81 ;
V_14 = F_44 ( V_48 , V_82 , & V_78 , & V_64 ) ;
if ( V_14 ) {
F_19 ( L_32 , V_82 ,
F_31 ( V_14 ) ) ;
return NULL ;
}
return V_64 ;
}
static void F_45 ( int V_12 )
{
F_4 ( L_33 , F_46 ( V_12 ) ) ;
}
static void F_47 ( void )
{
struct V_83 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_85 = F_45 ;
F_48 ( & V_84 . V_86 ) ;
V_83 ( V_87 , & V_84 , NULL ) ;
V_83 ( V_88 , & V_84 , NULL ) ;
V_84 . V_85 = V_89 ;
V_83 ( V_90 , & V_84 , NULL ) ;
}
static void F_49 ( void )
{
if ( V_91 ) {
F_4 ( L_34 , V_91 ) ;
T_5 * V_92 ;
V_92 = fopen ( V_91 , L_35 ) ;
if ( ! V_92 ) {
F_19 ( L_36 ,
V_91 , V_75 , strerror ( V_75 ) ) ;
return;
}
fprintf ( V_92 , L_37 , F_50 () ) ;
fclose ( V_92 ) ;
}
}
static void F_51 ( void )
{
if ( V_91 ) {
F_4 ( L_38 , V_91 ) ;
F_52 ( V_91 ) ;
}
}
static int F_53 ( int V_93 , int V_94 , int V_95 )
{
struct V_56 * V_64 ;
int V_65 [ V_96 ] ;
int V_67 , V_97 ;
int V_12 , V_98 ;
struct V_99 * V_100 ;
struct V_101 V_102 ;
T_6 V_103 ;
if ( F_54 () ) {
F_19 ( L_39 V_104 L_40
V_105 L_41 ) ;
return - 1 ;
}
if ( V_93 ) {
if ( F_55 ( 0 , 0 ) < 0 ) {
F_19 ( L_42 , strerror ( V_75 ) ) ;
F_56 () ;
return - 1 ;
}
F_57 ( 0 ) ;
V_106 = 1 ;
}
F_47 () ;
F_49 () ;
F_8 ( L_43 V_42 L_44 , V_107 ) ;
if ( V_94 && V_95 )
V_97 = V_108 ;
else if ( V_94 )
V_97 = V_109 ;
else
V_97 = V_110 ;
V_64 = F_43 ( NULL , V_97 ) ;
if ( ! V_64 ) {
F_56 () ;
return - 1 ;
}
V_67 = F_37 ( V_64 , V_65 ,
sizeof( V_65 ) / sizeof( * V_65 ) ) ;
F_58 ( V_64 ) ;
if ( V_67 <= 0 ) {
F_19 ( L_45 ) ;
F_56 () ;
return - 1 ;
}
F_4 ( L_46 , V_67 , ( V_67 == 1 ) ? L_47 : L_48 ) ;
V_100 = calloc ( V_67 , sizeof( struct V_99 ) ) ;
for ( V_12 = 0 ; V_12 < V_67 ; V_12 ++ ) {
V_100 [ V_12 ] . V_111 = V_65 [ V_12 ] ;
V_100 [ V_12 ] . V_112 = V_113 ;
}
V_102 . V_114 = V_115 ;
V_102 . V_116 = 0 ;
F_59 ( & V_103 ) ;
F_60 ( & V_103 , V_87 ) ;
F_60 ( & V_103 , V_88 ) ;
V_98 = 0 ;
while ( ! V_98 ) {
int V_117 ;
V_117 = F_61 ( V_100 , V_67 , & V_102 , & V_103 ) ;
if ( V_117 < 0 ) {
F_4 ( L_49 , strerror ( V_75 ) ) ;
V_98 = 1 ;
} else if ( V_117 ) {
for ( V_12 = 0 ; V_12 < V_67 ; V_12 ++ ) {
if ( V_100 [ V_12 ] . V_118 & V_113 ) {
F_4 ( L_50 ,
V_12 , V_65 [ V_12 ] ) ;
F_34 ( V_65 [ V_12 ] ) ;
}
}
} else {
F_4 ( L_51 ) ;
}
}
F_8 ( L_52 V_42 ) ;
free ( V_100 ) ;
F_56 () ;
return 0 ;
}
int main ( int V_119 , char * V_120 [] )
{
static const struct V_121 V_122 [] = {
{ L_53 , V_123 , NULL , '4' } ,
{ L_54 , V_123 , NULL , '6' } ,
{ L_55 , V_123 , NULL , 'D' } ,
{ L_55 , V_123 , NULL , 'D' } ,
{ L_56 , V_123 , NULL , 'd' } ,
{ L_57 , V_124 , NULL , 'P' } ,
{ L_58 , V_125 , NULL , 't' } ,
{ L_59 , V_123 , NULL , 'h' } ,
{ L_60 , V_123 , NULL , 'v' } ,
{ NULL , 0 , NULL , 0 }
} ;
enum {
V_126 = 1 ,
V_127 ,
V_128
} V_129 ;
int V_93 = 0 ;
int V_94 = 0 , V_95 = 0 ;
int V_130 , V_14 = - 1 ;
V_91 = NULL ;
V_131 = 1 ;
V_106 = 0 ;
if ( F_62 () != 0 )
F_19 ( L_61 ) ;
V_129 = V_126 ;
for (; ; ) {
V_130 = F_63 ( V_119 , V_120 , L_62 , V_122 , NULL ) ;
if ( V_130 == - 1 )
break;
switch ( V_130 ) {
case '4' :
V_94 = 1 ;
break;
case '6' :
V_95 = 1 ;
break;
case 'D' :
V_93 = 1 ;
break;
case 'd' :
V_132 = 1 ;
break;
case 'h' :
V_129 = V_127 ;
break;
case 'P' :
V_91 = V_133 ? V_133 : V_134 ;
break;
case 't' :
F_64 ( V_133 ) ;
break;
case 'v' :
V_129 = V_128 ;
break;
case '?' :
F_1 () ;
default:
goto V_135;
}
}
if ( ! V_94 && ! V_95 )
V_94 = V_95 = 1 ;
switch ( V_129 ) {
case V_126 :
V_14 = F_53 ( V_93 , V_94 , V_95 ) ;
F_51 () ;
break;
case V_128 :
printf ( V_42 L_63 , V_107 ) ;
V_14 = 0 ;
break;
case V_127 :
F_1 () ;
V_14 = 0 ;
break;
default:
F_1 () ;
goto V_135;
}
V_135:
return ( V_14 > - 1 ? V_136 : V_137 ) ;
}
