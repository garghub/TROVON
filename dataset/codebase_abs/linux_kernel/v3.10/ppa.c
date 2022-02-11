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
static inline int F_12 ( struct V_1 * V_2 , char * V_16 , int V_17 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
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
static int F_15 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
F_16 ( V_25 , L_5 , V_26 ) ;
F_16 ( V_25 , L_6 , V_4 -> V_4 -> V_6 -> V_27 ) ;
F_16 ( V_25 , L_7 , V_28 [ V_4 -> V_19 ] ) ;
#if V_29 > 0
F_16 ( V_25 , L_8 , V_4 -> V_20 ) ;
#endif
return 0 ;
}
static unsigned char F_17 ( T_1 * V_4 )
{
int V_30 ;
unsigned short V_31 = V_4 -> V_5 ;
unsigned char V_32 ;
V_30 = V_33 ;
for ( V_32 = F_18 ( V_31 ) ; ( ( V_32 & 0xc0 ) != 0xc0 ) && ( V_30 ) ; V_30 -- ) {
F_19 ( 1 ) ;
V_32 = F_18 ( V_31 ) ;
}
if ( V_30 )
return ( V_32 & 0xf0 ) ;
F_20 ( V_4 , V_34 ) ;
F_14 ( V_22 L_9 ) ;
return 0 ;
}
static inline void F_21 ( unsigned short V_31 )
{
int V_35 ;
V_35 = F_18 ( V_31 ) ;
F_22 ( V_31 , V_35 ) ;
F_22 ( V_31 , V_35 & 0xfe ) ;
}
static inline void F_23 ( T_1 * V_4 )
{
int V_35 , V_36 = V_4 -> V_4 -> V_6 -> V_37 ;
if ( V_36 == 0 )
return;
if ( ( F_24 ( V_36 ) & 0xe0 ) == 0x60 ) {
for ( V_35 = 0 ; V_35 < 100 ; V_35 ++ ) {
if ( F_24 ( V_36 ) & 0x01 )
return;
F_19 ( 5 ) ;
}
F_14 ( V_22 L_10 ) ;
}
}
static int F_25 ( unsigned short V_5 , const char * V_16 , int V_38 )
{
int V_35 ;
for ( V_35 = V_38 ; V_35 ; V_35 -- ) {
F_26 ( V_5 , * V_16 ++ ) ;
F_27 ( V_5 , 0xe ) ;
F_27 ( V_5 , 0xc ) ;
}
return 1 ;
}
static int F_28 ( unsigned short V_5 , char * V_16 , int V_38 )
{
int V_35 ;
for ( V_35 = V_38 ; V_35 ; V_35 -- ) {
* V_16 ++ = F_29 ( V_5 ) ;
F_27 ( V_5 , 0x27 ) ;
F_27 ( V_5 , 0x25 ) ;
}
return 1 ;
}
static int F_30 ( unsigned short V_5 , char * V_16 , int V_38 )
{
for (; V_38 ; V_38 -- ) {
unsigned char V_39 ;
F_27 ( V_5 , 0x4 ) ;
V_39 = F_18 ( V_5 ) & 0xf0 ;
F_27 ( V_5 , 0x6 ) ;
* V_16 ++ = V_39 | ( ( F_18 ( V_5 ) & 0xf0 ) >> 4 ) ;
}
return 1 ;
}
static int F_31 ( T_1 * V_4 , char * V_16 , int V_38 )
{
int V_32 ;
unsigned short V_31 = V_4 -> V_5 ;
V_32 = F_17 ( V_4 ) ;
if ( ( V_32 & 0x50 ) != 0x40 ) {
F_20 ( V_4 , V_40 ) ;
return 0 ;
}
switch ( V_4 -> V_19 ) {
case V_41 :
case V_42 :
V_32 = F_25 ( V_31 , V_16 , V_38 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
F_21 ( V_31 ) ;
F_27 ( V_31 , 0x4 ) ;
#ifdef F_32
if ( ! ( ( ( long ) V_16 | V_38 ) & 0x01 ) )
F_33 ( V_31 + 4 , V_16 , V_38 >> 1 ) ;
#else
if ( ! ( ( ( long ) V_16 | V_38 ) & 0x03 ) )
F_34 ( V_31 + 4 , V_16 , V_38 >> 2 ) ;
#endif
else
F_35 ( V_31 + 4 , V_16 , V_38 ) ;
F_27 ( V_31 , 0xc ) ;
V_32 = ! ( F_18 ( V_31 ) & 0x01 ) ;
F_27 ( V_31 , 0xc ) ;
F_23 ( V_4 ) ;
break;
default:
F_14 ( V_46 L_11 ) ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_36 ( T_1 * V_4 , char * V_16 , int V_38 )
{
int V_32 ;
unsigned short V_31 = V_4 -> V_5 ;
V_32 = F_17 ( V_4 ) ;
if ( ( V_32 & 0x50 ) != 0x50 ) {
F_20 ( V_4 , V_40 ) ;
return 0 ;
}
switch ( V_4 -> V_19 ) {
case V_41 :
V_32 = F_30 ( V_31 , V_16 , V_38 ) ;
F_27 ( V_31 , 0xc ) ;
break;
case V_42 :
F_27 ( V_31 , 0x25 ) ;
V_32 = F_28 ( V_31 , V_16 , V_38 ) ;
F_27 ( V_31 , 0x4 ) ;
F_27 ( V_31 , 0xc ) ;
break;
case V_43 :
case V_44 :
case V_45 :
F_21 ( V_31 ) ;
F_27 ( V_31 , 0x24 ) ;
#ifdef F_32
if ( ! ( ( ( long ) V_16 | V_38 ) & 0x01 ) )
F_37 ( V_31 + 4 , V_16 , V_38 >> 1 ) ;
#else
if ( ! ( ( ( long ) V_16 | V_38 ) & 0x03 ) )
F_38 ( V_31 + 4 , V_16 , V_38 >> 2 ) ;
#endif
else
F_39 ( V_31 + 4 , V_16 , V_38 ) ;
F_27 ( V_31 , 0x2c ) ;
V_32 = ! ( F_18 ( V_31 ) & 0x01 ) ;
F_27 ( V_31 , 0x2c ) ;
F_23 ( V_4 ) ;
break;
default:
F_14 ( V_46 L_12 ) ;
V_32 = 0 ;
break;
}
return V_32 ;
}
static inline void F_40 ( unsigned short V_31 , unsigned char V_47 )
{
F_26 ( V_31 , V_47 ) ;
F_27 ( V_31 , 0xc ) ;
F_27 ( V_31 , 0xe ) ;
F_27 ( V_31 , 0xc ) ;
F_27 ( V_31 , 0x4 ) ;
F_27 ( V_31 , 0xc ) ;
}
static void F_41 ( T_1 * V_4 )
{
unsigned short V_31 = V_4 -> V_5 ;
F_40 ( V_31 , 0 ) ;
F_40 ( V_31 , 0x3c ) ;
F_40 ( V_31 , 0x20 ) ;
F_40 ( V_31 , 0xf ) ;
}
static inline void F_42 ( unsigned short V_31 , unsigned char V_47 )
{
F_26 ( V_31 , V_47 ) ;
F_27 ( V_31 , 0x4 ) ;
F_27 ( V_31 , 0x6 ) ;
F_27 ( V_31 , 0x4 ) ;
F_27 ( V_31 , 0xc ) ;
}
static inline void F_43 ( T_1 * V_4 , int V_48 )
{
unsigned short V_31 = V_4 -> V_5 ;
F_42 ( V_31 , 0 ) ;
F_42 ( V_31 , 0x3c ) ;
F_42 ( V_31 , 0x20 ) ;
if ( ( V_48 == V_49 ) && F_44 ( V_4 -> V_19 ) )
F_42 ( V_31 , 0xcf ) ;
else
F_42 ( V_31 , 0x8f ) ;
}
static int F_45 ( T_1 * V_4 , int V_50 )
{
int V_30 ;
unsigned short V_31 = V_4 -> V_5 ;
V_30 = V_51 ;
do {
V_30 -- ;
F_19 ( 1 ) ;
} while ( ( F_18 ( V_31 ) & 0x40 ) && ( V_30 ) );
if ( ! V_30 )
return 0 ;
F_26 ( V_31 , ( 1 << V_50 ) ) ;
F_27 ( V_31 , 0xe ) ;
F_27 ( V_31 , 0xc ) ;
F_26 ( V_31 , 0x80 ) ;
F_27 ( V_31 , 0x8 ) ;
V_30 = V_51 ;
do {
V_30 -- ;
F_19 ( 1 ) ;
}
while ( ! ( F_18 ( V_31 ) & 0x40 ) && ( V_30 ) );
if ( ! V_30 )
return 0 ;
return 1 ;
}
static int F_46 ( T_1 * V_4 )
{
int V_52 ;
unsigned short V_31 = V_4 -> V_5 ;
F_41 ( V_4 ) ;
F_43 ( V_4 , V_53 ) ;
V_52 = 2 ;
F_27 ( V_31 , 0xe ) ;
if ( ( F_18 ( V_31 ) & 0x08 ) == 0x08 )
V_52 -- ;
F_27 ( V_31 , 0xc ) ;
if ( ( F_18 ( V_31 ) & 0x08 ) == 0x00 )
V_52 -- ;
if ( ! V_52 )
F_47 ( V_31 ) ;
F_19 ( 1000 ) ;
F_41 ( V_4 ) ;
F_19 ( 1000 ) ;
if ( V_52 )
return - V_54 ;
return F_48 ( V_4 ) ;
}
static inline int F_49 ( struct V_55 * V_56 )
{
T_1 * V_4 = F_1 ( V_56 -> V_57 -> V_2 ) ;
int V_30 ;
F_27 ( V_4 -> V_5 , 0x0c ) ;
for ( V_30 = 0 ; V_30 < V_56 -> V_58 ; V_30 ++ )
if ( ! F_31 ( V_4 , & V_56 -> V_59 [ V_30 ] , 1 ) )
return 0 ;
return 1 ;
}
static int F_50 ( struct V_55 * V_56 )
{
T_1 * V_4 = F_1 ( V_56 -> V_57 -> V_2 ) ;
unsigned short V_31 = V_4 -> V_5 ;
unsigned long V_60 = V_61 ;
unsigned char V_32 , V_62 ;
int V_63 , V_64 , V_65 ;
V_62 = V_56 -> V_59 [ 0 ] ;
V_64 = ( ( V_62 == V_66 ) ||
( V_62 == V_67 ) || ( V_62 == V_68 ) || ( V_62 == V_69 ) ) ;
V_32 = ( F_18 ( V_31 ) & 0xf0 ) ;
while ( V_32 != ( unsigned char ) 0xf0 ) {
if ( F_51 ( V_61 , V_60 + 1 ) )
return 0 ;
if ( ( V_56 -> V_8 . V_70 <= 0 ) ) {
F_20 ( V_4 , V_40 ) ;
return - 1 ;
}
if ( ( V_32 & 0xc0 ) != 0xc0 ) {
unsigned long V_30 = V_4 -> V_20 ;
for (; V_30 && ( ( V_32 = ( F_18 ( V_31 ) & 0xf0 ) ) & 0xc0 ) != 0xc0 ;
V_30 -- )
F_19 ( 1 ) ;
if ( ! V_30 )
return 0 ;
}
V_63 = ( V_64 && ( V_56 -> V_8 . V_70 >= V_71 ) )
? V_71 : 1 ;
if ( V_32 == ( unsigned char ) 0xc0 )
V_65 = F_31 ( V_4 , V_56 -> V_8 . V_72 , V_63 ) ;
else
V_65 = F_36 ( V_4 , V_56 -> V_8 . V_72 , V_63 ) ;
V_56 -> V_8 . V_72 += V_63 ;
V_56 -> V_8 . V_70 -= V_63 ;
if ( ! V_65 ) {
F_20 ( V_4 , V_73 ) ;
return - 1 ;
}
if ( V_56 -> V_8 . V_16 && ! V_56 -> V_8 . V_70 ) {
if ( V_56 -> V_8 . V_74 -- ) {
V_56 -> V_8 . V_16 ++ ;
V_56 -> V_8 . V_70 =
V_56 -> V_8 . V_16 -> V_17 ;
V_56 -> V_8 . V_72 = F_52 ( V_56 -> V_8 . V_16 ) ;
}
}
V_32 = ( F_18 ( V_31 ) & 0xf0 ) ;
if ( ! ( V_32 & 0x80 ) )
return 0 ;
}
return 1 ;
}
static void F_53 ( struct V_75 * V_76 )
{
T_1 * V_4 = F_54 ( V_76 , T_1 , V_77 . V_76 ) ;
struct V_55 * V_56 = V_4 -> V_7 ;
if ( ! V_56 ) {
F_14 ( V_46 L_13 ) ;
return;
}
if ( F_55 ( V_4 , V_56 ) ) {
F_56 ( & V_4 -> V_77 , 1 ) ;
return;
}
#if V_29 > 0
switch ( ( V_56 -> V_78 >> 16 ) & 0xff ) {
case V_79 :
break;
case V_80 :
F_14 ( V_81 L_14 , V_56 -> V_57 -> V_50 ) ;
break;
case V_73 :
F_14 ( V_81 L_15 ) ;
break;
case V_34 :
F_14 ( V_81 L_16 ) ;
break;
case V_82 :
F_14 ( V_81 L_17 ) ;
break;
case V_83 :
F_14 ( V_81 L_18 ) ;
break;
case V_40 :
F_14 ( V_81 L_19 ) ;
break;
case V_84 :
F_14 ( V_81 L_20 ) ;
break;
case V_85 :
F_14 ( V_22 L_21 ) ;
break;
default:
F_14 ( V_22 L_22 ,
( V_56 -> V_78 >> 16 ) & 0xff ) ;
}
#endif
if ( V_56 -> V_8 . V_9 > 1 )
F_41 ( V_4 ) ;
F_9 ( V_4 ) ;
V_4 -> V_7 = NULL ;
V_56 -> V_86 ( V_56 ) ;
}
static int F_55 ( T_1 * V_4 , struct V_55 * V_56 )
{
unsigned short V_31 = V_4 -> V_5 ;
unsigned char V_87 = 0 , V_39 = 0 ;
int V_52 ;
if ( V_4 -> V_88 )
return 0 ;
switch ( V_56 -> V_8 . V_9 ) {
case 0 :
if ( F_51 ( V_61 , V_4 -> V_89 + V_90 ) ) {
F_20 ( V_4 , V_73 ) ;
return 0 ;
}
return 1 ;
case 1 :
{
int V_52 = 2 ;
F_43 ( V_4 , V_49 ) ;
F_27 ( V_31 , 0xe ) ;
if ( ( F_18 ( V_31 ) & 0x08 ) == 0x08 )
V_52 -- ;
F_27 ( V_31 , 0xc ) ;
if ( ( F_18 ( V_31 ) & 0x08 ) == 0x00 )
V_52 -- ;
if ( V_52 ) {
if ( F_51 ( V_61 , V_4 -> V_89 + ( 1 * V_90 ) ) ) {
F_14 ( V_46 L_23 ) ;
F_20 ( V_4 , V_73 ) ;
return 0 ;
} else {
F_41 ( V_4 ) ;
return 1 ;
}
}
V_56 -> V_8 . V_9 ++ ;
}
case 2 :
if ( ! F_45 ( V_4 , F_57 ( V_56 ) ) ) {
F_20 ( V_4 , V_80 ) ;
return 0 ;
}
V_56 -> V_8 . V_9 ++ ;
case 3 :
F_27 ( V_31 , 0x0c ) ;
if ( ! ( F_18 ( V_31 ) & 0x80 ) )
return 1 ;
if ( ! F_49 ( V_56 ) )
return 0 ;
V_56 -> V_8 . V_9 ++ ;
case 4 :
if ( F_58 ( V_56 ) ) {
V_56 -> V_8 . V_16 = F_59 ( V_56 ) ;
V_56 -> V_8 . V_70 = V_56 -> V_8 . V_16 -> V_17 ;
V_56 -> V_8 . V_72 = F_52 ( V_56 -> V_8 . V_16 ) ;
} else {
V_56 -> V_8 . V_16 = NULL ;
V_56 -> V_8 . V_70 = 0 ;
V_56 -> V_8 . V_72 = NULL ;
}
V_56 -> V_8 . V_74 = F_60 ( V_56 ) - 1 ;
V_56 -> V_8 . V_9 ++ ;
case 5 :
F_27 ( V_31 , 0x0c ) ;
if ( ! ( F_18 ( V_31 ) & 0x80 ) )
return 1 ;
V_52 = F_50 ( V_56 ) ;
if ( V_52 == - 1 )
return 0 ;
if ( V_52 == 0 )
return 1 ;
V_56 -> V_8 . V_9 ++ ;
case 6 :
V_56 -> V_78 = V_79 << 16 ;
if ( F_17 ( V_4 ) != ( unsigned char ) 0xf0 ) {
F_20 ( V_4 , V_40 ) ;
return 0 ;
}
if ( F_36 ( V_4 , & V_87 , 1 ) ) {
if ( F_17 ( V_4 ) == ( unsigned char ) 0xf0 )
F_36 ( V_4 , & V_39 , 1 ) ;
V_56 -> V_78 =
( V_79 << 16 ) + ( V_39 << 8 ) + ( V_87 & V_91 ) ;
}
return 0 ;
break;
default:
F_14 ( V_46 L_24 ) ;
}
return 0 ;
}
static int F_61 ( struct V_55 * V_56 ,
void (* F_62) ( struct V_55 * ) )
{
T_1 * V_4 = F_1 ( V_56 -> V_57 -> V_2 ) ;
if ( V_4 -> V_7 ) {
F_14 ( V_46 L_25 ) ;
return 0 ;
}
V_4 -> V_88 = 0 ;
V_4 -> V_89 = V_61 ;
V_4 -> V_7 = V_56 ;
V_56 -> V_86 = F_62 ;
V_56 -> V_78 = V_40 << 16 ;
V_56 -> V_8 . V_9 = 0 ;
F_56 ( & V_4 -> V_77 , 0 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
int F_63 ( struct V_55 * V_56 )
{
T_1 * V_4 = F_1 ( V_56 -> V_57 -> V_2 ) ;
switch ( V_56 -> V_8 . V_9 ) {
case 0 :
case 1 :
V_4 -> V_7 = NULL ;
return V_92 ;
break;
default:
return V_93 ;
break;
}
}
static void F_47 ( unsigned int V_5 )
{
F_26 ( V_5 , 0x40 ) ;
F_27 ( V_5 , 0x8 ) ;
F_19 ( 30 ) ;
F_27 ( V_5 , 0xc ) ;
}
static int F_64 ( struct V_55 * V_56 )
{
T_1 * V_4 = F_1 ( V_56 -> V_57 -> V_2 ) ;
if ( V_56 -> V_8 . V_9 )
F_41 ( V_4 ) ;
V_4 -> V_7 = NULL ;
F_43 ( V_4 , V_53 ) ;
F_47 ( V_4 -> V_5 ) ;
F_65 ( 1 ) ;
F_41 ( V_4 ) ;
F_65 ( 1 ) ;
return V_92 ;
}
static int F_48 ( T_1 * V_4 )
{
static T_2 V_56 [ 6 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
int V_94 , V_95 , V_65 , V_30 , V_31 = V_4 -> V_5 ;
unsigned char V_87 ;
V_95 = V_4 -> V_19 ;
for ( V_94 = 0 ; V_94 < 8 ; V_94 ++ ) {
if ( ( V_31 & 0x0007 ) == 0x0000 )
V_4 -> V_19 = V_43 ;
V_96:
F_43 ( V_4 , V_49 ) ;
if ( ! F_45 ( V_4 , V_94 ) ) {
F_41 ( V_4 ) ;
continue;
}
F_14 ( V_21 L_26 ,
V_94 , V_28 [ V_4 -> V_19 ] ) ;
V_65 = 1 ;
F_27 ( V_31 , 0x0c ) ;
for ( V_87 = 0 ; ( V_87 < 6 ) && ( V_65 ) ; V_87 ++ )
V_65 = F_31 ( V_4 , V_56 , 1 ) ;
if ( ! V_65 ) {
F_41 ( V_4 ) ;
F_43 ( V_4 , V_49 ) ;
F_26 ( V_31 , 0x40 ) ;
F_27 ( V_31 , 0x08 ) ;
F_19 ( 30 ) ;
F_27 ( V_31 , 0x0c ) ;
F_19 ( 1000 ) ;
F_41 ( V_4 ) ;
F_19 ( 1000 ) ;
if ( V_4 -> V_19 == V_43 ) {
V_4 -> V_19 = V_95 ;
goto V_96;
}
return - V_54 ;
}
F_27 ( V_31 , 0x0c ) ;
V_30 = 1000000 ;
do {
V_87 = F_18 ( V_31 ) ;
V_30 -- ;
F_19 ( 1 ) ;
} while ( ! ( V_87 & 0x80 ) && ( V_30 ) );
V_87 &= 0xf0 ;
if ( V_87 != 0xf0 ) {
F_41 ( V_4 ) ;
F_43 ( V_4 , V_49 ) ;
F_47 ( V_31 ) ;
F_19 ( 1000 ) ;
F_41 ( V_4 ) ;
F_19 ( 1000 ) ;
if ( V_4 -> V_19 == V_43 ) {
V_4 -> V_19 = V_95 ;
goto V_96;
}
return - V_54 ;
}
F_41 ( V_4 ) ;
F_14 ( V_21 L_27 ,
V_94 , V_28 [ V_4 -> V_19 ] ) ;
F_43 ( V_4 , V_49 ) ;
F_47 ( V_31 ) ;
F_19 ( 1000 ) ;
F_41 ( V_4 ) ;
F_19 ( 1000 ) ;
return 0 ;
}
return - V_97 ;
}
static int F_66 ( struct V_98 * V_57 )
{
F_67 ( V_57 -> V_99 , V_100 ) ;
return 0 ;
}
static int F_68 ( struct V_101 * V_102 )
{
struct V_1 * V_2 ;
F_69 ( V_10 ) ;
F_70 ( V_103 ) ;
T_1 * V_4 ;
int V_104 ;
int V_105 , V_31 , V_36 ;
int V_106 = - V_107 ;
V_4 = F_71 ( sizeof( T_1 ) , V_108 ) ;
if ( ! V_4 )
return - V_107 ;
V_4 -> V_5 = - 1 ;
V_4 -> V_19 = V_109 ;
V_4 -> V_20 = V_110 ;
F_72 ( & V_10 ) ;
V_4 -> V_4 = F_73 ( V_102 , L_28 , NULL , F_4 ,
NULL , 0 , V_4 ) ;
if ( ! V_4 -> V_4 )
goto V_111;
V_106 = - V_112 ;
V_4 -> V_10 = & V_10 ;
F_74 ( & V_10 , & V_103 , V_113 ) ;
if ( F_8 ( V_4 ) )
F_75 ( 3 * V_90 ) ;
if ( V_4 -> V_14 ) {
F_14 ( V_46 L_29
L_30
L_31 , V_102 -> V_114 ) ;
F_9 ( V_4 ) ;
V_4 -> V_10 = NULL ;
F_76 ( & V_10 , & V_103 ) ;
goto V_115;
}
V_4 -> V_10 = NULL ;
F_76 ( & V_10 , & V_103 ) ;
V_31 = V_4 -> V_5 = V_4 -> V_4 -> V_6 -> V_5 ;
V_36 = V_4 -> V_4 -> V_6 -> V_37 ;
F_27 ( V_31 , 0x0c ) ;
V_105 = V_4 -> V_4 -> V_6 -> V_105 ;
V_4 -> V_19 = V_41 ;
if ( V_105 & V_116 )
V_4 -> V_19 = V_42 ;
if ( V_105 & V_117 ) {
F_77 ( V_36 , 0x20 ) ;
V_4 -> V_19 = V_42 ;
}
if ( ( V_105 & V_118 ) && ( V_105 & V_117 ) )
F_77 ( V_36 , 0x80 ) ;
V_106 = F_46 ( V_4 ) ;
F_11 ( V_4 ) ;
if ( V_106 )
goto V_115;
if ( V_4 -> V_19 == V_41 || V_4 -> V_19 == V_42 )
V_104 = 3 ;
else
V_104 = 8 ;
F_78 ( & V_4 -> V_77 , F_53 ) ;
V_106 = - V_107 ;
V_2 = F_79 ( & V_119 , sizeof( T_1 * ) ) ;
if ( ! V_2 )
goto V_115;
V_2 -> V_120 = V_102 -> V_5 ;
V_2 -> V_121 = V_104 ;
V_2 -> V_122 = - 1 ;
V_2 -> V_123 = V_102 -> V_114 ;
* ( T_1 * * ) & V_2 -> V_3 = V_4 ;
V_4 -> V_2 = V_2 ;
F_80 ( & V_4 -> V_124 , & V_125 ) ;
V_106 = F_81 ( V_2 , NULL ) ;
if ( V_106 )
goto V_126;
F_82 ( V_2 ) ;
return 0 ;
V_126:
F_83 ( & V_4 -> V_124 ) ;
F_84 ( V_2 ) ;
V_115:
F_85 ( V_4 -> V_4 ) ;
V_111:
F_86 ( V_4 ) ;
return V_106 ;
}
static void F_87 ( struct V_101 * V_102 )
{
F_68 ( V_102 ) ;
}
static void F_88 ( struct V_101 * V_102 )
{
T_1 * V_4 ;
F_89 (dev, &ppa_hosts, list) {
if ( V_4 -> V_4 -> V_6 == V_102 ) {
F_83 ( & V_4 -> V_124 ) ;
F_90 ( V_4 -> V_2 ) ;
F_84 ( V_4 -> V_2 ) ;
F_85 ( V_4 -> V_4 ) ;
F_86 ( V_4 ) ;
break;
}
}
}
static int T_3 F_91 ( void )
{
F_14 ( V_21 L_32 , V_26 ) ;
return F_92 ( & V_127 ) ;
}
static void T_4 F_93 ( void )
{
F_94 ( & V_127 ) ;
}
