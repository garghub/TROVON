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
T_3 * V_8 )
{
T_1 * V_4 ;
V_4 = F_2 ( V_2 , sizeof( T_2 ) + V_8 -> V_9 ) ;
if ( ! V_4 )
return - V_5 ;
F_8 ( V_4 , V_8 -> V_10 , V_8 -> V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
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
struct V_24 * V_25 )
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
static int F_19 ( void * * V_4 , void * V_30 , T_4 * V_31 )
{
void * V_32 = * V_4 ;
void * V_33 = ( void * ) ( ( char * ) V_32 + sizeof( T_4 ) ) ;
if ( F_3 ( V_33 > V_30 || V_33 < V_32 ) )
return - V_27 ;
memcpy ( V_31 , V_32 , sizeof( T_4 ) ) ;
* V_4 = V_33 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
T_2 V_16 ;
T_1 * V_4 ;
void * V_36 , * V_37 ;
T_4 V_38 ;
int V_39 , V_29 , V_21 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_16 = F_13 ( V_4 ) ;
V_4 = F_5 ( V_2 , V_16 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_36 = V_4 ;
V_37 = V_36 + V_16 ;
V_21 = F_19 ( & V_36 , V_37 , & V_38 ) ;
if ( V_21 )
return V_21 ;
V_35 -> V_40 = F_21 ( & V_41 , V_38 ) ;
V_21 = F_19 ( & V_36 , V_37 , & V_38 ) ;
if ( V_21 )
return V_21 ;
V_35 -> V_42 = F_22 ( & V_41 , V_38 ) ;
V_21 = F_19 ( & V_36 , V_37 , & V_38 ) ;
if ( V_21 )
return V_21 ;
V_39 = V_38 ;
V_35 -> V_43 = F_23 ( V_39 ) ;
if ( V_35 -> V_43 == NULL )
return - V_18 ;
for ( V_29 = 0 ; V_29 < V_39 ; V_29 ++ ) {
T_5 V_44 ;
V_21 = F_19 ( & V_36 , V_37 , & V_38 ) ;
if ( V_21 )
goto V_45;
V_21 = - V_27 ;
V_44 = F_22 ( & V_41 , V_38 ) ;
if ( ! F_24 ( V_44 ) )
goto V_45;
F_25 ( V_35 -> V_43 , V_29 ) = V_44 ;
}
return 0 ;
V_45:
F_26 ( V_35 -> V_43 ) ;
return V_21 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_34 * V_35 ;
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
V_25 -> V_10 = F_28 ( sizeof( struct V_19 ) , V_17 ) ;
if ( ! V_25 -> V_10 )
return - V_18 ;
V_35 = F_28 ( sizeof( struct V_34 ) , V_17 ) ;
if ( ! V_35 ) {
F_29 ( V_25 -> V_10 ) ;
return - V_18 ;
}
V_25 -> V_10 [ 0 ] . V_22 . V_10 = V_46 ;
V_25 -> V_10 [ 0 ] . V_22 . V_9 = sizeof( V_46 ) ;
V_25 -> V_10 [ 0 ] . V_23 . V_10 = ( void * ) V_35 ;
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
if ( V_16 == sizeof( V_46 ) &&
memcmp ( V_4 , V_46 , sizeof( V_46 ) ) == 0 ) {
V_21 = F_20 ( V_2 , V_35 ) ;
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
struct V_47 * V_48 )
{
T_1 * V_4 ;
int V_21 ;
V_4 = F_5 ( V_2 , 8 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_4 = F_31 ( V_4 , & V_48 -> V_49 ) ;
V_21 = F_12 ( V_2 , & V_48 -> V_50 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_5 ( V_2 , 8 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_4 = F_31 ( V_4 , & V_48 -> V_51 ) ;
V_21 = F_12 ( V_2 , & V_48 -> V_52 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_48 -> V_53 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_48 -> V_54 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_18 ( V_2 , & V_48 -> V_55 ) ;
return V_21 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_19 V_20 ;
T_1 * V_4 ;
int V_21 ;
V_21 = F_7 ( V_2 , & V_57 -> V_58 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_57 -> V_54 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_2 ( V_2 , 4 ) ;
* V_4 = F_10 ( 2 ) ;
V_20 . V_22 . V_10 = V_59 ;
V_20 . V_22 . V_9 = sizeof( V_59 ) ;
V_20 . V_23 . V_10 = V_60 ;
V_20 . V_23 . V_9 = sizeof( V_60 ) ;
V_21 = F_15 ( V_2 , & V_20 ) ;
V_20 . V_22 . V_10 = V_61 ;
V_20 . V_22 . V_9 = sizeof( V_61 ) ;
V_20 . V_23 . V_10 = V_46 ;
V_20 . V_23 . V_9 = sizeof( V_46 ) ;
V_21 = F_15 ( V_2 , & V_20 ) ;
return V_21 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
int V_21 ;
V_21 = F_12 ( V_2 , & V_63 -> V_63 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_63 -> V_23 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_18 ( V_2 , & V_63 -> V_64 ) ;
return V_21 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
T_1 * V_4 ;
if ( V_66 -> V_26 != 0 )
return - V_27 ;
V_4 = F_2 ( V_2 , 4 ) ;
if ( ! V_4 )
return - V_5 ;
* V_4 = 0 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_62 V_28 ;
T_2 V_26 , V_29 ;
T_1 * V_4 ;
V_4 = F_5 ( V_2 , 4 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_26 = F_13 ( V_4 ++ ) ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ ) {
F_33 ( V_2 , & V_28 ) ;
}
V_66 -> V_26 = 0 ;
V_66 -> V_10 = NULL ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
int V_21 ;
V_21 = F_7 ( V_2 , & V_68 -> V_69 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_70 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_70 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_70 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_34 ( V_2 , & V_71 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_17 ( V_2 , & V_72 ) ;
return V_21 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_73 V_74 ;
struct V_65 V_75 ;
struct V_24 V_76 ;
int V_21 ;
V_21 = F_12 ( V_2 , & V_68 -> V_69 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_74 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_74 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_74 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_35 ( V_2 , & V_75 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_18 ( V_2 , & V_76 ) ;
return V_21 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
T_1 * V_4 ;
if ( V_78 -> V_26 != 0 )
return - V_27 ;
V_4 = F_2 ( V_2 , 4 ) ;
if ( ! V_4 )
return - V_5 ;
* V_4 = 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
int V_21 ;
V_21 = F_36 ( V_2 , & V_80 -> V_81 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_38 ( V_2 , & V_80 -> V_82 ) ;
V_21 = F_7 ( V_2 , & V_80 -> V_83 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_1 ( V_2 , V_80 -> V_84 ) ;
return V_21 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_85 * V_57 )
{
T_1 * V_4 ;
int V_21 ;
V_21 = F_7 ( V_2 , & V_57 -> V_86 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_57 -> V_87 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_1 ( V_2 , V_57 -> V_88 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_57 -> V_50 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_36 ( V_2 , & V_57 -> V_89 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_36 ( V_2 , & V_57 -> V_90 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_2 ( V_2 , 8 + 8 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 = F_41 ( V_4 , V_57 -> V_91 ) ;
V_4 = F_41 ( V_4 , V_57 -> V_92 ) ;
V_21 = F_1 ( V_2 , V_57 -> V_93 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_1 ( V_2 , V_57 -> V_94 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_17 ( V_2 , & V_57 -> V_55 ) ;
return V_21 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_85 * V_57 )
{
T_1 * V_4 ;
int V_21 ;
V_21 = F_12 ( V_2 , & V_57 -> V_86 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_57 -> V_87 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_2 , & V_57 -> V_88 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_2 , & V_57 -> V_50 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_37 ( V_2 , & V_57 -> V_89 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_37 ( V_2 , & V_57 -> V_90 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_5 ( V_2 , 8 + 8 ) ;
if ( F_3 ( V_4 == NULL ) )
return - V_5 ;
V_4 = F_31 ( V_4 , & V_57 -> V_91 ) ;
V_4 = F_31 ( V_4 , & V_57 -> V_92 ) ;
V_21 = F_4 ( V_2 , & V_57 -> V_93 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_2 , & V_57 -> V_94 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_18 ( V_2 , & V_57 -> V_55 ) ;
return V_21 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
T_1 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 , 8 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 = F_41 ( V_4 , V_96 -> V_97 ) ;
V_21 = F_7 ( V_2 , & V_96 -> V_98 ) ;
if ( V_21 )
return V_21 ;
V_4 = F_2 ( V_2 , 8 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 = F_41 ( V_4 , V_96 -> V_99 ) ;
V_21 = F_7 ( V_2 , & V_96 -> V_100 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , & V_96 -> V_101 ) ;
return V_21 ;
}
void F_44 ( struct V_102 * V_103 ,
struct V_1 * V_2 ,
struct V_104 * V_105 )
{
int V_21 ;
V_21 = F_32 ( V_2 , & V_105 -> V_106 ) ;
if ( V_21 )
goto V_107;
if ( V_105 -> V_108 ) {
V_21 = F_40 ( V_2 , V_105 -> V_108 ) ;
if ( V_21 )
goto V_107;
} else {
V_21 = F_1 ( V_2 , 0 ) ;
}
if ( V_105 -> V_109 ) {
V_21 = F_39 ( V_2 , V_105 -> V_109 ) ;
if ( V_21 )
goto V_107;
} else {
V_21 = F_1 ( V_2 , 0 ) ;
}
V_21 = F_9 ( V_2 , & V_105 -> V_110 ) ;
if ( V_21 )
goto V_107;
if ( V_105 -> V_111 ) {
V_21 = F_43 ( V_2 , V_105 -> V_111 ) ;
if ( V_21 )
goto V_107;
} else {
V_21 = F_1 ( V_2 , 0 ) ;
}
V_21 = F_1 ( V_2 , V_105 -> V_112 ) ;
if ( V_21 )
goto V_107;
V_21 = F_17 ( V_2 , & V_105 -> V_55 ) ;
V_107:
if ( V_21 )
F_45 ( L_1 , V_21 ) ;
}
int F_46 ( struct V_102 * V_113 ,
struct V_1 * V_2 ,
struct V_114 * V_31 )
{
T_2 V_115 ;
int V_21 ;
V_21 = F_30 ( V_2 , & V_31 -> V_48 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_4 ( V_2 , & V_115 ) ;
if ( V_21 )
return V_21 ;
if ( V_115 ) {
V_21 = F_42 ( V_2 , V_31 -> V_108 ) ;
if ( V_21 )
return V_21 ;
} else {
V_31 -> V_108 = NULL ;
}
V_21 = F_4 ( V_2 , & V_115 ) ;
if ( V_21 )
return V_21 ;
if ( V_115 ) {
V_21 = F_12 ( V_2 , V_31 -> V_116 ) ;
if ( V_21 )
return V_21 ;
} else {
V_31 -> V_116 = NULL ;
}
V_21 = F_4 ( V_2 , & V_115 ) ;
if ( V_21 )
return V_21 ;
if ( V_115 ) {
return - V_27 ;
}
V_21 = F_27 ( V_2 , & V_31 -> V_55 ) ;
return V_21 ;
}
