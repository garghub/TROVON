static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
int F_5 ( int V_6 , T_1 * V_7 )
{
struct V_1 * V_2 = & V_8 ;
if ( ! V_2 -> V_9 )
return - V_10 ;
* V_7 = F_1 ( V_2 , V_6 ) ;
return 0 ;
}
int F_6 ( int V_6 , T_1 V_7 )
{
struct V_1 * V_2 = & V_8 ;
if ( ! V_2 -> V_9 )
return - V_10 ;
F_3 ( V_2 , V_6 , V_7 ) ;
return 0 ;
}
static void F_7 ( void )
{
T_2 V_11 ;
T_1 V_12 ;
F_8 ( L_1 ) ;
V_11 = V_13 + V_14 ;
V_12 = F_9 ( V_11 ) ;
V_12 &= V_15 ;
V_12 |= V_16 ;
V_12 |= V_17 ;
F_10 ( V_12 , V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_18 , ( T_1 ) V_19 ) ;
}
static void F_12 ( struct V_20 * V_21 , int V_22 ,
T_1 V_23 , const struct V_24 * V_25 ,
T_1 V_26 , const struct V_24 * V_27 )
{
int V_6 = V_28 * V_22 ;
int V_29 ;
for ( V_29 = 0 ; V_25 [ V_29 ] . V_30 ; V_29 ++ ) {
F_13 ( V_21 , L_2 ,
V_6 + V_29 , V_25 [ V_29 ] . V_30 ,
V_27 [ V_29 ] . V_31 & V_26 ? L_3 : L_4 ,
V_25 [ V_29 ] . V_31 & V_23 ? L_5 : L_6 ) ;
}
}
static int F_14 ( struct V_20 * V_21 , void * V_32 )
{
struct V_1 * V_2 = V_21 -> V_33 ;
const struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_37 , V_38 ;
T_1 V_39 , V_40 ;
V_37 = F_1 ( V_2 , V_41 ) ;
V_38 = F_1 ( V_2 , V_42 ) ;
V_39 = F_1 ( V_2 , V_43 ) ;
V_40 = F_1 ( V_2 , V_44 ) ;
F_12 ( V_21 , 0 , V_39 , V_35 -> V_39 , V_37 , V_35 -> V_37 ) ;
F_12 ( V_21 , 1 , V_40 , V_35 -> V_40 , V_38 , V_35 -> V_38 ) ;
return 0 ;
}
static int F_15 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_16 ( V_46 , F_14 , V_45 -> V_47 ) ;
}
static int F_17 ( struct V_20 * V_21 , void * V_32 )
{
struct V_1 * V_2 = V_21 -> V_33 ;
const struct V_24 * V_36 = V_2 -> V_36 -> V_48 ;
T_1 V_48 = F_1 ( V_2 , V_49 ) ;
int V_29 ;
for ( V_29 = 0 ; V_36 [ V_29 ] . V_30 ; V_29 ++ ) {
F_13 ( V_21 , L_7 ,
V_29 , V_36 [ V_29 ] . V_30 ,
V_36 [ V_29 ] . V_31 & V_48 ? L_8 : L_9 ) ;
}
return 0 ;
}
static int F_18 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_16 ( V_46 , F_17 , V_45 -> V_47 ) ;
}
static int F_19 ( struct V_20 * V_21 , void * V_32 )
{
struct V_1 * V_2 = V_21 -> V_33 ;
T_3 V_50 , V_51 , V_52 , V_53 , V_54 ;
V_50 = ( T_3 ) F_1 ( V_2 , V_55 ) << V_56 ;
V_51 = ( T_3 ) F_1 ( V_2 , V_57 ) << V_56 ;
V_52 = ( T_3 ) F_1 ( V_2 , V_58 ) << V_56 ;
V_53 = ( T_3 ) F_1 ( V_2 , V_59 ) << V_56 ;
V_54 = ( T_3 ) F_1 ( V_2 , V_60 ) << V_56 ;
F_13 ( V_21 , L_10 , V_50 ) ;
F_13 ( V_21 , L_11 , V_51 ) ;
F_13 ( V_21 , L_12 , V_52 ) ;
F_13 ( V_21 , L_13 , V_53 ) ;
F_13 ( V_21 , L_14 , V_54 ) ;
return 0 ;
}
static int F_20 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_16 ( V_46 , F_19 , V_45 -> V_47 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_61 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_62 * V_63 , * V_64 ;
V_63 = F_24 ( L_15 , NULL ) ;
if ( ! V_63 )
return - V_65 ;
V_2 -> V_61 = V_63 ;
V_64 = F_25 ( L_16 , V_66 | V_67 ,
V_63 , V_2 , & V_68 ) ;
if ( ! V_64 )
goto V_69;
V_64 = F_25 ( L_17 , V_66 | V_67 ,
V_63 , V_2 , & V_70 ) ;
if ( ! V_64 )
goto V_69;
V_64 = F_25 ( L_18 , V_66 | V_67 ,
V_63 , V_2 , & V_71 ) ;
if ( ! V_64 )
goto V_69;
return 0 ;
V_69:
F_21 ( V_2 ) ;
return - V_10 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_26 ( struct V_72 * V_73 , void T_4 * V_74 ,
const struct V_75 * V_75 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
V_79 = F_27 ( sizeof( * V_79 ) , V_80 ) ;
if ( ! V_79 )
return - V_65 ;
V_79 -> V_81 = V_74 ;
V_79 -> V_82 = V_75 -> V_82 ;
V_77 = F_28 ( & V_73 -> V_83 , L_19 ,
V_84 ,
V_79 , sizeof( * V_79 ) ) ;
if ( F_29 ( V_77 ) ) {
F_30 ( V_79 ) ;
return F_31 ( V_77 ) ;
}
F_30 ( V_79 ) ;
return 0 ;
}
static int F_32 ( struct V_72 * V_73 , const struct V_85 * V_86 )
{
struct V_1 * V_2 = & V_8 ;
const struct V_75 * V_87 = (struct V_75 * ) V_86 -> V_88 ;
const struct V_34 * V_36 = V_87 -> V_36 ;
int V_89 ;
F_33 ( V_73 , V_90 , & V_13 ) ;
V_13 &= V_91 ;
if ( V_13 != 0 && V_92 == NULL )
V_92 = F_7 ;
F_33 ( V_73 , V_93 , & V_2 -> V_94 ) ;
V_2 -> V_94 &= V_95 ;
V_2 -> V_4 = F_34 ( V_2 -> V_94 , V_96 ) ;
if ( ! V_2 -> V_4 ) {
F_35 ( & V_73 -> V_83 , L_20 ) ;
return - V_65 ;
}
V_2 -> V_36 = V_36 ;
F_11 ( V_2 ) ;
V_89 = F_23 ( V_2 ) ;
if ( V_89 )
F_36 ( & V_73 -> V_83 , L_21 ) ;
V_89 = F_26 ( V_73 , V_2 -> V_4 , V_87 ) ;
if ( V_89 )
F_36 ( & V_73 -> V_83 , L_22 ,
V_89 ) ;
V_2 -> V_9 = true ;
return V_89 ;
}
static int T_5 F_37 ( void )
{
struct V_72 * V_73 = NULL ;
const struct V_85 * V_86 ;
F_38 (pdev) {
V_86 = F_39 ( V_97 , V_73 ) ;
if ( V_86 )
return F_32 ( V_73 , V_86 ) ;
}
return - V_10 ;
}
