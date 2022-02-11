static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( V_4 , V_7 ) ;
}
void F_5 ( struct V_3 * V_4 )
{
F_6 ( & V_4 -> V_5 , F_1 ) ;
}
struct V_3 *
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
void F_21 ( struct V_8 * V_9 )
{
struct V_3 * V_11 ;
if ( F_22 ( & V_9 -> V_10 . V_19 ) != V_20 )
return;
V_11 = F_7 ( V_9 ) ;
if ( ! V_11 )
return;
F_13 ( V_9 , NULL ) ;
F_23 ( V_9 , V_21 , V_22 , NULL ) ;
F_5 ( V_11 ) ;
}
void F_24 ( struct V_8 * V_9 )
{
struct V_3 * V_11 = NULL ;
struct V_3 * V_23 = NULL ;
struct V_24 * V_25 = NULL ;
struct V_26 * V_27 = NULL ;
char V_28 [ 18 ] = { '\0' } ;
if ( F_22 ( & V_9 -> V_10 . V_19 ) != V_20 )
goto V_12;
if ( ! V_9 -> V_29 -> V_10 . V_30 )
goto V_12;
V_11 = F_7 ( V_9 ) ;
if ( ! F_25 ( & V_9 -> V_10 . V_18 ) && V_11 )
goto V_12;
V_23 = V_9 -> V_29 -> V_10 . V_30 ( V_9 ) ;
if ( V_11 == V_23 )
goto V_12;
if ( V_23 ) {
sprintf ( V_28 , L_1 , V_23 -> V_6 -> V_31 ) ;
V_25 = F_26 ( V_23 -> V_6 ,
V_32 ) ;
if ( ! V_25 ) {
F_19 ( V_9 ) ;
goto V_12;
}
V_27 = F_27 ( V_25 ,
V_32 ) ;
if ( ! V_27 ) {
F_19 ( V_9 ) ;
goto V_12;
}
}
if ( ( V_11 ) && ( ! V_23 ) ) {
F_28 ( V_33 , V_9 ,
L_2 ) ;
F_23 ( V_9 , V_21 , V_22 ,
NULL ) ;
} else if ( ( ! V_11 ) && ( V_23 ) ) {
F_28 ( V_33 , V_9 ,
L_3 ,
V_23 -> V_6 -> V_31 ,
V_23 -> V_34 / 10 ,
V_23 -> V_34 % 10 ,
V_23 -> V_35 / 10 ,
V_23 -> V_35 % 10 ,
V_27 -> V_36 . V_37 ) ;
F_23 ( V_9 , V_21 , V_38 ,
V_28 ) ;
} else {
F_28 ( V_33 , V_9 ,
L_4 ,
V_23 -> V_6 -> V_31 ,
V_23 -> V_34 / 10 ,
V_23 -> V_34 % 10 ,
V_23 -> V_35 / 10 ,
V_23 -> V_35 % 10 ,
V_27 -> V_36 . V_37 ) ;
F_23 ( V_9 , V_21 , V_39 ,
V_28 ) ;
}
F_13 ( V_9 , V_23 ) ;
V_12:
if ( V_11 )
F_5 ( V_11 ) ;
if ( V_23 )
F_5 ( V_23 ) ;
if ( V_25 )
F_29 ( V_25 ) ;
if ( V_27 )
F_30 ( V_27 ) ;
}
void F_31 ( struct V_8 * V_9 ,
struct V_13 * V_6 )
{
struct V_13 * V_40 ;
if ( ! V_9 -> V_29 -> V_10 . V_41 )
return;
V_40 = F_12 ( V_9 ) ;
if ( ! V_40 )
goto V_18;
if ( V_40 == V_6 )
goto V_12;
if ( ! V_9 -> V_29 -> V_10 . V_41 ( V_9 , V_40 ,
V_6 ) )
goto V_12;
V_18:
F_19 ( V_9 ) ;
V_12:
if ( V_40 )
F_3 ( V_40 ) ;
}
static void F_32 ( struct V_8 * V_9 ,
struct V_13 * V_6 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 ;
if ( V_43 -> V_34 == 0 )
return;
V_4 = F_33 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return;
F_34 ( & V_4 -> V_5 ) ;
F_35 ( & V_4 -> V_45 ) ;
F_15 ( & V_6 -> V_5 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_34 = F_36 ( V_43 -> V_34 ) ;
V_4 -> V_35 = F_36 ( V_43 -> V_35 ) ;
F_14 ( & V_9 -> V_10 . V_17 ) ;
F_15 ( & V_4 -> V_5 ) ;
F_37 ( & V_4 -> V_45 , & V_9 -> V_10 . V_45 ) ;
F_18 ( & V_9 -> V_10 . V_17 ) ;
F_28 ( V_33 , V_9 ,
L_5 ,
V_6 -> V_31 ,
F_36 ( V_43 -> V_34 ) / 10 ,
F_36 ( V_43 -> V_34 ) % 10 ,
F_36 ( V_43 -> V_35 ) / 10 ,
F_36 ( V_43 -> V_35 ) % 10 ) ;
F_5 ( V_4 ) ;
}
struct V_3 * F_38 ( struct V_8 * V_9 ,
struct V_13 * V_6 )
{
struct V_3 * V_46 , * V_4 = NULL ;
F_8 () ;
F_39 (gw_node_tmp, &bat_priv->gw.list, list) {
if ( V_46 -> V_6 != V_6 )
continue;
if ( ! F_10 ( & V_46 -> V_5 ) )
continue;
V_4 = V_46 ;
break;
}
F_11 () ;
return V_4 ;
}
void F_40 ( struct V_8 * V_9 ,
struct V_13 * V_6 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 , * V_11 = NULL ;
V_4 = F_38 ( V_9 , V_6 ) ;
if ( ! V_4 ) {
F_32 ( V_9 , V_6 , V_43 ) ;
goto V_12;
}
if ( ( V_4 -> V_34 == F_36 ( V_43 -> V_34 ) ) &&
( V_4 -> V_35 == F_36 ( V_43 -> V_35 ) ) )
goto V_12;
F_28 ( V_33 , V_9 ,
L_6 ,
V_6 -> V_31 ,
V_4 -> V_34 / 10 ,
V_4 -> V_34 % 10 ,
V_4 -> V_35 / 10 ,
V_4 -> V_35 % 10 ,
F_36 ( V_43 -> V_34 ) / 10 ,
F_36 ( V_43 -> V_34 ) % 10 ,
F_36 ( V_43 -> V_35 ) / 10 ,
F_36 ( V_43 -> V_35 ) % 10 ) ;
V_4 -> V_34 = F_36 ( V_43 -> V_34 ) ;
V_4 -> V_35 = F_36 ( V_43 -> V_35 ) ;
if ( F_36 ( V_43 -> V_34 ) == 0 ) {
F_28 ( V_33 , V_9 ,
L_7 ,
V_6 -> V_31 ) ;
F_14 ( & V_9 -> V_10 . V_17 ) ;
if ( ! F_41 ( & V_4 -> V_45 ) ) {
F_42 ( & V_4 -> V_45 ) ;
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
void F_43 ( struct V_8 * V_9 ,
struct V_13 * V_6 )
{
struct V_42 V_43 ;
V_43 . V_34 = 0 ;
V_43 . V_35 = 0 ;
F_40 ( V_9 , V_6 , & V_43 ) ;
}
void F_44 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
struct V_47 * V_48 ;
F_14 ( & V_9 -> V_10 . V_17 ) ;
F_45 (gw_node, node_tmp,
&bat_priv->gw.list, list) {
F_42 ( & V_4 -> V_45 ) ;
F_5 ( V_4 ) ;
}
F_18 ( & V_9 -> V_10 . V_17 ) ;
}
int F_46 ( struct V_49 * V_50 , void * V_51 )
{
struct V_52 * V_53 = (struct V_52 * ) V_50 -> V_54 ;
struct V_8 * V_9 = F_47 ( V_53 ) ;
struct V_55 * V_56 ;
V_56 = F_48 ( V_50 ) ;
if ( ! V_56 )
return 0 ;
F_49 ( V_50 , L_8 ,
V_57 , V_56 -> V_53 -> V_58 ,
V_56 -> V_53 -> V_59 , V_53 -> V_58 ,
V_9 -> V_29 -> V_58 ) ;
F_50 ( V_56 ) ;
if ( ! V_9 -> V_29 -> V_10 . V_60 ) {
F_51 ( V_50 ,
L_9 ) ;
return 0 ;
}
V_9 -> V_29 -> V_10 . V_60 ( V_9 , V_50 ) ;
return 0 ;
}
int F_52 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_55 * V_56 = NULL ;
struct V_65 * V_65 = F_53 ( V_64 -> V_66 -> V_67 ) ;
struct V_52 * V_68 ;
struct V_8 * V_9 ;
int V_69 ;
int V_70 ;
V_69 = F_54 ( V_64 -> V_71 ,
V_72 ) ;
if ( ! V_69 )
return - V_73 ;
V_68 = F_55 ( V_65 , V_69 ) ;
if ( ! V_68 || ! F_56 ( V_68 ) ) {
V_70 = - V_74 ;
goto V_12;
}
V_9 = F_47 ( V_68 ) ;
V_56 = F_57 ( V_9 ) ;
if ( ! V_56 || V_56 -> V_75 != V_76 ) {
V_70 = - V_77 ;
goto V_12;
}
if ( ! V_9 -> V_29 -> V_10 . V_78 ) {
V_70 = - V_79 ;
goto V_12;
}
V_9 -> V_29 -> V_10 . V_78 ( V_62 , V_64 , V_9 ) ;
V_70 = V_62 -> V_80 ;
V_12:
if ( V_56 )
F_50 ( V_56 ) ;
if ( V_68 )
F_58 ( V_68 ) ;
return V_70 ;
}
enum V_81
F_59 ( struct V_61 * V_66 , unsigned int * V_82 ,
T_1 * V_83 )
{
enum V_81 V_70 = V_84 ;
struct V_85 * V_85 ;
struct V_86 * V_86 ;
struct V_87 * V_87 ;
struct V_88 * V_88 ;
struct V_89 * V_90 ;
int V_91 ;
T_2 V_92 ;
T_1 * V_93 ;
if ( ! F_60 ( V_66 , * V_82 + V_94 ) )
return V_84 ;
V_85 = F_61 ( V_66 ) ;
V_92 = V_85 -> V_95 ;
* V_82 += V_94 ;
if ( V_92 == F_62 ( V_96 ) ) {
if ( ! F_60 ( V_66 , * V_82 + V_97 ) )
return V_84 ;
V_90 = F_63 ( V_66 ) ;
V_92 = V_90 -> V_98 ;
* V_82 += V_97 ;
}
switch ( V_92 ) {
case F_62 ( V_99 ) :
if ( ! F_60 ( V_66 , * V_82 + sizeof( * V_86 ) ) )
return V_84 ;
V_86 = (struct V_86 * ) ( V_66 -> V_100 + * V_82 ) ;
* V_82 += V_86 -> V_101 * 4 ;
if ( V_86 -> V_102 != V_103 )
return V_84 ;
break;
case F_62 ( V_104 ) :
if ( ! F_60 ( V_66 , * V_82 + sizeof( * V_87 ) ) )
return V_84 ;
V_87 = (struct V_87 * ) ( V_66 -> V_100 + * V_82 ) ;
* V_82 += sizeof( * V_87 ) ;
if ( V_87 -> V_105 != V_103 )
return V_84 ;
break;
default:
return V_84 ;
}
if ( ! F_60 ( V_66 , * V_82 + sizeof( * V_88 ) ) )
return V_84 ;
V_88 = (struct V_88 * ) ( V_66 -> V_100 + * V_82 ) ;
* V_82 += sizeof( * V_88 ) ;
switch ( V_92 ) {
case F_62 ( V_99 ) :
if ( V_88 -> V_106 == F_62 ( 67 ) )
V_70 = V_107 ;
else if ( V_88 -> V_108 == F_62 ( 67 ) )
V_70 = V_109 ;
break;
case F_62 ( V_104 ) :
if ( V_88 -> V_106 == F_62 ( 547 ) )
V_70 = V_107 ;
else if ( V_88 -> V_108 == F_62 ( 547 ) )
V_70 = V_109 ;
break;
}
V_91 = * V_82 + V_110 ;
if ( V_70 == V_109 &&
F_60 ( V_66 , V_91 + V_111 ) ) {
V_93 = V_66 -> V_100 + * V_82 + V_112 ;
if ( * V_93 != V_113 )
return V_84 ;
V_93 = V_66 -> V_100 + * V_82 + V_114 ;
if ( * V_93 != V_111 )
return V_84 ;
F_64 ( V_83 , V_66 -> V_100 + V_91 ) ;
}
return V_70 ;
}
bool F_65 ( struct V_8 * V_9 ,
struct V_61 * V_66 )
{
struct V_24 * V_115 = NULL ;
struct V_24 * V_116 = NULL ;
struct V_13 * V_117 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_11 = NULL ;
struct V_26 * V_118 , * V_119 ;
struct V_85 * V_85 = (struct V_85 * ) V_66 -> V_100 ;
bool V_120 = false ;
T_1 V_121 ;
unsigned short V_122 ;
V_122 = F_66 ( V_66 , 0 ) ;
V_117 = F_67 ( V_9 , V_85 -> V_123 ,
V_85 -> V_124 , V_122 ) ;
if ( ! V_117 )
goto V_12;
V_4 = F_38 ( V_9 , V_117 ) ;
if ( ! V_4 )
goto V_12;
switch ( F_22 ( & V_9 -> V_10 . V_19 ) ) {
case V_125 :
V_121 = V_126 ;
break;
case V_20 :
V_11 = F_7 ( V_9 ) ;
if ( ! V_11 )
goto V_12;
if ( V_11 -> V_6 == V_117 )
goto V_12;
V_115 = F_68 ( V_9 , V_11 -> V_6 ,
NULL ) ;
if ( ! V_115 )
goto V_12;
V_118 = F_27 ( V_115 ,
V_32 ) ;
if ( ! V_118 )
goto V_12;
V_121 = V_118 -> V_36 . V_37 ;
F_30 ( V_118 ) ;
break;
case V_127 :
default:
goto V_12;
}
V_116 = F_68 ( V_9 , V_117 , NULL ) ;
if ( ! V_116 )
goto V_12;
V_119 = F_27 ( V_116 , V_32 ) ;
if ( ! V_119 )
goto V_12;
if ( ( V_121 - V_119 -> V_36 . V_37 ) > V_128 )
V_120 = true ;
F_30 ( V_119 ) ;
V_12:
if ( V_117 )
F_3 ( V_117 ) ;
if ( V_11 )
F_5 ( V_11 ) ;
if ( V_4 )
F_5 ( V_4 ) ;
if ( V_116 )
F_29 ( V_116 ) ;
if ( V_115 )
F_29 ( V_115 ) ;
return V_120 ;
}
