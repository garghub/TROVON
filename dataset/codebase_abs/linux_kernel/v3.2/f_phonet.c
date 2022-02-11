static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
F_4 ( V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 )
{
F_6 ( V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_13 * V_14 = V_10 -> V_15 ;
switch ( V_10 -> V_16 ) {
case 0 :
V_6 -> V_17 . V_18 ++ ;
V_6 -> V_17 . V_19 += V_14 -> V_20 ;
break;
case - V_21 :
case - V_22 :
V_6 -> V_17 . V_23 ++ ;
default:
V_6 -> V_17 . V_24 ++ ;
}
F_8 ( V_14 ) ;
F_4 ( V_6 ) ;
}
static int F_9 ( struct V_13 * V_14 , struct V_5 * V_6 )
{
struct V_25 * V_26 = F_10 ( V_6 ) ;
struct V_1 * V_11 ;
struct V_9 * V_10 ;
unsigned long V_27 ;
if ( V_14 -> V_28 != F_11 ( V_29 ) )
goto V_30;
F_12 ( & V_26 -> V_31 , V_27 ) ;
V_11 = V_26 -> V_32 ;
if ( F_13 ( ! V_11 ) )
goto V_33;
V_10 = V_11 -> V_34 ;
V_10 -> V_35 = V_14 -> V_36 ;
V_10 -> V_37 = V_14 -> V_20 ;
V_10 -> V_38 = F_7 ;
V_10 -> V_39 = 1 ;
V_10 -> V_15 = V_14 ;
if ( F_13 ( F_14 ( V_11 -> V_40 , V_10 , V_41 ) ) )
goto V_33;
F_6 ( V_6 ) ;
V_14 = NULL ;
V_33:
F_15 ( & V_26 -> V_31 , V_27 ) ;
V_30:
if ( F_13 ( V_14 ) ) {
F_16 ( V_14 ) ;
V_6 -> V_17 . V_42 ++ ;
}
return V_43 ;
}
static int F_17 ( struct V_5 * V_6 , int V_44 )
{
if ( ( V_44 < V_45 ) || ( V_44 > V_46 ) )
return - V_47 ;
V_6 -> V_48 = V_44 ;
return 0 ;
}
static void F_18 ( struct V_5 * V_6 )
{
V_6 -> V_49 = 0 ;
V_6 -> type = V_50 ;
V_6 -> V_27 = V_51 | V_52 ;
V_6 -> V_48 = V_53 ;
V_6 -> V_54 = 1 ;
V_6 -> V_55 [ 0 ] = V_56 ;
V_6 -> V_57 = 1 ;
V_6 -> V_58 = 1 ;
V_6 -> V_59 = & V_60 ;
V_6 -> V_61 = V_62 ;
V_6 -> V_63 = & V_64 ;
}
static int
F_19 ( struct V_1 * V_11 , struct V_9 * V_10 , T_1 V_65 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_66 * V_66 ;
int V_67 ;
V_66 = F_20 ( V_6 , V_65 ) ;
if ( ! V_66 )
return - V_68 ;
V_10 -> V_35 = F_21 ( V_66 ) ;
V_10 -> V_37 = V_69 ;
V_10 -> V_15 = V_66 ;
V_67 = F_14 ( V_11 -> V_70 , V_10 , V_65 ) ;
if ( F_13 ( V_67 ) )
F_22 ( V_6 , V_66 ) ;
return V_67 ;
}
static void F_23 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_1 * V_11 = V_8 -> V_12 ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_66 * V_66 = V_10 -> V_15 ;
struct V_13 * V_14 ;
unsigned long V_27 ;
int V_16 = V_10 -> V_16 ;
switch ( V_16 ) {
case 0 :
F_12 ( & V_11 -> V_71 . V_31 , V_27 ) ;
V_14 = V_11 -> V_71 . V_14 ;
if ( ! V_14 )
V_14 = V_11 -> V_71 . V_14 = F_24 ( V_6 , 12 ) ;
if ( V_10 -> V_72 < V_10 -> V_37 )
V_11 -> V_71 . V_14 = NULL ;
F_15 ( & V_11 -> V_71 . V_31 , V_27 ) ;
if ( F_13 ( ! V_14 ) )
break;
if ( V_14 -> V_20 == 0 ) {
V_14 -> V_28 = F_11 ( V_29 ) ;
F_25 ( V_14 ) ;
memcpy ( F_26 ( V_14 , 1 ) , F_21 ( V_66 ) , 1 ) ;
}
F_27 ( V_14 , F_28 ( V_14 ) -> V_73 , V_66 ,
V_14 -> V_20 <= 1 , V_10 -> V_72 ) ;
V_66 = NULL ;
if ( V_10 -> V_72 < V_10 -> V_37 ) {
V_14 -> V_6 = V_6 ;
V_6 -> V_17 . V_74 ++ ;
V_6 -> V_17 . V_75 += V_14 -> V_20 ;
F_29 ( V_14 ) ;
}
break;
case - V_21 :
case - V_76 :
case - V_22 :
V_10 = NULL ;
break;
case - V_77 :
V_6 -> V_17 . V_78 ++ ;
default:
V_6 -> V_17 . V_79 ++ ;
break;
}
if ( V_66 )
F_22 ( V_6 , V_66 ) ;
if ( V_10 )
F_19 ( V_11 , V_10 , V_41 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_25 * V_26 = F_10 ( V_6 ) ;
F_31 ( V_6 ) ;
V_26 -> V_32 = NULL ;
F_32 ( V_11 -> V_70 ) ;
F_32 ( V_11 -> V_40 ) ;
if ( V_11 -> V_71 . V_14 ) {
F_33 ( V_11 -> V_71 . V_14 ) ;
V_11 -> V_71 . V_14 = NULL ;
}
}
static int F_34 ( struct V_2 * V_3 , unsigned V_80 , unsigned V_81 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_82 * V_83 = V_11 -> V_4 . V_84 -> V_85 -> V_83 ;
if ( V_80 == V_86 . V_87 )
return ( V_81 > 0 ) ? - V_47 : 0 ;
if ( V_80 == V_88 . V_87 ) {
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_25 * V_26 = F_10 ( V_6 ) ;
if ( V_81 > 1 )
return - V_47 ;
F_35 ( & V_26 -> V_31 ) ;
F_30 ( V_3 ) ;
if ( V_81 == 1 ) {
int V_89 ;
if ( F_36 ( V_83 , V_3 , V_11 -> V_40 ) ||
F_36 ( V_83 , V_3 , V_11 -> V_70 ) ) {
V_11 -> V_40 -> V_90 = NULL ;
V_11 -> V_70 -> V_90 = NULL ;
F_37 ( & V_26 -> V_31 ) ;
return - V_47 ;
}
F_38 ( V_11 -> V_70 ) ;
F_38 ( V_11 -> V_40 ) ;
V_26 -> V_32 = V_11 ;
V_11 -> V_70 -> V_12 = V_11 ;
V_11 -> V_40 -> V_12 = V_11 ;
F_39 ( V_6 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ )
F_19 ( V_11 , V_11 -> V_92 [ V_89 ] , V_41 ) ;
}
F_37 ( & V_26 -> V_31 ) ;
return 0 ;
}
return - V_47 ;
}
static int F_40 ( struct V_2 * V_3 , unsigned V_80 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_80 == V_86 . V_87 )
return 0 ;
if ( V_80 == V_88 . V_87 ) {
struct V_25 * V_26 = F_10 ( V_11 -> V_6 ) ;
T_2 V_81 ;
F_35 ( & V_26 -> V_31 ) ;
V_81 = V_26 -> V_32 != NULL ;
F_37 ( & V_26 -> V_31 ) ;
return V_81 ;
}
return - V_47 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_25 * V_26 = F_10 ( V_11 -> V_6 ) ;
unsigned long V_27 ;
F_12 ( & V_26 -> V_31 , V_27 ) ;
F_30 ( V_3 ) ;
F_15 ( & V_26 -> V_31 , V_27 ) ;
}
static T_3
int F_42 ( struct V_93 * V_94 , struct V_2 * V_3 )
{
struct V_95 * V_85 = V_94 -> V_85 ;
struct V_82 * V_83 = V_85 -> V_83 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_7 * V_8 ;
int V_16 , V_89 ;
V_16 = F_43 ( V_94 , V_3 ) ;
if ( V_16 < 0 )
goto V_67;
V_86 . V_87 = V_16 ;
V_96 . V_97 = V_16 ;
V_16 = F_43 ( V_94 , V_3 ) ;
if ( V_16 < 0 )
goto V_67;
V_98 . V_87 = V_16 ;
V_88 . V_87 = V_16 ;
V_96 . V_99 = V_16 ;
V_16 = - V_100 ;
V_8 = F_44 ( V_83 , & V_101 ) ;
if ( ! V_8 )
goto V_67;
V_11 -> V_70 = V_8 ;
V_8 -> V_12 = V_11 ;
V_8 = F_44 ( V_83 , & V_102 ) ;
if ( ! V_8 )
goto V_67;
V_11 -> V_40 = V_8 ;
V_8 -> V_12 = V_11 ;
V_103 . V_104 =
V_101 . V_104 ;
V_105 . V_104 =
V_102 . V_104 ;
V_11 -> V_4 . V_106 = V_107 ;
V_11 -> V_4 . V_108 = V_109 ;
V_16 = - V_68 ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
struct V_9 * V_10 ;
V_10 = F_45 ( V_11 -> V_70 , V_110 ) ;
if ( ! V_10 )
goto V_67;
V_10 -> V_38 = F_23 ;
V_11 -> V_92 [ V_89 ] = V_10 ;
}
V_11 -> V_34 = F_45 ( V_11 -> V_40 , V_110 ) ;
if ( ! V_11 -> V_34 )
goto V_67;
F_46 ( V_85 , L_1 ) ;
F_46 ( V_85 , L_2 , V_85 -> V_83 -> V_111 ,
V_11 -> V_70 -> V_111 , V_11 -> V_40 -> V_111 ) ;
return 0 ;
V_67:
if ( V_11 -> V_70 )
V_11 -> V_70 -> V_12 = NULL ;
if ( V_11 -> V_40 )
V_11 -> V_40 -> V_12 = NULL ;
ERROR ( V_85 , L_3 ) ;
return V_16 ;
}
static void
F_47 ( struct V_93 * V_94 , struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_89 ;
if ( V_11 -> V_34 )
F_48 ( V_11 -> V_40 , V_11 -> V_34 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ )
if ( V_11 -> V_92 [ V_89 ] )
F_48 ( V_11 -> V_70 , V_11 -> V_92 [ V_89 ] ) ;
F_49 ( V_11 ) ;
}
int T_3 F_50 ( struct V_93 * V_94 )
{
struct V_1 * V_11 ;
int V_67 , V_112 ;
V_112 = sizeof( * V_11 ) + ( V_91 * sizeof( struct V_9 * ) ) ;
V_11 = F_51 ( V_112 , V_110 ) ;
if ( ! V_11 )
return - V_68 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_4 . V_111 = L_4 ;
V_11 -> V_4 . V_113 = F_42 ;
V_11 -> V_4 . V_114 = F_47 ;
V_11 -> V_4 . V_115 = F_34 ;
V_11 -> V_4 . V_116 = F_40 ;
V_11 -> V_4 . V_117 = F_41 ;
F_52 ( & V_11 -> V_71 . V_31 ) ;
V_67 = F_53 ( V_94 , & V_11 -> V_4 ) ;
if ( V_67 )
F_49 ( V_11 ) ;
return V_67 ;
}
int T_3 F_54 ( struct V_82 * V_83 )
{
struct V_25 * V_26 ;
int V_67 ;
F_55 ( V_6 ) ;
V_6 = F_56 ( sizeof( * V_26 ) , L_5 , F_18 ) ;
if ( ! V_6 )
return - V_68 ;
V_26 = F_10 ( V_6 ) ;
F_52 ( & V_26 -> V_31 ) ;
F_31 ( V_6 ) ;
F_57 ( V_6 , & V_83 -> V_6 ) ;
V_67 = F_58 ( V_6 ) ;
if ( V_67 )
V_62 ( V_6 ) ;
return V_67 ;
}
void F_59 ( void )
{
F_60 ( V_6 ) ;
}
