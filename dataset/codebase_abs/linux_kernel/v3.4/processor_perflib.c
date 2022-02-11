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
F_28 ( ( V_70 , L_19 ,
V_68 -> V_55 . V_56 ) ) ;
V_8 -> V_16 -> V_19 = V_68 -> V_55 . V_56 ;
V_8 -> V_16 -> V_20 =
F_29 ( sizeof( struct V_71 ) * V_68 -> V_55 . V_56 ,
V_72 ) ;
if ( ! V_8 -> V_16 -> V_20 ) {
V_51 = - V_73 ;
goto V_58;
}
for ( V_69 = 0 ; V_69 < V_8 -> V_16 -> V_19 ; V_69 ++ ) {
struct V_71 * V_74 = & ( V_8 -> V_16 -> V_20 [ V_69 ] ) ;
V_67 . V_61 = sizeof( struct V_71 ) ;
V_67 . V_50 = V_74 ;
F_28 ( ( V_70 , L_20 , V_69 ) ) ;
V_22 = F_30 ( & ( V_68 -> V_55 . V_59 [ V_69 ] ) ,
& V_66 , & V_67 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 , L_21 ) ) ;
V_51 = - V_57 ;
F_25 ( V_8 -> V_16 -> V_20 ) ;
goto V_58;
}
F_28 ( ( V_70 ,
L_22 ,
V_69 ,
( V_75 ) V_74 -> V_21 ,
( V_75 ) V_74 -> V_76 ,
( V_75 ) V_74 -> V_77 ,
( V_75 ) V_74 -> V_78 ,
( V_75 ) V_74 -> V_79 , ( V_75 ) V_74 -> V_22 ) ) ;
if ( ! V_74 -> V_21 ||
( ( V_75 ) ( V_74 -> V_21 * 1000 ) !=
( V_74 -> V_21 * 1000 ) ) ) {
F_19 (KERN_ERR FW_BUG PREFIX
L_23 ,
px->core_frequency) ;
V_51 = - V_57 ;
F_25 ( V_8 -> V_16 -> V_20 ) ;
goto V_58;
}
}
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
F_28 ( ( V_70 ,
L_24 ) ) ;
return - V_29 ;
}
V_51 = F_26 ( V_8 ) ;
if ( V_51 )
goto V_80;
V_51 = F_27 ( V_8 ) ;
if ( V_51 )
goto V_80;
if ( V_11 != 1 )
V_51 = F_6 ( V_8 ) ;
return V_51 ;
V_80:
#ifdef F_32
if ( F_33 ( F_12 ( V_8 -> V_24 , L_1 , & V_24 ) ) ) {
if( F_34 ( V_81 ) )
F_19 (KERN_WARNING FW_BUG L_25
L_26 ) ;
}
#endif
return V_51 ;
}
int F_35 ( struct V_82 * V_83 )
{
T_1 V_22 ;
static int V_84 = 0 ;
if ( ! ( V_26 & V_44 ) )
return - V_85 ;
if ( ! F_36 ( V_83 ) )
return - V_23 ;
if ( V_84 > 0 ) {
F_37 ( V_83 ) ;
return 0 ;
} else if ( V_84 < 0 ) {
F_37 ( V_83 ) ;
return V_84 ;
}
V_84 = - V_86 ;
if ( ( ! V_87 . V_88 ) || ( ! V_87 . V_89 ) ) {
F_28 ( ( V_70 , L_27 ) ) ;
F_37 ( V_83 ) ;
return 0 ;
}
F_28 ( ( V_70 ,
L_28 ,
V_87 . V_89 , V_87 . V_88 ) ) ;
V_22 = F_38 ( V_87 . V_88 ,
( V_75 ) V_87 . V_89 , 8 ) ;
if ( F_8 ( V_22 ) ) {
F_9 ( ( V_28 , V_22 ,
L_29
L_30 , V_87 . V_89 ,
V_87 . V_88 ) ) ;
F_37 ( V_83 ) ;
return V_22 ;
}
V_84 = 1 ;
if ( ! ( V_26 & V_27 ) )
F_37 ( V_83 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 )
{
int V_51 = 0 ;
T_1 V_22 = V_65 ;
struct V_47 V_48 = { V_49 , NULL } ;
struct V_47 V_66 = { sizeof( L_31 ) , L_31 } ;
struct V_47 V_67 = { 0 , NULL } ;
union V_31 * V_90 = NULL ;
struct V_91 * V_92 ;
V_22 = F_13 ( V_8 -> V_24 , L_32 , NULL , & V_48 ) ;
if ( F_8 ( V_22 ) ) {
return - V_29 ;
}
V_90 = V_48 . V_50 ;
if ( ! V_90 || ( V_90 -> type != V_54 ) ) {
F_19 (KERN_ERR PREFIX L_33 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_90 -> V_55 . V_56 != 1 ) {
F_19 (KERN_ERR PREFIX L_33 ) ;
V_51 = - V_57 ;
goto V_58;
}
V_92 = & ( V_8 -> V_16 -> V_93 ) ;
V_67 . V_61 = sizeof( struct V_91 ) ;
V_67 . V_50 = V_92 ;
V_22 = F_30 ( & ( V_90 -> V_55 . V_59 [ 0 ] ) ,
& V_66 , & V_67 ) ;
if ( F_8 ( V_22 ) ) {
F_19 (KERN_ERR PREFIX L_33 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_92 -> V_94 != V_95 ) {
F_19 (KERN_ERR PREFIX L_34 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_92 -> V_96 != V_97 ) {
F_19 (KERN_ERR PREFIX L_35 ) ;
V_51 = - V_57 ;
goto V_58;
}
if ( V_92 -> V_98 != V_99 &&
V_92 -> V_98 != V_100 &&
V_92 -> V_98 != V_101 ) {
F_19 (KERN_ERR PREFIX L_36 ) ;
V_51 = - V_57 ;
goto V_58;
}
V_58:
F_25 ( V_48 . V_50 ) ;
return V_51 ;
}
int F_40 (
struct V_102 T_3 * V_16 )
{
int V_56 , V_103 ;
int V_104 = 0 ;
unsigned int V_69 , V_105 ;
T_4 V_106 ;
struct V_7 * V_8 ;
struct V_91 * V_92 ;
struct V_7 * V_107 ;
struct V_91 * V_108 ;
if ( ! F_41 ( & V_106 , V_72 ) )
return - V_73 ;
F_2 ( & V_13 ) ;
F_42 (i) {
V_8 = F_3 ( V_14 , V_69 ) ;
if ( ! V_8 ) {
continue;
}
if ( V_8 -> V_16 ) {
V_104 = - V_85 ;
goto V_109;
}
if ( ! V_16 || ! F_43 ( V_16 , V_69 ) ) {
V_104 = - V_23 ;
goto V_109;
}
}
F_42 (i) {
V_8 = F_3 ( V_14 , V_69 ) ;
if ( ! V_8 )
continue;
V_8 -> V_16 = F_43 ( V_16 , V_69 ) ;
F_44 ( V_69 , V_8 -> V_16 -> V_110 ) ;
if ( F_39 ( V_8 ) ) {
V_104 = - V_23 ;
continue;
}
}
if ( V_104 )
goto V_111;
F_42 (i) {
V_8 = F_3 ( V_14 , V_69 ) ;
if ( ! V_8 )
continue;
if ( F_45 ( V_69 , V_106 ) )
continue;
V_92 = & ( V_8 -> V_16 -> V_93 ) ;
F_44 ( V_69 , V_8 -> V_16 -> V_110 ) ;
F_44 ( V_69 , V_106 ) ;
if ( V_92 -> V_112 <= 1 )
continue;
V_103 = V_92 -> V_112 ;
V_56 = 1 ;
if ( V_92 -> V_98 == V_99 )
V_8 -> V_16 -> V_113 = V_114 ;
else if ( V_92 -> V_98 == V_101 )
V_8 -> V_16 -> V_113 = V_115 ;
else if ( V_92 -> V_98 == V_100 )
V_8 -> V_16 -> V_113 = V_116 ;
F_42 (j) {
if ( V_69 == V_105 )
continue;
V_107 = F_3 ( V_14 , V_105 ) ;
if ( ! V_107 )
continue;
V_108 = & ( V_107 -> V_16 -> V_93 ) ;
if ( V_108 -> V_117 != V_92 -> V_117 )
continue;
if ( V_108 -> V_112 != V_103 ) {
V_104 = - V_23 ;
goto V_111;
}
if ( V_92 -> V_98 != V_108 -> V_98 ) {
V_104 = - V_23 ;
goto V_111;
}
F_44 ( V_105 , V_106 ) ;
F_44 ( V_105 , V_8 -> V_16 -> V_110 ) ;
V_56 ++ ;
}
F_42 (j) {
if ( V_69 == V_105 )
continue;
V_107 = F_3 ( V_14 , V_105 ) ;
if ( ! V_107 )
continue;
V_108 = & ( V_107 -> V_16 -> V_93 ) ;
if ( V_108 -> V_117 != V_92 -> V_117 )
continue;
V_107 -> V_16 -> V_113 =
V_8 -> V_16 -> V_113 ;
F_46 ( V_107 -> V_16 -> V_110 ,
V_8 -> V_16 -> V_110 ) ;
}
}
V_111:
F_42 (i) {
V_8 = F_3 ( V_14 , V_69 ) ;
if ( ! V_8 || ! V_8 -> V_16 )
continue;
if ( V_104 ) {
F_47 ( V_8 -> V_16 -> V_110 ) ;
F_44 ( V_69 , V_8 -> V_16 -> V_110 ) ;
V_8 -> V_16 -> V_113 = V_114 ;
}
V_8 -> V_16 = NULL ;
}
V_109:
F_5 ( & V_13 ) ;
F_48 ( V_106 ) ;
return V_104 ;
}
int
F_49 ( struct V_102
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
return - V_85 ;
}
F_50 ( ! V_16 ) ;
V_8 -> V_16 = V_16 ;
if ( F_31 ( V_8 ) ) {
V_8 -> V_16 = NULL ;
F_5 ( & V_13 ) ;
return - V_86 ;
}
F_5 ( & V_13 ) ;
return 0 ;
}
void
F_51 ( struct V_102
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
