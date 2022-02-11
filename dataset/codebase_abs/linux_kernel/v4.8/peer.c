int
F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 ;
int V_6 ;
V_7 . V_8 = F_2 ( F_3 () ,
sizeof( * V_2 ) ) ;
if ( ! V_7 . V_8 ) {
F_4 ( L_1 ) ;
return - V_9 ;
}
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_6 ( & V_2 -> V_10 ) ;
F_7 ( V_4 , F_3 () , V_5 ,
V_11 * sizeof( * V_4 ) ) ;
if ( ! V_4 ) {
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
if ( ! V_7 . V_8 )
return;
F_5 (ptable, i, the_lnet.ln_peer_tables) {
V_4 = V_2 -> V_12 ;
if ( ! V_4 )
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
static void
F_13 ( T_1 * V_13 , struct V_1 * V_2 )
{
int V_5 ;
T_2 * V_14 ;
T_2 * V_15 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
F_14 (lp, tmp, &ptable->pt_hash[i],
lp_hashlist) {
if ( V_13 && V_13 != V_14 -> V_16 )
continue;
F_15 ( & V_14 -> V_17 ) ;
V_2 -> V_18 ++ ;
F_16 ( V_14 ) ;
}
}
}
static void
F_17 ( struct V_1 * V_2 ,
int V_19 )
{
int V_5 ;
for ( V_5 = 3 ; V_2 -> V_18 ; V_5 ++ ) {
F_18 ( V_19 ) ;
if ( F_19 ( V_5 ) ) {
F_20 ( V_20 ,
L_3 ,
V_2 -> V_18 ) ;
}
F_21 ( V_21 ) ;
F_22 ( F_23 ( 1 ) >> 1 ) ;
F_24 ( V_19 ) ;
}
}
static void
F_25 ( T_1 * V_13 , struct V_1 * V_2 ,
int V_19 )
{
T_2 * V_14 ;
T_2 * V_15 ;
T_3 V_22 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
F_14 (lp, tmp, &ptable->pt_hash[i],
lp_hashlist) {
if ( V_13 != V_14 -> V_16 )
continue;
if ( ! V_14 -> V_23 )
continue;
V_22 = V_14 -> V_22 ;
F_18 ( V_19 ) ;
F_26 ( F_27 ( V_24 ) , V_22 ) ;
F_24 ( V_19 ) ;
}
}
}
void
F_28 ( T_1 * V_13 )
{
struct V_1 * V_2 ;
struct V_3 V_25 ;
T_2 * V_14 ;
T_2 * V_26 ;
int V_5 ;
F_6 ( & V_25 ) ;
F_9 ( V_7 . V_27 || V_13 ) ;
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_24 ( V_5 ) ;
F_25 ( V_13 , V_2 , V_5 ) ;
F_18 ( V_5 ) ;
}
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_24 ( V_5 ) ;
F_13 ( V_13 , V_2 ) ;
F_18 ( V_5 ) ;
}
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_24 ( V_5 ) ;
F_17 ( V_2 , V_5 ) ;
F_29 ( & V_2 -> V_10 , & V_25 ) ;
F_18 ( V_5 ) ;
}
F_14 (lp, temp, &deathrow, lp_hashlist) {
F_30 ( & V_14 -> V_17 ) ;
F_11 ( V_14 , sizeof( * V_14 ) ) ;
}
}
void
F_31 ( T_2 * V_14 )
{
struct V_1 * V_2 ;
F_9 ( ! V_14 -> V_28 ) ;
F_9 ( ! V_14 -> V_23 ) ;
F_9 ( F_10 ( & V_14 -> V_29 ) ) ;
F_9 ( F_10 ( & V_14 -> V_17 ) ) ;
F_9 ( ! V_14 -> V_30 ) ;
V_2 = V_7 . V_8 [ V_14 -> V_31 ] ;
F_9 ( V_2 -> V_32 > 0 ) ;
V_2 -> V_32 -- ;
F_32 ( V_14 -> V_16 , V_14 -> V_31 ) ;
V_14 -> V_16 = NULL ;
F_33 ( & V_14 -> V_17 , & V_2 -> V_10 ) ;
F_9 ( V_2 -> V_18 > 0 ) ;
V_2 -> V_18 -- ;
}
T_2 *
F_34 ( struct V_1 * V_2 , T_3 V_33 )
{
struct V_3 * V_34 ;
T_2 * V_14 ;
F_9 ( ! V_7 . V_27 ) ;
V_34 = & V_2 -> V_12 [ F_35 ( V_33 ) ] ;
F_36 (lp, peers, lp_hashlist) {
if ( V_14 -> V_22 == V_33 ) {
F_37 ( V_14 ) ;
return V_14 ;
}
}
return NULL ;
}
int
F_38 ( T_2 * * V_35 , T_3 V_33 , int V_36 )
{
struct V_1 * V_2 ;
T_2 * V_14 = NULL ;
T_2 * V_37 ;
int V_38 ;
int V_39 = 0 ;
* V_35 = NULL ;
if ( V_7 . V_27 )
return - V_40 ;
V_38 = V_36 != V_41 ? V_36 : F_39 ( V_33 ) ;
V_2 = V_7 . V_8 [ V_38 ] ;
V_14 = F_34 ( V_2 , V_33 ) ;
if ( V_14 ) {
* V_35 = V_14 ;
return 0 ;
}
if ( ! F_10 ( & V_2 -> V_10 ) ) {
V_14 = F_40 ( V_2 -> V_10 . V_42 ,
T_2 , V_17 ) ;
F_30 ( & V_14 -> V_17 ) ;
}
V_2 -> V_32 ++ ;
F_18 ( V_36 ) ;
if ( V_14 )
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
else
F_7 ( V_14 , F_3 () , V_38 , sizeof( * V_14 ) ) ;
if ( ! V_14 ) {
V_39 = - V_9 ;
F_24 ( V_36 ) ;
goto V_43;
}
F_6 ( & V_14 -> V_29 ) ;
F_6 ( & V_14 -> V_44 ) ;
F_6 ( & V_14 -> V_45 ) ;
V_14 -> V_46 = 0 ;
V_14 -> V_47 = 0 ;
V_14 -> V_48 = 0 ;
V_14 -> V_49 = 0 ;
V_14 -> V_50 = 0 ;
V_14 -> V_51 = ! F_41 () ;
V_14 -> V_52 = F_42 () ;
V_14 -> V_53 = 0 ;
V_14 -> V_54 = 0 ;
V_14 -> V_55 = V_56 ;
V_14 -> V_22 = V_33 ;
V_14 -> V_31 = V_38 ;
V_14 -> V_28 = 2 ;
V_14 -> V_23 = 0 ;
F_24 ( V_36 ) ;
if ( V_7 . V_27 ) {
V_39 = - V_40 ;
goto V_43;
}
V_37 = F_34 ( V_2 , V_33 ) ;
if ( V_37 ) {
* V_35 = V_37 ;
goto V_43;
}
V_14 -> V_16 = F_43 ( F_27 ( V_33 ) , V_38 ) ;
if ( ! V_14 -> V_16 ) {
V_39 = - V_57 ;
goto V_43;
}
V_14 -> V_58 = V_14 -> V_16 -> V_59 ;
V_14 -> V_60 = V_14 -> V_16 -> V_59 ;
V_14 -> V_61 = F_44 ( V_14 -> V_16 ) ;
V_14 -> V_62 = F_44 ( V_14 -> V_16 ) ;
F_45 ( & V_14 -> V_17 ,
& V_2 -> V_12 [ F_35 ( V_33 ) ] ) ;
V_2 -> V_63 ++ ;
* V_35 = V_14 ;
return 0 ;
V_43:
if ( V_14 )
F_33 ( & V_14 -> V_17 , & V_2 -> V_10 ) ;
V_2 -> V_32 -- ;
return V_39 ;
}
void
F_46 ( T_3 V_33 )
{
char * V_64 = L_4 ;
T_2 * V_14 ;
int V_39 ;
int V_36 ;
V_36 = F_47 ( V_33 ) ;
F_24 ( V_36 ) ;
V_39 = F_38 ( & V_14 , V_33 , V_36 ) ;
if ( V_39 ) {
F_18 ( V_36 ) ;
F_20 ( V_20 , L_5 , F_48 ( V_33 ) ) ;
return;
}
if ( F_49 ( V_14 ) || F_50 ( V_14 ) )
V_64 = V_14 -> V_51 ? L_6 : L_7 ;
F_20 ( V_20 , L_8 ,
F_48 ( V_14 -> V_22 ) , V_14 -> V_28 ,
V_64 , V_14 -> V_16 -> V_59 ,
V_14 -> V_61 , V_14 -> V_62 ,
V_14 -> V_58 , V_14 -> V_60 , V_14 -> V_30 ) ;
F_16 ( V_14 ) ;
F_18 ( V_36 ) ;
}
int
F_51 ( T_4 V_65 , T_5 * V_33 ,
char V_64 [ V_66 ] ,
T_4 * V_67 , T_4 * V_68 ,
T_4 * V_69 , T_4 * V_70 ,
T_4 * V_71 , T_4 * V_72 ,
T_4 * V_73 )
{
struct V_1 * V_74 ;
T_2 * V_14 ;
bool V_75 = false ;
int V_76 , V_6 ;
V_76 = F_52 ( V_7 . V_8 ) ;
if ( * V_67 >= V_76 )
return - V_77 ;
V_74 = V_7 . V_8 [ * V_67 ] ;
if ( ! V_74 )
return - V_77 ;
F_24 ( * V_67 ) ;
for ( V_6 = 0 ; V_6 < V_11 && ! V_75 ; V_6 ++ ) {
struct V_3 * V_34 = & V_74 -> V_12 [ V_6 ] ;
F_36 (lp, peers, lp_hashlist) {
if ( V_65 -- > 0 )
continue;
snprintf ( V_64 , V_66 , L_4 ) ;
if ( F_49 ( V_14 ) ||
F_50 ( V_14 ) )
snprintf ( V_64 , V_66 ,
V_14 -> V_51 ? L_6 : L_7 ) ;
* V_33 = V_14 -> V_22 ;
* V_68 = V_14 -> V_28 ;
* V_69 = V_14 -> V_16 -> V_59 ;
* V_70 = V_14 -> V_58 ;
* V_71 = V_14 -> V_61 ;
* V_72 = V_14 -> V_60 ;
* V_73 = V_14 -> V_30 ;
V_75 = true ;
}
}
F_18 ( * V_67 ) ;
* V_67 = V_76 ;
return V_75 ? 0 : - V_77 ;
}
