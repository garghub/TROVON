static inline int F_1 ( int type )
{
F_2 ( type != V_1 && type != V_2 ) ;
return ( type == V_2 ) ? V_3 : V_4 ;
}
static void F_3 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_7 ) {
F_4 ( F_5 ( V_6 -> V_8 -> V_9 ) ) ;
if ( V_6 -> V_10 )
F_6 ( & V_6 -> V_11 ) ;
V_6 -> V_7 = true ;
}
}
static void F_7 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 ) {
F_8 ( F_5 ( V_6 -> V_8 -> V_9 ) ) ;
V_6 -> V_7 = false ;
}
}
static T_1 F_9 ( struct V_12 * V_13 ,
char * V_14 , unsigned int type ,
bool V_15 )
{
int V_16 = F_1 ( type ) ;
unsigned long * V_17 ;
T_1 V_18 ;
int V_19 ;
V_17 = F_10 ( F_11 ( V_16 ) , sizeof( * V_17 ) , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_22 ; V_19 ++ ) {
struct V_5 * V_6 = & V_13 -> V_23 [ V_19 ] ;
if ( V_6 -> V_8 -> type != type )
continue;
if ( V_15 && ! V_6 -> V_7 )
continue;
F_12 ( V_6 -> V_8 -> V_24 , V_17 ) ;
}
V_18 = F_13 ( V_14 , V_25 - 2 , V_17 , V_16 ) ;
V_14 [ V_18 ++ ] = '\n' ;
V_14 [ V_18 ] = '\0' ;
F_14 ( V_17 ) ;
return V_18 ;
}
static T_1 F_15 ( struct V_12 * V_13 ,
const char * V_14 , unsigned int type )
{
int V_16 = F_1 ( type ) ;
unsigned long * V_17 ;
T_1 error ;
int V_19 ;
V_17 = F_10 ( F_11 ( V_16 ) , sizeof( * V_17 ) , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
error = F_16 ( V_14 , V_17 , V_16 ) ;
if ( error )
goto V_26;
for ( V_19 = 0 ; V_19 < V_13 -> V_22 ; V_19 ++ ) {
struct V_5 * V_6 = & V_13 -> V_23 [ V_19 ] ;
if ( V_6 -> V_8 -> type != type )
continue;
if ( F_17 ( V_6 -> V_8 -> V_24 , V_17 ) &&
! V_6 -> V_8 -> V_27 ) {
error = - V_28 ;
goto V_26;
}
}
F_18 ( & V_13 -> V_29 ) ;
for ( V_19 = 0 ; V_19 < V_13 -> V_22 ; V_19 ++ ) {
struct V_5 * V_6 = & V_13 -> V_23 [ V_19 ] ;
if ( V_6 -> V_8 -> type != type )
continue;
if ( F_17 ( V_6 -> V_8 -> V_24 , V_17 ) )
F_3 ( V_6 ) ;
else
F_7 ( V_6 ) ;
}
F_19 ( & V_13 -> V_29 ) ;
V_26:
F_14 ( V_17 ) ;
return error ;
}
static void F_20 ( struct V_5 * V_6 )
{
struct V_30 * V_8 = V_6 -> V_8 ;
struct V_31 * V_32 = V_6 -> V_32 ;
unsigned int type = V_8 -> type ? : V_2 ;
int V_33 = ( F_21 ( V_8 -> V_9 ) ? 1 : 0 ) ^ V_8 -> V_34 ;
if ( type == V_35 ) {
if ( V_33 )
F_22 ( V_32 , type , V_8 -> V_24 , V_8 -> V_36 ) ;
} else {
F_22 ( V_32 , type , V_8 -> V_24 , ! ! V_33 ) ;
}
F_23 ( V_32 ) ;
}
static void F_24 ( struct V_37 * V_38 )
{
struct V_5 * V_6 =
F_25 ( V_38 , struct V_5 , V_38 ) ;
F_20 ( V_6 ) ;
}
static void F_26 ( unsigned long V_39 )
{
struct V_5 * V_23 = (struct V_5 * ) V_39 ;
F_27 ( & V_23 -> V_38 ) ;
}
static T_2 F_28 ( int V_40 , void * V_41 )
{
struct V_5 * V_6 = V_41 ;
struct V_30 * V_8 = V_6 -> V_8 ;
F_2 ( V_40 != F_5 ( V_8 -> V_9 ) ) ;
if ( V_6 -> V_10 )
F_29 ( & V_6 -> V_11 ,
V_42 + F_30 ( V_6 -> V_10 ) ) ;
else
F_27 ( & V_6 -> V_38 ) ;
return V_43 ;
}
static int T_3 F_31 ( struct V_44 * V_45 ,
struct V_5 * V_6 ,
struct V_30 * V_8 )
{
const char * V_46 = V_8 -> V_46 ? V_8 -> V_46 : L_1 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
unsigned long V_49 ;
int V_40 , error ;
F_32 ( & V_6 -> V_11 , F_26 , ( unsigned long ) V_6 ) ;
F_33 ( & V_6 -> V_38 , F_24 ) ;
error = F_34 ( V_8 -> V_9 , V_46 ) ;
if ( error < 0 ) {
F_35 ( V_48 , L_2 ,
V_8 -> V_9 , error ) ;
goto V_50;
}
error = F_36 ( V_8 -> V_9 ) ;
if ( error < 0 ) {
F_35 ( V_48 , L_3
L_4 ,
V_8 -> V_9 , error ) ;
goto V_51;
}
if ( V_8 -> V_52 ) {
error = F_37 ( V_8 -> V_9 ,
V_8 -> V_52 * 1000 ) ;
if ( error < 0 )
V_6 -> V_10 = V_8 -> V_52 ;
}
V_40 = F_5 ( V_8 -> V_9 ) ;
if ( V_40 < 0 ) {
error = V_40 ;
F_35 ( V_48 , L_5 ,
V_8 -> V_9 , error ) ;
goto V_51;
}
V_49 = V_53 | V_54 ;
if ( ! V_8 -> V_27 )
V_49 |= V_55 ;
error = F_38 ( V_40 , NULL , F_28 , V_49 , V_46 , V_6 ) ;
if ( error < 0 ) {
F_35 ( V_48 , L_6 ,
V_40 , error ) ;
goto V_51;
}
return 0 ;
V_51:
F_39 ( V_8 -> V_9 ) ;
V_50:
return error ;
}
static int F_40 ( struct V_31 * V_32 )
{
struct V_12 * V_13 = F_41 ( V_32 ) ;
return V_13 -> V_56 ? V_13 -> V_56 ( V_32 -> V_48 . V_57 ) : 0 ;
}
static void F_42 ( struct V_31 * V_32 )
{
struct V_12 * V_13 = F_41 ( V_32 ) ;
if ( V_13 -> V_58 )
V_13 -> V_58 ( V_32 -> V_48 . V_57 ) ;
}
static int F_43 ( struct V_47 * V_48 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 , * V_63 ;
int V_19 ;
struct V_30 * V_64 ;
T_4 V_65 ;
V_62 = V_48 -> V_66 ;
if ( V_62 == NULL )
return - V_67 ;
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_68 = ! ! F_44 ( V_62 , L_7 , NULL ) ;
V_60 -> V_69 = 0 ;
V_63 = NULL ;
while ( ( V_63 = F_45 ( V_62 , V_63 ) ) )
V_60 -> V_69 ++ ;
if ( V_60 -> V_69 == 0 )
return - V_67 ;
V_64 = F_46 ( V_60 -> V_69 * ( sizeof *V_64 ) , V_20 ) ;
if ( ! V_64 )
return - V_21 ;
V_63 = NULL ;
V_19 = 0 ;
while ( ( V_63 = F_45 ( V_62 , V_63 ) ) ) {
enum V_70 V_71 ;
if ( ! F_47 ( V_63 , L_8 , NULL ) ) {
V_60 -> V_69 -- ;
F_48 ( V_48 , L_9 ) ;
continue;
}
V_64 [ V_19 ] . V_9 = F_49 ( V_63 , 0 , & V_71 ) ;
V_64 [ V_19 ] . V_34 = V_71 & V_72 ;
if ( F_50 ( V_63 , L_10 , & V_65 ) ) {
F_35 ( V_48 , L_11 , V_64 [ V_19 ] . V_9 ) ;
goto V_73;
}
V_64 [ V_19 ] . V_24 = V_65 ;
V_64 [ V_19 ] . V_46 = F_44 ( V_63 , L_12 , NULL ) ;
if ( F_50 ( V_63 , L_13 , & V_65 ) == 0 )
V_64 [ V_19 ] . type = V_65 ;
else
V_64 [ V_19 ] . type = V_2 ;
V_64 [ V_19 ] . V_74 = ! ! F_44 ( V_63 , L_14 , NULL ) ;
if ( F_50 ( V_63 , L_15 , & V_65 ) == 0 )
V_64 [ V_19 ] . V_52 = V_65 ;
else
V_64 [ V_19 ] . V_52 = 5 ;
V_19 ++ ;
}
V_60 -> V_64 = V_64 ;
return 0 ;
V_73:
F_14 ( V_64 ) ;
return - V_67 ;
}
static int F_43 ( struct V_47 * V_48 ,
struct V_59 * V_75 )
{
return - V_67 ;
}
static int T_3 F_51 ( struct V_44 * V_45 )
{
struct V_59 * V_60 = V_45 -> V_48 . V_76 ;
struct V_12 * V_13 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
struct V_59 V_77 ;
struct V_31 * V_32 ;
int V_19 , error ;
int V_74 = 0 ;
if ( ! V_60 ) {
error = F_43 ( V_48 , & V_77 ) ;
if ( error )
return error ;
V_60 = & V_77 ;
}
V_13 = F_46 ( sizeof( struct V_12 ) +
V_60 -> V_69 * sizeof( struct V_5 ) ,
V_20 ) ;
V_32 = F_52 () ;
if ( ! V_13 || ! V_32 ) {
F_35 ( V_48 , L_16 ) ;
error = - V_21 ;
goto V_78;
}
V_13 -> V_32 = V_32 ;
V_13 -> V_22 = V_60 -> V_69 ;
V_13 -> V_56 = V_60 -> V_56 ;
V_13 -> V_58 = V_60 -> V_58 ;
F_53 ( & V_13 -> V_29 ) ;
F_54 ( V_45 , V_13 ) ;
F_55 ( V_32 , V_13 ) ;
V_32 -> V_79 = V_60 -> V_79 ? : V_45 -> V_79 ;
V_32 -> V_80 = L_17 ;
V_32 -> V_48 . V_57 = & V_45 -> V_48 ;
V_32 -> V_81 = F_40 ;
V_32 -> V_82 = F_42 ;
V_32 -> V_83 . V_84 = V_85 ;
V_32 -> V_83 . V_86 = 0x0001 ;
V_32 -> V_83 . V_87 = 0x0001 ;
V_32 -> V_83 . V_88 = 0x0100 ;
if ( V_60 -> V_68 )
F_12 ( V_89 , V_32 -> V_90 ) ;
for ( V_19 = 0 ; V_19 < V_60 -> V_69 ; V_19 ++ ) {
struct V_30 * V_8 = & V_60 -> V_64 [ V_19 ] ;
struct V_5 * V_6 = & V_13 -> V_23 [ V_19 ] ;
unsigned int type = V_8 -> type ? : V_2 ;
V_6 -> V_32 = V_32 ;
V_6 -> V_8 = V_8 ;
error = F_31 ( V_45 , V_6 , V_8 ) ;
if ( error )
goto V_50;
if ( V_8 -> V_74 )
V_74 = 1 ;
F_56 ( V_32 , type , V_8 -> V_24 ) ;
}
error = F_57 ( & V_45 -> V_48 . V_91 , & V_92 ) ;
if ( error ) {
F_35 ( V_48 , L_18 ,
error ) ;
goto V_50;
}
error = F_58 ( V_32 ) ;
if ( error ) {
F_35 ( V_48 , L_19 ,
error ) ;
goto V_51;
}
for ( V_19 = 0 ; V_19 < V_60 -> V_69 ; V_19 ++ )
F_20 ( & V_13 -> V_23 [ V_19 ] ) ;
F_23 ( V_32 ) ;
F_59 ( & V_45 -> V_48 , V_74 ) ;
return 0 ;
V_51:
F_60 ( & V_45 -> V_48 . V_91 , & V_92 ) ;
V_50:
while ( -- V_19 >= 0 ) {
F_61 ( F_5 ( V_60 -> V_64 [ V_19 ] . V_9 ) , & V_13 -> V_23 [ V_19 ] ) ;
if ( V_13 -> V_23 [ V_19 ] . V_10 )
F_6 ( & V_13 -> V_23 [ V_19 ] . V_11 ) ;
F_62 ( & V_13 -> V_23 [ V_19 ] . V_38 ) ;
F_39 ( V_60 -> V_64 [ V_19 ] . V_9 ) ;
}
F_54 ( V_45 , NULL ) ;
V_78:
F_63 ( V_32 ) ;
F_14 ( V_13 ) ;
if ( ! V_45 -> V_48 . V_76 )
F_14 ( V_60 -> V_64 ) ;
return error ;
}
static int T_5 F_64 ( struct V_44 * V_45 )
{
struct V_12 * V_13 = F_65 ( V_45 ) ;
struct V_31 * V_32 = V_13 -> V_32 ;
int V_19 ;
F_60 ( & V_45 -> V_48 . V_91 , & V_92 ) ;
F_59 ( & V_45 -> V_48 , 0 ) ;
for ( V_19 = 0 ; V_19 < V_13 -> V_22 ; V_19 ++ ) {
int V_40 = F_5 ( V_13 -> V_23 [ V_19 ] . V_8 -> V_9 ) ;
F_61 ( V_40 , & V_13 -> V_23 [ V_19 ] ) ;
if ( V_13 -> V_23 [ V_19 ] . V_10 )
F_6 ( & V_13 -> V_23 [ V_19 ] . V_11 ) ;
F_62 ( & V_13 -> V_23 [ V_19 ] . V_38 ) ;
F_39 ( V_13 -> V_23 [ V_19 ] . V_8 -> V_9 ) ;
}
F_66 ( V_32 ) ;
if ( ! V_45 -> V_48 . V_76 )
F_14 ( V_13 -> V_23 [ 0 ] . V_8 ) ;
F_14 ( V_13 ) ;
return 0 ;
}
static int F_67 ( struct V_47 * V_48 )
{
struct V_12 * V_13 = F_68 ( V_48 ) ;
int V_19 ;
if ( F_69 ( V_48 ) ) {
for ( V_19 = 0 ; V_19 < V_13 -> V_22 ; V_19 ++ ) {
struct V_30 * V_8 = V_13 -> V_23 [ V_19 ] . V_8 ;
if ( V_8 -> V_74 ) {
int V_40 = F_5 ( V_8 -> V_9 ) ;
F_70 ( V_40 ) ;
}
}
}
return 0 ;
}
static int F_71 ( struct V_47 * V_48 )
{
struct V_12 * V_13 = F_68 ( V_48 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_22 ; V_19 ++ ) {
struct V_30 * V_8 = V_13 -> V_23 [ V_19 ] . V_8 ;
if ( V_8 -> V_74 && F_69 ( V_48 ) ) {
int V_40 = F_5 ( V_8 -> V_9 ) ;
F_72 ( V_40 ) ;
}
F_20 ( & V_13 -> V_23 [ V_19 ] ) ;
}
F_23 ( V_13 -> V_32 ) ;
return 0 ;
}
static int T_6 F_73 ( void )
{
return F_74 ( & V_93 ) ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_93 ) ;
}
