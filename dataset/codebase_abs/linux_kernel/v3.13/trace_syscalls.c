static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
return & V_5 -> V_7 ;
}
static inline bool F_2 ( const char * V_8 , const char * V_9 )
{
return ! strcmp ( V_8 + 3 , V_9 + 3 ) ;
}
static int
F_3 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
if ( F_4 ( F_5 ( V_13 ) ) )
return - 1 ;
return F_6 ( V_11 , V_13 ) ;
}
static inline int
F_3 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
return F_6 ( V_11 , V_13 ) ;
}
struct V_4 * F_7 ( int V_14 )
{
if ( ! V_15 || V_14 >= V_16 || V_14 < 0 )
return NULL ;
return V_15 [ V_14 ] ;
}
static enum V_17
F_8 ( struct V_18 * V_19 , int V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_19 -> V_25 ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_28 * V_29 ;
struct V_4 * V_5 ;
int V_30 , V_31 , V_32 ;
V_29 = ( F_9 ( V_29 ) ) V_27 ;
V_32 = V_29 -> V_14 ;
V_5 = F_7 ( V_32 ) ;
if ( ! V_5 )
goto V_33;
if ( V_5 -> V_34 -> V_22 . type != V_27 -> type ) {
F_10 ( 1 ) ;
goto V_33;
}
V_31 = F_11 ( V_24 , L_1 , V_5 -> V_9 ) ;
if ( ! V_31 )
return V_35 ;
for ( V_30 = 0 ; V_30 < V_5 -> V_36 ; V_30 ++ ) {
if ( V_37 & V_38 ) {
V_31 = F_11 ( V_24 , L_2 , V_5 -> V_39 [ V_30 ] ) ;
if ( ! V_31 )
return V_35 ;
}
V_31 = F_11 ( V_24 , L_3 , V_5 -> args [ V_30 ] ,
V_29 -> args [ V_30 ] ,
V_30 == V_5 -> V_36 - 1 ? L_4 : L_5 ) ;
if ( ! V_31 )
return V_35 ;
}
V_31 = F_12 ( V_24 , ')' ) ;
if ( ! V_31 )
return V_35 ;
V_33:
V_31 = F_12 ( V_24 , '\n' ) ;
if ( ! V_31 )
return V_35 ;
return V_40 ;
}
static enum V_17
F_13 ( struct V_18 * V_19 , int V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_19 -> V_25 ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_41 * V_29 ;
int V_32 ;
struct V_4 * V_5 ;
int V_31 ;
V_29 = ( F_9 ( V_29 ) ) V_27 ;
V_32 = V_29 -> V_14 ;
V_5 = F_7 ( V_32 ) ;
if ( ! V_5 ) {
F_12 ( V_24 , '\n' ) ;
return V_40 ;
}
if ( V_5 -> V_42 -> V_22 . type != V_27 -> type ) {
F_10 ( 1 ) ;
return V_43 ;
}
V_31 = F_11 ( V_24 , L_6 , V_5 -> V_9 ,
V_29 -> V_31 ) ;
if ( ! V_31 )
return V_35 ;
return V_40 ;
}
static int T_1
F_14 ( struct V_4 * V_5 , char * V_44 , int V_45 )
{
int V_30 ;
int V_46 = 0 ;
#define F_15 (len ? len - pos : 0)
V_46 += snprintf ( V_44 + V_46 , F_15 , L_7 ) ;
for ( V_30 = 0 ; V_30 < V_5 -> V_36 ; V_30 ++ ) {
V_46 += snprintf ( V_44 + V_46 , F_15 , L_8 ,
V_5 -> args [ V_30 ] , sizeof( unsigned long ) ,
V_30 == V_5 -> V_36 - 1 ? L_4 : L_5 ) ;
}
V_46 += snprintf ( V_44 + V_46 , F_15 , L_7 ) ;
for ( V_30 = 0 ; V_30 < V_5 -> V_36 ; V_30 ++ ) {
V_46 += snprintf ( V_44 + V_46 , F_15 ,
L_9 , V_5 -> args [ V_30 ] ) ;
}
#undef F_15
return V_46 ;
}
static int T_1 F_16 ( struct V_2 * V_3 )
{
char * V_47 ;
int V_45 ;
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_34 != V_3 ) {
V_3 -> V_47 = L_10 ;
return 0 ;
}
V_45 = F_14 ( V_5 , NULL , 0 ) ;
V_47 = F_17 ( V_45 + 1 , V_48 ) ;
if ( ! V_47 )
return - V_49 ;
F_14 ( V_5 , V_47 , V_45 + 1 ) ;
V_3 -> V_47 = V_47 ;
return 0 ;
}
static void T_1 F_18 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_34 == V_3 )
F_19 ( V_3 -> V_47 ) ;
}
static int T_1 F_20 ( struct V_2 * V_3 )
{
struct V_28 V_29 ;
struct V_4 * V_50 = V_3 -> V_6 ;
int V_31 ;
int V_30 ;
int V_51 = F_21 ( F_9 ( V_29 ) , args ) ;
V_31 = F_22 ( V_3 , F_23 ( int , V_14 ) , V_52 ) ;
if ( V_31 )
return V_31 ;
for ( V_30 = 0 ; V_30 < V_50 -> V_36 ; V_30 ++ ) {
V_31 = F_22 ( V_3 , V_50 -> V_39 [ V_30 ] ,
V_50 -> args [ V_30 ] , V_51 ,
sizeof( unsigned long ) , 0 ,
V_52 ) ;
V_51 += sizeof( unsigned long ) ;
}
return V_31 ;
}
static int T_1 F_24 ( struct V_2 * V_3 )
{
struct V_41 V_29 ;
int V_31 ;
V_31 = F_22 ( V_3 , F_23 ( int , V_14 ) , V_52 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_22 ( V_3 , F_23 ( long , V_31 ) ,
V_52 ) ;
return V_31 ;
}
static void F_25 ( void * V_6 , struct V_12 * V_13 , long V_53 )
{
struct V_54 * V_55 = V_6 ;
struct V_56 * V_57 ;
struct V_28 * V_5 ;
struct V_4 * V_58 ;
struct V_59 * V_22 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
int V_63 ;
int V_64 ;
int V_65 ;
V_64 = F_3 ( V_66 , V_13 ) ;
if ( V_64 < 0 )
return;
V_57 = F_26 ( V_55 -> V_67 [ V_64 ] ) ;
if ( ! V_57 )
return;
if ( F_27 ( V_68 , & V_57 -> V_20 ) )
return;
V_58 = F_7 ( V_64 ) ;
if ( ! V_58 )
return;
V_65 = sizeof( * V_5 ) + sizeof( unsigned long ) * V_58 -> V_36 ;
F_28 ( V_62 ) ;
V_63 = F_29 () ;
V_61 = V_55 -> V_69 . V_61 ;
V_22 = F_30 ( V_61 ,
V_58 -> V_34 -> V_22 . type , V_65 , V_62 , V_63 ) ;
if ( ! V_22 )
return;
V_5 = F_31 ( V_22 ) ;
V_5 -> V_14 = V_64 ;
F_32 ( V_66 , V_13 , 0 , V_58 -> V_36 , V_5 -> args ) ;
if ( ! F_33 ( V_57 , V_5 , V_61 , V_22 ) )
F_34 ( V_61 , V_22 ,
V_62 , V_63 ) ;
}
static void F_35 ( void * V_6 , struct V_12 * V_13 , long V_31 )
{
struct V_54 * V_55 = V_6 ;
struct V_56 * V_57 ;
struct V_41 * V_5 ;
struct V_4 * V_58 ;
struct V_59 * V_22 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
int V_63 ;
int V_64 ;
V_64 = F_3 ( V_66 , V_13 ) ;
if ( V_64 < 0 )
return;
V_57 = F_26 ( V_55 -> V_70 [ V_64 ] ) ;
if ( ! V_57 )
return;
if ( F_27 ( V_68 , & V_57 -> V_20 ) )
return;
V_58 = F_7 ( V_64 ) ;
if ( ! V_58 )
return;
F_28 ( V_62 ) ;
V_63 = F_29 () ;
V_61 = V_55 -> V_69 . V_61 ;
V_22 = F_30 ( V_61 ,
V_58 -> V_42 -> V_22 . type , sizeof( * V_5 ) ,
V_62 , V_63 ) ;
if ( ! V_22 )
return;
V_5 = F_31 ( V_22 ) ;
V_5 -> V_14 = V_64 ;
V_5 -> V_31 = F_36 ( V_66 , V_13 ) ;
if ( ! F_33 ( V_57 , V_5 , V_61 , V_22 ) )
F_34 ( V_61 , V_22 ,
V_62 , V_63 ) ;
}
static int F_37 ( struct V_56 * V_71 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 = V_71 -> V_55 ;
int V_31 = 0 ;
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( F_10 ( V_72 < 0 || V_72 >= V_16 ) )
return - V_73 ;
F_38 ( & V_74 ) ;
if ( ! V_55 -> V_75 )
V_31 = F_39 ( F_25 , V_55 ) ;
if ( ! V_31 ) {
F_40 ( V_55 -> V_67 [ V_72 ] , V_71 ) ;
V_55 -> V_75 ++ ;
}
F_41 ( & V_74 ) ;
return V_31 ;
}
static void F_42 ( struct V_56 * V_71 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 = V_71 -> V_55 ;
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( F_10 ( V_72 < 0 || V_72 >= V_16 ) )
return;
F_38 ( & V_74 ) ;
V_55 -> V_75 -- ;
F_40 ( V_55 -> V_67 [ V_72 ] , NULL ) ;
if ( ! V_55 -> V_75 )
F_43 ( F_25 , V_55 ) ;
F_41 ( & V_74 ) ;
}
static int F_44 ( struct V_56 * V_71 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 = V_71 -> V_55 ;
int V_31 = 0 ;
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( F_10 ( V_72 < 0 || V_72 >= V_16 ) )
return - V_73 ;
F_38 ( & V_74 ) ;
if ( ! V_55 -> V_76 )
V_31 = F_45 ( F_35 , V_55 ) ;
if ( ! V_31 ) {
F_40 ( V_55 -> V_70 [ V_72 ] , V_71 ) ;
V_55 -> V_76 ++ ;
}
F_41 ( & V_74 ) ;
return V_31 ;
}
static void F_46 ( struct V_56 * V_71 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 = V_71 -> V_55 ;
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( F_10 ( V_72 < 0 || V_72 >= V_16 ) )
return;
F_38 ( & V_74 ) ;
V_55 -> V_76 -- ;
F_40 ( V_55 -> V_70 [ V_72 ] , NULL ) ;
if ( ! V_55 -> V_76 )
F_47 ( F_35 , V_55 ) ;
F_41 ( & V_74 ) ;
}
static int T_1 F_48 ( struct V_2 * V_3 )
{
int V_53 ;
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( V_72 < 0 || V_72 >= V_16 ) {
F_49 ( L_11 ,
( (struct V_4 * ) V_3 -> V_6 ) -> V_9 ) ;
return - V_73 ;
}
if ( F_16 ( V_3 ) < 0 )
return - V_49 ;
V_53 = F_50 ( V_3 ) ;
if ( V_53 < 0 ) {
F_18 ( V_3 ) ;
return V_53 ;
}
return V_53 ;
}
unsigned long T_1 __weak F_51 ( int V_14 )
{
return ( unsigned long ) V_77 [ V_14 ] ;
}
static int T_1 F_52 ( void )
{
struct V_4 * V_50 ;
unsigned long V_78 ;
int V_30 ;
V_15 = F_53 ( V_16 , sizeof( * V_15 ) ,
V_48 ) ;
if ( ! V_15 ) {
F_54 ( 1 ) ;
return - V_49 ;
}
for ( V_30 = 0 ; V_30 < V_16 ; V_30 ++ ) {
V_78 = F_51 ( V_30 ) ;
V_50 = F_55 ( V_78 ) ;
if ( ! V_50 )
continue;
V_50 -> V_64 = V_30 ;
V_15 [ V_30 ] = V_50 ;
}
return 0 ;
}
static void F_56 ( void * V_79 , struct V_12 * V_13 , long V_53 )
{
struct V_4 * V_58 ;
struct V_28 * V_80 ;
struct V_81 * V_82 ;
int V_64 ;
int V_83 ;
int V_65 ;
V_64 = F_3 ( V_66 , V_13 ) ;
if ( V_64 < 0 )
return;
if ( ! F_27 ( V_64 , V_84 ) )
return;
V_58 = F_7 ( V_64 ) ;
if ( ! V_58 )
return;
V_82 = F_57 ( V_58 -> V_34 -> V_85 ) ;
if ( F_58 ( V_82 ) )
return;
V_65 = sizeof( unsigned long ) * V_58 -> V_36 + sizeof( * V_80 ) ;
V_65 = F_59 ( V_65 + sizeof( V_86 ) , sizeof( V_87 ) ) ;
V_65 -= sizeof( V_86 ) ;
V_80 = (struct V_28 * ) F_60 ( V_65 ,
V_58 -> V_34 -> V_22 . type , V_13 , & V_83 ) ;
if ( ! V_80 )
return;
V_80 -> V_14 = V_64 ;
F_32 ( V_66 , V_13 , 0 , V_58 -> V_36 ,
( unsigned long * ) & V_80 -> args ) ;
F_61 ( V_80 , V_65 , V_83 , 0 , 1 , V_13 , V_82 , NULL ) ;
}
static int F_62 ( struct V_2 * V_3 )
{
int V_31 = 0 ;
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
F_38 ( & V_74 ) ;
if ( ! V_88 )
V_31 = F_39 ( F_56 , NULL ) ;
if ( V_31 ) {
F_63 ( L_12
L_13 ) ;
} else {
F_64 ( V_72 , V_84 ) ;
V_88 ++ ;
}
F_41 ( & V_74 ) ;
return V_31 ;
}
static void F_65 ( struct V_2 * V_3 )
{
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
F_38 ( & V_74 ) ;
V_88 -- ;
F_66 ( V_72 , V_84 ) ;
if ( ! V_88 )
F_43 ( F_56 , NULL ) ;
F_41 ( & V_74 ) ;
}
static void F_67 ( void * V_79 , struct V_12 * V_13 , long V_31 )
{
struct V_4 * V_58 ;
struct V_41 * V_80 ;
struct V_81 * V_82 ;
int V_64 ;
int V_83 ;
int V_65 ;
V_64 = F_3 ( V_66 , V_13 ) ;
if ( V_64 < 0 )
return;
if ( ! F_27 ( V_64 , V_89 ) )
return;
V_58 = F_7 ( V_64 ) ;
if ( ! V_58 )
return;
V_82 = F_57 ( V_58 -> V_42 -> V_85 ) ;
if ( F_58 ( V_82 ) )
return;
V_65 = F_59 ( sizeof( * V_80 ) + sizeof( V_86 ) , sizeof( V_87 ) ) ;
V_65 -= sizeof( V_86 ) ;
V_80 = (struct V_41 * ) F_60 ( V_65 ,
V_58 -> V_42 -> V_22 . type , V_13 , & V_83 ) ;
if ( ! V_80 )
return;
V_80 -> V_14 = V_64 ;
V_80 -> V_31 = F_36 ( V_66 , V_13 ) ;
F_61 ( V_80 , V_65 , V_83 , 0 , 1 , V_13 , V_82 , NULL ) ;
}
static int F_68 ( struct V_2 * V_3 )
{
int V_31 = 0 ;
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
F_38 ( & V_74 ) ;
if ( ! V_90 )
V_31 = F_45 ( F_67 , NULL ) ;
if ( V_31 ) {
F_63 ( L_12
L_14 ) ;
} else {
F_64 ( V_72 , V_89 ) ;
V_90 ++ ;
}
F_41 ( & V_74 ) ;
return V_31 ;
}
static void F_69 ( struct V_2 * V_3 )
{
int V_72 ;
V_72 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
F_38 ( & V_74 ) ;
V_90 -- ;
F_66 ( V_72 , V_89 ) ;
if ( ! V_90 )
F_47 ( F_67 , NULL ) ;
F_41 ( & V_74 ) ;
}
static int F_70 ( struct V_2 * V_22 ,
enum V_91 type , void * V_6 )
{
struct V_56 * V_71 = V_6 ;
switch ( type ) {
case V_92 :
return F_37 ( V_71 , V_22 ) ;
case V_93 :
F_42 ( V_71 , V_22 ) ;
return 0 ;
#ifdef F_71
case V_94 :
return F_62 ( V_22 ) ;
case V_95 :
F_65 ( V_22 ) ;
return 0 ;
case V_96 :
case V_97 :
case V_98 :
case V_99 :
return 0 ;
#endif
}
return 0 ;
}
static int F_72 ( struct V_2 * V_22 ,
enum V_91 type , void * V_6 )
{
struct V_56 * V_71 = V_6 ;
switch ( type ) {
case V_92 :
return F_44 ( V_71 , V_22 ) ;
case V_93 :
F_46 ( V_71 , V_22 ) ;
return 0 ;
#ifdef F_71
case V_94 :
return F_68 ( V_22 ) ;
case V_95 :
F_69 ( V_22 ) ;
return 0 ;
case V_96 :
case V_97 :
case V_98 :
case V_99 :
return 0 ;
#endif
}
return 0 ;
}
