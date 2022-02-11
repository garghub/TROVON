static inline
unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline
void F_3 ( struct V_1 * V_2 , T_2 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_3 F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_10 ;
return ( T_3 ) F_1 ( V_7 -> V_11 , V_9 -> V_12 ) ;
}
static void F_6 ( struct V_6 * V_7 , T_3 V_12 )
{
struct V_8 * V_9 = & V_7 -> V_13 ;
F_3 ( V_7 -> V_11 , V_12 , V_9 -> V_12 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_10 ;
return ( F_1 ( V_7 -> V_11 , V_9 -> V_14 ) == 0 ) ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_13 ;
return F_1 ( V_7 -> V_11 , V_9 -> V_15 ) ;
}
static void F_9 ( struct V_6 * V_7 , T_4 V_16 )
{
struct V_8 * V_9 = ( V_16 == V_17 ) ?
& V_7 -> V_13 : & V_7 -> V_10 ;
T_2 V_18 = V_9 -> V_19 ;
T_2 V_20 = V_9 -> V_20 ;
F_3 ( V_7 -> V_11 , V_18 , V_20 ) ;
F_1 ( V_7 -> V_11 , V_20 ) ;
}
static int F_10 ( struct V_6 * V_7 , T_4 V_16 )
{
struct V_8 * V_9 = ( V_16 == V_17 ) ?
& V_7 -> V_13 : & V_7 -> V_10 ;
T_2 V_18 = V_9 -> V_19 ;
T_2 V_21 = V_9 -> V_21 ;
T_2 V_20 = V_9 -> V_20 ;
T_2 V_22 = F_1 ( V_7 -> V_11 , V_21 ) ;
T_2 V_23 = F_1 ( V_7 -> V_11 , V_20 ) ;
return ( int ) ( V_22 & V_23 & V_18 ) ;
}
int F_11 ( struct V_6 * V_7 , T_3 V_12 )
{
struct V_24 * V_25 = V_7 -> V_26 ;
int V_27 = 0 , V_28 ;
F_12 ( & V_25 -> V_29 ) ;
if ( F_13 ( & V_25 -> V_9 ) < sizeof( V_12 ) ) {
V_27 = - V_30 ;
goto V_31;
}
if ( F_14 ( & V_25 -> V_9 ) && ! F_8 ( V_7 ) ) {
F_6 ( V_7 , V_12 ) ;
goto V_31;
}
V_28 = F_15 ( & V_25 -> V_9 , ( unsigned char * ) & V_12 , sizeof( V_12 ) ) ;
F_16 ( V_28 != sizeof( V_12 ) ) ;
F_17 ( & V_7 -> V_26 -> V_32 ) ;
V_31:
F_18 ( & V_25 -> V_29 ) ;
return V_27 ;
}
void F_19 ( struct V_6 * V_7 )
{
int V_33 ;
int V_34 ;
if ( V_7 -> V_35 )
V_34 = V_36 ;
else
V_34 = V_37 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_7 -> V_38 [ V_33 ] = F_1 ( V_7 -> V_11 , V_33 * sizeof( T_2 ) ) ;
F_20 ( V_7 -> V_39 , L_1 , V_40 ,
V_33 , V_7 -> V_38 [ V_33 ] ) ;
}
}
void F_21 ( struct V_6 * V_7 )
{
int V_33 ;
int V_34 ;
if ( V_7 -> V_35 )
V_34 = V_36 ;
else
V_34 = V_37 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
F_3 ( V_7 -> V_11 , V_7 -> V_38 [ V_33 ] , V_33 * sizeof( T_2 ) ) ;
F_20 ( V_7 -> V_39 , L_1 , V_40 ,
V_33 , V_7 -> V_38 [ V_33 ] ) ;
}
}
void F_22 ( struct V_6 * V_7 , T_4 V_16 )
{
T_2 V_41 ;
struct V_8 * V_9 = ( V_16 == V_17 ) ?
& V_7 -> V_13 : & V_7 -> V_10 ;
T_2 V_18 = V_9 -> V_19 ;
T_2 V_21 = V_9 -> V_21 ;
V_41 = F_1 ( V_7 -> V_11 , V_21 ) ;
V_41 |= V_18 ;
F_3 ( V_7 -> V_11 , V_41 , V_21 ) ;
}
void F_23 ( struct V_6 * V_7 , T_4 V_16 )
{
struct V_8 * V_9 = ( V_16 == V_17 ) ?
& V_7 -> V_13 : & V_7 -> V_10 ;
T_2 V_18 = V_9 -> V_19 ;
T_2 V_42 = V_9 -> V_42 ;
if ( ! V_7 -> V_35 )
V_18 = F_1 ( V_7 -> V_11 , V_42 ) & ~ V_18 ;
F_3 ( V_7 -> V_11 , V_18 , V_42 ) ;
}
static void F_24 ( unsigned long V_43 )
{
struct V_6 * V_7 = (struct V_6 * ) V_43 ;
struct V_24 * V_25 = V_7 -> V_26 ;
T_3 V_12 ;
int V_27 ;
while ( F_25 ( & V_25 -> V_9 ) ) {
if ( F_8 ( V_7 ) ) {
F_22 ( V_7 , V_17 ) ;
break;
}
V_27 = F_26 ( & V_25 -> V_9 , ( unsigned char * ) & V_12 ,
sizeof( V_12 ) ) ;
F_16 ( V_27 != sizeof( V_12 ) ) ;
F_6 ( V_7 , V_12 ) ;
}
}
static void F_27 ( struct V_44 * V_45 )
{
struct V_24 * V_25 =
F_28 ( V_45 , struct V_24 , V_45 ) ;
T_3 V_12 ;
int V_28 ;
while ( F_25 ( & V_25 -> V_9 ) >= sizeof( V_12 ) ) {
V_28 = F_26 ( & V_25 -> V_9 , ( unsigned char * ) & V_12 , sizeof( V_12 ) ) ;
F_16 ( V_28 != sizeof( V_12 ) ) ;
F_29 ( & V_25 -> V_7 -> V_46 , V_28 ,
( void * ) V_12 ) ;
F_30 ( & V_25 -> V_29 ) ;
if ( V_25 -> V_47 ) {
V_25 -> V_47 = false ;
F_22 ( V_25 -> V_7 , V_48 ) ;
}
F_31 ( & V_25 -> V_29 ) ;
}
}
static void F_32 ( struct V_6 * V_7 )
{
F_23 ( V_7 , V_17 ) ;
F_9 ( V_7 , V_17 ) ;
F_17 ( & V_7 -> V_26 -> V_32 ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_24 * V_25 = V_7 -> V_49 ;
T_3 V_12 ;
int V_28 ;
while ( ! F_7 ( V_7 ) ) {
if ( F_34 ( F_13 ( & V_25 -> V_9 ) < sizeof( V_12 ) ) ) {
F_23 ( V_7 , V_48 ) ;
V_25 -> V_47 = true ;
goto V_50;
}
V_12 = F_5 ( V_7 ) ;
V_28 = F_15 ( & V_25 -> V_9 , ( unsigned char * ) & V_12 , sizeof( V_12 ) ) ;
F_16 ( V_28 != sizeof( V_12 ) ) ;
}
F_9 ( V_7 , V_48 ) ;
V_50:
F_35 ( & V_7 -> V_49 -> V_45 ) ;
}
static T_5 F_36 ( int V_16 , void * V_51 )
{
struct V_6 * V_7 = V_51 ;
if ( F_10 ( V_7 , V_17 ) )
F_32 ( V_7 ) ;
if ( F_10 ( V_7 , V_48 ) )
F_33 ( V_7 ) ;
return V_52 ;
}
static struct V_24 * F_37 ( struct V_6 * V_7 ,
void (* V_45) ( struct V_44 * ) ,
void (* V_32)( unsigned long ) )
{
struct V_24 * V_25 ;
V_25 = F_38 ( sizeof( struct V_24 ) , V_53 ) ;
if ( ! V_25 )
return NULL ;
F_39 ( & V_25 -> V_29 ) ;
if ( F_40 ( & V_25 -> V_9 , V_54 , V_53 ) )
goto error;
if ( V_45 )
F_41 ( & V_25 -> V_45 , V_45 ) ;
if ( V_32 )
F_42 ( & V_25 -> V_32 , V_32 , ( unsigned long ) V_7 ) ;
return V_25 ;
error:
F_43 ( V_25 ) ;
return NULL ;
}
static void F_44 ( struct V_24 * V_55 )
{
F_45 ( & V_55 -> V_9 ) ;
F_43 ( V_55 ) ;
}
static int F_46 ( struct V_6 * V_7 )
{
int V_27 = 0 ;
struct V_24 * V_25 ;
struct V_1 * V_2 = V_7 -> V_11 ;
F_47 ( & V_2 -> V_56 ) ;
V_27 = F_48 ( V_2 -> V_39 ) ;
if ( F_34 ( V_27 < 0 ) )
goto V_57;
if ( ! V_7 -> V_58 ++ ) {
V_25 = F_37 ( V_7 , NULL , F_24 ) ;
if ( ! V_25 ) {
V_27 = - V_30 ;
goto V_59;
}
V_7 -> V_26 = V_25 ;
V_25 = F_37 ( V_7 , F_27 , NULL ) ;
if ( ! V_25 ) {
V_27 = - V_30 ;
goto V_60;
}
V_7 -> V_49 = V_25 ;
V_25 -> V_7 = V_7 ;
V_27 = F_49 ( V_7 -> V_16 , F_36 , V_61 ,
V_7 -> V_62 , V_7 ) ;
if ( F_34 ( V_27 ) ) {
F_50 ( L_2 ,
V_27 ) ;
goto V_63;
}
F_22 ( V_7 , V_48 ) ;
}
F_51 ( & V_2 -> V_56 ) ;
return 0 ;
V_63:
F_44 ( V_7 -> V_49 ) ;
V_60:
F_44 ( V_7 -> V_26 ) ;
V_59:
F_52 ( V_2 -> V_39 ) ;
V_7 -> V_58 -- ;
V_57:
F_51 ( & V_2 -> V_56 ) ;
return V_27 ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
F_47 ( & V_2 -> V_56 ) ;
if ( ! -- V_7 -> V_58 ) {
F_23 ( V_7 , V_48 ) ;
F_54 ( V_7 -> V_16 , V_7 ) ;
F_55 ( & V_7 -> V_26 -> V_32 ) ;
F_56 ( & V_7 -> V_49 -> V_45 ) ;
F_44 ( V_7 -> V_26 ) ;
F_44 ( V_7 -> V_49 ) ;
}
F_52 ( V_2 -> V_39 ) ;
F_51 ( & V_2 -> V_56 ) ;
}
static struct V_6 * F_57 ( struct V_1 * V_2 ,
const char * V_64 )
{
struct V_6 * V_65 , * V_7 = NULL ;
struct V_6 * * V_66 = V_2 -> V_66 ;
int V_33 ;
if ( ! V_66 )
return NULL ;
for ( V_33 = 0 ; ( V_65 = V_66 [ V_33 ] ) ; V_33 ++ ) {
if ( ! strcmp ( V_65 -> V_62 , V_64 ) ) {
V_7 = V_65 ;
break;
}
}
return V_7 ;
}
struct V_6 * F_58 ( const char * V_62 , struct V_67 * V_68 )
{
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 ;
int V_27 ;
F_47 ( & V_69 ) ;
F_59 (mdev, &omap_mbox_devices, elem) {
V_7 = F_57 ( V_2 , V_62 ) ;
if ( V_7 )
break;
}
F_51 ( & V_69 ) ;
if ( ! V_7 )
return F_60 ( - V_70 ) ;
if ( V_68 )
F_61 ( & V_7 -> V_46 , V_68 ) ;
V_27 = F_46 ( V_7 ) ;
if ( V_27 ) {
F_62 ( & V_7 -> V_46 , V_68 ) ;
return F_60 ( - V_71 ) ;
}
return V_7 ;
}
void F_63 ( struct V_6 * V_7 , struct V_67 * V_68 )
{
F_62 ( & V_7 -> V_46 , V_68 ) ;
F_53 ( V_7 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_27 ;
int V_33 ;
struct V_6 * * V_66 ;
if ( ! V_2 || ! V_2 -> V_66 )
return - V_72 ;
V_66 = V_2 -> V_66 ;
for ( V_33 = 0 ; V_66 [ V_33 ] ; V_33 ++ ) {
struct V_6 * V_7 = V_66 [ V_33 ] ;
V_7 -> V_39 = F_65 ( & V_73 ,
V_2 -> V_39 , 0 , V_7 , L_3 , V_7 -> V_62 ) ;
if ( F_66 ( V_7 -> V_39 ) ) {
V_27 = F_67 ( V_7 -> V_39 ) ;
goto V_74;
}
F_68 ( & V_7 -> V_46 ) ;
}
F_47 ( & V_69 ) ;
F_69 ( & V_2 -> V_75 , & V_76 ) ;
F_51 ( & V_69 ) ;
return 0 ;
V_74:
while ( V_33 -- )
F_70 ( V_66 [ V_33 ] -> V_39 ) ;
return V_27 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_33 ;
struct V_6 * * V_66 ;
if ( ! V_2 || ! V_2 -> V_66 )
return - V_72 ;
F_47 ( & V_69 ) ;
F_72 ( & V_2 -> V_75 ) ;
F_51 ( & V_69 ) ;
V_66 = V_2 -> V_66 ;
for ( V_33 = 0 ; V_66 [ V_33 ] ; V_33 ++ )
F_70 ( V_66 [ V_33 ] -> V_39 ) ;
return 0 ;
}
static int F_73 ( struct V_77 * V_78 )
{
struct V_79 * V_80 ;
int V_27 ;
struct V_6 * * V_81 , * V_7 , * V_82 ;
struct V_83 * V_84 = V_78 -> V_39 . V_85 ;
struct V_86 * V_87 = NULL ;
struct V_88 * V_89 , * V_90 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_91 * V_92 = V_78 -> V_39 . V_93 ;
struct V_91 * V_94 ;
const struct V_95 * V_96 ;
T_2 V_35 , V_97 ;
T_2 V_98 , V_99 ;
T_2 V_100 [ 3 ] ;
T_2 V_41 ;
int V_33 ;
if ( ! V_92 && ( ! V_84 || ! V_84 -> V_101 || ! V_84 -> V_87 ) ) {
F_50 ( L_4 , V_40 ) ;
return - V_71 ;
}
if ( V_92 ) {
V_96 = F_74 ( V_102 , & V_78 -> V_39 ) ;
if ( ! V_96 )
return - V_71 ;
V_35 = ( T_2 ) V_96 -> V_103 ;
if ( F_75 ( V_92 , L_5 ,
& V_98 ) )
return - V_71 ;
if ( F_75 ( V_92 , L_6 ,
& V_99 ) )
return - V_71 ;
V_97 = F_76 ( V_92 ) ;
if ( ! V_97 ) {
F_77 ( & V_78 -> V_39 , L_7 ) ;
return - V_71 ;
}
} else {
V_97 = V_84 -> V_101 ;
V_87 = V_84 -> V_87 ;
V_35 = V_84 -> V_35 ;
V_98 = V_84 -> V_98 ;
V_99 = V_84 -> V_99 ;
}
V_90 = F_78 ( & V_78 -> V_39 , V_97 * sizeof( * V_90 ) ,
V_53 ) ;
if ( ! V_90 )
return - V_30 ;
V_89 = V_90 ;
V_94 = NULL ;
for ( V_33 = 0 ; V_33 < V_97 ; V_33 ++ , V_89 ++ ) {
if ( V_92 ) {
V_94 = F_79 ( V_92 , V_94 ) ;
V_27 = F_80 ( V_94 , L_8 ,
V_100 , F_81 ( V_100 ) ) ;
if ( V_27 )
return V_27 ;
V_89 -> V_104 = V_100 [ 0 ] ;
V_89 -> V_105 = V_100 [ 1 ] ;
V_89 -> V_106 = V_100 [ 2 ] ;
V_27 = F_80 ( V_94 , L_9 ,
V_100 , F_81 ( V_100 ) ) ;
if ( V_27 )
return V_27 ;
V_89 -> V_107 = V_100 [ 0 ] ;
V_89 -> V_108 = V_100 [ 1 ] ;
V_89 -> V_109 = V_100 [ 2 ] ;
V_89 -> V_62 = V_94 -> V_62 ;
} else {
V_89 -> V_104 = V_87 -> V_104 ;
V_89 -> V_107 = V_87 -> V_107 ;
V_89 -> V_106 = V_87 -> V_110 ;
V_89 -> V_105 = V_87 -> V_111 ;
V_89 -> V_109 = V_87 -> V_110 ;
V_89 -> V_108 = V_87 -> V_111 ;
V_89 -> V_62 = V_87 -> V_62 ;
V_87 ++ ;
}
if ( V_89 -> V_104 >= V_99 || V_89 -> V_107 >= V_99 ||
V_89 -> V_106 >= V_98 || V_89 -> V_109 >= V_98 )
return - V_72 ;
}
V_2 = F_78 ( & V_78 -> V_39 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_30 ;
V_80 = F_82 ( V_78 , V_112 , 0 ) ;
V_2 -> V_4 = F_83 ( & V_78 -> V_39 , V_80 ) ;
if ( F_66 ( V_2 -> V_4 ) )
return F_67 ( V_2 -> V_4 ) ;
V_81 = F_78 ( & V_78 -> V_39 , ( V_97 + 1 ) * sizeof( * V_81 ) ,
V_53 ) ;
if ( ! V_81 )
return - V_30 ;
V_82 = F_78 ( & V_78 -> V_39 , V_97 * sizeof( * V_7 ) ,
V_53 ) ;
if ( ! V_82 )
return - V_30 ;
V_7 = V_82 ;
V_89 = V_90 ;
for ( V_33 = 0 ; V_33 < V_97 ; V_33 ++ , V_89 ++ ) {
V_9 = & V_7 -> V_13 ;
V_9 -> V_12 = F_84 ( V_89 -> V_104 ) ;
V_9 -> V_15 = F_85 ( V_89 -> V_104 ) ;
V_9 -> V_19 = F_86 ( V_89 -> V_104 ) ;
V_9 -> V_21 = F_87 ( V_35 , V_89 -> V_106 ) ;
V_9 -> V_20 = F_88 ( V_35 , V_89 -> V_106 ) ;
V_9 -> V_42 = F_89 ( V_35 , V_89 -> V_106 ) ;
V_9 = & V_7 -> V_10 ;
V_9 -> V_12 = F_84 ( V_89 -> V_107 ) ;
V_9 -> V_14 = F_90 ( V_89 -> V_107 ) ;
V_9 -> V_19 = F_91 ( V_89 -> V_107 ) ;
V_9 -> V_21 = F_87 ( V_35 , V_89 -> V_109 ) ;
V_9 -> V_20 = F_88 ( V_35 , V_89 -> V_109 ) ;
V_9 -> V_42 = F_89 ( V_35 , V_89 -> V_109 ) ;
V_7 -> V_35 = V_35 ;
V_7 -> V_11 = V_2 ;
V_7 -> V_62 = V_89 -> V_62 ;
V_7 -> V_16 = F_92 ( V_78 , V_89 -> V_105 ) ;
if ( V_7 -> V_16 < 0 )
return V_7 -> V_16 ;
V_81 [ V_33 ] = V_7 ++ ;
}
F_93 ( & V_2 -> V_56 ) ;
V_2 -> V_39 = & V_78 -> V_39 ;
V_2 -> V_98 = V_98 ;
V_2 -> V_99 = V_99 ;
V_2 -> V_66 = V_81 ;
V_27 = F_64 ( V_2 ) ;
if ( V_27 )
return V_27 ;
F_94 ( V_78 , V_2 ) ;
F_95 ( V_2 -> V_39 ) ;
V_27 = F_48 ( V_2 -> V_39 ) ;
if ( V_27 < 0 ) {
F_96 ( V_2 -> V_39 ) ;
goto V_113;
}
V_41 = F_1 ( V_2 , V_114 ) ;
F_97 ( V_2 -> V_39 , L_10 , V_41 ) ;
V_27 = F_52 ( V_2 -> V_39 ) ;
if ( V_27 < 0 )
goto V_113;
F_98 ( & V_78 -> V_39 , V_90 ) ;
return 0 ;
V_113:
F_99 ( V_2 -> V_39 ) ;
F_71 ( V_2 ) ;
return V_27 ;
}
static int F_100 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_101 ( V_78 ) ;
F_99 ( V_2 -> V_39 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static int T_6 F_102 ( void )
{
int V_115 ;
V_115 = F_103 ( & V_73 ) ;
if ( V_115 )
return V_115 ;
V_54 = F_104 ( V_54 , sizeof( T_3 ) ) ;
V_54 = F_105 (unsigned int, mbox_kfifo_size,
sizeof(mbox_msg_t)) ;
return F_106 ( & V_116 ) ;
}
static void T_7 F_107 ( void )
{
F_108 ( & V_116 ) ;
F_109 ( & V_73 ) ;
}
