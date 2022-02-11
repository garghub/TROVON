void F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ;
F_2 ( L_1 ) ;
F_3 ( V_9 ) ;
V_3 = ( V_2 -> V_10 ) >> 32 ;
V_4 = ( V_2 -> V_10 ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 18 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 18 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 15 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 15 ] ) & 0xffffffff ;
F_2 ( L_2 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_11 ) >> 32 ;
V_4 = ( V_2 -> V_11 ) & 0xffffffff ;
asm volatile ("getcon " __TEA ", %0" : "=r" (bh));
asm volatile ("getcon " __TEA ", %0" : "=r" (bl));
V_5 = ( V_5 ) >> 32 ;
V_6 = ( V_6 ) & 0xffffffff ;
asm volatile ("getcon " __KCR0 ", %0" : "=r" (ch));
asm volatile ("getcon " __KCR0 ", %0" : "=r" (cl));
V_7 = ( V_7 ) >> 32 ;
V_8 = ( V_8 ) & 0xffffffff ;
F_2 ( L_3 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 0 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 0 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 1 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 1 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 2 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 2 ] ) & 0xffffffff ;
F_2 ( L_4 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 3 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 3 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 4 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 4 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 5 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 5 ] ) & 0xffffffff ;
F_2 ( L_5 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 6 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 6 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 7 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 7 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 8 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 8 ] ) & 0xffffffff ;
F_2 ( L_6 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 9 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 9 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 10 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 10 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 11 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 11 ] ) & 0xffffffff ;
F_2 ( L_7 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 12 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 12 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 13 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 13 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 14 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 14 ] ) & 0xffffffff ;
F_2 ( L_8 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 16 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 16 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 17 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 17 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 19 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 19 ] ) & 0xffffffff ;
F_2 ( L_9 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 20 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 20 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 21 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 21 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 22 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 22 ] ) & 0xffffffff ;
F_2 ( L_10 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 23 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 23 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 24 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 24 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 25 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 25 ] ) & 0xffffffff ;
F_2 ( L_11 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 26 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 26 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 27 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 27 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 28 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 28 ] ) & 0xffffffff ;
F_2 ( L_12 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 29 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 29 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 30 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 30 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 31 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 31 ] ) & 0xffffffff ;
F_2 ( L_13 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 32 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 32 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 33 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 33 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 34 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 34 ] ) & 0xffffffff ;
F_2 ( L_14 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 35 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 35 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 36 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 36 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 37 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 37 ] ) & 0xffffffff ;
F_2 ( L_15 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 38 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 38 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 39 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 39 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 40 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 40 ] ) & 0xffffffff ;
F_2 ( L_16 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 41 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 41 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 42 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 42 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 43 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 43 ] ) & 0xffffffff ;
F_2 ( L_17 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 44 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 44 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 45 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 45 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 46 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 46 ] ) & 0xffffffff ;
F_2 ( L_18 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 47 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 47 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 48 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 48 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 49 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 49 ] ) & 0xffffffff ;
F_2 ( L_19 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 50 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 50 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 51 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 51 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 52 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 52 ] ) & 0xffffffff ;
F_2 ( L_20 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 53 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 53 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 54 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 54 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 55 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 55 ] ) & 0xffffffff ;
F_2 ( L_21 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 56 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 56 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 57 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 57 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 58 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 58 ] ) & 0xffffffff ;
F_2 ( L_22 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 59 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 59 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_2 [ 60 ] ) >> 32 ;
V_6 = ( V_2 -> V_2 [ 60 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_2 [ 61 ] ) >> 32 ;
V_8 = ( V_2 -> V_2 [ 61 ] ) & 0xffffffff ;
F_2 ( L_23 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_2 [ 62 ] ) >> 32 ;
V_4 = ( V_2 -> V_2 [ 62 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_12 [ 0 ] ) >> 32 ;
V_6 = ( V_2 -> V_12 [ 0 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_12 [ 1 ] ) >> 32 ;
V_8 = ( V_2 -> V_12 [ 1 ] ) & 0xffffffff ;
F_2 ( L_24 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_12 [ 2 ] ) >> 32 ;
V_4 = ( V_2 -> V_12 [ 2 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_12 [ 3 ] ) >> 32 ;
V_6 = ( V_2 -> V_12 [ 3 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_12 [ 4 ] ) >> 32 ;
V_8 = ( V_2 -> V_12 [ 4 ] ) & 0xffffffff ;
F_2 ( L_25 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
V_3 = ( V_2 -> V_12 [ 5 ] ) >> 32 ;
V_4 = ( V_2 -> V_12 [ 5 ] ) & 0xffffffff ;
V_5 = ( V_2 -> V_12 [ 6 ] ) >> 32 ;
V_6 = ( V_2 -> V_12 [ 6 ] ) & 0xffffffff ;
V_7 = ( V_2 -> V_12 [ 7 ] ) >> 32 ;
V_8 = ( V_2 -> V_12 [ 7 ] ) & 0xffffffff ;
F_2 ( L_26 ,
V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
if ( ! F_4 ( V_2 ) ) {
void V_13 ( struct V_14 * V_15 , unsigned long * V_16 ) ;
unsigned long V_16 = V_2 -> V_2 [ 15 ] & 0xffffffff ;
struct V_14 * V_15 = F_5 () ;
V_15 -> V_17 . V_18 = V_2 ;
V_13 ( V_15 , ( unsigned long * ) V_16 ) ;
}
}
void F_6 ( struct V_14 * V_15 )
{
#ifdef F_7
if ( V_19 == V_15 )
V_19 = NULL ;
#endif
}
void F_8 ( void )
{
#ifdef F_7
if ( V_19 == V_20 ) {
V_19 = NULL ;
}
F_9 () ;
#endif
if( V_20 -> V_17 . V_18 == & V_21 ) {
V_20 -> V_17 . V_18 =
( (struct V_1 * ) ( V_22 + ( unsigned long ) V_20 ) - 1 ) ;
V_20 -> V_17 . V_23 = V_20 -> V_17 . V_18 ;
}
}
void F_10 ( struct V_14 * V_24 )
{
}
int F_11 ( struct V_1 * V_2 , T_1 * V_25 )
{
#ifdef F_7
int V_26 ;
struct V_14 * V_15 = V_20 ;
V_26 = ! ! F_12 ( V_15 ) ;
if ( V_26 ) {
if ( V_20 == V_19 ) {
F_13 () ;
F_14 ( V_15 ) ;
F_15 () ;
V_19 = 0 ;
V_2 -> V_11 |= V_27 ;
}
memcpy ( V_25 , & V_15 -> V_17 . V_28 -> V_29 , sizeof( * V_25 ) ) ;
}
return V_26 ;
#else
return 0 ;
#endif
}
int F_16 ( unsigned long V_30 , unsigned long V_31 ,
unsigned long V_32 , struct V_14 * V_33 )
{
struct V_1 * V_34 ;
#ifdef F_7
if ( V_19 == V_20 ) {
F_13 () ;
F_14 ( V_20 ) ;
F_15 () ;
V_19 = NULL ;
F_17 () -> V_11 |= V_27 ;
}
#endif
V_34 = (struct V_1 * ) ( V_22 + F_18 ( V_33 ) ) - 1 ;
V_33 -> V_17 . V_16 = ( unsigned long ) V_34 ;
if ( F_19 ( V_33 -> V_35 & V_36 ) ) {
memset ( V_34 , 0 , sizeof( struct V_1 ) ) ;
V_34 -> V_2 [ 2 ] = ( unsigned long ) V_32 ;
V_34 -> V_2 [ 3 ] = ( unsigned long ) V_31 ;
V_34 -> V_11 = ( 1 << 30 ) ;
V_34 -> V_11 |= V_27 ;
V_33 -> V_17 . V_10 = ( unsigned long ) V_37 ;
return 0 ;
}
* V_34 = * F_17 () ;
if ( V_31 )
V_34 -> V_2 [ 15 ] = F_20 ( V_31 ) ;
V_33 -> V_17 . V_23 = V_34 ;
V_34 -> V_2 [ 9 ] = 0 ;
V_34 -> V_11 |= V_27 ;
V_33 -> V_17 . V_10 = ( unsigned long ) V_38 ;
return 0 ;
}
static int F_21 ( unsigned long V_10 )
{
extern char V_39 ;
return ( V_10 >= ( unsigned long ) V_40 ) &&
( V_10 < ( unsigned long ) & V_39 ) ;
}
unsigned long F_22 ( struct V_14 * V_33 )
{
unsigned long V_10 ;
if ( ! V_33 || V_33 == V_20 || V_33 -> V_41 == V_42 )
return 0 ;
V_10 = F_23 ( V_33 ) ;
#ifdef F_24
if ( F_21 ( V_10 ) ) {
unsigned long V_43 ;
unsigned long V_44 ;
unsigned long V_45 ;
V_44 = ( long ) V_33 -> V_17 . V_16 ;
V_43 = * ( unsigned long * ) ( long ) ( V_44 + 4 ) ;
V_45 = * ( unsigned long * ) ( long ) ( V_43 + 24 ) ;
return V_45 ;
}
#endif
return V_10 ;
}
