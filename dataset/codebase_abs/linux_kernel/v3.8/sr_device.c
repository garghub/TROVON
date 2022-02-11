static void T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 , V_9 = 0 ;
V_4 -> V_10 = 0 ;
V_4 -> V_6 = NULL ;
while ( V_2 [ V_9 ] . V_11 )
V_9 ++ ;
V_6 = F_2 ( sizeof( struct V_5 ) * V_9 ,
V_12 ) ;
if ( ! V_6 ) {
F_3 ( L_1 ) ;
return;
}
for ( V_7 = 0 , V_8 = 0 ; V_7 < V_9 ; V_7 ++ ) {
T_2 V_13 ;
if ( F_4 () ) {
T_3 V_14 = V_2 [ V_7 ] . V_15 ;
V_13 = F_5 ( V_14 ) |
F_5 ( V_14 + 1 ) << 8 |
F_5 ( V_14 + 2 ) << 16 ;
} else {
V_13 = F_6 ( V_2 [ V_7 ] . V_15 ) ;
}
if ( V_13 == 0 )
continue;
V_6 [ V_8 ] . V_16 = V_13 ;
V_6 [ V_8 ] . V_17 = V_2 [ V_7 ] . V_15 ;
V_6 [ V_8 ] . V_18 = V_2 [ V_7 ] . V_19 ;
V_6 [ V_8 ] . V_11 = V_2 [ V_7 ] . V_11 ;
V_8 ++ ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_10 = V_8 ;
}
static int T_1 F_7 ( struct V_20 * V_21 , void * V_22 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
char * V_27 = L_2 ;
static int V_7 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_12 ) ;
if ( ! V_4 ) {
F_3 ( L_3 ,
V_28 , V_21 -> V_27 ) ;
return - V_29 ;
}
V_26 = (struct V_25 * ) V_21 -> V_30 ;
if ( ! V_26 || ! V_26 -> V_31 ) {
F_3 ( L_4 ,
V_28 , V_21 -> V_27 ) ;
goto exit;
}
V_4 -> V_27 = V_21 -> V_27 ;
V_4 -> V_32 = V_21 -> V_33 -> V_34 ;
V_4 -> V_35 = 0x1 ;
V_4 -> V_36 = 0x1 ;
if ( F_8 () || F_4 () ) {
V_4 -> V_37 = V_38 ;
V_4 -> V_39 = V_40 ;
V_4 -> V_41 = V_42 ;
if ( ! ( strcmp ( V_4 -> V_27 , L_5 ) ) ) {
V_4 -> V_43 = V_44 ;
V_4 -> V_45 = V_46 ;
} else {
V_4 -> V_43 = V_47 ;
V_4 -> V_45 = V_48 ;
}
}
V_4 -> V_49 = F_9 ( V_26 -> V_31 ) ;
if ( ! V_4 -> V_49 ) {
F_3 ( L_6 ,
V_28 , V_26 -> V_31 ) ;
goto exit;
}
F_10 ( V_4 -> V_49 , & V_2 ) ;
if ( ! V_2 ) {
F_3 ( L_7 ,
V_28 , V_7 + 1 ) ;
goto exit;
}
F_1 ( V_2 , V_4 ) ;
V_4 -> V_50 = V_51 ;
V_24 = F_11 ( V_27 , V_7 , V_21 , V_4 , sizeof( * V_4 ) ,
NULL , 0 , 0 ) ;
if ( F_12 ( V_24 ) )
F_13 ( L_8 ,
V_28 , V_27 , V_21 -> V_27 ) ;
exit:
V_7 ++ ;
F_14 ( V_4 ) ;
return 0 ;
}
void T_1 F_15 ( void )
{
V_51 = true ;
}
int T_1 F_16 ( void )
{
return F_17 ( L_2 , F_7 , NULL ) ;
}
