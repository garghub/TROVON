static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) ) {
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 , V_5 ) ;
}
}
static struct V_1 *
F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
F_6 () ;
V_2 = F_7 ( V_7 -> V_8 . V_9 ) ;
if ( ! V_2 )
goto V_10;
if ( ! F_8 ( & V_2 -> V_3 ) )
V_2 = NULL ;
V_10:
F_9 () ;
return V_2 ;
}
struct V_11 *
F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_11 * V_4 = NULL ;
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
goto V_10;
F_6 () ;
V_4 = V_2 -> V_4 ;
if ( ! V_4 )
goto V_12;
if ( ! F_8 ( & V_4 -> V_3 ) )
V_4 = NULL ;
V_12:
F_9 () ;
V_10:
if ( V_2 )
F_1 ( V_2 ) ;
return V_4 ;
}
static void F_11 ( struct V_6 * V_7 ,
struct V_1 * V_13 )
{
struct V_1 * V_14 ;
F_12 ( & V_7 -> V_8 . V_15 ) ;
if ( V_13 && ! F_8 ( & V_13 -> V_3 ) )
V_13 = NULL ;
V_14 = F_13 ( V_7 -> V_8 . V_9 , 1 ) ;
F_14 ( V_7 -> V_8 . V_9 , V_13 ) ;
if ( V_14 )
F_1 ( V_14 ) ;
F_15 ( & V_7 -> V_8 . V_15 ) ;
}
void F_16 ( struct V_6 * V_7 )
{
F_17 ( & V_7 -> V_8 . V_16 , 1 ) ;
}
static struct V_1 *
F_18 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_1 * V_2 , * V_9 = NULL ;
T_1 V_21 = 0 , V_22 = 0 ;
T_1 V_23 ;
T_2 V_24 = 0 ;
T_2 V_25 ;
struct V_11 * V_4 ;
V_23 = V_26 * V_26 ;
V_23 *= 64 ;
F_6 () ;
F_19 (gw_node, &bat_priv->gw.list, list) {
if ( V_2 -> V_27 )
continue;
V_4 = V_2 -> V_4 ;
V_18 = F_20 ( V_4 , V_28 ) ;
if ( ! V_18 )
continue;
V_20 = F_21 ( V_18 ,
V_28 ) ;
if ( ! V_20 )
goto V_29;
if ( ! F_8 ( & V_2 -> V_3 ) )
goto V_29;
V_25 = V_20 -> V_30 . V_25 ;
switch ( F_22 ( & V_7 -> V_31 ) ) {
case 1 :
V_22 = V_25 * V_25 ;
V_22 *= V_2 -> V_32 ;
V_22 *= 100 * 100 ;
V_22 /= V_23 ;
if ( ( V_22 > V_21 ) ||
( ( V_22 == V_21 ) &&
( V_25 > V_24 ) ) ) {
if ( V_9 )
F_1 ( V_9 ) ;
V_9 = V_2 ;
F_23 ( & V_9 -> V_3 ) ;
}
break;
default:
if ( V_25 > V_24 ) {
if ( V_9 )
F_1 ( V_9 ) ;
V_9 = V_2 ;
F_23 ( & V_9 -> V_3 ) ;
}
break;
}
if ( V_25 > V_24 )
V_24 = V_25 ;
if ( V_22 > V_21 )
V_21 = V_22 ;
F_1 ( V_2 ) ;
V_29:
F_24 ( V_18 ) ;
if ( V_20 )
F_25 ( V_20 ) ;
}
F_9 () ;
return V_9 ;
}
void F_26 ( struct V_6 * V_7 )
{
struct V_1 * V_9 ;
if ( F_22 ( & V_7 -> V_33 ) != V_34 )
return;
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
return;
F_11 ( V_7 , NULL ) ;
F_27 ( V_7 , V_35 , V_36 , NULL ) ;
F_1 ( V_9 ) ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = NULL , * V_37 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_19 * V_20 = NULL ;
char V_38 [ 18 ] = { '\0' } ;
if ( F_22 ( & V_7 -> V_33 ) != V_34 )
goto V_10;
V_9 = F_5 ( V_7 ) ;
if ( ! F_29 ( & V_7 -> V_8 . V_16 ) && V_9 )
goto V_10;
V_37 = F_18 ( V_7 ) ;
if ( V_9 == V_37 )
goto V_10;
if ( V_37 ) {
sprintf ( V_38 , L_1 , V_37 -> V_4 -> V_39 ) ;
V_18 = F_20 ( V_37 -> V_4 ,
V_28 ) ;
if ( ! V_18 ) {
F_16 ( V_7 ) ;
goto V_10;
}
V_20 = F_21 ( V_18 ,
V_28 ) ;
if ( ! V_20 ) {
F_16 ( V_7 ) ;
goto V_10;
}
}
if ( ( V_9 ) && ( ! V_37 ) ) {
F_30 ( V_40 , V_7 ,
L_2 ) ;
F_27 ( V_7 , V_35 , V_36 ,
NULL ) ;
} else if ( ( ! V_9 ) && ( V_37 ) ) {
F_30 ( V_40 , V_7 ,
L_3 ,
V_37 -> V_4 -> V_39 ,
V_37 -> V_32 / 10 ,
V_37 -> V_32 % 10 ,
V_37 -> V_41 / 10 ,
V_37 -> V_41 % 10 ,
V_20 -> V_30 . V_25 ) ;
F_27 ( V_7 , V_35 , V_42 ,
V_38 ) ;
} else {
F_30 ( V_40 , V_7 ,
L_4 ,
V_37 -> V_4 -> V_39 ,
V_37 -> V_32 / 10 ,
V_37 -> V_32 % 10 ,
V_37 -> V_41 / 10 ,
V_37 -> V_41 % 10 ,
V_20 -> V_30 . V_25 ) ;
F_27 ( V_7 , V_35 , V_43 ,
V_38 ) ;
}
F_11 ( V_7 , V_37 ) ;
V_10:
if ( V_9 )
F_1 ( V_9 ) ;
if ( V_37 )
F_1 ( V_37 ) ;
if ( V_18 )
F_24 ( V_18 ) ;
if ( V_20 )
F_25 ( V_20 ) ;
}
void F_31 ( struct V_6 * V_7 ,
struct V_11 * V_4 )
{
struct V_19 * V_44 = NULL ;
struct V_19 * V_45 = NULL ;
struct V_11 * V_46 ;
struct V_17 * V_47 = NULL , * V_48 = NULL ;
T_2 V_49 , V_50 ;
V_46 = F_10 ( V_7 ) ;
if ( ! V_46 )
goto V_16;
V_47 = F_20 ( V_46 , V_28 ) ;
if ( ! V_47 )
goto V_16;
V_45 = F_21 ( V_47 ,
V_28 ) ;
if ( ! V_45 )
goto V_16;
if ( V_46 == V_4 )
goto V_10;
V_48 = F_20 ( V_4 , V_28 ) ;
if ( ! V_48 )
goto V_10;
V_44 = F_21 ( V_48 ,
V_28 ) ;
if ( ! V_44 )
goto V_10;
V_49 = V_45 -> V_30 . V_25 ;
V_50 = V_44 -> V_30 . V_25 ;
if ( V_50 < V_49 )
goto V_10;
if ( ( F_22 ( & V_7 -> V_31 ) > 3 ) &&
( V_50 - V_49 < F_22 ( & V_7 -> V_31 ) ) )
goto V_10;
F_30 ( V_40 , V_7 ,
L_5 ,
V_49 , V_50 ) ;
V_16:
F_16 ( V_7 ) ;
V_10:
if ( V_46 )
F_3 ( V_46 ) ;
if ( V_47 )
F_24 ( V_47 ) ;
if ( V_48 )
F_24 ( V_48 ) ;
if ( V_45 )
F_25 ( V_45 ) ;
if ( V_44 )
F_25 ( V_44 ) ;
}
static void F_32 ( struct V_6 * V_7 ,
struct V_11 * V_4 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 ;
if ( V_52 -> V_32 == 0 )
return;
if ( ! F_8 ( & V_4 -> V_3 ) )
return;
V_2 = F_33 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 ) {
F_3 ( V_4 ) ;
return;
}
F_34 ( & V_2 -> V_54 ) ;
V_2 -> V_4 = V_4 ;
F_17 ( & V_2 -> V_3 , 1 ) ;
F_12 ( & V_7 -> V_8 . V_15 ) ;
F_35 ( & V_2 -> V_54 , & V_7 -> V_8 . V_54 ) ;
F_15 ( & V_7 -> V_8 . V_15 ) ;
F_30 ( V_40 , V_7 ,
L_6 ,
V_4 -> V_39 ,
F_36 ( V_52 -> V_32 ) / 10 ,
F_36 ( V_52 -> V_32 ) % 10 ,
F_36 ( V_52 -> V_41 ) / 10 ,
F_36 ( V_52 -> V_41 ) % 10 ) ;
}
static struct V_1 *
F_37 ( struct V_6 * V_7 ,
struct V_11 * V_4 )
{
struct V_1 * V_55 , * V_2 = NULL ;
F_6 () ;
F_19 (gw_node_tmp, &bat_priv->gw.list, list) {
if ( V_55 -> V_4 != V_4 )
continue;
if ( V_55 -> V_27 )
continue;
if ( ! F_8 ( & V_55 -> V_3 ) )
continue;
V_2 = V_55 ;
break;
}
F_9 () ;
return V_2 ;
}
void F_38 ( struct V_6 * V_7 ,
struct V_11 * V_4 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 , * V_9 = NULL ;
V_2 = F_37 ( V_7 , V_4 ) ;
if ( ! V_2 ) {
F_32 ( V_7 , V_4 , V_52 ) ;
goto V_10;
}
if ( ( V_2 -> V_32 == F_36 ( V_52 -> V_32 ) ) &&
( V_2 -> V_41 == F_36 ( V_52 -> V_41 ) ) )
goto V_10;
F_30 ( V_40 , V_7 ,
L_7 ,
V_4 -> V_39 ,
V_2 -> V_32 / 10 ,
V_2 -> V_32 % 10 ,
V_2 -> V_41 / 10 ,
V_2 -> V_41 % 10 ,
F_36 ( V_52 -> V_32 ) / 10 ,
F_36 ( V_52 -> V_32 ) % 10 ,
F_36 ( V_52 -> V_41 ) / 10 ,
F_36 ( V_52 -> V_41 ) % 10 ) ;
V_2 -> V_32 = F_36 ( V_52 -> V_32 ) ;
V_2 -> V_41 = F_36 ( V_52 -> V_41 ) ;
V_2 -> V_27 = 0 ;
if ( F_36 ( V_52 -> V_32 ) == 0 ) {
V_2 -> V_27 = V_56 ;
F_30 ( V_40 , V_7 ,
L_8 ,
V_4 -> V_39 ) ;
V_9 = F_5 ( V_7 ) ;
if ( V_2 == V_9 )
F_16 ( V_7 ) ;
}
V_10:
if ( V_9 )
F_1 ( V_9 ) ;
if ( V_2 )
F_1 ( V_2 ) ;
}
void F_39 ( struct V_6 * V_7 ,
struct V_11 * V_4 )
{
struct V_51 V_52 ;
V_52 . V_32 = 0 ;
V_52 . V_41 = 0 ;
F_38 ( V_7 , V_4 , & V_52 ) ;
}
void F_40 ( struct V_6 * V_7 )
{
struct V_1 * V_2 , * V_9 ;
struct V_57 * V_58 ;
unsigned long V_59 = F_41 ( 2 * V_60 ) ;
int V_61 = 0 ;
V_9 = F_5 ( V_7 ) ;
F_12 ( & V_7 -> V_8 . V_15 ) ;
F_42 (gw_node, node_tmp,
&bat_priv->gw.list, list) {
if ( ( ( ! V_2 -> V_27 ) ||
( F_43 ( V_56 , V_2 -> V_27 + V_59 ) ) ) &&
F_22 ( & V_7 -> V_62 ) == V_63 )
continue;
if ( V_9 == V_2 )
V_61 = 1 ;
F_44 ( & V_2 -> V_54 ) ;
F_1 ( V_2 ) ;
}
F_15 ( & V_7 -> V_8 . V_15 ) ;
if ( V_61 )
F_16 ( V_7 ) ;
if ( V_9 )
F_1 ( V_9 ) ;
}
static int F_45 ( struct V_6 * V_7 ,
struct V_64 * V_65 ,
const struct V_1 * V_2 )
{
struct V_1 * V_9 ;
struct V_17 * V_18 ;
struct V_19 * V_20 = NULL ;
int V_66 = - 1 ;
V_18 = F_20 ( V_2 -> V_4 , V_28 ) ;
if ( ! V_18 )
goto V_10;
V_20 = F_21 ( V_18 , V_28 ) ;
if ( ! V_20 )
goto V_10;
V_9 = F_5 ( V_7 ) ;
V_66 = F_46 ( V_65 , L_9 ,
( V_9 == V_2 ? L_10 : L_11 ) ,
V_2 -> V_4 -> V_39 ,
V_20 -> V_30 . V_25 , V_18 -> V_67 ,
V_18 -> V_68 -> V_69 -> V_70 ,
V_2 -> V_32 / 10 ,
V_2 -> V_32 % 10 ,
V_2 -> V_41 / 10 ,
V_2 -> V_41 % 10 ) ;
if ( V_9 )
F_1 ( V_9 ) ;
V_10:
if ( V_20 )
F_25 ( V_20 ) ;
if ( V_18 )
F_24 ( V_18 ) ;
return V_66 ;
}
int F_47 ( struct V_64 * V_65 , void * V_71 )
{
struct V_72 * V_69 = (struct V_72 * ) V_65 -> V_73 ;
struct V_6 * V_7 = F_48 ( V_69 ) ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
int V_76 = 0 ;
V_75 = F_49 ( V_65 ) ;
if ( ! V_75 )
goto V_10;
F_46 ( V_65 ,
L_12 ,
L_13 , L_14 , V_77 , L_15 , L_16 ,
V_78 , V_75 -> V_69 -> V_70 ,
V_75 -> V_69 -> V_79 , V_69 -> V_70 ) ;
F_6 () ;
F_19 (gw_node, &bat_priv->gw.list, list) {
if ( V_2 -> V_27 )
continue;
if ( F_45 ( V_7 , V_65 , V_2 ) < 0 )
continue;
V_76 ++ ;
}
F_9 () ;
if ( V_76 == 0 )
F_50 ( V_65 , L_17 ) ;
V_10:
if ( V_75 )
F_51 ( V_75 ) ;
return 0 ;
}
enum V_80
F_52 ( struct V_81 * V_82 , unsigned int * V_83 ,
T_2 * V_84 )
{
enum V_80 V_66 = V_85 ;
struct V_86 * V_86 ;
struct V_87 * V_87 ;
struct V_88 * V_88 ;
struct V_89 * V_89 ;
struct V_90 * V_91 ;
int V_92 ;
T_3 V_93 ;
T_2 * V_94 ;
if ( ! F_53 ( V_82 , * V_83 + V_95 ) )
return V_85 ;
V_86 = F_54 ( V_82 ) ;
V_93 = V_86 -> V_96 ;
* V_83 += V_95 ;
if ( V_93 == F_55 ( V_97 ) ) {
if ( ! F_53 ( V_82 , * V_83 + V_98 ) )
return V_85 ;
V_91 = F_56 ( V_82 ) ;
V_93 = V_91 -> V_99 ;
* V_83 += V_98 ;
}
switch ( V_93 ) {
case F_55 ( V_100 ) :
if ( ! F_53 ( V_82 , * V_83 + sizeof( * V_87 ) ) )
return V_85 ;
V_87 = (struct V_87 * ) ( V_82 -> V_101 + * V_83 ) ;
* V_83 += V_87 -> V_102 * 4 ;
if ( V_87 -> V_103 != V_104 )
return V_85 ;
break;
case F_55 ( V_105 ) :
if ( ! F_53 ( V_82 , * V_83 + sizeof( * V_88 ) ) )
return V_85 ;
V_88 = (struct V_88 * ) ( V_82 -> V_101 + * V_83 ) ;
* V_83 += sizeof( * V_88 ) ;
if ( V_88 -> V_106 != V_104 )
return V_85 ;
break;
default:
return V_85 ;
}
if ( ! F_53 ( V_82 , * V_83 + sizeof( * V_89 ) ) )
return V_85 ;
V_86 = F_54 ( V_82 ) ;
if ( F_57 ( V_86 -> V_96 ) == V_97 )
V_86 = (struct V_86 * ) ( V_82 -> V_101 + V_98 ) ;
V_89 = (struct V_89 * ) ( V_82 -> V_101 + * V_83 ) ;
* V_83 += sizeof( * V_89 ) ;
switch ( V_93 ) {
case F_55 ( V_100 ) :
if ( V_89 -> V_107 == F_55 ( 67 ) )
V_66 = V_108 ;
else if ( V_89 -> V_109 == F_55 ( 67 ) )
V_66 = V_110 ;
break;
case F_55 ( V_105 ) :
if ( V_89 -> V_107 == F_55 ( 547 ) )
V_66 = V_108 ;
else if ( V_89 -> V_109 == F_55 ( 547 ) )
V_66 = V_110 ;
break;
}
V_92 = * V_83 + V_111 ;
if ( V_66 == V_110 &&
F_53 ( V_82 , V_92 + V_112 ) ) {
V_94 = V_82 -> V_101 + * V_83 + V_113 ;
if ( * V_94 != V_114 )
return V_85 ;
V_94 = V_82 -> V_101 + * V_83 + V_115 ;
if ( * V_94 != V_112 )
return V_85 ;
F_58 ( V_84 , V_82 -> V_101 + V_92 ) ;
}
return V_66 ;
}
bool F_59 ( struct V_6 * V_7 ,
struct V_81 * V_82 )
{
struct V_17 * V_116 = NULL , * V_117 = NULL ;
struct V_11 * V_118 = NULL ;
struct V_1 * V_2 = NULL , * V_9 = NULL ;
struct V_19 * V_119 , * V_120 ;
struct V_86 * V_86 = (struct V_86 * ) V_82 -> V_101 ;
bool V_121 = false ;
T_2 V_122 ;
unsigned short V_123 ;
V_123 = F_60 ( V_82 , 0 ) ;
V_118 = F_61 ( V_7 , V_86 -> V_124 ,
V_86 -> V_125 , V_123 ) ;
if ( ! V_118 )
goto V_10;
V_2 = F_37 ( V_7 , V_118 ) ;
if ( ! V_2 -> V_32 == 0 )
goto V_10;
switch ( F_22 ( & V_7 -> V_33 ) ) {
case V_126 :
V_122 = V_77 ;
break;
case V_34 :
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
goto V_10;
if ( V_9 -> V_4 == V_118 )
goto V_10;
V_116 = F_62 ( V_7 , V_9 -> V_4 ,
NULL ) ;
if ( ! V_116 )
goto V_10;
V_119 = F_21 ( V_116 ,
V_28 ) ;
if ( ! V_119 )
goto V_10;
V_122 = V_119 -> V_30 . V_25 ;
F_25 ( V_119 ) ;
break;
case V_127 :
default:
goto V_10;
}
V_117 = F_62 ( V_7 , V_118 , NULL ) ;
if ( ! V_117 )
goto V_10;
V_120 = F_21 ( V_117 , V_28 ) ;
if ( ! V_120 )
goto V_10;
if ( ( V_122 - V_120 -> V_30 . V_25 ) > V_128 )
V_121 = true ;
F_25 ( V_120 ) ;
V_10:
if ( V_118 )
F_3 ( V_118 ) ;
if ( V_9 )
F_1 ( V_9 ) ;
if ( V_2 )
F_1 ( V_2 ) ;
if ( V_117 )
F_24 ( V_117 ) ;
if ( V_116 )
F_24 ( V_116 ) ;
return V_121 ;
}
