static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_7 = 0 ;
if ( F_2 ( V_4 -> V_1 . V_8 ) ) {
struct V_5 * V_9 [ V_4 -> V_1 . V_10 + 1 ] ;
F_3 ( V_9 , V_4 -> V_1 . V_10 ,
V_6 , V_4 -> V_1 . V_11 ) ;
V_7 = V_4 -> V_1 . V_8 ( V_9 , & V_2 -> V_12 ) ;
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
struct V_3 * V_4 ;
struct V_1 * V_2 , * V_22 = NULL ;
char * V_23 ;
int V_7 ;
if ( ! V_19 [ V_24 ] ||
! V_19 [ V_25 ] ||
! V_19 [ V_26 ] ||
! V_19 [ V_27 ] )
return - V_28 ;
V_23 = F_5 ( V_19 [ V_24 ] ) ;
V_20 = F_6 ( F_7 ( V_19 [ V_25 ] ) ) ;
V_21 = F_8 ( V_19 [ V_26 ] ) ;
F_9 (timeout, &cttimeout_list, head) {
if ( strncmp ( V_2 -> V_23 , V_23 , V_29 ) != 0 )
continue;
if ( V_18 -> V_30 & V_31 )
return - V_32 ;
V_22 = V_2 ;
break;
}
V_4 = F_10 ( V_20 , V_21 ) ;
if ( V_4 -> V_4 != V_21 ) {
V_7 = - V_33 ;
goto V_34;
}
if ( V_22 ) {
if ( V_18 -> V_30 & V_35 ) {
if ( V_22 -> V_20 != V_20 ||
V_22 -> V_4 -> V_4 != V_21 ) {
V_7 = - V_28 ;
goto V_34;
}
V_7 = F_1 ( V_22 , V_4 ,
V_19 [ V_27 ] ) ;
return V_7 ;
}
V_7 = - V_36 ;
goto V_34;
}
V_2 = F_11 ( sizeof( struct V_1 ) +
V_4 -> V_1 . V_37 , V_38 ) ;
if ( V_2 == NULL ) {
V_7 = - V_39 ;
goto V_34;
}
V_7 = F_1 ( V_2 , V_4 ,
V_19 [ V_27 ] ) ;
if ( V_7 < 0 )
goto V_40;
strcpy ( V_2 -> V_23 , F_5 ( V_19 [ V_24 ] ) ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_4 = V_4 ;
F_12 ( & V_2 -> V_41 , 1 ) ;
F_13 ( & V_2 -> V_42 , & V_43 ) ;
return 0 ;
V_40:
F_14 ( V_2 ) ;
V_34:
F_15 ( V_4 ) ;
return V_7 ;
}
static int
F_16 ( struct V_15 * V_16 , T_3 V_44 , T_3 V_45 , T_3 type ,
int V_46 , struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_47 * V_48 ;
unsigned int V_49 = V_44 ? V_50 : 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 |= V_51 << 8 ;
V_18 = F_17 ( V_16 , V_44 , V_45 , V_46 , sizeof( * V_48 ) , V_49 ) ;
if ( V_18 == NULL )
goto V_52;
V_48 = F_18 ( V_18 ) ;
V_48 -> V_53 = V_54 ;
V_48 -> V_55 = V_56 ;
V_48 -> V_57 = 0 ;
F_19 ( V_16 , V_24 , V_2 -> V_23 ) ;
F_20 ( V_16 , V_25 , F_21 ( V_2 -> V_20 ) ) ;
F_22 ( V_16 , V_26 , V_2 -> V_4 -> V_4 ) ;
F_23 ( V_16 , V_58 ,
F_24 ( F_25 ( & V_2 -> V_41 ) ) ) ;
if ( F_2 ( V_4 -> V_1 . V_59 ) ) {
struct V_5 * V_60 ;
int V_7 ;
V_60 = F_26 ( V_16 ,
V_27 | V_61 ) ;
if ( ! V_60 )
goto V_62;
V_7 = V_4 -> V_1 . V_59 ( V_16 , & V_2 -> V_12 ) ;
if ( V_7 < 0 )
goto V_62;
F_27 ( V_16 , V_60 ) ;
}
F_28 ( V_16 , V_18 ) ;
return V_16 -> V_63 ;
V_52:
V_62:
F_29 ( V_16 , V_18 ) ;
return - 1 ;
}
static int
F_30 ( struct V_15 * V_16 , struct V_64 * V_65 )
{
struct V_1 * V_66 , * V_67 ;
if ( V_65 -> args [ 2 ] )
return 0 ;
V_67 = (struct V_1 * ) V_65 -> args [ 1 ] ;
if ( V_65 -> args [ 1 ] )
V_65 -> args [ 1 ] = 0 ;
F_31 () ;
F_32 (cur, &cttimeout_list, head) {
if ( V_67 && V_66 != V_67 )
continue;
if ( F_16 ( V_16 , F_33 ( V_65 -> V_16 ) . V_44 ,
V_65 -> V_18 -> V_68 ,
F_34 ( V_65 -> V_18 -> V_69 ) ,
V_70 , V_66 ) < 0 ) {
V_65 -> args [ 1 ] = ( unsigned long ) V_66 ;
break;
}
}
if ( ! V_65 -> args [ 1 ] )
V_65 -> args [ 2 ] = 1 ;
F_35 () ;
return V_16 -> V_63 ;
}
static int
F_36 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
int V_7 = - V_71 ;
char * V_23 ;
struct V_1 * V_66 ;
if ( V_18 -> V_30 & V_72 ) {
struct V_73 V_74 = {
. V_75 = F_30 ,
} ;
return F_37 ( V_14 , V_16 , V_18 , & V_74 ) ;
}
if ( ! V_19 [ V_24 ] )
return - V_28 ;
V_23 = F_5 ( V_19 [ V_24 ] ) ;
F_9 (cur, &cttimeout_list, head) {
struct V_15 * V_76 ;
if ( strncmp ( V_66 -> V_23 , V_23 , V_29 ) != 0 )
continue;
V_76 = F_38 ( V_77 , V_38 ) ;
if ( V_76 == NULL ) {
V_7 = - V_39 ;
break;
}
V_7 = F_16 ( V_76 , F_33 ( V_16 ) . V_44 ,
V_18 -> V_68 ,
F_34 ( V_18 -> V_69 ) ,
V_70 , V_66 ) ;
if ( V_7 <= 0 ) {
F_39 ( V_76 ) ;
break;
}
V_7 = F_40 ( V_14 , V_76 , F_33 ( V_16 ) . V_44 ,
V_78 ) ;
if ( V_7 > 0 )
V_7 = 0 ;
return V_7 == - V_79 ? - V_80 : V_7 ;
}
return V_7 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
if ( F_42 ( & V_2 -> V_41 ) ) {
F_43 ( & V_2 -> V_42 ) ;
F_15 ( V_2 -> V_4 ) ;
F_44 ( V_2 , V_81 ) ;
} else {
F_45 ( & V_2 -> V_41 ) ;
V_7 = - V_36 ;
}
return V_7 ;
}
static int
F_46 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_5 * const V_19 [] )
{
char * V_23 ;
struct V_1 * V_66 ;
int V_7 = - V_71 ;
if ( ! V_19 [ V_24 ] ) {
F_9 (cur, &cttimeout_list, head)
F_41 ( V_66 ) ;
return 0 ;
}
V_23 = F_5 ( V_19 [ V_24 ] ) ;
F_9 (cur, &cttimeout_list, head) {
if ( strncmp ( V_66 -> V_23 , V_23 , V_29 ) != 0 )
continue;
V_7 = F_41 ( V_66 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
}
return V_7 ;
}
static struct V_1 * F_47 ( const char * V_23 )
{
struct V_1 * V_2 , * V_22 = NULL ;
F_31 () ;
F_32 (timeout, &cttimeout_list, head) {
if ( strncmp ( V_2 -> V_23 , V_23 , V_29 ) != 0 )
continue;
if ( ! F_48 ( V_82 ) )
goto V_40;
if ( ! F_49 ( & V_2 -> V_41 ) ) {
F_50 ( V_82 ) ;
goto V_40;
}
V_22 = V_2 ;
break;
}
V_40:
F_35 () ;
return V_22 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_41 ) ;
F_50 ( V_82 ) ;
}
static int T_4 F_53 ( void )
{
int V_7 ;
V_7 = F_54 ( & V_83 ) ;
if ( V_7 < 0 ) {
F_55 ( L_1
L_2 ) ;
goto V_84;
}
#ifdef F_56
F_57 ( V_85 , F_47 ) ;
F_57 ( V_86 , F_51 ) ;
#endif
return 0 ;
V_84:
return V_7 ;
}
static void T_5 F_58 ( void )
{
struct V_1 * V_66 , * V_87 ;
F_59 ( L_3 ) ;
F_60 ( & V_83 ) ;
F_61 (cur, tmp, &cttimeout_list, head) {
F_43 ( & V_66 -> V_42 ) ;
F_15 ( V_66 -> V_4 ) ;
F_44 ( V_66 , V_81 ) ;
}
#ifdef F_56
F_57 ( V_85 , NULL ) ;
F_57 ( V_86 , NULL ) ;
#endif
}
