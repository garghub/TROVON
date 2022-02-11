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
if ( V_9 -> V_6 ) {
V_9 -> V_6 -> V_35 = V_9 -> V_6 -> V_10 . V_36 -> V_19 ;
V_9 -> V_6 -> V_10 . V_36 -> V_19 |= V_20 ;
}
}
void
F_27 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( V_9 -> V_6 ) {
V_9 -> V_6 -> V_10 . V_36 -> V_19 = V_9 -> V_6 -> V_35 ;
}
}
static void
F_28 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
if ( V_6 && V_9 -> V_30 ) {
F_29 () ;
V_6 -> V_10 . V_36 -> V_19 |= V_20 ;
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
struct V_1 * V_2 = V_6 -> V_10 . V_36 ;
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
F_38 ( struct V_34 * V_11 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 . V_36 ;
struct V_3 V_4 ;
V_4 . V_58 = V_4 . V_59 = 0 ;
V_4 . V_60 = V_2 -> V_61 . V_62 ;
V_4 . V_63 = V_2 -> V_61 . V_64 ;
V_4 . V_65 = 0 ;
V_4 . V_41 = V_66 ;
V_2 -> V_44 -> V_3 ( V_2 , & V_4 ) ;
}
static int
F_39 ( struct V_67 * V_10 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 =
F_40 ( V_10 , struct V_5 , V_10 ) ;
struct V_34 * V_11 = V_6 -> V_10 . V_11 ;
struct V_8 * V_9 = V_8 ( V_11 ) ;
struct V_12 * V_13 = & V_9 -> V_14 . V_13 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
struct V_28 * V_29 ;
struct V_72 * V_73 ;
struct V_74 V_75 ;
int V_15 ;
V_75 . V_60 = V_69 -> V_76 ;
V_75 . V_63 = V_69 -> V_77 ;
V_75 . V_78 [ 0 ] = V_75 . V_60 * ( V_69 -> V_79 >> 3 ) ;
V_75 . V_78 [ 0 ] = F_41 ( V_75 . V_78 [ 0 ] , 256 ) ;
V_75 . V_80 = F_42 ( V_69 -> V_79 ,
V_69 -> V_81 ) ;
V_15 = F_43 ( & V_9 -> V_14 , V_75 . V_78 [ 0 ] *
V_75 . V_63 , 0 , V_82 ,
0 , 0x0000 , & V_73 ) ;
if ( V_15 ) {
F_44 ( V_9 , L_1 ) ;
goto V_83;
}
V_15 = F_45 ( V_11 , & V_75 , V_73 , & V_71 ) ;
if ( V_15 )
goto V_84;
V_15 = F_46 ( V_73 , V_85 , false ) ;
if ( V_15 ) {
F_44 ( V_9 , L_2 , V_15 ) ;
goto V_84;
}
V_15 = F_47 ( V_73 ) ;
if ( V_15 ) {
F_44 ( V_9 , L_3 , V_15 ) ;
goto V_86;
}
V_29 = V_87 ? NULL : V_9 -> V_30 ;
if ( V_29 && V_13 -> V_2 . V_22 >= V_23 ) {
V_15 = F_48 ( V_73 , V_9 -> V_14 . V_88 , & V_71 -> V_89 ) ;
if ( V_15 ) {
F_44 ( V_9 , L_4 , V_15 ) ;
V_29 = NULL ;
}
}
V_2 = F_49 ( V_10 ) ;
if ( F_50 ( V_2 ) ) {
V_15 = F_51 ( V_2 ) ;
goto V_90;
}
V_2 -> V_91 = 1 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_10 . V_71 = & V_71 -> V_92 ;
strcpy ( V_2 -> V_93 . V_94 , L_5 ) ;
if ( ! V_29 )
V_2 -> V_19 = V_95 | V_20 ;
else
V_2 -> V_19 = V_95 | V_96 |
V_97 |
V_98 ;
V_2 -> V_19 |= V_99 ;
V_2 -> V_44 = & V_100 ;
V_2 -> V_93 . V_101 = V_71 -> V_73 -> V_102 . V_103 . V_104 . V_92 +
V_71 -> V_73 -> V_102 . V_103 . V_104 . V_105 ;
V_2 -> V_93 . V_106 = V_71 -> V_73 -> V_102 . V_103 . V_107 << V_108 ;
V_2 -> V_109 = F_52 ( V_71 -> V_73 ) ;
V_2 -> V_110 = V_71 -> V_73 -> V_102 . V_103 . V_107 << V_108 ;
F_53 ( V_2 , V_71 -> V_92 . V_78 [ 0 ] ,
V_71 -> V_92 . V_111 -> V_112 ) ;
F_54 ( V_2 , & V_6 -> V_10 , V_69 -> V_113 , V_69 -> V_114 ) ;
if ( V_29 )
F_32 ( V_11 ) ;
F_38 ( V_11 , V_6 ) ;
F_55 ( V_9 , L_6 ,
V_71 -> V_92 . V_60 , V_71 -> V_92 . V_63 , V_71 -> V_73 -> V_102 . V_105 , V_73 ) ;
F_56 ( V_11 -> V_115 , V_2 ) ;
return 0 ;
V_90:
if ( V_29 )
F_57 ( V_71 -> V_73 , & V_71 -> V_89 ) ;
F_58 ( V_71 -> V_73 ) ;
V_86:
F_59 ( V_71 -> V_73 ) ;
V_84:
F_60 ( NULL , & V_71 -> V_73 ) ;
V_83:
return V_15 ;
}
void
F_61 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( V_9 -> V_6 )
F_62 ( & V_9 -> V_6 -> V_10 ) ;
}
static int
F_63 ( struct V_34 * V_11 , struct V_5 * V_6 )
{
struct V_70 * V_116 = V_70 ( V_6 -> V_10 . V_71 ) ;
F_64 ( & V_6 -> V_10 ) ;
F_65 ( & V_6 -> V_10 ) ;
if ( V_116 -> V_73 ) {
F_57 ( V_116 -> V_73 , & V_116 -> V_89 ) ;
F_58 ( V_116 -> V_73 ) ;
F_59 ( V_116 -> V_73 ) ;
F_66 ( & V_116 -> V_92 ) ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
F_44 ( V_9 , L_7 ) ;
V_2 -> V_19 |= V_20 ;
}
static void
F_67 ( struct V_117 * V_118 )
{
struct V_8 * V_9 = F_40 ( V_118 , F_68 ( * V_9 ) , V_119 ) ;
int V_16 = F_69 ( V_9 -> V_120 ) ;
if ( V_16 == V_17 )
F_23 ( V_9 -> V_11 -> V_11 ) ;
F_29 () ;
if ( V_16 == V_17 )
F_27 ( V_9 -> V_11 ) ;
F_70 ( & V_9 -> V_6 -> V_10 , V_16 ) ;
if ( V_16 != V_17 )
F_26 ( V_9 -> V_11 ) ;
F_30 () ;
if ( V_16 == V_17 ) {
F_71 ( V_9 -> V_11 -> V_11 ) ;
F_72 ( V_9 -> V_11 -> V_11 ) ;
}
}
void
F_73 ( struct V_34 * V_11 , int V_16 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( ! V_9 -> V_6 )
return;
V_9 -> V_120 = V_16 ;
F_74 ( & V_9 -> V_119 ) ;
}
int
F_75 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
struct V_5 * V_6 ;
int V_121 ;
int V_15 ;
if ( ! V_11 -> V_122 . V_123 ||
( V_11 -> V_115 -> V_124 >> 8 ) != V_125 )
return 0 ;
V_6 = F_76 ( sizeof( struct V_5 ) , V_126 ) ;
if ( ! V_6 )
return - V_127 ;
V_9 -> V_6 = V_6 ;
F_77 ( & V_9 -> V_119 , F_67 ) ;
F_78 ( V_11 , & V_6 -> V_10 , & V_128 ) ;
V_15 = F_79 ( V_11 , & V_6 -> V_10 , 4 ) ;
if ( V_15 )
goto free;
V_15 = F_80 ( & V_6 -> V_10 ) ;
if ( V_15 )
goto V_129;
if ( V_9 -> V_14 . V_13 . V_2 . V_130 <= 32 * 1024 * 1024 )
V_121 = 8 ;
else
if ( V_9 -> V_14 . V_13 . V_2 . V_130 <= 64 * 1024 * 1024 )
V_121 = 16 ;
else
V_121 = 32 ;
if ( ! F_81 ( V_11 ) )
F_82 ( V_11 ) ;
V_15 = F_83 ( & V_6 -> V_10 , V_121 ) ;
if ( V_15 )
goto V_129;
if ( V_6 -> V_10 . V_36 )
V_6 -> V_10 . V_36 -> V_131 . V_132 = 4 ;
return 0 ;
V_129:
F_65 ( & V_6 -> V_10 ) ;
free:
F_84 ( V_6 ) ;
return V_15 ;
}
void
F_85 ( struct V_34 * V_11 )
{
struct V_8 * V_9 = V_8 ( V_11 ) ;
if ( ! V_9 -> V_6 )
return;
F_28 ( V_11 ) ;
F_63 ( V_11 , V_9 -> V_6 ) ;
F_84 ( V_9 -> V_6 ) ;
V_9 -> V_6 = NULL ;
}
