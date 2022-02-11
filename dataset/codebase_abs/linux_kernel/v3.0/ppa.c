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
return;
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
if ( ( V_17 > 10 ) && ( strncmp ( V_16 , L_2 , 10 ) == 0 ) ) {
V_18 = F_13 ( V_16 + 10 , NULL , 0 ) ;
V_4 -> V_20 = V_18 ;
F_14 ( V_21 L_3 , V_18 ) ;
return V_17 ;
}
F_14 ( V_22 L_4 ) ;
return - V_23 ;
}
static int F_15 ( struct V_1 * V_2 , char * V_16 , char * * V_24 , T_2 V_25 , int V_17 , int V_26 )
{
int V_27 = 0 ;
T_1 * V_4 = F_1 ( V_2 ) ;
if ( V_26 )
return F_12 ( V_4 , V_16 , V_17 ) ;
V_27 += sprintf ( V_16 + V_27 , L_5 , V_28 ) ;
V_27 +=
sprintf ( V_16 + V_27 , L_6 ,
V_4 -> V_4 -> V_6 -> V_29 ) ;
V_27 +=
sprintf ( V_16 + V_27 , L_7 ,
V_30 [ V_4 -> V_19 ] ) ;
#if V_31 > 0
V_27 +=
sprintf ( V_16 + V_27 , L_8 , V_4 -> V_20 ) ;
#endif
if ( V_25 > V_17 )
return 0 ;
* V_24 = V_16 + V_25 ;
V_27 -= V_25 ;
if ( V_27 > V_17 )
V_27 = V_17 ;
return V_27 ;
}
static unsigned char F_16 ( T_1 * V_4 )
{
int V_32 ;
unsigned short V_33 = V_4 -> V_5 ;
unsigned char V_34 ;
V_32 = V_35 ;
for ( V_34 = F_17 ( V_33 ) ; ( ( V_34 & 0xc0 ) != 0xc0 ) && ( V_32 ) ; V_32 -- ) {
F_18 ( 1 ) ;
V_34 = F_17 ( V_33 ) ;
}
if ( V_32 )
return ( V_34 & 0xf0 ) ;
F_19 ( V_4 , V_36 ) ;
F_14 ( V_22 L_9 ) ;
return 0 ;
}
static inline void F_20 ( unsigned short V_33 )
{
int V_37 ;
V_37 = F_17 ( V_33 ) ;
F_21 ( V_33 , V_37 ) ;
F_21 ( V_33 , V_37 & 0xfe ) ;
}
static inline void F_22 ( T_1 * V_4 )
{
int V_37 , V_38 = V_4 -> V_4 -> V_6 -> V_39 ;
if ( V_38 == 0 )
return;
if ( ( F_23 ( V_38 ) & 0xe0 ) == 0x60 ) {
for ( V_37 = 0 ; V_37 < 100 ; V_37 ++ ) {
if ( F_23 ( V_38 ) & 0x01 )
return;
F_18 ( 5 ) ;
}
F_14 ( V_22 L_10 ) ;
}
}
static int F_24 ( unsigned short V_5 , const char * V_16 , int V_27 )
{
int V_37 ;
for ( V_37 = V_27 ; V_37 ; V_37 -- ) {
F_25 ( V_5 , * V_16 ++ ) ;
F_26 ( V_5 , 0xe ) ;
F_26 ( V_5 , 0xc ) ;
}
return 1 ;
}
static int F_27 ( unsigned short V_5 , char * V_16 , int V_27 )
{
int V_37 ;
for ( V_37 = V_27 ; V_37 ; V_37 -- ) {
* V_16 ++ = F_28 ( V_5 ) ;
F_26 ( V_5 , 0x27 ) ;
F_26 ( V_5 , 0x25 ) ;
}
return 1 ;
}
static int F_29 ( unsigned short V_5 , char * V_16 , int V_27 )
{
for (; V_27 ; V_27 -- ) {
unsigned char V_40 ;
F_26 ( V_5 , 0x4 ) ;
V_40 = F_17 ( V_5 ) & 0xf0 ;
F_26 ( V_5 , 0x6 ) ;
* V_16 ++ = V_40 | ( ( F_17 ( V_5 ) & 0xf0 ) >> 4 ) ;
}
return 1 ;
}
static int F_30 ( T_1 * V_4 , char * V_16 , int V_27 )
{
int V_34 ;
unsigned short V_33 = V_4 -> V_5 ;
V_34 = F_16 ( V_4 ) ;
if ( ( V_34 & 0x50 ) != 0x40 ) {
F_19 ( V_4 , V_41 ) ;
return 0 ;
}
switch ( V_4 -> V_19 ) {
case V_42 :
case V_43 :
V_34 = F_24 ( V_33 , V_16 , V_27 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
F_20 ( V_33 ) ;
F_26 ( V_33 , 0x4 ) ;
#ifdef F_31
if ( ! ( ( ( long ) V_16 | V_27 ) & 0x01 ) )
F_32 ( V_33 + 4 , V_16 , V_27 >> 1 ) ;
#else
if ( ! ( ( ( long ) V_16 | V_27 ) & 0x03 ) )
F_33 ( V_33 + 4 , V_16 , V_27 >> 2 ) ;
#endif
else
F_34 ( V_33 + 4 , V_16 , V_27 ) ;
F_26 ( V_33 , 0xc ) ;
V_34 = ! ( F_17 ( V_33 ) & 0x01 ) ;
F_26 ( V_33 , 0xc ) ;
F_22 ( V_4 ) ;
break;
default:
F_14 ( V_47 L_11 ) ;
V_34 = 0 ;
}
return V_34 ;
}
static int F_35 ( T_1 * V_4 , char * V_16 , int V_27 )
{
int V_34 ;
unsigned short V_33 = V_4 -> V_5 ;
V_34 = F_16 ( V_4 ) ;
if ( ( V_34 & 0x50 ) != 0x50 ) {
F_19 ( V_4 , V_41 ) ;
return 0 ;
}
switch ( V_4 -> V_19 ) {
case V_42 :
V_34 = F_29 ( V_33 , V_16 , V_27 ) ;
F_26 ( V_33 , 0xc ) ;
break;
case V_43 :
F_26 ( V_33 , 0x25 ) ;
V_34 = F_27 ( V_33 , V_16 , V_27 ) ;
F_26 ( V_33 , 0x4 ) ;
F_26 ( V_33 , 0xc ) ;
break;
case V_44 :
case V_45 :
case V_46 :
F_20 ( V_33 ) ;
F_26 ( V_33 , 0x24 ) ;
#ifdef F_31
if ( ! ( ( ( long ) V_16 | V_27 ) & 0x01 ) )
F_36 ( V_33 + 4 , V_16 , V_27 >> 1 ) ;
#else
if ( ! ( ( ( long ) V_16 | V_27 ) & 0x03 ) )
F_37 ( V_33 + 4 , V_16 , V_27 >> 2 ) ;
#endif
else
F_38 ( V_33 + 4 , V_16 , V_27 ) ;
F_26 ( V_33 , 0x2c ) ;
V_34 = ! ( F_17 ( V_33 ) & 0x01 ) ;
F_26 ( V_33 , 0x2c ) ;
F_22 ( V_4 ) ;
break;
default:
F_14 ( V_47 L_12 ) ;
V_34 = 0 ;
break;
}
return V_34 ;
}
static inline void F_39 ( unsigned short V_33 , unsigned char V_48 )
{
F_25 ( V_33 , V_48 ) ;
F_26 ( V_33 , 0xc ) ;
F_26 ( V_33 , 0xe ) ;
F_26 ( V_33 , 0xc ) ;
F_26 ( V_33 , 0x4 ) ;
F_26 ( V_33 , 0xc ) ;
}
static void F_40 ( T_1 * V_4 )
{
unsigned short V_33 = V_4 -> V_5 ;
F_39 ( V_33 , 0 ) ;
F_39 ( V_33 , 0x3c ) ;
F_39 ( V_33 , 0x20 ) ;
F_39 ( V_33 , 0xf ) ;
}
static inline void F_41 ( unsigned short V_33 , unsigned char V_48 )
{
F_25 ( V_33 , V_48 ) ;
F_26 ( V_33 , 0x4 ) ;
F_26 ( V_33 , 0x6 ) ;
F_26 ( V_33 , 0x4 ) ;
F_26 ( V_33 , 0xc ) ;
}
static inline void F_42 ( T_1 * V_4 , int V_49 )
{
unsigned short V_33 = V_4 -> V_5 ;
F_41 ( V_33 , 0 ) ;
F_41 ( V_33 , 0x3c ) ;
F_41 ( V_33 , 0x20 ) ;
if ( ( V_49 == V_50 ) && F_43 ( V_4 -> V_19 ) )
F_41 ( V_33 , 0xcf ) ;
else
F_41 ( V_33 , 0x8f ) ;
}
static int F_44 ( T_1 * V_4 , int V_51 )
{
int V_32 ;
unsigned short V_33 = V_4 -> V_5 ;
V_32 = V_52 ;
do {
V_32 -- ;
F_18 ( 1 ) ;
} while ( ( F_17 ( V_33 ) & 0x40 ) && ( V_32 ) );
if ( ! V_32 )
return 0 ;
F_25 ( V_33 , ( 1 << V_51 ) ) ;
F_26 ( V_33 , 0xe ) ;
F_26 ( V_33 , 0xc ) ;
F_25 ( V_33 , 0x80 ) ;
F_26 ( V_33 , 0x8 ) ;
V_32 = V_52 ;
do {
V_32 -- ;
F_18 ( 1 ) ;
}
while ( ! ( F_17 ( V_33 ) & 0x40 ) && ( V_32 ) );
if ( ! V_32 )
return 0 ;
return 1 ;
}
static int F_45 ( T_1 * V_4 )
{
int V_53 ;
unsigned short V_33 = V_4 -> V_5 ;
F_40 ( V_4 ) ;
F_42 ( V_4 , V_54 ) ;
V_53 = 2 ;
F_26 ( V_33 , 0xe ) ;
if ( ( F_17 ( V_33 ) & 0x08 ) == 0x08 )
V_53 -- ;
F_26 ( V_33 , 0xc ) ;
if ( ( F_17 ( V_33 ) & 0x08 ) == 0x00 )
V_53 -- ;
if ( ! V_53 )
F_46 ( V_33 ) ;
F_18 ( 1000 ) ;
F_40 ( V_4 ) ;
F_18 ( 1000 ) ;
if ( V_53 )
return - V_55 ;
return F_47 ( V_4 ) ;
}
static inline int F_48 ( struct V_56 * V_57 )
{
T_1 * V_4 = F_1 ( V_57 -> V_58 -> V_2 ) ;
int V_32 ;
F_26 ( V_4 -> V_5 , 0x0c ) ;
for ( V_32 = 0 ; V_32 < V_57 -> V_59 ; V_32 ++ )
if ( ! F_30 ( V_4 , & V_57 -> V_60 [ V_32 ] , 1 ) )
return 0 ;
return 1 ;
}
static int F_49 ( struct V_56 * V_57 )
{
T_1 * V_4 = F_1 ( V_57 -> V_58 -> V_2 ) ;
unsigned short V_33 = V_4 -> V_5 ;
unsigned long V_61 = V_62 ;
unsigned char V_34 , V_63 ;
int V_64 , V_65 , V_66 ;
V_63 = V_57 -> V_60 [ 0 ] ;
V_65 = ( ( V_63 == V_67 ) ||
( V_63 == V_68 ) || ( V_63 == V_69 ) || ( V_63 == V_70 ) ) ;
V_34 = ( F_17 ( V_33 ) & 0xf0 ) ;
while ( V_34 != ( unsigned char ) 0xf0 ) {
if ( F_50 ( V_62 , V_61 + 1 ) )
return 0 ;
if ( ( V_57 -> V_8 . V_71 <= 0 ) ) {
F_19 ( V_4 , V_41 ) ;
return - 1 ;
}
if ( ( V_34 & 0xc0 ) != 0xc0 ) {
unsigned long V_32 = V_4 -> V_20 ;
for (; V_32 && ( ( V_34 = ( F_17 ( V_33 ) & 0xf0 ) ) & 0xc0 ) != 0xc0 ;
V_32 -- )
F_18 ( 1 ) ;
if ( ! V_32 )
return 0 ;
}
V_64 = ( V_65 && ( V_57 -> V_8 . V_71 >= V_72 ) )
? V_72 : 1 ;
if ( V_34 == ( unsigned char ) 0xc0 )
V_66 = F_30 ( V_4 , V_57 -> V_8 . V_73 , V_64 ) ;
else
V_66 = F_35 ( V_4 , V_57 -> V_8 . V_73 , V_64 ) ;
V_57 -> V_8 . V_73 += V_64 ;
V_57 -> V_8 . V_71 -= V_64 ;
if ( ! V_66 ) {
F_19 ( V_4 , V_74 ) ;
return - 1 ;
}
if ( V_57 -> V_8 . V_16 && ! V_57 -> V_8 . V_71 ) {
if ( V_57 -> V_8 . V_75 -- ) {
V_57 -> V_8 . V_16 ++ ;
V_57 -> V_8 . V_71 =
V_57 -> V_8 . V_16 -> V_17 ;
V_57 -> V_8 . V_73 = F_51 ( V_57 -> V_8 . V_16 ) ;
}
}
V_34 = ( F_17 ( V_33 ) & 0xf0 ) ;
if ( ! ( V_34 & 0x80 ) )
return 0 ;
}
return 1 ;
}
static void F_52 ( struct V_76 * V_77 )
{
T_1 * V_4 = F_53 ( V_77 , T_1 , V_78 . V_77 ) ;
struct V_56 * V_57 = V_4 -> V_7 ;
if ( ! V_57 ) {
F_14 ( V_47 L_13 ) ;
return;
}
if ( F_54 ( V_4 , V_57 ) ) {
F_55 ( & V_4 -> V_78 , 1 ) ;
return;
}
#if V_31 > 0
switch ( ( V_57 -> V_79 >> 16 ) & 0xff ) {
case V_80 :
break;
case V_81 :
F_14 ( V_82 L_14 , V_57 -> V_58 -> V_51 ) ;
break;
case V_74 :
F_14 ( V_82 L_15 ) ;
break;
case V_36 :
F_14 ( V_82 L_16 ) ;
break;
case V_83 :
F_14 ( V_82 L_17 ) ;
break;
case V_84 :
F_14 ( V_82 L_18 ) ;
break;
case V_41 :
F_14 ( V_82 L_19 ) ;
break;
case V_85 :
F_14 ( V_82 L_20 ) ;
break;
case V_86 :
F_14 ( V_22 L_21 ) ;
break;
default:
F_14 ( V_22 L_22 ,
( V_57 -> V_79 >> 16 ) & 0xff ) ;
}
#endif
if ( V_57 -> V_8 . V_9 > 1 )
F_40 ( V_4 ) ;
F_9 ( V_4 ) ;
V_4 -> V_7 = NULL ;
V_57 -> V_87 ( V_57 ) ;
}
static int F_54 ( T_1 * V_4 , struct V_56 * V_57 )
{
unsigned short V_33 = V_4 -> V_5 ;
unsigned char V_88 = 0 , V_40 = 0 ;
int V_53 ;
if ( V_4 -> V_89 )
return 0 ;
switch ( V_57 -> V_8 . V_9 ) {
case 0 :
if ( F_50 ( V_62 , V_4 -> V_90 + V_91 ) ) {
F_19 ( V_4 , V_74 ) ;
return 0 ;
}
return 1 ;
case 1 :
{
int V_53 = 2 ;
F_42 ( V_4 , V_50 ) ;
F_26 ( V_33 , 0xe ) ;
if ( ( F_17 ( V_33 ) & 0x08 ) == 0x08 )
V_53 -- ;
F_26 ( V_33 , 0xc ) ;
if ( ( F_17 ( V_33 ) & 0x08 ) == 0x00 )
V_53 -- ;
if ( V_53 ) {
if ( F_50 ( V_62 , V_4 -> V_90 + ( 1 * V_91 ) ) ) {
F_14 ( V_47 L_23 ) ;
F_19 ( V_4 , V_74 ) ;
return 0 ;
} else {
F_40 ( V_4 ) ;
return 1 ;
}
}
V_57 -> V_8 . V_9 ++ ;
}
case 2 :
if ( ! F_44 ( V_4 , F_56 ( V_57 ) ) ) {
F_19 ( V_4 , V_81 ) ;
return 0 ;
}
V_57 -> V_8 . V_9 ++ ;
case 3 :
F_26 ( V_33 , 0x0c ) ;
if ( ! ( F_17 ( V_33 ) & 0x80 ) )
return 1 ;
if ( ! F_48 ( V_57 ) )
return 0 ;
V_57 -> V_8 . V_9 ++ ;
case 4 :
if ( F_57 ( V_57 ) ) {
V_57 -> V_8 . V_16 = F_58 ( V_57 ) ;
V_57 -> V_8 . V_71 = V_57 -> V_8 . V_16 -> V_17 ;
V_57 -> V_8 . V_73 = F_51 ( V_57 -> V_8 . V_16 ) ;
} else {
V_57 -> V_8 . V_16 = NULL ;
V_57 -> V_8 . V_71 = 0 ;
V_57 -> V_8 . V_73 = NULL ;
}
V_57 -> V_8 . V_75 = F_59 ( V_57 ) - 1 ;
V_57 -> V_8 . V_9 ++ ;
case 5 :
F_26 ( V_33 , 0x0c ) ;
if ( ! ( F_17 ( V_33 ) & 0x80 ) )
return 1 ;
V_53 = F_49 ( V_57 ) ;
if ( V_53 == - 1 )
return 0 ;
if ( V_53 == 0 )
return 1 ;
V_57 -> V_8 . V_9 ++ ;
case 6 :
V_57 -> V_79 = V_80 << 16 ;
if ( F_16 ( V_4 ) != ( unsigned char ) 0xf0 ) {
F_19 ( V_4 , V_41 ) ;
return 0 ;
}
if ( F_35 ( V_4 , & V_88 , 1 ) ) {
if ( F_16 ( V_4 ) == ( unsigned char ) 0xf0 )
F_35 ( V_4 , & V_40 , 1 ) ;
V_57 -> V_79 =
( V_80 << 16 ) + ( V_40 << 8 ) + ( V_88 & V_92 ) ;
}
return 0 ;
break;
default:
F_14 ( V_47 L_24 ) ;
}
return 0 ;
}
static int F_60 ( struct V_56 * V_57 ,
void (* F_61) ( struct V_56 * ) )
{
T_1 * V_4 = F_1 ( V_57 -> V_58 -> V_2 ) ;
if ( V_4 -> V_7 ) {
F_14 ( V_47 L_25 ) ;
return 0 ;
}
V_4 -> V_89 = 0 ;
V_4 -> V_90 = V_62 ;
V_4 -> V_7 = V_57 ;
V_57 -> V_87 = F_61 ;
V_57 -> V_79 = V_41 << 16 ;
V_57 -> V_8 . V_9 = 0 ;
F_55 ( & V_4 -> V_78 , 0 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
int F_62 ( struct V_56 * V_57 )
{
T_1 * V_4 = F_1 ( V_57 -> V_58 -> V_2 ) ;
switch ( V_57 -> V_8 . V_9 ) {
case 0 :
case 1 :
V_4 -> V_7 = NULL ;
return V_93 ;
break;
default:
return V_94 ;
break;
}
}
static void F_46 ( unsigned int V_5 )
{
F_25 ( V_5 , 0x40 ) ;
F_26 ( V_5 , 0x8 ) ;
F_18 ( 30 ) ;
F_26 ( V_5 , 0xc ) ;
}
static int F_63 ( struct V_56 * V_57 )
{
T_1 * V_4 = F_1 ( V_57 -> V_58 -> V_2 ) ;
if ( V_57 -> V_8 . V_9 )
F_40 ( V_4 ) ;
V_4 -> V_7 = NULL ;
F_42 ( V_4 , V_54 ) ;
F_46 ( V_4 -> V_5 ) ;
F_64 ( 1 ) ;
F_40 ( V_4 ) ;
F_64 ( 1 ) ;
return V_93 ;
}
static int F_47 ( T_1 * V_4 )
{
static T_3 V_57 [ 6 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
int V_95 , V_96 , V_66 , V_32 , V_33 = V_4 -> V_5 ;
unsigned char V_88 ;
V_96 = V_4 -> V_19 ;
for ( V_95 = 0 ; V_95 < 8 ; V_95 ++ ) {
if ( ( V_33 & 0x0007 ) == 0x0000 )
V_4 -> V_19 = V_44 ;
V_97:
F_42 ( V_4 , V_50 ) ;
if ( ! F_44 ( V_4 , V_95 ) ) {
F_40 ( V_4 ) ;
continue;
}
F_14 ( V_21 L_26 ,
V_95 , V_30 [ V_4 -> V_19 ] ) ;
V_66 = 1 ;
F_26 ( V_33 , 0x0c ) ;
for ( V_88 = 0 ; ( V_88 < 6 ) && ( V_66 ) ; V_88 ++ )
V_66 = F_30 ( V_4 , V_57 , 1 ) ;
if ( ! V_66 ) {
F_40 ( V_4 ) ;
F_42 ( V_4 , V_50 ) ;
F_25 ( V_33 , 0x40 ) ;
F_26 ( V_33 , 0x08 ) ;
F_18 ( 30 ) ;
F_26 ( V_33 , 0x0c ) ;
F_18 ( 1000 ) ;
F_40 ( V_4 ) ;
F_18 ( 1000 ) ;
if ( V_4 -> V_19 == V_44 ) {
V_4 -> V_19 = V_96 ;
goto V_97;
}
return - V_55 ;
}
F_26 ( V_33 , 0x0c ) ;
V_32 = 1000000 ;
do {
V_88 = F_17 ( V_33 ) ;
V_32 -- ;
F_18 ( 1 ) ;
} while ( ! ( V_88 & 0x80 ) && ( V_32 ) );
V_88 &= 0xf0 ;
if ( V_88 != 0xf0 ) {
F_40 ( V_4 ) ;
F_42 ( V_4 , V_50 ) ;
F_46 ( V_33 ) ;
F_18 ( 1000 ) ;
F_40 ( V_4 ) ;
F_18 ( 1000 ) ;
if ( V_4 -> V_19 == V_44 ) {
V_4 -> V_19 = V_96 ;
goto V_97;
}
return - V_55 ;
}
F_40 ( V_4 ) ;
F_14 ( V_21 L_27 ,
V_95 , V_30 [ V_4 -> V_19 ] ) ;
F_42 ( V_4 , V_50 ) ;
F_46 ( V_33 ) ;
F_18 ( 1000 ) ;
F_40 ( V_4 ) ;
F_18 ( 1000 ) ;
return 0 ;
}
return - V_98 ;
}
static int F_65 ( struct V_99 * V_58 )
{
F_66 ( V_58 -> V_100 , V_101 ) ;
return 0 ;
}
static int F_67 ( struct V_102 * V_103 )
{
struct V_1 * V_2 ;
F_68 ( V_10 ) ;
F_69 ( V_104 ) ;
T_1 * V_4 ;
int V_105 ;
int V_106 , V_33 , V_38 ;
int V_107 = - V_108 ;
V_4 = F_70 ( sizeof( T_1 ) , V_109 ) ;
if ( ! V_4 )
return - V_108 ;
V_4 -> V_5 = - 1 ;
V_4 -> V_19 = V_110 ;
V_4 -> V_20 = V_111 ;
F_71 ( & V_10 ) ;
V_4 -> V_4 = F_72 ( V_103 , L_28 , NULL , F_4 ,
NULL , 0 , V_4 ) ;
if ( ! V_4 -> V_4 )
goto V_112;
V_107 = - V_113 ;
V_4 -> V_10 = & V_10 ;
F_73 ( & V_10 , & V_104 , V_114 ) ;
if ( F_8 ( V_4 ) )
F_74 ( 3 * V_91 ) ;
if ( V_4 -> V_14 ) {
F_14 ( V_47 L_29
L_30
L_31 , V_103 -> V_115 ) ;
F_9 ( V_4 ) ;
V_4 -> V_10 = NULL ;
F_75 ( & V_10 , & V_104 ) ;
goto V_116;
}
V_4 -> V_10 = NULL ;
F_75 ( & V_10 , & V_104 ) ;
V_33 = V_4 -> V_5 = V_4 -> V_4 -> V_6 -> V_5 ;
V_38 = V_4 -> V_4 -> V_6 -> V_39 ;
F_26 ( V_33 , 0x0c ) ;
V_106 = V_4 -> V_4 -> V_6 -> V_106 ;
V_4 -> V_19 = V_42 ;
if ( V_106 & V_117 )
V_4 -> V_19 = V_43 ;
if ( V_106 & V_118 ) {
F_76 ( V_38 , 0x20 ) ;
V_4 -> V_19 = V_43 ;
}
if ( ( V_106 & V_119 ) && ( V_106 & V_118 ) )
F_76 ( V_38 , 0x80 ) ;
V_107 = F_45 ( V_4 ) ;
F_11 ( V_4 ) ;
if ( V_107 )
goto V_116;
if ( V_4 -> V_19 == V_42 || V_4 -> V_19 == V_43 )
V_105 = 3 ;
else
V_105 = 8 ;
F_77 ( & V_4 -> V_78 , F_52 ) ;
V_107 = - V_108 ;
V_2 = F_78 ( & V_120 , sizeof( T_1 * ) ) ;
if ( ! V_2 )
goto V_116;
V_2 -> V_121 = V_103 -> V_5 ;
V_2 -> V_122 = V_105 ;
V_2 -> V_123 = - 1 ;
V_2 -> V_124 = V_103 -> V_115 ;
* ( T_1 * * ) & V_2 -> V_3 = V_4 ;
V_4 -> V_2 = V_2 ;
F_79 ( & V_4 -> V_125 , & V_126 ) ;
V_107 = F_80 ( V_2 , NULL ) ;
if ( V_107 )
goto V_127;
F_81 ( V_2 ) ;
return 0 ;
V_127:
F_82 ( & V_4 -> V_125 ) ;
F_83 ( V_2 ) ;
V_116:
F_84 ( V_4 -> V_4 ) ;
V_112:
F_85 ( V_4 ) ;
return V_107 ;
}
static void F_86 ( struct V_102 * V_103 )
{
F_67 ( V_103 ) ;
}
static void F_87 ( struct V_102 * V_103 )
{
T_1 * V_4 ;
F_88 (dev, &ppa_hosts, list) {
if ( V_4 -> V_4 -> V_6 == V_103 ) {
F_82 ( & V_4 -> V_125 ) ;
F_89 ( V_4 -> V_2 ) ;
F_83 ( V_4 -> V_2 ) ;
F_84 ( V_4 -> V_4 ) ;
F_85 ( V_4 ) ;
break;
}
}
}
static int T_4 F_90 ( void )
{
F_14 ( V_21 L_32 , V_28 ) ;
return F_91 ( & V_128 ) ;
}
static void T_5 F_92 ( void )
{
F_93 ( & V_128 ) ;
}
