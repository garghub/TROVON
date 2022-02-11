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
V_18 = F_6 ( sizeof( struct V_17 ) , V_19 ) ;
if ( ! V_18 ) {
V_9 = - V_20 ;
goto V_21;
}
memset ( V_18 , 0 , sizeof( struct V_17 ) ) ;
V_18 -> V_22 = F_7 ( 0 , V_19 ) ;
if ( ! ( V_13 % 512 ) )
V_13 ++ ;
V_18 -> V_3 = F_6 ( V_13 , V_19 ) ;
if ( ! V_18 -> V_22 || ! V_18 -> V_3 ) {
V_9 = - V_20 ;
goto V_21;
}
V_21:
if ( V_9 < 0 ) {
if ( V_18 ) {
F_8 ( V_18 -> V_22 ) ;
F_9 ( V_18 -> V_3 ) ;
F_9 ( V_18 ) ;
}
return NULL ;
}
return V_18 ;
}
static struct V_23 * F_10 ( void )
{
struct V_23 * V_24 = NULL ;
int V_9 = 0 ;
V_24 = F_6 ( sizeof( struct V_23 ) , V_19 ) ;
if ( ! V_24 ) {
V_9 = - V_20 ;
goto V_21;
}
memset ( V_24 , 0 , sizeof( struct V_23 ) ) ;
V_24 -> V_3 = F_6 ( V_25 , V_19 ) ;
if ( ! V_24 -> V_3 ) {
V_9 = - V_20 ;
goto V_21;
}
V_21:
if ( V_9 < 0 ) {
if ( V_24 ) {
F_9 ( V_24 -> V_3 ) ;
F_9 ( V_24 ) ;
}
return NULL ;
}
return V_24 ;
}
static void F_11 ( struct V_17 * V_18 )
{
if ( V_18 ) {
F_8 ( V_18 -> V_22 ) ;
F_9 ( V_18 -> V_3 ) ;
F_9 ( V_18 ) ;
}
}
static void F_12 ( struct V_23 * V_24 )
{
if ( V_24 ) {
F_9 ( V_24 -> V_3 ) ;
F_9 ( V_24 ) ;
}
}
static struct V_23 * F_13 ( struct V_26 * V_27 , int * V_28 )
{
struct V_23 * V_24 ;
if ( F_14 ( & V_27 -> V_29 ) )
return NULL ;
V_24 = F_15 ( V_27 -> V_29 . V_30 , struct V_23 , V_31 ) ;
F_16 ( & V_24 -> V_31 ) ;
V_27 -> V_32 -- ;
* V_28 = F_14 ( & V_27 -> V_29 ) ? 1 : 0 ;
return V_24 ;
}
static void F_17 ( struct V_26 * V_27 , struct V_23 * V_24 )
{
F_18 ( & V_24 -> V_31 , & V_27 -> V_29 ) ;
V_27 -> V_32 ++ ;
}
static struct V_33 * F_19 ( void )
{
struct V_33 * V_34 = NULL ;
int V_9 = 0 ;
V_34 = F_6 ( sizeof( struct V_33 ) , V_19 ) ;
if ( ! V_34 ) {
V_9 = - V_20 ;
goto V_21;
}
V_34 -> V_22 = F_7 ( 0 , V_19 ) ;
V_34 -> V_3 = F_6 ( V_35 , V_19 ) ;
if ( ! V_34 -> V_22 || ! V_34 -> V_3 ) {
V_9 = - V_20 ;
goto V_21;
}
V_21:
if ( V_9 < 0 ) {
if ( V_34 ) {
F_8 ( V_34 -> V_22 ) ;
F_9 ( V_34 -> V_3 ) ;
F_9 ( V_34 ) ;
}
return NULL ;
}
return V_34 ;
}
static void F_20 ( struct V_33 * V_34 )
{
if ( V_34 ) {
F_8 ( V_34 -> V_22 ) ;
F_9 ( V_34 -> V_3 ) ;
F_9 ( V_34 ) ;
}
}
static struct V_33 * F_21 ( struct V_36 * V_37 , int * V_28 )
{
struct V_33 * V_34 ;
unsigned long V_38 ;
F_22 ( & V_37 -> V_39 , V_38 ) ;
if ( F_14 ( & V_37 -> V_29 ) ) {
F_23 ( & V_37 -> V_39 , V_38 ) ;
return NULL ;
}
V_34 = F_15 ( V_37 -> V_29 . V_30 , struct V_33 , V_29 ) ;
F_16 ( & V_34 -> V_29 ) ;
V_37 -> V_32 -- ;
* V_28 = F_14 ( & V_37 -> V_29 ) ? 1 : 0 ;
F_23 ( & V_37 -> V_39 , V_38 ) ;
return V_34 ;
}
static void F_24 ( struct V_36 * V_37 , struct V_33 * V_34 )
{
unsigned long V_38 ;
F_22 ( & V_37 -> V_39 , V_38 ) ;
F_18 ( & V_34 -> V_29 , & V_37 -> V_29 ) ;
V_37 -> V_32 ++ ;
F_23 ( & V_37 -> V_39 , V_38 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_17 * V_18 , * V_40 ;
struct V_33 * V_34 , * V_41 ;
struct V_23 * V_24 , * V_42 ;
unsigned long V_38 ;
F_22 ( & V_27 -> V_43 , V_38 ) ;
F_26 (t_sdu, t_sdu_next, &tx->sdu_list, list)
{
F_16 ( & V_24 -> V_31 ) ;
F_12 ( V_24 ) ;
}
F_26 (t, t_next, &tx->hci_list, list)
{
F_16 ( & V_18 -> V_31 ) ;
F_11 ( V_18 ) ;
}
F_26 (t_sdu, t_sdu_next, &tx->free_list, list)
{
F_16 ( & V_24 -> V_31 ) ;
F_12 ( V_24 ) ;
}
F_23 ( & V_27 -> V_43 , V_38 ) ;
F_22 ( & V_37 -> V_44 , V_38 ) ;
F_26 (r, r_next, &rx->rx_submit_list, rx_submit_list)
{
F_23 ( & V_37 -> V_44 , V_38 ) ;
F_27 ( V_34 -> V_22 ) ;
F_22 ( & V_37 -> V_44 , V_38 ) ;
}
F_23 ( & V_37 -> V_44 , V_38 ) ;
F_22 ( & V_37 -> V_39 , V_38 ) ;
F_26 (r, r_next, &rx->free_list, free_list)
{
F_16 ( & V_34 -> V_29 ) ;
F_20 ( V_34 ) ;
}
F_23 ( & V_37 -> V_39 , V_38 ) ;
F_22 ( & V_37 -> V_45 , V_38 ) ;
F_26 (r, r_next, &rx->to_host_list, to_host_list)
{
if ( V_34 -> V_46 == ( void * ) V_2 ) {
F_16 ( & V_34 -> V_47 ) ;
F_20 ( V_34 ) ;
}
}
F_23 ( & V_37 -> V_45 , V_38 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
int V_48 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_23 * V_24 = NULL ;
struct V_33 * V_34 = NULL ;
V_2 -> V_49 = 1 ;
V_2 -> V_50 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_51 = V_52 ;
F_29 ( & V_27 -> V_53 ) ;
F_29 ( & V_27 -> V_54 ) ;
F_29 ( & V_27 -> V_29 ) ;
F_29 ( & V_37 -> V_55 ) ;
F_29 ( & V_37 -> V_29 ) ;
F_29 ( & V_37 -> V_47 ) ;
F_30 ( & V_27 -> V_43 ) ;
F_30 ( & V_37 -> V_39 ) ;
F_30 ( & V_37 -> V_44 ) ;
F_30 ( & V_37 -> V_45 ) ;
V_27 -> V_32 = 0 ;
V_37 -> V_32 = 0 ;
V_2 -> V_56 = NULL ;
for ( V_48 = 0 ; V_48 < V_57 ; V_48 ++ ) {
V_24 = F_10 () ;
if ( V_24 == NULL ) {
V_9 = - V_20 ;
goto V_58;
}
F_31 ( & V_24 -> V_31 , & V_27 -> V_29 ) ;
V_27 -> V_32 ++ ;
}
for ( V_48 = 0 ; V_48 < V_59 * 2 ; V_48 ++ ) {
V_34 = F_19 () ;
if ( V_34 == NULL ) {
V_9 = - V_20 ;
goto V_58;
}
F_31 ( & V_34 -> V_29 , & V_37 -> V_29 ) ;
V_37 -> V_32 ++ ;
}
F_32 ( & V_2 -> V_60 , V_61 ) ;
F_32 ( & V_2 -> V_62 , V_63 ) ;
return 0 ;
V_58:
return V_9 ;
}
static int F_33 ( T_1 * V_14 , void * V_64 )
{
struct V_65 * V_65 = (struct V_65 * ) V_64 ;
struct V_1 * V_2 = V_65 -> V_66 ;
struct V_67 * V_67 = (struct V_67 * ) V_14 ;
T_1 V_68 [ V_69 ] = { 0 , } ;
if ( V_67 -> type == V_15 && V_2 -> V_16 ) {
memcpy ( V_68 , V_67 -> V_14 , V_67 -> V_13 ) ;
if ( F_34 ( V_65 , & V_2 -> V_70 -> V_71 , V_68 ) < 0 )
F_35 ( L_1 ) ;
V_2 -> V_16 = 0 ;
return 1 ;
}
return 0 ;
}
static void V_63 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_36 ( V_73 , struct V_1 , V_62 . V_73 ) ;
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_33 * V_34 ;
struct V_4 * V_5 ;
struct V_65 * V_65 ;
T_2 V_10 ;
int V_9 ;
unsigned long V_38 ;
while ( 1 ) {
F_22 ( & V_37 -> V_45 , V_38 ) ;
if ( F_14 ( & V_37 -> V_47 ) ) {
F_23 ( & V_37 -> V_45 , V_38 ) ;
break;
}
V_34 = F_15 ( V_37 -> V_47 . V_30 , struct V_33 , V_47 ) ;
F_16 ( & V_34 -> V_47 ) ;
F_23 ( & V_37 -> V_45 , V_38 ) ;
V_65 = (struct V_65 * ) V_34 -> V_74 ;
V_2 = (struct V_1 * ) V_65 -> V_66 ;
V_5 = (struct V_4 * ) V_34 -> V_3 ;
V_10 = F_37 ( & V_2 -> V_11 , V_5 -> V_10 ) ;
switch ( V_10 ) {
case V_75 :
if ( F_33 ( V_5 -> V_14 , V_34 -> V_74 ) == 0 ) {
V_9 = V_34 -> V_76 ( V_34 -> V_74 ,
V_34 -> V_3 ,
V_34 -> V_22 -> V_77 ,
V_78 ) ;
}
break;
default:
if ( V_34 -> V_76 ) {
V_9 = V_34 -> V_76 ( V_34 -> V_74 ,
V_34 -> V_3 ,
V_34 -> V_22 -> V_77 ,
V_78 ) ;
if ( V_9 == - V_79 )
F_35 ( L_2 ) ;
}
break;
}
F_24 ( V_37 , V_34 ) ;
F_38 ( V_2 ,
V_34 -> V_76 ,
V_34 -> V_74 ,
V_80 ) ;
}
}
static void F_39 ( struct V_33 * V_34 , struct V_36 * V_37 )
{
unsigned long V_38 ;
struct V_33 * V_81 , * V_82 ;
F_22 ( & V_37 -> V_44 , V_38 ) ;
F_26 (r_remove, r_remove_next, &rx->rx_submit_list, rx_submit_list)
{
if ( V_34 == V_81 ) {
F_16 ( & V_34 -> V_55 ) ;
break;
}
}
F_23 ( & V_37 -> V_44 , V_38 ) ;
}
static void F_40 ( struct V_22 * V_22 )
{
struct V_33 * V_34 = V_22 -> V_83 ;
struct V_36 * V_37 = V_34 -> V_37 ;
unsigned long V_38 ;
struct V_1 * V_2 = F_36 ( V_34 -> V_37 , struct V_1 , V_37 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_39 ( V_34 , V_37 ) ;
if ( ! V_22 -> V_84 && V_34 -> V_76 ) {
F_22 ( & V_37 -> V_45 , V_38 ) ;
F_18 ( & V_34 -> V_47 , & V_37 -> V_47 ) ;
F_41 ( V_85 , & V_2 -> V_62 . V_73 ) ;
F_23 ( & V_37 -> V_45 , V_38 ) ;
} else {
if ( V_22 -> V_84 && V_2 -> V_51 == V_52 )
F_35 ( L_3 ,
V_86 , V_22 -> V_84 ) ;
F_24 ( V_37 , V_34 ) ;
}
F_42 ( V_7 ) ;
}
static int F_38 ( void * V_66 ,
int (* F_43)( void * V_74 , void * V_14 , int V_13 , int V_83 ) ,
void * V_74 ,
int V_83 )
{
struct V_1 * V_2 = V_66 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_33 * V_34 ;
int V_28 ;
int V_9 ;
unsigned long V_38 ;
if ( ! V_2 -> V_7 ) {
F_35 ( L_4 ) ;
return - V_87 ;
}
V_34 = F_21 ( V_37 , & V_28 ) ;
if ( ! V_34 ) {
F_35 ( L_5 ) ;
return - V_20 ;
}
V_2 -> V_56 = F_43 ;
V_34 -> V_76 = F_43 ;
V_34 -> V_74 = V_74 ;
V_34 -> V_46 = ( void * ) V_2 ;
V_34 -> V_37 = V_37 ;
F_44 ( V_34 -> V_22 ,
V_7 ,
F_45 ( V_7 , 0x83 ) ,
V_34 -> V_3 ,
V_35 ,
F_40 ,
V_34 ) ;
F_22 ( & V_37 -> V_44 , V_38 ) ;
F_18 ( & V_34 -> V_55 , & V_37 -> V_55 ) ;
F_23 ( & V_37 -> V_44 , V_38 ) ;
if ( V_83 == V_78 )
V_9 = F_46 ( V_34 -> V_22 , V_88 ) ;
else
V_9 = F_46 ( V_34 -> V_22 , V_19 ) ;
if ( V_9 ) {
F_22 ( & V_37 -> V_44 , V_38 ) ;
F_16 ( & V_34 -> V_55 ) ;
F_23 ( & V_37 -> V_44 , V_38 ) ;
F_35 ( L_6 , V_34 ) ;
F_24 ( V_37 , V_34 ) ;
}
return V_9 ;
}
static void F_47 ( struct V_22 * V_22 )
{
struct V_17 * V_18 = V_22 -> V_83 ;
struct V_26 * V_27 = V_18 -> V_27 ;
struct V_1 * V_2 = F_36 ( V_27 , struct V_1 , V_27 ) ;
unsigned long V_38 ;
if ( V_22 -> V_84 == - V_89 ) {
F_48 ( L_7 ) ;
return;
}
if ( V_18 -> V_76 )
V_18 -> V_76 ( V_18 -> V_74 ) ;
F_11 ( V_18 ) ;
F_22 ( & V_27 -> V_43 , V_38 ) ;
V_2 -> V_49 = 1 ;
F_41 ( V_90 , & V_2 -> V_60 . V_73 ) ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
}
static int F_49 ( struct V_6 * V_7 , struct V_17 * V_18 , T_3 V_13 )
{
int V_9 = 0 ;
if ( ! ( V_13 % 512 ) )
V_13 ++ ;
F_44 ( V_18 -> V_22 ,
V_7 ,
F_4 ( V_7 , 2 ) ,
V_18 -> V_3 ,
V_13 ,
F_47 ,
V_18 ) ;
V_9 = F_46 ( V_18 -> V_22 , V_19 ) ;
if ( V_9 )
F_35 ( L_8 , V_9 ) ;
F_42 ( V_7 ) ;
return V_9 ;
}
static T_3 F_50 ( struct V_1 * V_2 , T_1 * V_91 )
{
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_23 * V_24 = NULL ;
struct V_92 * V_92 = (struct V_92 * ) V_91 ;
T_2 V_93 = 0 ;
T_2 V_94 = 0 ;
unsigned long V_38 ;
V_92 -> V_10 = F_2 ( & V_2 -> V_11 , V_95 ) ;
while ( V_94 < V_96 ) {
F_22 ( & V_27 -> V_43 , V_38 ) ;
if ( F_14 ( & V_27 -> V_53 ) ) {
F_23 ( & V_27 -> V_43 , V_38 ) ;
break;
}
V_24 = F_15 ( V_27 -> V_53 . V_30 , struct V_23 , V_31 ) ;
if ( V_93 + V_24 -> V_13 > V_97 ) {
F_23 ( & V_27 -> V_43 , V_38 ) ;
break;
}
F_16 ( & V_24 -> V_31 ) ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
memcpy ( V_92 -> V_14 + V_93 , V_24 -> V_3 , V_24 -> V_13 ) ;
V_93 += ( V_24 -> V_13 + 3 ) & 0xfffc ;
V_94 ++ ;
if ( V_27 -> V_32 > 10 )
V_24 -> V_76 ( V_24 -> V_74 ) ;
F_22 ( & V_27 -> V_43 , V_38 ) ;
F_17 ( V_27 , V_24 ) ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
}
V_92 -> V_13 = F_2 ( & V_2 -> V_11 , V_93 ) ;
V_92 -> V_94 = F_2 ( & V_2 -> V_11 , V_94 ) ;
return V_93 + F_51 ( struct V_92 , V_14 ) ;
}
static void V_61 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_36 ( V_73 , struct V_1 , V_60 . V_73 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_17 * V_18 = NULL ;
int V_98 = 0 ;
T_3 V_13 = 0 ;
unsigned long V_38 ;
if ( ! F_52 ( V_2 -> V_70 ) )
F_53 ( V_2 -> V_70 ) ;
if ( V_2 -> V_51 == V_99 )
return;
F_22 ( & V_27 -> V_43 , V_38 ) ;
if ( ! V_2 -> V_49 ) {
F_23 ( & V_27 -> V_43 , V_38 ) ;
return;
} else {
V_2 -> V_49 = 0 ;
}
if ( ! F_14 ( & V_27 -> V_54 ) ) {
V_18 = F_15 ( V_27 -> V_54 . V_30 , struct V_17 , V_31 ) ;
F_16 ( & V_18 -> V_31 ) ;
V_13 = V_18 -> V_13 ;
V_18 -> V_100 = 0 ;
V_98 = 1 ;
} else if ( ! F_14 ( & V_27 -> V_53 ) ) {
if ( V_2 -> V_50 ) {
V_2 -> V_49 = 1 ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
return;
}
V_18 = F_5 ( V_101 ) ;
V_18 -> V_76 = NULL ;
V_18 -> V_27 = V_27 ;
V_18 -> V_100 = 1 ;
V_98 = 1 ;
}
if ( ! V_98 ) {
V_2 -> V_49 = 1 ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
return;
}
F_23 ( & V_27 -> V_43 , V_38 ) ;
if ( V_18 -> V_100 )
V_13 = F_50 ( V_2 , V_18 -> V_3 ) ;
if ( F_49 ( V_7 , V_18 , V_13 ) ) {
F_35 ( L_9 ) ;
V_18 -> V_76 = NULL ;
F_47 ( V_18 -> V_22 ) ;
}
}
static int F_54 ( void * V_66 , void * V_14 , int V_13 ,
unsigned int V_102 , unsigned int V_103 ,
void (* F_43)( void * V_14 ) , void * V_74 ,
int V_104 , int V_105 )
{
struct V_1 * V_2 = V_66 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_23 * V_24 ;
struct V_106 * V_106 = NULL ;
unsigned long V_38 ;
int V_28 = 0 ;
T_2 V_93 ;
if ( ! V_2 -> V_7 ) {
F_35 ( L_10 ) ;
return V_107 ;
}
F_22 ( & V_27 -> V_43 , V_38 ) ;
V_24 = F_13 ( V_27 , & V_28 ) ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
if ( V_24 == NULL ) {
F_35 ( L_11 ) ;
return V_108 ;
}
V_106 = (struct V_106 * ) V_24 -> V_3 ;
V_106 -> V_10 = F_2 ( & V_2 -> V_11 , V_109 ) ;
if ( V_105 == V_110 ) {
V_93 = V_13 + V_111 ;
memcpy ( V_106 -> V_14 , V_14 , V_13 ) ;
} else {
V_93 = V_13 - V_112 ;
V_93 += V_111 ;
memcpy ( V_106 -> V_14 , V_14 + V_112 , V_13 - V_112 ) ;
}
V_106 -> V_13 = F_2 ( & V_2 -> V_11 , V_93 ) ;
V_106 -> V_102 = F_55 ( & V_2 -> V_11 , V_102 ) ;
V_106 -> V_113 = F_55 ( & V_2 -> V_11 , V_103 ) ;
V_106 -> V_105 = F_55 ( & V_2 -> V_11 , V_105 ) ;
V_24 -> V_13 = V_93 + V_114 ;
V_24 -> V_76 = F_43 ;
V_24 -> V_74 = V_74 ;
F_22 ( & V_27 -> V_43 , V_38 ) ;
F_18 ( & V_24 -> V_31 , & V_27 -> V_53 ) ;
F_41 ( V_90 , & V_2 -> V_60 . V_73 ) ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
if ( V_28 )
return V_115 ;
return 0 ;
}
static int F_56 ( void * V_66 , void * V_14 , int V_13 ,
void (* F_43)( void * V_14 ) , void * V_74 )
{
struct V_1 * V_2 = V_66 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_17 * V_18 ;
unsigned long V_38 ;
if ( ! V_2 -> V_7 ) {
F_35 ( L_12 ) ;
return - V_87 ;
}
V_18 = F_5 ( V_13 ) ;
if ( V_18 == NULL ) {
F_35 ( L_13 ) ;
return - V_20 ;
}
memcpy ( V_18 -> V_3 , V_14 , V_13 ) ;
V_18 -> V_76 = F_43 ;
V_18 -> V_74 = V_74 ;
V_18 -> V_13 = V_13 ;
V_18 -> V_27 = V_27 ;
V_18 -> V_100 = 0 ;
F_22 ( & V_27 -> V_43 , V_38 ) ;
F_18 ( & V_18 -> V_31 , & V_27 -> V_54 ) ;
F_41 ( V_90 , & V_2 -> V_60 . V_73 ) ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
return 0 ;
}
static struct V_116 * F_57 ( void * V_66 )
{
struct V_1 * V_2 = V_66 ;
return & V_2 -> V_11 ;
}
static int F_58 ( struct V_117 * V_70 , const struct V_118 * V_119 )
{
int V_9 = 0 ;
struct V_65 * V_65 = NULL ;
struct V_1 * V_2 = NULL ;
T_2 V_120 , V_121 ;
int V_122 ;
struct V_6 * V_7 = F_59 ( V_70 ) ;
V_122 = V_70 -> V_123 -> V_124 . V_122 ;
V_120 = F_60 ( V_7 -> V_125 . V_120 ) ;
V_121 = F_60 ( V_7 -> V_125 . V_121 ) ;
F_48 ( L_14 , V_120 , V_121 ) ;
if ( V_122 > V_126 ) {
F_48 ( L_15 ) ;
return - 1 ;
}
V_65 = F_6 ( sizeof( struct V_65 ) , V_19 ) ;
if ( ! V_65 ) {
V_9 = - V_20 ;
goto V_21;
}
V_2 = F_6 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_2 ) {
V_9 = - V_20 ;
goto V_21;
}
memset ( V_65 , 0 , sizeof( struct V_65 ) ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_65 -> V_66 = ( void * ) V_2 ;
V_65 -> V_127 = F_56 ;
V_65 -> V_128 = F_54 ;
V_65 -> V_129 = F_38 ;
V_65 -> V_130 = F_57 ;
V_2 -> V_7 = V_7 ;
V_9 = F_28 ( V_2 ) ;
if ( V_9 < 0 ) {
F_35 ( L_16 ) ;
goto V_21;
}
V_2 -> V_70 = V_70 ;
V_70 -> V_131 = 1 ;
F_61 ( V_7 ) ;
F_62 ( & V_7 -> V_71 , V_132 ) ;
if ( V_121 == V_133 )
F_63 ( & V_2 -> V_11 , V_134 ) ;
else
F_63 ( & V_2 -> V_11 , V_135 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 ) {
F_35 ( L_17 ) ;
goto V_21;
}
F_64 ( V_65 ) ;
V_21:
if ( V_9 < 0 ) {
F_9 ( V_65 ) ;
if ( V_2 ) {
F_25 ( V_2 ) ;
F_9 ( V_2 ) ;
}
}
F_65 ( V_7 ) ;
F_66 ( V_70 , V_65 ) ;
return V_9 ;
}
static void F_67 ( struct V_117 * V_70 )
{
struct V_65 * V_65 ;
struct V_1 * V_2 ;
T_2 V_120 , V_121 ;
struct V_6 * V_7 ;
V_7 = F_59 ( V_70 ) ;
V_120 = F_60 ( V_7 -> V_125 . V_120 ) ;
V_121 = F_60 ( V_7 -> V_125 . V_121 ) ;
V_65 = F_68 ( V_70 ) ;
V_2 = V_65 -> V_66 ;
F_69 ( V_65 ) ;
F_25 ( V_2 ) ;
F_9 ( V_2 ) ;
V_2 = NULL ;
F_9 ( V_65 ) ;
V_65 = NULL ;
F_70 ( V_7 ) ;
}
static int F_71 ( struct V_117 * V_70 , T_4 V_136 )
{
struct V_65 * V_65 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
struct V_33 * V_34 ;
struct V_33 * V_41 ;
unsigned long V_38 ;
V_65 = F_68 ( V_70 ) ;
V_2 = V_65 -> V_66 ;
V_37 = & V_2 -> V_37 ;
if ( V_2 -> V_51 != V_52 ) {
F_35 ( L_18 ) ;
return - 1 ;
}
V_2 -> V_51 = V_99 ;
F_22 ( & V_37 -> V_44 , V_38 ) ;
F_26 (r, r_next, &rx->rx_submit_list, rx_submit_list)
{
F_23 ( & V_37 -> V_44 , V_38 ) ;
F_27 ( V_34 -> V_22 ) ;
F_22 ( & V_37 -> V_44 , V_38 ) ;
}
F_23 ( & V_37 -> V_44 , V_38 ) ;
return 0 ;
}
static int F_72 ( struct V_117 * V_70 )
{
struct V_65 * V_65 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
struct V_36 * V_37 ;
unsigned long V_38 ;
int V_137 ;
int V_48 ;
V_65 = F_68 ( V_70 ) ;
V_2 = V_65 -> V_66 ;
V_37 = & V_2 -> V_37 ;
if ( V_2 -> V_51 != V_99 ) {
F_35 ( L_19 ) ;
return - 1 ;
}
V_2 -> V_51 = V_52 ;
F_22 ( & V_37 -> V_39 , V_38 ) ;
V_137 = V_37 -> V_32 - V_59 ;
F_23 ( & V_37 -> V_39 , V_38 ) ;
if ( V_137 >= 0 ) {
for ( V_48 = 0 ; V_48 < V_137 ; V_48 ++ )
F_38 ( V_65 -> V_66 ,
V_2 -> V_56 ,
V_65 ,
V_80 ) ;
}
V_27 = & V_2 -> V_27 ;
F_22 ( & V_27 -> V_43 , V_38 ) ;
F_41 ( V_90 , & V_2 -> V_60 . V_73 ) ;
F_23 ( & V_27 -> V_43 , V_38 ) ;
return 0 ;
}
static int T_5 F_73 ( void )
{
if ( F_74 () < 0 ) {
F_35 ( L_20 ) ;
return - 1 ;
}
V_90 = F_75 ( L_21 ) ;
if ( V_90 == NULL )
return - 1 ;
V_85 = F_75 ( L_22 ) ;
if ( V_85 == NULL )
return - 1 ;
return F_76 ( & V_138 ) ;
}
static void T_6 F_77 ( void )
{
F_78 () ;
F_79 ( & V_138 ) ;
if ( V_90 ) {
F_80 ( V_90 ) ;
F_81 ( V_90 ) ;
}
if ( V_85 ) {
F_80 ( V_85 ) ;
F_81 ( V_85 ) ;
}
}
