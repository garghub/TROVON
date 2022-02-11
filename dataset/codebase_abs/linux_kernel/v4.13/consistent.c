void * F_1 ( T_1 V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned long V_4 , V_5 ;
void * V_6 ;
unsigned int V_7 , V_8 = 0 ;
struct V_9 * V_9 , * V_10 ;
#ifdef F_2
T_4 V_11 ;
struct V_12 * V_13 ;
unsigned long V_14 ;
#endif
if ( F_3 () )
F_4 () ;
V_2 = F_5 ( V_2 ) ;
V_4 = F_6 ( V_2 ) ;
V_5 = F_7 ( V_1 , V_4 ) ;
if ( ! V_5 )
return NULL ;
F_8 ( F_9 ( ( void * ) V_5 ) ,
F_9 ( ( void * ) V_5 ) + V_2 ) ;
#ifndef F_2
V_6 = ( void * ) V_5 ;
# ifdef F_10
V_6 = ( void * ) ( ( unsigned ) V_6 | V_15 ) ;
# endif
if ( ( unsigned int ) V_6 > V_16 . V_17 &&
( unsigned int ) V_6 < V_16 . V_18 )
F_11 ( L_1 ) ;
* V_3 = ( T_3 ) V_6 ;
#else
V_13 = F_12 ( V_2 , V_19 ) ;
if ( ! V_13 ) {
F_13 ( V_5 , V_4 ) ;
return NULL ;
}
V_14 = ( unsigned long ) V_13 -> V_20 ;
V_6 = ( void * ) V_14 ;
* V_3 = V_11 = F_14 ( V_5 ) ;
#endif
V_9 = F_15 ( V_5 ) ;
V_10 = V_9 + ( 1 << V_4 ) ;
F_16 ( V_9 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_2 && V_8 == 0 ; V_7 += V_21 ) {
#ifdef F_2
V_8 = F_17 ( V_14 + V_7 , V_11 + V_7 , V_22 | V_23 ) ;
#endif
F_18 ( V_9 ) ;
V_9 ++ ;
}
while ( V_9 < V_10 ) {
F_19 ( V_9 ) ;
V_9 ++ ;
}
if ( V_8 ) {
F_13 ( V_5 , V_4 ) ;
return NULL ;
}
return V_6 ;
}
static T_5 * F_20 ( void * V_5 )
{
unsigned long V_20 = ( unsigned long ) V_5 ;
return F_21 ( F_22 ( F_23 ( V_20 ) , V_20 ) , V_20 ) ;
}
unsigned long F_24 ( void * V_5 )
{
T_5 * V_24 = F_20 ( V_5 ) ;
if ( F_25 ( * V_24 ) || ! F_26 ( * V_24 ) )
return 0 ;
return F_27 ( * V_24 ) ;
}
void F_28 ( T_2 V_2 , void * V_5 )
{
struct V_9 * V_9 ;
if ( F_3 () )
F_4 () ;
V_2 = F_5 ( V_2 ) ;
#ifndef F_2
# ifdef F_10
V_5 = ( void * ) ( ( unsigned ) V_5 & ~ V_15 ) ;
# endif
V_9 = F_15 ( V_5 ) ;
do {
F_29 ( V_9 ) ;
V_9 ++ ;
} while ( V_2 -= V_21 );
#else
do {
T_5 * V_24 = F_20 ( V_5 ) ;
unsigned long V_25 ;
if ( ! F_25 ( * V_24 ) && F_26 ( * V_24 ) ) {
V_25 = F_27 ( * V_24 ) ;
F_30 ( & V_26 , ( unsigned int ) V_5 , V_24 ) ;
if ( F_31 ( V_25 ) ) {
V_9 = F_32 ( V_25 ) ;
F_29 ( V_9 ) ;
}
}
V_5 += V_21 ;
} while ( V_2 -= V_21 );
F_33 () ;
#endif
}
void F_34 ( void * V_5 , T_2 V_2 , int V_27 )
{
unsigned long V_28 ;
unsigned long V_10 ;
V_28 = ( unsigned long ) V_5 ;
#ifdef F_10
V_28 &= ~ V_15 ;
#endif
V_10 = V_28 + V_2 ;
switch ( V_27 ) {
case V_29 :
F_4 () ;
case V_30 :
F_35 ( V_28 , V_10 ) ;
break;
case V_31 :
F_8 ( V_28 , V_10 ) ;
break;
case V_32 :
F_8 ( V_28 , V_10 ) ;
break;
}
}
void F_36 ( struct V_9 * V_9 , unsigned long V_33 ,
T_2 V_2 , int V_27 )
{
unsigned long V_28 = ( unsigned long ) F_37 ( V_9 ) + V_33 ;
F_34 ( ( void * ) V_28 , V_2 , V_27 ) ;
}
