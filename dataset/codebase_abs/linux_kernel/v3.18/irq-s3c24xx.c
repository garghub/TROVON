static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_4 * V_6 = V_5 -> V_7 ;
struct V_3 * V_8 ;
unsigned long V_9 ;
unsigned int V_10 ;
V_9 = F_3 ( V_5 -> V_11 ) ;
V_9 |= ( 1UL << V_1 -> V_12 ) ;
F_4 ( V_9 , V_5 -> V_11 ) ;
if ( V_6 ) {
V_8 = & V_6 -> V_13 [ V_1 -> V_14 ] ;
if ( ( V_9 & V_8 -> V_15 ) == V_8 -> V_15 ) {
V_10 = F_5 ( V_6 -> V_16 ,
V_1 -> V_14 ) ;
F_1 ( F_6 ( V_10 ) ) ;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_4 * V_6 = V_5 -> V_7 ;
unsigned long V_9 ;
unsigned int V_10 ;
V_9 = F_3 ( V_5 -> V_11 ) ;
V_9 &= ~ ( 1UL << V_1 -> V_12 ) ;
F_4 ( V_9 , V_5 -> V_11 ) ;
if ( V_6 ) {
V_10 = F_5 ( V_6 -> V_16 ,
V_1 -> V_14 ) ;
F_7 ( F_6 ( V_10 ) ) ;
}
}
static inline void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
unsigned long V_17 = 1UL << V_1 -> V_12 ;
F_4 ( V_17 , V_5 -> V_18 ) ;
if ( V_5 -> V_19 )
F_4 ( V_17 , V_5 -> V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int type )
{
switch ( type ) {
case V_20 :
break;
case V_21 :
case V_22 :
case V_23 :
F_10 ( V_2 -> V_24 , V_25 ) ;
break;
case V_26 :
case V_27 :
F_10 ( V_2 -> V_24 , V_28 ) ;
break;
default:
F_11 ( L_1 , type ) ;
return - V_29 ;
}
return 0 ;
}
static int F_12 ( void T_1 * V_30 ,
void T_1 * V_31 ,
unsigned long V_32 ,
unsigned long V_33 ,
unsigned int type )
{
unsigned long V_34 = 0 , V_35 ;
V_35 = F_3 ( V_30 ) ;
V_35 = ( V_35 & ~ ( 3 << V_32 ) ) | ( 0x02 << V_32 ) ;
F_4 ( V_35 , V_30 ) ;
switch ( type )
{
case V_20 :
F_13 ( L_2 ) ;
break;
case V_21 :
V_34 = V_36 ;
break;
case V_22 :
V_34 = V_37 ;
break;
case V_23 :
V_34 = V_38 ;
break;
case V_26 :
V_34 = V_39 ;
break;
case V_27 :
V_34 = V_40 ;
break;
default:
F_11 ( L_1 , type ) ;
return - V_29 ;
}
V_35 = F_3 ( V_31 ) ;
V_35 = ( V_35 & ~ ( 7 << V_33 ) ) | ( V_34 << V_33 ) ;
F_4 ( V_35 , V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int type )
{
void T_1 * V_31 ;
void T_1 * V_30 ;
unsigned long V_32 , V_33 ;
if ( ( V_2 -> V_41 >= 4 ) && ( V_2 -> V_41 <= 7 ) ) {
V_30 = V_42 ;
V_31 = V_43 ;
V_32 = ( V_2 -> V_41 ) * 2 ;
V_33 = ( V_2 -> V_41 ) * 4 ;
} else if ( ( V_2 -> V_41 >= 8 ) && ( V_2 -> V_41 <= 15 ) ) {
V_30 = V_44 ;
V_31 = V_45 ;
V_32 = ( V_2 -> V_41 - 8 ) * 2 ;
V_33 = ( V_2 -> V_41 - 8 ) * 4 ;
} else if ( ( V_2 -> V_41 >= 16 ) && ( V_2 -> V_41 <= 23 ) ) {
V_30 = V_44 ;
V_31 = V_46 ;
V_32 = ( V_2 -> V_41 - 8 ) * 2 ;
V_33 = ( V_2 -> V_41 - 16 ) * 4 ;
} else {
return - V_29 ;
}
return F_12 ( V_30 , V_31 , V_32 ,
V_33 , type ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int type )
{
void T_1 * V_31 ;
void T_1 * V_30 ;
unsigned long V_32 , V_33 ;
if ( ( V_2 -> V_41 >= 0 ) && ( V_2 -> V_41 <= 3 ) ) {
V_30 = V_42 ;
V_31 = V_43 ;
V_32 = ( V_2 -> V_41 ) * 2 ;
V_33 = ( V_2 -> V_41 ) * 4 ;
} else {
return - V_29 ;
}
return F_12 ( V_30 , V_31 , V_32 ,
V_33 , type ) ;
}
static void F_16 ( unsigned int V_24 , struct V_47 * V_48 )
{
struct V_49 * V_50 = F_17 ( V_48 ) ;
struct V_3 * V_1 = F_18 ( V_48 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_4 * V_51 = V_1 -> V_51 ;
unsigned long V_52 ;
unsigned long V_53 ;
unsigned int V_54 ;
unsigned int V_12 ;
V_12 = ( V_5 -> V_16 -> V_55 ) ? 32 : 0 ;
F_19 ( V_50 , V_48 ) ;
V_52 = F_3 ( V_51 -> V_18 ) ;
V_53 = F_3 ( V_51 -> V_11 ) ;
V_52 &= ~ V_53 ;
V_52 &= V_1 -> V_15 ;
while ( V_52 ) {
V_54 = F_20 ( V_52 ) ;
V_52 &= ~ ( 1 << V_54 ) ;
V_24 = F_5 ( V_51 -> V_16 , V_12 + V_54 ) ;
F_21 ( V_24 ) ;
}
F_22 ( V_50 , V_48 ) ;
}
static inline int F_23 ( struct V_4 * V_5 ,
struct V_56 * V_57 , int V_58 )
{
int V_59 ;
int V_12 ;
V_59 = F_3 ( V_5 -> V_19 ) ;
if ( ! V_59 )
return false ;
if ( ! V_5 -> V_16 -> V_55 )
V_58 = 0 ;
V_12 = F_3 ( V_5 -> V_19 + 4 ) ;
if ( ! ( V_59 & ( 1 << V_12 ) ) )
V_12 = F_20 ( V_59 ) ;
F_24 ( V_5 -> V_16 , V_58 + V_12 , V_57 ) ;
return true ;
}
T_2 void T_3 F_25 ( struct V_56 * V_57 )
{
do {
if ( F_26 ( V_60 [ 0 ] ) )
if ( F_23 ( V_60 [ 0 ] , V_57 , 0 ) )
continue;
if ( V_60 [ 2 ] )
if ( F_23 ( V_60 [ 2 ] , V_57 , 64 ) )
continue;
break;
} while ( 1 );
}
int F_27 ( unsigned int V_24 , bool V_61 )
{
T_4 V_62 ;
unsigned V_63 ;
if ( V_61 ) {
V_63 = V_24 - V_64 ;
if ( V_63 > 31 )
return - V_29 ;
V_62 = 1 << V_63 ;
} else {
V_62 = 0 ;
}
F_4 ( V_62 , V_65 ) ;
return 0 ;
}
static int F_28 ( struct V_66 * V_67 , unsigned int V_68 ,
T_5 V_69 )
{
struct V_4 * V_5 = V_67 -> V_70 ;
struct V_3 * V_1 = & V_5 -> V_13 [ V_69 ] ;
struct V_4 * V_6 ;
struct V_3 * V_71 ;
unsigned int V_10 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_12 = V_69 ;
V_6 = V_5 -> V_7 ;
switch ( V_1 -> type ) {
case V_72 :
return 0 ;
case V_73 :
if ( V_6 && ( ! F_29 () || V_69 >= 4 ) )
F_30 ( V_68 , & V_74 ,
V_25 ) ;
else
F_30 ( V_68 , & V_75 ,
V_25 ) ;
break;
case V_76 :
if ( V_6 || V_5 -> V_18 == V_77 )
F_30 ( V_68 , & V_78 ,
V_25 ) ;
else
F_30 ( V_68 , & V_79 ,
V_25 ) ;
break;
case V_80 :
if ( V_6 )
F_30 ( V_68 , & V_78 ,
V_28 ) ;
else
F_30 ( V_68 , & V_79 ,
V_28 ) ;
break;
default:
F_11 ( L_3 , V_1 -> type ) ;
return - V_29 ;
}
F_31 ( V_68 , V_1 ) ;
F_32 ( V_68 , V_81 ) ;
if ( V_6 && V_1 -> type != V_72 ) {
if ( V_1 -> V_14 > 31 ) {
F_11 ( L_4 ,
V_1 -> V_14 ) ;
goto V_82;
}
V_71 = & V_6 -> V_13 [ V_1 -> V_14 ] ;
V_71 -> V_51 = V_5 ;
V_71 -> V_15 |= ( 1UL << V_69 ) ;
V_10 = F_5 ( V_6 -> V_16 ,
V_1 -> V_14 ) ;
if ( ! V_10 ) {
F_11 ( L_5 ,
V_1 -> V_14 ) ;
goto V_82;
}
F_33 ( V_10 , F_16 ) ;
}
return 0 ;
V_82:
F_32 ( V_68 , 0 ) ;
return - V_29 ;
}
static void F_34 ( struct V_4 * V_5 )
{
void T_1 * V_83 ;
unsigned long V_84 ;
unsigned long V_85 ;
int V_86 ;
V_83 = V_5 -> V_19 ? V_5 -> V_19 : V_5 -> V_18 ;
V_85 = 0 ;
for ( V_86 = 0 ; V_86 < 4 ; V_86 ++ ) {
V_84 = F_3 ( V_83 ) ;
if ( V_84 == 0 || V_84 == V_85 )
break;
F_4 ( V_84 , V_5 -> V_18 ) ;
if ( V_5 -> V_19 )
F_4 ( V_84 , V_5 -> V_19 ) ;
F_35 ( L_6 , ( int ) V_84 ) ;
V_85 = V_84 ;
}
}
static struct V_4 * T_6 F_36 ( struct V_87 * V_88 ,
struct V_3 * V_1 ,
struct V_4 * V_7 ,
unsigned long V_89 )
{
struct V_4 * V_5 ;
void T_1 * V_90 = ( void * ) 0xf6000000 ;
int V_91 ;
int V_92 ;
int V_93 ;
V_5 = F_37 ( sizeof( struct V_4 ) , V_94 ) ;
if ( ! V_5 )
return F_38 ( - V_95 ) ;
V_5 -> V_13 = V_1 ;
if ( V_7 )
V_5 -> V_7 = V_7 ;
switch ( V_89 ) {
case 0x4a000000 :
F_39 ( L_7 ) ;
V_5 -> V_18 = V_90 ;
V_5 -> V_11 = V_90 + 0x08 ;
V_5 -> V_19 = V_90 + 0x10 ;
V_91 = 32 ;
V_92 = F_40 ( 0 ) ;
break;
case 0x4a000018 :
F_39 ( L_8 ) ;
V_5 -> V_18 = V_90 + 0x18 ;
V_5 -> V_11 = V_90 + 0x1c ;
V_91 = 29 ;
V_92 = F_41 ( 0 ) ;
break;
case 0x4a000040 :
F_39 ( L_9 ) ;
V_5 -> V_18 = V_90 + 0x40 ;
V_5 -> V_11 = V_90 + 0x48 ;
V_5 -> V_19 = V_90 + 0x50 ;
V_91 = 8 ;
V_92 = F_42 ( 0 ) ;
break;
case 0x560000a4 :
F_39 ( L_10 ) ;
V_90 = ( void * ) 0xfd000000 ;
V_5 -> V_11 = V_90 + 0xa4 ;
V_5 -> V_18 = V_90 + 0xa8 ;
V_91 = 24 ;
V_92 = F_40 ( 32 ) ;
break;
default:
F_11 ( L_11 ) ;
V_93 = - V_29 ;
goto V_82;
}
F_34 ( V_5 ) ;
V_5 -> V_16 = F_43 ( V_88 , V_91 , V_92 ,
0 , & V_96 ,
V_5 ) ;
if ( ! V_5 -> V_16 ) {
F_11 ( L_12 ) ;
V_93 = - V_29 ;
goto V_82;
}
F_44 ( F_25 ) ;
return V_5 ;
V_82:
F_45 ( V_5 ) ;
return F_38 ( V_93 ) ;
}
void T_6 F_46 ( void )
{
#ifdef F_47
F_48 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_36 ( NULL , & V_97 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_49 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
V_60 [ 1 ] = F_36 ( NULL , & V_98 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
F_36 ( NULL , & V_99 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
}
void T_6 F_50 ( void )
{
F_35 ( L_14 ) ;
#ifdef F_47
F_48 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_36 ( NULL , & V_100 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_49 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_36 ( NULL , & V_101 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_36 ( NULL , & V_102 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
}
void T_6 F_51 ( void )
{
F_35 ( L_15 ) ;
#ifdef F_47
F_48 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_36 ( NULL , & V_103 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_49 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_36 ( NULL , & V_99 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_36 ( NULL , & V_104 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
V_60 [ 2 ] = F_36 ( NULL , & V_105 [ 0 ] ,
NULL , 0x4a000040 ) ;
}
void T_6 F_52 ( void )
{
F_35 ( L_16 ) ;
#ifdef F_47
F_48 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_36 ( NULL , & V_106 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_49 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_36 ( NULL , & V_99 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_36 ( NULL , & V_107 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
}
void T_6 F_53 ( void )
{
F_35 ( L_17 ) ;
#ifdef F_47
F_48 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_36 ( NULL , & V_108 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_49 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_36 ( NULL , & V_99 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_36 ( NULL , & V_109 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
}
void T_6 F_54 ( void )
{
F_35 ( L_18 ) ;
#ifdef F_47
F_48 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_36 ( NULL , & V_110 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_49 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_36 ( NULL , & V_99 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_36 ( NULL , & V_111 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
}
static int F_55 ( struct V_66 * V_67 , unsigned int V_68 ,
T_5 V_69 )
{
unsigned int V_112 = V_69 / 32 ;
unsigned int V_113 = V_69 % 32 ;
struct V_4 * V_5 = V_60 [ V_112 ] ;
struct V_4 * V_6 = V_5 -> V_7 ;
struct V_3 * V_1 = & V_5 -> V_13 [ V_113 ] ;
V_1 -> V_5 = V_5 ;
V_1 -> V_12 = V_113 ;
if ( ! V_6 )
F_30 ( V_68 , & V_79 , V_25 ) ;
else
F_30 ( V_68 , & V_78 ,
V_25 ) ;
F_31 ( V_68 , V_1 ) ;
F_32 ( V_68 , V_81 ) ;
return 0 ;
}
static int F_56 ( struct V_66 * V_114 , struct V_87 * V_54 ,
const T_4 * V_115 , unsigned int V_116 ,
T_5 * V_117 , unsigned int * V_118 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
struct V_3 * V_1 ;
struct V_3 * V_71 ;
int V_10 ;
if ( F_57 ( V_116 < 4 ) )
return - V_29 ;
if ( V_115 [ 0 ] > 2 || ! V_60 [ V_115 [ 0 ] ] ) {
F_11 ( L_19 , V_115 [ 0 ] ) ;
return - V_29 ;
}
V_5 = V_60 [ V_115 [ 0 ] ] ;
* V_117 = V_115 [ 0 ] * 32 + V_115 [ 2 ] ;
* V_118 = V_115 [ 3 ] & V_119 ;
V_6 = V_5 -> V_7 ;
if ( V_6 ) {
V_1 = & V_5 -> V_13 [ V_115 [ 2 ] ] ;
V_1 -> V_14 = V_115 [ 1 ] ;
V_71 = & V_6 -> V_13 [ V_1 -> V_14 ] ;
V_71 -> V_51 = V_5 ;
V_71 -> V_15 |= ( 1UL << V_115 [ 2 ] ) ;
V_10 = F_58 ( V_6 -> V_16 , V_115 [ 1 ] ) ;
if ( V_10 < 0 ) {
F_11 ( L_20 ) ;
return V_10 ;
}
F_33 ( V_10 , F_16 ) ;
}
return 0 ;
}
static int T_6 F_59 ( struct V_87 * V_88 ,
struct V_87 * V_120 ,
struct V_121 * V_122 , int V_123 )
{
struct V_4 * V_5 ;
struct V_121 * V_124 ;
struct V_66 * V_16 ;
void T_1 * V_125 ;
int V_86 ;
V_125 = F_60 ( V_88 , 0 ) ;
if ( ! V_125 ) {
F_11 ( L_21 ) ;
return - V_29 ;
}
V_16 = F_61 ( V_88 , V_123 * 32 ,
& V_126 , NULL ) ;
if ( ! V_16 ) {
F_11 ( L_12 ) ;
return - V_29 ;
}
for ( V_86 = 0 ; V_86 < V_123 ; V_86 ++ ) {
V_124 = & V_122 [ V_86 ] ;
F_39 ( L_22 , V_124 -> V_127 ) ;
V_5 = F_37 ( sizeof( struct V_4 ) , V_94 ) ;
if ( ! V_5 )
return - V_95 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_13 = F_37 ( sizeof( struct V_3 ) * 32 ,
V_94 ) ;
if ( ! V_5 -> V_13 ) {
F_45 ( V_5 ) ;
return - V_95 ;
}
if ( V_124 -> V_7 ) {
V_5 -> V_18 = V_125 + V_124 -> V_12 ;
V_5 -> V_11 = V_125 + V_124 -> V_12 + 0x4 ;
if ( * ( V_124 -> V_7 ) ) {
V_5 -> V_7 = * ( V_124 -> V_7 ) ;
} else {
F_13 ( L_23 ,
V_124 -> V_127 ) ;
F_45 ( V_5 -> V_13 ) ;
F_45 ( V_5 ) ;
continue;
}
} else {
V_5 -> V_18 = V_125 + V_124 -> V_12 ;
V_5 -> V_11 = V_125 + V_124 -> V_12 + 0x08 ;
V_5 -> V_19 = V_125 + V_124 -> V_12 + 0x10 ;
}
F_34 ( V_5 ) ;
V_60 [ V_86 ] = V_5 ;
}
F_44 ( F_25 ) ;
return 0 ;
}
int T_6 F_62 ( struct V_87 * V_88 ,
struct V_87 * V_120 )
{
return F_59 ( V_88 , V_120 ,
V_128 , F_63 ( V_128 ) ) ;
}
int T_6 F_64 ( struct V_87 * V_88 ,
struct V_87 * V_120 )
{
return F_59 ( V_88 , V_120 ,
V_129 , F_63 ( V_129 ) ) ;
}
