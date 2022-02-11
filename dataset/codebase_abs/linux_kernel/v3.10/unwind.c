inline long F_1 ( unsigned long V_1 )
{
return abs ( ( V_2 ) ( V_1 & 0xFFFF ) ) ;
}
static unsigned long * F_2 ( unsigned long * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ , V_3 -- ) {
unsigned long V_1 ;
V_2 V_5 ;
if ( ! F_3 ( ( unsigned long ) V_3 ) )
return NULL ;
V_1 = * V_3 ;
if ( ( V_1 & 0xFFFF0000 ) != 0x30210000 )
continue;
V_5 = F_1 ( V_1 ) ;
if ( ( V_5 < 8 ) || ( V_5 & 3 ) ) {
F_4 ( L_1 ,
V_5 , V_3 ) ;
return NULL ;
}
F_4 ( L_2 , V_3 ,
V_5 ) ;
return V_3 ;
}
return NULL ;
}
static int F_5 ( unsigned long V_6 , unsigned long V_3 ,
unsigned long V_7 ,
unsigned long * V_8 ,
unsigned long * V_9 )
{
unsigned long * V_10 = NULL ;
if ( V_3 != ( unsigned long ) & V_11 )
V_10 = F_2 ( ( unsigned long * ) V_3 ) ;
if ( V_10 ) {
long V_5 = F_1 ( * V_10 ) ;
* V_8 = V_6 + V_5 ;
* V_9 = * ( unsigned long * ) V_6 ;
} else {
if ( ! V_7 )
return - V_12 ;
* V_9 = V_7 ;
* V_8 = V_6 ;
}
return ( ! * V_9 || ( * V_9 & 3 ) ) ? - V_12 : 0 ;
}
static inline void F_6 ( struct V_13 * V_14 , unsigned long V_3 ,
unsigned long V_6 , struct V_15 * V_16 )
{
}
static inline void F_6 ( struct V_13 * V_14 , unsigned long V_3 ,
unsigned long V_6 , struct V_15 * V_16 )
{
const struct V_17 * V_18 = ( const struct V_17 * ) V_6 ;
F_7 ( V_14 , V_18 -> V_3 , V_18 -> V_19 , V_18 -> V_20 , V_16 ) ;
}
static void F_7 ( struct V_13 * V_14 ,
unsigned long V_3 , unsigned long V_6 ,
unsigned long V_7 ,
struct V_15 * V_16 )
{
int V_21 = 0 ;
F_4 ( L_3 , ( void * ) V_3 , ( void * ) V_6 ) ;
if ( ! V_3 || ! V_6 || ( V_3 & 3 ) || ( V_6 & 3 ) ) {
F_4 ( L_4 ) ;
return;
}
for (; V_3 != 0 ; ) {
unsigned long V_22 , V_23 = 0 ;
unsigned long V_24 = V_3 + 2 * sizeof( unsigned long ) ;
const struct V_25 * V_26 =
& V_27 ;
if ( ( V_24 >= ( unsigned long ) & V_28 )
&& ( V_24 < ( unsigned long ) & V_29 ) ) {
#ifndef F_8
const struct V_17 * V_18 =
( const struct V_17 * ) V_6 ;
#endif
F_9 ( L_5 ) ;
#ifndef F_8
F_7 ( V_14 , V_18 -> V_30 - 4 ,
V_6 + V_31 ,
V_18 -> V_20 , V_16 ) ;
#endif
return;
}
for (; V_26 -> V_32 ; ++ V_26 ) {
if ( ( V_24 >= V_26 -> V_32 )
&& ( V_24 <= V_26 -> V_33 ) ) {
if ( ! V_16 )
F_9 ( L_6 , V_26 -> V_34 ) ;
F_6 ( V_14 , V_3 , V_6 , V_16 ) ;
return;
}
}
V_3 -= V_21 ;
if ( V_16 ) {
#ifdef F_10
if ( V_16 -> V_35 > 0 )
V_16 -> V_35 -- ;
else
V_16 -> V_36 [ V_16 -> V_37 ++ ] = V_3 ;
if ( V_16 -> V_37 >= V_16 -> V_38 )
break;
#endif
} else {
if ( F_11 ( V_3 == F_12 ( V_14 ) -> V_3 ) ) {
F_9 ( L_7 ,
( void * ) V_3 ,
( unsigned long ) V_14 -> V_39 ,
V_14 -> V_40 ) ;
break;
} else
F_13 ( V_3 ) ;
}
if ( ! F_3 ( V_3 ) )
break;
if ( F_5 ( V_6 , V_3 , V_7 , & V_22 ,
& V_23 ) == 0 ) {
V_21 = sizeof( unsigned long ) ;
V_3 = V_23 & ~ 3 ;
V_6 = V_22 ;
V_7 = 0 ;
} else {
F_4 ( L_8 ) ;
break;
}
F_4 ( L_9 ,
( void * ) V_23 , ( void * ) V_22 ) ;
}
}
void F_14 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
if ( V_14 ) {
if ( V_14 == V_41 ) {
const struct V_17 * V_18 = F_12 ( V_14 ) ;
F_7 ( V_14 , V_18 -> V_3 , V_18 -> V_19 ,
V_18 -> V_20 , V_16 ) ;
} else {
struct V_42 * V_42 =
(struct V_42 * ) ( V_14 -> V_43 ) ;
const struct V_44 * V_44 =
& V_42 -> V_44 ;
F_7 ( V_14 ,
( unsigned long ) & V_11 ,
V_44 -> V_19 ,
V_44 -> V_20 , V_16 ) ;
}
} else {
unsigned long V_3 , V_6 ;
__asm__ __volatile__ ("or %0, r1, r0" : "=r" (fp));
__asm__ __volatile__ (
"brlid %0, 0f;"
"nop;"
"0:"
: "=r" (pc)
);
F_7 ( V_41 , V_3 , V_6 , 0 , V_16 ) ;
}
}
