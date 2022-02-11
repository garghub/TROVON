static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
int V_4 ;
F_2 (i)
F_3 ( V_3 -> V_5 , V_4 ) -> V_6 = 1 ;
V_3 -> V_7 . V_8 = V_9 + V_10 ;
F_4 ( & V_3 -> V_7 ) ;
}
static int F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
if ( F_6 ( & V_14 -> V_15 ) != V_12 -> V_16 )
return 0 ;
if ( V_12 -> V_17 && ! V_12 -> V_17 -> V_18 -> V_19 ( V_12 -> V_17 ) )
return 0 ;
return 1 ;
}
static void F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
if ( V_12 -> V_17 )
V_12 -> V_17 -> V_18 -> V_20 ( V_12 -> V_17 ) ;
F_8 ( V_21 , V_12 ) ;
}
static void F_9 ( struct V_22 * V_23 )
{
struct V_24 V_25 ;
struct V_11 * V_26 , * V_27 ;
struct V_13 * V_14 = F_10 ( V_23 , struct V_13 ,
V_28 ) ;
F_11 ( & V_25 ) ;
F_12 ( & V_14 -> V_29 ) ;
F_13 ( & V_14 -> V_30 , & V_25 ) ;
F_14 ( & V_14 -> V_29 ) ;
F_15 (fce, n, &gc_list, u.gc_list)
F_7 ( V_26 , V_14 ) ;
}
static void F_16 ( struct V_31 * V_32 ,
int V_33 , struct V_24 * V_25 ,
struct V_13 * V_14 )
{
if ( V_33 ) {
V_32 -> V_34 -= V_33 ;
F_12 ( & V_14 -> V_29 ) ;
F_17 ( V_25 , & V_14 -> V_30 ) ;
F_14 ( & V_14 -> V_29 ) ;
F_18 ( & V_14 -> V_28 ) ;
}
}
static void F_19 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
int V_35 )
{
struct V_11 * V_12 ;
struct V_36 * V_37 ;
F_20 ( V_25 ) ;
int V_4 , V_33 = 0 ;
struct V_13 * V_14 = F_10 ( V_3 , struct V_13 ,
V_38 ) ;
for ( V_4 = 0 ; V_4 < F_21 ( V_3 ) ; V_4 ++ ) {
int V_39 = 0 ;
F_22 (fle, tmp,
&fcp->hash_table[i], u.hlist) {
if ( V_39 < V_35 &&
F_5 ( V_12 , V_14 ) ) {
V_39 ++ ;
} else {
V_33 ++ ;
F_23 ( & V_12 -> V_40 . V_41 ) ;
F_24 ( & V_12 -> V_40 . V_25 , & V_25 ) ;
}
}
}
F_16 ( V_32 , V_33 , & V_25 , V_14 ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
int V_35 = V_3 -> V_42 / F_21 ( V_3 ) ;
F_19 ( V_3 , V_32 , V_35 ) ;
}
static void F_26 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
F_27 ( & V_32 -> V_43 , sizeof( V_44 ) ) ;
V_32 -> V_6 = 0 ;
F_19 ( V_3 , V_32 , 0 ) ;
}
static V_44 F_28 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
const struct V_45 * V_46 ,
T_1 V_47 )
{
const V_44 * V_48 = ( const V_44 * ) V_46 ;
const V_44 V_49 = V_47 * sizeof( V_50 ) / sizeof( V_44 ) ;
return F_29 ( V_48 , V_49 , V_32 -> V_43 )
& ( F_21 ( V_3 ) - 1 ) ;
}
static int F_30 ( const struct V_45 * V_51 , const struct V_45 * V_52 ,
T_1 V_47 )
{
const V_50 * V_53 , * V_54 , * V_55 ;
V_53 = ( const V_50 * ) V_51 ;
V_54 = V_53 + V_47 ;
V_55 = ( const V_50 * ) V_52 ;
do {
if ( * V_53 ++ != * V_55 ++ )
return 1 ;
} while ( V_53 < V_54 );
return 0 ;
}
struct V_56 *
F_31 ( struct V_57 * V_57 , const struct V_45 * V_46 , T_2 V_58 , T_3 V_59 ,
T_4 V_60 , void * V_61 )
{
struct V_2 * V_3 = & V_57 -> V_14 . V_38 ;
struct V_31 * V_32 ;
struct V_11 * V_12 , * V_62 ;
struct V_56 * V_63 ;
T_1 V_47 ;
unsigned int V_64 ;
F_32 () ;
V_32 = F_33 ( V_3 -> V_5 ) ;
V_12 = NULL ;
V_63 = NULL ;
V_47 = F_34 ( V_58 ) ;
if ( ! V_47 )
goto V_65;
if ( ! V_32 -> V_66 )
goto V_65;
if ( V_32 -> V_6 )
F_26 ( V_3 , V_32 ) ;
V_64 = F_28 ( V_3 , V_32 , V_46 , V_47 ) ;
F_35 (tfle, &fcp->hash_table[hash], u.hlist) {
if ( V_62 -> V_57 == V_57 &&
V_62 -> V_58 == V_58 &&
V_62 -> V_59 == V_59 &&
F_30 ( V_46 , & V_62 -> V_46 , V_47 ) == 0 ) {
V_12 = V_62 ;
break;
}
}
if ( F_36 ( ! V_12 ) ) {
if ( V_32 -> V_34 > V_3 -> V_67 )
F_25 ( V_3 , V_32 ) ;
V_12 = F_37 ( V_21 , V_68 ) ;
if ( V_12 ) {
V_12 -> V_57 = V_57 ;
V_12 -> V_58 = V_58 ;
V_12 -> V_59 = V_59 ;
memcpy ( & V_12 -> V_46 , V_46 , V_47 * sizeof( V_50 ) ) ;
V_12 -> V_17 = NULL ;
F_38 ( & V_12 -> V_40 . V_41 , & V_32 -> V_66 [ V_64 ] ) ;
V_32 -> V_34 ++ ;
}
} else if ( F_39 ( V_12 -> V_16 == F_6 ( & V_57 -> V_14 . V_15 ) ) ) {
V_63 = V_12 -> V_17 ;
if ( ! V_63 )
goto V_69;
V_63 = V_63 -> V_18 -> V_70 ( V_63 ) ;
if ( V_63 )
goto V_69;
} else if ( V_12 -> V_17 ) {
V_63 = V_12 -> V_17 ;
V_63 -> V_18 -> V_20 ( V_63 ) ;
V_12 -> V_17 = NULL ;
}
V_65:
V_63 = NULL ;
if ( V_12 ) {
V_63 = V_12 -> V_17 ;
V_12 -> V_17 = NULL ;
}
V_63 = V_60 ( V_57 , V_46 , V_58 , V_59 , V_63 , V_61 ) ;
if ( V_12 ) {
V_12 -> V_16 = F_6 ( & V_57 -> V_14 . V_15 ) ;
if ( ! F_40 ( V_63 ) )
V_12 -> V_17 = V_63 ;
else
V_12 -> V_16 -- ;
} else {
if ( ! F_41 ( V_63 ) )
V_63 -> V_18 -> V_20 ( V_63 ) ;
}
V_69:
F_42 () ;
return V_63 ;
}
static void F_43 ( unsigned long V_71 )
{
struct V_72 * V_73 = ( void * ) V_71 ;
struct V_2 * V_3 = V_73 -> V_74 ;
struct V_31 * V_32 ;
struct V_11 * V_12 ;
struct V_36 * V_37 ;
F_20 ( V_25 ) ;
int V_4 , V_33 = 0 ;
struct V_13 * V_14 = F_10 ( V_3 , struct V_13 ,
V_38 ) ;
V_32 = F_33 ( V_3 -> V_5 ) ;
for ( V_4 = 0 ; V_4 < F_21 ( V_3 ) ; V_4 ++ ) {
F_22 (fle, tmp,
&fcp->hash_table[i], u.hlist) {
if ( F_5 ( V_12 , V_14 ) )
continue;
V_33 ++ ;
F_23 ( & V_12 -> V_40 . V_41 ) ;
F_24 ( & V_12 -> V_40 . V_25 , & V_25 ) ;
}
}
F_16 ( V_32 , V_33 , & V_25 , V_14 ) ;
if ( F_44 ( & V_73 -> V_75 ) )
F_45 ( & V_73 -> V_76 ) ;
}
static int F_46 ( struct V_2 * V_3 , int V_77 )
{
struct V_31 * V_32 ;
int V_4 ;
V_32 = F_3 ( V_3 -> V_5 , V_77 ) ;
for ( V_4 = 0 ; V_4 < F_21 ( V_3 ) ; V_4 ++ )
if ( ! F_47 ( & V_32 -> V_66 [ V_4 ] ) )
return 0 ;
return 1 ;
}
static void F_48 ( void * V_71 )
{
struct V_72 * V_73 = V_71 ;
struct V_78 * V_79 ;
V_79 = & F_33 ( V_73 -> V_74 -> V_5 ) -> V_80 ;
V_79 -> V_71 = ( unsigned long ) V_73 ;
F_49 ( V_79 ) ;
}
void F_50 ( struct V_57 * V_57 )
{
struct V_72 V_73 ;
T_5 V_81 ;
int V_4 , V_82 ;
if ( ! F_51 ( & V_81 , V_83 ) )
return;
F_52 ( V_81 ) ;
F_53 () ;
F_54 ( & V_57 -> V_14 . V_84 ) ;
V_73 . V_74 = & V_57 -> V_14 . V_38 ;
F_55 (i)
if ( ! F_46 ( V_73 . V_74 , V_4 ) )
F_56 ( V_4 , V_81 ) ;
F_57 ( & V_73 . V_75 , F_58 ( V_81 ) ) ;
if ( F_6 ( & V_73 . V_75 ) == 0 )
goto V_85;
F_59 ( & V_73 . V_76 ) ;
F_32 () ;
V_82 = F_60 ( F_61 () , V_81 ) ;
F_62 ( V_81 , F_48 , & V_73 , 0 ) ;
if ( V_82 )
F_43 ( ( unsigned long ) & V_73 ) ;
F_42 () ;
F_63 ( & V_73 . V_76 ) ;
V_85:
F_64 ( & V_57 -> V_14 . V_84 ) ;
F_65 () ;
F_66 ( V_81 ) ;
}
static void F_67 ( struct V_22 * V_23 )
{
struct V_13 * V_14 = F_10 ( V_23 , struct V_13 ,
V_86 ) ;
struct V_57 * V_57 = F_10 ( V_14 , struct V_57 , V_14 ) ;
F_50 ( V_57 ) ;
}
void F_68 ( struct V_57 * V_57 )
{
F_18 ( & V_57 -> V_14 . V_86 ) ;
}
static int F_69 ( struct V_2 * V_3 , int V_77 )
{
struct V_31 * V_32 = F_3 ( V_3 -> V_5 , V_77 ) ;
T_1 V_87 = sizeof( struct V_88 ) * F_21 ( V_3 ) ;
if ( ! V_32 -> V_66 ) {
V_32 -> V_66 = F_70 ( V_87 , V_83 , F_71 ( V_77 ) ) ;
if ( ! V_32 -> V_66 ) {
F_72 ( L_1 , V_87 ) ;
return - V_89 ;
}
V_32 -> V_6 = 1 ;
V_32 -> V_34 = 0 ;
F_73 ( & V_32 -> V_80 , F_43 , 0 ) ;
}
return 0 ;
}
static int F_74 ( struct V_90 * V_91 ,
unsigned long V_92 ,
void * V_93 )
{
struct V_2 * V_3 = F_10 ( V_91 , struct V_2 ,
V_94 ) ;
int V_95 , V_77 = ( unsigned long ) V_93 ;
struct V_31 * V_32 = F_3 ( V_3 -> V_5 , V_77 ) ;
switch ( V_92 ) {
case V_96 :
case V_97 :
V_95 = F_69 ( V_3 , V_77 ) ;
if ( V_95 )
return F_75 ( V_95 ) ;
break;
case V_98 :
case V_99 :
F_19 ( V_3 , V_32 , 0 ) ;
break;
}
return V_100 ;
}
int F_76 ( struct V_57 * V_57 )
{
int V_4 ;
struct V_2 * V_3 = & V_57 -> V_14 . V_38 ;
if ( ! V_21 )
V_21 = F_77 ( L_2 ,
sizeof( struct V_11 ) ,
0 , V_101 , NULL ) ;
F_78 ( & V_57 -> V_14 . V_29 ) ;
F_11 ( & V_57 -> V_14 . V_30 ) ;
F_79 ( & V_57 -> V_14 . V_28 , F_9 ) ;
F_79 ( & V_57 -> V_14 . V_86 , F_67 ) ;
F_80 ( & V_57 -> V_14 . V_84 ) ;
V_3 -> V_102 = 10 ;
V_3 -> V_42 = 2 * F_21 ( V_3 ) ;
V_3 -> V_67 = 4 * F_21 ( V_3 ) ;
V_3 -> V_5 = F_81 ( struct V_31 ) ;
if ( ! V_3 -> V_5 )
return - V_89 ;
F_82 () ;
F_55 (i) {
if ( F_69 ( V_3 , V_4 ) )
goto V_103;
}
V_3 -> V_94 = (struct V_90 ) {
. V_104 = F_74 ,
} ;
F_83 ( & V_3 -> V_94 ) ;
F_84 () ;
F_85 ( & V_3 -> V_7 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_7 . V_8 = V_9 + V_10 ;
F_4 ( & V_3 -> V_7 ) ;
return 0 ;
V_103:
F_2 (i) {
struct V_31 * V_32 = F_3 ( V_3 -> V_5 , V_4 ) ;
F_86 ( V_32 -> V_66 ) ;
V_32 -> V_66 = NULL ;
}
F_84 () ;
F_87 ( V_3 -> V_5 ) ;
V_3 -> V_5 = NULL ;
return - V_89 ;
}
void F_88 ( struct V_57 * V_57 )
{
int V_4 ;
struct V_2 * V_3 = & V_57 -> V_14 . V_38 ;
F_89 ( & V_3 -> V_7 ) ;
F_90 ( & V_3 -> V_94 ) ;
F_2 (i) {
struct V_31 * V_32 = F_3 ( V_3 -> V_5 , V_4 ) ;
F_86 ( V_32 -> V_66 ) ;
V_32 -> V_66 = NULL ;
}
F_87 ( V_3 -> V_5 ) ;
V_3 -> V_5 = NULL ;
}
