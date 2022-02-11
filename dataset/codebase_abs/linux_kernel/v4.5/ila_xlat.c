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
static inline T_2 F_11 ( T_3 V_14 )
{
T_2 * V_15 = ( T_2 * ) & V_14 ;
return F_12 ( V_15 [ 0 ] , V_15 [ 1 ] , V_13 ) ;
}
static inline V_7 * F_13 ( struct V_1 * V_2 , T_3 V_14 )
{
return & V_2 -> V_9 [ F_11 ( V_14 ) & V_2 -> V_12 ] ;
}
static inline int F_14 ( struct V_16 * V_17 , T_3 V_18 ,
int V_19 , unsigned int V_20 )
{
return ( V_17 -> V_21 . V_22 . V_23 && V_17 -> V_21 . V_22 . V_23 != V_18 ) ||
( V_17 -> V_21 . V_19 && V_17 -> V_21 . V_19 != V_19 ) ||
! ( V_17 -> V_21 . V_20 & V_20 ) ;
}
static inline int F_15 ( struct V_16 * V_17 , struct V_24 * V_21 )
{
return ( V_17 -> V_21 . V_22 . V_23 != V_21 -> V_22 . V_23 ) ||
( V_17 -> V_21 . V_19 != V_21 -> V_19 ) ||
( V_17 -> V_21 . V_20 != V_21 -> V_20 ) ;
}
static int F_16 ( struct V_25 * V_26 ,
const void * V_27 )
{
const struct V_16 * V_17 = V_27 ;
return ( V_17 -> V_21 . V_14 != * ( T_3 * ) V_26 -> V_28 ) ;
}
static inline int F_17 ( struct V_16 * V_17 )
{
int V_29 = 0 ;
if ( V_17 -> V_21 . V_22 . V_23 )
V_29 += 1 << 0 ;
if ( V_17 -> V_21 . V_19 )
V_29 += 1 << 1 ;
return V_29 ;
}
static int F_18 ( struct V_30 * V_31 ,
struct V_24 * V_21 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
if ( V_31 -> V_32 [ V_33 ] )
V_21 -> V_14 = ( V_34 T_3 ) F_19 (
V_31 -> V_32 [ V_33 ] ) ;
if ( V_31 -> V_32 [ V_35 ] )
V_21 -> V_22 . V_36 = ( V_34 T_3 ) F_19 (
V_31 -> V_32 [ V_35 ] ) ;
if ( V_31 -> V_32 [ V_37 ] )
V_21 -> V_22 . V_23 = ( V_34 T_3 ) F_19 (
V_31 -> V_32 [ V_37 ] ) ;
if ( V_31 -> V_32 [ V_38 ] )
V_21 -> V_19 = F_20 ( V_31 -> V_32 [ V_38 ] ) ;
if ( V_31 -> V_32 [ V_39 ] )
V_21 -> V_20 = F_21 ( V_31 -> V_32 [ V_39 ] ) ;
return 0 ;
}
static inline struct V_16 * F_22 ( T_3 V_40 , T_3 V_18 ,
int V_19 ,
unsigned int V_20 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_23 ( & V_2 -> V_41 , & V_40 , V_42 ) ;
while ( V_17 ) {
if ( ! F_14 ( V_17 , V_18 , V_19 , V_20 ) )
return V_17 ;
V_17 = F_24 ( V_17 -> V_43 ) ;
}
return NULL ;
}
static inline struct V_16 * F_25 ( struct V_24 * V_21 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_23 ( & V_2 -> V_41 , & V_21 -> V_14 ,
V_42 ) ;
while ( V_17 ) {
if ( ! F_15 ( V_17 , V_21 ) )
return V_17 ;
V_17 = F_24 ( V_17 -> V_43 ) ;
}
return NULL ;
}
static inline void F_26 ( struct V_16 * V_17 )
{
F_27 ( V_17 , V_44 ) ;
}
static void F_28 ( void * V_45 , void * V_26 )
{
struct V_16 * V_17 = (struct V_16 * ) V_45 , * V_43 ;
while ( V_17 ) {
V_43 = F_24 ( V_17 -> V_43 ) ;
F_26 ( V_17 ) ;
V_17 = V_43 ;
}
}
static unsigned int
F_29 ( void * V_46 ,
struct V_47 * V_48 ,
const struct V_49 * V_50 )
{
F_30 ( V_48 , V_51 ) ;
return V_52 ;
}
static int F_31 ( struct V_53 * V_53 , struct V_24 * V_21 )
{
struct V_1 * V_2 = F_32 ( V_53 , V_54 ) ;
struct V_16 * V_17 , * V_55 ;
V_7 * V_56 = F_13 ( V_2 , V_21 -> V_14 ) ;
int V_57 = 0 , V_58 ;
if ( ! V_2 -> V_59 ) {
V_57 = F_33 ( V_53 , V_60 ,
F_34 ( V_60 ) ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_59 = true ;
}
V_17 = F_35 ( sizeof( * V_17 ) , V_10 ) ;
if ( ! V_17 )
return - V_11 ;
V_17 -> V_21 = * V_21 ;
if ( V_21 -> V_22 . V_23 ) {
V_17 -> V_21 . V_22 . V_61 = F_36 (
( V_62 * ) & V_21 -> V_22 . V_23 ,
( V_62 * ) & V_21 -> V_22 . V_36 ) ;
}
V_58 = F_17 ( V_17 ) ;
F_37 ( V_56 ) ;
V_55 = F_23 ( & V_2 -> V_41 , & V_21 -> V_14 ,
V_42 ) ;
if ( ! V_55 ) {
V_57 = F_38 ( & V_2 -> V_41 ,
& V_17 -> V_63 , V_42 ) ;
} else {
struct V_16 * V_64 = V_55 , * V_65 = NULL ;
do {
if ( ! F_15 ( V_64 , V_21 ) ) {
V_57 = - V_66 ;
goto V_67;
}
if ( V_58 > F_17 ( V_64 ) )
break;
V_65 = V_64 ;
V_64 = F_39 ( V_64 -> V_43 ,
F_40 ( V_56 ) ) ;
} while ( V_64 );
if ( V_65 ) {
F_41 ( V_17 -> V_43 , V_64 ) ;
F_42 ( V_65 -> V_43 , V_17 ) ;
} else {
F_41 ( V_17 -> V_43 , V_55 ) ;
V_57 = F_43 ( & V_2 -> V_41 ,
& V_55 -> V_63 ,
& V_17 -> V_63 , V_42 ) ;
if ( V_57 )
goto V_67;
}
}
V_67:
F_44 ( V_56 ) ;
if ( V_57 )
F_45 ( V_17 ) ;
return V_57 ;
}
static int F_46 ( struct V_53 * V_53 , struct V_24 * V_21 )
{
struct V_1 * V_2 = F_32 ( V_53 , V_54 ) ;
struct V_16 * V_17 , * V_55 , * V_65 ;
V_7 * V_56 = F_13 ( V_2 , V_21 -> V_14 ) ;
int V_57 = - V_68 ;
F_37 ( V_56 ) ;
V_55 = F_23 ( & V_2 -> V_41 ,
& V_21 -> V_14 , V_42 ) ;
V_17 = V_55 ;
V_65 = NULL ;
while ( V_17 ) {
if ( F_15 ( V_17 , V_21 ) ) {
V_65 = V_17 ;
V_17 = F_39 ( V_17 -> V_43 ,
F_40 ( V_56 ) ) ;
continue;
}
V_57 = 0 ;
if ( V_65 ) {
F_42 ( V_65 -> V_43 , V_17 -> V_43 ) ;
} else {
V_55 = F_39 ( V_17 -> V_43 ,
F_40 ( V_56 ) ) ;
if ( V_55 ) {
V_57 = F_43 (
& V_2 -> V_41 , & V_17 -> V_63 ,
& V_55 -> V_63 , V_42 ) ;
if ( V_57 )
goto V_67;
} else {
V_57 = F_47 ( & V_2 -> V_41 ,
& V_17 -> V_63 ,
V_42 ) ;
}
}
F_26 ( V_17 ) ;
break;
}
V_67:
F_44 ( V_56 ) ;
return V_57 ;
}
static int F_48 ( struct V_47 * V_48 , struct V_30 * V_31 )
{
struct V_53 * V_53 = F_49 ( V_31 ) ;
struct V_24 V_21 ;
int V_57 ;
V_57 = F_18 ( V_31 , & V_21 ) ;
if ( V_57 )
return V_57 ;
return F_31 ( V_53 , & V_21 ) ;
}
static int F_50 ( struct V_47 * V_48 , struct V_30 * V_31 )
{
struct V_53 * V_53 = F_49 ( V_31 ) ;
struct V_24 V_21 ;
int V_57 ;
V_57 = F_18 ( V_31 , & V_21 ) ;
if ( V_57 )
return V_57 ;
F_46 ( V_53 , & V_21 ) ;
return 0 ;
}
static int F_51 ( struct V_16 * V_17 , struct V_47 * V_69 )
{
if ( F_52 ( V_69 , V_33 ,
( V_34 V_70 ) V_17 -> V_21 . V_14 ) ||
F_52 ( V_69 , V_35 ,
( V_34 V_70 ) V_17 -> V_21 . V_22 . V_36 ) ||
F_52 ( V_69 , V_37 ,
( V_34 V_70 ) V_17 -> V_21 . V_22 . V_23 ) ||
F_53 ( V_69 , V_38 , V_17 -> V_21 . V_19 ) ||
F_54 ( V_69 , V_39 , V_17 -> V_21 . V_20 ) )
return - 1 ;
return 0 ;
}
static int F_55 ( struct V_16 * V_17 ,
T_2 V_71 , T_2 V_72 , T_2 V_73 ,
struct V_47 * V_48 , T_4 V_74 )
{
void * V_75 ;
V_75 = F_56 ( V_48 , V_71 , V_72 , & V_76 , V_73 , V_74 ) ;
if ( ! V_75 )
return - V_11 ;
if ( F_51 ( V_17 , V_48 ) < 0 )
goto V_77;
F_57 ( V_48 , V_75 ) ;
return 0 ;
V_77:
F_58 ( V_48 , V_75 ) ;
return - V_78 ;
}
static int F_59 ( struct V_47 * V_48 , struct V_30 * V_31 )
{
struct V_53 * V_53 = F_49 ( V_31 ) ;
struct V_1 * V_2 = F_32 ( V_53 , V_54 ) ;
struct V_47 * V_69 ;
struct V_24 V_21 ;
struct V_16 * V_17 ;
int V_79 ;
V_79 = F_18 ( V_31 , & V_21 ) ;
if ( V_79 )
return V_79 ;
V_69 = F_60 ( V_80 , V_10 ) ;
if ( ! V_69 )
return - V_11 ;
F_61 () ;
V_17 = F_25 ( & V_21 , V_2 ) ;
if ( V_17 ) {
V_79 = F_55 ( V_17 ,
V_31 -> V_81 ,
V_31 -> V_82 , 0 , V_69 ,
V_31 -> V_83 -> V_74 ) ;
}
F_62 () ;
if ( V_79 < 0 )
goto V_84;
return F_63 ( V_69 , V_31 ) ;
V_84:
F_64 ( V_69 ) ;
return V_79 ;
}
static int F_65 ( struct V_85 * V_86 )
{
struct V_53 * V_53 = F_66 ( V_86 -> V_48 -> V_87 ) ;
struct V_1 * V_2 = F_32 ( V_53 , V_54 ) ;
struct V_88 * V_89 = (struct V_88 * ) V_86 -> args ;
return F_67 ( & V_2 -> V_41 , & V_89 -> V_90 ) ;
}
static int F_68 ( struct V_85 * V_86 )
{
struct V_88 * V_89 = (struct V_88 * ) V_86 -> args ;
F_69 ( & V_89 -> V_90 ) ;
return 0 ;
}
static int F_70 ( struct V_47 * V_48 , struct V_85 * V_86 )
{
struct V_88 * V_89 = (struct V_88 * ) V_86 -> args ;
struct V_91 * V_90 = & V_89 -> V_90 ;
struct V_16 * V_17 ;
int V_79 ;
V_79 = F_71 ( V_90 ) ;
if ( V_79 && V_79 != - V_92 )
goto V_93;
for (; ; ) {
V_17 = F_72 ( V_90 ) ;
if ( F_73 ( V_17 ) ) {
if ( F_74 ( V_17 ) == - V_92 )
continue;
V_79 = F_74 ( V_17 ) ;
goto V_93;
} else if ( ! V_17 ) {
break;
}
while ( V_17 ) {
V_79 = F_55 ( V_17 , F_75 ( V_86 -> V_48 ) . V_71 ,
V_86 -> V_94 -> V_95 , V_96 ,
V_48 , V_97 ) ;
if ( V_79 )
goto V_93;
V_17 = F_24 ( V_17 -> V_43 ) ;
}
}
V_79 = V_48 -> V_98 ;
V_93:
F_76 ( V_90 ) ;
return V_79 ;
}
static T_5 int F_77 ( struct V_53 * V_53 )
{
int V_57 ;
struct V_1 * V_2 = F_32 ( V_53 , V_54 ) ;
V_57 = F_1 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_78 ( & V_2 -> V_41 , & V_42 ) ;
return 0 ;
}
static T_6 void F_79 ( struct V_53 * V_53 )
{
struct V_1 * V_2 = F_32 ( V_53 , V_54 ) ;
F_80 ( & V_2 -> V_41 , F_28 , NULL ) ;
F_81 ( V_2 -> V_9 ) ;
if ( V_2 -> V_59 )
F_82 ( V_53 , V_60 ,
F_34 ( V_60 ) ) ;
}
static int F_30 ( struct V_47 * V_48 , int V_20 )
{
struct V_16 * V_17 ;
struct V_99 * V_100 = F_83 ( V_48 ) ;
struct V_53 * V_53 = F_84 ( V_48 -> V_101 ) ;
struct V_1 * V_2 = F_32 ( V_53 , V_54 ) ;
T_3 V_14 , V_23 ;
T_7 V_102 ;
V_14 = * ( T_3 * ) & V_100 -> V_103 . V_104 . V_105 [ 8 ] ;
V_23 = * ( T_3 * ) & V_100 -> V_103 . V_104 . V_105 [ 0 ] ;
V_102 = sizeof( struct V_99 ) ;
F_61 () ;
V_17 = F_22 ( V_14 , V_23 ,
V_48 -> V_101 -> V_19 , V_20 , V_2 ) ;
if ( V_17 )
F_85 ( V_48 , & V_17 -> V_21 . V_22 ) ;
F_62 () ;
return 0 ;
}
int F_86 ( struct V_47 * V_48 )
{
return F_30 ( V_48 , V_51 ) ;
}
int F_87 ( struct V_47 * V_48 )
{
return F_30 ( V_48 , V_106 ) ;
}
int F_88 ( void )
{
int V_79 ;
V_79 = F_89 ( & V_107 ) ;
if ( V_79 )
goto exit;
V_79 = F_90 ( & V_76 ,
V_108 ) ;
if ( V_79 < 0 )
goto V_109;
return 0 ;
V_109:
F_91 ( & V_107 ) ;
exit:
return V_79 ;
}
void F_92 ( void )
{
F_93 ( & V_76 ) ;
F_91 ( & V_107 ) ;
}
