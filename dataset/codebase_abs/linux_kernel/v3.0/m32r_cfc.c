static inline T_1 F_1 ( unsigned long V_1 , int V_2 ) {
T_1 V_3 = 0 ;
T_1 V_4 ;
if ( V_2 == 1 ) {
V_4 = ( V_1 & 1 ) << 11 ;
V_1 -= V_1 & 1 ;
V_3 = V_5 - V_6 + V_4 + V_1 ;
} else if ( V_2 == 2 )
V_3 = V_7 - V_6 + V_1 ;
return V_3 ;
}
static inline T_1 F_1 ( unsigned long V_1 , int V_2 ) {
T_1 V_4 ;
T_1 V_3 = ( ( V_1 - V_6 ) & 0xf000 ) << 8 ;
if ( V_2 == 1 ) {
V_4 = V_1 & 1 ;
V_1 -= V_4 ;
V_4 <<= 11 ;
V_3 = ( V_3 | V_5 ) + V_4 + ( V_1 & 0xfff ) ;
} else if ( V_2 == 2 )
V_3 = ( V_3 | V_7 ) + ( V_1 & 0xfff ) ;
return V_3 ;
}
void F_2 ( int V_8 , unsigned long V_1 , void * V_9 , T_2 V_2 ,
T_2 V_10 , int V_11 )
{
T_1 V_3 ;
unsigned char * V_12 = ( unsigned char * ) V_9 ;
unsigned long V_13 ;
F_3 ( L_1
L_2 ,
V_8 , V_1 , V_9 , V_2 , V_10 , V_11 ) ;
V_3 = F_1 ( V_1 , 1 ) ;
if ( ! V_3 ) {
F_4 ( L_3 , V_1 ) ;
return;
}
F_3 ( L_4 , V_3 ) ;
F_5 ( & V_14 , V_13 ) ;
while ( V_10 -- )
* V_12 ++ = F_6 ( V_3 ) ;
F_7 ( & V_14 , V_13 ) ;
}
void F_8 ( int V_8 , unsigned long V_1 , void * V_9 , T_2 V_2 ,
T_2 V_10 , int V_11 )
{
T_1 V_3 ;
unsigned short * V_12 = ( unsigned short * ) V_9 ;
unsigned long V_13 ;
F_3 ( L_5
L_6 ,
V_8 , V_1 , V_9 , V_2 , V_10 , V_11 ) ;
if ( V_2 != 2 )
F_4 ( L_7 , V_2 ,
V_1 ) ;
if ( V_2 == 9 )
F_4 ( L_8 ) ;
V_3 = F_1 ( V_1 , 2 ) ;
if ( ! V_3 ) {
F_4 ( L_9 , V_1 ) ;
return;
}
F_3 ( L_10 , V_3 ) ;
F_5 ( & V_14 , V_13 ) ;
while ( V_10 -- )
* V_12 ++ = F_9 ( V_3 ) ;
F_7 ( & V_14 , V_13 ) ;
}
void F_10 ( int V_8 , unsigned long V_1 , void * V_9 , T_2 V_2 ,
T_2 V_10 , int V_11 )
{
T_1 V_3 ;
unsigned char * V_12 = ( unsigned char * ) V_9 ;
unsigned long V_13 ;
F_3 ( L_11
L_6 ,
V_8 , V_1 , V_9 , V_2 , V_10 , V_11 ) ;
V_3 = F_1 ( V_1 , 1 ) ;
if ( ! V_3 ) {
F_4 ( L_12 , V_1 ) ;
return;
}
F_3 ( L_13 , V_3 ) ;
F_5 ( & V_14 , V_13 ) ;
while ( V_10 -- )
F_11 ( * V_12 ++ , V_3 ) ;
F_7 ( & V_14 , V_13 ) ;
}
void F_12 ( int V_8 , unsigned long V_1 , void * V_9 , T_2 V_2 ,
T_2 V_10 , int V_11 )
{
T_1 V_3 ;
unsigned short * V_12 = ( unsigned short * ) V_9 ;
unsigned long V_13 ;
F_3 ( L_14
L_6 ,
V_8 , V_1 , V_9 , V_2 , V_10 , V_11 ) ;
if( V_2 != 2 )
F_4 ( L_15 ,
V_2 , V_1 ) ;
if( V_2 == 9 )
F_4 ( L_16 ) ;
V_3 = F_1 ( V_1 , 2 ) ;
if ( ! V_3 ) {
F_4 ( L_17 , V_1 ) ;
return;
}
#if 1
if ( V_3 & 1 ) {
F_4 ( L_18 , V_1 ,
V_3 ) ;
return;
}
#endif
F_3 ( L_19 , V_3 ) ;
F_5 ( & V_14 , V_13 ) ;
while ( V_10 -- )
F_13 ( * V_12 ++ , V_3 ) ;
F_7 ( & V_14 , V_13 ) ;
}
static unsigned int F_14 ( T_3 V_8 , unsigned int V_15 )
{
unsigned int V_16 = F_15 ( V_15 ) ;
F_3 ( L_20 , V_15 , V_16 ) ;
return V_16 ;
}
static void F_16 ( T_3 V_8 , unsigned int V_15 , unsigned int V_17 )
{
F_17 ( V_17 , V_15 ) ;
F_3 ( L_21 , V_15 , V_17 ) ;
}
static int T_4 F_18 ( T_3 V_8 )
{
unsigned int V_18 ;
F_3 ( L_22 ) ;
F_4 ( L_23 ) ;
V_18 = F_14 ( V_8 , ( unsigned int ) V_19 ) ;
if ( ! V_18 )
F_4 ( L_24 ) ;
F_4 ( L_25 , V_8 , V_18 ) ;
F_3 ( L_26 , V_18 ) ;
return 0 ;
}
static void F_19 ( T_5 V_20 , int V_21 , T_5 V_22 ,
unsigned int V_23 )
{
T_6 * V_24 = & V_25 [ V_26 ] ;
F_3 ( L_27
L_28 ,
V_20 , V_21 , V_22 , V_23 ) ;
V_24 -> V_23 = V_23 ;
V_24 -> V_22 = V_22 ;
#if ! F_20 ( V_27 )
V_24 -> V_20 = 0 ;
V_24 -> V_13 = 0 ;
V_24 -> V_28 = V_21 ;
V_24 -> V_29 = V_21 + 1 ;
#else
V_24 -> V_20 = V_20 ;
V_24 -> V_13 = 0 ;
V_24 -> V_28 = 0 ;
V_24 -> V_29 = 0 ;
#endif
if ( F_18 ( V_26 ) )
V_24 -> V_13 |= V_30 ;
#if ! F_20 ( V_27 )
F_21 ( ( unsigned int ) V_31 , 0x20 , L_29 ) ;
#else
{
unsigned int V_32 ;
V_32 = ( unsigned int ) V_31 ;
V_32 |= V_26 << 8 ;
F_21 ( V_32 , 0x20 , L_29 ) ;
}
#endif
F_4 ( V_33 L_30 , V_34 [ V_26 ] . V_35 ) ;
F_4 ( L_31 , V_24 -> V_20 ) ;
V_24 -> V_25 . V_36 |= ( V_37 | V_38 ) ;
V_24 -> V_25 . V_39 = V_40 ;
V_24 -> V_25 . V_41 = V_23 ;
V_24 -> V_25 . V_42 = 0 ;
#if ! F_20 ( V_27 )
V_24 -> V_25 . V_43 = V_44 ;
#else
V_24 -> V_25 . V_43 = V_45 + V_26 ;
#endif
#ifndef V_27
F_22 ( V_21 , V_46 , 0 , L_29 , V_46 ) ;
#ifndef F_23
F_22 ( V_21 + 1 , V_46 , 0 , L_29 , V_46 ) ;
#endif
F_3 ( L_32 ) ;
F_16 ( V_26 , ( unsigned int ) V_47 , 0x01 ) ;
#endif
#if F_20 ( V_48 ) || F_20 ( V_27 ) || F_20 ( V_49 )
F_16 ( V_26 , ( unsigned int ) V_50 , 0x0200 ) ;
#endif
V_26 ++ ;
return;
}
static T_7 V_46 ( int V_21 , void * V_51 )
{
int V_52 ;
T_8 V_53 = 0 ;
int V_54 = 0 ;
F_3 ( L_33 , V_21 , V_51 ) ;
for ( V_52 = 0 ; V_52 < V_26 ; V_52 ++ ) {
if ( V_25 [ V_52 ] . V_28 != V_21 && V_25 [ V_52 ] . V_29 != V_21 )
continue;
V_54 = 1 ;
F_3 ( L_34 ,
V_52 , V_21 ) ;
V_53 |= V_55 ;
if ( V_53 )
F_24 ( & V_25 [ V_52 ] . V_25 , V_53 ) ;
}
F_3 ( L_35 ) ;
return F_25 ( V_54 ) ;
}
static void F_26 ( T_1 V_17 )
{
F_3 ( L_36 ) ;
V_46 ( 0 , NULL ) ;
F_27 ( & V_56 ) ;
V_56 . V_57 = V_58 + V_59 ;
F_28 ( & V_56 ) ;
}
static int F_29 ( T_3 V_8 , T_8 * V_60 )
{
T_8 V_61 ;
F_3 ( L_37 ) ;
V_61 = F_14 ( V_8 , ( unsigned int ) V_19 ) ;
* V_60 = ( V_61 ) ? V_55 : 0 ;
F_3 ( L_38 , V_61 ) ;
#if F_20 ( V_48 ) || F_20 ( V_27 ) || F_20 ( V_49 )
if ( V_61 ) {
V_61 = F_15 ( ( unsigned int ) V_62 ) ;
if ( ! ( V_61 & V_63 ) ) {
F_3 ( L_39
L_40 , V_61 ) ;
V_61 |= V_63 ;
F_17 ( V_61 , ( unsigned int ) V_62 ) ;
F_30 ( 100 ) ;
}
* V_60 |= V_64 ;
F_16 ( V_8 , ( unsigned int ) V_65 , 0 ) ;
F_30 ( 100 ) ;
* V_60 |= V_66 ;
* V_60 |= V_67 ;
} else {
V_61 = F_15 ( ( unsigned int ) V_62 ) ;
V_61 &= ~ V_63 ;
F_17 ( V_61 , ( unsigned int ) V_62 ) ;
F_30 ( 100 ) ;
F_3 ( L_39
L_41 , V_61 ) ;
}
#elif F_20 ( V_68 ) || F_20 ( F_23 )
if ( V_61 ) {
V_61 = F_14 ( V_8 , ( unsigned int ) V_62 ) ;
if ( V_61 == 0 ) {
F_16 ( V_8 , ( unsigned int ) V_62 , 1 ) ;
F_16 ( V_8 , ( unsigned int ) V_65 , 0 ) ;
F_30 ( 50 ) ;
}
* V_60 |= V_64 ;
F_16 ( V_8 , ( unsigned int ) V_65 , 0 ) ;
F_30 ( 50 ) ;
F_16 ( V_8 , ( unsigned int ) V_31 , 0x0101 ) ;
F_30 ( 25 ) ;
F_16 ( V_8 , ( unsigned int ) V_31 , 0x0100 ) ;
F_31 ( 2 ) ;
* V_60 |= V_66 ;
* V_60 |= V_67 ;
} else {
F_16 ( V_8 , ( unsigned int ) V_62 , 0 ) ;
F_30 ( 100 ) ;
F_3 ( L_39
L_41 , V_61 ) ;
}
#else
#error no platform configuration
#endif
F_3 ( L_42 ,
V_8 , * V_60 ) ;
return 0 ;
}
static int F_32 ( T_3 V_8 , T_9 * V_69 )
{
F_3 ( L_43
L_44 , V_8 , V_69 -> V_13 ,
V_69 -> V_70 , V_69 -> V_71 , V_69 -> V_72 , V_69 -> V_73 ) ;
#if F_20 ( V_48 ) || F_20 ( V_27 ) || F_20 ( V_49 ) || F_20 ( V_68 ) || F_20 ( F_23 )
if ( V_69 -> V_70 ) {
if ( ( V_69 -> V_70 != 50 ) && ( V_69 -> V_70 != 33 ) )
return - V_74 ;
}
#endif
if ( V_69 -> V_13 & V_75 ) {
F_3 ( L_45 ) ;
F_16 ( V_8 , ( unsigned int ) V_31 , 0x101 ) ;
} else{
F_16 ( V_8 , ( unsigned int ) V_31 , 0x100 ) ;
}
if ( V_69 -> V_13 & V_76 ) {
F_3 ( L_46 ) ;
F_16 ( V_8 , ( unsigned int ) V_65 , 0 ) ;
} else {
F_16 ( V_8 , ( unsigned int ) V_65 , 1 ) ;
}
if( V_69 -> V_13 & V_77 ) {
F_3 ( L_47 ) ;
}
if ( V_69 -> V_13 & V_78 ) {
F_3 ( L_48 ) ;
}
if ( V_69 -> V_73 & V_55 )
F_3 ( L_49 ) ;
if ( V_69 -> V_13 & V_77 ) {
if ( V_69 -> V_73 & V_79 )
F_3 ( L_50 ) ;
} else {
if ( V_69 -> V_73 & V_80 )
F_3 ( L_51 ) ;
if ( V_69 -> V_73 & V_81 )
F_3 ( L_52 ) ;
if ( V_69 -> V_73 & V_66 )
F_3 ( L_53 ) ;
}
F_3 ( L_54 ) ;
return 0 ;
}
static int F_33 ( T_3 V_8 , struct V_82 * V_83 )
{
T_10 V_84 ;
F_3 ( L_55
L_56 , V_8 , V_83 -> V_84 , V_83 -> V_13 ,
V_83 -> V_85 , ( unsigned long long ) V_83 -> V_86 ,
( unsigned long long ) V_83 -> V_87 ) ;
V_84 = V_83 -> V_84 ;
return 0 ;
}
static int F_34 ( T_3 V_8 , struct V_88 * V_89 )
{
T_10 V_84 = V_89 -> V_84 ;
T_1 V_3 ;
T_6 * V_24 = & V_25 [ V_8 ] ;
F_3 ( L_57
L_58 , V_8 , V_84 , V_89 -> V_13 ,
V_89 -> V_85 , ( unsigned long long ) V_89 -> V_90 ,
V_89 -> V_91 ) ;
if ( ( V_84 > V_92 ) || ( V_89 -> V_91 > 0x3ffffff ) ) {
return - V_74 ;
}
if ( ( V_89 -> V_13 & V_93 ) == 0 ) {
V_24 -> V_94 = V_95 ;
return 0 ;
}
if ( V_89 -> V_13 & V_96 ) {
V_24 -> V_94 = V_97 ;
} else {
V_24 -> V_94 = V_98 ;
}
V_3 = V_24 -> V_22 + ( V_89 -> V_91 & V_99 ) ;
V_89 -> V_90 = V_3 + V_89 -> V_91 ;
return 0 ;
}
static int F_35 ( struct V_100 * V_101 , T_8 * V_60 )
{
unsigned int V_8 = F_36 ( V_101 , struct V_102 , V_25 ) -> V_103 ;
if ( V_25 [ V_8 ] . V_13 & V_30 ) {
F_37 ( & V_101 -> V_51 , L_59 , V_8 ) ;
* V_60 = 0 ;
return - V_74 ;
}
F_37 ( & V_101 -> V_51 , L_60 , V_8 ) ;
F_38 ( F_29 ( V_8 , V_60 ) ) ;
}
static int F_39 ( struct V_100 * V_101 , T_9 * V_69 )
{
unsigned int V_8 = F_36 ( V_101 , struct V_102 , V_25 ) -> V_103 ;
if ( V_25 [ V_8 ] . V_13 & V_30 ) {
F_37 ( & V_101 -> V_51 , L_61 , V_8 ) ;
return - V_74 ;
}
F_37 ( & V_101 -> V_51 , L_62 , V_8 ) ;
F_38 ( F_32 ( V_8 , V_69 ) ) ;
}
static int F_40 ( struct V_100 * V_101 , struct V_82 * V_83 )
{
unsigned int V_8 = F_36 ( V_101 , struct V_102 , V_25 ) -> V_103 ;
if ( V_25 [ V_8 ] . V_13 & V_30 ) {
F_37 ( & V_101 -> V_51 , L_63 , V_8 ) ;
return - V_74 ;
}
F_37 ( & V_101 -> V_51 , L_64 , V_8 ) ;
F_38 ( F_33 ( V_8 , V_83 ) ) ;
}
static int F_41 ( struct V_100 * V_101 , struct V_88 * V_89 )
{
unsigned int V_8 = F_36 ( V_101 , struct V_102 , V_25 ) -> V_103 ;
if ( V_25 [ V_8 ] . V_13 & V_30 ) {
F_37 ( & V_101 -> V_51 , L_65 , V_8 ) ;
return - V_74 ;
}
F_37 ( & V_101 -> V_51 , L_66 , V_8 ) ;
F_38 ( F_34 ( V_8 , V_89 ) ) ;
}
static int F_42 ( struct V_100 * V_101 )
{
F_37 ( & V_101 -> V_51 , L_67 ) ;
return 0 ;
}
static int T_4 F_43 ( void )
{
int V_52 , V_104 ;
V_104 = F_44 ( & V_105 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_45 ( & V_106 ) ;
if ( V_104 ) {
F_46 ( & V_105 ) ;
return V_104 ;
}
#if F_20 ( V_68 ) || F_20 ( F_23 )
F_16 ( 0 , ( unsigned int ) V_107 , 0x0f0f ) ;
F_16 ( 0 , ( unsigned int ) V_50 , 0x0200 ) ;
#endif
V_26 = 0 ;
#if ! F_20 ( V_27 )
F_19 ( V_108 , V_109 , V_110 ,
V_6 ) ;
#else
{
T_5 V_20 , V_22 ;
unsigned int V_23 ;
for ( V_52 = 0 ; V_52 < V_111 ; V_52 ++ ) {
V_20 = ( T_5 ) V_31 ;
V_20 = V_20 | ( V_52 << 8 ) ;
V_23 = ( V_52 + 1 ) << 12 ;
V_22 = V_110 | ( V_52 << 20 ) ;
F_19 ( V_20 , 0 , V_22 , V_23 ) ;
}
}
#endif
if ( V_26 == 0 ) {
F_4 ( L_68 ) ;
F_47 ( & V_106 ) ;
F_46 ( & V_105 ) ;
return - V_112 ;
}
for ( V_52 = 0 ; V_52 < V_26 ; V_52 ++ ) {
V_25 [ V_52 ] . V_25 . V_51 . V_113 = & V_106 . V_51 ;
V_25 [ V_52 ] . V_25 . V_114 = & V_115 ;
V_25 [ V_52 ] . V_25 . V_116 = & V_117 ;
V_25 [ V_52 ] . V_25 . V_118 = V_119 ;
V_25 [ V_52 ] . V_103 = V_52 ;
V_104 = F_48 ( & V_25 [ V_52 ] . V_25 ) ;
if ( ! V_104 )
V_25 [ V_52 ] . V_13 |= V_120 ;
#if 0
class_device_create_file(&socket[i].socket.dev,
&class_device_attr_info);
class_device_create_file(&socket[i].socket.dev,
&class_device_attr_exca);
#endif
}
if ( V_59 != 0 ) {
V_56 . V_121 = F_26 ;
V_56 . V_17 = 0 ;
F_27 ( & V_56 ) ;
V_56 . V_57 = V_58 + V_59 ;
F_28 ( & V_56 ) ;
}
return 0 ;
}
static void T_11 F_49 ( void )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_26 ; V_52 ++ )
if ( V_25 [ V_52 ] . V_13 & V_120 )
F_50 ( & V_25 [ V_52 ] . V_25 ) ;
F_47 ( & V_106 ) ;
if ( V_59 != 0 )
F_51 ( & V_56 ) ;
F_46 ( & V_105 ) ;
}
