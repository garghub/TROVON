static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 ) ;
V_2 -> V_5 ++ ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_6 = F_4 ( V_2 -> V_3 , V_2 -> V_7 ) ;
V_2 -> V_7 ++ ;
if ( V_2 -> V_6 == NULL ) {
V_2 -> V_7 = 0 ;
F_1 ( V_2 ) ;
}
}
static void * F_5 ( struct V_8 * V_9 , T_1 * V_10 )
{
struct V_1 * V_2 = V_11 ;
T_1 V_12 = * V_10 ;
if ( ! V_12 )
goto V_13;
F_6 ( V_9 -> V_14 == NULL ) ;
V_2 = V_9 -> V_14 ;
if ( V_2 -> V_3 == NULL )
F_1 ( V_2 ) ;
else
F_3 ( V_2 ) ;
if ( ( V_2 -> V_3 == NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 = NULL ;
V_13:
return V_2 ;
}
static void * F_7 ( struct V_8 * V_9 , void * V_15 , T_1 * V_12 )
{
( * V_12 ) ++ ;
return NULL ;
}
static void F_8 ( struct V_8 * V_16 , void * V_15 )
{
}
static void F_9 ( struct V_8 * V_9 , void * V_15 )
{
struct V_17 * V_3 = V_15 ;
int V_18 = 0 ;
int V_19 ;
struct V_20 * V_21 ;
struct V_20 * V_22 ;
F_10 ( & V_3 -> V_23 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
F_11 (walk, tmp, &tunnel->session_hlist[hash]) {
struct V_25 * V_6 ;
V_6 = F_12 ( V_21 , struct V_25 , V_26 ) ;
if ( V_6 -> V_27 == 0 )
continue;
V_18 ++ ;
}
}
F_13 ( & V_3 -> V_23 ) ;
F_14 ( V_9 , L_1 , V_3 -> V_28 , V_3 -> V_29 ) ;
if ( V_3 -> V_30 ) {
struct V_31 * V_32 = F_15 ( V_3 -> V_30 ) ;
F_14 ( V_9 , L_2 ,
& V_32 -> V_33 , & V_32 -> V_34 ) ;
if ( V_3 -> V_35 == V_36 )
F_14 ( V_9 , L_3 ,
F_16 ( V_32 -> V_37 ) , F_16 ( V_32 -> V_38 ) ) ;
}
F_14 ( V_9 , L_4 , V_3 -> V_39 ,
V_3 -> V_35 == V_36 ? L_5 :
V_3 -> V_35 == V_40 ? L_6 :
L_7 ) ;
F_14 ( V_9 , L_8 , V_18 ,
V_3 -> V_30 ? F_17 ( & V_3 -> V_30 -> V_41 ) : 0 ,
F_17 ( & V_3 -> V_42 ) ) ;
F_14 ( V_9 , L_9 ,
V_3 -> V_43 ,
( unsigned long long ) V_3 -> V_44 . V_45 ,
( unsigned long long ) V_3 -> V_44 . V_46 ,
( unsigned long long ) V_3 -> V_44 . V_47 ,
( unsigned long long ) V_3 -> V_44 . V_48 ,
( unsigned long long ) V_3 -> V_44 . V_49 ,
( unsigned long long ) V_3 -> V_44 . V_50 ) ;
if ( V_3 -> V_51 != NULL )
V_3 -> V_51 ( V_9 , V_3 ) ;
}
static void F_18 ( struct V_8 * V_9 , void * V_15 )
{
struct V_25 * V_6 = V_15 ;
F_14 ( V_9 , L_10 , V_6 -> V_27 ,
V_6 -> V_52 ,
V_6 -> V_53 == V_54 ? L_11 :
V_6 -> V_53 == V_55 ? L_12 :
L_7 ) ;
if ( V_6 -> V_56 || V_6 -> V_57 )
F_14 ( V_9 , L_13 , V_6 -> V_58 , V_6 -> V_59 ) ;
F_14 ( V_9 , L_14 , F_17 ( & V_6 -> V_42 ) ) ;
F_14 ( V_9 , L_15 ,
V_6 -> V_60 , V_6 -> V_61 ,
V_6 -> V_57 ? 'R' : '-' ,
V_6 -> V_56 ? 'S' : '-' ,
V_6 -> V_62 == 1 ? L_16 :
V_6 -> V_62 == 2 ? L_17 : L_18 ,
V_6 -> V_63 ? L_19 : L_20 ,
V_6 -> V_43 ,
F_19 ( V_6 -> V_64 ) ) ;
F_14 ( V_9 , L_21 ,
V_6 -> V_65 , V_6 -> V_66 , V_6 -> V_67 ) ;
if ( V_6 -> V_68 ) {
F_14 ( V_9 , L_22 ,
V_6 -> V_69 [ 0 ] , V_6 -> V_69 [ 1 ] ,
V_6 -> V_69 [ 2 ] , V_6 -> V_69 [ 3 ] ) ;
if ( V_6 -> V_68 == 8 )
F_14 ( V_9 , L_23 ,
V_6 -> V_69 [ 4 ] , V_6 -> V_69 [ 5 ] ,
V_6 -> V_69 [ 6 ] , V_6 -> V_69 [ 7 ] ) ;
F_14 ( V_9 , L_24 ) ;
}
if ( V_6 -> V_70 ) {
F_14 ( V_9 , L_25 ,
V_6 -> V_71 [ 0 ] , V_6 -> V_71 [ 1 ] ,
V_6 -> V_71 [ 2 ] , V_6 -> V_71 [ 3 ] ) ;
if ( V_6 -> V_70 == 8 )
F_14 ( V_9 , L_23 ,
V_6 -> V_71 [ 4 ] , V_6 -> V_71 [ 5 ] ,
V_6 -> V_71 [ 6 ] , V_6 -> V_71 [ 7 ] ) ;
F_14 ( V_9 , L_24 ) ;
}
F_14 ( V_9 , L_26 ,
V_6 -> V_58 , V_6 -> V_59 ,
( unsigned long long ) V_6 -> V_44 . V_45 ,
( unsigned long long ) V_6 -> V_44 . V_46 ,
( unsigned long long ) V_6 -> V_44 . V_47 ,
( unsigned long long ) V_6 -> V_44 . V_48 ,
( unsigned long long ) V_6 -> V_44 . V_49 ,
( unsigned long long ) V_6 -> V_44 . V_50 ) ;
if ( V_6 -> V_51 != NULL )
V_6 -> V_51 ( V_9 , V_6 ) ;
}
static int F_20 ( struct V_8 * V_9 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
if ( V_15 == V_11 ) {
F_21 ( V_9 , L_27 ) ;
F_21 ( V_9 , L_28 ) ;
F_21 ( V_9 , L_29 ) ;
F_21 ( V_9 , L_30 ) ;
F_21 ( V_9 , L_31 ) ;
F_21 ( V_9 , L_32 ) ;
F_21 ( V_9 , L_33 ) ;
F_21 ( V_9 , L_34 ) ;
F_21 ( V_9 , L_35 ) ;
F_21 ( V_9 , L_36 ) ;
F_21 ( V_9 , L_37 ) ;
goto V_13;
}
if ( V_2 -> V_6 == NULL )
F_9 ( V_9 , V_2 -> V_3 ) ;
else
F_18 ( V_9 , V_2 -> V_6 ) ;
V_13:
return 0 ;
}
static int F_22 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
struct V_1 * V_2 ;
struct V_8 * V_74 ;
int V_75 = - V_76 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_77 ) ;
if ( V_2 == NULL )
goto V_13;
V_2 -> V_4 = F_24 ( V_78 -> V_79 ) ;
if ( F_25 ( V_2 -> V_4 ) ) {
V_75 = F_26 ( V_2 -> V_4 ) ;
goto V_80;
}
V_75 = F_27 ( V_73 , & V_81 ) ;
if ( V_75 )
goto V_82;
V_74 = V_73 -> V_83 ;
V_74 -> V_14 = V_2 ;
V_13:
return V_75 ;
V_82:
F_28 ( V_2 -> V_4 ) ;
V_80:
F_29 ( V_2 ) ;
goto V_13;
}
static int F_30 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
struct V_1 * V_2 ;
struct V_8 * V_74 ;
V_74 = V_73 -> V_83 ;
V_2 = V_74 -> V_14 ;
if ( V_2 -> V_4 )
F_28 ( V_2 -> V_4 ) ;
F_29 ( V_2 ) ;
F_31 ( V_72 , V_73 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
int V_75 = 0 ;
V_84 = F_33 ( L_38 , NULL ) ;
if ( F_25 ( V_84 ) ) {
V_75 = F_26 ( V_84 ) ;
V_84 = NULL ;
goto V_13;
}
V_85 = F_34 ( L_39 , 0600 , V_84 , NULL , & V_86 ) ;
if ( V_85 == NULL )
V_75 = - V_87 ;
F_35 ( V_88 L_40 ) ;
V_13:
if ( V_75 )
F_35 ( V_89 L_41 ) ;
return V_75 ;
}
static void T_3 F_36 ( void )
{
F_37 ( V_85 ) ;
F_37 ( V_84 ) ;
}
