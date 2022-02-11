int F_1 ( T_1 V_1 )
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
V_13 = F_3 ( sizeof( struct V_12 ) , V_8 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_9 = F_4 ( 0 , V_8 ) ;
V_13 -> V_10 = F_5 ( V_14 , V_8 ) ;
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
static struct V_12 * F_11 ( struct V_15 * V_16 )
{
struct V_12 * V_13 ;
unsigned long V_17 ;
F_12 ( & V_16 -> V_18 , V_17 ) ;
if ( F_13 ( & V_16 -> V_19 ) ) {
F_14 ( & V_16 -> V_18 , V_17 ) ;
return NULL ;
}
V_13 = F_15 ( V_16 -> V_19 . V_20 , struct V_12 , V_21 ) ;
F_16 ( & V_13 -> V_21 ) ;
F_14 ( & V_16 -> V_18 , V_17 ) ;
return V_13 ;
}
static void F_17 ( struct V_15 * V_16 , struct V_12 * V_13 )
{
unsigned long V_17 ;
F_12 ( & V_16 -> V_18 , V_17 ) ;
F_18 ( & V_13 -> V_21 , & V_16 -> V_19 ) ;
F_14 ( & V_16 -> V_18 , V_17 ) ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_22 * V_22 = (struct V_22 * ) V_13 -> V_22 ;
struct V_23 * V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned short V_4 ;
int V_27 ;
int V_28 ;
T_2 V_29 = V_13 -> V_30 ;
int V_31 ;
int V_32 = V_33 ;
int V_6 = V_13 -> V_6 ;
while ( 1 ) {
V_24 = (struct V_23 * ) ( V_13 -> V_10 + V_29 ) ;
V_25 = F_20 ( V_24 -> V_25 ) ;
V_26 = F_20 ( V_24 -> V_26 ) ;
V_4 = F_21 ( V_24 -> V_4 ) ;
if ( V_25 != V_34 ) {
F_22 ( L_1 , V_25 ) ;
break;
}
V_27 = ( V_35 + V_26 ) % 4 ;
V_28 = V_27 ? ( 4 - V_27 ) : 0 ;
if ( V_6 - V_29 <
V_35 + V_26 + V_28 ) {
F_22 ( L_2 ,
V_26 , V_6 , V_4 ) ;
break;
}
V_31 = F_1 ( V_4 ) ;
if ( V_31 < 0 ) {
F_22 ( L_3 , V_31 ) ;
break;
}
V_32 = V_13 -> V_36 ( V_24 -> V_37 ,
V_26 ,
V_31 ,
V_22 -> V_38 ,
V_39
) ;
if ( V_32 == V_40 ) {
V_13 -> V_30 += V_29 ;
break;
}
V_29 += V_35 + V_26 + V_28 ;
if ( V_6 - V_29 <= V_35 + 2 ) {
V_32 = V_13 -> V_36 ( NULL ,
0 ,
V_31 ,
V_22 -> V_38 ,
V_41
) ;
break;
}
}
return V_32 ;
}
static void F_23 ( struct V_42 * V_43 )
{
struct V_22 * V_22 =
F_24 ( V_43 , struct V_22 , V_44 . V_43 ) ;
struct V_12 * V_13 ;
struct V_15 * V_16 = (struct V_15 * ) & V_22 -> V_16 ;
unsigned long V_17 ;
int V_32 = 0 ;
while ( 1 ) {
F_12 ( & V_16 -> V_45 , V_17 ) ;
if ( F_13 ( & V_16 -> V_46 ) ) {
F_14 ( & V_16 -> V_45 , V_17 ) ;
break;
}
V_13 = F_15 ( V_16 -> V_46 . V_47 , struct V_12 , V_46 ) ;
F_16 ( & V_13 -> V_46 ) ;
F_14 ( & V_16 -> V_45 , V_17 ) ;
V_32 = F_19 ( V_13 ) ;
if ( V_32 == V_40 )
F_22 ( L_4 ) ;
else
F_17 ( V_16 , V_13 ) ;
}
}
static void F_25 ( struct V_12 * V_13 , struct V_15 * V_16 )
{
unsigned long V_17 ;
struct V_12 * V_48 , * V_49 ;
F_12 ( & V_16 -> V_50 , V_17 ) ;
F_26 (r_remove, r_remove_next, &rx->rx_submit_list, rx_submit_list) {
if ( V_13 == V_48 )
F_16 ( & V_13 -> V_51 ) ;
}
F_14 ( & V_16 -> V_50 , V_17 ) ;
}
static void F_27 ( struct V_9 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_52 ;
struct V_22 * V_22 = (struct V_22 * ) V_13 -> V_22 ;
struct V_15 * V_16 = & V_22 -> V_16 ;
unsigned long V_17 ;
F_25 ( V_13 , V_16 ) ;
if ( V_9 -> V_53 ) {
if ( V_22 -> V_54 == V_55 )
F_22 ( L_5 ,
V_56 , V_9 -> V_53 ) ;
F_17 ( V_16 , V_13 ) ;
} else {
V_13 -> V_6 = V_13 -> V_9 -> V_57 ;
F_12 ( & V_16 -> V_45 , V_17 ) ;
F_18 ( & V_13 -> V_46 , & V_16 -> V_46 ) ;
F_28 ( V_58 , & V_22 -> V_44 . V_43 ) ;
F_14 ( & V_16 -> V_45 , V_17 ) ;
}
}
static int F_29 ( void * V_59 ,
int (* F_30)( void * V_37 , int V_6 , int V_60 , struct V_38 * V_38 , int V_61 )
)
{
struct V_22 * V_22 = V_59 ;
struct V_62 * V_63 = V_22 -> V_63 ;
struct V_12 * V_13 ;
struct V_15 * V_16 = & V_22 -> V_16 ;
unsigned long V_17 ;
int V_32 ;
if ( ! V_63 ) {
F_22 ( L_6 ) ;
return - V_64 ;
}
V_13 = F_11 ( V_16 ) ;
if ( ! V_13 ) {
F_22 ( L_7 ) ;
return - V_65 ;
}
V_13 -> V_30 = 0 ;
V_13 -> V_22 = ( void * ) V_22 ;
V_13 -> V_36 = F_30 ;
V_22 -> V_66 = F_30 ;
F_31 ( V_13 -> V_9 ,
V_63 ,
F_32 ( V_63 , 0x86 ) ,
V_13 -> V_10 ,
V_14 ,
F_27 ,
V_13 ) ;
F_12 ( & V_16 -> V_50 , V_17 ) ;
F_18 ( & V_13 -> V_51 , & V_16 -> V_51 ) ;
F_14 ( & V_16 -> V_50 , V_17 ) ;
V_32 = F_33 ( V_13 -> V_9 , V_67 ) ;
if ( V_32 ) {
F_12 ( & V_16 -> V_50 , V_17 ) ;
F_16 ( & V_13 -> V_51 ) ;
F_14 ( & V_16 -> V_50 , V_17 ) ;
F_17 ( V_16 , V_13 ) ;
F_22 ( L_8 , V_32 ) ;
}
F_34 ( V_63 ) ;
return V_32 ;
}
static void F_35 ( struct V_9 * V_9 )
{
struct V_5 * V_7 = V_9 -> V_52 ;
if ( V_9 -> V_53 == - V_68 ) {
F_36 ( L_9 ) ;
F_8 ( V_7 ) ;
return;
}
if ( V_7 -> V_36 )
V_7 -> V_36 ( V_7 -> V_69 ) ;
F_8 ( V_7 ) ;
}
static int F_37 ( void * V_59 , void * V_37 , int V_6 , int V_60 ,
void (* F_30)( void * V_37 ) , void * V_69 )
{
struct V_22 * V_22 = V_59 ;
struct V_62 * V_63 = V_22 -> V_63 ;
struct V_23 * V_24 ;
struct V_5 * V_7 = NULL ;
static T_2 V_70 = 1 ;
int V_27 ;
int V_28 ;
int V_71 ;
int V_32 ;
unsigned long V_17 ;
if ( V_22 -> V_54 == V_72 ) {
V_32 = F_38 ( V_22 -> V_73 ) ;
if ( ! V_32 )
F_39 ( V_22 -> V_73 ) ;
}
F_12 ( & V_22 -> V_74 , V_17 ) ;
V_27 = ( V_35 + V_6 ) % 4 ;
V_28 = V_27 ? ( 4 - V_27 ) : 0 ;
V_71 = V_6 + V_35 + V_28 ;
V_7 = F_2 ( V_71 ) ;
if ( ! V_7 ) {
F_22 ( L_10 ) ;
F_14 ( & V_22 -> V_74 , V_17 ) ;
return - V_65 ;
}
V_24 = (struct V_23 * ) V_7 -> V_10 ;
V_24 -> V_25 = F_40 ( V_34 ) ;
V_24 -> V_70 = F_40 ( V_70 ++ ) ;
V_24 -> V_26 = F_40 ( ( T_2 ) V_6 ) ;
V_24 -> V_4 = F_41 ( V_4 [ V_60 ] ) ;
memcpy ( V_7 -> V_10 + V_35 , V_37 , V_6 ) ;
memset ( V_7 -> V_10 + V_35 + V_6 , 0 , V_28 ) ;
V_7 -> V_6 = V_71 ;
V_7 -> V_36 = F_30 ;
V_7 -> V_69 = V_69 ;
F_31 ( V_7 -> V_9 ,
V_63 ,
F_42 ( V_63 , 5 ) ,
V_7 -> V_10 ,
V_71 ,
F_35 ,
V_7 ) ;
V_32 = F_33 ( V_7 -> V_9 , V_8 ) ;
F_14 ( & V_22 -> V_74 , V_17 ) ;
if ( V_32 )
F_22 ( L_11 , V_32 ) ;
F_34 ( V_63 ) ;
return V_32 ;
}
static int F_43 ( void * V_59 , int V_75 , int V_76 , void * V_10 , int V_6 )
{
struct V_22 * V_22 = V_59 ;
struct V_62 * V_63 = V_22 -> V_63 ;
int V_32 ;
V_32 = F_44 ( V_63 ,
F_45 ( V_63 , 0 ) ,
V_75 ,
V_77 ,
V_76 ,
2 ,
V_10 ,
V_6 ,
5000
) ;
if ( V_32 < 0 )
F_22 ( L_12 , V_32 ) ;
return V_32 < 0 ? V_32 : 0 ;
}
static void F_46 ( struct V_22 * V_22 )
{
struct V_15 * V_16 = & V_22 -> V_16 ;
struct V_12 * V_13 , * V_78 ;
unsigned long V_17 ;
F_47 ( & V_22 -> V_44 ) ;
F_12 ( & V_16 -> V_50 , V_17 ) ;
F_26 (r, r_next, &rx->rx_submit_list, rx_submit_list) {
F_14 ( & V_16 -> V_50 , V_17 ) ;
F_48 ( V_13 -> V_9 ) ;
F_12 ( & V_16 -> V_50 , V_17 ) ;
}
F_14 ( & V_16 -> V_50 , V_17 ) ;
F_12 ( & V_16 -> V_18 , V_17 ) ;
F_26 (r, r_next, &rx->rx_free_list, free_list) {
F_16 ( & V_13 -> V_21 ) ;
F_10 ( V_13 ) ;
}
F_14 ( & V_16 -> V_18 , V_17 ) ;
F_12 ( & V_16 -> V_45 , V_17 ) ;
F_26 (r, r_next, &rx->to_host_list, to_host_list) {
if ( V_13 -> V_22 == ( void * ) V_22 ) {
F_16 ( & V_13 -> V_46 ) ;
F_10 ( V_13 ) ;
}
}
F_14 ( & V_16 -> V_45 , V_17 ) ;
}
static int F_49 ( struct V_22 * V_22 )
{
struct V_12 * V_13 ;
struct V_15 * V_16 = & V_22 -> V_16 ;
int V_32 = 0 ;
int V_2 ;
F_50 ( & V_22 -> V_74 ) ;
F_51 ( & V_16 -> V_46 ) ;
F_51 ( & V_16 -> V_51 ) ;
F_51 ( & V_16 -> V_19 ) ;
F_50 ( & V_16 -> V_45 ) ;
F_50 ( & V_16 -> V_50 ) ;
F_50 ( & V_16 -> V_18 ) ;
for ( V_2 = 0 ; V_2 < V_79 * 2 ; V_2 ++ ) {
V_13 = F_9 () ;
if ( V_13 == NULL ) {
V_32 = - V_65 ;
break;
}
F_52 ( & V_13 -> V_21 , & V_16 -> V_19 ) ;
}
F_53 ( & V_22 -> V_44 , F_23 ) ;
return V_32 ;
}
static int F_54 ( struct V_80 * V_73 , const struct V_81 * V_82 )
{
struct V_22 * V_22 ;
struct V_38 * V_38 ;
T_1 V_83 , V_84 ;
int V_85 ;
int V_32 ;
int V_2 ;
struct V_62 * V_63 = F_55 ( V_73 ) ;
V_85 = V_73 -> V_86 -> V_87 . V_85 ;
V_83 = F_21 ( V_63 -> V_88 . V_83 ) ;
V_84 = F_21 ( V_63 -> V_88 . V_84 ) ;
F_36 ( L_13 , V_83 , V_84 ) ;
if ( V_85 != 2 )
return - V_64 ;
V_22 = F_3 ( sizeof( struct V_22 ) , V_67 ) ;
if ( ! V_22 )
return - V_65 ;
V_38 = F_3 ( sizeof( struct V_38 ) , V_67 ) ;
if ( ! V_38 ) {
V_32 = - V_65 ;
goto V_89;
}
V_22 -> V_63 = V_63 ;
V_22 -> V_90 = V_73 ;
V_32 = F_49 ( V_22 ) ;
if ( V_32 )
goto V_91;
V_38 -> V_59 = ( void * ) V_22 ;
V_38 -> V_92 = F_37 ;
V_38 -> V_93 = F_29 ;
V_38 -> V_94 = F_43 ;
V_32 = F_56 ( V_38 , & V_73 -> V_95 ) ;
if ( V_32 )
goto V_96;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_22 -> V_38 = V_38 ;
V_22 -> V_73 = V_73 ;
V_22 -> V_54 = V_55 ;
F_57 ( V_63 ) ;
F_58 ( V_73 , V_38 ) ;
return 0 ;
V_96:
F_59 ( V_38 ) ;
F_46 ( V_22 ) ;
V_91:
F_7 ( V_38 ) ;
V_89:
F_7 ( V_22 ) ;
return V_32 ;
}
static void F_60 ( struct V_80 * V_73 )
{
struct V_38 * V_38 ;
struct V_22 * V_22 ;
struct V_62 * V_63 = F_55 ( V_73 ) ;
V_38 = F_61 ( V_73 ) ;
V_22 = V_38 -> V_59 ;
F_46 ( V_22 ) ;
F_59 ( V_38 ) ;
F_7 ( V_22 ) ;
F_7 ( V_38 ) ;
F_62 ( V_63 ) ;
}
static int F_63 ( struct V_80 * V_73 , T_3 V_97 )
{
struct V_38 * V_38 ;
struct V_22 * V_22 ;
struct V_15 * V_16 ;
struct V_12 * V_13 , * V_78 ;
unsigned long V_17 ;
V_38 = F_61 ( V_73 ) ;
V_22 = V_38 -> V_59 ;
V_16 = & V_22 -> V_16 ;
if ( V_22 -> V_54 != V_55 ) {
F_22 ( L_14 ) ;
return - 1 ;
}
V_22 -> V_54 = V_72 ;
F_12 ( & V_16 -> V_50 , V_17 ) ;
F_26 (r, r_next, &rx->rx_submit_list, rx_submit_list) {
F_14 ( & V_16 -> V_50 , V_17 ) ;
F_48 ( V_13 -> V_9 ) ;
F_12 ( & V_16 -> V_50 , V_17 ) ;
}
F_14 ( & V_16 -> V_50 , V_17 ) ;
return 0 ;
}
static int F_64 ( struct V_80 * V_73 )
{
struct V_38 * V_38 ;
struct V_22 * V_22 ;
T_4 V_2 ;
V_38 = F_61 ( V_73 ) ;
V_22 = V_38 -> V_59 ;
if ( V_22 -> V_54 != V_72 ) {
F_22 ( L_15 ) ;
return - 1 ;
}
V_22 -> V_54 = V_55 ;
for ( V_2 = 0 ; V_2 < V_79 ; V_2 ++ )
F_29 ( V_22 , V_22 -> V_66 ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
V_58 = F_66 ( L_16 ) ;
if ( V_58 == NULL ) {
F_22 ( L_17 ) ;
return - 1 ;
}
F_67 () ;
return F_68 ( & V_98 ) ;
}
static void T_6 F_69 ( void )
{
F_70 () ;
if ( V_58 ) {
F_71 ( V_58 ) ;
F_72 ( V_58 ) ;
}
F_73 ( & V_98 ) ;
}
