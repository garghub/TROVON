static int T_1 F_1 ( void )
{
static const char * V_1 [] = V_2 ;
const char * * type ;
const char * V_3 = 0 ;
int V_4 ;
static struct { T_2 V_5 ; T_2 V_6 ; } V_7 [ V_8 ] = {
{ V_9 , V_10 } ,
{ V_11 , V_12 } ,
} ;
int V_13 = 0 ;
for( V_4 = 0 ; V_4 < V_8 ; V_4 ++ )
{
F_2 (KERN_NOTICE MSG_PREFIX L_1 ,
pt[i].size, pt[i].addr) ;
V_14 [ V_4 ] . V_15 = V_7 [ V_4 ] . V_5 ;
V_14 [ V_4 ] . V_16 = F_3 ( V_7 [ V_4 ] . V_5 , V_7 [ V_4 ] . V_6 ) ;
if ( ! V_14 [ V_4 ] . V_16 ) {
F_2 ( V_17 L_2 ) ;
return - V_18 ;
}
F_4 ( & V_14 [ V_4 ] ) ;
V_19 [ V_4 ] = 0 ;
type = V_1 ;
for(; ! V_19 [ V_4 ] && * type ; type ++ ) {
V_19 [ V_4 ] = F_5 ( * type , & V_14 [ V_4 ] ) ;
}
if ( V_19 [ V_4 ] ) {
V_19 [ V_4 ] -> V_20 = V_21 ;
V_13 ++ ;
V_22 [ V_4 ] = F_6 ( V_19 [ V_4 ] ,
V_23 ,
& V_24 [ V_4 ] ,
0 ) ;
if ( V_22 [ V_4 ] > 0 ) {
V_3 = L_3 ;
} else {
V_24 [ V_4 ] = V_25 ;
V_22 [ V_4 ] = F_7 ( V_25 ) ;
V_3 = L_4 ;
}
F_2 (KERN_NOTICE MSG_PREFIX
L_5 ,
part_type) ;
F_8 ( V_19 [ V_4 ] ,
V_24 [ V_4 ] , V_22 [ V_4 ] ) ;
}
else
F_9 ( ( void * ) V_14 [ V_4 ] . V_16 ) ;
}
return V_13 == 0 ? - V_26 : 0 ;
}
static void T_3 F_10 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ ) {
if ( V_19 [ V_4 ] ) {
F_11 ( V_19 [ V_4 ] ) ;
F_12 ( V_19 [ V_4 ] ) ;
F_9 ( ( void * ) V_14 [ V_4 ] . V_16 ) ;
V_14 [ V_4 ] . V_16 = 0 ;
}
}
}
