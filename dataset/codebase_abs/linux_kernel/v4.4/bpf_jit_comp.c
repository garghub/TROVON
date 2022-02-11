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
F_12 ( V_21 ) ) ;
}
static T_1 F_13 ( T_1 V_22 , T_2 V_16 )
{
if ( F_11 ( V_16 ) )
V_22 |= 1 ;
return V_22 ;
}
static T_1 F_14 ( T_1 V_22 , T_2 V_23 , T_2 V_24 )
{
if ( F_11 ( V_23 ) )
V_22 |= 1 ;
if ( F_11 ( V_24 ) )
V_22 |= 4 ;
return V_22 ;
}
static T_1 F_15 ( T_1 V_22 , T_2 V_25 )
{
return V_22 + V_26 [ V_25 ] ;
}
static T_1 F_16 ( T_1 V_22 , T_2 V_25 , T_2 V_27 )
{
return V_22 + V_26 [ V_25 ] + ( V_26 [ V_27 ] << 3 ) ;
}
static void F_17 ( void * V_28 , unsigned int V_29 )
{
memset ( V_28 , 0xcc , V_29 ) ;
}
static void F_18 ( T_1 * * V_30 )
{
T_1 * V_31 = * V_30 ;
int V_32 = 0 ;
F_19 ( 0x55 ) ;
F_20 ( 0x48 , 0x89 , 0xE5 ) ;
F_21 ( 0x48 , 0x81 , 0xEC , V_33 ) ;
F_21 ( 0x48 , 0x89 , 0x9D , - V_33 ) ;
F_21 ( 0x4C , 0x89 , 0xAD , - V_33 + 8 ) ;
F_21 ( 0x4C , 0x89 , 0xB5 , - V_33 + 16 ) ;
F_21 ( 0x4C , 0x89 , 0xBD , - V_33 + 24 ) ;
F_22 ( 0x31 , 0xc0 ) ;
F_20 ( 0x4D , 0x31 , 0xED ) ;
F_21 ( 0x48 , 0x89 , 0x85 , - V_33 + 32 ) ;
F_23 ( V_32 != V_34 ) ;
* V_30 = V_31 ;
}
static void F_24 ( T_1 * * V_30 )
{
T_1 * V_31 = * V_30 ;
int V_35 , V_36 , V_37 ;
int V_32 = 0 ;
F_25 ( 0x48 , 0x8B , 0x46 ,
F_26 ( struct V_38 , V_39 . V_40 ) ) ;
F_20 ( 0x48 , 0x39 , 0xD0 ) ;
#define F_27 47
F_22 ( V_41 , F_27 ) ;
V_35 = V_32 ;
F_28 ( 0x8B , 0x85 , - V_33 + 36 ) ;
F_20 ( 0x83 , 0xF8 , V_42 ) ;
#define F_29 36
F_22 ( V_43 , F_29 ) ;
V_36 = V_32 ;
F_20 ( 0x83 , 0xC0 , 0x01 ) ;
F_28 ( 0x89 , 0x85 , - V_33 + 36 ) ;
F_30 ( 0x48 , 0x8D , 0x84 , 0xD6 ,
F_26 ( struct V_38 , V_44 ) ) ;
F_20 ( 0x48 , 0x8B , 0x00 ) ;
F_25 ( 0x48 , 0x83 , 0xF8 , 0x00 ) ;
#define F_31 10
F_22 ( V_45 , F_31 ) ;
V_37 = V_32 ;
F_25 ( 0x48 , 0x8B , 0x40 ,
F_26 ( struct V_46 , V_47 ) ) ;
F_25 ( 0x48 , 0x83 , 0xC0 , V_34 ) ;
F_22 ( 0xFF , 0xE0 ) ;
F_23 ( V_32 - V_35 != F_27 ) ;
F_23 ( V_32 - V_36 != F_29 ) ;
F_23 ( V_32 - V_37 != F_31 ) ;
* V_30 = V_31 ;
}
static void F_32 ( T_1 * * V_30 )
{
T_1 * V_31 = * V_30 ;
int V_32 = 0 ;
F_21 ( 0x44 , 0x8b , 0x8f , F_26 ( struct V_48 , V_3 ) ) ;
F_21 ( 0x44 , 0x2b , 0x8f , F_26 ( struct V_48 , V_49 ) ) ;
F_21 ( 0x4c , 0x8b , 0x97 , F_26 ( struct V_48 , V_50 ) ) ;
* V_30 = V_31 ;
}
static int F_33 ( struct V_46 * V_46 , int * V_51 , T_1 * V_52 ,
int V_53 , struct V_54 * V_55 )
{
struct V_56 * V_57 = V_46 -> V_58 ;
int V_59 = V_46 -> V_3 ;
bool V_60 = V_55 -> V_60 | ( V_53 == 0 ) ;
bool V_61 = false ;
T_1 V_62 [ V_63 + V_64 ] ;
int V_65 , V_32 = 0 ;
int V_66 = 0 ;
T_1 * V_31 = V_62 ;
F_18 ( & V_31 ) ;
if ( V_60 )
F_32 ( & V_31 ) ;
for ( V_65 = 0 ; V_65 < V_59 ; V_65 ++ , V_57 ++ ) {
const V_6 V_67 = V_57 -> V_68 ;
T_2 V_25 = V_57 -> V_25 ;
T_2 V_27 = V_57 -> V_27 ;
T_1 V_69 = 0 , V_70 = 0 , V_71 = 0 ;
T_3 V_72 ;
T_1 V_73 ;
bool V_74 ;
int V_75 ;
T_1 * V_76 ;
switch ( V_57 -> V_77 ) {
case V_78 | V_79 | V_80 :
case V_78 | V_81 | V_80 :
case V_78 | V_82 | V_80 :
case V_78 | V_83 | V_80 :
case V_78 | V_84 | V_80 :
case V_85 | V_79 | V_80 :
case V_85 | V_81 | V_80 :
case V_85 | V_82 | V_80 :
case V_85 | V_83 | V_80 :
case V_85 | V_84 | V_80 :
switch ( F_34 ( V_57 -> V_77 ) ) {
case V_79 : V_70 = 0x01 ; break;
case V_81 : V_70 = 0x29 ; break;
case V_82 : V_70 = 0x21 ; break;
case V_83 : V_70 = 0x09 ; break;
case V_84 : V_70 = 0x31 ; break;
}
if ( F_35 ( V_57 -> V_77 ) == V_85 )
F_19 ( F_14 ( 0x48 , V_25 , V_27 ) ) ;
else if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_19 ( F_14 ( 0x40 , V_25 , V_27 ) ) ;
F_22 ( V_70 , F_16 ( 0xC0 , V_25 , V_27 ) ) ;
break;
case V_85 | V_86 | V_80 :
F_36 ( V_25 , V_27 ) ;
break;
case V_78 | V_86 | V_80 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_19 ( F_14 ( 0x40 , V_25 , V_27 ) ) ;
F_22 ( 0x89 , F_16 ( 0xC0 , V_25 , V_27 ) ) ;
break;
case V_78 | V_87 :
case V_85 | V_87 :
if ( F_35 ( V_57 -> V_77 ) == V_85 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
F_22 ( 0xF7 , F_15 ( 0xD8 , V_25 ) ) ;
break;
case V_78 | V_79 | V_88 :
case V_78 | V_81 | V_88 :
case V_78 | V_82 | V_88 :
case V_78 | V_83 | V_88 :
case V_78 | V_84 | V_88 :
case V_85 | V_79 | V_88 :
case V_85 | V_81 | V_88 :
case V_85 | V_82 | V_88 :
case V_85 | V_83 | V_88 :
case V_85 | V_84 | V_88 :
if ( F_35 ( V_57 -> V_77 ) == V_85 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_34 ( V_57 -> V_77 ) ) {
case V_79 : V_71 = 0xC0 ; break;
case V_81 : V_71 = 0xE8 ; break;
case V_82 : V_71 = 0xE0 ; break;
case V_83 : V_71 = 0xC8 ; break;
case V_84 : V_71 = 0xF0 ; break;
}
if ( F_3 ( V_67 ) )
F_20 ( 0x83 , F_15 ( V_71 , V_25 ) , V_67 ) ;
else
F_28 ( 0x81 , F_15 ( V_71 , V_25 ) , V_67 ) ;
break;
case V_85 | V_86 | V_88 :
if ( V_67 < 0 ) {
V_69 = F_13 ( 0x48 , V_25 ) ;
V_70 = 0xC7 ;
V_71 = 0xC0 ;
F_21 ( V_69 , V_70 , F_15 ( V_71 , V_25 ) , V_67 ) ;
break;
}
case V_78 | V_86 | V_88 :
if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
F_37 ( F_15 ( 0xB8 , V_25 ) , V_67 ) ;
break;
case V_89 | V_90 | V_11 :
if ( V_57 [ 1 ] . V_77 != 0 || V_57 [ 1 ] . V_27 != 0 ||
V_57 [ 1 ] . V_25 != 0 || V_57 [ 1 ] . V_91 != 0 ) {
F_38 ( L_1 ) ;
return - V_92 ;
}
F_22 ( F_13 ( 0x48 , V_25 ) , F_15 ( 0xB8 , V_25 ) ) ;
F_39 ( V_57 [ 0 ] . V_68 , 4 ) ;
F_39 ( V_57 [ 1 ] . V_68 , 4 ) ;
V_57 ++ ;
V_65 ++ ;
break;
case V_78 | V_93 | V_80 :
case V_78 | V_94 | V_80 :
case V_78 | V_93 | V_88 :
case V_78 | V_94 | V_88 :
case V_85 | V_93 | V_80 :
case V_85 | V_94 | V_80 :
case V_85 | V_93 | V_88 :
case V_85 | V_94 | V_88 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
if ( F_40 ( V_57 -> V_77 ) == V_80 )
F_36 ( V_18 , V_27 ) ;
else
F_21 ( 0x49 , 0xC7 , 0xC3 , V_67 ) ;
F_36 ( V_95 , V_25 ) ;
F_22 ( 0x31 , 0xd2 ) ;
if ( F_40 ( V_57 -> V_77 ) == V_80 ) {
F_25 ( 0x49 , 0x83 , 0xFB , 0x00 ) ;
F_22 ( V_96 , 1 + 1 + 2 + 5 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_22 ( 0x31 , 0xc0 ) ;
V_72 = V_55 -> V_97 - ( V_51 [ V_65 ] - 11 ) ;
F_37 ( 0xE9 , V_72 ) ;
}
if ( F_35 ( V_57 -> V_77 ) == V_85 )
F_20 ( 0x49 , 0xF7 , 0xF3 ) ;
else
F_20 ( 0x41 , 0xF7 , 0xF3 ) ;
if ( F_34 ( V_57 -> V_77 ) == V_93 )
F_20 ( 0x49 , 0x89 , 0xD3 ) ;
else
F_20 ( 0x49 , 0x89 , 0xC3 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_36 ( V_25 , V_18 ) ;
break;
case V_78 | V_98 | V_88 :
case V_78 | V_98 | V_80 :
case V_85 | V_98 | V_88 :
case V_85 | V_98 | V_80 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
F_36 ( V_18 , V_25 ) ;
if ( F_40 ( V_57 -> V_77 ) == V_80 )
F_36 ( V_95 , V_27 ) ;
else
F_21 ( 0x48 , 0xC7 , 0xC0 , V_67 ) ;
if ( F_35 ( V_57 -> V_77 ) == V_85 )
F_19 ( F_13 ( 0x48 , V_18 ) ) ;
else if ( F_11 ( V_18 ) )
F_19 ( F_13 ( 0x40 , V_18 ) ) ;
F_22 ( 0xF7 , F_15 ( 0xE0 , V_18 ) ) ;
F_36 ( V_18 , V_95 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_36 ( V_25 , V_18 ) ;
break;
case V_78 | V_99 | V_88 :
case V_78 | V_100 | V_88 :
case V_78 | V_101 | V_88 :
case V_85 | V_99 | V_88 :
case V_85 | V_100 | V_88 :
case V_85 | V_101 | V_88 :
if ( F_35 ( V_57 -> V_77 ) == V_85 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_34 ( V_57 -> V_77 ) ) {
case V_99 : V_71 = 0xE0 ; break;
case V_100 : V_71 = 0xE8 ; break;
case V_101 : V_71 = 0xF8 ; break;
}
F_20 ( 0xC1 , F_15 ( V_71 , V_25 ) , V_67 ) ;
break;
case V_78 | V_99 | V_80 :
case V_78 | V_100 | V_80 :
case V_78 | V_101 | V_80 :
case V_85 | V_99 | V_80 :
case V_85 | V_100 | V_80 :
case V_85 | V_101 | V_80 :
if ( V_25 == V_102 ) {
F_36 ( V_18 , V_25 ) ;
V_25 = V_18 ;
}
if ( V_27 != V_102 ) {
F_19 ( 0x51 ) ;
F_36 ( V_102 , V_27 ) ;
}
if ( F_35 ( V_57 -> V_77 ) == V_85 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_34 ( V_57 -> V_77 ) ) {
case V_99 : V_71 = 0xE0 ; break;
case V_100 : V_71 = 0xE8 ; break;
case V_101 : V_71 = 0xF8 ; break;
}
F_22 ( 0xD3 , F_15 ( V_71 , V_25 ) ) ;
if ( V_27 != V_102 )
F_19 ( 0x59 ) ;
if ( V_57 -> V_25 == V_102 )
F_36 ( V_57 -> V_25 , V_18 ) ;
break;
case V_78 | V_103 | V_104 :
switch ( V_67 ) {
case 16 :
F_19 ( 0x66 ) ;
if ( F_11 ( V_25 ) )
F_19 ( 0x41 ) ;
F_20 ( 0xC1 , F_15 ( 0xC8 , V_25 ) , 8 ) ;
if ( F_11 ( V_25 ) )
F_20 ( 0x45 , 0x0F , 0xB7 ) ;
else
F_22 ( 0x0F , 0xB7 ) ;
F_19 ( F_16 ( 0xC0 , V_25 , V_25 ) ) ;
break;
case 32 :
if ( F_11 ( V_25 ) )
F_22 ( 0x41 , 0x0F ) ;
else
F_19 ( 0x0F ) ;
F_19 ( F_15 ( 0xC8 , V_25 ) ) ;
break;
case 64 :
F_20 ( F_13 ( 0x48 , V_25 ) , 0x0F ,
F_15 ( 0xC8 , V_25 ) ) ;
break;
}
break;
case V_78 | V_103 | V_105 :
switch ( V_67 ) {
case 16 :
if ( F_11 ( V_25 ) )
F_20 ( 0x45 , 0x0F , 0xB7 ) ;
else
F_22 ( 0x0F , 0xB7 ) ;
F_19 ( F_16 ( 0xC0 , V_25 , V_25 ) ) ;
break;
case 32 :
if ( F_11 ( V_25 ) )
F_19 ( 0x45 ) ;
F_22 ( 0x89 , F_16 ( 0xC0 , V_25 , V_25 ) ) ;
break;
case 64 :
break;
}
break;
case V_106 | V_107 | V_10 :
if ( F_11 ( V_25 ) )
F_22 ( 0x41 , 0xC6 ) ;
else
F_19 ( 0xC6 ) ;
goto V_108;
case V_106 | V_107 | V_9 :
if ( F_11 ( V_25 ) )
F_20 ( 0x66 , 0x41 , 0xC7 ) ;
else
F_22 ( 0x66 , 0xC7 ) ;
goto V_108;
case V_106 | V_107 | V_8 :
if ( F_11 ( V_25 ) )
F_22 ( 0x41 , 0xC7 ) ;
else
F_19 ( 0xC7 ) ;
goto V_108;
case V_106 | V_107 | V_11 :
F_22 ( F_13 ( 0x48 , V_25 ) , 0xC7 ) ;
V_108: if ( F_3 ( V_57 -> V_91 ) )
F_22 ( F_15 ( 0x40 , V_25 ) , V_57 -> V_91 ) ;
else
F_37 ( F_15 ( 0x80 , V_25 ) , V_57 -> V_91 ) ;
F_39 ( V_67 , F_5 ( F_41 ( V_57 -> V_77 ) ) ) ;
break;
case V_109 | V_107 | V_10 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) ||
V_27 == V_110 || V_27 == V_111 )
F_22 ( F_14 ( 0x40 , V_25 , V_27 ) , 0x88 ) ;
else
F_19 ( 0x88 ) ;
goto V_112;
case V_109 | V_107 | V_9 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_20 ( 0x66 , F_14 ( 0x40 , V_25 , V_27 ) , 0x89 ) ;
else
F_22 ( 0x66 , 0x89 ) ;
goto V_112;
case V_109 | V_107 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_22 ( F_14 ( 0x40 , V_25 , V_27 ) , 0x89 ) ;
else
F_19 ( 0x89 ) ;
goto V_112;
case V_109 | V_107 | V_11 :
F_22 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x89 ) ;
V_112: if ( F_3 ( V_57 -> V_91 ) )
F_22 ( F_16 ( 0x40 , V_25 , V_27 ) , V_57 -> V_91 ) ;
else
F_37 ( F_16 ( 0x80 , V_25 , V_27 ) ,
V_57 -> V_91 ) ;
break;
case V_113 | V_107 | V_10 :
F_20 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x0F , 0xB6 ) ;
goto V_114;
case V_113 | V_107 | V_9 :
F_20 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x0F , 0xB7 ) ;
goto V_114;
case V_113 | V_107 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_22 ( F_14 ( 0x40 , V_27 , V_25 ) , 0x8B ) ;
else
F_19 ( 0x8B ) ;
goto V_114;
case V_113 | V_107 | V_11 :
F_22 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x8B ) ;
V_114:
if ( F_3 ( V_57 -> V_91 ) )
F_22 ( F_16 ( 0x40 , V_27 , V_25 ) , V_57 -> V_91 ) ;
else
F_37 ( F_16 ( 0x80 , V_27 , V_25 ) ,
V_57 -> V_91 ) ;
break;
case V_109 | V_115 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_20 ( 0xF0 , F_14 ( 0x40 , V_25 , V_27 ) , 0x01 ) ;
else
F_22 ( 0xF0 , 0x01 ) ;
goto V_116;
case V_109 | V_115 | V_11 :
F_20 ( 0xF0 , F_14 ( 0x48 , V_25 , V_27 ) , 0x01 ) ;
V_116: if ( F_3 ( V_57 -> V_91 ) )
F_22 ( F_16 ( 0x40 , V_25 , V_27 ) , V_57 -> V_91 ) ;
else
F_37 ( F_16 ( 0x80 , V_25 , V_27 ) ,
V_57 -> V_91 ) ;
break;
case V_117 | V_118 :
V_76 = ( T_1 * ) V_119 + V_67 ;
V_72 = V_76 - ( V_52 + V_51 [ V_65 ] ) ;
if ( V_60 ) {
V_74 = F_42 ( V_76 ) ;
if ( V_74 ) {
F_19 ( 0x57 ) ;
V_72 += 22 ;
} else {
F_22 ( 0x41 , 0x52 ) ;
F_22 ( 0x41 , 0x51 ) ;
V_72 += 4 ;
}
}
if ( ! V_67 || ! F_4 ( V_72 ) ) {
F_38 ( L_2 ,
V_67 , V_76 , V_52 ) ;
return - V_92 ;
}
F_37 ( 0xE8 , V_72 ) ;
if ( V_60 ) {
if ( V_74 ) {
F_19 ( 0x5F ) ;
F_32 ( & V_31 ) ;
} else {
F_22 ( 0x41 , 0x59 ) ;
F_22 ( 0x41 , 0x5A ) ;
}
}
break;
case V_117 | V_118 | V_80 :
F_24 ( & V_31 ) ;
break;
case V_117 | V_120 | V_80 :
case V_117 | V_121 | V_80 :
case V_117 | V_122 | V_80 :
case V_117 | V_123 | V_80 :
case V_117 | V_124 | V_80 :
case V_117 | V_125 | V_80 :
F_20 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x39 ,
F_16 ( 0xC0 , V_25 , V_27 ) ) ;
goto V_126;
case V_117 | V_127 | V_80 :
F_20 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x85 ,
F_16 ( 0xC0 , V_25 , V_27 ) ) ;
goto V_126;
case V_117 | V_127 | V_88 :
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
F_28 ( 0xF7 , F_15 ( 0xC0 , V_25 ) , V_67 ) ;
goto V_126;
case V_117 | V_120 | V_88 :
case V_117 | V_121 | V_88 :
case V_117 | V_122 | V_88 :
case V_117 | V_123 | V_88 :
case V_117 | V_124 | V_88 :
case V_117 | V_125 | V_88 :
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
if ( F_3 ( V_67 ) )
F_20 ( 0x83 , F_15 ( 0xF8 , V_25 ) , V_67 ) ;
else
F_28 ( 0x81 , F_15 ( 0xF8 , V_25 ) , V_67 ) ;
V_126:
switch ( F_34 ( V_57 -> V_77 ) ) {
case V_120 :
V_73 = V_45 ;
break;
case V_127 :
case V_121 :
V_73 = V_96 ;
break;
case V_122 :
V_73 = V_43 ;
break;
case V_123 :
V_73 = V_128 ;
break;
case V_124 :
V_73 = V_129 ;
break;
case V_125 :
V_73 = V_130 ;
break;
default:
return - V_131 ;
}
V_72 = V_51 [ V_65 + V_57 -> V_91 ] - V_51 [ V_65 ] ;
if ( F_3 ( V_72 ) ) {
F_22 ( V_73 , V_72 ) ;
} else if ( F_4 ( V_72 ) ) {
F_28 ( 0x0F , V_73 + 0x10 , V_72 ) ;
} else {
F_38 ( L_3 , V_72 ) ;
return - V_131 ;
}
break;
case V_117 | V_132 :
V_72 = V_51 [ V_65 + V_57 -> V_91 ] - V_51 [ V_65 ] ;
if ( ! V_72 )
break;
V_133:
if ( F_3 ( V_72 ) ) {
F_22 ( 0xEB , V_72 ) ;
} else if ( F_4 ( V_72 ) ) {
F_37 ( 0xE9 , V_72 ) ;
} else {
F_38 ( L_4 , V_72 ) ;
return - V_131 ;
}
break;
case V_89 | V_134 | V_8 :
V_76 = V_135 ;
goto V_136;
case V_89 | V_137 | V_8 :
V_76 = F_43 ( V_67 , V_135 ) ;
V_136:
V_55 -> V_60 = V_60 = true ;
V_72 = V_76 - ( V_52 + V_51 [ V_65 ] ) ;
if ( ! V_76 || ! F_4 ( V_72 ) ) {
F_38 ( L_2 ,
V_67 , V_76 , V_52 ) ;
return - V_92 ;
}
if ( F_44 ( V_57 -> V_77 ) == V_137 ) {
F_37 ( 0xBE , V_67 ) ;
} else {
F_36 ( V_111 , V_27 ) ;
if ( V_67 ) {
if ( F_3 ( V_67 ) )
F_20 ( 0x83 , 0xC6 , V_67 ) ;
else
F_28 ( 0x81 , 0xC6 , V_67 ) ;
}
}
F_37 ( 0xE8 , V_72 ) ;
break;
case V_89 | V_134 | V_9 :
V_76 = V_138 ;
goto V_136;
case V_89 | V_137 | V_9 :
V_76 = F_43 ( V_67 , V_138 ) ;
goto V_136;
case V_89 | V_134 | V_10 :
V_76 = V_139 ;
goto V_136;
case V_89 | V_137 | V_10 :
V_76 = F_43 ( V_67 , V_139 ) ;
goto V_136;
case V_117 | V_140 :
if ( V_61 ) {
V_72 = V_55 -> V_97 - V_51 [ V_65 ] ;
goto V_133;
}
V_61 = true ;
V_55 -> V_97 = V_66 ;
F_21 ( 0x48 , 0x8B , 0x9D , - V_33 ) ;
F_21 ( 0x4C , 0x8B , 0xAD , - V_33 + 8 ) ;
F_21 ( 0x4C , 0x8B , 0xB5 , - V_33 + 16 ) ;
F_21 ( 0x4C , 0x8B , 0xBD , - V_33 + 24 ) ;
F_19 ( 0xC9 ) ;
F_19 ( 0xC3 ) ;
break;
default:
F_38 ( L_5 , V_57 -> V_77 ) ;
return - V_92 ;
}
V_75 = V_31 - V_62 ;
if ( V_75 > V_63 ) {
F_38 ( L_6 ) ;
return - V_131 ;
}
if ( V_52 ) {
if ( F_45 ( V_66 + V_75 > V_53 ) ) {
F_38 ( L_7 ) ;
return - V_131 ;
}
memcpy ( V_52 + V_66 , V_62 , V_75 ) ;
}
V_66 += V_75 ;
V_51 [ V_65 ] = V_66 ;
V_31 = V_62 ;
}
return V_66 ;
}
void F_46 ( struct V_46 * V_31 )
{
}
void F_47 ( struct V_46 * V_31 )
{
struct V_141 * V_142 = NULL ;
int V_66 , V_53 = 0 ;
struct V_54 V_55 = {} ;
T_1 * V_52 = NULL ;
int * V_51 ;
int V_143 ;
int V_65 ;
if ( ! V_144 )
return;
if ( ! V_31 || ! V_31 -> V_3 )
return;
V_51 = F_48 ( V_31 -> V_3 * sizeof( * V_51 ) , V_145 ) ;
if ( ! V_51 )
return;
for ( V_66 = 0 , V_65 = 0 ; V_65 < V_31 -> V_3 ; V_65 ++ ) {
V_66 += 64 ;
V_51 [ V_65 ] = V_66 ;
}
V_55 . V_97 = V_66 ;
for ( V_143 = 0 ; V_143 < 10 || V_52 ; V_143 ++ ) {
V_66 = F_33 ( V_31 , V_51 , V_52 , V_53 , & V_55 ) ;
if ( V_66 <= 0 ) {
V_52 = NULL ;
if ( V_142 )
F_49 ( V_142 ) ;
goto V_146;
}
if ( V_52 ) {
if ( V_66 != V_53 ) {
F_38 ( L_8 ,
V_66 , V_53 ) ;
goto V_146;
}
break;
}
if ( V_66 == V_53 ) {
V_142 = F_50 ( V_66 , & V_52 ,
1 , F_17 ) ;
if ( ! V_142 )
goto V_146;
}
V_53 = V_66 ;
}
if ( V_144 > 1 )
F_51 ( V_31 -> V_3 , V_66 , V_143 + 1 , V_52 ) ;
if ( V_52 ) {
F_6 ( V_142 , V_52 + V_66 ) ;
F_52 ( ( unsigned long ) V_142 , V_142 -> V_147 ) ;
V_31 -> V_47 = ( void * ) V_52 ;
V_31 -> V_148 = 1 ;
}
V_146:
F_53 ( V_51 ) ;
}
void F_54 ( struct V_46 * V_149 )
{
unsigned long V_150 = ( unsigned long ) V_149 -> V_47 & V_151 ;
struct V_141 * V_142 = ( void * ) V_150 ;
if ( ! V_149 -> V_148 )
goto V_152;
F_55 ( V_150 , V_142 -> V_147 ) ;
F_49 ( V_142 ) ;
V_152:
F_56 ( V_149 ) ;
}
