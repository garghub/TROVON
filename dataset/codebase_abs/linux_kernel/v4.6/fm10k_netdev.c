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
#ifdef F_50
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
static T_4 F_56 ( struct V_67 * V_30 , struct V_61 * V_4 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
unsigned int V_68 = V_30 -> V_69 ;
int V_9 ;
if ( ( V_30 -> V_70 == F_57 ( V_71 ) ) &&
! F_58 ( V_30 ) ) {
struct V_72 * V_73 ;
T_3 V_74 ;
V_30 = F_59 ( V_30 , V_64 ) ;
if ( ! V_30 )
return V_75 ;
if ( F_60 ( ! F_61 ( V_30 , V_76 ) ) )
return V_75 ;
V_9 = F_62 ( V_30 , 0 ) ;
if ( V_9 ) {
F_28 ( V_30 ) ;
return V_75 ;
}
V_73 = (struct V_72 * ) ( V_30 -> V_77 + V_78 ) ;
F_63 ( V_30 ,
F_57 ( V_71 ) ,
F_39 ( V_73 -> V_79 ) ) ;
V_74 = V_73 -> V_80 ;
V_30 -> V_70 = ( F_39 ( V_74 ) >= 1536 ) ? V_74 :
F_57 ( V_81 ) ;
memmove ( V_30 -> V_77 + V_82 , V_30 -> V_77 , 12 ) ;
F_64 ( V_30 , V_82 ) ;
F_65 ( V_30 ) ;
}
if ( F_60 ( V_30 -> V_31 < 17 ) ) {
int V_83 = 17 - V_30 -> V_31 ;
if ( F_66 ( V_30 , V_83 ) )
return V_75 ;
F_67 ( V_30 , V_83 ) ;
}
if ( F_60 ( F_68 ( V_30 ) -> V_84 & V_85 ) )
F_69 ( V_17 , V_30 ) ;
if ( V_68 >= V_17 -> V_19 )
V_68 %= V_17 -> V_19 ;
V_9 = F_70 ( V_30 , V_17 -> V_2 [ V_68 ] ) ;
return V_9 ;
}
static int F_71 ( struct V_61 * V_4 , int V_86 )
{
if ( V_86 < 68 || V_86 > V_87 )
return - V_88 ;
V_4 -> V_89 = V_86 ;
return 0 ;
}
static void F_72 ( struct V_61 * V_21 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
bool V_90 = false ;
int V_18 ;
#define F_73 16000
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
struct V_1 * V_2 = V_17 -> V_2 [ V_18 ] ;
if ( F_74 ( V_2 ) && F_75 ( V_2 ) )
V_90 = true ;
}
if ( V_90 ) {
F_76 ( V_17 ) ;
} else {
F_77 ( V_17 , V_91 , V_21 ,
L_3 ,
V_21 -> V_92 / V_93 ) ;
if ( V_21 -> V_92 < F_73 )
V_21 -> V_92 *= 2 ;
}
}
static int F_78 ( struct V_61 * V_21 ,
const unsigned char * V_94 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_48 = V_17 -> V_48 ;
T_1 V_95 = V_17 -> V_95 ;
bool V_96 = ! ! ( V_95 / V_97 ) ;
int V_9 ;
V_95 &= V_97 - 1 ;
V_9 = V_43 -> V_45 . V_98 . V_99 ( V_43 , V_48 , V_94 , V_95 , V_96 , 0 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_79 ( struct V_61 * V_21 ,
const unsigned char * V_100 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_48 = V_17 -> V_48 ;
T_1 V_95 = V_17 -> V_95 ;
bool V_96 = ! ! ( V_95 / V_97 ) ;
int V_9 ;
V_95 &= V_97 - 1 ;
V_9 = V_43 -> V_45 . V_98 . V_101 ( V_43 , V_48 , V_100 , V_95 , V_96 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_80 ( struct V_61 * V_21 , T_1 V_95 , bool V_96 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_5 V_9 ;
int V_18 ;
if ( ! V_95 )
return 0 ;
if ( V_95 >= V_97 )
return - V_88 ;
if ( V_43 -> V_45 . V_102 )
return - V_103 ;
F_81 ( V_95 , V_17 -> V_104 ) ;
if ( ! V_96 )
F_82 ( V_95 , V_17 -> V_104 ) ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
struct V_1 * V_23 = V_17 -> V_23 [ V_18 ] ;
T_1 V_105 = V_23 -> V_95 & ( V_97 - 1 ) ;
if ( F_83 ( V_105 , V_17 -> V_104 ) )
V_23 -> V_95 |= V_106 ;
else
V_23 -> V_95 &= ~ V_106 ;
}
if ( ! V_96 && V_95 == V_43 -> V_45 . V_107 )
return 0 ;
if ( F_83 ( V_108 , & V_17 -> V_109 ) )
return 0 ;
F_84 ( V_17 ) ;
if ( ! ( V_21 -> V_110 & V_111 ) ) {
V_9 = V_43 -> V_45 . V_98 . V_112 ( V_43 , V_95 , 0 , V_96 ) ;
if ( V_9 )
goto V_113;
}
V_9 = V_43 -> V_45 . V_98 . V_99 ( V_43 , V_17 -> V_48 , V_43 -> V_45 . V_114 ,
V_95 , V_96 , 0 ) ;
if ( V_9 )
goto V_113;
V_17 -> V_95 = V_95 + ( V_96 ? V_97 : 0 ) ;
F_85 ( V_21 , F_78 ) ;
F_86 ( V_21 , F_79 ) ;
V_113:
F_87 ( V_17 ) ;
return V_9 ;
}
static int F_88 ( struct V_61 * V_21 ,
T_6 T_3 V_74 , T_1 V_95 )
{
return F_80 ( V_21 , V_95 , true ) ;
}
static int F_89 ( struct V_61 * V_21 ,
T_6 T_3 V_74 , T_1 V_95 )
{
return F_80 ( V_21 , V_95 , false ) ;
}
static T_1 F_90 ( struct V_16 * V_17 , T_1 V_95 )
{
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_107 = V_43 -> V_45 . V_107 ;
T_1 V_115 = V_95 < V_107 ? V_107 : V_97 ;
V_95 = F_91 ( V_17 -> V_104 , V_115 , ++ V_95 ) ;
return V_95 ;
}
static void F_92 ( struct V_16 * V_17 )
{
struct V_42 * V_43 = & V_17 -> V_43 ;
T_7 V_95 , V_116 ;
for ( V_95 = 0 , V_116 = 0 ;
V_116 < V_97 ;
V_116 = V_95 + 1 , V_95 = F_90 ( V_17 , V_95 ) ) {
if ( V_116 == V_95 )
continue;
V_116 += ( V_95 - V_116 - 1 ) << V_117 ;
V_43 -> V_45 . V_98 . V_112 ( V_43 , V_116 , 0 , false ) ;
}
}
static int F_93 ( struct V_61 * V_4 ,
const unsigned char * V_114 , bool V_118 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_95 , V_48 = V_17 -> V_48 ;
T_5 V_9 ;
if ( ! F_94 ( V_114 ) )
return - V_119 ;
for ( V_95 = V_43 -> V_45 . V_107 ? F_90 ( V_17 , 0 ) : 0 ;
V_95 < V_97 ;
V_95 = F_90 ( V_17 , V_95 ) ) {
V_9 = V_43 -> V_45 . V_98 . V_99 ( V_43 , V_48 , V_114 ,
V_95 , V_118 , 0 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_95 ( struct V_61 * V_4 ,
const unsigned char * V_114 )
{
return F_93 ( V_4 , V_114 , true ) ;
}
static int F_96 ( struct V_61 * V_4 ,
const unsigned char * V_114 )
{
return F_93 ( V_4 , V_114 , false ) ;
}
static int F_97 ( struct V_61 * V_4 , void * V_120 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
struct V_121 * V_114 = V_120 ;
T_5 V_9 = 0 ;
if ( ! F_94 ( V_114 -> V_122 ) )
return - V_119 ;
if ( V_4 -> V_110 & V_123 ) {
F_84 ( V_17 ) ;
V_9 = F_95 ( V_4 , V_114 -> V_122 ) ;
if ( ! V_9 )
F_96 ( V_4 , V_43 -> V_45 . V_114 ) ;
F_87 ( V_17 ) ;
}
if ( ! V_9 ) {
F_98 ( V_4 -> V_124 , V_114 -> V_122 ) ;
F_98 ( V_43 -> V_45 . V_114 , V_114 -> V_122 ) ;
V_4 -> V_125 &= ~ V_126 ;
}
return V_9 ? - V_127 : 0 ;
}
static int F_99 ( struct V_61 * V_4 ,
const unsigned char * V_114 , bool V_118 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
T_1 V_95 , V_48 = V_17 -> V_48 ;
for ( V_95 = V_43 -> V_45 . V_107 ? F_90 ( V_17 , 0 ) : 0 ;
V_95 < V_97 ;
V_95 = F_90 ( V_17 , V_95 ) ) {
V_43 -> V_45 . V_98 . V_101 ( V_43 , V_48 , V_114 , V_95 , V_118 ) ;
}
return 0 ;
}
static int F_100 ( struct V_61 * V_4 ,
const unsigned char * V_114 )
{
return F_99 ( V_4 , V_114 , true ) ;
}
static int F_101 ( struct V_61 * V_4 ,
const unsigned char * V_114 )
{
return F_99 ( V_4 , V_114 , false ) ;
}
static void F_102 ( struct V_61 * V_4 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_42 * V_43 = & V_17 -> V_43 ;
int V_128 ;
if ( ! ( V_4 -> V_110 & V_123 ) )
return;
V_128 = ( V_4 -> V_110 & V_111 ) ? V_129 :
( V_4 -> V_110 & V_130 ) ? V_131 :
( V_4 -> V_110 & ( V_132 | V_133 ) ) ?
V_134 : V_135 ;
F_84 ( V_17 ) ;
if ( V_17 -> V_128 != V_128 ) {
if ( V_128 == V_129 )
V_43 -> V_45 . V_98 . V_112 ( V_43 , V_136 , 0 , true ) ;
if ( V_17 -> V_128 == V_129 )
F_92 ( V_17 ) ;
V_43 -> V_45 . V_98 . V_137 ( V_43 , V_17 -> V_48 , V_128 ) ;
V_17 -> V_128 = V_128 ;
}
if ( V_128 != V_129 ) {
F_103 ( V_4 , F_95 , F_96 ) ;
if ( V_128 != V_131 )
F_104 ( V_4 , F_100 , F_101 ) ;
}
F_87 ( V_17 ) ;
}
void F_105 ( struct V_16 * V_17 )
{
struct V_61 * V_21 = V_17 -> V_21 ;
struct V_42 * V_43 = & V_17 -> V_43 ;
int V_128 ;
T_1 V_95 , V_48 ;
V_48 = V_17 -> V_48 ;
if ( V_21 -> V_110 & V_111 )
V_128 = V_129 ;
else if ( V_21 -> V_110 & V_130 )
V_128 = V_131 ;
else if ( V_21 -> V_110 & ( V_132 | V_133 ) )
V_128 = V_134 ;
else
V_128 = V_135 ;
F_84 ( V_17 ) ;
V_43 -> V_45 . V_98 . V_138 ( V_43 , V_48 , V_17 -> V_50 , true ) ;
V_43 -> V_45 . V_98 . V_112 ( V_43 , V_136 , 0 ,
V_128 == V_129 ) ;
V_43 -> V_45 . V_98 . V_112 ( V_43 , 0 , 0 , true ) ;
for ( V_95 = V_43 -> V_45 . V_107 ? F_90 ( V_17 , 0 ) : 0 ;
V_95 < V_97 ;
V_95 = F_90 ( V_17 , V_95 ) ) {
V_43 -> V_45 . V_98 . V_112 ( V_43 , V_95 , 0 , true ) ;
V_43 -> V_45 . V_98 . V_99 ( V_43 , V_48 , V_43 -> V_45 . V_114 ,
V_95 , true , 0 ) ;
}
V_43 -> V_45 . V_98 . V_137 ( V_43 , V_48 , V_128 ) ;
if ( V_128 != V_129 ) {
F_103 ( V_21 , F_95 , F_96 ) ;
if ( V_128 != V_131 )
F_104 ( V_21 , F_100 , F_101 ) ;
}
F_87 ( V_17 ) ;
V_17 -> V_128 = V_128 ;
F_37 ( V_17 ) ;
}
void F_106 ( struct V_16 * V_17 )
{
struct V_61 * V_21 = V_17 -> V_21 ;
struct V_42 * V_43 = & V_17 -> V_43 ;
F_84 ( V_17 ) ;
V_43 -> V_45 . V_98 . V_138 ( V_43 , V_17 -> V_48 ,
V_17 -> V_50 , false ) ;
F_87 ( V_17 ) ;
V_17 -> V_128 = V_135 ;
F_85 ( V_21 , NULL ) ;
F_86 ( V_21 , NULL ) ;
}
static struct V_139 * F_107 ( struct V_61 * V_21 ,
struct V_139 * V_140 )
{
struct V_16 * V_17 = F_41 ( V_21 ) ;
struct V_1 * V_29 ;
unsigned int V_141 , V_18 ;
T_8 V_142 , V_143 ;
F_108 () ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = F_109 ( V_17 -> V_23 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_141 = F_110 ( & V_29 -> V_10 ) ;
V_143 = V_29 -> V_140 . V_143 ;
V_142 = V_29 -> V_140 . V_142 ;
} while ( F_111 ( & V_29 -> V_10 , V_141 ) );
V_140 -> V_144 += V_143 ;
V_140 -> V_145 += V_142 ;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_29 = F_109 ( V_17 -> V_2 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_141 = F_110 ( & V_29 -> V_10 ) ;
V_143 = V_29 -> V_140 . V_143 ;
V_142 = V_29 -> V_140 . V_142 ;
} while ( F_111 ( & V_29 -> V_10 , V_141 ) );
V_140 -> V_146 += V_143 ;
V_140 -> V_147 += V_142 ;
}
F_112 () ;
V_140 -> V_148 = V_21 -> V_140 . V_148 ;
return V_140 ;
}
int F_113 ( struct V_61 * V_4 , T_9 V_149 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
int V_9 ;
if ( V_149 && ( V_17 -> V_43 . V_45 . type != V_56 ) )
return - V_88 ;
if ( V_149 > 8 )
return - V_88 ;
if ( F_114 ( V_4 ) )
F_54 ( V_4 ) ;
F_115 ( V_17 ) ;
F_116 ( V_17 ) ;
F_117 ( V_4 ) ;
F_118 ( V_4 , V_149 ) ;
V_9 = F_119 ( V_17 ) ;
if ( V_9 )
goto V_150;
V_9 = F_120 ( V_17 ) ;
if ( V_9 )
goto V_151;
V_9 = F_114 ( V_4 ) ? F_46 ( V_4 ) : 0 ;
if ( V_9 )
goto V_152;
V_17 -> V_110 |= V_153 ;
return 0 ;
V_152:
F_115 ( V_17 ) ;
V_151:
F_116 ( V_17 ) ;
V_150:
F_121 ( V_4 ) ;
return V_9 ;
}
static int F_122 ( struct V_61 * V_4 , T_7 V_154 , T_3 V_74 ,
struct V_155 * V_149 )
{
if ( V_149 -> type != V_156 )
return - V_88 ;
return F_113 ( V_4 , V_149 -> V_149 ) ;
}
static int F_123 ( struct V_61 * V_21 , struct V_157 * V_158 , int V_159 )
{
switch ( V_159 ) {
case V_160 :
return F_124 ( V_21 , V_158 ) ;
case V_161 :
return F_125 ( V_21 , V_158 ) ;
default:
return - V_162 ;
}
}
static void F_126 ( struct V_16 * V_17 ,
struct V_163 * V_164 )
{
struct V_1 * V_29 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = V_17 -> V_23 [ V_18 ] ;
F_127 ( V_29 -> V_164 , V_164 ) ;
}
V_17 -> V_164 = V_164 ;
}
static void * F_128 ( struct V_61 * V_4 ,
struct V_61 * V_165 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_163 * V_164 = V_17 -> V_164 ;
struct V_163 * V_166 = NULL ;
struct V_167 V_168 = { 0 } ;
struct V_42 * V_43 = & V_17 -> V_43 ;
int V_5 = 0 , V_18 ;
T_1 V_48 ;
if ( ! V_164 ) {
if ( V_17 -> V_50 < 7 )
return F_129 ( - V_169 ) ;
V_5 = F_130 ( struct V_163 , V_170 [ 7 ] ) ;
V_164 = F_131 ( V_5 , V_14 ) ;
if ( ! V_164 )
return F_129 ( - V_15 ) ;
V_164 -> V_5 = 7 ;
V_164 -> V_168 = V_17 -> V_48 ;
F_126 ( V_17 , V_164 ) ;
} else if ( ( V_164 -> V_7 == V_171 ) ||
( V_164 -> V_7 == ( V_17 -> V_50 - 1 ) ) ) {
return F_129 ( - V_169 ) ;
} else if ( V_164 -> V_7 == V_164 -> V_5 ) {
V_166 = V_164 ;
V_5 = F_130 ( struct V_163 ,
V_170 [ ( V_164 -> V_5 * 2 ) + 1 ] ) ;
V_164 = F_131 ( V_5 , V_14 ) ;
if ( ! V_164 )
return F_129 ( - V_15 ) ;
memcpy ( V_164 , V_166 ,
F_130 ( struct V_163 ,
V_170 [ V_166 -> V_5 ] ) ) ;
V_164 -> V_5 = ( V_166 -> V_5 * 2 ) + 1 ;
F_126 ( V_17 , V_164 ) ;
F_132 ( V_166 , V_172 ) ;
}
for ( V_18 = 0 ; V_18 < V_164 -> V_5 ; V_18 ++ ) {
if ( ! V_164 -> V_170 [ V_18 ] )
break;
}
V_164 -> V_170 [ V_18 ] = V_165 ;
V_164 -> V_7 ++ ;
V_168 . V_173 = V_174 ;
V_168 . V_175 = 1 ;
V_168 . V_176 = F_133 ( V_17 -> V_177 [ V_178 ] . V_44 ) ;
V_168 . V_179 = F_133 ( V_17 -> V_177 [ V_180 ] . V_44 ) ;
V_168 . V_48 = V_17 -> V_48 ;
V_168 . V_181 = F_133 ( V_164 -> V_5 ) ;
V_43 -> V_45 . V_98 . V_182 ( V_43 , & V_168 ) ;
F_84 ( V_17 ) ;
V_48 = V_164 -> V_168 + 1 + V_18 ;
V_43 -> V_45 . V_98 . V_137 ( V_43 , V_48 , V_134 ) ;
V_43 -> V_45 . V_98 . V_99 ( V_43 , V_48 , V_165 -> V_124 , 0 , true , 0 ) ;
F_87 ( V_17 ) ;
return V_165 ;
}
static void F_134 ( struct V_61 * V_4 , void * V_183 )
{
struct V_16 * V_17 = F_41 ( V_4 ) ;
struct V_163 * V_164 = F_109 ( V_17 -> V_164 ) ;
struct V_167 V_168 = { 0 } ;
struct V_42 * V_43 = & V_17 -> V_43 ;
struct V_61 * V_165 = V_183 ;
int V_18 ;
T_1 V_48 ;
if ( ! V_164 )
return;
for ( V_18 = 0 ; V_18 < V_164 -> V_5 ; V_18 ++ ) {
if ( V_164 -> V_170 [ V_18 ] == V_165 )
break;
}
if ( V_18 == V_164 -> V_5 )
return;
F_84 ( V_17 ) ;
V_48 = V_164 -> V_168 + 1 + V_18 ;
V_43 -> V_45 . V_98 . V_137 ( V_43 , V_48 , V_135 ) ;
V_43 -> V_45 . V_98 . V_99 ( V_43 , V_48 , V_165 -> V_124 , 0 , false , 0 ) ;
F_87 ( V_17 ) ;
V_164 -> V_170 [ V_18 ] = NULL ;
V_164 -> V_7 -- ;
V_168 . V_173 = V_174 ;
V_168 . V_175 = 1 ;
V_168 . V_176 = F_133 ( V_17 -> V_177 [ V_178 ] . V_44 ) ;
V_168 . V_179 = F_133 ( V_17 -> V_177 [ V_180 ] . V_44 ) ;
V_168 . V_48 = V_17 -> V_48 ;
V_168 . V_181 = F_133 ( V_164 -> V_5 ) ;
V_43 -> V_45 . V_98 . V_182 ( V_43 , & V_168 ) ;
if ( V_164 -> V_7 == 0 ) {
F_126 ( V_17 , NULL ) ;
F_132 ( V_164 , V_172 ) ;
}
}
static T_10 F_135 ( struct V_67 * V_30 ,
struct V_61 * V_4 ,
T_10 V_184 )
{
if ( ! V_30 -> V_185 || F_136 ( V_30 ) )
return V_184 ;
return V_184 & ~ ( V_186 | V_187 ) ;
}
struct V_61 * F_137 ( const struct V_188 * V_189 )
{
T_10 V_190 ;
struct V_16 * V_17 ;
struct V_61 * V_4 ;
V_4 = F_138 ( sizeof( struct V_16 ) , V_191 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_192 = & V_193 ;
F_139 ( V_4 ) ;
V_17 = F_41 ( V_4 ) ;
V_17 -> V_194 = ( 1 << V_195 ) - 1 ;
V_4 -> V_184 |= V_196 |
V_197 |
V_198 |
V_199 |
V_200 |
V_201 |
V_202 |
V_203 ;
if ( V_189 -> V_45 == V_56 ) {
V_4 -> V_204 = V_196 |
V_199 |
V_200 |
V_201 |
V_205 |
V_197 |
V_198 ;
V_4 -> V_184 |= V_205 ;
}
V_190 = V_4 -> V_184 ;
V_190 |= V_206 ;
V_4 -> V_207 |= V_4 -> V_184 ;
V_4 -> V_184 |= V_208 |
V_209 |
V_210 ;
V_4 -> V_211 |= V_212 ;
V_4 -> V_190 |= V_190 ;
return V_4 ;
}
