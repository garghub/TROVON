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
F_15 (fce, n, &gc_list, u.gc_list) {
F_7 ( V_26 , V_14 ) ;
F_16 ( & V_14 -> V_31 ) ;
}
}
static void F_17 ( struct V_32 * V_33 ,
unsigned int V_34 ,
struct V_24 * V_25 ,
struct V_13 * V_14 )
{
if ( V_34 ) {
F_18 ( V_34 , & V_14 -> V_31 ) ;
V_33 -> V_35 -= V_34 ;
F_12 ( & V_14 -> V_29 ) ;
F_19 ( V_25 , & V_14 -> V_30 ) ;
F_14 ( & V_14 -> V_29 ) ;
F_20 ( & V_14 -> V_28 ) ;
}
}
static void F_21 ( struct V_2 * V_3 ,
struct V_32 * V_33 ,
unsigned int V_36 )
{
struct V_11 * V_12 ;
struct V_37 * V_38 ;
F_22 ( V_25 ) ;
unsigned int V_34 = 0 ;
struct V_13 * V_14 = F_10 ( V_3 , struct V_13 ,
V_39 ) ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_23 ( V_3 ) ; V_4 ++ ) {
unsigned int V_40 = 0 ;
F_24 (fle, tmp,
&fcp->hash_table[i], u.hlist) {
if ( V_40 < V_36 &&
F_5 ( V_12 , V_14 ) ) {
V_40 ++ ;
} else {
V_34 ++ ;
F_25 ( & V_12 -> V_41 . V_42 ) ;
F_26 ( & V_12 -> V_41 . V_25 , & V_25 ) ;
}
}
}
F_17 ( V_33 , V_34 , & V_25 , V_14 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_32 * V_33 )
{
unsigned int V_36 = V_3 -> V_43 / F_23 ( V_3 ) ;
F_21 ( V_3 , V_33 , V_36 ) ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_32 * V_33 )
{
F_29 ( & V_33 -> V_44 , sizeof( V_45 ) ) ;
V_33 -> V_6 = 0 ;
F_21 ( V_3 , V_33 , 0 ) ;
}
static V_45 F_30 ( struct V_2 * V_3 ,
struct V_32 * V_33 ,
const struct V_46 * V_47 ,
unsigned int V_48 )
{
const V_45 * V_49 = ( const V_45 * ) V_47 ;
const V_45 V_50 = V_48 * sizeof( V_51 ) / sizeof( V_45 ) ;
return F_31 ( V_49 , V_50 , V_33 -> V_44 )
& ( F_23 ( V_3 ) - 1 ) ;
}
static int F_32 ( const struct V_46 * V_52 , const struct V_46 * V_53 ,
unsigned int V_48 )
{
const V_51 * V_54 , * V_55 , * V_56 ;
V_54 = ( const V_51 * ) V_52 ;
V_55 = V_54 + V_48 ;
V_56 = ( const V_51 * ) V_53 ;
do {
if ( * V_54 ++ != * V_56 ++ )
return 1 ;
} while ( V_54 < V_55 );
return 0 ;
}
struct V_57 *
F_33 ( struct V_58 * V_58 , const struct V_46 * V_47 , T_1 V_59 , T_2 V_60 ,
T_3 V_61 , void * V_62 )
{
struct V_2 * V_3 = & V_58 -> V_14 . V_39 ;
struct V_32 * V_33 ;
struct V_11 * V_12 , * V_63 ;
struct V_57 * V_64 ;
unsigned int V_48 ;
unsigned int V_65 ;
F_34 () ;
V_33 = F_35 ( V_3 -> V_5 ) ;
V_12 = NULL ;
V_64 = NULL ;
V_48 = F_36 ( V_59 ) ;
if ( ! V_48 )
goto V_66;
if ( ! V_33 -> V_67 )
goto V_66;
if ( V_33 -> V_6 )
F_28 ( V_3 , V_33 ) ;
V_65 = F_30 ( V_3 , V_33 , V_47 , V_48 ) ;
F_37 (tfle, &fcp->hash_table[hash], u.hlist) {
if ( V_63 -> V_58 == V_58 &&
V_63 -> V_59 == V_59 &&
V_63 -> V_60 == V_60 &&
F_32 ( V_47 , & V_63 -> V_47 , V_48 ) == 0 ) {
V_12 = V_63 ;
break;
}
}
if ( F_38 ( ! V_12 ) ) {
if ( V_33 -> V_35 > V_3 -> V_68 )
F_27 ( V_3 , V_33 ) ;
if ( F_6 ( & V_58 -> V_14 . V_31 ) >
2 * F_39 () * V_3 -> V_68 ) {
V_64 = F_40 ( - V_69 ) ;
goto V_70;
}
V_12 = F_41 ( V_21 , V_71 ) ;
if ( V_12 ) {
V_12 -> V_58 = V_58 ;
V_12 -> V_59 = V_59 ;
V_12 -> V_60 = V_60 ;
memcpy ( & V_12 -> V_47 , V_47 , V_48 * sizeof( V_51 ) ) ;
V_12 -> V_17 = NULL ;
F_42 ( & V_12 -> V_41 . V_42 , & V_33 -> V_67 [ V_65 ] ) ;
V_33 -> V_35 ++ ;
}
} else if ( F_43 ( V_12 -> V_16 == F_6 ( & V_58 -> V_14 . V_15 ) ) ) {
V_64 = V_12 -> V_17 ;
if ( ! V_64 )
goto V_70;
V_64 = V_64 -> V_18 -> V_72 ( V_64 ) ;
if ( V_64 )
goto V_70;
} else if ( V_12 -> V_17 ) {
V_64 = V_12 -> V_17 ;
V_64 -> V_18 -> V_20 ( V_64 ) ;
V_12 -> V_17 = NULL ;
}
V_66:
V_64 = NULL ;
if ( V_12 ) {
V_64 = V_12 -> V_17 ;
V_12 -> V_17 = NULL ;
}
V_64 = V_61 ( V_58 , V_47 , V_59 , V_60 , V_64 , V_62 ) ;
if ( V_12 ) {
V_12 -> V_16 = F_6 ( & V_58 -> V_14 . V_15 ) ;
if ( ! F_44 ( V_64 ) )
V_12 -> V_17 = V_64 ;
else
V_12 -> V_16 -- ;
} else {
if ( ! F_45 ( V_64 ) )
V_64 -> V_18 -> V_20 ( V_64 ) ;
}
V_70:
F_46 () ;
return V_64 ;
}
static void F_47 ( unsigned long V_73 )
{
struct V_74 * V_75 = ( void * ) V_73 ;
struct V_2 * V_3 = V_75 -> V_76 ;
struct V_32 * V_33 ;
struct V_11 * V_12 ;
struct V_37 * V_38 ;
F_22 ( V_25 ) ;
unsigned int V_34 = 0 ;
struct V_13 * V_14 = F_10 ( V_3 , struct V_13 ,
V_39 ) ;
unsigned int V_4 ;
V_33 = F_35 ( V_3 -> V_5 ) ;
for ( V_4 = 0 ; V_4 < F_23 ( V_3 ) ; V_4 ++ ) {
F_24 (fle, tmp,
&fcp->hash_table[i], u.hlist) {
if ( F_5 ( V_12 , V_14 ) )
continue;
V_34 ++ ;
F_25 ( & V_12 -> V_41 . V_42 ) ;
F_26 ( & V_12 -> V_41 . V_25 , & V_25 ) ;
}
}
F_17 ( V_33 , V_34 , & V_25 , V_14 ) ;
if ( F_48 ( & V_75 -> V_77 ) )
F_49 ( & V_75 -> V_78 ) ;
}
static int F_50 ( struct V_2 * V_3 , int V_79 )
{
struct V_32 * V_33 ;
unsigned int V_4 ;
V_33 = F_3 ( V_3 -> V_5 , V_79 ) ;
for ( V_4 = 0 ; V_4 < F_23 ( V_3 ) ; V_4 ++ )
if ( ! F_51 ( & V_33 -> V_67 [ V_4 ] ) )
return 0 ;
return 1 ;
}
static void F_52 ( void * V_73 )
{
struct V_74 * V_75 = V_73 ;
struct V_80 * V_81 ;
V_81 = & F_35 ( V_75 -> V_76 -> V_5 ) -> V_82 ;
V_81 -> V_73 = ( unsigned long ) V_75 ;
F_53 ( V_81 ) ;
}
void F_54 ( struct V_58 * V_58 )
{
struct V_74 V_75 ;
T_4 V_83 ;
int V_4 , V_84 ;
if ( ! F_55 ( & V_83 , V_85 ) )
return;
F_56 ( V_83 ) ;
F_57 () ;
F_58 ( & V_58 -> V_14 . V_86 ) ;
V_75 . V_76 = & V_58 -> V_14 . V_39 ;
F_59 (i)
if ( ! F_50 ( V_75 . V_76 , V_4 ) )
F_60 ( V_4 , V_83 ) ;
F_61 ( & V_75 . V_77 , F_62 ( V_83 ) ) ;
if ( F_6 ( & V_75 . V_77 ) == 0 )
goto V_87;
F_63 ( & V_75 . V_78 ) ;
F_34 () ;
V_84 = F_64 ( F_65 () , V_83 ) ;
F_66 ( V_83 , F_52 , & V_75 , 0 ) ;
if ( V_84 )
F_47 ( ( unsigned long ) & V_75 ) ;
F_46 () ;
F_67 ( & V_75 . V_78 ) ;
V_87:
F_68 ( & V_58 -> V_14 . V_86 ) ;
F_69 () ;
F_70 ( V_83 ) ;
}
static void F_71 ( struct V_22 * V_23 )
{
struct V_13 * V_14 = F_10 ( V_23 , struct V_13 ,
V_88 ) ;
struct V_58 * V_58 = F_10 ( V_14 , struct V_58 , V_14 ) ;
F_54 ( V_58 ) ;
}
void F_72 ( struct V_58 * V_58 )
{
F_20 ( & V_58 -> V_14 . V_88 ) ;
}
static int F_73 ( struct V_2 * V_3 , int V_79 )
{
struct V_32 * V_33 = F_3 ( V_3 -> V_5 , V_79 ) ;
unsigned int V_89 = sizeof( struct V_90 ) * F_23 ( V_3 ) ;
if ( ! V_33 -> V_67 ) {
V_33 -> V_67 = F_74 ( V_89 , V_85 , F_75 ( V_79 ) ) ;
if ( ! V_33 -> V_67 ) {
F_76 ( L_1 , V_89 ) ;
return - V_91 ;
}
V_33 -> V_6 = 1 ;
V_33 -> V_35 = 0 ;
F_77 ( & V_33 -> V_82 , F_47 , 0 ) ;
}
return 0 ;
}
static int F_78 ( unsigned int V_79 , struct V_37 * V_92 )
{
struct V_2 * V_3 = F_79 ( V_92 , struct V_2 , V_92 ) ;
return F_73 ( V_3 , V_79 ) ;
}
static int F_80 ( unsigned int V_79 , struct V_37 * V_92 )
{
struct V_2 * V_3 = F_79 ( V_92 , struct V_2 , V_92 ) ;
struct V_32 * V_33 = F_3 ( V_3 -> V_5 , V_79 ) ;
F_21 ( V_3 , V_33 , 0 ) ;
return 0 ;
}
int F_81 ( struct V_58 * V_58 )
{
int V_4 ;
struct V_2 * V_3 = & V_58 -> V_14 . V_39 ;
if ( ! V_21 )
V_21 = F_82 ( L_2 ,
sizeof( struct V_11 ) ,
0 , V_93 , NULL ) ;
F_83 ( & V_58 -> V_14 . V_29 ) ;
F_11 ( & V_58 -> V_14 . V_30 ) ;
F_84 ( & V_58 -> V_14 . V_28 , F_9 ) ;
F_84 ( & V_58 -> V_14 . V_88 , F_71 ) ;
F_85 ( & V_58 -> V_14 . V_86 ) ;
F_61 ( & V_58 -> V_14 . V_31 , 0 ) ;
V_3 -> V_94 = 10 ;
V_3 -> V_43 = 2 * F_23 ( V_3 ) ;
V_3 -> V_68 = 4 * F_23 ( V_3 ) ;
V_3 -> V_5 = F_86 ( struct V_32 ) ;
if ( ! V_3 -> V_5 )
return - V_91 ;
if ( F_87 ( V_95 , & V_3 -> V_92 ) )
goto V_96;
F_88 ( & V_3 -> V_7 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_7 . V_8 = V_9 + V_10 ;
F_4 ( & V_3 -> V_7 ) ;
return 0 ;
V_96:
F_2 (i) {
struct V_32 * V_33 = F_3 ( V_3 -> V_5 , V_4 ) ;
F_89 ( V_33 -> V_67 ) ;
V_33 -> V_67 = NULL ;
}
F_90 ( V_3 -> V_5 ) ;
V_3 -> V_5 = NULL ;
return - V_91 ;
}
void F_91 ( struct V_58 * V_58 )
{
int V_4 ;
struct V_2 * V_3 = & V_58 -> V_14 . V_39 ;
F_92 ( & V_3 -> V_7 ) ;
F_93 ( V_95 , & V_3 -> V_92 ) ;
F_2 (i) {
struct V_32 * V_33 = F_3 ( V_3 -> V_5 , V_4 ) ;
F_89 ( V_33 -> V_67 ) ;
V_33 -> V_67 = NULL ;
}
F_90 ( V_3 -> V_5 ) ;
V_3 -> V_5 = NULL ;
}
void T_5 F_94 ( void )
{
int V_97 ;
V_97 = F_95 ( V_95 ,
L_3 ,
F_78 ,
F_80 ) ;
F_96 ( V_97 < 0 ) ;
}
