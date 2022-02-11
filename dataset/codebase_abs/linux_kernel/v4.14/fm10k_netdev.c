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
V_53 = F_33 ( & V_17 -> V_54 ,
struct V_52 , V_55 ) ;
while ( V_53 ) {
F_34 ( & V_53 -> V_55 ) ;
F_35 ( V_53 ) ;
V_53 = F_33 ( & V_17 -> V_54 ,
struct V_52 ,
V_55 ) ;
}
V_53 = F_33 ( & V_17 -> V_56 ,
struct V_52 , V_55 ) ;
while ( V_53 ) {
F_34 ( & V_53 -> V_55 ) ;
F_35 ( V_53 ) ;
V_53 = F_33 ( & V_17 -> V_54 ,
struct V_52 ,
V_55 ) ;
}
}
static void F_36 ( struct V_16 * V_17 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_52 * V_53 ;
if ( V_42 -> V_44 . type != V_57 )
return;
V_53 = F_33 ( & V_17 -> V_54 ,
struct V_52 , V_55 ) ;
F_37 ( V_42 , V_58 ,
( V_53 ? F_38 ( V_53 -> V_53 ) : 0 ) |
( V_59 << V_60 ) ) ;
V_53 = F_33 ( & V_17 -> V_56 ,
struct V_52 , V_55 ) ;
F_37 ( V_42 , V_61 ,
( V_53 ? F_38 ( V_53 -> V_53 ) : 0 ) ) ;
}
static struct V_52 *
F_39 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_52 * V_53 ;
F_40 (port, ports, list) {
if ( ( V_53 -> V_53 == V_65 -> V_53 ) &&
( V_53 -> V_66 == V_65 -> V_66 ) ) {
F_34 ( & V_53 -> V_55 ) ;
return V_53 ;
}
}
return NULL ;
}
static void F_41 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_52 * V_53 ;
V_53 = F_39 ( V_63 , V_65 ) ;
if ( ! V_53 ) {
V_53 = F_42 ( sizeof( * V_53 ) , V_67 ) ;
if ( ! V_53 )
return;
V_53 -> V_53 = V_65 -> V_53 ;
V_53 -> V_66 = V_65 -> V_66 ;
}
F_43 ( & V_53 -> V_55 , V_63 ) ;
}
static void F_44 ( struct V_68 * V_4 ,
struct V_64 * V_65 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
if ( V_17 -> V_42 . V_44 . type != V_57 )
return;
switch ( V_65 -> type ) {
case V_69 :
F_41 ( & V_17 -> V_54 , V_65 ) ;
break;
case V_70 :
F_41 ( & V_17 -> V_56 , V_65 ) ;
break;
default:
return;
}
F_36 ( V_17 ) ;
}
static void F_46 ( struct V_68 * V_4 ,
struct V_64 * V_65 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_52 * V_53 = NULL ;
if ( V_17 -> V_42 . V_44 . type != V_57 )
return;
switch ( V_65 -> type ) {
case V_69 :
V_53 = F_39 ( & V_17 -> V_54 , V_65 ) ;
break;
case V_70 :
V_53 = F_39 ( & V_17 -> V_56 , V_65 ) ;
break;
default:
return;
}
F_35 ( V_53 ) ;
F_36 ( V_17 ) ;
}
int F_47 ( struct V_68 * V_21 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
int V_9 ;
V_9 = F_7 ( V_17 ) ;
if ( V_9 )
goto V_22;
V_9 = F_11 ( V_17 ) ;
if ( V_9 )
goto V_28;
V_9 = F_48 ( V_17 ) ;
if ( V_9 )
goto V_71;
F_31 ( V_17 ) ;
V_9 = F_49 ( V_21 ,
V_17 -> V_19 ) ;
if ( V_9 )
goto V_72;
V_9 = F_50 ( V_21 ,
V_17 -> V_27 ) ;
if ( V_9 )
goto V_72;
F_51 ( V_21 ) ;
F_52 ( V_17 ) ;
return 0 ;
V_72:
F_53 ( V_17 ) ;
V_71:
F_30 ( V_17 ) ;
V_28:
F_25 ( V_17 ) ;
V_22:
return V_9 ;
}
int F_54 ( struct V_68 * V_21 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
F_55 ( V_17 ) ;
F_53 ( V_17 ) ;
F_32 ( V_17 ) ;
F_25 ( V_17 ) ;
F_30 ( V_17 ) ;
return 0 ;
}
static T_2 F_56 ( struct V_73 * V_30 , struct V_68 * V_4 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
unsigned int V_74 = V_30 -> V_75 ;
int V_9 ;
if ( ( V_30 -> V_76 == F_57 ( V_77 ) ) &&
! F_58 ( V_30 ) ) {
struct V_78 * V_79 ;
T_3 V_80 ;
V_30 = F_59 ( V_30 , V_67 ) ;
if ( ! V_30 )
return V_81 ;
if ( F_60 ( ! F_61 ( V_30 , V_82 ) ) )
return V_81 ;
V_9 = F_62 ( V_30 , 0 ) ;
if ( V_9 ) {
F_27 ( V_30 ) ;
return V_81 ;
}
V_79 = (struct V_78 * ) ( V_30 -> V_83 + V_84 ) ;
F_63 ( V_30 ,
F_57 ( V_77 ) ,
F_38 ( V_79 -> V_85 ) ) ;
V_80 = V_79 -> V_86 ;
V_30 -> V_76 = ( F_38 ( V_80 ) >= 1536 ) ? V_80 :
F_57 ( V_87 ) ;
memmove ( V_30 -> V_83 + V_88 , V_30 -> V_83 , 12 ) ;
F_64 ( V_30 , V_88 ) ;
F_65 ( V_30 ) ;
}
if ( F_60 ( V_30 -> V_31 < 17 ) ) {
int V_89 = 17 - V_30 -> V_31 ;
if ( F_66 ( V_30 , V_89 ) )
return V_81 ;
F_67 ( V_30 , V_89 ) ;
}
if ( V_74 >= V_17 -> V_19 )
V_74 %= V_17 -> V_19 ;
V_9 = F_68 ( V_30 , V_17 -> V_2 [ V_74 ] ) ;
return V_9 ;
}
static void F_69 ( struct V_68 * V_21 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
bool V_90 = false ;
int V_18 ;
#define F_70 16000
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
struct V_1 * V_2 = V_17 -> V_2 [ V_18 ] ;
if ( F_71 ( V_2 ) && F_72 ( V_2 ) )
V_90 = true ;
}
if ( V_90 ) {
F_73 ( V_17 ) ;
} else {
F_74 ( V_17 , V_91 , V_21 ,
L_3 ,
V_21 -> V_92 / V_93 ) ;
if ( V_21 -> V_92 < F_70 )
V_21 -> V_92 *= 2 ;
}
}
static bool F_75 ( struct V_16 * V_17 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
return ( V_42 -> V_44 . type == V_94 || V_17 -> V_95 ) ;
}
static int F_76 ( struct V_68 * V_21 ,
const unsigned char * V_96 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_47 = V_17 -> V_47 ;
T_1 V_97 = V_17 -> V_97 ;
bool V_98 = ! ! ( V_97 / V_99 ) ;
int V_9 = - V_100 ;
V_97 &= V_99 - 1 ;
if ( F_75 ( V_17 ) )
V_9 = V_42 -> V_44 . V_101 . V_102 ( V_42 , V_47 , V_96 ,
V_97 , V_98 , 0 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_77 ( struct V_68 * V_21 ,
const unsigned char * V_103 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_47 = V_17 -> V_47 ;
T_1 V_97 = V_17 -> V_97 ;
bool V_98 = ! ! ( V_97 / V_99 ) ;
int V_9 = - V_100 ;
V_97 &= V_99 - 1 ;
if ( F_75 ( V_17 ) )
V_9 = V_42 -> V_44 . V_101 . V_104 ( V_42 , V_47 , V_103 , V_97 , V_98 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
static int F_78 ( struct V_68 * V_21 , T_1 V_97 , bool V_98 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_4 V_9 ;
int V_18 ;
if ( ! V_97 )
return 0 ;
if ( V_97 >= V_99 )
return - V_105 ;
if ( V_42 -> V_44 . V_106 )
return - V_107 ;
F_79 ( V_97 , V_17 -> V_108 ) ;
if ( ! V_98 )
F_80 ( V_97 , V_17 -> V_108 ) ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
struct V_1 * V_23 = V_17 -> V_23 [ V_18 ] ;
T_1 V_109 = V_23 -> V_97 & ( V_99 - 1 ) ;
if ( F_81 ( V_109 , V_17 -> V_108 ) )
V_23 -> V_97 |= V_110 ;
else
V_23 -> V_97 &= ~ V_110 ;
}
if ( ! V_98 && V_97 == V_42 -> V_44 . V_111 )
return 0 ;
if ( F_81 ( V_112 , V_17 -> V_113 ) )
return 0 ;
F_82 ( V_17 ) ;
if ( ! ( V_21 -> V_114 & V_115 ) ) {
V_9 = V_42 -> V_44 . V_101 . V_116 ( V_42 , V_97 , 0 , V_98 ) ;
if ( V_9 )
goto V_117;
}
if ( F_75 ( V_17 ) )
V_9 = V_42 -> V_44 . V_101 . V_102 ( V_42 , V_17 -> V_47 ,
V_42 -> V_44 . V_118 , V_97 , V_98 , 0 ) ;
else
V_9 = - V_100 ;
if ( V_9 )
goto V_117;
V_17 -> V_97 = V_97 + ( V_98 ? V_99 : 0 ) ;
F_83 ( V_21 , F_76 ) ;
F_84 ( V_21 , F_77 ) ;
V_117:
F_85 ( V_17 ) ;
return V_9 ;
}
static int F_86 ( struct V_68 * V_21 ,
T_5 T_3 V_80 , T_1 V_97 )
{
return F_78 ( V_21 , V_97 , true ) ;
}
static int F_87 ( struct V_68 * V_21 ,
T_5 T_3 V_80 , T_1 V_97 )
{
return F_78 ( V_21 , V_97 , false ) ;
}
static T_1 F_88 ( struct V_16 * V_17 , T_1 V_97 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_111 = V_42 -> V_44 . V_111 ;
T_1 V_119 = V_97 < V_111 ? V_111 : V_99 ;
V_97 = F_89 ( V_17 -> V_108 , V_119 , ++ V_97 ) ;
return V_97 ;
}
static void F_90 ( struct V_16 * V_17 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_6 V_97 , V_120 ;
for ( V_97 = 0 , V_120 = 0 ;
V_120 < V_99 ;
V_120 = V_97 + 1 , V_97 = F_88 ( V_17 , V_97 ) ) {
if ( V_120 == V_97 )
continue;
V_120 += ( V_97 - V_120 - 1 ) << V_121 ;
V_42 -> V_44 . V_101 . V_116 ( V_42 , V_120 , 0 , false ) ;
}
}
static int F_91 ( struct V_68 * V_4 ,
const unsigned char * V_118 , bool V_122 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_97 , V_47 = V_17 -> V_47 ;
T_4 V_9 ;
if ( ! F_92 ( V_118 ) )
return - V_123 ;
if ( ! F_75 ( V_17 ) )
return - V_100 ;
for ( V_97 = V_42 -> V_44 . V_111 ? F_88 ( V_17 , 0 ) : 1 ;
V_97 < V_99 ;
V_97 = F_88 ( V_17 , V_97 ) ) {
V_9 = V_42 -> V_44 . V_101 . V_102 ( V_42 , V_47 , V_118 ,
V_97 , V_122 , 0 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_93 ( struct V_68 * V_4 ,
const unsigned char * V_118 )
{
return F_91 ( V_4 , V_118 , true ) ;
}
static int F_94 ( struct V_68 * V_4 ,
const unsigned char * V_118 )
{
return F_91 ( V_4 , V_118 , false ) ;
}
static int F_95 ( struct V_68 * V_4 , void * V_124 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_125 * V_118 = V_124 ;
T_4 V_9 = 0 ;
if ( ! F_92 ( V_118 -> V_126 ) )
return - V_123 ;
if ( V_4 -> V_114 & V_127 ) {
F_82 ( V_17 ) ;
V_9 = F_93 ( V_4 , V_118 -> V_126 ) ;
if ( ! V_9 )
F_94 ( V_4 , V_42 -> V_44 . V_118 ) ;
F_85 ( V_17 ) ;
}
if ( ! V_9 ) {
F_96 ( V_4 -> V_128 , V_118 -> V_126 ) ;
F_96 ( V_42 -> V_44 . V_118 , V_118 -> V_126 ) ;
V_4 -> V_129 &= ~ V_130 ;
}
return V_9 ? - V_131 : 0 ;
}
static int F_97 ( struct V_68 * V_4 ,
const unsigned char * V_118 , bool V_122 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_97 , V_47 = V_17 -> V_47 ;
if ( ! F_75 ( V_17 ) )
return 0 ;
for ( V_97 = V_42 -> V_44 . V_111 ? F_88 ( V_17 , 0 ) : 1 ;
V_97 < V_99 ;
V_97 = F_88 ( V_17 , V_97 ) ) {
V_42 -> V_44 . V_101 . V_104 ( V_42 , V_47 , V_118 , V_97 , V_122 ) ;
}
return 0 ;
}
static int F_98 ( struct V_68 * V_4 ,
const unsigned char * V_118 )
{
return F_97 ( V_4 , V_118 , true ) ;
}
static int F_99 ( struct V_68 * V_4 ,
const unsigned char * V_118 )
{
return F_97 ( V_4 , V_118 , false ) ;
}
static void F_100 ( struct V_68 * V_4 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_132 ;
if ( ! ( V_4 -> V_114 & V_127 ) )
return;
V_132 = ( V_4 -> V_114 & V_115 ) ? V_133 :
( V_4 -> V_114 & V_134 ) ? V_135 :
( V_4 -> V_114 & ( V_136 | V_137 ) ) ?
V_138 : V_139 ;
F_82 ( V_17 ) ;
if ( V_17 -> V_132 != V_132 ) {
if ( V_132 == V_133 )
V_42 -> V_44 . V_101 . V_116 ( V_42 , V_140 , 0 , true ) ;
if ( V_17 -> V_132 == V_133 )
F_90 ( V_17 ) ;
if ( F_75 ( V_17 ) )
V_42 -> V_44 . V_101 . V_141 ( V_42 , V_17 -> V_47 ,
V_132 ) ;
V_17 -> V_132 = V_132 ;
}
F_101 ( V_4 , F_93 , F_94 ) ;
F_102 ( V_4 , F_98 , F_99 ) ;
F_85 ( V_17 ) ;
}
void F_103 ( struct V_16 * V_17 )
{
struct V_68 * V_21 = V_17 -> V_21 ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_132 ;
T_1 V_97 , V_47 ;
V_47 = V_17 -> V_47 ;
if ( V_21 -> V_114 & V_115 )
V_132 = V_133 ;
else if ( V_21 -> V_114 & V_134 )
V_132 = V_135 ;
else if ( V_21 -> V_114 & ( V_136 | V_137 ) )
V_132 = V_138 ;
else
V_132 = V_139 ;
F_82 ( V_17 ) ;
if ( F_75 ( V_17 ) )
V_42 -> V_44 . V_101 . V_142 ( V_42 , V_47 ,
V_17 -> V_49 , true ) ;
V_42 -> V_44 . V_101 . V_116 ( V_42 , V_140 , 0 ,
V_132 == V_133 ) ;
V_42 -> V_44 . V_101 . V_116 ( V_42 , 0 , 0 , true ) ;
for ( V_97 = V_42 -> V_44 . V_111 ? F_88 ( V_17 , 0 ) : 1 ;
V_97 < V_99 ;
V_97 = F_88 ( V_17 , V_97 ) ) {
V_42 -> V_44 . V_101 . V_116 ( V_42 , V_97 , 0 , true ) ;
if ( F_75 ( V_17 ) )
V_42 -> V_44 . V_101 . V_102 ( V_42 , V_47 , V_42 -> V_44 . V_118 ,
V_97 , true , 0 ) ;
}
if ( F_75 ( V_17 ) )
V_42 -> V_44 . V_101 . V_141 ( V_42 , V_47 , V_132 ) ;
F_101 ( V_21 , F_93 , F_94 ) ;
F_102 ( V_21 , F_98 , F_99 ) ;
F_85 ( V_17 ) ;
V_17 -> V_132 = V_132 ;
F_36 ( V_17 ) ;
}
void F_104 ( struct V_16 * V_17 )
{
struct V_68 * V_21 = V_17 -> V_21 ;
struct V_41 * V_42 = & V_17 -> V_42 ;
F_82 ( V_17 ) ;
if ( F_75 ( V_17 ) )
V_42 -> V_44 . V_101 . V_142 ( V_42 , V_17 -> V_47 ,
V_17 -> V_49 , false ) ;
F_85 ( V_17 ) ;
V_17 -> V_132 = V_139 ;
F_83 ( V_21 , NULL ) ;
F_84 ( V_21 , NULL ) ;
}
static void F_105 ( struct V_68 * V_21 ,
struct V_143 * V_144 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
struct V_1 * V_29 ;
unsigned int V_145 , V_18 ;
T_7 V_146 , V_147 ;
F_106 () ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = F_107 ( V_17 -> V_23 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_145 = F_108 ( & V_29 -> V_10 ) ;
V_147 = V_29 -> V_144 . V_147 ;
V_146 = V_29 -> V_144 . V_146 ;
} while ( F_109 ( & V_29 -> V_10 , V_145 ) );
V_144 -> V_148 += V_147 ;
V_144 -> V_149 += V_146 ;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_29 = F_107 ( V_17 -> V_2 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_145 = F_108 ( & V_29 -> V_10 ) ;
V_147 = V_29 -> V_144 . V_147 ;
V_146 = V_29 -> V_144 . V_146 ;
} while ( F_109 ( & V_29 -> V_10 , V_145 ) );
V_144 -> V_150 += V_147 ;
V_144 -> V_151 += V_146 ;
}
F_110 () ;
V_144 -> V_152 = V_21 -> V_144 . V_152 ;
}
int F_111 ( struct V_68 * V_4 , T_8 V_153 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
int V_9 ;
if ( V_153 && ( V_17 -> V_42 . V_44 . type != V_57 ) )
return - V_105 ;
if ( V_153 > 8 )
return - V_105 ;
if ( F_112 ( V_4 ) )
F_54 ( V_4 ) ;
F_113 ( V_17 ) ;
F_114 ( V_17 ) ;
F_115 ( V_4 ) ;
F_116 ( V_4 , V_153 ) ;
V_9 = F_117 ( V_17 ) ;
if ( V_9 )
goto V_154;
V_9 = F_118 ( V_17 ) ;
if ( V_9 )
goto V_155;
V_9 = F_112 ( V_4 ) ? F_47 ( V_4 ) : 0 ;
if ( V_9 )
goto V_156;
F_79 ( V_157 , V_17 -> V_114 ) ;
return 0 ;
V_156:
F_113 ( V_17 ) ;
V_155:
F_114 ( V_17 ) ;
V_154:
F_119 ( V_4 ) ;
return V_9 ;
}
static int F_120 ( struct V_68 * V_4 , enum V_158 type ,
void * V_159 )
{
struct V_160 * V_161 = V_159 ;
if ( type != V_162 )
return - V_163 ;
V_161 -> V_42 = V_164 ;
return F_111 ( V_4 , V_161 -> V_165 ) ;
}
static void F_121 ( struct V_16 * V_17 ,
struct V_166 * V_167 )
{
struct V_1 * V_29 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = V_17 -> V_23 [ V_18 ] ;
F_122 ( V_29 -> V_167 , V_167 ) ;
}
V_17 -> V_167 = V_167 ;
}
static void * F_123 ( struct V_68 * V_4 ,
struct V_68 * V_168 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_166 * V_167 = V_17 -> V_167 ;
struct V_166 * V_169 = NULL ;
struct V_170 V_171 = { 0 } ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_5 = 0 , V_18 ;
T_1 V_47 ;
if ( ! V_167 ) {
if ( V_17 -> V_49 < 7 )
return F_124 ( - V_172 ) ;
V_5 = F_125 ( struct V_166 , V_173 [ 7 ] ) ;
V_167 = F_126 ( V_5 , V_14 ) ;
if ( ! V_167 )
return F_124 ( - V_15 ) ;
V_167 -> V_5 = 7 ;
V_167 -> V_171 = V_17 -> V_47 ;
F_121 ( V_17 , V_167 ) ;
} else if ( ( V_167 -> V_7 == V_174 ) ||
( V_167 -> V_7 == ( V_17 -> V_49 - 1 ) ) ) {
return F_124 ( - V_172 ) ;
} else if ( V_167 -> V_7 == V_167 -> V_5 ) {
V_169 = V_167 ;
V_5 = F_125 ( struct V_166 ,
V_173 [ ( V_167 -> V_5 * 2 ) + 1 ] ) ;
V_167 = F_126 ( V_5 , V_14 ) ;
if ( ! V_167 )
return F_124 ( - V_15 ) ;
memcpy ( V_167 , V_169 ,
F_125 ( struct V_166 ,
V_173 [ V_169 -> V_5 ] ) ) ;
V_167 -> V_5 = ( V_169 -> V_5 * 2 ) + 1 ;
F_121 ( V_17 , V_167 ) ;
F_127 ( V_169 , V_175 ) ;
}
for ( V_18 = 0 ; V_18 < V_167 -> V_5 ; V_18 ++ ) {
if ( ! V_167 -> V_173 [ V_18 ] )
break;
}
V_167 -> V_173 [ V_18 ] = V_168 ;
V_167 -> V_7 ++ ;
V_171 . V_176 = V_177 ;
V_171 . V_178 = 1 ;
V_171 . V_179 = F_128 ( V_17 -> V_180 [ V_181 ] . V_43 ) ;
V_171 . V_182 = F_128 ( V_17 -> V_180 [ V_183 ] . V_43 ) ;
V_171 . V_47 = V_17 -> V_47 ;
V_171 . V_184 = F_128 ( V_167 -> V_5 ) ;
V_42 -> V_44 . V_101 . V_185 ( V_42 , & V_171 ) ;
F_82 ( V_17 ) ;
V_47 = V_167 -> V_171 + 1 + V_18 ;
if ( F_75 ( V_17 ) ) {
V_42 -> V_44 . V_101 . V_141 ( V_42 , V_47 ,
V_138 ) ;
V_42 -> V_44 . V_101 . V_102 ( V_42 , V_47 , V_168 -> V_128 ,
0 , true , 0 ) ;
}
F_85 ( V_17 ) ;
return V_168 ;
}
static void F_129 ( struct V_68 * V_4 , void * V_186 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_166 * V_167 = F_107 ( V_17 -> V_167 ) ;
struct V_170 V_171 = { 0 } ;
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_68 * V_168 = V_186 ;
int V_18 ;
T_1 V_47 ;
if ( ! V_167 )
return;
for ( V_18 = 0 ; V_18 < V_167 -> V_5 ; V_18 ++ ) {
if ( V_167 -> V_173 [ V_18 ] == V_168 )
break;
}
if ( V_18 == V_167 -> V_5 )
return;
F_82 ( V_17 ) ;
V_47 = V_167 -> V_171 + 1 + V_18 ;
if ( F_75 ( V_17 ) ) {
V_42 -> V_44 . V_101 . V_141 ( V_42 , V_47 ,
V_139 ) ;
V_42 -> V_44 . V_101 . V_102 ( V_42 , V_47 , V_168 -> V_128 ,
0 , false , 0 ) ;
}
F_85 ( V_17 ) ;
V_167 -> V_173 [ V_18 ] = NULL ;
V_167 -> V_7 -- ;
V_171 . V_176 = V_177 ;
V_171 . V_178 = 1 ;
V_171 . V_179 = F_128 ( V_17 -> V_180 [ V_181 ] . V_43 ) ;
V_171 . V_182 = F_128 ( V_17 -> V_180 [ V_183 ] . V_43 ) ;
V_171 . V_47 = V_17 -> V_47 ;
V_171 . V_184 = F_128 ( V_167 -> V_5 ) ;
V_42 -> V_44 . V_101 . V_185 ( V_42 , & V_171 ) ;
if ( V_167 -> V_7 == 0 ) {
F_121 ( V_17 , NULL ) ;
F_127 ( V_167 , V_175 ) ;
}
}
static T_9 F_130 ( struct V_73 * V_30 ,
struct V_68 * V_4 ,
T_9 V_187 )
{
if ( ! V_30 -> V_188 || F_131 ( V_30 ) )
return V_187 ;
return V_187 & ~ ( V_189 | V_190 ) ;
}
struct V_68 * F_132 ( const struct V_191 * V_192 )
{
T_9 V_193 ;
struct V_16 * V_17 ;
struct V_68 * V_4 ;
V_4 = F_133 ( sizeof( struct V_16 ) , V_194 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_195 = & V_196 ;
F_134 ( V_4 ) ;
V_17 = F_45 ( V_4 ) ;
V_17 -> V_197 = F_135 ( V_198 ) - 1 ;
V_4 -> V_187 |= V_199 |
V_200 |
V_201 |
V_202 |
V_203 |
V_204 |
V_205 |
V_206 ;
if ( V_192 -> V_44 == V_57 ) {
V_4 -> V_207 = V_199 |
V_202 |
V_203 |
V_204 |
V_208 |
V_200 |
V_201 ;
V_4 -> V_187 |= V_208 ;
}
V_193 = V_4 -> V_187 ;
V_193 |= V_209 ;
V_4 -> V_210 |= V_4 -> V_187 ;
V_4 -> V_187 |= V_211 |
V_212 |
V_213 ;
V_4 -> V_214 |= V_215 ;
V_4 -> V_193 |= V_193 ;
V_4 -> V_216 = V_217 ;
V_4 -> V_218 = V_219 ;
return V_4 ;
}
