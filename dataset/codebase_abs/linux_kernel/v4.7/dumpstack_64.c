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
unsigned long * V_15 = ( unsigned long * ) F_2 ( V_36 , V_1 ) ;
unsigned long V_37 ;
unsigned V_21 = 0 ;
int V_38 = 0 ;
int V_39 = 0 ;
if ( ! V_19 )
V_19 = V_40 ;
if ( ! V_2 ) {
if ( V_31 )
V_2 = ( unsigned long * ) V_31 -> V_41 ;
else if ( V_19 != V_40 )
V_2 = ( unsigned long * ) V_19 -> V_42 . V_41 ;
else
V_2 = & V_37 ;
}
if ( ! V_32 )
V_32 = F_8 ( V_19 , V_31 ) ;
while ( ! V_39 ) {
unsigned long * V_20 ;
enum V_17 V_43 ;
char * V_22 ;
V_43 = F_4 ( V_1 , V_19 , V_2 , & V_20 ,
V_15 , & V_21 , & V_22 ) ;
V_39 = 1 ;
switch ( V_43 ) {
case V_25 :
break;
case V_26 :
if ( V_34 -> V_2 ( V_35 , V_22 ) < 0 )
break;
V_32 = V_34 -> V_44 ( V_19 , V_2 , V_32 , V_34 ,
V_35 , V_20 , & V_38 ) ;
V_34 -> V_2 ( V_35 , L_1 ) ;
V_2 = ( unsigned long * ) V_20 [ - 2 ] ;
V_39 = 0 ;
break;
case V_28 :
if ( V_34 -> V_2 ( V_35 , L_2 ) < 0 )
break;
V_32 = V_34 -> V_44 ( V_19 , V_2 , V_32 ,
V_34 , V_35 , V_20 , & V_38 ) ;
V_2 = ( unsigned long * ) ( V_20 [ - 1 ] ) ;
V_15 = NULL ;
V_34 -> V_2 ( V_35 , L_3 ) ;
V_39 = 0 ;
break;
case V_29 :
V_34 -> V_2 ( V_35 , L_4 ) ;
break;
}
}
V_32 = V_34 -> V_44 ( V_19 , V_2 , V_32 , V_34 , V_35 , NULL , & V_38 ) ;
F_9 () ;
}
void
F_10 ( struct V_18 * V_19 , struct V_30 * V_31 ,
unsigned long * V_41 , unsigned long V_32 , char * V_45 )
{
unsigned long * V_16 ;
unsigned long * V_15 ;
unsigned long * V_2 ;
int V_1 ;
int V_46 ;
F_11 () ;
V_1 = F_12 () ;
V_16 = ( unsigned long * ) ( F_2 ( V_36 , V_1 ) ) ;
V_15 = ( unsigned long * ) ( F_2 ( V_36 , V_1 ) - V_47 ) ;
if ( V_41 == NULL ) {
if ( V_19 )
V_41 = ( unsigned long * ) V_19 -> V_42 . V_41 ;
else
V_41 = ( unsigned long * ) & V_41 ;
}
V_2 = V_41 ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
if ( V_2 >= V_15 && V_2 <= V_16 ) {
if ( V_2 == V_16 ) {
V_2 = ( unsigned long * ) ( V_16 [ - 1 ] ) ;
F_13 ( L_5 ) ;
}
} else {
if ( F_14 ( V_2 ) )
break;
}
if ( ( V_46 % V_49 ) == 0 ) {
if ( V_46 != 0 )
F_13 ( L_6 ) ;
F_15 ( L_7 , V_45 , * V_2 ++ ) ;
} else
F_13 ( L_8 , * V_2 ++ ) ;
F_16 () ;
}
F_17 () ;
F_13 ( L_6 ) ;
F_18 ( V_19 , V_31 , V_41 , V_32 , V_45 ) ;
}
void F_19 ( struct V_30 * V_31 )
{
int V_46 ;
unsigned long V_41 ;
V_41 = V_31 -> V_41 ;
F_20 ( V_50 ) ;
F_21 ( V_31 , 1 ) ;
if ( ! F_22 ( V_31 ) ) {
unsigned int V_51 = V_52 * 43 / 64 ;
unsigned int V_53 = V_52 ;
unsigned char V_54 ;
T_1 * V_55 ;
F_15 ( V_50 L_9 ) ;
F_10 ( NULL , V_31 , ( unsigned long * ) V_41 ,
0 , V_50 ) ;
F_15 ( V_50 L_10 ) ;
V_55 = ( T_1 * ) V_31 -> V_55 - V_51 ;
if ( V_55 < ( T_1 * ) V_56 || F_23 ( V_55 , V_54 ) ) {
V_55 = ( T_1 * ) V_31 -> V_55 ;
V_53 = V_53 - V_51 + 1 ;
}
for ( V_46 = 0 ; V_46 < V_53 ; V_46 ++ , V_55 ++ ) {
if ( V_55 < ( T_1 * ) V_56 ||
F_23 ( V_55 , V_54 ) ) {
F_13 ( L_11 ) ;
break;
}
if ( V_55 == ( T_1 * ) V_31 -> V_55 )
F_13 ( L_12 , V_54 ) ;
else
F_13 ( L_13 , V_54 ) ;
}
}
F_13 ( L_6 ) ;
}
int F_24 ( unsigned long V_55 )
{
unsigned short V_57 ;
if ( F_25 ( & V_57 , ( const void V_58 * ) V_55 , sizeof( V_57 ) ) )
return 0 ;
return V_57 == 0x0b0f ;
}
