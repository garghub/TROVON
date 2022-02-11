int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( ( V_4 == NULL ) || ( V_2 == NULL ) )
return - V_7 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_4 -> V_6 = V_6 ;
V_6 -> V_10 = V_4 -> V_11 ;
V_6 -> V_12 = V_2 -> V_12 ;
V_6 -> V_13 = V_2 -> V_13 ;
V_6 -> V_14 = V_2 -> V_14 ;
V_6 -> V_15 = V_2 -> V_16 ;
V_6 -> V_17 = V_18 ;
V_6 -> V_19 = V_20 ;
V_6 -> V_21 = V_2 -> V_21 ;
switch ( V_6 -> V_13 ) {
case V_22 :
F_3 ( V_6 ) ;
break;
case V_23 :
switch ( V_6 -> V_14 ) {
case V_24 :
F_4 ( V_6 ) ;
break;
case V_25 :
F_5 ( V_6 ) ;
break;
case V_26 :
case V_27 :
F_6 ( V_6 ) ;
break;
default:
return - V_7 ;
}
break;
default:
return - V_7 ;
}
F_7 ( V_6 ) ;
return 0 ;
}
int F_8 ( struct V_5 * V_6 )
{
if ( V_6 == NULL || V_6 -> V_28 == NULL )
return - V_7 ;
F_9 ( V_6 -> V_29 ) ;
F_9 ( V_6 -> V_30 ) ;
F_9 ( V_6 -> V_31 . V_32 ) ;
F_9 ( V_6 -> V_33 . V_32 ) ;
F_9 ( V_6 -> V_28 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
int F_10 ( struct V_5 * V_6 )
{
int V_34 ;
unsigned int V_35 ;
unsigned int V_36 ;
struct V_37 * V_38 ;
int V_39 ;
if ( V_6 -> V_40 -> V_41 == NULL )
return - V_7 ;
if ( V_6 -> V_40 -> V_42 == NULL )
return - V_7 ;
V_6 -> V_43 = V_36 = V_6 -> V_40 -> V_41 ( V_6 ) ;
V_6 -> V_44 = V_39 = V_6 -> V_40 -> V_42 ( V_6 ) +
sizeof( struct V_37 ) ;
V_6 -> V_28 = F_2 ( V_39 * V_36 , V_8 ) ;
if ( V_6 -> V_28 == NULL )
return - V_9 ;
V_38 = V_6 -> V_28 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_34 = V_6 -> V_40 -> V_45 ( V_6 , V_35 , V_38 ) ;
if ( V_38 -> V_46 . V_47 & V_48 ) {
V_6 -> V_49 = V_38 ;
V_6 -> V_50 = V_6 -> V_51 = V_38 ;
}
V_38 -> V_52 = V_35 + 1 ;
if ( V_38 -> V_46 . V_47 & V_53 )
V_6 -> V_54 = V_38 ;
V_38 = (struct V_37 * ) ( ( unsigned long ) V_38 + V_39 ) ;
}
return 0 ;
}
int F_11 ( struct V_5 * V_6 , T_1 V_55 ,
T_1 V_56 , T_1 V_57 )
{
T_1 V_35 ;
T_1 V_58 ;
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_12 ( V_59 L_1 ) ;
return - V_7 ;
}
for ( V_35 = 0 ; V_35 < V_6 -> V_17 ; V_35 ++ ) {
V_58 = F_13 ( V_6 -> V_12 , V_55 ) ;
if ( ( V_58 & V_57 ) == ( V_56 & V_57 ) )
break;
F_14 ( 1 ) ;
}
if ( V_35 == V_6 -> V_17 )
return - 1 ;
return 0 ;
}
int F_15 ( struct V_5 * V_6 ,
T_1 V_55 , T_1 V_56 , T_1 V_57 )
{
T_1 V_35 ;
T_1 V_58 ;
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_12 ( V_59 L_1 ) ;
return - V_7 ;
}
for ( V_35 = 0 ; V_35 < V_6 -> V_17 ; V_35 ++ ) {
V_58 = F_13 ( V_6 -> V_12 , V_55 ) ;
if ( ( V_58 & V_57 ) != ( V_56 & V_57 ) )
break;
F_14 ( 1 ) ;
}
if ( V_35 == V_6 -> V_17 )
return - 1 ;
return 0 ;
}
void F_16 ( struct V_5 * V_6 ,
T_1 V_60 ,
T_1 V_55 ,
T_1 V_56 ,
T_1 V_57 )
{
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_12 ( V_59 L_1 ) ;
return;
}
F_17 ( V_6 -> V_12 , V_60 , V_55 ) ;
F_11 ( V_6 , V_60 + 1 , V_57 , V_56 ) ;
}
void F_18 ( struct V_5 * V_6 ,
T_1 V_60 ,
T_1 V_55 ,
T_1 V_56 ,
T_1 V_57 )
{
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_12 ( V_59 L_1 ) ;
return;
}
F_17 ( V_6 -> V_12 , V_60 , V_55 ) ;
F_15 ( V_6 , V_60 + 1 ,
V_56 , V_57 ) ;
}
bool F_19 ( struct V_5 * V_6 )
{
return F_20 ( V_6 -> V_61 . V_62 , V_63 ) ;
}
bool F_21 ( struct V_5 * V_6 )
{
return F_20 ( V_6 -> V_61 . V_62 , V_64 ) ;
}
int F_22 ( struct V_65 * V_66 )
{
T_1 V_35 , V_67 ;
T_2 V_68 ;
bool V_69 = false ;
struct V_65 * V_70 ;
F_23 ((NULL != vol_table),
L_2 , return -EINVAL) ;
V_70 = F_2 ( sizeof( struct V_65 ) ,
V_8 ) ;
if ( NULL == V_70 )
return - V_7 ;
V_70 -> V_71 = V_66 -> V_71 ;
V_70 -> V_72 = V_66 -> V_72 ;
for ( V_35 = 0 ; V_35 < V_66 -> V_73 ; V_35 ++ ) {
V_68 = V_66 -> V_74 [ V_35 ] . V_56 ;
V_69 = false ;
for ( V_67 = 0 ; V_67 < V_70 -> V_73 ; V_67 ++ ) {
if ( V_68 == V_70 -> V_74 [ V_67 ] . V_56 ) {
V_69 = true ;
break;
}
}
if ( ! V_69 ) {
V_70 -> V_74 [ V_70 -> V_73 ] . V_56 = V_68 ;
V_70 -> V_74 [ V_70 -> V_73 ] . V_75 =
V_66 -> V_74 [ V_35 ] . V_75 ;
V_70 -> V_73 ++ ;
}
}
memcpy ( V_66 , V_70 , sizeof( struct V_65 ) ) ;
F_9 ( V_70 ) ;
return 0 ;
}
int F_24 ( struct V_65 * V_66 ,
T_3 * V_76 )
{
T_1 V_35 ;
int V_34 ;
F_23 ((0 != dep_table->count),
L_3 , return -EINVAL) ;
F_23 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_66 -> V_71 = 0 ;
V_66 -> V_72 = 0 ;
V_66 -> V_73 = V_76 -> V_73 ;
for ( V_35 = 0 ; V_35 < V_76 -> V_73 ; V_35 ++ ) {
V_66 -> V_74 [ V_35 ] . V_56 = V_76 -> V_74 [ V_35 ] . V_77 ;
V_66 -> V_74 [ V_35 ] . V_75 = 0 ;
}
V_34 = F_22 ( V_66 ) ;
F_23 ((0 == result),
L_5 , return result) ;
return 0 ;
}
int F_25 ( struct V_65 * V_66 ,
T_3 * V_76 )
{
T_1 V_35 ;
int V_34 ;
F_23 ((0 != dep_table->count),
L_3 , return -EINVAL) ;
F_23 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_66 -> V_71 = 0 ;
V_66 -> V_72 = 0 ;
V_66 -> V_73 = V_76 -> V_73 ;
for ( V_35 = 0 ; V_35 < V_76 -> V_73 ; V_35 ++ ) {
V_66 -> V_74 [ V_35 ] . V_56 = V_76 -> V_74 [ V_35 ] . V_78 ;
V_66 -> V_74 [ V_35 ] . V_75 = 0 ;
}
V_34 = F_22 ( V_66 ) ;
F_23 ((0 == result),
L_6 , return result) ;
return 0 ;
}
int F_26 ( struct V_65 * V_66 ,
T_4 * V_79 )
{
int V_35 = 0 ;
F_23 ((0 != lookup_table->count),
L_7 , return -EINVAL) ;
F_23 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_66 -> V_71 = 0 ;
V_66 -> V_72 = 0 ;
V_66 -> V_73 = V_79 -> V_73 ;
for ( V_35 = 0 ; V_35 < V_66 -> V_73 ; V_35 ++ ) {
V_66 -> V_74 [ V_35 ] . V_56 = V_79 -> V_74 [ V_35 ] . V_80 ;
V_66 -> V_74 [ V_35 ] . V_75 = 0 ;
}
return 0 ;
}
void F_27 ( T_1 V_81 ,
struct V_65 * V_66 )
{
unsigned int V_35 , V_82 ;
if ( V_66 -> V_73 <= V_81 )
return;
V_82 = V_66 -> V_73 - V_81 ;
for ( V_35 = 0 ; V_35 < V_81 ; V_35 ++ )
V_66 -> V_74 [ V_35 ] = V_66 -> V_74 [ V_35 + V_82 ] ;
V_66 -> V_73 = V_81 ;
return;
}
int F_28 ( void * V_70 ,
T_1 V_73 , int V_83 )
{
int V_35 ;
struct V_84 * V_85 = (struct V_84 * ) V_70 ;
F_23 ( V_73 <= V_83 ,
L_8 ,
) ;
V_85 -> V_73 = V_73 ;
for ( V_35 = 0 ; V_35 < V_83 ; V_35 ++ )
V_85 -> V_86 [ V_35 ] . V_87 = false ;
return 0 ;
}
void F_29 (
void * V_70 ,
T_1 V_55 , T_1 V_88 ,
T_1 V_89 )
{
struct V_84 * V_85 = (struct V_84 * ) V_70 ;
V_85 -> V_86 [ V_55 ] . V_56 = V_88 ;
V_85 -> V_86 [ V_55 ] . V_90 = V_89 ;
V_85 -> V_86 [ V_55 ] . V_87 = 1 ;
}
T_5 F_30 ( void * V_70 )
{
T_5 V_35 ;
T_5 V_57 = 0 ;
struct V_84 * V_85 = (struct V_84 * ) V_70 ;
for ( V_35 = V_85 -> V_73 ; V_35 > 0 ; V_35 -- ) {
V_57 = V_57 << 1 ;
if ( V_85 -> V_86 [ V_35 - 1 ] . V_87 )
V_57 |= 0x1 ;
else
V_57 &= 0xFFFFFFFE ;
}
return V_57 ;
}
T_6 F_31 (
struct T_4 * V_79 , T_2 V_91 )
{
T_6 V_73 = ( T_6 ) ( V_79 -> V_73 ) ;
T_6 V_35 ;
F_23 ((NULL != lookup_table),
L_9 , return 0 ) ;
F_23 ((0 != count),
L_9 , return 0 ) ;
for ( V_35 = 0 ; V_35 < V_79 -> V_73 ; V_35 ++ ) {
if ( V_79 -> V_74 [ V_35 ] . V_80 >= V_91 )
return V_35 ;
}
return V_35 - 1 ;
}
T_2 F_32 ( struct V_65 * V_92 , T_2 V_78 )
{
T_1 V_35 ;
for ( V_35 = 0 ; V_35 < V_92 -> V_73 ; V_35 ++ ) {
if ( V_92 -> V_74 [ V_35 ] . V_56 >= V_78 )
return V_92 -> V_74 [ V_35 ] . V_56 ;
}
F_23 (false,
L_10 ,
return vddci_table->entries[i-1].value) ;
}
int F_33 ( void * V_70 ,
T_1 V_56 , T_1 * V_93 )
{
int V_34 = - V_7 ;
T_1 V_35 ;
struct V_84 * V_85 = (struct V_84 * ) V_70 ;
for ( V_35 = 0 ; V_35 < V_85 -> V_73 ; V_35 ++ ) {
if ( V_56 == V_85 -> V_86 [ V_35 ] . V_56 ) {
* V_93 = V_35 ;
V_34 = 0 ;
}
}
return V_34 ;
}
int F_34 ( struct V_5 * V_6 ,
T_4 * V_79 ,
T_2 V_94 , T_5 * V_95 )
{
T_6 V_96 ;
T_6 V_97 ;
struct V_98 * V_99 =
(struct V_98 * ) ( V_6 -> V_100 ) ;
F_23 (lookup_table->count != 0 , L_11 , return -EINVAL) ;
for ( V_96 = 0 ; V_96 < V_99 -> V_101 -> V_73 ; V_96 ++ ) {
V_97 = V_99 -> V_101 -> V_74 [ V_96 ] . V_102 ;
if ( V_79 -> V_74 [ V_97 ] . V_80 == V_94 )
break;
}
F_23 (entryId < table_info->vdd_dep_on_sclk->count,
L_12 ,
return -EINVAL;
) ;
* V_95 = V_99 -> V_101 -> V_74 [ V_96 ] . V_103 ;
return 0 ;
}
int F_35 ( struct V_5 * V_6 )
{
T_1 V_104 ;
struct V_105 * V_106 ;
struct V_98 * V_107 = (struct V_98 * ) ( V_6 -> V_100 ) ;
V_104 = sizeof( T_1 ) + 4 * sizeof( struct V_108 ) ;
V_106 = F_2 ( V_104 , V_8 ) ;
if ( NULL == V_106 ) {
F_12 ( V_59 L_13 ) ;
return - V_9 ;
} else {
V_106 -> V_73 = 4 ;
V_106 -> V_74 [ 0 ] . V_103 = V_109 ;
V_106 -> V_74 [ 0 ] . V_110 = 0 ;
V_106 -> V_74 [ 1 ] . V_103 = V_111 ;
V_106 -> V_74 [ 1 ] . V_110 = 720 ;
V_106 -> V_74 [ 2 ] . V_103 = V_112 ;
V_106 -> V_74 [ 2 ] . V_110 = 810 ;
V_106 -> V_74 [ 3 ] . V_103 = V_113 ;
V_106 -> V_74 [ 3 ] . V_110 = 900 ;
V_107 -> V_114 = V_106 ;
V_6 -> V_115 . V_114 = V_106 ;
}
return 0 ;
}
int F_36 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_115 . V_114 ) {
F_9 ( V_6 -> V_115 . V_114 ) ;
V_6 -> V_115 . V_114 = NULL ;
}
if ( NULL != V_6 -> V_30 ) {
F_9 ( V_6 -> V_30 ) ;
V_6 -> V_30 = NULL ;
}
return 0 ;
}
T_1 F_37 ( struct V_5 * V_6 , T_1 V_57 )
{
T_1 V_116 = 0 ;
while ( 0 == ( V_57 & ( 1 << V_116 ) ) )
V_116 ++ ;
return V_116 ;
}
void F_38 ( struct V_5 * V_6 )
{
struct V_98 * V_99 =
(struct V_98 * ) V_6 -> V_100 ;
struct V_105 * V_70 =
V_99 -> V_114 ;
struct T_3 * V_117 ;
enum V_118 V_119 = V_6 -> V_119 ;
T_1 V_120 = 0 , V_121 , V_35 ;
if ( ! V_70 || V_70 -> V_73 <= 0
|| V_119 < V_109
|| V_119 > V_113 )
return;
for ( V_35 = 0 ; V_35 < V_70 -> V_73 ; V_35 ++ ) {
if ( V_119 == V_70 -> V_74 [ V_35 ] . V_103 ) {
V_120 = V_70 -> V_74 [ V_35 ] . V_110 ;
break;
}
}
V_117 = V_99 -> V_101 ;
for ( V_35 = 0 ; V_35 < V_117 -> V_73 ; V_35 ++ ) {
if ( V_120 <= V_117 -> V_74 [ V_35 ] . V_122 ) {
V_121 = ( ( ( T_1 ) V_117 -> V_74 [ V_35 ] . V_122 ) * V_123 ) ;
F_39 ( V_6 -> V_10 ,
V_124 , V_121 ) ;
return;
}
}
F_12 ( V_59 L_14
L_15 ) ;
}
