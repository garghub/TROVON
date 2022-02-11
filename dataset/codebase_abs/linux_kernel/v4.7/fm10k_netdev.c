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
T_2 V_61 , T_3 V_57 ) {
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_52 * V_53 ;
if ( V_17 -> V_42 . V_44 . type != V_55 )
return;
F_41 (vxlan_port, interface) {
if ( ( V_53 -> V_57 == V_57 ) &&
( V_53 -> V_61 == V_61 ) ) {
F_34 ( & V_53 -> V_54 ) ;
goto V_62;
}
}
V_53 = F_42 ( sizeof( * V_53 ) , V_63 ) ;
if ( ! V_53 )
return;
V_53 -> V_57 = V_57 ;
V_53 -> V_61 = V_61 ;
V_62:
F_43 ( & V_53 -> V_54 , & V_17 -> V_53 ) ;
F_36 ( V_17 ) ;
}
static void F_44 ( struct V_60 * V_4 ,
T_2 V_61 , T_3 V_57 ) {
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_52 * V_53 ;
if ( V_17 -> V_42 . V_44 . type != V_55 )
return;
F_41 (vxlan_port, interface) {
if ( ( V_53 -> V_57 == V_57 ) &&
( V_53 -> V_61 == V_61 ) ) {
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
goto V_64;
F_31 ( V_17 ) ;
V_9 = F_47 ( V_21 ,
V_17 -> V_19 ) ;
if ( V_9 )
goto V_65;
V_9 = F_48 ( V_21 ,
V_17 -> V_27 ) ;
if ( V_9 )
goto V_65;
#ifdef F_49
F_50 ( V_21 ) ;
#endif
F_51 ( V_17 ) ;
return 0 ;
V_65:
F_52 ( V_17 ) ;
V_64:
F_30 ( V_17 ) ;
V_28:
F_25 ( V_17 ) ;
V_22:
return V_9 ;
}
int F_53 ( struct V_60 * V_21 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
F_54 ( V_17 ) ;
F_52 ( V_17 ) ;
F_32 ( V_17 ) ;
F_25 ( V_17 ) ;
F_30 ( V_17 ) ;
return 0 ;
}
static T_4 F_55 ( struct V_66 * V_30 , struct V_60 * V_4 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
unsigned int V_67 = V_30 -> V_68 ;
int V_9 ;
if ( ( V_30 -> V_69 == F_56 ( V_70 ) ) &&
! F_57 ( V_30 ) ) {
struct V_71 * V_72 ;
T_3 V_73 ;
V_30 = F_58 ( V_30 , V_63 ) ;
if ( ! V_30 )
return V_74 ;
if ( F_59 ( ! F_60 ( V_30 , V_75 ) ) )
return V_74 ;
V_9 = F_61 ( V_30 , 0 ) ;
if ( V_9 ) {
F_27 ( V_30 ) ;
return V_74 ;
}
V_72 = (struct V_71 * ) ( V_30 -> V_76 + V_77 ) ;
F_62 ( V_30 ,
F_56 ( V_70 ) ,
F_38 ( V_72 -> V_78 ) ) ;
V_73 = V_72 -> V_79 ;
V_30 -> V_69 = ( F_38 ( V_73 ) >= 1536 ) ? V_73 :
F_56 ( V_80 ) ;
memmove ( V_30 -> V_76 + V_81 , V_30 -> V_76 , 12 ) ;
F_63 ( V_30 , V_81 ) ;
F_64 ( V_30 ) ;
}
if ( F_59 ( V_30 -> V_31 < 17 ) ) {
int V_82 = 17 - V_30 -> V_31 ;
if ( F_65 ( V_30 , V_82 ) )
return V_74 ;
F_66 ( V_30 , V_82 ) ;
}
if ( V_67 >= V_17 -> V_19 )
V_67 %= V_17 -> V_19 ;
V_9 = F_67 ( V_30 , V_17 -> V_2 [ V_67 ] ) ;
return V_9 ;
}
static int F_68 ( struct V_60 * V_4 , int V_83 )
{
if ( V_83 < 68 || V_83 > V_84 )
return - V_85 ;
V_4 -> V_86 = V_83 ;
return 0 ;
}
static void F_69 ( struct V_60 * V_21 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
bool V_87 = false ;
int V_18 ;
#define F_70 16000
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
struct V_1 * V_2 = V_17 -> V_2 [ V_18 ] ;
if ( F_71 ( V_2 ) && F_72 ( V_2 ) )
V_87 = true ;
}
if ( V_87 ) {
F_73 ( V_17 ) ;
} else {
F_74 ( V_17 , V_88 , V_21 ,
L_3 ,
V_21 -> V_89 / V_90 ) ;
if ( V_21 -> V_89 < F_70 )
V_21 -> V_89 *= 2 ;
}
}
static int F_75 ( struct V_60 * V_21 ,
const unsigned char * V_91 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_47 = V_17 -> V_47 ;
T_1 V_92 = V_17 -> V_92 ;
bool V_93 = ! ! ( V_92 / V_94 ) ;
int V_9 ;
V_92 &= V_94 - 1 ;
V_9 = V_42 -> V_44 . V_95 . V_96 ( V_42 , V_47 , V_91 , V_92 , V_93 , 0 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_76 ( struct V_60 * V_21 ,
const unsigned char * V_97 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_47 = V_17 -> V_47 ;
T_1 V_92 = V_17 -> V_92 ;
bool V_93 = ! ! ( V_92 / V_94 ) ;
int V_9 ;
V_92 &= V_94 - 1 ;
V_9 = V_42 -> V_44 . V_95 . V_98 ( V_42 , V_47 , V_97 , V_92 , V_93 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_77 ( struct V_60 * V_21 , T_1 V_92 , bool V_93 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_5 V_9 ;
int V_18 ;
if ( ! V_92 )
return 0 ;
if ( V_92 >= V_94 )
return - V_85 ;
if ( V_42 -> V_44 . V_99 )
return - V_100 ;
F_78 ( V_92 , V_17 -> V_101 ) ;
if ( ! V_93 )
F_79 ( V_92 , V_17 -> V_101 ) ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
struct V_1 * V_23 = V_17 -> V_23 [ V_18 ] ;
T_1 V_102 = V_23 -> V_92 & ( V_94 - 1 ) ;
if ( F_80 ( V_102 , V_17 -> V_101 ) )
V_23 -> V_92 |= V_103 ;
else
V_23 -> V_92 &= ~ V_103 ;
}
if ( ! V_93 && V_92 == V_42 -> V_44 . V_104 )
return 0 ;
if ( F_80 ( V_105 , & V_17 -> V_106 ) )
return 0 ;
F_81 ( V_17 ) ;
if ( ! ( V_21 -> V_107 & V_108 ) ) {
V_9 = V_42 -> V_44 . V_95 . V_109 ( V_42 , V_92 , 0 , V_93 ) ;
if ( V_9 )
goto V_110;
}
V_9 = V_42 -> V_44 . V_95 . V_96 ( V_42 , V_17 -> V_47 , V_42 -> V_44 . V_111 ,
V_92 , V_93 , 0 ) ;
if ( V_9 )
goto V_110;
V_17 -> V_92 = V_92 + ( V_93 ? V_94 : 0 ) ;
F_82 ( V_21 , F_75 ) ;
F_83 ( V_21 , F_76 ) ;
V_110:
F_84 ( V_17 ) ;
return V_9 ;
}
static int F_85 ( struct V_60 * V_21 ,
T_6 T_3 V_73 , T_1 V_92 )
{
return F_77 ( V_21 , V_92 , true ) ;
}
static int F_86 ( struct V_60 * V_21 ,
T_6 T_3 V_73 , T_1 V_92 )
{
return F_77 ( V_21 , V_92 , false ) ;
}
static T_1 F_87 ( struct V_16 * V_17 , T_1 V_92 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_104 = V_42 -> V_44 . V_104 ;
T_1 V_112 = V_92 < V_104 ? V_104 : V_94 ;
V_92 = F_88 ( V_17 -> V_101 , V_112 , ++ V_92 ) ;
return V_92 ;
}
static void F_89 ( struct V_16 * V_17 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_7 V_92 , V_113 ;
for ( V_92 = 0 , V_113 = 0 ;
V_113 < V_94 ;
V_113 = V_92 + 1 , V_92 = F_87 ( V_17 , V_92 ) ) {
if ( V_113 == V_92 )
continue;
V_113 += ( V_92 - V_113 - 1 ) << V_114 ;
V_42 -> V_44 . V_95 . V_109 ( V_42 , V_113 , 0 , false ) ;
}
}
static int F_90 ( struct V_60 * V_4 ,
const unsigned char * V_111 , bool V_115 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_92 , V_47 = V_17 -> V_47 ;
T_5 V_9 ;
if ( ! F_91 ( V_111 ) )
return - V_116 ;
for ( V_92 = V_42 -> V_44 . V_104 ? F_87 ( V_17 , 0 ) : 1 ;
V_92 < V_94 ;
V_92 = F_87 ( V_17 , V_92 ) ) {
V_9 = V_42 -> V_44 . V_95 . V_96 ( V_42 , V_47 , V_111 ,
V_92 , V_115 , 0 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_92 ( struct V_60 * V_4 ,
const unsigned char * V_111 )
{
return F_90 ( V_4 , V_111 , true ) ;
}
static int F_93 ( struct V_60 * V_4 ,
const unsigned char * V_111 )
{
return F_90 ( V_4 , V_111 , false ) ;
}
static int F_94 ( struct V_60 * V_4 , void * V_117 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_118 * V_111 = V_117 ;
T_5 V_9 = 0 ;
if ( ! F_91 ( V_111 -> V_119 ) )
return - V_116 ;
if ( V_4 -> V_107 & V_120 ) {
F_81 ( V_17 ) ;
V_9 = F_92 ( V_4 , V_111 -> V_119 ) ;
if ( ! V_9 )
F_93 ( V_4 , V_42 -> V_44 . V_111 ) ;
F_84 ( V_17 ) ;
}
if ( ! V_9 ) {
F_95 ( V_4 -> V_121 , V_111 -> V_119 ) ;
F_95 ( V_42 -> V_44 . V_111 , V_111 -> V_119 ) ;
V_4 -> V_122 &= ~ V_123 ;
}
return V_9 ? - V_124 : 0 ;
}
static int F_96 ( struct V_60 * V_4 ,
const unsigned char * V_111 , bool V_115 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_92 , V_47 = V_17 -> V_47 ;
for ( V_92 = V_42 -> V_44 . V_104 ? F_87 ( V_17 , 0 ) : 1 ;
V_92 < V_94 ;
V_92 = F_87 ( V_17 , V_92 ) ) {
V_42 -> V_44 . V_95 . V_98 ( V_42 , V_47 , V_111 , V_92 , V_115 ) ;
}
return 0 ;
}
static int F_97 ( struct V_60 * V_4 ,
const unsigned char * V_111 )
{
return F_96 ( V_4 , V_111 , true ) ;
}
static int F_98 ( struct V_60 * V_4 ,
const unsigned char * V_111 )
{
return F_96 ( V_4 , V_111 , false ) ;
}
static void F_99 ( struct V_60 * V_4 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_125 ;
if ( ! ( V_4 -> V_107 & V_120 ) )
return;
V_125 = ( V_4 -> V_107 & V_108 ) ? V_126 :
( V_4 -> V_107 & V_127 ) ? V_128 :
( V_4 -> V_107 & ( V_129 | V_130 ) ) ?
V_131 : V_132 ;
F_81 ( V_17 ) ;
if ( V_17 -> V_125 != V_125 ) {
if ( V_125 == V_126 )
V_42 -> V_44 . V_95 . V_109 ( V_42 , V_133 , 0 , true ) ;
if ( V_17 -> V_125 == V_126 )
F_89 ( V_17 ) ;
V_42 -> V_44 . V_95 . V_134 ( V_42 , V_17 -> V_47 , V_125 ) ;
V_17 -> V_125 = V_125 ;
}
F_100 ( V_4 , F_92 , F_93 ) ;
F_101 ( V_4 , F_97 , F_98 ) ;
F_84 ( V_17 ) ;
}
void F_102 ( struct V_16 * V_17 )
{
struct V_60 * V_21 = V_17 -> V_21 ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_125 ;
T_1 V_92 , V_47 ;
V_47 = V_17 -> V_47 ;
if ( V_21 -> V_107 & V_108 )
V_125 = V_126 ;
else if ( V_21 -> V_107 & V_127 )
V_125 = V_128 ;
else if ( V_21 -> V_107 & ( V_129 | V_130 ) )
V_125 = V_131 ;
else
V_125 = V_132 ;
F_81 ( V_17 ) ;
V_42 -> V_44 . V_95 . V_135 ( V_42 , V_47 , V_17 -> V_49 , true ) ;
V_42 -> V_44 . V_95 . V_109 ( V_42 , V_133 , 0 ,
V_125 == V_126 ) ;
V_42 -> V_44 . V_95 . V_109 ( V_42 , 0 , 0 , true ) ;
for ( V_92 = V_42 -> V_44 . V_104 ? F_87 ( V_17 , 0 ) : 1 ;
V_92 < V_94 ;
V_92 = F_87 ( V_17 , V_92 ) ) {
V_42 -> V_44 . V_95 . V_109 ( V_42 , V_92 , 0 , true ) ;
V_42 -> V_44 . V_95 . V_96 ( V_42 , V_47 , V_42 -> V_44 . V_111 ,
V_92 , true , 0 ) ;
}
V_42 -> V_44 . V_95 . V_134 ( V_42 , V_47 , V_125 ) ;
F_100 ( V_21 , F_92 , F_93 ) ;
F_101 ( V_21 , F_97 , F_98 ) ;
F_84 ( V_17 ) ;
V_17 -> V_125 = V_125 ;
F_36 ( V_17 ) ;
}
void F_103 ( struct V_16 * V_17 )
{
struct V_60 * V_21 = V_17 -> V_21 ;
struct V_41 * V_42 = & V_17 -> V_42 ;
F_81 ( V_17 ) ;
V_42 -> V_44 . V_95 . V_135 ( V_42 , V_17 -> V_47 ,
V_17 -> V_49 , false ) ;
F_84 ( V_17 ) ;
V_17 -> V_125 = V_132 ;
F_82 ( V_21 , NULL ) ;
F_83 ( V_21 , NULL ) ;
}
static struct V_136 * F_104 ( struct V_60 * V_21 ,
struct V_136 * V_137 )
{
struct V_16 * V_17 = F_40 ( V_21 ) ;
struct V_1 * V_29 ;
unsigned int V_138 , V_18 ;
T_8 V_139 , V_140 ;
F_105 () ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = F_106 ( V_17 -> V_23 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_138 = F_107 ( & V_29 -> V_10 ) ;
V_140 = V_29 -> V_137 . V_140 ;
V_139 = V_29 -> V_137 . V_139 ;
} while ( F_108 ( & V_29 -> V_10 , V_138 ) );
V_137 -> V_141 += V_140 ;
V_137 -> V_142 += V_139 ;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_29 = F_106 ( V_17 -> V_2 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_138 = F_107 ( & V_29 -> V_10 ) ;
V_140 = V_29 -> V_137 . V_140 ;
V_139 = V_29 -> V_137 . V_139 ;
} while ( F_108 ( & V_29 -> V_10 , V_138 ) );
V_137 -> V_143 += V_140 ;
V_137 -> V_144 += V_139 ;
}
F_109 () ;
V_137 -> V_145 = V_21 -> V_137 . V_145 ;
return V_137 ;
}
int F_110 ( struct V_60 * V_4 , T_9 V_146 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
int V_9 ;
if ( V_146 && ( V_17 -> V_42 . V_44 . type != V_55 ) )
return - V_85 ;
if ( V_146 > 8 )
return - V_85 ;
if ( F_111 ( V_4 ) )
F_53 ( V_4 ) ;
F_112 ( V_17 ) ;
F_113 ( V_17 ) ;
F_114 ( V_4 ) ;
F_115 ( V_4 , V_146 ) ;
V_9 = F_116 ( V_17 ) ;
if ( V_9 )
goto V_147;
V_9 = F_117 ( V_17 ) ;
if ( V_9 )
goto V_148;
V_9 = F_111 ( V_4 ) ? F_45 ( V_4 ) : 0 ;
if ( V_9 )
goto V_149;
V_17 -> V_107 |= V_150 ;
return 0 ;
V_149:
F_112 ( V_17 ) ;
V_148:
F_113 ( V_17 ) ;
V_147:
F_118 ( V_4 ) ;
return V_9 ;
}
static int F_119 ( struct V_60 * V_4 , T_7 V_151 , T_3 V_73 ,
struct V_152 * V_146 )
{
if ( V_146 -> type != V_153 )
return - V_85 ;
return F_110 ( V_4 , V_146 -> V_146 ) ;
}
static void F_120 ( struct V_16 * V_17 ,
struct V_154 * V_155 )
{
struct V_1 * V_29 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = V_17 -> V_23 [ V_18 ] ;
F_121 ( V_29 -> V_155 , V_155 ) ;
}
V_17 -> V_155 = V_155 ;
}
static void * F_122 ( struct V_60 * V_4 ,
struct V_60 * V_156 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_154 * V_155 = V_17 -> V_155 ;
struct V_154 * V_157 = NULL ;
struct V_158 V_159 = { 0 } ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_5 = 0 , V_18 ;
T_1 V_47 ;
if ( ! V_155 ) {
if ( V_17 -> V_49 < 7 )
return F_123 ( - V_160 ) ;
V_5 = F_124 ( struct V_154 , V_161 [ 7 ] ) ;
V_155 = F_125 ( V_5 , V_14 ) ;
if ( ! V_155 )
return F_123 ( - V_15 ) ;
V_155 -> V_5 = 7 ;
V_155 -> V_159 = V_17 -> V_47 ;
F_120 ( V_17 , V_155 ) ;
} else if ( ( V_155 -> V_7 == V_162 ) ||
( V_155 -> V_7 == ( V_17 -> V_49 - 1 ) ) ) {
return F_123 ( - V_160 ) ;
} else if ( V_155 -> V_7 == V_155 -> V_5 ) {
V_157 = V_155 ;
V_5 = F_124 ( struct V_154 ,
V_161 [ ( V_155 -> V_5 * 2 ) + 1 ] ) ;
V_155 = F_125 ( V_5 , V_14 ) ;
if ( ! V_155 )
return F_123 ( - V_15 ) ;
memcpy ( V_155 , V_157 ,
F_124 ( struct V_154 ,
V_161 [ V_157 -> V_5 ] ) ) ;
V_155 -> V_5 = ( V_157 -> V_5 * 2 ) + 1 ;
F_120 ( V_17 , V_155 ) ;
F_126 ( V_157 , V_163 ) ;
}
for ( V_18 = 0 ; V_18 < V_155 -> V_5 ; V_18 ++ ) {
if ( ! V_155 -> V_161 [ V_18 ] )
break;
}
V_155 -> V_161 [ V_18 ] = V_156 ;
V_155 -> V_7 ++ ;
V_159 . V_164 = V_165 ;
V_159 . V_166 = 1 ;
V_159 . V_167 = F_127 ( V_17 -> V_168 [ V_169 ] . V_43 ) ;
V_159 . V_170 = F_127 ( V_17 -> V_168 [ V_171 ] . V_43 ) ;
V_159 . V_47 = V_17 -> V_47 ;
V_159 . V_172 = F_127 ( V_155 -> V_5 ) ;
V_42 -> V_44 . V_95 . V_173 ( V_42 , & V_159 ) ;
F_81 ( V_17 ) ;
V_47 = V_155 -> V_159 + 1 + V_18 ;
V_42 -> V_44 . V_95 . V_134 ( V_42 , V_47 , V_131 ) ;
V_42 -> V_44 . V_95 . V_96 ( V_42 , V_47 , V_156 -> V_121 , 0 , true , 0 ) ;
F_84 ( V_17 ) ;
return V_156 ;
}
static void F_128 ( struct V_60 * V_4 , void * V_174 )
{
struct V_16 * V_17 = F_40 ( V_4 ) ;
struct V_154 * V_155 = F_106 ( V_17 -> V_155 ) ;
struct V_158 V_159 = { 0 } ;
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_60 * V_156 = V_174 ;
int V_18 ;
T_1 V_47 ;
if ( ! V_155 )
return;
for ( V_18 = 0 ; V_18 < V_155 -> V_5 ; V_18 ++ ) {
if ( V_155 -> V_161 [ V_18 ] == V_156 )
break;
}
if ( V_18 == V_155 -> V_5 )
return;
F_81 ( V_17 ) ;
V_47 = V_155 -> V_159 + 1 + V_18 ;
V_42 -> V_44 . V_95 . V_134 ( V_42 , V_47 , V_132 ) ;
V_42 -> V_44 . V_95 . V_96 ( V_42 , V_47 , V_156 -> V_121 , 0 , false , 0 ) ;
F_84 ( V_17 ) ;
V_155 -> V_161 [ V_18 ] = NULL ;
V_155 -> V_7 -- ;
V_159 . V_164 = V_165 ;
V_159 . V_166 = 1 ;
V_159 . V_167 = F_127 ( V_17 -> V_168 [ V_169 ] . V_43 ) ;
V_159 . V_170 = F_127 ( V_17 -> V_168 [ V_171 ] . V_43 ) ;
V_159 . V_47 = V_17 -> V_47 ;
V_159 . V_172 = F_127 ( V_155 -> V_5 ) ;
V_42 -> V_44 . V_95 . V_173 ( V_42 , & V_159 ) ;
if ( V_155 -> V_7 == 0 ) {
F_120 ( V_17 , NULL ) ;
F_126 ( V_155 , V_163 ) ;
}
}
static T_10 F_129 ( struct V_66 * V_30 ,
struct V_60 * V_4 ,
T_10 V_175 )
{
if ( ! V_30 -> V_176 || F_130 ( V_30 ) )
return V_175 ;
return V_175 & ~ ( V_177 | V_178 ) ;
}
struct V_60 * F_131 ( const struct V_179 * V_180 )
{
T_10 V_181 ;
struct V_16 * V_17 ;
struct V_60 * V_4 ;
V_4 = F_132 ( sizeof( struct V_16 ) , V_182 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_183 = & V_184 ;
F_133 ( V_4 ) ;
V_17 = F_40 ( V_4 ) ;
V_17 -> V_185 = F_134 ( V_186 ) - 1 ;
V_4 -> V_175 |= V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 |
V_193 |
V_194 ;
if ( V_180 -> V_44 == V_55 ) {
V_4 -> V_195 = V_187 |
V_190 |
V_191 |
V_192 |
V_196 |
V_188 |
V_189 ;
V_4 -> V_175 |= V_196 ;
}
V_181 = V_4 -> V_175 ;
V_181 |= V_197 ;
V_4 -> V_198 |= V_4 -> V_175 ;
V_4 -> V_175 |= V_199 |
V_200 |
V_201 ;
V_4 -> V_202 |= V_203 ;
V_4 -> V_181 |= V_181 ;
return V_4 ;
}
