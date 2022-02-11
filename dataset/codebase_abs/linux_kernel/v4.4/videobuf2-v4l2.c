static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( ! F_2 ( V_4 -> type ) )
return 0 ;
if ( NULL == V_4 -> V_5 . V_6 ) {
F_3 ( 1 , L_1
L_2 ) ;
return - V_7 ;
}
if ( V_4 -> V_8 < V_2 -> V_9 || V_4 -> V_8 > V_10 ) {
F_3 ( 1 , L_3
L_4 , V_2 -> V_9 , V_4 -> V_8 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
unsigned int V_8 ;
unsigned int V_11 ;
unsigned int V_12 ;
if ( ! F_5 ( V_4 -> type ) )
return 0 ;
if ( F_2 ( V_4 -> type ) ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_9 ; ++ V_12 ) {
V_8 = ( V_4 -> V_13 == V_14 ||
V_4 -> V_13 == V_15 )
? V_4 -> V_5 . V_6 [ V_12 ] . V_8
: V_2 -> V_6 [ V_12 ] . V_8 ;
V_11 = V_4 -> V_5 . V_6 [ V_12 ] . V_11
? V_4 -> V_5 . V_6 [ V_12 ] . V_11 : V_8 ;
if ( V_4 -> V_5 . V_6 [ V_12 ] . V_11 > V_8 )
return - V_7 ;
if ( V_4 -> V_5 . V_6 [ V_12 ] . V_16 > 0 &&
V_4 -> V_5 . V_6 [ V_12 ] . V_16 >= V_11 )
return - V_7 ;
}
} else {
V_8 = ( V_4 -> V_13 == V_14 )
? V_4 -> V_8 : V_2 -> V_6 [ 0 ] . V_8 ;
if ( V_4 -> V_11 > V_8 )
return - V_7 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , const void * V_17 )
{
const struct V_3 * V_4 = V_17 ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_20 ;
if ( V_21 -> V_22 ) {
if ( ( V_21 -> V_23 & V_24 ) ==
V_25 )
V_19 -> V_26 = V_4 -> V_26 ;
V_19 -> V_27 |= V_4 -> V_27 & V_28 ;
if ( V_4 -> V_27 & V_28 )
V_19 -> V_29 = V_4 -> V_29 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
static bool V_30 ;
if ( V_30 )
return;
V_30 = true ;
F_9 ( 1 ) ;
F_10 ( L_5 ) ;
if ( V_2 -> V_20 -> V_31 )
F_10 ( L_6 ) ;
else
F_10 ( L_7 ) ;
}
static int F_11 ( struct V_20 * V_21 , struct V_3 * V_4 ,
const char * V_32 )
{
if ( V_4 -> type != V_21 -> type ) {
F_3 ( 1 , L_8 , V_32 ) ;
return - V_7 ;
}
if ( V_4 -> V_33 >= V_21 -> V_34 ) {
F_3 ( 1 , L_9 , V_32 ) ;
return - V_7 ;
}
if ( V_21 -> V_35 [ V_4 -> V_33 ] == NULL ) {
F_3 ( 1 , L_10 , V_32 ) ;
return - V_7 ;
}
if ( V_4 -> V_13 != V_21 -> V_13 ) {
F_3 ( 1 , L_11 , V_32 ) ;
return - V_7 ;
}
return F_1 ( V_21 -> V_35 [ V_4 -> V_33 ] , V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 , void * V_17 )
{
struct V_3 * V_4 = V_17 ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_20 ;
unsigned int V_12 ;
V_4 -> V_33 = V_2 -> V_33 ;
V_4 -> type = V_2 -> type ;
V_4 -> V_13 = V_2 -> V_13 ;
V_4 -> V_11 = 0 ;
V_4 -> V_27 = V_19 -> V_27 ;
V_4 -> V_36 = V_19 -> V_36 ;
V_4 -> V_26 = V_19 -> V_26 ;
V_4 -> V_29 = V_19 -> V_29 ;
V_4 -> V_37 = V_19 -> V_37 ;
V_4 -> V_38 = 0 ;
V_4 -> V_39 = 0 ;
if ( V_21 -> V_40 ) {
V_4 -> V_8 = V_2 -> V_9 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_9 ; ++ V_12 ) {
struct V_41 * V_42 = & V_4 -> V_5 . V_6 [ V_12 ] ;
struct V_43 * V_44 = & V_2 -> V_6 [ V_12 ] ;
V_42 -> V_11 = V_44 -> V_11 ;
V_42 -> V_8 = V_44 -> V_8 ;
if ( V_21 -> V_13 == V_45 )
V_42 -> V_5 . V_46 = V_44 -> V_5 . V_47 ;
else if ( V_21 -> V_13 == V_14 )
V_42 -> V_5 . V_48 = V_44 -> V_5 . V_48 ;
else if ( V_21 -> V_13 == V_15 )
V_42 -> V_5 . V_49 = V_44 -> V_5 . V_49 ;
V_42 -> V_16 = V_44 -> V_16 ;
memset ( V_42 -> V_39 , 0 , sizeof( V_42 -> V_39 ) ) ;
}
} else {
V_4 -> V_8 = V_2 -> V_6 [ 0 ] . V_8 ;
V_4 -> V_11 = V_2 -> V_6 [ 0 ] . V_11 ;
if ( V_21 -> V_13 == V_45 )
V_4 -> V_5 . V_47 = V_2 -> V_6 [ 0 ] . V_5 . V_47 ;
else if ( V_21 -> V_13 == V_14 )
V_4 -> V_5 . V_48 = V_2 -> V_6 [ 0 ] . V_5 . V_48 ;
else if ( V_21 -> V_13 == V_15 )
V_4 -> V_5 . V_49 = V_2 -> V_6 [ 0 ] . V_5 . V_49 ;
}
V_4 -> V_27 &= ~ V_50 ;
V_4 -> V_27 |= V_21 -> V_23 & V_24 ;
if ( ( V_21 -> V_23 & V_24 ) !=
V_25 ) {
V_4 -> V_27 &= ~ V_51 ;
V_4 -> V_27 |= V_21 -> V_23 & V_51 ;
}
switch ( V_2 -> V_52 ) {
case V_53 :
case V_54 :
V_4 -> V_27 |= V_55 ;
break;
case V_56 :
V_4 -> V_27 |= V_57 ;
case V_58 :
V_4 -> V_27 |= V_59 ;
break;
case V_60 :
V_4 -> V_27 |= V_61 ;
break;
case V_62 :
case V_63 :
case V_64 :
break;
}
if ( F_13 ( V_21 , V_2 ) )
V_4 -> V_27 |= V_65 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
const void * V_17 , struct V_43 * V_6 )
{
struct V_20 * V_21 = V_2 -> V_20 ;
const struct V_3 * V_4 = V_17 ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
unsigned int V_12 ;
int V_66 ;
V_66 = F_4 ( V_2 , V_4 ) ;
if ( V_66 < 0 ) {
F_3 ( 1 , L_12 , V_66 ) ;
return V_66 ;
}
if ( V_4 -> V_36 == V_67 && V_21 -> V_22 ) {
F_3 ( 1 , L_13
L_14 ) ;
return - V_7 ;
}
V_19 -> V_26 . V_68 = 0 ;
V_19 -> V_26 . V_69 = 0 ;
V_19 -> V_37 = 0 ;
if ( F_2 ( V_4 -> type ) ) {
if ( V_4 -> V_13 == V_14 ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_9 ; ++ V_12 ) {
V_6 [ V_12 ] . V_5 . V_48 =
V_4 -> V_5 . V_6 [ V_12 ] . V_5 . V_48 ;
V_6 [ V_12 ] . V_8 =
V_4 -> V_5 . V_6 [ V_12 ] . V_8 ;
}
}
if ( V_4 -> V_13 == V_15 ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_9 ; ++ V_12 ) {
V_6 [ V_12 ] . V_5 . V_49 =
V_4 -> V_5 . V_6 [ V_12 ] . V_5 . V_49 ;
V_6 [ V_12 ] . V_8 =
V_4 -> V_5 . V_6 [ V_12 ] . V_8 ;
}
}
if ( F_5 ( V_4 -> type ) ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_9 ; ++ V_12 ) {
struct V_43 * V_42 = & V_6 [ V_12 ] ;
struct V_41 * V_44 = & V_4 -> V_5 . V_6 [ V_12 ] ;
if ( V_44 -> V_11 == 0 )
F_8 ( V_2 ) ;
if ( V_2 -> V_20 -> V_31 )
V_42 -> V_11 = V_44 -> V_11 ;
else
V_42 -> V_11 = V_44 -> V_11 ?
V_44 -> V_11 : V_42 -> V_8 ;
V_42 -> V_16 = V_44 -> V_16 ;
}
}
} else {
if ( V_4 -> V_13 == V_14 ) {
V_6 [ 0 ] . V_5 . V_48 = V_4 -> V_5 . V_48 ;
V_6 [ 0 ] . V_8 = V_4 -> V_8 ;
}
if ( V_4 -> V_13 == V_15 ) {
V_6 [ 0 ] . V_5 . V_49 = V_4 -> V_5 . V_49 ;
V_6 [ 0 ] . V_8 = V_4 -> V_8 ;
}
if ( F_5 ( V_4 -> type ) ) {
if ( V_4 -> V_11 == 0 )
F_8 ( V_2 ) ;
if ( V_2 -> V_20 -> V_31 )
V_6 [ 0 ] . V_11 = V_4 -> V_11 ;
else
V_6 [ 0 ] . V_11 = V_4 -> V_11 ?
V_4 -> V_11 : V_6 [ 0 ] . V_8 ;
} else
V_6 [ 0 ] . V_11 = 0 ;
}
V_19 -> V_27 = V_4 -> V_27 & ~ V_50 ;
if ( ( V_2 -> V_20 -> V_23 & V_24 ) !=
V_25 || ! F_5 ( V_4 -> type ) ) {
V_19 -> V_27 &= ~ V_51 ;
}
if ( F_5 ( V_4 -> type ) ) {
V_19 -> V_27 &= ~ V_28 ;
V_19 -> V_36 = V_4 -> V_36 ;
} else {
V_19 -> V_27 &= ~ V_70 ;
}
return 0 ;
}
int F_15 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_66 ;
if ( V_4 -> type != V_21 -> type ) {
F_3 ( 1 , L_15 ) ;
return - V_7 ;
}
if ( V_4 -> V_33 >= V_21 -> V_34 ) {
F_3 ( 1 , L_16 ) ;
return - V_7 ;
}
V_2 = V_21 -> V_35 [ V_4 -> V_33 ] ;
V_66 = F_1 ( V_2 , V_4 ) ;
return V_66 ? V_66 : F_16 ( V_21 , V_4 -> V_33 , V_4 ) ;
}
int F_17 ( struct V_20 * V_21 , struct V_71 * V_72 )
{
int V_66 = F_18 ( V_21 , V_72 -> V_13 , V_72 -> type ) ;
return V_66 ? V_66 : F_19 ( V_21 , V_72 -> V_13 , & V_72 -> V_73 ) ;
}
int F_20 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
int V_66 ;
if ( F_21 ( V_21 ) ) {
F_3 ( 1 , L_17 ) ;
return - V_74 ;
}
V_66 = F_11 ( V_21 , V_4 , L_18 ) ;
return V_66 ? V_66 : F_22 ( V_21 , V_4 -> V_33 , V_4 ) ;
}
int F_23 ( struct V_20 * V_21 , struct V_75 * V_76 )
{
int V_66 = F_18 ( V_21 , V_76 -> V_13 ,
V_76 -> V_77 . type ) ;
V_76 -> V_33 = V_21 -> V_34 ;
if ( V_76 -> V_73 == 0 )
return V_66 != - V_74 ? V_66 : 0 ;
return V_66 ? V_66 : F_24 ( V_21 , V_76 -> V_13 ,
& V_76 -> V_73 , & V_76 -> V_77 ) ;
}
static int F_25 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
int V_66 = F_11 ( V_21 , V_4 , L_19 ) ;
return V_66 ? V_66 : F_26 ( V_21 , V_4 -> V_33 , V_4 ) ;
}
int F_27 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
if ( F_21 ( V_21 ) ) {
F_3 ( 1 , L_17 ) ;
return - V_74 ;
}
return F_25 ( V_21 , V_4 ) ;
}
static int F_28 ( struct V_20 * V_21 , struct V_3 * V_4 ,
bool V_78 )
{
int V_66 ;
if ( V_4 -> type != V_21 -> type ) {
F_3 ( 1 , L_20 ) ;
return - V_7 ;
}
V_66 = F_29 ( V_21 , V_4 , V_78 ) ;
if ( ! V_66 && ! V_21 -> V_22 &&
V_4 -> V_27 & V_79 )
V_21 -> V_80 = true ;
return V_66 ;
}
int F_30 ( struct V_20 * V_21 , struct V_3 * V_4 , bool V_78 )
{
if ( F_21 ( V_21 ) ) {
F_3 ( 1 , L_17 ) ;
return - V_74 ;
}
return F_28 ( V_21 , V_4 , V_78 ) ;
}
int F_31 ( struct V_20 * V_21 , enum V_81 type )
{
if ( F_21 ( V_21 ) ) {
F_3 ( 1 , L_17 ) ;
return - V_74 ;
}
return F_32 ( V_21 , type ) ;
}
int F_33 ( struct V_20 * V_21 , enum V_81 type )
{
if ( F_21 ( V_21 ) ) {
F_3 ( 1 , L_17 ) ;
return - V_74 ;
}
return F_34 ( V_21 , type ) ;
}
int F_35 ( struct V_20 * V_21 , struct V_82 * V_83 )
{
return F_36 ( V_21 , & V_83 -> V_49 , V_83 -> type , V_83 -> V_33 ,
V_83 -> V_12 , V_83 -> V_27 ) ;
}
int F_37 ( struct V_20 * V_21 )
{
if ( F_9 ( ! V_21 ) ||
F_9 ( V_21 -> V_23 &
~ ( V_24 |
V_51 ) ) )
return - V_7 ;
F_9 ( ( V_21 -> V_23 & V_24 ) ==
V_84 ) ;
if ( F_9 ( V_45 != ( int ) V_85 )
|| F_9 ( V_14 != ( int ) V_86 )
|| F_9 ( V_15 != ( int ) V_87 ) )
return - V_7 ;
if ( V_21 -> V_88 == 0 )
V_21 -> V_88 = sizeof( struct V_18 ) ;
V_21 -> V_89 = & V_90 ;
V_21 -> V_40 = F_2 ( V_21 -> type ) ;
V_21 -> V_22 = F_5 ( V_21 -> type ) ;
return F_38 ( V_21 ) ;
}
void F_39 ( struct V_20 * V_21 )
{
F_40 ( V_21 ) ;
F_41 ( V_21 ) ;
}
unsigned int F_42 ( struct V_20 * V_21 , struct V_91 * V_91 , T_1 * V_92 )
{
struct V_93 * V_94 = F_43 ( V_91 ) ;
unsigned long V_95 = F_44 ( V_92 ) ;
struct V_1 * V_2 = NULL ;
unsigned int V_96 = 0 ;
unsigned long V_27 ;
if ( F_45 ( V_97 , & V_94 -> V_27 ) ) {
struct V_98 * V_99 = V_91 -> V_100 ;
if ( F_46 ( V_99 ) )
V_96 = V_101 ;
else if ( V_95 & V_101 )
F_47 ( V_91 , & V_99 -> V_92 , V_92 ) ;
}
if ( ! V_21 -> V_22 && ! ( V_95 & ( V_102 | V_103 ) ) )
return V_96 ;
if ( V_21 -> V_22 && ! ( V_95 & ( V_104 | V_105 ) ) )
return V_96 ;
if ( V_21 -> V_34 == 0 && ! F_21 ( V_21 ) ) {
if ( ! V_21 -> V_22 && ( V_21 -> V_106 & V_107 ) &&
( V_95 & ( V_102 | V_103 ) ) ) {
if ( F_48 ( V_21 , 1 ) )
return V_96 | V_108 ;
}
if ( V_21 -> V_22 && ( V_21 -> V_106 & V_109 ) &&
( V_95 & ( V_104 | V_105 ) ) ) {
if ( F_48 ( V_21 , 0 ) )
return V_96 | V_108 ;
return V_96 | V_104 | V_105 ;
}
}
if ( ! F_49 ( V_21 ) || V_21 -> error )
return V_96 | V_108 ;
if ( V_21 -> V_110 )
return V_96 | V_108 ;
if ( V_21 -> V_22 && V_21 -> V_111 < V_21 -> V_34 )
return V_96 | V_104 | V_105 ;
if ( F_50 ( & V_21 -> V_112 ) ) {
if ( V_21 -> V_80 )
return V_96 | V_102 | V_103 ;
F_47 ( V_91 , & V_21 -> V_113 , V_92 ) ;
}
F_51 ( & V_21 -> V_114 , V_27 ) ;
if ( ! F_50 ( & V_21 -> V_112 ) )
V_2 = F_52 ( & V_21 -> V_112 , struct V_1 ,
V_115 ) ;
F_53 ( & V_21 -> V_114 , V_27 ) ;
if ( V_2 && ( V_2 -> V_52 == V_58
|| V_2 -> V_52 == V_56 ) ) {
return ( V_21 -> V_22 ) ?
V_96 | V_104 | V_105 :
V_96 | V_102 | V_103 ;
}
return V_96 ;
}
static int F_48 ( struct V_20 * V_21 , int V_116 )
{
struct V_117 * V_118 ;
int V_119 , V_66 ;
unsigned int V_73 = 0 ;
if ( F_9 ( ( V_116 && ! ( V_21 -> V_106 & V_107 ) ) ||
( ! V_116 && ! ( V_21 -> V_106 & V_109 ) ) ) )
return - V_7 ;
if ( ! V_21 -> V_120 -> V_121 )
return - V_74 ;
if ( V_21 -> V_122 || V_21 -> V_34 > 0 )
return - V_74 ;
V_73 = 1 ;
F_3 ( 3 , L_21 ,
( V_116 ) ? L_22 : L_23 , V_73 , V_21 -> V_123 ,
V_21 -> V_124 ) ;
V_118 = F_54 ( sizeof( struct V_117 ) , V_125 ) ;
if ( V_118 == NULL )
return - V_126 ;
V_118 -> V_127 = V_21 -> V_123 ;
V_118 -> V_128 = V_21 -> V_124 ;
V_118 -> V_72 . V_73 = V_73 ;
V_118 -> V_72 . V_13 = V_45 ;
V_118 -> V_72 . type = V_21 -> type ;
V_21 -> V_118 = V_118 ;
V_66 = F_19 ( V_21 , V_118 -> V_72 . V_13 , & V_118 -> V_72 . V_73 ) ;
if ( V_66 )
goto V_129;
if ( V_21 -> V_35 [ 0 ] -> V_9 != 1 ) {
V_66 = - V_74 ;
goto V_130;
}
for ( V_119 = 0 ; V_119 < V_21 -> V_34 ; V_119 ++ ) {
V_118 -> V_35 [ V_119 ] . V_121 = F_55 ( V_21 -> V_35 [ V_119 ] , 0 ) ;
if ( V_118 -> V_35 [ V_119 ] . V_121 == NULL ) {
V_66 = - V_7 ;
goto V_130;
}
V_118 -> V_35 [ V_119 ] . V_131 = F_56 ( V_21 -> V_35 [ V_119 ] , 0 ) ;
}
if ( V_116 ) {
bool V_40 = V_21 -> V_40 ;
for ( V_119 = 0 ; V_119 < V_21 -> V_34 ; V_119 ++ ) {
struct V_3 * V_4 = & V_118 -> V_4 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> type = V_21 -> type ;
if ( V_40 ) {
memset ( & V_118 -> V_132 , 0 , sizeof( V_118 -> V_132 ) ) ;
V_4 -> V_5 . V_6 = & V_118 -> V_132 ;
V_4 -> V_8 = 1 ;
}
V_4 -> V_13 = V_21 -> V_13 ;
V_4 -> V_33 = V_119 ;
V_66 = F_25 ( V_21 , V_4 ) ;
if ( V_66 )
goto V_130;
V_118 -> V_35 [ V_119 ] . V_133 = 1 ;
}
V_118 -> V_134 = V_21 -> V_34 ;
V_118 -> V_135 = V_21 -> V_34 ;
}
V_66 = F_32 ( V_21 , V_21 -> type ) ;
if ( V_66 )
goto V_130;
return V_66 ;
V_130:
V_118 -> V_72 . V_73 = 0 ;
F_19 ( V_21 , V_118 -> V_72 . V_13 , & V_118 -> V_72 . V_73 ) ;
V_129:
V_21 -> V_118 = NULL ;
F_57 ( V_118 ) ;
return V_66 ;
}
static int F_40 ( struct V_20 * V_21 )
{
struct V_117 * V_118 = V_21 -> V_118 ;
if ( V_118 ) {
F_34 ( V_21 , V_21 -> type ) ;
V_21 -> V_118 = NULL ;
V_118 -> V_72 . V_73 = 0 ;
F_17 ( V_21 , & V_118 -> V_72 ) ;
F_57 ( V_118 ) ;
F_3 ( 3 , L_24 ) ;
}
return 0 ;
}
static T_2 F_58 ( struct V_20 * V_21 , char T_3 * V_136 , T_2 V_73 ,
T_4 * V_137 , int V_138 , int V_116 )
{
struct V_117 * V_118 ;
struct V_139 * V_140 ;
bool V_40 = V_21 -> V_40 ;
bool V_141 = ! V_116 &&
( V_21 -> V_23 & V_24 ) ==
V_25 ;
int V_66 , V_33 ;
F_3 ( 3 , L_25 ,
V_116 ? L_22 : L_23 , ( long ) * V_137 , V_73 ,
V_138 ? L_26 : L_27 ) ;
if ( ! V_136 )
return - V_7 ;
if ( ! F_21 ( V_21 ) ) {
V_66 = F_48 ( V_21 , V_116 ) ;
F_3 ( 3 , L_28 , V_66 ) ;
if ( V_66 )
return V_66 ;
}
V_118 = V_21 -> V_118 ;
V_33 = V_118 -> V_135 ;
if ( V_33 >= V_21 -> V_34 ) {
memset ( & V_118 -> V_4 , 0 , sizeof( V_118 -> V_4 ) ) ;
V_118 -> V_4 . type = V_21 -> type ;
V_118 -> V_4 . V_13 = V_21 -> V_13 ;
if ( V_40 ) {
memset ( & V_118 -> V_132 , 0 , sizeof( V_118 -> V_132 ) ) ;
V_118 -> V_4 . V_5 . V_6 = & V_118 -> V_132 ;
V_118 -> V_4 . V_8 = 1 ;
}
V_66 = F_28 ( V_21 , & V_118 -> V_4 , V_138 ) ;
F_3 ( 5 , L_29 , V_66 ) ;
if ( V_66 )
return V_66 ;
V_118 -> V_142 += 1 ;
V_118 -> V_135 = V_33 = V_118 -> V_4 . V_33 ;
V_140 = & V_118 -> V_35 [ V_33 ] ;
V_140 -> V_143 = 0 ;
V_140 -> V_133 = 0 ;
V_140 -> V_131 = V_116 ? F_59 ( V_21 -> V_35 [ V_33 ] , 0 )
: F_56 ( V_21 -> V_35 [ V_33 ] , 0 ) ;
if ( V_40 && V_116 &&
V_118 -> V_4 . V_5 . V_6 [ 0 ] . V_16 < V_140 -> V_131 ) {
V_140 -> V_143 = V_118 -> V_4 . V_5 . V_6 [ 0 ] . V_16 ;
V_140 -> V_131 -= V_140 -> V_143 ;
}
} else {
V_140 = & V_118 -> V_35 [ V_33 ] ;
}
if ( V_140 -> V_143 + V_73 > V_140 -> V_131 ) {
V_73 = V_140 -> V_131 - V_140 -> V_143 ;
F_3 ( 5 , L_30 , V_73 ) ;
}
F_3 ( 3 , L_31 ,
V_73 , V_33 , V_140 -> V_143 ) ;
if ( V_116 )
V_66 = F_60 ( V_136 , V_140 -> V_121 + V_140 -> V_143 , V_73 ) ;
else
V_66 = F_61 ( V_140 -> V_121 + V_140 -> V_143 , V_136 , V_73 ) ;
if ( V_66 ) {
F_3 ( 3 , L_32 ) ;
return - V_144 ;
}
V_140 -> V_143 += V_73 ;
* V_137 += V_73 ;
if ( V_140 -> V_143 == V_140 -> V_131 || ( ! V_116 && V_118 -> V_128 ) ) {
if ( V_116 && V_118 -> V_127 && V_118 -> V_142 == 1 ) {
F_3 ( 3 , L_33 ) ;
return F_40 ( V_21 ) ;
}
memset ( & V_118 -> V_4 , 0 , sizeof( V_118 -> V_4 ) ) ;
V_118 -> V_4 . type = V_21 -> type ;
V_118 -> V_4 . V_13 = V_21 -> V_13 ;
V_118 -> V_4 . V_33 = V_33 ;
V_118 -> V_4 . V_11 = V_140 -> V_143 ;
if ( V_40 ) {
memset ( & V_118 -> V_132 , 0 , sizeof( V_118 -> V_132 ) ) ;
V_118 -> V_132 . V_11 = V_140 -> V_143 ;
V_118 -> V_4 . V_5 . V_6 = & V_118 -> V_132 ;
V_118 -> V_4 . V_8 = 1 ;
}
if ( V_141 )
F_62 ( & V_118 -> V_4 . V_26 ) ;
V_66 = F_25 ( V_21 , & V_118 -> V_4 ) ;
F_3 ( 5 , L_34 , V_66 ) ;
if ( V_66 )
return V_66 ;
V_140 -> V_143 = 0 ;
V_140 -> V_133 = 1 ;
V_140 -> V_131 = F_56 ( V_21 -> V_35 [ V_33 ] , 0 ) ;
V_118 -> V_145 += 1 ;
if ( V_118 -> V_134 < V_21 -> V_34 )
V_118 -> V_134 ++ ;
V_118 -> V_135 = V_118 -> V_134 ;
}
if ( V_66 == 0 )
V_66 = V_73 ;
return V_66 ;
}
T_2 F_63 ( struct V_20 * V_21 , char T_3 * V_136 , T_2 V_73 ,
T_4 * V_137 , int V_78 )
{
return F_58 ( V_21 , V_136 , V_73 , V_137 , V_78 , 1 ) ;
}
T_2 F_64 ( struct V_20 * V_21 , const char T_3 * V_136 , T_2 V_73 ,
T_4 * V_137 , int V_78 )
{
return F_58 ( V_21 , ( char T_3 * ) V_136 , V_73 ,
V_137 , V_78 , 0 ) ;
}
static int F_65 ( void * V_136 )
{
struct V_20 * V_21 = V_136 ;
struct V_146 * V_147 = V_21 -> V_147 ;
struct V_117 * V_118 = V_21 -> V_118 ;
bool V_141 = false ;
int V_148 = 0 ;
int V_33 = 0 ;
int V_66 = 0 ;
if ( V_21 -> V_22 ) {
V_148 = V_21 -> V_34 ;
V_141 =
( V_21 -> V_23 & V_24 ) ==
V_25 ;
}
F_66 () ;
for (; ; ) {
struct V_1 * V_2 ;
memset ( & V_118 -> V_4 , 0 , sizeof( V_118 -> V_4 ) ) ;
V_118 -> V_4 . type = V_21 -> type ;
V_118 -> V_4 . V_13 = V_21 -> V_13 ;
if ( V_148 ) {
V_118 -> V_4 . V_33 = V_33 ++ ;
V_148 -- ;
} else {
F_67 ( V_21 , V_149 , V_21 ) ;
if ( ! V_147 -> V_150 )
V_66 = F_28 ( V_21 , & V_118 -> V_4 , 0 ) ;
F_67 ( V_21 , V_151 , V_21 ) ;
F_3 ( 5 , L_35 , V_66 ) ;
}
if ( V_66 || V_147 -> V_150 )
break;
F_68 () ;
V_2 = V_21 -> V_35 [ V_118 -> V_4 . V_33 ] ;
if ( ! ( V_118 -> V_4 . V_27 & V_57 ) )
if ( V_147 -> V_152 ( V_2 , V_147 -> V_153 ) )
break;
F_67 ( V_21 , V_149 , V_21 ) ;
if ( V_141 )
F_62 ( & V_118 -> V_4 . V_26 ) ;
if ( ! V_147 -> V_150 )
V_66 = F_25 ( V_21 , & V_118 -> V_4 ) ;
F_67 ( V_21 , V_151 , V_21 ) ;
if ( V_66 || V_147 -> V_150 )
break;
}
while ( ! F_69 () ) {
F_70 ( V_154 ) ;
F_71 () ;
}
return 0 ;
}
int F_72 ( struct V_20 * V_21 , T_5 V_152 , void * V_153 ,
const char * V_155 )
{
struct V_146 * V_147 ;
int V_66 = 0 ;
if ( V_21 -> V_147 )
return - V_74 ;
if ( F_73 ( V_21 ) )
return - V_74 ;
if ( F_9 ( V_21 -> V_118 ) )
return - V_74 ;
V_147 = F_54 ( sizeof( * V_147 ) , V_125 ) ;
if ( V_147 == NULL )
return - V_126 ;
V_147 -> V_152 = V_152 ;
V_147 -> V_153 = V_153 ;
V_66 = F_48 ( V_21 , ! V_21 -> V_22 ) ;
F_3 ( 3 , L_36 , V_66 ) ;
if ( V_66 )
goto V_156;
V_21 -> V_147 = V_147 ;
V_147 -> V_157 = F_74 ( F_65 , V_21 , L_37 , V_155 ) ;
if ( F_75 ( V_147 -> V_157 ) ) {
V_66 = F_76 ( V_147 -> V_157 ) ;
V_147 -> V_157 = NULL ;
goto V_158;
}
return 0 ;
V_158:
F_40 ( V_21 ) ;
V_156:
F_57 ( V_147 ) ;
return V_66 ;
}
int F_77 ( struct V_20 * V_21 )
{
struct V_146 * V_147 = V_21 -> V_147 ;
int V_159 ;
if ( V_147 == NULL )
return 0 ;
V_147 -> V_150 = true ;
F_78 ( V_21 ) ;
V_159 = F_79 ( V_147 -> V_157 ) ;
F_40 ( V_21 ) ;
V_147 -> V_157 = NULL ;
F_57 ( V_147 ) ;
V_21 -> V_147 = NULL ;
return V_159 ;
}
static inline bool F_80 ( struct V_93 * V_160 , struct V_91 * V_91 )
{
return V_160 -> V_161 -> V_162 && V_160 -> V_161 -> V_162 != V_91 -> V_100 ;
}
int F_81 ( struct V_91 * V_91 , void * V_153 ,
struct V_71 * V_132 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
int V_96 = F_18 ( V_160 -> V_161 , V_132 -> V_13 , V_132 -> type ) ;
if ( V_96 )
return V_96 ;
if ( F_80 ( V_160 , V_91 ) )
return - V_74 ;
V_96 = F_19 ( V_160 -> V_161 , V_132 -> V_13 , & V_132 -> V_73 ) ;
if ( V_96 == 0 )
V_160 -> V_161 -> V_162 = V_132 -> V_73 ? V_91 -> V_100 : NULL ;
return V_96 ;
}
int F_82 ( struct V_91 * V_91 , void * V_153 ,
struct V_75 * V_132 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
int V_96 = F_18 ( V_160 -> V_161 , V_132 -> V_13 ,
V_132 -> V_77 . type ) ;
V_132 -> V_33 = V_160 -> V_161 -> V_34 ;
if ( V_132 -> V_73 == 0 )
return V_96 != - V_74 ? V_96 : 0 ;
if ( V_96 )
return V_96 ;
if ( F_80 ( V_160 , V_91 ) )
return - V_74 ;
V_96 = F_24 ( V_160 -> V_161 , V_132 -> V_13 , & V_132 -> V_73 ,
& V_132 -> V_77 ) ;
if ( V_96 == 0 )
V_160 -> V_161 -> V_162 = V_91 -> V_100 ;
return V_96 ;
}
int F_83 ( struct V_91 * V_91 , void * V_153 ,
struct V_3 * V_132 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
if ( F_80 ( V_160 , V_91 ) )
return - V_74 ;
return F_20 ( V_160 -> V_161 , V_132 ) ;
}
int F_84 ( struct V_91 * V_91 , void * V_153 , struct V_3 * V_132 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
return F_15 ( V_160 -> V_161 , V_132 ) ;
}
int F_85 ( struct V_91 * V_91 , void * V_153 , struct V_3 * V_132 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
if ( F_80 ( V_160 , V_91 ) )
return - V_74 ;
return F_27 ( V_160 -> V_161 , V_132 ) ;
}
int F_86 ( struct V_91 * V_91 , void * V_153 , struct V_3 * V_132 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
if ( F_80 ( V_160 , V_91 ) )
return - V_74 ;
return F_30 ( V_160 -> V_161 , V_132 , V_91 -> V_163 & V_164 ) ;
}
int F_87 ( struct V_91 * V_91 , void * V_153 , enum V_81 V_119 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
if ( F_80 ( V_160 , V_91 ) )
return - V_74 ;
return F_31 ( V_160 -> V_161 , V_119 ) ;
}
int F_88 ( struct V_91 * V_91 , void * V_153 , enum V_81 V_119 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
if ( F_80 ( V_160 , V_91 ) )
return - V_74 ;
return F_33 ( V_160 -> V_161 , V_119 ) ;
}
int F_89 ( struct V_91 * V_91 , void * V_153 , struct V_82 * V_132 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
if ( F_80 ( V_160 , V_91 ) )
return - V_74 ;
return F_35 ( V_160 -> V_161 , V_132 ) ;
}
int F_90 ( struct V_91 * V_91 , struct V_165 * V_166 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
return F_91 ( V_160 -> V_161 , V_166 ) ;
}
int F_92 ( struct V_91 * V_91 , struct V_167 * V_168 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
if ( V_168 )
F_93 ( V_168 ) ;
if ( V_91 -> V_100 == V_160 -> V_161 -> V_162 ) {
F_39 ( V_160 -> V_161 ) ;
V_160 -> V_161 -> V_162 = NULL ;
}
if ( V_168 )
F_94 ( V_168 ) ;
return F_95 ( V_91 ) ;
}
int F_96 ( struct V_91 * V_91 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
struct V_167 * V_168 = V_160 -> V_161 -> V_168 ? V_160 -> V_161 -> V_168 : V_160 -> V_168 ;
return F_92 ( V_91 , V_168 ) ;
}
T_6 F_97 ( struct V_91 * V_91 , const char T_3 * V_140 ,
T_2 V_73 , T_4 * V_137 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
struct V_167 * V_168 = V_160 -> V_161 -> V_168 ? V_160 -> V_161 -> V_168 : V_160 -> V_168 ;
int V_159 = - V_74 ;
if ( ! ( V_160 -> V_161 -> V_106 & V_109 ) )
return - V_7 ;
if ( V_168 && F_98 ( V_168 ) )
return - V_169 ;
if ( F_80 ( V_160 , V_91 ) )
goto exit;
V_159 = F_64 ( V_160 -> V_161 , V_140 , V_73 , V_137 ,
V_91 -> V_163 & V_164 ) ;
if ( V_160 -> V_161 -> V_118 )
V_160 -> V_161 -> V_162 = V_91 -> V_100 ;
exit:
if ( V_168 )
F_94 ( V_168 ) ;
return V_159 ;
}
T_6 F_99 ( struct V_91 * V_91 , char T_3 * V_140 ,
T_2 V_73 , T_4 * V_137 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
struct V_167 * V_168 = V_160 -> V_161 -> V_168 ? V_160 -> V_161 -> V_168 : V_160 -> V_168 ;
int V_159 = - V_74 ;
if ( ! ( V_160 -> V_161 -> V_106 & V_107 ) )
return - V_7 ;
if ( V_168 && F_98 ( V_168 ) )
return - V_169 ;
if ( F_80 ( V_160 , V_91 ) )
goto exit;
V_159 = F_63 ( V_160 -> V_161 , V_140 , V_73 , V_137 ,
V_91 -> V_163 & V_164 ) ;
if ( V_160 -> V_161 -> V_118 )
V_160 -> V_161 -> V_162 = V_91 -> V_100 ;
exit:
if ( V_168 )
F_94 ( V_168 ) ;
return V_159 ;
}
unsigned int F_100 ( struct V_91 * V_91 , T_1 * V_92 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
struct V_20 * V_21 = V_160 -> V_161 ;
struct V_167 * V_168 = V_21 -> V_168 ? V_21 -> V_168 : V_160 -> V_168 ;
unsigned V_96 ;
void * V_118 ;
F_9 ( ! V_168 ) ;
if ( V_168 && F_98 ( V_168 ) )
return V_108 ;
V_118 = V_21 -> V_118 ;
V_96 = F_42 ( V_160 -> V_161 , V_91 , V_92 ) ;
if ( ! V_118 && V_21 -> V_118 )
V_21 -> V_162 = V_91 -> V_100 ;
if ( V_168 )
F_94 ( V_168 ) ;
return V_96 ;
}
unsigned long F_101 ( struct V_91 * V_91 , unsigned long V_170 ,
unsigned long V_171 , unsigned long V_172 , unsigned long V_27 )
{
struct V_93 * V_160 = F_43 ( V_91 ) ;
return F_102 ( V_160 -> V_161 , V_170 , V_171 , V_172 , V_27 ) ;
}
void F_103 ( struct V_20 * V_173 )
{
F_94 ( V_173 -> V_168 ) ;
}
void F_104 ( struct V_20 * V_173 )
{
F_93 ( V_173 -> V_168 ) ;
}
