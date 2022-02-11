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
F_26 ( struct V_38 , V_31 ) ) ;
F_20 ( 0x48 , 0x8B , 0x00 ) ;
F_25 ( 0x48 , 0x83 , 0xF8 , 0x00 ) ;
#define F_31 10
F_22 ( V_44 , F_31 ) ;
V_37 = V_32 ;
F_25 ( 0x48 , 0x8B , 0x40 ,
F_26 ( struct V_45 , V_46 ) ) ;
F_25 ( 0x48 , 0x83 , 0xC0 , V_34 ) ;
F_22 ( 0xFF , 0xE0 ) ;
F_23 ( V_32 - V_35 != F_27 ) ;
F_23 ( V_32 - V_36 != F_29 ) ;
F_23 ( V_32 - V_37 != F_31 ) ;
* V_30 = V_31 ;
}
static int F_32 ( struct V_45 * V_45 , int * V_47 , T_1 * V_48 ,
int V_49 , struct V_50 * V_51 )
{
struct V_52 * V_53 = V_45 -> V_54 ;
int V_55 = V_45 -> V_3 ;
bool V_56 = V_51 -> V_56 | ( V_49 == 0 ) ;
bool V_57 = false ;
T_1 V_58 [ V_59 + V_60 ] ;
int V_61 , V_32 = 0 ;
int V_62 = 0 ;
T_1 * V_31 = V_58 ;
F_18 ( & V_31 ) ;
if ( V_56 ) {
if ( F_3 ( F_26 ( struct V_63 , V_3 ) ) )
F_25 ( 0x44 , 0x8b , 0x4f ,
F_26 ( struct V_63 , V_3 ) ) ;
else
F_21 ( 0x44 , 0x8b , 0x8f ,
F_26 ( struct V_63 , V_3 ) ) ;
if ( F_3 ( F_26 ( struct V_63 , V_64 ) ) )
F_25 ( 0x44 , 0x2b , 0x4f ,
F_26 ( struct V_63 , V_64 ) ) ;
else
F_21 ( 0x44 , 0x2b , 0x8f ,
F_26 ( struct V_63 , V_64 ) ) ;
if ( F_3 ( F_26 ( struct V_63 , V_65 ) ) )
F_25 ( 0x4c , 0x8b , 0x57 ,
F_26 ( struct V_63 , V_65 ) ) ;
else
F_21 ( 0x4c , 0x8b , 0x97 ,
F_26 ( struct V_63 , V_65 ) ) ;
}
for ( V_61 = 0 ; V_61 < V_55 ; V_61 ++ , V_53 ++ ) {
const V_6 V_66 = V_53 -> V_67 ;
T_2 V_25 = V_53 -> V_25 ;
T_2 V_27 = V_53 -> V_27 ;
T_1 V_68 = 0 , V_69 = 0 , V_70 = 0 ;
T_3 V_71 ;
T_1 V_72 ;
int V_73 ;
T_1 * V_74 ;
switch ( V_53 -> V_75 ) {
case V_76 | V_77 | V_78 :
case V_76 | V_79 | V_78 :
case V_76 | V_80 | V_78 :
case V_76 | V_81 | V_78 :
case V_76 | V_82 | V_78 :
case V_83 | V_77 | V_78 :
case V_83 | V_79 | V_78 :
case V_83 | V_80 | V_78 :
case V_83 | V_81 | V_78 :
case V_83 | V_82 | V_78 :
switch ( F_33 ( V_53 -> V_75 ) ) {
case V_77 : V_69 = 0x01 ; break;
case V_79 : V_69 = 0x29 ; break;
case V_80 : V_69 = 0x21 ; break;
case V_81 : V_69 = 0x09 ; break;
case V_82 : V_69 = 0x31 ; break;
}
if ( F_34 ( V_53 -> V_75 ) == V_83 )
F_19 ( F_14 ( 0x48 , V_25 , V_27 ) ) ;
else if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_19 ( F_14 ( 0x40 , V_25 , V_27 ) ) ;
F_22 ( V_69 , F_16 ( 0xC0 , V_25 , V_27 ) ) ;
break;
case V_83 | V_84 | V_78 :
F_35 ( V_25 , V_27 ) ;
break;
case V_76 | V_84 | V_78 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_19 ( F_14 ( 0x40 , V_25 , V_27 ) ) ;
F_22 ( 0x89 , F_16 ( 0xC0 , V_25 , V_27 ) ) ;
break;
case V_76 | V_85 :
case V_83 | V_85 :
if ( F_34 ( V_53 -> V_75 ) == V_83 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
F_22 ( 0xF7 , F_15 ( 0xD8 , V_25 ) ) ;
break;
case V_76 | V_77 | V_86 :
case V_76 | V_79 | V_86 :
case V_76 | V_80 | V_86 :
case V_76 | V_81 | V_86 :
case V_76 | V_82 | V_86 :
case V_83 | V_77 | V_86 :
case V_83 | V_79 | V_86 :
case V_83 | V_80 | V_86 :
case V_83 | V_81 | V_86 :
case V_83 | V_82 | V_86 :
if ( F_34 ( V_53 -> V_75 ) == V_83 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_33 ( V_53 -> V_75 ) ) {
case V_77 : V_70 = 0xC0 ; break;
case V_79 : V_70 = 0xE8 ; break;
case V_80 : V_70 = 0xE0 ; break;
case V_81 : V_70 = 0xC8 ; break;
case V_82 : V_70 = 0xF0 ; break;
}
if ( F_3 ( V_66 ) )
F_20 ( 0x83 , F_15 ( V_70 , V_25 ) , V_66 ) ;
else
F_28 ( 0x81 , F_15 ( V_70 , V_25 ) , V_66 ) ;
break;
case V_83 | V_84 | V_86 :
if ( V_66 < 0 ) {
V_68 = F_13 ( 0x48 , V_25 ) ;
V_69 = 0xC7 ;
V_70 = 0xC0 ;
F_21 ( V_68 , V_69 , F_15 ( V_70 , V_25 ) , V_66 ) ;
break;
}
case V_76 | V_84 | V_86 :
if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
F_36 ( F_15 ( 0xB8 , V_25 ) , V_66 ) ;
break;
case V_87 | V_88 | V_11 :
if ( V_53 [ 1 ] . V_75 != 0 || V_53 [ 1 ] . V_27 != 0 ||
V_53 [ 1 ] . V_25 != 0 || V_53 [ 1 ] . V_89 != 0 ) {
F_37 ( L_1 ) ;
return - V_90 ;
}
F_22 ( F_13 ( 0x48 , V_25 ) , F_15 ( 0xB8 , V_25 ) ) ;
F_38 ( V_53 [ 0 ] . V_67 , 4 ) ;
F_38 ( V_53 [ 1 ] . V_67 , 4 ) ;
V_53 ++ ;
V_61 ++ ;
break;
case V_76 | V_91 | V_78 :
case V_76 | V_92 | V_78 :
case V_76 | V_91 | V_86 :
case V_76 | V_92 | V_86 :
case V_83 | V_91 | V_78 :
case V_83 | V_92 | V_78 :
case V_83 | V_91 | V_86 :
case V_83 | V_92 | V_86 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
if ( F_39 ( V_53 -> V_75 ) == V_78 )
F_35 ( V_18 , V_27 ) ;
else
F_21 ( 0x49 , 0xC7 , 0xC3 , V_66 ) ;
F_35 ( V_93 , V_25 ) ;
F_22 ( 0x31 , 0xd2 ) ;
if ( F_39 ( V_53 -> V_75 ) == V_78 ) {
F_25 ( 0x49 , 0x83 , 0xFB , 0x00 ) ;
F_22 ( V_94 , 1 + 1 + 2 + 5 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_22 ( 0x31 , 0xc0 ) ;
V_71 = V_51 -> V_95 - ( V_47 [ V_61 ] - 11 ) ;
F_36 ( 0xE9 , V_71 ) ;
}
if ( F_34 ( V_53 -> V_75 ) == V_83 )
F_20 ( 0x49 , 0xF7 , 0xF3 ) ;
else
F_20 ( 0x41 , 0xF7 , 0xF3 ) ;
if ( F_33 ( V_53 -> V_75 ) == V_91 )
F_20 ( 0x49 , 0x89 , 0xD3 ) ;
else
F_20 ( 0x49 , 0x89 , 0xC3 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_35 ( V_25 , V_18 ) ;
break;
case V_76 | V_96 | V_86 :
case V_76 | V_96 | V_78 :
case V_83 | V_96 | V_86 :
case V_83 | V_96 | V_78 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
F_35 ( V_18 , V_25 ) ;
if ( F_39 ( V_53 -> V_75 ) == V_78 )
F_35 ( V_93 , V_27 ) ;
else
F_21 ( 0x48 , 0xC7 , 0xC0 , V_66 ) ;
if ( F_34 ( V_53 -> V_75 ) == V_83 )
F_19 ( F_13 ( 0x48 , V_18 ) ) ;
else if ( F_11 ( V_18 ) )
F_19 ( F_13 ( 0x40 , V_18 ) ) ;
F_22 ( 0xF7 , F_15 ( 0xE0 , V_18 ) ) ;
F_35 ( V_18 , V_93 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_35 ( V_25 , V_18 ) ;
break;
case V_76 | V_97 | V_86 :
case V_76 | V_98 | V_86 :
case V_76 | V_99 | V_86 :
case V_83 | V_97 | V_86 :
case V_83 | V_98 | V_86 :
case V_83 | V_99 | V_86 :
if ( F_34 ( V_53 -> V_75 ) == V_83 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_33 ( V_53 -> V_75 ) ) {
case V_97 : V_70 = 0xE0 ; break;
case V_98 : V_70 = 0xE8 ; break;
case V_99 : V_70 = 0xF8 ; break;
}
F_20 ( 0xC1 , F_15 ( V_70 , V_25 ) , V_66 ) ;
break;
case V_76 | V_97 | V_78 :
case V_76 | V_98 | V_78 :
case V_76 | V_99 | V_78 :
case V_83 | V_97 | V_78 :
case V_83 | V_98 | V_78 :
case V_83 | V_99 | V_78 :
if ( V_25 == V_100 ) {
F_35 ( V_18 , V_25 ) ;
V_25 = V_18 ;
}
if ( V_27 != V_100 ) {
F_19 ( 0x51 ) ;
F_35 ( V_100 , V_27 ) ;
}
if ( F_34 ( V_53 -> V_75 ) == V_83 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_33 ( V_53 -> V_75 ) ) {
case V_97 : V_70 = 0xE0 ; break;
case V_98 : V_70 = 0xE8 ; break;
case V_99 : V_70 = 0xF8 ; break;
}
F_22 ( 0xD3 , F_15 ( V_70 , V_25 ) ) ;
if ( V_27 != V_100 )
F_19 ( 0x59 ) ;
if ( V_53 -> V_25 == V_100 )
F_35 ( V_53 -> V_25 , V_18 ) ;
break;
case V_76 | V_101 | V_102 :
switch ( V_66 ) {
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
case V_76 | V_101 | V_103 :
switch ( V_66 ) {
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
case V_104 | V_105 | V_10 :
if ( F_11 ( V_25 ) )
F_22 ( 0x41 , 0xC6 ) ;
else
F_19 ( 0xC6 ) ;
goto V_106;
case V_104 | V_105 | V_9 :
if ( F_11 ( V_25 ) )
F_20 ( 0x66 , 0x41 , 0xC7 ) ;
else
F_22 ( 0x66 , 0xC7 ) ;
goto V_106;
case V_104 | V_105 | V_8 :
if ( F_11 ( V_25 ) )
F_22 ( 0x41 , 0xC7 ) ;
else
F_19 ( 0xC7 ) ;
goto V_106;
case V_104 | V_105 | V_11 :
F_22 ( F_13 ( 0x48 , V_25 ) , 0xC7 ) ;
V_106: if ( F_3 ( V_53 -> V_89 ) )
F_22 ( F_15 ( 0x40 , V_25 ) , V_53 -> V_89 ) ;
else
F_36 ( F_15 ( 0x80 , V_25 ) , V_53 -> V_89 ) ;
F_38 ( V_66 , F_5 ( F_40 ( V_53 -> V_75 ) ) ) ;
break;
case V_107 | V_105 | V_10 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) ||
V_27 == V_108 || V_27 == V_109 )
F_22 ( F_14 ( 0x40 , V_25 , V_27 ) , 0x88 ) ;
else
F_19 ( 0x88 ) ;
goto V_110;
case V_107 | V_105 | V_9 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_20 ( 0x66 , F_14 ( 0x40 , V_25 , V_27 ) , 0x89 ) ;
else
F_22 ( 0x66 , 0x89 ) ;
goto V_110;
case V_107 | V_105 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_22 ( F_14 ( 0x40 , V_25 , V_27 ) , 0x89 ) ;
else
F_19 ( 0x89 ) ;
goto V_110;
case V_107 | V_105 | V_11 :
F_22 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x89 ) ;
V_110: if ( F_3 ( V_53 -> V_89 ) )
F_22 ( F_16 ( 0x40 , V_25 , V_27 ) , V_53 -> V_89 ) ;
else
F_36 ( F_16 ( 0x80 , V_25 , V_27 ) ,
V_53 -> V_89 ) ;
break;
case V_111 | V_105 | V_10 :
F_20 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x0F , 0xB6 ) ;
goto V_112;
case V_111 | V_105 | V_9 :
F_20 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x0F , 0xB7 ) ;
goto V_112;
case V_111 | V_105 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_22 ( F_14 ( 0x40 , V_27 , V_25 ) , 0x8B ) ;
else
F_19 ( 0x8B ) ;
goto V_112;
case V_111 | V_105 | V_11 :
F_22 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x8B ) ;
V_112:
if ( F_3 ( V_53 -> V_89 ) )
F_22 ( F_16 ( 0x40 , V_27 , V_25 ) , V_53 -> V_89 ) ;
else
F_36 ( F_16 ( 0x80 , V_27 , V_25 ) ,
V_53 -> V_89 ) ;
break;
case V_107 | V_113 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_20 ( 0xF0 , F_14 ( 0x40 , V_25 , V_27 ) , 0x01 ) ;
else
F_22 ( 0xF0 , 0x01 ) ;
goto V_114;
case V_107 | V_113 | V_11 :
F_20 ( 0xF0 , F_14 ( 0x48 , V_25 , V_27 ) , 0x01 ) ;
V_114: if ( F_3 ( V_53 -> V_89 ) )
F_22 ( F_16 ( 0x40 , V_25 , V_27 ) , V_53 -> V_89 ) ;
else
F_36 ( F_16 ( 0x80 , V_25 , V_27 ) ,
V_53 -> V_89 ) ;
break;
case V_115 | V_116 :
V_74 = ( T_1 * ) V_117 + V_66 ;
V_71 = V_74 - ( V_48 + V_47 [ V_61 ] ) ;
if ( V_56 ) {
F_22 ( 0x41 , 0x52 ) ;
F_22 ( 0x41 , 0x51 ) ;
V_71 += 4 ;
}
if ( ! V_66 || ! F_4 ( V_71 ) ) {
F_37 ( L_2 ,
V_66 , V_74 , V_48 ) ;
return - V_90 ;
}
F_36 ( 0xE8 , V_71 ) ;
if ( V_56 ) {
F_22 ( 0x41 , 0x59 ) ;
F_22 ( 0x41 , 0x5A ) ;
}
break;
case V_115 | V_116 | V_78 :
F_24 ( & V_31 ) ;
break;
case V_115 | V_118 | V_78 :
case V_115 | V_119 | V_78 :
case V_115 | V_120 | V_78 :
case V_115 | V_121 | V_78 :
case V_115 | V_122 | V_78 :
case V_115 | V_123 | V_78 :
F_20 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x39 ,
F_16 ( 0xC0 , V_25 , V_27 ) ) ;
goto V_124;
case V_115 | V_125 | V_78 :
F_20 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x85 ,
F_16 ( 0xC0 , V_25 , V_27 ) ) ;
goto V_124;
case V_115 | V_125 | V_86 :
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
F_28 ( 0xF7 , F_15 ( 0xC0 , V_25 ) , V_66 ) ;
goto V_124;
case V_115 | V_118 | V_86 :
case V_115 | V_119 | V_86 :
case V_115 | V_120 | V_86 :
case V_115 | V_121 | V_86 :
case V_115 | V_122 | V_86 :
case V_115 | V_123 | V_86 :
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
if ( F_3 ( V_66 ) )
F_20 ( 0x83 , F_15 ( 0xF8 , V_25 ) , V_66 ) ;
else
F_28 ( 0x81 , F_15 ( 0xF8 , V_25 ) , V_66 ) ;
V_124:
switch ( F_33 ( V_53 -> V_75 ) ) {
case V_118 :
V_72 = V_44 ;
break;
case V_125 :
case V_119 :
V_72 = V_94 ;
break;
case V_120 :
V_72 = V_43 ;
break;
case V_121 :
V_72 = V_126 ;
break;
case V_122 :
V_72 = V_127 ;
break;
case V_123 :
V_72 = V_128 ;
break;
default:
return - V_129 ;
}
V_71 = V_47 [ V_61 + V_53 -> V_89 ] - V_47 [ V_61 ] ;
if ( F_3 ( V_71 ) ) {
F_22 ( V_72 , V_71 ) ;
} else if ( F_4 ( V_71 ) ) {
F_28 ( 0x0F , V_72 + 0x10 , V_71 ) ;
} else {
F_37 ( L_3 , V_71 ) ;
return - V_129 ;
}
break;
case V_115 | V_130 :
V_71 = V_47 [ V_61 + V_53 -> V_89 ] - V_47 [ V_61 ] ;
if ( ! V_71 )
break;
V_131:
if ( F_3 ( V_71 ) ) {
F_22 ( 0xEB , V_71 ) ;
} else if ( F_4 ( V_71 ) ) {
F_36 ( 0xE9 , V_71 ) ;
} else {
F_37 ( L_4 , V_71 ) ;
return - V_129 ;
}
break;
case V_87 | V_132 | V_8 :
V_74 = V_133 ;
goto V_134;
case V_87 | V_135 | V_8 :
V_74 = F_41 ( V_66 , V_133 ) ;
V_134:
V_51 -> V_56 = V_56 = true ;
V_71 = V_74 - ( V_48 + V_47 [ V_61 ] ) ;
if ( ! V_74 || ! F_4 ( V_71 ) ) {
F_37 ( L_2 ,
V_66 , V_74 , V_48 ) ;
return - V_90 ;
}
if ( F_42 ( V_53 -> V_75 ) == V_135 ) {
F_36 ( 0xBE , V_66 ) ;
} else {
F_35 ( V_109 , V_27 ) ;
if ( V_66 ) {
if ( F_3 ( V_66 ) )
F_20 ( 0x83 , 0xC6 , V_66 ) ;
else
F_28 ( 0x81 , 0xC6 , V_66 ) ;
}
}
F_36 ( 0xE8 , V_71 ) ;
break;
case V_87 | V_132 | V_9 :
V_74 = V_136 ;
goto V_134;
case V_87 | V_135 | V_9 :
V_74 = F_41 ( V_66 , V_136 ) ;
goto V_134;
case V_87 | V_132 | V_10 :
V_74 = V_137 ;
goto V_134;
case V_87 | V_135 | V_10 :
V_74 = F_41 ( V_66 , V_137 ) ;
goto V_134;
case V_115 | V_138 :
if ( V_57 ) {
V_71 = V_51 -> V_95 - V_47 [ V_61 ] ;
goto V_131;
}
V_57 = true ;
V_51 -> V_95 = V_62 ;
F_21 ( 0x48 , 0x8B , 0x9D , - V_33 ) ;
F_21 ( 0x4C , 0x8B , 0xAD , - V_33 + 8 ) ;
F_21 ( 0x4C , 0x8B , 0xB5 , - V_33 + 16 ) ;
F_21 ( 0x4C , 0x8B , 0xBD , - V_33 + 24 ) ;
F_19 ( 0xC9 ) ;
F_19 ( 0xC3 ) ;
break;
default:
F_37 ( L_5 , V_53 -> V_75 ) ;
return - V_90 ;
}
V_73 = V_31 - V_58 ;
if ( V_73 > V_59 ) {
F_37 ( L_6 ) ;
return - V_129 ;
}
if ( V_48 ) {
if ( F_43 ( V_62 + V_73 > V_49 ) ) {
F_37 ( L_7 ) ;
return - V_129 ;
}
memcpy ( V_48 + V_62 , V_58 , V_73 ) ;
}
V_62 += V_73 ;
V_47 [ V_61 ] = V_62 ;
V_31 = V_58 ;
}
return V_62 ;
}
void F_44 ( struct V_45 * V_31 )
{
}
void F_45 ( struct V_45 * V_31 )
{
struct V_139 * V_140 = NULL ;
int V_62 , V_49 = 0 ;
struct V_50 V_51 = {} ;
T_1 * V_48 = NULL ;
int * V_47 ;
int V_141 ;
int V_61 ;
if ( ! V_142 )
return;
if ( ! V_31 || ! V_31 -> V_3 )
return;
V_47 = F_46 ( V_31 -> V_3 * sizeof( * V_47 ) , V_143 ) ;
if ( ! V_47 )
return;
for ( V_62 = 0 , V_61 = 0 ; V_61 < V_31 -> V_3 ; V_61 ++ ) {
V_62 += 64 ;
V_47 [ V_61 ] = V_62 ;
}
V_51 . V_95 = V_62 ;
for ( V_141 = 0 ; V_141 < 10 || V_48 ; V_141 ++ ) {
V_62 = F_32 ( V_31 , V_47 , V_48 , V_49 , & V_51 ) ;
if ( V_62 <= 0 ) {
V_48 = NULL ;
if ( V_140 )
F_47 ( V_140 ) ;
goto V_144;
}
if ( V_48 ) {
if ( V_62 != V_49 ) {
F_37 ( L_8 ,
V_62 , V_49 ) ;
goto V_144;
}
break;
}
if ( V_62 == V_49 ) {
V_140 = F_48 ( V_62 , & V_48 ,
1 , F_17 ) ;
if ( ! V_140 )
goto V_144;
}
V_49 = V_62 ;
}
if ( V_142 > 1 )
F_49 ( V_31 -> V_3 , V_62 , 0 , V_48 ) ;
if ( V_48 ) {
F_6 ( V_140 , V_48 + V_62 ) ;
F_50 ( ( unsigned long ) V_140 , V_140 -> V_145 ) ;
V_31 -> V_46 = ( void * ) V_48 ;
V_31 -> V_146 = true ;
}
V_144:
F_51 ( V_47 ) ;
}
void F_52 ( struct V_45 * V_147 )
{
unsigned long V_148 = ( unsigned long ) V_147 -> V_46 & V_149 ;
struct V_139 * V_140 = ( void * ) V_148 ;
if ( ! V_147 -> V_146 )
goto V_150;
F_53 ( V_148 , V_140 -> V_145 ) ;
F_47 ( V_140 ) ;
V_150:
F_54 ( V_147 ) ;
}
