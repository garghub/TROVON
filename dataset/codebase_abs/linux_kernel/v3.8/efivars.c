static unsigned long
F_1 ( T_1 * V_1 , T_2 V_2 )
{
unsigned long V_3 = 0 ;
while ( * V_1 ++ != 0 && V_3 < V_2 )
V_3 ++ ;
return V_3 ;
}
static inline unsigned long
F_2 ( T_1 * V_1 )
{
return F_1 ( V_1 , ~ 0UL ) ;
}
static inline unsigned long
F_3 ( T_1 * V_4 , unsigned long V_2 )
{
return F_1 ( V_4 , V_2 / sizeof( T_1 ) ) * sizeof( T_1 ) ;
}
static inline int
F_4 ( const T_1 * V_5 , const T_1 * V_6 , T_2 V_7 )
{
while ( 1 ) {
if ( V_7 == 0 )
return 0 ;
if ( * V_5 < * V_6 )
return - 1 ;
if ( * V_5 > * V_6 )
return 1 ;
if ( * V_5 == 0 )
return 0 ;
V_5 ++ ;
V_6 ++ ;
V_7 -- ;
}
}
static bool
F_5 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
struct V_12 * V_13 ;
int V_14 = 0 ;
V_13 = (struct V_12 * ) V_11 ;
if ( V_7 < sizeof( * V_13 ) )
return false ;
while ( V_14 <= V_7 - sizeof( * V_13 ) &&
V_13 -> V_3 >= sizeof( * V_13 ) &&
V_13 -> V_3 <= V_7 - V_14 ) {
V_14 += V_13 -> V_3 ;
if ( ( V_13 -> type == V_15 ||
V_13 -> type == V_16 ) &&
V_13 -> V_17 == V_18 )
return true ;
V_13 = (struct V_12 * ) ( V_11 + V_14 ) ;
}
return false ;
}
static bool
F_6 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
if ( ( V_7 % 2 ) != 0 )
return false ;
return true ;
}
static bool
F_7 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
T_4 V_19 ;
int V_20 , V_21 = 0 , V_22 ;
V_22 = F_1 ( V_9 -> V_23 , sizeof( V_9 -> V_23 ) ) ;
for ( V_20 = V_10 ; V_20 < V_10 + 4 ; V_20 ++ ) {
if ( V_9 -> V_23 [ V_20 ] > 127 ||
F_8 ( V_9 -> V_23 [ V_20 ] & 0xff ) < 0 )
return true ;
}
if ( V_22 > V_10 + 4 )
return false ;
if ( V_7 < 8 )
return false ;
V_19 = V_11 [ 4 ] | V_11 [ 5 ] << 8 ;
V_21 = F_3 ( ( T_1 * ) ( V_11 + 6 ) , V_7 - 6 ) + 2 ;
if ( ! V_21 )
return false ;
if ( ( V_21 + V_19 + 6 ) > V_7 )
return false ;
return F_5 ( V_9 , V_10 , V_11 + V_21 + 6 ,
V_19 ) ;
}
static bool
F_9 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
if ( V_7 != 2 )
return false ;
return true ;
}
static bool
F_10 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_7 ; V_20 ++ ) {
if ( V_11 [ V_20 ] > 127 )
return false ;
if ( V_11 [ V_20 ] == 0 )
return true ;
}
return false ;
}
static bool
F_11 ( struct V_8 * V_9 , T_3 * V_4 , unsigned long V_7 )
{
int V_20 ;
T_4 * V_24 = V_9 -> V_23 ;
for ( V_20 = 0 ; V_25 [ V_20 ] . V_26 != NULL ; V_20 ++ ) {
const char * V_27 = V_25 [ V_20 ] . V_27 ;
int V_10 ;
for ( V_10 = 0 ; ; V_10 ++ ) {
char V_28 = V_27 [ V_10 ] ;
T_4 V_29 = V_24 [ V_10 ] ;
if ( V_29 > 127 )
return true ;
if ( V_28 == '*' )
return V_25 [ V_20 ] . V_26 ( V_9 ,
V_10 , V_4 , V_7 ) ;
if ( V_28 != V_29 )
break;
if ( ! V_28 )
return V_25 [ V_20 ] . V_26 ( V_9 ,
V_10 , V_4 , V_7 ) ;
}
}
return true ;
}
static T_5
F_12 ( struct V_30 * V_30 , struct V_8 * V_9 )
{
T_5 V_31 ;
V_9 -> V_32 = 1024 ;
V_31 = V_30 -> V_33 -> V_34 ( V_9 -> V_23 ,
& V_9 -> V_35 ,
& V_9 -> V_36 ,
& V_9 -> V_32 ,
V_9 -> V_37 ) ;
return V_31 ;
}
static T_5
F_13 ( struct V_30 * V_30 , struct V_8 * V_9 )
{
T_5 V_31 ;
F_14 ( & V_30 -> V_38 ) ;
V_31 = F_12 ( V_30 , V_9 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_1 ,
V_31 ) ;
}
return V_31 ;
}
static T_6
F_17 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
char * V_44 = V_43 ;
if ( ! V_42 || ! V_43 )
return 0 ;
F_18 ( & V_9 -> V_35 , V_44 ) ;
V_44 += strlen ( V_44 ) ;
V_44 += sprintf ( V_44 , L_2 ) ;
return V_44 - V_43 ;
}
static T_6
F_19 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
char * V_44 = V_43 ;
T_5 V_31 ;
if ( ! V_42 || ! V_43 )
return - V_45 ;
V_31 = F_13 ( V_42 -> V_30 , V_9 ) ;
if ( V_31 != V_39 )
return - V_46 ;
if ( V_9 -> V_36 & V_47 )
V_44 += sprintf ( V_44 , L_3 ) ;
if ( V_9 -> V_36 & V_48 )
V_44 += sprintf ( V_44 , L_4 ) ;
if ( V_9 -> V_36 & V_49 )
V_44 += sprintf ( V_44 , L_5 ) ;
if ( V_9 -> V_36 & V_50 )
V_44 += sprintf ( V_44 , L_6 ) ;
if ( V_9 -> V_36 & V_51 )
V_44 += sprintf ( V_44 ,
L_7 ) ;
if ( V_9 -> V_36 &
V_52 )
V_44 += sprintf ( V_44 ,
L_8 ) ;
if ( V_9 -> V_36 & V_53 )
V_44 += sprintf ( V_44 , L_9 ) ;
return V_44 - V_43 ;
}
static T_6
F_20 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
char * V_44 = V_43 ;
T_5 V_31 ;
if ( ! V_42 || ! V_43 )
return - V_45 ;
V_31 = F_13 ( V_42 -> V_30 , V_9 ) ;
if ( V_31 != V_39 )
return - V_46 ;
V_44 += sprintf ( V_44 , L_10 , V_9 -> V_32 ) ;
return V_44 - V_43 ;
}
static T_6
F_21 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
T_5 V_31 ;
if ( ! V_42 || ! V_43 )
return - V_45 ;
V_31 = F_13 ( V_42 -> V_30 , V_9 ) ;
if ( V_31 != V_39 )
return - V_46 ;
memcpy ( V_43 , V_9 -> V_37 , V_9 -> V_32 ) ;
return V_9 -> V_32 ;
}
static T_6
F_22 ( struct V_41 * V_42 , const char * V_43 , T_2 V_54 )
{
struct V_8 * V_55 , * V_9 = & V_42 -> V_9 ;
struct V_30 * V_30 = V_42 -> V_30 ;
T_5 V_31 = V_56 ;
if ( V_54 != sizeof( struct V_8 ) )
return - V_45 ;
V_55 = (struct V_8 * ) V_43 ;
if ( memcmp ( V_55 -> V_23 , V_9 -> V_23 , sizeof( V_9 -> V_23 ) ) ||
F_23 ( V_55 -> V_35 , V_9 -> V_35 ) ) {
F_16 ( V_57 L_11 ) ;
return - V_45 ;
}
if ( ( V_55 -> V_32 <= 0 ) || ( V_55 -> V_36 == 0 ) ) {
F_16 ( V_57 L_12 ) ;
return - V_45 ;
}
if ( ( V_55 -> V_36 & ~ V_58 ) != 0 ||
F_11 ( V_55 , V_55 -> V_37 , V_55 -> V_32 ) == false ) {
F_16 ( V_57 L_13 ) ;
return - V_45 ;
}
F_14 ( & V_30 -> V_38 ) ;
V_31 = V_30 -> V_33 -> V_59 ( V_55 -> V_23 ,
& V_55 -> V_35 ,
V_55 -> V_36 ,
V_55 -> V_32 ,
V_55 -> V_37 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_14 ,
V_31 ) ;
return - V_46 ;
}
memcpy ( & V_42 -> V_9 , V_55 , V_54 ) ;
return V_54 ;
}
static T_6
F_24 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
T_5 V_31 ;
if ( ! V_42 || ! V_43 )
return 0 ;
V_31 = F_13 ( V_42 -> V_30 , V_9 ) ;
if ( V_31 != V_39 )
return - V_46 ;
memcpy ( V_43 , V_9 , sizeof( * V_9 ) ) ;
return sizeof( * V_9 ) ;
}
static T_6 F_25 ( struct V_60 * V_61 , struct V_62 * V_63 ,
char * V_43 )
{
struct V_41 * V_9 = F_26 ( V_61 ) ;
struct V_64 * V_65 = F_27 ( V_63 ) ;
T_6 V_66 = - V_46 ;
if ( ! F_28 ( V_67 ) )
return - V_68 ;
if ( V_65 -> V_69 ) {
V_66 = V_65 -> V_69 ( V_9 , V_43 ) ;
}
return V_66 ;
}
static T_6 F_29 ( struct V_60 * V_61 , struct V_62 * V_63 ,
const char * V_43 , T_2 V_54 )
{
struct V_41 * V_9 = F_26 ( V_61 ) ;
struct V_64 * V_65 = F_27 ( V_63 ) ;
T_6 V_66 = - V_46 ;
if ( ! F_28 ( V_67 ) )
return - V_68 ;
if ( V_65 -> V_70 )
V_66 = V_65 -> V_70 ( V_9 , V_43 , V_54 ) ;
return V_66 ;
}
static void F_30 ( struct V_60 * V_61 )
{
struct V_41 * V_9 = F_31 ( V_61 , struct V_41 , V_61 ) ;
F_32 ( V_9 ) ;
}
static inline void
F_33 ( struct V_41 * V_9 )
{
F_34 ( & V_9 -> V_61 ) ;
}
static int F_35 ( struct V_71 * V_71 , struct V_72 * V_72 )
{
V_72 -> V_73 = V_71 -> V_74 ;
return 0 ;
}
static int F_36 ( T_5 V_31 )
{
int V_75 ;
switch ( V_31 ) {
case V_76 :
V_75 = - V_45 ;
break;
case V_77 :
V_75 = - V_78 ;
break;
case V_79 :
V_75 = - V_46 ;
break;
case V_80 :
V_75 = - V_81 ;
break;
case V_82 :
V_75 = - V_68 ;
break;
case V_56 :
V_75 = - V_46 ;
break;
default:
V_75 = - V_45 ;
}
return V_75 ;
}
static T_6 F_37 ( struct V_72 * V_72 ,
const char T_7 * V_83 , T_2 V_54 , T_8 * V_84 )
{
struct V_41 * V_9 = V_72 -> V_73 ;
struct V_30 * V_30 ;
T_5 V_31 ;
void * V_4 ;
T_9 V_85 ;
struct V_71 * V_71 = V_72 -> V_86 -> V_87 ;
unsigned long V_88 = V_54 - sizeof( V_85 ) ;
unsigned long V_89 ;
T_10 V_90 , V_91 , V_92 ;
T_6 V_93 = 0 ;
if ( V_54 < sizeof( V_85 ) )
return - V_45 ;
if ( F_38 ( & V_85 , V_83 , sizeof( V_85 ) ) )
return - V_94 ;
if ( V_85 & ~ ( V_58 ) )
return - V_45 ;
V_30 = V_9 -> V_30 ;
F_14 ( & V_30 -> V_38 ) ;
if ( ! V_30 -> V_33 -> V_95 )
V_31 = V_96 ;
else {
const struct V_97 * V_98 = V_30 -> V_33 ;
V_31 = V_98 -> V_95 ( V_85 , & V_90 ,
& V_91 , & V_92 ) ;
}
F_15 ( & V_30 -> V_38 ) ;
if ( V_31 != V_39 ) {
if ( V_31 != V_96 )
return F_36 ( V_31 ) ;
V_91 = 65536 ;
}
if ( V_88 > V_91 )
return - V_78 ;
V_4 = F_39 ( V_88 , V_99 ) ;
if ( ! V_4 )
return - V_100 ;
if ( F_38 ( V_4 , V_83 + sizeof( V_85 ) , V_88 ) ) {
V_93 = - V_94 ;
goto V_101;
}
if ( F_11 ( & V_9 -> V_9 , V_4 , V_88 ) == false ) {
V_93 = - V_45 ;
goto V_101;
}
F_14 ( & V_30 -> V_38 ) ;
V_31 = V_30 -> V_33 -> V_59 ( V_9 -> V_9 . V_23 ,
& V_9 -> V_9 . V_35 ,
V_85 , V_88 ,
V_4 ) ;
if ( V_31 != V_39 ) {
F_15 ( & V_30 -> V_38 ) ;
F_32 ( V_4 ) ;
return F_36 ( V_31 ) ;
}
V_93 = V_54 ;
V_89 = 0 ;
V_31 = V_30 -> V_33 -> V_34 ( V_9 -> V_9 . V_23 ,
& V_9 -> V_9 . V_35 ,
NULL , & V_89 ,
NULL ) ;
if ( V_31 == V_102 ) {
F_15 ( & V_30 -> V_38 ) ;
F_40 ( & V_71 -> V_103 ) ;
F_41 ( V_71 , V_89 + sizeof( V_85 ) ) ;
F_42 ( & V_71 -> V_103 ) ;
} else if ( V_31 == V_56 ) {
F_43 ( & V_9 -> V_104 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_33 ( V_9 ) ;
F_44 ( V_71 ) ;
F_45 ( V_72 -> V_105 ) ;
F_46 ( V_72 -> V_105 ) ;
} else {
F_15 ( & V_30 -> V_38 ) ;
F_47 ( L_15
L_16 , V_31 ) ;
}
V_101:
F_32 ( V_4 ) ;
return V_93 ;
}
static T_6 F_48 ( struct V_72 * V_72 , char T_7 * V_83 ,
T_2 V_54 , T_8 * V_84 )
{
struct V_41 * V_9 = V_72 -> V_73 ;
struct V_30 * V_30 = V_9 -> V_30 ;
T_5 V_31 ;
unsigned long V_88 = 0 ;
T_9 V_85 ;
void * V_4 ;
T_6 V_106 = 0 ;
F_14 ( & V_30 -> V_38 ) ;
V_31 = V_30 -> V_33 -> V_34 ( V_9 -> V_9 . V_23 ,
& V_9 -> V_9 . V_35 ,
& V_85 , & V_88 , NULL ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_31 != V_102 )
return F_36 ( V_31 ) ;
V_4 = F_39 ( V_88 + sizeof( V_85 ) , V_99 ) ;
if ( ! V_4 )
return - V_100 ;
F_14 ( & V_30 -> V_38 ) ;
V_31 = V_30 -> V_33 -> V_34 ( V_9 -> V_9 . V_23 ,
& V_9 -> V_9 . V_35 ,
& V_85 , & V_88 ,
( V_4 + sizeof( V_85 ) ) ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_31 != V_39 ) {
V_106 = F_36 ( V_31 ) ;
goto V_107;
}
memcpy ( V_4 , & V_85 , sizeof( V_85 ) ) ;
V_106 = F_49 ( V_83 , V_54 , V_84 ,
V_4 , V_88 + sizeof( V_85 ) ) ;
V_107:
F_32 ( V_4 ) ;
return V_106 ;
}
static void F_50 ( struct V_71 * V_71 )
{
F_51 ( V_71 ) ;
}
static struct V_71 * F_52 ( struct V_108 * V_109 ,
const struct V_71 * V_110 , int V_111 , T_11 V_112 )
{
struct V_71 * V_71 = F_53 ( V_109 ) ;
if ( V_71 ) {
V_71 -> V_113 = F_54 () ;
V_71 -> V_114 = V_111 ;
V_71 -> V_115 = V_71 -> V_116 = V_71 -> V_117 = V_118 ;
switch ( V_111 & V_119 ) {
case V_120 :
V_71 -> V_121 = & V_122 ;
break;
case V_123 :
V_71 -> V_124 = & V_125 ;
V_71 -> V_121 = & V_126 ;
F_55 ( V_71 ) ;
break;
}
}
return V_71 ;
}
static void F_56 ( const char * V_44 , T_12 * V_127 )
{
V_127 -> V_6 [ 0 ] = F_8 ( V_44 [ 6 ] ) << 4 | F_8 ( V_44 [ 7 ] ) ;
V_127 -> V_6 [ 1 ] = F_8 ( V_44 [ 4 ] ) << 4 | F_8 ( V_44 [ 5 ] ) ;
V_127 -> V_6 [ 2 ] = F_8 ( V_44 [ 2 ] ) << 4 | F_8 ( V_44 [ 3 ] ) ;
V_127 -> V_6 [ 3 ] = F_8 ( V_44 [ 0 ] ) << 4 | F_8 ( V_44 [ 1 ] ) ;
V_127 -> V_6 [ 4 ] = F_8 ( V_44 [ 11 ] ) << 4 | F_8 ( V_44 [ 12 ] ) ;
V_127 -> V_6 [ 5 ] = F_8 ( V_44 [ 9 ] ) << 4 | F_8 ( V_44 [ 10 ] ) ;
V_127 -> V_6 [ 6 ] = F_8 ( V_44 [ 16 ] ) << 4 | F_8 ( V_44 [ 17 ] ) ;
V_127 -> V_6 [ 7 ] = F_8 ( V_44 [ 14 ] ) << 4 | F_8 ( V_44 [ 15 ] ) ;
V_127 -> V_6 [ 8 ] = F_8 ( V_44 [ 19 ] ) << 4 | F_8 ( V_44 [ 20 ] ) ;
V_127 -> V_6 [ 9 ] = F_8 ( V_44 [ 21 ] ) << 4 | F_8 ( V_44 [ 22 ] ) ;
V_127 -> V_6 [ 10 ] = F_8 ( V_44 [ 24 ] ) << 4 | F_8 ( V_44 [ 25 ] ) ;
V_127 -> V_6 [ 11 ] = F_8 ( V_44 [ 26 ] ) << 4 | F_8 ( V_44 [ 27 ] ) ;
V_127 -> V_6 [ 12 ] = F_8 ( V_44 [ 28 ] ) << 4 | F_8 ( V_44 [ 29 ] ) ;
V_127 -> V_6 [ 13 ] = F_8 ( V_44 [ 30 ] ) << 4 | F_8 ( V_44 [ 31 ] ) ;
V_127 -> V_6 [ 14 ] = F_8 ( V_44 [ 32 ] ) << 4 | F_8 ( V_44 [ 33 ] ) ;
V_127 -> V_6 [ 15 ] = F_8 ( V_44 [ 34 ] ) << 4 | F_8 ( V_44 [ 35 ] ) ;
}
static int F_57 ( struct V_71 * V_110 , struct V_128 * V_128 ,
T_13 V_111 , bool V_129 )
{
struct V_71 * V_71 ;
struct V_30 * V_30 = & V_130 ;
struct V_41 * V_9 ;
int V_22 , V_20 = 0 , V_75 = 0 ;
if ( V_128 -> V_131 . V_7 < V_132 + 2 )
return - V_45 ;
V_71 = F_52 ( V_110 -> V_133 , V_110 , V_111 , 0 ) ;
if ( ! V_71 )
return - V_100 ;
V_9 = F_58 ( sizeof( struct V_41 ) , V_99 ) ;
if ( ! V_9 ) {
V_75 = - V_100 ;
goto V_101;
}
V_22 = V_128 -> V_131 . V_7 - V_132 - 1 ;
F_56 ( V_128 -> V_131 . V_27 + V_22 + 1 ,
& V_9 -> V_9 . V_35 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
V_9 -> V_9 . V_23 [ V_20 ] = V_128 -> V_131 . V_27 [ V_20 ] ;
V_9 -> V_9 . V_23 [ V_20 ] = '\0' ;
V_71 -> V_74 = V_9 ;
V_9 -> V_30 = V_30 ;
V_9 -> V_61 . V_134 = V_30 -> V_134 ;
V_75 = F_59 ( & V_9 -> V_61 , & V_135 , NULL , L_17 ,
V_128 -> V_131 . V_27 ) ;
if ( V_75 )
goto V_101;
F_60 ( & V_9 -> V_61 , V_136 ) ;
F_14 ( & V_30 -> V_38 ) ;
F_61 ( & V_9 -> V_104 , & V_30 -> V_104 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_62 ( V_128 , V_71 ) ;
F_63 ( V_128 ) ;
V_101:
if ( V_75 ) {
F_32 ( V_9 ) ;
F_64 ( V_71 ) ;
}
return V_75 ;
}
static int F_65 ( struct V_71 * V_110 , struct V_128 * V_128 )
{
struct V_41 * V_9 = V_128 -> V_137 -> V_74 ;
struct V_30 * V_30 = V_9 -> V_30 ;
T_5 V_31 ;
F_14 ( & V_30 -> V_38 ) ;
V_31 = V_30 -> V_33 -> V_59 ( V_9 -> V_9 . V_23 ,
& V_9 -> V_9 . V_35 ,
0 , 0 , NULL ) ;
if ( V_31 == V_39 || V_31 == V_56 ) {
F_43 ( & V_9 -> V_104 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_33 ( V_9 ) ;
F_44 ( V_128 -> V_137 ) ;
F_46 ( V_128 ) ;
return 0 ;
}
F_15 ( & V_30 -> V_38 ) ;
return - V_45 ;
}
static int F_66 ( struct V_108 * V_109 , void * V_4 , int V_138 )
{
struct V_71 * V_71 = NULL ;
struct V_128 * V_139 ;
struct V_41 * V_42 , * V_140 ;
struct V_30 * V_30 = & V_130 ;
char * V_27 ;
V_141 = V_109 ;
V_109 -> V_142 = V_143 ;
V_109 -> V_144 = V_145 ;
V_109 -> V_146 = V_147 ;
V_109 -> V_148 = V_149 ;
V_109 -> V_150 = & V_151 ;
V_109 -> V_152 = 1 ;
V_71 = F_52 ( V_109 , NULL , V_123 | 0755 , 0 ) ;
if ( ! V_71 )
return - V_100 ;
V_71 -> V_124 = & V_125 ;
V_139 = F_67 ( V_71 ) ;
V_109 -> V_153 = V_139 ;
if ( ! V_139 )
return - V_100 ;
F_68 (entry, n, &efivars->list, list) {
struct V_128 * V_128 , * V_139 = V_141 -> V_153 ;
unsigned long V_106 = 0 ;
int V_7 , V_20 ;
V_71 = NULL ;
V_7 = F_2 ( V_42 -> V_9 . V_23 ) ;
V_27 = F_39 ( V_7 + 1 + V_132 + 1 , V_154 ) ;
if ( ! V_27 )
goto V_155;
for ( V_20 = 0 ; V_20 < V_7 ; V_20 ++ )
V_27 [ V_20 ] = V_42 -> V_9 . V_23 [ V_20 ] & 0xFF ;
V_27 [ V_7 ] = '-' ;
F_18 ( & V_42 -> V_9 . V_35 , V_27 + V_7 + 1 ) ;
V_27 [ V_7 + V_132 + 1 ] = '\0' ;
V_71 = F_52 ( V_141 , V_139 -> V_137 ,
V_120 | 0644 , 0 ) ;
if ( ! V_71 )
goto V_156;
V_128 = F_69 ( V_139 , V_27 ) ;
if ( ! V_128 )
goto V_157;
F_32 ( V_27 ) ;
F_14 ( & V_30 -> V_38 ) ;
V_30 -> V_33 -> V_34 ( V_42 -> V_9 . V_23 ,
& V_42 -> V_9 . V_35 ,
& V_42 -> V_9 . V_36 ,
& V_106 ,
NULL ) ;
F_15 ( & V_30 -> V_38 ) ;
F_40 ( & V_71 -> V_103 ) ;
V_71 -> V_74 = V_42 ;
F_41 ( V_71 , V_106 + 4 ) ;
F_42 ( & V_71 -> V_103 ) ;
F_70 ( V_128 , V_71 ) ;
}
return 0 ;
V_157:
F_64 ( V_71 ) ;
V_156:
F_32 ( V_27 ) ;
V_155:
return - V_100 ;
}
static struct V_128 * F_71 ( struct V_158 * V_159 ,
int V_160 , const char * V_161 , void * V_4 )
{
return F_72 ( V_159 , V_160 , V_4 , F_66 ) ;
}
static void F_73 ( struct V_108 * V_109 )
{
F_74 ( V_109 ) ;
V_141 = NULL ;
}
static int F_75 ( struct V_162 * V_163 )
{
struct V_30 * V_30 = V_163 -> V_4 ;
F_14 ( & V_30 -> V_38 ) ;
V_30 -> V_164 = F_76 ( & V_30 -> V_104 ,
struct V_41 , V_104 ) ;
return 0 ;
}
static int F_77 ( struct V_162 * V_163 )
{
struct V_30 * V_30 = V_163 -> V_4 ;
F_15 ( & V_30 -> V_38 ) ;
return 0 ;
}
static T_6 F_78 ( T_10 * V_165 , enum V_166 * type ,
int * V_54 , struct V_167 * V_167 ,
char * * V_43 , struct V_162 * V_163 )
{
T_12 V_168 = V_169 ;
struct V_30 * V_30 = V_163 -> V_4 ;
char V_27 [ V_170 ] ;
int V_20 ;
int V_171 ;
unsigned int V_172 , V_106 ;
unsigned long time ;
while ( & V_30 -> V_164 -> V_104 != & V_30 -> V_104 ) {
if ( ! F_23 ( V_30 -> V_164 -> V_9 . V_35 ,
V_168 ) ) {
for ( V_20 = 0 ; V_20 < V_170 ; V_20 ++ ) {
V_27 [ V_20 ] = V_30 -> V_164 -> V_9 . V_23 [ V_20 ] ;
}
if ( sscanf ( V_27 , L_18 ,
type , & V_172 , & V_171 , & time ) == 4 ) {
* V_165 = V_172 ;
* V_54 = V_171 ;
V_167 -> V_173 = time ;
V_167 -> V_174 = 0 ;
} else if ( sscanf ( V_27 , L_19 ,
type , & V_172 , & time ) == 3 ) {
* V_165 = V_172 ;
* V_54 = 0 ;
V_167 -> V_173 = time ;
V_167 -> V_174 = 0 ;
} else {
V_30 -> V_164 = F_79 (
V_30 -> V_164 -> V_104 . V_175 ,
struct V_41 , V_104 ) ;
continue;
}
F_12 ( V_30 , & V_30 -> V_164 -> V_9 ) ;
V_106 = V_30 -> V_164 -> V_9 . V_32 ;
* V_43 = F_39 ( V_106 , V_99 ) ;
if ( * V_43 == NULL )
return - V_100 ;
memcpy ( * V_43 , V_30 -> V_164 -> V_9 . V_37 ,
V_106 ) ;
V_30 -> V_164 = F_79 (
V_30 -> V_164 -> V_104 . V_175 ,
struct V_41 , V_104 ) ;
return V_106 ;
}
V_30 -> V_164 = F_79 ( V_30 -> V_164 -> V_104 . V_175 ,
struct V_41 , V_104 ) ;
}
return 0 ;
}
static int F_80 ( enum V_166 type ,
enum V_176 V_177 , T_10 * V_165 ,
unsigned int V_172 , int V_54 , T_2 V_106 ,
struct V_162 * V_163 )
{
char V_27 [ V_170 ] ;
T_1 V_178 [ V_170 ] ;
T_12 V_168 = V_169 ;
struct V_30 * V_30 = V_163 -> V_4 ;
int V_20 , V_66 = 0 ;
T_10 V_179 , V_180 , V_181 ;
T_5 V_31 = V_56 ;
F_14 ( & V_30 -> V_38 ) ;
V_31 = V_30 -> V_33 -> V_95 ( V_182 ,
& V_179 ,
& V_180 ,
& V_181 ) ;
if ( V_31 || V_180 < V_106 + V_170 * 2 ) {
F_15 ( & V_30 -> V_38 ) ;
* V_165 = V_172 ;
return - V_78 ;
}
sprintf ( V_27 , L_18 , type , V_172 , V_54 ,
F_81 () ) ;
for ( V_20 = 0 ; V_20 < V_170 ; V_20 ++ )
V_178 [ V_20 ] = V_27 [ V_20 ] ;
V_30 -> V_33 -> V_59 ( V_178 , & V_168 , V_182 ,
V_106 , V_163 -> V_43 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_106 )
V_66 = F_82 ( V_30 ,
F_3 ( V_178 ,
V_170 * 2 ) ,
V_178 , & V_168 ) ;
* V_165 = V_172 ;
return V_66 ;
}
static int F_83 ( enum V_166 type , T_10 V_165 , int V_54 ,
struct V_167 time , struct V_162 * V_163 )
{
char V_27 [ V_170 ] ;
T_1 V_178 [ V_170 ] ;
char V_183 [ V_170 ] ;
T_1 V_184 [ V_170 ] ;
T_12 V_168 = V_169 ;
struct V_30 * V_30 = V_163 -> V_4 ;
struct V_41 * V_42 , * V_185 = NULL ;
int V_20 ;
sprintf ( V_27 , L_18 , type , ( unsigned int ) V_165 , V_54 ,
time . V_173 ) ;
F_14 ( & V_30 -> V_38 ) ;
for ( V_20 = 0 ; V_20 < V_170 ; V_20 ++ )
V_178 [ V_20 ] = V_27 [ V_20 ] ;
F_84 (entry, &efivars->list, list) {
F_12 ( V_30 , & V_42 -> V_9 ) ;
if ( F_23 ( V_42 -> V_9 . V_35 , V_168 ) )
continue;
if ( F_4 ( V_42 -> V_9 . V_23 , V_178 ,
F_2 ( V_178 ) ) ) {
sprintf ( V_183 , L_19 , type ,
( unsigned int ) V_165 , time . V_173 ) ;
for ( V_20 = 0 ; V_20 < V_170 ; V_20 ++ )
V_184 [ V_20 ] = V_183 [ V_20 ] ;
if ( F_4 ( V_42 -> V_9 . V_23 , V_184 ,
F_2 ( V_184 ) ) )
continue;
}
V_185 = V_42 ;
V_30 -> V_33 -> V_59 ( V_42 -> V_9 . V_23 ,
& V_42 -> V_9 . V_35 ,
V_182 ,
0 , NULL ) ;
break;
}
if ( V_185 )
F_43 ( & V_185 -> V_104 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_185 )
F_33 ( V_185 ) ;
return 0 ;
}
static int F_75 ( struct V_162 * V_163 )
{
return 0 ;
}
static int F_77 ( struct V_162 * V_163 )
{
return 0 ;
}
static T_6 F_78 ( T_10 * V_165 , enum V_166 * type , int * V_54 ,
struct V_167 * V_167 ,
char * * V_43 , struct V_162 * V_163 )
{
return - 1 ;
}
static int F_80 ( enum V_166 type ,
enum V_176 V_177 , T_10 * V_165 ,
unsigned int V_172 , int V_54 , T_2 V_106 ,
struct V_162 * V_163 )
{
return 0 ;
}
static int F_83 ( enum V_166 type , T_10 V_165 , int V_54 ,
struct V_167 time , struct V_162 * V_163 )
{
return 0 ;
}
static T_6 F_85 ( struct V_72 * V_186 , struct V_60 * V_61 ,
struct V_187 * V_188 ,
char * V_43 , T_8 V_189 , T_2 V_54 )
{
struct V_8 * V_55 = (struct V_8 * ) V_43 ;
struct V_30 * V_30 = V_188 -> V_190 ;
struct V_41 * V_191 , * V_140 ;
unsigned long V_192 , V_193 ;
T_5 V_31 = V_56 ;
int V_185 = 0 ;
if ( ! F_28 ( V_67 ) )
return - V_68 ;
if ( ( V_55 -> V_36 & ~ V_58 ) != 0 ||
F_11 ( V_55 , V_55 -> V_37 , V_55 -> V_32 ) == false ) {
F_16 ( V_57 L_13 ) ;
return - V_45 ;
}
F_14 ( & V_30 -> V_38 ) ;
F_68 (search_efivar, n, &efivars->list, list) {
V_192 = F_3 ( V_191 -> V_9 . V_23 , 1024 ) ;
V_193 = F_3 ( V_55 -> V_23 , 1024 ) ;
if ( V_192 == V_193 &&
! memcmp ( & ( V_191 -> V_9 . V_23 ) ,
V_55 -> V_23 , V_192 ) &&
! F_23 ( V_191 -> V_9 . V_35 ,
V_55 -> V_35 ) ) {
V_185 = 1 ;
break;
}
}
if ( V_185 ) {
F_15 ( & V_30 -> V_38 ) ;
return - V_45 ;
}
V_31 = V_30 -> V_33 -> V_59 ( V_55 -> V_23 ,
& V_55 -> V_35 ,
V_55 -> V_36 ,
V_55 -> V_32 ,
V_55 -> V_37 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_14 ,
V_31 ) ;
F_15 ( & V_30 -> V_38 ) ;
return - V_46 ;
}
F_15 ( & V_30 -> V_38 ) ;
V_31 = F_82 ( V_30 ,
F_3 ( V_55 -> V_23 ,
1024 ) ,
V_55 -> V_23 ,
& V_55 -> V_35 ) ;
if ( V_31 ) {
F_16 ( V_40 L_20 ) ;
}
return V_54 ;
}
static T_6 F_86 ( struct V_72 * V_186 , struct V_60 * V_61 ,
struct V_187 * V_188 ,
char * V_43 , T_8 V_189 , T_2 V_54 )
{
struct V_8 * V_194 = (struct V_8 * ) V_43 ;
struct V_30 * V_30 = V_188 -> V_190 ;
struct V_41 * V_191 , * V_140 ;
unsigned long V_192 , V_193 ;
T_5 V_31 = V_56 ;
int V_185 = 0 ;
if ( ! F_28 ( V_67 ) )
return - V_68 ;
F_14 ( & V_30 -> V_38 ) ;
F_68 (search_efivar, n, &efivars->list, list) {
V_192 = F_3 ( V_191 -> V_9 . V_23 , 1024 ) ;
V_193 = F_3 ( V_194 -> V_23 , 1024 ) ;
if ( V_192 == V_193 &&
! memcmp ( & ( V_191 -> V_9 . V_23 ) ,
V_194 -> V_23 , V_192 ) &&
! F_23 ( V_191 -> V_9 . V_35 ,
V_194 -> V_35 ) ) {
V_185 = 1 ;
break;
}
}
if ( ! V_185 ) {
F_15 ( & V_30 -> V_38 ) ;
return - V_45 ;
}
V_194 -> V_36 = 0 ;
V_194 -> V_32 = 0 ;
V_31 = V_30 -> V_33 -> V_59 ( V_194 -> V_23 ,
& V_194 -> V_35 ,
V_194 -> V_36 ,
V_194 -> V_32 ,
V_194 -> V_37 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_14 ,
V_31 ) ;
F_15 ( & V_30 -> V_38 ) ;
return - V_46 ;
}
F_43 ( & V_191 -> V_104 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_33 ( V_191 ) ;
return V_54 ;
}
static T_6 F_87 ( struct V_60 * V_61 ,
struct V_195 * V_63 , char * V_43 )
{
char * V_44 = V_43 ;
if ( ! V_61 || ! V_43 )
return - V_45 ;
if ( V_196 . V_197 != V_198 )
V_44 += sprintf ( V_44 , L_21 , V_196 . V_197 ) ;
if ( V_196 . V_199 != V_198 )
V_44 += sprintf ( V_44 , L_22 , V_196 . V_199 ) ;
if ( V_196 . V_200 != V_198 )
V_44 += sprintf ( V_44 , L_23 , V_196 . V_200 ) ;
if ( V_196 . V_201 != V_198 )
V_44 += sprintf ( V_44 , L_24 , V_196 . V_201 ) ;
if ( V_196 . V_202 != V_198 )
V_44 += sprintf ( V_44 , L_25 , V_196 . V_202 ) ;
if ( V_196 . V_203 != V_198 )
V_44 += sprintf ( V_44 , L_26 , V_196 . V_203 ) ;
if ( V_196 . V_204 != V_198 )
V_44 += sprintf ( V_44 , L_27 , V_196 . V_204 ) ;
return V_44 - V_43 ;
}
static int
F_82 ( struct V_30 * V_30 ,
unsigned long V_205 ,
T_1 * V_206 ,
T_12 * V_207 )
{
int V_20 , V_208 ;
char * V_209 ;
struct V_41 * V_210 ;
V_208 = V_205 / sizeof( T_1 )
+ 1 + V_132 + 1 ;
V_209 = F_58 ( V_208 , V_99 ) ;
V_210 = F_58 ( sizeof( struct V_41 ) , V_99 ) ;
if ( ! V_209 || ! V_210 ) {
F_32 ( V_209 ) ;
F_32 ( V_210 ) ;
return 1 ;
}
V_210 -> V_30 = V_30 ;
memcpy ( V_210 -> V_9 . V_23 , V_206 ,
V_205 ) ;
memcpy ( & ( V_210 -> V_9 . V_35 ) , V_207 , sizeof( T_12 ) ) ;
for ( V_20 = 0 ; V_20 < ( int ) ( V_205 / sizeof( T_1 ) ) ; V_20 ++ ) {
V_209 [ V_20 ] = V_206 [ V_20 ] & 0xFF ;
}
* ( V_209 + strlen ( V_209 ) ) = '-' ;
F_18 ( V_207 , V_209 + strlen ( V_209 ) ) ;
V_210 -> V_61 . V_134 = V_30 -> V_134 ;
V_20 = F_59 ( & V_210 -> V_61 , & V_135 , NULL ,
L_17 , V_209 ) ;
if ( V_20 ) {
F_32 ( V_209 ) ;
F_32 ( V_210 ) ;
return 1 ;
}
F_60 ( & V_210 -> V_61 , V_136 ) ;
F_32 ( V_209 ) ;
V_209 = NULL ;
F_14 ( & V_30 -> V_38 ) ;
F_61 ( & V_210 -> V_104 , & V_30 -> V_104 ) ;
F_15 ( & V_30 -> V_38 ) ;
return 0 ;
}
static int
F_88 ( struct V_30 * V_30 )
{
struct V_187 * V_63 ;
int error ;
V_63 = F_58 ( sizeof( * V_63 ) , V_99 ) ;
if ( ! V_63 )
return - V_100 ;
V_63 -> V_63 . V_27 = L_28 ;
V_63 -> V_63 . V_111 = 0200 ;
V_63 -> V_211 = F_85 ;
V_63 -> V_190 = V_30 ;
V_30 -> V_55 = V_63 ;
V_63 = F_58 ( sizeof( * V_63 ) , V_99 ) ;
if ( ! V_63 ) {
error = - V_100 ;
goto V_107;
}
V_63 -> V_63 . V_27 = L_29 ;
V_63 -> V_63 . V_111 = 0200 ;
V_63 -> V_211 = F_86 ;
V_63 -> V_190 = V_30 ;
V_30 -> V_194 = V_63 ;
F_89 ( V_30 -> V_55 ) ;
F_89 ( V_30 -> V_194 ) ;
error = F_90 ( & V_30 -> V_134 -> V_61 ,
V_30 -> V_55 ) ;
if ( error ) {
F_16 ( V_57 L_30
L_31 , error ) ;
goto V_107;
}
error = F_90 ( & V_30 -> V_134 -> V_61 ,
V_30 -> V_194 ) ;
if ( error ) {
F_16 ( V_57 L_32
L_31 , error ) ;
F_91 ( & V_30 -> V_134 -> V_61 ,
V_30 -> V_55 ) ;
goto V_107;
}
return 0 ;
V_107:
F_32 ( V_30 -> V_194 ) ;
V_30 -> V_194 = NULL ;
F_32 ( V_30 -> V_55 ) ;
V_30 -> V_55 = NULL ;
return error ;
}
void F_92 ( struct V_30 * V_30 )
{
struct V_41 * V_42 , * V_140 ;
F_68 (entry, n, &efivars->list, list) {
F_14 ( & V_30 -> V_38 ) ;
F_43 ( & V_42 -> V_104 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_33 ( V_42 ) ;
}
if ( V_30 -> V_55 )
F_91 ( & V_30 -> V_134 -> V_61 , V_30 -> V_55 ) ;
if ( V_30 -> V_194 )
F_91 ( & V_30 -> V_134 -> V_61 , V_30 -> V_194 ) ;
F_32 ( V_30 -> V_55 ) ;
F_32 ( V_30 -> V_194 ) ;
F_34 ( V_30 -> V_60 ) ;
F_93 ( V_30 -> V_134 ) ;
}
int F_94 ( struct V_30 * V_30 ,
const struct V_97 * V_33 ,
struct V_60 * V_212 )
{
T_5 V_31 = V_56 ;
T_12 V_207 ;
T_1 * V_206 ;
unsigned long V_205 = 1024 ;
int error = 0 ;
V_206 = F_58 ( V_205 , V_99 ) ;
if ( ! V_206 ) {
F_16 ( V_57 L_33 ) ;
return - V_100 ;
}
F_95 ( & V_30 -> V_38 ) ;
F_96 ( & V_30 -> V_104 ) ;
V_30 -> V_33 = V_33 ;
V_30 -> V_134 = F_97 ( L_34 , NULL , V_212 ) ;
if ( ! V_30 -> V_134 ) {
F_16 ( V_57 L_35 ) ;
error = - V_100 ;
goto V_101;
}
V_30 -> V_60 = F_98 ( L_36 , V_212 ) ;
if ( ! V_30 -> V_60 ) {
F_99 ( L_35 ) ;
error = - V_100 ;
F_93 ( V_30 -> V_134 ) ;
goto V_101;
}
do {
V_205 = 1024 ;
V_31 = V_33 -> V_213 ( & V_205 ,
V_206 ,
& V_207 ) ;
switch ( V_31 ) {
case V_39 :
F_82 ( V_30 ,
V_205 ,
V_206 ,
& V_207 ) ;
break;
case V_56 :
break;
default:
F_16 ( V_40 L_37 ,
V_31 ) ;
V_31 = V_56 ;
break;
}
} while ( V_31 != V_56 );
error = F_88 ( V_30 ) ;
if ( error )
F_92 ( V_30 ) ;
V_30 -> V_214 = V_214 ;
V_30 -> V_214 . V_43 = F_39 ( 4096 , V_99 ) ;
if ( V_30 -> V_214 . V_43 ) {
V_30 -> V_214 . V_215 = 1024 ;
V_30 -> V_214 . V_4 = V_30 ;
F_95 ( & V_30 -> V_214 . V_216 ) ;
F_100 ( & V_30 -> V_214 ) ;
}
F_101 ( & V_217 ) ;
V_101:
F_32 ( V_206 ) ;
return error ;
}
static int T_14
F_102 ( void )
{
int error = 0 ;
F_16 ( V_218 L_38 , V_219 ,
V_220 ) ;
if ( ! F_103 ( V_221 ) )
return 0 ;
V_222 = F_98 ( L_39 , V_223 ) ;
if ( ! V_222 ) {
F_16 ( V_57 L_40 ) ;
return - V_100 ;
}
V_33 . V_34 = V_196 . V_34 ;
V_33 . V_59 = V_196 . V_59 ;
V_33 . V_213 = V_196 . V_213 ;
V_33 . V_95 = V_196 . V_95 ;
error = F_94 ( & V_130 , & V_33 , V_222 ) ;
if ( error )
goto V_224;
error = F_104 ( V_222 , & V_225 ) ;
if ( error ) {
F_16 ( V_57
L_41 ,
error ) ;
goto V_226;
}
return 0 ;
V_226:
F_92 ( & V_130 ) ;
V_224:
F_34 ( V_222 ) ;
return error ;
}
static void T_15
F_105 ( void )
{
if ( F_103 ( V_221 ) ) {
F_92 ( & V_130 ) ;
F_34 ( V_222 ) ;
}
}
