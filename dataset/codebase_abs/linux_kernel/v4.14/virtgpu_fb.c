static int F_1 ( struct V_1 * V_2 ,
bool V_3 , int V_4 , int V_5 ,
int V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 . V_9 ;
struct V_11 * V_12 = V_9 -> V_13 ;
bool V_14 = false ;
int V_15 = V_2 -> V_10 . V_16 -> V_17 [ 0 ] ;
int V_18 , V_19 ;
unsigned long V_20 ;
struct V_21 * V_22 = F_2 ( V_2 -> V_22 ) ;
if ( ( V_6 <= 0 ) ||
( V_4 + V_6 > V_2 -> V_10 . V_6 ) ||
( V_5 + V_7 > V_2 -> V_10 . V_7 ) ) {
F_3 ( L_1 ,
V_6 , V_7 , V_4 , V_5 ,
V_2 -> V_10 . V_6 , V_2 -> V_10 . V_7 ) ;
return - V_23 ;
}
if ( F_4 () || V_3 )
V_14 = true ;
V_18 = V_4 + V_6 - 1 ;
V_19 = V_5 + V_7 - 1 ;
F_5 ( & V_2 -> V_24 , V_20 ) ;
if ( V_2 -> y1 < V_5 )
V_5 = V_2 -> y1 ;
if ( V_2 -> V_19 > V_19 )
V_19 = V_2 -> V_19 ;
if ( V_2 -> V_25 < V_4 )
V_4 = V_2 -> V_25 ;
if ( V_2 -> V_18 > V_18 )
V_18 = V_2 -> V_18 ;
if ( V_14 ) {
V_2 -> V_25 = V_4 ;
V_2 -> V_18 = V_18 ;
V_2 -> y1 = V_5 ;
V_2 -> V_19 = V_19 ;
F_6 ( & V_2 -> V_24 , V_20 ) ;
return 0 ;
}
V_2 -> V_25 = V_2 -> y1 = V_26 ;
V_2 -> V_18 = V_2 -> V_19 = 0 ;
F_6 ( & V_2 -> V_24 , V_20 ) ;
{
T_1 V_27 ;
T_1 V_28 = V_18 - V_4 + 1 ;
T_1 V_29 = V_19 - V_5 + 1 ;
V_27 = ( V_5 * V_2 -> V_10 . V_30 [ 0 ] ) + V_4 * V_15 ;
F_7 ( V_12 , V_22 -> V_31 ,
V_27 ,
F_8 ( V_28 ) ,
F_8 ( V_29 ) ,
F_8 ( V_4 ) ,
F_8 ( V_5 ) ,
NULL ) ;
}
F_9 ( V_12 , V_22 -> V_31 ,
V_4 , V_5 , V_18 - V_4 + 1 , V_19 - V_5 + 1 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_32 ,
struct V_33 * V_34 ,
unsigned V_35 )
{
struct V_11 * V_12 = V_32 -> V_10 . V_9 -> V_13 ;
struct V_21 * V_22 = F_2 ( V_32 -> V_22 ) ;
struct V_33 V_36 ;
struct V_33 * V_37 ;
int V_38 , V_39 , V_40 , V_41 ;
int V_42 ;
int V_43 = 1 ;
if ( ! V_35 ) {
V_35 = 1 ;
V_34 = & V_36 ;
V_36 . V_25 = V_36 . y1 = 0 ;
V_36 . V_18 = V_32 -> V_10 . V_6 ;
V_36 . V_19 = V_32 -> V_10 . V_7 ;
}
V_38 = V_34 -> V_25 ;
V_39 = V_34 -> V_18 ;
V_40 = V_34 -> y1 ;
V_41 = V_34 -> V_19 ;
for ( V_42 = 1 , V_37 = V_34 + V_43 ;
V_42 < V_35 ; V_42 ++ , V_37 += V_43 ) {
V_38 = F_11 ( int , V_38 , ( int ) V_37 -> V_25 ) ;
V_39 = F_12 ( int , V_39 , ( int ) V_37 -> V_18 ) ;
V_40 = F_11 ( int , V_40 , ( int ) V_37 -> y1 ) ;
V_41 = F_12 ( int , V_41 , ( int ) V_37 -> V_19 ) ;
}
if ( V_22 -> V_44 )
return F_1 ( V_32 , false , V_38 , V_40 ,
V_39 - V_38 , V_41 - V_40 ) ;
F_9 ( V_12 , V_22 -> V_31 ,
V_38 , V_40 , V_39 - V_38 , V_41 - V_40 ) ;
return 0 ;
}
static void F_13 ( struct V_45 * V_46 )
{
struct V_47 * V_47 = F_14 ( V_46 ) ;
struct V_48 * V_49 =
F_15 ( V_47 , struct V_48 , V_46 ) ;
struct V_1 * V_32 = & V_49 -> V_32 ;
F_1 ( & V_49 -> V_32 , false , V_32 -> V_25 , V_32 -> y1 ,
V_32 -> V_18 - V_32 -> V_25 , V_32 -> V_19 - V_32 -> y1 ) ;
}
static void F_16 ( struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_48 * V_49 = V_51 -> V_54 ;
F_17 ( V_51 , V_53 ) ;
F_1 ( & V_49 -> V_32 , true , V_53 -> V_55 , V_53 -> V_56 ,
V_53 -> V_6 , V_53 -> V_7 ) ;
F_18 ( & V_49 -> V_46 , V_57 ) ;
}
static void F_19 ( struct V_50 * V_51 ,
const struct V_58 * V_59 )
{
struct V_48 * V_49 = V_51 -> V_54 ;
F_20 ( V_51 , V_59 ) ;
F_1 ( & V_49 -> V_32 , true , V_59 -> V_55 , V_59 -> V_56 ,
V_59 -> V_6 , V_59 -> V_7 ) ;
F_18 ( & V_49 -> V_46 , V_57 ) ;
}
static void F_21 ( struct V_50 * V_51 ,
const struct V_60 * V_61 )
{
struct V_48 * V_49 = V_51 -> V_54 ;
F_22 ( V_51 , V_61 ) ;
F_1 ( & V_49 -> V_32 , true , V_61 -> V_55 , V_61 -> V_56 ,
V_61 -> V_6 , V_61 -> V_7 ) ;
F_18 ( & V_49 -> V_46 , V_57 ) ;
}
static int F_23 ( struct V_11 * V_12 ,
struct V_21 * V_22 )
{
return F_24 ( V_22 , NULL ) ;
}
static int F_25 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_48 * V_49 =
F_15 ( V_63 , struct V_48 , V_63 ) ;
struct V_8 * V_9 = V_63 -> V_9 ;
struct V_11 * V_12 = V_9 -> V_13 ;
struct V_50 * V_51 ;
struct V_66 * V_2 ;
struct V_67 V_68 = {} ;
struct V_21 * V_22 ;
T_1 V_69 , V_16 , V_70 ;
int V_71 ;
V_68 . V_6 = V_65 -> V_72 ;
V_68 . V_7 = V_65 -> V_73 ;
V_68 . V_30 [ 0 ] = V_68 . V_6 * 4 ;
V_68 . V_74 = F_26 ( 32 , 24 ) ;
V_16 = F_27 ( V_68 . V_74 ) ;
if ( V_16 == 0 )
return - V_23 ;
V_70 = V_68 . V_30 [ 0 ] * V_68 . V_7 ;
V_22 = F_28 ( V_9 , V_70 , false , true ) ;
if ( F_29 ( V_22 ) )
return F_30 ( V_22 ) ;
F_31 ( V_12 , & V_69 ) ;
F_32 ( V_12 , V_69 , V_16 ,
V_68 . V_6 , V_68 . V_7 ) ;
V_71 = F_23 ( V_12 , V_22 ) ;
if ( V_71 ) {
F_33 ( L_2 , V_71 ) ;
goto V_75;
}
V_71 = F_34 ( V_12 , V_22 , V_69 , NULL ) ;
if ( V_71 )
goto V_76;
V_51 = F_35 ( V_63 ) ;
if ( F_29 ( V_51 ) ) {
V_71 = F_30 ( V_51 ) ;
goto V_77;
}
V_51 -> V_54 = V_63 ;
V_71 = F_36 ( V_9 , & V_49 -> V_32 ,
& V_68 , & V_22 -> V_78 ) ;
if ( V_71 )
goto V_77;
V_2 = & V_49 -> V_32 . V_10 ;
V_49 -> V_63 . V_2 = V_2 ;
strcpy ( V_51 -> V_79 . V_80 , L_3 ) ;
V_51 -> V_81 = & V_82 ;
V_51 -> V_83 . V_20 = V_84 ;
V_51 -> V_85 = V_22 -> V_86 ;
V_51 -> V_87 = V_22 -> V_78 . V_70 ;
F_37 ( V_51 , V_2 -> V_30 [ 0 ] , V_2 -> V_16 -> V_88 ) ;
F_38 ( V_51 , & V_49 -> V_63 ,
V_65 -> V_89 , V_65 -> V_90 ) ;
V_51 -> V_79 . V_91 = 0 ;
V_51 -> V_79 . V_92 = 0 ;
return 0 ;
V_77:
F_39 ( V_12 , V_69 ) ;
V_76:
V_75:
F_40 ( & V_22 -> V_78 ) ;
return V_71 ;
}
static int F_41 ( struct V_8 * V_9 ,
struct V_48 * V_93 )
{
struct V_1 * V_32 = & V_93 -> V_32 ;
F_42 ( & V_93 -> V_63 ) ;
if ( V_32 -> V_22 )
V_32 -> V_22 = NULL ;
F_43 ( & V_93 -> V_63 ) ;
F_44 ( & V_32 -> V_10 ) ;
return 0 ;
}
int F_45 ( struct V_11 * V_12 )
{
struct V_48 * V_93 ;
int V_94 = 32 ;
int V_71 ;
V_93 = F_46 ( sizeof( struct V_48 ) , V_95 ) ;
if ( ! V_93 )
return - V_96 ;
V_93 -> V_12 = V_12 ;
V_12 -> V_93 = V_93 ;
F_47 ( & V_93 -> V_46 , F_13 ) ;
F_48 ( V_12 -> V_97 , & V_93 -> V_63 ,
& V_98 ) ;
V_71 = F_49 ( V_12 -> V_97 , & V_93 -> V_63 ,
V_99 ) ;
if ( V_71 ) {
F_50 ( V_93 ) ;
return V_71 ;
}
F_51 ( & V_93 -> V_63 ) ;
F_52 ( & V_93 -> V_63 , V_94 ) ;
return 0 ;
}
void F_53 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_93 )
return;
F_41 ( V_12 -> V_97 , V_12 -> V_93 ) ;
F_50 ( V_12 -> V_93 ) ;
V_12 -> V_93 = NULL ;
}
