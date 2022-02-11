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
int F_11 ( T_3 V_30 , unsigned long long V_33 ,
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
if ( ( V_19 != 0 ) && ( V_33 > V_42 + 1 - V_19 ) )
V_27 = - V_36 ;
break;
case V_43 :
if ( ( ( V_33 + V_19 ) > V_44 ) ||
( V_33 > V_44 ) )
V_27 = - V_36 ;
break;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
break;
default:
F_5 ( V_18 L_7 ) ;
V_27 = - V_49 ;
break;
}
return V_27 ;
}
struct V_5 * F_12 ( struct V_1 * V_50 , T_3 V_51 ,
T_3 V_31 )
{
struct V_4 * V_21 ;
struct V_52 * V_53 = NULL ;
struct V_13 * V_54 = NULL ;
struct V_13 * V_55 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_56;
}
F_13 (slave_pos, &bridge->slave_resources) {
V_55 = F_4 ( V_53 ,
struct V_13 , V_10 ) ;
if ( V_55 == NULL ) {
F_5 ( V_18 L_9 ) ;
continue;
}
F_14 ( & V_55 -> V_57 ) ;
if ( ( ( V_55 -> V_58 & V_51 ) == V_51 ) &&
( ( V_55 -> V_59 & V_31 ) == V_31 ) &&
( V_55 -> V_60 == 0 ) ) {
V_55 -> V_60 = 1 ;
F_15 ( & V_55 -> V_57 ) ;
V_54 = V_55 ;
break;
}
F_15 ( & V_55 -> V_57 ) ;
}
if ( V_54 == NULL )
goto V_61;
V_6 = F_16 ( sizeof( struct V_5 ) , V_62 ) ;
if ( V_6 == NULL ) {
F_5 ( V_63 L_10 ) ;
goto V_64;
}
V_6 -> type = V_12 ;
V_6 -> V_8 = & V_54 -> V_10 ;
return V_6 ;
V_64:
F_14 ( & V_55 -> V_57 ) ;
V_55 -> V_60 = 0 ;
F_15 ( & V_55 -> V_57 ) ;
V_61:
V_56:
return NULL ;
}
int F_17 ( struct V_5 * V_6 , int V_26 ,
unsigned long long V_33 , unsigned long long V_19 ,
T_2 V_29 , T_3 V_30 , T_3 V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_13 * V_65 ;
int V_27 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return - V_49 ;
}
V_65 = F_4 ( V_6 -> V_8 , struct V_13 , V_10 ) ;
if ( V_21 -> V_66 == NULL ) {
F_5 ( V_18 L_12 ) ;
return - V_67 ;
}
if ( ! ( ( ( V_65 -> V_58 & V_30 ) == V_30 ) &&
( ( V_65 -> V_59 & V_31 ) == V_31 ) ) ) {
F_5 ( V_18 L_13 ) ;
return - V_49 ;
}
V_27 = F_11 ( V_30 , V_33 , V_19 ) ;
if ( V_27 )
return V_27 ;
return V_21 -> V_66 ( V_65 , V_26 , V_33 , V_19 , V_29 ,
V_30 , V_31 ) ;
}
int F_10 ( struct V_5 * V_6 , int * V_26 ,
unsigned long long * V_33 , unsigned long long * V_19 ,
T_2 * V_29 , T_3 * V_30 , T_3 * V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_13 * V_65 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return - V_49 ;
}
V_65 = F_4 ( V_6 -> V_8 , struct V_13 , V_10 ) ;
if ( V_21 -> V_68 == NULL ) {
F_5 ( V_18 L_14 ) ;
return - V_49 ;
}
return V_21 -> V_68 ( V_65 , V_26 , V_33 , V_19 , V_29 ,
V_30 , V_31 ) ;
}
void F_18 ( struct V_5 * V_6 )
{
struct V_13 * V_55 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return;
}
V_55 = F_4 ( V_6 -> V_8 , struct V_13 ,
V_10 ) ;
if ( V_55 == NULL ) {
F_5 ( V_18 L_15 ) ;
return;
}
F_14 ( & V_55 -> V_57 ) ;
if ( V_55 -> V_60 == 0 )
F_5 ( V_18 L_16 ) ;
V_55 -> V_60 = 0 ;
F_15 ( & V_55 -> V_57 ) ;
F_19 ( V_6 ) ;
}
struct V_5 * F_20 ( struct V_1 * V_50 , T_3 V_51 ,
T_3 V_31 , T_3 V_32 )
{
struct V_4 * V_21 ;
struct V_52 * V_69 = NULL ;
struct V_9 * V_54 = NULL ;
struct V_9 * V_70 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_56;
}
F_13 (master_pos, &bridge->master_resources) {
V_70 = F_4 ( V_69 ,
struct V_9 , V_10 ) ;
if ( V_70 == NULL ) {
F_5 ( V_63 L_17 ) ;
continue;
}
F_21 ( & V_70 -> V_71 ) ;
if ( ( ( V_70 -> V_58 & V_51 ) == V_51 ) &&
( ( V_70 -> V_59 & V_31 ) == V_31 ) &&
( ( V_70 -> V_72 & V_32 ) == V_32 ) &&
( V_70 -> V_60 == 0 ) ) {
V_70 -> V_60 = 1 ;
F_22 ( & V_70 -> V_71 ) ;
V_54 = V_70 ;
break;
}
F_22 ( & V_70 -> V_71 ) ;
}
if ( V_54 == NULL ) {
F_5 ( V_18 L_18 ) ;
goto V_61;
}
V_6 = F_16 ( sizeof( struct V_5 ) , V_62 ) ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_10 ) ;
goto V_64;
}
V_6 -> type = V_7 ;
V_6 -> V_8 = & V_54 -> V_10 ;
return V_6 ;
V_64:
F_21 ( & V_70 -> V_71 ) ;
V_70 -> V_60 = 0 ;
F_22 ( & V_70 -> V_71 ) ;
V_61:
V_56:
return NULL ;
}
int F_23 ( struct V_5 * V_6 , int V_26 ,
unsigned long long V_33 , unsigned long long V_19 , T_3 V_30 ,
T_3 V_31 , T_3 V_32 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_65 ;
int V_27 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_65 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
if ( V_21 -> V_73 == NULL ) {
F_5 ( V_63 L_20 ) ;
return - V_49 ;
}
if ( ! ( ( ( V_65 -> V_58 & V_30 ) == V_30 ) &&
( ( V_65 -> V_59 & V_31 ) == V_31 ) &&
( ( V_65 -> V_72 & V_32 ) == V_32 ) ) ) {
F_5 ( V_63 L_13 ) ;
return - V_49 ;
}
V_27 = F_11 ( V_30 , V_33 , V_19 ) ;
if ( V_27 )
return V_27 ;
return V_21 -> V_73 ( V_65 , V_26 , V_33 , V_19 , V_30 ,
V_31 , V_32 ) ;
}
int F_9 ( struct V_5 * V_6 , int * V_26 ,
unsigned long long * V_33 , unsigned long long * V_19 , T_3 * V_30 ,
T_3 * V_31 , T_3 * V_32 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_65 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_65 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
if ( V_21 -> V_74 == NULL ) {
F_5 ( V_63 L_21 , V_75 ) ;
return - V_49 ;
}
return V_21 -> V_74 ( V_65 , V_26 , V_33 , V_19 , V_30 ,
V_31 , V_32 ) ;
}
T_4 F_24 ( struct V_5 * V_6 , void * V_76 , T_1 V_77 ,
T_5 V_78 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_65 ;
T_1 V_79 ;
if ( V_21 -> V_80 == NULL ) {
F_5 ( V_63 L_22 ) ;
return - V_49 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_65 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_79 = F_8 ( V_6 ) ;
if ( V_78 > V_79 ) {
F_5 ( V_63 L_23 ) ;
return - V_36 ;
}
if ( ( V_78 + V_77 ) > V_79 )
V_77 = V_79 - V_78 ;
return V_21 -> V_80 ( V_65 , V_76 , V_77 , V_78 ) ;
}
T_4 F_25 ( struct V_5 * V_6 , void * V_76 ,
T_1 V_77 , T_5 V_78 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_65 ;
T_1 V_79 ;
if ( V_21 -> V_81 == NULL ) {
F_5 ( V_63 L_24 ) ;
return - V_49 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_65 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_79 = F_8 ( V_6 ) ;
if ( V_78 > V_79 ) {
F_5 ( V_63 L_23 ) ;
return - V_36 ;
}
if ( ( V_78 + V_77 ) > V_79 )
V_77 = V_79 - V_78 ;
return V_21 -> V_81 ( V_65 , V_76 , V_77 , V_78 ) ;
}
unsigned int F_26 ( struct V_5 * V_6 , unsigned int V_82 ,
unsigned int V_83 , unsigned int V_84 , T_5 V_78 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_65 ;
if ( V_21 -> V_85 == NULL ) {
F_5 ( V_63 L_24 ) ;
return - V_49 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_65 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
return V_21 -> V_85 ( V_65 , V_82 , V_83 , V_84 , V_78 ) ;
}
int F_27 ( struct V_5 * V_6 , struct V_86 * V_87 )
{
struct V_9 * V_65 ;
T_6 V_88 ;
unsigned long V_89 ;
if ( V_6 -> type != V_7 ) {
F_28 ( L_19 ) ;
return - V_49 ;
}
V_65 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_88 = V_65 -> V_90 . V_91 + ( V_87 -> V_92 << V_93 ) ;
V_89 = V_87 -> V_94 - V_87 -> V_95 ;
if ( V_88 + V_89 > V_65 -> V_90 . V_96 + 1 ) {
F_28 ( L_25 ) ;
return - V_36 ;
}
V_87 -> V_97 = F_29 ( V_87 -> V_97 ) ;
return F_30 ( V_87 , V_88 , V_87 -> V_94 - V_87 -> V_95 ) ;
}
void F_31 ( struct V_5 * V_6 )
{
struct V_9 * V_70 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return;
}
V_70 = F_4 ( V_6 -> V_8 , struct V_9 ,
V_10 ) ;
if ( V_70 == NULL ) {
F_5 ( V_18 L_26 ) ;
return;
}
F_21 ( & V_70 -> V_71 ) ;
if ( V_70 -> V_60 == 0 )
F_5 ( V_18 L_16 ) ;
V_70 -> V_60 = 0 ;
F_22 ( & V_70 -> V_71 ) ;
F_19 ( V_6 ) ;
}
struct V_5 * F_32 ( struct V_1 * V_50 , T_3 V_98 )
{
struct V_4 * V_21 ;
struct V_52 * V_99 = NULL ;
struct V_15 * V_100 = NULL ;
struct V_15 * V_101 = NULL ;
struct V_5 * V_6 = NULL ;
F_5 ( V_18 L_27 ) ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_56;
}
F_13 (dma_pos, &bridge->dma_resources) {
V_101 = F_4 ( V_99 ,
struct V_15 , V_10 ) ;
if ( V_101 == NULL ) {
F_5 ( V_18 L_28 ) ;
continue;
}
F_14 ( & V_101 -> V_57 ) ;
if ( ( ( V_101 -> V_102 & V_98 ) == V_98 ) &&
( V_101 -> V_60 == 0 ) ) {
V_101 -> V_60 = 1 ;
F_15 ( & V_101 -> V_57 ) ;
V_100 = V_101 ;
break;
}
F_15 ( & V_101 -> V_57 ) ;
}
if ( V_100 == NULL )
goto V_103;
V_6 = F_16 ( sizeof( struct V_5 ) , V_62 ) ;
if ( V_6 == NULL ) {
F_5 ( V_63 L_10 ) ;
goto V_64;
}
V_6 -> type = V_14 ;
V_6 -> V_8 = & V_100 -> V_10 ;
return V_6 ;
V_64:
F_14 ( & V_101 -> V_57 ) ;
V_101 -> V_60 = 0 ;
F_15 ( & V_101 -> V_57 ) ;
V_103:
V_56:
return NULL ;
}
struct V_104 * F_33 ( struct V_5 * V_6 )
{
struct V_15 * V_105 ;
struct V_104 * V_106 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_29 ) ;
return NULL ;
}
V_105 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
V_106 = F_16 ( sizeof( struct V_104 ) , V_62 ) ;
if ( V_106 == NULL ) {
F_5 ( V_18 L_30 ) ;
return NULL ;
}
F_34 ( & V_106 -> V_107 ) ;
V_106 -> V_11 = V_105 ;
F_35 ( & V_106 -> V_57 ) ;
return V_106 ;
}
struct V_108 * F_36 ( T_3 V_109 , T_3 type )
{
struct V_108 * V_110 ;
struct V_111 * V_112 ;
V_110 = F_16 ( sizeof( struct V_108 ) , V_62 ) ;
if ( V_110 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_113;
}
V_112 = F_16 ( sizeof( struct V_111 ) , V_62 ) ;
if ( V_112 == NULL ) {
F_5 ( V_18 L_32 ) ;
goto V_114;
}
V_110 -> type = V_115 ;
V_110 -> V_116 = ( void * ) V_112 ;
V_112 -> V_109 = V_109 ;
V_112 -> type = type ;
return V_110 ;
V_114:
F_19 ( V_110 ) ;
V_113:
return NULL ;
}
struct V_108 * F_37 ( T_2 V_51 )
{
struct V_108 * V_110 ;
struct V_117 * V_118 ;
V_110 = F_16 ( sizeof( struct V_108 ) , V_62 ) ;
if ( V_110 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_113;
}
V_118 = F_16 ( sizeof( struct V_117 ) , V_62 ) ;
if ( V_118 == NULL ) {
F_5 ( V_18 L_33 ) ;
goto V_119;
}
V_110 -> type = V_120 ;
V_110 -> V_116 = ( void * ) V_118 ;
V_118 -> V_51 = V_51 ;
return V_110 ;
V_119:
F_19 ( V_110 ) ;
V_113:
return NULL ;
}
struct V_108 * F_38 ( unsigned long long V_51 ,
T_3 V_30 , T_3 V_31 , T_3 V_32 )
{
struct V_108 * V_110 ;
struct V_121 * V_122 ;
V_110 = F_16 (
sizeof( struct V_108 ) , V_62 ) ;
if ( V_110 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_113;
}
V_122 = F_16 ( sizeof( struct V_121 ) , V_62 ) ;
if ( V_122 == NULL ) {
F_5 ( V_18 L_34 ) ;
goto V_123;
}
V_110 -> type = V_124 ;
V_110 -> V_116 = ( void * ) V_122 ;
V_122 -> V_51 = V_51 ;
V_122 -> V_30 = V_30 ;
V_122 -> V_31 = V_31 ;
V_122 -> V_32 = V_32 ;
return V_110 ;
V_123:
F_19 ( V_110 ) ;
V_113:
return NULL ;
}
void F_39 ( struct V_108 * V_110 )
{
F_19 ( V_110 -> V_116 ) ;
F_19 ( V_110 ) ;
}
int F_40 ( struct V_104 * V_10 , struct V_108 * V_125 ,
struct V_108 * V_126 , T_1 V_77 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_127 == NULL ) {
F_5 ( V_63 L_35 ) ;
return - V_49 ;
}
if ( ! F_41 ( & V_10 -> V_57 ) ) {
F_5 ( V_18 L_36 ) ;
return - V_49 ;
}
V_27 = V_21 -> V_127 ( V_10 , V_125 , V_126 , V_77 ) ;
F_15 ( & V_10 -> V_57 ) ;
return V_27 ;
}
int F_42 ( struct V_104 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_128 == NULL ) {
F_5 ( V_18 L_37 ) ;
return - V_49 ;
}
F_14 ( & V_10 -> V_57 ) ;
V_27 = V_21 -> V_128 ( V_10 ) ;
F_15 ( & V_10 -> V_57 ) ;
return V_27 ;
}
int F_43 ( struct V_104 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_129 == NULL ) {
F_5 ( V_63 L_38 ) ;
return - V_49 ;
}
if ( ! F_41 ( & V_10 -> V_57 ) ) {
F_5 ( V_18 L_39 ) ;
return - V_49 ;
}
V_27 = V_21 -> V_129 ( V_10 ) ;
if ( V_27 ) {
F_5 ( V_18 L_40 ) ;
F_15 ( & V_10 -> V_57 ) ;
return V_27 ;
}
F_15 ( & V_10 -> V_57 ) ;
F_19 ( V_10 ) ;
return V_27 ;
}
int F_44 ( struct V_5 * V_6 )
{
struct V_15 * V_105 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_29 ) ;
return - V_49 ;
}
V_105 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
if ( ! F_41 ( & V_105 -> V_57 ) ) {
F_5 ( V_18 L_41 ) ;
return - V_130 ;
}
if ( ! ( F_45 ( & V_105 -> V_131 ) && F_45 ( & V_105 -> V_132 ) ) ) {
F_5 ( V_63 L_42 ) ;
F_15 ( & V_105 -> V_57 ) ;
return - V_130 ;
}
V_105 -> V_60 = 0 ;
F_15 ( & V_105 -> V_57 ) ;
F_19 ( V_6 ) ;
return 0 ;
}
void F_46 ( struct V_4 * V_21 , int V_133 , int V_134 )
{
void (* F_47)( int , int , void * );
void * V_135 ;
F_47 = V_21 -> V_136 [ V_133 - 1 ] . V_137 [ V_134 ] . V_138 ;
V_135 = V_21 -> V_136 [ V_133 - 1 ] . V_137 [ V_134 ] . V_135 ;
if ( F_47 != NULL )
F_47 ( V_133 , V_134 , V_135 ) ;
else
F_5 ( V_63 L_43 ,
V_133 , V_134 ) ;
}
int F_48 ( struct V_1 * V_50 , int V_133 , int V_134 ,
void (* V_137)( int , int , void * ) ,
void * V_135 )
{
struct V_4 * V_21 ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_49 ;
}
if ( ( V_133 < 1 ) || ( V_133 > 7 ) ) {
F_5 ( V_18 L_44 ) ;
return - V_49 ;
}
if ( V_21 -> V_139 == NULL ) {
F_5 ( V_18 L_45 ) ;
return - V_49 ;
}
F_14 ( & V_21 -> V_140 ) ;
if ( V_21 -> V_136 [ V_133 - 1 ] . V_137 [ V_134 ] . V_138 ) {
F_15 ( & V_21 -> V_140 ) ;
F_5 ( V_63 L_46 ) ;
return - V_130 ;
}
V_21 -> V_136 [ V_133 - 1 ] . V_77 ++ ;
V_21 -> V_136 [ V_133 - 1 ] . V_137 [ V_134 ] . V_135 = V_135 ;
V_21 -> V_136 [ V_133 - 1 ] . V_137 [ V_134 ] . V_138 = V_137 ;
V_21 -> V_139 ( V_21 , V_133 , 1 , 1 ) ;
F_15 ( & V_21 -> V_140 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_50 , int V_133 , int V_134 )
{
struct V_4 * V_21 ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return;
}
if ( ( V_133 < 1 ) || ( V_133 > 7 ) ) {
F_5 ( V_18 L_44 ) ;
return;
}
if ( V_21 -> V_139 == NULL ) {
F_5 ( V_18 L_45 ) ;
return;
}
F_14 ( & V_21 -> V_140 ) ;
V_21 -> V_136 [ V_133 - 1 ] . V_77 -- ;
if ( V_21 -> V_136 [ V_133 - 1 ] . V_77 == 0 )
V_21 -> V_139 ( V_21 , V_133 , 0 , 1 ) ;
V_21 -> V_136 [ V_133 - 1 ] . V_137 [ V_134 ] . V_138 = NULL ;
V_21 -> V_136 [ V_133 - 1 ] . V_137 [ V_134 ] . V_135 = NULL ;
F_15 ( & V_21 -> V_140 ) ;
}
int F_50 ( struct V_1 * V_50 , int V_133 , int V_134 )
{
struct V_4 * V_21 ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_49 ;
}
if ( ( V_133 < 1 ) || ( V_133 > 7 ) ) {
F_5 ( V_63 L_44 ) ;
return - V_49 ;
}
if ( V_21 -> V_141 == NULL ) {
F_5 ( V_63 L_47 ) ;
return - V_49 ;
}
return V_21 -> V_141 ( V_21 , V_133 , V_134 ) ;
}
struct V_5 * F_51 ( struct V_1 * V_50 )
{
struct V_4 * V_21 ;
struct V_52 * V_142 = NULL ;
struct V_17 * V_143 = NULL ;
struct V_17 * V_144 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_56;
}
F_13 (lm_pos, &bridge->lm_resources) {
V_144 = F_4 ( V_142 ,
struct V_17 , V_10 ) ;
if ( V_144 == NULL ) {
F_5 ( V_18 L_48 ) ;
continue;
}
F_14 ( & V_144 -> V_57 ) ;
if ( V_144 -> V_60 == 0 ) {
V_144 -> V_60 = 1 ;
F_15 ( & V_144 -> V_57 ) ;
V_143 = V_144 ;
break;
}
F_15 ( & V_144 -> V_57 ) ;
}
if ( V_143 == NULL )
goto V_145;
V_6 = F_16 ( sizeof( struct V_5 ) , V_62 ) ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_10 ) ;
goto V_64;
}
V_6 -> type = V_16 ;
V_6 -> V_8 = & V_143 -> V_10 ;
return V_6 ;
V_64:
F_14 ( & V_144 -> V_57 ) ;
V_144 -> V_60 = 0 ;
F_15 ( & V_144 -> V_57 ) ;
V_145:
V_56:
return NULL ;
}
int F_52 ( struct V_5 * V_6 )
{
struct V_17 * V_144 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_49 ;
}
V_144 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
return V_144 -> V_146 ;
}
int F_53 ( struct V_5 * V_6 , unsigned long long V_147 ,
T_3 V_30 , T_3 V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_144 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_49 ;
}
V_144 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_148 == NULL ) {
F_5 ( V_18 L_50 ) ;
return - V_49 ;
}
return V_21 -> V_148 ( V_144 , V_147 , V_30 , V_31 ) ;
}
int F_54 ( struct V_5 * V_6 , unsigned long long * V_147 ,
T_3 * V_30 , T_3 * V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_144 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_49 ;
}
V_144 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_149 == NULL ) {
F_5 ( V_18 L_51 ) ;
return - V_49 ;
}
return V_21 -> V_149 ( V_144 , V_147 , V_30 , V_31 ) ;
}
int F_55 ( struct V_5 * V_6 , int V_150 ,
void (* V_137)( int ) )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_144 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_49 ;
}
V_144 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_151 == NULL ) {
F_5 ( V_18 L_52 ) ;
return - V_49 ;
}
return V_21 -> V_151 ( V_144 , V_150 , V_137 ) ;
}
int F_56 ( struct V_5 * V_6 , int V_150 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_144 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_49 ;
}
V_144 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_152 == NULL ) {
F_5 ( V_18 L_53 ) ;
return - V_49 ;
}
return V_21 -> V_152 ( V_144 , V_150 ) ;
}
void F_57 ( struct V_5 * V_6 )
{
struct V_17 * V_144 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return;
}
V_144 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
F_14 ( & V_144 -> V_57 ) ;
V_144 -> V_60 = 0 ;
F_15 ( & V_144 -> V_57 ) ;
F_19 ( V_6 ) ;
}
int F_58 ( struct V_1 * V_50 )
{
struct V_4 * V_21 ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_49 ;
}
if ( V_21 -> V_153 == NULL ) {
F_5 ( V_63 L_54 ) ;
return - V_49 ;
}
return V_21 -> V_153 ( V_21 ) ;
}
int F_59 ( struct V_1 * V_50 )
{
struct V_4 * V_21 ;
V_21 = V_50 -> V_21 ;
if ( V_21 == NULL ) {
F_28 ( L_8 ) ;
return - V_49 ;
}
return V_21 -> V_154 ;
}
static void F_60 ( struct V_2 * V_3 )
{
F_19 ( F_1 ( V_3 ) ) ;
}
int F_61 ( struct V_4 * V_21 )
{
int V_155 ;
int V_156 = - 1 ;
F_14 ( & V_157 ) ;
for ( V_155 = 0 ; V_155 < sizeof( V_158 ) * 8 ; V_155 ++ ) {
if ( ( V_158 & ( 1 << V_155 ) ) == 0 ) {
V_158 |= ( 1 << V_155 ) ;
V_21 -> V_154 = V_155 ;
F_34 ( & V_21 -> V_159 ) ;
F_62 ( & V_21 -> V_160 , & V_161 ) ;
V_156 = 0 ;
break;
}
}
F_15 ( & V_157 ) ;
return V_156 ;
}
void F_63 ( struct V_4 * V_21 )
{
struct V_1 * V_50 ;
struct V_1 * V_162 ;
F_14 ( & V_157 ) ;
V_158 &= ~ ( 1 << V_21 -> V_154 ) ;
F_64 (vdev, tmp, &bridge->devices, bridge_list) {
F_65 ( & V_50 -> V_163 ) ;
F_65 ( & V_50 -> V_164 ) ;
F_66 ( & V_50 -> V_3 ) ;
}
F_65 ( & V_21 -> V_160 ) ;
F_15 ( & V_157 ) ;
}
static int F_67 ( struct V_165 * V_166 ,
struct V_4 * V_21 , unsigned int V_167 )
{
int V_168 ;
unsigned int V_155 ;
struct V_1 * V_50 ;
struct V_1 * V_162 ;
for ( V_155 = 0 ; V_155 < V_167 ; V_155 ++ ) {
V_50 = F_68 ( sizeof( struct V_1 ) , V_62 ) ;
if ( ! V_50 ) {
V_168 = - V_169 ;
goto V_170;
}
V_50 -> V_154 = V_155 ;
V_50 -> V_21 = V_21 ;
V_50 -> V_3 . V_171 = V_166 ;
V_50 -> V_3 . V_172 = F_60 ;
V_50 -> V_3 . V_11 = V_21 -> V_11 ;
V_50 -> V_3 . V_173 = & V_174 ;
F_69 ( & V_50 -> V_3 , L_55 , V_166 -> V_22 , V_21 -> V_154 ,
V_50 -> V_154 ) ;
V_168 = F_70 ( & V_50 -> V_3 ) ;
if ( V_168 )
goto V_175;
if ( V_50 -> V_3 . V_171 ) {
F_62 ( & V_50 -> V_163 , & V_166 -> V_159 ) ;
F_62 ( & V_50 -> V_164 , & V_21 -> V_159 ) ;
} else
F_66 ( & V_50 -> V_3 ) ;
}
return 0 ;
V_175:
F_71 ( & V_50 -> V_3 ) ;
F_19 ( V_50 ) ;
V_170:
F_64 (vdev, tmp, &drv->devices, drv_list) {
F_65 ( & V_50 -> V_163 ) ;
F_65 ( & V_50 -> V_164 ) ;
F_66 ( & V_50 -> V_3 ) ;
}
return V_168 ;
}
static int F_72 ( struct V_165 * V_166 , unsigned int V_167 )
{
struct V_4 * V_21 ;
int V_168 = 0 ;
F_14 ( & V_157 ) ;
F_73 (bridge, &vme_bus_list, bus_list) {
V_168 = F_67 ( V_166 , V_21 , V_167 ) ;
if ( V_168 )
break;
}
F_15 ( & V_157 ) ;
return V_168 ;
}
int F_74 ( struct V_165 * V_166 , unsigned int V_167 )
{
int V_168 ;
V_166 -> V_176 . V_22 = V_166 -> V_22 ;
V_166 -> V_176 . V_173 = & V_174 ;
F_34 ( & V_166 -> V_159 ) ;
V_168 = F_75 ( & V_166 -> V_176 ) ;
if ( V_168 )
return V_168 ;
V_168 = F_72 ( V_166 , V_167 ) ;
if ( V_168 )
F_76 ( & V_166 -> V_176 ) ;
return V_168 ;
}
void F_77 ( struct V_165 * V_166 )
{
struct V_1 * V_3 , * V_177 ;
F_14 ( & V_157 ) ;
F_64 (dev, dev_tmp, &drv->devices, drv_list) {
F_65 ( & V_3 -> V_163 ) ;
F_65 ( & V_3 -> V_164 ) ;
F_66 ( & V_3 -> V_3 ) ;
}
F_15 ( & V_157 ) ;
F_76 ( & V_166 -> V_176 ) ;
}
static int F_78 ( struct V_2 * V_3 , struct V_178 * V_166 )
{
struct V_165 * V_179 ;
V_179 = F_2 ( V_166 , struct V_165 , V_176 ) ;
if ( V_3 -> V_171 == V_179 ) {
struct V_1 * V_50 = F_1 ( V_3 ) ;
if ( V_179 -> V_180 && V_179 -> V_180 ( V_50 ) )
return 1 ;
V_3 -> V_171 = NULL ;
}
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_27 = - V_181 ;
struct V_165 * V_176 ;
struct V_1 * V_50 = F_1 ( V_3 ) ;
V_176 = V_3 -> V_171 ;
if ( V_176 -> V_182 != NULL )
V_27 = V_176 -> V_182 ( V_50 ) ;
return V_27 ;
}
static int F_80 ( struct V_2 * V_3 )
{
int V_27 = - V_181 ;
struct V_165 * V_176 ;
struct V_1 * V_50 = F_1 ( V_3 ) ;
V_176 = V_3 -> V_171 ;
if ( V_176 -> remove != NULL )
V_27 = V_176 -> remove ( V_50 ) ;
return V_27 ;
}
static int T_7 F_81 ( void )
{
return F_82 ( & V_174 ) ;
}
static void T_8 F_83 ( void )
{
F_84 ( & V_174 ) ;
}
