static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_7 * const V_8 [] )
{
struct V_9 * V_10 , * V_11 = NULL ;
char * V_12 ;
unsigned int V_13 = 0 ;
T_1 V_14 = 0 ;
if ( ! V_8 [ V_15 ] )
return - V_16 ;
V_12 = F_2 ( V_8 [ V_15 ] ) ;
if ( strlen ( V_12 ) == 0 )
return - V_16 ;
F_3 (nfacct, &nfnl_acct_list, head) {
if ( strncmp ( V_10 -> V_17 , V_12 , V_18 ) != 0 )
continue;
if ( V_6 -> V_19 & V_20 )
return - V_21 ;
V_11 = V_10 ;
break;
}
if ( V_11 ) {
if ( V_6 -> V_19 & V_22 ) {
F_4 ( & V_11 -> V_23 , 0 ) ;
F_4 ( & V_11 -> V_24 , 0 ) ;
F_5 () ;
if ( ( V_11 -> V_14 & V_25 ) )
F_6 ( V_26 , & V_11 -> V_14 ) ;
return 0 ;
}
return - V_27 ;
}
if ( V_8 [ V_28 ] ) {
V_14 = F_7 ( F_8 ( V_8 [ V_28 ] ) ) ;
if ( V_14 & ~ V_25 )
return - V_29 ;
if ( ( V_14 & V_25 ) == V_25 )
return - V_16 ;
if ( V_14 & V_26 )
return - V_16 ;
V_13 += sizeof( V_30 ) ;
}
V_10 = F_9 ( sizeof( struct V_9 ) + V_13 , V_31 ) ;
if ( V_10 == NULL )
return - V_32 ;
if ( V_14 & V_25 ) {
V_30 * V_33 = ( V_30 * ) V_10 -> V_34 ;
* V_33 = F_10 ( F_11 ( V_8 [ V_35 ] ) ) ;
V_10 -> V_14 = V_14 ;
}
strncpy ( V_10 -> V_17 , F_2 ( V_8 [ V_15 ] ) , V_18 ) ;
if ( V_8 [ V_36 ] ) {
F_4 ( & V_10 -> V_24 ,
F_10 ( F_11 ( V_8 [ V_36 ] ) ) ) ;
}
if ( V_8 [ V_37 ] ) {
F_4 ( & V_10 -> V_23 ,
F_10 ( F_11 ( V_8 [ V_37 ] ) ) ) ;
}
F_12 ( & V_10 -> V_38 , 1 ) ;
F_13 ( & V_10 -> V_39 , & V_40 ) ;
return 0 ;
}
static int
F_14 ( struct V_3 * V_4 , T_1 V_41 , T_1 V_42 , T_1 type ,
int V_43 , struct V_9 * V_44 )
{
struct V_5 * V_6 ;
struct V_45 * V_46 ;
unsigned int V_14 = V_41 ? V_47 : 0 ;
V_30 V_23 , V_24 ;
V_43 |= V_48 << 8 ;
V_6 = F_15 ( V_4 , V_41 , V_42 , V_43 , sizeof( * V_46 ) , V_14 ) ;
if ( V_6 == NULL )
goto V_49;
V_46 = F_16 ( V_6 ) ;
V_46 -> V_50 = V_51 ;
V_46 -> V_52 = V_53 ;
V_46 -> V_54 = 0 ;
if ( F_17 ( V_4 , V_15 , V_44 -> V_17 ) )
goto V_55;
if ( type == V_56 ) {
V_23 = F_18 ( & V_44 -> V_23 , 0 ) ;
V_24 = F_18 ( & V_44 -> V_24 , 0 ) ;
F_5 () ;
if ( V_44 -> V_14 & V_25 )
F_6 ( V_26 , & V_44 -> V_14 ) ;
} else {
V_23 = F_19 ( & V_44 -> V_23 ) ;
V_24 = F_19 ( & V_44 -> V_24 ) ;
}
if ( F_20 ( V_4 , V_37 , F_21 ( V_23 ) ) ||
F_20 ( V_4 , V_36 , F_21 ( V_24 ) ) ||
F_22 ( V_4 , V_57 , F_23 ( F_24 ( & V_44 -> V_38 ) ) ) )
goto V_55;
if ( V_44 -> V_14 & V_25 ) {
V_30 * V_33 = ( V_30 * ) V_44 -> V_34 ;
if ( F_22 ( V_4 , V_28 , F_23 ( V_44 -> V_14 ) ) ||
F_20 ( V_4 , V_35 , F_21 ( * V_33 ) ) )
goto V_55;
}
F_25 ( V_4 , V_6 ) ;
return V_4 -> V_58 ;
V_49:
V_55:
F_26 ( V_4 , V_6 ) ;
return - 1 ;
}
static int
F_27 ( struct V_3 * V_4 , struct V_59 * V_60 )
{
struct V_9 * V_61 , * V_62 ;
if ( V_60 -> args [ 2 ] )
return 0 ;
V_62 = (struct V_9 * ) V_60 -> args [ 1 ] ;
if ( V_60 -> args [ 1 ] )
V_60 -> args [ 1 ] = 0 ;
F_28 () ;
F_29 (cur, &nfnl_acct_list, head) {
if ( V_62 ) {
if ( V_61 != V_62 )
continue;
V_62 = NULL ;
}
if ( F_14 ( V_4 , F_30 ( V_60 -> V_4 ) . V_41 ,
V_60 -> V_6 -> V_63 ,
F_31 ( V_60 -> V_6 -> V_64 ) ,
V_65 , V_61 ) < 0 ) {
V_60 -> args [ 1 ] = ( unsigned long ) V_61 ;
break;
}
}
if ( ! V_60 -> args [ 1 ] )
V_60 -> args [ 2 ] = 1 ;
F_32 () ;
return V_4 -> V_58 ;
}
static int
F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_7 * const V_8 [] )
{
int V_66 = - V_67 ;
struct V_9 * V_61 ;
char * V_12 ;
if ( V_6 -> V_19 & V_68 ) {
struct V_69 V_70 = {
. V_71 = F_27 ,
} ;
return F_34 ( V_2 , V_4 , V_6 , & V_70 ) ;
}
if ( ! V_8 [ V_15 ] )
return - V_16 ;
V_12 = F_2 ( V_8 [ V_15 ] ) ;
F_3 (cur, &nfnl_acct_list, head) {
struct V_3 * V_72 ;
if ( strncmp ( V_61 -> V_17 , V_12 , V_18 ) != 0 )
continue;
V_72 = F_35 ( V_73 , V_31 ) ;
if ( V_72 == NULL ) {
V_66 = - V_32 ;
break;
}
V_66 = F_14 ( V_72 , F_30 ( V_4 ) . V_41 ,
V_6 -> V_63 ,
F_31 ( V_6 -> V_64 ) ,
V_65 , V_61 ) ;
if ( V_66 <= 0 ) {
F_36 ( V_72 ) ;
break;
}
V_66 = F_37 ( V_2 , V_72 , F_30 ( V_4 ) . V_41 ,
V_74 ) ;
if ( V_66 > 0 )
V_66 = 0 ;
return V_66 == - V_75 ? - V_76 : V_66 ;
}
return V_66 ;
}
static int F_38 ( struct V_9 * V_61 )
{
int V_66 = 0 ;
if ( F_39 ( & V_61 -> V_38 ) ) {
F_40 ( & V_61 -> V_39 ) ;
F_41 ( V_61 , V_77 ) ;
} else {
F_42 ( & V_61 -> V_38 ) ;
V_66 = - V_27 ;
}
return V_66 ;
}
static int
F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_7 * const V_8 [] )
{
char * V_12 ;
struct V_9 * V_61 ;
int V_66 = - V_67 ;
if ( ! V_8 [ V_15 ] ) {
F_3 (cur, &nfnl_acct_list, head)
F_38 ( V_61 ) ;
return 0 ;
}
V_12 = F_2 ( V_8 [ V_15 ] ) ;
F_3 (cur, &nfnl_acct_list, head) {
if ( strncmp ( V_61 -> V_17 , V_12 , V_18 ) != 0 )
continue;
V_66 = F_38 ( V_61 ) ;
if ( V_66 < 0 )
return V_66 ;
break;
}
return V_66 ;
}
struct V_9 * F_44 ( const char * V_12 )
{
struct V_9 * V_61 , * V_44 = NULL ;
F_28 () ;
F_29 (cur, &nfnl_acct_list, head) {
if ( strncmp ( V_61 -> V_17 , V_12 , V_18 ) != 0 )
continue;
if ( ! F_45 ( V_78 ) )
goto V_79;
if ( ! F_46 ( & V_61 -> V_38 ) ) {
F_47 ( V_78 ) ;
goto V_79;
}
V_44 = V_61 ;
break;
}
V_79:
F_32 () ;
return V_44 ;
}
void F_48 ( struct V_9 * V_44 )
{
F_49 ( & V_44 -> V_38 ) ;
F_47 ( V_78 ) ;
}
void F_50 ( const struct V_3 * V_4 , struct V_9 * V_10 )
{
F_51 ( & V_10 -> V_23 ) ;
F_52 ( V_4 -> V_58 , & V_10 -> V_24 ) ;
}
static void F_53 ( struct V_9 * V_10 )
{
int V_66 ;
struct V_3 * V_4 ;
V_4 = F_35 ( V_73 , V_80 ) ;
if ( V_4 == NULL )
return;
V_66 = F_14 ( V_4 , 0 , 0 , V_81 , 0 ,
V_10 ) ;
if ( V_66 <= 0 ) {
F_36 ( V_4 ) ;
return;
}
F_54 ( V_82 . V_2 , V_4 , 0 , V_83 ,
V_80 ) ;
}
int F_55 ( const struct V_3 * V_4 , struct V_9 * V_10 )
{
V_30 V_84 ;
V_30 * V_33 ;
int V_66 = V_85 ;
if ( ! ( V_10 -> V_14 & V_25 ) )
return V_86 ;
V_33 = ( V_30 * ) V_10 -> V_34 ;
V_84 = ( V_10 -> V_14 & V_87 ) ?
F_19 ( & V_10 -> V_23 ) : F_19 ( & V_10 -> V_24 ) ;
V_66 = V_84 > * V_33 ;
if ( V_84 >= * V_33 &&
! F_56 ( V_26 , & V_10 -> V_14 ) ) {
F_53 ( V_10 ) ;
}
return V_66 ;
}
static int T_2 F_57 ( void )
{
int V_66 ;
F_58 ( L_1 ) ;
V_66 = F_59 ( & V_88 ) ;
if ( V_66 < 0 ) {
F_60 ( L_2 ) ;
goto V_89;
}
return 0 ;
V_89:
return V_66 ;
}
static void T_3 F_61 ( void )
{
struct V_9 * V_61 , * V_90 ;
F_58 ( L_3 ) ;
F_62 ( & V_88 ) ;
F_63 (cur, tmp, &nfnl_acct_list, head) {
F_40 ( & V_61 -> V_39 ) ;
F_41 ( V_61 , V_77 ) ;
}
}
