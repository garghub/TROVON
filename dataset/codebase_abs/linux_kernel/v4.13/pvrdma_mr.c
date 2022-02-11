struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 ;
union V_10 V_11 ;
union V_12 V_13 ;
struct V_14 * V_15 = & V_11 . V_16 ;
struct V_17 * V_18 = & V_13 . V_19 ;
int V_20 ;
if ( V_4 & ~ V_21 ) {
F_3 ( & V_6 -> V_22 -> V_6 ,
L_1 , V_4 ) ;
return F_4 ( - V_23 ) ;
}
V_9 = F_5 ( sizeof( * V_9 ) , V_24 ) ;
if ( ! V_9 )
return F_4 ( - V_25 ) ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_26 . V_15 = V_27 ;
V_15 -> V_28 = F_6 ( V_3 ) -> V_28 ;
V_15 -> V_29 = V_4 ;
V_15 -> V_30 = V_31 ;
V_20 = F_7 ( V_6 , & V_11 , & V_13 , V_32 ) ;
if ( V_20 < 0 ) {
F_3 ( & V_6 -> V_22 -> V_6 ,
L_2 , V_20 ) ;
F_8 ( V_9 ) ;
return F_4 ( V_20 ) ;
}
V_9 -> V_33 . V_34 = V_18 -> V_34 ;
V_9 -> V_35 . V_36 = V_18 -> V_36 ;
V_9 -> V_35 . V_37 = V_18 -> V_37 ;
return & V_9 -> V_35 ;
}
struct V_1 * F_9 ( struct V_2 * V_3 , T_1 V_38 , T_1 V_39 ,
T_1 V_40 , int V_29 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 = NULL ;
struct V_43 * V_44 ;
union V_10 V_11 ;
union V_12 V_13 ;
struct V_14 * V_15 = & V_11 . V_16 ;
struct V_17 * V_18 = & V_13 . V_19 ;
int V_45 ;
int V_20 ;
int V_46 ;
struct V_47 * V_48 ;
if ( V_39 == 0 || V_39 > V_6 -> V_49 -> V_50 . V_51 ) {
F_3 ( & V_6 -> V_22 -> V_6 , L_3 ) ;
return F_4 ( - V_52 ) ;
}
V_44 = F_10 ( V_3 -> V_53 -> V_54 , V_38 ,
V_39 , V_29 , 0 ) ;
if ( F_11 ( V_44 ) ) {
F_3 ( & V_6 -> V_22 -> V_6 ,
L_4 ) ;
return F_12 ( V_44 ) ;
}
V_45 = 0 ;
F_13 (umem->sg_head.sgl, sg, umem->nmap, entry)
V_45 += F_14 ( V_48 ) >> V_55 ;
if ( V_45 < 0 || V_45 > V_56 ) {
F_3 ( & V_6 -> V_22 -> V_6 , L_5 ,
V_45 ) ;
V_20 = - V_52 ;
goto V_57;
}
V_9 = F_5 ( sizeof( * V_9 ) , V_24 ) ;
if ( ! V_9 ) {
V_20 = - V_25 ;
goto V_57;
}
V_9 -> V_33 . V_58 = V_40 ;
V_9 -> V_33 . V_59 = V_39 ;
V_9 -> V_44 = V_44 ;
V_20 = F_15 ( V_6 , & V_9 -> V_60 , V_45 , false ) ;
if ( V_20 ) {
F_3 ( & V_6 -> V_22 -> V_6 ,
L_6 ) ;
goto V_57;
}
V_20 = F_16 ( & V_9 -> V_60 , V_9 -> V_44 , 0 ) ;
if ( V_20 )
goto V_61;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_26 . V_15 = V_27 ;
V_15 -> V_38 = V_38 ;
V_15 -> V_39 = V_39 ;
V_15 -> V_28 = F_6 ( V_3 ) -> V_28 ;
V_15 -> V_29 = V_29 ;
V_15 -> V_45 = V_45 ;
V_15 -> V_62 = V_9 -> V_60 . V_63 ;
V_20 = F_7 ( V_6 , & V_11 , & V_13 , V_32 ) ;
if ( V_20 < 0 ) {
F_3 ( & V_6 -> V_22 -> V_6 ,
L_7 , V_20 ) ;
goto V_61;
}
V_9 -> V_33 . V_34 = V_18 -> V_34 ;
V_9 -> V_35 . V_36 = V_18 -> V_36 ;
V_9 -> V_35 . V_37 = V_18 -> V_37 ;
return & V_9 -> V_35 ;
V_61:
F_17 ( V_6 , & V_9 -> V_60 ) ;
V_57:
F_18 ( V_44 ) ;
F_8 ( V_9 ) ;
return F_4 ( V_20 ) ;
}
struct V_1 * F_19 ( struct V_2 * V_3 , enum V_64 V_65 ,
T_2 V_66 )
{
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 ;
union V_10 V_11 ;
union V_12 V_13 ;
struct V_14 * V_15 = & V_11 . V_16 ;
struct V_17 * V_18 = & V_13 . V_19 ;
int V_59 = V_66 * sizeof( T_1 ) ;
int V_20 ;
if ( V_65 != V_67 ||
V_66 > V_68 )
return F_4 ( - V_52 ) ;
V_9 = F_5 ( sizeof( * V_9 ) , V_24 ) ;
if ( ! V_9 )
return F_4 ( - V_25 ) ;
V_9 -> V_69 = F_5 ( V_59 , V_24 ) ;
if ( ! V_9 -> V_69 ) {
V_20 = - V_25 ;
goto V_70;
}
V_20 = F_15 ( V_6 , & V_9 -> V_60 , V_66 , false ) ;
if ( V_20 ) {
F_3 ( & V_6 -> V_22 -> V_6 ,
L_8 ) ;
V_20 = - V_25 ;
goto V_71;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_26 . V_15 = V_27 ;
V_15 -> V_28 = F_6 ( V_3 ) -> V_28 ;
V_15 -> V_29 = 0 ;
V_15 -> V_30 = V_72 ;
V_15 -> V_45 = V_66 ;
V_20 = F_7 ( V_6 , & V_11 , & V_13 , V_32 ) ;
if ( V_20 < 0 ) {
F_3 ( & V_6 -> V_22 -> V_6 ,
L_9 , V_20 ) ;
goto V_73;
}
V_9 -> V_74 = V_66 ;
V_9 -> V_33 . V_34 = V_18 -> V_34 ;
V_9 -> V_35 . V_36 = V_18 -> V_36 ;
V_9 -> V_35 . V_37 = V_18 -> V_37 ;
V_9 -> V_75 = V_55 ;
V_9 -> V_44 = NULL ;
return & V_9 -> V_35 ;
V_73:
F_17 ( V_6 , & V_9 -> V_60 ) ;
V_71:
F_8 ( V_9 -> V_69 ) ;
V_70:
F_8 ( V_9 ) ;
return F_4 ( V_20 ) ;
}
int F_20 ( struct V_1 * V_35 )
{
struct V_8 * V_9 = F_21 ( V_35 ) ;
struct V_5 * V_6 = F_2 ( V_35 -> V_7 ) ;
union V_10 V_11 ;
struct V_76 * V_15 = & V_11 . V_77 ;
int V_20 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_26 . V_15 = V_78 ;
V_15 -> V_34 = V_9 -> V_33 . V_34 ;
V_20 = F_7 ( V_6 , & V_11 , NULL , 0 ) ;
if ( V_20 < 0 )
F_3 ( & V_6 -> V_22 -> V_6 ,
L_10 , V_20 ) ;
F_17 ( V_6 , & V_9 -> V_60 ) ;
if ( V_9 -> V_44 )
F_18 ( V_9 -> V_44 ) ;
F_8 ( V_9 -> V_69 ) ;
F_8 ( V_9 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_35 , T_1 V_79 )
{
struct V_8 * V_9 = F_21 ( V_35 ) ;
if ( V_9 -> V_80 == V_9 -> V_74 )
return - V_25 ;
V_9 -> V_69 [ V_9 -> V_80 ++ ] = V_79 ;
return 0 ;
}
int F_23 ( struct V_1 * V_35 , struct V_47 * V_48 , int V_81 ,
unsigned int * V_82 )
{
struct V_8 * V_9 = F_21 ( V_35 ) ;
struct V_5 * V_6 = F_2 ( V_35 -> V_7 ) ;
int V_20 ;
V_9 -> V_80 = 0 ;
V_20 = F_24 ( V_35 , V_48 , V_81 , V_82 , F_22 ) ;
if ( V_20 < 0 )
F_3 ( & V_6 -> V_22 -> V_6 , L_11 ) ;
return V_20 ;
}
