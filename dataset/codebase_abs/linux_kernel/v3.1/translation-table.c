static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static int F_3 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_8 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static void F_4 ( struct V_9 * V_9 )
{
F_5 ( & V_9 -> V_10 , V_11 ) ;
F_6 ( V_12 , & V_9 -> V_10 ,
F_7 ( 5000 ) ) ;
}
static struct V_5 * F_8 ( struct V_9 * V_9 ,
const void * V_13 )
{
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_5 * V_5 , * V_19 = NULL ;
int V_20 ;
if ( ! V_15 )
return NULL ;
V_20 = F_9 ( V_13 , V_15 -> V_21 ) ;
V_18 = & V_15 -> V_22 [ V_20 ] ;
F_10 () ;
F_11 (tt_local_entry, node, head, hash_entry) {
if ( ! F_12 ( V_5 , V_13 ) )
continue;
if ( ! F_13 ( & V_5 -> V_23 ) )
continue;
V_19 = V_5 ;
break;
}
F_14 () ;
return V_19 ;
}
static struct V_8 * F_15 ( struct V_9 * V_9 ,
const void * V_13 )
{
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_8 * V_25 = NULL ;
int V_20 ;
if ( ! V_15 )
return NULL ;
V_20 = F_9 ( V_13 , V_15 -> V_21 ) ;
V_18 = & V_15 -> V_22 [ V_20 ] ;
F_10 () ;
F_11 (tt_global_entry, node, head, hash_entry) {
if ( ! F_12 ( V_8 , V_13 ) )
continue;
if ( ! F_13 ( & V_8 -> V_23 ) )
continue;
V_25 = V_8 ;
break;
}
F_14 () ;
return V_25 ;
}
static bool F_16 ( unsigned long V_26 , unsigned long V_27 )
{
unsigned long V_28 ;
V_28 = V_26 + F_7 ( V_27 ) ;
return F_17 ( V_29 , V_28 ) ;
}
static void F_18 ( struct V_5 * V_5 )
{
if ( F_19 ( & V_5 -> V_23 ) )
F_20 ( V_5 , V_30 ) ;
}
static void F_21 ( struct V_8 * V_8 )
{
if ( F_19 ( & V_8 -> V_23 ) )
F_20 ( V_8 , V_30 ) ;
}
static void F_22 ( struct V_9 * V_9 , const T_1 * V_31 ,
T_1 V_32 )
{
struct V_33 * V_33 ;
V_33 = F_23 ( sizeof( * V_33 ) , V_34 ) ;
if ( ! V_33 )
return;
V_33 -> V_35 . V_32 = V_32 ;
memcpy ( V_33 -> V_35 . V_31 , V_31 , V_7 ) ;
F_24 ( & V_9 -> V_36 ) ;
F_25 ( & V_33 -> V_37 , & V_9 -> V_38 ) ;
F_26 ( & V_9 -> V_39 ) ;
F_27 ( & V_9 -> V_36 ) ;
F_28 ( & V_9 -> V_40 , 0 ) ;
}
int F_29 ( int V_41 )
{
return V_41 * sizeof( struct V_42 ) ;
}
static int F_30 ( struct V_9 * V_9 )
{
if ( V_9 -> V_16 )
return 1 ;
V_9 -> V_16 = F_31 ( 1024 ) ;
if ( ! V_9 -> V_16 )
return 0 ;
return 1 ;
}
void F_32 ( struct V_43 * V_44 , const T_1 * V_31 )
{
struct V_9 * V_9 = F_33 ( V_44 ) ;
struct V_5 * V_5 = NULL ;
struct V_8 * V_8 = NULL ;
V_5 = F_8 ( V_9 , V_31 ) ;
if ( V_5 ) {
V_5 -> V_45 = V_29 ;
goto V_46;
}
V_5 = F_23 ( sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 )
goto V_46;
F_34 ( V_47 , V_9 ,
L_1 , V_31 ,
( T_1 ) F_35 ( & V_9 -> V_48 ) ) ;
memcpy ( V_5 -> V_31 , V_31 , V_7 ) ;
V_5 -> V_45 = V_29 ;
V_5 -> V_32 = V_49 ;
F_28 ( & V_5 -> V_23 , 2 ) ;
if ( F_12 ( V_31 , V_44 -> V_50 ) )
V_5 -> V_32 |= V_51 ;
F_22 ( V_9 , V_31 , V_5 -> V_32 ) ;
V_5 -> V_32 |= V_52 ;
F_36 ( V_9 -> V_16 , F_1 , F_9 ,
V_5 , & V_5 -> V_6 ) ;
V_8 = F_15 ( V_9 , V_31 ) ;
if ( V_8 ) {
V_8 -> V_53 -> V_54 = true ;
V_8 -> V_32 |= V_55 ;
F_37 ( V_9 , V_8 -> V_31 ,
V_8 -> V_53 ) ;
}
V_46:
if ( V_5 )
F_18 ( V_5 ) ;
if ( V_8 )
F_21 ( V_8 ) ;
}
int F_38 ( struct V_9 * V_9 ,
unsigned char * V_56 , int V_57 )
{
int V_58 = 0 , V_59 = 0 ;
struct V_33 * V_60 , * V_61 ;
if ( V_57 > 0 )
V_59 = V_57 / F_29 ( 1 ) ;
F_24 ( & V_9 -> V_36 ) ;
F_28 ( & V_9 -> V_39 , 0 ) ;
F_39 (entry, safe, &bat_priv->tt_changes_list,
list) {
if ( V_58 < V_59 ) {
memcpy ( V_56 + F_29 ( V_58 ) ,
& V_60 -> V_35 , sizeof( struct V_42 ) ) ;
V_58 ++ ;
}
F_40 ( & V_60 -> V_37 ) ;
F_41 ( V_60 ) ;
}
F_27 ( & V_9 -> V_36 ) ;
F_24 ( & V_9 -> V_62 ) ;
F_41 ( V_9 -> V_63 ) ;
V_9 -> V_64 = 0 ;
V_9 -> V_63 = NULL ;
if ( V_57 > 0 ) {
V_9 -> V_63 = F_23 ( V_57 , V_34 ) ;
if ( V_9 -> V_63 ) {
memcpy ( V_9 -> V_63 , V_56 , V_57 ) ;
V_9 -> V_64 = V_57 ;
}
}
F_27 ( & V_9 -> V_62 ) ;
return V_59 ;
}
int F_42 ( struct V_65 * V_66 , void * V_67 )
{
struct V_43 * V_68 = (struct V_43 * ) V_66 -> V_69 ;
struct V_9 * V_9 = F_33 ( V_68 ) ;
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_5 * V_5 ;
struct V_70 * V_71 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_2 V_72 , V_73 ;
char * V_56 ;
int V_74 , V_75 = 0 ;
V_71 = F_43 ( V_9 ) ;
if ( ! V_71 ) {
V_75 = F_44 ( V_66 , L_2
L_3 ,
V_68 -> V_76 ) ;
goto V_46;
}
if ( V_71 -> V_77 != V_78 ) {
V_75 = F_44 ( V_66 , L_2
L_4 ,
V_68 -> V_76 ) ;
goto V_46;
}
F_44 ( V_66 , L_5
L_6 ,
V_68 -> V_76 , ( T_1 ) F_35 ( & V_9 -> V_48 ) ) ;
V_72 = 1 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
F_10 () ;
F_45 (node, head)
V_72 += 21 ;
F_14 () ;
}
V_56 = F_23 ( V_72 , V_34 ) ;
if ( ! V_56 ) {
V_75 = - V_79 ;
goto V_46;
}
V_56 [ 0 ] = '\0' ;
V_73 = 0 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
F_10 () ;
F_11 (tt_local_entry, node,
head, hash_entry) {
V_73 += snprintf ( V_56 + V_73 , 22 , L_7 ,
V_5 -> V_31 ) ;
}
F_14 () ;
}
F_44 ( V_66 , L_8 , V_56 ) ;
F_41 ( V_56 ) ;
V_46:
if ( V_71 )
F_46 ( V_71 ) ;
return V_75 ;
}
static void F_47 ( struct V_9 * V_9 ,
struct V_5 * V_5 ,
T_3 V_32 )
{
F_22 ( V_9 , V_5 -> V_31 ,
V_5 -> V_32 | V_32 ) ;
V_5 -> V_32 |= V_55 ;
}
void F_48 ( struct V_9 * V_9 , const T_1 * V_31 ,
const char * V_80 , bool V_81 )
{
struct V_5 * V_5 = NULL ;
V_5 = F_8 ( V_9 , V_31 ) ;
if ( ! V_5 )
goto V_46;
F_47 ( V_9 , V_5 , V_82 |
( V_81 ? V_83 : V_49 ) ) ;
F_34 ( V_47 , V_9 , L_9
L_10 , V_5 -> V_31 , V_80 ) ;
V_46:
if ( V_5 )
F_18 ( V_5 ) ;
}
static void F_49 ( struct V_9 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_84 ;
struct V_17 * V_18 ;
T_4 * V_85 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
V_85 = & V_15 -> V_86 [ V_74 ] ;
F_24 ( V_85 ) ;
F_50 (tt_local_entry, node, node_tmp,
head, hash_entry) {
if ( V_5 -> V_32 & V_51 )
continue;
if ( V_5 -> V_32 & V_55 )
continue;
if ( ! F_16 ( V_5 -> V_45 ,
V_87 * 1000 ) )
continue;
F_47 ( V_9 , V_5 ,
V_82 ) ;
F_34 ( V_47 , V_9 , L_11
L_12 ,
V_5 -> V_31 ) ;
}
F_27 ( V_85 ) ;
}
}
static void F_51 ( struct V_9 * V_9 )
{
struct V_14 * V_15 ;
T_4 * V_85 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_84 ;
struct V_17 * V_18 ;
int V_74 ;
if ( ! V_9 -> V_16 )
return;
V_15 = V_9 -> V_16 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
V_85 = & V_15 -> V_86 [ V_74 ] ;
F_24 ( V_85 ) ;
F_50 (tt_local_entry, node, node_tmp,
head, hash_entry) {
F_52 ( V_2 ) ;
F_18 ( V_5 ) ;
}
F_27 ( V_85 ) ;
}
F_53 ( V_15 ) ;
V_9 -> V_16 = NULL ;
}
static int F_54 ( struct V_9 * V_9 )
{
if ( V_9 -> V_24 )
return 1 ;
V_9 -> V_24 = F_31 ( 1024 ) ;
if ( ! V_9 -> V_24 )
return 0 ;
return 1 ;
}
static void F_55 ( struct V_9 * V_9 )
{
struct V_33 * V_60 , * V_61 ;
F_24 ( & V_9 -> V_36 ) ;
F_39 (entry, safe, &bat_priv->tt_changes_list,
list) {
F_40 ( & V_60 -> V_37 ) ;
F_41 ( V_60 ) ;
}
F_28 ( & V_9 -> V_39 , 0 ) ;
F_27 ( & V_9 -> V_36 ) ;
}
int F_56 ( struct V_9 * V_9 , struct V_53 * V_53 ,
const unsigned char * V_88 , T_1 V_48 , bool V_81 )
{
struct V_8 * V_8 ;
struct V_53 * V_89 ;
int V_75 = 0 ;
V_8 = F_15 ( V_9 , V_88 ) ;
if ( ! V_8 ) {
V_8 =
F_23 ( sizeof( * V_8 ) ,
V_34 ) ;
if ( ! V_8 )
goto V_46;
memcpy ( V_8 -> V_31 , V_88 , V_7 ) ;
F_26 ( & V_53 -> V_23 ) ;
V_8 -> V_53 = V_53 ;
V_8 -> V_48 = V_48 ;
V_8 -> V_32 = V_49 ;
V_8 -> V_90 = 0 ;
F_28 ( & V_8 -> V_23 , 2 ) ;
F_36 ( V_9 -> V_24 , F_3 ,
F_9 , V_8 ,
& V_8 -> V_6 ) ;
F_26 ( & V_53 -> V_91 ) ;
} else {
if ( V_8 -> V_53 != V_53 ) {
F_57 ( & V_8 -> V_53 -> V_91 ) ;
V_89 = V_8 -> V_53 ;
F_26 ( & V_53 -> V_23 ) ;
V_8 -> V_53 = V_53 ;
F_58 ( V_89 ) ;
F_26 ( & V_53 -> V_91 ) ;
}
V_8 -> V_48 = V_48 ;
V_8 -> V_32 = V_49 ;
V_8 -> V_90 = 0 ;
}
F_34 ( V_47 , V_9 ,
L_13 ,
V_8 -> V_31 , V_53 -> V_92 ) ;
F_48 ( V_9 , V_8 -> V_31 ,
L_14 , V_81 ) ;
V_75 = 1 ;
V_46:
if ( V_8 )
F_21 ( V_8 ) ;
return V_75 ;
}
int F_59 ( struct V_65 * V_66 , void * V_67 )
{
struct V_43 * V_68 = (struct V_43 * ) V_66 -> V_69 ;
struct V_9 * V_9 = F_33 ( V_68 ) ;
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_8 * V_8 ;
struct V_70 * V_71 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_2 V_72 , V_73 ;
char * V_56 ;
int V_74 , V_75 = 0 ;
V_71 = F_43 ( V_9 ) ;
if ( ! V_71 ) {
V_75 = F_44 ( V_66 , L_15
L_16 ,
V_68 -> V_76 ) ;
goto V_46;
}
if ( V_71 -> V_77 != V_78 ) {
V_75 = F_44 ( V_66 , L_2
L_4 ,
V_68 -> V_76 ) ;
goto V_46;
}
F_44 ( V_66 ,
L_17 ,
V_68 -> V_76 ) ;
F_44 ( V_66 , L_18 ,
L_19 , L_20 , L_21 , L_22 ) ;
V_72 = 1 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
F_10 () ;
F_45 (node, head)
V_72 += 59 ;
F_14 () ;
}
V_56 = F_23 ( V_72 , V_34 ) ;
if ( ! V_56 ) {
V_75 = - V_79 ;
goto V_46;
}
V_56 [ 0 ] = '\0' ;
V_73 = 0 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
F_10 () ;
F_11 (tt_global_entry, node,
head, hash_entry) {
V_73 += snprintf ( V_56 + V_73 , 61 ,
L_23 ,
V_8 -> V_31 ,
V_8 -> V_48 ,
V_8 -> V_53 -> V_92 ,
( T_1 ) F_35 (
& V_8 -> V_53 ->
V_93 ) ) ;
}
F_14 () ;
}
F_44 ( V_66 , L_8 , V_56 ) ;
F_41 ( V_56 ) ;
V_46:
if ( V_71 )
F_46 ( V_71 ) ;
return V_75 ;
}
static void F_60 ( struct V_9 * V_9 ,
struct V_8 * V_8 ,
const char * V_80 )
{
if ( ! V_8 )
goto V_46;
F_34 ( V_47 , V_9 ,
L_24 ,
V_8 -> V_31 , V_8 -> V_53 -> V_92 ,
V_80 ) ;
F_57 ( & V_8 -> V_53 -> V_91 ) ;
F_61 ( V_9 -> V_24 , F_3 , F_9 ,
V_8 -> V_31 ) ;
V_46:
if ( V_8 )
F_21 ( V_8 ) ;
}
void F_62 ( struct V_9 * V_9 ,
struct V_53 * V_53 , const unsigned char * V_31 ,
const char * V_80 , bool V_81 )
{
struct V_8 * V_8 = NULL ;
V_8 = F_15 ( V_9 , V_31 ) ;
if ( ! V_8 )
goto V_46;
if ( V_8 -> V_53 == V_53 ) {
if ( V_81 ) {
V_8 -> V_32 |= V_83 ;
V_8 -> V_90 = V_29 ;
goto V_46;
}
F_60 ( V_9 , V_8 , V_80 ) ;
}
V_46:
if ( V_8 )
F_21 ( V_8 ) ;
}
void F_63 ( struct V_9 * V_9 ,
struct V_53 * V_53 , const char * V_80 )
{
struct V_8 * V_8 ;
int V_74 ;
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_1 * V_2 , * V_61 ;
struct V_17 * V_18 ;
T_4 * V_85 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
V_85 = & V_15 -> V_86 [ V_74 ] ;
F_24 ( V_85 ) ;
F_50 (tt_global_entry, node, safe,
head, hash_entry) {
if ( V_8 -> V_53 == V_53 ) {
F_34 ( V_47 , V_9 ,
L_25
L_26 ,
V_8 -> V_31 ,
V_8 -> V_53 -> V_92 ) ;
F_52 ( V_2 ) ;
F_21 ( V_8 ) ;
}
}
F_27 ( V_85 ) ;
}
F_28 ( & V_53 -> V_91 , 0 ) ;
}
static void F_64 ( struct V_9 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_8 * V_8 ;
struct V_1 * V_2 , * V_84 ;
struct V_17 * V_18 ;
T_4 * V_85 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
V_85 = & V_15 -> V_86 [ V_74 ] ;
F_24 ( V_85 ) ;
F_50 (tt_global_entry, node, node_tmp,
head, hash_entry) {
if ( ! ( V_8 -> V_32 & V_83 ) )
continue;
if ( ! F_16 ( V_8 -> V_90 ,
V_94 * 1000 ) )
continue;
F_34 ( V_47 , V_9 , L_27
L_28 ,
V_8 -> V_31 ) ;
F_57 ( & V_8 -> V_53 -> V_91 ) ;
F_52 ( V_2 ) ;
F_21 ( V_8 ) ;
}
F_27 ( V_85 ) ;
}
}
static void F_65 ( struct V_9 * V_9 )
{
struct V_14 * V_15 ;
T_4 * V_85 ;
struct V_8 * V_8 ;
struct V_1 * V_2 , * V_84 ;
struct V_17 * V_18 ;
int V_74 ;
if ( ! V_9 -> V_24 )
return;
V_15 = V_9 -> V_24 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
V_85 = & V_15 -> V_86 [ V_74 ] ;
F_24 ( V_85 ) ;
F_50 (tt_global_entry, node, node_tmp,
head, hash_entry) {
F_52 ( V_2 ) ;
F_21 ( V_8 ) ;
}
F_27 ( V_85 ) ;
}
F_53 ( V_15 ) ;
V_9 -> V_24 = NULL ;
}
struct V_53 * F_66 ( struct V_9 * V_9 ,
const T_1 * V_31 )
{
struct V_8 * V_8 ;
struct V_53 * V_53 = NULL ;
V_8 = F_15 ( V_9 , V_31 ) ;
if ( ! V_8 )
goto V_46;
if ( ! F_13 ( & V_8 -> V_53 -> V_23 ) )
goto V_95;
if ( V_8 -> V_32 & V_55 )
goto V_95;
V_53 = V_8 -> V_53 ;
V_95:
F_21 ( V_8 ) ;
V_46:
return V_53 ;
}
T_3 F_67 ( struct V_9 * V_9 , struct V_53 * V_53 )
{
T_3 V_96 = 0 , V_97 ;
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_8 * V_8 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
int V_74 , V_98 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
F_10 () ;
F_11 (tt_global_entry, node,
head, hash_entry) {
if ( F_12 ( V_8 -> V_53 ,
V_53 ) ) {
if ( V_8 -> V_32 & V_83 )
continue;
V_97 = 0 ;
for ( V_98 = 0 ; V_98 < V_7 ; V_98 ++ )
V_97 = F_68 ( V_97 ,
V_8 -> V_31 [ V_98 ] ) ;
V_96 ^= V_97 ;
}
}
F_14 () ;
}
return V_96 ;
}
T_3 F_69 ( struct V_9 * V_9 )
{
T_3 V_96 = 0 , V_97 ;
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_5 * V_5 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
int V_74 , V_98 ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
F_10 () ;
F_11 (tt_local_entry, node,
head, hash_entry) {
if ( V_5 -> V_32 & V_52 )
continue;
V_97 = 0 ;
for ( V_98 = 0 ; V_98 < V_7 ; V_98 ++ )
V_97 = F_68 ( V_97 ,
V_5 -> V_31 [ V_98 ] ) ;
V_96 ^= V_97 ;
}
F_14 () ;
}
return V_96 ;
}
static void F_70 ( struct V_9 * V_9 )
{
struct V_99 * V_2 , * V_61 ;
F_24 ( & V_9 -> V_100 ) ;
F_39 (node, safe, &bat_priv->tt_req_list, list) {
F_40 ( & V_2 -> V_37 ) ;
F_41 ( V_2 ) ;
}
F_27 ( & V_9 -> V_100 ) ;
}
void F_71 ( struct V_9 * V_9 , struct V_53 * V_53 ,
const unsigned char * V_63 , T_1 V_101 )
{
T_3 V_64 = F_29 ( V_101 ) ;
F_24 ( & V_53 -> V_62 ) ;
if ( V_64 > 0 ) {
F_41 ( V_53 -> V_63 ) ;
V_53 -> V_64 = 0 ;
V_53 -> V_63 = F_23 ( V_64 , V_34 ) ;
if ( V_53 -> V_63 ) {
memcpy ( V_53 -> V_63 , V_63 , V_64 ) ;
V_53 -> V_64 = V_64 ;
}
}
F_27 ( & V_53 -> V_62 ) ;
}
static void F_72 ( struct V_9 * V_9 )
{
struct V_99 * V_2 , * V_61 ;
F_24 ( & V_9 -> V_100 ) ;
F_39 (node, safe, &bat_priv->tt_req_list, list) {
if ( F_16 ( V_2 -> V_102 ,
V_103 * 1000 ) ) {
F_40 ( & V_2 -> V_37 ) ;
F_41 ( V_2 ) ;
}
}
F_27 ( & V_9 -> V_100 ) ;
}
static struct V_99 * F_73 ( struct V_9 * V_9 ,
struct V_53 * V_53 )
{
struct V_99 * V_104 , * V_99 = NULL ;
F_24 ( & V_9 -> V_100 ) ;
F_74 (tt_req_node_tmp, &bat_priv->tt_req_list, list) {
if ( F_12 ( V_104 , V_53 ) &&
! F_16 ( V_104 -> V_102 ,
V_103 * 1000 ) )
goto V_105;
}
V_99 = F_23 ( sizeof( * V_99 ) , V_34 ) ;
if ( ! V_99 )
goto V_105;
memcpy ( V_99 -> V_31 , V_53 -> V_92 , V_7 ) ;
V_99 -> V_102 = V_29 ;
F_75 ( & V_99 -> V_37 , & V_9 -> V_106 ) ;
V_105:
F_27 ( & V_9 -> V_100 ) ;
return V_99 ;
}
static int F_76 ( const void * V_107 , const void * V_108 )
{
const struct V_5 * V_5 = V_107 ;
if ( V_5 -> V_32 & V_52 )
return 0 ;
return 1 ;
}
static int F_77 ( const void * V_107 , const void * V_108 )
{
const struct V_8 * V_8 = V_107 ;
const struct V_53 * V_53 = V_108 ;
if ( V_8 -> V_32 & V_83 )
return 0 ;
return ( V_8 -> V_53 == V_53 ) ;
}
static struct V_109 * F_78 ( T_3 F_29 , T_1 V_48 ,
struct V_14 * V_15 ,
struct V_70 * V_71 ,
int (* F_79)( const void * ,
const void * ) ,
void * V_110 )
{
struct V_5 * V_5 ;
struct V_111 * V_112 ;
struct V_42 * V_42 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_109 * V_113 = NULL ;
T_3 V_114 , V_115 ;
T_5 V_116 = sizeof( struct V_111 ) ;
int V_74 ;
if ( V_116 + F_29 > V_71 -> V_44 -> V_117 ) {
F_29 = V_71 -> V_44 -> V_117 - V_116 ;
F_29 -= F_29 % sizeof( struct V_42 ) ;
}
V_114 = F_29 / sizeof( struct V_42 ) ;
V_113 = F_80 ( V_116 + F_29 + V_118 ) ;
if ( ! V_113 )
goto V_46;
F_81 ( V_113 , V_118 ) ;
V_112 = (struct V_111 * ) F_82 ( V_113 ,
V_116 + F_29 ) ;
V_112 -> V_48 = V_48 ;
V_112 -> V_119 = F_83 ( V_114 ) ;
V_42 = (struct V_42 * ) ( V_113 -> V_13 + V_116 ) ;
V_115 = 0 ;
F_10 () ;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
F_11 (tt_local_entry, node,
head, hash_entry) {
if ( V_115 == V_114 )
break;
if ( ( F_79 ) && ( ! F_79 ( V_5 , V_110 ) ) )
continue;
memcpy ( V_42 -> V_31 , V_5 -> V_31 , V_7 ) ;
V_42 -> V_32 = V_49 ;
V_115 ++ ;
V_42 ++ ;
}
}
F_14 () ;
V_46:
return V_113 ;
}
int F_84 ( struct V_9 * V_9 , struct V_53 * V_120 ,
T_1 V_48 , T_3 V_121 , bool V_122 )
{
struct V_109 * V_113 = NULL ;
struct V_111 * V_123 ;
struct V_124 * V_124 = NULL ;
struct V_70 * V_71 ;
struct V_99 * V_99 = NULL ;
int V_75 = 1 ;
V_71 = F_43 ( V_9 ) ;
if ( ! V_71 )
goto V_46;
V_99 = F_73 ( V_9 , V_120 ) ;
if ( ! V_99 )
goto V_46;
V_113 = F_80 ( sizeof( struct V_111 ) + V_118 ) ;
if ( ! V_113 )
goto V_46;
F_81 ( V_113 , V_118 ) ;
V_123 = (struct V_111 * ) F_82 ( V_113 ,
sizeof( struct V_111 ) ) ;
V_123 -> V_125 = V_126 ;
V_123 -> V_127 = V_128 ;
memcpy ( V_123 -> V_129 , V_71 -> V_68 -> V_50 , V_7 ) ;
memcpy ( V_123 -> V_130 , V_120 -> V_92 , V_7 ) ;
V_123 -> V_131 = V_132 ;
V_123 -> V_48 = V_48 ;
V_123 -> V_119 = V_121 ;
V_123 -> V_32 = V_133 ;
if ( V_122 )
V_123 -> V_32 |= V_134 ;
V_124 = F_85 ( V_120 ) ;
if ( ! V_124 )
goto V_46;
F_34 ( V_47 , V_9 , L_29
L_30 , V_120 -> V_92 , V_124 -> V_31 ,
( V_122 ? 'F' : '.' ) ) ;
F_86 ( V_113 , V_124 -> V_135 , V_124 -> V_31 ) ;
V_75 = 0 ;
V_46:
if ( V_124 )
F_87 ( V_124 ) ;
if ( V_71 )
F_46 ( V_71 ) ;
if ( V_75 )
F_88 ( V_113 ) ;
if ( V_75 && V_99 ) {
F_24 ( & V_9 -> V_100 ) ;
F_40 ( & V_99 -> V_37 ) ;
F_27 ( & V_9 -> V_100 ) ;
F_41 ( V_99 ) ;
}
return V_75 ;
}
static bool F_89 ( struct V_9 * V_9 ,
struct V_111 * V_123 )
{
struct V_53 * V_136 = NULL , * V_137 = NULL ;
struct V_124 * V_124 = NULL ;
struct V_70 * V_71 = NULL ;
T_1 V_138 , V_139 , V_48 ;
int V_75 = false ;
unsigned char * V_63 ;
bool V_122 ;
T_3 F_29 , V_114 ;
struct V_109 * V_113 = NULL ;
struct V_111 * V_112 ;
F_34 ( V_47 , V_9 ,
L_31
L_32 , V_123 -> V_129 ,
V_123 -> V_48 , V_123 -> V_130 ,
( V_123 -> V_32 & V_134 ? 'F' : '.' ) ) ;
V_136 = F_90 ( V_9 , V_123 -> V_130 ) ;
if ( ! V_136 )
goto V_46;
V_137 = F_90 ( V_9 , V_123 -> V_129 ) ;
if ( ! V_137 )
goto V_46;
V_124 = F_85 ( V_137 ) ;
if ( ! V_124 )
goto V_46;
V_71 = F_43 ( V_9 ) ;
if ( ! V_71 )
goto V_46;
V_138 = ( T_1 ) F_35 ( & V_136 -> V_93 ) ;
V_139 = V_123 -> V_48 ;
if ( V_138 != V_139 ||
V_123 -> V_119 != V_136 -> V_121 )
goto V_46;
if ( V_123 -> V_32 & V_134 ||
! V_136 -> V_63 )
V_122 = true ;
else
V_122 = false ;
if ( ! V_122 ) {
F_24 ( & V_136 -> V_62 ) ;
F_29 = V_136 -> V_64 ;
V_114 = F_29 / sizeof( struct V_42 ) ;
V_113 = F_80 ( sizeof( struct V_111 ) +
F_29 + V_118 ) ;
if ( ! V_113 )
goto V_105;
F_81 ( V_113 , V_118 ) ;
V_112 = (struct V_111 * ) F_82 ( V_113 ,
sizeof( struct V_111 ) + F_29 ) ;
V_112 -> V_48 = V_139 ;
V_112 -> V_119 = F_83 ( V_114 ) ;
V_63 = V_113 -> V_13 + sizeof( struct V_111 ) ;
memcpy ( V_63 , V_136 -> V_63 ,
V_136 -> V_64 ) ;
F_27 ( & V_136 -> V_62 ) ;
} else {
F_29 = ( T_3 ) F_35 ( & V_136 -> V_91 ) *
sizeof( struct V_42 ) ;
V_48 = ( T_1 ) F_35 ( & V_136 -> V_93 ) ;
V_113 = F_78 ( F_29 , V_48 ,
V_9 -> V_24 ,
V_71 , F_77 ,
V_136 ) ;
if ( ! V_113 )
goto V_46;
V_112 = (struct V_111 * ) V_113 -> V_13 ;
}
V_112 -> V_125 = V_126 ;
V_112 -> V_127 = V_128 ;
V_112 -> V_131 = V_132 ;
memcpy ( V_112 -> V_129 , V_136 -> V_92 , V_7 ) ;
memcpy ( V_112 -> V_130 , V_123 -> V_129 , V_7 ) ;
V_112 -> V_32 = V_140 ;
if ( V_122 )
V_112 -> V_32 |= V_134 ;
F_34 ( V_47 , V_9 ,
L_33 ,
V_137 -> V_92 , V_124 -> V_31 ,
V_136 -> V_92 , V_139 ) ;
F_86 ( V_113 , V_124 -> V_135 , V_124 -> V_31 ) ;
V_75 = true ;
goto V_46;
V_105:
F_27 ( & V_136 -> V_62 ) ;
V_46:
if ( V_137 )
F_58 ( V_137 ) ;
if ( V_136 )
F_58 ( V_136 ) ;
if ( V_124 )
F_87 ( V_124 ) ;
if ( V_71 )
F_46 ( V_71 ) ;
if ( ! V_75 )
F_88 ( V_113 ) ;
return V_75 ;
}
static bool F_91 ( struct V_9 * V_9 ,
struct V_111 * V_123 )
{
struct V_53 * V_53 = NULL ;
struct V_124 * V_124 = NULL ;
struct V_70 * V_71 = NULL ;
T_1 V_141 , V_139 , V_48 ;
int V_75 = false ;
unsigned char * V_63 ;
bool V_122 ;
T_3 F_29 , V_114 ;
struct V_109 * V_113 = NULL ;
struct V_111 * V_112 ;
F_34 ( V_47 , V_9 ,
L_31
L_34 , V_123 -> V_129 ,
V_123 -> V_48 ,
( V_123 -> V_32 & V_134 ? 'F' : '.' ) ) ;
V_141 = ( T_1 ) F_35 ( & V_9 -> V_48 ) ;
V_139 = V_123 -> V_48 ;
V_53 = F_90 ( V_9 , V_123 -> V_129 ) ;
if ( ! V_53 )
goto V_46;
V_124 = F_85 ( V_53 ) ;
if ( ! V_124 )
goto V_46;
V_71 = F_43 ( V_9 ) ;
if ( ! V_71 )
goto V_46;
if ( V_123 -> V_32 & V_134 || V_141 != V_139 ||
! V_9 -> V_63 )
V_122 = true ;
else
V_122 = false ;
if ( ! V_122 ) {
F_24 ( & V_9 -> V_62 ) ;
F_29 = V_9 -> V_64 ;
V_114 = F_29 / sizeof( struct V_42 ) ;
V_113 = F_80 ( sizeof( struct V_111 ) +
F_29 + V_118 ) ;
if ( ! V_113 )
goto V_105;
F_81 ( V_113 , V_118 ) ;
V_112 = (struct V_111 * ) F_82 ( V_113 ,
sizeof( struct V_111 ) + F_29 ) ;
V_112 -> V_48 = V_139 ;
V_112 -> V_119 = F_83 ( V_114 ) ;
V_63 = V_113 -> V_13 + sizeof( struct V_111 ) ;
memcpy ( V_63 , V_9 -> V_63 ,
V_9 -> V_64 ) ;
F_27 ( & V_9 -> V_62 ) ;
} else {
F_29 = ( T_3 ) F_35 ( & V_9 -> V_142 ) *
sizeof( struct V_42 ) ;
V_48 = ( T_1 ) F_35 ( & V_9 -> V_48 ) ;
V_113 = F_78 ( F_29 , V_48 ,
V_9 -> V_16 ,
V_71 , F_76 ,
NULL ) ;
if ( ! V_113 )
goto V_46;
V_112 = (struct V_111 * ) V_113 -> V_13 ;
}
V_112 -> V_125 = V_126 ;
V_112 -> V_127 = V_128 ;
V_112 -> V_131 = V_132 ;
memcpy ( V_112 -> V_129 , V_71 -> V_68 -> V_50 , V_7 ) ;
memcpy ( V_112 -> V_130 , V_123 -> V_129 , V_7 ) ;
V_112 -> V_32 = V_140 ;
if ( V_122 )
V_112 -> V_32 |= V_134 ;
F_34 ( V_47 , V_9 ,
L_35 ,
V_53 -> V_92 , V_124 -> V_31 ,
( V_112 -> V_32 & V_134 ? 'F' : '.' ) ) ;
F_86 ( V_113 , V_124 -> V_135 , V_124 -> V_31 ) ;
V_75 = true ;
goto V_46;
V_105:
F_27 ( & V_9 -> V_62 ) ;
V_46:
if ( V_53 )
F_58 ( V_53 ) ;
if ( V_124 )
F_87 ( V_124 ) ;
if ( V_71 )
F_46 ( V_71 ) ;
if ( ! V_75 )
F_88 ( V_113 ) ;
return true ;
}
bool F_92 ( struct V_9 * V_9 ,
struct V_111 * V_123 )
{
if ( F_93 ( V_123 -> V_130 ) )
return F_91 ( V_9 , V_123 ) ;
else
return F_89 ( V_9 , V_123 ) ;
}
static void F_94 ( struct V_9 * V_9 ,
struct V_53 * V_53 ,
struct V_42 * V_42 ,
T_3 V_101 , T_1 V_48 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_101 ; V_74 ++ ) {
if ( ( V_42 + V_74 ) -> V_32 & V_82 )
F_62 ( V_9 , V_53 ,
( V_42 + V_74 ) -> V_31 ,
L_36 ,
( V_42 + V_74 ) -> V_32 & V_83 ) ;
else
if ( ! F_56 ( V_9 , V_53 ,
( V_42 + V_74 ) -> V_31 , V_48 , false ) )
return;
}
}
static void F_95 ( struct V_9 * V_9 ,
struct V_111 * V_112 )
{
struct V_53 * V_53 = NULL ;
V_53 = F_96 ( V_9 , V_112 -> V_129 ) ;
if ( ! V_53 )
goto V_46;
F_63 ( V_9 , V_53 , L_37 ) ;
F_94 ( V_9 , V_53 ,
(struct V_42 * ) ( V_112 + 1 ) ,
V_112 -> V_119 , V_112 -> V_48 ) ;
F_24 ( & V_53 -> V_62 ) ;
F_41 ( V_53 -> V_63 ) ;
V_53 -> V_64 = 0 ;
V_53 -> V_63 = NULL ;
F_27 ( & V_53 -> V_62 ) ;
F_28 ( & V_53 -> V_93 , V_112 -> V_48 ) ;
V_46:
if ( V_53 )
F_58 ( V_53 ) ;
}
void F_97 ( struct V_9 * V_9 , struct V_53 * V_53 ,
T_3 V_101 , T_1 V_48 ,
struct V_42 * V_42 )
{
F_94 ( V_9 , V_53 , V_42 , V_101 ,
V_48 ) ;
F_71 ( V_9 , V_53 , ( unsigned char * ) V_42 ,
V_101 ) ;
F_28 ( & V_53 -> V_93 , V_48 ) ;
}
bool F_98 ( struct V_9 * V_9 , const T_1 * V_31 )
{
struct V_5 * V_5 = NULL ;
bool V_75 = false ;
V_5 = F_8 ( V_9 , V_31 ) ;
if ( ! V_5 )
goto V_46;
if ( V_5 -> V_32 & V_55 )
goto V_46;
V_75 = true ;
V_46:
if ( V_5 )
F_18 ( V_5 ) ;
return V_75 ;
}
void F_99 ( struct V_9 * V_9 ,
struct V_111 * V_112 )
{
struct V_99 * V_2 , * V_61 ;
struct V_53 * V_53 = NULL ;
F_34 ( V_47 , V_9 , L_38
L_39 ,
V_112 -> V_129 , V_112 -> V_48 ,
V_112 -> V_119 ,
( V_112 -> V_32 & V_134 ? 'F' : '.' ) ) ;
V_53 = F_96 ( V_9 , V_112 -> V_129 ) ;
if ( ! V_53 )
goto V_46;
if ( V_112 -> V_32 & V_134 )
F_95 ( V_9 , V_112 ) ;
else
F_97 ( V_9 , V_53 , V_112 -> V_119 ,
V_112 -> V_48 ,
(struct V_42 * ) ( V_112 + 1 ) ) ;
F_24 ( & V_9 -> V_100 ) ;
F_39 (node, safe, &bat_priv->tt_req_list, list) {
if ( ! F_12 ( V_2 -> V_31 , V_112 -> V_129 ) )
continue;
F_40 ( & V_2 -> V_37 ) ;
F_41 ( V_2 ) ;
}
F_27 ( & V_9 -> V_100 ) ;
V_53 -> V_121 = F_67 ( V_9 , V_53 ) ;
V_53 -> V_54 = false ;
V_46:
if ( V_53 )
F_58 ( V_53 ) ;
}
int F_100 ( struct V_9 * V_9 )
{
if ( ! F_30 ( V_9 ) )
return 0 ;
if ( ! F_54 ( V_9 ) )
return 0 ;
F_4 ( V_9 ) ;
return 1 ;
}
static void F_101 ( struct V_9 * V_9 )
{
struct V_143 * V_2 , * V_61 ;
F_24 ( & V_9 -> V_144 ) ;
F_39 (node, safe, &bat_priv->tt_roam_list, list) {
F_40 ( & V_2 -> V_37 ) ;
F_41 ( V_2 ) ;
}
F_27 ( & V_9 -> V_144 ) ;
}
static void F_102 ( struct V_9 * V_9 )
{
struct V_143 * V_2 , * V_61 ;
F_24 ( & V_9 -> V_144 ) ;
F_39 (node, safe, &bat_priv->tt_roam_list, list) {
if ( ! F_16 ( V_2 -> V_145 ,
V_146 * 1000 ) )
continue;
F_40 ( & V_2 -> V_37 ) ;
F_41 ( V_2 ) ;
}
F_27 ( & V_9 -> V_144 ) ;
}
static bool F_103 ( struct V_9 * V_9 ,
T_1 * V_147 )
{
struct V_143 * V_143 ;
bool V_75 = false ;
F_24 ( & V_9 -> V_144 ) ;
F_74 (tt_roam_node, &bat_priv->tt_roam_list, list) {
if ( ! F_12 ( V_143 -> V_31 , V_147 ) )
continue;
if ( F_16 ( V_143 -> V_145 ,
V_146 * 1000 ) )
continue;
if ( ! F_104 ( & V_143 -> V_148 ) )
goto V_105;
V_75 = true ;
break;
}
if ( ! V_75 ) {
V_143 = F_23 ( sizeof( * V_143 ) , V_34 ) ;
if ( ! V_143 )
goto V_105;
V_143 -> V_145 = V_29 ;
F_28 ( & V_143 -> V_148 , V_149 - 1 ) ;
memcpy ( V_143 -> V_31 , V_147 , V_7 ) ;
F_75 ( & V_143 -> V_37 , & V_9 -> V_150 ) ;
V_75 = true ;
}
V_105:
F_27 ( & V_9 -> V_144 ) ;
return V_75 ;
}
void F_37 ( struct V_9 * V_9 , T_1 * V_147 ,
struct V_53 * V_53 )
{
struct V_124 * V_124 = NULL ;
struct V_109 * V_113 = NULL ;
struct V_151 * V_151 ;
int V_75 = 1 ;
struct V_70 * V_71 ;
if ( ! F_103 ( V_9 , V_147 ) )
goto V_46;
V_113 = F_80 ( sizeof( struct V_151 ) + V_118 ) ;
if ( ! V_113 )
goto V_46;
F_81 ( V_113 , V_118 ) ;
V_151 = (struct V_151 * ) F_82 ( V_113 ,
sizeof( struct V_151 ) ) ;
V_151 -> V_125 = V_152 ;
V_151 -> V_127 = V_128 ;
V_151 -> V_131 = V_132 ;
V_71 = F_43 ( V_9 ) ;
if ( ! V_71 )
goto V_46;
memcpy ( V_151 -> V_129 , V_71 -> V_68 -> V_50 , V_7 ) ;
F_46 ( V_71 ) ;
memcpy ( V_151 -> V_130 , V_53 -> V_92 , V_7 ) ;
memcpy ( V_151 -> V_147 , V_147 , V_7 ) ;
V_124 = F_85 ( V_53 ) ;
if ( ! V_124 )
goto V_46;
F_34 ( V_47 , V_9 ,
L_40 ,
V_53 -> V_92 , V_147 , V_124 -> V_31 ) ;
F_86 ( V_113 , V_124 -> V_135 , V_124 -> V_31 ) ;
V_75 = 0 ;
V_46:
if ( V_124 )
F_87 ( V_124 ) ;
if ( V_75 )
F_88 ( V_113 ) ;
return;
}
static void V_11 ( struct V_153 * V_154 )
{
struct V_155 * V_155 =
F_2 ( V_154 , struct V_155 , V_154 ) ;
struct V_9 * V_9 =
F_2 ( V_155 , struct V_9 , V_10 ) ;
F_49 ( V_9 ) ;
F_64 ( V_9 ) ;
F_72 ( V_9 ) ;
F_102 ( V_9 ) ;
F_4 ( V_9 ) ;
}
void F_105 ( struct V_9 * V_9 )
{
F_106 ( & V_9 -> V_10 ) ;
F_51 ( V_9 ) ;
F_65 ( V_9 ) ;
F_70 ( V_9 ) ;
F_55 ( V_9 ) ;
F_101 ( V_9 ) ;
F_41 ( V_9 -> V_63 ) ;
}
static void F_107 ( struct V_9 * V_9 , T_3 V_32 )
{
int V_74 ;
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
if ( ! V_15 )
return;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
F_10 () ;
F_11 (tt_local_entry, node,
head, hash_entry) {
V_5 -> V_32 &= ~ V_32 ;
F_26 ( & V_9 -> V_142 ) ;
}
F_14 () ;
}
}
static void F_108 ( struct V_9 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_84 ;
struct V_17 * V_18 ;
T_4 * V_85 ;
int V_74 ;
if ( ! V_15 )
return;
for ( V_74 = 0 ; V_74 < V_15 -> V_21 ; V_74 ++ ) {
V_18 = & V_15 -> V_22 [ V_74 ] ;
V_85 = & V_15 -> V_86 [ V_74 ] ;
F_24 ( V_85 ) ;
F_50 (tt_local_entry, node, node_tmp,
head, hash_entry) {
if ( ! ( V_5 -> V_32 & V_55 ) )
continue;
F_34 ( V_47 , V_9 , L_41
L_42 , V_5 -> V_31 ) ;
F_57 ( & V_9 -> V_142 ) ;
F_52 ( V_2 ) ;
F_18 ( V_5 ) ;
}
F_27 ( V_85 ) ;
}
}
void F_109 ( struct V_9 * V_9 )
{
F_107 ( V_9 , V_52 ) ;
F_108 ( V_9 ) ;
F_26 ( & V_9 -> V_48 ) ;
V_9 -> V_54 = false ;
}
