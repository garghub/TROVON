static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_4 * F_3 ( struct V_5 * V_6 )
{
switch ( V_6 -> type ) {
case V_7 :
return F_4 ( V_6 -> V_8 , struct V_9 ,
V_10 ) -> V_11 ;
break;
case V_12 :
return F_4 ( V_6 -> V_8 , struct V_13 ,
V_10 ) -> V_11 ;
break;
case V_14 :
return F_4 ( V_6 -> V_8 , struct V_15 ,
V_10 ) -> V_11 ;
break;
case V_16 :
return F_4 ( V_6 -> V_8 , struct V_17 ,
V_10 ) -> V_11 ;
break;
default:
F_5 ( V_18 L_1 ) ;
return NULL ;
break;
}
}
void * F_6 ( struct V_5 * V_6 , T_1 V_19 ,
T_2 * V_20 )
{
struct V_4 * V_21 ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_2 ) ;
return NULL ;
}
V_21 = F_3 ( V_6 ) ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_3 ) ;
return NULL ;
}
if ( V_21 -> V_11 == NULL ) {
F_5 ( V_18 L_4 , V_21 -> V_22 ) ;
return NULL ;
}
if ( V_21 -> V_23 == NULL ) {
F_5 ( V_18 L_5 ,
V_21 -> V_22 ) ;
return NULL ;
}
return V_21 -> V_23 ( V_21 -> V_11 , V_19 , V_20 ) ;
}
void F_7 ( struct V_5 * V_6 , T_1 V_19 ,
void * V_24 , T_2 V_20 )
{
struct V_4 * V_21 ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_2 ) ;
return;
}
V_21 = F_3 ( V_6 ) ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_3 ) ;
return;
}
if ( V_21 -> V_11 == NULL ) {
F_5 ( V_18 L_4 , V_21 -> V_22 ) ;
return;
}
if ( V_21 -> V_25 == NULL ) {
F_5 ( V_18 L_6 ,
V_21 -> V_22 ) ;
return;
}
V_21 -> V_25 ( V_21 -> V_11 , V_19 , V_24 , V_20 ) ;
}
T_1 F_8 ( struct V_5 * V_6 )
{
int V_26 , V_27 ;
unsigned long long V_28 , V_19 ;
T_2 V_29 ;
T_3 V_30 , V_31 , V_32 ;
switch ( V_6 -> type ) {
case V_7 :
V_27 = F_9 ( V_6 , & V_26 , & V_28 , & V_19 ,
& V_30 , & V_31 , & V_32 ) ;
return V_19 ;
break;
case V_12 :
V_27 = F_10 ( V_6 , & V_26 , & V_28 , & V_19 ,
& V_29 , & V_30 , & V_31 ) ;
return V_19 ;
break;
case V_14 :
return 0 ;
break;
default:
F_5 ( V_18 L_1 ) ;
return 0 ;
break;
}
}
static int F_11 ( T_3 V_30 , unsigned long long V_33 ,
unsigned long long V_19 )
{
int V_27 = 0 ;
switch ( V_30 ) {
case V_34 :
if ( ( ( V_33 + V_19 ) > V_35 ) ||
( V_33 > V_35 ) )
V_27 = - V_36 ;
break;
case V_37 :
if ( ( ( V_33 + V_19 ) > V_38 ) ||
( V_33 > V_38 ) )
V_27 = - V_36 ;
break;
case V_39 :
if ( ( ( V_33 + V_19 ) > V_40 ) ||
( V_33 > V_40 ) )
V_27 = - V_36 ;
break;
case V_41 :
break;
case V_42 :
if ( ( ( V_33 + V_19 ) > V_43 ) ||
( V_33 > V_43 ) )
V_27 = - V_36 ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
default:
F_5 ( V_18 L_7 ) ;
V_27 = - V_48 ;
break;
}
return V_27 ;
}
struct V_5 * F_12 ( struct V_1 * V_49 , T_3 V_50 ,
T_3 V_31 )
{
struct V_4 * V_21 ;
struct V_51 * V_52 = NULL ;
struct V_13 * V_53 = NULL ;
struct V_13 * V_54 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_55;
}
F_13 (slave_pos, &bridge->slave_resources) {
V_54 = F_4 ( V_52 ,
struct V_13 , V_10 ) ;
if ( V_54 == NULL ) {
F_5 ( V_18 L_9 ) ;
continue;
}
F_14 ( & V_54 -> V_56 ) ;
if ( ( ( V_54 -> V_57 & V_50 ) == V_50 ) &&
( ( V_54 -> V_58 & V_31 ) == V_31 ) &&
( V_54 -> V_59 == 0 ) ) {
V_54 -> V_59 = 1 ;
F_15 ( & V_54 -> V_56 ) ;
V_53 = V_54 ;
break;
}
F_15 ( & V_54 -> V_56 ) ;
}
if ( V_53 == NULL )
goto V_60;
V_6 = F_16 ( sizeof( struct V_5 ) , V_61 ) ;
if ( V_6 == NULL ) {
F_5 ( V_62 L_10 ) ;
goto V_63;
}
V_6 -> type = V_12 ;
V_6 -> V_8 = & V_53 -> V_10 ;
return V_6 ;
V_63:
F_14 ( & V_54 -> V_56 ) ;
V_54 -> V_59 = 0 ;
F_15 ( & V_54 -> V_56 ) ;
V_60:
V_55:
return NULL ;
}
int F_17 ( struct V_5 * V_6 , int V_26 ,
unsigned long long V_33 , unsigned long long V_19 ,
T_2 V_29 , T_3 V_30 , T_3 V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_13 * V_64 ;
int V_27 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_13 , V_10 ) ;
if ( V_21 -> V_65 == NULL ) {
F_5 ( V_18 L_12 ) ;
return - V_66 ;
}
if ( ! ( ( ( V_64 -> V_57 & V_30 ) == V_30 ) &&
( ( V_64 -> V_58 & V_31 ) == V_31 ) ) ) {
F_5 ( V_18 L_13 ) ;
return - V_48 ;
}
V_27 = F_11 ( V_30 , V_33 , V_19 ) ;
if ( V_27 )
return V_27 ;
return V_21 -> V_65 ( V_64 , V_26 , V_33 , V_19 , V_29 ,
V_30 , V_31 ) ;
}
int F_10 ( struct V_5 * V_6 , int * V_26 ,
unsigned long long * V_33 , unsigned long long * V_19 ,
T_2 * V_29 , T_3 * V_30 , T_3 * V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_13 * V_64 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_13 , V_10 ) ;
if ( V_21 -> V_67 == NULL ) {
F_5 ( V_18 L_14 ) ;
return - V_48 ;
}
return V_21 -> V_67 ( V_64 , V_26 , V_33 , V_19 , V_29 ,
V_30 , V_31 ) ;
}
void F_18 ( struct V_5 * V_6 )
{
struct V_13 * V_54 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return;
}
V_54 = F_4 ( V_6 -> V_8 , struct V_13 ,
V_10 ) ;
if ( V_54 == NULL ) {
F_5 ( V_18 L_15 ) ;
return;
}
F_14 ( & V_54 -> V_56 ) ;
if ( V_54 -> V_59 == 0 )
F_5 ( V_18 L_16 ) ;
V_54 -> V_59 = 0 ;
F_15 ( & V_54 -> V_56 ) ;
F_19 ( V_6 ) ;
}
struct V_5 * F_20 ( struct V_1 * V_49 , T_3 V_50 ,
T_3 V_31 , T_3 V_32 )
{
struct V_4 * V_21 ;
struct V_51 * V_68 = NULL ;
struct V_9 * V_53 = NULL ;
struct V_9 * V_69 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_55;
}
F_13 (master_pos, &bridge->master_resources) {
V_69 = F_4 ( V_68 ,
struct V_9 , V_10 ) ;
if ( V_69 == NULL ) {
F_5 ( V_62 L_17 ) ;
continue;
}
F_21 ( & V_69 -> V_70 ) ;
if ( ( ( V_69 -> V_57 & V_50 ) == V_50 ) &&
( ( V_69 -> V_58 & V_31 ) == V_31 ) &&
( ( V_69 -> V_71 & V_32 ) == V_32 ) &&
( V_69 -> V_59 == 0 ) ) {
V_69 -> V_59 = 1 ;
F_22 ( & V_69 -> V_70 ) ;
V_53 = V_69 ;
break;
}
F_22 ( & V_69 -> V_70 ) ;
}
if ( V_53 == NULL ) {
F_5 ( V_18 L_18 ) ;
goto V_60;
}
V_6 = F_16 ( sizeof( struct V_5 ) , V_61 ) ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_10 ) ;
goto V_63;
}
V_6 -> type = V_7 ;
V_6 -> V_8 = & V_53 -> V_10 ;
return V_6 ;
V_63:
F_21 ( & V_69 -> V_70 ) ;
V_69 -> V_59 = 0 ;
F_22 ( & V_69 -> V_70 ) ;
V_60:
V_55:
return NULL ;
}
int F_23 ( struct V_5 * V_6 , int V_26 ,
unsigned long long V_33 , unsigned long long V_19 , T_3 V_30 ,
T_3 V_31 , T_3 V_32 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_64 ;
int V_27 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
if ( V_21 -> V_72 == NULL ) {
F_5 ( V_62 L_20 ) ;
return - V_48 ;
}
if ( ! ( ( ( V_64 -> V_57 & V_30 ) == V_30 ) &&
( ( V_64 -> V_58 & V_31 ) == V_31 ) &&
( ( V_64 -> V_71 & V_32 ) == V_32 ) ) ) {
F_5 ( V_62 L_13 ) ;
return - V_48 ;
}
V_27 = F_11 ( V_30 , V_33 , V_19 ) ;
if ( V_27 )
return V_27 ;
return V_21 -> V_72 ( V_64 , V_26 , V_33 , V_19 , V_30 ,
V_31 , V_32 ) ;
}
int F_9 ( struct V_5 * V_6 , int * V_26 ,
unsigned long long * V_33 , unsigned long long * V_19 , T_3 * V_30 ,
T_3 * V_31 , T_3 * V_32 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_64 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
if ( V_21 -> V_73 == NULL ) {
F_5 ( V_62 L_21 , V_74 ) ;
return - V_48 ;
}
return V_21 -> V_73 ( V_64 , V_26 , V_33 , V_19 , V_30 ,
V_31 , V_32 ) ;
}
T_4 F_24 ( struct V_5 * V_6 , void * V_75 , T_1 V_76 ,
T_5 V_77 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_64 ;
T_1 V_78 ;
if ( V_21 -> V_79 == NULL ) {
F_5 ( V_62 L_22 ) ;
return - V_48 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_78 = F_8 ( V_6 ) ;
if ( V_77 > V_78 ) {
F_5 ( V_62 L_23 ) ;
return - V_36 ;
}
if ( ( V_77 + V_76 ) > V_78 )
V_76 = V_78 - V_77 ;
return V_21 -> V_79 ( V_64 , V_75 , V_76 , V_77 ) ;
}
T_4 F_25 ( struct V_5 * V_6 , void * V_75 ,
T_1 V_76 , T_5 V_77 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_64 ;
T_1 V_78 ;
if ( V_21 -> V_80 == NULL ) {
F_5 ( V_62 L_24 ) ;
return - V_48 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_78 = F_8 ( V_6 ) ;
if ( V_77 > V_78 ) {
F_5 ( V_62 L_23 ) ;
return - V_36 ;
}
if ( ( V_77 + V_76 ) > V_78 )
V_76 = V_78 - V_77 ;
return V_21 -> V_80 ( V_64 , V_75 , V_76 , V_77 ) ;
}
unsigned int F_26 ( struct V_5 * V_6 , unsigned int V_81 ,
unsigned int V_82 , unsigned int V_83 , T_5 V_77 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_64 ;
if ( V_21 -> V_84 == NULL ) {
F_5 ( V_62 L_24 ) ;
return - V_48 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
return V_21 -> V_84 ( V_64 , V_81 , V_82 , V_83 , V_77 ) ;
}
void F_27 ( struct V_5 * V_6 )
{
struct V_9 * V_69 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return;
}
V_69 = F_4 ( V_6 -> V_8 , struct V_9 ,
V_10 ) ;
if ( V_69 == NULL ) {
F_5 ( V_18 L_25 ) ;
return;
}
F_21 ( & V_69 -> V_70 ) ;
if ( V_69 -> V_59 == 0 )
F_5 ( V_18 L_16 ) ;
V_69 -> V_59 = 0 ;
F_22 ( & V_69 -> V_70 ) ;
F_19 ( V_6 ) ;
}
struct V_5 * F_28 ( struct V_1 * V_49 , T_3 V_85 )
{
struct V_4 * V_21 ;
struct V_51 * V_86 = NULL ;
struct V_15 * V_87 = NULL ;
struct V_15 * V_88 = NULL ;
struct V_5 * V_6 = NULL ;
F_5 ( V_18 L_26 ) ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_55;
}
F_13 (dma_pos, &bridge->dma_resources) {
V_88 = F_4 ( V_86 ,
struct V_15 , V_10 ) ;
if ( V_88 == NULL ) {
F_5 ( V_18 L_27 ) ;
continue;
}
F_14 ( & V_88 -> V_56 ) ;
if ( ( ( V_88 -> V_89 & V_85 ) == V_85 ) &&
( V_88 -> V_59 == 0 ) ) {
V_88 -> V_59 = 1 ;
F_15 ( & V_88 -> V_56 ) ;
V_87 = V_88 ;
break;
}
F_15 ( & V_88 -> V_56 ) ;
}
if ( V_87 == NULL )
goto V_90;
V_6 = F_16 ( sizeof( struct V_5 ) , V_61 ) ;
if ( V_6 == NULL ) {
F_5 ( V_62 L_10 ) ;
goto V_63;
}
V_6 -> type = V_14 ;
V_6 -> V_8 = & V_87 -> V_10 ;
return V_6 ;
V_63:
F_14 ( & V_88 -> V_56 ) ;
V_88 -> V_59 = 0 ;
F_15 ( & V_88 -> V_56 ) ;
V_90:
V_55:
return NULL ;
}
struct V_91 * F_29 ( struct V_5 * V_6 )
{
struct V_15 * V_92 ;
struct V_91 * V_93 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_28 ) ;
return NULL ;
}
V_92 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
V_93 = F_16 ( sizeof( struct V_91 ) , V_61 ) ;
if ( V_93 == NULL ) {
F_5 ( V_18 L_29 ) ;
return NULL ;
}
F_30 ( & V_93 -> V_94 ) ;
V_93 -> V_11 = V_92 ;
F_31 ( & V_93 -> V_56 ) ;
return V_93 ;
}
struct V_95 * F_32 ( T_3 V_96 , T_3 type )
{
struct V_95 * V_97 ;
struct V_98 * V_99 ;
V_97 = F_16 ( sizeof( struct V_95 ) , V_61 ) ;
if ( V_97 == NULL ) {
F_5 ( V_18 L_30 ) ;
goto V_100;
}
V_99 = F_16 ( sizeof( struct V_98 ) , V_61 ) ;
if ( V_99 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_101;
}
V_97 -> type = V_102 ;
V_97 -> V_103 = ( void * ) V_99 ;
V_99 -> V_96 = V_96 ;
V_99 -> type = type ;
return V_97 ;
V_101:
F_19 ( V_97 ) ;
V_100:
return NULL ;
}
struct V_95 * F_33 ( T_2 V_50 )
{
struct V_95 * V_97 ;
struct V_104 * V_105 ;
V_97 = F_16 ( sizeof( struct V_95 ) , V_61 ) ;
if ( V_97 == NULL ) {
F_5 ( V_18 L_30 ) ;
goto V_100;
}
V_105 = F_16 ( sizeof( struct V_104 ) , V_61 ) ;
if ( V_105 == NULL ) {
F_5 ( V_18 L_32 ) ;
goto V_106;
}
V_97 -> type = V_107 ;
V_97 -> V_103 = ( void * ) V_105 ;
V_105 -> V_50 = V_50 ;
return V_97 ;
V_106:
F_19 ( V_97 ) ;
V_100:
return NULL ;
}
struct V_95 * F_34 ( unsigned long long V_50 ,
T_3 V_30 , T_3 V_31 , T_3 V_32 )
{
struct V_95 * V_97 ;
struct V_108 * V_109 ;
V_97 = F_16 (
sizeof( struct V_95 ) , V_61 ) ;
if ( V_97 == NULL ) {
F_5 ( V_18 L_30 ) ;
goto V_100;
}
V_109 = F_16 ( sizeof( struct V_108 ) , V_61 ) ;
if ( V_109 == NULL ) {
F_5 ( V_18 L_33 ) ;
goto V_110;
}
V_97 -> type = V_111 ;
V_97 -> V_103 = ( void * ) V_109 ;
V_109 -> V_50 = V_50 ;
V_109 -> V_30 = V_30 ;
V_109 -> V_31 = V_31 ;
V_109 -> V_32 = V_32 ;
return V_97 ;
V_110:
F_19 ( V_97 ) ;
V_100:
return NULL ;
}
void F_35 ( struct V_95 * V_97 )
{
F_19 ( V_97 -> V_103 ) ;
F_19 ( V_97 ) ;
}
int F_36 ( struct V_91 * V_10 , struct V_95 * V_112 ,
struct V_95 * V_113 , T_1 V_76 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_114 == NULL ) {
F_5 ( V_62 L_34 ) ;
return - V_48 ;
}
if ( ! F_37 ( & V_10 -> V_56 ) ) {
F_5 ( V_18 L_35 ) ;
return - V_48 ;
}
V_27 = V_21 -> V_114 ( V_10 , V_112 , V_113 , V_76 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
int F_38 ( struct V_91 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_115 == NULL ) {
F_5 ( V_18 L_36 ) ;
return - V_48 ;
}
F_14 ( & V_10 -> V_56 ) ;
V_27 = V_21 -> V_115 ( V_10 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
int F_39 ( struct V_91 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_116 == NULL ) {
F_5 ( V_62 L_37 ) ;
return - V_48 ;
}
if ( ! F_37 ( & V_10 -> V_56 ) ) {
F_5 ( V_18 L_38 ) ;
return - V_48 ;
}
V_27 = V_21 -> V_116 ( V_10 ) ;
if ( V_27 ) {
F_5 ( V_18 L_39 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
F_15 ( & V_10 -> V_56 ) ;
F_19 ( V_10 ) ;
return V_27 ;
}
int F_40 ( struct V_5 * V_6 )
{
struct V_15 * V_92 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_28 ) ;
return - V_48 ;
}
V_92 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
if ( ! F_37 ( & V_92 -> V_56 ) ) {
F_5 ( V_18 L_40 ) ;
return - V_117 ;
}
if ( ! ( F_41 ( & V_92 -> V_118 ) && F_41 ( & V_92 -> V_119 ) ) ) {
F_5 ( V_62 L_41 ) ;
F_15 ( & V_92 -> V_56 ) ;
return - V_117 ;
}
V_92 -> V_59 = 0 ;
F_15 ( & V_92 -> V_56 ) ;
F_19 ( V_6 ) ;
return 0 ;
}
void F_42 ( struct V_4 * V_21 , int V_120 , int V_121 )
{
void (* F_43)( int , int , void * );
void * V_122 ;
F_43 = V_21 -> V_123 [ V_120 - 1 ] . V_124 [ V_121 ] . V_125 ;
V_122 = V_21 -> V_123 [ V_120 - 1 ] . V_124 [ V_121 ] . V_122 ;
if ( F_43 != NULL )
F_43 ( V_120 , V_121 , V_122 ) ;
else
F_5 ( V_62 L_42 ,
V_120 , V_121 ) ;
}
int F_44 ( struct V_1 * V_49 , int V_120 , int V_121 ,
void (* V_124)( int , int , void * ) ,
void * V_122 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_48 ;
}
if ( ( V_120 < 1 ) || ( V_120 > 7 ) ) {
F_5 ( V_18 L_43 ) ;
return - V_48 ;
}
if ( V_21 -> V_126 == NULL ) {
F_5 ( V_18 L_44 ) ;
return - V_48 ;
}
F_14 ( & V_21 -> V_127 ) ;
if ( V_21 -> V_123 [ V_120 - 1 ] . V_124 [ V_121 ] . V_125 ) {
F_15 ( & V_21 -> V_127 ) ;
F_5 ( V_62 L_45 ) ;
return - V_117 ;
}
V_21 -> V_123 [ V_120 - 1 ] . V_76 ++ ;
V_21 -> V_123 [ V_120 - 1 ] . V_124 [ V_121 ] . V_122 = V_122 ;
V_21 -> V_123 [ V_120 - 1 ] . V_124 [ V_121 ] . V_125 = V_124 ;
V_21 -> V_126 ( V_21 , V_120 , 1 , 1 ) ;
F_15 ( & V_21 -> V_127 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_49 , int V_120 , int V_121 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return;
}
if ( ( V_120 < 1 ) || ( V_120 > 7 ) ) {
F_5 ( V_18 L_43 ) ;
return;
}
if ( V_21 -> V_126 == NULL ) {
F_5 ( V_18 L_44 ) ;
return;
}
F_14 ( & V_21 -> V_127 ) ;
V_21 -> V_123 [ V_120 - 1 ] . V_76 -- ;
if ( V_21 -> V_123 [ V_120 - 1 ] . V_76 == 0 )
V_21 -> V_126 ( V_21 , V_120 , 0 , 1 ) ;
V_21 -> V_123 [ V_120 - 1 ] . V_124 [ V_121 ] . V_125 = NULL ;
V_21 -> V_123 [ V_120 - 1 ] . V_124 [ V_121 ] . V_122 = NULL ;
F_15 ( & V_21 -> V_127 ) ;
}
int F_46 ( struct V_1 * V_49 , int V_120 , int V_121 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_48 ;
}
if ( ( V_120 < 1 ) || ( V_120 > 7 ) ) {
F_5 ( V_62 L_43 ) ;
return - V_48 ;
}
if ( V_21 -> V_128 == NULL ) {
F_5 ( V_62 L_46 ) ;
return - V_48 ;
}
return V_21 -> V_128 ( V_21 , V_120 , V_121 ) ;
}
struct V_5 * F_47 ( struct V_1 * V_49 )
{
struct V_4 * V_21 ;
struct V_51 * V_129 = NULL ;
struct V_17 * V_130 = NULL ;
struct V_17 * V_131 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_55;
}
F_13 (lm_pos, &bridge->lm_resources) {
V_131 = F_4 ( V_129 ,
struct V_17 , V_10 ) ;
if ( V_131 == NULL ) {
F_5 ( V_18 L_47 ) ;
continue;
}
F_14 ( & V_131 -> V_56 ) ;
if ( V_131 -> V_59 == 0 ) {
V_131 -> V_59 = 1 ;
F_15 ( & V_131 -> V_56 ) ;
V_130 = V_131 ;
break;
}
F_15 ( & V_131 -> V_56 ) ;
}
if ( V_130 == NULL )
goto V_132;
V_6 = F_16 ( sizeof( struct V_5 ) , V_61 ) ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_10 ) ;
goto V_63;
}
V_6 -> type = V_16 ;
V_6 -> V_8 = & V_130 -> V_10 ;
return V_6 ;
V_63:
F_14 ( & V_131 -> V_56 ) ;
V_131 -> V_59 = 0 ;
F_15 ( & V_131 -> V_56 ) ;
V_132:
V_55:
return NULL ;
}
int F_48 ( struct V_5 * V_6 )
{
struct V_17 * V_131 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_48 ) ;
return - V_48 ;
}
V_131 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
return V_131 -> V_133 ;
}
int F_49 ( struct V_5 * V_6 , unsigned long long V_134 ,
T_3 V_30 , T_3 V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_131 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_48 ) ;
return - V_48 ;
}
V_131 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_135 == NULL ) {
F_5 ( V_18 L_49 ) ;
return - V_48 ;
}
return V_21 -> V_135 ( V_131 , V_134 , V_30 , V_31 ) ;
}
int F_50 ( struct V_5 * V_6 , unsigned long long * V_134 ,
T_3 * V_30 , T_3 * V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_131 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_48 ) ;
return - V_48 ;
}
V_131 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_136 == NULL ) {
F_5 ( V_18 L_50 ) ;
return - V_48 ;
}
return V_21 -> V_136 ( V_131 , V_134 , V_30 , V_31 ) ;
}
int F_51 ( struct V_5 * V_6 , int V_137 ,
void (* V_124)( int ) )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_131 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_48 ) ;
return - V_48 ;
}
V_131 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_138 == NULL ) {
F_5 ( V_18 L_51 ) ;
return - V_48 ;
}
return V_21 -> V_138 ( V_131 , V_137 , V_124 ) ;
}
int F_52 ( struct V_5 * V_6 , int V_137 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_131 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_48 ) ;
return - V_48 ;
}
V_131 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_139 == NULL ) {
F_5 ( V_18 L_52 ) ;
return - V_48 ;
}
return V_21 -> V_139 ( V_131 , V_137 ) ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_17 * V_131 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_48 ) ;
return;
}
V_131 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
F_14 ( & V_131 -> V_56 ) ;
V_131 -> V_59 = 0 ;
F_15 ( & V_131 -> V_56 ) ;
F_19 ( V_6 ) ;
}
int F_54 ( struct V_1 * V_49 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_48 ;
}
if ( V_21 -> V_140 == NULL ) {
F_5 ( V_62 L_53 ) ;
return - V_48 ;
}
return V_21 -> V_140 ( V_21 ) ;
}
int F_55 ( struct V_1 * V_49 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_56 ( L_8 ) ;
return - V_48 ;
}
return V_21 -> V_141 ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_19 ( F_1 ( V_3 ) ) ;
}
int F_58 ( struct V_4 * V_21 )
{
int V_142 ;
int V_143 = - 1 ;
F_14 ( & V_144 ) ;
for ( V_142 = 0 ; V_142 < sizeof( V_145 ) * 8 ; V_142 ++ ) {
if ( ( V_145 & ( 1 << V_142 ) ) == 0 ) {
V_145 |= ( 1 << V_142 ) ;
V_21 -> V_141 = V_142 ;
F_30 ( & V_21 -> V_146 ) ;
F_59 ( & V_21 -> V_147 , & V_148 ) ;
V_143 = 0 ;
break;
}
}
F_15 ( & V_144 ) ;
return V_143 ;
}
void F_60 ( struct V_4 * V_21 )
{
struct V_1 * V_49 ;
struct V_1 * V_149 ;
F_14 ( & V_144 ) ;
V_145 &= ~ ( 1 << V_21 -> V_141 ) ;
F_61 (vdev, tmp, &bridge->devices, bridge_list) {
F_62 ( & V_49 -> V_150 ) ;
F_62 ( & V_49 -> V_151 ) ;
F_63 ( & V_49 -> V_3 ) ;
}
F_62 ( & V_21 -> V_147 ) ;
F_15 ( & V_144 ) ;
}
static int F_64 ( struct V_152 * V_153 ,
struct V_4 * V_21 , unsigned int V_154 )
{
int V_155 ;
unsigned int V_142 ;
struct V_1 * V_49 ;
struct V_1 * V_149 ;
for ( V_142 = 0 ; V_142 < V_154 ; V_142 ++ ) {
V_49 = F_65 ( sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_49 ) {
V_155 = - V_156 ;
goto V_157;
}
V_49 -> V_141 = V_142 ;
V_49 -> V_21 = V_21 ;
V_49 -> V_3 . V_158 = V_153 ;
V_49 -> V_3 . V_159 = F_57 ;
V_49 -> V_3 . V_11 = V_21 -> V_11 ;
V_49 -> V_3 . V_160 = & V_161 ;
F_66 ( & V_49 -> V_3 , L_54 , V_153 -> V_22 , V_21 -> V_141 ,
V_49 -> V_141 ) ;
V_155 = F_67 ( & V_49 -> V_3 ) ;
if ( V_155 )
goto V_162;
if ( V_49 -> V_3 . V_158 ) {
F_59 ( & V_49 -> V_150 , & V_153 -> V_146 ) ;
F_59 ( & V_49 -> V_151 , & V_21 -> V_146 ) ;
} else
F_63 ( & V_49 -> V_3 ) ;
}
return 0 ;
V_162:
F_68 ( & V_49 -> V_3 ) ;
F_19 ( V_49 ) ;
V_157:
F_61 (vdev, tmp, &drv->devices, drv_list) {
F_62 ( & V_49 -> V_150 ) ;
F_62 ( & V_49 -> V_151 ) ;
F_63 ( & V_49 -> V_3 ) ;
}
return V_155 ;
}
static int F_69 ( struct V_152 * V_153 , unsigned int V_154 )
{
struct V_4 * V_21 ;
int V_155 = 0 ;
F_14 ( & V_144 ) ;
F_70 (bridge, &vme_bus_list, bus_list) {
V_155 = F_64 ( V_153 , V_21 , V_154 ) ;
if ( V_155 )
break;
}
F_15 ( & V_144 ) ;
return V_155 ;
}
int F_71 ( struct V_152 * V_153 , unsigned int V_154 )
{
int V_155 ;
V_153 -> V_163 . V_22 = V_153 -> V_22 ;
V_153 -> V_163 . V_160 = & V_161 ;
F_30 ( & V_153 -> V_146 ) ;
V_155 = F_72 ( & V_153 -> V_163 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_69 ( V_153 , V_154 ) ;
if ( V_155 )
F_73 ( & V_153 -> V_163 ) ;
return V_155 ;
}
void F_74 ( struct V_152 * V_153 )
{
struct V_1 * V_3 , * V_164 ;
F_14 ( & V_144 ) ;
F_61 (dev, dev_tmp, &drv->devices, drv_list) {
F_62 ( & V_3 -> V_150 ) ;
F_62 ( & V_3 -> V_151 ) ;
F_63 ( & V_3 -> V_3 ) ;
}
F_15 ( & V_144 ) ;
F_73 ( & V_153 -> V_163 ) ;
}
static int F_75 ( struct V_2 * V_3 , struct V_165 * V_153 )
{
struct V_152 * V_166 ;
V_166 = F_2 ( V_153 , struct V_152 , V_163 ) ;
if ( V_3 -> V_158 == V_166 ) {
struct V_1 * V_49 = F_1 ( V_3 ) ;
if ( V_166 -> V_167 && V_166 -> V_167 ( V_49 ) )
return 1 ;
V_3 -> V_158 = NULL ;
}
return 0 ;
}
static int F_76 ( struct V_2 * V_3 )
{
int V_27 = - V_168 ;
struct V_152 * V_163 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
V_163 = V_3 -> V_158 ;
if ( V_163 -> V_169 != NULL )
V_27 = V_163 -> V_169 ( V_49 ) ;
return V_27 ;
}
static int F_77 ( struct V_2 * V_3 )
{
int V_27 = - V_168 ;
struct V_152 * V_163 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
V_163 = V_3 -> V_158 ;
if ( V_163 -> remove != NULL )
V_27 = V_163 -> remove ( V_49 ) ;
return V_27 ;
}
static int T_6 F_78 ( void )
{
return F_79 ( & V_161 ) ;
}
static void T_7 F_80 ( void )
{
F_81 ( & V_161 ) ;
}
