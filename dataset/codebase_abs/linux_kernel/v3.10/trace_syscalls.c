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
F_11 ( V_24 , L_6 ) ;
return V_40 ;
}
if ( V_5 -> V_42 -> V_22 . type != V_27 -> type ) {
F_10 ( 1 ) ;
return V_43 ;
}
V_31 = F_11 ( V_24 , L_7 , V_5 -> V_9 ,
V_29 -> V_31 ) ;
if ( ! V_31 )
return V_35 ;
return V_40 ;
}
static
int F_14 ( struct V_4 * V_5 , char * V_44 , int V_45 )
{
int V_30 ;
int V_46 = 0 ;
#define F_15 (len ? len - pos : 0)
V_46 += snprintf ( V_44 + V_46 , F_15 , L_8 ) ;
for ( V_30 = 0 ; V_30 < V_5 -> V_36 ; V_30 ++ ) {
V_46 += snprintf ( V_44 + V_46 , F_15 , L_9 ,
V_5 -> args [ V_30 ] , sizeof( unsigned long ) ,
V_30 == V_5 -> V_36 - 1 ? L_4 : L_5 ) ;
}
V_46 += snprintf ( V_44 + V_46 , F_15 , L_8 ) ;
for ( V_30 = 0 ; V_30 < V_5 -> V_36 ; V_30 ++ ) {
V_46 += snprintf ( V_44 + V_46 , F_15 ,
L_10 , V_5 -> args [ V_30 ] ) ;
}
#undef F_15
return V_46 ;
}
static int F_16 ( struct V_2 * V_3 )
{
char * V_47 ;
int V_45 ;
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_34 != V_3 ) {
V_3 -> V_47 = L_11 ;
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
static void F_18 ( struct V_2 * V_3 )
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
struct V_28 * V_5 ;
struct V_4 * V_56 ;
struct V_57 * V_22 ;
struct V_58 * V_59 ;
int V_60 ;
int V_61 ;
V_60 = F_3 ( V_62 , V_13 ) ;
if ( V_60 < 0 )
return;
if ( ! F_26 ( V_60 , V_55 -> V_63 ) )
return;
V_56 = F_7 ( V_60 ) ;
if ( ! V_56 )
return;
V_61 = sizeof( * V_5 ) + sizeof( unsigned long ) * V_56 -> V_36 ;
V_59 = V_55 -> V_64 . V_59 ;
V_22 = F_27 ( V_59 ,
V_56 -> V_34 -> V_22 . type , V_61 , 0 , 0 ) ;
if ( ! V_22 )
return;
V_5 = F_28 ( V_22 ) ;
V_5 -> V_14 = V_60 ;
F_29 ( V_62 , V_13 , 0 , V_56 -> V_36 , V_5 -> args ) ;
if ( ! F_30 ( V_59 , V_56 -> V_34 ,
V_5 , V_22 ) )
F_31 ( V_59 , V_22 , 0 , 0 ) ;
}
static void F_32 ( void * V_6 , struct V_12 * V_13 , long V_31 )
{
struct V_54 * V_55 = V_6 ;
struct V_41 * V_5 ;
struct V_4 * V_56 ;
struct V_57 * V_22 ;
struct V_58 * V_59 ;
int V_60 ;
V_60 = F_3 ( V_62 , V_13 ) ;
if ( V_60 < 0 )
return;
if ( ! F_26 ( V_60 , V_55 -> V_65 ) )
return;
V_56 = F_7 ( V_60 ) ;
if ( ! V_56 )
return;
V_59 = V_55 -> V_64 . V_59 ;
V_22 = F_27 ( V_59 ,
V_56 -> V_42 -> V_22 . type , sizeof( * V_5 ) , 0 , 0 ) ;
if ( ! V_22 )
return;
V_5 = F_28 ( V_22 ) ;
V_5 -> V_14 = V_60 ;
V_5 -> V_31 = F_33 ( V_62 , V_13 ) ;
if ( ! F_30 ( V_59 , V_56 -> V_42 ,
V_5 , V_22 ) )
F_31 ( V_59 , V_22 , 0 , 0 ) ;
}
static int F_34 ( struct V_66 * V_67 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
int V_31 = 0 ;
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
if ( F_10 ( V_68 < 0 || V_68 >= V_16 ) )
return - V_69 ;
F_35 ( & V_70 ) ;
if ( ! V_55 -> V_71 )
V_31 = F_36 ( F_25 , V_55 ) ;
if ( ! V_31 ) {
F_37 ( V_68 , V_55 -> V_63 ) ;
V_55 -> V_71 ++ ;
}
F_38 ( & V_70 ) ;
return V_31 ;
}
static void F_39 ( struct V_66 * V_67 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
if ( F_10 ( V_68 < 0 || V_68 >= V_16 ) )
return;
F_35 ( & V_70 ) ;
V_55 -> V_71 -- ;
F_40 ( V_68 , V_55 -> V_63 ) ;
if ( ! V_55 -> V_71 )
F_41 ( F_25 , V_55 ) ;
F_38 ( & V_70 ) ;
}
static int F_42 ( struct V_66 * V_67 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
int V_31 = 0 ;
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
if ( F_10 ( V_68 < 0 || V_68 >= V_16 ) )
return - V_69 ;
F_35 ( & V_70 ) ;
if ( ! V_55 -> V_72 )
V_31 = F_43 ( F_32 , V_55 ) ;
if ( ! V_31 ) {
F_37 ( V_68 , V_55 -> V_65 ) ;
V_55 -> V_72 ++ ;
}
F_38 ( & V_70 ) ;
return V_31 ;
}
static void F_44 ( struct V_66 * V_67 ,
struct V_2 * V_3 )
{
struct V_54 * V_55 = V_67 -> V_55 ;
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
if ( F_10 ( V_68 < 0 || V_68 >= V_16 ) )
return;
F_35 ( & V_70 ) ;
V_55 -> V_72 -- ;
F_40 ( V_68 , V_55 -> V_65 ) ;
if ( ! V_55 -> V_72 )
F_45 ( F_32 , V_55 ) ;
F_38 ( & V_70 ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
int V_53 ;
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
if ( V_68 < 0 || V_68 >= V_16 ) {
F_47 ( L_12 ,
( (struct V_4 * ) V_3 -> V_6 ) -> V_9 ) ;
return - V_69 ;
}
if ( F_16 ( V_3 ) < 0 )
return - V_49 ;
V_53 = F_48 ( V_3 ) ;
if ( V_53 < 0 ) {
F_18 ( V_3 ) ;
return V_53 ;
}
return V_53 ;
}
unsigned long T_1 __weak F_49 ( int V_14 )
{
return ( unsigned long ) V_73 [ V_14 ] ;
}
static int T_1 F_50 ( void )
{
struct V_4 * V_50 ;
unsigned long V_74 ;
int V_30 ;
V_15 = F_51 ( V_16 , sizeof( * V_15 ) ,
V_48 ) ;
if ( ! V_15 ) {
F_52 ( 1 ) ;
return - V_49 ;
}
for ( V_30 = 0 ; V_30 < V_16 ; V_30 ++ ) {
V_74 = F_49 ( V_30 ) ;
V_50 = F_53 ( V_74 ) ;
if ( ! V_50 )
continue;
V_50 -> V_60 = V_30 ;
V_15 [ V_30 ] = V_50 ;
}
return 0 ;
}
static void F_54 ( void * V_75 , struct V_12 * V_13 , long V_53 )
{
struct V_4 * V_56 ;
struct V_28 * V_76 ;
struct V_77 * V_78 ;
int V_60 ;
int V_79 ;
int V_61 ;
V_60 = F_3 ( V_62 , V_13 ) ;
if ( V_60 < 0 )
return;
if ( ! F_26 ( V_60 , V_80 ) )
return;
V_56 = F_7 ( V_60 ) ;
if ( ! V_56 )
return;
V_61 = sizeof( unsigned long ) * V_56 -> V_36 + sizeof( * V_76 ) ;
V_61 = F_55 ( V_61 + sizeof( V_81 ) , sizeof( V_82 ) ) ;
V_61 -= sizeof( V_81 ) ;
if ( F_56 ( V_61 > V_83 ,
L_13 ) )
return;
V_76 = (struct V_28 * ) F_57 ( V_61 ,
V_56 -> V_34 -> V_22 . type , V_13 , & V_79 ) ;
if ( ! V_76 )
return;
V_76 -> V_14 = V_60 ;
F_29 ( V_62 , V_13 , 0 , V_56 -> V_36 ,
( unsigned long * ) & V_76 -> args ) ;
V_78 = F_58 ( V_56 -> V_34 -> V_84 ) ;
F_59 ( V_76 , V_61 , V_79 , 0 , 1 , V_13 , V_78 , NULL ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
int V_31 = 0 ;
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
F_35 ( & V_70 ) ;
if ( ! V_85 )
V_31 = F_36 ( F_54 , NULL ) ;
if ( V_31 ) {
F_61 ( L_14
L_15 ) ;
} else {
F_37 ( V_68 , V_80 ) ;
V_85 ++ ;
}
F_38 ( & V_70 ) ;
return V_31 ;
}
static void F_62 ( struct V_2 * V_3 )
{
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
F_35 ( & V_70 ) ;
V_85 -- ;
F_40 ( V_68 , V_80 ) ;
if ( ! V_85 )
F_41 ( F_54 , NULL ) ;
F_38 ( & V_70 ) ;
}
static void F_63 ( void * V_75 , struct V_12 * V_13 , long V_31 )
{
struct V_4 * V_56 ;
struct V_41 * V_76 ;
struct V_77 * V_78 ;
int V_60 ;
int V_79 ;
int V_61 ;
V_60 = F_3 ( V_62 , V_13 ) ;
if ( V_60 < 0 )
return;
if ( ! F_26 ( V_60 , V_86 ) )
return;
V_56 = F_7 ( V_60 ) ;
if ( ! V_56 )
return;
V_61 = F_55 ( sizeof( * V_76 ) + sizeof( V_81 ) , sizeof( V_82 ) ) ;
V_61 -= sizeof( V_81 ) ;
if ( F_56 ( V_61 > V_83 ,
L_16 ) )
return;
V_76 = (struct V_41 * ) F_57 ( V_61 ,
V_56 -> V_42 -> V_22 . type , V_13 , & V_79 ) ;
if ( ! V_76 )
return;
V_76 -> V_14 = V_60 ;
V_76 -> V_31 = F_33 ( V_62 , V_13 ) ;
V_78 = F_58 ( V_56 -> V_42 -> V_84 ) ;
F_59 ( V_76 , V_61 , V_79 , 0 , 1 , V_13 , V_78 , NULL ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
int V_31 = 0 ;
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
F_35 ( & V_70 ) ;
if ( ! V_87 )
V_31 = F_43 ( F_63 , NULL ) ;
if ( V_31 ) {
F_61 ( L_14
L_17 ) ;
} else {
F_37 ( V_68 , V_86 ) ;
V_87 ++ ;
}
F_38 ( & V_70 ) ;
return V_31 ;
}
static void F_65 ( struct V_2 * V_3 )
{
int V_68 ;
V_68 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_60 ;
F_35 ( & V_70 ) ;
V_87 -- ;
F_40 ( V_68 , V_86 ) ;
if ( ! V_87 )
F_45 ( F_63 , NULL ) ;
F_38 ( & V_70 ) ;
}
static int F_66 ( struct V_2 * V_22 ,
enum V_88 type , void * V_6 )
{
struct V_66 * V_67 = V_6 ;
switch ( type ) {
case V_89 :
return F_34 ( V_67 , V_22 ) ;
case V_90 :
F_39 ( V_67 , V_22 ) ;
return 0 ;
#ifdef F_67
case V_91 :
return F_60 ( V_22 ) ;
case V_92 :
F_62 ( V_22 ) ;
return 0 ;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
return 0 ;
#endif
}
return 0 ;
}
static int F_68 ( struct V_2 * V_22 ,
enum V_88 type , void * V_6 )
{
struct V_66 * V_67 = V_6 ;
switch ( type ) {
case V_89 :
return F_42 ( V_67 , V_22 ) ;
case V_90 :
F_44 ( V_67 , V_22 ) ;
return 0 ;
#ifdef F_67
case V_91 :
return F_64 ( V_22 ) ;
case V_92 :
F_65 ( V_22 ) ;
return 0 ;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
return 0 ;
#endif
}
return 0 ;
}
