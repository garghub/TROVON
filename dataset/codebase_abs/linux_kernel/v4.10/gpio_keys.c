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
if ( V_10 -> V_13 )
F_6 ( & V_10 -> V_14 ) ;
else
F_7 ( & V_10 -> V_15 ) ;
V_10 -> V_11 = true ;
}
}
static void F_8 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 ) {
F_9 ( V_10 -> V_12 ) ;
V_10 -> V_11 = false ;
}
}
static T_1 F_10 ( struct V_16 * V_17 ,
char * V_18 , unsigned int type ,
bool V_19 )
{
int V_20 = F_1 ( type ) ;
unsigned long * V_21 ;
T_1 V_22 ;
int V_23 ;
V_21 = F_11 ( F_12 ( V_20 ) , sizeof( * V_21 ) , V_24 ) ;
if ( ! V_21 )
return - V_25 ;
for ( V_23 = 0 ; V_23 < V_17 -> V_26 -> V_27 ; V_23 ++ ) {
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( V_10 -> V_29 -> type != type )
continue;
if ( V_19 && ! V_10 -> V_11 )
continue;
F_13 ( V_10 -> V_29 -> V_30 , V_21 ) ;
}
V_22 = F_14 ( V_18 , V_31 - 1 , L_1 , V_20 , V_21 ) ;
V_18 [ V_22 ++ ] = '\n' ;
V_18 [ V_22 ] = '\0' ;
F_15 ( V_21 ) ;
return V_22 ;
}
static T_1 F_16 ( struct V_16 * V_17 ,
const char * V_18 , unsigned int type )
{
int V_20 = F_1 ( type ) ;
const unsigned long * V_32 = F_3 ( V_17 -> V_33 , type ) ;
unsigned long * V_21 ;
T_1 error ;
int V_23 ;
V_21 = F_11 ( F_12 ( V_20 ) , sizeof( * V_21 ) , V_24 ) ;
if ( ! V_21 )
return - V_25 ;
error = F_17 ( V_18 , V_21 , V_20 ) ;
if ( error )
goto V_34;
if ( ! F_18 ( V_21 , V_32 , V_20 ) ) {
error = - V_35 ;
goto V_34;
}
for ( V_23 = 0 ; V_23 < V_17 -> V_26 -> V_27 ; V_23 ++ ) {
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( V_10 -> V_29 -> type != type )
continue;
if ( F_19 ( V_10 -> V_29 -> V_30 , V_21 ) &&
! V_10 -> V_29 -> V_36 ) {
error = - V_35 ;
goto V_34;
}
}
F_20 ( & V_17 -> V_37 ) ;
for ( V_23 = 0 ; V_23 < V_17 -> V_26 -> V_27 ; V_23 ++ ) {
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( V_10 -> V_29 -> type != type )
continue;
if ( F_19 ( V_10 -> V_29 -> V_30 , V_21 ) )
F_4 ( V_10 ) ;
else
F_8 ( V_10 ) ;
}
F_21 ( & V_17 -> V_37 ) ;
V_34:
F_15 ( V_21 ) ;
return error ;
}
static void F_22 ( struct V_9 * V_10 )
{
const struct V_38 * V_29 = V_10 -> V_29 ;
struct V_5 * V_33 = V_10 -> V_33 ;
unsigned int type = V_29 -> type ? : V_2 ;
int V_39 ;
V_39 = F_23 ( V_10 -> V_13 ) ;
if ( V_39 < 0 ) {
F_24 ( V_33 -> V_6 . V_40 ,
L_2 , V_39 ) ;
return;
}
if ( type == V_41 ) {
if ( V_39 )
F_25 ( V_33 , type , V_29 -> V_30 , V_29 -> V_42 ) ;
} else {
F_25 ( V_33 , type , V_29 -> V_30 , V_39 ) ;
}
F_26 ( V_33 ) ;
}
static void F_27 ( struct V_43 * V_14 )
{
struct V_9 * V_10 =
F_28 ( V_14 , struct V_9 , V_14 . V_14 ) ;
F_22 ( V_10 ) ;
if ( V_10 -> V_29 -> V_44 )
F_29 ( V_10 -> V_33 -> V_6 . V_40 ) ;
}
static T_2 F_30 ( int V_12 , void * V_45 )
{
struct V_9 * V_10 = V_45 ;
F_2 ( V_12 != V_10 -> V_12 ) ;
if ( V_10 -> V_29 -> V_44 )
F_31 ( V_10 -> V_33 -> V_6 . V_40 ) ;
F_32 ( V_46 ,
& V_10 -> V_14 ,
F_33 ( V_10 -> V_47 ) ) ;
return V_48 ;
}
static void F_34 ( unsigned long V_49 )
{
struct V_9 * V_10 = (struct V_9 * ) V_49 ;
struct V_5 * V_33 = V_10 -> V_33 ;
unsigned long V_50 ;
F_35 ( & V_10 -> V_51 , V_50 ) ;
if ( V_10 -> V_52 ) {
F_25 ( V_33 , V_2 , V_10 -> V_29 -> V_30 , 0 ) ;
F_26 ( V_33 ) ;
V_10 -> V_52 = false ;
}
F_36 ( & V_10 -> V_51 , V_50 ) ;
}
static T_2 F_37 ( int V_12 , void * V_45 )
{
struct V_9 * V_10 = V_45 ;
const struct V_38 * V_29 = V_10 -> V_29 ;
struct V_5 * V_33 = V_10 -> V_33 ;
unsigned long V_50 ;
F_2 ( V_12 != V_10 -> V_12 ) ;
F_35 ( & V_10 -> V_51 , V_50 ) ;
if ( ! V_10 -> V_52 ) {
if ( V_10 -> V_29 -> V_44 )
F_38 ( V_10 -> V_33 -> V_6 . V_40 , 0 ) ;
F_25 ( V_33 , V_2 , V_29 -> V_30 , 1 ) ;
F_26 ( V_33 ) ;
if ( ! V_10 -> V_53 ) {
F_25 ( V_33 , V_2 , V_29 -> V_30 , 0 ) ;
F_26 ( V_33 ) ;
goto V_34;
}
V_10 -> V_52 = true ;
}
if ( V_10 -> V_53 )
F_39 ( & V_10 -> V_15 ,
V_54 + F_33 ( V_10 -> V_53 ) ) ;
V_34:
F_36 ( & V_10 -> V_51 , V_50 ) ;
return V_48 ;
}
static void F_40 ( void * V_28 )
{
struct V_9 * V_10 = V_28 ;
if ( V_10 -> V_13 )
F_6 ( & V_10 -> V_14 ) ;
else
F_7 ( & V_10 -> V_15 ) ;
}
static int F_41 ( struct V_55 * V_56 ,
struct V_5 * V_33 ,
struct V_9 * V_10 ,
const struct V_38 * V_29 ,
struct V_57 * V_58 )
{
const char * V_59 = V_29 -> V_59 ? V_29 -> V_59 : L_3 ;
struct V_60 * V_6 = & V_56 -> V_6 ;
T_3 V_61 ;
unsigned long V_62 ;
int V_12 ;
int error ;
V_10 -> V_33 = V_33 ;
V_10 -> V_29 = V_29 ;
F_42 ( & V_10 -> V_51 ) ;
if ( V_58 ) {
V_10 -> V_13 = F_43 ( V_6 , NULL , V_58 ) ;
if ( F_44 ( V_10 -> V_13 ) ) {
error = F_45 ( V_10 -> V_13 ) ;
if ( error == - V_63 ) {
V_10 -> V_13 = NULL ;
} else {
if ( error != - V_64 )
F_24 ( V_6 , L_4 ,
error ) ;
return error ;
}
} else {
error = F_46 ( V_10 -> V_13 ) ;
if ( error ) {
F_24 ( V_6 , L_5 ,
F_47 ( V_10 -> V_13 ) , error ) ;
return error ;
}
}
} else if ( F_48 ( V_29 -> V_65 ) ) {
unsigned V_50 = V_66 ;
if ( V_29 -> V_67 )
V_50 |= V_68 ;
error = F_49 ( & V_56 -> V_6 , V_29 -> V_65 , V_50 ,
V_59 ) ;
if ( error < 0 ) {
F_24 ( V_6 , L_6 ,
V_29 -> V_65 , error ) ;
return error ;
}
V_10 -> V_13 = F_50 ( V_29 -> V_65 ) ;
if ( ! V_10 -> V_13 )
return - V_35 ;
}
if ( V_10 -> V_13 ) {
if ( V_29 -> V_69 ) {
error = F_51 ( V_10 -> V_13 ,
V_29 -> V_69 * 1000 ) ;
if ( error < 0 )
V_10 -> V_47 =
V_29 -> V_69 ;
}
if ( V_29 -> V_12 ) {
V_10 -> V_12 = V_29 -> V_12 ;
} else {
V_12 = F_52 ( V_10 -> V_13 ) ;
if ( V_12 < 0 ) {
error = V_12 ;
F_24 ( V_6 ,
L_7 ,
V_29 -> V_65 , error ) ;
return error ;
}
V_10 -> V_12 = V_12 ;
}
F_53 ( & V_10 -> V_14 , F_27 ) ;
V_61 = F_30 ;
V_62 = V_70 | V_71 ;
} else {
if ( ! V_29 -> V_12 ) {
F_24 ( V_6 , L_8 ) ;
return - V_35 ;
}
V_10 -> V_12 = V_29 -> V_12 ;
if ( V_29 -> type && V_29 -> type != V_2 ) {
F_24 ( V_6 , L_9 ) ;
return - V_35 ;
}
V_10 -> V_53 = V_29 -> V_69 ;
F_54 ( & V_10 -> V_15 ,
F_34 , ( unsigned long ) V_10 ) ;
V_61 = F_37 ;
V_62 = 0 ;
}
F_55 ( V_33 , V_29 -> type ? : V_2 , V_29 -> V_30 ) ;
error = F_56 ( & V_56 -> V_6 , F_40 , V_10 ) ;
if ( error ) {
F_24 ( & V_56 -> V_6 ,
L_10 ,
error ) ;
return error ;
}
if ( ! V_29 -> V_36 )
V_62 |= V_72 ;
error = F_57 ( & V_56 -> V_6 , V_10 -> V_12 ,
V_61 , V_62 , V_59 , V_10 ) ;
if ( error < 0 ) {
F_24 ( V_6 , L_11 ,
V_10 -> V_12 , error ) ;
return error ;
}
return 0 ;
}
static void F_58 ( struct V_16 * V_17 )
{
struct V_5 * V_33 = V_17 -> V_33 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_17 -> V_26 -> V_27 ; V_23 ++ ) {
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( V_10 -> V_13 )
F_22 ( V_10 ) ;
}
F_26 ( V_33 ) ;
}
static int F_59 ( struct V_5 * V_33 )
{
struct V_16 * V_17 = F_60 ( V_33 ) ;
const struct V_73 * V_26 = V_17 -> V_26 ;
int error ;
if ( V_26 -> V_74 ) {
error = V_26 -> V_74 ( V_33 -> V_6 . V_40 ) ;
if ( error )
return error ;
}
F_58 ( V_17 ) ;
return 0 ;
}
static void F_61 ( struct V_5 * V_33 )
{
struct V_16 * V_17 = F_60 ( V_33 ) ;
const struct V_73 * V_26 = V_17 -> V_26 ;
if ( V_26 -> V_75 )
V_26 -> V_75 ( V_33 -> V_6 . V_40 ) ;
}
static struct V_73 *
F_62 ( struct V_60 * V_6 )
{
struct V_73 * V_26 ;
struct V_38 * V_29 ;
struct V_57 * V_58 ;
int V_27 ;
V_27 = F_63 ( V_6 ) ;
if ( V_27 == 0 )
return F_64 ( - V_76 ) ;
V_26 = F_65 ( V_6 ,
sizeof( * V_26 ) + V_27 * sizeof( * V_29 ) ,
V_24 ) ;
if ( ! V_26 )
return F_64 ( - V_25 ) ;
V_29 = (struct V_38 * ) ( V_26 + 1 ) ;
V_26 -> V_77 = V_29 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_78 = F_66 ( V_6 , L_12 ) ;
F_67 ( V_6 , L_13 , & V_26 -> V_79 ) ;
F_68 (dev, child) {
if ( F_69 ( V_58 ) )
V_29 -> V_12 =
F_70 ( F_71 ( V_58 ) , 0 ) ;
if ( F_72 ( V_58 , L_14 ,
& V_29 -> V_30 ) ) {
F_24 ( V_6 , L_15 ) ;
F_73 ( V_58 ) ;
return F_64 ( - V_35 ) ;
}
F_74 ( V_58 , L_13 , & V_29 -> V_59 ) ;
if ( F_72 ( V_58 , L_16 ,
& V_29 -> type ) )
V_29 -> type = V_2 ;
V_29 -> V_44 =
F_75 ( V_58 , L_17 ) ||
F_75 ( V_58 , L_18 ) ;
V_29 -> V_36 =
F_75 ( V_58 , L_19 ) ;
if ( F_72 ( V_58 , L_20 ,
& V_29 -> V_69 ) )
V_29 -> V_69 = 5 ;
V_29 ++ ;
}
return V_26 ;
}
static int F_76 ( struct V_55 * V_56 )
{
struct V_60 * V_6 = & V_56 -> V_6 ;
const struct V_73 * V_26 = F_77 ( V_6 ) ;
struct V_57 * V_58 = NULL ;
struct V_16 * V_17 ;
struct V_5 * V_33 ;
T_4 V_80 ;
int V_23 , error ;
int V_44 = 0 ;
if ( ! V_26 ) {
V_26 = F_62 ( V_6 ) ;
if ( F_44 ( V_26 ) )
return F_45 ( V_26 ) ;
}
V_80 = sizeof( struct V_16 ) +
V_26 -> V_27 * sizeof( struct V_9 ) ;
V_17 = F_65 ( V_6 , V_80 , V_24 ) ;
if ( ! V_17 ) {
F_24 ( V_6 , L_21 ) ;
return - V_25 ;
}
V_33 = F_78 ( V_6 ) ;
if ( ! V_33 ) {
F_24 ( V_6 , L_22 ) ;
return - V_25 ;
}
V_17 -> V_26 = V_26 ;
V_17 -> V_33 = V_33 ;
F_79 ( & V_17 -> V_37 ) ;
F_80 ( V_56 , V_17 ) ;
F_81 ( V_33 , V_17 ) ;
V_33 -> V_79 = V_26 -> V_79 ? : V_56 -> V_79 ;
V_33 -> V_81 = L_23 ;
V_33 -> V_6 . V_40 = & V_56 -> V_6 ;
V_33 -> V_82 = F_59 ;
V_33 -> V_83 = F_61 ;
V_33 -> V_84 . V_85 = V_86 ;
V_33 -> V_84 . V_87 = 0x0001 ;
V_33 -> V_84 . V_88 = 0x0001 ;
V_33 -> V_84 . V_89 = 0x0100 ;
if ( V_26 -> V_78 )
F_13 ( V_90 , V_33 -> V_91 ) ;
for ( V_23 = 0 ; V_23 < V_26 -> V_27 ; V_23 ++ ) {
const struct V_38 * V_29 = & V_26 -> V_77 [ V_23 ] ;
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( ! F_77 ( V_6 ) ) {
V_58 = F_82 ( & V_56 -> V_6 , V_58 ) ;
if ( ! V_58 ) {
F_24 ( & V_56 -> V_6 ,
L_24 ,
V_23 ) ;
return - V_35 ;
}
}
error = F_41 ( V_56 , V_33 , V_10 , V_29 , V_58 ) ;
if ( error ) {
F_73 ( V_58 ) ;
return error ;
}
if ( V_29 -> V_44 )
V_44 = 1 ;
}
F_73 ( V_58 ) ;
error = F_83 ( & V_56 -> V_6 . V_92 , & V_93 ) ;
if ( error ) {
F_24 ( V_6 , L_25 ,
error ) ;
return error ;
}
error = F_84 ( V_33 ) ;
if ( error ) {
F_24 ( V_6 , L_26 ,
error ) ;
goto V_94;
}
F_85 ( & V_56 -> V_6 , V_44 ) ;
return 0 ;
V_94:
F_86 ( & V_56 -> V_6 . V_92 , & V_93 ) ;
return error ;
}
static int F_87 ( struct V_55 * V_56 )
{
F_86 ( & V_56 -> V_6 . V_92 , & V_93 ) ;
F_85 ( & V_56 -> V_6 , 0 ) ;
return 0 ;
}
static int T_5 F_88 ( struct V_60 * V_6 )
{
struct V_16 * V_17 = F_89 ( V_6 ) ;
struct V_5 * V_33 = V_17 -> V_33 ;
int V_23 ;
if ( F_90 ( V_6 ) ) {
for ( V_23 = 0 ; V_23 < V_17 -> V_26 -> V_27 ; V_23 ++ ) {
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( V_10 -> V_29 -> V_44 )
F_91 ( V_10 -> V_12 ) ;
}
} else {
F_20 ( & V_33 -> V_95 ) ;
if ( V_33 -> V_96 )
F_61 ( V_33 ) ;
F_21 ( & V_33 -> V_95 ) ;
}
return 0 ;
}
static int T_5 F_92 ( struct V_60 * V_6 )
{
struct V_16 * V_17 = F_89 ( V_6 ) ;
struct V_5 * V_33 = V_17 -> V_33 ;
int error = 0 ;
int V_23 ;
if ( F_90 ( V_6 ) ) {
for ( V_23 = 0 ; V_23 < V_17 -> V_26 -> V_27 ; V_23 ++ ) {
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( V_10 -> V_29 -> V_44 )
F_93 ( V_10 -> V_12 ) ;
}
} else {
F_20 ( & V_33 -> V_95 ) ;
if ( V_33 -> V_96 )
error = F_59 ( V_33 ) ;
F_21 ( & V_33 -> V_95 ) ;
}
if ( error )
return error ;
F_58 ( V_17 ) ;
return 0 ;
}
static int T_6 F_94 ( void )
{
return F_95 ( & V_97 ) ;
}
static void T_7 F_96 ( void )
{
F_97 ( & V_97 ) ;
}
