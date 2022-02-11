int T_1 F_1 ( void )
{
V_1 = F_2 ( sizeof( struct V_2 ) , V_3 ) ;
if ( V_1 == NULL )
return - V_4 ;
V_1 -> V_5 = V_6 ;
V_1 -> V_7 = F_3 ( V_8 ) ;
if ( ! V_1 -> V_7 ) {
F_4 ( L_1 ,
V_9 ) ;
F_5 ( V_1 ) ;
return - V_4 ;
}
return 0 ;
}
void F_6 ( void )
{
F_7 (irttp->magic == TTP_MAGIC, return;) ;
F_8 ( V_1 -> V_7 , ( V_10 ) V_11 ) ;
V_1 -> V_5 = 0 ;
F_5 ( V_1 ) ;
V_1 = NULL ;
}
static inline void F_9 ( struct V_12 * V_13 , int V_14 )
{
F_10 ( & V_13 -> V_15 , V_16 + V_14 ) ;
}
static void F_11 ( unsigned long V_17 )
{
struct V_12 * V_13 = (struct V_12 * ) V_17 ;
if ( ! V_13 || V_13 -> V_5 != V_18 )
return;
F_12 ( L_2 , V_9 , V_13 ) ;
F_13 ( V_13 ) ;
F_14 ( V_13 ) ;
if ( F_15 ( 0 , & V_13 -> V_19 ) ) {
if ( F_16 ( & V_13 -> V_20 ) ) {
F_17 ( 0 , & V_13 -> V_19 ) ;
F_18 ( V_13 , V_13 -> V_21 ,
V_22 ) ;
V_13 -> V_21 = NULL ;
} else {
F_9 ( V_13 , V_23 / 10 ) ;
return;
}
}
if ( V_13 -> V_24 )
F_19 ( V_13 ) ;
}
static void F_20 ( struct V_12 * V_13 )
{
struct V_25 * V_26 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
while ( ( V_26 = F_21 ( & V_13 -> V_20 ) ) != NULL )
F_22 ( V_26 ) ;
while ( ( V_26 = F_21 ( & V_13 -> V_27 ) ) != NULL )
F_22 ( V_26 ) ;
while ( ( V_26 = F_21 ( & V_13 -> V_28 ) ) != NULL )
F_22 ( V_26 ) ;
}
static struct V_25 * F_23 ( struct V_12 * V_13 )
{
struct V_25 * V_26 , * V_29 ;
int V_30 = 0 ;
F_7 (self != NULL, return NULL;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return NULL;) ;
F_12 ( L_3 , V_9 ,
V_13 -> V_31 ) ;
V_26 = F_24 ( V_32 + V_13 -> V_31 ) ;
if ( ! V_26 )
return NULL ;
F_25 ( V_26 , V_32 ) ;
F_26 ( V_26 , V_13 -> V_31 ) ;
while ( ( V_29 = F_21 ( & V_13 -> V_28 ) ) != NULL ) {
F_27 ( V_26 , V_30 , V_29 -> V_17 , V_29 -> V_33 ) ;
V_30 += V_29 -> V_33 ;
F_22 ( V_29 ) ;
}
F_12 ( L_4 ,
V_9 , V_30 , V_13 -> V_31 , V_13 -> V_34 ) ;
F_7 (n <= self->rx_sdu_size, n = self->rx_sdu_size;) ;
F_28 ( V_26 , V_30 ) ;
V_13 -> V_31 = 0 ;
return V_26 ;
}
static inline void F_29 ( struct V_12 * V_13 ,
struct V_25 * V_26 )
{
struct V_25 * V_29 ;
T_2 * V_35 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
F_7 (skb != NULL, return;) ;
while ( V_26 -> V_33 > V_13 -> V_36 ) {
F_12 ( L_5 , V_9 ) ;
V_29 = F_30 ( V_13 -> V_36 + V_13 -> V_37 ,
V_38 ) ;
if ( ! V_29 )
return;
F_25 ( V_29 , V_13 -> V_37 ) ;
F_31 ( V_26 , F_26 ( V_29 , V_13 -> V_36 ) ,
V_13 -> V_36 ) ;
V_35 = F_32 ( V_29 , V_32 ) ;
V_35 [ 0 ] = V_39 ;
F_33 ( V_26 , V_13 -> V_36 ) ;
F_34 ( & V_13 -> V_20 , V_29 ) ;
}
F_12 ( L_6 , V_9 ) ;
V_35 = F_32 ( V_26 , V_32 ) ;
V_35 [ 0 ] = 0x00 ;
F_34 ( & V_13 -> V_20 , V_26 ) ;
}
static int F_35 ( void * V_40 , T_3 * V_41 ,
int V_42 )
{
struct V_12 * V_13 ;
V_13 = V_40 ;
F_7 (self != NULL, return -1;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return -1;) ;
if ( V_42 )
V_41 -> V_43 . V_44 = V_13 -> V_45 ;
else
V_13 -> V_45 = V_41 -> V_43 . V_44 ;
F_12 ( L_7 , V_9 , V_41 -> V_43 . V_44 ) ;
return 0 ;
}
static void F_36 ( struct V_12 * V_46 )
{
F_37 ( & V_46 -> V_47 ) ;
F_38 ( & V_46 -> V_15 ) ;
F_39 ( & V_46 -> V_27 ) ;
F_39 ( & V_46 -> V_20 ) ;
F_39 ( & V_46 -> V_28 ) ;
}
struct V_12 * F_40 ( T_2 V_48 , int V_49 , T_4 * V_50 )
{
struct V_12 * V_13 ;
struct V_51 * V_52 ;
T_4 V_53 ;
F_7 (irttp->magic == TTP_MAGIC, return NULL;) ;
if ( ( V_48 != V_54 ) &&
( ( V_48 < 0x01 ) || ( V_48 >= 0x70 ) ) ) {
F_12 ( L_8 , V_9 ) ;
return NULL ;
}
V_13 = F_2 ( sizeof( struct V_12 ) , V_38 ) ;
if ( V_13 == NULL )
return NULL ;
F_36 ( V_13 ) ;
V_13 -> V_15 . V_17 = ( unsigned long ) V_13 ;
V_13 -> V_15 . V_55 = & F_11 ;
F_41 ( & V_53 ) ;
V_53 . V_56 = V_57 ;
V_53 . V_58 = V_59 ;
V_53 . V_60 = V_61 ;
V_53 . V_62 = V_63 ;
V_53 . V_64 = V_65 ;
V_53 . V_66 = V_67 ;
if ( V_50 -> V_68 != NULL )
V_53 . V_68 = V_69 ;
V_53 . V_40 = V_13 ;
strncpy ( V_53 . V_70 , V_50 -> V_70 , V_71 ) ;
V_13 -> V_5 = V_18 ;
V_13 -> V_72 = FALSE ;
V_52 = F_42 ( V_48 , & V_53 , 0 ) ;
if ( V_52 == NULL ) {
F_12 ( L_9 , V_9 ) ;
V_11 ( V_13 ) ;
return NULL ;
}
V_13 -> V_48 = V_52 -> V_73 ;
F_12 ( L_10 , V_9 , V_13 -> V_48 ) ;
V_13 -> V_50 = * V_50 ;
V_13 -> V_52 = V_52 ;
F_43 ( V_1 -> V_7 , ( V_74 * ) V_13 , ( long ) V_13 , NULL ) ;
if ( V_49 > V_75 )
V_13 -> V_76 = V_75 ;
else
V_13 -> V_76 = V_49 ;
return V_13 ;
}
static void V_11 ( struct V_12 * V_13 )
{
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
F_20 ( V_13 ) ;
F_44 ( & V_13 -> V_15 ) ;
if ( V_13 -> V_21 )
F_22 ( V_13 -> V_21 ) ;
V_13 -> V_72 = FALSE ;
V_13 -> V_5 = ~ V_18 ;
F_5 ( V_13 ) ;
}
int F_19 ( struct V_12 * V_13 )
{
struct V_12 * V_46 ;
F_7 (self != NULL, return -1;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return -1;) ;
if ( V_13 -> V_72 ) {
if ( ! F_15 ( 0 , & V_13 -> V_19 ) ) {
F_45 ( L_11 ,
V_9 ) ;
F_18 ( V_13 , NULL , V_22 ) ;
}
V_13 -> V_24 = TRUE ;
F_9 ( V_13 , V_23 / 10 ) ;
return 0 ;
}
V_46 = F_46 ( V_1 -> V_7 , ( long ) V_13 , NULL ) ;
F_7 (tsap == self, return -1;) ;
if ( V_13 -> V_52 ) {
F_47 ( V_13 -> V_52 ) ;
V_13 -> V_52 = NULL ;
}
V_11 ( V_13 ) ;
return 0 ;
}
int F_48 ( struct V_12 * V_13 , struct V_25 * V_26 )
{
int V_77 ;
F_7 (self != NULL, return -1;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return -1;) ;
F_7 (skb != NULL, return -1;) ;
if ( V_26 -> V_33 == 0 ) {
V_77 = 0 ;
goto V_78;
}
if ( ! V_13 -> V_72 ) {
F_45 ( L_12 , V_9 ) ;
V_77 = - V_79 ;
goto V_78;
}
if ( V_26 -> V_33 > V_13 -> V_36 ) {
F_4 ( L_13 ,
V_9 ) ;
V_77 = - V_80 ;
goto V_78;
}
F_49 ( V_13 -> V_52 , V_26 ) ;
V_13 -> V_81 . V_82 ++ ;
return 0 ;
V_78:
F_22 ( V_26 ) ;
return V_77 ;
}
int F_50 ( struct V_12 * V_13 , struct V_25 * V_26 )
{
T_2 * V_35 ;
int V_77 ;
F_7 (self != NULL, return -1;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return -1;) ;
F_7 (skb != NULL, return -1;) ;
F_12 ( L_14 , V_9 ,
F_51 ( & V_13 -> V_20 ) ) ;
if ( V_26 -> V_33 == 0 ) {
V_77 = 0 ;
goto V_78;
}
if ( ! V_13 -> V_72 ) {
F_45 ( L_15 , V_9 ) ;
V_77 = - V_79 ;
goto V_78;
}
if ( ( V_13 -> V_45 == 0 ) && ( V_26 -> V_33 > V_13 -> V_36 ) ) {
F_4 ( L_16 ,
V_9 ) ;
V_77 = - V_80 ;
goto V_78;
}
if ( ( V_13 -> V_45 != 0 ) &&
( V_13 -> V_45 != V_83 ) &&
( V_26 -> V_33 > V_13 -> V_45 ) ) {
F_4 ( L_17 ,
V_9 ) ;
V_77 = - V_80 ;
goto V_78;
}
if ( F_51 ( & V_13 -> V_20 ) >= V_84 ) {
F_14 ( V_13 ) ;
V_77 = - V_85 ;
goto V_78;
}
if ( ( V_13 -> V_45 == 0 ) || ( V_26 -> V_33 < V_13 -> V_36 ) ) {
F_7 (skb_headroom(skb) >= TTP_HEADER, return -1;) ;
V_35 = F_32 ( V_26 , V_32 ) ;
V_35 [ 0 ] = 0x00 ;
F_34 ( & V_13 -> V_20 , V_26 ) ;
} else {
F_29 ( V_13 , V_26 ) ;
}
if ( ( ! V_13 -> V_86 ) &&
( F_51 ( & V_13 -> V_20 ) > V_87 ) ) {
if ( V_13 -> V_50 . V_66 ) {
V_13 -> V_50 . V_66 ( V_13 -> V_50 . V_40 ,
V_13 , V_88 ) ;
}
V_13 -> V_86 = TRUE ;
}
F_14 ( V_13 ) ;
return 0 ;
V_78:
F_22 ( V_26 ) ;
return V_77 ;
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_25 * V_26 ;
unsigned long V_89 ;
int V_30 ;
F_12 ( L_18 ,
V_9 ,
V_13 -> V_90 , F_51 ( & V_13 -> V_20 ) ) ;
if ( F_52 ( & V_13 -> V_91 ) == FALSE )
return;
while ( ( V_13 -> V_90 > 0 ) &&
( ! F_53 ( V_13 -> V_52 ) ) &&
( V_26 = F_21 ( & V_13 -> V_20 ) ) ) {
F_54 ( & V_13 -> V_47 , V_89 ) ;
V_30 = V_13 -> V_92 ;
V_13 -> V_92 = 0 ;
if ( V_30 > 127 ) {
V_13 -> V_92 = V_30 - 127 ;
V_30 = 127 ;
}
V_13 -> V_93 += V_30 ;
V_13 -> V_90 -- ;
F_55 ( & V_13 -> V_47 , V_89 ) ;
V_26 -> V_17 [ 0 ] |= ( V_30 & 0x7f ) ;
if ( V_26 -> V_94 != NULL ) {
F_56 ( V_26 ) ;
}
F_57 ( V_13 -> V_52 , V_26 ) ;
V_13 -> V_81 . V_82 ++ ;
}
if ( ( V_13 -> V_86 ) &&
( F_51 ( & V_13 -> V_20 ) < V_95 ) &&
( ! V_13 -> V_24 ) ) {
if ( V_13 -> V_50 . V_66 )
V_13 -> V_50 . V_66 ( V_13 -> V_50 . V_40 ,
V_13 , V_96 ) ;
V_13 -> V_86 = FALSE ;
}
V_13 -> V_91 = 0 ;
}
static inline void F_58 ( struct V_12 * V_13 )
{
struct V_25 * V_97 = NULL ;
unsigned long V_89 ;
int V_30 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
F_12 ( L_19 ,
V_9 ,
V_13 -> V_90 , V_13 -> V_92 , V_13 -> V_93 ) ;
V_97 = F_30 ( V_98 , V_38 ) ;
if ( ! V_97 )
return;
F_25 ( V_97 , V_99 ) ;
F_54 ( & V_13 -> V_47 , V_89 ) ;
V_30 = V_13 -> V_92 ;
V_13 -> V_92 = 0 ;
if ( V_30 > 127 ) {
V_13 -> V_92 = V_30 - 127 ;
V_30 = 127 ;
}
V_13 -> V_93 += V_30 ;
F_55 ( & V_13 -> V_47 , V_89 ) ;
F_26 ( V_97 , 1 ) ;
V_97 -> V_17 [ 0 ] = ( T_2 ) ( V_30 & 0x7f ) ;
F_57 ( V_13 -> V_52 , V_97 ) ;
V_13 -> V_81 . V_82 ++ ;
}
static int V_65 ( void * V_40 , void * V_100 ,
struct V_25 * V_26 )
{
struct V_12 * V_13 ;
int V_78 ;
V_13 = V_40 ;
F_7 (self != NULL, return -1;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return -1;) ;
F_7 (skb != NULL, return -1;) ;
V_13 -> V_81 . V_101 ++ ;
if ( V_13 -> V_50 . V_64 ) {
V_78 = V_13 -> V_50 . V_64 ( V_13 -> V_50 . V_40 ,
V_13 , V_26 ) ;
if ( ! V_78 )
return 0 ;
}
F_22 ( V_26 ) ;
return 0 ;
}
static int V_63 ( void * V_40 , void * V_100 ,
struct V_25 * V_26 )
{
struct V_12 * V_13 ;
unsigned long V_89 ;
int V_30 ;
V_13 = V_40 ;
V_30 = V_26 -> V_17 [ 0 ] & 0x7f ;
V_13 -> V_81 . V_101 ++ ;
F_54 ( & V_13 -> V_47 , V_89 ) ;
V_13 -> V_90 += V_30 ;
if ( V_26 -> V_33 > 1 )
V_13 -> V_93 -- ;
F_55 ( & V_13 -> V_47 , V_89 ) ;
if ( V_26 -> V_33 > 1 ) {
F_34 ( & V_13 -> V_27 , V_26 ) ;
} else {
F_22 ( V_26 ) ;
}
F_13 ( V_13 ) ;
if ( V_13 -> V_90 == V_30 ) {
F_14 ( V_13 ) ;
}
return 0 ;
}
static void V_69 ( void * V_40 ,
T_5 V_102 , T_6 V_47 )
{
struct V_12 * V_13 ;
V_13 = V_40 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
if ( V_13 -> V_24 )
return;
if ( V_13 -> V_50 . V_68 != NULL )
V_13 -> V_50 . V_68 ( V_13 -> V_50 . V_40 ,
V_102 , V_47 ) ;
else
F_12 ( L_20 , V_9 ) ;
}
static void V_67 ( void * V_40 , void * V_100 , T_7 V_103 )
{
struct V_12 * V_13 ;
V_13 = V_40 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
F_12 ( L_2 , V_9 , V_13 ) ;
F_14 ( V_13 ) ;
if ( V_13 -> V_19 )
F_9 ( V_13 , 0 ) ;
}
void F_59 ( struct V_12 * V_13 , T_7 V_103 )
{
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
switch ( V_103 ) {
case V_88 :
F_12 ( L_21 , V_9 ) ;
V_13 -> V_104 = TRUE ;
break;
case V_96 :
F_12 ( L_22 , V_9 ) ;
V_13 -> V_104 = FALSE ;
F_13 ( V_13 ) ;
break;
default:
F_12 ( L_23 , V_9 ) ;
}
}
int F_60 ( struct V_12 * V_13 , T_2 V_105 ,
T_8 V_106 , T_8 V_107 ,
struct V_108 * V_109 , T_8 V_110 ,
struct V_25 * V_111 )
{
struct V_25 * V_97 ;
T_2 * V_35 ;
T_2 V_30 ;
F_12 ( L_24 , V_9 , V_110 ) ;
F_7 (self != NULL, return -EBADR;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return -EBADR;) ;
if ( V_13 -> V_72 ) {
if ( V_111 )
F_22 ( V_111 ) ;
return - V_112 ;
}
if ( V_111 == NULL ) {
V_97 = F_30 ( V_98 + V_113 ,
V_38 ) ;
if ( ! V_97 )
return - V_4 ;
F_25 ( V_97 , V_98 + V_113 ) ;
} else {
V_97 = V_111 ;
F_7 (skb_headroom(userdata) >= TTP_MAX_HEADER,
{ dev_kfree_skb(userdata); return -1; }) ;
}
V_13 -> V_72 = FALSE ;
V_13 -> V_92 = 0 ;
V_13 -> V_34 = V_110 ;
V_13 -> V_31 = 0 ;
V_13 -> V_104 = FALSE ;
V_13 -> V_105 = V_105 ;
V_30 = V_13 -> V_76 ;
V_13 -> V_93 = 0 ;
V_13 -> V_90 = 0 ;
if ( V_30 > 127 ) {
V_13 -> V_92 = V_30 - 127 ;
V_30 = 127 ;
}
V_13 -> V_93 = V_30 ;
if ( V_110 > 0 ) {
F_7 (skb_headroom(tx_skb) >= (TTP_MAX_HEADER + TTP_SAR_HEADER),
{ dev_kfree_skb(tx_skb); return -1; }) ;
V_35 = F_32 ( V_97 , V_32 + V_113 ) ;
V_35 [ 0 ] = V_114 | V_30 ;
V_35 [ 1 ] = 0x04 ;
V_35 [ 2 ] = 0x01 ;
V_35 [ 3 ] = 0x02 ;
F_61 ( F_62 ( ( V_115 ) V_110 ) ,
( V_116 * ) ( V_35 + 4 ) ) ;
} else {
V_35 = F_32 ( V_97 , V_32 ) ;
V_35 [ 0 ] = V_30 & 0x7f ;
}
return F_63 ( V_13 -> V_52 , V_105 , V_106 , V_107 , V_109 ,
V_97 ) ;
}
static void V_57 ( void * V_40 , void * V_100 ,
struct V_108 * V_109 , T_8 V_36 ,
T_2 V_37 , struct V_25 * V_26 )
{
struct V_12 * V_13 ;
int V_117 ;
int V_77 ;
T_2 V_118 ;
T_2 V_30 ;
V_13 = V_40 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
F_7 (skb != NULL, return;) ;
V_13 -> V_36 = V_36 - V_32 ;
V_13 -> V_37 = V_37 + V_32 ;
if ( V_109 ) {
F_12 ( L_25 ,
V_109 -> V_119 . V_120 ) ;
F_12 ( L_26 ,
V_109 -> V_119 . V_121 ) ;
}
V_30 = V_26 -> V_17 [ 0 ] & 0x7f ;
F_12 ( L_27 , V_9 , V_30 ) ;
V_13 -> V_90 = V_30 ;
V_13 -> V_45 = 0 ;
V_13 -> V_72 = TRUE ;
V_117 = V_26 -> V_17 [ 0 ] & 0x80 ;
F_7 (skb->len >= TTP_HEADER, return;) ;
F_33 ( V_26 , V_32 ) ;
if ( V_117 ) {
V_118 = V_26 -> V_17 [ 0 ] ;
V_77 = F_64 ( V_13 , V_26 -> V_17 + 1 ,
F_65 ( V_26 -> V_33 - 1 , V_118 ) ,
& V_122 ) ;
if ( V_77 < 0 ) {
F_45 ( L_28 ,
V_9 ) ;
F_22 ( V_26 ) ;
return;
}
F_33 ( V_26 , F_65 ( V_26 -> V_33 , V_118 + 1 ) ) ;
}
F_12 ( L_19 , V_9 ,
V_13 -> V_90 , V_13 -> V_92 , V_13 -> V_93 ) ;
F_12 ( L_7 , V_9 ,
V_13 -> V_45 ) ;
if ( V_13 -> V_50 . V_56 ) {
V_13 -> V_50 . V_56 ( V_13 -> V_50 . V_40 , V_13 , V_109 ,
V_13 -> V_45 ,
V_13 -> V_37 , V_26 ) ;
} else
F_22 ( V_26 ) ;
}
static void V_59 ( void * V_40 , void * V_100 ,
struct V_108 * V_109 , T_8 V_36 , T_2 V_37 ,
struct V_25 * V_26 )
{
struct V_12 * V_13 ;
struct V_51 * V_52 ;
int V_117 ;
int V_77 ;
T_2 V_118 ;
T_2 V_30 ;
V_13 = V_40 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
F_7 (skb != NULL, return;) ;
V_52 = V_100 ;
V_13 -> V_36 = V_36 - V_32 ;
V_13 -> V_37 = V_37 + V_32 ;
F_12 ( L_29 , V_9 , V_13 -> V_48 ) ;
V_13 -> V_105 = V_52 -> V_123 ;
V_30 = V_26 -> V_17 [ 0 ] & 0x7f ;
V_13 -> V_90 = V_30 ;
V_13 -> V_45 = 0 ;
V_117 = V_26 -> V_17 [ 0 ] & 0x80 ;
F_7 (skb->len >= TTP_HEADER, return;) ;
F_33 ( V_26 , V_32 ) ;
if ( V_117 ) {
V_118 = V_26 -> V_17 [ 0 ] ;
V_77 = F_64 ( V_13 , V_26 -> V_17 + 1 ,
F_65 ( V_26 -> V_33 - 1 , V_118 ) ,
& V_122 ) ;
if ( V_77 < 0 ) {
F_45 ( L_28 ,
V_9 ) ;
F_22 ( V_26 ) ;
return;
}
F_33 ( V_26 , F_65 ( V_26 -> V_33 , V_118 + 1 ) ) ;
}
if ( V_13 -> V_50 . V_58 ) {
V_13 -> V_50 . V_58 ( V_13 -> V_50 . V_40 , V_13 ,
V_109 , V_13 -> V_45 ,
V_13 -> V_37 , V_26 ) ;
} else
F_22 ( V_26 ) ;
}
int F_66 ( struct V_12 * V_13 , T_8 V_110 ,
struct V_25 * V_111 )
{
struct V_25 * V_97 ;
T_2 * V_35 ;
int V_77 ;
T_2 V_30 ;
F_7 (self != NULL, return -1;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return -1;) ;
F_12 ( L_30 , V_9 ,
V_13 -> V_48 ) ;
if ( V_111 == NULL ) {
V_97 = F_30 ( V_98 + V_113 ,
V_38 ) ;
if ( ! V_97 )
return - V_4 ;
F_25 ( V_97 , V_98 + V_113 ) ;
} else {
V_97 = V_111 ;
F_7 (skb_headroom(userdata) >= TTP_MAX_HEADER,
{ dev_kfree_skb(userdata); return -1; }) ;
}
V_13 -> V_92 = 0 ;
V_13 -> V_93 = 0 ;
V_13 -> V_34 = V_110 ;
V_13 -> V_31 = 0 ;
V_13 -> V_104 = FALSE ;
V_30 = V_13 -> V_76 ;
if ( V_30 > 127 ) {
V_13 -> V_92 = V_30 - 127 ;
V_30 = 127 ;
}
V_13 -> V_93 = V_30 ;
V_13 -> V_72 = TRUE ;
if ( V_110 > 0 ) {
F_7 (skb_headroom(tx_skb) >= (TTP_MAX_HEADER + TTP_SAR_HEADER),
{ dev_kfree_skb(tx_skb); return -1; }) ;
V_35 = F_32 ( V_97 , V_32 + V_113 ) ;
V_35 [ 0 ] = V_114 | V_30 ;
V_35 [ 1 ] = 0x04 ;
V_35 [ 2 ] = 0x01 ;
V_35 [ 3 ] = 0x02 ;
F_61 ( F_62 ( ( V_115 ) V_110 ) ,
( V_116 * ) ( V_35 + 4 ) ) ;
} else {
V_35 = F_32 ( V_97 , V_32 ) ;
V_35 [ 0 ] = V_30 & 0x7f ;
}
V_77 = F_67 ( V_13 -> V_52 , V_97 ) ;
return V_77 ;
}
struct V_12 * F_68 ( struct V_12 * V_124 , void * V_40 )
{
struct V_12 * V_125 ;
unsigned long V_89 ;
F_54 ( & V_1 -> V_7 -> V_126 , V_89 ) ;
if ( ! F_69 ( V_1 -> V_7 , ( long ) V_124 , NULL ) ) {
F_12 ( L_31 , V_9 ) ;
F_55 ( & V_1 -> V_7 -> V_126 , V_89 ) ;
return NULL ;
}
V_125 = F_70 ( V_124 , sizeof( struct V_12 ) , V_38 ) ;
if ( ! V_125 ) {
F_12 ( L_32 , V_9 ) ;
F_55 ( & V_1 -> V_7 -> V_126 , V_89 ) ;
return NULL ;
}
F_37 ( & V_125 -> V_47 ) ;
F_55 ( & V_1 -> V_7 -> V_126 , V_89 ) ;
V_125 -> V_52 = F_71 ( V_124 -> V_52 , V_125 ) ;
if ( ! V_125 -> V_52 ) {
F_12 ( L_33 , V_9 ) ;
F_5 ( V_125 ) ;
return NULL ;
}
V_125 -> V_50 . V_40 = V_40 ;
F_36 ( V_125 ) ;
F_43 ( V_1 -> V_7 , ( V_74 * ) V_125 , ( long ) V_125 , NULL ) ;
return V_125 ;
}
int F_18 ( struct V_12 * V_13 , struct V_25 * V_111 ,
int V_127 )
{
int V_77 ;
F_7 (self != NULL, return -1;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return -1;) ;
if ( ! V_13 -> V_72 ) {
F_12 ( L_34 , V_9 ) ;
if ( V_111 )
F_22 ( V_111 ) ;
return - 1 ;
}
if ( F_72 ( 0 , & V_13 -> V_19 ) ) {
F_12 ( L_35 ,
V_9 ) ;
if ( V_111 )
F_22 ( V_111 ) ;
F_14 ( V_13 ) ;
return - 1 ;
}
if ( ! F_16 ( & V_13 -> V_20 ) ) {
if ( V_127 == V_128 ) {
F_12 ( L_36 , V_9 ) ;
F_20 ( V_13 ) ;
} else if ( V_127 == V_22 ) {
V_13 -> V_21 = V_111 ;
F_14 ( V_13 ) ;
F_9 ( V_13 , V_23 / 10 ) ;
return - 1 ;
}
}
F_12 ( L_37 , V_9 ) ;
V_13 -> V_72 = FALSE ;
if ( ! V_111 ) {
struct V_25 * V_97 ;
V_97 = F_30 ( V_99 , V_38 ) ;
if ( ! V_97 )
return - V_4 ;
F_25 ( V_97 , V_99 ) ;
V_111 = V_97 ;
}
V_77 = F_73 ( V_13 -> V_52 , V_111 ) ;
F_17 ( 0 , & V_13 -> V_19 ) ;
return V_77 ;
}
static void V_61 ( void * V_40 , void * V_100 ,
T_9 V_129 , struct V_25 * V_26 )
{
struct V_12 * V_13 ;
V_13 = V_40 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == TTP_TSAP_MAGIC, return;) ;
V_13 -> V_72 = FALSE ;
if ( V_13 -> V_24 ) {
if ( V_26 )
F_22 ( V_26 ) ;
F_19 ( V_13 ) ;
return;
}
if ( V_13 -> V_50 . V_60 )
V_13 -> V_50 . V_60 ( V_13 -> V_50 . V_40 , V_13 ,
V_129 , V_26 ) ;
else
if ( V_26 )
F_22 ( V_26 ) ;
}
static void F_74 ( struct V_12 * V_13 , struct V_25 * V_26 )
{
int V_78 ;
if ( V_13 -> V_24 ) {
F_22 ( V_26 ) ;
return;
}
V_78 = V_13 -> V_50 . V_62 ( V_13 -> V_50 . V_40 , V_13 , V_26 ) ;
if ( V_78 ) {
F_12 ( L_38 , V_9 ) ;
V_13 -> V_104 = TRUE ;
F_32 ( V_26 , V_32 ) ;
V_26 -> V_17 [ 0 ] = 0x00 ;
F_75 ( & V_13 -> V_27 , V_26 ) ;
}
}
static void F_13 ( struct V_12 * V_13 )
{
struct V_25 * V_26 ;
int V_130 = 0 ;
F_12 ( L_19 , V_9 ,
V_13 -> V_90 , V_13 -> V_92 , V_13 -> V_93 ) ;
if ( F_52 ( & V_13 -> V_131 ) == FALSE )
return;
while ( ! V_13 -> V_104 && ( V_26 = F_21 ( & V_13 -> V_27 ) ) ) {
V_130 = V_26 -> V_17 [ 0 ] & 0x80 ;
F_33 ( V_26 , V_32 ) ;
V_13 -> V_31 += V_26 -> V_33 ;
if ( V_13 -> V_34 == V_132 ) {
F_74 ( V_13 , V_26 ) ;
V_13 -> V_31 = 0 ;
continue;
}
if ( V_130 ) {
if ( V_13 -> V_31 <= V_13 -> V_34 ) {
F_12 ( L_39 ,
V_9 ) ;
F_34 ( & V_13 -> V_28 , V_26 ) ;
} else {
F_22 ( V_26 ) ;
}
continue;
}
if ( ( V_13 -> V_31 <= V_13 -> V_34 ) ||
( V_13 -> V_34 == V_83 ) ) {
if ( ! F_16 ( & V_13 -> V_28 ) ) {
F_34 ( & V_13 -> V_28 ,
V_26 ) ;
V_26 = F_23 ( V_13 ) ;
}
F_74 ( V_13 , V_26 ) ;
} else {
F_12 ( L_40 , V_9 ) ;
F_22 ( V_26 ) ;
V_26 = F_23 ( V_13 ) ;
F_74 ( V_13 , V_26 ) ;
}
V_13 -> V_31 = 0 ;
}
V_13 -> V_92 = ( V_13 -> V_76 -
( V_13 -> V_93 +
F_51 ( & V_13 -> V_27 ) +
F_51 ( & V_13 -> V_28 ) ) ) ;
if ( ( V_13 -> V_93 <= V_133 ) &&
( V_13 -> V_92 > 0 ) ) {
F_58 ( V_13 ) ;
}
V_13 -> V_131 = 0 ;
}
static void * F_76 ( struct V_134 * V_135 , T_10 * V_136 )
{
struct V_137 * V_138 = V_135 -> V_139 ;
struct V_12 * V_13 ;
F_77 ( & V_1 -> V_7 -> V_126 ) ;
V_138 -> V_140 = 0 ;
for ( V_13 = (struct V_12 * ) F_78 ( V_1 -> V_7 ) ;
V_13 != NULL ;
V_13 = (struct V_12 * ) F_79 ( V_1 -> V_7 ) ) {
if ( V_138 -> V_140 == * V_136 )
break;
++ V_138 -> V_140 ;
}
return V_13 ;
}
static void * F_80 ( struct V_134 * V_135 , void * V_141 , T_10 * V_136 )
{
struct V_137 * V_138 = V_135 -> V_139 ;
++ * V_136 ;
++ V_138 -> V_140 ;
return ( void * ) F_79 ( V_1 -> V_7 ) ;
}
static void F_81 ( struct V_134 * V_135 , void * V_141 )
{
F_82 ( & V_1 -> V_7 -> V_126 ) ;
}
static int F_83 ( struct V_134 * V_135 , void * V_141 )
{
const struct V_137 * V_138 = V_135 -> V_139 ;
const struct V_12 * V_13 = V_141 ;
F_84 ( V_135 , L_41 , V_138 -> V_140 ) ;
F_84 ( V_135 , L_42 ,
V_13 -> V_48 ) ;
F_84 ( V_135 , L_43 ,
V_13 -> V_105 ) ;
F_84 ( V_135 , L_44 ,
V_13 -> V_72 ? L_45 : L_46 ) ;
F_84 ( V_135 , L_47 ,
V_13 -> V_92 ) ;
F_84 ( V_135 , L_48 ,
V_13 -> V_93 ) ;
F_84 ( V_135 , L_49 ,
V_13 -> V_90 ) ;
F_84 ( V_135 , L_50 ,
V_13 -> V_81 . V_82 ) ;
F_84 ( V_135 , L_51 ,
V_13 -> V_81 . V_101 ) ;
F_84 ( V_135 , L_52 ,
F_51 ( & V_13 -> V_20 ) ) ;
F_84 ( V_135 , L_53 ,
F_51 ( & V_13 -> V_27 ) ) ;
F_84 ( V_135 , L_54 ,
V_13 -> V_86 ? L_45 : L_46 ) ;
F_84 ( V_135 , L_55 ,
V_13 -> V_104 ? L_45 : L_46 ) ;
F_84 ( V_135 , L_56 ,
V_13 -> V_36 ) ;
F_84 ( V_135 , L_57 ,
V_13 -> V_45 ) ;
F_84 ( V_135 , L_58 ,
V_13 -> V_34 ) ;
F_84 ( V_135 , L_59 ,
V_13 -> V_50 . V_70 ) ;
return 0 ;
}
static int F_85 ( struct V_142 * V_142 , struct V_143 * V_143 )
{
return F_86 ( V_143 , & V_144 ,
sizeof( struct V_137 ) ) ;
}
