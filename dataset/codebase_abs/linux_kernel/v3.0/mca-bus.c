static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
const unsigned short * V_9 = V_8 -> V_10 ;
int V_11 = 0 ;
if ( V_9 ) {
for( V_11 = 0 ; V_9 [ V_11 ] ; V_11 ++ ) {
if ( V_9 [ V_11 ] == V_6 -> V_12 ) {
V_6 -> V_13 = V_11 ;
return 1 ;
}
}
}
if ( V_8 -> V_14 && V_6 -> V_12 ==
V_8 -> V_14 ) {
V_6 -> V_13 = V_11 ;
return 1 ;
}
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_15 * V_16 , char * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_18 ;
if( V_6 -> V_12 < V_19 )
V_18 = sprintf ( V_17 , L_1 , V_6 -> V_12 ) ;
else
V_18 = sprintf ( V_17 , L_2 ) ;
return V_18 ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_15 * V_16 , char * V_17 )
{
int V_20 , V_18 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
for( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
V_18 += sprintf ( V_17 + V_18 , L_3 , V_6 -> V_21 [ V_20 ] ) ;
V_17 [ V_18 - 1 ] = '\n' ;
return V_18 ;
}
int T_2 F_6 ( int V_22 , struct V_5 * V_6 )
{
struct V_23 * V_23 = V_24 [ V_22 ] ;
int V_25 ;
V_6 -> V_2 . V_26 = & V_23 -> V_2 ;
V_6 -> V_2 . V_22 = & V_27 ;
F_7 ( & V_6 -> V_2 , L_4 , V_22 , V_6 -> V_28 ) ;
V_6 -> V_29 = V_23 -> V_30 ;
V_6 -> V_2 . V_29 = & V_6 -> V_29 ;
V_6 -> V_2 . V_31 = V_6 -> V_29 ;
V_25 = F_8 ( & V_6 -> V_2 ) ;
if ( V_25 )
goto V_32;
V_25 = F_9 ( & V_6 -> V_2 , & V_33 ) ;
if ( V_25 ) goto V_34;
V_25 = F_9 ( & V_6 -> V_2 , & V_35 ) ;
if ( V_25 ) goto V_36;
return 1 ;
V_36:
F_10 ( & V_6 -> V_2 , & V_33 ) ;
V_34:
F_11 ( & V_6 -> V_2 ) ;
V_32:
return 0 ;
}
struct V_23 * T_3 F_12 ( int V_22 )
{
struct V_23 * V_23 ;
if ( F_13 ( V_24 [ V_22 ] != NULL ) ) {
F_14 ( V_37 L_5 ,
V_22 ) ;
F_15 () ;
return NULL ;
}
V_23 = F_16 ( sizeof( struct V_23 ) , V_38 ) ;
if ( ! V_23 )
return NULL ;
F_7 ( & V_23 -> V_2 , L_6 , V_22 ) ;
sprintf ( V_23 -> V_39 , L_7 , V_22 ? L_8 : L_9 ) ;
if ( F_8 ( & V_23 -> V_2 ) ) {
F_17 ( V_23 ) ;
return NULL ;
}
V_24 [ V_22 ] = V_23 ;
return V_23 ;
}
int T_2 F_18 ( void )
{
return F_19 ( & V_27 ) ;
}
