static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 . V_5 . V_6 ;
}
static T_1 F_2 ( struct V_7 * V_4 )
{
unsigned int V_8 , V_9 ;
T_2 V_10 = 0 ;
struct V_11 T_3 * V_12 = F_3 ( V_4 ) -> V_12 ;
T_4 T_3 * V_13 = F_4 ( V_12 ) ;
int V_14 = F_5 ( & V_12 -> V_14 ) ;
V_9 = F_6 ( unsigned , V_14 , sizeof( V_10 ) ) * 8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
if ( F_5 ( & V_13 [ V_8 / 8 ] ) & ( F_7 ( V_8 % 8 ) ) )
V_10 |= F_7 ( V_8 ) ;
return V_10 ;
}
static int F_8 ( struct V_7 * V_4 )
{
unsigned int V_8 , V_9 ;
struct V_11 T_3 * V_12 = F_3 ( V_4 ) -> V_12 ;
T_4 V_14 = F_5 ( & V_12 -> V_14 ) ;
T_4 T_3 * V_15 =
F_4 ( V_12 ) + V_14 ;
F_9 ( V_4 ) ;
F_10 ( ( T_2 ) V_4 -> V_10 != V_4 -> V_10 ) ;
F_11 ( V_15 , 0 , V_14 ) ;
V_9 = F_6 ( unsigned , V_14 ,
sizeof( V_4 -> V_10 ) ) * 8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( F_12 ( V_4 , V_8 ) )
F_13 ( F_5 ( & V_15 [ V_8 / 8 ] ) | ( 1 << ( V_8 % 8 ) ) ,
& V_15 [ V_8 / 8 ] ) ;
}
return 0 ;
}
static void F_14 ( struct V_7 * V_4 , unsigned int V_16 ,
void * V_17 , unsigned V_18 )
{
struct V_11 T_3 * V_12 = F_3 ( V_4 ) -> V_12 ;
if ( V_16 + V_18 > F_5 ( & V_12 -> V_19 ) )
return;
F_15 ( V_17 , F_16 ( V_12 ) + V_16 , V_18 ) ;
}
static void F_17 ( struct V_7 * V_4 , unsigned int V_16 ,
const void * V_17 , unsigned V_18 )
{
struct V_11 T_3 * V_12 = F_3 ( V_4 ) -> V_12 ;
if ( V_16 + V_18 > F_5 ( & V_12 -> V_19 ) )
return;
F_18 ( F_16 ( V_12 ) + V_16 , V_17 , V_18 ) ;
}
static T_4 F_19 ( struct V_7 * V_4 )
{
return F_5 ( & F_3 ( V_4 ) -> V_12 -> V_20 ) ;
}
static void F_20 ( struct V_7 * V_4 , T_4 V_20 )
{
struct V_2 * V_3 = F_3 ( V_4 ) ;
if ( ! V_20 )
return;
F_13 ( V_20 , & V_3 -> V_12 -> V_20 ) ;
F_21 ( V_3 -> V_21 , V_3 -> V_22 ) ;
}
static void F_22 ( struct V_7 * V_4 )
{
struct V_2 * V_3 = F_3 ( V_4 ) ;
struct V_23 T_3 * V_24 = V_3 -> V_24 ;
int V_25 ;
F_13 ( 0 , & V_24 -> V_26 ) ;
F_13 ( 1 , & V_24 -> V_27 ) ;
F_21 ( V_3 -> V_21 , V_3 -> V_22 ) ;
for ( V_25 = 100 ; V_25 -- ; ) {
if ( F_5 ( & V_24 -> V_26 ) )
break;
F_23 ( 100 ) ;
} ;
F_24 ( F_1 ( V_3 ) , L_1 , V_28 , V_25 ) ;
F_13 ( 0 , & V_3 -> V_12 -> V_20 ) ;
}
static void F_25 ( struct V_7 * V_4 )
{
struct V_2 * V_3 = F_3 ( V_4 ) ;
F_24 ( F_1 ( V_3 ) , L_2 ,
V_28 , V_4 -> V_29 . V_1 ) ;
F_22 ( V_4 ) ;
F_26 ( & V_3 -> V_30 ) ;
}
static bool F_27 ( struct V_31 * V_32 )
{
struct V_2 * V_3 = V_32 -> V_33 ;
F_21 ( V_3 -> V_21 , V_3 -> V_22 ) ;
return true ;
}
static void F_28 ( struct V_31 * V_32 , int V_34 )
{
struct V_2 * V_3 = F_3 ( V_32 -> V_4 ) ;
struct V_35 * V_36 = (struct V_35 * ) ( V_32 + 1 ) ;
F_29 ( ( unsigned long ) V_36 -> V_37 , F_30 ( V_3 -> V_38 [ V_34 ] ) ) ;
F_31 ( V_32 ) ;
F_32 ( V_3 -> V_21 , V_3 -> V_36 [ V_34 ] ) ;
V_3 -> V_36 [ V_34 ] = NULL ;
}
static void F_33 ( struct V_7 * V_4 )
{
struct V_2 * V_3 = F_3 ( V_4 ) ;
struct V_31 * V_32 , * V_34 ;
int V_39 = 0 ;
F_24 ( F_1 ( V_3 ) , L_3 , V_28 ) ;
F_34 (vq, n, &vdev->vqs, list)
F_28 ( V_32 , V_39 ++ ) ;
}
static struct V_31 * F_35 ( struct V_7 * V_4 ,
unsigned V_40 ,
void (* F_36)( struct V_31 * V_32 ) ,
const char * V_41 )
{
struct V_2 * V_3 = F_3 ( V_4 ) ;
struct V_42 T_3 * V_43 ;
struct V_42 V_44 ;
struct V_31 * V_32 ;
void T_3 * V_45 ;
struct V_46 T_3 * V_47 ;
void * V_37 ;
int V_48 , V_49 , V_50 , V_51 ;
struct V_35 * V_36 ;
T_4 type = F_5 ( & V_3 -> V_12 -> type ) ;
if ( V_40 >= F_5 ( & V_3 -> V_12 -> V_52 ) )
return F_37 ( - V_53 ) ;
if ( ! V_41 )
return F_37 ( - V_53 ) ;
V_43 = F_38 ( V_3 -> V_12 ) + V_40 ;
F_15 ( & V_44 , V_43 , sizeof( V_44 ) ) ;
V_49 = F_39 ( F_40 ( V_44 . V_54 ) , V_55 ) ;
V_48 = F_41 ( V_49 + sizeof( struct V_46 ) ) ;
V_45 = F_42 ( V_3 -> V_21 , F_43 ( V_44 . V_56 ) , V_48 ) ;
if ( ! V_45 )
return F_37 ( - V_57 ) ;
V_3 -> V_36 [ V_40 ] = V_45 ;
F_11 ( V_45 , 0x0 , V_49 ) ;
V_32 = F_44 ( V_40 , F_40 ( V_44 . V_54 ) ,
V_55 , V_4 , false ,
( void V_58 * ) V_45 , F_27 , F_36 ,
V_41 ) ;
if ( ! V_32 ) {
V_50 = - V_57 ;
goto V_59;
}
V_47 = V_45 + V_49 ;
V_51 = F_45 ( & V_47 -> V_51 ) ;
if ( F_46 ( V_51 != V_60 + type + V_40 , L_4 ) ) {
V_50 = - V_61 ;
goto V_59;
}
V_3 -> V_38 [ V_40 ] = F_41 ( sizeof( V_62 ) * 3 +
sizeof( struct V_63 ) *
F_40 ( V_44 . V_54 ) ) ;
V_37 = ( void * ) F_47 ( V_64 | V_65 ,
F_30 ( V_3 -> V_38 [ V_40 ] ) ) ;
if ( ! V_37 ) {
V_50 = - V_57 ;
F_48 ( F_1 ( V_3 ) , L_5 ,
V_28 , __LINE__ , V_50 ) ;
goto V_66;
}
F_49 ( F_50 ( V_37 ) , & V_43 -> V_67 ) ;
V_36 = (struct V_35 * ) ( V_32 + 1 ) ;
V_36 -> V_37 = V_37 ;
V_32 -> V_33 = V_3 ;
return V_32 ;
V_66:
F_31 ( V_32 ) ;
V_59:
F_32 ( V_3 -> V_21 , V_3 -> V_36 [ V_40 ] ) ;
return F_37 ( V_50 ) ;
}
static int F_51 ( struct V_7 * V_4 , unsigned V_68 ,
struct V_31 * V_69 [] ,
T_5 * V_70 [] ,
const char * const V_71 [] )
{
struct V_2 * V_3 = F_3 ( V_4 ) ;
struct V_23 T_3 * V_24 = V_3 -> V_24 ;
int V_8 , V_50 , V_25 ;
if ( V_68 > F_5 ( & V_3 -> V_12 -> V_52 ) )
return - V_53 ;
for ( V_8 = 0 ; V_8 < V_68 ; ++ V_8 ) {
F_24 ( F_1 ( V_3 ) , L_6 ,
V_28 , V_8 , V_71 [ V_8 ] ) ;
V_69 [ V_8 ] = F_35 ( V_4 , V_8 , V_70 [ V_8 ] , V_71 [ V_8 ] ) ;
if ( F_52 ( V_69 [ V_8 ] ) ) {
V_50 = F_53 ( V_69 [ V_8 ] ) ;
goto error;
}
}
F_13 ( 1 , & V_24 -> V_72 ) ;
F_21 ( V_3 -> V_21 , V_3 -> V_22 ) ;
for ( V_25 = 100 ; V_25 -- ; ) {
if ( ! F_5 ( & V_24 -> V_72 ) )
break;
F_23 ( 100 ) ;
} ;
F_24 ( F_1 ( V_3 ) , L_1 , V_28 , V_25 ) ;
if ( ! V_25 ) {
V_50 = - V_73 ;
goto error;
}
return 0 ;
error:
F_33 ( V_4 ) ;
return V_50 ;
}
static T_6
F_54 ( int V_74 , void * V_75 )
{
struct V_2 * V_3 = V_75 ;
struct V_31 * V_32 ;
F_55 ( V_3 -> V_21 ) ;
F_56 (vq, &mvdev->vdev.vqs, list)
F_57 ( 0 , V_32 ) ;
return V_76 ;
}
static void F_58 ( struct V_1 * V_77 )
{
}
static int F_59 ( struct V_11 T_3 * V_78 ,
unsigned int V_16 , struct V_79 * V_80 )
{
struct V_2 * V_3 ;
int V_81 ;
int V_82 ;
T_4 type = F_5 ( & V_78 -> type ) ;
V_3 = F_60 ( sizeof( * V_3 ) , V_64 ) ;
if ( ! V_3 ) {
F_48 ( V_80 -> V_5 , L_7 ,
V_16 , type ) ;
return - V_57 ;
}
V_3 -> V_21 = & V_80 -> V_21 ;
V_3 -> V_4 . V_5 . V_6 = V_80 -> V_5 ;
V_3 -> V_4 . V_5 . V_83 = F_58 ;
V_3 -> V_4 . V_29 . V_1 = type ;
V_3 -> V_4 . V_44 = & V_84 ;
V_3 -> V_12 = V_78 ;
V_3 -> V_24 = ( void T_3 * ) V_78 + F_61 ( V_78 ) ;
F_62 ( & V_3 -> V_30 ) ;
V_82 = F_63 () ;
V_3 -> V_85 = F_64 ( F_54 ,
NULL , L_8 , V_3 , V_82 ) ;
if ( F_52 ( V_3 -> V_85 ) ) {
V_81 = F_53 ( V_3 -> V_85 ) ;
goto V_86;
}
F_13 ( ( T_4 ) V_82 , & V_3 -> V_24 -> V_87 ) ;
V_3 -> V_22 = F_5 ( & V_3 -> V_24 -> V_22 ) ;
V_81 = F_65 ( & V_3 -> V_4 ) ;
if ( V_81 ) {
F_48 ( F_1 ( V_3 ) ,
L_9 ,
V_16 , type ) ;
goto V_88;
}
F_49 ( ( T_1 ) V_3 , & V_3 -> V_24 -> V_4 ) ;
F_24 ( F_1 ( V_3 ) , L_10 ,
V_28 , V_16 , type , V_3 ) ;
return 0 ;
V_88:
F_66 ( V_3 -> V_85 , V_3 ) ;
V_86:
V_86 ( V_3 ) ;
return V_81 ;
}
static int F_67 ( struct V_1 * V_5 , void * V_75 )
{
struct V_7 * V_4 = F_68 ( V_5 ) ;
struct V_2 * V_3 = F_3 ( V_4 ) ;
return V_3 -> V_12 == ( void T_3 * ) V_75 ;
}
static void F_69 ( struct V_11 T_3 * V_78 ,
unsigned int V_16 , struct V_79 * V_80 )
{
struct V_23 T_3 * V_24
= ( void T_3 * ) V_78 + F_61 ( V_78 ) ;
struct V_2 * V_3 = (struct V_2 * ) F_70 ( & V_24 -> V_4 ) ;
if ( F_5 ( & V_24 -> V_89 ) != V_90 )
return;
F_24 ( V_80 -> V_5 , L_11 , V_28 , __LINE__ ) ;
F_71 ( & V_3 -> V_4 ) ;
F_13 ( 1 , & V_24 -> V_91 ) ;
}
static int F_72 ( struct V_11 T_3 * V_78 ,
unsigned int V_16 , struct V_79 * V_80 )
{
struct V_23 T_3 * V_24
= ( void T_3 * ) V_78 + F_61 ( V_78 ) ;
struct V_2 * V_3 = (struct V_2 * ) F_70 ( & V_24 -> V_4 ) ;
T_4 V_20 ;
int V_81 = - 1 ;
if ( F_5 ( & V_24 -> V_89 ) == V_92 ) {
F_24 ( V_80 -> V_5 ,
L_12 ,
V_28 , __LINE__ ,
F_5 ( & V_24 -> V_89 ) , F_5 ( & V_78 -> type ) , V_3 ) ;
V_20 = F_5 ( & V_78 -> V_20 ) ;
F_73 ( & V_3 -> V_30 ) ;
F_74 ( & V_3 -> V_4 ) ;
F_66 ( V_3 -> V_85 , V_3 ) ;
if ( V_20 & V_93 )
F_75 ( & V_3 -> V_30 ) ;
V_86 ( V_3 ) ;
F_13 ( 1 , & V_24 -> V_91 ) ;
F_24 ( V_80 -> V_5 , L_13 ,
V_28 , __LINE__ , F_5 ( & V_24 -> V_91 ) ) ;
V_81 = 0 ;
}
return V_81 ;
}
static void F_76 ( struct V_79 * V_80 , bool remove )
{
T_7 type ;
unsigned int V_8 ;
struct V_11 T_3 * V_78 ;
struct V_23 T_3 * V_24 ;
struct V_1 * V_5 ;
int V_81 ;
for ( V_8 = sizeof( struct V_94 ) ; V_8 < V_95 ;
V_8 += F_77 ( V_78 ) ) {
V_78 = V_80 -> V_96 + V_8 ;
V_24 = ( void T_3 * ) V_78 + F_61 ( V_78 ) ;
F_78 () ;
type = F_5 ( & V_78 -> type ) ;
if ( type == 0 )
break;
if ( type == - 1 )
continue;
V_5 = F_79 ( V_80 -> V_5 , ( void V_58 * ) V_78 ,
F_67 ) ;
if ( V_5 ) {
if ( remove )
F_13 ( V_92 ,
& V_24 -> V_89 ) ;
F_80 ( V_5 ) ;
F_69 ( V_78 , V_8 , V_80 ) ;
V_81 = F_72 ( V_78 , V_8 , V_80 ) ;
if ( ! V_81 && ! remove )
F_13 ( - 1 , & V_78 -> type ) ;
if ( remove ) {
F_13 ( 0 , & V_24 -> V_89 ) ;
F_13 ( 0 , & V_24 -> V_91 ) ;
}
continue;
}
F_24 ( V_80 -> V_5 , L_14 ,
V_28 , __LINE__ , V_78 ) ;
if ( ! remove )
F_59 ( V_78 , V_8 , V_80 ) ;
}
}
static void F_81 ( struct V_97 * V_98 )
{
struct V_79 * V_80 = F_82 ( V_98 ,
struct V_79 , V_99 ) ;
F_76 ( V_80 , ! V_100 ) ;
}
static T_6
F_83 ( int V_74 , void * V_75 )
{
struct V_79 * V_80 = (struct V_79 * ) V_75 ;
F_24 ( V_80 -> V_5 , L_15 ,
V_28 , __LINE__ ) ;
F_55 ( & V_80 -> V_21 ) ;
F_84 ( & V_80 -> V_99 ) ;
return V_76 ;
}
int F_85 ( struct V_79 * V_80 )
{
int V_101 ;
struct V_94 T_3 * V_102 ;
int V_103 ;
F_86 ( & V_80 -> V_99 , F_81 ) ;
F_76 ( V_80 , ! V_100 ) ;
V_103 = F_63 () ;
V_104 = F_64 ( F_83 , NULL ,
L_16 , V_80 ,
V_103 ) ;
if ( F_52 ( V_104 ) ) {
V_101 = F_53 ( V_104 ) ;
goto exit;
}
V_102 = V_80 -> V_96 ;
F_13 ( V_103 , & V_102 -> V_105 ) ;
return 0 ;
exit:
return V_101 ;
}
void F_87 ( struct V_79 * V_80 )
{
struct V_94 T_3 * V_102 = V_80 -> V_96 ;
F_13 ( - 1 , & V_102 -> V_105 ) ;
F_66 ( V_104 , V_80 ) ;
F_88 ( & V_80 -> V_99 ) ;
F_76 ( V_80 , V_100 ) ;
}
