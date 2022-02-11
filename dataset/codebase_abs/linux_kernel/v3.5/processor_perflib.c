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
static int F_27 ( struct V_7 * V_8 )
{
int V_51 = 0 ;
T_1 V_22 = V_65 ;
struct V_47 V_48 = { V_49 , NULL } ;
struct V_47 V_66 = { sizeof( L_15 ) , L_15 } ;
struct V_47 V_67 = { 0 , NULL } ;
union V_31 * V_68 = NULL ;
int V_69 ;
int V_70 = - 1 ;
V_22 = F_13 ( V_8 -> V_24 , L_16 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_17 ) ) ;
return - V_29 ;
}
V_68 = V_48 . V_50 ;
if ( ! V_68 || ( V_68 -> type != V_54 ) ) {
F_19 (KERN_ERR PREFIX L_18 ) ;
V_51 = - V_57 ;
goto V_58;
}
F_28 ( ( V_71 , L_19 ,
V_68 -> V_55 . V_56 ) ) ;
V_8 -> V_16 -> V_19 = V_68 -> V_55 . V_56 ;
V_8 -> V_16 -> V_20 =
F_29 ( sizeof( struct V_72 ) * V_68 -> V_55 . V_56 ,
V_73 ) ;
if ( ! V_8 -> V_16 -> V_20 ) {
V_51 = - V_74 ;
goto V_58;
}
for ( V_69 = 0 ; V_69 < V_8 -> V_16 -> V_19 ; V_69 ++ ) {
struct V_72 * V_75 = & ( V_8 -> V_16 -> V_20 [ V_69 ] ) ;
V_67 . V_61 = sizeof( struct V_72 ) ;
V_67 . V_50 = V_75 ;
F_28 ( ( V_71 , L_20 , V_69 ) ) ;
V_22 = F_30 ( & ( V_68 -> V_55 . V_59 [ V_69 ] ) ,
& V_66 , & V_67 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_21 ) ) ;
V_51 = - V_57 ;
F_25 ( V_8 -> V_16 -> V_20 ) ;
goto V_58;
}
F_28 ( ( V_71 ,
L_22 ,
V_69 ,
( V_76 ) V_75 -> V_21 ,
( V_76 ) V_75 -> V_77 ,
( V_76 ) V_75 -> V_78 ,
( V_76 ) V_75 -> V_79 ,
( V_76 ) V_75 -> V_80 , ( V_76 ) V_75 -> V_22 ) ) ;
if ( ! V_75 -> V_21 ||
( ( V_76 ) ( V_75 -> V_21 * 1000 ) !=
( V_75 -> V_21 * 1000 ) ) ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_23 ,
pr->id, px->core_frequency) ;
if ( V_70 == - 1 )
V_70 = V_69 ;
} else {
if ( V_70 != - 1 ) {
memcpy ( & ( V_8 -> V_16 -> V_20 [ V_70 ] ) ,
V_75 , sizeof( struct V_72 ) ) ;
++ V_70 ;
}
}
}
if ( V_70 == 0 ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_24 , pr->id) ;
V_51 = - V_57 ;
F_25 ( V_8 -> V_16 -> V_20 ) ;
V_8 -> V_16 -> V_20 = NULL ;
}
if ( V_70 > 0 )
V_8 -> V_16 -> V_19 = V_70 ;
V_58:
F_25 ( V_48 . V_50 ) ;
return V_51 ;
}
static int F_31 ( struct V_7 * V_8 )
{
int V_51 = 0 ;
T_1 V_22 = V_65 ;
T_2 V_24 = NULL ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_24 )
return - V_23 ;
V_22 = F_12 ( V_8 -> V_24 , L_8 , & V_24 ) ;
if ( F_8 ( V_22 ) ) {
F_28 ( ( V_71 ,
L_25 ) ) ;
return - V_29 ;
}
V_51 = F_26 ( V_8 ) ;
if ( V_51 )
goto V_81;
V_51 = F_27 ( V_8 ) ;
if ( V_51 )
goto V_81;
if ( V_11 != 1 )
V_51 = F_6 ( V_8 ) ;
return V_51 ;
V_81:
#ifdef F_32
if ( F_33 ( F_12 ( V_8 -> V_24 , L_1 , & V_24 ) ) ) {
if( F_34 ( V_82 ) )
F_19 (KERN_WARNING FW_BUG L_26
L_27 ) ;
}
#endif
return V_51 ;
}
int F_35 ( struct V_83 * V_84 )
{
T_1 V_22 ;
static int V_85 = 0 ;
if ( ! ( V_26 & V_44 ) )
return - V_86 ;
if ( ! F_36 ( V_84 ) )
return - V_23 ;
if ( V_85 > 0 ) {
F_37 ( V_84 ) ;
return 0 ;
} else if ( V_85 < 0 ) {
F_37 ( V_84 ) ;
return V_85 ;
}
V_85 = - V_87 ;
if ( ( ! V_88 . V_89 ) || ( ! V_88 . V_90 ) ) {
F_28 ( ( V_71 , L_28 ) ) ;
F_37 ( V_84 ) ;
return 0 ;
}
F_28 ( ( V_71 ,
L_29 ,
V_88 . V_90 , V_88 . V_89 ) ) ;
V_22 = F_38 ( V_88 . V_89 ,
( V_76 ) V_88 . V_90 , 8 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 ,
L_30
L_31 , V_88 . V_90 ,
V_88 . V_89 ) ) ;
F_37 ( V_84 ) ;
return V_22 ;
}
V_85 = 1 ;
if ( ! ( V_26 & V_27 ) )
F_37 ( V_84 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 )
{
int V_51 = 0 ;
T_1 V_22 = V_65 ;
struct V_47 V_48 = { V_49 , NULL } ;
struct V_47 V_66 = { sizeof( L_32 ) , L_32 } ;
struct V_47 V_67 = { 0 , NULL } ;
union V_31 * V_91 = NULL ;
struct V_92 * V_93 ;
V_22 = F_13 ( V_8 -> V_24 , L_33 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
return - V_29 ;
}
V_91 = V_48 . V_50 ;
if ( ! V_91 || ( V_91 -> type != V_54 ) ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_91 -> V_55 . V_56 != 1 ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_51 = - V_57 ;
goto V_58;
}
V_93 = & ( V_8 -> V_16 -> V_94 ) ;
V_67 . V_61 = sizeof( struct V_92 ) ;
V_67 . V_50 = V_93 ;
V_22 = F_30 ( & ( V_91 -> V_55 . V_59 [ 0 ] ) ,
& V_66 , & V_67 ) ;
if ( F_8 ( V_22 ) ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_93 -> V_95 != V_96 ) {
F_19 (KERN_ERR PREFIX L_35 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_93 -> V_97 != V_98 ) {
F_19 (KERN_ERR PREFIX L_36 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_93 -> V_99 != V_100 &&
V_93 -> V_99 != V_101 &&
V_93 -> V_99 != V_102 ) {
F_19 (KERN_ERR PREFIX L_37 ) ;
V_51 = - V_57 ;
goto V_58;
}
V_58:
F_25 ( V_48 . V_50 ) ;
return V_51 ;
}
int F_40 (
struct V_103 T_3 * V_16 )
{
int V_56 , V_104 ;
int V_105 = 0 ;
unsigned int V_69 , V_106 ;
T_4 V_107 ;
struct V_7 * V_8 ;
struct V_92 * V_93 ;
struct V_7 * V_108 ;
struct V_92 * V_109 ;
if ( ! F_41 ( & V_107 , V_73 ) )
return - V_74 ;
F_2 ( & V_13 ) ;
F_42 (i) {
V_8 = F_3 ( V_14 , V_69 ) ;
if ( ! V_8 ) {
continue;
}
if ( V_8 -> V_16 ) {
V_105 = - V_86 ;
goto V_110;
}
if ( ! V_16 || ! F_43 ( V_16 , V_69 ) ) {
V_105 = - V_23 ;
goto V_110;
}
}
F_42 (i) {
V_8 = F_3 ( V_14 , V_69 ) ;
if ( ! V_8 )
continue;
V_8 -> V_16 = F_43 ( V_16 , V_69 ) ;
F_44 ( V_69 , V_8 -> V_16 -> V_111 ) ;
if ( F_39 ( V_8 ) ) {
V_105 = - V_23 ;
continue;
}
}
if ( V_105 )
goto V_112;
F_42 (i) {
V_8 = F_3 ( V_14 , V_69 ) ;
if ( ! V_8 )
continue;
if ( F_45 ( V_69 , V_107 ) )
continue;
V_93 = & ( V_8 -> V_16 -> V_94 ) ;
F_44 ( V_69 , V_8 -> V_16 -> V_111 ) ;
F_44 ( V_69 , V_107 ) ;
if ( V_93 -> V_113 <= 1 )
continue;
V_104 = V_93 -> V_113 ;
V_56 = 1 ;
if ( V_93 -> V_99 == V_100 )
V_8 -> V_16 -> V_114 = V_115 ;
else if ( V_93 -> V_99 == V_102 )
V_8 -> V_16 -> V_114 = V_116 ;
else if ( V_93 -> V_99 == V_101 )
V_8 -> V_16 -> V_114 = V_117 ;
F_42 (j) {
if ( V_69 == V_106 )
continue;
V_108 = F_3 ( V_14 , V_106 ) ;
if ( ! V_108 )
continue;
V_109 = & ( V_108 -> V_16 -> V_94 ) ;
if ( V_109 -> V_118 != V_93 -> V_118 )
continue;
if ( V_109 -> V_113 != V_104 ) {
V_105 = - V_23 ;
goto V_112;
}
if ( V_93 -> V_99 != V_109 -> V_99 ) {
V_105 = - V_23 ;
goto V_112;
}
F_44 ( V_106 , V_107 ) ;
F_44 ( V_106 , V_8 -> V_16 -> V_111 ) ;
V_56 ++ ;
}
F_42 (j) {
if ( V_69 == V_106 )
continue;
V_108 = F_3 ( V_14 , V_106 ) ;
if ( ! V_108 )
continue;
V_109 = & ( V_108 -> V_16 -> V_94 ) ;
if ( V_109 -> V_118 != V_93 -> V_118 )
continue;
V_108 -> V_16 -> V_114 =
V_8 -> V_16 -> V_114 ;
F_46 ( V_108 -> V_16 -> V_111 ,
V_8 -> V_16 -> V_111 ) ;
}
}
V_112:
F_42 (i) {
V_8 = F_3 ( V_14 , V_69 ) ;
if ( ! V_8 || ! V_8 -> V_16 )
continue;
if ( V_105 ) {
F_47 ( V_8 -> V_16 -> V_111 ) ;
F_44 ( V_69 , V_8 -> V_16 -> V_111 ) ;
V_8 -> V_16 -> V_114 = V_115 ;
}
V_8 -> V_16 = NULL ;
}
V_110:
F_5 ( & V_13 ) ;
F_48 ( V_107 ) ;
return V_105 ;
}
int
F_49 ( struct V_103
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
return - V_86 ;
}
F_50 ( ! V_16 ) ;
V_8 -> V_16 = V_16 ;
if ( F_31 ( V_8 ) ) {
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return - V_87 ;
}
F_5 ( & V_13 ) ;
return 0 ;
}
void
F_51 ( struct V_103
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
