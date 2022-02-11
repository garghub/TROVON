static int
F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_4 , const struct V_5 * V_6 )
{
int V_7 = 0 ;
if ( F_2 ( V_3 -> V_8 . V_9 ) ) {
struct V_5 * V_10 [ V_3 -> V_8 . V_11 + 1 ] ;
V_7 = F_3 ( V_10 , V_3 -> V_8 . V_11 ,
V_6 , V_3 -> V_8 . V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_3 -> V_8 . V_9 ( V_10 , V_4 , V_1 ) ;
}
return V_7 ;
}
static int F_4 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
T_1 V_20 ;
T_2 V_21 ;
struct V_2 * V_3 ;
struct V_8 * V_22 , * V_23 = NULL ;
char * V_24 ;
int V_7 ;
if ( ! V_19 [ V_25 ] ||
! V_19 [ V_26 ] ||
! V_19 [ V_27 ] ||
! V_19 [ V_28 ] )
return - V_29 ;
V_24 = F_5 ( V_19 [ V_25 ] ) ;
V_20 = F_6 ( F_7 ( V_19 [ V_26 ] ) ) ;
V_21 = F_8 ( V_19 [ V_27 ] ) ;
F_9 (timeout, &net->nfct_timeout_list, head) {
if ( strncmp ( V_22 -> V_24 , V_24 , V_30 ) != 0 )
continue;
if ( V_18 -> V_31 & V_32 )
return - V_33 ;
V_23 = V_22 ;
break;
}
V_3 = F_10 ( V_20 , V_21 ) ;
if ( V_3 -> V_3 != V_21 ) {
V_7 = - V_34 ;
goto V_35;
}
if ( V_23 ) {
if ( V_18 -> V_31 & V_36 ) {
if ( V_23 -> V_20 != V_20 ||
V_23 -> V_3 -> V_3 != V_21 ) {
V_7 = - V_29 ;
goto V_35;
}
V_7 = F_1 ( & V_23 -> V_37 ,
V_3 , V_4 ,
V_19 [ V_28 ] ) ;
return V_7 ;
}
V_7 = - V_38 ;
goto V_35;
}
V_22 = F_11 ( sizeof( struct V_8 ) +
V_3 -> V_8 . V_39 , V_40 ) ;
if ( V_22 == NULL ) {
V_7 = - V_41 ;
goto V_35;
}
V_7 = F_1 ( & V_22 -> V_37 , V_3 , V_4 ,
V_19 [ V_28 ] ) ;
if ( V_7 < 0 )
goto V_42;
strcpy ( V_22 -> V_24 , F_5 ( V_19 [ V_25 ] ) ) ;
V_22 -> V_20 = V_20 ;
V_22 -> V_3 = V_3 ;
F_12 ( & V_22 -> V_43 , 1 ) ;
F_13 ( & V_22 -> V_44 , & V_4 -> V_45 ) ;
return 0 ;
V_42:
F_14 ( V_22 ) ;
V_35:
F_15 ( V_3 ) ;
return V_7 ;
}
static int
F_16 ( struct V_15 * V_16 , T_3 V_46 , T_3 V_47 , T_3 type ,
int V_48 , struct V_8 * V_22 )
{
struct V_17 * V_18 ;
struct V_49 * V_50 ;
unsigned int V_51 = V_46 ? V_52 : 0 ;
struct V_2 * V_3 = V_22 -> V_3 ;
V_48 |= V_53 << 8 ;
V_18 = F_17 ( V_16 , V_46 , V_47 , V_48 , sizeof( * V_50 ) , V_51 ) ;
if ( V_18 == NULL )
goto V_54;
V_50 = F_18 ( V_18 ) ;
V_50 -> V_55 = V_56 ;
V_50 -> V_57 = V_58 ;
V_50 -> V_59 = 0 ;
if ( F_19 ( V_16 , V_25 , V_22 -> V_24 ) ||
F_20 ( V_16 , V_26 , F_21 ( V_22 -> V_20 ) ) ||
F_22 ( V_16 , V_27 , V_22 -> V_3 -> V_3 ) ||
F_23 ( V_16 , V_60 ,
F_24 ( F_25 ( & V_22 -> V_43 ) ) ) )
goto V_61;
if ( F_2 ( V_3 -> V_8 . V_62 ) ) {
struct V_5 * V_63 ;
int V_7 ;
V_63 = F_26 ( V_16 ,
V_28 | V_64 ) ;
if ( ! V_63 )
goto V_61;
V_7 = V_3 -> V_8 . V_62 ( V_16 , & V_22 -> V_37 ) ;
if ( V_7 < 0 )
goto V_61;
F_27 ( V_16 , V_63 ) ;
}
F_28 ( V_16 , V_18 ) ;
return V_16 -> V_65 ;
V_54:
V_61:
F_29 ( V_16 , V_18 ) ;
return - 1 ;
}
static int
F_30 ( struct V_15 * V_16 , struct V_66 * V_67 )
{
struct V_4 * V_4 = F_31 ( V_16 -> V_68 ) ;
struct V_8 * V_69 , * V_70 ;
if ( V_67 -> args [ 2 ] )
return 0 ;
V_70 = (struct V_8 * ) V_67 -> args [ 1 ] ;
if ( V_67 -> args [ 1 ] )
V_67 -> args [ 1 ] = 0 ;
F_32 () ;
F_33 (cur, &net->nfct_timeout_list, head) {
if ( V_70 ) {
if ( V_69 != V_70 )
continue;
V_70 = NULL ;
}
if ( F_16 ( V_16 , F_34 ( V_67 -> V_16 ) . V_46 ,
V_67 -> V_18 -> V_71 ,
F_35 ( V_67 -> V_18 -> V_72 ) ,
V_73 , V_69 ) < 0 ) {
V_67 -> args [ 1 ] = ( unsigned long ) V_69 ;
break;
}
}
if ( ! V_67 -> args [ 1 ] )
V_67 -> args [ 2 ] = 1 ;
F_36 () ;
return V_16 -> V_65 ;
}
static int F_37 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
int V_7 = - V_74 ;
char * V_24 ;
struct V_8 * V_69 ;
if ( V_18 -> V_31 & V_75 ) {
struct V_76 V_77 = {
. V_78 = F_30 ,
} ;
return F_38 ( V_14 , V_16 , V_18 , & V_77 ) ;
}
if ( ! V_19 [ V_25 ] )
return - V_29 ;
V_24 = F_5 ( V_19 [ V_25 ] ) ;
F_9 (cur, &net->nfct_timeout_list, head) {
struct V_15 * V_79 ;
if ( strncmp ( V_69 -> V_24 , V_24 , V_30 ) != 0 )
continue;
V_79 = F_39 ( V_80 , V_40 ) ;
if ( V_79 == NULL ) {
V_7 = - V_41 ;
break;
}
V_7 = F_16 ( V_79 , F_34 ( V_16 ) . V_46 ,
V_18 -> V_71 ,
F_35 ( V_18 -> V_72 ) ,
V_73 , V_69 ) ;
if ( V_7 <= 0 ) {
F_40 ( V_79 ) ;
break;
}
V_7 = F_41 ( V_14 , V_79 , F_34 ( V_16 ) . V_46 ,
V_81 ) ;
if ( V_7 > 0 )
V_7 = 0 ;
return V_7 == - V_82 ? - V_83 : V_7 ;
}
return V_7 ;
}
static void F_42 ( struct V_84 * V_85 ,
struct V_8 * V_22 )
{
struct V_86 * V_87 = F_43 ( V_85 ) ;
struct V_88 * V_89 = F_44 ( V_87 ) ;
if ( V_89 && ( ! V_22 || V_89 -> V_22 == V_22 ) )
F_45 ( V_89 -> V_22 , NULL ) ;
}
static void F_46 ( struct V_4 * V_4 , struct V_8 * V_22 )
{
struct V_84 * V_90 ;
const struct V_91 * V_92 ;
int V_85 ;
F_47 () ;
for ( V_85 = 0 ; V_85 < V_93 ; V_85 ++ ) {
F_48 ( & V_94 [ V_85 % V_95 ] ) ;
if ( V_85 < V_93 ) {
F_49 (h, nn, &nf_conntrack_hash[i], hnnode)
F_42 ( V_90 , V_22 ) ;
}
F_50 ( & V_94 [ V_85 % V_95 ] ) ;
}
F_51 () ;
}
static int F_52 ( struct V_4 * V_4 , struct V_8 * V_22 )
{
int V_7 = 0 ;
if ( F_53 ( & V_22 -> V_43 ) ) {
F_54 ( & V_22 -> V_44 ) ;
F_15 ( V_22 -> V_3 ) ;
F_46 ( V_4 , V_22 ) ;
F_55 ( V_22 , V_96 ) ;
} else {
F_56 ( & V_22 -> V_43 ) ;
V_7 = - V_38 ;
}
return V_7 ;
}
static int F_57 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
struct V_8 * V_69 ;
int V_7 = - V_74 ;
char * V_24 ;
if ( ! V_19 [ V_25 ] ) {
F_9 (cur, &net->nfct_timeout_list, head)
F_52 ( V_4 , V_69 ) ;
return 0 ;
}
V_24 = F_5 ( V_19 [ V_25 ] ) ;
F_9 (cur, &net->nfct_timeout_list, head) {
if ( strncmp ( V_69 -> V_24 , V_24 , V_30 ) != 0 )
continue;
V_7 = F_52 ( V_4 , V_69 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
}
return V_7 ;
}
static int F_58 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
T_1 V_20 ;
T_2 V_21 ;
struct V_2 * V_3 ;
unsigned int * V_1 ;
int V_7 ;
if ( ! V_19 [ V_26 ] ||
! V_19 [ V_27 ] ||
! V_19 [ V_28 ] )
return - V_29 ;
V_20 = F_6 ( F_7 ( V_19 [ V_26 ] ) ) ;
V_21 = F_8 ( V_19 [ V_27 ] ) ;
V_3 = F_10 ( V_20 , V_21 ) ;
if ( V_3 -> V_3 != V_21 ) {
V_7 = - V_34 ;
goto V_42;
}
V_1 = V_3 -> V_97 ( V_4 ) ;
V_7 = F_1 ( V_1 , V_3 , V_4 ,
V_19 [ V_28 ] ) ;
if ( V_7 < 0 )
goto V_42;
F_15 ( V_3 ) ;
return 0 ;
V_42:
F_15 ( V_3 ) ;
return V_7 ;
}
static int
F_59 ( struct V_4 * V_4 , struct V_15 * V_16 , T_3 V_46 ,
T_3 V_47 , T_3 type , int V_48 ,
struct V_2 * V_3 )
{
struct V_17 * V_18 ;
struct V_49 * V_50 ;
unsigned int V_51 = V_46 ? V_52 : 0 ;
V_48 |= V_53 << 8 ;
V_18 = F_17 ( V_16 , V_46 , V_47 , V_48 , sizeof( * V_50 ) , V_51 ) ;
if ( V_18 == NULL )
goto V_54;
V_50 = F_18 ( V_18 ) ;
V_50 -> V_55 = V_56 ;
V_50 -> V_57 = V_58 ;
V_50 -> V_59 = 0 ;
if ( F_20 ( V_16 , V_26 , F_21 ( V_3 -> V_98 ) ) ||
F_22 ( V_16 , V_27 , V_3 -> V_3 ) )
goto V_61;
if ( F_2 ( V_3 -> V_8 . V_62 ) ) {
struct V_5 * V_63 ;
unsigned int * V_1 = V_3 -> V_97 ( V_4 ) ;
int V_7 ;
V_63 = F_26 ( V_16 ,
V_28 | V_64 ) ;
if ( ! V_63 )
goto V_61;
V_7 = V_3 -> V_8 . V_62 ( V_16 , V_1 ) ;
if ( V_7 < 0 )
goto V_61;
F_27 ( V_16 , V_63 ) ;
}
F_28 ( V_16 , V_18 ) ;
return V_16 -> V_65 ;
V_54:
V_61:
F_29 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_60 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
T_1 V_20 ;
T_2 V_21 ;
struct V_2 * V_3 ;
struct V_15 * V_79 ;
int V_7 , V_42 ;
if ( ! V_19 [ V_26 ] || ! V_19 [ V_27 ] )
return - V_29 ;
V_20 = F_6 ( F_7 ( V_19 [ V_26 ] ) ) ;
V_21 = F_8 ( V_19 [ V_27 ] ) ;
V_3 = F_10 ( V_20 , V_21 ) ;
if ( V_3 -> V_3 != V_21 ) {
V_42 = - V_34 ;
goto V_42;
}
V_79 = F_39 ( V_80 , V_40 ) ;
if ( V_79 == NULL ) {
V_42 = - V_41 ;
goto V_42;
}
V_7 = F_59 ( V_4 , V_79 , F_34 ( V_16 ) . V_46 ,
V_18 -> V_71 ,
F_35 ( V_18 -> V_72 ) ,
V_99 ,
V_3 ) ;
if ( V_7 <= 0 ) {
F_40 ( V_79 ) ;
V_42 = - V_41 ;
goto V_42;
}
V_7 = F_41 ( V_14 , V_79 , F_34 ( V_16 ) . V_46 , V_81 ) ;
if ( V_7 > 0 )
V_7 = 0 ;
return V_7 == - V_82 ? - V_83 : V_7 ;
V_42:
F_15 ( V_3 ) ;
return V_42 ;
}
static struct V_8 *
F_61 ( struct V_4 * V_4 , const char * V_24 )
{
struct V_8 * V_22 , * V_23 = NULL ;
F_32 () ;
F_33 (timeout, &net->nfct_timeout_list, head) {
if ( strncmp ( V_22 -> V_24 , V_24 , V_30 ) != 0 )
continue;
if ( ! F_62 ( V_100 ) )
goto V_42;
if ( ! F_63 ( & V_22 -> V_43 ) ) {
F_64 ( V_100 ) ;
goto V_42;
}
V_23 = V_22 ;
break;
}
V_42:
F_36 () ;
return V_23 ;
}
static void F_65 ( struct V_8 * V_22 )
{
F_66 ( & V_22 -> V_43 ) ;
F_64 ( V_100 ) ;
}
static int T_4 F_67 ( struct V_4 * V_4 )
{
F_68 ( & V_4 -> V_45 ) ;
return 0 ;
}
static void T_5 F_69 ( struct V_4 * V_4 )
{
struct V_8 * V_69 , * V_101 ;
F_46 ( V_4 , NULL ) ;
F_70 (cur, tmp, &net->nfct_timeout_list, head) {
F_54 ( & V_69 -> V_44 ) ;
F_15 ( V_69 -> V_3 ) ;
F_55 ( V_69 , V_96 ) ;
}
}
static int T_6 F_71 ( void )
{
int V_7 ;
V_7 = F_72 ( & V_102 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_73 ( & V_103 ) ;
if ( V_7 < 0 ) {
F_74 ( L_1
L_2 ) ;
goto V_104;
}
#ifdef F_75
F_45 ( V_105 , F_61 ) ;
F_45 ( V_106 , F_65 ) ;
#endif
return 0 ;
V_104:
F_76 ( & V_102 ) ;
return V_7 ;
}
static void T_7 F_77 ( void )
{
F_78 ( L_3 ) ;
F_79 ( & V_103 ) ;
F_76 ( & V_102 ) ;
#ifdef F_75
F_45 ( V_105 , NULL ) ;
F_45 ( V_106 , NULL ) ;
#endif
F_80 () ;
}
