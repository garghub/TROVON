static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = - V_6 ;
if ( V_4 -> type != V_7 )
goto V_8;
V_5 = 0 ;
F_3 ( V_9 , V_4 , L_1 ) ;
V_8:
return V_5 ;
}
static void F_4 ( unsigned char * V_10 ,
struct V_11 * V_12 ,
unsigned char * V_13 )
{
memcpy ( V_10 , V_13 , 4 ) ;
V_10 [ 0 ] = 0 ;
if ( V_12 -> type == V_14 )
V_10 [ 1 ] = 0 ;
V_10 [ 2 ] &= 0xde ;
V_10 [ 3 ] &= 0x3c ;
}
static int F_5 ( struct V_3 * V_4 , int V_15 ,
void * V_16 , int V_17 )
{
int V_18 ;
unsigned char V_19 [] = {
V_20 ,
1 ,
V_15 ,
V_17 >> 8 ,
V_17 & 0xff ,
0
} ;
unsigned char V_21 ;
V_18 = F_6 ( V_4 , V_19 , V_22 , V_16 , V_17 ,
NULL , V_23 , V_24 , NULL ) ;
if ( F_7 ( ! V_18 ) )
return V_18 ;
V_21 = ( ( unsigned char * ) V_16 ) [ 0 ] ;
if ( F_8 ( V_21 == V_15 ) )
return V_18 ;
F_3 ( V_25 , V_4 ,
L_2 ,
V_15 , V_21 ) ;
return - V_26 ;
}
static int F_9 ( struct V_3 * V_4 , int V_15 ,
void * V_16 , int V_17 )
{
T_1 V_27 ;
unsigned char V_19 [] = {
V_28 ,
0x10 ,
0 ,
V_17 >> 8 ,
V_17 & 0xff ,
0
} ;
V_27 = F_6 ( V_4 , V_19 , V_29 , V_16 , V_17 ,
NULL , V_23 , V_24 , NULL ) ;
if ( V_27 )
F_3 ( V_25 , V_4 , L_3 ,
V_27 ) ;
return V_27 ;
}
static int F_10 ( struct V_30 * V_31 ,
struct V_11 * V_12 ,
unsigned char * V_32 )
{
int V_33 , V_34 , V_35 = 0 , V_36 = V_12 -> V_37 ;
struct V_3 * V_4 = F_2 ( V_31 -> V_31 . V_38 ) ;
struct V_39 * V_40 = V_31 -> V_41 ;
unsigned char * V_42 = V_40 -> V_43 ;
unsigned char * V_44 = V_40 -> V_45 + 8 ;
memset ( V_44 , 0 , V_40 -> V_46 - 8 ) ;
for ( V_33 = 0 ; V_33 < V_40 -> V_47 ; V_33 ++ , V_42 += 4 ) {
for ( V_34 = 0 ; V_34 < V_42 [ 1 ] ; V_34 ++ ) {
V_44 += 4 ;
if ( V_42 [ 0 ] != V_14 &&
V_42 [ 0 ] != V_48 )
continue;
if ( V_35 ++ == V_36 ) {
memcpy ( V_44 , V_32 , 4 ) ;
V_44 [ 0 ] |= 0x80 ;
V_44 [ 0 ] &= 0xf0 ;
}
}
}
return F_9 ( V_4 , 2 , V_40 -> V_45 , V_40 -> V_46 ) ;
}
static unsigned char * F_11 ( struct V_30 * V_31 ,
struct V_11 * V_12 )
{
int V_33 , V_34 , V_35 = 0 , V_36 = V_12 -> V_37 ;
struct V_3 * V_4 = F_2 ( V_31 -> V_31 . V_38 ) ;
struct V_39 * V_40 = V_31 -> V_41 ;
unsigned char * V_42 = V_40 -> V_43 ;
unsigned char * V_44 = V_40 -> V_45 + 8 ;
F_5 ( V_4 , 2 , V_40 -> V_45 , V_40 -> V_46 ) ;
for ( V_33 = 0 ; V_33 < V_40 -> V_47 ; V_33 ++ , V_42 += 4 ) {
for ( V_34 = 0 ; V_34 < V_42 [ 1 ] ; V_34 ++ ) {
V_44 += 4 ;
if ( V_42 [ 0 ] != V_14 &&
V_42 [ 0 ] != V_48 )
continue;
if ( V_35 ++ == V_36 )
return V_44 ;
}
}
return NULL ;
}
static void F_12 ( struct V_30 * V_31 ,
struct V_11 * V_12 )
{
unsigned char * V_32 ;
V_32 = F_11 ( V_31 , V_12 ) ;
if ( V_32 )
V_12 -> V_49 = ( V_32 [ 3 ] & 0x60 ) >> 4 ;
}
static int F_13 ( struct V_30 * V_31 ,
struct V_11 * V_12 ,
enum V_50 V_51 )
{
unsigned char V_32 [ 4 ] ;
unsigned char * V_44 ;
V_44 = F_11 ( V_31 , V_12 ) ;
if ( ! V_44 )
return - V_52 ;
F_4 ( V_32 , V_12 , V_44 ) ;
switch ( V_51 ) {
case V_53 :
V_32 [ 3 ] &= 0xdf ;
break;
case V_54 :
V_32 [ 3 ] |= 0x20 ;
break;
default:
return - V_26 ;
}
return F_10 ( V_31 , V_12 , V_32 ) ;
}
static void F_14 ( struct V_30 * V_31 ,
struct V_11 * V_12 )
{
unsigned char * V_32 ;
V_32 = F_11 ( V_31 , V_12 ) ;
if ( V_32 )
V_12 -> V_13 = ( V_32 [ 0 ] & 0x0f ) ;
}
static void F_15 ( struct V_30 * V_31 ,
struct V_11 * V_12 )
{
unsigned char * V_32 ;
V_32 = F_11 ( V_31 , V_12 ) ;
if ( V_32 )
V_12 -> V_55 = ( V_32 [ 2 ] & 0x02 ) ? 1 : 0 ;
}
static int F_16 ( struct V_30 * V_31 ,
struct V_11 * V_12 ,
enum V_50 V_51 )
{
unsigned char V_32 [ 4 ] ;
unsigned char * V_44 ;
V_44 = F_11 ( V_31 , V_12 ) ;
if ( ! V_44 )
return - V_52 ;
F_4 ( V_32 , V_12 , V_44 ) ;
switch ( V_51 ) {
case V_53 :
V_32 [ 2 ] &= 0xfd ;
break;
case V_54 :
V_32 [ 2 ] |= 0x02 ;
break;
default:
return - V_26 ;
}
return F_10 ( V_31 , V_12 , V_32 ) ;
}
static int F_17 ( struct V_30 * V_31 ,
struct V_11 * V_12 ,
enum V_50 V_51 )
{
unsigned char V_32 [ 4 ] ;
unsigned char * V_44 ;
V_44 = F_11 ( V_31 , V_12 ) ;
if ( ! V_44 )
return - V_52 ;
F_4 ( V_32 , V_12 , V_44 ) ;
switch ( V_51 ) {
case V_53 :
V_32 [ 2 ] &= 0x7f ;
V_12 -> V_56 = 0 ;
break;
case V_54 :
V_32 [ 2 ] |= 0x80 ;
V_12 -> V_56 = 1 ;
break;
default:
return - V_26 ;
}
return F_10 ( V_31 , V_12 , V_32 ) ;
}
static int F_18 ( struct V_30 * V_31 , char * V_16 )
{
struct V_39 * V_40 = V_31 -> V_41 ;
unsigned long long V_57 = F_19 ( V_40 -> V_58 + 8 + 4 ) ;
return sprintf ( V_16 , L_4 , V_57 ) ;
}
static void F_20 ( struct V_30 * V_31 ,
struct V_11 * V_12 )
{
unsigned char * V_32 ;
V_32 = F_11 ( V_31 , V_12 ) ;
if ( V_32 )
V_12 -> V_59 = ( V_32 [ 3 ] & 0x10 ) ? 0 : 1 ;
}
static int F_21 ( struct V_30 * V_31 ,
struct V_11 * V_12 ,
int V_51 )
{
unsigned char V_32 [ 4 ] ;
unsigned char * V_44 ;
V_44 = F_11 ( V_31 , V_12 ) ;
if ( ! V_44 )
return - V_52 ;
F_4 ( V_32 , V_12 , V_44 ) ;
switch ( V_51 ) {
case 0 :
V_32 [ 3 ] |= 0x10 ;
break;
case 1 :
V_32 [ 3 ] &= 0xef ;
break;
default:
return - V_26 ;
}
V_12 -> V_59 = V_51 ;
return F_10 ( V_31 , V_12 , V_32 ) ;
}
static void F_22 ( struct V_11 * V_12 ,
unsigned char * V_32 )
{
int V_60 = V_32 [ 0 ] & 0x10 ;
int V_61 = V_32 [ 0 ] & 0x80 ;
enum V_62 V_63 = V_32 [ 0 ] & 0x0f ;
T_2 V_64 = 0 ;
int V_65 = - 1 ;
struct V_66 * V_67 = V_12 -> V_41 ;
unsigned char * V_68 ;
if ( V_61 )
return;
switch ( V_63 ) {
case V_69 :
if ( V_60 ) {
V_68 = V_32 + 4 ;
V_65 = V_68 [ 3 ] ;
}
break;
case V_70 :
if ( V_60 ) {
V_68 = V_32 + 4 ;
V_65 = V_68 [ 3 ] ;
V_68 = V_32 + 8 ;
} else
V_68 = V_32 + 4 ;
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
V_12 -> V_65 = V_65 ;
V_67 -> V_64 = V_64 ;
}
static int F_23 ( struct V_30 * V_31 ,
void * V_71 )
{
struct V_72 * V_72 = V_71 ;
int V_33 ;
struct V_66 * V_67 ;
if ( ! V_31 -> V_73 [ 0 ] . V_41 )
return 0 ;
for ( V_33 = 0 ; V_33 < V_31 -> V_74 ; V_33 ++ ) {
V_67 = V_31 -> V_73 [ V_33 ] . V_41 ;
if ( V_67 -> V_64 != V_72 -> V_64 )
continue;
if ( F_24 ( V_31 , V_33 , V_72 -> V_2 ) == 0 )
F_25 ( & V_72 -> V_2 -> V_75 , V_76 ) ;
return 1 ;
}
return 0 ;
}
static void F_26 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
int V_77 )
{
T_1 V_27 ;
unsigned char * V_16 = NULL , * V_42 , * V_44 , * V_78 = NULL ;
int V_33 , V_34 , V_79 , V_80 , V_74 ;
struct V_39 * V_40 = V_31 -> V_41 ;
int V_81 = V_40 -> V_47 ;
unsigned char * V_82 = F_27 ( V_83 , V_84 ) ;
if ( ! V_82 )
goto V_85;
if ( V_40 -> V_86 )
F_5 ( V_4 , 10 , V_40 -> V_86 , V_40 -> V_87 ) ;
V_27 = F_5 ( V_4 , 7 , V_82 , V_83 ) ;
if ( V_27 )
goto V_85;
V_79 = V_80 = ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] + 4 ;
V_16 = F_27 ( V_80 + 1 , V_84 ) ;
if ( ! V_16 )
goto V_85;
V_27 = F_5 ( V_4 , 7 , V_16 , V_80 ) ;
if ( V_27 ) {
V_85:
F_28 ( V_16 ) ;
V_16 = NULL ;
V_44 = NULL ;
V_80 = 0 ;
V_79 = 0 ;
} else {
V_44 = V_16 + 8 ;
V_80 = ( V_44 [ 2 ] << 8 ) + V_44 [ 3 ] ;
V_44 += V_80 + 4 ;
}
if ( V_40 -> V_86 )
V_78 = V_40 -> V_86 + 8 ;
V_42 = V_40 -> V_43 ;
V_74 = 0 ;
for ( V_33 = 0 ; V_33 < V_81 ; V_33 ++ , V_42 += 4 ) {
for ( V_34 = 0 ; V_34 < V_42 [ 1 ] ; V_34 ++ ) {
char * V_88 = NULL ;
struct V_11 * V_12 ;
if ( V_44 ) {
if ( V_44 >= V_16 + V_79 ) {
V_44 = NULL ;
} else {
V_80 = ( V_44 [ 2 ] << 8 ) + V_44 [ 3 ] ;
V_44 += 4 ;
V_44 [ V_80 ] = '\0' ;
V_88 = V_44 ;
}
}
if ( V_42 [ 0 ] == V_14 ||
V_42 [ 0 ] == V_48 ) {
if ( V_77 )
V_12 = F_29 (
V_31 ,
V_74 ++ ,
V_42 [ 0 ] ,
V_88 ) ;
else
V_12 = & V_31 -> V_73 [ V_74 ++ ] ;
if ( ! F_30 ( V_12 ) ) {
F_20 ( V_31 , V_12 ) ;
if ( V_78 )
F_22 (
V_12 ,
V_78 ) ;
if ( V_77 )
F_31 (
V_12 ) ;
}
}
if ( V_44 )
V_44 += V_80 ;
if ( V_78 &&
( V_42 [ 0 ] == V_14 ||
V_42 [ 0 ] == V_48 ||
V_42 [ 0 ] == V_89 ||
V_42 [ 0 ] == V_90 ||
V_42 [ 0 ] == V_91 ||
V_42 [ 0 ] == V_92 ) )
V_78 += V_78 [ 1 ] + 2 ;
}
}
F_28 ( V_16 ) ;
F_28 ( V_82 ) ;
}
static void F_32 ( struct V_30 * V_31 ,
struct V_3 * V_4 )
{
struct V_72 V_72 = {
. V_64 = 0 ,
} ;
F_26 ( V_31 , F_2 ( V_31 -> V_31 . V_38 ) , 0 ) ;
if ( F_33 ( V_4 ) )
V_72 . V_64 = F_34 ( V_4 ) ;
if ( V_72 . V_64 ) {
V_72 . V_2 = & V_4 -> V_93 ;
F_35 ( F_23 , & V_72 ) ;
}
}
static int F_36 ( struct V_1 * V_94 ,
struct V_95 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_94 -> V_38 ) ;
struct V_3 * V_97 ;
unsigned char * V_16 = NULL , * V_82 , * V_42 ;
struct V_39 * V_40 ;
T_1 V_27 ;
int V_33 , V_81 , V_80 , V_74 = 0 ;
int V_5 = - V_98 ;
int V_99 ;
struct V_30 * V_31 ;
struct V_66 * V_67 = NULL ;
if ( ! F_37 ( V_4 ) ) {
struct V_30 * V_100 = NULL ;
while ( ( V_31 = F_38 ( & V_4 -> V_101 -> V_102 , V_100 ) ) != NULL ) {
F_32 ( V_31 , V_4 ) ;
V_100 = V_31 ;
}
return - V_6 ;
}
if ( V_4 -> type != V_7 )
F_3 ( V_9 , V_4 , L_5 ) ;
V_40 = F_27 ( sizeof( * V_40 ) , V_84 ) ;
V_82 = F_27 ( V_83 , V_84 ) ;
if ( ! V_82 || ! V_40 )
goto V_103;
V_27 = F_5 ( V_4 , 1 , V_82 , V_83 ) ;
if ( V_27 )
goto V_104;
V_80 = ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] + 4 ;
V_16 = F_27 ( V_80 , V_84 ) ;
if ( ! V_16 )
goto V_105;
V_27 = F_5 ( V_4 , 1 , V_16 , V_80 ) ;
if ( V_27 )
goto V_104;
V_81 = 0 ;
V_99 = V_16 [ 1 ] + 1 ;
V_42 = V_16 + 8 ;
for ( V_33 = 0 ; V_33 < V_99 && V_42 < V_16 + V_80 ; V_33 ++ ) {
V_81 += V_42 [ 2 ] ;
V_42 += V_42 [ 3 ] + 4 ;
}
V_40 -> V_43 = V_42 ;
V_40 -> V_47 = V_81 ;
for ( V_33 = 0 ; V_33 < V_81 && V_42 < V_16 + V_80 ; V_33 ++ , V_42 += 4 ) {
if ( V_42 [ 0 ] == V_14 ||
V_42 [ 0 ] == V_48 )
V_74 += V_42 [ 1 ] ;
}
V_40 -> V_58 = V_16 ;
V_40 -> V_106 = V_80 ;
V_16 = NULL ;
V_27 = F_5 ( V_4 , 2 , V_82 , V_83 ) ;
if ( V_27 )
goto V_104;
V_80 = ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] + 4 ;
V_16 = F_27 ( V_80 , V_84 ) ;
if ( ! V_16 )
goto V_105;
V_27 = F_5 ( V_4 , 2 , V_16 , V_80 ) ;
if ( V_27 )
goto V_104;
V_40 -> V_45 = V_16 ;
V_40 -> V_46 = V_80 ;
V_16 = NULL ;
V_27 = F_5 ( V_4 , 10 , V_82 , V_83 ) ;
if ( ! V_27 ) {
V_80 = ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] + 4 ;
V_16 = F_27 ( V_80 , V_84 ) ;
if ( ! V_16 )
goto V_105;
V_27 = F_5 ( V_4 , 10 , V_16 , V_80 ) ;
if ( V_27 )
goto V_104;
V_40 -> V_86 = V_16 ;
V_40 -> V_87 = V_80 ;
V_16 = NULL ;
}
V_67 = F_27 ( sizeof( struct V_66 ) * V_74 , V_84 ) ;
if ( ! V_67 )
goto V_105;
V_31 = F_39 ( V_94 -> V_38 , F_40 ( & V_4 -> V_93 ) ,
V_74 , & V_107 ) ;
if ( F_30 ( V_31 ) ) {
V_5 = F_41 ( V_31 ) ;
goto V_105;
}
F_28 ( V_82 ) ;
V_31 -> V_41 = V_40 ;
for ( V_33 = 0 ; V_33 < V_74 ; V_33 ++ )
V_31 -> V_73 [ V_33 ] . V_41 = V_67 + V_33 ;
F_26 ( V_31 , V_4 , 1 ) ;
F_42 (tmp_sdev, sdev->host) {
if ( V_97 -> V_108 != 0 || F_37 ( V_97 ) )
continue;
F_32 ( V_31 , V_97 ) ;
}
return 0 ;
V_104:
F_3 ( V_25 , V_4 , L_6 ,
V_27 ) ;
V_5 = - V_6 ;
V_105:
F_28 ( V_16 ) ;
F_28 ( V_67 ) ;
F_28 ( V_40 -> V_86 ) ;
F_28 ( V_40 -> V_45 ) ;
F_28 ( V_40 -> V_58 ) ;
V_103:
F_28 ( V_40 ) ;
F_28 ( V_82 ) ;
F_3 ( V_25 , V_4 , L_7 , V_5 ) ;
return V_5 ;
}
static int F_43 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_30 * V_31 , * V_100 = NULL ;
while ( ( V_31 = F_38 ( & V_4 -> V_101 -> V_102 , V_100 ) ) != NULL ) {
V_100 = V_31 ;
if ( ! F_45 ( V_31 , & V_4 -> V_93 ) )
break;
}
if ( V_31 )
F_46 ( & V_31 -> V_31 ) ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_30 * V_31 ;
struct V_39 * V_40 ;
V_31 = F_38 ( & V_4 -> V_93 , NULL ) ;
if ( ! V_31 )
return;
V_40 = V_31 -> V_41 ;
V_31 -> V_41 = NULL ;
F_28 ( V_40 -> V_86 ) ;
F_28 ( V_40 -> V_58 ) ;
F_28 ( V_40 -> V_45 ) ;
F_28 ( V_40 ) ;
F_28 ( V_31 -> V_73 [ 0 ] . V_41 ) ;
F_46 ( & V_31 -> V_31 ) ;
F_48 ( V_31 ) ;
}
static void F_49 ( struct V_1 * V_94 ,
struct V_95 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_94 -> V_38 ) ;
if ( ! F_37 ( V_4 ) )
F_44 ( V_4 ) ;
else
F_47 ( V_4 ) ;
}
static int T_3 F_50 ( void )
{
int V_5 ;
V_5 = F_51 ( & V_109 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_52 ( & V_110 . V_111 ) ;
if ( V_5 )
goto V_112;
return 0 ;
V_112:
F_53 ( & V_109 ) ;
return V_5 ;
}
static void T_4 F_54 ( void )
{
F_55 ( & V_110 . V_111 ) ;
F_53 ( & V_109 ) ;
}
