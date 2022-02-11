static void F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = V_2 ; V_3 < 7 ; V_3 ++ )
V_1 -> V_4 [ V_3 ] = - 1 ;
}
static void F_2 ( T_1 * V_1 )
{
memset ( & V_1 -> V_5 , 0 , sizeof( V_1 -> V_5 ) ) ;
}
static void F_3 ( T_1 * V_1 , int V_6 )
{
memcpy ( & V_1 -> V_7 [ V_6 ] , & V_1 -> V_5 , sizeof( V_1 -> V_5 ) ) ;
}
static int F_4 ( T_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
int V_3 , V_9 = 0 ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ )
if ( V_1 -> V_4 [ V_3 ] == V_6 )
V_9 ++ ;
if ( V_9 )
continue;
if ( ! memcmp ( V_1 -> V_7 + V_6 , & V_1 -> V_5 ,
sizeof( V_1 -> V_5 ) ) )
break;
}
return V_6 >= V_8 ? - 1 : V_6 ;
}
static int F_5 ( T_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
int V_3 , V_9 = 0 ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ )
if ( V_1 -> V_4 [ V_3 ] == V_6 )
V_9 ++ ;
if ( ! V_9 )
break;
}
return V_6 ;
}
static inline void F_6 ( T_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
int V_3 , V_9 = 0 ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ )
if ( V_1 -> V_4 [ V_3 ] == V_6 )
V_9 ++ ;
if ( ! V_9 )
V_1 -> V_10 [ V_6 ] . V_11 = - 1 ;
}
}
static void F_7 ( T_1 * V_1 )
{
int V_12 , V_13 , V_14 ;
struct V_15 * V_15 ;
struct V_16 * V_17 ;
V_13 = V_14 = 0 ;
V_12 = ( V_1 -> V_18 [ 0 ] & V_19 ) >> 8 ;
V_15 = V_12 ? V_1 -> V_15 [ V_1 -> V_4 [ V_12 - 1 ] ] : NULL ;
V_17 = ( V_15 != NULL ) ? V_15 -> V_17 : NULL ;
while ( V_1 -> V_20 < 15 - V_13 ) {
T_2 V_21 ;
V_21 = V_1 -> V_18 [ V_13 ] ;
if ( V_12 != ( V_21 & V_19 ) >> 8 ) {
if ( V_17 && V_17 -> V_22 ) {
V_17 -> V_22 ( V_15 , 0 , 0 ) ;
V_17 -> V_22 ( V_15 , V_23 >> 16 , 0 ) ;
V_17 -> V_22 ( V_15 , V_24 >> 8 , 0 ) ;
V_17 -> V_22 ( V_15 , V_25 + V_14 , 0 ) ;
}
V_12 = ( V_21 & V_19 ) >> 8 ;
V_15 = V_12 ? V_1 -> V_15 [ V_1 -> V_4 [ V_12 - 1 ] ] : NULL ;
V_17 = ( V_15 != NULL ) ? V_15 -> V_17 : NULL ;
V_14 = 0 ;
}
V_14 ++ ;
V_13 ++ ;
if ( V_17 && V_17 -> V_22 ) {
V_17 -> V_22 ( V_15 , ( V_21 >> 24 ) , 0 ) ;
V_17 -> V_22 ( V_15 , ( V_21 >> 16 ) & 0xff , 0 ) ;
V_17 -> V_22 ( V_15 , ( V_21 >> 8 ) & ~ V_19 , 0 ) ;
V_17 -> V_22 ( V_15 , V_21 & 0xff , 0 ) ;
}
}
}
static int F_8 ( T_1 * V_1 , int V_26 )
{
int V_27 ;
V_27 = F_4 ( V_1 ) ;
if ( V_27 == - 1 ) {
V_27 = F_5 ( V_1 ) ;
if ( V_27 == - 1 )
goto V_28;
#ifdef F_9
F_10 (KERN_DEBUG PREFIX L_1 , rc) ;
#endif
F_3 ( V_1 , V_27 ) ;
V_1 -> V_4 [ V_1 -> V_29 ] = V_27 ;
V_1 -> V_10 [ V_27 ] . V_11 = V_1 -> V_29 ;
F_6 ( V_1 ) ;
F_11 ( V_1 -> V_15 [ V_27 ] ) ;
return - 1 ;
}
V_1 -> V_4 [ V_1 -> V_29 ] = V_27 ;
#ifdef F_9
F_10 (KERN_DEBUG PREFIX L_2 , rc) ;
#endif
V_1 -> V_10 [ V_27 ] . V_11 = V_1 -> V_29 ;
F_6 ( V_1 ) ;
return 0 ;
V_28:
F_10 (KERN_ERR PREFIX L_3 ) ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , int V_26 )
{
struct V_30 V_31 ;
F_13 ( & V_31 ) ;
if ( V_1 -> V_32 && ( V_31 . V_33 - V_1 -> V_34 . V_33 ) < 5 )
return - 1 ;
V_1 -> V_34 = V_31 ;
V_1 -> V_32 = 0 ;
return 0 ;
}
static int F_14 ( T_1 * V_1 , int V_35 )
{
return V_1 -> V_32 ++ >= V_35 ? - 1 : 0 ;
}
static int F_15 ( T_1 * V_1 , int V_2 )
{
V_1 -> V_29 = V_2 ;
F_1 ( V_1 , V_2 + 1 ) ;
return 0 ;
}
static int F_16 ( T_1 * V_1 , int V_26 )
{
V_1 -> V_29 -- ;
if ( V_1 -> V_29 <= - 1 ) {
V_1 -> V_29 = - 1 ;
F_1 ( V_1 , 0 ) ;
return - 1 ;
}
F_1 ( V_1 , V_1 -> V_29 + 1 ) ;
return 0 ;
}
static int F_17 ( T_1 * V_1 , int V_26 )
{
F_18 ( V_1 -> V_29 >= 6 ) ;
V_1 -> V_29 ++ ;
return 0 ;
}
static int F_19 ( T_1 * V_1 , int V_26 )
{
int V_13 ;
if ( V_1 -> V_18 [ 0 ] & V_24 )
goto V_36;
for ( V_13 = 1 ; V_13 < 16 ; V_13 ++ ) {
if ( ( ( V_1 -> V_18 [ V_13 ] & V_19 ) ==
( V_1 -> V_18 [ 0 ] & V_19 ) ) &&
( V_1 -> V_18 [ V_13 ] & V_24 ) &&
( ( V_1 -> V_18 [ V_13 ] & V_37 ) == V_38 ) )
break;
}
if ( V_13 > 15 )
goto V_36;
while ( ++ V_13 < 16 )
if ( V_1 -> V_18 [ V_13 ] )
break;
if ( V_13 < 16 )
goto V_36;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
V_1 -> V_5 . V_39 [ V_13 ] =
V_1 -> V_18 [ V_13 ] & V_37 ;
if ( V_1 -> V_5 . V_39 [ 1 ] & V_40 )
return V_41 ;
if ( V_1 -> V_5 . V_39 [ 1 ] & V_42 )
return V_43 | 4 ;
return 0 ;
V_36:
V_1 -> V_29 -- ;
return - 1 ;
}
static int F_20 ( T_1 * V_1 , int V_26 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
V_1 -> V_5 . V_44 [ V_13 ] =
V_1 -> V_18 [ V_13 ] & V_37 ;
if ( V_1 -> V_5 . V_39 [ 1 ] & V_42 )
return V_41 ;
return 0 ;
}
static int F_21 ( T_1 * V_1 , int V_26 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
V_1 -> V_5 . V_45 [ V_13 ] =
V_1 -> V_18 [ V_13 ] & V_37 ;
if ( V_1 -> V_5 . V_45 [ 0 ] & V_46 )
return V_41 ;
return 0 ;
}
static int F_22 ( T_1 * V_1 , int V_26 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
V_1 -> V_5 . V_47 [ V_13 ] =
V_1 -> V_18 [ V_13 ] & V_37 ;
F_10 (KERN_INFO PREFIX L_4 ,
mlc->di_scratch.rnm) ;
return 0 ;
}
static int F_23 ( T_1 * V_1 , int V_48 )
{
if ( V_1 -> V_49 == 0 )
V_50 = 0 ;
V_1 -> V_49 = 1 ;
F_7 ( V_1 ) ;
if ( ! V_50 )
return 0 ;
V_50 = 0 ;
V_1 -> V_49 = 0 ;
return 1 ;
}
static inline void F_24 ( T_1 * V_1 , const struct V_51 * V_52 )
{
switch ( V_52 -> V_53 ) {
case V_54 :
V_1 -> V_55 = V_52 -> V_56 . V_57 ;
V_1 -> V_55 |= ( ( V_1 -> V_29 + 2 ) << V_58 ) ;
break;
case V_59 :
V_1 -> V_55 = V_52 -> V_56 . V_57 ;
V_1 -> V_55 |= ( ( V_1 -> V_29 + 1 ) << V_58 ) ;
break;
case V_60 :
V_1 -> V_55 = V_52 -> V_56 . V_57 ;
break;
case V_61 :
V_1 -> V_55 = 0 ;
break;
default:
F_25 () ;
}
V_1 -> V_62 = 1 ;
V_1 -> V_63 = V_52 -> V_64 ;
F_13 ( & ( V_1 -> V_65 ) ) ;
V_1 -> V_20 = 15 ;
memset ( V_1 -> V_18 , 0 , 16 * sizeof( T_2 ) ) ;
F_18 ( F_26 ( & V_1 -> V_66 ) ) ;
}
static int F_27 ( T_1 * V_1 )
{
const struct V_51 * V_52 ;
int V_67 = 0 ;
int V_68 = 0 ;
unsigned long V_69 ;
#ifdef F_9
if ( V_1 -> V_70 && V_1 -> V_70 != V_70 &&
V_1 -> V_70 != 41 && V_1 -> V_70 != 42 && V_1 -> V_70 != 43 ) {
F_10 (KERN_DEBUG PREFIX L_5 , doze, mlc->seidx) ;
V_71 = 0 ;
}
V_70 = V_1 -> V_70 ;
#endif
V_52 = V_72 + V_1 -> V_70 ;
switch ( V_52 -> V_53 ) {
int V_27 ;
T_2 V_73 ;
case V_74 :
F_18 ( V_52 -> V_56 . V_75 == NULL ) ;
V_27 = V_52 -> V_56 . V_75 ( V_1 , V_52 -> V_64 ) ;
V_67 = ( V_27 > 0 ) ? V_52 -> V_76 :
( ( V_27 < 0 ) ? V_52 -> V_77 : V_52 -> V_78 ) ;
if ( V_67 == V_79 )
V_67 = V_27 ;
break;
case V_59 :
case V_54 :
case V_60 :
case V_61 :
F_28 ( & V_1 -> V_80 , V_69 ) ;
V_27 = V_1 -> V_81 ( V_1 , V_52 -> V_64 ) ;
if ( V_27 == 2 ) {
V_67 = V_82 ;
V_68 = 1 ;
F_29 ( & V_1 -> V_80 , V_69 ) ;
break;
}
if ( V_27 == 1 )
V_67 = V_52 -> V_76 ;
else if ( V_27 == 0 )
V_67 = V_52 -> V_78 ;
else
V_67 = V_52 -> V_77 ;
V_1 -> V_62 = 0 ;
F_29 ( & V_1 -> V_80 , V_69 ) ;
break;
case V_83 :
F_28 ( & V_1 -> V_80 , V_69 ) ;
V_73 = V_52 -> V_56 . V_57 ;
V_73 |= ( ( V_1 -> V_29 + 1 ) << V_58 ) ;
goto V_84;
case V_85 :
F_28 ( & V_1 -> V_80 , V_69 ) ;
V_73 = V_52 -> V_56 . V_57 ;
V_73 |= ( ( V_1 -> V_29 + 2 ) << V_58 ) ;
goto V_84;
case V_86 :
F_28 ( & V_1 -> V_80 , V_69 ) ;
V_73 = V_52 -> V_56 . V_57 ;
V_84:
if ( ! V_1 -> V_62 ) {
if ( ( V_52 + 1 ) -> V_53 & V_61 )
F_24 ( V_1 , V_52 + 1 ) ;
}
F_29 ( & V_1 -> V_80 , V_69 ) ;
if ( F_26 ( & V_1 -> V_87 ) ) {
V_67 = V_82 ;
break;
}
F_30 ( & V_1 -> V_87 ) ;
F_28 ( & V_1 -> V_80 , V_69 ) ;
if ( ! V_1 -> V_88 ) {
V_1 -> V_88 = 1 ;
V_1 -> V_89 = V_73 ;
V_1 -> V_84 ( V_1 ) ;
V_67 = V_82 ;
F_29 ( & V_1 -> V_80 , V_69 ) ;
break;
}
V_1 -> V_88 = 0 ;
F_13 ( & ( V_1 -> V_65 ) ) ;
F_29 ( & V_1 -> V_80 , V_69 ) ;
V_67 = V_41 ;
break;
case V_90 :
F_28 ( & V_1 -> V_80 , V_69 ) ;
V_67 = V_1 -> V_91 ( V_1 ) ? V_52 -> V_77 : V_52 -> V_78 ;
F_29 ( & V_1 -> V_80 , V_69 ) ;
break;
default:
F_25 () ;
}
#ifdef F_9
if ( V_67 == V_82 )
V_71 ++ ;
#endif
while ( V_67 & V_92 ) {
struct V_30 V_31 ;
if ( ! V_68 )
goto V_93;
F_13 ( & V_31 ) ;
V_31 . V_94 += V_95 * ( V_31 . V_33 - V_1 -> V_65 . V_33 ) ;
V_31 . V_94 -= V_1 -> V_65 . V_94 ;
if ( V_31 . V_94 >= V_1 -> V_63 ) goto V_93;
V_31 . V_94 = ( V_1 -> V_63 - V_31 . V_94 ) * V_96 / V_95 ;
if ( ! V_31 . V_94 ) goto V_93;
F_31 ( & V_97 , V_98 + V_31 . V_94 ) ;
break;
V_93:
F_32 ( & V_99 ) ;
break;
}
if ( V_67 & V_43 )
V_1 -> V_70 += V_67 & V_100 ;
else if ( V_67 & V_101 )
V_1 -> V_70 -= V_67 & V_100 ;
else
V_1 -> V_70 = V_67 & V_100 ;
if ( V_67 & V_102 )
return 1 ;
return 0 ;
}
static void F_33 ( unsigned long V_26 )
{
struct V_103 * V_104 ;
F_34 ( & V_105 ) ;
F_35 (tmp, &hil_mlcs) {
struct T_1 * V_1 = F_36 ( V_104 , T_1 , V_106 ) ;
while ( F_27 ( V_1 ) == 0 ) {
#ifdef F_9
if ( V_1 -> V_70 != 41 &&
V_1 -> V_70 != 42 &&
V_1 -> V_70 != 43 )
F_10 (KERN_DEBUG PREFIX L_6 ) ;
#endif
}
}
F_37 ( & V_105 ) ;
}
static void F_38 ( unsigned long V_107 )
{
V_50 = 1 ;
F_32 ( & V_99 ) ;
if ( ! F_39 ( & V_97 ) )
F_31 ( & V_97 , V_98 + V_96 ) ;
}
static int F_40 ( struct V_15 * V_15 , unsigned char V_108 )
{
struct V_109 * V_110 ;
struct T_1 * V_1 ;
struct V_16 * V_17 ;
T_3 * V_6 , * V_111 ;
V_110 = V_15 -> V_112 ;
F_18 ( V_110 == NULL ) ;
V_1 = V_110 -> V_1 ;
F_18 ( V_1 == NULL ) ;
V_1 -> V_113 [ V_110 -> V_114 ] |=
( ( T_2 ) V_108 ) << ( 8 * ( 3 - V_1 -> V_115 [ V_110 -> V_114 ] ) ) ;
if ( V_1 -> V_115 [ V_110 -> V_114 ] >= 3 ) {
if ( ! ( V_1 -> V_113 [ V_110 -> V_114 ] & V_24 ) )
return - V_116 ;
switch ( V_1 -> V_113 [ V_110 -> V_114 ] & V_37 ) {
case V_38 :
V_6 = V_1 -> V_7 [ V_110 -> V_114 ] . V_39 ;
goto V_117;
case V_118 :
V_6 = V_1 -> V_7 [ V_110 -> V_114 ] . V_44 ;
goto V_117;
case V_119 :
V_6 = V_1 -> V_7 [ V_110 -> V_114 ] . V_45 ;
goto V_117;
case V_120 :
V_6 = V_1 -> V_7 [ V_110 -> V_114 ] . V_47 ;
goto V_117;
default:
break;
}
V_1 -> V_115 [ V_110 -> V_114 ] = 0 ;
V_1 -> V_113 [ V_110 -> V_114 ] = 0 ;
}
V_1 -> V_115 [ V_110 -> V_114 ] ++ ;
return - V_116 ;
V_117:
V_17 = V_15 -> V_17 ;
F_18 ( V_17 == NULL ) ;
V_111 = V_6 + 15 ;
while ( ( V_111 != V_6 ) && ( * V_111 == 0 ) )
V_111 -- ;
while ( V_6 != V_111 ) {
V_17 -> V_22 ( V_15 , 0 , 0 ) ;
V_17 -> V_22 ( V_15 , V_23 >> 16 , 0 ) ;
V_17 -> V_22 ( V_15 , 0 , 0 ) ;
V_17 -> V_22 ( V_15 , * V_6 , 0 ) ;
V_6 ++ ;
}
V_17 -> V_22 ( V_15 , 0 , 0 ) ;
V_17 -> V_22 ( V_15 , V_23 >> 16 , 0 ) ;
V_17 -> V_22 ( V_15 , V_24 >> 8 , 0 ) ;
V_17 -> V_22 ( V_15 , * V_6 , 0 ) ;
V_1 -> V_115 [ V_110 -> V_114 ] = 0 ;
V_1 -> V_113 [ V_110 -> V_114 ] = 0 ;
return 0 ;
}
static int F_41 ( struct V_15 * V_15 )
{
struct V_109 * V_110 ;
struct T_1 * V_1 ;
if ( F_42 ( V_15 ) != NULL )
return - V_121 ;
V_110 = V_15 -> V_112 ;
F_18 ( V_110 == NULL ) ;
V_1 = V_110 -> V_1 ;
F_18 ( V_1 == NULL ) ;
return 0 ;
}
static void F_43 ( struct V_15 * V_15 )
{
struct V_109 * V_110 ;
struct T_1 * V_1 ;
V_110 = V_15 -> V_112 ;
F_18 ( V_110 == NULL ) ;
V_1 = V_110 -> V_1 ;
F_18 ( V_1 == NULL ) ;
F_44 ( V_15 , NULL ) ;
V_15 -> V_17 = NULL ;
}
int F_45 ( T_1 * V_1 )
{
int V_13 ;
unsigned long V_69 ;
F_18 ( V_1 == NULL ) ;
V_1 -> V_62 = 0 ;
V_1 -> V_88 = 0 ;
F_46 ( & V_1 -> V_80 ) ;
F_47 ( & V_1 -> V_87 , 1 ) ;
F_47 ( & V_1 -> V_66 , 1 ) ;
V_1 -> V_20 = - 1 ;
V_1 -> V_55 = 0 ;
V_1 -> V_49 = 0 ;
F_47 ( & ( V_1 -> V_122 ) , 0 ) ;
F_2 ( V_1 ) ;
F_1 ( V_1 , 0 ) ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
struct V_15 * V_123 ;
F_3 ( V_1 , V_13 ) ;
V_123 = F_48 ( sizeof( * V_123 ) , V_124 ) ;
V_1 -> V_15 [ V_13 ] = V_123 ;
if ( ! V_1 -> V_15 [ V_13 ] ) {
for (; V_13 >= 0 ; V_13 -- )
F_49 ( V_1 -> V_15 [ V_13 ] ) ;
return - V_125 ;
}
snprintf ( V_123 -> V_126 , sizeof( V_123 -> V_126 ) - 1 , L_7 , V_13 ) ;
snprintf ( V_123 -> V_127 , sizeof( V_123 -> V_127 ) - 1 , L_8 , V_13 ) ;
V_123 -> V_128 = V_129 ;
V_123 -> V_128 . V_128 = V_13 ;
V_123 -> V_130 = F_40 ;
V_123 -> V_131 = F_41 ;
V_123 -> V_132 = F_43 ;
V_123 -> V_112 = & ( V_1 -> V_10 [ V_13 ] ) ;
V_1 -> V_10 [ V_13 ] . V_1 = V_1 ;
V_1 -> V_10 [ V_13 ] . V_114 = V_13 ;
V_1 -> V_10 [ V_13 ] . V_11 = - 1 ;
V_1 -> V_113 [ V_13 ] = 0 ;
V_1 -> V_115 [ V_13 ] = 0 ;
F_50 ( V_123 ) ;
}
V_1 -> V_133 = & V_99 ;
F_28 ( & V_105 , V_69 ) ;
F_51 ( & V_1 -> V_106 , & V_134 ) ;
V_1 -> V_70 = V_135 ;
F_29 ( & V_105 , V_69 ) ;
F_32 ( & V_99 ) ;
return 0 ;
}
int F_52 ( T_1 * V_1 )
{
struct V_103 * V_104 ;
unsigned long V_69 ;
int V_13 ;
F_18 ( V_1 == NULL ) ;
F_28 ( & V_105 , V_69 ) ;
F_35 (tmp, &hil_mlcs)
if ( F_36 ( V_104 , T_1 , V_106 ) == V_1 )
goto V_9;
F_29 ( & V_105 , V_69 ) ;
F_32 ( & V_99 ) ;
return - V_136 ;
V_9:
F_53 ( V_104 ) ;
F_29 ( & V_105 , V_69 ) ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
F_54 ( V_1 -> V_15 [ V_13 ] ) ;
V_1 -> V_15 [ V_13 ] = NULL ;
}
F_32 ( & V_99 ) ;
return 0 ;
}
static int T_4 F_55 ( void )
{
F_56 ( & V_97 , & F_38 , 0 ) ;
F_31 ( & V_97 , V_98 + V_96 ) ;
F_57 ( & V_99 ) ;
return 0 ;
}
static void T_5 F_58 ( void )
{
F_59 ( & V_97 ) ;
F_60 ( & V_99 ) ;
}
