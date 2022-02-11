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
return V_2 -> V_25 [ 2 ] == V_29 ? - V_30 : 0 ;
}
static void V_13 * T_2 F_10 ( struct V_2 * V_2 ,
struct V_1 * V_31 ,
const char * V_32 )
{
const struct V_33 {
unsigned long V_34 ;
unsigned int V_35 ;
} V_36 ( ( V_37 ) ) * V_5 ;
int V_6 ;
V_5 = F_3 ( V_31 , V_32 , & V_6 ) ;
if ( V_5 == NULL || V_6 != sizeof ( struct V_33 ) )
return NULL ;
return F_11 ( V_5 -> V_34 , V_5 -> V_35 ) ;
}
static int T_2 F_12 ( struct V_2 * V_2 )
{
struct V_1 * V_23 = V_2 -> V_3 ;
const char * V_5 ;
int V_38 ;
V_38 = - V_19 ;
V_2 -> V_32 = F_3 ( V_23 , L_7 , NULL ) ;
if ( ! V_2 -> V_32 )
goto V_39;
V_5 = F_3 ( V_23 , L_8 , NULL ) ;
if ( ! V_5 )
goto V_39;
V_2 -> V_40 = * ( unsigned long * ) V_5 ;
V_2 -> V_14 = ( void V_11 * )
F_10 ( V_2 , V_23 , L_8 ) ;
if ( ! V_2 -> V_14 )
goto V_39;
V_5 = F_3 ( V_23 , L_9 , NULL ) ;
if ( ! V_5 )
goto V_41;
V_2 -> V_42 = * ( unsigned long * ) V_5 ;
V_2 -> V_10 = F_10 ( V_2 , V_23 , L_9 ) ;
if ( ! V_2 -> V_10 )
goto V_41;
V_2 -> V_9 = F_10 ( V_2 , V_23 , L_10 ) ;
if ( ! V_2 -> V_9 )
goto V_41;
if ( ! F_5 ( V_7 ) ) {
V_2 -> V_8 = F_10 ( V_2 , V_23 , L_11 ) ;
if ( ! V_2 -> V_8 )
goto V_41;
}
V_38 = 0 ;
goto V_39;
V_41:
F_4 ( V_2 ) ;
V_39:
return V_38 ;
}
static int T_2 F_13 ( struct V_2 * V_2 , struct V_1 * V_15 )
{
struct V_43 V_44 ;
int V_38 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
V_38 = F_14 ( V_15 , V_45 , & V_44 ) ;
if ( V_38 ) {
F_15 ( L_12 , V_45 ) ;
goto V_46;
}
V_38 = - V_30 ;
F_15 ( L_13 , V_45 , V_44 . V_47 [ 0 ] ,
V_44 . V_48 -> V_49 ) ;
V_2 -> V_25 [ V_45 ] = F_16 ( V_44 . V_48 ,
V_44 . V_47 , V_44 . V_50 ) ;
if ( V_2 -> V_25 [ V_45 ] == V_29 ) {
F_15 ( L_14 ) ;
goto V_46;
}
}
return 0 ;
V_46:
F_15 ( L_15 , * V_44 . V_47 ,
V_2 -> V_32 ) ;
for (; V_45 >= 0 ; V_45 -- ) {
if ( V_2 -> V_25 [ V_45 ] != V_29 )
F_17 ( V_2 -> V_25 [ V_45 ] ) ;
}
return V_38 ;
}
static int F_18 ( struct V_2 * V_2 , int V_51 ,
void V_13 * * V_52 , unsigned long * V_53 )
{
struct V_1 * V_15 = V_2 -> V_3 ;
struct V_54 V_54 = { } ;
unsigned long V_35 ;
int V_38 ;
V_38 = F_19 ( V_15 , V_51 , & V_54 ) ;
if ( V_38 )
return V_38 ;
if ( V_53 )
* V_53 = V_54 . V_55 ;
V_35 = F_20 ( & V_54 ) ;
* V_52 = F_11 ( V_54 . V_55 , V_35 ) ;
if ( ! * V_52 )
return - V_30 ;
return 0 ;
}
static int T_2 F_21 ( struct V_2 * V_2 )
{
struct V_1 * V_15 = V_2 -> V_3 ;
int V_38 = - V_19 ;
V_2 -> V_32 = F_3 ( V_15 , L_7 , NULL ) ;
if ( ! V_2 -> V_32 )
goto V_39;
V_38 = F_18 ( V_2 , 0 , ( void V_13 * * ) & V_2 -> V_14 ,
& V_2 -> V_40 ) ;
if ( V_38 ) {
F_15 ( L_16 ,
V_15 -> V_49 ) ;
goto V_39;
}
V_38 = F_18 ( V_2 , 1 , ( void V_13 * * ) & V_2 -> V_10 ,
& V_2 -> V_42 ) ;
if ( V_38 ) {
F_15 ( L_17 ,
V_15 -> V_49 ) ;
goto V_41;
}
V_38 = F_18 ( V_2 , 2 , ( void V_13 * * ) & V_2 -> V_9 , NULL ) ;
if ( V_38 ) {
F_15 ( L_18 ,
V_15 -> V_49 ) ;
goto V_41;
}
if ( ! F_5 ( V_7 ) )
V_38 = F_18 ( V_2 , 3 ,
( void V_13 * * ) & V_2 -> V_8 , NULL ) ;
if ( V_38 ) {
F_15 ( L_19 ,
V_15 -> V_49 ) ;
goto V_41;
}
F_15 ( L_20 , V_15 -> V_49 ) ;
F_15 ( L_21 ,
V_2 -> V_40 , V_2 -> V_14 ) ;
F_15 ( L_22 ,
V_2 -> V_42 , V_2 -> V_10 ) ;
F_15 ( L_23 , V_2 -> V_9 ) ;
F_15 ( L_24 , V_2 -> V_8 ) ;
return 0 ;
V_41:
F_4 ( V_2 ) ;
V_39:
F_15 ( L_25 , V_2 -> V_32 , V_38 ) ;
return V_38 ;
}
static int T_2 F_22 ( int (* F_23)( void * V_56 ) )
{
int V_38 ;
struct V_1 * V_23 ;
unsigned int V_31 = 0 ;
V_38 = - V_19 ;
for ( V_23 = F_24 ( NULL , L_26 ) ;
V_23 ; V_23 = F_24 ( V_23 , L_26 ) ) {
V_38 = F_23 ( V_23 ) ;
if ( V_38 ) {
F_8 ( V_21 L_27 ,
V_22 , V_23 -> V_32 ) ;
break;
}
V_31 ++ ;
}
return V_38 ? V_38 : V_31 ;
}
static int T_2 F_25 ( struct V_2 * V_2 , void * V_56 )
{
int V_38 ;
struct V_1 * V_4 = (struct V_1 * ) V_56 ;
static int V_57 = 0 , V_58 = 0 ;
V_2 -> V_3 = F_26 ( V_4 ) ;
V_2 -> V_59 = F_2 ( V_4 ) ;
V_2 -> V_23 = F_27 ( V_4 ) ;
if ( V_2 -> V_23 >= V_60 ) {
F_8 ( V_21 L_28
L_29 , V_4 -> V_49 , V_2 -> V_23 ) ;
F_8 ( V_21 L_30 ) ;
V_38 = - V_19 ;
goto V_39;
}
V_38 = F_21 ( V_2 ) ;
if ( V_38 ) {
if ( ! V_57 ) {
V_57 = 1 ;
F_8 ( V_21 L_31
L_32 , V_22 ) ;
}
V_38 = F_12 ( V_2 ) ;
if ( V_38 ) {
F_8 ( V_61 L_33 ,
V_2 -> V_32 ) ;
goto V_39;
}
}
V_38 = F_13 ( V_2 , V_4 ) ;
if ( V_38 ) {
if ( ! V_58 ) {
V_58 = 1 ;
F_8 ( V_21 L_31
L_34 , V_22 ) ;
}
V_38 = F_7 ( V_2 , V_4 ) ;
if ( V_38 ) {
F_8 ( V_61 L_35 ,
V_2 -> V_32 ) ;
goto V_41;
}
}
F_15 ( L_36 , V_2 -> V_32 ,
V_2 -> V_14 , V_2 -> V_10 , V_2 -> V_8 ,
V_2 -> V_9 , V_2 -> V_62 ) ;
goto V_39;
V_41:
F_4 ( V_2 ) ;
V_39:
return V_38 ;
}
static int F_28 ( struct V_2 * V_2 )
{
F_4 ( V_2 ) ;
F_29 ( V_2 -> V_3 ) ;
return 0 ;
}
static void F_30 ( struct V_63 * V_64 )
{
V_64 -> V_65 -> V_66 ( V_64 ) ;
}
static void F_31 ( struct V_63 * V_64 )
{
V_64 -> V_65 -> V_67 ( V_64 ) ;
}
static struct V_2 * F_32 ( int V_23 , T_3 V_68 )
{
struct V_2 * V_2 ;
const T_3 * V_69 ;
F_33 (spu, &cbe_spu_info[node].spus, cbe_list) {
V_69 = F_3 ( F_1 ( V_2 ) , L_3 , NULL ) ;
if ( * V_69 == V_68 )
return V_2 ;
}
return NULL ;
}
static void F_34 ( void )
{
int V_23 , V_45 ;
struct V_2 * V_70 , * V_2 ;
T_3 V_68 ;
for ( V_23 = 0 ; V_23 < V_60 ; V_23 ++ ) {
V_70 = NULL ;
for ( V_45 = 0 ; V_45 < V_71 ; V_45 ++ ) {
V_68 = V_72 [ V_45 ] ;
V_2 = F_32 ( V_23 , V_68 ) ;
if ( ! V_2 )
continue;
V_2 -> V_73 = V_74 [ V_68 ] ;
if ( V_70 )
F_35 ( & V_2 -> V_75 ,
& V_70 -> V_75 ) ;
V_70 = V_2 ;
}
}
}
static int F_36 ( void )
{
struct V_1 * V_76 ;
F_37 (dn, L_26 ) {
if ( F_38 ( V_76 , L_37 , NULL ) ) {
F_29 ( V_76 ) ;
return 1 ;
}
}
return 0 ;
}
static struct V_2 * F_39 ( int V_77 , struct V_1 * V_76 )
{
struct V_2 * V_2 ;
F_33 (spu, &cbe_spu_info[cbe].spus, cbe_list)
if ( F_1 ( V_2 ) == V_76 )
return V_2 ;
return NULL ;
}
static struct V_2 *
F_40 ( int V_77 , struct V_1 * V_78 , struct V_1 * V_79 )
{
struct V_2 * V_2 ;
struct V_1 * V_80 ;
const T_4 * V_81 ;
int V_82 , V_45 ;
F_33 (spu, &cbe_spu_info[cbe].spus, cbe_list) {
V_80 = F_1 ( V_2 ) ;
if ( V_80 == V_79 )
continue;
V_81 = F_3 ( V_80 , L_37 , & V_82 ) ;
for ( V_45 = 0 ; V_45 < ( V_82 / sizeof( T_4 ) ) ; V_45 ++ ) {
if ( V_81 [ V_45 ] == V_78 -> T_4 )
return V_2 ;
}
}
return NULL ;
}
static void F_41 ( int V_77 )
{
struct V_2 * V_2 , * V_70 ;
struct V_1 * V_83 , * V_84 ;
T_4 V_85 ;
const T_4 * V_81 ;
const char * V_32 ;
int V_82 , V_45 , V_86 ;
V_70 = F_42 ( & V_87 [ V_77 ] . V_88 , struct V_2 ,
V_89 ) ;
V_85 = 0 ;
for ( V_86 = 1 ; V_86 < V_87 [ V_77 ] . V_90 ; V_86 ++ ) {
V_84 = F_1 ( V_70 ) ;
V_81 = F_3 ( V_84 , L_37 , & V_82 ) ;
for ( V_45 = 0 ; V_45 < ( V_82 / sizeof( T_4 ) ) ; V_45 ++ ) {
if ( V_81 [ V_45 ] == V_85 )
continue;
V_83 = F_43 ( V_81 [ V_45 ] ) ;
if ( ! V_83 )
continue;
V_32 = F_3 ( V_83 , L_7 , NULL ) ;
if ( ! V_32 )
continue;
if ( strcmp ( V_32 , L_26 ) == 0 ) {
V_2 = F_39 ( V_77 , V_83 ) ;
V_85 = V_84 -> T_4 ;
} else {
V_2 = F_40 ( V_77 , V_83 , V_84 ) ;
if ( ! V_2 )
continue;
if ( ! strcmp ( V_32 , L_38 ) ) {
V_70 -> V_73 = 1 ;
V_2 -> V_73 = 1 ;
}
V_85 = V_83 -> T_4 ;
}
F_35 ( & V_2 -> V_75 , & V_70 -> V_75 ) ;
V_70 = V_2 ;
break;
}
}
}
static void F_44 ( void )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_60 ; V_77 ++ )
F_41 ( V_77 ) ;
}
static int T_2 F_45 ( void )
{
if ( F_36 () ) {
F_44 () ;
} else {
long V_91 = F_46 () ;
if ( F_47 ( V_91 , L_39 ) )
F_34 () ;
else
F_8 ( L_40 ) ;
}
return 0 ;
}
