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
V_33 = F_39 ( V_73 ) ;
if ( V_33 )
F_32 ( V_2 , L_6 ,
V_74 , V_33 ) ;
F_13 ( V_16 ) ;
}
F_14 ( V_16 ) ;
return 0 ;
}
void F_40 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_41 ( V_76 , struct V_1 ,
V_77 ) ;
struct V_78 V_79 ;
int V_33 ;
if ( F_42 ( V_2 -> V_80 , V_2 -> V_64 , & V_79 ) ||
V_79 . V_81 != V_82 ) {
F_43 ( V_2 , L_7 ) ;
return;
}
V_33 = F_44 ( V_2 ) ;
if ( V_33 < 0 )
F_45 ( L_8 ,
V_2 -> V_16 -> V_83 , V_33 ) ;
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
static int F_53 ( int V_84 ,
struct V_85 * V_86 )
{
struct V_3 * V_4 = V_86 -> V_87 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_6 ( V_2 , L_9 ,
F_2 ( V_57 , & V_4 -> V_7 ) ?
L_10 : L_11 ,
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
F_54 ( V_2 -> V_14 , & V_2 -> V_77 ) ;
F_1 ( V_2 , NULL , 0 ) ;
goto V_91;
}
} else {
bool V_92 =
F_2 ( V_57 , & V_4 -> V_7 ) &&
V_84 == - V_93 ;
if ( V_4 -> V_94 < 20 ) {
if ( V_84 == - V_95 || V_84 == - V_45 ||
V_92 ) {
F_6 ( V_2 , L_12 ,
F_2 ( V_57 , & V_4 -> V_7 ) ? L_10 : L_11 ,
V_4 -> V_18 . V_19 . V_20 , V_84 ) ;
} else {
F_32 ( V_2 , L_12 ,
F_2 ( V_57 , & V_4 -> V_7 ) ? L_10 : L_11 ,
V_4 -> V_18 . V_19 . V_20 , V_84 ) ;
}
if ( ! V_92 )
V_4 -> V_94 ++ ;
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
F_55 ( & V_4 -> V_98 ) ;
return V_84 ;
}
static int F_56 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_85 * V_86 ;
struct V_40 V_90 = {
. V_99 = 1
} ;
T_1 V_100 ;
int V_33 = 0 ;
if ( ! V_2 -> V_43 ||
! F_2 ( V_6 , & V_2 -> V_7 ) )
return - V_93 ;
F_6 ( V_2 , L_13 , V_4 -> V_18 . V_19 . V_20 ) ;
V_90 . V_19 = V_4 -> V_18 . V_19 ;
V_90 . V_101 = V_2 -> V_102 ;
V_90 . V_103 = F_57 ( V_2 -> V_103 ) ;
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
if ( F_2 ( V_57 , & V_4 -> V_7 ) &&
V_2 -> V_120 )
V_90 . V_99 = V_121 ;
}
F_27 ( & V_2 -> V_44 ) ;
V_86 = F_58 ( & V_122 , V_2 -> V_80 , V_2 -> V_64 ,
& V_90 , V_100 , V_25 ,
F_53 , V_4 ) ;
F_26 ( & V_2 -> V_44 ) ;
if ( F_37 ( V_86 ) ) {
V_33 = F_38 ( V_86 ) ;
F_32 ( V_2 , L_14 , V_33 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
F_35 ( V_97 , & V_4 -> V_7 ) ;
F_27 ( & V_2 -> V_44 ) ;
F_55 ( & V_4 -> V_98 ) ;
F_26 ( & V_2 -> V_44 ) ;
}
return 0 ;
}
void F_59 ( struct V_75 * V_76 )
{
struct V_1 * V_2 =
F_41 ( V_76 , struct V_1 , V_8 . V_76 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_78 V_123 ;
unsigned long V_11 = 0 ;
struct V_3 * V_4 = NULL ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
if ( F_42 ( V_2 -> V_80 , V_2 -> V_64 , & V_123 ) ) {
F_43 ( V_2 , L_15 ) ;
return;
}
if ( V_123 . V_81 != V_82 ) {
F_43 ( V_2 , L_16 ,
V_123 . V_81 ) ;
return;
}
V_2 -> V_124 = V_123 . V_125 ;
F_60 ( V_16 ) ;
if ( ! F_2 ( V_126 , & V_2 -> V_7 ) ) {
F_61 ( V_16 ) ;
return;
}
F_61 ( V_16 ) ;
F_26 ( & V_2 -> V_44 ) ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
goto V_89;
if ( ! V_2 -> V_43 ) {
struct V_3 * V_43 ;
V_43 = F_16 ( V_16 , 0 ) ;
if ( ! V_43 ) {
F_32 ( V_2 , L_17 ) ;
F_1 ( V_2 , NULL , 1 ) ;
goto V_89;
}
memcpy ( V_43 -> V_18 . V_19 . V_20 , V_2 -> V_16 -> V_43 + 4 ,
sizeof ( union V_34 ) ) ;
V_2 -> V_43 = V_43 ;
F_22 ( V_16 , V_2 -> V_43 ) ;
}
if ( ! F_2 ( V_58 , & V_2 -> V_43 -> V_7 ) ) {
if ( F_62 ( V_2 -> V_43 -> V_96 ) &&
! F_2 ( V_97 , & V_2 -> V_43 -> V_7 ) ) {
V_4 = V_2 -> V_43 ;
if ( V_4 -> V_9 > 1 &&
F_63 ( V_12 , V_4 -> V_11 ) ) {
V_11 = V_4 -> V_11 ;
V_4 = NULL ;
}
}
goto V_89;
}
F_64 (mcast, &priv->multicast_list, list) {
if ( F_62 ( V_4 -> V_96 ) &&
! F_2 ( V_97 , & V_4 -> V_7 ) &&
( ! F_2 ( V_57 , & V_4 -> V_7 ) ||
! F_10 ( & V_4 -> V_22 ) ) ) {
if ( V_4 -> V_9 == 1 ||
F_65 ( V_12 , V_4 -> V_11 ) ) {
F_66 ( & V_4 -> V_98 ) ;
F_67 ( V_97 , & V_4 -> V_7 ) ;
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
F_6 ( V_2 , L_18 ) ;
V_89:
if ( V_11 ) {
F_3 ( & V_2 -> V_8 ) ;
F_4 ( V_2 -> V_14 , & V_2 -> V_8 ,
V_11 - V_12 ) ;
}
if ( V_4 ) {
F_66 ( & V_4 -> V_98 ) ;
F_67 ( V_97 , & V_4 -> V_7 ) ;
F_56 ( V_16 , V_4 ) ;
}
F_27 ( & V_2 -> V_44 ) ;
}
void F_68 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_7 ;
F_6 ( V_2 , L_19 ) ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
F_1 ( V_2 , NULL , 0 ) ;
F_70 ( & V_2 -> V_44 , V_7 ) ;
}
int F_71 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_7 ;
F_6 ( V_2 , L_20 ) ;
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
if ( F_74 ( V_97 , & V_4 -> V_7 ) )
F_32 ( V_2 , L_21 ) ;
if ( ! F_62 ( V_4 -> V_96 ) )
F_75 ( V_4 -> V_96 ) ;
if ( F_74 ( V_58 , & V_4 -> V_7 ) ) {
F_6 ( V_2 , L_22 ,
V_4 -> V_18 . V_19 . V_20 ) ;
V_33 = F_76 ( V_2 -> V_127 , & V_4 -> V_18 . V_19 ,
F_34 ( V_4 -> V_18 . V_59 ) ) ;
if ( V_33 )
F_32 ( V_2 , L_23 , V_33 ) ;
} else if ( ! F_2 ( V_57 , & V_4 -> V_7 ) )
F_43 ( V_2 , L_24
L_25 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 , T_2 * V_19 ,
struct V_128 * V_129 )
{
if ( * V_19 == 0xff ) {
struct V_3 * V_4 = F_20 ( V_2 -> V_16 , V_19 ) ;
if ( V_4 && F_2 ( V_57 , & V_4 -> V_7 ) ) {
F_78 ( & V_4 -> V_28 ) ;
F_79 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_80 ( & V_4 -> V_28 , V_129 ) ;
}
}
}
void F_81 ( struct V_128 * V_129 )
{
struct V_3 * V_4 , * V_38 ;
F_82 (mcast, tmcast, remove_list, list) {
F_73 ( V_4 -> V_16 , V_4 ) ;
F_5 ( V_4 ) ;
}
}
void F_83 ( struct V_15 * V_16 , T_2 * V_130 , struct V_72 * V_73 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_3 * V_4 ;
unsigned long V_7 ;
void * V_19 = V_130 + 4 ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) ||
! V_2 -> V_43 ||
! F_2 ( V_58 , & V_2 -> V_43 -> V_7 ) ) {
++ V_16 -> V_23 . V_17 ;
F_11 ( V_73 ) ;
goto V_131;
}
V_4 = F_20 ( V_16 , V_19 ) ;
if ( ! V_4 || ! V_4 -> V_21 ) {
if ( ! V_4 ) {
F_6 ( V_2 , L_26 ,
V_19 ) ;
V_4 = F_16 ( V_16 , 0 ) ;
if ( ! V_4 ) {
F_32 ( V_2 , L_27
L_28 ) ;
++ V_16 -> V_23 . V_17 ;
F_11 ( V_73 ) ;
goto V_131;
}
F_67 ( V_57 , & V_4 -> V_7 ) ;
memcpy ( V_4 -> V_18 . V_19 . V_20 , V_19 ,
sizeof ( union V_34 ) ) ;
F_22 ( V_16 , V_4 ) ;
F_80 ( & V_4 -> V_28 , & V_2 -> V_132 ) ;
}
if ( F_84 ( & V_4 -> V_22 ) < V_133 ) {
F_85 ( V_73 , sizeof( struct V_134 ) ) ;
F_86 ( & V_4 -> V_22 , V_73 ) ;
} else {
++ V_16 -> V_23 . V_17 ;
F_11 ( V_73 ) ;
}
if ( ! F_2 ( V_97 , & V_4 -> V_7 ) ) {
F_1 ( V_2 , NULL , 0 ) ;
}
} else {
struct V_135 * V_136 ;
F_70 ( & V_2 -> V_44 , V_7 ) ;
V_136 = F_87 ( V_16 , V_130 ) ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
if ( ! V_136 ) {
V_136 = F_88 ( V_130 , V_16 ) ;
if ( V_136 ) {
F_89 ( & V_4 -> V_21 -> V_137 ) ;
V_136 -> V_21 = V_4 -> V_21 ;
F_80 ( & V_136 -> V_28 , & V_4 -> V_29 ) ;
}
}
F_70 ( & V_2 -> V_44 , V_7 ) ;
F_90 ( V_16 , V_73 , V_4 -> V_21 , V_138 ) ;
if ( V_136 )
F_91 ( V_136 ) ;
return;
}
V_131:
F_70 ( & V_2 -> V_44 , V_7 ) ;
}
void F_92 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_93 ( V_129 ) ;
struct V_3 * V_4 , * V_38 ;
unsigned long V_7 ;
F_6 ( V_2 , L_29 ) ;
F_69 ( & V_2 -> V_44 , V_7 ) ;
F_82 (mcast, tmcast, &priv->multicast_list, list) {
F_78 ( & V_4 -> V_28 ) ;
F_79 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_80 ( & V_4 -> V_28 , & V_129 ) ;
}
if ( V_2 -> V_43 ) {
F_79 ( & V_2 -> V_43 -> V_30 , & V_2 -> V_32 ) ;
F_80 ( & V_2 -> V_43 -> V_28 , & V_129 ) ;
V_2 -> V_43 = NULL ;
}
F_70 ( & V_2 -> V_44 , V_7 ) ;
F_82 (mcast, tmcast, &remove_list, list)
if ( F_2 ( V_97 , & V_4 -> V_7 ) )
F_94 ( & V_4 -> V_98 ) ;
F_81 ( & V_129 ) ;
}
static int F_95 ( const T_2 * V_139 , const T_2 * V_43 )
{
if ( memcmp ( V_139 , V_43 , 6 ) )
return 0 ;
if ( memcmp ( V_139 + 7 , V_43 + 7 , 3 ) )
return 0 ;
return 1 ;
}
void F_96 ( struct V_75 * V_76 )
{
struct V_1 * V_2 =
F_41 ( V_76 , struct V_1 , V_140 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_141 * V_142 ;
struct V_3 * V_4 , * V_38 ;
F_93 ( V_129 ) ;
unsigned long V_7 ;
struct V_40 V_90 ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
F_6 ( V_2 , L_30 ) ;
F_97 ( V_7 ) ;
F_98 ( V_16 ) ;
F_99 ( & V_2 -> V_44 ) ;
F_64 (mcast, &priv->multicast_list, list)
F_35 ( V_143 , & V_4 -> V_7 ) ;
F_100 (ha, dev) {
union V_34 V_19 ;
if ( ! F_95 ( V_142 -> V_139 , V_16 -> V_43 ) )
continue;
memcpy ( V_19 . V_20 , V_142 -> V_139 + 4 , sizeof V_19 ) ;
V_4 = F_20 ( V_16 , & V_19 ) ;
if ( ! V_4 || F_2 ( V_57 , & V_4 -> V_7 ) ) {
struct V_3 * V_144 ;
if ( F_2 ( V_145 , & V_2 -> V_7 ) &&
! F_101 ( V_2 -> V_80 , V_2 -> V_64 , & V_19 , & V_90 ) ) {
F_6 ( V_2 , L_31 ,
V_19 . V_20 ) ;
continue;
}
F_6 ( V_2 , L_32 ,
V_19 . V_20 ) ;
V_144 = F_16 ( V_16 , 0 ) ;
if ( ! V_144 ) {
F_32 ( V_2 , L_33 ) ;
continue;
}
F_67 ( V_143 , & V_144 -> V_7 ) ;
V_144 -> V_18 . V_19 = V_19 ;
if ( V_4 ) {
F_102 ( & V_4 -> V_28 , & V_129 ) ;
F_103 ( & V_4 -> V_30 ,
& V_144 -> V_30 ,
& V_2 -> V_32 ) ;
} else
F_22 ( V_16 , V_144 ) ;
F_80 ( & V_144 -> V_28 , & V_2 -> V_132 ) ;
}
if ( V_4 )
F_67 ( V_143 , & V_4 -> V_7 ) ;
}
F_82 (mcast, tmcast, &priv->multicast_list, list) {
if ( ! F_2 ( V_143 , & V_4 -> V_7 ) &&
! F_2 ( V_57 , & V_4 -> V_7 ) ) {
F_6 ( V_2 , L_1 ,
V_4 -> V_18 . V_19 . V_20 ) ;
F_79 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_102 ( & V_4 -> V_28 , & V_129 ) ;
}
}
F_104 ( & V_2 -> V_44 ) ;
F_105 ( V_16 ) ;
F_106 ( V_7 ) ;
F_82 (mcast, tmcast, &remove_list, list)
if ( F_2 ( V_97 , & V_4 -> V_7 ) )
F_94 ( & V_4 -> V_98 ) ;
F_81 ( & V_129 ) ;
if ( F_2 ( V_6 , & V_2 -> V_7 ) ) {
F_69 ( & V_2 -> V_44 , V_7 ) ;
F_1 ( V_2 , NULL , 0 ) ;
F_70 ( & V_2 -> V_44 , V_7 ) ;
}
}
struct V_146 * F_107 ( struct V_15 * V_16 )
{
struct V_146 * V_147 ;
V_147 = F_108 ( sizeof *V_147 , V_25 ) ;
if ( ! V_147 )
return NULL ;
V_147 -> V_16 = V_16 ;
memset ( V_147 -> V_19 . V_20 , 0 , 16 ) ;
if ( F_109 ( V_147 ) ) {
F_15 ( V_147 ) ;
return NULL ;
}
return V_147 ;
}
int F_109 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = F_7 ( V_147 -> V_16 ) ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_33 = 1 ;
F_26 ( & V_2 -> V_44 ) ;
V_31 = F_110 ( & V_2 -> V_32 ) ;
while ( V_31 ) {
V_4 = F_21 ( V_31 , struct V_3 , V_30 ) ;
if ( memcmp ( V_147 -> V_19 . V_20 , V_4 -> V_18 . V_19 . V_20 ,
sizeof ( union V_34 ) ) < 0 ) {
V_147 -> V_19 = V_4 -> V_18 . V_19 ;
V_147 -> V_27 = V_4 -> V_27 ;
V_147 -> V_148 = F_84 ( & V_4 -> V_22 ) ;
V_147 -> F_55 = ! ! V_4 -> V_21 ;
V_147 -> V_149 = ! ! ( V_4 -> V_7 & ( 1 << V_57 ) ) ;
V_33 = 0 ;
break;
}
V_31 = F_111 ( V_31 ) ;
}
F_27 ( & V_2 -> V_44 ) ;
return V_33 ;
}
void F_112 ( struct V_146 * V_147 ,
union V_34 * V_19 ,
unsigned long * V_27 ,
unsigned int * V_148 ,
unsigned int * F_55 ,
unsigned int * V_149 )
{
* V_19 = V_147 -> V_19 ;
* V_27 = V_147 -> V_27 ;
* V_148 = V_147 -> V_148 ;
* F_55 = V_147 -> F_55 ;
* V_149 = V_147 -> V_149 ;
}
