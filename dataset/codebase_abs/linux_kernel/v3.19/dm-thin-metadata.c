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
static void F_13 ( void * V_19 , const void * V_20 )
{
struct V_21 * V_22 = V_19 ;
T_5 V_23 ;
T_2 V_4 ;
T_4 V_18 ;
memcpy ( & V_23 , V_20 , sizeof( V_23 ) ) ;
F_12 ( F_8 ( V_23 ) , & V_4 , & V_18 ) ;
F_14 ( V_22 , V_4 ) ;
}
static void F_15 ( void * V_19 , const void * V_20 )
{
struct V_21 * V_22 = V_19 ;
T_5 V_23 ;
T_2 V_4 ;
T_4 V_18 ;
memcpy ( & V_23 , V_20 , sizeof( V_23 ) ) ;
F_12 ( F_8 ( V_23 ) , & V_4 , & V_18 ) ;
F_16 ( V_22 , V_4 ) ;
}
static int F_17 ( void * V_19 , const void * V_24 , const void * V_25 )
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
static void F_18 ( void * V_19 , const void * V_30 )
{
struct V_31 * V_32 = V_19 ;
T_5 V_33 ;
T_2 V_34 ;
memcpy ( & V_33 , V_30 , sizeof( V_33 ) ) ;
V_34 = F_8 ( V_33 ) ;
F_19 ( V_32 -> V_35 , V_34 ) ;
}
static void F_20 ( void * V_19 , const void * V_30 )
{
struct V_31 * V_32 = V_19 ;
T_5 V_33 ;
T_2 V_34 ;
memcpy ( & V_33 , V_30 , sizeof( V_33 ) ) ;
V_34 = F_8 ( V_33 ) ;
if ( F_21 ( V_32 , V_34 ) )
F_9 ( L_5 ) ;
}
static int F_22 ( void * V_19 , const void * V_24 , const void * V_25 )
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
V_37 -> V_57 . V_49 . V_19 = & V_37 -> V_58 ;
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
T_1 V_61 ;
V_44 = F_33 ( V_37 -> V_62 , & V_61 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_34 ( V_37 -> V_62 , & V_37 -> V_63 , V_61 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_33 ( V_37 -> V_50 , & V_61 ) ;
if ( V_44 < 0 )
return V_44 ;
return F_34 ( V_37 -> V_50 , & V_37 -> V_64 , V_61 ) ;
}
static void F_35 ( struct V_36 * V_37 ,
struct V_6 * V_65 )
{
memcpy ( & V_65 -> V_63 ,
& V_37 -> V_63 ,
sizeof( V_37 -> V_63 ) ) ;
memcpy ( & V_65 -> V_64 ,
& V_37 -> V_64 ,
sizeof( V_37 -> V_64 ) ) ;
}
static int F_36 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_3 * V_38 ;
struct V_6 * V_7 ;
T_6 V_66 = F_37 ( V_37 -> V_67 -> V_68 ) >> V_69 ;
if ( V_66 > V_70 )
V_66 = V_70 ;
V_44 = F_38 ( V_37 -> V_50 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_32 ( V_37 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_39 ( V_37 -> V_35 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_23 ( V_37 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_38 ) ;
V_7 -> V_10 = 0 ;
memset ( V_7 -> V_71 , 0 , sizeof( V_7 -> V_71 ) ) ;
V_7 -> V_15 = F_3 ( V_16 ) ;
V_7 -> V_72 = F_5 ( V_73 ) ;
V_7 -> time = 0 ;
V_7 -> V_74 = 0 ;
V_7 -> V_75 = 0 ;
F_35 ( V_37 , V_7 ) ;
V_7 -> V_76 = F_3 ( V_37 -> V_34 ) ;
V_7 -> V_77 = F_3 ( V_37 -> V_78 ) ;
V_7 -> V_79 = F_5 ( V_80 ) ;
V_7 -> V_81 = F_3 ( V_66 >> V_82 ) ;
V_7 -> V_83 = F_5 ( V_37 -> V_83 ) ;
return F_40 ( V_37 -> V_35 , V_38 ) ;
}
static int F_41 ( struct V_36 * V_37 )
{
int V_44 ;
V_44 = F_42 ( V_37 -> V_39 , V_40 ,
& V_37 -> V_35 , & V_37 -> V_62 ) ;
if ( V_44 < 0 ) {
F_9 ( L_6 ) ;
return V_44 ;
}
V_37 -> V_50 = F_43 ( V_37 -> V_35 , 0 ) ;
if ( F_44 ( V_37 -> V_50 ) ) {
F_9 ( L_7 ) ;
V_44 = F_45 ( V_37 -> V_50 ) ;
goto V_84;
}
V_37 -> V_56 = F_46 ( V_37 -> V_35 ) ;
if ( ! V_37 -> V_56 ) {
F_9 ( L_8 ) ;
V_44 = - V_85 ;
goto V_86;
}
F_31 ( V_37 ) ;
V_44 = F_47 ( & V_37 -> V_32 , & V_37 -> V_34 ) ;
if ( V_44 < 0 )
goto V_87;
V_44 = F_47 ( & V_37 -> V_59 , & V_37 -> V_78 ) ;
if ( V_44 < 0 ) {
F_9 ( L_9 ) ;
goto V_87;
}
V_44 = F_36 ( V_37 ) ;
if ( V_44 )
goto V_87;
return 0 ;
V_87:
F_48 ( V_37 -> V_56 ) ;
V_86:
F_49 ( V_37 -> V_50 ) ;
V_84:
F_48 ( V_37 -> V_35 ) ;
F_49 ( V_37 -> V_62 ) ;
return V_44 ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_36 * V_37 )
{
T_4 V_88 ;
V_88 = F_10 ( V_7 -> V_89 ) & ~ V_90 ;
if ( V_88 ) {
F_9 ( L_10 ,
( unsigned long ) V_88 ) ;
return - V_91 ;
}
if ( F_51 ( V_37 -> V_67 -> V_92 ) )
return 0 ;
V_88 = F_10 ( V_7 -> V_93 ) & ~ V_94 ;
if ( V_88 ) {
F_9 ( L_11 ,
( unsigned long ) V_88 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_52 ( struct V_36 * V_37 )
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
if ( F_10 ( V_7 -> V_83 ) != V_37 -> V_83 ) {
F_9 ( L_13 ,
F_10 ( V_7 -> V_83 ) ,
( unsigned long long ) V_37 -> V_83 ) ;
V_44 = - V_91 ;
goto V_95;
}
V_44 = F_50 ( V_7 , V_37 ) ;
if ( V_44 < 0 )
goto V_95;
V_44 = F_53 ( V_37 -> V_39 , V_40 ,
V_7 -> V_63 ,
sizeof( V_7 -> V_63 ) ,
& V_37 -> V_35 , & V_37 -> V_62 ) ;
if ( V_44 < 0 ) {
F_9 ( L_14 ) ;
goto V_95;
}
V_37 -> V_50 = F_54 ( V_37 -> V_35 , V_7 -> V_64 ,
sizeof( V_7 -> V_64 ) ) ;
if ( F_44 ( V_37 -> V_50 ) ) {
F_9 ( L_15 ) ;
V_44 = F_45 ( V_37 -> V_50 ) ;
goto V_84;
}
V_37 -> V_56 = F_46 ( V_37 -> V_35 ) ;
if ( ! V_37 -> V_56 ) {
F_9 ( L_8 ) ;
V_44 = - V_85 ;
goto V_86;
}
F_31 ( V_37 ) ;
return F_30 ( V_38 ) ;
V_86:
F_49 ( V_37 -> V_50 ) ;
V_84:
F_48 ( V_37 -> V_35 ) ;
F_49 ( V_37 -> V_62 ) ;
V_95:
F_30 ( V_38 ) ;
return V_44 ;
}
static int F_55 ( struct V_36 * V_37 , bool V_96 )
{
int V_44 , V_97 ;
V_44 = F_27 ( V_37 -> V_39 , & V_97 ) ;
if ( V_44 )
return V_44 ;
if ( V_97 )
return V_96 ? F_41 ( V_37 ) : - V_98 ;
return F_52 ( V_37 ) ;
}
static int F_56 ( struct V_36 * V_37 , bool V_96 )
{
int V_44 ;
V_37 -> V_39 = F_57 ( V_37 -> V_67 , V_80 << V_69 ,
V_99 ,
V_100 ) ;
if ( F_44 ( V_37 -> V_39 ) ) {
F_9 ( L_16 ) ;
return F_45 ( V_37 -> V_39 ) ;
}
V_44 = F_55 ( V_37 , V_96 ) ;
if ( V_44 )
F_58 ( V_37 -> V_39 ) ;
return V_44 ;
}
static void F_59 ( struct V_36 * V_37 )
{
F_49 ( V_37 -> V_50 ) ;
F_49 ( V_37 -> V_62 ) ;
F_48 ( V_37 -> V_56 ) ;
F_48 ( V_37 -> V_35 ) ;
F_58 ( V_37 -> V_39 ) ;
}
static int F_60 ( struct V_36 * V_37 )
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
V_37 -> V_34 = F_8 ( V_7 -> V_76 ) ;
V_37 -> V_78 = F_8 ( V_7 -> V_77 ) ;
V_37 -> V_74 = F_8 ( V_7 -> V_74 ) ;
V_37 -> V_10 = F_10 ( V_7 -> V_10 ) ;
V_37 -> V_83 = F_10 ( V_7 -> V_83 ) ;
F_30 ( V_38 ) ;
return 0 ;
}
static int F_61 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_101 * V_102 , * V_103 ;
struct V_60 V_104 ;
T_2 V_105 ;
F_62 (td, tmp, &pmd->thin_devices, list) {
if ( ! V_102 -> V_106 )
continue;
V_105 = V_102 -> V_107 ;
V_104 . V_108 = F_3 ( V_102 -> V_108 ) ;
V_104 . V_109 = F_3 ( V_102 -> V_109 ) ;
V_104 . V_110 = F_5 ( V_102 -> V_110 ) ;
V_104 . V_111 = F_5 ( V_102 -> V_111 ) ;
F_63 ( & V_104 ) ;
V_44 = F_64 ( & V_37 -> V_59 , V_37 -> V_78 ,
& V_105 , & V_104 , & V_37 -> V_78 ) ;
if ( V_44 )
return V_44 ;
if ( V_102 -> V_112 )
V_102 -> V_106 = 0 ;
else {
F_65 ( & V_102 -> V_113 ) ;
F_66 ( V_102 ) ;
}
}
return 0 ;
}
static int F_67 ( struct V_36 * V_37 )
{
int V_44 ;
T_1 V_114 , V_115 ;
struct V_6 * V_7 ;
struct V_3 * V_38 ;
F_68 ( sizeof( struct V_6 ) > 512 ) ;
V_44 = F_61 ( V_37 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_38 ( V_37 -> V_50 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_39 ( V_37 -> V_35 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_33 ( V_37 -> V_62 , & V_114 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_33 ( V_37 -> V_50 , & V_115 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_32 ( V_37 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_25 ( V_37 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_38 ) ;
V_7 -> time = F_5 ( V_37 -> time ) ;
V_7 -> V_76 = F_3 ( V_37 -> V_34 ) ;
V_7 -> V_77 = F_3 ( V_37 -> V_78 ) ;
V_7 -> V_74 = F_3 ( V_37 -> V_74 ) ;
V_7 -> V_10 = F_5 ( V_37 -> V_10 ) ;
F_35 ( V_37 , V_7 ) ;
return F_40 ( V_37 -> V_35 , V_38 ) ;
}
struct V_36 * F_69 ( struct V_116 * V_67 ,
T_6 V_83 ,
bool V_96 )
{
int V_44 ;
struct V_36 * V_37 ;
V_37 = F_70 ( sizeof( * V_37 ) , V_117 ) ;
if ( ! V_37 ) {
F_9 ( L_17 ) ;
return F_71 ( - V_85 ) ;
}
F_72 ( & V_37 -> V_118 ) ;
V_37 -> time = 0 ;
F_73 ( & V_37 -> V_119 ) ;
V_37 -> V_120 = false ;
V_37 -> V_121 = false ;
V_37 -> V_67 = V_67 ;
V_37 -> V_83 = V_83 ;
V_44 = F_56 ( V_37 , V_96 ) ;
if ( V_44 ) {
F_66 ( V_37 ) ;
return F_71 ( V_44 ) ;
}
V_44 = F_60 ( V_37 ) ;
if ( V_44 < 0 ) {
if ( F_74 ( V_37 ) < 0 )
F_75 ( L_18 , V_122 ) ;
return F_71 ( V_44 ) ;
}
return V_37 ;
}
int F_74 ( struct V_36 * V_37 )
{
int V_44 ;
unsigned V_123 = 0 ;
struct V_101 * V_102 , * V_103 ;
F_76 ( & V_37 -> V_118 ) ;
F_62 (td, tmp, &pmd->thin_devices, list) {
if ( V_102 -> V_112 )
V_123 ++ ;
else {
F_65 ( & V_102 -> V_113 ) ;
F_66 ( V_102 ) ;
}
}
F_77 ( & V_37 -> V_118 ) ;
if ( V_123 ) {
F_9 ( L_19 ,
V_123 ) ;
return - V_124 ;
}
if ( ! V_37 -> V_120 && ! V_37 -> V_121 ) {
V_44 = F_67 ( V_37 ) ;
if ( V_44 < 0 )
F_75 ( L_20 ,
V_122 , V_44 ) ;
}
if ( ! V_37 -> V_121 )
F_59 ( V_37 ) ;
F_66 ( V_37 ) ;
return 0 ;
}
static int F_78 ( struct V_36 * V_37 ,
T_7 V_125 , int V_126 ,
struct V_101 * * V_102 )
{
int V_44 , V_106 = 0 ;
struct V_101 * V_127 ;
T_2 V_105 = V_125 ;
struct V_60 V_128 ;
F_79 (td2, &pmd->thin_devices, list)
if ( V_127 -> V_107 == V_125 ) {
if ( V_126 )
return - V_129 ;
V_127 -> V_112 ++ ;
* V_102 = V_127 ;
return 0 ;
}
V_44 = F_80 ( & V_37 -> V_59 , V_37 -> V_78 ,
& V_105 , & V_128 ) ;
if ( V_44 ) {
if ( V_44 != - V_130 || ! V_126 )
return V_44 ;
V_106 = 1 ;
V_128 . V_108 = 0 ;
V_128 . V_109 = F_3 ( V_37 -> V_74 ) ;
V_128 . V_110 = F_5 ( V_37 -> time ) ;
V_128 . V_111 = F_5 ( V_37 -> time ) ;
}
* V_102 = F_70 ( sizeof( * * V_102 ) , V_131 ) ;
if ( ! * V_102 )
return - V_85 ;
( * V_102 ) -> V_37 = V_37 ;
( * V_102 ) -> V_107 = V_125 ;
( * V_102 ) -> V_112 = 1 ;
( * V_102 ) -> V_106 = V_106 ;
( * V_102 ) -> V_132 = false ;
( * V_102 ) -> V_108 = F_8 ( V_128 . V_108 ) ;
( * V_102 ) -> V_109 = F_8 ( V_128 . V_109 ) ;
( * V_102 ) -> V_110 = F_10 ( V_128 . V_110 ) ;
( * V_102 ) -> V_111 = F_10 ( V_128 . V_111 ) ;
F_81 ( & ( * V_102 ) -> V_113 , & V_37 -> V_119 ) ;
return 0 ;
}
static void F_82 ( struct V_101 * V_102 )
{
-- V_102 -> V_112 ;
}
static int F_83 ( struct V_36 * V_37 ,
T_7 V_125 )
{
int V_44 ;
T_3 V_133 ;
T_2 V_105 = V_125 ;
struct V_60 V_128 ;
struct V_101 * V_102 ;
T_5 V_30 ;
V_44 = F_80 ( & V_37 -> V_59 , V_37 -> V_78 ,
& V_105 , & V_128 ) ;
if ( ! V_44 )
return - V_129 ;
V_44 = F_47 ( & V_37 -> V_58 , & V_133 ) ;
if ( V_44 )
return V_44 ;
V_30 = F_3 ( V_133 ) ;
F_63 ( & V_30 ) ;
V_44 = F_64 ( & V_37 -> V_57 , V_37 -> V_34 , & V_105 , & V_30 , & V_37 -> V_34 ) ;
if ( V_44 ) {
F_21 ( & V_37 -> V_58 , V_133 ) ;
return V_44 ;
}
V_44 = F_78 ( V_37 , V_125 , 1 , & V_102 ) ;
if ( V_44 ) {
F_84 ( & V_37 -> V_57 , V_37 -> V_34 , & V_105 , & V_37 -> V_34 ) ;
F_21 ( & V_37 -> V_58 , V_133 ) ;
return V_44 ;
}
F_82 ( V_102 ) ;
return V_44 ;
}
int F_85 ( struct V_36 * V_37 , T_7 V_125 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_83 ( V_37 , V_125 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_88 ( struct V_36 * V_37 ,
struct V_101 * V_134 ,
T_7 V_135 , T_4 time )
{
int V_44 ;
struct V_101 * V_102 ;
V_44 = F_78 ( V_37 , V_135 , 0 , & V_102 ) ;
if ( V_44 )
return V_44 ;
V_102 -> V_106 = 1 ;
V_102 -> V_111 = time ;
V_134 -> V_108 = V_102 -> V_108 ;
V_134 -> V_111 = time ;
F_82 ( V_102 ) ;
return 0 ;
}
static int F_89 ( struct V_36 * V_37 ,
T_7 V_125 , T_7 V_135 )
{
int V_44 ;
T_3 V_136 ;
T_2 V_105 = V_135 , V_137 = V_125 ;
struct V_101 * V_102 ;
struct V_60 V_128 ;
T_5 V_30 ;
V_44 = F_80 ( & V_37 -> V_59 , V_37 -> V_78 ,
& V_137 , & V_128 ) ;
if ( ! V_44 )
return - V_129 ;
V_44 = F_80 ( & V_37 -> V_57 , V_37 -> V_34 , & V_105 , & V_30 ) ;
if ( V_44 )
return V_44 ;
V_136 = F_8 ( V_30 ) ;
F_19 ( V_37 -> V_35 , V_136 ) ;
V_30 = F_3 ( V_136 ) ;
F_63 ( & V_30 ) ;
V_105 = V_125 ;
V_44 = F_64 ( & V_37 -> V_57 , V_37 -> V_34 , & V_105 , & V_30 , & V_37 -> V_34 ) ;
if ( V_44 ) {
F_90 ( V_37 -> V_35 , V_136 ) ;
return V_44 ;
}
V_37 -> time ++ ;
V_44 = F_78 ( V_37 , V_125 , 1 , & V_102 ) ;
if ( V_44 )
goto V_138;
V_44 = F_88 ( V_37 , V_102 , V_135 , V_37 -> time ) ;
F_82 ( V_102 ) ;
if ( V_44 )
goto V_138;
return 0 ;
V_138:
F_84 ( & V_37 -> V_57 , V_37 -> V_34 , & V_105 , & V_37 -> V_34 ) ;
F_84 ( & V_37 -> V_59 , V_37 -> V_78 ,
& V_105 , & V_37 -> V_78 ) ;
return V_44 ;
}
int F_91 ( struct V_36 * V_37 ,
T_7 V_125 ,
T_7 V_135 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_89 ( V_37 , V_125 , V_135 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_92 ( struct V_36 * V_37 , T_7 V_125 )
{
int V_44 ;
T_2 V_105 = V_125 ;
struct V_101 * V_102 ;
V_44 = F_78 ( V_37 , V_125 , 0 , & V_102 ) ;
if ( V_44 )
return V_44 ;
if ( V_102 -> V_112 > 1 ) {
F_82 ( V_102 ) ;
return - V_124 ;
}
F_65 ( & V_102 -> V_113 ) ;
F_66 ( V_102 ) ;
V_44 = F_84 ( & V_37 -> V_59 , V_37 -> V_78 ,
& V_105 , & V_37 -> V_78 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_84 ( & V_37 -> V_57 , V_37 -> V_34 , & V_105 , & V_37 -> V_34 ) ;
if ( V_44 )
return V_44 ;
return 0 ;
}
int F_93 ( struct V_36 * V_37 ,
T_7 V_125 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_92 ( V_37 , V_125 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_94 ( struct V_36 * V_37 ,
T_2 V_139 ,
T_2 V_140 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( V_37 -> V_121 )
goto V_141;
if ( V_37 -> V_74 != V_139 ) {
F_9 ( L_21 ) ;
goto V_141;
}
V_37 -> V_74 = V_140 ;
V_44 = 0 ;
V_141:
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_95 ( struct V_36 * V_37 ,
T_2 * V_43 )
{
int V_44 = - V_91 ;
F_76 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 ) {
* V_43 = V_37 -> V_74 ;
V_44 = 0 ;
}
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_96 ( struct V_36 * V_37 )
{
int V_44 , V_52 ;
struct V_6 * V_7 ;
struct V_3 * V_142 , * V_38 ;
T_3 V_75 ;
F_14 ( V_37 -> V_62 , V_40 ) ;
V_44 = F_97 ( V_37 -> V_35 , V_40 ,
& V_41 , & V_142 , & V_52 ) ;
if ( V_44 )
return V_44 ;
F_98 ( ! V_52 ) ;
V_75 = F_4 ( V_142 ) ;
V_7 = F_2 ( V_142 ) ;
if ( F_8 ( V_7 -> V_75 ) ) {
F_75 ( L_22 ) ;
F_90 ( V_37 -> V_35 , V_75 ) ;
F_99 ( V_37 -> V_35 , V_142 ) ;
return - V_124 ;
}
memset ( & V_7 -> V_64 , 0 ,
sizeof( V_7 -> V_64 ) ) ;
memset ( & V_7 -> V_63 , 0 ,
sizeof( V_7 -> V_63 ) ) ;
F_19 ( V_37 -> V_35 , F_8 ( V_7 -> V_76 ) ) ;
F_19 ( V_37 -> V_35 , F_8 ( V_7 -> V_77 ) ) ;
F_99 ( V_37 -> V_35 , V_142 ) ;
V_44 = F_25 ( V_37 , & V_38 ) ;
if ( V_44 ) {
F_90 ( V_37 -> V_35 , V_75 ) ;
return V_44 ;
}
V_7 = F_2 ( V_38 ) ;
V_7 -> V_75 = F_3 ( V_75 ) ;
F_30 ( V_38 ) ;
return 0 ;
}
int F_100 ( struct V_36 * V_37 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_96 ( V_37 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_101 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_38 , * V_142 ;
T_3 V_75 ;
V_44 = F_25 ( V_37 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_38 ) ;
V_75 = F_8 ( V_7 -> V_75 ) ;
V_7 -> V_75 = F_3 ( 0 ) ;
F_30 ( V_38 ) ;
if ( ! V_75 ) {
F_75 ( L_23 ) ;
return - V_91 ;
}
V_44 = F_102 ( V_37 -> V_35 , V_75 , & V_41 , & V_142 ) ;
if ( V_44 )
return V_44 ;
V_7 = F_2 ( V_142 ) ;
F_16 ( V_37 -> V_62 , F_8 ( V_7 -> V_76 ) ) ;
F_16 ( V_37 -> V_62 , F_8 ( V_7 -> V_77 ) ) ;
F_16 ( V_37 -> V_62 , V_75 ) ;
return F_99 ( V_37 -> V_35 , V_142 ) ;
}
int F_103 ( struct V_36 * V_37 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_101 ( V_37 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_104 ( struct V_36 * V_37 ,
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
* V_43 = F_8 ( V_7 -> V_75 ) ;
return F_30 ( V_38 ) ;
}
int F_105 ( struct V_36 * V_37 ,
T_3 * V_43 )
{
int V_44 = - V_91 ;
F_76 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_104 ( V_37 , V_43 ) ;
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_106 ( struct V_36 * V_37 , T_7 V_125 ,
struct V_101 * * V_102 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_78 ( V_37 , V_125 , 0 , V_102 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_107 ( struct V_101 * V_102 )
{
F_86 ( & V_102 -> V_37 -> V_118 ) ;
F_82 ( V_102 ) ;
F_87 ( & V_102 -> V_37 -> V_118 ) ;
return 0 ;
}
T_7 F_108 ( struct V_101 * V_102 )
{
return V_102 -> V_107 ;
}
static bool F_109 ( struct V_101 * V_102 , T_4 time )
{
return V_102 -> V_111 > time ;
}
int F_110 ( struct V_101 * V_102 , T_3 V_143 ,
int V_144 , struct V_145 * V_43 )
{
int V_44 ;
T_5 V_30 ;
struct V_36 * V_37 = V_102 -> V_37 ;
T_3 V_146 [ 2 ] = { V_102 -> V_107 , V_143 } ;
struct V_31 * V_32 ;
if ( V_37 -> V_121 )
return - V_91 ;
F_76 ( & V_37 -> V_118 ) ;
if ( V_144 ) {
V_32 = & V_37 -> V_32 ;
} else
V_32 = & V_37 -> V_55 ;
V_44 = F_80 ( V_32 , V_37 -> V_34 , V_146 , & V_30 ) ;
if ( ! V_44 ) {
T_2 V_147 = 0 ;
T_3 V_148 ;
T_4 V_149 ;
V_147 = F_8 ( V_30 ) ;
F_12 ( V_147 , & V_148 ,
& V_149 ) ;
V_43 -> V_143 = V_148 ;
V_43 -> V_150 = F_109 ( V_102 , V_149 ) ;
}
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_111 ( struct V_101 * V_102 , T_3 V_143 ,
T_3 V_151 )
{
int V_44 , V_152 ;
T_5 V_30 ;
struct V_36 * V_37 = V_102 -> V_37 ;
T_3 V_146 [ 2 ] = { V_102 -> V_107 , V_143 } ;
V_30 = F_3 ( F_11 ( V_151 , V_37 -> time ) ) ;
F_63 ( & V_30 ) ;
V_44 = F_112 ( & V_37 -> V_32 , V_37 -> V_34 , V_146 , & V_30 ,
& V_37 -> V_34 , & V_152 ) ;
if ( V_44 )
return V_44 ;
V_102 -> V_106 = 1 ;
if ( V_152 )
V_102 -> V_108 ++ ;
return 0 ;
}
int F_113 ( struct V_101 * V_102 , T_3 V_143 ,
T_3 V_151 )
{
int V_44 = - V_91 ;
F_86 ( & V_102 -> V_37 -> V_118 ) ;
if ( ! V_102 -> V_37 -> V_121 )
V_44 = F_111 ( V_102 , V_143 , V_151 ) ;
F_87 ( & V_102 -> V_37 -> V_118 ) ;
return V_44 ;
}
static int F_114 ( struct V_101 * V_102 , T_3 V_143 )
{
int V_44 ;
struct V_36 * V_37 = V_102 -> V_37 ;
T_3 V_146 [ 2 ] = { V_102 -> V_107 , V_143 } ;
V_44 = F_84 ( & V_37 -> V_32 , V_37 -> V_34 , V_146 , & V_37 -> V_34 ) ;
if ( V_44 )
return V_44 ;
V_102 -> V_108 -- ;
V_102 -> V_106 = 1 ;
return 0 ;
}
int F_115 ( struct V_101 * V_102 , T_3 V_143 )
{
int V_44 = - V_91 ;
F_86 ( & V_102 -> V_37 -> V_118 ) ;
if ( ! V_102 -> V_37 -> V_121 )
V_44 = F_114 ( V_102 , V_143 ) ;
F_87 ( & V_102 -> V_37 -> V_118 ) ;
return V_44 ;
}
int F_116 ( struct V_36 * V_37 , T_3 V_4 , bool * V_43 )
{
int V_44 ;
T_4 V_153 ;
F_76 ( & V_37 -> V_118 ) ;
V_44 = F_117 ( V_37 -> V_50 , V_4 , & V_153 ) ;
if ( ! V_44 )
* V_43 = ( V_153 != 0 ) ;
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
bool F_118 ( struct V_101 * V_102 )
{
int V_44 ;
F_76 ( & V_102 -> V_37 -> V_118 ) ;
V_44 = V_102 -> V_106 ;
F_77 ( & V_102 -> V_37 -> V_118 ) ;
return V_44 ;
}
bool F_119 ( struct V_36 * V_37 )
{
bool V_44 = false ;
struct V_101 * V_102 , * V_103 ;
F_76 ( & V_37 -> V_118 ) ;
F_62 (td, tmp, &pmd->thin_devices, list) {
if ( V_102 -> V_106 ) {
V_44 = V_102 -> V_106 ;
break;
}
}
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
bool F_120 ( struct V_101 * V_102 )
{
bool V_44 ;
F_76 ( & V_102 -> V_37 -> V_118 ) ;
V_44 = V_102 -> V_132 ;
F_77 ( & V_102 -> V_37 -> V_118 ) ;
return V_44 ;
}
int F_121 ( struct V_36 * V_37 , T_3 * V_43 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_122 ( V_37 -> V_50 , V_43 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_123 ( struct V_36 * V_37 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( V_37 -> V_121 )
goto V_141;
V_44 = F_67 ( V_37 ) ;
if ( V_44 <= 0 )
goto V_141;
V_44 = F_60 ( V_37 ) ;
V_141:
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static void F_124 ( struct V_36 * V_37 )
{
struct V_101 * V_102 ;
F_79 (td, &pmd->thin_devices, list)
V_102 -> V_132 = V_102 -> V_106 ;
}
int F_125 ( struct V_36 * V_37 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( V_37 -> V_121 )
goto V_141;
F_124 ( V_37 ) ;
F_59 ( V_37 ) ;
V_44 = F_56 ( V_37 , false ) ;
if ( V_44 )
V_37 -> V_121 = true ;
V_141:
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_126 ( struct V_36 * V_37 , T_3 * V_43 )
{
int V_44 = - V_91 ;
F_76 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_127 ( V_37 -> V_50 , V_43 ) ;
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_128 ( struct V_36 * V_37 ,
T_3 * V_43 )
{
int V_44 = - V_91 ;
F_76 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_127 ( V_37 -> V_62 , V_43 ) ;
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_129 ( struct V_36 * V_37 ,
T_3 * V_43 )
{
int V_44 = - V_91 ;
F_76 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_130 ( V_37 -> V_62 , V_43 ) ;
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_131 ( struct V_36 * V_37 , T_6 * V_43 )
{
F_76 ( & V_37 -> V_118 ) ;
* V_43 = V_37 -> V_83 ;
F_77 ( & V_37 -> V_118 ) ;
return 0 ;
}
int F_132 ( struct V_36 * V_37 , T_3 * V_43 )
{
int V_44 = - V_91 ;
F_76 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_130 ( V_37 -> V_50 , V_43 ) ;
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_133 ( struct V_101 * V_102 , T_3 * V_43 )
{
int V_44 = - V_91 ;
struct V_36 * V_37 = V_102 -> V_37 ;
F_76 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 ) {
* V_43 = V_102 -> V_108 ;
V_44 = 0 ;
}
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_134 ( struct V_101 * V_102 , T_3 * V_43 )
{
int V_44 ;
T_5 V_20 ;
T_3 V_154 ;
struct V_36 * V_37 = V_102 -> V_37 ;
V_44 = F_80 ( & V_37 -> V_57 , V_37 -> V_34 , & V_102 -> V_107 , & V_20 ) ;
if ( V_44 )
return V_44 ;
V_154 = F_8 ( V_20 ) ;
return F_135 ( & V_37 -> V_58 , V_154 , V_43 ) ;
}
int F_136 ( struct V_101 * V_102 ,
T_3 * V_43 )
{
int V_44 = - V_91 ;
struct V_36 * V_37 = V_102 -> V_37 ;
F_76 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_134 ( V_102 , V_43 ) ;
F_77 ( & V_37 -> V_118 ) ;
return V_44 ;
}
static int F_137 ( struct V_21 * V_22 , T_3 V_155 )
{
int V_44 ;
T_3 V_156 ;
V_44 = F_130 ( V_22 , & V_156 ) ;
if ( V_44 )
return V_44 ;
if ( V_155 == V_156 )
return 0 ;
if ( V_155 < V_156 ) {
F_9 ( L_24 ) ;
return - V_91 ;
}
return F_138 ( V_22 , V_155 - V_156 ) ;
}
int F_139 ( struct V_36 * V_37 , T_3 V_155 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_137 ( V_37 -> V_50 , V_155 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_140 ( struct V_36 * V_37 , T_3 V_155 )
{
int V_44 = - V_91 ;
F_86 ( & V_37 -> V_118 ) ;
if ( ! V_37 -> V_121 )
V_44 = F_137 ( V_37 -> V_62 , V_155 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
void F_141 ( struct V_36 * V_37 )
{
F_86 ( & V_37 -> V_118 ) ;
V_37 -> V_120 = true ;
F_142 ( V_37 -> V_39 ) ;
F_87 ( & V_37 -> V_118 ) ;
}
void F_143 ( struct V_36 * V_37 )
{
F_86 ( & V_37 -> V_118 ) ;
V_37 -> V_120 = false ;
F_144 ( V_37 -> V_39 ) ;
F_87 ( & V_37 -> V_118 ) ;
}
int F_145 ( struct V_36 * V_37 ,
T_3 V_157 ,
T_8 V_158 ,
void * V_19 )
{
int V_44 ;
F_86 ( & V_37 -> V_118 ) ;
V_44 = F_146 ( V_37 -> V_62 , V_157 , V_158 , V_19 ) ;
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
int F_147 ( struct V_36 * V_37 )
{
int V_44 ;
struct V_3 * V_38 ;
struct V_6 * V_7 ;
F_86 ( & V_37 -> V_118 ) ;
V_37 -> V_10 |= V_159 ;
V_44 = F_25 ( V_37 , & V_38 ) ;
if ( V_44 ) {
F_9 ( L_12 ) ;
goto V_141;
}
V_7 = F_2 ( V_38 ) ;
V_7 -> V_10 = F_5 ( V_37 -> V_10 ) ;
F_30 ( V_38 ) ;
V_141:
F_87 ( & V_37 -> V_118 ) ;
return V_44 ;
}
bool F_148 ( struct V_36 * V_37 )
{
bool V_160 ;
F_76 ( & V_37 -> V_118 ) ;
V_160 = V_37 -> V_10 & V_159 ;
F_77 ( & V_37 -> V_118 ) ;
return V_160 ;
}
void F_149 ( struct V_36 * V_37 )
{
F_150 ( V_37 -> V_35 ) ;
}
