void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 [ 0 ] ;
int V_8 , V_9 ;
V_9 = F_2 ( V_6 , & V_8 ) ;
if ( V_9 )
V_4 -> V_10 = V_11 ;
else
V_4 -> V_10 = V_12 ;
V_4 -> V_7 [ 0 ] = V_6 -> V_13 ;
V_4 -> V_7 [ 2 ] = V_8 ;
F_3 ( V_6 -> V_14 , V_4 ) ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 [ 0 ] ;
struct V_15 * V_16 =
(struct V_15 * ) V_4 -> V_7 [ 1 ] ;
F_5 ( & V_6 -> V_17 . V_18 ) ;
if ( V_4 -> V_10 == V_12 ) {
V_16 -> V_19 = V_20 ;
V_16 -> V_21 = ( int ) V_4 -> V_7 [ 2 ] ;
} else {
V_16 -> V_19 = V_22 ;
}
F_6 ( & V_6 -> V_17 . V_18 ) ;
F_7 ( & V_16 -> V_23 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 [ 0 ] ;
struct V_24 * V_25 ;
V_25 = F_9 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 ) {
V_4 -> V_7 [ 0 ] = V_6 -> V_13 ;
V_4 -> V_10 = V_27 ;
F_3 ( V_6 -> V_14 , V_4 ) ;
return;
}
memcpy ( & V_25 -> V_4 , V_4 , sizeof( struct V_3 ) ) ;
F_10 ( & V_25 -> V_28 ) ;
F_5 ( & V_29 . V_30 ) ;
F_11 ( & V_6 -> V_17 . V_31 ) ;
F_12 ( & V_25 -> V_28 , & V_29 . V_25 ) ;
F_6 ( & V_29 . V_30 ) ;
F_13 ( & V_29 . V_32 ) ;
}
void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 [ 0 ] ;
struct V_15 * V_16 =
(struct V_15 * ) V_4 -> V_7 [ 1 ] ;
F_5 ( & V_6 -> V_17 . V_18 ) ;
if ( V_4 -> V_10 == V_33 )
V_16 -> V_19 = V_20 ;
else
V_16 -> V_19 = V_22 ;
F_6 ( & V_6 -> V_17 . V_18 ) ;
F_7 ( & V_16 -> V_23 ) ;
}
void F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 [ 0 ] ;
int V_9 ;
V_9 = F_16 ( V_6 , V_4 -> V_7 [ 1 ] , V_4 -> V_7 [ 2 ] ,
V_34 ) ;
if ( V_9 )
V_4 -> V_10 = V_35 ;
else
V_4 -> V_10 = V_36 ;
V_4 -> V_7 [ 0 ] = V_6 -> V_13 ;
F_3 ( V_6 -> V_14 , V_4 ) ;
}
void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 [ 0 ] ;
int V_9 ;
V_9 = F_16 ( V_6 , V_4 -> V_7 [ 1 ] , V_4 -> V_7 [ 2 ] ,
V_37 ) ;
if ( V_9 )
V_4 -> V_10 = V_35 ;
else
V_4 -> V_10 = V_36 ;
V_4 -> V_7 [ 0 ] = V_6 -> V_13 ;
F_3 ( V_6 -> V_14 , V_4 ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 [ 0 ] ;
struct V_15 * V_16 =
(struct V_15 * ) V_4 -> V_7 [ 3 ] ;
F_5 ( & V_6 -> V_17 . V_18 ) ;
if ( V_4 -> V_10 == V_36 )
V_16 -> V_19 = V_20 ;
else
V_16 -> V_19 = V_22 ;
F_6 ( & V_6 -> V_17 . V_18 ) ;
F_7 ( & V_16 -> V_23 ) ;
}
static inline void * F_19 ( T_1 V_38 , struct V_39 * V_40 )
{
struct V_41 * * V_42 = V_40 -> V_43 -> V_42 ;
int V_44 = ( V_38 - V_40 -> V_45 ) >> V_46 ;
T_1 V_47 = V_38 & ~ V_48 ;
return F_20 ( V_42 [ V_44 ] ) + V_47 ;
}
static void F_21 ( void * V_49 )
{
struct V_50 * V_51 = V_49 ;
F_22 ( V_51 -> V_6 -> V_14 -> V_52 , V_51 ,
V_51 -> V_53 ) ;
}
static int F_23 ( T_2 V_54 , T_3 V_55 , T_4 V_56 )
{
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
struct V_57 * V_58 = V_6 -> V_17 . V_57 ;
struct V_59 * V_60 = V_58 -> V_61 ;
bool V_62 = ! F_24 ( V_58 -> V_61 , 1 , 1 , 1 ) ;
struct V_63 * V_64 ;
struct V_50 * V_51 = NULL ;
T_3 V_65 ;
T_5 V_66 ;
int V_9 ;
V_64 = V_60 -> V_67 ( V_58 , 0 , 0 , 0 , V_68 ) ;
if ( ! V_64 ) {
V_9 = - V_69 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
goto V_73;
}
V_66 = V_64 -> V_74 ( V_64 ) ;
if ( F_26 ( V_66 ) ) {
V_9 = ( int ) V_66 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
goto V_73;
}
F_27 ( V_58 ) ;
if ( V_62 ) {
V_64 = V_60 -> V_75 ( V_58 , V_55 , V_56 , 0 ) ;
} else {
V_51 = F_28 ( V_6 -> V_14 -> V_52 , V_26 ,
& V_65 ) ;
if ( ! V_51 ) {
V_9 = - V_69 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
goto V_73;
}
V_51 -> V_56 = V_56 ;
V_51 -> V_53 = V_65 ;
V_51 -> V_6 = V_6 ;
V_65 += F_29 ( struct V_50 , V_56 ) ;
V_64 = V_60 -> V_67 ( V_58 , V_55 , V_65 , sizeof( V_56 ) ,
V_76 ) ;
}
if ( ! V_64 ) {
V_9 = - V_69 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
goto V_77;
}
if ( ! V_62 ) {
V_64 -> V_78 = F_21 ;
V_64 -> V_79 = V_51 ;
}
V_66 = V_64 -> V_74 ( V_64 ) ;
if ( F_26 ( V_66 ) ) {
V_9 = - V_80 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
goto V_77;
}
F_27 ( V_58 ) ;
return 0 ;
V_77:
if ( ! V_62 )
F_22 ( V_6 -> V_14 -> V_52 , V_51 ,
V_51 -> V_53 ) ;
V_73:
return V_9 ;
}
int F_16 ( T_2 V_54 , T_1 V_45 , T_4 V_56 ,
enum V_81 type )
{
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
struct V_39 * V_40 = NULL ;
struct V_82 V_83 ;
T_3 V_84 ;
int V_9 ;
F_5 ( & V_6 -> V_17 . V_18 ) ;
V_83 . V_85 = & V_40 ;
V_83 . V_45 = V_45 ;
V_83 . V_86 = sizeof( T_4 ) ;
V_83 . V_87 = V_88 ;
V_83 . type = V_89 ;
if ( type == V_34 )
V_83 . V_90 = & V_6 -> V_17 . V_91 ;
else
V_83 . V_90 = & V_6 -> V_17 . V_92 ;
V_9 = F_30 ( & V_83 ) ;
if ( V_9 ) {
F_25 ( V_29 . V_93 . V_94 ,
L_1 , V_72 , __LINE__ , V_9 ) ;
goto V_95;
}
if ( F_31 () && F_32 ( V_6 -> V_14 ) ) {
T_4 * V_96 ;
if ( type == V_34 )
V_96 = F_19 ( V_45 , V_40 ) ;
else
V_96 =
F_19 ( V_45 , (struct V_39 * )
V_40 -> V_97 ) ;
* V_96 = V_56 ;
} else {
V_84 = F_33 ( V_40 , V_45 ) ;
V_9 = F_23 ( V_54 , V_84 , V_56 ) ;
}
V_95:
F_6 ( & V_6 -> V_17 . V_18 ) ;
return V_9 ;
}
static int F_34 ( T_2 V_54 , int V_8 )
{
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
T_5 V_66 = V_8 & ~ V_98 ;
int V_9 ;
V_9 = F_35 ( V_6 -> V_17 . V_99 ,
F_36 (
V_6 -> V_17 . V_57 ,
V_66 , NULL , NULL ) ==
V_100 ,
V_101 ) ;
if ( ! V_9 )
V_9 = - V_102 ;
else if ( V_9 > 0 )
V_9 = 0 ;
return V_9 ;
}
void F_37 ( void )
{
struct V_103 * V_104 , * V_105 ;
struct V_24 * V_25 ;
struct V_5 * V_6 ;
int V_8 , V_9 ;
F_38 () ;
F_5 ( & V_29 . V_30 ) ;
F_39 (item, tmp, &scif_info.fence) {
V_25 = F_40 ( V_104 , struct V_24 ,
V_28 ) ;
F_41 ( & V_25 -> V_28 ) ;
V_6 = (struct V_5 * ) V_25 -> V_4 . V_7 [ 0 ] ;
V_8 = V_25 -> V_4 . V_7 [ 2 ] ;
V_9 = F_34 ( V_6 , V_8 ) ;
if ( V_9 )
V_25 -> V_4 . V_10 = V_27 ;
else
V_25 -> V_4 . V_10 = V_33 ;
V_25 -> V_4 . V_7 [ 0 ] = V_6 -> V_13 ;
F_3 ( V_6 -> V_14 , & V_25 -> V_4 ) ;
F_42 ( V_25 ) ;
if ( ! F_43 ( 1 , & V_6 -> V_17 . V_31 ) )
F_13 ( & V_29 . V_32 ) ;
}
F_6 ( & V_29 . V_30 ) ;
}
static int F_44 ( T_2 V_54 , int V_10 , int V_8 , int * V_106 )
{
int V_9 ;
struct V_3 V_4 ;
struct V_15 * V_16 ;
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
V_16 = F_9 ( sizeof( * V_16 ) , V_26 ) ;
if ( ! V_16 ) {
V_9 = - V_69 ;
goto error;
}
V_16 -> V_19 = V_107 ;
F_45 ( & V_16 -> V_23 ) ;
V_4 . V_65 = V_6 -> V_108 ;
V_4 . V_10 = V_10 ;
V_4 . V_7 [ 0 ] = V_6 -> V_13 ;
V_4 . V_7 [ 1 ] = ( T_4 ) V_16 ;
if ( V_10 == V_109 )
V_4 . V_7 [ 2 ] = V_8 ;
F_46 ( & V_6 -> V_110 ) ;
if ( V_6 -> V_19 == V_111 )
V_9 = F_3 ( V_6 -> V_14 , & V_4 ) ;
else
V_9 = - V_112 ;
F_47 ( & V_6 -> V_110 ) ;
if ( V_9 )
goto V_113;
V_114:
V_9 = F_48 ( & V_16 -> V_23 ,
V_101 ) ;
if ( ! V_9 && F_49 ( V_6 ) )
goto V_114;
if ( ! V_9 )
V_9 = - V_115 ;
if ( V_9 > 0 )
V_9 = 0 ;
F_5 ( & V_6 -> V_17 . V_18 ) ;
if ( V_9 < 0 ) {
if ( V_16 -> V_19 == V_107 )
V_16 -> V_19 = V_22 ;
}
if ( V_16 -> V_19 == V_22 && ! V_9 )
V_9 = - V_69 ;
if ( V_10 == V_116 && V_16 -> V_19 == V_20 )
* V_106 = V_98 | V_16 -> V_21 ;
F_6 ( & V_6 -> V_17 . V_18 ) ;
V_113:
F_42 ( V_16 ) ;
error:
return V_9 ;
}
static int F_50 ( T_2 V_54 , int * V_106 )
{
return F_44 ( V_54 , V_116 , 0 , V_106 ) ;
}
static int F_51 ( T_2 V_54 , int V_8 )
{
return F_44 ( V_54 , V_109 , V_8 , NULL ) ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_15 * V_16 )
{
int V_9 ;
V_114:
V_9 = F_48 ( & V_16 -> V_23 ,
V_101 ) ;
if ( ! V_9 && F_49 ( V_6 ) )
goto V_114;
if ( ! V_9 )
V_9 = - V_115 ;
if ( V_9 > 0 )
V_9 = 0 ;
if ( V_9 < 0 ) {
F_5 ( & V_6 -> V_17 . V_18 ) ;
if ( V_16 -> V_19 == V_107 )
V_16 -> V_19 = V_22 ;
F_6 ( & V_6 -> V_17 . V_18 ) ;
}
if ( V_16 -> V_19 == V_22 && ! V_9 )
V_9 = - V_117 ;
return V_9 ;
}
static int F_53 ( T_2 V_54 , T_1 V_118 , T_4 V_119 ,
T_1 V_120 , T_4 V_121 , int V_122 )
{
int V_9 = 0 ;
struct V_3 V_4 ;
struct V_15 * V_16 ;
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
V_16 = F_9 ( sizeof( * V_16 ) , V_26 ) ;
if ( ! V_16 ) {
V_9 = - V_69 ;
goto error;
}
V_16 -> V_19 = V_107 ;
F_45 ( & V_16 -> V_23 ) ;
V_4 . V_65 = V_6 -> V_108 ;
if ( V_122 & V_123 ) {
V_4 . V_10 = V_124 ;
V_4 . V_7 [ 0 ] = V_6 -> V_13 ;
V_4 . V_7 [ 1 ] = V_118 ;
V_4 . V_7 [ 2 ] = V_119 ;
V_4 . V_7 [ 3 ] = ( T_4 ) V_16 ;
F_46 ( & V_6 -> V_110 ) ;
if ( V_6 -> V_19 == V_111 )
V_9 = F_3 ( V_6 -> V_14 , & V_4 ) ;
else
V_9 = - V_112 ;
F_47 ( & V_6 -> V_110 ) ;
if ( V_9 )
goto V_113;
V_9 = F_52 ( V_6 , V_16 ) ;
if ( V_9 )
goto V_113;
}
V_16 -> V_19 = V_107 ;
if ( V_122 & V_125 ) {
V_4 . V_10 = V_126 ;
V_4 . V_7 [ 0 ] = V_6 -> V_13 ;
V_4 . V_7 [ 1 ] = V_120 ;
V_4 . V_7 [ 2 ] = V_121 ;
V_4 . V_7 [ 3 ] = ( T_4 ) V_16 ;
F_46 ( & V_6 -> V_110 ) ;
if ( V_6 -> V_19 == V_111 )
V_9 = F_3 ( V_6 -> V_14 , & V_4 ) ;
else
V_9 = - V_112 ;
F_47 ( & V_6 -> V_110 ) ;
if ( V_9 )
goto V_113;
V_9 = F_52 ( V_6 , V_16 ) ;
}
V_113:
F_42 ( V_16 ) ;
error:
return V_9 ;
}
static void F_54 ( void * V_49 )
{
struct V_5 * V_6 = (struct V_5 * ) V_49 ;
F_55 ( & V_6 -> V_17 . V_99 ) ;
F_56 ( & V_6 -> V_17 . V_31 ) ;
}
int F_2 ( T_2 V_54 , int * V_8 )
{
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
struct V_57 * V_58 = V_6 -> V_17 . V_57 ;
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_63 * V_64 ;
T_5 V_66 ;
int V_9 ;
V_64 = V_60 -> V_67 ( V_58 , 0 , 0 , 0 , V_68 ) ;
if ( ! V_64 ) {
V_9 = - V_69 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
return V_9 ;
}
V_66 = V_64 -> V_74 ( V_64 ) ;
if ( F_26 ( V_66 ) ) {
V_9 = ( int ) V_66 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
return V_9 ;
}
F_27 ( V_58 ) ;
V_64 = V_60 -> V_127 ( V_58 , V_76 ) ;
if ( ! V_64 ) {
V_9 = - V_69 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
return V_9 ;
}
V_64 -> V_78 = F_54 ;
V_64 -> V_79 = V_6 ;
* V_8 = V_66 = V_64 -> V_74 ( V_64 ) ;
if ( F_26 ( V_66 ) ) {
V_9 = ( int ) V_66 ;
F_25 ( & V_6 -> V_14 -> V_70 -> V_71 , L_1 ,
V_72 , __LINE__ , V_9 ) ;
return V_9 ;
}
F_11 ( & V_6 -> V_17 . V_31 ) ;
F_27 ( V_58 ) ;
return 0 ;
}
int F_57 ( T_2 V_54 , int V_122 , int * V_8 )
{
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
int V_9 = 0 ;
F_58 ( V_29 . V_93 . V_94 ,
L_2 ,
V_6 , V_122 , * V_8 ) ;
V_9 = F_59 ( V_6 ) ;
if ( V_9 )
return V_9 ;
if ( V_122 & ~ ( V_128 | V_129 ) )
return - V_130 ;
if ( ! ( V_122 & ( V_128 | V_129 ) ) )
return - V_130 ;
if ( ( V_122 & V_128 ) && ( V_122 & V_129 ) )
return - V_130 ;
if ( F_32 ( V_6 -> V_14 ) && F_31 () ) {
* V_8 = V_131 ;
return 0 ;
}
if ( V_122 & V_128 )
V_9 = F_2 ( V_54 , V_8 ) ;
else
V_9 = F_50 ( V_6 , V_8 ) ;
if ( V_9 )
F_25 ( V_29 . V_93 . V_94 ,
L_1 , V_72 , __LINE__ , V_9 ) ;
F_58 ( V_29 . V_93 . V_94 ,
L_3 ,
V_6 , V_122 , * V_8 , V_9 ) ;
return V_9 ;
}
int F_60 ( T_2 V_54 , int V_8 )
{
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
int V_9 = 0 ;
F_58 ( V_29 . V_93 . V_94 ,
L_4 ,
V_6 , V_8 ) ;
V_9 = F_59 ( V_6 ) ;
if ( V_9 )
return V_9 ;
if ( F_32 ( V_6 -> V_14 ) && F_31 () ) {
if ( V_8 == V_131 )
return 0 ;
else
return - V_130 ;
}
if ( V_8 & V_98 )
V_9 = F_51 ( V_54 , V_8 ) ;
else
V_9 = F_34 ( V_54 , V_8 ) ;
if ( V_9 < 0 )
F_25 ( V_29 . V_93 . V_94 ,
L_1 , V_72 , __LINE__ , V_9 ) ;
return V_9 ;
}
int F_61 ( T_2 V_54 , T_1 V_120 , T_4 V_121 ,
T_1 V_118 , T_4 V_119 , int V_122 )
{
struct V_5 * V_6 = (struct V_5 * ) V_54 ;
int V_9 = 0 ;
F_58 ( V_29 . V_93 . V_94 ,
L_5 ,
V_6 , V_120 , V_121 , V_118 , V_119 , V_122 ) ;
V_9 = F_59 ( V_6 ) ;
if ( V_9 )
return V_9 ;
if ( V_122 & ~ ( V_128 | V_129 |
V_123 | V_125 ) )
return - V_130 ;
if ( ! ( V_122 & ( V_128 | V_129 ) ) )
return - V_130 ;
if ( ( V_122 & V_128 ) && ( V_122 & V_129 ) )
return - V_130 ;
if ( ! ( V_122 & ( V_123 | V_125 ) ) )
return - V_130 ;
if ( ( V_122 & V_123 ) && ( V_120 & ( sizeof( V_132 ) - 1 ) ) )
return - V_130 ;
if ( ( V_122 & V_125 ) && ( V_118 & ( sizeof( V_132 ) - 1 ) ) )
return - V_130 ;
if ( V_122 & V_129 ) {
V_9 = F_53 ( V_54 , V_118 , V_119 , V_120 ,
V_121 , V_122 ) ;
} else {
if ( V_122 & V_123 ) {
V_9 = F_16 ( V_54 , V_120 , V_121 ,
V_34 ) ;
if ( V_9 )
goto V_133;
}
if ( V_122 & V_125 )
V_9 = F_16 ( V_54 , V_118 ,
V_119 , V_37 ) ;
}
V_133:
if ( V_9 )
F_25 ( V_29 . V_93 . V_94 ,
L_1 , V_72 , __LINE__ , V_9 ) ;
return V_9 ;
}
