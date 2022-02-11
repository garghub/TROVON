static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] ,
struct V_10 * V_11 )
{
struct V_12 * V_13 , * V_14 = NULL ;
char * V_15 ;
unsigned int V_16 = 0 ;
T_1 V_17 = 0 ;
if ( ! V_9 [ V_18 ] )
return - V_19 ;
V_15 = F_2 ( V_9 [ V_18 ] ) ;
if ( strlen ( V_15 ) == 0 )
return - V_19 ;
F_3 (nfacct, &net->nfnl_acct_list, head) {
if ( strncmp ( V_13 -> V_20 , V_15 , V_21 ) != 0 )
continue;
if ( V_7 -> V_22 & V_23 )
return - V_24 ;
V_14 = V_13 ;
break;
}
if ( V_14 ) {
if ( V_7 -> V_22 & V_25 ) {
F_4 ( & V_14 -> V_26 , 0 ) ;
F_4 ( & V_14 -> V_27 , 0 ) ;
F_5 () ;
if ( ( V_14 -> V_17 & V_28 ) )
F_6 ( V_29 ,
& V_14 -> V_17 ) ;
return 0 ;
}
return - V_30 ;
}
if ( V_9 [ V_31 ] ) {
V_17 = F_7 ( F_8 ( V_9 [ V_31 ] ) ) ;
if ( V_17 & ~ V_28 )
return - V_32 ;
if ( ( V_17 & V_28 ) == V_28 )
return - V_19 ;
if ( V_17 & V_33 )
return - V_19 ;
if ( ( V_17 & V_28 ) && ! V_9 [ V_34 ] )
return - V_19 ;
V_16 += sizeof( V_35 ) ;
}
V_13 = F_9 ( sizeof( struct V_12 ) + V_16 , V_36 ) ;
if ( V_13 == NULL )
return - V_37 ;
if ( V_17 & V_28 ) {
V_35 * V_38 = ( V_35 * ) V_13 -> V_39 ;
* V_38 = F_10 ( F_11 ( V_9 [ V_34 ] ) ) ;
V_13 -> V_17 = V_17 ;
}
strncpy ( V_13 -> V_20 , F_2 ( V_9 [ V_18 ] ) , V_21 ) ;
if ( V_9 [ V_40 ] ) {
F_4 ( & V_13 -> V_27 ,
F_10 ( F_11 ( V_9 [ V_40 ] ) ) ) ;
}
if ( V_9 [ V_41 ] ) {
F_4 ( & V_13 -> V_26 ,
F_10 ( F_11 ( V_9 [ V_41 ] ) ) ) ;
}
F_12 ( & V_13 -> V_42 , 1 ) ;
F_13 ( & V_13 -> V_43 , & V_1 -> V_44 ) ;
return 0 ;
}
static int
F_14 ( struct V_4 * V_5 , T_1 V_45 , T_1 V_46 , T_1 type ,
int V_47 , struct V_12 * V_48 )
{
struct V_6 * V_7 ;
struct V_49 * V_50 ;
unsigned int V_17 = V_45 ? V_51 : 0 ;
V_35 V_26 , V_27 ;
T_1 V_52 ;
V_47 = F_15 ( V_53 , V_47 ) ;
V_7 = F_16 ( V_5 , V_45 , V_46 , V_47 , sizeof( * V_50 ) , V_17 ) ;
if ( V_7 == NULL )
goto V_54;
V_50 = F_17 ( V_7 ) ;
V_50 -> V_55 = V_56 ;
V_50 -> V_57 = V_58 ;
V_50 -> V_59 = 0 ;
if ( F_18 ( V_5 , V_18 , V_48 -> V_20 ) )
goto V_60;
V_52 = V_48 -> V_17 ;
if ( type == V_61 ) {
V_26 = F_19 ( & V_48 -> V_26 , 0 ) ;
V_27 = F_19 ( & V_48 -> V_27 , 0 ) ;
F_5 () ;
if ( V_48 -> V_17 & V_28 )
F_6 ( V_29 , & V_48 -> V_17 ) ;
} else {
V_26 = F_20 ( & V_48 -> V_26 ) ;
V_27 = F_20 ( & V_48 -> V_27 ) ;
}
if ( F_21 ( V_5 , V_41 , F_22 ( V_26 ) ,
V_62 ) ||
F_21 ( V_5 , V_40 , F_22 ( V_27 ) ,
V_62 ) ||
F_23 ( V_5 , V_63 , F_24 ( F_25 ( & V_48 -> V_42 ) ) ) )
goto V_60;
if ( V_48 -> V_17 & V_28 ) {
V_35 * V_38 = ( V_35 * ) V_48 -> V_39 ;
if ( F_23 ( V_5 , V_31 , F_24 ( V_52 ) ) ||
F_21 ( V_5 , V_34 , F_22 ( * V_38 ) ,
V_62 ) )
goto V_60;
}
F_26 ( V_5 , V_7 ) ;
return V_5 -> V_64 ;
V_54:
V_60:
F_27 ( V_5 , V_7 ) ;
return - 1 ;
}
static int
F_28 ( struct V_4 * V_5 , struct V_65 * V_66 )
{
struct V_1 * V_1 = F_29 ( V_5 -> V_67 ) ;
struct V_12 * V_68 , * V_69 ;
const struct V_70 * V_71 = V_66 -> V_39 ;
if ( V_66 -> args [ 2 ] )
return 0 ;
V_69 = (struct V_12 * ) V_66 -> args [ 1 ] ;
if ( V_66 -> args [ 1 ] )
V_66 -> args [ 1 ] = 0 ;
F_30 () ;
F_31 (cur, &net->nfnl_acct_list, head) {
if ( V_69 ) {
if ( V_68 != V_69 )
continue;
V_69 = NULL ;
}
if ( V_71 && ( V_68 -> V_17 & V_71 -> V_72 ) != V_71 -> V_73 )
continue;
if ( F_14 ( V_5 , F_32 ( V_66 -> V_5 ) . V_45 ,
V_66 -> V_7 -> V_74 ,
F_33 ( V_66 -> V_7 -> V_75 ) ,
V_76 , V_68 ) < 0 ) {
V_66 -> args [ 1 ] = ( unsigned long ) V_68 ;
break;
}
}
if ( ! V_66 -> args [ 1 ] )
V_66 -> args [ 2 ] = 1 ;
F_34 () ;
return V_5 -> V_64 ;
}
static int F_35 ( struct V_65 * V_66 )
{
F_36 ( V_66 -> V_39 ) ;
return 0 ;
}
static struct V_70 *
F_37 ( const struct V_8 * const V_77 )
{
struct V_70 * V_71 ;
struct V_8 * V_9 [ V_78 + 1 ] ;
int V_79 ;
V_79 = F_38 ( V_9 , V_78 , V_77 , V_80 ,
NULL ) ;
if ( V_79 < 0 )
return F_39 ( V_79 ) ;
if ( ! V_9 [ V_81 ] || ! V_9 [ V_82 ] )
return F_39 ( - V_19 ) ;
V_71 = F_9 ( sizeof( struct V_70 ) , V_36 ) ;
if ( ! V_71 )
return F_39 ( - V_37 ) ;
V_71 -> V_72 = F_7 ( F_8 ( V_9 [ V_81 ] ) ) ;
V_71 -> V_73 = F_7 ( F_8 ( V_9 [ V_82 ] ) ) ;
return V_71 ;
}
static int F_40 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] ,
struct V_10 * V_11 )
{
int V_83 = - V_84 ;
struct V_12 * V_68 ;
char * V_15 ;
if ( V_7 -> V_22 & V_85 ) {
struct V_86 V_87 = {
. V_88 = F_28 ,
. V_89 = F_35 ,
} ;
if ( V_9 [ V_90 ] ) {
struct V_70 * V_71 ;
V_71 = F_37 ( V_9 [ V_90 ] ) ;
if ( F_41 ( V_71 ) )
return F_42 ( V_71 ) ;
V_87 . V_39 = V_71 ;
}
return F_43 ( V_3 , V_5 , V_7 , & V_87 ) ;
}
if ( ! V_9 [ V_18 ] )
return - V_19 ;
V_15 = F_2 ( V_9 [ V_18 ] ) ;
F_3 (cur, &net->nfnl_acct_list, head) {
struct V_4 * V_91 ;
if ( strncmp ( V_68 -> V_20 , V_15 , V_21 ) != 0 )
continue;
V_91 = F_44 ( V_92 , V_36 ) ;
if ( V_91 == NULL ) {
V_83 = - V_37 ;
break;
}
V_83 = F_14 ( V_91 , F_32 ( V_5 ) . V_45 ,
V_7 -> V_74 ,
F_33 ( V_7 -> V_75 ) ,
V_76 , V_68 ) ;
if ( V_83 <= 0 ) {
F_45 ( V_91 ) ;
break;
}
V_83 = F_46 ( V_3 , V_91 , F_32 ( V_5 ) . V_45 ,
V_93 ) ;
if ( V_83 > 0 )
V_83 = 0 ;
return V_83 == - V_94 ? - V_95 : V_83 ;
}
return V_83 ;
}
static int F_47 ( struct V_12 * V_68 )
{
int V_83 = 0 ;
if ( F_48 ( & V_68 -> V_42 ) ) {
F_49 ( & V_68 -> V_43 ) ;
F_50 ( V_68 , V_96 ) ;
} else {
V_83 = - V_30 ;
}
return V_83 ;
}
static int F_51 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] ,
struct V_10 * V_11 )
{
struct V_12 * V_68 , * V_97 ;
int V_83 = - V_84 ;
char * V_15 ;
if ( ! V_9 [ V_18 ] ) {
F_52 (cur, tmp, &net->nfnl_acct_list, head)
F_47 ( V_68 ) ;
return 0 ;
}
V_15 = F_2 ( V_9 [ V_18 ] ) ;
F_3 (cur, &net->nfnl_acct_list, head) {
if ( strncmp ( V_68 -> V_20 , V_15 , V_21 ) != 0 )
continue;
V_83 = F_47 ( V_68 ) ;
if ( V_83 < 0 )
return V_83 ;
break;
}
return V_83 ;
}
struct V_12 * F_53 ( struct V_1 * V_1 , const char * V_15 )
{
struct V_12 * V_68 , * V_48 = NULL ;
F_30 () ;
F_31 (cur, &net->nfnl_acct_list, head) {
if ( strncmp ( V_68 -> V_20 , V_15 , V_21 ) != 0 )
continue;
if ( ! F_54 ( V_98 ) )
goto V_79;
if ( ! F_55 ( & V_68 -> V_42 ) ) {
F_56 ( V_98 ) ;
goto V_79;
}
V_48 = V_68 ;
break;
}
V_79:
F_34 () ;
return V_48 ;
}
void F_57 ( struct V_12 * V_48 )
{
if ( F_58 ( & V_48 -> V_42 ) )
F_50 ( V_48 , V_96 ) ;
F_56 ( V_98 ) ;
}
void F_59 ( const struct V_4 * V_5 , struct V_12 * V_13 )
{
F_60 ( & V_13 -> V_26 ) ;
F_61 ( V_5 -> V_64 , & V_13 -> V_27 ) ;
}
static void F_62 ( struct V_1 * V_1 , struct V_12 * V_13 )
{
int V_83 ;
struct V_4 * V_5 ;
V_5 = F_44 ( V_92 , V_99 ) ;
if ( V_5 == NULL )
return;
V_83 = F_14 ( V_5 , 0 , 0 , V_100 , 0 ,
V_13 ) ;
if ( V_83 <= 0 ) {
F_45 ( V_5 ) ;
return;
}
F_63 ( V_1 -> V_3 , V_5 , 0 , V_101 ,
V_99 ) ;
}
int F_64 ( struct V_1 * V_1 , const struct V_4 * V_5 ,
struct V_12 * V_13 )
{
V_35 V_102 ;
V_35 * V_38 ;
int V_83 = V_103 ;
if ( ! ( V_13 -> V_17 & V_28 ) )
return V_104 ;
V_38 = ( V_35 * ) V_13 -> V_39 ;
V_102 = ( V_13 -> V_17 & V_105 ) ?
F_20 ( & V_13 -> V_26 ) : F_20 ( & V_13 -> V_27 ) ;
V_83 = V_102 > * V_38 ;
if ( V_102 >= * V_38 &&
! F_65 ( V_29 , & V_13 -> V_17 ) ) {
F_62 ( V_1 , V_13 ) ;
}
return V_83 ;
}
static int T_2 F_66 ( struct V_1 * V_1 )
{
F_67 ( & V_1 -> V_44 ) ;
return 0 ;
}
static void T_3 F_68 ( struct V_1 * V_1 )
{
struct V_12 * V_68 , * V_97 ;
F_52 (cur, tmp, &net->nfnl_acct_list, head) {
F_49 ( & V_68 -> V_43 ) ;
if ( F_58 ( & V_68 -> V_42 ) )
F_50 ( V_68 , V_96 ) ;
}
}
static int T_4 F_69 ( void )
{
int V_83 ;
V_83 = F_70 ( & V_106 ) ;
if ( V_83 < 0 ) {
F_71 ( L_1 ) ;
goto V_107;
}
F_72 ( L_2 ) ;
V_83 = F_73 ( & V_108 ) ;
if ( V_83 < 0 ) {
F_71 ( L_3 ) ;
goto V_109;
}
return 0 ;
V_109:
F_74 ( & V_106 ) ;
V_107:
return V_83 ;
}
static void T_5 F_75 ( void )
{
F_72 ( L_4 ) ;
F_76 ( & V_108 ) ;
F_74 ( & V_106 ) ;
}
