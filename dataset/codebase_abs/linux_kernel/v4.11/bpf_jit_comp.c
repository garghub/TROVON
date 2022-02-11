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
static void F_18 ( T_1 * * V_31 )
{
T_1 * V_32 = * V_31 ;
int V_33 = 0 ;
F_19 ( 0x55 ) ;
F_20 ( 0x48 , 0x89 , 0xE5 ) ;
F_21 ( 0x48 , 0x81 , 0xEC , V_34 ) ;
F_21 ( 0x48 , 0x89 , 0x9D , - V_34 ) ;
F_21 ( 0x4C , 0x89 , 0xAD , - V_34 + 8 ) ;
F_21 ( 0x4C , 0x89 , 0xB5 , - V_34 + 16 ) ;
F_21 ( 0x4C , 0x89 , 0xBD , - V_34 + 24 ) ;
F_22 ( 0x31 , 0xc0 ) ;
F_21 ( 0x48 , 0x89 , 0x85 , - V_34 + 32 ) ;
F_23 ( V_33 != V_35 ) ;
* V_31 = V_32 ;
}
static void F_24 ( T_1 * * V_31 )
{
T_1 * V_32 = * V_31 ;
int V_36 , V_37 , V_38 ;
int V_33 = 0 ;
F_25 ( 0x48 , 0x8B , 0x46 ,
F_26 ( struct V_39 , V_40 . V_41 ) ) ;
F_20 ( 0x48 , 0x39 , 0xD0 ) ;
#define F_27 47
F_22 ( V_42 , F_27 ) ;
V_36 = V_33 ;
F_28 ( 0x8B , 0x85 , - V_34 + 36 ) ;
F_20 ( 0x83 , 0xF8 , V_43 ) ;
#define F_29 36
F_22 ( V_44 , F_29 ) ;
V_37 = V_33 ;
F_20 ( 0x83 , 0xC0 , 0x01 ) ;
F_28 ( 0x89 , 0x85 , - V_34 + 36 ) ;
F_30 ( 0x48 , 0x8D , 0x84 , 0xD6 ,
F_26 ( struct V_39 , V_45 ) ) ;
F_20 ( 0x48 , 0x8B , 0x00 ) ;
F_25 ( 0x48 , 0x83 , 0xF8 , 0x00 ) ;
#define F_31 10
F_22 ( V_46 , F_31 ) ;
V_38 = V_33 ;
F_25 ( 0x48 , 0x8B , 0x40 ,
F_26 ( struct V_47 , V_48 ) ) ;
F_25 ( 0x48 , 0x83 , 0xC0 , V_35 ) ;
F_22 ( 0xFF , 0xE0 ) ;
F_23 ( V_33 - V_36 != F_27 ) ;
F_23 ( V_33 - V_37 != F_29 ) ;
F_23 ( V_33 - V_38 != F_31 ) ;
* V_31 = V_32 ;
}
static void F_32 ( T_1 * * V_31 )
{
T_1 * V_32 = * V_31 ;
int V_33 = 0 ;
F_21 ( 0x44 , 0x8b , 0x8f , F_26 ( struct V_49 , V_3 ) ) ;
F_21 ( 0x44 , 0x2b , 0x8f , F_26 ( struct V_49 , V_50 ) ) ;
F_21 ( 0x4c , 0x8b , 0x97 , F_26 ( struct V_49 , V_51 ) ) ;
* V_31 = V_32 ;
}
static int F_33 ( struct V_47 * V_47 , int * V_52 , T_1 * V_53 ,
int V_54 , struct V_55 * V_56 )
{
struct V_57 * V_58 = V_47 -> V_59 ;
int V_60 = V_47 -> V_3 ;
bool V_61 = V_56 -> V_61 | ( V_54 == 0 ) ;
bool V_62 = V_56 -> V_62 | ( V_54 == 0 ) ;
bool V_63 = false ;
T_1 V_64 [ V_65 + V_66 ] ;
int V_67 , V_33 = 0 ;
int V_68 = 0 ;
T_1 * V_32 = V_64 ;
F_18 ( & V_32 ) ;
if ( V_61 )
F_32 ( & V_32 ) ;
for ( V_67 = 0 ; V_67 < V_60 ; V_67 ++ , V_58 ++ ) {
const V_6 V_69 = V_58 -> V_70 ;
T_2 V_26 = V_58 -> V_26 ;
T_2 V_28 = V_58 -> V_28 ;
T_1 V_71 = 0 , V_72 = 0 , V_73 = 0 ;
T_3 V_74 ;
T_1 V_75 ;
bool V_76 ;
int V_77 ;
T_1 * V_78 ;
if ( V_26 == V_22 || V_28 == V_22 )
V_56 -> V_62 = V_62 = true ;
switch ( V_58 -> V_79 ) {
case V_80 | V_81 | V_82 :
case V_80 | V_83 | V_82 :
case V_80 | V_84 | V_82 :
case V_80 | V_85 | V_82 :
case V_80 | V_86 | V_82 :
case V_87 | V_81 | V_82 :
case V_87 | V_83 | V_82 :
case V_87 | V_84 | V_82 :
case V_87 | V_85 | V_82 :
case V_87 | V_86 | V_82 :
switch ( F_34 ( V_58 -> V_79 ) ) {
case V_81 : V_72 = 0x01 ; break;
case V_83 : V_72 = 0x29 ; break;
case V_84 : V_72 = 0x21 ; break;
case V_85 : V_72 = 0x09 ; break;
case V_86 : V_72 = 0x31 ; break;
}
if ( F_35 ( V_58 -> V_79 ) == V_87 )
F_19 ( F_14 ( 0x48 , V_26 , V_28 ) ) ;
else if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_19 ( F_14 ( 0x40 , V_26 , V_28 ) ) ;
F_22 ( V_72 , F_16 ( 0xC0 , V_26 , V_28 ) ) ;
break;
case V_87 | V_88 | V_82 :
F_36 ( V_26 , V_28 ) ;
break;
case V_80 | V_88 | V_82 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_19 ( F_14 ( 0x40 , V_26 , V_28 ) ) ;
F_22 ( 0x89 , F_16 ( 0xC0 , V_26 , V_28 ) ) ;
break;
case V_80 | V_89 :
case V_87 | V_89 :
if ( F_35 ( V_58 -> V_79 ) == V_87 )
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
else if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
F_22 ( 0xF7 , F_15 ( 0xD8 , V_26 ) ) ;
break;
case V_80 | V_81 | V_90 :
case V_80 | V_83 | V_90 :
case V_80 | V_84 | V_90 :
case V_80 | V_85 | V_90 :
case V_80 | V_86 | V_90 :
case V_87 | V_81 | V_90 :
case V_87 | V_83 | V_90 :
case V_87 | V_84 | V_90 :
case V_87 | V_85 | V_90 :
case V_87 | V_86 | V_90 :
if ( F_35 ( V_58 -> V_79 ) == V_87 )
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
else if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
switch ( F_34 ( V_58 -> V_79 ) ) {
case V_81 : V_73 = 0xC0 ; break;
case V_83 : V_73 = 0xE8 ; break;
case V_84 : V_73 = 0xE0 ; break;
case V_85 : V_73 = 0xC8 ; break;
case V_86 : V_73 = 0xF0 ; break;
}
if ( F_3 ( V_69 ) )
F_20 ( 0x83 , F_15 ( V_73 , V_26 ) , V_69 ) ;
else
F_28 ( 0x81 , F_15 ( V_73 , V_26 ) , V_69 ) ;
break;
case V_87 | V_88 | V_90 :
if ( V_69 < 0 ) {
V_71 = F_13 ( 0x48 , V_26 ) ;
V_72 = 0xC7 ;
V_73 = 0xC0 ;
F_21 ( V_71 , V_72 , F_15 ( V_73 , V_26 ) , V_69 ) ;
break;
}
case V_80 | V_88 | V_90 :
if ( V_69 == 0 ) {
if ( F_11 ( V_26 ) )
F_19 ( F_14 ( 0x40 , V_26 , V_26 ) ) ;
V_72 = 0x31 ;
V_73 = 0xC0 ;
F_22 ( V_72 , F_16 ( V_73 , V_26 , V_26 ) ) ;
break;
}
if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
F_37 ( F_15 ( 0xB8 , V_26 ) , V_69 ) ;
break;
case V_91 | V_92 | V_11 :
if ( V_58 [ 1 ] . V_79 != 0 || V_58 [ 1 ] . V_28 != 0 ||
V_58 [ 1 ] . V_26 != 0 || V_58 [ 1 ] . V_93 != 0 ) {
F_38 ( L_1 ) ;
return - V_94 ;
}
if ( V_58 [ 0 ] . V_70 == 0 && V_58 [ 1 ] . V_70 == 0 ) {
V_71 = F_14 ( 0x48 , V_26 , V_26 ) ;
V_72 = 0x31 ;
V_73 = 0xC0 ;
F_20 ( V_71 , V_72 , F_16 ( V_73 , V_26 , V_26 ) ) ;
V_58 ++ ;
V_67 ++ ;
break;
}
F_22 ( F_13 ( 0x48 , V_26 ) , F_15 ( 0xB8 , V_26 ) ) ;
F_39 ( V_58 [ 0 ] . V_70 , 4 ) ;
F_39 ( V_58 [ 1 ] . V_70 , 4 ) ;
V_58 ++ ;
V_67 ++ ;
break;
case V_80 | V_95 | V_82 :
case V_80 | V_96 | V_82 :
case V_80 | V_95 | V_90 :
case V_80 | V_96 | V_90 :
case V_87 | V_95 | V_82 :
case V_87 | V_96 | V_82 :
case V_87 | V_95 | V_90 :
case V_87 | V_96 | V_90 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
if ( F_40 ( V_58 -> V_79 ) == V_82 )
F_36 ( V_18 , V_28 ) ;
else
F_21 ( 0x49 , 0xC7 , 0xC3 , V_69 ) ;
F_36 ( V_97 , V_26 ) ;
F_22 ( 0x31 , 0xd2 ) ;
if ( F_40 ( V_58 -> V_79 ) == V_82 ) {
F_25 ( 0x49 , 0x83 , 0xFB , 0x00 ) ;
F_22 ( V_98 , 1 + 1 + 2 + 5 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_22 ( 0x31 , 0xc0 ) ;
V_74 = V_56 -> V_99 - ( V_52 [ V_67 ] - 11 ) ;
F_37 ( 0xE9 , V_74 ) ;
}
if ( F_35 ( V_58 -> V_79 ) == V_87 )
F_20 ( 0x49 , 0xF7 , 0xF3 ) ;
else
F_20 ( 0x41 , 0xF7 , 0xF3 ) ;
if ( F_34 ( V_58 -> V_79 ) == V_95 )
F_20 ( 0x49 , 0x89 , 0xD3 ) ;
else
F_20 ( 0x49 , 0x89 , 0xC3 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_36 ( V_26 , V_18 ) ;
break;
case V_80 | V_100 | V_90 :
case V_80 | V_100 | V_82 :
case V_87 | V_100 | V_90 :
case V_87 | V_100 | V_82 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
F_36 ( V_18 , V_26 ) ;
if ( F_40 ( V_58 -> V_79 ) == V_82 )
F_36 ( V_97 , V_28 ) ;
else
F_21 ( 0x48 , 0xC7 , 0xC0 , V_69 ) ;
if ( F_35 ( V_58 -> V_79 ) == V_87 )
F_19 ( F_13 ( 0x48 , V_18 ) ) ;
else if ( F_11 ( V_18 ) )
F_19 ( F_13 ( 0x40 , V_18 ) ) ;
F_22 ( 0xF7 , F_15 ( 0xE0 , V_18 ) ) ;
F_36 ( V_18 , V_97 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_36 ( V_26 , V_18 ) ;
break;
case V_80 | V_101 | V_90 :
case V_80 | V_102 | V_90 :
case V_80 | V_103 | V_90 :
case V_87 | V_101 | V_90 :
case V_87 | V_102 | V_90 :
case V_87 | V_103 | V_90 :
if ( F_35 ( V_58 -> V_79 ) == V_87 )
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
else if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
switch ( F_34 ( V_58 -> V_79 ) ) {
case V_101 : V_73 = 0xE0 ; break;
case V_102 : V_73 = 0xE8 ; break;
case V_103 : V_73 = 0xF8 ; break;
}
F_20 ( 0xC1 , F_15 ( V_73 , V_26 ) , V_69 ) ;
break;
case V_80 | V_101 | V_82 :
case V_80 | V_102 | V_82 :
case V_80 | V_103 | V_82 :
case V_87 | V_101 | V_82 :
case V_87 | V_102 | V_82 :
case V_87 | V_103 | V_82 :
if ( V_26 == V_104 ) {
F_36 ( V_18 , V_26 ) ;
V_26 = V_18 ;
}
if ( V_28 != V_104 ) {
F_19 ( 0x51 ) ;
F_36 ( V_104 , V_28 ) ;
}
if ( F_35 ( V_58 -> V_79 ) == V_87 )
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
else if ( F_11 ( V_26 ) )
F_19 ( F_13 ( 0x40 , V_26 ) ) ;
switch ( F_34 ( V_58 -> V_79 ) ) {
case V_101 : V_73 = 0xE0 ; break;
case V_102 : V_73 = 0xE8 ; break;
case V_103 : V_73 = 0xF8 ; break;
}
F_22 ( 0xD3 , F_15 ( V_73 , V_26 ) ) ;
if ( V_28 != V_104 )
F_19 ( 0x59 ) ;
if ( V_58 -> V_26 == V_104 )
F_36 ( V_58 -> V_26 , V_18 ) ;
break;
case V_80 | V_105 | V_106 :
switch ( V_69 ) {
case 16 :
F_19 ( 0x66 ) ;
if ( F_11 ( V_26 ) )
F_19 ( 0x41 ) ;
F_20 ( 0xC1 , F_15 ( 0xC8 , V_26 ) , 8 ) ;
if ( F_11 ( V_26 ) )
F_20 ( 0x45 , 0x0F , 0xB7 ) ;
else
F_22 ( 0x0F , 0xB7 ) ;
F_19 ( F_16 ( 0xC0 , V_26 , V_26 ) ) ;
break;
case 32 :
if ( F_11 ( V_26 ) )
F_22 ( 0x41 , 0x0F ) ;
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
case V_80 | V_105 | V_107 :
switch ( V_69 ) {
case 16 :
if ( F_11 ( V_26 ) )
F_20 ( 0x45 , 0x0F , 0xB7 ) ;
else
F_22 ( 0x0F , 0xB7 ) ;
F_19 ( F_16 ( 0xC0 , V_26 , V_26 ) ) ;
break;
case 32 :
if ( F_11 ( V_26 ) )
F_19 ( 0x45 ) ;
F_22 ( 0x89 , F_16 ( 0xC0 , V_26 , V_26 ) ) ;
break;
case 64 :
break;
}
break;
case V_108 | V_109 | V_10 :
if ( F_11 ( V_26 ) )
F_22 ( 0x41 , 0xC6 ) ;
else
F_19 ( 0xC6 ) ;
goto V_110;
case V_108 | V_109 | V_9 :
if ( F_11 ( V_26 ) )
F_20 ( 0x66 , 0x41 , 0xC7 ) ;
else
F_22 ( 0x66 , 0xC7 ) ;
goto V_110;
case V_108 | V_109 | V_8 :
if ( F_11 ( V_26 ) )
F_22 ( 0x41 , 0xC7 ) ;
else
F_19 ( 0xC7 ) ;
goto V_110;
case V_108 | V_109 | V_11 :
F_22 ( F_13 ( 0x48 , V_26 ) , 0xC7 ) ;
V_110: if ( F_3 ( V_58 -> V_93 ) )
F_22 ( F_15 ( 0x40 , V_26 ) , V_58 -> V_93 ) ;
else
F_37 ( F_15 ( 0x80 , V_26 ) , V_58 -> V_93 ) ;
F_39 ( V_69 , F_5 ( F_41 ( V_58 -> V_79 ) ) ) ;
break;
case V_111 | V_109 | V_10 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) ||
V_28 == V_112 || V_28 == V_113 )
F_22 ( F_14 ( 0x40 , V_26 , V_28 ) , 0x88 ) ;
else
F_19 ( 0x88 ) ;
goto V_114;
case V_111 | V_109 | V_9 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_20 ( 0x66 , F_14 ( 0x40 , V_26 , V_28 ) , 0x89 ) ;
else
F_22 ( 0x66 , 0x89 ) ;
goto V_114;
case V_111 | V_109 | V_8 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_22 ( F_14 ( 0x40 , V_26 , V_28 ) , 0x89 ) ;
else
F_19 ( 0x89 ) ;
goto V_114;
case V_111 | V_109 | V_11 :
F_22 ( F_14 ( 0x48 , V_26 , V_28 ) , 0x89 ) ;
V_114: if ( F_3 ( V_58 -> V_93 ) )
F_22 ( F_16 ( 0x40 , V_26 , V_28 ) , V_58 -> V_93 ) ;
else
F_37 ( F_16 ( 0x80 , V_26 , V_28 ) ,
V_58 -> V_93 ) ;
break;
case V_115 | V_109 | V_10 :
F_20 ( F_14 ( 0x48 , V_28 , V_26 ) , 0x0F , 0xB6 ) ;
goto V_116;
case V_115 | V_109 | V_9 :
F_20 ( F_14 ( 0x48 , V_28 , V_26 ) , 0x0F , 0xB7 ) ;
goto V_116;
case V_115 | V_109 | V_8 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_22 ( F_14 ( 0x40 , V_28 , V_26 ) , 0x8B ) ;
else
F_19 ( 0x8B ) ;
goto V_116;
case V_115 | V_109 | V_11 :
F_22 ( F_14 ( 0x48 , V_28 , V_26 ) , 0x8B ) ;
V_116:
if ( F_3 ( V_58 -> V_93 ) )
F_22 ( F_16 ( 0x40 , V_28 , V_26 ) , V_58 -> V_93 ) ;
else
F_37 ( F_16 ( 0x80 , V_28 , V_26 ) ,
V_58 -> V_93 ) ;
break;
case V_111 | V_117 | V_8 :
if ( F_11 ( V_26 ) || F_11 ( V_28 ) )
F_20 ( 0xF0 , F_14 ( 0x40 , V_26 , V_28 ) , 0x01 ) ;
else
F_22 ( 0xF0 , 0x01 ) ;
goto V_118;
case V_111 | V_117 | V_11 :
F_20 ( 0xF0 , F_14 ( 0x48 , V_26 , V_28 ) , 0x01 ) ;
V_118: if ( F_3 ( V_58 -> V_93 ) )
F_22 ( F_16 ( 0x40 , V_26 , V_28 ) , V_58 -> V_93 ) ;
else
F_37 ( F_16 ( 0x80 , V_26 , V_28 ) ,
V_58 -> V_93 ) ;
break;
case V_119 | V_120 :
V_78 = ( T_1 * ) V_121 + V_69 ;
V_74 = V_78 - ( V_53 + V_52 [ V_67 ] ) ;
if ( V_61 ) {
V_76 = F_42 ( V_78 ) ;
if ( V_76 ) {
F_19 ( 0x57 ) ;
V_74 += 22 ;
} else {
F_22 ( 0x41 , 0x52 ) ;
F_22 ( 0x41 , 0x51 ) ;
V_74 += 4 ;
}
}
if ( ! V_69 || ! F_4 ( V_74 ) ) {
F_38 ( L_2 ,
V_69 , V_78 , V_53 ) ;
return - V_94 ;
}
F_37 ( 0xE8 , V_74 ) ;
if ( V_61 ) {
if ( V_76 ) {
F_19 ( 0x5F ) ;
F_32 ( & V_32 ) ;
} else {
F_22 ( 0x41 , 0x59 ) ;
F_22 ( 0x41 , 0x5A ) ;
}
}
break;
case V_119 | V_120 | V_82 :
F_24 ( & V_32 ) ;
break;
case V_119 | V_122 | V_82 :
case V_119 | V_123 | V_82 :
case V_119 | V_124 | V_82 :
case V_119 | V_125 | V_82 :
case V_119 | V_126 | V_82 :
case V_119 | V_127 | V_82 :
F_20 ( F_14 ( 0x48 , V_26 , V_28 ) , 0x39 ,
F_16 ( 0xC0 , V_26 , V_28 ) ) ;
goto V_128;
case V_119 | V_129 | V_82 :
F_20 ( F_14 ( 0x48 , V_26 , V_28 ) , 0x85 ,
F_16 ( 0xC0 , V_26 , V_28 ) ) ;
goto V_128;
case V_119 | V_129 | V_90 :
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
F_28 ( 0xF7 , F_15 ( 0xC0 , V_26 ) , V_69 ) ;
goto V_128;
case V_119 | V_122 | V_90 :
case V_119 | V_123 | V_90 :
case V_119 | V_124 | V_90 :
case V_119 | V_125 | V_90 :
case V_119 | V_126 | V_90 :
case V_119 | V_127 | V_90 :
F_19 ( F_13 ( 0x48 , V_26 ) ) ;
if ( F_3 ( V_69 ) )
F_20 ( 0x83 , F_15 ( 0xF8 , V_26 ) , V_69 ) ;
else
F_28 ( 0x81 , F_15 ( 0xF8 , V_26 ) , V_69 ) ;
V_128:
switch ( F_34 ( V_58 -> V_79 ) ) {
case V_122 :
V_75 = V_46 ;
break;
case V_129 :
case V_123 :
V_75 = V_98 ;
break;
case V_124 :
V_75 = V_44 ;
break;
case V_125 :
V_75 = V_130 ;
break;
case V_126 :
V_75 = V_131 ;
break;
case V_127 :
V_75 = V_132 ;
break;
default:
return - V_133 ;
}
V_74 = V_52 [ V_67 + V_58 -> V_93 ] - V_52 [ V_67 ] ;
if ( F_3 ( V_74 ) ) {
F_22 ( V_75 , V_74 ) ;
} else if ( F_4 ( V_74 ) ) {
F_28 ( 0x0F , V_75 + 0x10 , V_74 ) ;
} else {
F_38 ( L_3 , V_74 ) ;
return - V_133 ;
}
break;
case V_119 | V_134 :
V_74 = V_52 [ V_67 + V_58 -> V_93 ] - V_52 [ V_67 ] ;
if ( ! V_74 )
break;
V_135:
if ( F_3 ( V_74 ) ) {
F_22 ( 0xEB , V_74 ) ;
} else if ( F_4 ( V_74 ) ) {
F_37 ( 0xE9 , V_74 ) ;
} else {
F_38 ( L_4 , V_74 ) ;
return - V_133 ;
}
break;
case V_91 | V_136 | V_8 :
V_78 = V_137 ;
goto V_138;
case V_91 | V_139 | V_8 :
V_78 = F_43 ( V_69 , V_137 ) ;
V_138:
V_56 -> V_61 = V_61 = true ;
V_74 = V_78 - ( V_53 + V_52 [ V_67 ] ) ;
if ( ! V_78 || ! F_4 ( V_74 ) ) {
F_38 ( L_2 ,
V_69 , V_78 , V_53 ) ;
return - V_94 ;
}
if ( F_44 ( V_58 -> V_79 ) == V_139 ) {
F_37 ( 0xBE , V_69 ) ;
} else {
F_36 ( V_113 , V_28 ) ;
if ( V_69 ) {
if ( F_3 ( V_69 ) )
F_20 ( 0x83 , 0xC6 , V_69 ) ;
else
F_28 ( 0x81 , 0xC6 , V_69 ) ;
}
}
if ( V_62 )
F_21 ( 0x4c , 0x8b , 0x93 ,
F_26 ( struct V_49 , V_51 ) ) ;
F_37 ( 0xE8 , V_74 ) ;
break;
case V_91 | V_136 | V_9 :
V_78 = V_140 ;
goto V_138;
case V_91 | V_139 | V_9 :
V_78 = F_43 ( V_69 , V_140 ) ;
goto V_138;
case V_91 | V_136 | V_10 :
V_78 = V_141 ;
goto V_138;
case V_91 | V_139 | V_10 :
V_78 = F_43 ( V_69 , V_141 ) ;
goto V_138;
case V_119 | V_142 :
if ( V_63 ) {
V_74 = V_56 -> V_99 - V_52 [ V_67 ] ;
goto V_135;
}
V_63 = true ;
V_56 -> V_99 = V_68 ;
F_21 ( 0x48 , 0x8B , 0x9D , - V_34 ) ;
F_21 ( 0x4C , 0x8B , 0xAD , - V_34 + 8 ) ;
F_21 ( 0x4C , 0x8B , 0xB5 , - V_34 + 16 ) ;
F_21 ( 0x4C , 0x8B , 0xBD , - V_34 + 24 ) ;
F_19 ( 0xC9 ) ;
F_19 ( 0xC3 ) ;
break;
default:
F_38 ( L_5 , V_58 -> V_79 ) ;
return - V_94 ;
}
V_77 = V_32 - V_64 ;
if ( V_77 > V_65 ) {
F_38 ( L_6 ) ;
return - V_133 ;
}
if ( V_53 ) {
if ( F_45 ( V_68 + V_77 > V_54 ) ) {
F_38 ( L_7 ) ;
return - V_133 ;
}
memcpy ( V_53 + V_68 , V_64 , V_77 ) ;
}
V_68 += V_77 ;
V_52 [ V_67 ] = V_68 ;
V_32 = V_64 ;
}
return V_68 ;
}
struct V_47 * F_46 ( struct V_47 * V_32 )
{
struct V_143 * V_144 = NULL ;
struct V_47 * V_145 , * V_146 = V_32 ;
int V_68 , V_54 = 0 ;
struct V_55 V_56 = {} ;
bool V_147 = false ;
T_1 * V_53 = NULL ;
int * V_52 ;
int V_148 ;
int V_67 ;
if ( ! V_149 )
return V_146 ;
V_145 = F_47 ( V_32 ) ;
if ( F_48 ( V_145 ) )
return V_146 ;
if ( V_145 != V_32 ) {
V_147 = true ;
V_32 = V_145 ;
}
V_52 = F_49 ( V_32 -> V_3 * sizeof( * V_52 ) , V_150 ) ;
if ( ! V_52 ) {
V_32 = V_146 ;
goto V_151;
}
for ( V_68 = 0 , V_67 = 0 ; V_67 < V_32 -> V_3 ; V_67 ++ ) {
V_68 += 64 ;
V_52 [ V_67 ] = V_68 ;
}
V_56 . V_99 = V_68 ;
for ( V_148 = 0 ; V_148 < 10 || V_53 ; V_148 ++ ) {
V_68 = F_33 ( V_32 , V_52 , V_53 , V_54 , & V_56 ) ;
if ( V_68 <= 0 ) {
V_53 = NULL ;
if ( V_144 )
F_50 ( V_144 ) ;
V_32 = V_146 ;
goto V_152;
}
if ( V_53 ) {
if ( V_68 != V_54 ) {
F_38 ( L_8 ,
V_68 , V_54 ) ;
V_32 = V_146 ;
goto V_152;
}
break;
}
if ( V_68 == V_54 ) {
V_144 = F_51 ( V_68 , & V_53 ,
1 , F_17 ) ;
if ( ! V_144 ) {
V_32 = V_146 ;
goto V_152;
}
}
V_54 = V_68 ;
}
if ( V_149 > 1 )
F_52 ( V_32 -> V_3 , V_68 , V_148 + 1 , V_53 ) ;
if ( V_53 ) {
F_6 ( V_144 , V_53 + V_68 ) ;
F_53 ( V_144 ) ;
V_32 -> V_48 = ( void * ) V_53 ;
V_32 -> V_153 = 1 ;
} else {
V_32 = V_146 ;
}
V_152:
F_54 ( V_52 ) ;
V_151:
if ( V_147 )
F_55 ( V_32 , V_32 == V_146 ?
V_145 : V_146 ) ;
return V_32 ;
}
