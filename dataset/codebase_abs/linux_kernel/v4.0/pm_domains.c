static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 ;
void T_1 * V_6 ;
T_2 V_7 , V_8 ;
char * V_9 ;
V_5 = F_2 ( V_2 , struct V_4 , V_5 ) ;
V_6 = V_5 -> V_6 ;
if ( ! V_3 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
if ( F_4 ( V_5 -> V_12 [ V_10 ] , V_5 -> V_13 ) )
F_5 ( L_1 ,
V_5 -> V_14 , V_10 ) ;
}
}
V_8 = V_3 ? V_15 : 0 ;
F_6 ( V_8 , V_6 ) ;
V_7 = 10 ;
while ( ( F_7 ( V_6 + 0x4 ) & V_15 ) != V_8 ) {
if ( ! V_7 ) {
V_9 = ( V_3 ) ? L_2 : L_3 ;
F_5 ( L_4 , V_2 -> V_14 , V_9 ) ;
return - V_16 ;
}
V_7 -- ;
F_8 () ;
F_9 ( 80 , 100 ) ;
}
if ( V_3 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
if ( F_4 ( V_5 -> V_12 [ V_10 ] , V_5 -> V_17 [ V_10 ] ) )
F_5 ( L_5 ,
V_5 -> V_14 , V_10 ) ;
}
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , false ) ;
}
static T_3 int F_12 ( void )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
F_13 (np, NULL, L_6 ) {
struct V_4 * V_5 ;
int V_22 , V_10 ;
struct V_23 * V_24 ;
V_19 = F_14 ( V_21 ) ;
V_24 = & V_19 -> V_24 ;
V_5 = F_15 ( sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 ) {
F_5 ( L_7 ,
V_26 ) ;
return - V_27 ;
}
V_5 -> V_5 . V_14 = F_16 ( V_21 -> V_14 , V_25 ) ;
V_5 -> V_14 = V_5 -> V_5 . V_14 ;
V_5 -> V_6 = F_17 ( V_21 , 0 ) ;
V_5 -> V_5 . V_28 = F_11 ;
V_5 -> V_5 . V_3 = F_10 ;
V_5 -> V_13 = F_18 ( V_24 , L_8 ) ;
if ( F_3 ( V_5 -> V_13 ) )
goto V_29;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
char V_30 [ 8 ] ;
snprintf ( V_30 , sizeof( V_30 ) , L_9 , V_10 ) ;
V_5 -> V_12 [ V_10 ] = F_18 ( V_24 , V_30 ) ;
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
snprintf ( V_30 , sizeof( V_30 ) , L_10 , V_10 ) ;
V_5 -> V_17 [ V_10 ] = F_18 ( V_24 , V_30 ) ;
if ( F_3 ( V_5 -> V_17 [ V_10 ] ) ) {
F_19 ( V_5 -> V_12 [ V_10 ] ) ;
V_5 -> V_12 [ V_10 ] = F_20 ( - V_31 ) ;
break;
}
}
if ( F_3 ( V_5 -> V_12 [ 0 ] ) )
F_19 ( V_5 -> V_13 ) ;
V_29:
V_22 = F_7 ( V_5 -> V_6 + 0x4 ) & V_15 ;
F_21 ( & V_5 -> V_5 , NULL , ! V_22 ) ;
F_22 ( V_21 , & V_5 -> V_5 ) ;
}
F_13 (np, NULL, L_6 ) {
struct V_1 * V_32 , * V_33 ;
struct V_34 args ;
args . V_21 = V_21 ;
args . V_35 = 0 ;
V_32 = F_23 ( & args ) ;
if ( ! V_32 )
continue;
if ( F_24 ( V_21 , L_11 ,
L_12 , 0 , & args ) != 0 )
continue;
V_33 = F_23 ( & args ) ;
if ( ! V_33 )
continue;
if ( F_25 ( V_33 , V_32 ) )
F_26 ( L_13 ,
V_33 -> V_14 , V_32 -> V_14 ) ;
else
F_27 ( L_14 ,
V_33 -> V_14 , V_32 -> V_14 ) ;
F_28 ( V_21 ) ;
}
return 0 ;
}
