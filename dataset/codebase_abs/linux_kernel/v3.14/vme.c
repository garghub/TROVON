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
F_5 ( V_62 L_20 ) ;
return - V_48 ;
}
return V_21 -> V_73 ( V_64 , V_26 , V_33 , V_19 , V_30 ,
V_31 , V_32 ) ;
}
T_4 F_24 ( struct V_5 * V_6 , void * V_74 , T_1 V_75 ,
T_5 V_76 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_64 ;
T_1 V_77 ;
if ( V_21 -> V_78 == NULL ) {
F_5 ( V_62 L_21 ) ;
return - V_48 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_77 = F_8 ( V_6 ) ;
if ( V_76 > V_77 ) {
F_5 ( V_62 L_22 ) ;
return - V_36 ;
}
if ( ( V_76 + V_75 ) > V_77 )
V_75 = V_77 - V_76 ;
return V_21 -> V_78 ( V_64 , V_74 , V_75 , V_76 ) ;
}
T_4 F_25 ( struct V_5 * V_6 , void * V_74 ,
T_1 V_75 , T_5 V_76 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_64 ;
T_1 V_77 ;
if ( V_21 -> V_79 == NULL ) {
F_5 ( V_62 L_23 ) ;
return - V_48 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_77 = F_8 ( V_6 ) ;
if ( V_76 > V_77 ) {
F_5 ( V_62 L_22 ) ;
return - V_36 ;
}
if ( ( V_76 + V_75 ) > V_77 )
V_75 = V_77 - V_76 ;
return V_21 -> V_79 ( V_64 , V_74 , V_75 , V_76 ) ;
}
unsigned int F_26 ( struct V_5 * V_6 , unsigned int V_80 ,
unsigned int V_81 , unsigned int V_82 , T_5 V_76 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_64 ;
if ( V_21 -> V_83 == NULL ) {
F_5 ( V_62 L_23 ) ;
return - V_48 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
return V_21 -> V_83 ( V_64 , V_80 , V_81 , V_82 , V_76 ) ;
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
F_5 ( V_18 L_24 ) ;
return;
}
F_21 ( & V_69 -> V_70 ) ;
if ( V_69 -> V_59 == 0 )
F_5 ( V_18 L_16 ) ;
V_69 -> V_59 = 0 ;
F_22 ( & V_69 -> V_70 ) ;
F_19 ( V_6 ) ;
}
struct V_5 * F_28 ( struct V_1 * V_49 , T_3 V_84 )
{
struct V_4 * V_21 ;
struct V_51 * V_85 = NULL ;
struct V_15 * V_86 = NULL ;
struct V_15 * V_87 = NULL ;
struct V_5 * V_6 = NULL ;
F_5 ( V_18 L_25 ) ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_55;
}
F_13 (dma_pos, &bridge->dma_resources) {
V_87 = F_4 ( V_85 ,
struct V_15 , V_10 ) ;
if ( V_87 == NULL ) {
F_5 ( V_18 L_26 ) ;
continue;
}
F_14 ( & V_87 -> V_56 ) ;
if ( ( ( V_87 -> V_88 & V_84 ) == V_84 ) &&
( V_87 -> V_59 == 0 ) ) {
V_87 -> V_59 = 1 ;
F_15 ( & V_87 -> V_56 ) ;
V_86 = V_87 ;
break;
}
F_15 ( & V_87 -> V_56 ) ;
}
if ( V_86 == NULL )
goto V_89;
V_6 = F_16 ( sizeof( struct V_5 ) , V_61 ) ;
if ( V_6 == NULL ) {
F_5 ( V_62 L_10 ) ;
goto V_63;
}
V_6 -> type = V_14 ;
V_6 -> V_8 = & V_86 -> V_10 ;
return V_6 ;
V_63:
F_14 ( & V_87 -> V_56 ) ;
V_87 -> V_59 = 0 ;
F_15 ( & V_87 -> V_56 ) ;
V_89:
V_55:
return NULL ;
}
struct V_90 * F_29 ( struct V_5 * V_6 )
{
struct V_15 * V_91 ;
struct V_90 * V_92 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_27 ) ;
return NULL ;
}
V_91 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
V_92 = F_16 ( sizeof( struct V_90 ) , V_61 ) ;
if ( V_92 == NULL ) {
F_5 ( V_18 L_28 ) ;
return NULL ;
}
F_30 ( & V_92 -> V_93 ) ;
V_92 -> V_11 = V_91 ;
F_31 ( & V_92 -> V_56 ) ;
return V_92 ;
}
struct V_94 * F_32 ( T_3 V_95 , T_3 type )
{
struct V_94 * V_96 ;
struct V_97 * V_98 ;
V_96 = F_16 ( sizeof( struct V_94 ) , V_61 ) ;
if ( V_96 == NULL ) {
F_5 ( V_18 L_29 ) ;
goto V_99;
}
V_98 = F_16 ( sizeof( struct V_97 ) , V_61 ) ;
if ( V_98 == NULL ) {
F_5 ( V_18 L_30 ) ;
goto V_100;
}
V_96 -> type = V_101 ;
V_96 -> V_102 = ( void * ) V_98 ;
V_98 -> V_95 = V_95 ;
V_98 -> type = type ;
return V_96 ;
V_100:
F_19 ( V_96 ) ;
V_99:
return NULL ;
}
struct V_94 * F_33 ( T_2 V_50 )
{
struct V_94 * V_96 ;
struct V_103 * V_104 ;
V_96 = F_16 ( sizeof( struct V_94 ) , V_61 ) ;
if ( V_96 == NULL ) {
F_5 ( V_18 L_29 ) ;
goto V_99;
}
V_104 = F_16 ( sizeof( struct V_103 ) , V_61 ) ;
if ( V_104 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_105;
}
V_96 -> type = V_106 ;
V_96 -> V_102 = ( void * ) V_104 ;
V_104 -> V_50 = V_50 ;
return V_96 ;
V_105:
F_19 ( V_96 ) ;
V_99:
return NULL ;
}
struct V_94 * F_34 ( unsigned long long V_50 ,
T_3 V_30 , T_3 V_31 , T_3 V_32 )
{
struct V_94 * V_96 ;
struct V_107 * V_108 ;
V_96 = F_16 (
sizeof( struct V_94 ) , V_61 ) ;
if ( V_96 == NULL ) {
F_5 ( V_18 L_29 ) ;
goto V_99;
}
V_108 = F_16 ( sizeof( struct V_107 ) , V_61 ) ;
if ( V_108 == NULL ) {
F_5 ( V_18 L_32 ) ;
goto V_109;
}
V_96 -> type = V_110 ;
V_96 -> V_102 = ( void * ) V_108 ;
V_108 -> V_50 = V_50 ;
V_108 -> V_30 = V_30 ;
V_108 -> V_31 = V_31 ;
V_108 -> V_32 = V_32 ;
return V_96 ;
V_109:
F_19 ( V_96 ) ;
V_99:
return NULL ;
}
void F_35 ( struct V_94 * V_96 )
{
F_19 ( V_96 -> V_102 ) ;
F_19 ( V_96 ) ;
}
int F_36 ( struct V_90 * V_10 , struct V_94 * V_111 ,
struct V_94 * V_112 , T_1 V_75 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_113 == NULL ) {
F_5 ( V_62 L_33 ) ;
return - V_48 ;
}
if ( ! F_37 ( & V_10 -> V_56 ) ) {
F_5 ( V_18 L_34 ) ;
return - V_48 ;
}
V_27 = V_21 -> V_113 ( V_10 , V_111 , V_112 , V_75 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
int F_38 ( struct V_90 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_114 == NULL ) {
F_5 ( V_18 L_35 ) ;
return - V_48 ;
}
F_14 ( & V_10 -> V_56 ) ;
V_27 = V_21 -> V_114 ( V_10 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
int F_39 ( struct V_90 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_115 == NULL ) {
F_5 ( V_62 L_36 ) ;
return - V_48 ;
}
if ( ! F_37 ( & V_10 -> V_56 ) ) {
F_5 ( V_18 L_37 ) ;
return - V_48 ;
}
V_27 = V_21 -> V_115 ( V_10 ) ;
if ( V_27 ) {
F_5 ( V_18 L_38 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
F_15 ( & V_10 -> V_56 ) ;
F_19 ( V_10 ) ;
return V_27 ;
}
int F_40 ( struct V_5 * V_6 )
{
struct V_15 * V_91 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_27 ) ;
return - V_48 ;
}
V_91 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
if ( ! F_37 ( & V_91 -> V_56 ) ) {
F_5 ( V_18 L_39 ) ;
return - V_116 ;
}
if ( ! ( F_41 ( & V_91 -> V_117 ) && F_41 ( & V_91 -> V_118 ) ) ) {
F_5 ( V_62 L_40 ) ;
F_15 ( & V_91 -> V_56 ) ;
return - V_116 ;
}
V_91 -> V_59 = 0 ;
F_15 ( & V_91 -> V_56 ) ;
F_19 ( V_6 ) ;
return 0 ;
}
void F_42 ( struct V_4 * V_21 , int V_119 , int V_120 )
{
void (* F_43)( int , int , void * );
void * V_121 ;
F_43 = V_21 -> V_122 [ V_119 - 1 ] . V_123 [ V_120 ] . V_124 ;
V_121 = V_21 -> V_122 [ V_119 - 1 ] . V_123 [ V_120 ] . V_121 ;
if ( F_43 != NULL )
F_43 ( V_119 , V_120 , V_121 ) ;
else
F_5 ( V_62 L_41 ,
V_119 , V_120 ) ;
}
int F_44 ( struct V_1 * V_49 , int V_119 , int V_120 ,
void (* V_123)( int , int , void * ) ,
void * V_121 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_48 ;
}
if ( ( V_119 < 1 ) || ( V_119 > 7 ) ) {
F_5 ( V_18 L_42 ) ;
return - V_48 ;
}
if ( V_21 -> V_125 == NULL ) {
F_5 ( V_18 L_43 ) ;
return - V_48 ;
}
F_14 ( & V_21 -> V_126 ) ;
if ( V_21 -> V_122 [ V_119 - 1 ] . V_123 [ V_120 ] . V_124 ) {
F_15 ( & V_21 -> V_126 ) ;
F_5 ( V_62 L_44 ) ;
return - V_116 ;
}
V_21 -> V_122 [ V_119 - 1 ] . V_75 ++ ;
V_21 -> V_122 [ V_119 - 1 ] . V_123 [ V_120 ] . V_121 = V_121 ;
V_21 -> V_122 [ V_119 - 1 ] . V_123 [ V_120 ] . V_124 = V_123 ;
V_21 -> V_125 ( V_21 , V_119 , 1 , 1 ) ;
F_15 ( & V_21 -> V_126 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_49 , int V_119 , int V_120 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return;
}
if ( ( V_119 < 1 ) || ( V_119 > 7 ) ) {
F_5 ( V_18 L_42 ) ;
return;
}
if ( V_21 -> V_125 == NULL ) {
F_5 ( V_18 L_43 ) ;
return;
}
F_14 ( & V_21 -> V_126 ) ;
V_21 -> V_122 [ V_119 - 1 ] . V_75 -- ;
if ( V_21 -> V_122 [ V_119 - 1 ] . V_75 == 0 )
V_21 -> V_125 ( V_21 , V_119 , 0 , 1 ) ;
V_21 -> V_122 [ V_119 - 1 ] . V_123 [ V_120 ] . V_124 = NULL ;
V_21 -> V_122 [ V_119 - 1 ] . V_123 [ V_120 ] . V_121 = NULL ;
F_15 ( & V_21 -> V_126 ) ;
}
int F_46 ( struct V_1 * V_49 , int V_119 , int V_120 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_48 ;
}
if ( ( V_119 < 1 ) || ( V_119 > 7 ) ) {
F_5 ( V_62 L_42 ) ;
return - V_48 ;
}
if ( V_21 -> V_127 == NULL ) {
F_5 ( V_62 L_45 ) ;
return - V_48 ;
}
return V_21 -> V_127 ( V_21 , V_119 , V_120 ) ;
}
struct V_5 * F_47 ( struct V_1 * V_49 )
{
struct V_4 * V_21 ;
struct V_51 * V_128 = NULL ;
struct V_17 * V_129 = NULL ;
struct V_17 * V_130 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_55;
}
F_13 (lm_pos, &bridge->lm_resources) {
V_130 = F_4 ( V_128 ,
struct V_17 , V_10 ) ;
if ( V_130 == NULL ) {
F_5 ( V_18 L_46 ) ;
continue;
}
F_14 ( & V_130 -> V_56 ) ;
if ( V_130 -> V_59 == 0 ) {
V_130 -> V_59 = 1 ;
F_15 ( & V_130 -> V_56 ) ;
V_129 = V_130 ;
break;
}
F_15 ( & V_130 -> V_56 ) ;
}
if ( V_129 == NULL )
goto V_131;
V_6 = F_16 ( sizeof( struct V_5 ) , V_61 ) ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_10 ) ;
goto V_63;
}
V_6 -> type = V_16 ;
V_6 -> V_8 = & V_129 -> V_10 ;
return V_6 ;
V_63:
F_14 ( & V_130 -> V_56 ) ;
V_130 -> V_59 = 0 ;
F_15 ( & V_130 -> V_56 ) ;
V_131:
V_55:
return NULL ;
}
int F_48 ( struct V_5 * V_6 )
{
struct V_17 * V_130 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_47 ) ;
return - V_48 ;
}
V_130 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
return V_130 -> V_132 ;
}
int F_49 ( struct V_5 * V_6 , unsigned long long V_133 ,
T_3 V_30 , T_3 V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_130 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_47 ) ;
return - V_48 ;
}
V_130 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_134 == NULL ) {
F_5 ( V_18 L_48 ) ;
return - V_48 ;
}
return V_21 -> V_134 ( V_130 , V_133 , V_30 , V_31 ) ;
}
int F_50 ( struct V_5 * V_6 , unsigned long long * V_133 ,
T_3 * V_30 , T_3 * V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_130 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_47 ) ;
return - V_48 ;
}
V_130 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_135 == NULL ) {
F_5 ( V_18 L_49 ) ;
return - V_48 ;
}
return V_21 -> V_135 ( V_130 , V_133 , V_30 , V_31 ) ;
}
int F_51 ( struct V_5 * V_6 , int V_136 ,
void (* V_123)( int ) )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_130 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_47 ) ;
return - V_48 ;
}
V_130 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_137 == NULL ) {
F_5 ( V_18 L_50 ) ;
return - V_48 ;
}
return V_21 -> V_137 ( V_130 , V_136 , V_123 ) ;
}
int F_52 ( struct V_5 * V_6 , int V_136 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_130 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_47 ) ;
return - V_48 ;
}
V_130 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_138 == NULL ) {
F_5 ( V_18 L_51 ) ;
return - V_48 ;
}
return V_21 -> V_138 ( V_130 , V_136 ) ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_17 * V_130 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_47 ) ;
return;
}
V_130 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
F_14 ( & V_130 -> V_56 ) ;
V_130 -> V_59 = 0 ;
F_15 ( & V_130 -> V_56 ) ;
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
if ( V_21 -> V_139 == NULL ) {
F_5 ( V_62 L_52 ) ;
return - V_48 ;
}
return V_21 -> V_139 ( V_21 ) ;
}
int F_55 ( struct V_1 * V_49 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_56 ( L_8 ) ;
return - V_48 ;
}
return V_21 -> V_140 ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_19 ( F_1 ( V_3 ) ) ;
}
int F_58 ( struct V_4 * V_21 )
{
int V_141 ;
int V_142 = - 1 ;
F_14 ( & V_143 ) ;
for ( V_141 = 0 ; V_141 < sizeof( V_144 ) * 8 ; V_141 ++ ) {
if ( ( V_144 & ( 1 << V_141 ) ) == 0 ) {
V_144 |= ( 1 << V_141 ) ;
V_21 -> V_140 = V_141 ;
F_30 ( & V_21 -> V_145 ) ;
F_59 ( & V_21 -> V_146 , & V_147 ) ;
V_142 = 0 ;
break;
}
}
F_15 ( & V_143 ) ;
return V_142 ;
}
void F_60 ( struct V_4 * V_21 )
{
struct V_1 * V_49 ;
struct V_1 * V_148 ;
F_14 ( & V_143 ) ;
V_144 &= ~ ( 1 << V_21 -> V_140 ) ;
F_61 (vdev, tmp, &bridge->devices, bridge_list) {
F_62 ( & V_49 -> V_149 ) ;
F_62 ( & V_49 -> V_150 ) ;
F_63 ( & V_49 -> V_3 ) ;
}
F_62 ( & V_21 -> V_146 ) ;
F_15 ( & V_143 ) ;
}
static int F_64 ( struct V_151 * V_152 ,
struct V_4 * V_21 , unsigned int V_153 )
{
int V_154 ;
unsigned int V_141 ;
struct V_1 * V_49 ;
struct V_1 * V_148 ;
for ( V_141 = 0 ; V_141 < V_153 ; V_141 ++ ) {
V_49 = F_65 ( sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_49 ) {
V_154 = - V_155 ;
goto V_156;
}
V_49 -> V_140 = V_141 ;
V_49 -> V_21 = V_21 ;
V_49 -> V_3 . V_157 = V_152 ;
V_49 -> V_3 . V_158 = F_57 ;
V_49 -> V_3 . V_11 = V_21 -> V_11 ;
V_49 -> V_3 . V_159 = & V_160 ;
F_66 ( & V_49 -> V_3 , L_53 , V_152 -> V_22 , V_21 -> V_140 ,
V_49 -> V_140 ) ;
V_154 = F_67 ( & V_49 -> V_3 ) ;
if ( V_154 )
goto V_161;
if ( V_49 -> V_3 . V_157 ) {
F_59 ( & V_49 -> V_149 , & V_152 -> V_145 ) ;
F_59 ( & V_49 -> V_150 , & V_21 -> V_145 ) ;
} else
F_63 ( & V_49 -> V_3 ) ;
}
return 0 ;
V_161:
F_68 ( & V_49 -> V_3 ) ;
F_19 ( V_49 ) ;
V_156:
F_61 (vdev, tmp, &drv->devices, drv_list) {
F_62 ( & V_49 -> V_149 ) ;
F_62 ( & V_49 -> V_150 ) ;
F_63 ( & V_49 -> V_3 ) ;
}
return V_154 ;
}
static int F_69 ( struct V_151 * V_152 , unsigned int V_153 )
{
struct V_4 * V_21 ;
int V_154 = 0 ;
F_14 ( & V_143 ) ;
F_70 (bridge, &vme_bus_list, bus_list) {
V_154 = F_64 ( V_152 , V_21 , V_153 ) ;
if ( V_154 )
break;
}
F_15 ( & V_143 ) ;
return V_154 ;
}
int F_71 ( struct V_151 * V_152 , unsigned int V_153 )
{
int V_154 ;
V_152 -> V_162 . V_22 = V_152 -> V_22 ;
V_152 -> V_162 . V_159 = & V_160 ;
F_30 ( & V_152 -> V_145 ) ;
V_154 = F_72 ( & V_152 -> V_162 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_69 ( V_152 , V_153 ) ;
if ( V_154 )
F_73 ( & V_152 -> V_162 ) ;
return V_154 ;
}
void F_74 ( struct V_151 * V_152 )
{
struct V_1 * V_3 , * V_163 ;
F_14 ( & V_143 ) ;
F_61 (dev, dev_tmp, &drv->devices, drv_list) {
F_62 ( & V_3 -> V_149 ) ;
F_62 ( & V_3 -> V_150 ) ;
F_63 ( & V_3 -> V_3 ) ;
}
F_15 ( & V_143 ) ;
F_73 ( & V_152 -> V_162 ) ;
}
static int F_75 ( struct V_2 * V_3 , struct V_164 * V_152 )
{
struct V_151 * V_165 ;
V_165 = F_2 ( V_152 , struct V_151 , V_162 ) ;
if ( V_3 -> V_157 == V_165 ) {
struct V_1 * V_49 = F_1 ( V_3 ) ;
if ( V_165 -> V_166 && V_165 -> V_166 ( V_49 ) )
return 1 ;
V_3 -> V_157 = NULL ;
}
return 0 ;
}
static int F_76 ( struct V_2 * V_3 )
{
int V_27 = - V_167 ;
struct V_151 * V_162 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
V_162 = V_3 -> V_157 ;
if ( V_162 -> V_168 != NULL )
V_27 = V_162 -> V_168 ( V_49 ) ;
return V_27 ;
}
static int F_77 ( struct V_2 * V_3 )
{
int V_27 = - V_167 ;
struct V_151 * V_162 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
V_162 = V_3 -> V_157 ;
if ( V_162 -> remove != NULL )
V_27 = V_162 -> remove ( V_49 ) ;
return V_27 ;
}
static int T_6 F_78 ( void )
{
return F_79 ( & V_160 ) ;
}
static void T_7 F_80 ( void )
{
F_81 ( & V_160 ) ;
}
