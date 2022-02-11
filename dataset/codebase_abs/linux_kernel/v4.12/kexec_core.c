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
static int F_30 ( struct V_7 * V_8 , T_2 V_32 )
{
if ( * V_8 -> V_32 != 0 )
V_8 -> V_32 ++ ;
if ( V_8 -> V_32 == V_8 -> V_33 ) {
T_2 * V_61 ;
struct V_39 * V_39 ;
V_39 = F_31 ( V_8 , V_30 , V_62 ) ;
if ( ! V_39 )
return - V_63 ;
V_61 = F_32 ( V_39 ) ;
* V_8 -> V_32 = F_33 ( V_61 ) | V_64 ;
V_8 -> V_32 = V_61 ;
V_8 -> V_33 = V_61 +
( ( V_65 / sizeof( T_2 ) ) - 1 ) ;
}
* V_8 -> V_32 = V_32 ;
V_8 -> V_32 ++ ;
* V_8 -> V_32 = 0 ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 ,
unsigned long V_66 )
{
int V_67 ;
V_66 &= V_18 ;
V_67 = F_30 ( V_8 , V_66 | V_68 ) ;
return V_67 ;
}
static int F_35 ( struct V_7 * V_8 , unsigned long V_39 )
{
int V_67 ;
V_39 &= V_18 ;
V_67 = F_30 ( V_8 , V_39 | V_69 ) ;
return V_67 ;
}
static void F_36 ( struct V_7 * V_8 )
{
F_20 ( & V_8 -> V_37 ) ;
F_20 ( & V_8 -> V_38 ) ;
}
void F_37 ( struct V_7 * V_8 )
{
if ( * V_8 -> V_32 != 0 )
V_8 -> V_32 ++ ;
* V_8 -> V_32 = V_70 ;
}
static void F_38 ( T_2 V_32 )
{
struct V_39 * V_39 ;
V_39 = F_39 ( V_32 >> V_55 ) ;
F_16 ( V_39 ) ;
}
void F_40 ( struct V_7 * V_8 )
{
T_2 * V_71 , V_32 ;
T_2 V_72 = 0 ;
if ( ! V_8 )
return;
F_36 ( V_8 ) ;
F_41 (image, ptr, entry) {
if ( V_32 & V_64 ) {
if ( V_72 & V_64 )
F_38 ( V_72 ) ;
V_72 = V_32 ;
} else if ( V_32 & V_69 )
F_38 ( V_32 ) ;
}
if ( V_72 & V_64 )
F_38 ( V_72 ) ;
F_42 ( V_8 ) ;
F_20 ( & V_8 -> V_36 ) ;
if ( V_8 -> V_73 )
F_43 ( V_8 ) ;
F_44 ( V_8 ) ;
}
static T_2 * F_45 ( struct V_7 * V_8 ,
unsigned long V_39 )
{
T_2 * V_71 , V_32 ;
unsigned long V_66 = 0 ;
F_41 (image, ptr, entry) {
if ( V_32 & V_68 )
V_66 = V_32 & V_18 ;
else if ( V_32 & V_69 ) {
if ( V_39 == V_66 )
return V_71 ;
V_66 += V_65 ;
}
}
return NULL ;
}
static struct V_39 * F_31 ( struct V_7 * V_8 ,
T_1 V_40 ,
unsigned long V_66 )
{
struct V_39 * V_39 ;
unsigned long V_52 ;
F_46 (page, &image->dest_pages, lru) {
V_52 = F_24 ( V_39 ) << V_55 ;
if ( V_52 == V_66 ) {
F_22 ( & V_39 -> V_48 ) ;
return V_39 ;
}
}
V_39 = NULL ;
while ( 1 ) {
T_2 * V_74 ;
V_39 = F_12 ( V_40 , 0 ) ;
if ( ! V_39 )
return NULL ;
if ( F_24 ( V_39 ) >
( V_75 >> V_55 ) ) {
F_25 ( & V_39 -> V_48 , & V_8 -> V_38 ) ;
continue;
}
V_52 = F_24 ( V_39 ) << V_55 ;
if ( V_52 == V_66 )
break;
if ( ! F_11 ( V_8 , V_52 ,
V_52 + V_65 ) )
break;
V_74 = F_45 ( V_8 , V_52 ) ;
if ( V_74 ) {
unsigned long V_76 ;
struct V_39 * V_77 ;
V_76 = * V_74 & V_18 ;
V_77 = F_39 ( V_76 >> V_55 ) ;
F_47 ( V_39 , V_77 ) ;
* V_74 = V_52 | ( * V_74 & ~ V_18 ) ;
if ( ! ( V_40 & V_78 ) &&
F_48 ( V_77 ) ) {
F_16 ( V_77 ) ;
continue;
}
V_52 = V_76 ;
V_39 = V_77 ;
break;
}
F_25 ( & V_39 -> V_48 , & V_8 -> V_37 ) ;
}
return V_39 ;
}
static int F_49 ( struct V_7 * V_8 ,
struct V_79 * V_14 )
{
unsigned long V_80 ;
T_3 V_81 , V_82 ;
int V_67 ;
unsigned char T_4 * V_83 = NULL ;
unsigned char * V_84 = NULL ;
V_67 = 0 ;
if ( V_8 -> V_73 )
V_84 = V_14 -> V_84 ;
else
V_83 = V_14 -> V_83 ;
V_81 = V_14 -> V_24 ;
V_82 = V_14 -> V_16 ;
V_80 = V_14 -> V_15 ;
V_67 = F_34 ( V_8 , V_80 ) ;
if ( V_67 < 0 )
goto V_85;
while ( V_82 ) {
struct V_39 * V_39 ;
char * V_71 ;
T_3 V_86 , V_87 ;
V_39 = F_31 ( V_8 , V_88 , V_80 ) ;
if ( ! V_39 ) {
V_67 = - V_63 ;
goto V_85;
}
V_67 = F_35 ( V_8 , F_24 ( V_39 )
<< V_55 ) ;
if ( V_67 < 0 )
goto V_85;
V_71 = F_50 ( V_39 ) ;
F_51 ( V_71 ) ;
V_71 += V_80 & ~ V_18 ;
V_87 = F_52 ( T_3 , V_82 ,
V_65 - ( V_80 & ~ V_18 ) ) ;
V_86 = F_53 ( V_81 , V_87 ) ;
if ( V_8 -> V_73 )
memcpy ( V_71 , V_84 , V_86 ) ;
else
V_67 = F_54 ( V_71 , V_83 , V_86 ) ;
F_55 ( V_39 ) ;
if ( V_67 ) {
V_67 = - V_89 ;
goto V_85;
}
V_81 -= V_86 ;
V_80 += V_87 ;
if ( V_8 -> V_73 )
V_84 += V_87 ;
else
V_83 += V_87 ;
V_82 -= V_87 ;
}
V_85:
return V_67 ;
}
static int F_56 ( struct V_7 * V_8 ,
struct V_79 * V_14 )
{
unsigned long V_80 ;
T_3 V_81 , V_82 ;
int V_67 ;
unsigned char T_4 * V_83 = NULL ;
unsigned char * V_84 = NULL ;
V_67 = 0 ;
if ( V_8 -> V_73 )
V_84 = V_14 -> V_84 ;
else
V_83 = V_14 -> V_83 ;
V_81 = V_14 -> V_24 ;
V_82 = V_14 -> V_16 ;
V_80 = V_14 -> V_15 ;
while ( V_82 ) {
struct V_39 * V_39 ;
char * V_71 ;
T_3 V_86 , V_87 ;
V_39 = F_39 ( V_80 >> V_55 ) ;
if ( ! V_39 ) {
V_67 = - V_63 ;
goto V_85;
}
V_71 = F_50 ( V_39 ) ;
V_71 += V_80 & ~ V_18 ;
V_87 = F_52 ( T_3 , V_82 ,
V_65 - ( V_80 & ~ V_18 ) ) ;
V_86 = F_53 ( V_81 , V_87 ) ;
if ( V_87 > V_86 ) {
memset ( V_71 + V_86 , 0 , V_87 - V_86 ) ;
}
if ( V_8 -> V_73 )
memcpy ( V_71 , V_84 , V_86 ) ;
else
V_67 = F_54 ( V_71 , V_83 , V_86 ) ;
F_57 ( V_39 ) ;
F_55 ( V_39 ) ;
if ( V_67 ) {
V_67 = - V_89 ;
goto V_85;
}
V_81 -= V_86 ;
V_80 += V_87 ;
if ( V_8 -> V_73 )
V_84 += V_87 ;
else
V_83 += V_87 ;
V_82 -= V_87 ;
}
V_85:
return V_67 ;
}
int F_58 ( struct V_7 * V_8 ,
struct V_79 * V_14 )
{
int V_67 = - V_63 ;
switch ( V_8 -> type ) {
case V_35 :
V_67 = F_49 ( V_8 , V_14 ) ;
break;
case V_26 :
V_67 = F_56 ( V_8 , V_14 ) ;
break;
}
return V_67 ;
}
void F_59 ( struct V_90 * V_91 )
{
if ( F_60 ( & V_92 ) ) {
if ( V_6 ) {
struct V_90 V_93 ;
F_61 ( & V_93 , V_91 ) ;
F_62 () ;
F_63 ( & V_93 ) ;
F_64 ( V_6 ) ;
}
F_65 ( & V_92 ) ;
}
}
void F_66 ( struct V_90 * V_91 )
{
int V_94 , V_95 ;
V_95 = F_67 () ;
V_94 = F_68 ( & V_96 , V_97 , V_95 ) ;
if ( V_94 == V_97 ) {
F_69 () ;
F_59 ( V_91 ) ;
F_70 ( & V_96 , V_97 ) ;
}
}
T_3 F_71 ( void )
{
T_3 V_59 = 0 ;
F_72 ( & V_92 ) ;
if ( V_27 . V_29 != V_27 . V_28 )
V_59 = F_73 ( & V_27 ) ;
F_65 ( & V_92 ) ;
return V_59 ;
}
void __weak F_74 ( unsigned long V_98 ,
unsigned long V_29 )
{
unsigned long V_52 ;
for ( V_52 = V_98 ; V_52 < V_29 ; V_52 += V_65 )
F_75 ( F_39 ( V_52 >> V_55 ) ) ;
}
int F_76 ( unsigned long V_99 )
{
int V_100 = 0 ;
unsigned long V_28 , V_29 ;
unsigned long V_101 ;
struct V_102 * V_103 ;
F_72 ( & V_92 ) ;
if ( V_6 ) {
V_100 = - V_104 ;
goto V_105;
}
V_28 = V_27 . V_28 ;
V_29 = V_27 . V_29 ;
V_101 = ( V_29 == 0 ) ? 0 : V_29 - V_28 + 1 ;
if ( V_99 >= V_101 ) {
V_100 = ( V_99 == V_101 ) ? 0 : - V_23 ;
goto V_105;
}
V_103 = F_9 ( sizeof( * V_103 ) , V_30 ) ;
if ( ! V_103 ) {
V_100 = - V_63 ;
goto V_105;
}
V_28 = F_77 ( V_28 , V_106 ) ;
V_29 = F_77 ( V_28 + V_99 , V_106 ) ;
F_74 ( V_29 , V_27 . V_29 ) ;
if ( ( V_28 == V_29 ) && ( V_27 . V_107 != NULL ) )
F_78 ( & V_27 ) ;
V_103 -> V_28 = V_29 ;
V_103 -> V_29 = V_27 . V_29 ;
V_103 -> V_108 = V_109 | V_110 ;
V_103 -> V_111 = L_1 ;
V_27 . V_29 = V_29 - 1 ;
F_79 ( & V_112 , V_103 ) ;
V_105:
F_65 ( & V_92 ) ;
return V_100 ;
}
void F_80 ( struct V_90 * V_91 , int V_113 )
{
struct V_114 V_115 ;
T_5 * V_83 ;
if ( ( V_113 < 0 ) || ( V_113 >= V_116 ) )
return;
V_83 = ( T_5 * ) F_81 ( V_117 , V_113 ) ;
if ( ! V_83 )
return;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_115 . V_118 = V_119 -> V_4 ;
F_82 ( & V_115 . V_120 , V_91 ) ;
V_83 = F_83 ( V_83 , V_121 , V_122 ,
& V_115 , sizeof( V_115 ) ) ;
F_84 ( V_83 ) ;
}
static int T_6 F_85 ( void )
{
T_3 V_59 , V_123 ;
V_59 = sizeof( V_124 ) ;
V_123 = F_53 ( F_86 ( sizeof( V_124 ) ) , V_65 ) ;
F_87 ( V_59 > V_65 ) ;
V_117 = F_88 ( V_59 , V_123 ) ;
if ( ! V_117 ) {
F_89 ( L_2 ) ;
return - V_63 ;
}
return 0 ;
}
int F_90 ( void )
{
int error = 0 ;
if ( ! F_60 ( & V_92 ) )
return - V_125 ;
if ( ! V_126 ) {
error = - V_23 ;
goto V_127;
}
#ifdef F_91
if ( V_126 -> V_128 ) {
F_92 () ;
F_93 () ;
error = F_94 () ;
if ( error ) {
error = - V_125 ;
goto V_129;
}
F_95 () ;
error = F_96 ( V_130 ) ;
if ( error )
goto V_131;
error = F_97 ( V_130 ) ;
if ( error )
goto V_132;
error = F_98 () ;
if ( error )
goto V_133;
F_99 () ;
error = F_100 () ;
if ( error )
goto V_134;
} else
#endif
{
V_135 = true ;
F_101 ( NULL ) ;
F_102 () ;
F_103 () ;
F_104 ( L_3 ) ;
F_105 () ;
}
F_64 ( V_126 ) ;
#ifdef F_91
if ( V_126 -> V_128 ) {
F_106 () ;
V_134:
F_107 () ;
V_133:
F_108 () ;
F_109 ( V_136 ) ;
V_132:
F_110 ( V_136 ) ;
V_131:
F_111 () ;
F_112 () ;
V_129:
F_113 () ;
F_114 () ;
}
#endif
V_127:
F_65 ( & V_92 ) ;
return error ;
}
void __weak F_115 ( void )
{}
void __weak F_116 ( void )
{}
