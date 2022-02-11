static int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = ( V_2 -> V_7 == V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 , enum V_3 V_8 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = ( V_2 -> V_7 == V_4 ) ;
if ( V_5 )
V_2 -> V_7 = V_8 ;
F_3 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static enum V_3 F_5 ( struct V_1 * V_2 ,
enum V_3 V_8 )
{
enum V_3 V_9 ;
F_2 ( & V_2 -> V_6 ) ;
V_9 = V_2 -> V_7 ;
V_2 -> V_7 = V_8 ;
F_3 ( & V_2 -> V_6 ) ;
return V_9 ;
}
static struct V_1 * F_6 ( T_1 V_10 )
{
struct V_1 * V_2 ;
F_2 ( & V_11 ) ;
V_2 = F_7 ( & V_12 , V_10 ) ;
if ( V_2 )
F_8 ( & V_2 -> V_13 ) ;
F_3 ( & V_11 ) ;
return V_2 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_13 , V_14 ) ;
}
static void * F_11 ( struct V_15 * V_16 )
{
void * V_17 ;
int V_18 ;
V_17 = F_12 ( V_16 -> V_19 , V_20 ) ;
if ( V_17 ) {
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
if ( V_16 -> V_22 [ V_18 ] == V_17 ) {
V_16 -> V_22 [ V_18 ] = NULL ;
V_16 -> V_23 ++ ;
break;
}
}
if ( V_18 == V_21 )
F_13 ( L_1 , V_17 ) ;
}
return V_17 ;
}
static void F_14 ( struct V_15 * V_16 , int V_24 )
{
int V_18 ;
if ( V_16 -> V_23 == 0 )
return;
for ( V_18 = 0 ; V_18 < V_21 && V_16 -> V_23 && V_24 ; V_18 ++ ) {
if ( V_16 -> V_22 [ V_18 ] == NULL ) {
V_16 -> V_22 [ V_18 ] = F_15 ( V_25 , V_26 ) ;
if ( V_16 -> V_22 [ V_18 ] == NULL )
break;
F_16 ( V_16 -> V_19 , V_20 , V_16 -> V_22 [ V_18 ] ) ;
V_16 -> V_23 -- ;
V_24 -- ;
}
}
}
static void F_17 ( struct V_15 * V_16 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
if ( V_16 -> V_22 [ V_18 ] != NULL ) {
F_18 ( V_16 -> V_22 [ V_18 ] ) ;
V_16 -> V_22 [ V_18 ] = NULL ;
}
}
}
static int F_19 ( struct V_15 * V_16 , void * V_27 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_30 * V_31 = V_27 ;
T_1 V_32 ;
V_32 = F_20 ( V_31 -> V_33 ) ;
V_2 = F_6 ( V_32 ) ;
if ( ! V_2 )
return - V_34 ;
if ( V_2 -> V_7 != V_35 ) {
F_21 ( V_36 , L_2 , V_32 ) ;
F_9 ( V_2 ) ;
return - V_37 ;
}
V_29 = F_22 ( sizeof( * V_29 ) , V_26 ) ;
if ( ! V_29 ) {
F_9 ( V_2 ) ;
return - V_38 ;
}
V_29 -> V_39 = F_23 ( V_31 -> V_40 . V_41 ) ;
V_29 -> V_42 = F_20 ( V_31 -> V_43 ) ;
V_29 -> V_44 = V_16 ;
F_2 ( & V_2 -> V_6 ) ;
F_24 ( & V_29 -> V_45 , & V_2 -> V_46 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_25 ( & V_2 -> V_47 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_26 ( void * V_48 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 = V_48 ;
T_1 V_32 ;
V_32 = F_20 ( V_31 -> V_33 ) ;
V_2 = F_6 ( V_32 ) ;
if ( ! V_2 )
return - V_34 ;
if ( V_2 -> V_7 != V_49 ) {
F_9 ( V_2 ) ;
return - V_37 ;
}
F_5 ( V_2 , V_50 ) ;
V_2 -> V_51 = F_20 ( V_31 -> V_43 ) ;
F_25 ( & V_2 -> V_47 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_27 ( void * V_52 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 = V_52 ;
int V_5 ;
F_21 ( V_36 , L_3 , F_20 ( V_31 -> V_33 ) ) ;
F_2 ( & V_11 ) ;
V_2 = F_7 ( & V_12 , F_20 ( V_31 -> V_33 ) ) ;
if ( ! V_2 ) {
F_3 ( & V_11 ) ;
return - V_34 ;
}
F_28 ( & V_12 , V_2 -> V_53 ) ;
F_3 ( & V_11 ) ;
F_5 ( V_2 , V_54 ) ;
V_5 = F_29 ( V_2 ) ;
if ( V_5 )
F_21 ( V_36 , L_4 , V_5 ) ;
return 0 ;
}
static void F_30 ( struct V_15 * V_16 , void * V_52 )
{
struct V_30 * V_55 ;
if ( ! F_31 ( V_16 -> V_19 ) )
goto V_56;
V_55 = V_52 ;
F_21 ( V_36 , L_5 ,
V_55 -> V_57 , F_20 ( V_55 -> V_33 ) , F_20 ( V_55 -> V_43 ) ) ;
switch ( V_55 -> V_57 ) {
case V_58 :
F_19 ( V_16 , V_52 ) ;
break;
case V_59 :
F_26 ( V_52 ) ;
break;
case V_60 :
F_27 ( V_52 ) ;
break;
default:
F_32 ( L_6 ) ;
break;
}
V_56:
F_18 ( V_52 ) ;
}
static int F_33 ( struct V_15 * V_16 , void * V_61 )
{
struct V_30 * V_55 ;
struct V_1 * V_2 ;
V_55 = V_61 ;
F_21 ( V_62 , L_3 , F_20 ( V_55 -> V_33 ) ) ;
V_2 = F_6 ( F_20 ( V_55 -> V_33 ) ) ;
if ( ! V_2 ) {
F_18 ( V_61 ) ;
return - V_34 ;
}
F_34 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 != V_50 ) {
F_21 ( V_62 , L_7 ,
V_2 -> V_53 , V_2 -> V_7 ) ;
F_35 ( & V_2 -> V_6 ) ;
F_18 ( V_61 ) ;
F_9 ( V_2 ) ;
return - V_63 ;
}
if ( V_2 -> V_64 . V_65 == V_21 ) {
F_21 ( V_62 , L_8 , V_2 -> V_53 ) ;
F_35 ( & V_2 -> V_6 ) ;
F_18 ( V_61 ) ;
F_9 ( V_2 ) ;
return - V_38 ;
}
V_2 -> V_64 . V_61 [ V_2 -> V_64 . V_66 ] = V_61 ;
V_2 -> V_64 . V_66 ++ ;
V_2 -> V_64 . V_65 ++ ;
V_2 -> V_64 . V_66 %= V_21 ;
F_25 ( & V_2 -> V_47 ) ;
F_35 ( & V_2 -> V_6 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_36 ( struct V_67 * V_68 )
{
struct V_15 * V_16 = F_37 ( V_68 , struct V_15 , V_69 ) ;
void * V_52 ;
struct V_30 * V_55 ;
if ( ! F_31 ( V_16 -> V_19 ) )
return;
while ( 1 ) {
F_38 ( & V_16 -> V_70 ) ;
V_52 = F_11 ( V_16 ) ;
if ( V_52 )
F_14 ( V_16 , 1 ) ;
F_39 ( & V_16 -> V_70 ) ;
if ( V_52 == NULL )
break;
V_55 = V_52 ;
if ( V_55 -> V_40 . type != V_71 ) {
F_32 ( L_9 ,
V_55 -> V_40 . type ) ;
F_18 ( V_52 ) ;
continue;
}
if ( V_55 -> V_57 == V_72 )
F_33 ( V_16 , V_52 ) ;
else
F_30 ( V_16 , V_52 ) ;
}
}
static void F_40 ( struct V_73 * V_19 , void * V_74 ,
int V_75 , int V_76 )
{
struct V_15 * V_16 = V_74 ;
if ( F_31 ( V_16 -> V_19 ) && ! F_41 ( & V_16 -> V_69 ) )
F_42 ( V_16 -> V_77 , & V_16 -> V_69 ) ;
}
static void F_43 ( struct V_15 * V_16 , int V_76 )
{
int V_78 ;
F_21 ( V_79 , L_10 ,
V_16 -> V_19 -> V_53 , V_76 , V_16 -> V_80 ) ;
F_34 ( & V_16 -> V_81 ) ;
V_78 = V_16 -> V_82 ;
if ( V_78 == V_76 )
F_21 ( V_79 , L_11 ) ;
while ( V_16 -> V_80 && ( ( V_78 != V_76 ) ||
( V_16 -> V_80 == V_83 ) ) ) {
V_16 -> V_84 [ V_78 ] = NULL ;
++ V_78 ;
V_78 &= ( V_83 - 1 ) ;
V_16 -> V_80 -- ;
}
if ( V_16 -> V_80 < 0 || V_16 -> V_80 > V_83 )
F_32 ( L_12 , V_16 -> V_80 ) ;
F_44 ( ( V_16 -> V_80 < 0 ) || ( V_16 -> V_80 > V_83 ) ) ;
V_16 -> V_82 = V_78 ;
if ( ! F_45 ( & V_16 -> V_85 ) && ( V_16 -> V_80 < V_83 ) ) {
struct V_86 * V_29 , * V_87 ;
int V_88 ;
F_46 (req, _req, &cm->tx_reqs, node) {
F_47 ( & V_29 -> V_45 ) ;
V_16 -> V_84 [ V_16 -> V_89 ] = V_29 -> V_90 ;
V_88 = F_48 ( V_16 -> V_19 , V_29 -> V_91 , V_20 ,
V_29 -> V_90 , V_29 -> V_92 ) ;
F_18 ( V_29 -> V_90 ) ;
F_18 ( V_29 ) ;
++ V_16 -> V_80 ;
++ V_16 -> V_89 ;
V_16 -> V_89 &= ( V_83 - 1 ) ;
if ( V_16 -> V_80 == V_83 )
break;
}
}
F_35 ( & V_16 -> V_81 ) ;
}
static void F_49 ( struct V_73 * V_19 , void * V_74 ,
int V_75 , int V_76 )
{
struct V_15 * V_16 = V_74 ;
if ( V_16 && F_31 ( V_16 -> V_19 ) )
F_43 ( V_16 , V_76 ) ;
}
static int F_50 ( struct V_15 * V_16 , struct V_93 * V_91 ,
void * V_90 , T_2 V_92 )
{
unsigned long V_94 ;
struct V_86 * V_95 ;
V_95 = F_22 ( sizeof( * V_95 ) , V_26 ) ;
if ( V_95 == NULL )
return - V_38 ;
V_95 -> V_91 = V_91 ;
V_95 -> V_90 = V_90 ;
V_95 -> V_92 = V_92 ;
F_51 ( & V_16 -> V_81 , V_94 ) ;
F_24 ( & V_95 -> V_45 , & V_16 -> V_85 ) ;
F_52 ( & V_16 -> V_81 , V_94 ) ;
return 0 ;
}
static int F_53 ( struct V_15 * V_16 , struct V_93 * V_91 ,
void * V_90 , T_2 V_92 )
{
int V_88 ;
unsigned long V_94 ;
F_51 ( & V_16 -> V_81 , V_94 ) ;
if ( V_16 -> V_19 == NULL ) {
V_88 = - V_34 ;
goto V_96;
}
if ( V_16 -> V_80 == V_83 ) {
F_21 ( V_97 , L_13 ) ;
V_88 = - V_98 ;
goto V_96;
}
V_16 -> V_84 [ V_16 -> V_89 ] = V_90 ;
V_88 = F_48 ( V_16 -> V_19 , V_91 , V_20 , V_90 , V_92 ) ;
F_21 ( V_97 , L_14 ,
V_90 , V_91 -> V_39 , V_16 -> V_89 , V_16 -> V_80 ) ;
++ V_16 -> V_80 ;
++ V_16 -> V_89 ;
V_16 -> V_89 &= ( V_83 - 1 ) ;
V_96:
F_52 ( & V_16 -> V_81 , V_94 ) ;
return V_88 ;
}
static int F_54 ( T_1 V_99 , void * V_61 , int V_92 )
{
struct V_1 * V_2 ;
struct V_30 * V_55 ;
int V_5 ;
if ( V_61 == NULL || V_99 == 0 || V_92 == 0 || V_92 > V_25 )
return - V_37 ;
V_2 = F_6 ( V_99 ) ;
if ( ! V_2 ) {
F_32 ( L_15 , V_100 -> V_101 ,
F_55 ( V_100 ) , V_99 ) ;
return - V_34 ;
}
if ( ! F_1 ( V_2 , V_50 ) ) {
V_5 = - V_102 ;
goto V_96;
}
V_55 = V_61 ;
V_55 -> V_40 . V_41 = F_56 ( V_2 -> V_103 ) ;
V_55 -> V_40 . V_104 = F_56 ( V_2 -> V_105 ) ;
V_55 -> V_40 . V_106 = V_20 ;
V_55 -> V_40 . V_107 = V_20 ;
V_55 -> V_40 . type = V_71 ;
V_55 -> V_57 = V_72 ;
V_55 -> V_33 = F_57 ( V_2 -> V_51 ) ;
V_55 -> V_43 = F_57 ( V_2 -> V_53 ) ;
V_55 -> V_108 = F_57 ( ( T_1 ) V_92 ) ;
V_5 = F_53 ( V_2 -> V_44 , V_2 -> V_91 , V_61 , V_92 ) ;
if ( V_5 )
F_21 ( V_97 , L_16 , V_2 -> V_53 , V_5 ) ;
V_96:
F_9 ( V_2 ) ;
return V_5 ;
}
static int F_58 ( struct V_1 * V_2 , void * V_61 )
{
int V_18 , V_5 = - V_37 ;
F_2 ( & V_2 -> V_6 ) ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
if ( V_2 -> V_64 . V_109 [ V_18 ] == V_61 ) {
V_2 -> V_64 . V_109 [ V_18 ] = NULL ;
V_2 -> V_64 . V_110 -- ;
V_5 = 0 ;
break;
}
}
F_3 ( & V_2 -> V_6 ) ;
if ( ! V_5 )
F_18 ( V_61 ) ;
return V_5 ;
}
static int F_59 ( struct V_1 * V_2 , void * * V_61 , long V_111 )
{
void * V_112 = NULL ;
int V_18 , V_5 = 0 ;
long V_113 ;
if ( ! F_1 ( V_2 , V_50 ) ) {
V_5 = - V_102 ;
goto V_56;
}
if ( V_2 -> V_64 . V_110 == V_21 ) {
V_5 = - V_38 ;
goto V_56;
}
V_113 = F_60 ( & V_2 -> V_47 , V_111 ) ;
F_21 ( V_114 , L_17 , V_2 -> V_53 , V_113 ) ;
if ( ! V_113 )
V_5 = - V_115 ;
else if ( V_113 == - V_116 )
V_5 = - V_117 ;
else
V_5 = F_1 ( V_2 , V_50 ) ? 0 : - V_118 ;
if ( V_5 )
goto V_56;
F_2 ( & V_2 -> V_6 ) ;
V_112 = V_2 -> V_64 . V_61 [ V_2 -> V_64 . V_119 ] ;
V_2 -> V_64 . V_61 [ V_2 -> V_64 . V_119 ] = NULL ;
V_2 -> V_64 . V_65 -- ;
V_2 -> V_64 . V_119 ++ ;
V_2 -> V_64 . V_119 %= V_21 ;
V_5 = - V_38 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
if ( V_2 -> V_64 . V_109 [ V_18 ] == NULL ) {
V_2 -> V_64 . V_109 [ V_18 ] = V_112 ;
V_2 -> V_64 . V_110 ++ ;
V_5 = 0 ;
break;
}
}
if ( V_5 ) {
F_18 ( V_112 ) ;
V_112 = NULL ;
}
F_3 ( & V_2 -> V_6 ) ;
V_56:
* V_61 = V_112 ;
return V_5 ;
}
static int F_61 ( T_1 V_120 , struct V_15 * V_16 ,
struct V_121 * V_122 , T_1 V_123 )
{
struct V_1 * V_2 = NULL ;
struct V_30 * V_55 ;
int V_5 ;
long V_113 ;
V_2 = F_6 ( V_120 ) ;
if ( ! V_2 )
return - V_34 ;
if ( ! F_4 ( V_2 , V_124 , V_49 ) ) {
V_5 = - V_37 ;
goto V_125;
}
V_2 -> V_44 = V_16 ;
V_2 -> V_91 = V_122 -> V_91 ;
V_2 -> V_126 = NULL ;
V_2 -> V_103 = V_16 -> V_19 -> V_127 ;
V_2 -> V_51 = V_123 ;
V_55 = F_22 ( sizeof( * V_55 ) , V_26 ) ;
if ( V_55 == NULL ) {
V_5 = - V_38 ;
goto V_125;
}
V_55 -> V_40 . V_41 = F_56 ( V_2 -> V_103 ) ;
V_55 -> V_40 . V_104 = F_56 ( V_122 -> V_91 -> V_39 ) ;
V_55 -> V_40 . V_106 = V_20 ;
V_55 -> V_40 . V_107 = V_20 ;
V_55 -> V_40 . type = V_71 ;
V_55 -> V_57 = V_58 ;
V_55 -> V_33 = F_57 ( V_123 ) ;
V_55 -> V_43 = F_57 ( V_120 ) ;
V_5 = F_53 ( V_16 , V_122 -> V_91 , V_55 , sizeof( * V_55 ) ) ;
if ( V_5 != - V_98 ) {
F_18 ( V_55 ) ;
} else {
V_5 = F_50 ( V_16 , V_122 -> V_91 , V_55 , sizeof( * V_55 ) ) ;
if ( V_5 )
F_18 ( V_55 ) ;
}
if ( V_5 ) {
F_4 ( V_2 , V_49 , V_124 ) ;
goto V_125;
}
V_113 = F_60 ( & V_2 -> V_47 ,
V_128 * V_129 ) ;
F_21 ( V_114 , L_18 , V_2 -> V_53 , V_113 ) ;
if ( ! V_113 )
V_5 = - V_115 ;
else if ( V_113 == - V_116 )
V_5 = - V_117 ;
else
V_5 = F_1 ( V_2 , V_50 ) ? 0 : - 1 ;
V_125:
F_9 ( V_2 ) ;
return V_5 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_30 * V_55 ;
int V_5 ;
V_55 = F_22 ( sizeof( * V_55 ) , V_26 ) ;
if ( V_55 == NULL )
return - V_38 ;
V_55 -> V_40 . V_41 = F_56 ( V_2 -> V_103 ) ;
V_55 -> V_40 . V_104 = F_56 ( V_2 -> V_105 ) ;
V_55 -> V_33 = F_57 ( V_2 -> V_51 ) ;
V_55 -> V_43 = F_57 ( V_2 -> V_53 ) ;
V_55 -> V_40 . V_106 = V_20 ;
V_55 -> V_40 . V_107 = V_20 ;
V_55 -> V_40 . type = V_71 ;
V_55 -> V_57 = V_59 ;
V_5 = F_53 ( V_2 -> V_44 , V_2 -> V_91 , V_55 , sizeof( * V_55 ) ) ;
if ( V_5 == - V_98 && ! F_50 ( V_2 -> V_44 ,
V_2 -> V_91 , V_55 , sizeof( * V_55 ) ) )
return 0 ;
F_18 ( V_55 ) ;
if ( V_5 )
F_32 ( L_19 ,
V_2 -> V_53 , F_63 ( V_2 -> V_91 ) , V_5 ) ;
return V_5 ;
}
static struct V_1 * F_64 ( T_1 V_99 , T_1 * V_130 ,
long V_111 )
{
struct V_1 * V_2 ;
struct V_1 * V_131 ;
struct V_28 * V_29 ;
struct V_121 * V_122 ;
int V_132 = 0 ;
int V_133 = 0 ;
long V_113 ;
V_2 = F_6 ( V_99 ) ;
if ( ! V_2 )
return F_65 ( - V_37 ) ;
if ( ! F_1 ( V_2 , V_35 ) ) {
V_133 = - V_37 ;
goto V_134;
}
if ( ! V_111 ) {
if ( ! F_66 ( & V_2 -> V_47 ) ) {
V_133 = - V_102 ;
goto V_134;
}
} else {
F_21 ( V_114 , L_20 , V_2 -> V_53 ) ;
V_113 = F_60 ( & V_2 -> V_47 ,
V_111 ) ;
if ( ! V_113 ) {
V_133 = - V_115 ;
goto V_134;
} else if ( V_113 == - V_116 ) {
V_133 = - V_117 ;
goto V_134;
}
}
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 != V_35 ) {
V_133 = - V_135 ;
} else if ( F_45 ( & V_2 -> V_46 ) ) {
F_21 ( V_114 , L_21 ,
V_2 -> V_53 ) ;
V_133 = - V_63 ;
}
F_3 ( & V_2 -> V_6 ) ;
if ( V_133 ) {
F_21 ( V_114 , L_22 , V_2 -> V_53 , V_133 ) ;
goto V_134;
}
V_131 = F_67 ( V_136 ) ;
if ( F_68 ( V_131 ) ) {
F_32 ( L_23 ,
F_69 ( V_131 ) ) ;
V_133 = - V_38 ;
goto V_134;
}
F_2 ( & V_2 -> V_6 ) ;
V_29 = F_70 ( & V_2 -> V_46 , struct V_28 , V_45 ) ;
F_47 ( & V_29 -> V_45 ) ;
V_131 -> V_44 = V_2 -> V_44 ;
V_131 -> V_103 = V_2 -> V_103 ;
V_131 -> V_105 = V_29 -> V_39 ;
V_131 -> V_51 = V_29 -> V_42 ;
F_3 ( & V_2 -> V_6 ) ;
F_9 ( V_2 ) ;
V_2 = NULL ;
F_18 ( V_29 ) ;
F_71 ( & V_137 ) ;
F_72 (peer, &new_ch->cmdev->peers, node) {
if ( V_122 -> V_91 -> V_39 == V_131 -> V_105 ) {
F_21 ( V_36 , L_24 ,
F_63 ( V_122 -> V_91 ) ) ;
V_132 = 1 ;
break;
}
}
F_73 ( & V_137 ) ;
if ( ! V_132 ) {
V_133 = - V_34 ;
goto V_138;
}
V_131 -> V_91 = V_122 -> V_91 ;
V_131 -> V_7 = V_50 ;
F_74 ( & V_131 -> V_6 ) ;
F_62 ( V_131 ) ;
* V_130 = V_131 -> V_53 ;
return V_131 ;
V_138:
F_2 ( & V_11 ) ;
F_28 ( & V_12 , V_131 -> V_53 ) ;
F_3 ( & V_11 ) ;
F_9 ( V_131 ) ;
V_134:
if ( V_2 )
F_9 ( V_2 ) ;
* V_130 = 0 ;
return F_65 ( V_133 ) ;
}
static int F_75 ( T_1 V_99 )
{
struct V_1 * V_2 = NULL ;
int V_5 = 0 ;
F_21 ( V_139 , L_25 , V_99 ) ;
V_2 = F_6 ( V_99 ) ;
if ( ! V_2 || ! F_4 ( V_2 , V_140 , V_35 ) )
V_5 = - V_37 ;
F_9 ( V_2 ) ;
return V_5 ;
}
static int F_76 ( T_1 V_99 , T_3 V_141 , void * V_126 )
{
struct V_1 * V_2 = NULL ;
struct V_15 * V_16 ;
int V_88 = - V_34 ;
F_21 ( V_139 , L_26 , V_99 , V_141 ) ;
F_71 ( & V_137 ) ;
F_72 (cm, &cm_dev_list, list) {
if ( ( V_16 -> V_19 -> V_53 == V_141 ) &&
F_31 ( V_16 -> V_19 ) ) {
V_88 = 0 ;
break;
}
}
if ( V_88 )
goto exit;
V_2 = F_6 ( V_99 ) ;
if ( ! V_2 ) {
V_88 = - V_37 ;
goto exit;
}
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 != V_124 ) {
F_3 ( & V_2 -> V_6 ) ;
V_88 = - V_37 ;
goto V_134;
}
V_2 -> V_44 = V_16 ;
V_2 -> V_103 = V_16 -> V_19 -> V_127 ;
V_2 -> V_126 = V_126 ;
V_2 -> V_7 = V_140 ;
F_3 ( & V_2 -> V_6 ) ;
V_134:
F_9 ( V_2 ) ;
exit:
F_73 ( & V_137 ) ;
return V_88 ;
}
static struct V_1 * F_67 ( T_1 V_142 )
{
int V_53 ;
int V_143 , V_144 ;
struct V_1 * V_2 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return F_65 ( - V_38 ) ;
if ( V_142 ) {
V_143 = V_142 ;
V_144 = V_142 + 1 ;
} else {
V_143 = V_145 ;
V_144 = V_146 + 1 ;
}
F_77 ( V_26 ) ;
F_2 ( & V_11 ) ;
V_53 = F_78 ( & V_12 , V_2 , V_143 , V_144 , V_147 ) ;
F_3 ( & V_11 ) ;
F_79 () ;
if ( V_53 < 0 ) {
F_18 ( V_2 ) ;
return F_65 ( V_53 == - V_148 ? - V_98 : V_53 ) ;
}
V_2 -> V_53 = ( T_1 ) V_53 ;
V_2 -> V_7 = V_124 ;
F_74 ( & V_2 -> V_6 ) ;
F_80 ( & V_2 -> V_46 ) ;
F_80 ( & V_2 -> V_149 ) ;
F_81 ( & V_2 -> V_47 ) ;
F_81 ( & V_2 -> V_150 ) ;
F_82 ( & V_2 -> V_13 ) ;
V_2 -> V_64 . V_66 = 0 ;
V_2 -> V_64 . V_119 = 0 ;
V_2 -> V_64 . V_65 = 0 ;
V_2 -> V_64 . V_110 = 0 ;
return V_2 ;
}
static struct V_1 * F_83 ( T_1 * V_142 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_67 ( * V_142 ) ;
if ( F_68 ( V_2 ) )
F_21 ( V_139 , L_27 ,
* V_142 , F_69 ( V_2 ) ) ;
else
* V_142 = V_2 -> V_53 ;
return V_2 ;
}
static void V_14 ( struct V_151 * V_13 )
{
struct V_1 * V_2 = F_37 ( V_13 , struct V_1 , V_13 ) ;
int V_18 ;
F_21 ( V_139 , L_25 , V_2 -> V_53 ) ;
if ( V_2 -> V_64 . V_110 ) {
for ( V_18 = 0 ;
V_18 < V_21 && V_2 -> V_64 . V_110 ; V_18 ++ ) {
if ( V_2 -> V_64 . V_109 [ V_18 ] != NULL ) {
F_18 ( V_2 -> V_64 . V_109 [ V_18 ] ) ;
V_2 -> V_64 . V_110 -- ;
}
}
}
if ( V_2 -> V_64 . V_65 )
for ( V_18 = 0 ; V_18 < V_21 && V_2 -> V_64 . V_65 ; V_18 ++ ) {
if ( V_2 -> V_64 . V_61 [ V_18 ] != NULL ) {
F_18 ( V_2 -> V_64 . V_61 [ V_18 ] ) ;
V_2 -> V_64 . V_65 -- ;
}
}
F_25 ( & V_2 -> V_150 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_30 * V_55 ;
int V_5 ;
V_55 = F_22 ( sizeof( * V_55 ) , V_26 ) ;
if ( V_55 == NULL )
return - V_38 ;
V_55 -> V_40 . V_41 = F_56 ( V_2 -> V_103 ) ;
V_55 -> V_40 . V_104 = F_56 ( V_2 -> V_105 ) ;
V_55 -> V_40 . V_106 = V_20 ;
V_55 -> V_40 . V_107 = V_20 ;
V_55 -> V_40 . type = V_71 ;
V_55 -> V_57 = V_60 ;
V_55 -> V_33 = F_57 ( V_2 -> V_51 ) ;
V_55 -> V_43 = F_57 ( V_2 -> V_53 ) ;
V_5 = F_53 ( V_2 -> V_44 , V_2 -> V_91 , V_55 , sizeof( * V_55 ) ) ;
if ( V_5 == - V_98 && ! F_50 ( V_2 -> V_44 , V_2 -> V_91 ,
V_55 , sizeof( * V_55 ) ) )
return 0 ;
F_18 ( V_55 ) ;
if ( V_5 )
F_32 ( L_28 , V_2 -> V_53 , V_5 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned long V_152 = F_85 ( 3000 ) ;
enum V_3 V_7 ;
long V_113 ;
int V_5 = 0 ;
F_21 ( V_139 , L_29 ,
V_2 -> V_53 , V_100 -> V_101 , F_55 ( V_100 ) ) ;
V_7 = F_5 ( V_2 , V_153 ) ;
if ( V_7 == V_50 )
F_84 ( V_2 ) ;
F_86 ( & V_2 -> V_47 ) ;
F_9 ( V_2 ) ;
V_113 = F_60 ( & V_2 -> V_150 , V_152 ) ;
F_21 ( V_114 , L_18 , V_2 -> V_53 , V_113 ) ;
if ( V_113 == 0 ) {
F_21 ( V_139 , L_30 ,
V_100 -> V_101 , F_55 ( V_100 ) , V_2 -> V_53 ) ;
V_5 = - V_154 ;
} else if ( V_113 == - V_116 ) {
F_21 ( V_139 , L_31 ,
V_100 -> V_101 , F_55 ( V_100 ) , V_2 -> V_53 ) ;
V_5 = - V_117 ;
}
if ( ! V_5 ) {
F_21 ( V_139 , L_32 , V_2 -> V_53 ) ;
F_18 ( V_2 ) ;
} else {
F_21 ( V_139 , L_33 , V_2 -> V_53 ) ;
}
return V_5 ;
}
static int F_87 ( struct V_155 * V_155 , struct V_156 * V_157 )
{
F_21 ( V_158 , L_34 ,
V_100 -> V_101 , F_55 ( V_100 ) , V_157 ) ;
if ( F_45 ( & V_159 ) )
return - V_34 ;
return 0 ;
}
static int F_88 ( struct V_155 * V_155 , struct V_156 * V_157 )
{
struct V_1 * V_2 , * V_160 ;
unsigned int V_18 ;
F_89 ( V_161 ) ;
F_21 ( EXIT , L_35 ,
V_100 -> V_101 , F_55 ( V_100 ) , V_157 ) ;
F_2 ( & V_11 ) ;
F_90 (&ch_idr, ch, i) {
if ( V_2 && V_2 -> V_157 == V_157 ) {
F_21 ( EXIT , L_36 ,
V_2 -> V_53 , V_100 -> V_101 ,
F_55 ( V_100 ) ) ;
F_28 ( & V_12 , V_2 -> V_53 ) ;
F_91 ( & V_2 -> V_149 , & V_161 ) ;
}
}
F_3 ( & V_11 ) ;
if ( ! F_45 ( & V_161 ) ) {
F_46 (ch, _c, &list, ch_node) {
F_47 ( & V_2 -> V_149 ) ;
F_29 ( V_2 ) ;
}
}
return 0 ;
}
static int F_92 ( void T_4 * V_162 )
{
T_5 T_4 * V_163 = V_162 ;
T_5 V_141 ;
T_5 V_65 = 0 ;
struct V_15 * V_16 ;
if ( F_93 ( V_141 , V_163 ) )
return - V_164 ;
if ( V_141 >= V_165 )
return - V_37 ;
F_71 ( & V_137 ) ;
F_72 (cm, &cm_dev_list, list) {
if ( V_16 -> V_19 -> V_53 == V_141 ) {
V_65 = V_16 -> V_166 ;
F_73 ( & V_137 ) ;
if ( F_94 ( V_162 , & V_65 , sizeof( T_5 ) ) )
return - V_164 ;
return 0 ;
}
}
F_73 ( & V_137 ) ;
return - V_34 ;
}
static int F_95 ( void T_4 * V_162 )
{
struct V_15 * V_16 ;
struct V_121 * V_122 ;
T_5 V_167 [ 2 ] ;
void * V_61 ;
T_5 V_24 ;
T_5 * V_168 ;
T_5 V_18 = 0 ;
int V_5 = 0 ;
if ( F_96 ( & V_167 , V_162 , sizeof( V_167 ) ) )
return - V_164 ;
if ( V_167 [ 1 ] >= V_165 || V_167 [ 0 ] > V_169 )
return - V_37 ;
F_71 ( & V_137 ) ;
F_72 (cm, &cm_dev_list, list)
if ( V_16 -> V_19 -> V_53 == ( T_3 ) V_167 [ 1 ] )
goto V_132;
F_73 ( & V_137 ) ;
return - V_34 ;
V_132:
V_24 = F_97 ( V_167 [ 0 ] , V_16 -> V_166 ) ;
V_61 = F_98 ( V_24 + 2 , sizeof( T_5 ) , V_26 ) ;
if ( ! V_61 ) {
F_73 ( & V_137 ) ;
return - V_38 ;
}
V_168 = ( T_5 * ) ( ( V_170 ) V_61 + 2 * sizeof( T_5 ) ) ;
F_72 (peer, &cm->peers, node) {
* V_168 = ( T_5 ) V_122 -> V_91 -> V_39 ;
V_168 ++ ;
if ( ++ V_18 == V_24 )
break;
}
F_73 ( & V_137 ) ;
( ( T_5 * ) V_61 ) [ 0 ] = V_18 ;
( ( T_5 * ) V_61 ) [ 1 ] = V_167 [ 1 ] ;
if ( F_94 ( V_162 , V_61 , sizeof( T_5 ) * ( V_167 [ 0 ] + 2 ) ) )
V_5 = - V_164 ;
F_18 ( V_61 ) ;
return V_5 ;
}
static int F_99 ( void T_4 * V_162 )
{
int V_5 = 0 ;
T_5 V_171 ;
void * V_61 ;
struct V_15 * V_16 ;
T_5 * V_168 ;
int V_65 = 0 ;
if ( F_96 ( & V_171 , V_162 , sizeof( V_171 ) ) )
return - V_164 ;
if ( V_171 == 0 || V_171 > V_165 )
return - V_37 ;
V_61 = F_98 ( V_171 + 1 , sizeof( T_5 ) , V_26 ) ;
if ( ! V_61 )
return - V_38 ;
V_168 = ( T_5 * ) ( ( V_170 ) V_61 + sizeof( T_5 ) ) ;
F_71 ( & V_137 ) ;
F_72 (cm, &cm_dev_list, list) {
if ( V_65 ++ < V_171 ) {
* V_168 = ( V_16 -> V_19 -> V_53 << 16 ) |
V_16 -> V_19 -> V_127 ;
V_168 ++ ;
}
}
F_73 ( & V_137 ) ;
* ( ( T_5 * ) V_61 ) = V_65 ;
if ( F_94 ( V_162 , V_61 , sizeof( T_5 ) * ( V_65 + 1 ) ) )
V_5 = - V_164 ;
F_18 ( V_61 ) ;
return V_5 ;
}
static int F_100 ( struct V_156 * V_157 , void T_4 * V_162 )
{
T_1 T_4 * V_163 = V_162 ;
T_1 V_142 ;
struct V_1 * V_2 ;
if ( F_93 ( V_142 , V_163 ) )
return - V_164 ;
F_21 ( V_139 , L_37 ,
V_142 , V_100 -> V_101 , F_55 ( V_100 ) ) ;
V_2 = F_83 ( & V_142 ) ;
if ( F_68 ( V_2 ) )
return F_69 ( V_2 ) ;
V_2 -> V_157 = V_157 ;
F_21 ( V_139 , L_38 ,
V_142 , V_100 -> V_101 , F_55 ( V_100 ) ) ;
return F_101 ( V_142 , V_163 ) ;
}
static int F_102 ( struct V_156 * V_157 , void T_4 * V_162 )
{
T_1 T_4 * V_163 = V_162 ;
T_1 V_142 ;
struct V_1 * V_2 ;
if ( F_93 ( V_142 , V_163 ) )
return - V_164 ;
F_21 ( V_139 , L_29 ,
V_142 , V_100 -> V_101 , F_55 ( V_100 ) ) ;
F_2 ( & V_11 ) ;
V_2 = F_7 ( & V_12 , V_142 ) ;
if ( ! V_2 ) {
F_3 ( & V_11 ) ;
return 0 ;
}
if ( V_2 -> V_157 != V_157 ) {
F_3 ( & V_11 ) ;
return - V_37 ;
}
F_28 ( & V_12 , V_2 -> V_53 ) ;
F_3 ( & V_11 ) ;
return F_29 ( V_2 ) ;
}
static int F_103 ( void T_4 * V_162 )
{
struct V_172 V_42 ;
if ( F_96 ( & V_42 , V_162 , sizeof( V_42 ) ) )
return - V_164 ;
if ( V_42 . V_141 >= V_165 )
return - V_37 ;
return F_76 ( V_42 . V_53 , V_42 . V_141 , NULL ) ;
}
static int F_104 ( void T_4 * V_162 )
{
T_1 T_4 * V_163 = V_162 ;
T_1 V_142 ;
if ( F_93 ( V_142 , V_163 ) )
return - V_164 ;
return F_75 ( V_142 ) ;
}
static int F_105 ( struct V_156 * V_157 , void T_4 * V_162 )
{
struct V_173 V_174 ;
long V_175 ;
struct V_1 * V_2 ;
if ( F_96 ( & V_174 , V_162 , sizeof( V_174 ) ) )
return - V_164 ;
F_21 ( V_139 , L_39 ,
V_174 . V_142 , V_100 -> V_101 , F_55 ( V_100 ) ) ;
V_175 = V_174 . V_176 ?
F_85 ( V_174 . V_176 ) : 0 ;
V_2 = F_64 ( V_174 . V_142 , & V_174 . V_142 , V_175 ) ;
if ( F_68 ( V_2 ) )
return F_69 ( V_2 ) ;
V_2 -> V_157 = V_157 ;
F_21 ( V_139 , L_40 ,
V_2 -> V_53 , V_100 -> V_101 , F_55 ( V_100 ) ) ;
if ( F_94 ( V_162 , & V_174 , sizeof( V_174 ) ) )
return - V_164 ;
return 0 ;
}
static int F_106 ( void T_4 * V_162 )
{
struct V_172 V_42 ;
struct V_15 * V_16 ;
struct V_121 * V_122 ;
int V_5 = - V_34 ;
if ( F_96 ( & V_42 , V_162 , sizeof( V_42 ) ) )
return - V_164 ;
if ( V_42 . V_141 >= V_165 )
return - V_37 ;
F_71 ( & V_137 ) ;
F_72 (cm, &cm_dev_list, list) {
if ( V_16 -> V_19 -> V_53 == V_42 . V_141 ) {
V_5 = 0 ;
break;
}
}
if ( V_5 )
goto V_96;
if ( V_42 . V_177 >= F_107 ( V_16 -> V_19 -> V_178 ) ) {
V_5 = - V_37 ;
goto V_96;
}
V_5 = - V_34 ;
F_72 (peer, &cm->peers, node) {
if ( V_122 -> V_91 -> V_39 == V_42 . V_177 ) {
V_5 = 0 ;
break;
}
}
if ( V_5 )
goto V_96;
F_73 ( & V_137 ) ;
return F_61 ( V_42 . V_53 , V_16 , V_122 , V_42 . V_179 ) ;
V_96:
F_73 ( & V_137 ) ;
return V_5 ;
}
static int F_108 ( void T_4 * V_162 )
{
struct V_180 V_17 ;
void * V_61 ;
int V_5 ;
if ( F_96 ( & V_17 , V_162 , sizeof( V_17 ) ) )
return - V_164 ;
if ( V_17 . V_181 > V_25 )
return - V_37 ;
V_61 = F_109 ( ( void T_4 * ) ( V_170 ) V_17 . V_17 , V_17 . V_181 ) ;
if ( F_68 ( V_61 ) )
return F_69 ( V_61 ) ;
V_5 = F_54 ( V_17 . V_142 , V_61 , V_17 . V_181 ) ;
F_18 ( V_61 ) ;
return V_5 ;
}
static int F_110 ( void T_4 * V_162 )
{
struct V_180 V_17 ;
struct V_1 * V_2 ;
void * V_61 ;
long V_182 ;
int V_5 = 0 , V_183 ;
if ( F_96 ( & V_17 , V_162 , sizeof( V_17 ) ) )
return - V_164 ;
if ( V_17 . V_142 == 0 || V_17 . V_181 == 0 )
return - V_37 ;
V_2 = F_6 ( V_17 . V_142 ) ;
if ( ! V_2 )
return - V_34 ;
V_182 = V_17 . V_182 ? F_85 ( V_17 . V_182 ) : V_184 ;
V_5 = F_59 ( V_2 , & V_61 , V_182 ) ;
if ( V_5 )
goto V_56;
V_183 = F_97 ( V_17 . V_181 , ( T_1 ) ( V_25 ) ) ;
if ( F_94 ( ( void T_4 * ) ( V_170 ) V_17 . V_17 , V_61 , V_183 ) )
V_5 = - V_164 ;
F_58 ( V_2 , V_61 ) ;
V_56:
F_9 ( V_2 ) ;
return V_5 ;
}
static long
F_111 ( struct V_156 * V_157 , unsigned int V_185 , unsigned long V_162 )
{
switch ( V_185 ) {
case V_186 :
return F_92 ( ( void T_4 * ) V_162 ) ;
case V_187 :
return F_95 ( ( void T_4 * ) V_162 ) ;
case V_188 :
return F_100 ( V_157 , ( void T_4 * ) V_162 ) ;
case V_189 :
return F_102 ( V_157 , ( void T_4 * ) V_162 ) ;
case V_190 :
return F_103 ( ( void T_4 * ) V_162 ) ;
case V_191 :
return F_104 ( ( void T_4 * ) V_162 ) ;
case V_192 :
return F_105 ( V_157 , ( void T_4 * ) V_162 ) ;
case V_193 :
return F_106 ( ( void T_4 * ) V_162 ) ;
case V_194 :
return F_108 ( ( void T_4 * ) V_162 ) ;
case V_195 :
return F_110 ( ( void T_4 * ) V_162 ) ;
case V_196 :
return F_99 ( ( void T_4 * ) V_162 ) ;
default:
break;
}
return - V_37 ;
}
static int F_112 ( struct V_197 * V_198 , struct V_199 * V_200 )
{
struct V_121 * V_122 ;
struct V_93 * V_91 = F_113 ( V_198 ) ;
struct V_15 * V_16 ;
if ( ! F_114 ( V_91 ) )
return 0 ;
F_21 ( V_201 , L_41 , F_63 ( V_91 ) ) ;
V_122 = F_15 ( sizeof( * V_122 ) , V_26 ) ;
if ( ! V_122 )
return - V_38 ;
F_115 ( & V_137 ) ;
F_72 (cm, &cm_dev_list, list) {
if ( V_16 -> V_19 == V_91 -> V_202 -> V_203 )
goto V_132;
}
F_116 ( & V_137 ) ;
F_18 ( V_122 ) ;
return - V_34 ;
V_132:
V_122 -> V_91 = V_91 ;
F_24 ( & V_122 -> V_45 , & V_16 -> V_204 ) ;
V_16 -> V_166 ++ ;
F_116 ( & V_137 ) ;
return 0 ;
}
static void F_117 ( struct V_197 * V_198 , struct V_199 * V_200 )
{
struct V_93 * V_91 = F_113 ( V_198 ) ;
struct V_15 * V_16 ;
struct V_121 * V_122 ;
struct V_1 * V_2 , * V_160 ;
unsigned int V_18 ;
bool V_132 = false ;
F_89 ( V_161 ) ;
if ( ! F_114 ( V_91 ) )
return;
F_21 ( V_201 , L_41 , F_63 ( V_91 ) ) ;
F_115 ( & V_137 ) ;
F_72 (cm, &cm_dev_list, list) {
if ( V_16 -> V_19 == V_91 -> V_202 -> V_203 ) {
V_132 = true ;
break;
}
}
if ( ! V_132 ) {
F_116 ( & V_137 ) ;
return;
}
V_132 = false ;
F_72 (peer, &cm->peers, node) {
if ( V_122 -> V_91 == V_91 ) {
F_21 ( V_201 , L_42 , F_63 ( V_91 ) ) ;
V_132 = true ;
F_47 ( & V_122 -> V_45 ) ;
V_16 -> V_166 -- ;
F_18 ( V_122 ) ;
break;
}
}
F_116 ( & V_137 ) ;
if ( ! V_132 )
return;
F_2 ( & V_11 ) ;
F_90 (&ch_idr, ch, i) {
if ( V_2 && V_2 -> V_91 == V_91 ) {
if ( F_118 ( & V_91 -> V_7 ) != V_205 )
F_5 ( V_2 , V_54 ) ;
F_28 ( & V_12 , V_2 -> V_53 ) ;
F_91 ( & V_2 -> V_149 , & V_161 ) ;
}
}
F_3 ( & V_11 ) ;
if ( ! F_45 ( & V_161 ) ) {
F_46 (ch, _c, &list, ch_node) {
F_47 ( & V_2 -> V_149 ) ;
F_29 ( V_2 ) ;
}
}
}
static int F_119 ( T_6 V_206 )
{
int V_5 ;
F_120 ( & V_207 . V_208 , & V_209 ) ;
V_207 . V_208 . V_210 = V_211 ;
V_5 = F_121 ( & V_207 . V_208 , V_206 , 1 ) ;
if ( V_5 < 0 ) {
F_32 ( L_43 , V_5 ) ;
return V_5 ;
}
V_207 . V_198 = F_122 ( V_212 , NULL , V_206 , NULL , V_213 ) ;
if ( F_68 ( V_207 . V_198 ) ) {
F_123 ( & V_207 . V_208 ) ;
return F_69 ( V_207 . V_198 ) ;
}
F_21 ( V_214 , L_44 ,
V_213 , F_124 ( V_206 ) , F_125 ( V_206 ) ) ;
return 0 ;
}
static int F_126 ( struct V_197 * V_198 ,
struct V_215 * V_216 )
{
int V_88 ;
int V_18 ;
struct V_15 * V_16 ;
struct V_73 * V_19 = F_127 ( V_198 ) ;
F_21 ( V_214 , L_45 , V_19 -> V_217 ) ;
V_16 = F_22 ( sizeof( * V_16 ) , V_26 ) ;
if ( ! V_16 )
return - V_38 ;
V_16 -> V_19 = V_19 ;
V_88 = F_128 ( V_19 , V_16 , V_20 ,
V_83 , F_49 ) ;
if ( V_88 ) {
F_32 ( L_46 ,
V_20 , V_19 -> V_217 ) ;
F_18 ( V_16 ) ;
return - V_34 ;
}
V_88 = F_129 ( V_19 , V_16 , V_20 ,
V_21 , F_40 ) ;
if ( V_88 ) {
F_32 ( L_47 ,
V_20 , V_19 -> V_217 ) ;
F_130 ( V_19 , V_20 ) ;
F_18 ( V_16 ) ;
return - V_34 ;
}
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ )
V_16 -> V_22 [ V_18 ] = NULL ;
V_16 -> V_23 = V_21 ;
F_131 ( & V_16 -> V_70 ) ;
F_14 ( V_16 , V_21 ) ;
V_16 -> V_77 = F_132 ( V_218 L_48 ) ;
F_133 ( & V_16 -> V_69 , F_36 ) ;
V_16 -> V_89 = 0 ;
V_16 -> V_80 = 0 ;
V_16 -> V_82 = 0 ;
F_74 ( & V_16 -> V_81 ) ;
F_80 ( & V_16 -> V_204 ) ;
V_16 -> V_166 = 0 ;
F_80 ( & V_16 -> V_85 ) ;
F_115 ( & V_137 ) ;
F_24 ( & V_16 -> V_161 , & V_159 ) ;
F_116 ( & V_137 ) ;
return 0 ;
}
static void F_134 ( struct V_197 * V_198 ,
struct V_215 * V_216 )
{
struct V_73 * V_19 = F_127 ( V_198 ) ;
struct V_15 * V_16 ;
struct V_121 * V_122 , * V_219 ;
struct V_1 * V_2 , * V_160 ;
unsigned int V_18 ;
bool V_132 = false ;
F_89 ( V_161 ) ;
F_21 ( V_214 , L_49 , V_19 -> V_217 ) ;
F_115 ( & V_137 ) ;
F_72 (cm, &cm_dev_list, list) {
if ( V_16 -> V_19 == V_19 ) {
F_47 ( & V_16 -> V_161 ) ;
V_132 = true ;
break;
}
}
F_116 ( & V_137 ) ;
if ( ! V_132 )
return;
F_135 ( V_16 -> V_77 ) ;
F_136 ( V_16 -> V_77 ) ;
F_2 ( & V_11 ) ;
F_90 (&ch_idr, ch, i) {
if ( V_2 -> V_44 == V_16 ) {
F_21 ( V_201 , L_50 ,
V_19 -> V_217 , V_2 -> V_53 ) ;
F_28 ( & V_12 , V_2 -> V_53 ) ;
F_91 ( & V_2 -> V_149 , & V_161 ) ;
}
}
F_3 ( & V_11 ) ;
if ( ! F_45 ( & V_161 ) ) {
F_46 (ch, _c, &list, ch_node) {
F_47 ( & V_2 -> V_149 ) ;
F_29 ( V_2 ) ;
}
}
F_137 ( V_19 , V_20 ) ;
F_130 ( V_19 , V_20 ) ;
if ( ! F_45 ( & V_16 -> V_204 ) )
F_21 ( V_201 , L_51 ) ;
F_46 (peer, temp, &cm->peers, node) {
F_21 ( V_201 , L_42 , F_63 ( V_122 -> V_91 ) ) ;
F_47 ( & V_122 -> V_45 ) ;
F_18 ( V_122 ) ;
}
F_17 ( V_16 ) ;
F_18 ( V_16 ) ;
F_21 ( V_214 , L_52 , V_19 -> V_217 ) ;
}
static int F_138 ( struct V_220 * V_221 , unsigned long V_222 ,
void * V_223 )
{
struct V_1 * V_2 ;
unsigned int V_18 ;
F_89 ( V_161 ) ;
F_21 ( EXIT , L_53 ) ;
F_2 ( & V_11 ) ;
F_90 (&ch_idr, ch, i) {
if ( V_2 -> V_7 == V_50 ) {
F_21 ( EXIT , L_54 , V_2 -> V_53 ) ;
F_28 ( & V_12 , V_2 -> V_53 ) ;
F_91 ( & V_2 -> V_149 , & V_161 ) ;
}
}
F_3 ( & V_11 ) ;
F_72 (ch, &list, ch_node)
F_84 ( V_2 ) ;
return V_224 ;
}
static int T_7 F_139 ( void )
{
int V_5 ;
V_212 = F_140 ( V_211 , V_218 ) ;
if ( F_68 ( V_212 ) ) {
F_32 ( L_55 V_218 L_56 ) ;
return F_69 ( V_212 ) ;
}
V_5 = F_141 ( & V_225 , 0 , 1 , V_218 ) ;
if ( V_5 ) {
F_142 ( V_212 ) ;
return V_5 ;
}
V_226 = F_124 ( V_225 ) ;
V_227 = F_125 ( V_225 ) ;
F_21 ( V_158 , L_57 , V_226 ) ;
V_5 = F_143 ( & V_228 ) ;
if ( V_5 ) {
F_32 ( L_58 , V_5 ) ;
goto V_229;
}
V_5 = F_144 ( & V_230 ) ;
if ( V_5 ) {
F_32 ( L_59 , V_5 ) ;
goto V_231;
}
V_5 = F_145 ( & V_232 ) ;
if ( V_5 ) {
F_32 ( L_60 , V_5 ) ;
goto V_233;
}
V_5 = F_119 ( V_225 ) ;
if ( V_5 ) {
F_146 ( & V_232 ) ;
V_5 = - V_34 ;
goto V_233;
}
return 0 ;
V_233:
F_147 ( & V_230 ) ;
V_231:
F_148 ( & V_228 ) ;
V_229:
F_149 ( V_225 , 1 ) ;
F_142 ( V_212 ) ;
return V_5 ;
}
static void T_8 F_150 ( void )
{
F_21 ( EXIT , L_61 ) ;
F_146 ( & V_232 ) ;
F_147 ( & V_230 ) ;
F_148 ( & V_228 ) ;
F_151 ( & V_12 ) ;
F_152 ( V_207 . V_198 ) ;
F_123 ( & ( V_207 . V_208 ) ) ;
F_142 ( V_212 ) ;
F_149 ( V_225 , 1 ) ;
}
