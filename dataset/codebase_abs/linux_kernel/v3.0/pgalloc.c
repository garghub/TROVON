T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 * V_4 = ( T_1 * ) F_2 ( V_5 | V_6 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
return V_4 ;
}
T_2 F_4 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_7 * V_7 ;
#ifdef F_5
V_7 = F_6 ( V_5 | V_8 | V_6 , 0 ) ;
#else
V_7 = F_6 ( V_5 | V_6 , 0 ) ;
#endif
if ( V_7 ) {
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
return V_7 ;
}
void F_10 ( T_3 * V_9 , unsigned long V_10 )
{
unsigned long * V_11 = V_9 -> V_12 ;
int V_13 ;
if ( ! V_10 ) {
memset ( V_11 , 0 , V_14 ) ;
}
else {
F_11 ( V_10 & ( 0x3f00 | V_15 | 0xe ) ) ;
for ( V_13 = V_14 ; V_13 > 0 ; V_13 -= 4 ) {
* V_11 ++ = V_10 ;
V_10 += V_16 ;
}
}
F_12 ( ( unsigned long ) V_9 , ( unsigned long ) ( V_9 + 1 ) ) ;
}
static inline void F_13 ( T_4 * V_17 )
{
struct V_7 * V_7 = F_14 ( V_17 ) ;
V_7 -> V_18 = ( unsigned long ) V_19 ;
if ( V_19 )
F_15 ( V_19 , ( unsigned long ) & V_7 -> V_18 ) ;
V_19 = V_7 ;
F_15 ( V_7 , ( unsigned long ) & V_19 ) ;
}
static inline void F_16 ( T_4 * V_17 )
{
struct V_7 * V_20 , * * V_21 , * V_7 = F_14 ( V_17 ) ;
V_20 = (struct V_7 * ) V_7 -> V_18 ;
V_21 = (struct V_7 * * ) F_17 ( V_7 ) ;
* V_21 = V_20 ;
if ( V_20 )
F_15 ( V_20 , ( unsigned long ) V_21 ) ;
}
void F_18 ( void * V_17 )
{
unsigned long V_22 ;
if ( V_23 == 1 )
F_19 ( & V_24 , V_22 ) ;
memcpy ( ( T_4 * ) V_17 + V_25 ,
V_26 + V_25 ,
( V_27 - V_25 ) * sizeof( T_4 ) ) ;
if ( V_23 > 1 )
return;
F_13 ( V_17 ) ;
F_20 ( & V_24 , V_22 ) ;
memset ( V_17 , 0 , V_25 * sizeof( T_4 ) ) ;
}
void F_21 ( void * V_17 )
{
unsigned long V_22 ;
F_19 ( & V_24 , V_22 ) ;
F_16 ( V_17 ) ;
F_20 ( & V_24 , V_22 ) ;
}
T_4 * F_22 ( struct V_1 * V_2 )
{
T_4 * V_17 ;
V_17 = F_23 ( 0 , V_5 , F_18 ) ;
if ( ! V_17 )
return V_17 ;
return V_17 ;
}
void F_24 ( struct V_1 * V_2 , T_4 * V_17 )
{
F_25 ( 0 , F_21 , V_17 ) ;
}
void T_5 F_26 ( void )
{
}
void F_27 ( void )
{
F_28 ( 0 , F_21 , 25 , 16 ) ;
}
