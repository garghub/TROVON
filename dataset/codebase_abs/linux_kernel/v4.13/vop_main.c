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
const char * V_47 , bool V_48 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_23 * V_24 = V_3 -> V_24 ;
struct V_9 T_1 * V_49 ;
struct V_9 V_50 ;
struct V_35 * V_36 ;
void T_1 * V_51 ;
struct V_52 T_1 * V_53 ;
void * V_41 ;
int V_54 , V_55 , V_56 , V_57 ;
struct V_39 * V_40 ;
T_2 type = F_3 ( & V_3 -> V_7 -> type ) ;
if ( V_46 >= F_3 ( & V_3 -> V_7 -> V_8 ) )
return F_39 ( - V_58 ) ;
if ( ! V_47 )
return F_39 ( - V_58 ) ;
V_49 = F_4 ( V_3 -> V_7 ) + V_46 ;
F_19 ( & V_50 , V_49 , sizeof( V_50 ) ) ;
V_55 = F_40 ( F_41 ( V_50 . V_59 ) , V_60 ) ;
V_54 = F_42 ( V_55 + sizeof( struct V_52 ) ) ;
V_51 = V_24 -> V_25 -> V_61 ( V_24 , F_43 ( V_50 . V_62 ) ,
V_54 ) ;
if ( ! V_51 )
return F_39 ( - V_63 ) ;
V_3 -> V_40 [ V_46 ] = V_51 ;
F_15 ( V_51 , 0x0 , V_55 ) ;
V_36 = F_44 (
V_46 ,
F_41 ( V_50 . V_59 ) , V_60 ,
V_4 ,
false ,
V_48 ,
( void V_64 * ) V_51 , F_29 , F_38 , V_47 ) ;
if ( ! V_36 ) {
V_56 = - V_63 ;
goto V_65;
}
V_53 = V_51 + V_55 ;
V_57 = F_45 ( & V_53 -> V_57 ) ;
if ( F_46 ( V_57 != V_66 + type + V_46 , L_4 ) ) {
V_56 = - V_67 ;
goto V_65;
}
V_3 -> V_42 [ V_46 ] = F_42 ( sizeof( V_68 ) * 3 +
sizeof( struct V_69 ) *
F_41 ( V_50 . V_59 ) ) ;
V_41 = ( void * ) F_47 ( V_70 | V_71 ,
F_33 ( V_3 -> V_42 [ V_46 ] ) ) ;
if ( ! V_41 ) {
V_56 = - V_63 ;
F_48 ( F_1 ( V_3 ) , L_5 ,
V_32 , __LINE__ , V_56 ) ;
goto V_72;
}
V_3 -> V_41 [ V_46 ] = F_49 ( & V_24 -> V_4 , V_41 ,
V_3 -> V_42 [ V_46 ] ,
V_43 ) ;
if ( F_50 ( & V_24 -> V_4 , V_3 -> V_41 [ V_46 ] ) ) {
V_56 = - V_63 ;
F_48 ( F_1 ( V_3 ) , L_5 ,
V_32 , __LINE__ , V_56 ) ;
goto V_73;
}
F_51 ( V_3 -> V_41 [ V_46 ] , & V_49 -> V_74 ) ;
V_40 = (struct V_39 * ) ( V_36 + 1 ) ;
V_40 -> V_41 = V_41 ;
V_36 -> V_37 = V_3 ;
return V_36 ;
V_73:
F_32 ( ( unsigned long ) V_41 ,
F_33 ( V_3 -> V_42 [ V_46 ] ) ) ;
V_72:
F_34 ( V_36 ) ;
V_65:
V_24 -> V_25 -> V_44 ( V_24 , V_3 -> V_40 [ V_46 ] ) ;
return F_39 ( V_56 ) ;
}
static int F_52 ( struct V_13 * V_4 , unsigned V_75 ,
struct V_35 * V_76 [] ,
T_5 * V_77 [] ,
const char * const V_78 [] , const bool * V_48 ,
struct V_79 * V_7 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_23 * V_24 = V_3 -> V_24 ;
struct V_12 T_1 * V_28 = V_3 -> V_28 ;
int V_14 , V_56 , V_29 ;
if ( V_75 > F_3 ( & V_3 -> V_7 -> V_8 ) )
return - V_58 ;
for ( V_14 = 0 ; V_14 < V_75 ; ++ V_14 ) {
F_26 ( F_1 ( V_3 ) , L_6 ,
V_32 , V_14 , V_78 [ V_14 ] ) ;
V_76 [ V_14 ] = F_37 ( V_4 , V_14 , V_77 [ V_14 ] , V_78 [ V_14 ] ,
V_48 ? V_48 [ V_14 ] : false ) ;
if ( F_53 ( V_76 [ V_14 ] ) ) {
V_56 = F_54 ( V_76 [ V_14 ] ) ;
goto error;
}
}
F_17 ( 1 , & V_28 -> V_80 ) ;
V_24 -> V_25 -> V_26 ( V_24 , V_3 -> V_27 ) ;
for ( V_29 = 100 ; -- V_29 ; ) {
if ( ! F_3 ( & V_28 -> V_80 ) )
break;
F_25 ( 100 ) ;
} ;
F_26 ( F_1 ( V_3 ) , L_1 , V_32 , V_29 ) ;
if ( ! V_29 ) {
V_56 = - V_81 ;
goto error;
}
return 0 ;
error:
F_35 ( V_4 ) ;
return V_56 ;
}
static T_6 F_55 ( int V_82 , void * V_83 )
{
struct V_2 * V_3 = V_83 ;
struct V_23 * V_24 = V_3 -> V_24 ;
struct V_35 * V_36 ;
V_24 -> V_25 -> V_84 ( V_24 , V_3 -> V_85 ) ;
F_56 (vq, &vdev->vdev.vqs, list)
F_57 ( 0 , V_36 ) ;
return V_86 ;
}
static void F_58 ( struct V_1 * V_87 )
{
}
static int F_59 ( struct V_6 T_1 * V_88 ,
unsigned int V_19 , struct V_23 * V_24 ,
int V_89 )
{
struct V_2 * V_3 ;
int V_90 ;
T_2 type = F_3 ( & V_88 -> type ) ;
V_3 = F_60 ( sizeof( * V_3 ) , V_70 ) ;
if ( ! V_3 )
return - V_63 ;
V_3 -> V_24 = V_24 ;
V_3 -> V_3 . V_4 . V_5 = & V_24 -> V_4 ;
V_3 -> V_3 . V_4 . V_91 = F_58 ;
V_3 -> V_3 . V_33 . V_1 = type ;
V_3 -> V_3 . V_50 = & V_92 ;
V_3 -> V_7 = V_88 ;
V_3 -> V_28 = ( void T_1 * ) V_88 + F_8 ( V_88 ) ;
V_3 -> V_89 = V_89 ;
V_3 -> V_3 . V_37 = ( void * ) ( T_3 ) V_89 ;
F_61 ( & V_3 -> V_34 ) ;
V_3 -> V_85 = V_24 -> V_25 -> V_93 ( V_24 ) ;
V_3 -> V_94 = V_24 -> V_25 -> V_95 ( V_24 ,
F_55 , L_7 ,
V_3 , V_3 -> V_85 ) ;
if ( F_53 ( V_3 -> V_94 ) ) {
V_90 = F_54 ( V_3 -> V_94 ) ;
goto V_96;
}
F_17 ( ( T_2 ) V_3 -> V_85 , & V_3 -> V_28 -> V_85 ) ;
V_3 -> V_27 = F_3 ( & V_3 -> V_28 -> V_27 ) ;
V_90 = F_62 ( & V_3 -> V_3 ) ;
if ( V_90 ) {
F_48 ( F_1 ( V_3 ) ,
L_8 ,
V_19 , type ) ;
goto V_97;
}
F_51 ( ( T_3 ) V_3 , & V_3 -> V_28 -> V_3 ) ;
F_26 ( F_1 ( V_3 ) , L_9 ,
V_32 , V_19 , type , V_3 ) ;
return 0 ;
V_97:
V_24 -> V_25 -> V_97 ( V_24 , V_3 -> V_94 , V_3 ) ;
V_96:
V_96 ( V_3 ) ;
return V_90 ;
}
static int F_63 ( struct V_1 * V_4 , void * V_83 )
{
struct V_13 * V_98 = F_64 ( V_4 ) ;
struct V_2 * V_3 = F_10 ( V_98 ) ;
return V_3 -> V_7 == ( void T_1 * ) V_83 ;
}
static void F_65 ( struct V_6 T_1 * V_88 ,
unsigned int V_19 ,
struct V_23 * V_24 )
{
struct V_12 T_1 * V_28
= ( void T_1 * ) V_88 + F_8 ( V_88 ) ;
struct V_2 * V_3 = (struct V_2 * ) F_66 ( & V_28 -> V_3 ) ;
if ( F_3 ( & V_28 -> V_99 ) != V_100 )
return;
F_26 ( & V_24 -> V_4 , L_10 , V_32 , __LINE__ ) ;
F_67 ( & V_3 -> V_3 ) ;
F_17 ( 1 , & V_28 -> V_101 ) ;
}
static int F_68 ( struct V_6 T_1 * V_88 ,
unsigned int V_19 , struct V_23 * V_24 )
{
struct V_12 T_1 * V_28
= ( void T_1 * ) V_88 + F_8 ( V_88 ) ;
struct V_2 * V_3 = (struct V_2 * ) F_66 ( & V_28 -> V_3 ) ;
T_2 V_22 ;
int V_90 = - 1 ;
if ( F_3 ( & V_28 -> V_99 ) == V_102 ) {
F_26 ( & V_24 -> V_4 ,
L_11 ,
V_32 , __LINE__ ,
F_3 ( & V_28 -> V_99 ) , F_3 ( & V_88 -> type ) , V_3 ) ;
V_22 = F_3 ( & V_88 -> V_22 ) ;
F_69 ( & V_3 -> V_34 ) ;
F_70 ( & V_3 -> V_3 ) ;
V_24 -> V_25 -> V_97 ( V_24 , V_3 -> V_94 , V_3 ) ;
F_17 ( - 1 , & V_28 -> V_85 ) ;
if ( V_22 & V_103 )
F_71 ( & V_3 -> V_34 ) ;
V_96 ( V_3 ) ;
F_17 ( 1 , & V_28 -> V_101 ) ;
F_26 ( & V_24 -> V_4 , L_12 ,
V_32 , __LINE__ , F_3 ( & V_28 -> V_101 ) ) ;
F_17 ( - 1 , & V_88 -> type ) ;
V_90 = 0 ;
}
return V_90 ;
}
static void F_72 ( void T_1 * V_104 , struct V_23 * V_24 ,
bool remove , int V_89 )
{
T_7 type ;
unsigned int V_14 ;
struct V_6 T_1 * V_88 ;
struct V_12 T_1 * V_28 ;
struct V_1 * V_4 ;
int V_90 ;
for ( V_14 = sizeof( struct V_105 ) ;
V_14 < V_106 ; V_14 += F_7 ( V_88 ) ) {
V_88 = V_104 + V_14 ;
V_28 = ( void T_1 * ) V_88 + F_8 ( V_88 ) ;
F_73 () ;
type = F_3 ( & V_88 -> type ) ;
if ( type == 0 )
break;
if ( type == - 1 )
continue;
V_4 = F_74 ( & V_24 -> V_4 , ( void V_64 * ) V_88 ,
F_63 ) ;
if ( V_4 ) {
if ( remove )
F_17 ( V_102 ,
& V_28 -> V_99 ) ;
F_75 ( V_4 ) ;
F_65 ( V_88 , V_14 , V_24 ) ;
V_90 = F_68 ( V_88 , V_14 , V_24 ) ;
if ( remove ) {
F_17 ( 0 , & V_28 -> V_99 ) ;
F_17 ( 0 , & V_28 -> V_101 ) ;
}
continue;
}
F_26 ( & V_24 -> V_4 , L_13 ,
V_32 , __LINE__ , V_88 ) ;
if ( ! remove )
F_59 ( V_88 , V_14 , V_24 , V_89 ) ;
}
}
static void F_76 ( struct V_107 * V_108 ,
struct V_23 * V_24 , bool remove )
{
void T_1 * V_104 = V_24 -> V_25 -> V_109 ( V_24 ) ;
if ( ! V_104 )
return;
F_77 ( & V_108 -> V_110 ) ;
F_72 ( V_104 , V_24 , remove , V_24 -> V_89 ) ;
F_78 ( & V_108 -> V_110 ) ;
}
static void F_79 ( struct V_111 * V_112 )
{
struct V_107 * V_108 = F_80 ( V_112 , struct V_107 ,
V_113 ) ;
F_76 ( V_108 , V_108 -> V_24 , ! V_114 ) ;
}
static T_6 F_81 ( int V_82 , void * V_83 )
{
struct V_107 * V_108 = V_83 ;
struct V_105 T_1 * V_115 ;
struct V_23 * V_24 = V_108 -> V_24 ;
V_115 = V_24 -> V_25 -> V_109 ( V_24 ) ;
F_26 ( & V_24 -> V_4 , L_14 ,
V_32 , __LINE__ ) ;
V_24 -> V_25 -> V_84 ( V_24 , F_3 ( & V_115 -> V_116 ) ) ;
F_82 ( & V_108 -> V_113 ) ;
return V_86 ;
}
static int F_83 ( struct V_23 * V_24 )
{
struct V_107 * V_108 ;
int V_117 ;
V_108 = F_60 ( sizeof( * V_108 ) , V_70 ) ;
if ( ! V_108 ) {
V_117 = - V_63 ;
goto exit;
}
F_84 ( & V_24 -> V_4 , V_108 ) ;
V_108 -> V_24 = V_24 ;
F_85 ( & V_108 -> V_110 ) ;
F_86 ( & V_108 -> V_113 , F_79 ) ;
if ( V_24 -> V_89 ) {
V_117 = F_87 ( V_108 ) ;
if ( V_117 < 0 )
goto free;
} else {
struct V_105 T_1 * V_118 ;
F_76 ( V_108 , V_24 , ! V_114 ) ;
V_108 -> V_116 = V_24 -> V_25 -> V_93 ( V_24 ) ;
V_108 -> V_119 = V_24 -> V_25 -> V_95 ( V_24 ,
F_81 ,
L_15 ,
V_108 , V_108 -> V_116 ) ;
if ( F_53 ( V_108 -> V_119 ) ) {
V_117 = F_54 ( V_108 -> V_119 ) ;
goto free;
}
V_118 = V_24 -> V_25 -> V_109 ( V_24 ) ;
F_17 ( V_108 -> V_116 , & V_118 -> V_116 ) ;
}
F_88 ( V_108 ) ;
return 0 ;
free:
V_96 ( V_108 ) ;
exit:
return V_117 ;
}
static void F_89 ( struct V_23 * V_24 )
{
struct V_107 * V_108 = F_90 ( & V_24 -> V_4 ) ;
if ( V_24 -> V_89 ) {
F_91 ( V_108 ) ;
} else {
struct V_105 T_1 * V_118 =
V_24 -> V_25 -> V_109 ( V_24 ) ;
if ( V_118 )
F_17 ( - 1 , & V_118 -> V_116 ) ;
V_24 -> V_25 -> V_97 ( V_24 , V_108 -> V_119 , V_108 ) ;
F_92 ( & V_108 -> V_113 ) ;
F_76 ( V_108 , V_24 , V_114 ) ;
}
F_93 ( V_108 ) ;
V_96 ( V_108 ) ;
}
