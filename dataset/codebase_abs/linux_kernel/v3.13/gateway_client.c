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
T_2 V_23 ;
struct V_10 * V_11 ;
V_21 = V_24 * V_24 ;
V_21 *= 64 ;
F_5 () ;
F_18 (gw_node, &bat_priv->gw.list, list) {
if ( V_2 -> V_25 )
continue;
V_11 = V_2 -> V_11 ;
V_18 = F_19 ( V_11 ) ;
if ( ! V_18 )
continue;
if ( ! F_7 ( & V_2 -> V_3 ) )
goto V_26;
V_23 = V_18 -> V_27 . V_23 ;
switch ( F_20 ( & V_6 -> V_28 ) ) {
case 1 :
V_20 = V_23 * V_23 ;
V_20 *= V_2 -> V_29 ;
V_20 *= 100 * 100 ;
V_20 /= V_21 ;
if ( ( V_20 > V_19 ) ||
( ( V_20 == V_19 ) &&
( V_23 > V_22 ) ) ) {
if ( V_8 )
F_1 ( V_8 ) ;
V_8 = V_2 ;
F_21 ( & V_8 -> V_3 ) ;
}
break;
default:
if ( V_23 > V_22 ) {
if ( V_8 )
F_1 ( V_8 ) ;
V_8 = V_2 ;
F_21 ( & V_8 -> V_3 ) ;
}
break;
}
if ( V_23 > V_22 )
V_22 = V_23 ;
if ( V_20 > V_19 )
V_19 = V_20 ;
F_1 ( V_2 ) ;
V_26:
F_22 ( V_18 ) ;
}
F_8 () ;
return V_8 ;
}
void F_23 ( struct V_5 * V_6 )
{
struct V_1 * V_8 ;
if ( F_20 ( & V_6 -> V_30 ) != V_31 )
return;
V_8 = F_4 ( V_6 ) ;
if ( ! V_8 )
return;
F_24 ( V_6 , V_32 , V_33 , NULL ) ;
F_1 ( V_8 ) ;
}
void F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_8 = NULL , * V_34 = NULL ;
struct V_17 * V_18 = NULL ;
char V_35 [ 18 ] = { '\0' } ;
if ( F_20 ( & V_6 -> V_30 ) != V_31 )
goto V_9;
V_8 = F_4 ( V_6 ) ;
if ( ! F_26 ( & V_6 -> V_7 . V_16 ) && V_8 )
goto V_9;
V_34 = F_17 ( V_6 ) ;
if ( V_8 == V_34 )
goto V_9;
if ( V_34 ) {
sprintf ( V_35 , L_1 , V_34 -> V_11 -> V_36 ) ;
V_18 = F_19 ( V_34 -> V_11 ) ;
if ( ! V_18 ) {
F_15 ( V_6 ) ;
goto V_9;
}
}
if ( ( V_8 ) && ( ! V_34 ) ) {
F_27 ( V_37 , V_6 ,
L_2 ) ;
F_24 ( V_6 , V_32 , V_33 ,
NULL ) ;
} else if ( ( ! V_8 ) && ( V_34 ) ) {
F_27 ( V_37 , V_6 ,
L_3 ,
V_34 -> V_11 -> V_36 ,
V_34 -> V_29 / 10 ,
V_34 -> V_29 % 10 ,
V_34 -> V_38 / 10 ,
V_34 -> V_38 % 10 , V_18 -> V_27 . V_23 ) ;
F_24 ( V_6 , V_32 , V_39 ,
V_35 ) ;
} else {
F_27 ( V_37 , V_6 ,
L_4 ,
V_34 -> V_11 -> V_36 ,
V_34 -> V_29 / 10 ,
V_34 -> V_29 % 10 ,
V_34 -> V_38 / 10 ,
V_34 -> V_38 % 10 , V_18 -> V_27 . V_23 ) ;
F_24 ( V_6 , V_32 , V_40 ,
V_35 ) ;
}
F_10 ( V_6 , V_34 ) ;
V_9:
if ( V_8 )
F_1 ( V_8 ) ;
if ( V_34 )
F_1 ( V_34 ) ;
if ( V_18 )
F_22 ( V_18 ) ;
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
V_44 = V_42 -> V_27 . V_23 ;
V_45 = V_43 -> V_27 . V_23 ;
if ( V_45 < V_44 )
goto V_9;
if ( ( F_20 ( & V_6 -> V_28 ) > 3 ) &&
( V_45 - V_44 < F_20 ( & V_6 -> V_28 ) ) )
goto V_9;
F_27 ( V_37 , V_6 ,
L_5 ,
V_44 , V_45 ) ;
V_46:
F_15 ( V_6 ) ;
V_9:
if ( V_41 )
F_29 ( V_41 ) ;
if ( V_42 )
F_22 ( V_42 ) ;
if ( V_43 )
F_22 ( V_43 ) ;
return;
}
static void F_30 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 ;
if ( V_48 -> V_29 == 0 )
return;
V_2 = F_31 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return;
F_32 ( & V_2 -> V_50 ) ;
V_2 -> V_11 = V_11 ;
F_16 ( & V_2 -> V_3 , 1 ) ;
F_11 ( & V_6 -> V_7 . V_15 ) ;
F_33 ( & V_2 -> V_50 , & V_6 -> V_7 . V_50 ) ;
F_14 ( & V_6 -> V_7 . V_15 ) ;
F_27 ( V_37 , V_6 ,
L_6 ,
V_11 -> V_36 ,
F_34 ( V_48 -> V_29 ) / 10 ,
F_34 ( V_48 -> V_29 ) % 10 ,
F_34 ( V_48 -> V_38 ) / 10 ,
F_34 ( V_48 -> V_38 ) % 10 ) ;
}
static struct V_1 *
F_35 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
struct V_1 * V_51 , * V_2 = NULL ;
F_5 () ;
F_18 (gw_node_tmp, &bat_priv->gw.list, list) {
if ( V_51 -> V_11 != V_11 )
continue;
if ( V_51 -> V_25 )
continue;
if ( ! F_7 ( & V_51 -> V_3 ) )
continue;
V_2 = V_51 ;
break;
}
F_8 () ;
return V_2 ;
}
void F_36 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 , * V_8 = NULL ;
V_2 = F_35 ( V_6 , V_11 ) ;
if ( ! V_2 ) {
F_30 ( V_6 , V_11 , V_48 ) ;
goto V_9;
}
if ( ( V_2 -> V_29 == F_34 ( V_48 -> V_29 ) ) &&
( V_2 -> V_38 == F_34 ( V_48 -> V_38 ) ) )
goto V_9;
F_27 ( V_37 , V_6 ,
L_7 ,
V_11 -> V_36 ,
V_2 -> V_29 / 10 ,
V_2 -> V_29 % 10 ,
V_2 -> V_38 / 10 ,
V_2 -> V_38 % 10 ,
F_34 ( V_48 -> V_29 ) / 10 ,
F_34 ( V_48 -> V_29 ) % 10 ,
F_34 ( V_48 -> V_38 ) / 10 ,
F_34 ( V_48 -> V_38 ) % 10 ) ;
V_2 -> V_29 = F_34 ( V_48 -> V_29 ) ;
V_2 -> V_38 = F_34 ( V_48 -> V_38 ) ;
V_2 -> V_25 = 0 ;
if ( F_34 ( V_48 -> V_29 ) == 0 ) {
V_2 -> V_25 = V_52 ;
F_27 ( V_37 , V_6 ,
L_8 ,
V_11 -> V_36 ) ;
V_8 = F_4 ( V_6 ) ;
if ( V_2 == V_8 )
F_15 ( V_6 ) ;
}
V_9:
if ( V_8 )
F_1 ( V_8 ) ;
if ( V_2 )
F_1 ( V_2 ) ;
}
void F_37 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
struct V_47 V_48 ;
V_48 . V_29 = 0 ;
V_48 . V_38 = 0 ;
F_36 ( V_6 , V_11 , & V_48 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_8 ;
struct V_53 * V_54 ;
unsigned long V_55 = F_39 ( 2 * V_56 ) ;
int V_57 = 0 ;
V_8 = F_4 ( V_6 ) ;
F_11 ( & V_6 -> V_7 . V_15 ) ;
F_40 (gw_node, node_tmp,
&bat_priv->gw.list, list) {
if ( ( ( ! V_2 -> V_25 ) ||
( F_41 ( V_52 , V_2 -> V_25 + V_55 ) ) ) &&
F_20 ( & V_6 -> V_58 ) == V_59 )
continue;
if ( V_8 == V_2 )
V_57 = 1 ;
F_42 ( & V_2 -> V_50 ) ;
F_1 ( V_2 ) ;
}
F_14 ( & V_6 -> V_7 . V_15 ) ;
if ( V_57 )
F_15 ( V_6 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_60 * V_61 ,
const struct V_1 * V_2 )
{
struct V_1 * V_8 ;
struct V_17 * V_18 ;
int V_62 = - 1 ;
V_18 = F_19 ( V_2 -> V_11 ) ;
if ( ! V_18 )
goto V_9;
V_8 = F_4 ( V_6 ) ;
V_62 = F_44 ( V_61 , L_9 ,
( V_8 == V_2 ? L_10 : L_11 ) ,
V_2 -> V_11 -> V_36 ,
V_18 -> V_27 . V_23 , V_18 -> V_63 ,
V_18 -> V_64 -> V_65 -> V_66 ,
V_2 -> V_29 / 10 ,
V_2 -> V_29 % 10 ,
V_2 -> V_38 / 10 ,
V_2 -> V_38 % 10 ) ;
F_22 ( V_18 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
V_9:
return V_62 ;
}
int F_45 ( struct V_60 * V_61 , void * V_67 )
{
struct V_68 * V_65 = (struct V_68 * ) V_61 -> V_69 ;
struct V_5 * V_6 = F_46 ( V_65 ) ;
struct V_70 * V_71 ;
struct V_1 * V_2 ;
int V_72 = 0 ;
V_71 = F_47 ( V_61 ) ;
if ( ! V_71 )
goto V_9;
F_44 ( V_61 ,
L_12 ,
L_13 , L_14 , V_73 , L_15 , L_16 ,
V_74 , V_71 -> V_65 -> V_66 ,
V_71 -> V_65 -> V_75 , V_65 -> V_66 ) ;
F_5 () ;
F_18 (gw_node, &bat_priv->gw.list, list) {
if ( V_2 -> V_25 )
continue;
if ( F_43 ( V_6 , V_61 , V_2 ) < 0 )
continue;
V_72 ++ ;
}
F_8 () ;
if ( V_72 == 0 )
F_48 ( V_61 , L_17 ) ;
V_9:
if ( V_71 )
F_49 ( V_71 ) ;
return 0 ;
}
static bool F_50 ( struct V_76 * V_77 , int V_78 )
{
int V_62 = false ;
unsigned char * V_79 ;
int V_80 ;
if ( F_51 ( V_77 ) < 0 )
goto V_9;
V_80 = F_52 ( V_77 ) ;
if ( V_80 < V_78 + V_81 + 1 )
goto V_9;
V_79 = V_77 -> V_82 + V_78 + V_81 ;
V_80 -= V_78 + V_81 + 1 ;
while ( * V_79 != 255 && ! V_62 ) {
if ( * V_79 == 53 ) {
if ( V_80 < 2 )
goto V_9;
V_79 += 2 ;
if ( * V_79 == V_83 )
V_62 = true ;
break;
} else if ( * V_79 == 0 ) {
if ( V_80 < 1 )
goto V_9;
V_80 -- ;
V_79 ++ ;
} else {
if ( V_80 < 1 )
goto V_9;
V_80 -- ;
V_79 ++ ;
if ( V_80 < 1 + ( * V_79 ) )
goto V_9;
V_80 -= 1 + ( * V_79 ) ;
V_79 += 1 + ( * V_79 ) ;
}
}
V_9:
return V_62 ;
}
bool F_53 ( struct V_76 * V_77 , unsigned int * V_78 )
{
struct V_84 * V_84 ;
struct V_85 * V_85 ;
struct V_86 * V_86 ;
struct V_87 * V_87 ;
struct V_88 * V_89 ;
T_3 V_90 ;
if ( ! F_54 ( V_77 , * V_78 + V_91 ) )
return false ;
V_84 = (struct V_84 * ) V_77 -> V_82 ;
V_90 = V_84 -> V_92 ;
* V_78 += V_91 ;
if ( V_90 == F_55 ( V_93 ) ) {
if ( ! F_54 ( V_77 , * V_78 + V_94 ) )
return false ;
V_89 = (struct V_88 * ) V_77 -> V_82 ;
V_90 = V_89 -> V_95 ;
* V_78 += V_94 ;
}
switch ( V_90 ) {
case F_55 ( V_96 ) :
if ( ! F_54 ( V_77 , * V_78 + sizeof( * V_85 ) ) )
return false ;
V_85 = (struct V_85 * ) ( V_77 -> V_82 + * V_78 ) ;
* V_78 += V_85 -> V_97 * 4 ;
if ( V_85 -> V_98 != V_99 )
return false ;
break;
case F_55 ( V_100 ) :
if ( ! F_54 ( V_77 , * V_78 + sizeof( * V_86 ) ) )
return false ;
V_86 = (struct V_86 * ) ( V_77 -> V_82 + * V_78 ) ;
* V_78 += sizeof( * V_86 ) ;
if ( V_86 -> V_101 != V_99 )
return false ;
break;
default:
return false ;
}
if ( ! F_54 ( V_77 , * V_78 + sizeof( * V_87 ) ) )
return false ;
V_84 = (struct V_84 * ) V_77 -> V_82 ;
if ( F_56 ( V_84 -> V_92 ) == V_93 )
V_84 = (struct V_84 * ) ( V_77 -> V_82 + V_94 ) ;
V_87 = (struct V_87 * ) ( V_77 -> V_82 + * V_78 ) ;
* V_78 += sizeof( * V_87 ) ;
if ( ( V_90 == F_55 ( V_96 ) ) &&
( V_87 -> V_102 != F_55 ( 67 ) ) )
return false ;
if ( ( V_90 == F_55 ( V_100 ) ) &&
( V_87 -> V_102 != F_55 ( 547 ) ) )
return false ;
return true ;
}
bool F_57 ( struct V_5 * V_6 ,
struct V_76 * V_77 )
{
struct V_17 * V_103 = NULL , * V_104 = NULL ;
struct V_10 * V_105 = NULL ;
struct V_1 * V_2 = NULL , * V_8 = NULL ;
struct V_84 * V_84 ;
bool V_62 , V_106 = false ;
unsigned int V_78 = 0 ;
T_2 V_107 ;
unsigned short V_108 ;
V_108 = F_58 ( V_77 , 0 ) ;
V_62 = F_53 ( V_77 , & V_78 ) ;
if ( ! V_62 )
goto V_9;
V_84 = (struct V_84 * ) V_77 -> V_82 ;
V_105 = F_59 ( V_6 , V_84 -> V_109 ,
V_84 -> V_110 , V_108 ) ;
if ( ! V_105 )
goto V_9;
V_2 = F_35 ( V_6 , V_105 ) ;
if ( ! V_2 -> V_29 == 0 )
goto V_9;
V_62 = F_50 ( V_77 , V_78 ) ;
if ( ! V_62 )
goto V_9;
switch ( F_20 ( & V_6 -> V_30 ) ) {
case V_111 :
V_107 = V_73 ;
break;
case V_31 :
V_8 = F_4 ( V_6 ) ;
if ( ! V_8 )
goto V_9;
if ( V_8 -> V_11 == V_105 )
goto V_9;
V_103 = F_60 ( V_6 , V_8 -> V_11 ,
NULL ) ;
if ( ! V_103 )
goto V_9;
V_107 = V_103 -> V_27 . V_23 ;
break;
case V_112 :
default:
goto V_9;
}
V_104 = F_60 ( V_6 , V_105 , NULL ) ;
if ( ! V_104 )
goto V_9;
if ( V_107 - V_104 -> V_27 . V_23 > V_113 )
V_106 = true ;
V_9:
if ( V_105 )
F_29 ( V_105 ) ;
if ( V_8 )
F_1 ( V_8 ) ;
if ( V_2 )
F_1 ( V_2 ) ;
if ( V_104 )
F_22 ( V_104 ) ;
if ( V_103 )
F_22 ( V_103 ) ;
return V_106 ;
}
