static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_9 ;
int V_10 = 0 ;
F_3 ( F_2 ( V_4 ) , L_1 ,
V_2 -> V_11 . V_12 . V_13 ) ;
F_4 ( & V_6 -> V_14 ) ;
F_5 (neigh, tmp, &mcast->neigh_list, list) {
if ( V_8 -> V_15 )
F_6 ( V_8 -> V_15 ) ;
F_7 ( V_4 , V_8 ) ;
}
F_8 ( & V_6 -> V_14 ) ;
if ( V_2 -> V_15 )
F_6 ( V_2 -> V_15 ) ;
while ( ! F_9 ( & V_2 -> V_16 ) ) {
++ V_10 ;
F_10 ( F_11 ( & V_2 -> V_16 ) ) ;
}
F_12 ( V_4 ) ;
V_4 -> V_17 . V_10 += V_10 ;
F_13 ( V_4 ) ;
F_14 ( V_2 ) ;
}
static struct V_1 * F_15 ( struct V_3 * V_4 ,
int V_18 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( sizeof *V_2 , V_18 ? V_19 : V_20 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = V_4 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = 1 ;
F_17 ( & V_2 -> V_24 ) ;
F_17 ( & V_2 -> V_25 ) ;
F_18 ( & V_2 -> V_16 ) ;
return V_2 ;
}
static struct V_1 * F_19 ( struct V_3 * V_4 , void * V_12 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_26 * V_27 = V_6 -> V_28 . V_26 ;
while ( V_27 ) {
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_20 ( V_27 , struct V_1 , V_26 ) ;
V_29 = memcmp ( V_12 , V_2 -> V_11 . V_12 . V_13 ,
sizeof ( union V_30 ) ) ;
if ( V_29 < 0 )
V_27 = V_27 -> V_31 ;
else if ( V_29 > 0 )
V_27 = V_27 -> V_32 ;
else
return V_2 ;
}
return NULL ;
}
static int F_21 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_26 * * V_27 = & V_6 -> V_28 . V_26 , * V_33 = NULL ;
while ( * V_27 ) {
struct V_1 * V_34 ;
int V_29 ;
V_33 = * V_27 ;
V_34 = F_20 ( V_33 , struct V_1 , V_26 ) ;
V_29 = memcmp ( V_2 -> V_11 . V_12 . V_13 , V_34 -> V_11 . V_12 . V_13 ,
sizeof ( union V_30 ) ) ;
if ( V_29 < 0 )
V_27 = & V_33 -> V_31 ;
else if ( V_29 > 0 )
V_27 = & V_33 -> V_32 ;
else
return - V_35 ;
}
F_22 ( & V_2 -> V_26 , V_33 , V_27 ) ;
F_23 ( & V_2 -> V_26 , & V_6 -> V_28 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_36 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_37 * V_15 ;
int V_29 ;
int V_38 = 0 ;
V_2 -> V_11 = * V_11 ;
if ( ! memcmp ( V_2 -> V_11 . V_12 . V_13 , V_6 -> V_4 -> V_39 + 4 ,
sizeof ( union V_30 ) ) ) {
F_4 ( & V_6 -> V_14 ) ;
if ( ! V_6 -> V_39 ) {
F_8 ( & V_6 -> V_14 ) ;
return - V_40 ;
}
V_6 -> V_41 = F_25 ( V_6 -> V_39 -> V_11 . V_41 ) ;
F_8 ( & V_6 -> V_14 ) ;
V_6 -> V_42 . V_43 . V_44 . V_45 = V_6 -> V_41 ;
V_38 = 1 ;
}
if ( ! F_26 ( V_46 , & V_2 -> V_47 ) ) {
if ( F_27 ( V_48 , & V_2 -> V_47 ) ) {
F_28 ( V_6 , L_2 ,
V_2 -> V_11 . V_12 . V_13 ) ;
return 0 ;
}
V_29 = F_29 ( V_4 , F_30 ( V_2 -> V_11 . V_49 ) ,
& V_2 -> V_11 . V_12 , V_38 ) ;
if ( V_29 < 0 ) {
F_28 ( V_6 , L_3 ,
V_2 -> V_11 . V_12 . V_13 ) ;
F_31 ( V_48 , & V_2 -> V_47 ) ;
return V_29 ;
}
}
{
struct V_50 V_51 = {
. V_52 = F_30 ( V_2 -> V_11 . V_49 ) ,
. V_53 = V_6 -> V_54 ,
. V_55 = V_2 -> V_11 . V_55 ,
. V_56 = V_57 ,
. V_58 = V_2 -> V_11 . V_59 ,
. V_60 = {
. V_61 = F_25 ( V_2 -> V_11 . V_61 ) ,
. V_62 = V_2 -> V_11 . V_62 ,
. V_63 = 0 ,
. V_64 = V_2 -> V_11 . V_64
}
} ;
V_51 . V_60 . V_65 = V_2 -> V_11 . V_12 ;
V_15 = F_32 ( V_4 , V_6 -> V_66 , & V_51 ) ;
if ( ! V_15 ) {
F_28 ( V_6 , L_4 ) ;
} else {
F_4 ( & V_6 -> V_14 ) ;
V_2 -> V_15 = V_15 ;
F_8 ( & V_6 -> V_14 ) ;
F_3 ( V_6 , L_5 ,
V_2 -> V_11 . V_12 . V_13 ,
V_2 -> V_15 -> V_15 ,
F_30 ( V_2 -> V_11 . V_49 ) ,
V_2 -> V_11 . V_55 ) ;
}
}
F_12 ( V_4 ) ;
while ( ! F_9 ( & V_2 -> V_16 ) ) {
struct V_67 * V_68 = F_11 ( & V_2 -> V_16 ) ;
struct V_69 * V_70 = F_33 ( V_68 ) ;
struct V_71 * V_27 = NULL ;
F_13 ( V_4 ) ;
V_68 -> V_4 = V_4 ;
if ( V_70 )
V_27 = F_34 ( V_70 ) ;
if ( ! V_70 || ! V_27 ) {
F_35 ( V_68 , sizeof ( struct V_72 ) ) ;
}
if ( F_36 ( V_68 ) )
F_28 ( V_6 , L_6 ) ;
F_12 ( V_4 ) ;
}
F_13 ( V_4 ) ;
return 0 ;
}
static int
F_37 ( int V_73 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_76 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_73 == - V_77 )
return 0 ;
if ( ! V_73 )
V_73 = F_24 ( V_2 , & V_75 -> V_78 ) ;
if ( V_73 ) {
if ( V_2 -> V_79 ++ < 20 )
F_3 ( F_2 ( V_4 ) , L_7 ,
V_2 -> V_11 . V_12 . V_13 , V_73 ) ;
F_12 ( V_4 ) ;
while ( ! F_9 ( & V_2 -> V_16 ) ) {
++ V_4 -> V_17 . V_10 ;
F_10 ( F_11 ( & V_2 -> V_16 ) ) ;
}
F_13 ( V_4 ) ;
V_73 = F_38 ( V_80 ,
& V_2 -> V_47 ) ;
}
return V_73 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_36 V_78 = {
#if 0
.join_state = 4
#else
. V_81 = 1
#endif
} ;
int V_29 = 0 ;
if ( ! F_26 ( V_82 , & V_6 -> V_47 ) ) {
F_3 ( V_6 , L_8 ) ;
return - V_83 ;
}
if ( F_27 ( V_80 , & V_2 -> V_47 ) ) {
F_3 ( V_6 , L_9 ) ;
return - V_84 ;
}
V_78 . V_12 = V_2 -> V_11 . V_12 ;
V_78 . V_85 = V_6 -> V_86 ;
V_78 . V_87 = F_40 ( V_6 -> V_87 ) ;
V_2 -> V_88 = F_41 ( & V_89 , V_6 -> V_90 ,
V_6 -> V_54 , & V_78 ,
V_91 |
V_92 |
V_93 |
V_94 ,
V_20 ,
F_37 ,
V_2 ) ;
if ( F_42 ( V_2 -> V_88 ) ) {
V_29 = F_43 ( V_2 -> V_88 ) ;
F_31 ( V_80 , & V_2 -> V_47 ) ;
F_28 ( V_6 , L_10 ,
V_29 ) ;
} else {
F_3 ( V_6 , L_11 ,
V_2 -> V_11 . V_12 . V_13 ) ;
}
return V_29 ;
}
void F_44 ( struct V_95 * V_96 )
{
struct V_5 * V_6 = F_45 ( V_96 , struct V_5 ,
V_97 ) ;
struct V_98 V_99 ;
if ( F_46 ( V_6 -> V_90 , V_6 -> V_54 , & V_99 ) ||
V_99 . V_100 != V_101 ) {
F_47 ( V_6 , L_12 ) ;
return;
}
F_48 () ;
F_49 ( V_6 -> V_4 ) ;
F_50 () ;
}
static int F_51 ( int V_73 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_76 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( V_6 , L_13 ,
V_2 -> V_11 . V_12 . V_13 , V_73 ) ;
if ( V_73 == - V_77 )
return 0 ;
if ( ! V_73 )
V_73 = F_24 ( V_2 , & V_75 -> V_78 ) ;
if ( ! V_73 ) {
V_2 -> V_23 = 1 ;
F_52 ( & V_102 ) ;
if ( F_26 ( V_103 , & V_6 -> V_47 ) )
F_53 ( V_104 ,
& V_6 -> V_105 , 0 ) ;
F_54 ( & V_102 ) ;
if ( V_2 == V_6 -> V_39 )
F_55 ( V_104 , & V_6 -> V_97 ) ;
return 0 ;
}
if ( V_2 -> V_79 ++ < 20 ) {
if ( V_73 == - V_106 || V_73 == - V_40 ) {
F_3 ( V_6 , L_7 ,
V_2 -> V_11 . V_12 . V_13 , V_73 ) ;
} else {
F_28 ( V_6 , L_7 ,
V_2 -> V_11 . V_12 . V_13 , V_73 ) ;
}
}
V_2 -> V_23 *= 2 ;
if ( V_2 -> V_23 > V_107 )
V_2 -> V_23 = V_107 ;
V_73 = F_38 ( V_80 , & V_2 -> V_47 ) ;
F_52 ( & V_102 ) ;
F_4 ( & V_6 -> V_14 ) ;
if ( F_26 ( V_103 , & V_6 -> V_47 ) )
F_53 ( V_104 , & V_6 -> V_105 ,
V_2 -> V_23 * V_108 ) ;
F_8 ( & V_6 -> V_14 ) ;
F_54 ( & V_102 ) ;
return V_73 ;
}
static void F_56 ( struct V_3 * V_4 , struct V_1 * V_2 ,
int V_109 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_36 V_78 = {
. V_81 = 1
} ;
T_1 V_110 ;
int V_29 = 0 ;
F_3 ( V_6 , L_14 , V_2 -> V_11 . V_12 . V_13 ) ;
V_78 . V_12 = V_2 -> V_11 . V_12 ;
V_78 . V_85 = V_6 -> V_86 ;
V_78 . V_87 = F_40 ( V_6 -> V_87 ) ;
V_110 =
V_91 |
V_92 |
V_93 |
V_94 ;
if ( V_109 ) {
V_110 |=
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 ;
V_78 . V_41 = V_6 -> V_39 -> V_11 . V_41 ;
V_78 . V_120 = V_121 ;
V_78 . V_122 = V_6 -> V_39 -> V_11 . V_122 ;
V_78 . V_64 = V_6 -> V_39 -> V_11 . V_64 ;
V_78 . V_123 = V_121 ;
V_78 . V_59 = V_6 -> V_39 -> V_11 . V_59 ;
V_78 . V_55 = V_6 -> V_39 -> V_11 . V_55 ;
V_78 . V_61 = V_6 -> V_39 -> V_11 . V_61 ;
V_78 . V_62 = V_6 -> V_39 -> V_11 . V_62 ;
}
F_57 ( V_80 , & V_2 -> V_47 ) ;
V_2 -> V_88 = F_41 ( & V_89 , V_6 -> V_90 , V_6 -> V_54 ,
& V_78 , V_110 , V_19 ,
F_51 , V_2 ) ;
if ( F_42 ( V_2 -> V_88 ) ) {
F_31 ( V_80 , & V_2 -> V_47 ) ;
V_29 = F_43 ( V_2 -> V_88 ) ;
F_28 ( V_6 , L_15 , V_29 ) ;
V_2 -> V_23 *= 2 ;
if ( V_2 -> V_23 > V_107 )
V_2 -> V_23 = V_107 ;
F_52 ( & V_102 ) ;
if ( F_26 ( V_103 , & V_6 -> V_47 ) )
F_53 ( V_104 ,
& V_6 -> V_105 ,
V_2 -> V_23 * V_108 ) ;
F_54 ( & V_102 ) ;
}
}
void F_58 ( struct V_95 * V_96 )
{
struct V_5 * V_6 =
F_45 ( V_96 , struct V_5 , V_105 . V_96 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
if ( ! F_26 ( V_103 , & V_6 -> V_47 ) )
return;
if ( F_59 ( V_6 -> V_90 , V_6 -> V_54 , 0 , & V_6 -> V_86 ) )
F_28 ( V_6 , L_16 ) ;
else
memcpy ( V_6 -> V_4 -> V_124 + 4 , V_6 -> V_86 . V_13 , sizeof ( union V_30 ) ) ;
{
struct V_98 V_99 ;
if ( ! F_46 ( V_6 -> V_90 , V_6 -> V_54 , & V_99 ) )
V_6 -> V_125 = V_99 . V_126 ;
else
F_28 ( V_6 , L_17 ) ;
}
if ( ! V_6 -> V_39 ) {
struct V_1 * V_39 ;
if ( ! F_26 ( V_127 , & V_6 -> V_47 ) )
return;
V_39 = F_15 ( V_4 , 1 ) ;
if ( ! V_39 ) {
F_28 ( V_6 , L_18 ) ;
F_52 ( & V_102 ) ;
if ( F_26 ( V_103 , & V_6 -> V_47 ) )
F_53 ( V_104 ,
& V_6 -> V_105 , V_108 ) ;
F_54 ( & V_102 ) ;
return;
}
F_4 ( & V_6 -> V_14 ) ;
memcpy ( V_39 -> V_11 . V_12 . V_13 , V_6 -> V_4 -> V_39 + 4 ,
sizeof ( union V_30 ) ) ;
V_6 -> V_39 = V_39 ;
F_21 ( V_4 , V_6 -> V_39 ) ;
F_8 ( & V_6 -> V_14 ) ;
}
if ( ! F_26 ( V_48 , & V_6 -> V_39 -> V_47 ) ) {
if ( ! F_26 ( V_80 , & V_6 -> V_39 -> V_47 ) )
F_56 ( V_4 , V_6 -> V_39 , 0 ) ;
return;
}
while ( 1 ) {
struct V_1 * V_2 = NULL ;
F_4 ( & V_6 -> V_14 ) ;
F_60 (mcast, &priv->multicast_list, list) {
if ( ! F_26 ( V_46 , & V_2 -> V_47 )
&& ! F_26 ( V_80 , & V_2 -> V_47 )
&& ! F_26 ( V_48 , & V_2 -> V_47 ) ) {
break;
}
}
F_8 ( & V_6 -> V_14 ) ;
if ( & V_2 -> V_24 == & V_6 -> V_128 ) {
break;
}
F_56 ( V_4 , V_2 , 1 ) ;
return;
}
V_6 -> V_129 = F_61 ( F_62 ( V_6 -> V_39 -> V_11 . V_122 ) ) ;
if ( ! F_63 ( V_4 ) ) {
F_48 () ;
F_64 ( V_4 , F_65 ( V_6 -> V_129 , V_6 -> V_130 ) ) ;
F_50 () ;
}
F_3 ( V_6 , L_19 ) ;
F_31 ( V_103 , & V_6 -> V_47 ) ;
}
int F_66 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( V_6 , L_20 ) ;
F_52 ( & V_102 ) ;
if ( ! F_27 ( V_103 , & V_6 -> V_47 ) )
F_53 ( V_104 , & V_6 -> V_105 , 0 ) ;
F_54 ( & V_102 ) ;
return 0 ;
}
int F_67 ( struct V_3 * V_4 , int V_131 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( V_6 , L_21 ) ;
F_52 ( & V_102 ) ;
F_31 ( V_103 , & V_6 -> V_47 ) ;
F_68 ( & V_6 -> V_105 ) ;
F_54 ( & V_102 ) ;
if ( V_131 )
F_69 ( V_104 ) ;
return 0 ;
}
static int F_70 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_29 = 0 ;
if ( F_38 ( V_80 , & V_2 -> V_47 ) )
F_71 ( V_2 -> V_88 ) ;
if ( F_38 ( V_48 , & V_2 -> V_47 ) ) {
F_3 ( V_6 , L_22 ,
V_2 -> V_11 . V_12 . V_13 ) ;
V_29 = F_72 ( V_6 -> V_132 , & V_2 -> V_11 . V_12 ,
F_30 ( V_2 -> V_11 . V_49 ) ) ;
if ( V_29 )
F_28 ( V_6 , L_23 , V_29 ) ;
}
return 0 ;
}
void F_73 ( struct V_3 * V_4 , void * V_12 , struct V_67 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 ;
unsigned long V_47 ;
F_74 ( & V_6 -> V_14 , V_47 ) ;
if ( ! F_26 ( V_82 , & V_6 -> V_47 ) ||
! V_6 -> V_39 ||
! F_26 ( V_48 , & V_6 -> V_39 -> V_47 ) ) {
++ V_4 -> V_17 . V_10 ;
F_10 ( V_68 ) ;
goto V_133;
}
V_2 = F_19 ( V_4 , V_12 ) ;
if ( ! V_2 ) {
F_3 ( V_6 , L_24 ,
V_12 ) ;
V_2 = F_15 ( V_4 , 0 ) ;
if ( ! V_2 ) {
F_28 ( V_6 , L_25
L_26 ) ;
++ V_4 -> V_17 . V_10 ;
F_10 ( V_68 ) ;
goto V_134;
}
F_57 ( V_46 , & V_2 -> V_47 ) ;
memcpy ( V_2 -> V_11 . V_12 . V_13 , V_12 , sizeof ( union V_30 ) ) ;
F_21 ( V_4 , V_2 ) ;
F_75 ( & V_2 -> V_24 , & V_6 -> V_128 ) ;
}
if ( ! V_2 -> V_15 ) {
if ( F_76 ( & V_2 -> V_16 ) < V_135 )
F_77 ( & V_2 -> V_16 , V_68 ) ;
else {
++ V_4 -> V_17 . V_10 ;
F_10 ( V_68 ) ;
}
if ( F_26 ( V_80 , & V_2 -> V_47 ) )
F_3 ( V_6 , L_27
L_28 ) ;
else if ( F_26 ( V_46 , & V_2 -> V_47 ) )
F_39 ( V_2 ) ;
V_2 = NULL ;
}
V_134:
if ( V_2 && V_2 -> V_15 ) {
struct V_69 * V_70 = F_33 ( V_68 ) ;
struct V_71 * V_27 = NULL ;
if ( V_70 )
V_27 = F_34 ( V_70 ) ;
if ( V_27 && ! * F_78 ( V_27 ) ) {
struct V_7 * V_8 = F_79 ( V_27 ,
V_68 -> V_4 ) ;
if ( V_8 ) {
F_80 ( & V_2 -> V_15 -> V_136 ) ;
V_8 -> V_15 = V_2 -> V_15 ;
F_75 ( & V_8 -> V_24 , & V_2 -> V_25 ) ;
}
}
F_81 ( & V_6 -> V_14 , V_47 ) ;
F_82 ( V_4 , V_68 , V_2 -> V_15 , V_137 ) ;
return;
}
V_133:
F_81 ( & V_6 -> V_14 , V_47 ) ;
}
void F_83 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_84 ( V_138 ) ;
struct V_1 * V_2 , * V_34 ;
unsigned long V_47 ;
F_3 ( V_6 , L_29 ) ;
F_74 ( & V_6 -> V_14 , V_47 ) ;
F_5 (mcast, tmcast, &priv->multicast_list, list) {
F_85 ( & V_2 -> V_24 ) ;
F_86 ( & V_2 -> V_26 , & V_6 -> V_28 ) ;
F_75 ( & V_2 -> V_24 , & V_138 ) ;
}
if ( V_6 -> V_39 ) {
F_86 ( & V_6 -> V_39 -> V_26 , & V_6 -> V_28 ) ;
F_75 ( & V_6 -> V_39 -> V_24 , & V_138 ) ;
V_6 -> V_39 = NULL ;
}
F_81 ( & V_6 -> V_14 , V_47 ) ;
F_5 (mcast, tmcast, &remove_list, list) {
F_70 ( V_4 , V_2 ) ;
F_1 ( V_2 ) ;
}
}
static int F_87 ( const T_2 * V_139 , const T_2 * V_39 )
{
if ( memcmp ( V_139 , V_39 , 6 ) )
return 0 ;
if ( memcmp ( V_139 + 7 , V_39 + 7 , 3 ) )
return 0 ;
return 1 ;
}
void F_88 ( struct V_95 * V_96 )
{
struct V_5 * V_6 =
F_45 ( V_96 , struct V_5 , V_140 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_141 * V_142 ;
struct V_1 * V_2 , * V_34 ;
F_84 ( V_138 ) ;
unsigned long V_47 ;
struct V_36 V_78 ;
F_3 ( V_6 , L_30 ) ;
F_67 ( V_4 , 0 ) ;
F_89 ( V_47 ) ;
F_90 ( V_4 ) ;
F_91 ( & V_6 -> V_14 ) ;
F_60 (mcast, &priv->multicast_list, list)
F_31 ( V_143 , & V_2 -> V_47 ) ;
F_92 (ha, dev) {
union V_30 V_12 ;
if ( ! F_87 ( V_142 -> V_139 , V_4 -> V_39 ) )
continue;
memcpy ( V_12 . V_13 , V_142 -> V_139 + 4 , sizeof V_12 ) ;
V_2 = F_19 ( V_4 , & V_12 ) ;
if ( ! V_2 || F_26 ( V_46 , & V_2 -> V_47 ) ) {
struct V_1 * V_144 ;
if ( F_26 ( V_145 , & V_6 -> V_47 ) &&
! F_93 ( V_6 -> V_90 , V_6 -> V_54 , & V_12 , & V_78 ) ) {
F_3 ( V_6 , L_31 ,
V_12 . V_13 ) ;
continue;
}
F_3 ( V_6 , L_32 ,
V_12 . V_13 ) ;
V_144 = F_15 ( V_4 , 0 ) ;
if ( ! V_144 ) {
F_28 ( V_6 , L_33 ) ;
continue;
}
F_57 ( V_143 , & V_144 -> V_47 ) ;
V_144 -> V_11 . V_12 = V_12 ;
if ( V_2 ) {
F_94 ( & V_2 -> V_24 , & V_138 ) ;
F_95 ( & V_2 -> V_26 ,
& V_144 -> V_26 ,
& V_6 -> V_28 ) ;
} else
F_21 ( V_4 , V_144 ) ;
F_75 ( & V_144 -> V_24 , & V_6 -> V_128 ) ;
}
if ( V_2 )
F_57 ( V_143 , & V_2 -> V_47 ) ;
}
F_5 (mcast, tmcast, &priv->multicast_list, list) {
if ( ! F_26 ( V_143 , & V_2 -> V_47 ) &&
! F_26 ( V_46 , & V_2 -> V_47 ) ) {
F_3 ( V_6 , L_1 ,
V_2 -> V_11 . V_12 . V_13 ) ;
F_86 ( & V_2 -> V_26 , & V_6 -> V_28 ) ;
F_94 ( & V_2 -> V_24 , & V_138 ) ;
}
}
F_96 ( & V_6 -> V_14 ) ;
F_97 ( V_4 ) ;
F_98 ( V_47 ) ;
F_5 (mcast, tmcast, &remove_list, list) {
F_70 ( V_2 -> V_4 , V_2 ) ;
F_1 ( V_2 ) ;
}
if ( F_26 ( V_127 , & V_6 -> V_47 ) )
F_66 ( V_4 ) ;
}
struct V_146 * F_99 ( struct V_3 * V_4 )
{
struct V_146 * V_147 ;
V_147 = F_100 ( sizeof *V_147 , V_19 ) ;
if ( ! V_147 )
return NULL ;
V_147 -> V_4 = V_4 ;
memset ( V_147 -> V_12 . V_13 , 0 , 16 ) ;
if ( F_101 ( V_147 ) ) {
F_14 ( V_147 ) ;
return NULL ;
}
return V_147 ;
}
int F_101 ( struct V_146 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_147 -> V_4 ) ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
int V_29 = 1 ;
F_4 ( & V_6 -> V_14 ) ;
V_27 = F_102 ( & V_6 -> V_28 ) ;
while ( V_27 ) {
V_2 = F_20 ( V_27 , struct V_1 , V_26 ) ;
if ( memcmp ( V_147 -> V_12 . V_13 , V_2 -> V_11 . V_12 . V_13 ,
sizeof ( union V_30 ) ) < 0 ) {
V_147 -> V_12 = V_2 -> V_11 . V_12 ;
V_147 -> V_21 = V_2 -> V_21 ;
V_147 -> V_148 = F_76 ( & V_2 -> V_16 ) ;
V_147 -> V_149 = ! ! V_2 -> V_15 ;
V_147 -> V_150 = ! ! ( V_2 -> V_47 & ( 1 << V_46 ) ) ;
V_29 = 0 ;
break;
}
V_27 = F_103 ( V_27 ) ;
}
F_8 ( & V_6 -> V_14 ) ;
return V_29 ;
}
void F_104 ( struct V_146 * V_147 ,
union V_30 * V_12 ,
unsigned long * V_21 ,
unsigned int * V_148 ,
unsigned int * V_149 ,
unsigned int * V_150 )
{
* V_12 = V_147 -> V_12 ;
* V_21 = V_147 -> V_21 ;
* V_148 = V_147 -> V_148 ;
* V_149 = V_147 -> V_149 ;
* V_150 = V_147 -> V_150 ;
}
