static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_7 -> V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_7 -> V_9 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_11 V_13 ;
if ( F_4 ( V_4 ) != F_8 ( V_7 -> V_8 ) ) {
F_9 ( L_1
L_2 , F_8 ( V_7 -> V_8 ) ,
( unsigned long long ) F_4 ( V_4 ) ) ;
return - V_14 ;
}
if ( F_8 ( V_7 -> V_15 ) != V_16 ) {
F_9 ( L_3
L_2 , F_8 ( V_7 -> V_15 ) ,
( unsigned long long ) V_16 ) ;
return - V_17 ;
}
V_13 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
if ( V_13 != V_7 -> V_9 ) {
F_9 ( L_4 ,
F_10 ( V_13 ) , F_10 ( V_7 -> V_9 ) ) ;
return - V_17 ;
}
return 0 ;
}
static T_2 F_11 ( T_3 V_4 , T_4 V_18 )
{
return ( V_4 << 24 ) | V_18 ;
}
static void F_12 ( T_2 V_2 , T_3 * V_4 , T_4 * V_18 )
{
* V_4 = V_2 >> 24 ;
* V_18 = V_2 & ( ( 1 << 24 ) - 1 ) ;
}
static void F_13 ( void * V_19 , void * V_20 )
{
struct V_21 * V_22 = V_19 ;
T_5 V_23 ;
T_2 V_4 ;
T_4 V_18 ;
memcpy ( & V_23 , V_20 , sizeof( V_23 ) ) ;
F_12 ( F_8 ( V_23 ) , & V_4 , & V_18 ) ;
F_14 ( V_22 , V_4 ) ;
}
static void F_15 ( void * V_19 , void * V_20 )
{
struct V_21 * V_22 = V_19 ;
T_5 V_23 ;
T_2 V_4 ;
T_4 V_18 ;
memcpy ( & V_23 , V_20 , sizeof( V_23 ) ) ;
F_12 ( F_8 ( V_23 ) , & V_4 , & V_18 ) ;
F_16 ( V_22 , V_4 ) ;
}
static int F_17 ( void * V_19 , void * V_24 , void * V_25 )
{
T_5 V_26 , V_27 ;
T_2 V_28 , V_29 ;
T_4 V_18 ;
memcpy ( & V_26 , V_24 , sizeof( V_26 ) ) ;
memcpy ( & V_27 , V_25 , sizeof( V_27 ) ) ;
F_12 ( F_8 ( V_26 ) , & V_28 , & V_18 ) ;
F_12 ( F_8 ( V_27 ) , & V_29 , & V_18 ) ;
return V_28 == V_29 ;
}
static void F_18 ( void * V_19 , void * V_30 )
{
struct V_31 * V_32 = V_19 ;
T_5 V_33 ;
T_2 V_34 ;
memcpy ( & V_33 , V_30 , sizeof( V_33 ) ) ;
V_34 = F_8 ( V_33 ) ;
F_19 ( V_32 -> V_35 , V_34 ) ;
}
static void F_20 ( void * V_19 , void * V_30 )
{
struct V_31 * V_32 = V_19 ;
T_5 V_33 ;
T_2 V_34 ;
memcpy ( & V_33 , V_30 , sizeof( V_33 ) ) ;
V_34 = F_8 ( V_33 ) ;
if ( F_21 ( V_32 , V_34 ) )
F_9 ( L_5 ) ;
}
static int F_22 ( void * V_19 , void * V_24 , void * V_25 )
{
T_5 V_26 , V_27 ;
memcpy ( & V_26 , V_24 , sizeof( V_26 ) ) ;
memcpy ( & V_27 , V_25 , sizeof( V_27 ) ) ;
return V_26 == V_27 ;
}
static int F_23 ( struct V_36 * V_37 , int * V_38 )
{
int V_39 ;
unsigned V_40 ;
struct V_3 * V_4 ;
T_5 * V_41 , V_42 = F_3 ( 0 ) ;
unsigned V_5 = F_24 ( V_37 ) / sizeof( T_5 ) ;
V_39 = F_25 ( V_37 , V_43 , NULL , & V_4 ) ;
if ( V_39 )
return V_39 ;
V_41 = F_2 ( V_4 ) ;
* V_38 = 1 ;
for ( V_40 = 0 ; V_40 < V_5 ; V_40 ++ ) {
if ( V_41 [ V_40 ] != V_42 ) {
* V_38 = 0 ;
break;
}
}
return F_26 ( V_4 ) ;
}
static int F_27 ( struct V_44 * V_45 ,
struct V_36 * V_37 ,
T_3 V_46 , int V_47 )
{
int V_39 ;
struct V_21 * V_22 , * V_48 ;
struct V_49 * V_35 ;
struct V_3 * V_50 ;
if ( V_47 ) {
V_39 = F_28 ( V_37 , V_43 ,
& V_51 , & V_35 , & V_22 , & V_50 ) ;
if ( V_39 < 0 ) {
F_9 ( L_6 ) ;
return V_39 ;
}
V_48 = F_29 ( V_35 , V_46 ) ;
if ( F_30 ( V_48 ) ) {
F_9 ( L_7 ) ;
V_39 = F_31 ( V_48 ) ;
goto V_52;
}
} else {
struct V_6 * V_7 = NULL ;
T_1 V_53 =
F_32 ( struct V_6 , V_54 ) ;
V_39 = F_33 ( V_37 , V_43 ,
& V_51 , V_53 ,
V_55 , & V_35 , & V_22 , & V_50 ) ;
if ( V_39 < 0 ) {
F_9 ( L_8 ) ;
return V_39 ;
}
V_7 = F_2 ( V_50 ) ;
V_48 = F_34 ( V_35 , V_7 -> V_56 ,
sizeof( V_7 -> V_56 ) ) ;
if ( F_30 ( V_48 ) ) {
F_9 ( L_9 ) ;
V_39 = F_31 ( V_48 ) ;
goto V_52;
}
}
V_39 = F_35 ( V_35 , V_50 ) ;
if ( V_39 < 0 ) {
F_9 ( L_10 ) ;
goto V_57;
}
V_45 -> V_37 = V_37 ;
V_45 -> V_58 = V_22 ;
V_45 -> V_48 = V_48 ;
V_45 -> V_35 = V_35 ;
V_45 -> V_59 = F_36 ( V_35 ) ;
if ( ! V_45 -> V_59 ) {
F_9 ( L_11 ) ;
V_39 = - V_60 ;
goto V_57;
}
V_45 -> V_32 . V_35 = V_35 ;
V_45 -> V_32 . V_61 = 2 ;
V_45 -> V_32 . V_62 . V_19 = V_45 -> V_48 ;
V_45 -> V_32 . V_62 . V_63 = sizeof( T_5 ) ;
V_45 -> V_32 . V_62 . V_64 = F_13 ;
V_45 -> V_32 . V_62 . V_65 = F_15 ;
V_45 -> V_32 . V_62 . V_66 = F_17 ;
memcpy ( & V_45 -> V_67 , & V_45 -> V_32 , sizeof( V_45 -> V_67 ) ) ;
V_45 -> V_67 . V_35 = V_45 -> V_59 ;
V_45 -> V_68 . V_35 = V_35 ;
V_45 -> V_68 . V_61 = 1 ;
V_45 -> V_68 . V_62 . V_19 = & V_45 -> V_32 ;
V_45 -> V_68 . V_62 . V_63 = sizeof( T_5 ) ;
V_45 -> V_68 . V_62 . V_64 = F_18 ;
V_45 -> V_68 . V_62 . V_65 = F_20 ;
V_45 -> V_68 . V_62 . V_66 = F_22 ;
V_45 -> V_69 . V_35 = V_35 ;
V_45 -> V_69 . V_61 = 1 ;
V_45 -> V_69 . V_62 . V_19 = V_45 -> V_48 ;
V_45 -> V_69 . V_62 . V_63 = sizeof( T_5 ) ;
V_45 -> V_69 . V_62 . V_64 = F_13 ;
V_45 -> V_69 . V_62 . V_65 = F_15 ;
V_45 -> V_69 . V_62 . V_66 = F_17 ;
V_45 -> V_70 . V_35 = V_35 ;
V_45 -> V_70 . V_61 = 1 ;
V_45 -> V_70 . V_62 . V_19 = NULL ;
V_45 -> V_70 . V_62 . V_63 = sizeof( struct V_71 ) ;
V_45 -> V_70 . V_62 . V_64 = NULL ;
V_45 -> V_70 . V_62 . V_65 = NULL ;
V_45 -> V_70 . V_62 . V_66 = NULL ;
V_45 -> V_34 = 0 ;
F_37 ( & V_45 -> V_72 ) ;
V_45 -> time = 0 ;
V_45 -> V_73 = 0 ;
V_45 -> V_74 = 0 ;
V_45 -> V_75 = 0 ;
V_45 -> V_10 = 0 ;
F_38 ( & V_45 -> V_76 ) ;
return 0 ;
V_57:
F_39 ( V_48 ) ;
V_52:
F_40 ( V_35 ) ;
F_39 ( V_22 ) ;
return V_39 ;
}
static int F_41 ( struct V_44 * V_45 )
{
int V_39 ;
T_6 V_77 ;
struct V_6 * V_7 ;
struct V_3 * V_50 ;
F_42 ( V_45 -> V_73 ) ;
V_39 = F_25 ( V_45 -> V_37 , V_43 ,
& V_51 , & V_50 ) ;
if ( V_39 )
return V_39 ;
V_7 = F_2 ( V_50 ) ;
V_45 -> time = F_10 ( V_7 -> time ) ;
V_45 -> V_34 = F_8 ( V_7 -> V_78 ) ;
V_45 -> V_74 = F_8 ( V_7 -> V_79 ) ;
V_45 -> V_75 = F_8 ( V_7 -> V_75 ) ;
V_45 -> V_10 = F_10 ( V_7 -> V_10 ) ;
V_45 -> V_80 = F_10 ( V_7 -> V_80 ) ;
V_77 = F_10 ( V_7 -> V_81 ) & ~ V_82 ;
if ( V_77 ) {
F_9 ( L_12
L_13 ,
( unsigned long ) V_77 ) ;
V_39 = - V_83 ;
goto V_84;
}
if ( F_43 ( V_45 -> V_85 -> V_86 ) )
goto V_84;
V_77 = F_10 ( V_7 -> V_87 ) & ~ V_88 ;
if ( V_77 ) {
F_9 ( L_14
L_13 ,
( unsigned long ) V_77 ) ;
V_39 = - V_83 ;
}
V_84:
F_26 ( V_50 ) ;
return V_39 ;
}
static int F_44 ( struct V_44 * V_45 )
{
int V_39 ;
struct V_89 * V_90 , * V_91 ;
struct V_71 V_92 ;
T_2 V_93 ;
F_45 (td, tmp, &pmd->thin_devices, list) {
if ( ! V_90 -> V_94 )
continue;
V_93 = V_90 -> V_95 ;
V_92 . V_96 = F_3 ( V_90 -> V_96 ) ;
V_92 . V_97 = F_3 ( V_90 -> V_97 ) ;
V_92 . V_98 = F_5 ( V_90 -> V_98 ) ;
V_92 . V_99 = F_5 ( V_90 -> V_99 ) ;
F_46 ( & V_92 ) ;
V_39 = F_47 ( & V_45 -> V_70 , V_45 -> V_74 ,
& V_93 , & V_92 , & V_45 -> V_74 ) ;
if ( V_39 )
return V_39 ;
if ( V_90 -> V_100 )
V_90 -> V_94 = 0 ;
else {
F_48 ( & V_90 -> V_101 ) ;
F_49 ( V_90 ) ;
}
V_45 -> V_73 = 1 ;
}
return 0 ;
}
static int F_50 ( struct V_44 * V_45 )
{
int V_39 ;
T_1 V_102 , V_103 ;
struct V_6 * V_7 ;
struct V_3 * V_50 ;
F_51 ( sizeof( struct V_6 ) > 512 ) ;
V_39 = F_44 ( V_45 ) ;
if ( V_39 < 0 )
goto V_84;
if ( ! V_45 -> V_73 )
goto V_84;
V_39 = F_52 ( V_45 -> V_48 ) ;
if ( V_39 < 0 )
goto V_84;
V_39 = F_53 ( V_45 -> V_35 ) ;
if ( V_39 < 0 )
goto V_84;
V_39 = F_54 ( V_45 -> V_58 , & V_102 ) ;
if ( V_39 < 0 )
goto V_84;
V_39 = F_54 ( V_45 -> V_58 , & V_103 ) ;
if ( V_39 < 0 )
goto V_84;
V_39 = F_55 ( V_45 -> V_37 , V_43 ,
& V_51 , & V_50 ) ;
if ( V_39 )
goto V_84;
V_7 = F_2 ( V_50 ) ;
V_7 -> time = F_5 ( V_45 -> time ) ;
V_7 -> V_78 = F_3 ( V_45 -> V_34 ) ;
V_7 -> V_79 = F_3 ( V_45 -> V_74 ) ;
V_7 -> V_75 = F_3 ( V_45 -> V_75 ) ;
V_7 -> V_10 = F_5 ( V_45 -> V_10 ) ;
V_39 = F_56 ( V_45 -> V_58 , & V_7 -> V_54 ,
V_102 ) ;
if ( V_39 < 0 )
goto V_104;
V_39 = F_56 ( V_45 -> V_48 , & V_7 -> V_56 ,
V_103 ) ;
if ( V_39 < 0 )
goto V_104;
V_39 = F_57 ( V_45 -> V_35 , V_50 ) ;
if ( ! V_39 )
V_45 -> V_73 = 0 ;
V_84:
return V_39 ;
V_104:
F_26 ( V_50 ) ;
return V_39 ;
}
struct V_44 * F_58 ( struct V_105 * V_85 ,
T_7 V_80 )
{
int V_39 ;
struct V_6 * V_7 ;
struct V_44 * V_45 ;
T_7 V_106 = F_59 ( V_85 -> V_107 ) >> V_108 ;
struct V_36 * V_37 ;
int V_47 ;
struct V_3 * V_50 ;
V_45 = F_60 ( sizeof( * V_45 ) , V_109 ) ;
if ( ! V_45 ) {
F_9 ( L_15 ) ;
return F_61 ( - V_60 ) ;
}
V_37 = F_62 ( V_85 , V_110 ,
V_111 , 5 ) ;
if ( ! V_37 ) {
F_9 ( L_16 ) ;
F_49 ( V_45 ) ;
return F_61 ( - V_60 ) ;
}
V_39 = F_23 ( V_37 , & V_47 ) ;
if ( V_39 ) {
F_63 ( V_37 ) ;
F_49 ( V_45 ) ;
return F_61 ( V_39 ) ;
}
V_39 = F_27 ( V_45 , V_37 , 0 , V_47 ) ;
if ( V_39 ) {
F_63 ( V_37 ) ;
F_49 ( V_45 ) ;
return F_61 ( V_39 ) ;
}
V_45 -> V_85 = V_85 ;
if ( ! V_47 ) {
V_39 = F_41 ( V_45 ) ;
if ( V_39 < 0 )
goto V_52;
return V_45 ;
}
V_39 = F_55 ( V_45 -> V_37 , V_43 ,
& V_51 , & V_50 ) ;
if ( V_39 )
goto V_52;
V_7 = F_2 ( V_50 ) ;
V_7 -> V_15 = F_3 ( V_16 ) ;
V_7 -> V_112 = F_5 ( V_113 ) ;
V_7 -> time = 0 ;
V_7 -> V_114 = F_5 ( V_110 >> V_108 ) ;
V_7 -> V_115 = F_3 ( V_106 >> V_116 ) ;
V_7 -> V_80 = F_5 ( V_80 ) ;
V_39 = F_26 ( V_50 ) ;
if ( V_39 < 0 )
goto V_52;
V_39 = F_64 ( & V_45 -> V_32 , & V_45 -> V_34 ) ;
if ( V_39 < 0 )
goto V_52;
V_39 = F_64 ( & V_45 -> V_70 , & V_45 -> V_74 ) ;
if ( V_39 < 0 ) {
F_9 ( L_17 ) ;
goto V_52;
}
V_45 -> V_10 = 0 ;
V_45 -> V_73 = 1 ;
V_39 = F_65 ( V_45 ) ;
if ( V_39 < 0 ) {
F_9 ( L_18 ,
V_117 , V_39 ) ;
goto V_52;
}
return V_45 ;
V_52:
if ( F_66 ( V_45 ) < 0 )
F_67 ( L_19 , V_117 ) ;
return F_61 ( V_39 ) ;
}
int F_66 ( struct V_44 * V_45 )
{
int V_39 ;
unsigned V_118 = 0 ;
struct V_89 * V_90 , * V_91 ;
F_68 ( & V_45 -> V_72 ) ;
F_45 (td, tmp, &pmd->thin_devices, list) {
if ( V_90 -> V_100 )
V_118 ++ ;
else {
F_48 ( & V_90 -> V_101 ) ;
F_49 ( V_90 ) ;
}
}
F_69 ( & V_45 -> V_72 ) ;
if ( V_118 ) {
F_9 ( L_20 ,
V_118 ) ;
return - V_119 ;
}
V_39 = F_50 ( V_45 ) ;
if ( V_39 < 0 )
F_67 ( L_21 ,
V_117 , V_39 ) ;
F_40 ( V_45 -> V_35 ) ;
F_40 ( V_45 -> V_59 ) ;
F_63 ( V_45 -> V_37 ) ;
F_39 ( V_45 -> V_58 ) ;
F_39 ( V_45 -> V_48 ) ;
F_49 ( V_45 ) ;
return 0 ;
}
static int F_70 ( struct V_44 * V_45 ,
T_8 V_120 , int V_47 ,
struct V_89 * * V_90 )
{
int V_39 , V_94 = 0 ;
struct V_89 * V_121 ;
T_2 V_93 = V_120 ;
struct V_71 V_122 ;
F_71 (td2, &pmd->thin_devices, list)
if ( V_121 -> V_95 == V_120 ) {
V_121 -> V_100 ++ ;
* V_90 = V_121 ;
return 0 ;
}
V_39 = F_72 ( & V_45 -> V_70 , V_45 -> V_74 ,
& V_93 , & V_122 ) ;
if ( V_39 ) {
if ( V_39 != - V_123 || ! V_47 )
return V_39 ;
V_94 = 1 ;
V_122 . V_96 = 0 ;
V_122 . V_97 = F_3 ( V_45 -> V_75 ) ;
V_122 . V_98 = F_5 ( V_45 -> time ) ;
V_122 . V_99 = F_5 ( V_45 -> time ) ;
}
* V_90 = F_60 ( sizeof( * * V_90 ) , V_124 ) ;
if ( ! * V_90 )
return - V_60 ;
( * V_90 ) -> V_45 = V_45 ;
( * V_90 ) -> V_95 = V_120 ;
( * V_90 ) -> V_100 = 1 ;
( * V_90 ) -> V_94 = V_94 ;
( * V_90 ) -> V_96 = F_8 ( V_122 . V_96 ) ;
( * V_90 ) -> V_97 = F_8 ( V_122 . V_97 ) ;
( * V_90 ) -> V_98 = F_10 ( V_122 . V_98 ) ;
( * V_90 ) -> V_99 = F_10 ( V_122 . V_99 ) ;
F_73 ( & ( * V_90 ) -> V_101 , & V_45 -> V_76 ) ;
return 0 ;
}
static void F_74 ( struct V_89 * V_90 )
{
-- V_90 -> V_100 ;
}
static int F_75 ( struct V_44 * V_45 ,
T_8 V_120 )
{
int V_39 ;
T_3 V_125 ;
T_2 V_93 = V_120 ;
struct V_71 V_122 ;
struct V_89 * V_90 ;
T_5 V_30 ;
V_39 = F_72 ( & V_45 -> V_70 , V_45 -> V_74 ,
& V_93 , & V_122 ) ;
if ( ! V_39 )
return - V_126 ;
V_39 = F_64 ( & V_45 -> V_69 , & V_125 ) ;
if ( V_39 )
return V_39 ;
V_30 = F_3 ( V_125 ) ;
F_46 ( & V_30 ) ;
V_39 = F_47 ( & V_45 -> V_68 , V_45 -> V_34 , & V_93 , & V_30 , & V_45 -> V_34 ) ;
if ( V_39 ) {
F_21 ( & V_45 -> V_69 , V_125 ) ;
return V_39 ;
}
V_39 = F_70 ( V_45 , V_120 , 1 , & V_90 ) ;
if ( V_39 ) {
F_74 ( V_90 ) ;
F_76 ( & V_45 -> V_68 , V_45 -> V_34 , & V_93 , & V_45 -> V_34 ) ;
F_21 ( & V_45 -> V_69 , V_125 ) ;
return V_39 ;
}
V_90 -> V_94 = 1 ;
F_74 ( V_90 ) ;
return V_39 ;
}
int F_77 ( struct V_44 * V_45 , T_8 V_120 )
{
int V_39 ;
F_78 ( & V_45 -> V_72 ) ;
V_39 = F_75 ( V_45 , V_120 ) ;
F_79 ( & V_45 -> V_72 ) ;
return V_39 ;
}
static int F_80 ( struct V_44 * V_45 ,
struct V_89 * V_127 ,
T_8 V_128 , T_4 time )
{
int V_39 ;
struct V_89 * V_90 ;
V_39 = F_70 ( V_45 , V_128 , 0 , & V_90 ) ;
if ( V_39 )
return V_39 ;
V_90 -> V_94 = 1 ;
V_90 -> V_99 = time ;
V_127 -> V_96 = V_90 -> V_96 ;
V_127 -> V_99 = time ;
F_74 ( V_90 ) ;
return 0 ;
}
static int F_81 ( struct V_44 * V_45 ,
T_8 V_120 , T_8 V_128 )
{
int V_39 ;
T_3 V_129 ;
T_2 V_93 = V_128 , V_130 = V_120 ;
struct V_89 * V_90 ;
struct V_71 V_122 ;
T_5 V_30 ;
V_39 = F_72 ( & V_45 -> V_70 , V_45 -> V_74 ,
& V_130 , & V_122 ) ;
if ( ! V_39 )
return - V_126 ;
V_39 = F_72 ( & V_45 -> V_68 , V_45 -> V_34 , & V_93 , & V_30 ) ;
if ( V_39 )
return V_39 ;
V_129 = F_8 ( V_30 ) ;
F_19 ( V_45 -> V_35 , V_129 ) ;
V_30 = F_3 ( V_129 ) ;
F_46 ( & V_30 ) ;
V_93 = V_120 ;
V_39 = F_47 ( & V_45 -> V_68 , V_45 -> V_34 , & V_93 , & V_30 , & V_45 -> V_34 ) ;
if ( V_39 ) {
F_82 ( V_45 -> V_35 , V_129 ) ;
return V_39 ;
}
V_45 -> time ++ ;
V_39 = F_70 ( V_45 , V_120 , 1 , & V_90 ) ;
if ( V_39 )
goto V_52;
V_39 = F_80 ( V_45 , V_90 , V_128 , V_45 -> time ) ;
if ( V_39 )
goto V_52;
F_74 ( V_90 ) ;
return 0 ;
V_52:
F_74 ( V_90 ) ;
F_76 ( & V_45 -> V_68 , V_45 -> V_34 , & V_93 , & V_45 -> V_34 ) ;
F_76 ( & V_45 -> V_70 , V_45 -> V_74 ,
& V_93 , & V_45 -> V_74 ) ;
return V_39 ;
}
int F_83 ( struct V_44 * V_45 ,
T_8 V_120 ,
T_8 V_128 )
{
int V_39 ;
F_78 ( & V_45 -> V_72 ) ;
V_39 = F_81 ( V_45 , V_120 , V_128 ) ;
F_79 ( & V_45 -> V_72 ) ;
return V_39 ;
}
static int F_84 ( struct V_44 * V_45 , T_8 V_120 )
{
int V_39 ;
T_2 V_93 = V_120 ;
struct V_89 * V_90 ;
V_39 = F_70 ( V_45 , V_120 , 0 , & V_90 ) ;
if ( V_39 )
return V_39 ;
if ( V_90 -> V_100 > 1 ) {
F_74 ( V_90 ) ;
return - V_119 ;
}
F_48 ( & V_90 -> V_101 ) ;
F_49 ( V_90 ) ;
V_39 = F_76 ( & V_45 -> V_70 , V_45 -> V_74 ,
& V_93 , & V_45 -> V_74 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_76 ( & V_45 -> V_68 , V_45 -> V_34 , & V_93 , & V_45 -> V_34 ) ;
if ( V_39 )
return V_39 ;
V_45 -> V_73 = 1 ;
return 0 ;
}
int F_85 ( struct V_44 * V_45 ,
T_8 V_120 )
{
int V_39 ;
F_78 ( & V_45 -> V_72 ) ;
V_39 = F_84 ( V_45 , V_120 ) ;
F_79 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_86 ( struct V_44 * V_45 ,
T_2 V_131 ,
T_2 V_132 )
{
F_78 ( & V_45 -> V_72 ) ;
if ( V_45 -> V_75 != V_131 ) {
F_79 ( & V_45 -> V_72 ) ;
F_9 ( L_22 ) ;
return - V_83 ;
}
V_45 -> V_75 = V_132 ;
V_45 -> V_73 = 1 ;
F_79 ( & V_45 -> V_72 ) ;
return 0 ;
}
int F_87 ( struct V_44 * V_45 ,
T_2 * V_38 )
{
F_68 ( & V_45 -> V_72 ) ;
* V_38 = V_45 -> V_75 ;
F_69 ( & V_45 -> V_72 ) ;
return 0 ;
}
static int F_88 ( struct V_44 * V_45 ,
T_3 * V_38 )
{
int V_39 ;
struct V_6 * V_7 ;
struct V_3 * V_50 ;
V_39 = F_55 ( V_45 -> V_37 , V_43 ,
& V_51 , & V_50 ) ;
if ( V_39 )
return V_39 ;
V_7 = F_2 ( V_50 ) ;
* V_38 = F_8 ( V_7 -> V_133 ) ;
return F_26 ( V_50 ) ;
}
int F_89 ( struct V_44 * V_45 ,
T_3 * V_38 )
{
int V_39 ;
F_68 ( & V_45 -> V_72 ) ;
V_39 = F_88 ( V_45 , V_38 ) ;
F_69 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_90 ( struct V_44 * V_45 , T_8 V_120 ,
struct V_89 * * V_90 )
{
int V_39 ;
F_78 ( & V_45 -> V_72 ) ;
V_39 = F_70 ( V_45 , V_120 , 0 , V_90 ) ;
F_79 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_91 ( struct V_89 * V_90 )
{
F_78 ( & V_90 -> V_45 -> V_72 ) ;
F_74 ( V_90 ) ;
F_79 ( & V_90 -> V_45 -> V_72 ) ;
return 0 ;
}
T_8 F_92 ( struct V_89 * V_90 )
{
return V_90 -> V_95 ;
}
static int F_93 ( struct V_89 * V_90 , T_4 time )
{
return V_90 -> V_99 > time ;
}
int F_94 ( struct V_89 * V_90 , T_3 V_134 ,
int V_135 , struct V_136 * V_38 )
{
int V_39 ;
T_2 V_137 = 0 ;
T_5 V_30 ;
struct V_44 * V_45 = V_90 -> V_45 ;
T_3 V_138 [ 2 ] = { V_90 -> V_95 , V_134 } ;
if ( V_135 ) {
F_68 ( & V_45 -> V_72 ) ;
V_39 = F_72 ( & V_45 -> V_32 , V_45 -> V_34 , V_138 , & V_30 ) ;
if ( ! V_39 )
V_137 = F_8 ( V_30 ) ;
F_69 ( & V_45 -> V_72 ) ;
} else if ( F_95 ( & V_45 -> V_72 ) ) {
V_39 = F_72 ( & V_45 -> V_67 , V_45 -> V_34 , V_138 , & V_30 ) ;
if ( ! V_39 )
V_137 = F_8 ( V_30 ) ;
F_69 ( & V_45 -> V_72 ) ;
} else
return - V_139 ;
if ( ! V_39 ) {
T_3 V_140 ;
T_4 V_141 ;
F_12 ( V_137 , & V_140 ,
& V_141 ) ;
V_38 -> V_134 = V_140 ;
V_38 -> V_142 = F_93 ( V_90 , V_141 ) ;
}
return V_39 ;
}
static int F_96 ( struct V_89 * V_90 , T_3 V_134 ,
T_3 V_143 )
{
int V_39 , V_144 ;
T_5 V_30 ;
struct V_44 * V_45 = V_90 -> V_45 ;
T_3 V_138 [ 2 ] = { V_90 -> V_95 , V_134 } ;
V_45 -> V_73 = 1 ;
V_30 = F_3 ( F_11 ( V_143 , V_45 -> time ) ) ;
F_46 ( & V_30 ) ;
V_39 = F_97 ( & V_45 -> V_32 , V_45 -> V_34 , V_138 , & V_30 ,
& V_45 -> V_34 , & V_144 ) ;
if ( V_39 )
return V_39 ;
if ( V_144 ) {
V_90 -> V_96 ++ ;
V_90 -> V_94 = 1 ;
}
return 0 ;
}
int F_98 ( struct V_89 * V_90 , T_3 V_134 ,
T_3 V_143 )
{
int V_39 ;
F_78 ( & V_90 -> V_45 -> V_72 ) ;
V_39 = F_96 ( V_90 , V_134 , V_143 ) ;
F_79 ( & V_90 -> V_45 -> V_72 ) ;
return V_39 ;
}
static int F_99 ( struct V_89 * V_90 , T_3 V_134 )
{
int V_39 ;
struct V_44 * V_45 = V_90 -> V_45 ;
T_3 V_138 [ 2 ] = { V_90 -> V_95 , V_134 } ;
V_39 = F_76 ( & V_45 -> V_32 , V_45 -> V_34 , V_138 , & V_45 -> V_34 ) ;
if ( V_39 )
return V_39 ;
V_45 -> V_73 = 1 ;
return 0 ;
}
int F_100 ( struct V_89 * V_90 , T_3 V_134 )
{
int V_39 ;
F_78 ( & V_90 -> V_45 -> V_72 ) ;
V_39 = F_99 ( V_90 , V_134 ) ;
F_79 ( & V_90 -> V_45 -> V_72 ) ;
return V_39 ;
}
int F_101 ( struct V_44 * V_45 , T_3 * V_38 )
{
int V_39 ;
F_78 ( & V_45 -> V_72 ) ;
V_39 = F_102 ( V_45 -> V_48 , V_38 ) ;
V_45 -> V_73 = 1 ;
F_79 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_65 ( struct V_44 * V_45 )
{
int V_39 ;
F_78 ( & V_45 -> V_72 ) ;
V_39 = F_50 ( V_45 ) ;
if ( V_39 <= 0 )
goto V_84;
V_39 = F_41 ( V_45 ) ;
V_84:
F_79 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_103 ( struct V_44 * V_45 , T_3 * V_38 )
{
int V_39 ;
F_68 ( & V_45 -> V_72 ) ;
V_39 = F_104 ( V_45 -> V_48 , V_38 ) ;
F_69 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_105 ( struct V_44 * V_45 ,
T_3 * V_38 )
{
int V_39 ;
F_68 ( & V_45 -> V_72 ) ;
V_39 = F_104 ( V_45 -> V_58 , V_38 ) ;
F_69 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_106 ( struct V_44 * V_45 ,
T_3 * V_38 )
{
int V_39 ;
F_68 ( & V_45 -> V_72 ) ;
V_39 = F_107 ( V_45 -> V_58 , V_38 ) ;
F_69 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_108 ( struct V_44 * V_45 , T_7 * V_38 )
{
F_68 ( & V_45 -> V_72 ) ;
* V_38 = V_45 -> V_80 ;
F_69 ( & V_45 -> V_72 ) ;
return 0 ;
}
int F_109 ( struct V_44 * V_45 , T_3 * V_38 )
{
int V_39 ;
F_68 ( & V_45 -> V_72 ) ;
V_39 = F_107 ( V_45 -> V_48 , V_38 ) ;
F_69 ( & V_45 -> V_72 ) ;
return V_39 ;
}
int F_110 ( struct V_89 * V_90 , T_3 * V_38 )
{
struct V_44 * V_45 = V_90 -> V_45 ;
F_68 ( & V_45 -> V_72 ) ;
* V_38 = V_90 -> V_96 ;
F_69 ( & V_45 -> V_72 ) ;
return 0 ;
}
static int F_111 ( struct V_89 * V_90 , T_3 * V_38 )
{
int V_39 ;
T_5 V_20 ;
T_3 V_145 ;
struct V_44 * V_45 = V_90 -> V_45 ;
V_39 = F_72 ( & V_45 -> V_68 , V_45 -> V_34 , & V_90 -> V_95 , & V_20 ) ;
if ( V_39 )
return V_39 ;
V_145 = F_8 ( V_20 ) ;
return F_112 ( & V_45 -> V_69 , V_145 , V_38 ) ;
}
int F_113 ( struct V_89 * V_90 ,
T_3 * V_38 )
{
int V_39 ;
struct V_44 * V_45 = V_90 -> V_45 ;
F_68 ( & V_45 -> V_72 ) ;
V_39 = F_111 ( V_90 , V_38 ) ;
F_69 ( & V_45 -> V_72 ) ;
return V_39 ;
}
static int F_114 ( struct V_44 * V_45 , T_3 V_146 )
{
int V_39 ;
T_3 V_147 ;
V_39 = F_107 ( V_45 -> V_48 , & V_147 ) ;
if ( V_39 )
return V_39 ;
if ( V_146 == V_147 )
return 0 ;
if ( V_146 < V_147 ) {
F_9 ( L_23 ) ;
return - V_83 ;
}
V_39 = F_115 ( V_45 -> V_48 , V_146 - V_147 ) ;
if ( ! V_39 )
V_45 -> V_73 = 1 ;
return V_39 ;
}
int F_116 ( struct V_44 * V_45 , T_3 V_146 )
{
int V_39 ;
F_78 ( & V_45 -> V_72 ) ;
V_39 = F_114 ( V_45 , V_146 ) ;
F_79 ( & V_45 -> V_72 ) ;
return V_39 ;
}
