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
static T_3 F_12 ( int V_50 )
{
switch ( V_50 ) {
case 0x29 :
case 0x2D :
return V_34 ;
case 0x38 :
case 0x39 :
case 0x3A :
case 0x3B :
case 0x3C :
case 0x3D :
case 0x3E :
case 0x3F :
return V_37 ;
case 0x8 :
case 0x9 :
case 0xA :
case 0xB :
case 0xC :
case 0xD :
case 0xE :
case 0xF :
return V_39 ;
case 0x0 :
case 0x1 :
case 0x3 :
return V_41 ;
}
return 0 ;
}
struct V_5 * F_13 ( struct V_1 * V_51 , T_3 V_52 ,
T_3 V_31 )
{
struct V_4 * V_21 ;
struct V_53 * V_54 = NULL ;
struct V_13 * V_55 = NULL ;
struct V_13 * V_56 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_57;
}
F_14 (slave_pos, &bridge->slave_resources) {
V_56 = F_4 ( V_54 ,
struct V_13 , V_10 ) ;
if ( V_56 == NULL ) {
F_5 ( V_18 L_9 ) ;
continue;
}
F_15 ( & V_56 -> V_58 ) ;
if ( ( ( V_56 -> V_59 & V_52 ) == V_52 ) &&
( ( V_56 -> V_60 & V_31 ) == V_31 ) &&
( V_56 -> V_61 == 0 ) ) {
V_56 -> V_61 = 1 ;
F_16 ( & V_56 -> V_58 ) ;
V_55 = V_56 ;
break;
}
F_16 ( & V_56 -> V_58 ) ;
}
if ( V_55 == NULL )
goto V_62;
V_6 = F_17 ( sizeof( struct V_5 ) , V_63 ) ;
if ( V_6 == NULL ) {
F_5 ( V_64 L_10 ) ;
goto V_65;
}
V_6 -> type = V_12 ;
V_6 -> V_8 = & V_55 -> V_10 ;
return V_6 ;
V_65:
F_15 ( & V_56 -> V_58 ) ;
V_56 -> V_61 = 0 ;
F_16 ( & V_56 -> V_58 ) ;
V_62:
V_57:
return NULL ;
}
int F_18 ( struct V_5 * V_6 , int V_26 ,
unsigned long long V_33 , unsigned long long V_19 ,
T_2 V_29 , T_3 V_30 , T_3 V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_13 * V_66 ;
int V_27 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return - V_49 ;
}
V_66 = F_4 ( V_6 -> V_8 , struct V_13 , V_10 ) ;
if ( V_21 -> V_67 == NULL ) {
F_5 ( V_18 L_12 ) ;
return - V_68 ;
}
if ( ! ( ( ( V_66 -> V_59 & V_30 ) == V_30 ) &&
( ( V_66 -> V_60 & V_31 ) == V_31 ) ) ) {
F_5 ( V_18 L_13 ) ;
return - V_49 ;
}
V_27 = F_11 ( V_30 , V_33 , V_19 ) ;
if ( V_27 )
return V_27 ;
return V_21 -> V_67 ( V_66 , V_26 , V_33 , V_19 , V_29 ,
V_30 , V_31 ) ;
}
int F_10 ( struct V_5 * V_6 , int * V_26 ,
unsigned long long * V_33 , unsigned long long * V_19 ,
T_2 * V_29 , T_3 * V_30 , T_3 * V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_13 * V_66 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return - V_49 ;
}
V_66 = F_4 ( V_6 -> V_8 , struct V_13 , V_10 ) ;
if ( V_21 -> V_69 == NULL ) {
F_5 ( V_18 L_14 ) ;
return - V_49 ;
}
return V_21 -> V_69 ( V_66 , V_26 , V_33 , V_19 , V_29 ,
V_30 , V_31 ) ;
}
void F_19 ( struct V_5 * V_6 )
{
struct V_13 * V_56 ;
if ( V_6 -> type != V_12 ) {
F_5 ( V_18 L_11 ) ;
return;
}
V_56 = F_4 ( V_6 -> V_8 , struct V_13 ,
V_10 ) ;
if ( V_56 == NULL ) {
F_5 ( V_18 L_15 ) ;
return;
}
F_15 ( & V_56 -> V_58 ) ;
if ( V_56 -> V_61 == 0 )
F_5 ( V_18 L_16 ) ;
V_56 -> V_61 = 0 ;
F_16 ( & V_56 -> V_58 ) ;
F_20 ( V_6 ) ;
}
struct V_5 * F_21 ( struct V_1 * V_51 , T_3 V_52 ,
T_3 V_31 , T_3 V_32 )
{
struct V_4 * V_21 ;
struct V_53 * V_70 = NULL ;
struct V_9 * V_55 = NULL ;
struct V_9 * V_71 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_57;
}
F_14 (master_pos, &bridge->master_resources) {
V_71 = F_4 ( V_70 ,
struct V_9 , V_10 ) ;
if ( V_71 == NULL ) {
F_5 ( V_64 L_17 ) ;
continue;
}
F_22 ( & V_71 -> V_72 ) ;
if ( ( ( V_71 -> V_59 & V_52 ) == V_52 ) &&
( ( V_71 -> V_60 & V_31 ) == V_31 ) &&
( ( V_71 -> V_73 & V_32 ) == V_32 ) &&
( V_71 -> V_61 == 0 ) ) {
V_71 -> V_61 = 1 ;
F_23 ( & V_71 -> V_72 ) ;
V_55 = V_71 ;
break;
}
F_23 ( & V_71 -> V_72 ) ;
}
if ( V_55 == NULL ) {
F_5 ( V_18 L_18 ) ;
goto V_62;
}
V_6 = F_17 ( sizeof( struct V_5 ) , V_63 ) ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_10 ) ;
goto V_65;
}
V_6 -> type = V_7 ;
V_6 -> V_8 = & V_55 -> V_10 ;
return V_6 ;
V_65:
F_22 ( & V_71 -> V_72 ) ;
V_71 -> V_61 = 0 ;
F_23 ( & V_71 -> V_72 ) ;
V_62:
V_57:
return NULL ;
}
int F_24 ( struct V_5 * V_6 , int V_26 ,
unsigned long long V_33 , unsigned long long V_19 , T_3 V_30 ,
T_3 V_31 , T_3 V_32 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_66 ;
int V_27 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_66 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
if ( V_21 -> V_74 == NULL ) {
F_5 ( V_64 L_20 ) ;
return - V_49 ;
}
if ( ! ( ( ( V_66 -> V_59 & V_30 ) == V_30 ) &&
( ( V_66 -> V_60 & V_31 ) == V_31 ) &&
( ( V_66 -> V_73 & V_32 ) == V_32 ) ) ) {
F_5 ( V_64 L_13 ) ;
return - V_49 ;
}
V_27 = F_11 ( V_30 , V_33 , V_19 ) ;
if ( V_27 )
return V_27 ;
return V_21 -> V_74 ( V_66 , V_26 , V_33 , V_19 , V_30 ,
V_31 , V_32 ) ;
}
int F_9 ( struct V_5 * V_6 , int * V_26 ,
unsigned long long * V_33 , unsigned long long * V_19 , T_3 * V_30 ,
T_3 * V_31 , T_3 * V_32 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_66 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_66 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
if ( V_21 -> V_75 == NULL ) {
F_5 ( V_64 L_21 , V_76 ) ;
return - V_49 ;
}
return V_21 -> V_75 ( V_66 , V_26 , V_33 , V_19 , V_30 ,
V_31 , V_32 ) ;
}
T_4 F_25 ( struct V_5 * V_6 , void * V_77 , T_1 V_78 ,
T_5 V_79 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_66 ;
T_1 V_80 ;
if ( V_21 -> V_81 == NULL ) {
F_5 ( V_64 L_22 ) ;
return - V_49 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_66 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_80 = F_8 ( V_6 ) ;
if ( V_79 > V_80 ) {
F_5 ( V_64 L_23 ) ;
return - V_36 ;
}
if ( ( V_79 + V_78 ) > V_80 )
V_78 = V_80 - V_79 ;
return V_21 -> V_81 ( V_66 , V_77 , V_78 , V_79 ) ;
}
T_4 F_26 ( struct V_5 * V_6 , void * V_77 ,
T_1 V_78 , T_5 V_79 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_66 ;
T_1 V_80 ;
if ( V_21 -> V_82 == NULL ) {
F_5 ( V_64 L_24 ) ;
return - V_49 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_66 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_80 = F_8 ( V_6 ) ;
if ( V_79 > V_80 ) {
F_5 ( V_64 L_23 ) ;
return - V_36 ;
}
if ( ( V_79 + V_78 ) > V_80 )
V_78 = V_80 - V_79 ;
return V_21 -> V_82 ( V_66 , V_77 , V_78 , V_79 ) ;
}
unsigned int F_27 ( struct V_5 * V_6 , unsigned int V_83 ,
unsigned int V_84 , unsigned int V_85 , T_5 V_79 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_9 * V_66 ;
if ( V_21 -> V_86 == NULL ) {
F_5 ( V_64 L_24 ) ;
return - V_49 ;
}
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return - V_49 ;
}
V_66 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
return V_21 -> V_86 ( V_66 , V_83 , V_84 , V_85 , V_79 ) ;
}
int F_28 ( struct V_5 * V_6 , struct V_87 * V_88 )
{
struct V_9 * V_66 ;
T_6 V_89 ;
unsigned long V_90 ;
if ( V_6 -> type != V_7 ) {
F_29 ( L_19 ) ;
return - V_49 ;
}
V_66 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_89 = V_66 -> V_91 . V_92 + ( V_88 -> V_93 << V_94 ) ;
V_90 = V_88 -> V_95 - V_88 -> V_96 ;
if ( V_89 + V_90 > V_66 -> V_91 . V_97 + 1 ) {
F_29 ( L_25 ) ;
return - V_36 ;
}
V_88 -> V_98 = F_30 ( V_88 -> V_98 ) ;
return F_31 ( V_88 , V_89 , V_88 -> V_95 - V_88 -> V_96 ) ;
}
void F_32 ( struct V_5 * V_6 )
{
struct V_9 * V_71 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return;
}
V_71 = F_4 ( V_6 -> V_8 , struct V_9 ,
V_10 ) ;
if ( V_71 == NULL ) {
F_5 ( V_18 L_26 ) ;
return;
}
F_22 ( & V_71 -> V_72 ) ;
if ( V_71 -> V_61 == 0 )
F_5 ( V_18 L_16 ) ;
V_71 -> V_61 = 0 ;
F_23 ( & V_71 -> V_72 ) ;
F_20 ( V_6 ) ;
}
struct V_5 * F_33 ( struct V_1 * V_51 , T_3 V_99 )
{
struct V_4 * V_21 ;
struct V_53 * V_100 = NULL ;
struct V_15 * V_101 = NULL ;
struct V_15 * V_102 = NULL ;
struct V_5 * V_6 = NULL ;
F_5 ( V_18 L_27 ) ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_57;
}
F_14 (dma_pos, &bridge->dma_resources) {
V_102 = F_4 ( V_100 ,
struct V_15 , V_10 ) ;
if ( V_102 == NULL ) {
F_5 ( V_18 L_28 ) ;
continue;
}
F_15 ( & V_102 -> V_58 ) ;
if ( ( ( V_102 -> V_103 & V_99 ) == V_99 ) &&
( V_102 -> V_61 == 0 ) ) {
V_102 -> V_61 = 1 ;
F_16 ( & V_102 -> V_58 ) ;
V_101 = V_102 ;
break;
}
F_16 ( & V_102 -> V_58 ) ;
}
if ( V_101 == NULL )
goto V_104;
V_6 = F_17 ( sizeof( struct V_5 ) , V_63 ) ;
if ( V_6 == NULL ) {
F_5 ( V_64 L_10 ) ;
goto V_65;
}
V_6 -> type = V_14 ;
V_6 -> V_8 = & V_101 -> V_10 ;
return V_6 ;
V_65:
F_15 ( & V_102 -> V_58 ) ;
V_102 -> V_61 = 0 ;
F_16 ( & V_102 -> V_58 ) ;
V_104:
V_57:
return NULL ;
}
struct V_105 * F_34 ( struct V_5 * V_6 )
{
struct V_15 * V_106 ;
struct V_105 * V_107 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_29 ) ;
return NULL ;
}
V_106 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
V_107 = F_17 ( sizeof( struct V_105 ) , V_63 ) ;
if ( V_107 == NULL ) {
F_5 ( V_18 L_30 ) ;
return NULL ;
}
F_35 ( & V_107 -> V_108 ) ;
V_107 -> V_11 = V_106 ;
F_36 ( & V_107 -> V_58 ) ;
return V_107 ;
}
struct V_109 * F_37 ( T_3 V_110 , T_3 type )
{
struct V_109 * V_111 ;
struct V_112 * V_113 ;
V_111 = F_17 ( sizeof( struct V_109 ) , V_63 ) ;
if ( V_111 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_114;
}
V_113 = F_17 ( sizeof( struct V_112 ) , V_63 ) ;
if ( V_113 == NULL ) {
F_5 ( V_18 L_32 ) ;
goto V_115;
}
V_111 -> type = V_116 ;
V_111 -> V_117 = ( void * ) V_113 ;
V_113 -> V_110 = V_110 ;
V_113 -> type = type ;
return V_111 ;
V_115:
F_20 ( V_111 ) ;
V_114:
return NULL ;
}
struct V_109 * F_38 ( T_2 V_52 )
{
struct V_109 * V_111 ;
struct V_118 * V_119 ;
V_111 = F_17 ( sizeof( struct V_109 ) , V_63 ) ;
if ( V_111 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_114;
}
V_119 = F_17 ( sizeof( struct V_118 ) , V_63 ) ;
if ( V_119 == NULL ) {
F_5 ( V_18 L_33 ) ;
goto V_120;
}
V_111 -> type = V_121 ;
V_111 -> V_117 = ( void * ) V_119 ;
V_119 -> V_52 = V_52 ;
return V_111 ;
V_120:
F_20 ( V_111 ) ;
V_114:
return NULL ;
}
struct V_109 * F_39 ( unsigned long long V_52 ,
T_3 V_30 , T_3 V_31 , T_3 V_32 )
{
struct V_109 * V_111 ;
struct V_122 * V_123 ;
V_111 = F_17 (
sizeof( struct V_109 ) , V_63 ) ;
if ( V_111 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_114;
}
V_123 = F_17 ( sizeof( struct V_122 ) , V_63 ) ;
if ( V_123 == NULL ) {
F_5 ( V_18 L_34 ) ;
goto V_124;
}
V_111 -> type = V_125 ;
V_111 -> V_117 = ( void * ) V_123 ;
V_123 -> V_52 = V_52 ;
V_123 -> V_30 = V_30 ;
V_123 -> V_31 = V_31 ;
V_123 -> V_32 = V_32 ;
return V_111 ;
V_124:
F_20 ( V_111 ) ;
V_114:
return NULL ;
}
void F_40 ( struct V_109 * V_111 )
{
F_20 ( V_111 -> V_117 ) ;
F_20 ( V_111 ) ;
}
int F_41 ( struct V_105 * V_10 , struct V_109 * V_126 ,
struct V_109 * V_127 , T_1 V_78 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_128 == NULL ) {
F_5 ( V_64 L_35 ) ;
return - V_49 ;
}
if ( ! F_42 ( & V_10 -> V_58 ) ) {
F_5 ( V_18 L_36 ) ;
return - V_49 ;
}
V_27 = V_21 -> V_128 ( V_10 , V_126 , V_127 , V_78 ) ;
F_16 ( & V_10 -> V_58 ) ;
return V_27 ;
}
int F_43 ( struct V_105 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_129 == NULL ) {
F_5 ( V_18 L_37 ) ;
return - V_49 ;
}
F_15 ( & V_10 -> V_58 ) ;
V_27 = V_21 -> V_129 ( V_10 ) ;
F_16 ( & V_10 -> V_58 ) ;
return V_27 ;
}
int F_44 ( struct V_105 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_130 == NULL ) {
F_5 ( V_64 L_38 ) ;
return - V_49 ;
}
if ( ! F_42 ( & V_10 -> V_58 ) ) {
F_5 ( V_18 L_39 ) ;
return - V_49 ;
}
V_27 = V_21 -> V_130 ( V_10 ) ;
if ( V_27 ) {
F_5 ( V_18 L_40 ) ;
F_16 ( & V_10 -> V_58 ) ;
return V_27 ;
}
F_16 ( & V_10 -> V_58 ) ;
F_20 ( V_10 ) ;
return V_27 ;
}
int F_45 ( struct V_5 * V_6 )
{
struct V_15 * V_106 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_29 ) ;
return - V_49 ;
}
V_106 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
if ( ! F_42 ( & V_106 -> V_58 ) ) {
F_5 ( V_18 L_41 ) ;
return - V_131 ;
}
if ( ! ( F_46 ( & V_106 -> V_132 ) && F_46 ( & V_106 -> V_133 ) ) ) {
F_5 ( V_64 L_42 ) ;
F_16 ( & V_106 -> V_58 ) ;
return - V_131 ;
}
V_106 -> V_61 = 0 ;
F_16 ( & V_106 -> V_58 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
void F_47 ( struct V_4 * V_21 ,
unsigned long long V_52 , int V_50 )
{
struct V_53 * V_134 = NULL ;
struct V_135 * V_136 ;
int V_137 = 0 ;
T_3 V_30 = F_12 ( V_50 ) ;
F_14 (handler_pos, &bridge->vme_error_handlers) {
V_136 = F_4 ( V_134 , struct V_135 ,
V_10 ) ;
if ( ( V_30 == V_136 -> V_30 ) &&
( V_52 >= V_136 -> V_92 ) &&
( V_52 < V_136 -> V_97 ) ) {
if ( ! V_136 -> V_138 )
V_136 -> V_139 = V_52 ;
if ( V_136 -> V_138 != V_140 )
V_136 -> V_138 ++ ;
V_137 = 1 ;
}
}
if ( ! V_137 )
F_48 ( V_21 -> V_11 ,
L_43 ,
V_52 ) ;
}
struct V_135 * F_49 (
struct V_4 * V_21 , T_3 V_30 ,
unsigned long long V_52 , T_1 V_141 )
{
struct V_135 * V_136 ;
V_136 = F_17 ( sizeof( * V_136 ) , V_63 ) ;
if ( ! V_136 )
return NULL ;
V_136 -> V_30 = V_30 ;
V_136 -> V_92 = V_52 ;
V_136 -> V_97 = V_52 + V_141 ;
V_136 -> V_138 = 0 ;
V_136 -> V_139 = 0 ;
F_50 ( & V_136 -> V_10 , & V_21 -> V_142 ) ;
return V_136 ;
}
void F_51 ( struct V_135 * V_136 )
{
F_52 ( & V_136 -> V_10 ) ;
F_20 ( V_136 ) ;
}
void F_53 ( struct V_4 * V_21 , int V_143 , int V_144 )
{
void (* F_54)( int , int , void * );
void * V_145 ;
F_54 = V_21 -> V_146 [ V_143 - 1 ] . V_147 [ V_144 ] . V_148 ;
V_145 = V_21 -> V_146 [ V_143 - 1 ] . V_147 [ V_144 ] . V_145 ;
if ( F_54 != NULL )
F_54 ( V_143 , V_144 , V_145 ) ;
else
F_5 ( V_64 L_44 ,
V_143 , V_144 ) ;
}
int F_55 ( struct V_1 * V_51 , int V_143 , int V_144 ,
void (* V_147)( int , int , void * ) ,
void * V_145 )
{
struct V_4 * V_21 ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_49 ;
}
if ( ( V_143 < 1 ) || ( V_143 > 7 ) ) {
F_5 ( V_18 L_45 ) ;
return - V_49 ;
}
if ( V_21 -> V_149 == NULL ) {
F_5 ( V_18 L_46 ) ;
return - V_49 ;
}
F_15 ( & V_21 -> V_150 ) ;
if ( V_21 -> V_146 [ V_143 - 1 ] . V_147 [ V_144 ] . V_148 ) {
F_16 ( & V_21 -> V_150 ) ;
F_5 ( V_64 L_47 ) ;
return - V_131 ;
}
V_21 -> V_146 [ V_143 - 1 ] . V_78 ++ ;
V_21 -> V_146 [ V_143 - 1 ] . V_147 [ V_144 ] . V_145 = V_145 ;
V_21 -> V_146 [ V_143 - 1 ] . V_147 [ V_144 ] . V_148 = V_147 ;
V_21 -> V_149 ( V_21 , V_143 , 1 , 1 ) ;
F_16 ( & V_21 -> V_150 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_51 , int V_143 , int V_144 )
{
struct V_4 * V_21 ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return;
}
if ( ( V_143 < 1 ) || ( V_143 > 7 ) ) {
F_5 ( V_18 L_45 ) ;
return;
}
if ( V_21 -> V_149 == NULL ) {
F_5 ( V_18 L_46 ) ;
return;
}
F_15 ( & V_21 -> V_150 ) ;
V_21 -> V_146 [ V_143 - 1 ] . V_78 -- ;
if ( V_21 -> V_146 [ V_143 - 1 ] . V_78 == 0 )
V_21 -> V_149 ( V_21 , V_143 , 0 , 1 ) ;
V_21 -> V_146 [ V_143 - 1 ] . V_147 [ V_144 ] . V_148 = NULL ;
V_21 -> V_146 [ V_143 - 1 ] . V_147 [ V_144 ] . V_145 = NULL ;
F_16 ( & V_21 -> V_150 ) ;
}
int F_57 ( struct V_1 * V_51 , int V_143 , int V_144 )
{
struct V_4 * V_21 ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_49 ;
}
if ( ( V_143 < 1 ) || ( V_143 > 7 ) ) {
F_5 ( V_64 L_45 ) ;
return - V_49 ;
}
if ( V_21 -> V_151 == NULL ) {
F_5 ( V_64 L_48 ) ;
return - V_49 ;
}
return V_21 -> V_151 ( V_21 , V_143 , V_144 ) ;
}
struct V_5 * F_58 ( struct V_1 * V_51 )
{
struct V_4 * V_21 ;
struct V_53 * V_152 = NULL ;
struct V_17 * V_153 = NULL ;
struct V_17 * V_154 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_57;
}
F_14 (lm_pos, &bridge->lm_resources) {
V_154 = F_4 ( V_152 ,
struct V_17 , V_10 ) ;
if ( V_154 == NULL ) {
F_5 ( V_18 L_49 ) ;
continue;
}
F_15 ( & V_154 -> V_58 ) ;
if ( V_154 -> V_61 == 0 ) {
V_154 -> V_61 = 1 ;
F_16 ( & V_154 -> V_58 ) ;
V_153 = V_154 ;
break;
}
F_16 ( & V_154 -> V_58 ) ;
}
if ( V_153 == NULL )
goto V_155;
V_6 = F_17 ( sizeof( struct V_5 ) , V_63 ) ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_10 ) ;
goto V_65;
}
V_6 -> type = V_16 ;
V_6 -> V_8 = & V_153 -> V_10 ;
return V_6 ;
V_65:
F_15 ( & V_154 -> V_58 ) ;
V_154 -> V_61 = 0 ;
F_16 ( & V_154 -> V_58 ) ;
V_155:
V_57:
return NULL ;
}
int F_59 ( struct V_5 * V_6 )
{
struct V_17 * V_154 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_50 ) ;
return - V_49 ;
}
V_154 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
return V_154 -> V_156 ;
}
int F_60 ( struct V_5 * V_6 , unsigned long long V_157 ,
T_3 V_30 , T_3 V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_154 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_50 ) ;
return - V_49 ;
}
V_154 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_158 == NULL ) {
F_5 ( V_18 L_51 ) ;
return - V_49 ;
}
return V_21 -> V_158 ( V_154 , V_157 , V_30 , V_31 ) ;
}
int F_61 ( struct V_5 * V_6 , unsigned long long * V_157 ,
T_3 * V_30 , T_3 * V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_154 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_50 ) ;
return - V_49 ;
}
V_154 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_159 == NULL ) {
F_5 ( V_18 L_52 ) ;
return - V_49 ;
}
return V_21 -> V_159 ( V_154 , V_157 , V_30 , V_31 ) ;
}
int F_62 ( struct V_5 * V_6 , int V_160 ,
void (* V_147)( int ) )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_154 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_50 ) ;
return - V_49 ;
}
V_154 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_161 == NULL ) {
F_5 ( V_18 L_53 ) ;
return - V_49 ;
}
return V_21 -> V_161 ( V_154 , V_160 , V_147 ) ;
}
int F_63 ( struct V_5 * V_6 , int V_160 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_154 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_50 ) ;
return - V_49 ;
}
V_154 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_162 == NULL ) {
F_5 ( V_18 L_54 ) ;
return - V_49 ;
}
return V_21 -> V_162 ( V_154 , V_160 ) ;
}
void F_64 ( struct V_5 * V_6 )
{
struct V_17 * V_154 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_50 ) ;
return;
}
V_154 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
F_15 ( & V_154 -> V_58 ) ;
V_154 -> V_61 = 0 ;
F_16 ( & V_154 -> V_58 ) ;
F_20 ( V_6 ) ;
}
int F_65 ( struct V_1 * V_51 )
{
struct V_4 * V_21 ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_49 ;
}
if ( V_21 -> V_163 == NULL ) {
F_5 ( V_64 L_55 ) ;
return - V_49 ;
}
return V_21 -> V_163 ( V_21 ) ;
}
int F_66 ( struct V_1 * V_51 )
{
struct V_4 * V_21 ;
V_21 = V_51 -> V_21 ;
if ( V_21 == NULL ) {
F_29 ( L_8 ) ;
return - V_49 ;
}
return V_21 -> V_164 ;
}
static void F_67 ( struct V_2 * V_3 )
{
F_20 ( F_1 ( V_3 ) ) ;
}
int F_68 ( struct V_4 * V_21 )
{
int V_165 ;
int V_166 = - 1 ;
F_15 ( & V_167 ) ;
for ( V_165 = 0 ; V_165 < sizeof( V_168 ) * 8 ; V_165 ++ ) {
if ( ( V_168 & ( 1 << V_165 ) ) == 0 ) {
V_168 |= ( 1 << V_165 ) ;
V_21 -> V_164 = V_165 ;
F_35 ( & V_21 -> V_169 ) ;
F_50 ( & V_21 -> V_170 , & V_171 ) ;
V_166 = 0 ;
break;
}
}
F_16 ( & V_167 ) ;
return V_166 ;
}
void F_69 ( struct V_4 * V_21 )
{
struct V_1 * V_51 ;
struct V_1 * V_172 ;
F_15 ( & V_167 ) ;
V_168 &= ~ ( 1 << V_21 -> V_164 ) ;
F_70 (vdev, tmp, &bridge->devices, bridge_list) {
F_52 ( & V_51 -> V_173 ) ;
F_52 ( & V_51 -> V_174 ) ;
F_71 ( & V_51 -> V_3 ) ;
}
F_52 ( & V_21 -> V_170 ) ;
F_16 ( & V_167 ) ;
}
static int F_72 ( struct V_175 * V_176 ,
struct V_4 * V_21 , unsigned int V_177 )
{
int V_178 ;
unsigned int V_165 ;
struct V_1 * V_51 ;
struct V_1 * V_172 ;
for ( V_165 = 0 ; V_165 < V_177 ; V_165 ++ ) {
V_51 = F_73 ( sizeof( struct V_1 ) , V_63 ) ;
if ( ! V_51 ) {
V_178 = - V_179 ;
goto V_180;
}
V_51 -> V_164 = V_165 ;
V_51 -> V_21 = V_21 ;
V_51 -> V_3 . V_181 = V_176 ;
V_51 -> V_3 . V_182 = F_67 ;
V_51 -> V_3 . V_11 = V_21 -> V_11 ;
V_51 -> V_3 . V_183 = & V_184 ;
F_74 ( & V_51 -> V_3 , L_56 , V_176 -> V_22 , V_21 -> V_164 ,
V_51 -> V_164 ) ;
V_178 = F_75 ( & V_51 -> V_3 ) ;
if ( V_178 )
goto V_185;
if ( V_51 -> V_3 . V_181 ) {
F_50 ( & V_51 -> V_173 , & V_176 -> V_169 ) ;
F_50 ( & V_51 -> V_174 , & V_21 -> V_169 ) ;
} else
F_71 ( & V_51 -> V_3 ) ;
}
return 0 ;
V_185:
F_76 ( & V_51 -> V_3 ) ;
F_20 ( V_51 ) ;
V_180:
F_70 (vdev, tmp, &drv->devices, drv_list) {
F_52 ( & V_51 -> V_173 ) ;
F_52 ( & V_51 -> V_174 ) ;
F_71 ( & V_51 -> V_3 ) ;
}
return V_178 ;
}
static int F_77 ( struct V_175 * V_176 , unsigned int V_177 )
{
struct V_4 * V_21 ;
int V_178 = 0 ;
F_15 ( & V_167 ) ;
F_78 (bridge, &vme_bus_list, bus_list) {
V_178 = F_72 ( V_176 , V_21 , V_177 ) ;
if ( V_178 )
break;
}
F_16 ( & V_167 ) ;
return V_178 ;
}
int F_79 ( struct V_175 * V_176 , unsigned int V_177 )
{
int V_178 ;
V_176 -> V_186 . V_22 = V_176 -> V_22 ;
V_176 -> V_186 . V_183 = & V_184 ;
F_35 ( & V_176 -> V_169 ) ;
V_178 = F_80 ( & V_176 -> V_186 ) ;
if ( V_178 )
return V_178 ;
V_178 = F_77 ( V_176 , V_177 ) ;
if ( V_178 )
F_81 ( & V_176 -> V_186 ) ;
return V_178 ;
}
void F_82 ( struct V_175 * V_176 )
{
struct V_1 * V_3 , * V_187 ;
F_15 ( & V_167 ) ;
F_70 (dev, dev_tmp, &drv->devices, drv_list) {
F_52 ( & V_3 -> V_173 ) ;
F_52 ( & V_3 -> V_174 ) ;
F_71 ( & V_3 -> V_3 ) ;
}
F_16 ( & V_167 ) ;
F_81 ( & V_176 -> V_186 ) ;
}
static int F_83 ( struct V_2 * V_3 , struct V_188 * V_176 )
{
struct V_175 * V_189 ;
V_189 = F_2 ( V_176 , struct V_175 , V_186 ) ;
if ( V_3 -> V_181 == V_189 ) {
struct V_1 * V_51 = F_1 ( V_3 ) ;
if ( V_189 -> V_190 && V_189 -> V_190 ( V_51 ) )
return 1 ;
V_3 -> V_181 = NULL ;
}
return 0 ;
}
static int F_84 ( struct V_2 * V_3 )
{
int V_27 = - V_191 ;
struct V_175 * V_186 ;
struct V_1 * V_51 = F_1 ( V_3 ) ;
V_186 = V_3 -> V_181 ;
if ( V_186 -> V_192 != NULL )
V_27 = V_186 -> V_192 ( V_51 ) ;
return V_27 ;
}
static int F_85 ( struct V_2 * V_3 )
{
int V_27 = - V_191 ;
struct V_175 * V_186 ;
struct V_1 * V_51 = F_1 ( V_3 ) ;
V_186 = V_3 -> V_181 ;
if ( V_186 -> remove != NULL )
V_27 = V_186 -> remove ( V_51 ) ;
return V_27 ;
}
static int T_7 F_86 ( void )
{
return F_87 ( & V_184 ) ;
}
static void T_8 F_88 ( void )
{
F_89 ( & V_184 ) ;
}
