struct V_1 * F_1 ( struct V_2 * V_2 )
{
return V_2 -> V_3 ;
}
static T_1 T_2 F_2 ( struct V_1 * V_4 )
{
const unsigned int * V_5 ;
int V_6 ;
V_5 = F_3 ( V_4 , L_1 , & V_6 ) ;
if ( V_6 == 4 )
return ( T_1 ) * V_5 ;
V_5 = F_3 ( V_4 , L_2 , & V_6 ) ;
if ( V_6 == 4 )
return ( T_1 ) * V_5 ;
V_5 = F_3 ( V_4 , L_3 , & V_6 ) ;
if ( V_6 == 4 )
return ( T_1 ) * V_5 ;
return 0 ;
}
static void F_4 ( struct V_2 * V_2 )
{
if ( ! F_5 ( V_7 ) )
F_6 ( V_2 -> V_8 ) ;
F_6 ( V_2 -> V_9 ) ;
F_6 ( V_2 -> V_10 ) ;
F_6 ( ( V_11 V_12 V_13 * ) V_2 -> V_14 ) ;
}
static int T_2 F_7 ( struct V_2 * V_2 ,
struct V_1 * V_15 )
{
unsigned int V_16 ;
const T_3 * V_17 ;
int V_18 ;
V_17 = F_3 ( V_15 , L_4 , NULL ) ;
if ( ! V_17 )
return - V_19 ;
V_16 = V_17 [ 0 ] ;
V_17 = F_3 ( V_15 -> V_20 -> V_20 , L_5 , NULL ) ;
if ( ! V_17 ) {
F_8 ( V_21 L_6 , V_22 ) ;
V_18 = V_2 -> V_23 ;
} else
V_18 = V_17 [ 0 ] ;
V_16 |= V_18 << V_24 ;
V_2 -> V_25 [ 0 ] = F_9 ( NULL , V_26 | V_16 ) ;
V_2 -> V_25 [ 1 ] = F_9 ( NULL , V_27 | V_16 ) ;
V_2 -> V_25 [ 2 ] = F_9 ( NULL , V_28 | V_16 ) ;
if ( ! V_2 -> V_25 [ 2 ] )
return - V_29 ;
return 0 ;
}
static void V_13 * T_2 F_10 ( struct V_2 * V_2 ,
struct V_1 * V_30 ,
const char * V_31 )
{
const struct V_32 {
unsigned long V_33 ;
unsigned int V_34 ;
} V_35 ( ( V_36 ) ) * V_5 ;
int V_6 ;
V_5 = F_3 ( V_30 , V_31 , & V_6 ) ;
if ( V_5 == NULL || V_6 != sizeof ( struct V_32 ) )
return NULL ;
return F_11 ( V_5 -> V_33 , V_5 -> V_34 ) ;
}
static int T_2 F_12 ( struct V_2 * V_2 )
{
struct V_1 * V_23 = V_2 -> V_3 ;
const char * V_5 ;
int V_37 ;
V_37 = - V_19 ;
V_2 -> V_31 = F_3 ( V_23 , L_7 , NULL ) ;
if ( ! V_2 -> V_31 )
goto V_38;
V_5 = F_3 ( V_23 , L_8 , NULL ) ;
if ( ! V_5 )
goto V_38;
V_2 -> V_39 = * ( unsigned long * ) V_5 ;
V_2 -> V_14 = ( void V_11 * )
F_10 ( V_2 , V_23 , L_8 ) ;
if ( ! V_2 -> V_14 )
goto V_38;
V_5 = F_3 ( V_23 , L_9 , NULL ) ;
if ( ! V_5 )
goto V_40;
V_2 -> V_41 = * ( unsigned long * ) V_5 ;
V_2 -> V_10 = F_10 ( V_2 , V_23 , L_9 ) ;
if ( ! V_2 -> V_10 )
goto V_40;
V_2 -> V_9 = F_10 ( V_2 , V_23 , L_10 ) ;
if ( ! V_2 -> V_9 )
goto V_40;
if ( ! F_5 ( V_7 ) ) {
V_2 -> V_8 = F_10 ( V_2 , V_23 , L_11 ) ;
if ( ! V_2 -> V_8 )
goto V_40;
}
V_37 = 0 ;
goto V_38;
V_40:
F_4 ( V_2 ) ;
V_38:
return V_37 ;
}
static int T_2 F_13 ( struct V_2 * V_2 , struct V_1 * V_15 )
{
struct V_42 V_43 ;
int V_37 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < 3 ; V_44 ++ ) {
V_37 = F_14 ( V_15 , V_44 , & V_43 ) ;
if ( V_37 ) {
F_15 ( L_12 , V_44 ) ;
goto V_45;
}
V_37 = - V_29 ;
F_15 ( L_13 , V_44 , V_43 . args [ 0 ] ,
V_43 . V_15 ) ;
V_2 -> V_25 [ V_44 ] = F_16 ( & V_43 ) ;
if ( ! V_2 -> V_25 [ V_44 ] ) {
F_15 ( L_14 ) ;
goto V_45;
}
}
return 0 ;
V_45:
F_15 ( L_15 , * V_43 . args ,
V_2 -> V_31 ) ;
for (; V_44 >= 0 ; V_44 -- ) {
if ( V_2 -> V_25 [ V_44 ] )
F_17 ( V_2 -> V_25 [ V_44 ] ) ;
}
return V_37 ;
}
static int F_18 ( struct V_2 * V_2 , int V_46 ,
void V_13 * * V_47 , unsigned long * V_48 )
{
struct V_1 * V_15 = V_2 -> V_3 ;
struct V_49 V_49 = { } ;
unsigned long V_34 ;
int V_37 ;
V_37 = F_19 ( V_15 , V_46 , & V_49 ) ;
if ( V_37 )
return V_37 ;
if ( V_48 )
* V_48 = V_49 . V_50 ;
V_34 = F_20 ( & V_49 ) ;
* V_47 = F_11 ( V_49 . V_50 , V_34 ) ;
if ( ! * V_47 )
return - V_29 ;
return 0 ;
}
static int T_2 F_21 ( struct V_2 * V_2 )
{
struct V_1 * V_15 = V_2 -> V_3 ;
int V_37 = - V_19 ;
V_2 -> V_31 = F_3 ( V_15 , L_7 , NULL ) ;
if ( ! V_2 -> V_31 )
goto V_38;
V_37 = F_18 ( V_2 , 0 , ( void V_13 * * ) & V_2 -> V_14 ,
& V_2 -> V_39 ) ;
if ( V_37 ) {
F_15 ( L_16 ,
V_15 ) ;
goto V_38;
}
V_37 = F_18 ( V_2 , 1 , ( void V_13 * * ) & V_2 -> V_10 ,
& V_2 -> V_41 ) ;
if ( V_37 ) {
F_15 ( L_17 ,
V_15 ) ;
goto V_40;
}
V_37 = F_18 ( V_2 , 2 , ( void V_13 * * ) & V_2 -> V_9 , NULL ) ;
if ( V_37 ) {
F_15 ( L_18 ,
V_15 ) ;
goto V_40;
}
if ( ! F_5 ( V_7 ) )
V_37 = F_18 ( V_2 , 3 ,
( void V_13 * * ) & V_2 -> V_8 , NULL ) ;
if ( V_37 ) {
F_15 ( L_19 ,
V_15 ) ;
goto V_40;
}
F_15 ( L_20 , V_15 ) ;
F_15 ( L_21 ,
V_2 -> V_39 , V_2 -> V_14 ) ;
F_15 ( L_22 ,
V_2 -> V_41 , V_2 -> V_10 ) ;
F_15 ( L_23 , V_2 -> V_9 ) ;
F_15 ( L_24 , V_2 -> V_8 ) ;
return 0 ;
V_40:
F_4 ( V_2 ) ;
V_38:
F_15 ( L_25 , V_2 -> V_31 , V_37 ) ;
return V_37 ;
}
static int T_2 F_22 ( int (* F_23)( void * V_51 ) )
{
int V_37 ;
struct V_1 * V_23 ;
unsigned int V_30 = 0 ;
V_37 = - V_19 ;
for ( V_23 = F_24 ( NULL , L_26 ) ;
V_23 ; V_23 = F_24 ( V_23 , L_26 ) ) {
V_37 = F_23 ( V_23 ) ;
if ( V_37 ) {
F_8 ( V_21 L_27 ,
V_22 , V_23 -> V_31 ) ;
break;
}
V_30 ++ ;
}
return V_37 ? V_37 : V_30 ;
}
static int T_2 F_25 ( struct V_2 * V_2 , void * V_51 )
{
int V_37 ;
struct V_1 * V_4 = (struct V_1 * ) V_51 ;
static int V_52 = 0 , V_53 = 0 ;
V_2 -> V_3 = F_26 ( V_4 ) ;
V_2 -> V_54 = F_2 ( V_4 ) ;
V_2 -> V_23 = F_27 ( V_4 ) ;
if ( V_2 -> V_23 >= V_55 ) {
F_8 ( V_21 L_28
L_29 , V_4 , V_2 -> V_23 ) ;
F_8 ( V_21 L_30 ) ;
V_37 = - V_19 ;
goto V_38;
}
V_37 = F_21 ( V_2 ) ;
if ( V_37 ) {
if ( ! V_52 ) {
V_52 = 1 ;
F_8 ( V_21 L_31
L_32 , V_22 ) ;
}
V_37 = F_12 ( V_2 ) ;
if ( V_37 ) {
F_8 ( V_56 L_33 ,
V_2 -> V_31 ) ;
goto V_38;
}
}
V_37 = F_13 ( V_2 , V_4 ) ;
if ( V_37 ) {
if ( ! V_53 ) {
V_53 = 1 ;
F_8 ( V_21 L_31
L_34 , V_22 ) ;
}
V_37 = F_7 ( V_2 , V_4 ) ;
if ( V_37 ) {
F_8 ( V_56 L_35 ,
V_2 -> V_31 ) ;
goto V_40;
}
}
F_15 ( L_36 , V_2 -> V_31 ,
V_2 -> V_14 , V_2 -> V_10 , V_2 -> V_8 ,
V_2 -> V_9 , V_2 -> V_57 ) ;
goto V_38;
V_40:
F_4 ( V_2 ) ;
V_38:
return V_37 ;
}
static int F_28 ( struct V_2 * V_2 )
{
F_4 ( V_2 ) ;
F_29 ( V_2 -> V_3 ) ;
return 0 ;
}
static void F_30 ( struct V_58 * V_59 )
{
V_59 -> V_60 -> V_61 ( V_59 ) ;
}
static void F_31 ( struct V_58 * V_59 )
{
V_59 -> V_60 -> V_62 ( V_59 ) ;
}
static struct V_2 * F_32 ( int V_23 , T_3 V_63 )
{
struct V_2 * V_2 ;
const T_3 * V_64 ;
F_33 (spu, &cbe_spu_info[node].spus, cbe_list) {
V_64 = F_3 ( F_1 ( V_2 ) , L_3 , NULL ) ;
if ( * V_64 == V_63 )
return V_2 ;
}
return NULL ;
}
static void F_34 ( void )
{
int V_23 , V_44 ;
struct V_2 * V_65 , * V_2 ;
T_3 V_63 ;
for ( V_23 = 0 ; V_23 < V_55 ; V_23 ++ ) {
V_65 = NULL ;
for ( V_44 = 0 ; V_44 < V_66 ; V_44 ++ ) {
V_63 = V_67 [ V_44 ] ;
V_2 = F_32 ( V_23 , V_63 ) ;
if ( ! V_2 )
continue;
V_2 -> V_68 = V_69 [ V_63 ] ;
if ( V_65 )
F_35 ( & V_2 -> V_70 ,
& V_65 -> V_70 ) ;
V_65 = V_2 ;
}
}
}
static int F_36 ( void )
{
struct V_1 * V_71 ;
F_37 (dn, L_26 ) {
if ( F_38 ( V_71 , L_37 , NULL ) ) {
F_29 ( V_71 ) ;
return 1 ;
}
}
return 0 ;
}
static struct V_2 * F_39 ( int V_72 , struct V_1 * V_71 )
{
struct V_2 * V_2 ;
F_33 (spu, &cbe_spu_info[cbe].spus, cbe_list)
if ( F_1 ( V_2 ) == V_71 )
return V_2 ;
return NULL ;
}
static struct V_2 *
F_40 ( int V_72 , struct V_1 * V_73 , struct V_1 * V_74 )
{
struct V_2 * V_2 ;
struct V_1 * V_75 ;
const T_4 * V_76 ;
int V_77 , V_44 ;
F_33 (spu, &cbe_spu_info[cbe].spus, cbe_list) {
V_75 = F_1 ( V_2 ) ;
if ( V_75 == V_74 )
continue;
V_76 = F_3 ( V_75 , L_37 , & V_77 ) ;
for ( V_44 = 0 ; V_44 < ( V_77 / sizeof( T_4 ) ) ; V_44 ++ ) {
if ( V_76 [ V_44 ] == V_73 -> T_4 )
return V_2 ;
}
}
return NULL ;
}
static void F_41 ( int V_72 )
{
struct V_2 * V_2 , * V_65 ;
struct V_1 * V_78 , * V_79 ;
T_4 V_80 ;
const T_4 * V_76 ;
const char * V_31 ;
int V_77 , V_44 , V_81 ;
V_65 = F_42 ( & V_82 [ V_72 ] . V_83 , struct V_2 ,
V_84 ) ;
V_80 = 0 ;
for ( V_81 = 1 ; V_81 < V_82 [ V_72 ] . V_85 ; V_81 ++ ) {
V_79 = F_1 ( V_65 ) ;
V_76 = F_3 ( V_79 , L_37 , & V_77 ) ;
for ( V_44 = 0 ; V_44 < ( V_77 / sizeof( T_4 ) ) ; V_44 ++ ) {
if ( V_76 [ V_44 ] == V_80 )
continue;
V_78 = F_43 ( V_76 [ V_44 ] ) ;
if ( ! V_78 )
continue;
V_31 = F_3 ( V_78 , L_7 , NULL ) ;
if ( ! V_31 )
continue;
if ( strcmp ( V_31 , L_26 ) == 0 ) {
V_2 = F_39 ( V_72 , V_78 ) ;
V_80 = V_79 -> T_4 ;
} else {
V_2 = F_40 ( V_72 , V_78 , V_79 ) ;
if ( ! V_2 )
continue;
if ( ! strcmp ( V_31 , L_38 ) ) {
V_65 -> V_68 = 1 ;
V_2 -> V_68 = 1 ;
}
V_80 = V_78 -> T_4 ;
}
F_35 ( & V_2 -> V_70 , & V_65 -> V_70 ) ;
V_65 = V_2 ;
break;
}
}
}
static void F_44 ( void )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_55 ; V_72 ++ )
F_41 ( V_72 ) ;
}
static int T_2 F_45 ( void )
{
if ( F_36 () ) {
F_44 () ;
} else {
if ( F_46 ( L_39 ) )
F_34 () ;
else
F_8 ( L_40 ) ;
}
return 0 ;
}
