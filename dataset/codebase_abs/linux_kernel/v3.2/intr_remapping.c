static T_1 int F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static T_1 int F_2 ( char * V_1 )
{
if ( ! V_1 )
return - V_3 ;
while ( * V_1 ) {
if ( ! strncmp ( V_1 , L_1 , 2 ) )
V_2 = 0 ;
else if ( ! strncmp ( V_1 , L_2 , 3 ) )
V_2 = 1 ;
else if ( ! strncmp ( V_1 , L_3 , 5 ) )
V_4 = 1 ;
else if ( ! strncmp ( V_1 , L_4 , 16 ) )
V_5 = 1 ;
V_1 += strcspn ( V_1 , L_5 ) ;
while ( * V_1 == ',' )
V_1 ++ ;
}
return 0 ;
}
static struct V_6 * V_6 ( unsigned int V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
return V_9 ? & V_9 -> V_6 : NULL ;
}
int F_4 ( int V_7 , struct V_10 * V_11 )
{
struct V_6 * V_12 = V_6 ( V_7 ) ;
unsigned long V_13 ;
int V_14 ;
if ( ! V_11 || ! V_12 )
return - 1 ;
F_5 ( & V_15 , V_13 ) ;
V_14 = V_12 -> V_16 + V_12 -> V_17 ;
* V_11 = * ( V_12 -> V_18 -> V_19 -> V_20 + V_14 ) ;
F_6 ( & V_15 , V_13 ) ;
return 0 ;
}
int F_7 ( struct V_21 * V_18 , int V_7 , T_2 V_22 )
{
struct V_19 * V_23 = V_18 -> V_19 ;
struct V_6 * V_12 = V_6 ( V_7 ) ;
T_2 V_14 , V_24 ;
unsigned int V_25 = 0 ;
unsigned long V_13 ;
int V_26 ;
if ( ! V_22 || ! V_12 )
return - 1 ;
V_14 = V_24 = 0 ;
if ( V_22 > 1 ) {
V_22 = F_8 ( V_22 ) ;
V_25 = F_9 ( V_22 ) ;
}
if ( V_25 > F_10 ( V_18 -> V_27 ) ) {
F_11 ( V_28
L_6
L_7 , V_25 ,
F_10 ( V_18 -> V_27 ) ) ;
return - 1 ;
}
F_5 ( & V_15 , V_13 ) ;
do {
for ( V_26 = V_14 ; V_26 < V_14 + V_22 ; V_26 ++ )
if ( V_23 -> V_20 [ V_26 ] . V_29 )
break;
if ( V_26 == V_14 + V_22 )
break;
V_14 = ( V_14 + V_22 ) % V_30 ;
if ( V_14 == V_24 ) {
F_6 ( & V_15 , V_13 ) ;
F_11 ( V_28 L_8 ) ;
return - 1 ;
}
} while ( 1 );
for ( V_26 = V_14 ; V_26 < V_14 + V_22 ; V_26 ++ )
V_23 -> V_20 [ V_26 ] . V_29 = 1 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_16 = V_14 ;
V_12 -> V_17 = 0 ;
V_12 -> V_31 = V_25 ;
F_6 ( & V_15 , V_13 ) ;
return V_14 ;
}
static int F_12 ( struct V_21 * V_18 , int V_14 , int V_25 )
{
struct V_32 V_33 ;
V_33 . V_34 = F_13 ( V_14 ) | V_35 | F_14 ( V_25 )
| V_36 ;
V_33 . V_37 = 0 ;
return F_15 ( & V_33 , V_18 ) ;
}
int F_16 ( int V_7 , T_2 * V_17 )
{
struct V_6 * V_12 = V_6 ( V_7 ) ;
unsigned long V_13 ;
int V_14 ;
if ( ! V_12 )
return - 1 ;
F_5 ( & V_15 , V_13 ) ;
* V_17 = V_12 -> V_17 ;
V_14 = V_12 -> V_16 ;
F_6 ( & V_15 , V_13 ) ;
return V_14 ;
}
int F_17 ( int V_7 , struct V_21 * V_18 , T_2 V_14 , T_2 V_38 )
{
struct V_6 * V_12 = V_6 ( V_7 ) ;
unsigned long V_13 ;
if ( ! V_12 )
return - 1 ;
F_5 ( & V_15 , V_13 ) ;
V_12 -> V_18 = V_18 ;
V_12 -> V_16 = V_14 ;
V_12 -> V_17 = V_38 ;
V_12 -> V_31 = 0 ;
F_6 ( & V_15 , V_13 ) ;
return 0 ;
}
int F_18 ( int V_7 , struct V_10 * V_39 )
{
struct V_6 * V_12 = V_6 ( V_7 ) ;
struct V_21 * V_18 ;
unsigned long V_13 ;
struct V_10 * V_10 ;
int V_40 , V_14 ;
if ( ! V_12 )
return - 1 ;
F_5 ( & V_15 , V_13 ) ;
V_18 = V_12 -> V_18 ;
V_14 = V_12 -> V_16 + V_12 -> V_17 ;
V_10 = & V_18 -> V_19 -> V_20 [ V_14 ] ;
F_19 ( & V_10 -> V_34 , V_39 -> V_34 ) ;
F_19 ( & V_10 -> V_37 , V_39 -> V_37 ) ;
F_20 ( V_18 , V_10 , sizeof( * V_10 ) ) ;
V_40 = F_12 ( V_18 , V_14 , 0 ) ;
F_6 ( & V_15 , V_13 ) ;
return V_40 ;
}
struct V_21 * F_21 ( T_3 V_41 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ )
if ( V_43 [ V_26 ] . V_44 == V_41 )
return V_43 [ V_26 ] . V_18 ;
return NULL ;
}
struct V_21 * F_22 ( int V_45 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_46 ; V_26 ++ )
if ( V_47 [ V_26 ] . V_44 == V_45 )
return V_47 [ V_26 ] . V_18 ;
return NULL ;
}
struct V_21 * F_23 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
V_51 = F_24 ( V_49 ) ;
if ( ! V_51 )
return NULL ;
return V_51 -> V_18 ;
}
static int F_25 ( struct V_6 * V_12 )
{
struct V_10 * V_52 , * V_11 , * V_53 ;
struct V_21 * V_18 ;
int V_14 ;
if ( V_12 -> V_17 )
return 0 ;
V_18 = V_12 -> V_18 ;
V_14 = V_12 -> V_16 + V_12 -> V_17 ;
V_52 = V_18 -> V_19 -> V_20 + V_14 ;
V_53 = V_52 + ( 1 << V_12 -> V_31 ) ;
for ( V_11 = V_52 ; V_11 < V_53 ; V_11 ++ ) {
F_19 ( & V_11 -> V_34 , 0 ) ;
F_19 ( & V_11 -> V_37 , 0 ) ;
}
return F_12 ( V_18 , V_14 , V_12 -> V_31 ) ;
}
int F_26 ( int V_7 )
{
struct V_6 * V_12 = V_6 ( V_7 ) ;
unsigned long V_13 ;
int V_40 ;
if ( ! V_12 )
return - 1 ;
F_5 ( & V_15 , V_13 ) ;
V_40 = F_25 ( V_12 ) ;
V_12 -> V_18 = NULL ;
V_12 -> V_16 = 0 ;
V_12 -> V_17 = 0 ;
V_12 -> V_31 = 0 ;
F_6 ( & V_15 , V_13 ) ;
return V_40 ;
}
static void F_27 ( struct V_10 * V_10 , unsigned int V_54 ,
unsigned int V_55 , unsigned int V_56 )
{
if ( V_4 )
V_54 = V_57 ;
V_10 -> V_54 = V_54 ;
V_10 -> V_55 = V_55 ;
V_10 -> V_56 = V_56 ;
}
int F_28 ( struct V_10 * V_10 , int V_45 )
{
int V_26 ;
T_2 V_56 = 0 ;
if ( ! V_10 )
return - 1 ;
for ( V_26 = 0 ; V_26 < V_46 ; V_26 ++ ) {
if ( V_47 [ V_26 ] . V_44 == V_45 ) {
V_56 = ( V_47 [ V_26 ] . V_58 << 8 ) | V_47 [ V_26 ] . V_59 ;
break;
}
}
if ( V_56 == 0 ) {
F_29 ( L_9 , V_45 ) ;
return - 1 ;
}
F_27 ( V_10 , 1 , 0 , V_56 ) ;
return 0 ;
}
int F_30 ( struct V_10 * V_10 , T_3 V_44 )
{
int V_26 ;
T_2 V_56 = 0 ;
if ( ! V_10 )
return - 1 ;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ ) {
if ( V_43 [ V_26 ] . V_44 == V_44 ) {
V_56 = ( V_43 [ V_26 ] . V_58 << 8 ) | V_43 [ V_26 ] . V_59 ;
break;
}
}
if ( V_56 == 0 ) {
F_29 ( L_10 , V_44 ) ;
return - 1 ;
}
F_27 ( V_10 , V_60 , V_61 , V_56 ) ;
return 0 ;
}
int F_31 ( struct V_10 * V_10 , struct V_48 * V_49 )
{
struct V_48 * V_62 ;
if ( ! V_10 || ! V_49 )
return - 1 ;
if ( F_32 ( V_49 ) || ! V_49 -> V_58 -> V_63 ) {
F_27 ( V_10 , V_60 , V_64 ,
( V_49 -> V_58 -> V_65 << 8 ) | V_49 -> V_59 ) ;
return 0 ;
}
V_62 = F_33 ( V_49 ) ;
if ( V_62 ) {
if ( F_32 ( V_62 ) )
F_27 ( V_10 , V_66 , V_64 ,
( V_62 -> V_58 -> V_65 << 8 ) | V_49 -> V_58 -> V_65 ) ;
else
F_27 ( V_10 , V_60 , V_64 ,
( V_62 -> V_58 -> V_65 << 8 ) | V_62 -> V_59 ) ;
}
return 0 ;
}
static void F_34 ( struct V_21 * V_18 , int V_67 )
{
T_4 V_68 ;
T_5 V_69 ;
unsigned long V_13 ;
V_68 = F_35 ( ( void * ) V_18 -> V_19 -> V_20 ) ;
F_5 ( & V_18 -> V_70 , V_13 ) ;
F_36 ( V_18 -> V_71 + V_72 ,
( V_68 ) | F_37 ( V_67 ) | V_73 ) ;
V_18 -> V_74 |= V_75 ;
F_38 ( V_18 -> V_74 , V_18 -> V_71 + V_76 ) ;
F_39 ( V_18 , V_77 ,
V_78 , ( V_69 & V_79 ) , V_69 ) ;
F_6 ( & V_18 -> V_70 , V_13 ) ;
F_40 ( V_18 ) ;
F_5 ( & V_18 -> V_70 , V_13 ) ;
V_18 -> V_74 |= V_80 ;
F_38 ( V_18 -> V_74 , V_18 -> V_71 + V_76 ) ;
F_39 ( V_18 , V_77 ,
V_78 , ( V_69 & V_81 ) , V_69 ) ;
F_6 ( & V_18 -> V_70 , V_13 ) ;
}
static int F_41 ( struct V_21 * V_18 , int V_67 )
{
struct V_19 * V_19 ;
struct V_82 * V_83 ;
V_19 = V_18 -> V_19 = F_42 ( sizeof( struct V_19 ) ,
V_84 ) ;
if ( ! V_18 -> V_19 )
return - V_85 ;
V_83 = F_43 ( V_18 -> V_86 , V_84 | V_87 ,
V_88 ) ;
if ( ! V_83 ) {
F_11 ( V_28 L_11 ,
V_88 ) ;
F_44 ( V_18 -> V_19 ) ;
return - V_85 ;
}
V_19 -> V_20 = F_45 ( V_83 ) ;
F_34 ( V_18 , V_67 ) ;
return 0 ;
}
static void F_46 ( struct V_21 * V_18 )
{
unsigned long V_13 ;
T_5 V_69 ;
if ( ! F_47 ( V_18 -> V_27 ) )
return;
F_40 ( V_18 ) ;
F_5 ( & V_18 -> V_70 , V_13 ) ;
V_69 = F_48 ( V_18 -> V_71 + V_77 ) ;
if ( ! ( V_69 & V_81 ) )
goto V_53;
V_18 -> V_74 &= ~ V_80 ;
F_38 ( V_18 -> V_74 , V_18 -> V_71 + V_76 ) ;
F_39 ( V_18 , V_77 ,
V_78 , ! ( V_69 & V_81 ) , V_69 ) ;
V_53:
F_6 ( & V_18 -> V_70 , V_13 ) ;
}
static int T_1 F_49 ( void )
{
struct V_89 * V_90 ;
V_90 = (struct V_89 * ) V_91 ;
if ( ! V_90 || V_5 )
return 0 ;
return V_90 -> V_13 & V_92 ;
}
int T_1 F_50 ( void )
{
struct V_50 * V_51 ;
if ( V_2 )
return 0 ;
if ( ! F_51 () )
return 0 ;
F_52 (drhd) {
struct V_21 * V_18 = V_51 -> V_18 ;
if ( ! F_47 ( V_18 -> V_27 ) )
return 0 ;
}
return 1 ;
}
int T_1 F_53 ( void )
{
struct V_50 * V_51 ;
int V_93 = 0 ;
int V_94 = 0 ;
if ( F_54 () != 1 ) {
F_11 ( V_95 L_12 ) ;
return - 1 ;
}
if ( F_55 () ) {
V_94 = ! F_49 () ;
F_56 ( ! V_94 , V_96
L_13
L_14
L_15 ) ;
}
F_52 (drhd) {
struct V_21 * V_18 = V_51 -> V_18 ;
if ( V_18 -> V_97 )
continue;
F_57 ( - 1 , V_18 ) ;
F_46 ( V_18 ) ;
F_58 ( V_18 ) ;
}
F_52 (drhd) {
struct V_21 * V_18 = V_51 -> V_18 ;
if ( ! F_47 ( V_18 -> V_27 ) )
continue;
if ( V_94 && ! F_59 ( V_18 -> V_27 ) ) {
F_11 ( V_95 L_16
L_17 , V_51 -> V_98 , V_18 -> V_27 ) ;
return - 1 ;
}
}
F_52 (drhd) {
int V_99 ;
struct V_21 * V_18 = V_51 -> V_18 ;
V_99 = F_60 ( V_18 ) ;
if ( V_99 ) {
F_11 ( V_28 L_18
L_19 ,
V_51 -> V_98 , V_18 -> V_27 , V_99 ) ;
return - 1 ;
}
}
F_52 (drhd) {
struct V_21 * V_18 = V_51 -> V_18 ;
if ( ! F_47 ( V_18 -> V_27 ) )
continue;
if ( F_41 ( V_18 , V_94 ) )
goto error;
V_93 = 1 ;
}
if ( ! V_93 )
goto error;
V_100 = 1 ;
F_61 ( L_20 , V_94 ? L_21 : L_22 ) ;
return V_94 ? V_101 : V_102 ;
error:
return - 1 ;
}
static void F_62 ( struct V_103 * V_104 ,
struct V_21 * V_18 )
{
struct V_105 * V_106 ;
T_3 V_58 ;
int V_22 ;
V_58 = V_104 -> V_58 ;
V_106 = (struct V_105 * ) ( V_104 + 1 ) ;
V_22 = ( V_104 -> V_107 - sizeof( struct V_103 ) )
/ sizeof( struct V_105 ) ;
while ( -- V_22 > 0 ) {
V_58 = F_63 ( V_58 , V_106 -> V_49 , V_106 -> V_108 ,
V_109 ) ;
V_106 ++ ;
}
V_43 [ V_110 ] . V_58 = V_58 ;
V_43 [ V_110 ] . V_59 = F_64 ( V_106 -> V_49 , V_106 -> V_108 ) ;
V_43 [ V_110 ] . V_18 = V_18 ;
V_43 [ V_110 ] . V_44 = V_104 -> V_111 ;
V_110 ++ ;
}
static void F_65 ( struct V_103 * V_104 ,
struct V_21 * V_18 )
{
struct V_105 * V_106 ;
T_3 V_58 ;
int V_22 ;
V_58 = V_104 -> V_58 ;
V_106 = (struct V_105 * ) ( V_104 + 1 ) ;
V_22 = ( V_104 -> V_107 - sizeof( struct V_103 ) )
/ sizeof( struct V_105 ) ;
while ( -- V_22 > 0 ) {
V_58 = F_63 ( V_58 , V_106 -> V_49 , V_106 -> V_108 ,
V_109 ) ;
V_106 ++ ;
}
V_47 [ V_112 ] . V_58 = V_58 ;
V_47 [ V_112 ] . V_59 = F_64 ( V_106 -> V_49 , V_106 -> V_108 ) ;
V_47 [ V_112 ] . V_18 = V_18 ;
V_47 [ V_112 ] . V_44 = V_104 -> V_111 ;
V_112 ++ ;
}
static int F_66 ( struct V_113 * V_114 ,
struct V_21 * V_18 )
{
struct V_115 * V_51 ;
struct V_103 * V_104 ;
void * V_52 , * V_53 ;
V_51 = (struct V_115 * ) V_114 ;
V_52 = ( void * ) ( V_51 + 1 ) ;
V_53 = ( ( void * ) V_51 ) + V_114 -> V_107 ;
while ( V_52 < V_53 ) {
V_104 = V_52 ;
if ( V_104 -> V_116 == V_117 ) {
if ( V_112 == V_46 ) {
F_11 ( V_96 L_23 ) ;
return - 1 ;
}
F_11 ( V_95 L_24
L_25 , V_104 -> V_111 ,
V_51 -> V_118 , V_18 -> V_119 ) ;
F_65 ( V_104 , V_18 ) ;
} else if ( V_104 -> V_116 == V_120 ) {
if ( V_110 == V_42 ) {
F_11 ( V_96 L_26 ) ;
return - 1 ;
}
F_11 ( V_95 L_27
L_28 , V_104 -> V_111 ,
V_51 -> V_118 ) ;
F_62 ( V_104 , V_18 ) ;
}
V_52 += V_104 -> V_107 ;
}
return 0 ;
}
int T_1 F_54 ( void )
{
struct V_50 * V_51 ;
int V_121 = 0 ;
F_52 (drhd) {
struct V_21 * V_18 = V_51 -> V_18 ;
if ( F_47 ( V_18 -> V_27 ) ) {
if ( F_66 ( V_51 -> V_122 , V_18 ) )
return - 1 ;
V_121 = 1 ;
}
}
if ( V_121 && V_112 != V_123 ) {
F_11 ( V_96
L_29 ) ;
return - 1 ;
}
return V_121 ;
}
int T_1 F_67 ( void )
{
if ( ! V_100 )
return 0 ;
return F_68 () ;
}
void F_69 ( void )
{
struct V_50 * V_51 ;
struct V_21 * V_18 = NULL ;
F_70 (iommu, drhd) {
if ( ! F_47 ( V_18 -> V_27 ) )
continue;
F_46 ( V_18 ) ;
}
}
int F_71 ( int V_94 )
{
struct V_50 * V_51 ;
int V_93 = 0 ;
struct V_21 * V_18 = NULL ;
F_70 (iommu, drhd)
if ( V_18 -> V_97 )
F_72 ( V_18 ) ;
F_70 (iommu, drhd) {
if ( ! F_47 ( V_18 -> V_27 ) )
continue;
F_34 ( V_18 , V_94 ) ;
V_93 = 1 ;
}
if ( ! V_93 )
goto error;
return 0 ;
error:
return - 1 ;
}
