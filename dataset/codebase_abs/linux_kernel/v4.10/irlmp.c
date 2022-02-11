const char * F_1 ( T_1 V_1 )
{
V_1 = F_2 ( V_2 , V_1 , F_3 ( V_3 ) - 1 ) ;
return V_3 [ V_1 ] ;
}
int T_2 F_4 ( void )
{
V_4 = F_5 ( sizeof( struct V_5 ) , V_6 ) ;
if ( V_4 == NULL )
return - V_7 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = F_6 ( V_11 ) ;
V_4 -> V_12 = F_6 ( V_11 ) ;
V_4 -> V_13 = F_6 ( V_11 ) ;
V_4 -> V_14 = F_6 ( V_11 ) ;
V_4 -> V_15 = F_6 ( V_16 ) ;
if ( ( V_4 -> V_10 == NULL ) ||
( V_4 -> V_12 == NULL ) ||
( V_4 -> V_13 == NULL ) ||
( V_4 -> V_14 == NULL ) ||
( V_4 -> V_15 == NULL ) ) {
return - V_7 ;
}
F_7 ( & V_4 -> V_15 -> V_17 ) ;
V_4 -> V_18 = 0x0f ;
strcpy ( V_19 , L_1 ) ;
F_8 ( & V_4 -> V_20 ) ;
if ( V_21 )
F_9 ( V_4 ,
V_22 * V_23 ) ;
return 0 ;
}
void F_10 ( void )
{
F_11 (irlmp != NULL, return;) ;
F_11 (irlmp->magic == LMP_MAGIC, return;) ;
F_12 ( & V_4 -> V_20 ) ;
F_13 ( V_4 -> V_13 , ( V_24 ) V_25 ) ;
F_13 ( V_4 -> V_14 , ( V_24 ) V_25 ) ;
F_13 ( V_4 -> V_10 , ( V_24 ) V_25 ) ;
F_13 ( V_4 -> V_12 , ( V_24 ) V_25 ) ;
F_13 ( V_4 -> V_15 , ( V_24 ) V_25 ) ;
V_25 ( V_4 ) ;
V_4 = NULL ;
}
struct V_26 * F_14 ( T_3 V_27 , T_4 * V_28 , T_3 V_29 )
{
struct V_26 * V_30 ;
F_11 (notify != NULL, return NULL;) ;
F_11 (irlmp != NULL, return NULL;) ;
F_11 (irlmp->magic == LMP_MAGIC, return NULL;) ;
F_11 (notify->instance != NULL, return NULL;) ;
if ( V_27 == V_31 ) {
V_27 = F_15 () ;
if ( ! V_27 )
return NULL ;
} else if ( F_16 ( V_27 ) )
return NULL ;
V_30 = F_5 ( sizeof( struct V_26 ) , V_32 ) ;
if ( V_30 == NULL )
return NULL ;
V_30 -> V_8 = V_33 ;
V_30 -> V_27 = V_27 ;
if ( V_27 == V_34 ) {
#ifdef F_17
V_30 -> V_35 = V_34 ;
V_30 -> V_29 = V_29 ;
#endif
} else
V_30 -> V_35 = V_31 ;
F_8 ( & V_30 -> V_36 ) ;
V_30 -> V_28 = * V_28 ;
V_30 -> V_37 = V_38 ;
F_18 ( V_4 -> V_14 , ( V_39 * ) V_30 ,
( long ) V_30 , NULL ) ;
return V_30 ;
}
static void F_19 ( struct V_26 * V_30 )
{
F_11 (self != NULL, return;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return;) ;
V_30 -> V_8 = 0 ;
F_12 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_40 )
F_20 ( V_30 -> V_40 ) ;
V_25 ( V_30 ) ;
}
void F_21 ( struct V_26 * V_30 )
{
struct V_41 * V_42 ;
struct V_26 * V_43 = NULL ;
F_11 (self != NULL, return;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return;) ;
V_42 = V_30 -> V_42 ;
if ( V_42 ) {
F_11 (lap->magic == LMP_LAP_MAGIC, return;) ;
if( V_30 -> V_37 != V_38 ) {
V_30 -> V_37 = V_38 ;
F_22 ( V_30 -> V_42 ,
V_44 , NULL ) ;
}
V_43 = F_23 ( V_42 -> V_45 , ( long ) V_30 , NULL ) ;
#ifdef F_24
V_42 -> V_46 . V_47 = FALSE ;
#endif
}
V_30 -> V_42 = NULL ;
if ( ! V_43 ) {
V_43 = F_23 ( V_4 -> V_14 , ( long ) V_30 ,
NULL ) ;
}
if ( ! V_43 ) {
F_25 ( L_2 ,
V_48 ) ;
return;
}
F_19 ( V_30 ) ;
}
void F_26 ( struct V_49 * V_50 , T_5 V_51 , T_4 * V_28 )
{
struct V_41 * V_42 ;
F_11 (irlmp != NULL, return;) ;
F_11 (irlmp->magic == LMP_MAGIC, return;) ;
F_11 (notify != NULL, return;) ;
V_42 = F_5 ( sizeof( struct V_41 ) , V_6 ) ;
if ( V_42 == NULL )
return;
V_42 -> V_50 = V_50 ;
V_42 -> V_8 = V_52 ;
V_42 -> V_51 = V_51 ;
V_42 -> V_53 = V_54 ;
#ifdef F_24
V_42 -> V_46 . V_47 = FALSE ;
#endif
V_42 -> V_45 = F_6 ( V_11 ) ;
if ( V_42 -> V_45 == NULL ) {
F_27 ( L_3 ,
V_48 ) ;
V_25 ( V_42 ) ;
return;
}
V_42 -> V_55 = V_56 ;
F_8 ( & V_42 -> V_57 ) ;
F_18 ( V_4 -> V_13 , ( V_39 * ) V_42 , V_42 -> V_51 , NULL ) ;
F_28 ( V_28 ) ;
V_28 -> V_58 = V_42 ;
}
void F_29 ( T_5 V_51 )
{
struct V_41 * V_59 ;
V_59 = F_23 ( V_4 -> V_13 , V_51 , NULL ) ;
if ( V_59 ) {
F_11 (link->magic == LMP_LAP_MAGIC, return;) ;
V_59 -> V_1 = V_60 ;
V_59 -> V_53 = V_54 ;
F_22 ( V_59 , V_61 , NULL ) ;
F_30 ( V_4 -> V_15 , V_59 -> V_51 , TRUE ) ;
F_12 ( & V_59 -> V_57 ) ;
V_59 -> V_8 = 0 ;
F_13 ( V_59 -> V_45 , ( V_24 ) F_19 ) ;
V_25 ( V_59 ) ;
}
}
int F_31 ( struct V_26 * V_30 , T_3 V_35 ,
T_5 V_51 , T_5 V_53 ,
struct V_62 * V_63 , struct V_64 * V_65 )
{
struct V_64 * V_66 = V_65 ;
struct V_41 * V_42 ;
struct V_26 * V_43 ;
int V_67 ;
F_11 (self != NULL, return -EBADR;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return -EBADR;) ;
F_25 ( L_4 ,
V_48 , V_30 -> V_27 , V_35 , V_51 , V_53 ) ;
if ( F_32 ( 0 , & V_30 -> V_68 ) ) {
V_67 = - V_69 ;
goto V_70;
}
if ( ! V_53 ) {
V_67 = - V_71 ;
goto V_70;
}
if ( V_66 == NULL ) {
V_66 = F_33 ( V_72 , V_32 ) ;
if ( ! V_66 )
return - V_7 ;
F_34 ( V_66 , V_72 ) ;
}
F_11 (skb_headroom(tx_skb) >= LMP_CONTROL_HEADER, return -1;) ;
F_35 ( V_66 , V_73 ) ;
V_30 -> V_35 = V_35 ;
if ( ( ! V_51 ) || ( V_51 == V_54 ) ) {
T_6 * V_74 ;
unsigned long V_75 ;
F_36 ( & V_4 -> V_15 -> V_17 , V_75 ) ;
if ( V_53 != V_54 )
V_74 = F_37 ( V_4 -> V_15 , V_53 , NULL ) ;
else {
F_25 ( L_5 , V_48 ) ;
V_74 = ( T_6 * )
F_38 ( V_4 -> V_15 ) ;
}
if ( V_74 ) {
V_51 = V_74 -> V_76 . V_51 ;
V_53 = V_74 -> V_76 . V_53 ;
}
F_39 ( & V_4 -> V_15 -> V_17 , V_75 ) ;
}
V_42 = F_40 ( V_4 -> V_13 , V_51 , NULL ) ;
if ( V_42 == NULL ) {
F_25 ( L_6 , V_48 ) ;
V_67 = - V_77 ;
goto V_70;
}
if ( V_42 -> V_53 == V_54 )
V_42 -> V_53 = V_53 ;
else if ( V_42 -> V_53 != V_53 ) {
if ( F_41 ( V_42 -> V_45 ) == 0 ) {
F_25 ( L_7 ,
V_48 ) ;
V_67 = - V_78 ;
goto V_70;
}
F_25 ( L_8 , V_48 ) ;
V_67 = - V_79 ;
goto V_70;
}
V_30 -> V_42 = V_42 ;
V_43 = F_23 ( V_4 -> V_14 , ( long ) V_30 , NULL ) ;
F_11 (lsap != NULL, return -1;) ;
F_11 (lsap->magic == LMP_LSAP_MAGIC, return -1;) ;
F_11 (lsap->lap != NULL, return -1;) ;
F_11 (lsap->lap->magic == LMP_LAP_MAGIC, return -1;) ;
F_18 ( V_30 -> V_42 -> V_45 , ( V_39 * ) V_30 , ( long ) V_30 ,
NULL ) ;
F_42 ( 0 , & V_30 -> V_68 ) ;
if ( V_63 )
V_30 -> V_63 = * V_63 ;
F_43 ( V_30 , V_80 , V_66 ) ;
F_20 ( V_66 ) ;
return 0 ;
V_70:
if( V_66 )
F_20 ( V_66 ) ;
return V_67 ;
}
void F_44 ( struct V_26 * V_30 , struct V_64 * V_81 )
{
int V_82 ;
int V_83 ;
int V_84 ;
F_11 (self != NULL, return;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_11 (skb != NULL, return;) ;
F_11 (self->lap != NULL, return;) ;
F_25 ( L_9 ,
V_48 , V_30 -> V_27 , V_30 -> V_35 ) ;
V_30 -> V_63 = * V_30 -> V_42 -> V_63 ;
V_82 = V_30 -> V_42 -> V_63 -> V_85 . V_86 - V_87 ;
V_83 = F_45 ( V_30 -> V_42 -> V_50 ) ;
V_84 = V_87 + V_83 ;
F_46 ( V_81 , V_73 ) ;
if ( V_30 -> V_28 . V_88 ) {
F_47 ( V_81 ) ;
V_30 -> V_28 . V_88 ( V_30 -> V_28 . V_58 , V_30 ,
& V_30 -> V_63 , V_82 ,
V_84 , V_81 ) ;
}
}
int F_48 ( struct V_26 * V_30 , struct V_64 * V_65 )
{
F_11 (self != NULL, return -1;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_11 (userdata != NULL, return -1;) ;
F_25 ( L_9 ,
V_48 , V_30 -> V_27 , V_30 -> V_35 ) ;
F_11 (skb_headroom(userdata) >= LMP_CONTROL_HEADER, return -1;) ;
F_35 ( V_65 , V_73 ) ;
F_43 ( V_30 , V_89 , V_65 ) ;
F_20 ( V_65 ) ;
return 0 ;
}
void F_49 ( struct V_26 * V_30 , struct V_64 * V_81 )
{
int V_84 ;
int V_83 ;
int V_82 ;
F_11 (skb != NULL, return;) ;
F_11 (self != NULL, return;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_11 (self->lap != NULL, return;) ;
V_30 -> V_63 = * V_30 -> V_42 -> V_63 ;
V_82 = V_30 -> V_42 -> V_63 -> V_85 . V_86 - V_87 ;
V_83 = F_45 ( V_30 -> V_42 -> V_50 ) ;
V_84 = V_87 + V_83 ;
F_25 ( L_10 ,
V_48 , V_84 ) ;
F_46 ( V_81 , V_73 ) ;
if ( V_30 -> V_28 . V_90 ) {
F_47 ( V_81 ) ;
V_30 -> V_28 . V_90 ( V_30 -> V_28 . V_58 , V_30 ,
& V_30 -> V_63 , V_82 ,
V_84 , V_81 ) ;
}
}
struct V_26 * F_50 ( struct V_26 * V_91 , void * V_58 )
{
struct V_26 * V_92 ;
unsigned long V_75 ;
F_36 ( & V_4 -> V_14 -> V_17 , V_75 ) ;
if ( ( ! F_37 ( V_4 -> V_14 , ( long ) V_91 , NULL ) ) ||
( V_91 -> V_42 == NULL ) ) {
F_25 ( L_11 ,
V_48 ) ;
F_39 ( & V_4 -> V_14 -> V_17 ,
V_75 ) ;
return NULL ;
}
V_92 = F_51 ( V_91 , sizeof( * V_92 ) , V_32 ) ;
if ( ! V_92 ) {
F_25 ( L_12 , V_48 ) ;
F_39 ( & V_4 -> V_14 -> V_17 ,
V_75 ) ;
return NULL ;
}
V_92 -> V_40 = NULL ;
F_39 ( & V_4 -> V_14 -> V_17 , V_75 ) ;
V_92 -> V_28 . V_58 = V_58 ;
F_8 ( & V_92 -> V_36 ) ;
F_18 ( V_4 -> V_14 , ( V_39 * ) V_92 ,
( long ) V_92 , NULL ) ;
#ifdef F_24
V_92 -> V_42 -> V_46 . V_47 = FALSE ;
#endif
return V_92 ;
}
int F_52 ( struct V_26 * V_30 , struct V_64 * V_65 )
{
struct V_26 * V_43 ;
F_11 (self != NULL, return -1;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_11 (userdata != NULL, return -1;) ;
if ( ! F_53 ( 0 , & V_30 -> V_68 ) ) {
F_25 ( L_13 , V_48 ) ;
F_20 ( V_65 ) ;
return - 1 ;
}
F_35 ( V_65 , V_73 ) ;
F_43 ( V_30 , V_93 , V_65 ) ;
F_20 ( V_65 ) ;
F_11 (self->lap != NULL, return -1;) ;
F_11 (self->lap->magic == LMP_LAP_MAGIC, return -1;) ;
F_11 (self->lap->lsaps != NULL, return -1;) ;
V_43 = F_23 ( V_30 -> V_42 -> V_45 , ( long ) V_30 , NULL ) ;
#ifdef F_24
V_30 -> V_42 -> V_46 . V_47 = FALSE ;
#endif
F_11 (lsap != NULL, return -1;) ;
F_11 (lsap->magic == LMP_LSAP_MAGIC, return -1;) ;
F_11 (lsap == self, return -1;) ;
F_18 ( V_4 -> V_14 , ( V_39 * ) V_30 ,
( long ) V_30 , NULL ) ;
V_30 -> V_35 = V_31 ;
V_30 -> V_42 = NULL ;
return 0 ;
}
void F_54 ( struct V_26 * V_30 , T_1 V_1 ,
struct V_64 * V_81 )
{
struct V_26 * V_43 ;
F_25 ( L_14 , V_48 ,
F_1 ( V_1 ) , V_1 ) ;
F_11 (self != NULL, return;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_25 ( L_9 ,
V_48 , V_30 -> V_27 , V_30 -> V_35 ) ;
if ( ! F_53 ( 0 , & V_30 -> V_68 ) ) {
F_25 ( L_13 , V_48 ) ;
return;
}
F_11 (self->lap != NULL, return;) ;
F_11 (self->lap->lsaps != NULL, return;) ;
V_43 = F_23 ( V_30 -> V_42 -> V_45 , ( long ) V_30 , NULL ) ;
#ifdef F_24
V_30 -> V_42 -> V_46 . V_47 = FALSE ;
#endif
F_11 (lsap != NULL, return;) ;
F_11 (lsap == self, return;) ;
F_18 ( V_4 -> V_14 , ( V_39 * ) V_43 ,
( long ) V_43 , NULL ) ;
V_30 -> V_35 = V_31 ;
V_30 -> V_42 = NULL ;
if ( V_30 -> V_28 . V_94 ) {
if( V_81 )
F_47 ( V_81 ) ;
V_30 -> V_28 . V_94 ( V_30 -> V_28 . V_58 ,
V_30 , V_1 , V_81 ) ;
} else {
F_25 ( L_15 , V_48 ) ;
}
}
void F_55 ( void )
{
struct V_41 * V_42 ;
V_42 = (struct V_41 * ) F_38 ( V_4 -> V_13 ) ;
while ( V_42 != NULL ) {
F_11 (lap->magic == LMP_LAP_MAGIC, return;) ;
if ( V_42 -> V_55 == V_56 ) {
F_30 ( V_4 -> V_15 , V_42 -> V_51 ,
FALSE ) ;
}
V_42 = (struct V_41 * ) F_56 ( V_4 -> V_13 ) ;
}
}
void F_57 ( int V_95 )
{
struct V_41 * V_42 ;
T_7 * V_96 ;
if ( ( V_95 != 1 ) && ( V_95 != 6 ) && ( V_95 != 8 ) && ( V_95 != 16 ) ) {
F_27 ( L_16 ,
V_48 ) ;
V_95 = V_97 = 8 ;
}
V_96 = ( T_7 * ) V_4 -> V_98 . V_76 . V_99 ;
F_58 ( V_4 -> V_99 . V_100 , V_96 ) ;
V_4 -> V_98 . V_76 . V_101 = V_102 ;
strncpy ( V_4 -> V_98 . V_76 . V_103 , V_19 ,
V_104 ) ;
V_4 -> V_98 . V_105 = strlen ( V_4 -> V_98 . V_76 . V_103 ) ;
V_4 -> V_98 . V_95 = V_95 ;
V_42 = (struct V_41 * ) F_38 ( V_4 -> V_13 ) ;
while ( V_42 != NULL ) {
F_11 (lap->magic == LMP_LAP_MAGIC, return;) ;
if ( V_42 -> V_55 == V_56 ) {
F_22 ( V_42 , V_106 ,
NULL ) ;
}
V_42 = (struct V_41 * ) F_56 ( V_4 -> V_13 ) ;
}
}
void F_59 ( int V_95 )
{
F_60 ( V_4 -> V_15 , V_107 ) ;
if ( ! V_21 ) {
if ( V_95 == V_108 )
V_95 = V_97 ;
F_57 ( V_95 ) ;
}
}
struct V_109 * F_61 ( int * V_110 , T_7 V_111 , int V_95 )
{
if ( ! V_21 ) {
if ( V_95 == V_108 )
V_95 = V_97 ;
F_57 ( V_95 ) ;
}
return F_62 ( V_4 -> V_15 , V_110 , V_111 , TRUE ) ;
}
static inline void
F_63 ( T_8 * V_112 ,
T_9 * log , T_10 V_113 )
{
T_11 * V_114 ;
int V_115 ;
int V_116 ;
if ( ! V_112 -> V_117 )
return;
V_114 = F_62 ( log , & V_115 ,
V_112 -> V_118 . V_100 ,
( V_113 == V_107 ) ) ;
if ( V_114 == NULL )
return;
for( V_116 = 0 ; V_116 < V_115 ; V_116 ++ )
V_112 -> V_117 ( & ( V_114 [ V_116 ] ) , V_113 , V_112 -> V_119 ) ;
V_25 ( V_114 ) ;
}
void F_60 ( T_9 * log , T_10 V_113 )
{
T_8 * V_112 ;
T_8 * V_120 ;
F_11 (log != NULL, return;) ;
if ( ! ( F_41 ( log ) ) )
return;
V_112 = ( T_8 * ) F_38 ( V_4 -> V_10 ) ;
while ( NULL != F_64 ( V_4 -> V_10 , ( long ) V_112 , NULL ,
( void * ) & V_120 ) ) {
F_63 ( V_112 , log , V_113 ) ;
V_112 = V_120 ;
}
}
void F_65 ( T_11 * V_121 , int V_115 )
{
T_8 * V_112 ;
T_8 * V_120 ;
int V_116 ;
F_11 (expiries != NULL, return;) ;
V_112 = ( T_8 * ) F_38 ( V_4 -> V_10 ) ;
while ( NULL != F_64 ( V_4 -> V_10 , ( long ) V_112 , NULL ,
( void * ) & V_120 ) ) {
for( V_116 = 0 ; V_116 < V_115 ; V_116 ++ ) {
if ( ( V_112 -> V_122 ) &&
( V_112 -> V_118 . V_100 &
F_66 ( ( T_7 * ) V_121 [ V_116 ] . V_99 )
& 0x7f7f ) )
V_112 -> V_122 ( & ( V_121 [ V_116 ] ) ,
V_123 ,
V_112 -> V_119 ) ;
}
V_112 = V_120 ;
}
}
T_6 * F_67 ( void )
{
F_11 (irlmp != NULL, return NULL;) ;
F_58 ( V_4 -> V_99 . V_100 , ( T_7 * ) V_4 -> V_124 . V_76 . V_99 ) ;
V_4 -> V_124 . V_76 . V_101 = V_102 ;
strncpy ( V_4 -> V_124 . V_76 . V_103 , V_19 ,
V_104 ) ;
V_4 -> V_124 . V_105 = strlen ( V_4 -> V_124 . V_76 . V_103 ) ;
return & V_4 -> V_124 ;
}
int F_68 ( struct V_26 * V_30 , struct V_64 * V_65 )
{
int V_67 ;
F_11 (self != NULL, return -1;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_11 (skb_headroom(userdata) >= LMP_HEADER, return -1;) ;
F_35 ( V_65 , V_87 ) ;
V_67 = F_43 ( V_30 , V_125 , V_65 ) ;
F_20 ( V_65 ) ;
return V_67 ;
}
void F_69 ( struct V_26 * V_30 , struct V_64 * V_81 )
{
F_46 ( V_81 , V_87 ) ;
if ( V_30 -> V_28 . V_126 ) {
F_47 ( V_81 ) ;
V_30 -> V_28 . V_126 ( V_30 -> V_28 . V_58 , V_30 , V_81 ) ;
}
}
int F_70 ( struct V_26 * V_30 , struct V_64 * V_65 )
{
int V_67 ;
F_11 (userdata != NULL, return -1;) ;
F_11 (skb_headroom(userdata) >= LMP_HEADER, return -1;) ;
F_35 ( V_65 , V_87 ) ;
V_67 = F_43 ( V_30 , V_127 , V_65 ) ;
F_20 ( V_65 ) ;
return V_67 ;
}
void F_71 ( struct V_26 * V_30 , struct V_64 * V_81 )
{
F_11 (self != NULL, return;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_11 (skb != NULL, return;) ;
F_46 ( V_81 , V_87 ) ;
if ( V_30 -> V_28 . V_128 ) {
F_47 ( V_81 ) ;
V_30 -> V_28 . V_128 ( V_30 -> V_28 . V_58 , V_30 ,
V_81 ) ;
}
}
int F_72 ( struct V_26 * V_30 , struct V_64 * V_65 ,
T_3 V_29 )
{
struct V_64 * V_129 ;
struct V_41 * V_42 ;
F_11 (userdata != NULL, return -1;) ;
F_11 (skb_headroom(userdata) >= LMP_HEADER+LMP_PID_HEADER,
return -1;) ;
F_35 ( V_65 , V_130 ) ;
if( V_30 != NULL )
V_65 -> V_76 [ 0 ] = V_30 -> V_29 ;
else
V_65 -> V_76 [ 0 ] = V_29 ;
F_35 ( V_65 , V_87 ) ;
V_65 -> V_76 [ 0 ] = V_65 -> V_76 [ 1 ] = V_34 ;
V_42 = (struct V_41 * ) F_38 ( V_4 -> V_13 ) ;
while ( V_42 != NULL ) {
F_11 (lap->magic == LMP_LAP_MAGIC, return -1;) ;
V_129 = F_73 ( V_65 , V_32 ) ;
if ( ! V_129 ) {
F_20 ( V_65 ) ;
return - V_7 ;
}
F_74 ( V_42 -> V_50 , V_129 ) ;
V_42 = (struct V_41 * ) F_56 ( V_4 -> V_13 ) ;
}
F_20 ( V_65 ) ;
return 0 ;
}
void F_75 ( struct V_26 * V_30 , struct V_64 * V_81 )
{
F_11 (self != NULL, return;) ;
F_11 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_11 (skb != NULL, return;) ;
F_46 ( V_81 , V_87 + V_130 ) ;
if ( V_30 -> V_28 . V_128 ) {
F_47 ( V_81 ) ;
V_30 -> V_28 . V_128 ( V_30 -> V_28 . V_58 , V_30 ,
V_81 ) ;
}
}
void F_76 ( struct V_41 * V_30 ,
T_12 V_59 , T_13 V_131 )
{
struct V_26 * V_132 ;
struct V_26 * V_133 ;
V_133 = (struct V_26 * ) F_38 ( V_30 -> V_45 ) ;
while ( NULL != F_64 ( V_30 -> V_45 , ( long ) V_133 , NULL ,
( void * ) & V_132 ) ) {
F_11 (curr->magic == LMP_LSAP_MAGIC, return;) ;
if ( V_133 -> V_28 . V_134 != NULL )
V_133 -> V_28 . V_134 ( V_133 -> V_28 . V_58 ,
V_59 , V_131 ) ;
else
F_25 ( L_15 , V_48 ) ;
V_133 = V_132 ;
}
}
void F_77 ( struct V_41 * V_30 , T_14 V_135 )
{
struct V_26 * V_132 ;
struct V_26 * V_133 ;
int V_136 ;
F_11 (self->magic == LMP_LAP_MAGIC, return;) ;
F_11 (flow == FLOW_START, return;) ;
V_136 = F_41 ( V_30 -> V_45 ) ;
F_25 ( L_17 , V_48 , V_136 ) ;
while( ( V_136 -- ) &&
( F_78 ( V_30 -> V_50 ) < V_137 ) ) {
V_132 = V_30 -> V_138 ;
if( V_132 == NULL )
V_132 = (struct V_26 * ) F_38 ( V_30 -> V_45 ) ;
V_133 = F_64 ( V_30 -> V_45 , ( long ) V_132 , NULL ,
( void * ) & V_30 -> V_138 ) ;
if( V_133 == NULL )
break;
F_25 ( L_18 ,
V_48 , V_133 , V_132 , V_30 -> V_138 , V_136 ,
F_78 ( V_30 -> V_50 ) ) ;
if ( V_133 -> V_28 . V_139 != NULL )
V_133 -> V_28 . V_139 ( V_133 -> V_28 . V_58 ,
V_133 , V_135 ) ;
else
F_25 ( L_15 , V_48 ) ;
}
}
T_7 F_79 ( int V_140 )
{
T_15 V_141 ;
V_141 . V_142 [ 0 ] = V_143 [ V_140 ] [ 0 ] ;
V_141 . V_142 [ 1 ] = V_143 [ V_140 ] [ 1 ] ;
return V_141 . V_100 ;
}
void * F_80 ( T_7 V_99 )
{
T_16 * V_140 ;
F_25 ( L_19 , V_48 , V_99 ) ;
V_140 = F_81 ( sizeof( T_16 ) , V_32 ) ;
if ( ! V_140 )
return NULL ;
V_140 -> V_99 . V_100 = V_99 ;
F_18 ( V_4 -> V_12 , ( V_39 * ) V_140 ,
( long ) V_140 , NULL ) ;
V_4 -> V_99 . V_100 |= V_99 ;
return ( void * ) V_140 ;
}
int F_82 ( void * V_144 )
{
T_16 * V_140 ;
unsigned long V_75 ;
if ( ! V_144 )
return - 1 ;
V_140 = F_40 ( V_4 -> V_12 , ( long ) V_144 , NULL ) ;
if ( ! V_140 ) {
F_25 ( L_20 , V_48 ) ;
return - 1 ;
}
F_83 ( V_4 -> V_12 , ( V_39 * ) V_140 ) ;
V_25 ( V_140 ) ;
V_4 -> V_99 . V_100 = 0 ;
F_36 ( & V_4 -> V_12 -> V_17 , V_75 ) ;
V_140 = ( T_16 * ) F_38 ( V_4 -> V_12 ) ;
while ( V_140 ) {
V_4 -> V_99 . V_100 |= V_140 -> V_99 . V_100 ;
V_140 = ( T_16 * ) F_56 ( V_4 -> V_12 ) ;
}
F_39 ( & V_4 -> V_12 -> V_17 , V_75 ) ;
return 0 ;
}
void * F_84 ( T_7 V_118 , T_17 V_145 ,
T_18 V_146 , void * V_119 )
{
T_8 * V_112 ;
F_11 (irlmp != NULL, return NULL;) ;
V_112 = F_81 ( sizeof( T_8 ) , V_32 ) ;
if ( ! V_112 )
return NULL ;
V_112 -> V_118 . V_100 = V_118 ;
V_112 -> V_117 = V_145 ;
V_112 -> V_122 = V_146 ;
V_112 -> V_119 = V_119 ;
F_18 ( V_4 -> V_10 , ( V_39 * ) V_112 ,
( long ) V_112 , NULL ) ;
return ( void * ) V_112 ;
}
int F_85 ( void * V_144 , T_7 V_118 ,
T_17 V_145 ,
T_18 V_146 , void * V_119 )
{
T_8 * V_112 ;
if ( ! V_144 )
return - 1 ;
V_112 = F_40 ( V_4 -> V_10 , ( long ) V_144 , NULL ) ;
if ( ! V_112 ) {
F_25 ( L_21 , V_48 ) ;
return - 1 ;
}
V_112 -> V_118 . V_100 = V_118 ;
V_112 -> V_117 = V_145 ;
V_112 -> V_122 = V_146 ;
V_112 -> V_119 = V_119 ;
return 0 ;
}
int F_86 ( void * V_144 )
{
struct V_147 * V_112 ;
if ( ! V_144 )
return - 1 ;
V_112 = F_40 ( V_4 -> V_10 , ( long ) V_144 , NULL ) ;
if ( ! V_112 ) {
F_25 ( L_21 , V_48 ) ;
return - 1 ;
}
F_25 ( L_22 , V_48 ) ;
F_83 ( V_4 -> V_10 , ( V_39 * ) V_112 ) ;
V_25 ( V_112 ) ;
return 0 ;
}
static int F_16 ( T_3 V_27 )
{
struct V_26 * V_30 ;
struct V_41 * V_42 ;
unsigned long V_75 ;
F_11 (irlmp != NULL, return TRUE;) ;
F_11 (irlmp->magic == LMP_MAGIC, return TRUE;) ;
F_11 (slsap_sel != LSAP_ANY, return TRUE;) ;
#ifdef F_17
if ( V_27 == V_34 )
return FALSE ;
#endif
if ( V_27 > V_148 )
return TRUE ;
F_87 ( & V_4 -> V_13 -> V_17 , V_75 ,
V_149 ) ;
V_42 = (struct V_41 * ) F_38 ( V_4 -> V_13 ) ;
while ( V_42 != NULL ) {
F_11 (lap->magic == LMP_LAP_MAGIC, goto errlap;) ;
F_88 ( & V_42 -> V_45 -> V_17 ) ;
V_30 = (struct V_26 * ) F_38 ( V_42 -> V_45 ) ;
while ( V_30 != NULL ) {
F_11 (self->magic == LMP_LSAP_MAGIC,
goto errlsap;) ;
if ( ( V_30 -> V_27 == V_27 ) ) {
F_25 ( L_23 ,
V_30 -> V_27 ) ;
goto V_150;
}
V_30 = (struct V_26 * ) F_56 ( V_42 -> V_45 ) ;
}
F_89 ( & V_42 -> V_45 -> V_17 ) ;
V_42 = (struct V_41 * ) F_56 ( V_4 -> V_13 ) ;
}
F_39 ( & V_4 -> V_13 -> V_17 , V_75 ) ;
F_36 ( & V_4 -> V_14 -> V_17 , V_75 ) ;
V_30 = (struct V_26 * ) F_38 ( V_4 -> V_14 ) ;
while ( V_30 != NULL ) {
F_11 (self->magic == LMP_LSAP_MAGIC, goto erruncon;) ;
if ( ( V_30 -> V_27 == V_27 ) ) {
F_25 ( L_24 ,
V_30 -> V_27 ) ;
goto V_151;
}
V_30 = (struct V_26 * ) F_56 ( V_4 -> V_14 ) ;
}
F_39 ( & V_4 -> V_14 -> V_17 , V_75 ) ;
return FALSE ;
V_150:
F_89 ( & V_42 -> V_45 -> V_17 ) ;
F_90 (errlap:)
F_39 ( & V_4 -> V_13 -> V_17 , V_75 ) ;
return TRUE ;
V_151:
F_39 ( & V_4 -> V_14 -> V_17 , V_75 ) ;
return TRUE ;
}
static T_3 F_15 ( void )
{
T_3 V_152 ;
int V_153 = 0 ;
F_11 (irlmp != NULL, return -1;) ;
F_11 (irlmp->magic == LMP_MAGIC, return -1;) ;
do {
V_4 -> V_18 ++ ;
if ( V_4 -> V_18 > V_148 ) {
V_4 -> V_18 = 0x10 ;
if ( V_153 ++ ) {
F_91 ( L_25 ,
V_48 ) ;
return 0 ;
}
}
} while ( F_16 ( V_4 -> V_18 ) );
V_152 = V_4 -> V_18 ;
F_25 ( L_26 ,
V_48 , V_152 ) ;
return V_152 ;
}
T_1 F_92 ( T_19 V_154 )
{
int V_1 = V_155 ;
switch ( V_154 ) {
case V_60 :
F_25 ( L_27 , V_48 ) ;
V_1 = V_156 ;
break;
case V_157 :
F_25 ( L_28 , V_48 ) ;
V_1 = V_155 ;
break;
case V_158 :
F_25 ( L_29 , V_48 ) ;
V_1 = V_159 ;
break;
case V_160 :
case V_161 :
case V_162 :
F_25 ( L_30 ,
V_48 ) ;
V_1 = V_163 ;
break;
default:
F_25 ( L_31 ,
V_48 , V_154 ) ;
V_1 = V_155 ;
break;
}
return V_1 ;
}
static void * F_93 ( struct V_164 * V_165 , T_20 * V_166 )
{
void * V_167 ;
F_94 ( & V_165 -> V_168 -> V_17 ) ;
for ( V_167 = F_38 ( V_165 -> V_168 ) ;
V_167 != NULL ;
V_167 = F_56 ( V_165 -> V_168 ) ) {
if ( ! V_166 || ( * V_166 ) -- == 0 ) {
return V_167 ;
}
}
F_95 ( & V_165 -> V_168 -> V_17 ) ;
V_165 -> V_168 = NULL ;
return NULL ;
}
static void * F_96 ( struct V_169 * V_170 , T_20 * V_171 )
{
struct V_164 * V_165 = V_170 -> V_172 ;
void * V_173 ;
T_20 V_166 = * V_171 ;
V_165 -> V_168 = NULL ;
if ( V_166 -- == 0 )
return V_174 ;
V_165 -> V_168 = V_4 -> V_14 ;
V_173 = F_93 ( V_165 , & V_166 ) ;
if ( V_173 )
return V_173 ;
if ( V_166 -- == 0 )
return V_175 ;
V_165 -> V_168 = V_4 -> V_13 ;
return F_93 ( V_165 , & V_166 ) ;
}
static void * F_97 ( struct V_169 * V_170 , void * V_173 , T_20 * V_171 )
{
struct V_164 * V_165 = V_170 -> V_172 ;
++ * V_171 ;
if ( V_173 == V_174 ) {
V_165 -> V_168 = V_4 -> V_14 ;
V_173 = F_93 ( V_165 , NULL ) ;
return V_173 ? V_173 : V_175 ;
}
if ( V_173 == V_175 ) {
V_165 -> V_168 = V_4 -> V_13 ;
return F_93 ( V_165 , NULL ) ;
}
V_173 = F_56 ( V_165 -> V_168 ) ;
if ( V_173 == NULL ) {
F_95 ( & V_165 -> V_168 -> V_17 ) ;
if ( V_165 -> V_168 == V_4 -> V_14 )
V_173 = V_175 ;
V_165 -> V_168 = NULL ;
}
return V_173 ;
}
static void F_98 ( struct V_169 * V_170 , void * V_173 )
{
struct V_164 * V_165 = V_170 -> V_172 ;
if ( V_165 -> V_168 )
F_95 ( & V_165 -> V_168 -> V_17 ) ;
}
static int F_99 ( struct V_169 * V_170 , void * V_173 )
{
const struct V_164 * V_165 = V_170 -> V_172 ;
struct V_26 * V_30 = V_173 ;
if ( V_173 == V_174 )
F_100 ( V_170 , L_32 ) ;
else if ( V_173 == V_175 )
F_100 ( V_170 , L_33 ) ;
else if ( V_165 -> V_168 == V_4 -> V_14 ) {
V_30 = V_173 ;
F_11 (self->magic == LMP_LSAP_MAGIC, return -EINVAL; ) ;
F_101 ( V_170 , L_34 ,
V_176 [ V_30 -> V_37 ] ) ;
F_101 ( V_170 ,
L_35 ,
V_30 -> V_27 , V_30 -> V_35 ) ;
F_101 ( V_170 , L_36 , V_30 -> V_28 . V_177 ) ;
F_101 ( V_170 , L_37 ) ;
} else if ( V_165 -> V_168 == V_4 -> V_13 ) {
struct V_41 * V_42 = V_173 ;
F_101 ( V_170 , L_38 ,
V_178 [ V_42 -> V_55 ] ) ;
F_101 ( V_170 , L_39 ,
V_42 -> V_51 , V_42 -> V_53 ) ;
F_101 ( V_170 , L_40 ,
F_41 ( V_42 -> V_45 ) ) ;
F_101 ( V_170 , L_37 ) ;
F_88 ( & V_42 -> V_45 -> V_17 ) ;
F_101 ( V_170 , L_41 ) ;
for ( V_30 = (struct V_26 * ) F_38 ( V_42 -> V_45 ) ;
V_30 != NULL ;
V_30 = (struct V_26 * ) F_56 ( V_42 -> V_45 ) ) {
F_11 (self->magic == LMP_LSAP_MAGIC,
goto outloop;) ;
F_101 ( V_170 , L_42 ,
V_176 [ V_30 -> V_37 ] ) ;
F_101 ( V_170 ,
L_35 ,
V_30 -> V_27 , V_30 -> V_35 ) ;
F_101 ( V_170 , L_36 , V_30 -> V_28 . V_177 ) ;
F_102 ( V_170 , '\n' ) ;
}
F_90 (outloop:)
F_89 ( & V_42 -> V_45 -> V_17 ) ;
F_102 ( V_170 , '\n' ) ;
} else
return - V_71 ;
return 0 ;
}
static int F_103 ( struct V_179 * V_179 , struct V_180 * V_180 )
{
F_11 (irlmp != NULL, return -EINVAL;) ;
return F_104 ( V_180 , & V_181 ,
sizeof( struct V_164 ) ) ;
}
