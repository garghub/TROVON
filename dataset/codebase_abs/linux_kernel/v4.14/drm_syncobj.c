struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 ( & V_3 -> V_6 ) ;
V_5 = F_3 ( & V_3 -> V_7 , V_4 ) ;
if ( V_5 )
F_4 ( V_5 ) ;
F_5 ( & V_3 -> V_6 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_5 ,
struct V_8 * V_9 ,
T_2 V_10 )
{
V_9 -> V_10 = V_10 ;
F_7 ( & V_9 -> V_11 , & V_5 -> V_12 ) ;
}
static int F_8 ( struct V_1 * V_5 ,
struct V_13 * * V_14 ,
struct V_8 * V_9 ,
T_2 V_10 )
{
int V_15 ;
* V_14 = F_9 ( V_5 ) ;
if ( * V_14 )
return 1 ;
F_2 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_14 ) {
* V_14 = F_10 ( V_5 -> V_14 ) ;
V_15 = 1 ;
} else {
* V_14 = NULL ;
F_6 ( V_5 , V_9 , V_10 ) ;
V_15 = 0 ;
}
F_5 ( & V_5 -> V_16 ) ;
return V_15 ;
}
void F_11 ( struct V_1 * V_5 ,
struct V_8 * V_9 ,
T_2 V_10 )
{
F_2 ( & V_5 -> V_16 ) ;
F_6 ( V_5 , V_9 , V_10 ) ;
F_5 ( & V_5 -> V_16 ) ;
}
void F_12 ( struct V_1 * V_5 ,
struct V_8 * V_9 )
{
F_2 ( & V_5 -> V_16 ) ;
F_13 ( & V_9 -> V_11 ) ;
F_5 ( & V_5 -> V_16 ) ;
}
void F_14 ( struct V_1 * V_5 ,
struct V_13 * V_14 )
{
struct V_13 * V_17 ;
struct V_8 * V_18 , * V_19 ;
if ( V_14 )
F_10 ( V_14 ) ;
F_2 ( & V_5 -> V_16 ) ;
V_17 = V_5 -> V_14 ;
V_5 -> V_14 = V_14 ;
if ( V_14 != V_17 ) {
F_15 (cur, tmp, &syncobj->cb_list, node) {
F_13 ( & V_18 -> V_11 ) ;
V_18 -> V_10 ( V_5 , V_18 ) ;
}
}
F_5 ( & V_5 -> V_16 ) ;
F_16 ( V_17 ) ;
}
static const char * F_17 ( struct V_13 * V_14 )
{
return L_1 ;
}
static bool F_18 ( struct V_13 * V_14 )
{
F_19 ( V_14 ) ;
return ! F_20 ( V_14 ) ;
}
static int F_21 ( struct V_1 * V_5 )
{
struct V_20 * V_14 ;
V_14 = F_22 ( sizeof( * V_14 ) , V_21 ) ;
if ( V_14 == NULL )
return - V_22 ;
F_23 ( & V_14 -> V_16 ) ;
F_24 ( & V_14 -> V_23 , & V_24 ,
& V_14 -> V_16 , 0 , 0 ) ;
F_25 ( & V_14 -> V_23 ) ;
F_14 ( V_5 , & V_14 -> V_23 ) ;
F_16 ( & V_14 -> V_23 ) ;
return 0 ;
}
int F_26 ( struct V_2 * V_3 ,
T_1 V_4 ,
struct V_13 * * V_14 )
{
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
int V_15 = 0 ;
if ( ! V_5 )
return - V_25 ;
* V_14 = F_9 ( V_5 ) ;
if ( ! * V_14 ) {
V_15 = - V_26 ;
}
F_27 ( V_5 ) ;
return V_15 ;
}
void F_28 ( struct V_27 * V_27 )
{
struct V_1 * V_5 = F_29 ( V_27 ,
struct V_1 ,
V_28 ) ;
F_14 ( V_5 , NULL ) ;
F_30 ( V_5 ) ;
}
static int F_31 ( struct V_2 * V_3 ,
T_1 * V_4 , T_3 V_29 )
{
int V_15 ;
struct V_1 * V_5 ;
V_5 = F_22 ( sizeof( struct V_1 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
F_32 ( & V_5 -> V_28 ) ;
F_33 ( & V_5 -> V_12 ) ;
F_23 ( & V_5 -> V_16 ) ;
if ( V_29 & V_30 ) {
V_15 = F_21 ( V_5 ) ;
if ( V_15 < 0 ) {
F_27 ( V_5 ) ;
return V_15 ;
}
}
F_34 ( V_21 ) ;
F_2 ( & V_3 -> V_6 ) ;
V_15 = F_35 ( & V_3 -> V_7 , V_5 , 1 , 0 , V_31 ) ;
F_5 ( & V_3 -> V_6 ) ;
F_36 () ;
if ( V_15 < 0 ) {
F_27 ( V_5 ) ;
return V_15 ;
}
* V_4 = V_15 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 ( & V_3 -> V_6 ) ;
V_5 = F_38 ( & V_3 -> V_7 , V_4 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( ! V_5 )
return - V_26 ;
F_27 ( V_5 ) ;
return 0 ;
}
static int F_39 ( struct V_32 * V_32 , struct V_33 * V_33 )
{
struct V_1 * V_5 = V_33 -> V_34 ;
F_27 ( V_5 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_5 )
{
struct V_33 * V_33 = F_41 ( L_2 ,
& V_35 ,
V_5 , 0 ) ;
if ( F_42 ( V_33 ) )
return F_43 ( V_33 ) ;
F_4 ( V_5 ) ;
if ( F_44 ( & V_5 -> V_33 , NULL , V_33 ) ) {
F_45 ( V_33 ) ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 ,
T_1 V_4 , int * V_36 )
{
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
int V_15 ;
int V_37 ;
if ( ! V_5 )
return - V_26 ;
V_37 = F_47 ( V_38 ) ;
if ( V_37 < 0 ) {
F_27 ( V_5 ) ;
return V_37 ;
}
if ( ! V_5 -> V_33 ) {
V_15 = F_40 ( V_5 ) ;
if ( V_15 )
goto V_39;
}
F_48 ( V_37 , V_5 -> V_33 ) ;
F_27 ( V_5 ) ;
* V_36 = V_37 ;
return 0 ;
V_39:
F_49 ( V_37 ) ;
F_27 ( V_5 ) ;
return V_15 ;
}
static struct V_1 * F_50 ( int V_37 )
{
struct V_33 * V_33 = F_51 ( V_37 ) ;
if ( ! V_33 )
return NULL ;
if ( V_33 -> V_40 != & V_35 )
goto V_41;
return V_33 -> V_34 ;
V_41:
F_45 ( V_33 ) ;
return NULL ;
}
static int F_52 ( struct V_2 * V_3 ,
int V_37 , T_1 * V_4 )
{
struct V_1 * V_5 = F_50 ( V_37 ) ;
int V_15 ;
if ( ! V_5 )
return - V_26 ;
F_4 ( V_5 ) ;
F_34 ( V_21 ) ;
F_2 ( & V_3 -> V_6 ) ;
V_15 = F_35 ( & V_3 -> V_7 , V_5 , 1 , 0 , V_31 ) ;
F_5 ( & V_3 -> V_6 ) ;
F_36 () ;
if ( V_15 < 0 ) {
F_45 ( V_5 -> V_33 ) ;
return V_15 ;
}
* V_4 = V_15 ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 ,
int V_37 , int V_4 )
{
struct V_13 * V_14 = F_54 ( V_37 ) ;
struct V_1 * V_5 ;
if ( ! V_14 )
return - V_26 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_16 ( V_14 ) ;
return - V_25 ;
}
F_14 ( V_5 , V_14 ) ;
F_16 ( V_14 ) ;
F_27 ( V_5 ) ;
return 0 ;
}
int F_55 ( struct V_2 * V_3 ,
int V_4 , int * V_36 )
{
int V_15 ;
struct V_13 * V_14 ;
struct V_42 * V_42 ;
int V_37 = F_47 ( V_38 ) ;
if ( V_37 < 0 )
return V_37 ;
V_15 = F_26 ( V_3 , V_4 , & V_14 ) ;
if ( V_15 )
goto V_43;
V_42 = F_56 ( V_14 ) ;
F_16 ( V_14 ) ;
if ( ! V_42 ) {
V_15 = - V_26 ;
goto V_43;
}
F_48 ( V_37 , V_42 -> V_33 ) ;
* V_36 = V_37 ;
return 0 ;
V_43:
F_49 ( V_37 ) ;
return V_15 ;
}
void
F_57 ( struct V_2 * V_3 )
{
F_58 ( & V_3 -> V_7 ) ;
F_23 ( & V_3 -> V_6 ) ;
}
static int
F_59 ( int V_44 , void * V_45 , void * V_46 )
{
struct V_1 * V_5 = V_45 ;
F_27 ( V_5 ) ;
return 0 ;
}
void
F_60 ( struct V_2 * V_3 )
{
F_61 ( & V_3 -> V_7 ,
& F_59 , V_3 ) ;
F_62 ( & V_3 -> V_7 ) ;
}
int
F_63 ( struct V_47 * V_48 , void * V_46 ,
struct V_2 * V_3 )
{
struct F_31 * args = V_46 ;
if ( ! F_64 ( V_48 , V_49 ) )
return - V_50 ;
if ( args -> V_29 & ~ V_30 )
return - V_26 ;
return F_31 ( V_3 ,
& args -> V_4 , args -> V_29 ) ;
}
int
F_65 ( struct V_47 * V_48 , void * V_46 ,
struct V_2 * V_3 )
{
struct F_37 * args = V_46 ;
if ( ! F_64 ( V_48 , V_49 ) )
return - V_50 ;
if ( args -> V_51 )
return - V_26 ;
return F_37 ( V_3 , args -> V_4 ) ;
}
int
F_66 ( struct V_47 * V_48 , void * V_46 ,
struct V_2 * V_3 )
{
struct V_52 * args = V_46 ;
if ( ! F_64 ( V_48 , V_49 ) )
return - V_50 ;
if ( args -> V_51 )
return - V_26 ;
if ( args -> V_29 != 0 &&
args -> V_29 != V_53 )
return - V_26 ;
if ( args -> V_29 & V_53 )
return F_55 ( V_3 , args -> V_4 ,
& args -> V_37 ) ;
return F_46 ( V_3 , args -> V_4 ,
& args -> V_37 ) ;
}
int
F_67 ( struct V_47 * V_48 , void * V_46 ,
struct V_2 * V_3 )
{
struct V_52 * args = V_46 ;
if ( ! F_64 ( V_48 , V_49 ) )
return - V_50 ;
if ( args -> V_51 )
return - V_26 ;
if ( args -> V_29 != 0 &&
args -> V_29 != V_54 )
return - V_26 ;
if ( args -> V_29 & V_54 )
return F_53 ( V_3 ,
args -> V_37 ,
args -> V_4 ) ;
return F_52 ( V_3 , args -> V_37 ,
& args -> V_4 ) ;
}
static void F_68 ( struct V_13 * V_14 ,
struct V_55 * V_9 )
{
struct V_56 * V_57 =
F_29 ( V_9 , struct V_56 , V_58 ) ;
F_69 ( V_57 -> V_59 ) ;
}
static void F_70 ( struct V_1 * V_5 ,
struct V_8 * V_9 )
{
struct V_56 * V_57 =
F_29 ( V_9 , struct V_56 , V_60 ) ;
V_57 -> V_14 = F_10 ( V_5 -> V_14 ) ;
F_69 ( V_57 -> V_59 ) ;
}
static signed long F_71 ( struct V_1 * * V_61 ,
T_3 V_62 ,
T_3 V_29 ,
signed long V_63 ,
T_3 * V_64 )
{
struct V_56 * V_65 ;
struct V_13 * V_14 ;
signed long V_15 ;
T_3 V_66 , V_67 ;
V_65 = F_72 ( V_62 , sizeof( * V_65 ) , V_21 ) ;
if ( ! V_65 )
return - V_22 ;
V_66 = 0 ;
for ( V_67 = 0 ; V_67 < V_62 ; ++ V_67 ) {
V_65 [ V_67 ] . V_59 = V_68 ;
V_65 [ V_67 ] . V_14 = F_9 ( V_61 [ V_67 ] ) ;
if ( ! V_65 [ V_67 ] . V_14 ) {
if ( V_29 & V_69 ) {
continue;
} else {
V_15 = - V_26 ;
goto V_70;
}
}
if ( F_20 ( V_65 [ V_67 ] . V_14 ) ) {
if ( V_66 == 0 && V_64 )
* V_64 = V_67 ;
V_66 ++ ;
}
}
V_15 = F_73 (signed long, timeout, 1 ) ;
if ( V_66 == V_62 ||
( V_66 > 0 &&
! ( V_29 & V_71 ) ) )
goto V_70;
if ( V_29 & V_69 ) {
for ( V_67 = 0 ; V_67 < V_62 ; ++ V_67 ) {
F_8 ( V_61 [ V_67 ] ,
& V_65 [ V_67 ] . V_14 ,
& V_65 [ V_67 ] . V_60 ,
F_70 ) ;
}
}
do {
F_74 ( V_72 ) ;
V_66 = 0 ;
for ( V_67 = 0 ; V_67 < V_62 ; ++ V_67 ) {
V_14 = V_65 [ V_67 ] . V_14 ;
if ( ! V_14 )
continue;
if ( F_20 ( V_14 ) ||
( ! V_65 [ V_67 ] . V_58 . V_10 &&
F_75 ( V_14 ,
& V_65 [ V_67 ] . V_58 ,
F_68 ) ) ) {
if ( V_29 & V_71 ) {
V_66 ++ ;
} else {
if ( V_64 )
* V_64 = V_67 ;
goto V_73;
}
}
}
if ( V_66 == V_62 )
goto V_73;
if ( V_63 == 0 ) {
V_15 = 0 ;
goto V_73;
}
V_15 = F_76 ( V_15 ) ;
if ( V_15 > 0 && F_77 ( V_68 ) )
V_15 = - V_74 ;
} while ( V_15 > 0 );
V_73:
F_78 ( V_75 ) ;
V_70:
for ( V_67 = 0 ; V_67 < V_62 ; ++ V_67 ) {
if ( V_65 [ V_67 ] . V_60 . V_10 )
F_12 ( V_61 [ V_67 ] ,
& V_65 [ V_67 ] . V_60 ) ;
if ( V_65 [ V_67 ] . V_58 . V_10 )
F_79 ( V_65 [ V_67 ] . V_14 ,
& V_65 [ V_67 ] . V_58 ) ;
F_16 ( V_65 [ V_67 ] . V_14 ) ;
}
F_30 ( V_65 ) ;
return V_15 ;
}
static signed long F_80 ( T_4 V_76 )
{
T_5 V_77 , V_78 ;
T_6 V_79 , V_80 ;
if ( V_76 == 0 )
return 0 ;
V_77 = F_81 ( V_76 ) ;
V_78 = F_82 () ;
if ( ! F_83 ( V_77 , V_78 ) )
return 0 ;
V_79 = F_84 ( F_85 ( V_77 , V_78 ) ) ;
V_80 = F_86 ( V_79 ) ;
if ( V_80 >= V_81 - 1 )
return V_81 - 1 ;
return V_80 + 1 ;
}
static int F_87 ( struct V_47 * V_48 ,
struct V_2 * V_3 ,
struct V_82 * V_57 ,
struct V_1 * * V_61 )
{
signed long V_63 = F_80 ( V_57 -> V_76 ) ;
signed long V_15 = 0 ;
T_3 V_83 = ~ 0 ;
V_15 = F_71 ( V_61 ,
V_57 -> V_84 ,
V_57 -> V_29 ,
V_63 , & V_83 ) ;
if ( V_15 < 0 )
return V_15 ;
V_57 -> V_85 = V_83 ;
if ( V_15 == 0 )
return - V_86 ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 ,
void * V_87 , T_3 V_84 ,
struct V_1 * * * V_88 )
{
T_3 V_67 , * V_89 ;
struct V_1 * * V_61 ;
int V_15 ;
V_89 = F_89 ( V_84 , sizeof( * V_89 ) , V_21 ) ;
if ( V_89 == NULL )
return - V_22 ;
if ( F_90 ( V_89 , V_87 ,
sizeof( T_3 ) * V_84 ) ) {
V_15 = - V_90 ;
goto V_91;
}
V_61 = F_89 ( V_84 , sizeof( * V_61 ) , V_21 ) ;
if ( V_61 == NULL ) {
V_15 = - V_22 ;
goto V_91;
}
for ( V_67 = 0 ; V_67 < V_84 ; V_67 ++ ) {
V_61 [ V_67 ] = F_1 ( V_3 , V_89 [ V_67 ] ) ;
if ( ! V_61 [ V_67 ] ) {
V_15 = - V_25 ;
goto V_92;
}
}
F_30 ( V_89 ) ;
* V_88 = V_61 ;
return 0 ;
V_92:
while ( V_67 -- > 0 )
F_27 ( V_61 [ V_67 ] ) ;
F_30 ( V_61 ) ;
V_91:
F_30 ( V_89 ) ;
return V_15 ;
}
static void F_91 ( struct V_1 * * V_61 ,
T_3 V_62 )
{
T_3 V_67 ;
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ )
F_27 ( V_61 [ V_67 ] ) ;
F_30 ( V_61 ) ;
}
int
F_92 ( struct V_47 * V_48 , void * V_46 ,
struct V_2 * V_3 )
{
struct V_82 * args = V_46 ;
struct V_1 * * V_61 ;
int V_15 = 0 ;
if ( ! F_64 ( V_48 , V_49 ) )
return - V_50 ;
if ( args -> V_29 & ~ ( V_71 |
V_69 ) )
return - V_26 ;
if ( args -> V_84 == 0 )
return - V_26 ;
V_15 = F_88 ( V_3 ,
F_93 ( args -> V_89 ) ,
args -> V_84 ,
& V_61 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_87 ( V_48 , V_3 ,
args , V_61 ) ;
F_91 ( V_61 , args -> V_84 ) ;
return V_15 ;
}
int
F_94 ( struct V_47 * V_48 , void * V_46 ,
struct V_2 * V_3 )
{
struct V_93 * args = V_46 ;
struct V_1 * * V_61 ;
T_3 V_67 ;
int V_15 ;
if ( ! F_64 ( V_48 , V_49 ) )
return - V_50 ;
if ( args -> V_51 != 0 )
return - V_26 ;
if ( args -> V_84 == 0 )
return - V_26 ;
V_15 = F_88 ( V_3 ,
F_93 ( args -> V_89 ) ,
args -> V_84 ,
& V_61 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_67 = 0 ; V_67 < args -> V_84 ; V_67 ++ )
F_14 ( V_61 [ V_67 ] , NULL ) ;
F_91 ( V_61 , args -> V_84 ) ;
return 0 ;
}
int
F_95 ( struct V_47 * V_48 , void * V_46 ,
struct V_2 * V_3 )
{
struct V_93 * args = V_46 ;
struct V_1 * * V_61 ;
T_3 V_67 ;
int V_15 ;
if ( ! F_64 ( V_48 , V_49 ) )
return - V_50 ;
if ( args -> V_51 != 0 )
return - V_26 ;
if ( args -> V_84 == 0 )
return - V_26 ;
V_15 = F_88 ( V_3 ,
F_93 ( args -> V_89 ) ,
args -> V_84 ,
& V_61 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_67 = 0 ; V_67 < args -> V_84 ; V_67 ++ ) {
V_15 = F_21 ( V_61 [ V_67 ] ) ;
if ( V_15 < 0 )
break;
}
F_91 ( V_61 , args -> V_84 ) ;
return V_15 ;
}
