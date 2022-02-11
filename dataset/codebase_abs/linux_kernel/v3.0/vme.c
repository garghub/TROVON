static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static struct V_1 * F_2 ( struct V_5 * V_6 )
{
switch ( V_6 -> type ) {
case V_7 :
return F_3 ( V_6 -> V_8 , struct V_9 ,
V_10 ) -> V_11 ;
break;
case V_12 :
return F_3 ( V_6 -> V_8 , struct V_13 ,
V_10 ) -> V_11 ;
break;
case V_14 :
return F_3 ( V_6 -> V_8 , struct V_15 ,
V_10 ) -> V_11 ;
break;
case V_16 :
return F_3 ( V_6 -> V_8 , struct V_17 ,
V_10 ) -> V_11 ;
break;
default:
F_4 ( V_18 L_1 ) ;
return NULL ;
break;
}
}
void * F_5 ( struct V_5 * V_6 , T_1 V_19 ,
T_2 * V_20 )
{
struct V_1 * V_21 ;
struct V_22 * V_23 ;
if ( V_6 == NULL ) {
F_4 ( V_18 L_2 ) ;
return NULL ;
}
V_21 = F_2 ( V_6 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_3 ) ;
return NULL ;
}
if ( V_21 -> V_11 == NULL ) {
F_4 ( V_18 L_4 ) ;
return NULL ;
}
V_23 = F_6 ( V_21 -> V_11 , struct V_22 , V_3 ) ;
return F_7 ( V_23 , V_19 , V_20 ) ;
}
void F_8 ( struct V_5 * V_6 , T_1 V_19 ,
void * V_24 , T_2 V_20 )
{
struct V_1 * V_21 ;
struct V_22 * V_23 ;
if ( V_6 == NULL ) {
F_4 ( V_18 L_2 ) ;
return;
}
V_21 = F_2 ( V_6 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_3 ) ;
return;
}
V_23 = F_6 ( V_21 -> V_11 , struct V_22 , V_3 ) ;
F_9 ( V_23 , V_19 , V_24 , V_20 ) ;
}
T_1 F_10 ( struct V_5 * V_6 )
{
int V_25 , V_26 ;
unsigned long long V_27 , V_19 ;
T_2 V_28 ;
T_3 V_29 ;
T_4 V_30 ;
T_5 V_31 ;
switch ( V_6 -> type ) {
case V_7 :
V_26 = F_11 ( V_6 , & V_25 , & V_27 , & V_19 ,
& V_29 , & V_30 , & V_31 ) ;
return V_19 ;
break;
case V_12 :
V_26 = F_12 ( V_6 , & V_25 , & V_27 , & V_19 ,
& V_28 , & V_29 , & V_30 ) ;
return V_19 ;
break;
case V_14 :
return 0 ;
break;
default:
F_4 ( V_18 L_1 ) ;
return 0 ;
break;
}
}
static int F_13 ( T_3 V_29 , unsigned long long V_32 ,
unsigned long long V_19 )
{
int V_26 = 0 ;
switch ( V_29 ) {
case V_33 :
if ( ( ( V_32 + V_19 ) > V_34 ) ||
( V_32 > V_34 ) )
V_26 = - V_35 ;
break;
case V_36 :
if ( ( ( V_32 + V_19 ) > V_37 ) ||
( V_32 > V_37 ) )
V_26 = - V_35 ;
break;
case V_38 :
if ( ( ( V_32 + V_19 ) > V_39 ) ||
( V_32 > V_39 ) )
V_26 = - V_35 ;
break;
case V_40 :
break;
case V_41 :
if ( ( ( V_32 + V_19 ) > V_42 ) ||
( V_32 > V_42 ) )
V_26 = - V_35 ;
break;
case V_43 :
case V_44 :
case V_45 :
case V_46 :
break;
default:
F_4 ( V_18 L_5 ) ;
V_26 = - V_47 ;
break;
}
return V_26 ;
}
struct V_5 * F_14 ( struct V_2 * V_3 ,
T_3 V_48 , T_4 V_30 )
{
struct V_1 * V_21 ;
struct V_49 * V_50 = NULL ;
struct V_13 * V_51 = NULL ;
struct V_13 * V_52 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = F_1 ( V_3 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_6 ) ;
goto V_53;
}
F_15 (slave_pos, &bridge->slave_resources) {
V_52 = F_3 ( V_50 ,
struct V_13 , V_10 ) ;
if ( V_52 == NULL ) {
F_4 ( V_18 L_7 ) ;
continue;
}
F_16 ( & V_52 -> V_54 ) ;
if ( ( ( V_52 -> V_55 & V_48 ) == V_48 ) &&
( ( V_52 -> V_56 & V_30 ) == V_30 ) &&
( V_52 -> V_57 == 0 ) ) {
V_52 -> V_57 = 1 ;
F_17 ( & V_52 -> V_54 ) ;
V_51 = V_52 ;
break;
}
F_17 ( & V_52 -> V_54 ) ;
}
if ( V_51 == NULL )
goto V_58;
V_6 = F_18 ( sizeof( struct V_5 ) , V_59 ) ;
if ( V_6 == NULL ) {
F_4 ( V_60 L_8 ) ;
goto V_61;
}
V_6 -> type = V_12 ;
V_6 -> V_8 = & V_51 -> V_10 ;
return V_6 ;
V_61:
F_16 ( & V_52 -> V_54 ) ;
V_52 -> V_57 = 0 ;
F_17 ( & V_52 -> V_54 ) ;
V_58:
V_53:
return NULL ;
}
int F_19 ( struct V_5 * V_6 , int V_25 ,
unsigned long long V_32 , unsigned long long V_19 ,
T_2 V_28 , T_3 V_29 , T_4 V_30 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_13 * V_62 ;
int V_26 ;
if ( V_6 -> type != V_12 ) {
F_4 ( V_18 L_9 ) ;
return - V_47 ;
}
V_62 = F_3 ( V_6 -> V_8 , struct V_13 , V_10 ) ;
if ( V_21 -> V_63 == NULL ) {
F_4 ( V_18 L_10 ) ;
return - V_64 ;
}
if ( ! ( ( ( V_62 -> V_55 & V_29 ) == V_29 ) &&
( ( V_62 -> V_56 & V_30 ) == V_30 ) ) ) {
F_4 ( V_18 L_11 ) ;
return - V_47 ;
}
V_26 = F_13 ( V_29 , V_32 , V_19 ) ;
if ( V_26 )
return V_26 ;
return V_21 -> V_63 ( V_62 , V_25 , V_32 , V_19 , V_28 ,
V_29 , V_30 ) ;
}
int F_12 ( struct V_5 * V_6 , int * V_25 ,
unsigned long long * V_32 , unsigned long long * V_19 ,
T_2 * V_28 , T_3 * V_29 , T_4 * V_30 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_13 * V_62 ;
if ( V_6 -> type != V_12 ) {
F_4 ( V_18 L_9 ) ;
return - V_47 ;
}
V_62 = F_3 ( V_6 -> V_8 , struct V_13 , V_10 ) ;
if ( V_21 -> V_65 == NULL ) {
F_4 ( V_18 L_12 ) ;
return - V_47 ;
}
return V_21 -> V_65 ( V_62 , V_25 , V_32 , V_19 , V_28 ,
V_29 , V_30 ) ;
}
void F_20 ( struct V_5 * V_6 )
{
struct V_13 * V_52 ;
if ( V_6 -> type != V_12 ) {
F_4 ( V_18 L_9 ) ;
return;
}
V_52 = F_3 ( V_6 -> V_8 , struct V_13 ,
V_10 ) ;
if ( V_52 == NULL ) {
F_4 ( V_18 L_13 ) ;
return;
}
F_16 ( & V_52 -> V_54 ) ;
if ( V_52 -> V_57 == 0 )
F_4 ( V_18 L_14 ) ;
V_52 -> V_57 = 0 ;
F_17 ( & V_52 -> V_54 ) ;
F_21 ( V_6 ) ;
}
struct V_5 * F_22 ( struct V_2 * V_3 ,
T_3 V_48 , T_4 V_30 , T_5 V_31 )
{
struct V_1 * V_21 ;
struct V_49 * V_66 = NULL ;
struct V_9 * V_51 = NULL ;
struct V_9 * V_67 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = F_1 ( V_3 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_6 ) ;
goto V_53;
}
F_15 (master_pos, &bridge->master_resources) {
V_67 = F_3 ( V_66 ,
struct V_9 , V_10 ) ;
if ( V_67 == NULL ) {
F_4 ( V_60 L_15 ) ;
continue;
}
F_23 ( & V_67 -> V_68 ) ;
if ( ( ( V_67 -> V_55 & V_48 ) == V_48 ) &&
( ( V_67 -> V_56 & V_30 ) == V_30 ) &&
( ( V_67 -> V_69 & V_31 ) == V_31 ) &&
( V_67 -> V_57 == 0 ) ) {
V_67 -> V_57 = 1 ;
F_24 ( & V_67 -> V_68 ) ;
V_51 = V_67 ;
break;
}
F_24 ( & V_67 -> V_68 ) ;
}
if ( V_51 == NULL ) {
F_4 ( V_18 L_16 ) ;
goto V_58;
}
V_6 = F_18 ( sizeof( struct V_5 ) , V_59 ) ;
if ( V_6 == NULL ) {
F_4 ( V_18 L_8 ) ;
goto V_61;
}
V_6 -> type = V_7 ;
V_6 -> V_8 = & V_51 -> V_10 ;
return V_6 ;
V_61:
F_23 ( & V_67 -> V_68 ) ;
V_67 -> V_57 = 0 ;
F_24 ( & V_67 -> V_68 ) ;
V_58:
V_53:
return NULL ;
}
int F_25 ( struct V_5 * V_6 , int V_25 ,
unsigned long long V_32 , unsigned long long V_19 ,
T_3 V_29 , T_4 V_30 , T_5 V_31 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_9 * V_62 ;
int V_26 ;
if ( V_6 -> type != V_7 ) {
F_4 ( V_18 L_17 ) ;
return - V_47 ;
}
V_62 = F_3 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
if ( V_21 -> V_70 == NULL ) {
F_4 ( V_60 L_18 ) ;
return - V_47 ;
}
if ( ! ( ( ( V_62 -> V_55 & V_29 ) == V_29 ) &&
( ( V_62 -> V_56 & V_30 ) == V_30 ) &&
( ( V_62 -> V_69 & V_31 ) == V_31 ) ) ) {
F_4 ( V_60 L_11 ) ;
return - V_47 ;
}
V_26 = F_13 ( V_29 , V_32 , V_19 ) ;
if ( V_26 )
return V_26 ;
return V_21 -> V_70 ( V_62 , V_25 , V_32 , V_19 , V_29 ,
V_30 , V_31 ) ;
}
int F_11 ( struct V_5 * V_6 , int * V_25 ,
unsigned long long * V_32 , unsigned long long * V_19 ,
T_3 * V_29 , T_4 * V_30 , T_5 * V_31 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_9 * V_62 ;
if ( V_6 -> type != V_7 ) {
F_4 ( V_18 L_17 ) ;
return - V_47 ;
}
V_62 = F_3 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
if ( V_21 -> V_71 == NULL ) {
F_4 ( V_60 L_18 ) ;
return - V_47 ;
}
return V_21 -> V_71 ( V_62 , V_25 , V_32 , V_19 , V_29 ,
V_30 , V_31 ) ;
}
T_6 F_26 ( struct V_5 * V_6 , void * V_72 , T_1 V_73 ,
T_7 V_74 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_9 * V_62 ;
T_1 V_75 ;
if ( V_21 -> V_76 == NULL ) {
F_4 ( V_60 L_19 ) ;
return - V_47 ;
}
if ( V_6 -> type != V_7 ) {
F_4 ( V_18 L_17 ) ;
return - V_47 ;
}
V_62 = F_3 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_75 = F_10 ( V_6 ) ;
if ( V_74 > V_75 ) {
F_4 ( V_60 L_20 ) ;
return - V_35 ;
}
if ( ( V_74 + V_73 ) > V_75 )
V_73 = V_75 - V_74 ;
return V_21 -> V_76 ( V_62 , V_72 , V_73 , V_74 ) ;
}
T_6 F_27 ( struct V_5 * V_6 , void * V_72 ,
T_1 V_73 , T_7 V_74 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_9 * V_62 ;
T_1 V_75 ;
if ( V_21 -> V_77 == NULL ) {
F_4 ( V_60 L_21 ) ;
return - V_47 ;
}
if ( V_6 -> type != V_7 ) {
F_4 ( V_18 L_17 ) ;
return - V_47 ;
}
V_62 = F_3 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
V_75 = F_10 ( V_6 ) ;
if ( V_74 > V_75 ) {
F_4 ( V_60 L_20 ) ;
return - V_35 ;
}
if ( ( V_74 + V_73 ) > V_75 )
V_73 = V_75 - V_74 ;
return V_21 -> V_77 ( V_62 , V_72 , V_73 , V_74 ) ;
}
unsigned int F_28 ( struct V_5 * V_6 , unsigned int V_78 ,
unsigned int V_79 , unsigned int V_80 , T_7 V_74 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_9 * V_62 ;
if ( V_21 -> V_81 == NULL ) {
F_4 ( V_60 L_21 ) ;
return - V_47 ;
}
if ( V_6 -> type != V_7 ) {
F_4 ( V_18 L_17 ) ;
return - V_47 ;
}
V_62 = F_3 ( V_6 -> V_8 , struct V_9 , V_10 ) ;
return V_21 -> V_81 ( V_62 , V_78 , V_79 , V_80 , V_74 ) ;
}
void F_29 ( struct V_5 * V_6 )
{
struct V_9 * V_67 ;
if ( V_6 -> type != V_7 ) {
F_4 ( V_18 L_17 ) ;
return;
}
V_67 = F_3 ( V_6 -> V_8 , struct V_9 ,
V_10 ) ;
if ( V_67 == NULL ) {
F_4 ( V_18 L_22 ) ;
return;
}
F_23 ( & V_67 -> V_68 ) ;
if ( V_67 -> V_57 == 0 )
F_4 ( V_18 L_14 ) ;
V_67 -> V_57 = 0 ;
F_24 ( & V_67 -> V_68 ) ;
F_21 ( V_6 ) ;
}
struct V_5 * F_30 ( struct V_2 * V_3 , T_8 V_82 )
{
struct V_1 * V_21 ;
struct V_49 * V_83 = NULL ;
struct V_15 * V_84 = NULL ;
struct V_15 * V_85 = NULL ;
struct V_5 * V_6 = NULL ;
F_4 ( V_18 L_23 ) ;
V_21 = F_1 ( V_3 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_6 ) ;
goto V_53;
}
F_15 (dma_pos, &bridge->dma_resources) {
V_85 = F_3 ( V_83 ,
struct V_15 , V_10 ) ;
if ( V_85 == NULL ) {
F_4 ( V_18 L_24 ) ;
continue;
}
F_16 ( & V_85 -> V_54 ) ;
if ( ( ( V_85 -> V_86 & V_82 ) == V_82 ) &&
( V_85 -> V_57 == 0 ) ) {
V_85 -> V_57 = 1 ;
F_17 ( & V_85 -> V_54 ) ;
V_84 = V_85 ;
break;
}
F_17 ( & V_85 -> V_54 ) ;
}
if ( V_84 == NULL )
goto V_87;
V_6 = F_18 ( sizeof( struct V_5 ) , V_59 ) ;
if ( V_6 == NULL ) {
F_4 ( V_60 L_8 ) ;
goto V_61;
}
V_6 -> type = V_14 ;
V_6 -> V_8 = & V_84 -> V_10 ;
return V_6 ;
V_61:
F_16 ( & V_85 -> V_54 ) ;
V_85 -> V_57 = 0 ;
F_17 ( & V_85 -> V_54 ) ;
V_87:
V_53:
return NULL ;
}
struct V_88 * F_31 ( struct V_5 * V_6 )
{
struct V_15 * V_89 ;
struct V_88 * V_90 ;
if ( V_6 -> type != V_14 ) {
F_4 ( V_18 L_25 ) ;
return NULL ;
}
V_89 = F_3 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
V_90 = F_18 ( sizeof( struct V_88 ) , V_59 ) ;
if ( V_90 == NULL ) {
F_4 ( V_18 L_26 ) ;
return NULL ;
}
F_32 ( & V_90 -> V_91 ) ;
V_90 -> V_11 = V_89 ;
F_33 ( & V_90 -> V_54 ) ;
return V_90 ;
}
struct V_92 * F_34 ( T_9 V_93 ,
T_10 type )
{
struct V_92 * V_94 ;
struct V_95 * V_96 ;
V_94 = F_18 ( sizeof( struct V_92 ) , V_59 ) ;
if ( V_94 == NULL ) {
F_4 ( V_18 L_27
L_28 ) ;
goto V_97;
}
V_96 = F_18 ( sizeof( struct V_95 ) , V_59 ) ;
if ( V_96 == NULL ) {
F_4 ( V_18 L_29
L_30 ) ;
goto V_98;
}
V_94 -> type = V_99 ;
V_94 -> V_100 = ( void * ) V_96 ;
V_96 -> V_93 = V_93 ;
V_96 -> type = type ;
return V_94 ;
V_98:
F_21 ( V_94 ) ;
V_97:
return NULL ;
}
struct V_92 * F_35 ( T_2 V_48 )
{
struct V_92 * V_94 ;
struct V_101 * V_102 ;
V_94 = F_18 ( sizeof( struct V_92 ) , V_59 ) ;
if ( V_94 == NULL ) {
F_4 ( V_18 L_27
L_28 ) ;
goto V_97;
}
V_102 = F_18 ( sizeof( struct V_101 ) , V_59 ) ;
if ( V_102 == NULL ) {
F_4 ( V_18 L_31
L_30 ) ;
goto V_103;
}
V_94 -> type = V_104 ;
V_94 -> V_100 = ( void * ) V_102 ;
V_102 -> V_48 = V_48 ;
return V_94 ;
V_103:
F_21 ( V_94 ) ;
V_97:
return NULL ;
}
struct V_92 * F_36 ( unsigned long long V_48 ,
T_3 V_29 , T_4 V_30 , T_5 V_31 )
{
struct V_92 * V_94 ;
struct V_105 * V_106 ;
V_94 = F_18 (
sizeof( struct V_92 ) , V_59 ) ;
if ( V_94 == NULL ) {
F_4 ( V_18 L_27
L_28 ) ;
goto V_97;
}
V_106 = F_18 ( sizeof( struct V_105 ) , V_59 ) ;
if ( V_106 == NULL ) {
F_4 ( V_18 L_32
L_30 ) ;
goto V_107;
}
V_94 -> type = V_108 ;
V_94 -> V_100 = ( void * ) V_106 ;
V_106 -> V_48 = V_48 ;
V_106 -> V_29 = V_29 ;
V_106 -> V_30 = V_30 ;
V_106 -> V_31 = V_31 ;
return V_94 ;
V_107:
F_21 ( V_94 ) ;
V_97:
return NULL ;
}
void F_37 ( struct V_92 * V_94 )
{
F_21 ( V_94 -> V_100 ) ;
F_21 ( V_94 ) ;
}
int F_38 ( struct V_88 * V_10 , struct V_92 * V_109 ,
struct V_92 * V_110 , T_1 V_73 )
{
struct V_1 * V_21 = V_10 -> V_11 -> V_11 ;
int V_26 ;
if ( V_21 -> V_111 == NULL ) {
F_4 ( V_60 L_33 ) ;
return - V_47 ;
}
if ( ! F_39 ( & V_10 -> V_54 ) ) {
F_4 ( V_18 L_34 ) ;
return - V_47 ;
}
V_26 = V_21 -> V_111 ( V_10 , V_109 , V_110 , V_73 ) ;
F_17 ( & V_10 -> V_54 ) ;
return V_26 ;
}
int F_40 ( struct V_88 * V_10 )
{
struct V_1 * V_21 = V_10 -> V_11 -> V_11 ;
int V_26 ;
if ( V_21 -> V_112 == NULL ) {
F_4 ( V_18 L_35 ) ;
return - V_47 ;
}
F_16 ( & V_10 -> V_54 ) ;
V_26 = V_21 -> V_112 ( V_10 ) ;
F_17 ( & V_10 -> V_54 ) ;
return V_26 ;
}
int F_41 ( struct V_88 * V_10 )
{
struct V_1 * V_21 = V_10 -> V_11 -> V_11 ;
int V_26 ;
if ( V_21 -> V_113 == NULL ) {
F_4 ( V_60 L_36 ) ;
return - V_47 ;
}
if ( ! F_39 ( & V_10 -> V_54 ) ) {
F_4 ( V_18 L_37 ) ;
return - V_47 ;
}
V_26 = V_21 -> V_113 ( V_10 ) ;
if ( V_26 ) {
F_4 ( V_18 L_38 ) ;
F_17 ( & V_10 -> V_54 ) ;
return V_26 ;
}
F_17 ( & V_10 -> V_54 ) ;
F_21 ( V_10 ) ;
return V_26 ;
}
int F_42 ( struct V_5 * V_6 )
{
struct V_15 * V_89 ;
if ( V_6 -> type != V_14 ) {
F_4 ( V_18 L_25 ) ;
return - V_47 ;
}
V_89 = F_3 ( V_6 -> V_8 , struct V_15 , V_10 ) ;
if ( ! F_39 ( & V_89 -> V_54 ) ) {
F_4 ( V_18 L_39 ) ;
return - V_114 ;
}
if ( ! ( F_43 ( & V_89 -> V_115 ) && F_43 ( & V_89 -> V_116 ) ) ) {
F_4 ( V_60 L_40 ) ;
F_17 ( & V_89 -> V_54 ) ;
return - V_114 ;
}
V_89 -> V_57 = 0 ;
F_17 ( & V_89 -> V_54 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_21 , int V_117 , int V_118 )
{
void (* F_45)( int , int , void * );
void * V_119 ;
F_45 = V_21 -> V_120 [ V_117 - 1 ] . V_121 [ V_118 ] . V_122 ;
V_119 = V_21 -> V_120 [ V_117 - 1 ] . V_121 [ V_118 ] . V_119 ;
if ( F_45 != NULL )
F_45 ( V_117 , V_118 , V_119 ) ;
else
F_4 ( V_60 L_41
L_42 , V_117 , V_118 ) ;
}
int F_46 ( struct V_2 * V_3 , int V_117 , int V_118 ,
void (* V_121)( int , int , void * ) ,
void * V_119 )
{
struct V_1 * V_21 ;
V_21 = F_1 ( V_3 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_6 ) ;
return - V_47 ;
}
if ( ( V_117 < 1 ) || ( V_117 > 7 ) ) {
F_4 ( V_18 L_43 ) ;
return - V_47 ;
}
if ( V_21 -> V_123 == NULL ) {
F_4 ( V_18 L_44 ) ;
return - V_47 ;
}
F_16 ( & V_21 -> V_124 ) ;
if ( V_21 -> V_120 [ V_117 - 1 ] . V_121 [ V_118 ] . V_122 ) {
F_17 ( & V_21 -> V_124 ) ;
F_4 ( V_60 L_45 ) ;
return - V_114 ;
}
V_21 -> V_120 [ V_117 - 1 ] . V_73 ++ ;
V_21 -> V_120 [ V_117 - 1 ] . V_121 [ V_118 ] . V_119 = V_119 ;
V_21 -> V_120 [ V_117 - 1 ] . V_121 [ V_118 ] . V_122 = V_121 ;
V_21 -> V_123 ( V_21 , V_117 , 1 , 1 ) ;
F_17 ( & V_21 -> V_124 ) ;
return 0 ;
}
void F_47 ( struct V_2 * V_3 , int V_117 , int V_118 )
{
struct V_1 * V_21 ;
V_21 = F_1 ( V_3 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_6 ) ;
return;
}
if ( ( V_117 < 1 ) || ( V_117 > 7 ) ) {
F_4 ( V_18 L_43 ) ;
return;
}
if ( V_21 -> V_123 == NULL ) {
F_4 ( V_18 L_44 ) ;
return;
}
F_16 ( & V_21 -> V_124 ) ;
V_21 -> V_120 [ V_117 - 1 ] . V_73 -- ;
if ( V_21 -> V_120 [ V_117 - 1 ] . V_73 == 0 )
V_21 -> V_123 ( V_21 , V_117 , 0 , 1 ) ;
V_21 -> V_120 [ V_117 - 1 ] . V_121 [ V_118 ] . V_122 = NULL ;
V_21 -> V_120 [ V_117 - 1 ] . V_121 [ V_118 ] . V_119 = NULL ;
F_17 ( & V_21 -> V_124 ) ;
}
int F_48 ( struct V_2 * V_3 , int V_117 , int V_118 )
{
struct V_1 * V_21 ;
V_21 = F_1 ( V_3 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_6 ) ;
return - V_47 ;
}
if ( ( V_117 < 1 ) || ( V_117 > 7 ) ) {
F_4 ( V_60 L_43 ) ;
return - V_47 ;
}
if ( V_21 -> V_125 == NULL ) {
F_4 ( V_60 L_46 ) ;
return - V_47 ;
}
return V_21 -> V_125 ( V_21 , V_117 , V_118 ) ;
}
struct V_5 * F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_21 ;
struct V_49 * V_126 = NULL ;
struct V_17 * V_127 = NULL ;
struct V_17 * V_128 = NULL ;
struct V_5 * V_6 = NULL ;
V_21 = F_1 ( V_3 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_6 ) ;
goto V_53;
}
F_15 (lm_pos, &bridge->lm_resources) {
V_128 = F_3 ( V_126 ,
struct V_17 , V_10 ) ;
if ( V_128 == NULL ) {
F_4 ( V_18 L_47
L_48 ) ;
continue;
}
F_16 ( & V_128 -> V_54 ) ;
if ( V_128 -> V_57 == 0 ) {
V_128 -> V_57 = 1 ;
F_17 ( & V_128 -> V_54 ) ;
V_127 = V_128 ;
break;
}
F_17 ( & V_128 -> V_54 ) ;
}
if ( V_127 == NULL )
goto V_129;
V_6 = F_18 ( sizeof( struct V_5 ) , V_59 ) ;
if ( V_6 == NULL ) {
F_4 ( V_18 L_8 ) ;
goto V_61;
}
V_6 -> type = V_16 ;
V_6 -> V_8 = & V_127 -> V_10 ;
return V_6 ;
V_61:
F_16 ( & V_128 -> V_54 ) ;
V_128 -> V_57 = 0 ;
F_17 ( & V_128 -> V_54 ) ;
V_129:
V_53:
return NULL ;
}
int F_50 ( struct V_5 * V_6 )
{
struct V_17 * V_128 ;
if ( V_6 -> type != V_16 ) {
F_4 ( V_18 L_49 ) ;
return - V_47 ;
}
V_128 = F_3 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
return V_128 -> V_130 ;
}
int F_51 ( struct V_5 * V_6 , unsigned long long V_131 ,
T_3 V_29 , T_4 V_30 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_17 * V_128 ;
if ( V_6 -> type != V_16 ) {
F_4 ( V_18 L_49 ) ;
return - V_47 ;
}
V_128 = F_3 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_132 == NULL ) {
F_4 ( V_18 L_50 ) ;
return - V_47 ;
}
return V_21 -> V_132 ( V_128 , V_131 , V_29 , V_30 ) ;
}
int F_52 ( struct V_5 * V_6 , unsigned long long * V_131 ,
T_3 * V_29 , T_4 * V_30 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_17 * V_128 ;
if ( V_6 -> type != V_16 ) {
F_4 ( V_18 L_49 ) ;
return - V_47 ;
}
V_128 = F_3 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_133 == NULL ) {
F_4 ( V_18 L_51 ) ;
return - V_47 ;
}
return V_21 -> V_133 ( V_128 , V_131 , V_29 , V_30 ) ;
}
int F_53 ( struct V_5 * V_6 , int V_134 ,
void (* V_121)( int ) )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_17 * V_128 ;
if ( V_6 -> type != V_16 ) {
F_4 ( V_18 L_49 ) ;
return - V_47 ;
}
V_128 = F_3 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_135 == NULL ) {
F_4 ( V_18 L_52 ) ;
return - V_47 ;
}
return V_21 -> V_135 ( V_128 , V_134 , V_121 ) ;
}
int F_54 ( struct V_5 * V_6 , int V_134 )
{
struct V_1 * V_21 = F_2 ( V_6 ) ;
struct V_17 * V_128 ;
if ( V_6 -> type != V_16 ) {
F_4 ( V_18 L_49 ) ;
return - V_47 ;
}
V_128 = F_3 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
if ( V_21 -> V_136 == NULL ) {
F_4 ( V_18 L_53 ) ;
return - V_47 ;
}
return V_21 -> V_136 ( V_128 , V_134 ) ;
}
void F_55 ( struct V_5 * V_6 )
{
struct V_17 * V_128 ;
if ( V_6 -> type != V_16 ) {
F_4 ( V_18 L_49 ) ;
return;
}
V_128 = F_3 ( V_6 -> V_8 , struct V_17 , V_10 ) ;
F_16 ( & V_128 -> V_54 ) ;
V_128 -> V_57 = 0 ;
F_17 ( & V_128 -> V_54 ) ;
F_21 ( V_6 ) ;
}
int F_56 ( struct V_2 * V_137 )
{
struct V_1 * V_21 ;
V_21 = F_1 ( V_137 ) ;
if ( V_21 == NULL ) {
F_4 ( V_18 L_6 ) ;
return - V_47 ;
}
if ( V_21 -> V_138 == NULL ) {
F_4 ( V_60 L_54 ) ;
return - V_47 ;
}
return V_21 -> V_138 ( V_21 ) ;
}
static int F_57 ( void )
{
int V_139 ;
F_16 ( & V_140 ) ;
for ( V_139 = 0 ; V_139 < sizeof( V_141 ) * 8 ; V_139 ++ ) {
if ( ( ( V_141 >> V_139 ) & 0x1 ) == 0 ) {
V_141 |= ( 0x1 << V_139 ) ;
break;
}
}
F_17 ( & V_140 ) ;
return V_139 ;
}
static void F_58 ( int V_137 )
{
F_16 ( & V_140 ) ;
V_141 &= ~ ( 0x1 << V_137 ) ;
F_17 ( & V_140 ) ;
}
int F_59 ( struct V_1 * V_21 )
{
struct V_2 * V_3 ;
int V_26 ;
int V_139 ;
V_21 -> V_142 = F_57 () ;
for ( V_139 = 0 ; V_139 < V_143 ; V_139 ++ ) {
V_3 = & V_21 -> V_3 [ V_139 ] ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
V_3 -> V_11 = V_21 -> V_11 ;
V_3 -> V_137 = & V_144 ;
V_3 -> V_4 = V_21 ;
F_60 ( V_3 , L_55 , V_21 -> V_142 , V_139 + 1 ) ;
V_26 = F_61 ( V_3 ) ;
if ( V_26 )
goto V_145;
}
return V_26 ;
V_145:
while ( -- V_139 >= 0 ) {
V_3 = & V_21 -> V_3 [ V_139 ] ;
F_62 ( V_3 ) ;
}
F_58 ( V_21 -> V_142 ) ;
return V_26 ;
}
void F_63 ( struct V_1 * V_21 )
{
int V_139 ;
struct V_2 * V_3 ;
for ( V_139 = 0 ; V_139 < V_143 ; V_139 ++ ) {
V_3 = & V_21 -> V_3 [ V_139 ] ;
F_62 ( V_3 ) ;
}
F_58 ( V_21 -> V_142 ) ;
}
int F_64 ( struct V_146 * V_147 )
{
V_147 -> V_148 . V_149 = V_147 -> V_149 ;
V_147 -> V_148 . V_137 = & V_144 ;
return F_65 ( & V_147 -> V_148 ) ;
}
void F_66 ( struct V_146 * V_147 )
{
F_67 ( & V_147 -> V_148 ) ;
}
static int F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_21 ;
int V_142 ;
V_21 = F_1 ( V_3 ) ;
V_142 = 0 ;
while ( V_142 < V_143 ) {
if ( & V_21 -> V_3 [ V_142 ] == V_3 )
break;
V_142 ++ ;
}
if ( V_142 == V_143 ) {
F_69 ( V_3 , L_56 ) ;
V_142 = 0 ;
goto V_150;
}
V_142 ++ ;
V_150:
return V_142 ;
}
static struct V_146 * F_70 ( struct V_2 * V_3 )
{
if ( V_3 -> V_148 == NULL )
F_4 ( V_18 L_57 ) ;
return F_6 ( V_3 -> V_148 , struct V_146 , V_148 ) ;
}
static int F_71 ( struct V_2 * V_3 , struct V_151 * V_147 )
{
struct V_1 * V_21 ;
struct V_146 * V_148 ;
int V_139 , V_142 ;
V_21 = F_1 ( V_3 ) ;
V_148 = F_6 ( V_147 , struct V_146 , V_148 ) ;
V_142 = F_68 ( V_3 ) ;
if ( ! V_142 )
goto V_150;
if ( V_148 -> V_152 == NULL ) {
F_69 ( V_3 , L_58 ) ;
goto V_153;
}
V_139 = 0 ;
while ( ( V_148 -> V_152 [ V_139 ] . V_137 != 0 ) ||
( V_148 -> V_152 [ V_139 ] . V_154 != 0 ) ) {
if ( V_21 -> V_142 == V_148 -> V_152 [ V_139 ] . V_137 ) {
if ( V_142 == V_148 -> V_152 [ V_139 ] . V_154 )
return 1 ;
if ( V_148 -> V_152 [ V_139 ] . V_154 == V_155 )
return 1 ;
if ( ( V_148 -> V_152 [ V_139 ] . V_154 == V_156 ) &&
( V_142 == F_56 ( V_3 ) ) )
return 1 ;
}
V_139 ++ ;
}
V_150:
V_153:
return 0 ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_21 ;
struct V_146 * V_148 ;
int V_26 = - V_157 ;
V_148 = F_70 ( V_3 ) ;
V_21 = F_1 ( V_3 ) ;
if ( V_148 -> V_158 != NULL )
V_26 = V_148 -> V_158 ( V_3 , V_21 -> V_142 , F_68 ( V_3 ) ) ;
return V_26 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_21 ;
struct V_146 * V_148 ;
int V_26 = - V_157 ;
V_148 = F_70 ( V_3 ) ;
V_21 = F_1 ( V_3 ) ;
if ( V_148 -> remove != NULL )
V_26 = V_148 -> remove ( V_3 , V_21 -> V_142 , F_68 ( V_3 ) ) ;
return V_26 ;
}
static int T_11 F_74 ( void )
{
return F_75 ( & V_144 ) ;
}
static void T_12 F_76 ( void )
{
F_77 ( & V_144 ) ;
}
