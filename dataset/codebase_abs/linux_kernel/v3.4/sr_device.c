static void T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 = 0 ;
while ( V_2 [ V_8 ] . V_9 )
V_8 ++ ;
V_6 = F_2 ( sizeof( struct V_5 ) * V_8 ,
V_10 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
T_2 V_11 ;
if ( F_3 () ) {
T_3 V_12 = V_2 [ V_7 ] . V_13 ;
V_11 = F_4 ( V_12 ) |
F_4 ( V_12 + 1 ) << 8 |
F_4 ( V_12 + 2 ) << 16 ;
} else {
V_11 = F_5 ( V_2 [ V_7 ] . V_13 ) ;
}
V_6 [ V_7 ] . V_14 = V_2 [ V_7 ] . V_13 ;
V_6 [ V_7 ] . V_15 = V_11 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_16 = V_8 ;
}
static int T_1 F_6 ( struct V_17 * V_18 , void * V_19 )
{
struct V_3 * V_4 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
char * V_24 = L_1 ;
static int V_7 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_10 ) ;
if ( ! V_4 ) {
F_7 ( L_2 ,
V_25 , V_18 -> V_24 ) ;
return - V_26 ;
}
V_23 = (struct V_22 * ) V_18 -> V_27 ;
if ( ! V_23 || ! V_23 -> V_28 ) {
F_7 ( L_3
L_4 , V_25 ,
V_18 -> V_24 ) ;
goto exit;
}
V_4 -> V_29 = V_18 -> V_30 -> V_31 ;
V_4 -> V_32 = 0x1 ;
V_4 -> V_33 = 0x1 ;
V_4 -> V_34 = F_8 ( V_23 -> V_28 ) ;
if ( F_9 ( V_4 -> V_34 ) ) {
F_7 ( L_5 ,
V_25 , V_23 -> V_28 ) ;
goto exit;
}
F_10 ( V_4 -> V_34 , & V_2 ) ;
if ( ! V_2 ) {
F_11 ( L_6
L_7 , V_25 , V_7 + 1 ) ;
goto exit;
}
F_1 ( V_2 , V_4 ) ;
V_4 -> V_35 = V_36 ;
V_21 = F_12 ( V_24 , V_7 , V_18 , V_4 , sizeof( * V_4 ) ,
NULL , 0 , 0 ) ;
if ( F_9 ( V_21 ) )
F_11 ( L_8 ,
V_25 , V_24 , V_18 -> V_24 ) ;
exit:
V_7 ++ ;
F_13 ( V_4 ) ;
return 0 ;
}
void T_1 F_14 ( void )
{
V_36 = true ;
}
int T_1 F_15 ( void )
{
return F_16 ( L_1 , F_6 , NULL ) ;
}
