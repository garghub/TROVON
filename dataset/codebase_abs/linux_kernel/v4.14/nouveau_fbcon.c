static void
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
struct V_12 * V_13 = & V_9 -> V_14 . V_13 ;
int V_15 ;
if ( V_2 -> V_16 != V_17 )
return;
V_15 = - V_18 ;
if ( ! F_2 () && ! ( V_2 -> V_19 & V_20 ) &&
F_3 ( & V_9 -> V_14 . V_21 ) ) {
if ( V_13 -> V_2 . V_22 < V_23 )
V_15 = F_4 ( V_2 , V_4 ) ;
else
if ( V_13 -> V_2 . V_22 < V_24 )
V_15 = F_5 ( V_2 , V_4 ) ;
else
V_15 = F_6 ( V_2 , V_4 ) ;
F_7 ( & V_9 -> V_14 . V_21 ) ;
}
if ( V_15 == 0 )
return;
if ( V_15 != - V_18 )
F_8 ( V_2 ) ;
F_9 ( V_2 , V_4 ) ;
}
static void
F_10 ( struct V_1 * V_2 , const struct V_25 * V_26 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
struct V_12 * V_13 = & V_9 -> V_14 . V_13 ;
int V_15 ;
if ( V_2 -> V_16 != V_17 )
return;
V_15 = - V_18 ;
if ( ! F_2 () && ! ( V_2 -> V_19 & V_20 ) &&
F_3 ( & V_9 -> V_14 . V_21 ) ) {
if ( V_13 -> V_2 . V_22 < V_23 )
V_15 = F_11 ( V_2 , V_26 ) ;
else
if ( V_13 -> V_2 . V_22 < V_24 )
V_15 = F_12 ( V_2 , V_26 ) ;
else
V_15 = F_13 ( V_2 , V_26 ) ;
F_7 ( & V_9 -> V_14 . V_21 ) ;
}
if ( V_15 == 0 )
return;
if ( V_15 != - V_18 )
F_8 ( V_2 ) ;
F_14 ( V_2 , V_26 ) ;
}
static void
F_15 ( struct V_1 * V_2 , const struct V_27 * V_26 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
struct V_12 * V_13 = & V_9 -> V_14 . V_13 ;
int V_15 ;
if ( V_2 -> V_16 != V_17 )
return;
V_15 = - V_18 ;
if ( ! F_2 () && ! ( V_2 -> V_19 & V_20 ) &&
F_3 ( & V_9 -> V_14 . V_21 ) ) {
if ( V_13 -> V_2 . V_22 < V_23 )
V_15 = F_16 ( V_2 , V_26 ) ;
else
if ( V_13 -> V_2 . V_22 < V_24 )
V_15 = F_17 ( V_2 , V_26 ) ;
else
V_15 = F_18 ( V_2 , V_26 ) ;
F_7 ( & V_9 -> V_14 . V_21 ) ;
}
if ( V_15 == 0 )
return;
if ( V_15 != - V_18 )
F_8 ( V_2 ) ;
F_19 ( V_2 , V_26 ) ;
}
static int
F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
struct V_28 * V_29 = V_9 -> V_30 ;
int V_15 ;
if ( ! V_29 || ! V_29 -> V_31 || F_2 () ||
V_2 -> V_16 != V_17 ||
V_2 -> V_19 & V_20 )
return 0 ;
if ( ! F_3 ( & V_9 -> V_14 . V_21 ) )
return 0 ;
V_15 = F_21 ( V_29 ) ;
F_7 ( & V_9 -> V_14 . V_21 ) ;
if ( V_15 ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_29 -> V_31 = false ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 , int V_32 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
int V_15 = F_23 ( V_9 -> V_11 -> V_11 ) ;
if ( V_15 < 0 && V_15 != - V_33 )
return V_15 ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , int V_32 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
F_25 ( V_9 -> V_11 -> V_11 ) ;
return 0 ;
}
void
F_26 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( V_9 -> V_6 && V_9 -> V_6 -> V_10 . V_35 ) {
V_9 -> V_6 -> V_36 = V_9 -> V_6 -> V_10 . V_35 -> V_19 ;
V_9 -> V_6 -> V_10 . V_35 -> V_19 |= V_20 ;
}
}
void
F_27 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( V_9 -> V_6 && V_9 -> V_6 -> V_10 . V_35 ) {
V_9 -> V_6 -> V_10 . V_35 -> V_19 = V_9 -> V_6 -> V_36 ;
}
}
static void
F_28 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
if ( V_6 && V_9 -> V_30 ) {
F_29 () ;
if ( V_6 -> V_10 . V_35 )
V_6 -> V_10 . V_35 -> V_19 |= V_20 ;
F_30 () ;
F_21 ( V_9 -> V_30 ) ;
F_31 ( & V_6 -> V_37 ) ;
F_31 ( & V_6 -> V_38 ) ;
F_31 ( & V_6 -> V_39 ) ;
F_31 ( & V_6 -> V_40 ) ;
F_31 ( & V_6 -> V_41 ) ;
F_31 ( & V_6 -> V_42 ) ;
F_31 ( & V_6 -> V_43 ) ;
}
}
static void
F_32 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_10 . V_35 ;
int V_15 ;
if ( V_9 -> V_14 . V_13 . V_2 . V_22 < V_23 )
V_15 = F_33 ( V_2 ) ;
else
if ( V_9 -> V_14 . V_13 . V_2 . V_22 < V_24 )
V_15 = F_34 ( V_2 ) ;
else
V_15 = F_35 ( V_2 ) ;
if ( V_15 == 0 )
V_2 -> V_44 = & V_45 ;
}
static void
F_36 ( struct V_34 * V_11 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 . V_35 ;
struct V_3 V_4 ;
V_4 . V_46 = V_4 . V_47 = 0 ;
V_4 . V_48 = V_2 -> V_49 . V_50 ;
V_4 . V_51 = V_2 -> V_49 . V_52 ;
V_4 . V_53 = 0 ;
V_4 . V_41 = V_54 ;
V_2 -> V_44 -> V_3 ( V_2 , & V_4 ) ;
}
static int
F_37 ( struct V_55 * V_10 ,
struct V_56 * V_57 )
{
struct V_5 * V_6 =
F_38 ( V_10 , struct V_5 , V_10 ) ;
struct V_34 * V_11 = V_6 -> V_10 . V_11 ;
struct V_8 * V_9 = V_8 ( V_11 ) ;
struct V_12 * V_13 = & V_9 -> V_14 . V_13 ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_28 * V_29 ;
struct V_60 * V_61 ;
struct V_62 V_63 ;
int V_15 ;
V_63 . V_48 = V_57 -> V_64 ;
V_63 . V_51 = V_57 -> V_65 ;
V_63 . V_66 [ 0 ] = V_63 . V_48 * ( V_57 -> V_67 >> 3 ) ;
V_63 . V_66 [ 0 ] = F_39 ( V_63 . V_66 [ 0 ] , 256 ) ;
V_63 . V_68 = F_40 ( V_57 -> V_67 ,
V_57 -> V_69 ) ;
V_15 = F_41 ( & V_9 -> V_14 , V_63 . V_66 [ 0 ] *
V_63 . V_51 , 0 , V_70 ,
0 , 0x0000 , & V_61 ) ;
if ( V_15 ) {
F_42 ( V_9 , L_1 ) ;
goto V_71;
}
V_15 = F_43 ( V_11 , & V_63 , V_61 , & V_59 ) ;
if ( V_15 )
goto V_72;
V_15 = F_44 ( V_61 , V_73 , false ) ;
if ( V_15 ) {
F_42 ( V_9 , L_2 , V_15 ) ;
goto V_72;
}
V_15 = F_45 ( V_61 ) ;
if ( V_15 ) {
F_42 ( V_9 , L_3 , V_15 ) ;
goto V_74;
}
V_29 = V_75 ? NULL : V_9 -> V_30 ;
if ( V_29 && V_13 -> V_2 . V_22 >= V_23 ) {
V_15 = F_46 ( V_61 , V_9 -> V_14 . V_76 , & V_59 -> V_77 ) ;
if ( V_15 ) {
F_42 ( V_9 , L_4 , V_15 ) ;
V_29 = NULL ;
}
}
V_2 = F_47 ( V_10 ) ;
if ( F_48 ( V_2 ) ) {
V_15 = F_49 ( V_2 ) ;
goto V_78;
}
V_2 -> V_79 = 1 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_10 . V_59 = & V_59 -> V_80 ;
strcpy ( V_2 -> V_81 . V_82 , L_5 ) ;
if ( ! V_29 )
V_2 -> V_19 = V_83 | V_20 ;
else
V_2 -> V_19 = V_83 | V_84 |
V_85 |
V_86 ;
V_2 -> V_19 |= V_87 ;
V_2 -> V_44 = & V_88 ;
V_2 -> V_81 . V_89 = V_59 -> V_61 -> V_90 . V_91 . V_92 . V_80 +
V_59 -> V_61 -> V_90 . V_91 . V_92 . V_93 ;
V_2 -> V_81 . V_94 = V_59 -> V_61 -> V_90 . V_91 . V_95 << V_96 ;
V_2 -> V_97 = F_50 ( V_59 -> V_61 ) ;
V_2 -> V_98 = V_59 -> V_61 -> V_90 . V_91 . V_95 << V_96 ;
F_51 ( V_2 , V_59 -> V_80 . V_66 [ 0 ] ,
V_59 -> V_80 . V_99 -> V_100 ) ;
F_52 ( V_2 , & V_6 -> V_10 , V_57 -> V_101 , V_57 -> V_102 ) ;
if ( V_29 )
F_32 ( V_11 ) ;
F_36 ( V_11 , V_6 ) ;
F_53 ( V_9 , L_6 ,
V_59 -> V_80 . V_48 , V_59 -> V_80 . V_51 , V_59 -> V_61 -> V_90 . V_93 , V_61 ) ;
F_54 ( V_11 -> V_103 , V_2 ) ;
return 0 ;
V_78:
if ( V_29 )
F_55 ( V_59 -> V_61 , & V_59 -> V_77 ) ;
F_56 ( V_59 -> V_61 ) ;
V_74:
F_57 ( V_59 -> V_61 ) ;
V_72:
F_58 ( NULL , & V_59 -> V_61 ) ;
V_71:
return V_15 ;
}
void
F_59 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( V_9 -> V_6 )
F_60 ( & V_9 -> V_6 -> V_10 ) ;
}
static int
F_61 ( struct V_34 * V_11 , struct V_5 * V_6 )
{
struct V_58 * V_104 = V_58 ( V_6 -> V_10 . V_59 ) ;
F_62 ( & V_6 -> V_10 ) ;
F_63 ( & V_6 -> V_10 ) ;
if ( V_104 -> V_61 ) {
F_55 ( V_104 -> V_61 , & V_104 -> V_77 ) ;
F_56 ( V_104 -> V_61 ) ;
F_57 ( V_104 -> V_61 ) ;
F_64 ( & V_104 -> V_80 ) ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
F_42 ( V_9 , L_7 ) ;
V_2 -> V_19 |= V_20 ;
}
static void
F_65 ( struct V_105 * V_106 )
{
struct V_8 * V_9 = F_38 ( V_106 , F_66 ( * V_9 ) , V_107 ) ;
int V_16 = F_67 ( V_9 -> V_108 ) ;
if ( V_16 == V_17 )
F_23 ( V_9 -> V_11 -> V_11 ) ;
F_29 () ;
if ( V_16 == V_17 )
F_27 ( V_9 -> V_11 ) ;
F_68 ( & V_9 -> V_6 -> V_10 , V_16 ) ;
if ( V_16 != V_17 )
F_26 ( V_9 -> V_11 ) ;
F_30 () ;
if ( V_16 == V_17 ) {
F_69 ( V_9 -> V_11 -> V_11 ) ;
F_70 ( V_9 -> V_11 -> V_11 ) ;
}
}
void
F_71 ( struct V_34 * V_11 , int V_16 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( ! V_9 -> V_6 )
return;
V_9 -> V_108 = V_16 ;
F_72 ( & V_9 -> V_107 ) ;
}
int
F_73 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
struct V_5 * V_6 ;
int V_109 ;
int V_15 ;
if ( ! V_11 -> V_110 . V_111 ||
( V_11 -> V_103 -> V_112 >> 8 ) != V_113 )
return 0 ;
V_6 = F_74 ( sizeof( struct V_5 ) , V_114 ) ;
if ( ! V_6 )
return - V_115 ;
V_9 -> V_6 = V_6 ;
F_75 ( & V_9 -> V_107 , F_65 ) ;
F_76 ( V_11 , & V_6 -> V_10 , & V_116 ) ;
V_15 = F_77 ( V_11 , & V_6 -> V_10 , 4 ) ;
if ( V_15 )
goto free;
V_15 = F_78 ( & V_6 -> V_10 ) ;
if ( V_15 )
goto V_117;
if ( V_9 -> V_14 . V_13 . V_2 . V_118 <= 32 * 1024 * 1024 )
V_109 = 8 ;
else
if ( V_9 -> V_14 . V_13 . V_2 . V_118 <= 64 * 1024 * 1024 )
V_109 = 16 ;
else
V_109 = 32 ;
if ( ! F_79 ( V_11 ) )
F_80 ( V_11 ) ;
V_15 = F_81 ( & V_6 -> V_10 , V_109 ) ;
if ( V_15 )
goto V_117;
if ( V_6 -> V_10 . V_35 )
V_6 -> V_10 . V_35 -> V_119 . V_120 = 4 ;
return 0 ;
V_117:
F_63 ( & V_6 -> V_10 ) ;
free:
F_82 ( V_6 ) ;
return V_15 ;
}
void
F_83 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( ! V_9 -> V_6 )
return;
F_28 ( V_11 ) ;
F_61 ( V_11 , V_9 -> V_6 ) ;
F_82 ( V_9 -> V_6 ) ;
V_9 -> V_6 = NULL ;
}
