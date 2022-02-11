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
for( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
V_5 = F_3 ( V_7 , V_8 , V_10 , V_11 , V_12 ,
V_16 , V_19 , 1 ,
V_20 |
V_21 |
V_22 ,
NULL ) ;
if ( F_4 ( V_5 ) & V_23 ) {
struct V_13 V_24 ;
if ( ! V_14 )
V_14 = & V_24 ;
if ( F_5 ( V_16 , V_17 ,
V_14 )
&& V_14 -> V_25 == V_26 )
continue;
}
break;
}
return V_5 ;
}
static inline const char * F_6 ( enum V_27 type )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < F_7 ( V_28 ) ; V_15 ++ ) {
if ( type == V_28 [ V_15 ] . V_2 )
return V_28 [ V_15 ] . V_29 ;
}
return NULL ;
}
static inline enum V_27 F_8 ( const char * V_29 )
{
int V_15 , V_30 ;
for ( V_15 = 0 ; V_15 < F_7 ( V_28 ) ; V_15 ++ ) {
V_30 = strlen ( V_28 [ V_15 ] . V_29 ) ;
if ( strncmp ( V_29 , V_28 [ V_15 ] . V_29 , V_30 ) == 0 &&
( V_29 [ V_30 ] == '\n' || V_29 [ V_30 ] == '\0' ) )
return V_28 [ V_15 ] . V_2 ;
}
return V_31 ;
}
static int F_9 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_37 * V_38 = F_10 ( V_35 ) ;
F_11 ( V_38 ) = V_31 ;
return 0 ;
}
static int F_12 ( struct V_39 * V_40 ,
struct V_34 * V_35 )
{
struct V_37 * V_38 ;
if ( ! F_13 ( V_35 ) )
return 0 ;
V_38 = F_10 ( V_35 ) ;
if ( ! V_38 -> V_41 || V_38 -> V_41 -> V_42 . V_43 . V_44
!= & V_45 . V_44 )
return 0 ;
return & V_38 -> V_41 -> V_42 . V_43 == V_40 ;
}
static int F_14 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_6 * V_7 = F_15 ( V_35 ) ;
struct V_46 * V_47 = V_7 -> V_48 ;
unsigned V_49 = F_16 ( V_7 , & V_7 -> V_50 [ 8 ] ,
& V_7 -> V_50 [ 16 ] ,
V_51 ) ;
F_17 ( V_47 ) = F_18 ( V_7 ) ;
F_19 ( V_47 ) = F_20 ( V_7 ) ;
F_21 ( V_47 ) = F_22 ( V_7 ) ;
F_23 ( V_47 ) = F_24 ( V_7 ) ;
F_25 ( V_47 ) = F_26 ( V_7 ) ;
if ( V_49 & V_52 ) {
F_27 ( V_35 , L_2 ) ;
F_25 ( V_47 ) = 0 ;
}
F_28 ( V_47 ) = F_29 ( V_7 ) ;
return 0 ;
}
static int F_30 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_46 * V_47 = F_31 ( V_35 ) ;
F_32 ( V_47 ) = - 1 ;
F_33 ( V_47 ) = 0 ;
F_34 ( V_47 ) = 0 ;
F_35 ( V_47 ) = 255 ;
F_36 ( V_47 ) = 0 ;
F_37 ( V_47 ) = 1 ;
F_38 ( V_47 ) = 0 ;
F_39 ( V_47 ) = 1 ;
F_40 ( V_47 ) = 0 ;
F_41 ( V_47 ) = 0 ;
F_42 ( V_47 ) = 1 ;
F_43 ( V_47 ) = 0 ;
F_44 ( V_47 ) = 0 ;
F_45 ( V_47 ) = 0 ;
F_46 ( V_47 ) = 0 ;
F_47 ( V_47 ) = 0 ;
F_48 ( V_47 ) = 0 ;
F_49 ( V_47 ) = 0 ;
F_50 ( V_47 ) = 0 ;
F_51 ( & F_52 ( V_47 ) ) ;
return 0 ;
}
static int F_53 ( struct V_34 * V_35 , void * V_53 )
{
if ( ! F_54 ( V_35 ) )
return 0 ;
F_55 ( F_15 ( V_35 ) ) ;
return 1 ;
}
static T_1
F_56 ( struct V_34 * V_35 , struct V_54 * V_55 ,
const char * V_56 , T_2 V_57 )
{
struct V_46 * V_47 = F_57 ( V_35 ) ;
F_58 ( & V_47 -> V_35 , NULL , F_53 ) ;
return V_57 ;
}
static int F_59 ( char * V_56 , int V_58 )
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
F_60 ( char * V_56 , int V_58 )
{
int V_30 = F_59 ( V_56 , V_58 ) ;
V_56 [ V_30 ++ ] = '\n' ;
V_56 [ V_30 ] = '\0' ;
return V_30 ;
}
static T_1
F_61 ( struct V_34 * V_35 , const char * V_56 ,
T_2 V_57 , int * V_62 )
{
int V_63 , V_59 , V_58 = - 1 ;
char * V_64 ;
V_59 = F_62 ( V_56 , & V_64 , 10 ) * 1000 ;
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
F_63 ( struct V_34 * V_35 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_46 * V_47 = F_57 ( V_35 ) ;
struct V_37 * V_38 = F_10 ( V_47 -> V_35 . V_66 ) ;
struct V_67 * V_15 = F_64 ( V_38 -> V_41 ) ;
struct V_68 * V_69 =
(struct V_68 * ) & V_47 -> V_70 ;
if ( V_15 -> V_71 -> V_72 )
V_15 -> V_71 -> V_72 ( V_47 ) ;
return F_60 ( V_56 , V_69 -> V_58 ) ;
}
static T_1
F_65 ( struct V_34 * V_36 , struct V_54 * V_55 ,
const char * V_56 , T_2 V_57 )
{
struct V_46 * V_47 = F_57 ( V_36 ) ;
struct V_37 * V_38 = F_10 ( V_47 -> V_35 . V_66 ) ;
struct V_67 * V_15 = F_64 ( V_38 -> V_41 ) ;
struct V_68 * V_69 =
(struct V_68 * ) & V_47 -> V_70 ;
int V_58 , V_73 ;
if ( ! V_15 -> V_71 -> V_74 )
return - V_75 ;
V_73 = F_61 ( V_36 , V_56 , V_57 , & V_58 ) ;
if ( V_58 < V_69 -> V_76 )
V_58 = V_69 -> V_76 ;
V_15 -> V_71 -> V_74 ( V_47 , V_58 ) ;
return V_73 ;
}
static T_1
F_66 ( struct V_34 * V_36 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_46 * V_47 = F_57 ( V_36 ) ;
struct V_37 * V_38 = F_10 ( V_47 -> V_35 . V_66 ) ;
struct V_67 * V_15 = F_64 ( V_38 -> V_41 ) ;
struct V_68 * V_69 =
(struct V_68 * ) & V_47 -> V_70 ;
if ( ! V_15 -> V_71 -> V_74 )
return - V_75 ;
return F_60 ( V_56 , V_69 -> V_76 ) ;
}
static T_1
F_67 ( struct V_34 * V_36 ,
struct V_54 * V_55 ,
const char * V_56 , T_2 V_57 )
{
struct V_46 * V_47 = F_57 ( V_36 ) ;
struct V_68 * V_69 =
(struct V_68 * ) & V_47 -> V_70 ;
return F_61 ( V_36 , V_56 , V_57 ,
& V_69 -> V_76 ) ;
}
static T_1 F_68 ( struct V_34 * V_36 ,
struct V_54 * V_55 ,
char * V_56 )
{
struct V_37 * V_38 = F_69 ( V_36 ) ;
struct V_67 * V_15 = F_64 ( V_38 -> V_41 ) ;
if ( V_15 -> V_71 -> V_77 )
V_15 -> V_71 -> V_77 ( V_38 ) ;
return sprintf ( V_56 , L_4 , F_6 ( F_11 ( V_38 ) ) ) ;
}
static T_1 F_70 ( struct V_34 * V_35 ,
struct V_54 * V_55 ,
const char * V_56 , T_2 V_57 )
{
struct V_37 * V_38 = F_69 ( V_35 ) ;
struct V_67 * V_15 = F_64 ( V_38 -> V_41 ) ;
enum V_27 type = F_8 ( V_56 ) ;
if ( ! V_15 -> V_71 -> V_78 )
return - V_75 ;
if ( type != V_31 )
V_15 -> V_71 -> V_78 ( V_38 , type ) ;
return V_57 ;
}
static enum V_79
F_71 ( struct V_6 * V_7 , T_3 * V_11 ,
T_3 * V_80 , const int V_81 )
{
int V_30 = V_80 - V_11 ;
int V_63 , V_82 , V_83 , V_5 ;
unsigned int V_84 = 0x0000ffff ;
struct V_13 V_14 ;
const char V_85 [] = {
V_86 , 0x0a , 0 , 0 , 0 , 0 , 0 , V_30 >> 8 , V_30 & 0xff , 0
} ;
const char V_87 [] = {
V_88 , 0x0a , 0 , 0 , 0 , 0 , 0 , V_30 >> 8 , V_30 & 0xff , 0
} ;
for ( V_63 = 0 ; V_63 < V_30 ; ) {
for ( ; V_63 < F_72 ( V_30 , 32 ) ; V_63 ++ )
V_11 [ V_63 ] = V_63 ;
V_82 = V_63 ;
for ( ; V_63 < F_72 ( V_30 , V_82 + 32 ) ; V_63 += 2 ) {
T_4 * V_89 = ( T_4 * ) & V_11 [ V_63 ] ;
* V_89 = ( V_63 & 0x02 ) ? 0x0000 : 0xffff ;
}
V_82 = V_63 ;
for ( ; V_63 < F_72 ( V_30 , V_82 + 32 ) ; V_63 += 2 ) {
T_4 * V_89 = ( T_4 * ) & V_11 [ V_63 ] ;
* V_89 = ( V_63 & 0x02 ) ? 0x5555 : 0xaaaa ;
}
V_82 = V_63 ;
for ( ; V_63 < F_72 ( V_30 , V_82 + 32 ) ; V_63 += 4 ) {
T_5 * V_89 = ( unsigned int * ) & V_11 [ V_63 ] ;
T_5 V_90 = ( V_84 & 0x80000000 ) ? 1 : 0 ;
* V_89 = V_84 ;
V_84 = ( V_84 << 1 ) | V_90 ;
}
}
for ( V_83 = 0 ; V_83 < V_81 ; V_83 ++ ) {
V_5 = F_2 ( V_7 , V_85 , V_91 ,
V_11 , V_30 , & V_14 ) ;
if( V_5 || ! F_73 ( V_7 ) ) {
F_74 ( V_7 , V_92 ) ;
if ( F_75 ( & V_14 )
&& V_14 . V_25 == V_93
&& V_14 . V_94 == 0x24 && V_14 . V_95 == 0x00 )
return V_96 ;
F_76 ( V_97 , V_7 , L_5 , V_5 ) ;
return V_98 ;
}
memset ( V_80 , 0 , V_30 ) ;
F_2 ( V_7 , V_87 , V_99 ,
V_80 , V_30 , NULL ) ;
F_74 ( V_7 , V_92 ) ;
if ( memcmp ( V_11 , V_80 , V_30 ) != 0 )
return V_98 ;
}
return V_100 ;
}
static enum V_79
F_77 ( struct V_6 * V_7 , T_3 * V_11 ,
T_3 * V_80 , const int V_81 )
{
int V_83 , V_5 ;
const int V_30 = V_7 -> V_101 ;
const char V_102 [] = {
V_103 , 0 , 0 , 0 , V_30 , 0
} ;
for ( V_83 = 0 ; V_83 < V_81 ; V_83 ++ ) {
memset ( V_80 , 0 , V_30 ) ;
V_5 = F_2 ( V_7 , V_102 , V_99 ,
V_80 , V_30 , NULL ) ;
if( V_5 || ! F_73 ( V_7 ) ) {
F_74 ( V_7 , V_92 ) ;
return V_98 ;
}
if ( V_80 == V_11 ) {
V_80 += V_30 ;
-- V_83 ;
continue;
}
if ( memcmp ( V_11 , V_80 , V_30 ) != 0 )
return V_98 ;
}
return V_100 ;
}
static int
F_78 ( struct V_6 * V_7 , T_3 * V_11 )
{
int V_104 , V_5 ;
const char V_105 [] = {
V_106 , 0 , 0 , 0 , 0 , 0
} ;
const char V_107 [] = {
V_88 , 0x0b , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0
} ;
for ( V_104 = 0 ; ; V_104 ++ ) {
V_5 = F_2 ( V_7 , V_105 , V_108 ,
NULL , 0 , NULL ) ;
if( V_5 ) {
if( V_104 >= 3 )
return 0 ;
} else {
break;
}
}
V_5 = F_2 ( V_7 , V_107 ,
V_99 , V_11 , 4 , NULL ) ;
if ( V_5 )
return 0 ;
return V_11 [ 3 ] + ( ( V_11 [ 2 ] & 0x1f ) << 8 ) ;
}
static void
F_79 ( struct V_6 * V_7 , T_3 * V_11 )
{
struct V_67 * V_15 = F_64 ( V_7 -> V_109 -> V_41 ) ;
struct V_46 * V_47 = V_7 -> V_48 ;
struct V_37 * V_38 = V_7 -> V_109 ;
int V_30 = V_7 -> V_101 ;
int V_76 = F_33 ( V_47 ) ;
int V_110 = F_37 ( V_47 ) ;
F_80 ( V_111 , 0 ) ;
F_80 ( V_112 , 0 ) ;
if ( F_77 ( V_7 , V_11 , V_11 , V_113 )
!= V_100 ) {
F_81 ( V_97 , V_47 , L_6 ) ;
return;
}
if ( ! F_19 ( V_47 ) ) {
F_37 ( V_47 ) = 0 ;
V_110 = 0 ;
}
if ( V_15 -> V_71 -> V_114 && V_110 ) {
V_15 -> V_71 -> V_114 ( V_47 , 1 ) ;
if ( F_77 ( V_7 , V_11 ,
V_11 + V_30 ,
V_113 )
!= V_100 ) {
F_81 ( V_97 , V_47 , L_7 ) ;
V_15 -> V_71 -> V_114 ( V_47 , 0 ) ;
V_110 = 0 ;
if ( V_76 < 10 )
V_76 = 10 ;
}
}
if ( ! V_15 -> V_71 -> V_74 )
return;
if ( ! F_17 ( V_47 ) && ! F_21 ( V_47 ) )
return;
V_30 = - 1 ;
V_115:
F_80 ( V_111 , F_35 ( V_47 ) ) ;
F_80 ( V_58 , V_76 ) ;
if ( F_28 ( V_47 ) && F_42 ( V_47 ) ) {
F_80 ( V_116 , 1 ) ;
} else {
F_80 ( V_116 , 0 ) ;
}
if ( F_25 ( V_47 ) && F_39 ( V_47 ) &&
V_76 < 9 ) {
F_80 ( V_117 , 1 ) ;
F_80 ( V_118 , 1 ) ;
F_80 ( V_119 , 1 ) ;
F_80 ( V_120 , 1 ) ;
if ( V_76 == 8 )
F_80 ( V_121 , 1 ) ;
} else {
F_80 ( V_117 , 0 ) ;
}
if ( V_15 -> V_71 -> V_77 )
V_15 -> V_71 -> V_77 ( V_38 ) ;
if ( F_11 ( V_38 ) == V_122 ||
F_11 ( V_38 ) == V_123 ||
! F_21 ( V_47 ) ) {
F_80 ( V_124 , 0 ) ;
} else {
F_80 ( V_124 , 1 ) ;
}
F_80 ( V_112 , V_110 ) ;
F_82 ( V_7 , V_11 , V_11 + V_7 -> V_101 ,
F_77 ) ;
if ( V_15 -> V_71 -> V_125 )
V_15 -> V_71 -> V_125 ( V_47 ) ;
if ( V_30 == - 1 && F_40 ( V_47 ) )
V_30 = F_78 ( V_7 , V_11 ) ;
if ( V_30 <= 0 ) {
F_81 ( V_126 , V_47 , L_8 ) ;
return;
}
if ( V_30 > V_127 ) {
F_81 ( V_128 , V_47 , L_9 , V_30 , V_127 ) ;
V_30 = V_127 ;
}
if ( F_82 ( V_7 , V_11 , V_11 + V_30 ,
F_71 )
== V_96 ) {
V_30 = 0 ;
goto V_115;
}
}
void
F_55 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = V_7 -> V_48 ;
T_3 * V_11 ;
const int V_30 = V_127 * 2 ;
if ( F_83 ( F_84 ( V_7 ) ) )
return;
if ( F_83 ( F_49 ( V_47 ) ) )
return;
F_49 ( V_47 ) = 1 ;
V_11 = F_85 ( V_30 , V_129 ) ;
if ( F_83 ( ! V_11 ) )
goto V_130;
if ( F_83 ( F_86 ( V_7 ) ) )
goto V_131;
F_87 ( V_47 ) ;
F_48 ( V_47 ) = 1 ;
F_88 ( & F_52 ( V_47 ) ) ;
F_81 ( V_126 , V_47 , L_10 ) ;
F_79 ( V_7 , V_11 ) ;
F_81 ( V_126 , V_47 , L_11 ) ;
F_89 ( & F_52 ( V_47 ) ) ;
F_48 ( V_47 ) = 0 ;
F_90 ( V_47 ) ;
F_50 ( V_47 ) = 1 ;
V_131:
F_91 ( V_11 ) ;
V_130:
F_49 ( V_47 ) = 0 ;
F_92 ( V_7 ) ;
}
static void
F_93 ( struct V_132 * V_133 )
{
struct V_134 * V_135 =
F_94 ( V_133 , struct V_134 , V_133 ) ;
struct V_6 * V_7 = V_135 -> V_7 ;
F_91 ( V_135 ) ;
F_55 ( V_7 ) ;
F_48 ( V_7 -> V_48 ) = 0 ;
F_92 ( V_7 ) ;
}
void
F_95 ( struct V_6 * V_7 )
{
struct V_134 * V_135 =
F_96 ( sizeof( struct V_134 ) , V_136 ) ;
if ( F_83 ( ! V_135 ) )
return;
if ( F_83 ( F_48 ( V_7 -> V_48 ) ) ) {
F_91 ( V_135 ) ;
return;
}
F_48 ( V_7 -> V_48 ) = 1 ;
if ( F_83 ( F_84 ( V_7 ) ) ) {
F_91 ( V_135 ) ;
F_48 ( V_7 -> V_48 ) = 0 ;
return;
}
F_97 ( & V_135 -> V_133 , F_93 ) ;
V_135 -> V_7 = V_7 ;
F_98 ( & V_135 -> V_133 ) ;
}
void F_99 ( struct V_46 * V_47 )
{
struct V_68 * V_69 ;
V_69 = (struct V_68 * ) & V_47 -> V_70 ;
if ( V_69 -> V_111 > 0 && V_69 -> V_58 > 0 ) {
unsigned int V_59 , V_137 ;
char * V_138 = L_12 ;
char V_139 [ 8 ] ;
if ( V_69 -> V_58 <= V_60 ) {
V_59 = V_61 [ V_69 -> V_58 ] ;
switch ( V_69 -> V_58 ) {
case 7 : V_138 = L_13 ; break;
case 8 : V_138 = L_14 ; break;
case 9 : V_138 = L_15 ; break;
case 10 :
case 11 : V_138 = L_16 ; break;
case 12 : V_138 = L_17 ; break;
}
} else {
V_59 = V_69 -> V_58 * 4000 ;
if ( V_69 -> V_58 < 25 )
V_138 = L_17 ;
else if ( V_69 -> V_58 < 50 )
V_138 = L_18 ;
else
V_138 = L_19 ;
}
V_137 = ( 10000000 + V_59 / 2 ) / V_59 ;
if ( V_69 -> V_112 )
V_137 *= 2 ;
F_1 ( V_139 , V_59 , 1000 ) ;
F_27 ( & V_47 -> V_35 ,
L_20 ,
V_138 , V_69 -> V_112 ? L_21 : L_22 , V_137 / 10 , V_137 % 10 ,
V_69 -> V_124 ? L_23 : L_24 ,
V_69 -> V_117 ? L_25 : L_22 ,
V_69 -> V_116 ? L_26 : L_22 ,
V_69 -> V_118 ? L_27 : L_22 ,
V_69 -> V_120 ? L_28 : L_22 ,
V_69 -> V_119 ? L_29 : L_22 ,
V_69 -> V_121 ? L_30 : L_22 ,
V_69 -> V_140 ? L_31 : L_22 ,
V_139 , V_69 -> V_111 ) ;
} else {
F_27 ( & V_47 -> V_35 , L_32 ,
V_69 -> V_112 ? L_33 : L_22 ) ;
}
}
int F_100 ( unsigned char * V_141 , int V_112 )
{
V_141 [ 0 ] = V_142 ;
V_141 [ 1 ] = 2 ;
V_141 [ 2 ] = V_143 ;
V_141 [ 3 ] = V_112 ;
return 4 ;
}
int F_101 ( unsigned char * V_141 , int V_58 , int V_111 )
{
V_141 [ 0 ] = V_142 ;
V_141 [ 1 ] = 3 ;
V_141 [ 2 ] = V_144 ;
V_141 [ 3 ] = V_58 ;
V_141 [ 4 ] = V_111 ;
return 5 ;
}
int F_102 ( unsigned char * V_141 , int V_58 , int V_111 ,
int V_112 , int V_145 )
{
V_141 [ 0 ] = V_142 ;
V_141 [ 1 ] = 6 ;
V_141 [ 2 ] = V_146 ;
V_141 [ 3 ] = V_58 ;
V_141 [ 4 ] = 0 ;
V_141 [ 5 ] = V_111 ;
V_141 [ 6 ] = V_112 ;
V_141 [ 7 ] = V_145 ;
return 8 ;
}
static void F_103 ( const unsigned char * V_141 , int V_147 , int V_148 , int V_112 )
{
if ( V_147 ) {
char V_56 [ 20 ] ;
F_59 ( V_56 , V_141 [ V_147 ] ) ;
F_104 ( L_34 , V_56 ) ;
}
if ( V_148 )
F_104 ( L_35 , V_141 [ V_148 ] ) ;
if ( V_112 )
F_104 ( L_36 , 8 << V_141 [ V_112 ] ) ;
}
static void F_105 ( const unsigned char * V_141 , int V_149 , const char * V_150 )
{
int V_80 = ( V_141 [ V_149 ] << 24 ) | ( V_141 [ V_149 + 1 ] << 16 ) | ( V_141 [ V_149 + 2 ] << 8 ) |
V_141 [ V_149 + 3 ] ;
F_104 ( L_37 , V_150 , V_80 ) ;
}
int F_106 ( const unsigned char * V_141 )
{
int V_30 = 1 , V_15 ;
if ( V_141 [ 0 ] == V_142 ) {
V_30 = 2 + V_141 [ 1 ] ;
if ( V_30 == 2 )
V_30 += 256 ;
if ( V_141 [ 2 ] < F_7 ( V_151 ) )
F_104 ( L_38 , V_151 [ V_141 [ 2 ] ] ) ;
else
F_104 ( L_39 ,
( int ) V_141 [ 2 ] ) ;
switch ( V_141 [ 2 ] ) {
case V_152 :
F_105 ( V_141 , 3 , L_40 ) ;
break;
case V_144 :
F_103 ( V_141 , 3 , 4 , 0 ) ;
break;
case V_143 :
F_103 ( V_141 , 0 , 0 , 3 ) ;
break;
case V_146 :
F_103 ( V_141 , 3 , 5 , 6 ) ;
break;
case V_153 :
F_105 ( V_141 , 3 , L_41 ) ;
F_105 ( V_141 , 7 , L_42 ) ;
break;
default:
for ( V_15 = 2 ; V_15 < V_30 ; ++ V_15 )
F_104 ( L_43 , V_141 [ V_15 ] ) ;
}
} else if ( V_141 [ 0 ] & 0x80 ) {
F_104 ( L_44 ,
( V_141 [ 0 ] & 0x40 ) ? L_22 : L_45 ,
( V_141 [ 0 ] & 0x20 ) ? L_46 : L_47 ,
V_141 [ 0 ] & 0x7 ) ;
} else if ( V_141 [ 0 ] < 0x1f ) {
if ( V_141 [ 0 ] < F_7 ( V_154 ) && V_154 [ V_141 [ 0 ] ] )
F_104 ( L_38 , V_154 [ V_141 [ 0 ] ] ) ;
else
F_104 ( L_48 , V_141 [ 0 ] ) ;
} else if ( V_141 [ 0 ] == 0x55 ) {
F_104 ( L_49 ) ;
} else if ( V_141 [ 0 ] <= 0x2f ) {
if ( ( V_141 [ 0 ] - 0x20 ) < F_7 ( V_155 ) )
F_104 ( L_50 , V_155 [ V_141 [ 0 ] - 0x20 ] ,
V_141 [ 1 ] ) ;
else
F_104 ( L_51 ,
V_141 [ 0 ] , V_141 [ 1 ] ) ;
V_30 = 2 ;
} else
F_104 ( L_52 ) ;
return V_30 ;
}
int F_106 ( const unsigned char * V_141 )
{
int V_30 = 1 , V_15 ;
if ( V_141 [ 0 ] == V_142 ) {
V_30 = 2 + V_141 [ 1 ] ;
if ( V_30 == 2 )
V_30 += 256 ;
for ( V_15 = 0 ; V_15 < V_30 ; ++ V_15 )
F_104 ( L_43 , V_141 [ V_15 ] ) ;
} else if ( V_141 [ 0 ] & 0x80 ) {
F_104 ( L_43 , V_141 [ 0 ] ) ;
} else if ( ( V_141 [ 0 ] < 0x1f ) || ( V_141 [ 0 ] == 0x55 ) ) {
F_104 ( L_43 , V_141 [ 0 ] ) ;
} else if ( V_141 [ 0 ] <= 0x2f ) {
F_104 ( L_53 , V_141 [ 0 ] , V_141 [ 1 ] ) ;
V_30 = 2 ;
} else
F_104 ( L_43 , V_141 [ 0 ] ) ;
return V_30 ;
}
static int F_107 ( struct V_39 * V_40 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 ;
struct V_67 * V_15 ;
if ( ! F_54 ( V_35 ) )
return 0 ;
V_7 = F_15 ( V_35 ) ;
V_38 = V_7 -> V_109 ;
if ( ! V_38 -> V_41 || V_38 -> V_41 -> V_42 . V_43 . V_44
!= & V_45 . V_44 )
return 0 ;
V_15 = F_64 ( V_38 -> V_41 ) ;
if ( V_15 -> V_71 -> V_156 && V_15 -> V_71 -> V_156 ( V_7 -> V_48 ) )
return 0 ;
return 1 ;
}
static int F_108 ( struct V_39 * V_40 ,
struct V_34 * V_35 )
{
struct V_37 * V_38 ;
struct V_46 * V_47 ;
struct V_67 * V_15 ;
if ( ! F_109 ( V_35 ) )
return 0 ;
V_38 = F_10 ( V_35 -> V_66 ) ;
if ( ! V_38 -> V_41 || V_38 -> V_41 -> V_42 . V_43 . V_44
!= & V_45 . V_44 )
return 0 ;
V_15 = F_64 ( V_38 -> V_41 ) ;
V_47 = F_31 ( V_35 ) ;
if ( V_15 -> V_71 -> V_156 && V_15 -> V_71 -> V_156 ( V_47 ) )
return 0 ;
return & V_15 -> V_157 . V_158 . V_43 == V_40 ;
}
static int F_110 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_159 * V_160 = & V_36 -> V_160 ;
struct V_37 * V_38 = F_69 ( V_36 ) ;
struct V_67 * V_161 = F_64 ( V_38 -> V_41 ) ;
struct V_162 * V_55 = & V_163 . V_55 ;
int V_164 = 0 ;
if ( V_161 -> V_71 -> V_78 )
V_164 = F_111 ( V_160 , V_55 , V_55 -> V_165 | V_166 ) ;
return V_164 ;
}
static T_6 F_112 ( struct V_159 * V_160 ,
struct V_162 * V_55 , int V_15 )
{
struct V_34 * V_36 = F_94 ( V_160 , struct V_34 , V_160 ) ;
struct V_46 * V_47 = F_57 ( V_36 ) ;
struct V_37 * V_38 = F_69 ( V_36 ) ;
struct V_67 * V_161 = F_64 ( V_38 -> V_41 ) ;
if ( V_55 == & V_167 . V_55 &&
F_17 ( V_47 ) )
return F_113 ( V_58 ) ;
else if ( V_55 == & V_168 . V_55 &&
F_17 ( V_47 ) )
return F_113 ( V_58 ) ;
else if ( V_55 == & V_169 . V_55 &&
F_17 ( V_47 ) )
return F_113 ( V_111 ) ;
else if ( V_55 == & V_170 . V_55 &&
F_17 ( V_47 ) )
return F_113 ( V_111 ) ;
else if ( V_55 == & V_171 . V_55 &&
F_19 ( V_47 ) )
return F_113 ( V_112 ) ;
else if ( V_55 == & V_172 . V_55 &&
F_19 ( V_47 ) )
return F_113 ( V_112 ) ;
else if ( V_55 == & V_173 . V_55 &&
F_25 ( V_47 ) )
return F_113 ( V_117 ) ;
else if ( V_55 == & V_174 . V_55 &&
F_25 ( V_47 ) )
return F_113 ( V_117 ) ;
else if ( V_55 == & V_175 . V_55 &&
F_21 ( V_47 ) )
return F_113 ( V_124 ) ;
else if ( V_55 == & V_176 . V_55 &&
F_28 ( V_47 ) )
return F_113 ( V_116 ) ;
else if ( V_55 == & V_177 . V_55 &&
F_28 ( V_47 ) )
return F_113 ( V_116 ) ;
else if ( V_55 == & V_178 . V_55 &&
F_25 ( V_47 ) )
return F_113 ( V_119 ) ;
else if ( V_55 == & V_179 . V_55 &&
F_25 ( V_47 ) )
return F_113 ( V_118 ) ;
else if ( V_55 == & V_180 . V_55 &&
F_25 ( V_47 ) )
return F_113 ( V_120 ) ;
else if ( V_55 == & V_181 . V_55 &&
F_25 ( V_47 ) )
return F_113 ( V_121 ) ;
else if ( V_55 == & V_182 . V_55 &&
F_25 ( V_47 ) )
return F_113 ( V_140 ) ;
else if ( V_55 == & V_183 . V_55 )
return V_166 ;
return 0 ;
}
static int F_114 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_159 * V_160 = & V_36 -> V_160 ;
F_115 ( V_160 , & V_184 ) ;
return 0 ;
}
struct V_185 *
F_116 ( struct V_186 * V_187 )
{
struct V_67 * V_15 = F_85 ( sizeof( struct V_67 ) ,
V_129 ) ;
if ( F_83 ( ! V_15 ) )
return NULL ;
V_15 -> V_157 . V_158 . V_43 . V_44 = & V_188 . V_44 ;
V_15 -> V_157 . V_158 . V_43 . V_189 = & V_184 ;
V_15 -> V_157 . V_158 . V_43 . V_190 = F_108 ;
F_117 ( & V_15 -> V_157 . V_158 ) ;
V_15 -> V_157 . V_191 = sizeof( struct V_68 ) ;
V_15 -> V_157 . V_42 . V_43 . V_44 = & V_45 . V_44 ;
V_15 -> V_157 . V_42 . V_43 . V_189 = & V_192 ;
V_15 -> V_157 . V_42 . V_43 . V_190 = F_12 ;
F_117 ( & V_15 -> V_157 . V_42 ) ;
V_15 -> V_157 . V_193 = sizeof( struct V_194 ) ;
V_15 -> V_71 = V_187 ;
return & V_15 -> V_157 ;
}
void F_118 ( struct V_185 * V_157 )
{
struct V_67 * V_15 = F_64 ( V_157 ) ;
F_119 ( & V_15 -> V_157 . V_158 ) ;
F_119 ( & V_15 -> V_157 . V_42 ) ;
F_91 ( V_15 ) ;
}
static T_7 int F_120 ( void )
{
int error = F_121 ( V_51 ,
L_54 ) ;
if ( ! error ) {
int V_15 ;
for ( V_15 = 0 ; V_195 [ V_15 ] . V_196 ; V_15 ++ )
F_122 ( 1 ,
V_195 [ V_15 ] . V_196 ,
V_195 [ V_15 ] . V_197 ,
NULL ,
V_195 [ V_15 ] . V_198 ,
V_51 ) ;
}
error = F_123 ( & V_188 ) ;
if ( error )
return error ;
error = F_124 ( & V_199 ) ;
return F_123 ( & V_45 ) ;
}
static void T_8 F_125 ( void )
{
F_126 ( & V_188 ) ;
F_127 ( & V_199 ) ;
F_126 ( & V_45 ) ;
F_128 ( V_51 ) ;
}
