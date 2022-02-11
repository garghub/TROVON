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
struct V_1 * V_2 , * V_8 = NULL ;
T_1 V_19 = 0 , V_20 = 0 ;
T_1 V_21 ;
T_2 V_22 = 0 ;
int V_23 , V_24 ;
T_2 V_25 ;
struct V_10 * V_11 ;
V_21 = V_26 * V_26 ;
V_21 *= 64 ;
F_5 () ;
F_18 (gw_node, &bat_priv->gw.list, list) {
if ( V_2 -> V_27 )
continue;
V_11 = V_2 -> V_11 ;
V_18 = F_19 ( V_11 ) ;
if ( ! V_18 )
continue;
if ( ! F_7 ( & V_2 -> V_3 ) )
goto V_28;
V_25 = V_18 -> V_25 ;
switch ( F_20 ( & V_6 -> V_29 ) ) {
case 1 :
F_21 ( V_11 -> V_30 ,
& V_23 , & V_24 ) ;
V_20 = V_25 * V_25 * V_23 * 100 * 100 ;
V_20 /= V_21 ;
if ( ( V_20 > V_19 ) ||
( ( V_20 == V_19 ) &&
( V_25 > V_22 ) ) ) {
if ( V_8 )
F_1 ( V_8 ) ;
V_8 = V_2 ;
F_22 ( & V_8 -> V_3 ) ;
}
break;
default:
if ( V_25 > V_22 ) {
if ( V_8 )
F_1 ( V_8 ) ;
V_8 = V_2 ;
F_22 ( & V_8 -> V_3 ) ;
}
break;
}
if ( V_25 > V_22 )
V_22 = V_25 ;
if ( V_20 > V_19 )
V_19 = V_20 ;
F_1 ( V_2 ) ;
V_28:
F_23 ( V_18 ) ;
}
F_8 () ;
return V_8 ;
}
void F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_8 = NULL , * V_31 = NULL ;
struct V_17 * V_18 = NULL ;
char V_32 [ 18 ] = { '\0' } ;
if ( F_20 ( & V_6 -> V_33 ) != V_34 )
goto V_9;
V_8 = F_4 ( V_6 ) ;
if ( ! F_25 ( & V_6 -> V_7 . V_16 ) && V_8 )
goto V_9;
V_31 = F_17 ( V_6 ) ;
if ( V_8 == V_31 )
goto V_9;
if ( V_31 ) {
sprintf ( V_32 , L_1 , V_31 -> V_11 -> V_35 ) ;
V_18 = F_19 ( V_31 -> V_11 ) ;
if ( ! V_18 ) {
F_15 ( V_6 ) ;
goto V_9;
}
}
if ( ( V_8 ) && ( ! V_31 ) ) {
F_26 ( V_36 , V_6 ,
L_2 ) ;
F_27 ( V_6 , V_37 , V_38 ,
NULL ) ;
} else if ( ( ! V_8 ) && ( V_31 ) ) {
F_26 ( V_36 , V_6 ,
L_3 ,
V_31 -> V_11 -> V_35 ,
V_31 -> V_11 -> V_30 , V_18 -> V_25 ) ;
F_27 ( V_6 , V_37 , V_39 ,
V_32 ) ;
} else {
F_26 ( V_36 , V_6 ,
L_4 ,
V_31 -> V_11 -> V_35 ,
V_31 -> V_11 -> V_30 , V_18 -> V_25 ) ;
F_27 ( V_6 , V_37 , V_40 ,
V_32 ) ;
}
F_10 ( V_6 , V_31 ) ;
V_9:
if ( V_8 )
F_1 ( V_8 ) ;
if ( V_31 )
F_1 ( V_31 ) ;
if ( V_18 )
F_23 ( V_18 ) ;
}
void F_28 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
struct V_10 * V_41 ;
struct V_17 * V_42 = NULL , * V_43 = NULL ;
T_2 V_44 , V_45 ;
V_41 = F_9 ( V_6 ) ;
if ( ! V_41 )
goto V_46;
V_42 = F_19 ( V_41 ) ;
if ( ! V_42 )
goto V_46;
if ( V_41 == V_11 )
goto V_9;
V_43 = F_19 ( V_11 ) ;
if ( ! V_43 )
goto V_9;
V_44 = V_42 -> V_25 ;
V_45 = V_43 -> V_25 ;
if ( V_45 < V_44 )
goto V_9;
if ( ( F_20 ( & V_6 -> V_29 ) > 3 ) &&
( V_45 - V_44 < F_20 ( & V_6 -> V_29 ) ) )
goto V_9;
F_26 ( V_36 , V_6 ,
L_5 ,
V_44 , V_45 ) ;
V_46:
F_15 ( V_6 ) ;
V_9:
if ( V_41 )
F_29 ( V_41 ) ;
if ( V_42 )
F_23 ( V_42 ) ;
if ( V_43 )
F_23 ( V_43 ) ;
return;
}
static void F_30 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
T_2 V_47 )
{
struct V_1 * V_2 ;
int V_23 , V_24 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return;
F_32 ( & V_2 -> V_49 ) ;
V_2 -> V_11 = V_11 ;
F_16 ( & V_2 -> V_3 , 1 ) ;
F_11 ( & V_6 -> V_7 . V_15 ) ;
F_33 ( & V_2 -> V_49 , & V_6 -> V_7 . V_49 ) ;
F_14 ( & V_6 -> V_7 . V_15 ) ;
F_21 ( V_47 , & V_23 , & V_24 ) ;
F_26 ( V_36 , V_6 ,
L_6 ,
V_11 -> V_35 , V_47 ,
( V_23 > 2048 ? V_23 / 1024 : V_23 ) ,
( V_23 > 2048 ? L_7 : L_8 ) ,
( V_24 > 2048 ? V_24 / 1024 : V_24 ) ,
( V_24 > 2048 ? L_7 : L_8 ) ) ;
}
void F_34 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
T_2 V_47 )
{
struct V_1 * V_2 , * V_8 ;
V_8 = F_4 ( V_6 ) ;
F_5 () ;
F_18 (gw_node, &bat_priv->gw.list, list) {
if ( V_2 -> V_11 != V_11 )
continue;
F_26 ( V_36 , V_6 ,
L_9 ,
V_11 -> V_35 , V_2 -> V_11 -> V_30 ,
V_47 ) ;
V_2 -> V_27 = 0 ;
if ( V_47 == V_50 ) {
V_2 -> V_27 = V_51 ;
F_26 ( V_36 , V_6 ,
L_10 ,
V_11 -> V_35 ) ;
if ( V_2 == V_8 )
goto V_46;
}
goto V_12;
}
if ( V_47 == V_50 )
goto V_12;
F_30 ( V_6 , V_11 , V_47 ) ;
goto V_12;
V_46:
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
struct V_52 * V_53 ;
unsigned long V_54 = F_37 ( 2 * V_55 ) ;
int V_56 = 0 ;
V_8 = F_4 ( V_6 ) ;
F_11 ( & V_6 -> V_7 . V_15 ) ;
F_38 (gw_node, node_tmp,
&bat_priv->gw.list, list) {
if ( ( ( ! V_2 -> V_27 ) ||
( F_39 ( V_51 , V_2 -> V_27 + V_54 ) ) ) &&
F_20 ( & V_6 -> V_57 ) == V_58 )
continue;
if ( V_8 == V_2 )
V_56 = 1 ;
F_40 ( & V_2 -> V_49 ) ;
F_1 ( V_2 ) ;
}
F_14 ( & V_6 -> V_7 . V_15 ) ;
if ( V_56 )
F_15 ( V_6 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_59 * V_60 ,
const struct V_1 * V_2 )
{
struct V_1 * V_8 ;
struct V_17 * V_18 ;
int V_23 , V_24 , V_61 = - 1 ;
F_21 ( V_2 -> V_11 -> V_30 , & V_23 , & V_24 ) ;
V_18 = F_19 ( V_2 -> V_11 ) ;
if ( ! V_18 )
goto V_9;
V_8 = F_4 ( V_6 ) ;
V_61 = F_42 ( V_60 , L_11 ,
( V_8 == V_2 ? L_12 : L_13 ) ,
V_2 -> V_11 -> V_35 ,
V_18 -> V_25 , V_18 -> V_62 ,
V_18 -> V_63 -> V_64 -> V_65 ,
V_2 -> V_11 -> V_30 ,
( V_23 > 2048 ? V_23 / 1024 : V_23 ) ,
( V_23 > 2048 ? L_7 : L_8 ) ,
( V_24 > 2048 ? V_24 / 1024 : V_24 ) ,
( V_24 > 2048 ? L_7 : L_8 ) ) ;
F_23 ( V_18 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
V_9:
return V_61 ;
}
int F_43 ( struct V_59 * V_60 , void * V_66 )
{
struct V_67 * V_64 = (struct V_67 * ) V_60 -> V_68 ;
struct V_5 * V_6 = F_44 ( V_64 ) ;
struct V_69 * V_70 ;
struct V_1 * V_2 ;
int V_71 = 0 ;
V_70 = F_45 ( V_60 ) ;
if ( ! V_70 )
goto V_9;
F_42 ( V_60 ,
L_14 ,
L_15 , L_16 , V_72 , L_17 , L_18 ,
V_73 , V_70 -> V_64 -> V_65 ,
V_70 -> V_64 -> V_74 , V_64 -> V_65 ) ;
F_5 () ;
F_18 (gw_node, &bat_priv->gw.list, list) {
if ( V_2 -> V_27 )
continue;
if ( F_41 ( V_6 , V_60 , V_2 ) < 0 )
continue;
V_71 ++ ;
}
F_8 () ;
if ( V_71 == 0 )
F_42 ( V_60 , L_19 ) ;
V_9:
if ( V_70 )
F_46 ( V_70 ) ;
return 0 ;
}
static bool F_47 ( struct V_75 * V_76 , int V_77 )
{
int V_61 = false ;
unsigned char * V_78 ;
int V_79 ;
if ( F_48 ( V_76 ) < 0 )
goto V_9;
V_79 = F_49 ( V_76 ) ;
if ( V_79 < V_77 + V_80 + 1 )
goto V_9;
V_78 = V_76 -> V_81 + V_77 + V_80 ;
V_79 -= V_77 + V_80 + 1 ;
while ( * V_78 != 255 && ! V_61 ) {
if ( * V_78 == 53 ) {
if ( V_79 < 2 )
goto V_9;
V_78 += 2 ;
if ( * V_78 == V_82 )
V_61 = true ;
break;
} else if ( * V_78 == 0 ) {
if ( V_79 < 1 )
goto V_9;
V_79 -- ;
V_78 ++ ;
} else {
if ( V_79 < 1 )
goto V_9;
V_79 -- ;
V_78 ++ ;
if ( V_79 < 1 + ( * V_78 ) )
goto V_9;
V_79 -= 1 + ( * V_78 ) ;
V_78 += 1 + ( * V_78 ) ;
}
}
V_9:
return V_61 ;
}
bool F_50 ( struct V_75 * V_76 , unsigned int * V_77 )
{
struct V_83 * V_83 ;
struct V_84 * V_84 ;
struct V_85 * V_85 ;
struct V_86 * V_86 ;
if ( ! F_51 ( V_76 , * V_77 + V_87 ) )
return false ;
V_83 = (struct V_83 * ) V_76 -> V_81 ;
* V_77 += V_87 ;
if ( F_52 ( V_83 -> V_88 ) == V_89 ) {
if ( ! F_51 ( V_76 , * V_77 + V_90 ) )
return false ;
V_83 = (struct V_83 * ) ( V_76 -> V_81 + V_90 ) ;
* V_77 += V_90 ;
}
switch ( F_52 ( V_83 -> V_88 ) ) {
case V_91 :
if ( ! F_51 ( V_76 , * V_77 + sizeof( * V_84 ) ) )
return false ;
V_84 = (struct V_84 * ) ( V_76 -> V_81 + * V_77 ) ;
* V_77 += V_84 -> V_92 * 4 ;
if ( V_84 -> V_93 != V_94 )
return false ;
break;
case V_95 :
if ( ! F_51 ( V_76 , * V_77 + sizeof( * V_85 ) ) )
return false ;
V_85 = (struct V_85 * ) ( V_76 -> V_81 + * V_77 ) ;
* V_77 += sizeof( * V_85 ) ;
if ( V_85 -> V_96 != V_94 )
return false ;
break;
default:
return false ;
}
if ( ! F_51 ( V_76 , * V_77 + sizeof( * V_86 ) ) )
return false ;
V_86 = (struct V_86 * ) ( V_76 -> V_81 + * V_77 ) ;
* V_77 += sizeof( * V_86 ) ;
if ( ( F_52 ( V_83 -> V_88 ) == V_91 ) &&
( F_52 ( V_86 -> V_97 ) != 67 ) )
return false ;
if ( ( F_52 ( V_83 -> V_88 ) == V_95 ) &&
( F_52 ( V_86 -> V_97 ) != 547 ) )
return false ;
return true ;
}
bool F_53 ( struct V_5 * V_6 ,
struct V_75 * V_76 , struct V_83 * V_83 )
{
struct V_17 * V_98 = NULL , * V_99 = NULL ;
struct V_10 * V_100 = NULL ;
struct V_1 * V_8 = NULL ;
bool V_61 , V_101 = false ;
unsigned int V_77 = 0 ;
T_2 V_102 ;
V_61 = F_50 ( V_76 , & V_77 ) ;
if ( ! V_61 )
goto V_9;
V_100 = F_54 ( V_6 , V_83 -> V_103 ,
V_83 -> V_104 ) ;
if ( ! V_100 )
goto V_9;
if ( ! V_100 -> V_30 )
goto V_9;
V_61 = F_47 ( V_76 , V_77 ) ;
if ( ! V_61 )
goto V_9;
switch ( F_20 ( & V_6 -> V_33 ) ) {
case V_105 :
V_102 = V_72 ;
break;
case V_34 :
V_8 = F_4 ( V_6 ) ;
if ( ! V_8 )
goto V_9;
if ( V_8 -> V_11 == V_100 )
goto V_9;
V_98 = F_55 ( V_6 , V_8 -> V_11 ,
NULL ) ;
if ( ! V_98 )
goto V_9;
V_102 = V_98 -> V_25 ;
break;
case V_106 :
default:
goto V_9;
}
V_99 = F_55 ( V_6 , V_100 , NULL ) ;
if ( ! V_99 )
goto V_9;
if ( V_102 - V_99 -> V_25 > V_107 )
V_101 = true ;
V_9:
if ( V_100 )
F_29 ( V_100 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
if ( V_99 )
F_23 ( V_99 ) ;
if ( V_98 )
F_23 ( V_98 ) ;
return V_101 ;
}
