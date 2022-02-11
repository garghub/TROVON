static int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 * V_4 ;
V_4 = F_2 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
* V_4 = V_3 ? V_6 : V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_3 )
{
T_1 * V_4 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
* V_3 = F_6 ( * V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const T_3 * V_8 )
{
T_1 * V_4 ;
V_4 = F_2 ( V_2 , sizeof( T_2 ) + V_8 -> V_9 ) ;
if ( ! V_4 )
return - V_5 ;
F_8 ( V_4 , V_8 -> V_10 , V_8 -> V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
T_1 * V_4 ;
V_4 = F_2 ( V_2 , 4 ) ;
if ( ! V_4 )
return - V_5 ;
* V_4 = F_10 ( V_12 -> V_13 ) ;
F_11 ( V_2 , V_12 -> V_14 , V_12 -> V_15 , V_12 -> V_13 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_3 * V_8 )
{
T_2 V_16 ;
T_1 * V_4 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_16 = F_13 ( V_4 ) ;
V_4 = F_5 ( V_2 , V_16 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
if ( V_8 -> V_9 == 0 ) {
return 0 ;
}
if ( V_16 > V_8 -> V_9 )
return - V_5 ;
if ( ! V_8 -> V_10 ) {
V_8 -> V_10 = F_14 ( V_4 , V_16 , V_17 ) ;
if ( ! V_8 -> V_10 )
return - V_18 ;
} else {
memcpy ( V_8 -> V_10 , V_4 , V_16 ) ;
}
V_8 -> V_9 = V_16 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_21 ;
V_21 = F_7 ( V_2 , & V_20 -> V_22 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_20 -> V_23 ) ;
return V_21 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_21 ;
V_21 = F_12 ( V_2 , & V_20 -> V_22 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_20 -> V_23 ) ;
return V_21 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
T_1 * V_4 ;
if ( V_25 -> V_26 != 0 )
return - V_27 ;
V_4 = F_2 ( V_2 , 4 ) ;
if ( ! V_4 )
return - V_5 ;
* V_4 = 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_19 V_28 ;
T_2 V_26 , V_29 ;
T_1 * V_4 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_26 = F_13 ( V_4 ++ ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ ) {
F_16 ( V_2 , & V_28 ) ;
}
V_25 -> V_26 = 0 ;
V_25 -> V_10 = NULL ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 * V_30 )
{
T_1 * V_4 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( ! V_4 )
return - V_27 ;
memcpy ( V_30 , V_4 , sizeof( T_2 ) ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_2 V_16 ;
T_1 * V_4 ;
T_2 V_33 ;
T_2 V_34 ;
int V_29 , V_21 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_16 = F_13 ( V_4 ) ;
if ( V_16 > ( 3 + V_35 ) * sizeof( T_2 ) )
return - V_5 ;
V_21 = F_19 ( V_2 , & V_33 ) ;
if ( V_21 )
return V_21 ;
V_32 -> V_36 = F_21 ( & V_37 , V_33 ) ;
V_21 = F_19 ( V_2 , & V_33 ) ;
if ( V_21 )
return V_21 ;
V_32 -> V_38 = F_22 ( & V_37 , V_33 ) ;
V_21 = F_19 ( V_2 , & V_33 ) ;
if ( V_21 )
return V_21 ;
V_34 = V_33 ;
if ( ( 3 + V_34 ) * sizeof( T_2 ) != V_16 )
return - V_27 ;
V_32 -> V_39 = F_23 ( V_34 ) ;
if ( V_32 -> V_39 == NULL )
return - V_18 ;
for ( V_29 = 0 ; V_29 < V_34 ; V_29 ++ ) {
T_4 V_40 ;
V_21 = F_19 ( V_2 , & V_33 ) ;
if ( V_21 )
goto V_41;
V_21 = - V_27 ;
V_40 = F_22 ( & V_37 , V_33 ) ;
if ( ! F_24 ( V_40 ) )
goto V_41;
V_32 -> V_39 -> V_42 [ V_29 ] = V_40 ;
}
return 0 ;
V_41:
F_25 ( V_32 -> V_39 ) ;
return V_21 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_31 * V_32 ;
T_2 V_26 , V_29 ;
T_1 * V_4 ;
int V_21 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_26 = F_13 ( V_4 ++ ) ;
if ( ! V_26 )
return 0 ;
V_25 -> V_26 = 1 ;
V_25 -> V_10 = F_27 ( sizeof( struct V_19 ) , V_17 ) ;
if ( ! V_25 -> V_10 )
return - V_18 ;
V_32 = F_28 ( sizeof( struct V_31 ) , V_17 ) ;
if ( ! V_32 ) {
F_29 ( V_25 -> V_10 ) ;
return - V_18 ;
}
V_25 -> V_10 [ 0 ] . V_22 . V_10 = V_43 ;
V_25 -> V_10 [ 0 ] . V_22 . V_9 = sizeof( V_43 ) ;
V_25 -> V_10 [ 0 ] . V_23 . V_10 = ( void * ) V_32 ;
V_25 -> V_10 [ 0 ] . V_23 . V_9 = 0 ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ ) {
T_3 V_28 = { 0 , NULL } ;
T_2 V_16 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_16 = F_13 ( V_4 ) ;
V_4 = F_5 ( V_2 , V_16 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
if ( V_16 == sizeof( V_43 ) &&
memcmp ( V_4 , V_43 , sizeof( V_43 ) ) == 0 ) {
V_21 = F_20 ( V_2 , V_32 ) ;
if ( V_21 )
return V_21 ;
V_25 -> V_10 [ 0 ] . V_23 . V_9 = 1 ;
} else {
V_21 = F_12 ( V_2 , & V_28 ) ;
if ( V_21 )
return V_21 ;
}
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
T_1 * V_4 ;
int V_21 ;
V_4 = F_5 ( V_2 , 8 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_4 = F_31 ( V_4 , & V_45 -> V_46 ) ;
V_21 = F_12 ( V_2 , & V_45 -> V_47 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_5 ( V_2 , 8 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_4 = F_31 ( V_4 , & V_45 -> V_48 ) ;
V_21 = F_12 ( V_2 , & V_45 -> V_49 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_45 -> V_50 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_45 -> V_51 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_18 ( V_2 , & V_45 -> V_52 ) ;
return V_21 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_53 * V_54 )
{
struct V_19 V_20 ;
T_1 * V_4 ;
int V_21 ;
V_21 = F_7 ( V_2 , & V_54 -> V_55 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_54 -> V_51 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_2 ( V_2 , 4 ) ;
* V_4 = F_10 ( 2 ) ;
V_20 . V_22 . V_10 = V_56 ;
V_20 . V_22 . V_9 = sizeof( V_56 ) ;
V_20 . V_23 . V_10 = V_57 ;
V_20 . V_23 . V_9 = sizeof( V_57 ) ;
V_21 = F_15 ( V_2 , & V_20 ) ;
V_20 . V_22 . V_10 = V_58 ;
V_20 . V_22 . V_9 = sizeof( V_58 ) ;
V_20 . V_23 . V_10 = V_43 ;
V_20 . V_23 . V_9 = sizeof( V_43 ) ;
V_21 = F_15 ( V_2 , & V_20 ) ;
return V_21 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
int V_21 ;
V_21 = F_12 ( V_2 , & V_60 -> V_60 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_60 -> V_23 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_18 ( V_2 , & V_60 -> V_61 ) ;
return V_21 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
T_1 * V_4 ;
if ( V_63 -> V_26 != 0 )
return - V_27 ;
V_4 = F_2 ( V_2 , 4 ) ;
if ( ! V_4 )
return - V_5 ;
* V_4 = 0 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_59 V_28 = { . V_60 = { . V_9 = 0 } } ;
T_2 V_26 , V_29 ;
T_1 * V_4 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_26 = F_13 ( V_4 ++ ) ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ ) {
F_33 ( V_2 , & V_28 ) ;
}
V_63 -> V_26 = 0 ;
V_63 -> V_10 = NULL ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
int V_21 ;
V_21 = F_7 ( V_2 , & V_65 -> V_66 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_67 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_67 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_67 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_34 ( V_2 , & V_68 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_17 ( V_2 , & V_69 ) ;
return V_21 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_70 V_71 = { . V_9 = 0 } ;
struct V_62 V_72 = { . V_26 = 0 } ;
struct V_24 V_73 = { . V_26 = 0 } ;
int V_21 ;
V_21 = F_12 ( V_2 , & V_65 -> V_66 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_71 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_71 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_71 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_35 ( V_2 , & V_72 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_18 ( V_2 , & V_73 ) ;
return V_21 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
T_1 * V_4 ;
if ( V_75 -> V_26 != 0 )
return - V_27 ;
V_4 = F_2 ( V_2 , 4 ) ;
if ( ! V_4 )
return - V_5 ;
* V_4 = 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
int V_21 ;
V_21 = F_36 ( V_2 , & V_77 -> V_78 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_38 ( V_2 , & V_77 -> V_79 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_77 -> V_80 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_1 ( V_2 , V_77 -> V_81 ) ;
return V_21 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_82 * V_54 )
{
T_1 * V_4 ;
int V_21 ;
V_21 = F_7 ( V_2 , & V_54 -> V_83 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_54 -> V_84 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_1 ( V_2 , V_54 -> V_85 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_54 -> V_47 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_36 ( V_2 , & V_54 -> V_86 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_36 ( V_2 , & V_54 -> V_87 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_2 ( V_2 , 8 + 8 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 = F_41 ( V_4 , V_54 -> V_88 ) ;
V_4 = F_41 ( V_4 , V_54 -> V_89 ) ;
V_21 = F_1 ( V_2 , V_54 -> V_90 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_1 ( V_2 , V_54 -> V_91 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_17 ( V_2 , & V_54 -> V_52 ) ;
return V_21 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_82 * V_54 )
{
T_1 * V_4 ;
int V_21 ;
V_21 = F_12 ( V_2 , & V_54 -> V_83 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_54 -> V_84 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_2 , & V_54 -> V_85 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_54 -> V_47 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_37 ( V_2 , & V_54 -> V_86 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_37 ( V_2 , & V_54 -> V_87 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_5 ( V_2 , 8 + 8 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_4 = F_31 ( V_4 , & V_54 -> V_88 ) ;
V_4 = F_31 ( V_4 , & V_54 -> V_89 ) ;
V_21 = F_4 ( V_2 , & V_54 -> V_90 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_2 , & V_54 -> V_91 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_18 ( V_2 , & V_54 -> V_52 ) ;
return V_21 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
T_1 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 , 8 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 = F_41 ( V_4 , V_93 -> V_94 ) ;
V_21 = F_7 ( V_2 , & V_93 -> V_95 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_2 ( V_2 , 8 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 = F_41 ( V_4 , V_93 -> V_96 ) ;
V_21 = F_7 ( V_2 , & V_93 -> V_97 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_93 -> V_98 ) ;
return V_21 ;
}
void F_44 ( struct V_99 * V_100 ,
struct V_1 * V_2 ,
const void * V_10 )
{
const struct V_101 * V_102 = V_10 ;
int V_21 ;
V_21 = F_32 ( V_2 , & V_102 -> V_103 ) ;
if ( V_21 )
goto V_104;
if ( V_102 -> V_105 )
V_21 = F_40 ( V_2 , V_102 -> V_105 ) ;
else
V_21 = F_1 ( V_2 , 0 ) ;
if ( V_21 )
goto V_104;
if ( V_102 -> V_106 )
V_21 = F_39 ( V_2 , V_102 -> V_106 ) ;
else
V_21 = F_1 ( V_2 , 0 ) ;
if ( V_21 )
goto V_104;
V_21 = F_9 ( V_2 , & V_102 -> V_107 ) ;
if ( V_21 )
goto V_104;
if ( V_102 -> V_108 )
V_21 = F_43 ( V_2 , V_102 -> V_108 ) ;
else
V_21 = F_1 ( V_2 , 0 ) ;
if ( V_21 )
goto V_104;
V_21 = F_1 ( V_2 , V_102 -> V_109 ) ;
if ( V_21 )
goto V_104;
V_21 = F_17 ( V_2 , & V_102 -> V_52 ) ;
F_45 ( & V_100 -> V_110 ,
V_111 / 2 ,
V_102 -> V_14 , 0 , V_102 -> V_112 * V_111 ) ;
V_104:
if ( V_21 )
F_46 ( L_1 , V_21 ) ;
}
int F_47 ( struct V_99 * V_113 ,
struct V_1 * V_2 ,
void * V_10 )
{
struct V_114 * V_30 = V_10 ;
T_2 V_115 ;
int V_21 ;
struct V_116 * V_117 ;
V_117 = F_48 ( V_17 ) ;
if ( ! V_117 )
return - V_18 ;
F_49 ( V_2 , F_50 ( V_117 ) , V_111 ) ;
V_21 = F_30 ( V_2 , & V_30 -> V_45 ) ;
if ( V_21 )
goto V_118;
V_21 = F_4 ( V_2 , & V_115 ) ;
if ( V_21 )
goto V_118;
if ( V_115 ) {
V_21 = F_42 ( V_2 , V_30 -> V_105 ) ;
if ( V_21 )
goto V_118;
} else {
V_30 -> V_105 = NULL ;
}
V_21 = F_4 ( V_2 , & V_115 ) ;
if ( V_21 )
goto V_118;
if ( V_115 ) {
V_21 = F_12 ( V_2 , V_30 -> V_119 ) ;
if ( V_21 )
goto V_118;
} else {
V_30 -> V_119 = NULL ;
}
V_21 = F_4 ( V_2 , & V_115 ) ;
if ( V_21 )
goto V_118;
if ( V_115 ) {
V_21 = - V_27 ;
goto V_118;
}
V_21 = F_26 ( V_2 , & V_30 -> V_52 ) ;
V_118:
F_51 ( V_117 ) ;
return V_21 ;
}
