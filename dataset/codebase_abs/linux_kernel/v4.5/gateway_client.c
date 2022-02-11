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
T_1 V_21 = 0 ;
T_1 V_22 = 0 ;
T_2 V_23 = 0 ;
T_2 V_24 ;
struct V_11 * V_4 ;
F_6 () ;
F_19 (gw_node, &bat_priv->gw.list, list) {
V_4 = V_2 -> V_4 ;
V_18 = F_20 ( V_4 , V_25 ) ;
if ( ! V_18 )
continue;
V_20 = F_21 ( V_18 ,
V_25 ) ;
if ( ! V_20 )
goto V_26;
if ( ! F_8 ( & V_2 -> V_3 ) )
goto V_26;
V_24 = V_20 -> V_27 . V_24 ;
switch ( F_22 ( & V_7 -> V_28 ) ) {
case 1 :
V_22 = V_24 * V_24 ;
V_22 *= V_2 -> V_29 ;
V_22 *= 100 * 100 ;
V_22 >>= 18 ;
if ( ( V_22 > V_21 ) ||
( ( V_22 == V_21 ) &&
( V_24 > V_23 ) ) ) {
if ( V_9 )
F_1 ( V_9 ) ;
V_9 = V_2 ;
F_23 ( & V_9 -> V_3 ) ;
}
break;
default:
if ( V_24 > V_23 ) {
if ( V_9 )
F_1 ( V_9 ) ;
V_9 = V_2 ;
F_23 ( & V_9 -> V_3 ) ;
}
break;
}
if ( V_24 > V_23 )
V_23 = V_24 ;
if ( V_22 > V_21 )
V_21 = V_22 ;
F_1 ( V_2 ) ;
V_26:
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
if ( F_22 ( & V_7 -> V_30 ) != V_31 )
return;
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
return;
F_11 ( V_7 , NULL ) ;
F_27 ( V_7 , V_32 , V_33 , NULL ) ;
F_1 ( V_9 ) ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = NULL ;
struct V_1 * V_34 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_19 * V_20 = NULL ;
char V_35 [ 18 ] = { '\0' } ;
if ( F_22 ( & V_7 -> V_30 ) != V_31 )
goto V_10;
V_9 = F_5 ( V_7 ) ;
if ( ! F_29 ( & V_7 -> V_8 . V_16 ) && V_9 )
goto V_10;
V_34 = F_18 ( V_7 ) ;
if ( V_9 == V_34 )
goto V_10;
if ( V_34 ) {
sprintf ( V_35 , L_1 , V_34 -> V_4 -> V_36 ) ;
V_18 = F_20 ( V_34 -> V_4 ,
V_25 ) ;
if ( ! V_18 ) {
F_16 ( V_7 ) ;
goto V_10;
}
V_20 = F_21 ( V_18 ,
V_25 ) ;
if ( ! V_20 ) {
F_16 ( V_7 ) ;
goto V_10;
}
}
if ( ( V_9 ) && ( ! V_34 ) ) {
F_30 ( V_37 , V_7 ,
L_2 ) ;
F_27 ( V_7 , V_32 , V_33 ,
NULL ) ;
} else if ( ( ! V_9 ) && ( V_34 ) ) {
F_30 ( V_37 , V_7 ,
L_3 ,
V_34 -> V_4 -> V_36 ,
V_34 -> V_29 / 10 ,
V_34 -> V_29 % 10 ,
V_34 -> V_38 / 10 ,
V_34 -> V_38 % 10 ,
V_20 -> V_27 . V_24 ) ;
F_27 ( V_7 , V_32 , V_39 ,
V_35 ) ;
} else {
F_30 ( V_37 , V_7 ,
L_4 ,
V_34 -> V_4 -> V_36 ,
V_34 -> V_29 / 10 ,
V_34 -> V_29 % 10 ,
V_34 -> V_38 / 10 ,
V_34 -> V_38 % 10 ,
V_20 -> V_27 . V_24 ) ;
F_27 ( V_7 , V_32 , V_40 ,
V_35 ) ;
}
F_11 ( V_7 , V_34 ) ;
V_10:
if ( V_9 )
F_1 ( V_9 ) ;
if ( V_34 )
F_1 ( V_34 ) ;
if ( V_18 )
F_24 ( V_18 ) ;
if ( V_20 )
F_25 ( V_20 ) ;
}
void F_31 ( struct V_6 * V_7 ,
struct V_11 * V_4 )
{
struct V_19 * V_41 = NULL ;
struct V_19 * V_42 = NULL ;
struct V_11 * V_43 ;
struct V_17 * V_44 = NULL ;
struct V_17 * V_45 = NULL ;
T_2 V_46 , V_47 ;
V_43 = F_10 ( V_7 ) ;
if ( ! V_43 )
goto V_16;
V_44 = F_20 ( V_43 , V_25 ) ;
if ( ! V_44 )
goto V_16;
V_42 = F_21 ( V_44 ,
V_25 ) ;
if ( ! V_42 )
goto V_16;
if ( V_43 == V_4 )
goto V_10;
V_45 = F_20 ( V_4 , V_25 ) ;
if ( ! V_45 )
goto V_10;
V_41 = F_21 ( V_45 ,
V_25 ) ;
if ( ! V_41 )
goto V_10;
V_46 = V_42 -> V_27 . V_24 ;
V_47 = V_41 -> V_27 . V_24 ;
if ( V_47 < V_46 )
goto V_10;
if ( ( F_22 ( & V_7 -> V_28 ) > 3 ) &&
( V_47 - V_46 < F_22 ( & V_7 -> V_28 ) ) )
goto V_10;
F_30 ( V_37 , V_7 ,
L_5 ,
V_46 , V_47 ) ;
V_16:
F_16 ( V_7 ) ;
V_10:
if ( V_43 )
F_3 ( V_43 ) ;
if ( V_44 )
F_24 ( V_44 ) ;
if ( V_45 )
F_24 ( V_45 ) ;
if ( V_42 )
F_25 ( V_42 ) ;
if ( V_41 )
F_25 ( V_41 ) ;
}
static void F_32 ( struct V_6 * V_7 ,
struct V_11 * V_4 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 ;
if ( V_49 -> V_29 == 0 )
return;
if ( ! F_8 ( & V_4 -> V_3 ) )
return;
V_2 = F_33 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 ) {
F_3 ( V_4 ) ;
return;
}
F_34 ( & V_2 -> V_51 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_29 = F_35 ( V_49 -> V_29 ) ;
V_2 -> V_38 = F_35 ( V_49 -> V_38 ) ;
F_17 ( & V_2 -> V_3 , 1 ) ;
F_12 ( & V_7 -> V_8 . V_15 ) ;
F_36 ( & V_2 -> V_51 , & V_7 -> V_8 . V_51 ) ;
F_15 ( & V_7 -> V_8 . V_15 ) ;
F_30 ( V_37 , V_7 ,
L_6 ,
V_4 -> V_36 ,
F_35 ( V_49 -> V_29 ) / 10 ,
F_35 ( V_49 -> V_29 ) % 10 ,
F_35 ( V_49 -> V_38 ) / 10 ,
F_35 ( V_49 -> V_38 ) % 10 ) ;
}
static struct V_1 *
F_37 ( struct V_6 * V_7 ,
struct V_11 * V_4 )
{
struct V_1 * V_52 , * V_2 = NULL ;
F_6 () ;
F_19 (gw_node_tmp, &bat_priv->gw.list, list) {
if ( V_52 -> V_4 != V_4 )
continue;
if ( ! F_8 ( & V_52 -> V_3 ) )
continue;
V_2 = V_52 ;
break;
}
F_9 () ;
return V_2 ;
}
void F_38 ( struct V_6 * V_7 ,
struct V_11 * V_4 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 , * V_9 = NULL ;
V_2 = F_37 ( V_7 , V_4 ) ;
if ( ! V_2 ) {
F_32 ( V_7 , V_4 , V_49 ) ;
goto V_10;
}
if ( ( V_2 -> V_29 == F_35 ( V_49 -> V_29 ) ) &&
( V_2 -> V_38 == F_35 ( V_49 -> V_38 ) ) )
goto V_10;
F_30 ( V_37 , V_7 ,
L_7 ,
V_4 -> V_36 ,
V_2 -> V_29 / 10 ,
V_2 -> V_29 % 10 ,
V_2 -> V_38 / 10 ,
V_2 -> V_38 % 10 ,
F_35 ( V_49 -> V_29 ) / 10 ,
F_35 ( V_49 -> V_29 ) % 10 ,
F_35 ( V_49 -> V_38 ) / 10 ,
F_35 ( V_49 -> V_38 ) % 10 ) ;
V_2 -> V_29 = F_35 ( V_49 -> V_29 ) ;
V_2 -> V_38 = F_35 ( V_49 -> V_38 ) ;
if ( F_35 ( V_49 -> V_29 ) == 0 ) {
F_30 ( V_37 , V_7 ,
L_8 ,
V_4 -> V_36 ) ;
F_12 ( & V_7 -> V_8 . V_15 ) ;
if ( ! F_39 ( & V_2 -> V_51 ) ) {
F_40 ( & V_2 -> V_51 ) ;
F_1 ( V_2 ) ;
}
F_15 ( & V_7 -> V_8 . V_15 ) ;
V_9 = F_5 ( V_7 ) ;
if ( V_2 == V_9 )
F_16 ( V_7 ) ;
if ( V_9 )
F_1 ( V_9 ) ;
}
V_10:
if ( V_2 )
F_1 ( V_2 ) ;
}
void F_41 ( struct V_6 * V_7 ,
struct V_11 * V_4 )
{
struct V_48 V_49 ;
V_49 . V_29 = 0 ;
V_49 . V_38 = 0 ;
F_38 ( V_7 , V_4 , & V_49 ) ;
}
void F_42 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 ;
F_12 ( & V_7 -> V_8 . V_15 ) ;
F_43 (gw_node, node_tmp,
&bat_priv->gw.list, list) {
F_40 ( & V_2 -> V_51 ) ;
F_1 ( V_2 ) ;
}
F_15 ( & V_7 -> V_8 . V_15 ) ;
}
static int F_44 ( struct V_6 * V_7 ,
struct V_55 * V_56 ,
const struct V_1 * V_2 )
{
struct V_1 * V_9 ;
struct V_17 * V_18 ;
struct V_19 * V_20 = NULL ;
int V_57 = - 1 ;
V_18 = F_20 ( V_2 -> V_4 , V_25 ) ;
if ( ! V_18 )
goto V_10;
V_20 = F_21 ( V_18 , V_25 ) ;
if ( ! V_20 )
goto V_10;
V_9 = F_5 ( V_7 ) ;
F_45 ( V_56 , L_9 ,
( V_9 == V_2 ? L_10 : L_11 ) ,
V_2 -> V_4 -> V_36 ,
V_20 -> V_27 . V_24 , V_18 -> V_58 ,
V_18 -> V_59 -> V_60 -> V_61 ,
V_2 -> V_29 / 10 ,
V_2 -> V_29 % 10 ,
V_2 -> V_38 / 10 ,
V_2 -> V_38 % 10 ) ;
V_57 = F_46 ( V_56 ) ? - 1 : 0 ;
if ( V_9 )
F_1 ( V_9 ) ;
V_10:
if ( V_20 )
F_25 ( V_20 ) ;
if ( V_18 )
F_24 ( V_18 ) ;
return V_57 ;
}
int F_47 ( struct V_55 * V_56 , void * V_62 )
{
struct V_63 * V_60 = (struct V_63 * ) V_56 -> V_64 ;
struct V_6 * V_7 = F_48 ( V_60 ) ;
struct V_65 * V_66 ;
struct V_1 * V_2 ;
int V_67 = 0 ;
V_66 = F_49 ( V_56 ) ;
if ( ! V_66 )
goto V_10;
F_45 ( V_56 ,
L_12 ,
L_13 , L_14 , V_68 , L_15 , L_16 ,
V_69 , V_66 -> V_60 -> V_61 ,
V_66 -> V_60 -> V_70 , V_60 -> V_61 ) ;
F_6 () ;
F_19 (gw_node, &bat_priv->gw.list, list) {
if ( F_44 ( V_7 , V_56 , V_2 ) < 0 )
continue;
V_67 ++ ;
}
F_9 () ;
if ( V_67 == 0 )
F_50 ( V_56 , L_17 ) ;
V_10:
if ( V_66 )
F_51 ( V_66 ) ;
return 0 ;
}
enum V_71
F_52 ( struct V_72 * V_73 , unsigned int * V_74 ,
T_2 * V_75 )
{
enum V_71 V_57 = V_76 ;
struct V_77 * V_77 ;
struct V_78 * V_78 ;
struct V_79 * V_79 ;
struct V_80 * V_80 ;
struct V_81 * V_82 ;
int V_83 ;
T_3 V_84 ;
T_2 * V_85 ;
if ( ! F_53 ( V_73 , * V_74 + V_86 ) )
return V_76 ;
V_77 = F_54 ( V_73 ) ;
V_84 = V_77 -> V_87 ;
* V_74 += V_86 ;
if ( V_84 == F_55 ( V_88 ) ) {
if ( ! F_53 ( V_73 , * V_74 + V_89 ) )
return V_76 ;
V_82 = F_56 ( V_73 ) ;
V_84 = V_82 -> V_90 ;
* V_74 += V_89 ;
}
switch ( V_84 ) {
case F_55 ( V_91 ) :
if ( ! F_53 ( V_73 , * V_74 + sizeof( * V_78 ) ) )
return V_76 ;
V_78 = (struct V_78 * ) ( V_73 -> V_92 + * V_74 ) ;
* V_74 += V_78 -> V_93 * 4 ;
if ( V_78 -> V_94 != V_95 )
return V_76 ;
break;
case F_55 ( V_96 ) :
if ( ! F_53 ( V_73 , * V_74 + sizeof( * V_79 ) ) )
return V_76 ;
V_79 = (struct V_79 * ) ( V_73 -> V_92 + * V_74 ) ;
* V_74 += sizeof( * V_79 ) ;
if ( V_79 -> V_97 != V_95 )
return V_76 ;
break;
default:
return V_76 ;
}
if ( ! F_53 ( V_73 , * V_74 + sizeof( * V_80 ) ) )
return V_76 ;
V_80 = (struct V_80 * ) ( V_73 -> V_92 + * V_74 ) ;
* V_74 += sizeof( * V_80 ) ;
switch ( V_84 ) {
case F_55 ( V_91 ) :
if ( V_80 -> V_98 == F_55 ( 67 ) )
V_57 = V_99 ;
else if ( V_80 -> V_100 == F_55 ( 67 ) )
V_57 = V_101 ;
break;
case F_55 ( V_96 ) :
if ( V_80 -> V_98 == F_55 ( 547 ) )
V_57 = V_99 ;
else if ( V_80 -> V_100 == F_55 ( 547 ) )
V_57 = V_101 ;
break;
}
V_83 = * V_74 + V_102 ;
if ( V_57 == V_101 &&
F_53 ( V_73 , V_83 + V_103 ) ) {
V_85 = V_73 -> V_92 + * V_74 + V_104 ;
if ( * V_85 != V_105 )
return V_76 ;
V_85 = V_73 -> V_92 + * V_74 + V_106 ;
if ( * V_85 != V_103 )
return V_76 ;
F_57 ( V_75 , V_73 -> V_92 + V_83 ) ;
}
return V_57 ;
}
bool F_58 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
struct V_17 * V_107 = NULL ;
struct V_17 * V_108 = NULL ;
struct V_11 * V_109 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_9 = NULL ;
struct V_19 * V_110 , * V_111 ;
struct V_77 * V_77 = (struct V_77 * ) V_73 -> V_92 ;
bool V_112 = false ;
T_2 V_113 ;
unsigned short V_114 ;
V_114 = F_59 ( V_73 , 0 ) ;
V_109 = F_60 ( V_7 , V_77 -> V_115 ,
V_77 -> V_116 , V_114 ) ;
if ( ! V_109 )
goto V_10;
V_2 = F_37 ( V_7 , V_109 ) ;
if ( ! V_2 )
goto V_10;
switch ( F_22 ( & V_7 -> V_30 ) ) {
case V_117 :
V_113 = V_68 ;
break;
case V_31 :
V_9 = F_5 ( V_7 ) ;
if ( ! V_9 )
goto V_10;
if ( V_9 -> V_4 == V_109 )
goto V_10;
V_107 = F_61 ( V_7 , V_9 -> V_4 ,
NULL ) ;
if ( ! V_107 )
goto V_10;
V_110 = F_21 ( V_107 ,
V_25 ) ;
if ( ! V_110 )
goto V_10;
V_113 = V_110 -> V_27 . V_24 ;
F_25 ( V_110 ) ;
break;
case V_118 :
default:
goto V_10;
}
V_108 = F_61 ( V_7 , V_109 , NULL ) ;
if ( ! V_108 )
goto V_10;
V_111 = F_21 ( V_108 , V_25 ) ;
if ( ! V_111 )
goto V_10;
if ( ( V_113 - V_111 -> V_27 . V_24 ) > V_119 )
V_112 = true ;
F_25 ( V_111 ) ;
V_10:
if ( V_109 )
F_3 ( V_109 ) ;
if ( V_9 )
F_1 ( V_9 ) ;
if ( V_2 )
F_1 ( V_2 ) ;
if ( V_108 )
F_24 ( V_108 ) ;
if ( V_107 )
F_24 ( V_107 ) ;
return V_112 ;
}
