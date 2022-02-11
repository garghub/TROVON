T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
F_2 ( V_2 , V_4 , & V_3 ) ;
return ( F_3 ( V_2 -> V_5 , V_3 ) ) ;
}
int F_4 ( struct V_1 * V_6 ,
void * V_7 ,
int V_8 ,
int V_9 ,
void (* F_5) ( struct V_1 * V_6 , void * V_7 , int V_8 ,
int V_10 ) )
{
int V_11 = - V_12 ;
struct V_13 * V_14 ;
if ( V_6 -> V_15 -> V_16 == NULL )
goto V_17;
V_14 = F_6 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_14 ) {
F_7 ( V_14 , V_8 , V_8 ) ;
if ( ( V_11 =
F_8 ( & V_6 -> V_19 [ V_20 ] ,
V_14 ) ) < 0 ) {
F_9 ( V_14 ) ;
goto V_17;
}
V_6 -> V_21 [ V_8 ] . V_14 = V_14 ;
V_6 -> V_21 [ V_8 ] . V_22 = F_5 ;
V_11 = V_6 -> V_15 -> V_16 ( V_6 , V_7 , V_8 , V_9 ) ;
} else
V_11 = - V_23 ;
V_17:
return V_11 ;
}
int F_10 ( struct V_1 * V_6 , int V_8 )
{
if ( V_6 -> V_15 -> V_24 ) {
V_6 -> V_15 -> V_24 ( V_6 , V_8 ) ;
return F_11 ( V_6 -> V_21 [ V_8 ] . V_14 ) ;
} else
return - V_12 ;
}
int F_12 ( struct V_1 * V_6 ,
void * V_7 ,
int V_8 ,
int V_9 ,
void (* F_13) ( struct V_1 * V_6 , void * V_7 , int V_8 , int V_10 ) )
{
int V_11 = - V_12 ;
struct V_13 * V_14 ;
if ( V_6 -> V_15 -> V_25 == NULL )
goto V_17;
V_14 = F_6 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_14 ) {
F_7 ( V_14 , V_8 , V_8 ) ;
if ( ( V_11 =
F_8 ( & V_6 -> V_19 [ V_26 ] ,
V_14 ) ) < 0 ) {
F_9 ( V_14 ) ;
goto V_17;
}
V_6 -> V_27 [ V_8 ] . V_14 = V_14 ;
V_6 -> V_27 [ V_8 ] . V_22 = F_13 ;
V_11 = V_6 -> V_15 -> V_25 ( V_6 , V_7 , V_8 , V_9 ) ;
} else
V_11 = - V_23 ;
V_17:
return V_11 ;
}
int F_14 ( struct V_1 * V_6 , int V_8 )
{
if ( V_6 -> V_15 -> V_28 ) {
V_6 -> V_15 -> V_28 ( V_6 , V_8 ) ;
return F_11 ( V_6 -> V_27 [ V_8 ] . V_14 ) ;
} else
return - V_12 ;
}
static int
F_15 ( struct V_1 * V_6 , void * V_7 , struct V_13 * V_14 ,
void (* F_16) ( struct V_1 * V_6 , void * V_7 , T_1 V_29 , T_1 V_30 ,
T_1 V_31 ) )
{
int V_11 = 0 ;
struct V_32 * V_33 ;
if ( ! ( V_33 = F_6 ( sizeof( struct V_32 ) , V_18 ) ) ) {
V_11 = - V_23 ;
goto V_17;
}
V_33 -> V_14 = V_14 ;
V_33 -> F_16 = F_16 ;
V_33 -> V_7 = V_7 ;
F_17 ( & V_33 -> V_34 , & V_6 -> V_35 ) ;
V_17:
return V_11 ;
}
int F_18 ( struct V_1 * V_6 ,
void * V_7 ,
T_1 V_36 ,
T_1 V_37 ,
void (* F_16) ( struct V_1 * V_6 , void * V_7 , T_1 V_29 ,
T_1 V_30 , T_1 V_31 ) )
{
int V_11 = 0 ;
struct V_13 * V_14 = F_6 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_14 ) {
F_19 ( V_14 , V_36 , V_37 ) ;
if ( ( V_11 =
F_8 ( & V_6 -> V_19 [ V_38 ] ,
V_14 ) ) < 0 ) {
F_9 ( V_14 ) ;
goto V_17;
}
V_11 = F_15 ( V_6 , V_7 , V_14 , F_16 ) ;
} else
V_11 = - V_23 ;
V_17:
return V_11 ;
}
int F_20 ( struct V_1 * V_6 , T_1 V_36 , T_1 V_37 )
{
int V_11 = 0 , V_39 = 0 ;
struct V_32 * V_33 ;
F_21 (dbell, &mport->dbells, node) {
if ( ( V_33 -> V_14 -> V_36 == V_36 ) && ( V_33 -> V_14 -> V_37 == V_37 ) ) {
V_39 = 1 ;
break;
}
}
if ( ! V_39 ) {
V_11 = - V_40 ;
goto V_17;
}
F_22 ( & V_33 -> V_34 ) ;
V_11 = F_11 ( V_33 -> V_14 ) ;
F_9 ( V_33 ) ;
V_17:
return V_11 ;
}
struct V_13 * F_23 ( struct V_41 * V_42 , T_1 V_36 ,
T_1 V_37 )
{
struct V_13 * V_14 = F_6 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_14 ) {
F_19 ( V_14 , V_36 , V_37 ) ;
if ( F_8 ( & V_42 -> V_19 [ V_38 ] , V_14 )
< 0 ) {
F_9 ( V_14 ) ;
V_14 = NULL ;
}
}
return V_14 ;
}
int F_24 ( struct V_41 * V_42 , struct V_13 * V_14 )
{
int V_11 = F_11 ( V_14 ) ;
F_9 ( V_14 ) ;
return V_11 ;
}
int F_25 ( struct V_41 * V_42 ,
int (* F_26)( struct V_41 * V_42 , union V_43 * V_44 , int V_45 ) )
{
int V_11 = 0 ;
F_27 ( & V_46 ) ;
if ( V_42 -> F_26 != NULL )
V_11 = - V_23 ;
else
V_42 -> F_26 = F_26 ;
F_28 ( & V_46 ) ;
return V_11 ;
}
int F_29 ( struct V_41 * V_42 )
{
int V_11 = - V_23 ;
F_27 ( & V_46 ) ;
if ( V_42 -> F_26 ) {
V_42 -> F_26 = NULL ;
V_11 = 0 ;
}
F_28 ( & V_46 ) ;
return V_11 ;
}
T_2
F_30 ( struct V_1 * V_2 , int V_47 ,
T_1 V_48 , T_3 V_49 )
{
T_2 V_50 ;
T_2 V_51 ;
V_50 = F_31 ( V_2 , V_47 , V_48 , V_49 , 0 ) ;
while ( V_50 ) {
if ( V_47 )
F_2 ( V_2 , V_50 ,
& V_51 ) ;
else
F_32 ( V_2 , V_48 , V_49 ,
V_50 , & V_51 ) ;
V_51 = F_33 ( V_51 ) ;
switch ( V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return V_50 ;
default:
break;
}
V_50 = F_31 ( V_2 , V_47 , V_48 ,
V_49 , V_50 ) ;
}
return V_50 ;
}
struct V_41 * F_34 ( T_2 V_59 , struct V_41 * V_60 )
{
struct V_61 * V_62 ;
struct V_41 * V_42 ;
F_27 ( & V_46 ) ;
V_62 = V_60 ? V_60 -> V_63 . V_64 : V_65 . V_64 ;
while ( V_62 && ( V_62 != & V_65 ) ) {
V_42 = F_35 ( V_62 ) ;
if ( V_42 -> V_59 == V_59 )
goto exit;
V_62 = V_62 -> V_64 ;
}
V_42 = NULL ;
exit:
F_28 ( & V_46 ) ;
return V_42 ;
}
int F_36 ( struct V_41 * V_42 , T_2 V_66 , int V_67 )
{
T_2 V_68 ;
F_37 ( V_42 ,
V_42 -> V_69 + F_38 ( V_66 ) ,
& V_68 ) ;
if ( V_67 )
V_68 |= V_70 ;
else
V_68 &= ~ V_70 ;
F_39 ( V_42 ,
V_42 -> V_69 + F_38 ( V_66 ) ,
V_68 ) ;
return 0 ;
}
static int
F_40 ( struct V_41 * V_42 , struct V_41 * * V_71 , int * V_72 )
{
T_2 V_3 ;
int V_73 , V_11 = - V_74 ;
struct V_41 * V_75 = NULL ;
while ( V_42 -> V_75 && ( V_42 -> V_75 -> V_76 & V_77 ) ) {
if ( ! F_37 ( V_42 -> V_75 , V_78 , & V_3 ) ) {
V_75 = V_42 -> V_75 ;
break;
}
V_42 = V_42 -> V_75 ;
}
if ( V_75 == NULL )
goto V_79;
V_73 = V_75 -> V_80 -> V_81 [ V_42 -> V_48 ] ;
if ( V_73 != V_82 ) {
F_41 ( L_1 ,
F_42 ( V_75 ) , V_73 ) ;
* V_71 = V_75 ;
* V_72 = V_73 ;
V_11 = 0 ;
} else
F_41 ( L_2 , F_42 ( V_42 ) ) ;
V_79:
return V_11 ;
}
int
F_43 ( struct V_1 * V_6 , T_1 V_48 , T_3 V_49 )
{
int V_83 = 0 ;
T_2 V_84 ;
while ( F_32 ( V_6 , V_48 , V_49 ,
V_78 , & V_84 ) ) {
V_83 ++ ;
if ( V_83 == V_85 )
return - V_74 ;
F_44 ( 1 ) ;
}
return 0 ;
}
static int F_45 ( struct V_41 * V_42 )
{
return F_43 ( V_42 -> V_86 -> V_87 ,
V_42 -> V_48 , V_42 -> V_49 ) ;
}
static int
F_46 ( struct V_41 * V_42 , int V_66 , T_2 * V_88 )
{
T_2 V_68 ;
int V_89 ;
if ( V_88 ) {
F_37 ( V_42 ,
V_42 -> V_69 + F_47 ( V_66 ) ,
& V_68 ) ;
F_48 ( 50 ) ;
}
F_39 ( V_42 ,
V_42 -> V_69 + F_49 ( V_66 ) ,
V_90 ) ;
if ( V_88 == NULL )
return 0 ;
V_89 = 3 ;
while ( V_89 -- ) {
F_48 ( 50 ) ;
F_37 ( V_42 ,
V_42 -> V_69 + F_47 ( V_66 ) ,
& V_68 ) ;
if ( V_68 & V_91 ) {
* V_88 = V_68 ;
return 0 ;
}
}
return - V_74 ;
}
static int F_50 ( struct V_41 * V_42 , T_2 V_66 , T_2 V_92 )
{
struct V_41 * V_93 = V_42 -> V_80 -> V_93 [ V_66 ] ;
T_2 V_68 ;
T_2 V_94 , V_95 , V_96 ;
if ( V_92 == 0 )
F_37 ( V_42 ,
V_42 -> V_69 + F_51 ( V_66 ) ,
& V_92 ) ;
if ( V_92 & V_97 ) {
F_41 ( L_3 ) ;
if ( F_46 ( V_42 , V_66 , & V_68 ) ) {
F_41 ( L_4 ) ;
goto V_98;
}
F_41 ( L_5 ,
V_66 , V_68 ) ;
V_94 = ( V_68 & V_99 ) >> 5 ;
V_95 = V_68 & V_100 ;
F_37 ( V_42 ,
V_42 -> V_69 + F_52 ( V_66 ) ,
& V_68 ) ;
F_41 ( L_6 , V_66 , V_68 ) ;
V_96 = ( V_68 & V_101 ) >> 24 ;
F_41 ( L_7 \
L_8 ,
V_66 , V_94 , V_95 , V_96 ) ;
if ( ( V_94 != ( ( V_68 & V_102 ) >> 8 ) ) ||
( V_94 != ( V_68 & V_103 ) ) ) {
F_39 ( V_42 ,
V_42 -> V_69 + F_52 ( V_66 ) ,
( V_96 << 24 ) |
( V_94 << 8 ) | V_94 ) ;
V_94 ++ ;
if ( V_93 )
F_39 ( V_93 ,
V_93 -> V_69 +
F_52 ( F_53 ( V_93 -> V_104 ) ) ,
( V_94 << 24 ) |
( V_96 << 8 ) | V_96 ) ;
else
F_41 ( L_9 ) ;
}
V_98:
F_37 ( V_42 ,
V_42 -> V_69 + F_51 ( V_66 ) ,
& V_92 ) ;
F_41 ( L_10 , V_66 , V_92 ) ;
}
if ( ( V_92 & V_105 ) && V_93 ) {
F_41 ( L_11 ) ;
F_46 ( V_93 ,
F_53 ( V_93 -> V_104 ) , NULL ) ;
F_48 ( 50 ) ;
F_37 ( V_42 ,
V_42 -> V_69 + F_51 ( V_66 ) ,
& V_92 ) ;
F_41 ( L_10 , V_66 , V_92 ) ;
}
return ( V_92 & ( V_97 |
V_105 ) ) ? 1 : 0 ;
}
int F_54 ( union V_43 * V_106 )
{
struct V_41 * V_42 ;
T_2 V_92 , V_107 , V_108 ;
int V_11 , V_109 ;
V_42 = F_34 ( ( V_106 -> V_110 . V_111 & V_112 ) , NULL ) ;
if ( V_42 == NULL ) {
F_41 ( L_12 ,
V_113 , V_106 -> V_110 . V_111 ) ;
return - V_74 ;
}
F_41 ( L_13 , F_42 ( V_42 ) ) ;
#ifdef F_55
{
T_2 V_83 ;
for ( V_83 = 0 ; V_83 < V_114 / sizeof( T_2 ) ; ) {
F_41 ( L_14 ,
V_83 * 4 , V_106 -> V_115 [ V_83 ] , V_106 -> V_115 [ V_83 + 1 ] ,
V_106 -> V_115 [ V_83 + 2 ] , V_106 -> V_115 [ V_83 + 3 ] ) ;
V_83 += 4 ;
}
}
#endif
if ( V_42 -> F_26 != NULL ) {
V_11 = V_42 -> F_26 ( V_42 , V_106 , 0 ) ;
if ( V_11 == 0 )
return 0 ;
}
V_109 = V_106 -> V_110 . V_116 & 0xFF ;
if ( F_45 ( V_42 ) ) {
F_41 ( L_15 ) ;
if ( F_40 ( V_42 , & V_42 , & V_109 ) ) {
F_56 ( L_16 ,
F_42 ( V_42 ) ) ;
return - V_74 ;
}
V_106 = NULL ;
}
if ( ! ( V_42 -> V_76 & V_77 ) )
return 0 ;
if ( V_42 -> V_69 == 0 ) {
F_56 ( L_17 ,
F_42 ( V_42 ) ) ;
return 0 ;
}
if ( V_42 -> V_80 -> V_117 )
V_42 -> V_80 -> V_117 ( V_42 , V_109 ) ;
F_37 ( V_42 ,
V_42 -> V_69 + F_51 ( V_109 ) ,
& V_92 ) ;
F_41 ( L_18 , V_109 , V_92 ) ;
if ( V_92 & V_118 ) {
if ( ! ( V_42 -> V_80 -> V_119 & ( 1 << V_109 ) ) ) {
V_42 -> V_80 -> V_119 |= ( 1 << V_109 ) ;
F_36 ( V_42 , V_109 , 0 ) ;
F_41 ( L_19 ,
F_42 ( V_42 ) , V_109 ) ;
}
if ( V_92 & ( V_97 |
V_105 ) ) {
if ( F_50 ( V_42 , V_109 , V_92 ) )
F_50 ( V_42 , V_109 , 0 ) ;
}
} else {
if ( V_42 -> V_80 -> V_119 & ( 1 << V_109 ) ) {
V_42 -> V_80 -> V_119 &= ~ ( 1 << V_109 ) ;
F_36 ( V_42 , V_109 , 1 ) ;
F_39 ( V_42 ,
V_42 -> V_69 +
F_52 ( V_109 ) ,
V_120 ) ;
F_41 ( L_20 ,
F_42 ( V_42 ) , V_109 ) ;
}
}
F_37 ( V_42 ,
V_42 -> V_121 + F_57 ( V_109 ) , & V_107 ) ;
if ( V_107 ) {
F_41 ( L_21 ,
V_109 , V_107 ) ;
F_39 ( V_42 ,
V_42 -> V_121 + F_57 ( V_109 ) , 0 ) ;
}
F_37 ( V_42 ,
V_42 -> V_121 + V_122 , & V_108 ) ;
if ( V_108 ) {
F_41 ( L_22 ,
V_108 ) ;
F_39 ( V_42 ,
V_42 -> V_121 + V_122 , 0 ) ;
}
F_39 ( V_42 ,
V_42 -> V_69 + F_51 ( V_109 ) ,
V_92 ) ;
return 0 ;
}
T_2
F_31 ( struct V_1 * V_2 , int V_47 , T_1 V_48 ,
T_3 V_49 , T_2 V_60 )
{
T_2 V_123 ;
if ( V_60 == 0 ) {
if ( V_47 )
F_2 ( V_2 , V_124 ,
& V_123 ) ;
else
F_32 ( V_2 , V_48 , V_49 ,
V_124 , & V_123 ) ;
return V_123 & V_125 ;
} else {
if ( V_47 )
F_2 ( V_2 , V_60 , & V_123 ) ;
else
F_32 ( V_2 , V_48 , V_49 ,
V_60 , & V_123 ) ;
return F_33 ( V_123 ) ;
}
}
T_2
F_58 ( struct V_1 * V_2 , int V_47 , T_1 V_48 ,
T_3 V_49 , int V_126 )
{
T_2 V_127 , V_50 , V_51 ;
if ( V_47 )
F_2 ( V_2 , V_124 , & V_127 ) ;
else
F_32 ( V_2 , V_48 , V_49 ,
V_124 , & V_127 ) ;
V_50 = V_127 & V_125 ;
while ( V_50 ) {
if ( V_47 )
F_2 ( V_2 , V_50 ,
& V_51 ) ;
else
F_32 ( V_2 , V_48 , V_49 ,
V_50 , & V_51 ) ;
if ( F_33 ( V_51 ) == V_126 )
return V_50 ;
if ( ! ( V_50 = F_59 ( V_51 ) ) )
break;
}
return 0 ;
}
struct V_41 * F_60 ( T_1 V_128 , T_1 V_129 ,
T_1 V_130 , T_1 V_131 , struct V_41 * V_60 )
{
struct V_61 * V_62 ;
struct V_41 * V_42 ;
F_61 ( F_62 () ) ;
F_27 ( & V_46 ) ;
V_62 = V_60 ? V_60 -> V_63 . V_64 : V_65 . V_64 ;
while ( V_62 && ( V_62 != & V_65 ) ) {
V_42 = F_35 ( V_62 ) ;
if ( ( V_128 == V_132 || V_42 -> V_128 == V_128 ) &&
( V_129 == V_132 || V_42 -> V_129 == V_129 ) &&
( V_130 == V_132 || V_42 -> V_130 == V_130 ) &&
( V_131 == V_132 || V_42 -> V_131 == V_131 ) )
goto exit;
V_62 = V_62 -> V_64 ;
}
V_42 = NULL ;
exit:
F_63 ( V_60 ) ;
V_42 = F_64 ( V_42 ) ;
F_28 ( & V_46 ) ;
return V_42 ;
}
struct V_41 * F_65 ( T_1 V_128 , T_1 V_129 , struct V_41 * V_60 )
{
return F_60 ( V_128 , V_129 , V_132 , V_132 , V_60 ) ;
}
int F_66 ( struct V_1 * V_6 , T_1 V_48 , T_3 V_49 ,
T_1 V_133 , T_1 V_134 , T_3 V_135 )
{
if ( V_133 == V_136 ) {
F_67 ( V_6 , V_48 , V_49 ,
V_137 ,
( T_2 ) V_134 ) ;
F_67 ( V_6 , V_48 , V_49 ,
V_138 ,
( T_2 ) V_135 ) ;
}
F_48 ( 10 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_6 , T_1 V_48 , T_3 V_49 ,
T_1 V_133 , T_1 V_134 , T_3 * V_135 )
{
T_2 V_3 ;
if ( V_133 == V_136 ) {
F_67 ( V_6 , V_48 , V_49 ,
V_137 , V_134 ) ;
F_32 ( V_6 , V_48 , V_49 ,
V_138 , & V_3 ) ;
* V_135 = ( T_3 ) V_3 ;
}
return 0 ;
}
int F_69 ( struct V_1 * V_6 , T_1 V_48 , T_3 V_49 ,
T_1 V_133 )
{
T_2 V_139 = 0xff ;
T_2 V_83 , V_76 , V_140 = 1 , V_141 = 0 ;
T_2 V_142 = V_82 ;
if ( V_133 == V_136 ) {
F_32 ( V_6 , V_48 , V_49 ,
V_143 , & V_76 ) ;
if ( V_6 -> V_5 ) {
F_32 ( V_6 , V_48 , V_49 ,
V_144 ,
& V_139 ) ;
V_139 &= V_145 ;
}
if ( V_76 & V_146 ) {
V_141 = 0x80000000 ;
V_140 = 4 ;
V_142 = ( V_82 << 24 ) |
( V_82 << 16 ) |
( V_82 << 8 ) |
V_82 ;
}
for ( V_83 = 0 ; V_83 <= V_139 ; ) {
F_67 ( V_6 , V_48 , V_49 ,
V_137 ,
V_141 | V_83 ) ;
F_67 ( V_6 , V_48 , V_49 ,
V_138 ,
V_142 ) ;
V_83 += V_140 ;
}
}
F_48 ( 10 ) ;
return 0 ;
}
static void F_70 ( struct V_41 * V_147 )
{
}
static int T_4 F_71 ( void )
{
struct V_41 * V_147 = NULL ;
while ( ( V_147 = F_65 ( V_132 , V_132 , V_147 ) ) != NULL ) {
F_70 ( V_147 ) ;
}
return 0 ;
}
int T_4 F_72 ( void )
{
struct V_1 * V_2 ;
F_21 (port, &rio_mports, node) {
if ( V_2 -> V_148 >= 0 )
F_73 ( V_2 ) ;
else
F_74 ( V_2 ) ;
}
F_71 () ;
return 0 ;
}
static int F_75 ( int V_149 )
{
if ( ! V_150 [ 0 ] || V_150 [ 0 ] <= V_149 || V_149 >= V_151 )
return - 1 ;
return V_150 [ V_149 + 1 ] ;
}
static int F_76 ( char * V_152 )
{
( void ) F_77 ( V_152 , F_78 ( V_150 ) , V_150 ) ;
return 1 ;
}
int F_79 ( struct V_1 * V_2 )
{
if ( V_153 >= V_151 ) {
F_56 ( L_23 ) ;
return 1 ;
}
V_2 -> V_154 = V_153 ++ ;
V_2 -> V_148 = F_75 ( V_2 -> V_154 ) ;
F_17 ( & V_2 -> V_34 , & V_155 ) ;
return 0 ;
}
