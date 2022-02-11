static int F_1 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_4 [ V_2 ] == V_1 )
return V_2 ;
}
return - 1 ;
}
static struct V_5 * F_2 ( int V_6 )
{
struct V_5 * V_7 = NULL ;
V_7 = F_3 ( sizeof( struct V_5 ) , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_9 = F_4 ( 0 , V_8 ) ;
V_7 -> V_10 = F_5 ( V_11 , V_8 ) ;
if ( ! V_7 -> V_9 || ! V_7 -> V_10 ) {
F_6 ( V_7 -> V_9 ) ;
F_7 ( V_7 -> V_10 ) ;
F_7 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
static void F_8 ( struct V_5 * V_7 )
{
if ( V_7 ) {
F_6 ( V_7 -> V_9 ) ;
F_7 ( V_7 -> V_10 ) ;
F_7 ( V_7 ) ;
}
}
static struct V_12 * F_9 ( void )
{
struct V_12 * V_13 = NULL ;
V_13 = F_3 ( sizeof( struct V_12 ) , V_14 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_9 = F_4 ( 0 , V_14 ) ;
V_13 -> V_10 = F_5 ( V_15 , V_14 ) ;
if ( ! V_13 -> V_9 || ! V_13 -> V_10 ) {
F_6 ( V_13 -> V_9 ) ;
F_7 ( V_13 -> V_10 ) ;
F_7 ( V_13 ) ;
return NULL ;
}
return V_13 ;
}
static void F_10 ( struct V_12 * V_13 )
{
if ( V_13 ) {
F_6 ( V_13 -> V_9 ) ;
F_7 ( V_13 -> V_10 ) ;
F_7 ( V_13 ) ;
}
}
static struct V_12 * F_11 ( struct V_16 * V_17 )
{
struct V_12 * V_13 ;
unsigned long V_18 ;
F_12 ( & V_17 -> V_19 , V_18 ) ;
if ( F_13 ( & V_17 -> V_20 ) ) {
F_14 ( & V_17 -> V_19 , V_18 ) ;
return NULL ;
}
V_13 = F_15 ( V_17 -> V_20 . V_21 , struct V_12 , V_22 ) ;
F_16 ( & V_13 -> V_22 ) ;
F_14 ( & V_17 -> V_19 , V_18 ) ;
return V_13 ;
}
static void F_17 ( struct V_16 * V_17 , struct V_12 * V_13 )
{
unsigned long V_18 ;
F_12 ( & V_17 -> V_19 , V_18 ) ;
F_18 ( & V_13 -> V_22 , & V_17 -> V_20 ) ;
F_14 ( & V_17 -> V_19 , V_18 ) ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_23 * V_23 = (struct V_23 * ) V_13 -> V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned short V_4 ;
int V_28 ;
int V_29 ;
T_2 V_30 = V_13 -> V_31 ;
int V_32 ;
int V_33 = V_34 ;
int V_6 = V_13 -> V_6 ;
while ( 1 ) {
V_25 = (struct V_24 * ) ( V_13 -> V_10 + V_30 ) ;
V_26 = F_20 ( V_25 -> V_26 ) ;
V_27 = F_20 ( V_25 -> V_27 ) ;
V_4 = F_21 ( V_25 -> V_4 ) ;
if ( V_26 != V_35 ) {
F_22 ( L_1 , V_26 ) ;
break;
}
V_28 = ( V_36 + V_27 ) % 4 ;
V_29 = V_28 ? ( 4 - V_28 ) : 0 ;
if ( V_6 - V_30 <
V_36 + V_27 + V_29 ) {
F_22 ( L_2 ,
V_27 , V_6 , V_4 ) ;
break;
}
V_32 = F_1 ( V_4 ) ;
if ( V_32 < 0 ) {
F_22 ( L_3 , V_32 ) ;
break;
}
V_33 = V_13 -> V_37 ( V_25 -> V_38 ,
V_27 ,
V_32 ,
V_23 -> V_39 ,
V_40
) ;
if ( V_33 == V_41 ) {
V_13 -> V_31 += V_30 ;
break;
}
V_30 += V_36 + V_27 + V_29 ;
if ( V_6 - V_30 <= V_36 + 2 ) {
V_33 = V_13 -> V_37 ( NULL ,
0 ,
V_32 ,
V_23 -> V_39 ,
V_42
) ;
break;
}
}
return V_33 ;
}
static void F_23 ( struct V_43 * V_44 )
{
struct V_23 * V_23 =
F_24 ( V_44 , struct V_23 , V_45 . V_44 ) ;
struct V_12 * V_13 ;
struct V_16 * V_17 = (struct V_16 * ) & V_23 -> V_17 ;
unsigned long V_18 ;
int V_33 = 0 ;
while ( 1 ) {
F_12 ( & V_17 -> V_46 , V_18 ) ;
if ( F_13 ( & V_17 -> V_47 ) ) {
F_14 ( & V_17 -> V_46 , V_18 ) ;
break;
}
V_13 = F_15 ( V_17 -> V_47 . V_48 , struct V_12 , V_47 ) ;
F_16 ( & V_13 -> V_47 ) ;
F_14 ( & V_17 -> V_46 , V_18 ) ;
V_33 = F_19 ( V_13 ) ;
if ( V_33 == V_41 )
F_22 ( L_4 ) ;
else
F_17 ( V_17 , V_13 ) ;
}
}
static void F_25 ( struct V_12 * V_13 , struct V_16 * V_17 )
{
unsigned long V_18 ;
struct V_12 * V_49 , * V_50 ;
F_12 ( & V_17 -> V_51 , V_18 ) ;
F_26 (r_remove, r_remove_next, &rx->rx_submit_list, rx_submit_list) {
if ( V_13 == V_49 )
F_16 ( & V_13 -> V_52 ) ;
}
F_14 ( & V_17 -> V_51 , V_18 ) ;
}
static void F_27 ( struct V_9 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_53 ;
struct V_23 * V_23 = (struct V_23 * ) V_13 -> V_23 ;
struct V_16 * V_17 = & V_23 -> V_17 ;
unsigned long V_18 ;
F_25 ( V_13 , V_17 ) ;
if ( V_9 -> V_54 ) {
if ( V_23 -> V_55 == V_56 )
F_22 ( L_5 ,
V_57 , V_9 -> V_54 ) ;
F_17 ( V_17 , V_13 ) ;
} else {
V_13 -> V_6 = V_13 -> V_9 -> V_58 ;
F_12 ( & V_17 -> V_46 , V_18 ) ;
F_18 ( & V_13 -> V_47 , & V_17 -> V_47 ) ;
F_28 ( V_59 , & V_23 -> V_45 . V_44 ) ;
F_14 ( & V_17 -> V_46 , V_18 ) ;
}
}
static int F_29 ( void * V_60 ,
int (* F_30)( void * V_38 , int V_6 , int V_61 , struct V_39 * V_39 , int V_62 )
)
{
struct V_23 * V_23 = V_60 ;
struct V_63 * V_64 = V_23 -> V_64 ;
struct V_12 * V_13 ;
struct V_16 * V_17 = & V_23 -> V_17 ;
unsigned long V_18 ;
int V_33 ;
if ( ! V_64 ) {
F_22 ( L_6 ) ;
return - V_65 ;
}
V_13 = F_11 ( V_17 ) ;
if ( ! V_13 ) {
F_22 ( L_7 ) ;
return - V_66 ;
}
V_13 -> V_31 = 0 ;
V_13 -> V_23 = ( void * ) V_23 ;
V_13 -> V_37 = F_30 ;
V_23 -> V_67 = F_30 ;
F_31 ( V_13 -> V_9 ,
V_64 ,
F_32 ( V_64 , 0x86 ) ,
V_13 -> V_10 ,
V_15 ,
F_27 ,
V_13 ) ;
F_12 ( & V_17 -> V_51 , V_18 ) ;
F_18 ( & V_13 -> V_52 , & V_17 -> V_52 ) ;
F_14 ( & V_17 -> V_51 , V_18 ) ;
V_33 = F_33 ( V_13 -> V_9 , V_14 ) ;
if ( V_33 ) {
F_12 ( & V_17 -> V_51 , V_18 ) ;
F_16 ( & V_13 -> V_52 ) ;
F_14 ( & V_17 -> V_51 , V_18 ) ;
F_17 ( V_17 , V_13 ) ;
F_22 ( L_8 , V_33 ) ;
}
F_34 ( V_64 ) ;
return V_33 ;
}
static void F_35 ( struct V_9 * V_9 )
{
struct V_5 * V_7 = V_9 -> V_53 ;
if ( V_9 -> V_54 == - V_68 ) {
F_36 ( L_9 ) ;
F_8 ( V_7 ) ;
return;
}
if ( V_7 -> V_37 )
V_7 -> V_37 ( V_7 -> V_69 ) ;
F_8 ( V_7 ) ;
}
static int F_37 ( void * V_60 , void * V_38 , int V_6 , int V_61 ,
void (* F_30)( void * V_38 ) , void * V_69 )
{
struct V_23 * V_23 = V_60 ;
struct V_63 * V_64 = V_23 -> V_64 ;
struct V_24 * V_25 ;
struct V_5 * V_7 = NULL ;
static T_2 V_70 = 1 ;
int V_28 ;
int V_29 ;
int V_71 ;
int V_33 ;
unsigned long V_18 ;
if ( V_23 -> V_55 == V_72 ) {
V_33 = F_38 ( V_23 -> V_73 ) ;
if ( ! V_33 )
F_39 ( V_23 -> V_73 ) ;
}
F_12 ( & V_23 -> V_74 , V_18 ) ;
V_28 = ( V_36 + V_6 ) % 4 ;
V_29 = V_28 ? ( 4 - V_28 ) : 0 ;
V_71 = V_6 + V_36 + V_29 ;
V_7 = F_2 ( V_71 ) ;
if ( ! V_7 ) {
F_22 ( L_10 ) ;
F_14 ( & V_23 -> V_74 , V_18 ) ;
return - V_66 ;
}
V_25 = (struct V_24 * ) V_7 -> V_10 ;
V_25 -> V_26 = F_40 ( V_35 ) ;
V_25 -> V_70 = F_40 ( V_70 ++ ) ;
V_25 -> V_27 = F_40 ( ( T_2 ) V_6 ) ;
V_25 -> V_4 = F_41 ( V_4 [ V_61 ] ) ;
memcpy ( V_7 -> V_10 + V_36 , V_38 , V_6 ) ;
memset ( V_7 -> V_10 + V_36 + V_6 , 0 , V_29 ) ;
V_7 -> V_6 = V_71 ;
V_7 -> V_37 = F_30 ;
V_7 -> V_69 = V_69 ;
F_31 ( V_7 -> V_9 ,
V_64 ,
F_42 ( V_64 , 5 ) ,
V_7 -> V_10 ,
V_71 ,
F_35 ,
V_7 ) ;
V_33 = F_33 ( V_7 -> V_9 , V_8 ) ;
F_14 ( & V_23 -> V_74 , V_18 ) ;
if ( V_33 )
F_22 ( L_11 , V_33 ) ;
F_34 ( V_64 ) ;
return V_33 ;
}
static int F_43 ( void * V_60 , int V_75 , int V_76 , void * V_10 , int V_6 )
{
struct V_23 * V_23 = V_60 ;
struct V_63 * V_64 = V_23 -> V_64 ;
int V_33 ;
V_33 = F_44 ( V_64 ,
F_45 ( V_64 , 0 ) ,
V_75 ,
V_77 ,
V_76 ,
2 ,
V_10 ,
V_6 ,
5000
) ;
if ( V_33 < 0 )
F_22 ( L_12 , V_33 ) ;
return V_33 < 0 ? V_33 : 0 ;
}
static void F_46 ( struct V_23 * V_23 )
{
struct V_16 * V_17 = & V_23 -> V_17 ;
struct V_12 * V_13 , * V_78 ;
unsigned long V_18 ;
F_47 ( & V_23 -> V_45 ) ;
F_12 ( & V_17 -> V_51 , V_18 ) ;
F_26 (r, r_next, &rx->rx_submit_list, rx_submit_list) {
F_14 ( & V_17 -> V_51 , V_18 ) ;
F_48 ( V_13 -> V_9 ) ;
F_12 ( & V_17 -> V_51 , V_18 ) ;
}
F_14 ( & V_17 -> V_51 , V_18 ) ;
F_12 ( & V_17 -> V_19 , V_18 ) ;
F_26 (r, r_next, &rx->rx_free_list, free_list) {
F_16 ( & V_13 -> V_22 ) ;
F_10 ( V_13 ) ;
}
F_14 ( & V_17 -> V_19 , V_18 ) ;
F_12 ( & V_17 -> V_46 , V_18 ) ;
F_26 (r, r_next, &rx->to_host_list, to_host_list) {
if ( V_13 -> V_23 == ( void * ) V_23 ) {
F_16 ( & V_13 -> V_47 ) ;
F_10 ( V_13 ) ;
}
}
F_14 ( & V_17 -> V_46 , V_18 ) ;
}
static int F_49 ( struct V_23 * V_23 )
{
struct V_12 * V_13 ;
struct V_16 * V_17 = & V_23 -> V_17 ;
int V_33 = 0 ;
int V_2 ;
F_50 ( & V_23 -> V_74 ) ;
F_51 ( & V_17 -> V_47 ) ;
F_51 ( & V_17 -> V_52 ) ;
F_51 ( & V_17 -> V_20 ) ;
F_50 ( & V_17 -> V_46 ) ;
F_50 ( & V_17 -> V_51 ) ;
F_50 ( & V_17 -> V_19 ) ;
for ( V_2 = 0 ; V_2 < V_79 * 2 ; V_2 ++ ) {
V_13 = F_9 () ;
if ( V_13 == NULL ) {
V_33 = - V_66 ;
break;
}
F_52 ( & V_13 -> V_22 , & V_17 -> V_20 ) ;
}
F_53 ( & V_23 -> V_45 , F_23 ) ;
return V_33 ;
}
static int F_54 ( struct V_80 * V_73 , const struct V_81 * V_82 )
{
struct V_23 * V_23 ;
struct V_39 * V_39 ;
T_1 V_83 , V_84 ;
int V_85 ;
int V_33 ;
int V_2 ;
struct V_63 * V_64 = F_55 ( V_73 ) ;
V_85 = V_73 -> V_86 -> V_87 . V_85 ;
V_83 = F_21 ( V_64 -> V_88 . V_83 ) ;
V_84 = F_21 ( V_64 -> V_88 . V_84 ) ;
F_36 ( L_13 , V_83 , V_84 ) ;
if ( V_85 != 2 )
return - V_65 ;
V_23 = F_3 ( sizeof( struct V_23 ) , V_14 ) ;
if ( ! V_23 )
return - V_66 ;
V_39 = F_3 ( sizeof( struct V_39 ) , V_14 ) ;
if ( ! V_39 ) {
V_33 = - V_66 ;
goto V_89;
}
V_23 -> V_64 = V_64 ;
V_23 -> V_90 = V_73 ;
V_33 = F_49 ( V_23 ) ;
if ( V_33 )
goto V_91;
V_39 -> V_60 = ( void * ) V_23 ;
V_39 -> V_92 = F_37 ;
V_39 -> V_93 = F_29 ;
V_39 -> V_94 = F_43 ;
V_33 = F_56 ( V_39 , & V_73 -> V_95 ) ;
if ( V_33 )
goto V_96;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_23 -> V_39 = V_39 ;
V_23 -> V_73 = V_73 ;
V_23 -> V_55 = V_56 ;
F_57 ( V_64 ) ;
F_58 ( V_73 , V_39 ) ;
return 0 ;
V_96:
F_59 ( V_39 ) ;
V_91:
F_46 ( V_23 ) ;
F_7 ( V_39 ) ;
V_89:
F_7 ( V_23 ) ;
return V_33 ;
}
static void F_60 ( struct V_80 * V_73 )
{
struct V_39 * V_39 ;
struct V_23 * V_23 ;
struct V_63 * V_64 = F_55 ( V_73 ) ;
V_39 = F_61 ( V_73 ) ;
V_23 = V_39 -> V_60 ;
F_46 ( V_23 ) ;
F_59 ( V_39 ) ;
F_7 ( V_23 ) ;
F_7 ( V_39 ) ;
F_62 ( V_64 ) ;
}
static int F_63 ( struct V_80 * V_73 , T_3 V_97 )
{
struct V_39 * V_39 ;
struct V_23 * V_23 ;
struct V_16 * V_17 ;
struct V_12 * V_13 , * V_78 ;
unsigned long V_18 ;
V_39 = F_61 ( V_73 ) ;
V_23 = V_39 -> V_60 ;
V_17 = & V_23 -> V_17 ;
if ( V_23 -> V_55 != V_56 ) {
F_22 ( L_14 ) ;
return - 1 ;
}
V_23 -> V_55 = V_72 ;
F_12 ( & V_17 -> V_51 , V_18 ) ;
F_26 (r, r_next, &rx->rx_submit_list, rx_submit_list) {
F_14 ( & V_17 -> V_51 , V_18 ) ;
F_48 ( V_13 -> V_9 ) ;
F_12 ( & V_17 -> V_51 , V_18 ) ;
}
F_14 ( & V_17 -> V_51 , V_18 ) ;
return 0 ;
}
static int F_64 ( struct V_80 * V_73 )
{
struct V_39 * V_39 ;
struct V_23 * V_23 ;
T_4 V_2 ;
V_39 = F_61 ( V_73 ) ;
V_23 = V_39 -> V_60 ;
if ( V_23 -> V_55 != V_72 ) {
F_22 ( L_15 ) ;
return - 1 ;
}
V_23 -> V_55 = V_56 ;
for ( V_2 = 0 ; V_2 < V_79 ; V_2 ++ )
F_29 ( V_23 , V_23 -> V_67 ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
V_59 = F_66 ( L_16 ) ;
if ( V_59 == NULL ) {
F_22 ( L_17 ) ;
return - 1 ;
}
F_67 () ;
return F_68 ( & V_98 ) ;
}
static void T_6 F_69 ( void )
{
F_70 () ;
if ( V_59 ) {
F_71 ( V_59 ) ;
F_72 ( V_59 ) ;
}
F_73 ( & V_98 ) ;
}
