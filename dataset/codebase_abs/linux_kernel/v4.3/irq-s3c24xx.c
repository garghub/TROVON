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
static void F_16 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_17 ( V_48 ) ;
struct V_3 * V_1 = F_18 ( V_48 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_4 * V_51 = V_1 -> V_51 ;
unsigned int V_52 , V_12 , V_24 ;
unsigned long V_53 , V_54 ;
V_12 = ( V_5 -> V_16 -> V_55 ) ? 32 : 0 ;
F_19 ( V_50 , V_48 ) ;
V_53 = F_3 ( V_51 -> V_18 ) ;
V_54 = F_3 ( V_51 -> V_11 ) ;
V_53 &= ~ V_54 ;
V_53 &= V_1 -> V_15 ;
while ( V_53 ) {
V_52 = F_20 ( V_53 ) ;
V_53 &= ~ ( 1 << V_52 ) ;
V_24 = F_5 ( V_51 -> V_16 , V_12 + V_52 ) ;
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
if ( V_6 && V_1 -> type != V_72 ) {
if ( V_1 -> V_14 > 31 ) {
F_11 ( L_4 ,
V_1 -> V_14 ) ;
return - V_29 ;
}
V_71 = & V_6 -> V_13 [ V_1 -> V_14 ] ;
V_71 -> V_51 = V_5 ;
V_71 -> V_15 |= ( 1UL << V_69 ) ;
V_10 = F_5 ( V_6 -> V_16 ,
V_1 -> V_14 ) ;
if ( ! V_10 ) {
F_11 ( L_5 ,
V_1 -> V_14 ) ;
return - V_29 ;
}
F_32 ( V_10 , F_16 ) ;
}
return 0 ;
}
static void F_33 ( struct V_4 * V_5 )
{
void T_1 * V_81 ;
unsigned long V_82 ;
unsigned long V_83 ;
int V_84 ;
V_81 = V_5 -> V_19 ? V_5 -> V_19 : V_5 -> V_18 ;
V_83 = 0 ;
for ( V_84 = 0 ; V_84 < 4 ; V_84 ++ ) {
V_82 = F_3 ( V_81 ) ;
if ( V_82 == 0 || V_82 == V_83 )
break;
F_4 ( V_82 , V_5 -> V_18 ) ;
if ( V_5 -> V_19 )
F_4 ( V_82 , V_5 -> V_19 ) ;
F_34 ( L_6 , ( int ) V_82 ) ;
V_83 = V_82 ;
}
}
static struct V_4 * T_6 F_35 ( struct V_85 * V_86 ,
struct V_3 * V_1 ,
struct V_4 * V_7 ,
unsigned long V_87 )
{
struct V_4 * V_5 ;
void T_1 * V_88 = ( void * ) 0xf6000000 ;
int V_89 ;
int V_90 ;
int V_91 ;
V_5 = F_36 ( sizeof( struct V_4 ) , V_92 ) ;
if ( ! V_5 )
return F_37 ( - V_93 ) ;
V_5 -> V_13 = V_1 ;
if ( V_7 )
V_5 -> V_7 = V_7 ;
switch ( V_87 ) {
case 0x4a000000 :
F_38 ( L_7 ) ;
V_5 -> V_18 = V_88 ;
V_5 -> V_11 = V_88 + 0x08 ;
V_5 -> V_19 = V_88 + 0x10 ;
V_89 = 32 ;
V_90 = F_39 ( 0 ) ;
break;
case 0x4a000018 :
F_38 ( L_8 ) ;
V_5 -> V_18 = V_88 + 0x18 ;
V_5 -> V_11 = V_88 + 0x1c ;
V_89 = 29 ;
V_90 = F_40 ( 0 ) ;
break;
case 0x4a000040 :
F_38 ( L_9 ) ;
V_5 -> V_18 = V_88 + 0x40 ;
V_5 -> V_11 = V_88 + 0x48 ;
V_5 -> V_19 = V_88 + 0x50 ;
V_89 = 8 ;
V_90 = F_41 ( 0 ) ;
break;
case 0x560000a4 :
F_38 ( L_10 ) ;
V_88 = ( void * ) 0xfd000000 ;
V_5 -> V_11 = V_88 + 0xa4 ;
V_5 -> V_18 = V_88 + 0xa8 ;
V_89 = 24 ;
V_90 = F_39 ( 32 ) ;
break;
default:
F_11 ( L_11 ) ;
V_91 = - V_29 ;
goto V_94;
}
F_33 ( V_5 ) ;
V_5 -> V_16 = F_42 ( V_86 , V_89 , V_90 ,
0 , & V_95 ,
V_5 ) ;
if ( ! V_5 -> V_16 ) {
F_11 ( L_12 ) ;
V_91 = - V_29 ;
goto V_94;
}
F_43 ( F_25 ) ;
return V_5 ;
V_94:
F_44 ( V_5 ) ;
return F_37 ( V_91 ) ;
}
void T_6 F_45 ( void )
{
#ifdef F_46
F_47 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_35 ( NULL , & V_96 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_48 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
V_60 [ 1 ] = F_35 ( NULL , & V_97 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
F_35 ( NULL , & V_98 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
}
void T_6 F_49 ( void )
{
F_34 ( L_14 ) ;
#ifdef F_46
F_47 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_35 ( NULL , & V_99 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_48 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_35 ( NULL , & V_100 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_35 ( NULL , & V_101 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
}
void T_6 F_50 ( void )
{
F_34 ( L_15 ) ;
#ifdef F_46
F_47 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_35 ( NULL , & V_102 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_48 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_35 ( NULL , & V_98 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_35 ( NULL , & V_103 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
V_60 [ 2 ] = F_35 ( NULL , & V_104 [ 0 ] ,
NULL , 0x4a000040 ) ;
}
void T_6 F_51 ( void )
{
F_34 ( L_16 ) ;
#ifdef F_46
F_47 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_35 ( NULL , & V_105 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_48 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_35 ( NULL , & V_98 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_35 ( NULL , & V_106 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
}
void T_6 F_52 ( void )
{
F_34 ( L_17 ) ;
#ifdef F_46
F_47 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_35 ( NULL , & V_107 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_48 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_35 ( NULL , & V_98 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_35 ( NULL , & V_108 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
}
void T_6 F_53 ( void )
{
F_34 ( L_18 ) ;
#ifdef F_46
F_47 ( V_64 ) ;
#endif
V_60 [ 0 ] = F_35 ( NULL , & V_109 [ 0 ] , NULL ,
0x4a000000 ) ;
if ( F_48 ( V_60 [ 0 ] ) ) {
F_11 ( L_13 ) ;
return;
}
F_35 ( NULL , & V_98 [ 0 ] , V_60 [ 0 ] , 0x560000a4 ) ;
V_60 [ 1 ] = F_35 ( NULL , & V_110 [ 0 ] ,
V_60 [ 0 ] , 0x4a000018 ) ;
}
static int F_54 ( struct V_66 * V_67 , unsigned int V_68 ,
T_5 V_69 )
{
unsigned int V_111 = V_69 / 32 ;
unsigned int V_112 = V_69 % 32 ;
struct V_4 * V_5 = V_60 [ V_111 ] ;
struct V_4 * V_6 = V_5 -> V_7 ;
struct V_3 * V_1 = & V_5 -> V_13 [ V_112 ] ;
V_1 -> V_5 = V_5 ;
V_1 -> V_12 = V_112 ;
if ( ! V_6 )
F_30 ( V_68 , & V_79 , V_25 ) ;
else
F_30 ( V_68 , & V_78 ,
V_25 ) ;
F_31 ( V_68 , V_1 ) ;
return 0 ;
}
static int F_55 ( struct V_66 * V_113 , struct V_85 * V_52 ,
const T_4 * V_114 , unsigned int V_115 ,
T_5 * V_116 , unsigned int * V_117 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
struct V_3 * V_1 ;
struct V_3 * V_71 ;
int V_10 ;
if ( F_56 ( V_115 < 4 ) )
return - V_29 ;
if ( V_114 [ 0 ] > 2 || ! V_60 [ V_114 [ 0 ] ] ) {
F_11 ( L_19 , V_114 [ 0 ] ) ;
return - V_29 ;
}
V_5 = V_60 [ V_114 [ 0 ] ] ;
* V_116 = V_114 [ 0 ] * 32 + V_114 [ 2 ] ;
* V_117 = V_114 [ 3 ] & V_118 ;
V_6 = V_5 -> V_7 ;
if ( V_6 ) {
V_1 = & V_5 -> V_13 [ V_114 [ 2 ] ] ;
V_1 -> V_14 = V_114 [ 1 ] ;
V_71 = & V_6 -> V_13 [ V_1 -> V_14 ] ;
V_71 -> V_51 = V_5 ;
V_71 -> V_15 |= ( 1UL << V_114 [ 2 ] ) ;
V_10 = F_57 ( V_6 -> V_16 , V_114 [ 1 ] ) ;
if ( V_10 < 0 ) {
F_11 ( L_20 ) ;
return V_10 ;
}
F_32 ( V_10 , F_16 ) ;
}
return 0 ;
}
static int T_6 F_58 ( struct V_85 * V_86 ,
struct V_85 * V_119 ,
struct V_120 * V_121 , int V_122 )
{
struct V_4 * V_5 ;
struct V_120 * V_123 ;
struct V_66 * V_16 ;
void T_1 * V_124 ;
int V_84 ;
V_124 = F_59 ( V_86 , 0 ) ;
if ( ! V_124 ) {
F_11 ( L_21 ) ;
return - V_29 ;
}
V_16 = F_60 ( V_86 , V_122 * 32 ,
& V_125 , NULL ) ;
if ( ! V_16 ) {
F_11 ( L_12 ) ;
return - V_29 ;
}
for ( V_84 = 0 ; V_84 < V_122 ; V_84 ++ ) {
V_123 = & V_121 [ V_84 ] ;
F_38 ( L_22 , V_123 -> V_126 ) ;
V_5 = F_36 ( sizeof( struct V_4 ) , V_92 ) ;
if ( ! V_5 )
return - V_93 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_13 = F_36 ( sizeof( struct V_3 ) * 32 ,
V_92 ) ;
if ( ! V_5 -> V_13 ) {
F_44 ( V_5 ) ;
return - V_93 ;
}
if ( V_123 -> V_7 ) {
V_5 -> V_18 = V_124 + V_123 -> V_12 ;
V_5 -> V_11 = V_124 + V_123 -> V_12 + 0x4 ;
if ( * ( V_123 -> V_7 ) ) {
V_5 -> V_7 = * ( V_123 -> V_7 ) ;
} else {
F_13 ( L_23 ,
V_123 -> V_126 ) ;
F_44 ( V_5 -> V_13 ) ;
F_44 ( V_5 ) ;
continue;
}
} else {
V_5 -> V_18 = V_124 + V_123 -> V_12 ;
V_5 -> V_11 = V_124 + V_123 -> V_12 + 0x08 ;
V_5 -> V_19 = V_124 + V_123 -> V_12 + 0x10 ;
}
F_33 ( V_5 ) ;
V_60 [ V_84 ] = V_5 ;
}
F_43 ( F_25 ) ;
return 0 ;
}
int T_6 F_61 ( struct V_85 * V_86 ,
struct V_85 * V_119 )
{
return F_58 ( V_86 , V_119 ,
V_127 , F_62 ( V_127 ) ) ;
}
int T_6 F_63 ( struct V_85 * V_86 ,
struct V_85 * V_119 )
{
return F_58 ( V_86 , V_119 ,
V_128 , F_62 ( V_128 ) ) ;
}
