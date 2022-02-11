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
V_5 -> V_14 [ V_10 ] = F_5 ( V_5 -> V_13 [ V_10 ] ) ;
if ( F_6 ( V_5 -> V_13 [ V_10 ] , V_5 -> V_15 ) )
F_7 ( L_1 ,
V_5 -> V_16 , V_10 ) ;
}
}
V_8 = V_3 ? V_17 : 0 ;
F_8 ( V_8 , V_6 ) ;
V_7 = 10 ;
while ( ( F_9 ( V_6 + 0x4 ) & V_17 ) != V_8 ) {
if ( ! V_7 ) {
V_9 = ( V_3 ) ? L_2 : L_3 ;
F_7 ( L_4 , V_2 -> V_16 , V_9 ) ;
return - V_18 ;
}
V_7 -- ;
F_10 () ;
F_11 ( 80 , 100 ) ;
}
if ( V_3 ) {
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_13 [ V_10 ] ) )
break;
if ( F_3 ( V_5 -> V_13 [ V_10 ] ) )
continue;
if ( F_6 ( V_5 -> V_13 [ V_10 ] , V_5 -> V_14 [ V_10 ] ) )
F_7 ( L_5 ,
V_5 -> V_16 , V_10 ) ;
}
}
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
F_12 ( V_5 -> V_12 [ V_10 ] ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , false ) ;
}
static T_3 int F_15 ( void )
{
struct V_19 * V_20 ;
F_16 (np, NULL, L_6 ) {
struct V_4 * V_5 ;
int V_21 , V_10 ;
V_5 = F_17 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 ) {
F_7 ( L_7 ,
V_23 ) ;
F_18 ( V_20 ) ;
return - V_24 ;
}
V_5 -> V_5 . V_16 = F_19 ( strrchr ( V_20 -> V_25 , '/' ) + 1 ,
V_22 ) ;
if ( ! V_5 -> V_5 . V_16 ) {
F_20 ( V_5 ) ;
F_18 ( V_20 ) ;
return - V_24 ;
}
V_5 -> V_16 = V_5 -> V_5 . V_16 ;
V_5 -> V_6 = F_21 ( V_20 , 0 ) ;
if ( ! V_5 -> V_6 ) {
F_22 ( L_8 , V_23 ) ;
F_23 ( V_5 -> V_5 . V_16 ) ;
F_20 ( V_5 ) ;
continue;
}
V_5 -> V_5 . V_26 = F_14 ;
V_5 -> V_5 . V_3 = F_13 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
char V_27 [ 8 ] ;
snprintf ( V_27 , sizeof( V_27 ) , L_9 , V_10 ) ;
V_5 -> V_12 [ V_10 ] = F_24 ( V_20 , V_27 ) ;
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
}
V_5 -> V_15 = F_24 ( V_20 , L_10 ) ;
if ( F_3 ( V_5 -> V_15 ) )
goto V_28;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
char V_27 [ 8 ] ;
snprintf ( V_27 , sizeof( V_27 ) , L_11 , V_10 ) ;
V_5 -> V_13 [ V_10 ] = F_24 ( V_20 , V_27 ) ;
if ( F_3 ( V_5 -> V_13 [ V_10 ] ) )
break;
V_5 -> V_14 [ V_10 ] = F_25 ( - V_29 ) ;
}
if ( F_3 ( V_5 -> V_13 [ 0 ] ) )
F_26 ( V_5 -> V_15 ) ;
V_28:
V_21 = F_9 ( V_5 -> V_6 + 0x4 ) & V_17 ;
F_27 ( & V_5 -> V_5 , NULL , ! V_21 ) ;
F_28 ( V_20 , & V_5 -> V_5 ) ;
}
F_16 (np, NULL, L_6 ) {
struct V_1 * V_30 , * V_31 ;
struct V_32 args ;
args . V_20 = V_20 ;
args . V_33 = 0 ;
V_30 = F_29 ( & args ) ;
if ( F_3 ( V_30 ) )
continue;
if ( F_30 ( V_20 , L_12 ,
L_13 , 0 , & args ) != 0 )
continue;
V_31 = F_29 ( & args ) ;
if ( F_3 ( V_31 ) )
continue;
if ( F_31 ( V_31 , V_30 ) )
F_22 ( L_14 ,
V_31 -> V_16 , V_30 -> V_16 ) ;
else
F_32 ( L_15 ,
V_31 -> V_16 , V_30 -> V_16 ) ;
}
return 0 ;
}
