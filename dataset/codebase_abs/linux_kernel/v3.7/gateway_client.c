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
V_2 = F_6 ( V_6 -> V_7 . V_8 ) ;
if ( ! V_2 )
goto V_9;
if ( ! F_7 ( & V_2 -> V_3 ) )
V_2 = NULL ;
V_9:
F_8 () ;
return V_2 ;
}
struct V_10 *
F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 = NULL ;
V_2 = F_4 ( V_6 ) ;
if ( ! V_2 )
goto V_9;
F_5 () ;
V_11 = V_2 -> V_11 ;
if ( ! V_11 )
goto V_12;
if ( ! F_7 ( & V_11 -> V_3 ) )
V_11 = NULL ;
V_12:
F_8 () ;
V_9:
if ( V_2 )
F_1 ( V_2 ) ;
return V_11 ;
}
static void F_10 ( struct V_5 * V_6 ,
struct V_1 * V_13 )
{
struct V_1 * V_14 ;
F_11 ( & V_6 -> V_7 . V_15 ) ;
if ( V_13 && ! F_7 ( & V_13 -> V_3 ) )
V_13 = NULL ;
V_14 = F_12 ( V_6 -> V_7 . V_8 , 1 ) ;
F_13 ( V_6 -> V_7 . V_8 , V_13 ) ;
if ( V_14 )
F_1 ( V_14 ) ;
F_14 ( & V_6 -> V_7 . V_15 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
F_16 ( & V_6 -> V_7 . V_16 , 1 ) ;
}
static struct V_1 *
F_17 ( struct V_5 * V_6 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_1 * V_2 , * V_8 = NULL ;
T_1 V_21 = 0 , V_22 = 0 ;
T_1 V_23 ;
T_2 V_24 = 0 ;
int V_25 , V_26 ;
T_2 V_27 ;
struct V_10 * V_11 ;
V_23 = V_28 * V_28 ;
V_23 *= 64 ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw.list, list) {
if ( V_2 -> V_29 )
continue;
V_11 = V_2 -> V_11 ;
V_18 = F_19 ( V_11 ) ;
if ( ! V_18 )
continue;
if ( ! F_7 ( & V_2 -> V_3 ) )
goto V_30;
V_27 = V_18 -> V_27 ;
switch ( F_20 ( & V_6 -> V_31 ) ) {
case 1 :
F_21 ( V_11 -> V_32 ,
& V_25 , & V_26 ) ;
V_22 = V_27 * V_27 * V_25 * 100 * 100 ;
V_22 /= V_23 ;
if ( ( V_22 > V_21 ) ||
( ( V_22 == V_21 ) &&
( V_27 > V_24 ) ) ) {
if ( V_8 )
F_1 ( V_8 ) ;
V_8 = V_2 ;
F_22 ( & V_8 -> V_3 ) ;
}
break;
default:
if ( V_27 > V_24 ) {
if ( V_8 )
F_1 ( V_8 ) ;
V_8 = V_2 ;
F_22 ( & V_8 -> V_3 ) ;
}
break;
}
if ( V_27 > V_24 )
V_24 = V_27 ;
if ( V_22 > V_21 )
V_21 = V_22 ;
F_1 ( V_2 ) ;
V_30:
F_23 ( V_18 ) ;
}
F_8 () ;
return V_8 ;
}
void F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_8 = NULL , * V_33 = NULL ;
struct V_17 * V_18 = NULL ;
char V_34 [ 18 ] = { '\0' } ;
if ( F_20 ( & V_6 -> V_35 ) != V_36 )
goto V_9;
V_8 = F_4 ( V_6 ) ;
if ( ! F_25 ( & V_6 -> V_7 . V_16 ) && V_8 )
goto V_9;
V_33 = F_17 ( V_6 ) ;
if ( V_8 == V_33 )
goto V_9;
if ( V_33 ) {
sprintf ( V_34 , L_1 , V_33 -> V_11 -> V_37 ) ;
V_18 = F_19 ( V_33 -> V_11 ) ;
if ( ! V_18 ) {
F_15 ( V_6 ) ;
goto V_9;
}
}
if ( ( V_8 ) && ( ! V_33 ) ) {
F_26 ( V_38 , V_6 ,
L_2 ) ;
F_27 ( V_6 , V_39 , V_40 ,
NULL ) ;
} else if ( ( ! V_8 ) && ( V_33 ) ) {
F_26 ( V_38 , V_6 ,
L_3 ,
V_33 -> V_11 -> V_37 ,
V_33 -> V_11 -> V_32 , V_18 -> V_27 ) ;
F_27 ( V_6 , V_39 , V_41 ,
V_34 ) ;
} else {
F_26 ( V_38 , V_6 ,
L_4 ,
V_33 -> V_11 -> V_37 ,
V_33 -> V_11 -> V_32 , V_18 -> V_27 ) ;
F_27 ( V_6 , V_39 , V_42 ,
V_34 ) ;
}
F_10 ( V_6 , V_33 ) ;
V_9:
if ( V_8 )
F_1 ( V_8 ) ;
if ( V_33 )
F_1 ( V_33 ) ;
if ( V_18 )
F_23 ( V_18 ) ;
}
void F_28 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
struct V_10 * V_43 ;
struct V_17 * V_44 = NULL , * V_45 = NULL ;
T_2 V_46 , V_47 ;
V_43 = F_9 ( V_6 ) ;
if ( ! V_43 )
goto V_48;
V_44 = F_19 ( V_43 ) ;
if ( ! V_44 )
goto V_48;
if ( V_43 == V_11 )
goto V_9;
V_45 = F_19 ( V_11 ) ;
if ( ! V_45 )
goto V_9;
V_46 = V_44 -> V_27 ;
V_47 = V_45 -> V_27 ;
if ( V_47 < V_46 )
goto V_9;
if ( ( F_20 ( & V_6 -> V_31 ) > 3 ) &&
( V_47 - V_46 < F_20 ( & V_6 -> V_31 ) ) )
goto V_9;
F_26 ( V_38 , V_6 ,
L_5 ,
V_46 , V_47 ) ;
V_48:
F_15 ( V_6 ) ;
V_9:
if ( V_43 )
F_29 ( V_43 ) ;
if ( V_44 )
F_23 ( V_44 ) ;
if ( V_45 )
F_23 ( V_45 ) ;
return;
}
static void F_30 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
T_2 V_49 )
{
struct V_1 * V_2 ;
int V_25 , V_26 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return;
F_32 ( & V_2 -> V_51 ) ;
V_2 -> V_11 = V_11 ;
F_16 ( & V_2 -> V_3 , 1 ) ;
F_11 ( & V_6 -> V_7 . V_15 ) ;
F_33 ( & V_2 -> V_51 , & V_6 -> V_7 . V_51 ) ;
F_14 ( & V_6 -> V_7 . V_15 ) ;
F_21 ( V_49 , & V_25 , & V_26 ) ;
F_26 ( V_38 , V_6 ,
L_6 ,
V_11 -> V_37 , V_49 ,
( V_25 > 2048 ? V_25 / 1024 : V_25 ) ,
( V_25 > 2048 ? L_7 : L_8 ) ,
( V_26 > 2048 ? V_26 / 1024 : V_26 ) ,
( V_26 > 2048 ? L_7 : L_8 ) ) ;
}
void F_34 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
T_2 V_49 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 , * V_8 ;
V_8 = F_4 ( V_6 ) ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw.list, list) {
if ( V_2 -> V_11 != V_11 )
continue;
F_26 ( V_38 , V_6 ,
L_9 ,
V_11 -> V_37 , V_2 -> V_11 -> V_32 ,
V_49 ) ;
V_2 -> V_29 = 0 ;
if ( V_49 == V_52 ) {
V_2 -> V_29 = V_53 ;
F_26 ( V_38 , V_6 ,
L_10 ,
V_11 -> V_37 ) ;
if ( V_2 == V_8 )
goto V_48;
}
goto V_12;
}
if ( V_49 == V_52 )
goto V_12;
F_30 ( V_6 , V_11 , V_49 ) ;
goto V_12;
V_48:
F_15 ( V_6 ) ;
V_12:
F_8 () ;
if ( V_8 )
F_1 ( V_8 ) ;
}
void F_35 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
F_34 ( V_6 , V_11 , 0 ) ;
}
void F_36 ( struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_8 ;
struct V_19 * V_20 , * V_54 ;
unsigned long V_55 = F_37 ( 2 * V_56 ) ;
int V_57 = 0 ;
V_8 = F_4 ( V_6 ) ;
F_11 ( & V_6 -> V_7 . V_15 ) ;
F_38 (gw_node, node, node_tmp,
&bat_priv->gw.list, list) {
if ( ( ( ! V_2 -> V_29 ) ||
( F_39 ( V_53 , V_2 -> V_29 + V_55 ) ) ) &&
F_20 ( & V_6 -> V_58 ) == V_59 )
continue;
if ( V_8 == V_2 )
V_57 = 1 ;
F_40 ( & V_2 -> V_51 ) ;
F_1 ( V_2 ) ;
}
F_14 ( & V_6 -> V_7 . V_15 ) ;
if ( V_57 )
F_15 ( V_6 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_60 * V_61 ,
const struct V_1 * V_2 )
{
struct V_1 * V_8 ;
struct V_17 * V_18 ;
int V_25 , V_26 , V_62 = - 1 ;
F_21 ( V_2 -> V_11 -> V_32 , & V_25 , & V_26 ) ;
V_18 = F_19 ( V_2 -> V_11 ) ;
if ( ! V_18 )
goto V_9;
V_8 = F_4 ( V_6 ) ;
V_62 = F_42 ( V_61 , L_11 ,
( V_8 == V_2 ? L_12 : L_13 ) ,
V_2 -> V_11 -> V_37 ,
V_18 -> V_27 , V_18 -> V_63 ,
V_18 -> V_64 -> V_65 -> V_66 ,
V_2 -> V_11 -> V_32 ,
( V_25 > 2048 ? V_25 / 1024 : V_25 ) ,
( V_25 > 2048 ? L_7 : L_8 ) ,
( V_26 > 2048 ? V_26 / 1024 : V_26 ) ,
( V_26 > 2048 ? L_7 : L_8 ) ) ;
F_23 ( V_18 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
V_9:
return V_62 ;
}
int F_43 ( struct V_60 * V_61 , void * V_67 )
{
struct V_68 * V_65 = (struct V_68 * ) V_61 -> V_69 ;
struct V_5 * V_6 = F_44 ( V_65 ) ;
struct V_70 * V_71 ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_72 = 0 , V_62 = 0 ;
V_71 = F_45 ( V_6 ) ;
if ( ! V_71 ) {
V_62 = F_42 ( V_61 ,
L_14 ,
V_65 -> V_66 ) ;
goto V_9;
}
if ( V_71 -> V_73 != V_74 ) {
V_62 = F_42 ( V_61 ,
L_15 ,
V_65 -> V_66 ) ;
goto V_9;
}
F_42 ( V_61 ,
L_16 ,
L_17 , L_18 , V_75 , L_19 , L_20 ,
V_76 , V_71 -> V_65 -> V_66 ,
V_71 -> V_65 -> V_77 , V_65 -> V_66 ) ;
F_5 () ;
F_18 (gw_node, node, &bat_priv->gw.list, list) {
if ( V_2 -> V_29 )
continue;
if ( F_41 ( V_6 , V_61 , V_2 ) < 0 )
continue;
V_72 ++ ;
}
F_8 () ;
if ( V_72 == 0 )
F_42 ( V_61 , L_21 ) ;
V_9:
if ( V_71 )
F_46 ( V_71 ) ;
return V_62 ;
}
static bool F_47 ( struct V_78 * V_79 , int V_80 )
{
int V_62 = false ;
unsigned char * V_81 ;
int V_82 ;
if ( F_48 ( V_79 ) < 0 )
goto V_9;
V_82 = F_49 ( V_79 ) ;
if ( V_82 < V_80 + V_83 + 1 )
goto V_9;
V_81 = V_79 -> V_84 + V_80 + V_83 ;
V_82 -= V_80 + V_83 + 1 ;
while ( * V_81 != 255 && ! V_62 ) {
if ( * V_81 == 53 ) {
if ( V_82 < 2 )
goto V_9;
V_81 += 2 ;
if ( * V_81 == V_85 )
V_62 = true ;
break;
} else if ( * V_81 == 0 ) {
if ( V_82 < 1 )
goto V_9;
V_82 -- ;
V_81 ++ ;
} else {
if ( V_82 < 1 )
goto V_9;
V_82 -- ;
V_81 ++ ;
if ( V_82 < 1 + ( * V_81 ) )
goto V_9;
V_82 -= 1 + ( * V_81 ) ;
V_81 += 1 + ( * V_81 ) ;
}
}
V_9:
return V_62 ;
}
bool F_50 ( struct V_78 * V_79 , unsigned int * V_80 )
{
struct V_86 * V_86 ;
struct V_87 * V_87 ;
struct V_88 * V_88 ;
struct V_89 * V_89 ;
if ( ! F_51 ( V_79 , * V_80 + V_90 ) )
return false ;
V_86 = (struct V_86 * ) V_79 -> V_84 ;
* V_80 += V_90 ;
if ( F_52 ( V_86 -> V_91 ) == V_92 ) {
if ( ! F_51 ( V_79 , * V_80 + V_93 ) )
return false ;
V_86 = (struct V_86 * ) ( V_79 -> V_84 + V_93 ) ;
* V_80 += V_93 ;
}
switch ( F_52 ( V_86 -> V_91 ) ) {
case V_94 :
if ( ! F_51 ( V_79 , * V_80 + sizeof( * V_87 ) ) )
return false ;
V_87 = (struct V_87 * ) ( V_79 -> V_84 + * V_80 ) ;
* V_80 += V_87 -> V_95 * 4 ;
if ( V_87 -> V_96 != V_97 )
return false ;
break;
case V_98 :
if ( ! F_51 ( V_79 , * V_80 + sizeof( * V_88 ) ) )
return false ;
V_88 = (struct V_88 * ) ( V_79 -> V_84 + * V_80 ) ;
* V_80 += sizeof( * V_88 ) ;
if ( V_88 -> V_99 != V_97 )
return false ;
break;
default:
return false ;
}
if ( ! F_51 ( V_79 , * V_80 + sizeof( * V_89 ) ) )
return false ;
V_89 = (struct V_89 * ) ( V_79 -> V_84 + * V_80 ) ;
* V_80 += sizeof( * V_89 ) ;
if ( ( F_52 ( V_86 -> V_91 ) == V_94 ) &&
( F_52 ( V_89 -> V_100 ) != 67 ) )
return false ;
if ( ( F_52 ( V_86 -> V_91 ) == V_98 ) &&
( F_52 ( V_89 -> V_100 ) != 547 ) )
return false ;
return true ;
}
bool F_53 ( struct V_5 * V_6 ,
struct V_78 * V_79 , struct V_86 * V_86 )
{
struct V_17 * V_101 = NULL , * V_102 = NULL ;
struct V_10 * V_103 = NULL ;
struct V_1 * V_8 = NULL ;
bool V_62 , V_104 = false ;
unsigned int V_80 = 0 ;
T_2 V_105 ;
V_62 = F_50 ( V_79 , & V_80 ) ;
if ( ! V_62 )
goto V_9;
V_103 = F_54 ( V_6 , V_86 -> V_106 ,
V_86 -> V_107 ) ;
if ( ! V_103 )
goto V_9;
if ( ! V_103 -> V_32 )
goto V_9;
V_62 = F_47 ( V_79 , V_80 ) ;
if ( ! V_62 )
goto V_9;
switch ( F_20 ( & V_6 -> V_35 ) ) {
case V_108 :
V_105 = V_75 ;
break;
case V_36 :
V_8 = F_4 ( V_6 ) ;
if ( ! V_8 )
goto V_9;
if ( V_8 -> V_11 == V_103 )
goto V_9;
V_101 = F_55 ( V_6 , V_8 -> V_11 ,
NULL ) ;
if ( ! V_101 )
goto V_9;
V_105 = V_101 -> V_27 ;
break;
case V_109 :
default:
goto V_9;
}
V_102 = F_55 ( V_6 , V_103 , NULL ) ;
if ( ! V_102 )
goto V_9;
if ( V_105 - V_102 -> V_27 > V_110 )
V_104 = true ;
V_9:
if ( V_103 )
F_29 ( V_103 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
if ( V_102 )
F_23 ( V_102 ) ;
if ( V_101 )
F_23 ( V_101 ) ;
return V_104 ;
}
