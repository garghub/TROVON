static void
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_13 ;
if ( V_2 -> V_14 != V_15 )
return;
V_13 = - V_16 ;
if ( ! F_2 () && ! ( V_2 -> V_17 & V_18 ) &&
F_3 ( & V_11 -> V_19 -> V_20 ) ) {
if ( V_11 -> V_21 < V_22 )
V_13 = F_4 ( V_2 , V_4 ) ;
else
if ( V_11 -> V_21 < V_23 )
V_13 = F_5 ( V_2 , V_4 ) ;
else
V_13 = F_6 ( V_2 , V_4 ) ;
F_7 ( & V_11 -> V_19 -> V_20 ) ;
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
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_13 ;
if ( V_2 -> V_14 != V_15 )
return;
V_13 = - V_16 ;
if ( ! F_2 () && ! ( V_2 -> V_17 & V_18 ) &&
F_3 ( & V_11 -> V_19 -> V_20 ) ) {
if ( V_11 -> V_21 < V_22 )
V_13 = F_11 ( V_2 , V_25 ) ;
else
if ( V_11 -> V_21 < V_23 )
V_13 = F_12 ( V_2 , V_25 ) ;
else
V_13 = F_13 ( V_2 , V_25 ) ;
F_7 ( & V_11 -> V_19 -> V_20 ) ;
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
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_13 ;
if ( V_2 -> V_14 != V_15 )
return;
V_13 = - V_16 ;
if ( ! F_2 () && ! ( V_2 -> V_17 & V_18 ) &&
F_3 ( & V_11 -> V_19 -> V_20 ) ) {
if ( V_11 -> V_21 < V_22 )
V_13 = F_16 ( V_2 , V_25 ) ;
else
if ( V_11 -> V_21 < V_23 )
V_13 = F_17 ( V_2 , V_25 ) ;
else
V_13 = F_18 ( V_2 , V_25 ) ;
F_7 ( & V_11 -> V_19 -> V_20 ) ;
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
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_27 * V_28 = V_11 -> V_19 ;
int V_13 , V_29 ;
if ( ! V_28 || ! V_28 -> V_30 || F_2 () ||
V_2 -> V_14 != V_15 ||
V_2 -> V_17 & V_18 )
return 0 ;
if ( ! F_3 ( & V_28 -> V_20 ) )
return 0 ;
V_13 = F_21 ( V_28 , 4 ) ;
if ( V_13 ) {
F_7 ( & V_28 -> V_20 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
if ( V_11 -> V_21 >= V_23 ) {
F_22 ( V_28 , 2 , V_31 , 0x010c , 1 ) ;
F_23 ( V_28 , 0 ) ;
F_22 ( V_28 , 2 , V_31 , 0x0100 , 1 ) ;
F_23 ( V_28 , 0 ) ;
} else {
F_24 ( V_28 , 0 , 0x0104 , 1 ) ;
F_23 ( V_28 , 0 ) ;
F_24 ( V_28 , 0 , 0x0100 , 1 ) ;
F_23 ( V_28 , 0 ) ;
}
F_25 ( V_28 -> V_32 , V_28 -> V_33 / 4 + 3 , 0xffffffff ) ;
F_26 ( V_28 ) ;
F_7 ( & V_28 -> V_20 ) ;
V_13 = - V_34 ;
for ( V_29 = 0 ; V_29 < 100000 ; V_29 ++ ) {
if ( ! F_27 ( V_28 -> V_32 , V_28 -> V_33 / 4 + 3 ) ) {
V_13 = 0 ;
break;
}
F_28 ( 1 ) ;
}
if ( V_13 ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_28 -> V_30 = false ;
return 0 ;
}
static void F_29 ( struct V_35 * V_36 , T_1 V_37 , T_1 V_38 ,
T_1 V_39 , int V_40 )
{
struct V_41 * V_42 = V_41 ( V_36 ) ;
V_42 -> V_43 . V_44 [ V_40 ] = V_37 ;
V_42 -> V_43 . V_45 [ V_40 ] = V_38 ;
V_42 -> V_43 . V_46 [ V_40 ] = V_39 ;
}
static void F_30 ( struct V_35 * V_36 , T_1 * V_37 , T_1 * V_38 ,
T_1 * V_39 , int V_40 )
{
struct V_41 * V_42 = V_41 ( V_36 ) ;
* V_37 = V_42 -> V_43 . V_44 [ V_40 ] ;
* V_38 = V_42 -> V_43 . V_45 [ V_40 ] ;
* V_39 = V_42 -> V_43 . V_46 [ V_40 ] ;
}
static void
F_31 ( struct V_8 * V_9 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_47 . V_48 ;
struct V_3 V_4 ;
V_4 . V_49 = V_4 . V_50 = 0 ;
V_4 . V_51 = V_2 -> V_52 . V_53 ;
V_4 . V_54 = V_2 -> V_52 . V_55 ;
V_4 . V_56 = 0 ;
V_4 . V_57 = V_58 ;
V_2 -> V_59 -> V_3 ( V_2 , & V_4 ) ;
}
static int
F_32 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_2 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_27 * V_28 ;
struct V_66 * V_67 ;
struct V_68 V_69 ;
struct V_70 * V_71 = V_9 -> V_71 ;
struct V_72 * V_72 = & V_71 -> V_9 ;
int V_73 , V_13 ;
V_69 . V_51 = V_61 -> V_74 ;
V_69 . V_54 = V_61 -> V_75 ;
V_69 . V_76 = V_61 -> V_77 ;
V_69 . V_78 = V_69 . V_51 * ( V_69 . V_76 >> 3 ) ;
V_69 . V_78 = F_33 ( V_69 . V_78 , 256 ) ;
V_69 . V_79 = V_61 -> V_80 ;
V_73 = V_69 . V_78 * V_69 . V_54 ;
V_73 = F_33 ( V_73 , V_81 ) ;
V_13 = F_34 ( V_9 , V_73 , 0 , V_82 ,
0 , 0x0000 , & V_67 ) ;
if ( V_13 ) {
F_35 ( V_9 , L_1 ) ;
goto V_83;
}
V_13 = F_36 ( V_67 , V_84 ) ;
if ( V_13 ) {
F_35 ( V_9 , L_2 , V_13 ) ;
F_37 ( NULL , & V_67 ) ;
goto V_83;
}
V_13 = F_38 ( V_67 ) ;
if ( V_13 ) {
F_35 ( V_9 , L_3 , V_13 ) ;
F_39 ( V_67 ) ;
F_37 ( NULL , & V_67 ) ;
goto V_83;
}
V_28 = V_85 ? NULL : V_11 -> V_19 ;
if ( V_28 && V_11 -> V_21 >= V_22 ) {
V_13 = F_40 ( V_67 , V_28 -> V_86 , & V_6 -> V_65 . V_87 ) ;
if ( V_13 ) {
F_35 ( V_9 , L_4 , V_13 ) ;
V_28 = NULL ;
}
}
F_41 ( & V_9 -> V_88 ) ;
V_2 = F_42 ( 0 , V_72 ) ;
if ( ! V_2 ) {
V_13 = - V_89 ;
goto V_90;
}
V_13 = F_43 ( & V_2 -> V_91 , 256 , 0 ) ;
if ( V_13 ) {
V_13 = - V_89 ;
goto V_90;
}
V_2 -> V_7 = V_6 ;
F_44 ( V_9 , & V_6 -> V_65 , & V_69 , V_67 ) ;
V_65 = & V_6 -> V_65 ;
V_63 = & V_65 -> V_92 ;
V_6 -> V_47 . V_63 = V_63 ;
V_6 -> V_47 . V_48 = V_2 ;
strcpy ( V_2 -> V_93 . V_94 , L_5 ) ;
if ( V_85 )
V_2 -> V_17 = V_95 | V_18 ;
else
V_2 -> V_17 = V_95 | V_96 |
V_97 |
V_98 ;
V_2 -> V_17 |= V_99 ;
V_2 -> V_59 = & V_100 ;
V_2 -> V_93 . V_101 = V_67 -> V_102 . V_103 . V_104 . V_92 +
V_67 -> V_102 . V_103 . V_104 . V_105 ;
V_2 -> V_93 . V_106 = V_73 ;
V_2 -> V_107 = F_45 ( V_65 -> V_67 ) ;
V_2 -> V_108 = V_73 ;
F_46 ( V_2 , V_63 -> V_78 , V_63 -> V_79 ) ;
F_47 ( V_2 , & V_6 -> V_47 , V_61 -> V_109 , V_61 -> V_110 ) ;
V_2 -> V_111 = V_11 -> V_111 ;
if ( ! V_2 -> V_111 ) {
V_13 = - V_89 ;
goto V_90;
}
V_2 -> V_112 . V_73 = 64 * 1024 ;
V_2 -> V_112 . V_113 = 8 ;
V_2 -> V_112 . V_114 = 32 ;
V_2 -> V_112 . V_17 = V_115 ;
V_2 -> V_112 . V_116 = 1 ;
F_7 ( & V_9 -> V_88 ) ;
if ( V_11 -> V_19 && ! V_85 ) {
V_13 = - V_16 ;
if ( V_11 -> V_21 < V_22 )
V_13 = F_48 ( V_2 ) ;
else
if ( V_11 -> V_21 < V_23 )
V_13 = F_49 ( V_2 ) ;
else
V_13 = F_50 ( V_2 ) ;
if ( V_13 == 0 )
V_2 -> V_59 = & V_117 ;
}
F_31 ( V_9 , V_6 ) ;
F_51 ( V_9 , L_6 ,
V_65 -> V_92 . V_51 ,
V_65 -> V_92 . V_54 ,
V_67 -> V_102 . V_105 , V_67 ) ;
F_52 ( V_9 -> V_71 , V_2 ) ;
return 0 ;
V_90:
F_7 ( & V_9 -> V_88 ) ;
V_83:
return V_13 ;
}
static int
F_53 ( struct V_118 * V_47 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = (struct V_5 * ) V_47 ;
int V_119 = 0 ;
int V_13 ;
if ( ! V_47 -> V_63 ) {
V_13 = F_32 ( V_6 , V_61 ) ;
if ( V_13 )
return V_13 ;
V_119 = 1 ;
}
return V_119 ;
}
void
F_54 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
F_55 ( & V_11 -> V_6 -> V_47 ) ;
}
static int
F_56 ( struct V_8 * V_9 , struct V_5 * V_6 )
{
struct V_64 * V_65 = & V_6 -> V_65 ;
struct V_1 * V_2 ;
if ( V_6 -> V_47 . V_48 ) {
V_2 = V_6 -> V_47 . V_48 ;
F_57 ( V_2 ) ;
if ( V_2 -> V_91 . V_120 )
F_58 ( & V_2 -> V_91 ) ;
F_59 ( V_2 ) ;
}
if ( V_65 -> V_67 ) {
F_60 ( V_65 -> V_67 ) ;
F_61 ( V_65 -> V_67 , & V_65 -> V_87 ) ;
F_62 ( V_65 -> V_67 -> V_121 ) ;
V_65 -> V_67 = NULL ;
}
F_63 ( & V_6 -> V_47 ) ;
F_64 ( & V_65 -> V_92 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
F_35 ( V_9 , L_7 ) ;
V_2 -> V_17 |= V_18 ;
}
int F_65 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
int V_13 ;
V_6 = F_66 ( sizeof( struct V_5 ) , V_122 ) ;
if ( ! V_6 )
return - V_89 ;
V_6 -> V_9 = V_9 ;
V_11 -> V_6 = V_6 ;
V_6 -> V_47 . V_123 = & V_124 ;
V_13 = F_67 ( V_9 , & V_6 -> V_47 ,
F_68 ( V_9 ) ? 2 : 1 , 4 ) ;
if ( V_13 ) {
F_69 ( V_6 ) ;
return V_13 ;
}
F_70 ( & V_6 -> V_47 ) ;
F_71 ( & V_6 -> V_47 , 32 ) ;
return 0 ;
}
void F_72 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
if ( ! V_11 -> V_6 )
return;
F_56 ( V_9 , V_11 -> V_6 ) ;
F_69 ( V_11 -> V_6 ) ;
V_11 -> V_6 = NULL ;
}
void F_73 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_6 -> V_125 = V_11 -> V_6 -> V_47 . V_48 -> V_17 ;
V_11 -> V_6 -> V_47 . V_48 -> V_17 |= V_18 ;
}
void F_74 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_6 -> V_47 . V_48 -> V_17 = V_11 -> V_6 -> V_125 ;
}
void F_75 ( struct V_8 * V_9 , int V_14 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
F_76 ( V_11 -> V_6 -> V_47 . V_48 , V_14 ) ;
}
void F_77 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
F_31 ( V_9 , V_11 -> V_6 ) ;
}
