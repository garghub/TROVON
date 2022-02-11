static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( V_3 ) {
if ( F_2 ( & V_2 -> V_4 ) )
return - V_5 ;
} else {
F_3 ( & V_2 -> V_4 ) ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_4 ) ;
}
static void F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
if ( F_7 ( ! V_7 -> V_10 ) )
return;
V_9 = F_8 ( V_7 -> V_11 , struct V_8 ,
V_11 ) ;
F_9 ( V_7 -> V_2 -> V_12 , V_9 , V_7 -> V_13 ) ;
F_10 ( V_7 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_12 ( & V_2 -> V_14 ) ;
if ( V_7 -> V_10 ) {
F_6 ( V_7 ) ;
return;
}
F_13 ( & V_7 -> V_15 ) ;
F_14 ( & V_2 -> V_16 ) ;
if ( V_7 -> V_11 )
F_9 ( V_2 -> V_17 , V_7 -> V_11 ,
V_7 -> V_13 ) ;
F_10 ( V_7 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_10 ) {
F_6 ( V_7 ) ;
return;
}
F_16 ( & V_2 -> V_14 ) ;
F_11 ( V_7 ) ;
F_17 ( & V_2 -> V_14 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
T_1 V_18 ;
if ( sizeof( V_7 -> V_13 ) > 4 )
V_18 = ( V_7 -> V_13 >> 32 ) ;
else
V_18 = 0 ;
F_19 ( V_2 -> V_19 , V_20 , V_18 ) ;
V_18 = ( V_7 -> V_13 & 0xFFFFFFFFULL ) ;
V_18 |= V_7 -> V_21 & V_22 ;
F_19 ( V_2 -> V_19 , V_23 , V_18 ) ;
return V_7 -> V_11 -> V_24 ;
}
static void F_20 ( struct V_25 * V_26 )
{
F_21 ( & V_26 -> V_27 ) ;
F_21 ( & V_26 -> V_28 ) ;
F_21 ( & V_26 -> V_29 ) ;
V_26 -> V_30 = 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
while ( V_26 -> V_30 < V_2 -> V_31 &&
! F_23 ( & V_26 -> V_28 ) ) {
struct V_6 * V_32 ;
T_2 V_24 ;
V_32 = F_24 ( & V_26 -> V_28 ,
struct V_6 ,
V_33 ) ;
V_24 = F_18 ( V_32 ) ;
if ( F_7 ( V_24 == V_34 ) ) {
V_32 -> V_11 -> V_24 = V_35 ;
break;
}
F_25 ( & V_32 -> V_33 ) ;
F_26 ( & V_32 -> V_33 , & V_26 -> V_27 ) ;
V_26 -> V_30 ++ ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
int * V_36 )
{
struct V_6 * V_32 , * V_37 ;
F_22 ( V_2 , V_26 ) ;
F_28 (entry, next, &ctx->hw_submitted, list) {
T_2 V_24 = V_32 -> V_11 -> V_24 ;
if ( V_24 == V_35 )
break;
F_25 ( & V_32 -> V_33 ) ;
F_14 ( & V_2 -> V_38 ) ;
V_26 -> V_30 -- ;
switch ( V_24 ) {
case V_39 :
F_11 ( V_32 ) ;
break;
case V_40 :
case V_41 :
F_26 ( & V_32 -> V_33 , & V_2 -> error ) ;
F_29 ( & V_2 -> V_42 ) ;
break;
case V_43 :
F_30 ( & V_32 -> V_33 , & V_26 -> V_29 ) ;
break;
default:
F_31 ( true , L_1 ) ;
F_11 ( V_32 ) ;
break;
}
}
F_22 ( V_2 , V_26 ) ;
if ( ! F_23 ( & V_26 -> V_28 ) )
( * V_36 ) ++ ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_36 ;
struct V_25 * V_26 ;
int V_44 ;
V_45:
V_36 = 0 ;
F_33 (man, i, ctx)
F_27 ( V_2 , V_26 , & V_36 ) ;
if ( V_2 -> V_46 && ! V_36 ) {
F_34 ( V_2 -> V_19 ,
V_47 ,
& V_2 -> V_19 -> V_48 ) ;
V_2 -> V_46 = false ;
} else if ( ! V_2 -> V_46 && V_36 ) {
F_35 ( V_2 -> V_19 ,
V_47 ,
& V_2 -> V_19 -> V_48 ) ;
V_2 -> V_46 = true ;
goto V_45;
}
}
static void F_36 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_3 V_21 )
{
if ( ! ( V_7 -> V_11 -> V_49 & V_50 ) )
V_7 -> V_11 -> V_51 = 0 ;
V_7 -> V_21 = V_21 ;
F_26 ( & V_7 -> V_33 , & V_2 -> V_26 [ V_21 ] . V_28 ) ;
F_32 ( V_2 ) ;
}
static void F_37 ( unsigned long V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_38 ( & V_2 -> V_14 ) ;
F_32 ( V_2 ) ;
F_39 ( & V_2 -> V_14 ) ;
}
static void F_40 ( struct V_53 * V_42 )
{
struct V_1 * V_2 =
F_8 ( V_42 , struct V_1 , V_42 ) ;
struct V_6 * V_32 , * V_37 ;
T_4 V_54 ;
bool V_55 = false ;
F_16 ( & V_2 -> V_14 ) ;
F_28 (entry, next, &man->error, list) {
V_55 = true ;
F_41 ( L_2 ) ;
F_25 ( & V_32 -> V_33 ) ;
F_11 ( V_32 ) ;
F_14 ( & V_2 -> V_38 ) ;
}
F_17 ( & V_2 -> V_14 ) ;
if ( V_55 && F_42 ( V_2 , true ) )
F_41 ( L_3 ) ;
F_43 ( V_2 -> V_19 , & V_54 ) ;
}
static bool F_44 ( struct V_1 * V_2 ,
bool V_56 )
{
struct V_25 * V_26 ;
bool V_57 = false ;
int V_44 ;
F_16 ( & V_2 -> V_14 ) ;
F_32 ( V_2 ) ;
F_33 (man, i, ctx) {
if ( ! F_23 ( & V_26 -> V_28 ) ||
! F_23 ( & V_26 -> V_27 ) ||
( V_56 && ! F_23 ( & V_26 -> V_29 ) ) )
goto V_58;
}
V_57 = F_23 ( & V_2 -> error ) ;
V_58:
F_17 ( & V_2 -> V_14 ) ;
return V_57 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_59 = V_2 -> V_59 ;
F_46 ( ! F_47 ( & V_2 -> V_4 ) ) ;
if ( ! V_59 )
return;
F_16 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_60 == 0 ) {
F_11 ( V_59 ) ;
goto V_58;
}
V_2 -> V_59 -> V_11 -> V_61 = V_2 -> V_60 ;
F_36 ( V_2 , V_2 -> V_59 , V_62 ) ;
V_58:
F_17 ( & V_2 -> V_14 ) ;
V_2 -> V_59 = NULL ;
V_2 -> V_60 = 0 ;
}
int F_48 ( struct V_1 * V_2 ,
bool V_3 )
{
int V_63 = F_1 ( V_2 , V_3 ) ;
if ( V_63 )
return V_63 ;
F_45 ( V_2 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , bool V_3 ,
unsigned long V_64 )
{
int V_63 ;
V_63 = F_48 ( V_2 , V_3 ) ;
F_35 ( V_2 -> V_19 ,
V_47 ,
& V_2 -> V_19 -> V_48 ) ;
if ( V_3 ) {
V_63 = F_50
( V_2 -> V_38 , F_44 ( V_2 , true ) ,
V_64 ) ;
} else {
V_63 = F_51
( V_2 -> V_38 , F_44 ( V_2 , true ) ,
V_64 ) ;
}
F_34 ( V_2 -> V_19 ,
V_47 ,
& V_2 -> V_19 -> V_48 ) ;
if ( V_63 == 0 ) {
if ( ! F_44 ( V_2 , true ) )
V_63 = - V_65 ;
else
V_63 = 0 ;
}
if ( V_63 > 0 )
V_63 = 0 ;
return V_63 ;
}
static bool F_52 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
int V_63 ;
if ( V_67 -> V_68 )
return true ;
memset ( V_67 -> V_15 , 0 , sizeof( * V_67 -> V_15 ) ) ;
F_16 ( & V_2 -> V_14 ) ;
V_63 = F_53 ( & V_2 -> V_69 , V_67 -> V_15 , V_67 -> V_70 ,
0 , 0 ,
V_71 ,
V_72 ) ;
if ( V_63 ) {
F_32 ( V_2 ) ;
V_63 = F_53 ( & V_2 -> V_69 , V_67 -> V_15 ,
V_67 -> V_70 , 0 , 0 ,
V_71 ,
V_72 ) ;
}
F_17 ( & V_2 -> V_14 ) ;
V_67 -> V_68 = ! V_63 ;
return V_67 -> V_68 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_73 * V_15 ,
T_5 V_74 ,
bool V_3 )
{
struct V_66 V_67 ;
V_67 . V_70 = F_55 ( V_74 ) >> V_75 ;
V_67 . V_15 = V_15 ;
V_67 . V_68 = false ;
if ( V_3 ) {
if ( F_2 ( & V_2 -> V_76 ) )
return - V_5 ;
} else {
F_3 ( & V_2 -> V_76 ) ;
}
if ( F_52 ( V_2 , & V_67 ) )
goto V_58;
F_35 ( V_2 -> V_19 ,
V_47 ,
& V_2 -> V_19 -> V_48 ) ;
if ( V_3 ) {
int V_63 ;
V_63 = F_56
( V_2 -> V_16 , F_52 ( V_2 , & V_67 ) ) ;
if ( V_63 ) {
F_34
( V_2 -> V_19 , V_47 ,
& V_2 -> V_19 -> V_48 ) ;
F_5 ( & V_2 -> V_76 ) ;
return V_63 ;
}
} else {
F_57 ( V_2 -> V_16 , F_52 ( V_2 , & V_67 ) ) ;
}
F_34 ( V_2 -> V_19 ,
V_47 ,
& V_2 -> V_19 -> V_48 ) ;
V_58:
F_5 ( & V_2 -> V_76 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_5 V_74 ,
bool V_3 )
{
T_6 * V_77 ;
T_5 V_78 ;
int V_63 ;
if ( ! V_2 -> V_79 )
return - V_80 ;
V_63 = F_54 ( V_2 , & V_7 -> V_15 , V_74 , V_3 ) ;
if ( V_63 )
return V_63 ;
V_7 -> V_11 = F_59 ( V_2 -> V_17 , V_81 ,
& V_7 -> V_13 ) ;
if ( ! V_7 -> V_11 ) {
V_63 = - V_80 ;
goto V_82;
}
V_7 -> V_74 = V_7 -> V_15 . V_74 << V_75 ;
V_77 = V_7 -> V_11 ;
V_78 = V_7 -> V_15 . V_83 << V_75 ;
V_7 -> V_84 = V_2 -> V_85 + V_78 ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
if ( V_2 -> V_86 ) {
V_77 -> V_49 = V_87 ;
V_77 -> V_88 . V_89 . V_90 = V_2 -> V_91 -> V_92 . V_83 ;
V_77 -> V_88 . V_89 . V_93 = V_78 ;
} else {
V_77 -> V_88 . V_94 = ( V_95 ) V_2 -> V_13 + ( V_95 ) V_78 ;
}
return 0 ;
V_82:
F_16 ( & V_2 -> V_14 ) ;
F_13 ( & V_7 -> V_15 ) ;
F_17 ( & V_2 -> V_14 ) ;
return V_63 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_74 )
{
struct V_8 * V_9 ;
T_6 * V_77 ;
if ( F_7 ( V_74 > V_96 ) )
return - V_80 ;
V_9 = F_59 ( V_2 -> V_12 , V_81 ,
& V_7 -> V_13 ) ;
if ( ! V_9 )
return - V_80 ;
V_7 -> V_10 = true ;
V_7 -> V_74 = V_96 ;
V_77 = & V_9 -> V_11 ;
V_7 -> V_11 = V_77 ;
V_7 -> V_84 = V_9 -> V_84 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_77 -> V_24 = V_35 ;
V_77 -> V_49 = V_97 ;
V_77 -> V_88 . V_94 = ( V_95 ) V_7 -> V_13 +
( V_95 ) F_61 ( struct V_8 , V_84 ) ;
return 0 ;
}
void * F_62 ( struct V_1 * V_2 ,
T_5 V_74 , bool V_3 ,
struct V_6 * * V_98 )
{
struct V_6 * V_7 ;
int V_63 = 0 ;
* V_98 = NULL ;
V_7 = F_63 ( sizeof( * V_7 ) , V_81 ) ;
if ( ! V_7 )
return F_64 ( - V_80 ) ;
if ( V_74 <= V_96 )
V_63 = F_60 ( V_2 , V_7 , V_74 ) ;
else
V_63 = F_58 ( V_2 , V_7 , V_74 , V_3 ) ;
if ( V_63 ) {
F_10 ( V_7 ) ;
return F_64 ( V_63 ) ;
}
V_7 -> V_2 = V_2 ;
F_21 ( & V_7 -> V_33 ) ;
V_7 -> V_11 -> V_24 = V_35 ;
* V_98 = V_7 ;
return V_7 -> V_84 ;
}
static void * F_65 ( struct V_1 * V_2 ,
T_5 V_74 ,
int V_99 ,
bool V_3 )
{
struct V_6 * V_59 ;
void * V_63 ;
if ( F_1 ( V_2 , V_3 ) )
return F_64 ( - V_5 ) ;
V_59 = V_2 -> V_59 ;
if ( V_59 && ( V_74 + V_2 -> V_60 > V_59 -> V_74 ||
( ( V_59 -> V_11 -> V_49 & V_50 ) &&
V_99 != V_59 -> V_11 -> V_51 ) ) )
F_45 ( V_2 ) ;
if ( ! V_2 -> V_59 ) {
V_63 = F_62 ( V_2 ,
F_66 ( T_5 , V_74 , V_2 -> V_100 ) ,
V_3 , & V_2 -> V_59 ) ;
if ( F_67 ( V_63 ) ) {
F_4 ( V_2 ) ;
return V_63 ;
}
V_59 = V_2 -> V_59 ;
}
if ( V_99 != V_101 ) {
V_59 -> V_11 -> V_49 |= V_50 ;
V_59 -> V_11 -> V_51 = V_99 ;
}
V_59 -> V_102 = V_74 ;
return ( void * ) ( V_2 -> V_59 -> V_84 + V_2 -> V_60 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
T_5 V_74 , bool V_103 )
{
struct V_6 * V_59 = V_2 -> V_59 ;
F_46 ( ! F_47 ( & V_2 -> V_4 ) ) ;
F_46 ( V_74 > V_59 -> V_102 ) ;
V_2 -> V_60 += V_74 ;
if ( ! V_74 )
V_59 -> V_11 -> V_49 &= ~ V_50 ;
if ( V_103 )
F_45 ( V_2 ) ;
F_4 ( V_2 ) ;
}
void * F_69 ( struct V_1 * V_2 , T_5 V_74 ,
int V_99 , bool V_3 ,
struct V_6 * V_7 )
{
if ( ! V_7 )
return F_65 ( V_2 , V_74 , V_99 , V_3 ) ;
if ( V_74 > V_7 -> V_74 )
return F_64 ( - V_104 ) ;
if ( V_99 != V_101 ) {
V_7 -> V_11 -> V_49 |= V_50 ;
V_7 -> V_11 -> V_51 = V_99 ;
}
V_7 -> V_102 = V_74 ;
return V_7 -> V_84 ;
}
void F_70 ( struct V_1 * V_2 , T_5 V_74 ,
struct V_6 * V_7 , bool V_103 )
{
if ( ! V_7 ) {
F_68 ( V_2 , V_74 , V_103 ) ;
return;
}
( void ) F_1 ( V_2 , false ) ;
F_45 ( V_2 ) ;
F_46 ( V_74 > V_7 -> V_102 ) ;
V_2 -> V_59 = V_7 ;
V_2 -> V_60 = V_74 ;
if ( ! V_74 )
V_7 -> V_11 -> V_49 &= ~ V_50 ;
if ( V_103 )
F_45 ( V_2 ) ;
F_4 ( V_2 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_72 ( & V_2 -> V_105 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
const void * V_106 ,
T_5 V_74 )
{
struct V_6 * V_7 ;
int V_24 ;
void * V_84 = F_62 ( V_2 , V_74 , false , & V_7 ) ;
if ( F_67 ( V_84 ) )
return F_74 ( V_84 ) ;
memcpy ( V_84 , V_106 , V_74 ) ;
V_7 -> V_11 -> V_61 = V_74 ;
V_7 -> V_21 = V_107 ;
F_16 ( & V_2 -> V_14 ) ;
V_24 = F_18 ( V_7 ) ;
F_17 ( & V_2 -> V_14 ) ;
F_15 ( V_7 ) ;
if ( V_24 != V_39 ) {
F_41 ( L_4 ,
V_24 ) ;
return - V_104 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
bool V_108 )
{
struct {
T_7 V_109 ;
T_8 V_110 ;
} V_111 V_84 ;
V_84 . V_109 = V_112 ;
V_84 . V_110 . V_108 = ( V_108 ) ? 1 : 0 ;
V_84 . V_110 . V_113 = V_62 ;
return F_73 ( V_2 , & V_84 , sizeof( V_84 ) ) ;
}
int F_75 ( struct V_1 * V_2 ,
T_5 V_74 , T_5 V_100 )
{
struct V_114 * V_19 = V_2 -> V_19 ;
bool V_54 ;
int V_63 ;
if ( V_2 -> V_79 )
return - V_104 ;
V_74 = F_55 ( V_74 ) ;
V_2 -> V_85 = F_76 ( & V_19 -> V_115 -> V_116 -> V_115 , V_74 ,
& V_2 -> V_13 , V_81 ) ;
if ( V_2 -> V_85 ) {
V_2 -> V_86 = false ;
} else {
if ( ! ( V_19 -> V_117 & V_118 ) )
return - V_80 ;
V_63 = F_77 ( & V_19 -> V_119 , V_74 , V_120 ,
& V_121 , 0 , false , NULL ,
& V_2 -> V_91 ) ;
if ( V_63 )
return V_63 ;
V_2 -> V_86 = true ;
V_63 = F_78 ( V_2 -> V_91 , 0 , V_74 >> V_75 ,
& V_2 -> V_122 ) ;
if ( V_63 )
goto V_123;
V_2 -> V_85 = F_79 ( & V_2 -> V_122 , & V_54 ) ;
}
V_2 -> V_74 = V_74 ;
F_80 ( & V_2 -> V_69 , 0 , V_74 >> V_75 ) ;
V_2 -> V_79 = true ;
V_2 -> V_100 = V_96 ;
F_81 ( L_5 ,
( V_2 -> V_86 ) ? L_6 : L_7 ) ;
return 0 ;
V_123:
if ( V_2 -> V_86 )
F_82 ( & V_2 -> V_91 ) ;
return V_63 ;
}
struct V_1 * F_83 ( struct V_114 * V_19 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
int V_44 ;
int V_63 ;
if ( ! ( V_19 -> V_117 & V_124 ) )
return F_64 ( - V_125 ) ;
V_2 = F_63 ( sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return F_64 ( - V_80 ) ;
V_2 -> V_17 = F_84 ( L_8 ,
& V_19 -> V_115 -> V_116 -> V_115 ,
sizeof( T_6 ) ,
64 , V_126 ) ;
if ( ! V_2 -> V_17 ) {
V_63 = - V_80 ;
goto V_127;
}
V_2 -> V_12 = F_84 ( L_9 ,
& V_19 -> V_115 -> V_116 -> V_115 ,
sizeof( struct V_8 ) ,
64 , V_126 ) ;
if ( ! V_2 -> V_12 ) {
V_63 = - V_80 ;
goto V_128;
}
F_33 (man, i, ctx)
F_20 ( V_26 ) ;
F_21 ( & V_2 -> error ) ;
F_85 ( & V_2 -> V_14 ) ;
F_86 ( & V_2 -> V_4 ) ;
F_86 ( & V_2 -> V_76 ) ;
F_87 ( & V_2 -> V_105 , F_37 ,
( unsigned long ) V_2 ) ;
V_2 -> V_100 = V_96 ;
F_88 ( & V_2 -> V_16 ) ;
F_88 ( & V_2 -> V_38 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_31 = V_129 - 1 ;
F_89 ( & V_2 -> V_42 , & F_40 ) ;
F_35 ( V_19 , V_130 ,
& V_19 -> V_131 ) ;
V_63 = F_42 ( V_2 , true ) ;
if ( V_63 ) {
F_41 ( L_10 ) ;
F_90 ( V_2 ) ;
return F_64 ( V_63 ) ;
}
return V_2 ;
V_128:
F_91 ( V_2 -> V_17 ) ;
V_127:
F_10 ( V_2 ) ;
return F_64 ( V_63 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_79 )
return;
V_2 -> V_79 = false ;
V_2 -> V_100 = V_96 ;
( void ) F_49 ( V_2 , false , 10 * V_132 ) ;
if ( V_2 -> V_86 ) {
( void ) F_93 ( & V_2 -> V_122 ) ;
F_82 ( & V_2 -> V_91 ) ;
} else {
F_94 ( & V_2 -> V_19 -> V_115 -> V_116 -> V_115 ,
V_2 -> V_74 , V_2 -> V_85 , V_2 -> V_13 ) ;
}
}
void F_90 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_79 ) ;
( void ) F_49 ( V_2 , false , 10 * V_132 ) ;
if ( F_42 ( V_2 , false ) )
F_41 ( L_11 ) ;
F_34 ( V_2 -> V_19 , V_130 ,
& V_2 -> V_19 -> V_131 ) ;
F_95 ( & V_2 -> V_105 ) ;
( void ) F_96 ( & V_2 -> V_42 ) ;
F_91 ( V_2 -> V_12 ) ;
F_91 ( V_2 -> V_17 ) ;
F_97 ( & V_2 -> V_4 ) ;
F_97 ( & V_2 -> V_76 ) ;
F_10 ( V_2 ) ;
}
