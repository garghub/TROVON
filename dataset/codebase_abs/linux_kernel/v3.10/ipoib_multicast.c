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
if ( V_69 == - V_73 )
return 0 ;
if ( ! V_69 )
V_69 = F_21 ( V_2 , & V_71 -> V_74 ) ;
if ( ! V_69 ) {
V_2 -> V_17 = 1 ;
F_53 ( & V_98 ) ;
if ( F_32 ( V_99 , & V_21 -> V_47 ) )
F_54 ( V_100 ,
& V_21 -> V_101 , 0 ) ;
F_55 ( & V_98 ) ;
if ( V_2 == V_21 -> V_35 )
F_56 ( V_100 , & V_21 -> V_93 ) ;
return 0 ;
}
if ( V_2 -> V_75 ++ < 20 ) {
if ( V_69 == - V_102 || V_69 == - V_37 ) {
F_2 ( V_21 , L_7 ,
V_2 -> V_6 . V_7 . V_8 , V_69 ) ;
} else {
F_34 ( V_21 , L_7 ,
V_2 -> V_6 . V_7 . V_8 , V_69 ) ;
}
}
V_2 -> V_17 *= 2 ;
if ( V_2 -> V_17 > V_103 )
V_2 -> V_17 = V_103 ;
V_69 = F_43 ( V_76 , & V_2 -> V_47 ) ;
F_53 ( & V_98 ) ;
F_22 ( & V_21 -> V_36 ) ;
if ( F_32 ( V_99 , & V_21 -> V_47 ) )
F_54 ( V_100 , & V_21 -> V_101 ,
V_2 -> V_17 * V_104 ) ;
F_23 ( & V_21 -> V_36 ) ;
F_55 ( & V_98 ) ;
return V_69 ;
}
static void F_57 ( struct V_3 * V_4 , struct V_1 * V_2 ,
int V_105 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
struct V_32 V_74 = {
. V_77 = 1
} ;
T_1 V_106 ;
int V_25 = 0 ;
F_2 ( V_21 , L_14 , V_2 -> V_6 . V_7 . V_8 ) ;
V_74 . V_7 = V_2 -> V_6 . V_7 ;
V_74 . V_81 = V_21 -> V_82 ;
V_74 . V_83 = F_45 ( V_21 -> V_83 ) ;
V_106 =
V_87 |
V_88 |
V_89 |
V_90 ;
if ( V_105 ) {
V_106 |=
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 ;
V_74 . V_40 = V_21 -> V_35 -> V_6 . V_40 ;
V_74 . V_116 = V_117 ;
V_74 . V_39 = V_21 -> V_35 -> V_6 . V_39 ;
V_74 . V_64 = V_21 -> V_35 -> V_6 . V_64 ;
V_74 . V_118 = V_117 ;
V_74 . V_59 = V_21 -> V_35 -> V_6 . V_59 ;
V_74 . V_55 = V_21 -> V_35 -> V_6 . V_55 ;
V_74 . V_61 = V_21 -> V_35 -> V_6 . V_61 ;
V_74 . V_62 = V_21 -> V_35 -> V_6 . V_62 ;
}
F_58 ( V_76 , & V_2 -> V_47 ) ;
V_2 -> V_84 = F_46 ( & V_85 , V_21 -> V_86 , V_21 -> V_54 ,
& V_74 , V_106 , V_13 ,
F_52 , V_2 ) ;
if ( F_39 ( V_2 -> V_84 ) ) {
F_37 ( V_76 , & V_2 -> V_47 ) ;
V_25 = F_40 ( V_2 -> V_84 ) ;
F_34 ( V_21 , L_15 , V_25 ) ;
V_2 -> V_17 *= 2 ;
if ( V_2 -> V_17 > V_103 )
V_2 -> V_17 = V_103 ;
F_53 ( & V_98 ) ;
if ( F_32 ( V_99 , & V_21 -> V_47 ) )
F_54 ( V_100 ,
& V_21 -> V_101 ,
V_2 -> V_17 * V_104 ) ;
F_55 ( & V_98 ) ;
}
}
void F_59 ( struct V_91 * V_92 )
{
struct V_20 * V_21 =
F_48 ( V_92 , struct V_20 , V_101 . V_92 ) ;
struct V_3 * V_4 = V_21 -> V_4 ;
if ( ! F_32 ( V_99 , & V_21 -> V_47 ) )
return;
if ( F_60 ( V_21 -> V_86 , V_21 -> V_54 , 0 , & V_21 -> V_82 ) )
F_34 ( V_21 , L_16 ) ;
else
memcpy ( V_21 -> V_4 -> V_119 + 4 , V_21 -> V_82 . V_8 , sizeof ( union V_26 ) ) ;
{
struct V_94 V_95 ;
if ( ! F_49 ( V_21 -> V_86 , V_21 -> V_54 , & V_95 ) )
V_21 -> V_120 = V_95 . V_121 ;
else
F_34 ( V_21 , L_17 ) ;
}
if ( ! V_21 -> V_35 ) {
struct V_1 * V_35 ;
if ( ! F_32 ( V_122 , & V_21 -> V_47 ) )
return;
V_35 = F_12 ( V_4 , 1 ) ;
if ( ! V_35 ) {
F_34 ( V_21 , L_18 ) ;
F_53 ( & V_98 ) ;
if ( F_32 ( V_99 , & V_21 -> V_47 ) )
F_54 ( V_100 ,
& V_21 -> V_101 , V_104 ) ;
F_55 ( & V_98 ) ;
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
F_57 ( V_4 , V_21 -> V_35 , 0 ) ;
return;
}
while ( 1 ) {
struct V_1 * V_2 = NULL ;
F_22 ( & V_21 -> V_36 ) ;
F_61 (mcast, &priv->multicast_list, list) {
if ( ! F_32 ( V_46 , & V_2 -> V_47 )
&& ! F_32 ( V_76 , & V_2 -> V_47 )
&& ! F_32 ( V_48 , & V_2 -> V_47 ) ) {
break;
}
}
F_23 ( & V_21 -> V_36 ) ;
if ( & V_2 -> V_18 == & V_21 -> V_123 ) {
break;
}
F_57 ( V_4 , V_2 , 1 ) ;
return;
}
F_2 ( V_21 , L_19 ) ;
F_37 ( V_99 , & V_21 -> V_47 ) ;
}
int F_62 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
F_2 ( V_21 , L_20 ) ;
F_53 ( & V_98 ) ;
if ( ! F_33 ( V_99 , & V_21 -> V_47 ) )
F_54 ( V_100 , & V_21 -> V_101 , 0 ) ;
F_55 ( & V_98 ) ;
return 0 ;
}
int F_63 ( struct V_3 * V_4 , int V_124 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
F_2 ( V_21 , L_21 ) ;
F_53 ( & V_98 ) ;
F_37 ( V_99 , & V_21 -> V_47 ) ;
F_64 ( & V_21 -> V_101 ) ;
F_55 ( & V_98 ) ;
if ( V_124 )
F_65 ( V_100 ) ;
return 0 ;
}
static int F_66 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
int V_25 = 0 ;
if ( F_43 ( V_76 , & V_2 -> V_47 ) )
F_67 ( V_2 -> V_84 ) ;
if ( F_43 ( V_48 , & V_2 -> V_47 ) ) {
F_2 ( V_21 , L_22 ,
V_2 -> V_6 . V_7 . V_8 ) ;
V_25 = F_68 ( V_21 -> V_125 , & V_2 -> V_6 . V_7 ,
F_36 ( V_2 -> V_6 . V_49 ) ) ;
if ( V_25 )
F_34 ( V_21 , L_23 , V_25 ) ;
}
return 0 ;
}
void F_69 ( struct V_3 * V_4 , T_2 * V_126 , struct V_67 * V_68 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
struct V_1 * V_2 ;
unsigned long V_47 ;
void * V_7 = V_126 + 4 ;
F_70 ( & V_21 -> V_36 , V_47 ) ;
if ( ! F_32 ( V_78 , & V_21 -> V_47 ) ||
! V_21 -> V_35 ||
! F_32 ( V_48 , & V_21 -> V_35 -> V_47 ) ) {
++ V_4 -> V_11 . V_5 ;
F_7 ( V_68 ) ;
goto V_127;
}
V_2 = F_16 ( V_4 , V_7 ) ;
if ( ! V_2 ) {
F_2 ( V_21 , L_24 ,
V_7 ) ;
V_2 = F_12 ( V_4 , 0 ) ;
if ( ! V_2 ) {
F_34 ( V_21 , L_25
L_26 ) ;
++ V_4 -> V_11 . V_5 ;
F_7 ( V_68 ) ;
goto V_128;
}
F_58 ( V_46 , & V_2 -> V_47 ) ;
memcpy ( V_2 -> V_6 . V_7 . V_8 , V_7 , sizeof ( union V_26 ) ) ;
F_18 ( V_4 , V_2 ) ;
F_71 ( & V_2 -> V_18 , & V_21 -> V_123 ) ;
}
if ( ! V_2 -> V_9 ) {
if ( F_72 ( & V_2 -> V_10 ) < V_129 )
F_73 ( & V_2 -> V_10 , V_68 ) ;
else {
++ V_4 -> V_11 . V_5 ;
F_7 ( V_68 ) ;
}
if ( F_32 ( V_76 , & V_2 -> V_47 ) )
F_2 ( V_21 , L_27
L_28 ) ;
else if ( F_32 ( V_46 , & V_2 -> V_47 ) )
F_44 ( V_2 ) ;
V_2 = NULL ;
}
V_128:
if ( V_2 && V_2 -> V_9 ) {
struct V_130 * V_131 ;
F_74 ( & V_21 -> V_36 , V_47 ) ;
V_131 = F_75 ( V_4 , V_126 ) ;
F_70 ( & V_21 -> V_36 , V_47 ) ;
if ( ! V_131 ) {
V_131 = F_76 ( V_126 , V_4 ) ;
if ( V_131 ) {
F_77 ( & V_2 -> V_9 -> V_132 ) ;
V_131 -> V_9 = V_2 -> V_9 ;
F_71 ( & V_131 -> V_18 , & V_2 -> V_19 ) ;
}
}
F_74 ( & V_21 -> V_36 , V_47 ) ;
F_78 ( V_4 , V_68 , V_2 -> V_9 , V_133 ) ;
if ( V_131 )
F_79 ( V_131 ) ;
return;
}
V_127:
F_74 ( & V_21 -> V_36 , V_47 ) ;
}
void F_80 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = F_3 ( V_4 ) ;
F_81 ( V_134 ) ;
struct V_1 * V_2 , * V_30 ;
unsigned long V_47 ;
F_2 ( V_21 , L_29 ) ;
F_70 ( & V_21 -> V_36 , V_47 ) ;
F_82 (mcast, tmcast, &priv->multicast_list, list) {
F_83 ( & V_2 -> V_18 ) ;
F_84 ( & V_2 -> V_22 , & V_21 -> V_24 ) ;
F_71 ( & V_2 -> V_18 , & V_134 ) ;
}
if ( V_21 -> V_35 ) {
F_84 ( & V_21 -> V_35 -> V_22 , & V_21 -> V_24 ) ;
F_71 ( & V_21 -> V_35 -> V_18 , & V_134 ) ;
V_21 -> V_35 = NULL ;
}
F_74 ( & V_21 -> V_36 , V_47 ) ;
F_82 (mcast, tmcast, &remove_list, list) {
F_66 ( V_4 , V_2 ) ;
F_1 ( V_2 ) ;
}
}
static int F_85 ( const T_2 * V_135 , const T_2 * V_35 )
{
if ( memcmp ( V_135 , V_35 , 6 ) )
return 0 ;
if ( memcmp ( V_135 + 7 , V_35 + 7 , 3 ) )
return 0 ;
return 1 ;
}
void F_86 ( struct V_91 * V_92 )
{
struct V_20 * V_21 =
F_48 ( V_92 , struct V_20 , V_136 ) ;
struct V_3 * V_4 = V_21 -> V_4 ;
struct V_137 * V_138 ;
struct V_1 * V_2 , * V_30 ;
F_81 ( V_134 ) ;
unsigned long V_47 ;
struct V_32 V_74 ;
F_2 ( V_21 , L_30 ) ;
F_63 ( V_4 , 0 ) ;
F_87 ( V_47 ) ;
F_88 ( V_4 ) ;
F_89 ( & V_21 -> V_36 ) ;
F_61 (mcast, &priv->multicast_list, list)
F_37 ( V_139 , & V_2 -> V_47 ) ;
F_90 (ha, dev) {
union V_26 V_7 ;
if ( ! F_85 ( V_138 -> V_135 , V_4 -> V_35 ) )
continue;
memcpy ( V_7 . V_8 , V_138 -> V_135 + 4 , sizeof V_7 ) ;
V_2 = F_16 ( V_4 , & V_7 ) ;
if ( ! V_2 || F_32 ( V_46 , & V_2 -> V_47 ) ) {
struct V_1 * V_140 ;
if ( F_32 ( V_141 , & V_21 -> V_47 ) &&
! F_91 ( V_21 -> V_86 , V_21 -> V_54 , & V_7 , & V_74 ) ) {
F_2 ( V_21 , L_31 ,
V_7 . V_8 ) ;
continue;
}
F_2 ( V_21 , L_32 ,
V_7 . V_8 ) ;
V_140 = F_12 ( V_4 , 0 ) ;
if ( ! V_140 ) {
F_34 ( V_21 , L_33 ) ;
continue;
}
F_58 ( V_139 , & V_140 -> V_47 ) ;
V_140 -> V_6 . V_7 = V_7 ;
if ( V_2 ) {
F_92 ( & V_2 -> V_18 , & V_134 ) ;
F_93 ( & V_2 -> V_22 ,
& V_140 -> V_22 ,
& V_21 -> V_24 ) ;
} else
F_18 ( V_4 , V_140 ) ;
F_71 ( & V_140 -> V_18 , & V_21 -> V_123 ) ;
}
if ( V_2 )
F_58 ( V_139 , & V_2 -> V_47 ) ;
}
F_82 (mcast, tmcast, &priv->multicast_list, list) {
if ( ! F_32 ( V_139 , & V_2 -> V_47 ) &&
! F_32 ( V_46 , & V_2 -> V_47 ) ) {
F_2 ( V_21 , L_1 ,
V_2 -> V_6 . V_7 . V_8 ) ;
F_84 ( & V_2 -> V_22 , & V_21 -> V_24 ) ;
F_92 ( & V_2 -> V_18 , & V_134 ) ;
}
}
F_94 ( & V_21 -> V_36 ) ;
F_95 ( V_4 ) ;
F_96 ( V_47 ) ;
F_82 (mcast, tmcast, &remove_list, list) {
F_66 ( V_2 -> V_4 , V_2 ) ;
F_1 ( V_2 ) ;
}
if ( F_32 ( V_122 , & V_21 -> V_47 ) )
F_62 ( V_4 ) ;
}
struct V_142 * F_97 ( struct V_3 * V_4 )
{
struct V_142 * V_143 ;
V_143 = F_98 ( sizeof *V_143 , V_13 ) ;
if ( ! V_143 )
return NULL ;
V_143 -> V_4 = V_4 ;
memset ( V_143 -> V_7 . V_8 , 0 , 16 ) ;
if ( F_99 ( V_143 ) ) {
F_11 ( V_143 ) ;
return NULL ;
}
return V_143 ;
}
int F_99 ( struct V_142 * V_143 )
{
struct V_20 * V_21 = F_3 ( V_143 -> V_4 ) ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
int V_25 = 1 ;
F_22 ( & V_21 -> V_36 ) ;
V_23 = F_100 ( & V_21 -> V_24 ) ;
while ( V_23 ) {
V_2 = F_17 ( V_23 , struct V_1 , V_22 ) ;
if ( memcmp ( V_143 -> V_7 . V_8 , V_2 -> V_6 . V_7 . V_8 ,
sizeof ( union V_26 ) ) < 0 ) {
V_143 -> V_7 = V_2 -> V_6 . V_7 ;
V_143 -> V_15 = V_2 -> V_15 ;
V_143 -> V_144 = F_72 ( & V_2 -> V_10 ) ;
V_143 -> V_145 = ! ! V_2 -> V_9 ;
V_143 -> V_146 = ! ! ( V_2 -> V_47 & ( 1 << V_46 ) ) ;
V_25 = 0 ;
break;
}
V_23 = F_101 ( V_23 ) ;
}
F_23 ( & V_21 -> V_36 ) ;
return V_25 ;
}
void F_102 ( struct V_142 * V_143 ,
union V_26 * V_7 ,
unsigned long * V_15 ,
unsigned int * V_144 ,
unsigned int * V_145 ,
unsigned int * V_146 )
{
* V_7 = V_143 -> V_7 ;
* V_15 = V_143 -> V_15 ;
* V_144 = V_143 -> V_144 ;
* V_145 = V_143 -> V_145 ;
* V_146 = V_143 -> V_146 ;
}
