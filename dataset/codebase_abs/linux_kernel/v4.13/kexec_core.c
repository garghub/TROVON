int F_1 ( struct V_1 * V_2 )
{
if ( V_3 )
return 0 ;
if ( F_2 () || ! V_2 -> V_4 || F_3 ( V_2 ) || V_5 )
return 1 ;
return 0 ;
}
int F_4 ( void )
{
return ! ! V_6 ;
}
int F_5 ( struct V_7 * V_8 )
{
int V_9 ;
unsigned long V_10 = V_8 -> V_10 ;
unsigned long V_11 = 0 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_8 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_8 -> V_14 [ V_9 ] . V_16 ;
if ( V_12 > V_13 )
return - V_17 ;
if ( ( V_12 & ~ V_18 ) || ( V_13 & ~ V_18 ) )
return - V_17 ;
if ( V_13 >= V_19 )
return - V_17 ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
unsigned long V_20 ;
V_12 = V_8 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_8 -> V_14 [ V_9 ] . V_16 ;
for ( V_20 = 0 ; V_20 < V_9 ; V_20 ++ ) {
unsigned long V_21 , V_22 ;
V_21 = V_8 -> V_14 [ V_20 ] . V_15 ;
V_22 = V_21 + V_8 -> V_14 [ V_20 ] . V_16 ;
if ( ( V_13 > V_21 ) && ( V_12 < V_22 ) )
return - V_23 ;
}
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_8 -> V_14 [ V_9 ] . V_24 > V_8 -> V_14 [ V_9 ] . V_16 )
return - V_23 ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( F_6 ( V_8 -> V_14 [ V_9 ] . V_16 ) > V_25 / 2 )
return - V_23 ;
V_11 += F_6 ( V_8 -> V_14 [ V_9 ] . V_16 ) ;
}
if ( V_11 > V_25 / 2 )
return - V_23 ;
if ( V_8 -> type == V_26 ) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_8 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_8 -> V_14 [ V_9 ] . V_16 - 1 ;
if ( ( V_12 < F_7 ( V_27 . V_28 ) ) ||
( V_13 > F_7 ( V_27 . V_29 ) ) )
return - V_17 ;
}
}
return 0 ;
}
struct V_7 * F_8 ( void )
{
struct V_7 * V_8 ;
V_8 = F_9 ( sizeof( * V_8 ) , V_30 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = & V_8 -> V_31 ;
V_8 -> V_33 = & V_8 -> V_31 ;
V_8 -> V_34 = ~ 0 ;
V_8 -> type = V_35 ;
F_10 ( & V_8 -> V_36 ) ;
F_10 ( & V_8 -> V_37 ) ;
F_10 ( & V_8 -> V_38 ) ;
return V_8 ;
}
int F_11 ( struct V_7 * V_8 ,
unsigned long V_28 ,
unsigned long V_29 )
{
unsigned long V_9 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_8 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_8 -> V_14 [ V_9 ] . V_16 ;
if ( ( V_29 > V_12 ) && ( V_28 < V_13 ) )
return 1 ;
}
return 0 ;
}
static struct V_39 * F_12 ( T_1 V_40 , unsigned int V_41 )
{
struct V_39 * V_42 ;
V_42 = F_13 ( V_40 , V_41 ) ;
if ( V_42 ) {
unsigned int V_43 , V_9 ;
V_42 -> V_44 = NULL ;
F_14 ( V_42 , V_41 ) ;
V_43 = 1 << V_41 ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ )
F_15 ( V_42 + V_9 ) ;
}
return V_42 ;
}
static void F_16 ( struct V_39 * V_39 )
{
unsigned int V_41 , V_43 , V_9 ;
V_41 = F_17 ( V_39 ) ;
V_43 = 1 << V_41 ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ )
F_18 ( V_39 + V_9 ) ;
F_19 ( V_39 , V_41 ) ;
}
void F_20 ( struct V_45 * V_46 )
{
struct V_39 * V_39 , * V_47 ;
F_21 (page, next, list, lru) {
F_22 ( & V_39 -> V_48 ) ;
F_16 ( V_39 ) ;
}
}
static struct V_39 * F_23 ( struct V_7 * V_8 ,
unsigned int V_41 )
{
struct V_45 V_49 ;
struct V_39 * V_42 ;
unsigned int V_43 ;
V_43 = 1 << V_41 ;
F_10 ( & V_49 ) ;
do {
unsigned long V_50 , V_51 , V_52 , V_53 ;
V_42 = F_12 ( V_54 , V_41 ) ;
if ( ! V_42 )
break;
V_50 = F_24 ( V_42 ) ;
V_51 = V_50 + V_43 ;
V_52 = V_50 << V_55 ;
V_53 = V_51 << V_55 ;
if ( ( V_51 >= ( V_56 >> V_55 ) ) ||
F_11 ( V_8 , V_52 , V_53 ) ) {
F_25 ( & V_42 -> V_48 , & V_49 ) ;
V_42 = NULL ;
}
} while ( ! V_42 );
if ( V_42 ) {
F_25 ( & V_42 -> V_48 , & V_8 -> V_36 ) ;
}
F_20 ( & V_49 ) ;
return V_42 ;
}
static struct V_39 * F_26 ( struct V_7 * V_8 ,
unsigned int V_41 )
{
unsigned long V_57 , V_58 , V_59 ;
struct V_39 * V_42 ;
V_42 = NULL ;
V_59 = ( 1 << V_41 ) << V_55 ;
V_57 = ( V_8 -> V_34 + ( V_59 - 1 ) ) & ~ ( V_59 - 1 ) ;
V_58 = V_57 + V_59 - 1 ;
while ( V_58 <= V_27 . V_29 ) {
unsigned long V_9 ;
F_27 () ;
if ( V_58 > V_60 )
break;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_8 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_8 -> V_14 [ V_9 ] . V_16 - 1 ;
if ( ( V_58 >= V_12 ) && ( V_57 <= V_13 ) ) {
V_57 = ( V_13 + ( V_59 - 1 ) ) & ~ ( V_59 - 1 ) ;
V_58 = V_57 + V_59 - 1 ;
break;
}
}
if ( V_9 == V_8 -> V_10 ) {
V_42 = F_28 ( V_57 >> V_55 ) ;
V_8 -> V_34 = V_58 ;
break;
}
}
return V_42 ;
}
struct V_39 * F_29 ( struct V_7 * V_8 ,
unsigned int V_41 )
{
struct V_39 * V_42 = NULL ;
switch ( V_8 -> type ) {
case V_35 :
V_42 = F_23 ( V_8 , V_41 ) ;
break;
case V_26 :
V_42 = F_26 ( V_8 , V_41 ) ;
break;
}
return V_42 ;
}
int F_30 ( struct V_7 * V_8 )
{
struct V_39 * V_61 ;
void * V_62 ;
if ( V_8 -> type != V_26 )
return 0 ;
V_61 = F_29 ( V_8 , 0 ) ;
if ( ! V_61 ) {
F_31 ( L_1 ) ;
return - V_63 ;
}
V_62 = F_32 ( & V_61 , 1 , V_64 , V_65 ) ;
if ( ! V_62 ) {
F_31 ( L_2 ) ;
return - V_63 ;
}
V_8 -> V_66 = V_62 ;
F_33 ( V_62 ) ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 , T_2 V_32 )
{
if ( * V_8 -> V_32 != 0 )
V_8 -> V_32 ++ ;
if ( V_8 -> V_32 == V_8 -> V_33 ) {
T_2 * V_67 ;
struct V_39 * V_39 ;
V_39 = F_35 ( V_8 , V_30 , V_68 ) ;
if ( ! V_39 )
return - V_63 ;
V_67 = F_36 ( V_39 ) ;
* V_8 -> V_32 = F_37 ( V_67 ) | V_69 ;
V_8 -> V_32 = V_67 ;
V_8 -> V_33 = V_67 +
( ( V_70 / sizeof( T_2 ) ) - 1 ) ;
}
* V_8 -> V_32 = V_32 ;
V_8 -> V_32 ++ ;
* V_8 -> V_32 = 0 ;
return 0 ;
}
static int F_38 ( struct V_7 * V_8 ,
unsigned long V_71 )
{
int V_72 ;
V_71 &= V_18 ;
V_72 = F_34 ( V_8 , V_71 | V_73 ) ;
return V_72 ;
}
static int F_39 ( struct V_7 * V_8 , unsigned long V_39 )
{
int V_72 ;
V_39 &= V_18 ;
V_72 = F_34 ( V_8 , V_39 | V_74 ) ;
return V_72 ;
}
static void F_40 ( struct V_7 * V_8 )
{
F_20 ( & V_8 -> V_37 ) ;
F_20 ( & V_8 -> V_38 ) ;
}
void F_41 ( struct V_7 * V_8 )
{
if ( * V_8 -> V_32 != 0 )
V_8 -> V_32 ++ ;
* V_8 -> V_32 = V_75 ;
}
static void F_42 ( T_2 V_32 )
{
struct V_39 * V_39 ;
V_39 = F_43 ( V_32 >> V_55 ) ;
F_16 ( V_39 ) ;
}
void F_44 ( struct V_7 * V_8 )
{
T_2 * V_76 , V_32 ;
T_2 V_77 = 0 ;
if ( ! V_8 )
return;
if ( V_8 -> V_66 ) {
F_33 ( NULL ) ;
F_45 ( V_8 -> V_66 ) ;
}
F_40 ( V_8 ) ;
F_46 (image, ptr, entry) {
if ( V_32 & V_69 ) {
if ( V_77 & V_69 )
F_42 ( V_77 ) ;
V_77 = V_32 ;
} else if ( V_32 & V_74 )
F_42 ( V_32 ) ;
}
if ( V_77 & V_69 )
F_42 ( V_77 ) ;
F_47 ( V_8 ) ;
F_20 ( & V_8 -> V_36 ) ;
if ( V_8 -> V_78 )
F_48 ( V_8 ) ;
F_49 ( V_8 ) ;
}
static T_2 * F_50 ( struct V_7 * V_8 ,
unsigned long V_39 )
{
T_2 * V_76 , V_32 ;
unsigned long V_71 = 0 ;
F_46 (image, ptr, entry) {
if ( V_32 & V_73 )
V_71 = V_32 & V_18 ;
else if ( V_32 & V_74 ) {
if ( V_39 == V_71 )
return V_76 ;
V_71 += V_70 ;
}
}
return NULL ;
}
static struct V_39 * F_35 ( struct V_7 * V_8 ,
T_1 V_40 ,
unsigned long V_71 )
{
struct V_39 * V_39 ;
unsigned long V_52 ;
F_51 (page, &image->dest_pages, lru) {
V_52 = F_24 ( V_39 ) << V_55 ;
if ( V_52 == V_71 ) {
F_22 ( & V_39 -> V_48 ) ;
return V_39 ;
}
}
V_39 = NULL ;
while ( 1 ) {
T_2 * V_79 ;
V_39 = F_12 ( V_40 , 0 ) ;
if ( ! V_39 )
return NULL ;
if ( F_24 ( V_39 ) >
( V_80 >> V_55 ) ) {
F_25 ( & V_39 -> V_48 , & V_8 -> V_38 ) ;
continue;
}
V_52 = F_24 ( V_39 ) << V_55 ;
if ( V_52 == V_71 )
break;
if ( ! F_11 ( V_8 , V_52 ,
V_52 + V_70 ) )
break;
V_79 = F_50 ( V_8 , V_52 ) ;
if ( V_79 ) {
unsigned long V_81 ;
struct V_39 * V_82 ;
V_81 = * V_79 & V_18 ;
V_82 = F_43 ( V_81 >> V_55 ) ;
F_52 ( V_39 , V_82 ) ;
* V_79 = V_52 | ( * V_79 & ~ V_18 ) ;
if ( ! ( V_40 & V_83 ) &&
F_53 ( V_82 ) ) {
F_16 ( V_82 ) ;
continue;
}
V_52 = V_81 ;
V_39 = V_82 ;
break;
}
F_25 ( & V_39 -> V_48 , & V_8 -> V_37 ) ;
}
return V_39 ;
}
static int F_54 ( struct V_7 * V_8 ,
struct V_84 * V_14 )
{
unsigned long V_85 ;
T_3 V_86 , V_87 ;
int V_72 ;
unsigned char T_4 * V_88 = NULL ;
unsigned char * V_89 = NULL ;
V_72 = 0 ;
if ( V_8 -> V_78 )
V_89 = V_14 -> V_89 ;
else
V_88 = V_14 -> V_88 ;
V_86 = V_14 -> V_24 ;
V_87 = V_14 -> V_16 ;
V_85 = V_14 -> V_15 ;
V_72 = F_38 ( V_8 , V_85 ) ;
if ( V_72 < 0 )
goto V_90;
while ( V_87 ) {
struct V_39 * V_39 ;
char * V_76 ;
T_3 V_91 , V_92 ;
V_39 = F_35 ( V_8 , V_93 , V_85 ) ;
if ( ! V_39 ) {
V_72 = - V_63 ;
goto V_90;
}
V_72 = F_39 ( V_8 , F_24 ( V_39 )
<< V_55 ) ;
if ( V_72 < 0 )
goto V_90;
V_76 = F_55 ( V_39 ) ;
F_56 ( V_76 ) ;
V_76 += V_85 & ~ V_18 ;
V_92 = F_57 ( T_3 , V_87 ,
V_70 - ( V_85 & ~ V_18 ) ) ;
V_91 = F_58 ( V_86 , V_92 ) ;
if ( V_8 -> V_78 )
memcpy ( V_76 , V_89 , V_91 ) ;
else
V_72 = F_59 ( V_76 , V_88 , V_91 ) ;
F_60 ( V_39 ) ;
if ( V_72 ) {
V_72 = - V_94 ;
goto V_90;
}
V_86 -= V_91 ;
V_85 += V_92 ;
if ( V_8 -> V_78 )
V_89 += V_92 ;
else
V_88 += V_92 ;
V_87 -= V_92 ;
}
V_90:
return V_72 ;
}
static int F_61 ( struct V_7 * V_8 ,
struct V_84 * V_14 )
{
unsigned long V_85 ;
T_3 V_86 , V_87 ;
int V_72 ;
unsigned char T_4 * V_88 = NULL ;
unsigned char * V_89 = NULL ;
V_72 = 0 ;
if ( V_8 -> V_78 )
V_89 = V_14 -> V_89 ;
else
V_88 = V_14 -> V_88 ;
V_86 = V_14 -> V_24 ;
V_87 = V_14 -> V_16 ;
V_85 = V_14 -> V_15 ;
while ( V_87 ) {
struct V_39 * V_39 ;
char * V_76 ;
T_3 V_91 , V_92 ;
V_39 = F_43 ( V_85 >> V_55 ) ;
if ( ! V_39 ) {
V_72 = - V_63 ;
goto V_90;
}
V_76 = F_55 ( V_39 ) ;
V_76 += V_85 & ~ V_18 ;
V_92 = F_57 ( T_3 , V_87 ,
V_70 - ( V_85 & ~ V_18 ) ) ;
V_91 = F_58 ( V_86 , V_92 ) ;
if ( V_92 > V_91 ) {
memset ( V_76 + V_91 , 0 , V_92 - V_91 ) ;
}
if ( V_8 -> V_78 )
memcpy ( V_76 , V_89 , V_91 ) ;
else
V_72 = F_59 ( V_76 , V_88 , V_91 ) ;
F_62 ( V_39 ) ;
F_60 ( V_39 ) ;
if ( V_72 ) {
V_72 = - V_94 ;
goto V_90;
}
V_86 -= V_91 ;
V_85 += V_92 ;
if ( V_8 -> V_78 )
V_89 += V_92 ;
else
V_88 += V_92 ;
V_87 -= V_92 ;
}
V_90:
return V_72 ;
}
int F_63 ( struct V_7 * V_8 ,
struct V_84 * V_14 )
{
int V_72 = - V_63 ;
switch ( V_8 -> type ) {
case V_35 :
V_72 = F_54 ( V_8 , V_14 ) ;
break;
case V_26 :
V_72 = F_61 ( V_8 , V_14 ) ;
break;
}
return V_72 ;
}
void T_5 F_64 ( struct V_95 * V_96 )
{
if ( F_65 ( & V_97 ) ) {
if ( V_6 ) {
struct V_95 V_98 ;
F_66 ( & V_98 , V_96 ) ;
F_67 () ;
F_68 ( & V_98 ) ;
F_69 ( V_6 ) ;
}
F_70 ( & V_97 ) ;
}
}
void F_71 ( struct V_95 * V_96 )
{
int V_99 , V_100 ;
V_100 = F_72 () ;
V_99 = F_73 ( & V_101 , V_102 , V_100 ) ;
if ( V_99 == V_102 ) {
F_74 () ;
F_64 ( V_96 ) ;
F_75 ( & V_101 , V_102 ) ;
}
}
T_3 F_76 ( void )
{
T_3 V_59 = 0 ;
F_77 ( & V_97 ) ;
if ( V_27 . V_29 != V_27 . V_28 )
V_59 = F_78 ( & V_27 ) ;
F_70 ( & V_97 ) ;
return V_59 ;
}
void __weak F_79 ( unsigned long V_103 ,
unsigned long V_29 )
{
unsigned long V_52 ;
for ( V_52 = V_103 ; V_52 < V_29 ; V_52 += V_70 )
F_80 ( F_43 ( V_52 >> V_55 ) ) ;
}
int F_81 ( unsigned long V_104 )
{
int V_105 = 0 ;
unsigned long V_28 , V_29 ;
unsigned long V_106 ;
struct V_107 * V_108 ;
F_77 ( & V_97 ) ;
if ( V_6 ) {
V_105 = - V_109 ;
goto V_110;
}
V_28 = V_27 . V_28 ;
V_29 = V_27 . V_29 ;
V_106 = ( V_29 == 0 ) ? 0 : V_29 - V_28 + 1 ;
if ( V_104 >= V_106 ) {
V_105 = ( V_104 == V_106 ) ? 0 : - V_23 ;
goto V_110;
}
V_108 = F_9 ( sizeof( * V_108 ) , V_30 ) ;
if ( ! V_108 ) {
V_105 = - V_63 ;
goto V_110;
}
V_28 = F_82 ( V_28 , V_111 ) ;
V_29 = F_82 ( V_28 + V_104 , V_111 ) ;
F_79 ( V_29 , V_27 . V_29 ) ;
if ( ( V_28 == V_29 ) && ( V_27 . V_112 != NULL ) )
F_83 ( & V_27 ) ;
V_108 -> V_28 = V_29 ;
V_108 -> V_29 = V_27 . V_29 ;
V_108 -> V_113 = V_114 | V_115 ;
V_108 -> V_116 = L_3 ;
V_27 . V_29 = V_29 - 1 ;
F_84 ( & V_117 , V_108 ) ;
V_110:
F_70 ( & V_97 ) ;
return V_105 ;
}
void F_85 ( struct V_95 * V_96 , int V_118 )
{
struct V_119 V_120 ;
T_6 * V_88 ;
if ( ( V_118 < 0 ) || ( V_118 >= V_121 ) )
return;
V_88 = ( T_6 * ) F_86 ( V_122 , V_118 ) ;
if ( ! V_88 )
return;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_123 = V_124 -> V_4 ;
F_87 ( & V_120 . V_125 , V_96 ) ;
V_88 = F_88 ( V_88 , V_126 , V_127 ,
& V_120 , sizeof( V_120 ) ) ;
F_89 ( V_88 ) ;
}
static int T_7 F_90 ( void )
{
T_3 V_59 , V_128 ;
V_59 = sizeof( V_129 ) ;
V_128 = F_58 ( F_91 ( sizeof( V_129 ) ) , V_70 ) ;
F_92 ( V_59 > V_70 ) ;
V_122 = F_93 ( V_59 , V_128 ) ;
if ( ! V_122 ) {
F_31 ( L_4 ) ;
return - V_63 ;
}
return 0 ;
}
int F_94 ( void )
{
int error = 0 ;
if ( ! F_65 ( & V_97 ) )
return - V_130 ;
if ( ! V_131 ) {
error = - V_23 ;
goto V_132;
}
#ifdef F_95
if ( V_131 -> V_133 ) {
F_96 () ;
F_97 () ;
error = F_98 () ;
if ( error ) {
error = - V_130 ;
goto V_134;
}
F_99 () ;
error = F_100 ( V_135 ) ;
if ( error )
goto V_136;
error = F_101 ( V_135 ) ;
if ( error )
goto V_137;
error = F_102 () ;
if ( error )
goto V_138;
F_103 () ;
error = F_104 () ;
if ( error )
goto V_139;
} else
#endif
{
V_140 = true ;
F_105 ( NULL ) ;
F_106 () ;
F_107 () ;
F_108 ( L_5 ) ;
F_109 () ;
}
F_69 ( V_131 ) ;
#ifdef F_95
if ( V_131 -> V_133 ) {
F_110 () ;
V_139:
F_111 () ;
V_138:
F_112 () ;
F_113 ( V_141 ) ;
V_137:
F_114 ( V_141 ) ;
V_136:
F_115 () ;
F_116 () ;
V_134:
F_117 () ;
F_118 () ;
}
#endif
V_132:
F_70 ( & V_97 ) ;
return error ;
}
void __weak F_119 ( void )
{}
void __weak F_120 ( void )
{}
