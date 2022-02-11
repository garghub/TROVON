static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_8 ;
unsigned int V_9 = 0 ;
if ( V_3 == V_10 && V_11 <= 0 ) {
V_11 = 0 ;
return 0 ;
}
if ( V_11 )
return 0 ;
if ( V_3 != V_12 )
return 0 ;
F_2 ( & V_13 ) ;
V_8 = F_3 ( V_14 , V_6 -> V_15 ) ;
if ( ! V_8 || ! V_8 -> V_16 )
goto V_17;
V_9 = ( unsigned int ) V_8 -> V_18 ;
if ( V_9 >= V_8 -> V_16 -> V_19 )
goto V_17;
F_4 ( V_6 , 0 ,
V_8 -> V_16 -> V_20 [ V_9 ] .
V_21 * 1000 ) ;
V_17:
F_5 ( & V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
T_1 V_22 = 0 ;
unsigned long long V_9 = 0 ;
if ( ! V_8 )
return - V_23 ;
V_22 = F_7 ( V_8 -> V_24 , L_1 , NULL , & V_9 ) ;
if ( V_22 != V_25 )
V_26 |= V_27 ;
if ( F_8 ( V_22 ) && V_22 != V_25 ) {
F_9 ( ( V_28 , V_22 , L_2 ) ) ;
return - V_29 ;
}
F_10 ( L_3 , V_8 -> V_30 ,
( int ) V_9 , V_9 ? L_4 : L_5 ) ;
V_8 -> V_18 = ( int ) V_9 ;
return 0 ;
}
static void F_11 ( T_2 V_24 , int V_22 )
{
union V_31 V_32 [ 2 ] = {
{ . type = V_33 ,} ,
{ . type = V_33 ,} ,
} ;
struct V_34 V_35 = { 2 , V_32 } ;
if ( F_12 ( V_24 , L_6 ) ) {
V_32 [ 0 ] . integer . V_36 = V_37 ;
V_32 [ 1 ] . integer . V_36 = V_22 ;
F_13 ( V_24 , L_6 , & V_35 , NULL ) ;
}
}
int F_14 ( struct V_7 * V_8 , int V_38 )
{
int V_39 ;
if ( V_11 ) {
if ( V_38 )
F_11 ( V_8 -> V_24 , 1 ) ;
return 0 ;
}
V_39 = F_6 ( V_8 ) ;
if ( V_38 ) {
if ( V_39 < 0 )
F_11 ( V_8 -> V_24 , 1 ) ;
else
F_11 ( V_8 -> V_24 , 0 ) ;
}
if ( V_39 < 0 )
return ( V_39 ) ;
else
return F_15 ( V_8 -> V_30 ) ;
}
int F_16 ( int V_15 , unsigned int * V_40 )
{
struct V_7 * V_8 ;
V_8 = F_3 ( V_14 , V_15 ) ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_16 -> V_19 )
return - V_29 ;
* V_40 = V_8 -> V_16 -> V_20 [ V_8 -> V_18 ] .
V_21 * 1000 ;
return 0 ;
}
void F_17 ( void )
{
if ( ! F_18
( & V_41 , V_42 ) )
V_26 |= V_43 ;
else
F_19 ( V_44
L_7 ) ;
}
void F_20 ( void )
{
if ( V_26 & V_43 )
F_21 ( & V_41 ,
V_42 ) ;
V_26 &= ~ V_43 ;
}
void F_22 ( struct V_7 * V_8 )
{
static int V_45 ;
T_1 V_22 = 0 ;
struct V_46 V_47 = { V_48 , NULL } ;
if ( ! F_23 () || V_45 )
return;
V_22 = F_13 ( V_8 -> V_24 , L_8 , NULL , & V_47 ) ;
if ( ! F_8 ( V_22 ) ) {
F_19 (KERN_INFO PREFIX L_9 ) ;
F_24 ( L_10 ) ;
V_45 = 1 ;
}
F_25 ( V_47 . V_49 ) ;
}
static int F_26 ( struct V_7 * V_8 )
{
int V_50 = 0 ;
T_1 V_22 = 0 ;
struct V_46 V_47 = { V_48 , NULL } ;
union V_31 * V_51 = NULL ;
union V_31 V_52 = { 0 } ;
V_22 = F_13 ( V_8 -> V_24 , L_8 , NULL , & V_47 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_11 ) ) ;
return - V_29 ;
}
V_51 = (union V_31 * ) V_47 . V_49 ;
if ( ! V_51 || ( V_51 -> type != V_53 )
|| ( V_51 -> V_54 . V_55 != 2 ) ) {
F_19 (KERN_ERR PREFIX L_12 ) ;
V_50 = - V_56 ;
goto V_57;
}
V_52 = V_51 -> V_54 . V_58 [ 0 ] ;
if ( ( V_52 . type != V_59 )
|| ( V_52 . V_47 . V_60 < sizeof( struct V_61 ) )
|| ( V_52 . V_47 . V_49 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_13 ) ;
V_50 = - V_56 ;
goto V_57;
}
memcpy ( & V_8 -> V_16 -> V_62 , V_52 . V_47 . V_49 ,
sizeof( struct V_61 ) ) ;
V_52 = V_51 -> V_54 . V_58 [ 1 ] ;
if ( ( V_52 . type != V_59 )
|| ( V_52 . V_47 . V_60 < sizeof( struct V_61 ) )
|| ( V_52 . V_47 . V_49 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_14 ) ;
V_50 = - V_56 ;
goto V_57;
}
memcpy ( & V_8 -> V_16 -> V_63 , V_52 . V_47 . V_49 ,
sizeof( struct V_61 ) ) ;
V_57:
F_25 ( V_47 . V_49 ) ;
return V_50 ;
}
static void F_27 ( struct V_64 * V_65 , int V_66 )
{
T_3 V_67 , V_68 , V_69 , V_70 ;
int V_71 = V_65 -> V_72 & 0x00000007 ;
if ( V_73 . V_74 != V_75 )
return;
if ( ( V_73 . V_76 == 0x10 && V_73 . V_77 < 10 )
|| V_73 . V_76 == 0x11 ) {
F_28 ( V_78 + V_71 , V_68 , V_67 ) ;
if ( ! ( V_67 & F_29 ( 31 ) ) )
return;
V_69 = V_68 & 0x3f ;
V_70 = ( V_68 >> 6 ) & 7 ;
if ( V_73 . V_76 == 0x10 )
V_65 -> V_21 = ( 100 * ( V_69 + 0x10 ) ) >> V_70 ;
else
V_65 -> V_21 = ( 100 * ( V_69 + 8 ) ) >> V_70 ;
}
}
static void F_27 ( struct V_64 * V_65 , int V_66 ) {}
static int F_30 ( struct V_7 * V_8 )
{
int V_50 = 0 ;
T_1 V_22 = V_79 ;
struct V_46 V_47 = { V_48 , NULL } ;
struct V_46 V_80 = { sizeof( L_15 ) , L_15 } ;
struct V_46 V_81 = { 0 , NULL } ;
union V_31 * V_82 = NULL ;
int V_66 ;
int V_83 = - 1 ;
V_22 = F_13 ( V_8 -> V_24 , L_16 , NULL , & V_47 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_17 ) ) ;
return - V_29 ;
}
V_82 = V_47 . V_49 ;
if ( ! V_82 || ( V_82 -> type != V_53 ) ) {
F_19 (KERN_ERR PREFIX L_18 ) ;
V_50 = - V_56 ;
goto V_57;
}
F_31 ( ( V_84 , L_19 ,
V_82 -> V_54 . V_55 ) ) ;
V_8 -> V_16 -> V_19 = V_82 -> V_54 . V_55 ;
V_8 -> V_16 -> V_20 =
F_32 ( sizeof( struct V_64 ) * V_82 -> V_54 . V_55 ,
V_85 ) ;
if ( ! V_8 -> V_16 -> V_20 ) {
V_50 = - V_86 ;
goto V_57;
}
for ( V_66 = 0 ; V_66 < V_8 -> V_16 -> V_19 ; V_66 ++ ) {
struct V_64 * V_65 = & ( V_8 -> V_16 -> V_20 [ V_66 ] ) ;
V_81 . V_60 = sizeof( struct V_64 ) ;
V_81 . V_49 = V_65 ;
F_31 ( ( V_84 , L_20 , V_66 ) ) ;
V_22 = F_33 ( & ( V_82 -> V_54 . V_58 [ V_66 ] ) ,
& V_80 , & V_81 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_21 ) ) ;
V_50 = - V_56 ;
F_25 ( V_8 -> V_16 -> V_20 ) ;
goto V_57;
}
F_27 ( V_65 , V_66 ) ;
F_31 ( ( V_84 ,
L_22 ,
V_66 ,
( T_3 ) V_65 -> V_21 ,
( T_3 ) V_65 -> V_87 ,
( T_3 ) V_65 -> V_88 ,
( T_3 ) V_65 -> V_89 ,
( T_3 ) V_65 -> V_72 , ( T_3 ) V_65 -> V_22 ) ) ;
if ( ! V_65 -> V_21 ||
( ( T_3 ) ( V_65 -> V_21 * 1000 ) !=
( V_65 -> V_21 * 1000 ) ) ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_23 ,
pr->id, px->core_frequency) ;
if ( V_83 == - 1 )
V_83 = V_66 ;
} else {
if ( V_83 != - 1 ) {
memcpy ( & ( V_8 -> V_16 -> V_20 [ V_83 ] ) ,
V_65 , sizeof( struct V_64 ) ) ;
++ V_83 ;
}
}
}
if ( V_83 == 0 ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_24 , pr->id) ;
V_50 = - V_56 ;
F_25 ( V_8 -> V_16 -> V_20 ) ;
V_8 -> V_16 -> V_20 = NULL ;
}
if ( V_83 > 0 )
V_8 -> V_16 -> V_19 = V_83 ;
V_57:
F_25 ( V_47 . V_49 ) ;
return V_50 ;
}
int F_34 ( struct V_7 * V_8 )
{
int V_50 = 0 ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_24 )
return - V_23 ;
if ( ! F_12 ( V_8 -> V_24 , L_8 ) ) {
F_31 ( ( V_84 ,
L_25 ) ) ;
return - V_29 ;
}
V_50 = F_26 ( V_8 ) ;
if ( V_50 )
goto V_90;
V_50 = F_30 ( V_8 ) ;
if ( V_50 )
goto V_90;
if ( V_11 != 1 )
V_50 = F_6 ( V_8 ) ;
return V_50 ;
V_90:
#ifdef F_35
if ( F_12 ( V_8 -> V_24 , L_1 ) ) {
if( F_36 ( V_91 ) )
F_19 (KERN_WARNING FW_BUG L_26
L_27 ) ;
}
#endif
return V_50 ;
}
int F_37 ( struct V_92 * V_93 )
{
T_1 V_22 ;
static int V_94 = 0 ;
if ( ! ( V_26 & V_43 ) )
return - V_95 ;
if ( ! F_38 ( V_93 ) )
return - V_23 ;
if ( V_94 > 0 ) {
F_39 ( V_93 ) ;
return 0 ;
} else if ( V_94 < 0 ) {
F_39 ( V_93 ) ;
return V_94 ;
}
V_94 = - V_96 ;
if ( ( ! V_97 . V_98 ) || ( ! V_97 . V_99 ) ) {
F_31 ( ( V_84 , L_28 ) ) ;
F_39 ( V_93 ) ;
return 0 ;
}
F_31 ( ( V_84 ,
L_29 ,
V_97 . V_99 , V_97 . V_98 ) ) ;
V_22 = F_40 ( V_97 . V_98 ,
( T_3 ) V_97 . V_99 , 8 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 ,
L_30
L_31 , V_97 . V_99 ,
V_97 . V_98 ) ) ;
F_39 ( V_93 ) ;
return V_22 ;
}
V_94 = 1 ;
if ( ! ( V_26 & V_27 ) )
F_39 ( V_93 ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 )
{
int V_50 = 0 ;
T_1 V_22 = V_79 ;
struct V_46 V_47 = { V_48 , NULL } ;
struct V_46 V_80 = { sizeof( L_32 ) , L_32 } ;
struct V_46 V_81 = { 0 , NULL } ;
union V_31 * V_100 = NULL ;
struct V_101 * V_102 ;
V_22 = F_13 ( V_8 -> V_24 , L_33 , NULL , & V_47 ) ;
if ( F_8 ( V_22 ) ) {
return - V_29 ;
}
V_100 = V_47 . V_49 ;
if ( ! V_100 || ( V_100 -> type != V_53 ) ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_50 = - V_56 ;
goto V_57;
}
if ( V_100 -> V_54 . V_55 != 1 ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_50 = - V_56 ;
goto V_57;
}
V_102 = & ( V_8 -> V_16 -> V_103 ) ;
V_81 . V_60 = sizeof( struct V_101 ) ;
V_81 . V_49 = V_102 ;
V_22 = F_33 ( & ( V_100 -> V_54 . V_58 [ 0 ] ) ,
& V_80 , & V_81 ) ;
if ( F_8 ( V_22 ) ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_50 = - V_56 ;
goto V_57;
}
if ( V_102 -> V_104 != V_105 ) {
F_19 (KERN_ERR PREFIX L_35 ) ;
V_50 = - V_56 ;
goto V_57;
}
if ( V_102 -> V_106 != V_107 ) {
F_19 (KERN_ERR PREFIX L_36 ) ;
V_50 = - V_56 ;
goto V_57;
}
if ( V_102 -> V_108 != V_109 &&
V_102 -> V_108 != V_110 &&
V_102 -> V_108 != V_111 ) {
F_19 (KERN_ERR PREFIX L_37 ) ;
V_50 = - V_56 ;
goto V_57;
}
V_57:
F_25 ( V_47 . V_49 ) ;
return V_50 ;
}
int F_42 (
struct V_112 T_4 * V_16 )
{
int V_113 ;
int V_114 = 0 ;
unsigned int V_66 , V_115 ;
T_5 V_116 ;
struct V_7 * V_8 ;
struct V_101 * V_102 ;
struct V_7 * V_117 ;
struct V_101 * V_118 ;
if ( ! F_43 ( & V_116 , V_85 ) )
return - V_86 ;
F_2 ( & V_13 ) ;
F_44 (i) {
V_8 = F_3 ( V_14 , V_66 ) ;
if ( ! V_8 ) {
continue;
}
if ( V_8 -> V_16 ) {
V_114 = - V_95 ;
goto V_119;
}
if ( ! V_16 || ! F_45 ( V_16 , V_66 ) ) {
V_114 = - V_23 ;
goto V_119;
}
}
F_44 (i) {
V_8 = F_3 ( V_14 , V_66 ) ;
if ( ! V_8 )
continue;
V_8 -> V_16 = F_45 ( V_16 , V_66 ) ;
F_46 ( V_66 , V_8 -> V_16 -> V_120 ) ;
if ( F_41 ( V_8 ) ) {
V_114 = - V_23 ;
continue;
}
}
if ( V_114 )
goto V_121;
F_44 (i) {
V_8 = F_3 ( V_14 , V_66 ) ;
if ( ! V_8 )
continue;
if ( F_47 ( V_66 , V_116 ) )
continue;
V_102 = & ( V_8 -> V_16 -> V_103 ) ;
F_46 ( V_66 , V_8 -> V_16 -> V_120 ) ;
F_46 ( V_66 , V_116 ) ;
if ( V_102 -> V_122 <= 1 )
continue;
V_113 = V_102 -> V_122 ;
if ( V_102 -> V_108 == V_109 )
V_8 -> V_16 -> V_123 = V_124 ;
else if ( V_102 -> V_108 == V_111 )
V_8 -> V_16 -> V_123 = V_125 ;
else if ( V_102 -> V_108 == V_110 )
V_8 -> V_16 -> V_123 = V_126 ;
F_44 (j) {
if ( V_66 == V_115 )
continue;
V_117 = F_3 ( V_14 , V_115 ) ;
if ( ! V_117 )
continue;
V_118 = & ( V_117 -> V_16 -> V_103 ) ;
if ( V_118 -> V_127 != V_102 -> V_127 )
continue;
if ( V_118 -> V_122 != V_113 ) {
V_114 = - V_23 ;
goto V_121;
}
if ( V_102 -> V_108 != V_118 -> V_108 ) {
V_114 = - V_23 ;
goto V_121;
}
F_46 ( V_115 , V_116 ) ;
F_46 ( V_115 , V_8 -> V_16 -> V_120 ) ;
}
F_44 (j) {
if ( V_66 == V_115 )
continue;
V_117 = F_3 ( V_14 , V_115 ) ;
if ( ! V_117 )
continue;
V_118 = & ( V_117 -> V_16 -> V_103 ) ;
if ( V_118 -> V_127 != V_102 -> V_127 )
continue;
V_117 -> V_16 -> V_123 =
V_8 -> V_16 -> V_123 ;
F_48 ( V_117 -> V_16 -> V_120 ,
V_8 -> V_16 -> V_120 ) ;
}
}
V_121:
F_44 (i) {
V_8 = F_3 ( V_14 , V_66 ) ;
if ( ! V_8 || ! V_8 -> V_16 )
continue;
if ( V_114 ) {
F_49 ( V_8 -> V_16 -> V_120 ) ;
F_46 ( V_66 , V_8 -> V_16 -> V_120 ) ;
V_8 -> V_16 -> V_123 = V_124 ;
}
V_8 -> V_16 = NULL ;
}
V_119:
F_5 ( & V_13 ) ;
F_50 ( V_116 ) ;
return V_114 ;
}
int
F_51 ( struct V_112
* V_16 , unsigned int V_15 )
{
struct V_7 * V_8 ;
if ( ! ( V_26 & V_43 ) )
return - V_23 ;
F_2 ( & V_13 ) ;
V_8 = F_3 ( V_14 , V_15 ) ;
if ( ! V_8 ) {
F_5 ( & V_13 ) ;
return - V_29 ;
}
if ( V_8 -> V_16 ) {
F_5 ( & V_13 ) ;
return - V_95 ;
}
F_52 ( ! V_16 ) ;
V_8 -> V_16 = V_16 ;
if ( F_34 ( V_8 ) ) {
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return - V_96 ;
}
F_5 ( & V_13 ) ;
return 0 ;
}
void
F_53 ( struct V_112
* V_16 , unsigned int V_15 )
{
struct V_7 * V_8 ;
F_2 ( & V_13 ) ;
V_8 = F_3 ( V_14 , V_15 ) ;
if ( ! V_8 ) {
F_5 ( & V_13 ) ;
return;
}
if ( V_8 -> V_16 )
F_25 ( V_8 -> V_16 -> V_20 ) ;
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return;
}
