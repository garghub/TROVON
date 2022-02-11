static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_4 ;
int V_8 ;
V_8 = V_6 -> V_9 . V_10 >> V_11 ;
F_3 ( V_4 -> V_12 , V_6 -> V_13 . V_14 * V_8 ) ;
}
static int F_4 ( struct V_15 * V_13 ,
struct V_5 * V_6 )
{
struct V_16 * V_17 = F_5 ( V_6 ) ;
struct V_3 * V_4 = F_6 ( V_17 ) ;
if ( ! V_17 )
goto V_18;
if ( ! V_4 -> V_19 )
goto V_18;
if ( F_7 () ) {
F_1 ( & V_4 -> V_2 ) ;
} else {
struct V_20 * V_21 = V_17 -> V_22 -> V_23 ;
F_8 ( V_21 -> V_24 , & V_4 -> V_2 ) ;
}
return 0 ;
V_18:
return F_9 ( V_13 , V_6 ) ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 = F_6 ( V_17 ) ;
struct V_27 * V_22 = V_17 -> V_22 ;
struct V_20 * V_21 = V_22 -> V_23 ;
struct V_28 * V_29 = NULL ;
union V_30 V_31 ;
struct V_5 * V_6 = NULL ;
struct V_32 V_33 = { 0 } ;
T_1 V_34 ;
int V_35 ;
V_26 -> V_36 = 32 ;
V_26 -> V_37 = 24 ;
F_11 ( L_1 , V_26 -> V_38 ,
V_26 -> V_39 , V_26 -> V_36 ,
V_26 -> V_40 , V_26 -> V_41 ) ;
V_33 . V_42 = F_12 ( V_26 -> V_36 ,
V_26 -> V_37 ) ;
V_33 . V_43 = V_26 -> V_38 ;
V_33 . V_44 = V_26 -> V_39 ;
V_33 . V_45 [ 0 ] =
F_13 ( V_33 . V_43 * V_26 -> V_36 , 8 ) ;
V_4 -> V_19 = V_21 -> V_46 && V_19 ;
if ( V_4 -> V_19 ) {
V_33 . V_45 [ 0 ] = F_14 ( V_33 . V_45 [ 0 ] ) ;
}
V_31 = (union V_30 ) {
. V_47 = F_14 ( V_33 . V_45 [ 0 ] * V_33 . V_44 ) ,
} ;
F_11 ( L_2 , V_31 . V_47 , V_22 -> V_48 -> V_49 ) ;
V_4 -> V_12 = F_15 ( V_22 , V_31 , V_50 | V_51 ) ;
if ( ! V_4 -> V_12 ) {
F_16 ( V_22 -> V_22 , L_3 ) ;
V_35 = - V_52 ;
goto V_53;
}
V_29 = F_17 ( V_22 , & V_33 , & V_4 -> V_12 ) ;
if ( F_18 ( V_29 ) ) {
F_16 ( V_22 -> V_22 , L_4 ) ;
F_19 ( V_4 -> V_12 ) ;
V_35 = F_20 ( V_29 ) ;
goto V_53;
}
V_35 = F_21 ( V_4 -> V_12 , & V_34 ) ;
if ( V_35 ) {
F_16 ( V_22 -> V_22 , L_5 ) ;
V_35 = - V_52 ;
goto V_53;
}
F_22 ( & V_22 -> V_54 ) ;
V_6 = F_23 ( V_17 ) ;
if ( F_18 ( V_6 ) ) {
F_16 ( V_22 -> V_22 , L_6 ) ;
V_35 = F_20 ( V_6 ) ;
goto V_55;
}
F_11 ( L_7 , V_6 , V_22 ) ;
V_4 -> V_29 = V_29 ;
V_17 -> V_29 = V_29 ;
V_6 -> V_56 = V_17 ;
V_6 -> V_57 = V_58 ;
V_6 -> V_59 = & V_60 ;
strcpy ( V_6 -> V_9 . V_61 , V_62 ) ;
F_24 ( V_6 , V_29 -> V_45 [ 0 ] , V_29 -> V_63 -> V_64 ) ;
F_25 ( V_6 , V_17 , V_26 -> V_40 , V_26 -> V_41 ) ;
V_22 -> V_65 . V_66 = V_34 ;
V_6 -> V_67 = F_26 ( V_4 -> V_12 ) ;
V_6 -> V_68 = V_4 -> V_12 -> V_69 ;
V_6 -> V_9 . V_70 = V_34 ;
V_6 -> V_9 . V_71 = V_4 -> V_12 -> V_69 ;
if ( V_4 -> V_19 ) {
F_27 ( L_8 ) ;
V_6 -> V_57 |= V_72 | V_73 ;
V_6 -> V_9 . V_74 = 1 ;
}
F_11 ( L_9 , V_6 -> V_56 , V_6 -> V_13 . V_75 , V_6 -> V_13 . V_76 ) ;
F_11 ( L_10 , V_4 -> V_29 -> V_43 , V_4 -> V_29 -> V_44 ) ;
F_28 ( & V_22 -> V_54 ) ;
return 0 ;
V_55:
F_28 ( & V_22 -> V_54 ) ;
V_53:
if ( V_35 ) {
if ( V_29 )
F_29 ( V_29 ) ;
}
return V_35 ;
}
static struct V_16 * F_5 ( struct V_5 * V_6 )
{
if ( ! V_6 || strcmp ( V_6 -> V_9 . V_61 , V_62 ) ) {
return NULL ;
}
return V_6 -> V_56 ;
}
struct V_16 * F_30 ( struct V_27 * V_22 )
{
struct V_20 * V_21 = V_22 -> V_23 ;
struct V_3 * V_4 = NULL ;
struct V_16 * V_17 ;
int V_35 = 0 ;
V_4 = F_31 ( sizeof( * V_4 ) , V_77 ) ;
if ( ! V_4 )
goto V_53;
F_32 ( & V_4 -> V_2 , F_1 ) ;
V_17 = & V_4 -> V_7 ;
F_33 ( V_22 , V_17 , & V_78 ) ;
V_35 = F_34 ( V_22 , V_17 , V_21 -> V_79 ) ;
if ( V_35 ) {
F_16 ( V_22 -> V_22 , L_11 , V_35 ) ;
goto V_53;
}
V_35 = F_35 ( V_17 ) ;
if ( V_35 )
goto V_80;
V_35 = F_36 ( V_17 , 32 ) ;
if ( V_35 )
goto V_80;
V_21 -> V_4 = V_17 ;
return V_17 ;
V_80:
F_37 ( V_17 ) ;
V_53:
F_38 ( V_4 ) ;
F_39 ( V_22 -> V_22 , L_12 ) ;
return NULL ;
}
void F_40 ( struct V_27 * V_22 )
{
struct V_20 * V_21 = V_22 -> V_23 ;
struct V_16 * V_17 = V_21 -> V_4 ;
struct V_3 * V_4 ;
F_11 () ;
F_41 ( V_17 ) ;
F_37 ( V_17 ) ;
V_4 = F_6 ( V_21 -> V_4 ) ;
F_42 ( V_4 -> V_12 ) ;
if ( V_4 -> V_29 )
F_29 ( V_4 -> V_29 ) ;
F_38 ( V_4 ) ;
V_21 -> V_4 = NULL ;
}
