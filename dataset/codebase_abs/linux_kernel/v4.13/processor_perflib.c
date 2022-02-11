static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_8 ;
unsigned int V_9 = 0 ;
if ( V_10 < 0 )
V_10 = 0 ;
if ( V_10 )
return 0 ;
if ( V_3 != V_11 )
return 0 ;
F_2 ( & V_12 ) ;
V_8 = F_3 ( V_13 , V_6 -> V_14 ) ;
if ( ! V_8 || ! V_8 -> V_15 )
goto V_16;
V_9 = ( unsigned int ) V_8 -> V_17 ;
if ( V_9 >= V_8 -> V_15 -> V_18 )
goto V_16;
F_4 ( V_6 , 0 ,
V_8 -> V_15 -> V_19 [ V_9 ] .
V_20 * 1000 ) ;
V_16:
F_5 ( & V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
T_1 V_21 = 0 ;
unsigned long long V_9 = 0 ;
if ( ! V_8 )
return - V_22 ;
V_21 = F_7 ( V_8 -> V_23 , L_1 , NULL , & V_9 ) ;
if ( V_21 != V_24 )
V_25 |= V_26 ;
if ( F_8 ( V_21 ) && V_21 != V_24 ) {
F_9 ( ( V_27 , V_21 , L_2 ) ) ;
return - V_28 ;
}
F_10 ( L_3 , V_8 -> V_29 ,
( int ) V_9 , V_9 ? L_4 : L_5 ) ;
V_8 -> V_17 = ( int ) V_9 ;
return 0 ;
}
static void F_11 ( T_2 V_23 , int V_21 )
{
if ( F_12 ( V_23 , L_6 ) )
F_13 ( V_23 , V_30 ,
V_21 , NULL ) ;
}
void F_14 ( struct V_7 * V_8 , int V_31 )
{
int V_32 ;
if ( V_10 ) {
if ( V_31 )
F_11 ( V_8 -> V_23 , 1 ) ;
return;
}
V_32 = F_6 ( V_8 ) ;
if ( V_31 ) {
if ( V_32 < 0 )
F_11 ( V_8 -> V_23 , 1 ) ;
else
F_11 ( V_8 -> V_23 , 0 ) ;
}
if ( V_32 >= 0 )
F_15 ( V_8 -> V_29 ) ;
}
int F_16 ( int V_14 , unsigned int * V_33 )
{
struct V_7 * V_8 ;
V_8 = F_3 ( V_13 , V_14 ) ;
if ( ! V_8 || ! V_8 -> V_15 || ! V_8 -> V_15 -> V_18 )
return - V_28 ;
* V_33 = V_8 -> V_15 -> V_19 [ V_8 -> V_17 ] .
V_20 * 1000 ;
return 0 ;
}
void F_17 ( void )
{
if ( ! F_18
( & V_34 , V_35 ) )
V_25 |= V_36 ;
else
F_19 ( V_37
L_7 ) ;
}
void F_20 ( void )
{
if ( V_25 & V_36 )
F_21 ( & V_34 ,
V_35 ) ;
V_25 &= ~ V_36 ;
}
static int F_22 ( struct V_7 * V_8 )
{
int V_38 = 0 ;
T_1 V_21 = 0 ;
struct V_39 V_40 = { V_41 , NULL } ;
union V_42 * V_43 = NULL ;
union V_42 V_44 = { 0 } ;
V_21 = F_23 ( V_8 -> V_23 , L_8 , NULL , & V_40 ) ;
if ( F_8 ( V_21 ) ) {
F_9 ( ( V_27 , V_21 , L_9 ) ) ;
return - V_28 ;
}
V_43 = (union V_42 * ) V_40 . V_45 ;
if ( ! V_43 || ( V_43 -> type != V_46 )
|| ( V_43 -> V_47 . V_48 != 2 ) ) {
F_19 (KERN_ERR PREFIX L_10 ) ;
V_38 = - V_49 ;
goto V_50;
}
V_44 = V_43 -> V_47 . V_51 [ 0 ] ;
if ( ( V_44 . type != V_52 )
|| ( V_44 . V_40 . V_53 < sizeof( struct V_54 ) )
|| ( V_44 . V_40 . V_45 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_11 ) ;
V_38 = - V_49 ;
goto V_50;
}
memcpy ( & V_8 -> V_15 -> V_55 , V_44 . V_40 . V_45 ,
sizeof( struct V_54 ) ) ;
V_44 = V_43 -> V_47 . V_51 [ 1 ] ;
if ( ( V_44 . type != V_52 )
|| ( V_44 . V_40 . V_53 < sizeof( struct V_54 ) )
|| ( V_44 . V_40 . V_45 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_12 ) ;
V_38 = - V_49 ;
goto V_50;
}
memcpy ( & V_8 -> V_15 -> V_56 , V_44 . V_40 . V_45 ,
sizeof( struct V_54 ) ) ;
V_50:
F_24 ( V_40 . V_45 ) ;
return V_38 ;
}
static void F_25 ( struct V_57 * V_58 , int V_59 )
{
T_3 V_60 , V_61 , V_62 , V_63 ;
int V_64 = V_58 -> V_65 & 0x00000007 ;
if ( V_66 . V_67 != V_68 )
return;
if ( ( V_66 . V_69 == 0x10 && V_66 . V_70 < 10 )
|| V_66 . V_69 == 0x11 ) {
F_26 ( V_71 + V_64 , V_61 , V_60 ) ;
if ( ! ( V_60 & F_27 ( 31 ) ) )
return;
V_62 = V_61 & 0x3f ;
V_63 = ( V_61 >> 6 ) & 7 ;
if ( V_66 . V_69 == 0x10 )
V_58 -> V_20 = ( 100 * ( V_62 + 0x10 ) ) >> V_63 ;
else
V_58 -> V_20 = ( 100 * ( V_62 + 8 ) ) >> V_63 ;
}
}
static void F_25 ( struct V_57 * V_58 , int V_59 ) {}
static int F_28 ( struct V_7 * V_8 )
{
int V_38 = 0 ;
T_1 V_21 = V_72 ;
struct V_39 V_40 = { V_41 , NULL } ;
struct V_39 V_73 = { sizeof( L_13 ) , L_13 } ;
struct V_39 V_74 = { 0 , NULL } ;
union V_42 * V_75 = NULL ;
int V_59 ;
int V_76 = - 1 ;
V_21 = F_23 ( V_8 -> V_23 , L_14 , NULL , & V_40 ) ;
if ( F_8 ( V_21 ) ) {
F_9 ( ( V_27 , V_21 , L_15 ) ) ;
return - V_28 ;
}
V_75 = V_40 . V_45 ;
if ( ! V_75 || ( V_75 -> type != V_46 ) ) {
F_19 (KERN_ERR PREFIX L_16 ) ;
V_38 = - V_49 ;
goto V_50;
}
F_29 ( ( V_77 , L_17 ,
V_75 -> V_47 . V_48 ) ) ;
V_8 -> V_15 -> V_18 = V_75 -> V_47 . V_48 ;
V_8 -> V_15 -> V_19 =
F_30 ( sizeof( struct V_57 ) * V_75 -> V_47 . V_48 ,
V_78 ) ;
if ( ! V_8 -> V_15 -> V_19 ) {
V_38 = - V_79 ;
goto V_50;
}
for ( V_59 = 0 ; V_59 < V_8 -> V_15 -> V_18 ; V_59 ++ ) {
struct V_57 * V_58 = & ( V_8 -> V_15 -> V_19 [ V_59 ] ) ;
V_74 . V_53 = sizeof( struct V_57 ) ;
V_74 . V_45 = V_58 ;
F_29 ( ( V_77 , L_18 , V_59 ) ) ;
V_21 = F_31 ( & ( V_75 -> V_47 . V_51 [ V_59 ] ) ,
& V_73 , & V_74 ) ;
if ( F_8 ( V_21 ) ) {
F_9 ( ( V_27 , V_21 , L_19 ) ) ;
V_38 = - V_49 ;
F_24 ( V_8 -> V_15 -> V_19 ) ;
goto V_50;
}
F_25 ( V_58 , V_59 ) ;
F_29 ( ( V_77 ,
L_20 ,
V_59 ,
( T_3 ) V_58 -> V_20 ,
( T_3 ) V_58 -> V_80 ,
( T_3 ) V_58 -> V_81 ,
( T_3 ) V_58 -> V_82 ,
( T_3 ) V_58 -> V_65 , ( T_3 ) V_58 -> V_21 ) ) ;
if ( ! V_58 -> V_20 ||
( ( T_3 ) ( V_58 -> V_20 * 1000 ) !=
( V_58 -> V_20 * 1000 ) ) ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_21 ,
pr->id, px->core_frequency) ;
if ( V_76 == - 1 )
V_76 = V_59 ;
} else {
if ( V_76 != - 1 ) {
memcpy ( & ( V_8 -> V_15 -> V_19 [ V_76 ] ) ,
V_58 , sizeof( struct V_57 ) ) ;
++ V_76 ;
}
}
}
if ( V_76 == 0 ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_22 , pr->id) ;
V_38 = - V_49 ;
F_24 ( V_8 -> V_15 -> V_19 ) ;
V_8 -> V_15 -> V_19 = NULL ;
}
if ( V_76 > 0 )
V_8 -> V_15 -> V_18 = V_76 ;
V_50:
F_24 ( V_40 . V_45 ) ;
return V_38 ;
}
int F_32 ( struct V_7 * V_8 )
{
int V_38 = 0 ;
if ( ! V_8 || ! V_8 -> V_15 || ! V_8 -> V_23 )
return - V_22 ;
if ( ! F_12 ( V_8 -> V_23 , L_8 ) ) {
F_29 ( ( V_77 ,
L_23 ) ) ;
return - V_28 ;
}
V_38 = F_22 ( V_8 ) ;
if ( V_38 )
goto V_83;
V_38 = F_28 ( V_8 ) ;
if ( V_38 )
goto V_83;
if ( V_10 != 1 )
V_38 = F_6 ( V_8 ) ;
return V_38 ;
V_83:
#ifdef F_33
if ( F_12 ( V_8 -> V_23 , L_1 ) ) {
if( F_34 ( V_84 ) )
F_19 (KERN_WARNING FW_BUG L_24
L_25 ) ;
}
#endif
return V_38 ;
}
int F_35 ( void )
{
T_1 V_21 ;
if ( ! V_85 . V_86 || ! V_85 . V_87 )
return 0 ;
F_29 ( ( V_77 ,
L_26 ,
V_85 . V_87 , V_85 . V_86 ) ) ;
V_21 = F_36 ( V_85 . V_86 ,
( T_3 ) V_85 . V_87 , 8 ) ;
if ( F_37 ( V_21 ) )
return 1 ;
F_9 ( ( V_27 , V_21 ,
L_27 ,
V_85 . V_87 , V_85 . V_86 ) ) ;
return - V_88 ;
}
int F_38 ( struct V_89 * V_90 )
{
static int V_91 = 0 ;
int V_38 ;
if ( ! ( V_25 & V_36 ) )
return - V_92 ;
if ( ! F_39 ( V_90 ) )
return - V_22 ;
if ( V_91 > 0 ) {
F_40 ( V_90 ) ;
return 0 ;
} else if ( V_91 < 0 ) {
F_40 ( V_90 ) ;
return V_91 ;
}
V_91 = - V_88 ;
V_38 = F_35 () ;
if ( ! V_38 ) {
F_29 ( ( V_77 , L_28 ) ) ;
F_40 ( V_90 ) ;
return 0 ;
}
if ( V_38 < 0 ) {
F_40 ( V_90 ) ;
return V_38 ;
}
V_91 = 1 ;
if ( ! ( V_25 & V_26 ) )
F_40 ( V_90 ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 )
{
int V_38 = 0 ;
T_1 V_21 = V_72 ;
struct V_39 V_40 = { V_41 , NULL } ;
struct V_39 V_73 = { sizeof( L_29 ) , L_29 } ;
struct V_39 V_74 = { 0 , NULL } ;
union V_42 * V_93 = NULL ;
struct V_94 * V_95 ;
V_21 = F_23 ( V_8 -> V_23 , L_30 , NULL , & V_40 ) ;
if ( F_8 ( V_21 ) ) {
return - V_28 ;
}
V_93 = V_40 . V_45 ;
if ( ! V_93 || ( V_93 -> type != V_46 ) ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_38 = - V_49 ;
goto V_50;
}
if ( V_93 -> V_47 . V_48 != 1 ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_38 = - V_49 ;
goto V_50;
}
V_95 = & ( V_8 -> V_15 -> V_96 ) ;
V_74 . V_53 = sizeof( struct V_94 ) ;
V_74 . V_45 = V_95 ;
V_21 = F_31 ( & ( V_93 -> V_47 . V_51 [ 0 ] ) ,
& V_73 , & V_74 ) ;
if ( F_8 ( V_21 ) ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_38 = - V_49 ;
goto V_50;
}
if ( V_95 -> V_97 != V_98 ) {
F_19 (KERN_ERR PREFIX L_32 ) ;
V_38 = - V_49 ;
goto V_50;
}
if ( V_95 -> V_99 != V_100 ) {
F_19 (KERN_ERR PREFIX L_33 ) ;
V_38 = - V_49 ;
goto V_50;
}
if ( V_95 -> V_101 != V_102 &&
V_95 -> V_101 != V_103 &&
V_95 -> V_101 != V_104 ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_38 = - V_49 ;
goto V_50;
}
V_50:
F_24 ( V_40 . V_45 ) ;
return V_38 ;
}
int F_42 (
struct V_105 T_4 * V_15 )
{
int V_106 ;
int V_107 = 0 ;
unsigned int V_59 , V_108 ;
T_5 V_109 ;
struct V_7 * V_8 ;
struct V_94 * V_95 ;
struct V_7 * V_110 ;
struct V_94 * V_111 ;
if ( ! F_43 ( & V_109 , V_78 ) )
return - V_79 ;
F_2 ( & V_12 ) ;
F_44 (i) {
V_8 = F_3 ( V_13 , V_59 ) ;
if ( ! V_8 ) {
continue;
}
if ( V_8 -> V_15 ) {
V_107 = - V_92 ;
goto V_112;
}
if ( ! V_15 || ! F_45 ( V_15 , V_59 ) ) {
V_107 = - V_22 ;
goto V_112;
}
}
F_44 (i) {
V_8 = F_3 ( V_13 , V_59 ) ;
if ( ! V_8 )
continue;
V_8 -> V_15 = F_45 ( V_15 , V_59 ) ;
F_46 ( V_59 , V_8 -> V_15 -> V_113 ) ;
if ( F_41 ( V_8 ) ) {
V_107 = - V_22 ;
continue;
}
}
if ( V_107 )
goto V_114;
F_44 (i) {
V_8 = F_3 ( V_13 , V_59 ) ;
if ( ! V_8 )
continue;
if ( F_47 ( V_59 , V_109 ) )
continue;
V_95 = & ( V_8 -> V_15 -> V_96 ) ;
F_46 ( V_59 , V_8 -> V_15 -> V_113 ) ;
F_46 ( V_59 , V_109 ) ;
if ( V_95 -> V_115 <= 1 )
continue;
V_106 = V_95 -> V_115 ;
if ( V_95 -> V_101 == V_102 )
V_8 -> V_15 -> V_116 = V_117 ;
else if ( V_95 -> V_101 == V_104 )
V_8 -> V_15 -> V_116 = V_118 ;
else if ( V_95 -> V_101 == V_103 )
V_8 -> V_15 -> V_116 = V_119 ;
F_44 (j) {
if ( V_59 == V_108 )
continue;
V_110 = F_3 ( V_13 , V_108 ) ;
if ( ! V_110 )
continue;
V_111 = & ( V_110 -> V_15 -> V_96 ) ;
if ( V_111 -> V_120 != V_95 -> V_120 )
continue;
if ( V_111 -> V_115 != V_106 ) {
V_107 = - V_22 ;
goto V_114;
}
if ( V_95 -> V_101 != V_111 -> V_101 ) {
V_107 = - V_22 ;
goto V_114;
}
F_46 ( V_108 , V_109 ) ;
F_46 ( V_108 , V_8 -> V_15 -> V_113 ) ;
}
F_44 (j) {
if ( V_59 == V_108 )
continue;
V_110 = F_3 ( V_13 , V_108 ) ;
if ( ! V_110 )
continue;
V_111 = & ( V_110 -> V_15 -> V_96 ) ;
if ( V_111 -> V_120 != V_95 -> V_120 )
continue;
V_110 -> V_15 -> V_116 =
V_8 -> V_15 -> V_116 ;
F_48 ( V_110 -> V_15 -> V_113 ,
V_8 -> V_15 -> V_113 ) ;
}
}
V_114:
F_44 (i) {
V_8 = F_3 ( V_13 , V_59 ) ;
if ( ! V_8 || ! V_8 -> V_15 )
continue;
if ( V_107 ) {
F_49 ( V_8 -> V_15 -> V_113 ) ;
F_46 ( V_59 , V_8 -> V_15 -> V_113 ) ;
V_8 -> V_15 -> V_116 = V_117 ;
}
V_8 -> V_15 = NULL ;
}
V_112:
F_5 ( & V_12 ) ;
F_50 ( V_109 ) ;
return V_107 ;
}
int
F_51 ( struct V_105
* V_15 , unsigned int V_14 )
{
struct V_7 * V_8 ;
if ( ! ( V_25 & V_36 ) )
return - V_22 ;
F_2 ( & V_12 ) ;
V_8 = F_3 ( V_13 , V_14 ) ;
if ( ! V_8 ) {
F_5 ( & V_12 ) ;
return - V_28 ;
}
if ( V_8 -> V_15 ) {
F_5 ( & V_12 ) ;
return - V_92 ;
}
F_52 ( ! V_15 ) ;
V_8 -> V_15 = V_15 ;
if ( F_32 ( V_8 ) ) {
V_8 -> V_15 = NULL ;
F_5 ( & V_12 ) ;
return - V_88 ;
}
F_5 ( & V_12 ) ;
return 0 ;
}
void F_53 ( unsigned int V_14 )
{
struct V_7 * V_8 ;
F_2 ( & V_12 ) ;
V_8 = F_3 ( V_13 , V_14 ) ;
if ( ! V_8 ) {
F_5 ( & V_12 ) ;
return;
}
if ( V_8 -> V_15 )
F_24 ( V_8 -> V_15 -> V_19 ) ;
V_8 -> V_15 = NULL ;
F_5 ( & V_12 ) ;
return;
}
