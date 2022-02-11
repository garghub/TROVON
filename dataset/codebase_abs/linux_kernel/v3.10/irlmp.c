const char * F_1 ( T_1 V_1 )
{
V_1 = F_2 ( V_2 , V_1 , F_3 ( V_3 ) - 1 ) ;
return V_3 [ V_1 ] ;
}
int T_2 F_4 ( void )
{
F_5 ( 1 , L_1 , V_4 ) ;
V_5 = F_6 ( sizeof( struct V_6 ) , V_7 ) ;
if ( V_5 == NULL )
return - V_8 ;
V_5 -> V_9 = V_10 ;
V_5 -> V_11 = F_7 ( V_12 ) ;
V_5 -> V_13 = F_7 ( V_12 ) ;
V_5 -> V_14 = F_7 ( V_12 ) ;
V_5 -> V_15 = F_7 ( V_12 ) ;
V_5 -> V_16 = F_7 ( V_17 ) ;
if ( ( V_5 -> V_11 == NULL ) ||
( V_5 -> V_13 == NULL ) ||
( V_5 -> V_14 == NULL ) ||
( V_5 -> V_15 == NULL ) ||
( V_5 -> V_16 == NULL ) ) {
return - V_8 ;
}
F_8 ( & V_5 -> V_16 -> V_18 ) ;
V_5 -> V_19 = 0x0f ;
strcpy ( V_20 , L_2 ) ;
F_9 ( & V_5 -> V_21 ) ;
if ( V_22 )
F_10 ( V_5 ,
V_23 * V_24 ) ;
return 0 ;
}
void F_11 ( void )
{
F_12 (irlmp != NULL, return;) ;
F_12 (irlmp->magic == LMP_MAGIC, return;) ;
F_13 ( & V_5 -> V_21 ) ;
F_14 ( V_5 -> V_14 , ( V_25 ) V_26 ) ;
F_14 ( V_5 -> V_15 , ( V_25 ) V_26 ) ;
F_14 ( V_5 -> V_11 , ( V_25 ) V_26 ) ;
F_14 ( V_5 -> V_13 , ( V_25 ) V_26 ) ;
F_14 ( V_5 -> V_16 , ( V_25 ) V_26 ) ;
V_26 ( V_5 ) ;
V_5 = NULL ;
}
struct V_27 * F_15 ( T_3 V_28 , T_4 * V_29 , T_3 V_30 )
{
struct V_27 * V_31 ;
F_12 (notify != NULL, return NULL;) ;
F_12 (irlmp != NULL, return NULL;) ;
F_12 (irlmp->magic == LMP_MAGIC, return NULL;) ;
F_12 (notify->instance != NULL, return NULL;) ;
if ( V_28 == V_32 ) {
V_28 = F_16 () ;
if ( ! V_28 )
return NULL ;
} else if ( F_17 ( V_28 ) )
return NULL ;
V_31 = F_6 ( sizeof( struct V_27 ) , V_33 ) ;
if ( V_31 == NULL ) {
F_18 ( L_3 , V_4 ) ;
return NULL ;
}
V_31 -> V_9 = V_34 ;
V_31 -> V_28 = V_28 ;
if ( V_28 == V_35 ) {
#ifdef F_19
V_31 -> V_36 = V_35 ;
V_31 -> V_30 = V_30 ;
#endif
} else
V_31 -> V_36 = V_32 ;
F_9 ( & V_31 -> V_37 ) ;
V_31 -> V_29 = * V_29 ;
V_31 -> V_38 = V_39 ;
F_20 ( V_5 -> V_15 , ( V_40 * ) V_31 ,
( long ) V_31 , NULL ) ;
return V_31 ;
}
static void F_21 ( struct V_27 * V_31 )
{
F_5 ( 4 , L_1 , V_4 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return;) ;
V_31 -> V_9 = 0 ;
F_13 ( & V_31 -> V_37 ) ;
if ( V_31 -> V_41 )
F_22 ( V_31 -> V_41 ) ;
V_26 ( V_31 ) ;
}
void F_23 ( struct V_27 * V_31 )
{
struct V_42 * V_43 ;
struct V_27 * V_44 = NULL ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return;) ;
V_43 = V_31 -> V_43 ;
if ( V_43 ) {
F_12 (lap->magic == LMP_LAP_MAGIC, return;) ;
if( V_31 -> V_38 != V_39 ) {
V_31 -> V_38 = V_39 ;
F_24 ( V_31 -> V_43 ,
V_45 , NULL ) ;
}
V_44 = F_25 ( V_43 -> V_46 , ( long ) V_31 , NULL ) ;
#ifdef F_26
V_43 -> V_47 . V_48 = FALSE ;
#endif
}
V_31 -> V_43 = NULL ;
if ( ! V_44 ) {
V_44 = F_25 ( V_5 -> V_15 , ( long ) V_31 ,
NULL ) ;
}
if ( ! V_44 ) {
F_5 ( 0 ,
L_4 ,
V_4 ) ;
return;
}
F_21 ( V_31 ) ;
}
void F_27 ( struct V_49 * V_50 , T_5 V_51 , T_4 * V_29 )
{
struct V_42 * V_43 ;
F_12 (irlmp != NULL, return;) ;
F_12 (irlmp->magic == LMP_MAGIC, return;) ;
F_12 (notify != NULL, return;) ;
V_43 = F_6 ( sizeof( struct V_42 ) , V_7 ) ;
if ( V_43 == NULL ) {
F_18 ( L_5 , V_4 ) ;
return;
}
V_43 -> V_50 = V_50 ;
V_43 -> V_9 = V_52 ;
V_43 -> V_51 = V_51 ;
V_43 -> V_53 = V_54 ;
#ifdef F_26
V_43 -> V_47 . V_48 = FALSE ;
#endif
V_43 -> V_46 = F_7 ( V_12 ) ;
if ( V_43 -> V_46 == NULL ) {
F_28 ( L_6 , V_4 ) ;
V_26 ( V_43 ) ;
return;
}
V_43 -> V_55 = V_56 ;
F_9 ( & V_43 -> V_57 ) ;
F_20 ( V_5 -> V_14 , ( V_40 * ) V_43 , V_43 -> V_51 , NULL ) ;
F_29 ( V_29 ) ;
V_29 -> V_58 = V_43 ;
}
void F_30 ( T_5 V_51 )
{
struct V_42 * V_59 ;
F_5 ( 4 , L_1 , V_4 ) ;
V_59 = F_25 ( V_5 -> V_14 , V_51 , NULL ) ;
if ( V_59 ) {
F_12 (link->magic == LMP_LAP_MAGIC, return;) ;
V_59 -> V_1 = V_60 ;
V_59 -> V_53 = V_54 ;
F_24 ( V_59 , V_61 , NULL ) ;
F_31 ( V_5 -> V_16 , V_59 -> V_51 , TRUE ) ;
F_13 ( & V_59 -> V_57 ) ;
V_59 -> V_9 = 0 ;
F_14 ( V_59 -> V_46 , ( V_25 ) F_21 ) ;
V_26 ( V_59 ) ;
}
}
int F_32 ( struct V_27 * V_31 , T_3 V_36 ,
T_5 V_51 , T_5 V_53 ,
struct V_62 * V_63 , struct V_64 * V_65 )
{
struct V_64 * V_66 = V_65 ;
struct V_42 * V_43 ;
struct V_27 * V_44 ;
int V_67 ;
F_12 (self != NULL, return -EBADR;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return -EBADR;) ;
F_5 ( 2 ,
L_7 ,
V_4 , V_31 -> V_28 , V_36 , V_51 , V_53 ) ;
if ( F_33 ( 0 , & V_31 -> V_68 ) ) {
V_67 = - V_69 ;
goto V_70;
}
if ( ! V_53 ) {
V_67 = - V_71 ;
goto V_70;
}
if ( V_66 == NULL ) {
V_66 = F_34 ( V_72 , V_33 ) ;
if ( ! V_66 )
return - V_8 ;
F_35 ( V_66 , V_72 ) ;
}
F_12 (skb_headroom(tx_skb) >= LMP_CONTROL_HEADER, return -1;) ;
F_36 ( V_66 , V_73 ) ;
V_31 -> V_36 = V_36 ;
if ( ( ! V_51 ) || ( V_51 == V_54 ) ) {
T_6 * V_74 ;
unsigned long V_75 ;
F_37 ( & V_5 -> V_16 -> V_18 , V_75 ) ;
if ( V_53 != V_54 )
V_74 = F_38 ( V_5 -> V_16 , V_53 , NULL ) ;
else {
F_5 ( 2 , L_8 , V_4 ) ;
V_74 = ( T_6 * )
F_39 ( V_5 -> V_16 ) ;
}
if ( V_74 ) {
V_51 = V_74 -> V_76 . V_51 ;
V_53 = V_74 -> V_76 . V_53 ;
}
F_40 ( & V_5 -> V_16 -> V_18 , V_75 ) ;
}
V_43 = F_41 ( V_5 -> V_14 , V_51 , NULL ) ;
if ( V_43 == NULL ) {
F_5 ( 1 , L_9 , V_4 ) ;
V_67 = - V_77 ;
goto V_70;
}
if ( V_43 -> V_53 == V_54 )
V_43 -> V_53 = V_53 ;
else if ( V_43 -> V_53 != V_53 ) {
if ( F_42 ( V_43 -> V_46 ) == 0 ) {
F_5 ( 0 , L_10 , V_4 ) ;
V_67 = - V_78 ;
goto V_70;
}
F_5 ( 0 , L_11 , V_4 ) ;
V_67 = - V_79 ;
goto V_70;
}
V_31 -> V_43 = V_43 ;
V_44 = F_25 ( V_5 -> V_15 , ( long ) V_31 , NULL ) ;
F_12 (lsap != NULL, return -1;) ;
F_12 (lsap->magic == LMP_LSAP_MAGIC, return -1;) ;
F_12 (lsap->lap != NULL, return -1;) ;
F_12 (lsap->lap->magic == LMP_LAP_MAGIC, return -1;) ;
F_20 ( V_31 -> V_43 -> V_46 , ( V_40 * ) V_31 , ( long ) V_31 ,
NULL ) ;
F_43 ( 0 , & V_31 -> V_68 ) ;
if ( V_63 )
V_31 -> V_63 = * V_63 ;
F_44 ( V_31 , V_80 , V_66 ) ;
F_22 ( V_66 ) ;
return 0 ;
V_70:
if( V_66 )
F_22 ( V_66 ) ;
return V_67 ;
}
void F_45 ( struct V_27 * V_31 , struct V_64 * V_81 )
{
int V_82 ;
int V_83 ;
int V_84 ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_12 (skb != NULL, return;) ;
F_12 (self->lap != NULL, return;) ;
F_5 ( 2 , L_12 ,
V_4 , V_31 -> V_28 , V_31 -> V_36 ) ;
V_31 -> V_63 = * V_31 -> V_43 -> V_63 ;
V_82 = V_31 -> V_43 -> V_63 -> V_85 . V_86 - V_87 ;
V_83 = F_46 ( V_31 -> V_43 -> V_50 ) ;
V_84 = V_87 + V_83 ;
F_47 ( V_81 , V_73 ) ;
if ( V_31 -> V_29 . V_88 ) {
F_48 ( V_81 ) ;
V_31 -> V_29 . V_88 ( V_31 -> V_29 . V_58 , V_31 ,
& V_31 -> V_63 , V_82 ,
V_84 , V_81 ) ;
}
}
int F_49 ( struct V_27 * V_31 , struct V_64 * V_65 )
{
F_12 (self != NULL, return -1;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_12 (userdata != NULL, return -1;) ;
F_5 ( 2 , L_12 ,
V_4 , V_31 -> V_28 , V_31 -> V_36 ) ;
F_12 (skb_headroom(userdata) >= LMP_CONTROL_HEADER, return -1;) ;
F_36 ( V_65 , V_73 ) ;
F_44 ( V_31 , V_89 , V_65 ) ;
F_22 ( V_65 ) ;
return 0 ;
}
void F_50 ( struct V_27 * V_31 , struct V_64 * V_81 )
{
int V_84 ;
int V_83 ;
int V_82 ;
F_5 ( 3 , L_1 , V_4 ) ;
F_12 (skb != NULL, return;) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_12 (self->lap != NULL, return;) ;
V_31 -> V_63 = * V_31 -> V_43 -> V_63 ;
V_82 = V_31 -> V_43 -> V_63 -> V_85 . V_86 - V_87 ;
V_83 = F_46 ( V_31 -> V_43 -> V_50 ) ;
V_84 = V_87 + V_83 ;
F_5 ( 2 , L_13 ,
V_4 , V_84 ) ;
F_47 ( V_81 , V_73 ) ;
if ( V_31 -> V_29 . V_90 ) {
F_48 ( V_81 ) ;
V_31 -> V_29 . V_90 ( V_31 -> V_29 . V_58 , V_31 ,
& V_31 -> V_63 , V_82 ,
V_84 , V_81 ) ;
}
}
struct V_27 * F_51 ( struct V_27 * V_91 , void * V_58 )
{
struct V_27 * V_92 ;
unsigned long V_75 ;
F_5 ( 1 , L_1 , V_4 ) ;
F_37 ( & V_5 -> V_15 -> V_18 , V_75 ) ;
if ( ( ! F_38 ( V_5 -> V_15 , ( long ) V_91 , NULL ) ) ||
( V_91 -> V_43 == NULL ) ) {
F_5 ( 0 , L_14 ,
V_4 ) ;
F_40 ( & V_5 -> V_15 -> V_18 ,
V_75 ) ;
return NULL ;
}
V_92 = F_52 ( V_91 , sizeof( * V_92 ) , V_33 ) ;
if ( ! V_92 ) {
F_5 ( 0 , L_15 , V_4 ) ;
F_40 ( & V_5 -> V_15 -> V_18 ,
V_75 ) ;
return NULL ;
}
V_92 -> V_41 = NULL ;
F_40 ( & V_5 -> V_15 -> V_18 , V_75 ) ;
V_92 -> V_29 . V_58 = V_58 ;
F_9 ( & V_92 -> V_37 ) ;
F_20 ( V_5 -> V_15 , ( V_40 * ) V_92 ,
( long ) V_92 , NULL ) ;
#ifdef F_26
V_92 -> V_43 -> V_47 . V_48 = FALSE ;
#endif
return V_92 ;
}
int F_53 ( struct V_27 * V_31 , struct V_64 * V_65 )
{
struct V_27 * V_44 ;
F_12 (self != NULL, return -1;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_12 (userdata != NULL, return -1;) ;
if ( ! F_54 ( 0 , & V_31 -> V_68 ) ) {
F_5 ( 0 , L_16 , V_4 ) ;
F_22 ( V_65 ) ;
return - 1 ;
}
F_36 ( V_65 , V_73 ) ;
F_44 ( V_31 , V_93 , V_65 ) ;
F_22 ( V_65 ) ;
F_12 (self->lap != NULL, return -1;) ;
F_12 (self->lap->magic == LMP_LAP_MAGIC, return -1;) ;
F_12 (self->lap->lsaps != NULL, return -1;) ;
V_44 = F_25 ( V_31 -> V_43 -> V_46 , ( long ) V_31 , NULL ) ;
#ifdef F_26
V_31 -> V_43 -> V_47 . V_48 = FALSE ;
#endif
F_12 (lsap != NULL, return -1;) ;
F_12 (lsap->magic == LMP_LSAP_MAGIC, return -1;) ;
F_12 (lsap == self, return -1;) ;
F_20 ( V_5 -> V_15 , ( V_40 * ) V_31 ,
( long ) V_31 , NULL ) ;
V_31 -> V_36 = V_32 ;
V_31 -> V_43 = NULL ;
return 0 ;
}
void F_55 ( struct V_27 * V_31 , T_1 V_1 ,
struct V_64 * V_81 )
{
struct V_27 * V_44 ;
F_5 ( 1 , L_17 , V_4 ,
F_1 ( V_1 ) , V_1 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_5 ( 3 , L_12 ,
V_4 , V_31 -> V_28 , V_31 -> V_36 ) ;
if ( ! F_54 ( 0 , & V_31 -> V_68 ) ) {
F_5 ( 0 , L_16 , V_4 ) ;
return;
}
F_12 (self->lap != NULL, return;) ;
F_12 (self->lap->lsaps != NULL, return;) ;
V_44 = F_25 ( V_31 -> V_43 -> V_46 , ( long ) V_31 , NULL ) ;
#ifdef F_26
V_31 -> V_43 -> V_47 . V_48 = FALSE ;
#endif
F_12 (lsap != NULL, return;) ;
F_12 (lsap == self, return;) ;
F_20 ( V_5 -> V_15 , ( V_40 * ) V_44 ,
( long ) V_44 , NULL ) ;
V_31 -> V_36 = V_32 ;
V_31 -> V_43 = NULL ;
if ( V_31 -> V_29 . V_94 ) {
if( V_81 )
F_48 ( V_81 ) ;
V_31 -> V_29 . V_94 ( V_31 -> V_29 . V_58 ,
V_31 , V_1 , V_81 ) ;
} else {
F_5 ( 0 , L_18 , V_4 ) ;
}
}
void F_56 ( void )
{
struct V_42 * V_43 ;
V_43 = (struct V_42 * ) F_39 ( V_5 -> V_14 ) ;
while ( V_43 != NULL ) {
F_12 (lap->magic == LMP_LAP_MAGIC, return;) ;
if ( V_43 -> V_55 == V_56 ) {
F_31 ( V_5 -> V_16 , V_43 -> V_51 ,
FALSE ) ;
}
V_43 = (struct V_42 * ) F_57 ( V_5 -> V_14 ) ;
}
}
void F_58 ( int V_95 )
{
struct V_42 * V_43 ;
T_7 * V_96 ;
if ( ( V_95 != 1 ) && ( V_95 != 6 ) && ( V_95 != 8 ) && ( V_95 != 16 ) ) {
F_28 ( L_19 ,
V_4 ) ;
V_95 = V_97 = 8 ;
}
V_96 = ( T_7 * ) V_5 -> V_98 . V_76 . V_99 ;
F_59 ( V_5 -> V_99 . V_100 , V_96 ) ;
V_5 -> V_98 . V_76 . V_101 = V_102 ;
strncpy ( V_5 -> V_98 . V_76 . V_103 , V_20 ,
V_104 ) ;
V_5 -> V_98 . V_105 = strlen ( V_5 -> V_98 . V_76 . V_103 ) ;
V_5 -> V_98 . V_95 = V_95 ;
V_43 = (struct V_42 * ) F_39 ( V_5 -> V_14 ) ;
while ( V_43 != NULL ) {
F_12 (lap->magic == LMP_LAP_MAGIC, return;) ;
if ( V_43 -> V_55 == V_56 ) {
F_24 ( V_43 , V_106 ,
NULL ) ;
}
V_43 = (struct V_42 * ) F_57 ( V_5 -> V_14 ) ;
}
}
void F_60 ( int V_95 )
{
F_61 ( V_5 -> V_16 , V_107 ) ;
if ( ! V_22 ) {
if ( V_95 == V_108 )
V_95 = V_97 ;
F_58 ( V_95 ) ;
}
}
struct V_109 * F_62 ( int * V_110 , T_7 V_111 , int V_95 )
{
if ( ! V_22 ) {
if ( V_95 == V_108 )
V_95 = V_97 ;
F_58 ( V_95 ) ;
}
return F_63 ( V_5 -> V_16 , V_110 , V_111 , TRUE ) ;
}
static inline void
F_64 ( T_8 * V_112 ,
T_9 * log , T_10 V_113 )
{
T_11 * V_114 ;
int V_115 ;
int V_116 ;
F_5 ( 3 , L_1 , V_4 ) ;
if ( ! V_112 -> V_117 )
return;
V_114 = F_63 ( log , & V_115 ,
V_112 -> V_118 . V_100 ,
( V_113 == V_107 ) ) ;
if ( V_114 == NULL )
return;
for( V_116 = 0 ; V_116 < V_115 ; V_116 ++ )
V_112 -> V_117 ( & ( V_114 [ V_116 ] ) , V_113 , V_112 -> V_119 ) ;
V_26 ( V_114 ) ;
}
void F_61 ( T_9 * log , T_10 V_113 )
{
T_8 * V_112 ;
T_8 * V_120 ;
F_5 ( 3 , L_1 , V_4 ) ;
F_12 (log != NULL, return;) ;
if ( ! ( F_42 ( log ) ) )
return;
V_112 = ( T_8 * ) F_39 ( V_5 -> V_11 ) ;
while ( NULL != F_65 ( V_5 -> V_11 , ( long ) V_112 , NULL ,
( void * ) & V_120 ) ) {
F_64 ( V_112 , log , V_113 ) ;
V_112 = V_120 ;
}
}
void F_66 ( T_11 * V_121 , int V_115 )
{
T_8 * V_112 ;
T_8 * V_120 ;
int V_116 ;
F_5 ( 3 , L_1 , V_4 ) ;
F_12 (expiries != NULL, return;) ;
V_112 = ( T_8 * ) F_39 ( V_5 -> V_11 ) ;
while ( NULL != F_65 ( V_5 -> V_11 , ( long ) V_112 , NULL ,
( void * ) & V_120 ) ) {
for( V_116 = 0 ; V_116 < V_115 ; V_116 ++ ) {
if ( ( V_112 -> V_122 ) &&
( V_112 -> V_118 . V_100 &
F_67 ( ( T_7 * ) V_121 [ V_116 ] . V_99 )
& 0x7f7f ) )
V_112 -> V_122 ( & ( V_121 [ V_116 ] ) ,
V_123 ,
V_112 -> V_119 ) ;
}
V_112 = V_120 ;
}
}
T_6 * F_68 ( void )
{
F_5 ( 4 , L_1 , V_4 ) ;
F_12 (irlmp != NULL, return NULL;) ;
F_59 ( V_5 -> V_99 . V_100 , ( T_7 * ) V_5 -> V_124 . V_76 . V_99 ) ;
V_5 -> V_124 . V_76 . V_101 = V_102 ;
strncpy ( V_5 -> V_124 . V_76 . V_103 , V_20 ,
V_104 ) ;
V_5 -> V_124 . V_105 = strlen ( V_5 -> V_124 . V_76 . V_103 ) ;
return & V_5 -> V_124 ;
}
int F_69 ( struct V_27 * V_31 , struct V_64 * V_65 )
{
int V_67 ;
F_12 (self != NULL, return -1;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_12 (skb_headroom(userdata) >= LMP_HEADER, return -1;) ;
F_36 ( V_65 , V_87 ) ;
V_67 = F_44 ( V_31 , V_125 , V_65 ) ;
F_22 ( V_65 ) ;
return V_67 ;
}
void F_70 ( struct V_27 * V_31 , struct V_64 * V_81 )
{
F_47 ( V_81 , V_87 ) ;
if ( V_31 -> V_29 . V_126 ) {
F_48 ( V_81 ) ;
V_31 -> V_29 . V_126 ( V_31 -> V_29 . V_58 , V_31 , V_81 ) ;
}
}
int F_71 ( struct V_27 * V_31 , struct V_64 * V_65 )
{
int V_67 ;
F_5 ( 4 , L_1 , V_4 ) ;
F_12 (userdata != NULL, return -1;) ;
F_12 (skb_headroom(userdata) >= LMP_HEADER, return -1;) ;
F_36 ( V_65 , V_87 ) ;
V_67 = F_44 ( V_31 , V_127 , V_65 ) ;
F_22 ( V_65 ) ;
return V_67 ;
}
void F_72 ( struct V_27 * V_31 , struct V_64 * V_81 )
{
F_5 ( 4 , L_1 , V_4 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_12 (skb != NULL, return;) ;
F_47 ( V_81 , V_87 ) ;
if ( V_31 -> V_29 . V_128 ) {
F_48 ( V_81 ) ;
V_31 -> V_29 . V_128 ( V_31 -> V_29 . V_58 , V_31 ,
V_81 ) ;
}
}
int F_73 ( struct V_27 * V_31 , struct V_64 * V_65 ,
T_3 V_30 )
{
struct V_64 * V_129 ;
struct V_42 * V_43 ;
F_5 ( 4 , L_1 , V_4 ) ;
F_12 (userdata != NULL, return -1;) ;
F_12 (skb_headroom(userdata) >= LMP_HEADER+LMP_PID_HEADER,
return -1;) ;
F_36 ( V_65 , V_130 ) ;
if( V_31 != NULL )
V_65 -> V_76 [ 0 ] = V_31 -> V_30 ;
else
V_65 -> V_76 [ 0 ] = V_30 ;
F_36 ( V_65 , V_87 ) ;
V_65 -> V_76 [ 0 ] = V_65 -> V_76 [ 1 ] = V_35 ;
V_43 = (struct V_42 * ) F_39 ( V_5 -> V_14 ) ;
while ( V_43 != NULL ) {
F_12 (lap->magic == LMP_LAP_MAGIC, return -1;) ;
V_129 = F_74 ( V_65 , V_33 ) ;
if ( ! V_129 ) {
F_22 ( V_65 ) ;
return - V_8 ;
}
F_75 ( V_43 -> V_50 , V_129 ) ;
V_43 = (struct V_42 * ) F_57 ( V_5 -> V_14 ) ;
}
F_22 ( V_65 ) ;
return 0 ;
}
void F_76 ( struct V_27 * V_31 , struct V_64 * V_81 )
{
F_5 ( 4 , L_1 , V_4 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_12 (skb != NULL, return;) ;
F_47 ( V_81 , V_87 + V_130 ) ;
if ( V_31 -> V_29 . V_128 ) {
F_48 ( V_81 ) ;
V_31 -> V_29 . V_128 ( V_31 -> V_29 . V_58 , V_31 ,
V_81 ) ;
}
}
void F_77 ( struct V_42 * V_31 ,
T_12 V_59 , T_13 V_131 )
{
struct V_27 * V_132 ;
struct V_27 * V_133 ;
V_133 = (struct V_27 * ) F_39 ( V_31 -> V_46 ) ;
while ( NULL != F_65 ( V_31 -> V_46 , ( long ) V_133 , NULL ,
( void * ) & V_132 ) ) {
F_12 (curr->magic == LMP_LSAP_MAGIC, return;) ;
if ( V_133 -> V_29 . V_134 != NULL )
V_133 -> V_29 . V_134 ( V_133 -> V_29 . V_58 ,
V_59 , V_131 ) ;
else
F_5 ( 2 , L_18 , V_4 ) ;
V_133 = V_132 ;
}
}
void F_78 ( struct V_42 * V_31 , T_14 V_135 )
{
struct V_27 * V_132 ;
struct V_27 * V_133 ;
int V_136 ;
F_12 (self->magic == LMP_LAP_MAGIC, return;) ;
F_12 (flow == FLOW_START, return;) ;
V_136 = F_42 ( V_31 -> V_46 ) ;
F_5 ( 4 , L_20 , V_4 , V_136 ) ;
while( ( V_136 -- ) &&
( F_79 ( V_31 -> V_50 ) < V_137 ) ) {
V_132 = V_31 -> V_138 ;
if( V_132 == NULL )
V_132 = (struct V_27 * ) F_39 ( V_31 -> V_46 ) ;
V_133 = F_65 ( V_31 -> V_46 , ( long ) V_132 , NULL ,
( void * ) & V_31 -> V_138 ) ;
if( V_133 == NULL )
break;
F_5 ( 4 , L_21 , V_4 , V_133 , V_132 , V_31 -> V_138 , V_136 , F_79 ( V_31 -> V_50 ) ) ;
if ( V_133 -> V_29 . V_139 != NULL )
V_133 -> V_29 . V_139 ( V_133 -> V_29 . V_58 ,
V_133 , V_135 ) ;
else
F_5 ( 1 , L_18 , V_4 ) ;
}
}
T_7 F_80 ( int V_140 )
{
T_15 V_141 ;
V_141 . V_142 [ 0 ] = V_143 [ V_140 ] [ 0 ] ;
V_141 . V_142 [ 1 ] = V_143 [ V_140 ] [ 1 ] ;
return V_141 . V_100 ;
}
void * F_81 ( T_7 V_99 )
{
T_16 * V_140 ;
F_5 ( 4 , L_22 , V_4 , V_99 ) ;
V_140 = F_82 ( sizeof( T_16 ) , V_33 ) ;
if ( ! V_140 ) {
F_5 ( 1 , L_23 , V_4 ) ;
return NULL ;
}
V_140 -> V_99 . V_100 = V_99 ;
F_20 ( V_5 -> V_13 , ( V_40 * ) V_140 ,
( long ) V_140 , NULL ) ;
V_5 -> V_99 . V_100 |= V_99 ;
return ( void * ) V_140 ;
}
int F_83 ( void * V_144 )
{
T_16 * V_140 ;
unsigned long V_75 ;
F_5 ( 4 , L_1 , V_4 ) ;
if ( ! V_144 )
return - 1 ;
V_140 = F_41 ( V_5 -> V_13 , ( long ) V_144 , NULL ) ;
if ( ! V_140 ) {
F_5 ( 1 , L_24 , V_4 ) ;
return - 1 ;
}
F_84 ( V_5 -> V_13 , ( V_40 * ) V_140 ) ;
V_26 ( V_140 ) ;
V_5 -> V_99 . V_100 = 0 ;
F_37 ( & V_5 -> V_13 -> V_18 , V_75 ) ;
V_140 = ( T_16 * ) F_39 ( V_5 -> V_13 ) ;
while ( V_140 ) {
V_5 -> V_99 . V_100 |= V_140 -> V_99 . V_100 ;
V_140 = ( T_16 * ) F_57 ( V_5 -> V_13 ) ;
}
F_40 ( & V_5 -> V_13 -> V_18 , V_75 ) ;
return 0 ;
}
void * F_85 ( T_7 V_118 , T_17 V_145 ,
T_18 V_146 , void * V_119 )
{
T_8 * V_112 ;
F_5 ( 1 , L_1 , V_4 ) ;
F_12 (irlmp != NULL, return NULL;) ;
V_112 = F_82 ( sizeof( T_8 ) , V_33 ) ;
if ( ! V_112 ) {
F_5 ( 1 , L_23 , V_4 ) ;
return NULL ;
}
V_112 -> V_118 . V_100 = V_118 ;
V_112 -> V_117 = V_145 ;
V_112 -> V_122 = V_146 ;
V_112 -> V_119 = V_119 ;
F_20 ( V_5 -> V_11 , ( V_40 * ) V_112 ,
( long ) V_112 , NULL ) ;
return ( void * ) V_112 ;
}
int F_86 ( void * V_144 , T_7 V_118 ,
T_17 V_145 ,
T_18 V_146 , void * V_119 )
{
T_8 * V_112 ;
if ( ! V_144 )
return - 1 ;
V_112 = F_41 ( V_5 -> V_11 , ( long ) V_144 , NULL ) ;
if ( ! V_112 ) {
F_5 ( 1 , L_25 , V_4 ) ;
return - 1 ;
}
V_112 -> V_118 . V_100 = V_118 ;
V_112 -> V_117 = V_145 ;
V_112 -> V_122 = V_146 ;
V_112 -> V_119 = V_119 ;
return 0 ;
}
int F_87 ( void * V_144 )
{
struct V_147 * V_112 ;
F_5 ( 4 , L_1 , V_4 ) ;
if ( ! V_144 )
return - 1 ;
V_112 = F_41 ( V_5 -> V_11 , ( long ) V_144 , NULL ) ;
if ( ! V_112 ) {
F_5 ( 1 , L_25 , V_4 ) ;
return - 1 ;
}
F_5 ( 4 , L_26 , V_4 ) ;
F_84 ( V_5 -> V_11 , ( V_40 * ) V_112 ) ;
V_26 ( V_112 ) ;
return 0 ;
}
static int F_17 ( T_3 V_28 )
{
struct V_27 * V_31 ;
struct V_42 * V_43 ;
unsigned long V_75 ;
F_12 (irlmp != NULL, return TRUE;) ;
F_12 (irlmp->magic == LMP_MAGIC, return TRUE;) ;
F_12 (slsap_sel != LSAP_ANY, return TRUE;) ;
F_5 ( 4 , L_1 , V_4 ) ;
#ifdef F_19
if ( V_28 == V_35 )
return FALSE ;
#endif
if ( V_28 > V_148 )
return TRUE ;
F_88 ( & V_5 -> V_14 -> V_18 , V_75 ,
V_149 ) ;
V_43 = (struct V_42 * ) F_39 ( V_5 -> V_14 ) ;
while ( V_43 != NULL ) {
F_12 (lap->magic == LMP_LAP_MAGIC, goto errlap;) ;
F_89 ( & V_43 -> V_46 -> V_18 ) ;
V_31 = (struct V_27 * ) F_39 ( V_43 -> V_46 ) ;
while ( V_31 != NULL ) {
F_12 (self->magic == LMP_LSAP_MAGIC,
goto errlsap;) ;
if ( ( V_31 -> V_28 == V_28 ) ) {
F_5 ( 4 , L_27 ,
V_31 -> V_28 ) ;
goto V_150;
}
V_31 = (struct V_27 * ) F_57 ( V_43 -> V_46 ) ;
}
F_90 ( & V_43 -> V_46 -> V_18 ) ;
V_43 = (struct V_42 * ) F_57 ( V_5 -> V_14 ) ;
}
F_40 ( & V_5 -> V_14 -> V_18 , V_75 ) ;
F_37 ( & V_5 -> V_15 -> V_18 , V_75 ) ;
V_31 = (struct V_27 * ) F_39 ( V_5 -> V_15 ) ;
while ( V_31 != NULL ) {
F_12 (self->magic == LMP_LSAP_MAGIC, goto erruncon;) ;
if ( ( V_31 -> V_28 == V_28 ) ) {
F_5 ( 4 , L_28 ,
V_31 -> V_28 ) ;
goto V_151;
}
V_31 = (struct V_27 * ) F_57 ( V_5 -> V_15 ) ;
}
F_40 ( & V_5 -> V_15 -> V_18 , V_75 ) ;
return FALSE ;
V_150:
F_90 ( & V_43 -> V_46 -> V_18 ) ;
F_91 (errlap:)
F_40 ( & V_5 -> V_14 -> V_18 , V_75 ) ;
return TRUE ;
V_151:
F_40 ( & V_5 -> V_15 -> V_18 , V_75 ) ;
return TRUE ;
}
static T_3 F_16 ( void )
{
T_3 V_152 ;
int V_153 = 0 ;
F_12 (irlmp != NULL, return -1;) ;
F_12 (irlmp->magic == LMP_MAGIC, return -1;) ;
do {
V_5 -> V_19 ++ ;
if ( V_5 -> V_19 > V_148 ) {
V_5 -> V_19 = 0x10 ;
if ( V_153 ++ ) {
F_18 ( L_29 ,
V_4 ) ;
return 0 ;
}
}
} while ( F_17 ( V_5 -> V_19 ) );
V_152 = V_5 -> V_19 ;
F_5 ( 4 , L_30 ,
V_4 , V_152 ) ;
return V_152 ;
}
T_1 F_92 ( T_19 V_154 )
{
int V_1 = V_155 ;
switch ( V_154 ) {
case V_60 :
F_5 ( 1 , L_31 , V_4 ) ;
V_1 = V_156 ;
break;
case V_157 :
F_5 ( 1 , L_32 , V_4 ) ;
V_1 = V_155 ;
break;
case V_158 :
F_5 ( 1 , L_33 , V_4 ) ;
V_1 = V_159 ;
break;
case V_160 :
case V_161 :
case V_162 :
F_5 ( 1 , L_34 , V_4 ) ;
V_1 = V_163 ;
break;
default:
F_5 ( 1 , L_35 ,
V_4 , V_154 ) ;
V_1 = V_155 ;
break;
}
return V_1 ;
}
static void * F_93 ( struct V_164 * V_165 , T_20 * V_166 )
{
void * V_167 ;
F_94 ( & V_165 -> V_168 -> V_18 ) ;
for ( V_167 = F_39 ( V_165 -> V_168 ) ;
V_167 != NULL ;
V_167 = F_57 ( V_165 -> V_168 ) ) {
if ( ! V_166 || * V_166 -- == 0 ) {
return V_167 ;
}
}
F_95 ( & V_165 -> V_168 -> V_18 ) ;
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
V_165 -> V_168 = V_5 -> V_15 ;
V_173 = F_93 ( V_165 , & V_166 ) ;
if ( V_173 )
return V_173 ;
if ( V_166 -- == 0 )
return V_175 ;
V_165 -> V_168 = V_5 -> V_14 ;
return F_93 ( V_165 , & V_166 ) ;
}
static void * F_97 ( struct V_169 * V_170 , void * V_173 , T_20 * V_171 )
{
struct V_164 * V_165 = V_170 -> V_172 ;
++ * V_171 ;
if ( V_173 == V_174 ) {
V_165 -> V_168 = V_5 -> V_15 ;
V_173 = F_93 ( V_165 , NULL ) ;
return V_173 ? V_173 : V_175 ;
}
if ( V_173 == V_175 ) {
V_165 -> V_168 = V_5 -> V_14 ;
return F_93 ( V_165 , NULL ) ;
}
V_173 = F_57 ( V_165 -> V_168 ) ;
if ( V_173 == NULL ) {
F_95 ( & V_165 -> V_168 -> V_18 ) ;
if ( V_165 -> V_168 == V_5 -> V_15 )
V_173 = V_175 ;
V_165 -> V_168 = NULL ;
}
return V_173 ;
}
static void F_98 ( struct V_169 * V_170 , void * V_173 )
{
struct V_164 * V_165 = V_170 -> V_172 ;
if ( V_165 -> V_168 )
F_95 ( & V_165 -> V_168 -> V_18 ) ;
}
static int F_99 ( struct V_169 * V_170 , void * V_173 )
{
const struct V_164 * V_165 = V_170 -> V_172 ;
struct V_27 * V_31 = V_173 ;
if ( V_173 == V_174 )
F_100 ( V_170 , L_36 ) ;
else if ( V_173 == V_175 )
F_100 ( V_170 , L_37 ) ;
else if ( V_165 -> V_168 == V_5 -> V_15 ) {
V_31 = V_173 ;
F_12 (self->magic == LMP_LSAP_MAGIC, return -EINVAL; ) ;
F_101 ( V_170 , L_38 ,
V_176 [ V_31 -> V_38 ] ) ;
F_101 ( V_170 ,
L_39 ,
V_31 -> V_28 , V_31 -> V_36 ) ;
F_101 ( V_170 , L_40 , V_31 -> V_29 . V_177 ) ;
F_101 ( V_170 , L_41 ) ;
} else if ( V_165 -> V_168 == V_5 -> V_14 ) {
struct V_42 * V_43 = V_173 ;
F_101 ( V_170 , L_42 ,
V_178 [ V_43 -> V_55 ] ) ;
F_101 ( V_170 , L_43 ,
V_43 -> V_51 , V_43 -> V_53 ) ;
F_101 ( V_170 , L_44 ,
F_42 ( V_43 -> V_46 ) ) ;
F_101 ( V_170 , L_41 ) ;
F_89 ( & V_43 -> V_46 -> V_18 ) ;
F_101 ( V_170 , L_45 ) ;
for ( V_31 = (struct V_27 * ) F_39 ( V_43 -> V_46 ) ;
V_31 != NULL ;
V_31 = (struct V_27 * ) F_57 ( V_43 -> V_46 ) ) {
F_12 (self->magic == LMP_LSAP_MAGIC,
goto outloop;) ;
F_101 ( V_170 , L_46 ,
V_176 [ V_31 -> V_38 ] ) ;
F_101 ( V_170 ,
L_39 ,
V_31 -> V_28 , V_31 -> V_36 ) ;
F_101 ( V_170 , L_40 , V_31 -> V_29 . V_177 ) ;
F_102 ( V_170 , '\n' ) ;
}
F_91 (outloop:)
F_90 ( & V_43 -> V_46 -> V_18 ) ;
F_102 ( V_170 , '\n' ) ;
} else
return - V_71 ;
return 0 ;
}
static int F_103 ( struct V_179 * V_179 , struct V_180 * V_180 )
{
F_12 (irlmp != NULL, return -EINVAL;) ;
return F_104 ( V_180 , & V_181 ,
sizeof( struct V_164 ) ) ;
}
