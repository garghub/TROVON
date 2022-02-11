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
static void F_12 ( struct V_1 * V_10 , T_4 V_19 )
{
T_2 V_27 ;
struct V_11 * V_12 = ( V_19 == V_20 ) ?
& V_10 -> V_16 : & V_10 -> V_13 ;
T_2 V_21 = V_12 -> V_22 ;
T_2 V_24 = V_12 -> V_24 ;
V_27 = F_2 ( V_10 -> V_14 , V_24 ) ;
V_27 |= V_21 ;
F_4 ( V_10 -> V_14 , V_27 , V_24 ) ;
}
static void F_13 ( struct V_1 * V_10 , T_4 V_19 )
{
struct V_11 * V_12 = ( V_19 == V_20 ) ?
& V_10 -> V_16 : & V_10 -> V_13 ;
T_2 V_21 = V_12 -> V_22 ;
T_2 V_28 = V_12 -> V_28 ;
if ( ! V_10 -> V_29 )
V_21 = F_2 ( V_10 -> V_14 , V_28 ) & ~ V_21 ;
F_4 ( V_10 -> V_14 , V_21 , V_28 ) ;
}
void F_14 ( struct V_2 * V_3 , T_4 V_19 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( F_15 ( ! V_10 ) )
return;
F_12 ( V_10 , V_19 ) ;
}
void F_16 ( struct V_2 * V_3 , T_4 V_19 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( F_15 ( ! V_10 ) )
return;
F_13 ( V_10 , V_19 ) ;
}
static void F_17 ( struct V_30 * V_31 )
{
struct V_32 * V_33 =
F_18 ( V_31 , struct V_32 , V_31 ) ;
T_3 V_15 ;
int V_34 ;
while ( F_19 ( & V_33 -> V_12 ) >= sizeof( V_15 ) ) {
V_34 = F_20 ( & V_33 -> V_12 , ( unsigned char * ) & V_15 , sizeof( V_15 ) ) ;
F_15 ( V_34 != sizeof( V_15 ) ) ;
F_21 ( V_33 -> V_10 -> V_3 , ( void * ) V_15 ) ;
F_22 ( & V_33 -> V_35 ) ;
if ( V_33 -> V_36 ) {
V_33 -> V_36 = false ;
F_12 ( V_33 -> V_10 , V_37 ) ;
}
F_23 ( & V_33 -> V_35 ) ;
}
}
static void F_24 ( struct V_1 * V_10 )
{
F_13 ( V_10 , V_20 ) ;
F_10 ( V_10 , V_20 ) ;
F_25 ( V_10 -> V_3 , 0 ) ;
}
static void F_26 ( struct V_1 * V_10 )
{
struct V_32 * V_33 = V_10 -> V_38 ;
T_3 V_15 ;
int V_34 ;
while ( ! F_8 ( V_10 ) ) {
if ( F_27 ( F_28 ( & V_33 -> V_12 ) < sizeof( V_15 ) ) ) {
F_13 ( V_10 , V_37 ) ;
V_33 -> V_36 = true ;
goto V_39;
}
V_15 = F_6 ( V_10 ) ;
V_34 = F_29 ( & V_33 -> V_12 , ( unsigned char * ) & V_15 , sizeof( V_15 ) ) ;
F_15 ( V_34 != sizeof( V_15 ) ) ;
}
F_10 ( V_10 , V_37 ) ;
V_39:
F_30 ( & V_10 -> V_38 -> V_31 ) ;
}
static T_5 F_31 ( int V_19 , void * V_40 )
{
struct V_1 * V_10 = V_40 ;
if ( F_11 ( V_10 , V_20 ) )
F_24 ( V_10 ) ;
if ( F_11 ( V_10 , V_37 ) )
F_26 ( V_10 ) ;
return V_41 ;
}
static struct V_32 * F_32 ( struct V_1 * V_10 ,
void (* V_31)( struct V_30 * ) )
{
struct V_32 * V_33 ;
if ( ! V_31 )
return NULL ;
V_33 = F_33 ( sizeof( * V_33 ) , V_42 ) ;
if ( ! V_33 )
return NULL ;
F_34 ( & V_33 -> V_35 ) ;
if ( F_35 ( & V_33 -> V_12 , V_43 , V_42 ) )
goto error;
F_36 ( & V_33 -> V_31 , V_31 ) ;
return V_33 ;
error:
F_37 ( V_33 ) ;
return NULL ;
}
static void F_38 ( struct V_32 * V_44 )
{
F_39 ( & V_44 -> V_12 ) ;
F_37 ( V_44 ) ;
}
static int F_40 ( struct V_1 * V_10 )
{
int V_45 = 0 ;
struct V_32 * V_33 ;
V_33 = F_32 ( V_10 , F_17 ) ;
if ( ! V_33 )
return - V_46 ;
V_10 -> V_38 = V_33 ;
V_33 -> V_10 = V_10 ;
V_45 = F_41 ( V_10 -> V_19 , F_31 , V_47 ,
V_10 -> V_48 , V_10 ) ;
if ( F_27 ( V_45 ) ) {
F_42 ( L_1 , V_45 ) ;
goto V_49;
}
if ( V_10 -> V_50 )
V_10 -> V_3 -> V_51 = V_52 ;
F_12 ( V_10 , V_37 ) ;
return 0 ;
V_49:
F_38 ( V_10 -> V_38 ) ;
return V_45 ;
}
static void F_43 ( struct V_1 * V_10 )
{
F_13 ( V_10 , V_37 ) ;
F_44 ( V_10 -> V_19 , V_10 ) ;
F_45 ( & V_10 -> V_38 -> V_31 ) ;
F_38 ( V_10 -> V_38 ) ;
}
static struct V_1 * F_46 ( struct V_5 * V_6 ,
const char * V_53 )
{
struct V_1 * V_54 , * V_10 = NULL ;
struct V_1 * * V_55 = V_6 -> V_55 ;
int V_56 ;
if ( ! V_55 )
return NULL ;
for ( V_56 = 0 ; ( V_54 = V_55 [ V_56 ] ) ; V_56 ++ ) {
if ( ! strcmp ( V_54 -> V_48 , V_53 ) ) {
V_10 = V_54 ;
break;
}
}
return V_10 ;
}
struct V_2 * F_47 ( struct V_57 * V_58 ,
const char * V_59 )
{
struct V_60 * V_61 = V_58 -> V_61 ;
struct V_1 * V_10 = NULL ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
unsigned long V_62 ;
int V_45 ;
if ( ! V_61 )
return F_48 ( - V_63 ) ;
if ( V_61 -> V_64 ) {
F_42 ( L_2 ,
V_65 ) ;
return F_48 ( - V_63 ) ;
}
F_49 ( & V_66 ) ;
F_50 (mdev, &omap_mbox_devices, elem) {
V_10 = F_46 ( V_6 , V_59 ) ;
if ( V_10 )
break;
}
F_51 ( & V_66 ) ;
if ( ! V_10 || ! V_10 -> V_3 )
return F_48 ( - V_67 ) ;
V_3 = V_10 -> V_3 ;
F_52 ( & V_3 -> V_35 , V_62 ) ;
V_3 -> V_68 = 0 ;
V_3 -> V_69 = 0 ;
V_3 -> V_70 = NULL ;
V_3 -> V_58 = V_58 ;
F_53 ( & V_3 -> V_71 ) ;
F_54 ( & V_3 -> V_35 , V_62 ) ;
V_45 = V_3 -> V_10 -> V_72 -> V_73 ( V_3 ) ;
if ( V_45 ) {
F_42 ( L_3 , V_45 ) ;
F_55 ( V_3 ) ;
V_3 = F_48 ( V_45 ) ;
}
return V_3 ;
}
static int F_56 ( struct V_5 * V_6 )
{
int V_45 ;
int V_56 ;
struct V_1 * * V_55 ;
if ( ! V_6 || ! V_6 -> V_55 )
return - V_74 ;
V_55 = V_6 -> V_55 ;
for ( V_56 = 0 ; V_55 [ V_56 ] ; V_56 ++ ) {
struct V_1 * V_10 = V_55 [ V_56 ] ;
V_10 -> V_61 = F_57 ( & V_75 , V_6 -> V_61 ,
0 , V_10 , L_4 , V_10 -> V_48 ) ;
if ( F_58 ( V_10 -> V_61 ) ) {
V_45 = F_59 ( V_10 -> V_61 ) ;
goto V_76;
}
}
F_49 ( & V_66 ) ;
F_60 ( & V_6 -> V_77 , & V_78 ) ;
F_51 ( & V_66 ) ;
V_45 = F_61 ( & V_6 -> V_79 ) ;
V_76:
if ( V_45 ) {
while ( V_56 -- )
F_62 ( V_55 [ V_56 ] -> V_61 ) ;
}
return V_45 ;
}
static int F_63 ( struct V_5 * V_6 )
{
int V_56 ;
struct V_1 * * V_55 ;
if ( ! V_6 || ! V_6 -> V_55 )
return - V_74 ;
F_49 ( & V_66 ) ;
F_64 ( & V_6 -> V_77 ) ;
F_51 ( & V_66 ) ;
F_65 ( & V_6 -> V_79 ) ;
V_55 = V_6 -> V_55 ;
for ( V_56 = 0 ; V_55 [ V_56 ] ; V_56 ++ )
F_62 ( V_55 [ V_56 ] -> V_61 ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_10 -> V_14 ;
int V_45 = 0 ;
F_49 ( & V_6 -> V_80 ) ;
F_67 ( V_6 -> V_61 ) ;
V_45 = F_40 ( V_10 ) ;
if ( V_45 )
F_68 ( V_6 -> V_61 ) ;
F_51 ( & V_6 -> V_80 ) ;
return V_45 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_10 -> V_14 ;
F_49 ( & V_6 -> V_80 ) ;
F_43 ( V_10 ) ;
F_68 ( V_6 -> V_61 ) ;
F_51 ( & V_6 -> V_80 ) ;
}
static int F_70 ( struct V_1 * V_10 , void * V_81 )
{
int V_45 = - V_82 ;
if ( ! F_9 ( V_10 ) ) {
F_12 ( V_10 , V_37 ) ;
F_7 ( V_10 , ( T_3 ) V_81 ) ;
V_45 = 0 ;
F_13 ( V_10 , V_37 ) ;
F_6 ( V_10 ) ;
F_10 ( V_10 , V_37 ) ;
}
return V_45 ;
}
static int F_71 ( struct V_1 * V_10 , void * V_81 )
{
int V_45 = - V_82 ;
if ( ! F_9 ( V_10 ) ) {
F_7 ( V_10 , ( T_3 ) V_81 ) ;
V_45 = 0 ;
}
F_12 ( V_10 , V_20 ) ;
return V_45 ;
}
static int F_72 ( struct V_2 * V_3 , void * V_81 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_45 ;
if ( ! V_10 )
return - V_74 ;
if ( V_10 -> V_50 )
V_45 = F_70 ( V_10 , V_81 ) ;
else
V_45 = F_71 ( V_10 , V_81 ) ;
return V_45 ;
}
static int F_73 ( struct V_60 * V_61 )
{
struct V_5 * V_6 = F_74 ( V_61 ) ;
T_2 V_83 , V_12 , V_84 ;
if ( F_75 ( V_61 ) )
return 0 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_85 ; V_12 ++ ) {
if ( F_2 ( V_6 , F_76 ( V_12 ) ) ) {
F_77 ( V_6 -> V_61 , L_5 ,
V_12 ) ;
return - V_82 ;
}
}
for ( V_83 = 0 ; V_83 < V_6 -> V_86 ; V_83 ++ ) {
V_84 = F_78 ( V_6 -> V_29 , V_83 ) ;
V_6 -> V_87 [ V_83 ] = F_2 ( V_6 , V_84 ) ;
}
return 0 ;
}
static int F_79 ( struct V_60 * V_61 )
{
struct V_5 * V_6 = F_74 ( V_61 ) ;
T_2 V_83 , V_84 ;
if ( F_75 ( V_61 ) )
return 0 ;
for ( V_83 = 0 ; V_83 < V_6 -> V_86 ; V_83 ++ ) {
V_84 = F_78 ( V_6 -> V_29 , V_83 ) ;
F_4 ( V_6 , V_6 -> V_87 [ V_83 ] , V_84 ) ;
}
return 0 ;
}
static struct V_2 * F_80 ( struct V_88 * V_79 ,
const struct V_89 * V_90 )
{
T_6 T_6 = V_90 -> args [ 0 ] ;
struct V_91 * V_92 ;
struct V_5 * V_6 ;
struct V_1 * V_10 ;
V_6 = F_18 ( V_79 , struct V_5 , V_79 ) ;
if ( F_15 ( ! V_6 ) )
return F_48 ( - V_74 ) ;
V_92 = F_81 ( T_6 ) ;
if ( ! V_92 ) {
F_42 ( L_6 ,
V_65 , T_6 ) ;
return F_48 ( - V_63 ) ;
}
V_10 = F_46 ( V_6 , V_92 -> V_48 ) ;
F_82 ( V_92 ) ;
return V_10 ? V_10 -> V_3 : F_48 ( - V_67 ) ;
}
static int F_83 ( struct V_93 * V_94 )
{
struct V_95 * V_96 ;
int V_45 ;
struct V_2 * V_97 ;
struct V_1 * * V_98 , * V_10 , * V_99 ;
struct V_100 * V_101 , * V_102 ;
struct V_5 * V_6 ;
struct V_11 * V_12 ;
struct V_91 * V_92 = V_94 -> V_61 . V_64 ;
struct V_91 * V_103 ;
const struct V_104 * V_105 ;
T_2 V_29 , V_106 ;
T_2 V_86 , V_85 ;
T_2 V_107 [ 3 ] ;
T_2 V_27 ;
int V_56 ;
if ( ! V_92 ) {
F_42 ( L_7 , V_65 ) ;
return - V_63 ;
}
V_105 = F_84 ( V_108 , & V_94 -> V_61 ) ;
if ( ! V_105 )
return - V_63 ;
V_29 = ( T_2 ) V_105 -> V_81 ;
if ( F_85 ( V_92 , L_8 , & V_86 ) )
return - V_63 ;
if ( F_85 ( V_92 , L_9 , & V_85 ) )
return - V_63 ;
V_106 = F_86 ( V_92 ) ;
if ( ! V_106 ) {
F_77 ( & V_94 -> V_61 , L_10 ) ;
return - V_63 ;
}
V_102 = F_87 ( & V_94 -> V_61 , V_106 * sizeof( * V_102 ) ,
V_42 ) ;
if ( ! V_102 )
return - V_46 ;
V_101 = V_102 ;
V_103 = NULL ;
for ( V_56 = 0 ; V_56 < V_106 ; V_56 ++ , V_101 ++ ) {
V_103 = F_88 ( V_92 , V_103 ) ;
V_45 = F_89 ( V_103 , L_11 , V_107 ,
F_90 ( V_107 ) ) ;
if ( V_45 )
return V_45 ;
V_101 -> V_109 = V_107 [ 0 ] ;
V_101 -> V_110 = V_107 [ 1 ] ;
V_101 -> V_111 = V_107 [ 2 ] ;
V_45 = F_89 ( V_103 , L_12 , V_107 ,
F_90 ( V_107 ) ) ;
if ( V_45 )
return V_45 ;
V_101 -> V_112 = V_107 [ 0 ] ;
V_101 -> V_113 = V_107 [ 1 ] ;
V_101 -> V_114 = V_107 [ 2 ] ;
V_101 -> V_48 = V_103 -> V_48 ;
if ( F_91 ( V_103 , L_13 , NULL ) )
V_101 -> V_50 = true ;
if ( V_101 -> V_109 >= V_85 || V_101 -> V_112 >= V_85 ||
V_101 -> V_111 >= V_86 || V_101 -> V_114 >= V_86 )
return - V_74 ;
}
V_6 = F_87 ( & V_94 -> V_61 , sizeof( * V_6 ) , V_42 ) ;
if ( ! V_6 )
return - V_46 ;
V_96 = F_92 ( V_94 , V_115 , 0 ) ;
V_6 -> V_8 = F_93 ( & V_94 -> V_61 , V_96 ) ;
if ( F_58 ( V_6 -> V_8 ) )
return F_59 ( V_6 -> V_8 ) ;
V_6 -> V_87 = F_87 ( & V_94 -> V_61 , V_86 * sizeof( T_2 ) ,
V_42 ) ;
if ( ! V_6 -> V_87 )
return - V_46 ;
V_98 = F_87 ( & V_94 -> V_61 , ( V_106 + 1 ) * sizeof( * V_98 ) ,
V_42 ) ;
if ( ! V_98 )
return - V_46 ;
V_97 = F_87 ( & V_94 -> V_61 , ( V_106 + 1 ) * sizeof( * V_97 ) ,
V_42 ) ;
if ( ! V_97 )
return - V_46 ;
V_99 = F_87 ( & V_94 -> V_61 , V_106 * sizeof( * V_10 ) ,
V_42 ) ;
if ( ! V_99 )
return - V_46 ;
V_10 = V_99 ;
V_101 = V_102 ;
for ( V_56 = 0 ; V_56 < V_106 ; V_56 ++ , V_101 ++ ) {
V_12 = & V_10 -> V_16 ;
V_12 -> V_15 = F_94 ( V_101 -> V_109 ) ;
V_12 -> V_18 = F_95 ( V_101 -> V_109 ) ;
V_12 -> V_22 = F_96 ( V_101 -> V_109 ) ;
V_12 -> V_24 = F_78 ( V_29 , V_101 -> V_111 ) ;
V_12 -> V_23 = F_97 ( V_29 , V_101 -> V_111 ) ;
V_12 -> V_28 = F_98 ( V_29 , V_101 -> V_111 ) ;
V_12 = & V_10 -> V_13 ;
V_12 -> V_15 = F_94 ( V_101 -> V_112 ) ;
V_12 -> V_17 = F_76 ( V_101 -> V_112 ) ;
V_12 -> V_22 = F_99 ( V_101 -> V_112 ) ;
V_12 -> V_24 = F_78 ( V_29 , V_101 -> V_114 ) ;
V_12 -> V_23 = F_97 ( V_29 , V_101 -> V_114 ) ;
V_12 -> V_28 = F_98 ( V_29 , V_101 -> V_114 ) ;
V_10 -> V_50 = V_101 -> V_50 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_14 = V_6 ;
V_10 -> V_48 = V_101 -> V_48 ;
V_10 -> V_19 = F_100 ( V_94 , V_101 -> V_110 ) ;
if ( V_10 -> V_19 < 0 )
return V_10 -> V_19 ;
V_10 -> V_3 = & V_97 [ V_56 ] ;
V_97 [ V_56 ] . V_4 = V_10 ;
V_98 [ V_56 ] = V_10 ++ ;
}
F_101 ( & V_6 -> V_80 ) ;
V_6 -> V_61 = & V_94 -> V_61 ;
V_6 -> V_86 = V_86 ;
V_6 -> V_85 = V_85 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_55 = V_98 ;
V_6 -> V_79 . V_116 = true ;
V_6 -> V_79 . V_61 = V_6 -> V_61 ;
V_6 -> V_79 . V_72 = & V_117 ;
V_6 -> V_79 . V_118 = V_97 ;
V_6 -> V_79 . V_119 = V_106 ;
V_6 -> V_79 . V_120 = F_80 ;
V_45 = F_56 ( V_6 ) ;
if ( V_45 )
return V_45 ;
F_102 ( V_94 , V_6 ) ;
F_103 ( V_6 -> V_61 ) ;
V_45 = F_67 ( V_6 -> V_61 ) ;
if ( V_45 < 0 ) {
F_104 ( V_6 -> V_61 ) ;
goto V_121;
}
V_27 = F_2 ( V_6 , V_122 ) ;
F_105 ( V_6 -> V_61 , L_14 , V_27 ) ;
V_45 = F_68 ( V_6 -> V_61 ) ;
if ( V_45 < 0 )
goto V_121;
F_106 ( & V_94 -> V_61 , V_102 ) ;
return 0 ;
V_121:
F_107 ( V_6 -> V_61 ) ;
F_63 ( V_6 ) ;
return V_45 ;
}
static int F_108 ( struct V_93 * V_94 )
{
struct V_5 * V_6 = F_109 ( V_94 ) ;
F_107 ( V_6 -> V_61 ) ;
F_63 ( V_6 ) ;
return 0 ;
}
static int T_7 F_110 ( void )
{
int V_123 ;
V_123 = F_111 ( & V_75 ) ;
if ( V_123 )
return V_123 ;
V_43 = F_112 ( V_43 , sizeof( T_3 ) ) ;
V_43 = F_113 (unsigned int, mbox_kfifo_size,
sizeof(mbox_msg_t)) ;
return F_114 ( & V_124 ) ;
}
static void T_8 F_115 ( void )
{
F_116 ( & V_124 ) ;
F_117 ( & V_75 ) ;
}
