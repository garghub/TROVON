static inline void F_1 ( unsigned int V_1 , unsigned char * V_2 )
{
#ifdef F_2
if ( ( V_1 == 1 ) && V_2 [ 0 ] & 0x80 ) {
V_2 [ 1 ] = 0xff ;
V_2 [ 2 ] = 0xff ;
V_2 [ 3 ] = 0xff ;
}
if ( ( V_1 == 2 ) && V_2 [ 1 ] & 0x80 ) {
V_2 [ 2 ] = 0xff ;
V_2 [ 3 ] = 0xff ;
}
#else
if ( ( V_1 == 1 ) && V_2 [ 3 ] & 0x80 ) {
V_2 [ 2 ] = 0xff ;
V_2 [ 1 ] = 0xff ;
V_2 [ 0 ] = 0xff ;
}
if ( ( V_1 == 2 ) && V_2 [ 2 ] & 0x80 ) {
V_2 [ 1 ] = 0xff ;
V_2 [ 0 ] = 0xff ;
}
#endif
}
static int F_3 ( T_1 V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 )
{
int V_8 , V_9 , V_1 ;
unsigned long * V_10 , * V_11 ;
unsigned char * V_12 , * V_2 ;
unsigned char T_2 * V_13 , * V_14 ;
V_9 = ( V_3 >> 8 ) & 15 ;
V_11 = & V_5 -> V_5 [ V_9 ] ;
V_9 = ( V_3 >> 4 ) & 15 ;
V_10 = & V_5 -> V_5 [ V_9 ] ;
V_1 = 1 << ( V_3 & 3 ) ;
switch ( V_1 ) {
case 1 : F_4 () ; break;
case 2 : F_5 () ; break;
case 4 : F_6 () ; break;
case 8 : F_7 () ; break;
}
V_8 = - V_15 ;
switch ( V_3 >> 12 ) {
case 0 :
if ( V_3 & 8 ) {
V_13 = ( unsigned char T_2 * ) * V_10 ;
V_13 += V_5 -> V_5 [ 0 ] ;
V_2 = ( unsigned char * ) V_11 ;
* ( unsigned long * ) V_2 = 0 ;
#if ! F_8 ( F_2 )
V_2 += 4 - V_1 ;
#endif
if ( V_7 -> V_16 ( V_2 , V_13 , V_1 ) )
goto V_17;
F_1 ( V_1 , V_2 ) ;
} else {
V_12 = ( unsigned char * ) V_10 ;
#if ! F_8 ( F_2 )
V_12 += 4 - V_1 ;
#endif
V_14 = ( unsigned char T_2 * ) * V_11 ;
V_14 += V_5 -> V_5 [ 0 ] ;
if ( V_7 -> V_18 ( V_14 , V_12 , V_1 ) )
goto V_17;
}
V_8 = 0 ;
break;
case 1 :
V_12 = ( unsigned char * ) V_10 ;
V_14 = ( unsigned char T_2 * ) * V_11 ;
V_14 += ( V_3 & 0x000F ) << 2 ;
if ( V_7 -> V_18 ( V_14 , V_12 , 4 ) )
goto V_17;
V_8 = 0 ;
break;
case 2 :
if ( V_3 & 4 )
* V_11 -= V_1 ;
V_12 = ( unsigned char * ) V_10 ;
V_14 = ( unsigned char T_2 * ) * V_11 ;
#if ! F_8 ( F_2 )
V_12 += 4 - V_1 ;
#endif
if ( V_7 -> V_18 ( V_14 , V_12 , V_1 ) )
goto V_17;
V_8 = 0 ;
break;
case 5 :
V_13 = ( unsigned char T_2 * ) * V_10 ;
V_13 += ( V_3 & 0x000F ) << 2 ;
V_2 = ( unsigned char * ) V_11 ;
* ( unsigned long * ) V_2 = 0 ;
if ( V_7 -> V_16 ( V_2 , V_13 , 4 ) )
goto V_17;
V_8 = 0 ;
break;
case 6 :
V_13 = ( unsigned char T_2 * ) * V_10 ;
if ( V_3 & 4 )
* V_10 += V_1 ;
V_2 = ( unsigned char * ) V_11 ;
* ( unsigned long * ) V_2 = 0 ;
#if ! F_8 ( F_2 )
V_2 += 4 - V_1 ;
#endif
if ( V_7 -> V_16 ( V_2 , V_13 , V_1 ) )
goto V_17;
F_1 ( V_1 , V_2 ) ;
V_8 = 0 ;
break;
case 8 :
switch ( ( V_3 & 0xFF00 ) >> 8 ) {
case 0x81 :
V_12 = ( unsigned char * ) & V_5 -> V_5 [ 0 ] ;
#if ! F_8 ( F_2 )
V_12 += 2 ;
#endif
V_14 = ( unsigned char T_2 * ) * V_10 ;
V_14 += ( V_3 & 0x000F ) << 1 ;
if ( V_7 -> V_18 ( V_14 , V_12 , 2 ) )
goto V_17;
V_8 = 0 ;
break;
case 0x85 :
V_13 = ( unsigned char T_2 * ) * V_10 ;
V_13 += ( V_3 & 0x000F ) << 1 ;
V_2 = ( unsigned char * ) & V_5 -> V_5 [ 0 ] ;
* ( unsigned long * ) V_2 = 0 ;
#if ! F_8 ( F_2 )
V_2 += 2 ;
#endif
if ( V_7 -> V_16 ( V_2 , V_13 , 2 ) )
goto V_17;
F_1 ( 2 , V_2 ) ;
V_8 = 0 ;
break;
}
break;
case 9 :
V_13 = ( unsigned char T_2 * ) V_5 -> V_19 ;
V_13 += 4 ;
V_13 += ( V_3 & 0x00FF ) << 1 ;
V_2 = ( unsigned char * ) V_11 ;
* ( unsigned long * ) V_2 = 0 ;
#if ! F_8 ( F_2 )
V_2 += 2 ;
#endif
if ( V_7 -> V_16 ( V_2 , V_13 , 2 ) )
goto V_17;
F_1 ( 2 , V_2 ) ;
V_8 = 0 ;
break;
case 0xd :
V_13 = ( unsigned char T_2 * ) ( V_5 -> V_19 & ~ 0x3 ) ;
V_13 += 4 ;
V_13 += ( V_3 & 0x00FF ) << 2 ;
V_2 = ( unsigned char * ) V_11 ;
* ( unsigned long * ) V_2 = 0 ;
if ( V_7 -> V_16 ( V_2 , V_13 , 4 ) )
goto V_17;
V_8 = 0 ;
break;
}
return V_8 ;
V_17:
F_9 ( L_1 , V_5 , 0 ) ;
return - V_15 ;
}
static inline int F_10 ( struct V_4 * V_5 ,
T_1 V_20 ,
struct V_6 * V_7 )
{
T_1 V_3 ;
void T_2 * V_21 = ( void T_2 * ) ( V_5 -> V_19 +
F_11 ( V_20 ) ) ;
if ( F_12 ( & V_3 , V_21 , sizeof( V_3 ) ) ) {
if ( F_13 ( V_5 ) )
return - V_15 ;
F_14 ( L_2 ,
V_5 , 0 ) ;
}
return F_3 ( V_3 , V_5 , V_7 ) ;
}
int F_15 ( T_1 V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 , int V_22 ,
unsigned long V_23 )
{
T_3 V_10 ;
int V_8 , V_9 ;
if ( F_11 ( V_3 ) != 2 )
return - V_24 ;
V_9 = ( V_3 >> 8 ) & 15 ;
V_10 = V_5 -> V_5 [ V_9 ] ;
if ( ! V_22 ) {
F_16 ( V_25 , V_3 , V_5 ) ;
F_17 ( V_26 , 1 ,
V_5 , V_23 ) ;
}
V_8 = - V_15 ;
switch ( V_3 & 0xF000 ) {
case 0x0000 :
if ( V_3 == 0x000B ) {
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 )
V_5 -> V_19 = V_5 -> V_27 ;
}
else if ( ( V_3 & 0x00FF ) == 0x0023 ) {
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 )
V_5 -> V_19 += V_10 + 4 ;
}
else if ( ( V_3 & 0x00FF ) == 0x0003 ) {
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 ) {
V_5 -> V_27 = V_5 -> V_19 + 4 ;
V_5 -> V_19 += V_10 + 4 ;
}
}
else {
goto V_28;
}
break;
case 0x1000 :
goto V_28;
case 0x2000 :
goto V_28;
case 0x4000 :
if ( ( V_3 & 0x00FF ) == 0x002B ) {
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 )
V_5 -> V_19 = V_10 ;
}
else if ( ( V_3 & 0x00FF ) == 0x000B ) {
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 ) {
V_5 -> V_27 = V_5 -> V_19 + 4 ;
V_5 -> V_19 = V_10 ;
}
}
else {
goto V_28;
}
break;
case 0x5000 :
goto V_28;
case 0x6000 :
goto V_28;
case 0x8000 :
switch ( V_3 & 0x0F00 ) {
case 0x0100 :
goto V_28;
case 0x0500 :
goto V_28;
case 0x0B00 :
V_8 = 0 ;
break;
case 0x0F00 :
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 ) {
#if F_8 ( V_29 ) || F_8 ( V_30 )
if ( ( V_5 -> V_31 & 0x00000001 ) != 0 )
V_5 -> V_19 += 4 ;
else
#endif
V_5 -> V_19 += F_18 ( V_3 ) ;
}
break;
case 0x0900 :
V_8 = 0 ;
break;
case 0x0D00 :
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 ) {
#if F_8 ( V_29 ) || F_8 ( V_30 )
if ( ( V_5 -> V_31 & 0x00000001 ) == 0 )
V_5 -> V_19 += 4 ;
else
#endif
V_5 -> V_19 += F_18 ( V_3 ) ;
}
break;
}
break;
case 0x9000 :
goto V_28;
case 0xA000 :
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 )
V_5 -> V_19 += F_19 ( V_3 ) ;
break;
case 0xB000 :
V_8 = F_10 ( V_5 , V_3 , V_7 ) ;
if ( V_8 == 0 ) {
V_5 -> V_27 = V_5 -> V_19 + 4 ;
V_5 -> V_19 += F_19 ( V_3 ) ;
}
break;
case 0xD000 :
goto V_28;
}
return V_8 ;
V_28:
V_8 = F_3 ( V_3 , V_5 , V_7 ) ;
if ( V_8 == 0 )
V_5 -> V_19 += F_11 ( V_3 ) ;
return V_8 ;
}
T_4 void F_20 ( struct V_4 * V_5 ,
unsigned long V_32 ,
unsigned long V_23 )
{
unsigned long V_33 = 0 ;
T_5 V_34 ;
T_6 V_35 ;
T_1 V_3 ;
int V_36 ;
#ifdef F_21
V_33 = F_22 () ;
#endif
V_34 = F_23 () ;
if ( F_13 ( V_5 ) ) {
int V_37 = V_38 ;
unsigned int V_39 ;
F_24 () ;
F_25 () ;
F_26 ( V_40 ) ;
if ( F_12 ( & V_3 , ( T_1 * ) ( V_5 -> V_19 & ~ 1 ) ,
sizeof( V_3 ) ) ) {
F_26 ( V_34 ) ;
goto V_41;
}
F_26 ( V_34 ) ;
F_16 ( V_25 , V_3 , V_5 ) ;
V_39 = F_27 () ;
if ( V_39 & V_42 )
goto V_43;
if ( V_39 & V_44 )
goto V_41;
else {
V_5 -> V_19 += F_11 ( V_3 ) ;
return;
}
V_43:
if ( V_5 -> V_19 & 1 ) {
V_37 = V_45 ;
goto V_41;
}
F_26 ( V_40 ) ;
V_36 = F_15 ( V_3 , V_5 ,
& V_46 , 0 ,
V_23 ) ;
F_26 ( V_34 ) ;
if ( V_36 == 0 )
return;
V_41:
F_28 ( V_47 L_3
L_4 , V_25 -> V_48 , V_5 -> V_19 ,
V_5 -> V_27 ) ;
V_35 . V_49 = V_50 ;
V_35 . V_51 = 0 ;
V_35 . V_37 = V_37 ;
V_35 . V_52 = ( void T_2 * ) V_23 ;
F_29 ( V_50 , & V_35 , V_25 ) ;
} else {
F_30 () ;
if ( V_5 -> V_19 & 1 )
F_14 ( L_5 , V_5 , V_33 ) ;
F_26 ( V_53 ) ;
if ( F_12 ( & V_3 , ( void T_2 * ) ( V_5 -> V_19 ) ,
sizeof( V_3 ) ) ) {
F_26 ( V_34 ) ;
F_14 ( L_6 , V_5 , 0 ) ;
}
F_16 ( V_25 , V_3 , V_5 ) ;
F_15 ( V_3 , V_5 , & V_46 ,
0 , V_23 ) ;
F_26 ( V_34 ) ;
}
}
int F_31 ( struct V_4 * V_5 )
{
unsigned short V_54 = 0 ;
if ( ! ( V_55 . V_56 & V_57 ) || ( V_5 -> V_31 & V_58 ) )
return 0 ;
F_32 ( V_54 , ( ( unsigned short * ) V_5 -> V_19 ) ) ;
V_54 &= 0xf000 ;
if ( ( V_54 == 0xf000 ) || ( V_54 == 0x4000 ) )
return 1 ;
return 0 ;
}
T_4 void F_33 ( unsigned long V_59 )
{
T_6 V_35 ;
switch ( V_59 ) {
case V_60 :
V_35 . V_37 = V_61 ;
break;
case V_62 :
V_35 . V_37 = V_63 ;
break;
}
F_29 ( V_64 , & V_35 , V_25 ) ;
}
T_4 void F_34 ( void )
{
struct V_4 * V_5 = F_35 () ;
unsigned long V_33 ;
struct V_65 * V_66 = V_25 ;
#ifdef F_36
unsigned short V_54 = 0 ;
int V_67 ;
F_32 ( V_54 , ( unsigned short * ) V_5 -> V_19 ) ;
V_67 = F_37 ( V_54 , V_5 ) ;
if ( ! V_67 ) {
V_5 -> V_19 += F_11 ( V_54 ) ;
return;
}
#endif
#ifdef F_38
if ( F_31 ( V_5 ) ) {
V_5 -> V_31 |= V_58 ;
V_66 -> V_68 . V_69 . V_70 |= V_58 ;
return;
}
#endif
V_33 = F_22 () ;
F_24 () ;
F_39 ( V_71 , V_66 ) ;
F_9 ( L_7 , V_5 , V_33 ) ;
}
static int F_40 ( unsigned short V_54 , struct V_4 * V_5 )
{
if ( ( ( V_54 & 0xf000 ) == 0xb000 ) ||
( ( V_54 & 0xf0ff ) == 0x0003 ) ||
( ( V_54 & 0xf0ff ) == 0x400b ) )
V_5 -> V_27 = V_5 -> V_19 + 4 ;
if ( ( V_54 & 0xfd00 ) == 0x8d00 ) {
V_5 -> V_19 += F_18 ( V_54 ) ;
return 0 ;
}
if ( ( V_54 & 0xe000 ) == 0xa000 ) {
V_5 -> V_19 += F_19 ( V_54 ) ;
return 0 ;
}
if ( ( V_54 & 0xf0df ) == 0x0003 ) {
V_5 -> V_19 += V_5 -> V_5 [ ( V_54 & 0x0f00 ) >> 8 ] + 4 ;
return 0 ;
}
if ( ( V_54 & 0xf0df ) == 0x400b ) {
V_5 -> V_19 = V_5 -> V_5 [ ( V_54 & 0x0f00 ) >> 8 ] ;
return 0 ;
}
if ( ( V_54 & 0xffff ) == 0x000b ) {
V_5 -> V_19 = V_5 -> V_27 ;
return 0 ;
}
return 1 ;
}
T_4 void F_41 ( void )
{
struct V_4 * V_5 = F_35 () ;
unsigned long V_54 ;
struct V_65 * V_66 = V_25 ;
if ( F_42 ( V_5 -> V_19 ) == 0 )
return;
#ifdef F_36
F_32 ( V_54 , ( unsigned short * ) V_5 -> V_19 + 1 ) ;
if ( ! F_37 ( V_54 , V_5 ) ) {
F_32 ( V_54 , ( unsigned short * ) V_5 -> V_19 ) ;
if ( ! F_40 ( V_54 , V_5 ) )
return;
}
#endif
V_54 = F_22 () ;
F_24 () ;
F_39 ( V_71 , V_66 ) ;
F_9 ( L_8 , V_5 , V_54 ) ;
}
T_4 void F_43 ( void )
{
long V_72 ;
V_72 = F_22 () ;
F_44 ( L_9 , F_35 () , V_72 ) ;
}
void F_45 ( void )
{
extern void * V_73 ;
asm volatile("ldc %0, vbr"
:
: "r" (&vbr_base)
: "memory");
F_46 () ;
}
void * F_47 ( unsigned int V_74 , void * V_75 )
{
extern void * V_76 [] ;
void * V_77 ;
V_77 = V_76 [ V_74 ] ;
V_76 [ V_74 ] = V_75 ;
return V_77 ;
}
void T_7 F_48 ( void )
{
F_47 ( V_78 , F_34 ) ;
F_47 ( V_79 , F_41 ) ;
#if F_8 ( V_29 ) && ! F_8 ( V_80 ) || \
F_8 ( F_36 )
F_49 ( 0x800 , F_34 ) ;
F_49 ( 0x820 , F_41 ) ;
#elif F_8 ( V_80 )
F_49 ( 0x800 , V_81 ) ;
F_49 ( 0x820 , V_81 ) ;
#endif
#ifdef F_50
F_47 ( V_82 , V_83 ) ;
#endif
#ifdef F_51
F_47 ( V_60 , F_33 ) ;
F_47 ( V_62 , F_33 ) ;
#ifdef V_80
F_47 ( V_84 , V_85 ) ;
#endif
#endif
#ifdef F_52
F_47 ( F_52 , V_86 ) ;
#endif
}
