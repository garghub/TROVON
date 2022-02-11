static inline void F_1 ( const struct V_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_4 . V_5 + V_2 . V_2 ) ;
}
static inline T_1 F_3 ( const struct V_1 V_2 )
{
return F_4 ( V_4 . V_5 + V_2 . V_2 ) ;
}
static int F_5 ( void )
{
int V_6 ;
F_6 ( L_1 ) ;
V_6 = F_7 ( & V_4 . V_7 -> V_8 ) ;
F_8 ( V_6 < 0 ) ;
return V_6 < 0 ? V_6 : 0 ;
}
static void F_9 ( void )
{
int V_6 ;
F_6 ( L_2 ) ;
V_6 = F_10 ( & V_4 . V_7 -> V_8 ) ;
F_8 ( V_6 < 0 ) ;
}
void F_11 ( void )
{
F_12 ( & V_4 . V_9 ) ;
}
void F_13 ( void )
{
F_14 ( & V_4 . V_9 ) ;
}
void F_15 ( const void * V_10 , T_1 V_11 )
{
switch ( V_4 . V_12 ) {
case V_13 :
{
const T_2 * V_14 = V_10 ;
for (; V_11 ; V_11 -- )
F_1 ( V_15 , * V_14 ++ ) ;
break;
}
case V_16 :
{
const T_3 * V_17 = V_10 ;
F_16 ( V_11 & 1 ) ;
for (; V_11 ; V_11 -= 2 )
F_1 ( V_15 , * V_17 ++ ) ;
break;
}
case V_18 :
case V_19 :
default:
F_17 () ;
}
}
void F_18 ( void * V_10 , T_1 V_11 )
{
switch ( V_4 . V_12 ) {
case V_13 :
{
T_2 * V_14 = V_10 ;
for (; V_11 ; V_11 -- ) {
F_1 ( V_20 , 0 ) ;
* V_14 ++ = F_3 ( V_20 ) ;
}
break;
}
case V_16 :
{
T_3 * V_17 = V_10 ;
F_16 ( V_11 & ~ 1 ) ;
for (; V_11 ; V_11 -= 2 ) {
F_1 ( V_20 , 0 ) ;
* V_17 ++ = F_3 ( V_20 ) ;
}
break;
}
case V_18 :
case V_19 :
default:
F_17 () ;
}
}
void F_19 ( const void * V_10 , T_1 V_11 )
{
switch ( V_4 . V_12 ) {
case V_13 :
{
const T_2 * V_14 = V_10 ;
for (; V_11 ; V_11 -- )
F_1 ( V_21 , * V_14 ++ ) ;
break;
}
case V_16 :
{
const T_3 * V_17 = V_10 ;
F_16 ( V_11 & 1 ) ;
for (; V_11 ; V_11 -= 2 )
F_1 ( V_21 , * V_17 ++ ) ;
break;
}
case V_18 :
case V_19 :
default:
F_17 () ;
}
}
void F_20 ( const void T_4 * V_10 , int V_22 ,
T_3 V_23 , T_3 V_24 ,
T_3 V_17 , T_3 V_25 )
{
int V_26 = V_22 * V_24 + V_23 ;
int V_27 = V_22 - V_17 ;
int V_28 ;
if ( V_4 . V_29 == V_30 &&
V_4 . V_12 == V_13 ) {
const T_3 T_4 * V_31 = V_10 ;
V_31 += V_26 ;
for (; V_25 ; -- V_25 ) {
for ( V_28 = 0 ; V_28 < V_17 ; ++ V_28 ) {
const T_2 T_4 * V_14 = ( const T_2 T_4 * ) V_31 ;
F_1 ( V_21 , F_21 ( V_14 + 1 ) ) ;
F_1 ( V_21 , F_21 ( V_14 + 0 ) ) ;
++ V_31 ;
}
V_31 += V_27 ;
}
} else if ( V_4 . V_29 == V_32 &&
V_4 . V_12 == V_13 ) {
const T_1 T_4 * V_31 = V_10 ;
V_31 += V_26 ;
for (; V_25 ; -- V_25 ) {
for ( V_28 = 0 ; V_28 < V_17 ; ++ V_28 ) {
const T_2 T_4 * V_14 = ( const T_2 T_4 * ) V_31 ;
F_1 ( V_21 , F_21 ( V_14 + 2 ) ) ;
F_1 ( V_21 , F_21 ( V_14 + 1 ) ) ;
F_1 ( V_21 , F_21 ( V_14 + 0 ) ) ;
++ V_31 ;
}
V_31 += V_27 ;
}
} else if ( V_4 . V_29 == V_30 &&
V_4 . V_12 == V_16 ) {
const T_3 T_4 * V_31 = V_10 ;
V_31 += V_26 ;
for (; V_25 ; -- V_25 ) {
for ( V_28 = 0 ; V_28 < V_17 ; ++ V_28 ) {
F_1 ( V_21 , F_22 ( V_31 ) ) ;
++ V_31 ;
}
V_31 += V_27 ;
}
} else {
F_17 () ;
}
}
static void F_23 ( struct V_33 * V_34 , T_3 V_35 ,
T_3 V_36 , void (* F_24)( void * V_37 ) , void * V_37 )
{
T_1 V_38 ;
F_16 ( V_4 . V_39 != NULL ) ;
F_6 ( L_3 , V_35 , V_36 ) ;
F_25 ( V_34 -> V_40 -> V_41 , V_35 , V_36 ) ;
F_26 ( V_34 -> V_40 -> V_41 , true ) ;
V_4 . V_39 = F_24 ;
V_4 . V_42 = V_37 ;
F_1 ( V_43 , V_35 * V_36 ) ;
V_38 = F_3 ( V_44 ) ;
V_38 = F_27 ( V_38 , 1 , 0 , 0 ) ;
if ( ! V_4 . V_45 )
V_38 = F_27 ( V_38 , 1 , 4 , 4 ) ;
F_1 ( V_44 , V_38 ) ;
}
static void V_39 ( void * V_37 , T_1 V_46 )
{
void (* F_24)( void * V_37 );
F_6 ( L_4 ) ;
F_28 ( V_44 , 0 , 0 , 0 ) ;
F_24 = V_4 . V_39 ;
V_4 . V_39 = NULL ;
if ( F_24 != NULL )
F_24 ( V_4 . V_42 ) ;
}
static void F_29 ( void )
{
T_1 V_38 ;
T_1 time ;
V_38 = F_3 ( F_30 ( 0 ) ) ;
time = 1000000000 / V_4 . V_47 ;
if ( V_38 & ( 1 << 4 ) )
time *= 2 ;
F_6 ( L_5 , time ) ;
V_38 = F_3 ( F_31 ( 0 ) ) ;
F_6 ( L_6
L_7 ,
V_38 & 0x0f , ( V_38 >> 4 ) & 0x3f , ( V_38 >> 10 ) & 0x0f , ( V_38 >> 14 ) & 0x3f ,
( V_38 >> 20 ) & 0x0f , ( V_38 >> 24 ) & 0x3f ) ;
V_38 = F_3 ( F_32 ( 0 ) ) ;
F_6 ( L_8
L_9 ,
( V_38 & 0x3f ) , ( V_38 >> 6 ) & 0x3f , ( V_38 >> 12 ) & 0x3f ,
( V_38 >> 22 ) & 0x3f ) ;
}
static void F_29 ( void ) {}
static inline unsigned long F_33 ( unsigned long V_48 , int div )
{
int V_49 = V_50 * div ;
return ( V_48 + V_49 - 1 ) / V_49 * V_49 ;
}
static int F_34 ( struct V_51 * V_52 , int div )
{
V_52 -> V_53 = div ;
V_52 -> V_54 = F_33 ( V_52 -> V_54 , div ) ;
V_52 -> V_55 = F_33 ( V_52 -> V_55 , div ) ;
V_52 -> V_56 = F_33 ( V_52 -> V_56 , div ) ;
V_52 -> V_57 = F_33 ( V_52 -> V_57 , div ) ;
V_52 -> V_58 = F_33 ( V_52 -> V_58 , div ) ;
V_52 -> V_59 = F_33 ( V_52 -> V_59 , div ) ;
V_52 -> V_60 = F_33 ( V_52 -> V_60 , div ) ;
V_52 -> V_61 = F_33 ( V_52 -> V_61 , div ) ;
V_52 -> V_62 = F_33 ( V_52 -> V_62 , div ) ;
V_52 -> V_63 = F_33 ( V_52 -> V_63 , div ) ;
F_6 ( L_10 ,
V_52 -> V_54 , V_52 -> V_62 , V_52 -> V_58 , V_52 -> V_59 ) ;
F_6 ( L_11 ,
V_52 -> V_55 , V_52 -> V_56 , V_52 -> V_60 ,
V_52 -> V_57 ) ;
F_6 ( L_12 ,
V_52 -> V_61 , V_52 -> V_63 ) ;
return F_35 ( V_52 ) ;
}
static int F_36 ( struct V_51 * V_52 )
{
T_1 V_64 ;
int div ;
F_37 ( & V_50 , & V_64 ) ;
for ( div = 1 ; div <= V_64 ; div ++ ) {
if ( F_34 ( V_52 , div ) == 0 )
break;
}
if ( div <= V_64 )
return 0 ;
F_38 ( L_13 ) ;
return - 1 ;
}
static void F_39 ( int V_65 , struct V_51 * V_52 )
{
int V_6 ;
if ( ! V_52 -> V_66 ) {
V_6 = F_36 ( V_52 ) ;
if ( V_6 < 0 )
F_38 ( L_14 ) ;
}
F_16 ( ! V_52 -> V_66 ) ;
F_1 ( F_31 ( V_65 ) , V_52 -> V_67 [ 0 ] ) ;
F_1 ( F_32 ( V_65 ) , V_52 -> V_67 [ 1 ] ) ;
F_28 ( F_30 ( V_65 ) ,
( V_52 -> V_67 [ 2 ] ? 1 : 0 ) , 4 , 4 ) ;
F_29 () ;
}
static int F_40 ( int time , int div )
{
unsigned long V_68 ;
int V_69 ;
V_68 = 1000000000 / ( V_4 . V_47 ) * div ;
V_69 = ( time + V_68 - 1 ) / V_68 ;
return V_69 ;
}
static void F_37 ( T_1 * V_70 , T_1 * V_64 )
{
* V_70 = 1000000000 / V_4 . V_47 ;
* V_64 = 2 ;
}
static int F_35 ( struct V_51 * V_52 )
{
T_1 V_38 ;
int V_71 , V_72 , V_73 , V_74 , V_75 , V_76 , V_77 ;
int V_78 , V_79 , V_80 ;
int div = V_52 -> V_53 ;
if ( div <= 0 || div > 2 )
return - 1 ;
V_73 = F_40 ( V_52 -> V_55 , div ) ;
V_74 = F_40 ( V_52 -> V_56 , div ) ;
if ( V_74 <= V_73 )
V_74 = V_73 + 1 ;
if ( V_73 > 0x0f )
return - 1 ;
if ( V_74 > 0x3f )
return - 1 ;
V_71 = F_40 ( V_52 -> V_58 , div ) ;
V_72 = F_40 ( V_52 -> V_59 , div ) ;
if ( V_72 <= V_71 )
V_72 = V_71 + 1 ;
if ( V_71 > 0x0f )
return - 1 ;
if ( V_72 > 0x3f )
return - 1 ;
V_75 = F_40 ( V_52 -> V_54 , div ) ;
V_76 = F_40 ( V_52 -> V_62 , div ) ;
if ( V_76 <= V_75 )
V_76 = V_75 + 1 ;
if ( V_76 < F_41 ( V_74 , V_72 ) )
V_76 = F_41 ( V_74 , V_72 ) ;
if ( V_75 > 0x0f )
return - 1 ;
if ( V_76 > 0x3f )
return - 1 ;
V_38 = V_75 ;
V_38 |= V_76 << 4 ;
V_38 |= V_73 << 10 ;
V_38 |= V_74 << 14 ;
V_38 |= V_71 << 20 ;
V_38 |= V_72 << 24 ;
V_52 -> V_67 [ 0 ] = V_38 ;
V_78 = F_40 ( V_52 -> V_61 , div ) ;
if ( V_78 <= V_71 )
V_78 = V_71 + 1 ;
if ( V_78 > 0x3f )
return - 1 ;
V_80 = F_40 ( V_52 -> V_57 , div ) ;
if ( V_80 < V_74 )
V_80 = V_74 ;
if ( V_80 > 0x3f )
return - 1 ;
V_79 = F_40 ( V_52 -> V_60 , div ) ;
if ( V_79 < V_72 )
V_79 = V_72 ;
if ( V_79 > 0x3f )
return - 1 ;
V_77 = F_40 ( V_52 -> V_63 , div ) ;
if ( V_77 > 0x3f )
return - 1 ;
V_38 = V_80 ;
V_38 |= V_79 << 6 ;
V_38 |= V_77 << 12 ;
V_38 |= V_78 << 22 ;
V_52 -> V_67 [ 1 ] = V_38 ;
V_52 -> V_67 [ 2 ] = div - 1 ;
V_52 -> V_66 = 1 ;
return 0 ;
}
int F_42 ( enum V_81 V_82 ,
unsigned V_83 , unsigned V_84 ,
int V_85 , int V_86 , int V_87 )
{
int V_88 , V_89 ;
int V_90 ;
T_1 V_38 ;
V_88 = F_40 ( V_83 , 1 ) ;
V_89 = F_40 ( V_84 , 1 ) ;
if ( V_88 < 2 )
return - V_91 ;
if ( V_82 == V_92 )
V_90 = 2 ;
else
V_90 = 4 ;
if ( V_89 < V_90 )
return - V_91 ;
if ( V_89 == V_88 )
return - V_93 ;
V_4 . V_94 = V_82 ;
F_6 ( L_15 ,
V_82 , V_88 , V_89 , V_85 , V_86 ) ;
F_1 ( V_95 , V_88 ) ;
F_1 ( V_96 , V_89 ) ;
V_38 = F_3 ( F_30 ( 0 ) ) ;
if ( V_85 )
V_38 &= ~ ( 1 << 21 ) ;
else
V_38 |= 1 << 21 ;
if ( V_86 )
V_38 &= ~ ( 1 << 20 ) ;
else
V_38 |= 1 << 20 ;
return 0 ;
}
int F_43 ( bool V_97 , unsigned line )
{
T_1 V_38 ;
F_6 ( L_16 , V_97 , line , V_4 . V_94 ) ;
if ( line > ( 1 << 11 ) - 1 )
return - V_93 ;
V_38 = F_3 ( F_30 ( 0 ) ) ;
V_38 &= ~ ( 0x3 << 2 ) ;
if ( V_97 ) {
V_4 . V_45 = 1 ;
V_38 |= V_4 . V_94 << 2 ;
} else
V_4 . V_45 = 0 ;
F_1 ( F_30 ( 0 ) , V_38 ) ;
F_1 ( V_98 , line ) ;
return 0 ;
}
static int F_44 ( int V_65 , int V_99 , int V_100 )
{
T_1 V_38 ;
int V_101 = 0 , V_102 = 0 , V_103 = 0 ;
enum V_104 V_105 ;
enum V_106 V_29 ;
enum V_107 V_12 ;
switch ( V_99 ) {
case 12 :
V_29 = V_108 ;
break;
case 16 :
V_29 = V_30 ;
break;
case 18 :
V_29 = V_109 ;
break;
case 24 :
V_29 = V_32 ;
break;
default:
F_17 () ;
return 1 ;
}
V_4 . V_29 = V_29 ;
switch ( V_100 ) {
case 8 :
V_12 = V_13 ;
break;
case 9 :
V_12 = V_18 ;
break;
case 12 :
V_12 = V_19 ;
break;
case 16 :
V_12 = V_16 ;
break;
default:
F_17 () ;
return 1 ;
}
V_4 . V_12 = V_12 ;
if ( ( V_99 % V_100 ) == 0 ) {
switch ( V_99 / V_100 ) {
case 1 :
V_105 = V_110 ;
break;
case 2 :
V_105 = V_111 ;
break;
case 3 :
V_105 = V_112 ;
break;
default:
F_17 () ;
return 1 ;
}
} else if ( ( 2 * V_99 % V_100 ) == 0 ) {
if ( ( 2 * V_99 / V_100 ) == 3 )
V_105 = V_113 ;
else {
F_17 () ;
return 1 ;
}
} else {
F_17 () ;
return 1 ;
}
switch ( V_105 ) {
case V_110 :
V_101 = V_100 ;
break;
case V_111 :
V_101 = V_100 ;
V_102 = V_100 ;
break;
case V_112 :
V_101 = V_100 ;
V_102 = V_100 ;
V_103 = V_100 ;
break;
case V_113 :
V_101 = V_100 ;
V_102 = ( V_100 / 2 ) | ( ( V_100 / 2 ) << 16 ) ;
V_103 = ( V_100 << 16 ) ;
break;
}
F_28 ( V_44 , 0 , 3 , 2 ) ;
V_38 = 0 ;
V_38 |= F_45 ( V_12 , 1 , 0 ) ;
V_38 |= F_45 ( 0 , 3 , 2 ) ;
V_38 |= F_45 ( 0 , 4 , 4 ) ;
V_38 |= F_45 ( V_29 , 6 , 5 ) ;
V_38 |= F_45 ( 0 , 8 , 7 ) ;
V_38 |= F_45 ( V_105 , 10 , 9 ) ;
V_38 |= F_45 ( 0 , 12 , 11 ) ;
V_38 |= F_45 ( 0 , 16 , 16 ) ;
V_38 |= F_45 ( 0 , 17 , 17 ) ;
V_38 |= F_45 ( 0 , 18 , 18 ) ;
V_38 |= F_45 ( 0 , 19 , 19 ) ;
V_38 |= F_45 ( 1 , 20 , 20 ) ;
V_38 |= F_45 ( 1 , 21 , 21 ) ;
F_1 ( F_30 ( V_65 ) , V_38 ) ;
F_1 ( F_46 ( V_65 ) , V_101 ) ;
F_1 ( F_47 ( V_65 ) , V_102 ) ;
F_1 ( F_48 ( V_65 ) , V_103 ) ;
V_38 = F_3 ( V_44 ) ;
V_38 = F_27 ( V_38 , V_65 + 1 , 3 , 2 ) ;
V_38 = F_27 ( V_38 , 0 , 1 , 1 ) ;
F_1 ( V_44 , V_38 ) ;
F_6 ( L_17 ,
V_99 , V_100 , V_101 , V_102 , V_103 ) ;
return 0 ;
}
int F_49 ( struct V_33 * V_34 , int V_114 ,
int V_115 )
{
return F_44 ( V_34 -> V_116 . V_4 . V_117 , V_114 , V_115 ) ;
}
int F_50 ( struct V_33 * V_34 ,
T_3 * V_23 , T_3 * V_24 , T_3 * V_17 , T_3 * V_25 )
{
T_3 V_118 , V_119 ;
V_34 -> V_120 -> V_121 ( V_34 , & V_118 , & V_119 ) ;
if ( * V_23 > V_118 || * V_24 > V_119 )
return - V_93 ;
if ( * V_23 + * V_17 > V_118 )
return - V_93 ;
if ( * V_24 + * V_25 > V_119 )
return - V_93 ;
if ( * V_17 == 1 )
return - V_93 ;
if ( * V_17 == 0 || * V_25 == 0 )
return - V_93 ;
F_25 ( V_34 -> V_40 -> V_41 , * V_17 , * V_25 ) ;
return 0 ;
}
int F_51 ( struct V_33 * V_34 ,
T_3 V_23 , T_3 V_24 , T_3 V_17 , T_3 V_25 ,
void (* F_24)( void * ) , void * V_37 )
{
F_23 ( V_34 , V_17 , V_25 , F_24 , V_37 ) ;
return 0 ;
}
void F_52 ( struct V_122 * V_123 )
{
#define F_53 ( V_6 ) seq_printf(s, "%-35s %08x\n", #r, rfbi_read_reg(r))
if ( F_5 () )
return;
F_53 ( V_124 ) ;
F_53 ( V_125 ) ;
F_53 ( V_126 ) ;
F_53 ( V_44 ) ;
F_53 ( V_43 ) ;
F_53 ( V_98 ) ;
F_53 ( V_15 ) ;
F_53 ( V_21 ) ;
F_53 ( V_127 ) ;
F_53 ( V_20 ) ;
F_53 ( V_128 ) ;
F_53 ( F_30 ( 0 ) ) ;
F_53 ( F_31 ( 0 ) ) ;
F_53 ( F_32 ( 0 ) ) ;
F_53 ( F_46 ( 0 ) ) ;
F_53 ( F_47 ( 0 ) ) ;
F_53 ( F_48 ( 0 ) ) ;
F_53 ( F_30 ( 1 ) ) ;
F_53 ( F_31 ( 1 ) ) ;
F_53 ( F_32 ( 1 ) ) ;
F_53 ( F_46 ( 1 ) ) ;
F_53 ( F_47 ( 1 ) ) ;
F_53 ( F_48 ( 1 ) ) ;
F_53 ( V_96 ) ;
F_53 ( V_95 ) ;
F_9 () ;
#undef F_53
}
int F_54 ( struct V_33 * V_34 )
{
int V_6 ;
if ( V_34 -> V_40 == NULL ) {
F_38 ( L_18 ) ;
return - V_129 ;
}
V_6 = F_5 () ;
if ( V_6 )
return V_6 ;
V_6 = F_55 ( V_34 ) ;
if ( V_6 ) {
F_38 ( L_19 ) ;
goto V_130;
}
V_6 = F_56 ( V_39 , NULL ,
V_131 ) ;
if ( V_6 ) {
F_38 ( L_20 ) ;
goto V_132;
}
F_57 ( V_34 -> V_40 -> V_41 ,
V_133 ) ;
F_58 ( V_134 ) ;
F_59 ( V_34 -> V_40 -> V_41 , true ) ;
F_60 ( V_34 -> V_40 -> V_41 , V_34 -> V_135 . V_114 ) ;
F_44 ( V_34 -> V_116 . V_4 . V_117 ,
V_34 -> V_135 . V_114 ,
V_34 -> V_116 . V_4 . V_115 ) ;
F_39 ( V_34 -> V_116 . V_4 . V_117 ,
& V_34 -> V_135 . V_51 ) ;
return 0 ;
V_132:
F_61 ( V_34 ) ;
V_130:
F_9 () ;
return V_6 ;
}
void F_62 ( struct V_33 * V_34 )
{
F_63 ( V_39 , NULL ,
V_131 ) ;
F_61 ( V_34 ) ;
F_9 () ;
}
int F_64 ( struct V_33 * V_34 )
{
V_4 . V_34 [ V_34 -> V_116 . V_4 . V_117 ] = V_34 ;
V_34 -> V_136 = V_137 ;
return 0 ;
}
static int F_65 ( struct V_138 * V_7 )
{
T_1 V_139 ;
struct V_140 * V_141 ;
struct V_142 * V_142 ;
int V_6 ;
V_4 . V_7 = V_7 ;
F_66 ( & V_4 . V_9 , 1 ) ;
V_141 = F_67 ( V_4 . V_7 , V_143 , 0 ) ;
if ( ! V_141 ) {
F_38 ( L_21 ) ;
return - V_93 ;
}
V_4 . V_5 = F_68 ( & V_7 -> V_8 , V_141 -> V_144 ,
F_69 ( V_141 ) ) ;
if ( ! V_4 . V_5 ) {
F_38 ( L_22 ) ;
return - V_145 ;
}
V_142 = F_70 ( & V_7 -> V_8 , L_23 ) ;
if ( F_71 ( V_142 ) ) {
F_38 ( L_24 ) ;
return F_72 ( V_142 ) ;
}
V_4 . V_47 = F_73 ( V_142 ) / 1000 ;
F_74 ( V_142 ) ;
F_75 ( & V_7 -> V_8 ) ;
V_6 = F_5 () ;
if ( V_6 )
goto V_146;
F_76 ( 10 ) ;
V_139 = F_3 ( V_124 ) ;
F_77 ( & V_7 -> V_8 , L_25 ,
F_78 ( V_139 , 7 , 4 ) , F_78 ( V_139 , 3 , 0 ) ) ;
F_9 () ;
return 0 ;
V_146:
F_79 ( & V_7 -> V_8 ) ;
return V_6 ;
}
static int F_80 ( struct V_138 * V_7 )
{
F_79 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_81 ( struct V_147 * V_8 )
{
F_82 () ;
F_83 () ;
return 0 ;
}
static int F_84 ( struct V_147 * V_8 )
{
int V_6 ;
V_6 = F_85 () ;
if ( V_6 < 0 )
goto V_148;
V_6 = F_86 () ;
if ( V_6 < 0 )
goto V_149;
return 0 ;
V_149:
F_83 () ;
V_148:
return V_6 ;
}
int F_87 ( void )
{
return F_88 ( & V_150 ) ;
}
void F_89 ( void )
{
return F_90 ( & V_150 ) ;
}
