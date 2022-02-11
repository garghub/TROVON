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
struct V_6 * V_9 = F_4 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_11 = F_5 ( 0 , V_10 ) ;
V_9 -> V_12 = F_6 ( V_13 , V_10 ) ;
if ( ! V_9 -> V_11 || ! V_9 -> V_12 ) {
F_7 ( V_9 -> V_11 ) ;
F_8 ( V_9 -> V_12 ) ;
F_8 ( V_9 ) ;
return NULL ;
}
V_9 -> V_7 = V_8 ;
return V_9 ;
}
static void F_9 ( struct V_6 * V_9 )
{
if ( V_9 ) {
F_7 ( V_9 -> V_11 ) ;
F_8 ( V_9 -> V_12 ) ;
F_8 ( V_9 ) ;
}
}
static struct V_14 * F_10 ( struct V_15 * V_16 )
{
struct V_14 * V_17 = F_4 ( sizeof( * V_17 ) , V_10 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_11 = F_5 ( 0 , V_10 ) ;
V_17 -> V_12 = F_6 ( V_18 , V_10 ) ;
if ( ! V_17 -> V_11 || ! V_17 -> V_12 ) {
F_7 ( V_17 -> V_11 ) ;
F_8 ( V_17 -> V_12 ) ;
F_8 ( V_17 ) ;
return NULL ;
}
V_17 -> V_15 = V_16 ;
return V_17 ;
}
static void F_11 ( struct V_14 * V_17 )
{
if ( V_17 ) {
F_7 ( V_17 -> V_11 ) ;
F_8 ( V_17 -> V_12 ) ;
F_8 ( V_17 ) ;
}
}
static struct V_6 * F_12 ( struct V_7 * V_8 , int * V_19 )
{
struct V_6 * V_9 ;
if ( F_13 ( & V_8 -> V_20 ) ) {
* V_19 = 1 ;
return NULL ;
}
V_9 = F_14 ( V_8 -> V_20 . V_21 , struct V_6 , V_22 ) ;
F_15 ( & V_9 -> V_22 ) ;
* V_19 = F_13 ( & V_8 -> V_20 ) ? 1 : 0 ;
return V_9 ;
}
static void F_16 ( struct V_7 * V_8 , struct V_6 * V_9 )
{
F_17 ( & V_9 -> V_22 , & V_8 -> V_20 ) ;
}
static struct V_14 * F_18 ( struct V_15 * V_16 )
{
struct V_14 * V_17 ;
if ( F_13 ( & V_16 -> V_20 ) ) {
V_17 = F_10 ( V_16 ) ;
if ( V_17 == NULL )
return NULL ;
F_19 ( & V_17 -> V_22 , & V_16 -> V_20 ) ;
}
V_17 = F_14 ( V_16 -> V_20 . V_21 , struct V_14 , V_22 ) ;
F_20 ( & V_17 -> V_22 , & V_16 -> V_23 ) ;
return V_17 ;
}
static void F_21 ( struct V_15 * V_16 , struct V_14 * V_17 )
{
F_22 ( & V_17 -> V_22 , & V_16 -> V_20 ) ;
}
static int F_23 ( struct V_24 * V_25 )
{
int V_26 = 0 , V_4 ;
struct V_7 * V_8 = & V_25 -> V_8 ;
struct V_15 * V_16 = & V_25 -> V_16 ;
struct V_6 * V_9 ;
struct V_14 * V_17 ;
F_24 ( & V_8 -> V_20 ) ;
F_24 ( & V_8 -> V_27 ) ;
F_24 ( & V_8 -> V_28 ) ;
#if F_25 ( V_29 ) || F_25 ( V_30 )
F_24 ( & V_8 -> V_31 ) ;
#endif
F_24 ( & V_16 -> V_20 ) ;
F_24 ( & V_16 -> V_23 ) ;
F_26 ( & V_8 -> V_32 ) ;
F_26 ( & V_16 -> V_32 ) ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ ) {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
V_26 = - V_34 ;
goto V_35;
}
F_19 ( & V_9 -> V_22 , & V_8 -> V_20 ) ;
}
V_17 = F_10 ( V_16 ) ;
if ( V_17 == NULL ) {
V_26 = - V_34 ;
goto V_35;
}
F_19 ( & V_17 -> V_22 , & V_16 -> V_20 ) ;
return V_26 ;
V_35:
F_27 ( V_25 ) ;
return V_26 ;
}
static void F_27 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = & V_25 -> V_8 ;
struct V_15 * V_16 = & V_25 -> V_16 ;
struct V_6 * V_9 , * V_36 ;
struct V_14 * V_17 , * V_37 ;
F_28 (t, t_next, &tx->sdu_list, list) {
F_15 ( & V_9 -> V_22 ) ;
F_9 ( V_9 ) ;
}
F_28 (t, t_next, &tx->hci_list, list) {
F_15 ( & V_9 -> V_22 ) ;
F_9 ( V_9 ) ;
}
F_28 (t, t_next, &tx->free_list, list) {
F_15 ( & V_9 -> V_22 ) ;
F_9 ( V_9 ) ;
}
F_28 (r, r_next, &rx->free_list, list) {
F_15 ( & V_17 -> V_22 ) ;
F_11 ( V_17 ) ;
}
F_28 (r, r_next, &rx->used_list, list) {
F_15 ( & V_17 -> V_22 ) ;
F_11 ( V_17 ) ;
}
}
static void F_29 ( struct V_11 * V_11 )
{
struct V_6 * V_9 = V_11 -> V_38 ;
struct V_7 * V_8 = V_9 -> V_7 ;
T_1 * V_39 = V_9 -> V_12 ;
T_2 V_40 ;
if ( V_11 -> V_41 == - V_42 )
return;
if ( V_9 -> V_43 )
V_9 -> V_43 ( V_9 -> V_44 ) ;
F_15 ( & V_9 -> V_22 ) ;
V_40 = ( V_39 [ 0 ] << 8 ) | V_39 [ 1 ] ;
if ( V_40 == V_45 )
F_16 ( V_8 , V_9 ) ;
else
F_9 ( V_9 ) ;
}
static void F_30 ( struct V_11 * V_11 )
{
struct V_6 * V_9 = V_11 -> V_38 ;
struct V_7 * V_8 = V_9 -> V_7 ;
unsigned long V_46 ;
F_31 ( & V_8 -> V_32 , V_46 ) ;
F_29 ( V_11 ) ;
F_32 ( & V_8 -> V_32 , V_46 ) ;
}
static int F_33 ( void * V_47 , void * V_2 , int V_3 ,
void (* F_34)( void * V_2 ) , void * V_44 )
{
struct V_24 * V_25 = V_47 ;
struct V_48 * V_49 = V_25 -> V_49 ;
struct V_7 * V_8 = & V_25 -> V_8 ;
struct V_6 * V_9 ;
int V_50 = V_25 -> V_50 ;
int V_19 = 0 , V_26 ;
T_1 * V_39 = V_2 ;
T_2 V_40 ;
unsigned long V_46 ;
if ( ! V_25 -> V_49 ) {
F_2 ( V_51 L_4 , V_52 ) ;
return - V_53 ;
}
F_35 ( V_3 > V_13 - V_50 - 1 ) ;
F_31 ( & V_8 -> V_32 , V_46 ) ;
V_40 = ( V_39 [ 0 ] << 8 ) | V_39 [ 1 ] ;
if ( V_40 == V_45 ) {
V_9 = F_12 ( V_8 , & V_19 ) ;
if ( V_9 == NULL ) {
F_32 ( & V_8 -> V_32 , V_46 ) ;
return - V_54 ;
}
F_17 ( & V_9 -> V_22 , & V_8 -> V_27 ) ;
} else {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
F_32 ( & V_8 -> V_32 , V_46 ) ;
return - V_34 ;
}
F_17 ( & V_9 -> V_22 , & V_8 -> V_28 ) ;
}
memcpy ( V_9 -> V_12 + V_50 , V_2 , V_3 ) ;
V_9 -> V_43 = F_34 ;
V_9 -> V_44 = V_44 ;
if ( ( V_3 % 512 ) == 0 )
V_3 ++ ;
F_36 ( V_9 -> V_11 ,
V_49 ,
F_37 ( V_49 , 1 ) ,
V_9 -> V_12 ,
V_3 + V_50 ,
F_30 ,
V_9 ) ;
#ifdef F_38
F_1 ( L_5 , V_9 -> V_12 , V_3 + V_50 ) ;
#endif
#ifdef V_29
if ( V_49 -> V_55 & V_56 ) {
F_17 ( & V_9 -> V_57 , & V_8 -> V_31 ) ;
F_39 ( & V_25 -> V_58 ) ;
goto V_59;
}
#endif
#ifdef V_30
if ( V_25 -> V_60 ) {
F_17 ( & V_9 -> V_57 , & V_8 -> V_31 ) ;
goto V_59;
} else if ( V_40 == V_61 ) {
struct V_15 * V_16 ;
struct V_14 * V_17 ;
V_16 = & V_25 -> V_16 ;
F_40 (r, &rx->used_list, list)
F_41 ( V_17 -> V_11 ) ;
V_25 -> V_60 = 1 ;
F_42 ( & V_62 ) ;
F_17 ( & V_25 -> V_22 , & V_63 ) ;
F_43 ( & V_62 ) ;
F_44 ( & V_64 ) ;
}
#endif
V_26 = F_45 ( V_9 -> V_11 , V_10 ) ;
if ( V_26 )
goto V_65;
#ifdef V_29
F_46 ( V_49 ) ;
#endif
#if F_25 ( V_29 ) || F_25 ( V_30 )
V_59:
#endif
F_32 ( & V_8 -> V_32 , V_46 ) ;
if ( V_19 )
return - V_54 ;
return 0 ;
V_65:
V_9 -> V_43 = NULL ;
F_29 ( V_9 -> V_11 ) ;
F_32 ( & V_8 -> V_32 , V_46 ) ;
return V_26 ;
}
static void F_47 ( struct V_11 * V_11 )
{
struct V_14 * V_17 = V_11 -> V_38 ;
struct V_15 * V_16 = V_17 -> V_15 ;
struct V_24 * V_25 = F_48 ( V_17 -> V_15 , struct V_24 , V_16 ) ;
struct V_7 * V_8 = & V_25 -> V_8 ;
struct V_6 * V_9 ;
T_2 V_40 ;
unsigned long V_46 ;
#ifdef V_29
struct V_48 * V_66 = V_11 -> V_66 ;
#endif
if ( V_11 -> V_41 == - V_42 )
return;
F_31 ( & V_8 -> V_32 , V_46 ) ;
if ( ! V_11 -> V_41 ) {
V_40 = ( V_17 -> V_12 [ 0 ] << 8 ) | ( V_17 -> V_12 [ 1 ] ) ;
#ifdef F_38
F_1 ( L_6 , V_17 -> V_12 , V_11 -> V_67 ) ;
#endif
if ( V_40 == V_68 ) {
if ( V_17 -> V_12 [ 4 ] == 0 ) {
#ifdef F_38
F_2 ( V_5 L_7 ) ;
#endif
F_40 (t, &tx->sdu_list, list)
F_41 ( V_9 -> V_11 ) ;
} else if ( V_17 -> V_12 [ 4 ] == 1 ) {
#ifdef F_38
F_2 ( V_5 L_8 ) ;
#endif
F_40 (t, &tx->sdu_list, list) {
F_45 ( V_9 -> V_11 , V_10 ) ;
}
if ( F_13 ( & V_8 -> V_20 ) )
V_11 -> V_67 = 0 ;
}
}
}
if ( ! V_11 -> V_41 && V_17 -> V_43 )
V_17 -> V_43 ( V_17 -> V_44 , V_17 -> V_12 , V_11 -> V_67 ) ;
F_42 ( & V_16 -> V_32 ) ;
F_21 ( V_16 , V_17 ) ;
F_43 ( & V_16 -> V_32 ) ;
F_32 ( & V_8 -> V_32 , V_46 ) ;
#ifdef V_29
F_46 ( V_66 ) ;
#endif
}
static int F_49 ( void * V_47 ,
void (* F_34)( void * V_44 , void * V_2 , int V_3 ) ,
void * V_44 )
{
struct V_24 * V_25 = V_47 ;
struct V_48 * V_49 = V_25 -> V_49 ;
struct V_15 * V_16 = & V_25 -> V_16 ;
struct V_14 * V_17 ;
unsigned long V_46 ;
if ( ! V_25 -> V_49 ) {
F_2 ( V_51 L_4 , V_52 ) ;
return - V_53 ;
}
F_31 ( & V_16 -> V_32 , V_46 ) ;
V_17 = F_18 ( V_16 ) ;
F_32 ( & V_16 -> V_32 , V_46 ) ;
if ( V_17 == NULL )
return - V_34 ;
V_17 -> V_43 = F_34 ;
V_17 -> V_44 = V_44 ;
F_36 ( V_17 -> V_11 ,
V_49 ,
F_50 ( V_49 , 0x82 ) ,
V_17 -> V_12 ,
V_18 ,
F_47 ,
V_17 ) ;
return F_45 ( V_17 -> V_11 , V_10 ) ;
}
static void F_51 ( struct V_69 * V_70 )
{
struct V_24 * V_25 = F_48 ( V_70 , struct V_24 , V_58 ) ;
struct V_7 * V_8 = & V_25 -> V_8 ;
int V_26 ;
unsigned long V_46 ;
V_26 = F_52 ( V_25 -> V_71 ) ;
if ( ! V_26 )
F_53 ( V_25 -> V_71 ) ;
F_31 ( & V_8 -> V_32 , V_46 ) ;
if ( ! ( V_25 -> V_49 -> V_55 & V_56 )
&& ( ! F_13 ( & V_8 -> V_28 ) || ! F_13 ( & V_8 -> V_27 ) ) ) {
struct V_6 * V_9 , * V_72 ;
F_28 (t, temp, &tx->pending_list, p_list) {
F_15 ( & V_9 -> V_57 ) ;
V_26 = F_45 ( V_9 -> V_11 , V_10 ) ;
if ( V_26 ) {
V_9 -> V_43 = NULL ;
F_29 ( V_9 -> V_11 ) ;
}
}
}
F_32 ( & V_8 -> V_32 , V_46 ) ;
}
static int F_54 ( struct V_73 * V_71 ,
const struct V_74 * V_75 )
{
int V_26 = 0 ;
T_1 V_76 ;
struct V_77 * V_77 = NULL ;
struct V_24 * V_25 = NULL ;
T_2 V_78 , V_79 , V_80 ;
struct V_48 * V_49 = F_55 ( V_71 ) ;
F_56 ( V_49 ) ;
V_76 = V_49 -> V_81 -> V_82 . V_76 ;
V_78 = F_57 ( V_49 -> V_83 . V_78 ) ;
V_79 = F_57 ( V_49 -> V_83 . V_79 ) ;
V_80 = F_57 ( V_49 -> V_83 . V_80 ) ;
F_2 ( V_84 L_9 ,
V_78 , V_79 ) ;
F_2 ( V_84 L_10 , V_85 ) ;
if ( V_79 == V_86 ) {
V_26 = F_58 ( V_49 ) ;
goto V_59;
}
if ( V_76 == V_87 ||
V_79 & V_88 ) {
V_26 = F_59 ( V_49 , V_80 ) ;
goto V_59;
}
V_77 = F_4 ( sizeof( * V_77 ) , V_89 ) ;
if ( V_77 == NULL ) {
V_26 = - V_34 ;
goto V_59;
}
V_25 = F_4 ( sizeof( * V_25 ) , V_89 ) ;
if ( V_25 == NULL ) {
V_26 = - V_34 ;
goto V_59;
}
if ( V_79 == 0x7205 || V_79 == 0x7206 )
V_25 -> V_50 = V_90 ;
else
V_25 -> V_50 = 0 ;
V_77 -> V_47 = ( void * ) V_25 ;
V_77 -> V_91 = F_33 ;
V_77 -> V_92 = F_49 ;
V_26 = F_23 ( V_25 ) ;
if ( V_26 < 0 )
goto V_59;
V_25 -> V_49 = V_49 ;
#ifdef V_29
V_25 -> V_71 = V_71 ;
V_71 -> V_93 = 1 ;
F_60 ( & V_71 -> V_66 , 1 ) ;
F_61 ( & V_49 -> V_66 , 10 * 1000 ) ;
F_62 ( & V_25 -> V_58 , F_51 ) ;
#endif
V_26 = F_63 ( V_77 , & V_71 -> V_66 ) ;
V_59:
if ( V_26 ) {
F_8 ( V_77 ) ;
F_8 ( V_25 ) ;
}
F_64 ( V_71 , V_77 ) ;
return V_26 ;
}
static void F_65 ( struct V_73 * V_71 )
{
T_1 V_76 ;
struct V_77 * V_77 ;
struct V_24 * V_25 ;
T_2 V_79 ;
struct V_48 * V_49 = F_55 ( V_71 ) ;
V_76 = V_49 -> V_81 -> V_82 . V_76 ;
V_77 = F_66 ( V_71 ) ;
V_79 = F_57 ( V_49 -> V_83 . V_79 ) ;
if ( V_79 != V_86 &&
V_76 != V_87 &&
( V_79 & V_88 ) == 0 ) {
V_25 = V_77 -> V_47 ;
V_25 -> V_49 = NULL ;
F_67 ( V_77 ) ;
F_27 ( V_25 ) ;
F_8 ( V_25 ) ;
F_8 ( V_77 ) ;
}
F_68 ( V_49 ) ;
}
static int F_69 ( struct V_73 * V_71 , T_3 V_94 )
{
struct V_77 * V_77 ;
struct V_24 * V_25 ;
struct V_15 * V_16 ;
struct V_14 * V_17 ;
V_77 = F_66 ( V_71 ) ;
V_25 = V_77 -> V_47 ;
V_16 = & V_25 -> V_16 ;
F_40 (r, &rx->used_list, list)
F_41 ( V_17 -> V_11 ) ;
return 0 ;
}
static int F_70 ( struct V_73 * V_71 )
{
struct V_77 * V_77 ;
struct V_24 * V_25 ;
struct V_15 * V_16 ;
struct V_14 * V_17 ;
V_77 = F_66 ( V_71 ) ;
V_25 = V_77 -> V_47 ;
V_16 = & V_25 -> V_16 ;
F_40 (r, &rx->used_list, list)
F_45 ( V_17 -> V_11 , V_10 ) ;
return 0 ;
}
static int F_71 ( void * V_95 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 ;
struct V_15 * V_16 ;
struct V_6 * V_9 , * V_72 ;
struct V_14 * V_17 ;
unsigned long V_46 , V_96 , V_97 ;
int V_26 ;
F_72 ( L_11 ) ;
while ( ! V_98 ) {
F_31 ( & V_62 , V_96 ) ;
while ( ! F_13 ( & V_63 ) ) {
V_25 = F_14 ( V_63 . V_21 , struct V_24 , V_22 ) ;
V_8 = & V_25 -> V_8 ;
V_16 = & V_25 -> V_16 ;
F_15 ( & V_25 -> V_22 ) ;
F_32 ( & V_62 , V_96 ) ;
V_97 = V_99 + V_100 ;
while ( V_99 < V_97 )
F_73 ( V_100 ) ;
F_40 (r, &rx->used_list, list)
F_45 ( V_17 -> V_11 , V_10 ) ;
F_31 ( & V_8 -> V_32 , V_46 ) ;
F_28 (t, temp, &tx->pending_list,
p_list) {
F_15 ( & V_9 -> V_57 ) ;
V_26 = F_45 ( V_9 -> V_11 , V_10 ) ;
if ( V_26 ) {
V_9 -> V_43 = NULL ;
F_29 ( V_9 -> V_11 ) ;
}
}
V_25 -> V_60 = 0 ;
F_32 ( & V_8 -> V_32 , V_46 ) ;
F_31 ( & V_62 , V_96 ) ;
}
F_32 ( & V_62 , V_96 ) ;
F_74 ( & V_64 ) ;
}
return 0 ;
}
static int T_4 F_75 ( void )
{
#ifdef V_30
F_76 ( F_71 , NULL , L_12 ) ;
#endif
return F_77 ( & V_101 ) ;
}
static void T_5 F_78 ( void )
{
#ifdef V_30
V_98 = 1 ;
F_44 ( & V_64 ) ;
#endif
F_79 ( & V_101 ) ;
}
