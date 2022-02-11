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
void F_4 ( struct V_17 * V_18 , struct V_19 * V_20 ,
unsigned long * V_2 , unsigned long V_21 ,
const struct V_22 * V_23 , void * V_24 )
{
const unsigned V_1 = F_5 () ;
unsigned long * V_16 =
( unsigned long * ) F_2 ( V_25 , V_1 ) ;
unsigned V_26 = 0 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
unsigned long V_30 ;
if ( ! V_18 )
V_18 = V_31 ;
if ( ! V_2 ) {
if ( V_20 )
V_2 = ( unsigned long * ) V_20 -> V_32 ;
else if ( V_18 != V_31 )
V_2 = ( unsigned long * ) V_18 -> V_33 . V_32 ;
else
V_2 = & V_30 ;
}
if ( ! V_21 )
V_21 = F_6 ( V_18 , V_20 ) ;
V_28 = F_7 ( V_18 ) ;
for (; ; ) {
char * V_34 ;
unsigned long * V_35 ;
V_35 = F_1 ( V_1 , ( unsigned long ) V_2 ,
& V_26 , & V_34 ) ;
if ( V_35 ) {
if ( V_23 -> V_2 ( V_24 , V_34 ) < 0 )
break;
V_21 = V_23 -> V_36 ( V_28 , V_2 , V_21 , V_23 ,
V_24 , V_35 , & V_29 ) ;
V_23 -> V_2 ( V_24 , L_1 ) ;
V_2 = ( unsigned long * ) V_35 [ - 2 ] ;
continue;
}
if ( V_16 ) {
unsigned long * V_15 ;
V_15 = V_16 -
( V_37 - 64 ) / sizeof( * V_15 ) ;
if ( F_3 ( V_2 , V_15 , V_16 ) ) {
if ( V_23 -> V_2 ( V_24 , L_2 ) < 0 )
break;
V_21 = V_23 -> V_36 ( V_28 , V_2 , V_21 ,
V_23 , V_24 , V_16 , & V_29 ) ;
V_2 = ( unsigned long * ) ( V_16 [ - 1 ] ) ;
V_16 = NULL ;
V_23 -> V_2 ( V_24 , L_3 ) ;
continue;
}
}
break;
}
V_21 = V_23 -> V_36 ( V_28 , V_2 , V_21 , V_23 , V_24 , NULL , & V_29 ) ;
F_8 () ;
}
void
F_9 ( struct V_17 * V_18 , struct V_19 * V_20 ,
unsigned long * V_32 , unsigned long V_21 , char * V_38 )
{
unsigned long * V_16 ;
unsigned long * V_15 ;
unsigned long * V_2 ;
int V_1 ;
int V_39 ;
F_10 () ;
V_1 = F_11 () ;
V_16 = ( unsigned long * ) ( F_2 ( V_25 , V_1 ) ) ;
V_15 = ( unsigned long * ) ( F_2 ( V_25 , V_1 ) - V_37 ) ;
if ( V_32 == NULL ) {
if ( V_18 )
V_32 = ( unsigned long * ) V_18 -> V_33 . V_32 ;
else
V_32 = ( unsigned long * ) & V_32 ;
}
V_2 = V_32 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( V_2 >= V_15 && V_2 <= V_16 ) {
if ( V_2 == V_16 ) {
V_2 = ( unsigned long * ) ( V_16 [ - 1 ] ) ;
F_12 ( V_41 L_4 ) ;
}
} else {
if ( ( ( long ) V_2 & ( V_42 - 1 ) ) == 0 )
break;
}
if ( V_39 && ( ( V_39 % V_43 ) == 0 ) )
F_12 ( V_41 L_5 ) ;
F_12 ( V_41 L_6 , * V_2 ++ ) ;
F_13 () ;
}
F_14 () ;
F_12 ( V_41 L_5 ) ;
F_15 ( V_18 , V_20 , V_32 , V_21 , V_38 ) ;
}
void F_16 ( struct V_19 * V_20 )
{
int V_39 ;
unsigned long V_32 ;
const int V_1 = F_11 () ;
struct V_17 * V_44 = V_31 ;
V_32 = V_20 -> V_32 ;
F_12 ( L_7 , V_1 ) ;
F_17 () ;
F_18 ( V_20 , 1 ) ;
F_12 ( L_8 ,
V_44 -> V_45 , V_44 -> V_46 , F_7 ( V_44 ) , V_44 ) ;
if ( ! F_19 ( V_20 ) ) {
unsigned int V_47 = V_48 * 43 / 64 ;
unsigned int V_49 = V_48 ;
unsigned char V_50 ;
T_1 * V_51 ;
F_12 ( V_52 L_9 ) ;
F_9 ( NULL , V_20 , ( unsigned long * ) V_32 ,
0 , V_52 ) ;
F_12 ( V_52 L_10 ) ;
V_51 = ( T_1 * ) V_20 -> V_51 - V_47 ;
if ( V_51 < ( T_1 * ) V_53 || F_20 ( V_51 , V_50 ) ) {
V_51 = ( T_1 * ) V_20 -> V_51 ;
V_49 = V_49 - V_47 + 1 ;
}
for ( V_39 = 0 ; V_39 < V_49 ; V_39 ++ , V_51 ++ ) {
if ( V_51 < ( T_1 * ) V_53 ||
F_20 ( V_51 , V_50 ) ) {
F_12 ( V_41 L_11 ) ;
break;
}
if ( V_51 == ( T_1 * ) V_20 -> V_51 )
F_12 ( V_41 L_12 , V_50 ) ;
else
F_12 ( V_41 L_13 , V_50 ) ;
}
}
F_12 ( V_41 L_5 ) ;
}
int F_21 ( unsigned long V_51 )
{
unsigned short V_54 ;
if ( F_22 ( & V_54 , ( const void V_55 * ) V_51 , sizeof( V_54 ) ) )
return 0 ;
return V_54 == 0x0b0f ;
}
