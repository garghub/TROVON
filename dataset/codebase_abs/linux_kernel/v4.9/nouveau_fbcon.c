static void
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_12 ;
int V_13 ;
if ( V_2 -> V_14 != V_15 )
return;
V_13 = - V_16 ;
if ( ! F_2 () && ! ( V_2 -> V_17 & V_18 ) &&
F_3 ( & V_9 -> V_19 . V_20 ) ) {
if ( V_12 -> V_2 . V_21 < V_22 )
V_13 = F_4 ( V_2 , V_4 ) ;
else
if ( V_12 -> V_2 . V_21 < V_23 )
V_13 = F_5 ( V_2 , V_4 ) ;
else
V_13 = F_6 ( V_2 , V_4 ) ;
F_7 ( & V_9 -> V_19 . V_20 ) ;
}
if ( V_13 == 0 )
return;
if ( V_13 != - V_16 )
F_8 ( V_2 ) ;
F_9 ( V_2 , V_4 ) ;
}
static void
F_10 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_12 ;
int V_13 ;
if ( V_2 -> V_14 != V_15 )
return;
V_13 = - V_16 ;
if ( ! F_2 () && ! ( V_2 -> V_17 & V_18 ) &&
F_3 ( & V_9 -> V_19 . V_20 ) ) {
if ( V_12 -> V_2 . V_21 < V_22 )
V_13 = F_11 ( V_2 , V_25 ) ;
else
if ( V_12 -> V_2 . V_21 < V_23 )
V_13 = F_12 ( V_2 , V_25 ) ;
else
V_13 = F_13 ( V_2 , V_25 ) ;
F_7 ( & V_9 -> V_19 . V_20 ) ;
}
if ( V_13 == 0 )
return;
if ( V_13 != - V_16 )
F_8 ( V_2 ) ;
F_14 ( V_2 , V_25 ) ;
}
static void
F_15 ( struct V_1 * V_2 , const struct V_26 * V_25 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_12 ;
int V_13 ;
if ( V_2 -> V_14 != V_15 )
return;
V_13 = - V_16 ;
if ( ! F_2 () && ! ( V_2 -> V_17 & V_18 ) &&
F_3 ( & V_9 -> V_19 . V_20 ) ) {
if ( V_12 -> V_2 . V_21 < V_22 )
V_13 = F_16 ( V_2 , V_25 ) ;
else
if ( V_12 -> V_2 . V_21 < V_23 )
V_13 = F_17 ( V_2 , V_25 ) ;
else
V_13 = F_18 ( V_2 , V_25 ) ;
F_7 ( & V_9 -> V_19 . V_20 ) ;
}
if ( V_13 == 0 )
return;
if ( V_13 != - V_16 )
F_8 ( V_2 ) ;
F_19 ( V_2 , V_25 ) ;
}
static int
F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_27 * V_28 = V_9 -> V_29 ;
int V_13 ;
if ( ! V_28 || ! V_28 -> V_30 || F_2 () ||
V_2 -> V_14 != V_15 ||
V_2 -> V_17 & V_18 )
return 0 ;
if ( ! F_3 ( & V_9 -> V_19 . V_20 ) )
return 0 ;
V_13 = F_21 ( V_28 ) ;
F_7 ( & V_9 -> V_19 . V_20 ) ;
if ( V_13 ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_28 -> V_30 = false ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 , int V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
int V_13 = F_23 ( V_9 -> V_10 -> V_10 ) ;
if ( V_13 < 0 && V_13 != - V_32 )
return V_13 ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , int V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
F_25 ( V_9 -> V_10 -> V_10 ) ;
return 0 ;
}
void
F_26 ( struct V_33 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( V_9 -> V_6 ) {
V_9 -> V_6 -> V_34 = V_9 -> V_6 -> V_35 . V_36 -> V_17 ;
V_9 -> V_6 -> V_35 . V_36 -> V_17 |= V_18 ;
}
}
void
F_27 ( struct V_33 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( V_9 -> V_6 ) {
V_9 -> V_6 -> V_35 . V_36 -> V_17 = V_9 -> V_6 -> V_34 ;
}
}
static void
F_28 ( struct V_33 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
if ( V_6 && V_9 -> V_29 ) {
F_29 () ;
V_6 -> V_35 . V_36 -> V_17 |= V_18 ;
F_30 () ;
F_21 ( V_9 -> V_29 ) ;
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
F_32 ( struct V_33 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_35 . V_36 ;
int V_13 ;
if ( V_9 -> V_12 . V_2 . V_21 < V_22 )
V_13 = F_33 ( V_2 ) ;
else
if ( V_9 -> V_12 . V_2 . V_21 < V_23 )
V_13 = F_34 ( V_2 ) ;
else
V_13 = F_35 ( V_2 ) ;
if ( V_13 == 0 )
V_2 -> V_44 = & V_45 ;
}
static void F_36 ( struct V_46 * V_47 , T_1 V_48 , T_1 V_49 ,
T_1 V_50 , int V_51 )
{
struct V_52 * V_53 = V_52 ( V_47 ) ;
V_53 -> V_54 . V_55 [ V_51 ] = V_48 ;
V_53 -> V_54 . V_56 [ V_51 ] = V_49 ;
V_53 -> V_54 . V_57 [ V_51 ] = V_50 ;
}
static void F_37 ( struct V_46 * V_47 , T_1 * V_48 , T_1 * V_49 ,
T_1 * V_50 , int V_51 )
{
struct V_52 * V_53 = V_52 ( V_47 ) ;
* V_48 = V_53 -> V_54 . V_55 [ V_51 ] ;
* V_49 = V_53 -> V_54 . V_56 [ V_51 ] ;
* V_50 = V_53 -> V_54 . V_57 [ V_51 ] ;
}
static void
F_38 ( struct V_33 * V_10 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_35 . V_36 ;
struct V_3 V_4 ;
V_4 . V_58 = V_4 . V_59 = 0 ;
V_4 . V_60 = V_2 -> V_61 . V_62 ;
V_4 . V_63 = V_2 -> V_61 . V_64 ;
V_4 . V_65 = 0 ;
V_4 . V_41 = V_66 ;
V_2 -> V_44 -> V_3 ( V_2 , & V_4 ) ;
}
static int
F_39 ( struct V_67 * V_35 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 =
F_40 ( V_35 , struct V_5 , V_35 ) ;
struct V_33 * V_10 = V_6 -> V_10 ;
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_12 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_27 * V_28 ;
struct V_74 * V_75 ;
struct V_76 V_77 ;
int V_78 , V_13 ;
V_77 . V_60 = V_69 -> V_79 ;
V_77 . V_63 = V_69 -> V_80 ;
V_77 . V_81 [ 0 ] = V_77 . V_60 * ( V_69 -> V_82 >> 3 ) ;
V_77 . V_81 [ 0 ] = F_41 ( V_77 . V_81 [ 0 ] , 256 ) ;
V_77 . V_83 = F_42 ( V_69 -> V_82 ,
V_69 -> V_84 ) ;
V_78 = V_77 . V_81 [ 0 ] * V_77 . V_63 ;
V_78 = F_41 ( V_78 , V_85 ) ;
V_13 = F_43 ( V_10 , V_78 , 0 , V_86 ,
0 , 0x0000 , & V_75 ) ;
if ( V_13 ) {
F_44 ( V_9 , L_1 ) ;
goto V_87;
}
V_13 = F_45 ( V_75 , V_88 , false ) ;
if ( V_13 ) {
F_44 ( V_9 , L_2 , V_13 ) ;
goto V_89;
}
V_13 = F_46 ( V_75 ) ;
if ( V_13 ) {
F_44 ( V_9 , L_3 , V_13 ) ;
goto V_90;
}
V_28 = V_91 ? NULL : V_9 -> V_29 ;
if ( V_28 && V_12 -> V_2 . V_21 >= V_22 ) {
V_13 = F_47 ( V_75 , V_9 -> V_19 . V_92 ,
& V_6 -> V_73 . V_93 ) ;
if ( V_13 ) {
F_44 ( V_9 , L_4 , V_13 ) ;
V_28 = NULL ;
}
}
V_2 = F_48 ( V_35 ) ;
if ( F_49 ( V_2 ) ) {
V_13 = F_50 ( V_2 ) ;
goto V_94;
}
V_2 -> V_95 = 1 ;
V_2 -> V_7 = V_6 ;
F_51 ( V_10 , & V_6 -> V_73 , & V_77 , V_75 ) ;
V_73 = & V_6 -> V_73 ;
V_71 = & V_73 -> V_96 ;
V_6 -> V_35 . V_71 = V_71 ;
strcpy ( V_2 -> V_97 . V_98 , L_5 ) ;
if ( ! V_28 )
V_2 -> V_17 = V_99 | V_18 ;
else
V_2 -> V_17 = V_99 | V_100 |
V_101 |
V_102 ;
V_2 -> V_17 |= V_103 ;
V_2 -> V_44 = & V_104 ;
V_2 -> V_97 . V_105 = V_75 -> V_106 . V_107 . V_108 . V_96 +
V_75 -> V_106 . V_107 . V_108 . V_109 ;
V_2 -> V_97 . V_110 = V_78 ;
V_2 -> V_111 = F_52 ( V_73 -> V_75 ) ;
V_2 -> V_112 = V_78 ;
F_53 ( V_2 , V_71 -> V_81 [ 0 ] , V_71 -> V_113 ) ;
F_54 ( V_2 , & V_6 -> V_35 , V_69 -> V_114 , V_69 -> V_115 ) ;
if ( V_28 )
F_32 ( V_10 ) ;
F_38 ( V_10 , V_6 ) ;
F_55 ( V_9 , L_6 ,
V_73 -> V_96 . V_60 , V_73 -> V_96 . V_63 ,
V_75 -> V_106 . V_109 , V_75 ) ;
F_56 ( V_10 -> V_116 , V_2 ) ;
return 0 ;
V_94:
if ( V_28 )
F_57 ( V_75 , & V_6 -> V_73 . V_93 ) ;
F_58 ( V_75 ) ;
V_90:
F_59 ( V_75 ) ;
V_89:
F_60 ( NULL , & V_75 ) ;
V_87:
return V_13 ;
}
void
F_61 ( struct V_33 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( V_9 -> V_6 )
F_62 ( & V_9 -> V_6 -> V_35 ) ;
}
static int
F_63 ( struct V_33 * V_10 , struct V_5 * V_6 )
{
struct V_72 * V_73 = & V_6 -> V_73 ;
F_64 ( & V_6 -> V_35 ) ;
F_65 ( & V_6 -> V_35 ) ;
if ( V_73 -> V_75 ) {
F_58 ( V_73 -> V_75 ) ;
F_57 ( V_73 -> V_75 , & V_73 -> V_93 ) ;
F_59 ( V_73 -> V_75 ) ;
F_66 ( & V_73 -> V_75 -> V_117 ) ;
V_73 -> V_75 = NULL ;
}
F_67 ( & V_6 -> V_35 ) ;
F_68 ( & V_73 -> V_96 ) ;
F_69 ( & V_73 -> V_96 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
F_44 ( V_9 , L_7 ) ;
V_2 -> V_17 |= V_18 ;
}
void
F_70 ( struct V_33 * V_10 , int V_14 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( V_9 -> V_6 ) {
F_29 () ;
if ( V_14 == V_15 )
F_27 ( V_10 ) ;
F_71 ( & V_9 -> V_6 -> V_35 , V_14 ) ;
if ( V_14 != V_15 )
F_26 ( V_10 ) ;
F_30 () ;
}
}
int
F_72 ( struct V_33 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_5 * V_6 ;
int V_118 ;
int V_13 ;
if ( ! V_10 -> V_119 . V_120 ||
( V_10 -> V_116 -> V_121 >> 8 ) != V_122 )
return 0 ;
V_6 = F_73 ( sizeof( struct V_5 ) , V_123 ) ;
if ( ! V_6 )
return - V_124 ;
V_6 -> V_10 = V_10 ;
V_9 -> V_6 = V_6 ;
F_74 ( V_10 , & V_6 -> V_35 , & V_125 ) ;
V_13 = F_75 ( V_10 , & V_6 -> V_35 ,
V_10 -> V_119 . V_120 , 4 ) ;
if ( V_13 )
goto free;
V_13 = F_76 ( & V_6 -> V_35 ) ;
if ( V_13 )
goto V_126;
if ( V_9 -> V_12 . V_2 . V_127 <= 32 * 1024 * 1024 )
V_118 = 8 ;
else
if ( V_9 -> V_12 . V_2 . V_127 <= 64 * 1024 * 1024 )
V_118 = 16 ;
else
V_118 = 32 ;
F_77 ( V_10 ) ;
V_13 = F_78 ( & V_6 -> V_35 , V_118 ) ;
if ( V_13 )
goto V_126;
if ( V_6 -> V_35 . V_36 )
V_6 -> V_35 . V_36 -> V_128 . V_129 = 4 ;
return 0 ;
V_126:
F_67 ( & V_6 -> V_35 ) ;
free:
F_79 ( V_6 ) ;
return V_13 ;
}
void
F_80 ( struct V_33 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( ! V_9 -> V_6 )
return;
F_28 ( V_10 ) ;
F_63 ( V_10 , V_9 -> V_6 ) ;
F_79 ( V_9 -> V_6 ) ;
V_9 -> V_6 = NULL ;
}
