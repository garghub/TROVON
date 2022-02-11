static int
F_1 ( void * V_1 ,
const struct V_2 * V_3 ,
struct V_4 * V_4 , const struct V_5 * V_6 )
{
int V_7 = 0 ;
if ( F_2 ( V_3 -> V_8 . V_9 ) ) {
struct V_5 * V_10 [ V_3 -> V_8 . V_11 + 1 ] ;
V_7 = F_3 ( V_10 , V_3 -> V_8 . V_11 ,
V_6 , V_3 -> V_8 . V_12 ,
NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_3 -> V_8 . V_9 ( V_10 , V_4 , V_1 ) ;
}
return V_7 ;
}
static int F_4 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] ,
struct V_20 * V_21 )
{
T_1 V_22 ;
T_2 V_23 ;
const struct V_2 * V_3 ;
struct V_8 * V_24 , * V_25 = NULL ;
char * V_26 ;
int V_7 ;
if ( ! V_19 [ V_27 ] ||
! V_19 [ V_28 ] ||
! V_19 [ V_29 ] ||
! V_19 [ V_30 ] )
return - V_31 ;
V_26 = F_5 ( V_19 [ V_27 ] ) ;
V_22 = F_6 ( F_7 ( V_19 [ V_28 ] ) ) ;
V_23 = F_8 ( V_19 [ V_29 ] ) ;
F_9 (timeout, &net->nfct_timeout_list, head) {
if ( strncmp ( V_24 -> V_26 , V_26 , V_32 ) != 0 )
continue;
if ( V_18 -> V_33 & V_34 )
return - V_35 ;
V_25 = V_24 ;
break;
}
if ( V_25 ) {
if ( V_18 -> V_33 & V_36 ) {
if ( V_25 -> V_22 != V_22 ||
V_25 -> V_3 -> V_3 != V_23 )
return - V_31 ;
return F_1 ( & V_25 -> V_37 ,
V_25 -> V_3 , V_4 ,
V_19 [ V_30 ] ) ;
}
return - V_38 ;
}
V_3 = F_10 ( V_22 , V_23 ) ;
if ( V_3 -> V_3 != V_23 ) {
V_7 = - V_39 ;
goto V_40;
}
V_24 = F_11 ( sizeof( struct V_8 ) +
V_3 -> V_8 . V_41 , V_42 ) ;
if ( V_24 == NULL ) {
V_7 = - V_43 ;
goto V_40;
}
V_7 = F_1 ( & V_24 -> V_37 , V_3 , V_4 ,
V_19 [ V_30 ] ) ;
if ( V_7 < 0 )
goto V_44;
strcpy ( V_24 -> V_26 , F_5 ( V_19 [ V_27 ] ) ) ;
V_24 -> V_22 = V_22 ;
V_24 -> V_3 = V_3 ;
F_12 ( & V_24 -> V_45 , 1 ) ;
F_13 ( & V_24 -> V_46 , & V_4 -> V_47 ) ;
return 0 ;
V_44:
F_14 ( V_24 ) ;
V_40:
F_15 ( V_3 ) ;
return V_7 ;
}
static int
F_16 ( struct V_15 * V_16 , T_3 V_48 , T_3 V_49 , T_3 type ,
int V_50 , struct V_8 * V_24 )
{
struct V_17 * V_18 ;
struct V_51 * V_52 ;
unsigned int V_53 = V_48 ? V_54 : 0 ;
const struct V_2 * V_3 = V_24 -> V_3 ;
V_50 = F_17 ( V_55 , V_50 ) ;
V_18 = F_18 ( V_16 , V_48 , V_49 , V_50 , sizeof( * V_52 ) , V_53 ) ;
if ( V_18 == NULL )
goto V_56;
V_52 = F_19 ( V_18 ) ;
V_52 -> V_57 = V_58 ;
V_52 -> V_59 = V_60 ;
V_52 -> V_61 = 0 ;
if ( F_20 ( V_16 , V_27 , V_24 -> V_26 ) ||
F_21 ( V_16 , V_28 , F_22 ( V_24 -> V_22 ) ) ||
F_23 ( V_16 , V_29 , V_24 -> V_3 -> V_3 ) ||
F_24 ( V_16 , V_62 ,
F_25 ( F_26 ( & V_24 -> V_45 ) ) ) )
goto V_63;
if ( F_2 ( V_3 -> V_8 . V_64 ) ) {
struct V_5 * V_65 ;
int V_7 ;
V_65 = F_27 ( V_16 ,
V_30 | V_66 ) ;
if ( ! V_65 )
goto V_63;
V_7 = V_3 -> V_8 . V_64 ( V_16 , & V_24 -> V_37 ) ;
if ( V_7 < 0 )
goto V_63;
F_28 ( V_16 , V_65 ) ;
}
F_29 ( V_16 , V_18 ) ;
return V_16 -> V_67 ;
V_56:
V_63:
F_30 ( V_16 , V_18 ) ;
return - 1 ;
}
static int
F_31 ( struct V_15 * V_16 , struct V_68 * V_69 )
{
struct V_4 * V_4 = F_32 ( V_16 -> V_70 ) ;
struct V_8 * V_71 , * V_72 ;
if ( V_69 -> args [ 2 ] )
return 0 ;
V_72 = (struct V_8 * ) V_69 -> args [ 1 ] ;
if ( V_69 -> args [ 1 ] )
V_69 -> args [ 1 ] = 0 ;
F_33 () ;
F_34 (cur, &net->nfct_timeout_list, head) {
if ( V_72 ) {
if ( V_71 != V_72 )
continue;
V_72 = NULL ;
}
if ( F_16 ( V_16 , F_35 ( V_69 -> V_16 ) . V_48 ,
V_69 -> V_18 -> V_73 ,
F_36 ( V_69 -> V_18 -> V_74 ) ,
V_75 , V_71 ) < 0 ) {
V_69 -> args [ 1 ] = ( unsigned long ) V_71 ;
break;
}
}
if ( ! V_69 -> args [ 1 ] )
V_69 -> args [ 2 ] = 1 ;
F_37 () ;
return V_16 -> V_67 ;
}
static int F_38 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] ,
struct V_20 * V_21 )
{
int V_7 = - V_76 ;
char * V_26 ;
struct V_8 * V_71 ;
if ( V_18 -> V_33 & V_77 ) {
struct V_78 V_79 = {
. V_80 = F_31 ,
} ;
return F_39 ( V_14 , V_16 , V_18 , & V_79 ) ;
}
if ( ! V_19 [ V_27 ] )
return - V_31 ;
V_26 = F_5 ( V_19 [ V_27 ] ) ;
F_9 (cur, &net->nfct_timeout_list, head) {
struct V_15 * V_81 ;
if ( strncmp ( V_71 -> V_26 , V_26 , V_32 ) != 0 )
continue;
V_81 = F_40 ( V_82 , V_42 ) ;
if ( V_81 == NULL ) {
V_7 = - V_43 ;
break;
}
V_7 = F_16 ( V_81 , F_35 ( V_16 ) . V_48 ,
V_18 -> V_73 ,
F_36 ( V_18 -> V_74 ) ,
V_75 , V_71 ) ;
if ( V_7 <= 0 ) {
F_41 ( V_81 ) ;
break;
}
V_7 = F_42 ( V_14 , V_81 , F_35 ( V_16 ) . V_48 ,
V_83 ) ;
if ( V_7 > 0 )
V_7 = 0 ;
return V_7 == - V_84 ? - V_85 : V_7 ;
}
return V_7 ;
}
static int F_43 ( struct V_86 * V_87 , void * V_24 )
{
struct V_88 * V_89 = F_44 ( V_87 ) ;
if ( V_89 && ( ! V_24 || V_89 -> V_24 == V_24 ) )
F_45 ( V_89 -> V_24 , NULL ) ;
return 0 ;
}
static void F_46 ( struct V_4 * V_4 , struct V_8 * V_24 )
{
F_47 ( V_4 , F_43 , V_24 , 0 , 0 ) ;
}
static int F_48 ( struct V_4 * V_4 , struct V_8 * V_24 )
{
int V_7 = 0 ;
if ( F_49 ( & V_24 -> V_45 ) ) {
F_50 ( & V_24 -> V_46 ) ;
F_15 ( V_24 -> V_3 ) ;
F_46 ( V_4 , V_24 ) ;
F_51 ( V_24 , V_90 ) ;
} else {
V_7 = - V_38 ;
}
return V_7 ;
}
static int F_52 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] ,
struct V_20 * V_21 )
{
struct V_8 * V_71 , * V_91 ;
int V_7 = - V_76 ;
char * V_26 ;
if ( ! V_19 [ V_27 ] ) {
F_53 (cur, tmp, &net->nfct_timeout_list,
head)
F_48 ( V_4 , V_71 ) ;
return 0 ;
}
V_26 = F_5 ( V_19 [ V_27 ] ) ;
F_9 (cur, &net->nfct_timeout_list, head) {
if ( strncmp ( V_71 -> V_26 , V_26 , V_32 ) != 0 )
continue;
V_7 = F_48 ( V_4 , V_71 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
}
return V_7 ;
}
static int F_54 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] ,
struct V_20 * V_21 )
{
const struct V_2 * V_3 ;
unsigned int * V_1 ;
T_1 V_22 ;
T_2 V_23 ;
int V_7 ;
if ( ! V_19 [ V_28 ] ||
! V_19 [ V_29 ] ||
! V_19 [ V_30 ] )
return - V_31 ;
V_22 = F_6 ( F_7 ( V_19 [ V_28 ] ) ) ;
V_23 = F_8 ( V_19 [ V_29 ] ) ;
V_3 = F_10 ( V_22 , V_23 ) ;
if ( V_3 -> V_3 != V_23 ) {
V_7 = - V_39 ;
goto V_44;
}
V_1 = V_3 -> V_92 ( V_4 ) ;
V_7 = F_1 ( V_1 , V_3 , V_4 ,
V_19 [ V_30 ] ) ;
if ( V_7 < 0 )
goto V_44;
F_15 ( V_3 ) ;
return 0 ;
V_44:
F_15 ( V_3 ) ;
return V_7 ;
}
static int
F_55 ( struct V_4 * V_4 , struct V_15 * V_16 , T_3 V_48 ,
T_3 V_49 , T_3 type , int V_50 ,
const struct V_2 * V_3 )
{
struct V_17 * V_18 ;
struct V_51 * V_52 ;
unsigned int V_53 = V_48 ? V_54 : 0 ;
V_50 = F_17 ( V_55 , V_50 ) ;
V_18 = F_18 ( V_16 , V_48 , V_49 , V_50 , sizeof( * V_52 ) , V_53 ) ;
if ( V_18 == NULL )
goto V_56;
V_52 = F_19 ( V_18 ) ;
V_52 -> V_57 = V_58 ;
V_52 -> V_59 = V_60 ;
V_52 -> V_61 = 0 ;
if ( F_21 ( V_16 , V_28 , F_22 ( V_3 -> V_93 ) ) ||
F_23 ( V_16 , V_29 , V_3 -> V_3 ) )
goto V_63;
if ( F_2 ( V_3 -> V_8 . V_64 ) ) {
struct V_5 * V_65 ;
unsigned int * V_1 = V_3 -> V_92 ( V_4 ) ;
int V_7 ;
V_65 = F_27 ( V_16 ,
V_30 | V_66 ) ;
if ( ! V_65 )
goto V_63;
V_7 = V_3 -> V_8 . V_64 ( V_16 , V_1 ) ;
if ( V_7 < 0 )
goto V_63;
F_28 ( V_16 , V_65 ) ;
}
F_29 ( V_16 , V_18 ) ;
return V_16 -> V_67 ;
V_56:
V_63:
F_30 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_56 ( struct V_4 * V_4 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] ,
struct V_20 * V_21 )
{
const struct V_2 * V_3 ;
struct V_15 * V_81 ;
int V_7 , V_44 ;
T_1 V_22 ;
T_2 V_23 ;
if ( ! V_19 [ V_28 ] || ! V_19 [ V_29 ] )
return - V_31 ;
V_22 = F_6 ( F_7 ( V_19 [ V_28 ] ) ) ;
V_23 = F_8 ( V_19 [ V_29 ] ) ;
V_3 = F_10 ( V_22 , V_23 ) ;
if ( V_3 -> V_3 != V_23 ) {
V_44 = - V_39 ;
goto V_44;
}
V_81 = F_40 ( V_82 , V_42 ) ;
if ( V_81 == NULL ) {
V_44 = - V_43 ;
goto V_44;
}
V_7 = F_55 ( V_4 , V_81 , F_35 ( V_16 ) . V_48 ,
V_18 -> V_73 ,
F_36 ( V_18 -> V_74 ) ,
V_94 ,
V_3 ) ;
if ( V_7 <= 0 ) {
F_41 ( V_81 ) ;
V_44 = - V_43 ;
goto V_44;
}
V_7 = F_42 ( V_14 , V_81 , F_35 ( V_16 ) . V_48 , V_83 ) ;
if ( V_7 > 0 )
V_7 = 0 ;
return V_7 == - V_84 ? - V_85 : V_7 ;
V_44:
F_15 ( V_3 ) ;
return V_44 ;
}
static struct V_8 *
F_57 ( struct V_4 * V_4 , const char * V_26 )
{
struct V_8 * V_24 , * V_25 = NULL ;
F_34 (timeout, &net->nfct_timeout_list, head) {
if ( strncmp ( V_24 -> V_26 , V_26 , V_32 ) != 0 )
continue;
if ( ! F_58 ( V_95 ) )
goto V_44;
if ( ! F_59 ( & V_24 -> V_45 ) ) {
F_60 ( V_95 ) ;
goto V_44;
}
V_25 = V_24 ;
break;
}
V_44:
return V_25 ;
}
static void F_61 ( struct V_8 * V_24 )
{
if ( F_62 ( & V_24 -> V_45 ) )
F_51 ( V_24 , V_90 ) ;
F_60 ( V_95 ) ;
}
static int T_4 F_63 ( struct V_4 * V_4 )
{
F_64 ( & V_4 -> V_47 ) ;
return 0 ;
}
static void T_5 F_65 ( struct V_4 * V_4 )
{
struct V_8 * V_71 , * V_91 ;
F_66 ( V_4 ) ;
F_46 ( V_4 , NULL ) ;
F_53 (cur, tmp, &net->nfct_timeout_list, head) {
F_50 ( & V_71 -> V_46 ) ;
F_15 ( V_71 -> V_3 ) ;
if ( F_62 ( & V_71 -> V_45 ) )
F_51 ( V_71 , V_90 ) ;
}
}
static int T_6 F_67 ( void )
{
int V_7 ;
V_7 = F_68 ( & V_96 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_69 ( & V_97 ) ;
if ( V_7 < 0 ) {
F_70 ( L_1
L_2 ) ;
goto V_98;
}
#ifdef F_71
F_45 ( V_99 , F_57 ) ;
F_45 ( V_100 , F_61 ) ;
#endif
return 0 ;
V_98:
F_72 ( & V_96 ) ;
return V_7 ;
}
static void T_7 F_73 ( void )
{
F_74 ( L_3 ) ;
F_75 ( & V_97 ) ;
F_72 ( & V_96 ) ;
#ifdef F_71
F_45 ( V_99 , NULL ) ;
F_45 ( V_100 , NULL ) ;
F_76 () ;
#endif
}
