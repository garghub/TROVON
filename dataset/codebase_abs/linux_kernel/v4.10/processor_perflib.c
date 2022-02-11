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
if ( F_12 ( V_24 , L_6 ) )
F_13 ( V_24 , V_31 ,
V_22 , NULL ) ;
}
void F_14 ( struct V_7 * V_8 , int V_32 )
{
int V_33 ;
if ( V_11 ) {
if ( V_32 )
F_11 ( V_8 -> V_24 , 1 ) ;
return;
}
V_33 = F_6 ( V_8 ) ;
if ( V_32 ) {
if ( V_33 < 0 )
F_11 ( V_8 -> V_24 , 1 ) ;
else
F_11 ( V_8 -> V_24 , 0 ) ;
}
if ( V_33 >= 0 )
F_15 ( V_8 -> V_30 ) ;
}
int F_16 ( int V_15 , unsigned int * V_34 )
{
struct V_7 * V_8 ;
V_8 = F_3 ( V_14 , V_15 ) ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_16 -> V_19 )
return - V_29 ;
* V_34 = V_8 -> V_16 -> V_20 [ V_8 -> V_18 ] .
V_21 * 1000 ;
return 0 ;
}
void F_17 ( void )
{
if ( ! F_18
( & V_35 , V_36 ) )
V_26 |= V_37 ;
else
F_19 ( V_38
L_7 ) ;
}
void F_20 ( void )
{
if ( V_26 & V_37 )
F_21 ( & V_35 ,
V_36 ) ;
V_26 &= ~ V_37 ;
}
static int F_22 ( struct V_7 * V_8 )
{
int V_39 = 0 ;
T_1 V_22 = 0 ;
struct V_40 V_41 = { V_42 , NULL } ;
union V_43 * V_44 = NULL ;
union V_43 V_45 = { 0 } ;
V_22 = F_23 ( V_8 -> V_24 , L_8 , NULL , & V_41 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_9 ) ) ;
return - V_29 ;
}
V_44 = (union V_43 * ) V_41 . V_46 ;
if ( ! V_44 || ( V_44 -> type != V_47 )
|| ( V_44 -> V_48 . V_49 != 2 ) ) {
F_19 (KERN_ERR PREFIX L_10 ) ;
V_39 = - V_50 ;
goto V_51;
}
V_45 = V_44 -> V_48 . V_52 [ 0 ] ;
if ( ( V_45 . type != V_53 )
|| ( V_45 . V_41 . V_54 < sizeof( struct V_55 ) )
|| ( V_45 . V_41 . V_46 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_11 ) ;
V_39 = - V_50 ;
goto V_51;
}
memcpy ( & V_8 -> V_16 -> V_56 , V_45 . V_41 . V_46 ,
sizeof( struct V_55 ) ) ;
V_45 = V_44 -> V_48 . V_52 [ 1 ] ;
if ( ( V_45 . type != V_53 )
|| ( V_45 . V_41 . V_54 < sizeof( struct V_55 ) )
|| ( V_45 . V_41 . V_46 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_12 ) ;
V_39 = - V_50 ;
goto V_51;
}
memcpy ( & V_8 -> V_16 -> V_57 , V_45 . V_41 . V_46 ,
sizeof( struct V_55 ) ) ;
V_51:
F_24 ( V_41 . V_46 ) ;
return V_39 ;
}
static void F_25 ( struct V_58 * V_59 , int V_60 )
{
T_3 V_61 , V_62 , V_63 , V_64 ;
int V_65 = V_59 -> V_66 & 0x00000007 ;
if ( V_67 . V_68 != V_69 )
return;
if ( ( V_67 . V_70 == 0x10 && V_67 . V_71 < 10 )
|| V_67 . V_70 == 0x11 ) {
F_26 ( V_72 + V_65 , V_62 , V_61 ) ;
if ( ! ( V_61 & F_27 ( 31 ) ) )
return;
V_63 = V_62 & 0x3f ;
V_64 = ( V_62 >> 6 ) & 7 ;
if ( V_67 . V_70 == 0x10 )
V_59 -> V_21 = ( 100 * ( V_63 + 0x10 ) ) >> V_64 ;
else
V_59 -> V_21 = ( 100 * ( V_63 + 8 ) ) >> V_64 ;
}
}
static void F_25 ( struct V_58 * V_59 , int V_60 ) {}
static int F_28 ( struct V_7 * V_8 )
{
int V_39 = 0 ;
T_1 V_22 = V_73 ;
struct V_40 V_41 = { V_42 , NULL } ;
struct V_40 V_74 = { sizeof( L_13 ) , L_13 } ;
struct V_40 V_75 = { 0 , NULL } ;
union V_43 * V_76 = NULL ;
int V_60 ;
int V_77 = - 1 ;
V_22 = F_23 ( V_8 -> V_24 , L_14 , NULL , & V_41 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_15 ) ) ;
return - V_29 ;
}
V_76 = V_41 . V_46 ;
if ( ! V_76 || ( V_76 -> type != V_47 ) ) {
F_19 (KERN_ERR PREFIX L_16 ) ;
V_39 = - V_50 ;
goto V_51;
}
F_29 ( ( V_78 , L_17 ,
V_76 -> V_48 . V_49 ) ) ;
V_8 -> V_16 -> V_19 = V_76 -> V_48 . V_49 ;
V_8 -> V_16 -> V_20 =
F_30 ( sizeof( struct V_58 ) * V_76 -> V_48 . V_49 ,
V_79 ) ;
if ( ! V_8 -> V_16 -> V_20 ) {
V_39 = - V_80 ;
goto V_51;
}
for ( V_60 = 0 ; V_60 < V_8 -> V_16 -> V_19 ; V_60 ++ ) {
struct V_58 * V_59 = & ( V_8 -> V_16 -> V_20 [ V_60 ] ) ;
V_75 . V_54 = sizeof( struct V_58 ) ;
V_75 . V_46 = V_59 ;
F_29 ( ( V_78 , L_18 , V_60 ) ) ;
V_22 = F_31 ( & ( V_76 -> V_48 . V_52 [ V_60 ] ) ,
& V_74 , & V_75 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_19 ) ) ;
V_39 = - V_50 ;
F_24 ( V_8 -> V_16 -> V_20 ) ;
goto V_51;
}
F_25 ( V_59 , V_60 ) ;
F_29 ( ( V_78 ,
L_20 ,
V_60 ,
( T_3 ) V_59 -> V_21 ,
( T_3 ) V_59 -> V_81 ,
( T_3 ) V_59 -> V_82 ,
( T_3 ) V_59 -> V_83 ,
( T_3 ) V_59 -> V_66 , ( T_3 ) V_59 -> V_22 ) ) ;
if ( ! V_59 -> V_21 ||
( ( T_3 ) ( V_59 -> V_21 * 1000 ) !=
( V_59 -> V_21 * 1000 ) ) ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_21 ,
pr->id, px->core_frequency) ;
if ( V_77 == - 1 )
V_77 = V_60 ;
} else {
if ( V_77 != - 1 ) {
memcpy ( & ( V_8 -> V_16 -> V_20 [ V_77 ] ) ,
V_59 , sizeof( struct V_58 ) ) ;
++ V_77 ;
}
}
}
if ( V_77 == 0 ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_22 , pr->id) ;
V_39 = - V_50 ;
F_24 ( V_8 -> V_16 -> V_20 ) ;
V_8 -> V_16 -> V_20 = NULL ;
}
if ( V_77 > 0 )
V_8 -> V_16 -> V_19 = V_77 ;
V_51:
F_24 ( V_41 . V_46 ) ;
return V_39 ;
}
int F_32 ( struct V_7 * V_8 )
{
int V_39 = 0 ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_24 )
return - V_23 ;
if ( ! F_12 ( V_8 -> V_24 , L_8 ) ) {
F_29 ( ( V_78 ,
L_23 ) ) ;
return - V_29 ;
}
V_39 = F_22 ( V_8 ) ;
if ( V_39 )
goto V_84;
V_39 = F_28 ( V_8 ) ;
if ( V_39 )
goto V_84;
if ( V_11 != 1 )
V_39 = F_6 ( V_8 ) ;
return V_39 ;
V_84:
#ifdef F_33
if ( F_12 ( V_8 -> V_24 , L_1 ) ) {
if( F_34 ( V_85 ) )
F_19 (KERN_WARNING FW_BUG L_24
L_25 ) ;
}
#endif
return V_39 ;
}
int F_35 ( void )
{
T_1 V_22 ;
if ( ! V_86 . V_87 || ! V_86 . V_88 )
return 0 ;
F_29 ( ( V_78 ,
L_26 ,
V_86 . V_88 , V_86 . V_87 ) ) ;
V_22 = F_36 ( V_86 . V_87 ,
( T_3 ) V_86 . V_88 , 8 ) ;
if ( F_37 ( V_22 ) )
return 1 ;
F_9 ( ( V_28 , V_22 ,
L_27 ,
V_86 . V_88 , V_86 . V_87 ) ) ;
return - V_89 ;
}
int F_38 ( struct V_90 * V_91 )
{
static int V_92 = 0 ;
int V_39 ;
if ( ! ( V_26 & V_37 ) )
return - V_93 ;
if ( ! F_39 ( V_91 ) )
return - V_23 ;
if ( V_92 > 0 ) {
F_40 ( V_91 ) ;
return 0 ;
} else if ( V_92 < 0 ) {
F_40 ( V_91 ) ;
return V_92 ;
}
V_92 = - V_89 ;
V_39 = F_35 () ;
if ( ! V_39 ) {
F_29 ( ( V_78 , L_28 ) ) ;
F_40 ( V_91 ) ;
return 0 ;
}
if ( V_39 < 0 ) {
F_40 ( V_91 ) ;
return V_39 ;
}
V_92 = 1 ;
if ( ! ( V_26 & V_27 ) )
F_40 ( V_91 ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 )
{
int V_39 = 0 ;
T_1 V_22 = V_73 ;
struct V_40 V_41 = { V_42 , NULL } ;
struct V_40 V_74 = { sizeof( L_29 ) , L_29 } ;
struct V_40 V_75 = { 0 , NULL } ;
union V_43 * V_94 = NULL ;
struct V_95 * V_96 ;
V_22 = F_23 ( V_8 -> V_24 , L_30 , NULL , & V_41 ) ;
if ( F_8 ( V_22 ) ) {
return - V_29 ;
}
V_94 = V_41 . V_46 ;
if ( ! V_94 || ( V_94 -> type != V_47 ) ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_39 = - V_50 ;
goto V_51;
}
if ( V_94 -> V_48 . V_49 != 1 ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_39 = - V_50 ;
goto V_51;
}
V_96 = & ( V_8 -> V_16 -> V_97 ) ;
V_75 . V_54 = sizeof( struct V_95 ) ;
V_75 . V_46 = V_96 ;
V_22 = F_31 ( & ( V_94 -> V_48 . V_52 [ 0 ] ) ,
& V_74 , & V_75 ) ;
if ( F_8 ( V_22 ) ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_39 = - V_50 ;
goto V_51;
}
if ( V_96 -> V_98 != V_99 ) {
F_19 (KERN_ERR PREFIX L_32 ) ;
V_39 = - V_50 ;
goto V_51;
}
if ( V_96 -> V_100 != V_101 ) {
F_19 (KERN_ERR PREFIX L_33 ) ;
V_39 = - V_50 ;
goto V_51;
}
if ( V_96 -> V_102 != V_103 &&
V_96 -> V_102 != V_104 &&
V_96 -> V_102 != V_105 ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_39 = - V_50 ;
goto V_51;
}
V_51:
F_24 ( V_41 . V_46 ) ;
return V_39 ;
}
int F_42 (
struct V_106 T_4 * V_16 )
{
int V_107 ;
int V_108 = 0 ;
unsigned int V_60 , V_109 ;
T_5 V_110 ;
struct V_7 * V_8 ;
struct V_95 * V_96 ;
struct V_7 * V_111 ;
struct V_95 * V_112 ;
if ( ! F_43 ( & V_110 , V_79 ) )
return - V_80 ;
F_2 ( & V_13 ) ;
F_44 (i) {
V_8 = F_3 ( V_14 , V_60 ) ;
if ( ! V_8 ) {
continue;
}
if ( V_8 -> V_16 ) {
V_108 = - V_93 ;
goto V_113;
}
if ( ! V_16 || ! F_45 ( V_16 , V_60 ) ) {
V_108 = - V_23 ;
goto V_113;
}
}
F_44 (i) {
V_8 = F_3 ( V_14 , V_60 ) ;
if ( ! V_8 )
continue;
V_8 -> V_16 = F_45 ( V_16 , V_60 ) ;
F_46 ( V_60 , V_8 -> V_16 -> V_114 ) ;
if ( F_41 ( V_8 ) ) {
V_108 = - V_23 ;
continue;
}
}
if ( V_108 )
goto V_115;
F_44 (i) {
V_8 = F_3 ( V_14 , V_60 ) ;
if ( ! V_8 )
continue;
if ( F_47 ( V_60 , V_110 ) )
continue;
V_96 = & ( V_8 -> V_16 -> V_97 ) ;
F_46 ( V_60 , V_8 -> V_16 -> V_114 ) ;
F_46 ( V_60 , V_110 ) ;
if ( V_96 -> V_116 <= 1 )
continue;
V_107 = V_96 -> V_116 ;
if ( V_96 -> V_102 == V_103 )
V_8 -> V_16 -> V_117 = V_118 ;
else if ( V_96 -> V_102 == V_105 )
V_8 -> V_16 -> V_117 = V_119 ;
else if ( V_96 -> V_102 == V_104 )
V_8 -> V_16 -> V_117 = V_120 ;
F_44 (j) {
if ( V_60 == V_109 )
continue;
V_111 = F_3 ( V_14 , V_109 ) ;
if ( ! V_111 )
continue;
V_112 = & ( V_111 -> V_16 -> V_97 ) ;
if ( V_112 -> V_121 != V_96 -> V_121 )
continue;
if ( V_112 -> V_116 != V_107 ) {
V_108 = - V_23 ;
goto V_115;
}
if ( V_96 -> V_102 != V_112 -> V_102 ) {
V_108 = - V_23 ;
goto V_115;
}
F_46 ( V_109 , V_110 ) ;
F_46 ( V_109 , V_8 -> V_16 -> V_114 ) ;
}
F_44 (j) {
if ( V_60 == V_109 )
continue;
V_111 = F_3 ( V_14 , V_109 ) ;
if ( ! V_111 )
continue;
V_112 = & ( V_111 -> V_16 -> V_97 ) ;
if ( V_112 -> V_121 != V_96 -> V_121 )
continue;
V_111 -> V_16 -> V_117 =
V_8 -> V_16 -> V_117 ;
F_48 ( V_111 -> V_16 -> V_114 ,
V_8 -> V_16 -> V_114 ) ;
}
}
V_115:
F_44 (i) {
V_8 = F_3 ( V_14 , V_60 ) ;
if ( ! V_8 || ! V_8 -> V_16 )
continue;
if ( V_108 ) {
F_49 ( V_8 -> V_16 -> V_114 ) ;
F_46 ( V_60 , V_8 -> V_16 -> V_114 ) ;
V_8 -> V_16 -> V_117 = V_118 ;
}
V_8 -> V_16 = NULL ;
}
V_113:
F_5 ( & V_13 ) ;
F_50 ( V_110 ) ;
return V_108 ;
}
int
F_51 ( struct V_106
* V_16 , unsigned int V_15 )
{
struct V_7 * V_8 ;
if ( ! ( V_26 & V_37 ) )
return - V_23 ;
F_2 ( & V_13 ) ;
V_8 = F_3 ( V_14 , V_15 ) ;
if ( ! V_8 ) {
F_5 ( & V_13 ) ;
return - V_29 ;
}
if ( V_8 -> V_16 ) {
F_5 ( & V_13 ) ;
return - V_93 ;
}
F_52 ( ! V_16 ) ;
V_8 -> V_16 = V_16 ;
if ( F_32 ( V_8 ) ) {
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return - V_89 ;
}
F_5 ( & V_13 ) ;
return 0 ;
}
void F_53 ( unsigned int V_15 )
{
struct V_7 * V_8 ;
F_2 ( & V_13 ) ;
V_8 = F_3 ( V_14 , V_15 ) ;
if ( ! V_8 ) {
F_5 ( & V_13 ) ;
return;
}
if ( V_8 -> V_16 )
F_24 ( V_8 -> V_16 -> V_20 ) ;
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return;
}
