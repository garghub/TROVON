int F_1 ( void )
{
F_2 ( V_1 , 1 , V_2 , NULL , 0 ) ;
return F_3 () ;
}
void F_4 ( void )
{
F_2 ( V_1 , 2 , V_2 , NULL , 0 ) ;
F_5 () ;
}
int F_6 ( struct V_3 * V_4 , int V_5 )
{
int V_6 = 0 ;
struct V_7 * V_8 ;
struct V_7 * V_9 ;
F_2 ( V_1 , 3 , V_2 , NULL , V_5 ) ;
if ( V_5 ) {
F_7 ( L_1 ) ;
return 0 ;
}
F_7 ( L_2 ) ;
V_8 = F_8 ( sizeof( struct V_7 ) , V_10 ) ;
if ( V_8 == NULL )
return - V_11 ;
F_9 ( & V_8 -> V_12 , 1 ) ;
V_8 -> V_4 = V_4 ;
V_8 -> V_13 = 0 ;
F_10 ( & V_4 -> V_14 [ V_2 - 1 ] ) ;
V_9 = V_4 -> V_15 [ V_2 - 1 ] ;
if ( V_9 == NULL )
V_4 -> V_15 [ V_2 - 1 ] = V_8 ;
F_11 ( V_4 -> V_15 [ V_2 - 1 ] ) ;
F_12 ( & V_4 -> V_14 [ V_2 - 1 ] ) ;
if ( V_9 ) {
F_7 ( L_3 ) ;
F_13 ( V_8 ) ;
V_8 = V_9 ;
} else if ( V_8 ) {
F_14 ( V_4 ) ;
}
if ( V_8 -> V_16 ) {
F_15 ( V_8 , V_8 -> V_16 ) ;
} else {
V_8 -> V_16 = F_16 ( V_8 ) ;
if ( V_8 -> V_16 == NULL ) {
F_7 ( L_4 ) ;
F_10 ( & V_4 -> V_14 [ V_2 - 1 ] ) ;
V_4 -> V_15 [ V_2 - 1 ] = NULL ;
F_12 ( & V_4 -> V_14 [ V_2 - 1 ] ) ;
F_17 ( V_8 ) ;
V_6 = - 1 ;
}
}
F_17 ( V_8 ) ;
return V_6 ;
}
void F_18 ( struct V_3 * V_4 , int V_17 )
{
struct V_7 * V_8 ;
F_2 ( V_1 , 4 , V_2 , NULL , V_17 ) ;
if ( V_17 ) {
F_7 ( L_5 ) ;
return;
}
F_10 ( & V_4 -> V_14 [ V_2 - 1 ] ) ;
V_8 = (struct V_7 * ) V_4 -> V_15 [ V_2 - 1 ] ;
V_4 -> V_15 [ V_2 - 1 ] = NULL ;
F_12 ( & V_4 -> V_14 [ V_2 - 1 ] ) ;
if ( V_8 ) {
unsigned long V_18 = V_19 + V_20 ;
F_7 ( L_6 ) ;
V_8 -> V_13 = 1 ;
while ( ( F_19 ( & V_8 -> V_12 ) > 2 ) &&
F_20 ( V_19 , V_18 ) )
;
F_7 ( L_7 ) ;
F_21 ( V_8 -> V_16 ) ;
F_17 ( V_8 ) ;
}
}
void F_11 ( void * V_21 )
{
struct V_7 * V_8 = (struct V_7 * ) V_21 ;
F_22 ( & V_8 -> V_12 ) ;
}
void F_17 ( void * V_21 )
{
struct V_7 * V_8 = (struct V_7 * ) V_21 ;
if ( F_23 ( & V_8 -> V_12 ) ) {
F_7 ( L_8 ) ;
F_24 ( V_8 -> V_4 ) ;
F_13 ( V_8 ) ;
}
}
int F_25 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_6 = 0 ;
F_10 ( & V_4 -> V_14 [ V_2 - 1 ] ) ;
V_8 = (struct V_7 * ) V_4 -> V_15 [ V_2 - 1 ] ;
if ( V_8 )
F_11 ( V_8 ) ;
F_12 ( & V_4 -> V_14 [ V_2 - 1 ] ) ;
if ( V_8 == NULL )
return V_6 ;
if ( V_8 -> V_13 )
goto V_22;
if ( V_8 -> V_16 )
if ( F_26 ( V_8 -> V_16 ) )
V_6 = 1 ;
V_22:
F_17 ( V_8 ) ;
return V_6 ;
}
int F_27 ( void * V_21 , T_1 V_23 )
{
struct V_7 * V_8 = (struct V_7 * ) V_21 ;
struct V_3 * V_4 = V_8 -> V_4 ;
F_7 ( L_9 , V_23 ) ;
if ( V_4 -> V_24 & V_25 ) {
F_28 ( V_4 , V_23 ) ;
} else {
F_14 ( V_4 ) ;
if ( F_29 ( & V_4 -> V_26 , V_23 ,
4 * V_4 -> V_27 ) ) {
F_24 ( V_4 ) ;
return - 1 ;
}
}
return 0 ;
}
int F_30 ( void * V_21 , T_1 V_23 )
{
struct V_7 * V_8 = (struct V_7 * ) V_21 ;
if ( V_8 ) {
struct V_3 * V_4 = V_8 -> V_4 ;
if ( V_4 ) {
F_7 ( L_10 , V_23 ) ;
if ( V_4 -> V_24 & V_25 ) {
F_31 ( V_4 , V_23 ) ;
} else {
if ( F_32 ( & V_4 -> V_26 , V_23 ) )
return - 1 ;
F_24 ( V_4 ) ;
}
}
}
return 0 ;
}
void F_33 ( void * V_21 )
{
struct V_7 * V_8 = (struct V_7 * ) V_21 ;
if ( V_8 && V_8 -> V_4 )
F_34 ( V_8 -> V_4 ) ;
}
