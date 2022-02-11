static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 0 ;
V_4 -> V_6 = V_7 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = V_11 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_12 )
{
if ( V_12 == V_13 )
return F_3 ( V_2 ) ;
else
return - V_14 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_1 * V_17 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_20 , V_21 ;
char * V_22 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
V_22 = ( char * ) V_19 + V_24 [ V_20 ] . V_25 ;
V_17 [ V_20 ] = * ( T_1 * ) V_22 ;
}
for ( V_21 = 0 ; V_21 < V_19 -> V_26 ; V_21 ++ ) {
V_17 [ V_20 ++ ] = V_19 -> V_27 [ V_21 ] . V_16 . V_28 ;
V_17 [ V_20 ++ ] = V_19 -> V_27 [ V_21 ] . V_16 . V_29 ;
}
for ( V_21 = 0 ; V_21 < V_19 -> V_26 ; V_21 ++ ) {
V_17 [ V_20 ++ ] = V_19 -> V_30 [ V_21 ] . V_16 . V_28 ;
V_17 [ V_20 ++ ] = V_19 -> V_30 [ V_21 ] . V_16 . V_29 ;
}
}
static void F_6 ( struct V_1 * V_2 , T_2 V_12 , T_3 * V_17 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_3 * V_22 = V_17 ;
int V_20 ;
if ( V_12 == V_13 ) {
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
memcpy ( V_22 , V_24 [ V_20 ] . V_31 ,
V_32 ) ;
V_22 += V_32 ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_26 ; V_20 ++ ) {
snprintf ( V_22 , V_32 , L_1 , V_20 ) ;
V_22 += V_32 ;
snprintf ( V_22 , V_32 , L_2 , V_20 ) ;
V_22 += V_32 ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_26 ; V_20 ++ ) {
snprintf ( V_22 , V_32 , L_3 , V_20 ) ;
V_22 += V_32 ;
snprintf ( V_22 , V_32 , L_4 , V_20 ) ;
V_22 += V_32 ;
}
}
}
static T_2 F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
return V_19 -> V_33 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
if ( V_34 & V_17 )
V_19 -> V_35 . V_36 = V_17 ;
V_19 -> V_33 = V_17 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
F_10 ( V_38 -> V_39 , V_40 , 32 ) ;
F_10 ( V_38 -> V_41 , V_42 , 32 ) ;
F_10 ( V_38 -> V_43 , L_5 , 4 ) ;
F_10 ( V_38 -> V_44 , F_11 ( V_19 -> V_45 ) , 32 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_47 -> V_48 = V_49 ;
V_47 -> V_50 = V_51 ;
V_47 -> V_52 = V_19 -> V_53 ;
V_47 -> V_54 = V_19 -> V_55 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_2 V_56 , V_57 ;
if ( ( V_47 -> V_58 ) || ( V_47 -> V_59 ) )
return - V_14 ;
V_57 = F_14 ( T_2 , V_47 -> V_54 ,
V_60 ,
V_51 ) ;
V_57 = F_15 ( V_57 , V_61 ) ;
V_56 = F_14 ( T_2 , V_47 -> V_52 ,
V_62 ,
V_49 ) ;
V_56 = F_15 ( V_56 , V_61 ) ;
if ( ( V_57 == V_19 -> V_55 ) &&
( V_56 == V_19 -> V_53 ) )
return 0 ;
V_19 -> V_55 = V_57 ;
V_19 -> V_53 = V_56 ;
if ( F_16 ( V_2 ) ) {
V_19 -> V_63 |= V_64 ;
F_17 ( & V_19 -> V_65 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_68 * V_69 = & V_19 -> V_69 ;
V_67 -> V_70 = V_69 -> V_71 ;
V_67 -> V_72 = V_69 -> V_71 ;
if ( F_19 ( V_69 -> V_73 ) )
V_67 -> V_74 = 1 ;
if ( F_19 ( V_69 -> V_75 ) )
V_67 -> V_76 = 1 ;
V_67 -> V_77 = V_69 -> V_73 & ~ V_78 ;
V_67 -> V_79 = V_69 -> V_75 & ~ V_78 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_80 * V_35 = & V_19 -> V_35 ;
struct V_68 * V_69 = & V_19 -> V_69 ;
struct V_81 * V_82 ;
int V_20 ;
if ( V_67 -> V_83 || V_67 -> V_84 )
V_69 -> V_71 = V_67 -> V_83 ;
if ( ( V_67 -> V_77 >= ( V_85 << 1 ) ) &&
( V_67 -> V_77 <= ( V_86 << 1 ) ) )
V_69 -> V_73 = V_67 -> V_77 ;
else
return - V_14 ;
if ( ( V_67 -> V_79 >= ( V_85 << 1 ) ) &&
( V_67 -> V_79 <= ( V_86 << 1 ) ) )
V_69 -> V_75 = V_67 -> V_79 ;
else if ( V_67 -> V_76 )
V_69 -> V_75 = ( V_78 |
F_21 ( V_87 ) ) ;
else
return - V_14 ;
if ( V_67 -> V_74 )
V_69 -> V_73 |= V_78 ;
else
V_69 -> V_73 &= ~ V_78 ;
if ( V_67 -> V_76 )
V_69 -> V_75 |= V_78 ;
else
V_69 -> V_75 &= ~ V_78 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_88 - V_89 ; V_20 ++ ) {
V_82 = & V_19 -> V_90 [ V_20 ] ;
V_82 -> V_91 . V_92 = F_22 ( V_69 -> V_73 ) ;
F_23 ( V_35 , F_24 ( 0 , V_20 ) , V_82 -> V_91 . V_92 ) ;
V_82 -> V_93 . V_92 = F_22 ( V_69 -> V_75 ) ;
F_23 ( V_35 , F_24 ( 1 , V_20 ) , V_82 -> V_93 . V_92 ) ;
F_25 ( V_35 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
T_2 * V_96 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_97 = - V_98 ;
switch ( V_95 -> V_95 ) {
case V_99 :
V_95 -> V_17 = V_19 -> V_26 ;
V_97 = 0 ;
break;
case V_100 :
F_27 ( V_2 ,
L_6 ) ;
break;
default:
break;
}
return V_97 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_102 -> V_103 = V_19 -> V_26 ;
V_102 -> V_104 = V_89 ;
V_102 -> V_105 = V_89 ;
V_102 -> V_106 = V_19 -> V_26 ;
}
static T_2 F_29 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
return V_19 -> V_107 ;
}
static T_2 F_30 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
return V_19 -> V_108 ;
}
static int F_31 ( struct V_1 * V_2 , T_2 * V_109 , T_3 * V_110 ,
T_3 * V_111 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_4 V_20 ;
if ( V_111 )
* V_111 = V_112 ;
if ( ! V_109 )
return 0 ;
memcpy ( V_110 , V_19 -> V_113 , V_19 -> V_107 ) ;
for ( V_20 = 0 ; V_20 < V_19 -> V_108 ; V_20 ++ )
V_109 [ V_20 ] = ( T_2 ) V_19 -> V_114 [ V_20 ] ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , const T_2 * V_109 ,
const T_3 * V_110 , const T_3 V_111 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_4 V_20 ;
if ( V_110 ||
( V_111 != V_115 && V_111 != V_112 ) )
return - V_98 ;
if ( ! V_109 )
return 0 ;
if ( V_110 ) {
memcpy ( V_19 -> V_113 , V_110 , V_19 -> V_107 ) ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_108 ; V_20 ++ )
V_19 -> V_114 [ V_20 ] = ( T_3 ) ( V_109 [ V_20 ] ) ;
return F_33 ( V_19 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_116 = & V_117 ;
}
