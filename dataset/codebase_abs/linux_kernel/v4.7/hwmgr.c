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
switch ( V_6 -> V_13 ) {
case V_21 :
F_3 ( V_6 ) ;
break;
case V_22 :
switch ( V_6 -> V_14 ) {
case V_23 :
F_4 ( V_6 ) ;
break;
case V_24 :
F_5 ( V_6 ) ;
break;
case V_25 :
case V_26 :
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
if ( V_6 == NULL || V_6 -> V_27 == NULL )
return - V_7 ;
F_9 ( V_6 -> V_28 ) ;
F_9 ( V_6 -> V_29 . V_30 ) ;
F_9 ( V_6 -> V_31 . V_30 ) ;
F_9 ( V_6 -> V_27 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
int F_10 ( struct V_5 * V_6 )
{
int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
struct V_35 * V_36 ;
int V_37 ;
if ( V_6 -> V_38 -> V_39 == NULL )
return - V_7 ;
if ( V_6 -> V_38 -> V_40 == NULL )
return - V_7 ;
V_6 -> V_41 = V_34 = V_6 -> V_38 -> V_39 ( V_6 ) ;
V_6 -> V_42 = V_37 = V_6 -> V_38 -> V_40 ( V_6 ) +
sizeof( struct V_35 ) ;
V_6 -> V_27 = F_2 ( V_37 * V_34 , V_8 ) ;
if ( V_6 -> V_27 == NULL )
return - V_9 ;
V_36 = V_6 -> V_27 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_32 = V_6 -> V_38 -> V_43 ( V_6 , V_33 , V_36 ) ;
if ( V_36 -> V_44 . V_45 & V_46 ) {
V_6 -> V_47 = V_36 ;
V_6 -> V_48 = V_6 -> V_49 = V_36 ;
}
V_36 -> V_50 = V_33 + 1 ;
if ( V_36 -> V_44 . V_45 & V_51 )
V_6 -> V_52 = V_36 ;
V_36 = (struct V_35 * ) ( ( unsigned long ) V_36 + V_37 ) ;
}
return 0 ;
}
int F_11 ( struct V_5 * V_6 , T_1 V_53 ,
T_1 V_54 , T_1 V_55 )
{
T_1 V_33 ;
T_1 V_56 ;
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_12 ( V_57 L_1 ) ;
return - V_7 ;
}
for ( V_33 = 0 ; V_33 < V_6 -> V_17 ; V_33 ++ ) {
V_56 = F_13 ( V_6 -> V_12 , V_53 ) ;
if ( ( V_56 & V_55 ) == ( V_54 & V_55 ) )
break;
F_14 ( 1 ) ;
}
if ( V_33 == V_6 -> V_17 )
return - 1 ;
return 0 ;
}
int F_15 ( struct V_5 * V_6 ,
T_1 V_53 , T_1 V_54 , T_1 V_55 )
{
T_1 V_33 ;
T_1 V_56 ;
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_12 ( V_57 L_1 ) ;
return - V_7 ;
}
for ( V_33 = 0 ; V_33 < V_6 -> V_17 ; V_33 ++ ) {
V_56 = F_13 ( V_6 -> V_12 , V_53 ) ;
if ( ( V_56 & V_55 ) != ( V_54 & V_55 ) )
break;
F_14 ( 1 ) ;
}
if ( V_33 == V_6 -> V_17 )
return - 1 ;
return 0 ;
}
void F_16 ( struct V_5 * V_6 ,
T_1 V_58 ,
T_1 V_53 ,
T_1 V_54 ,
T_1 V_55 )
{
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_12 ( V_57 L_1 ) ;
return;
}
F_17 ( V_6 -> V_12 , V_58 , V_53 ) ;
F_11 ( V_6 , V_58 + 1 , V_55 , V_54 ) ;
}
void F_18 ( struct V_5 * V_6 ,
T_1 V_58 ,
T_1 V_53 ,
T_1 V_54 ,
T_1 V_55 )
{
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_12 ( V_57 L_1 ) ;
return;
}
F_17 ( V_6 -> V_12 , V_58 , V_53 ) ;
F_15 ( V_6 , V_58 + 1 ,
V_54 , V_55 ) ;
}
bool F_19 ( struct V_5 * V_6 )
{
return F_20 ( V_6 -> V_59 . V_60 , V_61 ) ;
}
bool F_21 ( struct V_5 * V_6 )
{
return F_20 ( V_6 -> V_59 . V_60 , V_62 ) ;
}
int F_22 ( struct V_63 * V_64 )
{
T_1 V_33 , V_65 ;
T_2 V_66 ;
bool V_67 = false ;
struct V_63 * V_68 ;
F_23 ((NULL != vol_table),
L_2 , return -EINVAL) ;
V_68 = F_2 ( sizeof( struct V_63 ) ,
V_8 ) ;
if ( NULL == V_68 )
return - V_7 ;
V_68 -> V_69 = V_64 -> V_69 ;
V_68 -> V_70 = V_64 -> V_70 ;
for ( V_33 = 0 ; V_33 < V_64 -> V_71 ; V_33 ++ ) {
V_66 = V_64 -> V_72 [ V_33 ] . V_54 ;
V_67 = false ;
for ( V_65 = 0 ; V_65 < V_68 -> V_71 ; V_65 ++ ) {
if ( V_66 == V_68 -> V_72 [ V_65 ] . V_54 ) {
V_67 = true ;
break;
}
}
if ( ! V_67 ) {
V_68 -> V_72 [ V_68 -> V_71 ] . V_54 = V_66 ;
V_68 -> V_72 [ V_68 -> V_71 ] . V_73 =
V_64 -> V_72 [ V_33 ] . V_73 ;
V_68 -> V_71 ++ ;
}
}
memcpy ( V_64 , V_68 , sizeof( struct V_63 ) ) ;
F_9 ( V_68 ) ;
return 0 ;
}
int F_24 ( struct V_63 * V_64 ,
T_3 * V_74 )
{
T_1 V_33 ;
int V_32 ;
F_23 ((0 != dep_table->count),
L_3 , return -EINVAL) ;
F_23 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_64 -> V_69 = 0 ;
V_64 -> V_70 = 0 ;
V_64 -> V_71 = V_74 -> V_71 ;
for ( V_33 = 0 ; V_33 < V_74 -> V_71 ; V_33 ++ ) {
V_64 -> V_72 [ V_33 ] . V_54 = V_74 -> V_72 [ V_33 ] . V_75 ;
V_64 -> V_72 [ V_33 ] . V_73 = 0 ;
}
V_32 = F_22 ( V_64 ) ;
F_23 ((0 == result),
L_5 , return result) ;
return 0 ;
}
int F_25 ( struct V_63 * V_64 ,
T_3 * V_74 )
{
T_1 V_33 ;
int V_32 ;
F_23 ((0 != dep_table->count),
L_3 , return -EINVAL) ;
F_23 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_64 -> V_69 = 0 ;
V_64 -> V_70 = 0 ;
V_64 -> V_71 = V_74 -> V_71 ;
for ( V_33 = 0 ; V_33 < V_74 -> V_71 ; V_33 ++ ) {
V_64 -> V_72 [ V_33 ] . V_54 = V_74 -> V_72 [ V_33 ] . V_76 ;
V_64 -> V_72 [ V_33 ] . V_73 = 0 ;
}
V_32 = F_22 ( V_64 ) ;
F_23 ((0 == result),
L_6 , return result) ;
return 0 ;
}
int F_26 ( struct V_63 * V_64 ,
T_4 * V_77 )
{
int V_33 = 0 ;
F_23 ((0 != lookup_table->count),
L_7 , return -EINVAL) ;
F_23 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_64 -> V_69 = 0 ;
V_64 -> V_70 = 0 ;
V_64 -> V_71 = V_77 -> V_71 ;
for ( V_33 = 0 ; V_33 < V_64 -> V_71 ; V_33 ++ ) {
V_64 -> V_72 [ V_33 ] . V_54 = V_77 -> V_72 [ V_33 ] . V_78 ;
V_64 -> V_72 [ V_33 ] . V_73 = 0 ;
}
return 0 ;
}
void F_27 ( T_1 V_79 ,
struct V_63 * V_64 )
{
unsigned int V_33 , V_80 ;
if ( V_64 -> V_71 <= V_79 )
return;
V_80 = V_64 -> V_71 - V_79 ;
for ( V_33 = 0 ; V_33 < V_79 ; V_33 ++ )
V_64 -> V_72 [ V_33 ] = V_64 -> V_72 [ V_33 + V_80 ] ;
V_64 -> V_71 = V_79 ;
return;
}
int F_28 ( void * V_68 ,
T_1 V_71 , int V_81 )
{
int V_33 ;
struct V_82 * V_83 = (struct V_82 * ) V_68 ;
F_23 ( V_71 <= V_81 ,
L_8 ,
) ;
V_83 -> V_71 = V_71 ;
for ( V_33 = 0 ; V_33 < V_81 ; V_33 ++ )
V_83 -> V_84 [ V_33 ] . V_85 = false ;
return 0 ;
}
void F_29 (
void * V_68 ,
T_1 V_53 , T_1 V_86 ,
T_1 V_87 )
{
struct V_82 * V_83 = (struct V_82 * ) V_68 ;
V_83 -> V_84 [ V_53 ] . V_54 = V_86 ;
V_83 -> V_84 [ V_53 ] . V_88 = V_87 ;
V_83 -> V_84 [ V_53 ] . V_85 = 1 ;
}
T_5 F_30 ( void * V_68 )
{
T_5 V_33 ;
T_5 V_55 = 0 ;
struct V_82 * V_83 = (struct V_82 * ) V_68 ;
for ( V_33 = V_83 -> V_71 ; V_33 > 0 ; V_33 -- ) {
V_55 = V_55 << 1 ;
if ( V_83 -> V_84 [ V_33 - 1 ] . V_85 )
V_55 |= 0x1 ;
else
V_55 &= 0xFFFFFFFE ;
}
return V_55 ;
}
T_6 F_31 (
struct T_4 * V_77 , T_2 V_89 )
{
T_6 V_71 = ( T_6 ) ( V_77 -> V_71 ) ;
T_6 V_33 ;
F_23 ((NULL != lookup_table),
L_9 , return 0 ) ;
F_23 ((0 != count),
L_9 , return 0 ) ;
for ( V_33 = 0 ; V_33 < V_77 -> V_71 ; V_33 ++ ) {
if ( V_77 -> V_72 [ V_33 ] . V_78 >= V_89 )
return V_33 ;
}
return V_33 - 1 ;
}
T_2 F_32 ( struct V_63 * V_90 , T_2 V_76 )
{
T_1 V_33 ;
for ( V_33 = 0 ; V_33 < V_90 -> V_71 ; V_33 ++ ) {
if ( V_90 -> V_72 [ V_33 ] . V_54 >= V_76 )
return V_90 -> V_72 [ V_33 ] . V_54 ;
}
F_23 (false,
L_10 ,
return vddci_table->entries[i-1].value) ;
}
int F_33 ( void * V_68 ,
T_1 V_54 , T_1 * V_91 )
{
int V_32 = - V_7 ;
T_1 V_33 ;
struct V_82 * V_83 = (struct V_82 * ) V_68 ;
for ( V_33 = 0 ; V_33 < V_83 -> V_71 ; V_33 ++ ) {
if ( V_54 == V_83 -> V_84 [ V_33 ] . V_54 ) {
* V_91 = V_33 ;
V_32 = 0 ;
}
}
return V_32 ;
}
int F_34 ( struct V_5 * V_6 ,
T_4 * V_77 ,
T_2 V_92 , T_5 * V_93 )
{
T_6 V_94 ;
T_6 V_95 ;
struct V_96 * V_97 =
(struct V_96 * ) ( V_6 -> V_98 ) ;
F_23 (lookup_table->count != 0 , L_11 , return -EINVAL) ;
for ( V_94 = 0 ; V_94 < V_97 -> V_99 -> V_71 ; V_94 ++ ) {
V_95 = V_97 -> V_99 -> V_72 [ V_94 ] . V_100 ;
if ( V_77 -> V_72 [ V_95 ] . V_78 == V_92 )
break;
}
F_23 (entryId < table_info->vdd_dep_on_sclk->count,
L_12 ,
return -EINVAL;
) ;
* V_93 = V_97 -> V_99 -> V_72 [ V_94 ] . V_101 ;
return 0 ;
}
int F_35 ( struct V_5 * V_6 )
{
T_1 V_102 ;
struct V_103 * V_104 ;
struct V_96 * V_105 = (struct V_96 * ) ( V_6 -> V_98 ) ;
V_102 = sizeof( T_1 ) + 4 * sizeof( struct V_106 ) ;
V_104 = (struct V_103 * ) F_2 ( V_102 , V_8 ) ;
if ( NULL == V_104 ) {
F_12 ( V_57 L_13 ) ;
return - V_9 ;
} else {
V_104 -> V_71 = 4 ;
V_104 -> V_72 [ 0 ] . V_101 = V_107 ;
V_104 -> V_72 [ 0 ] . V_108 = 0 ;
V_104 -> V_72 [ 1 ] . V_101 = V_109 ;
V_104 -> V_72 [ 1 ] . V_108 = 720 ;
V_104 -> V_72 [ 2 ] . V_101 = V_110 ;
V_104 -> V_72 [ 2 ] . V_108 = 810 ;
V_104 -> V_72 [ 3 ] . V_101 = V_111 ;
V_104 -> V_72 [ 3 ] . V_108 = 900 ;
V_105 -> V_112 = V_104 ;
V_6 -> V_113 . V_112 = V_104 ;
}
return 0 ;
}
int F_36 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_113 . V_112 ) {
F_9 ( V_6 -> V_113 . V_112 ) ;
V_6 -> V_113 . V_112 = NULL ;
}
if ( NULL != V_6 -> V_28 ) {
F_9 ( V_6 -> V_28 ) ;
V_6 -> V_28 = NULL ;
}
return 0 ;
}
T_1 F_37 ( struct V_5 * V_6 , T_1 V_55 )
{
T_1 V_114 = 0 ;
while ( 0 == ( V_55 & ( 1 << V_114 ) ) )
V_114 ++ ;
return V_114 ;
}
void F_38 ( struct V_5 * V_6 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_6 -> V_98 ;
struct V_103 * V_68 =
V_97 -> V_112 ;
struct T_3 * V_115 ;
enum V_116 V_117 = V_6 -> V_117 ;
T_1 V_118 = 0 , V_119 , V_33 ;
if ( ! V_68 || V_68 -> V_71 <= 0
|| V_117 < V_107
|| V_117 > V_111 )
return;
for ( V_33 = 0 ; V_33 < V_68 -> V_71 ; V_33 ++ ) {
if ( V_117 == V_68 -> V_72 [ V_33 ] . V_101 ) {
V_118 = V_68 -> V_72 [ V_33 ] . V_108 ;
break;
}
}
V_115 = V_97 -> V_99 ;
for ( V_33 = 0 ; V_33 < V_115 -> V_71 ; V_33 ++ ) {
if ( V_118 <= V_115 -> V_72 [ V_33 ] . V_120 ) {
V_119 = ( ( ( T_1 ) V_115 -> V_72 [ V_33 ] . V_120 ) * V_121 ) ;
F_39 ( V_6 -> V_10 ,
V_122 , V_119 ) ;
return;
}
}
F_12 ( V_57 L_14
L_15 ) ;
}
