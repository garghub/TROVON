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
unsigned char V_18 [] = {
V_19 ,
1 ,
V_15 ,
V_17 >> 8 ,
V_17 & 0xff ,
0
} ;
return F_6 ( V_4 , V_18 , V_20 , V_16 , V_17 ,
NULL , V_21 , V_22 , NULL ) ;
}
static int F_7 ( struct V_3 * V_4 , int V_15 ,
void * V_16 , int V_17 )
{
T_1 V_23 ;
unsigned char V_18 [] = {
V_24 ,
0x10 ,
0 ,
V_17 >> 8 ,
V_17 & 0xff ,
0
} ;
V_23 = F_6 ( V_4 , V_18 , V_25 , V_16 , V_17 ,
NULL , V_21 , V_22 , NULL ) ;
if ( V_23 )
F_3 ( V_26 , V_4 , L_2 ,
V_23 ) ;
return V_23 ;
}
static int F_8 ( struct V_27 * V_28 ,
struct V_11 * V_12 ,
unsigned char * V_29 )
{
int V_30 , V_31 , V_32 = 0 , V_33 = V_12 -> V_34 ;
struct V_3 * V_4 = F_2 ( V_28 -> V_28 . V_35 ) ;
struct V_36 * V_37 = V_28 -> V_38 ;
unsigned char * V_39 = V_37 -> V_40 ;
unsigned char * V_41 = V_37 -> V_42 + 8 ;
memset ( V_41 , 0 , V_37 -> V_43 - 8 ) ;
for ( V_30 = 0 ; V_30 < V_37 -> V_44 ; V_30 ++ , V_39 += 4 ) {
for ( V_31 = 0 ; V_31 < V_39 [ 1 ] ; V_31 ++ ) {
V_41 += 4 ;
if ( V_39 [ 0 ] != V_14 &&
V_39 [ 0 ] != V_45 )
continue;
if ( V_32 ++ == V_33 ) {
memcpy ( V_41 , V_29 , 4 ) ;
V_41 [ 0 ] |= 0x80 ;
V_41 [ 0 ] &= 0xf0 ;
}
}
}
return F_7 ( V_4 , 2 , V_37 -> V_42 , V_37 -> V_43 ) ;
}
static unsigned char * F_9 ( struct V_27 * V_28 ,
struct V_11 * V_12 )
{
int V_30 , V_31 , V_32 = 0 , V_33 = V_12 -> V_34 ;
struct V_3 * V_4 = F_2 ( V_28 -> V_28 . V_35 ) ;
struct V_36 * V_37 = V_28 -> V_38 ;
unsigned char * V_39 = V_37 -> V_40 ;
unsigned char * V_41 = V_37 -> V_42 + 8 ;
F_5 ( V_4 , 2 , V_37 -> V_42 , V_37 -> V_43 ) ;
for ( V_30 = 0 ; V_30 < V_37 -> V_44 ; V_30 ++ , V_39 += 4 ) {
for ( V_31 = 0 ; V_31 < V_39 [ 1 ] ; V_31 ++ ) {
V_41 += 4 ;
if ( V_39 [ 0 ] != V_14 &&
V_39 [ 0 ] != V_45 )
continue;
if ( V_32 ++ == V_33 )
return V_41 ;
}
}
return NULL ;
}
static void F_10 ( struct V_27 * V_28 ,
struct V_11 * V_12 )
{
unsigned char * V_29 ;
V_29 = F_9 ( V_28 , V_12 ) ;
if ( V_29 )
V_12 -> V_46 = ( V_29 [ 3 ] & 0x60 ) >> 4 ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_11 * V_12 ,
enum V_47 V_48 )
{
unsigned char V_29 [ 4 ] ;
unsigned char * V_41 ;
V_41 = F_9 ( V_28 , V_12 ) ;
if ( ! V_41 )
return - V_49 ;
F_4 ( V_29 , V_12 , V_41 ) ;
switch ( V_48 ) {
case V_50 :
V_29 [ 3 ] &= 0xdf ;
break;
case V_51 :
V_29 [ 3 ] |= 0x20 ;
break;
default:
return - V_52 ;
}
return F_8 ( V_28 , V_12 , V_29 ) ;
}
static void F_12 ( struct V_27 * V_28 ,
struct V_11 * V_12 )
{
unsigned char * V_29 ;
V_29 = F_9 ( V_28 , V_12 ) ;
if ( V_29 )
V_12 -> V_13 = ( V_29 [ 0 ] & 0x0f ) ;
}
static void F_13 ( struct V_27 * V_28 ,
struct V_11 * V_12 )
{
unsigned char * V_29 ;
V_29 = F_9 ( V_28 , V_12 ) ;
if ( V_29 )
V_12 -> V_53 = ( V_29 [ 2 ] & 0x02 ) ? 1 : 0 ;
}
static int F_14 ( struct V_27 * V_28 ,
struct V_11 * V_12 ,
enum V_47 V_48 )
{
unsigned char V_29 [ 4 ] ;
unsigned char * V_41 ;
V_41 = F_9 ( V_28 , V_12 ) ;
if ( ! V_41 )
return - V_49 ;
F_4 ( V_29 , V_12 , V_41 ) ;
switch ( V_48 ) {
case V_50 :
V_29 [ 2 ] &= 0xfd ;
break;
case V_51 :
V_29 [ 2 ] |= 0x02 ;
break;
default:
return - V_52 ;
}
return F_8 ( V_28 , V_12 , V_29 ) ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_11 * V_12 ,
enum V_47 V_48 )
{
unsigned char V_29 [ 4 ] ;
unsigned char * V_41 ;
V_41 = F_9 ( V_28 , V_12 ) ;
if ( ! V_41 )
return - V_49 ;
F_4 ( V_29 , V_12 , V_41 ) ;
switch ( V_48 ) {
case V_50 :
V_29 [ 2 ] &= 0x7f ;
V_12 -> V_54 = 0 ;
break;
case V_51 :
V_29 [ 2 ] |= 0x80 ;
V_12 -> V_54 = 1 ;
break;
default:
return - V_52 ;
}
return F_8 ( V_28 , V_12 , V_29 ) ;
}
static int F_16 ( struct V_27 * V_28 , char * V_16 )
{
struct V_36 * V_37 = V_28 -> V_38 ;
unsigned long long V_55 = F_17 ( V_37 -> V_56 + 8 + 4 ) ;
return sprintf ( V_16 , L_3 , V_55 ) ;
}
static void F_18 ( struct V_27 * V_28 ,
struct V_11 * V_12 )
{
unsigned char * V_29 ;
V_29 = F_9 ( V_28 , V_12 ) ;
if ( V_29 )
V_12 -> V_57 = ( V_29 [ 3 ] & 0x10 ) ? 0 : 1 ;
}
static int F_19 ( struct V_27 * V_28 ,
struct V_11 * V_12 ,
int V_48 )
{
unsigned char V_29 [ 4 ] ;
unsigned char * V_41 ;
V_41 = F_9 ( V_28 , V_12 ) ;
if ( ! V_41 )
return - V_49 ;
F_4 ( V_29 , V_12 , V_41 ) ;
switch ( V_48 ) {
case 0 :
V_29 [ 3 ] |= 0x10 ;
break;
case 1 :
V_29 [ 3 ] &= 0xef ;
break;
default:
return - V_52 ;
}
V_12 -> V_57 = V_48 ;
return F_8 ( V_28 , V_12 , V_29 ) ;
}
static void F_20 ( struct V_11 * V_12 ,
unsigned char * V_29 )
{
int V_58 = V_29 [ 0 ] & 0x10 ;
int V_59 = V_29 [ 0 ] & 0x80 ;
enum V_60 V_61 = V_29 [ 0 ] & 0x0f ;
T_2 V_62 = 0 ;
int V_63 = - 1 ;
struct V_64 * V_65 = V_12 -> V_38 ;
unsigned char * V_66 ;
if ( V_59 )
return;
switch ( V_61 ) {
case V_67 :
if ( V_58 ) {
V_66 = V_29 + 4 ;
V_63 = V_66 [ 3 ] ;
}
break;
case V_68 :
if ( V_58 ) {
V_66 = V_29 + 4 ;
V_63 = V_66 [ 3 ] ;
V_66 = V_29 + 8 ;
} else
V_66 = V_29 + 4 ;
V_62 = ( T_2 ) V_66 [ 12 ] << 56 |
( T_2 ) V_66 [ 13 ] << 48 |
( T_2 ) V_66 [ 14 ] << 40 |
( T_2 ) V_66 [ 15 ] << 32 |
( T_2 ) V_66 [ 16 ] << 24 |
( T_2 ) V_66 [ 17 ] << 16 |
( T_2 ) V_66 [ 18 ] << 8 |
( T_2 ) V_66 [ 19 ] ;
break;
default:
break;
}
V_12 -> V_63 = V_63 ;
V_65 -> V_62 = V_62 ;
}
static int F_21 ( struct V_27 * V_28 ,
void * V_69 )
{
struct V_70 * V_70 = V_69 ;
int V_30 ;
struct V_64 * V_65 ;
if ( ! V_28 -> V_71 [ 0 ] . V_38 )
return 0 ;
for ( V_30 = 0 ; V_30 < V_28 -> V_72 ; V_30 ++ ) {
V_65 = V_28 -> V_71 [ V_30 ] . V_38 ;
if ( V_65 -> V_62 != V_70 -> V_62 )
continue;
if ( F_22 ( V_28 , V_30 , V_70 -> V_2 ) == 0 )
F_23 ( & V_70 -> V_2 -> V_73 , V_74 ) ;
return 1 ;
}
return 0 ;
}
static void F_24 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
int V_75 )
{
T_1 V_23 ;
unsigned char * V_16 = NULL , * V_39 , * V_41 , * V_76 = NULL ;
int V_30 , V_31 , V_77 , V_78 , V_72 ;
struct V_36 * V_37 = V_28 -> V_38 ;
int V_79 = V_37 -> V_44 ;
unsigned char * V_80 = F_25 ( V_81 , V_82 ) ;
if ( ! V_80 )
goto V_83;
if ( V_37 -> V_84 )
F_5 ( V_4 , 10 , V_37 -> V_84 , V_37 -> V_85 ) ;
V_23 = F_5 ( V_4 , 7 , V_80 , V_81 ) ;
if ( V_23 )
goto V_83;
V_77 = V_78 = ( V_80 [ 2 ] << 8 ) + V_80 [ 3 ] + 4 ;
V_16 = F_25 ( V_78 + 1 , V_82 ) ;
if ( ! V_16 )
goto V_83;
V_23 = F_5 ( V_4 , 7 , V_16 , V_78 ) ;
if ( V_23 ) {
V_83:
F_26 ( V_16 ) ;
V_16 = NULL ;
V_41 = NULL ;
V_78 = 0 ;
V_77 = 0 ;
} else {
V_41 = V_16 + 8 ;
V_78 = ( V_41 [ 2 ] << 8 ) + V_41 [ 3 ] ;
V_41 += V_78 + 4 ;
}
if ( V_37 -> V_84 )
V_76 = V_37 -> V_84 + 8 ;
V_39 = V_37 -> V_40 ;
V_72 = 0 ;
for ( V_30 = 0 ; V_30 < V_79 ; V_30 ++ , V_39 += 4 ) {
for ( V_31 = 0 ; V_31 < V_39 [ 1 ] ; V_31 ++ ) {
char * V_86 = NULL ;
struct V_11 * V_12 ;
if ( V_41 ) {
if ( V_41 >= V_16 + V_77 ) {
V_41 = NULL ;
} else {
V_78 = ( V_41 [ 2 ] << 8 ) + V_41 [ 3 ] ;
V_41 += 4 ;
V_41 [ V_78 ] = '\0' ;
V_86 = V_41 ;
}
}
if ( V_39 [ 0 ] == V_14 ||
V_39 [ 0 ] == V_45 ) {
if ( V_75 )
V_12 = F_27 (
V_28 ,
V_72 ++ ,
V_39 [ 0 ] ,
V_86 ) ;
else
V_12 = & V_28 -> V_71 [ V_72 ++ ] ;
if ( ! F_28 ( V_12 ) ) {
F_18 ( V_28 , V_12 ) ;
if ( V_76 )
F_20 (
V_12 ,
V_76 ) ;
if ( V_75 )
F_29 (
V_12 ) ;
}
}
if ( V_41 )
V_41 += V_78 ;
if ( V_76 )
V_76 += V_76 [ 1 ] + 2 ;
}
}
F_26 ( V_16 ) ;
F_26 ( V_80 ) ;
}
static void F_30 ( struct V_27 * V_28 ,
struct V_3 * V_4 )
{
unsigned char * V_29 ;
struct V_70 V_70 = {
. V_62 = 0 ,
} ;
F_24 ( V_28 , F_2 ( V_28 -> V_28 . V_35 ) , 0 ) ;
if ( ! V_4 -> V_87 )
return;
V_29 = V_4 -> V_88 + 4 ;
while ( V_29 < V_4 -> V_88 + V_4 -> V_87 ) {
enum V_60 V_61 = V_29 [ 0 ] >> 4 ;
T_3 V_89 = V_29 [ 0 ] & 0x0f ;
T_3 V_90 = V_29 [ 1 ] & 0x80 ;
T_3 V_91 = ( V_29 [ 1 ] & 0x30 ) >> 4 ;
T_3 type = V_29 [ 1 ] & 0x0f ;
T_3 V_78 = V_29 [ 3 ] ;
if ( V_90 && V_89 == 1 && V_91 == 1
&& V_61 == V_68 && type == 3 && V_78 == 8 )
V_70 . V_62 = F_17 ( & V_29 [ 4 ] ) ;
V_29 += V_78 + 4 ;
}
if ( V_70 . V_62 ) {
V_70 . V_2 = & V_4 -> V_92 ;
F_31 ( F_21 , & V_70 ) ;
}
}
static int F_32 ( struct V_1 * V_93 ,
struct V_94 * V_95 )
{
struct V_3 * V_4 = F_2 ( V_93 -> V_35 ) ;
struct V_3 * V_96 ;
unsigned char * V_16 = NULL , * V_80 , * V_39 ;
struct V_36 * V_37 ;
T_1 V_23 ;
int V_30 , V_79 , V_78 , V_72 = 0 ;
int V_5 = - V_97 ;
int V_98 ;
struct V_27 * V_28 ;
struct V_64 * V_65 = NULL ;
if ( ! F_33 ( V_4 ) ) {
struct V_27 * V_99 = NULL ;
while ( ( V_28 = F_34 ( & V_4 -> V_100 -> V_101 , V_99 ) ) != NULL ) {
F_30 ( V_28 , V_4 ) ;
V_99 = V_28 ;
}
return - V_6 ;
}
if ( V_4 -> type != V_7 )
F_3 ( V_9 , V_4 , L_4 ) ;
V_37 = F_25 ( sizeof( * V_37 ) , V_82 ) ;
V_80 = F_25 ( V_81 , V_82 ) ;
if ( ! V_80 || ! V_37 )
goto V_102;
V_23 = F_5 ( V_4 , 1 , V_80 , V_81 ) ;
if ( V_23 )
goto V_103;
V_78 = ( V_80 [ 2 ] << 8 ) + V_80 [ 3 ] + 4 ;
V_16 = F_25 ( V_78 , V_82 ) ;
if ( ! V_16 )
goto V_104;
V_23 = F_5 ( V_4 , 1 , V_16 , V_78 ) ;
if ( V_23 )
goto V_103;
V_79 = 0 ;
V_98 = V_16 [ 1 ] + 1 ;
V_39 = V_16 + 8 ;
for ( V_30 = 0 ; V_30 < V_98 && V_39 < V_16 + V_78 ; V_30 ++ ) {
V_79 += V_39 [ 2 ] ;
V_39 += V_39 [ 3 ] + 4 ;
}
V_37 -> V_40 = V_39 ;
V_37 -> V_44 = V_79 ;
for ( V_30 = 0 ; V_30 < V_79 && V_39 < V_16 + V_78 ; V_30 ++ , V_39 += 4 ) {
if ( V_39 [ 0 ] == V_14 ||
V_39 [ 0 ] == V_45 )
V_72 += V_39 [ 1 ] ;
}
V_37 -> V_56 = V_16 ;
V_37 -> V_105 = V_78 ;
V_16 = NULL ;
V_23 = F_5 ( V_4 , 2 , V_80 , V_81 ) ;
if ( V_23 )
goto V_103;
V_78 = ( V_80 [ 2 ] << 8 ) + V_80 [ 3 ] + 4 ;
V_16 = F_25 ( V_78 , V_82 ) ;
if ( ! V_16 )
goto V_104;
V_23 = F_5 ( V_4 , 2 , V_16 , V_78 ) ;
if ( V_23 )
goto V_103;
V_37 -> V_42 = V_16 ;
V_37 -> V_43 = V_78 ;
V_16 = NULL ;
V_23 = F_5 ( V_4 , 10 , V_80 , V_81 ) ;
if ( ! V_23 ) {
V_78 = ( V_80 [ 2 ] << 8 ) + V_80 [ 3 ] + 4 ;
V_16 = F_25 ( V_78 , V_82 ) ;
if ( ! V_16 )
goto V_104;
V_23 = F_5 ( V_4 , 10 , V_16 , V_78 ) ;
if ( V_23 )
goto V_103;
V_37 -> V_84 = V_16 ;
V_37 -> V_85 = V_78 ;
V_16 = NULL ;
}
V_65 = F_25 ( sizeof( struct V_64 ) * V_72 , V_82 ) ;
if ( ! V_65 )
goto V_104;
V_28 = F_35 ( V_93 -> V_35 , F_36 ( & V_4 -> V_92 ) ,
V_72 , & V_106 ) ;
if ( F_28 ( V_28 ) ) {
V_5 = F_37 ( V_28 ) ;
goto V_104;
}
F_26 ( V_80 ) ;
V_28 -> V_38 = V_37 ;
for ( V_30 = 0 ; V_30 < V_72 ; V_30 ++ )
V_28 -> V_71 [ V_30 ] . V_38 = V_65 + V_30 ;
F_24 ( V_28 , V_4 , 1 ) ;
F_38 (tmp_sdev, sdev->host) {
if ( V_96 -> V_107 != 0 || F_33 ( V_96 ) )
continue;
F_30 ( V_28 , V_96 ) ;
}
return 0 ;
V_103:
F_3 ( V_26 , V_4 , L_5 ,
V_23 ) ;
V_5 = - V_6 ;
V_104:
F_26 ( V_16 ) ;
F_26 ( V_65 ) ;
F_26 ( V_37 -> V_84 ) ;
F_26 ( V_37 -> V_42 ) ;
F_26 ( V_37 -> V_56 ) ;
V_102:
F_26 ( V_37 ) ;
F_26 ( V_80 ) ;
F_3 ( V_26 , V_4 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_39 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_27 * V_28 , * V_99 = NULL ;
while ( ( V_28 = F_34 ( & V_4 -> V_100 -> V_101 , V_99 ) ) != NULL ) {
V_99 = V_28 ;
if ( ! F_41 ( V_28 , & V_4 -> V_92 ) )
break;
}
if ( V_28 )
F_42 ( & V_28 -> V_28 ) ;
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_27 * V_28 ;
struct V_36 * V_37 ;
V_28 = F_34 ( & V_4 -> V_92 , NULL ) ;
if ( ! V_28 )
return;
V_37 = V_28 -> V_38 ;
V_28 -> V_38 = NULL ;
F_26 ( V_37 -> V_84 ) ;
F_26 ( V_37 -> V_56 ) ;
F_26 ( V_37 -> V_42 ) ;
F_26 ( V_37 ) ;
F_26 ( V_28 -> V_71 [ 0 ] . V_38 ) ;
F_42 ( & V_28 -> V_28 ) ;
F_44 ( V_28 ) ;
}
static void F_45 ( struct V_1 * V_93 ,
struct V_94 * V_95 )
{
struct V_3 * V_4 = F_2 ( V_93 -> V_35 ) ;
if ( ! F_33 ( V_4 ) )
F_40 ( V_4 ) ;
else
F_43 ( V_4 ) ;
}
static int T_4 F_46 ( void )
{
int V_5 ;
V_5 = F_47 ( & V_108 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_48 ( & V_109 . V_110 ) ;
if ( V_5 )
goto V_111;
return 0 ;
V_111:
F_49 ( & V_108 ) ;
return V_5 ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_109 . V_110 ) ;
F_49 ( & V_108 ) ;
}
