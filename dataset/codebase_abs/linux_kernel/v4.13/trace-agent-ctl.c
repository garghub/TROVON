static void F_1 ( int V_1 )
{
V_2 = V_1 ;
}
int F_2 ( const char * V_3 )
{
int V_4 ;
V_4 = F_3 ( V_3 , V_5 ) ;
if ( V_4 == - 1 ) {
F_4 ( L_1 ) ;
goto error;
}
return V_4 ;
error:
exit ( V_6 ) ;
}
static int F_5 ( int V_4 )
{
struct V_7 V_8 ;
int V_9 = 0 ;
while ( ! V_10 ) {
V_8 . V_11 = V_4 ;
V_8 . V_12 = V_13 ;
V_9 = F_6 ( & V_8 , 1 , V_14 ) ;
if ( V_2 ) {
V_10 = true ;
F_7 ( L_2 , V_2 ) ;
if ( ! V_15 )
F_8 ( & V_16 ) ;
V_9 = - 1 ;
break;
}
if ( V_9 < 0 ) {
F_4 ( L_3 ) ;
goto error;
}
if ( V_9 )
break;
} ;
return V_9 ;
error:
exit ( V_6 ) ;
}
void * F_9 ( int V_4 )
{
T_1 V_17 ;
char V_18 [ V_19 ] ;
int V_9 ;
signal ( V_20 , F_1 ) ;
signal ( V_21 , F_1 ) ;
signal ( V_22 , F_1 ) ;
while ( ! V_10 ) {
V_9 = F_5 ( V_4 ) ;
if ( V_9 < 0 )
break;
V_17 = F_10 ( V_4 , V_18 , sizeof( V_18 ) ) ;
if ( V_17 < 0 ) {
F_4 ( L_4 ) ;
goto error;
}
if ( V_17 == 2 && V_18 [ 0 ] == '1' ) {
V_15 = true ;
F_8 ( & V_16 ) ;
F_11 ( L_5 ) ;
} else if ( V_17 == 2 && V_18 [ 0 ] == '0' ) {
V_15 = false ;
F_11 ( L_6 ) ;
} else
F_7 ( L_7 , V_18 ) ;
}
return NULL ;
error:
exit ( V_6 ) ;
}
