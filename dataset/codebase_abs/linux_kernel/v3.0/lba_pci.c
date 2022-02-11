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
T_1 V_15 = V_3 -> V_16 . V_17 -> V_18 ;
T_1 V_19 = V_3 -> V_16 . V_17 -> V_20 ;
if ( ( V_12 < V_15 ) ||
( V_12 > V_19 ) ||
( ( V_12 - V_15 ) >= V_21 ) ) {
return 0 ;
}
return 1 ;
}
static unsigned int
F_4 ( struct V_14 * V_3 , T_2 V_22 , T_1 V_23 , T_2 V_24 )
{
T_2 V_25 = ~ 0U ;
int error = 0 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
T_2 V_28 = 0 ;
F_5 ( V_3 , V_22 ) ;
F_6 ( V_3 , V_22 ) ;
F_7 ( V_3 , V_3 -> V_16 . V_29 , V_22 , error ) ;
if ( ! error ) {
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
F_8 ( V_3 , V_22 | V_23 ) ;
switch ( V_24 ) {
case 1 : V_25 = ( T_2 ) F_9 ( V_30 + ( V_23 & 3 ) ) ; break;
case 2 : V_25 = ( T_2 ) F_10 ( V_30 + ( V_23 & 2 ) ) ; break;
case 4 : V_25 = F_11 ( V_30 ) ; break;
}
}
F_12 ( V_3 , V_3 -> V_16 . V_29 ) ;
return ( V_25 ) ;
}
static int F_13 ( struct V_32 * V_12 , unsigned int V_33 , int V_34 , int V_24 , T_2 * V_25 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
T_2 V_36 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 ;
T_2 V_22 = F_16 ( V_36 , V_33 ) ;
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
if ( ( V_34 > 255 ) || ( V_33 > 255 ) )
return - V_37 ;
{
* V_25 = F_4 ( V_3 , V_22 , V_34 , V_24 ) ;
F_17 ( L_4 , V_38 , V_22 , V_34 , * V_25 ) ;
return 0 ;
}
if ( F_18 ( V_3 ) && ! F_3 ( V_12 -> V_18 , V_33 , V_3 ) ) {
F_17 ( L_5 , V_38 , V_22 , V_34 ) ;
* V_25 = ~ 0U ;
return ( 0 ) ;
}
F_8 ( V_3 , V_22 | V_34 ) ;
switch( V_24 ) {
case 1 : * V_25 = F_9 ( V_30 + ( V_34 & 3 ) ) ; break;
case 2 : * V_25 = F_10 ( V_30 + ( V_34 & 2 ) ) ; break;
case 4 : * V_25 = F_11 ( V_30 ) ; break;
}
F_17 ( L_6 , V_38 , V_22 , V_34 , * V_25 ) ;
return 0 ;
}
static void
F_19 ( struct V_14 * V_3 , T_2 V_22 , T_1 V_23 , T_2 V_25 , T_2 V_24 )
{
int error = 0 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
T_2 V_28 = 0 ;
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
F_5 ( V_3 , V_22 ) ;
F_8 ( V_3 , V_22 | V_23 ) ;
switch ( V_24 ) {
case 1 : F_20 ( V_25 , V_30 + ( V_23 & 3 ) ) ; break;
case 2 : F_21 ( V_25 , V_30 + ( V_23 & 2 ) ) ; break;
case 4 : F_22 ( V_25 , V_30 ) ; break;
}
F_7 ( V_3 , V_3 -> V_16 . V_29 , V_22 , error ) ;
F_12 ( V_3 , V_3 -> V_16 . V_29 ) ;
}
static int F_23 ( struct V_32 * V_12 , unsigned int V_33 , int V_34 , int V_24 , T_2 V_25 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
T_2 V_36 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 ;
T_2 V_22 = F_16 ( V_36 , V_33 ) ;
if ( ( V_34 > 255 ) || ( V_33 > 255 ) )
return - V_37 ;
if ( ! F_18 ( V_3 ) ) {
F_19 ( V_3 , V_22 , V_34 , ( T_2 ) V_25 , V_24 ) ;
F_17 ( L_7 , V_38 , V_22 , V_34 , V_25 ) ;
return 0 ;
}
if ( F_18 ( V_3 ) && ( ! F_3 ( V_12 -> V_18 , V_33 , V_3 ) ) ) {
F_17 ( L_8 , V_38 , V_22 , V_34 , V_25 ) ;
return 1 ;
}
F_17 ( L_9 , V_38 , V_22 , V_34 , V_25 ) ;
F_8 ( V_3 , V_22 | V_34 ) ;
switch( V_24 ) {
case 1 : F_20 ( V_25 , V_3 -> V_16 . V_29 + V_31 + ( V_34 & 3 ) ) ;
break;
case 2 : F_21 ( V_25 , V_3 -> V_16 . V_29 + V_31 + ( V_34 & 2 ) ) ;
break;
case 4 : F_22 ( V_25 , V_3 -> V_16 . V_29 + V_31 ) ;
break;
}
V_39 = F_11 ( V_3 -> V_16 . V_29 + V_40 ) ;
return 0 ;
}
static int F_24 ( struct V_32 * V_12 , unsigned int V_33 , int V_34 , int V_24 , T_2 * V_25 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
T_2 V_36 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 ;
T_2 V_22 = F_16 ( V_36 , V_33 ) ;
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
if ( ( V_34 > 255 ) || ( V_33 > 255 ) )
return - V_37 ;
F_25 ( V_3 , V_22 | V_34 ) ;
switch( V_24 ) {
case 1 :
* V_25 = F_9 ( V_30 + ( V_34 & 3 ) ) ;
break;
case 2 :
* V_25 = F_10 ( V_30 + ( V_34 & 2 ) ) ;
break;
case 4 :
* V_25 = F_11 ( V_30 ) ; break;
break;
}
F_17 ( L_10 , V_22 , V_34 , * V_25 ) ;
return 0 ;
}
static int F_26 ( struct V_32 * V_12 , unsigned int V_33 , int V_34 , int V_24 , T_2 V_25 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
T_2 V_36 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 ;
T_2 V_22 = F_16 ( V_36 , V_33 ) ;
if ( ( V_34 > 255 ) || ( V_33 > 255 ) )
return - V_37 ;
F_17 ( L_11 , V_38 , V_22 , V_34 , V_25 ) ;
F_25 ( V_3 , V_22 | V_34 ) ;
switch( V_24 ) {
case 1 :
F_20 ( V_25 , V_30 + ( V_34 & 3 ) ) ;
break;
case 2 :
F_21 ( V_25 , V_30 + ( V_34 & 2 ) ) ;
break;
case 4 :
F_22 ( V_25 , V_30 ) ;
break;
}
V_39 = F_27 ( V_3 -> V_16 . V_29 + V_40 ) ;
return 0 ;
}
static void
F_28 ( void )
{
F_29 ( V_41 L_12 ) ;
}
static unsigned long
F_30 ( struct V_1 * V_42 , struct V_1 * V_43 )
{
unsigned long V_7 = V_43 -> V_7 ;
unsigned long V_8 = V_43 -> V_8 ;
struct V_1 * V_44 = V_42 -> V_10 ;
if ( V_8 <= V_7 || V_7 < V_42 -> V_7 || ! V_44 )
return 0 ;
while ( V_44 && V_44 -> V_8 < V_7 )
V_44 = V_44 -> V_11 ;
if ( ! V_44 ) return 0 ;
if ( V_44 -> V_7 >= V_8 ) return 0 ;
if ( V_44 -> V_7 <= V_7 ) {
V_43 -> V_7 = V_44 -> V_8 + 1 ;
if ( V_44 -> V_8 >= V_8 ) {
return 1 ;
}
}
if ( V_44 -> V_8 < V_8 ) {
V_43 -> V_8 = V_44 -> V_7 - 1 ;
}
F_2 ( V_45 L_13
L_14 ,
V_7 , V_8 ,
( long ) V_43 -> V_7 , ( long ) V_43 -> V_8 ) ;
return 0 ;
}
static void
F_31 ( struct V_32 * V_12 )
{
struct V_46 * V_47 ;
#ifdef F_32
T_4 V_48 ;
#endif
struct V_14 * V_49 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
int V_50 = F_33 ( V_49 -> V_16 . V_51 ) ;
F_29 ( L_15 ,
V_12 , V_12 -> V_18 , V_12 -> V_35 -> V_52 ) ;
if ( V_12 -> V_6 ) {
int V_4 ;
F_34 ( V_12 ) ;
for ( V_4 = V_53 ; V_4 < V_54 ; V_4 ++ ) {
F_35 ( V_12 -> V_55 , V_4 ) ;
}
} else {
int V_56 , V_4 ;
F_29 ( L_16 ,
V_49 -> V_16 . V_57 . V_58 ,
V_49 -> V_16 . V_57 . V_7 , V_49 -> V_16 . V_57 . V_8 ,
V_49 -> V_16 . V_57 . V_9 ) ;
F_29 ( L_16 ,
V_49 -> V_16 . V_59 . V_58 ,
V_49 -> V_16 . V_59 . V_7 , V_49 -> V_16 . V_59 . V_8 ,
V_49 -> V_16 . V_59 . V_9 ) ;
V_56 = F_36 ( & V_60 , & ( V_49 -> V_16 . V_57 ) ) ;
if ( V_56 < 0 ) {
F_1 ( & V_60 , 2 ) ;
F_37 () ;
}
V_12 -> V_1 [ 0 ] = & ( V_49 -> V_16 . V_57 ) ;
V_4 = 1 ;
if ( V_49 -> V_16 . V_61 . V_7 ) {
V_56 = F_36 ( & V_62 ,
& ( V_49 -> V_16 . V_61 ) ) ;
if ( V_56 < 0 ) {
F_2 ( L_17
L_18 ,
( long ) V_49 -> V_16 . V_61 . V_7 ,
( long ) V_49 -> V_16 . V_61 . V_8 ) ;
} else
V_12 -> V_1 [ V_4 ++ ] = & ( V_49 -> V_16 . V_61 ) ;
}
if ( F_30 ( & V_62 ,
& ( V_49 -> V_16 . V_59 ) ) ) {
F_2 ( V_45 L_19 ,
( long ) V_49 -> V_16 . V_59 . V_7 ,
( long ) V_49 -> V_16 . V_59 . V_8 ) ;
} else {
V_56 = F_36 ( & V_62 , & ( V_49 -> V_16 . V_59 ) ) ;
if ( V_56 < 0 ) {
F_2 ( V_63 L_17
L_20 ,
( long ) V_49 -> V_16 . V_59 . V_7 ,
( long ) V_49 -> V_16 . V_59 . V_8 ) ;
} else
V_12 -> V_1 [ V_4 ++ ] = & ( V_49 -> V_16 . V_59 ) ;
}
#ifdef F_38
if ( V_49 -> V_16 . V_64 . V_9 ) {
V_56 = F_36 ( & V_62 , & ( V_49 -> V_16 . V_64 ) ) ;
if ( V_56 < 0 ) {
F_2 ( L_17
L_21 ,
( long ) V_49 -> V_16 . V_64 . V_7 ,
( long ) V_49 -> V_16 . V_64 . V_8 ) ;
F_1 ( & V_62 , 2 ) ;
F_37 () ;
}
V_12 -> V_1 [ V_4 ++ ] = & ( V_49 -> V_16 . V_64 ) ;
}
#endif
}
F_39 (ln, &bus->devices) {
int V_4 ;
struct V_65 * V_66 = F_40 ( V_47 ) ;
F_29 ( L_22 , F_41 ( V_66 ) ) ;
for ( V_4 = 0 ; V_4 < V_53 ; V_4 ++ ) {
struct V_1 * V_67 = & V_66 -> V_1 [ V_4 ] ;
if ( ! V_67 -> V_7 )
continue;
if ( V_67 -> V_9 & V_68 ) {
F_29 ( L_23 ,
V_67 -> V_7 , V_67 -> V_8 ) ;
V_67 -> V_7 |= V_50 ;
V_67 -> V_8 |= V_50 ;
F_29 ( L_24 , V_67 -> V_7 , V_67 -> V_8 ) ;
} else if ( V_67 -> V_9 & V_69 ) {
F_29 ( L_25 ,
V_67 -> V_7 , V_67 -> V_8 ) ;
V_67 -> V_7 = F_42 ( F_43 ( V_49 ) , V_67 -> V_7 ) ;
V_67 -> V_8 = F_42 ( F_43 ( V_49 ) , V_67 -> V_8 ) ;
F_29 ( L_24 , V_67 -> V_7 , V_67 -> V_8 ) ;
} else {
F_29 ( L_26 ,
V_67 -> V_9 , V_67 -> V_7 , V_67 -> V_8 ) ;
}
F_35 ( V_66 , V_4 ) ;
}
#ifdef F_32
( void ) F_44 ( V_66 , V_70 , & V_48 ) ;
V_12 -> V_71 &= ~ ( V_48 & V_72 ) ;
#endif
if ( ( V_66 -> V_73 >> 8 ) == V_74 )
continue;
F_45 ( V_49 -> V_75 , V_66 ) ;
}
#ifdef F_32
if ( V_76 ) {
if ( V_12 -> V_6 ) {
T_1 V_77 ;
( void ) F_46 ( V_12 -> V_55 , V_78 , & V_77 ) ;
( void ) F_47 ( V_12 -> V_55 , V_78 , V_77 | V_72 ) ;
} else {
}
V_76 = V_79 ;
}
F_39 (ln, &bus->devices) {
( void ) F_44 ( V_66 , V_80 , & V_48 ) ;
V_48 |= V_81 | V_82 | V_76 ;
( void ) F_48 ( V_66 , V_80 , V_48 ) ;
}
#endif
}
static void
F_49 ( struct V_83 * V_84 , struct V_14 * V_85 )
{
unsigned long V_86 ;
long V_87 ;
long V_48 ;
long V_88 ;
T_5 * V_89 ;
T_5 * V_90 ;
int V_4 ;
V_89 = F_50 ( sizeof( T_5 ) , V_91 ) ;
if ( ! V_89 )
return;
V_90 = F_50 ( sizeof( T_5 ) , V_91 ) ;
if ( ! V_90 ) {
F_51 ( V_89 ) ;
return;
}
V_48 = F_52 ( & V_86 , V_84 -> V_92 , V_84 -> V_93 ,
V_94 , V_89 ) ;
V_88 = V_89 -> V_95 [ 1 ] ;
V_48 |= F_52 ( & V_86 , V_84 -> V_92 , V_84 -> V_93 ,
V_96 , V_90 ) ;
V_87 = V_90 -> V_95 [ 1 ] ;
if ( V_48 != V_97 ) {
F_53 ( L_27 ) ;
}
if ( F_54 ( V_89 -> V_98 ) != V_99 ) {
F_53 ( L_28 ) ;
}
for ( V_4 = 0 ; V_4 < V_88 ; V_4 ++ ) {
struct {
unsigned long type ;
unsigned long V_7 ;
unsigned long V_8 ;
} * V_100 , * V_101 ;
struct V_1 * V_2 ;
V_100 = ( void * ) & ( V_89 -> V_95 [ 2 + V_4 * 3 ] ) ;
V_101 = ( void * ) & ( V_90 -> V_95 [ 2 + V_4 * 3 ] ) ;
switch( V_100 -> type & 0xff ) {
case V_102 :
V_85 -> V_16 . V_103 . V_7 = V_100 -> V_7 ;
V_85 -> V_16 . V_103 . V_8 = V_100 -> V_8 ;
break;
case V_104 :
if ( ! V_85 -> V_16 . V_59 . V_7 ) {
sprintf ( V_85 -> V_16 . V_105 ,
L_29 ,
( int ) V_85 -> V_16 . V_103 . V_7 ) ;
V_85 -> V_16 . V_106 = V_100 -> V_7 -
V_101 -> V_7 ;
V_2 = & V_85 -> V_16 . V_59 ;
V_2 -> V_58 = V_85 -> V_16 . V_105 ;
} else if ( ! V_85 -> V_16 . V_61 . V_7 ) {
sprintf ( V_85 -> V_16 . V_107 ,
L_30 ,
( int ) V_85 -> V_16 . V_103 . V_7 ) ;
V_2 = & V_85 -> V_16 . V_61 ;
V_2 -> V_58 = V_85 -> V_16 . V_107 ;
} else {
F_2 (KERN_WARNING MODULE_NAME
L_31 ) ;
break;
}
V_2 -> V_7 = V_100 -> V_7 ;
V_2 -> V_8 = V_100 -> V_8 ;
V_2 -> V_9 = V_69 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
case V_108 :
sprintf ( V_85 -> V_16 . V_109 , L_32 ,
( int ) V_85 -> V_16 . V_103 . V_7 ) ;
V_2 = & V_85 -> V_16 . V_64 ;
V_2 -> V_58 = V_85 -> V_16 . V_109 ;
V_2 -> V_7 = V_100 -> V_7 ;
V_2 -> V_8 = V_100 -> V_8 ;
V_2 -> V_9 = V_69 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
case V_110 :
F_2 (KERN_WARNING MODULE_NAME
L_33 ,
i, p->start) ;
break;
case V_111 :
V_85 -> V_112 = F_55 ( V_100 -> V_7 , 64 * 1024 * 1024 ) ;
sprintf ( V_85 -> V_16 . V_113 , L_34 ,
( int ) V_85 -> V_16 . V_103 . V_7 ) ;
V_2 = & V_85 -> V_16 . V_57 ;
V_2 -> V_58 = V_85 -> V_16 . V_113 ;
V_2 -> V_7 = F_33 ( V_85 -> V_16 . V_51 ) ;
V_2 -> V_8 = V_2 -> V_7 + V_114 - 1 ;
V_2 -> V_9 = V_68 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
default:
F_2 (KERN_WARNING MODULE_NAME
L_35 ,
i, p->type & 0xff ) ;
break;
}
}
F_51 ( V_89 ) ;
F_51 ( V_90 ) ;
}
static void
F_56 ( struct V_83 * V_84 , struct V_14 * V_85 )
{
struct V_1 * V_2 ;
int V_115 ;
V_85 -> V_16 . V_106 = V_116 ;
V_115 = F_11 ( V_85 -> V_16 . V_29 + V_117 ) ;
V_2 = & ( V_85 -> V_16 . V_103 ) ;
V_2 -> V_58 = L_36 ;
V_2 -> V_7 = V_115 & 0xff ;
V_2 -> V_8 = ( V_115 >> 8 ) & 0xff ;
V_2 = & ( V_85 -> V_16 . V_59 ) ;
sprintf ( V_85 -> V_16 . V_105 , L_29 ,
( int ) V_85 -> V_16 . V_103 . V_7 ) ;
V_2 -> V_58 = V_85 -> V_16 . V_105 ;
#if 1
F_57 ( V_84 , V_2 ) ;
#else
V_2 -> V_7 = F_11 ( V_85 -> V_16 . V_29 + V_118 ) ;
if ( V_2 -> V_7 & 1 ) {
unsigned long V_119 ;
V_2 -> V_9 = V_69 ;
V_2 -> V_7 &= V_120 ;
V_2 -> V_7 = F_42 ( F_43 ( V_85 ) , V_2 -> V_7 ) ;
V_119 = ~ F_11 ( V_85 -> V_16 . V_29 + V_121 ) ;
V_119 /= V_122 ;
V_2 -> V_7 += ( V_119 + 1 ) * F_58 ( V_84 -> V_123 . V_7 ) ;
V_2 -> V_8 = V_2 -> V_7 + V_119 ;
} else {
V_2 -> V_8 = V_2 -> V_7 = 0 ;
}
#endif
V_2 = & ( V_85 -> V_16 . V_61 ) ;
sprintf ( V_85 -> V_16 . V_107 , L_30 ,
( int ) V_85 -> V_16 . V_103 . V_7 ) ;
V_2 -> V_58 = V_85 -> V_16 . V_107 ;
#if 1
F_59 ( V_84 , V_2 ) ;
#else
V_2 -> V_7 = F_11 ( V_85 -> V_16 . V_29 + V_124 ) ;
if ( V_2 -> V_7 & 1 ) {
unsigned long V_119 ;
V_2 -> V_9 = V_69 ;
V_2 -> V_7 &= V_120 ;
V_2 -> V_7 = F_42 ( F_43 ( V_85 ) , V_2 -> V_7 ) ;
V_119 = F_11 ( V_85 -> V_16 . V_29 + V_125 ) ;
V_2 -> V_8 = V_2 -> V_7 + ~ V_119 ;
}
#endif
V_2 = & ( V_85 -> V_16 . V_57 ) ;
sprintf ( V_85 -> V_16 . V_113 , L_34 ,
( int ) V_85 -> V_16 . V_103 . V_7 ) ;
V_2 -> V_58 = V_85 -> V_16 . V_113 ;
V_2 -> V_9 = V_68 ;
V_2 -> V_7 = F_11 ( V_85 -> V_16 . V_29 + V_126 ) & ~ 1L ;
V_2 -> V_8 = V_2 -> V_7 + ( F_11 ( V_85 -> V_16 . V_29 + V_127 ) ^ ( V_114 - 1 ) ) ;
V_115 = F_33 ( V_85 -> V_16 . V_51 ) ;
V_2 -> V_7 |= V_115 ;
V_2 -> V_8 |= V_115 ;
}
static int T_6
F_60 ( struct V_14 * V_3 )
{
T_2 V_128 ;
T_2 V_129 ;
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
#ifdef F_38
#endif
V_129 = F_11 ( V_3 -> V_16 . V_29 + V_130 + 4 ) & 1 ;
if ( V_129 ) {
F_2 ( V_5 L_37 ) ;
}
V_128 = F_11 ( V_3 -> V_16 . V_29 + V_131 ) ;
if ( V_128 & V_132 ) {
F_2 ( V_5 L_38 ) ;
V_128 &= ~ V_132 ;
F_22 ( V_128 , V_3 -> V_16 . V_29 + V_131 ) ;
}
V_128 = F_11 ( V_3 -> V_16 . V_29 + V_130 ) ;
F_22 ( V_128 | V_133 , V_3 -> V_16 . V_29 + V_130 ) ;
if ( V_129 )
F_61 ( V_134 ) ;
if ( 0 == F_11 ( V_3 -> V_16 . V_29 + V_135 ) ) {
F_2 ( V_5 L_39 ) ;
F_22 ( 0x3 , V_3 -> V_16 . V_29 + V_135 ) ;
}
return 0 ;
}
static int T_6
F_62 ( struct V_83 * V_66 )
{
struct V_14 * V_85 ;
struct V_32 * V_136 ;
struct V_137 * V_138 ;
T_2 V_139 ;
void * V_140 ;
char * V_141 ;
void T_3 * V_142 = F_55 ( V_66 -> V_123 . V_7 , 4096 ) ;
V_139 = F_11 ( V_142 + V_143 ) ;
if ( F_63 ( V_66 ) ) {
V_139 &= 0xf ;
switch ( V_139 ) {
case 0 : V_141 = L_40 ; break;
case 1 : V_141 = L_41 ; break;
case 2 : V_141 = L_42 ; break;
case 3 : V_141 = L_43 ; break;
case 4 : V_141 = L_44 ; break;
case 5 : V_141 = L_45 ; break;
default: V_141 = L_46 ;
}
F_2 ( V_144 L_47 ,
V_141 , V_139 & 0xf , ( long ) V_66 -> V_123 . V_7 ) ;
if ( V_139 < 2 ) {
F_2 ( V_45 L_48
L_49 ) ;
}
#if 0
if (func_class > 4) {
cfg_ops = &mercury_cfg_ops;
} else
#endif
{
V_138 = & V_145 ;
}
} else if ( F_64 ( V_66 ) || F_65 ( V_66 ) ) {
int V_146 , V_147 ;
V_139 &= 0xff ;
V_146 = V_139 >> 4 , V_147 = V_139 & 0xf ;
F_2 ( V_144 L_50 ,
F_64 ( V_66 ) ? L_51 : L_52 , V_146 ,
V_147 , V_139 , ( long ) V_66 -> V_123 . V_7 ) ;
V_138 = & V_148 ;
} else {
F_2 ( V_63 L_53 ,
( long ) V_66 -> V_123 . V_7 ) ;
return - V_149 ;
}
V_140 = F_66 ( V_66 -> V_123 . V_7 + V_150 ) ;
V_85 = F_50 ( sizeof( struct V_14 ) , V_91 ) ;
if ( ! V_85 ) {
F_2 ( V_63 L_54 ) ;
return ( 1 ) ;
}
V_85 -> V_151 = V_139 ;
V_85 -> V_16 . V_29 = V_142 ;
V_85 -> V_16 . V_66 = V_66 ;
V_85 -> V_75 = V_140 ;
V_85 -> V_16 . V_152 = F_67 ( V_66 ) ;
F_68 ( V_66 , V_85 ) ;
V_153 = & V_154 ;
F_69 ( F_43 ( V_85 ) ) ;
F_70 ( & V_85 -> V_155 ) ;
if ( F_60 ( V_85 ) )
return ( 1 ) ;
if ( F_71 () ) {
V_156 = & V_157 ;
F_49 ( V_66 , V_85 ) ;
} else {
if ( ! V_158 ) {
V_158 = F_55 ( V_159 , 64 * 1024 ) ;
V_156 = & V_160 ;
}
F_56 ( V_66 , V_85 ) ;
}
if ( V_85 -> V_16 . V_103 . V_7 < V_161 )
V_85 -> V_16 . V_103 . V_7 = V_161 ;
V_66 -> V_66 . V_52 = V_85 ;
V_136 = V_85 -> V_16 . V_17 =
F_72 ( & V_66 -> V_66 , V_85 -> V_16 . V_103 . V_7 ,
V_138 , NULL ) ;
if ( F_71 () ) {
F_73 ( L_55 ) ;
F_74 ( V_136 ) ;
F_73 ( L_56 ) ;
F_75 ( V_136 ) ;
#ifdef F_76
F_73 ( L_57 ) ;
F_1 ( & V_85 -> V_16 . V_57 , 2 ) ;
F_73 ( L_58 ) ;
F_1 ( & V_85 -> V_16 . V_59 , 2 ) ;
#endif
}
F_77 ( V_136 ) ;
if ( V_138 == & V_145 ) {
V_85 -> V_9 |= V_162 ;
}
if ( V_136 ) {
V_161 = V_136 -> V_20 + 1 ;
F_78 ( V_136 ) ;
}
return 0 ;
}
void T_6 F_79 ( void )
{
F_80 ( & V_163 ) ;
}
void F_81 ( struct V_83 * V_164 , T_2 V_165 , T_2 V_166 )
{
void T_3 * V_29 = F_55 ( V_164 -> V_123 . V_7 , 4096 ) ;
V_166 <<= 2 ;
F_82 ( ( V_165 & 0x001fffff ) != 0 ) ;
F_82 ( ( V_166 & 0x001fffff ) != 0 ) ;
F_29 ( L_59 , V_38 , V_165 , V_166 ) ;
F_22 ( V_166 , V_29 + V_167 ) ;
F_22 ( V_165 , V_29 + V_168 ) ;
F_83 ( V_29 ) ;
}
