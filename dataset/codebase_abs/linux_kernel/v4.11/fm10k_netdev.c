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
static int F_75 ( struct V_68 * V_21 ,
const unsigned char * V_94 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
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
static int F_76 ( struct V_68 * V_21 ,
const unsigned char * V_100 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
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
static int F_77 ( struct V_68 * V_21 , T_1 V_95 , bool V_96 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_4 V_9 ;
int V_18 ;
if ( ! V_95 )
return 0 ;
if ( V_95 >= V_97 )
return - V_102 ;
if ( V_42 -> V_44 . V_103 )
return - V_104 ;
F_78 ( V_95 , V_17 -> V_105 ) ;
if ( ! V_96 )
F_79 ( V_95 , V_17 -> V_105 ) ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
struct V_1 * V_23 = V_17 -> V_23 [ V_18 ] ;
T_1 V_106 = V_23 -> V_95 & ( V_97 - 1 ) ;
if ( F_80 ( V_106 , V_17 -> V_105 ) )
V_23 -> V_95 |= V_107 ;
else
V_23 -> V_95 &= ~ V_107 ;
}
if ( ! V_96 && V_95 == V_42 -> V_44 . V_108 )
return 0 ;
if ( F_80 ( V_109 , & V_17 -> V_110 ) )
return 0 ;
F_81 ( V_17 ) ;
if ( ! ( V_21 -> V_111 & V_112 ) ) {
V_9 = V_42 -> V_44 . V_98 . V_113 ( V_42 , V_95 , 0 , V_96 ) ;
if ( V_9 )
goto V_114;
}
V_9 = V_42 -> V_44 . V_98 . V_99 ( V_42 , V_17 -> V_47 , V_42 -> V_44 . V_115 ,
V_95 , V_96 , 0 ) ;
if ( V_9 )
goto V_114;
V_17 -> V_95 = V_95 + ( V_96 ? V_97 : 0 ) ;
F_82 ( V_21 , F_75 ) ;
F_83 ( V_21 , F_76 ) ;
V_114:
F_84 ( V_17 ) ;
return V_9 ;
}
static int F_85 ( struct V_68 * V_21 ,
T_5 T_3 V_80 , T_1 V_95 )
{
return F_77 ( V_21 , V_95 , true ) ;
}
static int F_86 ( struct V_68 * V_21 ,
T_5 T_3 V_80 , T_1 V_95 )
{
return F_77 ( V_21 , V_95 , false ) ;
}
static T_1 F_87 ( struct V_16 * V_17 , T_1 V_95 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_108 = V_42 -> V_44 . V_108 ;
T_1 V_116 = V_95 < V_108 ? V_108 : V_97 ;
V_95 = F_88 ( V_17 -> V_105 , V_116 , ++ V_95 ) ;
return V_95 ;
}
static void F_89 ( struct V_16 * V_17 )
{
struct V_41 * V_42 = & V_17 -> V_42 ;
T_6 V_95 , V_117 ;
for ( V_95 = 0 , V_117 = 0 ;
V_117 < V_97 ;
V_117 = V_95 + 1 , V_95 = F_87 ( V_17 , V_95 ) ) {
if ( V_117 == V_95 )
continue;
V_117 += ( V_95 - V_117 - 1 ) << V_118 ;
V_42 -> V_44 . V_98 . V_113 ( V_42 , V_117 , 0 , false ) ;
}
}
static int F_90 ( struct V_68 * V_4 ,
const unsigned char * V_115 , bool V_119 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_95 , V_47 = V_17 -> V_47 ;
T_4 V_9 ;
if ( ! F_91 ( V_115 ) )
return - V_120 ;
for ( V_95 = V_42 -> V_44 . V_108 ? F_87 ( V_17 , 0 ) : 1 ;
V_95 < V_97 ;
V_95 = F_87 ( V_17 , V_95 ) ) {
V_9 = V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_115 ,
V_95 , V_119 , 0 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_92 ( struct V_68 * V_4 ,
const unsigned char * V_115 )
{
return F_90 ( V_4 , V_115 , true ) ;
}
static int F_93 ( struct V_68 * V_4 ,
const unsigned char * V_115 )
{
return F_90 ( V_4 , V_115 , false ) ;
}
static int F_94 ( struct V_68 * V_4 , void * V_121 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_122 * V_115 = V_121 ;
T_4 V_9 = 0 ;
if ( ! F_91 ( V_115 -> V_123 ) )
return - V_120 ;
if ( V_4 -> V_111 & V_124 ) {
F_81 ( V_17 ) ;
V_9 = F_92 ( V_4 , V_115 -> V_123 ) ;
if ( ! V_9 )
F_93 ( V_4 , V_42 -> V_44 . V_115 ) ;
F_84 ( V_17 ) ;
}
if ( ! V_9 ) {
F_95 ( V_4 -> V_125 , V_115 -> V_123 ) ;
F_95 ( V_42 -> V_44 . V_115 , V_115 -> V_123 ) ;
V_4 -> V_126 &= ~ V_127 ;
}
return V_9 ? - V_128 : 0 ;
}
static int F_96 ( struct V_68 * V_4 ,
const unsigned char * V_115 , bool V_119 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
T_1 V_95 , V_47 = V_17 -> V_47 ;
for ( V_95 = V_42 -> V_44 . V_108 ? F_87 ( V_17 , 0 ) : 1 ;
V_95 < V_97 ;
V_95 = F_87 ( V_17 , V_95 ) ) {
V_42 -> V_44 . V_98 . V_101 ( V_42 , V_47 , V_115 , V_95 , V_119 ) ;
}
return 0 ;
}
static int F_97 ( struct V_68 * V_4 ,
const unsigned char * V_115 )
{
return F_96 ( V_4 , V_115 , true ) ;
}
static int F_98 ( struct V_68 * V_4 ,
const unsigned char * V_115 )
{
return F_96 ( V_4 , V_115 , false ) ;
}
static void F_99 ( struct V_68 * V_4 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_129 ;
if ( ! ( V_4 -> V_111 & V_124 ) )
return;
V_129 = ( V_4 -> V_111 & V_112 ) ? V_130 :
( V_4 -> V_111 & V_131 ) ? V_132 :
( V_4 -> V_111 & ( V_133 | V_134 ) ) ?
V_135 : V_136 ;
F_81 ( V_17 ) ;
if ( V_17 -> V_129 != V_129 ) {
if ( V_129 == V_130 )
V_42 -> V_44 . V_98 . V_113 ( V_42 , V_137 , 0 , true ) ;
if ( V_17 -> V_129 == V_130 )
F_89 ( V_17 ) ;
V_42 -> V_44 . V_98 . V_138 ( V_42 , V_17 -> V_47 , V_129 ) ;
V_17 -> V_129 = V_129 ;
}
F_100 ( V_4 , F_92 , F_93 ) ;
F_101 ( V_4 , F_97 , F_98 ) ;
F_84 ( V_17 ) ;
}
void F_102 ( struct V_16 * V_17 )
{
struct V_68 * V_21 = V_17 -> V_21 ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_129 ;
T_1 V_95 , V_47 ;
V_47 = V_17 -> V_47 ;
if ( V_21 -> V_111 & V_112 )
V_129 = V_130 ;
else if ( V_21 -> V_111 & V_131 )
V_129 = V_132 ;
else if ( V_21 -> V_111 & ( V_133 | V_134 ) )
V_129 = V_135 ;
else
V_129 = V_136 ;
F_81 ( V_17 ) ;
V_42 -> V_44 . V_98 . V_139 ( V_42 , V_47 , V_17 -> V_49 , true ) ;
V_42 -> V_44 . V_98 . V_113 ( V_42 , V_137 , 0 ,
V_129 == V_130 ) ;
V_42 -> V_44 . V_98 . V_113 ( V_42 , 0 , 0 , true ) ;
for ( V_95 = V_42 -> V_44 . V_108 ? F_87 ( V_17 , 0 ) : 1 ;
V_95 < V_97 ;
V_95 = F_87 ( V_17 , V_95 ) ) {
V_42 -> V_44 . V_98 . V_113 ( V_42 , V_95 , 0 , true ) ;
V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_42 -> V_44 . V_115 ,
V_95 , true , 0 ) ;
}
V_42 -> V_44 . V_98 . V_138 ( V_42 , V_47 , V_129 ) ;
F_100 ( V_21 , F_92 , F_93 ) ;
F_101 ( V_21 , F_97 , F_98 ) ;
F_84 ( V_17 ) ;
V_17 -> V_129 = V_129 ;
F_36 ( V_17 ) ;
}
void F_103 ( struct V_16 * V_17 )
{
struct V_68 * V_21 = V_17 -> V_21 ;
struct V_41 * V_42 = & V_17 -> V_42 ;
F_81 ( V_17 ) ;
V_42 -> V_44 . V_98 . V_139 ( V_42 , V_17 -> V_47 ,
V_17 -> V_49 , false ) ;
F_84 ( V_17 ) ;
V_17 -> V_129 = V_136 ;
F_82 ( V_21 , NULL ) ;
F_83 ( V_21 , NULL ) ;
}
static void F_104 ( struct V_68 * V_21 ,
struct V_140 * V_141 )
{
struct V_16 * V_17 = F_45 ( V_21 ) ;
struct V_1 * V_29 ;
unsigned int V_142 , V_18 ;
T_7 V_143 , V_144 ;
F_105 () ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = F_106 ( V_17 -> V_23 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_142 = F_107 ( & V_29 -> V_10 ) ;
V_144 = V_29 -> V_141 . V_144 ;
V_143 = V_29 -> V_141 . V_143 ;
} while ( F_108 ( & V_29 -> V_10 , V_142 ) );
V_141 -> V_145 += V_144 ;
V_141 -> V_146 += V_143 ;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
V_29 = F_106 ( V_17 -> V_2 [ V_18 ] ) ;
if ( ! V_29 )
continue;
do {
V_142 = F_107 ( & V_29 -> V_10 ) ;
V_144 = V_29 -> V_141 . V_144 ;
V_143 = V_29 -> V_141 . V_143 ;
} while ( F_108 ( & V_29 -> V_10 , V_142 ) );
V_141 -> V_147 += V_144 ;
V_141 -> V_148 += V_143 ;
}
F_109 () ;
V_141 -> V_149 = V_21 -> V_141 . V_149 ;
}
int F_110 ( struct V_68 * V_4 , T_8 V_150 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
int V_9 ;
if ( V_150 && ( V_17 -> V_42 . V_44 . type != V_57 ) )
return - V_102 ;
if ( V_150 > 8 )
return - V_102 ;
if ( F_111 ( V_4 ) )
F_54 ( V_4 ) ;
F_112 ( V_17 ) ;
F_113 ( V_17 ) ;
F_114 ( V_4 ) ;
F_115 ( V_4 , V_150 ) ;
V_9 = F_116 ( V_17 ) ;
if ( V_9 )
goto V_151;
V_9 = F_117 ( V_17 ) ;
if ( V_9 )
goto V_152;
V_9 = F_111 ( V_4 ) ? F_47 ( V_4 ) : 0 ;
if ( V_9 )
goto V_153;
V_17 -> V_111 |= V_154 ;
return 0 ;
V_153:
F_112 ( V_17 ) ;
V_152:
F_113 ( V_17 ) ;
V_151:
F_118 ( V_4 ) ;
return V_9 ;
}
static int F_119 ( struct V_68 * V_4 , T_6 V_155 , T_3 V_80 ,
struct V_156 * V_150 )
{
if ( V_150 -> type != V_157 )
return - V_102 ;
return F_110 ( V_4 , V_150 -> V_150 ) ;
}
static void F_120 ( struct V_16 * V_17 ,
struct V_158 * V_159 )
{
struct V_1 * V_29 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_27 ; V_18 ++ ) {
V_29 = V_17 -> V_23 [ V_18 ] ;
F_121 ( V_29 -> V_159 , V_159 ) ;
}
V_17 -> V_159 = V_159 ;
}
static void * F_122 ( struct V_68 * V_4 ,
struct V_68 * V_160 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_158 * V_159 = V_17 -> V_159 ;
struct V_158 * V_161 = NULL ;
struct V_162 V_163 = { 0 } ;
struct V_41 * V_42 = & V_17 -> V_42 ;
int V_5 = 0 , V_18 ;
T_1 V_47 ;
if ( ! V_159 ) {
if ( V_17 -> V_49 < 7 )
return F_123 ( - V_164 ) ;
V_5 = F_124 ( struct V_158 , V_165 [ 7 ] ) ;
V_159 = F_125 ( V_5 , V_14 ) ;
if ( ! V_159 )
return F_123 ( - V_15 ) ;
V_159 -> V_5 = 7 ;
V_159 -> V_163 = V_17 -> V_47 ;
F_120 ( V_17 , V_159 ) ;
} else if ( ( V_159 -> V_7 == V_166 ) ||
( V_159 -> V_7 == ( V_17 -> V_49 - 1 ) ) ) {
return F_123 ( - V_164 ) ;
} else if ( V_159 -> V_7 == V_159 -> V_5 ) {
V_161 = V_159 ;
V_5 = F_124 ( struct V_158 ,
V_165 [ ( V_159 -> V_5 * 2 ) + 1 ] ) ;
V_159 = F_125 ( V_5 , V_14 ) ;
if ( ! V_159 )
return F_123 ( - V_15 ) ;
memcpy ( V_159 , V_161 ,
F_124 ( struct V_158 ,
V_165 [ V_161 -> V_5 ] ) ) ;
V_159 -> V_5 = ( V_161 -> V_5 * 2 ) + 1 ;
F_120 ( V_17 , V_159 ) ;
F_126 ( V_161 , V_167 ) ;
}
for ( V_18 = 0 ; V_18 < V_159 -> V_5 ; V_18 ++ ) {
if ( ! V_159 -> V_165 [ V_18 ] )
break;
}
V_159 -> V_165 [ V_18 ] = V_160 ;
V_159 -> V_7 ++ ;
V_163 . V_168 = V_169 ;
V_163 . V_170 = 1 ;
V_163 . V_171 = F_127 ( V_17 -> V_172 [ V_173 ] . V_43 ) ;
V_163 . V_174 = F_127 ( V_17 -> V_172 [ V_175 ] . V_43 ) ;
V_163 . V_47 = V_17 -> V_47 ;
V_163 . V_176 = F_127 ( V_159 -> V_5 ) ;
V_42 -> V_44 . V_98 . V_177 ( V_42 , & V_163 ) ;
F_81 ( V_17 ) ;
V_47 = V_159 -> V_163 + 1 + V_18 ;
V_42 -> V_44 . V_98 . V_138 ( V_42 , V_47 , V_135 ) ;
V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_160 -> V_125 , 0 , true , 0 ) ;
F_84 ( V_17 ) ;
return V_160 ;
}
static void F_128 ( struct V_68 * V_4 , void * V_178 )
{
struct V_16 * V_17 = F_45 ( V_4 ) ;
struct V_158 * V_159 = F_106 ( V_17 -> V_159 ) ;
struct V_162 V_163 = { 0 } ;
struct V_41 * V_42 = & V_17 -> V_42 ;
struct V_68 * V_160 = V_178 ;
int V_18 ;
T_1 V_47 ;
if ( ! V_159 )
return;
for ( V_18 = 0 ; V_18 < V_159 -> V_5 ; V_18 ++ ) {
if ( V_159 -> V_165 [ V_18 ] == V_160 )
break;
}
if ( V_18 == V_159 -> V_5 )
return;
F_81 ( V_17 ) ;
V_47 = V_159 -> V_163 + 1 + V_18 ;
V_42 -> V_44 . V_98 . V_138 ( V_42 , V_47 , V_136 ) ;
V_42 -> V_44 . V_98 . V_99 ( V_42 , V_47 , V_160 -> V_125 , 0 , false , 0 ) ;
F_84 ( V_17 ) ;
V_159 -> V_165 [ V_18 ] = NULL ;
V_159 -> V_7 -- ;
V_163 . V_168 = V_169 ;
V_163 . V_170 = 1 ;
V_163 . V_171 = F_127 ( V_17 -> V_172 [ V_173 ] . V_43 ) ;
V_163 . V_174 = F_127 ( V_17 -> V_172 [ V_175 ] . V_43 ) ;
V_163 . V_47 = V_17 -> V_47 ;
V_163 . V_176 = F_127 ( V_159 -> V_5 ) ;
V_42 -> V_44 . V_98 . V_177 ( V_42 , & V_163 ) ;
if ( V_159 -> V_7 == 0 ) {
F_120 ( V_17 , NULL ) ;
F_126 ( V_159 , V_167 ) ;
}
}
static T_9 F_129 ( struct V_73 * V_30 ,
struct V_68 * V_4 ,
T_9 V_179 )
{
if ( ! V_30 -> V_180 || F_130 ( V_30 ) )
return V_179 ;
return V_179 & ~ ( V_181 | V_182 ) ;
}
struct V_68 * F_131 ( const struct V_183 * V_184 )
{
T_9 V_185 ;
struct V_16 * V_17 ;
struct V_68 * V_4 ;
V_4 = F_132 ( sizeof( struct V_16 ) , V_186 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_187 = & V_188 ;
F_133 ( V_4 ) ;
V_17 = F_45 ( V_4 ) ;
V_17 -> V_189 = F_134 ( V_190 ) - 1 ;
V_4 -> V_179 |= V_191 |
V_192 |
V_193 |
V_194 |
V_195 |
V_196 |
V_197 |
V_198 ;
if ( V_184 -> V_44 == V_57 ) {
V_4 -> V_199 = V_191 |
V_194 |
V_195 |
V_196 |
V_200 |
V_192 |
V_193 ;
V_4 -> V_179 |= V_200 ;
}
V_185 = V_4 -> V_179 ;
V_185 |= V_201 ;
V_4 -> V_202 |= V_4 -> V_179 ;
V_4 -> V_179 |= V_203 |
V_204 |
V_205 ;
V_4 -> V_206 |= V_207 ;
V_4 -> V_185 |= V_185 ;
V_4 -> V_208 = V_209 ;
V_4 -> V_210 = V_211 ;
return V_4 ;
}
