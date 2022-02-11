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
unsigned long V_27 ;
F_24 ( & V_8 -> V_20 ) ;
F_24 ( & V_8 -> V_28 ) ;
F_24 ( & V_8 -> V_29 ) ;
#if F_25 ( V_30 ) || F_25 ( V_31 )
F_24 ( & V_8 -> V_32 ) ;
#endif
F_24 ( & V_16 -> V_20 ) ;
F_24 ( & V_16 -> V_23 ) ;
F_26 ( & V_8 -> V_33 ) ;
F_26 ( & V_16 -> V_33 ) ;
F_27 ( & V_8 -> V_33 , V_27 ) ;
for ( V_4 = 0 ; V_4 < V_34 ; V_4 ++ ) {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
F_28 ( & V_8 -> V_33 , V_27 ) ;
V_26 = - V_35 ;
goto V_36;
}
F_19 ( & V_9 -> V_22 , & V_8 -> V_20 ) ;
}
F_28 ( & V_8 -> V_33 , V_27 ) ;
V_17 = F_10 ( V_16 ) ;
if ( V_17 == NULL ) {
V_26 = - V_35 ;
goto V_36;
}
F_27 ( & V_16 -> V_33 , V_27 ) ;
F_19 ( & V_17 -> V_22 , & V_16 -> V_20 ) ;
F_28 ( & V_16 -> V_33 , V_27 ) ;
return V_26 ;
V_36:
F_29 ( V_25 ) ;
return V_26 ;
}
static void F_29 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = & V_25 -> V_8 ;
struct V_15 * V_16 = & V_25 -> V_16 ;
struct V_6 * V_9 , * V_37 ;
struct V_14 * V_17 , * V_38 ;
unsigned long V_27 ;
F_27 ( & V_8 -> V_33 , V_27 ) ;
F_30 (t, t_next, &tx->sdu_list, list) {
F_15 ( & V_9 -> V_22 ) ;
F_9 ( V_9 ) ;
}
F_30 (t, t_next, &tx->hci_list, list) {
F_15 ( & V_9 -> V_22 ) ;
F_9 ( V_9 ) ;
}
F_30 (t, t_next, &tx->free_list, list) {
F_15 ( & V_9 -> V_22 ) ;
F_9 ( V_9 ) ;
}
F_28 ( & V_8 -> V_33 , V_27 ) ;
F_27 ( & V_16 -> V_33 , V_27 ) ;
F_30 (r, r_next, &rx->free_list, list) {
F_15 ( & V_17 -> V_22 ) ;
F_11 ( V_17 ) ;
}
F_30 (r, r_next, &rx->used_list, list) {
F_15 ( & V_17 -> V_22 ) ;
F_11 ( V_17 ) ;
}
F_28 ( & V_16 -> V_33 , V_27 ) ;
}
static void F_31 ( struct V_11 * V_11 )
{
struct V_6 * V_9 = V_11 -> V_39 ;
struct V_7 * V_8 = V_9 -> V_7 ;
T_1 * V_40 = V_9 -> V_12 ;
T_2 V_41 ;
if ( V_11 -> V_42 == - V_43 )
return;
if ( V_9 -> V_44 )
V_9 -> V_44 ( V_9 -> V_45 ) ;
F_15 ( & V_9 -> V_22 ) ;
V_41 = ( V_40 [ 0 ] << 8 ) | V_40 [ 1 ] ;
if ( V_41 == V_46 )
F_16 ( V_8 , V_9 ) ;
else
F_9 ( V_9 ) ;
}
static void F_32 ( struct V_11 * V_11 )
{
struct V_6 * V_9 = V_11 -> V_39 ;
struct V_7 * V_8 = V_9 -> V_7 ;
unsigned long V_27 ;
F_27 ( & V_8 -> V_33 , V_27 ) ;
F_31 ( V_11 ) ;
F_28 ( & V_8 -> V_33 , V_27 ) ;
}
static int F_33 ( void * V_47 , void * V_2 , int V_3 ,
void (* F_34)( void * V_2 ) , void * V_45 )
{
struct V_24 * V_25 = V_47 ;
struct V_48 * V_49 = V_25 -> V_49 ;
struct V_7 * V_8 = & V_25 -> V_8 ;
struct V_6 * V_9 ;
int V_50 = V_25 -> V_50 ;
int V_19 = 0 , V_26 ;
T_1 * V_40 = V_2 ;
T_2 V_41 ;
unsigned long V_27 ;
#ifdef V_31
unsigned long V_51 ;
#endif
if ( ! V_25 -> V_49 ) {
F_35 ( & V_49 -> V_52 , L_4 , V_53 ) ;
return - V_54 ;
}
F_36 ( V_3 > V_13 - V_50 - 1 ) ;
F_27 ( & V_8 -> V_33 , V_27 ) ;
V_41 = ( V_40 [ 0 ] << 8 ) | V_40 [ 1 ] ;
if ( V_41 == V_46 ) {
V_9 = F_12 ( V_8 , & V_19 ) ;
if ( V_9 == NULL ) {
F_28 ( & V_8 -> V_33 , V_27 ) ;
return - V_55 ;
}
F_17 ( & V_9 -> V_22 , & V_8 -> V_28 ) ;
} else {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
F_28 ( & V_8 -> V_33 , V_27 ) ;
return - V_35 ;
}
F_17 ( & V_9 -> V_22 , & V_8 -> V_29 ) ;
}
memcpy ( V_9 -> V_12 + V_50 , V_2 , V_3 ) ;
V_9 -> V_44 = F_34 ;
V_9 -> V_45 = V_45 ;
if ( ( V_3 % 512 ) == 0 )
V_3 ++ ;
F_37 ( V_9 -> V_11 ,
V_49 ,
F_38 ( V_49 , 1 ) ,
V_9 -> V_12 ,
V_3 + V_50 ,
F_32 ,
V_9 ) ;
#ifdef F_39
F_1 ( L_5 , V_9 -> V_12 , V_3 + V_50 ) ;
#endif
#ifdef V_30
if ( V_49 -> V_56 & V_57 ) {
F_17 ( & V_9 -> V_58 , & V_8 -> V_32 ) ;
F_40 ( & V_25 -> V_59 ) ;
goto V_60;
}
#endif
#ifdef V_31
if ( V_25 -> V_61 ) {
F_17 ( & V_9 -> V_58 , & V_8 -> V_32 ) ;
goto V_60;
} else if ( V_41 == V_62 ) {
struct V_15 * V_16 ;
struct V_14 * V_17 ;
V_16 = & V_25 -> V_16 ;
F_27 ( & V_16 -> V_33 , V_51 ) ;
F_41 (r, &rx->used_list, list)
F_42 ( V_17 -> V_11 ) ;
F_28 ( & V_16 -> V_33 , V_51 ) ;
V_25 -> V_61 = 1 ;
F_27 ( & V_63 , V_51 ) ;
F_17 ( & V_25 -> V_22 , & V_64 ) ;
F_28 ( & V_63 , V_51 ) ;
F_43 ( & V_65 ) ;
}
#endif
V_26 = F_44 ( V_9 -> V_11 , V_10 ) ;
if ( V_26 )
goto V_66;
#ifdef V_30
F_45 ( V_49 ) ;
#endif
#if F_25 ( V_30 ) || F_25 ( V_31 )
V_60:
#endif
F_28 ( & V_8 -> V_33 , V_27 ) ;
if ( V_19 )
return - V_55 ;
return 0 ;
V_66:
V_9 -> V_44 = NULL ;
F_31 ( V_9 -> V_11 ) ;
F_28 ( & V_8 -> V_33 , V_27 ) ;
return V_26 ;
}
static void F_46 ( struct V_11 * V_11 )
{
struct V_14 * V_17 = V_11 -> V_39 ;
struct V_15 * V_16 = V_17 -> V_15 ;
struct V_24 * V_25 = F_47 ( V_17 -> V_15 , struct V_24 , V_16 ) ;
struct V_7 * V_8 = & V_25 -> V_8 ;
struct V_6 * V_9 ;
T_2 V_41 ;
unsigned long V_27 , V_51 ;
#ifdef V_30
struct V_48 * V_52 = V_11 -> V_52 ;
#endif
if ( V_11 -> V_42 == - V_43 )
return;
F_27 ( & V_8 -> V_33 , V_27 ) ;
if ( ! V_11 -> V_42 ) {
V_41 = ( V_17 -> V_12 [ 0 ] << 8 ) | ( V_17 -> V_12 [ 1 ] ) ;
#ifdef F_39
F_1 ( L_6 , V_17 -> V_12 , V_11 -> V_67 ) ;
#endif
if ( V_41 == V_68 ) {
if ( V_17 -> V_12 [ 4 ] == 0 ) {
#ifdef F_39
F_2 ( V_5 L_7 ) ;
#endif
F_41 (t, &tx->sdu_list, list)
F_42 ( V_9 -> V_11 ) ;
} else if ( V_17 -> V_12 [ 4 ] == 1 ) {
#ifdef F_39
F_2 ( V_5 L_8 ) ;
#endif
F_41 (t, &tx->sdu_list, list) {
F_44 ( V_9 -> V_11 , V_10 ) ;
}
if ( F_13 ( & V_8 -> V_20 ) )
V_11 -> V_67 = 0 ;
}
}
}
if ( ! V_11 -> V_42 && V_17 -> V_44 )
V_17 -> V_44 ( V_17 -> V_45 , V_17 -> V_12 , V_11 -> V_67 ) ;
F_27 ( & V_16 -> V_33 , V_51 ) ;
F_21 ( V_16 , V_17 ) ;
F_28 ( & V_16 -> V_33 , V_51 ) ;
F_28 ( & V_8 -> V_33 , V_27 ) ;
#ifdef V_30
F_45 ( V_52 ) ;
#endif
}
static int F_48 ( void * V_47 ,
void (* F_34)( void * V_45 , void * V_2 , int V_3 ) ,
void * V_45 )
{
struct V_24 * V_25 = V_47 ;
struct V_48 * V_49 = V_25 -> V_49 ;
struct V_15 * V_16 = & V_25 -> V_16 ;
struct V_14 * V_17 ;
unsigned long V_27 ;
if ( ! V_25 -> V_49 ) {
F_35 ( & V_49 -> V_52 , L_4 , V_53 ) ;
return - V_54 ;
}
F_27 ( & V_16 -> V_33 , V_27 ) ;
V_17 = F_18 ( V_16 ) ;
F_28 ( & V_16 -> V_33 , V_27 ) ;
if ( V_17 == NULL )
return - V_35 ;
V_17 -> V_44 = F_34 ;
V_17 -> V_45 = V_45 ;
F_37 ( V_17 -> V_11 ,
V_49 ,
F_49 ( V_49 , 0x82 ) ,
V_17 -> V_12 ,
V_18 ,
F_46 ,
V_17 ) ;
return F_44 ( V_17 -> V_11 , V_10 ) ;
}
static void F_50 ( struct V_69 * V_70 )
{
struct V_24 * V_25 = F_47 ( V_70 , struct V_24 , V_59 ) ;
struct V_7 * V_8 = & V_25 -> V_8 ;
int V_26 ;
unsigned long V_27 ;
V_26 = F_51 ( V_25 -> V_71 ) ;
if ( ! V_26 )
F_52 ( V_25 -> V_71 ) ;
F_27 ( & V_8 -> V_33 , V_27 ) ;
if ( ! ( V_25 -> V_49 -> V_56 & V_57 )
&& ( ! F_13 ( & V_8 -> V_29 ) || ! F_13 ( & V_8 -> V_28 ) ) ) {
struct V_6 * V_9 , * V_72 ;
F_30 (t, temp, &tx->pending_list, p_list) {
F_15 ( & V_9 -> V_58 ) ;
V_26 = F_44 ( V_9 -> V_11 , V_10 ) ;
if ( V_26 ) {
V_9 -> V_44 = NULL ;
F_31 ( V_9 -> V_11 ) ;
}
}
}
F_28 ( & V_8 -> V_33 , V_27 ) ;
}
static int F_53 ( struct V_73 * V_71 ,
const struct V_74 * V_75 )
{
int V_26 = 0 ;
T_1 V_76 ;
struct V_77 * V_77 = NULL ;
struct V_24 * V_25 = NULL ;
T_2 V_78 , V_79 , V_80 ;
struct V_48 * V_49 = F_54 ( V_71 ) ;
F_55 ( V_49 ) ;
V_76 = V_49 -> V_81 -> V_82 . V_76 ;
V_78 = F_56 ( V_49 -> V_83 . V_78 ) ;
V_79 = F_56 ( V_49 -> V_83 . V_79 ) ;
V_80 = F_56 ( V_49 -> V_83 . V_80 ) ;
F_57 ( & V_71 -> V_52 , L_9 ,
V_78 , V_79 ) ;
F_57 ( & V_71 -> V_52 , L_10 , V_84 ) ;
if ( V_79 == V_85 ) {
V_26 = F_58 ( V_49 ) ;
goto V_60;
}
if ( V_76 == V_86 ||
V_79 & V_87 ) {
V_26 = F_59 ( V_49 , V_80 ) ;
goto V_60;
}
V_77 = F_4 ( sizeof( * V_77 ) , V_88 ) ;
if ( V_77 == NULL ) {
V_26 = - V_35 ;
goto V_60;
}
V_25 = F_4 ( sizeof( * V_25 ) , V_88 ) ;
if ( V_25 == NULL ) {
V_26 = - V_35 ;
goto V_60;
}
if ( V_79 == 0x7205 || V_79 == 0x7206 )
V_25 -> V_50 = V_89 ;
else
V_25 -> V_50 = 0 ;
V_77 -> V_47 = ( void * ) V_25 ;
V_77 -> V_90 = F_33 ;
V_77 -> V_91 = F_48 ;
V_26 = F_23 ( V_25 ) ;
if ( V_26 < 0 )
goto V_60;
V_25 -> V_49 = V_49 ;
#ifdef V_30
V_25 -> V_71 = V_71 ;
V_71 -> V_92 = 1 ;
F_60 ( & V_71 -> V_52 , 1 ) ;
F_61 ( & V_49 -> V_52 , 10 * 1000 ) ;
F_62 ( & V_25 -> V_59 , F_50 ) ;
#endif
V_26 = F_63 ( V_77 , & V_71 -> V_52 ) ;
V_60:
if ( V_26 ) {
F_8 ( V_77 ) ;
F_8 ( V_25 ) ;
} else {
F_64 ( V_71 , V_77 ) ;
}
return V_26 ;
}
static void F_65 ( struct V_73 * V_71 )
{
T_1 V_76 ;
struct V_77 * V_77 ;
struct V_24 * V_25 ;
T_2 V_79 ;
struct V_48 * V_49 = F_54 ( V_71 ) ;
V_76 = V_49 -> V_81 -> V_82 . V_76 ;
V_77 = F_66 ( V_71 ) ;
V_79 = F_56 ( V_49 -> V_83 . V_79 ) ;
if ( V_79 != V_85 &&
V_76 != V_86 &&
( V_79 & V_87 ) == 0 ) {
V_25 = V_77 -> V_47 ;
V_25 -> V_49 = NULL ;
F_67 ( V_77 ) ;
F_29 ( V_25 ) ;
F_8 ( V_25 ) ;
F_8 ( V_77 ) ;
}
F_68 ( V_49 ) ;
}
static int F_69 ( struct V_73 * V_71 , T_3 V_93 )
{
struct V_77 * V_77 ;
struct V_24 * V_25 ;
struct V_15 * V_16 ;
struct V_14 * V_17 ;
unsigned long V_27 ;
V_77 = F_66 ( V_71 ) ;
if ( ! V_77 )
return 0 ;
V_25 = V_77 -> V_47 ;
V_16 = & V_25 -> V_16 ;
F_27 ( & V_16 -> V_33 , V_27 ) ;
F_41 (r, &rx->used_list, list)
F_42 ( V_17 -> V_11 ) ;
F_28 ( & V_16 -> V_33 , V_27 ) ;
return 0 ;
}
static int F_70 ( struct V_73 * V_71 )
{
struct V_77 * V_77 ;
struct V_24 * V_25 ;
struct V_15 * V_16 ;
struct V_14 * V_17 ;
unsigned long V_27 ;
V_77 = F_66 ( V_71 ) ;
if ( ! V_77 )
return 0 ;
V_25 = V_77 -> V_47 ;
V_16 = & V_25 -> V_16 ;
F_27 ( & V_16 -> V_33 , V_27 ) ;
F_41 (r, &rx->used_list, list)
F_44 ( V_17 -> V_11 , V_10 ) ;
F_28 ( & V_16 -> V_33 , V_27 ) ;
return 0 ;
}
static int F_71 ( void * V_94 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 ;
struct V_15 * V_16 ;
struct V_6 * V_9 , * V_72 ;
struct V_14 * V_17 ;
unsigned long V_27 , V_51 , V_95 ;
int V_26 ;
while ( ! V_96 ) {
F_27 ( & V_63 , V_51 ) ;
while ( ! F_13 ( & V_64 ) ) {
V_25 = F_14 ( V_64 . V_21 , struct V_24 , V_22 ) ;
V_8 = & V_25 -> V_8 ;
V_16 = & V_25 -> V_16 ;
F_15 ( & V_25 -> V_22 ) ;
F_28 ( & V_63 , V_51 ) ;
V_95 = V_97 + V_98 ;
while ( V_97 < V_95 )
F_72 ( V_98 ) ;
F_27 ( & V_16 -> V_33 , V_27 ) ;
F_41 (r, &rx->used_list, list)
F_44 ( V_17 -> V_11 , V_10 ) ;
F_28 ( & V_16 -> V_33 , V_27 ) ;
F_27 ( & V_8 -> V_33 , V_27 ) ;
F_30 (t, temp, &tx->pending_list,
p_list) {
F_15 ( & V_9 -> V_58 ) ;
V_26 = F_44 ( V_9 -> V_11 , V_10 ) ;
if ( V_26 ) {
V_9 -> V_44 = NULL ;
F_31 ( V_9 -> V_11 ) ;
}
}
V_25 -> V_61 = 0 ;
F_28 ( & V_8 -> V_33 , V_27 ) ;
F_27 ( & V_63 , V_51 ) ;
}
F_28 ( & V_63 , V_51 ) ;
F_73 ( & V_65 ) ;
}
return 0 ;
}
static int T_4 F_74 ( void )
{
#ifdef V_31
F_75 ( F_71 , NULL , L_11 ) ;
#endif
return F_76 ( & V_99 ) ;
}
static void T_5 F_77 ( void )
{
#ifdef V_31
V_96 = 1 ;
F_43 ( & V_65 ) ;
#endif
F_78 ( & V_99 ) ;
}
