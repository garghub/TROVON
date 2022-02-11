int F_1 ( struct V_1 * V_2 )
{
if ( V_3 )
return 0 ;
if ( F_2 () || ! V_2 -> V_4 || F_3 ( V_2 ) || V_5 )
return 1 ;
return 0 ;
}
int F_4 ( struct V_6 * V_7 )
{
int V_8 , V_9 ;
unsigned long V_10 = V_7 -> V_10 ;
V_8 = - V_11 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_7 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_7 -> V_14 [ V_9 ] . V_16 ;
if ( ( V_12 & ~ V_17 ) || ( V_13 & ~ V_17 ) )
return V_8 ;
if ( V_13 >= V_18 )
return V_8 ;
}
V_8 = - V_19 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
unsigned long V_20 ;
V_12 = V_7 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_7 -> V_14 [ V_9 ] . V_16 ;
for ( V_20 = 0 ; V_20 < V_9 ; V_20 ++ ) {
unsigned long V_21 , V_22 ;
V_21 = V_7 -> V_14 [ V_20 ] . V_15 ;
V_22 = V_21 + V_7 -> V_14 [ V_20 ] . V_16 ;
if ( ( V_13 > V_21 ) && ( V_12 < V_22 ) )
return V_8 ;
}
}
V_8 = - V_19 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_7 -> V_14 [ V_9 ] . V_23 > V_7 -> V_14 [ V_9 ] . V_16 )
return V_8 ;
}
if ( V_7 -> type == V_24 ) {
V_8 = - V_11 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_7 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_7 -> V_14 [ V_9 ] . V_16 - 1 ;
if ( ( V_12 < V_25 . V_26 ) ||
( V_13 > V_25 . V_27 ) )
return V_8 ;
}
}
return 0 ;
}
struct V_6 * F_5 ( void )
{
struct V_6 * V_7 ;
V_7 = F_6 ( sizeof( * V_7 ) , V_28 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_29 = 0 ;
V_7 -> V_30 = & V_7 -> V_29 ;
V_7 -> V_31 = & V_7 -> V_29 ;
V_7 -> V_32 = ~ 0 ;
V_7 -> type = V_33 ;
F_7 ( & V_7 -> V_34 ) ;
F_7 ( & V_7 -> V_35 ) ;
F_7 ( & V_7 -> V_36 ) ;
return V_7 ;
}
int F_8 ( struct V_6 * V_7 ,
unsigned long V_26 ,
unsigned long V_27 )
{
unsigned long V_9 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_7 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_7 -> V_14 [ V_9 ] . V_16 ;
if ( ( V_27 > V_12 ) && ( V_26 < V_13 ) )
return 1 ;
}
return 0 ;
}
static struct V_37 * F_9 ( T_1 V_38 , unsigned int V_39 )
{
struct V_37 * V_40 ;
V_40 = F_10 ( V_38 , V_39 ) ;
if ( V_40 ) {
unsigned int V_41 , V_9 ;
V_40 -> V_42 = NULL ;
F_11 ( V_40 , V_39 ) ;
V_41 = 1 << V_39 ;
for ( V_9 = 0 ; V_9 < V_41 ; V_9 ++ )
F_12 ( V_40 + V_9 ) ;
}
return V_40 ;
}
static void F_13 ( struct V_37 * V_37 )
{
unsigned int V_39 , V_41 , V_9 ;
V_39 = F_14 ( V_37 ) ;
V_41 = 1 << V_39 ;
for ( V_9 = 0 ; V_9 < V_41 ; V_9 ++ )
F_15 ( V_37 + V_9 ) ;
F_16 ( V_37 , V_39 ) ;
}
void F_17 ( struct V_43 * V_44 )
{
struct V_43 * V_45 , * V_46 ;
F_18 (pos, next, list) {
struct V_37 * V_37 ;
V_37 = F_19 ( V_45 , struct V_37 , V_47 ) ;
F_20 ( & V_37 -> V_47 ) ;
F_13 ( V_37 ) ;
}
}
static struct V_37 * F_21 ( struct V_6 * V_7 ,
unsigned int V_39 )
{
struct V_43 V_48 ;
struct V_37 * V_40 ;
unsigned int V_41 ;
V_41 = 1 << V_39 ;
F_7 ( & V_48 ) ;
do {
unsigned long V_49 , V_50 , V_51 , V_52 ;
V_40 = F_9 ( V_53 , V_39 ) ;
if ( ! V_40 )
break;
V_49 = F_22 ( V_40 ) ;
V_50 = V_49 + V_41 ;
V_51 = V_49 << V_54 ;
V_52 = V_50 << V_54 ;
if ( ( V_50 >= ( V_55 >> V_54 ) ) ||
F_8 ( V_7 , V_51 , V_52 ) ) {
F_23 ( & V_40 -> V_47 , & V_48 ) ;
V_40 = NULL ;
}
} while ( ! V_40 );
if ( V_40 ) {
F_23 ( & V_40 -> V_47 , & V_7 -> V_34 ) ;
}
F_17 ( & V_48 ) ;
return V_40 ;
}
static struct V_37 * F_24 ( struct V_6 * V_7 ,
unsigned int V_39 )
{
unsigned long V_56 , V_57 , V_58 ;
struct V_37 * V_40 ;
V_40 = NULL ;
V_58 = ( 1 << V_39 ) << V_54 ;
V_56 = ( V_7 -> V_32 + ( V_58 - 1 ) ) & ~ ( V_58 - 1 ) ;
V_57 = V_56 + V_58 - 1 ;
while ( V_57 <= V_25 . V_27 ) {
unsigned long V_9 ;
if ( V_57 > V_59 )
break;
for ( V_9 = 0 ; V_9 < V_7 -> V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_7 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_7 -> V_14 [ V_9 ] . V_16 - 1 ;
if ( ( V_57 >= V_12 ) && ( V_56 <= V_13 ) ) {
V_56 = ( V_13 + ( V_58 - 1 ) ) & ~ ( V_58 - 1 ) ;
V_57 = V_56 + V_58 - 1 ;
break;
}
}
if ( V_9 == V_7 -> V_10 ) {
V_40 = F_25 ( V_56 >> V_54 ) ;
V_7 -> V_32 = V_57 ;
break;
}
}
return V_40 ;
}
struct V_37 * F_26 ( struct V_6 * V_7 ,
unsigned int V_39 )
{
struct V_37 * V_40 = NULL ;
switch ( V_7 -> type ) {
case V_33 :
V_40 = F_21 ( V_7 , V_39 ) ;
break;
case V_24 :
V_40 = F_24 ( V_7 , V_39 ) ;
break;
}
return V_40 ;
}
static int F_27 ( struct V_6 * V_7 , T_2 V_30 )
{
if ( * V_7 -> V_30 != 0 )
V_7 -> V_30 ++ ;
if ( V_7 -> V_30 == V_7 -> V_31 ) {
T_2 * V_60 ;
struct V_37 * V_37 ;
V_37 = F_28 ( V_7 , V_28 , V_61 ) ;
if ( ! V_37 )
return - V_62 ;
V_60 = F_29 ( V_37 ) ;
* V_7 -> V_30 = F_30 ( V_60 ) | V_63 ;
V_7 -> V_30 = V_60 ;
V_7 -> V_31 = V_60 +
( ( V_64 / sizeof( T_2 ) ) - 1 ) ;
}
* V_7 -> V_30 = V_30 ;
V_7 -> V_30 ++ ;
* V_7 -> V_30 = 0 ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 ,
unsigned long V_65 )
{
int V_8 ;
V_65 &= V_17 ;
V_8 = F_27 ( V_7 , V_65 | V_66 ) ;
return V_8 ;
}
static int F_32 ( struct V_6 * V_7 , unsigned long V_37 )
{
int V_8 ;
V_37 &= V_17 ;
V_8 = F_27 ( V_7 , V_37 | V_67 ) ;
return V_8 ;
}
static void F_33 ( struct V_6 * V_7 )
{
F_17 ( & V_7 -> V_35 ) ;
F_17 ( & V_7 -> V_36 ) ;
}
void F_34 ( struct V_6 * V_7 )
{
if ( * V_7 -> V_30 != 0 )
V_7 -> V_30 ++ ;
* V_7 -> V_30 = V_68 ;
}
static void F_35 ( T_2 V_30 )
{
struct V_37 * V_37 ;
V_37 = F_25 ( V_30 >> V_54 ) ;
F_13 ( V_37 ) ;
}
void F_36 ( struct V_6 * V_7 )
{
T_2 * V_69 , V_30 ;
T_2 V_70 = 0 ;
if ( ! V_7 )
return;
F_33 ( V_7 ) ;
F_37 (image, ptr, entry) {
if ( V_30 & V_63 ) {
if ( V_70 & V_63 )
F_35 ( V_70 ) ;
V_70 = V_30 ;
} else if ( V_30 & V_67 )
F_35 ( V_30 ) ;
}
if ( V_70 & V_63 )
F_35 ( V_70 ) ;
F_38 ( V_7 ) ;
F_17 ( & V_7 -> V_34 ) ;
if ( V_7 -> V_71 )
F_39 ( V_7 ) ;
F_40 ( V_7 ) ;
}
static T_2 * F_41 ( struct V_6 * V_7 ,
unsigned long V_37 )
{
T_2 * V_69 , V_30 ;
unsigned long V_65 = 0 ;
F_37 (image, ptr, entry) {
if ( V_30 & V_66 )
V_65 = V_30 & V_17 ;
else if ( V_30 & V_67 ) {
if ( V_37 == V_65 )
return V_69 ;
V_65 += V_64 ;
}
}
return NULL ;
}
static struct V_37 * F_28 ( struct V_6 * V_7 ,
T_1 V_38 ,
unsigned long V_65 )
{
struct V_37 * V_37 ;
unsigned long V_51 ;
F_42 (page, &image->dest_pages, lru) {
V_51 = F_22 ( V_37 ) << V_54 ;
if ( V_51 == V_65 ) {
F_20 ( & V_37 -> V_47 ) ;
return V_37 ;
}
}
V_37 = NULL ;
while ( 1 ) {
T_2 * V_72 ;
V_37 = F_9 ( V_38 , 0 ) ;
if ( ! V_37 )
return NULL ;
if ( F_22 ( V_37 ) >
( V_73 >> V_54 ) ) {
F_23 ( & V_37 -> V_47 , & V_7 -> V_36 ) ;
continue;
}
V_51 = F_22 ( V_37 ) << V_54 ;
if ( V_51 == V_65 )
break;
if ( ! F_8 ( V_7 , V_51 ,
V_51 + V_64 ) )
break;
V_72 = F_41 ( V_7 , V_51 ) ;
if ( V_72 ) {
unsigned long V_74 ;
struct V_37 * V_75 ;
V_74 = * V_72 & V_17 ;
V_75 = F_25 ( V_74 >> V_54 ) ;
F_43 ( V_37 , V_75 ) ;
* V_72 = V_51 | ( * V_72 & ~ V_17 ) ;
if ( ! ( V_38 & V_76 ) &&
F_44 ( V_75 ) ) {
F_13 ( V_75 ) ;
continue;
}
V_51 = V_74 ;
V_37 = V_75 ;
break;
}
F_23 ( & V_37 -> V_47 , & V_7 -> V_35 ) ;
}
return V_37 ;
}
static int F_45 ( struct V_6 * V_7 ,
struct V_77 * V_14 )
{
unsigned long V_78 ;
T_3 V_79 , V_80 ;
int V_8 ;
unsigned char T_4 * V_81 = NULL ;
unsigned char * V_82 = NULL ;
V_8 = 0 ;
if ( V_7 -> V_71 )
V_82 = V_14 -> V_82 ;
else
V_81 = V_14 -> V_81 ;
V_79 = V_14 -> V_23 ;
V_80 = V_14 -> V_16 ;
V_78 = V_14 -> V_15 ;
V_8 = F_31 ( V_7 , V_78 ) ;
if ( V_8 < 0 )
goto V_83;
while ( V_80 ) {
struct V_37 * V_37 ;
char * V_69 ;
T_3 V_84 , V_85 ;
V_37 = F_28 ( V_7 , V_86 , V_78 ) ;
if ( ! V_37 ) {
V_8 = - V_62 ;
goto V_83;
}
V_8 = F_32 ( V_7 , F_22 ( V_37 )
<< V_54 ) ;
if ( V_8 < 0 )
goto V_83;
V_69 = F_46 ( V_37 ) ;
F_47 ( V_69 ) ;
V_69 += V_78 & ~ V_17 ;
V_85 = F_48 ( T_3 , V_80 ,
V_64 - ( V_78 & ~ V_17 ) ) ;
V_84 = F_49 ( V_79 , V_85 ) ;
if ( V_7 -> V_71 )
memcpy ( V_69 , V_82 , V_84 ) ;
else
V_8 = F_50 ( V_69 , V_81 , V_84 ) ;
F_51 ( V_37 ) ;
if ( V_8 ) {
V_8 = - V_87 ;
goto V_83;
}
V_79 -= V_84 ;
V_78 += V_85 ;
if ( V_7 -> V_71 )
V_82 += V_85 ;
else
V_81 += V_85 ;
V_80 -= V_85 ;
}
V_83:
return V_8 ;
}
static int F_52 ( struct V_6 * V_7 ,
struct V_77 * V_14 )
{
unsigned long V_78 ;
T_3 V_79 , V_80 ;
int V_8 ;
unsigned char T_4 * V_81 = NULL ;
unsigned char * V_82 = NULL ;
V_8 = 0 ;
if ( V_7 -> V_71 )
V_82 = V_14 -> V_82 ;
else
V_81 = V_14 -> V_81 ;
V_79 = V_14 -> V_23 ;
V_80 = V_14 -> V_16 ;
V_78 = V_14 -> V_15 ;
while ( V_80 ) {
struct V_37 * V_37 ;
char * V_69 ;
T_3 V_84 , V_85 ;
V_37 = F_25 ( V_78 >> V_54 ) ;
if ( ! V_37 ) {
V_8 = - V_62 ;
goto V_83;
}
V_69 = F_46 ( V_37 ) ;
V_69 += V_78 & ~ V_17 ;
V_85 = F_48 ( T_3 , V_80 ,
V_64 - ( V_78 & ~ V_17 ) ) ;
V_84 = F_49 ( V_79 , V_85 ) ;
if ( V_85 > V_84 ) {
memset ( V_69 + V_84 , 0 , V_85 - V_84 ) ;
}
if ( V_7 -> V_71 )
memcpy ( V_69 , V_82 , V_84 ) ;
else
V_8 = F_50 ( V_69 , V_81 , V_84 ) ;
F_53 ( V_37 ) ;
F_51 ( V_37 ) ;
if ( V_8 ) {
V_8 = - V_87 ;
goto V_83;
}
V_79 -= V_84 ;
V_78 += V_85 ;
if ( V_7 -> V_71 )
V_82 += V_85 ;
else
V_81 += V_85 ;
V_80 -= V_85 ;
}
V_83:
return V_8 ;
}
int F_54 ( struct V_6 * V_7 ,
struct V_77 * V_14 )
{
int V_8 = - V_62 ;
switch ( V_7 -> type ) {
case V_33 :
V_8 = F_45 ( V_7 , V_14 ) ;
break;
case V_24 :
V_8 = F_52 ( V_7 , V_14 ) ;
break;
}
return V_8 ;
}
void F_55 ( struct V_88 * V_89 )
{
if ( F_56 ( & V_90 ) ) {
if ( V_91 ) {
struct V_88 V_92 ;
F_57 ( & V_92 , V_89 ) ;
F_58 () ;
F_59 ( & V_92 ) ;
F_60 ( V_91 ) ;
}
F_61 ( & V_90 ) ;
}
}
T_3 F_62 ( void )
{
T_3 V_58 = 0 ;
F_63 ( & V_90 ) ;
if ( V_25 . V_27 != V_25 . V_26 )
V_58 = F_64 ( & V_25 ) ;
F_61 ( & V_90 ) ;
return V_58 ;
}
void __weak F_65 ( unsigned long V_93 ,
unsigned long V_27 )
{
unsigned long V_51 ;
for ( V_51 = V_93 ; V_51 < V_27 ; V_51 += V_64 )
F_66 ( F_25 ( V_51 >> V_54 ) ) ;
}
int F_67 ( unsigned long V_94 )
{
int V_95 = 0 ;
unsigned long V_26 , V_27 ;
unsigned long V_96 ;
struct V_97 * V_98 ;
F_63 ( & V_90 ) ;
if ( V_91 ) {
V_95 = - V_99 ;
goto V_100;
}
V_26 = V_25 . V_26 ;
V_27 = V_25 . V_27 ;
V_96 = ( V_27 == 0 ) ? 0 : V_27 - V_26 + 1 ;
if ( V_94 >= V_96 ) {
V_95 = ( V_94 == V_96 ) ? 0 : - V_19 ;
goto V_100;
}
V_98 = F_6 ( sizeof( * V_98 ) , V_28 ) ;
if ( ! V_98 ) {
V_95 = - V_62 ;
goto V_100;
}
V_26 = F_68 ( V_26 , V_101 ) ;
V_27 = F_68 ( V_26 + V_94 , V_101 ) ;
F_69 () ;
F_65 ( V_27 , V_25 . V_27 ) ;
if ( ( V_26 == V_27 ) && ( V_25 . V_102 != NULL ) )
F_70 ( & V_25 ) ;
V_98 -> V_26 = V_27 ;
V_98 -> V_27 = V_25 . V_27 ;
V_98 -> V_103 = V_104 | V_105 ;
V_98 -> V_106 = L_1 ;
V_25 . V_27 = V_27 - 1 ;
F_71 ( & V_107 , V_98 ) ;
F_72 () ;
V_100:
F_61 ( & V_90 ) ;
return V_95 ;
}
static T_5 * F_73 ( T_5 * V_81 , char * V_106 , unsigned type , void * V_108 ,
T_3 V_109 )
{
struct V_110 V_111 ;
V_111 . V_112 = strlen ( V_106 ) + 1 ;
V_111 . V_113 = V_109 ;
V_111 . V_114 = type ;
memcpy ( V_81 , & V_111 , sizeof( V_111 ) ) ;
V_81 += ( sizeof( V_111 ) + 3 ) / 4 ;
memcpy ( V_81 , V_106 , V_111 . V_112 ) ;
V_81 += ( V_111 . V_112 + 3 ) / 4 ;
memcpy ( V_81 , V_108 , V_111 . V_113 ) ;
V_81 += ( V_111 . V_113 + 3 ) / 4 ;
return V_81 ;
}
static void F_74 ( T_5 * V_81 )
{
struct V_110 V_111 ;
V_111 . V_112 = 0 ;
V_111 . V_113 = 0 ;
V_111 . V_114 = 0 ;
memcpy ( V_81 , & V_111 , sizeof( V_111 ) ) ;
}
void F_75 ( struct V_88 * V_89 , int V_115 )
{
struct V_116 V_117 ;
T_5 * V_81 ;
if ( ( V_115 < 0 ) || ( V_115 >= V_118 ) )
return;
V_81 = ( T_5 * ) F_76 ( V_119 , V_115 ) ;
if ( ! V_81 )
return;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_120 = V_121 -> V_4 ;
F_77 ( & V_117 . V_122 , V_89 ) ;
V_81 = F_73 ( V_81 , V_123 , V_124 ,
& V_117 , sizeof( V_117 ) ) ;
F_74 ( V_81 ) ;
}
static int T_6 F_78 ( void )
{
T_3 V_58 , V_125 ;
V_58 = sizeof( V_126 ) ;
V_125 = F_49 ( F_79 ( sizeof( V_126 ) ) , V_64 ) ;
F_80 ( V_58 > V_64 ) ;
V_119 = F_81 ( V_58 , V_125 ) ;
if ( ! V_119 ) {
F_82 ( L_2 ) ;
return - V_62 ;
}
return 0 ;
}
static int T_6 F_83 ( char * V_127 ,
unsigned long long V_128 ,
unsigned long long * V_129 ,
unsigned long long * V_130 )
{
char * V_131 = V_127 , * V_132 ;
do {
unsigned long long V_26 , V_27 = V_133 , V_58 ;
V_26 = F_84 ( V_131 , & V_132 ) ;
if ( V_131 == V_132 ) {
F_82 ( L_3 ) ;
return - V_19 ;
}
V_131 = V_132 ;
if ( * V_131 != '-' ) {
F_82 ( L_4 ) ;
return - V_19 ;
}
V_131 ++ ;
if ( * V_131 != ':' ) {
V_27 = F_84 ( V_131 , & V_132 ) ;
if ( V_131 == V_132 ) {
F_82 ( L_3 ) ;
return - V_19 ;
}
V_131 = V_132 ;
if ( V_27 <= V_26 ) {
F_82 ( L_5 ) ;
return - V_19 ;
}
}
if ( * V_131 != ':' ) {
F_82 ( L_6 ) ;
return - V_19 ;
}
V_131 ++ ;
V_58 = F_84 ( V_131 , & V_132 ) ;
if ( V_131 == V_132 ) {
F_82 ( L_7 ) ;
return - V_19 ;
}
V_131 = V_132 ;
if ( V_58 >= V_128 ) {
F_82 ( L_8 ) ;
return - V_19 ;
}
if ( V_128 >= V_26 && V_128 < V_27 ) {
* V_129 = V_58 ;
break;
}
} while ( * V_131 ++ == ',' );
if ( * V_129 > 0 ) {
while ( * V_131 && * V_131 != ' ' && * V_131 != '@' )
V_131 ++ ;
if ( * V_131 == '@' ) {
V_131 ++ ;
* V_130 = F_84 ( V_131 , & V_132 ) ;
if ( V_131 == V_132 ) {
F_82 ( L_9 ) ;
return - V_19 ;
}
}
}
return 0 ;
}
static int T_6 F_85 ( char * V_127 ,
unsigned long long * V_129 ,
unsigned long long * V_130 )
{
char * V_131 = V_127 ;
* V_129 = F_84 ( V_127 , & V_131 ) ;
if ( V_127 == V_131 ) {
F_82 ( L_10 ) ;
return - V_19 ;
}
if ( * V_131 == '@' )
* V_130 = F_84 ( V_131 + 1 , & V_131 ) ;
else if ( * V_131 != ' ' && * V_131 != '\0' ) {
F_82 ( L_11 , * V_131 ) ;
return - V_19 ;
}
return 0 ;
}
static int T_6 F_86 ( char * V_127 ,
unsigned long long * V_129 ,
const char * V_134 )
{
char * V_131 = V_127 ;
* V_129 = F_84 ( V_127 , & V_131 ) ;
if ( V_127 == V_131 ) {
F_82 ( L_10 ) ;
return - V_19 ;
}
if ( strncmp ( V_131 , V_134 , strlen ( V_134 ) ) ) {
F_82 ( L_11 , * V_131 ) ;
return - V_19 ;
}
V_131 += strlen ( V_134 ) ;
if ( * V_131 != ' ' && * V_131 != '\0' ) {
F_82 ( L_11 , * V_131 ) ;
return - V_19 ;
}
return 0 ;
}
static T_6 char * F_87 ( char * V_127 ,
const char * V_106 ,
const char * V_134 )
{
char * V_2 = V_127 , * V_135 = NULL ;
V_2 = strstr ( V_2 , V_106 ) ;
while ( V_2 ) {
char * V_136 = strchr ( V_2 , ' ' ) ;
char * V_137 ;
if ( ! V_136 )
V_136 = V_2 + strlen ( V_2 ) ;
if ( ! V_134 ) {
int V_9 ;
for ( V_9 = 0 ; V_138 [ V_9 ] ; V_9 ++ ) {
V_137 = V_136 - strlen ( V_138 [ V_9 ] ) ;
if ( ! strncmp ( V_137 , V_138 [ V_9 ] ,
strlen ( V_138 [ V_9 ] ) ) )
goto V_46;
}
V_135 = V_2 ;
} else {
V_137 = V_136 - strlen ( V_134 ) ;
if ( ! strncmp ( V_137 , V_134 , strlen ( V_134 ) ) )
V_135 = V_2 ;
}
V_46:
V_2 = strstr ( V_2 + 1 , V_106 ) ;
}
if ( ! V_135 )
return NULL ;
return V_135 ;
}
static int T_6 F_88 ( char * V_127 ,
unsigned long long V_128 ,
unsigned long long * V_129 ,
unsigned long long * V_130 ,
const char * V_106 ,
const char * V_134 )
{
char * V_139 , * V_140 ;
char * V_135 ;
F_89 ( ! V_129 || ! V_130 ) ;
* V_129 = 0 ;
* V_130 = 0 ;
V_135 = F_87 ( V_127 , V_106 , V_134 ) ;
if ( ! V_135 )
return - V_19 ;
V_135 += strlen ( V_106 ) ;
if ( V_134 )
return F_86 ( V_135 , V_129 ,
V_134 ) ;
V_139 = strchr ( V_135 , ':' ) ;
V_140 = strchr ( V_135 , ' ' ) ;
if ( V_139 && ( ! V_140 || V_139 < V_140 ) )
return F_83 ( V_135 , V_128 ,
V_129 , V_130 ) ;
return F_85 ( V_135 , V_129 , V_130 ) ;
}
int T_6 F_90 ( char * V_127 ,
unsigned long long V_128 ,
unsigned long long * V_129 ,
unsigned long long * V_130 )
{
return F_88 ( V_127 , V_128 , V_129 , V_130 ,
L_12 , NULL ) ;
}
int T_6 F_91 ( char * V_127 ,
unsigned long long V_128 ,
unsigned long long * V_129 ,
unsigned long long * V_130 )
{
return F_88 ( V_127 , V_128 , V_129 , V_130 ,
L_12 , V_138 [ V_141 ] ) ;
}
int T_6 F_92 ( char * V_127 ,
unsigned long long V_128 ,
unsigned long long * V_129 ,
unsigned long long * V_130 )
{
return F_88 ( V_127 , V_128 , V_129 , V_130 ,
L_12 , V_138 [ V_142 ] ) ;
}
static void F_93 ( void )
{
T_5 * V_81 = V_143 ;
if ( ! V_144 )
return;
V_81 = F_73 ( V_81 , V_145 , 0 , V_146 ,
V_144 ) ;
F_74 ( V_81 ) ;
}
void F_58 ( void )
{
F_94 ( L_13 , F_95 () ) ;
F_93 () ;
}
void F_94 ( const char * V_147 , ... )
{
T_7 args ;
char V_81 [ 0x50 ] ;
T_3 V_148 ;
va_start ( args , V_147 ) ;
V_148 = F_96 ( V_81 , sizeof( V_81 ) , V_147 , args ) ;
va_end ( args ) ;
V_148 = F_49 ( V_148 , V_149 - V_144 ) ;
memcpy ( & V_146 [ V_144 ] , V_81 , V_148 ) ;
V_144 += V_148 ;
}
void __weak F_97 ( void )
{}
unsigned long __weak F_98 ( void )
{
return F_99 ( ( unsigned long ) ( char * ) & V_143 ) ;
}
static int T_6 F_100 ( void )
{
F_101 ( V_150 . V_106 . V_151 ) ;
F_102 ( V_64 ) ;
F_103 ( V_150 ) ;
F_103 ( V_152 ) ;
#ifdef F_104
F_103 ( V_153 ) ;
#endif
F_103 ( V_154 ) ;
F_103 ( V_155 ) ;
#ifndef F_105
F_103 ( V_156 ) ;
F_103 ( V_157 ) ;
#endif
#ifdef F_106
F_103 ( V_158 ) ;
F_107 ( V_158 , V_159 ) ;
F_108 ( V_158 ) ;
F_109 ( V_158 , V_160 ) ;
#endif
F_108 ( V_37 ) ;
F_108 ( V_161 ) ;
F_108 ( V_162 ) ;
F_108 ( V_163 ) ;
F_108 ( V_43 ) ;
F_110 ( V_164 ) ;
F_109 ( V_37 , V_103 ) ;
F_109 ( V_37 , V_165 ) ;
F_109 ( V_37 , V_42 ) ;
F_109 ( V_37 , V_47 ) ;
F_109 ( V_37 , V_166 ) ;
F_109 ( V_37 , V_167 ) ;
F_109 ( V_161 , V_168 ) ;
F_109 ( V_161 , V_169 ) ;
#ifdef F_111
F_109 ( V_161 , V_170 ) ;
#endif
F_109 ( V_161 , V_171 ) ;
F_109 ( V_161 , V_172 ) ;
F_109 ( V_161 , V_173 ) ;
F_109 ( V_162 , V_163 ) ;
F_109 ( V_162 , V_174 ) ;
F_109 ( V_162 , V_175 ) ;
F_109 ( V_163 , V_176 ) ;
F_109 ( V_43 , V_46 ) ;
F_109 ( V_43 , V_177 ) ;
F_109 ( V_178 , va_start ) ;
F_109 ( V_178 , V_44 ) ;
F_107 ( V_162 . V_163 , V_179 ) ;
F_112 () ;
F_107 ( V_163 . V_176 , V_180 ) ;
F_113 ( V_181 ) ;
F_113 ( V_182 ) ;
F_113 ( V_183 ) ;
F_113 ( V_184 ) ;
F_113 ( V_185 ) ;
#ifdef F_114
F_113 ( V_186 ) ;
#endif
F_113 ( V_187 ) ;
F_113 ( V_188 ) ;
#ifdef F_115
F_113 ( V_189 ) ;
#endif
#ifdef F_116
F_103 ( V_190 ) ;
#endif
F_97 () ;
F_93 () ;
return 0 ;
}
int F_117 ( void )
{
int error = 0 ;
if ( ! F_56 ( & V_90 ) )
return - V_191 ;
if ( ! V_192 ) {
error = - V_19 ;
goto V_193;
}
#ifdef F_118
if ( V_192 -> V_194 ) {
F_119 () ;
F_120 () ;
error = F_121 () ;
if ( error ) {
error = - V_191 ;
goto V_195;
}
F_122 () ;
error = F_123 ( V_196 ) ;
if ( error )
goto V_197;
error = F_124 ( V_196 ) ;
if ( error )
goto V_198;
error = F_125 () ;
if ( error )
goto V_199;
F_126 () ;
error = F_127 () ;
if ( error )
goto V_200;
} else
#endif
{
V_201 = true ;
F_128 ( NULL ) ;
F_129 () ;
F_130 () ;
F_131 ( L_14 ) ;
F_132 () ;
}
F_60 ( V_192 ) ;
#ifdef F_118
if ( V_192 -> V_194 ) {
F_133 () ;
V_200:
F_134 () ;
V_199:
F_135 () ;
F_136 ( V_202 ) ;
V_198:
F_137 ( V_202 ) ;
V_197:
F_138 () ;
F_139 () ;
V_195:
F_140 () ;
F_141 () ;
}
#endif
V_193:
F_61 ( & V_90 ) ;
return error ;
}
void __weak F_69 ( void )
{}
void __weak F_72 ( void )
{}
