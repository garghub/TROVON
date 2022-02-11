static void
F_1 ( void * V_1 , bool V_2 ,
struct V_3 * V_4 , struct V_3 * V_5 )
{
int V_6 ;
V_6 = ( V_7 * ! ! V_8 ) +
( V_9 * ! ! V_10 ) ;
if ( ! V_6 )
return;
F_2 ( V_4 , V_5 , V_6 ) ;
}
static void
F_3 ( void * V_1 , struct V_3 * V_11 )
{
int V_6 ;
V_6 = ( V_7 * ! ! V_8 ) +
( V_9 * ! ! V_10 ) ;
if ( ! V_6 )
return;
F_4 ( V_12 , V_6 ) ;
}
static int F_5 ( void )
{
int V_13 ;
V_13 = F_6 ( F_3 , NULL ) ;
if ( V_13 ) {
F_7 ( L_1
L_2 ) ;
return V_13 ;
}
V_13 = F_8 ( F_3 , NULL ) ;
if ( V_13 ) {
F_7 ( L_1
L_3 ) ;
goto V_14;
}
V_13 = F_9 ( F_1 , NULL ) ;
if ( V_13 ) {
F_7 ( L_4
L_5 ) ;
goto V_15;
}
return V_13 ;
V_15:
F_10 ( F_3 , NULL ) ;
V_14:
F_11 ( F_3 , NULL ) ;
return V_13 ;
}
static void F_12 ( void )
{
F_13 ( F_1 , NULL ) ;
F_10 ( F_3 , NULL ) ;
F_11 ( F_3 , NULL ) ;
}
static void F_14 ( int V_16 )
{
bool V_17 = ( ! V_10 && ! V_8 ) ;
F_15 ( & V_18 ) ;
switch ( V_16 ) {
case V_9 :
V_10 ++ ;
break;
case V_7 :
V_8 ++ ;
break;
}
if ( V_17 && ( V_10 || V_8 ) )
F_5 () ;
F_16 ( & V_18 ) ;
}
static void F_17 ( int V_16 )
{
F_15 ( & V_18 ) ;
switch ( V_16 ) {
case V_9 :
V_10 -- ;
break;
case V_7 :
V_8 -- ;
break;
}
if ( ! V_10 && ! V_8 )
F_12 () ;
F_16 ( & V_18 ) ;
}
void F_18 ( void )
{
F_14 ( V_9 ) ;
}
void F_19 ( void )
{
F_17 ( V_9 ) ;
}
void F_20 ( void )
{
F_14 ( V_7 ) ;
}
void F_21 ( void )
{
F_17 ( V_7 ) ;
}
