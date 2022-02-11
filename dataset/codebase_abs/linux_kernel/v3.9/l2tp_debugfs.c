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
#if F_16 ( V_33 )
if ( V_3 -> V_30 -> V_34 == V_35 ) {
struct V_36 * V_37 = F_17 ( V_3 -> V_30 ) ;
F_14 ( V_9 , L_2 ,
& V_37 -> V_38 , & V_37 -> V_39 ) ;
} else
#endif
F_14 ( V_9 , L_3 ,
& V_32 -> V_40 , & V_32 -> V_41 ) ;
if ( V_3 -> V_42 == V_43 )
F_14 ( V_9 , L_4 ,
F_18 ( V_32 -> V_44 ) , F_18 ( V_32 -> V_45 ) ) ;
}
F_14 ( V_9 , L_5 , V_3 -> V_46 ,
V_3 -> V_42 == V_43 ? L_6 :
V_3 -> V_42 == V_47 ? L_7 :
L_8 ) ;
F_14 ( V_9 , L_9 , V_18 ,
V_3 -> V_30 ? F_19 ( & V_3 -> V_30 -> V_48 ) : 0 ,
F_19 ( & V_3 -> V_49 ) ) ;
F_14 ( V_9 , L_10 ,
V_3 -> V_50 ,
F_20 ( & V_3 -> V_51 . V_52 ) ,
F_20 ( & V_3 -> V_51 . V_53 ) ,
F_20 ( & V_3 -> V_51 . V_54 ) ,
F_20 ( & V_3 -> V_51 . V_55 ) ,
F_20 ( & V_3 -> V_51 . V_56 ) ,
F_20 ( & V_3 -> V_51 . V_57 ) ) ;
if ( V_3 -> V_58 != NULL )
V_3 -> V_58 ( V_9 , V_3 ) ;
}
static void F_21 ( struct V_8 * V_9 , void * V_15 )
{
struct V_25 * V_6 = V_15 ;
F_14 ( V_9 , L_11 , V_6 -> V_27 ,
V_6 -> V_59 ,
V_6 -> V_60 == V_61 ? L_12 :
V_6 -> V_60 == V_62 ? L_13 :
L_8 ) ;
if ( V_6 -> V_63 || V_6 -> V_64 )
F_14 ( V_9 , L_14 , V_6 -> V_65 , V_6 -> V_66 ) ;
F_14 ( V_9 , L_15 , F_19 ( & V_6 -> V_49 ) ) ;
F_14 ( V_9 , L_16 ,
V_6 -> V_67 , V_6 -> V_68 ,
V_6 -> V_64 ? 'R' : '-' ,
V_6 -> V_63 ? 'S' : '-' ,
V_6 -> V_69 == 1 ? L_17 :
V_6 -> V_69 == 2 ? L_18 : L_19 ,
V_6 -> V_70 ? L_20 : L_21 ,
V_6 -> V_50 ,
F_22 ( V_6 -> V_71 ) ) ;
F_14 ( V_9 , L_22 ,
V_6 -> V_72 , V_6 -> V_73 , V_6 -> V_74 ) ;
if ( V_6 -> V_75 ) {
F_14 ( V_9 , L_23 ,
V_6 -> V_76 [ 0 ] , V_6 -> V_76 [ 1 ] ,
V_6 -> V_76 [ 2 ] , V_6 -> V_76 [ 3 ] ) ;
if ( V_6 -> V_75 == 8 )
F_14 ( V_9 , L_24 ,
V_6 -> V_76 [ 4 ] , V_6 -> V_76 [ 5 ] ,
V_6 -> V_76 [ 6 ] , V_6 -> V_76 [ 7 ] ) ;
F_14 ( V_9 , L_25 ) ;
}
if ( V_6 -> V_77 ) {
F_14 ( V_9 , L_26 ,
V_6 -> V_78 [ 0 ] , V_6 -> V_78 [ 1 ] ,
V_6 -> V_78 [ 2 ] , V_6 -> V_78 [ 3 ] ) ;
if ( V_6 -> V_77 == 8 )
F_14 ( V_9 , L_24 ,
V_6 -> V_78 [ 4 ] , V_6 -> V_78 [ 5 ] ,
V_6 -> V_78 [ 6 ] , V_6 -> V_78 [ 7 ] ) ;
F_14 ( V_9 , L_25 ) ;
}
F_14 ( V_9 , L_27 ,
V_6 -> V_65 , V_6 -> V_66 ,
F_20 ( & V_6 -> V_51 . V_52 ) ,
F_20 ( & V_6 -> V_51 . V_53 ) ,
F_20 ( & V_6 -> V_51 . V_54 ) ,
F_20 ( & V_6 -> V_51 . V_55 ) ,
F_20 ( & V_6 -> V_51 . V_56 ) ,
F_20 ( & V_6 -> V_51 . V_57 ) ) ;
if ( V_6 -> V_58 != NULL )
V_6 -> V_58 ( V_9 , V_6 ) ;
}
static int F_23 ( struct V_8 * V_9 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
if ( V_15 == V_11 ) {
F_24 ( V_9 , L_28 ) ;
F_24 ( V_9 , L_29 ) ;
F_24 ( V_9 , L_30 ) ;
F_24 ( V_9 , L_31 ) ;
F_24 ( V_9 , L_32 ) ;
F_24 ( V_9 , L_33 ) ;
F_24 ( V_9 , L_34 ) ;
F_24 ( V_9 , L_35 ) ;
F_24 ( V_9 , L_36 ) ;
F_24 ( V_9 , L_37 ) ;
F_24 ( V_9 , L_38 ) ;
goto V_13;
}
if ( V_2 -> V_6 == NULL )
F_9 ( V_9 , V_2 -> V_3 ) ;
else
F_21 ( V_9 , V_2 -> V_6 ) ;
V_13:
return 0 ;
}
static int F_25 ( struct V_79 * V_79 , struct V_80 * V_80 )
{
struct V_1 * V_2 ;
struct V_8 * V_81 ;
int V_82 = - V_83 ;
V_2 = F_26 ( sizeof( * V_2 ) , V_84 ) ;
if ( V_2 == NULL )
goto V_13;
V_2 -> V_4 = F_27 ( V_85 -> V_86 ) ;
if ( F_28 ( V_2 -> V_4 ) ) {
V_82 = F_29 ( V_2 -> V_4 ) ;
goto V_87;
}
V_82 = F_30 ( V_80 , & V_88 ) ;
if ( V_82 )
goto V_89;
V_81 = V_80 -> V_90 ;
V_81 -> V_14 = V_2 ;
V_13:
return V_82 ;
V_89:
F_31 ( V_2 -> V_4 ) ;
V_87:
F_32 ( V_2 ) ;
goto V_13;
}
static int F_33 ( struct V_79 * V_79 , struct V_80 * V_80 )
{
struct V_1 * V_2 ;
struct V_8 * V_81 ;
V_81 = V_80 -> V_90 ;
V_2 = V_81 -> V_14 ;
if ( V_2 -> V_4 )
F_31 ( V_2 -> V_4 ) ;
F_32 ( V_2 ) ;
F_34 ( V_79 , V_80 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
int V_82 = 0 ;
V_91 = F_36 ( L_39 , NULL ) ;
if ( F_28 ( V_91 ) ) {
V_82 = F_29 ( V_91 ) ;
V_91 = NULL ;
goto V_13;
}
V_92 = F_37 ( L_40 , 0600 , V_91 , NULL , & V_93 ) ;
if ( V_92 == NULL )
V_82 = - V_94 ;
F_38 ( L_41 ) ;
V_13:
if ( V_82 )
F_39 ( L_42 ) ;
return V_82 ;
}
static void T_3 F_40 ( void )
{
F_41 ( V_92 ) ;
F_41 ( V_91 ) ;
}
