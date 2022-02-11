static unsigned long * F_1 ( unsigned V_1 , unsigned long V_2 ,
unsigned * V_3 , char * * V_4 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
unsigned long V_7 = F_2 ( V_8 , V_1 ) . V_9 [ V_5 ] ;
if ( V_2 >= V_7 )
continue;
if ( V_2 >= V_7 - V_10 ) {
if ( * V_3 & ( 1U << V_5 ) )
break;
* V_3 |= 1U << V_5 ;
* V_4 = V_11 [ V_5 ] ;
return ( unsigned long * ) V_7 ;
}
#if V_12 > V_10
if ( V_5 == V_13 - 1 && V_2 >= V_7 - V_12 ) {
unsigned V_14 = V_6 - 1 ;
do {
++ V_14 ;
V_7 -= V_10 ;
V_11 [ V_14 ] [ 4 ] = '1' +
( V_14 - V_6 ) ;
} while ( V_2 < V_7 - V_10 );
if ( * V_3 & ( 1U << V_14 ) )
break;
* V_3 |= 1U << V_14 ;
* V_4 = V_11 [ V_14 ] ;
return ( unsigned long * ) V_7 ;
}
#endif
}
return NULL ;
}
static inline int
F_3 ( unsigned long * V_2 , unsigned long * V_15 ,
unsigned long * V_16 )
{
return ( V_2 >= V_15 && V_2 < V_16 ) ;
}
static inline unsigned long
F_4 ( unsigned long V_17 , unsigned long * V_2 ,
unsigned long * V_15 , unsigned long * V_16 )
{
#ifdef F_5
struct V_18 * V_19 = (struct V_18 * ) V_17 ;
unsigned long V_20 ;
if ( ! F_3 ( V_2 , V_15 , V_16 ) ) {
if ( ! F_6 ( & V_19 -> V_21 , V_20 ) )
return V_20 ;
else
F_7 ( 1 , L_1
L_2 , & V_19 -> V_21 ) ;
}
#endif
return V_17 ;
}
void F_8 ( struct V_22 * V_23 , struct V_24 * V_25 ,
unsigned long * V_2 , unsigned long V_17 ,
const struct V_26 * V_27 , void * V_28 )
{
const unsigned V_1 = F_9 () ;
unsigned long * V_16 =
( unsigned long * ) F_2 ( V_29 , V_1 ) ;
unsigned V_30 = 0 ;
struct V_31 * V_32 ;
int V_33 = 0 ;
unsigned long V_34 ;
if ( ! V_23 )
V_23 = V_35 ;
if ( ! V_2 ) {
V_2 = & V_34 ;
if ( V_23 && V_23 != V_35 )
V_2 = ( unsigned long * ) V_23 -> V_36 . V_37 ;
}
if ( ! V_17 )
V_17 = V_18 ( V_23 , V_25 ) ;
V_32 = F_10 ( V_23 ) ;
for (; ; ) {
char * V_38 ;
unsigned long * V_39 ;
V_39 = F_1 ( V_1 , ( unsigned long ) V_2 ,
& V_30 , & V_38 ) ;
if ( V_39 ) {
if ( V_27 -> V_2 ( V_28 , V_38 ) < 0 )
break;
V_17 = V_27 -> V_40 ( V_32 , V_2 , V_17 , V_27 ,
V_28 , V_39 , & V_33 ) ;
V_27 -> V_2 ( V_28 , L_3 ) ;
V_2 = ( unsigned long * ) V_39 [ - 2 ] ;
continue;
}
if ( V_16 ) {
unsigned long * V_15 ;
V_15 = V_16 -
( V_41 - 64 ) / sizeof( * V_15 ) ;
if ( F_3 ( V_2 , V_15 , V_16 ) ) {
if ( V_27 -> V_2 ( V_28 , L_4 ) < 0 )
break;
V_17 = V_27 -> V_40 ( V_32 , V_2 , V_17 ,
V_27 , V_28 , V_16 , & V_33 ) ;
V_2 = ( unsigned long * ) ( V_16 [ - 1 ] ) ;
V_17 = F_4 ( V_17 , V_2 , V_15 ,
V_16 ) ;
V_16 = NULL ;
V_27 -> V_2 ( V_28 , L_5 ) ;
continue;
}
}
break;
}
V_17 = V_27 -> V_40 ( V_32 , V_2 , V_17 , V_27 , V_28 , NULL , & V_33 ) ;
F_11 () ;
}
void
F_12 ( struct V_22 * V_23 , struct V_24 * V_25 ,
unsigned long * V_37 , unsigned long V_17 , char * V_42 )
{
unsigned long * V_16 ;
unsigned long * V_15 ;
unsigned long * V_2 ;
int V_1 ;
int V_43 ;
F_13 () ;
V_1 = F_14 () ;
V_16 = ( unsigned long * ) ( F_2 ( V_29 , V_1 ) ) ;
V_15 = ( unsigned long * ) ( F_2 ( V_29 , V_1 ) - V_41 ) ;
if ( V_37 == NULL ) {
if ( V_23 )
V_37 = ( unsigned long * ) V_23 -> V_36 . V_37 ;
else
V_37 = ( unsigned long * ) & V_37 ;
}
V_2 = V_37 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_2 >= V_15 && V_2 <= V_16 ) {
if ( V_2 == V_16 ) {
V_2 = ( unsigned long * ) ( V_16 [ - 1 ] ) ;
F_15 ( V_45 L_6 ) ;
}
} else {
if ( ( ( long ) V_2 & ( V_46 - 1 ) ) == 0 )
break;
}
if ( V_43 && ( ( V_43 % V_47 ) == 0 ) )
F_15 ( V_45 L_7 ) ;
F_15 ( V_45 L_8 , * V_2 ++ ) ;
F_16 () ;
}
F_17 () ;
F_15 ( V_45 L_7 ) ;
F_18 ( V_23 , V_25 , V_37 , V_17 , V_42 ) ;
}
void F_19 ( struct V_24 * V_25 )
{
int V_43 ;
unsigned long V_37 ;
const int V_1 = F_14 () ;
struct V_22 * V_48 = V_35 ;
V_37 = V_25 -> V_37 ;
F_15 ( L_9 , V_1 ) ;
F_20 () ;
F_21 ( V_25 , 1 ) ;
F_15 ( L_10 ,
V_48 -> V_49 , V_48 -> V_50 , F_10 ( V_48 ) , V_48 ) ;
if ( ! F_22 ( V_25 ) ) {
unsigned int V_51 = V_52 * 43 / 64 ;
unsigned int V_53 = V_52 ;
unsigned char V_54 ;
T_1 * V_55 ;
F_15 ( V_56 L_11 ) ;
F_12 ( NULL , V_25 , ( unsigned long * ) V_37 ,
0 , V_56 ) ;
F_15 ( V_56 L_12 ) ;
V_55 = ( T_1 * ) V_25 -> V_55 - V_51 ;
if ( V_55 < ( T_1 * ) V_57 || F_6 ( V_55 , V_54 ) ) {
V_55 = ( T_1 * ) V_25 -> V_55 ;
V_53 = V_53 - V_51 + 1 ;
}
for ( V_43 = 0 ; V_43 < V_53 ; V_43 ++ , V_55 ++ ) {
if ( V_55 < ( T_1 * ) V_57 ||
F_6 ( V_55 , V_54 ) ) {
F_15 ( L_13 ) ;
break;
}
if ( V_55 == ( T_1 * ) V_25 -> V_55 )
F_15 ( L_14 , V_54 ) ;
else
F_15 ( L_15 , V_54 ) ;
}
}
F_15 ( L_7 ) ;
}
int F_23 ( unsigned long V_55 )
{
unsigned short V_58 ;
if ( F_24 ( & V_58 , ( const void V_59 * ) V_55 , sizeof( V_58 ) ) )
return 0 ;
return V_58 == 0x0b0f ;
}
