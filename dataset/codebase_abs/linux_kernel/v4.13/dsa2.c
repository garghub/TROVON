static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_2 (dst, &dsa_switch_trees, list)
if ( V_3 -> V_2 == V_2 ) {
F_3 ( & V_3 -> V_4 ) ;
return V_3 ;
}
return NULL ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_1 * V_3 = F_5 ( V_6 , struct V_1 ,
V_4 ) ;
F_6 ( & V_3 -> V_7 ) ;
F_7 ( V_3 ) ;
}
static void F_8 ( struct V_1 * V_3 )
{
F_9 ( & V_3 -> V_4 , F_4 ) ;
}
static struct V_1 * F_10 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_11 ( sizeof( * V_3 ) , V_8 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_2 = V_2 ;
F_12 ( & V_3 -> V_7 ) ;
F_13 ( & V_9 , & V_3 -> V_7 ) ;
F_14 ( & V_3 -> V_4 ) ;
return V_3 ;
}
static void F_15 ( struct V_1 * V_3 ,
struct V_10 * V_11 , T_1 V_12 )
{
F_3 ( & V_3 -> V_4 ) ;
V_3 -> V_11 [ V_12 ] = V_11 ;
}
static void F_16 ( struct V_1 * V_3 ,
struct V_10 * V_11 , T_1 V_12 )
{
V_3 -> V_11 [ V_12 ] = NULL ;
F_9 ( & V_3 -> V_4 , F_4 ) ;
}
static bool F_17 ( struct V_13 * V_14 )
{
return ! ! ( V_14 -> V_15 || V_14 -> V_16 ) ;
}
static bool F_18 ( struct V_13 * V_14 )
{
if ( V_14 -> V_16 && ! strcmp ( V_14 -> V_16 , L_1 ) )
return true ;
else
return ! ! F_19 ( V_14 -> V_15 , L_2 , 0 ) ;
}
static bool F_20 ( struct V_13 * V_14 )
{
if ( V_14 -> V_16 && ! strcmp ( V_14 -> V_16 , L_3 ) )
return true ;
else
return ! ! F_19 ( V_14 -> V_15 , L_4 , 0 ) ;
}
static bool F_21 ( struct V_10 * V_11 ,
struct V_17 * V_14 )
{
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_18 ; V_12 ++ )
if ( V_11 -> V_19 [ V_12 ] . V_15 == V_14 )
return true ;
return false ;
}
static struct V_10 * F_22 ( struct V_1 * V_3 ,
struct V_17 * V_14 )
{
struct V_10 * V_11 ;
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
V_11 = V_3 -> V_11 [ V_12 ] ;
if ( ! V_11 )
continue;
if ( F_21 ( V_11 , V_14 ) )
return V_11 ;
}
return NULL ;
}
static int F_23 ( struct V_1 * V_3 ,
struct V_10 * V_21 ,
struct V_13 * V_14 ,
T_1 V_22 )
{
struct V_17 * V_23 ;
int V_12 ;
struct V_10 * V_24 ;
for ( V_12 = 0 ; ; V_12 ++ ) {
V_23 = F_19 ( V_14 -> V_15 , L_2 , V_12 ) ;
if ( ! V_23 )
break;
V_24 = F_22 ( V_3 , V_23 ) ;
F_24 ( V_23 ) ;
if ( ! V_24 )
return 1 ;
V_21 -> V_25 [ V_24 -> V_12 ] = V_22 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_3 , struct V_10 * V_11 )
{
struct V_13 * V_14 ;
T_1 V_12 ;
int V_26 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_18 ; V_12 ++ ) {
V_14 = & V_11 -> V_19 [ V_12 ] ;
if ( ! F_17 ( V_14 ) )
continue;
if ( ! F_18 ( V_14 ) )
continue;
V_26 = F_23 ( V_3 , V_11 , V_14 , V_12 ) ;
if ( V_26 != 0 )
return V_26 ;
V_11 -> V_27 |= F_26 ( V_12 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_3 )
{
struct V_10 * V_11 ;
T_1 V_12 ;
int V_26 ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
V_11 = V_3 -> V_11 [ V_12 ] ;
if ( ! V_11 )
continue;
V_26 = F_25 ( V_3 , V_11 ) ;
if ( V_26 != 0 )
return V_26 ;
}
return 0 ;
}
static int F_28 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_11 ;
int V_26 ;
V_26 = F_29 ( V_11 , V_11 -> V_28 , V_14 , V_14 -> V_12 ) ;
if ( V_26 ) {
F_30 ( V_11 -> V_28 , L_5 ,
V_14 -> V_12 , V_26 ) ;
return V_26 ;
}
memset ( & V_14 -> V_29 , 0 , sizeof( V_14 -> V_29 ) ) ;
return F_31 ( V_11 -> V_30 , & V_14 -> V_29 ,
V_14 -> V_12 ) ;
}
static void F_32 ( struct V_13 * V_14 )
{
F_33 ( & V_14 -> V_29 ) ;
F_34 ( V_14 ) ;
}
static int F_35 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_11 ;
int V_26 ;
V_26 = F_29 ( V_11 , V_11 -> V_28 , V_14 , V_14 -> V_12 ) ;
if ( V_26 ) {
F_30 ( V_11 -> V_28 , L_6 ,
V_14 -> V_12 , V_26 ) ;
return V_26 ;
}
memset ( & V_14 -> V_29 , 0 , sizeof( V_14 -> V_29 ) ) ;
V_26 = F_31 ( V_11 -> V_30 , & V_14 -> V_29 ,
V_14 -> V_12 ) ;
return V_26 ;
}
static void F_36 ( struct V_13 * V_14 )
{
F_33 ( & V_14 -> V_29 ) ;
F_34 ( V_14 ) ;
V_14 -> V_11 -> V_31 &= ~ F_26 ( V_14 -> V_12 ) ;
}
static int F_37 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_11 ;
const char * V_16 = V_14 -> V_16 ;
int V_26 ;
if ( V_14 -> V_15 )
V_16 = F_38 ( V_14 -> V_15 , L_7 , NULL ) ;
if ( ! V_16 )
V_16 = L_8 ;
V_26 = F_39 ( V_11 , V_11 -> V_28 , V_14 -> V_12 , V_16 ) ;
if ( V_26 ) {
F_30 ( V_11 -> V_28 , L_9 ,
V_14 -> V_12 , V_26 ) ;
V_14 -> V_32 = NULL ;
return V_26 ;
}
memset ( & V_14 -> V_29 , 0 , sizeof( V_14 -> V_29 ) ) ;
V_26 = F_31 ( V_11 -> V_30 , & V_14 -> V_29 ,
V_14 -> V_12 ) ;
if ( V_26 )
return V_26 ;
F_40 ( & V_14 -> V_29 , V_14 -> V_32 ) ;
return 0 ;
}
static void F_41 ( struct V_13 * V_14 )
{
F_33 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_32 ) {
F_42 ( V_14 -> V_32 ) ;
V_14 -> V_32 = NULL ;
V_14 -> V_11 -> V_33 &= ~ ( 1 << V_14 -> V_12 ) ;
}
}
static int F_43 ( struct V_1 * V_3 , struct V_10 * V_11 )
{
struct V_13 * V_14 ;
T_1 V_12 ;
int V_26 ;
V_11 -> V_34 = V_11 -> V_33 ;
V_11 -> V_30 = F_44 ( & V_35 , 0 ) ;
if ( ! V_11 -> V_30 )
return - V_36 ;
V_26 = F_45 ( V_11 -> V_30 , V_11 -> V_28 ) ;
if ( V_26 )
return V_26 ;
V_26 = V_11 -> V_37 -> V_38 ( V_11 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_46 ( V_11 ) ;
if ( V_26 )
return V_26 ;
if ( V_11 -> V_37 -> V_39 ) {
V_26 = V_11 -> V_37 -> V_39 ( V_11 , V_3 -> V_40 -> V_32 -> V_41 ) ;
if ( V_26 < 0 )
return V_26 ;
}
if ( ! V_11 -> V_42 && V_11 -> V_37 -> V_43 ) {
V_11 -> V_42 = F_47 ( V_11 -> V_28 ) ;
if ( ! V_11 -> V_42 )
return - V_36 ;
F_48 ( V_11 ) ;
V_26 = F_49 ( V_11 -> V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
}
for ( V_12 = 0 ; V_12 < V_11 -> V_18 ; V_12 ++ ) {
V_14 = & V_11 -> V_19 [ V_12 ] ;
if ( ! F_17 ( V_14 ) )
continue;
if ( F_18 ( V_14 ) ) {
V_26 = F_28 ( V_14 ) ;
if ( V_26 )
return V_26 ;
continue;
}
if ( F_20 ( V_14 ) ) {
V_26 = F_35 ( V_14 ) ;
if ( V_26 )
return V_26 ;
continue;
}
V_26 = F_37 ( V_14 ) ;
if ( V_26 )
continue;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_3 , struct V_10 * V_11 )
{
struct V_13 * V_14 ;
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_18 ; V_12 ++ ) {
V_14 = & V_11 -> V_19 [ V_12 ] ;
if ( ! F_17 ( V_14 ) )
continue;
if ( F_18 ( V_14 ) ) {
F_32 ( V_14 ) ;
continue;
}
if ( F_20 ( V_14 ) ) {
F_36 ( V_14 ) ;
continue;
}
F_41 ( V_14 ) ;
}
if ( V_11 -> V_42 && V_11 -> V_37 -> V_43 )
F_51 ( V_11 -> V_42 ) ;
F_52 ( V_11 ) ;
if ( V_11 -> V_30 ) {
F_53 ( V_11 -> V_30 ) ;
F_54 ( V_11 -> V_30 ) ;
V_11 -> V_30 = NULL ;
}
}
static int F_55 ( struct V_1 * V_3 )
{
struct V_10 * V_11 ;
T_1 V_12 ;
int V_26 ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
V_11 = V_3 -> V_11 [ V_12 ] ;
if ( ! V_11 )
continue;
V_26 = F_43 ( V_3 , V_11 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_3 -> V_40 ) {
V_26 = F_56 ( V_3 -> V_40 ) ;
if ( V_26 )
return V_26 ;
}
F_57 () ;
V_3 -> V_40 -> V_32 -> V_44 = V_3 ;
V_3 -> V_45 = true ;
return 0 ;
}
static void F_58 ( struct V_1 * V_3 )
{
struct V_10 * V_11 ;
T_1 V_12 ;
if ( ! V_3 -> V_45 )
return;
V_3 -> V_40 -> V_32 -> V_44 = NULL ;
F_57 () ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
V_11 = V_3 -> V_11 [ V_12 ] ;
if ( ! V_11 )
continue;
F_50 ( V_3 , V_11 ) ;
}
if ( V_3 -> V_40 ) {
F_59 ( V_3 -> V_40 ) ;
V_3 -> V_40 = NULL ;
}
F_60 ( L_10 , V_3 -> V_2 ) ;
V_3 -> V_45 = false ;
}
static int F_61 ( struct V_13 * V_14 , T_1 V_12 ,
struct V_1 * V_3 ,
struct V_10 * V_11 )
{
enum V_46 V_47 ;
struct V_48 * V_49 ;
struct V_17 * V_50 ;
if ( V_14 -> V_15 ) {
V_50 = F_19 ( V_14 -> V_15 , L_4 , 0 ) ;
if ( ! V_50 )
return - V_51 ;
V_49 = F_62 ( V_50 ) ;
} else {
V_49 = F_63 ( V_11 -> V_52 -> V_32 [ V_12 ] ) ;
F_64 ( V_49 ) ;
}
if ( ! V_49 )
return - V_53 ;
if ( ! V_3 -> V_40 ) {
V_3 -> V_40 = V_14 ;
V_3 -> V_40 -> V_32 = V_49 ;
}
V_11 -> V_31 |= F_26 ( V_12 ) ;
V_47 = V_11 -> V_37 -> V_54 ( V_11 ) ;
V_3 -> V_55 = F_65 ( V_47 ) ;
if ( F_66 ( V_3 -> V_55 ) ) {
F_30 ( V_11 -> V_28 , L_11 ) ;
V_11 -> V_31 &= ~ F_26 ( V_12 ) ;
return F_67 ( V_3 -> V_55 ) ;
}
V_3 -> V_56 = V_3 -> V_55 -> V_56 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_3 , struct V_10 * V_11 )
{
struct V_13 * V_14 ;
T_1 V_12 ;
int V_26 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_18 ; V_12 ++ ) {
V_14 = & V_11 -> V_19 [ V_12 ] ;
if ( ! F_17 ( V_14 ) ||
F_18 ( V_14 ) )
continue;
if ( F_20 ( V_14 ) ) {
V_26 = F_61 ( V_14 , V_12 , V_3 , V_11 ) ;
if ( V_26 )
return V_26 ;
} else {
V_11 -> V_33 |= F_26 ( V_12 ) ;
}
}
F_60 ( L_12 , V_3 -> V_2 , V_11 -> V_12 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_3 )
{
struct V_10 * V_11 ;
struct V_13 * V_57 ;
T_1 V_12 ;
int V_14 ;
int V_26 ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
V_11 = V_3 -> V_11 [ V_12 ] ;
if ( ! V_11 )
continue;
V_26 = F_68 ( V_3 , V_11 ) ;
if ( V_26 )
return V_26 ;
}
if ( ! V_3 -> V_40 ) {
F_70 ( L_13 ) ;
return - V_51 ;
}
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
V_11 = V_3 -> V_11 [ V_12 ] ;
if ( ! V_11 )
continue;
for ( V_14 = 0 ; V_14 < V_11 -> V_18 ; V_14 ++ ) {
V_57 = & V_11 -> V_19 [ V_14 ] ;
if ( ! F_17 ( V_57 ) ||
F_18 ( V_57 ) ||
F_20 ( V_57 ) )
continue;
V_57 -> V_40 = V_3 -> V_40 ;
}
}
F_60 ( L_14 , V_3 -> V_2 ) ;
return 0 ;
}
static int F_71 ( struct V_17 * V_19 , struct V_10 * V_11 )
{
struct V_17 * V_14 ;
int V_26 ;
T_1 V_58 ;
F_72 (ports, port) {
V_26 = F_73 ( V_14 , L_15 , & V_58 ) ;
if ( V_26 )
return V_26 ;
if ( V_58 >= V_11 -> V_18 )
return - V_51 ;
V_11 -> V_19 [ V_58 ] . V_15 = V_14 ;
}
return 0 ;
}
static int F_74 ( struct V_59 * V_52 , struct V_10 * V_11 )
{
bool V_60 = false ;
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
if ( ! V_52 -> V_63 [ V_61 ] )
continue;
V_11 -> V_19 [ V_61 ] . V_16 = V_52 -> V_63 [ V_61 ] ;
V_60 = true ;
}
if ( ! V_60 && V_61 == V_62 )
return - V_51 ;
return 0 ;
}
static int F_75 ( struct V_17 * V_64 , T_1 * V_2 , T_1 * V_12 )
{
int V_26 ;
* V_2 = * V_12 = 0 ;
V_26 = F_76 ( V_64 , L_16 , 0 , V_2 ) ;
if ( V_26 ) {
if ( V_26 == - V_51 )
return 0 ;
return V_26 ;
}
V_26 = F_76 ( V_64 , L_16 , 1 , V_12 ) ;
if ( V_26 )
return V_26 ;
if ( * V_12 >= V_20 )
return - V_51 ;
return 0 ;
}
static int F_77 ( struct V_59 * V_65 , T_1 * V_2 , T_1 * V_12 )
{
if ( ! V_65 )
return - V_66 ;
* V_2 = 0 ;
* V_12 = 0 ;
return 0 ;
}
static struct V_17 * F_78 ( struct V_10 * V_11 ,
struct V_17 * V_64 )
{
struct V_17 * V_19 ;
V_19 = F_79 ( V_64 , L_17 ) ;
if ( ! V_19 ) {
F_80 ( V_11 -> V_28 , L_18 ) ;
return F_81 ( - V_51 ) ;
}
return V_19 ;
}
static int F_82 ( struct V_10 * V_11 )
{
struct V_59 * V_67 = V_11 -> V_28 -> V_68 ;
struct V_17 * V_64 = V_11 -> V_28 -> V_69 ;
struct V_1 * V_3 ;
struct V_17 * V_19 ;
T_1 V_2 , V_12 ;
int V_61 , V_26 ;
if ( V_64 ) {
V_26 = F_75 ( V_64 , & V_2 , & V_12 ) ;
if ( V_26 )
return V_26 ;
V_19 = F_78 ( V_11 , V_64 ) ;
if ( F_66 ( V_19 ) )
return F_67 ( V_19 ) ;
V_26 = F_71 ( V_19 , V_11 ) ;
if ( V_26 )
return V_26 ;
} else {
V_26 = F_77 ( V_67 , & V_2 , & V_12 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_74 ( V_67 , V_11 ) ;
if ( V_26 )
return V_26 ;
}
V_3 = F_1 ( V_2 ) ;
if ( ! V_3 ) {
V_3 = F_10 ( V_2 ) ;
if ( ! V_3 )
return - V_36 ;
}
if ( V_3 -> V_11 [ V_12 ] ) {
V_26 = - V_70 ;
goto V_71;
}
V_11 -> V_3 = V_3 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_52 = V_67 ;
for ( V_61 = 0 ; V_61 < V_20 ; ++ V_61 )
V_11 -> V_25 [ V_61 ] = V_72 ;
F_15 ( V_3 , V_11 , V_12 ) ;
V_26 = F_27 ( V_3 ) ;
if ( V_26 < 0 )
goto V_73;
if ( V_26 == 1 ) {
V_26 = 0 ;
goto V_71;
}
if ( V_3 -> V_45 ) {
F_60 ( L_19 ) ;
return - V_51 ;
}
V_26 = F_69 ( V_3 ) ;
if ( V_26 ) {
if ( V_26 == - V_53 ) {
F_16 ( V_3 , V_11 , V_11 -> V_12 ) ;
return V_26 ;
}
goto V_73;
}
V_26 = F_55 ( V_3 ) ;
if ( V_26 ) {
F_58 ( V_3 ) ;
goto V_73;
}
F_8 ( V_3 ) ;
return 0 ;
V_73:
F_16 ( V_3 , V_11 , V_11 -> V_12 ) ;
V_71:
F_8 ( V_3 ) ;
return V_26 ;
}
struct V_10 * F_83 ( struct V_74 * V_28 , T_2 V_75 )
{
T_2 V_76 = sizeof( struct V_10 ) + V_75 * sizeof( struct V_13 ) ;
struct V_10 * V_11 ;
int V_61 ;
V_11 = F_84 ( V_28 , V_76 , V_8 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_28 = V_28 ;
V_11 -> V_18 = V_75 ;
for ( V_61 = 0 ; V_61 < V_11 -> V_18 ; ++ V_61 ) {
V_11 -> V_19 [ V_61 ] . V_12 = V_61 ;
V_11 -> V_19 [ V_61 ] . V_11 = V_11 ;
}
return V_11 ;
}
int F_85 ( struct V_10 * V_11 )
{
int V_26 ;
F_86 ( & V_77 ) ;
V_26 = F_82 ( V_11 ) ;
F_87 ( & V_77 ) ;
return V_26 ;
}
static void F_88 ( struct V_10 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_3 ;
F_58 ( V_3 ) ;
F_16 ( V_3 , V_11 , V_11 -> V_12 ) ;
}
void F_89 ( struct V_10 * V_11 )
{
F_86 ( & V_77 ) ;
F_88 ( V_11 ) ;
F_87 ( & V_77 ) ;
}
