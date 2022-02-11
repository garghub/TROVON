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
F_13 ( & V_4 -> V_24 , V_13 -> V_25 , V_14 ) ;
F_14 ( V_4 , V_9 ) ;
return 0 ;
V_19:
F_1 ( V_2 , V_4 ) ;
return - V_26 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_27 )
{
struct V_28 * V_29 ;
int V_30 = 0 ;
while ( V_27 -- ) {
V_29 = F_16 ( V_2 ) ;
if ( F_10 ( V_29 ) ) {
F_17 ( L_1 ,
V_31 ) ;
V_30 = F_11 ( V_29 ) ;
break;
}
F_18 ( V_29 ) ;
}
return V_30 ;
}
int F_19 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_1 * V_2 = F_20 ( V_33 ) ;
struct V_5 * V_35 = & V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned int V_36 ;
int V_30 ;
if ( V_34 > V_37 >> 1 )
goto V_38;
for ( V_36 = 0 ; V_36 < ( V_34 << 1 ) ; V_36 ++ ) {
V_4 = F_21 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 ) {
F_17 ( L_2 ,
V_31 ) ;
goto V_39;
}
F_22 ( L_3 , V_31 , V_4 ) ;
V_4 -> V_40 = & V_2 -> V_41 ;
F_23 ( & V_4 -> V_42 ) ;
F_23 ( & V_4 -> V_43 ) ;
if ( F_8 ( V_2 , V_4 ) )
goto V_39;
F_24 ( & V_33 -> V_44 ) ;
F_25 ( & V_4 -> V_45 , & V_33 -> V_46 ) ;
F_26 ( & V_33 -> V_44 ) ;
}
V_30 = F_15 ( V_2 , V_34 ) ;
if ( V_30 )
goto V_39;
V_30 = F_27 ( V_2 , V_34 ) ;
if ( V_30 )
goto V_39;
V_35 -> V_47 = V_34 ;
F_28 ( L_4 ) ;
return 0 ;
V_39:
F_29 ( V_33 , V_34 ) ;
V_38:
F_17 ( L_5 , V_31 ) ;
return - V_26 ;
}
int F_30 ( struct V_48 * V_49 , struct V_50 * V_50 )
{
int V_51 ;
V_51 = F_31 ( V_49 , L_6 , V_50 , V_52 , 0 , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
return 0 ;
}
T_1 F_32 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_20 ( V_33 ) ;
struct V_53 * V_54 = & V_2 -> V_21 ;
T_1 V_55 ;
V_55 = F_33 (unsigned int, cdata->inline_rsize, cdata->inline_wsize) ;
return V_55 - V_56 ;
}
int F_34 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = V_4 -> V_40 ;
struct V_1 * V_2 = F_20 ( V_33 ) ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_57 * V_58 ;
V_58 = F_35 ( V_9 -> V_20 ) ;
V_58 -> V_59 = V_4 -> V_60 ;
V_58 -> V_61 = V_62 ;
V_58 -> V_63 =
F_36 ( V_2 -> V_7 . V_47 ) ;
V_58 -> V_64 = V_65 ;
V_58 -> V_66 . V_67 [ 0 ] = V_68 ;
V_58 -> V_66 . V_67 [ 1 ] = V_68 ;
V_58 -> V_66 . V_67 [ 2 ] = V_68 ;
if ( ! F_37 ( & V_2 -> V_69 , V_9 , V_56 ,
& V_4 -> V_24 , V_70 ) )
return - V_71 ;
return 0 ;
}
void F_29 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_1 * V_2 = F_20 ( V_33 ) ;
struct V_3 * V_4 , * V_72 ;
F_24 ( & V_33 -> V_44 ) ;
F_38 (rqst, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_4 ( & V_4 -> V_45 ) ;
F_26 ( & V_33 -> V_44 ) ;
F_1 ( V_2 , V_4 ) ;
F_24 ( & V_33 -> V_44 ) ;
}
F_26 ( & V_33 -> V_44 ) ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = V_4 -> V_40 ;
F_22 ( L_7 ,
V_31 , V_4 , F_2 ( V_4 ) ) ;
F_40 () ;
F_41 ( ! F_42 ( V_73 , & V_4 -> V_74 ) ) ;
F_43 ( V_73 , & V_4 -> V_74 ) ;
F_44 () ;
F_24 ( & V_33 -> V_44 ) ;
F_45 ( & V_4 -> V_45 , & V_33 -> V_46 ) ;
F_26 ( & V_33 -> V_44 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_32 * V_33 = & V_2 -> V_41 ;
struct V_57 * V_58 ;
struct V_48 * V_75 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
struct V_76 * V_6 ;
T_1 V_14 ;
T_2 * V_77 ;
V_58 = F_35 ( V_29 -> V_78 ) ;
#ifdef F_47
F_48 ( L_8 ,
V_31 , F_49 ( V_58 -> V_59 ) , V_29 -> V_79 ) ;
F_48 ( L_9 , V_31 , V_29 -> V_79 , V_58 ) ;
#endif
if ( V_29 -> V_79 < V_56 + 24 )
goto V_80;
V_77 = ( T_2 * ) ( ( unsigned char * ) V_58 + V_56 ) ;
V_14 = V_29 -> V_79 - V_56 ;
F_3 ( & V_33 -> V_44 ) ;
if ( F_50 ( & V_33 -> V_46 ) ) {
F_5 ( & V_33 -> V_44 ) ;
goto V_81;
}
V_4 = F_51 ( & V_33 -> V_46 ,
struct V_3 , V_45 ) ;
F_4 ( & V_4 -> V_45 ) ;
F_5 ( & V_33 -> V_44 ) ;
F_22 ( L_10 , V_31 , V_4 ) ;
V_4 -> V_82 = 0 ;
V_4 -> V_83 = 0 ;
V_4 -> V_60 = V_58 -> V_59 ;
V_4 -> V_84 . V_85 = V_14 ;
F_52 ( V_73 , & V_4 -> V_74 ) ;
V_6 = & V_4 -> V_86 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_87 [ 0 ] . V_88 = V_77 ;
V_6 -> V_87 [ 0 ] . V_89 = V_14 ;
V_6 -> V_85 = V_14 ;
V_9 = F_2 ( V_4 ) ;
F_22 ( L_11 ,
V_31 , V_29 , V_9 ) ;
V_9 -> V_90 = V_29 ;
V_9 -> V_91 = 0 ;
V_75 = V_33 -> V_75 ;
F_3 ( & V_75 -> V_92 ) ;
F_25 ( & V_4 -> V_43 , & V_75 -> V_93 ) ;
F_5 ( & V_75 -> V_92 ) ;
F_53 ( & V_75 -> V_94 ) ;
V_2 -> V_95 . V_96 ++ ;
return;
V_81:
F_54 ( L_12 ) ;
F_55 ( V_33 ) ;
return;
V_80:
F_54 ( L_13 ) ;
if ( F_56 ( & V_2 -> V_69 , V_29 ) )
F_55 ( V_33 ) ;
else
F_54 ( L_14 ,
V_31 , V_29 ) ;
}
