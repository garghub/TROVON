static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
unsigned int V_5 = F_2 () ;
V_5 = F_3 (unsigned int, nr_pcpus, 32UL ) ;
V_4 = F_4 ( V_5 * V_6 ) ;
if ( sizeof( V_7 ) != 0 ) {
V_2 -> V_8 = F_5 ( V_4 * sizeof( V_7 ) , V_9 ) ;
if ( ! V_2 -> V_8 )
return - V_10 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_6 ( & V_2 -> V_8 [ V_3 ] ) ;
}
V_2 -> V_11 = V_4 - 1 ;
return 0 ;
}
static T_1 void F_7 ( void )
{
F_8 ( & V_12 , sizeof( V_12 ) ) ;
}
static inline T_2 F_9 ( struct V_13 V_14 )
{
T_2 * V_15 = ( T_2 * ) V_14 . V_16 ;
F_7 () ;
return F_10 ( V_15 [ 0 ] , V_15 [ 1 ] , V_12 ) ;
}
static inline V_7 * F_11 ( struct V_1 * V_2 ,
struct V_13 V_14 )
{
return & V_2 -> V_8 [ F_9 ( V_14 ) & V_2 -> V_11 ] ;
}
static inline int F_12 ( struct V_17 * V_18 ,
struct V_19 * V_20 , int V_21 )
{
return ( V_18 -> V_22 . V_21 && V_18 -> V_22 . V_21 != V_21 ) ;
}
static inline int F_13 ( struct V_17 * V_18 ,
struct V_23 * V_22 )
{
return ( V_18 -> V_22 . V_21 != V_22 -> V_21 ) ;
}
static int F_14 ( struct V_24 * V_25 ,
const void * V_26 )
{
const struct V_17 * V_18 = V_26 ;
return ( V_18 -> V_22 . V_27 . V_28 . V_29 != * ( V_30 * ) V_25 -> V_31 ) ;
}
static inline int F_15 ( struct V_17 * V_18 )
{
int V_32 = 0 ;
if ( V_18 -> V_22 . V_21 )
V_32 += 1 << 1 ;
return V_32 ;
}
static int F_16 ( struct V_33 * V_34 ,
struct V_23 * V_22 )
{
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
if ( V_34 -> V_35 [ V_36 ] )
V_22 -> V_27 . V_37 . V_29 = ( V_38 V_30 ) F_17 (
V_34 -> V_35 [ V_36 ] ) ;
if ( V_34 -> V_35 [ V_39 ] )
V_22 -> V_27 . V_28 . V_29 = ( V_38 V_30 ) F_17 (
V_34 -> V_35 [ V_39 ] ) ;
if ( V_34 -> V_35 [ V_40 ] )
V_22 -> V_27 . V_41 = F_18 ( V_34 -> V_35 [ V_40 ] ) ;
if ( V_34 -> V_35 [ V_42 ] )
V_22 -> V_21 = F_19 ( V_34 -> V_35 [ V_42 ] ) ;
return 0 ;
}
static inline struct V_17 * F_20 ( struct V_19 * V_20 ,
int V_21 ,
struct V_1 * V_2 )
{
struct V_17 * V_18 ;
V_18 = F_21 ( & V_2 -> V_43 , & V_20 -> V_14 ,
V_44 ) ;
while ( V_18 ) {
if ( ! F_12 ( V_18 , V_20 , V_21 ) )
return V_18 ;
V_18 = F_22 ( V_18 -> V_45 ) ;
}
return NULL ;
}
static inline struct V_17 * F_23 ( struct V_23 * V_22 ,
struct V_1 * V_2 )
{
struct V_17 * V_18 ;
V_18 = F_21 ( & V_2 -> V_43 ,
& V_22 -> V_27 . V_28 ,
V_44 ) ;
while ( V_18 ) {
if ( ! F_13 ( V_18 , V_22 ) )
return V_18 ;
V_18 = F_22 ( V_18 -> V_45 ) ;
}
return NULL ;
}
static inline void F_24 ( struct V_17 * V_18 )
{
F_25 ( V_18 , V_46 ) ;
}
static void F_26 ( void * V_47 , void * V_25 )
{
struct V_17 * V_18 = (struct V_17 * ) V_47 , * V_45 ;
while ( V_18 ) {
V_45 = F_22 ( V_18 -> V_45 ) ;
F_24 ( V_18 ) ;
V_18 = V_45 ;
}
}
static unsigned int
F_27 ( void * V_48 ,
struct V_49 * V_50 ,
const struct V_51 * V_52 )
{
F_28 ( V_50 , false ) ;
return V_53 ;
}
static int F_29 ( struct V_54 * V_54 , struct V_23 * V_22 )
{
struct V_1 * V_2 = F_30 ( V_54 , V_55 ) ;
struct V_17 * V_18 , * V_56 ;
V_7 * V_57 = F_11 ( V_2 , V_22 -> V_27 . V_28 ) ;
int V_58 = 0 , V_59 ;
if ( ! V_2 -> V_60 ) {
V_58 = F_31 ( V_54 , V_61 ,
F_32 ( V_61 ) ) ;
if ( V_58 )
return V_58 ;
V_2 -> V_60 = true ;
}
V_18 = F_33 ( sizeof( * V_18 ) , V_9 ) ;
if ( ! V_18 )
return - V_10 ;
F_34 ( & V_22 -> V_27 ) ;
V_18 -> V_22 = * V_22 ;
V_59 = F_15 ( V_18 ) ;
F_35 ( V_57 ) ;
V_56 = F_21 ( & V_2 -> V_43 ,
& V_22 -> V_27 . V_28 ,
V_44 ) ;
if ( ! V_56 ) {
V_58 = F_36 ( & V_2 -> V_43 ,
& V_18 -> V_62 , V_44 ) ;
} else {
struct V_17 * V_63 = V_56 , * V_64 = NULL ;
do {
if ( ! F_13 ( V_63 , V_22 ) ) {
V_58 = - V_65 ;
goto V_66;
}
if ( V_59 > F_15 ( V_63 ) )
break;
V_64 = V_63 ;
V_63 = F_37 ( V_63 -> V_45 ,
F_38 ( V_57 ) ) ;
} while ( V_63 );
if ( V_64 ) {
F_39 ( V_18 -> V_45 , V_63 ) ;
F_40 ( V_64 -> V_45 , V_18 ) ;
} else {
F_39 ( V_18 -> V_45 , V_56 ) ;
V_58 = F_41 ( & V_2 -> V_43 ,
& V_56 -> V_62 ,
& V_18 -> V_62 , V_44 ) ;
if ( V_58 )
goto V_66;
}
}
V_66:
F_42 ( V_57 ) ;
if ( V_58 )
F_43 ( V_18 ) ;
return V_58 ;
}
static int F_44 ( struct V_54 * V_54 , struct V_23 * V_22 )
{
struct V_1 * V_2 = F_30 ( V_54 , V_55 ) ;
struct V_17 * V_18 , * V_56 , * V_64 ;
V_7 * V_57 = F_11 ( V_2 , V_22 -> V_27 . V_28 ) ;
int V_58 = - V_67 ;
F_35 ( V_57 ) ;
V_56 = F_21 ( & V_2 -> V_43 ,
& V_22 -> V_27 . V_28 , V_44 ) ;
V_18 = V_56 ;
V_64 = NULL ;
while ( V_18 ) {
if ( F_13 ( V_18 , V_22 ) ) {
V_64 = V_18 ;
V_18 = F_37 ( V_18 -> V_45 ,
F_38 ( V_57 ) ) ;
continue;
}
V_58 = 0 ;
if ( V_64 ) {
F_40 ( V_64 -> V_45 , V_18 -> V_45 ) ;
} else {
V_56 = F_37 ( V_18 -> V_45 ,
F_38 ( V_57 ) ) ;
if ( V_56 ) {
V_58 = F_41 (
& V_2 -> V_43 , & V_18 -> V_62 ,
& V_56 -> V_62 , V_44 ) ;
if ( V_58 )
goto V_66;
} else {
V_58 = F_45 ( & V_2 -> V_43 ,
& V_18 -> V_62 ,
V_44 ) ;
}
}
F_24 ( V_18 ) ;
break;
}
V_66:
F_42 ( V_57 ) ;
return V_58 ;
}
static int F_46 ( struct V_49 * V_50 , struct V_33 * V_34 )
{
struct V_54 * V_54 = F_47 ( V_34 ) ;
struct V_23 V_68 ;
int V_58 ;
V_58 = F_16 ( V_34 , & V_68 ) ;
if ( V_58 )
return V_58 ;
return F_29 ( V_54 , & V_68 ) ;
}
static int F_48 ( struct V_49 * V_50 , struct V_33 * V_34 )
{
struct V_54 * V_54 = F_47 ( V_34 ) ;
struct V_23 V_22 ;
int V_58 ;
V_58 = F_16 ( V_34 , & V_22 ) ;
if ( V_58 )
return V_58 ;
F_44 ( V_54 , & V_22 ) ;
return 0 ;
}
static int F_49 ( struct V_17 * V_18 , struct V_49 * V_69 )
{
if ( F_50 ( V_69 , V_36 ,
( V_38 V_70 ) V_18 -> V_22 . V_27 . V_37 . V_29 ,
V_71 ) ||
F_50 ( V_69 , V_39 ,
( V_38 V_70 ) V_18 -> V_22 . V_27 . V_28 . V_29 ,
V_71 ) ||
F_51 ( V_69 , V_42 , V_18 -> V_22 . V_21 ) ||
F_52 ( V_69 , V_40 , V_18 -> V_22 . V_27 . V_41 ) )
return - 1 ;
return 0 ;
}
static int F_53 ( struct V_17 * V_18 ,
T_2 V_72 , T_2 V_73 , T_2 V_74 ,
struct V_49 * V_50 , T_3 V_75 )
{
void * V_76 ;
V_76 = F_54 ( V_50 , V_72 , V_73 , & V_77 , V_74 , V_75 ) ;
if ( ! V_76 )
return - V_10 ;
if ( F_49 ( V_18 , V_50 ) < 0 )
goto V_78;
F_55 ( V_50 , V_76 ) ;
return 0 ;
V_78:
F_56 ( V_50 , V_76 ) ;
return - V_79 ;
}
static int F_57 ( struct V_49 * V_50 , struct V_33 * V_34 )
{
struct V_54 * V_54 = F_47 ( V_34 ) ;
struct V_1 * V_2 = F_30 ( V_54 , V_55 ) ;
struct V_49 * V_69 ;
struct V_23 V_22 ;
struct V_17 * V_18 ;
int V_80 ;
V_80 = F_16 ( V_34 , & V_22 ) ;
if ( V_80 )
return V_80 ;
V_69 = F_58 ( V_81 , V_9 ) ;
if ( ! V_69 )
return - V_10 ;
F_59 () ;
V_18 = F_23 ( & V_22 , V_2 ) ;
if ( V_18 ) {
V_80 = F_53 ( V_18 ,
V_34 -> V_82 ,
V_34 -> V_83 , 0 , V_69 ,
V_34 -> V_84 -> V_75 ) ;
}
F_60 () ;
if ( V_80 < 0 )
goto V_85;
return F_61 ( V_69 , V_34 ) ;
V_85:
F_62 ( V_69 ) ;
return V_80 ;
}
static int F_63 ( struct V_86 * V_87 )
{
struct V_54 * V_54 = F_64 ( V_87 -> V_50 -> V_88 ) ;
struct V_1 * V_2 = F_30 ( V_54 , V_55 ) ;
struct V_89 * V_90 = (struct V_89 * ) V_87 -> args [ 0 ] ;
if ( ! V_90 ) {
V_90 = F_65 ( sizeof( * V_90 ) , V_9 ) ;
if ( ! V_90 )
return - V_10 ;
V_87 -> args [ 0 ] = ( long ) V_90 ;
}
return F_66 ( & V_2 -> V_43 , & V_90 -> V_91 ,
V_9 ) ;
}
static int F_67 ( struct V_86 * V_87 )
{
struct V_89 * V_90 = (struct V_89 * ) V_87 -> args [ 0 ] ;
F_68 ( & V_90 -> V_91 ) ;
F_43 ( V_90 ) ;
return 0 ;
}
static int F_69 ( struct V_49 * V_50 , struct V_86 * V_87 )
{
struct V_89 * V_90 = (struct V_89 * ) V_87 -> args [ 0 ] ;
struct V_92 * V_91 = & V_90 -> V_91 ;
struct V_17 * V_18 ;
int V_80 ;
V_80 = F_70 ( V_91 ) ;
if ( V_80 && V_80 != - V_93 )
goto V_94;
for (; ; ) {
V_18 = F_71 ( V_91 ) ;
if ( F_72 ( V_18 ) ) {
if ( F_73 ( V_18 ) == - V_93 )
continue;
V_80 = F_73 ( V_18 ) ;
goto V_94;
} else if ( ! V_18 ) {
break;
}
while ( V_18 ) {
V_80 = F_53 ( V_18 , F_74 ( V_87 -> V_50 ) . V_72 ,
V_87 -> V_95 -> V_96 , V_97 ,
V_50 , V_98 ) ;
if ( V_80 )
goto V_94;
V_18 = F_22 ( V_18 -> V_45 ) ;
}
}
V_80 = V_50 -> V_99 ;
V_94:
F_75 ( V_91 ) ;
return V_80 ;
}
static T_4 int F_76 ( struct V_54 * V_54 )
{
int V_58 ;
struct V_1 * V_2 = F_30 ( V_54 , V_55 ) ;
V_58 = F_1 ( V_2 ) ;
if ( V_58 )
return V_58 ;
F_77 ( & V_2 -> V_43 , & V_44 ) ;
return 0 ;
}
static T_5 void F_78 ( struct V_54 * V_54 )
{
struct V_1 * V_2 = F_30 ( V_54 , V_55 ) ;
F_79 ( & V_2 -> V_43 , F_26 , NULL ) ;
F_80 ( V_2 -> V_8 ) ;
if ( V_2 -> V_60 )
F_81 ( V_54 , V_61 ,
F_32 ( V_61 ) ) ;
}
static int F_28 ( struct V_49 * V_50 , bool V_100 )
{
struct V_17 * V_18 ;
struct V_101 * V_102 = F_82 ( V_50 ) ;
struct V_54 * V_54 = F_83 ( V_50 -> V_103 ) ;
struct V_1 * V_2 = F_30 ( V_54 , V_55 ) ;
struct V_19 * V_20 = F_84 ( & V_102 -> V_104 ) ;
if ( ! F_85 ( V_20 ) ) {
return 0 ;
}
F_59 () ;
V_18 = F_20 ( V_20 , V_50 -> V_103 -> V_21 , V_2 ) ;
if ( V_18 )
F_86 ( V_50 , & V_18 -> V_22 . V_27 , V_100 ) ;
F_60 () ;
return 0 ;
}
int T_6 F_87 ( void )
{
int V_80 ;
V_80 = F_88 ( & V_105 ) ;
if ( V_80 )
goto exit;
V_80 = F_89 ( & V_77 ) ;
if ( V_80 < 0 )
goto V_106;
return 0 ;
V_106:
F_90 ( & V_105 ) ;
exit:
return V_80 ;
}
void F_91 ( void )
{
F_92 ( & V_77 ) ;
F_90 ( & V_105 ) ;
}
