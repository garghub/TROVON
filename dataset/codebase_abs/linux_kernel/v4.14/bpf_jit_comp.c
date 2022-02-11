static T_1 * F_1 ( T_1 * V_1 , T_2 V_2 , unsigned int V_3 )
{
if ( V_3 == 1 )
* V_1 = V_2 ;
else if ( V_3 == 2 )
* ( V_4 * ) V_1 = V_2 ;
else {
* ( T_2 * ) V_1 = V_2 ;
F_2 () ;
}
return V_1 + V_3 ;
}
static bool F_3 ( int V_5 )
{
return V_5 <= 127 && V_5 >= - 128 ;
}
static bool F_4 ( T_3 V_5 )
{
return V_5 == ( T_3 ) ( V_6 ) V_5 ;
}
static int F_5 ( int V_7 )
{
if ( V_7 == V_8 )
return 4 ;
else if ( V_7 == V_9 )
return 2 ;
else if ( V_7 == V_10 )
return 1 ;
else if ( V_7 == V_11 )
return 4 ;
else
return 0 ;
}
static void F_6 ( void * V_12 , void * V_13 )
{
T_4 V_14 = F_7 () ;
F_8 ( V_15 ) ;
F_9 () ;
F_10 ( ( unsigned long ) V_12 , ( unsigned long ) V_13 ) ;
F_8 ( V_14 ) ;
}
static bool F_11 ( T_2 V_16 )
{
return ( 1 << V_16 ) & ( F_12 ( V_17 ) |
F_12 ( V_18 ) |
F_12 ( V_19 ) |
F_12 ( V_20 ) |
F_12 ( V_21 ) |
F_12 ( V_22 ) ) ;
}
static T_1 F_13 ( T_1 V_23 , T_2 V_16 )
{
if ( F_11 ( V_16 ) )
V_23 |= 1 ;
return V_23 ;
}
static T_1 F_14 ( T_1 V_23 , T_2 V_24 , T_2 V_25 )
{
if ( F_11 ( V_24 ) )
V_23 |= 1 ;
if ( F_11 ( V_25 ) )
V_23 |= 4 ;
return V_23 ;
}
static T_1 F_15 ( T_1 V_23 , T_2 V_26 )
{
return V_23 + V_27 [ V_26 ] ;
}
static T_1 F_16 ( T_1 V_23 , T_2 V_26 , T_2 V_28 )
{
return V_23 + V_27 [ V_26 ] + ( V_27 [ V_28 ] << 3 ) ;
}
static void F_17 ( void * V_29 , unsigned int V_30 )
{
memset ( V_29 , 0xcc , V_30 ) ;
}
static void F_18 ( T_1 * * V_31 , T_2 V_32 )
{
T_1 * V_33 = * V_31 ;
int V_34 = 0 ;
F_19 ( 0x55 ) ;
F_20 ( 0x48 , 0x89 , 0xE5 ) ;
F_21 ( 0x48 , 0x81 , 0xEC ,
F_22 ( V_32 , 8 ) + V_35 ) ;
F_23 ( 0x48 , 0x83 , 0xED , V_35 ) ;
F_23 ( 0x48 , 0x89 , 0x5D , 0 ) ;
F_23 ( 0x4C , 0x89 , 0x6D , 8 ) ;
F_23 ( 0x4C , 0x89 , 0x75 , 16 ) ;
F_23 ( 0x4C , 0x89 , 0x7D , 24 ) ;
F_24 ( 0x31 , 0xc0 ) ;
F_23 ( 0x48 , 0x89 , 0x45 , 32 ) ;
F_25 ( V_34 != V_36 ) ;
* V_31 = V_33 ;
}
static void F_26 ( T_1 * * V_31 )
{
T_1 * V_33 = * V_31 ;
int V_37 , V_38 , V_39 ;
int V_34 = 0 ;
F_24 ( 0x89 , 0xD2 ) ;
F_20 ( 0x39 , 0x56 ,
F_27 ( struct V_40 , V_41 . V_42 ) ) ;
#define F_28 43
F_24 ( V_43 , F_28 ) ;
V_37 = V_34 ;
F_29 ( 0x8B , 0x85 , 36 ) ;
F_20 ( 0x83 , 0xF8 , V_44 ) ;
#define F_30 32
F_24 ( V_45 , F_30 ) ;
V_38 = V_34 ;
F_20 ( 0x83 , 0xC0 , 0x01 ) ;
F_29 ( 0x89 , 0x85 , 36 ) ;
F_31 ( 0x48 , 0x8B , 0x84 , 0xD6 ,
F_27 ( struct V_40 , V_46 ) ) ;
F_20 ( 0x48 , 0x85 , 0xC0 ) ;
#define F_32 10
F_24 ( V_47 , F_32 ) ;
V_39 = V_34 ;
F_23 ( 0x48 , 0x8B , 0x40 ,
F_27 ( struct V_48 , V_49 ) ) ;
F_23 ( 0x48 , 0x83 , 0xC0 , V_36 ) ;
F_24 ( 0xFF , 0xE0 ) ;
F_25 ( V_34 - V_37 != F_28 ) ;
F_25 ( V_34 - V_38 != F_30 ) ;
F_25 ( V_34 - V_39 != F_32 ) ;
* V_31 = V_33 ;
}
static void F_33 ( T_1 * * V_31 )
{
T_1 * V_33 = * V_31 ;
int V_34 = 0 ;
F_21 ( 0x44 , 0x8b , 0x8f , F_27 ( struct V_50 , V_3 ) ) ;
F_21 ( 0x44 , 0x2b , 0x8f , F_27 ( struct V_50 , V_51 ) ) ;
F_21 ( 0x4c , 0x8b , 0x97 , F_27 ( struct V_50 , V_52 ) ) ;
* V_31 = V_33 ;
}
static int F_34 ( struct V_48 * V_48 , int * V_53 , T_1 * V_54 ,
int V_55 , struct V_56 * V_57 )
{
struct V_58 * V_59 = V_48 -> V_60 ;
int V_61 = V_48 -> V_3 ;
bool V_62 = V_57 -> V_62 | ( V_55 == 0 ) ;
bool V_63 = V_57 -> V_63 | ( V_55 == 0 ) ;
bool V_64 = false ;
T_1 V_65 [ V_66 + V_67 ] ;
int V_68 , V_34 = 0 ;
int V_69 = 0 ;
T_1 * V_33 = V_65 ;
F_18 ( & V_33 , V_48 -> V_70 -> V_32 ) ;
if ( V_62 )
F_33 ( & V_33 ) ;
for ( V_68 = 0 ; V_68 < V_61 ; V_68 ++ , V_59 ++ ) {
const V_6 V_71 = V_59 -> V_72 ;
T_2 V_26 = V_59 -> V_26 ;
T_2 V_28 = V_59 -> V_28 ;
T_1 V_73 = 0 , V_74 = 0 , V_75 = 0 ;
T_3 V_76 ;
T_1 V_77 ;
bool V_78 ;
int V_79 ;
T_1 * V_80 ;
if ( V_26 == V_22 || V_28 == V_22 )
V_57 -> V_63 = V_63 = true ;
switch ( V_59 -> V_81 ) {
case V_82 | V_83 | V_84 :
case V_82 | V_85 | V_84 :
case V_82 | V_86 | V_84 :
case V_82 | V_87 | V_84 :
case V_82 | V_88 | V_84 :
case V_89 | V_83 | V_84 :
case V_89 | V_85 | V_84 :
case V_89 | V_86 | V_84 :
case V_89 | V_87 | V_84 :
case V_89 | V_88 | V_84 :
switch ( F_35 ( V_59 -> V_81 ) ) {
case V_83 : V_74 = 0x01 ; break;
case V_85 : V_74 = 0x29 ; break;
case V_86 : V_74 = 0x21 ; break;
case V_87 : V_74 = 0x09 ; break;
case V_88 : V_74 = 0x31 ; break;
}
if ( F_36 ( V_59 -> V_81 ) == V_89 )
F_19 ( F_14 ( 0x48 , V_26 , V_28 ) ) ;
else if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_19 ( F_14 ( 0x40 , V_26 , V_28 ) ) ;
F_24 ( V_74 , F_16 ( 0xC0 , V_26 , V_28 ) ) ;
break;
case V_89 | V_90 | V_84 :
F_37 ( V_26 , V_28 ) ;
break;
case V_82 | V_90 | V_84 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_19 ( F_14 ( 0x40 , V_26 , V_28 ) ) ;
F_24 ( 0x89 , F_16 ( 0xC0 , V_26 , V_28 ) ) ;
break;
case V_82 | V_91 :
case V_89 | V_91 :
if ( F_36 ( V_59 -> V_81 ) == V_89 )
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
else if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
F_24 ( 0xF7 , F_15 ( 0xD8 , V_26 ) ) ;
break;
case V_82 | V_83 | V_92 :
case V_82 | V_85 | V_92 :
case V_82 | V_86 | V_92 :
case V_82 | V_87 | V_92 :
case V_82 | V_88 | V_92 :
case V_89 | V_83 | V_92 :
case V_89 | V_85 | V_92 :
case V_89 | V_86 | V_92 :
case V_89 | V_87 | V_92 :
case V_89 | V_88 | V_92 :
if ( F_36 ( V_59 -> V_81 ) == V_89 )
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
else if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
switch ( F_35 ( V_59 -> V_81 ) ) {
case V_83 : V_75 = 0xC0 ; break;
case V_85 : V_75 = 0xE8 ; break;
case V_86 : V_75 = 0xE0 ; break;
case V_87 : V_75 = 0xC8 ; break;
case V_88 : V_75 = 0xF0 ; break;
}
if ( F_3 ( V_71 ) )
F_20 ( 0x83 , F_15 ( V_75 , V_26 ) , V_71 ) ;
else
F_29 ( 0x81 , F_15 ( V_75 , V_26 ) , V_71 ) ;
break;
case V_89 | V_90 | V_92 :
if ( V_71 < 0 ) {
V_73 = F_13 ( 0x48 , V_26 ) ;
V_74 = 0xC7 ;
V_75 = 0xC0 ;
F_21 ( V_73 , V_74 , F_15 ( V_75 , V_26 ) , V_71 ) ;
break;
}
case V_82 | V_90 | V_92 :
if ( V_71 == 0 ) {
if ( F_11 ( V_26 ) )
F_19 ( F_14 ( 0x40 , V_26 , V_26 ) ) ;
V_74 = 0x31 ;
V_75 = 0xC0 ;
F_24 ( V_74 , F_16 ( V_75 , V_26 , V_26 ) ) ;
break;
}
if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
F_38 ( F_15 ( 0xB8 , V_26 ) , V_71 ) ;
break;
case V_93 | V_94 | V_11 :
if ( V_59 [ 0 ] . V_72 == 0 && V_59 [ 1 ] . V_72 == 0 ) {
V_73 = F_14 ( 0x48 , V_26 , V_26 ) ;
V_74 = 0x31 ;
V_75 = 0xC0 ;
F_20 ( V_73 , V_74 , F_16 ( V_75 , V_26 , V_26 ) ) ;
V_59 ++ ;
V_68 ++ ;
break;
}
F_24 ( F_13 ( 0x48 , V_26 ) , F_15 ( 0xB8 , V_26 ) ) ;
F_39 ( V_59 [ 0 ] . V_72 , 4 ) ;
F_39 ( V_59 [ 1 ] . V_72 , 4 ) ;
V_59 ++ ;
V_68 ++ ;
break;
case V_82 | V_95 | V_84 :
case V_82 | V_96 | V_84 :
case V_82 | V_95 | V_92 :
case V_82 | V_96 | V_92 :
case V_89 | V_95 | V_84 :
case V_89 | V_96 | V_84 :
case V_89 | V_95 | V_92 :
case V_89 | V_96 | V_92 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
if ( F_40 ( V_59 -> V_81 ) == V_84 )
F_37 ( V_18 , V_28 ) ;
else
F_21 ( 0x49 , 0xC7 , 0xC3 , V_71 ) ;
F_37 ( V_97 , V_26 ) ;
F_24 ( 0x31 , 0xd2 ) ;
if ( F_40 ( V_59 -> V_81 ) == V_84 ) {
F_23 ( 0x49 , 0x83 , 0xFB , 0x00 ) ;
F_24 ( V_98 , 1 + 1 + 2 + 5 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_24 ( 0x31 , 0xc0 ) ;
V_76 = V_57 -> V_99 - ( V_53 [ V_68 ] - 11 ) ;
F_38 ( 0xE9 , V_76 ) ;
}
if ( F_36 ( V_59 -> V_81 ) == V_89 )
F_20 ( 0x49 , 0xF7 , 0xF3 ) ;
else
F_20 ( 0x41 , 0xF7 , 0xF3 ) ;
if ( F_35 ( V_59 -> V_81 ) == V_95 )
F_20 ( 0x49 , 0x89 , 0xD3 ) ;
else
F_20 ( 0x49 , 0x89 , 0xC3 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_37 ( V_26 , V_18 ) ;
break;
case V_82 | V_100 | V_92 :
case V_82 | V_100 | V_84 :
case V_89 | V_100 | V_92 :
case V_89 | V_100 | V_84 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
F_37 ( V_18 , V_26 ) ;
if ( F_40 ( V_59 -> V_81 ) == V_84 )
F_37 ( V_97 , V_28 ) ;
else
F_21 ( 0x48 , 0xC7 , 0xC0 , V_71 ) ;
if ( F_36 ( V_59 -> V_81 ) == V_89 )
F_19 ( F_13 ( 0x48 , V_18 ) ) ;
else if ( F_11 ( V_18 ) )
F_19 ( F_13 ( 0x40 , V_18 ) ) ;
F_24 ( 0xF7 , F_15 ( 0xE0 , V_18 ) ) ;
F_37 ( V_18 , V_97 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_37 ( V_26 , V_18 ) ;
break;
case V_82 | V_101 | V_92 :
case V_82 | V_102 | V_92 :
case V_82 | V_103 | V_92 :
case V_89 | V_101 | V_92 :
case V_89 | V_102 | V_92 :
case V_89 | V_103 | V_92 :
if ( F_36 ( V_59 -> V_81 ) == V_89 )
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
else if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
switch ( F_35 ( V_59 -> V_81 ) ) {
case V_101 : V_75 = 0xE0 ; break;
case V_102 : V_75 = 0xE8 ; break;
case V_103 : V_75 = 0xF8 ; break;
}
F_20 ( 0xC1 , F_15 ( V_75 , V_26 ) , V_71 ) ;
break;
case V_82 | V_101 | V_84 :
case V_82 | V_102 | V_84 :
case V_82 | V_103 | V_84 :
case V_89 | V_101 | V_84 :
case V_89 | V_102 | V_84 :
case V_89 | V_103 | V_84 :
if ( V_26 == V_104 ) {
F_37 ( V_18 , V_26 ) ;
V_26 = V_18 ;
}
if ( V_28 != V_104 ) {
F_19 ( 0x51 ) ;
F_37 ( V_104 , V_28 ) ;
}
if ( F_36 ( V_59 -> V_81 ) == V_89 )
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
else if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
switch ( F_35 ( V_59 -> V_81 ) ) {
case V_101 : V_75 = 0xE0 ; break;
case V_102 : V_75 = 0xE8 ; break;
case V_103 : V_75 = 0xF8 ; break;
}
F_24 ( 0xD3 , F_15 ( V_75 , V_26 ) ) ;
if ( V_28 != V_104 )
F_19 ( 0x59 ) ;
if ( V_59 -> V_26 == V_104 )
F_37 ( V_59 -> V_26 , V_18 ) ;
break;
case V_82 | V_105 | V_106 :
switch ( V_71 ) {
case 16 :
F_19 ( 0x66 ) ;
if ( F_11 ( V_26 ) )
F_19 ( 0x41 ) ;
F_20 ( 0xC1 , F_15 ( 0xC8 , V_26 ) , 8 ) ;
if ( F_11 ( V_26 ) )
F_20 ( 0x45 , 0x0F , 0xB7 ) ;
else
F_24 ( 0x0F , 0xB7 ) ;
F_19 ( F_16 ( 0xC0 , V_26 , V_26 ) ) ;
break;
case 32 :
if ( F_11 ( V_26 ) )
F_24 ( 0x41 , 0x0F ) ;
else
F_19 ( 0x0F ) ;
F_19 ( F_15 ( 0xC8 , V_26 ) ) ;
break;
case 64 :
F_20 ( F_13 ( 0x48 , V_26 ) , 0x0F ,
F_15 ( 0xC8 , V_26 ) ) ;
break;
}
break;
case V_82 | V_105 | V_107 :
switch ( V_71 ) {
case 16 :
if ( F_11 ( V_26 ) )
F_20 ( 0x45 , 0x0F , 0xB7 ) ;
else
F_24 ( 0x0F , 0xB7 ) ;
F_19 ( F_16 ( 0xC0 , V_26 , V_26 ) ) ;
break;
case 32 :
if ( F_11 ( V_26 ) )
F_19 ( 0x45 ) ;
F_24 ( 0x89 , F_16 ( 0xC0 , V_26 , V_26 ) ) ;
break;
case 64 :
break;
}
break;
case V_108 | V_109 | V_10 :
if ( F_11 ( V_26 ) )
F_24 ( 0x41 , 0xC6 ) ;
else
F_19 ( 0xC6 ) ;
goto V_110;
case V_108 | V_109 | V_9 :
if ( F_11 ( V_26 ) )
F_20 ( 0x66 , 0x41 , 0xC7 ) ;
else
F_24 ( 0x66 , 0xC7 ) ;
goto V_110;
case V_108 | V_109 | V_8 :
if ( F_11 ( V_26 ) )
F_24 ( 0x41 , 0xC7 ) ;
else
F_19 ( 0xC7 ) ;
goto V_110;
case V_108 | V_109 | V_11 :
F_24 ( F_13 ( 0x48 , V_26 ) , 0xC7 ) ;
V_110: if ( F_3 ( V_59 -> V_111 ) )
F_24 ( F_15 ( 0x40 , V_26 ) , V_59 -> V_111 ) ;
else
F_38 ( F_15 ( 0x80 , V_26 ) , V_59 -> V_111 ) ;
F_39 ( V_71 , F_5 ( F_41 ( V_59 -> V_81 ) ) ) ;
break;
case V_112 | V_109 | V_10 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) ||
V_28 == V_113 || V_28 == V_114 )
F_24 ( F_14 ( 0x40 , V_26 , V_28 ) , 0x88 ) ;
else
F_19 ( 0x88 ) ;
goto V_115;
case V_112 | V_109 | V_9 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_20 ( 0x66 , F_14 ( 0x40 , V_26 , V_28 ) , 0x89 ) ;
else
F_24 ( 0x66 , 0x89 ) ;
goto V_115;
case V_112 | V_109 | V_8 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_24 ( F_14 ( 0x40 , V_26 , V_28 ) , 0x89 ) ;
else
F_19 ( 0x89 ) ;
goto V_115;
case V_112 | V_109 | V_11 :
F_24 ( F_14 ( 0x48 , V_26 , V_28 ) , 0x89 ) ;
V_115: if ( F_3 ( V_59 -> V_111 ) )
F_24 ( F_16 ( 0x40 , V_26 , V_28 ) , V_59 -> V_111 ) ;
else
F_38 ( F_16 ( 0x80 , V_26 , V_28 ) ,
V_59 -> V_111 ) ;
break;
case V_116 | V_109 | V_10 :
F_20 ( F_14 ( 0x48 , V_28 , V_26 ) , 0x0F , 0xB6 ) ;
goto V_117;
case V_116 | V_109 | V_9 :
F_20 ( F_14 ( 0x48 , V_28 , V_26 ) , 0x0F , 0xB7 ) ;
goto V_117;
case V_116 | V_109 | V_8 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_24 ( F_14 ( 0x40 , V_28 , V_26 ) , 0x8B ) ;
else
F_19 ( 0x8B ) ;
goto V_117;
case V_116 | V_109 | V_11 :
F_24 ( F_14 ( 0x48 , V_28 , V_26 ) , 0x8B ) ;
V_117:
if ( F_3 ( V_59 -> V_111 ) )
F_24 ( F_16 ( 0x40 , V_28 , V_26 ) , V_59 -> V_111 ) ;
else
F_38 ( F_16 ( 0x80 , V_28 , V_26 ) ,
V_59 -> V_111 ) ;
break;
case V_112 | V_118 | V_8 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_20 ( 0xF0 , F_14 ( 0x40 , V_26 , V_28 ) , 0x01 ) ;
else
F_24 ( 0xF0 , 0x01 ) ;
goto V_119;
case V_112 | V_118 | V_11 :
F_20 ( 0xF0 , F_14 ( 0x48 , V_26 , V_28 ) , 0x01 ) ;
V_119: if ( F_3 ( V_59 -> V_111 ) )
F_24 ( F_16 ( 0x40 , V_26 , V_28 ) , V_59 -> V_111 ) ;
else
F_38 ( F_16 ( 0x80 , V_26 , V_28 ) ,
V_59 -> V_111 ) ;
break;
case V_120 | V_121 :
V_80 = ( T_1 * ) V_122 + V_71 ;
V_76 = V_80 - ( V_54 + V_53 [ V_68 ] ) ;
if ( V_62 ) {
V_78 = F_42 ( V_80 ) ;
if ( V_78 ) {
F_19 ( 0x57 ) ;
V_76 += 22 ;
} else {
F_24 ( 0x41 , 0x52 ) ;
F_24 ( 0x41 , 0x51 ) ;
V_76 += 4 ;
}
}
if ( ! V_71 || ! F_4 ( V_76 ) ) {
F_43 ( L_1 ,
V_71 , V_80 , V_54 ) ;
return - V_123 ;
}
F_38 ( 0xE8 , V_76 ) ;
if ( V_62 ) {
if ( V_78 ) {
F_19 ( 0x5F ) ;
F_33 ( & V_33 ) ;
} else {
F_24 ( 0x41 , 0x59 ) ;
F_24 ( 0x41 , 0x5A ) ;
}
}
break;
case V_120 | V_124 :
F_26 ( & V_33 ) ;
break;
case V_120 | V_125 | V_84 :
case V_120 | V_126 | V_84 :
case V_120 | V_127 | V_84 :
case V_120 | V_128 | V_84 :
case V_120 | V_129 | V_84 :
case V_120 | V_130 | V_84 :
case V_120 | V_131 | V_84 :
case V_120 | V_132 | V_84 :
case V_120 | V_133 | V_84 :
case V_120 | V_134 | V_84 :
F_20 ( F_14 ( 0x48 , V_26 , V_28 ) , 0x39 ,
F_16 ( 0xC0 , V_26 , V_28 ) ) ;
goto V_135;
case V_120 | V_136 | V_84 :
F_20 ( F_14 ( 0x48 , V_26 , V_28 ) , 0x85 ,
F_16 ( 0xC0 , V_26 , V_28 ) ) ;
goto V_135;
case V_120 | V_136 | V_92 :
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
F_29 ( 0xF7 , F_15 ( 0xC0 , V_26 ) , V_71 ) ;
goto V_135;
case V_120 | V_125 | V_92 :
case V_120 | V_126 | V_92 :
case V_120 | V_127 | V_92 :
case V_120 | V_128 | V_92 :
case V_120 | V_129 | V_92 :
case V_120 | V_130 | V_92 :
case V_120 | V_131 | V_92 :
case V_120 | V_132 | V_92 :
case V_120 | V_133 | V_92 :
case V_120 | V_134 | V_92 :
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
if ( F_3 ( V_71 ) )
F_20 ( 0x83 , F_15 ( 0xF8 , V_26 ) , V_71 ) ;
else
F_29 ( 0x81 , F_15 ( 0xF8 , V_26 ) , V_71 ) ;
V_135:
switch ( F_35 ( V_59 -> V_81 ) ) {
case V_125 :
V_77 = V_47 ;
break;
case V_136 :
case V_126 :
V_77 = V_98 ;
break;
case V_127 :
V_77 = V_45 ;
break;
case V_128 :
V_77 = V_137 ;
break;
case V_129 :
V_77 = V_138 ;
break;
case V_130 :
V_77 = V_43 ;
break;
case V_131 :
V_77 = V_139 ;
break;
case V_132 :
V_77 = V_140 ;
break;
case V_133 :
V_77 = V_141 ;
break;
case V_134 :
V_77 = V_142 ;
break;
default:
return - V_143 ;
}
V_76 = V_53 [ V_68 + V_59 -> V_111 ] - V_53 [ V_68 ] ;
if ( F_3 ( V_76 ) ) {
F_24 ( V_77 , V_76 ) ;
} else if ( F_4 ( V_76 ) ) {
F_29 ( 0x0F , V_77 + 0x10 , V_76 ) ;
} else {
F_43 ( L_2 , V_76 ) ;
return - V_143 ;
}
break;
case V_120 | V_144 :
V_76 = V_53 [ V_68 + V_59 -> V_111 ] - V_53 [ V_68 ] ;
if ( ! V_76 )
break;
V_145:
if ( F_3 ( V_76 ) ) {
F_24 ( 0xEB , V_76 ) ;
} else if ( F_4 ( V_76 ) ) {
F_38 ( 0xE9 , V_76 ) ;
} else {
F_43 ( L_3 , V_76 ) ;
return - V_143 ;
}
break;
case V_93 | V_146 | V_8 :
V_80 = V_147 ;
goto V_148;
case V_93 | V_149 | V_8 :
V_80 = F_44 ( V_71 , V_147 ) ;
V_148:
V_57 -> V_62 = V_62 = true ;
V_76 = V_80 - ( V_54 + V_53 [ V_68 ] ) ;
if ( ! V_80 || ! F_4 ( V_76 ) ) {
F_43 ( L_1 ,
V_71 , V_80 , V_54 ) ;
return - V_123 ;
}
if ( F_45 ( V_59 -> V_81 ) == V_149 ) {
F_38 ( 0xBE , V_71 ) ;
} else {
F_37 ( V_114 , V_28 ) ;
if ( V_71 ) {
if ( F_3 ( V_71 ) )
F_20 ( 0x83 , 0xC6 , V_71 ) ;
else
F_29 ( 0x81 , 0xC6 , V_71 ) ;
}
}
if ( V_63 )
F_21 ( 0x4c , 0x8b , 0x93 ,
F_27 ( struct V_50 , V_52 ) ) ;
F_38 ( 0xE8 , V_76 ) ;
break;
case V_93 | V_146 | V_9 :
V_80 = V_150 ;
goto V_148;
case V_93 | V_149 | V_9 :
V_80 = F_44 ( V_71 , V_150 ) ;
goto V_148;
case V_93 | V_146 | V_10 :
V_80 = V_151 ;
goto V_148;
case V_93 | V_149 | V_10 :
V_80 = F_44 ( V_71 , V_151 ) ;
goto V_148;
case V_120 | V_152 :
if ( V_64 ) {
V_76 = V_57 -> V_99 - V_53 [ V_68 ] ;
goto V_145;
}
V_64 = true ;
V_57 -> V_99 = V_69 ;
F_23 ( 0x48 , 0x8B , 0x5D , 0 ) ;
F_23 ( 0x4C , 0x8B , 0x6D , 8 ) ;
F_23 ( 0x4C , 0x8B , 0x75 , 16 ) ;
F_23 ( 0x4C , 0x8B , 0x7D , 24 ) ;
F_23 ( 0x48 , 0x83 , 0xC5 , V_35 ) ;
F_19 ( 0xC9 ) ;
F_19 ( 0xC3 ) ;
break;
default:
F_43 ( L_4 , V_59 -> V_81 ) ;
return - V_123 ;
}
V_79 = V_33 - V_65 ;
if ( V_79 > V_66 ) {
F_43 ( L_5 ) ;
return - V_143 ;
}
if ( V_54 ) {
if ( F_46 ( V_69 + V_79 > V_55 ) ) {
F_43 ( L_6 ) ;
return - V_143 ;
}
memcpy ( V_54 + V_69 , V_65 , V_79 ) ;
}
V_69 += V_79 ;
V_53 [ V_68 ] = V_69 ;
V_33 = V_65 ;
}
return V_69 ;
}
struct V_48 * F_47 ( struct V_48 * V_33 )
{
struct V_153 * V_154 = NULL ;
struct V_48 * V_155 , * V_156 = V_33 ;
int V_69 , V_55 = 0 ;
struct V_56 V_57 = {} ;
bool V_157 = false ;
T_1 * V_54 = NULL ;
int * V_53 ;
int V_158 ;
int V_68 ;
if ( ! V_159 )
return V_156 ;
V_155 = F_48 ( V_33 ) ;
if ( F_49 ( V_155 ) )
return V_156 ;
if ( V_155 != V_33 ) {
V_157 = true ;
V_33 = V_155 ;
}
V_53 = F_50 ( V_33 -> V_3 * sizeof( * V_53 ) , V_160 ) ;
if ( ! V_53 ) {
V_33 = V_156 ;
goto V_161;
}
for ( V_69 = 0 , V_68 = 0 ; V_68 < V_33 -> V_3 ; V_68 ++ ) {
V_69 += 64 ;
V_53 [ V_68 ] = V_69 ;
}
V_57 . V_99 = V_69 ;
for ( V_158 = 0 ; V_158 < 10 || V_54 ; V_158 ++ ) {
V_69 = F_34 ( V_33 , V_53 , V_54 , V_55 , & V_57 ) ;
if ( V_69 <= 0 ) {
V_54 = NULL ;
if ( V_154 )
F_51 ( V_154 ) ;
V_33 = V_156 ;
goto V_162;
}
if ( V_54 ) {
if ( V_69 != V_55 ) {
F_43 ( L_7 ,
V_69 , V_55 ) ;
V_33 = V_156 ;
goto V_162;
}
break;
}
if ( V_69 == V_55 ) {
V_154 = F_52 ( V_69 , & V_54 ,
1 , F_17 ) ;
if ( ! V_154 ) {
V_33 = V_156 ;
goto V_162;
}
}
V_55 = V_69 ;
}
if ( V_159 > 1 )
F_53 ( V_33 -> V_3 , V_69 , V_158 + 1 , V_54 ) ;
if ( V_54 ) {
F_6 ( V_154 , V_54 + V_69 ) ;
F_54 ( V_154 ) ;
V_33 -> V_49 = ( void * ) V_54 ;
V_33 -> V_163 = 1 ;
V_33 -> V_164 = V_69 ;
} else {
V_33 = V_156 ;
}
V_162:
F_55 ( V_53 ) ;
V_161:
if ( V_157 )
F_56 ( V_33 , V_33 == V_156 ?
V_155 : V_156 ) ;
return V_33 ;
}
