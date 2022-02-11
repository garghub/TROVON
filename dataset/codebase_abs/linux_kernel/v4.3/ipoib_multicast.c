static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_5 )
{
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
F_3 ( & V_2 -> V_8 ) ;
if ( V_4 && V_5 ) {
V_4 -> V_9 *= 2 ;
if ( V_4 -> V_9 > V_10 )
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = V_12 + ( V_4 -> V_9 * V_13 ) ;
F_4 ( V_2 -> V_14 , & V_2 -> V_8 , 0 ) ;
} else if ( V_5 ) {
F_4 ( V_2 -> V_14 , & V_2 -> V_8 , V_13 ) ;
} else
F_4 ( V_2 -> V_14 , & V_2 -> V_8 , 0 ) ;
}
void F_5 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_17 = 0 ;
F_6 ( F_7 ( V_16 ) , L_1 ,
V_4 -> V_18 . V_19 . V_20 ) ;
F_8 ( V_16 , V_4 -> V_18 . V_19 . V_20 ) ;
if ( V_4 -> V_21 )
F_9 ( V_4 -> V_21 ) ;
while ( ! F_10 ( & V_4 -> V_22 ) ) {
++ V_17 ;
F_11 ( F_12 ( & V_4 -> V_22 ) ) ;
}
F_13 ( V_16 ) ;
V_16 -> V_23 . V_17 += V_17 ;
F_14 ( V_16 ) ;
F_15 ( V_4 ) ;
}
static struct V_3 * F_16 ( struct V_15 * V_16 ,
int V_24 )
{
struct V_3 * V_4 ;
V_4 = F_17 ( sizeof *V_4 , V_24 ? V_25 : V_26 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_16 = V_16 ;
V_4 -> V_27 = V_12 ;
V_4 -> V_11 = V_12 ;
V_4 -> V_9 = 1 ;
F_18 ( & V_4 -> V_28 ) ;
F_18 ( & V_4 -> V_29 ) ;
F_19 ( & V_4 -> V_22 ) ;
return V_4 ;
}
struct V_3 * F_20 ( struct V_15 * V_16 , void * V_19 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_30 * V_31 = V_2 -> V_32 . V_30 ;
while ( V_31 ) {
struct V_3 * V_4 ;
int V_33 ;
V_4 = F_21 ( V_31 , struct V_3 , V_30 ) ;
V_33 = memcmp ( V_19 , V_4 -> V_18 . V_19 . V_20 ,
sizeof ( union V_34 ) ) ;
if ( V_33 < 0 )
V_31 = V_31 -> V_35 ;
else if ( V_33 > 0 )
V_31 = V_31 -> V_36 ;
else
return V_4 ;
}
return NULL ;
}
static int F_22 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_30 * * V_31 = & V_2 -> V_32 . V_30 , * V_37 = NULL ;
while ( * V_31 ) {
struct V_3 * V_38 ;
int V_33 ;
V_37 = * V_31 ;
V_38 = F_21 ( V_37 , struct V_3 , V_30 ) ;
V_33 = memcmp ( V_4 -> V_18 . V_19 . V_20 , V_38 -> V_18 . V_19 . V_20 ,
sizeof ( union V_34 ) ) ;
if ( V_33 < 0 )
V_31 = & V_37 -> V_35 ;
else if ( V_33 > 0 )
V_31 = & V_37 -> V_36 ;
else
return - V_39 ;
}
F_23 ( & V_4 -> V_30 , V_37 , V_31 ) ;
F_24 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
struct V_40 * V_18 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_41 * V_21 ;
int V_33 ;
int V_42 = 0 ;
V_4 -> V_18 = * V_18 ;
if ( ! memcmp ( V_4 -> V_18 . V_19 . V_20 , V_2 -> V_16 -> V_43 + 4 ,
sizeof ( union V_34 ) ) ) {
F_26 ( & V_2 -> V_44 ) ;
if ( ! V_2 -> V_43 ) {
F_27 ( & V_2 -> V_44 ) ;
return - V_45 ;
}
V_2 -> V_43 -> V_18 . V_46 = V_18 -> V_46 ;
V_2 -> V_43 -> V_18 . V_47 = V_18 -> V_47 ;
V_2 -> V_43 -> V_18 . V_48 = V_18 -> V_48 ;
V_2 -> V_43 -> V_18 . V_49 = V_18 -> V_49 ;
V_2 -> V_43 -> V_18 . V_50 = V_18 -> V_50 ;
V_2 -> V_43 -> V_18 . V_51 = V_18 -> V_51 ;
V_2 -> V_43 -> V_18 . V_52 = V_18 -> V_52 ;
if ( V_2 -> V_53 == V_2 -> V_54 )
V_2 -> V_54 =
V_2 -> V_53 =
F_28 ( F_29 ( V_2 -> V_43 -> V_18 . V_47 ) ) ;
else
V_2 -> V_53 =
F_28 ( F_29 ( V_2 -> V_43 -> V_18 . V_47 ) ) ;
V_2 -> V_46 = F_30 ( V_2 -> V_43 -> V_18 . V_46 ) ;
F_27 ( & V_2 -> V_44 ) ;
V_2 -> V_55 . V_56 . V_57 . V_58 = V_2 -> V_46 ;
V_42 = 1 ;
}
if ( ! F_2 ( V_59 , & V_4 -> V_7 ) ) {
if ( F_31 ( V_60 , & V_4 -> V_7 ) ) {
F_32 ( V_2 , L_2 ,
V_4 -> V_18 . V_19 . V_20 ) ;
return 0 ;
}
V_33 = F_33 ( V_16 , F_34 ( V_4 -> V_18 . V_61 ) ,
& V_4 -> V_18 . V_19 , V_42 ) ;
if ( V_33 < 0 ) {
F_32 ( V_2 , L_3 ,
V_4 -> V_18 . V_19 . V_20 ) ;
F_35 ( V_60 , & V_4 -> V_7 ) ;
return V_33 ;
}
}
{
struct V_62 V_63 = {
. V_64 = F_34 ( V_4 -> V_18 . V_61 ) ,
. V_65 = V_2 -> V_66 ,
. V_50 = V_4 -> V_18 . V_50 ,
. V_67 = V_68 ,
. V_69 = V_4 -> V_18 . V_49 ,
. V_70 = {
. V_51 = F_30 ( V_4 -> V_18 . V_51 ) ,
. V_52 = V_4 -> V_18 . V_52 ,
. V_71 = 0 ,
. V_48 = V_4 -> V_18 . V_48
}
} ;
V_63 . V_70 . V_72 = V_4 -> V_18 . V_19 ;
V_21 = F_36 ( V_16 , V_2 -> V_73 , & V_63 ) ;
if ( F_37 ( V_21 ) ) {
F_32 ( V_2 , L_4 ,
- F_38 ( V_21 ) ) ;
return F_38 ( V_21 ) ;
} else {
F_26 ( & V_2 -> V_44 ) ;
V_4 -> V_21 = V_21 ;
F_27 ( & V_2 -> V_44 ) ;
F_6 ( V_2 , L_5 ,
V_4 -> V_18 . V_19 . V_20 ,
V_4 -> V_21 -> V_21 ,
F_34 ( V_4 -> V_18 . V_61 ) ,
V_4 -> V_18 . V_50 ) ;
}
}
F_13 ( V_16 ) ;
while ( ! F_10 ( & V_4 -> V_22 ) ) {
struct V_74 * V_75 = F_12 ( & V_4 -> V_22 ) ;
F_14 ( V_16 ) ;
V_75 -> V_16 = V_16 ;
if ( F_39 ( V_75 ) )
F_32 ( V_2 , L_6 ) ;
F_13 ( V_16 ) ;
}
F_14 ( V_16 ) ;
return 0 ;
}
void F_40 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_41 ( V_77 , struct V_1 ,
V_78 ) ;
struct V_79 V_80 ;
if ( F_42 ( V_2 -> V_81 , V_2 -> V_66 , & V_80 ) ||
V_80 . V_82 != V_83 ) {
F_43 ( V_2 , L_7 ) ;
return;
}
while ( ! F_44 () ) {
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
else
F_45 ( 20 ) ;
}
if ( ! F_46 ( V_2 -> V_16 ) )
F_47 ( V_2 -> V_16 , F_48 ( V_2 -> V_53 , V_2 -> V_54 ) ) ;
F_49 ( V_2 -> V_16 ) ;
F_50 () ;
}
static int F_51 ( int V_84 ,
struct V_85 * V_86 )
{
struct V_3 * V_4 = V_86 -> V_87 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_6 ( V_2 , L_8 ,
F_2 ( V_59 , & V_4 -> V_7 ) ?
L_9 : L_10 ,
V_4 -> V_18 . V_19 . V_20 , V_84 ) ;
if ( V_84 == - V_88 ) {
V_84 = 0 ;
goto V_89;
}
if ( ! V_84 )
V_84 = F_25 ( V_4 , & V_86 -> V_90 ) ;
if ( ! V_84 ) {
V_4 -> V_9 = 1 ;
V_4 -> V_11 = V_12 ;
if ( V_4 == V_2 -> V_43 ) {
F_26 ( & V_2 -> V_44 ) ;
F_52 ( V_2 -> V_14 , & V_2 -> V_78 ) ;
F_1 ( V_2 , NULL , 0 ) ;
goto V_91;
}
} else {
bool V_92 =
F_2 ( V_59 , & V_4 -> V_7 ) &&
V_84 == - V_93 ;
if ( V_4 -> V_94 < 20 ) {
if ( V_84 == - V_95 || V_84 == - V_45 ||
V_92 ) {
F_6 ( V_2 , L_11 ,
F_2 ( V_59 , & V_4 -> V_7 ) ? L_9 : L_10 ,
V_4 -> V_18 . V_19 . V_20 , V_84 ) ;
} else {
F_32 ( V_2 , L_11 ,
F_2 ( V_59 , & V_4 -> V_7 ) ? L_9 : L_10 ,
V_4 -> V_18 . V_19 . V_20 , V_84 ) ;
}
if ( ! V_92 )
V_4 -> V_94 ++ ;
}
if ( F_2 ( V_59 , & V_4 -> V_7 ) &&
V_4 -> V_9 >= 2 ) {
V_4 -> V_9 = 1 ;
F_13 ( V_16 ) ;
while ( ! F_10 ( & V_4 -> V_22 ) ) {
++ V_16 -> V_23 . V_17 ;
F_11 ( F_12 ( & V_4 -> V_22 ) ) ;
}
F_14 ( V_16 ) ;
} else {
F_26 ( & V_2 -> V_44 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
goto V_91;
}
}
V_89:
F_26 ( & V_2 -> V_44 ) ;
V_91:
if ( V_84 )
V_4 -> V_96 = NULL ;
else
V_4 -> V_96 = V_86 ;
F_35 ( V_97 , & V_4 -> V_7 ) ;
F_27 ( & V_2 -> V_44 ) ;
F_53 ( & V_4 -> V_98 ) ;
return V_84 ;
}
static void F_54 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_85 * V_86 ;
struct V_40 V_90 = {
. V_99 = 1
} ;
T_1 V_100 ;
int V_33 = 0 ;
F_6 ( V_2 , L_12 , V_4 -> V_18 . V_19 . V_20 ) ;
V_90 . V_19 = V_4 -> V_18 . V_19 ;
V_90 . V_101 = V_2 -> V_102 ;
V_90 . V_103 = F_55 ( V_2 -> V_103 ) ;
V_100 =
V_104 |
V_105 |
V_106 |
V_107 ;
if ( V_4 != V_2 -> V_43 ) {
V_100 |=
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 ;
V_90 . V_46 = V_2 -> V_43 -> V_18 . V_46 ;
V_90 . V_117 = V_118 ;
V_90 . V_47 = V_2 -> V_43 -> V_18 . V_47 ;
V_90 . V_48 = V_2 -> V_43 -> V_18 . V_48 ;
V_90 . V_119 = V_118 ;
V_90 . V_49 = V_2 -> V_43 -> V_18 . V_49 ;
V_90 . V_50 = V_2 -> V_43 -> V_18 . V_50 ;
V_90 . V_51 = V_2 -> V_43 -> V_18 . V_51 ;
V_90 . V_52 = V_2 -> V_43 -> V_18 . V_52 ;
#if 0
if (test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags))
rec.join_state = 4;
#endif
}
V_86 = F_56 ( & V_120 , V_2 -> V_81 , V_2 -> V_66 ,
& V_90 , V_100 , V_25 ,
F_51 , V_4 ) ;
if ( F_37 ( V_86 ) ) {
V_33 = F_38 ( V_86 ) ;
F_32 ( V_2 , L_13 , V_33 ) ;
F_26 ( & V_2 -> V_44 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
F_35 ( V_97 , & V_4 -> V_7 ) ;
F_27 ( & V_2 -> V_44 ) ;
F_53 ( & V_4 -> V_98 ) ;
}
}
void F_57 ( struct V_76 * V_77 )
{
struct V_1 * V_2 =
F_41 ( V_77 , struct V_1 , V_8 . V_77 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_79 V_121 ;
unsigned long V_11 = 0 ;
struct V_3 * V_4 = NULL ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
if ( F_42 ( V_2 -> V_81 , V_2 -> V_66 , & V_121 ) ||
V_121 . V_82 != V_83 ) {
F_43 ( V_2 , L_14 ,
V_121 . V_82 ) ;
return;
}
V_2 -> V_122 = V_121 . V_123 ;
if ( F_58 ( V_2 -> V_81 , V_2 -> V_66 , 0 , & V_2 -> V_102 ) )
F_32 ( V_2 , L_15 ) ;
else
memcpy ( V_2 -> V_16 -> V_124 + 4 , V_2 -> V_102 . V_20 , sizeof ( union V_34 ) ) ;
F_26 ( & V_2 -> V_44 ) ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
goto V_89;
if ( ! V_2 -> V_43 ) {
struct V_3 * V_43 ;
V_43 = F_16 ( V_16 , 0 ) ;
if ( ! V_43 ) {
F_32 ( V_2 , L_16 ) ;
F_1 ( V_2 , NULL , 1 ) ;
goto V_89;
}
memcpy ( V_43 -> V_18 . V_19 . V_20 , V_2 -> V_16 -> V_43 + 4 ,
sizeof ( union V_34 ) ) ;
V_2 -> V_43 = V_43 ;
F_22 ( V_16 , V_2 -> V_43 ) ;
}
if ( ! F_2 ( V_60 , & V_2 -> V_43 -> V_7 ) ) {
if ( F_59 ( V_2 -> V_43 -> V_96 ) &&
! F_2 ( V_97 , & V_2 -> V_43 -> V_7 ) ) {
V_4 = V_2 -> V_43 ;
if ( V_4 -> V_9 > 1 &&
F_60 ( V_12 , V_4 -> V_11 ) ) {
V_11 = V_4 -> V_11 ;
V_4 = NULL ;
}
}
goto V_89;
}
F_61 (mcast, &priv->multicast_list, list) {
if ( F_59 ( V_4 -> V_96 ) &&
! F_2 ( V_97 , & V_4 -> V_7 ) &&
( ! F_2 ( V_59 , & V_4 -> V_7 ) ||
! F_10 ( & V_4 -> V_22 ) ) ) {
if ( V_4 -> V_9 == 1 ||
F_62 ( V_12 , V_4 -> V_11 ) ) {
F_63 ( & V_4 -> V_98 ) ;
F_64 ( V_97 , & V_4 -> V_7 ) ;
F_27 ( & V_2 -> V_44 ) ;
F_54 ( V_16 , V_4 ) ;
F_26 ( & V_2 -> V_44 ) ;
} else if ( ! V_11 ||
F_60 ( V_4 -> V_11 , V_11 ) )
V_11 = V_4 -> V_11 ;
}
}
V_4 = NULL ;
F_6 ( V_2 , L_17 ) ;
V_89:
if ( V_11 ) {
F_3 ( & V_2 -> V_8 ) ;
F_4 ( V_2 -> V_14 , & V_2 -> V_8 ,
V_11 - V_12 ) ;
}
if ( V_4 ) {
F_63 ( & V_4 -> V_98 ) ;
F_64 ( V_97 , & V_4 -> V_7 ) ;
}
F_27 ( & V_2 -> V_44 ) ;
if ( V_4 )
F_54 ( V_16 , V_4 ) ;
}
int F_65 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_7 ;
F_6 ( V_2 , L_18 ) ;
F_66 ( & V_2 -> V_44 , V_7 ) ;
F_1 ( V_2 , NULL , 0 ) ;
F_67 ( & V_2 -> V_44 , V_7 ) ;
return 0 ;
}
int F_68 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_7 ;
F_6 ( V_2 , L_19 ) ;
F_66 ( & V_2 -> V_44 , V_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
F_67 ( & V_2 -> V_44 , V_7 ) ;
F_69 ( V_2 -> V_14 ) ;
return 0 ;
}
int F_70 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
int V_33 = 0 ;
if ( F_71 ( V_97 , & V_4 -> V_7 ) )
F_32 ( V_2 , L_20 ) ;
if ( ! F_59 ( V_4 -> V_96 ) )
F_72 ( V_4 -> V_96 ) ;
if ( F_71 ( V_60 , & V_4 -> V_7 ) ) {
F_6 ( V_2 , L_21 ,
V_4 -> V_18 . V_19 . V_20 ) ;
V_33 = F_73 ( V_2 -> V_125 , & V_4 -> V_18 . V_19 ,
F_34 ( V_4 -> V_18 . V_61 ) ) ;
if ( V_33 )
F_32 ( V_2 , L_22 , V_33 ) ;
} else if ( ! F_2 ( V_59 , & V_4 -> V_7 ) )
F_43 ( V_2 , L_23
L_24 ) ;
return 0 ;
}
void F_74 ( struct V_15 * V_16 , T_2 * V_126 , struct V_74 * V_75 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_3 * V_4 ;
unsigned long V_7 ;
void * V_19 = V_126 + 4 ;
F_66 ( & V_2 -> V_44 , V_7 ) ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) ||
! V_2 -> V_43 ||
! F_2 ( V_60 , & V_2 -> V_43 -> V_7 ) ) {
++ V_16 -> V_23 . V_17 ;
F_11 ( V_75 ) ;
goto V_127;
}
V_4 = F_20 ( V_16 , V_19 ) ;
if ( ! V_4 || ! V_4 -> V_21 ) {
if ( ! V_4 ) {
F_6 ( V_2 , L_25 ,
V_19 ) ;
V_4 = F_16 ( V_16 , 0 ) ;
if ( ! V_4 ) {
F_32 ( V_2 , L_26
L_27 ) ;
++ V_16 -> V_23 . V_17 ;
F_11 ( V_75 ) ;
goto V_127;
}
F_64 ( V_59 , & V_4 -> V_7 ) ;
memcpy ( V_4 -> V_18 . V_19 . V_20 , V_19 ,
sizeof ( union V_34 ) ) ;
F_22 ( V_16 , V_4 ) ;
F_75 ( & V_4 -> V_28 , & V_2 -> V_128 ) ;
}
if ( F_76 ( & V_4 -> V_22 ) < V_129 )
F_77 ( & V_4 -> V_22 , V_75 ) ;
else {
++ V_16 -> V_23 . V_17 ;
F_11 ( V_75 ) ;
}
if ( ! F_2 ( V_97 , & V_4 -> V_7 ) ) {
F_1 ( V_2 , NULL , 0 ) ;
}
} else {
struct V_130 * V_131 ;
F_67 ( & V_2 -> V_44 , V_7 ) ;
V_131 = F_78 ( V_16 , V_126 ) ;
F_66 ( & V_2 -> V_44 , V_7 ) ;
if ( ! V_131 ) {
V_131 = F_79 ( V_126 , V_16 ) ;
if ( V_131 ) {
F_80 ( & V_4 -> V_21 -> V_132 ) ;
V_131 -> V_21 = V_4 -> V_21 ;
F_75 ( & V_131 -> V_28 , & V_4 -> V_29 ) ;
}
}
F_67 ( & V_2 -> V_44 , V_7 ) ;
F_81 ( V_16 , V_75 , V_4 -> V_21 , V_133 ) ;
if ( V_131 )
F_82 ( V_131 ) ;
return;
}
V_127:
F_67 ( & V_2 -> V_44 , V_7 ) ;
}
void F_83 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_84 ( V_134 ) ;
struct V_3 * V_4 , * V_38 ;
unsigned long V_7 ;
F_6 ( V_2 , L_28 ) ;
F_66 ( & V_2 -> V_44 , V_7 ) ;
F_85 (mcast, tmcast, &priv->multicast_list, list) {
F_86 ( & V_4 -> V_28 ) ;
F_87 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_75 ( & V_4 -> V_28 , & V_134 ) ;
}
if ( V_2 -> V_43 ) {
F_87 ( & V_2 -> V_43 -> V_30 , & V_2 -> V_32 ) ;
F_75 ( & V_2 -> V_43 -> V_28 , & V_134 ) ;
V_2 -> V_43 = NULL ;
}
F_67 ( & V_2 -> V_44 , V_7 ) ;
F_85 (mcast, tmcast, &remove_list, list)
if ( F_2 ( V_97 , & V_4 -> V_7 ) )
F_88 ( & V_4 -> V_98 ) ;
F_85 (mcast, tmcast, &remove_list, list) {
F_70 ( V_16 , V_4 ) ;
F_5 ( V_4 ) ;
}
}
static int F_89 ( const T_2 * V_135 , const T_2 * V_43 )
{
if ( memcmp ( V_135 , V_43 , 6 ) )
return 0 ;
if ( memcmp ( V_135 + 7 , V_43 + 7 , 3 ) )
return 0 ;
return 1 ;
}
void F_90 ( struct V_76 * V_77 )
{
struct V_1 * V_2 =
F_41 ( V_77 , struct V_1 , V_136 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_137 * V_138 ;
struct V_3 * V_4 , * V_38 ;
F_84 ( V_134 ) ;
unsigned long V_7 ;
struct V_40 V_90 ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
F_6 ( V_2 , L_29 ) ;
F_91 ( V_7 ) ;
F_92 ( V_16 ) ;
F_93 ( & V_2 -> V_44 ) ;
F_61 (mcast, &priv->multicast_list, list)
F_35 ( V_139 , & V_4 -> V_7 ) ;
F_94 (ha, dev) {
union V_34 V_19 ;
if ( ! F_89 ( V_138 -> V_135 , V_16 -> V_43 ) )
continue;
memcpy ( V_19 . V_20 , V_138 -> V_135 + 4 , sizeof V_19 ) ;
V_4 = F_20 ( V_16 , & V_19 ) ;
if ( ! V_4 || F_2 ( V_59 , & V_4 -> V_7 ) ) {
struct V_3 * V_140 ;
if ( F_2 ( V_141 , & V_2 -> V_7 ) &&
! F_95 ( V_2 -> V_81 , V_2 -> V_66 , & V_19 , & V_90 ) ) {
F_6 ( V_2 , L_30 ,
V_19 . V_20 ) ;
continue;
}
F_6 ( V_2 , L_31 ,
V_19 . V_20 ) ;
V_140 = F_16 ( V_16 , 0 ) ;
if ( ! V_140 ) {
F_32 ( V_2 , L_32 ) ;
continue;
}
F_64 ( V_139 , & V_140 -> V_7 ) ;
V_140 -> V_18 . V_19 = V_19 ;
if ( V_4 ) {
F_96 ( & V_4 -> V_28 , & V_134 ) ;
F_97 ( & V_4 -> V_30 ,
& V_140 -> V_30 ,
& V_2 -> V_32 ) ;
} else
F_22 ( V_16 , V_140 ) ;
F_75 ( & V_140 -> V_28 , & V_2 -> V_128 ) ;
}
if ( V_4 )
F_64 ( V_139 , & V_4 -> V_7 ) ;
}
F_85 (mcast, tmcast, &priv->multicast_list, list) {
if ( ! F_2 ( V_139 , & V_4 -> V_7 ) &&
! F_2 ( V_59 , & V_4 -> V_7 ) ) {
F_6 ( V_2 , L_1 ,
V_4 -> V_18 . V_19 . V_20 ) ;
F_87 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_96 ( & V_4 -> V_28 , & V_134 ) ;
}
}
F_98 ( & V_2 -> V_44 ) ;
F_99 ( V_16 ) ;
F_100 ( V_7 ) ;
F_85 (mcast, tmcast, &remove_list, list)
if ( F_2 ( V_97 , & V_4 -> V_7 ) )
F_88 ( & V_4 -> V_98 ) ;
F_85 (mcast, tmcast, &remove_list, list) {
F_70 ( V_4 -> V_16 , V_4 ) ;
F_5 ( V_4 ) ;
}
if ( F_2 ( V_6 , & V_2 -> V_7 ) ) {
F_66 ( & V_2 -> V_44 , V_7 ) ;
F_1 ( V_2 , NULL , 0 ) ;
F_67 ( & V_2 -> V_44 , V_7 ) ;
}
}
struct V_142 * F_101 ( struct V_15 * V_16 )
{
struct V_142 * V_143 ;
V_143 = F_102 ( sizeof *V_143 , V_25 ) ;
if ( ! V_143 )
return NULL ;
V_143 -> V_16 = V_16 ;
memset ( V_143 -> V_19 . V_20 , 0 , 16 ) ;
if ( F_103 ( V_143 ) ) {
F_15 ( V_143 ) ;
return NULL ;
}
return V_143 ;
}
int F_103 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = F_7 ( V_143 -> V_16 ) ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_33 = 1 ;
F_26 ( & V_2 -> V_44 ) ;
V_31 = F_104 ( & V_2 -> V_32 ) ;
while ( V_31 ) {
V_4 = F_21 ( V_31 , struct V_3 , V_30 ) ;
if ( memcmp ( V_143 -> V_19 . V_20 , V_4 -> V_18 . V_19 . V_20 ,
sizeof ( union V_34 ) ) < 0 ) {
V_143 -> V_19 = V_4 -> V_18 . V_19 ;
V_143 -> V_27 = V_4 -> V_27 ;
V_143 -> V_144 = F_76 ( & V_4 -> V_22 ) ;
V_143 -> F_53 = ! ! V_4 -> V_21 ;
V_143 -> V_145 = ! ! ( V_4 -> V_7 & ( 1 << V_59 ) ) ;
V_33 = 0 ;
break;
}
V_31 = F_105 ( V_31 ) ;
}
F_27 ( & V_2 -> V_44 ) ;
return V_33 ;
}
void F_106 ( struct V_142 * V_143 ,
union V_34 * V_19 ,
unsigned long * V_27 ,
unsigned int * V_144 ,
unsigned int * F_53 ,
unsigned int * V_145 )
{
* V_19 = V_143 -> V_19 ;
* V_27 = V_143 -> V_27 ;
* V_144 = V_143 -> V_144 ;
* F_53 = V_143 -> F_53 ;
* V_145 = V_143 -> V_145 ;
}
