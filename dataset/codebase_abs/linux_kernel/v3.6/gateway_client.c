static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) )
F_3 ( V_2 , V_4 ) ;
}
static struct V_1 *
F_4 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_5 () ;
V_2 = F_6 ( V_6 -> V_7 ) ;
if ( ! V_2 )
goto V_8;
if ( ! F_7 ( & V_2 -> V_3 ) )
V_2 = NULL ;
V_8:
F_8 () ;
return V_2 ;
}
struct V_9 *
F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = NULL ;
V_2 = F_4 ( V_6 ) ;
if ( ! V_2 )
goto V_8;
F_5 () ;
V_10 = V_2 -> V_10 ;
if ( ! V_10 )
goto V_11;
if ( ! F_7 ( & V_10 -> V_3 ) )
V_10 = NULL ;
V_11:
F_8 () ;
V_8:
if ( V_2 )
F_1 ( V_2 ) ;
return V_10 ;
}
static void F_10 ( struct V_5 * V_6 ,
struct V_1 * V_12 )
{
struct V_1 * V_13 ;
F_11 ( & V_6 -> V_14 ) ;
if ( V_12 && ! F_7 ( & V_12 -> V_3 ) )
V_12 = NULL ;
V_13 = F_12 ( V_6 -> V_7 , 1 ) ;
F_13 ( V_6 -> V_7 , V_12 ) ;
if ( V_13 )
F_1 ( V_13 ) ;
F_14 ( & V_6 -> V_14 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
F_16 ( & V_6 -> V_15 , 1 ) ;
}
static struct V_1 *
F_17 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_1 * V_2 , * V_7 = NULL ;
T_1 V_20 = 0 , V_21 = 0 ;
T_2 V_22 = 0 ;
int V_23 , V_24 ;
struct V_9 * V_10 ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_2 -> V_25 )
continue;
V_10 = V_2 -> V_10 ;
V_17 = F_19 ( V_10 ) ;
if ( ! V_17 )
continue;
if ( ! F_7 ( & V_2 -> V_3 ) )
goto V_26;
switch ( F_20 ( & V_6 -> V_27 ) ) {
case 1 :
F_21 ( V_10 -> V_28 ,
& V_23 , & V_24 ) ;
V_21 = ( V_17 -> V_29 * V_17 -> V_29 *
V_23 * 100 * 100 ) /
( V_30 *
V_30 * 64 ) ;
if ( ( V_21 > V_20 ) ||
( ( V_21 == V_20 ) &&
( V_17 -> V_29 > V_22 ) ) ) {
if ( V_7 )
F_1 ( V_7 ) ;
V_7 = V_2 ;
F_22 ( & V_7 -> V_3 ) ;
}
break;
default:
if ( V_17 -> V_29 > V_22 ) {
if ( V_7 )
F_1 ( V_7 ) ;
V_7 = V_2 ;
F_22 ( & V_7 -> V_3 ) ;
}
break;
}
if ( V_17 -> V_29 > V_22 )
V_22 = V_17 -> V_29 ;
if ( V_21 > V_20 )
V_20 = V_21 ;
F_1 ( V_2 ) ;
V_26:
F_23 ( V_17 ) ;
}
F_8 () ;
return V_7 ;
}
void F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = NULL , * V_31 = NULL ;
struct V_16 * V_17 = NULL ;
char V_32 [ 18 ] = { '\0' } ;
if ( F_20 ( & V_6 -> V_33 ) != V_34 )
goto V_8;
V_7 = F_4 ( V_6 ) ;
if ( ! F_25 ( & V_6 -> V_15 ) && V_7 )
goto V_8;
V_31 = F_17 ( V_6 ) ;
if ( V_7 == V_31 )
goto V_8;
if ( V_31 ) {
sprintf ( V_32 , L_1 , V_31 -> V_10 -> V_35 ) ;
V_17 = F_19 ( V_31 -> V_10 ) ;
if ( ! V_17 ) {
F_15 ( V_6 ) ;
goto V_8;
}
}
if ( ( V_7 ) && ( ! V_31 ) ) {
F_26 ( V_36 , V_6 ,
L_2 ) ;
F_27 ( V_6 , V_37 , V_38 ,
NULL ) ;
} else if ( ( ! V_7 ) && ( V_31 ) ) {
F_26 ( V_36 , V_6 ,
L_3 ,
V_31 -> V_10 -> V_35 ,
V_31 -> V_10 -> V_28 , V_17 -> V_29 ) ;
F_27 ( V_6 , V_37 , V_39 ,
V_32 ) ;
} else {
F_26 ( V_36 , V_6 ,
L_4 ,
V_31 -> V_10 -> V_35 ,
V_31 -> V_10 -> V_28 , V_17 -> V_29 ) ;
F_27 ( V_6 , V_37 , V_40 ,
V_32 ) ;
}
F_10 ( V_6 , V_31 ) ;
V_8:
if ( V_7 )
F_1 ( V_7 ) ;
if ( V_31 )
F_1 ( V_31 ) ;
if ( V_17 )
F_23 ( V_17 ) ;
}
void F_28 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
struct V_9 * V_41 ;
struct V_16 * V_42 = NULL , * V_43 = NULL ;
T_2 V_44 , V_45 ;
V_41 = F_9 ( V_6 ) ;
if ( ! V_41 )
goto V_46;
V_42 = F_19 ( V_41 ) ;
if ( ! V_42 )
goto V_46;
if ( V_41 == V_10 )
goto V_8;
V_43 = F_19 ( V_10 ) ;
if ( ! V_43 )
goto V_8;
V_44 = V_42 -> V_29 ;
V_45 = V_43 -> V_29 ;
if ( V_45 < V_44 )
goto V_8;
if ( ( F_20 ( & V_6 -> V_27 ) > 3 ) &&
( V_45 - V_44 < F_20 ( & V_6 -> V_27 ) ) )
goto V_8;
F_26 ( V_36 , V_6 ,
L_5 ,
V_44 , V_45 ) ;
V_46:
F_15 ( V_6 ) ;
V_8:
if ( V_41 )
F_29 ( V_41 ) ;
if ( V_42 )
F_23 ( V_42 ) ;
if ( V_43 )
F_23 ( V_43 ) ;
return;
}
static void F_30 ( struct V_5 * V_6 ,
struct V_9 * V_10 ,
T_2 V_47 )
{
struct V_1 * V_2 ;
int V_23 , V_24 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return;
F_32 ( & V_2 -> V_49 ) ;
V_2 -> V_10 = V_10 ;
F_16 ( & V_2 -> V_3 , 1 ) ;
F_11 ( & V_6 -> V_14 ) ;
F_33 ( & V_2 -> V_49 , & V_6 -> V_50 ) ;
F_14 ( & V_6 -> V_14 ) ;
F_21 ( V_47 , & V_23 , & V_24 ) ;
F_26 ( V_36 , V_6 ,
L_6 ,
V_10 -> V_35 , V_47 ,
( V_23 > 2048 ? V_23 / 1024 : V_23 ) ,
( V_23 > 2048 ? L_7 : L_8 ) ,
( V_24 > 2048 ? V_24 / 1024 : V_24 ) ,
( V_24 > 2048 ? L_7 : L_8 ) ) ;
}
void F_34 ( struct V_5 * V_6 ,
struct V_9 * V_10 ,
T_2 V_47 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 , * V_7 ;
V_7 = F_4 ( V_6 ) ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_2 -> V_10 != V_10 )
continue;
F_26 ( V_36 , V_6 ,
L_9 ,
V_10 -> V_35 , V_2 -> V_10 -> V_28 ,
V_47 ) ;
V_2 -> V_25 = 0 ;
if ( V_47 == V_51 ) {
V_2 -> V_25 = V_52 ;
F_26 ( V_36 , V_6 ,
L_10 ,
V_10 -> V_35 ) ;
if ( V_2 == V_7 )
goto V_46;
}
goto V_11;
}
if ( V_47 == V_51 )
goto V_11;
F_30 ( V_6 , V_10 , V_47 ) ;
goto V_11;
V_46:
F_15 ( V_6 ) ;
V_11:
F_8 () ;
if ( V_7 )
F_1 ( V_7 ) ;
}
void F_35 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
F_34 ( V_6 , V_10 , 0 ) ;
}
void F_36 ( struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_7 ;
struct V_18 * V_19 , * V_53 ;
unsigned long V_54 = F_37 ( 2 * V_55 ) ;
int V_56 = 0 ;
V_7 = F_4 ( V_6 ) ;
F_11 ( & V_6 -> V_14 ) ;
F_38 (gw_node, node, node_tmp,
&bat_priv->gw_list, list) {
if ( ( ( ! V_2 -> V_25 ) ||
( F_39 ( V_52 , V_2 -> V_25 + V_54 ) ) ) &&
F_20 ( & V_6 -> V_57 ) == V_58 )
continue;
if ( V_7 == V_2 )
V_56 = 1 ;
F_40 ( & V_2 -> V_49 ) ;
F_1 ( V_2 ) ;
}
F_14 ( & V_6 -> V_14 ) ;
if ( V_56 )
F_15 ( V_6 ) ;
if ( V_7 )
F_1 ( V_7 ) ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_59 * V_60 ,
const struct V_1 * V_2 )
{
struct V_1 * V_7 ;
struct V_16 * V_17 ;
int V_23 , V_24 , V_61 = - 1 ;
F_21 ( V_2 -> V_10 -> V_28 , & V_23 , & V_24 ) ;
V_17 = F_19 ( V_2 -> V_10 ) ;
if ( ! V_17 )
goto V_8;
V_7 = F_4 ( V_6 ) ;
V_61 = F_42 ( V_60 , L_11 ,
( V_7 == V_2 ? L_12 : L_13 ) ,
V_2 -> V_10 -> V_35 ,
V_17 -> V_29 , V_17 -> V_62 ,
V_17 -> V_63 -> V_64 -> V_65 ,
V_2 -> V_10 -> V_28 ,
( V_23 > 2048 ? V_23 / 1024 : V_23 ) ,
( V_23 > 2048 ? L_7 : L_8 ) ,
( V_24 > 2048 ? V_24 / 1024 : V_24 ) ,
( V_24 > 2048 ? L_7 : L_8 ) ) ;
F_23 ( V_17 ) ;
if ( V_7 )
F_1 ( V_7 ) ;
V_8:
return V_61 ;
}
int F_43 ( struct V_59 * V_60 , void * V_66 )
{
struct V_67 * V_64 = (struct V_67 * ) V_60 -> V_68 ;
struct V_5 * V_6 = F_44 ( V_64 ) ;
struct V_69 * V_70 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_71 = 0 , V_61 = 0 ;
V_70 = F_45 ( V_6 ) ;
if ( ! V_70 ) {
V_61 = F_42 ( V_60 ,
L_14 ,
V_64 -> V_65 ) ;
goto V_8;
}
if ( V_70 -> V_72 != V_73 ) {
V_61 = F_42 ( V_60 ,
L_15 ,
V_64 -> V_65 ) ;
goto V_8;
}
F_42 ( V_60 ,
L_16 ,
L_17 , L_18 , V_74 , L_19 , L_20 ,
V_75 , V_70 -> V_64 -> V_65 ,
V_70 -> V_64 -> V_76 , V_64 -> V_65 ) ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_2 -> V_25 )
continue;
if ( F_41 ( V_6 , V_60 , V_2 ) < 0 )
continue;
V_71 ++ ;
}
F_8 () ;
if ( V_71 == 0 )
F_42 ( V_60 , L_21 ) ;
V_8:
if ( V_70 )
F_46 ( V_70 ) ;
return V_61 ;
}
static bool F_47 ( struct V_77 * V_78 , int V_79 )
{
int V_61 = false ;
unsigned char * V_80 ;
int V_81 ;
if ( F_48 ( V_78 ) < 0 )
goto V_8;
V_81 = F_49 ( V_78 ) ;
if ( V_81 < V_79 + V_82 + 1 )
goto V_8;
V_80 = V_78 -> V_83 + V_79 + V_82 ;
V_81 -= V_79 + V_82 + 1 ;
while ( * V_80 != 255 && ! V_61 ) {
if ( * V_80 == 53 ) {
if ( V_81 < 2 )
goto V_8;
V_80 += 2 ;
if ( * V_80 == V_84 )
V_61 = true ;
break;
} else if ( * V_80 == 0 ) {
if ( V_81 < 1 )
goto V_8;
V_81 -- ;
V_80 ++ ;
} else {
if ( V_81 < 1 )
goto V_8;
V_81 -- ;
V_80 ++ ;
if ( V_81 < 1 + ( * V_80 ) )
goto V_8;
V_81 -= 1 + ( * V_80 ) ;
V_80 += 1 + ( * V_80 ) ;
}
}
V_8:
return V_61 ;
}
bool F_50 ( struct V_77 * V_78 , unsigned int * V_79 )
{
struct V_85 * V_85 ;
struct V_86 * V_86 ;
struct V_87 * V_87 ;
struct V_88 * V_88 ;
if ( ! F_51 ( V_78 , * V_79 + V_89 ) )
return false ;
V_85 = (struct V_85 * ) V_78 -> V_83 ;
* V_79 += V_89 ;
if ( F_52 ( V_85 -> V_90 ) == V_91 ) {
if ( ! F_51 ( V_78 , * V_79 + V_92 ) )
return false ;
V_85 = (struct V_85 * ) ( V_78 -> V_83 + V_92 ) ;
* V_79 += V_92 ;
}
switch ( F_52 ( V_85 -> V_90 ) ) {
case V_93 :
if ( ! F_51 ( V_78 , * V_79 + sizeof( * V_86 ) ) )
return false ;
V_86 = (struct V_86 * ) ( V_78 -> V_83 + * V_79 ) ;
* V_79 += V_86 -> V_94 * 4 ;
if ( V_86 -> V_95 != V_96 )
return false ;
break;
case V_97 :
if ( ! F_51 ( V_78 , * V_79 + sizeof( * V_87 ) ) )
return false ;
V_87 = (struct V_87 * ) ( V_78 -> V_83 + * V_79 ) ;
* V_79 += sizeof( * V_87 ) ;
if ( V_87 -> V_98 != V_96 )
return false ;
break;
default:
return false ;
}
if ( ! F_51 ( V_78 , * V_79 + sizeof( * V_88 ) ) )
return false ;
V_88 = (struct V_88 * ) ( V_78 -> V_83 + * V_79 ) ;
* V_79 += sizeof( * V_88 ) ;
if ( ( F_52 ( V_85 -> V_90 ) == V_93 ) &&
( F_52 ( V_88 -> V_99 ) != 67 ) )
return false ;
if ( ( F_52 ( V_85 -> V_90 ) == V_97 ) &&
( F_52 ( V_88 -> V_99 ) != 547 ) )
return false ;
return true ;
}
bool F_53 ( struct V_5 * V_6 ,
struct V_77 * V_78 , struct V_85 * V_85 )
{
struct V_16 * V_100 = NULL , * V_101 = NULL ;
struct V_9 * V_102 = NULL ;
struct V_1 * V_7 = NULL ;
bool V_61 , V_103 = false ;
unsigned int V_79 = 0 ;
T_2 V_104 ;
V_61 = F_50 ( V_78 , & V_79 ) ;
if ( ! V_61 )
goto V_8;
V_102 = F_54 ( V_6 , V_85 -> V_105 ,
V_85 -> V_106 ) ;
if ( ! V_102 )
goto V_8;
if ( ! V_102 -> V_28 )
goto V_8;
V_61 = F_47 ( V_78 , V_79 ) ;
if ( ! V_61 )
goto V_8;
switch ( F_20 ( & V_6 -> V_33 ) ) {
case V_107 :
V_104 = V_74 ;
break;
case V_34 :
V_7 = F_4 ( V_6 ) ;
if ( ! V_7 )
goto V_8;
if ( V_7 -> V_10 == V_102 )
goto V_8;
V_100 = F_55 ( V_6 , V_7 -> V_10 ,
NULL ) ;
if ( ! V_100 )
goto V_8;
V_104 = V_100 -> V_29 ;
break;
case V_108 :
default:
goto V_8;
}
V_101 = F_55 ( V_6 , V_102 , NULL ) ;
if ( ! V_101 )
goto V_8;
if ( V_104 - V_101 -> V_29 > V_109 )
V_103 = true ;
V_8:
if ( V_102 )
F_29 ( V_102 ) ;
if ( V_7 )
F_1 ( V_7 ) ;
if ( V_101 )
F_23 ( V_101 ) ;
if ( V_100 )
F_23 ( V_100 ) ;
return V_103 ;
}
