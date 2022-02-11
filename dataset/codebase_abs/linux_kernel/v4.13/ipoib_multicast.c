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
struct V_41 * V_42 = F_26 ( V_16 ) ;
struct V_43 * V_21 ;
struct V_44 V_45 ;
int V_33 ;
int V_46 = 0 ;
V_4 -> V_18 = * V_18 ;
if ( ! memcmp ( V_4 -> V_18 . V_19 . V_20 , V_2 -> V_16 -> V_47 + 4 ,
sizeof ( union V_34 ) ) ) {
F_27 ( & V_2 -> V_48 ) ;
if ( ! V_2 -> V_47 ) {
F_28 ( & V_2 -> V_48 ) ;
return - V_49 ;
}
V_2 -> V_47 -> V_18 . V_50 = V_18 -> V_50 ;
V_2 -> V_47 -> V_18 . V_51 = V_18 -> V_51 ;
V_2 -> V_47 -> V_18 . V_52 = V_18 -> V_52 ;
V_2 -> V_47 -> V_18 . V_53 = V_18 -> V_53 ;
V_2 -> V_47 -> V_18 . V_54 = V_18 -> V_54 ;
V_2 -> V_47 -> V_18 . V_55 = V_18 -> V_55 ;
V_2 -> V_47 -> V_18 . V_56 = V_18 -> V_56 ;
if ( V_2 -> V_57 == V_2 -> V_58 )
V_2 -> V_58 =
V_2 -> V_57 =
F_29 ( F_30 ( V_2 -> V_47 -> V_18 . V_51 ) ) ;
else
V_2 -> V_57 =
F_29 ( F_30 ( V_2 -> V_47 -> V_18 . V_51 ) ) ;
V_2 -> V_50 = F_31 ( V_2 -> V_47 -> V_18 . V_50 ) ;
F_28 ( & V_2 -> V_48 ) ;
V_2 -> V_59 . V_60 = V_2 -> V_50 ;
V_46 = 1 ;
}
if ( ! F_2 ( V_61 , & V_4 -> V_7 ) ) {
if ( F_32 ( V_62 , & V_4 -> V_7 ) ) {
F_33 ( V_2 , L_2 ,
V_4 -> V_18 . V_19 . V_20 ) ;
return 0 ;
}
V_33 = V_42 -> V_63 ( V_16 , V_2 -> V_64 , & V_4 -> V_18 . V_19 ,
F_34 ( V_4 -> V_18 . V_65 ) ,
V_46 , V_2 -> V_50 ) ;
if ( V_33 < 0 ) {
F_33 ( V_2 , L_3 ,
V_4 -> V_18 . V_19 . V_20 ) ;
F_35 ( V_62 , & V_4 -> V_7 ) ;
return V_33 ;
}
}
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . type = F_36 ( V_2 -> V_64 , V_2 -> V_66 ) ;
F_37 ( & V_45 , F_34 ( V_4 -> V_18 . V_65 ) ) ,
F_38 ( & V_45 , V_2 -> V_66 ) ;
F_39 ( & V_45 , V_4 -> V_18 . V_54 ) ;
F_40 ( & V_45 , V_4 -> V_18 . V_53 ) ;
F_41 ( & V_45 , & V_4 -> V_18 . V_19 ,
F_31 ( V_4 -> V_18 . V_55 ) ,
0 , V_4 -> V_18 . V_56 ,
V_4 -> V_18 . V_52 ) ;
V_21 = F_42 ( V_16 , V_2 -> V_67 , & V_45 ) ;
if ( F_43 ( V_21 ) ) {
F_33 ( V_2 , L_4 ,
- F_44 ( V_21 ) ) ;
return F_44 ( V_21 ) ;
}
F_27 ( & V_2 -> V_48 ) ;
V_4 -> V_21 = V_21 ;
F_28 ( & V_2 -> V_48 ) ;
F_6 ( V_2 , L_5 ,
V_4 -> V_18 . V_19 . V_20 ,
V_4 -> V_21 -> V_21 ,
F_34 ( V_4 -> V_18 . V_65 ) ,
V_4 -> V_18 . V_54 ) ;
F_13 ( V_16 ) ;
while ( ! F_10 ( & V_4 -> V_22 ) ) {
struct V_68 * V_69 = F_12 ( & V_4 -> V_22 ) ;
F_14 ( V_16 ) ;
V_69 -> V_16 = V_16 ;
V_33 = F_45 ( V_69 ) ;
if ( V_33 )
F_33 ( V_2 , L_6 ,
V_70 , V_33 ) ;
F_13 ( V_16 ) ;
}
F_14 ( V_16 ) ;
return 0 ;
}
void F_46 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_47 ( V_72 , struct V_1 ,
V_73 ) ;
struct V_74 V_75 ;
if ( F_48 ( V_2 -> V_64 , V_2 -> V_66 , & V_75 ) ||
V_75 . V_76 != V_77 ) {
F_49 ( V_2 , L_7 ) ;
return;
}
V_2 -> V_78 =
F_50 ( & V_79 ,
V_2 -> V_64 , V_2 -> V_66 ) ;
while ( ! F_51 () ) {
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
else
F_52 ( 20 ) ;
}
if ( ! F_53 ( V_2 -> V_16 ) )
F_54 ( V_2 -> V_16 , F_55 ( V_2 -> V_57 , V_2 -> V_58 ) ) ;
F_56 ( V_2 -> V_16 ) ;
F_57 () ;
}
static int F_58 ( int V_80 ,
struct V_81 * V_82 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_6 ( V_2 , L_8 ,
F_2 ( V_61 , & V_4 -> V_7 ) ?
L_9 : L_10 ,
V_4 -> V_18 . V_19 . V_20 , V_80 ) ;
if ( V_80 == - V_84 ) {
V_80 = 0 ;
goto V_85;
}
if ( ! V_80 )
V_80 = F_25 ( V_4 , & V_82 -> V_86 ) ;
if ( ! V_80 ) {
V_4 -> V_9 = 1 ;
V_4 -> V_11 = V_12 ;
if ( V_4 == V_2 -> V_47 ) {
F_27 ( & V_2 -> V_48 ) ;
F_59 ( V_2 -> V_14 , & V_2 -> V_73 ) ;
F_1 ( V_2 , NULL , 0 ) ;
goto V_87;
}
} else {
bool V_88 =
F_2 ( V_61 , & V_4 -> V_7 ) &&
V_80 == - V_89 ;
if ( V_4 -> V_90 < 20 ) {
if ( V_80 == - V_91 || V_80 == - V_49 ||
V_88 ) {
F_6 ( V_2 , L_11 ,
F_2 ( V_61 , & V_4 -> V_7 ) ? L_9 : L_10 ,
V_4 -> V_18 . V_19 . V_20 , V_80 ) ;
} else {
F_33 ( V_2 , L_11 ,
F_2 ( V_61 , & V_4 -> V_7 ) ? L_9 : L_10 ,
V_4 -> V_18 . V_19 . V_20 , V_80 ) ;
}
if ( ! V_88 )
V_4 -> V_90 ++ ;
}
if ( F_2 ( V_61 , & V_4 -> V_7 ) &&
V_4 -> V_9 >= 2 ) {
V_4 -> V_9 = 1 ;
F_13 ( V_16 ) ;
while ( ! F_10 ( & V_4 -> V_22 ) ) {
++ V_16 -> V_23 . V_17 ;
F_11 ( F_12 ( & V_4 -> V_22 ) ) ;
}
F_14 ( V_16 ) ;
} else {
F_27 ( & V_2 -> V_48 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
goto V_87;
}
}
V_85:
F_27 ( & V_2 -> V_48 ) ;
V_87:
if ( V_80 )
V_4 -> V_92 = NULL ;
else
V_4 -> V_92 = V_82 ;
F_35 ( V_93 , & V_4 -> V_7 ) ;
F_28 ( & V_2 -> V_48 ) ;
F_60 ( & V_4 -> V_94 ) ;
return V_80 ;
}
static int F_61 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_81 * V_82 ;
struct V_40 V_86 = {
. V_95 = 1
} ;
T_1 V_96 ;
int V_33 = 0 ;
if ( ! V_2 -> V_47 ||
! F_2 ( V_6 , & V_2 -> V_7 ) )
return - V_89 ;
F_62 ( & V_4 -> V_94 ) ;
F_63 ( V_93 , & V_4 -> V_7 ) ;
F_6 ( V_2 , L_12 , V_4 -> V_18 . V_19 . V_20 ) ;
V_86 . V_19 = V_4 -> V_18 . V_19 ;
V_86 . V_97 = V_2 -> V_98 ;
V_86 . V_99 = F_64 ( V_2 -> V_99 ) ;
V_96 =
V_100 |
V_101 |
V_102 |
V_103 ;
if ( V_4 != V_2 -> V_47 ) {
V_96 |=
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 ;
V_86 . V_50 = V_2 -> V_47 -> V_18 . V_50 ;
V_86 . V_113 = V_114 ;
V_86 . V_51 = V_2 -> V_47 -> V_18 . V_51 ;
V_86 . V_52 = V_2 -> V_47 -> V_18 . V_52 ;
V_86 . V_115 = V_114 ;
V_86 . V_53 = V_2 -> V_47 -> V_18 . V_53 ;
V_86 . V_54 = V_2 -> V_47 -> V_18 . V_54 ;
V_86 . V_55 = V_2 -> V_47 -> V_18 . V_55 ;
V_86 . V_56 = V_2 -> V_47 -> V_18 . V_56 ;
if ( F_2 ( V_61 , & V_4 -> V_7 ) &&
V_2 -> V_78 )
V_86 . V_95 = V_116 ;
}
F_28 ( & V_2 -> V_48 ) ;
V_82 = F_65 ( & V_79 , V_2 -> V_64 , V_2 -> V_66 ,
& V_86 , V_96 , V_25 ,
F_58 , V_4 ) ;
F_27 ( & V_2 -> V_48 ) ;
if ( F_43 ( V_82 ) ) {
V_33 = F_44 ( V_82 ) ;
F_33 ( V_2 , L_13 , V_33 ) ;
F_1 ( V_2 , V_4 , 1 ) ;
F_35 ( V_93 , & V_4 -> V_7 ) ;
F_28 ( & V_2 -> V_48 ) ;
F_60 ( & V_4 -> V_94 ) ;
F_27 ( & V_2 -> V_48 ) ;
}
return 0 ;
}
void F_66 ( struct V_71 * V_72 )
{
struct V_1 * V_2 =
F_47 ( V_72 , struct V_1 , V_8 . V_72 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_74 V_117 ;
unsigned long V_11 = 0 ;
struct V_3 * V_4 = NULL ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
if ( F_48 ( V_2 -> V_64 , V_2 -> V_66 , & V_117 ) ) {
F_49 ( V_2 , L_14 ) ;
return;
}
if ( V_117 . V_76 != V_77 ) {
F_49 ( V_2 , L_15 ,
V_117 . V_76 ) ;
return;
}
V_2 -> V_118 = V_117 . V_119 ;
F_67 ( V_16 ) ;
if ( ! F_2 ( V_120 , & V_2 -> V_7 ) ) {
F_68 ( V_16 ) ;
return;
}
F_68 ( V_16 ) ;
F_27 ( & V_2 -> V_48 ) ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
goto V_85;
if ( ! V_2 -> V_47 ) {
struct V_3 * V_47 ;
V_47 = F_16 ( V_16 , 0 ) ;
if ( ! V_47 ) {
F_33 ( V_2 , L_16 ) ;
F_1 ( V_2 , NULL , 1 ) ;
goto V_85;
}
memcpy ( V_47 -> V_18 . V_19 . V_20 , V_2 -> V_16 -> V_47 + 4 ,
sizeof ( union V_34 ) ) ;
V_2 -> V_47 = V_47 ;
F_22 ( V_16 , V_2 -> V_47 ) ;
}
if ( ! F_2 ( V_62 , & V_2 -> V_47 -> V_7 ) ) {
if ( F_69 ( V_2 -> V_47 -> V_92 ) &&
! F_2 ( V_93 , & V_2 -> V_47 -> V_7 ) ) {
V_4 = V_2 -> V_47 ;
if ( V_4 -> V_9 > 1 &&
F_70 ( V_12 , V_4 -> V_11 ) ) {
V_11 = V_4 -> V_11 ;
V_4 = NULL ;
}
}
goto V_85;
}
F_71 (mcast, &priv->multicast_list, list) {
if ( F_69 ( V_4 -> V_92 ) &&
! F_2 ( V_93 , & V_4 -> V_7 ) &&
( ! F_2 ( V_61 , & V_4 -> V_7 ) ||
! F_10 ( & V_4 -> V_22 ) ) ) {
if ( V_4 -> V_9 == 1 ||
F_72 ( V_12 , V_4 -> V_11 ) ) {
if ( F_61 ( V_16 , V_4 ) ) {
F_28 ( & V_2 -> V_48 ) ;
return;
}
} else if ( ! V_11 ||
F_70 ( V_4 -> V_11 , V_11 ) )
V_11 = V_4 -> V_11 ;
}
}
V_4 = NULL ;
F_6 ( V_2 , L_17 ) ;
V_85:
if ( V_11 ) {
F_3 ( & V_2 -> V_8 ) ;
F_4 ( V_2 -> V_14 , & V_2 -> V_8 ,
V_11 - V_12 ) ;
}
if ( V_4 )
F_61 ( V_16 , V_4 ) ;
F_28 ( & V_2 -> V_48 ) ;
}
void F_73 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_7 ;
F_6 ( V_2 , L_18 ) ;
F_74 ( & V_2 -> V_48 , V_7 ) ;
F_1 ( V_2 , NULL , 0 ) ;
F_75 ( & V_2 -> V_48 , V_7 ) ;
}
int F_76 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_6 ( V_2 , L_19 ) ;
F_77 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int F_78 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_41 * V_42 = F_26 ( V_16 ) ;
int V_33 = 0 ;
if ( F_79 ( V_93 , & V_4 -> V_7 ) )
F_33 ( V_2 , L_20 ) ;
if ( ! F_69 ( V_4 -> V_92 ) )
F_80 ( V_4 -> V_92 ) ;
if ( F_79 ( V_62 , & V_4 -> V_7 ) ) {
F_6 ( V_2 , L_21 ,
V_4 -> V_18 . V_19 . V_20 ) ;
V_33 = V_42 -> V_121 ( V_16 , V_2 -> V_64 , & V_4 -> V_18 . V_19 ,
F_34 ( V_4 -> V_18 . V_65 ) ) ;
if ( V_33 )
F_33 ( V_2 , L_22 , V_33 ) ;
} else if ( ! F_2 ( V_61 , & V_4 -> V_7 ) )
F_49 ( V_2 , L_23
L_24 ) ;
return 0 ;
}
void F_81 ( struct V_1 * V_2 , T_2 * V_19 ,
struct V_122 * V_123 )
{
if ( * V_19 == 0xff ) {
struct V_3 * V_4 = F_20 ( V_2 -> V_16 , V_19 ) ;
if ( V_4 && F_2 ( V_61 , & V_4 -> V_7 ) ) {
F_82 ( & V_4 -> V_28 ) ;
F_83 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_84 ( & V_4 -> V_28 , V_123 ) ;
}
}
}
void F_85 ( struct V_122 * V_123 )
{
struct V_3 * V_4 , * V_38 ;
F_86 (mcast, tmcast, remove_list, list)
if ( F_2 ( V_93 , & V_4 -> V_7 ) )
F_87 ( & V_4 -> V_94 ) ;
F_86 (mcast, tmcast, remove_list, list) {
F_78 ( V_4 -> V_16 , V_4 ) ;
F_5 ( V_4 ) ;
}
}
void F_88 ( struct V_15 * V_16 , T_2 * V_124 , struct V_68 * V_69 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_41 * V_42 = F_26 ( V_16 ) ;
struct V_3 * V_4 ;
unsigned long V_7 ;
void * V_19 = V_124 + 4 ;
F_74 ( & V_2 -> V_48 , V_7 ) ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) ||
! V_2 -> V_47 ||
! F_2 ( V_62 , & V_2 -> V_47 -> V_7 ) ) {
++ V_16 -> V_23 . V_17 ;
F_11 ( V_69 ) ;
goto V_125;
}
V_4 = F_20 ( V_16 , V_19 ) ;
if ( ! V_4 || ! V_4 -> V_21 ) {
if ( ! V_4 ) {
F_6 ( V_2 , L_25 ,
V_19 ) ;
V_4 = F_16 ( V_16 , 0 ) ;
if ( ! V_4 ) {
F_33 ( V_2 , L_26
L_27 ) ;
++ V_16 -> V_23 . V_17 ;
F_11 ( V_69 ) ;
goto V_125;
}
F_63 ( V_61 , & V_4 -> V_7 ) ;
memcpy ( V_4 -> V_18 . V_19 . V_20 , V_19 ,
sizeof ( union V_34 ) ) ;
F_22 ( V_16 , V_4 ) ;
F_84 ( & V_4 -> V_28 , & V_2 -> V_126 ) ;
}
if ( F_89 ( & V_4 -> V_22 ) < V_127 ) {
F_90 ( V_69 , sizeof( struct V_128 ) ) ;
F_91 ( & V_4 -> V_22 , V_69 ) ;
} else {
++ V_16 -> V_23 . V_17 ;
F_11 ( V_69 ) ;
}
if ( ! F_2 ( V_93 , & V_4 -> V_7 ) ) {
F_1 ( V_2 , NULL , 0 ) ;
}
} else {
struct V_129 * V_130 ;
F_75 ( & V_2 -> V_48 , V_7 ) ;
V_130 = F_92 ( V_16 , V_124 ) ;
F_74 ( & V_2 -> V_48 , V_7 ) ;
if ( ! V_130 ) {
V_130 = F_93 ( V_124 , V_16 ) ;
if ( V_130 ) {
F_94 ( & V_4 -> V_21 -> V_131 ) ;
V_130 -> V_21 = V_4 -> V_21 ;
F_84 ( & V_130 -> V_28 , & V_4 -> V_29 ) ;
}
}
F_75 ( & V_2 -> V_48 , V_7 ) ;
V_4 -> V_21 -> V_132 = V_42 -> V_133 ( V_16 , V_69 , V_4 -> V_21 -> V_21 ,
V_134 ) ;
if ( V_130 )
F_95 ( V_130 ) ;
return;
}
V_125:
F_75 ( & V_2 -> V_48 , V_7 ) ;
}
void F_96 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
F_97 ( V_123 ) ;
struct V_3 * V_4 , * V_38 ;
unsigned long V_7 ;
F_98 ( & V_2 -> V_135 ) ;
F_6 ( V_2 , L_28 ) ;
F_74 ( & V_2 -> V_48 , V_7 ) ;
F_86 (mcast, tmcast, &priv->multicast_list, list) {
F_82 ( & V_4 -> V_28 ) ;
F_83 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_84 ( & V_4 -> V_28 , & V_123 ) ;
}
if ( V_2 -> V_47 ) {
F_83 ( & V_2 -> V_47 -> V_30 , & V_2 -> V_32 ) ;
F_84 ( & V_2 -> V_47 -> V_28 , & V_123 ) ;
V_2 -> V_47 = NULL ;
}
F_75 ( & V_2 -> V_48 , V_7 ) ;
F_85 ( & V_123 ) ;
F_99 ( & V_2 -> V_135 ) ;
}
static int F_100 ( const T_2 * V_136 , const T_2 * V_47 )
{
if ( memcmp ( V_136 , V_47 , 6 ) )
return 0 ;
if ( memcmp ( V_136 + 7 , V_47 + 7 , 3 ) )
return 0 ;
return 1 ;
}
void F_101 ( struct V_71 * V_72 )
{
struct V_1 * V_2 =
F_47 ( V_72 , struct V_1 , V_137 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_138 * V_139 ;
struct V_3 * V_4 , * V_38 ;
F_97 ( V_123 ) ;
unsigned long V_7 ;
struct V_40 V_86 ;
if ( ! F_2 ( V_6 , & V_2 -> V_7 ) )
return;
F_6 ( V_2 , L_29 ) ;
F_102 ( V_7 ) ;
F_103 ( V_16 ) ;
F_104 ( & V_2 -> V_48 ) ;
F_71 (mcast, &priv->multicast_list, list)
F_35 ( V_140 , & V_4 -> V_7 ) ;
F_105 (ha, dev) {
union V_34 V_19 ;
if ( ! F_100 ( V_139 -> V_136 , V_16 -> V_47 ) )
continue;
memcpy ( V_19 . V_20 , V_139 -> V_136 + 4 , sizeof V_19 ) ;
V_4 = F_20 ( V_16 , & V_19 ) ;
if ( ! V_4 || F_2 ( V_61 , & V_4 -> V_7 ) ) {
struct V_3 * V_141 ;
if ( F_2 ( V_142 , & V_2 -> V_7 ) &&
! F_106 ( V_2 -> V_64 , V_2 -> V_66 , & V_19 , & V_86 ) ) {
F_6 ( V_2 , L_30 ,
V_19 . V_20 ) ;
continue;
}
F_6 ( V_2 , L_31 ,
V_19 . V_20 ) ;
V_141 = F_16 ( V_16 , 0 ) ;
if ( ! V_141 ) {
F_33 ( V_2 , L_32 ) ;
continue;
}
F_63 ( V_140 , & V_141 -> V_7 ) ;
V_141 -> V_18 . V_19 = V_19 ;
if ( V_4 ) {
F_107 ( & V_4 -> V_28 , & V_123 ) ;
F_108 ( & V_4 -> V_30 ,
& V_141 -> V_30 ,
& V_2 -> V_32 ) ;
} else
F_22 ( V_16 , V_141 ) ;
F_84 ( & V_141 -> V_28 , & V_2 -> V_126 ) ;
}
if ( V_4 )
F_63 ( V_140 , & V_4 -> V_7 ) ;
}
F_86 (mcast, tmcast, &priv->multicast_list, list) {
if ( ! F_2 ( V_140 , & V_4 -> V_7 ) &&
! F_2 ( V_61 , & V_4 -> V_7 ) ) {
F_6 ( V_2 , L_1 ,
V_4 -> V_18 . V_19 . V_20 ) ;
F_83 ( & V_4 -> V_30 , & V_2 -> V_32 ) ;
F_107 ( & V_4 -> V_28 , & V_123 ) ;
}
}
F_109 ( & V_2 -> V_48 ) ;
F_110 ( V_16 ) ;
F_111 ( V_7 ) ;
F_85 ( & V_123 ) ;
if ( F_2 ( V_6 , & V_2 -> V_7 ) ) {
F_74 ( & V_2 -> V_48 , V_7 ) ;
F_1 ( V_2 , NULL , 0 ) ;
F_75 ( & V_2 -> V_48 , V_7 ) ;
}
}
struct V_143 * F_112 ( struct V_15 * V_16 )
{
struct V_143 * V_144 ;
V_144 = F_113 ( sizeof *V_144 , V_25 ) ;
if ( ! V_144 )
return NULL ;
V_144 -> V_16 = V_16 ;
memset ( V_144 -> V_19 . V_20 , 0 , 16 ) ;
if ( F_114 ( V_144 ) ) {
F_15 ( V_144 ) ;
return NULL ;
}
return V_144 ;
}
int F_114 ( struct V_143 * V_144 )
{
struct V_1 * V_2 = F_7 ( V_144 -> V_16 ) ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_33 = 1 ;
F_27 ( & V_2 -> V_48 ) ;
V_31 = F_115 ( & V_2 -> V_32 ) ;
while ( V_31 ) {
V_4 = F_21 ( V_31 , struct V_3 , V_30 ) ;
if ( memcmp ( V_144 -> V_19 . V_20 , V_4 -> V_18 . V_19 . V_20 ,
sizeof ( union V_34 ) ) < 0 ) {
V_144 -> V_19 = V_4 -> V_18 . V_19 ;
V_144 -> V_27 = V_4 -> V_27 ;
V_144 -> V_145 = F_89 ( & V_4 -> V_22 ) ;
V_144 -> F_60 = ! ! V_4 -> V_21 ;
V_144 -> V_146 = ! ! ( V_4 -> V_7 & ( 1 << V_61 ) ) ;
V_33 = 0 ;
break;
}
V_31 = F_116 ( V_31 ) ;
}
F_28 ( & V_2 -> V_48 ) ;
return V_33 ;
}
void F_117 ( struct V_143 * V_144 ,
union V_34 * V_19 ,
unsigned long * V_27 ,
unsigned int * V_145 ,
unsigned int * F_60 ,
unsigned int * V_146 )
{
* V_19 = V_144 -> V_19 ;
* V_27 = V_144 -> V_27 ;
* V_145 = V_144 -> V_145 ;
* F_60 = V_144 -> F_60 ;
* V_146 = V_144 -> V_146 ;
}
