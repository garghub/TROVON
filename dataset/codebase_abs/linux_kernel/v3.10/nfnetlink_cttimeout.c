static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_5 ,
const struct V_6 * V_7 )
{
int V_8 = 0 ;
if ( F_2 ( V_4 -> V_1 . V_9 ) ) {
struct V_6 * V_10 [ V_4 -> V_1 . V_11 + 1 ] ;
F_3 ( V_10 , V_4 -> V_1 . V_11 ,
V_7 , V_4 -> V_1 . V_12 ) ;
V_8 = V_4 -> V_1 . V_9 ( V_10 , V_5 ,
& V_2 -> V_13 ) ;
}
return V_8 ;
}
static int
F_4 ( struct V_14 * V_15 , struct V_16 * V_17 ,
const struct V_18 * V_19 ,
const struct V_6 * const V_20 [] )
{
T_1 V_21 ;
T_2 V_22 ;
struct V_3 * V_4 ;
struct V_1 * V_2 , * V_23 = NULL ;
struct V_5 * V_5 = F_5 ( V_17 -> V_24 ) ;
char * V_25 ;
int V_8 ;
if ( ! V_20 [ V_26 ] ||
! V_20 [ V_27 ] ||
! V_20 [ V_28 ] ||
! V_20 [ V_29 ] )
return - V_30 ;
V_25 = F_6 ( V_20 [ V_26 ] ) ;
V_21 = F_7 ( F_8 ( V_20 [ V_27 ] ) ) ;
V_22 = F_9 ( V_20 [ V_28 ] ) ;
F_10 (timeout, &cttimeout_list, head) {
if ( strncmp ( V_2 -> V_25 , V_25 , V_31 ) != 0 )
continue;
if ( V_19 -> V_32 & V_33 )
return - V_34 ;
V_23 = V_2 ;
break;
}
V_4 = F_11 ( V_21 , V_22 ) ;
if ( V_4 -> V_4 != V_22 ) {
V_8 = - V_35 ;
goto V_36;
}
if ( V_23 ) {
if ( V_19 -> V_32 & V_37 ) {
if ( V_23 -> V_21 != V_21 ||
V_23 -> V_4 -> V_4 != V_22 ) {
V_8 = - V_30 ;
goto V_36;
}
V_8 = F_1 ( V_23 , V_4 , V_5 ,
V_20 [ V_29 ] ) ;
return V_8 ;
}
V_8 = - V_38 ;
goto V_36;
}
V_2 = F_12 ( sizeof( struct V_1 ) +
V_4 -> V_1 . V_39 , V_40 ) ;
if ( V_2 == NULL ) {
V_8 = - V_41 ;
goto V_36;
}
V_8 = F_1 ( V_2 , V_4 , V_5 ,
V_20 [ V_29 ] ) ;
if ( V_8 < 0 )
goto V_42;
strcpy ( V_2 -> V_25 , F_6 ( V_20 [ V_26 ] ) ) ;
V_2 -> V_21 = V_21 ;
V_2 -> V_4 = V_4 ;
F_13 ( & V_2 -> V_43 , 1 ) ;
F_14 ( & V_2 -> V_44 , & V_45 ) ;
return 0 ;
V_42:
F_15 ( V_2 ) ;
V_36:
F_16 ( V_4 ) ;
return V_8 ;
}
static int
F_17 ( struct V_16 * V_17 , T_3 V_46 , T_3 V_47 , T_3 type ,
int V_48 , struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_49 * V_50 ;
unsigned int V_51 = V_46 ? V_52 : 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_48 |= V_53 << 8 ;
V_19 = F_18 ( V_17 , V_46 , V_47 , V_48 , sizeof( * V_50 ) , V_51 ) ;
if ( V_19 == NULL )
goto V_54;
V_50 = F_19 ( V_19 ) ;
V_50 -> V_55 = V_56 ;
V_50 -> V_57 = V_58 ;
V_50 -> V_59 = 0 ;
if ( F_20 ( V_17 , V_26 , V_2 -> V_25 ) ||
F_21 ( V_17 , V_27 , F_22 ( V_2 -> V_21 ) ) ||
F_23 ( V_17 , V_28 , V_2 -> V_4 -> V_4 ) ||
F_24 ( V_17 , V_60 ,
F_25 ( F_26 ( & V_2 -> V_43 ) ) ) )
goto V_61;
if ( F_2 ( V_4 -> V_1 . V_62 ) ) {
struct V_6 * V_63 ;
int V_8 ;
V_63 = F_27 ( V_17 ,
V_29 | V_64 ) ;
if ( ! V_63 )
goto V_61;
V_8 = V_4 -> V_1 . V_62 ( V_17 , & V_2 -> V_13 ) ;
if ( V_8 < 0 )
goto V_61;
F_28 ( V_17 , V_63 ) ;
}
F_29 ( V_17 , V_19 ) ;
return V_17 -> V_65 ;
V_54:
V_61:
F_30 ( V_17 , V_19 ) ;
return - 1 ;
}
static int
F_31 ( struct V_16 * V_17 , struct V_66 * V_67 )
{
struct V_1 * V_68 , * V_69 ;
if ( V_67 -> args [ 2 ] )
return 0 ;
V_69 = (struct V_1 * ) V_67 -> args [ 1 ] ;
if ( V_67 -> args [ 1 ] )
V_67 -> args [ 1 ] = 0 ;
F_32 () ;
F_33 (cur, &cttimeout_list, head) {
if ( V_69 ) {
if ( V_68 != V_69 )
continue;
V_69 = NULL ;
}
if ( F_17 ( V_17 , F_34 ( V_67 -> V_17 ) . V_46 ,
V_67 -> V_19 -> V_70 ,
F_35 ( V_67 -> V_19 -> V_71 ) ,
V_72 , V_68 ) < 0 ) {
V_67 -> args [ 1 ] = ( unsigned long ) V_68 ;
break;
}
}
if ( ! V_67 -> args [ 1 ] )
V_67 -> args [ 2 ] = 1 ;
F_36 () ;
return V_17 -> V_65 ;
}
static int
F_37 ( struct V_14 * V_15 , struct V_16 * V_17 ,
const struct V_18 * V_19 ,
const struct V_6 * const V_20 [] )
{
int V_8 = - V_73 ;
char * V_25 ;
struct V_1 * V_68 ;
if ( V_19 -> V_32 & V_74 ) {
struct V_75 V_76 = {
. V_77 = F_31 ,
} ;
return F_38 ( V_15 , V_17 , V_19 , & V_76 ) ;
}
if ( ! V_20 [ V_26 ] )
return - V_30 ;
V_25 = F_6 ( V_20 [ V_26 ] ) ;
F_10 (cur, &cttimeout_list, head) {
struct V_16 * V_78 ;
if ( strncmp ( V_68 -> V_25 , V_25 , V_31 ) != 0 )
continue;
V_78 = F_39 ( V_79 , V_40 ) ;
if ( V_78 == NULL ) {
V_8 = - V_41 ;
break;
}
V_8 = F_17 ( V_78 , F_34 ( V_17 ) . V_46 ,
V_19 -> V_70 ,
F_35 ( V_19 -> V_71 ) ,
V_72 , V_68 ) ;
if ( V_8 <= 0 ) {
F_40 ( V_78 ) ;
break;
}
V_8 = F_41 ( V_15 , V_78 , F_34 ( V_17 ) . V_46 ,
V_80 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
return V_8 == - V_81 ? - V_82 : V_8 ;
}
return V_8 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
if ( F_43 ( & V_2 -> V_43 ) ) {
F_44 ( & V_2 -> V_44 ) ;
F_16 ( V_2 -> V_4 ) ;
F_45 ( V_2 , V_83 ) ;
} else {
F_46 ( & V_2 -> V_43 ) ;
V_8 = - V_38 ;
}
return V_8 ;
}
static int
F_47 ( struct V_14 * V_15 , struct V_16 * V_17 ,
const struct V_18 * V_19 ,
const struct V_6 * const V_20 [] )
{
char * V_25 ;
struct V_1 * V_68 ;
int V_8 = - V_73 ;
if ( ! V_20 [ V_26 ] ) {
F_10 (cur, &cttimeout_list, head)
F_42 ( V_68 ) ;
return 0 ;
}
V_25 = F_6 ( V_20 [ V_26 ] ) ;
F_10 (cur, &cttimeout_list, head) {
if ( strncmp ( V_68 -> V_25 , V_25 , V_31 ) != 0 )
continue;
V_8 = F_42 ( V_68 ) ;
if ( V_8 < 0 )
return V_8 ;
break;
}
return V_8 ;
}
static struct V_1 * F_48 ( const char * V_25 )
{
struct V_1 * V_2 , * V_23 = NULL ;
F_32 () ;
F_33 (timeout, &cttimeout_list, head) {
if ( strncmp ( V_2 -> V_25 , V_25 , V_31 ) != 0 )
continue;
if ( ! F_49 ( V_84 ) )
goto V_42;
if ( ! F_50 ( & V_2 -> V_43 ) ) {
F_51 ( V_84 ) ;
goto V_42;
}
V_23 = V_2 ;
break;
}
V_42:
F_36 () ;
return V_23 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_43 ) ;
F_51 ( V_84 ) ;
}
static int T_4 F_54 ( void )
{
int V_8 ;
V_8 = F_55 ( & V_85 ) ;
if ( V_8 < 0 ) {
F_56 ( L_1
L_2 ) ;
goto V_86;
}
#ifdef F_57
F_58 ( V_87 , F_48 ) ;
F_58 ( V_88 , F_52 ) ;
#endif
return 0 ;
V_86:
return V_8 ;
}
static void T_5 F_59 ( void )
{
struct V_1 * V_68 , * V_89 ;
F_60 ( L_3 ) ;
F_61 ( & V_85 ) ;
F_62 (cur, tmp, &cttimeout_list, head) {
F_44 ( & V_68 -> V_44 ) ;
F_16 ( V_68 -> V_4 ) ;
F_45 ( V_68 , V_83 ) ;
}
#ifdef F_57
F_58 ( V_87 , NULL ) ;
F_58 ( V_88 , NULL ) ;
#endif
}
