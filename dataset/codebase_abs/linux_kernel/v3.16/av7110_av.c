int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
if ( ! ( V_6 -> V_8 & V_9 ) )
return 0 ;
if ( V_3 [ 3 ] == 0xe0 )
V_3 [ 4 ] = V_3 [ 5 ] = 0 ;
if ( V_6 -> V_8 & V_10 )
return V_6 -> V_11 . V_12 ( V_3 , V_4 , NULL , 0 ,
& V_6 -> V_13 . V_12 , V_14 ) ;
else
return V_1 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_2 ( void * V_7 , unsigned char * V_15 )
{
struct V_5 * V_6 = (struct V_5 * ) V_7 ;
V_6 -> V_11 . V_12 ( V_15 , 188 , NULL , 0 ,
& V_6 -> V_13 . V_12 , V_14 ) ;
return 0 ;
}
int F_3 ( struct V_16 * V_16 , int V_17 ,
struct V_5 * V_6 )
{
int V_18 = 0 ;
struct V_19 * V_20 = V_6 -> V_21 ;
F_4 ( 2 , L_1 , V_16 , V_6 ) ;
if ( V_16 -> V_22 || ( V_16 -> V_23 & V_17 ) )
return - V_24 ;
F_5 ( V_16 , V_25 , V_26 , 0 ) ;
V_20 -> V_27 = 1 ;
V_16 -> V_23 |= V_17 ;
switch ( V_16 -> V_23 ) {
case V_28 :
F_6 ( & V_16 -> V_2 [ 0 ] ,
V_20 -> V_29 [ 0 ] -> V_30 ,
F_2 ,
( void * ) V_20 -> V_29 [ 0 ] ) ;
V_18 = F_5 ( V_16 , V_25 , V_31 , 2 , V_32 , 0 ) ;
break;
case V_33 :
F_6 ( & V_16 -> V_2 [ 1 ] ,
V_20 -> V_29 [ 1 ] -> V_30 ,
F_2 ,
( void * ) V_20 -> V_29 [ 1 ] ) ;
V_18 = F_5 ( V_16 , V_25 , V_31 , 2 , V_34 , 0 ) ;
break;
case V_35 :
F_6 ( & V_16 -> V_2 [ 0 ] ,
V_20 -> V_29 [ 0 ] -> V_30 ,
F_2 ,
( void * ) V_20 -> V_29 [ 0 ] ) ;
F_6 ( & V_16 -> V_2 [ 1 ] ,
V_20 -> V_29 [ 1 ] -> V_30 ,
F_2 ,
( void * ) V_20 -> V_29 [ 1 ] ) ;
V_18 = F_5 ( V_16 , V_25 , V_31 , 2 , V_36 , 0 ) ;
break;
}
return V_18 ;
}
int F_7 ( struct V_16 * V_16 , int V_17 )
{
int V_18 = 0 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( V_16 -> V_23 )
return - V_24 ;
if ( V_16 -> V_22 & V_17 )
return - V_24 ;
F_5 ( V_16 , V_25 , V_26 , 0 ) ;
if ( V_16 -> V_22 == V_37 ) {
F_8 ( & V_16 -> V_38 [ 0 ] ) ;
F_8 ( & V_16 -> V_38 [ 1 ] ) ;
}
V_16 -> V_22 |= V_17 ;
switch ( V_16 -> V_22 ) {
case V_28 :
V_18 = F_5 ( V_16 , V_25 , V_39 , 2 , V_32 , 0 ) ;
break;
case V_33 :
V_18 = F_5 ( V_16 , V_25 , V_39 , 2 , V_34 , 0 ) ;
V_16 -> V_40 = 0 ;
break;
case V_35 :
V_16 -> V_40 = 0 ;
V_18 = F_5 ( V_16 , V_25 , V_39 , 2 , V_36 , 0 ) ;
break;
}
return V_18 ;
}
int F_9 ( struct V_16 * V_16 , int V_17 )
{
int V_18 = 0 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ! ( V_16 -> V_22 & V_17 ) && ! ( V_16 -> V_23 & V_17 ) )
return 0 ;
F_5 ( V_16 , V_25 , V_26 , 0 ) ;
if ( V_16 -> V_22 ) {
V_16 -> V_22 &= ~ V_17 ;
switch ( V_16 -> V_22 ) {
case V_28 :
V_18 = F_5 ( V_16 , V_25 , V_39 , 2 , V_32 , 0 ) ;
break;
case V_33 :
V_18 = F_5 ( V_16 , V_25 , V_39 , 2 , V_34 , 0 ) ;
break;
case V_37 :
V_18 = F_10 ( V_16 , V_16 -> V_41 ) ;
break;
}
} else {
V_16 -> V_23 &= ~ V_17 ;
switch ( V_16 -> V_23 ) {
case V_28 :
V_18 = F_5 ( V_16 , V_25 , V_31 , 2 , V_32 , 0 ) ;
break;
case V_33 :
V_18 = F_5 ( V_16 , V_25 , V_31 , 2 , V_34 , 0 ) ;
break;
case V_37 :
break;
}
}
return V_18 ;
}
int F_11 ( void * V_42 , struct V_43 * V_3 , int V_44 )
{
int V_4 ;
T_3 V_45 ;
T_4 V_46 ;
if ( ! V_44 ) {
F_12 ( & V_3 -> V_47 ) ;
return - 1 ;
}
while ( 1 ) {
V_4 = F_13 ( V_3 ) ;
if ( V_4 < 6 ) {
F_12 ( & V_3 -> V_47 ) ;
return - 1 ;
}
V_45 = F_14 ( V_3 , 0 ) << 24 ;
V_45 |= F_14 ( V_3 , 1 ) << 16 ;
V_45 |= F_14 ( V_3 , 2 ) << 8 ;
V_45 |= F_14 ( V_3 , 3 ) ;
if ( ( ( V_45 & ~ 0x0f ) == 0x000001e0 ) ||
( ( V_45 & ~ 0x1f ) == 0x000001c0 ) ||
( V_45 == 0x000001bd ) )
break;
F_15 ( L_3 ) ;
F_16 ( V_3 , 1 ) ;
}
V_46 = F_14 ( V_3 , 4 ) << 8 ;
V_46 |= F_14 ( V_3 , 5 ) ;
V_46 += 6 ;
if ( V_4 < V_46 || V_46 > V_44 ) {
F_12 ( & V_3 -> V_47 ) ;
return - 1 ;
}
F_17 ( V_3 , V_42 , ( T_2 ) V_46 ) ;
F_4 ( 2 , L_4 ,
( unsigned long ) V_3 -> V_48 , ( unsigned long ) V_3 -> V_49 ) ;
F_12 ( & V_3 -> V_47 ) ;
return V_46 ;
}
int F_18 ( struct V_16 * V_16 , int V_50 , int V_51 )
{
int V_52 , V_53 , V_54 , V_55 = 0 ;
F_4 ( 2 , L_2 , V_16 ) ;
V_16 -> V_56 . V_57 = V_50 ;
V_16 -> V_56 . V_58 = V_51 ;
switch ( V_16 -> V_59 ) {
case V_60 :
V_50 = ( V_50 * 256 ) / 1036 ;
V_51 = ( V_51 * 256 ) / 1036 ;
if ( V_50 > 0x3f )
V_50 = 0x3f ;
if ( V_51 > 0x3f )
V_51 = 0x3f ;
if ( ( V_52 = F_19 ( V_16 , 3 , 0x80 + V_50 ) ) )
return V_52 ;
return F_19 ( V_16 , 4 , V_51 ) ;
case V_61 :
V_50 = 127 - V_50 / 2 ;
V_51 = 127 - V_51 / 2 ;
F_20 ( V_16 , 0x20 , 0x03 , V_50 ) ;
F_20 ( V_16 , 0x20 , 0x04 , V_51 ) ;
return 0 ;
case V_62 :
V_53 = ( V_50 > V_51 ) ? V_50 : V_51 ;
V_54 = ( V_53 * 0x73 / 255 ) << 8 ;
if ( V_53 > 0 )
V_55 = ( ( V_51 - V_50 ) * 127 ) / V_53 ;
F_21 ( V_16 , V_63 , 0x0001 , V_55 << 8 ) ;
F_21 ( V_16 , V_63 , 0x0000 , V_54 ) ;
F_21 ( V_16 , V_63 , 0x0006 , V_54 ) ;
return 0 ;
case V_64 :
V_53 = ( V_50 > V_51 ) ? V_50 : V_51 ;
V_54 = ( V_53 * 0x73 / 255 ) << 8 ;
if ( V_53 > 0 )
V_55 = ( ( V_51 - V_50 ) * 127 ) / V_53 ;
F_21 ( V_16 , V_63 , 0x0001 , V_55 << 8 ) ;
F_21 ( V_16 , V_63 , 0x0000 , V_54 ) ;
return 0 ;
}
return 0 ;
}
int F_10 ( struct V_16 * V_16 , enum V_65 V_66 )
{
int V_18 ;
F_4 ( 2 , L_2 , V_16 ) ;
V_18 = F_5 ( V_16 , V_67 , V_68 , 1 , V_66 ) ;
if ( ! V_18 && ! V_16 -> V_22 ) {
V_18 = F_22 ( V_16 , V_16 -> V_69 [ V_70 ] ,
V_16 -> V_69 [ V_71 ] ,
V_16 -> V_69 [ V_72 ] ,
0 , V_16 -> V_69 [ V_73 ] ) ;
if ( ! V_18 )
V_18 = F_5 ( V_16 , V_74 , V_75 , 0 ) ;
}
return V_18 ;
}
static int F_23 ( struct V_16 * V_16 , T_1 * V_3 , int V_76 )
{
int V_77 ;
int V_78 , V_79 ;
int V_80 ;
T_1 * V_81 ;
int V_18 = 0 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( V_16 -> V_40 )
return 0 ;
for ( V_77 = 7 ; V_77 < V_76 - 10 ; V_77 ++ ) {
V_81 = V_3 + V_77 ;
if ( V_81 [ 0 ] || V_81 [ 1 ] || V_81 [ 2 ] != 0x01 || V_81 [ 3 ] != 0xb3 )
continue;
V_81 += 4 ;
V_78 = ( ( V_81 [ 1 ] & 0xF0 ) >> 4 ) | ( V_81 [ 0 ] << 4 ) ;
V_79 = ( ( V_81 [ 1 ] & 0x0F ) << 8 ) | ( V_81 [ 2 ] ) ;
V_80 = ( V_81 [ 3 ] & 0x0F ) ;
V_18 = F_10 ( V_16 , V_82 [ V_80 ] ) ;
if ( ! V_18 ) {
F_4 ( 2 , L_5 , V_78 , V_79 , V_80 ) ;
V_16 -> V_40 = 1 ;
}
break;
}
return V_18 ;
}
static inline long F_24 ( struct V_43 * V_83 ,
const T_1 * V_3 , unsigned long V_76 )
{
unsigned long V_84 = V_76 ;
int free ;
while ( V_84 > 0 ) {
if ( F_25 ( V_83 ) < 2048 ) {
if ( F_26 ( V_83 -> V_47 ,
( F_25 ( V_83 ) >= 2048 ) ) )
return V_76 - V_84 ;
}
free = F_25 ( V_83 ) ;
if ( free > V_84 )
free = V_84 ;
F_27 ( V_83 , V_3 , free ) ;
V_84 -= free ;
V_3 += free ;
}
return V_76 - V_84 ;
}
static void F_28 ( T_1 * V_3 , int V_76 , void * V_7 )
{
struct V_16 * V_16 = (struct V_16 * ) V_7 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ( V_3 [ 3 ] & 0xe0 ) == 0xe0 ) {
F_23 ( V_16 , V_3 , V_76 ) ;
F_24 ( & V_16 -> V_85 , V_3 , V_76 ) ;
} else
F_24 ( & V_16 -> V_86 , V_3 , V_76 ) ;
}
static void F_29 ( T_1 * V_3 , int V_76 , void * V_7 )
{
struct V_16 * V_16 = (struct V_16 * ) V_7 ;
F_4 ( 2 , L_2 , V_16 ) ;
F_24 ( & V_16 -> V_86 , V_3 , V_76 ) ;
}
static T_5 F_30 ( struct V_16 * V_16 , const char T_6 * V_3 ,
unsigned long V_76 , int V_87 , int type )
{
struct V_43 * V_88 ;
T_1 * V_89 ;
unsigned long V_84 = V_76 ;
F_4 ( 2 , L_6 , V_90 , type , V_76 ) ;
V_88 = ( type ) ? & V_16 -> V_85 : & V_16 -> V_86 ;
V_89 = V_16 -> V_91 [ type ] ;
if ( ! V_89 )
return - V_92 ;
if ( V_87 && ! V_93 )
return - V_94 ;
while ( V_84 >= V_95 ) {
if ( ! V_93 ) {
if ( V_87 )
return V_76 - V_84 ;
if ( F_26 ( V_88 -> V_47 , V_93 ) )
return V_76 - V_84 ;
}
if ( F_31 ( V_89 , V_3 , V_95 ) )
return - V_96 ;
F_32 ( V_16 , type , V_89 , V_95 ) ;
V_84 -= V_95 ;
V_3 += V_95 ;
}
return V_76 - V_84 ;
}
static T_5 F_33 ( struct V_16 * V_16 , const char T_6 * V_3 ,
unsigned long V_76 , int V_87 , int type )
{
unsigned long V_84 = V_76 , V_97 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ! V_16 -> V_91 [ type ] )
return - V_92 ;
if ( V_87 && ! V_98 )
return - V_94 ;
while ( V_84 > 0 ) {
if ( ! V_98 ) {
if ( V_87 )
return V_76 - V_84 ;
if ( F_26 ( V_16 -> V_85 . V_47 ,
V_98 ) )
return V_76 - V_84 ;
}
V_97 = V_84 ;
if ( V_97 > V_99 * 2 )
V_97 = V_99 * 2 ;
if ( F_31 ( V_16 -> V_91 [ type ] , V_3 , V_97 ) )
return - V_96 ;
F_34 ( V_16 -> V_91 [ type ] , V_97 ,
& V_16 -> V_38 [ type ] ) ;
V_84 -= V_97 ;
V_3 += V_97 ;
}
return V_76 - V_84 ;
}
static T_5 F_35 ( struct V_16 * V_16 , const T_1 * V_3 ,
unsigned long V_76 , int V_87 , int type )
{
unsigned long V_84 = V_76 , V_97 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ! V_16 -> V_91 [ type ] )
return - V_92 ;
if ( V_87 && ! V_98 )
return - V_94 ;
while ( V_84 > 0 ) {
if ( ! V_98 ) {
if ( V_87 )
return V_76 - V_84 ;
if ( F_26 ( V_16 -> V_85 . V_47 ,
V_98 ) )
return V_76 - V_84 ;
}
V_97 = V_84 ;
if ( V_97 > V_99 * 2 )
V_97 = V_99 * 2 ;
F_34 ( V_3 , V_97 , & V_16 -> V_38 [ type ] ) ;
V_84 -= V_97 ;
V_3 += V_97 ;
}
return V_76 - V_84 ;
}
static T_5 F_36 ( struct V_16 * V_16 , const char T_6 * V_3 ,
unsigned long V_76 , int V_87 , int type )
{
unsigned long V_84 = V_76 , V_97 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ! V_16 -> V_91 [ type ] )
return - V_92 ;
if ( V_87 && F_25 ( & V_16 -> V_86 ) < 20 * 1024 )
return - V_94 ;
while ( V_84 > 0 ) {
if ( F_25 ( & V_16 -> V_86 ) < 20 * 1024 ) {
if ( V_87 )
return V_76 - V_84 ;
if ( F_26 ( V_16 -> V_86 . V_47 ,
( F_25 ( & V_16 -> V_86 ) >= 20 * 1024 ) ) )
return V_76 - V_84 ;
}
V_97 = V_84 ;
if ( V_97 > V_99 * 2 )
V_97 = V_99 * 2 ;
if ( F_31 ( V_16 -> V_91 [ type ] , V_3 , V_97 ) )
return - V_96 ;
F_34 ( V_16 -> V_91 [ type ] , V_97 ,
& V_16 -> V_38 [ type ] ) ;
V_84 -= V_97 ;
V_3 += V_97 ;
}
return V_76 - V_84 ;
}
void F_37 ( struct V_100 * V_81 , struct V_5 * V_13 )
{
memset ( V_81 -> V_101 , 0 , V_95 ) ;
V_81 -> V_102 = 0 ;
V_81 -> V_103 = 0 ;
V_81 -> V_104 = 0 ;
if ( V_13 )
V_81 -> V_13 = V_13 ;
}
static void F_38 ( struct V_100 * V_81 )
{
memset ( V_81 -> V_101 , 0 , V_95 ) ;
V_81 -> V_103 = 0 ;
V_81 -> V_104 = 0 ;
}
static int F_39 ( T_1 const * V_3 , long int V_105 , int * V_104 )
{
int V_106 = 0 ;
int V_107 = 0 ;
* V_104 = 0 ;
while ( V_106 < V_105 - 3 && ! V_107 ) {
if ( V_3 [ V_106 ] == 0x00 && V_3 [ V_106 + 1 ] == 0x00 &&
V_3 [ V_106 + 2 ] == 0x01 ) {
switch ( V_3 [ V_106 + 3 ] ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 ... V_118 :
case V_119 ... V_120 :
V_107 = 1 ;
break;
default:
V_106 ++ ;
break;
}
} else
V_106 ++ ;
}
if ( V_106 == V_105 - 3 && ! V_107 ) {
if ( V_3 [ V_105 - 1 ] == 0x00 )
* V_104 = 1 ;
if ( V_3 [ V_105 - 2 ] == 0x00 &&
V_3 [ V_105 - 1 ] == 0x00 )
* V_104 = 2 ;
if ( V_3 [ V_105 - 3 ] == 0x00 &&
V_3 [ V_105 - 2 ] == 0x00 &&
V_3 [ V_105 - 1 ] == 0x01 )
* V_104 = 3 ;
return - 1 ;
}
return V_106 ;
}
void F_40 ( T_1 const * V_3 , long int V_105 , T_4 V_30 , struct V_100 * V_81 )
{
int V_106 , V_121 , V_122 , V_123 ;
int V_124 , V_125 ;
V_106 = 0 ;
V_121 = 0 ;
if ( V_81 -> V_104 ) {
V_124 = 0 ;
switch( V_81 -> V_104 ) {
case 1 :
if ( V_3 [ V_106 ] == 0x00 && V_3 [ V_106 + 1 ] == 0x01 ) {
V_124 = 1 ;
V_106 += 2 ;
}
break;
case 2 :
if ( V_3 [ V_106 ] == 0x01 ) {
V_124 = 1 ;
V_106 ++ ;
}
break;
case 3 :
V_124 = 1 ;
}
if ( V_124 ) {
switch ( V_3 [ V_106 ] ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 ... V_118 :
case V_119 ... V_120 :
V_81 -> V_101 [ 0 ] = 0x00 ;
V_81 -> V_101 [ 1 ] = 0x00 ;
V_81 -> V_101 [ 2 ] = 0x01 ;
V_81 -> V_101 [ 3 ] = V_3 [ V_106 ] ;
V_81 -> V_103 = 4 ;
memcpy ( V_81 -> V_101 + V_81 -> V_103 , V_3 + V_106 , ( V_95 - 4 ) - V_81 -> V_103 ) ;
V_106 += ( V_95 - 4 ) - V_81 -> V_103 ;
F_41 ( V_81 -> V_101 , ( V_95 - 4 ) , V_30 , & V_81 -> V_102 , V_81 -> V_13 ) ;
F_38 ( V_81 ) ;
break;
default:
V_106 = 0 ;
break;
}
}
V_81 -> V_104 = 0 ;
}
if ( V_81 -> V_103 ) {
V_121 = F_39 ( V_3 + V_106 , V_105 - V_106 , & V_81 -> V_104 ) ;
if ( V_121 >= 0 && V_121 < ( V_95 - 4 ) - V_81 -> V_103 )
V_122 = V_121 + V_106 ;
else
V_122 = ( V_95 - 4 ) - V_81 -> V_103 ;
memcpy ( V_81 -> V_101 + V_81 -> V_103 , V_3 , V_122 ) ;
V_106 += V_122 ;
V_81 -> V_103 += V_122 ;
F_41 ( V_81 -> V_101 , V_81 -> V_103 , V_30 , & V_81 -> V_102 , V_81 -> V_13 ) ;
F_38 ( V_81 ) ;
}
V_123 = 0 ;
while ( V_106 < V_105 ) {
V_121 = F_39 ( V_3 + V_106 + V_123 , V_105 - V_106 - V_123 , & V_81 -> V_104 ) ;
if ( V_121 >= 0 ) {
V_121 += V_106 + V_123 ;
if ( V_121 > V_106 ) {
F_41 ( V_3 + V_106 , V_121 - V_106 , V_30 , & V_81 -> V_102 , V_81 -> V_13 ) ;
V_106 = V_121 ;
F_38 ( V_81 ) ;
V_123 = 0 ;
} else
V_123 = 1 ;
} else {
V_122 = V_105 - V_106 ;
V_125 = V_122 % ( V_95 - 4 ) ;
V_122 -= V_125 ;
F_41 ( V_3 + V_106 , V_122 , V_30 , & V_81 -> V_102 , V_81 -> V_13 ) ;
memcpy ( V_81 -> V_101 , V_3 + V_106 + V_122 , V_125 ) ;
V_81 -> V_103 = V_125 ;
V_106 = V_105 ;
}
}
}
static int F_42 ( T_4 V_30 , T_1 * V_102 , int V_126 , T_1 * V_3 , T_1 V_105 )
{
int V_77 ;
int V_106 = 0 ;
int V_127 ;
T_1 V_128 [ 4 ] = { 0x47 , 0x00 , 0x00 , 0x10 } ;
V_127 = ( V_95 - 4 ) - V_105 ;
if ( V_126 )
V_128 [ 1 ] = 0x40 ;
if ( V_127 )
V_128 [ 3 ] = 0x30 ;
V_128 [ 1 ] |= ( T_1 ) ( ( V_30 & 0x1F00 ) >> 8 ) ;
V_128 [ 2 ] |= ( T_1 ) ( V_30 & 0x00FF ) ;
V_128 [ 3 ] |= ( ( * V_102 ) ++ & 0x0F ) ;
memcpy ( V_3 , V_128 , 4 ) ;
V_106 += 4 ;
if ( V_127 ) {
V_3 [ 4 ] = V_127 - 1 ;
V_106 ++ ;
if ( V_127 > 1 ) {
V_3 [ 5 ] = 0x00 ;
V_106 ++ ;
}
for ( V_77 = 6 ; V_77 < V_127 + 4 ; V_77 ++ ) {
V_3 [ V_77 ] = 0xFF ;
V_106 ++ ;
}
}
return V_106 ;
}
static void F_41 ( T_1 const * V_3 , long int V_105 , T_4 V_30 , T_1 * V_102 ,
struct V_5 * V_13 )
{
int V_122 , V_126 ;
T_1 V_129 [ V_95 ] ;
long V_106 = 0 ;
V_126 = 0 ;
if ( V_105 > 3 &&
V_3 [ 0 ] == 0x00 && V_3 [ 1 ] == 0x00 && V_3 [ 2 ] == 0x01 )
switch ( V_3 [ 3 ] ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 ... V_118 :
case V_119 ... V_120 :
V_126 = 1 ;
break;
default:
break;
}
while ( V_106 < V_105 ) {
memset ( V_129 , 0 , V_95 ) ;
if ( V_105 - V_106 >= ( V_95 - 4 ) ) {
V_122 = F_42 ( V_30 , V_102 , V_126 ,
V_129 , ( V_95 - 4 ) ) ;
memcpy ( V_129 + V_122 , V_3 + V_106 , V_95 - V_122 ) ;
V_106 += V_95 - V_122 ;
} else {
V_122 = F_42 ( V_30 , V_102 , V_126 ,
V_129 , V_105 - V_106 ) ;
memcpy ( V_129 + V_122 , V_3 + V_106 , V_95 - V_122 ) ;
V_106 = V_105 ;
}
V_13 -> V_11 . V_12 ( V_129 , 188 , NULL , 0 , & V_13 -> V_13 . V_12 , V_14 ) ;
V_126 = 0 ;
}
}
static int F_32 ( struct V_16 * V_16 , int type , const T_1 * V_3 , T_2 V_4 )
{
struct V_38 * V_38 = & V_16 -> V_38 [ type ] ;
if ( V_3 [ 1 ] & V_130 ) {
F_8 ( V_38 ) ;
return - 1 ;
}
if ( ! ( V_3 [ 3 ] & V_131 ) )
return - 1 ;
if ( V_3 [ 1 ] & V_132 )
F_43 ( V_38 ) ;
if ( V_3 [ 3 ] & V_133 ) {
V_4 -= V_3 [ 4 ] + 1 ;
V_3 += V_3 [ 4 ] + 1 ;
if ( ! V_4 )
return 0 ;
}
F_34 ( V_3 + 4 , V_4 - 4 , V_38 ) ;
return 0 ;
}
int F_44 ( struct V_5 * V_13 , const T_1 * V_3 , T_2 V_4 )
{
struct V_19 * V_21 = V_13 -> V_21 ;
struct V_16 * V_16 = (struct V_16 * ) V_21 -> V_7 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( V_16 -> V_134 && V_21 -> V_135 . V_136 -> V_137 != V_138 )
return 0 ;
switch ( V_13 -> V_139 ) {
case 0 :
if ( V_16 -> V_140 . V_141 == V_142 )
return - V_143 ;
break;
case 1 :
if ( V_16 -> V_144 . V_141 == V_145 )
return - V_143 ;
break;
default:
return - 1 ;
}
return F_32 ( V_16 , V_13 -> V_139 , V_3 , V_4 ) ;
}
void F_45 ( struct V_16 * V_16 , struct V_146 * V_147 )
{
struct V_148 * V_149 = & V_16 -> V_150 ;
int V_151 ;
F_46 ( & V_149 -> V_152 ) ;
V_151 = ( V_149 -> V_153 + 1 ) % V_154 ;
if ( V_151 == V_149 -> V_155 ) {
V_149 -> V_156 = 1 ;
V_149 -> V_155 = ( V_149 -> V_155 + 1 ) % V_154 ;
}
memcpy ( & V_149 -> V_149 [ V_149 -> V_153 ] , V_147 , sizeof( struct V_146 ) ) ;
V_149 -> V_153 = V_151 ;
F_47 ( & V_149 -> V_152 ) ;
F_48 ( & V_149 -> V_157 ) ;
}
static int F_49 ( struct V_16 * V_16 , struct V_146 * V_147 , int V_158 )
{
struct V_148 * V_149 = & V_16 -> V_150 ;
if ( V_149 -> V_156 ) {
V_149 -> V_156 = 0 ;
return - V_159 ;
}
if ( V_149 -> V_153 == V_149 -> V_155 ) {
int V_18 ;
if ( V_158 & V_160 )
return - V_94 ;
V_18 = F_26 ( V_149 -> V_157 ,
V_149 -> V_153 != V_149 -> V_155 ) ;
if ( V_18 < 0 )
return V_18 ;
}
F_46 ( & V_149 -> V_152 ) ;
memcpy ( V_147 , & V_149 -> V_149 [ V_149 -> V_155 ] ,
sizeof( struct V_146 ) ) ;
V_149 -> V_155 = ( V_149 -> V_155 + 1 ) % V_154 ;
F_47 ( & V_149 -> V_152 ) ;
return 0 ;
}
static unsigned int F_50 ( struct V_161 * V_161 , T_7 * V_162 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
unsigned int V_166 = 0 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ( V_161 -> V_167 & V_168 ) != V_169 )
F_51 ( V_161 , & V_16 -> V_85 . V_47 , V_162 ) ;
F_51 ( V_161 , & V_16 -> V_150 . V_157 , V_162 ) ;
if ( V_16 -> V_150 . V_153 != V_16 -> V_150 . V_155 )
V_166 = V_170 ;
if ( ( V_161 -> V_167 & V_168 ) != V_169 ) {
if ( V_16 -> V_22 ) {
if ( V_98 )
V_166 |= ( V_171 | V_172 ) ;
} else {
V_166 |= ( V_171 | V_172 ) ;
}
}
return V_166 ;
}
static T_5 F_52 ( struct V_161 * V_161 , const char T_6 * V_3 ,
T_2 V_76 , T_8 * V_173 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
unsigned char V_106 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ( V_161 -> V_167 & V_168 ) == V_169 )
return - V_174 ;
if ( V_16 -> V_144 . V_141 != V_145 )
return - V_174 ;
if ( F_53 ( V_106 , V_3 ) )
return - V_96 ;
if ( V_106 == 0x47 && V_76 % V_95 == 0 )
return F_30 ( V_16 , V_3 , V_76 , V_161 -> V_167 & V_160 , 1 ) ;
else
return F_33 ( V_16 , V_3 , V_76 , V_161 -> V_167 & V_160 , 1 ) ;
}
static unsigned int F_54 ( struct V_161 * V_161 , T_7 * V_162 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
unsigned int V_166 = 0 ;
F_4 ( 2 , L_2 , V_16 ) ;
F_51 ( V_161 , & V_16 -> V_86 . V_47 , V_162 ) ;
if ( V_16 -> V_22 ) {
if ( F_25 ( & V_16 -> V_86 ) >= 20 * 1024 )
V_166 |= ( V_171 | V_172 ) ;
} else
V_166 = ( V_171 | V_172 ) ;
return V_166 ;
}
static T_5 F_55 ( struct V_161 * V_161 , const char T_6 * V_3 ,
T_2 V_76 , T_8 * V_173 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
unsigned char V_106 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( V_16 -> V_140 . V_141 != V_142 ) {
F_15 ( V_175 L_7 ) ;
return - V_174 ;
}
if ( F_53 ( V_106 , V_3 ) )
return - V_96 ;
if ( V_106 == 0x47 && V_76 % V_95 == 0 )
return F_30 ( V_16 , V_3 , V_76 , V_161 -> V_167 & V_160 , 0 ) ;
else
return F_36 ( V_16 , V_3 , V_76 , V_161 -> V_167 & V_160 , 0 ) ;
}
static int F_56 ( struct V_16 * V_16 , char T_6 * V_3 , unsigned int V_4 , int V_87 )
{
unsigned V_77 , V_97 ;
int V_176 = 0 ;
int V_177 = 0 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ! ( V_16 -> V_22 & V_33 ) ) {
if ( F_7 ( V_16 , V_33 ) < 0 )
return - V_24 ;
}
for ( V_77 = 0 ; V_77 < V_4 ; V_77 ++ ) {
unsigned char V_106 ;
if ( F_53 ( V_106 , V_3 + V_77 ) )
return - V_96 ;
if ( V_177 == 5 ) {
V_176 = V_106 & 0x08 ;
V_177 = 0 ;
}
if ( V_106 == 0x00 ) {
V_177 = ( V_177 == 1 || V_177 == 2 ) ? 2 : 1 ;
continue;
}
switch ( V_177 ++ ) {
case 2 : if ( V_106 == 0x01 )
continue;
break;
case 3 : if ( V_106 == 0xb5 )
continue;
break;
case 4 : if ( ( V_106 & 0xf0 ) == 0x10 )
continue;
break;
}
V_177 = 0 ;
}
V_97 = V_178 / V_4 + 1 ;
F_35 ( V_16 , V_179 , sizeof( V_179 ) , 0 , 1 ) ;
for ( V_77 = 0 ; V_77 < V_97 ; V_77 ++ )
F_33 ( V_16 , V_3 , V_4 , 0 , 1 ) ;
F_43 ( & V_16 -> V_38 [ 1 ] ) ;
if ( V_176 )
return F_57 ( V_16 , V_180 , 1 ) ;
else
return 0 ;
}
static int F_58 ( struct V_161 * V_161 ,
unsigned int V_181 , void * V_182 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
unsigned long V_183 = ( unsigned long ) V_182 ;
int V_18 = 0 ;
F_4 ( 1 , L_8 , V_16 , V_181 ) ;
if ( ( V_161 -> V_167 & V_168 ) == V_169 ) {
if ( V_181 != V_184 && V_181 != V_185 &&
V_181 != V_186 ) {
return - V_174 ;
}
}
if ( F_59 ( & V_16 -> V_187 ) )
return - V_188 ;
switch ( V_181 ) {
case V_189 :
V_16 -> V_144 . V_190 = V_191 ;
if ( V_16 -> V_144 . V_141 == V_145 )
V_18 = F_9 ( V_16 , V_33 ) ;
else
V_18 = F_57 ( V_16 , V_192 ,
V_16 -> V_144 . V_193 ? 0 : 1 ) ;
if ( ! V_18 )
V_16 -> V_194 = V_195 ;
break;
case V_196 :
V_16 -> V_194 = V_195 ;
if ( V_16 -> V_144 . V_190 == V_197 ) {
V_16 -> V_144 . V_190 = V_198 ;
V_18 = F_57 ( V_16 , V_199 , 0 ) ;
if ( V_18 )
break;
}
if ( V_16 -> V_144 . V_141 == V_145 ) {
if ( V_16 -> V_22 == V_35 ) {
V_18 = F_5 ( V_16 , V_25 , V_26 , 0 ) ;
if ( V_18 )
break;
V_16 -> V_22 &= ~ V_33 ;
}
V_18 = F_7 ( V_16 , V_33 ) ;
}
if ( ! V_18 )
V_18 = F_57 ( V_16 , V_199 , 0 ) ;
if ( ! V_18 )
V_16 -> V_144 . V_190 = V_198 ;
break;
case V_200 :
V_16 -> V_144 . V_190 = V_197 ;
if ( V_16 -> V_22 & V_33 )
V_18 = F_5 ( V_16 , V_25 , V_201 , 0 ) ;
else
V_18 = F_57 ( V_16 , V_180 , 1 ) ;
if ( ! V_18 )
V_16 -> V_194 = V_202 ;
break;
case V_203 :
if ( V_16 -> V_22 & V_33 )
V_18 = F_5 ( V_16 , V_25 , V_204 , 0 ) ;
if ( ! V_18 )
V_18 = F_57 ( V_16 , V_199 , 0 ) ;
if ( ! V_18 ) {
V_16 -> V_144 . V_190 = V_198 ;
V_16 -> V_194 = V_195 ;
}
break;
case V_205 :
V_16 -> V_144 . V_141 = ( V_206 ) V_183 ;
break;
case V_207 :
V_16 -> V_144 . V_193 = ( int ) V_183 ;
break;
case V_184 :
memcpy ( V_182 , & V_16 -> V_144 , sizeof( struct V_208 ) ) ;
break;
case V_185 :
V_18 = F_49 ( V_16 , V_182 , V_161 -> V_167 ) ;
break;
case V_186 :
memcpy ( V_182 , & V_16 -> V_209 , sizeof( V_210 ) ) ;
break;
case V_211 :
{
T_9 V_212 = ( T_9 ) V_183 ;
switch ( V_212 ) {
case V_213 :
V_16 -> V_214 = V_215 ;
break;
case V_216 :
V_16 -> V_214 = V_217 ;
break;
case V_218 :
V_16 -> V_214 = V_219 ;
break;
default:
V_18 = - V_143 ;
}
if ( V_18 < 0 )
break;
V_16 -> V_144 . V_220 = V_212 ;
V_18 = F_5 ( V_16 , V_67 , V_221 ,
1 , V_16 -> V_214 ) ;
break;
}
case V_222 :
if ( V_183 > 1 ) {
V_18 = - V_143 ;
break;
}
V_16 -> V_223 = V_183 ;
V_18 = F_5 ( V_16 , V_67 , V_224 ,
1 , ( T_4 ) V_183 ) ;
break;
case V_225 :
{
struct V_226 * V_227 =
(struct V_226 * ) V_182 ;
V_16 -> V_144 . V_141 = V_145 ;
F_60 ( & V_16 -> V_85 ) ;
V_18 = F_56 ( V_16 , V_227 -> V_228 , V_227 -> V_229 ,
V_161 -> V_167 & V_160 ) ;
break;
}
case V_230 :
if ( V_16 -> V_22 & V_33 )
V_18 = F_5 ( V_16 , V_25 ,
V_231 , 2 , V_36 , 0 ) ;
else
V_18 = F_57 ( V_16 , V_232 , V_183 ) ;
if ( ! V_18 ) {
V_16 -> V_194 = V_233 ;
V_16 -> V_144 . V_190 = V_198 ;
}
break;
case V_234 :
if ( V_16 -> V_22 & V_33 ) {
if ( V_16 -> V_194 != V_235 )
V_18 = F_5 ( V_16 , V_25 , V_236 , 2 , 0 , 0 ) ;
if ( ! V_18 )
V_18 = F_57 ( V_16 , V_237 , V_183 ) ;
} else {
V_18 = F_57 ( V_16 , V_199 , 0 ) ;
if ( ! V_18 )
V_18 = F_57 ( V_16 , V_192 , 0 ) ;
if ( ! V_18 )
V_18 = F_57 ( V_16 , V_237 , V_183 ) ;
}
if ( ! V_18 ) {
V_16 -> V_194 = V_235 ;
V_16 -> V_144 . V_190 = V_198 ;
}
break;
case V_238 :
* ( int * ) V_182 = V_239 | V_240 |
V_241 | V_242 ;
break;
case V_243 :
F_60 ( & V_16 -> V_85 ) ;
F_8 ( & V_16 -> V_38 [ 1 ] ) ;
if ( V_16 -> V_22 == V_35 ) {
V_18 = F_5 ( V_16 , V_25 ,
V_39 , 2 , V_36 , 0 ) ;
if ( V_18 )
break;
if ( V_16 -> V_194 == V_233 )
V_18 = F_5 ( V_16 , V_25 ,
V_231 , 2 , V_36 , 0 ) ;
if ( V_16 -> V_194 == V_235 ) {
V_18 = F_5 ( V_16 , V_25 ,
V_236 , 2 , 0 , 0 ) ;
if ( ! V_18 )
V_18 = F_57 ( V_16 , V_237 , V_183 ) ;
}
if ( V_16 -> V_194 == V_202 )
V_18 = F_57 ( V_16 , V_192 , 1 ) ;
}
break;
case V_244 :
break;
default:
V_18 = - V_245 ;
break;
}
F_61 ( & V_16 -> V_187 ) ;
return V_18 ;
}
static int F_62 ( struct V_161 * V_161 ,
unsigned int V_181 , void * V_182 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
unsigned long V_183 = ( unsigned long ) V_182 ;
int V_18 = 0 ;
F_4 ( 1 , L_8 , V_16 , V_181 ) ;
if ( ( ( V_161 -> V_167 & V_168 ) == V_169 ) &&
( V_181 != V_246 ) )
return - V_174 ;
if ( F_59 ( & V_16 -> V_187 ) )
return - V_188 ;
switch ( V_181 ) {
case V_247 :
if ( V_16 -> V_140 . V_141 == V_142 )
V_18 = F_9 ( V_16 , V_28 ) ;
else
V_18 = F_63 ( V_16 , V_248 ) ;
if ( ! V_18 )
V_16 -> V_140 . V_190 = V_249 ;
break;
case V_250 :
if ( V_16 -> V_140 . V_141 == V_142 )
V_18 = F_7 ( V_16 , V_28 ) ;
if ( ! V_18 )
V_18 = F_63 ( V_16 , V_251 ) ;
if ( ! V_18 )
V_16 -> V_140 . V_190 = V_252 ;
break;
case V_253 :
V_18 = F_63 ( V_16 , V_248 ) ;
if ( ! V_18 )
V_16 -> V_140 . V_190 = V_254 ;
break;
case V_255 :
if ( V_16 -> V_140 . V_190 == V_254 ) {
V_16 -> V_140 . V_190 = V_252 ;
V_18 = F_63 ( V_16 , V_251 | V_256 ) ;
}
break;
case V_257 :
V_16 -> V_140 . V_141 = ( V_258 ) V_183 ;
break;
case V_259 :
{
V_18 = F_63 ( V_16 , V_183 ? V_248 : V_251 ) ;
if ( ! V_18 )
V_16 -> V_140 . V_260 = ( int ) V_183 ;
break;
}
case V_261 :
V_16 -> V_140 . V_262 = ( int ) V_183 ;
V_18 = F_63 ( V_16 , V_183 ? V_263 : V_264 ) ;
break;
case V_265 :
if ( F_64 ( V_16 -> V_266 ) < 0x2621 )
V_18 = - V_143 ;
V_16 -> V_140 . V_267 = ( int ) V_183 ;
break;
case V_268 :
V_16 -> V_140 . V_269 = ( V_270 ) V_183 ;
switch( V_16 -> V_140 . V_269 ) {
case V_271 :
V_18 = F_63 ( V_16 , V_272 ) ;
if ( ! V_18 ) {
if ( V_16 -> V_59 == V_61 )
F_20 ( V_16 , 0x20 , 0x02 , 0x49 ) ;
else if ( V_16 -> V_59 == V_64 )
F_21 ( V_16 , V_63 , 0x0008 , 0x0220 ) ;
}
break;
case V_273 :
V_18 = F_63 ( V_16 , V_274 ) ;
if ( ! V_18 ) {
if ( V_16 -> V_59 == V_61 )
F_20 ( V_16 , 0x20 , 0x02 , 0x4a ) ;
else if ( V_16 -> V_59 == V_64 )
F_21 ( V_16 , V_63 , 0x0008 , 0x0200 ) ;
}
break;
case V_275 :
V_18 = F_63 ( V_16 , V_276 ) ;
if ( ! V_18 ) {
if ( V_16 -> V_59 == V_61 )
F_20 ( V_16 , 0x20 , 0x02 , 0x45 ) ;
else if ( V_16 -> V_59 == V_64 )
F_21 ( V_16 , V_63 , 0x0008 , 0x0210 ) ;
}
break;
default:
V_18 = - V_143 ;
break;
}
break;
case V_246 :
memcpy ( V_182 , & V_16 -> V_140 , sizeof( struct V_277 ) ) ;
break;
case V_278 :
if ( F_64 ( V_16 -> V_266 ) < 0x2621 )
* ( unsigned int * ) V_182 = V_279 | V_280 | V_281 ;
else
* ( unsigned int * ) V_182 = V_279 | V_282 | V_283 |
V_280 | V_281 ;
break;
case V_284 :
F_60 ( & V_16 -> V_86 ) ;
F_8 ( & V_16 -> V_38 [ 0 ] ) ;
if ( V_16 -> V_22 == V_35 )
V_18 = F_5 ( V_16 , V_25 ,
V_39 , 2 , V_36 , 0 ) ;
break;
case V_285 :
break;
case V_286 :
{
struct V_287 * V_288 = (struct V_287 * ) V_182 ;
V_18 = F_18 ( V_16 , V_288 -> V_57 , V_288 -> V_58 ) ;
break;
}
case V_289 :
break;
default:
V_18 = - V_245 ;
}
F_61 ( & V_16 -> V_187 ) ;
return V_18 ;
}
static int F_65 ( struct V_290 * V_290 , struct V_161 * V_161 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
int V_52 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ( V_52 = F_66 ( V_290 , V_161 ) ) < 0 )
return V_52 ;
if ( ( V_161 -> V_167 & V_168 ) != V_169 ) {
F_60 ( & V_16 -> V_86 ) ;
F_60 ( & V_16 -> V_85 ) ;
V_16 -> V_193 = 1 ;
V_16 -> V_140 . V_262 = 1 ;
V_16 -> V_144 . V_141 = V_291 ;
V_16 -> V_150 . V_155 = V_16 -> V_150 . V_153 = 0 ;
}
return 0 ;
}
static int F_67 ( struct V_290 * V_290 , struct V_161 * V_161 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( ( V_161 -> V_167 & V_168 ) != V_169 ) {
F_9 ( V_16 , V_33 ) ;
}
return F_68 ( V_290 , V_161 ) ;
}
static int F_69 ( struct V_290 * V_290 , struct V_161 * V_161 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
int V_52 = F_66 ( V_290 , V_161 ) ;
F_4 ( 2 , L_2 , V_16 ) ;
if ( V_52 < 0 )
return V_52 ;
F_60 ( & V_16 -> V_86 ) ;
V_16 -> V_140 . V_141 = V_292 ;
return 0 ;
}
static int F_70 ( struct V_290 * V_290 , struct V_161 * V_161 )
{
struct V_163 * V_164 = V_161 -> V_165 ;
struct V_16 * V_16 = V_164 -> V_7 ;
F_4 ( 2 , L_2 , V_16 ) ;
F_9 ( V_16 , V_28 ) ;
return F_68 ( V_290 , V_161 ) ;
}
int F_71 ( struct V_16 * V_16 )
{
V_16 -> V_140 . V_262 = 0 ;
V_16 -> V_140 . V_260 = 0 ;
V_16 -> V_140 . V_190 = V_249 ;
V_16 -> V_140 . V_141 = V_292 ;
V_16 -> V_140 . V_269 = V_271 ;
V_16 -> V_140 . V_267 = 0 ;
V_16 -> V_144 . V_193 = 0 ;
V_16 -> V_144 . V_190 = V_191 ;
V_16 -> V_144 . V_141 = V_291 ;
V_16 -> V_144 . V_293 = V_294 ;
V_16 -> V_144 . V_220 = V_216 ;
V_16 -> V_223 = V_294 ;
V_16 -> V_214 = V_217 ;
F_72 ( & V_16 -> V_150 . V_157 ) ;
F_73 ( & V_16 -> V_150 . V_152 ) ;
V_16 -> V_150 . V_153 = V_16 -> V_150 . V_155 = 0 ;
V_16 -> V_150 . V_156 = 0 ;
memset ( & V_16 -> V_209 , 0 , sizeof ( V_210 ) ) ;
F_74 ( & V_16 -> V_295 , & V_16 -> V_296 ,
& V_297 , V_16 , V_298 ) ;
F_74 ( & V_16 -> V_295 , & V_16 -> V_299 ,
& V_300 , V_16 , V_301 ) ;
return 0 ;
}
void F_75 ( struct V_16 * V_16 )
{
F_76 ( V_16 -> V_299 ) ;
F_76 ( V_16 -> V_296 ) ;
}
int F_77 ( struct V_16 * V_16 )
{
void (* F_78 [])( T_1 * , int , void * ) = { F_29 , play_video_cb }
