static void F_1 ( char * V_1 , T_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( V_5 L_1 , V_1 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
F_2 ( V_5 L_2 , V_2 [ V_4 ] ) ;
if ( ( V_4 & 0xf ) == 0xf )
F_2 ( V_5 L_3 ) ;
}
F_2 ( V_5 L_3 ) ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = NULL ;
V_9 = F_4 ( sizeof( * V_9 ) , V_10 ) ;
if ( V_9 == NULL )
goto V_11;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_12 = F_5 ( 0 , V_10 ) ;
V_9 -> V_13 = F_4 ( V_14 , V_10 ) ;
if ( V_9 -> V_12 == NULL || V_9 -> V_13 == NULL )
goto V_11;
V_9 -> V_7 = V_8 ;
return V_9 ;
V_11:
if ( V_9 ) {
F_6 ( V_9 -> V_12 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
return NULL ;
}
static void F_8 ( struct V_6 * V_9 )
{
if ( V_9 ) {
F_6 ( V_9 -> V_12 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_15 * F_9 ( struct V_16 * V_17 )
{
struct V_15 * V_18 = NULL ;
V_18 = F_4 ( sizeof( * V_18 ) , V_10 ) ;
if ( V_18 == NULL )
goto V_11;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_12 = F_5 ( 0 , V_10 ) ;
V_18 -> V_13 = F_4 ( V_19 , V_10 ) ;
if ( V_18 -> V_12 == NULL || V_18 -> V_13 == NULL )
goto V_11;
V_18 -> V_16 = V_17 ;
return V_18 ;
V_11:
if ( V_18 ) {
F_6 ( V_18 -> V_12 ) ;
F_7 ( V_18 -> V_13 ) ;
F_7 ( V_18 ) ;
}
return NULL ;
}
static void F_10 ( struct V_15 * V_18 )
{
if ( V_18 ) {
F_6 ( V_18 -> V_12 ) ;
F_7 ( V_18 -> V_13 ) ;
F_7 ( V_18 ) ;
}
}
static struct V_6 * F_11 ( struct V_7 * V_8 , int * V_20 )
{
struct V_6 * V_9 ;
if ( F_12 ( & V_8 -> V_21 ) ) {
* V_20 = 1 ;
return NULL ;
}
V_9 = F_13 ( V_8 -> V_21 . V_22 , struct V_6 , V_23 ) ;
F_14 ( & V_9 -> V_23 ) ;
* V_20 = F_12 ( & V_8 -> V_21 ) ? 1 : 0 ;
return V_9 ;
}
static void F_15 ( struct V_7 * V_8 , struct V_6 * V_9 )
{
F_16 ( & V_9 -> V_23 , & V_8 -> V_21 ) ;
}
static struct V_15 * F_17 ( struct V_16 * V_17 )
{
struct V_15 * V_18 ;
if ( F_12 ( & V_17 -> V_21 ) ) {
V_18 = F_9 ( V_17 ) ;
if ( V_18 == NULL )
return NULL ;
F_18 ( & V_18 -> V_23 , & V_17 -> V_21 ) ;
}
V_18 = F_13 ( V_17 -> V_21 . V_22 , struct V_15 , V_23 ) ;
F_14 ( & V_18 -> V_23 ) ;
F_16 ( & V_18 -> V_23 , & V_17 -> V_24 ) ;
return V_18 ;
}
static void F_19 ( struct V_16 * V_17 , struct V_15 * V_18 )
{
F_14 ( & V_18 -> V_23 ) ;
F_18 ( & V_18 -> V_23 , & V_17 -> V_21 ) ;
}
static int F_20 ( struct V_25 * V_26 )
{
int V_27 = 0 , V_4 ;
struct V_7 * V_8 = & V_26 -> V_8 ;
struct V_16 * V_17 = & V_26 -> V_17 ;
struct V_6 * V_9 ;
struct V_15 * V_18 ;
F_21 ( & V_8 -> V_21 ) ;
F_21 ( & V_8 -> V_28 ) ;
F_21 ( & V_8 -> V_29 ) ;
#if F_22 ( V_30 ) || F_22 ( V_31 )
F_21 ( & V_8 -> V_32 ) ;
#endif
F_21 ( & V_17 -> V_21 ) ;
F_21 ( & V_17 -> V_24 ) ;
F_23 ( & V_8 -> V_33 ) ;
F_23 ( & V_17 -> V_33 ) ;
for ( V_4 = 0 ; V_4 < V_34 ; V_4 ++ ) {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
V_27 = - V_35 ;
goto V_36;
}
F_18 ( & V_9 -> V_23 , & V_8 -> V_21 ) ;
}
V_18 = F_9 ( V_17 ) ;
if ( V_18 == NULL ) {
V_27 = - V_35 ;
goto V_36;
}
F_18 ( & V_18 -> V_23 , & V_17 -> V_21 ) ;
return V_27 ;
V_36:
F_24 ( V_26 ) ;
return V_27 ;
}
static void F_24 ( struct V_25 * V_26 )
{
struct V_7 * V_8 = & V_26 -> V_8 ;
struct V_16 * V_17 = & V_26 -> V_17 ;
struct V_6 * V_9 , * V_37 ;
struct V_15 * V_18 , * V_38 ;
F_25 (t, t_next, &tx->sdu_list, list) {
F_14 ( & V_9 -> V_23 ) ;
F_8 ( V_9 ) ;
}
F_25 (t, t_next, &tx->hci_list, list) {
F_14 ( & V_9 -> V_23 ) ;
F_8 ( V_9 ) ;
}
F_25 (t, t_next, &tx->free_list, list) {
F_14 ( & V_9 -> V_23 ) ;
F_8 ( V_9 ) ;
}
F_25 (r, r_next, &rx->free_list, list) {
F_14 ( & V_18 -> V_23 ) ;
F_10 ( V_18 ) ;
}
F_25 (r, r_next, &rx->used_list, list) {
F_14 ( & V_18 -> V_23 ) ;
F_10 ( V_18 ) ;
}
}
static void F_26 ( struct V_12 * V_12 )
{
struct V_6 * V_9 = V_12 -> V_39 ;
struct V_7 * V_8 = V_9 -> V_7 ;
T_1 * V_40 = V_9 -> V_13 ;
T_2 V_41 ;
unsigned long V_42 ;
if ( V_12 -> V_43 == - V_44 )
return;
F_27 ( & V_8 -> V_33 , V_42 ) ;
if ( V_9 -> V_45 )
V_9 -> V_45 ( V_9 -> V_46 ) ;
F_14 ( & V_9 -> V_23 ) ;
V_41 = ( V_40 [ 0 ] << 8 ) | V_40 [ 1 ] ;
if ( V_41 == V_47 )
F_15 ( V_8 , V_9 ) ;
else
F_8 ( V_9 ) ;
F_28 ( & V_8 -> V_33 , V_42 ) ;
}
static int F_29 ( void * V_48 , void * V_2 , int V_3 ,
void (* F_30)( void * V_2 ) , void * V_46 )
{
struct V_25 * V_26 = V_48 ;
struct V_49 * V_50 = V_26 -> V_50 ;
struct V_7 * V_8 = & V_26 -> V_8 ;
struct V_6 * V_9 ;
int V_51 = V_26 -> V_51 ;
int V_20 = 0 , V_27 ;
T_1 * V_40 = V_2 ;
T_2 V_41 ;
unsigned long V_42 ;
if ( ! V_26 -> V_50 ) {
F_2 ( V_52 L_4 , V_53 ) ;
return - V_54 ;
}
F_31 ( V_3 > V_14 - V_51 - 1 ) ;
F_27 ( & V_8 -> V_33 , V_42 ) ;
V_41 = ( V_40 [ 0 ] << 8 ) | V_40 [ 1 ] ;
if ( V_41 == V_47 ) {
V_9 = F_11 ( V_8 , & V_20 ) ;
if ( V_9 == NULL ) {
F_28 ( & V_8 -> V_33 , V_42 ) ;
return - V_55 ;
}
F_16 ( & V_9 -> V_23 , & V_8 -> V_28 ) ;
} else {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
F_28 ( & V_8 -> V_33 , V_42 ) ;
return - V_35 ;
}
F_16 ( & V_9 -> V_23 , & V_8 -> V_29 ) ;
}
memcpy ( V_9 -> V_13 + V_51 , V_2 , V_3 ) ;
V_9 -> V_45 = F_30 ;
V_9 -> V_46 = V_46 ;
if ( ( V_3 % 512 ) == 0 )
V_3 ++ ;
F_32 ( V_9 -> V_12 ,
V_50 ,
F_33 ( V_50 , 1 ) ,
V_9 -> V_13 ,
V_3 + V_51 ,
F_26 ,
V_9 ) ;
#ifdef F_34
F_1 ( L_5 , V_9 -> V_13 , V_3 + V_51 ) ;
#endif
#ifdef V_30
if ( V_50 -> V_56 & V_57 ) {
F_16 ( & V_9 -> V_58 , & V_8 -> V_32 ) ;
F_35 ( & V_26 -> V_59 ) ;
goto V_11;
}
#endif
#ifdef V_31
if ( V_26 -> V_60 ) {
F_16 ( & V_9 -> V_58 , & V_8 -> V_32 ) ;
goto V_11;
} else if ( V_41 == V_61 ) {
struct V_16 * V_17 ;
struct V_15 * V_18 ;
V_17 = & V_26 -> V_17 ;
F_36 (r, &rx->used_list, list)
F_37 ( V_18 -> V_12 ) ;
V_26 -> V_60 = 1 ;
F_38 ( & V_62 ) ;
F_16 ( & V_26 -> V_23 , & V_63 ) ;
F_39 ( & V_62 ) ;
F_40 ( & V_64 ) ;
}
#endif
V_27 = F_41 ( V_9 -> V_12 , V_10 ) ;
if ( V_27 )
goto V_65;
#ifdef V_30
F_42 ( V_50 ) ;
#endif
#if F_22 ( V_30 ) || F_22 ( V_31 )
V_11:
#endif
F_28 ( & V_8 -> V_33 , V_42 ) ;
if ( V_20 )
return - V_55 ;
return 0 ;
V_65:
V_9 -> V_45 = NULL ;
F_26 ( V_9 -> V_12 ) ;
F_28 ( & V_8 -> V_33 , V_42 ) ;
return V_27 ;
}
static void F_43 ( struct V_12 * V_12 )
{
struct V_15 * V_18 = V_12 -> V_39 ;
struct V_16 * V_17 = V_18 -> V_16 ;
struct V_25 * V_26 = F_44 ( V_18 -> V_16 , struct V_25 , V_17 ) ;
struct V_7 * V_8 = & V_26 -> V_8 ;
struct V_6 * V_9 ;
T_2 V_41 ;
unsigned long V_42 ;
#ifdef V_30
struct V_49 * V_66 = V_12 -> V_66 ;
#endif
if ( V_12 -> V_43 == - V_44 )
return;
F_27 ( & V_8 -> V_33 , V_42 ) ;
if ( ! V_12 -> V_43 ) {
V_41 = ( V_18 -> V_13 [ 0 ] << 8 ) | ( V_18 -> V_13 [ 1 ] ) ;
#ifdef F_34
F_1 ( L_6 , V_18 -> V_13 , V_12 -> V_67 ) ;
#endif
if ( V_41 == V_68 ) {
if ( V_18 -> V_13 [ 4 ] == 0 ) {
#ifdef F_34
F_2 ( V_5 L_7 ) ;
#endif
F_36 (t, &tx->sdu_list, list)
F_37 ( V_9 -> V_12 ) ;
} else if ( V_18 -> V_13 [ 4 ] == 1 ) {
#ifdef F_34
F_2 ( V_5 L_8 ) ;
#endif
F_36 (t, &tx->sdu_list, list) {
F_41 ( V_9 -> V_12 , V_10 ) ;
}
if ( F_12 ( & V_8 -> V_21 ) )
V_12 -> V_67 = 0 ;
}
}
}
if ( ! V_12 -> V_43 && V_18 -> V_45 )
V_18 -> V_45 ( V_18 -> V_46 , V_18 -> V_13 , V_12 -> V_67 ) ;
F_38 ( & V_17 -> V_33 ) ;
F_19 ( V_17 , V_18 ) ;
F_39 ( & V_17 -> V_33 ) ;
F_28 ( & V_8 -> V_33 , V_42 ) ;
#ifdef V_30
F_42 ( V_66 ) ;
#endif
}
static int F_45 ( void * V_48 ,
void (* F_30)( void * V_46 , void * V_2 , int V_3 ) ,
void * V_46 )
{
struct V_25 * V_26 = V_48 ;
struct V_49 * V_50 = V_26 -> V_50 ;
struct V_16 * V_17 = & V_26 -> V_17 ;
struct V_15 * V_18 ;
unsigned long V_42 ;
if ( ! V_26 -> V_50 ) {
F_2 ( V_52 L_4 , V_53 ) ;
return - V_54 ;
}
F_27 ( & V_17 -> V_33 , V_42 ) ;
V_18 = F_17 ( V_17 ) ;
F_28 ( & V_17 -> V_33 , V_42 ) ;
if ( V_18 == NULL )
return - V_35 ;
V_18 -> V_45 = F_30 ;
V_18 -> V_46 = V_46 ;
F_32 ( V_18 -> V_12 ,
V_50 ,
F_46 ( V_50 , 0x82 ) ,
V_18 -> V_13 ,
V_19 ,
F_43 ,
V_18 ) ;
return F_41 ( V_18 -> V_12 , V_10 ) ;
}
static void F_47 ( struct V_69 * V_70 )
{
struct V_25 * V_26 = F_44 ( V_70 , struct V_25 , V_59 ) ;
struct V_7 * V_8 = & V_26 -> V_8 ;
int V_27 ;
unsigned long V_42 ;
V_27 = F_48 ( V_26 -> V_71 ) ;
if ( ! V_27 )
F_49 ( V_26 -> V_71 ) ;
F_27 ( & V_8 -> V_33 , V_42 ) ;
if ( ! ( V_26 -> V_50 -> V_56 & V_57 )
&& ( ! F_12 ( & V_8 -> V_29 ) || ! F_12 ( & V_8 -> V_28 ) ) ) {
struct V_6 * V_9 , * V_72 ;
F_25 (t, temp, &tx->pending_list, p_list) {
F_14 ( & V_9 -> V_58 ) ;
V_27 = F_41 ( V_9 -> V_12 , V_10 ) ;
if ( V_27 ) {
V_9 -> V_45 = NULL ;
F_26 ( V_9 -> V_12 ) ;
}
}
}
F_28 ( & V_8 -> V_33 , V_42 ) ;
}
static int F_50 ( struct V_73 * V_71 ,
const struct V_74 * V_75 )
{
int V_27 = 0 ;
T_1 V_76 ;
struct V_77 * V_77 = NULL ;
struct V_25 * V_26 = NULL ;
T_2 V_78 , V_79 , V_80 ;
struct V_49 * V_50 = F_51 ( V_71 ) ;
F_52 ( V_50 ) ;
V_76 = V_50 -> V_81 -> V_82 . V_76 ;
V_78 = F_53 ( V_50 -> V_83 . V_78 ) ;
V_79 = F_53 ( V_50 -> V_83 . V_79 ) ;
V_80 = F_53 ( V_50 -> V_83 . V_80 ) ;
F_2 ( V_84 L_9 ,
V_78 , V_79 ) ;
F_2 ( V_84 L_10 , V_85 ) ;
if ( V_79 == V_86 ) {
V_27 = F_54 ( V_50 ) ;
goto V_11;
}
if ( V_76 == V_87 ||
V_79 & V_88 ) {
V_27 = F_55 ( V_50 , V_80 ) ;
goto V_11;
}
V_77 = F_4 ( sizeof( * V_77 ) , V_89 ) ;
if ( V_77 == NULL ) {
V_27 = - V_35 ;
goto V_11;
}
V_26 = F_4 ( sizeof( * V_26 ) , V_89 ) ;
if ( V_26 == NULL ) {
V_27 = - V_35 ;
goto V_11;
}
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
if ( V_79 == 0x7205 || V_79 == 0x7206 )
V_26 -> V_51 = V_90 ;
else
V_26 -> V_51 = 0 ;
V_77 -> V_48 = ( void * ) V_26 ;
V_77 -> V_91 = F_29 ;
V_77 -> V_92 = F_45 ;
V_27 = F_20 ( V_26 ) ;
if ( V_27 < 0 )
goto V_11;
V_26 -> V_50 = V_50 ;
#ifdef V_30
V_26 -> V_71 = V_71 ;
V_71 -> V_93 = 1 ;
F_56 ( & V_71 -> V_66 , 1 ) ;
F_57 ( & V_50 -> V_66 , 10 * 1000 ) ;
F_58 ( & V_26 -> V_59 , F_47 ) ;
#endif
V_27 = F_59 ( V_77 , & V_71 -> V_66 ) ;
V_11:
if ( V_27 ) {
F_7 ( V_77 ) ;
F_7 ( V_26 ) ;
}
F_60 ( V_71 , V_77 ) ;
return V_27 ;
}
static void F_61 ( struct V_73 * V_71 )
{
T_1 V_76 ;
struct V_77 * V_77 ;
struct V_25 * V_26 ;
T_2 V_79 ;
struct V_49 * V_50 = F_51 ( V_71 ) ;
V_76 = V_50 -> V_81 -> V_82 . V_76 ;
V_77 = F_62 ( V_71 ) ;
V_79 = F_53 ( V_50 -> V_83 . V_79 ) ;
if ( V_79 != V_86 &&
V_76 != V_87 &&
( V_79 & V_88 ) == 0 ) {
V_26 = V_77 -> V_48 ;
V_26 -> V_50 = NULL ;
F_63 ( V_77 ) ;
F_24 ( V_26 ) ;
F_7 ( V_26 ) ;
F_7 ( V_77 ) ;
}
F_64 ( V_50 ) ;
}
static int F_65 ( struct V_73 * V_71 , T_3 V_94 )
{
struct V_77 * V_77 ;
struct V_25 * V_26 ;
struct V_16 * V_17 ;
struct V_15 * V_18 ;
V_77 = F_62 ( V_71 ) ;
V_26 = V_77 -> V_48 ;
V_17 = & V_26 -> V_17 ;
F_36 (r, &rx->used_list, list)
F_37 ( V_18 -> V_12 ) ;
return 0 ;
}
static int F_66 ( struct V_73 * V_71 )
{
struct V_77 * V_77 ;
struct V_25 * V_26 ;
struct V_16 * V_17 ;
struct V_15 * V_18 ;
V_77 = F_62 ( V_71 ) ;
V_26 = V_77 -> V_48 ;
V_17 = & V_26 -> V_17 ;
F_36 (r, &rx->used_list, list)
F_41 ( V_18 -> V_12 , V_10 ) ;
return 0 ;
}
static int F_67 ( void * V_95 )
{
struct V_25 * V_26 ;
struct V_7 * V_8 ;
struct V_16 * V_17 ;
struct V_6 * V_9 , * V_72 ;
struct V_15 * V_18 ;
unsigned long V_42 , V_96 , V_97 ;
int V_27 ;
F_68 ( L_11 ) ;
while ( ! V_98 ) {
F_27 ( & V_62 , V_96 ) ;
while ( ! F_12 ( & V_63 ) ) {
V_26 = F_13 ( V_63 . V_22 , struct V_25 , V_23 ) ;
V_8 = & V_26 -> V_8 ;
V_17 = & V_26 -> V_17 ;
F_14 ( & V_26 -> V_23 ) ;
F_28 ( & V_62 , V_96 ) ;
V_97 = V_99 + V_100 ;
while ( V_99 < V_97 )
F_69 ( V_100 ) ;
F_36 (r, &rx->used_list, list)
F_41 ( V_18 -> V_12 , V_10 ) ;
F_27 ( & V_8 -> V_33 , V_42 ) ;
F_25 (t, temp, &tx->pending_list,
p_list) {
F_14 ( & V_9 -> V_58 ) ;
V_27 = F_41 ( V_9 -> V_12 , V_10 ) ;
if ( V_27 ) {
V_9 -> V_45 = NULL ;
F_26 ( V_9 -> V_12 ) ;
}
}
V_26 -> V_60 = 0 ;
F_28 ( & V_8 -> V_33 , V_42 ) ;
F_27 ( & V_62 , V_96 ) ;
}
F_28 ( & V_62 , V_96 ) ;
F_70 ( & V_64 ) ;
}
return 0 ;
}
static int T_4 F_71 ( void )
{
#ifdef V_31
F_72 ( F_67 , NULL , V_101 ) ;
#endif
return F_73 ( & V_102 ) ;
}
static void T_5 F_74 ( void )
{
#ifdef V_31
V_98 = 1 ;
F_40 ( & V_64 ) ;
#endif
F_75 ( & V_102 ) ;
}
