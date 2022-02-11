static void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( int V_2 )
{
struct V_3 V_4 ;
struct V_5 * V_6 ;
struct V_7 V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
int error = 0 ;
int V_12 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_12 = F_3 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_2 ) ;
return - 1 ;
}
F_5 ( 0 , & V_4 ) ;
F_6 (i, &host_driver->edev_list) {
V_6 = F_7 ( V_10 , struct V_5 , V_13 ) ;
if ( ! strncmp ( V_4 . V_14 , V_6 -> V_15 . V_14 , V_16 ) ) {
F_8 ( L_3 , V_4 . V_14 ) ;
V_11 = 1 ;
break;
}
}
if ( V_11 ) {
F_9 ( V_2 ) ;
V_12 = F_10 ( V_6 , V_2 ) ;
if ( V_12 < 0 )
error = 1 ;
} else {
F_8 ( L_4 , V_4 . V_14 ) ;
error = 1 ;
}
V_12 = F_11 ( V_2 , V_17 ,
( ! error ? V_18 : V_19 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_5 , V_17 ) ;
return - 1 ;
}
if ( error ) {
F_4 ( L_6 , V_4 . V_14 ) ;
return - 1 ;
}
memcpy ( & V_8 , & V_6 -> V_15 , sizeof( V_8 ) ) ;
F_12 ( 1 , & V_8 ) ;
V_12 = F_13 ( V_2 , & V_8 , sizeof( V_8 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_7 ) ;
return - 1 ;
}
F_4 ( L_8 , V_4 . V_14 ) ;
return 0 ;
}
static int F_14 ( int V_20 )
{
struct V_5 * V_6 ;
struct V_7 V_8 ;
struct V_21 V_22 ;
struct V_23 V_24 ;
struct V_9 * V_25 ;
int V_12 , V_10 ;
V_24 . V_26 = 0 ;
F_6 (j, &host_driver->edev_list) {
V_24 . V_26 += 1 ;
}
F_8 ( L_9 , V_24 . V_26 ) ;
V_12 = F_11 ( V_20 , V_27 , V_18 ) ;
if ( V_12 < 0 ) {
F_4 ( L_5 , V_27 ) ;
return - 1 ;
}
F_15 ( 1 , & V_24 ) ;
V_12 = F_13 ( V_20 , & V_24 , sizeof( V_24 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_10 , V_27 ) ;
return - 1 ;
}
F_6 (j, &host_driver->edev_list) {
V_6 = F_7 ( V_25 , struct V_5 , V_13 ) ;
F_16 ( & V_6 -> V_15 ) ;
memcpy ( & V_8 , & V_6 -> V_15 , sizeof( V_8 ) ) ;
F_12 ( 1 , & V_8 ) ;
V_12 = F_13 ( V_20 , & V_8 , sizeof( V_8 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_11 ) ;
return - 1 ;
}
for ( V_10 = 0 ; V_10 < V_6 -> V_15 . V_28 ; V_10 ++ ) {
F_17 ( & V_6 -> V_29 [ V_10 ] ) ;
memcpy ( & V_22 , & V_6 -> V_29 [ V_10 ] , sizeof( V_22 ) ) ;
F_18 ( 1 , & V_22 ) ;
V_12 = F_13 ( V_20 , & V_22 ,
sizeof( V_22 ) ) ;
if ( V_12 < 0 ) {
F_19 ( L_12 ) ;
return - 1 ;
}
}
}
return 0 ;
}
static int F_20 ( int V_20 )
{
struct V_30 V_4 ;
int V_12 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_12 = F_3 ( V_20 , & V_4 , sizeof( V_4 ) ) ;
if ( V_12 < 0 ) {
F_4 ( L_13 ) ;
return - 1 ;
}
V_12 = F_14 ( V_20 ) ;
if ( V_12 < 0 ) {
F_4 ( L_14 ) ;
return - 1 ;
}
return 0 ;
}
static int F_21 ( int V_20 )
{
T_1 V_31 = V_32 ;
int V_33 ;
V_33 = F_22 ( V_20 , & V_31 ) ;
if ( V_33 < 0 ) {
F_4 ( L_15 , V_31 ) ;
return - 1 ;
}
V_33 = F_23 () ;
if ( V_33 < 0 ) {
F_4 ( L_16 , V_33 ) ;
return - 1 ;
}
F_8 ( L_17 , V_31 , V_20 ) ;
switch ( V_31 ) {
case V_34 :
V_33 = F_20 ( V_20 ) ;
break;
case V_35 :
V_33 = F_2 ( V_20 ) ;
break;
case V_36 :
case V_37 :
default:
F_19 ( L_18 , V_31 ) ;
V_33 = - 1 ;
}
if ( V_33 == 0 )
F_8 ( L_19 , V_31 , V_20 ) ;
else
F_8 ( L_20 , V_31 , V_20 ) ;
return V_33 ;
}
static int F_24 ( int V_20 )
{
struct V_38 V_39 ;
int V_12 ;
F_25 ( & V_39 , V_40 , V_41 , V_42 , V_20 , 0 ) ;
F_26 ( & V_39 ) ;
V_12 = F_27 ( & V_39 ) ;
if ( V_12 == 0 )
return - 1 ;
return 0 ;
}
static int F_28 ( int V_43 )
{
int V_20 ;
struct V_44 V_45 ;
T_2 V_46 = sizeof( V_45 ) ;
char V_47 [ V_48 ] , V_49 [ V_50 ] ;
int V_12 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_20 = F_29 ( V_43 , (struct V_51 * ) & V_45 , & V_46 ) ;
if ( V_20 < 0 ) {
F_19 ( L_21 ) ;
return - 1 ;
}
V_12 = F_30 ( (struct V_51 * ) & V_45 , V_46 , V_47 , sizeof( V_47 ) ,
V_49 , sizeof( V_49 ) , V_52 | V_53 ) ;
if ( V_12 )
F_19 ( L_22 , F_31 ( V_12 ) ) ;
#ifdef F_32
V_12 = F_24 ( V_20 ) ;
if ( V_12 < 0 ) {
F_8 ( L_23 , V_47 ) ;
F_33 ( V_20 ) ;
return - 1 ;
}
#endif
F_8 ( L_24 , V_47 , V_49 ) ;
return V_20 ;
}
int F_34 ( int V_43 )
{
T_3 V_54 ;
int V_20 ;
V_20 = F_28 ( V_43 ) ;
if ( V_20 < 0 )
return - 1 ;
V_54 = F_35 () ;
if ( V_54 == 0 ) {
F_33 ( V_43 ) ;
F_21 ( V_20 ) ;
exit ( 0 ) ;
}
F_33 ( V_20 ) ;
return 0 ;
}
static void F_36 ( struct V_55 * V_56 , char V_57 [] ,
const T_4 V_58 )
{
char V_59 [ V_48 ] ;
char V_60 [ V_50 ] ;
int V_12 ;
V_57 [ 0 ] = '\0' ;
V_12 = F_30 ( V_56 -> V_61 , V_56 -> V_62 , V_59 , sizeof( V_59 ) ,
V_60 , sizeof( V_60 ) , V_52 | V_53 ) ;
if ( V_12 )
F_19 ( L_22 , F_31 ( V_12 ) ) ;
snprintf ( V_57 , V_58 , L_25 , V_59 , V_60 ) ;
}
static int F_37 ( struct V_55 * V_63 , int V_64 [] ,
int V_65 )
{
struct V_55 * V_56 ;
int V_33 , V_66 = 0 ;
const T_4 V_67 = V_48 + V_50 + 2 ;
char V_68 [ V_67 ] ;
for ( V_56 = V_63 ; V_56 && V_66 < V_65 ; V_56 = V_56 -> V_69 ) {
int V_70 ;
F_36 ( V_56 , V_68 , V_67 ) ;
F_4 ( L_26 , V_68 ) ;
V_70 = F_38 ( V_56 -> V_71 , V_56 -> V_72 , V_56 -> V_73 ) ;
if ( V_70 < 0 ) {
F_19 ( L_27 ,
V_68 , V_74 , strerror ( V_74 ) ) ;
continue;
}
F_39 ( V_70 ) ;
F_9 ( V_70 ) ;
F_40 ( V_70 ) ;
if ( V_70 >= V_75 ) {
F_19 ( L_28 ,
V_68 , V_70 , V_75 ) ;
F_33 ( V_70 ) ;
continue;
}
V_33 = F_41 ( V_70 , V_56 -> V_61 , V_56 -> V_62 ) ;
if ( V_33 < 0 ) {
F_19 ( L_29 ,
V_68 , V_74 , strerror ( V_74 ) ) ;
F_33 ( V_70 ) ;
continue;
}
V_33 = F_42 ( V_70 , V_76 ) ;
if ( V_33 < 0 ) {
F_19 ( L_30 ,
V_68 , V_74 , strerror ( V_74 ) ) ;
F_33 ( V_70 ) ;
continue;
}
F_8 ( L_31 , V_68 ) ;
V_64 [ V_66 ++ ] = V_70 ;
}
return V_66 ;
}
static struct V_55 * F_43 ( char * V_47 , int V_71 )
{
struct V_55 V_77 , * V_63 ;
int V_12 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_71 = V_71 ;
V_77 . V_72 = V_78 ;
V_77 . V_79 = V_80 ;
V_12 = F_44 ( V_47 , V_81 , & V_77 , & V_63 ) ;
if ( V_12 ) {
F_19 ( L_32 , V_81 ,
F_31 ( V_12 ) ) ;
return NULL ;
}
return V_63 ;
}
static void F_45 ( int V_10 )
{
F_4 ( L_33 , F_46 ( V_10 ) ) ;
}
static void F_47 ( void )
{
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_84 = F_45 ;
F_48 ( & V_83 . V_85 ) ;
V_82 ( V_86 , & V_83 , NULL ) ;
V_82 ( V_87 , & V_83 , NULL ) ;
V_83 . V_84 = V_88 ;
V_82 ( V_89 , & V_83 , NULL ) ;
}
static void F_49 ( void )
{
if ( V_90 ) {
F_4 ( L_34 , V_90 ) ;
T_5 * V_91 ;
V_91 = fopen ( V_90 , L_35 ) ;
if ( ! V_91 ) {
F_19 ( L_36 ,
V_90 , V_74 , strerror ( V_74 ) ) ;
return;
}
fprintf ( V_91 , L_37 , F_50 () ) ;
fclose ( V_91 ) ;
}
}
static void F_51 ( void )
{
if ( V_90 ) {
F_4 ( L_38 , V_90 ) ;
F_52 ( V_90 ) ;
}
}
static int F_53 ( int V_92 , int V_93 , int V_94 )
{
struct V_55 * V_63 ;
int V_64 [ V_95 ] ;
int V_66 , V_96 ;
int V_10 , V_97 ;
struct V_98 * V_99 ;
struct V_100 V_101 ;
T_6 V_102 ;
if ( F_54 () ) {
F_19 ( L_39 V_103 L_40
V_104 L_41 ) ;
return - 1 ;
}
if ( V_92 ) {
if ( F_55 ( 0 , 0 ) < 0 ) {
F_19 ( L_42 , strerror ( V_74 ) ) ;
F_56 () ;
return - 1 ;
}
F_57 ( 0 ) ;
V_105 = 1 ;
}
F_47 () ;
F_49 () ;
F_8 ( L_43 V_41 L_44 , V_106 ) ;
if ( V_93 && V_94 )
V_96 = V_107 ;
else if ( V_93 )
V_96 = V_108 ;
else
V_96 = V_109 ;
V_63 = F_43 ( NULL , V_96 ) ;
if ( ! V_63 ) {
F_56 () ;
return - 1 ;
}
V_66 = F_37 ( V_63 , V_64 ,
sizeof( V_64 ) / sizeof( * V_64 ) ) ;
F_58 ( V_63 ) ;
if ( V_66 <= 0 ) {
F_19 ( L_45 ) ;
F_56 () ;
return - 1 ;
}
F_4 ( L_46 , V_66 , ( V_66 == 1 ) ? L_47 : L_48 ) ;
V_99 = calloc ( V_66 , sizeof( struct V_98 ) ) ;
for ( V_10 = 0 ; V_10 < V_66 ; V_10 ++ ) {
V_99 [ V_10 ] . V_110 = V_64 [ V_10 ] ;
V_99 [ V_10 ] . V_111 = V_112 ;
}
V_101 . V_113 = V_114 ;
V_101 . V_115 = 0 ;
F_59 ( & V_102 ) ;
F_60 ( & V_102 , V_86 ) ;
F_60 ( & V_102 , V_87 ) ;
V_97 = 0 ;
while ( ! V_97 ) {
int V_116 ;
V_116 = F_61 ( V_99 , V_66 , & V_101 , & V_102 ) ;
if ( V_116 < 0 ) {
F_4 ( L_49 , strerror ( V_74 ) ) ;
V_97 = 1 ;
} else if ( V_116 ) {
for ( V_10 = 0 ; V_10 < V_66 ; V_10 ++ ) {
if ( V_99 [ V_10 ] . V_117 & V_112 ) {
F_4 ( L_50 ,
V_10 , V_64 [ V_10 ] ) ;
F_34 ( V_64 [ V_10 ] ) ;
}
}
} else {
F_4 ( L_51 ) ;
}
}
F_8 ( L_52 V_41 ) ;
free ( V_99 ) ;
F_56 () ;
return 0 ;
}
int main ( int V_118 , char * V_119 [] )
{
static const struct V_120 V_121 [] = {
{ L_53 , V_122 , NULL , '4' } ,
{ L_54 , V_122 , NULL , '6' } ,
{ L_55 , V_122 , NULL , 'D' } ,
{ L_55 , V_122 , NULL , 'D' } ,
{ L_56 , V_122 , NULL , 'd' } ,
{ L_57 , V_123 , NULL , 'P' } ,
{ L_58 , V_124 , NULL , 't' } ,
{ L_59 , V_122 , NULL , 'h' } ,
{ L_60 , V_122 , NULL , 'v' } ,
{ NULL , 0 , NULL , 0 }
} ;
enum {
V_125 = 1 ,
V_126 ,
V_127
} V_128 ;
int V_92 = 0 ;
int V_93 = 0 , V_94 = 0 ;
int V_129 , V_12 = - 1 ;
V_90 = NULL ;
V_130 = 1 ;
V_105 = 0 ;
if ( F_62 () != 0 )
F_19 ( L_61 ) ;
V_128 = V_125 ;
for (; ; ) {
V_129 = F_63 ( V_118 , V_119 , L_62 , V_121 , NULL ) ;
if ( V_129 == - 1 )
break;
switch ( V_129 ) {
case '4' :
V_93 = 1 ;
break;
case '6' :
V_94 = 1 ;
break;
case 'D' :
V_92 = 1 ;
break;
case 'd' :
V_131 = 1 ;
break;
case 'h' :
V_128 = V_126 ;
break;
case 'P' :
V_90 = V_132 ? V_132 : V_133 ;
break;
case 't' :
F_64 ( V_132 ) ;
break;
case 'v' :
V_128 = V_127 ;
break;
case '?' :
F_1 () ;
default:
goto V_134;
}
}
if ( ! V_93 && ! V_94 )
V_93 = V_94 = 1 ;
switch ( V_128 ) {
case V_125 :
V_12 = F_53 ( V_92 , V_93 , V_94 ) ;
F_51 () ;
break;
case V_127 :
printf ( V_41 L_63 , V_106 ) ;
V_12 = 0 ;
break;
case V_126 :
F_1 () ;
V_12 = 0 ;
break;
default:
F_1 () ;
goto V_134;
}
V_134:
return ( V_12 > - 1 ? V_135 : V_136 ) ;
}
