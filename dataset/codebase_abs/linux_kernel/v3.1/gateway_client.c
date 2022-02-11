static void F_1 ( struct V_1 * V_1 )
{
if ( F_2 ( & V_1 -> V_2 ) )
F_3 ( V_1 , V_3 ) ;
}
static struct V_1 * F_4 ( struct V_4 * V_4 )
{
struct V_1 * V_1 ;
F_5 () ;
V_1 = F_6 ( V_4 -> V_5 ) ;
if ( ! V_1 )
goto V_6;
if ( ! F_7 ( & V_1 -> V_2 ) )
V_1 = NULL ;
V_6:
F_8 () ;
return V_1 ;
}
struct V_7 * F_9 ( struct V_4 * V_4 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 = NULL ;
V_1 = F_4 ( V_4 ) ;
if ( ! V_1 )
goto V_6;
F_5 () ;
V_7 = V_1 -> V_7 ;
if ( ! V_7 )
goto V_8;
if ( ! F_7 ( & V_7 -> V_2 ) )
V_7 = NULL ;
V_8:
F_8 () ;
V_6:
if ( V_1 )
F_1 ( V_1 ) ;
return V_7 ;
}
static void F_10 ( struct V_4 * V_4 , struct V_1 * V_9 )
{
struct V_1 * V_10 ;
F_11 ( & V_4 -> V_11 ) ;
if ( V_9 && ! F_7 ( & V_9 -> V_2 ) )
V_9 = NULL ;
V_10 = F_12 ( V_4 -> V_5 , 1 ) ;
F_13 ( V_4 -> V_5 , V_9 ) ;
if ( V_10 )
F_1 ( V_10 ) ;
F_14 ( & V_4 -> V_11 ) ;
}
void F_15 ( struct V_4 * V_4 )
{
F_16 ( & V_4 -> V_12 , 1 ) ;
}
static struct V_1 * F_17 ( struct V_4 * V_4 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_1 * V_1 , * V_5 = NULL ;
T_1 V_17 = 0 , V_18 = 0 ;
T_2 V_19 = 0 ;
int V_20 , V_21 ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_1 -> V_22 )
continue;
V_14 = F_19 ( V_1 -> V_7 ) ;
if ( ! V_14 )
continue;
if ( ! F_7 ( & V_1 -> V_2 ) )
goto V_23;
switch ( F_20 ( & V_4 -> V_24 ) ) {
case 1 :
F_21 ( V_1 -> V_7 -> V_25 ,
& V_20 , & V_21 ) ;
V_18 = ( V_14 -> V_26 * V_14 -> V_26 *
V_20 * 100 * 100 ) /
( V_27 *
V_27 * 64 ) ;
if ( ( V_18 > V_17 ) ||
( ( V_18 == V_17 ) &&
( V_14 -> V_26 > V_19 ) ) ) {
if ( V_5 )
F_1 ( V_5 ) ;
V_5 = V_1 ;
F_22 ( & V_5 -> V_2 ) ;
}
break;
default:
if ( V_14 -> V_26 > V_19 ) {
if ( V_5 )
F_1 ( V_5 ) ;
V_5 = V_1 ;
F_22 ( & V_5 -> V_2 ) ;
}
break;
}
if ( V_14 -> V_26 > V_19 )
V_19 = V_14 -> V_26 ;
if ( V_18 > V_17 )
V_17 = V_18 ;
F_1 ( V_1 ) ;
V_23:
F_23 ( V_14 ) ;
}
F_8 () ;
return V_5 ;
}
void F_24 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = NULL , * V_28 = NULL ;
struct V_13 * V_14 = NULL ;
char V_29 [ 18 ] = { '\0' } ;
if ( F_20 ( & V_4 -> V_30 ) != V_31 )
goto V_6;
if ( ! F_25 ( & V_4 -> V_12 ) )
goto V_6;
V_5 = F_4 ( V_4 ) ;
V_28 = F_17 ( V_4 ) ;
if ( V_5 == V_28 )
goto V_6;
if ( V_28 ) {
sprintf ( V_29 , L_1 , V_28 -> V_7 -> V_32 ) ;
V_14 = F_19 ( V_28 -> V_7 ) ;
if ( ! V_14 ) {
F_15 ( V_4 ) ;
goto V_6;
}
}
if ( ( V_5 ) && ( ! V_28 ) ) {
F_26 ( V_33 , V_4 ,
L_2 ) ;
F_27 ( V_4 , V_34 , V_35 , NULL ) ;
} else if ( ( ! V_5 ) && ( V_28 ) ) {
F_26 ( V_33 , V_4 ,
L_3 ,
V_28 -> V_7 -> V_32 ,
V_28 -> V_7 -> V_25 ,
V_14 -> V_26 ) ;
F_27 ( V_4 , V_34 , V_36 , V_29 ) ;
} else {
F_26 ( V_33 , V_4 ,
L_4
L_5 ,
V_28 -> V_7 -> V_32 ,
V_28 -> V_7 -> V_25 ,
V_14 -> V_26 ) ;
F_27 ( V_4 , V_34 , V_37 , V_29 ) ;
}
F_10 ( V_4 , V_28 ) ;
V_6:
if ( V_5 )
F_1 ( V_5 ) ;
if ( V_28 )
F_1 ( V_28 ) ;
if ( V_14 )
F_23 ( V_14 ) ;
}
void F_28 ( struct V_4 * V_4 , struct V_7 * V_7 )
{
struct V_7 * V_38 ;
struct V_13 * V_39 = NULL , * V_40 = NULL ;
T_2 V_41 , V_42 ;
V_38 = F_9 ( V_4 ) ;
if ( ! V_38 )
goto V_43;
V_39 = F_19 ( V_38 ) ;
if ( ! V_39 )
goto V_43;
if ( V_38 == V_7 )
goto V_6;
V_40 = F_19 ( V_7 ) ;
if ( ! V_40 )
goto V_6;
V_41 = V_39 -> V_26 ;
V_42 = V_40 -> V_26 ;
if ( V_42 < V_41 )
goto V_6;
if ( ( F_20 ( & V_4 -> V_24 ) > 3 ) &&
( V_42 - V_41 < F_20 ( & V_4 -> V_24 ) ) )
goto V_6;
F_26 ( V_33 , V_4 ,
L_6
L_7 ,
V_41 , V_42 ) ;
V_43:
F_15 ( V_4 ) ;
V_6:
if ( V_38 )
F_29 ( V_38 ) ;
if ( V_39 )
F_23 ( V_39 ) ;
if ( V_40 )
F_23 ( V_40 ) ;
return;
}
static void F_30 ( struct V_4 * V_4 ,
struct V_7 * V_7 , T_2 V_44 )
{
struct V_1 * V_1 ;
int V_20 , V_21 ;
V_1 = F_31 ( sizeof( * V_1 ) , V_45 ) ;
if ( ! V_1 )
return;
F_32 ( & V_1 -> V_46 ) ;
V_1 -> V_7 = V_7 ;
F_16 ( & V_1 -> V_2 , 1 ) ;
F_11 ( & V_4 -> V_11 ) ;
F_33 ( & V_1 -> V_46 , & V_4 -> V_47 ) ;
F_14 ( & V_4 -> V_11 ) ;
F_21 ( V_44 , & V_20 , & V_21 ) ;
F_26 ( V_33 , V_4 ,
L_8 ,
V_7 -> V_32 , V_44 ,
( V_20 > 2048 ? V_20 / 1024 : V_20 ) ,
( V_20 > 2048 ? L_9 : L_10 ) ,
( V_21 > 2048 ? V_21 / 1024 : V_21 ) ,
( V_21 > 2048 ? L_9 : L_10 ) ) ;
}
void F_34 ( struct V_4 * V_4 ,
struct V_7 * V_7 , T_2 V_44 )
{
struct V_15 * V_16 ;
struct V_1 * V_1 , * V_5 ;
V_5 = F_4 ( V_4 ) ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_1 -> V_7 != V_7 )
continue;
F_26 ( V_33 , V_4 ,
L_11
L_12 ,
V_7 -> V_32 , V_1 -> V_7 -> V_25 ,
V_44 ) ;
V_1 -> V_22 = 0 ;
if ( V_44 == V_48 ) {
V_1 -> V_22 = V_49 ;
F_26 ( V_33 , V_4 ,
L_13 ,
V_7 -> V_32 ) ;
if ( V_1 == V_5 )
goto V_43;
}
goto V_8;
}
if ( V_44 == V_48 )
goto V_8;
F_30 ( V_4 , V_7 , V_44 ) ;
goto V_8;
V_43:
F_15 ( V_4 ) ;
V_8:
F_8 () ;
if ( V_5 )
F_1 ( V_5 ) ;
}
void F_35 ( struct V_4 * V_4 , struct V_7 * V_7 )
{
F_34 ( V_4 , V_7 , 0 ) ;
}
void F_36 ( struct V_4 * V_4 )
{
struct V_1 * V_1 , * V_5 ;
struct V_15 * V_16 , * V_50 ;
unsigned long V_51 = 2 * V_52 * V_53 ;
int V_54 = 0 ;
V_5 = F_4 ( V_4 ) ;
F_11 ( & V_4 -> V_11 ) ;
F_37 (gw_node, node, node_tmp,
&bat_priv->gw_list, list) {
if ( ( ( ! V_1 -> V_22 ) ||
( F_38 ( V_49 , V_1 -> V_22 + V_51 ) ) ) &&
F_20 ( & V_4 -> V_55 ) == V_56 )
continue;
if ( V_5 == V_1 )
V_54 = 1 ;
F_39 ( & V_1 -> V_46 ) ;
F_1 ( V_1 ) ;
}
F_14 ( & V_4 -> V_11 ) ;
if ( V_54 )
F_15 ( V_4 ) ;
if ( V_5 )
F_1 ( V_5 ) ;
}
static int F_40 ( struct V_4 * V_4 , struct V_57 * V_58 ,
const struct V_1 * V_1 )
{
struct V_1 * V_5 ;
struct V_13 * V_14 ;
int V_20 , V_21 , V_59 = - 1 ;
F_21 ( V_1 -> V_7 -> V_25 , & V_20 , & V_21 ) ;
V_14 = F_19 ( V_1 -> V_7 ) ;
if ( ! V_14 )
goto V_6;
V_5 = F_4 ( V_4 ) ;
V_59 = F_41 ( V_58 , L_14 ,
( V_5 == V_1 ? L_15 : L_16 ) ,
V_1 -> V_7 -> V_32 ,
V_14 -> V_26 , V_14 -> V_60 ,
V_14 -> V_61 -> V_62 -> V_63 ,
V_1 -> V_7 -> V_25 ,
( V_20 > 2048 ? V_20 / 1024 : V_20 ) ,
( V_20 > 2048 ? L_9 : L_10 ) ,
( V_21 > 2048 ? V_21 / 1024 : V_21 ) ,
( V_21 > 2048 ? L_9 : L_10 ) ) ;
F_23 ( V_14 ) ;
if ( V_5 )
F_1 ( V_5 ) ;
V_6:
return V_59 ;
}
int F_42 ( struct V_57 * V_58 , void * V_64 )
{
struct V_65 * V_62 = (struct V_65 * ) V_58 -> V_66 ;
struct V_4 * V_4 = F_43 ( V_62 ) ;
struct V_67 * V_68 ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_69 = 0 , V_59 = 0 ;
V_68 = F_44 ( V_4 ) ;
if ( ! V_68 ) {
V_59 = F_41 ( V_58 , L_17
L_18 ,
V_62 -> V_63 ) ;
goto V_6;
}
if ( V_68 -> V_70 != V_71 ) {
V_59 = F_41 ( V_58 , L_19
L_20 ,
V_62 -> V_63 ) ;
goto V_6;
}
F_41 ( V_58 , L_21
L_22 ,
L_23 , L_24 , V_72 , L_25 ,
L_26 , V_73 , V_68 -> V_62 -> V_63 ,
V_68 -> V_62 -> V_74 , V_62 -> V_63 ) ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_1 -> V_22 )
continue;
if ( F_40 ( V_4 , V_58 , V_1 ) < 0 )
continue;
V_69 ++ ;
}
F_8 () ;
if ( V_69 == 0 )
F_41 ( V_58 , L_27 ) ;
V_6:
if ( V_68 )
F_45 ( V_68 ) ;
return V_59 ;
}
static bool F_46 ( struct V_75 * V_76 , int V_77 )
{
int V_59 = false ;
unsigned char * V_78 ;
int V_79 ;
if ( F_47 ( V_76 ) < 0 )
goto V_6;
V_79 = F_48 ( V_76 ) ;
if ( V_79 < V_77 + V_80 + 1 )
goto V_6;
V_78 = V_76 -> V_81 + V_77 + V_80 ;
V_79 -= V_77 + V_80 + 1 ;
while ( * V_78 != 255 && ! V_59 ) {
if ( * V_78 == 53 ) {
if ( V_79 < 2 )
goto V_6;
V_78 += 2 ;
if ( * V_78 == V_82 )
V_59 = true ;
break;
} else if ( * V_78 == 0 ) {
if ( V_79 < 1 )
goto V_6;
V_79 -- ;
V_78 ++ ;
} else {
if ( V_79 < 1 )
goto V_6;
V_79 -- ;
V_78 ++ ;
if ( V_79 < * V_78 )
goto V_6;
V_79 -= * V_78 ;
V_78 += ( * V_78 ) ;
}
}
V_6:
return V_59 ;
}
int F_49 ( struct V_4 * V_4 , struct V_75 * V_76 ,
struct V_7 * V_83 )
{
struct V_84 * V_84 ;
struct V_85 * V_85 ;
struct V_86 * V_86 ;
struct V_87 * V_87 ;
struct V_1 * V_5 ;
struct V_13 * V_88 = NULL , * V_89 = NULL ;
unsigned int V_77 = 0 ;
int V_59 = 1 ;
if ( F_20 ( & V_4 -> V_30 ) == V_90 )
return 0 ;
if ( ! F_50 ( V_76 , V_77 + V_91 ) )
return 0 ;
V_84 = (struct V_84 * ) V_76 -> V_81 ;
V_77 += V_91 ;
if ( F_51 ( V_84 -> V_92 ) == V_93 ) {
if ( ! F_50 ( V_76 , V_77 + V_94 ) )
return 0 ;
V_84 = (struct V_84 * ) ( V_76 -> V_81 + V_94 ) ;
V_77 += V_94 ;
}
switch ( F_51 ( V_84 -> V_92 ) ) {
case V_95 :
if ( ! F_50 ( V_76 , V_77 + sizeof( * V_85 ) ) )
return 0 ;
V_85 = (struct V_85 * ) ( V_76 -> V_81 + V_77 ) ;
V_77 += V_85 -> V_96 * 4 ;
if ( V_85 -> V_97 != V_98 )
return 0 ;
break;
case V_99 :
if ( ! F_50 ( V_76 , V_77 + sizeof( * V_86 ) ) )
return 0 ;
V_86 = (struct V_86 * ) ( V_76 -> V_81 + V_77 ) ;
V_77 += sizeof( * V_86 ) ;
if ( V_86 -> V_100 != V_98 )
return 0 ;
break;
default:
return 0 ;
}
if ( ! F_50 ( V_76 , V_77 + sizeof( * V_87 ) ) )
return 0 ;
V_87 = (struct V_87 * ) ( V_76 -> V_81 + V_77 ) ;
V_77 += sizeof( * V_87 ) ;
if ( ( F_51 ( V_84 -> V_92 ) == V_95 ) &&
( F_51 ( V_87 -> V_101 ) != 67 ) )
return 0 ;
if ( ( F_51 ( V_84 -> V_92 ) == V_99 ) &&
( F_51 ( V_87 -> V_101 ) != 547 ) )
return 0 ;
if ( F_20 ( & V_4 -> V_30 ) == V_102 )
return - 1 ;
V_5 = F_4 ( V_4 ) ;
if ( ! V_5 )
return 0 ;
if ( V_83 && V_5 -> V_7 != V_83 ) {
if ( F_46 ( V_76 , V_77 ) ) {
V_88 = F_52 ( V_4 , V_5 -> V_7 ,
NULL ) ;
V_89 = F_52 ( V_4 , V_83 , NULL ) ;
if ( ! V_88 || ! V_89 )
goto V_103;
if ( V_88 -> V_26 - V_89 -> V_26 <
V_104 )
V_59 = - 1 ;
}
}
V_103:
if ( V_89 )
F_23 ( V_89 ) ;
if ( V_88 )
F_23 ( V_88 ) ;
if ( V_5 )
F_1 ( V_5 ) ;
return V_59 ;
}
