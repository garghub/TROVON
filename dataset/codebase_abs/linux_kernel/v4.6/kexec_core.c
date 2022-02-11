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
struct V_37 * V_37 , * V_45 ;
F_18 (page, next, list, lru) {
F_19 ( & V_37 -> V_46 ) ;
F_13 ( V_37 ) ;
}
}
static struct V_37 * F_20 ( struct V_6 * V_7 ,
unsigned int V_39 )
{
struct V_43 V_47 ;
struct V_37 * V_40 ;
unsigned int V_41 ;
V_41 = 1 << V_39 ;
F_7 ( & V_47 ) ;
do {
unsigned long V_48 , V_49 , V_50 , V_51 ;
V_40 = F_9 ( V_52 , V_39 ) ;
if ( ! V_40 )
break;
V_48 = F_21 ( V_40 ) ;
V_49 = V_48 + V_41 ;
V_50 = V_48 << V_53 ;
V_51 = V_49 << V_53 ;
if ( ( V_49 >= ( V_54 >> V_53 ) ) ||
F_8 ( V_7 , V_50 , V_51 ) ) {
F_22 ( & V_40 -> V_46 , & V_47 ) ;
V_40 = NULL ;
}
} while ( ! V_40 );
if ( V_40 ) {
F_22 ( & V_40 -> V_46 , & V_7 -> V_34 ) ;
}
F_17 ( & V_47 ) ;
return V_40 ;
}
static struct V_37 * F_23 ( struct V_6 * V_7 ,
unsigned int V_39 )
{
unsigned long V_55 , V_56 , V_57 ;
struct V_37 * V_40 ;
V_40 = NULL ;
V_57 = ( 1 << V_39 ) << V_53 ;
V_55 = ( V_7 -> V_32 + ( V_57 - 1 ) ) & ~ ( V_57 - 1 ) ;
V_56 = V_55 + V_57 - 1 ;
while ( V_56 <= V_25 . V_27 ) {
unsigned long V_9 ;
if ( V_56 > V_58 )
break;
for ( V_9 = 0 ; V_9 < V_7 -> V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_7 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_7 -> V_14 [ V_9 ] . V_16 - 1 ;
if ( ( V_56 >= V_12 ) && ( V_55 <= V_13 ) ) {
V_55 = ( V_13 + ( V_57 - 1 ) ) & ~ ( V_57 - 1 ) ;
V_56 = V_55 + V_57 - 1 ;
break;
}
}
if ( V_9 == V_7 -> V_10 ) {
V_40 = F_24 ( V_55 >> V_53 ) ;
V_7 -> V_32 = V_56 ;
break;
}
}
return V_40 ;
}
struct V_37 * F_25 ( struct V_6 * V_7 ,
unsigned int V_39 )
{
struct V_37 * V_40 = NULL ;
switch ( V_7 -> type ) {
case V_33 :
V_40 = F_20 ( V_7 , V_39 ) ;
break;
case V_24 :
V_40 = F_23 ( V_7 , V_39 ) ;
break;
}
return V_40 ;
}
static int F_26 ( struct V_6 * V_7 , T_2 V_30 )
{
if ( * V_7 -> V_30 != 0 )
V_7 -> V_30 ++ ;
if ( V_7 -> V_30 == V_7 -> V_31 ) {
T_2 * V_59 ;
struct V_37 * V_37 ;
V_37 = F_27 ( V_7 , V_28 , V_60 ) ;
if ( ! V_37 )
return - V_61 ;
V_59 = F_28 ( V_37 ) ;
* V_7 -> V_30 = F_29 ( V_59 ) | V_62 ;
V_7 -> V_30 = V_59 ;
V_7 -> V_31 = V_59 +
( ( V_63 / sizeof( T_2 ) ) - 1 ) ;
}
* V_7 -> V_30 = V_30 ;
V_7 -> V_30 ++ ;
* V_7 -> V_30 = 0 ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 ,
unsigned long V_64 )
{
int V_8 ;
V_64 &= V_17 ;
V_8 = F_26 ( V_7 , V_64 | V_65 ) ;
return V_8 ;
}
static int F_31 ( struct V_6 * V_7 , unsigned long V_37 )
{
int V_8 ;
V_37 &= V_17 ;
V_8 = F_26 ( V_7 , V_37 | V_66 ) ;
return V_8 ;
}
static void F_32 ( struct V_6 * V_7 )
{
F_17 ( & V_7 -> V_35 ) ;
F_17 ( & V_7 -> V_36 ) ;
}
void F_33 ( struct V_6 * V_7 )
{
if ( * V_7 -> V_30 != 0 )
V_7 -> V_30 ++ ;
* V_7 -> V_30 = V_67 ;
}
static void F_34 ( T_2 V_30 )
{
struct V_37 * V_37 ;
V_37 = F_24 ( V_30 >> V_53 ) ;
F_13 ( V_37 ) ;
}
void F_35 ( struct V_6 * V_7 )
{
T_2 * V_68 , V_30 ;
T_2 V_69 = 0 ;
if ( ! V_7 )
return;
F_32 ( V_7 ) ;
F_36 (image, ptr, entry) {
if ( V_30 & V_62 ) {
if ( V_69 & V_62 )
F_34 ( V_69 ) ;
V_69 = V_30 ;
} else if ( V_30 & V_66 )
F_34 ( V_30 ) ;
}
if ( V_69 & V_62 )
F_34 ( V_69 ) ;
F_37 ( V_7 ) ;
F_17 ( & V_7 -> V_34 ) ;
if ( V_7 -> V_70 )
F_38 ( V_7 ) ;
F_39 ( V_7 ) ;
}
static T_2 * F_40 ( struct V_6 * V_7 ,
unsigned long V_37 )
{
T_2 * V_68 , V_30 ;
unsigned long V_64 = 0 ;
F_36 (image, ptr, entry) {
if ( V_30 & V_65 )
V_64 = V_30 & V_17 ;
else if ( V_30 & V_66 ) {
if ( V_37 == V_64 )
return V_68 ;
V_64 += V_63 ;
}
}
return NULL ;
}
static struct V_37 * F_27 ( struct V_6 * V_7 ,
T_1 V_38 ,
unsigned long V_64 )
{
struct V_37 * V_37 ;
unsigned long V_50 ;
F_41 (page, &image->dest_pages, lru) {
V_50 = F_21 ( V_37 ) << V_53 ;
if ( V_50 == V_64 ) {
F_19 ( & V_37 -> V_46 ) ;
return V_37 ;
}
}
V_37 = NULL ;
while ( 1 ) {
T_2 * V_71 ;
V_37 = F_9 ( V_38 , 0 ) ;
if ( ! V_37 )
return NULL ;
if ( F_21 ( V_37 ) >
( V_72 >> V_53 ) ) {
F_22 ( & V_37 -> V_46 , & V_7 -> V_36 ) ;
continue;
}
V_50 = F_21 ( V_37 ) << V_53 ;
if ( V_50 == V_64 )
break;
if ( ! F_8 ( V_7 , V_50 ,
V_50 + V_63 ) )
break;
V_71 = F_40 ( V_7 , V_50 ) ;
if ( V_71 ) {
unsigned long V_73 ;
struct V_37 * V_74 ;
V_73 = * V_71 & V_17 ;
V_74 = F_24 ( V_73 >> V_53 ) ;
F_42 ( V_37 , V_74 ) ;
* V_71 = V_50 | ( * V_71 & ~ V_17 ) ;
if ( ! ( V_38 & V_75 ) &&
F_43 ( V_74 ) ) {
F_13 ( V_74 ) ;
continue;
}
V_50 = V_73 ;
V_37 = V_74 ;
break;
}
F_22 ( & V_37 -> V_46 , & V_7 -> V_35 ) ;
}
return V_37 ;
}
static int F_44 ( struct V_6 * V_7 ,
struct V_76 * V_14 )
{
unsigned long V_77 ;
T_3 V_78 , V_79 ;
int V_8 ;
unsigned char T_4 * V_80 = NULL ;
unsigned char * V_81 = NULL ;
V_8 = 0 ;
if ( V_7 -> V_70 )
V_81 = V_14 -> V_81 ;
else
V_80 = V_14 -> V_80 ;
V_78 = V_14 -> V_23 ;
V_79 = V_14 -> V_16 ;
V_77 = V_14 -> V_15 ;
V_8 = F_30 ( V_7 , V_77 ) ;
if ( V_8 < 0 )
goto V_82;
while ( V_79 ) {
struct V_37 * V_37 ;
char * V_68 ;
T_3 V_83 , V_84 ;
V_37 = F_27 ( V_7 , V_85 , V_77 ) ;
if ( ! V_37 ) {
V_8 = - V_61 ;
goto V_82;
}
V_8 = F_31 ( V_7 , F_21 ( V_37 )
<< V_53 ) ;
if ( V_8 < 0 )
goto V_82;
V_68 = F_45 ( V_37 ) ;
F_46 ( V_68 ) ;
V_68 += V_77 & ~ V_17 ;
V_84 = F_47 ( T_3 , V_79 ,
V_63 - ( V_77 & ~ V_17 ) ) ;
V_83 = F_48 ( V_78 , V_84 ) ;
if ( V_7 -> V_70 )
memcpy ( V_68 , V_81 , V_83 ) ;
else
V_8 = F_49 ( V_68 , V_80 , V_83 ) ;
F_50 ( V_37 ) ;
if ( V_8 ) {
V_8 = - V_86 ;
goto V_82;
}
V_78 -= V_83 ;
V_77 += V_84 ;
if ( V_7 -> V_70 )
V_81 += V_84 ;
else
V_80 += V_84 ;
V_79 -= V_84 ;
}
V_82:
return V_8 ;
}
static int F_51 ( struct V_6 * V_7 ,
struct V_76 * V_14 )
{
unsigned long V_77 ;
T_3 V_78 , V_79 ;
int V_8 ;
unsigned char T_4 * V_80 = NULL ;
unsigned char * V_81 = NULL ;
V_8 = 0 ;
if ( V_7 -> V_70 )
V_81 = V_14 -> V_81 ;
else
V_80 = V_14 -> V_80 ;
V_78 = V_14 -> V_23 ;
V_79 = V_14 -> V_16 ;
V_77 = V_14 -> V_15 ;
while ( V_79 ) {
struct V_37 * V_37 ;
char * V_68 ;
T_3 V_83 , V_84 ;
V_37 = F_24 ( V_77 >> V_53 ) ;
if ( ! V_37 ) {
V_8 = - V_61 ;
goto V_82;
}
V_68 = F_45 ( V_37 ) ;
V_68 += V_77 & ~ V_17 ;
V_84 = F_47 ( T_3 , V_79 ,
V_63 - ( V_77 & ~ V_17 ) ) ;
V_83 = F_48 ( V_78 , V_84 ) ;
if ( V_84 > V_83 ) {
memset ( V_68 + V_83 , 0 , V_84 - V_83 ) ;
}
if ( V_7 -> V_70 )
memcpy ( V_68 , V_81 , V_83 ) ;
else
V_8 = F_49 ( V_68 , V_80 , V_83 ) ;
F_52 ( V_37 ) ;
F_50 ( V_37 ) ;
if ( V_8 ) {
V_8 = - V_86 ;
goto V_82;
}
V_78 -= V_83 ;
V_77 += V_84 ;
if ( V_7 -> V_70 )
V_81 += V_84 ;
else
V_80 += V_84 ;
V_79 -= V_84 ;
}
V_82:
return V_8 ;
}
int F_53 ( struct V_6 * V_7 ,
struct V_76 * V_14 )
{
int V_8 = - V_61 ;
switch ( V_7 -> type ) {
case V_33 :
V_8 = F_44 ( V_7 , V_14 ) ;
break;
case V_24 :
V_8 = F_51 ( V_7 , V_14 ) ;
break;
}
return V_8 ;
}
void F_54 ( struct V_87 * V_88 )
{
if ( F_55 ( & V_89 ) ) {
if ( V_90 ) {
struct V_87 V_91 ;
F_56 ( & V_91 , V_88 ) ;
F_57 () ;
F_58 ( & V_91 ) ;
F_59 ( V_90 ) ;
}
F_60 ( & V_89 ) ;
}
}
void F_61 ( struct V_87 * V_88 )
{
int V_92 , V_93 ;
V_93 = F_62 () ;
V_92 = F_63 ( & V_94 , V_95 , V_93 ) ;
if ( V_92 == V_95 ) {
F_54 ( V_88 ) ;
F_64 ( & V_94 , V_95 ) ;
}
}
T_3 F_65 ( void )
{
T_3 V_57 = 0 ;
F_66 ( & V_89 ) ;
if ( V_25 . V_27 != V_25 . V_26 )
V_57 = F_67 ( & V_25 ) ;
F_60 ( & V_89 ) ;
return V_57 ;
}
void __weak F_68 ( unsigned long V_96 ,
unsigned long V_27 )
{
unsigned long V_50 ;
for ( V_50 = V_96 ; V_50 < V_27 ; V_50 += V_63 )
F_69 ( F_24 ( V_50 >> V_53 ) ) ;
}
int F_70 ( unsigned long V_97 )
{
int V_98 = 0 ;
unsigned long V_26 , V_27 ;
unsigned long V_99 ;
struct V_100 * V_101 ;
F_66 ( & V_89 ) ;
if ( V_90 ) {
V_98 = - V_102 ;
goto V_103;
}
V_26 = V_25 . V_26 ;
V_27 = V_25 . V_27 ;
V_99 = ( V_27 == 0 ) ? 0 : V_27 - V_26 + 1 ;
if ( V_97 >= V_99 ) {
V_98 = ( V_97 == V_99 ) ? 0 : - V_19 ;
goto V_103;
}
V_101 = F_6 ( sizeof( * V_101 ) , V_28 ) ;
if ( ! V_101 ) {
V_98 = - V_61 ;
goto V_103;
}
V_26 = F_71 ( V_26 , V_104 ) ;
V_27 = F_71 ( V_26 + V_97 , V_104 ) ;
F_72 () ;
F_68 ( V_27 , V_25 . V_27 ) ;
if ( ( V_26 == V_27 ) && ( V_25 . V_105 != NULL ) )
F_73 ( & V_25 ) ;
V_101 -> V_26 = V_27 ;
V_101 -> V_27 = V_25 . V_27 ;
V_101 -> V_106 = V_107 | V_108 ;
V_101 -> V_109 = L_1 ;
V_25 . V_27 = V_27 - 1 ;
F_74 ( & V_110 , V_101 ) ;
F_75 () ;
V_103:
F_60 ( & V_89 ) ;
return V_98 ;
}
static T_5 * F_76 ( T_5 * V_80 , char * V_109 , unsigned type , void * V_111 ,
T_3 V_112 )
{
struct V_113 V_114 ;
V_114 . V_115 = strlen ( V_109 ) + 1 ;
V_114 . V_116 = V_112 ;
V_114 . V_117 = type ;
memcpy ( V_80 , & V_114 , sizeof( V_114 ) ) ;
V_80 += ( sizeof( V_114 ) + 3 ) / 4 ;
memcpy ( V_80 , V_109 , V_114 . V_115 ) ;
V_80 += ( V_114 . V_115 + 3 ) / 4 ;
memcpy ( V_80 , V_111 , V_114 . V_116 ) ;
V_80 += ( V_114 . V_116 + 3 ) / 4 ;
return V_80 ;
}
static void F_77 ( T_5 * V_80 )
{
struct V_113 V_114 ;
V_114 . V_115 = 0 ;
V_114 . V_116 = 0 ;
V_114 . V_117 = 0 ;
memcpy ( V_80 , & V_114 , sizeof( V_114 ) ) ;
}
void F_78 ( struct V_87 * V_88 , int V_118 )
{
struct V_119 V_120 ;
T_5 * V_80 ;
if ( ( V_118 < 0 ) || ( V_118 >= V_121 ) )
return;
V_80 = ( T_5 * ) F_79 ( V_122 , V_118 ) ;
if ( ! V_80 )
return;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_123 = V_124 -> V_4 ;
F_80 ( & V_120 . V_125 , V_88 ) ;
V_80 = F_76 ( V_80 , V_126 , V_127 ,
& V_120 , sizeof( V_120 ) ) ;
F_77 ( V_80 ) ;
}
static int T_6 F_81 ( void )
{
T_3 V_57 , V_128 ;
V_57 = sizeof( V_129 ) ;
V_128 = F_48 ( F_82 ( sizeof( V_129 ) ) , V_63 ) ;
F_83 ( V_57 > V_63 ) ;
V_122 = F_84 ( V_57 , V_128 ) ;
if ( ! V_122 ) {
F_85 ( L_2 ) ;
return - V_61 ;
}
return 0 ;
}
static int T_6 F_86 ( char * V_130 ,
unsigned long long V_131 ,
unsigned long long * V_132 ,
unsigned long long * V_133 )
{
char * V_134 = V_130 , * V_135 ;
do {
unsigned long long V_26 , V_27 = V_136 , V_57 ;
V_26 = F_87 ( V_134 , & V_135 ) ;
if ( V_134 == V_135 ) {
F_85 ( L_3 ) ;
return - V_19 ;
}
V_134 = V_135 ;
if ( * V_134 != '-' ) {
F_85 ( L_4 ) ;
return - V_19 ;
}
V_134 ++ ;
if ( * V_134 != ':' ) {
V_27 = F_87 ( V_134 , & V_135 ) ;
if ( V_134 == V_135 ) {
F_85 ( L_3 ) ;
return - V_19 ;
}
V_134 = V_135 ;
if ( V_27 <= V_26 ) {
F_85 ( L_5 ) ;
return - V_19 ;
}
}
if ( * V_134 != ':' ) {
F_85 ( L_6 ) ;
return - V_19 ;
}
V_134 ++ ;
V_57 = F_87 ( V_134 , & V_135 ) ;
if ( V_134 == V_135 ) {
F_85 ( L_7 ) ;
return - V_19 ;
}
V_134 = V_135 ;
if ( V_57 >= V_131 ) {
F_85 ( L_8 ) ;
return - V_19 ;
}
if ( V_131 >= V_26 && V_131 < V_27 ) {
* V_132 = V_57 ;
break;
}
} while ( * V_134 ++ == ',' );
if ( * V_132 > 0 ) {
while ( * V_134 && * V_134 != ' ' && * V_134 != '@' )
V_134 ++ ;
if ( * V_134 == '@' ) {
V_134 ++ ;
* V_133 = F_87 ( V_134 , & V_135 ) ;
if ( V_134 == V_135 ) {
F_85 ( L_9 ) ;
return - V_19 ;
}
}
}
return 0 ;
}
static int T_6 F_88 ( char * V_130 ,
unsigned long long * V_132 ,
unsigned long long * V_133 )
{
char * V_134 = V_130 ;
* V_132 = F_87 ( V_130 , & V_134 ) ;
if ( V_130 == V_134 ) {
F_85 ( L_10 ) ;
return - V_19 ;
}
if ( * V_134 == '@' )
* V_133 = F_87 ( V_134 + 1 , & V_134 ) ;
else if ( * V_134 != ' ' && * V_134 != '\0' ) {
F_85 ( L_11 , * V_134 ) ;
return - V_19 ;
}
return 0 ;
}
static int T_6 F_89 ( char * V_130 ,
unsigned long long * V_132 ,
const char * V_137 )
{
char * V_134 = V_130 ;
* V_132 = F_87 ( V_130 , & V_134 ) ;
if ( V_130 == V_134 ) {
F_85 ( L_10 ) ;
return - V_19 ;
}
if ( strncmp ( V_134 , V_137 , strlen ( V_137 ) ) ) {
F_85 ( L_11 , * V_134 ) ;
return - V_19 ;
}
V_134 += strlen ( V_137 ) ;
if ( * V_134 != ' ' && * V_134 != '\0' ) {
F_85 ( L_11 , * V_134 ) ;
return - V_19 ;
}
return 0 ;
}
static T_6 char * F_90 ( char * V_130 ,
const char * V_109 ,
const char * V_137 )
{
char * V_2 = V_130 , * V_138 = NULL ;
V_2 = strstr ( V_2 , V_109 ) ;
while ( V_2 ) {
char * V_139 = strchr ( V_2 , ' ' ) ;
char * V_140 ;
if ( ! V_139 )
V_139 = V_2 + strlen ( V_2 ) ;
if ( ! V_137 ) {
int V_9 ;
for ( V_9 = 0 ; V_141 [ V_9 ] ; V_9 ++ ) {
V_140 = V_139 - strlen ( V_141 [ V_9 ] ) ;
if ( ! strncmp ( V_140 , V_141 [ V_9 ] ,
strlen ( V_141 [ V_9 ] ) ) )
goto V_45;
}
V_138 = V_2 ;
} else {
V_140 = V_139 - strlen ( V_137 ) ;
if ( ! strncmp ( V_140 , V_137 , strlen ( V_137 ) ) )
V_138 = V_2 ;
}
V_45:
V_2 = strstr ( V_2 + 1 , V_109 ) ;
}
if ( ! V_138 )
return NULL ;
return V_138 ;
}
static int T_6 F_91 ( char * V_130 ,
unsigned long long V_131 ,
unsigned long long * V_132 ,
unsigned long long * V_133 ,
const char * V_109 ,
const char * V_137 )
{
char * V_142 , * V_143 ;
char * V_138 ;
F_92 ( ! V_132 || ! V_133 ) ;
* V_132 = 0 ;
* V_133 = 0 ;
V_138 = F_90 ( V_130 , V_109 , V_137 ) ;
if ( ! V_138 )
return - V_19 ;
V_138 += strlen ( V_109 ) ;
if ( V_137 )
return F_89 ( V_138 , V_132 ,
V_137 ) ;
V_142 = strchr ( V_138 , ':' ) ;
V_143 = strchr ( V_138 , ' ' ) ;
if ( V_142 && ( ! V_143 || V_142 < V_143 ) )
return F_86 ( V_138 , V_131 ,
V_132 , V_133 ) ;
return F_88 ( V_138 , V_132 , V_133 ) ;
}
int T_6 F_93 ( char * V_130 ,
unsigned long long V_131 ,
unsigned long long * V_132 ,
unsigned long long * V_133 )
{
return F_91 ( V_130 , V_131 , V_132 , V_133 ,
L_12 , NULL ) ;
}
int T_6 F_94 ( char * V_130 ,
unsigned long long V_131 ,
unsigned long long * V_132 ,
unsigned long long * V_133 )
{
return F_91 ( V_130 , V_131 , V_132 , V_133 ,
L_12 , V_141 [ V_144 ] ) ;
}
int T_6 F_95 ( char * V_130 ,
unsigned long long V_131 ,
unsigned long long * V_132 ,
unsigned long long * V_133 )
{
return F_91 ( V_130 , V_131 , V_132 , V_133 ,
L_12 , V_141 [ V_145 ] ) ;
}
static void F_96 ( void )
{
T_5 * V_80 = V_146 ;
if ( ! V_147 )
return;
V_80 = F_76 ( V_80 , V_148 , 0 , V_149 ,
V_147 ) ;
F_77 ( V_80 ) ;
}
void F_57 ( void )
{
F_97 ( L_13 , F_98 () ) ;
F_96 () ;
}
void F_97 ( const char * V_150 , ... )
{
T_7 args ;
char V_80 [ 0x50 ] ;
T_3 V_151 ;
va_start ( args , V_150 ) ;
V_151 = F_99 ( V_80 , sizeof( V_80 ) , V_150 , args ) ;
va_end ( args ) ;
V_151 = F_48 ( V_151 , V_152 - V_147 ) ;
memcpy ( & V_149 [ V_147 ] , V_80 , V_151 ) ;
V_147 += V_151 ;
}
void __weak F_100 ( void )
{}
unsigned long __weak F_101 ( void )
{
return F_102 ( ( unsigned long ) ( char * ) & V_146 ) ;
}
static int T_6 F_103 ( void )
{
F_104 ( V_153 . V_109 . V_154 ) ;
F_105 ( V_63 ) ;
F_106 ( V_153 ) ;
F_106 ( V_155 ) ;
#ifdef F_107
F_106 ( V_156 ) ;
#endif
F_106 ( V_157 ) ;
F_106 ( V_158 ) ;
#ifndef F_108
F_106 ( V_159 ) ;
F_106 ( V_160 ) ;
#endif
#ifdef F_109
F_106 ( V_161 ) ;
F_110 ( V_161 , V_162 ) ;
F_111 ( V_161 ) ;
F_112 ( V_161 , V_163 ) ;
#endif
F_111 ( V_37 ) ;
F_111 ( V_164 ) ;
F_111 ( V_165 ) ;
F_111 ( V_166 ) ;
F_111 ( V_43 ) ;
F_113 ( V_167 ) ;
F_112 ( V_37 , V_106 ) ;
F_112 ( V_37 , V_168 ) ;
F_112 ( V_37 , V_42 ) ;
F_112 ( V_37 , V_46 ) ;
F_112 ( V_37 , V_169 ) ;
F_112 ( V_37 , V_170 ) ;
F_112 ( V_37 , V_171 ) ;
F_112 ( V_37 , V_172 ) ;
F_112 ( V_37 , V_173 ) ;
F_112 ( V_164 , V_174 ) ;
F_112 ( V_164 , V_175 ) ;
#ifdef F_114
F_112 ( V_164 , V_176 ) ;
#endif
F_112 ( V_164 , V_177 ) ;
F_112 ( V_164 , V_178 ) ;
F_112 ( V_164 , V_179 ) ;
F_112 ( V_165 , V_166 ) ;
F_112 ( V_165 , V_180 ) ;
F_112 ( V_165 , V_181 ) ;
F_112 ( V_166 , V_182 ) ;
F_112 ( V_43 , V_45 ) ;
F_112 ( V_43 , V_183 ) ;
F_112 ( V_184 , va_start ) ;
F_112 ( V_184 , V_44 ) ;
F_110 ( V_165 . V_166 , V_185 ) ;
F_115 () ;
F_110 ( V_166 . V_182 , V_186 ) ;
F_116 ( V_187 ) ;
F_116 ( V_188 ) ;
F_116 ( V_189 ) ;
F_116 ( V_190 ) ;
F_116 ( V_191 ) ;
#ifdef F_117
F_116 ( V_192 ) ;
#endif
F_116 ( V_193 ) ;
F_116 ( V_194 ) ;
#ifdef F_118
F_116 ( V_195 ) ;
#endif
#ifdef F_119
F_116 ( V_196 ) ;
#endif
F_100 () ;
F_96 () ;
return 0 ;
}
int F_120 ( void )
{
int error = 0 ;
if ( ! F_55 ( & V_89 ) )
return - V_197 ;
if ( ! V_198 ) {
error = - V_19 ;
goto V_199;
}
#ifdef F_121
if ( V_198 -> V_200 ) {
F_122 () ;
F_123 () ;
error = F_124 () ;
if ( error ) {
error = - V_197 ;
goto V_201;
}
F_125 () ;
error = F_126 ( V_202 ) ;
if ( error )
goto V_203;
error = F_127 ( V_202 ) ;
if ( error )
goto V_204;
error = F_128 () ;
if ( error )
goto V_205;
F_129 () ;
error = F_130 () ;
if ( error )
goto V_206;
} else
#endif
{
V_207 = true ;
F_131 ( NULL ) ;
F_132 () ;
F_133 () ;
F_134 ( L_14 ) ;
F_135 () ;
}
F_59 ( V_198 ) ;
#ifdef F_121
if ( V_198 -> V_200 ) {
F_136 () ;
V_206:
F_137 () ;
V_205:
F_138 () ;
F_139 ( V_208 ) ;
V_204:
F_140 ( V_208 ) ;
V_203:
F_141 () ;
F_142 () ;
V_201:
F_143 () ;
F_144 () ;
}
#endif
V_199:
F_60 ( & V_89 ) ;
return error ;
}
void __weak F_72 ( void )
{}
void __weak F_75 ( void )
{}
