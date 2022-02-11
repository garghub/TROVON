static int F_1 ( char * V_1 , int V_2 , int V_3 )
{
int V_4 = V_2 % V_3 ;
int V_5 = sprintf ( V_1 , L_1 , V_2 / V_3 ) ;
if ( V_4 == 0 )
return V_5 ;
V_1 [ V_5 ++ ] = '.' ;
do {
V_3 /= 10 ;
sprintf ( V_1 + V_5 , L_1 , V_4 / V_3 ) ;
V_5 ++ ;
V_4 %= V_3 ;
} while ( V_4 );
V_1 [ V_5 ++ ] = '\0' ;
return V_5 ;
}
static int F_2 ( struct V_6 * V_7 , const void * V_8 ,
enum V_9 V_10 ,
void * V_11 , unsigned V_12 ,
struct V_13 * V_14 )
{
int V_15 , V_5 ;
unsigned char V_16 [ V_17 ] ;
struct V_13 V_18 ;
if ( ! V_14 )
V_14 = & V_18 ;
for( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_5 = F_3 ( V_7 , V_8 , V_10 , V_11 , V_12 , V_16 ,
V_14 , V_20 , 1 ,
V_21 |
V_22 |
V_23 ,
0 , NULL ) ;
if ( ! ( F_4 ( V_5 ) & V_24 ) ||
V_14 -> V_25 != V_26 )
break;
}
return V_5 ;
}
static inline const char * F_5 ( enum V_27 type )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < F_6 ( V_28 ) ; V_15 ++ ) {
if ( type == V_28 [ V_15 ] . V_2 )
return V_28 [ V_15 ] . V_29 ;
}
return NULL ;
}
static inline enum V_27 F_7 ( const char * V_29 )
{
int V_15 , V_30 ;
for ( V_15 = 0 ; V_15 < F_6 ( V_28 ) ; V_15 ++ ) {
V_30 = strlen ( V_28 [ V_15 ] . V_29 ) ;
if ( strncmp ( V_29 , V_28 [ V_15 ] . V_29 , V_30 ) == 0 &&
( V_29 [ V_30 ] == '\n' || V_29 [ V_30 ] == '\0' ) )
return V_28 [ V_15 ] . V_2 ;
}
return V_31 ;
}
static int F_8 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_37 * V_38 = F_9 ( V_35 ) ;
F_10 ( V_38 ) = V_31 ;
return 0 ;
}
static int F_11 ( struct V_39 * V_40 ,
struct V_34 * V_35 )
{
struct V_37 * V_38 ;
if ( ! F_12 ( V_35 ) )
return 0 ;
V_38 = F_9 ( V_35 ) ;
if ( ! V_38 -> V_41 || V_38 -> V_41 -> V_42 . V_43 . V_44
!= & V_45 . V_44 )
return 0 ;
return & V_38 -> V_41 -> V_42 . V_43 == V_40 ;
}
static int F_13 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_6 * V_7 = F_14 ( V_35 ) ;
struct V_46 * V_47 = V_7 -> V_48 ;
unsigned V_49 = F_15 ( V_7 , & V_7 -> V_50 [ 8 ] ,
& V_7 -> V_50 [ 16 ] ,
V_51 ) ;
F_16 ( V_47 ) = F_17 ( V_7 ) ;
F_18 ( V_47 ) = F_19 ( V_7 ) ;
F_20 ( V_47 ) = F_21 ( V_7 ) ;
F_22 ( V_47 ) = F_23 ( V_7 ) ;
F_24 ( V_47 ) = F_25 ( V_7 ) ;
if ( V_49 & V_52 ) {
F_26 ( V_35 , L_2 ) ;
F_24 ( V_47 ) = 0 ;
}
F_27 ( V_47 ) = F_28 ( V_7 ) ;
return 0 ;
}
static int F_29 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_46 * V_47 = F_30 ( V_35 ) ;
F_31 ( V_47 ) = - 1 ;
F_32 ( V_47 ) = 0 ;
F_33 ( V_47 ) = 0 ;
F_34 ( V_47 ) = 255 ;
F_35 ( V_47 ) = 0 ;
F_36 ( V_47 ) = 1 ;
F_37 ( V_47 ) = 0 ;
F_38 ( V_47 ) = 1 ;
F_39 ( V_47 ) = 0 ;
F_40 ( V_47 ) = 0 ;
F_41 ( V_47 ) = 1 ;
F_42 ( V_47 ) = 0 ;
F_43 ( V_47 ) = 0 ;
F_44 ( V_47 ) = 0 ;
F_45 ( V_47 ) = 0 ;
F_46 ( V_47 ) = 0 ;
F_47 ( V_47 ) = 0 ;
F_48 ( V_47 ) = 0 ;
F_49 ( V_47 ) = 0 ;
F_50 ( & F_51 ( V_47 ) ) ;
return 0 ;
}
static int F_52 ( struct V_34 * V_35 , void * V_53 )
{
if ( ! F_53 ( V_35 ) )
return 0 ;
F_54 ( F_14 ( V_35 ) ) ;
return 1 ;
}
static T_1
F_55 ( struct V_34 * V_35 , struct V_54 * V_55 ,
const char * V_56 , T_2 V_57 )
{
struct V_46 * V_47 = F_56 ( V_35 ) ;
F_57 ( & V_47 -> V_35 , NULL , F_52 ) ;
return V_57 ;
}
static int F_58 ( char * V_56 , int V_58 )
{
int V_30 , V_59 ;
if ( V_58 < 0 || V_58 > 0xff ) {
V_59 = - 1 ;
} else if ( V_58 <= V_60 ) {
V_59 = V_61 [ V_58 ] ;
} else {
V_59 = V_58 * 4000 ;
}
if ( V_59 == - 1 ) {
V_30 = sprintf ( V_56 , L_3 ) ;
} else {
V_30 = F_1 ( V_56 , V_59 , 1000 ) ;
}
return V_30 ;
}
static T_1
F_59 ( char * V_56 , int V_58 )
{
int V_30 = F_58 ( V_56 , V_58 ) ;
V_56 [ V_30 ++ ] = '\n' ;
V_56 [ V_30 ] = '\0' ;
return V_30 ;
}
static T_1
F_60 ( struct V_34 * V_35 , const char * V_56 ,
T_2 V_57 , int * V_62 )
{
int V_63 , V_59 , V_58 = - 1 ;
char * V_64 ;
V_59 = F_61 ( V_56 , & V_64 , 10 ) * 1000 ;
if ( * V_64 == '.' ) {
int V_65 = 100 ;
do {
V_64 ++ ;
if ( ! isdigit ( * V_64 ) )
break;
V_59 += ( * V_64 - '0' ) * V_65 ;
V_65 /= 10 ;
} while ( V_65 > 0 );
}
for ( V_63 = 0 ; V_63 <= V_60 ; V_63 ++ ) {
if ( V_61 [ V_63 ] < V_59 )
continue;
V_58 = V_63 ;
break;
}
if ( V_58 == - 1 )
V_58 = V_59 / 4000 ;
if ( V_58 > 0xff )
V_58 = 0xff ;
* V_62 = V_58 ;
return V_57 ;
}
static T_1
F_62 ( struct V_34 * V_35 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_46 * V_47 = F_56 ( V_35 ) ;
struct V_37 * V_38 = F_9 ( V_47 -> V_35 . V_66 ) ;
struct V_67 * V_15 = F_63 ( V_38 -> V_41 ) ;
struct V_68 * V_69 =
(struct V_68 * ) & V_47 -> V_70 ;
if ( V_15 -> V_71 -> V_72 )
V_15 -> V_71 -> V_72 ( V_47 ) ;
return F_59 ( V_56 , V_69 -> V_58 ) ;
}
static T_1
F_64 ( struct V_34 * V_36 , struct V_54 * V_55 ,
const char * V_56 , T_2 V_57 )
{
struct V_46 * V_47 = F_56 ( V_36 ) ;
struct V_37 * V_38 = F_9 ( V_47 -> V_35 . V_66 ) ;
struct V_67 * V_15 = F_63 ( V_38 -> V_41 ) ;
struct V_68 * V_69 =
(struct V_68 * ) & V_47 -> V_70 ;
int V_58 , V_73 ;
if ( ! V_15 -> V_71 -> V_74 )
return - V_75 ;
V_73 = F_60 ( V_36 , V_56 , V_57 , & V_58 ) ;
if ( V_58 < V_69 -> V_76 )
V_58 = V_69 -> V_76 ;
V_15 -> V_71 -> V_74 ( V_47 , V_58 ) ;
return V_73 ;
}
static T_1
F_65 ( struct V_34 * V_36 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_46 * V_47 = F_56 ( V_36 ) ;
struct V_37 * V_38 = F_9 ( V_47 -> V_35 . V_66 ) ;
struct V_67 * V_15 = F_63 ( V_38 -> V_41 ) ;
struct V_68 * V_69 =
(struct V_68 * ) & V_47 -> V_70 ;
if ( ! V_15 -> V_71 -> V_74 )
return - V_75 ;
return F_59 ( V_56 , V_69 -> V_76 ) ;
}
static T_1
F_66 ( struct V_34 * V_36 ,
struct V_54 * V_55 ,
const char * V_56 , T_2 V_57 )
{
struct V_46 * V_47 = F_56 ( V_36 ) ;
struct V_68 * V_69 =
(struct V_68 * ) & V_47 -> V_70 ;
return F_60 ( V_36 , V_56 , V_57 ,
& V_69 -> V_76 ) ;
}
static T_1 F_67 ( struct V_34 * V_36 ,
struct V_54 * V_55 ,
char * V_56 )
{
struct V_37 * V_38 = F_68 ( V_36 ) ;
struct V_67 * V_15 = F_63 ( V_38 -> V_41 ) ;
if ( V_15 -> V_71 -> V_77 )
V_15 -> V_71 -> V_77 ( V_38 ) ;
return sprintf ( V_56 , L_4 , F_5 ( F_10 ( V_38 ) ) ) ;
}
static T_1 F_69 ( struct V_34 * V_35 ,
struct V_54 * V_55 ,
const char * V_56 , T_2 V_57 )
{
struct V_37 * V_38 = F_68 ( V_35 ) ;
struct V_67 * V_15 = F_63 ( V_38 -> V_41 ) ;
enum V_27 type = F_7 ( V_56 ) ;
if ( ! V_15 -> V_71 -> V_78 )
return - V_75 ;
if ( type != V_31 )
V_15 -> V_71 -> V_78 ( V_38 , type ) ;
return V_57 ;
}
static T_1 F_70 ( struct V_34 * V_36 ,
struct V_54 * V_55 ,
char * V_56 )
{
struct V_37 * V_38 = F_68 ( V_36 ) ;
return sprintf ( V_56 , L_4 , V_38 -> V_79 == 16 ? L_5 : L_6 ) ;
}
static T_1 F_71 ( struct V_34 * V_36 ,
struct V_54 * V_55 ,
char * V_56 )
{
struct V_37 * V_38 = F_68 ( V_36 ) ;
return sprintf ( V_56 , L_7 , V_38 -> V_80 ) ;
}
static enum V_81
F_72 ( struct V_6 * V_7 , T_3 * V_11 ,
T_3 * V_82 , const int V_83 )
{
int V_30 = V_82 - V_11 ;
int V_63 , V_84 , V_85 , V_5 ;
unsigned int V_86 = 0x0000ffff ;
struct V_13 V_14 ;
const char V_87 [] = {
V_88 , 0x0a , 0 , 0 , 0 , 0 , 0 , V_30 >> 8 , V_30 & 0xff , 0
} ;
const char V_89 [] = {
V_90 , 0x0a , 0 , 0 , 0 , 0 , 0 , V_30 >> 8 , V_30 & 0xff , 0
} ;
for ( V_63 = 0 ; V_63 < V_30 ; ) {
for ( ; V_63 < F_73 ( V_30 , 32 ) ; V_63 ++ )
V_11 [ V_63 ] = V_63 ;
V_84 = V_63 ;
for ( ; V_63 < F_73 ( V_30 , V_84 + 32 ) ; V_63 += 2 ) {
T_4 * V_91 = ( T_4 * ) & V_11 [ V_63 ] ;
* V_91 = ( V_63 & 0x02 ) ? 0x0000 : 0xffff ;
}
V_84 = V_63 ;
for ( ; V_63 < F_73 ( V_30 , V_84 + 32 ) ; V_63 += 2 ) {
T_4 * V_91 = ( T_4 * ) & V_11 [ V_63 ] ;
* V_91 = ( V_63 & 0x02 ) ? 0x5555 : 0xaaaa ;
}
V_84 = V_63 ;
for ( ; V_63 < F_73 ( V_30 , V_84 + 32 ) ; V_63 += 4 ) {
T_5 * V_91 = ( unsigned int * ) & V_11 [ V_63 ] ;
T_5 V_92 = ( V_86 & 0x80000000 ) ? 1 : 0 ;
* V_91 = V_86 ;
V_86 = ( V_86 << 1 ) | V_92 ;
}
}
for ( V_85 = 0 ; V_85 < V_83 ; V_85 ++ ) {
V_5 = F_2 ( V_7 , V_87 , V_93 ,
V_11 , V_30 , & V_14 ) ;
if( V_5 || ! F_74 ( V_7 ) ) {
F_75 ( V_7 , V_94 ) ;
if ( F_76 ( & V_14 )
&& V_14 . V_25 == V_95
&& V_14 . V_96 == 0x24 && V_14 . V_97 == 0x00 )
return V_98 ;
F_77 ( V_99 , V_7 , L_8 , V_5 ) ;
return V_100 ;
}
memset ( V_82 , 0 , V_30 ) ;
F_2 ( V_7 , V_89 , V_101 ,
V_82 , V_30 , NULL ) ;
F_75 ( V_7 , V_94 ) ;
if ( memcmp ( V_11 , V_82 , V_30 ) != 0 )
return V_100 ;
}
return V_102 ;
}
static enum V_81
F_78 ( struct V_6 * V_7 , T_3 * V_11 ,
T_3 * V_82 , const int V_83 )
{
int V_85 , V_5 ;
const int V_30 = V_7 -> V_103 ;
const char V_104 [] = {
V_105 , 0 , 0 , 0 , V_30 , 0
} ;
for ( V_85 = 0 ; V_85 < V_83 ; V_85 ++ ) {
memset ( V_82 , 0 , V_30 ) ;
V_5 = F_2 ( V_7 , V_104 , V_101 ,
V_82 , V_30 , NULL ) ;
if( V_5 || ! F_74 ( V_7 ) ) {
F_75 ( V_7 , V_94 ) ;
return V_100 ;
}
if ( V_82 == V_11 ) {
V_82 += V_30 ;
-- V_85 ;
continue;
}
if ( memcmp ( V_11 , V_82 , V_30 ) != 0 )
return V_100 ;
}
return V_102 ;
}
static int
F_79 ( struct V_6 * V_7 , T_3 * V_11 )
{
int V_106 , V_5 ;
const char V_107 [] = {
V_108 , 0 , 0 , 0 , 0 , 0
} ;
const char V_109 [] = {
V_90 , 0x0b , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0
} ;
for ( V_106 = 0 ; ; V_106 ++ ) {
V_5 = F_2 ( V_7 , V_107 , V_110 ,
NULL , 0 , NULL ) ;
if( V_5 ) {
if( V_106 >= 3 )
return 0 ;
} else {
break;
}
}
V_5 = F_2 ( V_7 , V_109 ,
V_101 , V_11 , 4 , NULL ) ;
if ( V_5 )
return 0 ;
return V_11 [ 3 ] + ( ( V_11 [ 2 ] & 0x1f ) << 8 ) ;
}
static void
F_80 ( struct V_6 * V_7 , T_3 * V_11 )
{
struct V_67 * V_15 = F_63 ( V_7 -> V_111 -> V_41 ) ;
struct V_46 * V_47 = V_7 -> V_48 ;
struct V_37 * V_38 = V_7 -> V_111 ;
int V_30 = V_7 -> V_103 ;
int V_76 = F_32 ( V_47 ) ;
int V_112 = F_36 ( V_47 ) ;
F_81 ( V_113 , 0 ) ;
F_81 ( V_114 , 0 ) ;
if ( F_78 ( V_7 , V_11 , V_11 , V_115 )
!= V_102 ) {
F_82 ( V_99 , V_47 , L_9 ) ;
return;
}
if ( ! F_18 ( V_47 ) ) {
F_36 ( V_47 ) = 0 ;
V_112 = 0 ;
}
if ( V_15 -> V_71 -> V_116 && V_112 ) {
V_15 -> V_71 -> V_116 ( V_47 , 1 ) ;
if ( F_78 ( V_7 , V_11 ,
V_11 + V_30 ,
V_115 )
!= V_102 ) {
F_82 ( V_99 , V_47 , L_10 ) ;
V_15 -> V_71 -> V_116 ( V_47 , 0 ) ;
V_112 = 0 ;
if ( V_76 < 10 )
V_76 = 10 ;
}
}
if ( ! V_15 -> V_71 -> V_74 )
return;
if ( ! F_16 ( V_47 ) && ! F_20 ( V_47 ) )
return;
V_30 = - 1 ;
V_117:
F_81 ( V_113 , F_34 ( V_47 ) ) ;
F_81 ( V_58 , V_76 ) ;
if ( F_27 ( V_47 ) && F_41 ( V_47 ) ) {
F_81 ( V_118 , 1 ) ;
} else {
F_81 ( V_118 , 0 ) ;
}
if ( F_24 ( V_47 ) && F_38 ( V_47 ) &&
V_76 < 9 ) {
F_81 ( V_119 , 1 ) ;
F_81 ( V_120 , 1 ) ;
F_81 ( V_121 , 1 ) ;
F_81 ( V_122 , 1 ) ;
if ( V_76 == 8 )
F_81 ( V_123 , 1 ) ;
} else {
F_81 ( V_119 , 0 ) ;
}
if ( V_15 -> V_71 -> V_77 )
V_15 -> V_71 -> V_77 ( V_38 ) ;
if ( F_10 ( V_38 ) == V_124 ||
F_10 ( V_38 ) == V_125 ||
! F_20 ( V_47 ) ) {
F_81 ( V_126 , 0 ) ;
} else {
F_81 ( V_126 , 1 ) ;
}
F_81 ( V_114 , V_112 ) ;
F_83 ( V_7 , V_11 , V_11 + V_7 -> V_103 ,
F_78 ) ;
if ( V_15 -> V_71 -> V_127 )
V_15 -> V_71 -> V_127 ( V_47 ) ;
if ( V_30 == - 1 && F_39 ( V_47 ) )
V_30 = F_79 ( V_7 , V_11 ) ;
if ( V_30 <= 0 ) {
F_82 ( V_128 , V_47 , L_11 ) ;
return;
}
if ( V_30 > V_129 ) {
F_82 ( V_130 , V_47 , L_12 , V_30 , V_129 ) ;
V_30 = V_129 ;
}
if ( F_83 ( V_7 , V_11 , V_11 + V_30 ,
F_72 )
== V_98 ) {
V_30 = 0 ;
goto V_117;
}
}
void
F_54 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = V_7 -> V_48 ;
T_3 * V_11 ;
const int V_30 = V_129 * 2 ;
if ( F_84 ( F_48 ( V_47 ) ) )
return;
if ( F_84 ( F_85 ( V_7 ) ) )
return;
F_48 ( V_47 ) = 1 ;
V_11 = F_86 ( V_30 , V_131 ) ;
if ( F_84 ( ! V_11 ) )
goto V_132;
if ( F_84 ( F_87 ( V_7 ) ) )
goto V_133;
F_88 ( V_47 ) ;
F_47 ( V_47 ) = 1 ;
F_89 ( & F_51 ( V_47 ) ) ;
F_82 ( V_128 , V_47 , L_13 ) ;
F_80 ( V_7 , V_11 ) ;
F_82 ( V_128 , V_47 , L_14 ) ;
F_90 ( & F_51 ( V_47 ) ) ;
F_47 ( V_47 ) = 0 ;
F_91 ( V_47 ) ;
F_49 ( V_47 ) = 1 ;
V_133:
F_92 ( V_11 ) ;
V_132:
F_48 ( V_47 ) = 0 ;
F_93 ( V_7 ) ;
}
static void
F_94 ( struct V_134 * V_135 )
{
struct V_136 * V_137 =
F_95 ( V_135 , struct V_136 , V_135 ) ;
struct V_6 * V_7 = V_137 -> V_7 ;
F_92 ( V_137 ) ;
F_54 ( V_7 ) ;
F_47 ( V_7 -> V_48 ) = 0 ;
F_93 ( V_7 ) ;
}
void
F_96 ( struct V_6 * V_7 )
{
struct V_136 * V_137 =
F_97 ( sizeof( struct V_136 ) , V_138 ) ;
if ( F_84 ( ! V_137 ) )
return;
if ( F_84 ( F_47 ( V_7 -> V_48 ) ) ) {
F_92 ( V_137 ) ;
return;
}
F_47 ( V_7 -> V_48 ) = 1 ;
if ( F_84 ( F_85 ( V_7 ) ) ) {
F_92 ( V_137 ) ;
F_47 ( V_7 -> V_48 ) = 0 ;
return;
}
F_98 ( & V_137 -> V_135 , F_94 ) ;
V_137 -> V_7 = V_7 ;
F_99 ( & V_137 -> V_135 ) ;
}
void F_100 ( struct V_46 * V_47 )
{
struct V_68 * V_69 ;
V_69 = (struct V_68 * ) & V_47 -> V_70 ;
if ( V_69 -> V_113 > 0 && V_69 -> V_58 > 0 ) {
unsigned int V_59 , V_139 ;
char * V_140 = L_15 ;
char V_141 [ 8 ] ;
if ( V_69 -> V_58 <= V_60 ) {
V_59 = V_61 [ V_69 -> V_58 ] ;
switch ( V_69 -> V_58 ) {
case 7 : V_140 = L_16 ; break;
case 8 : V_140 = L_17 ; break;
case 9 : V_140 = L_18 ; break;
case 10 :
case 11 : V_140 = L_19 ; break;
case 12 : V_140 = L_20 ; break;
}
} else {
V_59 = V_69 -> V_58 * 4000 ;
if ( V_69 -> V_58 < 25 )
V_140 = L_20 ;
else if ( V_69 -> V_58 < 50 )
V_140 = L_21 ;
else
V_140 = L_22 ;
}
V_139 = ( 10000000 + V_59 / 2 ) / V_59 ;
if ( V_69 -> V_114 )
V_139 *= 2 ;
F_1 ( V_141 , V_59 , 1000 ) ;
F_26 ( & V_47 -> V_35 ,
L_23 ,
V_140 , V_69 -> V_114 ? L_24 : L_25 , V_139 / 10 , V_139 % 10 ,
V_69 -> V_126 ? L_26 : L_27 ,
V_69 -> V_119 ? L_28 : L_25 ,
V_69 -> V_118 ? L_29 : L_25 ,
V_69 -> V_120 ? L_30 : L_25 ,
V_69 -> V_122 ? L_31 : L_25 ,
V_69 -> V_121 ? L_32 : L_25 ,
V_69 -> V_123 ? L_33 : L_25 ,
V_69 -> V_142 ? L_34 : L_25 ,
V_141 , V_69 -> V_113 ) ;
} else {
F_26 ( & V_47 -> V_35 , L_35 ,
V_69 -> V_114 ? L_36 : L_25 ) ;
}
}
int F_101 ( unsigned char * V_143 , int V_114 )
{
V_143 [ 0 ] = V_144 ;
V_143 [ 1 ] = 2 ;
V_143 [ 2 ] = V_145 ;
V_143 [ 3 ] = V_114 ;
return 4 ;
}
int F_102 ( unsigned char * V_143 , int V_58 , int V_113 )
{
V_143 [ 0 ] = V_144 ;
V_143 [ 1 ] = 3 ;
V_143 [ 2 ] = V_146 ;
V_143 [ 3 ] = V_58 ;
V_143 [ 4 ] = V_113 ;
return 5 ;
}
int F_103 ( unsigned char * V_143 , int V_58 , int V_113 ,
int V_114 , int V_147 )
{
V_143 [ 0 ] = V_144 ;
V_143 [ 1 ] = 6 ;
V_143 [ 2 ] = V_148 ;
V_143 [ 3 ] = V_58 ;
V_143 [ 4 ] = 0 ;
V_143 [ 5 ] = V_113 ;
V_143 [ 6 ] = V_114 ;
V_143 [ 7 ] = V_147 ;
return 8 ;
}
int F_104 ( unsigned char * V_143 , struct V_149 * V_8 )
{
if ( V_8 -> V_150 & V_151 ) {
* V_143 ++ = V_152 ;
* V_143 ++ = V_8 -> V_153 -> V_154 ;
return 2 ;
}
return 0 ;
}
static void F_105 ( const unsigned char * V_143 , int V_155 , int V_156 , int V_114 )
{
if ( V_155 ) {
char V_56 [ 20 ] ;
F_58 ( V_56 , V_143 [ V_155 ] ) ;
F_106 ( L_37 , V_56 ) ;
}
if ( V_156 )
F_106 ( L_38 , V_143 [ V_156 ] ) ;
if ( V_114 )
F_106 ( L_39 , 8 << V_143 [ V_114 ] ) ;
}
static void F_107 ( const unsigned char * V_143 , int V_157 , const char * V_158 )
{
int V_82 = ( V_143 [ V_157 ] << 24 ) | ( V_143 [ V_157 + 1 ] << 16 ) | ( V_143 [ V_157 + 2 ] << 8 ) |
V_143 [ V_157 + 3 ] ;
F_106 ( L_40 , V_158 , V_82 ) ;
}
int F_108 ( const unsigned char * V_143 )
{
int V_30 = 1 , V_15 ;
if ( V_143 [ 0 ] == V_144 ) {
V_30 = 2 + V_143 [ 1 ] ;
if ( V_30 == 2 )
V_30 += 256 ;
if ( V_143 [ 2 ] < F_6 ( V_159 ) )
F_106 ( L_41 , V_159 [ V_143 [ 2 ] ] ) ;
else
F_106 ( L_42 ,
( int ) V_143 [ 2 ] ) ;
switch ( V_143 [ 2 ] ) {
case V_160 :
F_107 ( V_143 , 3 , L_43 ) ;
break;
case V_146 :
F_105 ( V_143 , 3 , 4 , 0 ) ;
break;
case V_145 :
F_105 ( V_143 , 0 , 0 , 3 ) ;
break;
case V_148 :
F_105 ( V_143 , 3 , 5 , 6 ) ;
break;
case V_161 :
F_107 ( V_143 , 3 , L_44 ) ;
F_107 ( V_143 , 7 , L_45 ) ;
break;
default:
for ( V_15 = 2 ; V_15 < V_30 ; ++ V_15 )
F_106 ( L_46 , V_143 [ V_15 ] ) ;
}
} else if ( V_143 [ 0 ] & 0x80 ) {
F_106 ( L_47 ,
( V_143 [ 0 ] & 0x40 ) ? L_25 : L_48 ,
( V_143 [ 0 ] & 0x20 ) ? L_49 : L_50 ,
V_143 [ 0 ] & 0x7 ) ;
} else if ( V_143 [ 0 ] < 0x1f ) {
if ( V_143 [ 0 ] < F_6 ( V_162 ) && V_162 [ V_143 [ 0 ] ] )
F_106 ( L_41 , V_162 [ V_143 [ 0 ] ] ) ;
else
F_106 ( L_51 , V_143 [ 0 ] ) ;
} else if ( V_143 [ 0 ] == 0x55 ) {
F_106 ( L_52 ) ;
} else if ( V_143 [ 0 ] <= 0x2f ) {
if ( ( V_143 [ 0 ] - 0x20 ) < F_6 ( V_163 ) )
F_106 ( L_53 , V_163 [ V_143 [ 0 ] - 0x20 ] ,
V_143 [ 1 ] ) ;
else
F_106 ( L_54 ,
V_143 [ 0 ] , V_143 [ 1 ] ) ;
V_30 = 2 ;
} else
F_106 ( L_55 ) ;
return V_30 ;
}
int F_108 ( const unsigned char * V_143 )
{
int V_30 = 1 , V_15 ;
if ( V_143 [ 0 ] == V_144 ) {
V_30 = 2 + V_143 [ 1 ] ;
if ( V_30 == 2 )
V_30 += 256 ;
for ( V_15 = 0 ; V_15 < V_30 ; ++ V_15 )
F_106 ( L_46 , V_143 [ V_15 ] ) ;
} else if ( V_143 [ 0 ] & 0x80 ) {
F_106 ( L_46 , V_143 [ 0 ] ) ;
} else if ( ( V_143 [ 0 ] < 0x1f ) || ( V_143 [ 0 ] == 0x55 ) ) {
F_106 ( L_46 , V_143 [ 0 ] ) ;
} else if ( V_143 [ 0 ] <= 0x2f ) {
F_106 ( L_56 , V_143 [ 0 ] , V_143 [ 1 ] ) ;
V_30 = 2 ;
} else
F_106 ( L_46 , V_143 [ 0 ] ) ;
return V_30 ;
}
static int F_109 ( struct V_39 * V_40 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 ;
struct V_67 * V_15 ;
if ( ! F_53 ( V_35 ) )
return 0 ;
V_7 = F_14 ( V_35 ) ;
V_38 = V_7 -> V_111 ;
if ( ! V_38 -> V_41 || V_38 -> V_41 -> V_42 . V_43 . V_44
!= & V_45 . V_44 )
return 0 ;
V_15 = F_63 ( V_38 -> V_41 ) ;
if ( V_15 -> V_71 -> V_164 && V_15 -> V_71 -> V_164 ( V_7 -> V_48 ) )
return 0 ;
return 1 ;
}
static int F_110 ( struct V_39 * V_40 ,
struct V_34 * V_35 )
{
struct V_37 * V_38 ;
struct V_46 * V_47 ;
struct V_67 * V_15 ;
if ( ! F_111 ( V_35 ) )
return 0 ;
V_38 = F_9 ( V_35 -> V_66 ) ;
if ( ! V_38 -> V_41 || V_38 -> V_41 -> V_42 . V_43 . V_44
!= & V_45 . V_44 )
return 0 ;
V_15 = F_63 ( V_38 -> V_41 ) ;
V_47 = F_30 ( V_35 ) ;
if ( V_15 -> V_71 -> V_164 && V_15 -> V_71 -> V_164 ( V_47 ) )
return 0 ;
return & V_15 -> V_165 . V_166 . V_43 == V_40 ;
}
static int F_112 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_167 * V_168 = & V_36 -> V_168 ;
struct V_37 * V_38 = F_68 ( V_36 ) ;
struct V_67 * V_169 = F_63 ( V_38 -> V_41 ) ;
struct V_170 * V_55 = & V_171 . V_55 ;
int V_172 = 0 ;
if ( V_169 -> V_71 -> V_78 )
V_172 = F_113 ( V_168 , V_55 , V_55 -> V_173 | V_174 ) ;
return V_172 ;
}
static T_6 F_114 ( struct V_167 * V_168 ,
struct V_170 * V_55 , int V_15 )
{
struct V_34 * V_36 = F_95 ( V_168 , struct V_34 , V_168 ) ;
struct V_46 * V_47 = F_56 ( V_36 ) ;
struct V_37 * V_38 = F_68 ( V_36 ) ;
struct V_67 * V_169 = F_63 ( V_38 -> V_41 ) ;
if ( V_55 == & V_175 . V_55 &&
F_16 ( V_47 ) )
return F_115 ( V_58 ) ;
else if ( V_55 == & V_176 . V_55 &&
F_16 ( V_47 ) )
return F_115 ( V_58 ) ;
else if ( V_55 == & V_177 . V_55 &&
F_16 ( V_47 ) )
return F_115 ( V_113 ) ;
else if ( V_55 == & V_178 . V_55 &&
F_16 ( V_47 ) )
return F_115 ( V_113 ) ;
else if ( V_55 == & V_179 . V_55 &&
F_18 ( V_47 ) )
return F_115 ( V_114 ) ;
else if ( V_55 == & V_180 . V_55 &&
F_18 ( V_47 ) )
return F_115 ( V_114 ) ;
else if ( V_55 == & V_181 . V_55 &&
F_24 ( V_47 ) )
return F_115 ( V_119 ) ;
else if ( V_55 == & V_182 . V_55 &&
F_24 ( V_47 ) )
return F_115 ( V_119 ) ;
else if ( V_55 == & V_183 . V_55 &&
F_20 ( V_47 ) )
return F_115 ( V_126 ) ;
else if ( V_55 == & V_184 . V_55 &&
F_27 ( V_47 ) )
return F_115 ( V_118 ) ;
else if ( V_55 == & V_185 . V_55 &&
F_27 ( V_47 ) )
return F_115 ( V_118 ) ;
else if ( V_55 == & V_186 . V_55 &&
F_24 ( V_47 ) )
return F_115 ( V_121 ) ;
else if ( V_55 == & V_187 . V_55 &&
F_24 ( V_47 ) )
return F_115 ( V_120 ) ;
else if ( V_55 == & V_188 . V_55 &&
F_24 ( V_47 ) )
return F_115 ( V_122 ) ;
else if ( V_55 == & V_189 . V_55 &&
F_24 ( V_47 ) )
return F_115 ( V_123 ) ;
else if ( V_55 == & V_190 . V_55 &&
F_24 ( V_47 ) )
return F_115 ( V_142 ) ;
else if ( V_55 == & V_191 . V_55 )
return V_174 ;
return 0 ;
}
static int F_116 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_167 * V_168 = & V_36 -> V_168 ;
F_117 ( V_168 , & V_192 ) ;
return 0 ;
}
struct V_193 *
F_118 ( struct V_194 * V_195 )
{
struct V_67 * V_15 = F_86 ( sizeof( struct V_67 ) ,
V_131 ) ;
if ( F_84 ( ! V_15 ) )
return NULL ;
V_15 -> V_165 . V_166 . V_43 . V_44 = & V_196 . V_44 ;
V_15 -> V_165 . V_166 . V_43 . V_197 = & V_192 ;
V_15 -> V_165 . V_166 . V_43 . V_198 = F_110 ;
F_119 ( & V_15 -> V_165 . V_166 ) ;
V_15 -> V_165 . V_199 = sizeof( struct V_68 ) ;
V_15 -> V_165 . V_42 . V_43 . V_44 = & V_45 . V_44 ;
V_15 -> V_165 . V_42 . V_43 . V_197 = & V_200 ;
V_15 -> V_165 . V_42 . V_43 . V_198 = F_11 ;
F_119 ( & V_15 -> V_165 . V_42 ) ;
V_15 -> V_165 . V_201 = sizeof( struct V_202 ) ;
V_15 -> V_71 = V_195 ;
return & V_15 -> V_165 ;
}
void F_120 ( struct V_193 * V_165 )
{
struct V_67 * V_15 = F_63 ( V_165 ) ;
F_121 ( & V_15 -> V_165 . V_166 ) ;
F_121 ( & V_15 -> V_165 . V_42 ) ;
F_92 ( V_15 ) ;
}
static T_7 int F_122 ( void )
{
int error = F_123 ( V_51 ,
L_57 ) ;
if ( ! error ) {
int V_15 ;
for ( V_15 = 0 ; V_203 [ V_15 ] . V_204 ; V_15 ++ )
F_124 ( 1 ,
V_203 [ V_15 ] . V_204 ,
V_203 [ V_15 ] . V_205 ,
NULL ,
V_203 [ V_15 ] . V_150 ,
V_51 ) ;
}
error = F_125 ( & V_196 ) ;
if ( error )
return error ;
error = F_126 ( & V_206 ) ;
return F_125 ( & V_45 ) ;
}
static void T_8 F_127 ( void )
{
F_128 ( & V_196 ) ;
F_129 ( & V_206 ) ;
F_128 ( & V_45 ) ;
F_130 ( V_51 ) ;
}
