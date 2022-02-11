static int T_1 F_1 ( void )
{
static const char * V_1 [] = V_2 ;
const char * * type ;
int V_3 ;
static struct { T_2 V_4 ; T_2 V_5 ; } V_6 [ V_7 ] = {
{ V_8 , V_9 } ,
{ V_10 , V_11 } ,
} ;
int V_12 = 0 ;
for( V_3 = 0 ; V_3 < V_7 ; V_3 ++ )
{
F_2 (KERN_NOTICE MSG_PREFIX L_1 ,
pt[i].size, pt[i].addr) ;
V_13 [ V_3 ] . V_14 = V_6 [ V_3 ] . V_4 ;
V_13 [ V_3 ] . V_15 = F_3 ( V_6 [ V_3 ] . V_4 , V_6 [ V_3 ] . V_5 ) ;
if ( ! V_13 [ V_3 ] . V_15 ) {
F_2 ( V_16 L_2 ) ;
return - V_17 ;
}
F_4 ( & V_13 [ V_3 ] ) ;
V_18 [ V_3 ] = 0 ;
type = V_1 ;
for(; ! V_18 [ V_3 ] && * type ; type ++ ) {
V_18 [ V_3 ] = F_5 ( * type , & V_13 [ V_3 ] ) ;
}
if ( V_18 [ V_3 ] ) {
V_18 [ V_3 ] -> V_19 = V_20 ;
V_12 ++ ;
F_6 ( V_18 [ V_3 ] , NULL , NULL ,
V_21 ,
F_7 ( V_21 ) ) ;
}
else
F_8 ( ( void * ) V_13 [ V_3 ] . V_15 ) ;
}
return V_12 == 0 ? - V_22 : 0 ;
}
static void T_3 F_9 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_18 [ V_3 ] ) {
F_10 ( V_18 [ V_3 ] ) ;
F_11 ( V_18 [ V_3 ] ) ;
F_8 ( ( void * ) V_13 [ V_3 ] . V_15 ) ;
V_13 [ V_3 ] . V_15 = 0 ;
}
}
}
