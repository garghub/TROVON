static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( F_3 ( struct V_1 , V_3 ) != 0 ) ;
return F_4 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_5 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_4 , struct V_5 , V_7 ) ;
if ( V_6 -> V_8 != V_9 )
F_6 ( & V_10 , V_6 -> V_8 ) ;
F_7 ( & V_6 -> V_11 ) ;
F_8 ( & V_12 ) ;
F_9 ( & V_6 -> V_13 ) ;
F_10 ( V_6 ) ;
}
static struct V_5 * F_11 ( struct V_5 * V_6 )
{
if ( V_6 )
F_12 ( & V_6 -> V_7 ) ;
return V_6 ;
}
static void F_13 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_14 ( & V_6 -> V_7 , F_5 , & V_12 ) ;
}
static int F_15 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
int V_16 = - V_17 ;
F_16 ( & V_6 -> V_18 ) ;
if ( V_6 -> V_19 )
V_16 = V_6 -> V_19 -> V_20 ( V_6 -> V_19 , V_15 ) ;
else
F_17 ( V_15 ) ;
F_8 ( & V_6 -> V_18 ) ;
return V_16 ;
}
static struct V_5 * F_18 ( unsigned int V_8 )
{
struct V_5 * V_6 ;
F_16 ( & V_12 ) ;
V_6 = F_19 ( & V_10 , V_8 ) ;
V_6 = F_11 ( V_6 ) ;
F_8 ( & V_12 ) ;
return V_6 ;
}
static void F_20 ( struct V_5 * V_6 , unsigned int V_8 )
{
if ( V_6 -> V_8 != V_9 || V_8 == V_9 )
return;
F_16 ( & V_12 ) ;
F_21 ( & V_10 , V_8 , V_6 ) ;
V_6 -> V_8 = V_8 ;
F_8 ( & V_12 ) ;
}
int F_22 ( struct V_21 * V_19 , const void * V_22 , T_1 V_23 )
{
struct V_5 * V_6 = V_19 -> V_6 ;
const struct V_24 * V_25 = V_22 ;
struct V_14 * V_15 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned int type ;
unsigned int V_28 ;
unsigned int V_29 ;
if ( V_23 < V_30 || V_23 & 3 )
return - V_31 ;
V_28 = F_23 ( V_25 -> V_32 ) ;
V_27 = F_23 ( V_25 -> V_27 ) ;
type = F_23 ( V_25 -> type ) ;
V_29 = F_23 ( V_25 -> V_33 ) ;
V_26 = ( V_27 + 3 ) & ~ 3 ;
if ( V_28 != V_34 )
return - V_31 ;
if ( V_23 != V_26 + V_30 )
return - V_31 ;
if ( V_29 != V_35 && type != V_36 )
return - V_31 ;
V_15 = F_24 ( NULL , V_23 ) ;
if ( ! V_15 )
return - V_37 ;
F_25 ( V_15 ) ;
F_26 ( V_15 , V_22 , V_23 ) ;
F_27 ( & V_6 -> V_13 , V_15 ) ;
F_28 ( & V_6 -> V_38 ) ;
return 0 ;
}
static struct V_14 * F_29 ( T_2 type , T_1 V_39 ,
T_2 V_40 , T_2 V_41 )
{
struct V_24 * V_42 ;
struct V_14 * V_15 ;
V_15 = F_30 ( V_30 + V_39 , V_43 ) ;
if ( ! V_15 )
return NULL ;
F_25 ( V_15 ) ;
V_42 = F_31 ( V_15 , V_30 ) ;
V_42 -> V_32 = F_32 ( V_34 ) ;
V_42 -> type = F_32 ( type ) ;
V_42 -> V_44 = F_32 ( V_40 ) ;
V_42 -> V_45 = F_32 ( V_35 ) ;
V_42 -> V_46 = F_32 ( 0 ) ;
V_42 -> V_27 = F_32 ( V_39 ) ;
V_42 -> V_47 = F_32 ( V_41 ) ;
V_42 -> V_33 = F_32 ( V_35 ) ;
return V_15 ;
}
static struct V_14 * F_33 ( T_2 V_40 ,
T_2 V_41 , T_2 V_48 )
{
const int V_39 = 20 ;
struct V_14 * V_15 ;
T_3 * V_49 ;
V_15 = F_29 ( V_50 , V_39 ,
V_40 , V_41 ) ;
if ( ! V_15 )
return NULL ;
V_49 = F_34 ( V_15 , V_39 ) ;
V_49 [ 0 ] = F_32 ( V_50 ) ;
V_49 [ 1 ] = F_32 ( V_40 ) ;
V_49 [ 2 ] = F_32 ( V_48 ) ;
return V_15 ;
}
static struct V_14 * F_35 ( T_2 V_40 )
{
const int V_39 = 20 ;
struct V_14 * V_15 ;
T_3 * V_49 ;
V_15 = F_29 ( V_51 , V_39 ,
V_40 , V_52 ) ;
if ( ! V_15 )
return NULL ;
V_49 = F_34 ( V_15 , V_39 ) ;
V_49 [ 0 ] = F_32 ( V_51 ) ;
return V_15 ;
}
static struct V_14 * F_36 ( struct V_53 * V_54 )
{
const int V_39 = 20 ;
struct V_14 * V_15 ;
T_3 * V_49 ;
V_15 = F_29 ( V_55 , V_39 ,
V_54 -> V_56 , V_57 ) ;
if ( ! V_15 )
return NULL ;
V_49 = F_34 ( V_15 , V_39 ) ;
V_49 [ 0 ] = F_32 ( V_55 ) ;
V_49 [ 1 ] = F_32 ( V_54 -> V_56 ) ;
V_49 [ 2 ] = F_32 ( V_54 -> V_58 ) ;
return V_15 ;
}
static void F_37 ( struct V_59 * V_38 )
{
struct V_5 * V_6 = F_4 ( V_38 , struct V_5 , V_38 ) ;
struct V_14 * V_15 ;
while ( ( V_15 = F_38 ( & V_6 -> V_13 ) ) != NULL ) {
const struct V_24 * V_25 ;
T_2 V_41 , V_60 ;
struct V_1 * V_61 ;
T_2 V_40 ;
int V_62 ;
V_25 = ( const struct V_24 * ) F_39 ( V_15 ) ;
V_40 = F_23 ( V_25 -> V_44 ) ;
V_41 = F_23 ( V_25 -> V_47 ) ;
V_60 = F_23 ( V_25 -> V_33 ) ;
V_62 = ! ! V_25 -> V_46 ;
F_20 ( V_6 , V_40 ) ;
V_61 = F_40 ( V_60 ) ;
if ( ! V_61 ) {
F_17 ( V_15 ) ;
} else {
if ( F_41 ( & V_61 -> V_3 , V_15 ) )
F_17 ( V_15 ) ;
F_42 ( V_61 ) ;
}
if ( V_62 ) {
V_15 = F_33 ( V_41 , V_6 -> V_8 , V_60 ) ;
if ( ! V_15 )
break;
if ( F_15 ( V_6 , V_15 ) )
break;
}
}
}
int F_43 ( struct V_21 * V_19 , unsigned int V_8 )
{
struct V_5 * V_6 ;
if ( ! V_19 || ! V_19 -> V_20 )
return - V_31 ;
V_6 = F_44 ( sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_37 ;
F_45 ( & V_6 -> V_38 , F_37 ) ;
F_46 ( & V_6 -> V_7 ) ;
F_47 ( & V_6 -> V_18 ) ;
F_48 ( & V_6 -> V_13 ) ;
V_6 -> V_8 = V_9 ;
V_6 -> V_19 = V_19 ;
F_20 ( V_6 , V_8 ) ;
F_16 ( & V_12 ) ;
F_49 ( & V_6 -> V_11 , & V_63 ) ;
F_8 ( & V_12 ) ;
V_19 -> V_6 = V_6 ;
return 0 ;
}
void F_50 ( struct V_21 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_6 ;
struct V_14 * V_15 ;
F_16 ( & V_6 -> V_18 ) ;
V_6 -> V_19 = NULL ;
F_8 ( & V_6 -> V_18 ) ;
V_15 = F_35 ( V_6 -> V_8 ) ;
if ( V_15 )
F_51 ( NULL , V_15 ) ;
F_13 ( V_6 ) ;
V_19 -> V_6 = NULL ;
}
static struct V_1 * F_40 ( int V_48 )
{
struct V_1 * V_61 ;
if ( V_48 == V_35 )
V_48 = 0 ;
F_16 ( & V_64 ) ;
V_61 = F_52 ( & V_65 , V_48 ) ;
if ( V_61 )
F_53 ( & V_61 -> V_3 ) ;
F_8 ( & V_64 ) ;
return V_61 ;
}
static void F_42 ( struct V_1 * V_61 )
{
F_54 ( & V_61 -> V_3 ) ;
}
static void F_55 ( struct V_1 * V_61 )
{
struct V_14 * V_15 ;
int V_48 = V_61 -> V_66 . V_58 ;
V_15 = F_36 ( & V_61 -> V_66 ) ;
if ( V_15 ) {
F_56 ( V_15 , & V_61 -> V_3 ) ;
F_57 ( NULL , V_15 ) ;
}
if ( V_48 == V_35 )
V_48 = 0 ;
F_58 ( & V_61 -> V_3 ) ;
F_16 ( & V_64 ) ;
F_59 ( & V_65 , V_48 ) ;
F_8 ( & V_64 ) ;
}
static int F_60 ( struct V_1 * V_61 , int * V_48 )
{
int V_16 ;
F_16 ( & V_64 ) ;
if ( ! * V_48 ) {
V_16 = F_61 ( & V_65 , V_61 ,
V_67 , V_68 + 1 ,
V_69 ) ;
if ( V_16 >= 0 )
* V_48 = V_16 ;
} else if ( * V_48 < V_67 && ! F_62 ( V_70 ) ) {
V_16 = - V_71 ;
} else if ( * V_48 == V_35 ) {
V_16 = F_61 ( & V_65 , V_61 , 0 , 1 , V_69 ) ;
} else {
V_16 = F_61 ( & V_65 , V_61 , * V_48 , * V_48 + 1 , V_69 ) ;
if ( V_16 >= 0 )
* V_48 = V_16 ;
}
F_8 ( & V_64 ) ;
if ( V_16 == - V_72 )
return - V_73 ;
else if ( V_16 < 0 )
return V_16 ;
F_53 ( & V_61 -> V_3 ) ;
return 0 ;
}
static void F_63 ( void )
{
struct V_1 * V_61 ;
int V_74 ;
F_16 ( & V_64 ) ;
F_64 (&qrtr_ports, ipc, id) {
if ( V_74 == 0 )
continue;
F_53 ( & V_61 -> V_3 ) ;
V_61 -> V_3 . V_75 = V_76 ;
F_65 ( F_66 ( & V_61 -> V_3 ) ) ;
F_54 ( & V_61 -> V_3 ) ;
}
F_8 ( & V_64 ) ;
}
static int F_67 ( struct V_77 * V_2 ,
const struct V_53 * V_78 , int V_79 )
{
struct V_1 * V_61 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_48 ;
int V_16 ;
if ( ! V_79 && V_78 -> V_58 == V_61 -> V_66 . V_58 )
return 0 ;
V_48 = V_78 -> V_58 ;
V_16 = F_60 ( V_61 , & V_48 ) ;
if ( V_16 )
return V_16 ;
if ( ! V_79 )
F_55 ( V_61 ) ;
V_61 -> V_66 . V_58 = V_48 ;
F_68 ( V_3 , V_80 ) ;
if ( V_48 == V_35 )
F_63 () ;
return 0 ;
}
static int F_69 ( struct V_77 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_53 V_78 ;
if ( ! F_70 ( V_3 , V_80 ) )
return 0 ;
V_78 . V_81 = V_82 ;
V_78 . V_56 = V_52 ;
V_78 . V_58 = 0 ;
return F_67 ( V_2 , & V_78 , 1 ) ;
}
static int F_71 ( struct V_77 * V_2 , struct V_83 * V_84 , int V_23 )
{
F_72 ( struct V_53 * , V_78 , V_84 ) ;
struct V_1 * V_61 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_16 ;
if ( V_23 < sizeof( * V_78 ) || V_78 -> V_81 != V_82 )
return - V_31 ;
if ( V_78 -> V_56 != V_61 -> V_66 . V_56 )
return - V_31 ;
F_73 ( V_3 ) ;
V_16 = F_67 ( V_2 , V_78 , F_70 ( V_3 , V_80 ) ) ;
F_74 ( V_3 ) ;
return V_16 ;
}
static int F_51 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
const struct V_24 * V_25 ;
struct V_1 * V_61 ;
V_25 = ( const struct V_24 * ) F_39 ( V_15 ) ;
V_61 = F_40 ( F_23 ( V_25 -> V_33 ) ) ;
if ( ! V_61 || & V_61 -> V_3 == V_15 -> V_3 ) {
F_17 ( V_15 ) ;
return - V_17 ;
}
if ( F_41 ( & V_61 -> V_3 , V_15 ) ) {
F_42 ( V_61 ) ;
F_17 ( V_15 ) ;
return - V_72 ;
}
F_42 ( V_61 ) ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_14 * V_85 ;
F_16 ( & V_12 ) ;
F_75 (node, &qrtr_all_nodes, item) {
V_85 = F_76 ( V_15 , V_43 ) ;
if ( ! V_85 )
break;
F_56 ( V_85 , V_15 -> V_3 ) ;
F_15 ( V_6 , V_85 ) ;
}
F_8 ( & V_12 ) ;
F_51 ( V_6 , V_15 ) ;
return 0 ;
}
static int F_77 ( struct V_77 * V_2 , struct V_86 * V_87 , T_1 V_23 )
{
F_72 ( struct V_53 * , V_78 , V_87 -> V_88 ) ;
int (* F_78)( struct V_5 * , struct V_14 * );
struct V_1 * V_61 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_5 * V_6 ;
struct V_24 * V_42 ;
struct V_14 * V_15 ;
T_1 V_89 ;
int V_16 ;
if ( V_87 -> V_90 & ~ ( V_91 ) )
return - V_31 ;
if ( V_23 > 65535 )
return - V_92 ;
F_73 ( V_3 ) ;
if ( V_78 ) {
if ( V_87 -> V_93 < sizeof( * V_78 ) ) {
F_74 ( V_3 ) ;
return - V_31 ;
}
if ( V_78 -> V_81 != V_82 ) {
F_74 ( V_3 ) ;
return - V_31 ;
}
V_16 = F_69 ( V_2 ) ;
if ( V_16 ) {
F_74 ( V_3 ) ;
return V_16 ;
}
} else if ( V_3 -> V_94 == V_95 ) {
V_78 = & V_61 -> V_96 ;
} else {
F_74 ( V_3 ) ;
return - V_97 ;
}
V_6 = NULL ;
if ( V_78 -> V_56 == V_57 ) {
F_78 = F_57 ;
} else if ( V_78 -> V_56 == V_61 -> V_66 . V_56 ) {
F_78 = F_51 ;
} else {
F_78 = F_15 ;
V_6 = F_18 ( V_78 -> V_56 ) ;
if ( ! V_6 ) {
F_74 ( V_3 ) ;
return - V_98 ;
}
}
V_89 = ( V_23 + 3 ) & ~ 3 ;
V_15 = F_79 ( V_3 , V_89 + V_30 ,
V_87 -> V_90 & V_91 , & V_16 ) ;
if ( ! V_15 )
goto V_99;
F_25 ( V_15 ) ;
F_31 ( V_15 , V_23 + V_30 ) ;
V_42 = (struct V_24 * ) F_39 ( V_15 ) ;
V_42 -> V_32 = F_32 ( V_34 ) ;
V_42 -> V_44 = F_32 ( V_61 -> V_66 . V_56 ) ;
V_42 -> V_45 = F_32 ( V_61 -> V_66 . V_58 ) ;
V_42 -> V_46 = F_32 ( 0 ) ;
V_42 -> V_27 = F_32 ( V_23 ) ;
V_42 -> V_47 = F_32 ( V_78 -> V_56 ) ;
V_42 -> V_33 = F_32 ( V_78 -> V_58 ) ;
V_16 = F_80 ( V_15 , V_30 ,
& V_87 -> V_100 , V_23 ) ;
if ( V_16 ) {
F_17 ( V_15 ) ;
goto V_99;
}
if ( V_89 != V_23 ) {
V_16 = F_81 ( V_15 , V_89 - V_23 ) ;
if ( V_16 )
goto V_99;
F_31 ( V_15 , V_89 - V_23 ) ;
}
if ( V_61 -> V_66 . V_58 == V_35 ) {
if ( V_23 < 4 ) {
V_16 = - V_31 ;
F_17 ( V_15 ) ;
goto V_99;
}
F_82 ( V_15 , V_30 , & V_42 -> type , 4 ) ;
} else {
V_42 -> type = F_32 ( V_36 ) ;
}
V_16 = F_78 ( V_6 , V_15 ) ;
if ( V_16 >= 0 )
V_16 = V_23 ;
V_99:
F_13 ( V_6 ) ;
F_74 ( V_3 ) ;
return V_16 ;
}
static int F_83 ( struct V_77 * V_2 , struct V_86 * V_87 ,
T_1 V_27 , int V_101 )
{
F_72 ( struct V_53 * , V_78 , V_87 -> V_88 ) ;
const struct V_24 * V_25 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_14 * V_15 ;
int V_102 , V_16 ;
F_73 ( V_3 ) ;
if ( F_70 ( V_3 , V_80 ) ) {
F_74 ( V_3 ) ;
return - V_103 ;
}
V_15 = F_84 ( V_3 , V_101 & ~ V_91 ,
V_101 & V_91 , & V_16 ) ;
if ( ! V_15 ) {
F_74 ( V_3 ) ;
return V_16 ;
}
V_25 = ( const struct V_24 * ) F_39 ( V_15 ) ;
V_102 = F_23 ( V_25 -> V_27 ) ;
if ( V_102 > V_27 ) {
V_102 = V_27 ;
V_87 -> V_90 |= V_104 ;
}
V_16 = F_85 ( V_15 , V_30 , V_87 , V_102 ) ;
if ( V_16 < 0 )
goto V_105;
V_16 = V_102 ;
if ( V_78 ) {
V_78 -> V_81 = V_82 ;
V_78 -> V_56 = F_23 ( V_25 -> V_44 ) ;
V_78 -> V_58 = F_23 ( V_25 -> V_45 ) ;
V_87 -> V_93 = sizeof( * V_78 ) ;
}
V_105:
F_86 ( V_3 , V_15 ) ;
F_74 ( V_3 ) ;
return V_16 ;
}
static int F_87 ( struct V_77 * V_2 , struct V_83 * V_84 ,
int V_23 , int V_101 )
{
F_72 ( struct V_53 * , V_78 , V_84 ) ;
struct V_1 * V_61 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_16 ;
if ( V_23 < sizeof( * V_78 ) || V_78 -> V_81 != V_82 )
return - V_31 ;
F_73 ( V_3 ) ;
V_3 -> V_94 = V_106 ;
V_2 -> V_107 = V_108 ;
V_16 = F_69 ( V_2 ) ;
if ( V_16 ) {
F_74 ( V_3 ) ;
return V_16 ;
}
V_61 -> V_96 = * V_78 ;
V_2 -> V_107 = V_109 ;
V_3 -> V_94 = V_95 ;
F_74 ( V_3 ) ;
return 0 ;
}
static int F_88 ( struct V_77 * V_2 , struct V_83 * V_84 ,
int * V_23 , int V_96 )
{
struct V_1 * V_61 = F_1 ( V_2 -> V_3 ) ;
struct V_53 V_110 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_73 ( V_3 ) ;
if ( V_96 ) {
if ( V_3 -> V_94 != V_95 ) {
F_74 ( V_3 ) ;
return - V_97 ;
}
V_110 = V_61 -> V_96 ;
} else {
V_110 = V_61 -> V_66 ;
}
F_74 ( V_3 ) ;
* V_23 = sizeof( V_110 ) ;
V_110 . V_81 = V_82 ;
memcpy ( V_84 , & V_110 , sizeof( V_110 ) ) ;
return 0 ;
}
static int F_89 ( struct V_77 * V_2 , unsigned int V_111 , unsigned long V_112 )
{
void T_4 * V_113 = ( void T_4 * ) V_112 ;
struct V_1 * V_61 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_53 * V_54 ;
struct V_14 * V_15 ;
struct V_114 V_115 ;
long V_23 = 0 ;
int V_16 = 0 ;
F_73 ( V_3 ) ;
switch ( V_111 ) {
case V_116 :
V_23 = V_3 -> V_117 - F_90 ( V_3 ) ;
if ( V_23 < 0 )
V_23 = 0 ;
V_16 = F_91 ( V_23 , ( int T_4 * ) V_113 ) ;
break;
case V_118 :
V_15 = F_92 ( & V_3 -> V_119 ) ;
if ( V_15 )
V_23 = V_15 -> V_23 - V_30 ;
V_16 = F_91 ( V_23 , ( int T_4 * ) V_113 ) ;
break;
case V_120 :
if ( F_93 ( & V_115 , V_113 , sizeof( V_115 ) ) ) {
V_16 = - V_121 ;
break;
}
V_54 = (struct V_53 * ) & V_115 . V_122 ;
* V_54 = V_61 -> V_66 ;
if ( F_94 ( V_113 , & V_115 , sizeof( V_115 ) ) ) {
V_16 = - V_121 ;
break;
}
break;
case V_123 :
V_16 = F_95 ( V_3 , V_113 ) ;
break;
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
V_16 = - V_31 ;
break;
default:
V_16 = - V_133 ;
break;
}
F_74 ( V_3 ) ;
return V_16 ;
}
static int F_96 ( struct V_77 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_61 ;
if ( ! V_3 )
return 0 ;
F_73 ( V_3 ) ;
V_61 = F_1 ( V_3 ) ;
V_3 -> V_134 = V_135 ;
if ( ! F_70 ( V_3 , V_136 ) )
V_3 -> V_137 ( V_3 ) ;
F_97 ( V_3 , V_136 ) ;
V_2 -> V_3 = NULL ;
if ( ! F_70 ( V_3 , V_80 ) )
F_55 ( V_61 ) ;
F_9 ( & V_3 -> V_119 ) ;
F_74 ( V_3 ) ;
F_54 ( V_3 ) ;
return 0 ;
}
static int F_98 ( struct V_138 * V_138 , struct V_77 * V_2 ,
int V_139 , int V_140 )
{
struct V_1 * V_61 ;
struct V_2 * V_3 ;
if ( V_2 -> type != V_141 )
return - V_142 ;
V_3 = F_99 ( V_138 , V_82 , V_43 , & V_143 , V_140 ) ;
if ( ! V_3 )
return - V_37 ;
F_97 ( V_3 , V_80 ) ;
F_100 ( V_2 , V_3 ) ;
V_2 -> V_144 = & V_145 ;
V_61 = F_1 ( V_3 ) ;
V_61 -> V_66 . V_81 = V_82 ;
V_61 -> V_66 . V_56 = V_52 ;
V_61 -> V_66 . V_58 = 0 ;
return 0 ;
}
static int F_101 ( struct V_14 * V_15 , struct V_146 * V_147 ,
struct V_148 * V_149 )
{
struct V_150 * V_151 [ V_152 + 1 ] ;
struct V_153 * V_154 ;
int V_16 ;
if ( ! F_102 ( V_15 , V_70 ) )
return - V_155 ;
if ( ! F_102 ( V_15 , V_156 ) )
return - V_155 ;
F_103 () ;
V_16 = F_104 ( V_147 , sizeof( * V_154 ) , V_151 , V_152 , V_157 , V_149 ) ;
if ( V_16 < 0 )
return V_16 ;
V_154 = F_105 ( V_147 ) ;
if ( ! V_151 [ V_158 ] )
return - V_31 ;
V_52 = F_106 ( V_151 [ V_158 ] ) ;
return 0 ;
}
static int T_5 F_107 ( void )
{
int V_16 ;
V_16 = F_108 ( & V_143 , 1 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_109 ( & V_159 ) ;
if ( V_16 ) {
F_110 ( & V_143 ) ;
return V_16 ;
}
F_111 ( V_160 , V_161 , F_101 , NULL , NULL ) ;
return 0 ;
}
static void T_6 F_112 ( void )
{
F_113 ( V_160 , V_161 ) ;
F_114 ( V_159 . V_162 ) ;
F_110 ( & V_143 ) ;
}
