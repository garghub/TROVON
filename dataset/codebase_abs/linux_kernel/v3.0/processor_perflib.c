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
static int F_22 ( struct V_7 * V_8 )
{
int V_46 = 0 ;
T_1 V_22 = 0 ;
struct V_47 V_48 = { V_49 , NULL } ;
union V_31 * V_50 = NULL ;
union V_31 V_51 = { 0 } ;
V_22 = F_13 ( V_8 -> V_24 , L_8 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_9 ) ) ;
return - V_29 ;
}
V_50 = (union V_31 * ) V_48 . V_52 ;
if ( ! V_50 || ( V_50 -> type != V_53 )
|| ( V_50 -> V_54 . V_55 != 2 ) ) {
F_19 (KERN_ERR PREFIX L_10 ) ;
V_46 = - V_56 ;
goto V_57;
}
V_51 = V_50 -> V_54 . V_58 [ 0 ] ;
if ( ( V_51 . type != V_59 )
|| ( V_51 . V_48 . V_60 < sizeof( struct V_61 ) )
|| ( V_51 . V_48 . V_52 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_11 ) ;
V_46 = - V_56 ;
goto V_57;
}
memcpy ( & V_8 -> V_16 -> V_62 , V_51 . V_48 . V_52 ,
sizeof( struct V_61 ) ) ;
V_51 = V_50 -> V_54 . V_58 [ 1 ] ;
if ( ( V_51 . type != V_59 )
|| ( V_51 . V_48 . V_60 < sizeof( struct V_61 ) )
|| ( V_51 . V_48 . V_52 == NULL ) ) {
F_19 (KERN_ERR PREFIX L_12 ) ;
V_46 = - V_56 ;
goto V_57;
}
memcpy ( & V_8 -> V_16 -> V_63 , V_51 . V_48 . V_52 ,
sizeof( struct V_61 ) ) ;
V_57:
F_23 ( V_48 . V_52 ) ;
return V_46 ;
}
static int F_24 ( struct V_7 * V_8 )
{
int V_46 = 0 ;
T_1 V_22 = V_64 ;
struct V_47 V_48 = { V_49 , NULL } ;
struct V_47 V_65 = { sizeof( L_13 ) , L_13 } ;
struct V_47 V_66 = { 0 , NULL } ;
union V_31 * V_67 = NULL ;
int V_68 ;
V_22 = F_13 ( V_8 -> V_24 , L_14 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_15 ) ) ;
return - V_29 ;
}
V_67 = V_48 . V_52 ;
if ( ! V_67 || ( V_67 -> type != V_53 ) ) {
F_19 (KERN_ERR PREFIX L_16 ) ;
V_46 = - V_56 ;
goto V_57;
}
F_25 ( ( V_69 , L_17 ,
V_67 -> V_54 . V_55 ) ) ;
V_8 -> V_16 -> V_19 = V_67 -> V_54 . V_55 ;
V_8 -> V_16 -> V_20 =
F_26 ( sizeof( struct V_70 ) * V_67 -> V_54 . V_55 ,
V_71 ) ;
if ( ! V_8 -> V_16 -> V_20 ) {
V_46 = - V_72 ;
goto V_57;
}
for ( V_68 = 0 ; V_68 < V_8 -> V_16 -> V_19 ; V_68 ++ ) {
struct V_70 * V_73 = & ( V_8 -> V_16 -> V_20 [ V_68 ] ) ;
V_66 . V_60 = sizeof( struct V_70 ) ;
V_66 . V_52 = V_73 ;
F_25 ( ( V_69 , L_18 , V_68 ) ) ;
V_22 = F_27 ( & ( V_67 -> V_54 . V_58 [ V_68 ] ) ,
& V_65 , & V_66 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_19 ) ) ;
V_46 = - V_56 ;
F_23 ( V_8 -> V_16 -> V_20 ) ;
goto V_57;
}
F_25 ( ( V_69 ,
L_20 ,
V_68 ,
( V_74 ) V_73 -> V_21 ,
( V_74 ) V_73 -> V_75 ,
( V_74 ) V_73 -> V_76 ,
( V_74 ) V_73 -> V_77 ,
( V_74 ) V_73 -> V_78 , ( V_74 ) V_73 -> V_22 ) ) ;
if ( ! V_73 -> V_21 ||
( ( V_74 ) ( V_73 -> V_21 * 1000 ) !=
( V_73 -> V_21 * 1000 ) ) ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_21 ,
px->core_frequency) ;
V_46 = - V_56 ;
F_23 ( V_8 -> V_16 -> V_20 ) ;
goto V_57;
}
}
V_57:
F_23 ( V_48 . V_52 ) ;
return V_46 ;
}
static int F_28 ( struct V_7 * V_8 )
{
int V_46 = 0 ;
T_1 V_22 = V_64 ;
T_2 V_24 = NULL ;
if ( ! V_8 || ! V_8 -> V_16 || ! V_8 -> V_24 )
return - V_23 ;
V_22 = F_12 ( V_8 -> V_24 , L_8 , & V_24 ) ;
if ( F_8 ( V_22 ) ) {
F_25 ( ( V_69 ,
L_22 ) ) ;
return - V_29 ;
}
V_46 = F_22 ( V_8 ) ;
if ( V_46 )
goto V_79;
V_46 = F_24 ( V_8 ) ;
if ( V_46 )
goto V_79;
if ( V_11 != 1 )
V_46 = F_6 ( V_8 ) ;
return V_46 ;
V_79:
#ifdef F_29
if ( F_30 ( F_12 ( V_8 -> V_24 , L_1 , & V_24 ) ) ) {
if( F_31 ( V_80 ) )
F_19 (KERN_WARNING FW_BUG L_23
L_24 ) ;
}
#endif
return V_46 ;
}
int F_32 ( struct V_81 * V_82 )
{
T_1 V_22 ;
static int V_83 = 0 ;
if ( ! ( V_26 & V_44 ) )
return - V_84 ;
if ( ! F_33 ( V_82 ) )
return - V_23 ;
if ( V_83 > 0 ) {
F_34 ( V_82 ) ;
return 0 ;
} else if ( V_83 < 0 ) {
F_34 ( V_82 ) ;
return V_83 ;
}
V_83 = - V_85 ;
if ( ( ! V_86 . V_87 ) || ( ! V_86 . V_88 ) ) {
F_25 ( ( V_69 , L_25 ) ) ;
F_34 ( V_82 ) ;
return 0 ;
}
F_25 ( ( V_69 ,
L_26 ,
V_86 . V_88 , V_86 . V_87 ) ) ;
V_22 = F_35 ( V_86 . V_87 ,
( V_74 ) V_86 . V_88 , 8 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 ,
L_27
L_28 , V_86 . V_88 ,
V_86 . V_87 ) ) ;
F_34 ( V_82 ) ;
return V_22 ;
}
V_83 = 1 ;
if ( ! ( V_26 & V_27 ) )
F_34 ( V_82 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 )
{
int V_46 = 0 ;
T_1 V_22 = V_64 ;
struct V_47 V_48 = { V_49 , NULL } ;
struct V_47 V_65 = { sizeof( L_29 ) , L_29 } ;
struct V_47 V_66 = { 0 , NULL } ;
union V_31 * V_89 = NULL ;
struct V_90 * V_91 ;
V_22 = F_13 ( V_8 -> V_24 , L_30 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
return - V_29 ;
}
V_89 = V_48 . V_52 ;
if ( ! V_89 || ( V_89 -> type != V_53 ) ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_46 = - V_56 ;
goto V_57;
}
if ( V_89 -> V_54 . V_55 != 1 ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_46 = - V_56 ;
goto V_57;
}
V_91 = & ( V_8 -> V_16 -> V_92 ) ;
V_66 . V_60 = sizeof( struct V_90 ) ;
V_66 . V_52 = V_91 ;
V_22 = F_27 ( & ( V_89 -> V_54 . V_58 [ 0 ] ) ,
& V_65 , & V_66 ) ;
if ( F_8 ( V_22 ) ) {
F_19 (KERN_ERR PREFIX L_31 ) ;
V_46 = - V_56 ;
goto V_57;
}
if ( V_91 -> V_93 != V_94 ) {
F_19 (KERN_ERR PREFIX L_32 ) ;
V_46 = - V_56 ;
goto V_57;
}
if ( V_91 -> V_95 != V_96 ) {
F_19 (KERN_ERR PREFIX L_33 ) ;
V_46 = - V_56 ;
goto V_57;
}
if ( V_91 -> V_97 != V_98 &&
V_91 -> V_97 != V_99 &&
V_91 -> V_97 != V_100 ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_46 = - V_56 ;
goto V_57;
}
V_57:
F_23 ( V_48 . V_52 ) ;
return V_46 ;
}
int F_37 (
struct V_101 T_3 * V_16 )
{
int V_55 , V_102 ;
int V_103 = 0 ;
unsigned int V_68 , V_104 ;
T_4 V_105 ;
struct V_7 * V_8 ;
struct V_90 * V_91 ;
struct V_7 * V_106 ;
struct V_90 * V_107 ;
if ( ! F_38 ( & V_105 , V_71 ) )
return - V_72 ;
F_2 ( & V_13 ) ;
F_39 (i) {
V_8 = F_3 ( V_14 , V_68 ) ;
if ( ! V_8 ) {
continue;
}
if ( V_8 -> V_16 ) {
V_103 = - V_84 ;
goto V_108;
}
if ( ! V_16 || ! F_40 ( V_16 , V_68 ) ) {
V_103 = - V_23 ;
goto V_108;
}
}
F_39 (i) {
V_8 = F_3 ( V_14 , V_68 ) ;
if ( ! V_8 )
continue;
V_8 -> V_16 = F_40 ( V_16 , V_68 ) ;
F_41 ( V_68 , V_8 -> V_16 -> V_109 ) ;
if ( F_36 ( V_8 ) ) {
V_103 = - V_23 ;
continue;
}
}
if ( V_103 )
goto V_110;
F_39 (i) {
V_8 = F_3 ( V_14 , V_68 ) ;
if ( ! V_8 )
continue;
if ( F_42 ( V_68 , V_105 ) )
continue;
V_91 = & ( V_8 -> V_16 -> V_92 ) ;
F_41 ( V_68 , V_8 -> V_16 -> V_109 ) ;
F_41 ( V_68 , V_105 ) ;
if ( V_91 -> V_111 <= 1 )
continue;
V_102 = V_91 -> V_111 ;
V_55 = 1 ;
if ( V_91 -> V_97 == V_98 )
V_8 -> V_16 -> V_112 = V_113 ;
else if ( V_91 -> V_97 == V_100 )
V_8 -> V_16 -> V_112 = V_114 ;
else if ( V_91 -> V_97 == V_99 )
V_8 -> V_16 -> V_112 = V_115 ;
F_39 (j) {
if ( V_68 == V_104 )
continue;
V_106 = F_3 ( V_14 , V_104 ) ;
if ( ! V_106 )
continue;
V_107 = & ( V_106 -> V_16 -> V_92 ) ;
if ( V_107 -> V_116 != V_91 -> V_116 )
continue;
if ( V_107 -> V_111 != V_102 ) {
V_103 = - V_23 ;
goto V_110;
}
if ( V_91 -> V_97 != V_107 -> V_97 ) {
V_103 = - V_23 ;
goto V_110;
}
F_41 ( V_104 , V_105 ) ;
F_41 ( V_104 , V_8 -> V_16 -> V_109 ) ;
V_55 ++ ;
}
F_39 (j) {
if ( V_68 == V_104 )
continue;
V_106 = F_3 ( V_14 , V_104 ) ;
if ( ! V_106 )
continue;
V_107 = & ( V_106 -> V_16 -> V_92 ) ;
if ( V_107 -> V_116 != V_91 -> V_116 )
continue;
V_106 -> V_16 -> V_112 =
V_8 -> V_16 -> V_112 ;
F_43 ( V_106 -> V_16 -> V_109 ,
V_8 -> V_16 -> V_109 ) ;
}
}
V_110:
F_39 (i) {
V_8 = F_3 ( V_14 , V_68 ) ;
if ( ! V_8 || ! V_8 -> V_16 )
continue;
if ( V_103 ) {
F_44 ( V_8 -> V_16 -> V_109 ) ;
F_41 ( V_68 , V_8 -> V_16 -> V_109 ) ;
V_8 -> V_16 -> V_112 = V_113 ;
}
V_8 -> V_16 = NULL ;
}
V_108:
F_5 ( & V_13 ) ;
F_45 ( V_105 ) ;
return V_103 ;
}
int
F_46 ( struct V_101
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
return - V_84 ;
}
F_47 ( ! V_16 ) ;
V_8 -> V_16 = V_16 ;
if ( F_28 ( V_8 ) ) {
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return - V_85 ;
}
F_5 ( & V_13 ) ;
return 0 ;
}
void
F_48 ( struct V_101
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
