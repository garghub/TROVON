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
for ( V_18 = 0 ; V_18 < V_12 -> V_21 -> V_22 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_23 [ V_18 ] ;
if ( V_6 -> V_24 -> type != type )
continue;
if ( V_14 && ! V_6 -> V_7 )
continue;
F_11 ( V_6 -> V_24 -> V_25 , V_16 ) ;
}
V_17 = F_12 ( V_13 , V_26 - 2 , V_16 , V_15 ) ;
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
goto V_27;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 -> V_22 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_23 [ V_18 ] ;
if ( V_6 -> V_24 -> type != type )
continue;
if ( F_16 ( V_6 -> V_24 -> V_25 , V_16 ) &&
! V_6 -> V_24 -> V_28 ) {
error = - V_29 ;
goto V_27;
}
}
F_17 ( & V_12 -> V_30 ) ;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 -> V_22 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_23 [ V_18 ] ;
if ( V_6 -> V_24 -> type != type )
continue;
if ( F_16 ( V_6 -> V_24 -> V_25 , V_16 ) )
F_3 ( V_6 ) ;
else
F_6 ( V_6 ) ;
}
F_18 ( & V_12 -> V_30 ) ;
V_27:
F_13 ( V_16 ) ;
return error ;
}
static void F_19 ( struct V_5 * V_6 )
{
const struct V_31 * V_24 = V_6 -> V_24 ;
struct V_32 * V_33 = V_6 -> V_33 ;
unsigned int type = V_24 -> type ? : V_2 ;
int V_34 = ( F_20 ( V_24 -> V_35 ) ? 1 : 0 ) ^ V_24 -> V_36 ;
if ( type == V_37 ) {
if ( V_34 )
F_21 ( V_33 , type , V_24 -> V_25 , V_24 -> V_38 ) ;
} else {
F_21 ( V_33 , type , V_24 -> V_25 , ! ! V_34 ) ;
}
F_22 ( V_33 ) ;
}
static void F_23 ( struct V_39 * V_40 )
{
struct V_5 * V_6 =
F_24 ( V_40 , struct V_5 , V_40 ) ;
F_19 ( V_6 ) ;
if ( V_6 -> V_24 -> V_41 )
F_25 ( V_6 -> V_33 -> V_42 . V_43 ) ;
}
static void F_26 ( unsigned long V_44 )
{
struct V_5 * V_6 = (struct V_5 * ) V_44 ;
F_27 ( & V_6 -> V_40 ) ;
}
static T_2 F_28 ( int V_8 , void * V_45 )
{
struct V_5 * V_6 = V_45 ;
F_2 ( V_8 != V_6 -> V_8 ) ;
if ( V_6 -> V_24 -> V_41 )
F_29 ( V_6 -> V_33 -> V_42 . V_43 ) ;
if ( V_6 -> V_9 )
F_30 ( & V_6 -> V_10 ,
V_46 + F_31 ( V_6 -> V_9 ) ) ;
else
F_27 ( & V_6 -> V_40 ) ;
return V_47 ;
}
static void F_32 ( unsigned long V_44 )
{
struct V_5 * V_6 = (struct V_5 * ) V_44 ;
struct V_32 * V_33 = V_6 -> V_33 ;
unsigned long V_48 ;
F_33 ( & V_6 -> V_49 , V_48 ) ;
if ( V_6 -> V_50 ) {
F_21 ( V_33 , V_2 , V_6 -> V_24 -> V_25 , 0 ) ;
F_22 ( V_33 ) ;
V_6 -> V_50 = false ;
}
F_34 ( & V_6 -> V_49 , V_48 ) ;
}
static T_2 F_35 ( int V_8 , void * V_45 )
{
struct V_5 * V_6 = V_45 ;
const struct V_31 * V_24 = V_6 -> V_24 ;
struct V_32 * V_33 = V_6 -> V_33 ;
unsigned long V_48 ;
F_2 ( V_8 != V_6 -> V_8 ) ;
F_33 ( & V_6 -> V_49 , V_48 ) ;
if ( ! V_6 -> V_50 ) {
if ( V_6 -> V_24 -> V_41 )
F_36 ( V_6 -> V_33 -> V_42 . V_43 , 0 ) ;
F_21 ( V_33 , V_2 , V_24 -> V_25 , 1 ) ;
F_22 ( V_33 ) ;
if ( ! V_6 -> V_9 ) {
F_21 ( V_33 , V_2 , V_24 -> V_25 , 0 ) ;
F_22 ( V_33 ) ;
goto V_27;
}
V_6 -> V_50 = true ;
}
if ( V_6 -> V_9 )
F_30 ( & V_6 -> V_10 ,
V_46 + F_31 ( V_6 -> V_9 ) ) ;
V_27:
F_34 ( & V_6 -> V_49 , V_48 ) ;
return V_47 ;
}
static int T_3 F_37 ( struct V_51 * V_52 ,
struct V_32 * V_33 ,
struct V_5 * V_6 ,
const struct V_31 * V_24 )
{
const char * V_53 = V_24 -> V_53 ? V_24 -> V_53 : L_1 ;
struct V_54 * V_42 = & V_52 -> V_42 ;
T_4 V_55 ;
unsigned long V_56 ;
int V_8 , error ;
V_6 -> V_33 = V_33 ;
V_6 -> V_24 = V_24 ;
F_38 ( & V_6 -> V_49 ) ;
if ( F_39 ( V_24 -> V_35 ) ) {
error = F_40 ( V_24 -> V_35 , V_53 ) ;
if ( error < 0 ) {
F_41 ( V_42 , L_2 ,
V_24 -> V_35 , error ) ;
return error ;
}
error = F_42 ( V_24 -> V_35 ) ;
if ( error < 0 ) {
F_41 ( V_42 ,
L_3 ,
V_24 -> V_35 , error ) ;
goto V_57;
}
if ( V_24 -> V_58 ) {
error = F_43 ( V_24 -> V_35 ,
V_24 -> V_58 * 1000 ) ;
if ( error < 0 )
V_6 -> V_9 =
V_24 -> V_58 ;
}
V_8 = F_44 ( V_24 -> V_35 ) ;
if ( V_8 < 0 ) {
error = V_8 ;
F_41 ( V_42 ,
L_4 ,
V_24 -> V_35 , error ) ;
goto V_57;
}
V_6 -> V_8 = V_8 ;
F_45 ( & V_6 -> V_40 , F_23 ) ;
F_46 ( & V_6 -> V_10 ,
F_26 , ( unsigned long ) V_6 ) ;
V_55 = F_28 ;
V_56 = V_59 | V_60 ;
} else {
if ( ! V_24 -> V_8 ) {
F_41 ( V_42 , L_5 ) ;
return - V_29 ;
}
V_6 -> V_8 = V_24 -> V_8 ;
if ( V_24 -> type && V_24 -> type != V_2 ) {
F_41 ( V_42 , L_6 ) ;
return - V_29 ;
}
V_6 -> V_9 = V_24 -> V_58 ;
F_46 ( & V_6 -> V_10 ,
F_32 , ( unsigned long ) V_6 ) ;
V_55 = F_35 ;
V_56 = 0 ;
}
F_47 ( V_33 , V_24 -> type ? : V_2 , V_24 -> V_25 ) ;
if ( ! V_24 -> V_28 )
V_56 |= V_61 ;
error = F_48 ( V_6 -> V_8 , V_55 , V_56 , V_53 , V_6 ) ;
if ( error < 0 ) {
F_41 ( V_42 , L_7 ,
V_6 -> V_8 , error ) ;
goto V_57;
}
return 0 ;
V_57:
if ( F_39 ( V_24 -> V_35 ) )
F_49 ( V_24 -> V_35 ) ;
return error ;
}
static int F_50 ( struct V_32 * V_33 )
{
struct V_11 * V_12 = F_51 ( V_33 ) ;
const struct V_62 * V_21 = V_12 -> V_21 ;
return V_21 -> V_63 ? V_21 -> V_63 ( V_33 -> V_42 . V_43 ) : 0 ;
}
static void F_52 ( struct V_32 * V_33 )
{
struct V_11 * V_12 = F_51 ( V_33 ) ;
const struct V_62 * V_21 = V_12 -> V_21 ;
if ( V_21 -> V_64 )
V_21 -> V_64 ( V_33 -> V_42 . V_43 ) ;
}
static struct V_62 * T_3
F_53 ( struct V_54 * V_42 )
{
struct V_65 * V_66 , * V_67 ;
struct V_62 * V_21 ;
struct V_31 * V_24 ;
int error ;
int V_22 ;
int V_18 ;
V_66 = V_42 -> V_68 ;
if ( ! V_66 ) {
error = - V_69 ;
goto V_70;
}
V_22 = F_54 ( V_66 ) ;
if ( V_22 == 0 ) {
error = - V_69 ;
goto V_70;
}
V_21 = F_55 ( sizeof( * V_21 ) + V_22 * ( sizeof *V_24 ) ,
V_19 ) ;
if ( ! V_21 ) {
error = - V_20 ;
goto V_70;
}
V_21 -> V_71 = (struct V_31 * ) ( V_21 + 1 ) ;
V_21 -> V_22 = V_22 ;
V_21 -> V_72 = ! ! F_56 ( V_66 , L_8 , NULL ) ;
V_18 = 0 ;
F_57 (node, pp) {
enum V_73 V_48 ;
if ( ! F_58 ( V_67 , L_9 , NULL ) ) {
V_21 -> V_22 -- ;
F_59 ( V_42 , L_10 ) ;
continue;
}
V_24 = & V_21 -> V_71 [ V_18 ++ ] ;
V_24 -> V_35 = F_60 ( V_67 , 0 , & V_48 ) ;
V_24 -> V_36 = V_48 & V_74 ;
if ( F_61 ( V_67 , L_11 , & V_24 -> V_25 ) ) {
F_41 ( V_42 , L_12 ,
V_24 -> V_35 ) ;
error = - V_29 ;
goto V_75;
}
V_24 -> V_53 = F_56 ( V_67 , L_13 , NULL ) ;
if ( F_61 ( V_67 , L_14 , & V_24 -> type ) )
V_24 -> type = V_2 ;
V_24 -> V_41 = ! ! F_56 ( V_67 , L_15 , NULL ) ;
if ( F_61 ( V_67 , L_16 ,
& V_24 -> V_58 ) )
V_24 -> V_58 = 5 ;
}
if ( V_21 -> V_22 == 0 ) {
error = - V_29 ;
goto V_75;
}
return V_21 ;
V_75:
F_13 ( V_21 ) ;
V_70:
return F_62 ( error ) ;
}
static inline struct V_62 *
F_53 ( struct V_54 * V_42 )
{
return F_62 ( - V_69 ) ;
}
static void F_63 ( struct V_5 * V_6 )
{
F_64 ( V_6 -> V_8 , V_6 ) ;
if ( V_6 -> V_9 )
F_5 ( & V_6 -> V_10 ) ;
F_65 ( & V_6 -> V_40 ) ;
if ( F_39 ( V_6 -> V_24 -> V_35 ) )
F_49 ( V_6 -> V_24 -> V_35 ) ;
}
static int T_3 F_66 ( struct V_51 * V_52 )
{
struct V_54 * V_42 = & V_52 -> V_42 ;
const struct V_62 * V_21 = F_67 ( V_42 ) ;
struct V_11 * V_12 ;
struct V_32 * V_33 ;
int V_18 , error ;
int V_41 = 0 ;
if ( ! V_21 ) {
V_21 = F_53 ( V_42 ) ;
if ( F_68 ( V_21 ) )
return F_69 ( V_21 ) ;
}
V_12 = F_55 ( sizeof( struct V_11 ) +
V_21 -> V_22 * sizeof( struct V_5 ) ,
V_19 ) ;
V_33 = F_70 () ;
if ( ! V_12 || ! V_33 ) {
F_41 ( V_42 , L_17 ) ;
error = - V_20 ;
goto V_76;
}
V_12 -> V_21 = V_21 ;
V_12 -> V_33 = V_33 ;
F_71 ( & V_12 -> V_30 ) ;
F_72 ( V_52 , V_12 ) ;
F_73 ( V_33 , V_12 ) ;
V_33 -> V_77 = V_21 -> V_77 ? : V_52 -> V_77 ;
V_33 -> V_78 = L_18 ;
V_33 -> V_42 . V_43 = & V_52 -> V_42 ;
V_33 -> V_79 = F_50 ;
V_33 -> V_80 = F_52 ;
V_33 -> V_81 . V_82 = V_83 ;
V_33 -> V_81 . V_84 = 0x0001 ;
V_33 -> V_81 . V_85 = 0x0001 ;
V_33 -> V_81 . V_86 = 0x0100 ;
if ( V_21 -> V_72 )
F_11 ( V_87 , V_33 -> V_88 ) ;
for ( V_18 = 0 ; V_18 < V_21 -> V_22 ; V_18 ++ ) {
const struct V_31 * V_24 = & V_21 -> V_71 [ V_18 ] ;
struct V_5 * V_6 = & V_12 -> V_23 [ V_18 ] ;
error = F_37 ( V_52 , V_33 , V_6 , V_24 ) ;
if ( error )
goto V_89;
if ( V_24 -> V_41 )
V_41 = 1 ;
}
error = F_74 ( & V_52 -> V_42 . V_90 , & V_91 ) ;
if ( error ) {
F_41 ( V_42 , L_19 ,
error ) ;
goto V_89;
}
error = F_75 ( V_33 ) ;
if ( error ) {
F_41 ( V_42 , L_20 ,
error ) ;
goto V_92;
}
for ( V_18 = 0 ; V_18 < V_21 -> V_22 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_23 [ V_18 ] ;
if ( F_39 ( V_6 -> V_24 -> V_35 ) )
F_19 ( V_6 ) ;
}
F_22 ( V_33 ) ;
F_76 ( & V_52 -> V_42 , V_41 ) ;
return 0 ;
V_92:
F_77 ( & V_52 -> V_42 . V_90 , & V_91 ) ;
V_89:
while ( -- V_18 >= 0 )
F_63 ( & V_12 -> V_23 [ V_18 ] ) ;
F_72 ( V_52 , NULL ) ;
V_76:
F_78 ( V_33 ) ;
F_13 ( V_12 ) ;
if ( ! F_67 ( & V_52 -> V_42 ) )
F_13 ( V_21 ) ;
return error ;
}
static int T_5 F_79 ( struct V_51 * V_52 )
{
struct V_11 * V_12 = F_80 ( V_52 ) ;
struct V_32 * V_33 = V_12 -> V_33 ;
int V_18 ;
F_77 ( & V_52 -> V_42 . V_90 , & V_91 ) ;
F_76 ( & V_52 -> V_42 , 0 ) ;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 -> V_22 ; V_18 ++ )
F_63 ( & V_12 -> V_23 [ V_18 ] ) ;
F_81 ( V_33 ) ;
if ( ! F_67 ( & V_52 -> V_42 ) )
F_13 ( V_12 -> V_21 ) ;
F_13 ( V_12 ) ;
return 0 ;
}
static int F_82 ( struct V_54 * V_42 )
{
struct V_11 * V_12 = F_83 ( V_42 ) ;
int V_18 ;
if ( F_84 ( V_42 ) ) {
for ( V_18 = 0 ; V_18 < V_12 -> V_21 -> V_22 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_23 [ V_18 ] ;
if ( V_6 -> V_24 -> V_41 )
F_85 ( V_6 -> V_8 ) ;
}
}
return 0 ;
}
static int F_86 ( struct V_54 * V_42 )
{
struct V_11 * V_12 = F_83 ( V_42 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_21 -> V_22 ; V_18 ++ ) {
struct V_5 * V_6 = & V_12 -> V_23 [ V_18 ] ;
if ( V_6 -> V_24 -> V_41 && F_84 ( V_42 ) )
F_87 ( V_6 -> V_8 ) ;
if ( F_39 ( V_6 -> V_24 -> V_35 ) )
F_19 ( V_6 ) ;
}
F_22 ( V_12 -> V_33 ) ;
return 0 ;
}
static int T_6 F_88 ( void )
{
return F_89 ( & V_93 ) ;
}
static void T_7 F_90 ( void )
{
F_91 ( & V_93 ) ;
}
