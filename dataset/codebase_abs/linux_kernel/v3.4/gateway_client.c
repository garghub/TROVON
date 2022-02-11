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
V_28 -> V_7 -> V_32 , V_28 -> V_7 -> V_25 ,
V_14 -> V_26 ) ;
F_27 ( V_4 , V_34 , V_36 , V_29 ) ;
} else {
F_26 ( V_33 , V_4 ,
L_4 ,
V_28 -> V_7 -> V_32 , V_28 -> V_7 -> V_25 ,
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
L_5 ,
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
L_6 ,
V_7 -> V_32 , V_44 ,
( V_20 > 2048 ? V_20 / 1024 : V_20 ) ,
( V_20 > 2048 ? L_7 : L_8 ) ,
( V_21 > 2048 ? V_21 / 1024 : V_21 ) ,
( V_21 > 2048 ? L_7 : L_8 ) ) ;
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
L_9 ,
V_7 -> V_32 , V_1 -> V_7 -> V_25 ,
V_44 ) ;
V_1 -> V_22 = 0 ;
if ( V_44 == V_48 ) {
V_1 -> V_22 = V_49 ;
F_26 ( V_33 , V_4 ,
L_10 ,
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
unsigned long V_51 = F_37 ( 2 * V_52 ) ;
int V_53 = 0 ;
V_5 = F_4 ( V_4 ) ;
F_11 ( & V_4 -> V_11 ) ;
F_38 (gw_node, node, node_tmp,
&bat_priv->gw_list, list) {
if ( ( ( ! V_1 -> V_22 ) ||
( F_39 ( V_49 , V_1 -> V_22 + V_51 ) ) ) &&
F_20 ( & V_4 -> V_54 ) == V_55 )
continue;
if ( V_5 == V_1 )
V_53 = 1 ;
F_40 ( & V_1 -> V_46 ) ;
F_1 ( V_1 ) ;
}
F_14 ( & V_4 -> V_11 ) ;
if ( V_53 )
F_15 ( V_4 ) ;
if ( V_5 )
F_1 ( V_5 ) ;
}
static int F_41 ( struct V_4 * V_4 , struct V_56 * V_57 ,
const struct V_1 * V_1 )
{
struct V_1 * V_5 ;
struct V_13 * V_14 ;
int V_20 , V_21 , V_58 = - 1 ;
F_21 ( V_1 -> V_7 -> V_25 , & V_20 , & V_21 ) ;
V_14 = F_19 ( V_1 -> V_7 ) ;
if ( ! V_14 )
goto V_6;
V_5 = F_4 ( V_4 ) ;
V_58 = F_42 ( V_57 , L_11 ,
( V_5 == V_1 ? L_12 : L_13 ) ,
V_1 -> V_7 -> V_32 ,
V_14 -> V_26 , V_14 -> V_59 ,
V_14 -> V_60 -> V_61 -> V_62 ,
V_1 -> V_7 -> V_25 ,
( V_20 > 2048 ? V_20 / 1024 : V_20 ) ,
( V_20 > 2048 ? L_7 : L_8 ) ,
( V_21 > 2048 ? V_21 / 1024 : V_21 ) ,
( V_21 > 2048 ? L_7 : L_8 ) ) ;
F_23 ( V_14 ) ;
if ( V_5 )
F_1 ( V_5 ) ;
V_6:
return V_58 ;
}
int F_43 ( struct V_56 * V_57 , void * V_63 )
{
struct V_64 * V_61 = (struct V_64 * ) V_57 -> V_65 ;
struct V_4 * V_4 = F_44 ( V_61 ) ;
struct V_66 * V_67 ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_68 = 0 , V_58 = 0 ;
V_67 = F_45 ( V_4 ) ;
if ( ! V_67 ) {
V_58 = F_42 ( V_57 ,
L_14 ,
V_61 -> V_62 ) ;
goto V_6;
}
if ( V_67 -> V_69 != V_70 ) {
V_58 = F_42 ( V_57 ,
L_15 ,
V_61 -> V_62 ) ;
goto V_6;
}
F_42 ( V_57 ,
L_16 ,
L_17 , L_18 , V_71 , L_19 , L_20 ,
V_72 , V_67 -> V_61 -> V_62 ,
V_67 -> V_61 -> V_73 , V_61 -> V_62 ) ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_1 -> V_22 )
continue;
if ( F_41 ( V_4 , V_57 , V_1 ) < 0 )
continue;
V_68 ++ ;
}
F_8 () ;
if ( V_68 == 0 )
F_42 ( V_57 , L_21 ) ;
V_6:
if ( V_67 )
F_46 ( V_67 ) ;
return V_58 ;
}
static bool F_47 ( struct V_74 * V_75 , int V_76 )
{
int V_58 = false ;
unsigned char * V_77 ;
int V_78 ;
if ( F_48 ( V_75 ) < 0 )
goto V_6;
V_78 = F_49 ( V_75 ) ;
if ( V_78 < V_76 + V_79 + 1 )
goto V_6;
V_77 = V_75 -> V_80 + V_76 + V_79 ;
V_78 -= V_76 + V_79 + 1 ;
while ( * V_77 != 255 && ! V_58 ) {
if ( * V_77 == 53 ) {
if ( V_78 < 2 )
goto V_6;
V_77 += 2 ;
if ( * V_77 == V_81 )
V_58 = true ;
break;
} else if ( * V_77 == 0 ) {
if ( V_78 < 1 )
goto V_6;
V_78 -- ;
V_77 ++ ;
} else {
if ( V_78 < 1 )
goto V_6;
V_78 -- ;
V_77 ++ ;
if ( V_78 < * V_77 )
goto V_6;
V_78 -= * V_77 ;
V_77 += ( * V_77 ) ;
}
}
V_6:
return V_58 ;
}
bool F_50 ( struct V_74 * V_75 , unsigned int * V_76 )
{
struct V_82 * V_82 ;
struct V_83 * V_83 ;
struct V_84 * V_84 ;
struct V_85 * V_85 ;
if ( ! F_51 ( V_75 , * V_76 + V_86 ) )
return false ;
V_82 = (struct V_82 * ) V_75 -> V_80 ;
* V_76 += V_86 ;
if ( F_52 ( V_82 -> V_87 ) == V_88 ) {
if ( ! F_51 ( V_75 , * V_76 + V_89 ) )
return false ;
V_82 = (struct V_82 * ) ( V_75 -> V_80 + V_89 ) ;
* V_76 += V_89 ;
}
switch ( F_52 ( V_82 -> V_87 ) ) {
case V_90 :
if ( ! F_51 ( V_75 , * V_76 + sizeof( * V_83 ) ) )
return false ;
V_83 = (struct V_83 * ) ( V_75 -> V_80 + * V_76 ) ;
* V_76 += V_83 -> V_91 * 4 ;
if ( V_83 -> V_92 != V_93 )
return false ;
break;
case V_94 :
if ( ! F_51 ( V_75 , * V_76 + sizeof( * V_84 ) ) )
return false ;
V_84 = (struct V_84 * ) ( V_75 -> V_80 + * V_76 ) ;
* V_76 += sizeof( * V_84 ) ;
if ( V_84 -> V_95 != V_93 )
return false ;
break;
default:
return false ;
}
if ( ! F_51 ( V_75 , * V_76 + sizeof( * V_85 ) ) )
return false ;
V_85 = (struct V_85 * ) ( V_75 -> V_80 + * V_76 ) ;
* V_76 += sizeof( * V_85 ) ;
if ( ( F_52 ( V_82 -> V_87 ) == V_90 ) &&
( F_52 ( V_85 -> V_96 ) != 67 ) )
return false ;
if ( ( F_52 ( V_82 -> V_87 ) == V_94 ) &&
( F_52 ( V_85 -> V_96 ) != 547 ) )
return false ;
return true ;
}
bool F_53 ( struct V_4 * V_4 ,
struct V_74 * V_75 , struct V_82 * V_82 )
{
struct V_13 * V_97 = NULL , * V_98 = NULL ;
struct V_7 * V_99 = NULL ;
struct V_1 * V_5 = NULL ;
bool V_58 , V_100 = false ;
unsigned int V_76 = 0 ;
T_2 V_101 ;
V_58 = F_50 ( V_75 , & V_76 ) ;
if ( ! V_58 )
goto V_6;
V_99 = F_54 ( V_4 , V_82 -> V_102 ,
V_82 -> V_103 ) ;
if ( ! V_99 )
goto V_6;
if ( ! V_99 -> V_25 )
goto V_6;
V_58 = F_47 ( V_75 , V_76 ) ;
if ( ! V_58 )
goto V_6;
switch ( F_20 ( & V_4 -> V_30 ) ) {
case V_104 :
V_101 = V_71 ;
break;
case V_31 :
V_5 = F_4 ( V_4 ) ;
if ( ! V_5 )
goto V_6;
if ( V_5 -> V_7 == V_99 )
goto V_6;
V_97 = F_55 ( V_4 , V_5 -> V_7 , NULL ) ;
if ( ! V_97 )
goto V_6;
V_101 = V_97 -> V_26 ;
break;
case V_105 :
default:
goto V_6;
}
V_98 = F_55 ( V_4 , V_99 , NULL ) ;
if ( ! V_98 )
goto V_6;
if ( V_101 - V_98 -> V_26 > V_106 )
V_100 = true ;
V_6:
if ( V_99 )
F_29 ( V_99 ) ;
if ( V_5 )
F_1 ( V_5 ) ;
if ( V_98 )
F_23 ( V_98 ) ;
if ( V_97 )
F_23 ( V_97 ) ;
return V_100 ;
}
