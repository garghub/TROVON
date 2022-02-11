int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = sizeof( struct V_6 ) * V_2 -> V_7 ;
V_2 -> V_8 = F_2 ( V_5 ) ;
if ( ! V_2 -> V_8 )
goto V_9;
F_3 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = V_2 -> V_7 * sizeof( struct V_11 ) ;
V_2 -> V_5 = F_4 ( V_2 -> V_5 , 4096 ) ;
V_2 -> V_12 = F_5 ( V_4 , V_2 -> V_5 ,
& V_2 -> V_13 , V_14 ) ;
if ( ! V_2 -> V_12 )
goto V_9;
return 0 ;
V_9:
F_6 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
return - V_15 ;
}
static int F_7 ( struct V_16 * V_17 )
{
int V_18 , V_9 = 0 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_9 = F_1 ( V_17 -> V_2 [ V_18 ] ) ;
if ( ! V_9 )
continue;
F_8 ( V_17 , V_20 , V_17 -> V_21 ,
L_1 , V_18 ) ;
goto V_22;
}
return 0 ;
V_22:
while ( V_18 -- )
F_9 ( V_17 -> V_2 [ V_18 ] ) ;
return V_9 ;
}
int F_10 ( struct V_1 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
int V_5 ;
V_5 = sizeof( struct V_24 ) * V_23 -> V_7 ;
V_23 -> V_25 = F_2 ( V_5 ) ;
if ( ! V_23 -> V_25 )
goto V_9;
F_3 ( & V_23 -> V_10 ) ;
V_23 -> V_5 = V_23 -> V_7 * sizeof( union V_26 ) ;
V_23 -> V_5 = F_4 ( V_23 -> V_5 , 4096 ) ;
V_23 -> V_12 = F_5 ( V_4 , V_23 -> V_5 ,
& V_23 -> V_13 , V_14 ) ;
if ( ! V_23 -> V_12 )
goto V_9;
return 0 ;
V_9:
F_6 ( V_23 -> V_25 ) ;
V_23 -> V_25 = NULL ;
return - V_15 ;
}
static int F_11 ( struct V_16 * V_17 )
{
int V_18 , V_9 = 0 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_9 = F_10 ( V_17 -> V_23 [ V_18 ] ) ;
if ( ! V_9 )
continue;
F_8 ( V_17 , V_20 , V_17 -> V_21 ,
L_2 , V_18 ) ;
goto V_28;
}
return 0 ;
V_28:
while ( V_18 -- )
F_12 ( V_17 -> V_23 [ V_18 ] ) ;
return V_9 ;
}
void F_13 ( struct V_1 * V_29 ,
struct V_6 * V_8 )
{
if ( V_8 -> V_30 ) {
F_14 ( V_8 -> V_30 ) ;
if ( F_15 ( V_8 , V_31 ) )
F_16 ( V_29 -> V_4 ,
F_17 ( V_8 , V_13 ) ,
F_15 ( V_8 , V_31 ) ,
V_32 ) ;
} else if ( F_15 ( V_8 , V_31 ) ) {
F_18 ( V_29 -> V_4 ,
F_17 ( V_8 , V_13 ) ,
F_15 ( V_8 , V_31 ) ,
V_32 ) ;
}
V_8 -> V_33 = NULL ;
V_8 -> V_30 = NULL ;
F_19 ( V_8 , V_31 , 0 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_8 ;
unsigned long V_5 ;
T_1 V_18 ;
if ( ! V_2 -> V_8 )
return;
for ( V_18 = 0 ; V_18 < V_2 -> V_7 ; V_18 ++ ) {
V_8 = & V_2 -> V_8 [ V_18 ] ;
F_13 ( V_2 , V_8 ) ;
}
F_21 ( F_22 ( V_2 ) ) ;
V_5 = sizeof( struct V_6 ) * V_2 -> V_7 ;
memset ( V_2 -> V_8 , 0 , V_5 ) ;
memset ( V_2 -> V_12 , 0 , V_2 -> V_5 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_6 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
if ( ! V_2 -> V_12 )
return;
F_23 ( V_2 -> V_4 , V_2 -> V_5 ,
V_2 -> V_12 , V_2 -> V_13 ) ;
V_2 -> V_12 = NULL ;
}
void F_24 ( struct V_16 * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ )
F_20 ( V_17 -> V_2 [ V_18 ] ) ;
}
static void F_25 ( struct V_16 * V_17 )
{
int V_18 = V_17 -> V_19 ;
while ( V_18 -- )
F_9 ( V_17 -> V_2 [ V_18 ] ) ;
}
static void F_26 ( struct V_1 * V_23 )
{
unsigned long V_5 ;
T_1 V_18 ;
if ( ! V_23 -> V_25 )
return;
if ( V_23 -> V_30 )
F_27 ( V_23 -> V_30 ) ;
V_23 -> V_30 = NULL ;
for ( V_18 = 0 ; V_18 < V_23 -> V_7 ; V_18 ++ ) {
struct V_24 * V_34 = & V_23 -> V_25 [ V_18 ] ;
if ( ! V_34 -> V_35 )
continue;
F_18 ( V_23 -> V_4 , V_34 -> V_13 ,
V_36 , V_37 ) ;
F_28 ( V_34 -> V_35 ) ;
V_34 -> V_35 = NULL ;
}
V_5 = sizeof( struct V_24 ) * V_23 -> V_7 ;
memset ( V_23 -> V_25 , 0 , V_5 ) ;
memset ( V_23 -> V_12 , 0 , V_23 -> V_5 ) ;
V_23 -> V_38 = 0 ;
V_23 -> V_39 = 0 ;
V_23 -> V_40 = 0 ;
}
void F_12 ( struct V_1 * V_23 )
{
F_26 ( V_23 ) ;
F_6 ( V_23 -> V_25 ) ;
V_23 -> V_25 = NULL ;
if ( ! V_23 -> V_12 )
return;
F_23 ( V_23 -> V_4 , V_23 -> V_5 ,
V_23 -> V_12 , V_23 -> V_13 ) ;
V_23 -> V_12 = NULL ;
}
void F_29 ( struct V_16 * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ )
F_26 ( V_17 -> V_23 [ V_18 ] ) ;
}
static void F_30 ( struct V_16 * V_17 )
{
int V_18 = V_17 -> V_27 ;
while ( V_18 -- )
F_12 ( V_17 -> V_23 [ V_18 ] ) ;
}
static void F_31 ( struct V_16 * V_17 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_43 = ( ~ V_42 -> V_44 . V_45 ) >> V_46 ;
V_17 -> V_47 = V_42 -> V_44 . V_45 & V_48 ;
V_17 -> V_49 = 0 ;
if ( V_42 -> V_44 . V_45 == V_48 )
return;
if ( V_43 <= V_42 -> V_50 . V_51 ) {
V_17 -> V_49 = 1 ;
V_17 -> V_47 += V_43 ;
} else if ( V_43 < 64 ) {
V_17 -> V_49 = ( V_43 + 1 ) / 2 ;
V_17 -> V_47 += V_17 -> V_49 ;
} else {
V_17 -> V_49 = V_43 - 63 ;
V_17 -> V_47 += 64 ;
}
}
static void F_32 ( struct V_16 * V_17 )
{
struct V_52 * V_53 ;
V_53 = F_33 ( & V_17 -> V_53 ,
struct V_52 , V_54 ) ;
while ( V_53 ) {
F_34 ( & V_53 -> V_54 ) ;
F_35 ( V_53 ) ;
V_53 = F_33 ( & V_17 -> V_53 ,
struct V_52 ,
V_54 ) ;
}
}
static void F_36 ( struct V_16 * V_17 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_52 * V_53 ;
if ( V_42 -> V_44 . type != V_55 )
return;
V_53 = F_33 ( & V_17 -> V_53 ,
struct V_52 , V_54 ) ;
F_37 ( V_42 , V_56 ,
( V_53 ? F_38 ( V_53 -> V_57 ) : 0 ) |
( V_58 << V_59 ) ) ;
}
static void F_39 ( struct V_60 * V_4 ,
struct V_61 * V_62 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_52 * V_53 ;
if ( V_62 -> type != V_63 )
return;
if ( V_17 -> V_42 . V_44 . type != V_55 )
return;
F_41 (vxlan_port, interface) {
if ( ( V_53 -> V_57 == V_62 -> V_57 ) &&
( V_53 -> V_64 == V_62 -> V_64 ) ) {
F_34 ( & V_53 -> V_54 ) ;
goto V_65;
}
}
V_53 = F_42 ( sizeof( * V_53 ) , V_66 ) ;
if ( ! V_53 )
return;
V_53 -> V_57 = V_62 -> V_57 ;
V_53 -> V_64 = V_62 -> V_64 ;
V_65:
F_43 ( & V_53 -> V_54 , & V_17 -> V_53 ) ;
F_36 ( V_17 ) ;
}
static void F_44 ( struct V_60 * V_4 ,
struct V_61 * V_62 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_52 * V_53 ;
if ( V_62 -> type != V_63 )
return;
if ( V_17 -> V_42 . V_44 . type != V_55 )
return;
F_41 (vxlan_port, interface) {
if ( ( V_53 -> V_57 == V_62 -> V_57 ) &&
( V_53 -> V_64 == V_62 -> V_64 ) ) {
F_34 ( & V_53 -> V_54 ) ;
F_35 ( V_53 ) ;
break;
}
}
F_36 ( V_17 ) ;
}
int F_45 ( struct V_60 * V_21 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
int V_9 ;
V_9 = F_7 ( V_17 ) ;
if ( V_9 )
goto V_22;
V_9 = F_11 ( V_17 ) ;
if ( V_9 )
goto V_28;
V_9 = F_46 ( V_17 ) ;
if ( V_9 )
goto V_67;
F_31 ( V_17 ) ;
V_9 = F_47 ( V_21 ,
V_17 -> V_19 ) ;
if ( V_9 )
goto V_68;
V_9 = F_48 ( V_21 ,
V_17 -> V_27 ) ;
if ( V_9 )
goto V_68;
F_49 ( V_21 ) ;
F_50 ( V_17 ) ;
return 0 ;
V_68:
F_51 ( V_17 ) ;
V_67:
F_30 ( V_17 ) ;
V_28:
F_25 ( V_17 ) ;
V_22:
return V_9 ;
}
int F_52 ( struct V_60 * V_21 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
F_53 ( V_17 ) ;
F_51 ( V_17 ) ;
F_32 ( V_17 ) ;
F_25 ( V_17 ) ;
F_30 ( V_17 ) ;
return 0 ;
}
static T_2 F_54 ( struct V_69 * V_30 , struct V_60 * V_4 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
unsigned int V_70 = V_30 -> V_71 ;
int V_9 ;
if ( ( V_30 -> V_72 == F_55 ( V_73 ) ) &&
! F_56 ( V_30 ) ) {
struct V_74 * V_75 ;
T_3 V_76 ;
V_30 = F_57 ( V_30 , V_66 ) ;
if ( ! V_30 )
return V_77 ;
if ( F_58 ( ! F_59 ( V_30 , V_78 ) ) )
return V_77 ;
V_9 = F_60 ( V_30 , 0 ) ;
if ( V_9 ) {
F_27 ( V_30 ) ;
return V_77 ;
}
V_75 = (struct V_74 * ) ( V_30 -> V_79 + V_80 ) ;
F_61 ( V_30 ,
F_55 ( V_73 ) ,
F_38 ( V_75 -> V_81 ) ) ;
V_76 = V_75 -> V_82 ;
V_30 -> V_72 = ( F_38 ( V_76 ) >= 1536 ) ? V_76 :
F_55 ( V_83 ) ;
memmove ( V_30 -> V_79 + V_84 , V_30 -> V_79 , 12 ) ;
F_62 ( V_30 , V_84 ) ;
F_63 ( V_30 ) ;
}
if ( F_58 ( V_30 -> V_31 < 17 ) ) {
int V_85 = 17 - V_30 -> V_31 ;
if ( F_64 ( V_30 , V_85 ) )
return V_77 ;
F_65 ( V_30 , V_85 ) ;
}
if ( V_70 >= V_17 -> V_19 )
V_70 %= V_17 -> V_19 ;
V_9 = F_66 ( V_30 , V_17 -> V_2 [ V_70 ] ) ;
return V_9 ;
}
static int F_67 ( struct V_60 * V_4 , int V_86 )
{
if ( V_86 < 68 || V_86 > V_87 )
return - V_88 ;
V_4 -> V_89 = V_86 ;
return 0 ;
}
static void F_68 ( struct V_60 * V_21 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
bool V_90 = false ;
int V_18 ;
#define F_69 16000
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
struct V_1 * V_2 = V_17 -> V_2 [ V_18 ] ;
if ( F_70 ( V_2 ) && F_71 ( V_2 ) )
V_90 = true ;
}
if ( V_90 ) {
F_72 ( V_17 ) ;
} else {
F_73 ( V_17 , V_91 , V_21 ,
L_3 ,
V_21 -> V_92 / V_93 ) ;
if ( V_21 -> V_92 < F_69 )
V_21 -> V_92 *= 2 ;
}
}
static int F_74 ( struct V_60 * V_21 ,
const unsigned char * V_94 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_47 = V_17 -> V_47 ;
T_1 V_95 = V_17 -> V_95 ;
bool V_96 = ! ! ( V_95 / V_97 ) ;
int V_9 ;
V_95 &= V_97 - 1 ;
V_9 = V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_94 , V_95 , V_96 , 0 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_75 ( struct V_60 * V_21 ,
const unsigned char * V_100 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_47 = V_17 -> V_47 ;
T_1 V_95 = V_17 -> V_95 ;
bool V_96 = ! ! ( V_95 / V_97 ) ;
int V_9 ;
V_95 &= V_97 - 1 ;
V_9 = V_42 -> V_44 . V_98 . V_101 ( V_42 , V_47 , V_100 , V_95 , V_96 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_76 ( struct V_60 * V_21 , T_1 V_95 , bool V_96 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_4 V_9 ;
int V_18 ;
if ( ! V_95 )
return 0 ;
if ( V_95 >= V_97 )
return - V_88 ;
if ( V_42 -> V_44 . V_102 )
return - V_103 ;
F_77 ( V_95 , V_17 -> V_104 ) ;
if ( ! V_96 )
F_78 ( V_95 , V_17 -> V_104 ) ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
struct V_1 * V_23 = V_17 -> V_23 [ V_18 ] ;
T_1 V_105 = V_23 -> V_95 & ( V_97 - 1 ) ;
if ( F_79 ( V_105 , V_17 -> V_104 ) )
V_23 -> V_95 |= V_106 ;
else
V_23 -> V_95 &= ~ V_106 ;
}
if ( ! V_96 && V_95 == V_42 -> V_44 . V_107 )
return 0 ;
if ( F_79 ( V_108 , & V_17 -> V_109 ) )
return 0 ;
F_80 ( V_17 ) ;
if ( ! ( V_21 -> V_110 & V_111 ) ) {
V_9 = V_42 -> V_44 . V_98 . V_112 ( V_42 , V_95 , 0 , V_96 ) ;
if ( V_9 )
goto V_113;
}
V_9 = V_42 -> V_44 . V_98 . V_99 ( V_42 , V_17 -> V_47 , V_42 -> V_44 . V_114 ,
V_95 , V_96 , 0 ) ;
if ( V_9 )
goto V_113;
V_17 -> V_95 = V_95 + ( V_96 ? V_97 : 0 ) ;
F_81 ( V_21 , F_74 ) ;
F_82 ( V_21 , F_75 ) ;
V_113:
F_83 ( V_17 ) ;
return V_9 ;
}
static int F_84 ( struct V_60 * V_21 ,
T_5 T_3 V_76 , T_1 V_95 )
{
return F_76 ( V_21 , V_95 , true ) ;
}
static int F_85 ( struct V_60 * V_21 ,
T_5 T_3 V_76 , T_1 V_95 )
{
return F_76 ( V_21 , V_95 , false ) ;
}
static T_1 F_86 ( struct V_16 * V_17 , T_1 V_95 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_107 = V_42 -> V_44 . V_107 ;
T_1 V_115 = V_95 < V_107 ? V_107 : V_97 ;
V_95 = F_87 ( V_17 -> V_104 , V_115 , ++ V_95 ) ;
return V_95 ;
}
static void F_88 ( struct V_16 * V_17 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_6 V_95 , V_116 ;
for ( V_95 = 0 , V_116 = 0 ;
V_116 < V_97 ;
V_116 = V_95 + 1 , V_95 = F_86 ( V_17 , V_95 ) ) {
if ( V_116 == V_95 )
continue;
V_116 += ( V_95 - V_116 - 1 ) << V_117 ;
V_42 -> V_44 . V_98 . V_112 ( V_42 , V_116 , 0 , false ) ;
}
}
static int F_89 ( struct V_60 * V_4 ,
const unsigned char * V_114 , bool V_118 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_95 , V_47 = V_17 -> V_47 ;
T_4 V_9 ;
if ( ! F_90 ( V_114 ) )
return - V_119 ;
for ( V_95 = V_42 -> V_44 . V_107 ? F_86 ( V_17 , 0 ) : 1 ;
V_95 < V_97 ;
V_95 = F_86 ( V_17 , V_95 ) ) {
V_9 = V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_114 ,
V_95 , V_118 , 0 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_91 ( struct V_60 * V_4 ,
const unsigned char * V_114 )
{
return F_89 ( V_4 , V_114 , true ) ;
}
static int F_92 ( struct V_60 * V_4 ,
const unsigned char * V_114 )
{
return F_89 ( V_4 , V_114 , false ) ;
}
static int F_93 ( struct V_60 * V_4 , void * V_120 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_121 * V_114 = V_120 ;
T_4 V_9 = 0 ;
if ( ! F_90 ( V_114 -> V_122 ) )
return - V_119 ;
if ( V_4 -> V_110 & V_123 ) {
F_80 ( V_17 ) ;
V_9 = F_91 ( V_4 , V_114 -> V_122 ) ;
if ( ! V_9 )
F_92 ( V_4 , V_42 -> V_44 . V_114 ) ;
F_83 ( V_17 ) ;
}
if ( ! V_9 ) {
F_94 ( V_4 -> V_124 , V_114 -> V_122 ) ;
F_94 ( V_42 -> V_44 . V_114 , V_114 -> V_122 ) ;
V_4 -> V_125 &= ~ V_126 ;
}
return V_9 ? - V_127 : 0 ;
}
static int F_95 ( struct V_60 * V_4 ,
const unsigned char * V_114 , bool V_118 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_95 , V_47 = V_17 -> V_47 ;
for ( V_95 = V_42 -> V_44 . V_107 ? F_86 ( V_17 , 0 ) : 1 ;
V_95 < V_97 ;
V_95 = F_86 ( V_17 , V_95 ) ) {
V_42 -> V_44 . V_98 . V_101 ( V_42 , V_47 , V_114 , V_95 , V_118 ) ;
}
return 0 ;
}
static int F_96 ( struct V_60 * V_4 ,
const unsigned char * V_114 )
{
return F_95 ( V_4 , V_114 , true ) ;
}
static int F_97 ( struct V_60 * V_4 ,
const unsigned char * V_114 )
{
return F_95 ( V_4 , V_114 , false ) ;
}
static void F_98 ( struct V_60 * V_4 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_128 ;
if ( ! ( V_4 -> V_110 & V_123 ) )
return;
V_128 = ( V_4 -> V_110 & V_111 ) ? V_129 :
( V_4 -> V_110 & V_130 ) ? V_131 :
( V_4 -> V_110 & ( V_132 | V_133 ) ) ?
V_134 : V_135 ;
F_80 ( V_17 ) ;
if ( V_17 -> V_128 != V_128 ) {
if ( V_128 == V_129 )
V_42 -> V_44 . V_98 . V_112 ( V_42 , V_136 , 0 , true ) ;
if ( V_17 -> V_128 == V_129 )
F_88 ( V_17 ) ;
V_42 -> V_44 . V_98 . V_137 ( V_42 , V_17 -> V_47 , V_128 ) ;
V_17 -> V_128 = V_128 ;
}
F_99 ( V_4 , F_91 , F_92 ) ;
F_100 ( V_4 , F_96 , F_97 ) ;
F_83 ( V_17 ) ;
}
void F_101 ( struct V_16 * V_17 )
{
struct V_60 * V_21 = V_17 -> V_21 ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_128 ;
T_1 V_95 , V_47 ;
V_47 = V_17 -> V_47 ;
if ( V_21 -> V_110 & V_111 )
V_128 = V_129 ;
else if ( V_21 -> V_110 & V_130 )
V_128 = V_131 ;
else if ( V_21 -> V_110 & ( V_132 | V_133 ) )
V_128 = V_134 ;
else
V_128 = V_135 ;
F_80 ( V_17 ) ;
V_42 -> V_44 . V_98 . V_138 ( V_42 , V_47 , V_17 -> V_49 , true ) ;
V_42 -> V_44 . V_98 . V_112 ( V_42 , V_136 , 0 ,
V_128 == V_129 ) ;
V_42 -> V_44 . V_98 . V_112 ( V_42 , 0 , 0 , true ) ;
for ( V_95 = V_42 -> V_44 . V_107 ? F_86 ( V_17 , 0 ) : 1 ;
V_95 < V_97 ;
V_95 = F_86 ( V_17 , V_95 ) ) {
V_42 -> V_44 . V_98 . V_112 ( V_42 , V_95 , 0 , true ) ;
V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_42 -> V_44 . V_114 ,
V_95 , true , 0 ) ;
}
V_42 -> V_44 . V_98 . V_137 ( V_42 , V_47 , V_128 ) ;
F_99 ( V_21 , F_91 , F_92 ) ;
F_100 ( V_21 , F_96 , F_97 ) ;
F_83 ( V_17 ) ;
V_17 -> V_128 = V_128 ;
F_36 ( V_17 ) ;
}
void F_102 ( struct V_16 * V_17 )
{
struct V_60 * V_21 = V_17 -> V_21 ;
struct V_41 * V_42 = & V_17 -> V_42 ;
F_80 ( V_17 ) ;
V_42 -> V_44 . V_98 . V_138 ( V_42 , V_17 -> V_47 ,
V_17 -> V_49 , false ) ;
F_83 ( V_17 ) ;
V_17 -> V_128 = V_135 ;
F_81 ( V_21 , NULL ) ;
F_82 ( V_21 , NULL ) ;
}
static struct V_139 * F_103 ( struct V_60 * V_21 ,
struct V_139 * V_140 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
struct V_1 * V_29 ;
unsigned int V_141 , V_18 ;
T_7 V_142 , V_143 ;
F_104 () ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = F_105 ( V_17 -> V_23 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_141 = F_106 ( & V_29 -> V_10 ) ;
V_143 = V_29 -> V_140 . V_143 ;
V_142 = V_29 -> V_140 . V_142 ;
} while ( F_107 ( & V_29 -> V_10 , V_141 ) );
V_140 -> V_144 += V_143 ;
V_140 -> V_145 += V_142 ;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_29 = F_105 ( V_17 -> V_2 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_141 = F_106 ( & V_29 -> V_10 ) ;
V_143 = V_29 -> V_140 . V_143 ;
V_142 = V_29 -> V_140 . V_142 ;
} while ( F_107 ( & V_29 -> V_10 , V_141 ) );
V_140 -> V_146 += V_143 ;
V_140 -> V_147 += V_142 ;
}
F_108 () ;
V_140 -> V_148 = V_21 -> V_140 . V_148 ;
return V_140 ;
}
int F_109 ( struct V_60 * V_4 , T_8 V_149 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
int V_9 ;
if ( V_149 && ( V_17 -> V_42 . V_44 . type != V_55 ) )
return - V_88 ;
if ( V_149 > 8 )
return - V_88 ;
if ( F_110 ( V_4 ) )
F_52 ( V_4 ) ;
F_111 ( V_17 ) ;
F_112 ( V_17 ) ;
F_113 ( V_4 ) ;
F_114 ( V_4 , V_149 ) ;
V_9 = F_115 ( V_17 ) ;
if ( V_9 )
goto V_150;
V_9 = F_116 ( V_17 ) ;
if ( V_9 )
goto V_151;
V_9 = F_110 ( V_4 ) ? F_45 ( V_4 ) : 0 ;
if ( V_9 )
goto V_152;
V_17 -> V_110 |= V_153 ;
return 0 ;
V_152:
F_111 ( V_17 ) ;
V_151:
F_112 ( V_17 ) ;
V_150:
F_117 ( V_4 ) ;
return V_9 ;
}
static int F_118 ( struct V_60 * V_4 , T_6 V_154 , T_3 V_76 ,
struct V_155 * V_149 )
{
if ( V_149 -> type != V_156 )
return - V_88 ;
return F_109 ( V_4 , V_149 -> V_149 ) ;
}
static void F_119 ( struct V_16 * V_17 ,
struct V_157 * V_158 )
{
struct V_1 * V_29 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = V_17 -> V_23 [ V_18 ] ;
F_120 ( V_29 -> V_158 , V_158 ) ;
}
V_17 -> V_158 = V_158 ;
}
static void * F_121 ( struct V_60 * V_4 ,
struct V_60 * V_159 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_157 * V_158 = V_17 -> V_158 ;
struct V_157 * V_160 = NULL ;
struct V_161 V_162 = { 0 } ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_5 = 0 , V_18 ;
T_1 V_47 ;
if ( ! V_158 ) {
if ( V_17 -> V_49 < 7 )
return F_122 ( - V_163 ) ;
V_5 = F_123 ( struct V_157 , V_164 [ 7 ] ) ;
V_158 = F_124 ( V_5 , V_14 ) ;
if ( ! V_158 )
return F_122 ( - V_15 ) ;
V_158 -> V_5 = 7 ;
V_158 -> V_162 = V_17 -> V_47 ;
F_119 ( V_17 , V_158 ) ;
} else if ( ( V_158 -> V_7 == V_165 ) ||
( V_158 -> V_7 == ( V_17 -> V_49 - 1 ) ) ) {
return F_122 ( - V_163 ) ;
} else if ( V_158 -> V_7 == V_158 -> V_5 ) {
V_160 = V_158 ;
V_5 = F_123 ( struct V_157 ,
V_164 [ ( V_158 -> V_5 * 2 ) + 1 ] ) ;
V_158 = F_124 ( V_5 , V_14 ) ;
if ( ! V_158 )
return F_122 ( - V_15 ) ;
memcpy ( V_158 , V_160 ,
F_123 ( struct V_157 ,
V_164 [ V_160 -> V_5 ] ) ) ;
V_158 -> V_5 = ( V_160 -> V_5 * 2 ) + 1 ;
F_119 ( V_17 , V_158 ) ;
F_125 ( V_160 , V_166 ) ;
}
for ( V_18 = 0 ; V_18 < V_158 -> V_5 ; V_18 ++ ) {
if ( ! V_158 -> V_164 [ V_18 ] )
break;
}
V_158 -> V_164 [ V_18 ] = V_159 ;
V_158 -> V_7 ++ ;
V_162 . V_167 = V_168 ;
V_162 . V_169 = 1 ;
V_162 . V_170 = F_126 ( V_17 -> V_171 [ V_172 ] . V_43 ) ;
V_162 . V_173 = F_126 ( V_17 -> V_171 [ V_174 ] . V_43 ) ;
V_162 . V_47 = V_17 -> V_47 ;
V_162 . V_175 = F_126 ( V_158 -> V_5 ) ;
V_42 -> V_44 . V_98 . V_176 ( V_42 , & V_162 ) ;
F_80 ( V_17 ) ;
V_47 = V_158 -> V_162 + 1 + V_18 ;
V_42 -> V_44 . V_98 . V_137 ( V_42 , V_47 , V_134 ) ;
V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_159 -> V_124 , 0 , true , 0 ) ;
F_83 ( V_17 ) ;
return V_159 ;
}
static void F_127 ( struct V_60 * V_4 , void * V_177 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_157 * V_158 = F_105 ( V_17 -> V_158 ) ;
struct V_161 V_162 = { 0 } ;
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_60 * V_159 = V_177 ;
int V_18 ;
T_1 V_47 ;
if ( ! V_158 )
return;
for ( V_18 = 0 ; V_18 < V_158 -> V_5 ; V_18 ++ ) {
if ( V_158 -> V_164 [ V_18 ] == V_159 )
break;
}
if ( V_18 == V_158 -> V_5 )
return;
F_80 ( V_17 ) ;
V_47 = V_158 -> V_162 + 1 + V_18 ;
V_42 -> V_44 . V_98 . V_137 ( V_42 , V_47 , V_135 ) ;
V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_159 -> V_124 , 0 , false , 0 ) ;
F_83 ( V_17 ) ;
V_158 -> V_164 [ V_18 ] = NULL ;
V_158 -> V_7 -- ;
V_162 . V_167 = V_168 ;
V_162 . V_169 = 1 ;
V_162 . V_170 = F_126 ( V_17 -> V_171 [ V_172 ] . V_43 ) ;
V_162 . V_173 = F_126 ( V_17 -> V_171 [ V_174 ] . V_43 ) ;
V_162 . V_47 = V_17 -> V_47 ;
V_162 . V_175 = F_126 ( V_158 -> V_5 ) ;
V_42 -> V_44 . V_98 . V_176 ( V_42 , & V_162 ) ;
if ( V_158 -> V_7 == 0 ) {
F_119 ( V_17 , NULL ) ;
F_125 ( V_158 , V_166 ) ;
}
}
static T_9 F_128 ( struct V_69 * V_30 ,
struct V_60 * V_4 ,
T_9 V_178 )
{
if ( ! V_30 -> V_179 || F_129 ( V_30 ) )
return V_178 ;
return V_178 & ~ ( V_180 | V_181 ) ;
}
struct V_60 * F_130 ( const struct V_182 * V_183 )
{
T_9 V_184 ;
struct V_16 * V_17 ;
struct V_60 * V_4 ;
V_4 = F_131 ( sizeof( struct V_16 ) , V_185 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_186 = & V_187 ;
F_132 ( V_4 ) ;
V_17 = F_40 ( V_4 ) ;
V_17 -> V_188 = F_133 ( V_189 ) - 1 ;
V_4 -> V_178 |= V_190 |
V_191 |
V_192 |
V_193 |
V_194 |
V_195 |
V_196 |
V_197 ;
if ( V_183 -> V_44 == V_55 ) {
V_4 -> V_198 = V_190 |
V_193 |
V_194 |
V_195 |
V_199 |
V_191 |
V_192 ;
V_4 -> V_178 |= V_199 ;
}
V_184 = V_4 -> V_178 ;
V_184 |= V_200 ;
V_4 -> V_201 |= V_4 -> V_178 ;
V_4 -> V_178 |= V_202 |
V_203 |
V_204 ;
V_4 -> V_205 |= V_206 ;
V_4 -> V_184 |= V_184 ;
return V_4 ;
}
