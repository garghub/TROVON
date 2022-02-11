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
if ( F_6 ( V_4 -> V_4 ) == 0 ) {
F_2 ( V_4 ) ;
V_4 -> V_14 = 0 ;
}
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
static int F_12 ( struct V_1 * V_2 , char * V_16 , int V_17 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
if ( ( V_17 > 5 ) && ( strncmp ( V_16 , L_1 , 5 ) == 0 ) ) {
V_4 -> V_18 = F_13 ( V_16 + 5 , NULL , 0 ) ;
return V_17 ;
}
F_14 ( L_2 ) ;
return - V_19 ;
}
static int F_15 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
F_16 ( V_21 , L_3 , V_22 ) ;
F_16 ( V_21 , L_4 , V_4 -> V_4 -> V_6 -> V_23 ) ;
F_16 ( V_21 , L_5 , V_24 [ V_4 -> V_18 ] ) ;
return 0 ;
}
static unsigned char F_17 ( T_1 * V_4 )
{
int V_25 ;
unsigned short V_26 = V_4 -> V_5 ;
unsigned char V_27 ;
F_18 ( V_26 , 0x0c ) ;
V_25 = V_28 ;
do {
V_27 = F_19 ( V_26 ) ;
V_25 -- ;
F_20 ( 1 ) ;
}
while ( ! ( V_27 & 0x80 ) && ( V_25 ) );
F_18 ( V_26 , 0x04 ) ;
if ( V_25 )
return ( V_27 & 0xb8 ) ;
F_21 ( V_4 , V_29 ) ;
F_14 ( L_6 ) ;
return 0 ;
}
static int F_22 ( T_1 * V_30 )
{
unsigned short V_5 = V_30 -> V_5 ;
unsigned char V_31 , V_18 ;
switch ( V_30 -> V_18 ) {
case V_32 :
V_18 = 0x00 ;
break;
case V_33 :
V_18 = 0x01 ;
break;
default:
return 0 ;
}
F_18 ( V_5 , 0x04 ) ;
F_20 ( 5 ) ;
F_23 ( V_5 , V_18 ) ;
F_20 ( 100 ) ;
F_18 ( V_5 , 0x06 ) ;
F_20 ( 5 ) ;
V_31 = ( F_19 ( V_5 ) & 0x20 ) ? 0 : 1 ;
F_20 ( 5 ) ;
F_18 ( V_5 , 0x07 ) ;
F_20 ( 5 ) ;
F_18 ( V_5 , 0x06 ) ;
if ( V_31 ) {
F_14
( L_7 ) ;
F_21 ( V_30 , V_34 ) ;
}
return V_31 ;
}
static inline void F_24 ( unsigned short V_26 )
{
int V_35 ;
V_35 = F_19 ( V_26 ) ;
F_25 ( V_26 , V_35 ) ;
F_25 ( V_26 , V_35 & 0xfe ) ;
}
static inline void F_26 ( T_1 * V_4 )
{
int V_35 , V_36 = V_4 -> V_37 ;
if ( V_36 == 0 )
return;
if ( ( F_27 ( V_36 ) & 0xe0 ) == 0x60 ) {
for ( V_35 = 0 ; V_35 < 100 ; V_35 ++ ) {
if ( F_27 ( V_36 ) & 0x01 )
return;
F_20 ( 5 ) ;
}
F_14 ( L_8 ) ;
}
}
static int F_28 ( unsigned short V_5 , const char * V_16 , int V_38 )
{
int V_35 ;
F_18 ( V_5 , 0x4 ) ;
for ( V_35 = V_38 >> 1 ; V_35 ; V_35 -- ) {
F_23 ( V_5 , * V_16 ++ ) ;
F_18 ( V_5 , 0x5 ) ;
F_23 ( V_5 , * V_16 ++ ) ;
F_18 ( V_5 , 0x0 ) ;
}
F_18 ( V_5 , 0x4 ) ;
return 1 ;
}
static int F_29 ( unsigned short V_5 , char * V_16 , int V_38 )
{
unsigned char V_39 ;
int V_35 ;
F_18 ( V_5 , 0x4 ) ;
for ( V_35 = V_38 ; V_35 ; V_35 -- ) {
F_18 ( V_5 , 0x6 ) ;
V_39 = ( F_19 ( V_5 ) & 0xf0 ) >> 4 ;
F_18 ( V_5 , 0x5 ) ;
* V_16 ++ = ( F_19 ( V_5 ) & 0xf0 ) | V_39 ;
F_18 ( V_5 , 0x4 ) ;
}
return 1 ;
}
static int F_30 ( unsigned short V_5 , char * V_16 , int V_38 )
{
int V_35 ;
F_18 ( V_5 , 0x4 ) ;
for ( V_35 = V_38 ; V_35 ; V_35 -- ) {
F_18 ( V_5 , 0x26 ) ;
* V_16 ++ = F_31 ( V_5 ) ;
F_18 ( V_5 , 0x25 ) ;
}
return 1 ;
}
static int F_32 ( T_1 * V_4 , char * V_16 , int V_38 )
{
unsigned short V_26 = V_4 -> V_5 ;
int V_27 = F_17 ( V_4 ) ;
if ( ( V_27 & 0x18 ) != 0x08 ) {
F_21 ( V_4 , V_34 ) ;
F_14 ( L_9 , V_27 ) ;
return 0 ;
}
switch ( V_4 -> V_18 ) {
case V_40 :
case V_41 :
case V_42 :
F_24 ( V_26 ) ;
F_18 ( V_26 , 0x4 ) ;
#ifdef F_33
if ( ! ( ( ( long ) V_16 | V_38 ) & 0x01 ) )
F_34 ( V_26 + 4 , V_16 , V_38 >> 1 ) ;
#else
if ( ! ( ( ( long ) V_16 | V_38 ) & 0x03 ) )
F_35 ( V_26 + 4 , V_16 , V_38 >> 2 ) ;
#endif
else
F_36 ( V_26 + 4 , V_16 , V_38 ) ;
F_18 ( V_26 , 0xc ) ;
V_27 = ! ( F_19 ( V_26 ) & 0x01 ) ;
F_18 ( V_26 , 0xc ) ;
F_26 ( V_4 ) ;
break;
case V_32 :
case V_33 :
V_27 = F_28 ( V_26 , V_16 , V_38 ) ;
break;
default:
F_14 ( L_10 ) ;
V_27 = 0 ;
}
return V_27 ;
}
static int F_37 ( T_1 * V_4 , char * V_16 , int V_38 )
{
unsigned short V_26 = V_4 -> V_5 ;
int V_27 = F_17 ( V_4 ) ;
if ( ( V_27 & 0x18 ) != 0x18 ) {
F_21 ( V_4 , V_34 ) ;
return 0 ;
}
switch ( V_4 -> V_18 ) {
case V_32 :
V_27 = F_29 ( V_26 , V_16 , V_38 ) ;
F_18 ( V_26 , 0xc ) ;
break;
case V_33 :
V_27 = F_30 ( V_26 , V_16 , V_38 ) ;
F_18 ( V_26 , 0xc ) ;
break;
case V_40 :
case V_41 :
case V_42 :
F_24 ( V_26 ) ;
F_18 ( V_26 , 0x24 ) ;
#ifdef F_33
if ( ! ( ( ( long ) V_16 | V_38 ) & 0x01 ) )
F_38 ( V_26 + 4 , V_16 , V_38 >> 1 ) ;
#else
if ( ! ( ( ( long ) V_16 | V_38 ) & 0x03 ) )
F_39 ( V_26 + 4 , V_16 , V_38 >> 2 ) ;
#endif
else
F_40 ( V_26 + 4 , V_16 , V_38 ) ;
F_18 ( V_26 , 0x2c ) ;
V_27 = ! ( F_19 ( V_26 ) & 0x01 ) ;
F_18 ( V_26 , 0x2c ) ;
F_26 ( V_4 ) ;
break;
default:
F_14 ( L_11 ) ;
V_27 = 0 ;
break;
}
return V_27 ;
}
static int F_41 ( unsigned short V_26 , unsigned char V_43 )
{
unsigned char V_44 , V_45 , V_46 ;
F_18 ( V_26 , 0x0c ) ;
F_20 ( 2 ) ;
F_23 ( V_26 , 0xaa ) ;
F_20 ( 10 ) ;
F_23 ( V_26 , 0x55 ) ;
F_20 ( 10 ) ;
F_23 ( V_26 , 0x00 ) ;
F_20 ( 10 ) ;
F_23 ( V_26 , 0xff ) ;
F_20 ( 10 ) ;
V_44 = F_19 ( V_26 ) & 0xb8 ;
F_23 ( V_26 , 0x87 ) ;
F_20 ( 10 ) ;
V_45 = F_19 ( V_26 ) & 0xb8 ;
F_23 ( V_26 , 0x78 ) ;
F_20 ( 10 ) ;
V_46 = F_19 ( V_26 ) & 0x38 ;
F_23 ( V_26 , V_43 ) ;
F_20 ( 2 ) ;
F_18 ( V_26 , 0x0c ) ;
F_20 ( 10 ) ;
F_18 ( V_26 , 0x0d ) ;
F_20 ( 2 ) ;
F_18 ( V_26 , 0x0c ) ;
F_20 ( 10 ) ;
F_23 ( V_26 , 0xff ) ;
F_20 ( 10 ) ;
if ( ( V_44 == 0xb8 ) && ( V_45 == 0x18 ) && ( V_46 == 0x30 ) )
return 1 ;
if ( ( V_44 == 0xb8 ) && ( V_45 == 0x18 ) && ( V_46 == 0x38 ) )
return 0 ;
return - 1 ;
}
static inline int F_42 ( T_1 * V_4 , int V_47 )
{
unsigned short V_26 = V_4 -> V_5 ;
F_41 ( V_26 , 0xe0 ) ;
F_41 ( V_26 , 0x30 ) ;
if ( ( V_4 -> V_18 == V_42 ) ||
( V_4 -> V_18 == V_41 ) ||
( V_4 -> V_18 == V_40 ) )
return F_41 ( V_26 , 0x28 ) ;
return F_41 ( V_26 , 0xe0 ) ;
}
static void F_43 ( T_1 * V_4 )
{
F_41 ( V_4 -> V_5 , 0x30 ) ;
}
static int F_44 ( T_1 * V_4 , int V_48 )
{
int V_25 ;
unsigned short V_26 = V_4 -> V_5 ;
F_18 ( V_26 , 0xc ) ;
V_25 = V_49 ;
do {
V_25 -- ;
} while ( ( F_19 ( V_26 ) & 0x08 ) && ( V_25 ) );
if ( ! V_25 )
return 0 ;
F_18 ( V_26 , 0x4 ) ;
F_23 ( V_26 , 0x80 | ( 1 << V_48 ) ) ;
F_20 ( 1 ) ;
F_18 ( V_26 , 0xc ) ;
F_18 ( V_26 , 0xd ) ;
V_25 = V_49 ;
do {
V_25 -- ;
}
while ( ! ( F_19 ( V_26 ) & 0x08 ) && ( V_25 ) );
F_18 ( V_26 , 0xc ) ;
return ( V_25 ) ? 1 : 0 ;
}
static int F_45 ( T_1 * V_4 )
{
if ( F_42 ( V_4 , 0 ) != 1 )
return - V_50 ;
F_46 ( V_4 -> V_5 ) ;
F_47 ( 1 ) ;
F_43 ( V_4 ) ;
F_47 ( 1 ) ;
return F_48 ( V_4 ) ;
}
static inline int F_49 ( struct V_51 * V_52 )
{
T_1 * V_4 = F_1 ( V_52 -> V_53 -> V_2 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_52 -> V_54 ; V_25 += 2 )
if ( ! F_32 ( V_4 , & V_52 -> V_55 [ V_25 ] , 2 ) )
return 0 ;
return 1 ;
}
static int F_50 ( struct V_51 * V_52 )
{
T_1 * V_4 = F_1 ( V_52 -> V_53 -> V_2 ) ;
unsigned short V_26 = V_4 -> V_5 ;
unsigned long V_56 = V_57 ;
unsigned char V_27 , V_58 ;
int V_59 , V_60 , V_61 ;
V_58 = V_52 -> V_55 [ 0 ] ;
V_60 = ( ( V_58 == V_62 ) ||
( V_58 == V_63 ) || ( V_58 == V_64 ) || ( V_58 == V_65 ) ) ;
F_18 ( V_26 , 0x0c ) ;
V_27 = ( F_19 ( V_26 ) & 0xb8 ) ;
while ( V_27 != ( unsigned char ) 0xb8 ) {
if ( F_51 ( V_57 , V_56 + 1 ) )
return 0 ;
if ( ( ( V_27 & 0x88 ) != 0x88 ) || ( V_52 -> V_8 . V_66 <= 0 ) ) {
F_21 ( V_4 , V_34 ) ;
return - 1 ;
}
if ( V_4 -> V_67 == 0 ) {
V_59 = ( V_60
&& ( V_52 -> V_8 . V_66 >=
V_68 ) ) ? V_68 : 2 ;
V_61 = F_32 ( V_4 , V_52 -> V_8 . V_69 , V_59 ) ;
} else {
V_59 = ( V_60
&& ( V_52 -> V_8 . V_66 >=
V_68 ) ) ? V_68 : 1 ;
V_61 = F_37 ( V_4 , V_52 -> V_8 . V_69 , V_59 ) ;
}
V_52 -> V_8 . V_69 += V_59 ;
V_52 -> V_8 . V_66 -= V_59 ;
if ( ! V_61 ) {
F_21 ( V_4 , V_70 ) ;
return - 1 ;
}
if ( V_52 -> V_8 . V_16 && ! V_52 -> V_8 . V_66 ) {
if ( V_52 -> V_8 . V_71 -- ) {
V_52 -> V_8 . V_16 ++ ;
V_52 -> V_8 . V_66 =
V_52 -> V_8 . V_16 -> V_17 ;
V_52 -> V_8 . V_69 = F_52 ( V_52 -> V_8 . V_16 ) ;
if ( V_52 -> V_8 . V_66 & 0x01 )
V_52 -> V_8 . V_66 ++ ;
}
}
F_18 ( V_26 , 0x0c ) ;
V_27 = ( F_19 ( V_26 ) & 0xb8 ) ;
if ( ! ( V_27 & 0x80 ) )
return 0 ;
}
return 1 ;
}
static void F_53 ( struct V_72 * V_73 )
{
T_1 * V_4 = F_54 ( V_73 , T_1 , V_74 . V_73 ) ;
struct V_51 * V_52 = V_4 -> V_7 ;
struct V_1 * V_2 = V_52 -> V_53 -> V_2 ;
unsigned long V_12 ;
if ( F_55 ( V_4 , V_52 ) ) {
F_56 ( & V_4 -> V_74 , 1 ) ;
return;
}
#if V_75 > 0
switch ( ( V_52 -> V_76 >> 16 ) & 0xff ) {
case V_77 :
break;
case V_78 :
F_14 ( L_12 , V_52 -> V_53 -> V_79 ) ;
break;
case V_70 :
F_14 ( L_13 ) ;
break;
case V_29 :
F_14 ( L_14 ) ;
break;
case V_80 :
F_14 ( L_15 ) ;
break;
case V_81 :
F_14 ( L_16 ) ;
break;
case V_34 :
F_14 ( L_17 ) ;
break;
case V_82 :
F_14 ( L_18 ) ;
break;
case V_83 :
F_14 ( L_19 ) ;
break;
default:
F_14 ( L_20 ,
( V_52 -> V_76 >> 16 ) & 0xff ) ;
}
#endif
if ( V_52 -> V_8 . V_9 > 1 )
F_43 ( V_4 ) ;
F_9 ( V_4 ) ;
F_5 ( V_2 -> V_84 , V_12 ) ;
V_4 -> V_7 = NULL ;
V_52 -> V_85 ( V_52 ) ;
F_7 ( V_2 -> V_84 , V_12 ) ;
return;
}
static int F_55 ( T_1 * V_4 , struct V_51 * V_52 )
{
unsigned short V_26 = V_4 -> V_5 ;
unsigned char V_39 = 0 , V_86 = 0 ;
int V_87 , V_88 ;
if ( V_4 -> V_89 )
return 0 ;
switch ( V_52 -> V_8 . V_9 ) {
case 0 :
if ( F_51 ( V_57 , V_4 -> V_90 + V_91 ) ) {
F_21 ( V_4 , V_70 ) ;
return 0 ;
}
return 1 ;
case 1 :
F_42 ( V_4 , V_92 ) ;
V_52 -> V_8 . V_9 ++ ;
case 2 :
if ( ! F_44 ( V_4 , F_57 ( V_52 ) ) ) {
F_21 ( V_4 , V_78 ) ;
return 0 ;
}
V_52 -> V_8 . V_9 ++ ;
case 3 :
F_18 ( V_26 , 0x0c ) ;
if ( ! ( F_19 ( V_26 ) & 0x80 ) )
return 1 ;
if ( ! F_49 ( V_52 ) )
return 0 ;
V_52 -> V_8 . V_9 ++ ;
case 4 :
if ( F_58 ( V_52 ) ) {
V_52 -> V_8 . V_16 = F_59 ( V_52 ) ;
V_52 -> V_8 . V_66 = V_52 -> V_8 . V_16 -> V_17 ;
V_52 -> V_8 . V_69 = F_52 ( V_52 -> V_8 . V_16 ) ;
} else {
V_52 -> V_8 . V_16 = NULL ;
V_52 -> V_8 . V_66 = 0 ;
V_52 -> V_8 . V_69 = NULL ;
}
V_52 -> V_8 . V_71 = F_60 ( V_52 ) - 1 ;
V_52 -> V_8 . V_9 ++ ;
if ( V_52 -> V_8 . V_66 & 0x01 )
V_52 -> V_8 . V_66 ++ ;
case 5 :
F_18 ( V_26 , 0x0c ) ;
if ( ! ( F_19 ( V_26 ) & 0x80 ) )
return 1 ;
V_88 = ( F_19 ( V_26 ) & 0xb8 ) ;
V_4 -> V_67 = ( V_88 & 0x10 ) ? 1 : 0 ;
V_4 -> V_93 = ( V_88 & 0x20 ) ? 0 : 1 ;
if ( ( V_4 -> V_93 ) && ( V_4 -> V_67 ) )
if ( F_22 ( V_4 ) )
return 0 ;
V_52 -> V_8 . V_9 ++ ;
case 6 :
F_18 ( V_26 , 0x0c ) ;
if ( ! ( F_19 ( V_26 ) & 0x80 ) )
return 1 ;
if ( V_4 -> V_93 ) {
V_87 = F_50 ( V_52 ) ;
if ( V_87 == - 1 )
return 0 ;
if ( V_87 == 0 )
return 1 ;
}
V_52 -> V_8 . V_9 ++ ;
case 7 :
if ( ( V_4 -> V_93 ) && ( V_4 -> V_67 ) ) {
if ( ( V_4 -> V_18 == V_32 ) || ( V_4 -> V_18 == V_33 ) ) {
F_18 ( V_26 , 0x4 ) ;
F_18 ( V_26 , 0xc ) ;
F_18 ( V_26 , 0xe ) ;
F_18 ( V_26 , 0x4 ) ;
}
}
V_52 -> V_8 . V_9 ++ ;
case 8 :
if ( F_17 ( V_4 ) != ( unsigned char ) 0xb8 ) {
F_21 ( V_4 , V_34 ) ;
return 0 ;
}
if ( F_22 ( V_4 ) )
return 0 ;
if ( F_37 ( V_4 , & V_39 , 1 ) ) {
if ( F_17 ( V_4 ) == ( unsigned char ) 0xb8 )
F_37 ( V_4 , & V_86 , 1 ) ;
V_52 -> V_76 = ( V_77 << 16 ) + ( V_39 & V_94 ) ;
}
if ( ( V_4 -> V_18 == V_32 ) || ( V_4 -> V_18 == V_33 ) ) {
F_18 ( V_26 , 0x4 ) ;
F_18 ( V_26 , 0xc ) ;
F_18 ( V_26 , 0xe ) ;
F_18 ( V_26 , 0x4 ) ;
}
return 0 ;
break;
default:
F_14 ( L_21 ) ;
}
return 0 ;
}
static int F_61 ( struct V_51 * V_52 ,
void (* F_62)( struct V_51 * ) )
{
T_1 * V_4 = F_1 ( V_52 -> V_53 -> V_2 ) ;
if ( V_4 -> V_7 ) {
F_14 ( L_22 ) ;
return 0 ;
}
V_4 -> V_89 = 0 ;
V_4 -> V_90 = V_57 ;
V_4 -> V_7 = V_52 ;
V_52 -> V_85 = F_62 ;
V_52 -> V_76 = V_34 << 16 ;
V_52 -> V_8 . V_9 = 0 ;
F_56 ( & V_4 -> V_74 , 0 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
int F_63 ( struct V_51 * V_52 )
{
T_1 * V_4 = F_1 ( V_52 -> V_53 -> V_2 ) ;
switch ( V_52 -> V_8 . V_9 ) {
case 0 :
case 1 :
V_4 -> V_7 = NULL ;
return V_95 ;
break;
default:
return V_96 ;
break;
}
}
static void F_46 ( unsigned int V_5 )
{
F_18 ( V_5 , 0x04 ) ;
F_23 ( V_5 , 0x40 ) ;
F_20 ( 1 ) ;
F_18 ( V_5 , 0x0c ) ;
F_18 ( V_5 , 0x0d ) ;
F_20 ( 50 ) ;
F_18 ( V_5 , 0x0c ) ;
F_18 ( V_5 , 0x04 ) ;
}
static int F_64 ( struct V_51 * V_52 )
{
T_1 * V_4 = F_1 ( V_52 -> V_53 -> V_2 ) ;
if ( V_52 -> V_8 . V_9 )
F_43 ( V_4 ) ;
V_4 -> V_7 = NULL ;
F_42 ( V_4 , V_97 ) ;
F_46 ( V_4 -> V_5 ) ;
F_47 ( 1 ) ;
F_43 ( V_4 ) ;
F_47 ( 1 ) ;
return V_95 ;
}
static int F_48 ( T_1 * V_4 )
{
static char V_52 [ 6 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
int V_98 , V_99 , V_61 , V_25 , V_26 = V_4 -> V_5 ;
unsigned char V_39 ;
V_99 = V_4 -> V_18 ;
for ( V_98 = 0 ; V_98 < 8 ; V_98 ++ ) {
if ( ( V_26 & 0x0007 ) == 0x0000 )
V_4 -> V_18 = V_40 ;
V_100:
F_42 ( V_4 , V_92 ) ;
if ( ! F_44 ( V_4 , V_98 ) ) {
F_43 ( V_4 ) ;
continue;
}
F_14 ( L_23 ,
V_98 , V_24 [ V_4 -> V_18 ] ) ;
V_61 = 1 ;
F_18 ( V_26 , 0x0c ) ;
for ( V_39 = 0 ; ( V_39 < 3 ) && ( V_61 ) ; V_39 ++ )
V_61 = F_32 ( V_4 , & V_52 [ V_39 << 1 ] , 2 ) ;
if ( ! V_61 ) {
F_43 ( V_4 ) ;
F_42 ( V_4 , V_92 ) ;
F_46 ( V_4 -> V_5 ) ;
F_20 ( 1000 ) ;
F_43 ( V_4 ) ;
F_20 ( 1000 ) ;
if ( V_4 -> V_18 == V_40 ) {
V_4 -> V_18 = V_99 ;
goto V_100;
}
F_14 ( L_24 ) ;
return - V_50 ;
}
F_18 ( V_26 , 0x0c ) ;
V_25 = 1000000 ;
do {
V_39 = F_19 ( V_26 ) ;
V_25 -- ;
F_20 ( 1 ) ;
} while ( ! ( V_39 & 0x80 ) && ( V_25 ) );
V_39 &= 0xb8 ;
if ( V_39 != 0xb8 ) {
F_43 ( V_4 ) ;
F_42 ( V_4 , V_92 ) ;
F_46 ( V_4 -> V_5 ) ;
F_20 ( 1000 ) ;
F_43 ( V_4 ) ;
F_20 ( 1000 ) ;
if ( V_4 -> V_18 == V_40 ) {
V_4 -> V_18 = V_99 ;
goto V_100;
}
F_14
( L_24 ) ;
return - V_50 ;
}
F_43 ( V_4 ) ;
F_14
( L_25 ,
V_26 , V_98 , V_24 [ V_4 -> V_18 ] ) ;
F_42 ( V_4 , V_92 ) ;
F_46 ( V_4 -> V_5 ) ;
F_20 ( 1000 ) ;
F_43 ( V_4 ) ;
F_20 ( 1000 ) ;
return 0 ;
}
F_14 ( L_26 ) ;
return - V_101 ;
}
static int F_65 ( struct V_102 * V_53 )
{
F_66 ( V_53 -> V_103 , V_104 ) ;
return 0 ;
}
static inline T_1 * F_67 ( void )
{
T_1 * V_4 , * V_105 = NULL ;
unsigned int V_106 = 0 ;
if ( F_68 ( & V_107 ) )
return NULL ;
F_69 (dev, &imm_hosts, list) {
if ( V_4 -> V_108 != V_106 )
return V_105 ;
V_106 ++ ;
V_105 = V_4 ;
}
return V_105 ;
}
static int F_70 ( struct V_109 * V_110 )
{
struct V_1 * V_2 ;
T_1 * V_4 , * V_111 ;
F_71 ( V_10 ) ;
F_72 ( V_112 ) ;
int V_113 ;
int V_114 , V_26 ;
int V_115 = - V_116 ;
struct V_117 V_118 ;
F_73 ( & V_10 ) ;
V_4 = F_74 ( sizeof( T_1 ) , V_119 ) ;
if ( ! V_4 )
return - V_116 ;
V_4 -> V_5 = - 1 ;
V_4 -> V_18 = V_120 ;
F_75 ( & V_4 -> V_121 ) ;
V_111 = F_67 () ;
if ( V_111 )
V_4 -> V_108 = V_111 -> V_108 + 1 ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_122 = V_4 ;
V_118 . V_123 = F_4 ;
V_4 -> V_4 = F_76 ( V_110 , L_27 , & V_118 , V_4 -> V_108 ) ;
if ( ! V_4 -> V_4 )
goto V_124;
V_115 = - V_125 ;
V_4 -> V_10 = & V_10 ;
F_77 ( & V_10 , & V_112 , V_126 ) ;
if ( F_8 ( V_4 ) )
F_78 ( 3 * V_91 ) ;
if ( V_4 -> V_14 ) {
F_14 ( V_127 L_28
L_29
L_30 , V_110 -> V_128 ) ;
F_9 ( V_4 ) ;
V_4 -> V_10 = NULL ;
F_79 ( & V_10 , & V_112 ) ;
goto V_129;
}
V_4 -> V_10 = NULL ;
F_79 ( & V_10 , & V_112 ) ;
V_26 = V_4 -> V_5 = V_4 -> V_4 -> V_6 -> V_5 ;
V_4 -> V_37 = V_4 -> V_4 -> V_6 -> V_37 ;
F_18 ( V_26 , 0x0c ) ;
V_114 = V_4 -> V_4 -> V_6 -> V_114 ;
V_4 -> V_18 = V_32 ;
if ( V_114 & V_130 )
V_4 -> V_18 = V_33 ;
V_115 = F_45 ( V_4 ) ;
F_11 ( V_4 ) ;
if ( V_115 )
goto V_129;
if ( V_4 -> V_18 == V_32 || V_4 -> V_18 == V_33 )
V_113 = 3 ;
else
V_113 = 8 ;
F_80 ( & V_4 -> V_74 , F_53 ) ;
V_115 = - V_116 ;
V_2 = F_81 ( & V_131 , sizeof( T_1 * ) ) ;
if ( ! V_2 )
goto V_129;
V_2 -> V_132 = V_110 -> V_5 ;
V_2 -> V_133 = V_113 ;
V_2 -> V_134 = - 1 ;
V_2 -> V_135 = V_110 -> V_128 ;
* ( T_1 * * ) & V_2 -> V_3 = V_4 ;
V_4 -> V_2 = V_2 ;
if ( ! V_111 )
F_82 ( & V_4 -> V_121 , & V_107 ) ;
else
F_82 ( & V_4 -> V_121 , & V_111 -> V_121 ) ;
V_115 = F_83 ( V_2 , NULL ) ;
if ( V_115 )
goto V_136;
F_84 ( V_2 ) ;
return 0 ;
V_136:
F_85 ( & V_4 -> V_121 ) ;
F_86 ( V_2 ) ;
V_129:
F_87 ( V_4 -> V_4 ) ;
V_124:
F_88 ( V_4 ) ;
return V_115 ;
}
static void F_89 ( struct V_109 * V_110 )
{
F_70 ( V_110 ) ;
}
static void F_90 ( struct V_109 * V_110 )
{
T_1 * V_4 ;
F_69 (dev, &imm_hosts, list) {
if ( V_4 -> V_4 -> V_6 == V_110 ) {
F_85 ( & V_4 -> V_121 ) ;
F_91 ( V_4 -> V_2 ) ;
F_86 ( V_4 -> V_2 ) ;
F_87 ( V_4 -> V_4 ) ;
F_88 ( V_4 ) ;
break;
}
}
}
static int T_2 F_92 ( void )
{
F_14 ( L_31 , V_22 ) ;
return F_93 ( & V_137 ) ;
}
static void T_3 F_94 ( void )
{
F_95 ( & V_137 ) ;
}
