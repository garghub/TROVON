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
const struct V_43 * V_44 ,
T_1 V_45 )
{
const V_42 * V_46 = ( const V_42 * ) V_44 ;
const V_42 V_47 = V_45 * sizeof( V_48 ) / sizeof( V_42 ) ;
return F_28 ( V_46 , V_47 , V_29 -> V_41 )
& ( F_20 ( V_3 ) - 1 ) ;
}
static int F_29 ( const struct V_43 * V_49 , const struct V_43 * V_50 ,
T_1 V_45 )
{
const V_48 * V_51 , * V_52 , * V_53 ;
V_51 = ( const V_48 * ) V_49 ;
V_52 = V_51 + V_45 ;
V_53 = ( const V_48 * ) V_50 ;
do {
if ( * V_51 ++ != * V_53 ++ )
return 1 ;
} while ( V_51 < V_52 );
return 0 ;
}
struct V_54 *
F_30 ( struct V_55 * V_55 , const struct V_43 * V_44 , T_2 V_56 , T_3 V_57 ,
T_4 V_58 , void * V_59 )
{
struct V_2 * V_3 = & V_60 ;
struct V_28 * V_29 ;
struct V_11 * V_12 , * V_61 ;
struct V_34 * V_35 ;
struct V_54 * V_62 ;
T_1 V_45 ;
unsigned int V_63 ;
F_31 () ;
V_29 = F_32 ( V_3 -> V_5 ) ;
V_12 = NULL ;
V_62 = NULL ;
V_45 = F_33 ( V_56 ) ;
if ( ! V_45 )
goto V_64;
if ( ! V_29 -> V_65 )
goto V_64;
if ( V_29 -> V_6 )
F_25 ( V_3 , V_29 ) ;
V_63 = F_27 ( V_3 , V_29 , V_44 , V_45 ) ;
F_34 (tfle, entry, &fcp->hash_table[hash], u.hlist) {
if ( V_61 -> V_55 == V_55 &&
V_61 -> V_56 == V_56 &&
V_61 -> V_57 == V_57 &&
F_29 ( V_44 , & V_61 -> V_44 , V_45 ) == 0 ) {
V_12 = V_61 ;
break;
}
}
if ( F_35 ( ! V_12 ) ) {
if ( V_29 -> V_31 > V_3 -> V_66 )
F_24 ( V_3 , V_29 ) ;
V_12 = F_36 ( V_19 , V_67 ) ;
if ( V_12 ) {
V_12 -> V_55 = V_55 ;
V_12 -> V_56 = V_56 ;
V_12 -> V_57 = V_57 ;
memcpy ( & V_12 -> V_44 , V_44 , V_45 * sizeof( V_48 ) ) ;
V_12 -> V_15 = NULL ;
F_37 ( & V_12 -> V_38 . V_39 , & V_29 -> V_65 [ V_63 ] ) ;
V_29 -> V_31 ++ ;
}
} else if ( F_38 ( V_12 -> V_14 == F_6 ( & V_13 ) ) ) {
V_62 = V_12 -> V_15 ;
if ( ! V_62 )
goto V_68;
V_62 = V_62 -> V_16 -> V_69 ( V_62 ) ;
if ( V_62 )
goto V_68;
} else if ( V_12 -> V_15 ) {
V_62 = V_12 -> V_15 ;
V_62 -> V_16 -> V_18 ( V_62 ) ;
V_12 -> V_15 = NULL ;
}
V_64:
V_62 = NULL ;
if ( V_12 ) {
V_62 = V_12 -> V_15 ;
V_12 -> V_15 = NULL ;
}
V_62 = V_58 ( V_55 , V_44 , V_56 , V_57 , V_62 , V_59 ) ;
if ( V_12 ) {
V_12 -> V_14 = F_6 ( & V_13 ) ;
if ( ! F_39 ( V_62 ) )
V_12 -> V_15 = V_62 ;
else
V_12 -> V_14 -- ;
} else {
if ( V_62 && ! F_39 ( V_62 ) )
V_62 -> V_16 -> V_18 ( V_62 ) ;
}
V_68:
F_40 () ;
return V_62 ;
}
static void F_41 ( unsigned long V_70 )
{
struct V_71 * V_72 = ( void * ) V_70 ;
struct V_2 * V_3 = V_72 -> V_73 ;
struct V_28 * V_29 ;
struct V_11 * V_12 ;
struct V_34 * V_35 , * V_36 ;
F_19 ( V_23 ) ;
int V_4 , V_30 = 0 ;
V_29 = F_32 ( V_3 -> V_5 ) ;
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
if ( F_42 ( & V_72 -> V_74 ) )
F_43 ( & V_72 -> V_75 ) ;
}
static void F_44 ( void * V_70 )
{
struct V_71 * V_72 = V_70 ;
int V_76 ;
struct V_77 * V_78 ;
V_76 = F_45 () ;
V_78 = & F_3 ( V_72 -> V_73 -> V_5 , V_76 ) -> V_79 ;
V_78 -> V_70 = ( unsigned long ) V_72 ;
F_46 ( V_78 ) ;
}
void F_47 ( void )
{
struct V_71 V_72 ;
static F_48 ( V_80 ) ;
F_49 () ;
F_50 ( & V_80 ) ;
V_72 . V_73 = & V_60 ;
F_51 ( & V_72 . V_74 , F_52 () ) ;
F_53 ( & V_72 . V_75 ) ;
F_31 () ;
F_54 ( F_44 , & V_72 , 0 ) ;
F_41 ( ( unsigned long ) & V_72 ) ;
F_40 () ;
F_55 ( & V_72 . V_75 ) ;
F_56 ( & V_80 ) ;
F_57 () ;
}
static void F_58 ( struct V_20 * V_21 )
{
F_47 () ;
}
void F_59 ( void )
{
F_17 ( & V_81 ) ;
}
static int T_5 F_60 ( struct V_2 * V_3 , int V_76 )
{
struct V_28 * V_29 = F_3 ( V_3 -> V_5 , V_76 ) ;
T_1 V_82 = sizeof( struct V_83 ) * F_20 ( V_3 ) ;
if ( ! V_29 -> V_65 ) {
V_29 -> V_65 = F_61 ( V_82 , V_84 , F_62 ( V_76 ) ) ;
if ( ! V_29 -> V_65 ) {
F_63 ( L_1 , V_82 ) ;
return - V_85 ;
}
V_29 -> V_6 = 1 ;
V_29 -> V_31 = 0 ;
F_64 ( & V_29 -> V_79 , F_41 , 0 ) ;
}
return 0 ;
}
static int T_5 F_65 ( struct V_86 * V_87 ,
unsigned long V_88 ,
void * V_89 )
{
struct V_2 * V_3 = F_66 ( V_87 , struct V_2 , V_90 ) ;
int V_91 , V_76 = ( unsigned long ) V_89 ;
struct V_28 * V_29 = F_3 ( V_3 -> V_5 , V_76 ) ;
switch ( V_88 ) {
case V_92 :
case V_93 :
V_91 = F_60 ( V_3 , V_76 ) ;
if ( V_91 )
return F_67 ( V_91 ) ;
break;
case V_94 :
case V_95 :
F_18 ( V_3 , V_29 , 0 ) ;
break;
}
return V_96 ;
}
static int T_6 F_68 ( struct V_2 * V_3 )
{
int V_4 ;
V_3 -> V_97 = 10 ;
V_3 -> V_40 = 2 * F_20 ( V_3 ) ;
V_3 -> V_66 = 4 * F_20 ( V_3 ) ;
V_3 -> V_5 = F_69 ( struct V_28 ) ;
if ( ! V_3 -> V_5 )
return - V_85 ;
F_70 (i) {
if ( F_60 ( V_3 , V_4 ) )
goto V_98;
}
V_3 -> V_90 = (struct V_86 ) {
. V_99 = F_65 ,
} ;
F_71 ( & V_3 -> V_90 ) ;
F_72 ( & V_3 -> V_7 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_7 . V_8 = V_9 + V_10 ;
F_4 ( & V_3 -> V_7 ) ;
return 0 ;
V_98:
F_2 (i) {
struct V_28 * V_29 = F_3 ( V_3 -> V_5 , V_4 ) ;
F_73 ( V_29 -> V_65 ) ;
V_29 -> V_65 = NULL ;
}
F_74 ( V_3 -> V_5 ) ;
V_3 -> V_5 = NULL ;
return - V_85 ;
}
static int T_6 F_75 ( void )
{
V_19 = F_76 ( L_2 ,
sizeof( struct V_11 ) ,
0 , V_100 , NULL ) ;
return F_68 ( & V_60 ) ;
}
