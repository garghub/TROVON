static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] )
{
struct V_10 * V_11 , * V_12 = NULL ;
char * V_13 ;
unsigned int V_14 = 0 ;
T_1 V_15 = 0 ;
if ( ! V_9 [ V_16 ] )
return - V_17 ;
V_13 = F_2 ( V_9 [ V_16 ] ) ;
if ( strlen ( V_13 ) == 0 )
return - V_17 ;
F_3 (nfacct, &net->nfnl_acct_list, head) {
if ( strncmp ( V_11 -> V_18 , V_13 , V_19 ) != 0 )
continue;
if ( V_7 -> V_20 & V_21 )
return - V_22 ;
V_12 = V_11 ;
break;
}
if ( V_12 ) {
if ( V_7 -> V_20 & V_23 ) {
F_4 ( & V_12 -> V_24 , 0 ) ;
F_4 ( & V_12 -> V_25 , 0 ) ;
F_5 () ;
if ( ( V_12 -> V_15 & V_26 ) )
F_6 ( V_27 ,
& V_12 -> V_15 ) ;
return 0 ;
}
return - V_28 ;
}
if ( V_9 [ V_29 ] ) {
V_15 = F_7 ( F_8 ( V_9 [ V_29 ] ) ) ;
if ( V_15 & ~ V_26 )
return - V_30 ;
if ( ( V_15 & V_26 ) == V_26 )
return - V_17 ;
if ( V_15 & V_31 )
return - V_17 ;
if ( ( V_15 & V_26 ) && ! V_9 [ V_32 ] )
return - V_17 ;
V_14 += sizeof( V_33 ) ;
}
V_11 = F_9 ( sizeof( struct V_10 ) + V_14 , V_34 ) ;
if ( V_11 == NULL )
return - V_35 ;
if ( V_15 & V_26 ) {
V_33 * V_36 = ( V_33 * ) V_11 -> V_37 ;
* V_36 = F_10 ( F_11 ( V_9 [ V_32 ] ) ) ;
V_11 -> V_15 = V_15 ;
}
strncpy ( V_11 -> V_18 , F_2 ( V_9 [ V_16 ] ) , V_19 ) ;
if ( V_9 [ V_38 ] ) {
F_4 ( & V_11 -> V_25 ,
F_10 ( F_11 ( V_9 [ V_38 ] ) ) ) ;
}
if ( V_9 [ V_39 ] ) {
F_4 ( & V_11 -> V_24 ,
F_10 ( F_11 ( V_9 [ V_39 ] ) ) ) ;
}
F_12 ( & V_11 -> V_40 , 1 ) ;
F_13 ( & V_11 -> V_41 , & V_1 -> V_42 ) ;
return 0 ;
}
static int
F_14 ( struct V_4 * V_5 , T_1 V_43 , T_1 V_44 , T_1 type ,
int V_45 , struct V_10 * V_46 )
{
struct V_6 * V_7 ;
struct V_47 * V_48 ;
unsigned int V_15 = V_43 ? V_49 : 0 ;
V_33 V_24 , V_25 ;
T_1 V_50 ;
V_45 |= V_51 << 8 ;
V_7 = F_15 ( V_5 , V_43 , V_44 , V_45 , sizeof( * V_48 ) , V_15 ) ;
if ( V_7 == NULL )
goto V_52;
V_48 = F_16 ( V_7 ) ;
V_48 -> V_53 = V_54 ;
V_48 -> V_55 = V_56 ;
V_48 -> V_57 = 0 ;
if ( F_17 ( V_5 , V_16 , V_46 -> V_18 ) )
goto V_58;
V_50 = V_46 -> V_15 ;
if ( type == V_59 ) {
V_24 = F_18 ( & V_46 -> V_24 , 0 ) ;
V_25 = F_18 ( & V_46 -> V_25 , 0 ) ;
F_5 () ;
if ( V_46 -> V_15 & V_26 )
F_6 ( V_27 , & V_46 -> V_15 ) ;
} else {
V_24 = F_19 ( & V_46 -> V_24 ) ;
V_25 = F_19 ( & V_46 -> V_25 ) ;
}
if ( F_20 ( V_5 , V_39 , F_21 ( V_24 ) ,
V_60 ) ||
F_20 ( V_5 , V_38 , F_21 ( V_25 ) ,
V_60 ) ||
F_22 ( V_5 , V_61 , F_23 ( F_24 ( & V_46 -> V_40 ) ) ) )
goto V_58;
if ( V_46 -> V_15 & V_26 ) {
V_33 * V_36 = ( V_33 * ) V_46 -> V_37 ;
if ( F_22 ( V_5 , V_29 , F_23 ( V_50 ) ) ||
F_20 ( V_5 , V_32 , F_21 ( * V_36 ) ,
V_60 ) )
goto V_58;
}
F_25 ( V_5 , V_7 ) ;
return V_5 -> V_62 ;
V_52:
V_58:
F_26 ( V_5 , V_7 ) ;
return - 1 ;
}
static int
F_27 ( struct V_4 * V_5 , struct V_63 * V_64 )
{
struct V_1 * V_1 = F_28 ( V_5 -> V_65 ) ;
struct V_10 * V_66 , * V_67 ;
const struct V_68 * V_69 = V_64 -> V_37 ;
if ( V_64 -> args [ 2 ] )
return 0 ;
V_67 = (struct V_10 * ) V_64 -> args [ 1 ] ;
if ( V_64 -> args [ 1 ] )
V_64 -> args [ 1 ] = 0 ;
F_29 () ;
F_30 (cur, &net->nfnl_acct_list, head) {
if ( V_67 ) {
if ( V_66 != V_67 )
continue;
V_67 = NULL ;
}
if ( V_69 && ( V_66 -> V_15 & V_69 -> V_70 ) != V_69 -> V_71 )
continue;
if ( F_14 ( V_5 , F_31 ( V_64 -> V_5 ) . V_43 ,
V_64 -> V_7 -> V_72 ,
F_32 ( V_64 -> V_7 -> V_73 ) ,
V_74 , V_66 ) < 0 ) {
V_64 -> args [ 1 ] = ( unsigned long ) V_66 ;
break;
}
}
if ( ! V_64 -> args [ 1 ] )
V_64 -> args [ 2 ] = 1 ;
F_33 () ;
return V_5 -> V_62 ;
}
static int F_34 ( struct V_63 * V_64 )
{
F_35 ( V_64 -> V_37 ) ;
return 0 ;
}
static struct V_68 *
F_36 ( const struct V_8 * const V_75 )
{
struct V_68 * V_69 ;
struct V_8 * V_9 [ V_76 + 1 ] ;
int V_77 ;
V_77 = F_37 ( V_9 , V_76 , V_75 , V_78 ) ;
if ( V_77 < 0 )
return F_38 ( V_77 ) ;
if ( ! V_9 [ V_79 ] || ! V_9 [ V_80 ] )
return F_38 ( - V_17 ) ;
V_69 = F_9 ( sizeof( struct V_68 ) , V_34 ) ;
if ( ! V_69 )
return F_38 ( - V_35 ) ;
V_69 -> V_70 = F_7 ( F_8 ( V_9 [ V_79 ] ) ) ;
V_69 -> V_71 = F_7 ( F_8 ( V_9 [ V_80 ] ) ) ;
return V_69 ;
}
static int F_39 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] )
{
int V_81 = - V_82 ;
struct V_10 * V_66 ;
char * V_13 ;
if ( V_7 -> V_20 & V_83 ) {
struct V_84 V_85 = {
. V_86 = F_27 ,
. V_87 = F_34 ,
} ;
if ( V_9 [ V_88 ] ) {
struct V_68 * V_69 ;
V_69 = F_36 ( V_9 [ V_88 ] ) ;
if ( F_40 ( V_69 ) )
return F_41 ( V_69 ) ;
V_85 . V_37 = V_69 ;
}
return F_42 ( V_3 , V_5 , V_7 , & V_85 ) ;
}
if ( ! V_9 [ V_16 ] )
return - V_17 ;
V_13 = F_2 ( V_9 [ V_16 ] ) ;
F_3 (cur, &net->nfnl_acct_list, head) {
struct V_4 * V_89 ;
if ( strncmp ( V_66 -> V_18 , V_13 , V_19 ) != 0 )
continue;
V_89 = F_43 ( V_90 , V_34 ) ;
if ( V_89 == NULL ) {
V_81 = - V_35 ;
break;
}
V_81 = F_14 ( V_89 , F_31 ( V_5 ) . V_43 ,
V_7 -> V_72 ,
F_32 ( V_7 -> V_73 ) ,
V_74 , V_66 ) ;
if ( V_81 <= 0 ) {
F_44 ( V_89 ) ;
break;
}
V_81 = F_45 ( V_3 , V_89 , F_31 ( V_5 ) . V_43 ,
V_91 ) ;
if ( V_81 > 0 )
V_81 = 0 ;
return V_81 == - V_92 ? - V_93 : V_81 ;
}
return V_81 ;
}
static int F_46 ( struct V_10 * V_66 )
{
int V_81 = 0 ;
if ( F_47 ( & V_66 -> V_40 , 1 , 0 ) == 1 ) {
F_48 ( & V_66 -> V_41 ) ;
F_49 ( V_66 , V_94 ) ;
} else {
V_81 = - V_28 ;
}
return V_81 ;
}
static int F_50 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] )
{
struct V_10 * V_66 , * V_95 ;
int V_81 = - V_82 ;
char * V_13 ;
if ( ! V_9 [ V_16 ] ) {
F_51 (cur, tmp, &net->nfnl_acct_list, head)
F_46 ( V_66 ) ;
return 0 ;
}
V_13 = F_2 ( V_9 [ V_16 ] ) ;
F_3 (cur, &net->nfnl_acct_list, head) {
if ( strncmp ( V_66 -> V_18 , V_13 , V_19 ) != 0 )
continue;
V_81 = F_46 ( V_66 ) ;
if ( V_81 < 0 )
return V_81 ;
break;
}
return V_81 ;
}
struct V_10 * F_52 ( struct V_1 * V_1 , const char * V_13 )
{
struct V_10 * V_66 , * V_46 = NULL ;
F_29 () ;
F_30 (cur, &net->nfnl_acct_list, head) {
if ( strncmp ( V_66 -> V_18 , V_13 , V_19 ) != 0 )
continue;
if ( ! F_53 ( V_96 ) )
goto V_77;
if ( ! F_54 ( & V_66 -> V_40 ) ) {
F_55 ( V_96 ) ;
goto V_77;
}
V_46 = V_66 ;
break;
}
V_77:
F_33 () ;
return V_46 ;
}
void F_56 ( struct V_10 * V_46 )
{
if ( F_57 ( & V_46 -> V_40 ) )
F_49 ( V_46 , V_94 ) ;
F_55 ( V_96 ) ;
}
void F_58 ( const struct V_4 * V_5 , struct V_10 * V_11 )
{
F_59 ( & V_11 -> V_24 ) ;
F_60 ( V_5 -> V_62 , & V_11 -> V_25 ) ;
}
static void F_61 ( struct V_1 * V_1 , struct V_10 * V_11 )
{
int V_81 ;
struct V_4 * V_5 ;
V_5 = F_43 ( V_90 , V_97 ) ;
if ( V_5 == NULL )
return;
V_81 = F_14 ( V_5 , 0 , 0 , V_98 , 0 ,
V_11 ) ;
if ( V_81 <= 0 ) {
F_44 ( V_5 ) ;
return;
}
F_62 ( V_1 -> V_3 , V_5 , 0 , V_99 ,
V_97 ) ;
}
int F_63 ( struct V_1 * V_1 , const struct V_4 * V_5 ,
struct V_10 * V_11 )
{
V_33 V_100 ;
V_33 * V_36 ;
int V_81 = V_101 ;
if ( ! ( V_11 -> V_15 & V_26 ) )
return V_102 ;
V_36 = ( V_33 * ) V_11 -> V_37 ;
V_100 = ( V_11 -> V_15 & V_103 ) ?
F_19 ( & V_11 -> V_24 ) : F_19 ( & V_11 -> V_25 ) ;
V_81 = V_100 > * V_36 ;
if ( V_100 >= * V_36 &&
! F_64 ( V_27 , & V_11 -> V_15 ) ) {
F_61 ( V_1 , V_11 ) ;
}
return V_81 ;
}
static int T_2 F_65 ( struct V_1 * V_1 )
{
F_66 ( & V_1 -> V_42 ) ;
return 0 ;
}
static void T_3 F_67 ( struct V_1 * V_1 )
{
struct V_10 * V_66 , * V_95 ;
F_51 (cur, tmp, &net->nfnl_acct_list, head) {
F_48 ( & V_66 -> V_41 ) ;
if ( F_57 ( & V_66 -> V_40 ) )
F_49 ( V_66 , V_94 ) ;
}
}
static int T_4 F_68 ( void )
{
int V_81 ;
V_81 = F_69 ( & V_104 ) ;
if ( V_81 < 0 ) {
F_70 ( L_1 ) ;
goto V_105;
}
F_71 ( L_2 ) ;
V_81 = F_72 ( & V_106 ) ;
if ( V_81 < 0 ) {
F_70 ( L_3 ) ;
goto V_107;
}
return 0 ;
V_107:
F_73 ( & V_104 ) ;
V_105:
return V_81 ;
}
static void T_5 F_74 ( void )
{
F_71 ( L_4 ) ;
F_75 ( & V_106 ) ;
F_73 ( & V_104 ) ;
}
