static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_3 . V_4 . V_5 ;
}
static inline unsigned F_2 ( struct V_6 T_1 * V_7 )
{
return sizeof( * V_7 )
+ F_3 ( & V_7 -> V_8 ) * sizeof( struct V_9 )
+ F_3 ( & V_7 -> V_10 ) * 2
+ F_3 ( & V_7 -> V_11 ) ;
}
static inline struct V_9 T_1 *
F_4 ( struct V_6 T_1 * V_7 )
{
return (struct V_9 T_1 * ) ( V_7 + 1 ) ;
}
static inline T_2 T_1 *
F_5 ( struct V_6 T_1 * V_7 )
{
return ( T_2 T_1 * ) ( F_4 ( V_7 ) + F_3 ( & V_7 -> V_8 ) ) ;
}
static inline T_2 T_1 *
F_6 ( struct V_6 T_1 * V_7 )
{
return F_5 ( V_7 ) + F_3 ( & V_7 -> V_10 ) * 2 ;
}
static inline unsigned
F_7 ( struct V_6 T_1 * V_7 )
{
return F_8 ( V_7 ) + sizeof( struct V_12 ) ;
}
static T_3 F_9 ( struct V_13 * V_3 )
{
unsigned int V_14 , V_15 ;
T_4 V_16 = 0 ;
struct V_6 T_1 * V_7 = F_10 ( V_3 ) -> V_7 ;
T_2 T_1 * V_17 = F_5 ( V_7 ) ;
int V_10 = F_3 ( & V_7 -> V_10 ) ;
V_15 = F_11 ( unsigned , V_10 , sizeof( V_3 -> V_16 ) ) * 8 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
if ( F_3 ( & V_17 [ V_14 / 8 ] ) & ( F_12 ( V_14 % 8 ) ) )
V_16 |= F_12 ( V_14 ) ;
return V_16 ;
}
static int F_13 ( struct V_13 * V_3 )
{
unsigned int V_14 , V_15 ;
struct V_6 T_1 * V_7 = F_10 ( V_3 ) -> V_7 ;
T_2 V_10 = F_3 ( & V_7 -> V_10 ) ;
T_2 T_1 * V_18 =
F_5 ( V_7 ) + V_10 ;
F_14 ( V_3 ) ;
F_15 ( V_18 , 0 , V_10 ) ;
V_15 = F_11 ( unsigned , V_10 ,
sizeof( V_3 -> V_16 ) ) * 8 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( F_16 ( V_3 , V_14 ) )
F_17 ( F_3 ( & V_18 [ V_14 / 8 ] ) | ( 1 << ( V_14 % 8 ) ) ,
& V_18 [ V_14 / 8 ] ) ;
}
return 0 ;
}
static void F_18 ( struct V_13 * V_3 , unsigned int V_19 ,
void * V_20 , unsigned V_21 )
{
struct V_6 T_1 * V_7 = F_10 ( V_3 ) -> V_7 ;
if ( V_19 + V_21 > F_3 ( & V_7 -> V_11 ) )
return;
F_19 ( V_20 , F_6 ( V_7 ) + V_19 , V_21 ) ;
}
static void F_20 ( struct V_13 * V_3 , unsigned int V_19 ,
const void * V_20 , unsigned V_21 )
{
struct V_6 T_1 * V_7 = F_10 ( V_3 ) -> V_7 ;
if ( V_19 + V_21 > F_3 ( & V_7 -> V_11 ) )
return;
F_21 ( F_6 ( V_7 ) + V_19 , V_20 , V_21 ) ;
}
static T_2 F_22 ( struct V_13 * V_3 )
{
return F_3 ( & F_10 ( V_3 ) -> V_7 -> V_22 ) ;
}
static void F_23 ( struct V_13 * V_4 , T_2 V_22 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_23 * V_24 = V_3 -> V_24 ;
if ( ! V_22 )
return;
F_17 ( V_22 , & V_3 -> V_7 -> V_22 ) ;
V_24 -> V_25 -> V_26 ( V_24 , V_3 -> V_27 ) ;
}
static void F_24 ( struct V_13 * V_4 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_12 T_1 * V_28 = V_3 -> V_28 ;
struct V_23 * V_24 = V_3 -> V_24 ;
int V_29 ;
F_17 ( 0 , & V_28 -> V_30 ) ;
F_17 ( 1 , & V_28 -> V_31 ) ;
V_24 -> V_25 -> V_26 ( V_24 , V_3 -> V_27 ) ;
for ( V_29 = 100 ; V_29 -- ; ) {
if ( F_3 ( & V_28 -> V_30 ) )
break;
F_25 ( 100 ) ;
} ;
F_26 ( F_1 ( V_3 ) , L_1 , V_32 , V_29 ) ;
F_17 ( 0 , & V_3 -> V_7 -> V_22 ) ;
}
static void F_27 ( struct V_13 * V_4 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
F_26 ( F_1 ( V_3 ) , L_2 ,
V_32 , V_4 -> V_33 . V_1 ) ;
F_24 ( V_4 ) ;
F_28 ( & V_3 -> V_34 ) ;
}
static bool F_29 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_37 ;
struct V_23 * V_24 = V_3 -> V_24 ;
V_24 -> V_25 -> V_26 ( V_24 , V_3 -> V_27 ) ;
return true ;
}
static void F_30 ( struct V_35 * V_36 , int V_38 )
{
struct V_2 * V_3 = F_10 ( V_36 -> V_3 ) ;
struct V_39 * V_40 = (struct V_39 * ) ( V_36 + 1 ) ;
struct V_23 * V_24 = V_3 -> V_24 ;
F_31 ( & V_24 -> V_4 , V_3 -> V_41 [ V_38 ] ,
V_3 -> V_42 [ V_38 ] , V_43 ) ;
F_32 ( ( unsigned long ) V_40 -> V_41 , F_33 ( V_3 -> V_42 [ V_38 ] ) ) ;
F_34 ( V_36 ) ;
V_24 -> V_25 -> V_44 ( V_24 , V_3 -> V_40 [ V_38 ] ) ;
V_3 -> V_40 [ V_38 ] = NULL ;
}
static void F_35 ( struct V_13 * V_4 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_35 * V_36 , * V_38 ;
int V_45 = 0 ;
F_26 ( F_1 ( V_3 ) , L_3 , V_32 ) ;
F_36 (vq, n, &dev->vqs, list)
F_30 ( V_36 , V_45 ++ ) ;
}
static struct V_35 * F_37 ( struct V_13 * V_4 ,
unsigned V_46 ,
void (* F_38)( struct V_35 * V_36 ) ,
const char * V_47 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_23 * V_24 = V_3 -> V_24 ;
struct V_9 T_1 * V_48 ;
struct V_9 V_49 ;
struct V_35 * V_36 ;
void T_1 * V_50 ;
struct V_51 T_1 * V_52 ;
void * V_41 ;
int V_53 , V_54 , V_55 , V_56 ;
struct V_39 * V_40 ;
T_2 type = F_3 ( & V_3 -> V_7 -> type ) ;
if ( V_46 >= F_3 ( & V_3 -> V_7 -> V_8 ) )
return F_39 ( - V_57 ) ;
if ( ! V_47 )
return F_39 ( - V_57 ) ;
V_48 = F_4 ( V_3 -> V_7 ) + V_46 ;
F_19 ( & V_49 , V_48 , sizeof( V_49 ) ) ;
V_54 = F_40 ( F_41 ( V_49 . V_58 ) , V_59 ) ;
V_53 = F_42 ( V_54 + sizeof( struct V_51 ) ) ;
V_50 = V_24 -> V_25 -> V_60 ( V_24 , F_43 ( V_49 . V_61 ) ,
V_53 ) ;
if ( ! V_50 )
return F_39 ( - V_62 ) ;
V_3 -> V_40 [ V_46 ] = V_50 ;
F_15 ( V_50 , 0x0 , V_54 ) ;
V_36 = F_44 (
V_46 ,
F_41 ( V_49 . V_58 ) , V_59 ,
V_4 ,
false ,
( void V_63 * ) V_50 , F_29 , F_38 , V_47 ) ;
if ( ! V_36 ) {
V_55 = - V_62 ;
goto V_64;
}
V_52 = V_50 + V_54 ;
V_56 = F_45 ( & V_52 -> V_56 ) ;
if ( F_46 ( V_56 != V_65 + type + V_46 , L_4 ) ) {
V_55 = - V_66 ;
goto V_64;
}
V_3 -> V_42 [ V_46 ] = F_42 ( sizeof( V_67 ) * 3 +
sizeof( struct V_68 ) *
F_41 ( V_49 . V_58 ) ) ;
V_41 = ( void * ) F_47 ( V_69 | V_70 ,
F_33 ( V_3 -> V_42 [ V_46 ] ) ) ;
if ( ! V_41 ) {
V_55 = - V_62 ;
F_48 ( F_1 ( V_3 ) , L_5 ,
V_32 , __LINE__ , V_55 ) ;
goto V_71;
}
V_3 -> V_41 [ V_46 ] = F_49 ( & V_24 -> V_4 , V_41 ,
V_3 -> V_42 [ V_46 ] ,
V_43 ) ;
if ( F_50 ( & V_24 -> V_4 , V_3 -> V_41 [ V_46 ] ) ) {
V_55 = - V_62 ;
F_48 ( F_1 ( V_3 ) , L_5 ,
V_32 , __LINE__ , V_55 ) ;
goto V_72;
}
F_51 ( V_3 -> V_41 [ V_46 ] , & V_48 -> V_73 ) ;
V_40 = (struct V_39 * ) ( V_36 + 1 ) ;
V_40 -> V_41 = V_41 ;
V_36 -> V_37 = V_3 ;
return V_36 ;
V_72:
F_32 ( ( unsigned long ) V_41 ,
F_33 ( V_3 -> V_42 [ V_46 ] ) ) ;
V_71:
F_34 ( V_36 ) ;
V_64:
V_24 -> V_25 -> V_44 ( V_24 , V_3 -> V_40 [ V_46 ] ) ;
return F_39 ( V_55 ) ;
}
static int F_52 ( struct V_13 * V_4 , unsigned V_74 ,
struct V_35 * V_75 [] ,
T_5 * V_76 [] ,
const char * const V_77 [] )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_23 * V_24 = V_3 -> V_24 ;
struct V_12 T_1 * V_28 = V_3 -> V_28 ;
int V_14 , V_55 , V_29 ;
if ( V_74 > F_3 ( & V_3 -> V_7 -> V_8 ) )
return - V_57 ;
for ( V_14 = 0 ; V_14 < V_74 ; ++ V_14 ) {
F_26 ( F_1 ( V_3 ) , L_6 ,
V_32 , V_14 , V_77 [ V_14 ] ) ;
V_75 [ V_14 ] = F_37 ( V_4 , V_14 , V_76 [ V_14 ] , V_77 [ V_14 ] ) ;
if ( F_53 ( V_75 [ V_14 ] ) ) {
V_55 = F_54 ( V_75 [ V_14 ] ) ;
goto error;
}
}
F_17 ( 1 , & V_28 -> V_78 ) ;
V_24 -> V_25 -> V_26 ( V_24 , V_3 -> V_27 ) ;
for ( V_29 = 100 ; -- V_29 ; ) {
if ( ! F_3 ( & V_28 -> V_78 ) )
break;
F_25 ( 100 ) ;
} ;
F_26 ( F_1 ( V_3 ) , L_1 , V_32 , V_29 ) ;
if ( ! V_29 ) {
V_55 = - V_79 ;
goto error;
}
return 0 ;
error:
F_35 ( V_4 ) ;
return V_55 ;
}
static T_6 F_55 ( int V_80 , void * V_81 )
{
struct V_2 * V_3 = V_81 ;
struct V_23 * V_24 = V_3 -> V_24 ;
struct V_35 * V_36 ;
V_24 -> V_25 -> V_82 ( V_24 , V_3 -> V_83 ) ;
F_56 (vq, &vdev->vdev.vqs, list)
F_57 ( 0 , V_36 ) ;
return V_84 ;
}
static void F_58 ( struct V_1 * V_85 )
{
}
static int F_59 ( struct V_6 T_1 * V_86 ,
unsigned int V_19 , struct V_23 * V_24 ,
int V_87 )
{
struct V_2 * V_3 ;
int V_88 ;
T_2 type = F_3 ( & V_86 -> type ) ;
V_3 = F_60 ( sizeof( * V_3 ) , V_69 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_24 = V_24 ;
V_3 -> V_3 . V_4 . V_5 = & V_24 -> V_4 ;
V_3 -> V_3 . V_4 . V_89 = F_58 ;
V_3 -> V_3 . V_33 . V_1 = type ;
V_3 -> V_3 . V_49 = & V_90 ;
V_3 -> V_7 = V_86 ;
V_3 -> V_28 = ( void T_1 * ) V_86 + F_8 ( V_86 ) ;
V_3 -> V_87 = V_87 ;
V_3 -> V_3 . V_37 = ( void * ) ( T_3 ) V_87 ;
F_61 ( & V_3 -> V_34 ) ;
V_3 -> V_83 = V_24 -> V_25 -> V_91 ( V_24 ) ;
V_3 -> V_92 = V_24 -> V_25 -> V_93 ( V_24 ,
F_55 , L_7 ,
V_3 , V_3 -> V_83 ) ;
if ( F_53 ( V_3 -> V_92 ) ) {
V_88 = F_54 ( V_3 -> V_92 ) ;
goto V_94;
}
F_17 ( ( T_2 ) V_3 -> V_83 , & V_3 -> V_28 -> V_83 ) ;
V_3 -> V_27 = F_3 ( & V_3 -> V_28 -> V_27 ) ;
V_88 = F_62 ( & V_3 -> V_3 ) ;
if ( V_88 ) {
F_48 ( F_1 ( V_3 ) ,
L_8 ,
V_19 , type ) ;
goto V_95;
}
F_51 ( ( T_3 ) V_3 , & V_3 -> V_28 -> V_3 ) ;
F_26 ( F_1 ( V_3 ) , L_9 ,
V_32 , V_19 , type , V_3 ) ;
return 0 ;
V_95:
V_24 -> V_25 -> V_95 ( V_24 , V_3 -> V_92 , V_3 ) ;
V_94:
V_94 ( V_3 ) ;
return V_88 ;
}
static int F_63 ( struct V_1 * V_4 , void * V_81 )
{
struct V_13 * V_96 = F_64 ( V_4 ) ;
struct V_2 * V_3 = F_10 ( V_96 ) ;
return V_3 -> V_7 == ( void T_1 * ) V_81 ;
}
static void F_65 ( struct V_6 T_1 * V_86 ,
unsigned int V_19 ,
struct V_23 * V_24 )
{
struct V_12 T_1 * V_28
= ( void T_1 * ) V_86 + F_8 ( V_86 ) ;
struct V_2 * V_3 = (struct V_2 * ) F_66 ( & V_28 -> V_3 ) ;
if ( F_3 ( & V_28 -> V_97 ) != V_98 )
return;
F_26 ( & V_24 -> V_4 , L_10 , V_32 , __LINE__ ) ;
F_67 ( & V_3 -> V_3 ) ;
F_17 ( 1 , & V_28 -> V_99 ) ;
}
static int F_68 ( struct V_6 T_1 * V_86 ,
unsigned int V_19 , struct V_23 * V_24 )
{
struct V_12 T_1 * V_28
= ( void T_1 * ) V_86 + F_8 ( V_86 ) ;
struct V_2 * V_3 = (struct V_2 * ) F_66 ( & V_28 -> V_3 ) ;
T_2 V_22 ;
int V_88 = - 1 ;
if ( F_3 ( & V_28 -> V_97 ) == V_100 ) {
F_26 ( & V_24 -> V_4 ,
L_11 ,
V_32 , __LINE__ ,
F_3 ( & V_28 -> V_97 ) , F_3 ( & V_86 -> type ) , V_3 ) ;
V_22 = F_3 ( & V_86 -> V_22 ) ;
F_69 ( & V_3 -> V_34 ) ;
F_70 ( & V_3 -> V_3 ) ;
V_24 -> V_25 -> V_95 ( V_24 , V_3 -> V_92 , V_3 ) ;
F_17 ( - 1 , & V_28 -> V_83 ) ;
if ( V_22 & V_101 )
F_71 ( & V_3 -> V_34 ) ;
V_94 ( V_3 ) ;
F_17 ( 1 , & V_28 -> V_99 ) ;
F_26 ( & V_24 -> V_4 , L_12 ,
V_32 , __LINE__ , F_3 ( & V_28 -> V_99 ) ) ;
F_17 ( - 1 , & V_86 -> type ) ;
V_88 = 0 ;
}
return V_88 ;
}
static void F_72 ( void T_1 * V_102 , struct V_23 * V_24 ,
bool remove , int V_87 )
{
T_7 type ;
unsigned int V_14 ;
struct V_6 T_1 * V_86 ;
struct V_12 T_1 * V_28 ;
struct V_1 * V_4 ;
int V_88 ;
for ( V_14 = sizeof( struct V_103 ) ;
V_14 < V_104 ; V_14 += F_7 ( V_86 ) ) {
V_86 = V_102 + V_14 ;
V_28 = ( void T_1 * ) V_86 + F_8 ( V_86 ) ;
F_73 () ;
type = F_3 ( & V_86 -> type ) ;
if ( type == 0 )
break;
if ( type == - 1 )
continue;
V_4 = F_74 ( & V_24 -> V_4 , ( void V_63 * ) V_86 ,
F_63 ) ;
if ( V_4 ) {
if ( remove )
F_17 ( V_100 ,
& V_28 -> V_97 ) ;
F_75 ( V_4 ) ;
F_65 ( V_86 , V_14 , V_24 ) ;
V_88 = F_68 ( V_86 , V_14 , V_24 ) ;
if ( remove ) {
F_17 ( 0 , & V_28 -> V_97 ) ;
F_17 ( 0 , & V_28 -> V_99 ) ;
}
continue;
}
F_26 ( & V_24 -> V_4 , L_13 ,
V_32 , __LINE__ , V_86 ) ;
if ( ! remove )
F_59 ( V_86 , V_14 , V_24 , V_87 ) ;
}
}
static void F_76 ( struct V_105 * V_106 ,
struct V_23 * V_24 , bool remove )
{
void T_1 * V_102 = V_24 -> V_25 -> V_107 ( V_24 ) ;
if ( ! V_102 )
return;
F_77 ( & V_106 -> V_108 ) ;
F_72 ( V_102 , V_24 , remove , V_24 -> V_87 ) ;
F_78 ( & V_106 -> V_108 ) ;
}
static void F_79 ( struct V_109 * V_110 )
{
struct V_105 * V_106 = F_80 ( V_110 , struct V_105 ,
V_111 ) ;
F_76 ( V_106 , V_106 -> V_24 , ! V_112 ) ;
}
static T_6 F_81 ( int V_80 , void * V_81 )
{
struct V_105 * V_106 = V_81 ;
struct V_103 T_1 * V_113 ;
struct V_23 * V_24 = V_106 -> V_24 ;
V_113 = V_24 -> V_25 -> V_107 ( V_24 ) ;
F_26 ( & V_24 -> V_4 , L_14 ,
V_32 , __LINE__ ) ;
V_24 -> V_25 -> V_82 ( V_24 , F_3 ( & V_113 -> V_114 ) ) ;
F_82 ( & V_106 -> V_111 ) ;
return V_84 ;
}
static int F_83 ( struct V_23 * V_24 )
{
struct V_105 * V_106 ;
int V_115 ;
V_106 = F_60 ( sizeof( * V_106 ) , V_69 ) ;
if ( ! V_106 ) {
V_115 = - V_62 ;
goto exit;
}
F_84 ( & V_24 -> V_4 , V_106 ) ;
V_106 -> V_24 = V_24 ;
F_85 ( & V_106 -> V_108 ) ;
F_86 ( & V_106 -> V_111 , F_79 ) ;
if ( V_24 -> V_87 ) {
V_115 = F_87 ( V_106 ) ;
if ( V_115 < 0 )
goto free;
} else {
struct V_103 T_1 * V_116 ;
F_76 ( V_106 , V_24 , ! V_112 ) ;
V_106 -> V_114 = V_24 -> V_25 -> V_91 ( V_24 ) ;
V_106 -> V_117 = V_24 -> V_25 -> V_93 ( V_24 ,
F_81 ,
L_15 ,
V_106 , V_106 -> V_114 ) ;
if ( F_53 ( V_106 -> V_117 ) ) {
V_115 = F_54 ( V_106 -> V_117 ) ;
goto free;
}
V_116 = V_24 -> V_25 -> V_107 ( V_24 ) ;
F_17 ( V_106 -> V_114 , & V_116 -> V_114 ) ;
}
F_88 ( V_106 ) ;
return 0 ;
free:
V_94 ( V_106 ) ;
exit:
return V_115 ;
}
static void F_89 ( struct V_23 * V_24 )
{
struct V_105 * V_106 = F_90 ( & V_24 -> V_4 ) ;
if ( V_24 -> V_87 ) {
F_91 ( V_106 ) ;
} else {
struct V_103 T_1 * V_116 =
V_24 -> V_25 -> V_107 ( V_24 ) ;
if ( V_116 )
F_17 ( - 1 , & V_116 -> V_114 ) ;
V_24 -> V_25 -> V_95 ( V_24 , V_106 -> V_117 , V_106 ) ;
F_92 ( & V_106 -> V_111 ) ;
F_76 ( V_106 , V_24 , V_112 ) ;
}
F_93 ( V_106 ) ;
V_94 ( V_106 ) ;
}
