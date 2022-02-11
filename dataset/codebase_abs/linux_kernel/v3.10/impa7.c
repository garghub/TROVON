static int T_1 F_1 ( void )
{
const char * const * type ;
int V_1 ;
static struct { T_2 V_2 ; T_2 V_3 ; } V_4 [ V_5 ] = {
{ V_6 , V_7 } ,
{ V_8 , V_9 } ,
} ;
int V_10 = 0 ;
for( V_1 = 0 ; V_1 < V_5 ; V_1 ++ )
{
F_2 (KERN_NOTICE MSG_PREFIX L_1 ,
pt[i].size, pt[i].addr) ;
V_11 [ V_1 ] . V_12 = V_4 [ V_1 ] . V_2 ;
V_11 [ V_1 ] . V_13 = F_3 ( V_4 [ V_1 ] . V_2 , V_4 [ V_1 ] . V_3 ) ;
if ( ! V_11 [ V_1 ] . V_13 ) {
F_2 ( V_14 L_2 ) ;
return - V_15 ;
}
F_4 ( & V_11 [ V_1 ] ) ;
V_16 [ V_1 ] = 0 ;
type = V_17 ;
for(; ! V_16 [ V_1 ] && * type ; type ++ ) {
V_16 [ V_1 ] = F_5 ( * type , & V_11 [ V_1 ] ) ;
}
if ( V_16 [ V_1 ] ) {
V_16 [ V_1 ] -> V_18 = V_19 ;
V_10 ++ ;
F_6 ( V_16 [ V_1 ] , NULL , NULL ,
V_20 ,
F_7 ( V_20 ) ) ;
}
else
F_8 ( ( void * ) V_11 [ V_1 ] . V_13 ) ;
}
return V_10 == 0 ? - V_21 : 0 ;
}
static void T_3 F_9 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_5 ; V_1 ++ ) {
if ( V_16 [ V_1 ] ) {
F_10 ( V_16 [ V_1 ] ) ;
F_11 ( V_16 [ V_1 ] ) ;
F_8 ( ( void * ) V_11 [ V_1 ] . V_13 ) ;
V_11 [ V_1 ] . V_13 = 0 ;
}
}
}
