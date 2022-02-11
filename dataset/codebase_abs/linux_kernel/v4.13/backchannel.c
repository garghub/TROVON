static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
F_3 ( & V_6 -> V_10 ) ;
F_4 ( & V_9 -> V_11 ) ;
F_5 ( & V_6 -> V_10 ) ;
F_6 ( V_9 ) ;
F_7 ( V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 ;
struct V_8 * V_9 ;
T_1 V_14 ;
V_9 = F_9 ( V_2 ) ;
if ( F_10 ( V_9 ) )
return F_11 ( V_9 ) ;
V_9 -> V_15 = true ;
V_13 = F_12 ( V_16 ,
V_17 , V_18 ) ;
if ( F_10 ( V_13 ) )
goto V_19;
V_9 -> V_20 = V_13 ;
V_14 = V_2 -> V_21 . V_22 ;
V_13 = F_12 ( V_14 , V_17 , V_18 ) ;
if ( F_10 ( V_13 ) )
goto V_19;
V_9 -> V_23 = V_13 ;
F_13 ( & V_4 -> V_24 , V_13 -> V_25 ,
F_14 ( T_1 , V_14 , V_26 ) ) ;
F_15 ( V_4 , V_9 ) ;
return 0 ;
V_19:
F_1 ( V_2 , V_4 ) ;
return - V_27 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_28 )
{
struct V_29 * V_30 ;
int V_31 = 0 ;
while ( V_28 -- ) {
V_30 = F_17 ( V_2 ) ;
if ( F_10 ( V_30 ) ) {
F_18 ( L_1 ,
V_32 ) ;
V_31 = F_11 ( V_30 ) ;
break;
}
F_19 ( V_30 ) ;
}
return V_31 ;
}
int F_20 ( struct V_33 * V_34 , unsigned int V_35 )
{
struct V_1 * V_2 = F_21 ( V_34 ) ;
struct V_5 * V_36 = & V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned int V_37 ;
int V_31 ;
if ( V_35 > V_38 >> 1 )
goto V_39;
for ( V_37 = 0 ; V_37 < ( V_35 << 1 ) ; V_37 ++ ) {
V_4 = F_22 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
goto V_40;
F_23 ( L_2 , V_32 , V_4 ) ;
V_4 -> V_41 = & V_2 -> V_42 ;
F_24 ( & V_4 -> V_43 ) ;
F_24 ( & V_4 -> V_44 ) ;
if ( F_8 ( V_2 , V_4 ) )
goto V_40;
F_25 ( & V_34 -> V_45 ) ;
F_26 ( & V_4 -> V_46 , & V_34 -> V_47 ) ;
F_27 ( & V_34 -> V_45 ) ;
}
V_31 = F_16 ( V_2 , V_35 ) ;
if ( V_31 )
goto V_40;
V_31 = F_28 ( V_2 , V_35 ) ;
if ( V_31 )
goto V_40;
V_36 -> V_48 = V_35 ;
F_29 ( L_3 ) ;
return 0 ;
V_40:
F_30 ( V_34 , V_35 ) ;
V_39:
F_18 ( L_4 , V_32 ) ;
return - V_27 ;
}
int F_31 ( struct V_49 * V_50 , struct V_51 * V_51 )
{
int V_52 ;
V_52 = F_32 ( V_50 , L_5 , V_51 , V_53 , 0 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
return 0 ;
}
T_1 F_33 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_21 ( V_34 ) ;
struct V_54 * V_55 = & V_2 -> V_21 ;
T_1 V_56 ;
V_56 = F_14 (unsigned int, cdata->inline_rsize, cdata->inline_wsize) ;
V_56 = F_14 (unsigned int, maxmsg, PAGE_SIZE) ;
return V_56 - V_57 ;
}
int F_34 ( struct V_3 * V_4 )
{
struct V_33 * V_34 = V_4 -> V_41 ;
struct V_1 * V_2 = F_21 ( V_34 ) ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_58 * V_59 ;
V_59 = F_35 ( V_9 -> V_20 ) ;
V_59 -> V_60 = V_4 -> V_61 ;
V_59 -> V_62 = V_63 ;
V_59 -> V_64 =
F_36 ( V_2 -> V_7 . V_48 ) ;
V_59 -> V_65 = V_66 ;
V_59 -> V_67 . V_68 [ 0 ] = V_69 ;
V_59 -> V_67 . V_68 [ 1 ] = V_69 ;
V_59 -> V_67 . V_68 [ 2 ] = V_69 ;
if ( ! F_37 ( & V_2 -> V_70 , V_9 , V_57 ,
& V_4 -> V_24 , V_71 ) )
return - V_72 ;
return 0 ;
}
void F_30 ( struct V_33 * V_34 , unsigned int V_35 )
{
struct V_1 * V_2 = F_21 ( V_34 ) ;
struct V_3 * V_4 , * V_73 ;
F_25 ( & V_34 -> V_45 ) ;
F_38 (rqst, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_4 ( & V_4 -> V_46 ) ;
F_27 ( & V_34 -> V_45 ) ;
F_1 ( V_2 , V_4 ) ;
F_25 ( & V_34 -> V_45 ) ;
}
F_27 ( & V_34 -> V_45 ) ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_33 * V_34 = V_4 -> V_41 ;
F_23 ( L_6 ,
V_32 , V_4 , F_2 ( V_4 ) ) ;
F_40 () ;
F_41 ( ! F_42 ( V_74 , & V_4 -> V_75 ) ) ;
F_43 ( V_74 , & V_4 -> V_75 ) ;
F_44 () ;
F_25 ( & V_34 -> V_45 ) ;
F_45 ( & V_4 -> V_46 , & V_34 -> V_47 ) ;
F_27 ( & V_34 -> V_45 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_33 * V_34 = & V_2 -> V_42 ;
struct V_58 * V_59 ;
struct V_49 * V_76 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
struct V_77 * V_6 ;
T_1 V_14 ;
T_2 * V_78 ;
V_59 = F_35 ( V_30 -> V_79 ) ;
#ifdef F_47
F_48 ( L_7 ,
V_32 , F_49 ( V_59 -> V_60 ) , V_30 -> V_80 ) ;
F_48 ( L_8 , V_32 , V_30 -> V_80 , V_59 ) ;
#endif
if ( V_30 -> V_80 < V_57 + 24 )
goto V_81;
V_78 = ( T_2 * ) ( ( unsigned char * ) V_59 + V_57 ) ;
V_14 = V_30 -> V_80 - V_57 ;
F_3 ( & V_34 -> V_45 ) ;
if ( F_50 ( & V_34 -> V_47 ) ) {
F_5 ( & V_34 -> V_45 ) ;
goto V_82;
}
V_4 = F_51 ( & V_34 -> V_47 ,
struct V_3 , V_46 ) ;
F_4 ( & V_4 -> V_46 ) ;
F_5 ( & V_34 -> V_45 ) ;
F_23 ( L_9 , V_32 , V_4 ) ;
V_4 -> V_83 = 0 ;
V_4 -> V_84 = 0 ;
V_4 -> V_61 = V_59 -> V_60 ;
V_4 -> V_85 . V_86 = V_14 ;
F_52 ( V_74 , & V_4 -> V_75 ) ;
V_6 = & V_4 -> V_87 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_88 [ 0 ] . V_89 = V_78 ;
V_6 -> V_88 [ 0 ] . V_90 = V_14 ;
V_6 -> V_86 = V_14 ;
V_9 = F_2 ( V_4 ) ;
F_23 ( L_10 ,
V_32 , V_30 , V_9 ) ;
V_9 -> V_91 = V_30 ;
V_9 -> V_92 = 0 ;
V_76 = V_34 -> V_76 ;
F_3 ( & V_76 -> V_93 ) ;
F_26 ( & V_4 -> V_44 , & V_76 -> V_94 ) ;
F_5 ( & V_76 -> V_93 ) ;
F_53 ( & V_76 -> V_95 ) ;
V_2 -> V_96 . V_97 ++ ;
return;
V_82:
F_54 ( L_11 ) ;
F_55 ( V_34 ) ;
return;
V_81:
F_54 ( L_12 ) ;
if ( F_56 ( & V_2 -> V_70 , V_30 ) )
F_55 ( V_34 ) ;
else
F_54 ( L_13 ,
V_32 , V_30 ) ;
}
