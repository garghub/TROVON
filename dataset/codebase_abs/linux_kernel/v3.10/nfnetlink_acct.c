static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_7 * const V_8 [] )
{
struct V_9 * V_10 , * V_11 = NULL ;
char * V_12 ;
if ( ! V_8 [ V_13 ] )
return - V_14 ;
V_12 = F_2 ( V_8 [ V_13 ] ) ;
if ( strlen ( V_12 ) == 0 )
return - V_14 ;
F_3 (nfacct, &nfnl_acct_list, head) {
if ( strncmp ( V_10 -> V_15 , V_12 , V_16 ) != 0 )
continue;
if ( V_6 -> V_17 & V_18 )
return - V_19 ;
V_11 = V_10 ;
break;
}
if ( V_11 ) {
if ( V_6 -> V_17 & V_20 ) {
F_4 ( & V_11 -> V_21 , 0 ) ;
F_4 ( & V_11 -> V_22 , 0 ) ;
return 0 ;
}
return - V_23 ;
}
V_10 = F_5 ( sizeof( struct V_9 ) , V_24 ) ;
if ( V_10 == NULL )
return - V_25 ;
strncpy ( V_10 -> V_15 , F_2 ( V_8 [ V_13 ] ) , V_16 ) ;
if ( V_8 [ V_26 ] ) {
F_4 ( & V_10 -> V_22 ,
F_6 ( F_7 ( V_8 [ V_26 ] ) ) ) ;
}
if ( V_8 [ V_27 ] ) {
F_4 ( & V_10 -> V_21 ,
F_6 ( F_7 ( V_8 [ V_27 ] ) ) ) ;
}
F_8 ( & V_10 -> V_28 , 1 ) ;
F_9 ( & V_10 -> V_29 , & V_30 ) ;
return 0 ;
}
static int
F_10 ( struct V_3 * V_4 , T_1 V_31 , T_1 V_32 , T_1 type ,
int V_33 , struct V_9 * V_34 )
{
struct V_5 * V_6 ;
struct V_35 * V_36 ;
unsigned int V_37 = V_31 ? V_38 : 0 ;
T_2 V_21 , V_22 ;
V_33 |= V_39 << 8 ;
V_6 = F_11 ( V_4 , V_31 , V_32 , V_33 , sizeof( * V_36 ) , V_37 ) ;
if ( V_6 == NULL )
goto V_40;
V_36 = F_12 ( V_6 ) ;
V_36 -> V_41 = V_42 ;
V_36 -> V_43 = V_44 ;
V_36 -> V_45 = 0 ;
if ( F_13 ( V_4 , V_13 , V_34 -> V_15 ) )
goto V_46;
if ( type == V_47 ) {
V_21 = F_14 ( & V_34 -> V_21 , 0 ) ;
V_22 = F_14 ( & V_34 -> V_22 , 0 ) ;
} else {
V_21 = F_15 ( & V_34 -> V_21 ) ;
V_22 = F_15 ( & V_34 -> V_22 ) ;
}
if ( F_16 ( V_4 , V_27 , F_17 ( V_21 ) ) ||
F_16 ( V_4 , V_26 , F_17 ( V_22 ) ) ||
F_18 ( V_4 , V_48 , F_19 ( F_20 ( & V_34 -> V_28 ) ) ) )
goto V_46;
F_21 ( V_4 , V_6 ) ;
return V_4 -> V_49 ;
V_40:
V_46:
F_22 ( V_4 , V_6 ) ;
return - 1 ;
}
static int
F_23 ( struct V_3 * V_4 , struct V_50 * V_51 )
{
struct V_9 * V_52 , * V_53 ;
if ( V_51 -> args [ 2 ] )
return 0 ;
V_53 = (struct V_9 * ) V_51 -> args [ 1 ] ;
if ( V_51 -> args [ 1 ] )
V_51 -> args [ 1 ] = 0 ;
F_24 () ;
F_25 (cur, &nfnl_acct_list, head) {
if ( V_53 ) {
if ( V_52 != V_53 )
continue;
V_53 = NULL ;
}
if ( F_10 ( V_4 , F_26 ( V_51 -> V_4 ) . V_31 ,
V_51 -> V_6 -> V_54 ,
F_27 ( V_51 -> V_6 -> V_55 ) ,
V_56 , V_52 ) < 0 ) {
V_51 -> args [ 1 ] = ( unsigned long ) V_52 ;
break;
}
}
if ( ! V_51 -> args [ 1 ] )
V_51 -> args [ 2 ] = 1 ;
F_28 () ;
return V_4 -> V_49 ;
}
static int
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_7 * const V_8 [] )
{
int V_57 = - V_58 ;
struct V_9 * V_52 ;
char * V_12 ;
if ( V_6 -> V_17 & V_59 ) {
struct V_60 V_61 = {
. V_62 = F_23 ,
} ;
return F_30 ( V_2 , V_4 , V_6 , & V_61 ) ;
}
if ( ! V_8 [ V_13 ] )
return - V_14 ;
V_12 = F_2 ( V_8 [ V_13 ] ) ;
F_3 (cur, &nfnl_acct_list, head) {
struct V_3 * V_63 ;
if ( strncmp ( V_52 -> V_15 , V_12 , V_16 ) != 0 )
continue;
V_63 = F_31 ( V_64 , V_24 ) ;
if ( V_63 == NULL ) {
V_57 = - V_25 ;
break;
}
V_57 = F_10 ( V_63 , F_26 ( V_4 ) . V_31 ,
V_6 -> V_54 ,
F_27 ( V_6 -> V_55 ) ,
V_56 , V_52 ) ;
if ( V_57 <= 0 ) {
F_32 ( V_63 ) ;
break;
}
V_57 = F_33 ( V_2 , V_63 , F_26 ( V_4 ) . V_31 ,
V_65 ) ;
if ( V_57 > 0 )
V_57 = 0 ;
return V_57 == - V_66 ? - V_67 : V_57 ;
}
return V_57 ;
}
static int F_34 ( struct V_9 * V_52 )
{
int V_57 = 0 ;
if ( F_35 ( & V_52 -> V_28 ) ) {
F_36 ( & V_52 -> V_29 ) ;
F_37 ( V_52 , V_68 ) ;
} else {
F_38 ( & V_52 -> V_28 ) ;
V_57 = - V_23 ;
}
return V_57 ;
}
static int
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_7 * const V_8 [] )
{
char * V_12 ;
struct V_9 * V_52 ;
int V_57 = - V_58 ;
if ( ! V_8 [ V_13 ] ) {
F_3 (cur, &nfnl_acct_list, head)
F_34 ( V_52 ) ;
return 0 ;
}
V_12 = F_2 ( V_8 [ V_13 ] ) ;
F_3 (cur, &nfnl_acct_list, head) {
if ( strncmp ( V_52 -> V_15 , V_12 , V_16 ) != 0 )
continue;
V_57 = F_34 ( V_52 ) ;
if ( V_57 < 0 )
return V_57 ;
break;
}
return V_57 ;
}
struct V_9 * F_40 ( const char * V_12 )
{
struct V_9 * V_52 , * V_34 = NULL ;
F_24 () ;
F_25 (cur, &nfnl_acct_list, head) {
if ( strncmp ( V_52 -> V_15 , V_12 , V_16 ) != 0 )
continue;
if ( ! F_41 ( V_69 ) )
goto V_70;
if ( ! F_42 ( & V_52 -> V_28 ) ) {
F_43 ( V_69 ) ;
goto V_70;
}
V_34 = V_52 ;
break;
}
V_70:
F_28 () ;
return V_34 ;
}
void F_44 ( struct V_9 * V_34 )
{
F_45 ( & V_34 -> V_28 ) ;
F_43 ( V_69 ) ;
}
void F_46 ( const struct V_3 * V_4 , struct V_9 * V_10 )
{
F_47 ( & V_10 -> V_21 ) ;
F_48 ( V_4 -> V_49 , & V_10 -> V_22 ) ;
}
static int T_3 F_49 ( void )
{
int V_57 ;
F_50 ( L_1 ) ;
V_57 = F_51 ( & V_71 ) ;
if ( V_57 < 0 ) {
F_52 ( L_2 ) ;
goto V_72;
}
return 0 ;
V_72:
return V_57 ;
}
static void T_4 F_53 ( void )
{
struct V_9 * V_52 , * V_73 ;
F_50 ( L_3 ) ;
F_54 ( & V_71 ) ;
F_55 (cur, tmp, &nfnl_acct_list, head) {
F_36 ( & V_52 -> V_29 ) ;
F_37 ( V_52 , V_68 ) ;
}
}
