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
default:
return - V_7 ;
}
break;
default:
return - V_7 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_7 ( struct V_5 * V_6 )
{
if ( V_6 == NULL || V_6 -> V_25 == NULL )
return - V_7 ;
F_8 ( V_6 -> V_25 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
int F_9 ( struct V_5 * V_6 )
{
int V_26 ;
unsigned int V_27 ;
unsigned int V_28 ;
struct V_29 * V_30 ;
int V_31 ;
if ( V_6 -> V_32 -> V_33 == NULL )
return - V_7 ;
if ( V_6 -> V_32 -> V_34 == NULL )
return - V_7 ;
V_6 -> V_35 = V_28 = V_6 -> V_32 -> V_33 ( V_6 ) ;
V_6 -> V_36 = V_31 = V_6 -> V_32 -> V_34 ( V_6 ) +
sizeof( struct V_29 ) ;
V_6 -> V_25 = F_2 ( V_31 * V_28 , V_8 ) ;
if ( V_6 -> V_25 == NULL )
return - V_9 ;
V_30 = V_6 -> V_25 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_26 = V_6 -> V_32 -> V_37 ( V_6 , V_27 , V_30 ) ;
if ( V_30 -> V_38 . V_39 & V_40 ) {
V_6 -> V_41 = V_30 ;
V_6 -> V_42 = V_6 -> V_43 = V_30 ;
}
V_30 -> V_44 = V_27 + 1 ;
if ( V_30 -> V_38 . V_39 & V_45 )
V_6 -> V_46 = V_30 ;
V_30 = (struct V_29 * ) ( ( unsigned long ) V_30 + V_31 ) ;
}
return 0 ;
}
int F_10 ( struct V_5 * V_6 , T_1 V_47 ,
T_1 V_48 , T_1 V_49 )
{
T_1 V_27 ;
T_1 V_50 ;
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_11 ( V_51 L_1 ) ;
return - V_7 ;
}
for ( V_27 = 0 ; V_27 < V_6 -> V_17 ; V_27 ++ ) {
V_50 = F_12 ( V_6 -> V_12 , V_47 ) ;
if ( ( V_50 & V_49 ) == ( V_48 & V_49 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_6 -> V_17 )
return - 1 ;
return 0 ;
}
int F_14 ( struct V_5 * V_6 ,
T_1 V_47 , T_1 V_48 , T_1 V_49 )
{
T_1 V_27 ;
T_1 V_50 ;
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_11 ( V_51 L_1 ) ;
return - V_7 ;
}
for ( V_27 = 0 ; V_27 < V_6 -> V_17 ; V_27 ++ ) {
V_50 = F_12 ( V_6 -> V_12 , V_47 ) ;
if ( ( V_50 & V_49 ) != ( V_48 & V_49 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_6 -> V_17 )
return - 1 ;
return 0 ;
}
void F_15 ( struct V_5 * V_6 ,
T_1 V_52 ,
T_1 V_47 ,
T_1 V_48 ,
T_1 V_49 )
{
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_11 ( V_51 L_1 ) ;
return;
}
F_16 ( V_6 -> V_12 , V_52 , V_47 ) ;
F_10 ( V_6 , V_52 + 1 , V_49 , V_48 ) ;
}
void F_17 ( struct V_5 * V_6 ,
T_1 V_52 ,
T_1 V_47 ,
T_1 V_48 ,
T_1 V_49 )
{
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_11 ( V_51 L_1 ) ;
return;
}
F_16 ( V_6 -> V_12 , V_52 , V_47 ) ;
F_14 ( V_6 , V_52 + 1 ,
V_48 , V_49 ) ;
}
bool F_18 ( struct V_5 * V_6 )
{
return F_19 ( V_6 -> V_53 . V_54 , V_55 ) ;
}
bool F_20 ( struct V_5 * V_6 )
{
return F_19 ( V_6 -> V_53 . V_54 , V_56 ) ;
}
int F_21 ( struct V_57 * V_58 )
{
T_1 V_27 , V_59 ;
T_2 V_60 ;
bool V_61 = false ;
struct V_57 * V_62 ;
F_22 ((NULL != vol_table),
L_2 , return -EINVAL) ;
V_62 = F_2 ( sizeof( struct V_57 ) ,
V_8 ) ;
if ( NULL == V_62 )
return - V_7 ;
V_62 -> V_63 = V_58 -> V_63 ;
V_62 -> V_64 = V_58 -> V_64 ;
for ( V_27 = 0 ; V_27 < V_58 -> V_65 ; V_27 ++ ) {
V_60 = V_58 -> V_66 [ V_27 ] . V_48 ;
V_61 = false ;
for ( V_59 = 0 ; V_59 < V_62 -> V_65 ; V_59 ++ ) {
if ( V_60 == V_62 -> V_66 [ V_59 ] . V_48 ) {
V_61 = true ;
break;
}
}
if ( ! V_61 ) {
V_62 -> V_66 [ V_62 -> V_65 ] . V_48 = V_60 ;
V_62 -> V_66 [ V_62 -> V_65 ] . V_67 =
V_58 -> V_66 [ V_27 ] . V_67 ;
V_62 -> V_65 ++ ;
}
}
memcpy ( V_58 , V_62 , sizeof( struct V_57 ) ) ;
F_8 ( V_62 ) ;
return 0 ;
}
int F_23 ( struct V_57 * V_58 ,
T_3 * V_68 )
{
T_1 V_27 ;
int V_26 ;
F_22 ((0 != dep_table->count),
L_3 , return -EINVAL) ;
F_22 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_58 -> V_63 = 0 ;
V_58 -> V_64 = 0 ;
V_58 -> V_65 = V_68 -> V_65 ;
for ( V_27 = 0 ; V_27 < V_68 -> V_65 ; V_27 ++ ) {
V_58 -> V_66 [ V_27 ] . V_48 = V_68 -> V_66 [ V_27 ] . V_69 ;
V_58 -> V_66 [ V_27 ] . V_67 = 0 ;
}
V_26 = F_21 ( V_58 ) ;
F_22 ((0 == result),
L_5 , return result) ;
return 0 ;
}
int F_24 ( struct V_57 * V_58 ,
T_3 * V_68 )
{
T_1 V_27 ;
int V_26 ;
F_22 ((0 != dep_table->count),
L_3 , return -EINVAL) ;
F_22 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_58 -> V_63 = 0 ;
V_58 -> V_64 = 0 ;
V_58 -> V_65 = V_68 -> V_65 ;
for ( V_27 = 0 ; V_27 < V_68 -> V_65 ; V_27 ++ ) {
V_58 -> V_66 [ V_27 ] . V_48 = V_68 -> V_66 [ V_27 ] . V_70 ;
V_58 -> V_66 [ V_27 ] . V_67 = 0 ;
}
V_26 = F_21 ( V_58 ) ;
F_22 ((0 == result),
L_6 , return result) ;
return 0 ;
}
int F_25 ( struct V_57 * V_58 ,
T_4 * V_71 )
{
int V_27 = 0 ;
F_22 ((0 != lookup_table->count),
L_7 , return -EINVAL) ;
F_22 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_58 -> V_63 = 0 ;
V_58 -> V_64 = 0 ;
V_58 -> V_65 = V_71 -> V_65 ;
for ( V_27 = 0 ; V_27 < V_58 -> V_65 ; V_27 ++ ) {
V_58 -> V_66 [ V_27 ] . V_48 = V_71 -> V_66 [ V_27 ] . V_72 ;
V_58 -> V_66 [ V_27 ] . V_67 = 0 ;
}
return 0 ;
}
void F_26 ( T_1 V_73 ,
struct V_57 * V_58 )
{
unsigned int V_27 , V_74 ;
if ( V_58 -> V_65 <= V_73 )
return;
V_74 = V_58 -> V_65 - V_73 ;
for ( V_27 = 0 ; V_27 < V_73 ; V_27 ++ )
V_58 -> V_66 [ V_27 ] = V_58 -> V_66 [ V_27 + V_74 ] ;
V_58 -> V_65 = V_73 ;
return;
}
int F_27 ( void * V_62 ,
T_1 V_65 , int V_75 )
{
int V_27 ;
struct V_76 * V_77 = (struct V_76 * ) V_62 ;
F_22 ( V_65 <= V_75 ,
L_8 ,
) ;
V_77 -> V_65 = V_65 ;
for ( V_27 = 0 ; V_27 < V_75 ; V_27 ++ )
V_77 -> V_78 [ V_27 ] . V_79 = false ;
return 0 ;
}
void F_28 (
void * V_62 ,
T_1 V_47 , T_1 V_80 ,
T_1 V_81 )
{
struct V_76 * V_77 = (struct V_76 * ) V_62 ;
V_77 -> V_78 [ V_47 ] . V_48 = V_80 ;
V_77 -> V_78 [ V_47 ] . V_82 = V_81 ;
V_77 -> V_78 [ V_47 ] . V_79 = 1 ;
}
T_5 F_29 ( void * V_62 )
{
T_5 V_27 ;
T_5 V_49 = 0 ;
struct V_76 * V_77 = (struct V_76 * ) V_62 ;
for ( V_27 = V_77 -> V_65 ; V_27 > 0 ; V_27 -- ) {
V_49 = V_49 << 1 ;
if ( V_77 -> V_78 [ V_27 - 1 ] . V_79 )
V_49 |= 0x1 ;
else
V_49 &= 0xFFFFFFFE ;
}
return V_49 ;
}
T_6 F_30 (
struct T_4 * V_71 , T_2 V_83 )
{
T_6 V_65 = ( T_6 ) ( V_71 -> V_65 ) ;
T_6 V_27 ;
F_22 ((NULL != lookup_table),
L_9 , return 0 ) ;
F_22 ((0 != count),
L_9 , return 0 ) ;
for ( V_27 = 0 ; V_27 < V_71 -> V_65 ; V_27 ++ ) {
if ( V_71 -> V_66 [ V_27 ] . V_72 >= V_83 )
return V_27 ;
}
return V_27 - 1 ;
}
T_2 F_31 ( struct V_57 * V_84 , T_2 V_70 )
{
T_1 V_27 ;
for ( V_27 = 0 ; V_27 < V_84 -> V_65 ; V_27 ++ ) {
if ( V_84 -> V_66 [ V_27 ] . V_48 >= V_70 )
return V_84 -> V_66 [ V_27 ] . V_48 ;
}
F_22 (false,
L_10 ,
return vddci_table->entries[i].value) ;
}
int F_32 ( void * V_62 ,
T_1 V_48 , T_1 * V_85 )
{
int V_26 = - V_7 ;
T_1 V_27 ;
struct V_76 * V_77 = (struct V_76 * ) V_62 ;
for ( V_27 = 0 ; V_27 < V_77 -> V_65 ; V_27 ++ ) {
if ( V_48 == V_77 -> V_78 [ V_27 ] . V_48 ) {
* V_85 = V_27 ;
V_26 = 0 ;
}
}
return V_26 ;
}
int F_33 ( struct V_5 * V_6 ,
T_4 * V_71 ,
T_2 V_86 , T_5 * V_87 )
{
T_6 V_88 ;
T_6 V_89 ;
struct V_90 * V_91 =
(struct V_90 * ) ( V_6 -> V_92 ) ;
F_22 (lookup_table->count != 0 , L_11 , return -EINVAL) ;
for ( V_88 = 0 ; V_88 < V_91 -> V_93 -> V_65 ; V_88 ++ ) {
V_89 = V_91 -> V_93 -> V_66 [ V_88 ] . V_94 ;
if ( V_71 -> V_66 [ V_89 ] . V_72 == V_86 )
break;
}
F_22 (entryId < table_info->vdd_dep_on_sclk->count,
L_12 ,
return -EINVAL;
) ;
* V_87 = V_91 -> V_93 -> V_66 [ V_88 ] . V_95 ;
return 0 ;
}
int F_34 ( struct V_5 * V_6 )
{
T_1 V_96 ;
struct V_97 * V_98 ;
struct V_90 * V_99 = (struct V_90 * ) ( V_6 -> V_92 ) ;
V_96 = sizeof( T_1 ) + 4 * sizeof( struct V_100 ) ;
V_98 = (struct V_97 * ) F_2 ( V_96 , V_8 ) ;
if ( NULL == V_98 ) {
F_11 ( V_51 L_13 ) ;
return - V_9 ;
} else {
V_98 -> V_65 = 4 ;
V_98 -> V_66 [ 0 ] . V_95 = V_101 ;
V_98 -> V_66 [ 0 ] . V_102 = 0 ;
V_98 -> V_66 [ 1 ] . V_95 = V_103 ;
V_98 -> V_66 [ 1 ] . V_102 = 720 ;
V_98 -> V_66 [ 2 ] . V_95 = V_104 ;
V_98 -> V_66 [ 2 ] . V_102 = 810 ;
V_98 -> V_66 [ 3 ] . V_95 = V_105 ;
V_98 -> V_66 [ 3 ] . V_102 = 900 ;
V_99 -> V_106 = V_98 ;
V_6 -> V_107 . V_106 = V_98 ;
}
return 0 ;
}
int F_35 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_107 . V_106 ) {
F_8 ( V_6 -> V_107 . V_106 ) ;
V_6 -> V_107 . V_106 = NULL ;
}
if ( NULL != V_6 -> V_108 ) {
F_8 ( V_6 -> V_108 ) ;
V_6 -> V_108 = NULL ;
}
return 0 ;
}
T_1 F_36 ( struct V_5 * V_6 , T_1 V_49 )
{
T_1 V_109 = 0 ;
while ( 0 == ( V_49 & ( 1 << V_109 ) ) )
V_109 ++ ;
return V_109 ;
}
