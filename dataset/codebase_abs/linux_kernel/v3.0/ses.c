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
static int F_4 ( struct V_3 * V_4 , int V_10 ,
void * V_11 , int V_12 )
{
unsigned char V_13 [] = {
V_14 ,
1 ,
V_10 ,
V_12 >> 8 ,
V_12 & 0xff ,
0
} ;
return F_5 ( V_4 , V_13 , V_15 , V_11 , V_12 ,
NULL , V_16 , V_17 , NULL ) ;
}
static int F_6 ( struct V_3 * V_4 , int V_10 ,
void * V_11 , int V_12 )
{
T_1 V_18 ;
unsigned char V_13 [] = {
V_19 ,
0x10 ,
0 ,
V_12 >> 8 ,
V_12 & 0xff ,
0
} ;
V_18 = F_5 ( V_4 , V_13 , V_20 , V_11 , V_12 ,
NULL , V_16 , V_17 , NULL ) ;
if ( V_18 )
F_3 ( V_21 , V_4 , L_2 ,
V_18 ) ;
return V_18 ;
}
static int F_7 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
unsigned char * V_26 )
{
int V_27 , V_28 , V_29 = 0 , V_30 = V_25 -> V_31 ;
struct V_3 * V_4 = F_2 ( V_23 -> V_23 . V_32 ) ;
struct V_33 * V_34 = V_23 -> V_35 ;
unsigned char * V_36 = V_34 -> V_37 ;
unsigned char * V_38 = V_34 -> V_39 + 8 ;
memset ( V_38 , 0 , V_34 -> V_40 - 8 ) ;
for ( V_27 = 0 ; V_27 < V_34 -> V_41 ; V_27 ++ , V_36 += 4 ) {
for ( V_28 = 0 ; V_28 < V_36 [ 1 ] ; V_28 ++ ) {
V_38 += 4 ;
if ( V_36 [ 0 ] != V_42 &&
V_36 [ 0 ] != V_43 )
continue;
if ( V_29 ++ == V_30 ) {
memcpy ( V_38 , V_26 , 4 ) ;
V_38 [ 0 ] |= 0x80 ;
V_38 [ 0 ] &= 0xf0 ;
}
}
}
return F_6 ( V_4 , 2 , V_34 -> V_39 , V_34 -> V_40 ) ;
}
static unsigned char * F_8 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
int V_27 , V_28 , V_29 = 0 , V_30 = V_25 -> V_31 ;
struct V_3 * V_4 = F_2 ( V_23 -> V_23 . V_32 ) ;
struct V_33 * V_34 = V_23 -> V_35 ;
unsigned char * V_36 = V_34 -> V_37 ;
unsigned char * V_38 = V_34 -> V_39 + 8 ;
F_4 ( V_4 , 2 , V_34 -> V_39 , V_34 -> V_40 ) ;
for ( V_27 = 0 ; V_27 < V_34 -> V_41 ; V_27 ++ , V_36 += 4 ) {
for ( V_28 = 0 ; V_28 < V_36 [ 1 ] ; V_28 ++ ) {
V_38 += 4 ;
if ( V_36 [ 0 ] != V_42 &&
V_36 [ 0 ] != V_43 )
continue;
if ( V_29 ++ == V_30 )
return V_38 ;
}
}
return NULL ;
}
static void F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
unsigned char * V_26 ;
V_26 = F_8 ( V_23 , V_25 ) ;
if ( V_26 )
V_25 -> V_44 = ( V_26 [ 3 ] & 0x60 ) >> 4 ;
}
static int F_10 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
enum V_45 V_46 )
{
unsigned char V_26 [ 4 ] = { 0 } ;
switch ( V_46 ) {
case V_47 :
break;
case V_48 :
V_26 [ 2 ] = 0x02 ;
break;
default:
return - V_49 ;
}
return F_7 ( V_23 , V_25 , V_26 ) ;
}
static void F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
unsigned char * V_26 ;
V_26 = F_8 ( V_23 , V_25 ) ;
if ( V_26 )
V_25 -> V_50 = ( V_26 [ 0 ] & 0x0f ) ;
}
static void F_12 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
unsigned char * V_26 ;
V_26 = F_8 ( V_23 , V_25 ) ;
if ( V_26 )
V_25 -> V_51 = ( V_26 [ 2 ] & 0x02 ) ? 1 : 0 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
enum V_45 V_46 )
{
unsigned char V_26 [ 4 ] = { 0 } ;
switch ( V_46 ) {
case V_47 :
break;
case V_48 :
V_26 [ 2 ] = 0x02 ;
break;
default:
return - V_49 ;
}
return F_7 ( V_23 , V_25 , V_26 ) ;
}
static int F_14 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
enum V_45 V_46 )
{
unsigned char V_26 [ 4 ] = { 0 } ;
switch ( V_46 ) {
case V_47 :
V_25 -> V_52 = 0 ;
break;
case V_48 :
V_26 [ 2 ] = 0x80 ;
V_25 -> V_52 = 1 ;
break;
default:
return - V_49 ;
}
return F_7 ( V_23 , V_25 , V_26 ) ;
}
static void F_15 ( struct V_24 * V_25 ,
unsigned char * V_26 )
{
int V_53 = V_26 [ 0 ] & 0x10 ;
int V_54 = V_26 [ 0 ] & 0x80 ;
enum V_55 V_56 = V_26 [ 0 ] & 0x0f ;
T_2 V_57 = 0 ;
struct V_58 * V_59 = V_25 -> V_35 ;
unsigned char * V_60 ;
V_59 -> V_26 = V_26 ;
if ( V_54 )
return;
switch ( V_56 ) {
case V_61 :
if ( V_53 )
V_60 = V_26 + 8 ;
else
V_60 = V_26 + 4 ;
V_57 = ( T_2 ) V_60 [ 12 ] << 56 |
( T_2 ) V_60 [ 13 ] << 48 |
( T_2 ) V_60 [ 14 ] << 40 |
( T_2 ) V_60 [ 15 ] << 32 |
( T_2 ) V_60 [ 16 ] << 24 |
( T_2 ) V_60 [ 17 ] << 16 |
( T_2 ) V_60 [ 18 ] << 8 |
( T_2 ) V_60 [ 19 ] ;
break;
default:
break;
}
V_59 -> V_57 = V_57 ;
}
static int F_16 ( struct V_22 * V_23 ,
void * V_62 )
{
struct V_63 * V_63 = V_62 ;
int V_27 ;
struct V_58 * V_59 ;
if ( ! V_23 -> V_64 [ 0 ] . V_35 )
return 0 ;
for ( V_27 = 0 ; V_27 < V_23 -> V_65 ; V_27 ++ ) {
V_59 = V_23 -> V_64 [ V_27 ] . V_35 ;
if ( V_59 -> V_57 != V_63 -> V_57 )
continue;
F_17 ( V_23 , V_27 , V_63 -> V_2 ) ;
return 1 ;
}
return 0 ;
}
static void F_18 ( struct V_22 * V_23 ,
struct V_3 * V_4 ,
int V_66 )
{
T_1 V_18 ;
unsigned char * V_11 = NULL , * V_36 , * V_38 , * V_67 = NULL ;
int V_27 , V_28 , V_68 , V_69 , V_65 ;
struct V_33 * V_34 = V_23 -> V_35 ;
int V_70 = V_34 -> V_41 ;
unsigned char * V_71 = F_19 ( V_72 , V_73 ) ;
if ( ! V_71 )
goto V_74;
if ( V_34 -> V_75 )
F_4 ( V_4 , 10 , V_34 -> V_75 , V_34 -> V_76 ) ;
V_18 = F_4 ( V_4 , 7 , V_71 , V_72 ) ;
if ( V_18 )
goto V_74;
V_68 = V_69 = ( V_71 [ 2 ] << 8 ) + V_71 [ 3 ] + 4 ;
V_11 = F_19 ( V_69 + 1 , V_73 ) ;
if ( ! V_11 )
goto V_74;
V_18 = F_4 ( V_4 , 7 , V_11 , V_69 ) ;
if ( V_18 ) {
V_74:
F_20 ( V_11 ) ;
V_11 = NULL ;
V_38 = NULL ;
V_69 = 0 ;
V_68 = 0 ;
} else {
V_38 = V_11 + 8 ;
V_69 = ( V_38 [ 2 ] << 8 ) + V_38 [ 3 ] ;
V_38 += V_69 + 4 ;
}
if ( V_34 -> V_75 )
V_67 = V_34 -> V_75 + 8 ;
V_36 = V_34 -> V_37 ;
V_65 = 0 ;
for ( V_27 = 0 ; V_27 < V_70 ; V_27 ++ , V_36 += 4 ) {
for ( V_28 = 0 ; V_28 < V_36 [ 1 ] ; V_28 ++ ) {
char * V_77 = NULL ;
struct V_24 * V_25 ;
if ( V_38 ) {
if ( V_38 >= V_11 + V_68 ) {
V_38 = NULL ;
} else {
V_69 = ( V_38 [ 2 ] << 8 ) + V_38 [ 3 ] ;
V_38 += 4 ;
V_38 [ V_69 ] = '\0' ;
V_77 = V_38 ;
}
}
if ( V_36 [ 0 ] == V_42 ||
V_36 [ 0 ] == V_43 ) {
if ( V_66 )
V_25 = F_21 ( V_23 ,
V_65 ++ ,
V_36 [ 0 ] ,
V_77 ) ;
else
V_25 = & V_23 -> V_64 [ V_65 ++ ] ;
if ( ! F_22 ( V_25 ) && V_67 )
F_15 ( V_25 ,
V_67 ) ;
}
if ( V_38 )
V_38 += V_69 ;
if ( V_67 )
V_67 += V_67 [ 1 ] + 2 ;
}
}
F_20 ( V_11 ) ;
F_20 ( V_71 ) ;
}
static void F_23 ( struct V_22 * V_23 ,
struct V_3 * V_4 )
{
unsigned char * V_11 ;
unsigned char * V_26 ;
unsigned int V_78 ;
struct V_63 V_63 = {
. V_57 = 0 ,
} ;
V_11 = F_24 ( V_72 , V_73 ) ;
if ( ! V_11 || F_25 ( V_4 , 0x83 , V_11 , V_72 ) )
goto free;
F_18 ( V_23 , F_2 ( V_23 -> V_23 . V_32 ) , 0 ) ;
V_78 = ( ( V_11 [ 2 ] << 8 ) | V_11 [ 3 ] ) + 4 ;
F_20 ( V_11 ) ;
V_11 = F_24 ( V_78 , V_73 ) ;
if ( ! V_11 || F_25 ( V_4 , 0x83 , V_11 , V_78 ) )
goto free;
V_26 = V_11 + 4 ;
while ( V_26 < V_11 + V_78 ) {
enum V_55 V_56 = V_26 [ 0 ] >> 4 ;
T_3 V_79 = V_26 [ 0 ] & 0x0f ;
T_3 V_80 = V_26 [ 1 ] & 0x80 ;
T_3 V_81 = ( V_26 [ 1 ] & 0x30 ) >> 4 ;
T_3 type = V_26 [ 1 ] & 0x0f ;
T_3 V_69 = V_26 [ 3 ] ;
if ( V_80 && V_79 == 1 && V_81 == 1
&& V_56 == V_61 && type == 3 && V_69 == 8 )
V_63 . V_57 = ( T_2 ) V_26 [ 4 ] << 56 |
( T_2 ) V_26 [ 5 ] << 48 |
( T_2 ) V_26 [ 6 ] << 40 |
( T_2 ) V_26 [ 7 ] << 32 |
( T_2 ) V_26 [ 8 ] << 24 |
( T_2 ) V_26 [ 9 ] << 16 |
( T_2 ) V_26 [ 10 ] << 8 |
( T_2 ) V_26 [ 11 ] ;
V_26 += V_69 + 4 ;
}
if ( ! V_63 . V_57 )
goto free;
V_63 . V_2 = & V_4 -> V_82 ;
F_26 ( F_16 , & V_63 ) ;
free:
F_20 ( V_11 ) ;
}
static int F_27 ( struct V_1 * V_83 ,
struct V_84 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_32 ) ;
struct V_3 * V_86 ;
unsigned char * V_11 = NULL , * V_71 , * V_36 ;
struct V_33 * V_34 ;
T_1 V_18 ;
int V_27 , V_70 , V_69 , V_65 = 0 ;
int V_5 = - V_87 ;
int V_88 ;
struct V_22 * V_23 ;
struct V_58 * V_59 = NULL ;
if ( ! F_28 ( V_4 ) ) {
struct V_22 * V_89 = NULL ;
while ( ( V_23 = F_29 ( & V_4 -> V_90 -> V_91 , V_89 ) ) != NULL ) {
F_23 ( V_23 , V_4 ) ;
V_89 = V_23 ;
}
return - V_6 ;
}
if ( V_4 -> type != V_7 )
F_3 ( V_9 , V_4 , L_3 ) ;
V_34 = F_19 ( sizeof( * V_34 ) , V_73 ) ;
V_71 = F_19 ( V_72 , V_73 ) ;
if ( ! V_71 || ! V_34 )
goto V_92;
V_18 = F_4 ( V_4 , 1 , V_71 , V_72 ) ;
if ( V_18 )
goto V_93;
V_69 = ( V_71 [ 2 ] << 8 ) + V_71 [ 3 ] + 4 ;
V_11 = F_19 ( V_69 , V_73 ) ;
if ( ! V_11 )
goto V_94;
V_18 = F_4 ( V_4 , 1 , V_11 , V_69 ) ;
if ( V_18 )
goto V_93;
V_70 = 0 ;
V_88 = V_11 [ 1 ] + 1 ;
V_36 = V_11 + 8 ;
for ( V_27 = 0 ; V_27 < V_88 && V_36 < V_11 + V_69 ; V_27 ++ ) {
V_70 += V_36 [ 2 ] ;
V_36 += V_36 [ 3 ] + 4 ;
}
V_34 -> V_37 = V_36 ;
V_34 -> V_41 = V_70 ;
for ( V_27 = 0 ; V_27 < V_70 && V_36 < V_11 + V_69 ; V_27 ++ , V_36 += 4 ) {
if ( V_36 [ 0 ] == V_42 ||
V_36 [ 0 ] == V_43 )
V_65 += V_36 [ 1 ] ;
}
V_34 -> V_95 = V_11 ;
V_34 -> V_96 = V_69 ;
V_11 = NULL ;
V_18 = F_4 ( V_4 , 2 , V_71 , V_72 ) ;
if ( V_18 )
goto V_93;
V_69 = ( V_71 [ 2 ] << 8 ) + V_71 [ 3 ] + 4 ;
V_11 = F_19 ( V_69 , V_73 ) ;
if ( ! V_11 )
goto V_94;
V_18 = F_4 ( V_4 , 2 , V_11 , V_69 ) ;
if ( V_18 )
goto V_93;
V_34 -> V_39 = V_11 ;
V_34 -> V_40 = V_69 ;
V_11 = NULL ;
V_18 = F_4 ( V_4 , 10 , V_71 , V_72 ) ;
if ( ! V_18 ) {
V_69 = ( V_71 [ 2 ] << 8 ) + V_71 [ 3 ] + 4 ;
V_11 = F_19 ( V_69 , V_73 ) ;
if ( ! V_11 )
goto V_94;
V_18 = F_4 ( V_4 , 10 , V_11 , V_69 ) ;
if ( V_18 )
goto V_93;
V_34 -> V_75 = V_11 ;
V_34 -> V_76 = V_69 ;
V_11 = NULL ;
}
V_59 = F_19 ( sizeof( struct V_58 ) * V_65 , V_73 ) ;
if ( ! V_59 )
goto V_94;
V_23 = F_30 ( V_83 -> V_32 , F_31 ( & V_4 -> V_82 ) ,
V_65 , & V_97 ) ;
if ( F_22 ( V_23 ) ) {
V_5 = F_32 ( V_23 ) ;
goto V_94;
}
F_20 ( V_71 ) ;
V_23 -> V_35 = V_34 ;
for ( V_27 = 0 ; V_27 < V_65 ; V_27 ++ )
V_23 -> V_64 [ V_27 ] . V_35 = V_59 + V_27 ;
F_18 ( V_23 , V_4 , 1 ) ;
F_33 (tmp_sdev, sdev->host) {
if ( V_86 -> V_98 != 0 || F_28 ( V_86 ) )
continue;
F_23 ( V_23 , V_86 ) ;
}
return 0 ;
V_93:
F_3 ( V_21 , V_4 , L_4 ,
V_18 ) ;
V_5 = - V_6 ;
V_94:
F_20 ( V_11 ) ;
F_20 ( V_59 ) ;
F_20 ( V_34 -> V_75 ) ;
F_20 ( V_34 -> V_39 ) ;
F_20 ( V_34 -> V_95 ) ;
V_92:
F_20 ( V_34 ) ;
F_20 ( V_71 ) ;
F_3 ( V_21 , V_4 , L_5 , V_5 ) ;
return V_5 ;
}
static int F_34 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_35 ( struct V_3 * V_4 )
{
struct V_22 * V_23 , * V_89 = NULL ;
while ( ( V_23 = F_29 ( & V_4 -> V_90 -> V_91 , V_89 ) ) != NULL ) {
V_89 = V_23 ;
if ( ! F_36 ( V_23 , & V_4 -> V_82 ) )
break;
}
if ( V_23 )
F_37 ( & V_23 -> V_23 ) ;
}
static void F_38 ( struct V_3 * V_4 )
{
struct V_22 * V_23 ;
struct V_33 * V_34 ;
V_23 = F_29 ( & V_4 -> V_82 , NULL ) ;
if ( ! V_23 )
return;
V_34 = V_23 -> V_35 ;
V_23 -> V_35 = NULL ;
F_20 ( V_34 -> V_75 ) ;
F_20 ( V_34 -> V_95 ) ;
F_20 ( V_34 -> V_39 ) ;
F_20 ( V_34 ) ;
F_20 ( V_23 -> V_64 [ 0 ] . V_35 ) ;
F_37 ( & V_23 -> V_23 ) ;
F_39 ( V_23 ) ;
}
static void F_40 ( struct V_1 * V_83 ,
struct V_84 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_32 ) ;
if ( ! F_28 ( V_4 ) )
F_35 ( V_4 ) ;
else
F_38 ( V_4 ) ;
}
static int T_4 F_41 ( void )
{
int V_5 ;
V_5 = F_42 ( & V_99 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_43 ( & V_100 . V_101 ) ;
if ( V_5 )
goto V_102;
return 0 ;
V_102:
F_44 ( & V_99 ) ;
return V_5 ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_100 . V_101 ) ;
F_44 ( & V_99 ) ;
}
