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
static int F_22 ( struct V_7 * V_8 )
{
int V_45 = 0 ;
T_1 V_22 = 0 ;
struct V_46 V_47 = { V_48 , NULL } ;
union V_31 * V_49 = NULL ;
union V_31 V_50 = { 0 } ;
V_22 = F_13 ( V_8 -> V_24 , L_8 , NULL , & V_47 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_9 ) ) ;
return - V_29 ;
}
V_49 = (union V_31 * ) V_47 . V_51 ;
if ( ! V_49 || ( V_49 -> type != V_52 )
|| ( V_49 -> V_53 . V_54 != 2 ) ) {
F_19 (KERN_ERR PREFIX L_10 ) ;
V_45 = - V_55 ;
goto V_56;
}
V_50 = V_49 -> V_53 . V_57 [ 0 ] ;
if ( ( V_50 . type != V_58 )
|| ( V_50 . V_47 . V_59 < sizeof( struct V_60 ) )
|| ( V_50 . V_47 . V_51 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_11 ) ;
V_45 = - V_55 ;
goto V_56;
}
memcpy ( & V_8 -> V_16 -> V_61 , V_50 . V_47 . V_51 ,
sizeof( struct V_60 ) ) ;
V_50 = V_49 -> V_53 . V_57 [ 1 ] ;
if ( ( V_50 . type != V_58 )
|| ( V_50 . V_47 . V_59 < sizeof( struct V_60 ) )
|| ( V_50 . V_47 . V_51 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_12 ) ;
V_45 = - V_55 ;
goto V_56;
}
memcpy ( & V_8 -> V_16 -> V_62 , V_50 . V_47 . V_51 ,
sizeof( struct V_60 ) ) ;
V_56:
F_23 ( V_47 . V_51 ) ;
return V_45 ;
}
static void F_24 ( struct V_63 * V_64 , int V_65 )
{
T_3 V_66 , V_67 , V_68 , V_69 ;
int V_70 = V_64 -> V_71 & 0x00000007 ;
if ( V_72 . V_73 != V_74 )
return;
if ( ( V_72 . V_75 == 0x10 && V_72 . V_76 < 10 )
|| V_72 . V_75 == 0x11 ) {
F_25 ( V_77 + V_70 , V_67 , V_66 ) ;
if ( ! ( V_66 & F_26 ( 31 ) ) )
return;
V_68 = V_67 & 0x3f ;
V_69 = ( V_67 >> 6 ) & 7 ;
if ( V_72 . V_75 == 0x10 )
V_64 -> V_21 = ( 100 * ( V_68 + 0x10 ) ) >> V_69 ;
else
V_64 -> V_21 = ( 100 * ( V_68 + 8 ) ) >> V_69 ;
}
}
static void F_24 ( struct V_63 * V_64 , int V_65 ) {}
static int F_27 ( struct V_7 * V_8 )
{
int V_45 = 0 ;
T_1 V_22 = V_78 ;
struct V_46 V_47 = { V_48 , NULL } ;
struct V_46 V_79 = { sizeof( L_13 ) , L_13 } ;
struct V_46 V_80 = { 0 , NULL } ;
union V_31 * V_81 = NULL ;
int V_65 ;
int V_82 = - 1 ;
V_22 = F_13 ( V_8 -> V_24 , L_14 , NULL , & V_47 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_15 ) ) ;
return - V_29 ;
}
V_81 = V_47 . V_51 ;
if ( ! V_81 || ( V_81 -> type != V_52 ) ) {
F_19 (KERN_ERR PREFIX L_16 ) ;
V_45 = - V_55 ;
goto V_56;
}
F_28 ( ( V_83 , L_17 ,
V_81 -> V_53 . V_54 ) ) ;
V_8 -> V_16 -> V_19 = V_81 -> V_53 . V_54 ;
V_8 -> V_16 -> V_20 =
F_29 ( sizeof( struct V_63 ) * V_81 -> V_53 . V_54 ,
V_84 ) ;
if ( ! V_8 -> V_16 -> V_20 ) {
V_45 = - V_85 ;
goto V_56;
}
for ( V_65 = 0 ; V_65 < V_8 -> V_16 -> V_19 ; V_65 ++ ) {
struct V_63 * V_64 = & ( V_8 -> V_16 -> V_20 [ V_65 ] ) ;
V_80 . V_59 = sizeof( struct V_63 ) ;
V_80 . V_51 = V_64 ;
F_28 ( ( V_83 , L_18 , V_65 ) ) ;
V_22 = F_30 ( & ( V_81 -> V_53 . V_57 [ V_65 ] ) ,
& V_79 , & V_80 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_19 ) ) ;
V_45 = - V_55 ;
F_23 ( V_8 -> V_16 -> V_20 ) ;
goto V_56;
}
F_24 ( V_64 , V_65 ) ;
F_28 ( ( V_83 ,
L_20 ,
V_65 ,
( T_3 ) V_64 -> V_21 ,
( T_3 ) V_64 -> V_86 ,
( T_3 ) V_64 -> V_87 ,
( T_3 ) V_64 -> V_88 ,
( T_3 ) V_64 -> V_71 , ( T_3 ) V_64 -> V_22 ) ) ;
if ( ! V_64 -> V_21 ||
( ( T_3 ) ( V_64 -> V_21 * 1000 ) !=
( V_64 -> V_21 * 1000 ) ) ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_21 ,
pr->id, px->core_frequency) ;
if ( V_82 == - 1 )
V_82 = V_65 ;
} else {
if ( V_82 != - 1 ) {
memcpy ( & ( V_8 -> V_16 -> V_20 [ V_82 ] ) ,
V_64 , sizeof( struct V_63 ) ) ;
++ V_82 ;
}
}
}
if ( V_82 == 0 ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_22 , pr->id) ;
V_45 = - V_55 ;
F_23 ( V_8 -> V_16 -> V_20 ) ;
V_8 -> V_16 -> V_20 = NULL ;
}
if ( V_82 > 0 )
V_8 -> V_16 -> V_19 = V_82 ;
V_56:
F_23 ( V_47 . V_51 ) ;
return V_45 ;
}
int F_31 ( struct V_7 * V_8 )
{
int V_45 = 0 ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_24 )
return - V_23 ;
if ( ! F_12 ( V_8 -> V_24 , L_8 ) ) {
F_28 ( ( V_83 ,
L_23 ) ) ;
return - V_29 ;
}
V_45 = F_22 ( V_8 ) ;
if ( V_45 )
goto V_89;
V_45 = F_27 ( V_8 ) ;
if ( V_45 )
goto V_89;
if ( V_11 != 1 )
V_45 = F_6 ( V_8 ) ;
return V_45 ;
V_89:
#ifdef F_32
if ( F_12 ( V_8 -> V_24 , L_1 ) ) {
if( F_33 ( V_90 ) )
F_19 (KERN_WARNING FW_BUG L_24
L_25 ) ;
}
#endif
return V_45 ;
}
int F_34 ( struct V_91 * V_92 )
{
T_1 V_22 ;
static int V_93 = 0 ;
if ( ! ( V_26 & V_43 ) )
return - V_94 ;
if ( ! F_35 ( V_92 ) )
return - V_23 ;
if ( V_93 > 0 ) {
F_36 ( V_92 ) ;
return 0 ;
} else if ( V_93 < 0 ) {
F_36 ( V_92 ) ;
return V_93 ;
}
V_93 = - V_95 ;
if ( ( ! V_96 . V_97 ) || ( ! V_96 . V_98 ) ) {
F_28 ( ( V_83 , L_26 ) ) ;
F_36 ( V_92 ) ;
return 0 ;
}
F_28 ( ( V_83 ,
L_27 ,
V_96 . V_98 , V_96 . V_97 ) ) ;
V_22 = F_37 ( V_96 . V_97 ,
( T_3 ) V_96 . V_98 , 8 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 ,
L_28
L_29 , V_96 . V_98 ,
V_96 . V_97 ) ) ;
F_36 ( V_92 ) ;
return V_22 ;
}
V_93 = 1 ;
if ( ! ( V_26 & V_27 ) )
F_36 ( V_92 ) ;
return 0 ;
}
static int F_38 ( struct V_7 * V_8 )
{
int V_45 = 0 ;
T_1 V_22 = V_78 ;
struct V_46 V_47 = { V_48 , NULL } ;
struct V_46 V_79 = { sizeof( L_30 ) , L_30 } ;
struct V_46 V_80 = { 0 , NULL } ;
union V_31 * V_99 = NULL ;
struct V_100 * V_101 ;
V_22 = F_13 ( V_8 -> V_24 , L_31 , NULL , & V_47 ) ;
if ( F_8 ( V_22 ) ) {
return - V_29 ;
}
V_99 = V_47 . V_51 ;
if ( ! V_99 || ( V_99 -> type != V_52 ) ) {
F_19 (KERN_ERR PREFIX L_32 ) ;
V_45 = - V_55 ;
goto V_56;
}
if ( V_99 -> V_53 . V_54 != 1 ) {
F_19 (KERN_ERR PREFIX L_32 ) ;
V_45 = - V_55 ;
goto V_56;
}
V_101 = & ( V_8 -> V_16 -> V_102 ) ;
V_80 . V_59 = sizeof( struct V_100 ) ;
V_80 . V_51 = V_101 ;
V_22 = F_30 ( & ( V_99 -> V_53 . V_57 [ 0 ] ) ,
& V_79 , & V_80 ) ;
if ( F_8 ( V_22 ) ) {
F_19 (KERN_ERR PREFIX L_32 ) ;
V_45 = - V_55 ;
goto V_56;
}
if ( V_101 -> V_103 != V_104 ) {
F_19 (KERN_ERR PREFIX L_33 ) ;
V_45 = - V_55 ;
goto V_56;
}
if ( V_101 -> V_105 != V_106 ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_45 = - V_55 ;
goto V_56;
}
if ( V_101 -> V_107 != V_108 &&
V_101 -> V_107 != V_109 &&
V_101 -> V_107 != V_110 ) {
F_19 (KERN_ERR PREFIX L_35 ) ;
V_45 = - V_55 ;
goto V_56;
}
V_56:
F_23 ( V_47 . V_51 ) ;
return V_45 ;
}
int F_39 (
struct V_111 T_4 * V_16 )
{
int V_112 ;
int V_113 = 0 ;
unsigned int V_65 , V_114 ;
T_5 V_115 ;
struct V_7 * V_8 ;
struct V_100 * V_101 ;
struct V_7 * V_116 ;
struct V_100 * V_117 ;
if ( ! F_40 ( & V_115 , V_84 ) )
return - V_85 ;
F_2 ( & V_13 ) ;
F_41 (i) {
V_8 = F_3 ( V_14 , V_65 ) ;
if ( ! V_8 ) {
continue;
}
if ( V_8 -> V_16 ) {
V_113 = - V_94 ;
goto V_118;
}
if ( ! V_16 || ! F_42 ( V_16 , V_65 ) ) {
V_113 = - V_23 ;
goto V_118;
}
}
F_41 (i) {
V_8 = F_3 ( V_14 , V_65 ) ;
if ( ! V_8 )
continue;
V_8 -> V_16 = F_42 ( V_16 , V_65 ) ;
F_43 ( V_65 , V_8 -> V_16 -> V_119 ) ;
if ( F_38 ( V_8 ) ) {
V_113 = - V_23 ;
continue;
}
}
if ( V_113 )
goto V_120;
F_41 (i) {
V_8 = F_3 ( V_14 , V_65 ) ;
if ( ! V_8 )
continue;
if ( F_44 ( V_65 , V_115 ) )
continue;
V_101 = & ( V_8 -> V_16 -> V_102 ) ;
F_43 ( V_65 , V_8 -> V_16 -> V_119 ) ;
F_43 ( V_65 , V_115 ) ;
if ( V_101 -> V_121 <= 1 )
continue;
V_112 = V_101 -> V_121 ;
if ( V_101 -> V_107 == V_108 )
V_8 -> V_16 -> V_122 = V_123 ;
else if ( V_101 -> V_107 == V_110 )
V_8 -> V_16 -> V_122 = V_124 ;
else if ( V_101 -> V_107 == V_109 )
V_8 -> V_16 -> V_122 = V_125 ;
F_41 (j) {
if ( V_65 == V_114 )
continue;
V_116 = F_3 ( V_14 , V_114 ) ;
if ( ! V_116 )
continue;
V_117 = & ( V_116 -> V_16 -> V_102 ) ;
if ( V_117 -> V_126 != V_101 -> V_126 )
continue;
if ( V_117 -> V_121 != V_112 ) {
V_113 = - V_23 ;
goto V_120;
}
if ( V_101 -> V_107 != V_117 -> V_107 ) {
V_113 = - V_23 ;
goto V_120;
}
F_43 ( V_114 , V_115 ) ;
F_43 ( V_114 , V_8 -> V_16 -> V_119 ) ;
}
F_41 (j) {
if ( V_65 == V_114 )
continue;
V_116 = F_3 ( V_14 , V_114 ) ;
if ( ! V_116 )
continue;
V_117 = & ( V_116 -> V_16 -> V_102 ) ;
if ( V_117 -> V_126 != V_101 -> V_126 )
continue;
V_116 -> V_16 -> V_122 =
V_8 -> V_16 -> V_122 ;
F_45 ( V_116 -> V_16 -> V_119 ,
V_8 -> V_16 -> V_119 ) ;
}
}
V_120:
F_41 (i) {
V_8 = F_3 ( V_14 , V_65 ) ;
if ( ! V_8 || ! V_8 -> V_16 )
continue;
if ( V_113 ) {
F_46 ( V_8 -> V_16 -> V_119 ) ;
F_43 ( V_65 , V_8 -> V_16 -> V_119 ) ;
V_8 -> V_16 -> V_122 = V_123 ;
}
V_8 -> V_16 = NULL ;
}
V_118:
F_5 ( & V_13 ) ;
F_47 ( V_115 ) ;
return V_113 ;
}
int
F_48 ( struct V_111
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
return - V_94 ;
}
F_49 ( ! V_16 ) ;
V_8 -> V_16 = V_16 ;
if ( F_31 ( V_8 ) ) {
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return - V_95 ;
}
F_5 ( & V_13 ) ;
return 0 ;
}
void
F_50 ( struct V_111
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
F_23 ( V_8 -> V_16 -> V_20 ) ;
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return;
}
