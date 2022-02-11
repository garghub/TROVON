int T_1 F_1 ( void )
{
F_2 ( 1 , L_1 , V_1 ) ;
V_2 = F_3 ( sizeof( struct V_3 ) , V_4 ) ;
if ( V_2 == NULL )
return - V_5 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_8 = F_4 ( V_9 ) ;
V_2 -> V_10 = F_4 ( V_9 ) ;
V_2 -> V_11 = F_4 ( V_9 ) ;
V_2 -> V_12 = F_4 ( V_9 ) ;
V_2 -> V_13 = F_4 ( V_14 ) ;
if ( ( V_2 -> V_8 == NULL ) ||
( V_2 -> V_10 == NULL ) ||
( V_2 -> V_11 == NULL ) ||
( V_2 -> V_12 == NULL ) ||
( V_2 -> V_13 == NULL ) ) {
return - V_5 ;
}
F_5 ( & V_2 -> V_13 -> V_15 ) ;
V_2 -> V_16 = 0x0f ;
strcpy ( V_17 , L_2 ) ;
F_6 ( & V_2 -> V_18 ) ;
if ( V_19 )
F_7 ( V_2 ,
V_20 * V_21 ) ;
return 0 ;
}
void F_8 ( void )
{
F_9 (irlmp != NULL, return;) ;
F_9 (irlmp->magic == LMP_MAGIC, return;) ;
F_10 ( & V_2 -> V_18 ) ;
F_11 ( V_2 -> V_11 , ( V_22 ) V_23 ) ;
F_11 ( V_2 -> V_12 , ( V_22 ) V_23 ) ;
F_11 ( V_2 -> V_8 , ( V_22 ) V_23 ) ;
F_11 ( V_2 -> V_10 , ( V_22 ) V_23 ) ;
F_11 ( V_2 -> V_13 , ( V_22 ) V_23 ) ;
V_23 ( V_2 ) ;
V_2 = NULL ;
}
struct V_24 * F_12 ( T_2 V_25 , T_3 * V_26 , T_2 V_27 )
{
struct V_24 * V_28 ;
F_9 (notify != NULL, return NULL;) ;
F_9 (irlmp != NULL, return NULL;) ;
F_9 (irlmp->magic == LMP_MAGIC, return NULL;) ;
F_9 (notify->instance != NULL, return NULL;) ;
if ( V_25 == V_29 ) {
V_25 = F_13 () ;
if ( ! V_25 )
return NULL ;
} else if ( F_14 ( V_25 ) )
return NULL ;
V_28 = F_3 ( sizeof( struct V_24 ) , V_30 ) ;
if ( V_28 == NULL ) {
F_15 ( L_3 , V_1 ) ;
return NULL ;
}
V_28 -> V_6 = V_31 ;
V_28 -> V_25 = V_25 ;
if ( V_25 == V_32 ) {
#ifdef F_16
V_28 -> V_33 = V_32 ;
V_28 -> V_27 = V_27 ;
#endif
} else
V_28 -> V_33 = V_29 ;
F_6 ( & V_28 -> V_34 ) ;
V_28 -> V_26 = * V_26 ;
V_28 -> V_35 = V_36 ;
F_17 ( V_2 -> V_12 , ( V_37 * ) V_28 ,
( long ) V_28 , NULL ) ;
return V_28 ;
}
static void F_18 ( struct V_24 * V_28 )
{
F_2 ( 4 , L_1 , V_1 ) ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return;) ;
V_28 -> V_6 = 0 ;
F_10 ( & V_28 -> V_34 ) ;
if ( V_28 -> V_38 )
F_19 ( V_28 -> V_38 ) ;
V_23 ( V_28 ) ;
}
void F_20 ( struct V_24 * V_28 )
{
struct V_39 * V_40 ;
struct V_24 * V_41 = NULL ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return;) ;
V_40 = V_28 -> V_40 ;
if ( V_40 ) {
F_9 (lap->magic == LMP_LAP_MAGIC, return;) ;
if( V_28 -> V_35 != V_36 ) {
V_28 -> V_35 = V_36 ;
F_21 ( V_28 -> V_40 ,
V_42 , NULL ) ;
}
V_41 = F_22 ( V_40 -> V_43 , ( long ) V_28 , NULL ) ;
#ifdef F_23
V_40 -> V_44 . V_45 = FALSE ;
#endif
}
V_28 -> V_40 = NULL ;
if ( ! V_41 ) {
V_41 = F_22 ( V_2 -> V_12 , ( long ) V_28 ,
NULL ) ;
}
if ( ! V_41 ) {
F_2 ( 0 ,
L_4 ,
V_1 ) ;
return;
}
F_18 ( V_28 ) ;
}
void F_24 ( struct V_46 * V_47 , T_4 V_48 , T_3 * V_26 )
{
struct V_39 * V_40 ;
F_9 (irlmp != NULL, return;) ;
F_9 (irlmp->magic == LMP_MAGIC, return;) ;
F_9 (notify != NULL, return;) ;
V_40 = F_3 ( sizeof( struct V_39 ) , V_4 ) ;
if ( V_40 == NULL ) {
F_15 ( L_5 , V_1 ) ;
return;
}
V_40 -> V_47 = V_47 ;
V_40 -> V_6 = V_49 ;
V_40 -> V_48 = V_48 ;
V_40 -> V_50 = V_51 ;
#ifdef F_23
V_40 -> V_44 . V_45 = FALSE ;
#endif
V_40 -> V_43 = F_4 ( V_9 ) ;
if ( V_40 -> V_43 == NULL ) {
F_25 ( L_6 , V_1 ) ;
V_23 ( V_40 ) ;
return;
}
V_40 -> V_52 = V_53 ;
F_6 ( & V_40 -> V_54 ) ;
F_17 ( V_2 -> V_11 , ( V_37 * ) V_40 , V_40 -> V_48 , NULL ) ;
F_26 ( V_26 ) ;
V_26 -> V_55 = V_40 ;
}
void F_27 ( T_4 V_48 )
{
struct V_39 * V_56 ;
F_2 ( 4 , L_1 , V_1 ) ;
V_56 = F_22 ( V_2 -> V_11 , V_48 , NULL ) ;
if ( V_56 ) {
F_9 (link->magic == LMP_LAP_MAGIC, return;) ;
V_56 -> V_57 = V_58 ;
V_56 -> V_50 = V_51 ;
F_21 ( V_56 , V_59 , NULL ) ;
F_28 ( V_2 -> V_13 , V_56 -> V_48 , TRUE ) ;
F_10 ( & V_56 -> V_54 ) ;
V_56 -> V_6 = 0 ;
F_11 ( V_56 -> V_43 , ( V_22 ) F_18 ) ;
V_23 ( V_56 ) ;
}
}
int F_29 ( struct V_24 * V_28 , T_2 V_33 ,
T_4 V_48 , T_4 V_50 ,
struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_62 * V_64 = V_63 ;
struct V_39 * V_40 ;
struct V_24 * V_41 ;
int V_65 ;
F_9 (self != NULL, return -EBADR;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return -EBADR;) ;
F_2 ( 2 ,
L_7 ,
V_1 , V_28 -> V_25 , V_33 , V_48 , V_50 ) ;
if ( F_30 ( 0 , & V_28 -> V_66 ) ) {
V_65 = - V_67 ;
goto V_68;
}
if ( ! V_50 ) {
V_65 = - V_69 ;
goto V_68;
}
if ( V_64 == NULL ) {
V_64 = F_31 ( V_70 , V_30 ) ;
if ( ! V_64 )
return - V_5 ;
F_32 ( V_64 , V_70 ) ;
}
F_9 (skb_headroom(tx_skb) >= LMP_CONTROL_HEADER, return -1;) ;
F_33 ( V_64 , V_71 ) ;
V_28 -> V_33 = V_33 ;
if ( ( ! V_48 ) || ( V_48 == V_51 ) ) {
T_5 * V_72 ;
unsigned long V_73 ;
F_34 ( & V_2 -> V_13 -> V_15 , V_73 ) ;
if ( V_50 != V_51 )
V_72 = F_35 ( V_2 -> V_13 , V_50 , NULL ) ;
else {
F_2 ( 2 , L_8 , V_1 ) ;
V_72 = ( T_5 * )
F_36 ( V_2 -> V_13 ) ;
}
if ( V_72 ) {
V_48 = V_72 -> V_74 . V_48 ;
V_50 = V_72 -> V_74 . V_50 ;
}
F_37 ( & V_2 -> V_13 -> V_15 , V_73 ) ;
}
V_40 = F_38 ( V_2 -> V_11 , V_48 , NULL ) ;
if ( V_40 == NULL ) {
F_2 ( 1 , L_9 , V_1 ) ;
V_65 = - V_75 ;
goto V_68;
}
if ( V_40 -> V_50 == V_51 )
V_40 -> V_50 = V_50 ;
else if ( V_40 -> V_50 != V_50 ) {
if ( F_39 ( V_40 -> V_43 ) == 0 ) {
F_2 ( 0 , L_10 , V_1 ) ;
V_65 = - V_76 ;
goto V_68;
}
F_2 ( 0 , L_11 , V_1 ) ;
V_65 = - V_77 ;
goto V_68;
}
V_28 -> V_40 = V_40 ;
V_41 = F_22 ( V_2 -> V_12 , ( long ) V_28 , NULL ) ;
F_9 (lsap != NULL, return -1;) ;
F_9 (lsap->magic == LMP_LSAP_MAGIC, return -1;) ;
F_9 (lsap->lap != NULL, return -1;) ;
F_9 (lsap->lap->magic == LMP_LAP_MAGIC, return -1;) ;
F_17 ( V_28 -> V_40 -> V_43 , ( V_37 * ) V_28 , ( long ) V_28 ,
NULL ) ;
F_40 ( 0 , & V_28 -> V_66 ) ;
if ( V_61 )
V_28 -> V_61 = * V_61 ;
F_41 ( V_28 , V_78 , V_64 ) ;
F_19 ( V_64 ) ;
return 0 ;
V_68:
if( V_64 )
F_19 ( V_64 ) ;
return V_65 ;
}
void F_42 ( struct V_24 * V_28 , struct V_62 * V_79 )
{
int V_80 ;
int V_81 ;
int V_82 ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_9 (skb != NULL, return;) ;
F_9 (self->lap != NULL, return;) ;
F_2 ( 2 , L_12 ,
V_1 , V_28 -> V_25 , V_28 -> V_33 ) ;
V_28 -> V_61 = * V_28 -> V_40 -> V_61 ;
V_80 = V_28 -> V_40 -> V_61 -> V_83 . V_84 - V_85 ;
V_81 = F_43 ( V_28 -> V_40 -> V_47 ) ;
V_82 = V_85 + V_81 ;
F_44 ( V_79 , V_71 ) ;
if ( V_28 -> V_26 . V_86 ) {
F_45 ( V_79 ) ;
V_28 -> V_26 . V_86 ( V_28 -> V_26 . V_55 , V_28 ,
& V_28 -> V_61 , V_80 ,
V_82 , V_79 ) ;
}
}
int F_46 ( struct V_24 * V_28 , struct V_62 * V_63 )
{
F_9 (self != NULL, return -1;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_9 (userdata != NULL, return -1;) ;
F_2 ( 2 , L_12 ,
V_1 , V_28 -> V_25 , V_28 -> V_33 ) ;
F_9 (skb_headroom(userdata) >= LMP_CONTROL_HEADER, return -1;) ;
F_33 ( V_63 , V_71 ) ;
F_41 ( V_28 , V_87 , V_63 ) ;
F_19 ( V_63 ) ;
return 0 ;
}
void F_47 ( struct V_24 * V_28 , struct V_62 * V_79 )
{
int V_82 ;
int V_81 ;
int V_80 ;
F_2 ( 3 , L_1 , V_1 ) ;
F_9 (skb != NULL, return;) ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_9 (self->lap != NULL, return;) ;
V_28 -> V_61 = * V_28 -> V_40 -> V_61 ;
V_80 = V_28 -> V_40 -> V_61 -> V_83 . V_84 - V_85 ;
V_81 = F_43 ( V_28 -> V_40 -> V_47 ) ;
V_82 = V_85 + V_81 ;
F_2 ( 2 , L_13 ,
V_1 , V_82 ) ;
F_44 ( V_79 , V_71 ) ;
if ( V_28 -> V_26 . V_88 ) {
F_45 ( V_79 ) ;
V_28 -> V_26 . V_88 ( V_28 -> V_26 . V_55 , V_28 ,
& V_28 -> V_61 , V_80 ,
V_82 , V_79 ) ;
}
}
struct V_24 * F_48 ( struct V_24 * V_89 , void * V_55 )
{
struct V_24 * V_90 ;
unsigned long V_73 ;
F_2 ( 1 , L_1 , V_1 ) ;
F_34 ( & V_2 -> V_12 -> V_15 , V_73 ) ;
if ( ( ! F_35 ( V_2 -> V_12 , ( long ) V_89 , NULL ) ) ||
( V_89 -> V_40 == NULL ) ) {
F_2 ( 0 , L_14 ,
V_1 ) ;
F_37 ( & V_2 -> V_12 -> V_15 ,
V_73 ) ;
return NULL ;
}
V_90 = F_49 ( V_89 , sizeof( * V_90 ) , V_30 ) ;
if ( ! V_90 ) {
F_2 ( 0 , L_15 , V_1 ) ;
F_37 ( & V_2 -> V_12 -> V_15 ,
V_73 ) ;
return NULL ;
}
V_90 -> V_38 = NULL ;
F_37 ( & V_2 -> V_12 -> V_15 , V_73 ) ;
V_90 -> V_26 . V_55 = V_55 ;
F_6 ( & V_90 -> V_34 ) ;
F_17 ( V_2 -> V_12 , ( V_37 * ) V_90 ,
( long ) V_90 , NULL ) ;
#ifdef F_23
V_90 -> V_40 -> V_44 . V_45 = FALSE ;
#endif
return V_90 ;
}
int F_50 ( struct V_24 * V_28 , struct V_62 * V_63 )
{
struct V_24 * V_41 ;
F_9 (self != NULL, return -1;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_9 (userdata != NULL, return -1;) ;
if ( ! F_51 ( 0 , & V_28 -> V_66 ) ) {
F_2 ( 0 , L_16 , V_1 ) ;
F_19 ( V_63 ) ;
return - 1 ;
}
F_33 ( V_63 , V_71 ) ;
F_41 ( V_28 , V_91 , V_63 ) ;
F_19 ( V_63 ) ;
F_9 (self->lap != NULL, return -1;) ;
F_9 (self->lap->magic == LMP_LAP_MAGIC, return -1;) ;
F_9 (self->lap->lsaps != NULL, return -1;) ;
V_41 = F_22 ( V_28 -> V_40 -> V_43 , ( long ) V_28 , NULL ) ;
#ifdef F_23
V_28 -> V_40 -> V_44 . V_45 = FALSE ;
#endif
F_9 (lsap != NULL, return -1;) ;
F_9 (lsap->magic == LMP_LSAP_MAGIC, return -1;) ;
F_9 (lsap == self, return -1;) ;
F_17 ( V_2 -> V_12 , ( V_37 * ) V_28 ,
( long ) V_28 , NULL ) ;
V_28 -> V_33 = V_29 ;
V_28 -> V_40 = NULL ;
return 0 ;
}
void F_52 ( struct V_24 * V_28 , T_6 V_57 ,
struct V_62 * V_79 )
{
struct V_24 * V_41 ;
F_2 ( 1 , L_17 , V_1 , V_92 [ V_57 ] ) ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_2 ( 3 , L_12 ,
V_1 , V_28 -> V_25 , V_28 -> V_33 ) ;
if ( ! F_51 ( 0 , & V_28 -> V_66 ) ) {
F_2 ( 0 , L_16 , V_1 ) ;
return;
}
F_9 (self->lap != NULL, return;) ;
F_9 (self->lap->lsaps != NULL, return;) ;
V_41 = F_22 ( V_28 -> V_40 -> V_43 , ( long ) V_28 , NULL ) ;
#ifdef F_23
V_28 -> V_40 -> V_44 . V_45 = FALSE ;
#endif
F_9 (lsap != NULL, return;) ;
F_9 (lsap == self, return;) ;
F_17 ( V_2 -> V_12 , ( V_37 * ) V_41 ,
( long ) V_41 , NULL ) ;
V_28 -> V_33 = V_29 ;
V_28 -> V_40 = NULL ;
if ( V_28 -> V_26 . V_93 ) {
if( V_79 )
F_45 ( V_79 ) ;
V_28 -> V_26 . V_93 ( V_28 -> V_26 . V_55 ,
V_28 , V_57 , V_79 ) ;
} else {
F_2 ( 0 , L_18 , V_1 ) ;
}
}
void F_53 ( void )
{
struct V_39 * V_40 ;
V_40 = (struct V_39 * ) F_36 ( V_2 -> V_11 ) ;
while ( V_40 != NULL ) {
F_9 (lap->magic == LMP_LAP_MAGIC, return;) ;
if ( V_40 -> V_52 == V_53 ) {
F_28 ( V_2 -> V_13 , V_40 -> V_48 ,
FALSE ) ;
}
V_40 = (struct V_39 * ) F_54 ( V_2 -> V_11 ) ;
}
}
void F_55 ( int V_94 )
{
struct V_39 * V_40 ;
T_7 * V_95 ;
if ( ( V_94 != 1 ) && ( V_94 != 6 ) && ( V_94 != 8 ) && ( V_94 != 16 ) ) {
F_25 ( L_19 ,
V_1 ) ;
V_94 = V_96 = 8 ;
}
V_95 = ( T_7 * ) V_2 -> V_97 . V_74 . V_98 ;
F_56 ( V_2 -> V_98 . V_99 , V_95 ) ;
V_2 -> V_97 . V_74 . V_100 = V_101 ;
strncpy ( V_2 -> V_97 . V_74 . V_102 , V_17 ,
V_103 ) ;
V_2 -> V_97 . V_104 = strlen ( V_2 -> V_97 . V_74 . V_102 ) ;
V_2 -> V_97 . V_94 = V_94 ;
V_40 = (struct V_39 * ) F_36 ( V_2 -> V_11 ) ;
while ( V_40 != NULL ) {
F_9 (lap->magic == LMP_LAP_MAGIC, return;) ;
if ( V_40 -> V_52 == V_53 ) {
F_21 ( V_40 , V_105 ,
NULL ) ;
}
V_40 = (struct V_39 * ) F_54 ( V_2 -> V_11 ) ;
}
}
void F_57 ( int V_94 )
{
F_58 ( V_2 -> V_13 , V_106 ) ;
if ( ! V_19 ) {
if ( V_94 == V_107 )
V_94 = V_96 ;
F_55 ( V_94 ) ;
}
}
struct V_108 * F_59 ( int * V_109 , T_7 V_110 , int V_94 )
{
if ( ! V_19 ) {
if ( V_94 == V_107 )
V_94 = V_96 ;
F_55 ( V_94 ) ;
}
return F_60 ( V_2 -> V_13 , V_109 , V_110 , TRUE ) ;
}
static inline void
F_61 ( T_8 * V_111 ,
T_9 * log , T_10 V_112 )
{
T_11 * V_113 ;
int V_114 ;
int V_115 ;
F_2 ( 3 , L_1 , V_1 ) ;
if ( ! V_111 -> V_116 )
return;
V_113 = F_60 ( log , & V_114 ,
V_111 -> V_117 . V_99 ,
( V_112 == V_106 ) ) ;
if ( V_113 == NULL )
return;
for( V_115 = 0 ; V_115 < V_114 ; V_115 ++ )
V_111 -> V_116 ( & ( V_113 [ V_115 ] ) , V_112 , V_111 -> V_118 ) ;
V_23 ( V_113 ) ;
}
void F_58 ( T_9 * log , T_10 V_112 )
{
T_8 * V_111 ;
T_8 * V_119 ;
F_2 ( 3 , L_1 , V_1 ) ;
F_9 (log != NULL, return;) ;
if ( ! ( F_39 ( log ) ) )
return;
V_111 = ( T_8 * ) F_36 ( V_2 -> V_8 ) ;
while ( NULL != F_62 ( V_2 -> V_8 , ( long ) V_111 , NULL ,
( void * ) & V_119 ) ) {
F_61 ( V_111 , log , V_112 ) ;
V_111 = V_119 ;
}
}
void F_63 ( T_11 * V_120 , int V_114 )
{
T_8 * V_111 ;
T_8 * V_119 ;
int V_115 ;
F_2 ( 3 , L_1 , V_1 ) ;
F_9 (expiries != NULL, return;) ;
V_111 = ( T_8 * ) F_36 ( V_2 -> V_8 ) ;
while ( NULL != F_62 ( V_2 -> V_8 , ( long ) V_111 , NULL ,
( void * ) & V_119 ) ) {
for( V_115 = 0 ; V_115 < V_114 ; V_115 ++ ) {
if ( ( V_111 -> V_121 ) &&
( V_111 -> V_117 . V_99 &
F_64 ( ( T_7 * ) V_120 [ V_115 ] . V_98 )
& 0x7f7f ) )
V_111 -> V_121 ( & ( V_120 [ V_115 ] ) ,
V_122 ,
V_111 -> V_118 ) ;
}
V_111 = V_119 ;
}
}
T_5 * F_65 ( void )
{
F_2 ( 4 , L_1 , V_1 ) ;
F_9 (irlmp != NULL, return NULL;) ;
F_56 ( V_2 -> V_98 . V_99 , ( T_7 * ) V_2 -> V_123 . V_74 . V_98 ) ;
V_2 -> V_123 . V_74 . V_100 = V_101 ;
strncpy ( V_2 -> V_123 . V_74 . V_102 , V_17 ,
V_103 ) ;
V_2 -> V_123 . V_104 = strlen ( V_2 -> V_123 . V_74 . V_102 ) ;
return & V_2 -> V_123 ;
}
int F_66 ( struct V_24 * V_28 , struct V_62 * V_63 )
{
int V_65 ;
F_9 (self != NULL, return -1;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_9 (skb_headroom(userdata) >= LMP_HEADER, return -1;) ;
F_33 ( V_63 , V_85 ) ;
V_65 = F_41 ( V_28 , V_124 , V_63 ) ;
F_19 ( V_63 ) ;
return V_65 ;
}
void F_67 ( struct V_24 * V_28 , struct V_62 * V_79 )
{
F_44 ( V_79 , V_85 ) ;
if ( V_28 -> V_26 . V_125 ) {
F_45 ( V_79 ) ;
V_28 -> V_26 . V_125 ( V_28 -> V_26 . V_55 , V_28 , V_79 ) ;
}
}
int F_68 ( struct V_24 * V_28 , struct V_62 * V_63 )
{
int V_65 ;
F_2 ( 4 , L_1 , V_1 ) ;
F_9 (userdata != NULL, return -1;) ;
F_9 (skb_headroom(userdata) >= LMP_HEADER, return -1;) ;
F_33 ( V_63 , V_85 ) ;
V_65 = F_41 ( V_28 , V_126 , V_63 ) ;
F_19 ( V_63 ) ;
return V_65 ;
}
void F_69 ( struct V_24 * V_28 , struct V_62 * V_79 )
{
F_2 ( 4 , L_1 , V_1 ) ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_9 (skb != NULL, return;) ;
F_44 ( V_79 , V_85 ) ;
if ( V_28 -> V_26 . V_127 ) {
F_45 ( V_79 ) ;
V_28 -> V_26 . V_127 ( V_28 -> V_26 . V_55 , V_28 ,
V_79 ) ;
}
}
int F_70 ( struct V_24 * V_28 , struct V_62 * V_63 ,
T_2 V_27 )
{
struct V_62 * V_128 ;
struct V_39 * V_40 ;
F_2 ( 4 , L_1 , V_1 ) ;
F_9 (userdata != NULL, return -1;) ;
F_9 (skb_headroom(userdata) >= LMP_HEADER+LMP_PID_HEADER,
return -1;) ;
F_33 ( V_63 , V_129 ) ;
if( V_28 != NULL )
V_63 -> V_74 [ 0 ] = V_28 -> V_27 ;
else
V_63 -> V_74 [ 0 ] = V_27 ;
F_33 ( V_63 , V_85 ) ;
V_63 -> V_74 [ 0 ] = V_63 -> V_74 [ 1 ] = V_32 ;
V_40 = (struct V_39 * ) F_36 ( V_2 -> V_11 ) ;
while ( V_40 != NULL ) {
F_9 (lap->magic == LMP_LAP_MAGIC, return -1;) ;
V_128 = F_71 ( V_63 , V_30 ) ;
if ( ! V_128 ) {
F_19 ( V_63 ) ;
return - V_5 ;
}
F_72 ( V_40 -> V_47 , V_128 ) ;
V_40 = (struct V_39 * ) F_54 ( V_2 -> V_11 ) ;
}
F_19 ( V_63 ) ;
return 0 ;
}
void F_73 ( struct V_24 * V_28 , struct V_62 * V_79 )
{
F_2 ( 4 , L_1 , V_1 ) ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_9 (skb != NULL, return;) ;
F_44 ( V_79 , V_85 + V_129 ) ;
if ( V_28 -> V_26 . V_127 ) {
F_45 ( V_79 ) ;
V_28 -> V_26 . V_127 ( V_28 -> V_26 . V_55 , V_28 ,
V_79 ) ;
}
}
void F_74 ( struct V_39 * V_28 ,
T_12 V_56 , T_13 V_130 )
{
struct V_24 * V_131 ;
struct V_24 * V_132 ;
V_132 = (struct V_24 * ) F_36 ( V_28 -> V_43 ) ;
while ( NULL != F_62 ( V_28 -> V_43 , ( long ) V_132 , NULL ,
( void * ) & V_131 ) ) {
F_9 (curr->magic == LMP_LSAP_MAGIC, return;) ;
if ( V_132 -> V_26 . V_133 != NULL )
V_132 -> V_26 . V_133 ( V_132 -> V_26 . V_55 ,
V_56 , V_130 ) ;
else
F_2 ( 2 , L_18 , V_1 ) ;
V_132 = V_131 ;
}
}
void F_75 ( struct V_39 * V_28 , T_14 V_134 )
{
struct V_24 * V_131 ;
struct V_24 * V_132 ;
int V_135 ;
F_9 (self->magic == LMP_LAP_MAGIC, return;) ;
F_9 (flow == FLOW_START, return;) ;
V_135 = F_39 ( V_28 -> V_43 ) ;
F_2 ( 4 , L_20 , V_1 , V_135 ) ;
while( ( V_135 -- ) &&
( F_76 ( V_28 -> V_47 ) < V_136 ) ) {
V_131 = V_28 -> V_137 ;
if( V_131 == NULL )
V_131 = (struct V_24 * ) F_36 ( V_28 -> V_43 ) ;
V_132 = F_62 ( V_28 -> V_43 , ( long ) V_131 , NULL ,
( void * ) & V_28 -> V_137 ) ;
if( V_132 == NULL )
break;
F_2 ( 4 , L_21 , V_1 , V_132 , V_131 , V_28 -> V_137 , V_135 , F_76 ( V_28 -> V_47 ) ) ;
if ( V_132 -> V_26 . V_138 != NULL )
V_132 -> V_26 . V_138 ( V_132 -> V_26 . V_55 ,
V_132 , V_134 ) ;
else
F_2 ( 1 , L_18 , V_1 ) ;
}
}
T_7 F_77 ( int V_139 )
{
T_15 V_140 ;
V_140 . V_141 [ 0 ] = V_142 [ V_139 ] [ 0 ] ;
V_140 . V_141 [ 1 ] = V_142 [ V_139 ] [ 1 ] ;
return V_140 . V_99 ;
}
void * F_78 ( T_7 V_98 )
{
T_16 * V_139 ;
F_2 ( 4 , L_22 , V_1 , V_98 ) ;
V_139 = F_79 ( sizeof( T_16 ) , V_30 ) ;
if ( ! V_139 ) {
F_2 ( 1 , L_23 , V_1 ) ;
return NULL ;
}
V_139 -> V_98 . V_99 = V_98 ;
F_17 ( V_2 -> V_10 , ( V_37 * ) V_139 ,
( long ) V_139 , NULL ) ;
V_2 -> V_98 . V_99 |= V_98 ;
return ( void * ) V_139 ;
}
int F_80 ( void * V_143 )
{
T_16 * V_139 ;
unsigned long V_73 ;
F_2 ( 4 , L_1 , V_1 ) ;
if ( ! V_143 )
return - 1 ;
V_139 = F_38 ( V_2 -> V_10 , ( long ) V_143 , NULL ) ;
if ( ! V_139 ) {
F_2 ( 1 , L_24 , V_1 ) ;
return - 1 ;
}
F_81 ( V_2 -> V_10 , ( V_37 * ) V_139 ) ;
V_23 ( V_139 ) ;
V_2 -> V_98 . V_99 = 0 ;
F_34 ( & V_2 -> V_10 -> V_15 , V_73 ) ;
V_139 = ( T_16 * ) F_36 ( V_2 -> V_10 ) ;
while ( V_139 ) {
V_2 -> V_98 . V_99 |= V_139 -> V_98 . V_99 ;
V_139 = ( T_16 * ) F_54 ( V_2 -> V_10 ) ;
}
F_37 ( & V_2 -> V_10 -> V_15 , V_73 ) ;
return 0 ;
}
void * F_82 ( T_7 V_117 , T_17 V_144 ,
T_18 V_145 , void * V_118 )
{
T_8 * V_111 ;
F_2 ( 1 , L_1 , V_1 ) ;
F_9 (irlmp != NULL, return NULL;) ;
V_111 = F_79 ( sizeof( T_8 ) , V_30 ) ;
if ( ! V_111 ) {
F_2 ( 1 , L_23 , V_1 ) ;
return NULL ;
}
V_111 -> V_117 . V_99 = V_117 ;
V_111 -> V_116 = V_144 ;
V_111 -> V_121 = V_145 ;
V_111 -> V_118 = V_118 ;
F_17 ( V_2 -> V_8 , ( V_37 * ) V_111 ,
( long ) V_111 , NULL ) ;
return ( void * ) V_111 ;
}
int F_83 ( void * V_143 , T_7 V_117 ,
T_17 V_144 ,
T_18 V_145 , void * V_118 )
{
T_8 * V_111 ;
if ( ! V_143 )
return - 1 ;
V_111 = F_38 ( V_2 -> V_8 , ( long ) V_143 , NULL ) ;
if ( ! V_111 ) {
F_2 ( 1 , L_25 , V_1 ) ;
return - 1 ;
}
V_111 -> V_117 . V_99 = V_117 ;
V_111 -> V_116 = V_144 ;
V_111 -> V_121 = V_145 ;
V_111 -> V_118 = V_118 ;
return 0 ;
}
int F_84 ( void * V_143 )
{
struct V_146 * V_111 ;
F_2 ( 4 , L_1 , V_1 ) ;
if ( ! V_143 )
return - 1 ;
V_111 = F_38 ( V_2 -> V_8 , ( long ) V_143 , NULL ) ;
if ( ! V_111 ) {
F_2 ( 1 , L_25 , V_1 ) ;
return - 1 ;
}
F_2 ( 4 , L_26 , V_1 ) ;
F_81 ( V_2 -> V_8 , ( V_37 * ) V_111 ) ;
V_23 ( V_111 ) ;
return 0 ;
}
static int F_14 ( T_2 V_25 )
{
struct V_24 * V_28 ;
struct V_39 * V_40 ;
unsigned long V_73 ;
F_9 (irlmp != NULL, return TRUE;) ;
F_9 (irlmp->magic == LMP_MAGIC, return TRUE;) ;
F_9 (slsap_sel != LSAP_ANY, return TRUE;) ;
F_2 ( 4 , L_1 , V_1 ) ;
#ifdef F_16
if ( V_25 == V_32 )
return FALSE ;
#endif
if ( V_25 > V_147 )
return TRUE ;
F_85 ( & V_2 -> V_11 -> V_15 , V_73 ,
V_148 ) ;
V_40 = (struct V_39 * ) F_36 ( V_2 -> V_11 ) ;
while ( V_40 != NULL ) {
F_9 (lap->magic == LMP_LAP_MAGIC, goto errlap;) ;
F_86 ( & V_40 -> V_43 -> V_15 ) ;
V_28 = (struct V_24 * ) F_36 ( V_40 -> V_43 ) ;
while ( V_28 != NULL ) {
F_9 (self->magic == LMP_LSAP_MAGIC,
goto errlsap;) ;
if ( ( V_28 -> V_25 == V_25 ) ) {
F_2 ( 4 , L_27 ,
V_28 -> V_25 ) ;
goto V_149;
}
V_28 = (struct V_24 * ) F_54 ( V_40 -> V_43 ) ;
}
F_87 ( & V_40 -> V_43 -> V_15 ) ;
V_40 = (struct V_39 * ) F_54 ( V_2 -> V_11 ) ;
}
F_37 ( & V_2 -> V_11 -> V_15 , V_73 ) ;
F_34 ( & V_2 -> V_12 -> V_15 , V_73 ) ;
V_28 = (struct V_24 * ) F_36 ( V_2 -> V_12 ) ;
while ( V_28 != NULL ) {
F_9 (self->magic == LMP_LSAP_MAGIC, goto erruncon;) ;
if ( ( V_28 -> V_25 == V_25 ) ) {
F_2 ( 4 , L_28 ,
V_28 -> V_25 ) ;
goto V_150;
}
V_28 = (struct V_24 * ) F_54 ( V_2 -> V_12 ) ;
}
F_37 ( & V_2 -> V_12 -> V_15 , V_73 ) ;
return FALSE ;
V_149:
F_87 ( & V_40 -> V_43 -> V_15 ) ;
F_88 (errlap:)
F_37 ( & V_2 -> V_11 -> V_15 , V_73 ) ;
return TRUE ;
V_150:
F_37 ( & V_2 -> V_12 -> V_15 , V_73 ) ;
return TRUE ;
}
static T_2 F_13 ( void )
{
T_2 V_151 ;
int V_152 = 0 ;
F_9 (irlmp != NULL, return -1;) ;
F_9 (irlmp->magic == LMP_MAGIC, return -1;) ;
do {
V_2 -> V_16 ++ ;
if ( V_2 -> V_16 > V_147 ) {
V_2 -> V_16 = 0x10 ;
if ( V_152 ++ ) {
F_15 ( L_29 ,
V_1 ) ;
return 0 ;
}
}
} while ( F_14 ( V_2 -> V_16 ) );
V_151 = V_2 -> V_16 ;
F_2 ( 4 , L_30 ,
V_1 , V_151 ) ;
return V_151 ;
}
T_6 F_89 ( T_19 V_153 )
{
int V_57 = V_154 ;
switch ( V_153 ) {
case V_58 :
F_2 ( 1 , L_31 , V_1 ) ;
V_57 = V_155 ;
break;
case V_156 :
F_2 ( 1 , L_32 , V_1 ) ;
V_57 = V_154 ;
break;
case V_157 :
F_2 ( 1 , L_33 , V_1 ) ;
V_57 = V_158 ;
break;
case V_159 :
case V_160 :
case V_161 :
F_2 ( 1 , L_34 , V_1 ) ;
V_57 = V_162 ;
break;
default:
F_2 ( 1 , L_35 ,
V_1 , V_153 ) ;
V_57 = V_154 ;
break;
}
return V_57 ;
}
static void * F_90 ( struct V_163 * V_164 , T_20 * V_165 )
{
void * V_166 ;
F_91 ( & V_164 -> V_167 -> V_15 ) ;
for ( V_166 = F_36 ( V_164 -> V_167 ) ;
V_166 != NULL ;
V_166 = F_54 ( V_164 -> V_167 ) ) {
if ( ! V_165 || * V_165 -- == 0 ) {
return V_166 ;
}
}
F_92 ( & V_164 -> V_167 -> V_15 ) ;
V_164 -> V_167 = NULL ;
return NULL ;
}
static void * F_93 ( struct V_168 * V_169 , T_20 * V_170 )
{
struct V_163 * V_164 = V_169 -> V_171 ;
void * V_172 ;
T_20 V_165 = * V_170 ;
V_164 -> V_167 = NULL ;
if ( V_165 -- == 0 )
return V_173 ;
V_164 -> V_167 = V_2 -> V_12 ;
V_172 = F_90 ( V_164 , & V_165 ) ;
if ( V_172 )
return V_172 ;
if ( V_165 -- == 0 )
return V_174 ;
V_164 -> V_167 = V_2 -> V_11 ;
return F_90 ( V_164 , & V_165 ) ;
}
static void * F_94 ( struct V_168 * V_169 , void * V_172 , T_20 * V_170 )
{
struct V_163 * V_164 = V_169 -> V_171 ;
++ * V_170 ;
if ( V_172 == V_173 ) {
V_164 -> V_167 = V_2 -> V_12 ;
V_172 = F_90 ( V_164 , NULL ) ;
return V_172 ? V_172 : V_174 ;
}
if ( V_172 == V_174 ) {
V_164 -> V_167 = V_2 -> V_11 ;
return F_90 ( V_164 , NULL ) ;
}
V_172 = F_54 ( V_164 -> V_167 ) ;
if ( V_172 == NULL ) {
F_92 ( & V_164 -> V_167 -> V_15 ) ;
if ( V_164 -> V_167 == V_2 -> V_12 )
V_172 = V_174 ;
V_164 -> V_167 = NULL ;
}
return V_172 ;
}
static void F_95 ( struct V_168 * V_169 , void * V_172 )
{
struct V_163 * V_164 = V_169 -> V_171 ;
if ( V_164 -> V_167 )
F_92 ( & V_164 -> V_167 -> V_15 ) ;
}
static int F_96 ( struct V_168 * V_169 , void * V_172 )
{
const struct V_163 * V_164 = V_169 -> V_171 ;
struct V_24 * V_28 = V_172 ;
if ( V_172 == V_173 )
F_97 ( V_169 , L_36 ) ;
else if ( V_172 == V_174 )
F_97 ( V_169 , L_37 ) ;
else if ( V_164 -> V_167 == V_2 -> V_12 ) {
V_28 = V_172 ;
F_9 (self->magic == LMP_LSAP_MAGIC, return -EINVAL; ) ;
F_98 ( V_169 , L_38 ,
V_175 [ V_28 -> V_35 ] ) ;
F_98 ( V_169 ,
L_39 ,
V_28 -> V_25 , V_28 -> V_33 ) ;
F_98 ( V_169 , L_40 , V_28 -> V_26 . V_176 ) ;
F_98 ( V_169 , L_41 ) ;
} else if ( V_164 -> V_167 == V_2 -> V_11 ) {
struct V_39 * V_40 = V_172 ;
F_98 ( V_169 , L_42 ,
V_177 [ V_40 -> V_52 ] ) ;
F_98 ( V_169 , L_43 ,
V_40 -> V_48 , V_40 -> V_50 ) ;
F_98 ( V_169 , L_44 ,
F_39 ( V_40 -> V_43 ) ) ;
F_98 ( V_169 , L_41 ) ;
F_86 ( & V_40 -> V_43 -> V_15 ) ;
F_98 ( V_169 , L_45 ) ;
for ( V_28 = (struct V_24 * ) F_36 ( V_40 -> V_43 ) ;
V_28 != NULL ;
V_28 = (struct V_24 * ) F_54 ( V_40 -> V_43 ) ) {
F_9 (self->magic == LMP_LSAP_MAGIC,
goto outloop;) ;
F_98 ( V_169 , L_46 ,
V_175 [ V_28 -> V_35 ] ) ;
F_98 ( V_169 ,
L_39 ,
V_28 -> V_25 , V_28 -> V_33 ) ;
F_98 ( V_169 , L_40 , V_28 -> V_26 . V_176 ) ;
F_99 ( V_169 , '\n' ) ;
}
F_88 (outloop:)
F_87 ( & V_40 -> V_43 -> V_15 ) ;
F_99 ( V_169 , '\n' ) ;
} else
return - V_69 ;
return 0 ;
}
static int F_100 ( struct V_178 * V_178 , struct V_179 * V_179 )
{
F_9 (irlmp != NULL, return -EINVAL;) ;
return F_101 ( V_179 , & V_180 ,
sizeof( struct V_163 ) ) ;
}
