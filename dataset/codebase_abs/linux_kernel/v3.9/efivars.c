static bool
F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
struct V_6 * V_7 ;
int V_8 = 0 ;
V_7 = (struct V_6 * ) V_4 ;
if ( V_5 < sizeof( * V_7 ) )
return false ;
while ( V_8 <= V_5 - sizeof( * V_7 ) &&
V_7 -> V_9 >= sizeof( * V_7 ) &&
V_7 -> V_9 <= V_5 - V_8 ) {
V_8 += V_7 -> V_9 ;
if ( ( V_7 -> type == V_10 ||
V_7 -> type == V_11 ) &&
V_7 -> V_12 == V_13 )
return true ;
V_7 = (struct V_6 * ) ( V_4 + V_8 ) ;
}
return false ;
}
static bool
F_2 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
if ( ( V_5 % 2 ) != 0 )
return false ;
return true ;
}
static bool
F_3 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
T_2 V_14 ;
int V_15 , V_16 = 0 , V_17 ;
V_17 = F_4 ( V_2 -> V_18 , sizeof( V_2 -> V_18 ) ) ;
for ( V_15 = V_3 ; V_15 < V_3 + 4 ; V_15 ++ ) {
if ( V_2 -> V_18 [ V_15 ] > 127 ||
F_5 ( V_2 -> V_18 [ V_15 ] & 0xff ) < 0 )
return true ;
}
if ( V_17 > V_3 + 4 )
return false ;
if ( V_5 < 8 )
return false ;
V_14 = V_4 [ 4 ] | V_4 [ 5 ] << 8 ;
V_16 = F_6 ( ( V_19 * ) ( V_4 + 6 ) , V_5 - 6 ) + 2 ;
if ( ! V_16 )
return false ;
if ( ( V_16 + V_14 + 6 ) > V_5 )
return false ;
return F_1 ( V_2 , V_3 , V_4 + V_16 + 6 ,
V_14 ) ;
}
static bool
F_7 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
if ( V_5 != 2 )
return false ;
return true ;
}
static bool
F_8 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ ) {
if ( V_4 [ V_15 ] > 127 )
return false ;
if ( V_4 [ V_15 ] == 0 )
return true ;
}
return false ;
}
static bool
F_9 ( struct V_1 * V_2 , T_1 * V_20 , unsigned long V_5 )
{
int V_15 ;
T_2 * V_21 = V_2 -> V_18 ;
for ( V_15 = 0 ; V_22 [ V_15 ] . V_23 != NULL ; V_15 ++ ) {
const char * V_24 = V_22 [ V_15 ] . V_24 ;
int V_3 ;
for ( V_3 = 0 ; ; V_3 ++ ) {
char V_25 = V_24 [ V_3 ] ;
T_2 V_26 = V_21 [ V_3 ] ;
if ( V_26 > 127 )
return true ;
if ( V_25 == '*' )
return V_22 [ V_15 ] . V_23 ( V_2 ,
V_3 , V_20 , V_5 ) ;
if ( V_25 != V_26 )
break;
if ( ! V_25 )
return V_22 [ V_15 ] . V_23 ( V_2 ,
V_3 , V_20 , V_5 ) ;
}
}
return true ;
}
static T_3
F_10 ( struct V_27 * V_27 , struct V_1 * V_2 )
{
T_3 V_28 ;
V_2 -> V_29 = 1024 ;
V_28 = V_27 -> V_30 -> V_31 ( V_2 -> V_18 ,
& V_2 -> V_32 ,
& V_2 -> V_33 ,
& V_2 -> V_29 ,
V_2 -> V_34 ) ;
return V_28 ;
}
static T_3
F_11 ( struct V_27 * V_27 , struct V_1 * V_2 )
{
T_3 V_28 ;
unsigned long V_35 ;
F_12 ( & V_27 -> V_36 , V_35 ) ;
V_28 = F_10 ( V_27 , V_2 ) ;
F_13 ( & V_27 -> V_36 , V_35 ) ;
if ( V_28 != V_37 ) {
F_14 ( V_38 L_1 ,
V_28 ) ;
}
return V_28 ;
}
static T_3
F_15 ( struct V_27 * V_27 , T_4 V_39 ,
unsigned long V_40 )
{
const struct V_41 * V_42 = V_27 -> V_30 ;
if ( ! V_27 -> V_30 -> V_43 )
return V_44 ;
return V_42 -> V_43 ( V_39 , V_40 ) ;
}
static T_3
F_16 ( struct V_27 * V_27 , T_4 V_39 , unsigned long V_40 )
{
T_3 V_28 ;
unsigned long V_35 ;
F_12 ( & V_27 -> V_36 , V_35 ) ;
V_28 = F_15 ( V_27 , V_39 , V_40 ) ;
F_13 ( & V_27 -> V_36 , V_35 ) ;
return V_28 ;
}
static T_5
F_17 ( struct V_45 * V_46 , char * V_47 )
{
struct V_1 * V_2 = & V_46 -> V_2 ;
char * V_48 = V_47 ;
if ( ! V_46 || ! V_47 )
return 0 ;
F_18 ( & V_2 -> V_32 , V_48 ) ;
V_48 += strlen ( V_48 ) ;
V_48 += sprintf ( V_48 , L_2 ) ;
return V_48 - V_47 ;
}
static T_5
F_19 ( struct V_45 * V_46 , char * V_47 )
{
struct V_1 * V_2 = & V_46 -> V_2 ;
char * V_48 = V_47 ;
T_3 V_28 ;
if ( ! V_46 || ! V_47 )
return - V_49 ;
V_28 = F_11 ( V_46 -> V_27 , V_2 ) ;
if ( V_28 != V_37 )
return - V_50 ;
if ( V_2 -> V_33 & V_51 )
V_48 += sprintf ( V_48 , L_3 ) ;
if ( V_2 -> V_33 & V_52 )
V_48 += sprintf ( V_48 , L_4 ) ;
if ( V_2 -> V_33 & V_53 )
V_48 += sprintf ( V_48 , L_5 ) ;
if ( V_2 -> V_33 & V_54 )
V_48 += sprintf ( V_48 , L_6 ) ;
if ( V_2 -> V_33 & V_55 )
V_48 += sprintf ( V_48 ,
L_7 ) ;
if ( V_2 -> V_33 &
V_56 )
V_48 += sprintf ( V_48 ,
L_8 ) ;
if ( V_2 -> V_33 & V_57 )
V_48 += sprintf ( V_48 , L_9 ) ;
return V_48 - V_47 ;
}
static T_5
F_20 ( struct V_45 * V_46 , char * V_47 )
{
struct V_1 * V_2 = & V_46 -> V_2 ;
char * V_48 = V_47 ;
T_3 V_28 ;
if ( ! V_46 || ! V_47 )
return - V_49 ;
V_28 = F_11 ( V_46 -> V_27 , V_2 ) ;
if ( V_28 != V_37 )
return - V_50 ;
V_48 += sprintf ( V_48 , L_10 , V_2 -> V_29 ) ;
return V_48 - V_47 ;
}
static T_5
F_21 ( struct V_45 * V_46 , char * V_47 )
{
struct V_1 * V_2 = & V_46 -> V_2 ;
T_3 V_28 ;
if ( ! V_46 || ! V_47 )
return - V_49 ;
V_28 = F_11 ( V_46 -> V_27 , V_2 ) ;
if ( V_28 != V_37 )
return - V_50 ;
memcpy ( V_47 , V_2 -> V_34 , V_2 -> V_29 ) ;
return V_2 -> V_29 ;
}
static T_5
F_22 ( struct V_45 * V_46 , const char * V_47 , T_6 V_58 )
{
struct V_1 * V_59 , * V_2 = & V_46 -> V_2 ;
struct V_27 * V_27 = V_46 -> V_27 ;
T_3 V_28 = V_60 ;
if ( V_58 != sizeof( struct V_1 ) )
return - V_49 ;
V_59 = (struct V_1 * ) V_47 ;
if ( memcmp ( V_59 -> V_18 , V_2 -> V_18 , sizeof( V_2 -> V_18 ) ) ||
F_23 ( V_59 -> V_32 , V_2 -> V_32 ) ) {
F_14 ( V_61 L_11 ) ;
return - V_49 ;
}
if ( ( V_59 -> V_29 <= 0 ) || ( V_59 -> V_33 == 0 ) ) {
F_14 ( V_61 L_12 ) ;
return - V_49 ;
}
if ( ( V_59 -> V_33 & ~ V_62 ) != 0 ||
F_9 ( V_59 , V_59 -> V_34 , V_59 -> V_29 ) == false ) {
F_14 ( V_61 L_13 ) ;
return - V_49 ;
}
F_24 ( & V_27 -> V_36 ) ;
V_28 = F_15 ( V_27 , V_59 -> V_33 ,
V_59 -> V_29 + F_6 ( V_59 -> V_18 , 1024 ) ) ;
if ( V_28 == V_37 || V_28 == V_44 )
V_28 = V_27 -> V_30 -> V_63 ( V_59 -> V_18 ,
& V_59 -> V_32 ,
V_59 -> V_33 ,
V_59 -> V_29 ,
V_59 -> V_34 ) ;
F_25 ( & V_27 -> V_36 ) ;
if ( V_28 != V_37 ) {
F_14 ( V_38 L_14 ,
V_28 ) ;
return - V_50 ;
}
memcpy ( & V_46 -> V_2 , V_59 , V_58 ) ;
return V_58 ;
}
static T_5
F_26 ( struct V_45 * V_46 , char * V_47 )
{
struct V_1 * V_2 = & V_46 -> V_2 ;
T_3 V_28 ;
if ( ! V_46 || ! V_47 )
return 0 ;
V_28 = F_11 ( V_46 -> V_27 , V_2 ) ;
if ( V_28 != V_37 )
return - V_50 ;
memcpy ( V_47 , V_2 , sizeof( * V_2 ) ) ;
return sizeof( * V_2 ) ;
}
static T_5 F_27 ( struct V_64 * V_65 , struct V_66 * V_67 ,
char * V_47 )
{
struct V_45 * V_2 = F_28 ( V_65 ) ;
struct V_68 * V_69 = F_29 ( V_67 ) ;
T_5 V_70 = - V_50 ;
if ( ! F_30 ( V_71 ) )
return - V_72 ;
if ( V_69 -> V_73 ) {
V_70 = V_69 -> V_73 ( V_2 , V_47 ) ;
}
return V_70 ;
}
static T_5 F_31 ( struct V_64 * V_65 , struct V_66 * V_67 ,
const char * V_47 , T_6 V_58 )
{
struct V_45 * V_2 = F_28 ( V_65 ) ;
struct V_68 * V_69 = F_29 ( V_67 ) ;
T_5 V_70 = - V_50 ;
if ( ! F_30 ( V_71 ) )
return - V_72 ;
if ( V_69 -> V_74 )
V_70 = V_69 -> V_74 ( V_2 , V_47 , V_58 ) ;
return V_70 ;
}
static void F_32 ( struct V_64 * V_65 )
{
struct V_45 * V_2 = F_33 ( V_65 , struct V_45 , V_65 ) ;
F_34 ( V_2 ) ;
}
static inline void
F_35 ( struct V_45 * V_2 )
{
F_36 ( & V_2 -> V_65 ) ;
}
static int F_37 ( struct V_75 * V_75 , struct V_76 * V_76 )
{
V_76 -> V_77 = V_75 -> V_78 ;
return 0 ;
}
static int F_38 ( T_3 V_28 )
{
int V_79 ;
switch ( V_28 ) {
case V_80 :
V_79 = - V_49 ;
break;
case V_81 :
V_79 = - V_82 ;
break;
case V_83 :
V_79 = - V_50 ;
break;
case V_84 :
V_79 = - V_85 ;
break;
case V_86 :
V_79 = - V_72 ;
break;
case V_60 :
V_79 = - V_50 ;
break;
default:
V_79 = - V_49 ;
}
return V_79 ;
}
static T_5 F_39 ( struct V_76 * V_76 ,
const char T_7 * V_87 , T_6 V_58 , T_8 * V_88 )
{
struct V_45 * V_2 = V_76 -> V_77 ;
struct V_27 * V_27 ;
T_3 V_28 ;
void * V_20 ;
T_4 V_39 ;
struct V_75 * V_75 = V_76 -> V_89 -> V_90 ;
unsigned long V_91 = V_58 - sizeof( V_39 ) ;
unsigned long V_92 , V_93 ;
T_5 V_94 = 0 ;
if ( V_58 < sizeof( V_39 ) )
return - V_49 ;
if ( F_40 ( & V_39 , V_87 , sizeof( V_39 ) ) )
return - V_95 ;
if ( V_39 & ~ ( V_62 ) )
return - V_49 ;
V_27 = V_2 -> V_27 ;
V_93 = V_91 + F_6 ( V_2 -> V_2 . V_18 , 1024 ) ;
V_28 = F_16 ( V_27 , V_39 , V_93 ) ;
if ( V_28 != V_37 ) {
if ( V_28 != V_44 )
return F_38 ( V_28 ) ;
if ( V_91 > 65536 )
return - V_82 ;
}
V_20 = F_41 ( V_91 , V_96 ) ;
if ( ! V_20 )
return - V_97 ;
if ( F_40 ( V_20 , V_87 + sizeof( V_39 ) , V_91 ) ) {
V_94 = - V_95 ;
goto V_98;
}
if ( F_9 ( & V_2 -> V_2 , V_20 , V_91 ) == false ) {
V_94 = - V_49 ;
goto V_98;
}
F_24 ( & V_27 -> V_36 ) ;
V_28 = F_15 ( V_27 , V_39 , V_93 ) ;
if ( V_28 != V_37 && V_28 != V_44 ) {
F_25 ( & V_27 -> V_36 ) ;
F_34 ( V_20 ) ;
return F_38 ( V_28 ) ;
}
V_28 = V_27 -> V_30 -> V_63 ( V_2 -> V_2 . V_18 ,
& V_2 -> V_2 . V_32 ,
V_39 , V_91 ,
V_20 ) ;
if ( V_28 != V_37 ) {
F_25 ( & V_27 -> V_36 ) ;
F_34 ( V_20 ) ;
return F_38 ( V_28 ) ;
}
V_94 = V_58 ;
V_92 = 0 ;
V_28 = V_27 -> V_30 -> V_31 ( V_2 -> V_2 . V_18 ,
& V_2 -> V_2 . V_32 ,
NULL , & V_92 ,
NULL ) ;
if ( V_28 == V_99 ) {
F_25 ( & V_27 -> V_36 ) ;
F_42 ( & V_75 -> V_100 ) ;
F_43 ( V_75 , V_92 + sizeof( V_39 ) ) ;
F_44 ( & V_75 -> V_100 ) ;
} else if ( V_28 == V_60 ) {
F_45 ( & V_2 -> V_101 ) ;
F_25 ( & V_27 -> V_36 ) ;
F_35 ( V_2 ) ;
F_46 ( V_75 ) ;
F_47 ( V_76 -> V_102 ) ;
F_48 ( V_76 -> V_102 ) ;
} else {
F_25 ( & V_27 -> V_36 ) ;
F_49 ( L_15
L_16 , V_28 ) ;
}
V_98:
F_34 ( V_20 ) ;
return V_94 ;
}
static T_5 F_50 ( struct V_76 * V_76 , char T_7 * V_87 ,
T_6 V_58 , T_8 * V_88 )
{
struct V_45 * V_2 = V_76 -> V_77 ;
struct V_27 * V_27 = V_2 -> V_27 ;
T_3 V_28 ;
unsigned long V_91 = 0 ;
T_4 V_39 ;
void * V_20 ;
T_5 V_40 = 0 ;
F_24 ( & V_27 -> V_36 ) ;
V_28 = V_27 -> V_30 -> V_31 ( V_2 -> V_2 . V_18 ,
& V_2 -> V_2 . V_32 ,
& V_39 , & V_91 , NULL ) ;
F_25 ( & V_27 -> V_36 ) ;
if ( V_28 != V_99 )
return F_38 ( V_28 ) ;
V_20 = F_41 ( V_91 + sizeof( V_39 ) , V_96 ) ;
if ( ! V_20 )
return - V_97 ;
F_24 ( & V_27 -> V_36 ) ;
V_28 = V_27 -> V_30 -> V_31 ( V_2 -> V_2 . V_18 ,
& V_2 -> V_2 . V_32 ,
& V_39 , & V_91 ,
( V_20 + sizeof( V_39 ) ) ) ;
F_25 ( & V_27 -> V_36 ) ;
if ( V_28 != V_37 ) {
V_40 = F_38 ( V_28 ) ;
goto V_103;
}
memcpy ( V_20 , & V_39 , sizeof( V_39 ) ) ;
V_40 = F_51 ( V_87 , V_58 , V_88 ,
V_20 , V_91 + sizeof( V_39 ) ) ;
V_103:
F_34 ( V_20 ) ;
return V_40 ;
}
static void F_52 ( struct V_75 * V_75 )
{
F_53 ( V_75 ) ;
}
static struct V_75 * F_54 ( struct V_104 * V_105 ,
const struct V_75 * V_106 , int V_107 , T_9 V_108 )
{
struct V_75 * V_75 = F_55 ( V_105 ) ;
if ( V_75 ) {
V_75 -> V_109 = F_56 () ;
V_75 -> V_110 = V_107 ;
V_75 -> V_111 = V_75 -> V_112 = V_75 -> V_113 = V_114 ;
switch ( V_107 & V_115 ) {
case V_116 :
V_75 -> V_117 = & V_118 ;
break;
case V_119 :
V_75 -> V_120 = & V_121 ;
V_75 -> V_117 = & V_122 ;
F_57 ( V_75 ) ;
break;
}
}
return V_75 ;
}
static bool F_58 ( const char * V_48 , int V_5 )
{
static const char V_123 [ V_124 ] = {
[ 8 ] = 1 , [ 13 ] = 1 , [ 18 ] = 1 , [ 23 ] = 1
} ;
const char * V_125 = V_48 + V_5 - V_124 ;
int V_15 ;
if ( V_5 < V_124 + 2 )
return false ;
if ( * ( V_125 - 1 ) != '-' )
return false ;
for ( V_15 = 0 ; V_15 < V_124 ; V_15 ++ ) {
if ( V_123 [ V_15 ] ) {
if ( * V_125 ++ != '-' )
return false ;
} else {
if ( ! isxdigit ( * V_125 ++ ) )
return false ;
}
}
return true ;
}
static void F_59 ( const char * V_48 , T_10 * V_126 )
{
V_126 -> V_127 [ 0 ] = F_5 ( V_48 [ 6 ] ) << 4 | F_5 ( V_48 [ 7 ] ) ;
V_126 -> V_127 [ 1 ] = F_5 ( V_48 [ 4 ] ) << 4 | F_5 ( V_48 [ 5 ] ) ;
V_126 -> V_127 [ 2 ] = F_5 ( V_48 [ 2 ] ) << 4 | F_5 ( V_48 [ 3 ] ) ;
V_126 -> V_127 [ 3 ] = F_5 ( V_48 [ 0 ] ) << 4 | F_5 ( V_48 [ 1 ] ) ;
V_126 -> V_127 [ 4 ] = F_5 ( V_48 [ 11 ] ) << 4 | F_5 ( V_48 [ 12 ] ) ;
V_126 -> V_127 [ 5 ] = F_5 ( V_48 [ 9 ] ) << 4 | F_5 ( V_48 [ 10 ] ) ;
V_126 -> V_127 [ 6 ] = F_5 ( V_48 [ 16 ] ) << 4 | F_5 ( V_48 [ 17 ] ) ;
V_126 -> V_127 [ 7 ] = F_5 ( V_48 [ 14 ] ) << 4 | F_5 ( V_48 [ 15 ] ) ;
V_126 -> V_127 [ 8 ] = F_5 ( V_48 [ 19 ] ) << 4 | F_5 ( V_48 [ 20 ] ) ;
V_126 -> V_127 [ 9 ] = F_5 ( V_48 [ 21 ] ) << 4 | F_5 ( V_48 [ 22 ] ) ;
V_126 -> V_127 [ 10 ] = F_5 ( V_48 [ 24 ] ) << 4 | F_5 ( V_48 [ 25 ] ) ;
V_126 -> V_127 [ 11 ] = F_5 ( V_48 [ 26 ] ) << 4 | F_5 ( V_48 [ 27 ] ) ;
V_126 -> V_127 [ 12 ] = F_5 ( V_48 [ 28 ] ) << 4 | F_5 ( V_48 [ 29 ] ) ;
V_126 -> V_127 [ 13 ] = F_5 ( V_48 [ 30 ] ) << 4 | F_5 ( V_48 [ 31 ] ) ;
V_126 -> V_127 [ 14 ] = F_5 ( V_48 [ 32 ] ) << 4 | F_5 ( V_48 [ 33 ] ) ;
V_126 -> V_127 [ 15 ] = F_5 ( V_48 [ 34 ] ) << 4 | F_5 ( V_48 [ 35 ] ) ;
}
static int F_60 ( struct V_75 * V_106 , struct V_128 * V_128 ,
T_11 V_107 , bool V_129 )
{
struct V_75 * V_75 ;
struct V_27 * V_27 = & V_130 ;
struct V_45 * V_2 ;
int V_17 , V_15 = 0 , V_79 = 0 ;
if ( ! F_58 ( V_128 -> V_131 . V_24 , V_128 -> V_131 . V_5 ) )
return - V_49 ;
V_75 = F_54 ( V_106 -> V_132 , V_106 , V_107 , 0 ) ;
if ( ! V_75 )
return - V_97 ;
V_2 = F_61 ( sizeof( struct V_45 ) , V_96 ) ;
if ( ! V_2 ) {
V_79 = - V_97 ;
goto V_98;
}
V_17 = V_128 -> V_131 . V_5 - V_124 - 1 ;
F_59 ( V_128 -> V_131 . V_24 + V_17 + 1 ,
& V_2 -> V_2 . V_32 ) ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ )
V_2 -> V_2 . V_18 [ V_15 ] = V_128 -> V_131 . V_24 [ V_15 ] ;
V_2 -> V_2 . V_18 [ V_15 ] = '\0' ;
V_75 -> V_78 = V_2 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_65 . V_133 = V_27 -> V_133 ;
V_79 = F_62 ( & V_2 -> V_65 , & V_134 , NULL , L_17 ,
V_128 -> V_131 . V_24 ) ;
if ( V_79 )
goto V_98;
F_63 ( & V_2 -> V_65 , V_135 ) ;
F_24 ( & V_27 -> V_36 ) ;
F_64 ( & V_2 -> V_101 , & V_27 -> V_101 ) ;
F_25 ( & V_27 -> V_36 ) ;
F_65 ( V_128 , V_75 ) ;
F_66 ( V_128 ) ;
V_98:
if ( V_79 ) {
F_34 ( V_2 ) ;
F_67 ( V_75 ) ;
}
return V_79 ;
}
static int F_68 ( struct V_75 * V_106 , struct V_128 * V_128 )
{
struct V_45 * V_2 = V_128 -> V_136 -> V_78 ;
struct V_27 * V_27 = V_2 -> V_27 ;
T_3 V_28 ;
F_24 ( & V_27 -> V_36 ) ;
V_28 = V_27 -> V_30 -> V_63 ( V_2 -> V_2 . V_18 ,
& V_2 -> V_2 . V_32 ,
0 , 0 , NULL ) ;
if ( V_28 == V_37 || V_28 == V_60 ) {
F_45 ( & V_2 -> V_101 ) ;
F_25 ( & V_27 -> V_36 ) ;
F_35 ( V_2 ) ;
F_46 ( V_128 -> V_136 ) ;
F_48 ( V_128 ) ;
return 0 ;
}
F_25 ( & V_27 -> V_36 ) ;
return - V_49 ;
}
static int F_69 ( const struct V_128 * V_137 , const struct V_75 * V_138 ,
const struct V_128 * V_128 , const struct V_75 * V_75 ,
unsigned int V_5 , const char * V_48 ,
const struct V_139 * V_24 )
{
int V_126 = V_5 - V_124 ;
if ( V_24 -> V_5 != V_5 )
return 1 ;
if ( memcmp ( V_48 , V_24 -> V_24 , V_126 ) )
return 1 ;
return strncasecmp ( V_24 -> V_24 + V_126 , V_48 + V_126 , V_124 ) ;
}
static int F_70 ( const struct V_128 * V_128 ,
const struct V_75 * V_75 , struct V_139 * V_139 )
{
unsigned long V_140 = F_71 () ;
const unsigned char * V_125 = V_139 -> V_24 ;
unsigned int V_5 = V_139 -> V_5 ;
if ( ! F_58 ( V_125 , V_5 ) )
return - V_49 ;
while ( V_5 -- > V_124 )
V_140 = F_72 ( * V_125 ++ , V_140 ) ;
while ( V_5 -- )
V_140 = F_72 ( tolower ( * V_125 ++ ) , V_140 ) ;
V_139 -> V_140 = F_73 ( V_140 ) ;
return 0 ;
}
static int F_74 ( const struct V_128 * V_128 )
{
return 1 ;
}
static struct V_128 * F_75 ( struct V_128 * V_137 , char * V_24 )
{
struct V_128 * V_141 ;
struct V_139 V_142 ;
int V_79 ;
V_142 . V_24 = V_24 ;
V_142 . V_5 = strlen ( V_24 ) ;
V_79 = F_70 ( NULL , NULL , & V_142 ) ;
if ( V_79 )
return F_76 ( V_79 ) ;
V_141 = F_77 ( V_137 , & V_142 ) ;
if ( V_141 )
return V_141 ;
return F_76 ( - V_97 ) ;
}
static int F_78 ( struct V_104 * V_105 , void * V_20 , int V_143 )
{
struct V_75 * V_75 = NULL ;
struct V_128 * V_144 ;
struct V_45 * V_46 , * V_145 ;
struct V_27 * V_27 = & V_130 ;
char * V_24 ;
int V_79 = - V_97 ;
V_146 = V_105 ;
V_105 -> V_147 = V_148 ;
V_105 -> V_149 = V_150 ;
V_105 -> V_151 = V_152 ;
V_105 -> V_153 = V_154 ;
V_105 -> V_155 = & V_156 ;
V_105 -> V_157 = & V_158 ;
V_105 -> V_159 = 1 ;
V_75 = F_54 ( V_105 , NULL , V_119 | 0755 , 0 ) ;
if ( ! V_75 )
return - V_97 ;
V_75 -> V_120 = & V_121 ;
V_144 = F_79 ( V_75 ) ;
V_105 -> V_160 = V_144 ;
if ( ! V_144 )
return - V_97 ;
F_80 (entry, n, &efivars->list, list) {
struct V_128 * V_128 , * V_144 = V_146 -> V_160 ;
unsigned long V_40 = 0 ;
int V_5 , V_15 ;
V_75 = NULL ;
V_5 = F_81 ( V_46 -> V_2 . V_18 ) ;
V_24 = F_41 ( V_5 + 1 + V_124 + 1 , V_161 ) ;
if ( ! V_24 )
goto V_162;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ )
V_24 [ V_15 ] = V_46 -> V_2 . V_18 [ V_15 ] & 0xFF ;
V_24 [ V_5 ] = '-' ;
F_18 ( & V_46 -> V_2 . V_32 , V_24 + V_5 + 1 ) ;
V_24 [ V_5 + V_124 + 1 ] = '\0' ;
V_75 = F_54 ( V_146 , V_144 -> V_136 ,
V_116 | 0644 , 0 ) ;
if ( ! V_75 )
goto V_163;
V_128 = F_75 ( V_144 , V_24 ) ;
if ( F_82 ( V_128 ) ) {
V_79 = F_83 ( V_128 ) ;
goto V_164;
}
F_34 ( V_24 ) ;
F_24 ( & V_27 -> V_36 ) ;
V_27 -> V_30 -> V_31 ( V_46 -> V_2 . V_18 ,
& V_46 -> V_2 . V_32 ,
& V_46 -> V_2 . V_33 ,
& V_40 ,
NULL ) ;
F_25 ( & V_27 -> V_36 ) ;
F_42 ( & V_75 -> V_100 ) ;
V_75 -> V_78 = V_46 ;
F_43 ( V_75 , V_40 + sizeof( V_46 -> V_2 . V_33 ) ) ;
F_44 ( & V_75 -> V_100 ) ;
F_84 ( V_128 , V_75 ) ;
}
return 0 ;
V_164:
F_67 ( V_75 ) ;
V_163:
F_34 ( V_24 ) ;
V_162:
return V_79 ;
}
static struct V_128 * F_85 ( struct V_165 * V_166 ,
int V_35 , const char * V_167 , void * V_20 )
{
return F_86 ( V_166 , V_35 , V_20 , F_78 ) ;
}
static void F_87 ( struct V_104 * V_105 )
{
F_88 ( V_105 ) ;
V_146 = NULL ;
}
static struct V_128 * F_89 ( struct V_75 * V_106 , struct V_128 * V_128 ,
unsigned int V_35 )
{
if ( V_128 -> V_131 . V_5 > V_168 )
return F_76 ( - V_169 ) ;
F_84 ( V_128 , NULL ) ;
return NULL ;
}
static int F_90 ( struct V_170 * V_171 )
{
struct V_27 * V_27 = V_171 -> V_20 ;
F_24 ( & V_27 -> V_36 ) ;
V_27 -> V_172 = F_91 ( & V_27 -> V_101 ,
struct V_45 , V_101 ) ;
return 0 ;
}
static int F_92 ( struct V_170 * V_171 )
{
struct V_27 * V_27 = V_171 -> V_20 ;
F_25 ( & V_27 -> V_36 ) ;
return 0 ;
}
static T_5 F_93 ( T_12 * V_173 , enum V_174 * type ,
int * V_58 , struct V_175 * V_175 ,
char * * V_47 , struct V_170 * V_171 )
{
T_10 V_176 = V_177 ;
struct V_27 * V_27 = V_171 -> V_20 ;
char V_24 [ V_178 ] ;
int V_15 ;
int V_179 ;
unsigned int V_180 , V_40 ;
unsigned long time ;
while ( & V_27 -> V_172 -> V_101 != & V_27 -> V_101 ) {
if ( ! F_23 ( V_27 -> V_172 -> V_2 . V_32 ,
V_176 ) ) {
for ( V_15 = 0 ; V_15 < V_178 ; V_15 ++ ) {
V_24 [ V_15 ] = V_27 -> V_172 -> V_2 . V_18 [ V_15 ] ;
}
if ( sscanf ( V_24 , L_18 ,
type , & V_180 , & V_179 , & time ) == 4 ) {
* V_173 = V_180 ;
* V_58 = V_179 ;
V_175 -> V_181 = time ;
V_175 -> V_182 = 0 ;
} else if ( sscanf ( V_24 , L_19 ,
type , & V_180 , & time ) == 3 ) {
* V_173 = V_180 ;
* V_58 = 0 ;
V_175 -> V_181 = time ;
V_175 -> V_182 = 0 ;
} else {
V_27 -> V_172 = F_94 (
V_27 -> V_172 -> V_101 . V_183 ,
struct V_45 , V_101 ) ;
continue;
}
F_10 ( V_27 , & V_27 -> V_172 -> V_2 ) ;
V_40 = V_27 -> V_172 -> V_2 . V_29 ;
* V_47 = F_41 ( V_40 , V_96 ) ;
if ( * V_47 == NULL )
return - V_97 ;
memcpy ( * V_47 , V_27 -> V_172 -> V_2 . V_34 ,
V_40 ) ;
V_27 -> V_172 = F_94 (
V_27 -> V_172 -> V_101 . V_183 ,
struct V_45 , V_101 ) ;
return V_40 ;
}
V_27 -> V_172 = F_94 ( V_27 -> V_172 -> V_101 . V_183 ,
struct V_45 , V_101 ) ;
}
return 0 ;
}
static int F_95 ( enum V_174 type ,
enum V_184 V_185 , T_12 * V_173 ,
unsigned int V_180 , int V_58 , T_6 V_40 ,
struct V_170 * V_171 )
{
char V_24 [ V_178 ] ;
V_19 V_186 [ V_178 ] ;
T_10 V_176 = V_177 ;
struct V_27 * V_27 = V_171 -> V_20 ;
int V_15 , V_70 = 0 ;
T_3 V_28 = V_60 ;
unsigned long V_35 ;
if ( F_96 ( V_185 ) ) {
if ( ! F_97 ( & V_27 -> V_36 , V_35 ) )
return - V_187 ;
} else
F_12 ( & V_27 -> V_36 , V_35 ) ;
V_28 = F_15 ( V_27 , V_188 ,
V_40 + V_178 * 2 ) ;
if ( V_28 ) {
F_13 ( & V_27 -> V_36 , V_35 ) ;
* V_173 = V_180 ;
return - V_82 ;
}
sprintf ( V_24 , L_18 , type , V_180 , V_58 ,
F_98 () ) ;
for ( V_15 = 0 ; V_15 < V_178 ; V_15 ++ )
V_186 [ V_15 ] = V_24 [ V_15 ] ;
V_27 -> V_30 -> V_63 ( V_186 , & V_176 , V_188 ,
V_40 , V_171 -> V_47 ) ;
F_13 ( & V_27 -> V_36 , V_35 ) ;
if ( V_185 == V_189 && V_190 )
F_99 ( & V_191 ) ;
* V_173 = V_180 ;
return V_70 ;
}
static int F_100 ( enum V_174 type , T_12 V_173 , int V_58 ,
struct V_175 time , struct V_170 * V_171 )
{
char V_24 [ V_178 ] ;
V_19 V_186 [ V_178 ] ;
char V_192 [ V_178 ] ;
V_19 V_193 [ V_178 ] ;
T_10 V_176 = V_177 ;
struct V_27 * V_27 = V_171 -> V_20 ;
struct V_45 * V_46 , * V_194 = NULL ;
int V_15 ;
sprintf ( V_24 , L_18 , type , ( unsigned int ) V_173 , V_58 ,
time . V_181 ) ;
F_24 ( & V_27 -> V_36 ) ;
for ( V_15 = 0 ; V_15 < V_178 ; V_15 ++ )
V_186 [ V_15 ] = V_24 [ V_15 ] ;
F_101 (entry, &efivars->list, list) {
F_10 ( V_27 , & V_46 -> V_2 ) ;
if ( F_23 ( V_46 -> V_2 . V_32 , V_176 ) )
continue;
if ( F_102 ( V_46 -> V_2 . V_18 , V_186 ,
F_81 ( V_186 ) ) ) {
sprintf ( V_192 , L_19 , type ,
( unsigned int ) V_173 , time . V_181 ) ;
for ( V_15 = 0 ; V_15 < V_178 ; V_15 ++ )
V_193 [ V_15 ] = V_192 [ V_15 ] ;
if ( F_102 ( V_46 -> V_2 . V_18 , V_193 ,
F_81 ( V_193 ) ) )
continue;
}
V_194 = V_46 ;
V_27 -> V_30 -> V_63 ( V_46 -> V_2 . V_18 ,
& V_46 -> V_2 . V_32 ,
V_188 ,
0 , NULL ) ;
break;
}
if ( V_194 )
F_45 ( & V_194 -> V_101 ) ;
F_25 ( & V_27 -> V_36 ) ;
if ( V_194 )
F_35 ( V_194 ) ;
return 0 ;
}
static void F_103 ( struct V_27 * V_27 )
{
V_27 -> V_195 = V_195 ;
V_27 -> V_195 . V_47 = F_41 ( 4096 , V_96 ) ;
if ( V_27 -> V_195 . V_47 ) {
V_27 -> V_195 . V_196 = 1024 ;
V_27 -> V_195 . V_20 = V_27 ;
F_104 ( & V_27 -> V_195 . V_197 ) ;
F_105 ( & V_27 -> V_195 ) ;
}
}
static void F_103 ( struct V_27 * V_27 )
{
return;
}
static T_5 F_106 ( struct V_76 * V_198 , struct V_64 * V_65 ,
struct V_199 * V_200 ,
char * V_47 , T_8 V_201 , T_6 V_58 )
{
struct V_1 * V_59 = (struct V_1 * ) V_47 ;
struct V_27 * V_27 = V_200 -> V_202 ;
struct V_45 * V_203 , * V_145 ;
unsigned long V_204 , V_205 ;
T_3 V_28 = V_60 ;
int V_194 = 0 ;
if ( ! F_30 ( V_71 ) )
return - V_72 ;
if ( ( V_59 -> V_33 & ~ V_62 ) != 0 ||
F_9 ( V_59 , V_59 -> V_34 , V_59 -> V_29 ) == false ) {
F_14 ( V_61 L_13 ) ;
return - V_49 ;
}
F_24 ( & V_27 -> V_36 ) ;
F_80 (search_efivar, n, &efivars->list, list) {
V_204 = F_6 ( V_203 -> V_2 . V_18 , 1024 ) ;
V_205 = F_6 ( V_59 -> V_18 , 1024 ) ;
if ( V_204 == V_205 &&
! memcmp ( & ( V_203 -> V_2 . V_18 ) ,
V_59 -> V_18 , V_204 ) &&
! F_23 ( V_203 -> V_2 . V_32 ,
V_59 -> V_32 ) ) {
V_194 = 1 ;
break;
}
}
if ( V_194 ) {
F_25 ( & V_27 -> V_36 ) ;
return - V_49 ;
}
V_28 = F_15 ( V_27 , V_59 -> V_33 ,
V_59 -> V_29 + F_6 ( V_59 -> V_18 , 1024 ) ) ;
if ( V_28 && V_28 != V_44 ) {
F_25 ( & V_27 -> V_36 ) ;
return F_38 ( V_28 ) ;
}
V_28 = V_27 -> V_30 -> V_63 ( V_59 -> V_18 ,
& V_59 -> V_32 ,
V_59 -> V_33 ,
V_59 -> V_29 ,
V_59 -> V_34 ) ;
if ( V_28 != V_37 ) {
F_14 ( V_38 L_14 ,
V_28 ) ;
F_25 ( & V_27 -> V_36 ) ;
return - V_50 ;
}
F_25 ( & V_27 -> V_36 ) ;
V_28 = F_107 ( V_27 ,
F_6 ( V_59 -> V_18 ,
1024 ) ,
V_59 -> V_18 ,
& V_59 -> V_32 ) ;
if ( V_28 ) {
F_14 ( V_38 L_20 ) ;
}
return V_58 ;
}
static T_5 F_108 ( struct V_76 * V_198 , struct V_64 * V_65 ,
struct V_199 * V_200 ,
char * V_47 , T_8 V_201 , T_6 V_58 )
{
struct V_1 * V_206 = (struct V_1 * ) V_47 ;
struct V_27 * V_27 = V_200 -> V_202 ;
struct V_45 * V_203 , * V_145 ;
unsigned long V_204 , V_205 ;
T_3 V_28 = V_60 ;
int V_194 = 0 ;
if ( ! F_30 ( V_71 ) )
return - V_72 ;
F_24 ( & V_27 -> V_36 ) ;
F_80 (search_efivar, n, &efivars->list, list) {
V_204 = F_6 ( V_203 -> V_2 . V_18 , 1024 ) ;
V_205 = F_6 ( V_206 -> V_18 , 1024 ) ;
if ( V_204 == V_205 &&
! memcmp ( & ( V_203 -> V_2 . V_18 ) ,
V_206 -> V_18 , V_204 ) &&
! F_23 ( V_203 -> V_2 . V_32 ,
V_206 -> V_32 ) ) {
V_194 = 1 ;
break;
}
}
if ( ! V_194 ) {
F_25 ( & V_27 -> V_36 ) ;
return - V_49 ;
}
V_206 -> V_33 = 0 ;
V_206 -> V_29 = 0 ;
V_28 = V_27 -> V_30 -> V_63 ( V_206 -> V_18 ,
& V_206 -> V_32 ,
V_206 -> V_33 ,
V_206 -> V_29 ,
V_206 -> V_34 ) ;
if ( V_28 != V_37 ) {
F_14 ( V_38 L_14 ,
V_28 ) ;
F_25 ( & V_27 -> V_36 ) ;
return - V_50 ;
}
F_45 ( & V_203 -> V_101 ) ;
F_25 ( & V_27 -> V_36 ) ;
F_35 ( V_203 ) ;
return V_58 ;
}
static bool F_109 ( struct V_27 * V_27 ,
V_19 * V_207 ,
T_10 * V_176 )
{
struct V_45 * V_46 , * V_145 ;
unsigned long V_204 , V_205 ;
bool V_194 = false ;
V_204 = F_6 ( V_207 , 1024 ) ;
F_80 (entry, n, &efivars->list, list) {
V_205 = F_6 ( V_46 -> V_2 . V_18 , 1024 ) ;
if ( V_204 == V_205 &&
! memcmp ( V_207 , & ( V_46 -> V_2 . V_18 ) ,
V_205 ) &&
! F_23 ( V_46 -> V_2 . V_32 ,
* V_176 ) ) {
V_194 = true ;
break;
}
}
return V_194 ;
}
static unsigned long F_110 ( V_19 * V_207 ,
unsigned long V_208 )
{
unsigned long V_5 ;
V_19 V_25 ;
for ( V_5 = 2 ; V_5 <= V_208 ; V_5 += sizeof( V_25 ) ) {
V_25 = V_207 [ ( V_5 / sizeof( V_25 ) ) - 1 ] ;
if ( ! V_25 )
break;
}
return F_111 ( V_5 , V_208 ) ;
}
static void F_112 ( struct V_209 * V_210 )
{
struct V_27 * V_27 = & V_130 ;
T_10 V_176 ;
V_19 * V_207 ;
unsigned long V_208 = 1024 ;
T_3 V_28 = V_60 ;
bool V_194 ;
while ( 1 ) {
V_207 = F_61 ( V_208 , V_96 ) ;
if ( ! V_207 ) {
F_113 ( L_21 ) ;
return;
}
F_24 ( & V_27 -> V_36 ) ;
V_194 = false ;
while ( 1 ) {
V_208 = 1024 ;
V_28 = V_27 -> V_30 -> V_211 (
& V_208 ,
V_207 ,
& V_176 ) ;
if ( V_28 != V_37 ) {
break;
} else {
if ( ! F_109 ( V_27 ,
V_207 , & V_176 ) ) {
V_194 = true ;
break;
}
}
}
F_25 ( & V_27 -> V_36 ) ;
if ( ! V_194 ) {
F_34 ( V_207 ) ;
break;
} else {
V_208 = F_110 ( V_207 ,
V_208 ) ;
F_107 ( V_27 ,
V_208 ,
V_207 , & V_176 ) ;
}
}
}
static T_5 F_114 ( struct V_64 * V_65 ,
struct V_212 * V_67 , char * V_47 )
{
char * V_48 = V_47 ;
if ( ! V_65 || ! V_47 )
return - V_49 ;
if ( V_213 . V_214 != V_215 )
V_48 += sprintf ( V_48 , L_22 , V_213 . V_214 ) ;
if ( V_213 . V_216 != V_215 )
V_48 += sprintf ( V_48 , L_23 , V_213 . V_216 ) ;
if ( V_213 . V_217 != V_215 )
V_48 += sprintf ( V_48 , L_24 , V_213 . V_217 ) ;
if ( V_213 . V_218 != V_215 )
V_48 += sprintf ( V_48 , L_25 , V_213 . V_218 ) ;
if ( V_213 . V_219 != V_215 )
V_48 += sprintf ( V_48 , L_26 , V_213 . V_219 ) ;
if ( V_213 . V_220 != V_215 )
V_48 += sprintf ( V_48 , L_27 , V_213 . V_220 ) ;
if ( V_213 . V_221 != V_215 )
V_48 += sprintf ( V_48 , L_28 , V_213 . V_221 ) ;
return V_48 - V_47 ;
}
static int
F_107 ( struct V_27 * V_27 ,
unsigned long V_208 ,
V_19 * V_207 ,
T_10 * V_222 )
{
int V_15 , V_223 ;
char * V_224 ;
struct V_45 * V_225 ;
V_223 = V_208 / sizeof( V_19 )
+ 1 + V_124 + 1 ;
V_224 = F_61 ( V_223 , V_96 ) ;
V_225 = F_61 ( sizeof( struct V_45 ) , V_96 ) ;
if ( ! V_224 || ! V_225 ) {
F_34 ( V_224 ) ;
F_34 ( V_225 ) ;
return 1 ;
}
V_225 -> V_27 = V_27 ;
memcpy ( V_225 -> V_2 . V_18 , V_207 ,
V_208 ) ;
memcpy ( & ( V_225 -> V_2 . V_32 ) , V_222 , sizeof( T_10 ) ) ;
for ( V_15 = 0 ; V_15 < ( int ) ( V_208 / sizeof( V_19 ) ) ; V_15 ++ ) {
V_224 [ V_15 ] = V_207 [ V_15 ] & 0xFF ;
}
* ( V_224 + strlen ( V_224 ) ) = '-' ;
F_18 ( V_222 , V_224 + strlen ( V_224 ) ) ;
V_225 -> V_65 . V_133 = V_27 -> V_133 ;
V_15 = F_62 ( & V_225 -> V_65 , & V_134 , NULL ,
L_17 , V_224 ) ;
if ( V_15 ) {
F_34 ( V_224 ) ;
F_34 ( V_225 ) ;
return 1 ;
}
F_63 ( & V_225 -> V_65 , V_135 ) ;
F_34 ( V_224 ) ;
V_224 = NULL ;
F_24 ( & V_27 -> V_36 ) ;
F_64 ( & V_225 -> V_101 , & V_27 -> V_101 ) ;
F_25 ( & V_27 -> V_36 ) ;
return 0 ;
}
static int
F_115 ( struct V_27 * V_27 )
{
struct V_199 * V_67 ;
int error ;
V_67 = F_61 ( sizeof( * V_67 ) , V_96 ) ;
if ( ! V_67 )
return - V_97 ;
V_67 -> V_67 . V_24 = L_29 ;
V_67 -> V_67 . V_107 = 0200 ;
V_67 -> V_226 = F_106 ;
V_67 -> V_202 = V_27 ;
V_27 -> V_59 = V_67 ;
V_67 = F_61 ( sizeof( * V_67 ) , V_96 ) ;
if ( ! V_67 ) {
error = - V_97 ;
goto V_103;
}
V_67 -> V_67 . V_24 = L_30 ;
V_67 -> V_67 . V_107 = 0200 ;
V_67 -> V_226 = F_108 ;
V_67 -> V_202 = V_27 ;
V_27 -> V_206 = V_67 ;
F_116 ( V_27 -> V_59 ) ;
F_116 ( V_27 -> V_206 ) ;
error = F_117 ( & V_27 -> V_133 -> V_65 ,
V_27 -> V_59 ) ;
if ( error ) {
F_14 ( V_61 L_31
L_32 , error ) ;
goto V_103;
}
error = F_117 ( & V_27 -> V_133 -> V_65 ,
V_27 -> V_206 ) ;
if ( error ) {
F_14 ( V_61 L_33
L_32 , error ) ;
F_118 ( & V_27 -> V_133 -> V_65 ,
V_27 -> V_59 ) ;
goto V_103;
}
return 0 ;
V_103:
F_34 ( V_27 -> V_206 ) ;
V_27 -> V_206 = NULL ;
F_34 ( V_27 -> V_59 ) ;
V_27 -> V_59 = NULL ;
return error ;
}
void F_119 ( struct V_27 * V_27 )
{
struct V_45 * V_46 , * V_145 ;
F_80 (entry, n, &efivars->list, list) {
F_24 ( & V_27 -> V_36 ) ;
F_45 ( & V_46 -> V_101 ) ;
F_25 ( & V_27 -> V_36 ) ;
F_35 ( V_46 ) ;
}
if ( V_27 -> V_59 )
F_118 ( & V_27 -> V_133 -> V_65 , V_27 -> V_59 ) ;
if ( V_27 -> V_206 )
F_118 ( & V_27 -> V_133 -> V_65 , V_27 -> V_206 ) ;
F_34 ( V_27 -> V_59 ) ;
F_34 ( V_27 -> V_206 ) ;
F_36 ( V_27 -> V_64 ) ;
F_120 ( V_27 -> V_133 ) ;
}
static void F_121 ( V_19 * V_227 , T_10 * V_222 ,
unsigned long V_228 )
{
T_6 V_15 , V_229 = V_228 / sizeof( V_19 ) ;
char * V_230 ;
V_190 = false ;
V_230 = F_61 ( V_229 , V_96 ) ;
if ( ! V_230 )
return;
for ( V_15 = 0 ; V_15 < V_229 ; V_15 ++ )
V_230 [ V_15 ] = V_227 [ V_15 ] ;
F_14 ( V_38 L_34 ,
V_230 , V_222 ) ;
F_34 ( V_230 ) ;
}
int F_122 ( struct V_27 * V_27 ,
const struct V_41 * V_30 ,
struct V_64 * V_231 )
{
T_3 V_28 = V_60 ;
T_10 V_222 ;
V_19 * V_207 ;
unsigned long V_208 = 1024 ;
int error = 0 ;
V_207 = F_61 ( V_208 , V_96 ) ;
if ( ! V_207 ) {
F_14 ( V_61 L_21 ) ;
return - V_97 ;
}
F_104 ( & V_27 -> V_36 ) ;
F_123 ( & V_27 -> V_101 ) ;
V_27 -> V_30 = V_30 ;
V_27 -> V_133 = F_124 ( L_35 , NULL , V_231 ) ;
if ( ! V_27 -> V_133 ) {
F_14 ( V_61 L_36 ) ;
error = - V_97 ;
goto V_98;
}
V_27 -> V_64 = F_125 ( L_37 , V_231 ) ;
if ( ! V_27 -> V_64 ) {
F_113 ( L_36 ) ;
error = - V_97 ;
F_120 ( V_27 -> V_133 ) ;
goto V_98;
}
do {
V_208 = 1024 ;
V_28 = V_30 -> V_211 ( & V_208 ,
V_207 ,
& V_222 ) ;
switch ( V_28 ) {
case V_37 :
V_208 = F_110 ( V_207 ,
V_208 ) ;
if ( F_109 ( V_27 , V_207 ,
& V_222 ) ) {
F_121 ( V_207 , & V_222 ,
V_208 ) ;
V_28 = V_60 ;
break;
}
F_107 ( V_27 ,
V_208 ,
V_207 ,
& V_222 ) ;
break;
case V_60 :
break;
default:
F_14 ( V_38 L_38 ,
V_28 ) ;
V_28 = V_60 ;
break;
}
} while ( V_28 != V_60 );
error = F_115 ( V_27 ) ;
if ( error )
F_119 ( V_27 ) ;
if ( ! V_232 )
F_103 ( V_27 ) ;
F_126 ( & V_233 ) ;
V_98:
F_34 ( V_207 ) ;
return error ;
}
static int T_13
F_127 ( void )
{
int error = 0 ;
F_14 ( V_234 L_39 , V_235 ,
V_236 ) ;
if ( ! F_128 ( V_237 ) )
return 0 ;
V_238 = F_125 ( L_40 , V_239 ) ;
if ( ! V_238 ) {
F_14 ( V_61 L_41 ) ;
return - V_97 ;
}
V_30 . V_31 = V_213 . V_31 ;
V_30 . V_63 = V_213 . V_63 ;
V_30 . V_211 = V_213 . V_211 ;
V_30 . V_43 = V_240 ;
error = F_122 ( & V_130 , & V_30 , V_238 ) ;
if ( error )
goto V_241;
error = F_129 ( V_238 , & V_242 ) ;
if ( error ) {
F_14 ( V_61
L_42 ,
error ) ;
goto V_243;
}
return 0 ;
V_243:
F_119 ( & V_130 ) ;
V_241:
F_36 ( V_238 ) ;
return error ;
}
static void T_14
F_130 ( void )
{
F_131 ( & V_191 ) ;
if ( F_128 ( V_237 ) ) {
F_119 ( & V_130 ) ;
F_36 ( V_238 ) ;
}
}
