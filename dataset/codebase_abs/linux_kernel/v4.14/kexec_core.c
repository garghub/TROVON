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
V_42 = F_13 ( V_40 & ~ V_43 , V_41 ) ;
if ( V_42 ) {
unsigned int V_44 , V_9 ;
V_42 -> V_45 = NULL ;
F_14 ( V_42 , V_41 ) ;
V_44 = 1 << V_41 ;
for ( V_9 = 0 ; V_9 < V_44 ; V_9 ++ )
F_15 ( V_42 + V_9 ) ;
F_16 ( F_17 ( V_42 ) , V_44 ,
V_40 ) ;
if ( V_40 & V_43 )
for ( V_9 = 0 ; V_9 < V_44 ; V_9 ++ )
F_18 ( V_42 + V_9 ) ;
}
return V_42 ;
}
static void F_19 ( struct V_39 * V_39 )
{
unsigned int V_41 , V_44 , V_9 ;
V_41 = F_20 ( V_39 ) ;
V_44 = 1 << V_41 ;
F_21 ( F_17 ( V_39 ) , V_44 ) ;
for ( V_9 = 0 ; V_9 < V_44 ; V_9 ++ )
F_22 ( V_39 + V_9 ) ;
F_23 ( V_39 , V_41 ) ;
}
void F_24 ( struct V_46 * V_47 )
{
struct V_39 * V_39 , * V_48 ;
F_25 (page, next, list, lru) {
F_26 ( & V_39 -> V_49 ) ;
F_19 ( V_39 ) ;
}
}
static struct V_39 * F_27 ( struct V_7 * V_8 ,
unsigned int V_41 )
{
struct V_46 V_50 ;
struct V_39 * V_42 ;
unsigned int V_44 ;
V_44 = 1 << V_41 ;
F_10 ( & V_50 ) ;
do {
unsigned long V_51 , V_52 , V_53 , V_54 ;
V_42 = F_12 ( V_55 , V_41 ) ;
if ( ! V_42 )
break;
V_51 = F_28 ( V_42 ) ;
V_52 = V_51 + V_44 ;
V_53 = V_51 << V_56 ;
V_54 = V_52 << V_56 ;
if ( ( V_52 >= ( V_57 >> V_56 ) ) ||
F_11 ( V_8 , V_53 , V_54 ) ) {
F_29 ( & V_42 -> V_49 , & V_50 ) ;
V_42 = NULL ;
}
} while ( ! V_42 );
if ( V_42 ) {
F_29 ( & V_42 -> V_49 , & V_8 -> V_36 ) ;
}
F_24 ( & V_50 ) ;
return V_42 ;
}
static struct V_39 * F_30 ( struct V_7 * V_8 ,
unsigned int V_41 )
{
unsigned long V_58 , V_59 , V_60 ;
struct V_39 * V_42 ;
V_42 = NULL ;
V_60 = ( 1 << V_41 ) << V_56 ;
V_58 = ( V_8 -> V_34 + ( V_60 - 1 ) ) & ~ ( V_60 - 1 ) ;
V_59 = V_58 + V_60 - 1 ;
while ( V_59 <= V_27 . V_29 ) {
unsigned long V_9 ;
F_31 () ;
if ( V_59 > V_61 )
break;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 ; V_9 ++ ) {
unsigned long V_12 , V_13 ;
V_12 = V_8 -> V_14 [ V_9 ] . V_15 ;
V_13 = V_12 + V_8 -> V_14 [ V_9 ] . V_16 - 1 ;
if ( ( V_59 >= V_12 ) && ( V_58 <= V_13 ) ) {
V_58 = ( V_13 + ( V_60 - 1 ) ) & ~ ( V_60 - 1 ) ;
V_59 = V_58 + V_60 - 1 ;
break;
}
}
if ( V_9 == V_8 -> V_10 ) {
V_42 = F_32 ( V_58 >> V_56 ) ;
V_8 -> V_34 = V_59 ;
break;
}
}
return V_42 ;
}
struct V_39 * F_33 ( struct V_7 * V_8 ,
unsigned int V_41 )
{
struct V_39 * V_42 = NULL ;
switch ( V_8 -> type ) {
case V_35 :
V_42 = F_27 ( V_8 , V_41 ) ;
break;
case V_26 :
V_42 = F_30 ( V_8 , V_41 ) ;
break;
}
return V_42 ;
}
int F_34 ( struct V_7 * V_8 )
{
struct V_39 * V_62 ;
void * V_63 ;
if ( V_8 -> type != V_26 )
return 0 ;
V_62 = F_33 ( V_8 , 0 ) ;
if ( ! V_62 ) {
F_35 ( L_1 ) ;
return - V_64 ;
}
V_63 = F_36 ( & V_62 , 1 , V_65 , V_66 ) ;
if ( ! V_63 ) {
F_35 ( L_2 ) ;
return - V_64 ;
}
V_8 -> V_67 = V_63 ;
F_37 ( V_63 ) ;
return 0 ;
}
static int F_38 ( struct V_7 * V_8 , T_2 V_32 )
{
if ( * V_8 -> V_32 != 0 )
V_8 -> V_32 ++ ;
if ( V_8 -> V_32 == V_8 -> V_33 ) {
T_2 * V_68 ;
struct V_39 * V_39 ;
V_39 = F_39 ( V_8 , V_30 , V_69 ) ;
if ( ! V_39 )
return - V_64 ;
V_68 = F_17 ( V_39 ) ;
* V_8 -> V_32 = F_40 ( V_68 ) | V_70 ;
V_8 -> V_32 = V_68 ;
V_8 -> V_33 = V_68 +
( ( V_71 / sizeof( T_2 ) ) - 1 ) ;
}
* V_8 -> V_32 = V_32 ;
V_8 -> V_32 ++ ;
* V_8 -> V_32 = 0 ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 ,
unsigned long V_72 )
{
int V_73 ;
V_72 &= V_18 ;
V_73 = F_38 ( V_8 , V_72 | V_74 ) ;
return V_73 ;
}
static int F_42 ( struct V_7 * V_8 , unsigned long V_39 )
{
int V_73 ;
V_39 &= V_18 ;
V_73 = F_38 ( V_8 , V_39 | V_75 ) ;
return V_73 ;
}
static void F_43 ( struct V_7 * V_8 )
{
F_24 ( & V_8 -> V_37 ) ;
F_24 ( & V_8 -> V_38 ) ;
}
void F_44 ( struct V_7 * V_8 )
{
if ( * V_8 -> V_32 != 0 )
V_8 -> V_32 ++ ;
* V_8 -> V_32 = V_76 ;
}
static void F_45 ( T_2 V_32 )
{
struct V_39 * V_39 ;
V_39 = F_46 ( V_32 >> V_56 ) ;
F_19 ( V_39 ) ;
}
void F_47 ( struct V_7 * V_8 )
{
T_2 * V_77 , V_32 ;
T_2 V_78 = 0 ;
if ( ! V_8 )
return;
if ( V_8 -> V_67 ) {
F_37 ( NULL ) ;
F_48 ( V_8 -> V_67 ) ;
}
F_43 ( V_8 ) ;
F_49 (image, ptr, entry) {
if ( V_32 & V_70 ) {
if ( V_78 & V_70 )
F_45 ( V_78 ) ;
V_78 = V_32 ;
} else if ( V_32 & V_75 )
F_45 ( V_32 ) ;
}
if ( V_78 & V_70 )
F_45 ( V_78 ) ;
F_50 ( V_8 ) ;
F_24 ( & V_8 -> V_36 ) ;
if ( V_8 -> V_79 )
F_51 ( V_8 ) ;
F_52 ( V_8 ) ;
}
static T_2 * F_53 ( struct V_7 * V_8 ,
unsigned long V_39 )
{
T_2 * V_77 , V_32 ;
unsigned long V_72 = 0 ;
F_49 (image, ptr, entry) {
if ( V_32 & V_74 )
V_72 = V_32 & V_18 ;
else if ( V_32 & V_75 ) {
if ( V_39 == V_72 )
return V_77 ;
V_72 += V_71 ;
}
}
return NULL ;
}
static struct V_39 * F_39 ( struct V_7 * V_8 ,
T_1 V_40 ,
unsigned long V_72 )
{
struct V_39 * V_39 ;
unsigned long V_53 ;
F_54 (page, &image->dest_pages, lru) {
V_53 = F_28 ( V_39 ) << V_56 ;
if ( V_53 == V_72 ) {
F_26 ( & V_39 -> V_49 ) ;
return V_39 ;
}
}
V_39 = NULL ;
while ( 1 ) {
T_2 * V_80 ;
V_39 = F_12 ( V_40 , 0 ) ;
if ( ! V_39 )
return NULL ;
if ( F_28 ( V_39 ) >
( V_81 >> V_56 ) ) {
F_29 ( & V_39 -> V_49 , & V_8 -> V_38 ) ;
continue;
}
V_53 = F_28 ( V_39 ) << V_56 ;
if ( V_53 == V_72 )
break;
if ( ! F_11 ( V_8 , V_53 ,
V_53 + V_71 ) )
break;
V_80 = F_53 ( V_8 , V_53 ) ;
if ( V_80 ) {
unsigned long V_82 ;
struct V_39 * V_83 ;
V_82 = * V_80 & V_18 ;
V_83 = F_46 ( V_82 >> V_56 ) ;
F_55 ( V_39 , V_83 ) ;
* V_80 = V_53 | ( * V_80 & ~ V_18 ) ;
if ( ! ( V_40 & V_84 ) &&
F_56 ( V_83 ) ) {
F_19 ( V_83 ) ;
continue;
}
V_53 = V_82 ;
V_39 = V_83 ;
break;
}
F_29 ( & V_39 -> V_49 , & V_8 -> V_37 ) ;
}
return V_39 ;
}
static int F_57 ( struct V_7 * V_8 ,
struct V_85 * V_14 )
{
unsigned long V_86 ;
T_3 V_87 , V_88 ;
int V_73 ;
unsigned char T_4 * V_89 = NULL ;
unsigned char * V_90 = NULL ;
V_73 = 0 ;
if ( V_8 -> V_79 )
V_90 = V_14 -> V_90 ;
else
V_89 = V_14 -> V_89 ;
V_87 = V_14 -> V_24 ;
V_88 = V_14 -> V_16 ;
V_86 = V_14 -> V_15 ;
V_73 = F_41 ( V_8 , V_86 ) ;
if ( V_73 < 0 )
goto V_91;
while ( V_88 ) {
struct V_39 * V_39 ;
char * V_77 ;
T_3 V_92 , V_93 ;
V_39 = F_39 ( V_8 , V_94 , V_86 ) ;
if ( ! V_39 ) {
V_73 = - V_64 ;
goto V_91;
}
V_73 = F_42 ( V_8 , F_28 ( V_39 )
<< V_56 ) ;
if ( V_73 < 0 )
goto V_91;
V_77 = F_58 ( V_39 ) ;
F_59 ( V_77 ) ;
V_77 += V_86 & ~ V_18 ;
V_93 = F_60 ( T_3 , V_88 ,
V_71 - ( V_86 & ~ V_18 ) ) ;
V_92 = F_61 ( V_87 , V_93 ) ;
if ( V_8 -> V_79 )
memcpy ( V_77 , V_90 , V_92 ) ;
else
V_73 = F_62 ( V_77 , V_89 , V_92 ) ;
F_63 ( V_39 ) ;
if ( V_73 ) {
V_73 = - V_95 ;
goto V_91;
}
V_87 -= V_92 ;
V_86 += V_93 ;
if ( V_8 -> V_79 )
V_90 += V_93 ;
else
V_89 += V_93 ;
V_88 -= V_93 ;
}
V_91:
return V_73 ;
}
static int F_64 ( struct V_7 * V_8 ,
struct V_85 * V_14 )
{
unsigned long V_86 ;
T_3 V_87 , V_88 ;
int V_73 ;
unsigned char T_4 * V_89 = NULL ;
unsigned char * V_90 = NULL ;
V_73 = 0 ;
if ( V_8 -> V_79 )
V_90 = V_14 -> V_90 ;
else
V_89 = V_14 -> V_89 ;
V_87 = V_14 -> V_24 ;
V_88 = V_14 -> V_16 ;
V_86 = V_14 -> V_15 ;
while ( V_88 ) {
struct V_39 * V_39 ;
char * V_77 ;
T_3 V_92 , V_93 ;
V_39 = F_46 ( V_86 >> V_56 ) ;
if ( ! V_39 ) {
V_73 = - V_64 ;
goto V_91;
}
V_77 = F_58 ( V_39 ) ;
V_77 += V_86 & ~ V_18 ;
V_93 = F_60 ( T_3 , V_88 ,
V_71 - ( V_86 & ~ V_18 ) ) ;
V_92 = F_61 ( V_87 , V_93 ) ;
if ( V_93 > V_92 ) {
memset ( V_77 + V_92 , 0 , V_93 - V_92 ) ;
}
if ( V_8 -> V_79 )
memcpy ( V_77 , V_90 , V_92 ) ;
else
V_73 = F_62 ( V_77 , V_89 , V_92 ) ;
F_65 ( V_39 ) ;
F_63 ( V_39 ) ;
if ( V_73 ) {
V_73 = - V_95 ;
goto V_91;
}
V_87 -= V_92 ;
V_86 += V_93 ;
if ( V_8 -> V_79 )
V_90 += V_93 ;
else
V_89 += V_93 ;
V_88 -= V_93 ;
}
V_91:
return V_73 ;
}
int F_66 ( struct V_7 * V_8 ,
struct V_85 * V_14 )
{
int V_73 = - V_64 ;
switch ( V_8 -> type ) {
case V_35 :
V_73 = F_57 ( V_8 , V_14 ) ;
break;
case V_26 :
V_73 = F_64 ( V_8 , V_14 ) ;
break;
}
return V_73 ;
}
void T_5 F_67 ( struct V_96 * V_97 )
{
if ( F_68 ( & V_98 ) ) {
if ( V_6 ) {
struct V_96 V_99 ;
F_69 ( & V_99 , V_97 ) ;
F_70 () ;
F_71 ( & V_99 ) ;
F_72 ( V_6 ) ;
}
F_73 ( & V_98 ) ;
}
}
void F_74 ( struct V_96 * V_97 )
{
int V_100 , V_101 ;
V_101 = F_75 () ;
V_100 = F_76 ( & V_102 , V_103 , V_101 ) ;
if ( V_100 == V_103 ) {
F_77 () ;
F_67 ( V_97 ) ;
F_78 ( & V_102 , V_103 ) ;
}
}
T_3 F_79 ( void )
{
T_3 V_60 = 0 ;
F_80 ( & V_98 ) ;
if ( V_27 . V_29 != V_27 . V_28 )
V_60 = F_81 ( & V_27 ) ;
F_73 ( & V_98 ) ;
return V_60 ;
}
void __weak F_82 ( unsigned long V_104 ,
unsigned long V_29 )
{
unsigned long V_53 ;
for ( V_53 = V_104 ; V_53 < V_29 ; V_53 += V_71 )
F_83 ( F_46 ( V_53 >> V_56 ) ) ;
}
int F_84 ( unsigned long V_105 )
{
int V_106 = 0 ;
unsigned long V_28 , V_29 ;
unsigned long V_107 ;
struct V_108 * V_109 ;
F_80 ( & V_98 ) ;
if ( V_6 ) {
V_106 = - V_110 ;
goto V_111;
}
V_28 = V_27 . V_28 ;
V_29 = V_27 . V_29 ;
V_107 = ( V_29 == 0 ) ? 0 : V_29 - V_28 + 1 ;
if ( V_105 >= V_107 ) {
V_106 = ( V_105 == V_107 ) ? 0 : - V_23 ;
goto V_111;
}
V_109 = F_9 ( sizeof( * V_109 ) , V_30 ) ;
if ( ! V_109 ) {
V_106 = - V_64 ;
goto V_111;
}
V_28 = F_85 ( V_28 , V_112 ) ;
V_29 = F_85 ( V_28 + V_105 , V_112 ) ;
F_82 ( V_29 , V_27 . V_29 ) ;
if ( ( V_28 == V_29 ) && ( V_27 . V_113 != NULL ) )
F_86 ( & V_27 ) ;
V_109 -> V_28 = V_29 ;
V_109 -> V_29 = V_27 . V_29 ;
V_109 -> V_114 = V_115 | V_116 ;
V_109 -> V_117 = L_3 ;
V_27 . V_29 = V_29 - 1 ;
F_87 ( & V_118 , V_109 ) ;
V_111:
F_73 ( & V_98 ) ;
return V_106 ;
}
void F_88 ( struct V_96 * V_97 , int V_119 )
{
struct V_120 V_121 ;
T_6 * V_89 ;
if ( ( V_119 < 0 ) || ( V_119 >= V_122 ) )
return;
V_89 = ( T_6 * ) F_89 ( V_123 , V_119 ) ;
if ( ! V_89 )
return;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_124 = V_125 -> V_4 ;
F_90 ( & V_121 . V_126 , V_97 ) ;
V_89 = F_91 ( V_89 , V_127 , V_128 ,
& V_121 , sizeof( V_121 ) ) ;
F_92 ( V_89 ) ;
}
static int T_7 F_93 ( void )
{
T_3 V_60 , V_129 ;
V_60 = sizeof( V_130 ) ;
V_129 = F_61 ( F_94 ( sizeof( V_130 ) ) , V_71 ) ;
F_95 ( V_60 > V_71 ) ;
V_123 = F_96 ( V_60 , V_129 ) ;
if ( ! V_123 ) {
F_35 ( L_4 ) ;
return - V_64 ;
}
return 0 ;
}
int F_97 ( void )
{
int error = 0 ;
if ( ! F_68 ( & V_98 ) )
return - V_131 ;
if ( ! V_132 ) {
error = - V_23 ;
goto V_133;
}
#ifdef F_98
if ( V_132 -> V_134 ) {
F_99 () ;
F_100 () ;
error = F_101 () ;
if ( error ) {
error = - V_131 ;
goto V_135;
}
F_102 () ;
error = F_103 ( V_136 ) ;
if ( error )
goto V_137;
error = F_104 ( V_136 ) ;
if ( error )
goto V_138;
error = F_105 () ;
if ( error )
goto V_139;
F_106 () ;
error = F_107 () ;
if ( error )
goto V_140;
} else
#endif
{
V_141 = true ;
F_108 ( NULL ) ;
F_109 () ;
F_110 () ;
F_111 ( L_5 ) ;
F_112 () ;
}
F_72 ( V_132 ) ;
#ifdef F_98
if ( V_132 -> V_134 ) {
F_113 () ;
V_140:
F_114 () ;
V_139:
F_115 () ;
F_116 ( V_142 ) ;
V_138:
F_117 ( V_142 ) ;
V_137:
F_118 () ;
F_119 () ;
V_135:
F_120 () ;
F_121 () ;
}
#endif
V_133:
F_73 ( & V_98 ) ;
return error ;
}
void __weak F_122 ( void )
{}
void __weak F_123 ( void )
{}
