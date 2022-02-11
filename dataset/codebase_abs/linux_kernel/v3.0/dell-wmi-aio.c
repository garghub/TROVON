static void F_1 ( T_1 V_1 , void * V_2 )
{
struct V_3 V_4 = { V_5 , NULL } ;
union V_6 * V_7 ;
T_2 V_8 ;
V_8 = F_2 ( V_1 , & V_4 ) ;
if ( V_8 != V_9 ) {
F_3 ( L_1 , V_8 ) ;
return;
}
V_7 = (union V_6 * ) V_4 . V_10 ;
if ( V_7 ) {
unsigned int V_11 ;
switch ( V_7 -> type ) {
case V_12 :
V_11 = V_7 -> integer . V_1 ;
F_4 ( V_13 ,
V_11 , 1 , true ) ;
break;
case V_14 :
if ( V_7 -> V_15 . V_10 && V_7 -> V_15 . V_16 > 0 ) {
V_11 = V_7 -> V_15 . V_10 [ 0 ] ;
F_4 (
V_13 ,
V_11 , 1 , true ) ;
}
break;
}
}
F_5 ( V_7 ) ;
}
static int T_3 F_6 ( void )
{
int V_17 ;
V_13 = F_7 () ;
if ( ! V_13 )
return - V_18 ;
V_13 -> V_19 = L_2 ;
V_13 -> V_20 = L_3 ;
V_13 -> V_21 . V_22 = V_23 ;
V_17 = F_8 ( V_13 ,
V_24 , NULL ) ;
if ( V_17 ) {
F_9 ( L_4 ) ;
goto V_25;
}
V_17 = F_10 ( V_13 ) ;
if ( V_17 ) {
F_3 ( L_5 ) ;
goto V_26;
}
return 0 ;
V_26:
F_11 ( V_13 ) ;
V_25:
F_12 ( V_13 ) ;
return V_17 ;
}
static const char * F_13 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_28 [ V_27 ] != NULL ; V_27 ++ )
if ( F_14 ( V_28 [ V_27 ] ) )
return V_28 [ V_27 ] ;
return NULL ;
}
static int T_3 F_15 ( void )
{
int V_17 ;
const char * V_29 ;
V_29 = F_13 () ;
if ( ! V_29 ) {
F_16 ( L_6 ) ;
return - V_30 ;
}
V_17 = F_6 () ;
if ( V_17 )
return V_17 ;
V_17 = F_17 ( V_29 , F_1 , NULL ) ;
if ( V_17 ) {
F_9 ( L_7 , V_17 ) ;
F_11 ( V_13 ) ;
F_18 ( V_13 ) ;
return V_17 ;
}
return 0 ;
}
static void T_4 F_19 ( void )
{
const char * V_29 ;
V_29 = F_13 () ;
F_20 ( V_29 ) ;
F_11 ( V_13 ) ;
F_18 ( V_13 ) ;
}
