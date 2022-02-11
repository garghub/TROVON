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
V_10 = V_4 -> V_5 ;
F_12 ( V_4 -> V_5 , V_9 ) ;
if ( V_10 )
F_1 ( V_10 ) ;
F_13 ( & V_4 -> V_11 ) ;
}
void F_14 ( struct V_4 * V_4 )
{
F_10 ( V_4 , NULL ) ;
}
void F_15 ( struct V_4 * V_4 )
{
struct V_12 * V_13 ;
struct V_1 * V_1 , * V_5 = NULL , * V_14 = NULL ;
struct V_15 * V_16 ;
T_1 V_17 = 0 ;
T_2 V_18 = 0 , V_19 = 0 ;
int V_20 , V_21 ;
if ( F_16 ( & V_4 -> V_22 ) != V_23 )
return;
V_5 = F_4 ( V_4 ) ;
if ( V_5 )
goto V_6;
F_5 () ;
if ( F_17 ( & V_4 -> V_24 ) ) {
F_18 ( V_25 , V_4 ,
L_1
L_2 ) ;
F_14 ( V_4 ) ;
goto V_8;
}
F_19 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_1 -> V_26 )
continue;
V_16 = F_20 ( V_1 -> V_7 ) ;
if ( ! V_16 )
continue;
switch ( F_16 ( & V_4 -> V_27 ) ) {
case 1 :
F_21 ( V_1 -> V_7 -> V_28 ,
& V_20 , & V_21 ) ;
V_19 = ( V_16 -> V_29 * V_16 -> V_29 *
V_20 * 100 * 100 ) /
( V_30 *
V_30 * 64 ) ;
if ( ( V_19 > V_18 ) ||
( ( V_19 == V_18 ) &&
( V_16 -> V_29 > V_17 ) ) )
V_14 = V_1 ;
break;
default:
if ( V_16 -> V_29 > V_17 )
V_14 = V_1 ;
break;
}
if ( V_16 -> V_29 > V_17 )
V_17 = V_16 -> V_29 ;
if ( V_19 > V_18 )
V_18 = V_19 ;
F_22 ( V_16 ) ;
}
if ( V_5 != V_14 ) {
V_16 = F_20 ( V_14 -> V_7 ) ;
if ( ! V_16 )
goto V_8;
if ( ( V_5 ) && ( ! V_14 ) )
F_18 ( V_25 , V_4 ,
L_1
L_2 ) ;
else if ( ( ! V_5 ) && ( V_14 ) )
F_18 ( V_25 , V_4 ,
L_3
L_4 ,
V_14 -> V_7 -> V_31 ,
V_14 -> V_7 -> V_28 ,
V_16 -> V_29 ) ;
else
F_18 ( V_25 , V_4 ,
L_5
L_4 ,
V_14 -> V_7 -> V_31 ,
V_14 -> V_7 -> V_28 ,
V_16 -> V_29 ) ;
F_22 ( V_16 ) ;
F_10 ( V_4 , V_14 ) ;
}
V_8:
F_8 () ;
V_6:
if ( V_5 )
F_1 ( V_5 ) ;
}
void F_23 ( struct V_4 * V_4 , struct V_7 * V_7 )
{
struct V_7 * V_32 ;
struct V_15 * V_33 = NULL , * V_34 = NULL ;
T_1 V_35 , V_36 ;
V_32 = F_9 ( V_4 ) ;
if ( ! V_32 )
goto V_37;
V_33 = F_20 ( V_32 ) ;
if ( ! V_33 )
goto V_37;
if ( V_32 == V_7 )
goto V_6;
V_34 = F_20 ( V_7 ) ;
if ( ! V_34 )
goto V_6;
V_35 = V_33 -> V_29 ;
V_36 = V_34 -> V_29 ;
if ( V_36 < V_35 )
goto V_6;
if ( ( F_16 ( & V_4 -> V_27 ) > 3 ) &&
( V_36 - V_35 < F_16 ( & V_4 -> V_27 ) ) )
goto V_6;
F_18 ( V_25 , V_4 ,
L_6
L_7 ,
V_35 , V_36 ) ;
V_37:
F_14 ( V_4 ) ;
V_6:
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_33 )
F_22 ( V_33 ) ;
if ( V_34 )
F_22 ( V_34 ) ;
return;
}
static void F_25 ( struct V_4 * V_4 ,
struct V_7 * V_7 , T_1 V_38 )
{
struct V_1 * V_1 ;
int V_20 , V_21 ;
V_1 = F_26 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_1 )
return;
memset ( V_1 , 0 , sizeof( struct V_1 ) ) ;
F_27 ( & V_1 -> V_40 ) ;
V_1 -> V_7 = V_7 ;
F_28 ( & V_1 -> V_2 , 1 ) ;
F_11 ( & V_4 -> V_11 ) ;
F_29 ( & V_1 -> V_40 , & V_4 -> V_24 ) ;
F_13 ( & V_4 -> V_11 ) ;
F_21 ( V_38 , & V_20 , & V_21 ) ;
F_18 ( V_25 , V_4 ,
L_8 ,
V_7 -> V_31 , V_38 ,
( V_20 > 2048 ? V_20 / 1024 : V_20 ) ,
( V_20 > 2048 ? L_9 : L_10 ) ,
( V_21 > 2048 ? V_21 / 1024 : V_21 ) ,
( V_21 > 2048 ? L_9 : L_10 ) ) ;
}
void F_30 ( struct V_4 * V_4 ,
struct V_7 * V_7 , T_1 V_38 )
{
struct V_12 * V_13 ;
struct V_1 * V_1 , * V_5 ;
V_5 = F_4 ( V_4 ) ;
F_5 () ;
F_19 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_1 -> V_7 != V_7 )
continue;
F_18 ( V_25 , V_4 ,
L_11
L_12 ,
V_7 -> V_31 , V_1 -> V_7 -> V_28 ,
V_38 ) ;
V_1 -> V_26 = 0 ;
if ( V_38 == 0 ) {
V_1 -> V_26 = V_41 ;
F_18 ( V_25 , V_4 ,
L_13 ,
V_7 -> V_31 ) ;
if ( V_1 == V_5 )
goto V_37;
}
goto V_8;
}
if ( V_38 == 0 )
goto V_8;
F_25 ( V_4 , V_7 , V_38 ) ;
goto V_8;
V_37:
F_14 ( V_4 ) ;
V_8:
F_8 () ;
if ( V_5 )
F_1 ( V_5 ) ;
}
void F_31 ( struct V_4 * V_4 , struct V_7 * V_7 )
{
return F_30 ( V_4 , V_7 , 0 ) ;
}
void F_32 ( struct V_4 * V_4 )
{
struct V_1 * V_1 , * V_5 ;
struct V_12 * V_13 , * V_42 ;
unsigned long V_43 = 2 * V_44 * V_45 ;
char V_46 = 0 ;
V_5 = F_4 ( V_4 ) ;
F_11 ( & V_4 -> V_11 ) ;
F_33 (gw_node, node, node_tmp,
&bat_priv->gw_list, list) {
if ( ( ( ! V_1 -> V_26 ) ||
( F_34 ( V_41 , V_1 -> V_26 + V_43 ) ) ) &&
F_16 ( & V_4 -> V_47 ) == V_48 )
continue;
if ( V_5 == V_1 )
V_46 = 1 ;
F_35 ( & V_1 -> V_40 ) ;
F_1 ( V_1 ) ;
}
F_13 ( & V_4 -> V_11 ) ;
if ( V_46 )
F_14 ( V_4 ) ;
if ( V_5 )
F_1 ( V_5 ) ;
}
static int F_36 ( struct V_4 * V_4 ,
struct V_49 * V_50 , struct V_1 * V_1 )
{
struct V_1 * V_5 ;
struct V_15 * V_16 ;
int V_20 , V_21 , V_51 = - 1 ;
F_21 ( V_1 -> V_7 -> V_28 , & V_20 , & V_21 ) ;
V_16 = F_20 ( V_1 -> V_7 ) ;
if ( ! V_16 )
goto V_6;
V_5 = F_4 ( V_4 ) ;
V_51 = F_37 ( V_50 , L_14 ,
( V_5 == V_1 ? L_15 : L_16 ) ,
V_1 -> V_7 -> V_31 ,
V_16 -> V_29 , V_16 -> V_52 ,
V_16 -> V_53 -> V_54 -> V_55 ,
V_1 -> V_7 -> V_28 ,
( V_20 > 2048 ? V_20 / 1024 : V_20 ) ,
( V_20 > 2048 ? L_9 : L_10 ) ,
( V_21 > 2048 ? V_21 / 1024 : V_21 ) ,
( V_21 > 2048 ? L_9 : L_10 ) ) ;
F_22 ( V_16 ) ;
if ( V_5 )
F_1 ( V_5 ) ;
V_6:
return V_51 ;
}
int F_38 ( struct V_49 * V_50 , void * V_56 )
{
struct V_57 * V_54 = (struct V_57 * ) V_50 -> V_58 ;
struct V_4 * V_4 = F_39 ( V_54 ) ;
struct V_59 * V_60 ;
struct V_1 * V_1 ;
struct V_12 * V_13 ;
int V_61 = 0 , V_51 = 0 ;
V_60 = F_40 ( V_4 ) ;
if ( ! V_60 ) {
V_51 = F_37 ( V_50 , L_17
L_18 ,
V_54 -> V_55 ) ;
goto V_6;
}
if ( V_60 -> V_62 != V_63 ) {
V_51 = F_37 ( V_50 , L_19
L_20 ,
V_54 -> V_55 ) ;
goto V_6;
}
F_37 ( V_50 , L_21
L_22 ,
L_23 , L_24 , V_64 , L_25 ,
L_26 , V_65 , V_66 ,
V_60 -> V_54 -> V_55 ,
V_60 -> V_54 -> V_67 , V_54 -> V_55 ) ;
F_5 () ;
F_19 (gw_node, node, &bat_priv->gw_list, list) {
if ( V_1 -> V_26 )
continue;
if ( F_36 ( V_4 , V_50 , V_1 ) < 0 )
continue;
V_61 ++ ;
}
F_8 () ;
if ( V_61 == 0 )
F_37 ( V_50 , L_27 ) ;
V_6:
if ( V_60 )
F_41 ( V_60 ) ;
return V_51 ;
}
int F_42 ( struct V_4 * V_4 , struct V_68 * V_69 )
{
struct V_70 * V_70 ;
struct V_71 * V_71 ;
struct V_72 * V_72 ;
struct V_73 * V_73 ;
struct V_1 * V_5 ;
unsigned int V_74 = 0 ;
if ( F_16 ( & V_4 -> V_22 ) == V_75 )
return 0 ;
if ( ! F_43 ( V_69 , V_74 + V_76 ) )
return 0 ;
V_70 = (struct V_70 * ) V_69 -> V_77 ;
V_74 += V_76 ;
if ( F_44 ( V_70 -> V_78 ) == V_79 ) {
if ( ! F_43 ( V_69 , V_74 + V_80 ) )
return 0 ;
V_70 = (struct V_70 * ) ( V_69 -> V_77 + V_80 ) ;
V_74 += V_80 ;
}
switch ( F_44 ( V_70 -> V_78 ) ) {
case V_81 :
if ( ! F_43 ( V_69 , V_74 + sizeof( struct V_71 ) ) )
return 0 ;
V_71 = (struct V_71 * ) ( V_69 -> V_77 + V_74 ) ;
V_74 += V_71 -> V_82 * 4 ;
if ( V_71 -> V_83 != V_84 )
return 0 ;
break;
case V_85 :
if ( ! F_43 ( V_69 , V_74 + sizeof( struct V_72 ) ) )
return 0 ;
V_72 = (struct V_72 * ) ( V_69 -> V_77 + V_74 ) ;
V_74 += sizeof( struct V_72 ) ;
if ( V_72 -> V_86 != V_84 )
return 0 ;
break;
default:
return 0 ;
}
if ( ! F_43 ( V_69 , V_74 + sizeof( struct V_73 ) ) )
return 0 ;
V_73 = (struct V_73 * ) ( V_69 -> V_77 + V_74 ) ;
V_74 += sizeof( struct V_73 ) ;
if ( ( F_44 ( V_70 -> V_78 ) == V_81 ) &&
( F_44 ( V_73 -> V_87 ) != 67 ) )
return 0 ;
if ( ( F_44 ( V_70 -> V_78 ) == V_85 ) &&
( F_44 ( V_73 -> V_87 ) != 547 ) )
return 0 ;
if ( F_16 ( & V_4 -> V_22 ) == V_88 )
return - 1 ;
V_5 = F_4 ( V_4 ) ;
if ( ! V_5 )
return 0 ;
if ( V_5 )
F_1 ( V_5 ) ;
return 1 ;
}
