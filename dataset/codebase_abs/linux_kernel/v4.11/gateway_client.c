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
F_37 ( & V_4 -> V_45 , & V_9 -> V_10 . V_46 ) ;
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
struct V_3 * V_47 , * V_4 = NULL ;
F_8 () ;
F_39 (gw_node_tmp, &bat_priv->gw.gateway_list,
list) {
if ( V_47 -> V_6 != V_6 )
continue;
if ( ! F_10 ( & V_47 -> V_5 ) )
continue;
V_4 = V_47 ;
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
struct V_48 * V_49 ;
F_14 ( & V_9 -> V_10 . V_17 ) ;
F_45 (gw_node, node_tmp,
&bat_priv->gw.gateway_list, list) {
F_42 ( & V_4 -> V_45 ) ;
F_5 ( V_4 ) ;
}
F_18 ( & V_9 -> V_10 . V_17 ) ;
}
int F_46 ( struct V_50 * V_51 , void * V_52 )
{
struct V_53 * V_54 = (struct V_53 * ) V_51 -> V_55 ;
struct V_8 * V_9 = F_47 ( V_54 ) ;
struct V_56 * V_57 ;
V_57 = F_48 ( V_51 ) ;
if ( ! V_57 )
return 0 ;
F_49 ( V_51 , L_8 ,
V_58 , V_57 -> V_54 -> V_59 ,
V_57 -> V_54 -> V_60 , V_54 -> V_59 ,
V_9 -> V_29 -> V_59 ) ;
F_50 ( V_57 ) ;
if ( ! V_9 -> V_29 -> V_10 . V_61 ) {
F_51 ( V_51 ,
L_9 ) ;
return 0 ;
}
V_9 -> V_29 -> V_10 . V_61 ( V_9 , V_51 ) ;
return 0 ;
}
int F_52 ( struct V_62 * V_63 , struct V_64 * V_65 )
{
struct V_56 * V_57 = NULL ;
struct V_66 * V_66 = F_53 ( V_65 -> V_67 -> V_68 ) ;
struct V_53 * V_69 ;
struct V_8 * V_9 ;
int V_70 ;
int V_71 ;
V_70 = F_54 ( V_65 -> V_72 ,
V_73 ) ;
if ( ! V_70 )
return - V_74 ;
V_69 = F_55 ( V_66 , V_70 ) ;
if ( ! V_69 || ! F_56 ( V_69 ) ) {
V_71 = - V_75 ;
goto V_12;
}
V_9 = F_47 ( V_69 ) ;
V_57 = F_57 ( V_9 ) ;
if ( ! V_57 || V_57 -> V_76 != V_77 ) {
V_71 = - V_78 ;
goto V_12;
}
if ( ! V_9 -> V_29 -> V_10 . V_79 ) {
V_71 = - V_80 ;
goto V_12;
}
V_9 -> V_29 -> V_10 . V_79 ( V_63 , V_65 , V_9 ) ;
V_71 = V_63 -> V_81 ;
V_12:
if ( V_57 )
F_50 ( V_57 ) ;
if ( V_69 )
F_58 ( V_69 ) ;
return V_71 ;
}
enum V_82
F_59 ( struct V_62 * V_67 , unsigned int * V_83 ,
T_1 * V_84 )
{
enum V_82 V_71 = V_85 ;
struct V_86 * V_86 ;
struct V_87 * V_87 ;
struct V_88 * V_88 ;
struct V_89 * V_89 ;
struct V_90 * V_91 ;
int V_92 ;
T_2 V_93 ;
T_1 * V_94 ;
if ( ! F_60 ( V_67 , * V_83 + V_95 ) )
return V_85 ;
V_86 = F_61 ( V_67 ) ;
V_93 = V_86 -> V_96 ;
* V_83 += V_95 ;
if ( V_93 == F_62 ( V_97 ) ) {
if ( ! F_60 ( V_67 , * V_83 + V_98 ) )
return V_85 ;
V_91 = F_63 ( V_67 ) ;
V_93 = V_91 -> V_99 ;
* V_83 += V_98 ;
}
switch ( V_93 ) {
case F_62 ( V_100 ) :
if ( ! F_60 ( V_67 , * V_83 + sizeof( * V_87 ) ) )
return V_85 ;
V_87 = (struct V_87 * ) ( V_67 -> V_101 + * V_83 ) ;
* V_83 += V_87 -> V_102 * 4 ;
if ( V_87 -> V_103 != V_104 )
return V_85 ;
break;
case F_62 ( V_105 ) :
if ( ! F_60 ( V_67 , * V_83 + sizeof( * V_88 ) ) )
return V_85 ;
V_88 = (struct V_88 * ) ( V_67 -> V_101 + * V_83 ) ;
* V_83 += sizeof( * V_88 ) ;
if ( V_88 -> V_106 != V_104 )
return V_85 ;
break;
default:
return V_85 ;
}
if ( ! F_60 ( V_67 , * V_83 + sizeof( * V_89 ) ) )
return V_85 ;
V_89 = (struct V_89 * ) ( V_67 -> V_101 + * V_83 ) ;
* V_83 += sizeof( * V_89 ) ;
switch ( V_93 ) {
case F_62 ( V_100 ) :
if ( V_89 -> V_107 == F_62 ( 67 ) )
V_71 = V_108 ;
else if ( V_89 -> V_109 == F_62 ( 67 ) )
V_71 = V_110 ;
break;
case F_62 ( V_105 ) :
if ( V_89 -> V_107 == F_62 ( 547 ) )
V_71 = V_108 ;
else if ( V_89 -> V_109 == F_62 ( 547 ) )
V_71 = V_110 ;
break;
}
V_92 = * V_83 + V_111 ;
if ( V_71 == V_110 &&
F_60 ( V_67 , V_92 + V_112 ) ) {
V_94 = V_67 -> V_101 + * V_83 + V_113 ;
if ( * V_94 != V_114 )
return V_85 ;
V_94 = V_67 -> V_101 + * V_83 + V_115 ;
if ( * V_94 != V_112 )
return V_85 ;
F_64 ( V_84 , V_67 -> V_101 + V_92 ) ;
}
return V_71 ;
}
bool F_65 ( struct V_8 * V_9 ,
struct V_62 * V_67 )
{
struct V_24 * V_116 = NULL ;
struct V_24 * V_117 = NULL ;
struct V_13 * V_118 ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_11 = NULL ;
struct V_26 * V_119 , * V_120 ;
struct V_86 * V_86 = (struct V_86 * ) V_67 -> V_101 ;
bool V_121 = false ;
T_1 V_122 ;
unsigned short V_123 ;
V_123 = F_66 ( V_67 , 0 ) ;
V_118 = F_67 ( V_9 , V_86 -> V_124 ,
V_86 -> V_125 , V_123 ) ;
if ( ! V_118 )
goto V_12;
V_4 = F_38 ( V_9 , V_118 ) ;
if ( ! V_4 )
goto V_12;
switch ( F_22 ( & V_9 -> V_10 . V_19 ) ) {
case V_126 :
V_122 = V_127 ;
break;
case V_20 :
V_11 = F_7 ( V_9 ) ;
if ( ! V_11 )
goto V_12;
if ( V_11 -> V_6 == V_118 )
goto V_12;
V_116 = F_68 ( V_9 , V_11 -> V_6 ,
NULL ) ;
if ( ! V_116 )
goto V_12;
V_119 = F_27 ( V_116 ,
V_32 ) ;
if ( ! V_119 )
goto V_12;
V_122 = V_119 -> V_36 . V_37 ;
F_30 ( V_119 ) ;
break;
case V_128 :
default:
goto V_12;
}
V_117 = F_68 ( V_9 , V_118 , NULL ) ;
if ( ! V_117 )
goto V_12;
V_120 = F_27 ( V_117 , V_32 ) ;
if ( ! V_120 )
goto V_12;
if ( ( V_122 - V_120 -> V_36 . V_37 ) > V_129 )
V_121 = true ;
F_30 ( V_120 ) ;
V_12:
if ( V_118 )
F_3 ( V_118 ) ;
if ( V_11 )
F_5 ( V_11 ) ;
if ( V_4 )
F_5 ( V_4 ) ;
if ( V_117 )
F_29 ( V_117 ) ;
if ( V_116 )
F_29 ( V_116 ) ;
return V_121 ;
}
