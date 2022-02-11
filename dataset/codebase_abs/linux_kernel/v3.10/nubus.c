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
if ( V_50 >= 10 )
F_4 ( V_51 L_14 ,
V_49 -> V_12 , V_21 . V_12 ) ;
if ( ( V_26 = F_27 ( sizeof( * V_26 ) , V_52 ) ) == NULL )
return NULL ;
V_26 -> V_28 = V_49 -> type ;
V_26 -> V_22 = V_21 . V_12 ;
V_26 -> V_19 = V_19 ;
while ( F_15 ( & V_21 , & V_27 ) != - 1 )
{
switch( V_27 . type )
{
case V_53 :
{
unsigned short V_54 [ 4 ] ;
F_10 ( V_54 , & V_27 , 8 ) ;
V_26 -> V_29 = V_54 [ 0 ] ;
V_26 -> type = V_54 [ 1 ] ;
V_26 -> V_31 = V_54 [ 2 ] ;
V_26 -> V_30 = V_54 [ 3 ] ;
F_4 ( V_38 L_15 ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] , V_54 [ 3 ] ) ;
break;
}
case V_55 :
{
F_11 ( V_26 -> V_56 , & V_27 , 64 ) ;
F_4 ( V_38 L_16 , V_26 -> V_56 ) ;
break;
}
case V_57 :
{
struct V_20 V_58 ;
struct V_10 V_59 ;
F_16 ( & V_27 , & V_58 ) ;
F_15 ( & V_58 , & V_59 ) ;
V_26 -> V_60 = F_9 ( & V_59 ) ;
F_4 ( V_38 L_17 ,
V_26 -> V_60 ) ;
break;
}
case V_61 :
F_10 ( & V_26 -> V_62 , & V_27 , 4 ) ;
F_4 ( V_38 L_18 ,
V_26 -> V_62 ) ;
break;
case V_63 :
F_10 ( & V_26 -> V_64 , & V_27 , 4 ) ;
F_4 ( V_38 L_19 ,
V_26 -> V_64 ) ;
break;
case V_65 :
V_26 -> V_66 = V_27 . V_13 ;
F_4 ( V_38 L_20 , V_26 -> V_66 ) ;
break;
case V_67 :
V_26 -> V_68 = V_27 . V_13 ;
F_4 ( V_38 L_21 , V_26 -> V_68 ) ;
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
struct V_69 {
T_1 V_70 ;
T_3 V_71 ;
char V_56 [ 32 ] ;
};
F_4 ( V_38 L_22 ) ;
F_16 ( V_49 , & V_21 ) ;
if ( V_50 >= 10 )
F_4 ( V_51 L_23 ,
V_49 -> V_12 , V_21 . V_12 ) ;
while( F_15 ( & V_21 , & V_27 ) != - 1 )
{
struct V_69 V_72 ;
T_1 V_70 ;
F_10 ( & V_70 , & V_27 , 4 ) ;
if ( V_70 > sizeof( V_72 ) - 1 )
V_70 = sizeof( V_72 ) - 1 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
F_10 ( & V_72 , & V_27 , V_70 ) ;
F_4 ( V_38 L_24 , V_27 . type ,
V_72 . V_71 , V_72 . V_56 ) ;
}
return 0 ;
}
static int T_2 F_29 ( struct V_18 * V_19 ,
const struct V_10 * V_27 )
{
unsigned char V_73 [ 128 ] ;
int V_74 , V_75 ;
F_10 ( & V_73 , V_27 , 128 ) ;
F_4 ( V_38 L_25 ) ;
for ( V_75 = 0 ; V_75 < 32 ; V_75 ++ ) {
F_4 ( V_38 L_26 ) ;
for ( V_74 = 0 ; V_74 < 32 ; V_74 ++ ) {
if ( V_73 [ V_75 * 4 + V_74 / 8 ]
& ( 0x80 >> ( V_74 % 8 ) ) )
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
static char * V_76 [ 6 ] = { L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 } ;
F_4 ( V_38 L_35 ) ;
F_16 ( V_49 , & V_21 ) ;
if ( V_50 >= 10 )
F_4 ( V_51 L_36 ,
V_49 -> V_12 , V_21 . V_12 ) ;
while( F_15 ( & V_21 , & V_27 ) != - 1 )
{
char V_56 [ 64 ] ;
F_11 ( V_56 , & V_27 , 64 ) ;
if ( V_27 . type > 5 )
V_27 . type = 5 ;
F_4 ( V_38 L_37 ,
V_76 [ V_27 . type - 1 ] , V_56 ) ;
}
return 0 ;
}
static int T_2 F_31 ( struct V_18 * V_19 , int V_9 ,
const struct V_10 * V_49 )
{
struct V_20 V_21 ;
struct V_10 V_27 ;
F_16 ( V_49 , & V_21 ) ;
if ( V_50 >= 10 )
F_4 ( V_51 L_38 ,
V_49 -> V_12 , V_21 . V_12 ) ;
while( F_15 ( & V_21 , & V_27 ) != - 1 )
{
switch ( V_27 . type ) {
case V_53 :
{
unsigned short V_54 [ 4 ] ;
F_10 ( V_54 , & V_27 , 8 ) ;
F_4 ( V_38 L_15 ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] ,
V_54 [ 3 ] ) ;
if ( V_54 [ 0 ] != 1 || V_54 [ 1 ] != 0 ||
V_54 [ 2 ] != 0 || V_54 [ 3 ] != 0 )
F_4 ( V_7 L_39 ) ;
break;
}
case V_55 :
F_11 ( V_19 -> V_56 , & V_27 , 64 ) ;
F_4 ( V_38 L_16 , V_19 -> V_56 ) ;
break;
case V_77 :
F_29 ( V_19 , & V_27 ) ;
break;
case V_78 :
F_4 ( V_38 L_40 , V_27 . V_13 ) ;
break;
case V_79 :
F_4 ( V_38 L_41 , V_27 . V_13 ) ;
break;
case V_80 :
F_30 ( V_19 , & V_27 ) ;
break;
case V_65 :
F_4 ( V_38 L_20 , V_27 . V_13 ) ;
break;
case V_67 :
F_4 ( V_38 L_21 , V_27 . V_13 ) ;
break;
case V_81 :
F_4 ( V_38 L_42 , V_27 . V_13 ) ;
break;
case V_82 :
F_28 ( V_19 , & V_27 ) ;
break;
case V_83 :
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
unsigned char * V_84 ;
unsigned char * V_85 ;
struct V_20 V_21 ;
struct V_10 V_27 ;
V_84 = V_19 -> V_86 ;
F_3 ( & V_84 , 4 , V_19 -> V_24 ) ;
if ( F_2 ( & V_84 , 4 , V_19 -> V_24 ) != V_87 ) {
V_19 -> V_22 = V_19 -> V_86 ;
F_6 ( & V_19 -> V_22 ,
F_7 ( V_19 -> V_88 ) ,
V_19 -> V_24 ) ;
return;
}
V_85 = F_8 ( V_19 -> V_9 ) ;
F_3 ( & V_85 , V_89 , V_19 -> V_24 ) ;
V_21 . V_12 = V_21 . V_4 = V_85 ;
V_21 . V_23 = 0 ;
V_21 . V_14 = V_19 -> V_24 ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 )
goto V_90;
if ( V_50 >= 10 )
F_4 ( V_38 L_44 , V_27 . type , V_27 . V_13 ) ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 )
goto V_90;
if ( V_50 >= 10 )
F_4 ( V_51 L_44 , V_27 . type , V_27 . V_13 ) ;
F_16 ( & V_27 , & V_21 ) ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 )
goto V_90;
if ( V_50 >= 10 )
F_4 ( V_51 L_44 , V_27 . type , V_27 . V_13 ) ;
if ( F_15 ( & V_21 , & V_27 ) == - 1 )
goto V_90;
if ( V_50 >= 10 )
F_4 ( V_51 L_44 , V_27 . type , V_27 . V_13 ) ;
F_16 ( & V_27 , & V_21 ) ;
V_19 -> V_22 = V_21 . V_12 ;
return;
V_90:
V_19 -> V_22 = V_19 -> V_86 ;
F_6 ( & V_19 -> V_22 , F_7 ( V_19 -> V_88 ) , V_19 -> V_24 ) ;
F_4 ( V_7 L_45 ) ;
}
static struct V_18 * T_2 F_33 ( int V_9 , int V_91 )
{
struct V_18 * V_19 ;
struct V_18 * * V_92 ;
unsigned char * V_84 ;
unsigned long V_93 ;
struct V_20 V_21 ;
struct V_10 V_27 ;
V_84 = F_8 ( V_9 ) ;
F_3 ( & V_84 , V_94 , V_91 ) ;
if ( ( V_19 = F_27 ( sizeof( * V_19 ) , V_52 ) ) == NULL )
return NULL ;
V_19 -> V_86 = V_84 ;
if ( V_50 >= 10 ) {
int V_41 ;
F_4 ( V_51 L_46 ,
V_9 , V_84 ) ;
F_4 ( V_51 L_47 ) ;
for ( V_41 = 0 ; V_41 < V_94 ; V_41 += 4 ) {
unsigned short V_8 , V_95 ;
V_8 = F_2 ( & V_84 , 2 , V_91 ) ;
V_95 = F_2 ( & V_84 , 2 , V_91 ) ;
F_4 ( L_48 , V_8 , V_95 ) ;
}
F_4 ( L_10 ) ;
V_84 = V_19 -> V_86 ;
}
V_19 -> V_9 = V_9 ;
V_19 -> V_96 = ( unsigned long ) F_34 ( V_9 ) ;
V_19 -> V_88 = F_2 ( & V_84 , 4 , V_91 ) ;
V_19 -> V_97 = F_2 ( & V_84 , 4 , V_91 ) ;
V_19 -> V_98 = F_2 ( & V_84 , 4 , V_91 ) ;
V_19 -> V_99 = F_2 ( & V_84 , 1 , V_91 ) ;
V_19 -> V_100 = F_2 ( & V_84 , 1 , V_91 ) ;
V_19 -> V_24 = V_91 ;
if( ! ( V_19 -> V_88 & 0x00FF0000 ) )
F_4 ( V_101 L_49 ) ;
V_93 = F_2 ( & V_84 , 4 , V_91 ) ;
if( V_93 != V_87 )
F_4 ( V_101 L_50 , V_93 ) ;
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
struct V_25 * * V_102 ;
V_26 = F_26 ( V_19 , V_9 , & V_27 ) ;
if ( V_26 == NULL )
continue;
if ( V_19 -> V_103 == NULL )
V_19 -> V_103 = V_26 ;
for ( V_102 = & V_35 ; * V_102 != NULL ; V_102 = & ( ( * V_102 ) -> V_34 ) )
;
* V_102 = V_26 ;
V_26 -> V_34 = NULL ;
}
for ( V_92 = & V_104 ; * V_92 != NULL ; V_92 = & ( ( * V_92 ) -> V_34 ) )
;
* V_92 = V_19 ;
V_19 -> V_34 = NULL ;
return V_19 ;
}
void T_2 F_35 ( int V_9 )
{
unsigned char V_105 ;
unsigned char * V_84 ;
int V_41 ;
V_84 = F_8 ( V_9 ) ;
for( V_41 = 4 ; V_41 ; V_41 -- )
{
unsigned long V_66 ;
int V_106 ;
V_84 -- ;
F_36 ( V_66 ) ;
V_106 = F_37 ( V_84 ) ;
F_38 ( V_66 ) ;
if ( ! V_106 )
continue;
F_4 ( V_51 L_54 , V_9 , V_84 ) ;
V_105 = * V_84 ;
if( V_105 == 0 )
continue;
if ( ( ( ( V_105 >> 4 ) ^ V_105 ) & 0x0F ) != 0x0F )
continue;
if ( ( V_105 & 0x0F ) >= ( 1 << V_41 ) )
continue;
F_33 ( V_9 , V_105 ) ;
return;
}
}
void T_2 F_39 ( void )
{
int V_9 ;
#ifdef F_40
F_35 ( 0 ) ;
#endif
for( V_9 = 9 ; V_9 < 15 ; V_9 ++ )
{
F_35 ( V_9 ) ;
}
}
static int T_2 F_41 ( void )
{
if ( ! V_107 )
return 0 ;
if ( V_108 ) {
F_42 () ;
} else {
F_43 () ;
}
#ifdef F_44
F_45 ( 1000 ) ;
#endif
F_4 ( L_55 ) ;
V_35 = NULL ;
V_104 = NULL ;
F_39 () ;
F_46 () ;
return 0 ;
}
