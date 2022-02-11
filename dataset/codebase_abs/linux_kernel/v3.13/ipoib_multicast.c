static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = 0 ;
F_2 ( F_3 ( V_4 ) , L_1 ,
V_2 -> V_6 . V_7 . V_8 ) ;
F_4 ( V_4 , V_2 -> V_6 . V_7 . V_8 ) ;
if ( V_2 -> V_9 )
F_5 ( V_2 -> V_9 ) ;
while ( ! F_6 ( & V_2 -> V_10 ) ) {
++ V_5 ;
F_7 ( F_8 ( & V_2 -> V_10 ) ) ;
}
F_9 ( V_4 ) ;
V_4 -> V_11 . V_5 += V_5 ;
F_10 ( V_4 ) ;
F_11 ( V_2 ) ;
}
static struct V_1 * F_12 ( struct V_3 * V_4 ,
int V_12 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( sizeof *V_2 , V_12 ? V_13 : V_14 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = 1 ;
F_14 ( & V_2 -> V_18 ) ;
F_14 ( & V_2 -> V_19 ) ;
F_15 ( & V_2 -> V_10 ) ;
return V_2 ;
}
static struct V_1 * F_16 ( struct V_3 * V_4 , void * V_7 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
struct V_22 * V_23 = V_21 -> V_24 . V_22 ;
while ( V_23 ) {
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_17 ( V_23 , struct V_1 , V_22 ) ;
V_25 = memcmp ( V_7 , V_2 -> V_6 . V_7 . V_8 ,
sizeof ( union V_26 ) ) ;
if ( V_25 < 0 )
V_23 = V_23 -> V_27 ;
else if ( V_25 > 0 )
V_23 = V_23 -> V_28 ;
else
return V_2 ;
}
return NULL ;
}
static int F_18 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
struct V_22 * * V_23 = & V_21 -> V_24 . V_22 , * V_29 = NULL ;
while ( * V_23 ) {
struct V_1 * V_30 ;
int V_25 ;
V_29 = * V_23 ;
V_30 = F_17 ( V_29 , struct V_1 , V_22 ) ;
V_25 = memcmp ( V_2 -> V_6 . V_7 . V_8 , V_30 -> V_6 . V_7 . V_8 ,
sizeof ( union V_26 ) ) ;
if ( V_25 < 0 )
V_23 = & V_29 -> V_27 ;
else if ( V_25 > 0 )
V_23 = & V_29 -> V_28 ;
else
return - V_31 ;
}
F_19 ( & V_2 -> V_22 , V_29 , V_23 ) ;
F_20 ( & V_2 -> V_22 , & V_21 -> V_24 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_32 * V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = F_3 ( V_4 ) ;
struct V_33 * V_9 ;
int V_25 ;
int V_34 = 0 ;
V_2 -> V_6 = * V_6 ;
if ( ! memcmp ( V_2 -> V_6 . V_7 . V_8 , V_21 -> V_4 -> V_35 + 4 ,
sizeof ( union V_26 ) ) ) {
F_22 ( & V_21 -> V_36 ) ;
if ( ! V_21 -> V_35 ) {
F_23 ( & V_21 -> V_36 ) ;
return - V_37 ;
}
V_21 -> V_38 = F_24 ( F_25 ( V_21 -> V_35 -> V_6 . V_39 ) ) ;
V_21 -> V_40 = F_26 ( V_21 -> V_35 -> V_6 . V_40 ) ;
F_23 ( & V_21 -> V_36 ) ;
V_21 -> V_41 . V_42 . V_43 . V_44 = V_21 -> V_40 ;
V_34 = 1 ;
if ( ! F_27 ( V_4 ) ) {
F_28 () ;
F_29 ( V_4 , F_30 ( V_21 -> V_38 , V_21 -> V_45 ) ) ;
F_31 () ;
}
}
if ( ! F_32 ( V_46 , & V_2 -> V_47 ) ) {
if ( F_33 ( V_48 , & V_2 -> V_47 ) ) {
F_34 ( V_21 , L_2 ,
V_2 -> V_6 . V_7 . V_8 ) ;
return 0 ;
}
V_25 = F_35 ( V_4 , F_36 ( V_2 -> V_6 . V_49 ) ,
& V_2 -> V_6 . V_7 , V_34 ) ;
if ( V_25 < 0 ) {
F_34 ( V_21 , L_3 ,
V_2 -> V_6 . V_7 . V_8 ) ;
F_37 ( V_48 , & V_2 -> V_47 ) ;
return V_25 ;
}
}
{
struct V_50 V_51 = {
. V_52 = F_36 ( V_2 -> V_6 . V_49 ) ,
. V_53 = V_21 -> V_54 ,
. V_55 = V_2 -> V_6 . V_55 ,
. V_56 = V_57 ,
. V_58 = V_2 -> V_6 . V_59 ,
. V_60 = {
. V_61 = F_26 ( V_2 -> V_6 . V_61 ) ,
. V_62 = V_2 -> V_6 . V_62 ,
. V_63 = 0 ,
. V_64 = V_2 -> V_6 . V_64
}
} ;
V_51 . V_60 . V_65 = V_2 -> V_6 . V_7 ;
V_9 = F_38 ( V_4 , V_21 -> V_66 , & V_51 ) ;
if ( F_39 ( V_9 ) ) {
F_34 ( V_21 , L_4 ,
- F_40 ( V_9 ) ) ;
return F_40 ( V_9 ) ;
} else {
F_22 ( & V_21 -> V_36 ) ;
V_2 -> V_9 = V_9 ;
F_23 ( & V_21 -> V_36 ) ;
F_2 ( V_21 , L_5 ,
V_2 -> V_6 . V_7 . V_8 ,
V_2 -> V_9 -> V_9 ,
F_36 ( V_2 -> V_6 . V_49 ) ,
V_2 -> V_6 . V_55 ) ;
}
}
F_9 ( V_4 ) ;
while ( ! F_6 ( & V_2 -> V_10 ) ) {
struct V_67 * V_68 = F_8 ( & V_2 -> V_10 ) ;
F_10 ( V_4 ) ;
V_68 -> V_4 = V_4 ;
if ( F_41 ( V_68 ) )
F_34 ( V_21 , L_6 ) ;
F_9 ( V_4 ) ;
}
F_10 ( V_4 ) ;
return 0 ;
}
static int
F_42 ( int V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_69 == - V_73 )
return 0 ;
if ( ! V_69 )
V_69 = F_21 ( V_2 , & V_71 -> V_74 ) ;
if ( V_69 ) {
if ( V_2 -> V_75 ++ < 20 )
F_2 ( F_3 ( V_4 ) , L_7 ,
V_2 -> V_6 . V_7 . V_8 , V_69 ) ;
F_9 ( V_4 ) ;
while ( ! F_6 ( & V_2 -> V_10 ) ) {
++ V_4 -> V_11 . V_5 ;
F_7 ( F_8 ( & V_2 -> V_10 ) ) ;
}
F_10 ( V_4 ) ;
V_69 = F_43 ( V_76 ,
& V_2 -> V_47 ) ;
}
return V_69 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = F_3 ( V_4 ) ;
struct V_32 V_74 = {
#if 0
.join_state = 4
#else
. V_77 = 1
#endif
} ;
int V_25 = 0 ;
if ( ! F_32 ( V_78 , & V_21 -> V_47 ) ) {
F_2 ( V_21 , L_8 ) ;
return - V_79 ;
}
if ( F_33 ( V_76 , & V_2 -> V_47 ) ) {
F_2 ( V_21 , L_9 ) ;
return - V_80 ;
}
V_74 . V_7 = V_2 -> V_6 . V_7 ;
V_74 . V_81 = V_21 -> V_82 ;
V_74 . V_83 = F_45 ( V_21 -> V_83 ) ;
V_2 -> V_84 = F_46 ( & V_85 , V_21 -> V_86 ,
V_21 -> V_54 , & V_74 ,
V_87 |
V_88 |
V_89 |
V_90 ,
V_14 ,
F_42 ,
V_2 ) ;
if ( F_39 ( V_2 -> V_84 ) ) {
V_25 = F_40 ( V_2 -> V_84 ) ;
F_37 ( V_76 , & V_2 -> V_47 ) ;
F_34 ( V_21 , L_10 ,
V_25 ) ;
} else {
F_2 ( V_21 , L_11 ,
V_2 -> V_6 . V_7 . V_8 ) ;
}
return V_25 ;
}
void F_47 ( struct V_91 * V_92 )
{
struct V_20 * V_21 = F_48 ( V_92 , struct V_20 ,
V_93 ) ;
struct V_94 V_95 ;
if ( F_49 ( V_21 -> V_86 , V_21 -> V_54 , & V_95 ) ||
V_95 . V_96 != V_97 ) {
F_50 ( V_21 , L_12 ) ;
return;
}
F_28 () ;
F_51 ( V_21 -> V_4 ) ;
F_31 () ;
}
static int F_52 ( int V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = F_3 ( V_4 ) ;
F_2 ( V_21 , L_13 ,
V_2 -> V_6 . V_7 . V_8 , V_69 ) ;
if ( V_69 == - V_73 ) {
V_69 = 0 ;
goto V_98;
}
if ( ! V_69 )
V_69 = F_21 ( V_2 , & V_71 -> V_74 ) ;
if ( ! V_69 ) {
V_2 -> V_17 = 1 ;
F_53 ( & V_99 ) ;
if ( F_32 ( V_100 , & V_21 -> V_47 ) )
F_54 ( V_101 ,
& V_21 -> V_102 , 0 ) ;
F_55 ( & V_99 ) ;
if ( V_2 == V_21 -> V_35 )
F_56 ( V_101 , & V_21 -> V_93 ) ;
V_69 = 0 ;
goto V_98;
}
if ( V_2 -> V_75 ++ < 20 ) {
if ( V_69 == - V_103 || V_69 == - V_37 ) {
F_2 ( V_21 , L_7 ,
V_2 -> V_6 . V_7 . V_8 , V_69 ) ;
} else {
F_34 ( V_21 , L_7 ,
V_2 -> V_6 . V_7 . V_8 , V_69 ) ;
}
}
V_2 -> V_17 *= 2 ;
if ( V_2 -> V_17 > V_104 )
V_2 -> V_17 = V_104 ;
V_69 = F_43 ( V_76 , & V_2 -> V_47 ) ;
F_53 ( & V_99 ) ;
F_22 ( & V_21 -> V_36 ) ;
if ( F_32 ( V_100 , & V_21 -> V_47 ) )
F_54 ( V_101 , & V_21 -> V_102 ,
V_2 -> V_17 * V_105 ) ;
F_23 ( & V_21 -> V_36 ) ;
F_55 ( & V_99 ) ;
V_98:
F_57 ( & V_2 -> V_106 ) ;
return V_69 ;
}
static void F_58 ( struct V_3 * V_4 , struct V_1 * V_2 ,
int V_107 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
struct V_32 V_74 = {
. V_77 = 1
} ;
T_1 V_108 ;
int V_25 = 0 ;
F_2 ( V_21 , L_14 , V_2 -> V_6 . V_7 . V_8 ) ;
V_74 . V_7 = V_2 -> V_6 . V_7 ;
V_74 . V_81 = V_21 -> V_82 ;
V_74 . V_83 = F_45 ( V_21 -> V_83 ) ;
V_108 =
V_87 |
V_88 |
V_89 |
V_90 ;
if ( V_107 ) {
V_108 |=
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 ;
V_74 . V_40 = V_21 -> V_35 -> V_6 . V_40 ;
V_74 . V_118 = V_119 ;
V_74 . V_39 = V_21 -> V_35 -> V_6 . V_39 ;
V_74 . V_64 = V_21 -> V_35 -> V_6 . V_64 ;
V_74 . V_120 = V_119 ;
V_74 . V_59 = V_21 -> V_35 -> V_6 . V_59 ;
V_74 . V_55 = V_21 -> V_35 -> V_6 . V_55 ;
V_74 . V_61 = V_21 -> V_35 -> V_6 . V_61 ;
V_74 . V_62 = V_21 -> V_35 -> V_6 . V_62 ;
}
F_59 ( V_76 , & V_2 -> V_47 ) ;
F_60 ( & V_2 -> V_106 ) ;
F_59 ( V_121 , & V_2 -> V_47 ) ;
V_2 -> V_84 = F_46 ( & V_85 , V_21 -> V_86 , V_21 -> V_54 ,
& V_74 , V_108 , V_13 ,
F_52 , V_2 ) ;
if ( F_39 ( V_2 -> V_84 ) ) {
F_37 ( V_76 , & V_2 -> V_47 ) ;
F_57 ( & V_2 -> V_106 ) ;
V_25 = F_40 ( V_2 -> V_84 ) ;
F_34 ( V_21 , L_15 , V_25 ) ;
V_2 -> V_17 *= 2 ;
if ( V_2 -> V_17 > V_104 )
V_2 -> V_17 = V_104 ;
F_53 ( & V_99 ) ;
if ( F_32 ( V_100 , & V_21 -> V_47 ) )
F_54 ( V_101 ,
& V_21 -> V_102 ,
V_2 -> V_17 * V_105 ) ;
F_55 ( & V_99 ) ;
}
}
void F_61 ( struct V_91 * V_92 )
{
struct V_20 * V_21 =
F_48 ( V_92 , struct V_20 , V_102 . V_92 ) ;
struct V_3 * V_4 = V_21 -> V_4 ;
struct V_94 V_122 ;
if ( ! F_32 ( V_100 , & V_21 -> V_47 ) )
return;
if ( F_49 ( V_21 -> V_86 , V_21 -> V_54 , & V_122 ) ||
V_122 . V_96 != V_97 ) {
F_50 ( V_21 , L_16 ,
V_122 . V_96 ) ;
return;
}
if ( F_62 ( V_21 -> V_86 , V_21 -> V_54 , 0 , & V_21 -> V_82 ) )
F_34 ( V_21 , L_17 ) ;
else
memcpy ( V_21 -> V_4 -> V_123 + 4 , V_21 -> V_82 . V_8 , sizeof ( union V_26 ) ) ;
{
struct V_94 V_95 ;
if ( ! F_49 ( V_21 -> V_86 , V_21 -> V_54 , & V_95 ) )
V_21 -> V_124 = V_95 . V_125 ;
else
F_34 ( V_21 , L_18 ) ;
}
if ( ! V_21 -> V_35 ) {
struct V_1 * V_35 ;
if ( ! F_32 ( V_126 , & V_21 -> V_47 ) )
return;
V_35 = F_12 ( V_4 , 1 ) ;
if ( ! V_35 ) {
F_34 ( V_21 , L_19 ) ;
F_53 ( & V_99 ) ;
if ( F_32 ( V_100 , & V_21 -> V_47 ) )
F_54 ( V_101 ,
& V_21 -> V_102 , V_105 ) ;
F_55 ( & V_99 ) ;
return;
}
F_22 ( & V_21 -> V_36 ) ;
memcpy ( V_35 -> V_6 . V_7 . V_8 , V_21 -> V_4 -> V_35 + 4 ,
sizeof ( union V_26 ) ) ;
V_21 -> V_35 = V_35 ;
F_18 ( V_4 , V_21 -> V_35 ) ;
F_23 ( & V_21 -> V_36 ) ;
}
if ( ! F_32 ( V_48 , & V_21 -> V_35 -> V_47 ) ) {
if ( ! F_32 ( V_76 , & V_21 -> V_35 -> V_47 ) )
F_58 ( V_4 , V_21 -> V_35 , 0 ) ;
return;
}
while ( 1 ) {
struct V_1 * V_2 = NULL ;
F_22 ( & V_21 -> V_36 ) ;
F_63 (mcast, &priv->multicast_list, list) {
if ( ! F_32 ( V_46 , & V_2 -> V_47 )
&& ! F_32 ( V_76 , & V_2 -> V_47 )
&& ! F_32 ( V_48 , & V_2 -> V_47 ) ) {
break;
}
}
F_23 ( & V_21 -> V_36 ) ;
if ( & V_2 -> V_18 == & V_21 -> V_127 ) {
break;
}
F_58 ( V_4 , V_2 , 1 ) ;
return;
}
F_2 ( V_21 , L_20 ) ;
F_37 ( V_100 , & V_21 -> V_47 ) ;
}
int F_64 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
F_2 ( V_21 , L_21 ) ;
F_53 ( & V_99 ) ;
if ( ! F_33 ( V_100 , & V_21 -> V_47 ) )
F_54 ( V_101 , & V_21 -> V_102 , 0 ) ;
F_55 ( & V_99 ) ;
return 0 ;
}
int F_65 ( struct V_3 * V_4 , int V_128 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
F_2 ( V_21 , L_22 ) ;
F_53 ( & V_99 ) ;
F_37 ( V_100 , & V_21 -> V_47 ) ;
F_66 ( & V_21 -> V_102 ) ;
F_55 ( & V_99 ) ;
if ( V_128 )
F_67 ( V_101 ) ;
return 0 ;
}
static int F_68 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
int V_25 = 0 ;
if ( F_43 ( V_76 , & V_2 -> V_47 ) )
F_69 ( V_2 -> V_84 ) ;
if ( F_43 ( V_48 , & V_2 -> V_47 ) ) {
F_2 ( V_21 , L_23 ,
V_2 -> V_6 . V_7 . V_8 ) ;
V_25 = F_70 ( V_21 -> V_129 , & V_2 -> V_6 . V_7 ,
F_36 ( V_2 -> V_6 . V_49 ) ) ;
if ( V_25 )
F_34 ( V_21 , L_24 , V_25 ) ;
}
return 0 ;
}
void F_71 ( struct V_3 * V_4 , T_2 * V_130 , struct V_67 * V_68 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
struct V_1 * V_2 ;
unsigned long V_47 ;
void * V_7 = V_130 + 4 ;
F_72 ( & V_21 -> V_36 , V_47 ) ;
if ( ! F_32 ( V_78 , & V_21 -> V_47 ) ||
! V_21 -> V_35 ||
! F_32 ( V_48 , & V_21 -> V_35 -> V_47 ) ) {
++ V_4 -> V_11 . V_5 ;
F_7 ( V_68 ) ;
goto V_131;
}
V_2 = F_16 ( V_4 , V_7 ) ;
if ( ! V_2 ) {
F_2 ( V_21 , L_25 ,
V_7 ) ;
V_2 = F_12 ( V_4 , 0 ) ;
if ( ! V_2 ) {
F_34 ( V_21 , L_26
L_27 ) ;
++ V_4 -> V_11 . V_5 ;
F_7 ( V_68 ) ;
goto V_98;
}
F_59 ( V_46 , & V_2 -> V_47 ) ;
memcpy ( V_2 -> V_6 . V_7 . V_8 , V_7 , sizeof ( union V_26 ) ) ;
F_18 ( V_4 , V_2 ) ;
F_73 ( & V_2 -> V_18 , & V_21 -> V_127 ) ;
}
if ( ! V_2 -> V_9 ) {
if ( F_74 ( & V_2 -> V_10 ) < V_132 )
F_75 ( & V_2 -> V_10 , V_68 ) ;
else {
++ V_4 -> V_11 . V_5 ;
F_7 ( V_68 ) ;
}
if ( F_32 ( V_76 , & V_2 -> V_47 ) )
F_2 ( V_21 , L_28
L_29 ) ;
else if ( F_32 ( V_46 , & V_2 -> V_47 ) )
F_44 ( V_2 ) ;
V_2 = NULL ;
}
V_98:
if ( V_2 && V_2 -> V_9 ) {
struct V_133 * V_134 ;
F_76 ( & V_21 -> V_36 , V_47 ) ;
V_134 = F_77 ( V_4 , V_130 ) ;
F_72 ( & V_21 -> V_36 , V_47 ) ;
if ( ! V_134 ) {
V_134 = F_78 ( V_130 , V_4 ) ;
if ( V_134 ) {
F_79 ( & V_2 -> V_9 -> V_135 ) ;
V_134 -> V_9 = V_2 -> V_9 ;
F_73 ( & V_134 -> V_18 , & V_2 -> V_19 ) ;
}
}
F_76 ( & V_21 -> V_36 , V_47 ) ;
F_80 ( V_4 , V_68 , V_2 -> V_9 , V_136 ) ;
if ( V_134 )
F_81 ( V_134 ) ;
return;
}
V_131:
F_76 ( & V_21 -> V_36 , V_47 ) ;
}
void F_82 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
F_83 ( V_137 ) ;
struct V_1 * V_2 , * V_30 ;
unsigned long V_47 ;
F_2 ( V_21 , L_30 ) ;
F_72 ( & V_21 -> V_36 , V_47 ) ;
F_84 (mcast, tmcast, &priv->multicast_list, list) {
F_85 ( & V_2 -> V_18 ) ;
F_86 ( & V_2 -> V_22 , & V_21 -> V_24 ) ;
F_73 ( & V_2 -> V_18 , & V_137 ) ;
}
if ( V_21 -> V_35 ) {
F_86 ( & V_21 -> V_35 -> V_22 , & V_21 -> V_24 ) ;
F_73 ( & V_21 -> V_35 -> V_18 , & V_137 ) ;
V_21 -> V_35 = NULL ;
}
F_76 ( & V_21 -> V_36 , V_47 ) ;
F_84 (mcast, tmcast, &remove_list, list)
if ( F_32 ( V_121 , & V_2 -> V_47 ) )
F_87 ( & V_2 -> V_106 ) ;
F_84 (mcast, tmcast, &remove_list, list) {
F_68 ( V_4 , V_2 ) ;
F_1 ( V_2 ) ;
}
}
static int F_88 ( const T_2 * V_138 , const T_2 * V_35 )
{
if ( memcmp ( V_138 , V_35 , 6 ) )
return 0 ;
if ( memcmp ( V_138 + 7 , V_35 + 7 , 3 ) )
return 0 ;
return 1 ;
}
void F_89 ( struct V_91 * V_92 )
{
struct V_20 * V_21 =
F_48 ( V_92 , struct V_20 , V_139 ) ;
struct V_3 * V_4 = V_21 -> V_4 ;
struct V_140 * V_141 ;
struct V_1 * V_2 , * V_30 ;
F_83 ( V_137 ) ;
unsigned long V_47 ;
struct V_32 V_74 ;
F_2 ( V_21 , L_31 ) ;
F_65 ( V_4 , 0 ) ;
F_90 ( V_47 ) ;
F_91 ( V_4 ) ;
F_92 ( & V_21 -> V_36 ) ;
F_63 (mcast, &priv->multicast_list, list)
F_37 ( V_142 , & V_2 -> V_47 ) ;
F_93 (ha, dev) {
union V_26 V_7 ;
if ( ! F_88 ( V_141 -> V_138 , V_4 -> V_35 ) )
continue;
memcpy ( V_7 . V_8 , V_141 -> V_138 + 4 , sizeof V_7 ) ;
V_2 = F_16 ( V_4 , & V_7 ) ;
if ( ! V_2 || F_32 ( V_46 , & V_2 -> V_47 ) ) {
struct V_1 * V_143 ;
if ( F_32 ( V_144 , & V_21 -> V_47 ) &&
! F_94 ( V_21 -> V_86 , V_21 -> V_54 , & V_7 , & V_74 ) ) {
F_2 ( V_21 , L_32 ,
V_7 . V_8 ) ;
continue;
}
F_2 ( V_21 , L_33 ,
V_7 . V_8 ) ;
V_143 = F_12 ( V_4 , 0 ) ;
if ( ! V_143 ) {
F_34 ( V_21 , L_34 ) ;
continue;
}
F_59 ( V_142 , & V_143 -> V_47 ) ;
V_143 -> V_6 . V_7 = V_7 ;
if ( V_2 ) {
F_95 ( & V_2 -> V_18 , & V_137 ) ;
F_96 ( & V_2 -> V_22 ,
& V_143 -> V_22 ,
& V_21 -> V_24 ) ;
} else
F_18 ( V_4 , V_143 ) ;
F_73 ( & V_143 -> V_18 , & V_21 -> V_127 ) ;
}
if ( V_2 )
F_59 ( V_142 , & V_2 -> V_47 ) ;
}
F_84 (mcast, tmcast, &priv->multicast_list, list) {
if ( ! F_32 ( V_142 , & V_2 -> V_47 ) &&
! F_32 ( V_46 , & V_2 -> V_47 ) ) {
F_2 ( V_21 , L_1 ,
V_2 -> V_6 . V_7 . V_8 ) ;
F_86 ( & V_2 -> V_22 , & V_21 -> V_24 ) ;
F_95 ( & V_2 -> V_18 , & V_137 ) ;
}
}
F_97 ( & V_21 -> V_36 ) ;
F_98 ( V_4 ) ;
F_99 ( V_47 ) ;
F_84 (mcast, tmcast, &remove_list, list) {
F_68 ( V_2 -> V_4 , V_2 ) ;
F_1 ( V_2 ) ;
}
if ( F_32 ( V_126 , & V_21 -> V_47 ) )
F_64 ( V_4 ) ;
}
struct V_145 * F_100 ( struct V_3 * V_4 )
{
struct V_145 * V_146 ;
V_146 = F_101 ( sizeof *V_146 , V_13 ) ;
if ( ! V_146 )
return NULL ;
V_146 -> V_4 = V_4 ;
memset ( V_146 -> V_7 . V_8 , 0 , 16 ) ;
if ( F_102 ( V_146 ) ) {
F_11 ( V_146 ) ;
return NULL ;
}
return V_146 ;
}
int F_102 ( struct V_145 * V_146 )
{
struct V_20 * V_21 = F_3 ( V_146 -> V_4 ) ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
int V_25 = 1 ;
F_22 ( & V_21 -> V_36 ) ;
V_23 = F_103 ( & V_21 -> V_24 ) ;
while ( V_23 ) {
V_2 = F_17 ( V_23 , struct V_1 , V_22 ) ;
if ( memcmp ( V_146 -> V_7 . V_8 , V_2 -> V_6 . V_7 . V_8 ,
sizeof ( union V_26 ) ) < 0 ) {
V_146 -> V_7 = V_2 -> V_6 . V_7 ;
V_146 -> V_15 = V_2 -> V_15 ;
V_146 -> V_147 = F_74 ( & V_2 -> V_10 ) ;
V_146 -> F_57 = ! ! V_2 -> V_9 ;
V_146 -> V_148 = ! ! ( V_2 -> V_47 & ( 1 << V_46 ) ) ;
V_25 = 0 ;
break;
}
V_23 = F_104 ( V_23 ) ;
}
F_23 ( & V_21 -> V_36 ) ;
return V_25 ;
}
void F_105 ( struct V_145 * V_146 ,
union V_26 * V_7 ,
unsigned long * V_15 ,
unsigned int * V_147 ,
unsigned int * F_57 ,
unsigned int * V_148 )
{
* V_7 = V_146 -> V_7 ;
* V_15 = V_146 -> V_15 ;
* V_147 = V_146 -> V_147 ;
* F_57 = V_146 -> F_57 ;
* V_148 = V_146 -> V_148 ;
}
