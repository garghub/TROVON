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
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_25 * V_26 = & V_19 -> V_27 ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_30 * V_31 ;
struct V_4 * V_5 ;
int V_32 , V_33 ;
V_31 = ( F_9 ( V_31 ) ) V_29 ;
V_33 = V_31 -> V_14 ;
V_5 = F_7 ( V_33 ) ;
if ( ! V_5 )
goto V_34;
if ( V_5 -> V_35 -> V_22 . type != V_29 -> type ) {
F_10 ( 1 ) ;
goto V_34;
}
F_11 ( V_26 , L_1 , V_5 -> V_9 ) ;
for ( V_32 = 0 ; V_32 < V_5 -> V_36 ; V_32 ++ ) {
if ( F_12 ( V_26 ) )
goto V_34;
if ( V_24 -> V_37 & V_38 )
F_11 ( V_26 , L_2 , V_5 -> V_39 [ V_32 ] ) ;
F_11 ( V_26 , L_3 , V_5 -> args [ V_32 ] ,
V_31 -> args [ V_32 ] ,
V_32 == V_5 -> V_36 - 1 ? L_4 : L_5 ) ;
}
F_13 ( V_26 , ')' ) ;
V_34:
F_13 ( V_26 , '\n' ) ;
return F_14 ( V_26 ) ;
}
static enum V_17
F_15 ( struct V_18 * V_19 , int V_20 ,
struct V_21 * V_22 )
{
struct V_25 * V_26 = & V_19 -> V_27 ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_40 * V_31 ;
int V_33 ;
struct V_4 * V_5 ;
V_31 = ( F_9 ( V_31 ) ) V_29 ;
V_33 = V_31 -> V_14 ;
V_5 = F_7 ( V_33 ) ;
if ( ! V_5 ) {
F_13 ( V_26 , '\n' ) ;
goto V_41;
}
if ( V_5 -> V_42 -> V_22 . type != V_29 -> type ) {
F_10 ( 1 ) ;
return V_43 ;
}
F_11 ( V_26 , L_6 , V_5 -> V_9 ,
V_31 -> V_44 ) ;
V_41:
return F_14 ( V_26 ) ;
}
static int T_1
F_16 ( struct V_4 * V_5 , char * V_45 , int V_46 )
{
int V_32 ;
int V_47 = 0 ;
#define F_17 (len ? len - pos : 0)
V_47 += snprintf ( V_45 + V_47 , F_17 , L_7 ) ;
for ( V_32 = 0 ; V_32 < V_5 -> V_36 ; V_32 ++ ) {
V_47 += snprintf ( V_45 + V_47 , F_17 , L_8 ,
V_5 -> args [ V_32 ] , sizeof( unsigned long ) ,
V_32 == V_5 -> V_36 - 1 ? L_4 : L_5 ) ;
}
V_47 += snprintf ( V_45 + V_47 , F_17 , L_7 ) ;
for ( V_32 = 0 ; V_32 < V_5 -> V_36 ; V_32 ++ ) {
V_47 += snprintf ( V_45 + V_47 , F_17 ,
L_9 , V_5 -> args [ V_32 ] ) ;
}
#undef F_17
return V_47 ;
}
static int T_1 F_18 ( struct V_2 * V_3 )
{
char * V_48 ;
int V_46 ;
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_35 != V_3 ) {
V_3 -> V_48 = L_10 ;
return 0 ;
}
V_46 = F_16 ( V_5 , NULL , 0 ) ;
V_48 = F_19 ( V_46 + 1 , V_49 ) ;
if ( ! V_48 )
return - V_50 ;
F_16 ( V_5 , V_48 , V_46 + 1 ) ;
V_3 -> V_48 = V_48 ;
return 0 ;
}
static void T_1 F_20 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_35 == V_3 )
F_21 ( V_3 -> V_48 ) ;
}
static int T_1 F_22 ( struct V_2 * V_3 )
{
struct V_30 V_31 ;
struct V_4 * V_51 = V_3 -> V_6 ;
int V_44 ;
int V_32 ;
int V_52 = F_23 ( F_9 ( V_31 ) , args ) ;
V_44 = F_24 ( V_3 , F_25 ( int , V_14 ) , V_53 ) ;
if ( V_44 )
return V_44 ;
for ( V_32 = 0 ; V_32 < V_51 -> V_36 ; V_32 ++ ) {
V_44 = F_24 ( V_3 , V_51 -> V_39 [ V_32 ] ,
V_51 -> args [ V_32 ] , V_52 ,
sizeof( unsigned long ) , 0 ,
V_53 ) ;
V_52 += sizeof( unsigned long ) ;
}
return V_44 ;
}
static int T_1 F_26 ( struct V_2 * V_3 )
{
struct V_40 V_31 ;
int V_44 ;
V_44 = F_24 ( V_3 , F_25 ( int , V_14 ) , V_53 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_24 ( V_3 , F_25 ( long , V_44 ) ,
V_53 ) ;
return V_44 ;
}
static void F_27 ( void * V_6 , struct V_12 * V_13 , long V_54 )
{
struct V_23 * V_24 = V_6 ;
struct V_55 * V_56 ;
struct V_30 * V_5 ;
struct V_4 * V_57 ;
struct V_58 * V_22 ;
struct V_59 * V_60 ;
unsigned long V_61 ;
int V_62 ;
int V_63 ;
int V_64 ;
V_63 = F_3 ( V_65 , V_13 ) ;
if ( V_63 < 0 || V_63 >= V_16 )
return;
V_56 = F_28 ( V_24 -> V_66 [ V_63 ] ) ;
if ( ! V_56 )
return;
if ( F_29 ( V_56 ) )
return;
V_57 = F_7 ( V_63 ) ;
if ( ! V_57 )
return;
V_64 = sizeof( * V_5 ) + sizeof( unsigned long ) * V_57 -> V_36 ;
F_30 ( V_61 ) ;
V_62 = F_31 () ;
V_60 = V_24 -> V_67 . V_60 ;
V_22 = F_32 ( V_60 ,
V_57 -> V_35 -> V_22 . type , V_64 , V_61 , V_62 ) ;
if ( ! V_22 )
return;
V_5 = F_33 ( V_22 ) ;
V_5 -> V_14 = V_63 ;
F_34 ( V_65 , V_13 , 0 , V_57 -> V_36 , V_5 -> args ) ;
F_35 ( V_56 , V_60 , V_22 , V_5 ,
V_61 , V_62 ) ;
}
static void F_36 ( void * V_6 , struct V_12 * V_13 , long V_44 )
{
struct V_23 * V_24 = V_6 ;
struct V_55 * V_56 ;
struct V_40 * V_5 ;
struct V_4 * V_57 ;
struct V_58 * V_22 ;
struct V_59 * V_60 ;
unsigned long V_61 ;
int V_62 ;
int V_63 ;
V_63 = F_3 ( V_65 , V_13 ) ;
if ( V_63 < 0 || V_63 >= V_16 )
return;
V_56 = F_28 ( V_24 -> V_68 [ V_63 ] ) ;
if ( ! V_56 )
return;
if ( F_29 ( V_56 ) )
return;
V_57 = F_7 ( V_63 ) ;
if ( ! V_57 )
return;
F_30 ( V_61 ) ;
V_62 = F_31 () ;
V_60 = V_24 -> V_67 . V_60 ;
V_22 = F_32 ( V_60 ,
V_57 -> V_42 -> V_22 . type , sizeof( * V_5 ) ,
V_61 , V_62 ) ;
if ( ! V_22 )
return;
V_5 = F_33 ( V_22 ) ;
V_5 -> V_14 = V_63 ;
V_5 -> V_44 = F_37 ( V_65 , V_13 ) ;
F_35 ( V_56 , V_60 , V_22 , V_5 ,
V_61 , V_62 ) ;
}
static int F_38 ( struct V_55 * V_69 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = V_69 -> V_24 ;
int V_44 = 0 ;
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
if ( F_10 ( V_70 < 0 || V_70 >= V_16 ) )
return - V_71 ;
F_39 ( & V_72 ) ;
if ( ! V_24 -> V_73 )
V_44 = F_40 ( F_27 , V_24 ) ;
if ( ! V_44 ) {
F_41 ( V_24 -> V_66 [ V_70 ] , V_69 ) ;
V_24 -> V_73 ++ ;
}
F_42 ( & V_72 ) ;
return V_44 ;
}
static void F_43 ( struct V_55 * V_69 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = V_69 -> V_24 ;
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
if ( F_10 ( V_70 < 0 || V_70 >= V_16 ) )
return;
F_39 ( & V_72 ) ;
V_24 -> V_73 -- ;
F_44 ( V_24 -> V_66 [ V_70 ] , NULL ) ;
if ( ! V_24 -> V_73 )
F_45 ( F_27 , V_24 ) ;
F_42 ( & V_72 ) ;
}
static int F_46 ( struct V_55 * V_69 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = V_69 -> V_24 ;
int V_44 = 0 ;
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
if ( F_10 ( V_70 < 0 || V_70 >= V_16 ) )
return - V_71 ;
F_39 ( & V_72 ) ;
if ( ! V_24 -> V_74 )
V_44 = F_47 ( F_36 , V_24 ) ;
if ( ! V_44 ) {
F_41 ( V_24 -> V_68 [ V_70 ] , V_69 ) ;
V_24 -> V_74 ++ ;
}
F_42 ( & V_72 ) ;
return V_44 ;
}
static void F_48 ( struct V_55 * V_69 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = V_69 -> V_24 ;
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
if ( F_10 ( V_70 < 0 || V_70 >= V_16 ) )
return;
F_39 ( & V_72 ) ;
V_24 -> V_74 -- ;
F_44 ( V_24 -> V_68 [ V_70 ] , NULL ) ;
if ( ! V_24 -> V_74 )
F_49 ( F_36 , V_24 ) ;
F_42 ( & V_72 ) ;
}
static int T_1 F_50 ( struct V_2 * V_3 )
{
int V_54 ;
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
if ( V_70 < 0 || V_70 >= V_16 ) {
F_51 ( L_11 ,
( (struct V_4 * ) V_3 -> V_6 ) -> V_9 ) ;
return - V_71 ;
}
if ( F_18 ( V_3 ) < 0 )
return - V_50 ;
V_54 = F_52 ( V_3 ) ;
if ( V_54 < 0 ) {
F_20 ( V_3 ) ;
return V_54 ;
}
return V_54 ;
}
unsigned long T_1 __weak F_53 ( int V_14 )
{
return ( unsigned long ) V_75 [ V_14 ] ;
}
void T_1 F_54 ( void )
{
struct V_4 * V_51 ;
unsigned long V_76 ;
int V_32 ;
V_15 = F_55 ( V_16 , sizeof( * V_15 ) ,
V_49 ) ;
if ( ! V_15 ) {
F_56 ( 1 ) ;
return;
}
for ( V_32 = 0 ; V_32 < V_16 ; V_32 ++ ) {
V_76 = F_53 ( V_32 ) ;
V_51 = F_57 ( V_76 ) ;
if ( ! V_51 )
continue;
V_51 -> V_63 = V_32 ;
V_15 [ V_32 ] = V_51 ;
}
}
static void F_58 ( void * V_77 , struct V_12 * V_13 , long V_54 )
{
struct V_4 * V_57 ;
struct V_30 * V_78 ;
struct V_79 * V_80 ;
int V_63 ;
int V_81 ;
int V_64 ;
V_63 = F_3 ( V_65 , V_13 ) ;
if ( V_63 < 0 || V_63 >= V_16 )
return;
if ( ! F_59 ( V_63 , V_82 ) )
return;
V_57 = F_7 ( V_63 ) ;
if ( ! V_57 )
return;
V_80 = F_60 ( V_57 -> V_35 -> V_83 ) ;
if ( F_61 ( V_80 ) )
return;
V_64 = sizeof( unsigned long ) * V_57 -> V_36 + sizeof( * V_78 ) ;
V_64 = F_62 ( V_64 + sizeof( V_84 ) , sizeof( V_85 ) ) ;
V_64 -= sizeof( V_84 ) ;
V_78 = (struct V_30 * ) F_63 ( V_64 ,
V_57 -> V_35 -> V_22 . type , NULL , & V_81 ) ;
if ( ! V_78 )
return;
V_78 -> V_14 = V_63 ;
F_34 ( V_65 , V_13 , 0 , V_57 -> V_36 ,
( unsigned long * ) & V_78 -> args ) ;
F_64 ( V_78 , V_64 , V_81 , 0 , 1 , V_13 , V_80 , NULL ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
int V_44 = 0 ;
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
F_39 ( & V_72 ) ;
if ( ! V_86 )
V_44 = F_40 ( F_58 , NULL ) ;
if ( V_44 ) {
F_66 ( L_12
L_13 ) ;
} else {
F_67 ( V_70 , V_82 ) ;
V_86 ++ ;
}
F_42 ( & V_72 ) ;
return V_44 ;
}
static void F_68 ( struct V_2 * V_3 )
{
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
F_39 ( & V_72 ) ;
V_86 -- ;
F_69 ( V_70 , V_82 ) ;
if ( ! V_86 )
F_45 ( F_58 , NULL ) ;
F_42 ( & V_72 ) ;
}
static void F_70 ( void * V_77 , struct V_12 * V_13 , long V_44 )
{
struct V_4 * V_57 ;
struct V_40 * V_78 ;
struct V_79 * V_80 ;
int V_63 ;
int V_81 ;
int V_64 ;
V_63 = F_3 ( V_65 , V_13 ) ;
if ( V_63 < 0 || V_63 >= V_16 )
return;
if ( ! F_59 ( V_63 , V_87 ) )
return;
V_57 = F_7 ( V_63 ) ;
if ( ! V_57 )
return;
V_80 = F_60 ( V_57 -> V_42 -> V_83 ) ;
if ( F_61 ( V_80 ) )
return;
V_64 = F_62 ( sizeof( * V_78 ) + sizeof( V_84 ) , sizeof( V_85 ) ) ;
V_64 -= sizeof( V_84 ) ;
V_78 = (struct V_40 * ) F_63 ( V_64 ,
V_57 -> V_42 -> V_22 . type , NULL , & V_81 ) ;
if ( ! V_78 )
return;
V_78 -> V_14 = V_63 ;
V_78 -> V_44 = F_37 ( V_65 , V_13 ) ;
F_64 ( V_78 , V_64 , V_81 , 0 , 1 , V_13 , V_80 , NULL ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
int V_44 = 0 ;
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
F_39 ( & V_72 ) ;
if ( ! V_88 )
V_44 = F_47 ( F_70 , NULL ) ;
if ( V_44 ) {
F_66 ( L_12
L_14 ) ;
} else {
F_67 ( V_70 , V_87 ) ;
V_88 ++ ;
}
F_42 ( & V_72 ) ;
return V_44 ;
}
static void F_72 ( struct V_2 * V_3 )
{
int V_70 ;
V_70 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_63 ;
F_39 ( & V_72 ) ;
V_88 -- ;
F_69 ( V_70 , V_87 ) ;
if ( ! V_88 )
F_49 ( F_70 , NULL ) ;
F_42 ( & V_72 ) ;
}
static int F_73 ( struct V_2 * V_22 ,
enum V_89 type , void * V_6 )
{
struct V_55 * V_69 = V_6 ;
switch ( type ) {
case V_90 :
return F_38 ( V_69 , V_22 ) ;
case V_91 :
F_43 ( V_69 , V_22 ) ;
return 0 ;
#ifdef F_74
case V_92 :
return F_65 ( V_22 ) ;
case V_93 :
F_68 ( V_22 ) ;
return 0 ;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
return 0 ;
#endif
}
return 0 ;
}
static int F_75 ( struct V_2 * V_22 ,
enum V_89 type , void * V_6 )
{
struct V_55 * V_69 = V_6 ;
switch ( type ) {
case V_90 :
return F_46 ( V_69 , V_22 ) ;
case V_91 :
F_48 ( V_69 , V_22 ) ;
return 0 ;
#ifdef F_74
case V_92 :
return F_71 ( V_22 ) ;
case V_93 :
F_72 ( V_22 ) ;
return 0 ;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
return 0 ;
#endif
}
return 0 ;
}
