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
V_7 = F_3 ( sizeof( * V_7 ) , V_8 ) ;
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
V_13 = F_3 ( sizeof( * V_13 ) , V_14 ) ;
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
struct V_23 * V_23 = V_13 -> V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned short V_4 ;
int V_28 ;
T_2 V_29 = V_13 -> V_30 ;
int V_31 ;
int V_32 = V_33 ;
int V_6 = V_13 -> V_6 ;
while ( 1 ) {
V_25 = (struct V_24 * ) ( V_13 -> V_10 +
V_29 ) ;
V_26 = F_20 ( V_25 -> V_26 ) ;
V_27 = F_20 ( V_25 -> V_27 ) ;
V_4 = F_21 ( V_25 -> V_4 ) ;
if ( V_26 != V_34 ) {
F_22 ( L_1 , V_26 ) ;
break;
}
V_28 = F_23 ( V_35 + V_27 , 4 ) ;
if ( V_6 - V_29 <
V_28 ) {
F_22 ( L_2 ,
V_27 , V_6 , V_4 ) ;
break;
}
V_31 = F_1 ( V_4 ) ;
if ( V_31 < 0 ) {
F_22 ( L_3 , V_31 ) ;
break;
}
V_32 = V_13 -> V_36 ( V_25 -> V_37 ,
V_27 ,
V_31 ,
V_23 -> V_38 ,
V_39
) ;
if ( V_32 == V_40 ) {
V_13 -> V_30 += V_29 ;
break;
}
V_29 += V_28 ;
if ( V_6 - V_29 <= V_35 + 2 ) {
V_32 = V_13 -> V_36 ( NULL ,
0 ,
V_31 ,
V_23 -> V_38 ,
V_41
) ;
break;
}
}
return V_32 ;
}
static void F_24 ( struct V_42 * V_43 )
{
struct V_23 * V_23 =
F_25 ( V_43 , struct V_23 , V_44 . V_43 ) ;
struct V_12 * V_13 ;
struct V_16 * V_17 = & V_23 -> V_17 ;
unsigned long V_18 ;
int V_32 = 0 ;
while ( 1 ) {
F_12 ( & V_17 -> V_45 , V_18 ) ;
if ( F_13 ( & V_17 -> V_46 ) ) {
F_14 ( & V_17 -> V_45 , V_18 ) ;
break;
}
V_13 = F_15 ( V_17 -> V_46 . V_47 , struct V_12 ,
V_46 ) ;
F_16 ( & V_13 -> V_46 ) ;
F_14 ( & V_17 -> V_45 , V_18 ) ;
V_32 = F_19 ( V_13 ) ;
if ( V_32 == V_40 )
F_22 ( L_4 ) ;
else
F_17 ( V_17 , V_13 ) ;
}
}
static void F_26 ( struct V_12 * V_13 , struct V_16 * V_17 )
{
unsigned long V_18 ;
struct V_12 * V_48 , * V_49 ;
F_12 ( & V_17 -> V_50 , V_18 ) ;
F_27 (r_remove, r_remove_next, &rx->rx_submit_list,
rx_submit_list) {
if ( V_13 == V_48 )
F_16 ( & V_13 -> V_51 ) ;
}
F_14 ( & V_17 -> V_50 , V_18 ) ;
}
static void F_28 ( struct V_9 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_52 ;
struct V_23 * V_23 = V_13 -> V_23 ;
struct V_16 * V_17 = & V_23 -> V_17 ;
unsigned long V_18 ;
F_26 ( V_13 , V_17 ) ;
if ( V_9 -> V_53 ) {
if ( V_23 -> V_54 == V_55 )
F_29 ( & V_9 -> V_56 -> V_56 , L_5 ,
V_57 , V_9 -> V_53 ) ;
F_17 ( V_17 , V_13 ) ;
} else {
V_13 -> V_6 = V_13 -> V_9 -> V_58 ;
F_12 ( & V_17 -> V_45 , V_18 ) ;
F_18 ( & V_13 -> V_46 , & V_17 -> V_46 ) ;
F_30 ( & V_23 -> V_44 . V_43 ) ;
F_14 ( & V_17 -> V_45 , V_18 ) ;
}
}
static int F_31 ( void * V_59 ,
int (* F_32)( void * V_37 , int V_6 , int V_60 ,
struct V_38 * V_38 , int V_61 ) )
{
struct V_23 * V_23 = V_59 ;
struct V_62 * V_63 = V_23 -> V_63 ;
struct V_12 * V_13 ;
struct V_16 * V_17 = & V_23 -> V_17 ;
unsigned long V_18 ;
int V_32 ;
if ( ! V_63 ) {
F_22 ( L_6 ) ;
return - V_64 ;
}
V_13 = F_11 ( V_17 ) ;
if ( ! V_13 ) {
F_22 ( L_7 ) ;
return - V_65 ;
}
V_13 -> V_30 = 0 ;
V_13 -> V_23 = ( void * ) V_23 ;
V_13 -> V_36 = F_32 ;
V_23 -> V_66 = F_32 ;
F_33 ( V_13 -> V_9 ,
V_63 ,
F_34 ( V_63 , 0x86 ) ,
V_13 -> V_10 ,
V_15 ,
F_28 ,
V_13 ) ;
F_12 ( & V_17 -> V_50 , V_18 ) ;
F_18 ( & V_13 -> V_51 , & V_17 -> V_51 ) ;
F_14 ( & V_17 -> V_50 , V_18 ) ;
V_32 = F_35 ( V_13 -> V_9 , V_14 ) ;
if ( V_32 ) {
F_12 ( & V_17 -> V_50 , V_18 ) ;
F_16 ( & V_13 -> V_51 ) ;
F_14 ( & V_17 -> V_50 , V_18 ) ;
F_17 ( V_17 , V_13 ) ;
F_22 ( L_8 , V_32 ) ;
}
F_36 ( V_63 ) ;
return V_32 ;
}
static void F_37 ( struct V_9 * V_9 )
{
struct V_5 * V_7 = V_9 -> V_52 ;
if ( V_9 -> V_53 == - V_67 ) {
F_38 ( & V_9 -> V_56 -> V_56 , L_9 ) ;
F_8 ( V_7 ) ;
return;
}
if ( V_7 -> V_36 )
V_7 -> V_36 ( V_7 -> V_68 ) ;
F_8 ( V_7 ) ;
}
static int F_39 ( void * V_59 , void * V_37 , int V_6 , int V_60 ,
void (* F_32)( void * V_37 ) , void * V_68 )
{
struct V_23 * V_23 = V_59 ;
struct V_62 * V_63 = V_23 -> V_63 ;
struct V_24 * V_25 ;
struct V_5 * V_7 = NULL ;
static T_2 V_69 = 1 ;
int V_28 ;
int V_32 ;
unsigned long V_18 ;
if ( V_23 -> V_54 == V_70 ) {
V_32 = F_40 ( V_23 -> V_71 ) ;
if ( ! V_32 )
F_41 ( V_23 -> V_71 ) ;
}
F_12 ( & V_23 -> V_72 , V_18 ) ;
V_28 = F_23 ( V_35 + V_6 , 4 ) ;
V_7 = F_2 ( V_28 ) ;
if ( ! V_7 ) {
F_22 ( L_10 ) ;
F_14 ( & V_23 -> V_72 , V_18 ) ;
return - V_65 ;
}
V_25 = (struct V_24 * ) V_7 -> V_10 ;
V_25 -> V_26 = F_42 ( V_34 ) ;
V_25 -> V_69 = F_42 ( V_69 ++ ) ;
V_25 -> V_27 = F_42 ( ( T_2 ) V_6 ) ;
V_25 -> V_4 = F_43 ( V_4 [ V_60 ] ) ;
memcpy ( V_7 -> V_10 + V_35 , V_37 , V_6 ) ;
memset ( V_7 -> V_10 + V_35 + V_6 , 0 , V_28 - V_35 -
V_6 ) ;
V_7 -> V_6 = V_28 ;
V_7 -> V_36 = F_32 ;
V_7 -> V_68 = V_68 ;
F_33 ( V_7 -> V_9 ,
V_63 ,
F_44 ( V_63 , 5 ) ,
V_7 -> V_10 ,
V_28 ,
F_37 ,
V_7 ) ;
V_32 = F_35 ( V_7 -> V_9 , V_8 ) ;
F_14 ( & V_23 -> V_72 , V_18 ) ;
if ( V_32 )
F_22 ( L_11 , V_32 ) ;
F_36 ( V_63 ) ;
return V_32 ;
}
static int F_45 ( void * V_59 , int V_73 , int V_74 ,
void * V_10 , int V_6 )
{
struct V_23 * V_23 = V_59 ;
struct V_62 * V_63 = V_23 -> V_63 ;
int V_32 ;
V_32 = F_46 ( V_63 ,
F_47 ( V_63 , 0 ) ,
V_73 ,
V_75 ,
V_74 ,
2 ,
V_10 ,
V_6 ,
5000
) ;
if ( V_32 < 0 )
F_22 ( L_12 , V_32 ) ;
return F_48 ( V_32 , 0 ) ;
}
static void F_49 ( struct V_23 * V_23 )
{
struct V_16 * V_17 = & V_23 -> V_17 ;
struct V_12 * V_13 , * V_76 ;
unsigned long V_18 ;
F_50 ( & V_23 -> V_44 ) ;
F_12 ( & V_17 -> V_50 , V_18 ) ;
F_27 (r, r_next, &rx->rx_submit_list,
rx_submit_list) {
F_14 ( & V_17 -> V_50 , V_18 ) ;
F_51 ( V_13 -> V_9 ) ;
F_12 ( & V_17 -> V_50 , V_18 ) ;
}
F_14 ( & V_17 -> V_50 , V_18 ) ;
F_12 ( & V_17 -> V_19 , V_18 ) ;
F_27 (r, r_next, &rx->rx_free_list, free_list) {
F_16 ( & V_13 -> V_22 ) ;
F_10 ( V_13 ) ;
}
F_14 ( & V_17 -> V_19 , V_18 ) ;
F_12 ( & V_17 -> V_45 , V_18 ) ;
F_27 (r, r_next, &rx->to_host_list, to_host_list) {
if ( V_13 -> V_23 == ( void * ) V_23 ) {
F_16 ( & V_13 -> V_46 ) ;
F_10 ( V_13 ) ;
}
}
F_14 ( & V_17 -> V_45 , V_18 ) ;
}
static int F_52 ( struct V_23 * V_23 )
{
struct V_12 * V_13 ;
struct V_16 * V_17 = & V_23 -> V_17 ;
int V_32 = 0 ;
int V_2 ;
F_53 ( & V_23 -> V_72 ) ;
F_54 ( & V_17 -> V_46 ) ;
F_54 ( & V_17 -> V_51 ) ;
F_54 ( & V_17 -> V_20 ) ;
F_53 ( & V_17 -> V_45 ) ;
F_53 ( & V_17 -> V_50 ) ;
F_53 ( & V_17 -> V_19 ) ;
for ( V_2 = 0 ; V_2 < V_77 * 2 ; V_2 ++ ) {
V_13 = F_9 () ;
if ( ! V_13 ) {
V_32 = - V_65 ;
break;
}
F_55 ( & V_13 -> V_22 , & V_17 -> V_20 ) ;
}
F_56 ( & V_23 -> V_44 , F_24 ) ;
return V_32 ;
}
static int F_57 ( struct V_78 * V_71 ,
const struct V_79 * V_80 )
{
struct V_23 * V_23 ;
struct V_38 * V_38 ;
T_1 V_81 , V_82 ;
int V_83 ;
int V_32 ;
int V_2 ;
struct V_62 * V_63 = F_58 ( V_71 ) ;
V_83 = V_71 -> V_84 -> V_85 . V_83 ;
V_81 = F_21 ( V_63 -> V_86 . V_81 ) ;
V_82 = F_21 ( V_63 -> V_86 . V_82 ) ;
F_59 ( L_13 , V_81 , V_82 ) ;
if ( V_83 != 2 )
return - V_64 ;
V_23 = F_3 ( sizeof( * V_23 ) , V_14 ) ;
if ( ! V_23 )
return - V_65 ;
V_38 = F_3 ( sizeof( * V_38 ) , V_14 ) ;
if ( ! V_38 ) {
V_32 = - V_65 ;
goto V_87;
}
V_23 -> V_63 = V_63 ;
V_23 -> V_88 = V_71 ;
V_32 = F_52 ( V_23 ) ;
if ( V_32 )
goto V_89;
V_38 -> V_59 = ( void * ) V_23 ;
V_38 -> V_90 = F_39 ;
V_38 -> V_91 = F_31 ;
V_38 -> V_92 = F_45 ;
V_32 = F_60 ( V_38 , & V_71 -> V_56 ) ;
if ( V_32 )
goto V_93;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_23 -> V_38 = V_38 ;
V_23 -> V_71 = V_71 ;
V_23 -> V_54 = V_55 ;
F_61 ( V_63 ) ;
F_62 ( V_71 , V_38 ) ;
return 0 ;
V_93:
F_63 ( V_38 ) ;
V_89:
F_49 ( V_23 ) ;
F_7 ( V_38 ) ;
V_87:
F_7 ( V_23 ) ;
return V_32 ;
}
static void F_64 ( struct V_78 * V_71 )
{
struct V_38 * V_38 ;
struct V_23 * V_23 ;
struct V_62 * V_63 = F_58 ( V_71 ) ;
V_38 = F_65 ( V_71 ) ;
V_23 = V_38 -> V_59 ;
F_49 ( V_23 ) ;
F_63 ( V_38 ) ;
F_7 ( V_23 ) ;
F_7 ( V_38 ) ;
F_66 ( V_63 ) ;
}
static int F_67 ( struct V_78 * V_71 , T_3 V_94 )
{
struct V_38 * V_38 ;
struct V_23 * V_23 ;
struct V_16 * V_17 ;
struct V_12 * V_13 , * V_76 ;
unsigned long V_18 ;
V_38 = F_65 ( V_71 ) ;
V_23 = V_38 -> V_59 ;
V_17 = & V_23 -> V_17 ;
F_68 ( & V_23 -> V_44 . V_43 ) ;
if ( V_23 -> V_54 != V_55 ) {
F_29 ( V_71 -> V_95 , L_14 ) ;
return - 1 ;
}
V_23 -> V_54 = V_70 ;
F_12 ( & V_17 -> V_50 , V_18 ) ;
F_27 (r, r_next, &rx->rx_submit_list,
rx_submit_list) {
F_14 ( & V_17 -> V_50 , V_18 ) ;
F_51 ( V_13 -> V_9 ) ;
F_12 ( & V_17 -> V_50 , V_18 ) ;
}
F_14 ( & V_17 -> V_50 , V_18 ) ;
return 0 ;
}
static int F_69 ( struct V_78 * V_71 )
{
struct V_38 * V_38 ;
struct V_23 * V_23 ;
T_4 V_2 ;
V_38 = F_65 ( V_71 ) ;
V_23 = V_38 -> V_59 ;
if ( V_23 -> V_54 != V_70 ) {
F_29 ( V_71 -> V_95 , L_15 ) ;
return - 1 ;
}
V_23 -> V_54 = V_55 ;
for ( V_2 = 0 ; V_2 < V_77 ; V_2 ++ )
F_31 ( V_23 , V_23 -> V_66 ) ;
return 0 ;
}
static int T_5 F_70 ( void )
{
F_71 () ;
return F_72 ( & V_96 ) ;
}
static void T_6 F_73 ( void )
{
F_74 () ;
F_75 ( & V_96 ) ;
}
