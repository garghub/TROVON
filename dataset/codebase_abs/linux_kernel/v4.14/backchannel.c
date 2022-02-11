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
F_13 ( & V_9 -> V_21 , V_13 -> V_22 , F_14 ( V_13 ) ) ;
V_14 = V_2 -> V_23 . V_24 ;
V_13 = F_12 ( V_14 , V_17 , V_18 ) ;
if ( F_10 ( V_13 ) )
goto V_19;
V_9 -> V_25 = V_13 ;
F_13 ( & V_4 -> V_26 , V_13 -> V_22 ,
F_15 ( T_1 , V_14 , V_27 ) ) ;
F_16 ( V_4 , V_9 ) ;
return 0 ;
V_19:
F_1 ( V_2 , V_4 ) ;
return - V_28 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_29 )
{
struct V_30 * V_31 ;
int V_32 = 0 ;
while ( V_29 -- ) {
V_31 = F_18 ( V_2 ) ;
if ( F_10 ( V_31 ) ) {
F_19 ( L_1 ,
V_33 ) ;
V_32 = F_11 ( V_31 ) ;
break;
}
F_20 ( V_31 ) ;
}
return V_32 ;
}
int F_21 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_1 * V_2 = F_22 ( V_35 ) ;
struct V_5 * V_37 = & V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned int V_38 ;
int V_32 ;
if ( V_36 > V_39 >> 1 )
goto V_40;
for ( V_38 = 0 ; V_38 < ( V_36 << 1 ) ; V_38 ++ ) {
V_4 = F_23 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
goto V_41;
F_24 ( L_2 , V_33 , V_4 ) ;
V_4 -> V_42 = & V_2 -> V_43 ;
F_25 ( & V_4 -> V_44 ) ;
F_25 ( & V_4 -> V_45 ) ;
if ( F_8 ( V_2 , V_4 ) )
goto V_41;
F_26 ( & V_35 -> V_46 ) ;
F_27 ( & V_4 -> V_47 , & V_35 -> V_48 ) ;
F_28 ( & V_35 -> V_46 ) ;
}
V_32 = F_17 ( V_2 , V_36 ) ;
if ( V_32 )
goto V_41;
V_32 = F_29 ( V_2 , V_36 ) ;
if ( V_32 )
goto V_41;
V_37 -> V_49 = V_36 ;
F_30 ( L_3 ) ;
return 0 ;
V_41:
F_31 ( V_35 , V_36 ) ;
V_40:
F_19 ( L_4 , V_33 ) ;
return - V_28 ;
}
int F_32 ( struct V_50 * V_51 , struct V_52 * V_52 )
{
int V_53 ;
V_53 = F_33 ( V_51 , L_5 , V_52 , V_54 , 0 , 0 ) ;
if ( V_53 < 0 )
return V_53 ;
return 0 ;
}
T_1 F_34 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_22 ( V_35 ) ;
struct V_55 * V_56 = & V_2 -> V_23 ;
T_1 V_57 ;
V_57 = F_15 (unsigned int, cdata->inline_rsize, cdata->inline_wsize) ;
V_57 = F_15 (unsigned int, maxmsg, PAGE_SIZE) ;
return V_57 - V_58 ;
}
int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_22 ( V_4 -> V_42 ) ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
T_2 * V_59 ;
F_36 ( & V_9 -> V_21 , 0 ) ;
F_37 ( & V_9 -> V_60 , & V_9 -> V_21 ,
V_9 -> V_20 -> V_22 ) ;
V_59 = F_38 ( & V_9 -> V_60 , 28 ) ;
if ( F_39 ( ! V_59 ) )
return - V_61 ;
* V_59 ++ = V_4 -> V_62 ;
* V_59 ++ = V_63 ;
* V_59 ++ = F_40 ( V_2 -> V_7 . V_49 ) ;
* V_59 ++ = V_64 ;
* V_59 ++ = V_65 ;
* V_59 ++ = V_65 ;
* V_59 = V_65 ;
if ( ! F_41 ( & V_2 -> V_66 , V_9 , V_58 ,
& V_4 -> V_26 , V_67 ) )
return - V_61 ;
return 0 ;
}
void F_31 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_1 * V_2 = F_22 ( V_35 ) ;
struct V_3 * V_4 , * V_68 ;
F_26 ( & V_35 -> V_46 ) ;
F_42 (rqst, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_4 ( & V_4 -> V_47 ) ;
F_28 ( & V_35 -> V_46 ) ;
F_1 ( V_2 , V_4 ) ;
F_26 ( & V_35 -> V_46 ) ;
}
F_28 ( & V_35 -> V_46 ) ;
}
void F_43 ( struct V_3 * V_4 )
{
struct V_34 * V_35 = V_4 -> V_42 ;
F_24 ( L_6 ,
V_33 , V_4 , F_2 ( V_4 ) ) ;
F_44 () ;
F_45 ( ! F_46 ( V_69 , & V_4 -> V_70 ) ) ;
F_47 ( V_69 , & V_4 -> V_70 ) ;
F_48 () ;
F_26 ( & V_35 -> V_46 ) ;
F_49 ( & V_4 -> V_47 , & V_35 -> V_48 ) ;
F_28 ( & V_35 -> V_46 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_34 * V_35 = & V_2 -> V_43 ;
struct V_50 * V_71 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
struct V_72 * V_6 ;
T_1 V_14 ;
T_2 * V_59 ;
V_59 = F_51 ( & V_31 -> V_73 , 0 ) ;
V_14 = F_52 ( & V_31 -> V_73 ) ;
#ifdef F_53
F_54 ( L_7 ,
V_33 , F_55 ( V_59 ) , V_14 ) ;
F_54 ( L_8 , V_33 , V_14 , V_59 ) ;
#endif
F_3 ( & V_35 -> V_46 ) ;
if ( F_56 ( & V_35 -> V_48 ) ) {
F_5 ( & V_35 -> V_46 ) ;
goto V_74;
}
V_4 = F_57 ( & V_35 -> V_48 ,
struct V_3 , V_47 ) ;
F_4 ( & V_4 -> V_47 ) ;
F_5 ( & V_35 -> V_46 ) ;
F_24 ( L_9 , V_33 , V_4 ) ;
V_4 -> V_75 = 0 ;
V_4 -> V_76 = 0 ;
V_4 -> V_62 = * V_59 ;
V_4 -> V_77 . V_78 = V_14 ;
F_58 ( V_69 , & V_4 -> V_70 ) ;
V_6 = & V_4 -> V_79 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_80 [ 0 ] . V_81 = V_59 ;
V_6 -> V_80 [ 0 ] . V_82 = V_14 ;
V_6 -> V_78 = V_14 ;
V_9 = F_2 ( V_4 ) ;
F_24 ( L_10 ,
V_33 , V_31 , V_9 ) ;
V_9 -> V_83 = V_31 ;
V_9 -> V_84 = 0 ;
V_71 = V_35 -> V_71 ;
F_3 ( & V_71 -> V_85 ) ;
F_27 ( & V_4 -> V_45 , & V_71 -> V_86 ) ;
F_5 ( & V_71 -> V_85 ) ;
F_59 ( & V_71 -> V_87 ) ;
V_2 -> V_88 . V_89 ++ ;
return;
V_74:
F_60 ( L_11 ) ;
F_61 ( V_35 ) ;
return;
}
