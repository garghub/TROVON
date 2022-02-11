static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 ;
void T_1 * V_6 ;
T_2 V_7 , V_8 ;
char * V_9 ;
int V_10 ;
V_5 = F_2 ( V_2 , struct V_4 , V_5 ) ;
V_6 = V_5 -> V_6 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
F_4 ( V_5 -> V_12 [ V_10 ] ) ;
}
if ( ! V_3 ) {
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_13 [ V_10 ] ) )
break;
if ( F_5 ( V_5 -> V_13 [ V_10 ] , V_5 -> V_14 ) )
F_6 ( L_1 ,
V_5 -> V_15 , V_10 ) ;
}
}
V_8 = V_3 ? V_16 : 0 ;
F_7 ( V_8 , V_6 ) ;
V_7 = 10 ;
while ( ( F_8 ( V_6 + 0x4 ) & V_16 ) != V_8 ) {
if ( ! V_7 ) {
V_9 = ( V_3 ) ? L_2 : L_3 ;
F_6 ( L_4 , V_2 -> V_15 , V_9 ) ;
return - V_17 ;
}
V_7 -- ;
F_9 () ;
F_10 ( 80 , 100 ) ;
}
if ( V_3 ) {
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_13 [ V_10 ] ) )
break;
if ( F_5 ( V_5 -> V_13 [ V_10 ] , V_5 -> V_18 [ V_10 ] ) )
F_6 ( L_5 ,
V_5 -> V_15 , V_10 ) ;
}
}
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
F_11 ( V_5 -> V_12 [ V_10 ] ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , false ) ;
}
static T_3 int F_14 ( void )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
F_15 (np, NULL, L_6 ) {
struct V_4 * V_5 ;
int V_23 , V_10 ;
struct V_24 * V_25 ;
V_20 = F_16 ( V_22 ) ;
V_25 = & V_20 -> V_25 ;
V_5 = F_17 ( sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 ) {
F_6 ( L_7 ,
V_27 ) ;
return - V_28 ;
}
V_5 -> V_5 . V_15 = F_18 ( F_19 ( V_25 ) , V_26 ) ;
V_5 -> V_15 = V_5 -> V_5 . V_15 ;
V_5 -> V_6 = F_20 ( V_22 , 0 ) ;
V_5 -> V_5 . V_29 = F_13 ;
V_5 -> V_5 . V_3 = F_12 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
char V_30 [ 8 ] ;
snprintf ( V_30 , sizeof( V_30 ) , L_8 , V_10 ) ;
V_5 -> V_12 [ V_10 ] = F_21 ( V_25 , V_30 ) ;
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
}
V_5 -> V_14 = F_21 ( V_25 , L_9 ) ;
if ( F_3 ( V_5 -> V_14 ) )
goto V_31;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
char V_30 [ 8 ] ;
snprintf ( V_30 , sizeof( V_30 ) , L_10 , V_10 ) ;
V_5 -> V_13 [ V_10 ] = F_21 ( V_25 , V_30 ) ;
if ( F_3 ( V_5 -> V_13 [ V_10 ] ) )
break;
snprintf ( V_30 , sizeof( V_30 ) , L_11 , V_10 ) ;
V_5 -> V_18 [ V_10 ] = F_21 ( V_25 , V_30 ) ;
if ( F_3 ( V_5 -> V_18 [ V_10 ] ) ) {
F_22 ( V_5 -> V_13 [ V_10 ] ) ;
V_5 -> V_13 [ V_10 ] = F_23 ( - V_32 ) ;
break;
}
}
if ( F_3 ( V_5 -> V_13 [ 0 ] ) )
F_22 ( V_5 -> V_14 ) ;
V_31:
V_23 = F_8 ( V_5 -> V_6 + 0x4 ) & V_16 ;
F_24 ( & V_5 -> V_5 , NULL , ! V_23 ) ;
F_25 ( V_22 , & V_5 -> V_5 ) ;
}
F_15 (np, NULL, L_6 ) {
struct V_1 * V_33 , * V_34 ;
struct V_35 args ;
args . V_22 = V_22 ;
args . V_36 = 0 ;
V_33 = F_26 ( & args ) ;
if ( F_3 ( V_33 ) )
continue;
if ( F_27 ( V_22 , L_12 ,
L_13 , 0 , & args ) != 0 )
continue;
V_34 = F_26 ( & args ) ;
if ( F_3 ( V_34 ) )
continue;
if ( F_28 ( V_34 , V_33 ) )
F_29 ( L_14 ,
V_34 -> V_15 , V_33 -> V_15 ) ;
else
F_30 ( L_15 ,
V_34 -> V_15 , V_33 -> V_15 ) ;
F_31 ( V_22 ) ;
}
return 0 ;
}
