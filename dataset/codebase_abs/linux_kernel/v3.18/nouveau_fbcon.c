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
void
F_22 ( struct V_31 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( V_9 -> V_6 ) {
V_9 -> V_6 -> V_32 = V_9 -> V_6 -> V_33 . V_34 -> V_17 ;
V_9 -> V_6 -> V_33 . V_34 -> V_17 |= V_18 ;
}
}
void
F_23 ( struct V_31 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( V_9 -> V_6 ) {
V_9 -> V_6 -> V_33 . V_34 -> V_17 = V_9 -> V_6 -> V_32 ;
}
}
static void
F_24 ( struct V_31 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
if ( V_6 && V_9 -> V_29 ) {
F_25 () ;
V_6 -> V_33 . V_34 -> V_17 |= V_18 ;
F_26 () ;
F_21 ( V_9 -> V_29 ) ;
F_27 ( & V_6 -> V_35 ) ;
F_27 ( & V_6 -> V_36 ) ;
F_27 ( & V_6 -> V_37 ) ;
F_27 ( & V_6 -> V_38 ) ;
F_27 ( & V_6 -> V_39 ) ;
F_27 ( & V_6 -> V_40 ) ;
F_27 ( & V_6 -> V_41 ) ;
}
}
static void
F_28 ( struct V_31 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_5 * V_6 = V_9 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_33 . V_34 ;
int V_13 ;
if ( V_9 -> V_12 . V_2 . V_21 < V_22 )
V_13 = F_29 ( V_2 ) ;
else
if ( V_9 -> V_12 . V_2 . V_21 < V_23 )
V_13 = F_30 ( V_2 ) ;
else
V_13 = F_31 ( V_2 ) ;
if ( V_13 == 0 )
V_2 -> V_42 = & V_43 ;
}
static void F_32 ( struct V_44 * V_45 , T_1 V_46 , T_1 V_47 ,
T_1 V_48 , int V_49 )
{
struct V_50 * V_51 = V_50 ( V_45 ) ;
V_51 -> V_52 . V_53 [ V_49 ] = V_46 ;
V_51 -> V_52 . V_54 [ V_49 ] = V_47 ;
V_51 -> V_52 . V_55 [ V_49 ] = V_48 ;
}
static void F_33 ( struct V_44 * V_45 , T_1 * V_46 , T_1 * V_47 ,
T_1 * V_48 , int V_49 )
{
struct V_50 * V_51 = V_50 ( V_45 ) ;
* V_46 = V_51 -> V_52 . V_53 [ V_49 ] ;
* V_47 = V_51 -> V_52 . V_54 [ V_49 ] ;
* V_48 = V_51 -> V_52 . V_55 [ V_49 ] ;
}
static void
F_34 ( struct V_31 * V_10 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_33 . V_34 ;
struct V_3 V_4 ;
V_4 . V_56 = V_4 . V_57 = 0 ;
V_4 . V_58 = V_2 -> V_59 . V_60 ;
V_4 . V_61 = V_2 -> V_59 . V_62 ;
V_4 . V_63 = 0 ;
V_4 . V_39 = V_64 ;
V_2 -> V_42 -> V_3 ( V_2 , & V_4 ) ;
}
static int
F_35 ( struct V_65 * V_33 ,
struct V_66 * V_67 )
{
struct V_5 * V_6 =
F_36 ( V_33 , struct V_5 , V_33 ) ;
struct V_31 * V_10 = V_6 -> V_10 ;
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_12 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_27 * V_28 ;
struct V_72 * V_73 ;
struct V_74 V_75 ;
struct V_76 * V_77 = V_10 -> V_77 ;
int V_78 , V_13 ;
V_75 . V_58 = V_67 -> V_79 ;
V_75 . V_61 = V_67 -> V_80 ;
V_75 . V_81 [ 0 ] = V_75 . V_58 * ( V_67 -> V_82 >> 3 ) ;
V_75 . V_81 [ 0 ] = F_37 ( V_75 . V_81 [ 0 ] , 256 ) ;
V_75 . V_83 = F_38 ( V_67 -> V_82 ,
V_67 -> V_84 ) ;
V_78 = V_75 . V_81 [ 0 ] * V_75 . V_61 ;
V_78 = F_37 ( V_78 , V_85 ) ;
V_13 = F_39 ( V_10 , V_78 , 0 , V_86 ,
0 , 0x0000 , & V_73 ) ;
if ( V_13 ) {
F_40 ( V_9 , L_1 ) ;
goto V_87;
}
V_13 = F_41 ( V_73 , V_88 ) ;
if ( V_13 ) {
F_40 ( V_9 , L_2 , V_13 ) ;
goto V_89;
}
V_13 = F_42 ( V_73 ) ;
if ( V_13 ) {
F_40 ( V_9 , L_3 , V_13 ) ;
goto V_90;
}
V_28 = V_91 ? NULL : V_9 -> V_29 ;
if ( V_28 && V_12 -> V_2 . V_21 >= V_22 ) {
V_13 = F_43 ( V_73 , V_9 -> V_19 . V_92 ,
& V_6 -> V_71 . V_93 ) ;
if ( V_13 ) {
F_40 ( V_9 , L_4 , V_13 ) ;
V_28 = NULL ;
}
}
F_44 ( & V_10 -> V_94 ) ;
V_2 = F_45 ( 0 , & V_77 -> V_10 ) ;
if ( ! V_2 ) {
V_13 = - V_95 ;
goto V_96;
}
V_13 = F_46 ( & V_2 -> V_97 , 256 , 0 ) ;
if ( V_13 ) {
V_13 = - V_95 ;
F_47 ( V_2 ) ;
goto V_96;
}
V_2 -> V_7 = V_6 ;
F_48 ( V_10 , & V_6 -> V_71 , & V_75 , V_73 ) ;
V_71 = & V_6 -> V_71 ;
V_69 = & V_71 -> V_98 ;
V_6 -> V_33 . V_69 = V_69 ;
V_6 -> V_33 . V_34 = V_2 ;
strcpy ( V_2 -> V_99 . V_100 , L_5 ) ;
if ( ! V_28 )
V_2 -> V_17 = V_101 | V_18 ;
else
V_2 -> V_17 = V_101 | V_102 |
V_103 |
V_104 ;
V_2 -> V_17 |= V_105 ;
V_2 -> V_42 = & V_106 ;
V_2 -> V_99 . V_107 = V_73 -> V_108 . V_109 . V_110 . V_98 +
V_73 -> V_108 . V_109 . V_110 . V_111 ;
V_2 -> V_99 . V_112 = V_78 ;
V_2 -> V_113 = F_49 ( V_71 -> V_73 ) ;
V_2 -> V_114 = V_78 ;
F_50 ( V_2 , V_69 -> V_81 [ 0 ] , V_69 -> V_115 ) ;
F_51 ( V_2 , & V_6 -> V_33 , V_67 -> V_116 , V_67 -> V_117 ) ;
F_7 ( & V_10 -> V_94 ) ;
if ( V_28 )
F_28 ( V_10 ) ;
F_34 ( V_10 , V_6 ) ;
F_52 ( V_9 , L_6 ,
V_71 -> V_98 . V_58 , V_71 -> V_98 . V_61 ,
V_73 -> V_108 . V_111 , V_73 ) ;
F_53 ( V_10 -> V_77 , V_2 ) ;
return 0 ;
V_96:
F_7 ( & V_10 -> V_94 ) ;
if ( V_28 )
F_54 ( V_73 , & V_6 -> V_71 . V_93 ) ;
F_55 ( V_73 ) ;
V_90:
F_56 ( V_73 ) ;
V_89:
F_57 ( NULL , & V_73 ) ;
V_87:
return V_13 ;
}
void
F_58 ( struct V_31 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( V_9 -> V_6 )
F_59 ( & V_9 -> V_6 -> V_33 ) ;
}
static int
F_60 ( struct V_31 * V_10 , struct V_5 * V_6 )
{
struct V_70 * V_71 = & V_6 -> V_71 ;
struct V_1 * V_2 ;
if ( V_6 -> V_33 . V_34 ) {
V_2 = V_6 -> V_33 . V_34 ;
F_61 ( V_2 ) ;
if ( V_2 -> V_97 . V_118 )
F_62 ( & V_2 -> V_97 ) ;
F_47 ( V_2 ) ;
}
if ( V_71 -> V_73 ) {
F_55 ( V_71 -> V_73 ) ;
F_54 ( V_71 -> V_73 , & V_71 -> V_93 ) ;
F_56 ( V_71 -> V_73 ) ;
F_63 ( & V_71 -> V_73 -> V_119 ) ;
V_71 -> V_73 = NULL ;
}
F_64 ( & V_6 -> V_33 ) ;
F_65 ( & V_71 -> V_98 ) ;
F_66 ( & V_71 -> V_98 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
F_40 ( V_9 , L_7 ) ;
V_2 -> V_17 |= V_18 ;
}
static void
F_67 ( struct V_120 * V_121 )
{
struct V_5 * V_6 = F_36 ( V_121 , F_68 ( * V_6 ) , V_121 ) ;
F_25 () ;
F_23 ( V_6 -> V_10 ) ;
F_34 ( V_6 -> V_10 , V_6 ) ;
F_69 ( V_6 -> V_33 . V_34 , V_15 ) ;
F_26 () ;
}
int
F_70 ( struct V_31 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_5 * V_6 ;
int V_122 ;
int V_13 ;
if ( ! V_10 -> V_123 . V_124 ||
( V_10 -> V_77 -> V_125 >> 8 ) != V_126 )
return 0 ;
V_6 = F_71 ( sizeof( struct V_5 ) , V_127 ) ;
if ( ! V_6 )
return - V_95 ;
F_72 ( & V_6 -> V_121 , F_67 ) ;
V_6 -> V_10 = V_10 ;
V_9 -> V_6 = V_6 ;
F_73 ( V_10 , & V_6 -> V_33 , & V_128 ) ;
V_13 = F_74 ( V_10 , & V_6 -> V_33 ,
V_10 -> V_123 . V_124 , 4 ) ;
if ( V_13 ) {
F_75 ( V_6 ) ;
return V_13 ;
}
F_76 ( & V_6 -> V_33 ) ;
if ( V_9 -> V_12 . V_2 . V_129 <= 32 * 1024 * 1024 )
V_122 = 8 ;
else
if ( V_9 -> V_12 . V_2 . V_129 <= 64 * 1024 * 1024 )
V_122 = 16 ;
else
V_122 = 32 ;
F_77 ( V_10 ) ;
F_78 ( & V_6 -> V_33 , V_122 ) ;
return 0 ;
}
void
F_79 ( struct V_31 * V_10 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( ! V_9 -> V_6 )
return;
F_24 ( V_10 ) ;
F_60 ( V_10 , V_9 -> V_6 ) ;
F_75 ( V_9 -> V_6 ) ;
V_9 -> V_6 = NULL ;
}
void
F_80 ( struct V_31 * V_10 , int V_14 )
{
struct V_8 * V_9 = V_8 ( V_10 ) ;
if ( V_9 -> V_6 ) {
if ( V_14 == V_15 ) {
F_81 ( & V_9 -> V_6 -> V_121 ) ;
return;
}
F_82 ( & V_9 -> V_6 -> V_121 ) ;
F_25 () ;
F_69 ( V_9 -> V_6 -> V_33 . V_34 , V_14 ) ;
F_22 ( V_10 ) ;
F_26 () ;
}
}
