static inline int F_1 ( int type )
{
F_2 ( type != V_1 && type != V_2 ) ;
return ( type == V_2 ) ? V_3 : V_4 ;
}
static void F_3 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_7 ) {
F_4 ( V_6 -> V_8 ) ;
if ( V_6 -> V_9 )
F_5 ( & V_6 -> V_10 ) ;
V_6 -> V_7 = true ;
}
}
static void F_6 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 ) {
F_7 ( V_6 -> V_8 ) ;
V_6 -> V_7 = false ;
}
}
static T_1 F_8 ( struct V_11 * V_12 ,
char * V_13 , unsigned int type ,
bool V_14 )
{
int V_15 = F_1 ( type ) ;
unsigned long * V_16 ;
T_1 V_17 ;
int V_18 ;
V_16 = F_9 ( F_10 ( V_15 ) , sizeof( * V_16 ) , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_22 [ V_18 ] ;
if ( V_6 -> V_23 -> type != type )
continue;
if ( V_14 && ! V_6 -> V_7 )
continue;
F_11 ( V_6 -> V_23 -> V_24 , V_16 ) ;
}
V_17 = F_12 ( V_13 , V_25 - 2 , V_16 , V_15 ) ;
V_13 [ V_17 ++ ] = '\n' ;
V_13 [ V_17 ] = '\0' ;
F_13 ( V_16 ) ;
return V_17 ;
}
static T_1 F_14 ( struct V_11 * V_12 ,
const char * V_13 , unsigned int type )
{
int V_15 = F_1 ( type ) ;
unsigned long * V_16 ;
T_1 error ;
int V_18 ;
V_16 = F_9 ( F_10 ( V_15 ) , sizeof( * V_16 ) , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
error = F_15 ( V_13 , V_16 , V_15 ) ;
if ( error )
goto V_26;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_22 [ V_18 ] ;
if ( V_6 -> V_23 -> type != type )
continue;
if ( F_16 ( V_6 -> V_23 -> V_24 , V_16 ) &&
! V_6 -> V_23 -> V_27 ) {
error = - V_28 ;
goto V_26;
}
}
F_17 ( & V_12 -> V_29 ) ;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_22 [ V_18 ] ;
if ( V_6 -> V_23 -> type != type )
continue;
if ( F_16 ( V_6 -> V_23 -> V_24 , V_16 ) )
F_3 ( V_6 ) ;
else
F_6 ( V_6 ) ;
}
F_18 ( & V_12 -> V_29 ) ;
V_26:
F_13 ( V_16 ) ;
return error ;
}
static void F_19 ( struct V_5 * V_6 )
{
const struct V_30 * V_23 = V_6 -> V_23 ;
struct V_31 * V_32 = V_6 -> V_32 ;
unsigned int type = V_23 -> type ? : V_2 ;
int V_33 = ( F_20 ( V_23 -> V_34 ) ? 1 : 0 ) ^ V_23 -> V_35 ;
if ( type == V_36 ) {
if ( V_33 )
F_21 ( V_32 , type , V_23 -> V_24 , V_23 -> V_37 ) ;
} else {
F_21 ( V_32 , type , V_23 -> V_24 , ! ! V_33 ) ;
}
F_22 ( V_32 ) ;
}
static void F_23 ( struct V_38 * V_39 )
{
struct V_5 * V_6 =
F_24 ( V_39 , struct V_5 , V_39 ) ;
F_19 ( V_6 ) ;
}
static void F_25 ( unsigned long V_40 )
{
struct V_5 * V_6 = (struct V_5 * ) V_40 ;
F_26 ( & V_6 -> V_39 ) ;
}
static T_2 F_27 ( int V_8 , void * V_41 )
{
struct V_5 * V_6 = V_41 ;
F_2 ( V_8 != V_6 -> V_8 ) ;
if ( V_6 -> V_9 )
F_28 ( & V_6 -> V_10 ,
V_42 + F_29 ( V_6 -> V_9 ) ) ;
else
F_26 ( & V_6 -> V_39 ) ;
return V_43 ;
}
static void F_30 ( unsigned long V_40 )
{
struct V_5 * V_6 = (struct V_5 * ) V_40 ;
struct V_31 * V_32 = V_6 -> V_32 ;
unsigned long V_44 ;
F_31 ( & V_6 -> V_45 , V_44 ) ;
if ( V_6 -> V_46 ) {
F_21 ( V_32 , V_2 , V_6 -> V_23 -> V_24 , 0 ) ;
F_22 ( V_32 ) ;
V_6 -> V_46 = false ;
}
F_32 ( & V_6 -> V_45 , V_44 ) ;
}
static T_2 F_33 ( int V_8 , void * V_41 )
{
struct V_5 * V_6 = V_41 ;
const struct V_30 * V_23 = V_6 -> V_23 ;
struct V_31 * V_32 = V_6 -> V_32 ;
unsigned long V_44 ;
F_2 ( V_8 != V_6 -> V_8 ) ;
F_31 ( & V_6 -> V_45 , V_44 ) ;
if ( ! V_6 -> V_46 ) {
F_21 ( V_32 , V_2 , V_23 -> V_24 , 1 ) ;
F_22 ( V_32 ) ;
if ( ! V_6 -> V_9 ) {
F_21 ( V_32 , V_2 , V_23 -> V_24 , 0 ) ;
F_22 ( V_32 ) ;
goto V_26;
}
V_6 -> V_46 = true ;
}
if ( V_6 -> V_9 )
F_28 ( & V_6 -> V_10 ,
V_42 + F_29 ( V_6 -> V_9 ) ) ;
V_26:
F_32 ( & V_6 -> V_45 , V_44 ) ;
return V_43 ;
}
static int T_3 F_34 ( struct V_47 * V_48 ,
struct V_31 * V_32 ,
struct V_5 * V_6 ,
const struct V_30 * V_23 )
{
const char * V_49 = V_23 -> V_49 ? V_23 -> V_49 : L_1 ;
struct V_50 * V_51 = & V_48 -> V_51 ;
T_4 V_52 ;
unsigned long V_53 ;
int V_8 , error ;
V_6 -> V_32 = V_32 ;
V_6 -> V_23 = V_23 ;
F_35 ( & V_6 -> V_45 ) ;
if ( F_36 ( V_23 -> V_34 ) ) {
error = F_37 ( V_23 -> V_34 , V_49 ) ;
if ( error < 0 ) {
F_38 ( V_51 , L_2 ,
V_23 -> V_34 , error ) ;
return error ;
}
error = F_39 ( V_23 -> V_34 ) ;
if ( error < 0 ) {
F_38 ( V_51 ,
L_3 ,
V_23 -> V_34 , error ) ;
goto V_54;
}
if ( V_23 -> V_55 ) {
error = F_40 ( V_23 -> V_34 ,
V_23 -> V_55 * 1000 ) ;
if ( error < 0 )
V_6 -> V_9 =
V_23 -> V_55 ;
}
V_8 = F_41 ( V_23 -> V_34 ) ;
if ( V_8 < 0 ) {
error = V_8 ;
F_38 ( V_51 ,
L_4 ,
V_23 -> V_34 , error ) ;
goto V_54;
}
V_6 -> V_8 = V_8 ;
F_42 ( & V_6 -> V_39 , F_23 ) ;
F_43 ( & V_6 -> V_10 ,
F_25 , ( unsigned long ) V_6 ) ;
V_52 = F_27 ;
V_53 = V_56 | V_57 ;
} else {
if ( ! V_23 -> V_8 ) {
F_38 ( V_51 , L_5 ) ;
return - V_28 ;
}
V_6 -> V_8 = V_23 -> V_8 ;
if ( V_23 -> type && V_23 -> type != V_2 ) {
F_38 ( V_51 , L_6 ) ;
return - V_28 ;
}
V_6 -> V_9 = V_23 -> V_55 ;
F_43 ( & V_6 -> V_10 ,
F_30 , ( unsigned long ) V_6 ) ;
V_52 = F_33 ;
V_53 = 0 ;
}
F_44 ( V_32 , V_23 -> type ? : V_2 , V_23 -> V_24 ) ;
if ( ! V_23 -> V_27 )
V_53 |= V_58 ;
error = F_45 ( V_6 -> V_8 , V_52 , V_53 , V_49 , V_6 ) ;
if ( error < 0 ) {
F_38 ( V_51 , L_7 ,
V_6 -> V_8 , error ) ;
goto V_54;
}
return 0 ;
V_54:
if ( F_36 ( V_23 -> V_34 ) )
F_46 ( V_23 -> V_34 ) ;
return error ;
}
static int F_47 ( struct V_31 * V_32 )
{
struct V_11 * V_12 = F_48 ( V_32 ) ;
return V_12 -> V_59 ? V_12 -> V_59 ( V_32 -> V_51 . V_60 ) : 0 ;
}
static void F_49 ( struct V_31 * V_32 )
{
struct V_11 * V_12 = F_48 ( V_32 ) ;
if ( V_12 -> V_61 )
V_12 -> V_61 ( V_32 -> V_51 . V_60 ) ;
}
static int F_50 ( struct V_50 * V_51 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 , * V_66 ;
int V_18 ;
struct V_30 * V_67 ;
T_5 V_68 ;
V_65 = V_51 -> V_69 ;
if ( V_65 == NULL )
return - V_70 ;
memset ( V_63 , 0 , sizeof *V_63 ) ;
V_63 -> V_71 = ! ! F_51 ( V_65 , L_8 , NULL ) ;
V_66 = NULL ;
while ( ( V_66 = F_52 ( V_65 , V_66 ) ) )
V_63 -> V_72 ++ ;
if ( V_63 -> V_72 == 0 )
return - V_70 ;
V_67 = F_53 ( V_63 -> V_72 * ( sizeof *V_67 ) , V_19 ) ;
if ( ! V_67 )
return - V_20 ;
V_66 = NULL ;
V_18 = 0 ;
while ( ( V_66 = F_52 ( V_65 , V_66 ) ) ) {
enum V_73 V_44 ;
if ( ! F_54 ( V_66 , L_9 , NULL ) ) {
V_63 -> V_72 -- ;
F_55 ( V_51 , L_10 ) ;
continue;
}
V_67 [ V_18 ] . V_34 = F_56 ( V_66 , 0 , & V_44 ) ;
V_67 [ V_18 ] . V_35 = V_44 & V_74 ;
if ( F_57 ( V_66 , L_11 , & V_68 ) ) {
F_38 ( V_51 , L_12 , V_67 [ V_18 ] . V_34 ) ;
goto V_75;
}
V_67 [ V_18 ] . V_24 = V_68 ;
V_67 [ V_18 ] . V_49 = F_51 ( V_66 , L_13 , NULL ) ;
if ( F_57 ( V_66 , L_14 , & V_68 ) == 0 )
V_67 [ V_18 ] . type = V_68 ;
else
V_67 [ V_18 ] . type = V_2 ;
V_67 [ V_18 ] . V_76 = ! ! F_51 ( V_66 , L_15 , NULL ) ;
if ( F_57 ( V_66 , L_16 , & V_68 ) == 0 )
V_67 [ V_18 ] . V_55 = V_68 ;
else
V_67 [ V_18 ] . V_55 = 5 ;
V_18 ++ ;
}
V_63 -> V_67 = V_67 ;
return 0 ;
V_75:
F_13 ( V_67 ) ;
return - V_70 ;
}
static int F_50 ( struct V_50 * V_51 ,
struct V_62 * V_77 )
{
return - V_70 ;
}
static void F_58 ( struct V_5 * V_6 )
{
F_59 ( V_6 -> V_8 , V_6 ) ;
if ( V_6 -> V_9 )
F_5 ( & V_6 -> V_10 ) ;
F_60 ( & V_6 -> V_39 ) ;
if ( F_36 ( V_6 -> V_23 -> V_34 ) )
F_46 ( V_6 -> V_23 -> V_34 ) ;
}
static int T_3 F_61 ( struct V_47 * V_48 )
{
const struct V_62 * V_63 = V_48 -> V_51 . V_78 ;
struct V_11 * V_12 ;
struct V_50 * V_51 = & V_48 -> V_51 ;
struct V_62 V_79 ;
struct V_31 * V_32 ;
int V_18 , error ;
int V_76 = 0 ;
if ( ! V_63 ) {
error = F_50 ( V_51 , & V_79 ) ;
if ( error )
return error ;
V_63 = & V_79 ;
}
V_12 = F_53 ( sizeof( struct V_11 ) +
V_63 -> V_72 * sizeof( struct V_5 ) ,
V_19 ) ;
V_32 = F_62 () ;
if ( ! V_12 || ! V_32 ) {
F_38 ( V_51 , L_17 ) ;
error = - V_20 ;
goto V_80;
}
V_12 -> V_32 = V_32 ;
V_12 -> V_21 = V_63 -> V_72 ;
V_12 -> V_59 = V_63 -> V_59 ;
V_12 -> V_61 = V_63 -> V_61 ;
F_63 ( & V_12 -> V_29 ) ;
F_64 ( V_48 , V_12 ) ;
F_65 ( V_32 , V_12 ) ;
V_32 -> V_81 = V_63 -> V_81 ? : V_48 -> V_81 ;
V_32 -> V_82 = L_18 ;
V_32 -> V_51 . V_60 = & V_48 -> V_51 ;
V_32 -> V_83 = F_47 ;
V_32 -> V_84 = F_49 ;
V_32 -> V_85 . V_86 = V_87 ;
V_32 -> V_85 . V_88 = 0x0001 ;
V_32 -> V_85 . V_89 = 0x0001 ;
V_32 -> V_85 . V_90 = 0x0100 ;
if ( V_63 -> V_71 )
F_11 ( V_91 , V_32 -> V_92 ) ;
for ( V_18 = 0 ; V_18 < V_63 -> V_72 ; V_18 ++ ) {
const struct V_30 * V_23 = & V_63 -> V_67 [ V_18 ] ;
struct V_5 * V_6 = & V_12 -> V_22 [ V_18 ] ;
error = F_34 ( V_48 , V_32 , V_6 , V_23 ) ;
if ( error )
goto V_93;
if ( V_23 -> V_76 )
V_76 = 1 ;
}
error = F_66 ( & V_48 -> V_51 . V_94 , & V_95 ) ;
if ( error ) {
F_38 ( V_51 , L_19 ,
error ) ;
goto V_93;
}
error = F_67 ( V_32 ) ;
if ( error ) {
F_38 ( V_51 , L_20 ,
error ) ;
goto V_96;
}
for ( V_18 = 0 ; V_18 < V_63 -> V_72 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_22 [ V_18 ] ;
if ( F_36 ( V_6 -> V_23 -> V_34 ) )
F_19 ( V_6 ) ;
}
F_22 ( V_32 ) ;
F_68 ( & V_48 -> V_51 , V_76 ) ;
return 0 ;
V_96:
F_69 ( & V_48 -> V_51 . V_94 , & V_95 ) ;
V_93:
while ( -- V_18 >= 0 )
F_58 ( & V_12 -> V_22 [ V_18 ] ) ;
F_64 ( V_48 , NULL ) ;
V_80:
F_70 ( V_32 ) ;
F_13 ( V_12 ) ;
if ( ! V_48 -> V_51 . V_78 )
F_13 ( V_63 -> V_67 ) ;
return error ;
}
static int T_6 F_71 ( struct V_47 * V_48 )
{
struct V_11 * V_12 = F_72 ( V_48 ) ;
struct V_31 * V_32 = V_12 -> V_32 ;
int V_18 ;
F_69 ( & V_48 -> V_51 . V_94 , & V_95 ) ;
F_68 ( & V_48 -> V_51 , 0 ) ;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 ; V_18 ++ )
F_58 ( & V_12 -> V_22 [ V_18 ] ) ;
F_73 ( V_32 ) ;
if ( ! V_48 -> V_51 . V_78 )
F_13 ( V_12 -> V_22 [ 0 ] . V_23 ) ;
F_13 ( V_12 ) ;
return 0 ;
}
static int F_74 ( struct V_50 * V_51 )
{
struct V_11 * V_12 = F_75 ( V_51 ) ;
int V_18 ;
if ( F_76 ( V_51 ) ) {
for ( V_18 = 0 ; V_18 < V_12 -> V_21 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_22 [ V_18 ] ;
if ( V_6 -> V_23 -> V_76 )
F_77 ( V_6 -> V_8 ) ;
}
}
return 0 ;
}
static int F_78 ( struct V_50 * V_51 )
{
struct V_11 * V_12 = F_75 ( V_51 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_22 [ V_18 ] ;
if ( V_6 -> V_23 -> V_76 && F_76 ( V_51 ) )
F_79 ( V_6 -> V_8 ) ;
if ( F_36 ( V_6 -> V_23 -> V_34 ) )
F_19 ( V_6 ) ;
}
F_22 ( V_12 -> V_32 ) ;
return 0 ;
}
static int T_7 F_80 ( void )
{
return F_81 ( & V_97 ) ;
}
static void T_8 F_82 ( void )
{
F_83 ( & V_97 ) ;
}
