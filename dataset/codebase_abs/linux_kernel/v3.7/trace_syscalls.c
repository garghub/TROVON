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
struct V_4 * F_3 ( int V_10 )
{
if ( ! V_11 || V_10 >= V_12 || V_10 < 0 )
return NULL ;
return V_11 [ V_10 ] ;
}
enum V_13
F_4 ( struct V_14 * V_15 , int V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_15 -> V_21 ;
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_24 * V_25 ;
struct V_4 * V_5 ;
int V_26 , V_27 , V_28 ;
V_25 = ( F_5 ( V_25 ) ) V_23 ;
V_28 = V_25 -> V_10 ;
V_5 = F_3 ( V_28 ) ;
if ( ! V_5 )
goto V_29;
if ( V_5 -> V_30 -> V_18 . type != V_23 -> type ) {
F_6 ( 1 ) ;
goto V_29;
}
V_27 = F_7 ( V_20 , L_1 , V_5 -> V_9 ) ;
if ( ! V_27 )
return V_31 ;
for ( V_26 = 0 ; V_26 < V_5 -> V_32 ; V_26 ++ ) {
if ( V_33 & V_34 ) {
V_27 = F_7 ( V_20 , L_2 , V_5 -> V_35 [ V_26 ] ) ;
if ( ! V_27 )
return V_31 ;
}
V_27 = F_7 ( V_20 , L_3 , V_5 -> args [ V_26 ] ,
V_25 -> args [ V_26 ] ,
V_26 == V_5 -> V_32 - 1 ? L_4 : L_5 ) ;
if ( ! V_27 )
return V_31 ;
}
V_27 = F_8 ( V_20 , ')' ) ;
if ( ! V_27 )
return V_31 ;
V_29:
V_27 = F_8 ( V_20 , '\n' ) ;
if ( ! V_27 )
return V_31 ;
return V_36 ;
}
enum V_13
F_9 ( struct V_14 * V_15 , int V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_15 -> V_21 ;
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_37 * V_25 ;
int V_28 ;
struct V_4 * V_5 ;
int V_27 ;
V_25 = ( F_5 ( V_25 ) ) V_23 ;
V_28 = V_25 -> V_10 ;
V_5 = F_3 ( V_28 ) ;
if ( ! V_5 ) {
F_7 ( V_20 , L_6 ) ;
return V_36 ;
}
if ( V_5 -> V_38 -> V_18 . type != V_23 -> type ) {
F_6 ( 1 ) ;
return V_39 ;
}
V_27 = F_7 ( V_20 , L_7 , V_5 -> V_9 ,
V_25 -> V_27 ) ;
if ( ! V_27 )
return V_31 ;
return V_36 ;
}
static
int F_10 ( struct V_4 * V_5 , char * V_40 , int V_41 )
{
int V_26 ;
int V_42 = 0 ;
#define F_11 (len ? len - pos : 0)
V_42 += snprintf ( V_40 + V_42 , F_11 , L_8 ) ;
for ( V_26 = 0 ; V_26 < V_5 -> V_32 ; V_26 ++ ) {
V_42 += snprintf ( V_40 + V_42 , F_11 , L_9 ,
V_5 -> args [ V_26 ] , sizeof( unsigned long ) ,
V_26 == V_5 -> V_32 - 1 ? L_4 : L_5 ) ;
}
V_42 += snprintf ( V_40 + V_42 , F_11 , L_8 ) ;
for ( V_26 = 0 ; V_26 < V_5 -> V_32 ; V_26 ++ ) {
V_42 += snprintf ( V_40 + V_42 , F_11 ,
L_10 , V_5 -> args [ V_26 ] ) ;
}
#undef F_11
return V_42 ;
}
static int F_12 ( struct V_2 * V_3 )
{
char * V_43 ;
int V_41 ;
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_30 != V_3 ) {
V_3 -> V_43 = L_11 ;
return 0 ;
}
V_41 = F_10 ( V_5 , NULL , 0 ) ;
V_43 = F_13 ( V_41 + 1 , V_44 ) ;
if ( ! V_43 )
return - V_45 ;
F_10 ( V_5 , V_43 , V_41 + 1 ) ;
V_3 -> V_43 = V_43 ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_5 -> V_30 == V_3 )
F_15 ( V_3 -> V_43 ) ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_24 V_25 ;
struct V_4 * V_46 = V_3 -> V_6 ;
int V_27 ;
int V_26 ;
int V_47 = F_17 ( F_5 ( V_25 ) , args ) ;
V_27 = F_18 ( V_3 , F_19 ( int , V_10 ) , V_48 ) ;
if ( V_27 )
return V_27 ;
for ( V_26 = 0 ; V_26 < V_46 -> V_32 ; V_26 ++ ) {
V_27 = F_18 ( V_3 , V_46 -> V_35 [ V_26 ] ,
V_46 -> args [ V_26 ] , V_47 ,
sizeof( unsigned long ) , 0 ,
V_48 ) ;
V_47 += sizeof( unsigned long ) ;
}
return V_27 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_37 V_25 ;
int V_27 ;
V_27 = F_18 ( V_3 , F_19 ( int , V_10 ) , V_48 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_18 ( V_3 , F_19 ( long , V_27 ) ,
V_48 ) ;
return V_27 ;
}
void F_21 ( void * V_49 , struct V_50 * V_51 , long V_52 )
{
struct V_24 * V_5 ;
struct V_4 * V_53 ;
struct V_54 * V_18 ;
struct V_55 * V_56 ;
int V_57 ;
int V_58 ;
V_58 = F_22 ( V_59 , V_51 ) ;
if ( V_58 < 0 )
return;
if ( ! F_23 ( V_58 , V_60 ) )
return;
V_53 = F_3 ( V_58 ) ;
if ( ! V_53 )
return;
V_57 = sizeof( * V_5 ) + sizeof( unsigned long ) * V_53 -> V_32 ;
V_18 = F_24 ( & V_56 ,
V_53 -> V_30 -> V_18 . type , V_57 , 0 , 0 ) ;
if ( ! V_18 )
return;
V_5 = F_25 ( V_18 ) ;
V_5 -> V_10 = V_58 ;
F_26 ( V_59 , V_51 , 0 , V_53 -> V_32 , V_5 -> args ) ;
if ( ! F_27 ( V_56 , V_53 -> V_30 ,
V_5 , V_18 ) )
F_28 ( V_56 , V_18 , 0 , 0 ) ;
}
void F_29 ( void * V_49 , struct V_50 * V_51 , long V_27 )
{
struct V_37 * V_5 ;
struct V_4 * V_53 ;
struct V_54 * V_18 ;
struct V_55 * V_56 ;
int V_58 ;
V_58 = F_22 ( V_59 , V_51 ) ;
if ( V_58 < 0 )
return;
if ( ! F_23 ( V_58 , V_61 ) )
return;
V_53 = F_3 ( V_58 ) ;
if ( ! V_53 )
return;
V_18 = F_24 ( & V_56 ,
V_53 -> V_38 -> V_18 . type , sizeof( * V_5 ) , 0 , 0 ) ;
if ( ! V_18 )
return;
V_5 = F_25 ( V_18 ) ;
V_5 -> V_10 = V_58 ;
V_5 -> V_27 = F_30 ( V_59 , V_51 ) ;
if ( ! F_27 ( V_56 , V_53 -> V_38 ,
V_5 , V_18 ) )
F_28 ( V_56 , V_18 , 0 , 0 ) ;
}
int F_31 ( struct V_2 * V_3 )
{
int V_27 = 0 ;
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
if ( F_6 ( V_62 < 0 || V_62 >= V_12 ) )
return - V_63 ;
F_32 ( & V_64 ) ;
if ( ! V_65 )
V_27 = F_33 ( F_21 , NULL ) ;
if ( ! V_27 ) {
F_34 ( V_62 , V_60 ) ;
V_65 ++ ;
}
F_35 ( & V_64 ) ;
return V_27 ;
}
void F_36 ( struct V_2 * V_3 )
{
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
if ( F_6 ( V_62 < 0 || V_62 >= V_12 ) )
return;
F_32 ( & V_64 ) ;
V_65 -- ;
F_37 ( V_62 , V_60 ) ;
if ( ! V_65 )
F_38 ( F_21 , NULL ) ;
F_35 ( & V_64 ) ;
}
int F_39 ( struct V_2 * V_3 )
{
int V_27 = 0 ;
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
if ( F_6 ( V_62 < 0 || V_62 >= V_12 ) )
return - V_63 ;
F_32 ( & V_64 ) ;
if ( ! V_66 )
V_27 = F_40 ( F_29 , NULL ) ;
if ( ! V_27 ) {
F_34 ( V_62 , V_61 ) ;
V_66 ++ ;
}
F_35 ( & V_64 ) ;
return V_27 ;
}
void F_41 ( struct V_2 * V_3 )
{
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
if ( F_6 ( V_62 < 0 || V_62 >= V_12 ) )
return;
F_32 ( & V_64 ) ;
V_66 -- ;
F_37 ( V_62 , V_61 ) ;
if ( ! V_66 )
F_42 ( F_29 , NULL ) ;
F_35 ( & V_64 ) ;
}
int F_43 ( struct V_2 * V_3 )
{
int V_52 ;
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
if ( V_62 < 0 || V_62 >= V_12 ) {
F_44 ( L_12 ,
( (struct V_4 * ) V_3 -> V_6 ) -> V_9 ) ;
return - V_63 ;
}
if ( F_12 ( V_3 ) < 0 )
return - V_45 ;
V_52 = F_45 ( V_3 ) ;
if ( V_52 < 0 ) {
F_14 ( V_3 ) ;
return V_52 ;
}
return V_52 ;
}
unsigned long T_1 __weak F_46 ( int V_10 )
{
return ( unsigned long ) V_67 [ V_10 ] ;
}
int T_1 F_47 ( void )
{
struct V_4 * V_46 ;
unsigned long V_68 ;
int V_26 ;
V_11 = F_48 ( V_12 , sizeof( * V_11 ) ,
V_44 ) ;
if ( ! V_11 ) {
F_49 ( 1 ) ;
return - V_45 ;
}
for ( V_26 = 0 ; V_26 < V_12 ; V_26 ++ ) {
V_68 = F_46 ( V_26 ) ;
V_46 = F_50 ( V_68 ) ;
if ( ! V_46 )
continue;
V_46 -> V_58 = V_26 ;
V_11 [ V_26 ] = V_46 ;
}
return 0 ;
}
static void F_51 ( void * V_49 , struct V_50 * V_51 , long V_52 )
{
struct V_4 * V_53 ;
struct V_24 * V_69 ;
struct V_70 * V_71 ;
int V_58 ;
int V_72 ;
int V_57 ;
V_58 = F_22 ( V_59 , V_51 ) ;
if ( V_58 < 0 )
return;
if ( ! F_23 ( V_58 , V_73 ) )
return;
V_53 = F_3 ( V_58 ) ;
if ( ! V_53 )
return;
V_57 = sizeof( unsigned long ) * V_53 -> V_32 + sizeof( * V_69 ) ;
V_57 = F_52 ( V_57 + sizeof( V_74 ) , sizeof( V_75 ) ) ;
V_57 -= sizeof( V_74 ) ;
if ( F_53 ( V_57 > V_76 ,
L_13 ) )
return;
V_69 = (struct V_24 * ) F_54 ( V_57 ,
V_53 -> V_30 -> V_18 . type , V_51 , & V_72 ) ;
if ( ! V_69 )
return;
V_69 -> V_10 = V_58 ;
F_26 ( V_59 , V_51 , 0 , V_53 -> V_32 ,
( unsigned long * ) & V_69 -> args ) ;
V_71 = F_55 ( V_53 -> V_30 -> V_77 ) ;
F_56 ( V_69 , V_57 , V_72 , 0 , 1 , V_51 , V_71 , NULL ) ;
}
int F_57 ( struct V_2 * V_3 )
{
int V_27 = 0 ;
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
F_32 ( & V_64 ) ;
if ( ! V_78 )
V_27 = F_33 ( F_51 , NULL ) ;
if ( V_27 ) {
F_58 ( L_14
L_15 ) ;
} else {
F_34 ( V_62 , V_73 ) ;
V_78 ++ ;
}
F_35 ( & V_64 ) ;
return V_27 ;
}
void F_59 ( struct V_2 * V_3 )
{
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
F_32 ( & V_64 ) ;
V_78 -- ;
F_37 ( V_62 , V_73 ) ;
if ( ! V_78 )
F_38 ( F_51 , NULL ) ;
F_35 ( & V_64 ) ;
}
static void F_60 ( void * V_49 , struct V_50 * V_51 , long V_27 )
{
struct V_4 * V_53 ;
struct V_37 * V_69 ;
struct V_70 * V_71 ;
int V_58 ;
int V_72 ;
int V_57 ;
V_58 = F_22 ( V_59 , V_51 ) ;
if ( V_58 < 0 )
return;
if ( ! F_23 ( V_58 , V_79 ) )
return;
V_53 = F_3 ( V_58 ) ;
if ( ! V_53 )
return;
V_57 = F_52 ( sizeof( * V_69 ) + sizeof( V_74 ) , sizeof( V_75 ) ) ;
V_57 -= sizeof( V_74 ) ;
if ( F_53 ( V_57 > V_76 ,
L_16 ) )
return;
V_69 = (struct V_37 * ) F_54 ( V_57 ,
V_53 -> V_38 -> V_18 . type , V_51 , & V_72 ) ;
if ( ! V_69 )
return;
V_69 -> V_10 = V_58 ;
V_69 -> V_27 = F_30 ( V_59 , V_51 ) ;
V_71 = F_55 ( V_53 -> V_38 -> V_77 ) ;
F_56 ( V_69 , V_57 , V_72 , 0 , 1 , V_51 , V_71 , NULL ) ;
}
int F_61 ( struct V_2 * V_3 )
{
int V_27 = 0 ;
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
F_32 ( & V_64 ) ;
if ( ! V_80 )
V_27 = F_40 ( F_60 , NULL ) ;
if ( V_27 ) {
F_58 ( L_14
L_17 ) ;
} else {
F_34 ( V_62 , V_79 ) ;
V_80 ++ ;
}
F_35 ( & V_64 ) ;
return V_27 ;
}
void F_62 ( struct V_2 * V_3 )
{
int V_62 ;
V_62 = ( (struct V_4 * ) V_3 -> V_6 ) -> V_58 ;
F_32 ( & V_64 ) ;
V_80 -- ;
F_37 ( V_62 , V_79 ) ;
if ( ! V_80 )
F_42 ( F_60 , NULL ) ;
F_35 ( & V_64 ) ;
}
static int F_63 ( struct V_2 * V_18 ,
enum V_81 type , void * V_6 )
{
switch ( type ) {
case V_82 :
return F_31 ( V_18 ) ;
case V_83 :
F_36 ( V_18 ) ;
return 0 ;
#ifdef F_64
case V_84 :
return F_57 ( V_18 ) ;
case V_85 :
F_59 ( V_18 ) ;
return 0 ;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
return 0 ;
#endif
}
return 0 ;
}
static int F_65 ( struct V_2 * V_18 ,
enum V_81 type , void * V_6 )
{
switch ( type ) {
case V_82 :
return F_39 ( V_18 ) ;
case V_83 :
F_41 ( V_18 ) ;
return 0 ;
#ifdef F_64
case V_84 :
return F_61 ( V_18 ) ;
case V_85 :
F_62 ( V_18 ) ;
return 0 ;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
return 0 ;
#endif
}
return 0 ;
}
