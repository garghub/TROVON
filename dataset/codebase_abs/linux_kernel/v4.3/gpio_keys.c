static inline int F_1 ( int type )
{
F_2 ( type != V_1 && type != V_2 ) ;
return ( type == V_2 ) ? V_3 : V_4 ;
}
static void F_3 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_7 ) {
F_4 ( V_6 -> V_8 ) ;
if ( F_5 ( V_6 -> V_9 -> V_10 ) )
F_6 ( & V_6 -> V_11 ) ;
else
F_7 ( & V_6 -> V_12 ) ;
V_6 -> V_7 = true ;
}
}
static void F_8 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 ) {
F_9 ( V_6 -> V_8 ) ;
V_6 -> V_7 = false ;
}
}
static T_1 F_10 ( struct V_13 * V_14 ,
char * V_15 , unsigned int type ,
bool V_16 )
{
int V_17 = F_1 ( type ) ;
unsigned long * V_18 ;
T_1 V_19 ;
int V_20 ;
V_18 = F_11 ( F_12 ( V_17 ) , sizeof( * V_18 ) , V_21 ) ;
if ( ! V_18 )
return - V_22 ;
for ( V_20 = 0 ; V_20 < V_14 -> V_23 -> V_24 ; V_20 ++ ) {
struct V_5 * V_6 = & V_14 -> V_25 [ V_20 ] ;
if ( V_6 -> V_9 -> type != type )
continue;
if ( V_16 && ! V_6 -> V_7 )
continue;
F_13 ( V_6 -> V_9 -> V_26 , V_18 ) ;
}
V_19 = F_14 ( V_15 , V_27 - 1 , L_1 , V_17 , V_18 ) ;
V_15 [ V_19 ++ ] = '\n' ;
V_15 [ V_19 ] = '\0' ;
F_15 ( V_18 ) ;
return V_19 ;
}
static T_1 F_16 ( struct V_13 * V_14 ,
const char * V_15 , unsigned int type )
{
int V_17 = F_1 ( type ) ;
unsigned long * V_18 ;
T_1 error ;
int V_20 ;
V_18 = F_11 ( F_12 ( V_17 ) , sizeof( * V_18 ) , V_21 ) ;
if ( ! V_18 )
return - V_22 ;
error = F_17 ( V_15 , V_18 , V_17 ) ;
if ( error )
goto V_28;
for ( V_20 = 0 ; V_20 < V_14 -> V_23 -> V_24 ; V_20 ++ ) {
struct V_5 * V_6 = & V_14 -> V_25 [ V_20 ] ;
if ( V_6 -> V_9 -> type != type )
continue;
if ( F_18 ( V_6 -> V_9 -> V_26 , V_18 ) &&
! V_6 -> V_9 -> V_29 ) {
error = - V_30 ;
goto V_28;
}
}
if ( V_20 == V_14 -> V_23 -> V_24 ) {
error = - V_30 ;
goto V_28;
}
F_19 ( & V_14 -> V_31 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_23 -> V_24 ; V_20 ++ ) {
struct V_5 * V_6 = & V_14 -> V_25 [ V_20 ] ;
if ( V_6 -> V_9 -> type != type )
continue;
if ( F_18 ( V_6 -> V_9 -> V_26 , V_18 ) )
F_3 ( V_6 ) ;
else
F_8 ( V_6 ) ;
}
F_20 ( & V_14 -> V_31 ) ;
V_28:
F_15 ( V_18 ) ;
return error ;
}
static void F_21 ( struct V_5 * V_6 )
{
const struct V_32 * V_9 = V_6 -> V_9 ;
struct V_33 * V_34 = V_6 -> V_34 ;
unsigned int type = V_9 -> type ? : V_2 ;
int V_35 = ( F_22 ( V_9 -> V_10 ) ? 1 : 0 ) ^ V_9 -> V_36 ;
if ( type == V_37 ) {
if ( V_35 )
F_23 ( V_34 , type , V_9 -> V_26 , V_9 -> V_38 ) ;
} else {
F_23 ( V_34 , type , V_9 -> V_26 , ! ! V_35 ) ;
}
F_24 ( V_34 ) ;
}
static void F_25 ( struct V_39 * V_11 )
{
struct V_5 * V_6 =
F_26 ( V_11 , struct V_5 , V_11 . V_11 ) ;
F_21 ( V_6 ) ;
if ( V_6 -> V_9 -> V_40 )
F_27 ( V_6 -> V_34 -> V_41 . V_42 ) ;
}
static T_2 F_28 ( int V_8 , void * V_43 )
{
struct V_5 * V_6 = V_43 ;
F_2 ( V_8 != V_6 -> V_8 ) ;
if ( V_6 -> V_9 -> V_40 )
F_29 ( V_6 -> V_34 -> V_41 . V_42 ) ;
F_30 ( V_44 ,
& V_6 -> V_11 ,
F_31 ( V_6 -> V_45 ) ) ;
return V_46 ;
}
static void F_32 ( unsigned long V_47 )
{
struct V_5 * V_6 = (struct V_5 * ) V_47 ;
struct V_33 * V_34 = V_6 -> V_34 ;
unsigned long V_48 ;
F_33 ( & V_6 -> V_49 , V_48 ) ;
if ( V_6 -> V_50 ) {
F_23 ( V_34 , V_2 , V_6 -> V_9 -> V_26 , 0 ) ;
F_24 ( V_34 ) ;
V_6 -> V_50 = false ;
}
F_34 ( & V_6 -> V_49 , V_48 ) ;
}
static T_2 F_35 ( int V_8 , void * V_43 )
{
struct V_5 * V_6 = V_43 ;
const struct V_32 * V_9 = V_6 -> V_9 ;
struct V_33 * V_34 = V_6 -> V_34 ;
unsigned long V_48 ;
F_2 ( V_8 != V_6 -> V_8 ) ;
F_33 ( & V_6 -> V_49 , V_48 ) ;
if ( ! V_6 -> V_50 ) {
if ( V_6 -> V_9 -> V_40 )
F_36 ( V_6 -> V_34 -> V_41 . V_42 , 0 ) ;
F_23 ( V_34 , V_2 , V_9 -> V_26 , 1 ) ;
F_24 ( V_34 ) ;
if ( ! V_6 -> V_51 ) {
F_23 ( V_34 , V_2 , V_9 -> V_26 , 0 ) ;
F_24 ( V_34 ) ;
goto V_28;
}
V_6 -> V_50 = true ;
}
if ( V_6 -> V_51 )
F_37 ( & V_6 -> V_12 ,
V_52 + F_31 ( V_6 -> V_51 ) ) ;
V_28:
F_34 ( & V_6 -> V_49 , V_48 ) ;
return V_46 ;
}
static void F_38 ( void * V_25 )
{
struct V_5 * V_6 = V_25 ;
if ( F_5 ( V_6 -> V_9 -> V_10 ) )
F_6 ( & V_6 -> V_11 ) ;
else
F_7 ( & V_6 -> V_12 ) ;
}
static int F_39 ( struct V_53 * V_54 ,
struct V_33 * V_34 ,
struct V_5 * V_6 ,
const struct V_32 * V_9 )
{
const char * V_55 = V_9 -> V_55 ? V_9 -> V_55 : L_2 ;
struct V_56 * V_41 = & V_54 -> V_41 ;
T_3 V_57 ;
unsigned long V_58 ;
int V_8 ;
int error ;
V_6 -> V_34 = V_34 ;
V_6 -> V_9 = V_9 ;
F_40 ( & V_6 -> V_49 ) ;
if ( F_5 ( V_9 -> V_10 ) ) {
error = F_41 ( & V_54 -> V_41 , V_9 -> V_10 ,
V_59 , V_55 ) ;
if ( error < 0 ) {
F_42 ( V_41 , L_3 ,
V_9 -> V_10 , error ) ;
return error ;
}
if ( V_9 -> V_60 ) {
error = F_43 ( V_9 -> V_10 ,
V_9 -> V_60 * 1000 ) ;
if ( error < 0 )
V_6 -> V_45 =
V_9 -> V_60 ;
}
if ( V_9 -> V_8 ) {
V_6 -> V_8 = V_9 -> V_8 ;
} else {
V_8 = F_44 ( V_9 -> V_10 ) ;
if ( V_8 < 0 ) {
error = V_8 ;
F_42 ( V_41 ,
L_4 ,
V_9 -> V_10 , error ) ;
return error ;
}
V_6 -> V_8 = V_8 ;
}
F_45 ( & V_6 -> V_11 , F_25 ) ;
V_57 = F_28 ;
V_58 = V_61 | V_62 ;
} else {
if ( ! V_9 -> V_8 ) {
F_42 ( V_41 , L_5 ) ;
return - V_30 ;
}
V_6 -> V_8 = V_9 -> V_8 ;
if ( V_9 -> type && V_9 -> type != V_2 ) {
F_42 ( V_41 , L_6 ) ;
return - V_30 ;
}
V_6 -> V_51 = V_9 -> V_60 ;
F_46 ( & V_6 -> V_12 ,
F_32 , ( unsigned long ) V_6 ) ;
V_57 = F_35 ;
V_58 = 0 ;
}
F_47 ( V_34 , V_9 -> type ? : V_2 , V_9 -> V_26 ) ;
error = F_48 ( & V_54 -> V_41 , F_38 , V_6 ) ;
if ( error ) {
F_42 ( & V_54 -> V_41 ,
L_7 ,
error ) ;
return error ;
}
if ( ! V_9 -> V_29 )
V_58 |= V_63 ;
error = F_49 ( & V_54 -> V_41 , V_6 -> V_8 ,
V_57 , V_58 , V_55 , V_6 ) ;
if ( error < 0 ) {
F_42 ( V_41 , L_8 ,
V_6 -> V_8 , error ) ;
return error ;
}
return 0 ;
}
static void F_50 ( struct V_13 * V_14 )
{
struct V_33 * V_34 = V_14 -> V_34 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_14 -> V_23 -> V_24 ; V_20 ++ ) {
struct V_5 * V_6 = & V_14 -> V_25 [ V_20 ] ;
if ( F_5 ( V_6 -> V_9 -> V_10 ) )
F_21 ( V_6 ) ;
}
F_24 ( V_34 ) ;
}
static int F_51 ( struct V_33 * V_34 )
{
struct V_13 * V_14 = F_52 ( V_34 ) ;
const struct V_64 * V_23 = V_14 -> V_23 ;
int error ;
if ( V_23 -> V_65 ) {
error = V_23 -> V_65 ( V_34 -> V_41 . V_42 ) ;
if ( error )
return error ;
}
F_50 ( V_14 ) ;
return 0 ;
}
static void F_53 ( struct V_33 * V_34 )
{
struct V_13 * V_14 = F_52 ( V_34 ) ;
const struct V_64 * V_23 = V_14 -> V_23 ;
if ( V_23 -> V_66 )
V_23 -> V_66 ( V_34 -> V_41 . V_42 ) ;
}
static struct V_64 *
F_54 ( struct V_56 * V_41 )
{
struct V_67 * V_68 , * V_69 ;
struct V_64 * V_23 ;
struct V_32 * V_9 ;
int error ;
int V_24 ;
int V_20 ;
V_68 = V_41 -> V_70 ;
if ( ! V_68 )
return F_55 ( - V_71 ) ;
V_24 = F_56 ( V_68 ) ;
if ( V_24 == 0 )
return F_55 ( - V_71 ) ;
V_23 = F_57 ( V_41 ,
sizeof( * V_23 ) + V_24 * sizeof( * V_9 ) ,
V_21 ) ;
if ( ! V_23 )
return F_55 ( - V_22 ) ;
V_23 -> V_72 = (struct V_32 * ) ( V_23 + 1 ) ;
V_23 -> V_24 = V_24 ;
V_23 -> V_73 = ! ! F_58 ( V_68 , L_9 , NULL ) ;
V_20 = 0 ;
F_59 (node, pp) {
enum V_74 V_48 ;
V_9 = & V_23 -> V_72 [ V_20 ++ ] ;
V_9 -> V_10 = F_60 ( V_69 , 0 , & V_48 ) ;
if ( V_9 -> V_10 < 0 ) {
error = V_9 -> V_10 ;
if ( error != - V_75 ) {
if ( error != - V_76 )
F_42 ( V_41 ,
L_10 ,
error ) ;
return F_55 ( error ) ;
}
} else {
V_9 -> V_36 = V_48 & V_77 ;
}
V_9 -> V_8 = F_61 ( V_69 , 0 ) ;
if ( ! F_5 ( V_9 -> V_10 ) && ! V_9 -> V_8 ) {
F_42 ( V_41 , L_11 ) ;
return F_55 ( - V_30 ) ;
}
if ( F_62 ( V_69 , L_12 , & V_9 -> V_26 ) ) {
F_42 ( V_41 , L_13 ,
V_9 -> V_10 ) ;
return F_55 ( - V_30 ) ;
}
V_9 -> V_55 = F_58 ( V_69 , L_14 , NULL ) ;
if ( F_62 ( V_69 , L_15 , & V_9 -> type ) )
V_9 -> type = V_2 ;
V_9 -> V_40 = F_63 ( V_69 , L_16 ) ||
F_63 ( V_69 , L_17 ) ;
V_9 -> V_29 = ! ! F_58 ( V_69 , L_18 , NULL ) ;
if ( F_62 ( V_69 , L_19 ,
& V_9 -> V_60 ) )
V_9 -> V_60 = 5 ;
}
if ( V_23 -> V_24 == 0 )
return F_55 ( - V_30 ) ;
return V_23 ;
}
static inline struct V_64 *
F_54 ( struct V_56 * V_41 )
{
return F_55 ( - V_71 ) ;
}
static int F_64 ( struct V_53 * V_54 )
{
struct V_56 * V_41 = & V_54 -> V_41 ;
const struct V_64 * V_23 = F_65 ( V_41 ) ;
struct V_13 * V_14 ;
struct V_33 * V_34 ;
T_4 V_78 ;
int V_20 , error ;
int V_40 = 0 ;
if ( ! V_23 ) {
V_23 = F_54 ( V_41 ) ;
if ( F_66 ( V_23 ) )
return F_67 ( V_23 ) ;
}
V_78 = sizeof( struct V_13 ) +
V_23 -> V_24 * sizeof( struct V_5 ) ;
V_14 = F_57 ( V_41 , V_78 , V_21 ) ;
if ( ! V_14 ) {
F_42 ( V_41 , L_20 ) ;
return - V_22 ;
}
V_34 = F_68 ( V_41 ) ;
if ( ! V_34 ) {
F_42 ( V_41 , L_21 ) ;
return - V_22 ;
}
V_14 -> V_23 = V_23 ;
V_14 -> V_34 = V_34 ;
F_69 ( & V_14 -> V_31 ) ;
F_70 ( V_54 , V_14 ) ;
F_71 ( V_34 , V_14 ) ;
V_34 -> V_79 = V_23 -> V_79 ? : V_54 -> V_79 ;
V_34 -> V_80 = L_22 ;
V_34 -> V_41 . V_42 = & V_54 -> V_41 ;
V_34 -> V_81 = F_51 ;
V_34 -> V_82 = F_53 ;
V_34 -> V_83 . V_84 = V_85 ;
V_34 -> V_83 . V_86 = 0x0001 ;
V_34 -> V_83 . V_87 = 0x0001 ;
V_34 -> V_83 . V_88 = 0x0100 ;
if ( V_23 -> V_73 )
F_13 ( V_89 , V_34 -> V_90 ) ;
for ( V_20 = 0 ; V_20 < V_23 -> V_24 ; V_20 ++ ) {
const struct V_32 * V_9 = & V_23 -> V_72 [ V_20 ] ;
struct V_5 * V_6 = & V_14 -> V_25 [ V_20 ] ;
error = F_39 ( V_54 , V_34 , V_6 , V_9 ) ;
if ( error )
return error ;
if ( V_9 -> V_40 )
V_40 = 1 ;
}
error = F_72 ( & V_54 -> V_41 . V_91 , & V_92 ) ;
if ( error ) {
F_42 ( V_41 , L_23 ,
error ) ;
return error ;
}
error = F_73 ( V_34 ) ;
if ( error ) {
F_42 ( V_41 , L_24 ,
error ) ;
goto V_93;
}
F_74 ( & V_54 -> V_41 , V_40 ) ;
return 0 ;
V_93:
F_75 ( & V_54 -> V_41 . V_91 , & V_92 ) ;
return error ;
}
static int F_76 ( struct V_53 * V_54 )
{
F_75 ( & V_54 -> V_41 . V_91 , & V_92 ) ;
F_74 ( & V_54 -> V_41 , 0 ) ;
return 0 ;
}
static int F_77 ( struct V_56 * V_41 )
{
struct V_13 * V_14 = F_78 ( V_41 ) ;
struct V_33 * V_34 = V_14 -> V_34 ;
int V_20 ;
if ( F_79 ( V_41 ) ) {
for ( V_20 = 0 ; V_20 < V_14 -> V_23 -> V_24 ; V_20 ++ ) {
struct V_5 * V_6 = & V_14 -> V_25 [ V_20 ] ;
if ( V_6 -> V_9 -> V_40 )
F_80 ( V_6 -> V_8 ) ;
}
} else {
F_19 ( & V_34 -> V_94 ) ;
if ( V_34 -> V_95 )
F_53 ( V_34 ) ;
F_20 ( & V_34 -> V_94 ) ;
}
return 0 ;
}
static int F_81 ( struct V_56 * V_41 )
{
struct V_13 * V_14 = F_78 ( V_41 ) ;
struct V_33 * V_34 = V_14 -> V_34 ;
int error = 0 ;
int V_20 ;
if ( F_79 ( V_41 ) ) {
for ( V_20 = 0 ; V_20 < V_14 -> V_23 -> V_24 ; V_20 ++ ) {
struct V_5 * V_6 = & V_14 -> V_25 [ V_20 ] ;
if ( V_6 -> V_9 -> V_40 )
F_82 ( V_6 -> V_8 ) ;
}
} else {
F_19 ( & V_34 -> V_94 ) ;
if ( V_34 -> V_95 )
error = F_51 ( V_34 ) ;
F_20 ( & V_34 -> V_94 ) ;
}
if ( error )
return error ;
F_50 ( V_14 ) ;
return 0 ;
}
static int T_5 F_83 ( void )
{
return F_84 ( & V_96 ) ;
}
static void T_6 F_85 ( void )
{
F_86 ( & V_96 ) ;
}
