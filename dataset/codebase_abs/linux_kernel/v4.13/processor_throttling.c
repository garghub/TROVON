static int F_1 ( void )
{
int V_1 , V_2 ;
int V_3 = 0 ;
unsigned int V_4 , V_5 ;
T_1 V_6 ;
struct V_7 * V_8 , * V_9 ;
struct V_10 * V_11 , * V_12 ;
struct V_13 * V_14 , * V_15 ;
if ( ! F_2 ( & V_6 , V_16 ) )
return - V_17 ;
F_3 (i) {
V_8 = F_4 ( V_18 , V_4 ) ;
if ( ! V_8 )
continue;
V_14 = & ( V_8 -> V_19 ) ;
if ( ! V_14 -> V_20 ) {
V_3 = - V_21 ;
break;
}
}
if ( V_3 )
goto V_22;
F_3 (i) {
V_8 = F_4 ( V_18 , V_4 ) ;
if ( ! V_8 )
continue;
if ( F_5 ( V_4 , V_6 ) )
continue;
V_14 = & V_8 -> V_19 ;
V_11 = & ( V_14 -> V_23 ) ;
F_6 ( V_4 , V_14 -> V_24 ) ;
F_6 ( V_4 , V_6 ) ;
if ( V_11 -> V_25 <= 1 )
continue;
V_2 = V_11 -> V_25 ;
V_1 = 1 ;
F_3 (j) {
if ( V_4 == V_5 )
continue;
V_9 = F_4 ( V_18 , V_5 ) ;
if ( ! V_9 )
continue;
V_15 = & ( V_9 -> V_19 ) ;
V_12 = & ( V_15 -> V_23 ) ;
if ( V_12 -> V_26 != V_11 -> V_26 )
continue;
if ( V_12 -> V_25 != V_2 ) {
V_3 = - V_21 ;
goto V_22;
}
if ( V_11 -> V_27 != V_12 -> V_27 ) {
V_3 = - V_21 ;
goto V_22;
}
F_6 ( V_5 , V_6 ) ;
F_6 ( V_5 , V_14 -> V_24 ) ;
V_1 ++ ;
}
F_3 (j) {
if ( V_4 == V_5 )
continue;
V_9 = F_4 ( V_18 , V_5 ) ;
if ( ! V_9 )
continue;
V_15 = & ( V_9 -> V_19 ) ;
V_12 = & ( V_15 -> V_23 ) ;
if ( V_12 -> V_26 != V_11 -> V_26 )
continue;
F_7 ( V_15 -> V_24 ,
V_14 -> V_24 ) ;
}
}
V_22:
F_8 ( V_6 ) ;
F_3 (i) {
V_8 = F_4 ( V_18 , V_4 ) ;
if ( ! V_8 )
continue;
if ( V_3 ) {
V_14 = & ( V_8 -> V_19 ) ;
F_9 ( V_14 -> V_24 ) ;
F_6 ( V_4 , V_14 -> V_24 ) ;
V_14 -> V_28 = V_29 ;
}
}
return V_3 ;
}
void F_10 ( void )
{
if ( F_1 () ) {
F_11 ( ( V_30 ,
L_1 ) ) ;
}
return;
}
static int F_12 ( unsigned long V_31 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_7 * V_8 ;
unsigned int V_35 ;
int V_36 ;
struct V_37 * V_38 ;
struct V_13 * V_39 ;
V_35 = V_34 -> V_35 ;
V_8 = F_4 ( V_18 , V_35 ) ;
if ( ! V_8 ) {
F_11 ( ( V_30 , L_2 ) ) ;
return 0 ;
}
if ( ! V_8 -> V_40 . V_19 ) {
F_11 ( ( V_30 , L_3
L_4 , V_35 ) ) ;
return 0 ;
}
V_36 = V_34 -> V_36 ;
V_39 = & ( V_8 -> V_19 ) ;
switch ( V_31 ) {
case V_41 :
V_38 = & V_8 -> V_42 ;
if ( V_38 -> V_43 . V_44 > V_36 )
V_36 = V_38 -> V_43 . V_44 ;
if ( V_38 -> V_45 . V_44 > V_36 )
V_36 = V_38 -> V_45 . V_44 ;
if ( V_8 -> V_46 > V_36 )
V_36 = V_8 -> V_46 ;
if ( V_36 >= V_39 -> V_47 ) {
F_13 ( V_48
L_5 ) ;
V_36 = V_39 -> V_47 - 1 ;
}
V_34 -> V_36 = V_36 ;
F_11 ( ( V_30 , L_6
L_7 ,
V_35 , V_36 ) ) ;
break;
case V_49 :
V_39 -> V_50 = V_36 ;
F_11 ( ( V_30 , L_8
L_9 ,
V_35 , V_36 ) ) ;
break;
default:
F_13 ( V_48
L_10 ) ;
break;
}
return 0 ;
}
static int F_14 ( struct V_7 * V_8 )
{
T_2 V_51 = 0 ;
unsigned long long V_52 = 0 ;
if ( ! V_8 )
return - V_21 ;
if ( V_53 )
goto V_54;
V_51 = F_15 ( V_8 -> V_55 , L_11 , NULL , & V_52 ) ;
if ( F_16 ( V_51 ) ) {
if ( V_51 != V_56 ) {
F_17 ( ( V_57 , V_51 , L_12 ) ) ;
}
return - V_58 ;
}
V_54:
V_8 -> V_46 = ( int ) V_52 ;
return 0 ;
}
int F_18 ( struct V_7 * V_8 )
{
int V_59 = 0 ;
int V_60 ;
int V_61 ;
struct V_37 * V_42 ;
int V_36 ;
if ( V_53 )
return 0 ;
V_59 = F_14 ( V_8 ) ;
if ( V_59 ) {
return V_59 ;
}
V_60 = V_8 -> V_46 ;
if ( V_60 >= V_8 -> V_19 . V_47 ) {
return - V_21 ;
}
V_61 = V_8 -> V_19 . V_50 ;
if ( V_61 > V_60 ) {
V_42 = & V_8 -> V_42 ;
V_36 = V_60 ;
if ( V_42 -> V_43 . V_44 > V_36 )
V_36 = V_42 -> V_43 . V_44 ;
if ( V_42 -> V_45 . V_44 > V_36 )
V_36 = V_42 -> V_45 . V_44 ;
} else if ( V_61 == V_60 ) {
return 0 ;
} else {
V_36 = V_60 ;
}
return F_19 ( V_8 , V_36 , false ) ;
}
void F_20 ( struct V_7 * V_8 ,
bool V_62 )
{
int V_59 = 0 ;
if ( V_62 ) {
V_8 -> V_40 . V_19 = 0 ;
return;
}
if ( ! V_8 -> V_19 . V_47 ) {
V_8 -> V_40 . V_19 = 0 ;
return;
}
V_8 -> V_40 . V_19 = 1 ;
V_59 = F_21 ( V_8 ) ;
if ( V_59 )
goto V_54;
if ( V_8 -> V_19 . V_50 ) {
V_59 = F_19 ( V_8 , 0 , false ) ;
if ( V_59 )
goto V_54;
}
V_54:
if ( V_59 )
V_8 -> V_40 . V_19 = 0 ;
}
static int F_22 ( struct V_7 * V_8 )
{
int V_59 = 0 ;
T_2 V_51 = 0 ;
struct V_63 V_64 = { V_65 , NULL } ;
union V_66 * V_67 = NULL ;
union V_66 V_68 = { 0 } ;
struct V_13 * V_19 ;
V_51 = F_23 ( V_8 -> V_55 , L_13 , NULL , & V_64 ) ;
if ( F_16 ( V_51 ) ) {
if ( V_51 != V_56 ) {
F_17 ( ( V_57 , V_51 , L_14 ) ) ;
}
return - V_58 ;
}
V_67 = (union V_66 * ) V_64 . V_69 ;
if ( ! V_67 || ( V_67 -> type != V_70 )
|| ( V_67 -> V_71 . V_1 != 2 ) ) {
F_13 (KERN_ERR PREFIX L_15 ) ;
V_59 = - V_72 ;
goto V_54;
}
V_68 = V_67 -> V_71 . V_73 [ 0 ] ;
if ( ( V_68 . type != V_74 )
|| ( V_68 . V_64 . V_75 < sizeof( struct V_76 ) )
|| ( V_68 . V_64 . V_69 == NULL ) ) {
F_13 (KERN_ERR PREFIX
L_16 ) ;
V_59 = - V_72 ;
goto V_54;
}
memcpy ( & V_8 -> V_19 . V_77 , V_68 . V_64 . V_69 ,
sizeof( struct V_76 ) ) ;
V_68 = V_67 -> V_71 . V_73 [ 1 ] ;
if ( ( V_68 . type != V_74 )
|| ( V_68 . V_64 . V_75 < sizeof( struct V_76 ) )
|| ( V_68 . V_64 . V_69 == NULL ) ) {
F_13 (KERN_ERR PREFIX L_17 ) ;
V_59 = - V_72 ;
goto V_54;
}
memcpy ( & V_8 -> V_19 . V_78 , V_68 . V_64 . V_69 ,
sizeof( struct V_76 ) ) ;
V_19 = & V_8 -> V_19 ;
if ( ( V_19 -> V_77 . V_79 +
V_19 -> V_77 . V_80 ) > 32 ) {
F_13 (KERN_ERR PREFIX L_18 ) ;
V_59 = - V_72 ;
goto V_54;
}
if ( ( V_19 -> V_78 . V_79 +
V_19 -> V_78 . V_80 ) > 32 ) {
F_13 (KERN_ERR PREFIX L_19 ) ;
V_59 = - V_72 ;
goto V_54;
}
V_54:
F_24 ( V_64 . V_69 ) ;
return V_59 ;
}
static int F_25 ( struct V_7 * V_8 )
{
int V_59 = 0 ;
T_2 V_51 = V_81 ;
struct V_63 V_64 = { V_65 , NULL } ;
struct V_63 V_82 = { sizeof( L_20 ) , L_20 } ;
struct V_63 V_50 = { 0 , NULL } ;
union V_66 * V_83 = NULL ;
int V_4 ;
V_51 = F_23 ( V_8 -> V_55 , L_21 , NULL , & V_64 ) ;
if ( F_16 ( V_51 ) ) {
if ( V_51 != V_56 ) {
F_17 ( ( V_57 , V_51 , L_22 ) ) ;
}
return - V_58 ;
}
V_83 = V_64 . V_69 ;
if ( ! V_83 || ( V_83 -> type != V_70 ) ) {
F_13 (KERN_ERR PREFIX L_23 ) ;
V_59 = - V_72 ;
goto V_54;
}
F_11 ( ( V_30 , L_24 ,
V_83 -> V_71 . V_1 ) ) ;
V_8 -> V_19 . V_47 = V_83 -> V_71 . V_1 ;
V_8 -> V_19 . V_84 =
F_26 ( sizeof( struct V_85 ) * V_83 -> V_71 . V_1 ,
V_16 ) ;
if ( ! V_8 -> V_19 . V_84 ) {
V_59 = - V_17 ;
goto V_54;
}
for ( V_4 = 0 ; V_4 < V_8 -> V_19 . V_47 ; V_4 ++ ) {
struct V_85 * V_44 =
(struct V_85 * ) & ( V_8 -> V_19 .
V_84 [ V_4 ] ) ;
V_50 . V_75 = sizeof( struct V_85 ) ;
V_50 . V_69 = V_44 ;
F_11 ( ( V_30 , L_25 , V_4 ) ) ;
V_51 = F_27 ( & ( V_83 -> V_71 . V_73 [ V_4 ] ) ,
& V_82 , & V_50 ) ;
if ( F_16 ( V_51 ) ) {
F_17 ( ( V_57 , V_51 , L_26 ) ) ;
V_59 = - V_72 ;
F_24 ( V_8 -> V_19 . V_84 ) ;
goto V_54;
}
if ( ! V_44 -> V_86 ) {
F_13 (KERN_ERR PREFIX
L_27 ) ;
V_59 = - V_72 ;
F_24 ( V_8 -> V_19 . V_84 ) ;
goto V_54;
}
}
V_54:
F_24 ( V_64 . V_69 ) ;
return V_59 ;
}
static int F_28 ( struct V_7 * V_8 )
{
int V_59 = 0 ;
T_2 V_51 = V_81 ;
struct V_63 V_64 = { V_65 , NULL } ;
struct V_63 V_82 = { sizeof( L_20 ) , L_20 } ;
struct V_63 V_50 = { 0 , NULL } ;
union V_66 * V_87 = NULL ;
struct V_10 * V_11 ;
struct V_13 * V_14 ;
V_14 = & V_8 -> V_19 ;
V_14 -> V_20 = 0 ;
V_51 = F_23 ( V_8 -> V_55 , L_28 , NULL , & V_64 ) ;
if ( F_16 ( V_51 ) ) {
if ( V_51 != V_56 ) {
F_17 ( ( V_57 , V_51 , L_29 ) ) ;
}
return - V_58 ;
}
V_87 = V_64 . V_69 ;
if ( ! V_87 || ( V_87 -> type != V_70 ) ) {
F_13 (KERN_ERR PREFIX L_30 ) ;
V_59 = - V_72 ;
goto V_54;
}
if ( V_87 -> V_71 . V_1 != 1 ) {
F_13 (KERN_ERR PREFIX L_30 ) ;
V_59 = - V_72 ;
goto V_54;
}
V_11 = & ( V_8 -> V_19 . V_23 ) ;
V_50 . V_75 = sizeof( struct V_10 ) ;
V_50 . V_69 = V_11 ;
V_51 = F_27 ( & ( V_87 -> V_71 . V_73 [ 0 ] ) ,
& V_82 , & V_50 ) ;
if ( F_16 ( V_51 ) ) {
F_13 (KERN_ERR PREFIX L_30 ) ;
V_59 = - V_72 ;
goto V_54;
}
if ( V_11 -> V_88 != V_89 ) {
F_13 (KERN_ERR PREFIX L_31 ) ;
V_59 = - V_72 ;
goto V_54;
}
if ( V_11 -> V_90 != V_91 ) {
F_13 (KERN_ERR PREFIX L_32 ) ;
V_59 = - V_72 ;
goto V_54;
}
V_14 = & V_8 -> V_19 ;
V_14 -> V_20 = 1 ;
V_14 -> V_28 = V_11 -> V_27 ;
F_6 ( V_8 -> V_92 , V_14 -> V_24 ) ;
if ( V_11 -> V_27 != V_29 &&
V_11 -> V_27 != V_93 &&
V_11 -> V_27 != V_94 ) {
V_14 -> V_20 = 0 ;
V_14 -> V_28 = V_29 ;
}
V_54:
F_24 ( V_64 . V_69 ) ;
return V_59 ;
}
static int F_29 ( struct V_7 * V_8 )
{
int V_50 = 0 ;
T_3 V_95 = 0 ;
T_3 V_96 = 0 ;
T_3 V_97 = 0 ;
if ( ! V_8 )
return - V_21 ;
if ( ! V_8 -> V_40 . V_19 )
return - V_58 ;
F_30 ( V_8 -> V_19 . V_98 , 6 , L_33 ) ;
V_8 -> V_19 . V_50 = 0 ;
V_96 = V_8 -> V_19 . V_47 - 1 ;
V_96 <<= V_8 -> V_19 . V_99 ;
F_31 () ;
V_95 = F_32 ( V_8 -> V_19 . V_98 ) ;
if ( V_95 & 0x10 ) {
V_97 = V_95 & V_96 ;
V_97 >>= V_8 -> V_19 . V_99 ;
if ( V_97 )
V_50 = V_8 -> V_19 . V_47 - V_97 ;
}
V_8 -> V_19 . V_50 = V_50 ;
F_33 () ;
F_11 ( ( V_30 ,
L_34 ,
V_50 , V_8 -> V_19 . V_100 [ V_50 ] . V_101 ) ) ;
return 0 ;
}
static int F_34 ( T_4 * V_95 )
{
T_4 V_102 , V_103 ;
T_4 V_104 = 0 ;
int V_105 = - 1 ;
if ( ( F_35 ( V_106 . V_107 ) != V_108 ) ||
! F_36 ( V_109 ) ) {
F_13 (KERN_ERR PREFIX
L_35 ) ;
} else {
V_103 = 0 ;
V_102 = 0 ;
F_37 ( V_110 ,
( T_3 * ) & V_103 , ( T_3 * ) & V_102 ) ;
V_104 = ( V_102 << 32 ) | V_103 ;
* V_95 = ( T_4 ) V_104 ;
V_105 = 0 ;
}
return V_105 ;
}
static int F_38 ( T_4 V_95 )
{
int V_105 = - 1 ;
T_4 V_104 ;
if ( ( F_35 ( V_106 . V_107 ) != V_108 ) ||
! F_36 ( V_109 ) ) {
F_13 (KERN_ERR PREFIX
L_35 ) ;
} else {
V_104 = V_95 ;
F_39 ( V_110 ,
V_104 & 0xffffffff , V_104 >> 32 ) ;
V_105 = 0 ;
}
return V_105 ;
}
static int F_34 ( T_4 * V_95 )
{
F_13 (KERN_ERR PREFIX
L_35 ) ;
return - 1 ;
}
static int F_38 ( T_4 V_95 )
{
F_13 (KERN_ERR PREFIX
L_35 ) ;
return - 1 ;
}
static int F_40 ( struct V_7 * V_8 ,
T_4 * V_95 )
{
T_3 V_79 , V_80 ;
T_3 V_111 ;
T_4 V_112 ;
struct V_13 * V_19 ;
int V_105 = - 1 ;
V_19 = & V_8 -> V_19 ;
switch ( V_19 -> V_78 . V_113 ) {
case V_114 :
V_79 = V_19 -> V_78 . V_79 ;
V_80 = V_19 -> V_78 . V_80 ;
F_41 ( ( V_115 ) V_19 -> V_78 .
V_98 , & V_111 ,
( T_3 ) ( V_79 + V_80 ) ) ;
V_112 = ( 1 << V_79 ) - 1 ;
* V_95 = ( T_4 ) ( ( V_111 >> V_80 ) & V_112 ) ;
V_105 = 0 ;
break;
case V_116 :
V_105 = F_34 ( V_95 ) ;
break;
default:
F_13 (KERN_ERR PREFIX L_36 ,
(u32) (throttling->status_register.space_id)) ;
}
return V_105 ;
}
static int F_42 ( struct V_7 * V_8 ,
T_4 V_95 )
{
T_3 V_79 , V_80 ;
T_4 V_111 ;
T_4 V_112 ;
struct V_13 * V_19 ;
int V_105 = - 1 ;
V_19 = & V_8 -> V_19 ;
switch ( V_19 -> V_77 . V_113 ) {
case V_114 :
V_79 = V_19 -> V_77 . V_79 ;
V_80 = V_19 -> V_77 . V_80 ;
V_112 = ( 1 << V_79 ) - 1 ;
V_111 = V_95 & V_112 ;
F_43 ( ( V_115 ) V_19 ->
V_77 . V_98 ,
( T_3 ) ( V_111 << V_80 ) ,
( T_3 ) ( V_79 + V_80 ) ) ;
V_105 = 0 ;
break;
case V_116 :
V_105 = F_38 ( V_95 ) ;
break;
default:
F_13 (KERN_ERR PREFIX L_36 ,
(u32) (throttling->control_register.space_id)) ;
}
return V_105 ;
}
static int F_44 ( struct V_7 * V_8 ,
T_4 V_95 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_8 -> V_19 . V_47 ; V_4 ++ ) {
struct V_85 * V_44 =
(struct V_85 * ) & ( V_8 -> V_19 .
V_84 [ V_4 ] ) ;
if ( V_44 -> V_117 == V_95 )
return V_4 ;
}
return - 1 ;
}
static int F_45 ( struct V_7 * V_8 ,
int V_50 , T_4 * V_95 )
{
int V_105 = - 1 ;
if ( V_50 >= 0 && V_50 <= V_8 -> V_19 . V_47 ) {
struct V_85 * V_44 =
(struct V_85 * ) & ( V_8 -> V_19 .
V_84 [ V_50 ] ) ;
* V_95 = V_44 -> V_117 ;
V_105 = 0 ;
}
return V_105 ;
}
static int F_46 ( struct V_7 * V_8 )
{
int V_50 = 0 ;
int V_105 ;
T_4 V_95 ;
if ( ! V_8 )
return - V_21 ;
if ( ! V_8 -> V_40 . V_19 )
return - V_58 ;
V_8 -> V_19 . V_50 = 0 ;
V_95 = 0 ;
V_105 = F_40 ( V_8 , & V_95 ) ;
if ( V_105 >= 0 ) {
V_50 = F_44 ( V_8 , V_95 ) ;
if ( V_50 == - 1 ) {
F_11 ( ( V_30 ,
L_37 ) ) ;
V_50 = 0 ;
V_105 = F_47 ( V_8 , V_50 , true ,
true ) ;
if ( V_105 )
return V_105 ;
}
V_8 -> V_19 . V_50 = V_50 ;
}
return 0 ;
}
static long F_48 ( void * V_32 )
{
struct V_7 * V_8 = V_32 ;
return V_8 -> V_19 . F_21 ( V_8 ) ;
}
static int F_49 ( int V_35 , long (* F_50)( void * ) , void * V_118 , bool V_119 )
{
if ( V_119 || ( F_51 () && V_35 == F_52 () ) )
return F_50 ( V_118 ) ;
return F_53 ( V_35 , F_50 , V_118 ) ;
}
static int F_21 ( struct V_7 * V_8 )
{
if ( ! V_8 )
return - V_21 ;
if ( ! V_8 -> V_40 . V_19 )
return - V_58 ;
if ( ! F_54 ( V_8 -> V_92 ) )
return - V_58 ;
return F_49 ( V_8 -> V_92 , F_48 , V_8 , false ) ;
}
static int F_55 ( struct V_7 * V_8 )
{
int V_4 , V_120 ;
if ( ! V_8 -> V_19 . V_98 ) {
F_11 ( ( V_30 , L_38 ) ) ;
return - V_21 ;
} else if ( ! V_8 -> V_19 . V_121 ) {
F_11 ( ( V_30 , L_39 ) ) ;
return - V_21 ;
}
else if ( ( V_8 -> V_19 . V_99 + V_8 -> V_19 . V_121 ) > 4 ) {
F_13 (KERN_WARNING PREFIX L_40 ) ;
return - V_21 ;
}
V_8 -> V_19 . V_47 = 1 << V_122 . V_121 ;
V_120 = ( 1000 / V_8 -> V_19 . V_47 ) ;
for ( V_4 = 0 ; V_4 < V_8 -> V_19 . V_47 ; V_4 ++ ) {
V_8 -> V_19 . V_100 [ V_4 ] . V_101 = 1000 - V_120 * V_4 ;
V_8 -> V_19 . V_100 [ V_4 ] . V_123 = 1000 - V_120 * V_4 ;
}
return 0 ;
}
static int F_56 ( struct V_7 * V_8 ,
int V_50 , bool V_124 )
{
T_3 V_95 = 0 ;
T_3 V_96 = 0 ;
T_3 V_97 = 0 ;
if ( ! V_8 )
return - V_21 ;
if ( ( V_50 < 0 ) || ( V_50 > ( V_8 -> V_19 . V_47 - 1 ) ) )
return - V_21 ;
if ( ! V_8 -> V_40 . V_19 )
return - V_58 ;
if ( ! V_124 && ( V_50 == V_8 -> V_19 . V_50 ) )
return 0 ;
if ( V_50 < V_8 -> V_46 )
return - V_125 ;
if ( V_50 ) {
V_97 = V_8 -> V_19 . V_47 - V_50 ;
V_97 <<= V_8 -> V_19 . V_99 ;
V_96 = V_8 -> V_19 . V_47 - 1 ;
V_96 <<= V_122 . V_99 ;
V_96 = ~ V_96 ;
}
F_31 () ;
V_95 = F_32 ( V_8 -> V_19 . V_98 ) ;
if ( V_95 & 0x10 ) {
V_95 &= 0xFFFFFFEF ;
F_57 ( V_95 , V_8 -> V_19 . V_98 ) ;
}
if ( V_50 ) {
V_95 &= V_96 ;
V_95 |= V_97 ;
F_57 ( V_95 , V_8 -> V_19 . V_98 ) ;
V_95 |= 0x00000010 ;
F_57 ( V_95 , V_8 -> V_19 . V_98 ) ;
}
V_8 -> V_19 . V_50 = V_50 ;
F_33 () ;
F_11 ( ( V_30 ,
L_41 , V_50 ,
( V_8 -> V_19 . V_100 [ V_50 ] . V_101 ? V_8 ->
V_19 . V_100 [ V_50 ] . V_101 / 10 : 0 ) ) ) ;
return 0 ;
}
static int F_58 ( struct V_7 * V_8 ,
int V_50 , bool V_124 )
{
int V_105 ;
T_4 V_95 ;
if ( ! V_8 )
return - V_21 ;
if ( ( V_50 < 0 ) || ( V_50 > ( V_8 -> V_19 . V_47 - 1 ) ) )
return - V_21 ;
if ( ! V_8 -> V_40 . V_19 )
return - V_58 ;
if ( ! V_124 && ( V_50 == V_8 -> V_19 . V_50 ) )
return 0 ;
if ( V_50 < V_8 -> V_46 )
return - V_125 ;
V_95 = 0 ;
V_105 = F_45 ( V_8 , V_50 , & V_95 ) ;
if ( V_105 >= 0 ) {
F_42 ( V_8 , V_95 ) ;
V_8 -> V_19 . V_50 = V_50 ;
}
return 0 ;
}
static long F_59 ( void * V_32 )
{
struct V_126 * V_118 = V_32 ;
struct V_7 * V_8 = V_118 -> V_8 ;
return V_8 -> V_19 . F_19 ( V_8 ,
V_118 -> V_36 , V_118 -> V_124 ) ;
}
static int F_47 ( struct V_7 * V_8 ,
int V_50 , bool V_124 , bool V_119 )
{
int V_105 = 0 ;
unsigned int V_4 ;
struct V_7 * V_9 ;
struct V_13 * V_39 ;
struct V_126 V_118 ;
struct V_33 V_127 ;
if ( ! V_8 )
return - V_21 ;
if ( ! V_8 -> V_40 . V_19 )
return - V_58 ;
if ( ( V_50 < 0 ) || ( V_50 > ( V_8 -> V_19 . V_47 - 1 ) ) )
return - V_21 ;
if ( F_60 ( V_8 -> V_92 ) ) {
return - V_58 ;
}
V_127 . V_36 = V_50 ;
V_39 = & ( V_8 -> V_19 ) ;
F_61 (i, cpu_online_mask, p_throttling->shared_cpu_map) {
V_127 . V_35 = V_4 ;
F_12 ( V_41 ,
& V_127 ) ;
}
if ( V_39 -> V_28 == V_93 ) {
V_118 . V_8 = V_8 ;
V_118 . V_36 = V_50 ;
V_118 . V_124 = V_124 ;
V_105 = F_49 ( V_8 -> V_92 , F_59 , & V_118 ,
V_119 ) ;
} else {
F_61 (i, cpu_online_mask,
p_throttling->shared_cpu_map) {
V_9 = F_4 ( V_18 , V_4 ) ;
if ( ! V_9 ) {
F_11 ( ( V_30 ,
L_42 , V_4 ) ) ;
continue;
}
if ( ! V_9 -> V_40 . V_19 ) {
F_11 ( ( V_30 ,
L_43
L_44 , V_4 ) ) ;
continue;
}
V_118 . V_8 = V_9 ;
V_118 . V_36 = V_50 ;
V_118 . V_124 = V_124 ;
V_105 = F_49 ( V_8 -> V_92 , F_59 ,
& V_118 , V_119 ) ;
}
}
F_61 (i, cpu_online_mask, p_throttling->shared_cpu_map) {
V_127 . V_35 = V_4 ;
F_12 ( V_49 ,
& V_127 ) ;
}
return V_105 ;
}
int F_19 ( struct V_7 * V_8 , int V_50 ,
bool V_124 )
{
return F_47 ( V_8 , V_50 , V_124 , false ) ;
}
int F_62 ( struct V_7 * V_8 )
{
int V_59 = 0 ;
struct V_13 * V_14 ;
F_11 ( ( V_30 ,
L_45 ,
V_8 -> V_19 . V_98 ,
V_8 -> V_19 . V_99 ,
V_8 -> V_19 . V_121 ) ) ;
if ( F_22 ( V_8 ) ||
F_25 ( V_8 ) ||
F_14 ( V_8 ) )
{
V_8 -> V_19 . F_21 =
& F_29 ;
V_8 -> V_19 . F_19 =
& F_56 ;
if ( F_55 ( V_8 ) )
return 0 ;
} else {
V_8 -> V_19 . F_21 =
& F_46 ;
V_8 -> V_19 . F_19 =
& F_58 ;
}
if ( F_28 ( V_8 ) ) {
V_14 = & V_8 -> V_19 ;
V_14 -> V_20 = 0 ;
F_6 ( V_8 -> V_92 , V_14 -> V_24 ) ;
V_14 -> V_28 = V_29 ;
}
if ( V_128 . V_129 . V_130 ) {
F_11 ( ( V_30 ,
L_46 ) ) ;
return 0 ;
}
F_11 ( ( V_30 , L_24 ,
V_8 -> V_19 . V_47 ) ) ;
V_8 -> V_40 . V_19 = 1 ;
V_59 = F_21 ( V_8 ) ;
if ( V_59 )
goto V_54;
if ( V_8 -> V_19 . V_50 ) {
F_11 ( ( V_30 ,
L_47 ,
V_8 -> V_19 . V_50 ) ) ;
V_59 = F_19 ( V_8 , 0 , false ) ;
if ( V_59 )
goto V_54;
}
V_54:
if ( V_59 )
V_8 -> V_40 . V_19 = 0 ;
return V_59 ;
}
