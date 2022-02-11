static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return ( V_4 -> V_6 != NULL ) ;
}
static int F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 = - V_12 ;
if ( V_10 -> type != V_13 )
goto V_14;
V_11 = 0 ;
F_4 ( V_15 , V_10 , L_1 ) ;
V_14:
return V_11 ;
}
static void F_5 ( unsigned char * V_16 ,
struct V_17 * V_18 ,
unsigned char * V_19 )
{
memcpy ( V_16 , V_19 , 4 ) ;
V_16 [ 0 ] = 0 ;
if ( V_18 -> type == V_20 )
V_16 [ 1 ] = 0 ;
V_16 [ 2 ] &= 0xde ;
V_16 [ 3 ] &= 0x3c ;
}
static int F_6 ( struct V_9 * V_10 , int V_21 ,
void * V_22 , int V_23 )
{
int V_24 ;
unsigned char V_25 [] = {
V_26 ,
1 ,
V_21 ,
V_23 >> 8 ,
V_23 & 0xff ,
0
} ;
unsigned char V_27 ;
V_24 = F_7 ( V_10 , V_25 , V_28 , V_22 , V_23 ,
NULL , V_29 , V_30 , NULL ) ;
if ( F_8 ( V_24 ) )
return V_24 ;
V_27 = ( ( unsigned char * ) V_22 ) [ 0 ] ;
if ( F_9 ( V_27 == V_21 ) )
return V_24 ;
F_4 ( V_31 , V_10 ,
L_2 ,
V_21 , V_27 ) ;
return - V_32 ;
}
static int F_10 ( struct V_9 * V_10 , int V_21 ,
void * V_22 , int V_23 )
{
T_1 V_33 ;
unsigned char V_25 [] = {
V_34 ,
0x10 ,
0 ,
V_23 >> 8 ,
V_23 & 0xff ,
0
} ;
V_33 = F_7 ( V_10 , V_25 , V_35 , V_22 , V_23 ,
NULL , V_29 , V_30 , NULL ) ;
if ( V_33 )
F_4 ( V_31 , V_10 , L_3 ,
V_33 ) ;
return V_33 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
unsigned char * V_36 )
{
int V_37 , V_38 , V_39 = 0 , V_40 = V_18 -> V_41 ;
struct V_9 * V_10 = F_3 ( V_2 -> V_2 . V_42 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_43 = V_4 -> V_44 ;
unsigned char * V_45 = V_4 -> V_6 + 8 ;
memset ( V_45 , 0 , V_4 -> V_46 - 8 ) ;
for ( V_37 = 0 ; V_37 < V_4 -> V_47 ; V_37 ++ , V_43 += 4 ) {
for ( V_38 = 0 ; V_38 < V_43 [ 1 ] ; V_38 ++ ) {
V_45 += 4 ;
if ( V_43 [ 0 ] != V_20 &&
V_43 [ 0 ] != V_48 )
continue;
if ( V_39 ++ == V_40 ) {
memcpy ( V_45 , V_36 , 4 ) ;
V_45 [ 0 ] |= 0x80 ;
V_45 [ 0 ] &= 0xf0 ;
}
}
}
return F_10 ( V_10 , 2 , V_4 -> V_6 , V_4 -> V_46 ) ;
}
static unsigned char * F_12 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_37 , V_38 , V_39 = 0 , V_40 = V_18 -> V_41 ;
struct V_9 * V_10 = F_3 ( V_2 -> V_2 . V_42 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_43 = V_4 -> V_44 ;
unsigned char * V_45 = V_4 -> V_6 + 8 ;
if ( F_6 ( V_10 , 2 , V_4 -> V_6 , V_4 -> V_46 ) < 0 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_4 -> V_47 ; V_37 ++ , V_43 += 4 ) {
for ( V_38 = 0 ; V_38 < V_43 [ 1 ] ; V_38 ++ ) {
V_45 += 4 ;
if ( V_43 [ 0 ] != V_20 &&
V_43 [ 0 ] != V_48 )
continue;
if ( V_39 ++ == V_40 )
return V_45 ;
}
}
return NULL ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
unsigned char * V_36 ;
if ( ! F_1 ( V_2 ) ) {
V_18 -> V_49 = 0 ;
return;
}
V_36 = F_12 ( V_2 , V_18 ) ;
if ( V_36 )
V_18 -> V_49 = ( V_36 [ 3 ] & 0x60 ) >> 4 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
enum V_50 V_51 )
{
unsigned char V_36 [ 4 ] ;
unsigned char * V_45 ;
if ( ! F_1 ( V_2 ) )
return - V_32 ;
V_45 = F_12 ( V_2 , V_18 ) ;
if ( ! V_45 )
return - V_52 ;
F_5 ( V_36 , V_18 , V_45 ) ;
switch ( V_51 ) {
case V_53 :
V_36 [ 3 ] &= 0xdf ;
break;
case V_54 :
V_36 [ 3 ] |= 0x20 ;
break;
default:
return - V_32 ;
}
return F_11 ( V_2 , V_18 , V_36 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
unsigned char * V_36 ;
if ( ! F_1 ( V_2 ) ) {
V_18 -> V_19 = 0 ;
return;
}
V_36 = F_12 ( V_2 , V_18 ) ;
if ( V_36 )
V_18 -> V_19 = ( V_36 [ 0 ] & 0x0f ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
unsigned char * V_36 ;
if ( ! F_1 ( V_2 ) ) {
V_18 -> V_55 = 0 ;
return;
}
V_36 = F_12 ( V_2 , V_18 ) ;
if ( V_36 )
V_18 -> V_55 = ( V_36 [ 2 ] & 0x02 ) ? 1 : 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
enum V_50 V_51 )
{
unsigned char V_36 [ 4 ] ;
unsigned char * V_45 ;
if ( ! F_1 ( V_2 ) )
return - V_32 ;
V_45 = F_12 ( V_2 , V_18 ) ;
if ( ! V_45 )
return - V_52 ;
F_5 ( V_36 , V_18 , V_45 ) ;
switch ( V_51 ) {
case V_53 :
V_36 [ 2 ] &= 0xfd ;
break;
case V_54 :
V_36 [ 2 ] |= 0x02 ;
break;
default:
return - V_32 ;
}
return F_11 ( V_2 , V_18 , V_36 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
enum V_50 V_51 )
{
unsigned char V_36 [ 4 ] ;
unsigned char * V_45 ;
if ( ! F_1 ( V_2 ) )
return - V_32 ;
V_45 = F_12 ( V_2 , V_18 ) ;
if ( ! V_45 )
return - V_52 ;
F_5 ( V_36 , V_18 , V_45 ) ;
switch ( V_51 ) {
case V_53 :
V_36 [ 2 ] &= 0x7f ;
V_18 -> V_56 = 0 ;
break;
case V_54 :
V_36 [ 2 ] |= 0x80 ;
V_18 -> V_56 = 1 ;
break;
default:
return - V_32 ;
}
return F_11 ( V_2 , V_18 , V_36 ) ;
}
static int F_19 ( struct V_1 * V_2 , char * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long long V_57 = F_20 ( V_4 -> V_58 + 8 + 4 ) ;
return sprintf ( V_22 , L_4 , V_57 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
unsigned char * V_36 ;
if ( ! F_1 ( V_2 ) ) {
V_18 -> V_59 = 0 ;
return;
}
V_36 = F_12 ( V_2 , V_18 ) ;
if ( V_36 )
V_18 -> V_59 = ( V_36 [ 3 ] & 0x10 ) ? 0 : 1 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
int V_51 )
{
unsigned char V_36 [ 4 ] ;
unsigned char * V_45 ;
if ( ! F_1 ( V_2 ) )
return - V_32 ;
V_45 = F_12 ( V_2 , V_18 ) ;
if ( ! V_45 )
return - V_52 ;
F_5 ( V_36 , V_18 , V_45 ) ;
switch ( V_51 ) {
case 0 :
V_36 [ 3 ] |= 0x10 ;
break;
case 1 :
V_36 [ 3 ] &= 0xef ;
break;
default:
return - V_32 ;
}
V_18 -> V_59 = V_51 ;
return F_11 ( V_2 , V_18 , V_36 ) ;
}
static void F_23 ( struct V_17 * V_18 ,
unsigned char * V_36 )
{
int V_60 = V_36 [ 0 ] & 0x10 ;
int V_61 = V_36 [ 0 ] & 0x80 ;
enum V_62 V_63 = V_36 [ 0 ] & 0x0f ;
T_2 V_64 = 0 ;
int V_65 = - 1 ;
struct V_66 * V_67 = V_18 -> V_5 ;
unsigned char * V_68 ;
if ( V_61 )
return;
switch ( V_63 ) {
case V_69 :
if ( V_60 ) {
V_68 = V_36 + 4 ;
V_65 = V_68 [ 3 ] ;
}
break;
case V_70 :
if ( V_60 ) {
V_68 = V_36 + 4 ;
V_65 = V_68 [ 3 ] ;
V_68 = V_36 + 8 ;
} else
V_68 = V_36 + 4 ;
V_64 = ( T_2 ) V_68 [ 12 ] << 56 |
( T_2 ) V_68 [ 13 ] << 48 |
( T_2 ) V_68 [ 14 ] << 40 |
( T_2 ) V_68 [ 15 ] << 32 |
( T_2 ) V_68 [ 16 ] << 24 |
( T_2 ) V_68 [ 17 ] << 16 |
( T_2 ) V_68 [ 18 ] << 8 |
( T_2 ) V_68 [ 19 ] ;
break;
default:
break;
}
V_18 -> V_65 = V_65 ;
V_67 -> V_64 = V_64 ;
}
static int F_24 ( struct V_1 * V_2 ,
void * V_71 )
{
struct V_72 * V_72 = V_71 ;
int V_37 ;
struct V_66 * V_67 ;
if ( ! V_2 -> V_73 [ 0 ] . V_5 )
return 0 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_74 ; V_37 ++ ) {
V_67 = V_2 -> V_73 [ V_37 ] . V_5 ;
if ( V_67 -> V_64 != V_72 -> V_64 )
continue;
if ( F_25 ( V_2 , V_37 , V_72 -> V_8 ) == 0 )
F_26 ( & V_72 -> V_8 -> V_75 , V_76 ) ;
return 1 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_77 )
{
T_1 V_33 ;
unsigned char * V_22 = NULL , * V_43 , * V_45 , * V_78 = NULL ;
int V_37 , V_38 , V_79 , V_80 , V_74 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_81 = V_4 -> V_47 ;
unsigned char * V_82 = F_28 ( V_83 , V_84 ) ;
if ( ! V_82 )
goto V_85;
if ( V_4 -> V_86 )
F_6 ( V_10 , 10 , V_4 -> V_86 , V_4 -> V_87 ) ;
V_33 = F_6 ( V_10 , 7 , V_82 , V_83 ) ;
if ( V_33 )
goto V_85;
V_79 = V_80 = ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] + 4 ;
V_22 = F_28 ( V_80 + 1 , V_84 ) ;
if ( ! V_22 )
goto V_85;
V_33 = F_6 ( V_10 , 7 , V_22 , V_80 ) ;
if ( V_33 ) {
V_85:
F_29 ( V_22 ) ;
V_22 = NULL ;
V_45 = NULL ;
V_80 = 0 ;
V_79 = 0 ;
} else {
V_45 = V_22 + 8 ;
V_80 = ( V_45 [ 2 ] << 8 ) + V_45 [ 3 ] ;
V_45 += V_80 + 4 ;
}
if ( V_4 -> V_86 )
V_78 = V_4 -> V_86 + 8 ;
V_43 = V_4 -> V_44 ;
V_74 = 0 ;
for ( V_37 = 0 ; V_37 < V_81 ; V_37 ++ , V_43 += 4 ) {
for ( V_38 = 0 ; V_38 < V_43 [ 1 ] ; V_38 ++ ) {
char * V_88 = NULL ;
struct V_17 * V_18 ;
if ( V_45 ) {
if ( V_45 >= V_22 + V_79 ) {
V_45 = NULL ;
} else {
V_80 = ( V_45 [ 2 ] << 8 ) + V_45 [ 3 ] ;
V_45 += 4 ;
V_45 [ V_80 ] = '\0' ;
V_88 = V_45 ;
}
}
if ( V_43 [ 0 ] == V_20 ||
V_43 [ 0 ] == V_48 ) {
if ( V_77 )
V_18 = F_30 (
V_2 ,
V_74 ++ ,
V_43 [ 0 ] ,
V_88 ) ;
else
V_18 = & V_2 -> V_73 [ V_74 ++ ] ;
if ( ! F_31 ( V_18 ) ) {
if ( V_78 )
F_23 (
V_18 ,
V_78 ) ;
if ( V_77 )
F_32 (
V_18 ) ;
}
}
if ( V_45 )
V_45 += V_80 ;
if ( V_78 &&
( V_43 [ 0 ] == V_20 ||
V_43 [ 0 ] == V_48 ||
V_43 [ 0 ] == V_89 ||
V_43 [ 0 ] == V_90 ||
V_43 [ 0 ] == V_91 ||
V_43 [ 0 ] == V_92 ) )
V_78 += V_78 [ 1 ] + 2 ;
}
}
F_29 ( V_22 ) ;
F_29 ( V_82 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_72 V_72 = {
. V_64 = 0 ,
} ;
F_27 ( V_2 , F_3 ( V_2 -> V_2 . V_42 ) , 0 ) ;
if ( F_34 ( V_10 -> V_93 -> V_8 . V_42 ) )
V_72 . V_64 = F_35 ( V_10 ) ;
if ( V_72 . V_64 ) {
V_72 . V_8 = & V_10 -> V_94 ;
F_36 ( F_24 , & V_72 ) ;
}
}
static int F_37 ( struct V_7 * V_95 ,
struct V_96 * V_97 )
{
struct V_9 * V_10 = F_3 ( V_95 -> V_42 ) ;
struct V_9 * V_98 ;
unsigned char * V_22 = NULL , * V_82 , * V_43 , V_99 ;
struct V_3 * V_4 ;
T_1 V_33 ;
int V_37 , V_81 , V_80 , V_74 = 0 ;
int V_11 = - V_100 ;
int V_101 ;
struct V_1 * V_2 ;
struct V_66 * V_67 = NULL ;
if ( ! F_38 ( V_10 ) ) {
struct V_1 * V_102 = NULL ;
while ( ( V_2 = F_39 ( & V_10 -> V_103 -> V_104 , V_102 ) ) != NULL ) {
F_33 ( V_2 , V_10 ) ;
V_102 = V_2 ;
}
return - V_12 ;
}
if ( V_10 -> type != V_13 )
F_4 ( V_15 , V_10 , L_5 ) ;
V_4 = F_28 ( sizeof( * V_4 ) , V_84 ) ;
V_82 = F_28 ( V_83 , V_84 ) ;
if ( ! V_82 || ! V_4 )
goto V_105;
V_99 = 1 ;
V_33 = F_6 ( V_10 , V_99 , V_82 , V_83 ) ;
if ( V_33 )
goto V_106;
V_80 = ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] + 4 ;
V_22 = F_28 ( V_80 , V_84 ) ;
if ( ! V_22 )
goto V_107;
V_33 = F_6 ( V_10 , V_99 , V_22 , V_80 ) ;
if ( V_33 )
goto V_106;
V_81 = 0 ;
V_101 = V_22 [ 1 ] + 1 ;
V_43 = V_22 + 8 ;
for ( V_37 = 0 ; V_37 < V_101 && V_43 < V_22 + V_80 ; V_37 ++ ) {
V_81 += V_43 [ 2 ] ;
V_43 += V_43 [ 3 ] + 4 ;
}
V_4 -> V_44 = V_43 ;
V_4 -> V_47 = V_81 ;
for ( V_37 = 0 ; V_37 < V_81 && V_43 < V_22 + V_80 ; V_37 ++ , V_43 += 4 ) {
if ( V_43 [ 0 ] == V_20 ||
V_43 [ 0 ] == V_48 )
V_74 += V_43 [ 1 ] ;
}
V_4 -> V_58 = V_22 ;
V_4 -> V_108 = V_80 ;
V_22 = NULL ;
V_99 = 2 ;
V_33 = F_6 ( V_10 , V_99 , V_82 , V_83 ) ;
if ( V_33 )
goto V_109;
V_80 = ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] + 4 ;
V_22 = F_28 ( V_80 , V_84 ) ;
if ( ! V_22 )
goto V_107;
V_33 = F_6 ( V_10 , 2 , V_22 , V_80 ) ;
if ( V_33 )
goto V_106;
V_4 -> V_6 = V_22 ;
V_4 -> V_46 = V_80 ;
V_22 = NULL ;
V_99 = 10 ;
V_33 = F_6 ( V_10 , V_99 , V_82 , V_83 ) ;
if ( ! V_33 ) {
V_80 = ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] + 4 ;
V_22 = F_28 ( V_80 , V_84 ) ;
if ( ! V_22 )
goto V_107;
V_33 = F_6 ( V_10 , V_99 , V_22 , V_80 ) ;
if ( V_33 )
goto V_106;
V_4 -> V_86 = V_22 ;
V_4 -> V_87 = V_80 ;
V_22 = NULL ;
}
V_109:
V_67 = F_28 ( sizeof( struct V_66 ) * V_74 , V_84 ) ;
if ( ! V_67 )
goto V_107;
V_2 = F_40 ( V_95 -> V_42 , F_41 ( & V_10 -> V_94 ) ,
V_74 , & V_110 ) ;
if ( F_31 ( V_2 ) ) {
V_11 = F_42 ( V_2 ) ;
goto V_107;
}
F_29 ( V_82 ) ;
V_2 -> V_5 = V_4 ;
for ( V_37 = 0 ; V_37 < V_74 ; V_37 ++ )
V_2 -> V_73 [ V_37 ] . V_5 = V_67 + V_37 ;
F_27 ( V_2 , V_10 , 1 ) ;
F_43 (tmp_sdev, sdev->host) {
if ( V_98 -> V_111 != 0 || F_38 ( V_98 ) )
continue;
F_33 ( V_2 , V_98 ) ;
}
return 0 ;
V_106:
F_4 ( V_31 , V_10 , L_6 ,
V_99 ) ;
V_11 = - V_12 ;
V_107:
F_29 ( V_22 ) ;
F_29 ( V_67 ) ;
F_29 ( V_4 -> V_86 ) ;
F_29 ( V_4 -> V_6 ) ;
F_29 ( V_4 -> V_58 ) ;
V_105:
F_29 ( V_4 ) ;
F_29 ( V_82 ) ;
F_4 ( V_31 , V_10 , L_7 , V_11 ) ;
return V_11 ;
}
static int F_44 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_45 ( struct V_9 * V_10 )
{
struct V_1 * V_2 , * V_102 = NULL ;
while ( ( V_2 = F_39 ( & V_10 -> V_103 -> V_104 , V_102 ) ) != NULL ) {
V_102 = V_2 ;
if ( ! F_46 ( V_2 , & V_10 -> V_94 ) )
break;
}
if ( V_2 )
F_47 ( & V_2 -> V_2 ) ;
}
static void F_48 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_39 ( & V_10 -> V_94 , NULL ) ;
if ( ! V_2 )
return;
V_4 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_29 ( V_4 -> V_86 ) ;
F_29 ( V_4 -> V_58 ) ;
F_29 ( V_4 -> V_6 ) ;
F_29 ( V_4 ) ;
F_29 ( V_2 -> V_73 [ 0 ] . V_5 ) ;
F_47 ( & V_2 -> V_2 ) ;
F_49 ( V_2 ) ;
}
static void F_50 ( struct V_7 * V_95 ,
struct V_96 * V_97 )
{
struct V_9 * V_10 = F_3 ( V_95 -> V_42 ) ;
if ( ! F_38 ( V_10 ) )
F_45 ( V_10 ) ;
else
F_48 ( V_10 ) ;
}
static int T_3 F_51 ( void )
{
int V_11 ;
V_11 = F_52 ( & V_112 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_53 ( & V_113 . V_114 ) ;
if ( V_11 )
goto V_115;
return 0 ;
V_115:
F_54 ( & V_112 ) ;
return V_11 ;
}
static void T_4 F_55 ( void )
{
F_56 ( & V_113 . V_114 ) ;
F_54 ( & V_112 ) ;
}
