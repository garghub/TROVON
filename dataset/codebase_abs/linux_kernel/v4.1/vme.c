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
int F_27 ( struct V_5 * V_6 , struct V_85 * V_86 )
{
struct V_9 * V_64 ;
T_6 V_87 ;
unsigned long V_88 ;
if ( V_6 -> type != V_7 ) {
F_28 ( L_19 ) ;
return - V_48 ;
}
V_64 = F_4 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_87 = V_64 -> V_89 . V_90 + ( V_86 -> V_91 << V_92 ) ;
V_88 = V_86 -> V_93 - V_86 -> V_94 ;
if ( V_87 + V_88 > V_64 -> V_89 . V_95 + 1 ) {
F_28 ( L_25 ) ;
return - V_36 ;
}
V_86 -> V_96 = F_29 ( V_86 -> V_96 ) ;
return F_30 ( V_86 , V_87 , V_86 -> V_93 - V_86 -> V_94 ) ;
}
void F_31 ( struct V_5 * V_6 )
{
struct V_9 * V_69 ;
if ( V_6 -> type != V_7 ) {
F_5 ( V_18 L_19 ) ;
return;
}
V_69 = F_4 ( V_6 -> V_8 , struct V_9 ,
V_10 ) ;
if ( V_69 == NULL ) {
F_5 ( V_18 L_26 ) ;
return;
}
F_21 ( & V_69 -> V_70 ) ;
if ( V_69 -> V_59 == 0 )
F_5 ( V_18 L_16 ) ;
V_69 -> V_59 = 0 ;
F_22 ( & V_69 -> V_70 ) ;
F_19 ( V_6 ) ;
}
struct V_5 * F_32 ( struct V_1 * V_49 , T_3 V_97 )
{
struct V_4 * V_21 ;
struct V_51 * V_98 = NULL ;
struct V_15 * V_99 = NULL ;
struct V_15 * V_100 = NULL ;
struct V_5 * V_6 = NULL ;
F_5 ( V_18 L_27 ) ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_55;
}
F_13 (dma_pos, &bridge->dma_resources) {
V_100 = F_4 ( V_98 ,
struct V_15 , V_10 ) ;
if ( V_100 == NULL ) {
F_5 ( V_18 L_28 ) ;
continue;
}
F_14 ( & V_100 -> V_56 ) ;
if ( ( ( V_100 -> V_101 & V_97 ) == V_97 ) &&
( V_100 -> V_59 == 0 ) ) {
V_100 -> V_59 = 1 ;
F_15 ( & V_100 -> V_56 ) ;
V_99 = V_100 ;
break;
}
F_15 ( & V_100 -> V_56 ) ;
}
if ( V_99 == NULL )
goto V_102;
V_6 = F_16 ( sizeof( struct V_5 ) , V_61 ) ;
if ( V_6 == NULL ) {
F_5 ( V_62 L_10 ) ;
goto V_63;
}
V_6 -> type = V_14 ;
V_6 -> V_8 = & V_99 -> V_10 ;
return V_6 ;
V_63:
F_14 ( & V_100 -> V_56 ) ;
V_100 -> V_59 = 0 ;
F_15 ( & V_100 -> V_56 ) ;
V_102:
V_55:
return NULL ;
}
struct V_103 * F_33 ( struct V_5 * V_6 )
{
struct V_15 * V_104 ;
struct V_103 * V_105 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_29 ) ;
return NULL ;
}
V_104 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
V_105 = F_16 ( sizeof( struct V_103 ) , V_61 ) ;
if ( V_105 == NULL ) {
F_5 ( V_18 L_30 ) ;
return NULL ;
}
F_34 ( & V_105 -> V_106 ) ;
V_105 -> V_11 = V_104 ;
F_35 ( & V_105 -> V_56 ) ;
return V_105 ;
}
struct V_107 * F_36 ( T_3 V_108 , T_3 type )
{
struct V_107 * V_109 ;
struct V_110 * V_111 ;
V_109 = F_16 ( sizeof( struct V_107 ) , V_61 ) ;
if ( V_109 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_112;
}
V_111 = F_16 ( sizeof( struct V_110 ) , V_61 ) ;
if ( V_111 == NULL ) {
F_5 ( V_18 L_32 ) ;
goto V_113;
}
V_109 -> type = V_114 ;
V_109 -> V_115 = ( void * ) V_111 ;
V_111 -> V_108 = V_108 ;
V_111 -> type = type ;
return V_109 ;
V_113:
F_19 ( V_109 ) ;
V_112:
return NULL ;
}
struct V_107 * F_37 ( T_2 V_50 )
{
struct V_107 * V_109 ;
struct V_116 * V_117 ;
V_109 = F_16 ( sizeof( struct V_107 ) , V_61 ) ;
if ( V_109 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_112;
}
V_117 = F_16 ( sizeof( struct V_116 ) , V_61 ) ;
if ( V_117 == NULL ) {
F_5 ( V_18 L_33 ) ;
goto V_118;
}
V_109 -> type = V_119 ;
V_109 -> V_115 = ( void * ) V_117 ;
V_117 -> V_50 = V_50 ;
return V_109 ;
V_118:
F_19 ( V_109 ) ;
V_112:
return NULL ;
}
struct V_107 * F_38 ( unsigned long long V_50 ,
T_3 V_30 , T_3 V_31 , T_3 V_32 )
{
struct V_107 * V_109 ;
struct V_120 * V_121 ;
V_109 = F_16 (
sizeof( struct V_107 ) , V_61 ) ;
if ( V_109 == NULL ) {
F_5 ( V_18 L_31 ) ;
goto V_112;
}
V_121 = F_16 ( sizeof( struct V_120 ) , V_61 ) ;
if ( V_121 == NULL ) {
F_5 ( V_18 L_34 ) ;
goto V_122;
}
V_109 -> type = V_123 ;
V_109 -> V_115 = ( void * ) V_121 ;
V_121 -> V_50 = V_50 ;
V_121 -> V_30 = V_30 ;
V_121 -> V_31 = V_31 ;
V_121 -> V_32 = V_32 ;
return V_109 ;
V_122:
F_19 ( V_109 ) ;
V_112:
return NULL ;
}
void F_39 ( struct V_107 * V_109 )
{
F_19 ( V_109 -> V_115 ) ;
F_19 ( V_109 ) ;
}
int F_40 ( struct V_103 * V_10 , struct V_107 * V_124 ,
struct V_107 * V_125 , T_1 V_76 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_126 == NULL ) {
F_5 ( V_62 L_35 ) ;
return - V_48 ;
}
if ( ! F_41 ( & V_10 -> V_56 ) ) {
F_5 ( V_18 L_36 ) ;
return - V_48 ;
}
V_27 = V_21 -> V_126 ( V_10 , V_124 , V_125 , V_76 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
int F_42 ( struct V_103 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_127 == NULL ) {
F_5 ( V_18 L_37 ) ;
return - V_48 ;
}
F_14 ( & V_10 -> V_56 ) ;
V_27 = V_21 -> V_127 ( V_10 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
int F_43 ( struct V_103 * V_10 )
{
struct V_4 * V_21 = V_10 -> V_11 -> V_11 ;
int V_27 ;
if ( V_21 -> V_128 == NULL ) {
F_5 ( V_62 L_38 ) ;
return - V_48 ;
}
if ( ! F_41 ( & V_10 -> V_56 ) ) {
F_5 ( V_18 L_39 ) ;
return - V_48 ;
}
V_27 = V_21 -> V_128 ( V_10 ) ;
if ( V_27 ) {
F_5 ( V_18 L_40 ) ;
F_15 ( & V_10 -> V_56 ) ;
return V_27 ;
}
F_15 ( & V_10 -> V_56 ) ;
F_19 ( V_10 ) ;
return V_27 ;
}
int F_44 ( struct V_5 * V_6 )
{
struct V_15 * V_104 ;
if ( V_6 -> type != V_14 ) {
F_5 ( V_18 L_29 ) ;
return - V_48 ;
}
V_104 = F_4 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
if ( ! F_41 ( & V_104 -> V_56 ) ) {
F_5 ( V_18 L_41 ) ;
return - V_129 ;
}
if ( ! ( F_45 ( & V_104 -> V_130 ) && F_45 ( & V_104 -> V_131 ) ) ) {
F_5 ( V_62 L_42 ) ;
F_15 ( & V_104 -> V_56 ) ;
return - V_129 ;
}
V_104 -> V_59 = 0 ;
F_15 ( & V_104 -> V_56 ) ;
F_19 ( V_6 ) ;
return 0 ;
}
void F_46 ( struct V_4 * V_21 , int V_132 , int V_133 )
{
void (* F_47)( int , int , void * );
void * V_134 ;
F_47 = V_21 -> V_135 [ V_132 - 1 ] . V_136 [ V_133 ] . V_137 ;
V_134 = V_21 -> V_135 [ V_132 - 1 ] . V_136 [ V_133 ] . V_134 ;
if ( F_47 != NULL )
F_47 ( V_132 , V_133 , V_134 ) ;
else
F_5 ( V_62 L_43 ,
V_132 , V_133 ) ;
}
int F_48 ( struct V_1 * V_49 , int V_132 , int V_133 ,
void (* V_136)( int , int , void * ) ,
void * V_134 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_48 ;
}
if ( ( V_132 < 1 ) || ( V_132 > 7 ) ) {
F_5 ( V_18 L_44 ) ;
return - V_48 ;
}
if ( V_21 -> V_138 == NULL ) {
F_5 ( V_18 L_45 ) ;
return - V_48 ;
}
F_14 ( & V_21 -> V_139 ) ;
if ( V_21 -> V_135 [ V_132 - 1 ] . V_136 [ V_133 ] . V_137 ) {
F_15 ( & V_21 -> V_139 ) ;
F_5 ( V_62 L_46 ) ;
return - V_129 ;
}
V_21 -> V_135 [ V_132 - 1 ] . V_76 ++ ;
V_21 -> V_135 [ V_132 - 1 ] . V_136 [ V_133 ] . V_134 = V_134 ;
V_21 -> V_135 [ V_132 - 1 ] . V_136 [ V_133 ] . V_137 = V_136 ;
V_21 -> V_138 ( V_21 , V_132 , 1 , 1 ) ;
F_15 ( & V_21 -> V_139 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_49 , int V_132 , int V_133 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return;
}
if ( ( V_132 < 1 ) || ( V_132 > 7 ) ) {
F_5 ( V_18 L_44 ) ;
return;
}
if ( V_21 -> V_138 == NULL ) {
F_5 ( V_18 L_45 ) ;
return;
}
F_14 ( & V_21 -> V_139 ) ;
V_21 -> V_135 [ V_132 - 1 ] . V_76 -- ;
if ( V_21 -> V_135 [ V_132 - 1 ] . V_76 == 0 )
V_21 -> V_138 ( V_21 , V_132 , 0 , 1 ) ;
V_21 -> V_135 [ V_132 - 1 ] . V_136 [ V_133 ] . V_137 = NULL ;
V_21 -> V_135 [ V_132 - 1 ] . V_136 [ V_133 ] . V_134 = NULL ;
F_15 ( & V_21 -> V_139 ) ;
}
int F_50 ( struct V_1 * V_49 , int V_132 , int V_133 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_48 ;
}
if ( ( V_132 < 1 ) || ( V_132 > 7 ) ) {
F_5 ( V_62 L_44 ) ;
return - V_48 ;
}
if ( V_21 -> V_140 == NULL ) {
F_5 ( V_62 L_47 ) ;
return - V_48 ;
}
return V_21 -> V_140 ( V_21 , V_132 , V_133 ) ;
}
struct V_5 * F_51 ( struct V_1 * V_49 )
{
struct V_4 * V_21 ;
struct V_51 * V_141 = NULL ;
struct V_17 * V_142 = NULL ;
struct V_17 * V_143 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
goto V_55;
}
F_13 (lm_pos, &bridge->lm_resources) {
V_143 = F_4 ( V_141 ,
struct V_17 , V_10 ) ;
if ( V_143 == NULL ) {
F_5 ( V_18 L_48 ) ;
continue;
}
F_14 ( & V_143 -> V_56 ) ;
if ( V_143 -> V_59 == 0 ) {
V_143 -> V_59 = 1 ;
F_15 ( & V_143 -> V_56 ) ;
V_142 = V_143 ;
break;
}
F_15 ( & V_143 -> V_56 ) ;
}
if ( V_142 == NULL )
goto V_144;
V_6 = F_16 ( sizeof( struct V_5 ) , V_61 ) ;
if ( V_6 == NULL ) {
F_5 ( V_18 L_10 ) ;
goto V_63;
}
V_6 -> type = V_16 ;
V_6 -> V_8 = & V_142 -> V_10 ;
return V_6 ;
V_63:
F_14 ( & V_143 -> V_56 ) ;
V_143 -> V_59 = 0 ;
F_15 ( & V_143 -> V_56 ) ;
V_144:
V_55:
return NULL ;
}
int F_52 ( struct V_5 * V_6 )
{
struct V_17 * V_143 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_48 ;
}
V_143 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
return V_143 -> V_145 ;
}
int F_53 ( struct V_5 * V_6 , unsigned long long V_146 ,
T_3 V_30 , T_3 V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_143 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_48 ;
}
V_143 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_147 == NULL ) {
F_5 ( V_18 L_50 ) ;
return - V_48 ;
}
return V_21 -> V_147 ( V_143 , V_146 , V_30 , V_31 ) ;
}
int F_54 ( struct V_5 * V_6 , unsigned long long * V_146 ,
T_3 * V_30 , T_3 * V_31 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_143 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_48 ;
}
V_143 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_148 == NULL ) {
F_5 ( V_18 L_51 ) ;
return - V_48 ;
}
return V_21 -> V_148 ( V_143 , V_146 , V_30 , V_31 ) ;
}
int F_55 ( struct V_5 * V_6 , int V_149 ,
void (* V_136)( int ) )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_143 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_48 ;
}
V_143 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_150 == NULL ) {
F_5 ( V_18 L_52 ) ;
return - V_48 ;
}
return V_21 -> V_150 ( V_143 , V_149 , V_136 ) ;
}
int F_56 ( struct V_5 * V_6 , int V_149 )
{
struct V_4 * V_21 = F_3 ( V_6 ) ;
struct V_17 * V_143 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return - V_48 ;
}
V_143 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_151 == NULL ) {
F_5 ( V_18 L_53 ) ;
return - V_48 ;
}
return V_21 -> V_151 ( V_143 , V_149 ) ;
}
void F_57 ( struct V_5 * V_6 )
{
struct V_17 * V_143 ;
if ( V_6 -> type != V_16 ) {
F_5 ( V_18 L_49 ) ;
return;
}
V_143 = F_4 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
F_14 ( & V_143 -> V_56 ) ;
V_143 -> V_59 = 0 ;
F_15 ( & V_143 -> V_56 ) ;
F_19 ( V_6 ) ;
}
int F_58 ( struct V_1 * V_49 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_5 ( V_18 L_8 ) ;
return - V_48 ;
}
if ( V_21 -> V_152 == NULL ) {
F_5 ( V_62 L_54 ) ;
return - V_48 ;
}
return V_21 -> V_152 ( V_21 ) ;
}
int F_59 ( struct V_1 * V_49 )
{
struct V_4 * V_21 ;
V_21 = V_49 -> V_21 ;
if ( V_21 == NULL ) {
F_28 ( L_8 ) ;
return - V_48 ;
}
return V_21 -> V_153 ;
}
static void F_60 ( struct V_2 * V_3 )
{
F_19 ( F_1 ( V_3 ) ) ;
}
int F_61 ( struct V_4 * V_21 )
{
int V_154 ;
int V_155 = - 1 ;
F_14 ( & V_156 ) ;
for ( V_154 = 0 ; V_154 < sizeof( V_157 ) * 8 ; V_154 ++ ) {
if ( ( V_157 & ( 1 << V_154 ) ) == 0 ) {
V_157 |= ( 1 << V_154 ) ;
V_21 -> V_153 = V_154 ;
F_34 ( & V_21 -> V_158 ) ;
F_62 ( & V_21 -> V_159 , & V_160 ) ;
V_155 = 0 ;
break;
}
}
F_15 ( & V_156 ) ;
return V_155 ;
}
void F_63 ( struct V_4 * V_21 )
{
struct V_1 * V_49 ;
struct V_1 * V_161 ;
F_14 ( & V_156 ) ;
V_157 &= ~ ( 1 << V_21 -> V_153 ) ;
F_64 (vdev, tmp, &bridge->devices, bridge_list) {
F_65 ( & V_49 -> V_162 ) ;
F_65 ( & V_49 -> V_163 ) ;
F_66 ( & V_49 -> V_3 ) ;
}
F_65 ( & V_21 -> V_159 ) ;
F_15 ( & V_156 ) ;
}
static int F_67 ( struct V_164 * V_165 ,
struct V_4 * V_21 , unsigned int V_166 )
{
int V_167 ;
unsigned int V_154 ;
struct V_1 * V_49 ;
struct V_1 * V_161 ;
for ( V_154 = 0 ; V_154 < V_166 ; V_154 ++ ) {
V_49 = F_68 ( sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_49 ) {
V_167 = - V_168 ;
goto V_169;
}
V_49 -> V_153 = V_154 ;
V_49 -> V_21 = V_21 ;
V_49 -> V_3 . V_170 = V_165 ;
V_49 -> V_3 . V_171 = F_60 ;
V_49 -> V_3 . V_11 = V_21 -> V_11 ;
V_49 -> V_3 . V_172 = & V_173 ;
F_69 ( & V_49 -> V_3 , L_55 , V_165 -> V_22 , V_21 -> V_153 ,
V_49 -> V_153 ) ;
V_167 = F_70 ( & V_49 -> V_3 ) ;
if ( V_167 )
goto V_174;
if ( V_49 -> V_3 . V_170 ) {
F_62 ( & V_49 -> V_162 , & V_165 -> V_158 ) ;
F_62 ( & V_49 -> V_163 , & V_21 -> V_158 ) ;
} else
F_66 ( & V_49 -> V_3 ) ;
}
return 0 ;
V_174:
F_71 ( & V_49 -> V_3 ) ;
F_19 ( V_49 ) ;
V_169:
F_64 (vdev, tmp, &drv->devices, drv_list) {
F_65 ( & V_49 -> V_162 ) ;
F_65 ( & V_49 -> V_163 ) ;
F_66 ( & V_49 -> V_3 ) ;
}
return V_167 ;
}
static int F_72 ( struct V_164 * V_165 , unsigned int V_166 )
{
struct V_4 * V_21 ;
int V_167 = 0 ;
F_14 ( & V_156 ) ;
F_73 (bridge, &vme_bus_list, bus_list) {
V_167 = F_67 ( V_165 , V_21 , V_166 ) ;
if ( V_167 )
break;
}
F_15 ( & V_156 ) ;
return V_167 ;
}
int F_74 ( struct V_164 * V_165 , unsigned int V_166 )
{
int V_167 ;
V_165 -> V_175 . V_22 = V_165 -> V_22 ;
V_165 -> V_175 . V_172 = & V_173 ;
F_34 ( & V_165 -> V_158 ) ;
V_167 = F_75 ( & V_165 -> V_175 ) ;
if ( V_167 )
return V_167 ;
V_167 = F_72 ( V_165 , V_166 ) ;
if ( V_167 )
F_76 ( & V_165 -> V_175 ) ;
return V_167 ;
}
void F_77 ( struct V_164 * V_165 )
{
struct V_1 * V_3 , * V_176 ;
F_14 ( & V_156 ) ;
F_64 (dev, dev_tmp, &drv->devices, drv_list) {
F_65 ( & V_3 -> V_162 ) ;
F_65 ( & V_3 -> V_163 ) ;
F_66 ( & V_3 -> V_3 ) ;
}
F_15 ( & V_156 ) ;
F_76 ( & V_165 -> V_175 ) ;
}
static int F_78 ( struct V_2 * V_3 , struct V_177 * V_165 )
{
struct V_164 * V_178 ;
V_178 = F_2 ( V_165 , struct V_164 , V_175 ) ;
if ( V_3 -> V_170 == V_178 ) {
struct V_1 * V_49 = F_1 ( V_3 ) ;
if ( V_178 -> V_179 && V_178 -> V_179 ( V_49 ) )
return 1 ;
V_3 -> V_170 = NULL ;
}
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_27 = - V_180 ;
struct V_164 * V_175 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
V_175 = V_3 -> V_170 ;
if ( V_175 -> V_181 != NULL )
V_27 = V_175 -> V_181 ( V_49 ) ;
return V_27 ;
}
static int F_80 ( struct V_2 * V_3 )
{
int V_27 = - V_180 ;
struct V_164 * V_175 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
V_175 = V_3 -> V_170 ;
if ( V_175 -> remove != NULL )
V_27 = V_175 -> remove ( V_49 ) ;
return V_27 ;
}
static int T_7 F_81 ( void )
{
return F_82 ( & V_173 ) ;
}
static void T_8 F_83 ( void )
{
F_84 ( & V_173 ) ;
}
