static int T_1 F_1 ( const void * V_1 , const void * V_2 )
{
const struct V_3 * V_4 = V_1 ;
const struct V_3 * V_5 = V_2 ;
if ( V_4 -> V_6 . V_7 < V_5 -> V_6 . V_7 )
return - 1 ;
if ( V_4 -> V_6 . V_7 > V_5 -> V_6 . V_7 )
return 1 ;
return 0 ;
}
void T_1 F_2 ( void )
{
int V_8 = V_9 . V_10 . V_11 ;
T_2 * V_12 ;
T_3 V_13 ;
void * V_14 ;
int V_15 ;
if ( ! V_16 )
return;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
F_3 (md) {
struct V_6 * V_17 = & V_18 [ V_15 ] . V_6 ;
V_8 += F_4 ( V_12 , V_17 ) ;
}
}
V_13 = F_5 ( V_8 ) ;
if ( ! V_13 )
return;
V_14 = F_6 ( V_13 ,
V_9 . V_10 . V_19 * V_8 ) ;
if ( ! V_14 ) {
F_7 ( V_13 , V_9 . V_10 . V_19 * V_8 ) ;
return;
}
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_8 ( & V_9 . V_10 , V_14 , & V_18 [ V_15 ] ) ;
F_9 ( V_14 , V_9 . V_10 . V_19 * V_8 ) ;
F_10 ( V_13 , V_8 ) ;
F_11 () ;
}
static int T_1 F_12 ( char * V_20 )
{
T_4 V_7 = 0 , V_21 = 0 , V_22 = 0 ;
int V_15 ;
if ( ! V_20 )
return - V_23 ;
while ( * V_20 != '\0' ) {
V_21 = F_13 ( V_20 , & V_20 ) ;
if ( * V_20 == '@' )
V_7 = F_13 ( V_20 + 1 , & V_20 ) ;
else
break;
if ( * V_20 == ':' )
V_22 = F_14 ( V_20 + 1 , & V_20 , 0 ) ;
else
break;
if ( V_16 >= V_24 )
break;
V_18 [ V_16 ] . V_6 . V_7 = V_7 ;
V_18 [ V_16 ] . V_6 . V_25 = V_7 + V_21 - 1 ;
V_18 [ V_16 ] . V_22 = V_22 ;
V_16 ++ ;
if ( * V_20 == ',' )
V_20 ++ ;
}
F_15 ( V_18 , V_16 , sizeof( struct V_3 ) ,
F_1 , NULL ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_16 ( L_1 ,
V_18 [ V_15 ] . V_22 , V_18 [ V_15 ] . V_6 . V_7 ,
V_18 [ V_15 ] . V_6 . V_25 ) ;
return * V_20 == '\0' ? 0 : - V_23 ;
}
