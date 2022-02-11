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
if ( V_5 > 65536 )
F_4 ( L_1 , V_5 ) ;
while ( V_5 ) {
do {
V_1 -- ;
} while ( F_1 ( V_1 , V_2 ) );
V_5 -- ;
}
* V_4 = V_1 ;
}
static void F_5 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
unsigned char * V_1 = * V_4 ;
if ( V_5 > 65536 )
F_4 ( L_2 , V_5 ) ;
while ( V_5 ) {
while ( F_1 ( V_1 , V_2 ) )
V_1 ++ ;
V_1 ++ ;
V_5 -- ;
}
* V_4 = V_1 ;
}
static void F_6 ( unsigned char * * V_4 , int V_5 , int V_2 )
{
if ( V_5 > 0 )
F_5 ( V_4 , V_5 , V_2 ) ;
else if ( V_5 < 0 )
F_3 ( V_4 , - V_5 , V_2 ) ;
}
static inline long F_7 ( long V_7 )
{
if ( V_7 & 0x00800000 )
V_7 |= 0xFF000000 ;
return V_7 ;
}
static inline void * F_8 ( int V_8 )
{
return ( void * ) ( 0xF1000000 + ( V_8 << 24 ) ) ;
}
static unsigned char * F_9 ( const struct V_9 * V_10 )
{
unsigned char * V_1 = V_10 -> V_11 ;
F_6 ( & V_1 , F_7 ( V_10 -> V_12 ) , V_10 -> V_13 ) ;
return V_1 ;
}
void F_10 ( void * V_14 , const struct V_9 * V_15 ,
int V_5 )
{
unsigned char * V_16 = ( unsigned char * ) V_14 ;
unsigned char * V_1 = F_9 ( V_15 ) ;
while ( V_5 ) {
* V_16 ++ = F_2 ( & V_1 , 1 , V_15 -> V_13 ) ;
V_5 -- ;
}
}
void F_11 ( void * V_14 , const struct V_9 * V_15 ,
int V_5 )
{
unsigned char * V_16 = ( unsigned char * ) V_14 ;
unsigned char * V_1 = F_9 ( V_15 ) ;
while ( V_5 ) {
* V_16 = F_2 ( & V_1 , 1 , V_15 -> V_13 ) ;
if ( ! * V_16 ++ )
break;
V_5 -- ;
}
}
int F_12 ( const struct V_17 * V_18 ,
struct V_19 * V_20 )
{
V_20 -> V_4 = V_20 -> V_11 = V_18 -> V_21 ;
V_20 -> V_22 = 0 ;
V_20 -> V_13 = V_18 -> V_23 ;
return 0 ;
}
int F_13 ( const struct V_24 * V_25 ,
struct V_19 * V_20 )
{
V_20 -> V_4 = V_20 -> V_11 = V_25 -> V_21 ;
V_20 -> V_22 = 0 ;
V_20 -> V_13 = V_25 -> V_18 -> V_23 ;
return 0 ;
}
int F_14 ( const struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_9 V_26 ;
V_20 -> V_4 = V_20 -> V_11 = V_18 -> V_21 ;
V_20 -> V_22 = 0 ;
V_20 -> V_13 = V_18 -> V_23 ;
if ( F_15 ( V_20 , & V_26 ) == - 1 )
return - 1 ;
if ( F_16 ( & V_26 , V_20 ) == - 1 )
return - 1 ;
return 0 ;
}
int F_16 ( const struct V_9 * V_26 ,
struct V_19 * V_20 )
{
V_20 -> V_4 = V_20 -> V_11 = F_9 ( V_26 ) ;
V_20 -> V_22 = 0 ;
V_20 -> V_13 = V_26 -> V_13 ;
return 0 ;
}
int F_15 ( struct V_19 * V_10 , struct V_9 * V_26 )
{
T_1 V_27 ;
if ( V_10 -> V_22 )
return - 1 ;
V_26 -> V_11 = V_10 -> V_4 ;
V_27 = F_2 ( & V_10 -> V_4 , 4 , V_10 -> V_13 ) ;
if ( ( V_27 & 0xff000000 ) == 0xff000000 ) {
V_10 -> V_22 = 1 ;
return - 1 ;
}
V_26 -> type = V_27 >> 24 ;
V_26 -> V_12 = V_27 & 0xffffff ;
V_26 -> V_13 = V_10 -> V_13 ;
return 0 ;
}
int F_17 ( struct V_19 * V_20 )
{
V_20 -> V_4 = V_20 -> V_11 ;
V_20 -> V_22 = 0 ;
return 0 ;
}
struct V_24 *
F_18 ( unsigned short V_28 , unsigned short type ,
unsigned short V_29 , unsigned short V_30 ,
const struct V_24 * V_31 )
{
struct V_24 * V_32 = V_31 ? V_31 -> V_33 : V_34 ;
while ( V_32 ) {
if ( V_32 -> V_28 == V_28 && V_32 -> type == type &&
V_32 -> V_29 == V_29 && V_32 -> V_30 == V_30 )
return V_32 ;
V_32 = V_32 -> V_33 ;
}
return NULL ;
}
struct V_24 *
F_19 ( unsigned short V_28 , unsigned short type ,
const struct V_24 * V_31 )
{
struct V_24 * V_32 = V_31 ? V_31 -> V_33 : V_34 ;
while ( V_32 ) {
if ( V_32 -> V_28 == V_28 && V_32 -> type == type )
return V_32 ;
V_32 = V_32 -> V_33 ;
}
return NULL ;
}
struct V_24 *
F_20 ( unsigned int V_8 , const struct V_24 * V_31 )
{
struct V_24 * V_32 = V_31 ? V_31 -> V_33 : V_34 ;
while ( V_32 ) {
if ( V_32 -> V_18 -> V_8 == V_8 )
return V_32 ;
V_32 = V_32 -> V_33 ;
}
return NULL ;
}
int
F_21 ( struct V_19 * V_20 , unsigned char V_35 ,
struct V_9 * V_26 )
{
while ( F_15 ( V_20 , V_26 ) != - 1 ) {
if ( V_26 -> type == V_35 )
return 0 ;
}
return - 1 ;
}
static int T_2 F_22 ( struct V_24 * V_25 ,
const struct V_9 * V_26 )
{
switch ( V_26 -> type ) {
case V_36 :
F_23 ( L_3 , V_26 -> V_12 ) ;
break;
case 0x0080 ... 0x0085 :
F_23 ( L_4 ,
V_26 -> type , V_26 -> V_12 ) ;
break;
default:
F_23 ( L_5 ,
V_26 -> type , V_26 -> V_12 ) ;
}
return 0 ;
}
static int T_2 F_24 ( struct V_24 * V_25 ,
const struct V_9 * V_26 )
{
switch ( V_26 -> type ) {
case V_37 :
{
char V_38 [ 6 ] ;
F_10 ( V_38 , V_26 , 6 ) ;
F_23 ( L_6 , V_38 ) ;
break;
}
default:
F_23 ( L_5 ,
V_26 -> type , V_26 -> V_12 ) ;
}
return 0 ;
}
static int T_2 F_25 ( struct V_24 * V_25 ,
const struct V_9 * V_26 )
{
switch ( V_26 -> type ) {
case V_39 :
{
unsigned long V_40 [ 2 ] ;
F_10 ( & V_40 , V_26 , 8 ) ;
F_23 ( L_7 ,
V_40 [ 0 ] , V_40 [ 1 ] ) ;
break;
}
case V_41 :
{
unsigned long V_42 [ 2 ] ;
F_10 ( & V_42 , V_26 , 8 ) ;
F_23 ( L_8 ,
V_42 [ 0 ] , V_42 [ 1 ] ) ;
break;
}
default:
F_23 ( L_5 ,
V_26 -> type , V_26 -> V_12 ) ;
}
return 0 ;
}
static int T_2 F_26 ( struct V_24 * V_25 ,
const struct V_9 * V_26 )
{
switch ( V_25 -> V_28 ) {
case V_43 :
F_22 ( V_25 , V_26 ) ;
break;
case V_44 :
F_24 ( V_25 , V_26 ) ;
break;
case V_45 :
F_25 ( V_25 , V_26 ) ;
break;
default:
F_23 ( L_5 ,
V_26 -> type , V_26 -> V_12 ) ;
}
return 0 ;
}
static struct V_24 * T_2
F_27 ( struct V_17 * V_18 , int V_8 ,
const struct V_9 * V_46 )
{
struct V_19 V_20 ;
struct V_9 V_26 ;
struct V_24 * V_25 ;
F_23 ( L_9 , V_46 -> type ) ;
F_16 ( V_46 , & V_20 ) ;
if ( V_8 == 0 && ( unsigned long ) V_20 . V_11 % 2 )
V_20 . V_11 += 1 ;
F_28 ( L_10 ,
V_47 , V_46 -> V_11 , V_20 . V_11 ) ;
if ( ( V_25 = F_29 ( sizeof( * V_25 ) , V_48 ) ) == NULL )
return NULL ;
V_25 -> V_27 = V_46 -> type ;
V_25 -> V_21 = V_20 . V_11 ;
V_25 -> V_18 = V_18 ;
while ( F_15 ( & V_20 , & V_26 ) != - 1 ) {
switch ( V_26 . type ) {
case V_49 :
{
unsigned short V_50 [ 4 ] ;
F_10 ( V_50 , & V_26 , 8 ) ;
V_25 -> V_28 = V_50 [ 0 ] ;
V_25 -> type = V_50 [ 1 ] ;
V_25 -> V_30 = V_50 [ 2 ] ;
V_25 -> V_29 = V_50 [ 3 ] ;
F_23 ( L_11 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] ) ;
break;
}
case V_51 :
{
F_11 ( V_25 -> V_52 , & V_26 , 64 ) ;
F_23 ( L_12 , V_25 -> V_52 ) ;
break;
}
case V_53 :
{
struct V_19 V_54 ;
struct V_9 V_55 ;
F_16 ( & V_26 , & V_54 ) ;
F_15 ( & V_54 , & V_55 ) ;
V_25 -> V_56 = F_9 ( & V_55 ) ;
F_23 ( L_13 , V_25 -> V_56 ) ;
break;
}
case V_57 :
F_10 ( & V_25 -> V_58 , & V_26 , 4 ) ;
F_23 ( L_14 , V_25 -> V_58 ) ;
break;
case V_59 :
F_10 ( & V_25 -> V_60 , & V_26 , 4 ) ;
F_23 ( L_15 , V_25 -> V_60 ) ;
break;
case V_61 :
V_25 -> V_62 = V_26 . V_12 ;
F_23 ( L_16 , V_25 -> V_62 ) ;
break;
case V_63 :
V_25 -> V_64 = V_26 . V_12 ;
F_23 ( L_17 , V_25 -> V_64 ) ;
break;
default:
F_26 ( V_25 , & V_26 ) ;
}
}
return V_25 ;
}
static int T_2 F_30 ( struct V_17 * V_18 ,
const struct V_9 * V_46 )
{
struct V_19 V_20 ;
struct V_9 V_26 ;
struct V_65 {
T_1 V_66 ;
T_3 V_67 ;
char V_52 [ 32 ] ;
};
F_23 ( L_18 ) ;
F_16 ( V_46 , & V_20 ) ;
F_28 ( L_10 ,
V_47 , V_46 -> V_11 , V_20 . V_11 ) ;
while ( F_15 ( & V_20 , & V_26 ) != - 1 ) {
struct V_65 V_68 ;
T_1 V_66 ;
F_10 ( & V_66 , & V_26 , 4 ) ;
if ( V_66 > sizeof( V_68 ) - 1 )
V_66 = sizeof( V_68 ) - 1 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
F_10 ( & V_68 , & V_26 , V_66 ) ;
F_23 ( L_19 , V_26 . type ,
V_68 . V_67 , V_68 . V_52 ) ;
}
return 0 ;
}
static int T_2 F_31 ( struct V_17 * V_18 ,
const struct V_9 * V_26 )
{
unsigned char V_69 [ 128 ] ;
int V_70 , V_71 ;
F_10 ( & V_69 , V_26 , 128 ) ;
F_23 ( L_20 ) ;
for ( V_71 = 0 ; V_71 < 32 ; V_71 ++ ) {
F_23 ( L_21 ) ;
for ( V_70 = 0 ; V_70 < 32 ; V_70 ++ ) {
if ( V_69 [ V_71 * 4 + V_70 / 8 ] & ( 0x80 >> ( V_70 % 8 ) ) )
F_32 ( L_22 ) ;
else
F_32 ( L_23 ) ;
}
F_32 ( L_24 ) ;
}
return 0 ;
}
static int T_2 F_33 ( struct V_17 * V_18 ,
const struct V_9 * V_46 )
{
struct V_19 V_20 ;
struct V_9 V_26 ;
static char * V_72 [ 6 ] = { L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 } ;
F_23 ( L_31 ) ;
F_16 ( V_46 , & V_20 ) ;
F_28 ( L_10 ,
V_47 , V_46 -> V_11 , V_20 . V_11 ) ;
while ( F_15 ( & V_20 , & V_26 ) != - 1 ) {
char V_52 [ 64 ] ;
F_11 ( V_52 , & V_26 , 64 ) ;
if ( V_26 . type > 5 )
V_26 . type = 5 ;
F_23 ( L_32 , V_72 [ V_26 . type - 1 ] , V_52 ) ;
}
return 0 ;
}
static int T_2 F_34 ( struct V_17 * V_18 , int V_8 ,
const struct V_9 * V_46 )
{
struct V_19 V_20 ;
struct V_9 V_26 ;
F_16 ( V_46 , & V_20 ) ;
F_28 ( L_10 ,
V_47 , V_46 -> V_11 , V_20 . V_11 ) ;
while ( F_15 ( & V_20 , & V_26 ) != - 1 ) {
switch ( V_26 . type ) {
case V_49 :
{
unsigned short V_50 [ 4 ] ;
F_10 ( V_50 , & V_26 , 8 ) ;
F_23 ( L_11 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] ) ;
if ( V_50 [ 0 ] != 1 || V_50 [ 1 ] != 0 ||
V_50 [ 2 ] != 0 || V_50 [ 3 ] != 0 )
F_4 ( L_33 ) ;
break;
}
case V_51 :
F_11 ( V_18 -> V_52 , & V_26 , 64 ) ;
F_23 ( L_12 , V_18 -> V_52 ) ;
break;
case V_73 :
F_31 ( V_18 , & V_26 ) ;
break;
case V_74 :
F_23 ( L_34 , V_26 . V_12 ) ;
break;
case V_75 :
F_23 ( L_35 , V_26 . V_12 ) ;
break;
case V_76 :
F_33 ( V_18 , & V_26 ) ;
break;
case V_61 :
F_23 ( L_16 , V_26 . V_12 ) ;
break;
case V_63 :
F_23 ( L_17 , V_26 . V_12 ) ;
break;
case V_77 :
F_23 ( L_36 , V_26 . V_12 ) ;
break;
case V_78 :
F_30 ( V_18 , & V_26 ) ;
break;
case V_79 :
F_23 ( L_37 ,
V_26 . V_12 ) ;
break;
default:
F_23 ( L_5 ,
V_26 . type , V_26 . V_12 ) ;
}
}
return 0 ;
}
static void T_2 F_35 ( struct V_17 * V_18 )
{
unsigned char * V_80 ;
unsigned char * V_81 ;
struct V_19 V_20 ;
struct V_9 V_26 ;
V_80 = V_18 -> V_82 ;
F_3 ( & V_80 , 4 , V_18 -> V_23 ) ;
if ( F_2 ( & V_80 , 4 , V_18 -> V_23 ) != V_83 ) {
V_18 -> V_21 = V_18 -> V_82 ;
F_6 ( & V_18 -> V_21 ,
F_7 ( V_18 -> V_84 ) ,
V_18 -> V_23 ) ;
return;
}
V_81 = F_8 ( V_18 -> V_8 ) ;
F_3 ( & V_81 , V_85 , V_18 -> V_23 ) ;
V_20 . V_11 = V_20 . V_4 = V_81 ;
V_20 . V_22 = 0 ;
V_20 . V_13 = V_18 -> V_23 ;
if ( F_15 ( & V_20 , & V_26 ) == - 1 )
goto V_86;
if ( V_87 >= V_88 )
F_36 ( V_89 L_38 , V_26 . type , V_26 . V_12 ) ;
if ( F_15 ( & V_20 , & V_26 ) == - 1 )
goto V_86;
if ( V_87 >= V_88 )
F_36 ( V_90 L_38 , V_26 . type , V_26 . V_12 ) ;
F_16 ( & V_26 , & V_20 ) ;
if ( F_15 ( & V_20 , & V_26 ) == - 1 )
goto V_86;
if ( V_87 >= V_88 )
F_36 ( V_90 L_38 , V_26 . type , V_26 . V_12 ) ;
if ( F_15 ( & V_20 , & V_26 ) == - 1 )
goto V_86;
if ( V_87 >= V_88 )
F_36 ( V_90 L_38 , V_26 . type , V_26 . V_12 ) ;
F_16 ( & V_26 , & V_20 ) ;
V_18 -> V_21 = V_20 . V_11 ;
return;
V_86:
V_18 -> V_21 = V_18 -> V_82 ;
F_6 ( & V_18 -> V_21 , F_7 ( V_18 -> V_84 ) , V_18 -> V_23 ) ;
F_36 ( V_91 L_39 ) ;
}
static struct V_17 * T_2 F_37 ( int V_8 , int V_92 )
{
struct V_17 * V_18 ;
struct V_17 * * V_93 ;
unsigned char * V_80 ;
unsigned long V_94 ;
struct V_19 V_20 ;
struct V_9 V_26 ;
V_80 = F_8 ( V_8 ) ;
F_3 ( & V_80 , V_95 , V_92 ) ;
if ( ( V_18 = F_29 ( sizeof( * V_18 ) , V_48 ) ) == NULL )
return NULL ;
V_18 -> V_82 = V_80 ;
F_28 ( L_40 , V_8 , V_80 ) ;
F_28 ( L_41 , F_2 ( & V_80 , 1 , V_92 ) ) ;
F_28 ( L_41 , F_2 ( & V_80 , 1 , V_92 ) ) ;
F_28 ( L_42 , F_2 ( & V_80 , 4 , V_92 ) ) ;
F_28 ( L_41 , F_2 ( & V_80 , 1 , V_92 ) ) ;
F_28 ( L_41 , F_2 ( & V_80 , 1 , V_92 ) ) ;
F_28 ( L_42 , F_2 ( & V_80 , 4 , V_92 ) ) ;
F_28 ( L_42 , F_2 ( & V_80 , 4 , V_92 ) ) ;
F_28 ( L_42 , F_2 ( & V_80 , 4 , V_92 ) ) ;
V_80 = V_18 -> V_82 ;
V_18 -> V_8 = V_8 ;
V_18 -> V_96 = ( unsigned long ) F_38 ( V_8 ) ;
V_18 -> V_84 = F_2 ( & V_80 , 4 , V_92 ) ;
V_18 -> V_97 = F_2 ( & V_80 , 4 , V_92 ) ;
V_18 -> V_98 = F_2 ( & V_80 , 4 , V_92 ) ;
V_18 -> V_99 = F_2 ( & V_80 , 1 , V_92 ) ;
V_18 -> V_100 = F_2 ( & V_80 , 1 , V_92 ) ;
V_18 -> V_23 = V_92 ;
if ( ! ( V_18 -> V_84 & 0x00FF0000 ) )
F_39 ( L_43 ) ;
V_94 = F_2 ( & V_80 , 4 , V_92 ) ;
if ( V_94 != V_83 )
F_39 ( L_44 , V_94 ) ;
F_35 ( V_18 ) ;
F_12 ( V_18 , & V_20 ) ;
F_23 ( L_45 , V_8 ) ;
if ( F_15 ( & V_20 , & V_26 ) == - 1 ) {
F_4 ( L_46 ) ;
return NULL ;
} else {
F_23 ( L_47 ) ;
F_34 ( V_18 , V_8 , & V_26 ) ;
}
while ( F_15 ( & V_20 , & V_26 ) != - 1 ) {
struct V_24 * V_25 ;
struct V_24 * * V_101 ;
V_25 = F_27 ( V_18 , V_8 , & V_26 ) ;
if ( V_25 == NULL )
continue;
if ( V_18 -> V_102 == NULL )
V_18 -> V_102 = V_25 ;
for ( V_101 = & V_34 ; * V_101 != NULL ;
V_101 = & ( ( * V_101 ) -> V_33 ) )
;
* V_101 = V_25 ;
V_25 -> V_33 = NULL ;
}
for ( V_93 = & V_103 ; * V_93 != NULL ;
V_93 = & ( ( * V_93 ) -> V_33 ) )
;
* V_93 = V_18 ;
V_18 -> V_33 = NULL ;
return V_18 ;
}
void T_2 F_40 ( int V_8 )
{
unsigned char V_104 ;
unsigned char * V_80 ;
int V_105 ;
V_80 = F_8 ( V_8 ) ;
for ( V_105 = 4 ; V_105 ; V_105 -- ) {
int V_106 ;
V_80 -- ;
V_106 = F_41 ( V_80 ) ;
if ( ! V_106 )
continue;
V_104 = * V_80 ;
if( V_104 == 0 )
continue;
if ( ( ( ( V_104 >> 4 ) ^ V_104 ) & 0x0F ) != 0x0F )
continue;
if ( ( V_104 & 0x0F ) >= ( 1 << V_105 ) )
continue;
F_37 ( V_8 , V_104 ) ;
return;
}
}
void T_2 F_42 ( void )
{
int V_8 ;
#ifdef F_43
F_40 ( 0 ) ;
#endif
for ( V_8 = 9 ; V_8 < 15 ; V_8 ++ ) {
F_40 ( V_8 ) ;
}
}
static int T_2 F_44 ( void )
{
if ( ! V_107 )
return 0 ;
if ( V_108 ) {
F_45 () ;
} else {
F_46 () ;
}
#ifdef F_47
F_48 ( 1000 ) ;
#endif
F_23 ( L_48 ) ;
V_34 = NULL ;
V_103 = NULL ;
F_42 () ;
F_49 () ;
return 0 ;
}
