static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
unsigned int V_5 = F_2 () ;
V_5 = F_3 (unsigned int, nr_pcpus, 32UL ) ;
V_4 = F_4 ( V_5 * V_6 ) ;
if ( sizeof( V_7 ) != 0 ) {
#ifdef F_5
if ( V_4 * sizeof( V_7 ) > V_8 )
V_2 -> V_9 = F_6 ( V_4 * sizeof( V_7 ) ) ;
else
#endif
V_2 -> V_9 = F_7 ( V_4 , sizeof( V_7 ) ,
V_10 ) ;
if ( ! V_2 -> V_9 )
return - V_11 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_8 ( & V_2 -> V_9 [ V_3 ] ) ;
}
V_2 -> V_12 = V_4 - 1 ;
return 0 ;
}
static T_1 void F_9 ( void )
{
F_10 ( & V_13 , sizeof( V_13 ) ) ;
}
static inline T_2 F_11 ( struct V_14 V_15 )
{
T_2 * V_16 = ( T_2 * ) V_15 . V_17 ;
return F_12 ( V_16 [ 0 ] , V_16 [ 1 ] , V_13 ) ;
}
static inline V_7 * F_13 ( struct V_1 * V_2 ,
struct V_14 V_15 )
{
return & V_2 -> V_9 [ F_11 ( V_15 ) & V_2 -> V_12 ] ;
}
static inline int F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 , int V_22 )
{
return ( V_19 -> V_23 . V_22 && V_19 -> V_23 . V_22 != V_22 ) ;
}
static inline int F_15 ( struct V_18 * V_19 ,
struct V_24 * V_23 )
{
return ( V_19 -> V_23 . V_22 != V_23 -> V_22 ) ;
}
static int F_16 ( struct V_25 * V_26 ,
const void * V_27 )
{
const struct V_18 * V_19 = V_27 ;
return ( V_19 -> V_23 . V_28 . V_29 . V_30 != * ( V_31 * ) V_26 -> V_32 ) ;
}
static inline int F_17 ( struct V_18 * V_19 )
{
int V_33 = 0 ;
if ( V_19 -> V_23 . V_22 )
V_33 += 1 << 1 ;
return V_33 ;
}
static int F_18 ( struct V_34 * V_35 ,
struct V_24 * V_23 )
{
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
if ( V_35 -> V_36 [ V_37 ] )
V_23 -> V_28 . V_38 . V_30 = ( V_39 V_31 ) F_19 (
V_35 -> V_36 [ V_37 ] ) ;
if ( V_35 -> V_36 [ V_40 ] )
V_23 -> V_28 . V_29 . V_30 = ( V_39 V_31 ) F_19 (
V_35 -> V_36 [ V_40 ] ) ;
if ( V_35 -> V_36 [ V_41 ] )
V_23 -> V_28 . V_42 = F_20 ( V_35 -> V_36 [ V_41 ] ) ;
if ( V_35 -> V_36 [ V_43 ] )
V_23 -> V_22 = F_21 ( V_35 -> V_36 [ V_43 ] ) ;
return 0 ;
}
static inline struct V_18 * F_22 ( struct V_20 * V_21 ,
int V_22 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 ;
V_19 = F_23 ( & V_2 -> V_44 , & V_21 -> V_15 ,
V_45 ) ;
while ( V_19 ) {
if ( ! F_14 ( V_19 , V_21 , V_22 ) )
return V_19 ;
V_19 = F_24 ( V_19 -> V_46 ) ;
}
return NULL ;
}
static inline struct V_18 * F_25 ( struct V_24 * V_23 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 ;
V_19 = F_23 ( & V_2 -> V_44 ,
& V_23 -> V_28 . V_29 ,
V_45 ) ;
while ( V_19 ) {
if ( ! F_15 ( V_19 , V_23 ) )
return V_19 ;
V_19 = F_24 ( V_19 -> V_46 ) ;
}
return NULL ;
}
static inline void F_26 ( struct V_18 * V_19 )
{
F_27 ( V_19 , V_47 ) ;
}
static void F_28 ( void * V_48 , void * V_26 )
{
struct V_18 * V_19 = (struct V_18 * ) V_48 , * V_46 ;
while ( V_19 ) {
V_46 = F_24 ( V_19 -> V_46 ) ;
F_26 ( V_19 ) ;
V_19 = V_46 ;
}
}
static unsigned int
F_29 ( void * V_49 ,
struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
F_30 ( V_51 , false ) ;
return V_54 ;
}
static int F_31 ( struct V_55 * V_55 , struct V_24 * V_23 )
{
struct V_1 * V_2 = F_32 ( V_55 , V_56 ) ;
struct V_18 * V_19 , * V_57 ;
V_7 * V_58 = F_13 ( V_2 , V_23 -> V_28 . V_29 ) ;
int V_59 = 0 , V_60 ;
if ( ! V_2 -> V_61 ) {
V_59 = F_33 ( V_55 , V_62 ,
F_34 ( V_62 ) ) ;
if ( V_59 )
return V_59 ;
V_2 -> V_61 = true ;
}
V_19 = F_35 ( sizeof( * V_19 ) , V_10 ) ;
if ( ! V_19 )
return - V_11 ;
F_36 ( & V_23 -> V_28 ) ;
V_19 -> V_23 = * V_23 ;
V_60 = F_17 ( V_19 ) ;
F_37 ( V_58 ) ;
V_57 = F_23 ( & V_2 -> V_44 ,
& V_23 -> V_28 . V_29 ,
V_45 ) ;
if ( ! V_57 ) {
V_59 = F_38 ( & V_2 -> V_44 ,
& V_19 -> V_63 , V_45 ) ;
} else {
struct V_18 * V_64 = V_57 , * V_65 = NULL ;
do {
if ( ! F_15 ( V_64 , V_23 ) ) {
V_59 = - V_66 ;
goto V_67;
}
if ( V_60 > F_17 ( V_64 ) )
break;
V_65 = V_64 ;
V_64 = F_39 ( V_64 -> V_46 ,
F_40 ( V_58 ) ) ;
} while ( V_64 );
if ( V_65 ) {
F_41 ( V_19 -> V_46 , V_64 ) ;
F_42 ( V_65 -> V_46 , V_19 ) ;
} else {
F_41 ( V_19 -> V_46 , V_57 ) ;
V_59 = F_43 ( & V_2 -> V_44 ,
& V_57 -> V_63 ,
& V_19 -> V_63 , V_45 ) ;
if ( V_59 )
goto V_67;
}
}
V_67:
F_44 ( V_58 ) ;
if ( V_59 )
F_45 ( V_19 ) ;
return V_59 ;
}
static int F_46 ( struct V_55 * V_55 , struct V_24 * V_23 )
{
struct V_1 * V_2 = F_32 ( V_55 , V_56 ) ;
struct V_18 * V_19 , * V_57 , * V_65 ;
V_7 * V_58 = F_13 ( V_2 , V_23 -> V_28 . V_29 ) ;
int V_59 = - V_68 ;
F_37 ( V_58 ) ;
V_57 = F_23 ( & V_2 -> V_44 ,
& V_23 -> V_28 . V_29 , V_45 ) ;
V_19 = V_57 ;
V_65 = NULL ;
while ( V_19 ) {
if ( F_15 ( V_19 , V_23 ) ) {
V_65 = V_19 ;
V_19 = F_39 ( V_19 -> V_46 ,
F_40 ( V_58 ) ) ;
continue;
}
V_59 = 0 ;
if ( V_65 ) {
F_42 ( V_65 -> V_46 , V_19 -> V_46 ) ;
} else {
V_57 = F_39 ( V_19 -> V_46 ,
F_40 ( V_58 ) ) ;
if ( V_57 ) {
V_59 = F_43 (
& V_2 -> V_44 , & V_19 -> V_63 ,
& V_57 -> V_63 , V_45 ) ;
if ( V_59 )
goto V_67;
} else {
V_59 = F_47 ( & V_2 -> V_44 ,
& V_19 -> V_63 ,
V_45 ) ;
}
}
F_26 ( V_19 ) ;
break;
}
V_67:
F_44 ( V_58 ) ;
return V_59 ;
}
static int F_48 ( struct V_50 * V_51 , struct V_34 * V_35 )
{
struct V_55 * V_55 = F_49 ( V_35 ) ;
struct V_24 V_69 ;
int V_59 ;
V_59 = F_18 ( V_35 , & V_69 ) ;
if ( V_59 )
return V_59 ;
return F_31 ( V_55 , & V_69 ) ;
}
static int F_50 ( struct V_50 * V_51 , struct V_34 * V_35 )
{
struct V_55 * V_55 = F_49 ( V_35 ) ;
struct V_24 V_23 ;
int V_59 ;
V_59 = F_18 ( V_35 , & V_23 ) ;
if ( V_59 )
return V_59 ;
F_46 ( V_55 , & V_23 ) ;
return 0 ;
}
static int F_51 ( struct V_18 * V_19 , struct V_50 * V_70 )
{
if ( F_52 ( V_70 , V_37 ,
( V_39 V_71 ) V_19 -> V_23 . V_28 . V_38 . V_30 ,
V_72 ) ||
F_52 ( V_70 , V_40 ,
( V_39 V_71 ) V_19 -> V_23 . V_28 . V_29 . V_30 ,
V_72 ) ||
F_53 ( V_70 , V_43 , V_19 -> V_23 . V_22 ) ||
F_54 ( V_70 , V_41 , V_19 -> V_23 . V_28 . V_42 ) )
return - 1 ;
return 0 ;
}
static int F_55 ( struct V_18 * V_19 ,
T_2 V_73 , T_2 V_74 , T_2 V_75 ,
struct V_50 * V_51 , T_3 V_76 )
{
void * V_77 ;
V_77 = F_56 ( V_51 , V_73 , V_74 , & V_78 , V_75 , V_76 ) ;
if ( ! V_77 )
return - V_11 ;
if ( F_51 ( V_19 , V_51 ) < 0 )
goto V_79;
F_57 ( V_51 , V_77 ) ;
return 0 ;
V_79:
F_58 ( V_51 , V_77 ) ;
return - V_80 ;
}
static int F_59 ( struct V_50 * V_51 , struct V_34 * V_35 )
{
struct V_55 * V_55 = F_49 ( V_35 ) ;
struct V_1 * V_2 = F_32 ( V_55 , V_56 ) ;
struct V_50 * V_70 ;
struct V_24 V_23 ;
struct V_18 * V_19 ;
int V_81 ;
V_81 = F_18 ( V_35 , & V_23 ) ;
if ( V_81 )
return V_81 ;
V_70 = F_60 ( V_82 , V_10 ) ;
if ( ! V_70 )
return - V_11 ;
F_61 () ;
V_19 = F_25 ( & V_23 , V_2 ) ;
if ( V_19 ) {
V_81 = F_55 ( V_19 ,
V_35 -> V_83 ,
V_35 -> V_84 , 0 , V_70 ,
V_35 -> V_85 -> V_76 ) ;
}
F_62 () ;
if ( V_81 < 0 )
goto V_86;
return F_63 ( V_70 , V_35 ) ;
V_86:
F_64 ( V_70 ) ;
return V_81 ;
}
static int F_65 ( struct V_87 * V_88 )
{
struct V_55 * V_55 = F_66 ( V_88 -> V_51 -> V_89 ) ;
struct V_1 * V_2 = F_32 ( V_55 , V_56 ) ;
struct V_90 * V_91 = (struct V_90 * ) V_88 -> args [ 0 ] ;
if ( ! V_91 ) {
V_91 = F_67 ( sizeof( * V_91 ) , V_10 ) ;
if ( ! V_91 )
return - V_11 ;
V_88 -> args [ 0 ] = ( long ) V_91 ;
}
return F_68 ( & V_2 -> V_44 , & V_91 -> V_92 ,
V_10 ) ;
}
static int F_69 ( struct V_87 * V_88 )
{
struct V_90 * V_91 = (struct V_90 * ) V_88 -> args [ 0 ] ;
F_70 ( & V_91 -> V_92 ) ;
F_45 ( V_91 ) ;
return 0 ;
}
static int F_71 ( struct V_50 * V_51 , struct V_87 * V_88 )
{
struct V_90 * V_91 = (struct V_90 * ) V_88 -> args [ 0 ] ;
struct V_93 * V_92 = & V_91 -> V_92 ;
struct V_18 * V_19 ;
int V_81 ;
V_81 = F_72 ( V_92 ) ;
if ( V_81 && V_81 != - V_94 )
goto V_95;
for (; ; ) {
V_19 = F_73 ( V_92 ) ;
if ( F_74 ( V_19 ) ) {
if ( F_75 ( V_19 ) == - V_94 )
continue;
V_81 = F_75 ( V_19 ) ;
goto V_95;
} else if ( ! V_19 ) {
break;
}
while ( V_19 ) {
V_81 = F_55 ( V_19 , F_76 ( V_88 -> V_51 ) . V_73 ,
V_88 -> V_96 -> V_97 , V_98 ,
V_51 , V_99 ) ;
if ( V_81 )
goto V_95;
V_19 = F_24 ( V_19 -> V_46 ) ;
}
}
V_81 = V_51 -> V_100 ;
V_95:
F_77 ( V_92 ) ;
return V_81 ;
}
static T_4 int F_78 ( struct V_55 * V_55 )
{
int V_59 ;
struct V_1 * V_2 = F_32 ( V_55 , V_56 ) ;
V_59 = F_1 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_79 ( & V_2 -> V_44 , & V_45 ) ;
return 0 ;
}
static T_5 void F_80 ( struct V_55 * V_55 )
{
struct V_1 * V_2 = F_32 ( V_55 , V_56 ) ;
F_81 ( & V_2 -> V_44 , F_28 , NULL ) ;
F_82 ( V_2 -> V_9 ) ;
if ( V_2 -> V_61 )
F_83 ( V_55 , V_62 ,
F_34 ( V_62 ) ) ;
}
static int F_30 ( struct V_50 * V_51 , bool V_101 )
{
struct V_18 * V_19 ;
struct V_102 * V_103 = F_84 ( V_51 ) ;
struct V_55 * V_55 = F_85 ( V_51 -> V_104 ) ;
struct V_1 * V_2 = F_32 ( V_55 , V_56 ) ;
struct V_20 * V_21 = F_86 ( & V_103 -> V_105 ) ;
if ( ! F_87 ( V_21 ) ) {
return 0 ;
}
F_61 () ;
V_19 = F_22 ( V_21 , V_51 -> V_104 -> V_22 , V_2 ) ;
if ( V_19 )
F_88 ( V_51 , & V_19 -> V_23 . V_28 , V_101 ) ;
F_62 () ;
return 0 ;
}
int T_6 F_89 ( void )
{
int V_81 ;
V_81 = F_90 ( & V_106 ) ;
if ( V_81 )
goto exit;
V_81 = F_91 ( & V_78 ) ;
if ( V_81 < 0 )
goto V_107;
return 0 ;
V_107:
F_92 ( & V_106 ) ;
exit:
return V_81 ;
}
void F_93 ( void )
{
F_94 ( & V_78 ) ;
F_92 ( & V_106 ) ;
}
