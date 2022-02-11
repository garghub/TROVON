int
F_1 ( const struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 , V_3 ) ;
return V_5 ? F_3 ( V_5 ) : 0 ;
}
static int
F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_13 * V_14 = NULL ;
struct V_9 * V_15 ;
int V_16 = - V_17 ;
if ( F_6 ( V_8 , V_18 , V_19 ) ||
F_6 ( V_8 , V_20 ,
V_12 -> V_21 -> V_22 ) ||
F_7 ( V_8 , V_23 , V_10 -> V_24 ) ||
F_6 ( V_8 , V_25 , V_10 -> V_22 ) ||
F_8 ( V_8 , V_26 , V_27 ,
V_10 -> V_28 ) ||
F_9 ( V_8 , V_29 ,
( V_30 ) F_10 ( & V_12 -> V_31 . V_32 ) ) )
goto V_33;
#ifdef F_11
if ( F_12 ( V_8 , V_34 ,
F_13 ( V_12 -> V_35 . V_36 . V_37 ) ) )
goto V_33;
#endif
V_14 = F_14 ( V_12 ) ;
if ( V_14 && V_14 -> V_38 == V_39 ) {
V_15 = V_14 -> V_40 ;
if ( F_7 ( V_8 , V_41 ,
V_15 -> V_24 ) ||
F_6 ( V_8 , V_42 ,
V_15 -> V_22 ) ||
F_8 ( V_8 , V_43 , V_27 ,
V_15 -> V_28 ) )
goto V_33;
}
V_16 = 0 ;
V_33:
if ( V_14 )
F_15 ( V_14 ) ;
return V_16 ;
}
static int
F_16 ( struct V_7 * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_47 = F_17 ( V_46 ) ;
struct V_9 * V_10 ;
struct V_7 * V_8 = NULL ;
void * V_48 ;
int V_24 ;
int V_16 ;
if ( ! V_46 -> V_49 [ V_23 ] )
return - V_50 ;
V_24 = F_3 ( V_46 -> V_49 [ V_23 ] ) ;
if ( ! V_24 )
return - V_50 ;
V_10 = F_18 ( V_47 , V_24 ) ;
if ( ! V_10 || ! F_19 ( V_10 ) ) {
V_16 = - V_51 ;
goto V_33;
}
V_8 = F_20 ( V_52 , V_53 ) ;
if ( ! V_8 ) {
V_16 = - V_54 ;
goto V_33;
}
V_48 = F_21 ( V_8 , V_46 -> V_55 , V_46 -> V_56 ,
& V_57 , 0 ,
V_58 ) ;
if ( ! V_48 ) {
V_16 = - V_17 ;
goto V_33;
}
V_16 = F_4 ( V_8 , V_10 ) ;
V_33:
if ( V_10 )
F_22 ( V_10 ) ;
if ( V_16 ) {
if ( V_8 )
F_23 ( V_8 ) ;
return V_16 ;
}
F_24 ( V_8 , V_48 ) ;
return F_25 ( V_8 , V_46 ) ;
}
static int
F_26 ( struct V_7 * V_8 , T_1 V_59 )
{
if ( F_7 ( V_8 , V_60 , V_59 ) )
return - V_17 ;
return 0 ;
}
int F_27 ( struct V_11 * V_12 , const V_30 * V_61 ,
V_30 V_62 , T_1 V_63 , T_2 V_64 ,
T_1 V_59 )
{
struct V_7 * V_8 ;
void * V_65 ;
int V_16 ;
V_8 = F_20 ( V_52 , V_53 ) ;
if ( ! V_8 )
return - V_54 ;
V_65 = F_21 ( V_8 , 0 , 0 , & V_57 , 0 ,
V_66 ) ;
if ( ! V_65 ) {
V_16 = - V_17 ;
goto V_67;
}
if ( F_7 ( V_8 , V_60 , V_59 ) )
goto V_68;
if ( F_7 ( V_8 , V_69 , V_63 ) )
goto V_68;
if ( F_28 ( V_8 , V_70 , V_64 ,
V_71 ) )
goto V_68;
if ( F_9 ( V_8 , V_72 , V_62 ) )
goto V_68;
if ( F_8 ( V_8 , V_73 , V_27 , V_61 ) )
goto V_68;
F_24 ( V_8 , V_65 ) ;
F_29 ( & V_57 ,
F_30 ( V_12 -> V_10 ) , V_8 , 0 ,
V_74 , V_53 ) ;
return 0 ;
V_68:
F_31 ( V_8 , V_65 ) ;
V_16 = - V_75 ;
V_67:
F_23 ( V_8 ) ;
return V_16 ;
}
static int
F_32 ( struct V_7 * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_47 = F_17 ( V_46 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_7 * V_8 = NULL ;
T_1 V_76 ;
void * V_48 ;
int V_24 ;
T_1 V_59 ;
V_30 * V_61 ;
int V_16 ;
if ( ! V_46 -> V_49 [ V_23 ] )
return - V_50 ;
if ( ! V_46 -> V_49 [ V_73 ] )
return - V_50 ;
if ( ! V_46 -> V_49 [ V_69 ] )
return - V_50 ;
V_24 = F_3 ( V_46 -> V_49 [ V_23 ] ) ;
if ( ! V_24 )
return - V_50 ;
V_61 = F_33 ( V_46 -> V_49 [ V_73 ] ) ;
V_76 = F_3 ( V_46 -> V_49 [ V_69 ] ) ;
V_10 = F_18 ( V_47 , V_24 ) ;
if ( ! V_10 || ! F_19 ( V_10 ) ) {
V_16 = - V_51 ;
goto V_33;
}
V_8 = F_20 ( V_52 , V_53 ) ;
if ( ! V_8 ) {
V_16 = - V_54 ;
goto V_33;
}
V_48 = F_21 ( V_8 , V_46 -> V_55 , V_46 -> V_56 ,
& V_57 , 0 ,
V_66 ) ;
if ( ! V_48 ) {
V_16 = - V_17 ;
goto V_33;
}
V_12 = F_5 ( V_10 ) ;
F_34 ( V_12 , V_61 , V_76 , & V_59 ) ;
V_16 = F_26 ( V_8 , V_59 ) ;
V_33:
if ( V_10 )
F_22 ( V_10 ) ;
if ( V_16 ) {
if ( V_8 )
F_23 ( V_8 ) ;
return V_16 ;
}
F_24 ( V_8 , V_48 ) ;
return F_25 ( V_8 , V_46 ) ;
}
static int
F_35 ( struct V_7 * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_47 = F_17 ( V_46 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_24 ;
V_30 * V_61 ;
int V_16 = 0 ;
if ( ! V_46 -> V_49 [ V_23 ] )
return - V_50 ;
if ( ! V_46 -> V_49 [ V_73 ] )
return - V_50 ;
V_24 = F_3 ( V_46 -> V_49 [ V_23 ] ) ;
if ( ! V_24 )
return - V_50 ;
V_61 = F_33 ( V_46 -> V_49 [ V_73 ] ) ;
V_10 = F_18 ( V_47 , V_24 ) ;
if ( ! V_10 || ! F_19 ( V_10 ) ) {
V_16 = - V_51 ;
goto V_33;
}
V_12 = F_5 ( V_10 ) ;
F_36 ( V_12 , V_61 , V_77 ) ;
V_33:
if ( V_10 )
F_22 ( V_10 ) ;
return V_16 ;
}
static int
F_37 ( struct V_7 * V_8 , T_1 V_78 , T_1 V_79 ,
struct V_13 * V_15 )
{
struct V_9 * V_40 = V_15 -> V_40 ;
void * V_65 ;
V_65 = F_21 ( V_8 , V_78 , V_79 , & V_57 , V_80 ,
V_81 ) ;
if ( ! V_65 )
return - V_75 ;
if ( F_7 ( V_8 , V_41 ,
V_40 -> V_24 ) ||
F_6 ( V_8 , V_42 ,
V_40 -> V_22 ) ||
F_8 ( V_8 , V_43 , V_27 ,
V_40 -> V_28 ) )
goto V_68;
if ( V_15 -> V_38 == V_39 ) {
if ( F_38 ( V_8 , V_82 ) )
goto V_68;
}
F_24 ( V_8 , V_65 ) ;
return 0 ;
V_68:
F_31 ( V_8 , V_65 ) ;
return - V_75 ;
}
static int
F_39 ( struct V_7 * V_8 , struct V_83 * V_84 )
{
struct V_47 * V_47 = F_40 ( V_84 -> V_44 -> V_85 ) ;
struct V_9 * V_10 ;
struct V_13 * V_15 ;
int V_24 ;
int V_78 = F_41 ( V_84 -> V_44 ) . V_78 ;
int V_79 = V_84 -> V_2 -> V_86 ;
int V_87 = V_84 -> args [ 0 ] ;
int V_88 = 0 ;
V_24 = F_1 ( V_84 -> V_2 ,
V_23 ) ;
if ( ! V_24 )
return - V_50 ;
V_10 = F_18 ( V_47 , V_24 ) ;
if ( ! V_10 )
return - V_51 ;
if ( ! F_19 ( V_10 ) ) {
F_22 ( V_10 ) ;
return - V_51 ;
}
F_42 () ;
F_43 (hard_iface, &batadv_hardif_list, list) {
if ( V_15 -> V_10 != V_10 )
continue;
if ( V_88 ++ < V_87 )
continue;
if ( F_37 ( V_8 , V_78 , V_79 ,
V_15 ) ) {
V_88 -- ;
break;
}
}
F_44 () ;
F_22 ( V_10 ) ;
V_84 -> args [ 0 ] = V_88 ;
return V_8 -> V_89 ;
}
void T_3 F_45 ( void )
{
int V_16 ;
V_16 = F_46 ( & V_57 ) ;
if ( V_16 )
F_47 ( L_1 ) ;
}
void F_48 ( void )
{
F_49 ( & V_57 ) ;
}
