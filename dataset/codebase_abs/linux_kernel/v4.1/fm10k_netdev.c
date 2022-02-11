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
F_25 ( & V_17 -> V_34 ) ;
}
static void F_26 ( struct V_16 * V_17 )
{
int V_18 = V_17 -> V_19 ;
while ( V_18 -- )
F_9 ( V_17 -> V_2 [ V_18 ] ) ;
}
static void F_27 ( struct V_1 * V_23 )
{
unsigned long V_5 ;
T_1 V_18 ;
if ( ! V_23 -> V_25 )
return;
if ( V_23 -> V_30 )
F_28 ( V_23 -> V_30 ) ;
V_23 -> V_30 = NULL ;
for ( V_18 = 0 ; V_18 < V_23 -> V_7 ; V_18 ++ ) {
struct V_24 * V_35 = & V_23 -> V_25 [ V_18 ] ;
if ( ! V_35 -> V_36 )
continue;
F_18 ( V_23 -> V_4 , V_35 -> V_13 ,
V_37 , V_38 ) ;
F_29 ( V_35 -> V_36 ) ;
V_35 -> V_36 = NULL ;
}
V_5 = sizeof( struct V_24 ) * V_23 -> V_7 ;
memset ( V_23 -> V_25 , 0 , V_5 ) ;
memset ( V_23 -> V_12 , 0 , V_23 -> V_5 ) ;
V_23 -> V_39 = 0 ;
V_23 -> V_40 = 0 ;
V_23 -> V_41 = 0 ;
}
void F_12 ( struct V_1 * V_23 )
{
F_27 ( V_23 ) ;
F_6 ( V_23 -> V_25 ) ;
V_23 -> V_25 = NULL ;
if ( ! V_23 -> V_12 )
return;
F_23 ( V_23 -> V_4 , V_23 -> V_5 ,
V_23 -> V_12 , V_23 -> V_13 ) ;
V_23 -> V_12 = NULL ;
}
void F_30 ( struct V_16 * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ )
F_27 ( V_17 -> V_23 [ V_18 ] ) ;
}
static void F_31 ( struct V_16 * V_17 )
{
int V_18 = V_17 -> V_27 ;
while ( V_18 -- )
F_12 ( V_17 -> V_23 [ V_18 ] ) ;
}
static void F_32 ( struct V_16 * V_17 )
{
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_44 = ( ~ V_43 -> V_45 . V_46 ) >> V_47 ;
V_17 -> V_48 = V_43 -> V_45 . V_46 & V_49 ;
V_17 -> V_50 = 0 ;
if ( V_43 -> V_45 . V_46 == V_49 )
return;
if ( V_44 <= V_43 -> V_51 . V_52 ) {
V_17 -> V_50 = 1 ;
V_17 -> V_48 += V_44 ;
} else if ( V_44 < 64 ) {
V_17 -> V_50 = ( V_44 + 1 ) / 2 ;
V_17 -> V_48 += V_17 -> V_50 ;
} else {
V_17 -> V_50 = V_44 - 63 ;
V_17 -> V_48 += 64 ;
}
}
static void F_33 ( struct V_16 * V_17 )
{
struct V_53 * V_54 ;
V_54 = F_34 ( & V_17 -> V_54 ,
struct V_53 , V_55 ) ;
while ( V_54 ) {
F_35 ( & V_54 -> V_55 ) ;
F_36 ( V_54 ) ;
V_54 = F_34 ( & V_17 -> V_54 ,
struct V_53 ,
V_55 ) ;
}
}
static void F_37 ( struct V_16 * V_17 )
{
struct V_42 * V_43 = & V_17 -> V_43 ;
struct V_53 * V_54 ;
if ( V_43 -> V_45 . type != V_56 )
return;
V_54 = F_34 ( & V_17 -> V_54 ,
struct V_53 , V_55 ) ;
F_38 ( V_43 , V_57 ,
( V_54 ? F_39 ( V_54 -> V_58 ) : 0 ) |
( V_59 << V_60 ) ) ;
}
static void F_40 ( struct V_61 * V_4 ,
T_2 V_62 , T_3 V_58 ) {
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_53 * V_54 ;
if ( V_17 -> V_43 . V_45 . type != V_56 )
return;
F_42 (vxlan_port, interface) {
if ( ( V_54 -> V_58 == V_58 ) &&
( V_54 -> V_62 == V_62 ) ) {
F_35 ( & V_54 -> V_55 ) ;
goto V_63;
}
}
V_54 = F_43 ( sizeof( * V_54 ) , V_64 ) ;
if ( ! V_54 )
return;
V_54 -> V_58 = V_58 ;
V_54 -> V_62 = V_62 ;
V_63:
F_44 ( & V_54 -> V_55 , & V_17 -> V_54 ) ;
F_37 ( V_17 ) ;
}
static void F_45 ( struct V_61 * V_4 ,
T_2 V_62 , T_3 V_58 ) {
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_53 * V_54 ;
if ( V_17 -> V_43 . V_45 . type != V_56 )
return;
F_42 (vxlan_port, interface) {
if ( ( V_54 -> V_58 == V_58 ) &&
( V_54 -> V_62 == V_62 ) ) {
F_35 ( & V_54 -> V_55 ) ;
F_36 ( V_54 ) ;
break;
}
}
F_37 ( V_17 ) ;
}
int F_46 ( struct V_61 * V_21 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
int V_9 ;
V_9 = F_7 ( V_17 ) ;
if ( V_9 )
goto V_22;
V_9 = F_11 ( V_17 ) ;
if ( V_9 )
goto V_28;
V_9 = F_47 ( V_17 ) ;
if ( V_9 )
goto V_65;
F_32 ( V_17 ) ;
V_9 = F_48 ( V_21 ,
V_17 -> V_19 ) ;
if ( V_9 )
goto V_66;
V_9 = F_49 ( V_21 ,
V_17 -> V_27 ) ;
if ( V_9 )
goto V_66;
#if F_50 ( V_67 )
F_51 ( V_21 ) ;
#endif
F_52 ( V_17 ) ;
return 0 ;
V_66:
F_53 ( V_17 ) ;
V_65:
F_31 ( V_17 ) ;
V_28:
F_26 ( V_17 ) ;
V_22:
return V_9 ;
}
int F_54 ( struct V_61 * V_21 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
F_55 ( V_17 ) ;
F_53 ( V_17 ) ;
F_33 ( V_17 ) ;
F_26 ( V_17 ) ;
F_31 ( V_17 ) ;
return 0 ;
}
static T_4 F_56 ( struct V_68 * V_30 , struct V_61 * V_4 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
unsigned int V_69 = V_30 -> V_70 ;
int V_9 ;
if ( ( V_30 -> V_71 == F_57 ( V_72 ) ) &&
! F_58 ( V_30 ) ) {
struct V_73 * V_74 ;
T_3 V_75 ;
V_30 = F_59 ( V_30 , V_64 ) ;
if ( ! V_30 )
return V_76 ;
if ( F_60 ( ! F_61 ( V_30 , V_77 ) ) )
return V_76 ;
V_9 = F_62 ( V_30 , 0 ) ;
if ( V_9 )
return V_76 ;
V_74 = (struct V_73 * ) ( V_30 -> V_78 + V_79 ) ;
F_63 ( V_30 ,
F_57 ( V_72 ) ,
F_39 ( V_74 -> V_80 ) ) ;
V_75 = V_74 -> V_81 ;
V_30 -> V_71 = ( F_39 ( V_75 ) >= 1536 ) ? V_75 :
F_57 ( V_82 ) ;
memmove ( V_30 -> V_78 + V_83 , V_30 -> V_78 , 12 ) ;
F_64 ( V_30 , V_83 ) ;
F_65 ( V_30 ) ;
}
if ( F_60 ( V_30 -> V_31 < 17 ) ) {
int V_84 = 17 - V_30 -> V_31 ;
if ( F_66 ( V_30 , V_84 ) )
return V_76 ;
F_67 ( V_30 , V_84 ) ;
}
if ( F_60 ( F_68 ( V_30 ) -> V_85 & V_86 ) )
F_69 ( V_17 , V_30 ) ;
if ( V_69 >= V_17 -> V_19 )
V_69 %= V_17 -> V_19 ;
V_9 = F_70 ( V_30 , V_17 -> V_2 [ V_69 ] ) ;
return V_9 ;
}
static int F_71 ( struct V_61 * V_4 , int V_87 )
{
if ( V_87 < 68 || V_87 > V_88 )
return - V_89 ;
V_4 -> V_90 = V_87 ;
return 0 ;
}
static void F_72 ( struct V_61 * V_21 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
bool V_91 = false ;
int V_18 ;
#define F_73 16000
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
struct V_1 * V_2 = V_17 -> V_2 [ V_18 ] ;
if ( F_74 ( V_2 ) && F_75 ( V_2 ) )
V_91 = true ;
}
if ( V_91 ) {
F_76 ( V_17 ) ;
} else {
F_77 ( V_17 , V_92 , V_21 ,
L_3 ,
V_21 -> V_93 / V_94 ) ;
if ( V_21 -> V_93 < F_73 )
V_21 -> V_93 *= 2 ;
}
}
static int F_78 ( struct V_61 * V_21 ,
const unsigned char * V_95 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_48 = V_17 -> V_48 ;
T_1 V_96 = V_17 -> V_96 ;
bool V_97 = ! ! ( V_96 / V_98 ) ;
int V_9 ;
V_96 &= V_98 - 1 ;
V_9 = V_43 -> V_45 . V_99 . V_100 ( V_43 , V_48 , V_95 , V_96 , V_97 , 0 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_79 ( struct V_61 * V_21 ,
const unsigned char * V_101 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_48 = V_17 -> V_48 ;
T_1 V_96 = V_17 -> V_96 ;
bool V_97 = ! ! ( V_96 / V_98 ) ;
int V_9 ;
V_96 &= V_98 - 1 ;
V_9 = V_43 -> V_45 . V_99 . V_102 ( V_43 , V_48 , V_101 , V_96 , V_97 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_80 ( struct V_61 * V_21 , T_1 V_96 , bool V_97 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_5 V_9 ;
if ( ! V_96 )
return 0 ;
if ( V_96 >= V_98 )
return - V_89 ;
if ( V_43 -> V_45 . V_103 )
return - V_104 ;
F_81 ( V_96 , V_17 -> V_105 ) ;
if ( ! V_97 )
F_82 ( V_96 , V_17 -> V_105 ) ;
if ( V_96 == V_43 -> V_45 . V_106 )
return 0 ;
F_83 ( V_17 ) ;
if ( ! ( V_21 -> V_107 & V_108 ) ) {
V_9 = V_43 -> V_45 . V_99 . V_109 ( V_43 , V_96 , 0 , V_97 ) ;
if ( V_9 )
goto V_110;
}
V_9 = V_43 -> V_45 . V_99 . V_100 ( V_43 , V_17 -> V_48 , V_43 -> V_45 . V_111 ,
V_96 , V_97 , 0 ) ;
if ( V_9 )
goto V_110;
V_17 -> V_96 = V_96 + ( V_97 ? V_98 : 0 ) ;
F_84 ( V_21 , F_78 ) ;
F_85 ( V_21 , F_79 ) ;
V_110:
F_86 ( V_17 ) ;
return V_9 ;
}
static int F_87 ( struct V_61 * V_21 ,
T_6 T_3 V_75 , T_1 V_96 )
{
return F_80 ( V_21 , V_96 , true ) ;
}
static int F_88 ( struct V_61 * V_21 ,
T_6 T_3 V_75 , T_1 V_96 )
{
return F_80 ( V_21 , V_96 , false ) ;
}
static T_1 F_89 ( struct V_16 * V_17 , T_1 V_96 )
{
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_106 = V_43 -> V_45 . V_106 ;
T_1 V_112 = V_96 < V_106 ? V_106 : V_98 ;
V_96 = F_90 ( V_17 -> V_105 , V_112 , ++ V_96 ) ;
return V_96 ;
}
static void F_91 ( struct V_16 * V_17 )
{
struct V_42 * V_43 = & V_17 -> V_43 ;
T_7 V_96 , V_113 ;
for ( V_96 = 0 , V_113 = 0 ;
V_113 < V_98 ;
V_113 = V_96 + 1 , V_96 = F_89 ( V_17 , V_96 ) ) {
if ( V_113 == V_96 )
continue;
V_113 += ( V_96 - V_113 - 1 ) << V_114 ;
V_43 -> V_45 . V_99 . V_109 ( V_43 , V_113 , 0 , false ) ;
}
}
static int F_92 ( struct V_61 * V_4 ,
const unsigned char * V_111 , bool V_115 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_96 , V_48 = V_17 -> V_48 ;
T_5 V_9 ;
if ( ! F_93 ( V_111 ) )
return - V_116 ;
for ( V_96 = V_43 -> V_45 . V_106 ? F_89 ( V_17 , 0 ) : 0 ;
V_96 < V_98 ;
V_96 = F_89 ( V_17 , V_96 ) ) {
V_9 = V_43 -> V_45 . V_99 . V_100 ( V_43 , V_48 , V_111 ,
V_96 , V_115 , 0 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_94 ( struct V_61 * V_4 ,
const unsigned char * V_111 )
{
return F_92 ( V_4 , V_111 , true ) ;
}
static int F_95 ( struct V_61 * V_4 ,
const unsigned char * V_111 )
{
return F_92 ( V_4 , V_111 , false ) ;
}
static int F_96 ( struct V_61 * V_4 , void * V_117 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
struct V_118 * V_111 = V_117 ;
T_5 V_9 = 0 ;
if ( ! F_93 ( V_111 -> V_119 ) )
return - V_116 ;
if ( V_4 -> V_107 & V_120 ) {
F_83 ( V_17 ) ;
V_9 = F_94 ( V_4 , V_111 -> V_119 ) ;
if ( ! V_9 )
F_95 ( V_4 , V_43 -> V_45 . V_111 ) ;
F_86 ( V_17 ) ;
}
if ( ! V_9 ) {
F_97 ( V_4 -> V_121 , V_111 -> V_119 ) ;
F_97 ( V_43 -> V_45 . V_111 , V_111 -> V_119 ) ;
V_4 -> V_122 &= ~ V_123 ;
}
return V_9 ? - V_124 : 0 ;
}
static int F_98 ( struct V_61 * V_4 ,
const unsigned char * V_111 , bool V_115 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_96 , V_48 = V_17 -> V_48 ;
T_5 V_9 ;
if ( ! F_99 ( V_111 ) )
return - V_116 ;
for ( V_96 = V_43 -> V_45 . V_106 ? F_89 ( V_17 , 0 ) : 0 ;
V_96 < V_98 ;
V_96 = F_89 ( V_17 , V_96 ) ) {
V_9 = V_43 -> V_45 . V_99 . V_102 ( V_43 , V_48 , V_111 , V_96 , V_115 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_100 ( struct V_61 * V_4 ,
const unsigned char * V_111 )
{
return F_98 ( V_4 , V_111 , true ) ;
}
static int F_101 ( struct V_61 * V_4 ,
const unsigned char * V_111 )
{
return F_98 ( V_4 , V_111 , false ) ;
}
static void F_102 ( struct V_61 * V_4 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
int V_125 ;
if ( ! ( V_4 -> V_107 & V_120 ) )
return;
V_125 = ( V_4 -> V_107 & V_108 ) ? V_126 :
( V_4 -> V_107 & V_127 ) ? V_128 :
( V_4 -> V_107 & ( V_129 | V_130 ) ) ?
V_131 : V_132 ;
F_83 ( V_17 ) ;
if ( V_17 -> V_125 != V_125 ) {
if ( V_125 == V_126 )
V_43 -> V_45 . V_99 . V_109 ( V_43 , V_133 , 0 , true ) ;
if ( V_17 -> V_125 == V_126 )
F_91 ( V_17 ) ;
V_43 -> V_45 . V_99 . V_134 ( V_43 , V_17 -> V_48 , V_125 ) ;
V_17 -> V_125 = V_125 ;
}
if ( V_125 != V_126 ) {
F_103 ( V_4 , F_94 , F_95 ) ;
if ( V_125 != V_128 )
F_104 ( V_4 , F_100 , F_101 ) ;
}
F_86 ( V_17 ) ;
}
void F_105 ( struct V_16 * V_17 )
{
struct V_61 * V_21 = V_17 -> V_21 ;
struct V_42 * V_43 = & V_17 -> V_43 ;
int V_125 ;
T_1 V_96 , V_48 ;
if ( V_43 -> V_45 . type == V_135 ) {
if ( F_93 ( V_43 -> V_45 . V_136 ) ) {
F_97 ( V_43 -> V_45 . V_111 , V_43 -> V_45 . V_136 ) ;
F_97 ( V_21 -> V_136 , V_43 -> V_45 . V_136 ) ;
F_97 ( V_21 -> V_121 , V_43 -> V_45 . V_136 ) ;
V_21 -> V_122 &= ~ V_123 ;
}
if ( V_43 -> V_45 . V_103 )
V_21 -> V_137 &= ~ V_138 ;
else
V_21 -> V_137 |= V_138 ;
}
V_48 = V_17 -> V_48 ;
if ( V_21 -> V_107 & V_108 )
V_125 = V_126 ;
else if ( V_21 -> V_107 & V_127 )
V_125 = V_128 ;
else if ( V_21 -> V_107 & ( V_129 | V_130 ) )
V_125 = V_131 ;
else
V_125 = V_132 ;
F_83 ( V_17 ) ;
V_43 -> V_45 . V_99 . V_139 ( V_43 , V_48 , V_17 -> V_50 , true ) ;
V_43 -> V_45 . V_99 . V_109 ( V_43 , V_133 , 0 ,
V_125 == V_126 ) ;
V_43 -> V_45 . V_99 . V_109 ( V_43 , 0 , 0 , true ) ;
for ( V_96 = V_43 -> V_45 . V_106 ? F_89 ( V_17 , 0 ) : 0 ;
V_96 < V_98 ;
V_96 = F_89 ( V_17 , V_96 ) ) {
V_43 -> V_45 . V_99 . V_109 ( V_43 , V_96 , 0 , true ) ;
V_43 -> V_45 . V_99 . V_100 ( V_43 , V_48 , V_43 -> V_45 . V_111 ,
V_96 , true , 0 ) ;
}
V_43 -> V_45 . V_99 . V_134 ( V_43 , V_48 , V_125 ) ;
if ( V_125 != V_126 ) {
F_103 ( V_21 , F_94 , F_95 ) ;
if ( V_125 != V_128 )
F_104 ( V_21 , F_100 , F_101 ) ;
}
F_86 ( V_17 ) ;
V_17 -> V_125 = V_125 ;
F_37 ( V_17 ) ;
}
void F_106 ( struct V_16 * V_17 )
{
struct V_61 * V_21 = V_17 -> V_21 ;
struct V_42 * V_43 = & V_17 -> V_43 ;
F_83 ( V_17 ) ;
V_43 -> V_45 . V_99 . V_139 ( V_43 , V_17 -> V_48 ,
V_17 -> V_50 , false ) ;
F_86 ( V_17 ) ;
V_17 -> V_125 = V_132 ;
F_84 ( V_21 , NULL ) ;
F_85 ( V_21 , NULL ) ;
}
static struct V_140 * F_107 ( struct V_61 * V_21 ,
struct V_140 * V_141 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
struct V_1 * V_29 ;
unsigned int V_142 , V_18 ;
T_8 V_143 , V_144 ;
F_108 () ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = F_109 ( V_17 -> V_23 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_142 = F_110 ( & V_29 -> V_10 ) ;
V_144 = V_29 -> V_141 . V_144 ;
V_143 = V_29 -> V_141 . V_143 ;
} while ( F_111 ( & V_29 -> V_10 , V_142 ) );
V_141 -> V_145 += V_144 ;
V_141 -> V_146 += V_143 ;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_29 = F_109 ( V_17 -> V_2 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_142 = F_110 ( & V_29 -> V_10 ) ;
V_144 = V_29 -> V_141 . V_144 ;
V_143 = V_29 -> V_141 . V_143 ;
} while ( F_111 ( & V_29 -> V_10 , V_142 ) );
V_141 -> V_147 += V_144 ;
V_141 -> V_148 += V_143 ;
}
F_112 () ;
V_141 -> V_149 = V_21 -> V_141 . V_149 ;
return V_141 ;
}
int F_113 ( struct V_61 * V_4 , T_9 V_150 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
if ( V_150 && ( V_17 -> V_43 . V_45 . type != V_56 ) )
return - V_89 ;
if ( V_150 > 8 )
return - V_89 ;
if ( F_114 ( V_4 ) )
F_54 ( V_4 ) ;
F_115 ( V_17 ) ;
F_116 ( V_17 ) ;
F_117 ( V_4 ) ;
F_118 ( V_4 , V_150 ) ;
F_119 ( V_17 ) ;
F_120 ( V_17 ) ;
if ( F_114 ( V_4 ) )
F_46 ( V_4 ) ;
V_17 -> V_107 |= V_151 ;
return 0 ;
}
static int F_121 ( struct V_61 * V_21 , struct V_152 * V_153 , int V_154 )
{
switch ( V_154 ) {
case V_155 :
return F_122 ( V_21 , V_153 ) ;
case V_156 :
return F_123 ( V_21 , V_153 ) ;
default:
return - V_157 ;
}
}
static void F_124 ( struct V_16 * V_17 ,
struct V_158 * V_159 )
{
struct V_1 * V_29 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = V_17 -> V_23 [ V_18 ] ;
F_125 ( V_29 -> V_159 , V_159 ) ;
}
V_17 -> V_159 = V_159 ;
}
static void * F_126 ( struct V_61 * V_4 ,
struct V_61 * V_160 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_158 * V_159 = V_17 -> V_159 ;
struct V_158 * V_161 = NULL ;
struct V_162 V_163 = { 0 } ;
struct V_42 * V_43 = & V_17 -> V_43 ;
int V_5 = 0 , V_18 ;
T_1 V_48 ;
if ( ! V_159 ) {
if ( V_17 -> V_50 < 7 )
return F_127 ( - V_164 ) ;
V_5 = F_128 ( struct V_158 , V_165 [ 7 ] ) ;
V_159 = F_129 ( V_5 , V_14 ) ;
if ( ! V_159 )
return F_127 ( - V_15 ) ;
V_159 -> V_5 = 7 ;
V_159 -> V_163 = V_17 -> V_48 ;
F_124 ( V_17 , V_159 ) ;
} else if ( ( V_159 -> V_7 == V_166 ) ||
( V_159 -> V_7 == ( V_17 -> V_50 - 1 ) ) ) {
return F_127 ( - V_164 ) ;
} else if ( V_159 -> V_7 == V_159 -> V_5 ) {
V_161 = V_159 ;
V_5 = F_128 ( struct V_158 ,
V_165 [ ( V_159 -> V_5 * 2 ) + 1 ] ) ;
V_159 = F_129 ( V_5 , V_14 ) ;
if ( ! V_159 )
return F_127 ( - V_15 ) ;
memcpy ( V_159 , V_161 ,
F_128 ( struct V_158 ,
V_165 [ V_161 -> V_5 ] ) ) ;
V_159 -> V_5 = ( V_161 -> V_5 * 2 ) + 1 ;
F_124 ( V_17 , V_159 ) ;
F_130 ( V_161 , V_167 ) ;
}
for ( V_18 = 0 ; V_18 < V_159 -> V_5 ; V_18 ++ ) {
if ( ! V_159 -> V_165 [ V_18 ] )
break;
}
V_159 -> V_165 [ V_18 ] = V_160 ;
V_159 -> V_7 ++ ;
V_163 . V_168 = V_169 ;
V_163 . V_170 = 1 ;
V_163 . V_171 = F_131 ( V_17 -> V_172 [ V_173 ] . V_44 ) ;
V_163 . V_174 = F_131 ( V_17 -> V_172 [ V_175 ] . V_44 ) ;
V_163 . V_48 = V_17 -> V_48 ;
V_163 . V_176 = F_131 ( V_159 -> V_5 ) ;
V_43 -> V_45 . V_99 . V_177 ( V_43 , & V_163 ) ;
F_83 ( V_17 ) ;
V_48 = V_159 -> V_163 + 1 + V_18 ;
V_43 -> V_45 . V_99 . V_134 ( V_43 , V_48 , V_131 ) ;
V_43 -> V_45 . V_99 . V_100 ( V_43 , V_48 , V_160 -> V_121 , 0 , true , 0 ) ;
F_86 ( V_17 ) ;
return V_160 ;
}
static void F_132 ( struct V_61 * V_4 , void * V_178 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_158 * V_159 = F_109 ( V_17 -> V_159 ) ;
struct V_162 V_163 = { 0 } ;
struct V_42 * V_43 = & V_17 -> V_43 ;
struct V_61 * V_160 = V_178 ;
int V_18 ;
T_1 V_48 ;
if ( ! V_159 )
return;
for ( V_18 = 0 ; V_18 < V_159 -> V_5 ; V_18 ++ ) {
if ( V_159 -> V_165 [ V_18 ] == V_160 )
break;
}
if ( V_18 == V_159 -> V_5 )
return;
F_83 ( V_17 ) ;
V_48 = V_159 -> V_163 + 1 + V_18 ;
V_43 -> V_45 . V_99 . V_134 ( V_43 , V_48 , V_132 ) ;
V_43 -> V_45 . V_99 . V_100 ( V_43 , V_48 , V_160 -> V_121 , 0 , false , 0 ) ;
F_86 ( V_17 ) ;
V_159 -> V_165 [ V_18 ] = NULL ;
V_159 -> V_7 -- ;
V_163 . V_168 = V_169 ;
V_163 . V_170 = 1 ;
V_163 . V_171 = F_131 ( V_17 -> V_172 [ V_173 ] . V_44 ) ;
V_163 . V_174 = F_131 ( V_17 -> V_172 [ V_175 ] . V_44 ) ;
V_163 . V_48 = V_17 -> V_48 ;
if ( V_159 )
V_163 . V_176 = F_131 ( V_159 -> V_5 ) ;
V_43 -> V_45 . V_99 . V_177 ( V_43 , & V_163 ) ;
if ( V_159 -> V_7 == 0 ) {
F_124 ( V_17 , NULL ) ;
F_130 ( V_159 , V_167 ) ;
}
}
static T_10 F_133 ( struct V_68 * V_30 ,
struct V_61 * V_4 ,
T_10 V_137 )
{
if ( ! V_30 -> V_179 || F_134 ( V_30 ) )
return V_137 ;
return V_137 & ~ ( V_180 | V_181 ) ;
}
struct V_61 * F_135 ( void )
{
struct V_16 * V_17 ;
struct V_61 * V_4 ;
V_4 = F_136 ( sizeof( struct V_16 ) , V_182 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_183 = & V_184 ;
F_137 ( V_4 ) ;
V_17 = F_41 ( V_4 ) ;
V_17 -> V_185 = ( 1 << V_186 ) - 1 ;
V_4 -> V_137 |= V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 |
V_193 |
V_194 |
V_195 ;
V_4 -> V_196 |= V_4 -> V_137 ;
V_4 -> V_196 |= V_197 ;
V_4 -> V_198 |= V_4 -> V_137 ;
V_4 -> V_199 |= V_187 |
V_190 |
V_191 |
V_192 |
V_193 |
V_188 ;
V_4 -> V_137 |= V_200 |
V_138 |
V_201 ;
V_4 -> V_202 |= V_203 ;
return V_4 ;
}
