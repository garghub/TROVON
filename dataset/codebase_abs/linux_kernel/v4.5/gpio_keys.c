static int F_1 ( int type )
{
F_2 ( type != V_1 && type != V_2 ) ;
return ( type == V_2 ) ? V_3 : V_4 ;
}
static const unsigned long * F_3 ( struct V_5 * V_6 ,
int type )
{
F_2 ( type != V_1 && type != V_2 ) ;
return ( type == V_2 ) ? V_6 -> V_7 : V_6 -> V_8 ;
}
static void F_4 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_11 ) {
F_5 ( V_10 -> V_12 ) ;
if ( F_6 ( V_10 -> V_13 -> V_14 ) )
F_7 ( & V_10 -> V_15 ) ;
else
F_8 ( & V_10 -> V_16 ) ;
V_10 -> V_11 = true ;
}
}
static void F_9 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 ) {
F_10 ( V_10 -> V_12 ) ;
V_10 -> V_11 = false ;
}
}
static T_1 F_11 ( struct V_17 * V_18 ,
char * V_19 , unsigned int type ,
bool V_20 )
{
int V_21 = F_1 ( type ) ;
unsigned long * V_22 ;
T_1 V_23 ;
int V_24 ;
V_22 = F_12 ( F_13 ( V_21 ) , sizeof( * V_22 ) , V_25 ) ;
if ( ! V_22 )
return - V_26 ;
for ( V_24 = 0 ; V_24 < V_18 -> V_27 -> V_28 ; V_24 ++ ) {
struct V_9 * V_10 = & V_18 -> V_29 [ V_24 ] ;
if ( V_10 -> V_13 -> type != type )
continue;
if ( V_20 && ! V_10 -> V_11 )
continue;
F_14 ( V_10 -> V_13 -> V_30 , V_22 ) ;
}
V_23 = F_15 ( V_19 , V_31 - 1 , L_1 , V_21 , V_22 ) ;
V_19 [ V_23 ++ ] = '\n' ;
V_19 [ V_23 ] = '\0' ;
F_16 ( V_22 ) ;
return V_23 ;
}
static T_1 F_17 ( struct V_17 * V_18 ,
const char * V_19 , unsigned int type )
{
int V_21 = F_1 ( type ) ;
const unsigned long * V_32 = F_3 ( V_18 -> V_33 , type ) ;
unsigned long * V_22 ;
T_1 error ;
int V_24 ;
V_22 = F_12 ( F_13 ( V_21 ) , sizeof( * V_22 ) , V_25 ) ;
if ( ! V_22 )
return - V_26 ;
error = F_18 ( V_19 , V_22 , V_21 ) ;
if ( error )
goto V_34;
if ( ! F_19 ( V_22 , V_32 , V_21 ) ) {
error = - V_35 ;
goto V_34;
}
for ( V_24 = 0 ; V_24 < V_18 -> V_27 -> V_28 ; V_24 ++ ) {
struct V_9 * V_10 = & V_18 -> V_29 [ V_24 ] ;
if ( V_10 -> V_13 -> type != type )
continue;
if ( F_20 ( V_10 -> V_13 -> V_30 , V_22 ) &&
! V_10 -> V_13 -> V_36 ) {
error = - V_35 ;
goto V_34;
}
}
F_21 ( & V_18 -> V_37 ) ;
for ( V_24 = 0 ; V_24 < V_18 -> V_27 -> V_28 ; V_24 ++ ) {
struct V_9 * V_10 = & V_18 -> V_29 [ V_24 ] ;
if ( V_10 -> V_13 -> type != type )
continue;
if ( F_20 ( V_10 -> V_13 -> V_30 , V_22 ) )
F_4 ( V_10 ) ;
else
F_9 ( V_10 ) ;
}
F_22 ( & V_18 -> V_37 ) ;
V_34:
F_16 ( V_22 ) ;
return error ;
}
static void F_23 ( struct V_9 * V_10 )
{
const struct V_38 * V_13 = V_10 -> V_13 ;
struct V_5 * V_33 = V_10 -> V_33 ;
unsigned int type = V_13 -> type ? : V_2 ;
int V_39 = F_24 ( V_13 -> V_14 ) ;
if ( V_39 < 0 ) {
F_25 ( V_33 -> V_6 . V_40 , L_2 ) ;
return;
}
V_39 = ( V_39 ? 1 : 0 ) ^ V_13 -> V_41 ;
if ( type == V_42 ) {
if ( V_39 )
F_26 ( V_33 , type , V_13 -> V_30 , V_13 -> V_43 ) ;
} else {
F_26 ( V_33 , type , V_13 -> V_30 , ! ! V_39 ) ;
}
F_27 ( V_33 ) ;
}
static void F_28 ( struct V_44 * V_15 )
{
struct V_9 * V_10 =
F_29 ( V_15 , struct V_9 , V_15 . V_15 ) ;
F_23 ( V_10 ) ;
if ( V_10 -> V_13 -> V_45 )
F_30 ( V_10 -> V_33 -> V_6 . V_40 ) ;
}
static T_2 F_31 ( int V_12 , void * V_46 )
{
struct V_9 * V_10 = V_46 ;
F_2 ( V_12 != V_10 -> V_12 ) ;
if ( V_10 -> V_13 -> V_45 )
F_32 ( V_10 -> V_33 -> V_6 . V_40 ) ;
F_33 ( V_47 ,
& V_10 -> V_15 ,
F_34 ( V_10 -> V_48 ) ) ;
return V_49 ;
}
static void F_35 ( unsigned long V_50 )
{
struct V_9 * V_10 = (struct V_9 * ) V_50 ;
struct V_5 * V_33 = V_10 -> V_33 ;
unsigned long V_51 ;
F_36 ( & V_10 -> V_52 , V_51 ) ;
if ( V_10 -> V_53 ) {
F_26 ( V_33 , V_2 , V_10 -> V_13 -> V_30 , 0 ) ;
F_27 ( V_33 ) ;
V_10 -> V_53 = false ;
}
F_37 ( & V_10 -> V_52 , V_51 ) ;
}
static T_2 F_38 ( int V_12 , void * V_46 )
{
struct V_9 * V_10 = V_46 ;
const struct V_38 * V_13 = V_10 -> V_13 ;
struct V_5 * V_33 = V_10 -> V_33 ;
unsigned long V_51 ;
F_2 ( V_12 != V_10 -> V_12 ) ;
F_36 ( & V_10 -> V_52 , V_51 ) ;
if ( ! V_10 -> V_53 ) {
if ( V_10 -> V_13 -> V_45 )
F_39 ( V_10 -> V_33 -> V_6 . V_40 , 0 ) ;
F_26 ( V_33 , V_2 , V_13 -> V_30 , 1 ) ;
F_27 ( V_33 ) ;
if ( ! V_10 -> V_54 ) {
F_26 ( V_33 , V_2 , V_13 -> V_30 , 0 ) ;
F_27 ( V_33 ) ;
goto V_34;
}
V_10 -> V_53 = true ;
}
if ( V_10 -> V_54 )
F_40 ( & V_10 -> V_16 ,
V_55 + F_34 ( V_10 -> V_54 ) ) ;
V_34:
F_37 ( & V_10 -> V_52 , V_51 ) ;
return V_49 ;
}
static void F_41 ( void * V_29 )
{
struct V_9 * V_10 = V_29 ;
if ( F_6 ( V_10 -> V_13 -> V_14 ) )
F_7 ( & V_10 -> V_15 ) ;
else
F_8 ( & V_10 -> V_16 ) ;
}
static int F_42 ( struct V_56 * V_57 ,
struct V_5 * V_33 ,
struct V_9 * V_10 ,
const struct V_38 * V_13 )
{
const char * V_58 = V_13 -> V_58 ? V_13 -> V_58 : L_3 ;
struct V_59 * V_6 = & V_57 -> V_6 ;
T_3 V_60 ;
unsigned long V_61 ;
int V_12 ;
int error ;
V_10 -> V_33 = V_33 ;
V_10 -> V_13 = V_13 ;
F_43 ( & V_10 -> V_52 ) ;
if ( F_6 ( V_13 -> V_14 ) ) {
error = F_44 ( & V_57 -> V_6 , V_13 -> V_14 ,
V_62 , V_58 ) ;
if ( error < 0 ) {
F_25 ( V_6 , L_4 ,
V_13 -> V_14 , error ) ;
return error ;
}
if ( V_13 -> V_63 ) {
error = F_45 ( V_13 -> V_14 ,
V_13 -> V_63 * 1000 ) ;
if ( error < 0 )
V_10 -> V_48 =
V_13 -> V_63 ;
}
if ( V_13 -> V_12 ) {
V_10 -> V_12 = V_13 -> V_12 ;
} else {
V_12 = F_46 ( V_13 -> V_14 ) ;
if ( V_12 < 0 ) {
error = V_12 ;
F_25 ( V_6 ,
L_5 ,
V_13 -> V_14 , error ) ;
return error ;
}
V_10 -> V_12 = V_12 ;
}
F_47 ( & V_10 -> V_15 , F_28 ) ;
V_60 = F_31 ;
V_61 = V_64 | V_65 ;
} else {
if ( ! V_13 -> V_12 ) {
F_25 ( V_6 , L_6 ) ;
return - V_35 ;
}
V_10 -> V_12 = V_13 -> V_12 ;
if ( V_13 -> type && V_13 -> type != V_2 ) {
F_25 ( V_6 , L_7 ) ;
return - V_35 ;
}
V_10 -> V_54 = V_13 -> V_63 ;
F_48 ( & V_10 -> V_16 ,
F_35 , ( unsigned long ) V_10 ) ;
V_60 = F_38 ;
V_61 = 0 ;
}
F_49 ( V_33 , V_13 -> type ? : V_2 , V_13 -> V_30 ) ;
error = F_50 ( & V_57 -> V_6 , F_41 , V_10 ) ;
if ( error ) {
F_25 ( & V_57 -> V_6 ,
L_8 ,
error ) ;
return error ;
}
if ( ! V_13 -> V_36 )
V_61 |= V_66 ;
error = F_51 ( & V_57 -> V_6 , V_10 -> V_12 ,
V_60 , V_61 , V_58 , V_10 ) ;
if ( error < 0 ) {
F_25 ( V_6 , L_9 ,
V_10 -> V_12 , error ) ;
return error ;
}
return 0 ;
}
static void F_52 ( struct V_17 * V_18 )
{
struct V_5 * V_33 = V_18 -> V_33 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_18 -> V_27 -> V_28 ; V_24 ++ ) {
struct V_9 * V_10 = & V_18 -> V_29 [ V_24 ] ;
if ( F_6 ( V_10 -> V_13 -> V_14 ) )
F_23 ( V_10 ) ;
}
F_27 ( V_33 ) ;
}
static int F_53 ( struct V_5 * V_33 )
{
struct V_17 * V_18 = F_54 ( V_33 ) ;
const struct V_67 * V_27 = V_18 -> V_27 ;
int error ;
if ( V_27 -> V_68 ) {
error = V_27 -> V_68 ( V_33 -> V_6 . V_40 ) ;
if ( error )
return error ;
}
F_52 ( V_18 ) ;
return 0 ;
}
static void F_55 ( struct V_5 * V_33 )
{
struct V_17 * V_18 = F_54 ( V_33 ) ;
const struct V_67 * V_27 = V_18 -> V_27 ;
if ( V_27 -> V_69 )
V_27 -> V_69 ( V_33 -> V_6 . V_40 ) ;
}
static struct V_67 *
F_56 ( struct V_59 * V_6 )
{
struct V_70 * V_71 , * V_72 ;
struct V_67 * V_27 ;
struct V_38 * V_13 ;
int error ;
int V_28 ;
int V_24 ;
V_71 = V_6 -> V_73 ;
if ( ! V_71 )
return F_57 ( - V_74 ) ;
V_28 = F_58 ( V_71 ) ;
if ( V_28 == 0 )
return F_57 ( - V_74 ) ;
V_27 = F_59 ( V_6 ,
sizeof( * V_27 ) + V_28 * sizeof( * V_13 ) ,
V_25 ) ;
if ( ! V_27 )
return F_57 ( - V_26 ) ;
V_27 -> V_75 = (struct V_38 * ) ( V_27 + 1 ) ;
V_27 -> V_28 = V_28 ;
V_27 -> V_76 = ! ! F_60 ( V_71 , L_10 , NULL ) ;
F_61 ( V_71 , L_11 , & V_27 -> V_77 ) ;
V_24 = 0 ;
F_62 (node, pp) {
enum V_78 V_51 ;
V_13 = & V_27 -> V_75 [ V_24 ++ ] ;
V_13 -> V_14 = F_63 ( V_72 , 0 , & V_51 ) ;
if ( V_13 -> V_14 < 0 ) {
error = V_13 -> V_14 ;
if ( error != - V_79 ) {
if ( error != - V_80 )
F_25 ( V_6 ,
L_12 ,
error ) ;
return F_57 ( error ) ;
}
} else {
V_13 -> V_41 = V_51 & V_81 ;
}
V_13 -> V_12 = F_64 ( V_72 , 0 ) ;
if ( ! F_6 ( V_13 -> V_14 ) && ! V_13 -> V_12 ) {
F_25 ( V_6 , L_13 ) ;
return F_57 ( - V_35 ) ;
}
if ( F_65 ( V_72 , L_14 , & V_13 -> V_30 ) ) {
F_25 ( V_6 , L_15 ,
V_13 -> V_14 ) ;
return F_57 ( - V_35 ) ;
}
V_13 -> V_58 = F_60 ( V_72 , L_11 , NULL ) ;
if ( F_65 ( V_72 , L_16 , & V_13 -> type ) )
V_13 -> type = V_2 ;
V_13 -> V_45 = F_66 ( V_72 , L_17 ) ||
F_66 ( V_72 , L_18 ) ;
V_13 -> V_36 = ! ! F_60 ( V_72 , L_19 , NULL ) ;
if ( F_65 ( V_72 , L_20 ,
& V_13 -> V_63 ) )
V_13 -> V_63 = 5 ;
}
if ( V_27 -> V_28 == 0 )
return F_57 ( - V_35 ) ;
return V_27 ;
}
static inline struct V_67 *
F_56 ( struct V_59 * V_6 )
{
return F_57 ( - V_74 ) ;
}
static int F_67 ( struct V_56 * V_57 )
{
struct V_59 * V_6 = & V_57 -> V_6 ;
const struct V_67 * V_27 = F_68 ( V_6 ) ;
struct V_17 * V_18 ;
struct V_5 * V_33 ;
T_4 V_82 ;
int V_24 , error ;
int V_45 = 0 ;
if ( ! V_27 ) {
V_27 = F_56 ( V_6 ) ;
if ( F_69 ( V_27 ) )
return F_70 ( V_27 ) ;
}
V_82 = sizeof( struct V_17 ) +
V_27 -> V_28 * sizeof( struct V_9 ) ;
V_18 = F_59 ( V_6 , V_82 , V_25 ) ;
if ( ! V_18 ) {
F_25 ( V_6 , L_21 ) ;
return - V_26 ;
}
V_33 = F_71 ( V_6 ) ;
if ( ! V_33 ) {
F_25 ( V_6 , L_22 ) ;
return - V_26 ;
}
V_18 -> V_27 = V_27 ;
V_18 -> V_33 = V_33 ;
F_72 ( & V_18 -> V_37 ) ;
F_73 ( V_57 , V_18 ) ;
F_74 ( V_33 , V_18 ) ;
V_33 -> V_77 = V_27 -> V_77 ? : V_57 -> V_77 ;
V_33 -> V_83 = L_23 ;
V_33 -> V_6 . V_40 = & V_57 -> V_6 ;
V_33 -> V_84 = F_53 ;
V_33 -> V_85 = F_55 ;
V_33 -> V_86 . V_87 = V_88 ;
V_33 -> V_86 . V_89 = 0x0001 ;
V_33 -> V_86 . V_90 = 0x0001 ;
V_33 -> V_86 . V_91 = 0x0100 ;
if ( V_27 -> V_76 )
F_14 ( V_92 , V_33 -> V_93 ) ;
for ( V_24 = 0 ; V_24 < V_27 -> V_28 ; V_24 ++ ) {
const struct V_38 * V_13 = & V_27 -> V_75 [ V_24 ] ;
struct V_9 * V_10 = & V_18 -> V_29 [ V_24 ] ;
error = F_42 ( V_57 , V_33 , V_10 , V_13 ) ;
if ( error )
return error ;
if ( V_13 -> V_45 )
V_45 = 1 ;
}
error = F_75 ( & V_57 -> V_6 . V_94 , & V_95 ) ;
if ( error ) {
F_25 ( V_6 , L_24 ,
error ) ;
return error ;
}
error = F_76 ( V_33 ) ;
if ( error ) {
F_25 ( V_6 , L_25 ,
error ) ;
goto V_96;
}
F_77 ( & V_57 -> V_6 , V_45 ) ;
return 0 ;
V_96:
F_78 ( & V_57 -> V_6 . V_94 , & V_95 ) ;
return error ;
}
static int F_79 ( struct V_56 * V_57 )
{
F_78 ( & V_57 -> V_6 . V_94 , & V_95 ) ;
F_77 ( & V_57 -> V_6 , 0 ) ;
return 0 ;
}
static int F_80 ( struct V_59 * V_6 )
{
struct V_17 * V_18 = F_81 ( V_6 ) ;
struct V_5 * V_33 = V_18 -> V_33 ;
int V_24 ;
if ( F_82 ( V_6 ) ) {
for ( V_24 = 0 ; V_24 < V_18 -> V_27 -> V_28 ; V_24 ++ ) {
struct V_9 * V_10 = & V_18 -> V_29 [ V_24 ] ;
if ( V_10 -> V_13 -> V_45 )
F_83 ( V_10 -> V_12 ) ;
}
} else {
F_21 ( & V_33 -> V_97 ) ;
if ( V_33 -> V_98 )
F_55 ( V_33 ) ;
F_22 ( & V_33 -> V_97 ) ;
}
return 0 ;
}
static int F_84 ( struct V_59 * V_6 )
{
struct V_17 * V_18 = F_81 ( V_6 ) ;
struct V_5 * V_33 = V_18 -> V_33 ;
int error = 0 ;
int V_24 ;
if ( F_82 ( V_6 ) ) {
for ( V_24 = 0 ; V_24 < V_18 -> V_27 -> V_28 ; V_24 ++ ) {
struct V_9 * V_10 = & V_18 -> V_29 [ V_24 ] ;
if ( V_10 -> V_13 -> V_45 )
F_85 ( V_10 -> V_12 ) ;
}
} else {
F_21 ( & V_33 -> V_97 ) ;
if ( V_33 -> V_98 )
error = F_53 ( V_33 ) ;
F_22 ( & V_33 -> V_97 ) ;
}
if ( error )
return error ;
F_52 ( V_18 ) ;
return 0 ;
}
static int T_5 F_86 ( void )
{
return F_87 ( & V_99 ) ;
}
static void T_6 F_88 ( void )
{
F_89 ( & V_99 ) ;
}
