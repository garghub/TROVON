static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 [ 16 ] = { 0 ,} ;
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
int V_9 = - 1 ;
V_5 -> V_10 = F_2 ( & V_2 -> V_11 , V_12 ) ;
V_5 -> V_13 = F_2 ( & V_2 -> V_11 , 1 ) ;
V_5 -> V_14 [ 0 ] = V_15 ;
V_9 = F_3 ( V_7 , F_4 ( V_7 , 2 ) , V_3 , 5 ,
& V_8 , 1000 ) ;
V_2 -> V_16 = 1 ;
return V_9 ;
}
static struct V_17 * F_5 ( int V_13 )
{
struct V_17 * V_18 = NULL ;
int V_9 = 0 ;
V_18 = F_6 ( sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 ) {
V_9 = - V_20 ;
goto V_21;
}
V_18 -> V_22 = F_7 ( 0 , V_19 ) ;
if ( ! ( V_13 % 512 ) )
V_13 ++ ;
V_18 -> V_3 = F_8 ( V_13 , V_19 ) ;
if ( ! V_18 -> V_22 || ! V_18 -> V_3 ) {
V_9 = - V_20 ;
goto V_21;
}
V_21:
if ( V_9 < 0 ) {
if ( V_18 ) {
F_9 ( V_18 -> V_22 ) ;
F_10 ( V_18 -> V_3 ) ;
F_10 ( V_18 ) ;
}
return NULL ;
}
return V_18 ;
}
static struct V_23 * F_11 ( void )
{
struct V_23 * V_24 ;
V_24 = F_6 ( sizeof( * V_24 ) , V_25 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_3 = F_8 ( V_26 , V_25 ) ;
if ( ! V_24 -> V_3 ) {
F_10 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
static void F_12 ( struct V_17 * V_18 )
{
if ( V_18 ) {
F_9 ( V_18 -> V_22 ) ;
F_10 ( V_18 -> V_3 ) ;
F_10 ( V_18 ) ;
}
}
static void F_13 ( struct V_23 * V_24 )
{
if ( V_24 ) {
F_10 ( V_24 -> V_3 ) ;
F_10 ( V_24 ) ;
}
}
static struct V_23 * F_14 ( struct V_27 * V_28 , int * V_29 )
{
struct V_23 * V_24 ;
if ( F_15 ( & V_28 -> V_30 ) )
return NULL ;
V_24 = F_16 ( V_28 -> V_30 . V_31 , struct V_23 , V_32 ) ;
F_17 ( & V_24 -> V_32 ) ;
V_28 -> V_33 -- ;
* V_29 = F_15 ( & V_28 -> V_30 ) ? 1 : 0 ;
return V_24 ;
}
static void F_18 ( struct V_27 * V_28 , struct V_23 * V_24 )
{
F_19 ( & V_24 -> V_32 , & V_28 -> V_30 ) ;
V_28 -> V_33 ++ ;
}
static struct V_34 * F_20 ( void )
{
struct V_34 * V_35 = NULL ;
int V_9 = 0 ;
V_35 = F_8 ( sizeof( * V_35 ) , V_25 ) ;
if ( ! V_35 ) {
V_9 = - V_20 ;
goto V_21;
}
V_35 -> V_22 = F_7 ( 0 , V_25 ) ;
V_35 -> V_3 = F_8 ( V_36 , V_25 ) ;
if ( ! V_35 -> V_22 || ! V_35 -> V_3 ) {
V_9 = - V_20 ;
goto V_21;
}
V_21:
if ( V_9 < 0 ) {
if ( V_35 ) {
F_9 ( V_35 -> V_22 ) ;
F_10 ( V_35 -> V_3 ) ;
F_10 ( V_35 ) ;
}
return NULL ;
}
return V_35 ;
}
static void F_21 ( struct V_34 * V_35 )
{
if ( V_35 ) {
F_9 ( V_35 -> V_22 ) ;
F_10 ( V_35 -> V_3 ) ;
F_10 ( V_35 ) ;
}
}
static struct V_34 * F_22 ( struct V_37 * V_38 , int * V_29 )
{
struct V_34 * V_35 ;
unsigned long V_39 ;
F_23 ( & V_38 -> V_40 , V_39 ) ;
if ( F_15 ( & V_38 -> V_30 ) ) {
F_24 ( & V_38 -> V_40 , V_39 ) ;
return NULL ;
}
V_35 = F_16 ( V_38 -> V_30 . V_31 , struct V_34 , V_30 ) ;
F_17 ( & V_35 -> V_30 ) ;
V_38 -> V_33 -- ;
* V_29 = F_15 ( & V_38 -> V_30 ) ? 1 : 0 ;
F_24 ( & V_38 -> V_40 , V_39 ) ;
return V_35 ;
}
static void F_25 ( struct V_37 * V_38 , struct V_34 * V_35 )
{
unsigned long V_39 ;
F_23 ( & V_38 -> V_40 , V_39 ) ;
F_19 ( & V_35 -> V_30 , & V_38 -> V_30 ) ;
V_38 -> V_33 ++ ;
F_24 ( & V_38 -> V_40 , V_39 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = & V_2 -> V_38 ;
struct V_27 * V_28 = & V_2 -> V_28 ;
struct V_17 * V_18 , * V_41 ;
struct V_34 * V_35 , * V_42 ;
struct V_23 * V_24 , * V_43 ;
unsigned long V_39 ;
F_23 ( & V_28 -> V_44 , V_39 ) ;
F_27 (t_sdu, t_sdu_next, &tx->sdu_list, list) {
F_17 ( & V_24 -> V_32 ) ;
F_13 ( V_24 ) ;
}
F_27 (t, t_next, &tx->hci_list, list) {
F_17 ( & V_18 -> V_32 ) ;
F_12 ( V_18 ) ;
}
F_27 (t_sdu, t_sdu_next, &tx->free_list, list) {
F_17 ( & V_24 -> V_32 ) ;
F_13 ( V_24 ) ;
}
F_24 ( & V_28 -> V_44 , V_39 ) ;
F_23 ( & V_38 -> V_45 , V_39 ) ;
F_27 (r, r_next, &rx->rx_submit_list,
rx_submit_list) {
F_24 ( & V_38 -> V_45 , V_39 ) ;
F_28 ( V_35 -> V_22 ) ;
F_23 ( & V_38 -> V_45 , V_39 ) ;
}
F_24 ( & V_38 -> V_45 , V_39 ) ;
F_23 ( & V_38 -> V_40 , V_39 ) ;
F_27 (r, r_next, &rx->free_list, free_list) {
F_17 ( & V_35 -> V_30 ) ;
F_21 ( V_35 ) ;
}
F_24 ( & V_38 -> V_40 , V_39 ) ;
F_23 ( & V_38 -> V_46 , V_39 ) ;
F_27 (r, r_next, &rx->to_host_list, to_host_list) {
if ( V_35 -> V_47 == ( void * ) V_2 ) {
F_17 ( & V_35 -> V_48 ) ;
F_21 ( V_35 ) ;
}
}
F_24 ( & V_38 -> V_46 , V_39 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
int V_49 ;
struct V_27 * V_28 = & V_2 -> V_28 ;
struct V_37 * V_38 = & V_2 -> V_38 ;
struct V_23 * V_24 = NULL ;
struct V_34 * V_35 = NULL ;
V_2 -> V_50 = 1 ;
V_2 -> V_51 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_52 = V_53 ;
F_30 ( & V_28 -> V_54 ) ;
F_30 ( & V_28 -> V_55 ) ;
F_30 ( & V_28 -> V_30 ) ;
F_30 ( & V_38 -> V_56 ) ;
F_30 ( & V_38 -> V_30 ) ;
F_30 ( & V_38 -> V_48 ) ;
F_31 ( & V_28 -> V_44 ) ;
F_31 ( & V_38 -> V_40 ) ;
F_31 ( & V_38 -> V_45 ) ;
F_31 ( & V_38 -> V_46 ) ;
V_28 -> V_33 = 0 ;
V_38 -> V_33 = 0 ;
V_2 -> V_57 = NULL ;
for ( V_49 = 0 ; V_49 < V_58 ; V_49 ++ ) {
V_24 = F_11 () ;
if ( ! V_24 ) {
V_9 = - V_20 ;
goto V_59;
}
F_32 ( & V_24 -> V_32 , & V_28 -> V_30 ) ;
V_28 -> V_33 ++ ;
}
for ( V_49 = 0 ; V_49 < V_60 * 2 ; V_49 ++ ) {
V_35 = F_20 () ;
if ( ! V_35 ) {
V_9 = - V_20 ;
goto V_59;
}
F_32 ( & V_35 -> V_30 , & V_38 -> V_30 ) ;
V_38 -> V_33 ++ ;
}
F_33 ( & V_2 -> V_61 , V_62 ) ;
F_33 ( & V_2 -> V_63 , V_64 ) ;
return 0 ;
V_59:
F_26 ( V_2 ) ;
return V_9 ;
}
static int F_34 ( T_1 * V_14 , void * V_65 )
{
struct V_66 * V_66 = V_65 ;
struct V_1 * V_2 = V_66 -> V_67 ;
struct V_68 * V_68 = (struct V_68 * ) V_14 ;
T_1 V_69 [ V_70 ] = { 0 , } ;
if ( V_68 -> type == V_15 && V_2 -> V_16 ) {
memcpy ( V_69 , V_68 -> V_14 , V_68 -> V_13 ) ;
if ( F_35 ( V_66 ,
& V_2 -> V_71 -> V_72 , V_69 ) < 0 )
F_36 ( L_1 ) ;
V_2 -> V_16 = 0 ;
return 1 ;
}
return 0 ;
}
static void V_64 ( struct V_73 * V_74 )
{
struct V_1 * V_2 =
F_37 ( V_74 , struct V_1 , V_63 . V_74 ) ;
struct V_37 * V_38 = & V_2 -> V_38 ;
struct V_34 * V_35 ;
struct V_4 * V_5 ;
struct V_66 * V_66 ;
T_2 V_10 ;
int V_9 ;
unsigned long V_39 ;
while ( 1 ) {
F_23 ( & V_38 -> V_46 , V_39 ) ;
if ( F_15 ( & V_38 -> V_48 ) ) {
F_24 ( & V_38 -> V_46 , V_39 ) ;
break;
}
V_35 = F_16 ( V_38 -> V_48 . V_31 ,
struct V_34 , V_48 ) ;
F_17 ( & V_35 -> V_48 ) ;
F_24 ( & V_38 -> V_46 , V_39 ) ;
V_66 = V_35 -> V_75 ;
V_2 = V_66 -> V_67 ;
V_5 = (struct V_4 * ) V_35 -> V_3 ;
V_10 = F_38 ( & V_2 -> V_11 , V_5 -> V_10 ) ;
switch ( V_10 ) {
case V_76 :
if ( F_34 ( V_5 -> V_14 , V_35 -> V_75 ) == 0 ) {
V_35 -> V_77 ( V_35 -> V_75 ,
V_35 -> V_3 ,
V_35 -> V_22 -> V_78 ,
V_79 ) ;
}
break;
default:
if ( V_35 -> V_77 ) {
V_9 = V_35 -> V_77 ( V_35 -> V_75 ,
V_35 -> V_3 ,
V_35 -> V_22 -> V_78 ,
V_79 ) ;
if ( V_9 == - V_80 )
F_36 ( L_2 ) ;
}
break;
}
F_25 ( V_38 , V_35 ) ;
F_39 ( V_2 ,
V_35 -> V_77 ,
V_35 -> V_75 ,
V_81 ) ;
}
}
static void F_40 ( struct V_34 * V_35 , struct V_37 * V_38 )
{
unsigned long V_39 ;
struct V_34 * V_82 , * V_83 ;
F_23 ( & V_38 -> V_45 , V_39 ) ;
F_27 (r_remove, r_remove_next,
&rx->rx_submit_list, rx_submit_list) {
if ( V_35 == V_82 ) {
F_17 ( & V_35 -> V_56 ) ;
break;
}
}
F_24 ( & V_38 -> V_45 , V_39 ) ;
}
static void F_41 ( struct V_22 * V_22 )
{
struct V_34 * V_35 = V_22 -> V_84 ;
struct V_37 * V_38 = V_35 -> V_38 ;
unsigned long V_39 ;
struct V_1 * V_2 = F_37 ( V_35 -> V_38 , struct V_1 , V_38 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_40 ( V_35 , V_38 ) ;
if ( ! V_22 -> V_85 && V_35 -> V_77 ) {
F_23 ( & V_38 -> V_46 , V_39 ) ;
F_19 ( & V_35 -> V_48 , & V_38 -> V_48 ) ;
F_42 ( & V_2 -> V_63 . V_74 ) ;
F_24 ( & V_38 -> V_46 , V_39 ) ;
} else {
if ( V_22 -> V_85 && V_2 -> V_52 == V_53 )
F_43 ( & V_22 -> V_72 -> V_72 , L_3 ,
V_86 , V_22 -> V_85 ) ;
F_25 ( V_38 , V_35 ) ;
}
F_44 ( V_7 ) ;
}
static int F_39 ( void * V_67 ,
int (* F_45)( void * V_75 ,
void * V_14 , int V_13 , int V_84 ) ,
void * V_75 ,
int V_84 )
{
struct V_1 * V_2 = V_67 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_37 * V_38 = & V_2 -> V_38 ;
struct V_34 * V_35 ;
int V_29 ;
int V_9 ;
unsigned long V_39 ;
if ( ! V_2 -> V_7 ) {
F_36 ( L_4 ) ;
return - V_87 ;
}
V_35 = F_22 ( V_38 , & V_29 ) ;
if ( ! V_35 ) {
F_36 ( L_5 ) ;
return - V_20 ;
}
V_2 -> V_57 = F_45 ;
V_35 -> V_77 = F_45 ;
V_35 -> V_75 = V_75 ;
V_35 -> V_47 = ( void * ) V_2 ;
V_35 -> V_38 = V_38 ;
F_46 ( V_35 -> V_22 ,
V_7 ,
F_47 ( V_7 , 0x83 ) ,
V_35 -> V_3 ,
V_36 ,
F_41 ,
V_35 ) ;
F_23 ( & V_38 -> V_45 , V_39 ) ;
F_19 ( & V_35 -> V_56 , & V_38 -> V_56 ) ;
F_24 ( & V_38 -> V_45 , V_39 ) ;
if ( V_84 == V_79 )
V_9 = F_48 ( V_35 -> V_22 , V_25 ) ;
else
V_9 = F_48 ( V_35 -> V_22 , V_19 ) ;
if ( V_9 ) {
F_23 ( & V_38 -> V_45 , V_39 ) ;
F_17 ( & V_35 -> V_56 ) ;
F_24 ( & V_38 -> V_45 , V_39 ) ;
F_36 ( L_6 , V_35 ) ;
F_25 ( V_38 , V_35 ) ;
}
return V_9 ;
}
static void F_49 ( struct V_22 * V_22 )
{
struct V_17 * V_18 = V_22 -> V_84 ;
struct V_27 * V_28 = V_18 -> V_28 ;
struct V_1 * V_2 = F_37 ( V_28 , struct V_1 , V_28 ) ;
unsigned long V_39 ;
if ( V_22 -> V_85 == - V_88 ) {
F_50 ( & V_22 -> V_72 -> V_72 , L_7 ) ;
return;
}
if ( V_18 -> V_77 )
V_18 -> V_77 ( V_18 -> V_75 ) ;
F_12 ( V_18 ) ;
F_23 ( & V_28 -> V_44 , V_39 ) ;
V_2 -> V_50 = 1 ;
F_42 ( & V_2 -> V_61 . V_74 ) ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
}
static int F_51 ( struct V_6 * V_7 , struct V_17 * V_18 , T_3 V_13 )
{
int V_9 = 0 ;
if ( ! ( V_13 % 512 ) )
V_13 ++ ;
F_46 ( V_18 -> V_22 ,
V_7 ,
F_4 ( V_7 , 2 ) ,
V_18 -> V_3 ,
V_13 ,
F_49 ,
V_18 ) ;
V_9 = F_48 ( V_18 -> V_22 , V_19 ) ;
if ( V_9 )
F_43 ( & V_7 -> V_72 , L_8 ,
V_9 ) ;
F_44 ( V_7 ) ;
return V_9 ;
}
static T_3 F_52 ( struct V_1 * V_2 , T_1 * V_89 )
{
struct V_27 * V_28 = & V_2 -> V_28 ;
struct V_23 * V_24 = NULL ;
struct V_90 * V_90 = (struct V_90 * ) V_89 ;
T_2 V_91 = 0 ;
T_2 V_92 = 0 ;
unsigned long V_39 ;
V_90 -> V_10 = F_2 ( & V_2 -> V_11 , V_93 ) ;
while ( V_92 < V_94 ) {
F_23 ( & V_28 -> V_44 , V_39 ) ;
if ( F_15 ( & V_28 -> V_54 ) ) {
F_24 ( & V_28 -> V_44 , V_39 ) ;
break;
}
V_24 = F_16 ( V_28 -> V_54 . V_31 , struct V_23 , V_32 ) ;
if ( V_91 + V_24 -> V_13 > V_95 ) {
F_24 ( & V_28 -> V_44 , V_39 ) ;
break;
}
F_17 ( & V_24 -> V_32 ) ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
memcpy ( V_90 -> V_14 + V_91 , V_24 -> V_3 , V_24 -> V_13 ) ;
V_91 += ( V_24 -> V_13 + 3 ) & 0xfffc ;
V_92 ++ ;
if ( V_28 -> V_33 > 10 )
V_24 -> V_77 ( V_24 -> V_75 ) ;
F_23 ( & V_28 -> V_44 , V_39 ) ;
F_18 ( V_28 , V_24 ) ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
}
V_90 -> V_13 = F_2 ( & V_2 -> V_11 , V_91 ) ;
V_90 -> V_92 = F_2 ( & V_2 -> V_11 , V_92 ) ;
return V_91 + F_53 ( struct V_90 , V_14 ) ;
}
static void V_62 ( struct V_73 * V_74 )
{
struct V_1 * V_2 =
F_37 ( V_74 , struct V_1 , V_61 . V_74 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_27 * V_28 = & V_2 -> V_28 ;
struct V_17 * V_18 = NULL ;
int V_96 = 0 ;
T_3 V_13 = 0 ;
unsigned long V_39 ;
if ( ! F_54 ( V_2 -> V_71 ) )
F_55 ( V_2 -> V_71 ) ;
if ( V_2 -> V_52 == V_97 )
return;
F_23 ( & V_28 -> V_44 , V_39 ) ;
if ( ! V_2 -> V_50 ) {
F_24 ( & V_28 -> V_44 , V_39 ) ;
return;
}
V_2 -> V_50 = 0 ;
if ( ! F_15 ( & V_28 -> V_55 ) ) {
V_18 = F_16 ( V_28 -> V_55 . V_31 , struct V_17 , V_32 ) ;
F_17 ( & V_18 -> V_32 ) ;
V_13 = V_18 -> V_13 ;
V_18 -> V_98 = 0 ;
V_96 = 1 ;
} else if ( ! F_15 ( & V_28 -> V_54 ) ) {
if ( V_2 -> V_51 ) {
V_2 -> V_50 = 1 ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
return;
}
V_18 = F_5 ( V_99 ) ;
if ( ! V_18 ) {
F_24 ( & V_28 -> V_44 , V_39 ) ;
return;
}
V_18 -> V_77 = NULL ;
V_18 -> V_28 = V_28 ;
V_18 -> V_98 = 1 ;
V_96 = 1 ;
}
if ( ! V_96 ) {
V_2 -> V_50 = 1 ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
return;
}
F_24 ( & V_28 -> V_44 , V_39 ) ;
if ( V_18 -> V_98 )
V_13 = F_52 ( V_2 , V_18 -> V_3 ) ;
if ( F_51 ( V_7 , V_18 , V_13 ) ) {
F_36 ( L_9 ) ;
V_18 -> V_77 = NULL ;
F_49 ( V_18 -> V_22 ) ;
}
}
static int F_56 ( void * V_67 , void * V_14 , int V_13 ,
unsigned int V_100 , unsigned int V_101 ,
void (* F_45)( void * V_14 ) , void * V_75 ,
int V_102 , int V_103 )
{
struct V_1 * V_2 = V_67 ;
struct V_27 * V_28 = & V_2 -> V_28 ;
struct V_23 * V_24 ;
struct V_104 * V_104 = NULL ;
unsigned long V_39 ;
int V_29 = 0 ;
T_2 V_91 ;
if ( ! V_2 -> V_7 ) {
F_36 ( L_10 ) ;
return V_105 ;
}
F_23 ( & V_28 -> V_44 , V_39 ) ;
V_24 = F_14 ( V_28 , & V_29 ) ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
if ( ! V_24 ) {
F_36 ( L_11 ) ;
return V_106 ;
}
V_104 = (struct V_104 * ) V_24 -> V_3 ;
V_104 -> V_10 = F_2 ( & V_2 -> V_11 , V_107 ) ;
if ( V_103 == V_108 ) {
V_91 = V_13 + V_109 ;
memcpy ( V_104 -> V_14 , V_14 , V_13 ) ;
} else {
V_91 = V_13 - V_110 ;
V_91 += V_109 ;
memcpy ( V_104 -> V_14 , V_14 + V_110 , V_13 - V_110 ) ;
}
V_104 -> V_13 = F_2 ( & V_2 -> V_11 , V_91 ) ;
V_104 -> V_100 = F_57 ( & V_2 -> V_11 , V_100 ) ;
V_104 -> V_111 = F_57 ( & V_2 -> V_11 , V_101 ) ;
V_104 -> V_103 = F_57 ( & V_2 -> V_11 , V_103 ) ;
V_24 -> V_13 = V_91 + V_112 ;
V_24 -> V_77 = F_45 ;
V_24 -> V_75 = V_75 ;
F_23 ( & V_28 -> V_44 , V_39 ) ;
F_19 ( & V_24 -> V_32 , & V_28 -> V_54 ) ;
F_42 ( & V_2 -> V_61 . V_74 ) ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
if ( V_29 )
return V_113 ;
return 0 ;
}
static int F_58 ( void * V_67 , void * V_14 , int V_13 ,
void (* F_45)( void * V_14 ) , void * V_75 )
{
struct V_1 * V_2 = V_67 ;
struct V_27 * V_28 = & V_2 -> V_28 ;
struct V_17 * V_18 ;
unsigned long V_39 ;
if ( ! V_2 -> V_7 ) {
F_36 ( L_12 ) ;
return - V_87 ;
}
V_18 = F_5 ( V_13 ) ;
if ( ! V_18 ) {
F_36 ( L_13 ) ;
return - V_20 ;
}
memcpy ( V_18 -> V_3 , V_14 , V_13 ) ;
V_18 -> V_77 = F_45 ;
V_18 -> V_75 = V_75 ;
V_18 -> V_13 = V_13 ;
V_18 -> V_28 = V_28 ;
V_18 -> V_98 = 0 ;
F_23 ( & V_28 -> V_44 , V_39 ) ;
F_19 ( & V_18 -> V_32 , & V_28 -> V_55 ) ;
F_42 ( & V_2 -> V_61 . V_74 ) ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
return 0 ;
}
static struct V_114 * F_59 ( void * V_67 )
{
struct V_1 * V_2 = V_67 ;
return & V_2 -> V_11 ;
}
static int F_60 ( struct V_115 * V_71 ,
const struct V_116 * V_117 )
{
int V_9 = 0 ;
struct V_66 * V_66 = NULL ;
struct V_1 * V_2 = NULL ;
T_2 V_118 , V_119 ;
int V_120 ;
struct V_6 * V_7 = F_61 ( V_71 ) ;
V_120 = V_71 -> V_121 -> V_122 . V_120 ;
V_118 = F_62 ( V_7 -> V_123 . V_118 ) ;
V_119 = F_62 ( V_7 -> V_123 . V_119 ) ;
F_63 ( L_14 , V_118 , V_119 ) ;
if ( V_120 > V_124 ) {
F_63 ( L_15 ) ;
return - V_87 ;
}
V_66 = F_6 ( sizeof( * V_66 ) , V_25 ) ;
if ( ! V_66 )
return - V_20 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 ) {
V_9 = - V_20 ;
goto V_125;
}
V_66 -> V_67 = ( void * ) V_2 ;
V_66 -> V_126 = F_58 ;
V_66 -> V_127 = F_56 ;
V_66 -> V_128 = F_39 ;
V_66 -> V_129 = F_59 ;
V_2 -> V_7 = V_7 ;
V_9 = F_29 ( V_2 ) ;
if ( V_9 < 0 ) {
F_43 ( V_71 -> V_130 , L_16 ) ;
goto V_131;
}
V_2 -> V_71 = V_71 ;
V_71 -> V_132 = 1 ;
F_64 ( V_7 ) ;
F_65 ( & V_7 -> V_72 , V_133 ) ;
if ( V_119 == V_134 )
F_66 ( & V_2 -> V_11 , V_135 ) ;
else
F_66 ( & V_2 -> V_11 , V_136 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 ) {
F_43 ( V_71 -> V_130 , L_17 ) ;
goto V_137;
}
F_67 ( V_66 ) ;
F_68 ( V_7 ) ;
F_69 ( V_71 , V_66 ) ;
return 0 ;
V_137:
F_26 ( V_2 ) ;
V_131:
F_10 ( V_2 ) ;
V_125:
F_10 ( V_66 ) ;
return V_9 ;
}
static void F_70 ( struct V_115 * V_71 )
{
struct V_66 * V_66 ;
struct V_1 * V_2 ;
T_2 V_118 , V_119 ;
struct V_6 * V_7 ;
V_7 = F_61 ( V_71 ) ;
V_118 = F_62 ( V_7 -> V_123 . V_118 ) ;
V_119 = F_62 ( V_7 -> V_123 . V_119 ) ;
V_66 = F_71 ( V_71 ) ;
V_2 = V_66 -> V_67 ;
F_72 ( V_66 ) ;
F_26 ( V_2 ) ;
F_10 ( V_2 ) ;
V_2 = NULL ;
F_10 ( V_66 ) ;
V_66 = NULL ;
F_73 ( V_7 ) ;
}
static int F_74 ( struct V_115 * V_71 , T_4 V_138 )
{
struct V_66 * V_66 ;
struct V_1 * V_2 ;
struct V_37 * V_38 ;
struct V_34 * V_35 ;
struct V_34 * V_42 ;
unsigned long V_39 ;
V_66 = F_71 ( V_71 ) ;
V_2 = V_66 -> V_67 ;
V_38 = & V_2 -> V_38 ;
if ( V_2 -> V_52 != V_53 ) {
F_43 ( V_71 -> V_130 , L_18 ) ;
return - 1 ;
}
V_2 -> V_52 = V_97 ;
F_23 ( & V_38 -> V_45 , V_39 ) ;
F_27 (r, r_next, &rx->rx_submit_list,
rx_submit_list) {
F_24 ( & V_38 -> V_45 , V_39 ) ;
F_28 ( V_35 -> V_22 ) ;
F_23 ( & V_38 -> V_45 , V_39 ) ;
}
F_24 ( & V_38 -> V_45 , V_39 ) ;
F_75 ( & V_2 -> V_61 . V_74 ) ;
F_75 ( & V_2 -> V_63 . V_74 ) ;
return 0 ;
}
static int F_76 ( struct V_115 * V_71 )
{
struct V_66 * V_66 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
struct V_37 * V_38 ;
unsigned long V_39 ;
int V_139 ;
int V_49 ;
V_66 = F_71 ( V_71 ) ;
V_2 = V_66 -> V_67 ;
V_38 = & V_2 -> V_38 ;
if ( V_2 -> V_52 != V_97 ) {
F_43 ( V_71 -> V_130 , L_19 ) ;
return - 1 ;
}
V_2 -> V_52 = V_53 ;
F_23 ( & V_38 -> V_40 , V_39 ) ;
V_139 = V_38 -> V_33 - V_60 ;
F_24 ( & V_38 -> V_40 , V_39 ) ;
if ( V_139 >= 0 ) {
for ( V_49 = 0 ; V_49 < V_139 ; V_49 ++ )
F_39 ( V_66 -> V_67 ,
V_2 -> V_57 ,
V_66 ,
V_81 ) ;
}
V_28 = & V_2 -> V_28 ;
F_23 ( & V_28 -> V_44 , V_39 ) ;
F_42 ( & V_2 -> V_61 . V_74 ) ;
F_24 ( & V_28 -> V_44 , V_39 ) ;
return 0 ;
}
static int T_5 F_77 ( void )
{
if ( F_78 () < 0 ) {
F_36 ( L_20 ) ;
return - 1 ;
}
return F_79 ( & V_140 ) ;
}
static void T_6 F_80 ( void )
{
F_81 () ;
F_82 ( & V_140 ) ;
}
