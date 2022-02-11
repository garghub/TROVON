static inline T_1 * F_1 ( struct V_1 * V_2 )
{
return * ( T_1 * * ) & V_2 -> V_3 ;
}
static void F_2 ( T_1 * V_4 )
{
V_4 -> V_5 = V_4 -> V_4 -> V_6 -> V_5 ;
if ( V_4 -> V_7 )
V_4 -> V_7 -> V_8 . V_9 = 1 ;
else
F_3 ( V_4 -> V_10 ) ;
}
static void F_4 ( void * V_11 )
{
T_1 * V_4 = ( T_1 * ) V_11 ;
unsigned long V_12 ;
F_5 ( & V_13 , V_12 ) ;
if ( V_4 -> V_14 ) {
F_6 ( V_4 -> V_4 ) ;
F_2 ( V_4 ) ;
V_4 -> V_14 = 0 ;
}
F_7 ( & V_13 , V_12 ) ;
}
static int F_8 ( T_1 * V_4 )
{
unsigned long V_12 ;
int V_15 = 1 ;
F_5 ( & V_13 , V_12 ) ;
if ( F_6 ( V_4 -> V_4 ) == 0 ) {
F_2 ( V_4 ) ;
V_15 = 0 ;
}
V_4 -> V_14 = V_15 ;
F_7 ( & V_13 , V_12 ) ;
return V_15 ;
}
static void F_9 ( T_1 * V_4 )
{
unsigned long V_12 ;
int V_14 ;
F_5 ( & V_13 , V_12 ) ;
V_14 = V_4 -> V_14 ;
V_4 -> V_14 = 0 ;
F_7 ( & V_13 , V_12 ) ;
if ( ! V_14 )
F_10 ( V_4 -> V_4 ) ;
}
static inline void F_11 ( T_1 * V_4 )
{
F_10 ( V_4 -> V_4 ) ;
}
static inline int F_12 ( T_1 * V_4 , char * V_16 , int V_17 )
{
unsigned long V_18 ;
if ( ( V_17 > 5 ) && ( strncmp ( V_16 , L_1 , 5 ) == 0 ) ) {
V_18 = F_13 ( V_16 + 5 , NULL , 0 ) ;
V_4 -> V_19 = V_18 ;
return V_17 ;
}
F_14 ( L_2 ) ;
return ( - V_20 ) ;
}
static int F_15 ( struct V_1 * V_2 , char * V_16 , char * * V_21 ,
T_2 V_22 , int V_17 , int V_23 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
int V_24 = 0 ;
if ( V_23 )
return F_12 ( V_4 , V_16 , V_17 ) ;
V_24 += sprintf ( V_16 + V_24 , L_3 , V_25 ) ;
V_24 +=
sprintf ( V_16 + V_24 , L_4 ,
V_4 -> V_4 -> V_6 -> V_26 ) ;
V_24 +=
sprintf ( V_16 + V_24 , L_5 ,
V_27 [ V_4 -> V_19 ] ) ;
if ( V_22 > V_24 )
return 0 ;
* V_21 = V_16 + V_22 ;
V_24 -= V_22 ;
if ( V_24 > V_17 )
V_24 = V_17 ;
return V_24 ;
}
static unsigned char F_16 ( T_1 * V_4 )
{
int V_28 ;
unsigned short V_29 = V_4 -> V_5 ;
unsigned char V_30 ;
F_17 ( V_29 , 0x0c ) ;
V_28 = V_31 ;
do {
V_30 = F_18 ( V_29 ) ;
V_28 -- ;
F_19 ( 1 ) ;
}
while ( ! ( V_30 & 0x80 ) && ( V_28 ) );
F_17 ( V_29 , 0x04 ) ;
if ( V_28 )
return ( V_30 & 0xb8 ) ;
F_20 ( V_4 , V_32 ) ;
F_14 ( L_6 ) ;
return 0 ;
}
static int F_21 ( T_1 * V_33 )
{
unsigned short V_5 = V_33 -> V_5 ;
unsigned char V_34 , V_19 ;
switch ( V_33 -> V_19 ) {
case V_35 :
V_19 = 0x00 ;
break;
case V_36 :
V_19 = 0x01 ;
break;
default:
return 0 ;
}
F_17 ( V_5 , 0x04 ) ;
F_19 ( 5 ) ;
F_22 ( V_5 , V_19 ) ;
F_19 ( 100 ) ;
F_17 ( V_5 , 0x06 ) ;
F_19 ( 5 ) ;
V_34 = ( F_18 ( V_5 ) & 0x20 ) ? 0 : 1 ;
F_19 ( 5 ) ;
F_17 ( V_5 , 0x07 ) ;
F_19 ( 5 ) ;
F_17 ( V_5 , 0x06 ) ;
if ( V_34 ) {
F_14
( L_7 ) ;
F_20 ( V_33 , V_37 ) ;
}
return V_34 ;
}
static inline void F_23 ( unsigned short V_29 )
{
int V_38 ;
V_38 = F_18 ( V_29 ) ;
F_24 ( V_29 , V_38 ) ;
F_24 ( V_29 , V_38 & 0xfe ) ;
}
static inline void F_25 ( T_1 * V_4 )
{
int V_38 , V_39 = V_4 -> V_40 ;
if ( V_39 == 0 )
return;
if ( ( F_26 ( V_39 ) & 0xe0 ) == 0x60 ) {
for ( V_38 = 0 ; V_38 < 100 ; V_38 ++ ) {
if ( F_26 ( V_39 ) & 0x01 )
return;
F_19 ( 5 ) ;
}
F_14 ( L_8 ) ;
}
}
static int F_27 ( unsigned short V_5 , const char * V_16 , int V_24 )
{
int V_38 ;
F_17 ( V_5 , 0x4 ) ;
for ( V_38 = V_24 >> 1 ; V_38 ; V_38 -- ) {
F_22 ( V_5 , * V_16 ++ ) ;
F_17 ( V_5 , 0x5 ) ;
F_22 ( V_5 , * V_16 ++ ) ;
F_17 ( V_5 , 0x0 ) ;
}
F_17 ( V_5 , 0x4 ) ;
return 1 ;
}
static int F_28 ( unsigned short V_5 , char * V_16 , int V_24 )
{
unsigned char V_41 ;
int V_38 ;
F_17 ( V_5 , 0x4 ) ;
for ( V_38 = V_24 ; V_38 ; V_38 -- ) {
F_17 ( V_5 , 0x6 ) ;
V_41 = ( F_18 ( V_5 ) & 0xf0 ) >> 4 ;
F_17 ( V_5 , 0x5 ) ;
* V_16 ++ = ( F_18 ( V_5 ) & 0xf0 ) | V_41 ;
F_17 ( V_5 , 0x4 ) ;
}
return 1 ;
}
static int F_29 ( unsigned short V_5 , char * V_16 , int V_24 )
{
int V_38 ;
F_17 ( V_5 , 0x4 ) ;
for ( V_38 = V_24 ; V_38 ; V_38 -- ) {
F_17 ( V_5 , 0x26 ) ;
* V_16 ++ = F_30 ( V_5 ) ;
F_17 ( V_5 , 0x25 ) ;
}
return 1 ;
}
static int F_31 ( T_1 * V_4 , char * V_16 , int V_24 )
{
unsigned short V_29 = V_4 -> V_5 ;
int V_30 = F_16 ( V_4 ) ;
if ( ( V_30 & 0x18 ) != 0x08 ) {
F_20 ( V_4 , V_37 ) ;
F_14 ( L_9 , V_30 ) ;
return 0 ;
}
switch ( V_4 -> V_19 ) {
case V_42 :
case V_43 :
case V_44 :
F_23 ( V_29 ) ;
F_17 ( V_29 , 0x4 ) ;
#ifdef F_32
if ( ! ( ( ( long ) V_16 | V_24 ) & 0x01 ) )
F_33 ( V_29 + 4 , V_16 , V_24 >> 1 ) ;
#else
if ( ! ( ( ( long ) V_16 | V_24 ) & 0x03 ) )
F_34 ( V_29 + 4 , V_16 , V_24 >> 2 ) ;
#endif
else
F_35 ( V_29 + 4 , V_16 , V_24 ) ;
F_17 ( V_29 , 0xc ) ;
V_30 = ! ( F_18 ( V_29 ) & 0x01 ) ;
F_17 ( V_29 , 0xc ) ;
F_25 ( V_4 ) ;
break;
case V_35 :
case V_36 :
V_30 = F_27 ( V_29 , V_16 , V_24 ) ;
break;
default:
F_14 ( L_10 ) ;
V_30 = 0 ;
}
return V_30 ;
}
static int F_36 ( T_1 * V_4 , char * V_16 , int V_24 )
{
unsigned short V_29 = V_4 -> V_5 ;
int V_30 = F_16 ( V_4 ) ;
if ( ( V_30 & 0x18 ) != 0x18 ) {
F_20 ( V_4 , V_37 ) ;
return 0 ;
}
switch ( V_4 -> V_19 ) {
case V_35 :
V_30 = F_28 ( V_29 , V_16 , V_24 ) ;
F_17 ( V_29 , 0xc ) ;
break;
case V_36 :
V_30 = F_29 ( V_29 , V_16 , V_24 ) ;
F_17 ( V_29 , 0xc ) ;
break;
case V_42 :
case V_43 :
case V_44 :
F_23 ( V_29 ) ;
F_17 ( V_29 , 0x24 ) ;
#ifdef F_32
if ( ! ( ( ( long ) V_16 | V_24 ) & 0x01 ) )
F_37 ( V_29 + 4 , V_16 , V_24 >> 1 ) ;
#else
if ( ! ( ( ( long ) V_16 | V_24 ) & 0x03 ) )
F_38 ( V_29 + 4 , V_16 , V_24 >> 2 ) ;
#endif
else
F_39 ( V_29 + 4 , V_16 , V_24 ) ;
F_17 ( V_29 , 0x2c ) ;
V_30 = ! ( F_18 ( V_29 ) & 0x01 ) ;
F_17 ( V_29 , 0x2c ) ;
F_25 ( V_4 ) ;
break;
default:
F_14 ( L_11 ) ;
V_30 = 0 ;
break;
}
return V_30 ;
}
static int F_40 ( unsigned short V_29 , unsigned char V_45 )
{
unsigned char V_46 , V_47 , V_48 ;
F_17 ( V_29 , 0x0c ) ;
F_19 ( 2 ) ;
F_22 ( V_29 , 0xaa ) ;
F_19 ( 10 ) ;
F_22 ( V_29 , 0x55 ) ;
F_19 ( 10 ) ;
F_22 ( V_29 , 0x00 ) ;
F_19 ( 10 ) ;
F_22 ( V_29 , 0xff ) ;
F_19 ( 10 ) ;
V_46 = F_18 ( V_29 ) & 0xb8 ;
F_22 ( V_29 , 0x87 ) ;
F_19 ( 10 ) ;
V_47 = F_18 ( V_29 ) & 0xb8 ;
F_22 ( V_29 , 0x78 ) ;
F_19 ( 10 ) ;
V_48 = F_18 ( V_29 ) & 0x38 ;
F_22 ( V_29 , V_45 ) ;
F_19 ( 2 ) ;
F_17 ( V_29 , 0x0c ) ;
F_19 ( 10 ) ;
F_17 ( V_29 , 0x0d ) ;
F_19 ( 2 ) ;
F_17 ( V_29 , 0x0c ) ;
F_19 ( 10 ) ;
F_22 ( V_29 , 0xff ) ;
F_19 ( 10 ) ;
if ( ( V_46 == 0xb8 ) && ( V_47 == 0x18 ) && ( V_48 == 0x30 ) )
return 1 ;
if ( ( V_46 == 0xb8 ) && ( V_47 == 0x18 ) && ( V_48 == 0x38 ) )
return 0 ;
return - 1 ;
}
static inline int F_41 ( T_1 * V_4 , int V_49 )
{
unsigned short V_29 = V_4 -> V_5 ;
F_40 ( V_29 , 0xe0 ) ;
F_40 ( V_29 , 0x30 ) ;
if ( ( V_4 -> V_19 == V_44 ) ||
( V_4 -> V_19 == V_43 ) ||
( V_4 -> V_19 == V_42 ) )
return F_40 ( V_29 , 0x28 ) ;
return F_40 ( V_29 , 0xe0 ) ;
}
static void F_42 ( T_1 * V_4 )
{
F_40 ( V_4 -> V_5 , 0x30 ) ;
}
static int F_43 ( T_1 * V_4 , int V_50 )
{
int V_28 ;
unsigned short V_29 = V_4 -> V_5 ;
F_17 ( V_29 , 0xc ) ;
V_28 = V_51 ;
do {
V_28 -- ;
} while ( ( F_18 ( V_29 ) & 0x08 ) && ( V_28 ) );
if ( ! V_28 )
return 0 ;
F_17 ( V_29 , 0x4 ) ;
F_22 ( V_29 , 0x80 | ( 1 << V_50 ) ) ;
F_19 ( 1 ) ;
F_17 ( V_29 , 0xc ) ;
F_17 ( V_29 , 0xd ) ;
V_28 = V_51 ;
do {
V_28 -- ;
}
while ( ! ( F_18 ( V_29 ) & 0x08 ) && ( V_28 ) );
F_17 ( V_29 , 0xc ) ;
return ( V_28 ) ? 1 : 0 ;
}
static int F_44 ( T_1 * V_4 )
{
if ( F_41 ( V_4 , 0 ) != 1 )
return - V_52 ;
F_45 ( V_4 -> V_5 ) ;
F_46 ( 1 ) ;
F_42 ( V_4 ) ;
F_46 ( 1 ) ;
return F_47 ( V_4 ) ;
}
static inline int F_48 ( struct V_53 * V_54 )
{
T_1 * V_4 = F_1 ( V_54 -> V_55 -> V_2 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_54 -> V_56 ; V_28 += 2 )
if ( ! F_31 ( V_4 , & V_54 -> V_57 [ V_28 ] , 2 ) )
return 0 ;
return 1 ;
}
static int F_49 ( struct V_53 * V_54 )
{
T_1 * V_4 = F_1 ( V_54 -> V_55 -> V_2 ) ;
unsigned short V_29 = V_4 -> V_5 ;
unsigned long V_58 = V_59 ;
unsigned char V_30 , V_60 ;
int V_61 , V_62 , V_63 ;
V_60 = V_54 -> V_57 [ 0 ] ;
V_62 = ( ( V_60 == V_64 ) ||
( V_60 == V_65 ) || ( V_60 == V_66 ) || ( V_60 == V_67 ) ) ;
F_17 ( V_29 , 0x0c ) ;
V_30 = ( F_18 ( V_29 ) & 0xb8 ) ;
while ( V_30 != ( unsigned char ) 0xb8 ) {
if ( F_50 ( V_59 , V_58 + 1 ) )
return 0 ;
if ( ( ( V_30 & 0x88 ) != 0x88 ) || ( V_54 -> V_8 . V_68 <= 0 ) ) {
F_20 ( V_4 , V_37 ) ;
return - 1 ;
}
if ( V_4 -> V_69 == 0 ) {
V_61 = ( V_62
&& ( V_54 -> V_8 . V_68 >=
V_70 ) ) ? V_70 : 2 ;
V_63 = F_31 ( V_4 , V_54 -> V_8 . V_71 , V_61 ) ;
} else {
V_61 = ( V_62
&& ( V_54 -> V_8 . V_68 >=
V_70 ) ) ? V_70 : 1 ;
V_63 = F_36 ( V_4 , V_54 -> V_8 . V_71 , V_61 ) ;
}
V_54 -> V_8 . V_71 += V_61 ;
V_54 -> V_8 . V_68 -= V_61 ;
if ( ! V_63 ) {
F_20 ( V_4 , V_72 ) ;
return - 1 ;
}
if ( V_54 -> V_8 . V_16 && ! V_54 -> V_8 . V_68 ) {
if ( V_54 -> V_8 . V_73 -- ) {
V_54 -> V_8 . V_16 ++ ;
V_54 -> V_8 . V_68 =
V_54 -> V_8 . V_16 -> V_17 ;
V_54 -> V_8 . V_71 = F_51 ( V_54 -> V_8 . V_16 ) ;
if ( V_54 -> V_8 . V_68 & 0x01 )
V_54 -> V_8 . V_68 ++ ;
}
}
F_17 ( V_29 , 0x0c ) ;
V_30 = ( F_18 ( V_29 ) & 0xb8 ) ;
if ( ! ( V_30 & 0x80 ) )
return 0 ;
}
return 1 ;
}
static void F_52 ( struct V_74 * V_75 )
{
T_1 * V_4 = F_53 ( V_75 , T_1 , V_76 . V_75 ) ;
struct V_53 * V_54 = V_4 -> V_7 ;
struct V_1 * V_2 = V_54 -> V_55 -> V_2 ;
unsigned long V_12 ;
if ( F_54 ( V_4 , V_54 ) ) {
F_55 ( & V_4 -> V_76 , 1 ) ;
return;
}
#if V_77 > 0
switch ( ( V_54 -> V_78 >> 16 ) & 0xff ) {
case V_79 :
break;
case V_80 :
F_14 ( L_12 , V_54 -> V_55 -> V_81 ) ;
break;
case V_72 :
F_14 ( L_13 ) ;
break;
case V_32 :
F_14 ( L_14 ) ;
break;
case V_82 :
F_14 ( L_15 ) ;
break;
case V_83 :
F_14 ( L_16 ) ;
break;
case V_37 :
F_14 ( L_17 ) ;
break;
case V_84 :
F_14 ( L_18 ) ;
break;
case V_85 :
F_14 ( L_19 ) ;
break;
default:
F_14 ( L_20 ,
( V_54 -> V_78 >> 16 ) & 0xff ) ;
}
#endif
if ( V_54 -> V_8 . V_9 > 1 )
F_42 ( V_4 ) ;
F_9 ( V_4 ) ;
F_5 ( V_2 -> V_86 , V_12 ) ;
V_4 -> V_7 = NULL ;
V_54 -> V_87 ( V_54 ) ;
F_7 ( V_2 -> V_86 , V_12 ) ;
return;
}
static int F_54 ( T_1 * V_4 , struct V_53 * V_54 )
{
unsigned short V_29 = V_4 -> V_5 ;
unsigned char V_41 = 0 , V_88 = 0 ;
int V_89 , V_18 ;
if ( V_4 -> V_90 )
return 0 ;
switch ( V_54 -> V_8 . V_9 ) {
case 0 :
if ( F_50 ( V_59 , V_4 -> V_91 + V_92 ) ) {
F_20 ( V_4 , V_72 ) ;
return 0 ;
}
return 1 ;
case 1 :
F_41 ( V_4 , V_93 ) ;
V_54 -> V_8 . V_9 ++ ;
case 2 :
if ( ! F_43 ( V_4 , F_56 ( V_54 ) ) ) {
F_20 ( V_4 , V_80 ) ;
return 0 ;
}
V_54 -> V_8 . V_9 ++ ;
case 3 :
F_17 ( V_29 , 0x0c ) ;
if ( ! ( F_18 ( V_29 ) & 0x80 ) )
return 1 ;
if ( ! F_48 ( V_54 ) )
return 0 ;
V_54 -> V_8 . V_9 ++ ;
case 4 :
if ( F_57 ( V_54 ) ) {
V_54 -> V_8 . V_16 = F_58 ( V_54 ) ;
V_54 -> V_8 . V_68 = V_54 -> V_8 . V_16 -> V_17 ;
V_54 -> V_8 . V_71 = F_51 ( V_54 -> V_8 . V_16 ) ;
} else {
V_54 -> V_8 . V_16 = NULL ;
V_54 -> V_8 . V_68 = 0 ;
V_54 -> V_8 . V_71 = NULL ;
}
V_54 -> V_8 . V_73 = F_59 ( V_54 ) - 1 ;
V_54 -> V_8 . V_9 ++ ;
if ( V_54 -> V_8 . V_68 & 0x01 )
V_54 -> V_8 . V_68 ++ ;
case 5 :
F_17 ( V_29 , 0x0c ) ;
if ( ! ( F_18 ( V_29 ) & 0x80 ) )
return 1 ;
V_18 = ( F_18 ( V_29 ) & 0xb8 ) ;
V_4 -> V_69 = ( V_18 & 0x10 ) ? 1 : 0 ;
V_4 -> V_94 = ( V_18 & 0x20 ) ? 0 : 1 ;
if ( ( V_4 -> V_94 ) && ( V_4 -> V_69 ) )
if ( F_21 ( V_4 ) )
return 0 ;
V_54 -> V_8 . V_9 ++ ;
case 6 :
F_17 ( V_29 , 0x0c ) ;
if ( ! ( F_18 ( V_29 ) & 0x80 ) )
return 1 ;
if ( V_4 -> V_94 ) {
V_89 = F_49 ( V_54 ) ;
if ( V_89 == - 1 )
return 0 ;
if ( V_89 == 0 )
return 1 ;
}
V_54 -> V_8 . V_9 ++ ;
case 7 :
if ( ( V_4 -> V_94 ) && ( V_4 -> V_69 ) ) {
if ( ( V_4 -> V_19 == V_35 ) || ( V_4 -> V_19 == V_36 ) ) {
F_17 ( V_29 , 0x4 ) ;
F_17 ( V_29 , 0xc ) ;
F_17 ( V_29 , 0xe ) ;
F_17 ( V_29 , 0x4 ) ;
}
}
V_54 -> V_8 . V_9 ++ ;
case 8 :
if ( F_16 ( V_4 ) != ( unsigned char ) 0xb8 ) {
F_20 ( V_4 , V_37 ) ;
return 0 ;
}
if ( F_21 ( V_4 ) )
return 0 ;
if ( F_36 ( V_4 , & V_41 , 1 ) ) {
if ( F_16 ( V_4 ) == ( unsigned char ) 0xb8 )
F_36 ( V_4 , & V_88 , 1 ) ;
V_54 -> V_78 = ( V_79 << 16 ) + ( V_41 & V_95 ) ;
}
if ( ( V_4 -> V_19 == V_35 ) || ( V_4 -> V_19 == V_36 ) ) {
F_17 ( V_29 , 0x4 ) ;
F_17 ( V_29 , 0xc ) ;
F_17 ( V_29 , 0xe ) ;
F_17 ( V_29 , 0x4 ) ;
}
return 0 ;
break;
default:
F_14 ( L_21 ) ;
}
return 0 ;
}
static int F_60 ( struct V_53 * V_54 ,
void (* F_61)( struct V_53 * ) )
{
T_1 * V_4 = F_1 ( V_54 -> V_55 -> V_2 ) ;
if ( V_4 -> V_7 ) {
F_14 ( L_22 ) ;
return 0 ;
}
V_4 -> V_90 = 0 ;
V_4 -> V_91 = V_59 ;
V_4 -> V_7 = V_54 ;
V_54 -> V_87 = F_61 ;
V_54 -> V_78 = V_37 << 16 ;
V_54 -> V_8 . V_9 = 0 ;
F_55 ( & V_4 -> V_76 , 0 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
int F_62 ( struct V_53 * V_54 )
{
T_1 * V_4 = F_1 ( V_54 -> V_55 -> V_2 ) ;
switch ( V_54 -> V_8 . V_9 ) {
case 0 :
case 1 :
V_4 -> V_7 = NULL ;
return V_96 ;
break;
default:
return V_97 ;
break;
}
}
static void F_45 ( unsigned int V_5 )
{
F_17 ( V_5 , 0x04 ) ;
F_22 ( V_5 , 0x40 ) ;
F_19 ( 1 ) ;
F_17 ( V_5 , 0x0c ) ;
F_17 ( V_5 , 0x0d ) ;
F_19 ( 50 ) ;
F_17 ( V_5 , 0x0c ) ;
F_17 ( V_5 , 0x04 ) ;
}
static int F_63 ( struct V_53 * V_54 )
{
T_1 * V_4 = F_1 ( V_54 -> V_55 -> V_2 ) ;
if ( V_54 -> V_8 . V_9 )
F_42 ( V_4 ) ;
V_4 -> V_7 = NULL ;
F_41 ( V_4 , V_98 ) ;
F_45 ( V_4 -> V_5 ) ;
F_46 ( 1 ) ;
F_42 ( V_4 ) ;
F_46 ( 1 ) ;
return V_96 ;
}
static int F_47 ( T_1 * V_4 )
{
static char V_54 [ 6 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
int V_99 , V_100 , V_63 , V_28 , V_29 = V_4 -> V_5 ;
unsigned char V_41 ;
V_100 = V_4 -> V_19 ;
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ ) {
if ( ( V_29 & 0x0007 ) == 0x0000 )
V_4 -> V_19 = V_42 ;
V_101:
F_41 ( V_4 , V_93 ) ;
if ( ! F_43 ( V_4 , V_99 ) ) {
F_42 ( V_4 ) ;
continue;
}
F_14 ( L_23 ,
V_99 , V_27 [ V_4 -> V_19 ] ) ;
V_63 = 1 ;
F_17 ( V_29 , 0x0c ) ;
for ( V_41 = 0 ; ( V_41 < 3 ) && ( V_63 ) ; V_41 ++ )
V_63 = F_31 ( V_4 , & V_54 [ V_41 << 1 ] , 2 ) ;
if ( ! V_63 ) {
F_42 ( V_4 ) ;
F_41 ( V_4 , V_93 ) ;
F_45 ( V_4 -> V_5 ) ;
F_19 ( 1000 ) ;
F_42 ( V_4 ) ;
F_19 ( 1000 ) ;
if ( V_4 -> V_19 == V_42 ) {
V_4 -> V_19 = V_100 ;
goto V_101;
}
F_14 ( L_24 ) ;
return - V_52 ;
}
F_17 ( V_29 , 0x0c ) ;
V_28 = 1000000 ;
do {
V_41 = F_18 ( V_29 ) ;
V_28 -- ;
F_19 ( 1 ) ;
} while ( ! ( V_41 & 0x80 ) && ( V_28 ) );
V_41 &= 0xb8 ;
if ( V_41 != 0xb8 ) {
F_42 ( V_4 ) ;
F_41 ( V_4 , V_93 ) ;
F_45 ( V_4 -> V_5 ) ;
F_19 ( 1000 ) ;
F_42 ( V_4 ) ;
F_19 ( 1000 ) ;
if ( V_4 -> V_19 == V_42 ) {
V_4 -> V_19 = V_100 ;
goto V_101;
}
F_14
( L_24 ) ;
return - V_52 ;
}
F_42 ( V_4 ) ;
F_14
( L_25 ,
V_29 , V_99 , V_27 [ V_4 -> V_19 ] ) ;
F_41 ( V_4 , V_93 ) ;
F_45 ( V_4 -> V_5 ) ;
F_19 ( 1000 ) ;
F_42 ( V_4 ) ;
F_19 ( 1000 ) ;
return 0 ;
}
F_14 ( L_26 ) ;
return - V_102 ;
}
static int F_64 ( struct V_103 * V_55 )
{
F_65 ( V_55 -> V_104 , V_105 ) ;
return 0 ;
}
static int F_66 ( struct V_106 * V_107 )
{
struct V_1 * V_2 ;
T_1 * V_4 ;
F_67 ( V_10 ) ;
F_68 ( V_108 ) ;
int V_109 ;
int V_110 , V_29 ;
int V_111 = - V_112 ;
F_69 ( & V_10 ) ;
V_4 = F_70 ( sizeof( T_1 ) , V_113 ) ;
if ( ! V_4 )
return - V_112 ;
V_4 -> V_5 = - 1 ;
V_4 -> V_19 = V_114 ;
F_71 ( & V_4 -> V_115 ) ;
V_4 -> V_4 = F_72 ( V_107 , L_27 , NULL , F_4 ,
NULL , 0 , V_4 ) ;
if ( ! V_4 -> V_4 )
goto V_116;
V_111 = - V_117 ;
V_4 -> V_10 = & V_10 ;
F_73 ( & V_10 , & V_108 , V_118 ) ;
if ( F_8 ( V_4 ) )
F_74 ( 3 * V_92 ) ;
if ( V_4 -> V_14 ) {
F_14 ( V_119 L_28
L_29
L_30 , V_107 -> V_120 ) ;
F_9 ( V_4 ) ;
V_4 -> V_10 = NULL ;
F_75 ( & V_10 , & V_108 ) ;
goto V_121;
}
V_4 -> V_10 = NULL ;
F_75 ( & V_10 , & V_108 ) ;
V_29 = V_4 -> V_5 = V_4 -> V_4 -> V_6 -> V_5 ;
V_4 -> V_40 = V_4 -> V_4 -> V_6 -> V_40 ;
F_17 ( V_29 , 0x0c ) ;
V_110 = V_4 -> V_4 -> V_6 -> V_110 ;
V_4 -> V_19 = V_35 ;
if ( V_110 & V_122 )
V_4 -> V_19 = V_36 ;
V_111 = F_44 ( V_4 ) ;
F_11 ( V_4 ) ;
if ( V_111 )
goto V_121;
if ( V_4 -> V_19 == V_35 || V_4 -> V_19 == V_36 )
V_109 = 3 ;
else
V_109 = 8 ;
F_76 ( & V_4 -> V_76 , F_52 ) ;
V_111 = - V_112 ;
V_2 = F_77 ( & V_123 , sizeof( T_1 * ) ) ;
if ( ! V_2 )
goto V_121;
V_2 -> V_124 = V_107 -> V_5 ;
V_2 -> V_125 = V_109 ;
V_2 -> V_126 = - 1 ;
V_2 -> V_127 = V_107 -> V_120 ;
* ( T_1 * * ) & V_2 -> V_3 = V_4 ;
V_4 -> V_2 = V_2 ;
F_78 ( & V_4 -> V_115 , & V_128 ) ;
V_111 = F_79 ( V_2 , NULL ) ;
if ( V_111 )
goto V_129;
F_80 ( V_2 ) ;
return 0 ;
V_129:
F_81 ( & V_4 -> V_115 ) ;
F_82 ( V_2 ) ;
V_121:
F_83 ( V_4 -> V_4 ) ;
V_116:
F_84 ( V_4 ) ;
return V_111 ;
}
static void F_85 ( struct V_106 * V_107 )
{
F_66 ( V_107 ) ;
}
static void F_86 ( struct V_106 * V_107 )
{
T_1 * V_4 ;
F_87 (dev, &imm_hosts, list) {
if ( V_4 -> V_4 -> V_6 == V_107 ) {
F_81 ( & V_4 -> V_115 ) ;
F_88 ( V_4 -> V_2 ) ;
F_82 ( V_4 -> V_2 ) ;
F_83 ( V_4 -> V_4 ) ;
F_84 ( V_4 ) ;
break;
}
}
}
static int T_3 F_89 ( void )
{
F_14 ( L_31 , V_25 ) ;
return F_90 ( & V_130 ) ;
}
static void T_4 F_91 ( void )
{
F_92 ( & V_130 ) ;
}
