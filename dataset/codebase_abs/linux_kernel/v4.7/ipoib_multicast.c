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
static void F_5 ( struct V_3 * V_4 )
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
static struct V_3 * F_20 ( struct V_15 * V_16 , void * V_19 )
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
V_2 -> V_55 . V_56 = V_2 -> V_46 ;
V_42 = 1 ;
}
if ( ! F_2 ( V_57 , & V_4 -> V_7 ) ) {
if ( F_31 ( V_58 , & V_4 -> V_7 ) ) {
F_32 ( V_2 , L_2 ,
V_4 -> V_18 . V_19 . V_20 ) ;
return 0 ;
}
V_33 = F_33 ( V_16 , F_34 ( V_4 -> V_18 . V_59 ) ,
& V_4 -> V_18 . V_19 , V_42 ) ;
if ( V_33 < 0 ) {
F_32 ( V_2 , L_3 ,
V_4 -> V_18 . V_19 . V_20 ) ;
F_35 ( V_58 , & V_4 -> V_7 ) ;
return V_33 ;
}
}
{
struct V_60 V_61 = {
. V_62 = F_34 ( V_4 -> V_18 . V_59 ) ,
. V_63 = V_2 -> V_64 ,
. V_50 = V_4 -> V_18 . V_50 ,
. V_65 = V_66 ,
. V_67 = V_4 -> V_18 . V_49 ,
. V_68 = {
. V_51 = F_30 ( V_4 -> V_18 . V_51 ) ,
. V_52 = V_4 -> V_18 . V_52 ,
. V_69 = 0 ,
. V_48 = V_4 -> V_18 . V_48
}
} ;
V_61 . V_68 . V_70 = V_4 -> V_18 . V_19 ;
V_21 = F_36 ( V_16 , V_2 -> V_71 , & V_61 ) ;
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
F_34 ( V_4 -> V_18 . V_59 ) ,
V_4 -> V_18 . V_50 ) ;
}
}
F_13 ( V_16 ) ;
while ( ! F_10 ( & V_4 -> V_22 ) ) {
struct V_72 * V_73 = F_12 ( & V_4 -> V_22 ) ;
F_14 ( V_16 ) ;
V_73 -> V_16 = V_16 ;
if ( F_39 ( V_73 ) )
F_32 ( V_2 , L_6 ) ;
F_13 ( V_16 ) ;
}
F_14 ( V_16 ) ;
return 0 ;
}
void F_40 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_41 ( V_75 , struct V_1 ,
V_76 ) ;
struct V_77 V_78 ;
int V_33 ;
if ( F_42 ( V_2 -> V_79 , V_2 -> V_64 , & V_78 ) ||
V_78 . V_80 != V_81 ) {
F_43 ( V_2 , L_7 ) ;
return;
}
V_33 = F_44 ( V_2 ) ;
if ( V_33 < 0 )
F_45 ( L_8 ,
V_2 -> V_16 -> V_82 , V_33 ) ;
while ( ! F_46 () ) {
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
else
F_47 ( 20 ) ;
}
if ( ! F_48 ( V_2 -> V_16 ) )
F_49 ( V_2 -> V_16 , F_50 ( V_2 -> V_53 , V_2 -> V_54 ) ) ;
F_51 ( V_2 -> V_16 ) ;
F_52 () ;
}
static int F_53 ( int V_83 ,
struct V_84 * V_85 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_6 ( V_2 , L_9 ,
F_2 ( V_57 , & V_4 -> V_7 ) ?
L_10 : L_11 ,
V_4 -> V_18 . V_19 . V_20 , V_83 ) ;
if ( V_83 == - V_87 ) {
V_83 = 0 ;
goto V_88;
}
if ( ! V_83 )
V_83 = F_25 ( V_4 , & V_85 -> V_89 ) ;
if ( ! V_83 ) {
V_4 -> V_9 = 1 ;
V_4 -> V_11 = V_12 ;
if ( V_4 == V_2 -> V_43 ) {
F_26 ( & V_2 -> V_44 ) ;
F_54 ( V_2 -> V_14 , & V_2 -> V_76 ) ;
F_1 ( V_2 , NULL , 0 ) ;
goto V_90;
}
} else {
bool V_91 =
F_2 ( V_57 , & V_4 -> V_7 ) &&
V_83 == - V_92 ;
if ( V_4 -> V_93 < 20 ) {
if ( V_83 == - V_94 || V_83 == - V_45 ||
V_91 ) {
F_6 ( V_2 , L_12 ,
F_2 ( V_57 , & V_4 -> V_7 ) ? L_10 : L_11 ,
V_4 -> V_18 . V_19 . V_20 , V_83 ) ;
} else {
F_32 ( V_2 , L_12 ,
F_2 ( V_57 , & V_4 -> V_7 ) ? L_10 : L_11 ,
V_4 -> V_18 . V_19 . V_20 , V_83 ) ;
}
if ( ! V_91 )
V_4 -> V_93 ++ ;
}
if ( F_2 ( V_57 , & V_4 -> V_7 ) &&
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
goto V_90;
}
}
V_88:
F_26 ( & V_2 -> V_44 ) ;
V_90:
if ( V_83 )
V_4 -> V_95 = NULL ;
else
V_4 -> V_95 = V_85 ;
F_35 ( V_96 , & V_4 -> V_7 ) ;
F_27 ( & V_2 -> V_44 ) ;
F_55 ( & V_4 -> V_97 ) ;
return V_83 ;
}
static int F_56 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_84 * V_85 ;
struct V_40 V_89 = {
. V_98 = 1
} ;
T_1 V_99 ;
int V_33 = 0 ;
if ( ! V_2 -> V_43 ||
! F_2 ( V_6 , & V_2 -> V_7 ) )
return - V_92 ;
F_6 ( V_2 , L_13 , V_4 -> V_18 . V_19 . V_20 ) ;
V_89 . V_19 = V_4 -> V_18 . V_19 ;
V_89 . V_100 = V_2 -> V_101 ;
V_89 . V_102 = F_57 ( V_2 -> V_102 ) ;
V_99 =
V_103 |
V_104 |
V_105 |
V_106 ;
if ( V_4 != V_2 -> V_43 ) {
V_99 |=
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 ;
V_89 . V_46 = V_2 -> V_43 -> V_18 . V_46 ;
V_89 . V_116 = V_117 ;
V_89 . V_47 = V_2 -> V_43 -> V_18 . V_47 ;
V_89 . V_48 = V_2 -> V_43 -> V_18 . V_48 ;
V_89 . V_118 = V_117 ;
V_89 . V_49 = V_2 -> V_43 -> V_18 . V_49 ;
V_89 . V_50 = V_2 -> V_43 -> V_18 . V_50 ;
V_89 . V_51 = V_2 -> V_43 -> V_18 . V_51 ;
V_89 . V_52 = V_2 -> V_43 -> V_18 . V_52 ;
if ( F_2 ( V_57 , & V_4 -> V_7 ) &&
V_2 -> V_119 )
V_89 . V_98 = V_120 ;
}
F_27 ( & V_2 -> V_44 ) ;
V_85 = F_58 ( & V_121 , V_2 -> V_79 , V_2 -> V_64 ,
& V_89 , V_99 , V_25 ,
F_53 , V_4 ) ;
F_26 ( & V_2 -> V_44 ) ;
if ( F_37 ( V_85 ) ) {
V_33 = F_38 ( V_85 ) ;
F_32 ( V_2 , L_14 , V_33 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
F_35 ( V_96 , & V_4 -> V_7 ) ;
F_27 ( & V_2 -> V_44 ) ;
F_55 ( & V_4 -> V_97 ) ;
F_26 ( & V_2 -> V_44 ) ;
}
return 0 ;
}
void F_59 ( struct V_74 * V_75 )
{
struct V_1 * V_2 =
F_41 ( V_75 , struct V_1 , V_8 . V_75 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_77 V_122 ;
unsigned long V_11 = 0 ;
struct V_3 * V_4 = NULL ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
if ( F_42 ( V_2 -> V_79 , V_2 -> V_64 , & V_122 ) ||
V_122 . V_80 != V_81 ) {
F_43 ( V_2 , L_15 ,
V_122 . V_80 ) ;
return;
}
V_2 -> V_123 = V_122 . V_124 ;
F_60 ( V_16 ) ;
if ( ! F_2 ( V_125 , & V_2 -> V_7 ) ) {
F_61 ( V_16 ) ;
return;
}
F_61 ( V_16 ) ;
F_26 ( & V_2 -> V_44 ) ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
goto V_88;
if ( ! V_2 -> V_43 ) {
struct V_3 * V_43 ;
V_43 = F_16 ( V_16 , 0 ) ;
if ( ! V_43 ) {
F_32 ( V_2 , L_16 ) ;
F_1 ( V_2 , NULL , 1 ) ;
goto V_88;
}
memcpy ( V_43 -> V_18 . V_19 . V_20 , V_2 -> V_16 -> V_43 + 4 ,
sizeof ( union V_34 ) ) ;
V_2 -> V_43 = V_43 ;
F_22 ( V_16 , V_2 -> V_43 ) ;
}
if ( ! F_2 ( V_58 , & V_2 -> V_43 -> V_7 ) ) {
if ( F_62 ( V_2 -> V_43 -> V_95 ) &&
! F_2 ( V_96 , & V_2 -> V_43 -> V_7 ) ) {
V_4 = V_2 -> V_43 ;
if ( V_4 -> V_9 > 1 &&
F_63 ( V_12 , V_4 -> V_11 ) ) {
V_11 = V_4 -> V_11 ;
V_4 = NULL ;
}
}
goto V_88;
}
F_64 (mcast, &priv->multicast_list, list) {
if ( F_62 ( V_4 -> V_95 ) &&
! F_2 ( V_96 , & V_4 -> V_7 ) &&
( ! F_2 ( V_57 , & V_4 -> V_7 ) ||
! F_10 ( & V_4 -> V_22 ) ) ) {
if ( V_4 -> V_9 == 1 ||
F_65 ( V_12 , V_4 -> V_11 ) ) {
F_66 ( & V_4 -> V_97 ) ;
F_67 ( V_96 , & V_4 -> V_7 ) ;
if ( F_56 ( V_16 , V_4 ) ) {
F_27 ( & V_2 -> V_44 ) ;
return;
}
} else if ( ! V_11 ||
F_63 ( V_4 -> V_11 , V_11 ) )
V_11 = V_4 -> V_11 ;
}
}
V_4 = NULL ;
F_6 ( V_2 , L_17 ) ;
V_88:
if ( V_11 ) {
F_3 ( & V_2 -> V_8 ) ;
F_4 ( V_2 -> V_14 , & V_2 -> V_8 ,
V_11 - V_12 ) ;
}
if ( V_4 ) {
F_66 ( & V_4 -> V_97 ) ;
F_67 ( V_96 , & V_4 -> V_7 ) ;
F_56 ( V_16 , V_4 ) ;
}
F_27 ( & V_2 -> V_44 ) ;
}
int F_68 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_7 ;
F_6 ( V_2 , L_18 ) ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
F_1 ( V_2 , NULL , 0 ) ;
F_70 ( & V_2 -> V_44 , V_7 ) ;
return 0 ;
}
int F_71 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_7 ;
F_6 ( V_2 , L_19 ) ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
F_70 ( & V_2 -> V_44 , V_7 ) ;
F_72 ( V_2 -> V_14 ) ;
return 0 ;
}
static int F_73 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
int V_33 = 0 ;
if ( F_74 ( V_96 , & V_4 -> V_7 ) )
F_32 ( V_2 , L_20 ) ;
if ( ! F_62 ( V_4 -> V_95 ) )
F_75 ( V_4 -> V_95 ) ;
if ( F_74 ( V_58 , & V_4 -> V_7 ) ) {
F_6 ( V_2 , L_21 ,
V_4 -> V_18 . V_19 . V_20 ) ;
V_33 = F_76 ( V_2 -> V_126 , & V_4 -> V_18 . V_19 ,
F_34 ( V_4 -> V_18 . V_59 ) ) ;
if ( V_33 )
F_32 ( V_2 , L_22 , V_33 ) ;
} else if ( ! F_2 ( V_57 , & V_4 -> V_7 ) )
F_43 ( V_2 , L_23
L_24 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 , T_2 * V_19 ,
struct V_127 * V_128 )
{
if ( * V_19 == 0xff ) {
struct V_3 * V_4 = F_20 ( V_2 -> V_16 , V_19 ) ;
if ( V_4 && F_2 ( V_57 , & V_4 -> V_7 ) ) {
F_78 ( & V_4 -> V_28 ) ;
F_79 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_80 ( & V_4 -> V_28 , V_128 ) ;
}
}
}
void F_81 ( struct V_127 * V_128 )
{
struct V_3 * V_4 , * V_38 ;
F_82 (mcast, tmcast, remove_list, list) {
F_73 ( V_4 -> V_16 , V_4 ) ;
F_5 ( V_4 ) ;
}
}
void F_83 ( struct V_15 * V_16 , T_2 * V_129 , struct V_72 * V_73 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_3 * V_4 ;
unsigned long V_7 ;
void * V_19 = V_129 + 4 ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) ||
! V_2 -> V_43 ||
! F_2 ( V_58 , & V_2 -> V_43 -> V_7 ) ) {
++ V_16 -> V_23 . V_17 ;
F_11 ( V_73 ) ;
goto V_130;
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
F_11 ( V_73 ) ;
goto V_130;
}
F_67 ( V_57 , & V_4 -> V_7 ) ;
memcpy ( V_4 -> V_18 . V_19 . V_20 , V_19 ,
sizeof ( union V_34 ) ) ;
F_22 ( V_16 , V_4 ) ;
F_80 ( & V_4 -> V_28 , & V_2 -> V_131 ) ;
}
if ( F_84 ( & V_4 -> V_22 ) < V_132 )
F_85 ( & V_4 -> V_22 , V_73 ) ;
else {
++ V_16 -> V_23 . V_17 ;
F_11 ( V_73 ) ;
}
if ( ! F_2 ( V_96 , & V_4 -> V_7 ) ) {
F_1 ( V_2 , NULL , 0 ) ;
}
} else {
struct V_133 * V_134 ;
F_70 ( & V_2 -> V_44 , V_7 ) ;
V_134 = F_86 ( V_16 , V_129 ) ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
if ( ! V_134 ) {
V_134 = F_87 ( V_129 , V_16 ) ;
if ( V_134 ) {
F_88 ( & V_4 -> V_21 -> V_135 ) ;
V_134 -> V_21 = V_4 -> V_21 ;
F_80 ( & V_134 -> V_28 , & V_4 -> V_29 ) ;
}
}
F_70 ( & V_2 -> V_44 , V_7 ) ;
F_89 ( V_16 , V_73 , V_4 -> V_21 , V_136 ) ;
if ( V_134 )
F_90 ( V_134 ) ;
return;
}
V_130:
F_70 ( & V_2 -> V_44 , V_7 ) ;
}
void F_91 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_92 ( V_128 ) ;
struct V_3 * V_4 , * V_38 ;
unsigned long V_7 ;
F_6 ( V_2 , L_28 ) ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
F_82 (mcast, tmcast, &priv->multicast_list, list) {
F_78 ( & V_4 -> V_28 ) ;
F_79 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_80 ( & V_4 -> V_28 , & V_128 ) ;
}
if ( V_2 -> V_43 ) {
F_79 ( & V_2 -> V_43 -> V_30 , & V_2 -> V_32 ) ;
F_80 ( & V_2 -> V_43 -> V_28 , & V_128 ) ;
V_2 -> V_43 = NULL ;
}
F_70 ( & V_2 -> V_44 , V_7 ) ;
F_82 (mcast, tmcast, &remove_list, list)
if ( F_2 ( V_96 , & V_4 -> V_7 ) )
F_93 ( & V_4 -> V_97 ) ;
F_81 ( & V_128 ) ;
}
static int F_94 ( const T_2 * V_137 , const T_2 * V_43 )
{
if ( memcmp ( V_137 , V_43 , 6 ) )
return 0 ;
if ( memcmp ( V_137 + 7 , V_43 + 7 , 3 ) )
return 0 ;
return 1 ;
}
void F_95 ( struct V_74 * V_75 )
{
struct V_1 * V_2 =
F_41 ( V_75 , struct V_1 , V_138 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_139 * V_140 ;
struct V_3 * V_4 , * V_38 ;
F_92 ( V_128 ) ;
unsigned long V_7 ;
struct V_40 V_89 ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
F_6 ( V_2 , L_29 ) ;
F_96 ( V_7 ) ;
F_97 ( V_16 ) ;
F_98 ( & V_2 -> V_44 ) ;
F_64 (mcast, &priv->multicast_list, list)
F_35 ( V_141 , & V_4 -> V_7 ) ;
F_99 (ha, dev) {
union V_34 V_19 ;
if ( ! F_94 ( V_140 -> V_137 , V_16 -> V_43 ) )
continue;
memcpy ( V_19 . V_20 , V_140 -> V_137 + 4 , sizeof V_19 ) ;
V_4 = F_20 ( V_16 , & V_19 ) ;
if ( ! V_4 || F_2 ( V_57 , & V_4 -> V_7 ) ) {
struct V_3 * V_142 ;
if ( F_2 ( V_143 , & V_2 -> V_7 ) &&
! F_100 ( V_2 -> V_79 , V_2 -> V_64 , & V_19 , & V_89 ) ) {
F_6 ( V_2 , L_30 ,
V_19 . V_20 ) ;
continue;
}
F_6 ( V_2 , L_31 ,
V_19 . V_20 ) ;
V_142 = F_16 ( V_16 , 0 ) ;
if ( ! V_142 ) {
F_32 ( V_2 , L_32 ) ;
continue;
}
F_67 ( V_141 , & V_142 -> V_7 ) ;
V_142 -> V_18 . V_19 = V_19 ;
if ( V_4 ) {
F_101 ( & V_4 -> V_28 , & V_128 ) ;
F_102 ( & V_4 -> V_30 ,
& V_142 -> V_30 ,
& V_2 -> V_32 ) ;
} else
F_22 ( V_16 , V_142 ) ;
F_80 ( & V_142 -> V_28 , & V_2 -> V_131 ) ;
}
if ( V_4 )
F_67 ( V_141 , & V_4 -> V_7 ) ;
}
F_82 (mcast, tmcast, &priv->multicast_list, list) {
if ( ! F_2 ( V_141 , & V_4 -> V_7 ) &&
! F_2 ( V_57 , & V_4 -> V_7 ) ) {
F_6 ( V_2 , L_1 ,
V_4 -> V_18 . V_19 . V_20 ) ;
F_79 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_101 ( & V_4 -> V_28 , & V_128 ) ;
}
}
F_103 ( & V_2 -> V_44 ) ;
F_104 ( V_16 ) ;
F_105 ( V_7 ) ;
F_82 (mcast, tmcast, &remove_list, list)
if ( F_2 ( V_96 , & V_4 -> V_7 ) )
F_93 ( & V_4 -> V_97 ) ;
F_81 ( & V_128 ) ;
if ( F_2 ( V_6 , & V_2 -> V_7 ) ) {
F_69 ( & V_2 -> V_44 , V_7 ) ;
F_1 ( V_2 , NULL , 0 ) ;
F_70 ( & V_2 -> V_44 , V_7 ) ;
}
}
struct V_144 * F_106 ( struct V_15 * V_16 )
{
struct V_144 * V_145 ;
V_145 = F_107 ( sizeof *V_145 , V_25 ) ;
if ( ! V_145 )
return NULL ;
V_145 -> V_16 = V_16 ;
memset ( V_145 -> V_19 . V_20 , 0 , 16 ) ;
if ( F_108 ( V_145 ) ) {
F_15 ( V_145 ) ;
return NULL ;
}
return V_145 ;
}
int F_108 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = F_7 ( V_145 -> V_16 ) ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_33 = 1 ;
F_26 ( & V_2 -> V_44 ) ;
V_31 = F_109 ( & V_2 -> V_32 ) ;
while ( V_31 ) {
V_4 = F_21 ( V_31 , struct V_3 , V_30 ) ;
if ( memcmp ( V_145 -> V_19 . V_20 , V_4 -> V_18 . V_19 . V_20 ,
sizeof ( union V_34 ) ) < 0 ) {
V_145 -> V_19 = V_4 -> V_18 . V_19 ;
V_145 -> V_27 = V_4 -> V_27 ;
V_145 -> V_146 = F_84 ( & V_4 -> V_22 ) ;
V_145 -> F_55 = ! ! V_4 -> V_21 ;
V_145 -> V_147 = ! ! ( V_4 -> V_7 & ( 1 << V_57 ) ) ;
V_33 = 0 ;
break;
}
V_31 = F_110 ( V_31 ) ;
}
F_27 ( & V_2 -> V_44 ) ;
return V_33 ;
}
void F_111 ( struct V_144 * V_145 ,
union V_34 * V_19 ,
unsigned long * V_27 ,
unsigned int * V_146 ,
unsigned int * F_55 ,
unsigned int * V_147 )
{
* V_19 = V_145 -> V_19 ;
* V_27 = V_145 -> V_27 ;
* V_146 = V_145 -> V_146 ;
* F_55 = V_145 -> F_55 ;
* V_147 = V_145 -> V_147 ;
}
