static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
void * V_4 = F_2 ( V_2 , struct V_5 , V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static int F_3 ( struct V_1 * V_2 , void * V_3 )
{
void * V_4 = F_2 ( V_2 , struct V_8 , V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static void F_4 ( struct V_9 * V_9 )
{
F_5 ( & V_9 -> V_10 , V_11 ) ;
F_6 ( V_12 , & V_9 -> V_10 , 10 * V_13 ) ;
}
static struct V_5 * F_7 ( struct V_9 * V_9 ,
void * V_14 )
{
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_5 * V_5 , * V_20 = NULL ;
int V_21 ;
if ( ! V_16 )
return NULL ;
V_21 = F_8 ( V_14 , V_16 -> V_22 ) ;
V_19 = & V_16 -> V_23 [ V_21 ] ;
F_9 () ;
F_10 (tt_local_entry, node, head, hash_entry) {
if ( ! F_11 ( V_5 , V_14 ) )
continue;
V_20 = V_5 ;
break;
}
F_12 () ;
return V_20 ;
}
static struct V_8 * F_13 ( struct V_9 * V_9 ,
void * V_14 )
{
struct V_15 * V_16 = V_9 -> V_24 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_8 * V_25 = NULL ;
int V_21 ;
if ( ! V_16 )
return NULL ;
V_21 = F_8 ( V_14 , V_16 -> V_22 ) ;
V_19 = & V_16 -> V_23 [ V_21 ] ;
F_9 () ;
F_10 (tt_global_entry, node, head, hash_entry) {
if ( ! F_11 ( V_8 , V_14 ) )
continue;
V_25 = V_8 ;
break;
}
F_12 () ;
return V_25 ;
}
int F_14 ( struct V_9 * V_9 )
{
if ( V_9 -> V_17 )
return 1 ;
V_9 -> V_17 = F_15 ( 1024 ) ;
if ( ! V_9 -> V_17 )
return 0 ;
F_16 ( & V_9 -> V_26 , 0 ) ;
F_4 ( V_9 ) ;
return 1 ;
}
void F_17 ( struct V_27 * V_28 , T_1 * V_29 )
{
struct V_9 * V_9 = F_18 ( V_28 ) ;
struct V_5 * V_5 ;
struct V_8 * V_8 ;
int V_30 ;
F_19 ( & V_9 -> V_31 ) ;
V_5 = F_7 ( V_9 , V_29 ) ;
F_20 ( & V_9 -> V_31 ) ;
if ( V_5 ) {
V_5 -> V_32 = V_33 ;
return;
}
V_30 = ( V_9 -> V_34 + 1 ) * V_7 ;
V_30 += V_35 ;
if ( ( V_30 > V_36 ) ||
( F_21 ( & V_9 -> V_37 ) &&
V_30 > V_38 ) ||
( V_9 -> V_34 + 1 > 255 ) ) {
F_22 ( V_39 , V_9 ,
L_1
L_2 ,
V_29 ) ;
return;
}
F_22 ( V_39 , V_9 ,
L_3 , V_29 ) ;
V_5 = F_23 ( sizeof( struct V_5 ) , V_40 ) ;
if ( ! V_5 )
return;
memcpy ( V_5 -> V_29 , V_29 , V_7 ) ;
V_5 -> V_32 = V_33 ;
if ( F_11 ( V_29 , V_28 -> V_41 ) )
V_5 -> V_42 = 1 ;
else
V_5 -> V_42 = 0 ;
F_19 ( & V_9 -> V_31 ) ;
F_24 ( V_9 -> V_17 , F_1 , F_8 ,
V_5 , & V_5 -> V_6 ) ;
V_9 -> V_34 ++ ;
F_16 ( & V_9 -> V_26 , 1 ) ;
F_20 ( & V_9 -> V_31 ) ;
F_19 ( & V_9 -> V_43 ) ;
V_8 = F_13 ( V_9 , V_29 ) ;
if ( V_8 )
F_25 ( V_9 , V_8 ,
L_4 ) ;
F_20 ( & V_9 -> V_43 ) ;
}
int F_26 ( struct V_9 * V_9 ,
unsigned char * V_44 , int V_45 )
{
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_5 * V_5 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_46 , V_47 = 0 ;
F_19 ( & V_9 -> V_31 ) ;
for ( V_46 = 0 ; V_46 < V_16 -> V_22 ; V_46 ++ ) {
V_19 = & V_16 -> V_23 [ V_46 ] ;
F_9 () ;
F_10 (tt_local_entry, node,
head, hash_entry) {
if ( V_45 < ( V_47 + 1 ) * V_7 )
break;
memcpy ( V_44 + ( V_47 * V_7 ) , V_5 -> V_29 ,
V_7 ) ;
V_47 ++ ;
}
F_12 () ;
}
if ( V_47 == V_9 -> V_34 )
F_16 ( & V_9 -> V_26 , 0 ) ;
F_20 ( & V_9 -> V_31 ) ;
return V_47 ;
}
int F_27 ( struct V_48 * V_49 , void * V_50 )
{
struct V_27 * V_51 = (struct V_27 * ) V_49 -> V_52 ;
struct V_9 * V_9 = F_18 ( V_51 ) ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_5 * V_5 ;
struct V_53 * V_54 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
T_2 V_55 , V_56 ;
char * V_44 ;
int V_46 , V_57 = 0 ;
V_54 = F_28 ( V_9 ) ;
if ( ! V_54 ) {
V_57 = F_29 ( V_49 , L_5
L_6 ,
V_51 -> V_58 ) ;
goto V_59;
}
if ( V_54 -> V_60 != V_61 ) {
V_57 = F_29 ( V_49 , L_5
L_7 ,
V_51 -> V_58 ) ;
goto V_59;
}
F_29 ( V_49 , L_8
L_9 ,
V_51 -> V_58 ) ;
F_19 ( & V_9 -> V_31 ) ;
V_55 = 1 ;
for ( V_46 = 0 ; V_46 < V_16 -> V_22 ; V_46 ++ ) {
V_19 = & V_16 -> V_23 [ V_46 ] ;
F_9 () ;
F_30 (node, head)
V_55 += 21 ;
F_12 () ;
}
V_44 = F_23 ( V_55 , V_40 ) ;
if ( ! V_44 ) {
F_20 ( & V_9 -> V_31 ) ;
V_57 = - V_62 ;
goto V_59;
}
V_44 [ 0 ] = '\0' ;
V_56 = 0 ;
for ( V_46 = 0 ; V_46 < V_16 -> V_22 ; V_46 ++ ) {
V_19 = & V_16 -> V_23 [ V_46 ] ;
F_9 () ;
F_10 (tt_local_entry, node,
head, hash_entry) {
V_56 += snprintf ( V_44 + V_56 , 22 , L_10 ,
V_5 -> V_29 ) ;
}
F_12 () ;
}
F_20 ( & V_9 -> V_31 ) ;
F_29 ( V_49 , L_11 , V_44 ) ;
F_31 ( V_44 ) ;
V_59:
if ( V_54 )
F_32 ( V_54 ) ;
return V_57 ;
}
static void F_33 ( struct V_1 * V_2 , void * V_63 )
{
struct V_9 * V_9 = (struct V_9 * ) V_63 ;
void * V_14 = F_2 ( V_2 , struct V_5 , V_6 ) ;
F_31 ( V_14 ) ;
V_9 -> V_34 -- ;
F_16 ( & V_9 -> V_26 , 1 ) ;
}
static void F_34 ( struct V_9 * V_9 ,
struct V_5 * V_5 ,
char * V_64 )
{
F_22 ( V_39 , V_9 , L_12 ,
V_5 -> V_29 , V_64 ) ;
F_35 ( V_9 -> V_17 , F_1 , F_8 ,
V_5 -> V_29 ) ;
F_33 ( & V_5 -> V_6 , V_9 ) ;
}
void F_36 ( struct V_9 * V_9 ,
T_1 * V_29 , char * V_64 )
{
struct V_5 * V_5 ;
F_19 ( & V_9 -> V_31 ) ;
V_5 = F_7 ( V_9 , V_29 ) ;
if ( V_5 )
F_34 ( V_9 , V_5 , V_64 ) ;
F_20 ( & V_9 -> V_31 ) ;
}
static void V_11 ( struct V_65 * V_66 )
{
struct V_67 * V_67 =
F_2 ( V_66 , struct V_67 , V_66 ) ;
struct V_9 * V_9 =
F_2 ( V_67 , struct V_9 , V_10 ) ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_68 ;
struct V_18 * V_19 ;
unsigned long V_69 ;
int V_46 ;
F_19 ( & V_9 -> V_31 ) ;
for ( V_46 = 0 ; V_46 < V_16 -> V_22 ; V_46 ++ ) {
V_19 = & V_16 -> V_23 [ V_46 ] ;
F_37 (tt_local_entry, node, node_tmp,
head, hash_entry) {
if ( V_5 -> V_42 )
continue;
V_69 = V_5 -> V_32 ;
V_69 += V_70 * V_13 ;
if ( F_38 ( V_33 , V_69 ) )
continue;
F_34 ( V_9 , V_5 ,
L_13 ) ;
}
}
F_20 ( & V_9 -> V_31 ) ;
F_4 ( V_9 ) ;
}
void F_39 ( struct V_9 * V_9 )
{
if ( ! V_9 -> V_17 )
return;
F_40 ( & V_9 -> V_10 ) ;
F_41 ( V_9 -> V_17 , F_33 , V_9 ) ;
V_9 -> V_17 = NULL ;
}
int F_42 ( struct V_9 * V_9 )
{
if ( V_9 -> V_24 )
return 1 ;
V_9 -> V_24 = F_15 ( 1024 ) ;
if ( ! V_9 -> V_24 )
return 0 ;
return 1 ;
}
void F_43 ( struct V_9 * V_9 ,
struct V_71 * V_71 ,
unsigned char * V_72 , int V_73 )
{
struct V_8 * V_8 ;
struct V_5 * V_5 ;
int V_74 = 0 ;
unsigned char * V_75 ;
while ( ( V_74 + 1 ) * V_7 <= V_73 ) {
F_19 ( & V_9 -> V_43 ) ;
V_75 = V_72 + ( V_74 * V_7 ) ;
V_8 = F_13 ( V_9 , V_75 ) ;
if ( ! V_8 ) {
F_20 ( & V_9 -> V_43 ) ;
V_8 =
F_23 ( sizeof( struct V_8 ) ,
V_40 ) ;
if ( ! V_8 )
break;
memcpy ( V_8 -> V_29 , V_75 , V_7 ) ;
F_22 ( V_39 , V_9 ,
L_14
L_15 ,
V_8 -> V_29 , V_71 -> V_76 ) ;
F_19 ( & V_9 -> V_43 ) ;
F_24 ( V_9 -> V_24 , F_3 ,
F_8 , V_8 ,
& V_8 -> V_6 ) ;
}
V_8 -> V_71 = V_71 ;
F_20 ( & V_9 -> V_43 ) ;
F_19 ( & V_9 -> V_31 ) ;
V_75 = V_72 + ( V_74 * V_7 ) ;
V_5 = F_7 ( V_9 , V_75 ) ;
if ( V_5 )
F_34 ( V_9 , V_5 ,
L_16 ) ;
F_20 ( & V_9 -> V_31 ) ;
V_74 ++ ;
}
V_71 -> V_72 = NULL ;
V_71 -> V_73 = 0 ;
if ( V_73 > 0 ) {
V_71 -> V_72 = F_23 ( V_73 , V_40 ) ;
if ( V_71 -> V_72 ) {
memcpy ( V_71 -> V_72 , V_72 , V_73 ) ;
V_71 -> V_73 = V_73 ;
}
}
}
int F_44 ( struct V_48 * V_49 , void * V_50 )
{
struct V_27 * V_51 = (struct V_27 * ) V_49 -> V_52 ;
struct V_9 * V_9 = F_18 ( V_51 ) ;
struct V_15 * V_16 = V_9 -> V_24 ;
struct V_8 * V_8 ;
struct V_53 * V_54 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
T_2 V_55 , V_56 ;
char * V_44 ;
int V_46 , V_57 = 0 ;
V_54 = F_28 ( V_9 ) ;
if ( ! V_54 ) {
V_57 = F_29 ( V_49 , L_17
L_18 ,
V_51 -> V_58 ) ;
goto V_59;
}
if ( V_54 -> V_60 != V_61 ) {
V_57 = F_29 ( V_49 , L_5
L_7 ,
V_51 -> V_58 ) ;
goto V_59;
}
F_29 ( V_49 ,
L_19 ,
V_51 -> V_58 ) ;
F_19 ( & V_9 -> V_43 ) ;
V_55 = 1 ;
for ( V_46 = 0 ; V_46 < V_16 -> V_22 ; V_46 ++ ) {
V_19 = & V_16 -> V_23 [ V_46 ] ;
F_9 () ;
F_30 (node, head)
V_55 += 43 ;
F_12 () ;
}
V_44 = F_23 ( V_55 , V_40 ) ;
if ( ! V_44 ) {
F_20 ( & V_9 -> V_43 ) ;
V_57 = - V_62 ;
goto V_59;
}
V_44 [ 0 ] = '\0' ;
V_56 = 0 ;
for ( V_46 = 0 ; V_46 < V_16 -> V_22 ; V_46 ++ ) {
V_19 = & V_16 -> V_23 [ V_46 ] ;
F_9 () ;
F_10 (tt_global_entry, node,
head, hash_entry) {
V_56 += snprintf ( V_44 + V_56 , 44 ,
L_20 ,
V_8 -> V_29 ,
V_8 -> V_71 -> V_76 ) ;
}
F_12 () ;
}
F_20 ( & V_9 -> V_43 ) ;
F_29 ( V_49 , L_11 , V_44 ) ;
F_31 ( V_44 ) ;
V_59:
if ( V_54 )
F_32 ( V_54 ) ;
return V_57 ;
}
static void F_25 ( struct V_9 * V_9 ,
struct V_8 * V_8 ,
char * V_64 )
{
F_22 ( V_39 , V_9 ,
L_21 ,
V_8 -> V_29 , V_8 -> V_71 -> V_76 ,
V_64 ) ;
F_35 ( V_9 -> V_24 , F_3 , F_8 ,
V_8 -> V_29 ) ;
F_31 ( V_8 ) ;
}
void F_45 ( struct V_9 * V_9 ,
struct V_71 * V_71 , char * V_64 )
{
struct V_8 * V_8 ;
int V_74 = 0 ;
unsigned char * V_75 ;
if ( V_71 -> V_73 == 0 )
return;
F_19 ( & V_9 -> V_43 ) ;
while ( ( V_74 + 1 ) * V_7 <= V_71 -> V_73 ) {
V_75 = V_71 -> V_72 + ( V_74 * V_7 ) ;
V_8 = F_13 ( V_9 , V_75 ) ;
if ( ( V_8 ) &&
( V_8 -> V_71 == V_71 ) )
F_25 ( V_9 , V_8 ,
V_64 ) ;
V_74 ++ ;
}
F_20 ( & V_9 -> V_43 ) ;
V_71 -> V_73 = 0 ;
F_31 ( V_71 -> V_72 ) ;
V_71 -> V_72 = NULL ;
}
static void F_46 ( struct V_1 * V_2 , void * V_63 )
{
void * V_14 = F_2 ( V_2 , struct V_8 , V_6 ) ;
F_31 ( V_14 ) ;
}
void F_47 ( struct V_9 * V_9 )
{
if ( ! V_9 -> V_24 )
return;
F_41 ( V_9 -> V_24 , F_46 , NULL ) ;
V_9 -> V_24 = NULL ;
}
struct V_71 * F_48 ( struct V_9 * V_9 , T_1 * V_29 )
{
struct V_8 * V_8 ;
struct V_71 * V_71 = NULL ;
F_19 ( & V_9 -> V_43 ) ;
V_8 = F_13 ( V_9 , V_29 ) ;
if ( ! V_8 )
goto V_59;
if ( ! F_49 ( & V_8 -> V_71 -> V_77 ) )
goto V_59;
V_71 = V_8 -> V_71 ;
V_59:
F_20 ( & V_9 -> V_43 ) ;
return V_71 ;
}
