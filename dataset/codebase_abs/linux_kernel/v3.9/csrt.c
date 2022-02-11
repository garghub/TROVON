static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 V_8 [ 3 ] ;
T_2 V_9 ;
int V_10 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_9 = 0 ;
V_6 = ( const struct V_5 * ) & V_4 [ 1 ] ;
if ( ! V_6 -> V_11 && V_6 -> V_12 ) {
V_8 [ V_9 ] . V_13 = V_6 -> V_12 ;
V_8 [ V_9 ] . V_14 = V_8 [ 0 ] . V_13 + V_15 - 1 ;
V_8 [ V_9 ++ ] . V_16 = V_17 ;
}
if ( V_6 -> V_18 ) {
int V_19 = F_2 ( NULL , V_6 -> V_18 ,
V_6 -> V_20 ,
V_6 -> V_21 ) ;
V_8 [ V_9 ] . V_13 = V_19 ;
V_8 [ V_9 ] . V_14 = V_19 ;
V_8 [ V_9 ++ ] . V_16 = V_22 ;
}
if ( V_6 -> V_23 || V_6 -> V_24 ) {
V_8 [ V_9 ] . V_13 = V_6 -> V_23 ;
V_8 [ V_9 ] . V_14 = V_8 [ V_9 ] . V_13 + V_6 -> V_24 - 1 ;
V_8 [ V_9 ++ ] . V_16 = V_25 ;
}
V_10 = F_3 ( V_2 , V_8 , V_9 ) ;
if ( V_10 ) {
if ( V_6 -> V_18 )
F_4 ( V_6 -> V_18 ) ;
return V_10 ;
}
return 0 ;
}
static int T_1
F_5 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
char V_26 [ 5 ] , V_27 [ 16 ] ;
int V_10 , V_28 ;
V_26 [ 0 ] = V_4 -> V_29 ;
V_26 [ 1 ] = V_4 -> V_29 >> 8 ;
V_26 [ 2 ] = V_4 -> V_29 >> 16 ;
V_26 [ 3 ] = V_4 -> V_29 >> 24 ;
V_26 [ 4 ] = '\0' ;
if ( V_4 -> V_30 != sizeof( struct V_5 ) )
return - V_31 ;
snprintf ( V_27 , sizeof( V_27 ) , L_1 , V_26 , V_4 -> V_32 ) ;
V_2 = F_6 ( V_27 , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_10 = F_1 ( V_2 , V_4 ) ;
if ( V_10 )
goto V_35;
V_10 = F_7 ( V_2 ) ;
if ( V_10 )
goto V_35;
for ( V_28 = 0 ; V_28 < V_2 -> V_36 ; V_28 ++ )
F_8 ( & V_2 -> V_37 , L_2 , & V_2 -> V_7 [ V_28 ] ) ;
return 0 ;
V_35:
F_9 ( V_2 ) ;
return V_10 ;
}
void T_1 F_10 ( void )
{
struct V_3 * V_4 , * V_14 ;
struct V_38 * V_39 ;
T_3 V_40 ;
int V_10 ;
V_40 = F_11 ( V_41 , 0 ,
(struct V_42 * * ) & V_39 ) ;
if ( F_12 ( V_40 ) ) {
if ( V_40 != V_43 )
F_13 ( L_3 ) ;
return;
}
F_14 ( L_4 ) ;
V_4 = (struct V_3 * ) ( V_39 + 1 ) ;
V_14 = (struct V_3 * ) ( ( void * ) V_39 + V_39 -> V_44 . V_45 ) ;
while ( V_4 < V_14 ) {
V_10 = F_5 ( V_4 ) ;
if ( V_10 ) {
F_13 ( L_5 , V_10 ) ;
return;
}
V_4 = (struct V_3 * ) ( ( void * ) V_4 + V_4 -> V_45 ) ;
}
}
