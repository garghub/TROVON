static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( V_4 , V_7 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
F_6 ( & V_4 -> V_5 , F_1 ) ;
}
static struct V_3 *
F_7 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
F_8 () ;
V_4 = F_9 ( V_9 -> V_10 . V_11 ) ;
if ( ! V_4 )
goto V_12;
if ( ! F_10 ( & V_4 -> V_5 ) )
V_4 = NULL ;
V_12:
F_11 () ;
return V_4 ;
}
struct V_13 *
F_12 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
struct V_13 * V_6 = NULL ;
V_4 = F_7 ( V_9 ) ;
if ( ! V_4 )
goto V_12;
F_8 () ;
V_6 = V_4 -> V_6 ;
if ( ! V_6 )
goto V_14;
if ( ! F_10 ( & V_6 -> V_5 ) )
V_6 = NULL ;
V_14:
F_11 () ;
V_12:
if ( V_4 )
F_5 ( V_4 ) ;
return V_6 ;
}
static void F_13 ( struct V_8 * V_9 ,
struct V_3 * V_15 )
{
struct V_3 * V_16 ;
F_14 ( & V_9 -> V_10 . V_17 ) ;
if ( V_15 )
F_15 ( & V_15 -> V_5 ) ;
V_16 = F_16 ( V_9 -> V_10 . V_11 , 1 ) ;
F_17 ( V_9 -> V_10 . V_11 , V_15 ) ;
if ( V_16 )
F_5 ( V_16 ) ;
F_18 ( & V_9 -> V_10 . V_17 ) ;
}
void F_19 ( struct V_8 * V_9 )
{
F_20 ( & V_9 -> V_10 . V_18 , 1 ) ;
}
static struct V_3 *
F_21 ( struct V_8 * V_9 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_3 * V_4 , * V_11 = NULL ;
T_1 V_23 = 0 ;
T_1 V_24 = 0 ;
T_2 V_25 = 0 ;
T_2 V_26 ;
struct V_13 * V_6 ;
F_8 () ;
F_22 (gw_node, &bat_priv->gw.list, list) {
V_6 = V_4 -> V_6 ;
V_20 = F_23 ( V_6 , V_27 ) ;
if ( ! V_20 )
continue;
V_22 = F_24 ( V_20 ,
V_27 ) ;
if ( ! V_22 )
goto V_28;
if ( ! F_10 ( & V_4 -> V_5 ) )
goto V_28;
V_26 = V_22 -> V_29 . V_26 ;
switch ( F_25 ( & V_9 -> V_30 ) ) {
case 1 :
V_24 = V_26 * V_26 ;
V_24 *= V_4 -> V_31 ;
V_24 *= 100 * 100 ;
V_24 >>= 18 ;
if ( ( V_24 > V_23 ) ||
( ( V_24 == V_23 ) &&
( V_26 > V_25 ) ) ) {
if ( V_11 )
F_5 ( V_11 ) ;
V_11 = V_4 ;
F_15 ( & V_11 -> V_5 ) ;
}
break;
default:
if ( V_26 > V_25 ) {
if ( V_11 )
F_5 ( V_11 ) ;
V_11 = V_4 ;
F_15 ( & V_11 -> V_5 ) ;
}
break;
}
if ( V_26 > V_25 )
V_25 = V_26 ;
if ( V_24 > V_23 )
V_23 = V_24 ;
F_5 ( V_4 ) ;
V_28:
F_26 ( V_20 ) ;
if ( V_22 )
F_27 ( V_22 ) ;
}
F_11 () ;
return V_11 ;
}
void F_28 ( struct V_8 * V_9 )
{
struct V_3 * V_11 ;
if ( F_25 ( & V_9 -> V_32 ) != V_33 )
return;
V_11 = F_7 ( V_9 ) ;
if ( ! V_11 )
return;
F_13 ( V_9 , NULL ) ;
F_29 ( V_9 , V_34 , V_35 , NULL ) ;
F_5 ( V_11 ) ;
}
void F_30 ( struct V_8 * V_9 )
{
struct V_3 * V_11 = NULL ;
struct V_3 * V_36 = NULL ;
struct V_19 * V_20 = NULL ;
struct V_21 * V_22 = NULL ;
char V_37 [ 18 ] = { '\0' } ;
if ( F_25 ( & V_9 -> V_32 ) != V_33 )
goto V_12;
V_11 = F_7 ( V_9 ) ;
if ( ! F_31 ( & V_9 -> V_10 . V_18 ) && V_11 )
goto V_12;
V_36 = F_21 ( V_9 ) ;
if ( V_11 == V_36 )
goto V_12;
if ( V_36 ) {
sprintf ( V_37 , L_1 , V_36 -> V_6 -> V_38 ) ;
V_20 = F_23 ( V_36 -> V_6 ,
V_27 ) ;
if ( ! V_20 ) {
F_19 ( V_9 ) ;
goto V_12;
}
V_22 = F_24 ( V_20 ,
V_27 ) ;
if ( ! V_22 ) {
F_19 ( V_9 ) ;
goto V_12;
}
}
if ( ( V_11 ) && ( ! V_36 ) ) {
F_32 ( V_39 , V_9 ,
L_2 ) ;
F_29 ( V_9 , V_34 , V_35 ,
NULL ) ;
} else if ( ( ! V_11 ) && ( V_36 ) ) {
F_32 ( V_39 , V_9 ,
L_3 ,
V_36 -> V_6 -> V_38 ,
V_36 -> V_31 / 10 ,
V_36 -> V_31 % 10 ,
V_36 -> V_40 / 10 ,
V_36 -> V_40 % 10 ,
V_22 -> V_29 . V_26 ) ;
F_29 ( V_9 , V_34 , V_41 ,
V_37 ) ;
} else {
F_32 ( V_39 , V_9 ,
L_4 ,
V_36 -> V_6 -> V_38 ,
V_36 -> V_31 / 10 ,
V_36 -> V_31 % 10 ,
V_36 -> V_40 / 10 ,
V_36 -> V_40 % 10 ,
V_22 -> V_29 . V_26 ) ;
F_29 ( V_9 , V_34 , V_42 ,
V_37 ) ;
}
F_13 ( V_9 , V_36 ) ;
V_12:
if ( V_11 )
F_5 ( V_11 ) ;
if ( V_36 )
F_5 ( V_36 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
if ( V_22 )
F_27 ( V_22 ) ;
}
void F_33 ( struct V_8 * V_9 ,
struct V_13 * V_6 )
{
struct V_21 * V_43 = NULL ;
struct V_21 * V_44 = NULL ;
struct V_13 * V_45 ;
struct V_19 * V_46 = NULL ;
struct V_19 * V_47 = NULL ;
T_2 V_48 , V_49 ;
V_45 = F_12 ( V_9 ) ;
if ( ! V_45 )
goto V_18;
V_46 = F_23 ( V_45 , V_27 ) ;
if ( ! V_46 )
goto V_18;
V_44 = F_24 ( V_46 ,
V_27 ) ;
if ( ! V_44 )
goto V_18;
if ( V_45 == V_6 )
goto V_12;
V_47 = F_23 ( V_6 , V_27 ) ;
if ( ! V_47 )
goto V_12;
V_43 = F_24 ( V_47 ,
V_27 ) ;
if ( ! V_43 )
goto V_12;
V_48 = V_44 -> V_29 . V_26 ;
V_49 = V_43 -> V_29 . V_26 ;
if ( V_49 < V_48 )
goto V_12;
if ( ( F_25 ( & V_9 -> V_30 ) > 3 ) &&
( V_49 - V_48 < F_25 ( & V_9 -> V_30 ) ) )
goto V_12;
F_32 ( V_39 , V_9 ,
L_5 ,
V_48 , V_49 ) ;
V_18:
F_19 ( V_9 ) ;
V_12:
if ( V_45 )
F_3 ( V_45 ) ;
if ( V_46 )
F_26 ( V_46 ) ;
if ( V_47 )
F_26 ( V_47 ) ;
if ( V_44 )
F_27 ( V_44 ) ;
if ( V_43 )
F_27 ( V_43 ) ;
}
static void F_34 ( struct V_8 * V_9 ,
struct V_13 * V_6 ,
struct V_50 * V_51 )
{
struct V_3 * V_4 ;
if ( V_51 -> V_31 == 0 )
return;
V_4 = F_35 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return;
F_15 ( & V_6 -> V_5 ) ;
F_36 ( & V_4 -> V_53 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_31 = F_37 ( V_51 -> V_31 ) ;
V_4 -> V_40 = F_37 ( V_51 -> V_40 ) ;
F_38 ( & V_4 -> V_5 ) ;
F_14 ( & V_9 -> V_10 . V_17 ) ;
F_39 ( & V_4 -> V_53 , & V_9 -> V_10 . V_53 ) ;
F_18 ( & V_9 -> V_10 . V_17 ) ;
F_32 ( V_39 , V_9 ,
L_6 ,
V_6 -> V_38 ,
F_37 ( V_51 -> V_31 ) / 10 ,
F_37 ( V_51 -> V_31 ) % 10 ,
F_37 ( V_51 -> V_40 ) / 10 ,
F_37 ( V_51 -> V_40 ) % 10 ) ;
}
static struct V_3 *
F_40 ( struct V_8 * V_9 ,
struct V_13 * V_6 )
{
struct V_3 * V_54 , * V_4 = NULL ;
F_8 () ;
F_22 (gw_node_tmp, &bat_priv->gw.list, list) {
if ( V_54 -> V_6 != V_6 )
continue;
if ( ! F_10 ( & V_54 -> V_5 ) )
continue;
V_4 = V_54 ;
break;
}
F_11 () ;
return V_4 ;
}
void F_41 ( struct V_8 * V_9 ,
struct V_13 * V_6 ,
struct V_50 * V_51 )
{
struct V_3 * V_4 , * V_11 = NULL ;
V_4 = F_40 ( V_9 , V_6 ) ;
if ( ! V_4 ) {
F_34 ( V_9 , V_6 , V_51 ) ;
goto V_12;
}
if ( ( V_4 -> V_31 == F_37 ( V_51 -> V_31 ) ) &&
( V_4 -> V_40 == F_37 ( V_51 -> V_40 ) ) )
goto V_12;
F_32 ( V_39 , V_9 ,
L_7 ,
V_6 -> V_38 ,
V_4 -> V_31 / 10 ,
V_4 -> V_31 % 10 ,
V_4 -> V_40 / 10 ,
V_4 -> V_40 % 10 ,
F_37 ( V_51 -> V_31 ) / 10 ,
F_37 ( V_51 -> V_31 ) % 10 ,
F_37 ( V_51 -> V_40 ) / 10 ,
F_37 ( V_51 -> V_40 ) % 10 ) ;
V_4 -> V_31 = F_37 ( V_51 -> V_31 ) ;
V_4 -> V_40 = F_37 ( V_51 -> V_40 ) ;
if ( F_37 ( V_51 -> V_31 ) == 0 ) {
F_32 ( V_39 , V_9 ,
L_8 ,
V_6 -> V_38 ) ;
F_14 ( & V_9 -> V_10 . V_17 ) ;
if ( ! F_42 ( & V_4 -> V_53 ) ) {
F_43 ( & V_4 -> V_53 ) ;
F_5 ( V_4 ) ;
}
F_18 ( & V_9 -> V_10 . V_17 ) ;
V_11 = F_7 ( V_9 ) ;
if ( V_4 == V_11 )
F_19 ( V_9 ) ;
if ( V_11 )
F_5 ( V_11 ) ;
}
V_12:
if ( V_4 )
F_5 ( V_4 ) ;
}
void F_44 ( struct V_8 * V_9 ,
struct V_13 * V_6 )
{
struct V_50 V_51 ;
V_51 . V_31 = 0 ;
V_51 . V_40 = 0 ;
F_41 ( V_9 , V_6 , & V_51 ) ;
}
void F_45 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
struct V_55 * V_56 ;
F_14 ( & V_9 -> V_10 . V_17 ) ;
F_46 (gw_node, node_tmp,
&bat_priv->gw.list, list) {
F_43 ( & V_4 -> V_53 ) ;
F_5 ( V_4 ) ;
}
F_18 ( & V_9 -> V_10 . V_17 ) ;
}
static int F_47 ( struct V_8 * V_9 ,
struct V_57 * V_58 ,
const struct V_3 * V_4 )
{
struct V_3 * V_11 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
int V_59 = - 1 ;
V_20 = F_23 ( V_4 -> V_6 , V_27 ) ;
if ( ! V_20 )
goto V_12;
V_22 = F_24 ( V_20 , V_27 ) ;
if ( ! V_22 )
goto V_12;
V_11 = F_7 ( V_9 ) ;
F_48 ( V_58 , L_9 ,
( V_11 == V_4 ? L_10 : L_11 ) ,
V_4 -> V_6 -> V_38 ,
V_22 -> V_29 . V_26 , V_20 -> V_60 ,
V_20 -> V_61 -> V_62 -> V_63 ,
V_4 -> V_31 / 10 ,
V_4 -> V_31 % 10 ,
V_4 -> V_40 / 10 ,
V_4 -> V_40 % 10 ) ;
V_59 = F_49 ( V_58 ) ? - 1 : 0 ;
if ( V_11 )
F_5 ( V_11 ) ;
V_12:
if ( V_22 )
F_27 ( V_22 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
return V_59 ;
}
int F_50 ( struct V_57 * V_58 , void * V_64 )
{
struct V_65 * V_62 = (struct V_65 * ) V_58 -> V_66 ;
struct V_8 * V_9 = F_51 ( V_62 ) ;
struct V_67 * V_68 ;
struct V_3 * V_4 ;
int V_69 = 0 ;
V_68 = F_52 ( V_58 ) ;
if ( ! V_68 )
goto V_12;
F_48 ( V_58 ,
L_12 ,
L_13 , L_14 , V_70 , L_15 , L_16 ,
V_71 , V_68 -> V_62 -> V_63 ,
V_68 -> V_62 -> V_72 , V_62 -> V_63 ) ;
F_8 () ;
F_22 (gw_node, &bat_priv->gw.list, list) {
if ( F_47 ( V_9 , V_58 , V_4 ) < 0 )
continue;
V_69 ++ ;
}
F_11 () ;
if ( V_69 == 0 )
F_53 ( V_58 , L_17 ) ;
V_12:
if ( V_68 )
F_54 ( V_68 ) ;
return 0 ;
}
enum V_73
F_55 ( struct V_74 * V_75 , unsigned int * V_76 ,
T_2 * V_77 )
{
enum V_73 V_59 = V_78 ;
struct V_79 * V_79 ;
struct V_80 * V_80 ;
struct V_81 * V_81 ;
struct V_82 * V_82 ;
struct V_83 * V_84 ;
int V_85 ;
T_3 V_86 ;
T_2 * V_87 ;
if ( ! F_56 ( V_75 , * V_76 + V_88 ) )
return V_78 ;
V_79 = F_57 ( V_75 ) ;
V_86 = V_79 -> V_89 ;
* V_76 += V_88 ;
if ( V_86 == F_58 ( V_90 ) ) {
if ( ! F_56 ( V_75 , * V_76 + V_91 ) )
return V_78 ;
V_84 = F_59 ( V_75 ) ;
V_86 = V_84 -> V_92 ;
* V_76 += V_91 ;
}
switch ( V_86 ) {
case F_58 ( V_93 ) :
if ( ! F_56 ( V_75 , * V_76 + sizeof( * V_80 ) ) )
return V_78 ;
V_80 = (struct V_80 * ) ( V_75 -> V_94 + * V_76 ) ;
* V_76 += V_80 -> V_95 * 4 ;
if ( V_80 -> V_96 != V_97 )
return V_78 ;
break;
case F_58 ( V_98 ) :
if ( ! F_56 ( V_75 , * V_76 + sizeof( * V_81 ) ) )
return V_78 ;
V_81 = (struct V_81 * ) ( V_75 -> V_94 + * V_76 ) ;
* V_76 += sizeof( * V_81 ) ;
if ( V_81 -> V_99 != V_97 )
return V_78 ;
break;
default:
return V_78 ;
}
if ( ! F_56 ( V_75 , * V_76 + sizeof( * V_82 ) ) )
return V_78 ;
V_82 = (struct V_82 * ) ( V_75 -> V_94 + * V_76 ) ;
* V_76 += sizeof( * V_82 ) ;
switch ( V_86 ) {
case F_58 ( V_93 ) :
if ( V_82 -> V_100 == F_58 ( 67 ) )
V_59 = V_101 ;
else if ( V_82 -> V_102 == F_58 ( 67 ) )
V_59 = V_103 ;
break;
case F_58 ( V_98 ) :
if ( V_82 -> V_100 == F_58 ( 547 ) )
V_59 = V_101 ;
else if ( V_82 -> V_102 == F_58 ( 547 ) )
V_59 = V_103 ;
break;
}
V_85 = * V_76 + V_104 ;
if ( V_59 == V_103 &&
F_56 ( V_75 , V_85 + V_105 ) ) {
V_87 = V_75 -> V_94 + * V_76 + V_106 ;
if ( * V_87 != V_107 )
return V_78 ;
V_87 = V_75 -> V_94 + * V_76 + V_108 ;
if ( * V_87 != V_105 )
return V_78 ;
F_60 ( V_77 , V_75 -> V_94 + V_85 ) ;
}
return V_59 ;
}
bool F_61 ( struct V_8 * V_9 ,
struct V_74 * V_75 )
{
struct V_19 * V_109 = NULL ;
struct V_19 * V_110 = NULL ;
struct V_13 * V_111 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_11 = NULL ;
struct V_21 * V_112 , * V_113 ;
struct V_79 * V_79 = (struct V_79 * ) V_75 -> V_94 ;
bool V_114 = false ;
T_2 V_115 ;
unsigned short V_116 ;
V_116 = F_62 ( V_75 , 0 ) ;
V_111 = F_63 ( V_9 , V_79 -> V_117 ,
V_79 -> V_118 , V_116 ) ;
if ( ! V_111 )
goto V_12;
V_4 = F_40 ( V_9 , V_111 ) ;
if ( ! V_4 )
goto V_12;
switch ( F_25 ( & V_9 -> V_32 ) ) {
case V_119 :
V_115 = V_70 ;
break;
case V_33 :
V_11 = F_7 ( V_9 ) ;
if ( ! V_11 )
goto V_12;
if ( V_11 -> V_6 == V_111 )
goto V_12;
V_109 = F_64 ( V_9 , V_11 -> V_6 ,
NULL ) ;
if ( ! V_109 )
goto V_12;
V_112 = F_24 ( V_109 ,
V_27 ) ;
if ( ! V_112 )
goto V_12;
V_115 = V_112 -> V_29 . V_26 ;
F_27 ( V_112 ) ;
break;
case V_120 :
default:
goto V_12;
}
V_110 = F_64 ( V_9 , V_111 , NULL ) ;
if ( ! V_110 )
goto V_12;
V_113 = F_24 ( V_110 , V_27 ) ;
if ( ! V_113 )
goto V_12;
if ( ( V_115 - V_113 -> V_29 . V_26 ) > V_121 )
V_114 = true ;
F_27 ( V_113 ) ;
V_12:
if ( V_111 )
F_3 ( V_111 ) ;
if ( V_11 )
F_5 ( V_11 ) ;
if ( V_4 )
F_5 ( V_4 ) ;
if ( V_110 )
F_26 ( V_110 ) ;
if ( V_109 )
F_26 ( V_109 ) ;
return V_114 ;
}
