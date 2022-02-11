static inline unsigned F_1 ( unsigned V_1 , unsigned V_2 )
{
return ( V_1 << 10 ) | ( V_2 << 2 ) ;
}
static int F_2 ( struct V_3 * V_4 )
{
unsigned V_5 ;
do {
V_5 = F_3 ( & V_4 -> V_6 -> V_5 ) ;
} while ( ! ( V_5 & 2 ) );
return V_5 & 1 ;
}
static int F_4 ( struct V_3 * V_4 )
{
int V_7 ;
unsigned long V_8 ;
F_5 ( V_8 ) ;
F_6 ( F_1 ( 500 , 65 ) , & V_4 -> V_6 -> V_5 ) ;
V_7 = F_2 ( V_4 ) ;
F_7 ( V_8 ) ;
F_8 ( 500 ) ;
return V_7 ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_9 ;
unsigned long V_8 ;
F_5 ( V_8 ) ;
F_6 ( F_1 ( 6 , 13 ) , & V_4 -> V_6 -> V_5 ) ;
V_9 = F_2 ( V_4 ) ;
F_7 ( V_8 ) ;
F_8 ( 500 ) ;
return V_9 ;
}
static void F_10 ( struct V_3 * V_4 , int V_10 )
{
if ( V_10 )
F_6 ( F_1 ( 6 , 110 ) , & V_4 -> V_6 -> V_5 ) ;
else
F_6 ( F_1 ( 80 , 30 ) , & V_4 -> V_6 -> V_5 ) ;
F_2 ( V_4 ) ;
}
static unsigned F_11 ( struct V_3 * V_4 )
{
unsigned V_9 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
V_9 = ( V_9 >> 1 ) | ( F_9 ( V_4 ) << 7 ) ;
return V_9 ;
}
static void F_12 ( struct V_3 * V_4 , int V_12 )
{
int V_11 , V_10 ;
for ( V_11 = 8 ; V_11 ; V_11 -- ) {
V_10 = V_12 & 1 ;
V_12 >>= 1 ;
F_10 ( V_4 , V_10 ) ;
}
}
static unsigned long
F_13 ( struct V_3 * V_4 , int * V_13 , unsigned long V_14 )
{
int V_15 , V_16 , V_17 , V_18 ;
F_4 ( V_4 ) ;
F_12 ( V_4 , 0xF0 ) ;
for ( V_17 = 0 , V_18 = 0 ; V_17 < 64 ; V_17 ++ ) {
V_15 = F_9 ( V_4 ) ;
V_16 = F_9 ( V_4 ) ;
if ( V_15 && V_16 ) {
F_14 ( V_19 L_1 ) ;
* V_13 = 0 ;
return 0 ;
}
if ( ! V_15 && ! V_16 ) {
if ( V_17 == * V_13 ) {
V_14 |= 1UL << V_17 ;
} else if ( V_17 > * V_13 ) {
V_14 &= ~ ( 1UL << V_17 ) ;
V_18 = V_17 ;
} else if ( ( V_14 & ( 1UL << V_17 ) ) == 0 )
V_18 = V_17 ;
F_10 ( V_4 , ( V_14 >> V_17 ) & 1 ) ;
continue;
} else {
if ( V_15 )
V_14 |= 1UL << V_17 ;
else
V_14 &= ~ ( 1UL << V_17 ) ;
F_10 ( V_4 , V_15 ) ;
continue;
}
}
* V_13 = V_18 ;
return V_14 ;
}
static void F_15 ( struct V_3 * V_4 , unsigned long V_14 )
{
int V_17 ;
F_4 ( V_4 ) ;
F_12 ( V_4 , 0xF0 ) ;
for ( V_17 = 0 ; V_17 < 64 ; V_17 ++ ) {
F_9 ( V_4 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 , ( V_14 >> V_17 ) & 1 ) ;
}
}
static void F_16 ( unsigned int * V_20 , unsigned char V_21 )
{
int V_11 ;
for( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
* V_20 <<= 1 ;
if( ( V_21 ^ ( * V_20 >> 16 ) ) & 1 )
* V_20 ^= 0x8005 ;
V_21 >>= 1 ;
}
* V_20 &= 0xFFFF ;
}
static unsigned int F_17 ( unsigned char * V_22 , int V_23 , unsigned int V_20 )
{
while( V_23 -- )
F_16 ( & V_20 , * ( V_22 ++ ) ) ;
return V_20 ;
}
static void F_18 ( unsigned int * V_20 , unsigned char V_21 )
{
int V_11 , V_24 ;
for( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_24 = ( * V_20 ^ V_21 ) & 1 ;
* V_20 >>= 1 ;
V_21 >>= 1 ;
if( V_24 )
* V_20 ^= 0x8c ;
}
* V_20 &= 0xff ;
}
static unsigned int F_19 ( unsigned long V_14 )
{
int V_11 ;
unsigned int V_20 = 0x00 ;
for( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
F_18 ( & V_20 , V_14 >> ( V_11 << 3 ) ) ;
return V_20 ;
}
static void
F_20 ( struct V_3 * V_4 , unsigned long V_14 , int V_25 ,
unsigned char * V_26 , unsigned char * V_27 )
{
int V_28 = 16 , V_11 ;
while( V_26 [ V_25 ] != 0xFF ) {
V_25 = V_26 [ V_25 ] ^ 0xFF ;
V_28 -- ;
if( V_28 < 0 ) {
F_14 ( V_29 L_2 ) ;
return;
}
}
V_28 = 3 ;
while( V_28 > 0 ) {
F_15 ( V_4 , V_14 ) ;
F_12 ( V_4 , 0xF0 ) ;
F_12 ( V_4 , ( V_25 << 5 ) & 0xE0 ) ;
F_12 ( V_4 , ( V_25 >> 3 ) & 0x1F ) ;
for( V_11 = 0 ; V_11 < 0x20 ; V_11 ++ )
V_27 [ V_11 ] = F_11 ( V_4 ) ;
if( F_17 ( V_27 , 0x20 , 0x0000 ) == 0x800d )
return;
V_28 -- ;
}
F_14 ( V_29 L_3 ) ;
for( V_11 = 0 ; V_11 < 0x20 ; V_11 ++ )
V_27 [ V_11 ] = 0x00 ;
}
static void
F_21 ( struct V_3 * V_4 , unsigned long V_14 ,
unsigned char * V_26 )
{
int V_11 , V_30 , V_28 = 3 , V_31 ;
unsigned int V_20 ;
while( V_28 > 0 ) {
V_31 = 1 ;
F_15 ( V_4 , V_14 ) ;
F_12 ( V_4 , 0xAA ) ;
F_12 ( V_4 , 0x00 ) ;
F_12 ( V_4 , 0x01 ) ;
for( V_11 = 0 ; V_11 < 64 ; V_11 += 8 ) {
for( V_30 = 0 ; V_30 < 8 ; V_30 ++ )
V_26 [ V_11 + V_30 ] = F_11 ( V_4 ) ;
V_20 = F_17 ( V_26 + V_11 , 8 , ( V_11 == 0 ) ? 0x8707 : 0x0000 ) ;
F_16 ( & V_20 , F_11 ( V_4 ) ) ;
F_16 ( & V_20 , F_11 ( V_4 ) ) ;
if( V_20 != 0x800d )
V_31 = 0 ;
}
if( V_31 )
return;
V_28 -- ;
}
F_14 ( V_29 L_4 ) ;
for( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_26 [ V_11 ] = 0xFF ;
}
static void F_22 ( struct V_3 * V_4 , unsigned long V_14 )
{
unsigned char V_26 [ 64 ] ;
unsigned char V_27 [ 64 ] , V_32 [ 32 ] ;
int V_11 , V_30 ;
F_21 ( V_4 , V_14 , V_26 ) ;
F_20 ( V_4 , V_14 , 0 , V_26 , V_27 ) ;
F_20 ( V_4 , V_14 , 1 , V_26 , V_27 + 32 ) ;
V_30 = 0 ;
for( V_11 = 0 ; V_11 < 19 ; V_11 ++ )
if( V_27 [ V_11 + 11 ] != ' ' )
V_32 [ V_30 ++ ] = V_27 [ V_11 + 11 ] ;
for( V_11 = 0 ; V_11 < 6 ; V_11 ++ )
if( V_27 [ V_11 + 32 ] != ' ' )
V_32 [ V_30 ++ ] = V_27 [ V_11 + 32 ] ;
V_32 [ V_30 ] = 0 ;
if( ! strncmp ( V_32 , L_5 , 9 ) )
return;
if( ! strncmp ( V_32 , L_6 , 9 ) )
return;
strcpy ( V_4 -> V_33 , V_32 ) ;
V_30 = 0 ;
for( V_11 = 0 ; V_11 < 10 ; V_11 ++ )
if( V_27 [ V_11 + 1 ] != ' ' )
V_4 -> V_34 [ V_30 ++ ] = V_27 [ V_11 + 1 ] ;
V_4 -> V_34 [ V_30 ] = 0 ;
}
static void F_23 ( struct V_3 * V_4 , unsigned long V_14 )
{
int V_11 , V_28 = 3 ;
unsigned char V_27 [ 13 ] ;
while( V_28 > 0 ) {
F_15 ( V_4 , V_14 ) ;
F_12 ( V_4 , 0xF0 ) ;
F_12 ( V_4 , 0x00 ) ;
F_12 ( V_4 , 0x00 ) ;
F_11 ( V_4 ) ;
for( V_11 = 0 ; V_11 < 13 ; V_11 ++ )
V_27 [ V_11 ] = F_11 ( V_4 ) ;
if( F_17 ( V_27 , 13 , 0x0000 ) == 0x800d ) {
for( V_11 = 10 ; V_11 > 4 ; V_11 -- )
V_4 -> V_35 [ 10 - V_11 ] = V_27 [ V_11 ] ;
return;
}
V_28 -- ;
}
F_14 ( V_29 L_7 ) ;
for( V_11 = 0 ; V_11 < 6 ; V_11 ++ )
V_4 -> V_35 [ V_11 ] = 0x00 ;
}
static void F_24 ( struct V_3 * V_4 )
{
int V_36 = 0 , V_28 = 3 ;
unsigned long V_37 , V_14 ;
F_6 ( V_38 , & V_4 -> V_6 -> V_39 ) ;
while( V_28 > 0 ) {
V_4 -> V_33 [ 0 ] = 0 ;
V_4 -> V_34 [ 0 ] = 0 ;
V_14 = V_37 = F_13 ( V_4 , & V_36 , 0 ) ;
if( ! V_37 )
return;
while( 1 ) {
if( F_19 ( V_14 ) )
break;
else {
switch( V_14 & 0xFF ) {
case 0x0B :
F_22 ( V_4 , V_14 ) ;
break;
case 0x09 :
case 0x89 :
case 0x91 :
F_23 ( V_4 , V_14 ) ;
break;
}
}
V_14 = F_13 ( V_4 , & V_36 , V_14 ) ;
if( V_14 == V_37 )
return;
}
V_28 -- ;
}
F_14 ( V_29 L_8 ) ;
}
static void F_25 ( struct V_3 * V_4 , T_1 V_40 , int V_41 )
{
unsigned long V_8 ;
F_26 ( & V_4 -> V_42 , V_8 ) ;
switch ( V_41 ) {
case V_43 :
F_6 ( V_40 , & V_4 -> V_6 -> V_44 ) ;
break;
case V_45 :
F_6 ( V_40 , & V_4 -> V_6 -> V_46 ) ;
break;
}
F_27 ( & V_4 -> V_42 , V_8 ) ;
}
static inline T_1 F_28 ( struct V_3 * V_4 )
{
unsigned long V_47 ;
T_1 V_48 = 0 ;
F_26 ( & V_4 -> V_42 , V_47 ) ;
V_48 = F_3 ( & V_4 -> V_6 -> V_49 ) ;
V_48 &= F_3 ( & V_4 -> V_6 -> V_44 ) ;
F_27 ( & V_4 -> V_42 , V_47 ) ;
return V_48 ;
}
static T_2 F_29 ( int V_50 , void * V_51 )
{
unsigned long V_8 ;
struct V_3 * V_4 = V_51 ;
int V_52 = 1 , V_53 ;
unsigned int V_54 ;
F_30 ( & V_55 , V_8 ) ;
if( V_4 -> V_56 && F_31 ( & V_4 -> V_6 -> V_57 ) ) {
if( V_58 && V_4 -> V_59 [ V_58 -> V_53 ] &&
V_58 -> V_60 ) {
V_52 = V_52 && ! V_58 -> V_60 ( V_58 ,
V_4 , 0 ) ;
}
}
V_54 = F_28 ( V_4 ) ;
for( V_53 = 0 ; V_53 < V_61 ; V_53 ++ ) {
if( V_4 -> V_59 [ V_53 ] && V_62 [ V_53 ]
&& ( V_54 & V_62 [ V_53 ] -> V_63 )
&& V_62 [ V_53 ] -> V_60 ) {
F_25 ( V_4 , V_62 [ V_53 ] -> V_63 ,
V_45 ) ;
if( ! V_62 [ V_53 ] -> V_60 ( V_62 [ V_53 ] ,
V_4 , V_54 & V_62 [ V_53 ] -> V_63 ) )
V_54 &= ~ V_62 [ V_53 ] -> V_63 ;
if ( V_62 [ V_53 ] -> V_64 )
F_25 ( V_4 , V_62 [ V_53 ] -> V_63 ,
V_43 ) ;
}
}
F_32 ( & V_55 , V_8 ) ;
if( V_54 ) {
F_14 ( V_19
L_9 , V_54 ) ;
F_25 ( V_4 , V_54 , V_45 ) ;
V_52 = 1 ;
}
return V_52 ? V_65 : V_66 ;
}
static T_2 F_33 ( int V_50 , void * V_51 )
{
unsigned long V_8 ;
struct V_3 * V_4 = (struct V_3 * ) V_51 ;
int V_52 = 1 ;
if( ! V_4 -> V_56 )
return V_66 ;
F_30 ( & V_55 , V_8 ) ;
if( V_58 && V_4 -> V_59 [ V_58 -> V_53 ]
&& V_58 -> V_60 )
V_52 = V_52 && ! V_58 -> V_60 ( V_58 , V_4 , 0 ) ;
F_32 ( & V_55 , V_8 ) ;
return V_52 ? V_65 : V_66 ;
}
void F_34 ( struct V_67 * V_68 ,
struct V_3 * V_4 , unsigned int V_69 )
{
F_25 ( V_4 , V_69 & V_68 -> V_63 , V_43 ) ;
}
void F_35 ( struct V_67 * V_68 , struct V_3 * V_4 ,
unsigned int V_69 )
{
F_6 ( V_69 & V_68 -> V_63 , & V_4 -> V_6 -> V_49 ) ;
}
void F_36 ( struct V_67 * V_68 ,
struct V_3 * V_4 , unsigned int V_69 )
{
F_25 ( V_4 , V_69 & V_68 -> V_63 , V_45 ) ;
}
void F_37 ( struct V_3 * V_4 , unsigned int V_40 )
{
unsigned long V_8 ;
F_26 ( & V_4 -> V_70 , V_8 ) ;
F_6 ( V_40 , & V_4 -> V_6 -> V_39 ) ;
F_27 ( & V_4 -> V_70 , V_8 ) ;
}
static int F_38 ( void * * V_71 , int V_72 )
{
int V_11 ;
for( V_11 = 0 ; V_11 < V_72 ; V_11 ++ )
if( ! ( V_71 [ V_11 ] ) )
return V_11 ;
return - 1 ;
}
int F_39 ( struct V_67 * V_68 )
{
struct V_3 * V_4 ;
int V_73 ;
unsigned long V_8 ;
F_40 ( & V_55 , V_8 ) ;
V_73 = F_38 ( ( void * * ) V_62 , V_61 ) ;
if( V_73 != - 1 ) {
V_62 [ V_73 ] = V_68 ;
if( V_68 -> V_74 ) {
if( V_58 == NULL )
V_58 = V_68 ;
else
F_14 ( V_19
L_10 ) ;
}
}
F_41 ( & V_55 , V_8 ) ;
if( V_73 == - 1 ) {
F_14 ( V_19 L_11 ) ;
return - V_75 ;
}
V_68 -> V_53 = V_73 ;
if ( ! V_68 -> V_76 )
return 0 ;
F_42 ( & V_77 ) ;
F_43 (idd, &ioc3_devices, list) {
V_4 -> V_59 [ V_73 ] = 1 ;
V_4 -> V_59 [ V_73 ] = ! V_68 -> V_76 ( V_68 , V_4 ) ;
}
F_44 ( & V_77 ) ;
return 0 ;
}
void F_45 ( struct V_67 * V_68 )
{
struct V_3 * V_4 ;
unsigned long V_8 ;
F_40 ( & V_55 , V_8 ) ;
if( V_62 [ V_68 -> V_53 ] == V_68 )
V_62 [ V_68 -> V_53 ] = NULL ;
else
F_14 ( V_19
L_12 , V_68 -> V_78 ) ;
if( V_58 == V_68 )
V_58 = NULL ;
F_41 ( & V_55 , V_8 ) ;
F_42 ( & V_77 ) ;
F_43 (idd, &ioc3_devices, list)
if( V_4 -> V_59 [ V_68 -> V_53 ] ) {
if( V_68 -> remove )
if( V_68 -> remove ( V_68 , V_4 ) )
F_14 ( V_19
L_13
L_14 ,
V_79 , F_46 ( V_68 -> V_80 ) ,
F_47 ( V_4 -> V_81 ) ) ;
V_4 -> V_59 [ V_68 -> V_53 ] = 0 ;
if( V_68 -> V_63 )
F_25 ( V_4 , V_68 -> V_63 , V_45 ) ;
}
F_44 ( & V_77 ) ;
}
static int T_3 F_48 ( struct V_3 * V_4 )
{
int V_82 = V_83 ;
if( ! strncmp ( V_4 -> V_33 , L_15 , 9 ) )
V_82 = V_84 ;
if( ! strncmp ( V_4 -> V_33 , L_16 , 9 ) )
V_82 = V_85 ;
if( ! strncmp ( V_4 -> V_33 , L_17 , 9 ) )
V_82 = V_86 ;
if( ! strncmp ( V_4 -> V_33 , L_18 , 9 ) )
V_82 = V_86 ;
#ifdef F_49
if( ! V_4 -> V_33 [ 0 ] )
V_82 = V_87 ;
#endif
F_14 ( V_88 L_19 ,
V_4 -> V_33 , V_4 -> V_34 , V_89 [ V_82 ] ) ;
return V_82 ;
}
static int T_3
F_50 ( struct V_90 * V_81 , const struct V_91 * V_92 )
{
struct V_3 * V_4 ;
T_1 V_93 ;
int V_94 , V_53 ;
if ( ( V_94 = F_51 ( V_81 ) ) ) {
F_14 ( V_19
L_20 ,
V_79 , F_47 ( V_81 ) ) ;
goto V_95;
}
F_52 ( V_81 ) ;
#ifdef F_53
V_94 = F_54 ( V_81 , F_55 ( 64 ) ) ;
if ( ! V_94 ) {
V_94 = F_56 ( V_81 , F_55 ( 64 ) ) ;
if ( V_94 < 0 ) {
F_14 ( V_19 L_21
L_22 ,
V_79 ) ;
}
}
#endif
V_4 = F_57 ( sizeof( struct V_3 ) , V_96 ) ;
if ( ! V_4 ) {
F_14 ( V_19
L_23 ,
V_79 , F_47 ( V_81 ) ) ;
V_94 = - V_97 ;
goto V_98;
}
F_58 ( & V_4 -> V_42 ) ;
F_58 ( & V_4 -> V_70 ) ;
V_4 -> V_81 = V_81 ;
V_4 -> V_99 = F_59 ( V_81 , 0 ) ;
if ( ! V_4 -> V_99 ) {
F_14 ( V_19
L_24
L_14 ,
V_79 , F_47 ( V_81 ) ) ;
V_94 = - V_97 ;
goto V_100;
}
if ( ! F_60 ( V_4 -> V_99 , V_101 , L_25 ) ) {
F_14 ( V_19
L_26
L_14 ,
V_79 , F_47 ( V_81 ) ) ;
V_94 = - V_97 ;
goto V_100;
}
V_4 -> V_6 = F_61 ( V_4 -> V_99 , V_101 ) ;
if ( ! V_4 -> V_6 ) {
F_14 ( V_19
L_27
L_14 ,
V_79 , F_47 ( V_81 ) ) ;
V_94 = - V_97 ;
goto V_102;
}
F_62 ( V_81 , V_4 ) ;
F_63 ( & V_77 ) ;
F_64 ( & V_4 -> V_103 , & V_104 ) ;
V_4 -> V_53 = V_105 ++ ;
F_65 ( & V_77 ) ;
V_4 -> V_106 = F_3 ( & V_4 -> V_6 -> V_107 ) ;
F_24 ( V_4 ) ;
V_4 -> V_108 = F_48 ( V_4 ) ;
F_66 ( V_81 , V_109 , & V_93 ) ;
F_67 ( V_81 , V_109 ,
V_93 | V_110 |
V_111 | V_112 |
V_113 ) ;
F_25 ( V_4 , ~ 0 , V_45 ) ;
F_6 ( ~ 0 , & V_4 -> V_6 -> V_49 ) ;
if( V_4 -> V_108 == V_84
|| V_4 -> V_108 == V_87 ) {
F_6 ( 0 , & V_4 -> V_6 -> V_114 ) ;
F_6 ( ~ 0 , & V_4 -> V_6 -> V_57 ) ;
V_4 -> V_56 = 1 ;
if ( ! F_68 ( V_81 -> V_50 , F_33 , V_115 ,
L_28 , ( void * ) V_4 ) ) {
V_4 -> V_116 = V_81 -> V_50 ;
} else {
F_14 ( V_19
L_29 ,
V_79 , V_81 -> V_50 ) ;
}
if ( ! F_68 ( V_81 -> V_50 + 2 , F_29 , V_115 ,
L_30 , ( void * ) V_4 ) ) {
V_4 -> V_117 = V_81 -> V_50 + 2 ;
} else {
F_14 ( V_19
L_29 ,
V_79 , V_81 -> V_50 + 2 ) ;
}
} else {
if ( ! F_68 ( V_81 -> V_50 , F_29 , V_115 ,
L_25 , ( void * ) V_4 ) ) {
V_4 -> V_117 = V_81 -> V_50 ;
} else {
F_14 ( V_19
L_29 ,
V_79 , V_81 -> V_50 ) ;
}
}
for( V_53 = 0 ; V_53 < V_61 ; V_53 ++ )
if( V_62 [ V_53 ] && V_62 [ V_53 ] -> V_76 ) {
V_4 -> V_59 [ V_53 ] = 1 ;
V_4 -> V_59 [ V_53 ] = ! V_62 [ V_53 ] -> V_76
( V_62 [ V_53 ] , V_4 ) ;
}
F_14 ( V_88 L_31 , F_47 ( V_81 ) ) ;
return 0 ;
V_102:
F_69 ( V_4 -> V_99 , V_101 ) ;
V_100:
F_70 ( V_4 ) ;
V_98:
F_71 ( V_81 ) ;
V_95:
return V_94 ;
}
static void T_4 F_72 ( struct V_90 * V_81 )
{
int V_53 ;
struct V_3 * V_4 ;
V_4 = F_73 ( V_81 ) ;
for( V_53 = 0 ; V_53 < V_61 ; V_53 ++ )
if( V_4 -> V_59 [ V_53 ] ) {
if( V_62 [ V_53 ] && V_62 [ V_53 ] -> remove )
if( V_62 [ V_53 ] -> remove ( V_62 [ V_53 ] ,
V_4 ) )
F_14 ( V_19
L_32
L_14 ,
V_79 ,
F_46 ( V_62 [ V_53 ] -> V_80 ) ,
F_47 ( V_81 ) ) ;
V_4 -> V_59 [ V_53 ] = 0 ;
}
F_25 ( V_4 , ~ 0 , V_45 ) ;
F_6 ( ~ 0 , & V_4 -> V_6 -> V_49 ) ;
F_74 ( V_4 -> V_117 , ( void * ) V_4 ) ;
if( V_4 -> V_56 )
F_74 ( V_4 -> V_116 , ( void * ) V_4 ) ;
F_75 ( V_4 -> V_6 ) ;
F_69 ( V_4 -> V_99 , V_101 ) ;
F_71 ( V_81 ) ;
F_63 ( & V_77 ) ;
F_76 ( & V_4 -> V_103 ) ;
F_65 ( & V_77 ) ;
F_70 ( V_4 ) ;
}
static int T_5 F_77 ( void )
{
if ( F_78 ( L_33 ) )
return F_79 ( & V_118 ) ;
return - V_97 ;
}
static void T_6 F_80 ( void )
{
F_81 ( & V_118 ) ;
}
