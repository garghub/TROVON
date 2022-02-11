static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
F_3 ( & V_6 -> V_10 ) ;
F_4 ( & V_9 -> V_11 ) ;
F_5 ( & V_6 -> V_10 ) ;
F_6 ( & V_2 -> V_12 , V_9 ) ;
F_7 ( V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 = & V_2 -> V_12 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
struct V_17 * V_6 ;
T_1 V_18 ;
V_9 = F_9 ( V_2 ) ;
if ( ! V_9 )
return - V_19 ;
V_9 -> V_20 = true ;
V_18 = F_10 ( V_4 ) ;
V_16 = F_11 ( V_14 , V_18 , V_21 ) ;
if ( F_12 ( V_16 ) )
goto V_22;
V_9 -> V_23 = V_16 ;
V_18 += F_13 ( V_4 ) ;
V_16 = F_11 ( V_14 , V_18 , V_21 ) ;
if ( F_12 ( V_16 ) )
goto V_22;
V_16 -> V_24 = V_9 ;
V_9 -> V_25 = V_16 ;
V_4 -> V_26 = ( void * ) V_9 -> V_25 -> V_27 ;
V_6 = & V_4 -> V_28 ;
V_6 -> V_29 [ 0 ] . V_30 = V_4 -> V_26 ;
V_6 -> V_29 [ 0 ] . V_31 = 0 ;
V_6 -> V_32 [ 0 ] . V_30 = NULL ;
V_6 -> V_32 [ 0 ] . V_31 = 0 ;
V_6 -> V_33 = 0 ;
V_6 -> V_34 = 0 ;
V_6 -> V_35 = V_18 ;
return 0 ;
V_22:
F_1 ( V_2 , V_4 ) ;
return - V_19 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
struct V_5 * V_37 = & V_2 -> V_7 ;
struct V_38 * V_39 ;
unsigned long V_40 ;
int V_41 = 0 ;
while ( V_36 -- ) {
V_39 = F_15 ( V_2 ) ;
if ( F_12 ( V_39 ) ) {
F_16 ( L_1 ,
V_42 ) ;
V_41 = F_17 ( V_39 ) ;
break;
}
F_18 ( & V_37 -> V_43 , V_40 ) ;
F_19 ( & V_39 -> V_44 , & V_37 -> V_45 ) ;
F_20 ( & V_37 -> V_43 , V_40 ) ;
}
return V_41 ;
}
int F_21 ( struct V_46 * V_47 , unsigned int V_48 )
{
struct V_1 * V_2 = F_22 ( V_47 ) ;
struct V_5 * V_49 = & V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned int V_50 ;
int V_41 ;
if ( V_48 > V_51 >> 1 )
goto V_52;
for ( V_50 = 0 ; V_50 < ( V_48 << 1 ) ; V_50 ++ ) {
V_4 = F_23 ( sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 ) {
F_16 ( L_2 ,
V_42 ) ;
goto V_53;
}
V_4 -> V_54 = & V_2 -> V_55 ;
F_24 ( & V_4 -> V_56 ) ;
F_24 ( & V_4 -> V_57 ) ;
if ( F_8 ( V_2 , V_4 ) )
goto V_53;
F_25 ( & V_47 -> V_58 ) ;
F_19 ( & V_4 -> V_59 , & V_47 -> V_60 ) ;
F_26 ( & V_47 -> V_58 ) ;
}
V_41 = F_14 ( V_2 , V_48 ) ;
if ( V_41 )
goto V_53;
V_41 = F_27 ( V_2 , V_48 ) ;
if ( V_41 )
goto V_53;
V_49 -> V_61 = V_48 ;
F_28 ( L_3 ) ;
return 0 ;
V_53:
F_29 ( V_47 , V_48 ) ;
V_52:
F_16 ( L_4 , V_42 ) ;
return - V_19 ;
}
int F_30 ( struct V_62 * V_63 , struct V_64 * V_64 )
{
int V_65 ;
V_65 = F_31 ( V_63 , L_5 , V_64 , V_66 , 0 , 0 ) ;
if ( V_65 < 0 )
return V_65 ;
return 0 ;
}
int F_32 ( struct V_3 * V_4 )
{
struct V_46 * V_47 = V_4 -> V_54 ;
struct V_1 * V_2 = F_22 ( V_47 ) ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_67 * V_68 ;
T_1 V_69 ;
V_68 = F_33 ( V_9 -> V_23 ) ;
V_68 -> V_70 = V_4 -> V_71 ;
V_68 -> V_72 = V_73 ;
V_68 -> V_74 =
F_34 ( V_2 -> V_7 . V_61 ) ;
V_68 -> V_75 = V_76 ;
V_68 -> V_77 . V_78 [ 0 ] = V_79 ;
V_68 -> V_77 . V_78 [ 1 ] = V_79 ;
V_68 -> V_77 . V_78 [ 2 ] = V_79 ;
V_69 = V_4 -> V_80 [ 0 ] . V_31 ;
F_35 ( L_6 ,
V_42 , V_69 , V_68 , F_36 ( V_9 -> V_23 ) ) ;
F_35 ( L_7 ,
V_42 , ( int ) V_81 , V_68 ) ;
F_35 ( L_8 ,
V_42 , ( int ) V_69 , V_4 -> V_80 [ 0 ] . V_30 ) ;
V_9 -> V_82 [ 0 ] . V_83 = F_37 ( V_9 -> V_23 ) ;
V_9 -> V_82 [ 0 ] . V_84 = V_81 ;
V_9 -> V_82 [ 0 ] . V_85 = F_36 ( V_9 -> V_23 ) ;
V_9 -> V_82 [ 1 ] . V_83 = F_37 ( V_9 -> V_25 ) ;
V_9 -> V_82 [ 1 ] . V_84 = V_69 ;
V_9 -> V_82 [ 1 ] . V_85 = F_36 ( V_9 -> V_25 ) ;
V_9 -> V_86 = 2 ;
return 0 ;
}
void F_29 ( struct V_46 * V_47 , unsigned int V_48 )
{
struct V_1 * V_2 = F_22 ( V_47 ) ;
struct V_3 * V_4 , * V_87 ;
F_25 ( & V_47 -> V_58 ) ;
F_38 (rqst, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_4 ( & V_4 -> V_59 ) ;
F_26 ( & V_47 -> V_58 ) ;
F_1 ( V_2 , V_4 ) ;
F_25 ( & V_47 -> V_58 ) ;
}
F_26 ( & V_47 -> V_58 ) ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_46 * V_47 = V_4 -> V_54 ;
F_40 () ;
F_41 ( ! F_42 ( V_88 , & V_4 -> V_89 ) ) ;
F_43 ( V_88 , & V_4 -> V_89 ) ;
F_44 () ;
F_25 ( & V_47 -> V_58 ) ;
F_45 ( & V_4 -> V_59 , & V_47 -> V_60 ) ;
F_26 ( & V_47 -> V_58 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_46 * V_47 = & V_2 -> V_55 ;
struct V_67 * V_68 ;
struct V_62 * V_90 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
struct V_17 * V_6 ;
T_1 V_18 ;
T_2 * V_91 ;
V_68 = F_33 ( V_39 -> V_92 ) ;
#ifdef F_47
F_35 ( L_9 ,
V_42 , F_48 ( V_68 -> V_70 ) , V_39 -> V_93 ) ;
F_35 ( L_10 , V_42 , V_39 -> V_93 , V_68 ) ;
#endif
if ( V_39 -> V_93 < V_81 + 24 )
goto V_94;
V_91 = ( T_2 * ) ( ( unsigned char * ) V_68 + V_81 ) ;
V_18 = V_39 -> V_93 - V_81 ;
F_3 ( & V_47 -> V_58 ) ;
if ( F_49 ( & V_47 -> V_60 ) ) {
F_5 ( & V_47 -> V_58 ) ;
goto V_95;
}
V_4 = F_50 ( & V_47 -> V_60 ,
struct V_3 , V_59 ) ;
F_4 ( & V_4 -> V_59 ) ;
F_5 ( & V_47 -> V_58 ) ;
#ifdef F_47
F_35 ( L_11 , V_42 , V_4 ) ;
#endif
V_4 -> V_96 = 0 ;
V_4 -> V_97 = 0 ;
V_4 -> V_71 = V_68 -> V_70 ;
F_51 ( V_88 , & V_4 -> V_89 ) ;
V_6 = & V_4 -> V_98 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_29 [ 0 ] . V_30 = V_91 ;
V_6 -> V_29 [ 0 ] . V_31 = V_18 ;
V_6 -> V_34 = V_18 ;
V_9 = F_2 ( V_4 ) ;
#ifdef F_47
F_35 ( L_12 ,
V_42 , V_39 , V_9 ) ;
#endif
V_9 -> V_99 = V_39 ;
V_9 -> V_100 = 0 ;
V_90 = V_47 -> V_90 ;
F_3 ( & V_90 -> V_101 ) ;
F_19 ( & V_4 -> V_57 , & V_90 -> V_102 ) ;
F_5 ( & V_90 -> V_101 ) ;
F_52 ( & V_90 -> V_103 ) ;
V_2 -> V_104 . V_105 ++ ;
return;
V_95:
F_53 ( L_13 ) ;
F_54 ( V_47 ) ;
return;
V_94:
F_53 ( L_14 ) ;
if ( F_55 ( & V_2 -> V_12 , & V_2 -> V_106 , V_39 ) )
F_54 ( V_47 ) ;
else
F_53 ( L_15 ,
V_42 , V_39 ) ;
}
