int F_1 ( void )
{
return F_2 () ;
}
void F_3 ( void )
{
F_4 () ;
}
int F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
if ( V_3 ) {
F_6 ( L_1 ) ;
return 0 ;
}
F_6 ( L_2 ) ;
V_6 = F_7 ( sizeof( struct V_5 ) , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
F_8 ( & V_6 -> V_10 , 1 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_11 = 0 ;
F_9 ( & V_2 -> V_12 [ V_13 - 1 ] ) ;
V_7 = V_2 -> V_14 [ V_13 - 1 ] ;
if ( V_7 == NULL )
V_2 -> V_14 [ V_13 - 1 ] = V_6 ;
F_10 ( V_2 -> V_14 [ V_13 - 1 ] ) ;
F_11 ( & V_2 -> V_12 [ V_13 - 1 ] ) ;
if ( V_7 ) {
F_6 ( L_3 ) ;
F_12 ( V_6 ) ;
V_6 = V_7 ;
} else if ( V_6 ) {
F_13 ( V_2 ) ;
}
if ( V_6 -> V_15 ) {
F_14 ( V_6 , V_6 -> V_15 ) ;
} else {
V_6 -> V_15 = F_15 ( V_6 ) ;
if ( V_6 -> V_15 == NULL ) {
F_6 ( L_4 ) ;
F_9 ( & V_2 -> V_12 [ V_13 - 1 ] ) ;
V_2 -> V_14 [ V_13 - 1 ] = NULL ;
F_11 ( & V_2 -> V_12 [ V_13 - 1 ] ) ;
F_16 ( V_6 ) ;
V_4 = - 1 ;
}
}
F_16 ( V_6 ) ;
return V_4 ;
}
void F_17 ( struct V_1 * V_2 , int V_16 )
{
struct V_5 * V_6 ;
if ( V_16 ) {
F_6 ( L_5 ) ;
return;
}
F_9 ( & V_2 -> V_12 [ V_13 - 1 ] ) ;
V_6 = (struct V_5 * ) V_2 -> V_14 [ V_13 - 1 ] ;
V_2 -> V_14 [ V_13 - 1 ] = NULL ;
F_11 ( & V_2 -> V_12 [ V_13 - 1 ] ) ;
if ( V_6 ) {
unsigned long V_17 = V_18 + V_19 ;
F_6 ( L_6 ) ;
V_6 -> V_11 = 1 ;
while ( ( F_18 ( & V_6 -> V_10 ) > 2 ) &&
F_19 ( V_18 , V_17 ) )
;
F_6 ( L_7 ) ;
F_20 ( V_6 -> V_15 ) ;
F_16 ( V_6 ) ;
}
}
void F_10 ( void * V_20 )
{
struct V_5 * V_6 = (struct V_5 * ) V_20 ;
F_21 ( & V_6 -> V_10 ) ;
}
void F_16 ( void * V_20 )
{
struct V_5 * V_6 = (struct V_5 * ) V_20 ;
if ( F_22 ( & V_6 -> V_10 ) ) {
F_6 ( L_8 ) ;
F_23 ( V_6 -> V_2 ) ;
F_12 ( V_6 ) ;
}
}
int F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_4 = 0 ;
F_9 ( & V_2 -> V_12 [ V_13 - 1 ] ) ;
V_6 = (struct V_5 * ) V_2 -> V_14 [ V_13 - 1 ] ;
if ( V_6 )
F_10 ( V_6 ) ;
F_11 ( & V_2 -> V_12 [ V_13 - 1 ] ) ;
if ( V_6 == NULL )
return V_4 ;
if ( V_6 -> V_11 )
goto V_21;
if ( V_6 -> V_15 )
if ( F_25 ( V_6 -> V_15 ) )
V_4 = 1 ;
V_21:
F_16 ( V_6 ) ;
return V_4 ;
}
int F_26 ( void * V_20 , T_1 V_22 )
{
struct V_5 * V_6 = (struct V_5 * ) V_20 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_6 ( L_9 , V_22 ) ;
if ( V_2 -> V_23 & V_24 ) {
F_27 ( V_2 , V_22 ) ;
} else {
F_13 ( V_2 ) ;
if ( F_28 ( & V_2 -> V_25 , V_22 ,
4 * V_2 -> V_26 ) ) {
F_23 ( V_2 ) ;
return - 1 ;
}
}
return 0 ;
}
int F_29 ( void * V_20 , T_1 V_22 )
{
struct V_5 * V_6 = (struct V_5 * ) V_20 ;
if ( V_6 ) {
struct V_1 * V_2 = V_6 -> V_2 ;
if ( V_2 ) {
F_6 ( L_10 , V_22 ) ;
if ( V_2 -> V_23 & V_24 ) {
F_30 ( V_2 , V_22 ) ;
} else {
if ( F_31 ( & V_2 -> V_25 , V_22 ) )
return - 1 ;
F_23 ( V_2 ) ;
}
}
}
return 0 ;
}
void F_32 ( void * V_20 )
{
struct V_5 * V_6 = (struct V_5 * ) V_20 ;
if ( V_6 && V_6 -> V_2 )
F_33 ( V_6 -> V_2 ) ;
}
