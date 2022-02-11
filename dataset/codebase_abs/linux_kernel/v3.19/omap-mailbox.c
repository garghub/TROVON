static struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( ! V_3 || ! V_3 -> V_4 )
return NULL ;
return (struct V_1 * ) V_3 -> V_4 ;
}
static inline
unsigned int F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_3 ( V_6 -> V_8 + V_7 ) ;
}
static inline
void F_4 ( struct V_5 * V_6 , T_2 V_9 , T_1 V_7 )
{
F_5 ( V_9 , V_6 -> V_8 + V_7 ) ;
}
static T_3 F_6 ( struct V_1 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_13 ;
return ( T_3 ) F_2 ( V_10 -> V_14 , V_12 -> V_15 ) ;
}
static void F_7 ( struct V_1 * V_10 , T_3 V_15 )
{
struct V_11 * V_12 = & V_10 -> V_16 ;
F_4 ( V_10 -> V_14 , V_15 , V_12 -> V_15 ) ;
}
static int F_8 ( struct V_1 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_13 ;
return ( F_2 ( V_10 -> V_14 , V_12 -> V_17 ) == 0 ) ;
}
static int F_9 ( struct V_1 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_16 ;
return F_2 ( V_10 -> V_14 , V_12 -> V_18 ) ;
}
static void F_10 ( struct V_1 * V_10 , T_4 V_19 )
{
struct V_11 * V_12 = ( V_19 == V_20 ) ?
& V_10 -> V_16 : & V_10 -> V_13 ;
T_2 V_21 = V_12 -> V_22 ;
T_2 V_23 = V_12 -> V_23 ;
F_4 ( V_10 -> V_14 , V_21 , V_23 ) ;
F_2 ( V_10 -> V_14 , V_23 ) ;
}
static int F_11 ( struct V_1 * V_10 , T_4 V_19 )
{
struct V_11 * V_12 = ( V_19 == V_20 ) ?
& V_10 -> V_16 : & V_10 -> V_13 ;
T_2 V_21 = V_12 -> V_22 ;
T_2 V_24 = V_12 -> V_24 ;
T_2 V_23 = V_12 -> V_23 ;
T_2 V_25 = F_2 ( V_10 -> V_14 , V_24 ) ;
T_2 V_26 = F_2 ( V_10 -> V_14 , V_23 ) ;
return ( int ) ( V_25 & V_26 & V_21 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
int V_27 ;
int V_28 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( F_13 ( ! V_10 ) )
return;
if ( V_10 -> V_29 )
V_28 = V_30 ;
else
V_28 = V_31 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_10 -> V_32 [ V_27 ] = F_2 ( V_10 -> V_14 , V_27 * sizeof( T_2 ) ) ;
F_14 ( V_10 -> V_33 , L_1 , V_34 ,
V_27 , V_10 -> V_32 [ V_27 ] ) ;
}
}
void F_15 ( struct V_2 * V_3 )
{
int V_27 ;
int V_28 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( F_13 ( ! V_10 ) )
return;
if ( V_10 -> V_29 )
V_28 = V_30 ;
else
V_28 = V_31 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_4 ( V_10 -> V_14 , V_10 -> V_32 [ V_27 ] , V_27 * sizeof( T_2 ) ) ;
F_14 ( V_10 -> V_33 , L_1 , V_34 ,
V_27 , V_10 -> V_32 [ V_27 ] ) ;
}
}
static void F_16 ( struct V_1 * V_10 , T_4 V_19 )
{
T_2 V_35 ;
struct V_11 * V_12 = ( V_19 == V_20 ) ?
& V_10 -> V_16 : & V_10 -> V_13 ;
T_2 V_21 = V_12 -> V_22 ;
T_2 V_24 = V_12 -> V_24 ;
V_35 = F_2 ( V_10 -> V_14 , V_24 ) ;
V_35 |= V_21 ;
F_4 ( V_10 -> V_14 , V_35 , V_24 ) ;
}
static void F_17 ( struct V_1 * V_10 , T_4 V_19 )
{
struct V_11 * V_12 = ( V_19 == V_20 ) ?
& V_10 -> V_16 : & V_10 -> V_13 ;
T_2 V_21 = V_12 -> V_22 ;
T_2 V_36 = V_12 -> V_36 ;
if ( ! V_10 -> V_29 )
V_21 = F_2 ( V_10 -> V_14 , V_36 ) & ~ V_21 ;
F_4 ( V_10 -> V_14 , V_21 , V_36 ) ;
}
void F_18 ( struct V_2 * V_3 , T_4 V_19 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( F_13 ( ! V_10 ) )
return;
F_16 ( V_10 , V_19 ) ;
}
void F_19 ( struct V_2 * V_3 , T_4 V_19 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( F_13 ( ! V_10 ) )
return;
F_17 ( V_10 , V_19 ) ;
}
static void F_20 ( struct V_37 * V_38 )
{
struct V_39 * V_40 =
F_21 ( V_38 , struct V_39 , V_38 ) ;
T_3 V_15 ;
int V_41 ;
while ( F_22 ( & V_40 -> V_12 ) >= sizeof( V_15 ) ) {
V_41 = F_23 ( & V_40 -> V_12 , ( unsigned char * ) & V_15 , sizeof( V_15 ) ) ;
F_13 ( V_41 != sizeof( V_15 ) ) ;
F_24 ( V_40 -> V_10 -> V_3 , ( void * ) V_15 ) ;
F_25 ( & V_40 -> V_42 ) ;
if ( V_40 -> V_43 ) {
V_40 -> V_43 = false ;
F_16 ( V_40 -> V_10 , V_44 ) ;
}
F_26 ( & V_40 -> V_42 ) ;
}
}
static void F_27 ( struct V_1 * V_10 )
{
F_17 ( V_10 , V_20 ) ;
F_10 ( V_10 , V_20 ) ;
F_28 ( V_10 -> V_3 , 0 ) ;
}
static void F_29 ( struct V_1 * V_10 )
{
struct V_39 * V_40 = V_10 -> V_45 ;
T_3 V_15 ;
int V_41 ;
while ( ! F_8 ( V_10 ) ) {
if ( F_30 ( F_31 ( & V_40 -> V_12 ) < sizeof( V_15 ) ) ) {
F_17 ( V_10 , V_44 ) ;
V_40 -> V_43 = true ;
goto V_46;
}
V_15 = F_6 ( V_10 ) ;
V_41 = F_32 ( & V_40 -> V_12 , ( unsigned char * ) & V_15 , sizeof( V_15 ) ) ;
F_13 ( V_41 != sizeof( V_15 ) ) ;
}
F_10 ( V_10 , V_44 ) ;
V_46:
F_33 ( & V_10 -> V_45 -> V_38 ) ;
}
static T_5 F_34 ( int V_19 , void * V_47 )
{
struct V_1 * V_10 = V_47 ;
if ( F_11 ( V_10 , V_20 ) )
F_27 ( V_10 ) ;
if ( F_11 ( V_10 , V_44 ) )
F_29 ( V_10 ) ;
return V_48 ;
}
static struct V_39 * F_35 ( struct V_1 * V_10 ,
void (* V_38)( struct V_37 * ) )
{
struct V_39 * V_40 ;
if ( ! V_38 )
return NULL ;
V_40 = F_36 ( sizeof( struct V_39 ) , V_49 ) ;
if ( ! V_40 )
return NULL ;
F_37 ( & V_40 -> V_42 ) ;
if ( F_38 ( & V_40 -> V_12 , V_50 , V_49 ) )
goto error;
F_39 ( & V_40 -> V_38 , V_38 ) ;
return V_40 ;
error:
F_40 ( V_40 ) ;
return NULL ;
}
static void F_41 ( struct V_39 * V_51 )
{
F_42 ( & V_51 -> V_12 ) ;
F_40 ( V_51 ) ;
}
static int F_43 ( struct V_1 * V_10 )
{
int V_52 = 0 ;
struct V_39 * V_40 ;
V_40 = F_35 ( V_10 , F_20 ) ;
if ( ! V_40 )
return - V_53 ;
V_10 -> V_45 = V_40 ;
V_40 -> V_10 = V_10 ;
V_52 = F_44 ( V_10 -> V_19 , F_34 , V_54 ,
V_10 -> V_55 , V_10 ) ;
if ( F_30 ( V_52 ) ) {
F_45 ( L_2 , V_52 ) ;
goto V_56;
}
F_16 ( V_10 , V_44 ) ;
return 0 ;
V_56:
F_41 ( V_10 -> V_45 ) ;
return V_52 ;
}
static void F_46 ( struct V_1 * V_10 )
{
F_17 ( V_10 , V_44 ) ;
F_47 ( V_10 -> V_19 , V_10 ) ;
F_48 ( & V_10 -> V_45 -> V_38 ) ;
F_41 ( V_10 -> V_45 ) ;
}
static struct V_1 * F_49 ( struct V_5 * V_6 ,
const char * V_57 )
{
struct V_1 * V_58 , * V_10 = NULL ;
struct V_1 * * V_59 = V_6 -> V_59 ;
int V_27 ;
if ( ! V_59 )
return NULL ;
for ( V_27 = 0 ; ( V_58 = V_59 [ V_27 ] ) ; V_27 ++ ) {
if ( ! strcmp ( V_58 -> V_55 , V_57 ) ) {
V_10 = V_58 ;
break;
}
}
return V_10 ;
}
struct V_2 * F_50 ( struct V_60 * V_61 ,
const char * V_62 )
{
struct V_63 * V_33 = V_61 -> V_33 ;
struct V_1 * V_10 = NULL ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_64 ;
int V_52 ;
if ( ! V_33 )
return F_51 ( - V_65 ) ;
if ( V_33 -> V_66 ) {
F_45 ( L_3 ,
V_34 ) ;
return F_51 ( - V_65 ) ;
}
F_52 ( & V_67 ) ;
F_53 (mdev, &omap_mbox_devices, elem) {
V_10 = F_49 ( V_6 , V_62 ) ;
if ( V_10 )
break;
}
F_54 ( & V_67 ) ;
if ( ! V_10 || ! V_10 -> V_3 )
return F_51 ( - V_68 ) ;
V_3 = V_10 -> V_3 ;
F_55 ( & V_3 -> V_42 , V_64 ) ;
V_3 -> V_69 = 0 ;
V_3 -> V_70 = 0 ;
V_3 -> V_71 = NULL ;
V_3 -> V_61 = V_61 ;
F_56 ( & V_3 -> V_72 ) ;
F_57 ( & V_3 -> V_42 , V_64 ) ;
V_52 = V_3 -> V_10 -> V_73 -> V_74 ( V_3 ) ;
if ( V_52 ) {
F_45 ( L_4 , V_52 ) ;
F_58 ( V_3 ) ;
V_3 = F_51 ( V_52 ) ;
}
return V_3 ;
}
static int F_59 ( struct V_5 * V_6 )
{
int V_52 ;
int V_27 ;
struct V_1 * * V_59 ;
if ( ! V_6 || ! V_6 -> V_59 )
return - V_75 ;
V_59 = V_6 -> V_59 ;
for ( V_27 = 0 ; V_59 [ V_27 ] ; V_27 ++ ) {
struct V_1 * V_10 = V_59 [ V_27 ] ;
V_10 -> V_33 = F_60 ( & V_76 , V_6 -> V_33 ,
0 , V_10 , L_5 , V_10 -> V_55 ) ;
if ( F_61 ( V_10 -> V_33 ) ) {
V_52 = F_62 ( V_10 -> V_33 ) ;
goto V_77;
}
}
F_52 ( & V_67 ) ;
F_63 ( & V_6 -> V_78 , & V_79 ) ;
F_54 ( & V_67 ) ;
V_52 = F_64 ( & V_6 -> V_80 ) ;
V_77:
if ( V_52 ) {
while ( V_27 -- )
F_65 ( V_59 [ V_27 ] -> V_33 ) ;
}
return V_52 ;
}
static int F_66 ( struct V_5 * V_6 )
{
int V_27 ;
struct V_1 * * V_59 ;
if ( ! V_6 || ! V_6 -> V_59 )
return - V_75 ;
F_52 ( & V_67 ) ;
F_67 ( & V_6 -> V_78 ) ;
F_54 ( & V_67 ) ;
F_68 ( & V_6 -> V_80 ) ;
V_59 = V_6 -> V_59 ;
for ( V_27 = 0 ; V_59 [ V_27 ] ; V_27 ++ )
F_65 ( V_59 [ V_27 ] -> V_33 ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_10 -> V_14 ;
int V_52 = 0 ;
F_52 ( & V_6 -> V_81 ) ;
F_70 ( V_6 -> V_33 ) ;
V_52 = F_43 ( V_10 ) ;
if ( V_52 )
F_71 ( V_6 -> V_33 ) ;
F_54 ( & V_6 -> V_81 ) ;
return V_52 ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_10 -> V_14 ;
F_52 ( & V_6 -> V_81 ) ;
F_46 ( V_10 ) ;
F_71 ( V_6 -> V_33 ) ;
F_54 ( & V_6 -> V_81 ) ;
}
static int F_73 ( struct V_2 * V_3 , void * V_82 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_52 = - V_83 ;
if ( ! V_10 )
return - V_75 ;
if ( ! F_9 ( V_10 ) ) {
F_7 ( V_10 , ( T_3 ) V_82 ) ;
V_52 = 0 ;
}
F_16 ( V_10 , V_20 ) ;
return V_52 ;
}
static struct V_2 * F_74 ( struct V_84 * V_80 ,
const struct V_85 * V_86 )
{
T_6 T_6 = V_86 -> args [ 0 ] ;
struct V_87 * V_88 ;
struct V_5 * V_6 ;
struct V_1 * V_10 ;
V_6 = F_21 ( V_80 , struct V_5 , V_80 ) ;
if ( F_13 ( ! V_6 ) )
return NULL ;
V_88 = F_75 ( T_6 ) ;
if ( ! V_88 ) {
F_45 ( L_6 ,
V_34 , T_6 ) ;
return NULL ;
}
V_10 = F_49 ( V_6 , V_88 -> V_55 ) ;
F_76 ( V_88 ) ;
return V_10 ? V_10 -> V_3 : NULL ;
}
static int F_77 ( struct V_89 * V_90 )
{
struct V_91 * V_92 ;
int V_52 ;
struct V_2 * V_93 ;
struct V_1 * * V_94 , * V_10 , * V_95 ;
struct V_96 * V_97 = V_90 -> V_33 . V_98 ;
struct V_99 * V_100 = NULL ;
struct V_101 * V_102 , * V_103 ;
struct V_5 * V_6 ;
struct V_11 * V_12 ;
struct V_87 * V_88 = V_90 -> V_33 . V_66 ;
struct V_87 * V_104 ;
const struct V_105 * V_106 ;
T_2 V_29 , V_107 ;
T_2 V_108 , V_109 ;
T_2 V_110 [ 3 ] ;
T_2 V_35 ;
int V_27 ;
if ( ! V_88 && ( ! V_97 || ! V_97 -> V_111 || ! V_97 -> V_100 ) ) {
F_45 ( L_7 , V_34 ) ;
return - V_65 ;
}
if ( V_88 ) {
V_106 = F_78 ( V_112 , & V_90 -> V_33 ) ;
if ( ! V_106 )
return - V_65 ;
V_29 = ( T_2 ) V_106 -> V_82 ;
if ( F_79 ( V_88 , L_8 ,
& V_108 ) )
return - V_65 ;
if ( F_79 ( V_88 , L_9 ,
& V_109 ) )
return - V_65 ;
V_107 = F_80 ( V_88 ) ;
if ( ! V_107 ) {
F_81 ( & V_90 -> V_33 , L_10 ) ;
return - V_65 ;
}
} else {
V_107 = V_97 -> V_111 ;
V_100 = V_97 -> V_100 ;
V_29 = V_97 -> V_29 ;
V_108 = V_97 -> V_108 ;
V_109 = V_97 -> V_109 ;
}
V_103 = F_82 ( & V_90 -> V_33 , V_107 * sizeof( * V_103 ) ,
V_49 ) ;
if ( ! V_103 )
return - V_53 ;
V_102 = V_103 ;
V_104 = NULL ;
for ( V_27 = 0 ; V_27 < V_107 ; V_27 ++ , V_102 ++ ) {
if ( V_88 ) {
V_104 = F_83 ( V_88 , V_104 ) ;
V_52 = F_84 ( V_104 , L_11 ,
V_110 , F_85 ( V_110 ) ) ;
if ( V_52 )
return V_52 ;
V_102 -> V_113 = V_110 [ 0 ] ;
V_102 -> V_114 = V_110 [ 1 ] ;
V_102 -> V_115 = V_110 [ 2 ] ;
V_52 = F_84 ( V_104 , L_12 ,
V_110 , F_85 ( V_110 ) ) ;
if ( V_52 )
return V_52 ;
V_102 -> V_116 = V_110 [ 0 ] ;
V_102 -> V_117 = V_110 [ 1 ] ;
V_102 -> V_118 = V_110 [ 2 ] ;
V_102 -> V_55 = V_104 -> V_55 ;
} else {
V_102 -> V_113 = V_100 -> V_113 ;
V_102 -> V_116 = V_100 -> V_116 ;
V_102 -> V_115 = V_100 -> V_119 ;
V_102 -> V_114 = V_100 -> V_120 ;
V_102 -> V_118 = V_100 -> V_119 ;
V_102 -> V_117 = V_100 -> V_120 ;
V_102 -> V_55 = V_100 -> V_55 ;
V_100 ++ ;
}
if ( V_102 -> V_113 >= V_109 || V_102 -> V_116 >= V_109 ||
V_102 -> V_115 >= V_108 || V_102 -> V_118 >= V_108 )
return - V_75 ;
}
V_6 = F_82 ( & V_90 -> V_33 , sizeof( * V_6 ) , V_49 ) ;
if ( ! V_6 )
return - V_53 ;
V_92 = F_86 ( V_90 , V_121 , 0 ) ;
V_6 -> V_8 = F_87 ( & V_90 -> V_33 , V_92 ) ;
if ( F_61 ( V_6 -> V_8 ) )
return F_62 ( V_6 -> V_8 ) ;
V_94 = F_82 ( & V_90 -> V_33 , ( V_107 + 1 ) * sizeof( * V_94 ) ,
V_49 ) ;
if ( ! V_94 )
return - V_53 ;
V_93 = F_82 ( & V_90 -> V_33 , ( V_107 + 1 ) * sizeof( * V_93 ) ,
V_49 ) ;
if ( ! V_93 )
return - V_53 ;
V_95 = F_82 ( & V_90 -> V_33 , V_107 * sizeof( * V_10 ) ,
V_49 ) ;
if ( ! V_95 )
return - V_53 ;
V_10 = V_95 ;
V_102 = V_103 ;
for ( V_27 = 0 ; V_27 < V_107 ; V_27 ++ , V_102 ++ ) {
V_12 = & V_10 -> V_16 ;
V_12 -> V_15 = F_88 ( V_102 -> V_113 ) ;
V_12 -> V_18 = F_89 ( V_102 -> V_113 ) ;
V_12 -> V_22 = F_90 ( V_102 -> V_113 ) ;
V_12 -> V_24 = F_91 ( V_29 , V_102 -> V_115 ) ;
V_12 -> V_23 = F_92 ( V_29 , V_102 -> V_115 ) ;
V_12 -> V_36 = F_93 ( V_29 , V_102 -> V_115 ) ;
V_12 = & V_10 -> V_13 ;
V_12 -> V_15 = F_88 ( V_102 -> V_116 ) ;
V_12 -> V_17 = F_94 ( V_102 -> V_116 ) ;
V_12 -> V_22 = F_95 ( V_102 -> V_116 ) ;
V_12 -> V_24 = F_91 ( V_29 , V_102 -> V_118 ) ;
V_12 -> V_23 = F_92 ( V_29 , V_102 -> V_118 ) ;
V_12 -> V_36 = F_93 ( V_29 , V_102 -> V_118 ) ;
V_10 -> V_29 = V_29 ;
V_10 -> V_14 = V_6 ;
V_10 -> V_55 = V_102 -> V_55 ;
V_10 -> V_19 = F_96 ( V_90 , V_102 -> V_114 ) ;
if ( V_10 -> V_19 < 0 )
return V_10 -> V_19 ;
V_10 -> V_3 = & V_93 [ V_27 ] ;
V_93 [ V_27 ] . V_4 = V_10 ;
V_94 [ V_27 ] = V_10 ++ ;
}
F_97 ( & V_6 -> V_81 ) ;
V_6 -> V_33 = & V_90 -> V_33 ;
V_6 -> V_108 = V_108 ;
V_6 -> V_109 = V_109 ;
V_6 -> V_59 = V_94 ;
V_6 -> V_80 . V_122 = true ;
V_6 -> V_80 . V_33 = V_6 -> V_33 ;
V_6 -> V_80 . V_73 = & V_123 ;
V_6 -> V_80 . V_124 = V_93 ;
V_6 -> V_80 . V_125 = V_107 ;
V_6 -> V_80 . V_126 = F_74 ;
V_52 = F_59 ( V_6 ) ;
if ( V_52 )
return V_52 ;
F_98 ( V_90 , V_6 ) ;
F_99 ( V_6 -> V_33 ) ;
V_52 = F_70 ( V_6 -> V_33 ) ;
if ( V_52 < 0 ) {
F_100 ( V_6 -> V_33 ) ;
goto V_127;
}
V_35 = F_2 ( V_6 , V_128 ) ;
F_101 ( V_6 -> V_33 , L_13 , V_35 ) ;
V_52 = F_71 ( V_6 -> V_33 ) ;
if ( V_52 < 0 )
goto V_127;
F_102 ( & V_90 -> V_33 , V_103 ) ;
return 0 ;
V_127:
F_103 ( V_6 -> V_33 ) ;
F_66 ( V_6 ) ;
return V_52 ;
}
static int F_104 ( struct V_89 * V_90 )
{
struct V_5 * V_6 = F_105 ( V_90 ) ;
F_103 ( V_6 -> V_33 ) ;
F_66 ( V_6 ) ;
return 0 ;
}
static int T_7 F_106 ( void )
{
int V_129 ;
V_129 = F_107 ( & V_76 ) ;
if ( V_129 )
return V_129 ;
V_50 = F_108 ( V_50 , sizeof( T_3 ) ) ;
V_50 = F_109 (unsigned int, mbox_kfifo_size,
sizeof(mbox_msg_t)) ;
return F_110 ( & V_130 ) ;
}
static void T_8 F_111 ( void )
{
F_112 ( & V_130 ) ;
F_113 ( & V_76 ) ;
}
