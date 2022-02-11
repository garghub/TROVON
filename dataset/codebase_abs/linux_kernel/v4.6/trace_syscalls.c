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
const char * F_8 ( int V_17 )
{
struct V_4 * V_5 ;
V_5 = F_7 ( V_17 ) ;
if ( ! V_5 )
return NULL ;
return V_5 -> V_9 ;
}
static enum V_18
F_9 ( struct V_19 * V_20 , int V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_20 -> V_25 ;
struct V_26 * V_27 = & V_20 -> V_28 ;
struct V_29 * V_30 = V_20 -> V_30 ;
struct V_31 * V_32 ;
struct V_4 * V_5 ;
int V_33 , V_17 ;
V_32 = ( F_10 ( V_32 ) ) V_30 ;
V_17 = V_32 -> V_14 ;
V_5 = F_7 ( V_17 ) ;
if ( ! V_5 )
goto V_34;
if ( V_5 -> V_35 -> V_23 . type != V_30 -> type ) {
F_11 ( 1 ) ;
goto V_34;
}
F_12 ( V_27 , L_1 , V_5 -> V_9 ) ;
for ( V_33 = 0 ; V_33 < V_5 -> V_36 ; V_33 ++ ) {
if ( F_13 ( V_27 ) )
goto V_34;
if ( V_25 -> V_37 & V_38 )
F_12 ( V_27 , L_2 , V_5 -> V_39 [ V_33 ] ) ;
F_12 ( V_27 , L_3 , V_5 -> args [ V_33 ] ,
V_32 -> args [ V_33 ] ,
V_33 == V_5 -> V_36 - 1 ? L_4 : L_5 ) ;
}
F_14 ( V_27 , ')' ) ;
V_34:
F_14 ( V_27 , '\n' ) ;
return F_15 ( V_27 ) ;
}
static enum V_18
F_16 ( struct V_19 * V_20 , int V_21 ,
struct V_22 * V_23 )
{
struct V_26 * V_27 = & V_20 -> V_28 ;
struct V_29 * V_30 = V_20 -> V_30 ;
struct V_40 * V_32 ;
int V_17 ;
struct V_4 * V_5 ;
V_32 = ( F_10 ( V_32 ) ) V_30 ;
V_17 = V_32 -> V_14 ;
V_5 = F_7 ( V_17 ) ;
if ( ! V_5 ) {
F_14 ( V_27 , '\n' ) ;
goto V_41;
}
if ( V_5 -> V_42 -> V_23 . type != V_30 -> type ) {
F_11 ( 1 ) ;
return V_43 ;
}
F_12 ( V_27 , L_6 , V_5 -> V_9 ,
V_32 -> V_44 ) ;
V_41:
return F_15 ( V_27 ) ;
}
static int T_1
F_17 ( struct V_4 * V_5 , char * V_45 , int V_46 )
{
int V_33 ;
int V_47 = 0 ;
#define F_18 (len ? len - pos : 0)
V_47 += snprintf ( V_45 + V_47 , F_18 , L_7 ) ;
for ( V_33 = 0 ; V_33 < V_5 -> V_36 ; V_33 ++ ) {
V_47 += snprintf ( V_45 + V_47 , F_18 , L_8 ,
V_5 -> args [ V_33 ] , sizeof( unsigned long ) ,
V_33 == V_5 -> V_36 - 1 ? L_4 : L_5 ) ;
}
V_47 += snprintf ( V_45 + V_47 , F_18 , L_7 ) ;
for ( V_33 = 0 ; V_33 < V_5 -> V_36 ; V_33 ++ ) {
V_47 += snprintf ( V_45 + V_47 , F_18 ,
L_9 , V_5 -> args [ V_33 ] ) ;
}
#undef F_18
return V_47 ;
}
static int T_1 F_19 ( struct V_2 * V_3 )
{
char * V_48 ;
int V_46 ;
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_35 != V_3 ) {
V_3 -> V_48 = L_10 ;
return 0 ;
}
V_46 = F_17 ( V_5 , NULL , 0 ) ;
V_48 = F_20 ( V_46 + 1 , V_49 ) ;
if ( ! V_48 )
return - V_50 ;
F_17 ( V_5 , V_48 , V_46 + 1 ) ;
V_3 -> V_48 = V_48 ;
return 0 ;
}
static void T_1 F_21 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_35 == V_3 )
F_22 ( V_3 -> V_48 ) ;
}
static int T_1 F_23 ( struct V_2 * V_3 )
{
struct V_31 V_32 ;
struct V_4 * V_51 = V_3 -> V_6 ;
int V_44 ;
int V_33 ;
int V_52 = F_24 ( F_10 ( V_32 ) , args ) ;
V_44 = F_25 ( V_3 , F_26 ( int , V_14 , V_53 ) ,
V_54 ) ;
if ( V_44 )
return V_44 ;
for ( V_33 = 0 ; V_33 < V_51 -> V_36 ; V_33 ++ ) {
V_44 = F_25 ( V_3 , V_51 -> V_39 [ V_33 ] ,
V_51 -> args [ V_33 ] , V_52 ,
sizeof( unsigned long ) , 0 ,
V_54 ) ;
V_52 += sizeof( unsigned long ) ;
}
return V_44 ;
}
static int T_1 F_27 ( struct V_2 * V_3 )
{
struct V_40 V_32 ;
int V_44 ;
V_44 = F_25 ( V_3 , F_26 ( int , V_14 , V_53 ) ,
V_54 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_25 ( V_3 , F_26 ( long , V_44 , V_44 ) ,
V_54 ) ;
return V_44 ;
}
static void F_28 ( void * V_6 , struct V_12 * V_13 , long V_55 )
{
struct V_24 * V_25 = V_6 ;
struct V_56 * V_57 ;
struct V_31 * V_5 ;
struct V_4 * V_58 ;
struct V_59 * V_23 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
int V_63 ;
int V_64 ;
int V_65 ;
V_64 = F_3 ( V_66 , V_13 ) ;
if ( V_64 < 0 || V_64 >= V_16 )
return;
V_57 = F_29 ( V_25 -> V_67 [ V_64 ] ) ;
if ( ! V_57 )
return;
if ( F_30 ( V_57 ) )
return;
V_58 = F_7 ( V_64 ) ;
if ( ! V_58 )
return;
V_65 = sizeof( * V_5 ) + sizeof( unsigned long ) * V_58 -> V_36 ;
F_31 ( V_62 ) ;
V_63 = F_32 () ;
V_61 = V_25 -> V_68 . V_61 ;
V_23 = F_33 ( V_61 ,
V_58 -> V_35 -> V_23 . type , V_65 , V_62 , V_63 ) ;
if ( ! V_23 )
return;
V_5 = F_34 ( V_23 ) ;
V_5 -> V_14 = V_64 ;
F_35 ( V_66 , V_13 , 0 , V_58 -> V_36 , V_5 -> args ) ;
F_36 ( V_57 , V_61 , V_23 , V_5 ,
V_62 , V_63 ) ;
}
static void F_37 ( void * V_6 , struct V_12 * V_13 , long V_44 )
{
struct V_24 * V_25 = V_6 ;
struct V_56 * V_57 ;
struct V_40 * V_5 ;
struct V_4 * V_58 ;
struct V_59 * V_23 ;
struct V_60 * V_61 ;
unsigned long V_62 ;
int V_63 ;
int V_64 ;
V_64 = F_3 ( V_66 , V_13 ) ;
if ( V_64 < 0 || V_64 >= V_16 )
return;
V_57 = F_29 ( V_25 -> V_69 [ V_64 ] ) ;
if ( ! V_57 )
return;
if ( F_30 ( V_57 ) )
return;
V_58 = F_7 ( V_64 ) ;
if ( ! V_58 )
return;
F_31 ( V_62 ) ;
V_63 = F_32 () ;
V_61 = V_25 -> V_68 . V_61 ;
V_23 = F_33 ( V_61 ,
V_58 -> V_42 -> V_23 . type , sizeof( * V_5 ) ,
V_62 , V_63 ) ;
if ( ! V_23 )
return;
V_5 = F_34 ( V_23 ) ;
V_5 -> V_14 = V_64 ;
V_5 -> V_44 = F_38 ( V_66 , V_13 ) ;
F_36 ( V_57 , V_61 , V_23 , V_5 ,
V_62 , V_63 ) ;
}
static int F_39 ( struct V_56 * V_70 ,
struct V_2 * V_3 )
{
struct V_24 * V_25 = V_70 -> V_25 ;
int V_44 = 0 ;
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( F_11 ( V_71 < 0 || V_71 >= V_16 ) )
return - V_72 ;
F_40 ( & V_73 ) ;
if ( ! V_25 -> V_74 )
V_44 = F_41 ( F_28 , V_25 ) ;
if ( ! V_44 ) {
F_42 ( V_25 -> V_67 [ V_71 ] , V_70 ) ;
V_25 -> V_74 ++ ;
}
F_43 ( & V_73 ) ;
return V_44 ;
}
static void F_44 ( struct V_56 * V_70 ,
struct V_2 * V_3 )
{
struct V_24 * V_25 = V_70 -> V_25 ;
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( F_11 ( V_71 < 0 || V_71 >= V_16 ) )
return;
F_40 ( & V_73 ) ;
V_25 -> V_74 -- ;
F_45 ( V_25 -> V_67 [ V_71 ] , NULL ) ;
if ( ! V_25 -> V_74 )
F_46 ( F_28 , V_25 ) ;
F_43 ( & V_73 ) ;
}
static int F_47 ( struct V_56 * V_70 ,
struct V_2 * V_3 )
{
struct V_24 * V_25 = V_70 -> V_25 ;
int V_44 = 0 ;
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( F_11 ( V_71 < 0 || V_71 >= V_16 ) )
return - V_72 ;
F_40 ( & V_73 ) ;
if ( ! V_25 -> V_75 )
V_44 = F_48 ( F_37 , V_25 ) ;
if ( ! V_44 ) {
F_42 ( V_25 -> V_69 [ V_71 ] , V_70 ) ;
V_25 -> V_75 ++ ;
}
F_43 ( & V_73 ) ;
return V_44 ;
}
static void F_49 ( struct V_56 * V_70 ,
struct V_2 * V_3 )
{
struct V_24 * V_25 = V_70 -> V_25 ;
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( F_11 ( V_71 < 0 || V_71 >= V_16 ) )
return;
F_40 ( & V_73 ) ;
V_25 -> V_75 -- ;
F_45 ( V_25 -> V_69 [ V_71 ] , NULL ) ;
if ( ! V_25 -> V_75 )
F_50 ( F_37 , V_25 ) ;
F_43 ( & V_73 ) ;
}
static int T_1 F_51 ( struct V_2 * V_3 )
{
int V_55 ;
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
if ( V_71 < 0 || V_71 >= V_16 ) {
F_52 ( L_11 ,
( (struct V_4 * ) V_3 -> V_6 ) -> V_9 ) ;
return - V_72 ;
}
if ( F_19 ( V_3 ) < 0 )
return - V_50 ;
V_55 = F_53 ( V_3 ) ;
if ( V_55 < 0 ) {
F_21 ( V_3 ) ;
return V_55 ;
}
return V_55 ;
}
unsigned long T_1 __weak F_54 ( int V_14 )
{
return ( unsigned long ) V_76 [ V_14 ] ;
}
void T_1 F_55 ( void )
{
struct V_4 * V_51 ;
unsigned long V_77 ;
int V_33 ;
V_15 = F_56 ( V_16 , sizeof( * V_15 ) ,
V_49 ) ;
if ( ! V_15 ) {
F_57 ( 1 ) ;
return;
}
for ( V_33 = 0 ; V_33 < V_16 ; V_33 ++ ) {
V_77 = F_54 ( V_33 ) ;
V_51 = F_58 ( V_77 ) ;
if ( ! V_51 )
continue;
V_51 -> V_64 = V_33 ;
V_15 [ V_33 ] = V_51 ;
}
}
static void F_59 ( void * V_78 , struct V_12 * V_13 , long V_55 )
{
struct V_4 * V_58 ;
struct V_31 * V_79 ;
struct V_80 * V_81 ;
int V_64 ;
int V_82 ;
int V_65 ;
V_64 = F_3 ( V_66 , V_13 ) ;
if ( V_64 < 0 || V_64 >= V_16 )
return;
if ( ! F_60 ( V_64 , V_83 ) )
return;
V_58 = F_7 ( V_64 ) ;
if ( ! V_58 )
return;
V_81 = F_61 ( V_58 -> V_35 -> V_84 ) ;
if ( F_62 ( V_81 ) )
return;
V_65 = sizeof( unsigned long ) * V_58 -> V_36 + sizeof( * V_79 ) ;
V_65 = F_63 ( V_65 + sizeof( V_85 ) , sizeof( V_86 ) ) ;
V_65 -= sizeof( V_85 ) ;
V_79 = (struct V_31 * ) F_64 ( V_65 ,
V_58 -> V_35 -> V_23 . type , NULL , & V_82 ) ;
if ( ! V_79 )
return;
V_79 -> V_14 = V_64 ;
F_35 ( V_66 , V_13 , 0 , V_58 -> V_36 ,
( unsigned long * ) & V_79 -> args ) ;
F_65 ( V_79 , V_65 , V_82 , 0 , 1 , V_13 , V_81 , NULL ) ;
}
static int F_66 ( struct V_2 * V_3 )
{
int V_44 = 0 ;
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
F_40 ( & V_73 ) ;
if ( ! V_87 )
V_44 = F_41 ( F_59 , NULL ) ;
if ( V_44 ) {
F_67 ( L_12
L_13 ) ;
} else {
F_68 ( V_71 , V_83 ) ;
V_87 ++ ;
}
F_43 ( & V_73 ) ;
return V_44 ;
}
static void F_69 ( struct V_2 * V_3 )
{
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
F_40 ( & V_73 ) ;
V_87 -- ;
F_70 ( V_71 , V_83 ) ;
if ( ! V_87 )
F_46 ( F_59 , NULL ) ;
F_43 ( & V_73 ) ;
}
static void F_71 ( void * V_78 , struct V_12 * V_13 , long V_44 )
{
struct V_4 * V_58 ;
struct V_40 * V_79 ;
struct V_80 * V_81 ;
int V_64 ;
int V_82 ;
int V_65 ;
V_64 = F_3 ( V_66 , V_13 ) ;
if ( V_64 < 0 || V_64 >= V_16 )
return;
if ( ! F_60 ( V_64 , V_88 ) )
return;
V_58 = F_7 ( V_64 ) ;
if ( ! V_58 )
return;
V_81 = F_61 ( V_58 -> V_42 -> V_84 ) ;
if ( F_62 ( V_81 ) )
return;
V_65 = F_63 ( sizeof( * V_79 ) + sizeof( V_85 ) , sizeof( V_86 ) ) ;
V_65 -= sizeof( V_85 ) ;
V_79 = (struct V_40 * ) F_64 ( V_65 ,
V_58 -> V_42 -> V_23 . type , NULL , & V_82 ) ;
if ( ! V_79 )
return;
V_79 -> V_14 = V_64 ;
V_79 -> V_44 = F_38 ( V_66 , V_13 ) ;
F_65 ( V_79 , V_65 , V_82 , 0 , 1 , V_13 , V_81 , NULL ) ;
}
static int F_72 ( struct V_2 * V_3 )
{
int V_44 = 0 ;
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
F_40 ( & V_73 ) ;
if ( ! V_89 )
V_44 = F_48 ( F_71 , NULL ) ;
if ( V_44 ) {
F_67 ( L_12
L_14 ) ;
} else {
F_68 ( V_71 , V_88 ) ;
V_89 ++ ;
}
F_43 ( & V_73 ) ;
return V_44 ;
}
static void F_73 ( struct V_2 * V_3 )
{
int V_71 ;
V_71 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_64 ;
F_40 ( & V_73 ) ;
V_89 -- ;
F_70 ( V_71 , V_88 ) ;
if ( ! V_89 )
F_50 ( F_71 , NULL ) ;
F_43 ( & V_73 ) ;
}
static int F_74 ( struct V_2 * V_23 ,
enum V_90 type , void * V_6 )
{
struct V_56 * V_70 = V_6 ;
switch ( type ) {
case V_91 :
return F_39 ( V_70 , V_23 ) ;
case V_92 :
F_44 ( V_70 , V_23 ) ;
return 0 ;
#ifdef F_75
case V_93 :
return F_66 ( V_23 ) ;
case V_94 :
F_69 ( V_23 ) ;
return 0 ;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
return 0 ;
#endif
}
return 0 ;
}
static int F_76 ( struct V_2 * V_23 ,
enum V_90 type , void * V_6 )
{
struct V_56 * V_70 = V_6 ;
switch ( type ) {
case V_91 :
return F_47 ( V_70 , V_23 ) ;
case V_92 :
F_49 ( V_70 , V_23 ) ;
return 0 ;
#ifdef F_75
case V_93 :
return F_72 ( V_23 ) ;
case V_94 :
F_73 ( V_23 ) ;
return 0 ;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
return 0 ;
#endif
}
return 0 ;
}
