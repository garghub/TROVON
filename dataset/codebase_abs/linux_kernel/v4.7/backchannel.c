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
if ( F_10 ( V_9 ) )
return F_11 ( V_9 ) ;
V_9 -> V_19 = true ;
V_18 = F_12 ( V_4 ) ;
V_16 = F_13 ( V_14 , V_18 , V_20 ) ;
if ( F_10 ( V_16 ) )
goto V_21;
V_9 -> V_22 = V_16 ;
V_18 += F_14 ( V_4 ) ;
V_16 = F_13 ( V_14 , V_18 , V_20 ) ;
if ( F_10 ( V_16 ) )
goto V_21;
V_16 -> V_23 = V_9 ;
V_9 -> V_24 = V_16 ;
V_4 -> V_25 = ( void * ) V_9 -> V_24 -> V_26 ;
V_6 = & V_4 -> V_27 ;
V_6 -> V_28 [ 0 ] . V_29 = V_4 -> V_25 ;
V_6 -> V_28 [ 0 ] . V_30 = 0 ;
V_6 -> V_31 [ 0 ] . V_29 = NULL ;
V_6 -> V_31 [ 0 ] . V_30 = 0 ;
V_6 -> V_32 = 0 ;
V_6 -> V_33 = 0 ;
V_6 -> V_34 = V_18 ;
return 0 ;
V_21:
F_1 ( V_2 , V_4 ) ;
return - V_35 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
struct V_37 * V_38 ;
int V_39 = 0 ;
while ( V_36 -- ) {
V_38 = F_16 ( V_2 ) ;
if ( F_10 ( V_38 ) ) {
F_17 ( L_1 ,
V_40 ) ;
V_39 = F_11 ( V_38 ) ;
break;
}
F_18 ( V_38 ) ;
}
return V_39 ;
}
int F_19 ( struct V_41 * V_42 , unsigned int V_43 )
{
struct V_1 * V_2 = F_20 ( V_42 ) ;
struct V_5 * V_44 = & V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned int V_45 ;
int V_39 ;
if ( V_43 > V_46 >> 1 )
goto V_47;
for ( V_45 = 0 ; V_45 < ( V_43 << 1 ) ; V_45 ++ ) {
V_4 = F_21 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 ) {
F_17 ( L_2 ,
V_40 ) ;
goto V_48;
}
F_22 ( L_3 , V_40 , V_4 ) ;
V_4 -> V_49 = & V_2 -> V_50 ;
F_23 ( & V_4 -> V_51 ) ;
F_23 ( & V_4 -> V_52 ) ;
if ( F_8 ( V_2 , V_4 ) )
goto V_48;
F_24 ( & V_42 -> V_53 ) ;
F_25 ( & V_4 -> V_54 , & V_42 -> V_55 ) ;
F_26 ( & V_42 -> V_53 ) ;
}
V_39 = F_15 ( V_2 , V_43 ) ;
if ( V_39 )
goto V_48;
V_39 = F_27 ( V_2 , V_43 ) ;
if ( V_39 )
goto V_48;
V_44 -> V_56 = V_43 ;
F_28 ( L_4 ) ;
return 0 ;
V_48:
F_29 ( V_42 , V_43 ) ;
V_47:
F_17 ( L_5 , V_40 ) ;
return - V_35 ;
}
int F_30 ( struct V_57 * V_58 , struct V_59 * V_59 )
{
int V_60 ;
V_60 = F_31 ( V_58 , L_6 , V_59 , V_61 , 0 , 0 ) ;
if ( V_60 < 0 )
return V_60 ;
return 0 ;
}
T_1 F_32 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_20 ( V_42 ) ;
struct V_62 * V_63 = & V_2 -> V_64 ;
T_1 V_65 ;
V_65 = F_33 (unsigned int, cdata->inline_rsize, cdata->inline_wsize) ;
return V_65 - V_66 ;
}
int F_34 ( struct V_3 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_49 ;
struct V_1 * V_2 = F_20 ( V_42 ) ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_67 * V_68 ;
T_1 V_69 ;
V_68 = F_35 ( V_9 -> V_22 ) ;
V_68 -> V_70 = V_4 -> V_71 ;
V_68 -> V_72 = V_73 ;
V_68 -> V_74 =
F_36 ( V_2 -> V_7 . V_56 ) ;
V_68 -> V_75 = V_76 ;
V_68 -> V_77 . V_78 [ 0 ] = V_79 ;
V_68 -> V_77 . V_78 [ 1 ] = V_79 ;
V_68 -> V_77 . V_78 [ 2 ] = V_79 ;
V_69 = V_4 -> V_80 [ 0 ] . V_30 ;
#ifdef F_37
F_38 ( L_7 ,
V_40 , V_69 , V_68 , F_39 ( V_9 -> V_22 ) ) ;
F_38 ( L_8 ,
V_40 , ( int ) V_66 , V_68 ) ;
F_38 ( L_9 ,
V_40 , ( int ) V_69 , V_4 -> V_80 [ 0 ] . V_29 ) ;
#endif
V_9 -> V_81 [ 0 ] . V_82 = F_40 ( V_9 -> V_22 ) ;
V_9 -> V_81 [ 0 ] . V_83 = V_66 ;
V_9 -> V_81 [ 0 ] . V_84 = F_39 ( V_9 -> V_22 ) ;
V_9 -> V_81 [ 1 ] . V_82 = F_40 ( V_9 -> V_24 ) ;
V_9 -> V_81 [ 1 ] . V_83 = V_69 ;
V_9 -> V_81 [ 1 ] . V_84 = F_39 ( V_9 -> V_24 ) ;
V_9 -> V_85 = 2 ;
return 0 ;
}
void F_29 ( struct V_41 * V_42 , unsigned int V_43 )
{
struct V_1 * V_2 = F_20 ( V_42 ) ;
struct V_3 * V_4 , * V_86 ;
F_24 ( & V_42 -> V_53 ) ;
F_41 (rqst, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_4 ( & V_4 -> V_54 ) ;
F_26 ( & V_42 -> V_53 ) ;
F_1 ( V_2 , V_4 ) ;
F_24 ( & V_42 -> V_53 ) ;
}
F_26 ( & V_42 -> V_53 ) ;
}
void F_42 ( struct V_3 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_49 ;
F_22 ( L_10 ,
V_40 , V_4 , F_2 ( V_4 ) ) ;
F_43 () ;
F_44 ( ! F_45 ( V_87 , & V_4 -> V_88 ) ) ;
F_46 ( V_87 , & V_4 -> V_88 ) ;
F_47 () ;
F_24 ( & V_42 -> V_53 ) ;
F_48 ( & V_4 -> V_54 , & V_42 -> V_55 ) ;
F_26 ( & V_42 -> V_53 ) ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_41 * V_42 = & V_2 -> V_50 ;
struct V_67 * V_68 ;
struct V_57 * V_89 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
struct V_17 * V_6 ;
T_1 V_18 ;
T_2 * V_90 ;
V_68 = F_35 ( V_38 -> V_91 ) ;
#ifdef F_37
F_38 ( L_11 ,
V_40 , F_50 ( V_68 -> V_70 ) , V_38 -> V_92 ) ;
F_38 ( L_12 , V_40 , V_38 -> V_92 , V_68 ) ;
#endif
if ( V_38 -> V_92 < V_66 + 24 )
goto V_93;
V_90 = ( T_2 * ) ( ( unsigned char * ) V_68 + V_66 ) ;
V_18 = V_38 -> V_92 - V_66 ;
F_3 ( & V_42 -> V_53 ) ;
if ( F_51 ( & V_42 -> V_55 ) ) {
F_5 ( & V_42 -> V_53 ) ;
goto V_94;
}
V_4 = F_52 ( & V_42 -> V_55 ,
struct V_3 , V_54 ) ;
F_4 ( & V_4 -> V_54 ) ;
F_5 ( & V_42 -> V_53 ) ;
F_22 ( L_13 , V_40 , V_4 ) ;
V_4 -> V_95 = 0 ;
V_4 -> V_96 = 0 ;
V_4 -> V_71 = V_68 -> V_70 ;
V_4 -> V_97 . V_33 = V_18 ;
F_53 ( V_87 , & V_4 -> V_88 ) ;
V_6 = & V_4 -> V_98 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_28 [ 0 ] . V_29 = V_90 ;
V_6 -> V_28 [ 0 ] . V_30 = V_18 ;
V_6 -> V_33 = V_18 ;
V_9 = F_2 ( V_4 ) ;
F_22 ( L_14 ,
V_40 , V_38 , V_9 ) ;
V_9 -> V_99 = V_38 ;
V_9 -> V_100 = 0 ;
V_89 = V_42 -> V_89 ;
F_3 ( & V_89 -> V_101 ) ;
F_25 ( & V_4 -> V_52 , & V_89 -> V_102 ) ;
F_5 ( & V_89 -> V_101 ) ;
F_54 ( & V_89 -> V_103 ) ;
V_2 -> V_104 . V_105 ++ ;
return;
V_94:
F_55 ( L_15 ) ;
F_56 ( V_42 ) ;
return;
V_93:
F_55 ( L_16 ) ;
if ( F_57 ( & V_2 -> V_12 , & V_2 -> V_106 , V_38 ) )
F_56 ( V_42 ) ;
else
F_55 ( L_17 ,
V_40 , V_38 ) ;
}
