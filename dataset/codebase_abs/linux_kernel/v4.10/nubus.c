static inline int F_1 ( void * V_1 , int V_2 )
{
unsigned long V_3 = ( unsigned long ) V_1 ;
V_3 &= 3 ;
if( V_2 & ( 1 << V_3 ) )
return 0 ;
return 1 ;
}
static unsigned long F_2 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
unsigned long V_6 = 0 ;
unsigned char * V_1 = * V_4 ;
while( V_5 )
{
V_6 <<= 8 ;
while( F_1 ( V_1 , V_2 ) )
V_1 ++ ;
V_6 |= * V_1 ++ ;
V_5 -- ;
}
* V_4 = V_1 ;
return V_6 ;
}
static void F_3 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
unsigned char * V_1 = * V_4 ;
if( V_5 > 65536 )
F_4 ( V_7 L_1 , V_5 ) ;
while( V_5 )
{
do
{
V_1 -- ;
}
while( F_1 ( V_1 , V_2 ) );
V_5 -- ;
}
* V_4 = V_1 ;
}
static void F_5 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
unsigned char * V_1 = * V_4 ;
if( V_5 > 65536 )
F_4 ( V_7 L_2 , V_5 ) ;
while( V_5 )
{
while( F_1 ( V_1 , V_2 ) )
V_1 ++ ;
V_1 ++ ;
V_5 -- ;
}
* V_4 = V_1 ;
}
static void F_6 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
if( V_5 > 0 )
F_5 ( V_4 , V_5 , V_2 ) ;
else if( V_5 < 0 )
F_3 ( V_4 , - V_5 , V_2 ) ;
}
static inline long F_7 ( long V_8 )
{
if( V_8 & 0x00800000 )
V_8 |= 0xFF000000 ;
return V_8 ;
}
static inline void * F_8 ( int V_9 )
{
return ( void * ) ( 0xF1000000 + ( V_9 << 24 ) ) ;
}
static unsigned char * F_9 ( const struct V_10 * V_11 )
{
unsigned char * V_1 = V_11 -> V_12 ;
F_6 ( & V_1 , F_7 ( V_11 -> V_13 ) , V_11 -> V_14 ) ;
return V_1 ;
}
void F_10 ( void * V_15 , const struct V_10 * V_16 ,
int V_5 )
{
unsigned char * V_17 = ( unsigned char * ) V_15 ;
unsigned char * V_1 = F_9 ( V_16 ) ;
while( V_5 )
{
* V_17 ++ = F_2 ( & V_1 , 1 , V_16 -> V_14 ) ;
V_5 -- ;
}
}
void F_11 ( void * V_15 , const struct V_10 * V_16 ,
int V_5 )
{
unsigned char * V_17 = ( unsigned char * ) V_15 ;
unsigned char * V_1 = F_9 ( V_16 ) ;
while( V_5 )
{
* V_17 = F_2 ( & V_1 , 1 , V_16 -> V_14 ) ;
if( ! * V_17 ++ )
break;
V_5 -- ;
}
}
int F_12 ( const struct V_18 * V_19 ,
struct V_20 * V_21 )
{
V_21 -> V_4 = V_21 -> V_12 = V_19 -> V_22 ;
V_21 -> V_23 = 0 ;
V_21 -> V_14 = V_19 -> V_24 ;
return 0 ;
}
int F_13 ( const struct V_25 * V_26 ,
struct V_20 * V_21 )
{
V_21 -> V_4 = V_21 -> V_12 = V_26 -> V_22 ;
V_21 -> V_23 = 0 ;
V_21 -> V_14 = V_26 -> V_19 -> V_24 ;
return 0 ;
}
int F_14 ( const struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_10 V_27 ;
V_21 -> V_4 = V_21 -> V_12 = V_19 -> V_22 ;
V_21 -> V_23 = 0 ;
V_21 -> V_14 = V_19 -> V_24 ;
if ( F_15 ( V_21 , & V_27 ) == - 1 )
return - 1 ;
if ( F_16 ( & V_27 , V_21 ) == - 1 )
return - 1 ;
return 0 ;
}
int F_16 ( const struct V_10 * V_27 ,
struct V_20 * V_21 )
{
V_21 -> V_4 = V_21 -> V_12 = F_9 ( V_27 ) ;
V_21 -> V_23 = 0 ;
V_21 -> V_14 = V_27 -> V_14 ;
return 0 ;
}
int F_15 ( struct V_20 * V_11 , struct V_10 * V_27 )
{
T_1 V_28 ;
if ( V_11 -> V_23 )
return - 1 ;
V_27 -> V_12 = V_11 -> V_4 ;
V_28 = F_2 ( & V_11 -> V_4 , 4 , V_11 -> V_14 ) ;
if( ( V_28 & 0xff000000 ) == 0xff000000 )
{
V_11 -> V_23 = 1 ;
return - 1 ;
}
V_27 -> type = V_28 >> 24 ;
V_27 -> V_13 = V_28 & 0xffffff ;
V_27 -> V_14 = V_11 -> V_14 ;
return 0 ;
}
int F_17 ( struct V_20 * V_21 )
{
V_21 -> V_4 = V_21 -> V_12 ;
return 0 ;
}
struct V_25 *
F_18 ( unsigned short V_29 ,
unsigned short type ,
unsigned short V_30 ,
unsigned short V_31 ,
const struct V_25 * V_32 )
{
struct V_25 * V_33 =
V_32 ? V_32 -> V_34 : V_35 ;
while ( V_33 ) {
if ( V_33 -> V_29 == V_29
&& V_33 -> type == type
&& V_33 -> V_30 == V_30
&& V_33 -> V_31 == V_31 )
return V_33 ;
V_33 = V_33 -> V_34 ;
}
return NULL ;
}
struct V_25 *
F_19 ( unsigned short V_29 ,
unsigned short type ,
const struct V_25 * V_32 )
{
struct V_25 * V_33 =
V_32 ? V_32 -> V_34 : V_35 ;
while ( V_33 ) {
if ( V_33 -> V_29 == V_29
&& V_33 -> type == type )
return V_33 ;
V_33 = V_33 -> V_34 ;
}
return NULL ;
}
struct V_25 *
F_20 ( unsigned int V_9 ,
const struct V_25 * V_32 )
{
struct V_25 * V_33 =
V_32 ? V_32 -> V_34 : V_35 ;
while ( V_33 ) {
if ( V_33 -> V_19 -> V_9 == V_9 )
return V_33 ;
V_33 = V_33 -> V_34 ;
}
return NULL ;
}
int
F_21 ( struct V_20 * V_21 , unsigned char V_36 ,
struct V_10 * V_27 )
{
while ( F_15 ( V_21 , V_27 ) != - 1 ) {
if ( V_27 -> type == V_36 )
return 0 ;
}
return - 1 ;
}
static int T_2 F_22 ( struct V_25 * V_26 ,
const struct V_10 * V_27 )
{
switch ( V_27 -> type ) {
case V_37 :
F_4 ( V_38 L_3 , V_27 -> V_13 ) ;
break;
case 0x0080 ... 0x0085 :
F_4 ( V_38 L_4 ,
V_27 -> type , V_27 -> V_13 ) ;
break;
default:
F_4 ( V_38 L_5 ,
V_27 -> type , V_27 -> V_13 ) ;
}
return 0 ;
}
static int T_2 F_23 ( struct V_25 * V_26 ,
const struct V_10 * V_27 )
{
switch ( V_27 -> type ) {
case V_39 :
{
char V_40 [ 6 ] ;
int V_41 ;
F_10 ( V_40 , V_27 , 6 ) ;
F_4 ( V_38 L_6 ) ;
for ( V_41 = 0 ; V_41 < 6 ; V_41 ++ )
F_4 ( L_7 , V_40 [ V_41 ] & 0xff ,
V_41 == 5 ? L_8 : L_9 ) ;
F_4 ( L_10 ) ;
break;
}
default:
F_4 ( V_38 L_5 ,
V_27 -> type , V_27 -> V_13 ) ;
}
return 0 ;
}
static int T_2 F_24 ( struct V_25 * V_26 ,
const struct V_10 * V_27 )
{
switch ( V_27 -> type ) {
case V_42 :
{
unsigned long V_43 [ 2 ] ;
F_10 ( & V_43 , V_27 , 8 ) ;
F_4 ( V_38 L_11 ,
V_43 [ 0 ] , V_43 [ 1 ] ) ;
break;
}
case V_44 :
{
unsigned long V_45 [ 2 ] ;
F_10 ( & V_45 , V_27 , 8 ) ;
F_4 ( V_38 L_12 ,
V_45 [ 0 ] , V_45 [ 1 ] ) ;
break;
}
default:
F_4 ( V_38 L_5 ,
V_27 -> type , V_27 -> V_13 ) ;
}
return 0 ;
}
static int T_2 F_25 ( struct V_25 * V_26 ,
const struct V_10 * V_27 )
{
switch ( V_26 -> V_29 ) {
case V_46 :
F_22 ( V_26 , V_27 ) ;
break;
case V_47 :
F_23 ( V_26 , V_27 ) ;
break;
case V_48 :
F_24 ( V_26 , V_27 ) ;
break;
default:
F_4 ( V_38 L_5 ,
V_27 -> type , V_27 -> V_13 ) ;
}
return 0 ;
}
static struct V_25 * T_2
F_26 ( struct V_18 * V_19 ,
int V_9 ,
const struct V_10 * V_49 )
{
struct V_20 V_21 ;
struct V_10 V_27 ;
struct V_25 * V_26 ;
F_4 ( V_38 L_13 , V_49 -> type ) ;
F_16 ( V_49 , & V_21 ) ;
if ( V_9 == 0 && ( unsigned long ) V_21 . V_12 % 2 )
V_21 . V_12 += 1 ;
if ( V_50 >= V_51 )
F_4 ( V_52 L_14 ,
V_49 -> V_12 , V_21 . V_12 ) ;
if ( ( V_26 = F_27 ( sizeof( * V_26 ) , V_53 ) ) == NULL )
return NULL ;
V_26 -> V_28 = V_49 -> type ;
V_26 -> V_22 = V_21 . V_12 ;
V_26 -> V_19 = V_19 ;
while ( F_15 ( & V_21 , & V_27 ) != - 1 )
{
switch( V_27 . type )
{
case V_54 :
{
unsigned short V_55 [ 4 ] ;
F_10 ( V_55 , & V_27 , 8 ) ;
V_26 -> V_29 = V_55 [ 0 ] ;
V_26 -> type = V_55 [ 1 ] ;
V_26 -> V_31 = V_55 [ 2 ] ;
V_26 -> V_30 = V_55 [ 3 ] ;
F_4 ( V_38 L_15 ,
V_55 [ 0 ] , V_55 [ 1 ] , V_55 [ 2 ] , V_55 [ 3 ] ) ;
break;
}
case V_56 :
{
F_11 ( V_26 -> V_57 , & V_27 , 64 ) ;
F_4 ( V_38 L_16 , V_26 -> V_57 ) ;
break;
}
case V_58 :
{
struct V_20 V_59 ;
struct V_10 V_60 ;
F_16 ( & V_27 , & V_59 ) ;
F_15 ( & V_59 , & V_60 ) ;
V_26 -> V_61 = F_9 ( & V_60 ) ;
F_4 ( V_38 L_17 ,
V_26 -> V_61 ) ;
break;
}
case V_62 :
F_10 ( & V_26 -> V_63 , & V_27 , 4 ) ;
F_4 ( V_38 L_18 ,
V_26 -> V_63 ) ;
break;
case V_64 :
F_10 ( & V_26 -> V_65 , & V_27 , 4 ) ;
F_4 ( V_38 L_19 ,
V_26 -> V_65 ) ;
break;
case V_66 :
V_26 -> V_67 = V_27 . V_13 ;
F_4 ( V_38 L_20 , V_26 -> V_67 ) ;
break;
case V_68 :
V_26 -> V_69 = V_27 . V_13 ;
F_4 ( V_38 L_21 , V_26 -> V_69 ) ;
break;
default:
F_25 ( V_26 , & V_27 ) ;
}
}
return V_26 ;
}
static int T_2 F_28 ( struct V_18 * V_19 ,
const struct V_10 * V_49 )
{
struct V_20 V_21 ;
struct V_10 V_27 ;
struct V_70 {
T_1 V_71 ;
T_3 V_72 ;
char V_57 [ 32 ] ;
};
F_4 ( V_38 L_22 ) ;
F_16 ( V_49 , & V_21 ) ;
if ( V_50 >= V_51 )
F_4 ( V_52 L_23 ,
V_49 -> V_12 , V_21 . V_12 ) ;
while( F_15 ( & V_21 , & V_27 ) != - 1 )
{
struct V_70 V_73 ;
T_1 V_71 ;
F_10 ( & V_71 , & V_27 , 4 ) ;
if ( V_71 > sizeof( V_73 ) - 1 )
V_71 = sizeof( V_73 ) - 1 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_10 ( & V_73 , & V_27 , V_71 ) ;
F_4 ( V_38 L_24 , V_27 . type ,
V_73 . V_72 , V_73 . V_57 ) ;
}
return 0 ;
}
static int T_2 F_29 ( struct V_18 * V_19 ,
const struct V_10 * V_27 )
{
unsigned char V_74 [ 128 ] ;
int V_75 , V_76 ;
F_10 ( & V_74 , V_27 , 128 ) ;
F_4 ( V_38 L_25 ) ;
for ( V_76 = 0 ; V_76 < 32 ; V_76 ++ ) {
F_4 ( V_38 L_26 ) ;
for ( V_75 = 0 ; V_75 < 32 ; V_75 ++ ) {
if ( V_74 [ V_76 * 4 + V_75 / 8 ]
& ( 0x80 >> ( V_75 % 8 ) ) )
F_4 ( L_27 ) ;
else
F_4 ( L_28 ) ;
}
F_4 ( L_10 ) ;
}
return 0 ;
}
static int T_2 F_30 ( struct V_18 * V_19 ,
const struct V_10 * V_49 )
{
struct V_20 V_21 ;
struct V_10 V_27 ;
static char * V_77 [ 6 ] = { L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 } ;
F_4 ( V_38 L_35 ) ;
F_16 ( V_49 , & V_21 ) ;
if ( V_50 >= V_51 )
F_4 ( V_52 L_36 ,
V_49 -> V_12 , V_21 . V_12 ) ;
while( F_15 ( & V_21 , & V_27 ) != - 1 )
{
char V_57 [ 64 ] ;
F_11 ( V_57 , & V_27 , 64 ) ;
if ( V_27 . type > 5 )
V_27 . type = 5 ;
F_4 ( V_38 L_37 ,
V_77 [ V_27 . type - 1 ] , V_57 ) ;
}
return 0 ;
}
static int T_2 F_31 ( struct V_18 * V_19 , int V_9 ,
const struct V_10 * V_49 )
{
struct V_20 V_21 ;
struct V_10 V_27 ;
F_16 ( V_49 , & V_21 ) ;
if ( V_50 >= V_51 )
F_4 ( V_52 L_38 ,
V_49 -> V_12 , V_21 . V_12 ) ;
while( F_15 ( & V_21 , & V_27 ) != - 1 )
{
switch ( V_27 . type ) {
case V_54 :
{
unsigned short V_55 [ 4 ] ;
F_10 ( V_55 , & V_27 , 8 ) ;
F_4 ( V_38 L_15 ,
V_55 [ 0 ] , V_55 [ 1 ] , V_55 [ 2 ] ,
V_55 [ 3 ] ) ;
if ( V_55 [ 0 ] != 1 || V_55 [ 1 ] != 0 ||
V_55 [ 2 ] != 0 || V_55 [ 3 ] != 0 )
F_4 ( V_7 L_39 ) ;
break;
}
case V_56 :
F_11 ( V_19 -> V_57 , & V_27 , 64 ) ;
F_4 ( V_38 L_16 , V_19 -> V_57 ) ;
break;
case V_78 :
F_29 ( V_19 , & V_27 ) ;
break;
case V_79 :
F_4 ( V_38 L_40 , V_27 . V_13 ) ;
break;
case V_80 :
F_4 ( V_38 L_41 , V_27 . V_13 ) ;
break;
case V_81 :
F_30 ( V_19 , & V_27 ) ;
break;
case V_66 :
F_4 ( V_38 L_20 , V_27 . V_13 ) ;
break;
case V_68 :
F_4 ( V_38 L_21 , V_27 . V_13 ) ;
break;
case V_82 :
F_4 ( V_38 L_42 , V_27 . V_13 ) ;
break;
case V_83 :
F_28 ( V_19 , & V_27 ) ;
break;
case V_84 :
F_4 ( V_38 L_43 ,
V_27 . V_13 ) ;
break;
default:
F_4 ( V_38 L_5 ,
V_27 . type , V_27 . V_13 ) ;
}
}
return 0 ;
}
static void T_2 F_32 ( struct V_18 * V_19 )
{
unsigned char * V_85 ;
unsigned char * V_86 ;
struct V_20 V_21 ;
struct V_10 V_27 ;
V_85 = V_19 -> V_87 ;
F_3 ( & V_85 , 4 , V_19 -> V_24 ) ;
if ( F_2 ( & V_85 , 4 , V_19 -> V_24 ) != V_88 ) {
V_19 -> V_22 = V_19 -> V_87 ;
F_6 ( & V_19 -> V_22 ,
F_7 ( V_19 -> V_89 ) ,
V_19 -> V_24 ) ;
return;
}
V_86 = F_8 ( V_19 -> V_9 ) ;
F_3 ( & V_86 , V_90 , V_19 -> V_24 ) ;
V_21 . V_12 = V_21 . V_4 = V_86 ;
V_21 . V_23 = 0 ;
V_21 . V_14 = V_19 -> V_24 ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 )
goto V_91;
if ( V_50 >= V_51 )
F_4 ( V_38 L_44 , V_27 . type , V_27 . V_13 ) ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 )
goto V_91;
if ( V_50 >= V_51 )
F_4 ( V_52 L_44 , V_27 . type , V_27 . V_13 ) ;
F_16 ( & V_27 , & V_21 ) ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 )
goto V_91;
if ( V_50 >= V_51 )
F_4 ( V_52 L_44 , V_27 . type , V_27 . V_13 ) ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 )
goto V_91;
if ( V_50 >= V_51 )
F_4 ( V_52 L_44 , V_27 . type , V_27 . V_13 ) ;
F_16 ( & V_27 , & V_21 ) ;
V_19 -> V_22 = V_21 . V_12 ;
return;
V_91:
V_19 -> V_22 = V_19 -> V_87 ;
F_6 ( & V_19 -> V_22 , F_7 ( V_19 -> V_89 ) , V_19 -> V_24 ) ;
F_4 ( V_7 L_45 ) ;
}
static struct V_18 * T_2 F_33 ( int V_9 , int V_92 )
{
struct V_18 * V_19 ;
struct V_18 * * V_93 ;
unsigned char * V_85 ;
unsigned long V_94 ;
struct V_20 V_21 ;
struct V_10 V_27 ;
V_85 = F_8 ( V_9 ) ;
F_3 ( & V_85 , V_95 , V_92 ) ;
if ( ( V_19 = F_27 ( sizeof( * V_19 ) , V_53 ) ) == NULL )
return NULL ;
V_19 -> V_87 = V_85 ;
if ( V_50 >= V_51 ) {
int V_41 ;
F_4 ( V_52 L_46 ,
V_9 , V_85 ) ;
F_4 ( V_52 L_47 ) ;
for ( V_41 = 0 ; V_41 < V_95 ; V_41 += 4 ) {
unsigned short V_8 , V_96 ;
V_8 = F_2 ( & V_85 , 2 , V_92 ) ;
V_96 = F_2 ( & V_85 , 2 , V_92 ) ;
F_4 ( L_48 , V_8 , V_96 ) ;
}
F_4 ( L_10 ) ;
V_85 = V_19 -> V_87 ;
}
V_19 -> V_9 = V_9 ;
V_19 -> V_97 = ( unsigned long ) F_34 ( V_9 ) ;
V_19 -> V_89 = F_2 ( & V_85 , 4 , V_92 ) ;
V_19 -> V_98 = F_2 ( & V_85 , 4 , V_92 ) ;
V_19 -> V_99 = F_2 ( & V_85 , 4 , V_92 ) ;
V_19 -> V_100 = F_2 ( & V_85 , 1 , V_92 ) ;
V_19 -> V_101 = F_2 ( & V_85 , 1 , V_92 ) ;
V_19 -> V_24 = V_92 ;
if( ! ( V_19 -> V_89 & 0x00FF0000 ) )
F_4 ( V_102 L_49 ) ;
V_94 = F_2 ( & V_85 , 4 , V_92 ) ;
if( V_94 != V_88 )
F_4 ( V_102 L_50 , V_94 ) ;
F_32 ( V_19 ) ;
F_12 ( V_19 , & V_21 ) ;
F_4 ( V_38 L_51 , V_9 ) ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 ) {
F_4 ( V_7 L_52 ) ;
return NULL ;
} else {
F_4 ( V_38 L_53 ) ;
F_31 ( V_19 , V_9 , & V_27 ) ;
}
while ( F_15 ( & V_21 , & V_27 ) != - 1 ) {
struct V_25 * V_26 ;
struct V_25 * * V_103 ;
V_26 = F_26 ( V_19 , V_9 , & V_27 ) ;
if ( V_26 == NULL )
continue;
if ( V_19 -> V_104 == NULL )
V_19 -> V_104 = V_26 ;
for ( V_103 = & V_35 ; * V_103 != NULL ; V_103 = & ( ( * V_103 ) -> V_34 ) )
;
* V_103 = V_26 ;
V_26 -> V_34 = NULL ;
}
for ( V_93 = & V_105 ; * V_93 != NULL ; V_93 = & ( ( * V_93 ) -> V_34 ) )
;
* V_93 = V_19 ;
V_19 -> V_34 = NULL ;
return V_19 ;
}
void T_2 F_35 ( int V_9 )
{
unsigned char V_106 ;
unsigned char * V_85 ;
int V_41 ;
V_85 = F_8 ( V_9 ) ;
for( V_41 = 4 ; V_41 ; V_41 -- )
{
int V_107 ;
V_85 -- ;
V_107 = F_36 ( V_85 ) ;
if ( ! V_107 )
continue;
F_4 ( V_52 L_54 , V_9 , V_85 ) ;
V_106 = * V_85 ;
if( V_106 == 0 )
continue;
if ( ( ( ( V_106 >> 4 ) ^ V_106 ) & 0x0F ) != 0x0F )
continue;
if ( ( V_106 & 0x0F ) >= ( 1 << V_41 ) )
continue;
F_33 ( V_9 , V_106 ) ;
return;
}
}
void T_2 F_37 ( void )
{
int V_9 ;
#ifdef F_38
F_35 ( 0 ) ;
#endif
for( V_9 = 9 ; V_9 < 15 ; V_9 ++ )
{
F_35 ( V_9 ) ;
}
}
static int T_2 F_39 ( void )
{
if ( ! V_108 )
return 0 ;
if ( V_109 ) {
F_40 () ;
} else {
F_41 () ;
}
#ifdef F_42
F_43 ( 1000 ) ;
#endif
F_4 ( L_55 ) ;
V_35 = NULL ;
V_105 = NULL ;
F_37 () ;
F_44 () ;
return 0 ;
}
