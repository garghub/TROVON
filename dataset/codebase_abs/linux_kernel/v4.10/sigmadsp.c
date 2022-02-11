static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
const T_1 V_3 [] , T_2 V_4 )
{
return V_1 -> V_5 ( V_1 -> V_6 , V_2 , V_3 , V_4 ) ;
}
static int F_2 ( struct V_1 * V_1 , unsigned int V_2 ,
T_1 V_3 [] , T_2 V_4 )
{
return V_1 -> V_7 ( V_1 -> V_6 , V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_9 -> V_14 ;
V_11 -> type = V_15 ;
V_11 -> V_16 = V_13 -> V_17 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 ,
struct V_12 * V_13 , void * V_3 )
{
if ( V_13 -> V_17 > 4 && V_13 -> V_17 <= 20 && V_1 -> V_18 &&
V_1 -> V_18 -> V_19 )
return V_1 -> V_18 -> V_19 ( V_1 , V_13 -> V_2 , V_3 ,
V_13 -> V_17 ) ;
else
return F_1 ( V_1 , V_13 -> V_2 , V_3 ,
V_13 -> V_17 ) ;
}
static int F_5 ( struct V_8 * V_9 ,
struct V_20 * V_21 )
{
struct V_12 * V_13 = ( void * ) V_9 -> V_14 ;
struct V_1 * V_1 = F_6 ( V_9 ) ;
T_1 * V_3 ;
int V_22 = 0 ;
F_7 ( & V_1 -> V_23 ) ;
V_3 = V_21 -> V_24 . V_25 . V_3 ;
if ( ! ( V_9 -> V_26 [ 0 ] . V_27 & V_28 ) )
V_22 = F_4 ( V_1 , V_13 , V_3 ) ;
if ( V_22 == 0 ) {
memcpy ( V_13 -> V_29 , V_3 , V_13 -> V_17 ) ;
V_13 -> V_30 = true ;
}
F_8 ( & V_1 -> V_23 ) ;
return V_22 ;
}
static int F_9 ( struct V_8 * V_9 ,
struct V_20 * V_21 )
{
struct V_12 * V_13 = ( void * ) V_9 -> V_14 ;
struct V_1 * V_1 = F_6 ( V_9 ) ;
int V_22 = 0 ;
F_7 ( & V_1 -> V_23 ) ;
if ( ! V_13 -> V_30 ) {
V_22 = F_2 ( V_1 , V_13 -> V_2 , V_13 -> V_29 ,
V_13 -> V_17 ) ;
}
if ( V_22 == 0 ) {
V_13 -> V_30 = true ;
memcpy ( V_21 -> V_24 . V_25 . V_3 , V_13 -> V_29 ,
V_13 -> V_17 ) ;
}
F_8 ( & V_1 -> V_23 ) ;
return V_22 ;
}
static void F_10 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = ( void * ) V_9 -> V_14 ;
V_13 -> V_9 = NULL ;
}
static bool F_11 ( const char * V_31 , unsigned int V_4 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_4 ; V_32 ++ ) {
if ( V_31 [ V_32 ] < ' ' || V_31 [ V_32 ] > '~' )
return false ;
}
return true ;
}
static int F_12 ( struct V_1 * V_1 ,
const struct V_33 * V_34 , unsigned int V_35 )
{
const struct V_36 * V_37 ;
struct V_12 * V_13 ;
unsigned int V_17 ;
T_2 V_38 ;
char * V_31 ;
int V_22 ;
if ( V_35 <= sizeof( * V_37 ) )
return - V_39 ;
V_37 = ( const struct V_36 * ) V_34 ;
V_38 = V_35 - sizeof( * V_37 ) ;
if ( V_38 >= V_40 )
V_38 = V_40 - 1 ;
if ( ! F_11 ( V_37 -> V_31 , V_38 ) )
return - V_39 ;
V_17 = F_13 ( V_37 -> V_17 ) ;
V_13 = F_14 ( sizeof( * V_13 ) + V_17 , V_41 ) ;
if ( ! V_13 )
return - V_42 ;
V_31 = F_14 ( V_38 + 1 , V_41 ) ;
if ( ! V_31 ) {
V_22 = - V_42 ;
goto V_43;
}
memcpy ( V_31 , V_37 -> V_31 , V_38 ) ;
V_31 [ V_38 ] = '\0' ;
V_13 -> V_31 = V_31 ;
V_13 -> V_2 = F_13 ( V_37 -> V_2 ) ;
V_13 -> V_17 = V_17 ;
V_13 -> V_44 = F_15 ( V_34 -> V_44 ) ;
F_16 ( & V_13 -> V_45 , & V_1 -> V_46 ) ;
return 0 ;
V_43:
F_17 ( V_13 ) ;
return V_22 ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_33 * V_34 , unsigned int V_35 )
{
const struct V_47 * V_48 ;
struct V_49 * V_3 ;
if ( V_35 <= sizeof( * V_48 ) )
return - V_39 ;
V_48 = (struct V_47 * ) V_34 ;
V_35 -= sizeof( * V_48 ) ;
V_3 = F_14 ( sizeof( * V_3 ) + V_35 , V_41 ) ;
if ( ! V_3 )
return - V_42 ;
V_3 -> V_2 = F_13 ( V_48 -> V_2 ) ;
V_3 -> V_35 = V_35 ;
V_3 -> V_44 = F_15 ( V_34 -> V_44 ) ;
memcpy ( V_3 -> V_3 , V_48 -> V_3 , V_35 ) ;
F_16 ( & V_3 -> V_45 , & V_1 -> V_50 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 ,
const struct V_33 * V_34 , unsigned int V_35 )
{
const struct V_51 * V_52 ;
unsigned int V_53 ;
unsigned int * V_54 ;
unsigned int V_32 ;
V_52 = ( const struct V_51 * ) V_34 ;
V_53 = ( V_35 - sizeof( * V_52 ) ) / sizeof( V_55 ) ;
if ( V_53 > 32 || V_53 == 0 )
return - V_39 ;
if ( V_1 -> V_56 . V_16 )
return - V_39 ;
V_54 = F_20 ( V_53 , sizeof( * V_54 ) , V_41 ) ;
if ( ! V_54 )
return - V_42 ;
for ( V_32 = 0 ; V_32 < V_53 ; V_32 ++ )
V_54 [ V_32 ] = F_15 ( V_52 -> V_44 [ V_32 ] ) ;
V_1 -> V_56 . V_16 = V_53 ;
V_1 -> V_56 . V_57 = V_54 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 ,
const struct V_58 * V_59 )
{
struct V_33 * V_34 ;
unsigned int V_35 , V_60 ;
int V_22 ;
if ( V_59 -> V_61 < sizeof( * V_34 ) + sizeof( struct V_62 ) )
return 0 ;
V_60 = sizeof( struct V_62 ) ;
while ( V_60 < V_59 -> V_61 - sizeof( * V_34 ) ) {
V_34 = (struct V_33 * ) ( V_59 -> V_3 + V_60 ) ;
V_35 = F_15 ( V_34 -> V_35 ) ;
if ( V_35 > V_59 -> V_61 - V_60 || V_35 < sizeof( * V_34 ) )
return - V_39 ;
switch ( F_15 ( V_34 -> V_63 ) ) {
case V_64 :
V_22 = F_18 ( V_1 , V_34 , V_35 ) ;
break;
case V_65 :
V_22 = F_12 ( V_1 , V_34 , V_35 ) ;
break;
case V_66 :
V_22 = F_19 ( V_1 , V_34 , V_35 ) ;
break;
default:
F_22 ( V_1 -> V_67 , L_1 ,
V_34 -> V_63 ) ;
V_22 = 0 ;
break;
}
if ( V_22 )
return V_22 ;
V_60 += F_23 ( V_35 , sizeof( V_55 ) ) ;
}
return 0 ;
}
static inline T_3 F_24 ( struct V_68 * V_69 )
{
return ( V_69 -> V_70 << 16 ) | F_13 ( V_69 -> V_4 ) ;
}
static T_2 F_25 ( struct V_68 * V_69 )
{
T_2 V_71 = 0 ;
switch ( V_69 -> V_72 ) {
case V_73 :
case V_74 :
case V_75 :
V_71 = F_24 ( V_69 ) ;
break;
default:
break;
}
V_71 = F_23 ( V_71 , 2 ) ;
return V_71 + sizeof( struct V_68 ) ;
}
static int F_26 ( struct V_1 * V_1 ,
struct V_68 * V_69 )
{
T_2 V_4 = F_24 ( V_69 ) ;
struct V_49 * V_3 ;
F_27 ( L_2 , V_76 ,
V_69 -> V_72 , V_69 -> V_2 , V_4 ) ;
switch ( V_69 -> V_72 ) {
case V_73 :
case V_74 :
case V_75 :
if ( V_4 < 3 )
return - V_39 ;
V_3 = F_14 ( sizeof( * V_3 ) + V_4 - 2 , V_41 ) ;
if ( ! V_3 )
return - V_42 ;
V_3 -> V_2 = F_28 ( V_69 -> V_2 ) ;
V_3 -> V_35 = V_4 - 2 ;
memcpy ( V_3 -> V_3 , V_69 -> V_71 , V_3 -> V_35 ) ;
F_16 ( & V_3 -> V_45 , & V_1 -> V_50 ) ;
break;
case V_77 :
return 0 ;
default:
return - V_39 ;
}
return 1 ;
}
static int F_29 ( struct V_1 * V_1 ,
const struct V_58 * V_59 )
{
struct V_68 * V_69 ;
T_2 V_61 , V_60 ;
int V_22 ;
V_60 = sizeof( struct V_62 ) ;
while ( V_60 + sizeof( * V_69 ) <= V_59 -> V_61 ) {
V_69 = (struct V_68 * ) ( V_59 -> V_3 + V_60 ) ;
V_61 = F_25 ( V_69 ) ;
V_60 += V_61 ;
if ( V_60 > V_59 -> V_61 || V_61 == 0 )
break;
V_22 = F_26 ( V_1 , V_69 ) ;
F_27 ( L_3 , V_76 , V_22 ) ;
if ( V_22 <= 0 )
return V_22 ;
}
if ( V_60 != V_59 -> V_61 )
return - V_39 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_12 * V_13 , * V_78 ;
struct V_49 * V_3 , * V_79 ;
F_31 (ctrl, _ctrl, &sigmadsp->ctrl_list, head) {
F_17 ( V_13 -> V_31 ) ;
F_17 ( V_13 ) ;
}
F_31 (data, _data, &sigmadsp->data_list, head)
F_17 ( V_3 ) ;
F_32 ( & V_1 -> V_46 ) ;
F_32 ( & V_1 -> V_50 ) ;
}
static void F_33 ( struct V_80 * V_67 , void * V_81 )
{
F_30 ( (struct V_1 * ) V_81 ) ;
}
static int F_34 ( struct V_1 * V_1 , const char * V_31 )
{
const struct V_62 * V_82 ;
const struct V_58 * V_59 ;
int V_22 ;
T_3 V_83 ;
V_22 = F_35 ( & V_59 , V_31 , V_1 -> V_67 ) ;
if ( V_22 ) {
F_27 ( L_4 , V_76 , V_22 ) ;
goto V_84;
}
V_22 = - V_39 ;
if ( V_59 -> V_61 < sizeof( * V_82 ) || V_59 -> V_61 >= 0x4000000 ) {
F_36 ( V_1 -> V_67 , L_5 ) ;
goto V_84;
}
V_82 = ( void * ) V_59 -> V_3 ;
if ( memcmp ( V_82 -> V_85 , V_86 , F_37 ( V_82 -> V_85 ) ) ) {
F_36 ( V_1 -> V_67 , L_6 ) ;
goto V_84;
}
V_83 = F_38 ( 0 , V_59 -> V_3 + sizeof( * V_82 ) ,
V_59 -> V_61 - sizeof( * V_82 ) ) ;
F_27 ( L_7 , V_76 , V_83 ) ;
if ( V_83 != F_15 ( V_82 -> V_83 ) ) {
F_36 ( V_1 -> V_67 , L_8 ,
F_15 ( V_82 -> V_83 ) , V_83 ) ;
goto V_84;
}
switch ( V_82 -> V_87 ) {
case 1 :
V_22 = F_29 ( V_1 , V_59 ) ;
break;
case 2 :
V_22 = F_21 ( V_1 , V_59 ) ;
break;
default:
F_36 ( V_1 -> V_67 ,
L_9 ,
V_82 -> V_87 ) ;
V_22 = - V_39 ;
break;
}
if ( V_22 )
F_30 ( V_1 ) ;
V_84:
F_39 ( V_59 ) ;
return V_22 ;
}
static int F_40 ( struct V_1 * V_1 , struct V_80 * V_67 ,
const struct V_88 * V_18 , const char * V_89 )
{
V_1 -> V_18 = V_18 ;
V_1 -> V_67 = V_67 ;
F_32 ( & V_1 -> V_46 ) ;
F_32 ( & V_1 -> V_50 ) ;
F_41 ( & V_1 -> V_23 ) ;
return F_34 ( V_1 , V_89 ) ;
}
struct V_1 * F_42 ( struct V_80 * V_67 ,
const struct V_88 * V_18 , const char * V_89 )
{
struct V_1 * V_1 ;
int V_22 ;
V_1 = F_43 ( F_33 , sizeof( * V_1 ) ,
V_41 ) ;
if ( ! V_1 )
return F_44 ( - V_42 ) ;
V_22 = F_40 ( V_1 , V_67 , V_18 , V_89 ) ;
if ( V_22 ) {
F_45 ( V_1 ) ;
return F_44 ( V_22 ) ;
}
F_46 ( V_67 , V_1 ) ;
return V_1 ;
}
static int F_47 ( struct V_1 * V_1 , unsigned int V_90 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_1 -> V_56 . V_16 ; V_32 ++ ) {
if ( V_1 -> V_56 . V_57 [ V_32 ] == V_90 )
return V_32 ;
}
return - V_39 ;
}
static unsigned int F_48 ( struct V_1 * V_1 ,
unsigned int V_91 )
{
int V_92 ;
if ( V_91 == 0 )
return 0 ;
if ( V_1 -> V_56 . V_16 ) {
V_92 = F_47 ( V_1 , V_91 ) ;
if ( V_92 < 0 )
return 0 ;
return F_49 ( V_92 ) ;
} else {
return ~ 0 ;
}
}
static bool F_50 ( unsigned int V_93 ,
unsigned int V_94 )
{
if ( ! V_93 )
return true ;
return V_93 & V_94 ;
}
static int F_51 ( struct V_1 * V_1 ,
struct V_12 * V_13 , unsigned int V_95 )
{
struct V_96 V_97 ;
struct V_8 * V_9 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_98 = V_99 ;
V_97 . V_31 = V_13 -> V_31 ;
V_97 . V_11 = F_3 ;
V_97 . V_100 = F_9 ;
V_97 . V_101 = F_5 ;
V_97 . V_14 = ( unsigned long ) V_13 ;
V_97 . V_27 = V_102 ;
if ( ! F_50 ( V_13 -> V_44 , V_95 ) )
V_97 . V_27 |= V_28 ;
V_9 = F_52 ( & V_97 , V_1 ) ;
if ( ! V_9 )
return - V_42 ;
V_9 -> V_103 = F_10 ;
V_13 -> V_9 = V_9 ;
return F_53 ( V_1 -> V_104 -> V_105 -> V_106 , V_9 ) ;
}
static void F_54 ( struct V_1 * V_1 ,
struct V_12 * V_13 , unsigned int V_95 )
{
struct V_106 * V_105 = V_1 -> V_104 -> V_105 -> V_106 ;
struct V_107 * V_26 ;
struct V_108 V_109 ;
bool V_110 ;
bool V_111 = false ;
V_110 = F_50 ( V_13 -> V_44 , V_95 ) ;
F_55 ( & V_105 -> V_112 ) ;
if ( ! V_13 -> V_9 ) {
F_56 ( & V_105 -> V_112 ) ;
return;
}
V_109 = V_13 -> V_9 -> V_109 ;
V_26 = & V_13 -> V_9 -> V_26 [ 0 ] ;
if ( V_110 == ( bool ) ( V_26 -> V_27 & V_28 ) ) {
V_26 -> V_27 ^= V_28 ;
V_111 = true ;
}
F_56 ( & V_105 -> V_112 ) ;
if ( V_110 && V_111 ) {
F_7 ( & V_1 -> V_23 ) ;
if ( V_13 -> V_30 )
F_4 ( V_1 , V_13 , V_13 -> V_29 ) ;
F_8 ( & V_1 -> V_23 ) ;
}
if ( V_111 )
F_57 ( V_105 , V_113 , & V_109 ) ;
}
int F_58 ( struct V_1 * V_1 ,
struct V_114 * V_104 )
{
struct V_12 * V_13 ;
unsigned int V_95 ;
int V_22 ;
V_1 -> V_104 = V_104 ;
V_95 = F_48 ( V_1 ,
V_1 -> V_115 ) ;
F_59 (ctrl, &sigmadsp->ctrl_list, head) {
V_22 = F_51 ( V_1 , V_13 , V_95 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_1 , unsigned int V_91 )
{
struct V_12 * V_13 ;
unsigned int V_95 ;
struct V_49 * V_3 ;
int V_22 ;
if ( V_1 -> V_115 == V_91 )
return 0 ;
V_95 = F_48 ( V_1 , V_91 ) ;
if ( V_95 == 0 )
return - V_39 ;
F_59 (data, &sigmadsp->data_list, head) {
if ( ! F_50 ( V_3 -> V_44 ,
V_95 ) )
continue;
V_22 = F_1 ( V_1 , V_3 -> V_2 , V_3 -> V_3 ,
V_3 -> V_35 ) ;
if ( V_22 )
goto V_116;
}
F_59 (ctrl, &sigmadsp->ctrl_list, head)
F_54 ( V_1 , V_13 , V_95 ) ;
V_1 -> V_115 = V_91 ;
return 0 ;
V_116:
F_61 ( V_1 ) ;
return V_22 ;
}
void F_61 ( struct V_1 * V_1 )
{
struct V_12 * V_13 ;
F_59 (ctrl, &sigmadsp->ctrl_list, head)
F_54 ( V_1 , V_13 , false ) ;
V_1 -> V_115 = 0 ;
}
int F_62 ( struct V_1 * V_1 ,
struct V_117 * V_118 )
{
if ( V_1 -> V_56 . V_16 == 0 )
return 0 ;
return F_63 ( V_118 -> V_119 , 0 ,
V_120 , & V_1 -> V_56 ) ;
}
