static void F_1 ( unsigned int V_1 , unsigned char V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( V_2 , V_5 ) ;
F_3 ( V_1 , V_6 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_5 ( unsigned int V_1 , unsigned char V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( V_2 , V_5 ) ; F_3 ( V_1 >> 8 , V_6 ) ;
F_3 ( V_2 + 1 , V_5 ) ; F_3 ( V_1 & 0xff , V_6 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static int F_6 ( unsigned char V_1 , unsigned char V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( V_2 , V_5 ) ;
F_7 ( V_1 , V_6 ) ;
F_8 ( 20 ) ; V_1 = ( F_9 ( V_6 ) == V_1 ) ;
F_4 ( & V_4 , V_3 ) ;
return V_1 ;
}
static inline void F_10 ( unsigned int V_7 )
{
if ( V_8 == V_7 )
return;
F_5 ( V_7 >> 1 , 0x0e ) ;
V_8 = V_7 ;
}
static inline void F_11 ( int V_9 , int V_10 )
{
if ( V_11 == V_9 && V_12 == V_10 )
return;
if ( V_9 > V_10 ) {
F_1 ( V_13 , 0x0a ) ;
} else {
F_1 ( V_9 , 0x0a ) ;
F_1 ( V_10 , 0x0b ) ;
}
V_11 = V_9 ;
V_12 = V_10 ;
}
static int T_1 F_12 ( char * V_14 )
{
int V_15 [ 3 ] ;
V_14 = F_13 ( V_14 , F_14 ( V_15 ) , V_15 ) ;
if ( V_15 [ 0 ] < 2 )
return 0 ;
if ( V_15 [ 1 ] < 1 || V_15 [ 1 ] > V_16 ||
V_15 [ 2 ] < 1 || V_15 [ 2 ] > V_16 )
return 0 ;
V_17 = V_15 [ 1 ] ;
V_18 = V_15 [ 2 ] ;
return 1 ;
}
static int F_15 ( void )
{
int V_19 = 0 ;
T_2 * V_20 , V_21 ;
T_2 * V_22 , V_23 ;
V_20 = ( T_2 * ) V_24 ;
V_22 = ( T_2 * ) ( V_24 + 0x01000 ) ;
V_21 = F_16 ( V_20 ) ; V_23 = F_16 ( V_22 ) ;
F_17 ( 0xAA55 , V_20 ) ; if ( F_16 ( V_20 ) == 0xAA55 ) V_19 ++ ;
F_17 ( 0x55AA , V_20 ) ; if ( F_16 ( V_20 ) == 0x55AA ) V_19 ++ ;
F_17 ( V_21 , V_20 ) ;
if ( V_19 != 2 ) {
return 0 ;
}
F_17 ( 0xA55A , V_22 ) ; F_17 ( 0x0000 , V_20 ) ;
if ( F_16 ( V_22 ) == 0xA55A ) V_19 ++ ;
F_17 ( 0x5AA5 , V_22 ) ; F_17 ( 0x0000 , V_20 ) ;
if ( F_16 ( V_22 ) == 0x5AA5 ) V_19 ++ ;
F_17 ( V_21 , V_20 ) ; F_17 ( V_23 , V_22 ) ;
if ( V_19 == 4 ) {
V_25 = 0x02000 ;
}
#ifdef F_18
if ( ! F_6 ( 0x66 , 0x0f ) ) {
return 0 ;
}
if ( ! F_6 ( 0x99 , 0x0f ) ) {
return 0 ;
}
#endif
V_21 = V_23 = F_9 ( V_26 ) & V_27 ;
for ( V_19 = 0 ; V_19 < 50000 && V_21 == V_23 ; V_19 ++ ) {
V_23 = F_19 ( V_26 ) & V_27 ;
F_8 ( 2 ) ;
}
if ( V_21 != V_23 ) {
switch ( F_9 ( V_26 ) & 0x70 ) {
case 0x10 :
V_28 = V_29 ;
V_30 = L_1 ;
break;
case 0x50 :
V_28 = V_31 ;
V_30 = L_2 ;
break;
default:
V_28 = V_32 ;
V_30 = L_3 ;
break;
}
}
return 1 ;
}
static void F_20 ( void )
{
F_1 ( 97 , 0x00 ) ;
F_1 ( 80 , 0x01 ) ;
F_1 ( 82 , 0x02 ) ;
F_1 ( 15 , 0x03 ) ;
F_1 ( 25 , 0x04 ) ;
F_1 ( 6 , 0x05 ) ;
F_1 ( 25 , 0x06 ) ;
F_1 ( 25 , 0x07 ) ;
F_1 ( 2 , 0x08 ) ;
F_1 ( 13 , 0x09 ) ;
F_1 ( 12 , 0x0a ) ;
F_1 ( 13 , 0x0b ) ;
F_5 ( 0x0000 , 0x0c ) ;
F_5 ( 0x0000 , 0x0e ) ;
F_3 ( V_33 | V_34 , V_35 ) ;
F_3 ( 0x00 , V_26 ) ;
F_3 ( 0x00 , V_36 ) ;
}
static const char * F_21 ( void )
{
V_37 = 80 ;
V_38 = 25 ;
V_25 = 0x01000 ;
V_24 = F_22 ( 0xb0000 , V_25 ) ;
V_5 = 0x3b4 ;
V_6 = 0x3b5 ;
V_35 = 0x3b8 ;
V_26 = 0x3ba ;
V_36 = 0x3bf ;
V_28 = V_39 ;
V_30 = L_4 ;
if ( ! F_15 () ) {
F_23 ( L_5 ) ;
return NULL ;
}
if ( V_28 != V_39 ) {
F_20 () ;
}
F_10 ( V_25 - 1 ) ;
F_23 ( L_6 ,
V_30 , V_25 / 1024 ) ;
return L_7 ;
}
static void F_24 ( struct V_40 * V_41 , int V_42 )
{
V_41 -> V_43 = 0x0800 ;
V_41 -> V_44 = & V_45 ;
if ( V_42 ) {
V_41 -> V_46 = V_37 ;
V_41 -> V_47 = V_38 ;
} else
F_25 ( V_41 , V_37 , V_38 ) ;
if ( V_45 == NULL )
V_45 = V_41 ;
}
static void F_26 ( struct V_40 * V_41 )
{
if ( V_45 == V_41 )
V_45 = NULL ;
}
static inline T_2 F_27 ( T_2 V_48 )
{
T_2 V_49 = 0x0700 ;
if ( V_48 & 0x0800 ) V_49 = 0x7000 ;
else if ( V_48 & 0x0400 ) V_49 = 0x0100 ;
return ( ( V_48 & 0x0200 ) << 2 ) |
( V_48 & 0x8000 ) |
( V_48 & 0x00ff ) | V_49 ;
}
static T_3 F_28 ( struct V_40 * V_41 , T_3 V_50 , T_3 V_51 ,
T_3 V_52 , T_3 V_53 , T_3 V_54 , T_3 V_55 )
{
return ( V_51 & 3 ) |
( ( V_53 & 1 ) << 2 ) |
( ( V_54 & 1 ) << 3 ) |
( ! ! V_55 << 4 ) |
( ( V_52 & 1 ) << 7 ) ;
}
static void F_29 ( struct V_40 * V_41 , T_2 * V_20 , int V_19 )
{
for (; V_19 > 0 ; V_19 -- ) {
F_17 ( F_16 ( V_20 ) ^ 0x0800 , V_20 ) ;
V_20 ++ ;
}
}
static void F_30 ( struct V_40 * V_41 , int V_48 , int V_56 , int V_57 )
{
F_17 ( F_27 ( V_48 ) , F_31 ( V_57 , V_56 ) ) ;
}
static void F_32 ( struct V_40 * V_41 , const unsigned short * V_58 ,
int V_19 , int V_56 , int V_57 )
{
T_2 * V_59 = F_31 ( V_57 , V_56 ) ;
for (; V_19 > 0 ; V_19 -- ) {
F_17 ( F_27 ( F_16 ( V_58 ++ ) ) , V_59 ++ ) ;
}
}
static void F_33 ( struct V_40 * V_41 , int V_56 , int V_57 ,
int V_60 , int V_61 )
{
T_2 * V_59 = F_31 ( V_57 , V_56 ) ;
T_2 V_62 = F_27 ( V_41 -> V_63 ) ;
if ( V_61 <= 0 || V_60 <= 0 )
return;
if ( V_57 == 0 && V_61 == V_37 ) {
F_34 ( V_59 , V_62 , V_60 * V_61 * 2 ) ;
} else {
for (; V_60 > 0 ; V_60 -- , V_59 += V_37 )
F_34 ( V_59 , V_62 , V_61 * 2 ) ;
}
}
static void F_35 ( struct V_40 * V_41 , int V_64 , int V_65 ,
int V_66 , int V_67 , int V_60 , int V_61 )
{
T_2 * V_68 , * V_59 ;
if ( V_61 <= 0 || V_60 <= 0 )
return;
if ( V_65 == 0 && V_67 == 0 && V_61 == V_37 ) {
F_36 ( F_31 ( 0 , V_66 ) , F_31 ( 0 , V_64 ) , V_60 * V_61 * 2 ) ;
} else if ( V_66 < V_64 || ( V_66 == V_64 && V_67 < V_65 ) ) {
V_68 = F_31 ( V_65 , V_64 ) ;
V_59 = F_31 ( V_67 , V_66 ) ;
for (; V_60 > 0 ; V_60 -- ) {
F_36 ( V_59 , V_68 , V_61 * 2 ) ;
V_68 += V_37 ;
V_59 += V_37 ;
}
} else {
V_68 = F_31 ( V_65 , V_64 + V_60 - 1 ) ;
V_59 = F_31 ( V_67 , V_66 + V_60 - 1 ) ;
for (; V_60 > 0 ; V_60 -- ) {
F_36 ( V_59 , V_68 , V_61 * 2 ) ;
V_68 -= V_37 ;
V_59 -= V_37 ;
}
}
}
static int F_37 ( struct V_40 * V_41 )
{
return 1 ;
}
static int F_38 ( struct V_40 * V_41 , const unsigned char * V_69 )
{
return - V_70 ;
}
static int F_39 ( struct V_40 * V_41 , int V_71 , int V_72 )
{
if ( V_28 == V_39 ) {
if ( V_71 )
F_34 ( ( void * ) V_24 ,
F_27 ( V_41 -> V_63 ) ,
V_41 -> V_73 ) ;
return 1 ;
} else {
if ( V_71 )
F_3 ( 0x00 , V_35 ) ;
else
F_3 ( V_33 | V_34 ,
V_35 ) ;
return 0 ;
}
}
static int F_40 ( struct V_40 * V_41 , int V_74 )
{
return 0 ;
}
static void F_41 ( struct V_40 * V_41 , int V_75 )
{
if ( V_75 == V_76 ) {
F_10 ( V_25 - 1 ) ;
return;
}
F_10 ( V_41 -> V_77 * V_37 * 2 + V_41 -> V_78 * 2 ) ;
switch ( V_41 -> V_79 & 0x0f ) {
case V_80 : F_11 ( 10 , 13 ) ; break;
case V_81 : F_11 ( 7 , 13 ) ; break;
case V_82 : F_11 ( 4 , 13 ) ; break;
case V_83 : F_11 ( 1 , 13 ) ; break;
case V_84 : F_11 ( 14 , 13 ) ; break;
default: F_11 ( 12 , 13 ) ; break;
}
}
static int F_42 ( struct V_40 * V_41 , int V_85 , int V_86 , int V_87 , int V_74 )
{
T_2 V_62 = F_27 ( V_41 -> V_63 ) ;
if ( ! V_74 )
return 0 ;
if ( V_74 > V_41 -> V_47 )
V_74 = V_41 -> V_47 ;
switch ( V_87 ) {
case V_88 :
F_36 ( F_31 ( 0 , V_85 ) , F_31 ( 0 , V_85 + V_74 ) ,
( V_86 - V_85 - V_74 ) * V_37 * 2 ) ;
F_34 ( F_31 ( 0 , V_86 - V_74 ) , V_62 ,
V_74 * V_37 * 2 ) ;
break;
case V_89 :
F_36 ( F_31 ( 0 , V_85 + V_74 ) , F_31 ( 0 , V_85 ) ,
( V_86 - V_85 - V_74 ) * V_37 * 2 ) ;
F_34 ( F_31 ( 0 , V_85 ) , V_62 , V_74 * V_37 * 2 ) ;
break;
}
return 0 ;
}
int T_1 F_43 ( void )
{
int V_90 ;
if ( V_17 > V_18 )
return 1 ;
F_44 () ;
V_90 = F_45 ( & V_91 , V_17 - 1 , V_18 - 1 , 0 ) ;
F_46 () ;
return V_90 ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_91 ) ;
}
