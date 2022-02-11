void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
if ( ! F_6 ( & V_2 -> V_4 ) )
F_7 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static struct V_1
* F_8 ( struct V_1 * V_6 )
{
struct V_1 * V_2 , * V_7 = NULL ;
F_9 ( & V_3 ) ;
F_10 (nst, &nst_start->st_net_debug_item,
st_net_debug_item) {
if ( & V_2 -> V_4 == & V_5 )
break;
if ( V_2 -> V_8 != NULL ) {
V_7 = V_2 ;
break;
}
}
return V_7 ;
}
static void * F_11 ( struct V_9 * V_10 , T_1 * V_11 )
{
struct V_1 * V_2 , * V_12 = V_10 -> V_13 ;
F_2 ( & V_3 ) ;
V_2 = F_8 ( V_12 ) ;
F_4 ( & V_3 ) ;
return V_2 ;
}
static void * F_12 ( struct V_9 * V_10 , void * V_14 , T_1 * V_11 )
{
struct V_1 * V_2 , * V_12 = V_10 -> V_13 ;
F_2 ( & V_3 ) ;
V_2 = F_8 ( V_12 ) ;
F_7 ( & V_12 -> V_4 ) ;
if ( V_2 )
F_3 ( & V_12 -> V_4 ,
& V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
return V_2 ;
}
static int F_13 ( struct V_9 * V_10 , void * V_14 )
{
struct V_1 * V_2 , * V_12 = V_10 -> V_13 ;
T_2 V_15 ;
T_3 V_16 , V_17 , V_18 ;
F_2 ( & V_3 ) ;
V_2 = F_8 ( V_12 ) ;
if ( ! V_2 )
goto V_19;
V_15 = F_14 () ;
V_16 = F_15 ( F_16 ( V_15 , V_2 -> V_20 ) ) ;
V_17 = F_15 ( F_16 ( V_15 , V_2 -> V_21 ) ) ;
V_18 = F_15 ( F_16 ( V_15 , V_2 -> V_22 ) ) ;
F_17 ( V_10 , L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12 ,
V_2 , ( unsigned long ) F_18 ( V_2 -> V_8 ) ,
( unsigned long ) V_2 -> V_8 -> V_23 ,
V_2 -> V_8 -> V_24 , V_2 -> V_25 ,
V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_28 ,
V_2 -> V_29 ,
( long long ) V_16 ,
( long long ) V_17 ,
( long long ) V_18 ) ;
V_19:
F_4 ( & V_3 ) ;
return 0 ;
}
static void F_19 ( struct V_9 * V_10 , void * V_14 )
{
}
static int F_20 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
struct V_1 * V_12 ;
struct V_9 * V_10 ;
int V_7 ;
V_12 = F_21 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_12 == NULL ) {
V_7 = - V_33 ;
goto V_19;
}
V_12 -> V_8 = NULL ;
V_7 = F_22 ( V_31 , & V_34 ) ;
if ( V_7 )
goto V_19;
V_10 = V_31 -> V_35 ;
V_10 -> V_13 = V_12 ;
F_1 ( V_12 ) ;
V_12 = NULL ;
V_19:
F_23 ( V_12 ) ;
return V_7 ;
}
static int F_24 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_35 ;
struct V_1 * V_12 = V_10 -> V_13 ;
F_5 ( V_12 ) ;
return F_25 ( V_30 , V_31 ) ;
}
void F_26 ( struct V_36 * V_37 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_37 -> V_38 , & V_39 ) ;
F_4 ( & V_3 ) ;
}
void F_27 ( struct V_36 * V_37 )
{
F_2 ( & V_3 ) ;
F_7 ( & V_37 -> V_38 ) ;
F_4 ( & V_3 ) ;
}
static struct V_36
* F_28 ( struct V_36 * V_40 )
{
struct V_36 * V_37 , * V_7 = NULL ;
F_9 ( & V_3 ) ;
F_10 (sc, &sc_start->sc_net_debug_item,
sc_net_debug_item) {
if ( & V_37 -> V_38 == & V_39 )
break;
if ( V_37 -> V_41 != NULL ) {
V_7 = V_37 ;
break;
}
}
return V_7 ;
}
static void * F_29 ( struct V_9 * V_10 , T_1 * V_11 )
{
struct V_42 * V_43 = V_10 -> V_13 ;
struct V_36 * V_37 , * V_44 = V_43 -> V_45 ;
F_2 ( & V_3 ) ;
V_37 = F_28 ( V_44 ) ;
F_4 ( & V_3 ) ;
return V_37 ;
}
static void * F_30 ( struct V_9 * V_10 , void * V_14 , T_1 * V_11 )
{
struct V_42 * V_43 = V_10 -> V_13 ;
struct V_36 * V_37 , * V_44 = V_43 -> V_45 ;
F_2 ( & V_3 ) ;
V_37 = F_28 ( V_44 ) ;
F_7 ( & V_44 -> V_38 ) ;
if ( V_37 )
F_3 ( & V_44 -> V_38 , & V_37 -> V_38 ) ;
F_4 ( & V_3 ) ;
return V_37 ;
}
static void F_31 ( struct V_9 * V_10 ,
struct V_36 * V_37 )
{
if ( ! V_37 )
return;
F_17 ( V_10 , L_13 , V_46 ,
V_37 -> V_47 -> V_48 , ( unsigned long ) F_32 ( V_37 ) ,
( long long ) F_33 ( V_37 ) ,
( long long ) F_34 ( V_37 ) ,
( long long ) F_35 ( V_37 ) ,
( unsigned long ) F_36 ( V_37 ) ,
( long long ) F_37 ( V_37 ) ) ;
}
static void F_38 ( struct V_9 * V_10 ,
struct V_36 * V_37 )
{
struct V_49 * V_50 = NULL ;
T_4 V_51 = 0 , V_52 = 0 ;
T_5 V_53 = 0 , V_54 = 0 ;
if ( ! V_37 )
return;
if ( V_37 -> V_55 ) {
V_50 = F_39 ( V_37 -> V_55 -> V_56 ) ;
V_51 = ( V_57 T_4 ) V_50 -> V_58 ;
V_52 = ( V_57 T_4 ) V_50 -> V_59 ;
V_53 = ( V_57 T_5 ) V_50 -> V_60 ;
V_54 = ( V_57 T_5 ) V_50 -> V_61 ;
}
F_17 ( V_10 , L_1
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27 ,
V_37 ,
F_40 ( & V_37 -> V_62 . V_63 ) ,
& V_51 , V_50 ? F_41 ( V_53 ) : 0 ,
& V_52 , V_50 ? F_41 ( V_54 ) : 0 ,
V_37 -> V_47 -> V_64 ,
V_37 -> V_65 ,
V_37 -> V_66 ,
( long long ) F_15 ( V_37 -> V_67 ) ,
( long long ) F_15 ( V_37 -> V_68 ) ,
( long long ) F_15 ( V_37 -> V_69 ) ,
( long long ) F_15 ( V_37 -> V_70 ) ,
( long long ) F_15 ( V_37 -> V_71 ) ,
( long long ) F_15 ( V_37 -> V_72 ) ,
V_37 -> V_73 ,
V_37 -> V_74 ) ;
}
static int F_42 ( struct V_9 * V_10 , void * V_14 )
{
struct V_42 * V_43 = V_10 -> V_13 ;
struct V_36 * V_37 , * V_44 = V_43 -> V_45 ;
F_2 ( & V_3 ) ;
V_37 = F_28 ( V_44 ) ;
if ( V_37 ) {
if ( V_43 -> V_75 == V_76 )
F_38 ( V_10 , V_37 ) ;
else
F_31 ( V_10 , V_37 ) ;
}
F_4 ( & V_3 ) ;
return 0 ;
}
static void F_43 ( struct V_9 * V_10 , void * V_14 )
{
}
static int F_44 ( struct V_31 * V_31 , struct V_42 * V_43 )
{
struct V_36 * V_44 ;
struct V_9 * V_10 ;
int V_7 ;
V_44 = F_21 ( sizeof( struct V_36 ) , V_32 ) ;
if ( V_44 == NULL ) {
V_7 = - V_33 ;
goto V_19;
}
V_44 -> V_41 = NULL ;
V_7 = F_22 ( V_31 , & V_77 ) ;
if ( V_7 )
goto V_19;
V_10 = V_31 -> V_35 ;
V_10 -> V_13 = V_43 ;
V_43 -> V_45 = V_44 ;
F_26 ( V_44 ) ;
V_44 = NULL ;
V_19:
F_23 ( V_44 ) ;
return V_7 ;
}
static int F_45 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_35 ;
struct V_42 * V_43 = V_10 -> V_13 ;
struct V_36 * V_44 = V_43 -> V_45 ;
F_27 ( V_44 ) ;
return F_25 ( V_30 , V_31 ) ;
}
static int F_46 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
struct V_42 * V_43 ;
V_43 = F_21 ( sizeof( struct V_42 ) , V_32 ) ;
if ( V_43 == NULL )
return - V_33 ;
V_43 -> V_75 = V_78 ;
V_43 -> V_45 = NULL ;
return F_44 ( V_31 , V_43 ) ;
}
static int F_47 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
struct V_42 * V_43 ;
V_43 = F_21 ( sizeof( struct V_42 ) , V_32 ) ;
if ( V_43 == NULL )
return - V_33 ;
V_43 -> V_75 = V_76 ;
V_43 -> V_45 = NULL ;
return F_44 ( V_31 , V_43 ) ;
}
static int F_48 ( char * V_79 , int V_80 )
{
unsigned long V_81 [ F_49 ( V_82 ) ] ;
int V_83 = - 1 , V_19 = 0 ;
F_50 ( V_81 , sizeof( V_81 ) ) ;
while ( ( V_83 = F_51 ( V_81 , V_82 , V_83 + 1 ) ) < V_82 )
V_19 += snprintf ( V_79 + V_19 , V_84 - V_19 , L_28 , V_83 ) ;
V_19 += snprintf ( V_79 + V_19 , V_84 - V_19 , L_29 ) ;
return V_19 ;
}
static int F_52 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
char * V_79 ;
V_79 = F_21 ( V_84 , V_32 ) ;
if ( ! V_79 )
return - V_33 ;
F_53 ( V_30 , F_48 ( V_79 , V_84 ) ) ;
V_31 -> V_35 = V_79 ;
return 0 ;
}
static int F_54 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
F_23 ( V_31 -> V_35 ) ;
return 0 ;
}
static T_6 F_55 ( struct V_31 * V_31 , char T_7 * V_79 ,
T_8 V_85 , T_1 * V_86 )
{
return F_56 ( V_79 , V_85 , V_86 , V_31 -> V_35 ,
F_57 ( V_31 -> V_87 -> V_88 ) ) ;
}
void F_58 ( void )
{
F_59 ( V_89 ) ;
F_59 ( V_90 ) ;
F_59 ( V_91 ) ;
F_59 ( V_92 ) ;
F_59 ( V_93 ) ;
}
int F_60 ( void )
{
T_9 V_94 = V_95 | V_96 ;
V_93 = F_61 ( V_97 , NULL ) ;
if ( V_93 )
V_92 = F_62 ( V_98 , V_94 ,
V_93 , NULL , & V_99 ) ;
if ( V_92 )
V_91 = F_62 ( V_100 , V_94 ,
V_93 , NULL , & V_101 ) ;
if ( V_91 )
V_90 = F_62 ( V_102 , V_94 ,
V_93 , NULL , & V_103 ) ;
if ( V_90 )
V_89 = F_62 ( V_104 , V_94 ,
V_93 , NULL , & V_105 ) ;
if ( V_89 )
return 0 ;
F_58 () ;
F_63 ( - V_33 ) ;
return - V_33 ;
}
