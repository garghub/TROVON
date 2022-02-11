static T_1 int F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static T_1 int F_2 ( char * V_1 )
{
if ( ! V_1 )
return - V_3 ;
if ( ! strncmp ( V_1 , L_1 , 2 ) )
V_2 = 0 ;
else if ( ! strncmp ( V_1 , L_2 , 3 ) )
V_2 = 1 ;
else if ( ! strncmp ( V_1 , L_3 , 5 ) )
V_4 = 1 ;
return 0 ;
}
static struct V_5 * V_5 ( unsigned int V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 ? & V_8 -> V_5 : NULL ;
}
int F_4 ( int V_6 , struct V_9 * V_10 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
unsigned long V_12 ;
int V_13 ;
if ( ! V_10 || ! V_11 )
return - 1 ;
F_5 ( & V_14 , V_12 ) ;
V_13 = V_11 -> V_15 + V_11 -> V_16 ;
* V_10 = * ( V_11 -> V_17 -> V_18 -> V_19 + V_13 ) ;
F_6 ( & V_14 , V_12 ) ;
return 0 ;
}
int F_7 ( struct V_20 * V_17 , int V_6 , T_2 V_21 )
{
struct V_18 * V_22 = V_17 -> V_18 ;
struct V_5 * V_11 = V_5 ( V_6 ) ;
T_2 V_13 , V_23 ;
unsigned int V_24 = 0 ;
unsigned long V_12 ;
int V_25 ;
if ( ! V_21 || ! V_11 )
return - 1 ;
V_13 = V_23 = 0 ;
if ( V_21 > 1 ) {
V_21 = F_8 ( V_21 ) ;
V_24 = F_9 ( V_21 ) ;
}
if ( V_24 > F_10 ( V_17 -> V_26 ) ) {
F_11 ( V_27
L_4
L_5 , V_24 ,
F_10 ( V_17 -> V_26 ) ) ;
return - 1 ;
}
F_5 ( & V_14 , V_12 ) ;
do {
for ( V_25 = V_13 ; V_25 < V_13 + V_21 ; V_25 ++ )
if ( V_22 -> V_19 [ V_25 ] . V_28 )
break;
if ( V_25 == V_13 + V_21 )
break;
V_13 = ( V_13 + V_21 ) % V_29 ;
if ( V_13 == V_23 ) {
F_6 ( & V_14 , V_12 ) ;
F_11 ( V_27 L_6 ) ;
return - 1 ;
}
} while ( 1 );
for ( V_25 = V_13 ; V_25 < V_13 + V_21 ; V_25 ++ )
V_22 -> V_19 [ V_25 ] . V_28 = 1 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_15 = V_13 ;
V_11 -> V_16 = 0 ;
V_11 -> V_30 = V_24 ;
F_6 ( & V_14 , V_12 ) ;
return V_13 ;
}
static int F_12 ( struct V_20 * V_17 , int V_13 , int V_24 )
{
struct V_31 V_32 ;
V_32 . V_33 = F_13 ( V_13 ) | V_34 | F_14 ( V_24 )
| V_35 ;
V_32 . V_36 = 0 ;
return F_15 ( & V_32 , V_17 ) ;
}
int F_16 ( int V_6 , T_2 * V_16 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
unsigned long V_12 ;
int V_13 ;
if ( ! V_11 )
return - 1 ;
F_5 ( & V_14 , V_12 ) ;
* V_16 = V_11 -> V_16 ;
V_13 = V_11 -> V_15 ;
F_6 ( & V_14 , V_12 ) ;
return V_13 ;
}
int F_17 ( int V_6 , struct V_20 * V_17 , T_2 V_13 , T_2 V_37 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
unsigned long V_12 ;
if ( ! V_11 )
return - 1 ;
F_5 ( & V_14 , V_12 ) ;
V_11 -> V_17 = V_17 ;
V_11 -> V_15 = V_13 ;
V_11 -> V_16 = V_37 ;
V_11 -> V_30 = 0 ;
F_6 ( & V_14 , V_12 ) ;
return 0 ;
}
int F_18 ( int V_6 , struct V_9 * V_38 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
struct V_20 * V_17 ;
unsigned long V_12 ;
struct V_9 * V_9 ;
int V_39 , V_13 ;
if ( ! V_11 )
return - 1 ;
F_5 ( & V_14 , V_12 ) ;
V_17 = V_11 -> V_17 ;
V_13 = V_11 -> V_15 + V_11 -> V_16 ;
V_9 = & V_17 -> V_18 -> V_19 [ V_13 ] ;
F_19 ( & V_9 -> V_33 , V_38 -> V_33 ) ;
F_19 ( & V_9 -> V_36 , V_38 -> V_36 ) ;
F_20 ( V_17 , V_9 , sizeof( * V_9 ) ) ;
V_39 = F_12 ( V_17 , V_13 , 0 ) ;
F_6 ( & V_14 , V_12 ) ;
return V_39 ;
}
struct V_20 * F_21 ( T_3 V_40 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ )
if ( V_42 [ V_25 ] . V_43 == V_40 )
return V_42 [ V_25 ] . V_17 ;
return NULL ;
}
struct V_20 * F_22 ( int V_44 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_45 ; V_25 ++ )
if ( V_46 [ V_25 ] . V_43 == V_44 )
return V_46 [ V_25 ] . V_17 ;
return NULL ;
}
struct V_20 * F_23 ( struct V_47 * V_48 )
{
struct V_49 * V_50 ;
V_50 = F_24 ( V_48 ) ;
if ( ! V_50 )
return NULL ;
return V_50 -> V_17 ;
}
static int F_25 ( struct V_5 * V_11 )
{
struct V_9 * V_51 , * V_10 , * V_52 ;
struct V_20 * V_17 ;
int V_13 ;
if ( V_11 -> V_16 )
return 0 ;
V_17 = V_11 -> V_17 ;
V_13 = V_11 -> V_15 + V_11 -> V_16 ;
V_51 = V_17 -> V_18 -> V_19 + V_13 ;
V_52 = V_51 + ( 1 << V_11 -> V_30 ) ;
for ( V_10 = V_51 ; V_10 < V_52 ; V_10 ++ ) {
F_19 ( & V_10 -> V_33 , 0 ) ;
F_19 ( & V_10 -> V_36 , 0 ) ;
}
return F_12 ( V_17 , V_13 , V_11 -> V_30 ) ;
}
int F_26 ( int V_6 )
{
struct V_5 * V_11 = V_5 ( V_6 ) ;
unsigned long V_12 ;
int V_39 ;
if ( ! V_11 )
return - 1 ;
F_5 ( & V_14 , V_12 ) ;
V_39 = F_25 ( V_11 ) ;
V_11 -> V_17 = NULL ;
V_11 -> V_15 = 0 ;
V_11 -> V_16 = 0 ;
V_11 -> V_30 = 0 ;
F_6 ( & V_14 , V_12 ) ;
return V_39 ;
}
static void F_27 ( struct V_9 * V_9 , unsigned int V_53 ,
unsigned int V_54 , unsigned int V_55 )
{
if ( V_4 )
V_53 = V_56 ;
V_9 -> V_53 = V_53 ;
V_9 -> V_54 = V_54 ;
V_9 -> V_55 = V_55 ;
}
int F_28 ( struct V_9 * V_9 , int V_44 )
{
int V_25 ;
T_2 V_55 = 0 ;
if ( ! V_9 )
return - 1 ;
for ( V_25 = 0 ; V_25 < V_45 ; V_25 ++ ) {
if ( V_46 [ V_25 ] . V_43 == V_44 ) {
V_55 = ( V_46 [ V_25 ] . V_57 << 8 ) | V_46 [ V_25 ] . V_58 ;
break;
}
}
if ( V_55 == 0 ) {
F_29 ( L_7 , V_44 ) ;
return - 1 ;
}
F_27 ( V_9 , 1 , 0 , V_55 ) ;
return 0 ;
}
int F_30 ( struct V_9 * V_9 , T_3 V_43 )
{
int V_25 ;
T_2 V_55 = 0 ;
if ( ! V_9 )
return - 1 ;
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ ) {
if ( V_42 [ V_25 ] . V_43 == V_43 ) {
V_55 = ( V_42 [ V_25 ] . V_57 << 8 ) | V_42 [ V_25 ] . V_58 ;
break;
}
}
if ( V_55 == 0 ) {
F_29 ( L_8 , V_43 ) ;
return - 1 ;
}
F_27 ( V_9 , V_59 , V_60 , V_55 ) ;
return 0 ;
}
int F_31 ( struct V_9 * V_9 , struct V_47 * V_48 )
{
struct V_47 * V_61 ;
if ( ! V_9 || ! V_48 )
return - 1 ;
if ( F_32 ( V_48 ) || ! V_48 -> V_57 -> V_62 ) {
F_27 ( V_9 , V_59 , V_63 ,
( V_48 -> V_57 -> V_64 << 8 ) | V_48 -> V_58 ) ;
return 0 ;
}
V_61 = F_33 ( V_48 ) ;
if ( V_61 ) {
if ( F_32 ( V_61 ) )
F_27 ( V_9 , V_65 , V_63 ,
( V_61 -> V_57 -> V_64 << 8 ) | V_48 -> V_57 -> V_64 ) ;
else
F_27 ( V_9 , V_59 , V_63 ,
( V_61 -> V_57 -> V_64 << 8 ) | V_61 -> V_58 ) ;
}
return 0 ;
}
static void F_34 ( struct V_20 * V_17 , int V_66 )
{
T_4 V_67 ;
T_5 V_68 ;
unsigned long V_12 ;
V_67 = F_35 ( ( void * ) V_17 -> V_18 -> V_19 ) ;
F_5 ( & V_17 -> V_69 , V_12 ) ;
F_36 ( V_17 -> V_70 + V_71 ,
( V_67 ) | F_37 ( V_66 ) | V_72 ) ;
V_17 -> V_73 |= V_74 ;
F_38 ( V_17 -> V_73 , V_17 -> V_70 + V_75 ) ;
F_39 ( V_17 , V_76 ,
V_77 , ( V_68 & V_78 ) , V_68 ) ;
F_6 ( & V_17 -> V_69 , V_12 ) ;
F_40 ( V_17 ) ;
F_5 ( & V_17 -> V_69 , V_12 ) ;
V_17 -> V_73 |= V_79 ;
F_38 ( V_17 -> V_73 , V_17 -> V_70 + V_75 ) ;
F_39 ( V_17 , V_76 ,
V_77 , ( V_68 & V_80 ) , V_68 ) ;
F_6 ( & V_17 -> V_69 , V_12 ) ;
}
static int F_41 ( struct V_20 * V_17 , int V_66 )
{
struct V_18 * V_18 ;
struct V_81 * V_82 ;
V_18 = V_17 -> V_18 = F_42 ( sizeof( struct V_18 ) ,
V_83 ) ;
if ( ! V_17 -> V_18 )
return - V_84 ;
V_82 = F_43 ( V_17 -> V_85 , V_83 | V_86 ,
V_87 ) ;
if ( ! V_82 ) {
F_11 ( V_27 L_9 ,
V_87 ) ;
F_44 ( V_17 -> V_18 ) ;
return - V_84 ;
}
V_18 -> V_19 = F_45 ( V_82 ) ;
F_34 ( V_17 , V_66 ) ;
return 0 ;
}
static void F_46 ( struct V_20 * V_17 )
{
unsigned long V_12 ;
T_5 V_68 ;
if ( ! F_47 ( V_17 -> V_26 ) )
return;
F_40 ( V_17 ) ;
F_5 ( & V_17 -> V_69 , V_12 ) ;
V_68 = F_48 ( V_17 -> V_70 + V_76 ) ;
if ( ! ( V_68 & V_80 ) )
goto V_52;
V_17 -> V_73 &= ~ V_79 ;
F_38 ( V_17 -> V_73 , V_17 -> V_70 + V_75 ) ;
F_39 ( V_17 , V_76 ,
V_77 , ! ( V_68 & V_80 ) , V_68 ) ;
V_52:
F_6 ( & V_17 -> V_69 , V_12 ) ;
}
int T_1 F_49 ( void )
{
struct V_49 * V_50 ;
if ( V_2 )
return 0 ;
if ( ! F_50 () )
return 0 ;
F_51 (drhd) {
struct V_20 * V_17 = V_50 -> V_17 ;
if ( ! F_47 ( V_17 -> V_26 ) )
return 0 ;
}
return 1 ;
}
int T_1 F_52 ( int V_88 )
{
struct V_49 * V_50 ;
int V_89 = 0 ;
if ( F_53 () != 1 ) {
F_11 ( V_90 L_10 ) ;
return - 1 ;
}
F_51 (drhd) {
struct V_20 * V_17 = V_50 -> V_17 ;
if ( V_17 -> V_91 )
continue;
F_54 ( - 1 , V_17 ) ;
F_46 ( V_17 ) ;
F_55 ( V_17 ) ;
}
F_51 (drhd) {
struct V_20 * V_17 = V_50 -> V_17 ;
if ( ! F_47 ( V_17 -> V_26 ) )
continue;
if ( V_88 && ! F_56 ( V_17 -> V_26 ) ) {
F_11 ( V_90 L_11
L_12 , V_50 -> V_92 , V_17 -> V_26 ) ;
return - 1 ;
}
}
F_51 (drhd) {
int V_93 ;
struct V_20 * V_17 = V_50 -> V_17 ;
V_93 = F_57 ( V_17 ) ;
if ( V_93 ) {
F_11 ( V_27 L_13
L_14 ,
V_50 -> V_92 , V_17 -> V_26 , V_93 ) ;
return - 1 ;
}
}
F_51 (drhd) {
struct V_20 * V_17 = V_50 -> V_17 ;
if ( ! F_47 ( V_17 -> V_26 ) )
continue;
if ( F_41 ( V_17 , V_88 ) )
goto error;
V_89 = 1 ;
}
if ( ! V_89 )
goto error;
V_94 = 1 ;
return 0 ;
error:
return - 1 ;
}
static void F_58 ( struct V_95 * V_96 ,
struct V_20 * V_17 )
{
struct V_97 * V_98 ;
T_3 V_57 ;
int V_21 ;
V_57 = V_96 -> V_57 ;
V_98 = (struct V_97 * ) ( V_96 + 1 ) ;
V_21 = ( V_96 -> V_99 - sizeof( struct V_95 ) )
/ sizeof( struct V_97 ) ;
while ( -- V_21 > 0 ) {
V_57 = F_59 ( V_57 , V_98 -> V_48 , V_98 -> V_100 ,
V_101 ) ;
V_98 ++ ;
}
V_42 [ V_102 ] . V_57 = V_57 ;
V_42 [ V_102 ] . V_58 = F_60 ( V_98 -> V_48 , V_98 -> V_100 ) ;
V_42 [ V_102 ] . V_17 = V_17 ;
V_42 [ V_102 ] . V_43 = V_96 -> V_103 ;
V_102 ++ ;
}
static void F_61 ( struct V_95 * V_96 ,
struct V_20 * V_17 )
{
struct V_97 * V_98 ;
T_3 V_57 ;
int V_21 ;
V_57 = V_96 -> V_57 ;
V_98 = (struct V_97 * ) ( V_96 + 1 ) ;
V_21 = ( V_96 -> V_99 - sizeof( struct V_95 ) )
/ sizeof( struct V_97 ) ;
while ( -- V_21 > 0 ) {
V_57 = F_59 ( V_57 , V_98 -> V_48 , V_98 -> V_100 ,
V_101 ) ;
V_98 ++ ;
}
V_46 [ V_104 ] . V_57 = V_57 ;
V_46 [ V_104 ] . V_58 = F_60 ( V_98 -> V_48 , V_98 -> V_100 ) ;
V_46 [ V_104 ] . V_17 = V_17 ;
V_46 [ V_104 ] . V_43 = V_96 -> V_103 ;
V_104 ++ ;
}
static int F_62 ( struct V_105 * V_106 ,
struct V_20 * V_17 )
{
struct V_107 * V_50 ;
struct V_95 * V_96 ;
void * V_51 , * V_52 ;
V_50 = (struct V_107 * ) V_106 ;
V_51 = ( void * ) ( V_50 + 1 ) ;
V_52 = ( ( void * ) V_50 ) + V_106 -> V_99 ;
while ( V_51 < V_52 ) {
V_96 = V_51 ;
if ( V_96 -> V_108 == V_109 ) {
if ( V_104 == V_45 ) {
F_11 ( V_110 L_15 ) ;
return - 1 ;
}
F_11 ( V_90 L_16
L_17 , V_96 -> V_103 ,
V_50 -> V_111 , V_17 -> V_112 ) ;
F_61 ( V_96 , V_17 ) ;
} else if ( V_96 -> V_108 == V_113 ) {
if ( V_102 == V_41 ) {
F_11 ( V_110 L_18 ) ;
return - 1 ;
}
F_11 ( V_90 L_19
L_20 , V_96 -> V_103 ,
V_50 -> V_111 ) ;
F_58 ( V_96 , V_17 ) ;
}
V_51 += V_96 -> V_99 ;
}
return 0 ;
}
int T_1 F_53 ( void )
{
struct V_49 * V_50 ;
int V_114 = 0 ;
F_51 (drhd) {
struct V_20 * V_17 = V_50 -> V_17 ;
if ( F_47 ( V_17 -> V_26 ) ) {
if ( F_62 ( V_50 -> V_115 , V_17 ) )
return - 1 ;
V_114 = 1 ;
}
}
if ( V_114 && V_104 != V_116 ) {
F_11 ( V_110
L_21 ) ;
return - 1 ;
}
return V_114 ;
}
void F_63 ( void )
{
struct V_49 * V_50 ;
struct V_20 * V_17 = NULL ;
F_64 (iommu, drhd) {
if ( ! F_47 ( V_17 -> V_26 ) )
continue;
F_46 ( V_17 ) ;
}
}
int F_65 ( int V_88 )
{
struct V_49 * V_50 ;
int V_89 = 0 ;
struct V_20 * V_17 = NULL ;
F_64 (iommu, drhd)
if ( V_17 -> V_91 )
F_66 ( V_17 ) ;
F_64 (iommu, drhd) {
if ( ! F_47 ( V_17 -> V_26 ) )
continue;
F_34 ( V_17 , V_88 ) ;
V_89 = 1 ;
}
if ( ! V_89 )
goto error;
return 0 ;
error:
return - 1 ;
}
