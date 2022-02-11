static T_1
F_1 ( struct V_1 * V_2 , unsigned long V_3 , T_2 V_4 , int type )
{
return 0 ;
}
static void
F_2 ( struct V_1 * V_2 , T_1 V_5 , int V_6 )
{
return;
}
static void *
F_3 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
return NULL ;
}
static inline T_3
F_4 ( T_3 V_11 , T_3 V_12 , T_3 V_13 ,
T_3 V_14 )
{
struct V_15 V_16 ;
V_16 . V_17 = 0 ;
V_16 . V_18 = 0 ;
F_5 ( V_16 ,
( T_3 ) V_19 ,
( T_3 ) V_11 , ( T_3 ) V_12 ,
( T_3 ) V_13 , ( T_3 ) V_14 , 0 , 0 , 0 ) ;
return V_16 . V_17 ;
}
inline struct V_20 *
F_6 ( struct V_1 * V_21 )
{
struct V_20 * V_22 ;
F_7 (pcidev,
&(SN_PLATFORM_DATA(dev)->pcidev_info), pdi_list) {
if ( V_22 -> V_23 == V_21 )
return V_22 ;
}
return NULL ;
}
static T_4 F_8 ( T_3 V_11 , T_3 V_24 , int V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_15 V_31 = { 0 , 0 , 0 , 0 } ;
F_9 ( V_32
L_1 ) ;
V_29 = F_10 ( V_33 * sizeof( * V_29 ) , V_34 ) ;
F_11 ( ! V_29 ) ;
F_5 ( V_31 , V_35 ,
V_11 , V_24 , F_12 ( V_29 ) , 0 , 0 , 0 , 0 ) ;
if ( V_31 . V_17 )
F_13 ( L_2 ,
F_14 ( V_31 . V_17 ) ) ;
V_30 = V_29 + V_25 ;
memcpy ( V_27 , V_30 , sizeof( * V_27 ) ) ;
F_15 ( V_29 ) ;
return V_31 . V_17 ;
}
void T_5
F_16 ( struct V_36 * V_37 )
{
struct V_38 * V_38 ;
struct V_38 * V_30 ;
T_4 V_17 ;
int V_24 , V_25 , V_4 ;
if ( V_37 -> V_39 & 1 )
F_17 ( V_37 ) ;
else
F_18 ( V_37 ) ;
for ( V_24 = 0 ; V_24 <= V_40 ; V_24 ++ )
V_37 -> V_41 [ V_24 ] . V_42 = V_37 ;
if ( ! V_37 -> V_43 . V_44 )
return;
V_4 = ( V_40 + 1 ) *
sizeof( struct V_38 * ) ;
V_37 -> V_43 . V_44 =
F_10 ( V_4 , V_34 ) ;
F_11 ( ! V_37 -> V_43 . V_44 ) ;
for ( V_24 = 0 ; V_24 <= V_40 ; V_24 ++ ) {
V_4 = V_33 *
sizeof( struct V_38 ) ;
V_38 = F_10 ( V_4 , V_34 ) ;
F_11 ( ! V_38 ) ;
V_30 = V_38 ;
for ( V_25 = 0 ; V_25 < V_33 ;
V_25 ++ , V_30 ++ ) {
V_4 = sizeof( struct V_26 ) ;
V_30 -> V_27 = F_10 ( V_4 , V_34 ) ;
F_11 ( ! V_30 -> V_27 ) ;
if ( F_19 ( V_45 ) )
V_17 = F_4 (
V_37 -> V_39 , V_24 , V_25 ,
( T_3 ) ( V_30 -> V_27 ) ) ;
else
V_17 = F_8 ( V_37 -> V_39 ,
V_24 , V_25 ,
V_30 -> V_27 ) ;
if ( V_17 != V_46 )
F_13 ( L_3 ,
F_14 ( V_17 ) ) ;
F_20 ( & V_30 -> V_47 ) ;
}
if ( V_38 )
V_37 -> V_43 . V_44 [ V_24 ] =
V_38 ;
}
}
void F_21 ( struct V_1 * V_21 )
{
struct V_1 * V_48 = F_22 ( V_21 ) -> V_48 ;
F_23 ( V_21 ) ;
F_24 ( V_48 ) ;
F_24 ( V_21 ) ;
}
void F_25 ( struct V_1 * V_21 , struct V_20 * V_20 ,
struct V_49 * V_49 )
{
int V_50 = F_26 ( V_21 -> V_51 ) ;
struct V_7 * V_52 ;
struct V_53 * V_54 ;
struct V_1 * V_48 ;
unsigned int V_55 , V_56 ;
F_27 ( V_21 ) ;
F_28 ( & V_20 -> V_57 ,
& ( F_29 ( V_21 -> V_51 ) -> V_20 ) ) ;
V_55 = ( V_20 -> V_58 >> 32 ) & 0xff ;
V_56 = V_20 -> V_58 & 0xffffffff ;
V_54 = F_30 ( V_50 , V_55 ) ;
V_48 = F_31 ( V_54 , V_56 ) ;
V_20 -> V_48 = V_48 ;
V_20 -> V_23 = V_21 ;
V_20 -> V_59 = F_22 ( V_48 ) ;
V_52 = F_32 ( V_21 -> V_51 ) ;
V_20 -> V_60 = V_52 ;
if ( V_52 && V_52 -> V_61 < V_62 ) {
F_33 ( V_21 ) = V_63 [ V_52 -> V_61 ] ;
} else {
F_33 ( V_21 ) = & V_64 ;
}
if ( V_52 && V_49 -> V_65 ) {
V_20 -> V_66 = V_49 ;
V_21 -> V_67 = V_20 -> V_66 -> V_65 ;
F_34 ( V_21 , V_49 ) ;
} else {
V_20 -> V_66 = NULL ;
F_15 ( V_49 ) ;
}
}
void
F_35 ( struct V_53 * V_51 ,
struct V_7 * V_68 )
{
int V_69 ;
struct V_9 * V_10 ;
struct V_36 * V_36 ;
int V_11 ;
void * V_70 ;
struct V_71 * V_72 ;
struct V_73 * V_73 ;
V_10 = F_36 ( V_51 ) ;
if ( V_68 -> V_61 >= V_62 ) {
F_37 ( V_32 L_4 ,
V_68 -> V_61 ) ;
return;
}
if ( V_68 -> V_61 == V_74 )
return;
V_72 = V_63 [ V_68 -> V_61 ] ;
if ( V_72 == NULL )
F_13 ( L_5 ,
V_68 -> V_61 ) ;
if ( V_72 -> V_75 )
V_70 = (* V_72 -> V_75 ) ( V_68 ,
V_10 ) ;
else
V_70 = NULL ;
V_10 -> V_76 = F_10 ( sizeof( struct V_73 ) ,
V_34 ) ;
F_11 ( V_10 -> V_76 == NULL ) ;
V_73 =
(struct V_73 * ) V_10 -> V_76 ;
V_73 -> V_70 = V_70 ;
F_38 ( & ( (struct V_73 * )
V_10 -> V_76 ) -> V_20 ) ;
V_11 = F_39 ( F_32 ( V_51 ) -> V_77 ) ;
V_69 = F_40 ( V_11 ) ;
V_36 = (struct V_36 * ) ( F_41 ( V_69 ) -> V_78 ) ;
F_32 ( V_51 ) -> V_79 =
& ( V_36 -> V_41 [ F_32 ( V_51 ) -> V_80 ] ) ;
if ( V_10 -> V_81 >= F_42 () ) {
struct V_7 * V_82 = F_32 ( V_51 ) ;
F_37 ( V_32 L_6
L_7 ,
V_82 -> V_61 , V_82 -> V_80 , V_82 -> V_83 ,
V_82 -> V_84 , V_82 -> V_85 , V_82 -> V_77 ) ;
F_37 ( V_32 L_8
L_9 ,
V_10 -> V_81 , F_42 () ) ;
V_10 -> V_81 = - 1 ;
}
}
void F_43 ( struct V_1 * V_21 )
{
struct V_86 * V_87 ;
V_87 = F_10 ( sizeof( struct V_86 ) , V_34 ) ;
if ( ! V_87 ) {
F_44 ( & V_21 -> V_21 , L_10 , V_88 ) ;
return;
}
V_87 -> V_89 = F_22 ( V_21 ) ;
F_45 ( & V_87 -> V_90 , & V_91 ) ;
}
void F_46 ( void )
{
struct V_86 * V_87 ;
struct V_92 * V_93 , * V_94 ;
F_47 (list, safe, &sn_sysdata_list) {
V_87 = F_48 ( V_93 , struct V_86 , V_90 ) ;
F_49 ( & V_87 -> V_90 ) ;
F_49 ( & ( ( (struct V_20 * )
( V_87 -> V_89 ) ) -> V_57 ) ) ;
F_15 ( V_87 -> V_89 ) ;
F_15 ( V_87 ) ;
}
return;
}
void T_5 F_50 ( T_6 * V_95 , T_7 V_81 )
{
struct V_36 * V_36 ;
int V_4 ;
T_8 * V_96 ;
V_4 = sizeof( struct V_36 ) ;
if ( V_81 >= F_42 () )
V_96 = F_51 ( 0 ) ;
else
V_96 = F_51 ( V_81 ) ;
V_36 = (struct V_36 * ) F_52 ( V_96 , V_4 ) ;
V_95 -> V_78 = ( void * ) V_36 ;
}
T_9
F_53 ( T_7 V_69 )
{
struct V_36 * V_37 ;
V_37 = (struct V_36 * ) ( F_41 ( V_69 ) -> V_78 ) ;
return V_37 -> V_97 ;
}
void F_54 ( struct V_53 * V_53 , char * V_14 )
{
T_10 V_11 ;
T_7 V_69 ;
T_9 V_98 ;
T_11 V_99 ;
T_12 V_100 ;
V_11 = F_39 ( F_32 ( V_53 ) -> V_77 ) ;
V_69 = F_40 ( V_11 ) ;
V_98 = F_53 ( V_69 ) ;
V_99 = F_55 ( V_98 ) ;
sprintf ( V_14 , L_11 ,
'0' + F_56 ( F_57 ( V_99 ) ) ,
'0' + F_58 ( F_57 ( V_99 ) ) ,
'0' + F_59 ( F_57 ( V_99 ) ) ,
F_60 ( V_99 ) , F_61 ( V_99 ) ) ;
V_100 = F_62 ( V_99 ) ;
if ( ( V_100 == V_101 ) ||
( V_100 == V_102 ) )
sprintf ( V_14 + strlen ( V_14 ) , L_12 ,
F_63 ( V_98 ) ) ;
}
void T_13
F_64 ( struct V_53 * V_51 )
{
if ( F_65 () )
F_66 ( V_51 ) ;
else
F_67 ( V_51 ) ;
}
static int T_5
F_68 ( void )
{
int V_103 ;
if ( ! F_69 ( L_13 ) || F_70 () )
return 0 ;
{
struct V_104 * V_105 = NULL ;
F_71 ( V_106 , 1 , & V_105 ) ;
F_11 ( V_105 == NULL ) ;
V_107 = V_105 -> V_108 ;
}
for ( V_103 = 0 ; V_103 < V_62 ; V_103 ++ )
V_63 [ V_103 ] = & V_64 ;
F_72 () ;
F_73 () ;
F_74 () ;
V_109 = ~ V_110 ;
F_75 () ;
F_38 ( & V_91 ) ;
F_76 () ;
#ifdef F_77
F_78 () ;
#endif
{
struct V_104 * V_105 ;
( void ) F_71 ( V_106 , 1 , & V_105 ) ;
F_37 ( V_111 L_14 ,
V_105 -> V_108 ) ;
}
if ( F_65 () )
F_79 () ;
else
F_80 () ;
return 0 ;
}
int T_5
F_81 ( void )
{
struct V_53 * V_51 ;
struct V_7 * V_112 ;
T_7 V_69 ;
T_10 V_11 ;
T_7 V_113 ;
if ( ! F_69 ( L_13 ) || F_70 () )
return 0 ;
V_51 = NULL ;
while ( ( V_51 = F_82 ( V_51 ) ) != NULL ) {
V_112 = F_32 ( V_51 ) ;
V_11 = F_39 ( V_112 -> V_77 ) ;
V_69 = F_40 ( V_11 ) ;
if ( ( V_112 -> V_61 == V_114 ) ||
( V_112 -> V_61 == V_115 ) ||
( V_112 -> V_61 == V_116 ) ) {
int V_117 = F_83 ( V_69 , NULL ,
& V_113 ) ;
if ( V_117 < 0 ) {
V_113 = ( T_7 ) - 1 ;
F_37 ( V_32 L_15
L_16
L_17 , V_69 , V_117 ) ;
}
F_36 ( V_51 ) -> V_81 = V_113 ;
}
}
V_118 = 1 ;
return 0 ;
}
