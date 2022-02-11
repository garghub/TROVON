static inline int F_1 ( void * V_1 , int V_2 )
{
unsigned long V_3 = ( unsigned long ) V_1 ;
V_3 &= 3 ;
if ( V_2 & ( 1 << V_3 ) )
return 0 ;
return 1 ;
}
static unsigned long F_2 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
unsigned long V_6 = 0 ;
unsigned char * V_1 = * V_4 ;
while ( V_5 ) {
V_6 <<= 8 ;
while ( F_1 ( V_1 , V_2 ) )
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
while ( V_5 ) {
do {
V_1 -- ;
} while ( F_1 ( V_1 , V_2 ) );
V_5 -- ;
}
* V_4 = V_1 ;
}
static void F_4 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
unsigned char * V_1 = * V_4 ;
while ( V_5 ) {
while ( F_1 ( V_1 , V_2 ) )
V_1 ++ ;
V_1 ++ ;
V_5 -- ;
}
* V_4 = V_1 ;
}
static void F_5 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
unsigned long V_7 = ( unsigned long ) * V_4 & 0xFF000000 ;
if ( V_5 > 0 )
F_4 ( V_4 , V_5 , V_2 ) ;
else if ( V_5 < 0 )
F_3 ( V_4 , - V_5 , V_2 ) ;
if ( ( ( unsigned long ) * V_4 & 0xFF000000 ) != V_7 )
F_6 ( L_1 , V_8 ) ;
}
static inline long F_7 ( long V_9 )
{
if ( V_9 & 0x00800000 )
V_9 |= 0xFF000000 ;
return V_9 ;
}
static inline void * F_8 ( int V_10 )
{
return ( void * ) ( 0xF1000000 + ( V_10 << 24 ) ) ;
}
static unsigned char * F_9 ( const struct V_11 * V_12 )
{
unsigned char * V_1 = V_12 -> V_13 ;
F_5 ( & V_1 , F_7 ( V_12 -> V_14 ) , V_12 -> V_15 ) ;
return V_1 ;
}
void F_10 ( void * V_16 , const struct V_11 * V_17 ,
int V_5 )
{
unsigned char * V_18 = ( unsigned char * ) V_16 ;
unsigned char * V_1 = F_9 ( V_17 ) ;
while ( V_5 ) {
* V_18 ++ = F_2 ( & V_1 , 1 , V_17 -> V_15 ) ;
V_5 -- ;
}
}
void F_11 ( void * V_16 , const struct V_11 * V_17 ,
int V_5 )
{
unsigned char * V_18 = ( unsigned char * ) V_16 ;
unsigned char * V_1 = F_9 ( V_17 ) ;
while ( V_5 ) {
* V_18 = F_2 ( & V_1 , 1 , V_17 -> V_15 ) ;
if ( ! * V_18 ++ )
break;
V_5 -- ;
}
}
int F_12 ( const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
V_22 -> V_4 = V_22 -> V_13 = V_20 -> V_23 ;
V_22 -> V_24 = 0 ;
V_22 -> V_15 = V_20 -> V_25 ;
return 0 ;
}
int F_13 ( const struct V_26 * V_27 ,
struct V_21 * V_22 )
{
V_22 -> V_4 = V_22 -> V_13 = V_27 -> V_23 ;
V_22 -> V_24 = 0 ;
V_22 -> V_15 = V_27 -> V_20 -> V_25 ;
return 0 ;
}
int F_14 ( const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_11 V_28 ;
V_22 -> V_4 = V_22 -> V_13 = V_20 -> V_23 ;
V_22 -> V_24 = 0 ;
V_22 -> V_15 = V_20 -> V_25 ;
if ( F_15 ( V_22 , & V_28 ) == - 1 )
return - 1 ;
if ( F_16 ( & V_28 , V_22 ) == - 1 )
return - 1 ;
return 0 ;
}
int F_16 ( const struct V_11 * V_28 ,
struct V_21 * V_22 )
{
V_22 -> V_4 = V_22 -> V_13 = F_9 ( V_28 ) ;
V_22 -> V_24 = 0 ;
V_22 -> V_15 = V_28 -> V_15 ;
return 0 ;
}
int F_15 ( struct V_21 * V_12 , struct V_11 * V_28 )
{
T_1 V_29 ;
if ( V_12 -> V_24 )
return - 1 ;
V_28 -> V_13 = V_12 -> V_4 ;
V_29 = F_2 ( & V_12 -> V_4 , 4 , V_12 -> V_15 ) ;
if ( ( V_29 & 0xff000000 ) == 0xff000000 ) {
V_12 -> V_24 = 1 ;
return - 1 ;
}
V_28 -> type = V_29 >> 24 ;
V_28 -> V_14 = V_29 & 0xffffff ;
V_28 -> V_15 = V_12 -> V_15 ;
return 0 ;
}
int F_17 ( struct V_21 * V_22 )
{
V_22 -> V_4 = V_22 -> V_13 ;
V_22 -> V_24 = 0 ;
return 0 ;
}
struct V_26 *
F_18 ( unsigned short V_30 , unsigned short type ,
unsigned short V_31 , unsigned short V_32 ,
const struct V_26 * V_33 )
{
struct V_26 * V_34 = V_33 ? V_33 -> V_35 : V_36 ;
while ( V_34 ) {
if ( V_34 -> V_30 == V_30 && V_34 -> type == type &&
V_34 -> V_31 == V_31 && V_34 -> V_32 == V_32 )
return V_34 ;
V_34 = V_34 -> V_35 ;
}
return NULL ;
}
struct V_26 *
F_19 ( unsigned short V_30 , unsigned short type ,
const struct V_26 * V_33 )
{
struct V_26 * V_34 = V_33 ? V_33 -> V_35 : V_36 ;
while ( V_34 ) {
if ( V_34 -> V_30 == V_30 && V_34 -> type == type )
return V_34 ;
V_34 = V_34 -> V_35 ;
}
return NULL ;
}
struct V_26 *
F_20 ( unsigned int V_10 , const struct V_26 * V_33 )
{
struct V_26 * V_34 = V_33 ? V_33 -> V_35 : V_36 ;
while ( V_34 ) {
if ( V_34 -> V_20 -> V_10 == V_10 )
return V_34 ;
V_34 = V_34 -> V_35 ;
}
return NULL ;
}
int
F_21 ( struct V_21 * V_22 , unsigned char V_37 ,
struct V_11 * V_28 )
{
while ( F_15 ( V_22 , V_28 ) != - 1 ) {
if ( V_28 -> type == V_37 )
return 0 ;
}
return - 1 ;
}
static int T_2 F_22 ( struct V_26 * V_27 ,
const struct V_11 * V_28 )
{
switch ( V_28 -> type ) {
case V_38 :
F_23 ( L_2 , V_28 -> V_14 ) ;
break;
case 0x0080 ... 0x0085 :
F_23 ( L_3 ,
V_28 -> type , V_28 -> V_14 ) ;
break;
default:
F_23 ( L_4 ,
V_28 -> type , V_28 -> V_14 ) ;
}
return 0 ;
}
static int T_2 F_24 ( struct V_26 * V_27 ,
const struct V_11 * V_28 )
{
switch ( V_28 -> type ) {
case V_39 :
{
char V_40 [ 6 ] ;
F_10 ( V_40 , V_28 , 6 ) ;
F_23 ( L_5 , V_40 ) ;
break;
}
default:
F_23 ( L_4 ,
V_28 -> type , V_28 -> V_14 ) ;
}
return 0 ;
}
static int T_2 F_25 ( struct V_26 * V_27 ,
const struct V_11 * V_28 )
{
switch ( V_28 -> type ) {
case V_41 :
{
unsigned long V_42 [ 2 ] ;
F_10 ( & V_42 , V_28 , 8 ) ;
F_23 ( L_6 ,
V_42 [ 0 ] , V_42 [ 1 ] ) ;
break;
}
case V_43 :
{
unsigned long V_44 [ 2 ] ;
F_10 ( & V_44 , V_28 , 8 ) ;
F_23 ( L_7 ,
V_44 [ 0 ] , V_44 [ 1 ] ) ;
break;
}
default:
F_23 ( L_4 ,
V_28 -> type , V_28 -> V_14 ) ;
}
return 0 ;
}
static int T_2 F_26 ( struct V_26 * V_27 ,
const struct V_11 * V_28 )
{
switch ( V_27 -> V_30 ) {
case V_45 :
F_22 ( V_27 , V_28 ) ;
break;
case V_46 :
F_24 ( V_27 , V_28 ) ;
break;
case V_47 :
F_25 ( V_27 , V_28 ) ;
break;
default:
F_23 ( L_4 ,
V_28 -> type , V_28 -> V_14 ) ;
}
return 0 ;
}
static struct V_26 * T_2
F_27 ( struct V_19 * V_20 , int V_10 ,
const struct V_11 * V_48 )
{
struct V_21 V_22 ;
struct V_11 V_28 ;
struct V_26 * V_27 ;
F_23 ( L_8 , V_48 -> type ) ;
F_16 ( V_48 , & V_22 ) ;
F_28 ( L_9 ,
V_8 , V_48 -> V_13 , V_22 . V_13 ) ;
if ( ( V_27 = F_29 ( sizeof( * V_27 ) , V_49 ) ) == NULL )
return NULL ;
V_27 -> V_29 = V_48 -> type ;
V_27 -> V_23 = V_22 . V_13 ;
V_27 -> V_20 = V_20 ;
while ( F_15 ( & V_22 , & V_28 ) != - 1 ) {
switch ( V_28 . type ) {
case V_50 :
{
unsigned short V_51 [ 4 ] ;
F_10 ( V_51 , & V_28 , 8 ) ;
V_27 -> V_30 = V_51 [ 0 ] ;
V_27 -> type = V_51 [ 1 ] ;
V_27 -> V_32 = V_51 [ 2 ] ;
V_27 -> V_31 = V_51 [ 3 ] ;
F_23 ( L_10 ,
V_51 [ 0 ] , V_51 [ 1 ] , V_51 [ 2 ] , V_51 [ 3 ] ) ;
break;
}
case V_52 :
{
F_11 ( V_27 -> V_53 , & V_28 , 64 ) ;
F_23 ( L_11 , V_27 -> V_53 ) ;
break;
}
case V_54 :
{
struct V_21 V_55 ;
struct V_11 V_56 ;
F_16 ( & V_28 , & V_55 ) ;
F_15 ( & V_55 , & V_56 ) ;
V_27 -> V_57 = F_9 ( & V_56 ) ;
F_23 ( L_12 , V_27 -> V_57 ) ;
break;
}
case V_58 :
F_10 ( & V_27 -> V_59 , & V_28 , 4 ) ;
F_23 ( L_13 , V_27 -> V_59 ) ;
break;
case V_60 :
F_10 ( & V_27 -> V_61 , & V_28 , 4 ) ;
F_23 ( L_14 , V_27 -> V_61 ) ;
break;
case V_62 :
V_27 -> V_63 = V_28 . V_14 ;
F_23 ( L_15 , V_27 -> V_63 ) ;
break;
case V_64 :
V_27 -> V_65 = V_28 . V_14 ;
F_23 ( L_16 , V_27 -> V_65 ) ;
break;
default:
F_26 ( V_27 , & V_28 ) ;
}
}
return V_27 ;
}
static int T_2 F_30 ( struct V_19 * V_20 ,
const struct V_11 * V_48 )
{
struct V_21 V_22 ;
struct V_11 V_28 ;
struct V_66 {
T_1 V_67 ;
T_3 V_68 ;
char V_53 [ 32 ] ;
};
F_23 ( L_17 ) ;
F_16 ( V_48 , & V_22 ) ;
F_28 ( L_9 ,
V_8 , V_48 -> V_13 , V_22 . V_13 ) ;
while ( F_15 ( & V_22 , & V_28 ) != - 1 ) {
struct V_66 V_69 ;
T_1 V_67 ;
F_10 ( & V_67 , & V_28 , 4 ) ;
if ( V_67 > sizeof( V_69 ) - 1 )
V_67 = sizeof( V_69 ) - 1 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
F_10 ( & V_69 , & V_28 , V_67 ) ;
F_23 ( L_18 , V_28 . type ,
V_69 . V_68 , V_69 . V_53 ) ;
}
return 0 ;
}
static int T_2 F_31 ( struct V_19 * V_20 ,
const struct V_11 * V_28 )
{
unsigned char V_70 [ 128 ] ;
int V_71 , V_72 ;
F_10 ( & V_70 , V_28 , 128 ) ;
F_23 ( L_19 ) ;
for ( V_72 = 0 ; V_72 < 32 ; V_72 ++ ) {
F_23 ( L_20 ) ;
for ( V_71 = 0 ; V_71 < 32 ; V_71 ++ ) {
if ( V_70 [ V_72 * 4 + V_71 / 8 ] & ( 0x80 >> ( V_71 % 8 ) ) )
F_32 ( L_21 ) ;
else
F_32 ( L_22 ) ;
}
F_32 ( L_23 ) ;
}
return 0 ;
}
static int T_2 F_33 ( struct V_19 * V_20 ,
const struct V_11 * V_48 )
{
struct V_21 V_22 ;
struct V_11 V_28 ;
static char * V_73 [ 6 ] = { L_24 , L_25 , L_26 ,
L_27 , L_28 , L_29 } ;
F_23 ( L_30 ) ;
F_16 ( V_48 , & V_22 ) ;
F_28 ( L_9 ,
V_8 , V_48 -> V_13 , V_22 . V_13 ) ;
while ( F_15 ( & V_22 , & V_28 ) != - 1 ) {
char V_53 [ 64 ] ;
F_11 ( V_53 , & V_28 , 64 ) ;
if ( V_28 . type > 5 )
V_28 . type = 5 ;
F_23 ( L_31 , V_73 [ V_28 . type - 1 ] , V_53 ) ;
}
return 0 ;
}
static int T_2 F_34 ( struct V_19 * V_20 , int V_10 ,
const struct V_11 * V_48 )
{
struct V_21 V_22 ;
struct V_11 V_28 ;
F_16 ( V_48 , & V_22 ) ;
F_28 ( L_9 ,
V_8 , V_48 -> V_13 , V_22 . V_13 ) ;
while ( F_15 ( & V_22 , & V_28 ) != - 1 ) {
switch ( V_28 . type ) {
case V_50 :
{
unsigned short V_51 [ 4 ] ;
F_10 ( V_51 , & V_28 , 8 ) ;
F_23 ( L_10 ,
V_51 [ 0 ] , V_51 [ 1 ] , V_51 [ 2 ] , V_51 [ 3 ] ) ;
if ( V_51 [ 0 ] != 1 || V_51 [ 1 ] != 0 ||
V_51 [ 2 ] != 0 || V_51 [ 3 ] != 0 )
F_6 ( L_32 ) ;
break;
}
case V_52 :
F_11 ( V_20 -> V_53 , & V_28 , 64 ) ;
F_23 ( L_11 , V_20 -> V_53 ) ;
break;
case V_74 :
F_31 ( V_20 , & V_28 ) ;
break;
case V_75 :
F_23 ( L_33 , V_28 . V_14 ) ;
break;
case V_76 :
F_23 ( L_34 , V_28 . V_14 ) ;
break;
case V_77 :
F_33 ( V_20 , & V_28 ) ;
break;
case V_62 :
F_23 ( L_15 , V_28 . V_14 ) ;
break;
case V_64 :
F_23 ( L_16 , V_28 . V_14 ) ;
break;
case V_78 :
F_23 ( L_35 , V_28 . V_14 ) ;
break;
case V_79 :
F_30 ( V_20 , & V_28 ) ;
break;
case V_80 :
F_23 ( L_36 ,
V_28 . V_14 ) ;
break;
default:
F_23 ( L_4 ,
V_28 . type , V_28 . V_14 ) ;
}
}
return 0 ;
}
static struct V_19 * T_2 F_35 ( int V_10 , int V_81 )
{
struct V_19 * V_20 ;
struct V_19 * * V_82 ;
unsigned char * V_83 ;
unsigned long V_84 ;
struct V_21 V_22 ;
struct V_11 V_28 ;
V_83 = F_8 ( V_10 ) ;
F_3 ( & V_83 , V_85 , V_81 ) ;
if ( ( V_20 = F_29 ( sizeof( * V_20 ) , V_49 ) ) == NULL )
return NULL ;
V_20 -> V_86 = V_83 ;
F_28 ( L_37 , V_10 , V_83 ) ;
F_28 ( L_38 , F_2 ( & V_83 , 1 , V_81 ) ) ;
F_28 ( L_38 , F_2 ( & V_83 , 1 , V_81 ) ) ;
F_28 ( L_39 , F_2 ( & V_83 , 4 , V_81 ) ) ;
F_28 ( L_38 , F_2 ( & V_83 , 1 , V_81 ) ) ;
F_28 ( L_38 , F_2 ( & V_83 , 1 , V_81 ) ) ;
F_28 ( L_39 , F_2 ( & V_83 , 4 , V_81 ) ) ;
F_28 ( L_39 , F_2 ( & V_83 , 4 , V_81 ) ) ;
F_28 ( L_39 , F_2 ( & V_83 , 4 , V_81 ) ) ;
V_83 = V_20 -> V_86 ;
V_20 -> V_10 = V_10 ;
V_20 -> V_87 = ( unsigned long ) F_36 ( V_10 ) ;
V_20 -> V_88 = F_2 ( & V_83 , 4 , V_81 ) ;
V_20 -> V_89 = F_2 ( & V_83 , 4 , V_81 ) ;
V_20 -> V_90 = F_2 ( & V_83 , 4 , V_81 ) ;
V_20 -> V_91 = F_2 ( & V_83 , 1 , V_81 ) ;
V_20 -> V_92 = F_2 ( & V_83 , 1 , V_81 ) ;
V_20 -> V_25 = V_81 ;
if ( ! ( V_20 -> V_88 & 0x00FF0000 ) )
F_37 ( L_40 ) ;
V_84 = F_2 ( & V_83 , 4 , V_81 ) ;
if ( V_84 != V_93 )
F_37 ( L_41 , V_84 ) ;
V_20 -> V_23 = V_20 -> V_86 ;
F_5 ( & V_20 -> V_23 , F_7 ( V_20 -> V_88 ) ,
V_20 -> V_25 ) ;
F_12 ( V_20 , & V_22 ) ;
F_23 ( L_42 , V_10 ) ;
if ( F_15 ( & V_22 , & V_28 ) == - 1 ) {
F_6 ( L_43 ) ;
return NULL ;
} else {
F_23 ( L_44 ) ;
F_34 ( V_20 , V_10 , & V_28 ) ;
}
while ( F_15 ( & V_22 , & V_28 ) != - 1 ) {
struct V_26 * V_27 ;
struct V_26 * * V_94 ;
V_27 = F_27 ( V_20 , V_10 , & V_28 ) ;
if ( V_27 == NULL )
continue;
if ( V_20 -> V_95 == NULL )
V_20 -> V_95 = V_27 ;
for ( V_94 = & V_36 ; * V_94 != NULL ;
V_94 = & ( ( * V_94 ) -> V_35 ) )
;
* V_94 = V_27 ;
V_27 -> V_35 = NULL ;
}
for ( V_82 = & V_96 ; * V_82 != NULL ;
V_82 = & ( ( * V_82 ) -> V_35 ) )
;
* V_82 = V_20 ;
V_20 -> V_35 = NULL ;
return V_20 ;
}
void T_2 F_38 ( int V_10 )
{
unsigned char V_97 ;
unsigned char * V_83 ;
int V_98 ;
V_83 = F_8 ( V_10 ) ;
for ( V_98 = 4 ; V_98 ; V_98 -- ) {
int V_99 ;
V_83 -- ;
V_99 = F_39 ( V_83 ) ;
if ( ! V_99 )
continue;
V_97 = * V_83 ;
if ( ( ( ( V_97 >> 4 ) ^ V_97 ) & 0x0F ) != 0x0F )
continue;
if ( F_1 ( V_83 , V_97 ) )
continue;
F_35 ( V_10 , V_97 ) ;
return;
}
}
void T_2 F_40 ( void )
{
int V_10 ;
for ( V_10 = 9 ; V_10 < 15 ; V_10 ++ ) {
F_38 ( V_10 ) ;
}
}
static int T_2 F_41 ( void )
{
if ( ! V_100 )
return 0 ;
if ( V_101 ) {
F_42 () ;
} else {
F_43 () ;
}
F_23 ( L_45 ) ;
V_36 = NULL ;
V_96 = NULL ;
F_40 () ;
F_44 () ;
return 0 ;
}
