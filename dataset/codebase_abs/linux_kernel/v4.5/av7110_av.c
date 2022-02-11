int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
if ( ! ( V_6 -> V_8 & V_9 ) )
return 0 ;
if ( V_3 [ 3 ] == 0xe0 )
V_3 [ 4 ] = V_3 [ 5 ] = 0 ;
if ( V_6 -> V_8 & V_10 )
return V_6 -> V_11 . V_12 ( V_3 , V_4 , NULL , 0 ,
& V_6 -> V_13 . V_12 ) ;
else
return V_1 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_2 ( void * V_7 , unsigned char * V_14 )
{
struct V_5 * V_6 = (struct V_5 * ) V_7 ;
V_6 -> V_11 . V_12 ( V_14 , 188 , NULL , 0 ,
& V_6 -> V_13 . V_12 ) ;
return 0 ;
}
int F_3 ( struct V_15 * V_15 , int V_16 ,
struct V_5 * V_6 )
{
int V_17 = 0 ;
struct V_18 * V_19 = V_6 -> V_20 ;
F_4 ( 2 , L_1 , V_15 , V_6 ) ;
if ( V_15 -> V_21 || ( V_15 -> V_22 & V_16 ) )
return - V_23 ;
F_5 ( V_15 , V_24 , V_25 , 0 ) ;
V_19 -> V_26 = 1 ;
V_15 -> V_22 |= V_16 ;
switch ( V_15 -> V_22 ) {
case V_27 :
F_6 ( & V_15 -> V_2 [ 0 ] ,
V_19 -> V_28 [ 0 ] -> V_29 ,
F_2 ,
( void * ) V_19 -> V_28 [ 0 ] ) ;
V_17 = F_5 ( V_15 , V_24 , V_30 , 2 , V_31 , 0 ) ;
break;
case V_32 :
F_6 ( & V_15 -> V_2 [ 1 ] ,
V_19 -> V_28 [ 1 ] -> V_29 ,
F_2 ,
( void * ) V_19 -> V_28 [ 1 ] ) ;
V_17 = F_5 ( V_15 , V_24 , V_30 , 2 , V_33 , 0 ) ;
break;
case V_34 :
F_6 ( & V_15 -> V_2 [ 0 ] ,
V_19 -> V_28 [ 0 ] -> V_29 ,
F_2 ,
( void * ) V_19 -> V_28 [ 0 ] ) ;
F_6 ( & V_15 -> V_2 [ 1 ] ,
V_19 -> V_28 [ 1 ] -> V_29 ,
F_2 ,
( void * ) V_19 -> V_28 [ 1 ] ) ;
V_17 = F_5 ( V_15 , V_24 , V_30 , 2 , V_35 , 0 ) ;
break;
}
return V_17 ;
}
int F_7 ( struct V_15 * V_15 , int V_16 )
{
int V_17 = 0 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( V_15 -> V_22 )
return - V_23 ;
if ( V_15 -> V_21 & V_16 )
return - V_23 ;
F_5 ( V_15 , V_24 , V_25 , 0 ) ;
if ( V_15 -> V_21 == V_36 ) {
F_8 ( & V_15 -> V_37 [ 0 ] ) ;
F_8 ( & V_15 -> V_37 [ 1 ] ) ;
}
V_15 -> V_21 |= V_16 ;
switch ( V_15 -> V_21 ) {
case V_27 :
V_17 = F_5 ( V_15 , V_24 , V_38 , 2 , V_31 , 0 ) ;
break;
case V_32 :
V_17 = F_5 ( V_15 , V_24 , V_38 , 2 , V_33 , 0 ) ;
V_15 -> V_39 = 0 ;
break;
case V_34 :
V_15 -> V_39 = 0 ;
V_17 = F_5 ( V_15 , V_24 , V_38 , 2 , V_35 , 0 ) ;
break;
}
return V_17 ;
}
int F_9 ( struct V_15 * V_15 , int V_16 )
{
int V_17 = 0 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ! ( V_15 -> V_21 & V_16 ) && ! ( V_15 -> V_22 & V_16 ) )
return 0 ;
F_5 ( V_15 , V_24 , V_25 , 0 ) ;
if ( V_15 -> V_21 ) {
V_15 -> V_21 &= ~ V_16 ;
switch ( V_15 -> V_21 ) {
case V_27 :
V_17 = F_5 ( V_15 , V_24 , V_38 , 2 , V_31 , 0 ) ;
break;
case V_32 :
V_17 = F_5 ( V_15 , V_24 , V_38 , 2 , V_33 , 0 ) ;
break;
case V_36 :
V_17 = F_10 ( V_15 , V_15 -> V_40 ) ;
break;
}
} else {
V_15 -> V_22 &= ~ V_16 ;
switch ( V_15 -> V_22 ) {
case V_27 :
V_17 = F_5 ( V_15 , V_24 , V_30 , 2 , V_31 , 0 ) ;
break;
case V_32 :
V_17 = F_5 ( V_15 , V_24 , V_30 , 2 , V_33 , 0 ) ;
break;
case V_36 :
break;
}
}
return V_17 ;
}
int F_11 ( void * V_41 , struct V_42 * V_3 , int V_43 )
{
int V_4 ;
T_3 V_44 ;
T_4 V_45 ;
if ( ! V_43 ) {
F_12 ( & V_3 -> V_46 ) ;
return - 1 ;
}
while ( 1 ) {
V_4 = F_13 ( V_3 ) ;
if ( V_4 < 6 ) {
F_12 ( & V_3 -> V_46 ) ;
return - 1 ;
}
V_44 = F_14 ( V_3 , 0 ) << 24 ;
V_44 |= F_14 ( V_3 , 1 ) << 16 ;
V_44 |= F_14 ( V_3 , 2 ) << 8 ;
V_44 |= F_14 ( V_3 , 3 ) ;
if ( ( ( V_44 & ~ 0x0f ) == 0x000001e0 ) ||
( ( V_44 & ~ 0x1f ) == 0x000001c0 ) ||
( V_44 == 0x000001bd ) )
break;
F_15 ( L_3 ) ;
F_16 ( V_3 , 1 ) ;
}
V_45 = F_14 ( V_3 , 4 ) << 8 ;
V_45 |= F_14 ( V_3 , 5 ) ;
V_45 += 6 ;
if ( V_4 < V_45 || V_45 > V_43 ) {
F_12 ( & V_3 -> V_46 ) ;
return - 1 ;
}
F_17 ( V_3 , V_41 , ( T_2 ) V_45 ) ;
F_4 ( 2 , L_4 ,
( unsigned long ) V_3 -> V_47 , ( unsigned long ) V_3 -> V_48 ) ;
F_12 ( & V_3 -> V_46 ) ;
return V_45 ;
}
int F_18 ( struct V_15 * V_15 , unsigned int V_49 ,
unsigned int V_50 )
{
unsigned int V_51 , V_52 , V_53 = 0 ;
int V_54 ;
F_4 ( 2 , L_2 , V_15 ) ;
V_15 -> V_55 . V_56 = V_49 ;
V_15 -> V_55 . V_57 = V_50 ;
switch ( V_15 -> V_58 ) {
case V_59 :
V_49 = ( V_49 * 256 ) / 1036 ;
V_50 = ( V_50 * 256 ) / 1036 ;
if ( V_49 > 0x3f )
V_49 = 0x3f ;
if ( V_50 > 0x3f )
V_50 = 0x3f ;
if ( ( V_54 = F_19 ( V_15 , 3 , 0x80 + V_49 ) ) )
return V_54 ;
return F_19 ( V_15 , 4 , V_50 ) ;
case V_60 :
V_49 = 127 - V_49 / 2 ;
V_50 = 127 - V_50 / 2 ;
F_20 ( V_15 , 0x20 , 0x03 , V_49 ) ;
F_20 ( V_15 , 0x20 , 0x04 , V_50 ) ;
return 0 ;
case V_61 :
V_51 = ( V_49 > V_50 ) ? V_49 : V_50 ;
V_52 = ( V_51 * 0x73 / 255 ) << 8 ;
if ( V_51 > 0 )
V_53 = ( ( V_50 - V_49 ) * 127 ) / V_51 ;
F_21 ( V_15 , V_62 , 0x0001 , V_53 << 8 ) ;
F_21 ( V_15 , V_62 , 0x0000 , V_52 ) ;
F_21 ( V_15 , V_62 , 0x0006 , V_52 ) ;
return 0 ;
case V_63 :
V_51 = ( V_49 > V_50 ) ? V_49 : V_50 ;
V_52 = ( V_51 * 0x73 / 255 ) << 8 ;
if ( V_51 > 0 )
V_53 = ( ( V_50 - V_49 ) * 127 ) / V_51 ;
F_21 ( V_15 , V_62 , 0x0001 , V_53 << 8 ) ;
F_21 ( V_15 , V_62 , 0x0000 , V_52 ) ;
return 0 ;
}
return 0 ;
}
int F_10 ( struct V_15 * V_15 , enum V_64 V_65 )
{
int V_17 ;
F_4 ( 2 , L_2 , V_15 ) ;
V_17 = F_5 ( V_15 , V_66 , V_67 , 1 , V_65 ) ;
if ( ! V_17 && ! V_15 -> V_21 ) {
V_17 = F_22 ( V_15 , V_15 -> V_68 [ V_69 ] ,
V_15 -> V_68 [ V_70 ] ,
V_15 -> V_68 [ V_71 ] ,
0 , V_15 -> V_68 [ V_72 ] ) ;
if ( ! V_17 )
V_17 = F_5 ( V_15 , V_73 , V_74 , 0 ) ;
}
return V_17 ;
}
static int F_23 ( struct V_15 * V_15 , T_1 * V_3 , int V_75 )
{
int V_76 ;
int V_77 , V_78 ;
int V_79 ;
T_1 * V_80 ;
int V_17 = 0 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( V_15 -> V_39 )
return 0 ;
for ( V_76 = 7 ; V_76 < V_75 - 10 ; V_76 ++ ) {
V_80 = V_3 + V_76 ;
if ( V_80 [ 0 ] || V_80 [ 1 ] || V_80 [ 2 ] != 0x01 || V_80 [ 3 ] != 0xb3 )
continue;
V_80 += 4 ;
V_77 = ( ( V_80 [ 1 ] & 0xF0 ) >> 4 ) | ( V_80 [ 0 ] << 4 ) ;
V_78 = ( ( V_80 [ 1 ] & 0x0F ) << 8 ) | ( V_80 [ 2 ] ) ;
V_79 = ( V_80 [ 3 ] & 0x0F ) ;
V_17 = F_10 ( V_15 , V_81 [ V_79 ] ) ;
if ( ! V_17 ) {
F_4 ( 2 , L_5 , V_77 , V_78 , V_79 ) ;
V_15 -> V_39 = 1 ;
}
break;
}
return V_17 ;
}
static inline long F_24 ( struct V_42 * V_82 ,
const T_1 * V_3 , unsigned long V_75 )
{
unsigned long V_83 = V_75 ;
int free ;
while ( V_83 > 0 ) {
if ( F_25 ( V_82 ) < 2048 ) {
if ( F_26 ( V_82 -> V_46 ,
( F_25 ( V_82 ) >= 2048 ) ) )
return V_75 - V_83 ;
}
free = F_25 ( V_82 ) ;
if ( free > V_83 )
free = V_83 ;
F_27 ( V_82 , V_3 , free ) ;
V_83 -= free ;
V_3 += free ;
}
return V_75 - V_83 ;
}
static void F_28 ( T_1 * V_3 , int V_75 , void * V_7 )
{
struct V_15 * V_15 = (struct V_15 * ) V_7 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ( V_3 [ 3 ] & 0xe0 ) == 0xe0 ) {
F_23 ( V_15 , V_3 , V_75 ) ;
F_24 ( & V_15 -> V_84 , V_3 , V_75 ) ;
} else
F_24 ( & V_15 -> V_85 , V_3 , V_75 ) ;
}
static void F_29 ( T_1 * V_3 , int V_75 , void * V_7 )
{
struct V_15 * V_15 = (struct V_15 * ) V_7 ;
F_4 ( 2 , L_2 , V_15 ) ;
F_24 ( & V_15 -> V_85 , V_3 , V_75 ) ;
}
static T_5 F_30 ( struct V_15 * V_15 , const char T_6 * V_3 ,
unsigned long V_75 , int V_86 , int type )
{
struct V_42 * V_87 ;
T_1 * V_88 ;
unsigned long V_83 = V_75 ;
F_4 ( 2 , L_6 , V_89 , type , V_75 ) ;
V_87 = ( type ) ? & V_15 -> V_84 : & V_15 -> V_85 ;
V_88 = V_15 -> V_90 [ type ] ;
if ( ! V_88 )
return - V_91 ;
if ( V_86 && ! V_92 )
return - V_93 ;
while ( V_83 >= V_94 ) {
if ( ! V_92 ) {
if ( V_86 )
return V_75 - V_83 ;
if ( F_26 ( V_87 -> V_46 , V_92 ) )
return V_75 - V_83 ;
}
if ( F_31 ( V_88 , V_3 , V_94 ) )
return - V_95 ;
F_32 ( V_15 , type , V_88 , V_94 ) ;
V_83 -= V_94 ;
V_3 += V_94 ;
}
return V_75 - V_83 ;
}
static T_5 F_33 ( struct V_15 * V_15 , const char T_6 * V_3 ,
unsigned long V_75 , int V_86 , int type )
{
unsigned long V_83 = V_75 , V_96 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ! V_15 -> V_90 [ type ] )
return - V_91 ;
if ( V_86 && ! V_97 )
return - V_93 ;
while ( V_83 > 0 ) {
if ( ! V_97 ) {
if ( V_86 )
return V_75 - V_83 ;
if ( F_26 ( V_15 -> V_84 . V_46 ,
V_97 ) )
return V_75 - V_83 ;
}
V_96 = V_83 ;
if ( V_96 > V_98 * 2 )
V_96 = V_98 * 2 ;
if ( F_31 ( V_15 -> V_90 [ type ] , V_3 , V_96 ) )
return - V_95 ;
F_34 ( V_15 -> V_90 [ type ] , V_96 ,
& V_15 -> V_37 [ type ] ) ;
V_83 -= V_96 ;
V_3 += V_96 ;
}
return V_75 - V_83 ;
}
static T_5 F_35 ( struct V_15 * V_15 , const T_1 * V_3 ,
unsigned long V_75 , int V_86 , int type )
{
unsigned long V_83 = V_75 , V_96 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ! V_15 -> V_90 [ type ] )
return - V_91 ;
if ( V_86 && ! V_97 )
return - V_93 ;
while ( V_83 > 0 ) {
if ( ! V_97 ) {
if ( V_86 )
return V_75 - V_83 ;
if ( F_26 ( V_15 -> V_84 . V_46 ,
V_97 ) )
return V_75 - V_83 ;
}
V_96 = V_83 ;
if ( V_96 > V_98 * 2 )
V_96 = V_98 * 2 ;
F_34 ( V_3 , V_96 , & V_15 -> V_37 [ type ] ) ;
V_83 -= V_96 ;
V_3 += V_96 ;
}
return V_75 - V_83 ;
}
static T_5 F_36 ( struct V_15 * V_15 , const char T_6 * V_3 ,
unsigned long V_75 , int V_86 , int type )
{
unsigned long V_83 = V_75 , V_96 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ! V_15 -> V_90 [ type ] )
return - V_91 ;
if ( V_86 && F_25 ( & V_15 -> V_85 ) < 20 * 1024 )
return - V_93 ;
while ( V_83 > 0 ) {
if ( F_25 ( & V_15 -> V_85 ) < 20 * 1024 ) {
if ( V_86 )
return V_75 - V_83 ;
if ( F_26 ( V_15 -> V_85 . V_46 ,
( F_25 ( & V_15 -> V_85 ) >= 20 * 1024 ) ) )
return V_75 - V_83 ;
}
V_96 = V_83 ;
if ( V_96 > V_98 * 2 )
V_96 = V_98 * 2 ;
if ( F_31 ( V_15 -> V_90 [ type ] , V_3 , V_96 ) )
return - V_95 ;
F_34 ( V_15 -> V_90 [ type ] , V_96 ,
& V_15 -> V_37 [ type ] ) ;
V_83 -= V_96 ;
V_3 += V_96 ;
}
return V_75 - V_83 ;
}
void F_37 ( struct V_99 * V_80 , struct V_5 * V_13 )
{
memset ( V_80 -> V_100 , 0 , V_94 ) ;
V_80 -> V_101 = 0 ;
V_80 -> V_102 = 0 ;
V_80 -> V_103 = 0 ;
if ( V_13 )
V_80 -> V_13 = V_13 ;
}
static void F_38 ( struct V_99 * V_80 )
{
memset ( V_80 -> V_100 , 0 , V_94 ) ;
V_80 -> V_102 = 0 ;
V_80 -> V_103 = 0 ;
}
static int F_39 ( T_1 const * V_3 , long int V_104 , int * V_103 )
{
int V_105 = 0 ;
int V_106 = 0 ;
* V_103 = 0 ;
while ( V_105 < V_104 - 3 && ! V_106 ) {
if ( V_3 [ V_105 ] == 0x00 && V_3 [ V_105 + 1 ] == 0x00 &&
V_3 [ V_105 + 2 ] == 0x01 ) {
switch ( V_3 [ V_105 + 3 ] ) {
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 ... V_117 :
case V_118 ... V_119 :
V_106 = 1 ;
break;
default:
V_105 ++ ;
break;
}
} else
V_105 ++ ;
}
if ( V_105 == V_104 - 3 && ! V_106 ) {
if ( V_3 [ V_104 - 1 ] == 0x00 )
* V_103 = 1 ;
if ( V_3 [ V_104 - 2 ] == 0x00 &&
V_3 [ V_104 - 1 ] == 0x00 )
* V_103 = 2 ;
if ( V_3 [ V_104 - 3 ] == 0x00 &&
V_3 [ V_104 - 2 ] == 0x00 &&
V_3 [ V_104 - 1 ] == 0x01 )
* V_103 = 3 ;
return - 1 ;
}
return V_105 ;
}
void F_40 ( T_1 const * V_3 , long int V_104 , T_4 V_29 , struct V_99 * V_80 )
{
int V_105 , V_120 , V_121 , V_122 ;
int V_123 , V_124 ;
V_105 = 0 ;
V_120 = 0 ;
if ( V_80 -> V_103 ) {
V_123 = 0 ;
switch( V_80 -> V_103 ) {
case 1 :
if ( V_3 [ V_105 ] == 0x00 && V_3 [ V_105 + 1 ] == 0x01 ) {
V_123 = 1 ;
V_105 += 2 ;
}
break;
case 2 :
if ( V_3 [ V_105 ] == 0x01 ) {
V_123 = 1 ;
V_105 ++ ;
}
break;
case 3 :
V_123 = 1 ;
}
if ( V_123 ) {
switch ( V_3 [ V_105 ] ) {
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 ... V_117 :
case V_118 ... V_119 :
V_80 -> V_100 [ 0 ] = 0x00 ;
V_80 -> V_100 [ 1 ] = 0x00 ;
V_80 -> V_100 [ 2 ] = 0x01 ;
V_80 -> V_100 [ 3 ] = V_3 [ V_105 ] ;
V_80 -> V_102 = 4 ;
memcpy ( V_80 -> V_100 + V_80 -> V_102 , V_3 + V_105 , ( V_94 - 4 ) - V_80 -> V_102 ) ;
V_105 += ( V_94 - 4 ) - V_80 -> V_102 ;
F_41 ( V_80 -> V_100 , ( V_94 - 4 ) , V_29 , & V_80 -> V_101 , V_80 -> V_13 ) ;
F_38 ( V_80 ) ;
break;
default:
V_105 = 0 ;
break;
}
}
V_80 -> V_103 = 0 ;
}
if ( V_80 -> V_102 ) {
V_120 = F_39 ( V_3 + V_105 , V_104 - V_105 , & V_80 -> V_103 ) ;
if ( V_120 >= 0 && V_120 < ( V_94 - 4 ) - V_80 -> V_102 )
V_121 = V_120 + V_105 ;
else
V_121 = ( V_94 - 4 ) - V_80 -> V_102 ;
memcpy ( V_80 -> V_100 + V_80 -> V_102 , V_3 , V_121 ) ;
V_105 += V_121 ;
V_80 -> V_102 += V_121 ;
F_41 ( V_80 -> V_100 , V_80 -> V_102 , V_29 , & V_80 -> V_101 , V_80 -> V_13 ) ;
F_38 ( V_80 ) ;
}
V_122 = 0 ;
while ( V_105 < V_104 ) {
V_120 = F_39 ( V_3 + V_105 + V_122 , V_104 - V_105 - V_122 , & V_80 -> V_103 ) ;
if ( V_120 >= 0 ) {
V_120 += V_105 + V_122 ;
if ( V_120 > V_105 ) {
F_41 ( V_3 + V_105 , V_120 - V_105 , V_29 , & V_80 -> V_101 , V_80 -> V_13 ) ;
V_105 = V_120 ;
F_38 ( V_80 ) ;
V_122 = 0 ;
} else
V_122 = 1 ;
} else {
V_121 = V_104 - V_105 ;
V_124 = V_121 % ( V_94 - 4 ) ;
V_121 -= V_124 ;
F_41 ( V_3 + V_105 , V_121 , V_29 , & V_80 -> V_101 , V_80 -> V_13 ) ;
memcpy ( V_80 -> V_100 , V_3 + V_105 + V_121 , V_124 ) ;
V_80 -> V_102 = V_124 ;
V_105 = V_104 ;
}
}
}
static int F_42 ( T_4 V_29 , T_1 * V_101 , int V_125 , T_1 * V_3 , T_1 V_104 )
{
int V_76 ;
int V_105 = 0 ;
int V_126 ;
T_1 V_127 [ 4 ] = { 0x47 , 0x00 , 0x00 , 0x10 } ;
V_126 = ( V_94 - 4 ) - V_104 ;
if ( V_125 )
V_127 [ 1 ] = 0x40 ;
if ( V_126 )
V_127 [ 3 ] = 0x30 ;
V_127 [ 1 ] |= ( T_1 ) ( ( V_29 & 0x1F00 ) >> 8 ) ;
V_127 [ 2 ] |= ( T_1 ) ( V_29 & 0x00FF ) ;
V_127 [ 3 ] |= ( ( * V_101 ) ++ & 0x0F ) ;
memcpy ( V_3 , V_127 , 4 ) ;
V_105 += 4 ;
if ( V_126 ) {
V_3 [ 4 ] = V_126 - 1 ;
V_105 ++ ;
if ( V_126 > 1 ) {
V_3 [ 5 ] = 0x00 ;
V_105 ++ ;
}
for ( V_76 = 6 ; V_76 < V_126 + 4 ; V_76 ++ ) {
V_3 [ V_76 ] = 0xFF ;
V_105 ++ ;
}
}
return V_105 ;
}
static void F_41 ( T_1 const * V_3 , long int V_104 , T_4 V_29 , T_1 * V_101 ,
struct V_5 * V_13 )
{
int V_121 , V_125 ;
T_1 V_128 [ V_94 ] ;
long V_105 = 0 ;
V_125 = 0 ;
if ( V_104 > 3 &&
V_3 [ 0 ] == 0x00 && V_3 [ 1 ] == 0x00 && V_3 [ 2 ] == 0x01 )
switch ( V_3 [ 3 ] ) {
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 ... V_117 :
case V_118 ... V_119 :
V_125 = 1 ;
break;
default:
break;
}
while ( V_105 < V_104 ) {
memset ( V_128 , 0 , V_94 ) ;
if ( V_104 - V_105 >= ( V_94 - 4 ) ) {
V_121 = F_42 ( V_29 , V_101 , V_125 ,
V_128 , ( V_94 - 4 ) ) ;
memcpy ( V_128 + V_121 , V_3 + V_105 , V_94 - V_121 ) ;
V_105 += V_94 - V_121 ;
} else {
V_121 = F_42 ( V_29 , V_101 , V_125 ,
V_128 , V_104 - V_105 ) ;
memcpy ( V_128 + V_121 , V_3 + V_105 , V_94 - V_121 ) ;
V_105 = V_104 ;
}
V_13 -> V_11 . V_12 ( V_128 , 188 , NULL , 0 , & V_13 -> V_13 . V_12 ) ;
V_125 = 0 ;
}
}
static int F_32 ( struct V_15 * V_15 , int type , const T_1 * V_3 , T_2 V_4 )
{
struct V_37 * V_37 = & V_15 -> V_37 [ type ] ;
if ( V_3 [ 1 ] & V_129 ) {
F_8 ( V_37 ) ;
return - 1 ;
}
if ( ! ( V_3 [ 3 ] & V_130 ) )
return - 1 ;
if ( V_3 [ 1 ] & V_131 )
F_43 ( V_37 ) ;
if ( V_3 [ 3 ] & V_132 ) {
V_4 -= V_3 [ 4 ] + 1 ;
V_3 += V_3 [ 4 ] + 1 ;
if ( ! V_4 )
return 0 ;
}
F_34 ( V_3 + 4 , V_4 - 4 , V_37 ) ;
return 0 ;
}
int F_44 ( struct V_5 * V_13 , const T_1 * V_3 , T_2 V_4 )
{
struct V_18 * V_20 = V_13 -> V_20 ;
struct V_15 * V_15 = (struct V_15 * ) V_20 -> V_7 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( V_15 -> V_133 && V_20 -> V_134 . V_135 -> V_136 != V_137 )
return 0 ;
switch ( V_13 -> V_138 ) {
case 0 :
if ( V_15 -> V_139 . V_140 == V_141 )
return - V_142 ;
break;
case 1 :
if ( V_15 -> V_143 . V_140 == V_144 )
return - V_142 ;
break;
default:
return - 1 ;
}
return F_32 ( V_15 , V_13 -> V_138 , V_3 , V_4 ) ;
}
void F_45 ( struct V_15 * V_15 , struct V_145 * V_146 )
{
struct V_147 * V_148 = & V_15 -> V_149 ;
int V_150 ;
F_46 ( & V_148 -> V_151 ) ;
V_150 = ( V_148 -> V_152 + 1 ) % V_153 ;
if ( V_150 == V_148 -> V_154 ) {
V_148 -> V_155 = 1 ;
V_148 -> V_154 = ( V_148 -> V_154 + 1 ) % V_153 ;
}
memcpy ( & V_148 -> V_148 [ V_148 -> V_152 ] , V_146 , sizeof( struct V_145 ) ) ;
V_148 -> V_152 = V_150 ;
F_47 ( & V_148 -> V_151 ) ;
F_48 ( & V_148 -> V_156 ) ;
}
static int F_49 ( struct V_15 * V_15 , struct V_145 * V_146 , int V_157 )
{
struct V_147 * V_148 = & V_15 -> V_149 ;
if ( V_148 -> V_155 ) {
V_148 -> V_155 = 0 ;
return - V_158 ;
}
if ( V_148 -> V_152 == V_148 -> V_154 ) {
int V_17 ;
if ( V_157 & V_159 )
return - V_93 ;
V_17 = F_26 ( V_148 -> V_156 ,
V_148 -> V_152 != V_148 -> V_154 ) ;
if ( V_17 < 0 )
return V_17 ;
}
F_46 ( & V_148 -> V_151 ) ;
memcpy ( V_146 , & V_148 -> V_148 [ V_148 -> V_154 ] ,
sizeof( struct V_145 ) ) ;
V_148 -> V_154 = ( V_148 -> V_154 + 1 ) % V_153 ;
F_47 ( & V_148 -> V_151 ) ;
return 0 ;
}
static unsigned int F_50 ( struct V_160 * V_160 , T_7 * V_161 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
unsigned int V_165 = 0 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ( V_160 -> V_166 & V_167 ) != V_168 )
F_51 ( V_160 , & V_15 -> V_84 . V_46 , V_161 ) ;
F_51 ( V_160 , & V_15 -> V_149 . V_156 , V_161 ) ;
if ( V_15 -> V_149 . V_152 != V_15 -> V_149 . V_154 )
V_165 = V_169 ;
if ( ( V_160 -> V_166 & V_167 ) != V_168 ) {
if ( V_15 -> V_21 ) {
if ( V_97 )
V_165 |= ( V_170 | V_171 ) ;
} else {
V_165 |= ( V_170 | V_171 ) ;
}
}
return V_165 ;
}
static T_5 F_52 ( struct V_160 * V_160 , const char T_6 * V_3 ,
T_2 V_75 , T_8 * V_172 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
unsigned char V_105 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ( V_160 -> V_166 & V_167 ) == V_168 )
return - V_173 ;
if ( V_15 -> V_143 . V_140 != V_144 )
return - V_173 ;
if ( F_53 ( V_105 , V_3 ) )
return - V_95 ;
if ( V_105 == 0x47 && V_75 % V_94 == 0 )
return F_30 ( V_15 , V_3 , V_75 , V_160 -> V_166 & V_159 , 1 ) ;
else
return F_33 ( V_15 , V_3 , V_75 , V_160 -> V_166 & V_159 , 1 ) ;
}
static unsigned int F_54 ( struct V_160 * V_160 , T_7 * V_161 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
unsigned int V_165 = 0 ;
F_4 ( 2 , L_2 , V_15 ) ;
F_51 ( V_160 , & V_15 -> V_85 . V_46 , V_161 ) ;
if ( V_15 -> V_21 ) {
if ( F_25 ( & V_15 -> V_85 ) >= 20 * 1024 )
V_165 |= ( V_170 | V_171 ) ;
} else
V_165 = ( V_170 | V_171 ) ;
return V_165 ;
}
static T_5 F_55 ( struct V_160 * V_160 , const char T_6 * V_3 ,
T_2 V_75 , T_8 * V_172 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
unsigned char V_105 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( V_15 -> V_139 . V_140 != V_141 ) {
F_15 ( V_174 L_7 ) ;
return - V_173 ;
}
if ( F_53 ( V_105 , V_3 ) )
return - V_95 ;
if ( V_105 == 0x47 && V_75 % V_94 == 0 )
return F_30 ( V_15 , V_3 , V_75 , V_160 -> V_166 & V_159 , 0 ) ;
else
return F_36 ( V_15 , V_3 , V_75 , V_160 -> V_166 & V_159 , 0 ) ;
}
static int F_56 ( struct V_15 * V_15 , char T_6 * V_3 , unsigned int V_4 , int V_86 )
{
unsigned V_76 , V_96 ;
int V_175 = 0 ;
int V_176 = 0 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( V_4 == 0 )
return 0 ;
if ( ! ( V_15 -> V_21 & V_32 ) ) {
if ( F_7 ( V_15 , V_32 ) < 0 )
return - V_23 ;
}
for ( V_76 = 0 ; V_76 < V_4 ; V_76 ++ ) {
unsigned char V_105 ;
if ( F_53 ( V_105 , V_3 + V_76 ) )
return - V_95 ;
if ( V_176 == 5 ) {
V_175 = V_105 & 0x08 ;
V_176 = 0 ;
}
if ( V_105 == 0x00 ) {
V_176 = ( V_176 == 1 || V_176 == 2 ) ? 2 : 1 ;
continue;
}
switch ( V_176 ++ ) {
case 2 : if ( V_105 == 0x01 )
continue;
break;
case 3 : if ( V_105 == 0xb5 )
continue;
break;
case 4 : if ( ( V_105 & 0xf0 ) == 0x10 )
continue;
break;
}
V_176 = 0 ;
}
V_96 = V_177 / V_4 + 1 ;
F_35 ( V_15 , V_178 , sizeof( V_178 ) , 0 , 1 ) ;
for ( V_76 = 0 ; V_76 < V_96 ; V_76 ++ )
F_33 ( V_15 , V_3 , V_4 , 0 , 1 ) ;
F_43 ( & V_15 -> V_37 [ 1 ] ) ;
if ( V_175 )
return F_57 ( V_15 , V_179 , 1 ) ;
else
return 0 ;
}
static int F_58 ( struct V_160 * V_160 ,
unsigned int V_180 , void * V_181 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
unsigned long V_182 = ( unsigned long ) V_181 ;
int V_17 = 0 ;
F_4 ( 1 , L_8 , V_15 , V_180 ) ;
if ( ( V_160 -> V_166 & V_167 ) == V_168 ) {
if ( V_180 != V_183 && V_180 != V_184 &&
V_180 != V_185 ) {
return - V_173 ;
}
}
if ( F_59 ( & V_15 -> V_186 ) )
return - V_187 ;
switch ( V_180 ) {
case V_188 :
V_15 -> V_143 . V_189 = V_190 ;
if ( V_15 -> V_143 . V_140 == V_144 )
V_17 = F_9 ( V_15 , V_32 ) ;
else
V_17 = F_57 ( V_15 , V_191 ,
V_15 -> V_143 . V_192 ? 0 : 1 ) ;
if ( ! V_17 )
V_15 -> V_193 = V_194 ;
break;
case V_195 :
V_15 -> V_193 = V_194 ;
if ( V_15 -> V_143 . V_189 == V_196 ) {
V_15 -> V_143 . V_189 = V_197 ;
V_17 = F_57 ( V_15 , V_198 , 0 ) ;
if ( V_17 )
break;
}
if ( V_15 -> V_143 . V_140 == V_144 ) {
if ( V_15 -> V_21 == V_34 ) {
V_17 = F_5 ( V_15 , V_24 , V_25 , 0 ) ;
if ( V_17 )
break;
V_15 -> V_21 &= ~ V_32 ;
}
V_17 = F_7 ( V_15 , V_32 ) ;
}
if ( ! V_17 )
V_17 = F_57 ( V_15 , V_198 , 0 ) ;
if ( ! V_17 )
V_15 -> V_143 . V_189 = V_197 ;
break;
case V_199 :
V_15 -> V_143 . V_189 = V_196 ;
if ( V_15 -> V_21 & V_32 )
V_17 = F_5 ( V_15 , V_24 , V_200 , 0 ) ;
else
V_17 = F_57 ( V_15 , V_179 , 1 ) ;
if ( ! V_17 )
V_15 -> V_193 = V_201 ;
break;
case V_202 :
if ( V_15 -> V_21 & V_32 )
V_17 = F_5 ( V_15 , V_24 , V_203 , 0 ) ;
if ( ! V_17 )
V_17 = F_57 ( V_15 , V_198 , 0 ) ;
if ( ! V_17 ) {
V_15 -> V_143 . V_189 = V_197 ;
V_15 -> V_193 = V_194 ;
}
break;
case V_204 :
V_15 -> V_143 . V_140 = ( V_205 ) V_182 ;
break;
case V_206 :
V_15 -> V_143 . V_192 = ( int ) V_182 ;
break;
case V_183 :
memcpy ( V_181 , & V_15 -> V_143 , sizeof( struct V_207 ) ) ;
break;
case V_184 :
V_17 = F_49 ( V_15 , V_181 , V_160 -> V_166 ) ;
break;
case V_185 :
memcpy ( V_181 , & V_15 -> V_208 , sizeof( V_209 ) ) ;
break;
case V_210 :
{
T_9 V_211 = ( T_9 ) V_182 ;
switch ( V_211 ) {
case V_212 :
V_15 -> V_213 = V_214 ;
break;
case V_215 :
V_15 -> V_213 = V_216 ;
break;
case V_217 :
V_15 -> V_213 = V_218 ;
break;
default:
V_17 = - V_142 ;
}
if ( V_17 < 0 )
break;
V_15 -> V_143 . V_219 = V_211 ;
V_17 = F_5 ( V_15 , V_66 , V_220 ,
1 , V_15 -> V_213 ) ;
break;
}
case V_221 :
if ( V_182 > 1 ) {
V_17 = - V_142 ;
break;
}
V_15 -> V_222 = V_182 ;
V_17 = F_5 ( V_15 , V_66 , V_223 ,
1 , ( T_4 ) V_182 ) ;
break;
case V_224 :
{
struct V_225 * V_226 =
(struct V_225 * ) V_181 ;
V_15 -> V_143 . V_140 = V_144 ;
F_60 ( & V_15 -> V_84 ) ;
V_17 = F_56 ( V_15 , V_226 -> V_227 , V_226 -> V_228 ,
V_160 -> V_166 & V_159 ) ;
break;
}
case V_229 :
if ( V_15 -> V_21 & V_32 )
V_17 = F_5 ( V_15 , V_24 ,
V_230 , 2 , V_35 , 0 ) ;
else
V_17 = F_57 ( V_15 , V_231 , V_182 ) ;
if ( ! V_17 ) {
V_15 -> V_193 = V_232 ;
V_15 -> V_143 . V_189 = V_197 ;
}
break;
case V_233 :
if ( V_15 -> V_21 & V_32 ) {
if ( V_15 -> V_193 != V_234 )
V_17 = F_5 ( V_15 , V_24 , V_235 , 2 , 0 , 0 ) ;
if ( ! V_17 )
V_17 = F_57 ( V_15 , V_236 , V_182 ) ;
} else {
V_17 = F_57 ( V_15 , V_198 , 0 ) ;
if ( ! V_17 )
V_17 = F_57 ( V_15 , V_191 , 0 ) ;
if ( ! V_17 )
V_17 = F_57 ( V_15 , V_236 , V_182 ) ;
}
if ( ! V_17 ) {
V_15 -> V_193 = V_234 ;
V_15 -> V_143 . V_189 = V_197 ;
}
break;
case V_237 :
* ( int * ) V_181 = V_238 | V_239 |
V_240 | V_241 ;
break;
case V_242 :
F_60 ( & V_15 -> V_84 ) ;
F_8 ( & V_15 -> V_37 [ 1 ] ) ;
if ( V_15 -> V_21 == V_34 ) {
V_17 = F_5 ( V_15 , V_24 ,
V_38 , 2 , V_35 , 0 ) ;
if ( V_17 )
break;
if ( V_15 -> V_193 == V_232 )
V_17 = F_5 ( V_15 , V_24 ,
V_230 , 2 , V_35 , 0 ) ;
if ( V_15 -> V_193 == V_234 ) {
V_17 = F_5 ( V_15 , V_24 ,
V_235 , 2 , 0 , 0 ) ;
if ( ! V_17 )
V_17 = F_57 ( V_15 , V_236 , V_182 ) ;
}
if ( V_15 -> V_193 == V_201 )
V_17 = F_57 ( V_15 , V_191 , 1 ) ;
}
break;
case V_243 :
break;
default:
V_17 = - V_244 ;
break;
}
F_61 ( & V_15 -> V_186 ) ;
return V_17 ;
}
static int F_62 ( struct V_160 * V_160 ,
unsigned int V_180 , void * V_181 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
unsigned long V_182 = ( unsigned long ) V_181 ;
int V_17 = 0 ;
F_4 ( 1 , L_8 , V_15 , V_180 ) ;
if ( ( ( V_160 -> V_166 & V_167 ) == V_168 ) &&
( V_180 != V_245 ) )
return - V_173 ;
if ( F_59 ( & V_15 -> V_186 ) )
return - V_187 ;
switch ( V_180 ) {
case V_246 :
if ( V_15 -> V_139 . V_140 == V_141 )
V_17 = F_9 ( V_15 , V_27 ) ;
else
V_17 = F_63 ( V_15 , V_247 ) ;
if ( ! V_17 )
V_15 -> V_139 . V_189 = V_248 ;
break;
case V_249 :
if ( V_15 -> V_139 . V_140 == V_141 )
V_17 = F_7 ( V_15 , V_27 ) ;
if ( ! V_17 )
V_17 = F_63 ( V_15 , V_250 ) ;
if ( ! V_17 )
V_15 -> V_139 . V_189 = V_251 ;
break;
case V_252 :
V_17 = F_63 ( V_15 , V_247 ) ;
if ( ! V_17 )
V_15 -> V_139 . V_189 = V_253 ;
break;
case V_254 :
if ( V_15 -> V_139 . V_189 == V_253 ) {
V_15 -> V_139 . V_189 = V_251 ;
V_17 = F_63 ( V_15 , V_250 | V_255 ) ;
}
break;
case V_256 :
V_15 -> V_139 . V_140 = ( V_257 ) V_182 ;
break;
case V_258 :
{
V_17 = F_63 ( V_15 , V_182 ? V_247 : V_250 ) ;
if ( ! V_17 )
V_15 -> V_139 . V_259 = ( int ) V_182 ;
break;
}
case V_260 :
V_15 -> V_139 . V_261 = ( int ) V_182 ;
V_17 = F_63 ( V_15 , V_182 ? V_262 : V_263 ) ;
break;
case V_264 :
if ( F_64 ( V_15 -> V_265 ) < 0x2621 )
V_17 = - V_142 ;
V_15 -> V_139 . V_266 = ( int ) V_182 ;
break;
case V_267 :
V_15 -> V_139 . V_268 = ( V_269 ) V_182 ;
switch( V_15 -> V_139 . V_268 ) {
case V_270 :
V_17 = F_63 ( V_15 , V_271 ) ;
if ( ! V_17 ) {
if ( V_15 -> V_58 == V_60 )
F_20 ( V_15 , 0x20 , 0x02 , 0x49 ) ;
else if ( V_15 -> V_58 == V_63 )
F_21 ( V_15 , V_62 , 0x0008 , 0x0220 ) ;
}
break;
case V_272 :
V_17 = F_63 ( V_15 , V_273 ) ;
if ( ! V_17 ) {
if ( V_15 -> V_58 == V_60 )
F_20 ( V_15 , 0x20 , 0x02 , 0x4a ) ;
else if ( V_15 -> V_58 == V_63 )
F_21 ( V_15 , V_62 , 0x0008 , 0x0200 ) ;
}
break;
case V_274 :
V_17 = F_63 ( V_15 , V_275 ) ;
if ( ! V_17 ) {
if ( V_15 -> V_58 == V_60 )
F_20 ( V_15 , 0x20 , 0x02 , 0x45 ) ;
else if ( V_15 -> V_58 == V_63 )
F_21 ( V_15 , V_62 , 0x0008 , 0x0210 ) ;
}
break;
default:
V_17 = - V_142 ;
break;
}
break;
case V_245 :
memcpy ( V_181 , & V_15 -> V_139 , sizeof( struct V_276 ) ) ;
break;
case V_277 :
if ( F_64 ( V_15 -> V_265 ) < 0x2621 )
* ( unsigned int * ) V_181 = V_278 | V_279 | V_280 ;
else
* ( unsigned int * ) V_181 = V_278 | V_281 | V_282 |
V_279 | V_280 ;
break;
case V_283 :
F_60 ( & V_15 -> V_85 ) ;
F_8 ( & V_15 -> V_37 [ 0 ] ) ;
if ( V_15 -> V_21 == V_34 )
V_17 = F_5 ( V_15 , V_24 ,
V_38 , 2 , V_35 , 0 ) ;
break;
case V_284 :
break;
case V_285 :
{
struct V_286 * V_287 = (struct V_286 * ) V_181 ;
V_17 = F_18 ( V_15 , V_287 -> V_56 , V_287 -> V_57 ) ;
break;
}
case V_288 :
break;
default:
V_17 = - V_244 ;
}
F_61 ( & V_15 -> V_186 ) ;
return V_17 ;
}
static int F_65 ( struct V_289 * V_289 , struct V_160 * V_160 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
int V_54 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ( V_54 = F_66 ( V_289 , V_160 ) ) < 0 )
return V_54 ;
if ( ( V_160 -> V_166 & V_167 ) != V_168 ) {
F_60 ( & V_15 -> V_85 ) ;
F_60 ( & V_15 -> V_84 ) ;
V_15 -> V_192 = 1 ;
V_15 -> V_139 . V_261 = 1 ;
V_15 -> V_143 . V_140 = V_290 ;
V_15 -> V_149 . V_154 = V_15 -> V_149 . V_152 = 0 ;
}
return 0 ;
}
static int F_67 ( struct V_289 * V_289 , struct V_160 * V_160 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( ( V_160 -> V_166 & V_167 ) != V_168 ) {
F_9 ( V_15 , V_32 ) ;
}
return F_68 ( V_289 , V_160 ) ;
}
static int F_69 ( struct V_289 * V_289 , struct V_160 * V_160 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
int V_54 = F_66 ( V_289 , V_160 ) ;
F_4 ( 2 , L_2 , V_15 ) ;
if ( V_54 < 0 )
return V_54 ;
F_60 ( & V_15 -> V_85 ) ;
V_15 -> V_139 . V_140 = V_291 ;
return 0 ;
}
static int F_70 ( struct V_289 * V_289 , struct V_160 * V_160 )
{
struct V_162 * V_163 = V_160 -> V_164 ;
struct V_15 * V_15 = V_163 -> V_7 ;
F_4 ( 2 , L_2 , V_15 ) ;
F_9 ( V_15 , V_27 ) ;
return F_68 ( V_289 , V_160 ) ;
}
int F_71 ( struct V_15 * V_15 )
{
V_15 -> V_139 . V_261 = 0 ;
V_15 -> V_139 . V_259 = 0 ;
V_15 -> V_139 . V_189 = V_248 ;
V_15 -> V_139 . V_140 = V_291 ;
V_15 -> V_139 . V_268 = V_270 ;
V_15 -> V_139 . V_266 = 0 ;
V_15 -> V_143 . V_192 = 0 ;
V_15 -> V_143 . V_189 = V_190 ;
V_15 -> V_143 . V_140 = V_290 ;
V_15 -> V_143 . V_292 = V_293 ;
V_15 -> V_143 . V_219 = V_215 ;
V_15 -> V_222 = V_293 ;
V_15 -> V_213 = V_216 ;
F_72 ( & V_15 -> V_149 . V_156 ) ;
F_73 ( & V_15 -> V_149 . V_151 ) ;
V_15 -> V_149 . V_152 = V_15 -> V_149 . V_154 = 0 ;
V_15 -> V_149 . V_155 = 0 ;
memset ( & V_15 -> V_208 , 0 , sizeof ( V_209 ) ) ;
F_74 ( & V_15 -> V_294 , & V_15 -> V_295 ,
& V_296 , V_15 , V_297 , 0 ) ;
F_74 ( & V_15 -> V_294 , & V_15 -> V_298 ,
& V_299 , V_15 , V_300 , 0 ) ;
return 0 ;
}
void F_75 ( struct V_15 * V_15 )
{
F_76 ( V_15 -> V_298 ) ;
F_76 ( V_15 -> V_295 ) ;
}
int F_77 ( struct V_15 * V_15 )
{
void (* F_78 [])( T_1 * , int , void * ) = { F_29 , play_video_cb }
