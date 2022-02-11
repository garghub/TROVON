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
T_2 V_36 ;
V_32 [ 0 ] . integer . V_37 = V_38 ;
V_32 [ 1 ] . integer . V_37 = V_22 ;
if ( F_8 ( F_12 ( V_24 , L_6 , & V_36 ) ) )
return;
F_13 ( V_24 , L_6 , & V_35 , NULL ) ;
return;
}
int F_14 ( struct V_7 * V_8 , int V_39 )
{
int V_40 ;
if ( V_11 ) {
if ( V_39 )
F_11 ( V_8 -> V_24 , 1 ) ;
return 0 ;
}
V_40 = F_6 ( V_8 ) ;
if ( V_39 ) {
if ( V_40 < 0 )
F_11 ( V_8 -> V_24 , 1 ) ;
else
F_11 ( V_8 -> V_24 , 0 ) ;
}
if ( V_40 < 0 )
return ( V_40 ) ;
else
return F_15 ( V_8 -> V_30 ) ;
}
int F_16 ( int V_15 , unsigned int * V_41 )
{
struct V_7 * V_8 ;
V_8 = F_3 ( V_14 , V_15 ) ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_16 -> V_19 )
return - V_29 ;
* V_41 = V_8 -> V_16 -> V_20 [ V_8 -> V_18 ] .
V_21 * 1000 ;
return 0 ;
}
void F_17 ( void )
{
if ( ! F_18
( & V_42 , V_43 ) )
V_26 |= V_44 ;
else
F_19 ( V_45
L_7 ) ;
}
void F_20 ( void )
{
if ( V_26 & V_44 )
F_21 ( & V_42 ,
V_43 ) ;
V_26 &= ~ V_44 ;
}
void F_22 ( struct V_7 * V_8 )
{
static int V_46 ;
T_1 V_22 = 0 ;
struct V_47 V_48 = { V_49 , NULL } ;
if ( ! F_23 () || V_46 )
return;
V_22 = F_13 ( V_8 -> V_24 , L_8 , NULL , & V_48 ) ;
if ( ! F_8 ( V_22 ) ) {
F_19 (KERN_INFO PREFIX L_9 ) ;
F_24 ( L_10 ) ;
V_46 = 1 ;
}
F_25 ( V_48 . V_50 ) ;
}
static int F_26 ( struct V_7 * V_8 )
{
int V_51 = 0 ;
T_1 V_22 = 0 ;
struct V_47 V_48 = { V_49 , NULL } ;
union V_31 * V_52 = NULL ;
union V_31 V_53 = { 0 } ;
V_22 = F_13 ( V_8 -> V_24 , L_8 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_11 ) ) ;
return - V_29 ;
}
V_52 = (union V_31 * ) V_48 . V_50 ;
if ( ! V_52 || ( V_52 -> type != V_54 )
|| ( V_52 -> V_55 . V_56 != 2 ) ) {
F_19 (KERN_ERR PREFIX L_12 ) ;
V_51 = - V_57 ;
goto V_58;
}
V_53 = V_52 -> V_55 . V_59 [ 0 ] ;
if ( ( V_53 . type != V_60 )
|| ( V_53 . V_48 . V_61 < sizeof( struct V_62 ) )
|| ( V_53 . V_48 . V_50 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_13 ) ;
V_51 = - V_57 ;
goto V_58;
}
memcpy ( & V_8 -> V_16 -> V_63 , V_53 . V_48 . V_50 ,
sizeof( struct V_62 ) ) ;
V_53 = V_52 -> V_55 . V_59 [ 1 ] ;
if ( ( V_53 . type != V_60 )
|| ( V_53 . V_48 . V_61 < sizeof( struct V_62 ) )
|| ( V_53 . V_48 . V_50 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_14 ) ;
V_51 = - V_57 ;
goto V_58;
}
memcpy ( & V_8 -> V_16 -> V_64 , V_53 . V_48 . V_50 ,
sizeof( struct V_62 ) ) ;
V_58:
F_25 ( V_48 . V_50 ) ;
return V_51 ;
}
static void F_27 ( struct V_65 * V_66 , int V_67 )
{
T_3 V_68 , V_69 , V_70 , V_71 ;
int V_72 = V_66 -> V_73 & 0x00000007 ;
if ( V_74 . V_75 != V_76 )
return;
if ( ( V_74 . V_77 == 0x10 && V_74 . V_78 < 10 )
|| V_74 . V_77 == 0x11 ) {
F_28 ( V_79 + V_72 , V_69 , V_68 ) ;
V_70 = V_69 & 0x3f ;
V_71 = ( V_69 >> 6 ) & 7 ;
if ( V_74 . V_77 == 0x10 )
V_66 -> V_21 = ( 100 * ( V_70 + 0x10 ) ) >> V_71 ;
else
V_66 -> V_21 = ( 100 * ( V_70 + 8 ) ) >> V_71 ;
}
}
static void F_27 ( struct V_65 * V_66 , int V_67 ) {}
static int F_29 ( struct V_7 * V_8 )
{
int V_51 = 0 ;
T_1 V_22 = V_80 ;
struct V_47 V_48 = { V_49 , NULL } ;
struct V_47 V_81 = { sizeof( L_15 ) , L_15 } ;
struct V_47 V_82 = { 0 , NULL } ;
union V_31 * V_83 = NULL ;
int V_67 ;
int V_84 = - 1 ;
V_22 = F_13 ( V_8 -> V_24 , L_16 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_17 ) ) ;
return - V_29 ;
}
V_83 = V_48 . V_50 ;
if ( ! V_83 || ( V_83 -> type != V_54 ) ) {
F_19 (KERN_ERR PREFIX L_18 ) ;
V_51 = - V_57 ;
goto V_58;
}
F_30 ( ( V_85 , L_19 ,
V_83 -> V_55 . V_56 ) ) ;
V_8 -> V_16 -> V_19 = V_83 -> V_55 . V_56 ;
V_8 -> V_16 -> V_20 =
F_31 ( sizeof( struct V_65 ) * V_83 -> V_55 . V_56 ,
V_86 ) ;
if ( ! V_8 -> V_16 -> V_20 ) {
V_51 = - V_87 ;
goto V_58;
}
for ( V_67 = 0 ; V_67 < V_8 -> V_16 -> V_19 ; V_67 ++ ) {
struct V_65 * V_66 = & ( V_8 -> V_16 -> V_20 [ V_67 ] ) ;
V_82 . V_61 = sizeof( struct V_65 ) ;
V_82 . V_50 = V_66 ;
F_30 ( ( V_85 , L_20 , V_67 ) ) ;
V_22 = F_32 ( & ( V_83 -> V_55 . V_59 [ V_67 ] ) ,
& V_81 , & V_82 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_21 ) ) ;
V_51 = - V_57 ;
F_25 ( V_8 -> V_16 -> V_20 ) ;
goto V_58;
}
F_27 ( V_66 , V_67 ) ;
F_30 ( ( V_85 ,
L_22 ,
V_67 ,
( T_3 ) V_66 -> V_21 ,
( T_3 ) V_66 -> V_88 ,
( T_3 ) V_66 -> V_89 ,
( T_3 ) V_66 -> V_90 ,
( T_3 ) V_66 -> V_73 , ( T_3 ) V_66 -> V_22 ) ) ;
if ( ! V_66 -> V_21 ||
( ( T_3 ) ( V_66 -> V_21 * 1000 ) !=
( V_66 -> V_21 * 1000 ) ) ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_23 ,
pr->id, px->core_frequency) ;
if ( V_84 == - 1 )
V_84 = V_67 ;
} else {
if ( V_84 != - 1 ) {
memcpy ( & ( V_8 -> V_16 -> V_20 [ V_84 ] ) ,
V_66 , sizeof( struct V_65 ) ) ;
++ V_84 ;
}
}
}
if ( V_84 == 0 ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_24 , pr->id) ;
V_51 = - V_57 ;
F_25 ( V_8 -> V_16 -> V_20 ) ;
V_8 -> V_16 -> V_20 = NULL ;
}
if ( V_84 > 0 )
V_8 -> V_16 -> V_19 = V_84 ;
V_58:
F_25 ( V_48 . V_50 ) ;
return V_51 ;
}
static int F_33 ( struct V_7 * V_8 )
{
int V_51 = 0 ;
T_1 V_22 = V_80 ;
T_2 V_24 = NULL ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_24 )
return - V_23 ;
V_22 = F_12 ( V_8 -> V_24 , L_8 , & V_24 ) ;
if ( F_8 ( V_22 ) ) {
F_30 ( ( V_85 ,
L_25 ) ) ;
return - V_29 ;
}
V_51 = F_26 ( V_8 ) ;
if ( V_51 )
goto V_91;
V_51 = F_29 ( V_8 ) ;
if ( V_51 )
goto V_91;
if ( V_11 != 1 )
V_51 = F_6 ( V_8 ) ;
return V_51 ;
V_91:
#ifdef F_34
if ( F_35 ( F_12 ( V_8 -> V_24 , L_1 , & V_24 ) ) ) {
if( F_36 ( V_92 ) )
F_19 (KERN_WARNING FW_BUG L_26
L_27 ) ;
}
#endif
return V_51 ;
}
int F_37 ( struct V_93 * V_94 )
{
T_1 V_22 ;
static int V_95 = 0 ;
if ( ! ( V_26 & V_44 ) )
return - V_96 ;
if ( ! F_38 ( V_94 ) )
return - V_23 ;
if ( V_95 > 0 ) {
F_39 ( V_94 ) ;
return 0 ;
} else if ( V_95 < 0 ) {
F_39 ( V_94 ) ;
return V_95 ;
}
V_95 = - V_97 ;
if ( ( ! V_98 . V_99 ) || ( ! V_98 . V_100 ) ) {
F_30 ( ( V_85 , L_28 ) ) ;
F_39 ( V_94 ) ;
return 0 ;
}
F_30 ( ( V_85 ,
L_29 ,
V_98 . V_100 , V_98 . V_99 ) ) ;
V_22 = F_40 ( V_98 . V_99 ,
( T_3 ) V_98 . V_100 , 8 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 ,
L_30
L_31 , V_98 . V_100 ,
V_98 . V_99 ) ) ;
F_39 ( V_94 ) ;
return V_22 ;
}
V_95 = 1 ;
if ( ! ( V_26 & V_27 ) )
F_39 ( V_94 ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 )
{
int V_51 = 0 ;
T_1 V_22 = V_80 ;
struct V_47 V_48 = { V_49 , NULL } ;
struct V_47 V_81 = { sizeof( L_32 ) , L_32 } ;
struct V_47 V_82 = { 0 , NULL } ;
union V_31 * V_101 = NULL ;
struct V_102 * V_103 ;
V_22 = F_13 ( V_8 -> V_24 , L_33 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
return - V_29 ;
}
V_101 = V_48 . V_50 ;
if ( ! V_101 || ( V_101 -> type != V_54 ) ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_101 -> V_55 . V_56 != 1 ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_51 = - V_57 ;
goto V_58;
}
V_103 = & ( V_8 -> V_16 -> V_104 ) ;
V_82 . V_61 = sizeof( struct V_102 ) ;
V_82 . V_50 = V_103 ;
V_22 = F_32 ( & ( V_101 -> V_55 . V_59 [ 0 ] ) ,
& V_81 , & V_82 ) ;
if ( F_8 ( V_22 ) ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_103 -> V_105 != V_106 ) {
F_19 (KERN_ERR PREFIX L_35 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_103 -> V_107 != V_108 ) {
F_19 (KERN_ERR PREFIX L_36 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_103 -> V_109 != V_110 &&
V_103 -> V_109 != V_111 &&
V_103 -> V_109 != V_112 ) {
F_19 (KERN_ERR PREFIX L_37 ) ;
V_51 = - V_57 ;
goto V_58;
}
V_58:
F_25 ( V_48 . V_50 ) ;
return V_51 ;
}
int F_42 (
struct V_113 T_4 * V_16 )
{
int V_56 , V_114 ;
int V_115 = 0 ;
unsigned int V_67 , V_116 ;
T_5 V_117 ;
struct V_7 * V_8 ;
struct V_102 * V_103 ;
struct V_7 * V_118 ;
struct V_102 * V_119 ;
if ( ! F_43 ( & V_117 , V_86 ) )
return - V_87 ;
F_2 ( & V_13 ) ;
F_44 (i) {
V_8 = F_3 ( V_14 , V_67 ) ;
if ( ! V_8 ) {
continue;
}
if ( V_8 -> V_16 ) {
V_115 = - V_96 ;
goto V_120;
}
if ( ! V_16 || ! F_45 ( V_16 , V_67 ) ) {
V_115 = - V_23 ;
goto V_120;
}
}
F_44 (i) {
V_8 = F_3 ( V_14 , V_67 ) ;
if ( ! V_8 )
continue;
V_8 -> V_16 = F_45 ( V_16 , V_67 ) ;
F_46 ( V_67 , V_8 -> V_16 -> V_121 ) ;
if ( F_41 ( V_8 ) ) {
V_115 = - V_23 ;
continue;
}
}
if ( V_115 )
goto V_122;
F_44 (i) {
V_8 = F_3 ( V_14 , V_67 ) ;
if ( ! V_8 )
continue;
if ( F_47 ( V_67 , V_117 ) )
continue;
V_103 = & ( V_8 -> V_16 -> V_104 ) ;
F_46 ( V_67 , V_8 -> V_16 -> V_121 ) ;
F_46 ( V_67 , V_117 ) ;
if ( V_103 -> V_123 <= 1 )
continue;
V_114 = V_103 -> V_123 ;
V_56 = 1 ;
if ( V_103 -> V_109 == V_110 )
V_8 -> V_16 -> V_124 = V_125 ;
else if ( V_103 -> V_109 == V_112 )
V_8 -> V_16 -> V_124 = V_126 ;
else if ( V_103 -> V_109 == V_111 )
V_8 -> V_16 -> V_124 = V_127 ;
F_44 (j) {
if ( V_67 == V_116 )
continue;
V_118 = F_3 ( V_14 , V_116 ) ;
if ( ! V_118 )
continue;
V_119 = & ( V_118 -> V_16 -> V_104 ) ;
if ( V_119 -> V_128 != V_103 -> V_128 )
continue;
if ( V_119 -> V_123 != V_114 ) {
V_115 = - V_23 ;
goto V_122;
}
if ( V_103 -> V_109 != V_119 -> V_109 ) {
V_115 = - V_23 ;
goto V_122;
}
F_46 ( V_116 , V_117 ) ;
F_46 ( V_116 , V_8 -> V_16 -> V_121 ) ;
V_56 ++ ;
}
F_44 (j) {
if ( V_67 == V_116 )
continue;
V_118 = F_3 ( V_14 , V_116 ) ;
if ( ! V_118 )
continue;
V_119 = & ( V_118 -> V_16 -> V_104 ) ;
if ( V_119 -> V_128 != V_103 -> V_128 )
continue;
V_118 -> V_16 -> V_124 =
V_8 -> V_16 -> V_124 ;
F_48 ( V_118 -> V_16 -> V_121 ,
V_8 -> V_16 -> V_121 ) ;
}
}
V_122:
F_44 (i) {
V_8 = F_3 ( V_14 , V_67 ) ;
if ( ! V_8 || ! V_8 -> V_16 )
continue;
if ( V_115 ) {
F_49 ( V_8 -> V_16 -> V_121 ) ;
F_46 ( V_67 , V_8 -> V_16 -> V_121 ) ;
V_8 -> V_16 -> V_124 = V_125 ;
}
V_8 -> V_16 = NULL ;
}
V_120:
F_5 ( & V_13 ) ;
F_50 ( V_117 ) ;
return V_115 ;
}
int
F_51 ( struct V_113
* V_16 , unsigned int V_15 )
{
struct V_7 * V_8 ;
if ( ! ( V_26 & V_44 ) )
return - V_23 ;
F_2 ( & V_13 ) ;
V_8 = F_3 ( V_14 , V_15 ) ;
if ( ! V_8 ) {
F_5 ( & V_13 ) ;
return - V_29 ;
}
if ( V_8 -> V_16 ) {
F_5 ( & V_13 ) ;
return - V_96 ;
}
F_52 ( ! V_16 ) ;
V_8 -> V_16 = V_16 ;
if ( F_33 ( V_8 ) ) {
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return - V_97 ;
}
F_5 ( & V_13 ) ;
return 0 ;
}
void
F_53 ( struct V_113
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
