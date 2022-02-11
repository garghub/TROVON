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
F_13 ( * V_10 -> V_30 , V_21 ) ;
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
if ( F_19 ( * V_10 -> V_30 , V_21 ) &&
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
if ( F_19 ( * V_10 -> V_30 , V_21 ) )
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
F_25 ( V_33 , type , * V_10 -> V_30 , V_39 ) ;
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
if ( V_10 -> V_29 -> V_44 ) {
const struct V_38 * V_29 = V_10 -> V_29 ;
F_31 ( V_10 -> V_33 -> V_6 . V_40 ) ;
if ( V_10 -> V_46 &&
( V_29 -> type == 0 || V_29 -> type == V_2 ) ) {
F_32 ( V_10 -> V_33 , V_29 -> V_30 , 1 ) ;
}
}
F_33 ( V_47 ,
& V_10 -> V_14 ,
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
F_25 ( V_33 , V_2 , * V_10 -> V_30 , 0 ) ;
F_26 ( V_33 ) ;
V_10 -> V_53 = false ;
}
F_37 ( & V_10 -> V_52 , V_51 ) ;
}
static T_2 F_38 ( int V_12 , void * V_45 )
{
struct V_9 * V_10 = V_45 ;
struct V_5 * V_33 = V_10 -> V_33 ;
unsigned long V_51 ;
F_2 ( V_12 != V_10 -> V_12 ) ;
F_36 ( & V_10 -> V_52 , V_51 ) ;
if ( ! V_10 -> V_53 ) {
if ( V_10 -> V_29 -> V_44 )
F_39 ( V_10 -> V_33 -> V_6 . V_40 , 0 ) ;
F_25 ( V_33 , V_2 , * V_10 -> V_30 , 1 ) ;
F_26 ( V_33 ) ;
if ( ! V_10 -> V_54 ) {
F_25 ( V_33 , V_2 , * V_10 -> V_30 , 0 ) ;
F_26 ( V_33 ) ;
goto V_34;
}
V_10 -> V_53 = true ;
}
if ( V_10 -> V_54 )
F_40 ( & V_10 -> V_15 ,
V_55 + F_34 ( V_10 -> V_54 ) ) ;
V_34:
F_37 ( & V_10 -> V_52 , V_51 ) ;
return V_49 ;
}
static void F_41 ( void * V_28 )
{
struct V_9 * V_10 = V_28 ;
if ( V_10 -> V_13 )
F_6 ( & V_10 -> V_14 ) ;
else
F_7 ( & V_10 -> V_15 ) ;
}
static int F_42 ( struct V_56 * V_57 ,
struct V_5 * V_33 ,
struct V_16 * V_17 ,
const struct V_38 * V_29 ,
int V_58 ,
struct V_59 * V_60 )
{
const char * V_61 = V_29 -> V_61 ? V_29 -> V_61 : L_3 ;
struct V_62 * V_6 = & V_57 -> V_6 ;
struct V_9 * V_10 = & V_17 -> V_28 [ V_58 ] ;
T_3 V_63 ;
unsigned long V_64 ;
int V_12 ;
int error ;
V_10 -> V_33 = V_33 ;
V_10 -> V_29 = V_29 ;
F_43 ( & V_10 -> V_52 ) ;
if ( V_60 ) {
V_10 -> V_13 = F_44 ( V_6 , NULL ,
V_60 ,
V_65 ,
V_61 ) ;
if ( F_45 ( V_10 -> V_13 ) ) {
error = F_46 ( V_10 -> V_13 ) ;
if ( error == - V_66 ) {
V_10 -> V_13 = NULL ;
} else {
if ( error != - V_67 )
F_24 ( V_6 , L_4 ,
error ) ;
return error ;
}
}
} else if ( F_47 ( V_29 -> V_68 ) ) {
unsigned V_51 = V_69 ;
if ( V_29 -> V_70 )
V_51 |= V_71 ;
error = F_48 ( V_6 , V_29 -> V_68 , V_51 , V_61 ) ;
if ( error < 0 ) {
F_24 ( V_6 , L_5 ,
V_29 -> V_68 , error ) ;
return error ;
}
V_10 -> V_13 = F_49 ( V_29 -> V_68 ) ;
if ( ! V_10 -> V_13 )
return - V_35 ;
}
if ( V_10 -> V_13 ) {
if ( V_29 -> V_72 ) {
error = F_50 ( V_10 -> V_13 ,
V_29 -> V_72 * 1000 ) ;
if ( error < 0 )
V_10 -> V_48 =
V_29 -> V_72 ;
}
if ( V_29 -> V_12 ) {
V_10 -> V_12 = V_29 -> V_12 ;
} else {
V_12 = F_51 ( V_10 -> V_13 ) ;
if ( V_12 < 0 ) {
error = V_12 ;
F_24 ( V_6 ,
L_6 ,
V_29 -> V_68 , error ) ;
return error ;
}
V_10 -> V_12 = V_12 ;
}
F_52 ( & V_10 -> V_14 , F_27 ) ;
V_63 = F_30 ;
V_64 = V_73 | V_74 ;
} else {
if ( ! V_29 -> V_12 ) {
F_24 ( V_6 , L_7 ) ;
return - V_35 ;
}
V_10 -> V_12 = V_29 -> V_12 ;
if ( V_29 -> type && V_29 -> type != V_2 ) {
F_24 ( V_6 , L_8 ) ;
return - V_35 ;
}
V_10 -> V_54 = V_29 -> V_72 ;
F_53 ( & V_10 -> V_15 ,
F_35 , ( unsigned long ) V_10 ) ;
V_63 = F_38 ;
V_64 = 0 ;
}
V_10 -> V_30 = & V_17 -> V_75 [ V_58 ] ;
* V_10 -> V_30 = V_29 -> V_30 ;
F_54 ( V_33 , V_29 -> type ? : V_2 , * V_10 -> V_30 ) ;
error = F_55 ( V_6 , F_41 , V_10 ) ;
if ( error ) {
F_24 ( V_6 , L_9 ,
error ) ;
return error ;
}
if ( ! V_29 -> V_36 )
V_64 |= V_76 ;
error = F_56 ( V_6 , V_10 -> V_12 , V_63 , V_64 ,
V_61 , V_10 ) ;
if ( error < 0 ) {
F_24 ( V_6 , L_10 ,
V_10 -> V_12 , error ) ;
return error ;
}
return 0 ;
}
static void F_57 ( struct V_16 * V_17 )
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
static int F_58 ( struct V_5 * V_33 )
{
struct V_16 * V_17 = F_59 ( V_33 ) ;
const struct V_77 * V_26 = V_17 -> V_26 ;
int error ;
if ( V_26 -> V_78 ) {
error = V_26 -> V_78 ( V_33 -> V_6 . V_40 ) ;
if ( error )
return error ;
}
F_57 ( V_17 ) ;
return 0 ;
}
static void F_60 ( struct V_5 * V_33 )
{
struct V_16 * V_17 = F_59 ( V_33 ) ;
const struct V_77 * V_26 = V_17 -> V_26 ;
if ( V_26 -> V_79 )
V_26 -> V_79 ( V_33 -> V_6 . V_40 ) ;
}
static struct V_77 *
F_61 ( struct V_62 * V_6 )
{
struct V_77 * V_26 ;
struct V_38 * V_29 ;
struct V_59 * V_60 ;
int V_27 ;
V_27 = F_62 ( V_6 ) ;
if ( V_27 == 0 )
return F_63 ( - V_80 ) ;
V_26 = F_64 ( V_6 ,
sizeof( * V_26 ) + V_27 * sizeof( * V_29 ) ,
V_24 ) ;
if ( ! V_26 )
return F_63 ( - V_25 ) ;
V_29 = (struct V_38 * ) ( V_26 + 1 ) ;
V_26 -> V_81 = V_29 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_82 = F_65 ( V_6 , L_11 ) ;
F_66 ( V_6 , L_12 , & V_26 -> V_83 ) ;
F_67 (dev, child) {
if ( F_68 ( V_60 ) )
V_29 -> V_12 =
F_69 ( F_70 ( V_60 ) , 0 ) ;
if ( F_71 ( V_60 , L_13 ,
& V_29 -> V_30 ) ) {
F_24 ( V_6 , L_14 ) ;
F_72 ( V_60 ) ;
return F_63 ( - V_35 ) ;
}
F_73 ( V_60 , L_12 , & V_29 -> V_61 ) ;
if ( F_71 ( V_60 , L_15 ,
& V_29 -> type ) )
V_29 -> type = V_2 ;
V_29 -> V_44 =
F_74 ( V_60 , L_16 ) ||
F_74 ( V_60 , L_17 ) ;
V_29 -> V_36 =
F_74 ( V_60 , L_18 ) ;
if ( F_71 ( V_60 , L_19 ,
& V_29 -> V_72 ) )
V_29 -> V_72 = 5 ;
V_29 ++ ;
}
return V_26 ;
}
static int F_75 ( struct V_56 * V_57 )
{
struct V_62 * V_6 = & V_57 -> V_6 ;
const struct V_77 * V_26 = F_76 ( V_6 ) ;
struct V_59 * V_60 = NULL ;
struct V_16 * V_17 ;
struct V_5 * V_33 ;
T_4 V_84 ;
int V_23 , error ;
int V_44 = 0 ;
if ( ! V_26 ) {
V_26 = F_61 ( V_6 ) ;
if ( F_45 ( V_26 ) )
return F_46 ( V_26 ) ;
}
V_84 = sizeof( struct V_16 ) +
V_26 -> V_27 * sizeof( struct V_9 ) ;
V_17 = F_64 ( V_6 , V_84 , V_24 ) ;
if ( ! V_17 ) {
F_24 ( V_6 , L_20 ) ;
return - V_25 ;
}
V_17 -> V_75 = F_77 ( V_6 ,
V_26 -> V_27 , sizeof( V_17 -> V_75 [ 0 ] ) ,
V_24 ) ;
if ( ! V_17 -> V_75 )
return - V_25 ;
V_33 = F_78 ( V_6 ) ;
if ( ! V_33 ) {
F_24 ( V_6 , L_21 ) ;
return - V_25 ;
}
V_17 -> V_26 = V_26 ;
V_17 -> V_33 = V_33 ;
F_79 ( & V_17 -> V_37 ) ;
F_80 ( V_57 , V_17 ) ;
F_81 ( V_33 , V_17 ) ;
V_33 -> V_83 = V_26 -> V_83 ? : V_57 -> V_83 ;
V_33 -> V_85 = L_22 ;
V_33 -> V_6 . V_40 = V_6 ;
V_33 -> V_86 = F_58 ;
V_33 -> V_87 = F_60 ;
V_33 -> V_88 . V_89 = V_90 ;
V_33 -> V_88 . V_91 = 0x0001 ;
V_33 -> V_88 . V_92 = 0x0001 ;
V_33 -> V_88 . V_93 = 0x0100 ;
V_33 -> V_94 = V_17 -> V_75 ;
V_33 -> V_95 = sizeof( V_17 -> V_75 [ 0 ] ) ;
V_33 -> V_96 = V_26 -> V_27 ;
if ( V_26 -> V_82 )
F_13 ( V_97 , V_33 -> V_98 ) ;
for ( V_23 = 0 ; V_23 < V_26 -> V_27 ; V_23 ++ ) {
const struct V_38 * V_29 = & V_26 -> V_81 [ V_23 ] ;
if ( ! F_76 ( V_6 ) ) {
V_60 = F_82 ( V_6 , V_60 ) ;
if ( ! V_60 ) {
F_24 ( V_6 ,
L_23 ,
V_23 ) ;
return - V_35 ;
}
}
error = F_42 ( V_57 , V_33 , V_17 ,
V_29 , V_23 , V_60 ) ;
if ( error ) {
F_72 ( V_60 ) ;
return error ;
}
if ( V_29 -> V_44 )
V_44 = 1 ;
}
F_72 ( V_60 ) ;
error = F_83 ( V_6 , & V_99 ) ;
if ( error ) {
F_24 ( V_6 , L_24 ,
error ) ;
return error ;
}
error = F_84 ( V_33 ) ;
if ( error ) {
F_24 ( V_6 , L_25 ,
error ) ;
return error ;
}
F_85 ( V_6 , V_44 ) ;
return 0 ;
}
static int T_5 F_86 ( struct V_62 * V_6 )
{
struct V_16 * V_17 = F_87 ( V_6 ) ;
struct V_5 * V_33 = V_17 -> V_33 ;
int V_23 ;
if ( F_88 ( V_6 ) ) {
for ( V_23 = 0 ; V_23 < V_17 -> V_26 -> V_27 ; V_23 ++ ) {
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( V_10 -> V_29 -> V_44 )
F_89 ( V_10 -> V_12 ) ;
V_10 -> V_46 = true ;
}
} else {
F_20 ( & V_33 -> V_100 ) ;
if ( V_33 -> V_101 )
F_60 ( V_33 ) ;
F_21 ( & V_33 -> V_100 ) ;
}
return 0 ;
}
static int T_5 F_90 ( struct V_62 * V_6 )
{
struct V_16 * V_17 = F_87 ( V_6 ) ;
struct V_5 * V_33 = V_17 -> V_33 ;
int error = 0 ;
int V_23 ;
if ( F_88 ( V_6 ) ) {
for ( V_23 = 0 ; V_23 < V_17 -> V_26 -> V_27 ; V_23 ++ ) {
struct V_9 * V_10 = & V_17 -> V_28 [ V_23 ] ;
if ( V_10 -> V_29 -> V_44 )
F_91 ( V_10 -> V_12 ) ;
V_10 -> V_46 = false ;
}
} else {
F_20 ( & V_33 -> V_100 ) ;
if ( V_33 -> V_101 )
error = F_58 ( V_33 ) ;
F_21 ( & V_33 -> V_100 ) ;
}
if ( error )
return error ;
F_57 ( V_17 ) ;
return 0 ;
}
static int T_6 F_92 ( void )
{
return F_93 ( & V_102 ) ;
}
static void T_7 F_94 ( void )
{
F_95 ( & V_102 ) ;
}
