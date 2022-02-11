int
F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 ;
int V_6 ;
V_7 . V_8 = F_2 ( F_3 () ,
sizeof( * V_2 ) ) ;
if ( V_7 . V_8 == NULL ) {
F_4 ( L_1 ) ;
return - V_9 ;
}
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_6 ( & V_2 -> V_10 ) ;
F_7 ( V_4 , F_3 () , V_5 ,
V_11 * sizeof( * V_4 ) ) ;
if ( V_4 == NULL ) {
F_4 ( L_2 ) ;
F_8 () ;
return - V_9 ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ )
F_6 ( & V_4 [ V_6 ] ) ;
V_2 -> V_12 = V_4 ;
}
return 0 ;
}
void
F_8 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 ;
int V_6 ;
if ( V_7 . V_8 == NULL )
return;
F_5 (ptable, i, the_lnet.ln_peer_tables) {
V_4 = V_2 -> V_12 ;
if ( V_4 == NULL )
break;
F_9 ( F_10 ( & V_2 -> V_10 ) ) ;
V_2 -> V_12 = NULL ;
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ )
F_9 ( F_10 ( & V_4 [ V_6 ] ) ) ;
F_11 ( V_4 , V_11 * sizeof( * V_4 ) ) ;
}
F_12 ( V_7 . V_8 ) ;
V_7 . V_8 = NULL ;
}
void
F_13 ( void )
{
struct V_1 * V_2 ;
int V_5 ;
int V_6 ;
F_9 ( V_7 . V_13 ) ;
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_14 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
struct V_3 * V_14 = & V_2 -> V_12 [ V_6 ] ;
while ( ! F_10 ( V_14 ) ) {
T_1 * V_15 = F_15 ( V_14 -> V_16 ,
T_1 ,
V_17 ) ;
F_16 ( & V_15 -> V_17 ) ;
F_17 ( V_15 ) ;
}
}
F_18 ( V_5 ) ;
}
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_19 ( V_18 ) ;
T_1 * V_15 ;
F_14 ( V_5 ) ;
for ( V_6 = 3 ; V_2 -> V_19 != 0 ; V_6 ++ ) {
F_18 ( V_5 ) ;
if ( ( V_6 & ( V_6 - 1 ) ) == 0 ) {
F_20 ( V_20 ,
L_3 ,
V_2 -> V_19 ) ;
}
F_21 ( V_21 ) ;
F_22 ( F_23 ( 1 ) / 2 ) ;
F_14 ( V_5 ) ;
}
F_24 ( & V_2 -> V_10 , & V_18 ) ;
F_18 ( V_5 ) ;
while ( ! F_10 ( & V_18 ) ) {
V_15 = F_15 ( V_18 . V_16 ,
T_1 , V_17 ) ;
F_25 ( & V_15 -> V_17 ) ;
F_11 ( V_15 , sizeof( * V_15 ) ) ;
}
}
}
void
F_26 ( T_1 * V_15 )
{
struct V_1 * V_2 ;
F_9 ( V_15 -> V_22 == 0 ) ;
F_9 ( V_15 -> V_23 == 0 ) ;
F_9 ( F_10 ( & V_15 -> V_24 ) ) ;
F_9 ( F_10 ( & V_15 -> V_17 ) ) ;
F_9 ( V_15 -> V_25 == 0 ) ;
V_2 = V_7 . V_8 [ V_15 -> V_26 ] ;
F_9 ( V_2 -> V_19 > 0 ) ;
V_2 -> V_19 -- ;
F_27 ( V_15 -> V_27 , V_15 -> V_26 ) ;
V_15 -> V_27 = NULL ;
F_28 ( & V_15 -> V_17 , & V_2 -> V_10 ) ;
}
T_1 *
F_29 ( struct V_1 * V_2 , T_2 V_28 )
{
struct V_3 * V_14 ;
T_1 * V_15 ;
F_9 ( ! V_7 . V_13 ) ;
V_14 = & V_2 -> V_12 [ F_30 ( V_28 ) ] ;
F_31 (lp, peers, lp_hashlist) {
if ( V_15 -> V_29 == V_28 ) {
F_32 ( V_15 ) ;
return V_15 ;
}
}
return NULL ;
}
int
F_33 ( T_1 * * V_30 , T_2 V_28 , int V_31 )
{
struct V_1 * V_2 ;
T_1 * V_15 = NULL ;
T_1 * V_32 ;
int V_33 ;
int V_34 = 0 ;
* V_30 = NULL ;
if ( V_7 . V_13 )
return - V_35 ;
V_33 = V_31 != V_36 ? V_31 : F_34 ( V_28 ) ;
V_2 = V_7 . V_8 [ V_33 ] ;
V_15 = F_29 ( V_2 , V_28 ) ;
if ( V_15 != NULL ) {
* V_30 = V_15 ;
return 0 ;
}
if ( ! F_10 ( & V_2 -> V_10 ) ) {
V_15 = F_15 ( V_2 -> V_10 . V_16 ,
T_1 , V_17 ) ;
F_25 ( & V_15 -> V_17 ) ;
}
V_2 -> V_19 ++ ;
F_18 ( V_31 ) ;
if ( V_15 != NULL )
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
else
F_7 ( V_15 , F_3 () , V_33 , sizeof( * V_15 ) ) ;
if ( V_15 == NULL ) {
V_34 = - V_9 ;
F_14 ( V_31 ) ;
goto V_37;
}
F_6 ( & V_15 -> V_24 ) ;
F_6 ( & V_15 -> V_38 ) ;
F_6 ( & V_15 -> V_39 ) ;
V_15 -> V_40 = 0 ;
V_15 -> V_41 = 0 ;
V_15 -> V_42 = 0 ;
V_15 -> V_43 = 0 ;
V_15 -> V_44 = 0 ;
V_15 -> V_45 = ! F_35 () ;
V_15 -> V_46 = F_36 () ;
V_15 -> V_47 = 0 ;
V_15 -> V_48 = 0 ;
V_15 -> V_49 = V_50 ;
V_15 -> V_29 = V_28 ;
V_15 -> V_26 = V_33 ;
V_15 -> V_22 = 2 ;
V_15 -> V_23 = 0 ;
F_14 ( V_31 ) ;
if ( V_7 . V_13 ) {
V_34 = - V_35 ;
goto V_37;
}
V_32 = F_29 ( V_2 , V_28 ) ;
if ( V_32 != NULL ) {
* V_30 = V_32 ;
goto V_37;
}
V_15 -> V_27 = F_37 ( F_38 ( V_28 ) , V_33 ) ;
if ( V_15 -> V_27 == NULL ) {
V_34 = - V_51 ;
goto V_37;
}
V_15 -> V_52 =
V_15 -> V_53 = V_15 -> V_27 -> V_54 ;
V_15 -> V_55 =
V_15 -> V_56 = F_39 ( V_15 -> V_27 ) ;
F_40 ( & V_15 -> V_17 ,
& V_2 -> V_12 [ F_30 ( V_28 ) ] ) ;
V_2 -> V_57 ++ ;
* V_30 = V_15 ;
return 0 ;
V_37:
if ( V_15 != NULL )
F_28 ( & V_15 -> V_17 , & V_2 -> V_10 ) ;
V_2 -> V_19 -- ;
return V_34 ;
}
void
F_41 ( T_2 V_28 )
{
char * V_58 = L_4 ;
T_1 * V_15 ;
int V_34 ;
int V_31 ;
V_31 = F_42 ( V_28 ) ;
F_14 ( V_31 ) ;
V_34 = F_33 ( & V_15 , V_28 , V_31 ) ;
if ( V_34 != 0 ) {
F_18 ( V_31 ) ;
F_20 ( V_20 , L_5 , F_43 ( V_28 ) ) ;
return;
}
if ( F_44 ( V_15 ) || F_45 ( V_15 ) )
V_58 = V_15 -> V_45 ? L_6 : L_7 ;
F_20 ( V_20 , L_8 ,
F_43 ( V_15 -> V_29 ) , V_15 -> V_22 ,
V_58 , V_15 -> V_27 -> V_54 ,
V_15 -> V_55 , V_15 -> V_56 ,
V_15 -> V_52 , V_15 -> V_53 , V_15 -> V_25 ) ;
F_17 ( V_15 ) ;
F_18 ( V_31 ) ;
}
