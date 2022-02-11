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
static int F_23 ( struct V_36 * V_37 ,
struct V_3 * * V_38 )
{
return F_24 ( V_37 -> V_39 , V_40 ,
& V_41 , V_38 ) ;
}
static int F_25 ( struct V_36 * V_37 ,
struct V_3 * * V_38 )
{
return F_26 ( V_37 -> V_39 , V_40 ,
& V_41 , V_38 ) ;
}
static int F_27 ( struct V_42 * V_39 , int * V_43 )
{
int V_44 ;
unsigned V_45 ;
struct V_3 * V_4 ;
T_5 * V_46 , V_47 = F_3 ( 0 ) ;
unsigned V_5 = F_28 ( V_39 ) / sizeof( T_5 ) ;
V_44 = F_29 ( V_39 , V_40 , NULL , & V_4 ) ;
if ( V_44 )
return V_44 ;
V_46 = F_2 ( V_4 ) ;
* V_43 = 1 ;
for ( V_45 = 0 ; V_45 < V_5 ; V_45 ++ ) {
if ( V_46 [ V_45 ] != V_47 ) {
* V_43 = 0 ;
break;
}
}
return F_30 ( V_4 ) ;
}
static void F_31 ( struct V_36 * V_37 )
{
V_37 -> V_32 . V_35 = V_37 -> V_35 ;
V_37 -> V_32 . V_48 = 2 ;
V_37 -> V_32 . V_49 . V_19 = V_37 -> V_50 ;
V_37 -> V_32 . V_49 . V_51 = sizeof( T_5 ) ;
V_37 -> V_32 . V_49 . V_52 = F_13 ;
V_37 -> V_32 . V_49 . V_53 = F_15 ;
V_37 -> V_32 . V_49 . V_54 = F_17 ;
memcpy ( & V_37 -> V_55 , & V_37 -> V_32 , sizeof( V_37 -> V_55 ) ) ;
V_37 -> V_55 . V_35 = V_37 -> V_56 ;
V_37 -> V_57 . V_35 = V_37 -> V_35 ;
V_37 -> V_57 . V_48 = 1 ;
V_37 -> V_57 . V_49 . V_19 = & V_37 -> V_32 ;
V_37 -> V_57 . V_49 . V_51 = sizeof( T_5 ) ;
V_37 -> V_57 . V_49 . V_52 = F_18 ;
V_37 -> V_57 . V_49 . V_53 = F_20 ;
V_37 -> V_57 . V_49 . V_54 = F_22 ;
V_37 -> V_58 . V_35 = V_37 -> V_35 ;
V_37 -> V_58 . V_48 = 1 ;
V_37 -> V_58 . V_49 . V_19 = V_37 -> V_50 ;
V_37 -> V_58 . V_49 . V_51 = sizeof( T_5 ) ;
V_37 -> V_58 . V_49 . V_52 = F_13 ;
V_37 -> V_58 . V_49 . V_53 = F_15 ;
V_37 -> V_58 . V_49 . V_54 = F_17 ;
V_37 -> V_59 . V_35 = V_37 -> V_35 ;
V_37 -> V_59 . V_48 = 1 ;
V_37 -> V_59 . V_49 . V_19 = NULL ;
V_37 -> V_59 . V_49 . V_51 = sizeof( struct V_60 ) ;
V_37 -> V_59 . V_49 . V_52 = NULL ;
V_37 -> V_59 . V_49 . V_53 = NULL ;
V_37 -> V_59 . V_49 . V_54 = NULL ;
}
static int F_32 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_3 * V_38 ;
T_1 V_61 , V_62 ;
struct V_6 * V_7 ;
T_6 V_63 = F_33 ( V_37 -> V_64 -> V_65 ) >> V_66 ;
if ( V_63 > V_67 )
V_63 = V_67 ;
V_44 = F_34 ( V_37 -> V_68 , & V_61 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_34 ( V_37 -> V_50 , & V_62 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_35 ( V_37 -> V_50 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_36 ( V_37 -> V_35 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_23 ( V_37 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_38 ) ;
V_7 -> V_10 = 0 ;
memset ( V_7 -> V_69 , 0 , sizeof( V_7 -> V_69 ) ) ;
V_7 -> V_15 = F_3 ( V_16 ) ;
V_7 -> V_70 = F_5 ( V_71 ) ;
V_7 -> time = 0 ;
V_7 -> V_72 = 0 ;
V_7 -> V_73 = 0 ;
V_44 = F_37 ( V_37 -> V_68 , & V_7 -> V_74 ,
V_61 ) ;
if ( V_44 < 0 )
goto V_75;
V_44 = F_37 ( V_37 -> V_50 , & V_7 -> V_76 ,
V_62 ) ;
if ( V_44 < 0 )
goto V_75;
V_7 -> V_77 = F_3 ( V_37 -> V_34 ) ;
V_7 -> V_78 = F_3 ( V_37 -> V_79 ) ;
V_7 -> V_80 = F_5 ( V_81 >> V_66 ) ;
V_7 -> V_82 = F_3 ( V_63 >> V_83 ) ;
V_7 -> V_84 = F_5 ( V_37 -> V_84 ) ;
return F_38 ( V_37 -> V_35 , V_38 ) ;
V_75:
F_30 ( V_38 ) ;
return V_44 ;
}
static int F_39 ( struct V_36 * V_37 )
{
int V_44 ;
V_44 = F_40 ( V_37 -> V_39 , V_40 ,
& V_37 -> V_35 , & V_37 -> V_68 ) ;
if ( V_44 < 0 ) {
F_9 ( L_6 ) ;
return V_44 ;
}
V_37 -> V_50 = F_41 ( V_37 -> V_35 , 0 ) ;
if ( F_42 ( V_37 -> V_50 ) ) {
F_9 ( L_7 ) ;
V_44 = F_43 ( V_37 -> V_50 ) ;
goto V_85;
}
V_37 -> V_56 = F_44 ( V_37 -> V_35 ) ;
if ( ! V_37 -> V_56 ) {
F_9 ( L_8 ) ;
V_44 = - V_86 ;
goto V_87;
}
F_31 ( V_37 ) ;
V_44 = F_45 ( & V_37 -> V_32 , & V_37 -> V_34 ) ;
if ( V_44 < 0 )
goto V_88;
V_44 = F_45 ( & V_37 -> V_59 , & V_37 -> V_79 ) ;
if ( V_44 < 0 ) {
F_9 ( L_9 ) ;
goto V_88;
}
V_44 = F_32 ( V_37 ) ;
if ( V_44 )
goto V_88;
return 0 ;
V_88:
F_46 ( V_37 -> V_56 ) ;
V_87:
F_47 ( V_37 -> V_50 ) ;
V_85:
F_46 ( V_37 -> V_35 ) ;
F_47 ( V_37 -> V_68 ) ;
return V_44 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_36 * V_37 )
{
T_4 V_89 ;
V_89 = F_10 ( V_7 -> V_90 ) & ~ V_91 ;
if ( V_89 ) {
F_9 ( L_10 ,
( unsigned long ) V_89 ) ;
return - V_92 ;
}
if ( F_49 ( V_37 -> V_64 -> V_93 ) )
return 0 ;
V_89 = F_10 ( V_7 -> V_94 ) & ~ V_95 ;
if ( V_89 ) {
F_9 ( L_11 ,
( unsigned long ) V_89 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_50 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_3 * V_38 ;
struct V_6 * V_7 ;
V_44 = F_29 ( V_37 -> V_39 , V_40 ,
& V_41 , & V_38 ) ;
if ( V_44 < 0 ) {
F_9 ( L_12 ) ;
return V_44 ;
}
V_7 = F_2 ( V_38 ) ;
V_44 = F_48 ( V_7 , V_37 ) ;
if ( V_44 < 0 )
goto V_96;
V_44 = F_51 ( V_37 -> V_39 , V_40 ,
V_7 -> V_74 ,
sizeof( V_7 -> V_74 ) ,
& V_37 -> V_35 , & V_37 -> V_68 ) ;
if ( V_44 < 0 ) {
F_9 ( L_13 ) ;
goto V_96;
}
V_37 -> V_50 = F_52 ( V_37 -> V_35 , V_7 -> V_76 ,
sizeof( V_7 -> V_76 ) ) ;
if ( F_42 ( V_37 -> V_50 ) ) {
F_9 ( L_14 ) ;
V_44 = F_43 ( V_37 -> V_50 ) ;
goto V_85;
}
V_37 -> V_56 = F_44 ( V_37 -> V_35 ) ;
if ( ! V_37 -> V_56 ) {
F_9 ( L_8 ) ;
V_44 = - V_86 ;
goto V_87;
}
F_31 ( V_37 ) ;
return F_30 ( V_38 ) ;
V_87:
F_47 ( V_37 -> V_50 ) ;
V_85:
F_46 ( V_37 -> V_35 ) ;
F_47 ( V_37 -> V_68 ) ;
V_96:
F_30 ( V_38 ) ;
return V_44 ;
}
static int F_53 ( struct V_36 * V_37 , bool V_97 )
{
int V_44 , V_98 ;
V_44 = F_27 ( V_37 -> V_39 , & V_98 ) ;
if ( V_44 )
return V_44 ;
if ( V_98 )
return V_97 ? F_39 ( V_37 ) : - V_99 ;
return F_50 ( V_37 ) ;
}
static int F_54 ( struct V_36 * V_37 , bool V_97 )
{
int V_44 ;
V_37 -> V_39 = F_55 ( V_37 -> V_64 , V_81 ,
V_100 ,
V_101 ) ;
if ( F_42 ( V_37 -> V_39 ) ) {
F_9 ( L_15 ) ;
return F_43 ( V_37 -> V_39 ) ;
}
V_44 = F_53 ( V_37 , V_97 ) ;
if ( V_44 )
F_56 ( V_37 -> V_39 ) ;
return V_44 ;
}
static void F_57 ( struct V_36 * V_37 )
{
F_47 ( V_37 -> V_50 ) ;
F_47 ( V_37 -> V_68 ) ;
F_46 ( V_37 -> V_56 ) ;
F_46 ( V_37 -> V_35 ) ;
F_56 ( V_37 -> V_39 ) ;
}
static int F_58 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_38 ;
V_44 = F_29 ( V_37 -> V_39 , V_40 ,
& V_41 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_38 ) ;
V_37 -> time = F_10 ( V_7 -> time ) ;
V_37 -> V_34 = F_8 ( V_7 -> V_77 ) ;
V_37 -> V_79 = F_8 ( V_7 -> V_78 ) ;
V_37 -> V_72 = F_8 ( V_7 -> V_72 ) ;
V_37 -> V_10 = F_10 ( V_7 -> V_10 ) ;
V_37 -> V_84 = F_10 ( V_7 -> V_84 ) ;
F_30 ( V_38 ) ;
return 0 ;
}
static int F_59 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_102 * V_103 , * V_104 ;
struct V_60 V_105 ;
T_2 V_106 ;
F_60 (td, tmp, &pmd->thin_devices, list) {
if ( ! V_103 -> V_107 )
continue;
V_106 = V_103 -> V_108 ;
V_105 . V_109 = F_3 ( V_103 -> V_109 ) ;
V_105 . V_110 = F_3 ( V_103 -> V_110 ) ;
V_105 . V_111 = F_5 ( V_103 -> V_111 ) ;
V_105 . V_112 = F_5 ( V_103 -> V_112 ) ;
F_61 ( & V_105 ) ;
V_44 = F_62 ( & V_37 -> V_59 , V_37 -> V_79 ,
& V_106 , & V_105 , & V_37 -> V_79 ) ;
if ( V_44 )
return V_44 ;
if ( V_103 -> V_113 )
V_103 -> V_107 = 0 ;
else {
F_63 ( & V_103 -> V_114 ) ;
F_64 ( V_103 ) ;
}
}
return 0 ;
}
static int F_65 ( struct V_36 * V_37 )
{
int V_44 ;
T_1 V_61 , V_62 ;
struct V_6 * V_7 ;
struct V_3 * V_38 ;
F_66 ( sizeof( struct V_6 ) > 512 ) ;
V_44 = F_59 ( V_37 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_35 ( V_37 -> V_50 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_36 ( V_37 -> V_35 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_34 ( V_37 -> V_68 , & V_61 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_34 ( V_37 -> V_50 , & V_62 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_25 ( V_37 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_38 ) ;
V_7 -> time = F_5 ( V_37 -> time ) ;
V_7 -> V_77 = F_3 ( V_37 -> V_34 ) ;
V_7 -> V_78 = F_3 ( V_37 -> V_79 ) ;
V_7 -> V_72 = F_3 ( V_37 -> V_72 ) ;
V_7 -> V_10 = F_5 ( V_37 -> V_10 ) ;
V_44 = F_37 ( V_37 -> V_68 , & V_7 -> V_74 ,
V_61 ) ;
if ( V_44 < 0 )
goto V_115;
V_44 = F_37 ( V_37 -> V_50 , & V_7 -> V_76 ,
V_62 ) ;
if ( V_44 < 0 )
goto V_115;
return F_38 ( V_37 -> V_35 , V_38 ) ;
V_115:
F_30 ( V_38 ) ;
return V_44 ;
}
struct V_36 * F_67 ( struct V_116 * V_64 ,
T_6 V_84 ,
bool V_97 )
{
int V_44 ;
struct V_36 * V_37 ;
V_37 = F_68 ( sizeof( * V_37 ) , V_117 ) ;
if ( ! V_37 ) {
F_9 ( L_16 ) ;
return F_69 ( - V_86 ) ;
}
F_70 ( & V_37 -> V_118 ) ;
V_37 -> time = 0 ;
F_71 ( & V_37 -> V_119 ) ;
V_37 -> V_120 = false ;
V_37 -> V_121 = false ;
V_37 -> V_64 = V_64 ;
V_37 -> V_84 = V_84 ;
V_44 = F_54 ( V_37 , V_97 ) ;
if ( V_44 ) {
F_64 ( V_37 ) ;
return F_69 ( V_44 ) ;
}
V_44 = F_58 ( V_37 ) ;
if ( V_44 < 0 ) {
if ( F_72 ( V_37 ) < 0 )
F_73 ( L_17 , V_122 ) ;
return F_69 ( V_44 ) ;
}
return V_37 ;
}
int F_72 ( struct V_36 * V_37 )
{
int V_44 ;
unsigned V_123 = 0 ;
struct V_102 * V_103 , * V_104 ;
F_74 ( & V_37 -> V_118 ) ;
F_60 (td, tmp, &pmd->thin_devices, list) {
if ( V_103 -> V_113 )
V_123 ++ ;
else {
F_63 ( & V_103 -> V_114 ) ;
F_64 ( V_103 ) ;
}
}
F_75 ( & V_37 -> V_118 ) ;
if ( V_123 ) {
F_9 ( L_18 ,
V_123 ) ;
return - V_124 ;
}
if ( ! V_37 -> V_120 && ! V_37 -> V_121 ) {
V_44 = F_65 ( V_37 ) ;
if ( V_44 < 0 )
F_73 ( L_19 ,
V_122 , V_44 ) ;
}
if ( ! V_37 -> V_121 )
F_57 ( V_37 ) ;
F_64 ( V_37 ) ;
return 0 ;
}
static int F_76 ( struct V_36 * V_37 ,
T_7 V_125 , int V_126 ,
struct V_102 * * V_103 )
{
int V_44 , V_107 = 0 ;
struct V_102 * V_127 ;
T_2 V_106 = V_125 ;
struct V_60 V_128 ;
F_77 (td2, &pmd->thin_devices, list)
if ( V_127 -> V_108 == V_125 ) {
if ( V_126 )
return - V_129 ;
V_127 -> V_113 ++ ;
* V_103 = V_127 ;
return 0 ;
}
V_44 = F_78 ( & V_37 -> V_59 , V_37 -> V_79 ,
& V_106 , & V_128 ) ;
if ( V_44 ) {
if ( V_44 != - V_130 || ! V_126 )
return V_44 ;
V_107 = 1 ;
V_128 . V_109 = 0 ;
V_128 . V_110 = F_3 ( V_37 -> V_72 ) ;
V_128 . V_111 = F_5 ( V_37 -> time ) ;
V_128 . V_112 = F_5 ( V_37 -> time ) ;
}
* V_103 = F_68 ( sizeof( * * V_103 ) , V_131 ) ;
if ( ! * V_103 )
return - V_86 ;
( * V_103 ) -> V_37 = V_37 ;
( * V_103 ) -> V_108 = V_125 ;
( * V_103 ) -> V_113 = 1 ;
( * V_103 ) -> V_107 = V_107 ;
( * V_103 ) -> V_132 = false ;
( * V_103 ) -> V_109 = F_8 ( V_128 . V_109 ) ;
( * V_103 ) -> V_110 = F_8 ( V_128 . V_110 ) ;
( * V_103 ) -> V_111 = F_10 ( V_128 . V_111 ) ;
( * V_103 ) -> V_112 = F_10 ( V_128 . V_112 ) ;
F_79 ( & ( * V_103 ) -> V_114 , & V_37 -> V_119 ) ;
return 0 ;
}
static void F_80 ( struct V_102 * V_103 )
{
-- V_103 -> V_113 ;
}
static int F_81 ( struct V_36 * V_37 ,
T_7 V_125 )
{
int V_44 ;
T_3 V_133 ;
T_2 V_106 = V_125 ;
struct V_60 V_128 ;
struct V_102 * V_103 ;
T_5 V_30 ;
V_44 = F_78 ( & V_37 -> V_59 , V_37 -> V_79 ,
& V_106 , & V_128 ) ;
if ( ! V_44 )
return - V_129 ;
V_44 = F_45 ( & V_37 -> V_58 , & V_133 ) ;
if ( V_44 )
return V_44 ;
V_30 = F_3 ( V_133 ) ;
F_61 ( & V_30 ) ;
V_44 = F_62 ( & V_37 -> V_57 , V_37 -> V_34 , & V_106 , & V_30 , & V_37 -> V_34 ) ;
if ( V_44 ) {
F_21 ( & V_37 -> V_58 , V_133 ) ;
return V_44 ;
}
V_44 = F_76 ( V_37 , V_125 , 1 , & V_103 ) ;
if ( V_44 ) {
F_82 ( & V_37 -> V_57 , V_37 -> V_34 , & V_106 , & V_37 -> V_34 ) ;
F_21 ( & V_37 -> V_58 , V_133 ) ;
return V_44 ;
}
F_80 ( V_103 ) ;
return V_44 ;
}
int F_83 ( struct V_36 * V_37 , T_7 V_125 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_81 ( V_37 , V_125 ) ;
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_86 ( struct V_36 * V_37 ,
struct V_102 * V_134 ,
T_7 V_135 , T_4 time )
{
int V_44 ;
struct V_102 * V_103 ;
V_44 = F_76 ( V_37 , V_135 , 0 , & V_103 ) ;
if ( V_44 )
return V_44 ;
V_103 -> V_107 = 1 ;
V_103 -> V_112 = time ;
V_134 -> V_109 = V_103 -> V_109 ;
V_134 -> V_112 = time ;
F_80 ( V_103 ) ;
return 0 ;
}
static int F_87 ( struct V_36 * V_37 ,
T_7 V_125 , T_7 V_135 )
{
int V_44 ;
T_3 V_136 ;
T_2 V_106 = V_135 , V_137 = V_125 ;
struct V_102 * V_103 ;
struct V_60 V_128 ;
T_5 V_30 ;
V_44 = F_78 ( & V_37 -> V_59 , V_37 -> V_79 ,
& V_137 , & V_128 ) ;
if ( ! V_44 )
return - V_129 ;
V_44 = F_78 ( & V_37 -> V_57 , V_37 -> V_34 , & V_106 , & V_30 ) ;
if ( V_44 )
return V_44 ;
V_136 = F_8 ( V_30 ) ;
F_19 ( V_37 -> V_35 , V_136 ) ;
V_30 = F_3 ( V_136 ) ;
F_61 ( & V_30 ) ;
V_106 = V_125 ;
V_44 = F_62 ( & V_37 -> V_57 , V_37 -> V_34 , & V_106 , & V_30 , & V_37 -> V_34 ) ;
if ( V_44 ) {
F_88 ( V_37 -> V_35 , V_136 ) ;
return V_44 ;
}
V_37 -> time ++ ;
V_44 = F_76 ( V_37 , V_125 , 1 , & V_103 ) ;
if ( V_44 )
goto V_138;
V_44 = F_86 ( V_37 , V_103 , V_135 , V_37 -> time ) ;
F_80 ( V_103 ) ;
if ( V_44 )
goto V_138;
return 0 ;
V_138:
F_82 ( & V_37 -> V_57 , V_37 -> V_34 , & V_106 , & V_37 -> V_34 ) ;
F_82 ( & V_37 -> V_59 , V_37 -> V_79 ,
& V_106 , & V_37 -> V_79 ) ;
return V_44 ;
}
int F_89 ( struct V_36 * V_37 ,
T_7 V_125 ,
T_7 V_135 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_87 ( V_37 , V_125 , V_135 ) ;
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_90 ( struct V_36 * V_37 , T_7 V_125 )
{
int V_44 ;
T_2 V_106 = V_125 ;
struct V_102 * V_103 ;
V_44 = F_76 ( V_37 , V_125 , 0 , & V_103 ) ;
if ( V_44 )
return V_44 ;
if ( V_103 -> V_113 > 1 ) {
F_80 ( V_103 ) ;
return - V_124 ;
}
F_63 ( & V_103 -> V_114 ) ;
F_64 ( V_103 ) ;
V_44 = F_82 ( & V_37 -> V_59 , V_37 -> V_79 ,
& V_106 , & V_37 -> V_79 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_82 ( & V_37 -> V_57 , V_37 -> V_34 , & V_106 , & V_37 -> V_34 ) ;
if ( V_44 )
return V_44 ;
return 0 ;
}
int F_91 ( struct V_36 * V_37 ,
T_7 V_125 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_90 ( V_37 , V_125 ) ;
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_92 ( struct V_36 * V_37 ,
T_2 V_139 ,
T_2 V_140 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( V_37 -> V_121 )
goto V_141;
if ( V_37 -> V_72 != V_139 ) {
F_9 ( L_20 ) ;
goto V_141;
}
V_37 -> V_72 = V_140 ;
V_44 = 0 ;
V_141:
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_93 ( struct V_36 * V_37 ,
T_2 * V_43 )
{
int V_44 = - V_92 ;
F_74 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 ) {
* V_43 = V_37 -> V_72 ;
V_44 = 0 ;
}
F_75 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_94 ( struct V_36 * V_37 )
{
int V_44 , V_52 ;
struct V_6 * V_7 ;
struct V_3 * V_142 , * V_38 ;
T_3 V_73 ;
F_14 ( V_37 -> V_68 , V_40 ) ;
V_44 = F_95 ( V_37 -> V_35 , V_40 ,
& V_41 , & V_142 , & V_52 ) ;
if ( V_44 )
return V_44 ;
F_96 ( ! V_52 ) ;
V_73 = F_4 ( V_142 ) ;
V_7 = F_2 ( V_142 ) ;
if ( F_8 ( V_7 -> V_73 ) ) {
F_73 ( L_21 ) ;
F_88 ( V_37 -> V_35 , V_73 ) ;
F_97 ( V_37 -> V_35 , V_142 ) ;
return - V_124 ;
}
memset ( & V_7 -> V_76 , 0 ,
sizeof( V_7 -> V_76 ) ) ;
memset ( & V_7 -> V_74 , 0 ,
sizeof( V_7 -> V_74 ) ) ;
F_19 ( V_37 -> V_35 , F_8 ( V_7 -> V_77 ) ) ;
F_19 ( V_37 -> V_35 , F_8 ( V_7 -> V_78 ) ) ;
F_97 ( V_37 -> V_35 , V_142 ) ;
V_44 = F_25 ( V_37 , & V_38 ) ;
if ( V_44 ) {
F_88 ( V_37 -> V_35 , V_73 ) ;
return V_44 ;
}
V_7 = F_2 ( V_38 ) ;
V_7 -> V_73 = F_3 ( V_73 ) ;
F_30 ( V_38 ) ;
return 0 ;
}
int F_98 ( struct V_36 * V_37 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_94 ( V_37 ) ;
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_99 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_38 , * V_142 ;
T_3 V_73 ;
V_44 = F_25 ( V_37 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_38 ) ;
V_73 = F_8 ( V_7 -> V_73 ) ;
V_7 -> V_73 = F_3 ( 0 ) ;
F_30 ( V_38 ) ;
if ( ! V_73 ) {
F_73 ( L_22 ) ;
return - V_92 ;
}
V_44 = F_100 ( V_37 -> V_35 , V_73 , & V_41 , & V_142 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_142 ) ;
F_16 ( V_37 -> V_68 , F_8 ( V_7 -> V_77 ) ) ;
F_16 ( V_37 -> V_68 , F_8 ( V_7 -> V_78 ) ) ;
F_16 ( V_37 -> V_68 , V_73 ) ;
return F_97 ( V_37 -> V_35 , V_142 ) ;
}
int F_101 ( struct V_36 * V_37 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_99 ( V_37 ) ;
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_102 ( struct V_36 * V_37 ,
T_3 * V_43 )
{
int V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_38 ;
V_44 = F_29 ( V_37 -> V_39 , V_40 ,
& V_41 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_38 ) ;
* V_43 = F_8 ( V_7 -> V_73 ) ;
return F_30 ( V_38 ) ;
}
int F_103 ( struct V_36 * V_37 ,
T_3 * V_43 )
{
int V_44 = - V_92 ;
F_74 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_102 ( V_37 , V_43 ) ;
F_75 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_104 ( struct V_36 * V_37 , T_7 V_125 ,
struct V_102 * * V_103 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_76 ( V_37 , V_125 , 0 , V_103 ) ;
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_105 ( struct V_102 * V_103 )
{
F_84 ( & V_103 -> V_37 -> V_118 ) ;
F_80 ( V_103 ) ;
F_85 ( & V_103 -> V_37 -> V_118 ) ;
return 0 ;
}
T_7 F_106 ( struct V_102 * V_103 )
{
return V_103 -> V_108 ;
}
static bool F_107 ( struct V_102 * V_103 , T_4 time )
{
return V_103 -> V_112 > time ;
}
int F_108 ( struct V_102 * V_103 , T_3 V_143 ,
int V_144 , struct V_145 * V_43 )
{
int V_44 = - V_92 ;
T_2 V_146 = 0 ;
T_5 V_30 ;
struct V_36 * V_37 = V_103 -> V_37 ;
T_3 V_147 [ 2 ] = { V_103 -> V_108 , V_143 } ;
struct V_31 * V_32 ;
if ( V_144 ) {
F_74 ( & V_37 -> V_118 ) ;
V_32 = & V_37 -> V_32 ;
} else if ( F_109 ( & V_37 -> V_118 ) )
V_32 = & V_37 -> V_55 ;
else
return - V_148 ;
if ( V_37 -> V_121 )
goto V_141;
V_44 = F_78 ( V_32 , V_37 -> V_34 , V_147 , & V_30 ) ;
if ( ! V_44 )
V_146 = F_8 ( V_30 ) ;
V_141:
F_75 ( & V_37 -> V_118 ) ;
if ( ! V_44 ) {
T_3 V_149 ;
T_4 V_150 ;
F_12 ( V_146 , & V_149 ,
& V_150 ) ;
V_43 -> V_143 = V_149 ;
V_43 -> V_151 = F_107 ( V_103 , V_150 ) ;
}
return V_44 ;
}
static int F_110 ( struct V_102 * V_103 , T_3 V_143 ,
T_3 V_152 )
{
int V_44 , V_153 ;
T_5 V_30 ;
struct V_36 * V_37 = V_103 -> V_37 ;
T_3 V_147 [ 2 ] = { V_103 -> V_108 , V_143 } ;
V_30 = F_3 ( F_11 ( V_152 , V_37 -> time ) ) ;
F_61 ( & V_30 ) ;
V_44 = F_111 ( & V_37 -> V_32 , V_37 -> V_34 , V_147 , & V_30 ,
& V_37 -> V_34 , & V_153 ) ;
if ( V_44 )
return V_44 ;
V_103 -> V_107 = 1 ;
if ( V_153 )
V_103 -> V_109 ++ ;
return 0 ;
}
int F_112 ( struct V_102 * V_103 , T_3 V_143 ,
T_3 V_152 )
{
int V_44 = - V_92 ;
F_84 ( & V_103 -> V_37 -> V_118 ) ;
if ( ! V_103 -> V_37 -> V_121 )
V_44 = F_110 ( V_103 , V_143 , V_152 ) ;
F_85 ( & V_103 -> V_37 -> V_118 ) ;
return V_44 ;
}
static int F_113 ( struct V_102 * V_103 , T_3 V_143 )
{
int V_44 ;
struct V_36 * V_37 = V_103 -> V_37 ;
T_3 V_147 [ 2 ] = { V_103 -> V_108 , V_143 } ;
V_44 = F_82 ( & V_37 -> V_32 , V_37 -> V_34 , V_147 , & V_37 -> V_34 ) ;
if ( V_44 )
return V_44 ;
V_103 -> V_109 -- ;
V_103 -> V_107 = 1 ;
return 0 ;
}
int F_114 ( struct V_102 * V_103 , T_3 V_143 )
{
int V_44 = - V_92 ;
F_84 ( & V_103 -> V_37 -> V_118 ) ;
if ( ! V_103 -> V_37 -> V_121 )
V_44 = F_113 ( V_103 , V_143 ) ;
F_85 ( & V_103 -> V_37 -> V_118 ) ;
return V_44 ;
}
bool F_115 ( struct V_102 * V_103 )
{
int V_44 ;
F_74 ( & V_103 -> V_37 -> V_118 ) ;
V_44 = V_103 -> V_107 ;
F_75 ( & V_103 -> V_37 -> V_118 ) ;
return V_44 ;
}
bool F_116 ( struct V_102 * V_103 )
{
bool V_44 ;
F_74 ( & V_103 -> V_37 -> V_118 ) ;
V_44 = V_103 -> V_132 ;
F_75 ( & V_103 -> V_37 -> V_118 ) ;
return V_44 ;
}
int F_117 ( struct V_36 * V_37 , T_3 * V_43 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_118 ( V_37 -> V_50 , V_43 ) ;
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_119 ( struct V_36 * V_37 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( V_37 -> V_121 )
goto V_141;
V_44 = F_65 ( V_37 ) ;
if ( V_44 <= 0 )
goto V_141;
V_44 = F_58 ( V_37 ) ;
V_141:
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static void F_120 ( struct V_36 * V_37 )
{
struct V_102 * V_103 ;
F_77 (td, &pmd->thin_devices, list)
V_103 -> V_132 = V_103 -> V_107 ;
}
int F_121 ( struct V_36 * V_37 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( V_37 -> V_121 )
goto V_141;
F_120 ( V_37 ) ;
F_57 ( V_37 ) ;
V_44 = F_54 ( V_37 , false ) ;
if ( V_44 )
V_37 -> V_121 = true ;
V_141:
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_122 ( struct V_36 * V_37 , T_3 * V_43 )
{
int V_44 = - V_92 ;
F_74 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_123 ( V_37 -> V_50 , V_43 ) ;
F_75 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_124 ( struct V_36 * V_37 ,
T_3 * V_43 )
{
int V_44 = - V_92 ;
F_74 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_123 ( V_37 -> V_68 , V_43 ) ;
F_75 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_125 ( struct V_36 * V_37 ,
T_3 * V_43 )
{
int V_44 = - V_92 ;
F_74 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_126 ( V_37 -> V_68 , V_43 ) ;
F_75 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_127 ( struct V_36 * V_37 , T_6 * V_43 )
{
F_74 ( & V_37 -> V_118 ) ;
* V_43 = V_37 -> V_84 ;
F_75 ( & V_37 -> V_118 ) ;
return 0 ;
}
int F_128 ( struct V_36 * V_37 , T_3 * V_43 )
{
int V_44 = - V_92 ;
F_74 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_126 ( V_37 -> V_50 , V_43 ) ;
F_75 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_129 ( struct V_102 * V_103 , T_3 * V_43 )
{
int V_44 = - V_92 ;
struct V_36 * V_37 = V_103 -> V_37 ;
F_74 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 ) {
* V_43 = V_103 -> V_109 ;
V_44 = 0 ;
}
F_75 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_130 ( struct V_102 * V_103 , T_3 * V_43 )
{
int V_44 ;
T_5 V_20 ;
T_3 V_154 ;
struct V_36 * V_37 = V_103 -> V_37 ;
V_44 = F_78 ( & V_37 -> V_57 , V_37 -> V_34 , & V_103 -> V_108 , & V_20 ) ;
if ( V_44 )
return V_44 ;
V_154 = F_8 ( V_20 ) ;
return F_131 ( & V_37 -> V_58 , V_154 , V_43 ) ;
}
int F_132 ( struct V_102 * V_103 ,
T_3 * V_43 )
{
int V_44 = - V_92 ;
struct V_36 * V_37 = V_103 -> V_37 ;
F_74 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_130 ( V_103 , V_43 ) ;
F_75 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_133 ( struct V_36 * V_37 , T_3 V_155 )
{
int V_44 ;
T_3 V_156 ;
V_44 = F_126 ( V_37 -> V_50 , & V_156 ) ;
if ( V_44 )
return V_44 ;
if ( V_155 == V_156 )
return 0 ;
if ( V_155 < V_156 ) {
F_9 ( L_23 ) ;
return - V_92 ;
}
return F_134 ( V_37 -> V_50 , V_155 - V_156 ) ;
}
int F_135 ( struct V_36 * V_37 , T_3 V_155 )
{
int V_44 = - V_92 ;
F_84 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_133 ( V_37 , V_155 ) ;
F_85 ( & V_37 -> V_118 ) ;
return V_44 ;
}
void F_136 ( struct V_36 * V_37 )
{
F_84 ( & V_37 -> V_118 ) ;
V_37 -> V_120 = true ;
F_137 ( V_37 -> V_39 ) ;
F_85 ( & V_37 -> V_118 ) ;
}
