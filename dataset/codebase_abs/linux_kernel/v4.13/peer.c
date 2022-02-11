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
F_13 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_5 ;
struct V_15 * V_16 ;
struct V_15 * V_17 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
F_14 (lp, tmp, &ptable->pt_hash[i],
lp_hashlist) {
if ( V_14 && V_14 != V_16 -> V_18 )
continue;
F_15 ( & V_16 -> V_19 ) ;
V_2 -> V_20 ++ ;
F_16 ( V_16 ) ;
}
}
}
static void
F_17 ( struct V_1 * V_2 ,
int V_21 )
{
int V_5 ;
for ( V_5 = 3 ; V_2 -> V_20 ; V_5 ++ ) {
F_18 ( V_21 ) ;
if ( F_19 ( V_5 ) ) {
F_20 ( V_22 ,
L_3 ,
V_2 -> V_20 ) ;
}
F_21 ( V_23 ) ;
F_22 ( F_23 ( 1 ) >> 1 ) ;
F_24 ( V_21 ) ;
}
}
static void
F_25 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_21 )
{
struct V_15 * V_16 ;
struct V_15 * V_17 ;
T_1 V_24 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
F_14 (lp, tmp, &ptable->pt_hash[i],
lp_hashlist) {
if ( V_14 != V_16 -> V_18 )
continue;
if ( ! V_16 -> V_25 )
continue;
V_24 = V_16 -> V_24 ;
F_18 ( V_21 ) ;
F_26 ( F_27 ( V_26 ) , V_24 ) ;
F_24 ( V_21 ) ;
}
}
}
void
F_28 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_3 V_27 ;
struct V_15 * V_16 ;
struct V_15 * V_28 ;
int V_5 ;
F_6 ( & V_27 ) ;
F_9 ( V_7 . V_29 || V_14 ) ;
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_24 ( V_5 ) ;
F_25 ( V_14 , V_2 , V_5 ) ;
F_18 ( V_5 ) ;
}
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_24 ( V_5 ) ;
F_13 ( V_14 , V_2 ) ;
F_18 ( V_5 ) ;
}
F_5 (ptable, i, the_lnet.ln_peer_tables) {
F_24 ( V_5 ) ;
F_17 ( V_2 , V_5 ) ;
F_29 ( & V_2 -> V_10 , & V_27 ) ;
F_18 ( V_5 ) ;
}
F_14 (lp, temp, &deathrow, lp_hashlist) {
F_30 ( & V_16 -> V_19 ) ;
F_11 ( V_16 , sizeof( * V_16 ) ) ;
}
}
void
F_31 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
F_9 ( ! V_16 -> V_30 ) ;
F_9 ( ! V_16 -> V_25 ) ;
F_9 ( F_10 ( & V_16 -> V_31 ) ) ;
F_9 ( F_10 ( & V_16 -> V_19 ) ) ;
F_9 ( ! V_16 -> V_32 ) ;
V_2 = V_7 . V_8 [ V_16 -> V_33 ] ;
F_9 ( V_2 -> V_34 > 0 ) ;
V_2 -> V_34 -- ;
F_32 ( V_16 -> V_18 , V_16 -> V_33 ) ;
V_16 -> V_18 = NULL ;
F_33 ( & V_16 -> V_19 , & V_2 -> V_10 ) ;
F_9 ( V_2 -> V_20 > 0 ) ;
V_2 -> V_20 -- ;
}
struct V_15 *
F_34 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_3 * V_36 ;
struct V_15 * V_16 ;
F_9 ( ! V_7 . V_29 ) ;
V_36 = & V_2 -> V_12 [ F_35 ( V_35 ) ] ;
F_36 (lp, peers, lp_hashlist) {
if ( V_16 -> V_24 == V_35 ) {
F_37 ( V_16 ) ;
return V_16 ;
}
}
return NULL ;
}
int
F_38 ( struct V_15 * * V_37 , T_1 V_35 , int V_38 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 = NULL ;
struct V_15 * V_39 ;
int V_40 ;
int V_41 = 0 ;
* V_37 = NULL ;
if ( V_7 . V_29 )
return - V_42 ;
V_40 = V_38 != V_43 ? V_38 : F_39 ( V_35 ) ;
V_2 = V_7 . V_8 [ V_40 ] ;
V_16 = F_34 ( V_2 , V_35 ) ;
if ( V_16 ) {
* V_37 = V_16 ;
return 0 ;
}
if ( ! F_10 ( & V_2 -> V_10 ) ) {
V_16 = F_40 ( V_2 -> V_10 . V_44 ,
struct V_15 , V_19 ) ;
F_30 ( & V_16 -> V_19 ) ;
}
V_2 -> V_34 ++ ;
F_18 ( V_38 ) ;
if ( V_16 )
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
else
F_7 ( V_16 , F_3 () , V_40 , sizeof( * V_16 ) ) ;
if ( ! V_16 ) {
V_41 = - V_9 ;
F_24 ( V_38 ) ;
goto V_45;
}
F_6 ( & V_16 -> V_31 ) ;
F_6 ( & V_16 -> V_46 ) ;
F_6 ( & V_16 -> V_47 ) ;
V_16 -> V_48 = 0 ;
V_16 -> V_49 = 0 ;
V_16 -> V_50 = 0 ;
V_16 -> V_51 = 0 ;
V_16 -> V_52 = 0 ;
V_16 -> V_53 = ! F_41 () ;
V_16 -> V_54 = F_42 () ;
V_16 -> V_55 = 0 ;
V_16 -> V_56 = 0 ;
V_16 -> V_57 = V_58 ;
V_16 -> V_24 = V_35 ;
V_16 -> V_33 = V_40 ;
V_16 -> V_30 = 2 ;
V_16 -> V_25 = 0 ;
F_24 ( V_38 ) ;
if ( V_7 . V_29 ) {
V_41 = - V_42 ;
goto V_45;
}
V_39 = F_34 ( V_2 , V_35 ) ;
if ( V_39 ) {
* V_37 = V_39 ;
goto V_45;
}
V_16 -> V_18 = F_43 ( F_27 ( V_35 ) , V_40 ) ;
if ( ! V_16 -> V_18 ) {
V_41 = - V_59 ;
goto V_45;
}
V_16 -> V_60 = V_16 -> V_18 -> V_61 ;
V_16 -> V_62 = V_16 -> V_18 -> V_61 ;
V_16 -> V_63 = F_44 ( V_16 -> V_18 ) ;
V_16 -> V_64 = F_44 ( V_16 -> V_18 ) ;
F_45 ( & V_16 -> V_19 ,
& V_2 -> V_12 [ F_35 ( V_35 ) ] ) ;
V_2 -> V_65 ++ ;
* V_37 = V_16 ;
return 0 ;
V_45:
if ( V_16 )
F_33 ( & V_16 -> V_19 , & V_2 -> V_10 ) ;
V_2 -> V_34 -- ;
return V_41 ;
}
void
F_46 ( T_1 V_35 )
{
char * V_66 = L_4 ;
struct V_15 * V_16 ;
int V_41 ;
int V_38 ;
V_38 = F_47 ( V_35 ) ;
F_24 ( V_38 ) ;
V_41 = F_38 ( & V_16 , V_35 , V_38 ) ;
if ( V_41 ) {
F_18 ( V_38 ) ;
F_20 ( V_22 , L_5 , F_48 ( V_35 ) ) ;
return;
}
if ( F_49 ( V_16 ) || F_50 ( V_16 ) )
V_66 = V_16 -> V_53 ? L_6 : L_7 ;
F_20 ( V_22 , L_8 ,
F_48 ( V_16 -> V_24 ) , V_16 -> V_30 ,
V_66 , V_16 -> V_18 -> V_61 ,
V_16 -> V_63 , V_16 -> V_64 ,
V_16 -> V_60 , V_16 -> V_62 , V_16 -> V_32 ) ;
F_16 ( V_16 ) ;
F_18 ( V_38 ) ;
}
int
F_51 ( T_2 V_67 , T_3 * V_35 ,
char V_66 [ V_68 ] ,
T_2 * V_69 , T_2 * V_70 ,
T_2 * V_71 , T_2 * V_72 ,
T_2 * V_73 , T_2 * V_74 ,
T_2 * V_75 )
{
struct V_1 * V_76 ;
struct V_15 * V_16 ;
bool V_77 = false ;
int V_78 , V_6 ;
V_78 = F_52 ( V_7 . V_8 ) ;
if ( * V_69 >= V_78 )
return - V_79 ;
V_76 = V_7 . V_8 [ * V_69 ] ;
if ( ! V_76 )
return - V_79 ;
F_24 ( * V_69 ) ;
for ( V_6 = 0 ; V_6 < V_11 && ! V_77 ; V_6 ++ ) {
struct V_3 * V_36 = & V_76 -> V_12 [ V_6 ] ;
F_36 (lp, peers, lp_hashlist) {
if ( V_67 -- > 0 )
continue;
snprintf ( V_66 , V_68 , L_4 ) ;
if ( F_49 ( V_16 ) ||
F_50 ( V_16 ) )
snprintf ( V_66 , V_68 ,
V_16 -> V_53 ? L_6 : L_7 ) ;
* V_35 = V_16 -> V_24 ;
* V_70 = V_16 -> V_30 ;
* V_71 = V_16 -> V_18 -> V_61 ;
* V_72 = V_16 -> V_60 ;
* V_73 = V_16 -> V_63 ;
* V_74 = V_16 -> V_62 ;
* V_75 = V_16 -> V_32 ;
V_77 = true ;
}
}
F_18 ( * V_69 ) ;
* V_69 = V_78 ;
return V_77 ? 0 : - V_79 ;
}
