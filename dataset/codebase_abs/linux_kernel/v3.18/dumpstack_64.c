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
static enum V_17
F_4 ( int V_1 , struct V_18 * V_19 , unsigned long * V_2 ,
unsigned long * * V_20 , unsigned long * V_15 ,
unsigned * V_21 , char * * V_22 )
{
unsigned long V_23 ;
V_23 = ( ( unsigned long ) V_2 & ( ~ ( V_24 - 1 ) ) ) ;
if ( ( unsigned long ) F_5 ( V_19 ) == V_23 )
return V_25 ;
* V_20 = F_1 ( V_1 , ( unsigned long ) V_2 ,
V_21 , V_22 ) ;
if ( * V_20 )
return V_26 ;
if ( ! V_15 )
return V_25 ;
* V_20 = V_15 ;
V_15 = V_15 - V_27 ;
if ( F_3 ( V_2 , V_15 , * V_20 ) )
return V_28 ;
return V_29 ;
}
void F_6 ( struct V_18 * V_19 , struct V_30 * V_31 ,
unsigned long * V_2 , unsigned long V_32 ,
const struct V_33 * V_34 , void * V_35 )
{
const unsigned V_1 = F_7 () ;
struct V_36 * V_37 ;
unsigned long * V_15 = ( unsigned long * ) F_2 ( V_38 , V_1 ) ;
unsigned long V_39 ;
unsigned V_21 = 0 ;
int V_40 = 0 ;
int V_41 = 0 ;
if ( ! V_19 )
V_19 = V_42 ;
if ( ! V_2 ) {
if ( V_31 )
V_2 = ( unsigned long * ) V_31 -> V_43 ;
else if ( V_19 != V_42 )
V_2 = ( unsigned long * ) V_19 -> V_44 . V_43 ;
else
V_2 = & V_39 ;
}
if ( ! V_32 )
V_32 = F_8 ( V_19 , V_31 ) ;
V_37 = F_9 ( V_19 ) ;
while ( ! V_41 ) {
unsigned long * V_20 ;
enum V_17 V_45 ;
char * V_22 ;
V_45 = F_4 ( V_1 , V_19 , V_2 , & V_20 ,
V_15 , & V_21 , & V_22 ) ;
V_41 = 1 ;
switch ( V_45 ) {
case V_25 :
break;
case V_26 :
if ( V_34 -> V_2 ( V_35 , V_22 ) < 0 )
break;
V_32 = V_34 -> V_46 ( V_37 , V_2 , V_32 , V_34 ,
V_35 , V_20 , & V_40 ) ;
V_34 -> V_2 ( V_35 , L_1 ) ;
V_2 = ( unsigned long * ) V_20 [ - 2 ] ;
V_41 = 0 ;
break;
case V_28 :
if ( V_34 -> V_2 ( V_35 , L_2 ) < 0 )
break;
V_32 = V_34 -> V_46 ( V_37 , V_2 , V_32 ,
V_34 , V_35 , V_20 , & V_40 ) ;
V_2 = ( unsigned long * ) ( V_20 [ - 1 ] ) ;
V_15 = NULL ;
V_34 -> V_2 ( V_35 , L_3 ) ;
V_41 = 0 ;
break;
case V_29 :
V_34 -> V_2 ( V_35 , L_4 ) ;
break;
}
}
V_32 = V_34 -> V_46 ( V_37 , V_2 , V_32 , V_34 , V_35 , NULL , & V_40 ) ;
F_10 () ;
}
void
F_11 ( struct V_18 * V_19 , struct V_30 * V_31 ,
unsigned long * V_43 , unsigned long V_32 , char * V_47 )
{
unsigned long * V_16 ;
unsigned long * V_15 ;
unsigned long * V_2 ;
int V_1 ;
int V_48 ;
F_12 () ;
V_1 = F_13 () ;
V_16 = ( unsigned long * ) ( F_2 ( V_38 , V_1 ) ) ;
V_15 = ( unsigned long * ) ( F_2 ( V_38 , V_1 ) - V_49 ) ;
if ( V_43 == NULL ) {
if ( V_19 )
V_43 = ( unsigned long * ) V_19 -> V_44 . V_43 ;
else
V_43 = ( unsigned long * ) & V_43 ;
}
V_2 = V_43 ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
if ( V_2 >= V_15 && V_2 <= V_16 ) {
if ( V_2 == V_16 ) {
V_2 = ( unsigned long * ) ( V_16 [ - 1 ] ) ;
F_14 ( L_5 ) ;
}
} else {
if ( ( ( long ) V_2 & ( V_24 - 1 ) ) == 0 )
break;
}
if ( V_48 && ( ( V_48 % V_51 ) == 0 ) )
F_14 ( L_6 ) ;
F_14 ( L_7 , * V_2 ++ ) ;
F_15 () ;
}
F_16 () ;
F_14 ( L_6 ) ;
F_17 ( V_19 , V_31 , V_43 , V_32 , V_47 ) ;
}
void F_18 ( struct V_30 * V_31 )
{
int V_48 ;
unsigned long V_43 ;
V_43 = V_31 -> V_43 ;
F_19 ( V_52 ) ;
F_20 ( V_31 , 1 ) ;
if ( ! F_21 ( V_31 ) ) {
unsigned int V_53 = V_54 * 43 / 64 ;
unsigned int V_55 = V_54 ;
unsigned char V_56 ;
T_1 * V_57 ;
F_22 ( V_52 L_8 ) ;
F_11 ( NULL , V_31 , ( unsigned long * ) V_43 ,
0 , V_52 ) ;
F_22 ( V_52 L_9 ) ;
V_57 = ( T_1 * ) V_31 -> V_57 - V_53 ;
if ( V_57 < ( T_1 * ) V_58 || F_23 ( V_57 , V_56 ) ) {
V_57 = ( T_1 * ) V_31 -> V_57 ;
V_55 = V_55 - V_53 + 1 ;
}
for ( V_48 = 0 ; V_48 < V_55 ; V_48 ++ , V_57 ++ ) {
if ( V_57 < ( T_1 * ) V_58 ||
F_23 ( V_57 , V_56 ) ) {
F_14 ( L_10 ) ;
break;
}
if ( V_57 == ( T_1 * ) V_31 -> V_57 )
F_14 ( L_11 , V_56 ) ;
else
F_14 ( L_12 , V_56 ) ;
}
}
F_14 ( L_6 ) ;
}
int F_24 ( unsigned long V_57 )
{
unsigned short V_59 ;
if ( F_25 ( & V_59 , ( const void V_60 * ) V_57 , sizeof( V_59 ) ) )
return 0 ;
return V_59 == 0x0b0f ;
}
