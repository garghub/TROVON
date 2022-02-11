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
static int
F_4 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
T_1 V_20 ;
T_2 V_21 ;
struct V_2 * V_3 ;
struct V_8 * V_22 , * V_23 = NULL ;
struct V_4 * V_4 = F_5 ( V_16 -> V_24 ) ;
char * V_25 ;
int V_7 ;
if ( ! V_19 [ V_26 ] ||
! V_19 [ V_27 ] ||
! V_19 [ V_28 ] ||
! V_19 [ V_29 ] )
return - V_30 ;
V_25 = F_6 ( V_19 [ V_26 ] ) ;
V_20 = F_7 ( F_8 ( V_19 [ V_27 ] ) ) ;
V_21 = F_9 ( V_19 [ V_28 ] ) ;
F_10 (timeout, &cttimeout_list, head) {
if ( strncmp ( V_22 -> V_25 , V_25 , V_31 ) != 0 )
continue;
if ( V_18 -> V_32 & V_33 )
return - V_34 ;
V_23 = V_22 ;
break;
}
V_3 = F_11 ( V_20 , V_21 ) ;
if ( V_3 -> V_3 != V_21 ) {
V_7 = - V_35 ;
goto V_36;
}
if ( V_23 ) {
if ( V_18 -> V_32 & V_37 ) {
if ( V_23 -> V_20 != V_20 ||
V_23 -> V_3 -> V_3 != V_21 ) {
V_7 = - V_30 ;
goto V_36;
}
V_7 = F_1 ( & V_23 -> V_38 ,
V_3 , V_4 ,
V_19 [ V_29 ] ) ;
return V_7 ;
}
V_7 = - V_39 ;
goto V_36;
}
V_22 = F_12 ( sizeof( struct V_8 ) +
V_3 -> V_8 . V_40 , V_41 ) ;
if ( V_22 == NULL ) {
V_7 = - V_42 ;
goto V_36;
}
V_7 = F_1 ( & V_22 -> V_38 , V_3 , V_4 ,
V_19 [ V_29 ] ) ;
if ( V_7 < 0 )
goto V_43;
strcpy ( V_22 -> V_25 , F_6 ( V_19 [ V_26 ] ) ) ;
V_22 -> V_20 = V_20 ;
V_22 -> V_3 = V_3 ;
F_13 ( & V_22 -> V_44 , 1 ) ;
F_14 ( & V_22 -> V_45 , & V_46 ) ;
return 0 ;
V_43:
F_15 ( V_22 ) ;
V_36:
F_16 ( V_3 ) ;
return V_7 ;
}
static int
F_17 ( struct V_15 * V_16 , T_3 V_47 , T_3 V_48 , T_3 type ,
int V_49 , struct V_8 * V_22 )
{
struct V_17 * V_18 ;
struct V_50 * V_51 ;
unsigned int V_52 = V_47 ? V_53 : 0 ;
struct V_2 * V_3 = V_22 -> V_3 ;
V_49 |= V_54 << 8 ;
V_18 = F_18 ( V_16 , V_47 , V_48 , V_49 , sizeof( * V_51 ) , V_52 ) ;
if ( V_18 == NULL )
goto V_55;
V_51 = F_19 ( V_18 ) ;
V_51 -> V_56 = V_57 ;
V_51 -> V_58 = V_59 ;
V_51 -> V_60 = 0 ;
if ( F_20 ( V_16 , V_26 , V_22 -> V_25 ) ||
F_21 ( V_16 , V_27 , F_22 ( V_22 -> V_20 ) ) ||
F_23 ( V_16 , V_28 , V_22 -> V_3 -> V_3 ) ||
F_24 ( V_16 , V_61 ,
F_25 ( F_26 ( & V_22 -> V_44 ) ) ) )
goto V_62;
if ( F_2 ( V_3 -> V_8 . V_63 ) ) {
struct V_5 * V_64 ;
int V_7 ;
V_64 = F_27 ( V_16 ,
V_29 | V_65 ) ;
if ( ! V_64 )
goto V_62;
V_7 = V_3 -> V_8 . V_63 ( V_16 , & V_22 -> V_38 ) ;
if ( V_7 < 0 )
goto V_62;
F_28 ( V_16 , V_64 ) ;
}
F_29 ( V_16 , V_18 ) ;
return V_16 -> V_66 ;
V_55:
V_62:
F_30 ( V_16 , V_18 ) ;
return - 1 ;
}
static int
F_31 ( struct V_15 * V_16 , struct V_67 * V_68 )
{
struct V_8 * V_69 , * V_70 ;
if ( V_68 -> args [ 2 ] )
return 0 ;
V_70 = (struct V_8 * ) V_68 -> args [ 1 ] ;
if ( V_68 -> args [ 1 ] )
V_68 -> args [ 1 ] = 0 ;
F_32 () ;
F_33 (cur, &cttimeout_list, head) {
if ( V_70 ) {
if ( V_69 != V_70 )
continue;
V_70 = NULL ;
}
if ( F_17 ( V_16 , F_34 ( V_68 -> V_16 ) . V_47 ,
V_68 -> V_18 -> V_71 ,
F_35 ( V_68 -> V_18 -> V_72 ) ,
V_73 , V_69 ) < 0 ) {
V_68 -> args [ 1 ] = ( unsigned long ) V_69 ;
break;
}
}
if ( ! V_68 -> args [ 1 ] )
V_68 -> args [ 2 ] = 1 ;
F_36 () ;
return V_16 -> V_66 ;
}
static int
F_37 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
int V_7 = - V_74 ;
char * V_25 ;
struct V_8 * V_69 ;
if ( V_18 -> V_32 & V_75 ) {
struct V_76 V_77 = {
. V_78 = F_31 ,
} ;
return F_38 ( V_14 , V_16 , V_18 , & V_77 ) ;
}
if ( ! V_19 [ V_26 ] )
return - V_30 ;
V_25 = F_6 ( V_19 [ V_26 ] ) ;
F_10 (cur, &cttimeout_list, head) {
struct V_15 * V_79 ;
if ( strncmp ( V_69 -> V_25 , V_25 , V_31 ) != 0 )
continue;
V_79 = F_39 ( V_80 , V_41 ) ;
if ( V_79 == NULL ) {
V_7 = - V_42 ;
break;
}
V_7 = F_17 ( V_79 , F_34 ( V_16 ) . V_47 ,
V_18 -> V_71 ,
F_35 ( V_18 -> V_72 ) ,
V_73 , V_69 ) ;
if ( V_7 <= 0 ) {
F_40 ( V_79 ) ;
break;
}
V_7 = F_41 ( V_14 , V_79 , F_34 ( V_16 ) . V_47 ,
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
static void F_46 ( struct V_8 * V_22 )
{
struct V_84 * V_90 ;
const struct V_91 * V_92 ;
int V_85 ;
F_47 () ;
for ( V_85 = 0 ; V_85 < V_93 . V_87 . V_94 ; V_85 ++ ) {
F_48 ( & V_95 [ V_85 % V_96 ] ) ;
if ( V_85 < V_93 . V_87 . V_94 ) {
F_49 (h, nn, &init_net.ct.hash[i], hnnode)
F_42 ( V_90 , V_22 ) ;
}
F_50 ( & V_95 [ V_85 % V_96 ] ) ;
}
F_51 () ;
}
static int F_52 ( struct V_8 * V_22 )
{
int V_7 = 0 ;
if ( F_53 ( & V_22 -> V_44 ) ) {
F_54 ( & V_22 -> V_45 ) ;
F_16 ( V_22 -> V_3 ) ;
F_46 ( V_22 ) ;
F_55 ( V_22 , V_97 ) ;
} else {
F_56 ( & V_22 -> V_44 ) ;
V_7 = - V_39 ;
}
return V_7 ;
}
static int
F_57 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
char * V_25 ;
struct V_8 * V_69 ;
int V_7 = - V_74 ;
if ( ! V_19 [ V_26 ] ) {
F_10 (cur, &cttimeout_list, head)
F_52 ( V_69 ) ;
return 0 ;
}
V_25 = F_6 ( V_19 [ V_26 ] ) ;
F_10 (cur, &cttimeout_list, head) {
if ( strncmp ( V_69 -> V_25 , V_25 , V_31 ) != 0 )
continue;
V_7 = F_52 ( V_69 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
}
return V_7 ;
}
static int
F_58 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
T_1 V_20 ;
T_2 V_21 ;
struct V_2 * V_3 ;
struct V_4 * V_4 = F_5 ( V_16 -> V_24 ) ;
unsigned int * V_1 ;
int V_7 ;
if ( ! V_19 [ V_27 ] ||
! V_19 [ V_28 ] ||
! V_19 [ V_29 ] )
return - V_30 ;
V_20 = F_7 ( F_8 ( V_19 [ V_27 ] ) ) ;
V_21 = F_9 ( V_19 [ V_28 ] ) ;
V_3 = F_11 ( V_20 , V_21 ) ;
if ( V_3 -> V_3 != V_21 ) {
V_7 = - V_35 ;
goto V_43;
}
V_1 = V_3 -> V_98 ( V_4 ) ;
V_7 = F_1 ( V_1 , V_3 , V_4 ,
V_19 [ V_29 ] ) ;
if ( V_7 < 0 )
goto V_43;
F_16 ( V_3 ) ;
return 0 ;
V_43:
F_16 ( V_3 ) ;
return V_7 ;
}
static int
F_59 ( struct V_4 * V_4 , struct V_15 * V_16 , T_3 V_47 ,
T_3 V_48 , T_3 type , int V_49 ,
struct V_2 * V_3 )
{
struct V_17 * V_18 ;
struct V_50 * V_51 ;
unsigned int V_52 = V_47 ? V_53 : 0 ;
V_49 |= V_54 << 8 ;
V_18 = F_18 ( V_16 , V_47 , V_48 , V_49 , sizeof( * V_51 ) , V_52 ) ;
if ( V_18 == NULL )
goto V_55;
V_51 = F_19 ( V_18 ) ;
V_51 -> V_56 = V_57 ;
V_51 -> V_58 = V_59 ;
V_51 -> V_60 = 0 ;
if ( F_21 ( V_16 , V_27 , F_22 ( V_3 -> V_99 ) ) ||
F_23 ( V_16 , V_28 , V_3 -> V_3 ) )
goto V_62;
if ( F_2 ( V_3 -> V_8 . V_63 ) ) {
struct V_5 * V_64 ;
unsigned int * V_1 = V_3 -> V_98 ( V_4 ) ;
int V_7 ;
V_64 = F_27 ( V_16 ,
V_29 | V_65 ) ;
if ( ! V_64 )
goto V_62;
V_7 = V_3 -> V_8 . V_63 ( V_16 , V_1 ) ;
if ( V_7 < 0 )
goto V_62;
F_28 ( V_16 , V_64 ) ;
}
F_29 ( V_16 , V_18 ) ;
return V_16 -> V_66 ;
V_55:
V_62:
F_30 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_60 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
T_1 V_20 ;
T_2 V_21 ;
struct V_2 * V_3 ;
struct V_4 * V_4 = F_5 ( V_16 -> V_24 ) ;
struct V_15 * V_79 ;
int V_7 , V_43 ;
if ( ! V_19 [ V_27 ] || ! V_19 [ V_28 ] )
return - V_30 ;
V_20 = F_7 ( F_8 ( V_19 [ V_27 ] ) ) ;
V_21 = F_9 ( V_19 [ V_28 ] ) ;
V_3 = F_11 ( V_20 , V_21 ) ;
if ( V_3 -> V_3 != V_21 ) {
V_43 = - V_35 ;
goto V_43;
}
V_79 = F_39 ( V_80 , V_41 ) ;
if ( V_79 == NULL ) {
V_43 = - V_42 ;
goto V_43;
}
V_7 = F_59 ( V_4 , V_79 , F_34 ( V_16 ) . V_47 ,
V_18 -> V_71 ,
F_35 ( V_18 -> V_72 ) ,
V_100 ,
V_3 ) ;
if ( V_7 <= 0 ) {
F_40 ( V_79 ) ;
V_43 = - V_42 ;
goto V_43;
}
V_7 = F_41 ( V_14 , V_79 , F_34 ( V_16 ) . V_47 , V_81 ) ;
if ( V_7 > 0 )
V_7 = 0 ;
return V_7 == - V_82 ? - V_83 : V_7 ;
V_43:
F_16 ( V_3 ) ;
return V_43 ;
}
static struct V_8 * F_61 ( const char * V_25 )
{
struct V_8 * V_22 , * V_23 = NULL ;
F_32 () ;
F_33 (timeout, &cttimeout_list, head) {
if ( strncmp ( V_22 -> V_25 , V_25 , V_31 ) != 0 )
continue;
if ( ! F_62 ( V_101 ) )
goto V_43;
if ( ! F_63 ( & V_22 -> V_44 ) ) {
F_64 ( V_101 ) ;
goto V_43;
}
V_23 = V_22 ;
break;
}
V_43:
F_36 () ;
return V_23 ;
}
static void F_65 ( struct V_8 * V_22 )
{
F_66 ( & V_22 -> V_44 ) ;
F_64 ( V_101 ) ;
}
static int T_4 F_67 ( void )
{
int V_7 ;
V_7 = F_68 ( & V_102 ) ;
if ( V_7 < 0 ) {
F_69 ( L_1
L_2 ) ;
goto V_103;
}
#ifdef F_70
F_45 ( V_104 , F_61 ) ;
F_45 ( V_105 , F_65 ) ;
#endif
return 0 ;
V_103:
return V_7 ;
}
static void T_5 F_71 ( void )
{
struct V_8 * V_69 , * V_106 ;
F_72 ( L_3 ) ;
F_73 ( & V_102 ) ;
F_46 ( NULL ) ;
F_74 (cur, tmp, &cttimeout_list, head) {
F_54 ( & V_69 -> V_45 ) ;
F_16 ( V_69 -> V_3 ) ;
F_55 ( V_69 , V_97 ) ;
}
#ifdef F_70
F_45 ( V_104 , NULL ) ;
F_45 ( V_105 , NULL ) ;
#endif
F_75 () ;
}
