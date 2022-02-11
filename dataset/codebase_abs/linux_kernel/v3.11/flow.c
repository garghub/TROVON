static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
int V_4 ;
F_2 (i)
F_3 ( V_3 -> V_5 , V_4 ) -> V_6 = 1 ;
V_3 -> V_7 . V_8 = V_9 + V_10 ;
F_4 ( & V_3 -> V_7 ) ;
}
static int F_5 ( struct V_11 * V_12 )
{
if ( F_6 ( & V_13 ) != V_12 -> V_14 )
return 0 ;
if ( V_12 -> V_15 && ! V_12 -> V_15 -> V_16 -> V_17 ( V_12 -> V_15 ) )
return 0 ;
return 1 ;
}
static void F_7 ( struct V_11 * V_12 )
{
if ( V_12 -> V_15 )
V_12 -> V_15 -> V_16 -> V_18 ( V_12 -> V_15 ) ;
F_8 ( V_19 , V_12 ) ;
}
static void F_9 ( struct V_20 * V_21 )
{
struct V_22 V_23 ;
struct V_11 * V_24 , * V_25 ;
F_10 ( & V_23 ) ;
F_11 ( & V_26 ) ;
F_12 ( & V_27 , & V_23 ) ;
F_13 ( & V_26 ) ;
F_14 (fce, n, &gc_list, u.gc_list)
F_7 ( V_24 ) ;
}
static void F_15 ( struct V_28 * V_29 ,
int V_30 , struct V_22 * V_23 )
{
if ( V_30 ) {
V_29 -> V_31 -= V_30 ;
F_11 ( & V_26 ) ;
F_16 ( V_23 , & V_27 ) ;
F_13 ( & V_26 ) ;
F_17 ( & V_32 ) ;
}
}
static void F_18 ( struct V_2 * V_3 ,
struct V_28 * V_29 ,
int V_33 )
{
struct V_11 * V_12 ;
struct V_34 * V_35 ;
F_19 ( V_23 ) ;
int V_4 , V_30 = 0 ;
for ( V_4 = 0 ; V_4 < F_20 ( V_3 ) ; V_4 ++ ) {
int V_36 = 0 ;
F_21 (fle, tmp,
&fcp->hash_table[i], u.hlist) {
if ( V_36 < V_33 &&
F_5 ( V_12 ) ) {
V_36 ++ ;
} else {
V_30 ++ ;
F_22 ( & V_12 -> V_37 . V_38 ) ;
F_23 ( & V_12 -> V_37 . V_23 , & V_23 ) ;
}
}
}
F_15 ( V_29 , V_30 , & V_23 ) ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
int V_33 = V_3 -> V_39 / F_20 ( V_3 ) ;
F_18 ( V_3 , V_29 , V_33 ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
F_26 ( & V_29 -> V_40 , sizeof( V_41 ) ) ;
V_29 -> V_6 = 0 ;
F_18 ( V_3 , V_29 , 0 ) ;
}
static V_41 F_27 ( struct V_2 * V_3 ,
struct V_28 * V_29 ,
const struct V_42 * V_43 ,
T_1 V_44 )
{
const V_41 * V_45 = ( const V_41 * ) V_43 ;
const V_41 V_46 = V_44 * sizeof( V_47 ) / sizeof( V_41 ) ;
return F_28 ( V_45 , V_46 , V_29 -> V_40 )
& ( F_20 ( V_3 ) - 1 ) ;
}
static int F_29 ( const struct V_42 * V_48 , const struct V_42 * V_49 ,
T_1 V_44 )
{
const V_47 * V_50 , * V_51 , * V_52 ;
V_50 = ( const V_47 * ) V_48 ;
V_51 = V_50 + V_44 ;
V_52 = ( const V_47 * ) V_49 ;
do {
if ( * V_50 ++ != * V_52 ++ )
return 1 ;
} while ( V_50 < V_51 );
return 0 ;
}
struct V_53 *
F_30 ( struct V_54 * V_54 , const struct V_42 * V_43 , T_2 V_55 , T_3 V_56 ,
T_4 V_57 , void * V_58 )
{
struct V_2 * V_3 = & V_59 ;
struct V_28 * V_29 ;
struct V_11 * V_12 , * V_60 ;
struct V_53 * V_61 ;
T_1 V_44 ;
unsigned int V_62 ;
F_31 () ;
V_29 = F_32 ( V_3 -> V_5 ) ;
V_12 = NULL ;
V_61 = NULL ;
V_44 = F_33 ( V_55 ) ;
if ( ! V_44 )
goto V_63;
if ( ! V_29 -> V_64 )
goto V_63;
if ( V_29 -> V_6 )
F_25 ( V_3 , V_29 ) ;
V_62 = F_27 ( V_3 , V_29 , V_43 , V_44 ) ;
F_34 (tfle, &fcp->hash_table[hash], u.hlist) {
if ( V_60 -> V_54 == V_54 &&
V_60 -> V_55 == V_55 &&
V_60 -> V_56 == V_56 &&
F_29 ( V_43 , & V_60 -> V_43 , V_44 ) == 0 ) {
V_12 = V_60 ;
break;
}
}
if ( F_35 ( ! V_12 ) ) {
if ( V_29 -> V_31 > V_3 -> V_65 )
F_24 ( V_3 , V_29 ) ;
V_12 = F_36 ( V_19 , V_66 ) ;
if ( V_12 ) {
V_12 -> V_54 = V_54 ;
V_12 -> V_55 = V_55 ;
V_12 -> V_56 = V_56 ;
memcpy ( & V_12 -> V_43 , V_43 , V_44 * sizeof( V_47 ) ) ;
V_12 -> V_15 = NULL ;
F_37 ( & V_12 -> V_37 . V_38 , & V_29 -> V_64 [ V_62 ] ) ;
V_29 -> V_31 ++ ;
}
} else if ( F_38 ( V_12 -> V_14 == F_6 ( & V_13 ) ) ) {
V_61 = V_12 -> V_15 ;
if ( ! V_61 )
goto V_67;
V_61 = V_61 -> V_16 -> V_68 ( V_61 ) ;
if ( V_61 )
goto V_67;
} else if ( V_12 -> V_15 ) {
V_61 = V_12 -> V_15 ;
V_61 -> V_16 -> V_18 ( V_61 ) ;
V_12 -> V_15 = NULL ;
}
V_63:
V_61 = NULL ;
if ( V_12 ) {
V_61 = V_12 -> V_15 ;
V_12 -> V_15 = NULL ;
}
V_61 = V_57 ( V_54 , V_43 , V_55 , V_56 , V_61 , V_58 ) ;
if ( V_12 ) {
V_12 -> V_14 = F_6 ( & V_13 ) ;
if ( ! F_39 ( V_61 ) )
V_12 -> V_15 = V_61 ;
else
V_12 -> V_14 -- ;
} else {
if ( ! F_40 ( V_61 ) )
V_61 -> V_16 -> V_18 ( V_61 ) ;
}
V_67:
F_41 () ;
return V_61 ;
}
static void F_42 ( unsigned long V_69 )
{
struct V_70 * V_71 = ( void * ) V_69 ;
struct V_2 * V_3 = V_71 -> V_72 ;
struct V_28 * V_29 ;
struct V_11 * V_12 ;
struct V_34 * V_35 ;
F_19 ( V_23 ) ;
int V_4 , V_30 = 0 ;
V_29 = F_32 ( V_3 -> V_5 ) ;
for ( V_4 = 0 ; V_4 < F_20 ( V_3 ) ; V_4 ++ ) {
F_21 (fle, tmp,
&fcp->hash_table[i], u.hlist) {
if ( F_5 ( V_12 ) )
continue;
V_30 ++ ;
F_22 ( & V_12 -> V_37 . V_38 ) ;
F_23 ( & V_12 -> V_37 . V_23 , & V_23 ) ;
}
}
F_15 ( V_29 , V_30 , & V_23 ) ;
if ( F_43 ( & V_71 -> V_73 ) )
F_44 ( & V_71 -> V_74 ) ;
}
static int F_45 ( struct V_2 * V_3 , int V_75 )
{
struct V_28 * V_29 ;
int V_4 ;
V_29 = F_3 ( V_3 -> V_5 , V_75 ) ;
for ( V_4 = 0 ; V_4 < F_20 ( V_3 ) ; V_4 ++ )
if ( ! F_46 ( & V_29 -> V_64 [ V_4 ] ) )
return 0 ;
return 1 ;
}
static void F_47 ( void * V_69 )
{
struct V_70 * V_71 = V_69 ;
struct V_76 * V_77 ;
V_77 = & F_32 ( V_71 -> V_72 -> V_5 ) -> V_78 ;
V_77 -> V_69 = ( unsigned long ) V_71 ;
F_48 ( V_77 ) ;
}
void F_49 ( void )
{
struct V_70 V_71 ;
static F_50 ( V_79 ) ;
T_5 V_80 ;
int V_4 , V_81 ;
if ( ! F_51 ( & V_80 , V_82 ) )
return;
F_52 ( V_80 ) ;
F_53 () ;
F_54 ( & V_79 ) ;
V_71 . V_72 = & V_59 ;
F_55 (i)
if ( ! F_45 ( V_71 . V_72 , V_4 ) )
F_56 ( V_4 , V_80 ) ;
F_57 ( & V_71 . V_73 , F_58 ( V_80 ) ) ;
if ( F_6 ( & V_71 . V_73 ) == 0 )
goto V_83;
F_59 ( & V_71 . V_74 ) ;
F_31 () ;
V_81 = F_60 ( F_61 () , V_80 ) ;
F_62 ( V_80 , F_47 , & V_71 , 0 ) ;
if ( V_81 )
F_42 ( ( unsigned long ) & V_71 ) ;
F_41 () ;
F_63 ( & V_71 . V_74 ) ;
V_83:
F_64 ( & V_79 ) ;
F_65 () ;
F_66 ( V_80 ) ;
}
static void F_67 ( struct V_20 * V_21 )
{
F_49 () ;
}
void F_68 ( void )
{
F_17 ( & V_84 ) ;
}
static int F_69 ( struct V_2 * V_3 , int V_75 )
{
struct V_28 * V_29 = F_3 ( V_3 -> V_5 , V_75 ) ;
T_1 V_85 = sizeof( struct V_86 ) * F_20 ( V_3 ) ;
if ( ! V_29 -> V_64 ) {
V_29 -> V_64 = F_70 ( V_85 , V_82 , F_71 ( V_75 ) ) ;
if ( ! V_29 -> V_64 ) {
F_72 ( L_1 , V_85 ) ;
return - V_87 ;
}
V_29 -> V_6 = 1 ;
V_29 -> V_31 = 0 ;
F_73 ( & V_29 -> V_78 , F_42 , 0 ) ;
}
return 0 ;
}
static int F_74 ( struct V_88 * V_89 ,
unsigned long V_90 ,
void * V_91 )
{
struct V_2 * V_3 = F_75 ( V_89 , struct V_2 , V_92 ) ;
int V_93 , V_75 = ( unsigned long ) V_91 ;
struct V_28 * V_29 = F_3 ( V_3 -> V_5 , V_75 ) ;
switch ( V_90 ) {
case V_94 :
case V_95 :
V_93 = F_69 ( V_3 , V_75 ) ;
if ( V_93 )
return F_76 ( V_93 ) ;
break;
case V_96 :
case V_97 :
F_18 ( V_3 , V_29 , 0 ) ;
break;
}
return V_98 ;
}
static int T_6 F_77 ( struct V_2 * V_3 )
{
int V_4 ;
V_3 -> V_99 = 10 ;
V_3 -> V_39 = 2 * F_20 ( V_3 ) ;
V_3 -> V_65 = 4 * F_20 ( V_3 ) ;
V_3 -> V_5 = F_78 ( struct V_28 ) ;
if ( ! V_3 -> V_5 )
return - V_87 ;
F_55 (i) {
if ( F_69 ( V_3 , V_4 ) )
goto V_100;
}
V_3 -> V_92 = (struct V_88 ) {
. V_101 = F_74 ,
} ;
F_79 ( & V_3 -> V_92 ) ;
F_80 ( & V_3 -> V_7 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_7 . V_8 = V_9 + V_10 ;
F_4 ( & V_3 -> V_7 ) ;
return 0 ;
V_100:
F_2 (i) {
struct V_28 * V_29 = F_3 ( V_3 -> V_5 , V_4 ) ;
F_81 ( V_29 -> V_64 ) ;
V_29 -> V_64 = NULL ;
}
F_82 ( V_3 -> V_5 ) ;
V_3 -> V_5 = NULL ;
return - V_87 ;
}
static int T_6 F_83 ( void )
{
V_19 = F_84 ( L_2 ,
sizeof( struct V_11 ) ,
0 , V_102 , NULL ) ;
return F_77 ( & V_59 ) ;
}
