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
struct V_34 * V_35 , * V_36 ;
F_19 ( V_23 ) ;
int V_4 , V_30 = 0 ;
for ( V_4 = 0 ; V_4 < F_20 ( V_3 ) ; V_4 ++ ) {
int V_37 = 0 ;
F_21 (fle, entry, tmp,
&fcp->hash_table[i], u.hlist) {
if ( V_37 < V_33 &&
F_5 ( V_12 ) ) {
V_37 ++ ;
} else {
V_30 ++ ;
F_22 ( & V_12 -> V_38 . V_39 ) ;
F_23 ( & V_12 -> V_38 . V_23 , & V_23 ) ;
}
}
}
F_15 ( V_29 , V_30 , & V_23 ) ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
int V_33 = V_3 -> V_40 / F_20 ( V_3 ) ;
F_18 ( V_3 , V_29 , V_33 ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
F_26 ( & V_29 -> V_41 , sizeof( V_42 ) ) ;
V_29 -> V_6 = 0 ;
F_18 ( V_3 , V_29 , 0 ) ;
}
static V_42 F_27 ( struct V_2 * V_3 ,
struct V_28 * V_29 ,
const struct V_43 * V_44 )
{
const V_42 * V_45 = ( const V_42 * ) V_44 ;
return F_28 ( V_45 , ( sizeof( * V_44 ) / sizeof( V_42 ) ) , V_29 -> V_41 )
& ( F_20 ( V_3 ) - 1 ) ;
}
static int F_29 ( const struct V_43 * V_46 , const struct V_43 * V_47 )
{
const T_1 * V_48 , * V_49 , * V_50 ;
const int V_51 = sizeof( struct V_43 ) / sizeof( T_1 ) ;
F_30 ( sizeof( struct V_43 ) % sizeof( T_1 ) ) ;
V_48 = ( const T_1 * ) V_46 ;
V_49 = V_48 + V_51 ;
V_50 = ( const T_1 * ) V_47 ;
do {
if ( * V_48 ++ != * V_50 ++ )
return 1 ;
} while ( V_48 < V_49 );
return 0 ;
}
struct V_52 *
F_31 ( struct V_53 * V_53 , const struct V_43 * V_44 , T_2 V_54 , T_3 V_55 ,
T_4 V_56 , void * V_57 )
{
struct V_2 * V_3 = & V_58 ;
struct V_28 * V_29 ;
struct V_11 * V_12 , * V_59 ;
struct V_34 * V_35 ;
struct V_52 * V_60 ;
unsigned int V_61 ;
F_32 () ;
V_29 = F_33 ( V_3 -> V_5 ) ;
V_12 = NULL ;
V_60 = NULL ;
if ( ! V_29 -> V_62 )
goto V_63;
if ( V_29 -> V_6 )
F_25 ( V_3 , V_29 ) ;
V_61 = F_27 ( V_3 , V_29 , V_44 ) ;
F_34 (tfle, entry, &fcp->hash_table[hash], u.hlist) {
if ( V_59 -> V_54 == V_54 &&
V_59 -> V_55 == V_55 &&
F_29 ( V_44 , & V_59 -> V_44 ) == 0 ) {
V_12 = V_59 ;
break;
}
}
if ( F_35 ( ! V_12 ) ) {
if ( V_29 -> V_31 > V_3 -> V_64 )
F_24 ( V_3 , V_29 ) ;
V_12 = F_36 ( V_19 , V_65 ) ;
if ( V_12 ) {
V_12 -> V_54 = V_54 ;
V_12 -> V_55 = V_55 ;
memcpy ( & V_12 -> V_44 , V_44 , sizeof( * V_44 ) ) ;
V_12 -> V_15 = NULL ;
F_37 ( & V_12 -> V_38 . V_39 , & V_29 -> V_62 [ V_61 ] ) ;
V_29 -> V_31 ++ ;
}
} else if ( F_38 ( V_12 -> V_14 == F_6 ( & V_13 ) ) ) {
V_60 = V_12 -> V_15 ;
if ( ! V_60 )
goto V_66;
V_60 = V_60 -> V_16 -> V_67 ( V_60 ) ;
if ( V_60 )
goto V_66;
} else if ( V_12 -> V_15 ) {
V_60 = V_12 -> V_15 ;
V_60 -> V_16 -> V_18 ( V_60 ) ;
V_12 -> V_15 = NULL ;
}
V_63:
V_60 = NULL ;
if ( V_12 ) {
V_60 = V_12 -> V_15 ;
V_12 -> V_15 = NULL ;
}
V_60 = V_56 ( V_53 , V_44 , V_54 , V_55 , V_60 , V_57 ) ;
if ( V_12 ) {
V_12 -> V_14 = F_6 ( & V_13 ) ;
if ( ! F_39 ( V_60 ) )
V_12 -> V_15 = V_60 ;
else
V_12 -> V_14 -- ;
} else {
if ( V_60 && ! F_39 ( V_60 ) )
V_60 -> V_16 -> V_18 ( V_60 ) ;
}
V_66:
F_40 () ;
return V_60 ;
}
static void F_41 ( unsigned long V_68 )
{
struct V_69 * V_70 = ( void * ) V_68 ;
struct V_2 * V_3 = V_70 -> V_71 ;
struct V_28 * V_29 ;
struct V_11 * V_12 ;
struct V_34 * V_35 , * V_36 ;
F_19 ( V_23 ) ;
int V_4 , V_30 = 0 ;
V_29 = F_33 ( V_3 -> V_5 ) ;
for ( V_4 = 0 ; V_4 < F_20 ( V_3 ) ; V_4 ++ ) {
F_21 (fle, entry, tmp,
&fcp->hash_table[i], u.hlist) {
if ( F_5 ( V_12 ) )
continue;
V_30 ++ ;
F_22 ( & V_12 -> V_38 . V_39 ) ;
F_23 ( & V_12 -> V_38 . V_23 , & V_23 ) ;
}
}
F_15 ( V_29 , V_30 , & V_23 ) ;
if ( F_42 ( & V_70 -> V_72 ) )
F_43 ( & V_70 -> V_73 ) ;
}
static void F_44 ( void * V_68 )
{
struct V_69 * V_70 = V_68 ;
int V_74 ;
struct V_75 * V_76 ;
V_74 = F_45 () ;
V_76 = & F_3 ( V_70 -> V_71 -> V_5 , V_74 ) -> V_77 ;
V_76 -> V_68 = ( unsigned long ) V_70 ;
F_46 ( V_76 ) ;
}
void F_47 ( void )
{
struct V_69 V_70 ;
static F_48 ( V_78 ) ;
F_49 () ;
F_50 ( & V_78 ) ;
V_70 . V_71 = & V_58 ;
F_51 ( & V_70 . V_72 , F_52 () ) ;
F_53 ( & V_70 . V_73 ) ;
F_32 () ;
F_54 ( F_44 , & V_70 , 0 ) ;
F_41 ( ( unsigned long ) & V_70 ) ;
F_40 () ;
F_55 ( & V_70 . V_73 ) ;
F_56 ( & V_78 ) ;
F_57 () ;
}
static int T_5 F_58 ( struct V_2 * V_3 , int V_74 )
{
struct V_28 * V_29 = F_3 ( V_3 -> V_5 , V_74 ) ;
T_6 V_79 = sizeof( struct V_80 ) * F_20 ( V_3 ) ;
if ( ! V_29 -> V_62 ) {
V_29 -> V_62 = F_59 ( V_79 , V_81 , F_60 ( V_74 ) ) ;
if ( ! V_29 -> V_62 ) {
F_61 ( L_1 , V_79 ) ;
return - V_82 ;
}
V_29 -> V_6 = 1 ;
V_29 -> V_31 = 0 ;
F_62 ( & V_29 -> V_77 , F_41 , 0 ) ;
}
return 0 ;
}
static int T_5 F_63 ( struct V_83 * V_84 ,
unsigned long V_85 ,
void * V_86 )
{
struct V_2 * V_3 = F_64 ( V_84 , struct V_2 , V_87 ) ;
int V_88 , V_74 = ( unsigned long ) V_86 ;
struct V_28 * V_29 = F_3 ( V_3 -> V_5 , V_74 ) ;
switch ( V_85 ) {
case V_89 :
case V_90 :
V_88 = F_58 ( V_3 , V_74 ) ;
if ( V_88 )
return F_65 ( V_88 ) ;
break;
case V_91 :
case V_92 :
F_18 ( V_3 , V_29 , 0 ) ;
break;
}
return V_93 ;
}
static int T_7 F_66 ( struct V_2 * V_3 )
{
int V_4 ;
V_3 -> V_94 = 10 ;
V_3 -> V_40 = 2 * F_20 ( V_3 ) ;
V_3 -> V_64 = 4 * F_20 ( V_3 ) ;
V_3 -> V_5 = F_67 ( struct V_28 ) ;
if ( ! V_3 -> V_5 )
return - V_82 ;
F_68 (i) {
if ( F_58 ( V_3 , V_4 ) )
return - V_82 ;
}
V_3 -> V_87 = (struct V_83 ) {
. V_95 = F_63 ,
} ;
F_69 ( & V_3 -> V_87 ) ;
F_70 ( & V_3 -> V_7 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_7 . V_8 = V_9 + V_10 ;
F_4 ( & V_3 -> V_7 ) ;
return 0 ;
}
static int T_7 F_71 ( void )
{
V_19 = F_72 ( L_2 ,
sizeof( struct V_11 ) ,
0 , V_96 , NULL ) ;
return F_66 ( & V_58 ) ;
}
