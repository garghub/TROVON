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
F_6 ( V_26 ,
& V_11 -> V_14 ) ;
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
if ( V_14 & V_30 )
return - V_16 ;
V_13 += sizeof( V_31 ) ;
}
V_10 = F_9 ( sizeof( struct V_9 ) + V_13 , V_32 ) ;
if ( V_10 == NULL )
return - V_33 ;
if ( V_14 & V_25 ) {
V_31 * V_34 = ( V_31 * ) V_10 -> V_35 ;
* V_34 = F_10 ( F_11 ( V_8 [ V_36 ] ) ) ;
V_10 -> V_14 = V_14 ;
}
strncpy ( V_10 -> V_17 , F_2 ( V_8 [ V_15 ] ) , V_18 ) ;
if ( V_8 [ V_37 ] ) {
F_4 ( & V_10 -> V_24 ,
F_10 ( F_11 ( V_8 [ V_37 ] ) ) ) ;
}
if ( V_8 [ V_38 ] ) {
F_4 ( & V_10 -> V_23 ,
F_10 ( F_11 ( V_8 [ V_38 ] ) ) ) ;
}
F_12 ( & V_10 -> V_39 , 1 ) ;
F_13 ( & V_10 -> V_40 , & V_41 ) ;
return 0 ;
}
static int
F_14 ( struct V_3 * V_4 , T_1 V_42 , T_1 V_43 , T_1 type ,
int V_44 , struct V_9 * V_45 )
{
struct V_5 * V_6 ;
struct V_46 * V_47 ;
unsigned int V_14 = V_42 ? V_48 : 0 ;
V_31 V_23 , V_24 ;
T_1 V_49 ;
V_44 |= V_50 << 8 ;
V_6 = F_15 ( V_4 , V_42 , V_43 , V_44 , sizeof( * V_47 ) , V_14 ) ;
if ( V_6 == NULL )
goto V_51;
V_47 = F_16 ( V_6 ) ;
V_47 -> V_52 = V_53 ;
V_47 -> V_54 = V_55 ;
V_47 -> V_56 = 0 ;
if ( F_17 ( V_4 , V_15 , V_45 -> V_17 ) )
goto V_57;
V_49 = V_45 -> V_14 ;
if ( type == V_58 ) {
V_23 = F_18 ( & V_45 -> V_23 , 0 ) ;
V_24 = F_18 ( & V_45 -> V_24 , 0 ) ;
F_5 () ;
if ( V_45 -> V_14 & V_25 )
F_6 ( V_26 , & V_45 -> V_14 ) ;
} else {
V_23 = F_19 ( & V_45 -> V_23 ) ;
V_24 = F_19 ( & V_45 -> V_24 ) ;
}
if ( F_20 ( V_4 , V_38 , F_21 ( V_23 ) ) ||
F_20 ( V_4 , V_37 , F_21 ( V_24 ) ) ||
F_22 ( V_4 , V_59 , F_23 ( F_24 ( & V_45 -> V_39 ) ) ) )
goto V_57;
if ( V_45 -> V_14 & V_25 ) {
V_31 * V_34 = ( V_31 * ) V_45 -> V_35 ;
if ( F_22 ( V_4 , V_28 , F_23 ( V_49 ) ) ||
F_20 ( V_4 , V_36 , F_21 ( * V_34 ) ) )
goto V_57;
}
F_25 ( V_4 , V_6 ) ;
return V_4 -> V_60 ;
V_51:
V_57:
F_26 ( V_4 , V_6 ) ;
return - 1 ;
}
static int
F_27 ( struct V_3 * V_4 , struct V_61 * V_62 )
{
struct V_9 * V_63 , * V_64 ;
const struct V_65 * V_66 = V_62 -> V_35 ;
if ( V_62 -> args [ 2 ] )
return 0 ;
V_64 = (struct V_9 * ) V_62 -> args [ 1 ] ;
if ( V_62 -> args [ 1 ] )
V_62 -> args [ 1 ] = 0 ;
F_28 () ;
F_29 (cur, &nfnl_acct_list, head) {
if ( V_64 ) {
if ( V_63 != V_64 )
continue;
V_64 = NULL ;
}
if ( V_66 && ( V_63 -> V_14 & V_66 -> V_67 ) != V_66 -> V_68 )
continue;
if ( F_14 ( V_4 , F_30 ( V_62 -> V_4 ) . V_42 ,
V_62 -> V_6 -> V_69 ,
F_31 ( V_62 -> V_6 -> V_70 ) ,
V_71 , V_63 ) < 0 ) {
V_62 -> args [ 1 ] = ( unsigned long ) V_63 ;
break;
}
}
if ( ! V_62 -> args [ 1 ] )
V_62 -> args [ 2 ] = 1 ;
F_32 () ;
return V_4 -> V_60 ;
}
static int F_33 ( struct V_61 * V_62 )
{
F_34 ( V_62 -> V_35 ) ;
return 0 ;
}
static struct V_65 *
F_35 ( const struct V_7 * const V_72 )
{
struct V_65 * V_66 ;
struct V_7 * V_8 [ V_73 + 1 ] ;
int V_74 ;
V_74 = F_36 ( V_8 , V_73 , V_72 , V_75 ) ;
if ( V_74 < 0 )
return F_37 ( V_74 ) ;
V_66 = F_9 ( sizeof( struct V_65 ) , V_32 ) ;
if ( ! V_66 )
return F_37 ( - V_33 ) ;
V_66 -> V_67 = F_7 ( F_8 ( V_8 [ V_76 ] ) ) ;
V_66 -> V_68 = F_7 ( F_8 ( V_8 [ V_77 ] ) ) ;
return V_66 ;
}
static int
F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_7 * const V_8 [] )
{
int V_78 = - V_79 ;
struct V_9 * V_63 ;
char * V_12 ;
if ( V_6 -> V_19 & V_80 ) {
struct V_81 V_82 = {
. V_83 = F_27 ,
. V_84 = F_33 ,
} ;
if ( V_8 [ V_85 ] ) {
struct V_65 * V_66 ;
V_66 = F_35 ( V_8 [ V_85 ] ) ;
if ( F_39 ( V_66 ) )
return F_40 ( V_66 ) ;
V_82 . V_35 = V_66 ;
}
return F_41 ( V_2 , V_4 , V_6 , & V_82 ) ;
}
if ( ! V_8 [ V_15 ] )
return - V_16 ;
V_12 = F_2 ( V_8 [ V_15 ] ) ;
F_3 (cur, &nfnl_acct_list, head) {
struct V_3 * V_86 ;
if ( strncmp ( V_63 -> V_17 , V_12 , V_18 ) != 0 )
continue;
V_86 = F_42 ( V_87 , V_32 ) ;
if ( V_86 == NULL ) {
V_78 = - V_33 ;
break;
}
V_78 = F_14 ( V_86 , F_30 ( V_4 ) . V_42 ,
V_6 -> V_69 ,
F_31 ( V_6 -> V_70 ) ,
V_71 , V_63 ) ;
if ( V_78 <= 0 ) {
F_43 ( V_86 ) ;
break;
}
V_78 = F_44 ( V_2 , V_86 , F_30 ( V_4 ) . V_42 ,
V_88 ) ;
if ( V_78 > 0 )
V_78 = 0 ;
return V_78 == - V_89 ? - V_90 : V_78 ;
}
return V_78 ;
}
static int F_45 ( struct V_9 * V_63 )
{
int V_78 = 0 ;
if ( F_46 ( & V_63 -> V_39 ) ) {
F_47 ( & V_63 -> V_40 ) ;
F_48 ( V_63 , V_91 ) ;
} else {
F_49 ( & V_63 -> V_39 ) ;
V_78 = - V_27 ;
}
return V_78 ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_7 * const V_8 [] )
{
char * V_12 ;
struct V_9 * V_63 ;
int V_78 = - V_79 ;
if ( ! V_8 [ V_15 ] ) {
F_3 (cur, &nfnl_acct_list, head)
F_45 ( V_63 ) ;
return 0 ;
}
V_12 = F_2 ( V_8 [ V_15 ] ) ;
F_3 (cur, &nfnl_acct_list, head) {
if ( strncmp ( V_63 -> V_17 , V_12 , V_18 ) != 0 )
continue;
V_78 = F_45 ( V_63 ) ;
if ( V_78 < 0 )
return V_78 ;
break;
}
return V_78 ;
}
struct V_9 * F_51 ( const char * V_12 )
{
struct V_9 * V_63 , * V_45 = NULL ;
F_28 () ;
F_29 (cur, &nfnl_acct_list, head) {
if ( strncmp ( V_63 -> V_17 , V_12 , V_18 ) != 0 )
continue;
if ( ! F_52 ( V_92 ) )
goto V_74;
if ( ! F_53 ( & V_63 -> V_39 ) ) {
F_54 ( V_92 ) ;
goto V_74;
}
V_45 = V_63 ;
break;
}
V_74:
F_32 () ;
return V_45 ;
}
void F_55 ( struct V_9 * V_45 )
{
F_56 ( & V_45 -> V_39 ) ;
F_54 ( V_92 ) ;
}
void F_57 ( const struct V_3 * V_4 , struct V_9 * V_10 )
{
F_58 ( & V_10 -> V_23 ) ;
F_59 ( V_4 -> V_60 , & V_10 -> V_24 ) ;
}
static void F_60 ( struct V_9 * V_10 )
{
int V_78 ;
struct V_3 * V_4 ;
V_4 = F_42 ( V_87 , V_93 ) ;
if ( V_4 == NULL )
return;
V_78 = F_14 ( V_4 , 0 , 0 , V_94 , 0 ,
V_10 ) ;
if ( V_78 <= 0 ) {
F_43 ( V_4 ) ;
return;
}
F_61 ( V_95 . V_2 , V_4 , 0 , V_96 ,
V_93 ) ;
}
int F_62 ( const struct V_3 * V_4 , struct V_9 * V_10 )
{
V_31 V_97 ;
V_31 * V_34 ;
int V_78 = V_98 ;
if ( ! ( V_10 -> V_14 & V_25 ) )
return V_99 ;
V_34 = ( V_31 * ) V_10 -> V_35 ;
V_97 = ( V_10 -> V_14 & V_100 ) ?
F_19 ( & V_10 -> V_23 ) : F_19 ( & V_10 -> V_24 ) ;
V_78 = V_97 > * V_34 ;
if ( V_97 >= * V_34 &&
! F_63 ( V_26 , & V_10 -> V_14 ) ) {
F_60 ( V_10 ) ;
}
return V_78 ;
}
static int T_2 F_64 ( void )
{
int V_78 ;
F_65 ( L_1 ) ;
V_78 = F_66 ( & V_101 ) ;
if ( V_78 < 0 ) {
F_67 ( L_2 ) ;
goto V_102;
}
return 0 ;
V_102:
return V_78 ;
}
static void T_3 F_68 ( void )
{
struct V_9 * V_63 , * V_103 ;
F_65 ( L_3 ) ;
F_69 ( & V_101 ) ;
F_70 (cur, tmp, &nfnl_acct_list, head) {
F_47 ( & V_63 -> V_40 ) ;
F_48 ( V_63 , V_91 ) ;
}
}
