static inline unsigned long
F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
V_2 = V_3 [ V_1 >> 13 ] ;
V_2 >>= 32 ;
V_2 <<= 13 ;
V_2 |= V_1 & 0x1fff ;
return V_2 ;
}
int
F_2 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_6 , unsigned long V_7 )
{
unsigned long V_8 , V_9 ;
#ifdef F_3
F_4 ( L_1 ,
V_4 , V_5 , V_6 , V_7 ) ;
#endif
for ( V_8 = V_4 ; V_8 <= V_5 ; V_8 += V_10 )
{
V_9 = ( F_1 ( V_8 ) | V_11 ) ;
if ( V_9 >= V_6 && V_9 <= V_7 )
{
#ifdef F_3
F_4 ( L_2
L_3 ,
V_8 , V_9 , V_6 , V_7 ) ;
#endif
return 1 ;
}
}
return 0 ;
}
void
F_5 ( void )
{
unsigned long V_12 , V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_18 -> V_19 = 0 ;
V_18 -> V_20 = 0 ;
V_18 -> V_21 = V_22 [ 1 ] >> 32 ;
V_18 -> V_23 = 0 ;
V_18 -> V_24 = 0 ;
V_18 -> V_25 = 0 ;
V_18 -> V_26 = 1 ;
V_18 -> V_27 = 0 ;
V_18 -> V_28 = 0 ;
V_17 = (struct V_16 * ) F_1 ( ( unsigned long ) V_18 ) ;
F_4 ( L_4 ) ;
V_12 = F_6 ( 2 , V_18 , V_17 , V_3 ) ;
if ( V_12 ) {
F_4 ( L_5 , V_12 ) ;
F_7 () ;
}
V_15 = (struct V_14 * )
( V_29 -> V_30 + ( unsigned long ) V_29 ) ;
V_13 = V_15 -> V_31 = V_15 -> V_32 [ 2 ] ;
F_4 ( L_6 , V_13 ) ;
F_8 () ;
}
static inline void
F_9 ( void )
{
__asm__ __volatile__(
"bis %0,%0,$27\n\t"
"jmp ($27)"
:
: "r" (START_ADDR));
}
void
F_10 ( void )
{
int V_33 = 0 ;
unsigned long V_34 = V_35 ;
unsigned long V_36 = V_37 ;
unsigned long V_38 = V_39 ;
static long V_40 ;
static char V_41 [ 256 ] V_42 ( ( F_11 ( 8 ) ) ) ;
register unsigned long T_1 V_43 ( L_7 ) ;
V_44 = T_1 ;
F_4 ( L_8 V_45 L_9 ) ;
if ( V_29 -> V_46 != 8192 ) {
F_4 ( L_10 ,
V_29 -> V_46 >> 10 ) ;
return;
}
if ( V_29 -> V_47 != ( unsigned long ) V_3 ) {
F_4 ( L_11 ,
V_3 , ( void * ) V_29 -> V_47 ) ;
return;
}
F_5 () ;
V_40 = F_12 ( V_48 , V_41 , sizeof( V_41 ) ) ;
if ( V_40 < 0 || V_40 >= sizeof( V_41 ) ) {
V_40 = 0 ;
}
V_41 [ V_40 ] = '\0' ;
#ifdef F_13
F_4 ( L_12 , V_49 ) ;
F_4 ( L_13 , V_50 ) ;
F_4 ( L_14 , V_51 ) ;
F_4 ( L_15 , V_52 ) ;
#endif
if ( F_2 ( V_53 , V_54 ,
V_55 , V_37 ) )
{
F_4 ( L_16 ) ;
F_7 () ;
}
if ( F_2 ( V_56 , V_57 ,
V_35 , V_58 ) )
{
#ifdef F_13
F_4 ( L_17 ) ;
#endif
V_34 = V_59 ;
V_36 = V_58 ;
V_33 = 1 ;
while ( F_2 ( V_56 , V_57 ,
V_34 ,
V_36 ) )
{
#if 0
uncompressed_image_start += K_COPY_IMAGE_SIZE;
uncompressed_image_end += K_COPY_IMAGE_SIZE;
initrd_image_start += K_COPY_IMAGE_SIZE;
#else
V_34 += V_10 ;
V_36 += V_10 ;
V_38 += V_10 ;
#endif
}
}
F_4 ( L_18 , V_41 ) ;
#ifdef F_13
F_4 ( L_19
L_20 ,
V_56 ,
V_34 ,
V_51 ) ;
#endif
F_14 ( ( void * ) V_34 ,
( void * ) V_56 ,
V_51 , V_52 ) ;
#ifdef F_15
#ifdef F_13
F_4 ( L_21
L_22 ,
V_60 ,
V_38 ,
F_15 ) ;
#endif
memcpy ( ( void * ) V_38 , ( void * ) V_60 ,
F_15 ) ;
#endif
if ( V_33 ) {
#ifdef F_13
F_4 ( L_23
L_20 ,
V_34 ,
V_35 ,
( unsigned ) V_51 ) ;
#endif
F_16 ( V_38 - V_10 ) ;
memcpy ( ( void * ) V_35 ,
( void * ) V_34 , V_51 ) ;
}
#ifdef F_17
F_4 ( L_24 ) ;
#endif
memset ( ( char * ) V_61 , 0 , V_10 ) ;
strcpy ( ( char * ) V_61 , V_41 ) ;
#ifdef F_15
#ifdef F_17
F_4 ( L_25 ) ;
#endif
( ( long * ) ( V_61 + 256 ) ) [ 0 ] = V_38 ;
( ( long * ) ( V_61 + 256 ) ) [ 1 ] = F_15 ;
#endif
#ifdef F_17
F_4 ( L_26 ) ;
#endif
F_9 () ;
}
void * F_18 ( T_2 V_62 , T_3 V_26 )
{
return ( void * ) NULL ;
}
