static void F_1 ( unsigned long * V_1 ,
unsigned long * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
V_2 [ V_3 ] =
V_1 [ V_3 ] & V_4 -> V_6 [ V_3 ] ;
V_1 [ V_3 ] ^= V_2 [ V_3 ] ;
}
}
static void F_2 ( unsigned int V_7 , struct V_8 * V_9 )
{
unsigned long V_10 [ V_11 ] ;
unsigned long V_12 [ V_11 ] ;
struct V_13 * V_14 = F_3 ( V_9 ) ;
unsigned int V_15 ;
int V_16 = V_4 -> V_5 * 32 ;
if ( V_4 -> V_17 ) {
V_4 -> V_18 ( V_4 -> V_19 ) ;
V_4 -> V_20 = true ;
}
while ( ! V_4 -> V_17 ) {
V_4 -> V_21 ( V_10 ) ;
if ( F_4 ( V_10 , V_16 ) >= V_16 )
break;
F_1 ( V_10 , V_12 ) ;
F_5 (virtirq, priority_pending, nr_irqs)
F_6 ( V_4 -> V_22 + V_15 ) ;
F_5 (virtirq, pending, nr_irqs)
F_6 ( V_4 -> V_22 + V_15 ) ;
}
if ( V_14 -> V_23 )
V_14 -> V_23 ( & V_9 -> V_24 ) ;
if ( V_14 -> V_25 )
V_14 -> V_25 ( & V_9 -> V_24 ) ;
V_14 -> V_26 ( & V_9 -> V_24 ) ;
V_4 -> V_27 () ;
}
int F_7 ( const char * V_28 )
{
int V_3 ;
if ( ! V_4 || ! V_28 )
return - V_29 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_16 ; V_3 ++ )
if ( ! strcmp ( V_4 -> V_30 [ V_3 ] . V_28 , V_28 ) )
return V_4 -> V_22 +
V_4 -> V_30 [ V_3 ] . V_31 ;
return - V_29 ;
}
void F_8 ( void )
{
int V_3 ;
if ( ! V_4 ) {
F_9 ( L_1 ) ;
return;
}
if ( V_32 ) {
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
if ( V_32 [ V_3 ] )
F_10 ( V_32 [ V_3 ] ,
0xffffffff , 0 , 0 ) ;
V_32 [ V_3 ] = NULL ;
}
F_11 ( V_32 ) ;
V_32 = NULL ;
}
F_11 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_11 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
F_12 ( V_4 -> V_7 , NULL ) ;
if ( V_4 -> V_22 > 0 )
F_13 ( V_4 -> V_22 ,
V_4 -> V_5 * 32 ) ;
V_4 -> V_22 = 0 ;
}
void F_14 ( void )
{
V_4 -> V_17 = true ;
}
void F_15 ( void )
{
V_4 -> V_17 = false ;
if ( ! V_4 -> V_20 )
return;
V_4 -> V_20 = false ;
V_4 -> V_33 ( V_4 -> V_19 ) ;
}
int F_16 ( struct V_34 * V_35 )
{
int V_5 = V_35 -> V_5 ;
T_1 V_36 [ V_11 ] ;
int V_31 , V_3 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
if ( ! V_35 )
return - V_41 ;
if ( V_4 ) {
F_9 ( L_2 ) ;
return - V_41 ;
}
if ( V_5 > V_11 ) {
F_9 ( L_3 ) ;
return - V_41 ;
}
V_4 = V_35 ;
V_32 = F_17 ( sizeof( void * ) * V_5 , V_42 ) ;
V_4 -> V_19 = F_17 ( sizeof( T_1 ) * V_5 , V_42 ) ;
V_4 -> V_6 = F_17 ( sizeof( T_1 ) * V_5 ,
V_42 ) ;
if ( ! V_32 || ! V_4 -> V_19 ||
! V_4 -> V_6 ) {
F_9 ( L_4 ) ;
goto V_43;
}
memset ( V_36 , 0 , sizeof( V_36 ) ) ;
for ( V_3 = 0 ; V_3 < V_35 -> V_16 ; V_3 ++ ) {
V_31 = V_35 -> V_30 [ V_3 ] . V_31 ;
V_36 [ V_31 >> 5 ] |= 1 << ( V_31 & 0x1f ) ;
if ( V_35 -> V_30 [ V_3 ] . V_44 )
V_35 -> V_6 [ V_31 >> 5 ] |=
1 << ( V_31 & 0x1f ) ;
}
F_12 ( V_35 -> V_7 , F_2 ) ;
V_35 -> V_22 = F_18 ( - 1 , 0 , V_35 -> V_5 * 32 ,
0 ) ;
if ( V_35 -> V_22 < 0 ) {
F_9 ( L_5 ,
V_35 -> V_22 ) ;
goto V_43;
}
for ( V_3 = 0 ; V_3 <= V_35 -> V_5 ; V_3 ++ ) {
V_38 = F_19 ( L_6 , 1 ,
V_35 -> V_22 + V_3 * 32 , V_45 ,
V_46 ) ;
if ( ! V_38 ) {
F_9 ( L_7 ) ;
goto V_43;
}
V_40 = V_38 -> V_47 ;
V_40 -> V_14 . V_23 = V_48 ;
V_40 -> V_14 . V_49 = V_50 ;
V_40 -> V_14 . V_26 = V_51 ;
V_40 -> V_52 . V_53 = V_35 -> V_53 + V_3 * 4 ;
V_40 -> V_52 . V_36 = V_35 -> V_36 + V_3 * 4 ;
F_20 ( V_38 , V_36 [ V_3 ] , 0 , V_54 , 0 ) ;
V_32 [ V_3 ] = V_38 ;
}
return 0 ;
V_43:
F_8 () ;
return - V_55 ;
}
