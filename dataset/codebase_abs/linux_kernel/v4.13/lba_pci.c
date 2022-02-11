static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( NULL == V_2 )
return;
F_2 ( V_5 L_1 , V_2 -> V_6 ) ;
for ( V_4 = V_3 ; V_4 ; -- V_4 ) F_2 ( L_2 ) ;
F_2 ( V_5 L_3 , V_2 ,
( long ) V_2 -> V_7 , ( long ) V_2 -> V_8 , V_2 -> V_9 ) ;
F_1 ( V_2 -> V_10 , V_3 + 2 ) ;
F_1 ( V_2 -> V_11 , V_3 ) ;
}
static int F_3 ( T_1 V_12 , T_1 V_13 , struct V_14 * V_3 )
{
T_1 V_15 = V_3 -> V_16 . V_17 -> V_18 . V_7 ;
T_1 V_19 = V_3 -> V_16 . V_17 -> V_18 . V_8 ;
if ( ( V_12 < V_15 ) ||
( V_12 > V_19 ) ||
( ( V_12 - V_15 ) >= V_20 ) ) {
return 0 ;
}
return 1 ;
}
static unsigned int
F_4 ( struct V_14 * V_3 , T_2 V_21 , T_1 V_22 , T_2 V_23 )
{
T_2 V_24 = ~ 0U ;
int error = 0 ;
T_2 V_25 = 0 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
F_5 ( V_3 , V_21 ) ;
F_6 ( V_3 , V_21 ) ;
F_7 ( V_3 , V_3 -> V_16 . V_28 , V_21 , error ) ;
if ( ! error ) {
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
F_8 ( V_3 , V_21 | V_22 ) ;
switch ( V_23 ) {
case 1 : V_24 = ( T_2 ) F_9 ( V_29 + ( V_22 & 3 ) ) ; break;
case 2 : V_24 = ( T_2 ) F_10 ( V_29 + ( V_22 & 2 ) ) ; break;
case 4 : V_24 = F_11 ( V_29 ) ; break;
}
}
F_12 ( V_3 , V_3 -> V_16 . V_28 ) ;
return ( V_24 ) ;
}
static int F_13 ( struct V_31 * V_12 , unsigned int V_32 , int V_33 , int V_23 , T_2 * V_24 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
T_2 V_35 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 . V_7 ;
T_2 V_21 = F_16 ( V_35 , V_32 ) ;
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
if ( ( V_33 > 255 ) || ( V_32 > 255 ) )
return - V_36 ;
{
* V_24 = F_4 ( V_3 , V_21 , V_33 , V_23 ) ;
F_17 ( L_4 , V_37 , V_21 , V_33 , * V_24 ) ;
return 0 ;
}
if ( F_18 ( V_3 ) && ! F_3 ( V_12 -> V_18 . V_7 , V_32 , V_3 ) ) {
F_17 ( L_5 , V_37 , V_21 , V_33 ) ;
* V_24 = ~ 0U ;
return ( 0 ) ;
}
F_8 ( V_3 , V_21 | V_33 ) ;
switch( V_23 ) {
case 1 : * V_24 = F_9 ( V_29 + ( V_33 & 3 ) ) ; break;
case 2 : * V_24 = F_10 ( V_29 + ( V_33 & 2 ) ) ; break;
case 4 : * V_24 = F_11 ( V_29 ) ; break;
}
F_17 ( L_6 , V_37 , V_21 , V_33 , * V_24 ) ;
return 0 ;
}
static void
F_19 ( struct V_14 * V_3 , T_2 V_21 , T_1 V_22 , T_2 V_24 , T_2 V_23 )
{
int error = 0 ;
T_2 V_25 = 0 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
F_5 ( V_3 , V_21 ) ;
F_8 ( V_3 , V_21 | V_22 ) ;
switch ( V_23 ) {
case 1 : F_20 ( V_24 , V_29 + ( V_22 & 3 ) ) ; break;
case 2 : F_21 ( V_24 , V_29 + ( V_22 & 2 ) ) ; break;
case 4 : F_22 ( V_24 , V_29 ) ; break;
}
F_7 ( V_3 , V_3 -> V_16 . V_28 , V_21 , error ) ;
F_12 ( V_3 , V_3 -> V_16 . V_28 ) ;
}
static int F_23 ( struct V_31 * V_12 , unsigned int V_32 , int V_33 , int V_23 , T_2 V_24 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
T_2 V_35 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 . V_7 ;
T_2 V_21 = F_16 ( V_35 , V_32 ) ;
if ( ( V_33 > 255 ) || ( V_32 > 255 ) )
return - V_36 ;
if ( ! F_18 ( V_3 ) ) {
F_19 ( V_3 , V_21 , V_33 , ( T_2 ) V_24 , V_23 ) ;
F_17 ( L_7 , V_37 , V_21 , V_33 , V_24 ) ;
return 0 ;
}
if ( F_18 ( V_3 ) && ( ! F_3 ( V_12 -> V_18 . V_7 , V_32 , V_3 ) ) ) {
F_17 ( L_8 , V_37 , V_21 , V_33 , V_24 ) ;
return 1 ;
}
F_17 ( L_9 , V_37 , V_21 , V_33 , V_24 ) ;
F_8 ( V_3 , V_21 | V_33 ) ;
switch( V_23 ) {
case 1 : F_20 ( V_24 , V_3 -> V_16 . V_28 + V_30 + ( V_33 & 3 ) ) ;
break;
case 2 : F_21 ( V_24 , V_3 -> V_16 . V_28 + V_30 + ( V_33 & 2 ) ) ;
break;
case 4 : F_22 ( V_24 , V_3 -> V_16 . V_28 + V_30 ) ;
break;
}
V_38 = F_11 ( V_3 -> V_16 . V_28 + V_39 ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_12 , unsigned int V_32 , int V_33 , int V_23 , T_2 * V_24 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
T_2 V_35 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 . V_7 ;
T_2 V_21 = F_16 ( V_35 , V_32 ) ;
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
if ( ( V_33 > 255 ) || ( V_32 > 255 ) )
return - V_36 ;
F_25 ( V_3 , V_21 | V_33 ) ;
switch( V_23 ) {
case 1 :
* V_24 = F_9 ( V_29 + ( V_33 & 3 ) ) ;
break;
case 2 :
* V_24 = F_10 ( V_29 + ( V_33 & 2 ) ) ;
break;
case 4 :
* V_24 = F_11 ( V_29 ) ; break;
break;
}
F_17 ( L_10 , V_21 , V_33 , * V_24 ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_12 , unsigned int V_32 , int V_33 , int V_23 , T_2 V_24 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
T_2 V_35 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 . V_7 ;
T_2 V_21 = F_16 ( V_35 , V_32 ) ;
if ( ( V_33 > 255 ) || ( V_32 > 255 ) )
return - V_36 ;
F_17 ( L_11 , V_37 , V_21 , V_33 , V_24 ) ;
F_25 ( V_3 , V_21 | V_33 ) ;
switch( V_23 ) {
case 1 :
F_20 ( V_24 , V_29 + ( V_33 & 3 ) ) ;
break;
case 2 :
F_21 ( V_24 , V_29 + ( V_33 & 2 ) ) ;
break;
case 4 :
F_22 ( V_24 , V_29 ) ;
break;
}
V_38 = F_27 ( V_3 -> V_16 . V_28 + V_39 ) ;
return 0 ;
}
static void
F_28 ( void )
{
F_29 ( V_40 L_12 ) ;
}
static unsigned long
F_30 ( struct V_1 * V_41 , struct V_1 * V_42 )
{
unsigned long V_7 = V_42 -> V_7 ;
unsigned long V_8 = V_42 -> V_8 ;
struct V_1 * V_43 = V_41 -> V_10 ;
if ( V_8 <= V_7 || V_7 < V_41 -> V_7 || ! V_43 )
return 0 ;
while ( V_43 && V_43 -> V_8 < V_7 )
V_43 = V_43 -> V_11 ;
if ( ! V_43 ) return 0 ;
if ( V_43 -> V_7 >= V_8 ) return 0 ;
if ( V_43 -> V_7 <= V_7 ) {
V_42 -> V_7 = V_43 -> V_8 + 1 ;
if ( V_43 -> V_8 >= V_8 ) {
return 1 ;
}
}
if ( V_43 -> V_8 < V_8 ) {
V_42 -> V_8 = V_43 -> V_7 - 1 ;
}
F_2 ( V_44 L_13
L_14 ,
V_7 , V_8 ,
( long ) V_42 -> V_7 , ( long ) V_42 -> V_8 ) ;
return 0 ;
}
static unsigned long
F_31 ( unsigned long V_7 , unsigned long V_8 , unsigned long V_45 )
{
struct V_1 * V_43 ;
if ( V_46 . V_47 < V_48 )
return V_8 ;
F_32 ( L_15 ,
V_8 - V_7 , V_45 ) ;
V_45 = F_33 ( V_45 + 1 , 256UL * 1024 * 1024 ) ;
F_32 ( L_16 , V_7 , V_8 ) ;
V_8 += V_45 ;
if ( V_8 < V_7 )
V_8 = - 1ULL ;
F_32 ( L_17 , V_7 , V_8 ) ;
for ( V_43 = V_49 . V_10 ; V_43 ; V_43 = V_43 -> V_11 ) {
F_32 ( L_18 , V_43 ) ;
if ( V_43 -> V_7 == V_7 )
continue;
if ( V_43 -> V_8 < V_7 )
continue;
if ( V_43 -> V_7 > V_8 )
continue;
if ( V_8 >= V_43 -> V_7 )
V_8 = V_43 -> V_7 - 1 ;
}
F_34 ( L_19 , V_7 , V_8 ) ;
return V_8 ;
}
static void
F_35 ( struct V_31 * V_12 )
{
struct V_50 * V_51 ;
#ifdef F_36
T_4 V_52 ;
#endif
struct V_14 * V_53 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
F_29 ( L_20 ,
V_12 , ( int ) V_12 -> V_18 . V_7 , V_12 -> V_34 -> V_54 ) ;
if ( V_12 -> V_6 ) {
int V_4 ;
F_37 ( V_12 ) ;
for ( V_4 = V_55 ; V_4 < V_56 ; V_4 ++ )
F_38 ( V_12 -> V_57 , V_4 ) ;
} else {
int V_58 ;
F_29 ( L_21 ,
V_53 -> V_16 . V_59 . V_60 ,
V_53 -> V_16 . V_59 . V_7 , V_53 -> V_16 . V_59 . V_8 ,
V_53 -> V_16 . V_59 . V_9 ) ;
F_29 ( L_21 ,
V_53 -> V_16 . V_61 . V_60 ,
V_53 -> V_16 . V_61 . V_7 , V_53 -> V_16 . V_61 . V_8 ,
V_53 -> V_16 . V_61 . V_9 ) ;
V_58 = F_39 ( & V_62 , & ( V_53 -> V_16 . V_59 ) ) ;
if ( V_58 < 0 ) {
F_1 ( & V_62 , 2 ) ;
F_40 () ;
}
if ( V_53 -> V_16 . V_63 . V_9 ) {
V_58 = F_39 ( & V_49 ,
& ( V_53 -> V_16 . V_63 ) ) ;
if ( V_58 < 0 ) {
F_2 ( L_22
L_23 ,
( long ) V_53 -> V_16 . V_63 . V_7 ,
( long ) V_53 -> V_16 . V_63 . V_8 ) ;
}
}
if ( V_53 -> V_16 . V_61 . V_9 ) {
V_58 = F_39 ( & V_49 , & ( V_53 -> V_16 . V_61 ) ) ;
if ( V_58 < 0 ) {
F_2 ( V_64 L_22
L_24 ,
( long ) V_53 -> V_16 . V_61 . V_7 ,
( long ) V_53 -> V_16 . V_61 . V_8 ) ;
}
}
#ifdef F_41
if ( V_53 -> V_16 . V_65 . V_9 ) {
V_58 = F_39 ( & V_49 , & ( V_53 -> V_16 . V_65 ) ) ;
if ( V_58 < 0 ) {
F_2 ( L_22
L_25 ,
( long ) V_53 -> V_16 . V_65 . V_7 ,
( long ) V_53 -> V_16 . V_65 . V_8 ) ;
F_1 ( & V_49 , 2 ) ;
F_40 () ;
}
}
#endif
}
F_42 (dev, &bus->devices, bus_list) {
int V_4 ;
F_29 ( L_26 , F_43 ( V_51 ) ) ;
for ( V_4 = 0 ; V_4 < V_55 ; V_4 ++ ) {
struct V_1 * V_66 = & V_51 -> V_1 [ V_4 ] ;
if ( ! V_66 -> V_7 )
continue;
F_44 ( V_51 , V_4 ) ;
}
#ifdef F_36
( void ) F_45 ( V_51 , V_67 , & V_52 ) ;
V_12 -> V_68 &= ~ ( V_52 & V_69 ) ;
#endif
if ( ( V_51 -> V_70 >> 8 ) == V_71 ) {
F_46 ( V_51 ) ;
continue;
}
F_47 ( V_53 -> V_72 , V_51 ) ;
}
#ifdef F_36
if ( V_73 ) {
if ( V_12 -> V_6 ) {
T_1 V_74 ;
( void ) F_48 ( V_12 -> V_57 , V_75 , & V_74 ) ;
( void ) F_49 ( V_12 -> V_57 , V_75 , V_74 | V_69 ) ;
} else {
}
V_73 = V_76 ;
}
F_42 (dev, &bus->devices, bus_list) {
( void ) F_45 ( V_51 , V_77 , & V_52 ) ;
V_52 |= V_78 | V_79 | V_73 ;
( void ) F_50 ( V_51 , V_77 , V_52 ) ;
}
#endif
}
static void
F_51 ( struct V_80 * V_81 , struct V_14 * V_82 )
{
unsigned long V_83 ;
long V_84 ;
long V_52 ;
long V_85 ;
T_5 * V_86 ;
T_5 * V_87 ;
int V_4 ;
V_86 = F_52 ( sizeof( T_5 ) , V_88 ) ;
if ( ! V_86 )
return;
V_87 = F_52 ( sizeof( T_5 ) , V_88 ) ;
if ( ! V_87 ) {
F_53 ( V_86 ) ;
return;
}
V_52 = F_54 ( & V_83 , V_81 -> V_89 , V_81 -> V_90 ,
V_91 , V_86 ) ;
V_85 = V_86 -> V_92 [ 1 ] ;
V_52 |= F_54 ( & V_83 , V_81 -> V_89 , V_81 -> V_90 ,
V_93 , V_87 ) ;
V_84 = V_87 -> V_92 [ 1 ] ;
if ( V_52 != V_94 ) {
F_55 ( L_27 ) ;
}
if ( F_56 ( V_86 -> V_95 ) != V_96 ) {
F_55 ( L_28 ) ;
}
for ( V_4 = 0 ; V_4 < V_85 ; V_4 ++ ) {
struct {
unsigned long type ;
unsigned long V_7 ;
unsigned long V_8 ;
} * V_97 , * V_98 ;
struct V_1 * V_2 ;
V_97 = ( void * ) & ( V_86 -> V_92 [ 2 + V_4 * 3 ] ) ;
V_98 = ( void * ) & ( V_87 -> V_92 [ 2 + V_4 * 3 ] ) ;
switch( V_97 -> type & 0xff ) {
case V_99 :
V_82 -> V_16 . V_100 . V_7 = V_97 -> V_7 ;
V_82 -> V_16 . V_100 . V_8 = V_97 -> V_8 ;
V_82 -> V_16 . V_100 . V_9 = V_101 ;
break;
case V_102 :
if ( ! V_82 -> V_16 . V_61 . V_9 ) {
unsigned long V_45 ;
V_45 = ~ F_11 ( V_82 -> V_16 . V_28
+ V_103 ) ;
if ( ( V_97 -> V_8 - V_97 -> V_7 ) != V_45 )
V_97 -> V_8 = F_31 ( V_97 -> V_7 ,
V_97 -> V_8 , V_45 ) ;
sprintf ( V_82 -> V_16 . V_104 ,
L_29 ,
( int ) V_82 -> V_16 . V_100 . V_7 ) ;
V_82 -> V_16 . V_105 = V_97 -> V_7 -
V_98 -> V_7 ;
V_2 = & V_82 -> V_16 . V_61 ;
V_2 -> V_60 = V_82 -> V_16 . V_104 ;
} else if ( ! V_82 -> V_16 . V_63 . V_9 ) {
sprintf ( V_82 -> V_16 . V_106 ,
L_30 ,
( int ) V_82 -> V_16 . V_100 . V_7 ) ;
V_2 = & V_82 -> V_16 . V_63 ;
V_2 -> V_60 = V_82 -> V_16 . V_106 ;
} else {
F_2 (KERN_WARNING MODULE_NAME
L_31 ) ;
break;
}
V_2 -> V_7 = V_97 -> V_7 ;
V_2 -> V_8 = V_97 -> V_8 ;
V_2 -> V_9 = V_107 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
case V_108 :
sprintf ( V_82 -> V_16 . V_109 , L_32 ,
( int ) V_82 -> V_16 . V_100 . V_7 ) ;
V_2 = & V_82 -> V_16 . V_65 ;
V_2 -> V_60 = V_82 -> V_16 . V_109 ;
V_2 -> V_7 = V_97 -> V_7 ;
V_2 -> V_8 = V_97 -> V_8 ;
V_2 -> V_9 = V_107 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
case V_110 :
F_2 (KERN_WARNING MODULE_NAME
L_33 ,
i, p->start) ;
break;
case V_111 :
V_82 -> V_112 = F_57 ( V_97 -> V_7 , 64 * 1024 * 1024 ) ;
sprintf ( V_82 -> V_16 . V_113 , L_34 ,
( int ) V_82 -> V_16 . V_100 . V_7 ) ;
V_2 = & V_82 -> V_16 . V_59 ;
V_2 -> V_60 = V_82 -> V_16 . V_113 ;
V_2 -> V_7 = F_58 ( V_82 -> V_16 . V_114 ) ;
V_2 -> V_8 = V_2 -> V_7 + V_115 - 1 ;
V_2 -> V_9 = V_116 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
default:
F_2 (KERN_WARNING MODULE_NAME
L_35 ,
i, p->type & 0xff ) ;
break;
}
}
F_53 ( V_86 ) ;
F_53 ( V_87 ) ;
}
static void
F_59 ( struct V_80 * V_81 , struct V_14 * V_82 )
{
struct V_1 * V_2 ;
int V_117 ;
V_82 -> V_16 . V_105 = V_118 ;
V_117 = F_11 ( V_82 -> V_16 . V_28 + V_119 ) ;
V_2 = & ( V_82 -> V_16 . V_100 ) ;
V_2 -> V_60 = L_36 ;
V_2 -> V_7 = V_117 & 0xff ;
V_2 -> V_8 = ( V_117 >> 8 ) & 0xff ;
V_2 -> V_9 = V_101 ;
V_2 = & ( V_82 -> V_16 . V_61 ) ;
sprintf ( V_82 -> V_16 . V_104 , L_29 ,
( int ) V_82 -> V_16 . V_100 . V_7 ) ;
V_2 -> V_60 = V_82 -> V_16 . V_104 ;
#if 1
F_60 ( V_81 , V_2 ) ;
#else
V_2 -> V_7 = F_11 ( V_82 -> V_16 . V_28 + V_120 ) ;
if ( V_2 -> V_7 & 1 ) {
unsigned long V_121 ;
V_2 -> V_9 = V_107 ;
V_2 -> V_7 &= V_122 ;
V_2 -> V_7 = F_61 ( F_62 ( V_82 ) , V_2 -> V_7 ) ;
V_121 = ~ F_11 ( V_82 -> V_16 . V_28 + V_103 ) ;
V_121 /= V_123 ;
V_2 -> V_7 += ( V_121 + 1 ) * F_63 ( V_81 -> V_124 . V_7 ) ;
V_2 -> V_8 = V_2 -> V_7 + V_121 ;
} else {
V_2 -> V_8 = V_2 -> V_7 = 0 ;
}
#endif
V_2 = & ( V_82 -> V_16 . V_63 ) ;
sprintf ( V_82 -> V_16 . V_106 , L_30 ,
( int ) V_82 -> V_16 . V_100 . V_7 ) ;
V_2 -> V_60 = V_82 -> V_16 . V_106 ;
#if 1
F_64 ( V_81 , V_2 ) ;
#else
V_2 -> V_7 = F_11 ( V_82 -> V_16 . V_28 + V_125 ) ;
if ( V_2 -> V_7 & 1 ) {
unsigned long V_121 ;
V_2 -> V_9 = V_107 ;
V_2 -> V_7 &= V_122 ;
V_2 -> V_7 = F_61 ( F_62 ( V_82 ) , V_2 -> V_7 ) ;
V_121 = F_11 ( V_82 -> V_16 . V_28 + V_126 ) ;
V_2 -> V_8 = V_2 -> V_7 + ~ V_121 ;
}
#endif
V_2 = & ( V_82 -> V_16 . V_59 ) ;
sprintf ( V_82 -> V_16 . V_113 , L_34 ,
( int ) V_82 -> V_16 . V_100 . V_7 ) ;
V_2 -> V_60 = V_82 -> V_16 . V_113 ;
V_2 -> V_9 = V_116 ;
V_2 -> V_7 = F_11 ( V_82 -> V_16 . V_28 + V_127 ) & ~ 1L ;
V_2 -> V_8 = V_2 -> V_7 + ( F_11 ( V_82 -> V_16 . V_28 + V_128 ) ^ ( V_115 - 1 ) ) ;
V_117 = F_58 ( V_82 -> V_16 . V_114 ) ;
V_2 -> V_7 |= V_117 ;
V_2 -> V_8 |= V_117 ;
}
static int T_6
F_65 ( struct V_14 * V_3 )
{
T_2 V_129 ;
T_2 V_130 ;
#if 0
printk(KERN_DEBUG "LBA %lx STAT_CTL %Lx ERROR_CFG %Lx STATUS %Lx DMA_CTL %Lx\n",
d->hba.base_addr,
READ_REG64(d->hba.base_addr + LBA_STAT_CTL),
READ_REG64(d->hba.base_addr + LBA_ERROR_CONFIG),
READ_REG64(d->hba.base_addr + LBA_ERROR_STATUS),
READ_REG64(d->hba.base_addr + LBA_DMA_CTL) );
printk(KERN_DEBUG " ARB mask %Lx pri %Lx mode %Lx mtlt %Lx\n",
READ_REG64(d->hba.base_addr + LBA_ARB_MASK),
READ_REG64(d->hba.base_addr + LBA_ARB_PRI),
READ_REG64(d->hba.base_addr + LBA_ARB_MODE),
READ_REG64(d->hba.base_addr + LBA_ARB_MTLT) );
printk(KERN_DEBUG " HINT cfg 0x%Lx\n",
READ_REG64(d->hba.base_addr + LBA_HINT_CFG));
printk(KERN_DEBUG " HINT reg ");
{ int i;
for (i=LBA_HINT_BASE; i< (14*8 + LBA_HINT_BASE); i+=8)
printk(" %Lx", READ_REG64(d->hba.base_addr + i));
}
printk("\n");
#endif
#ifdef F_41
#endif
V_130 = F_11 ( V_3 -> V_16 . V_28 + V_131 + 4 ) & 1 ;
if ( V_130 ) {
F_2 ( V_5 L_37 ) ;
}
V_129 = F_11 ( V_3 -> V_16 . V_28 + V_132 ) ;
if ( V_129 & V_133 ) {
F_2 ( V_5 L_38 ) ;
V_129 &= ~ V_133 ;
F_22 ( V_129 , V_3 -> V_16 . V_28 + V_132 ) ;
}
V_129 = F_11 ( V_3 -> V_16 . V_28 + V_131 ) ;
F_22 ( V_129 | V_134 , V_3 -> V_16 . V_28 + V_131 ) ;
if ( V_130 )
F_66 ( V_135 ) ;
if ( 0 == F_11 ( V_3 -> V_16 . V_28 + V_136 ) ) {
F_2 ( V_5 L_39 ) ;
F_22 ( 0x3 , V_3 -> V_16 . V_28 + V_136 ) ;
}
return 0 ;
}
static int T_6
F_67 ( struct V_80 * V_51 )
{
struct V_14 * V_82 ;
F_68 ( V_137 ) ;
struct V_31 * V_138 ;
struct V_139 * V_140 ;
T_2 V_141 ;
void * V_142 ;
char * V_143 ;
void T_3 * V_144 = F_57 ( V_51 -> V_124 . V_7 , 4096 ) ;
int V_145 ;
V_141 = F_11 ( V_144 + V_146 ) ;
if ( F_69 ( V_51 ) ) {
V_141 &= 0xf ;
switch ( V_141 ) {
case 0 : V_143 = L_40 ; break;
case 1 : V_143 = L_41 ; break;
case 2 : V_143 = L_42 ; break;
case 3 : V_143 = L_43 ; break;
case 4 : V_143 = L_44 ; break;
case 5 : V_143 = L_45 ; break;
default: V_143 = L_46 ;
}
F_2 ( V_147 L_47 ,
V_143 , V_141 & 0xf , ( long ) V_51 -> V_124 . V_7 ) ;
if ( V_141 < 2 ) {
F_2 ( V_44 L_48
L_49 ) ;
}
#if 0
if (func_class > 4) {
cfg_ops = &mercury_cfg_ops;
} else
#endif
{
V_140 = & V_148 ;
}
} else if ( F_70 ( V_51 ) || F_71 ( V_51 ) ) {
int V_149 , V_150 ;
V_141 &= 0xff ;
V_149 = V_141 >> 4 , V_150 = V_141 & 0xf ;
F_2 ( V_147 L_50 ,
F_70 ( V_51 ) ? L_51 : L_52 , V_149 ,
V_150 , V_141 , ( long ) V_51 -> V_124 . V_7 ) ;
V_140 = & V_151 ;
} else {
F_2 ( V_64 L_53 ,
( long ) V_51 -> V_124 . V_7 ) ;
return - V_152 ;
}
V_142 = F_72 ( V_51 -> V_124 . V_7 + V_153 ) ;
V_82 = F_52 ( sizeof( struct V_14 ) , V_88 ) ;
if ( ! V_82 ) {
F_2 ( V_64 L_54 ) ;
return ( 1 ) ;
}
V_82 -> V_154 = V_141 ;
V_82 -> V_16 . V_28 = V_144 ;
V_82 -> V_16 . V_51 = V_51 ;
V_82 -> V_72 = V_142 ;
V_82 -> V_16 . V_155 = F_73 ( V_51 ) ;
F_74 ( V_51 , V_82 ) ;
V_156 = & V_157 ;
F_75 ( F_62 ( V_82 ) ) ;
F_76 ( & V_82 -> V_158 ) ;
if ( F_65 ( V_82 ) )
return ( 1 ) ;
if ( F_77 () ) {
V_159 = & V_160 ;
F_51 ( V_51 , V_82 ) ;
} else {
if ( ! V_161 ) {
V_161 = F_57 ( V_162 , 64 * 1024 ) ;
V_159 = & V_163 ;
}
F_59 ( V_51 , V_82 ) ;
}
if ( V_82 -> V_16 . V_100 . V_7 < V_164 )
V_82 -> V_16 . V_100 . V_7 = V_164 ;
if ( F_30 ( & V_49 ,
& ( V_82 -> V_16 . V_61 ) ) ) {
F_2 ( V_44 L_55 ,
( long ) V_82 -> V_16 . V_61 . V_7 ,
( long ) V_82 -> V_16 . V_61 . V_8 ) ;
V_82 -> V_16 . V_61 . V_9 = 0 ;
}
F_78 ( & V_137 , & V_82 -> V_16 . V_59 ,
F_58 ( V_82 -> V_16 . V_114 ) ) ;
if ( V_82 -> V_16 . V_63 . V_9 )
F_78 ( & V_137 , & V_82 -> V_16 . V_63 ,
V_82 -> V_16 . V_105 ) ;
if ( V_82 -> V_16 . V_61 . V_9 )
F_78 ( & V_137 , & V_82 -> V_16 . V_61 ,
V_82 -> V_16 . V_105 ) ;
if ( V_82 -> V_16 . V_65 . V_9 ) {
}
F_79 ( & V_137 , & V_82 -> V_16 . V_100 ) ;
V_51 -> V_51 . V_54 = V_82 ;
V_138 = V_82 -> V_16 . V_17 =
F_80 ( & V_51 -> V_51 , V_82 -> V_16 . V_100 . V_7 ,
V_140 , NULL , & V_137 ) ;
if ( ! V_138 ) {
F_81 ( & V_137 ) ;
return 0 ;
}
V_145 = F_82 ( V_138 ) ;
if ( F_77 () ) {
F_83 ( L_56 ) ;
F_84 ( V_138 ) ;
F_83 ( L_57 ) ;
F_85 ( V_138 ) ;
#ifdef F_86
F_83 ( L_58 ) ;
F_1 ( & V_82 -> V_16 . V_59 , 2 ) ;
F_83 ( L_59 ) ;
F_1 ( & V_82 -> V_16 . V_61 , 2 ) ;
#endif
}
if ( V_140 == & V_148 ) {
V_82 -> V_9 |= V_165 ;
}
V_164 = V_145 + 1 ;
F_87 ( V_138 ) ;
return 0 ;
}
void T_6 F_88 ( void )
{
F_89 ( & V_166 ) ;
}
void F_90 ( struct V_80 * V_167 , T_2 V_168 , T_2 V_169 )
{
void T_3 * V_28 = F_57 ( V_167 -> V_124 . V_7 , 4096 ) ;
V_169 <<= 2 ;
F_91 ( ( V_168 & 0x001fffff ) != 0 ) ;
F_91 ( ( V_169 & 0x001fffff ) != 0 ) ;
F_29 ( L_60 , V_37 , V_168 , V_169 ) ;
F_22 ( V_169 , V_28 + V_170 ) ;
F_22 ( V_168 , V_28 + V_171 ) ;
F_92 ( V_28 ) ;
}
