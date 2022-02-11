static bool F_1 ( T_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
if ( V_4 == NULL || V_2 < 6 )
return false ;
if ( ( V_4 -> type == 0 || V_4 -> type == 0xf ) &&
V_4 -> V_2 >= 2 )
return true ;
return false ;
}
static void F_2 ( T_2 V_5 , void * V_6 )
{
struct V_7 V_8 = { V_9 , NULL } ;
union V_10 * V_11 ;
struct V_3 * V_4 ;
T_3 V_12 ;
V_12 = F_3 ( V_5 , & V_8 ) ;
if ( V_12 != V_13 ) {
F_4 ( L_1 , V_12 ) ;
return;
}
V_11 = (union V_10 * ) V_8 . V_14 ;
if ( V_11 ) {
unsigned int V_15 = 0 ;
switch ( V_11 -> type ) {
case V_16 :
V_15 = V_11 -> integer . V_5 ;
F_5 ( V_17 ,
V_15 , 1 , true ) ;
break;
case V_18 :
if ( F_1 ( V_11 -> V_1 . V_14 ,
V_11 -> V_1 . V_2 ) ) {
V_4 = (struct V_3 * )
V_11 -> V_1 . V_14 ;
V_15 = V_4 -> V_4 [ 0 ] ;
} else {
if ( V_11 -> V_1 . V_14 &&
V_11 -> V_1 . V_2 > 0 )
V_15 = V_11 -> V_1 . V_14 [ 0 ] ;
}
if ( V_15 )
F_5 (
V_17 ,
V_15 , 1 , true ) ;
break;
}
}
F_6 ( V_11 ) ;
}
static int T_4 F_7 ( void )
{
int V_19 ;
V_17 = F_8 () ;
if ( ! V_17 )
return - V_20 ;
V_17 -> V_21 = L_2 ;
V_17 -> V_22 = L_3 ;
V_17 -> V_23 . V_24 = V_25 ;
V_19 = F_9 ( V_17 ,
V_26 , NULL ) ;
if ( V_19 ) {
F_10 ( L_4 ) ;
goto V_27;
}
V_19 = F_11 ( V_17 ) ;
if ( V_19 ) {
F_4 ( L_5 ) ;
goto V_27;
}
return 0 ;
V_27:
F_12 ( V_17 ) ;
return V_19 ;
}
static const char * F_13 ( void )
{
int V_28 ;
for ( V_28 = 0 ; V_29 [ V_28 ] != NULL ; V_28 ++ )
if ( F_14 ( V_29 [ V_28 ] ) )
return V_29 [ V_28 ] ;
return NULL ;
}
static int T_4 F_15 ( void )
{
int V_19 ;
const char * V_30 ;
V_30 = F_13 () ;
if ( ! V_30 ) {
F_16 ( L_6 ) ;
return - V_31 ;
}
V_19 = F_7 () ;
if ( V_19 )
return V_19 ;
V_19 = F_17 ( V_30 , F_2 , NULL ) ;
if ( V_19 ) {
F_10 ( L_7 , V_19 ) ;
F_18 ( V_17 ) ;
return V_19 ;
}
return 0 ;
}
static void T_5 F_19 ( void )
{
const char * V_30 ;
V_30 = F_13 () ;
F_20 ( V_30 ) ;
F_18 ( V_17 ) ;
}
