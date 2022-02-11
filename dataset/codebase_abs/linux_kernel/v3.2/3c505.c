static unsigned long F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 ) ;
return F_3 ( V_3 , V_2 ) ;
}
static inline unsigned char F_4 ( unsigned int V_4 )
{
return F_5 ( V_4 + V_5 ) ;
}
static inline int F_6 ( unsigned int V_4 )
{
return F_5 ( V_4 + V_6 ) ;
}
static inline void F_7 ( unsigned char V_7 , struct V_8 * V_9 )
{
F_8 ( V_7 , V_9 -> V_4 + V_10 ) ;
( ( V_11 * ) ( F_9 ( V_9 ) ) ) -> V_12 = V_7 ;
}
static inline void F_10 ( unsigned char V_7 , unsigned int V_4 )
{
F_8 ( V_7 , V_4 + V_6 ) ;
}
static inline unsigned int F_11 ( unsigned int V_13 )
{
return ( V_13 + 1 ) % V_14 ;
}
static inline int F_12 ( unsigned int V_4 )
{
unsigned long V_15 = V_16 + 10 * V_17 / 100 ;
register int V_18 ;
do {
V_18 = F_4 ( V_4 ) ;
} while ( V_18 != F_4 ( V_4 ) && F_13 ( V_16 , V_15 ) );
if ( F_14 ( V_16 , V_15 ) )
F_15 ( __LINE__ ) ;
return V_18 ;
}
static inline void F_16 ( struct V_8 * V_9 , int V_19 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
unsigned long V_21 ;
F_17 ( & V_20 -> V_22 , V_21 ) ;
F_7 ( ( F_18 ( V_9 ) & ~ V_23 ) | V_19 , V_9 ) ;
F_19 ( & V_20 -> V_22 , V_21 ) ;
}
static inline void F_20 ( struct V_8 * V_9 )
{
unsigned long V_15 ;
V_11 * V_20 = F_9 ( V_9 ) ;
unsigned char V_24 = V_20 -> V_12 ;
F_7 ( 0 , V_9 ) ;
if ( F_4 ( V_9 -> V_4 ) & V_25 ) {
do {
F_6 ( V_9 -> V_4 ) ;
V_15 = V_16 + 2 * V_17 / 100 ;
while ( F_21 ( V_16 , V_15 ) && ! ( F_4 ( V_9 -> V_4 ) & V_25 ) ) ;
} while ( F_4 ( V_9 -> V_4 ) & V_25 );
F_16 ( V_9 , V_26 ) ;
}
F_7 ( V_20 -> V_12 | V_27 | V_28 , V_9 ) ;
F_22 ( 10 ) ;
F_7 ( V_20 -> V_12 & ~ V_27 , V_9 ) ;
F_22 ( 10 ) ;
F_7 ( V_20 -> V_12 | V_29 , V_9 ) ;
F_22 ( 10 ) ;
F_7 ( V_20 -> V_12 & ~ V_29 , V_9 ) ;
F_22 ( 10 ) ;
F_7 ( V_24 , V_9 ) ;
if ( ! F_23 ( V_9 , & V_20 -> V_30 ) )
F_24 ( L_1 , V_9 -> V_31 ) ;
}
static inline void F_25 ( struct V_8 * V_9 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
if ( V_20 -> V_32 && F_26 ( V_16 , V_20 -> V_33 . V_34 + 10 ) ) {
unsigned long V_21 , V_35 ;
F_24 ( L_2 , V_9 -> V_31 ,
V_20 -> V_33 . V_36 ? L_3 : L_4 ,
F_27 ( V_9 -> V_37 ) ) ;
F_17 ( & V_20 -> V_22 , V_21 ) ;
V_20 -> V_32 = 0 ;
V_20 -> V_38 = 0 ;
V_35 = F_28 () ;
F_29 ( V_9 -> V_37 ) ;
F_30 ( V_35 ) ;
if ( V_20 -> V_39 )
V_20 -> V_39 -- ;
F_7 ( V_20 -> V_12 & ~ ( V_40 | V_41 | V_28 ) , V_9 ) ;
F_19 ( & V_20 -> V_22 , V_21 ) ;
}
}
static inline bool F_31 ( unsigned int V_4 , unsigned char V_42 )
{
unsigned long V_15 ;
F_10 ( V_42 , V_4 ) ;
for ( V_15 = V_16 + 5 * V_17 / 100 ; F_13 ( V_16 , V_15 ) ; ) {
if ( F_4 ( V_4 ) & V_43 )
return false ;
}
F_32 ( L_5 ) ;
return true ;
}
static inline bool F_33 ( unsigned int V_4 , unsigned char V_42 )
{
unsigned int V_15 ;
F_10 ( V_42 , V_4 ) ;
for ( V_15 = 0 ; V_15 < 40000 ; V_15 ++ ) {
if ( F_4 ( V_4 ) & V_43 )
return false ;
}
F_32 ( L_6 ) ;
return true ;
}
static inline void F_34 ( struct V_8 * V_9 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
while ( V_20 -> V_39 < V_44 && F_35 ( V_9 ) ) {
if ( ! F_23 ( V_9 , & V_20 -> V_45 ) )
break;
}
}
static bool F_36 ( struct V_8 * V_9 , T_1 * V_46 )
{
int V_47 ;
unsigned long V_15 ;
V_11 * V_20 = F_9 ( V_9 ) ;
unsigned long V_21 ;
F_25 ( V_9 ) ;
if ( V_20 -> V_32 && V_20 -> V_33 . V_36 == 0 )
return false ;
if ( F_37 ( 1 , & V_20 -> V_48 ) ) {
if ( V_49 >= 3 ) {
F_38 ( L_7 , V_9 -> V_31 ) ;
}
return false ;
}
F_16 ( V_9 , 0 ) ;
if ( F_31 ( V_9 -> V_4 , V_46 -> V_50 ) )
goto abort;
F_17 ( & V_20 -> V_22 , V_21 ) ;
if ( F_33 ( V_9 -> V_4 , V_46 -> V_51 ) )
goto V_52;
for ( V_47 = 0 ; V_47 < V_46 -> V_51 ; V_47 ++ ) {
if ( F_33 ( V_9 -> V_4 , V_46 -> V_53 . V_54 [ V_47 ] ) )
goto V_52;
}
F_7 ( V_20 -> V_12 | 3 , V_9 ) ;
F_10 ( 2 + V_46 -> V_51 , V_9 -> V_4 ) ;
F_19 ( & V_20 -> V_22 , V_21 ) ;
for ( V_15 = V_16 + 5 * V_17 / 100 ; F_13 ( V_16 , V_15 ) ; ) {
switch ( F_39 ( V_9 -> V_4 ) ) {
case V_55 :
V_20 -> V_48 = 0 ;
return true ;
case V_56 :
#ifdef F_40
F_38 ( L_8 , V_9 -> V_31 ) ;
#endif
goto abort;
}
}
if ( V_49 >= 1 )
F_38 ( L_9 ,
V_9 -> V_31 , F_4 ( V_9 -> V_4 ) ) ;
goto abort;
V_52:
F_19 ( & V_20 -> V_22 , V_21 ) ;
abort:
V_20 -> V_48 = 0 ;
return false ;
}
static bool F_41 ( struct V_8 * V_9 , T_1 * V_46 )
{
int V_47 , V_57 ;
int V_58 ;
int V_59 ;
unsigned long V_15 ;
unsigned long V_21 ;
V_11 * V_20 = F_9 ( V_9 ) ;
F_16 ( V_9 , 0 ) ;
V_15 = V_16 + 2 * V_17 / 100 ;
while ( ( ( V_59 = F_12 ( V_9 -> V_4 ) ) & V_25 ) == 0 && F_13 ( V_16 , V_15 ) ) ;
if ( F_14 ( V_16 , V_15 ) ) {
F_15 ( __LINE__ ) ;
return false ;
}
V_46 -> V_50 = F_6 ( V_9 -> V_4 ) ;
V_15 = V_16 + 3 * V_17 / 100 ;
while ( ( ( V_59 = F_12 ( V_9 -> V_4 ) ) & V_25 ) == 0 && F_13 ( V_16 , V_15 ) ) ;
if ( F_14 ( V_16 , V_15 ) ) {
F_15 ( __LINE__ ) ;
F_42 ( L_10 , V_9 -> V_31 , V_59 ) ;
return false ;
}
V_46 -> V_51 = F_6 ( V_9 -> V_4 ) ;
if ( V_46 -> V_51 > V_60 ) {
F_43 ( V_46 -> V_51 ) ;
F_20 ( V_9 ) ;
return false ;
}
F_17 ( & V_20 -> V_22 , V_21 ) ;
for ( V_47 = 0 ; V_47 < V_60 ; V_47 ++ ) {
for ( V_57 = 0 ; V_57 < 20000 ; V_57 ++ ) {
V_59 = F_12 ( V_9 -> V_4 ) ;
if ( V_59 & V_25 )
break;
}
V_46 -> V_53 . V_54 [ V_47 ] = F_6 ( V_9 -> V_4 ) ;
if ( ( V_59 & V_61 ) == V_62 || V_57 >= 20000 )
break;
}
F_19 ( & V_20 -> V_22 , V_21 ) ;
if ( V_47 >= V_60 ) {
F_43 ( V_47 ) ;
return false ;
}
if ( V_57 >= 20000 ) {
F_15 ( __LINE__ ) ;
return false ;
}
V_58 = V_46 -> V_53 . V_54 [ V_47 ] ;
if ( V_58 != ( V_46 -> V_51 + 2 ) ) {
if ( V_49 >= 2 )
F_32 ( L_11 , V_9 -> V_31 ) ;
F_16 ( V_9 , V_26 ) ;
return false ;
}
if ( V_46 -> V_50 == V_63 ) {
if ( F_37 ( 0 , ( void * ) & V_20 -> V_38 ) ) {
if ( F_11 ( V_20 -> V_64 . V_65 ) == V_20 -> V_64 . V_66 ) {
F_16 ( V_9 , V_26 ) ;
F_32 ( L_12 , V_9 -> V_31 ) ;
V_46 -> V_50 = 0 ;
return true ;
} else {
V_46 -> V_50 = 0xff ;
}
}
}
F_16 ( V_9 , V_67 ) ;
return true ;
}
static bool F_23 ( struct V_8 * V_9 , T_1 * V_30 )
{
bool V_68 ;
V_11 * V_20 = F_9 ( V_9 ) ;
if ( V_49 >= 3 )
F_38 ( L_13 , V_9 -> V_31 ) ;
V_30 -> V_50 = V_69 ;
V_30 -> V_51 = sizeof( struct V_70 ) ;
V_30 -> V_53 . V_71 . V_72
= V_30 -> V_53 . V_71 . V_73 = 0 ;
V_30 -> V_53 . V_71 . V_74 = 1600 ;
V_30 -> V_53 . V_71 . V_15 = 0 ;
V_68 = F_36 ( V_9 , V_30 ) ;
if ( V_68 )
V_20 -> V_39 ++ ;
return V_68 ;
}
static void F_44 ( struct V_8 * V_9 , int V_75 )
{
int V_76 ;
V_11 * V_20 = F_9 ( V_9 ) ;
void * V_77 ;
struct V_78 * V_79 ;
unsigned long V_21 ;
V_76 = ( V_75 + 1 ) & ~ 1 ;
V_79 = F_45 ( V_76 + 2 ) ;
if ( ! V_79 ) {
F_32 ( L_14 , V_9 -> V_31 ) ;
V_77 = V_20 -> V_80 ;
V_20 -> V_33 . V_77 = NULL ;
return;
}
F_46 ( V_79 , 2 ) ;
V_77 = F_47 ( V_79 , V_76 ) ;
if ( ( unsigned long ) ( V_77 + V_76 ) >= V_81 ) {
V_20 -> V_33 . V_77 = V_77 ;
V_77 = V_20 -> V_80 ;
} else {
V_20 -> V_33 . V_77 = NULL ;
}
if ( F_37 ( 0 , ( void * ) & V_20 -> V_32 ) )
F_24 ( L_15 ,
V_9 -> V_31 , V_20 -> V_33 . V_36 ) ;
V_20 -> V_33 . V_36 = 0 ;
V_20 -> V_33 . V_51 = V_76 ;
V_20 -> V_33 . V_79 = V_79 ;
V_20 -> V_33 . V_34 = V_16 ;
F_7 ( V_20 -> V_12 | V_28 | V_41 | V_40 , V_9 ) ;
V_21 = F_28 () ;
F_29 ( V_9 -> V_37 ) ;
F_48 ( V_9 -> V_37 ) ;
F_49 ( V_9 -> V_37 , 0x04 ) ;
F_50 ( V_9 -> V_37 , F_51 ( V_77 ) ) ;
F_52 ( V_9 -> V_37 , V_76 ) ;
F_53 ( V_9 -> V_37 ) ;
F_30 ( V_21 ) ;
if ( V_49 >= 3 ) {
F_38 ( L_16 , V_9 -> V_31 ) ;
}
if ( V_20 -> V_39 )
V_20 -> V_39 -- ;
if ( ! V_20 -> V_38 )
F_32 ( L_17 , V_9 -> V_31 ) ;
}
static T_2 F_54 ( int V_82 , void * V_83 )
{
int V_75 ;
int V_84 ;
int V_85 = 0 ;
struct V_8 * V_9 = V_83 ;
V_11 * V_20 = F_9 ( V_9 ) ;
unsigned long V_15 ;
F_55 ( & V_20 -> V_22 ) ;
do {
if ( F_4 ( V_9 -> V_4 ) & V_86 ) {
if ( ! V_20 -> V_32 )
F_32 ( L_18 , V_9 -> V_31 ) ;
if ( V_49 >= 3 )
F_38 ( L_19 , V_9 -> V_31 ,
V_20 -> V_33 . V_36 ? L_20 : L_21 ,
F_4 ( V_9 -> V_4 ) ) ;
F_7 ( V_20 -> V_12 & ~ ( V_40 | V_41 | V_28 ) , V_9 ) ;
if ( V_20 -> V_33 . V_36 ) {
F_56 ( V_20 -> V_33 . V_79 ) ;
} else {
struct V_78 * V_79 = V_20 -> V_33 . V_79 ;
if ( V_79 ) {
if ( V_20 -> V_33 . V_77 ) {
memcpy ( V_20 -> V_33 . V_77 , V_20 -> V_80 , V_20 -> V_33 . V_51 ) ;
}
V_79 -> V_87 = F_57 ( V_79 , V_9 ) ;
V_9 -> V_88 . V_89 += V_79 -> V_75 ;
F_58 ( V_79 ) ;
}
}
V_20 -> V_32 = 0 ;
if ( V_20 -> V_64 . V_65 != V_20 -> V_64 . V_66 ) {
int V_90 = V_20 -> V_64 . V_51 [ V_20 -> V_64 . V_66 ] ;
V_20 -> V_64 . V_66 = F_11 ( V_20 -> V_64 . V_66 ) ;
if ( V_49 >= 2 )
F_38 ( L_22 , V_9 -> V_31 , V_90 ) ;
F_44 ( V_9 , V_90 ) ;
} else {
V_20 -> V_38 = 0 ;
}
} else {
F_25 ( V_9 ) ;
}
V_15 = V_16 + 3 * V_17 / 100 ;
while ( ( F_4 ( V_9 -> V_4 ) & V_25 ) != 0 && F_13 ( V_16 , V_15 ) ) {
if ( F_41 ( V_9 , & V_20 -> V_91 ) ) {
switch ( V_20 -> V_91 . V_50 )
{
case 0 :
break;
case 0xff :
case V_63 :
if ( ! F_35 ( V_9 ) )
break;
V_75 = V_20 -> V_91 . V_53 . V_92 . V_93 ;
V_84 = V_20 -> V_91 . V_53 . V_92 . V_74 ;
if ( V_20 -> V_91 . V_53 . V_92 . V_15 != 0 ) {
F_24 ( L_23 , V_9 -> V_31 ) ;
} else {
if ( V_49 >= 3 ) {
F_38 ( L_24 ,
V_9 -> V_31 , V_75 , V_84 ) ;
}
if ( V_20 -> V_91 . V_50 == 0xff ) {
if ( V_49 >= 2 )
F_38 ( L_25 ,
V_9 -> V_31 , V_84 ) ;
V_20 -> V_64 . V_51 [ V_20 -> V_64 . V_65 ] = V_84 ;
V_20 -> V_64 . V_65 = F_11 ( V_20 -> V_64 . V_65 ) ;
} else {
F_44 ( V_9 , V_84 ) ;
}
if ( V_49 >= 3 )
F_38 ( L_26 , V_9 -> V_31 ) ;
}
break;
case V_94 :
V_20 -> V_95 [ V_96 ] = 1 ;
if ( V_49 >= 3 )
F_38 ( L_27 , V_9 -> V_31 ) ;
break;
case V_97 :
V_20 -> V_95 [ V_98 ] = 1 ;
if ( V_49 >= 3 )
F_38 ( L_28 , V_9 -> V_31 ,
V_20 -> V_91 . V_53 . V_99 ? L_29 : L_30 ) ;
break;
case V_100 :
V_20 -> V_95 [ V_101 ] = 1 ;
if ( V_49 >= 3 )
F_38 ( L_31 , V_9 -> V_31 ,
V_20 -> V_91 . V_53 . V_99 ? L_29 : L_30 ) ;
break;
case V_102 :
V_20 -> V_95 [ V_103 ] = 1 ;
if ( V_49 >= 3 )
F_38 ( L_32 , V_9 -> V_31 ,
V_20 -> V_91 . V_53 . V_99 ? L_29 : L_30 ) ;
break;
case V_104 :
V_9 -> V_88 . V_105 += V_20 -> V_91 . V_53 . V_106 . V_107 ;
V_9 -> V_88 . V_108 += V_20 -> V_91 . V_53 . V_106 . V_109 ;
V_9 -> V_88 . V_110 += V_20 -> V_91 . V_53 . V_106 . V_111 ;
V_9 -> V_88 . V_112 += V_20 -> V_91 . V_53 . V_106 . V_113 ;
V_9 -> V_88 . V_114 += V_20 -> V_91 . V_53 . V_106 . V_115 ;
V_9 -> V_88 . V_116 += V_20 -> V_91 . V_53 . V_106 . V_117 ;
V_20 -> V_95 [ V_118 ] = 1 ;
if ( V_49 >= 3 )
F_38 ( L_33 , V_9 -> V_31 ) ;
break;
case V_119 :
if ( V_49 >= 3 )
F_38 ( L_34 , V_9 -> V_31 ) ;
if ( ! F_35 ( V_9 ) )
break;
switch ( V_20 -> V_91 . V_53 . V_120 . V_121 ) {
case 0xffff :
V_9 -> V_88 . V_122 ++ ;
F_42 ( L_35 , V_9 -> V_31 ) ;
break;
case 0xfffe :
V_9 -> V_88 . V_123 ++ ;
F_42 ( L_36 , V_9 -> V_31 ) ;
break;
}
F_59 ( V_9 ) ;
break;
default:
F_38 ( L_37 ,
V_9 -> V_31 , V_20 -> V_91 . V_50 ) ;
break;
}
} else {
F_32 ( L_38 , V_9 -> V_31 ) ;
F_20 ( V_9 ) ;
}
}
} while ( V_85 ++ < 5 && ( F_4 ( V_9 -> V_4 ) & ( V_25 | V_86 ) ) );
F_34 ( V_9 ) ;
F_60 ( & V_20 -> V_22 ) ;
return V_124 ;
}
static int F_61 ( struct V_8 * V_9 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
int V_125 ;
if ( V_49 >= 3 )
F_38 ( L_39 , V_9 -> V_31 ) ;
if ( V_20 == NULL ) {
F_24 ( L_40 , V_9 -> V_31 ) ;
return - V_126 ;
}
F_7 ( 0 , V_9 ) ;
F_6 ( V_9 -> V_4 ) ;
F_20 ( V_9 ) ;
V_20 -> V_39 = 0 ;
V_20 -> V_38 = 0 ;
V_20 -> V_48 = 0 ;
V_20 -> V_64 . V_65 = 0 ;
V_20 -> V_64 . V_66 = 0 ;
F_62 ( & V_20 -> V_22 ) ;
if ( ( V_125 = F_63 ( V_9 -> V_82 , F_54 , 0 , V_9 -> V_31 , V_9 ) ) ) {
F_24 ( L_41 , V_9 -> V_31 , V_9 -> V_82 ) ;
return V_125 ;
}
if ( ( V_125 = F_64 ( V_9 -> V_37 , V_9 -> V_31 ) ) ) {
F_65 ( V_9 -> V_82 , V_9 ) ;
F_24 ( L_42 , V_9 -> V_31 , V_9 -> V_37 ) ;
return V_125 ;
}
V_20 -> V_80 = ( void * ) F_1 ( V_127 ) ;
if ( ! V_20 -> V_80 ) {
F_24 ( L_43 , V_9 -> V_31 ) ;
F_66 ( V_9 -> V_37 ) ;
F_65 ( V_9 -> V_82 , V_9 ) ;
return - V_128 ;
}
V_20 -> V_32 = 0 ;
F_7 ( V_129 , V_9 ) ;
if ( V_49 >= 3 )
F_38 ( L_44 , V_9 -> V_31 ) ;
V_20 -> V_30 . V_50 = V_98 ;
V_20 -> V_30 . V_53 . V_130 . V_131 = 10 ;
V_20 -> V_30 . V_53 . V_130 . V_132 = 20 ;
V_20 -> V_30 . V_53 . V_130 . V_133 = 10 ;
V_20 -> V_30 . V_53 . V_130 . V_134 = 20 ;
V_20 -> V_30 . V_53 . V_130 . V_135 = 20 ;
V_20 -> V_30 . V_53 . V_130 . V_136 = 0 ;
V_20 -> V_30 . V_51 = sizeof( struct V_137 ) ;
V_20 -> V_95 [ V_98 ] = 0 ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) )
F_24 ( L_45 , V_9 -> V_31 ) ;
else {
unsigned long V_15 = V_16 + V_138 ;
while ( V_20 -> V_95 [ V_98 ] == 0 && F_13 ( V_16 , V_15 ) ) ;
if ( F_14 ( V_16 , V_15 ) )
F_15 ( __LINE__ ) ;
}
if ( V_49 >= 3 )
F_38 ( L_46 , V_9 -> V_31 ) ;
V_20 -> V_30 . V_50 = V_96 ;
V_20 -> V_30 . V_53 . V_139 = V_140 | V_141 ;
V_20 -> V_30 . V_51 = 2 ;
V_20 -> V_95 [ V_96 ] = 0 ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) )
F_24 ( L_47 , V_9 -> V_31 ) ;
else {
unsigned long V_15 = V_16 + V_138 ;
while ( V_20 -> V_95 [ V_96 ] == 0 && F_13 ( V_16 , V_15 ) ) ;
if ( F_14 ( V_16 , V_15 ) )
F_15 ( __LINE__ ) ;
}
F_34 ( V_9 ) ;
if ( V_49 >= 3 )
F_38 ( L_48 , V_9 -> V_31 , V_20 -> V_39 ) ;
F_67 ( V_9 ) ;
return 0 ;
}
static T_3 F_68 ( struct V_8 * V_9 , struct V_78 * V_79 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
unsigned long V_77 ;
unsigned long V_21 ;
unsigned int V_142 = ( ( ( V_79 -> V_75 < 60 ) ? 60 : V_79 -> V_75 ) + 1 ) & ( ~ 1 ) ;
if ( F_37 ( 0 , ( void * ) & V_20 -> V_38 ) ) {
if ( V_49 >= 2 )
F_38 ( L_49 , V_9 -> V_31 ) ;
return false ;
}
V_9 -> V_88 . V_143 += V_142 ;
V_20 -> V_30 . V_50 = V_144 ;
V_20 -> V_30 . V_51 = sizeof( struct V_145 ) ;
V_20 -> V_30 . V_53 . V_146 . V_73
= V_20 -> V_30 . V_53 . V_146 . V_72 = 0 ;
V_20 -> V_30 . V_53 . V_146 . V_93 = V_142 ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) ) {
V_20 -> V_38 = 0 ;
return false ;
}
if ( F_37 ( 0 , ( void * ) & V_20 -> V_32 ) )
F_38 ( L_50 , V_9 -> V_31 , V_20 -> V_33 . V_36 ) ;
V_20 -> V_33 . V_36 = 1 ;
V_20 -> V_33 . V_34 = V_16 ;
if ( ( unsigned long ) ( V_79 -> V_53 + V_142 ) >= V_81 || V_142 != V_79 -> V_75 ) {
F_69 ( V_79 , V_20 -> V_80 , V_142 ) ;
memset ( V_20 -> V_80 + V_79 -> V_75 , 0 , V_142 - V_79 -> V_75 ) ;
V_77 = F_51 ( V_20 -> V_80 ) ;
}
else {
V_77 = F_51 ( V_79 -> V_53 ) ;
}
V_20 -> V_33 . V_79 = V_79 ;
V_21 = F_28 () ;
F_29 ( V_9 -> V_37 ) ;
F_48 ( V_9 -> V_37 ) ;
F_49 ( V_9 -> V_37 , 0x48 ) ;
F_50 ( V_9 -> V_37 , V_77 ) ;
F_52 ( V_9 -> V_37 , V_142 ) ;
F_7 ( V_20 -> V_12 | V_40 | V_41 , V_9 ) ;
F_53 ( V_9 -> V_37 ) ;
F_30 ( V_21 ) ;
if ( V_49 >= 3 )
F_38 ( L_51 , V_9 -> V_31 ) ;
return true ;
}
static void F_70 ( struct V_8 * V_9 )
{
int V_59 ;
V_59 = F_4 ( V_9 -> V_4 ) ;
F_32 ( L_52 , V_9 -> V_31 ,
( V_59 & V_25 ) ? L_53 : L_54 ) ;
if ( V_49 >= 1 )
F_38 ( L_55 , V_9 -> V_31 , V_59 ) ;
V_9 -> V_147 = V_16 ;
V_9 -> V_88 . V_148 ++ ;
F_59 ( V_9 ) ;
}
static T_3 F_71 ( struct V_78 * V_79 , struct V_8 * V_9 )
{
unsigned long V_21 ;
V_11 * V_20 = F_9 ( V_9 ) ;
F_17 ( & V_20 -> V_22 , V_21 ) ;
F_25 ( V_9 ) ;
if ( V_49 >= 3 )
F_38 ( L_56 , V_9 -> V_31 , ( int ) V_79 -> V_75 ) ;
F_72 ( V_9 ) ;
if ( ! F_68 ( V_9 , V_79 ) ) {
if ( V_49 >= 2 ) {
F_38 ( L_57 , V_9 -> V_31 ) ;
}
F_19 ( & V_20 -> V_22 , V_21 ) ;
return V_149 ;
}
if ( V_49 >= 3 )
F_38 ( L_58 , V_9 -> V_31 , ( int ) V_79 -> V_75 ) ;
F_34 ( V_9 ) ;
F_19 ( & V_20 -> V_22 , V_21 ) ;
F_67 ( V_9 ) ;
return V_150 ;
}
static struct V_151 * F_73 ( struct V_8 * V_9 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
if ( V_49 >= 3 )
F_38 ( L_59 , V_9 -> V_31 ) ;
if ( ! F_35 ( V_9 ) )
return & V_9 -> V_88 ;
V_20 -> V_30 . V_50 = V_118 ;
V_20 -> V_30 . V_51 = 0 ;
V_20 -> V_95 [ V_118 ] = 0 ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) )
F_24 ( L_60 , V_9 -> V_31 ) ;
else {
unsigned long V_15 = V_16 + V_138 ;
while ( V_20 -> V_95 [ V_118 ] == 0 && F_13 ( V_16 , V_15 ) ) ;
if ( F_14 ( V_16 , V_15 ) ) {
F_15 ( __LINE__ ) ;
return & V_9 -> V_88 ;
}
}
return & V_9 -> V_88 ;
}
static void F_74 ( struct V_8 * V_9 ,
struct V_152 * V_153 )
{
strcpy ( V_153 -> V_154 , V_155 ) ;
strcpy ( V_153 -> V_156 , V_157 ) ;
sprintf ( V_153 -> V_158 , L_61 , V_9 -> V_4 ) ;
}
static T_4 F_75 ( struct V_8 * V_9 )
{
return V_159 ;
}
static void F_76 ( struct V_8 * V_9 , T_4 V_160 )
{
V_159 = V_160 ;
}
static int F_77 ( struct V_8 * V_9 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
if ( V_49 >= 3 )
F_38 ( L_62 , V_9 -> V_31 ) ;
F_72 ( V_9 ) ;
( void ) F_73 ( V_9 ) ;
F_7 ( 0 , V_9 ) ;
F_65 ( V_9 -> V_82 , V_9 ) ;
F_66 ( V_9 -> V_37 ) ;
F_78 ( ( unsigned long ) V_20 -> V_80 , F_2 ( V_127 ) ) ;
return 0 ;
}
static void F_79 ( struct V_8 * V_9 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
struct V_161 * V_162 ;
int V_47 ;
unsigned long V_21 ;
if ( V_49 >= 3 )
F_38 ( L_63 , V_9 -> V_31 ) ;
F_17 ( & V_20 -> V_22 , V_21 ) ;
if ( ! ( V_9 -> V_21 & ( V_163 | V_164 ) ) ) {
V_20 -> V_30 . V_50 = V_101 ;
V_20 -> V_30 . V_51 = 6 * F_80 ( V_9 ) ;
V_47 = 0 ;
F_81 (ha, dev)
memcpy ( V_20 -> V_30 . V_53 . V_165 [ V_47 ++ ] ,
V_162 -> V_166 , 6 ) ;
V_20 -> V_95 [ V_101 ] = 0 ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) )
F_24 ( L_64 , V_9 -> V_31 ) ;
else {
unsigned long V_15 = V_16 + V_138 ;
while ( V_20 -> V_95 [ V_101 ] == 0 && F_13 ( V_16 , V_15 ) ) ;
if ( F_14 ( V_16 , V_15 ) ) {
F_15 ( __LINE__ ) ;
}
}
if ( ! F_82 ( V_9 ) )
V_20 -> V_30 . V_53 . V_139 = V_140 | V_141 | V_167 ;
else
V_20 -> V_30 . V_53 . V_139 = V_140 | V_141 ;
} else
V_20 -> V_30 . V_53 . V_139 = V_140 | V_168 ;
if ( V_49 >= 3 )
F_38 ( L_46 , V_9 -> V_31 ) ;
V_20 -> V_30 . V_50 = V_96 ;
V_20 -> V_30 . V_51 = 2 ;
V_20 -> V_95 [ V_96 ] = 0 ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) )
{
F_19 ( & V_20 -> V_22 , V_21 ) ;
F_24 ( L_47 , V_9 -> V_31 ) ;
}
else {
unsigned long V_15 = V_16 + V_138 ;
F_19 ( & V_20 -> V_22 , V_21 ) ;
while ( V_20 -> V_95 [ V_96 ] == 0 && F_13 ( V_16 , V_15 ) ) ;
if ( F_14 ( V_16 , V_15 ) )
F_15 ( __LINE__ ) ;
}
}
static int T_5 F_83 ( struct V_8 * V_9 )
{
int V_166 = V_9 -> V_4 ;
const char * V_31 = V_9 -> V_31 ;
V_42 V_169 ;
if ( ! F_84 ( V_166 , V_170 , L_65 ) )
return - V_171 ;
V_169 = F_4 ( V_166 ) ;
if ( V_49 > 0 )
F_38 ( V_172 , V_31 , V_166 ) ;
if ( V_169 == 0xff ) {
if ( V_49 > 0 )
F_85 ( V_173 , 1 ) ;
goto V_66;
}
if ( V_49 > 0 )
F_85 ( V_174 ) ;
if ( V_169 & V_28 ) {
F_8 ( 0 , V_9 -> V_4 + V_10 ) ;
F_86 ( 300 ) ;
if ( F_4 ( V_166 ) & V_28 ) {
if ( V_49 > 0 )
F_85 ( V_173 , 2 ) ;
goto V_66;
}
} else {
F_8 ( V_28 , V_9 -> V_4 + V_10 ) ;
F_86 ( 300 ) ;
if ( ! ( F_4 ( V_166 ) & V_28 ) ) {
if ( V_49 > 0 )
F_85 ( V_173 , 3 ) ;
goto V_66;
}
}
if ( V_49 > 0 )
F_85 ( V_175 ) ;
return 0 ;
V_66:
F_87 ( V_166 , V_170 ) ;
return - V_171 ;
}
static int T_5 F_88 ( struct V_8 * V_9 )
{
int V_176 = 0 ;
if ( V_9 -> V_4 != 0 ) {
if ( F_83 ( V_9 ) == 0 )
return V_9 -> V_4 ;
} else
while ( ( V_9 -> V_4 = V_177 [ V_176 ++ ] ) ) {
if ( F_83 ( V_9 ) == 0 )
return V_9 -> V_4 ;
}
if ( V_49 > 0 )
F_38 ( V_178 , V_9 -> V_31 ) ;
return 0 ;
}
static int T_5 F_89 ( struct V_8 * V_9 )
{
V_11 * V_20 = F_9 ( V_9 ) ;
int V_47 , V_179 , V_180 , V_181 ;
unsigned long V_15 ;
unsigned long V_182 = 0 ;
int V_183 = - V_171 ;
V_9 -> V_4 = F_88 ( V_9 ) ;
if ( ! V_9 -> V_4 )
return - V_171 ;
V_20 -> V_48 = 0 ;
for ( V_180 = 0 ; V_180 < 3 ; V_180 ++ ) {
F_7 ( ( V_20 -> V_12 | V_129 ) & ~ V_28 , V_9 ) ;
V_15 = V_16 + 5 * V_17 / 100 ;
V_181 = 0 ;
while ( F_13 ( V_16 , V_15 ) && ! ( F_4 ( V_9 -> V_4 ) & V_43 ) ) ;
if ( ( F_4 ( V_9 -> V_4 ) & V_43 ) ) {
F_10 ( 0 , V_9 -> V_4 ) ;
V_15 = V_16 + 5 * V_17 / 100 ;
while ( F_13 ( V_16 , V_15 ) && ! ( F_4 ( V_9 -> V_4 ) & V_43 ) ) ;
if ( F_4 ( V_9 -> V_4 ) & V_43 )
V_181 = 1 ;
}
if ( ! V_181 ) {
F_24 ( L_66 , V_9 -> V_31 ) ;
if ( ( F_4 ( V_9 -> V_4 ) & 7 ) == 3 ) {
F_85 ( L_67 ) ;
V_15 = V_16 + 10 * V_17 ;
while ( F_13 ( V_16 , V_15 ) && ( F_4 ( V_9 -> V_4 ) & 7 ) ) ;
if ( F_4 ( V_9 -> V_4 ) & 7 ) {
F_24 ( L_68 , V_9 -> V_31 ) ;
} else {
V_181 = 1 ;
}
} else {
F_85 ( L_69 ) ;
}
}
for ( V_179 = 0 ; V_179 < 5 && V_181 ; V_179 ++ ) {
V_20 -> V_30 . V_50 = V_184 ;
V_20 -> V_30 . V_51 = 0 ;
V_182 = F_90 () ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) ) {
F_24 ( L_70 , V_9 -> V_31 ) ;
F_91 ( V_182 ) ;
continue;
}
if ( ! F_41 ( V_9 , & V_20 -> V_185 ) ) {
F_24 ( L_71 , V_9 -> V_31 ) ;
F_91 ( V_182 ) ;
continue;
}
if ( ( V_20 -> V_185 . V_50 != V_186 ) ||
( V_20 -> V_185 . V_51 != 6 ) ) {
F_24 ( L_72 , V_9 -> V_31 ,
V_20 -> V_185 . V_50 , V_20 -> V_185 . V_51 ) ;
F_91 ( V_182 ) ;
continue;
}
goto V_181;
}
F_42 ( L_73 , V_9 -> V_31 ) ;
F_7 ( V_20 -> V_12 | V_29 | V_27 , V_9 ) ;
F_7 ( V_20 -> V_12 & ~ ( V_29 | V_27 ) , V_9 ) ;
}
F_24 ( L_74 , V_9 -> V_31 ) ;
goto V_66;
V_181:
if ( V_9 -> V_82 ) {
int V_187 = F_91 ( V_182 ) ;
if ( V_9 -> V_82 != V_187 ) {
F_32 ( L_75 , V_9 -> V_31 , V_9 -> V_82 , V_187 ) ;
}
} else
V_9 -> V_82 = F_91 ( V_182 ) ;
switch ( V_9 -> V_82 ) {
case 0 :
F_24 ( L_76 ,
V_9 -> V_31 ) ;
goto V_66;
case 1 :
case 6 :
case 8 :
case 13 :
F_24 ( L_77 ,
V_9 -> V_31 , V_9 -> V_82 ) ;
goto V_66;
}
F_7 ( V_20 -> V_12 & ~ V_129 , V_9 ) ;
for ( V_47 = 0 ; V_47 < 6 ; V_47 ++ )
V_9 -> V_188 [ V_47 ] = V_20 -> V_185 . V_53 . V_189 [ V_47 ] ;
if ( ! V_9 -> V_37 ) {
if ( V_9 -> V_190 ) {
V_9 -> V_37 = V_9 -> V_190 & 7 ;
}
else {
F_32 ( L_78 , V_9 -> V_31 ) ;
V_9 -> V_37 = V_191 ;
}
}
F_42 ( L_79 ,
V_9 -> V_31 , V_9 -> V_4 , V_9 -> V_82 , V_9 -> V_37 , V_9 -> V_188 ) ;
V_20 -> V_30 . V_50 = V_192 ;
V_20 -> V_30 . V_51 = 0 ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) ||
! F_41 ( V_9 , & V_20 -> V_185 ) ||
( V_20 -> V_185 . V_50 != V_193 ) ||
( V_20 -> V_185 . V_51 != 10 ) ) {
F_85 ( L_80 ) ;
}
F_85 ( L_81 , V_20 -> V_185 . V_53 . V_153 . V_194 ,
V_20 -> V_185 . V_53 . V_153 . V_195 , V_20 -> V_185 . V_53 . V_153 . V_196 ) ;
V_20 -> V_30 . V_50 = V_98 ;
V_20 -> V_30 . V_51 = 12 ;
V_20 -> V_30 . V_53 . V_130 . V_131 = 8 ;
V_20 -> V_30 . V_53 . V_130 . V_132 = 8 ;
V_20 -> V_30 . V_53 . V_130 . V_133 = 10 ;
V_20 -> V_30 . V_53 . V_130 . V_134 = 10 ;
V_20 -> V_30 . V_53 . V_130 . V_135 = 10 ;
V_20 -> V_30 . V_53 . V_130 . V_136 = 0 ;
if ( ! F_36 ( V_9 , & V_20 -> V_30 ) ||
! F_41 ( V_9 , & V_20 -> V_185 ) ||
( V_20 -> V_185 . V_50 != V_97 ) ||
( V_20 -> V_185 . V_51 != 2 ) ) {
F_24 ( L_82 , V_9 -> V_31 ) ;
}
if ( V_20 -> V_185 . V_53 . V_139 ) {
F_24 ( L_83 , V_9 -> V_31 ) ;
}
V_9 -> V_197 = & V_198 ;
V_9 -> V_199 = 10 * V_17 ;
V_9 -> V_200 = & V_201 ;
V_9 -> V_190 = V_9 -> V_202 = 0 ;
V_183 = F_92 ( V_9 ) ;
if ( V_183 )
goto V_66;
return 0 ;
V_66:
F_87 ( V_9 -> V_4 , V_170 ) ;
return V_183 ;
}
struct V_8 * T_5 F_93 ( int V_203 )
{
struct V_8 * V_9 = F_94 ( sizeof( V_11 ) ) ;
int V_183 ;
if ( ! V_9 )
return F_95 ( - V_128 ) ;
sprintf ( V_9 -> V_31 , L_84 , V_203 ) ;
F_96 ( V_9 ) ;
V_183 = F_89 ( V_9 ) ;
if ( V_183 ) {
F_97 ( V_9 ) ;
return F_95 ( V_183 ) ;
}
return V_9 ;
}
int T_5 F_98 ( void )
{
int V_204 , V_205 = 0 ;
for ( V_204 = 0 ; V_204 < V_206 ; V_204 ++ ) {
struct V_8 * V_9 = F_94 ( sizeof( V_11 ) ) ;
if ( ! V_9 )
break;
V_9 -> V_82 = V_82 [ V_204 ] ;
V_9 -> V_4 = V_207 [ V_204 ] ;
if ( V_37 [ V_204 ] ) {
V_9 -> V_37 = V_37 [ V_204 ] ;
} else {
V_9 -> V_37 = V_191 ;
F_32 ( L_85 ) ;
}
if ( V_207 [ V_204 ] == 0 ) {
if ( V_204 ) {
F_97 ( V_9 ) ;
break;
}
F_99 ( L_86 ) ;
}
if ( F_89 ( V_9 ) != 0 ) {
F_32 ( L_87 , V_207 [ V_204 ] ) ;
F_97 ( V_9 ) ;
break;
}
V_208 [ V_204 ] = V_9 ;
V_205 ++ ;
}
if ( ! V_205 )
return - V_171 ;
return 0 ;
}
void T_6 F_100 ( void )
{
int V_204 ;
for ( V_204 = 0 ; V_204 < V_206 ; V_204 ++ ) {
struct V_8 * V_9 = V_208 [ V_204 ] ;
if ( V_9 ) {
F_101 ( V_9 ) ;
F_87 ( V_9 -> V_4 , V_170 ) ;
F_97 ( V_9 ) ;
}
}
}
