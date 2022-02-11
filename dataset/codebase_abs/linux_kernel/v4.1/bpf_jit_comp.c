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
static int F_18 ( struct V_30 * V_30 , int * V_31 , T_1 * V_32 ,
int V_33 , struct V_34 * V_35 )
{
struct V_36 * V_37 = V_30 -> V_38 ;
int V_39 = V_30 -> V_3 ;
bool V_40 = V_35 -> V_40 | ( V_33 == 0 ) ;
bool V_41 = false ;
T_1 V_42 [ V_43 + V_44 ] ;
int V_45 ;
int V_46 = 0 ;
T_1 * V_47 = V_42 ;
int V_48 = V_49 +
32 +
8 ;
F_19 ( 0x55 ) ;
F_20 ( 0x48 , 0x89 , 0xE5 ) ;
F_21 ( 0x48 , 0x81 , 0xEC , V_48 ) ;
F_21 ( 0x48 , 0x89 , 0x9D , - V_48 ) ;
F_21 ( 0x4C , 0x89 , 0xAD , - V_48 + 8 ) ;
F_21 ( 0x4C , 0x89 , 0xB5 , - V_48 + 16 ) ;
F_21 ( 0x4C , 0x89 , 0xBD , - V_48 + 24 ) ;
F_22 ( 0x31 , 0xc0 ) ;
F_20 ( 0x4D , 0x31 , 0xED ) ;
if ( V_40 ) {
if ( F_3 ( F_23 ( struct V_50 , V_3 ) ) )
F_24 ( 0x44 , 0x8b , 0x4f ,
F_23 ( struct V_50 , V_3 ) ) ;
else
F_21 ( 0x44 , 0x8b , 0x8f ,
F_23 ( struct V_50 , V_3 ) ) ;
if ( F_3 ( F_23 ( struct V_50 , V_51 ) ) )
F_24 ( 0x44 , 0x2b , 0x4f ,
F_23 ( struct V_50 , V_51 ) ) ;
else
F_21 ( 0x44 , 0x2b , 0x8f ,
F_23 ( struct V_50 , V_51 ) ) ;
if ( F_3 ( F_23 ( struct V_50 , V_52 ) ) )
F_24 ( 0x4c , 0x8b , 0x57 ,
F_23 ( struct V_50 , V_52 ) ) ;
else
F_21 ( 0x4c , 0x8b , 0x97 ,
F_23 ( struct V_50 , V_52 ) ) ;
}
for ( V_45 = 0 ; V_45 < V_39 ; V_45 ++ , V_37 ++ ) {
const V_6 V_53 = V_37 -> V_54 ;
T_2 V_25 = V_37 -> V_25 ;
T_2 V_27 = V_37 -> V_27 ;
T_1 V_55 = 0 , V_56 = 0 , V_57 = 0 ;
T_3 V_58 ;
T_1 V_59 ;
int V_60 ;
T_1 * V_61 ;
switch ( V_37 -> V_62 ) {
case V_63 | V_64 | V_65 :
case V_63 | V_66 | V_65 :
case V_63 | V_67 | V_65 :
case V_63 | V_68 | V_65 :
case V_63 | V_69 | V_65 :
case V_70 | V_64 | V_65 :
case V_70 | V_66 | V_65 :
case V_70 | V_67 | V_65 :
case V_70 | V_68 | V_65 :
case V_70 | V_69 | V_65 :
switch ( F_25 ( V_37 -> V_62 ) ) {
case V_64 : V_56 = 0x01 ; break;
case V_66 : V_56 = 0x29 ; break;
case V_67 : V_56 = 0x21 ; break;
case V_68 : V_56 = 0x09 ; break;
case V_69 : V_56 = 0x31 ; break;
}
if ( F_26 ( V_37 -> V_62 ) == V_70 )
F_19 ( F_14 ( 0x48 , V_25 , V_27 ) ) ;
else if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_19 ( F_14 ( 0x40 , V_25 , V_27 ) ) ;
F_22 ( V_56 , F_16 ( 0xC0 , V_25 , V_27 ) ) ;
break;
case V_70 | V_71 | V_65 :
F_27 ( V_25 , V_27 ) ;
break;
case V_63 | V_71 | V_65 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_19 ( F_14 ( 0x40 , V_25 , V_27 ) ) ;
F_22 ( 0x89 , F_16 ( 0xC0 , V_25 , V_27 ) ) ;
break;
case V_63 | V_72 :
case V_70 | V_72 :
if ( F_26 ( V_37 -> V_62 ) == V_70 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
F_22 ( 0xF7 , F_15 ( 0xD8 , V_25 ) ) ;
break;
case V_63 | V_64 | V_73 :
case V_63 | V_66 | V_73 :
case V_63 | V_67 | V_73 :
case V_63 | V_68 | V_73 :
case V_63 | V_69 | V_73 :
case V_70 | V_64 | V_73 :
case V_70 | V_66 | V_73 :
case V_70 | V_67 | V_73 :
case V_70 | V_68 | V_73 :
case V_70 | V_69 | V_73 :
if ( F_26 ( V_37 -> V_62 ) == V_70 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_25 ( V_37 -> V_62 ) ) {
case V_64 : V_57 = 0xC0 ; break;
case V_66 : V_57 = 0xE8 ; break;
case V_67 : V_57 = 0xE0 ; break;
case V_68 : V_57 = 0xC8 ; break;
case V_69 : V_57 = 0xF0 ; break;
}
if ( F_3 ( V_53 ) )
F_20 ( 0x83 , F_15 ( V_57 , V_25 ) , V_53 ) ;
else
F_28 ( 0x81 , F_15 ( V_57 , V_25 ) , V_53 ) ;
break;
case V_70 | V_71 | V_73 :
if ( V_53 < 0 ) {
V_55 = F_13 ( 0x48 , V_25 ) ;
V_56 = 0xC7 ;
V_57 = 0xC0 ;
F_21 ( V_55 , V_56 , F_15 ( V_57 , V_25 ) , V_53 ) ;
break;
}
case V_63 | V_71 | V_73 :
if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
F_29 ( F_15 ( 0xB8 , V_25 ) , V_53 ) ;
break;
case V_74 | V_75 | V_11 :
if ( V_37 [ 1 ] . V_62 != 0 || V_37 [ 1 ] . V_27 != 0 ||
V_37 [ 1 ] . V_25 != 0 || V_37 [ 1 ] . V_76 != 0 ) {
F_30 ( L_1 ) ;
return - V_77 ;
}
F_22 ( F_13 ( 0x48 , V_25 ) , F_15 ( 0xB8 , V_25 ) ) ;
F_31 ( V_37 [ 0 ] . V_54 , 4 ) ;
F_31 ( V_37 [ 1 ] . V_54 , 4 ) ;
V_37 ++ ;
V_45 ++ ;
break;
case V_63 | V_78 | V_65 :
case V_63 | V_79 | V_65 :
case V_63 | V_78 | V_73 :
case V_63 | V_79 | V_73 :
case V_70 | V_78 | V_65 :
case V_70 | V_79 | V_65 :
case V_70 | V_78 | V_73 :
case V_70 | V_79 | V_73 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
if ( F_32 ( V_37 -> V_62 ) == V_65 )
F_27 ( V_18 , V_27 ) ;
else
F_21 ( 0x49 , 0xC7 , 0xC3 , V_53 ) ;
F_27 ( V_80 , V_25 ) ;
F_22 ( 0x31 , 0xd2 ) ;
if ( F_32 ( V_37 -> V_62 ) == V_65 ) {
F_24 ( 0x49 , 0x83 , 0xFB , 0x00 ) ;
F_22 ( V_81 , 1 + 1 + 2 + 5 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_22 ( 0x31 , 0xc0 ) ;
V_58 = V_35 -> V_82 - ( V_31 [ V_45 ] - 11 ) ;
F_29 ( 0xE9 , V_58 ) ;
}
if ( F_26 ( V_37 -> V_62 ) == V_70 )
F_20 ( 0x49 , 0xF7 , 0xF3 ) ;
else
F_20 ( 0x41 , 0xF7 , 0xF3 ) ;
if ( F_25 ( V_37 -> V_62 ) == V_78 )
F_20 ( 0x49 , 0x89 , 0xD3 ) ;
else
F_20 ( 0x49 , 0x89 , 0xC3 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_27 ( V_25 , V_18 ) ;
break;
case V_63 | V_83 | V_73 :
case V_63 | V_83 | V_65 :
case V_70 | V_83 | V_73 :
case V_70 | V_83 | V_65 :
F_19 ( 0x50 ) ;
F_19 ( 0x52 ) ;
F_27 ( V_18 , V_25 ) ;
if ( F_32 ( V_37 -> V_62 ) == V_65 )
F_27 ( V_80 , V_27 ) ;
else
F_21 ( 0x48 , 0xC7 , 0xC0 , V_53 ) ;
if ( F_26 ( V_37 -> V_62 ) == V_70 )
F_19 ( F_13 ( 0x48 , V_18 ) ) ;
else if ( F_11 ( V_18 ) )
F_19 ( F_13 ( 0x40 , V_18 ) ) ;
F_22 ( 0xF7 , F_15 ( 0xE0 , V_18 ) ) ;
F_27 ( V_18 , V_80 ) ;
F_19 ( 0x5A ) ;
F_19 ( 0x58 ) ;
F_27 ( V_25 , V_18 ) ;
break;
case V_63 | V_84 | V_73 :
case V_63 | V_85 | V_73 :
case V_63 | V_86 | V_73 :
case V_70 | V_84 | V_73 :
case V_70 | V_85 | V_73 :
case V_70 | V_86 | V_73 :
if ( F_26 ( V_37 -> V_62 ) == V_70 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_25 ( V_37 -> V_62 ) ) {
case V_84 : V_57 = 0xE0 ; break;
case V_85 : V_57 = 0xE8 ; break;
case V_86 : V_57 = 0xF8 ; break;
}
F_20 ( 0xC1 , F_15 ( V_57 , V_25 ) , V_53 ) ;
break;
case V_63 | V_84 | V_65 :
case V_63 | V_85 | V_65 :
case V_63 | V_86 | V_65 :
case V_70 | V_84 | V_65 :
case V_70 | V_85 | V_65 :
case V_70 | V_86 | V_65 :
if ( V_25 == V_87 ) {
F_27 ( V_18 , V_25 ) ;
V_25 = V_18 ;
}
if ( V_27 != V_87 ) {
F_19 ( 0x51 ) ;
F_27 ( V_87 , V_27 ) ;
}
if ( F_26 ( V_37 -> V_62 ) == V_70 )
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
else if ( F_11 ( V_25 ) )
F_19 ( F_13 ( 0x40 , V_25 ) ) ;
switch ( F_25 ( V_37 -> V_62 ) ) {
case V_84 : V_57 = 0xE0 ; break;
case V_85 : V_57 = 0xE8 ; break;
case V_86 : V_57 = 0xF8 ; break;
}
F_22 ( 0xD3 , F_15 ( V_57 , V_25 ) ) ;
if ( V_27 != V_87 )
F_19 ( 0x59 ) ;
if ( V_37 -> V_25 == V_87 )
F_27 ( V_37 -> V_25 , V_18 ) ;
break;
case V_63 | V_88 | V_89 :
switch ( V_53 ) {
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
case V_63 | V_88 | V_90 :
switch ( V_53 ) {
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
case V_91 | V_92 | V_10 :
if ( F_11 ( V_25 ) )
F_22 ( 0x41 , 0xC6 ) ;
else
F_19 ( 0xC6 ) ;
goto V_93;
case V_91 | V_92 | V_9 :
if ( F_11 ( V_25 ) )
F_20 ( 0x66 , 0x41 , 0xC7 ) ;
else
F_22 ( 0x66 , 0xC7 ) ;
goto V_93;
case V_91 | V_92 | V_8 :
if ( F_11 ( V_25 ) )
F_22 ( 0x41 , 0xC7 ) ;
else
F_19 ( 0xC7 ) ;
goto V_93;
case V_91 | V_92 | V_11 :
F_22 ( F_13 ( 0x48 , V_25 ) , 0xC7 ) ;
V_93: if ( F_3 ( V_37 -> V_76 ) )
F_22 ( F_15 ( 0x40 , V_25 ) , V_37 -> V_76 ) ;
else
F_29 ( F_15 ( 0x80 , V_25 ) , V_37 -> V_76 ) ;
F_31 ( V_53 , F_5 ( F_33 ( V_37 -> V_62 ) ) ) ;
break;
case V_94 | V_92 | V_10 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) ||
V_27 == V_95 || V_27 == V_96 )
F_22 ( F_14 ( 0x40 , V_25 , V_27 ) , 0x88 ) ;
else
F_19 ( 0x88 ) ;
goto V_97;
case V_94 | V_92 | V_9 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_20 ( 0x66 , F_14 ( 0x40 , V_25 , V_27 ) , 0x89 ) ;
else
F_22 ( 0x66 , 0x89 ) ;
goto V_97;
case V_94 | V_92 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_22 ( F_14 ( 0x40 , V_25 , V_27 ) , 0x89 ) ;
else
F_19 ( 0x89 ) ;
goto V_97;
case V_94 | V_92 | V_11 :
F_22 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x89 ) ;
V_97: if ( F_3 ( V_37 -> V_76 ) )
F_22 ( F_16 ( 0x40 , V_25 , V_27 ) , V_37 -> V_76 ) ;
else
F_29 ( F_16 ( 0x80 , V_25 , V_27 ) ,
V_37 -> V_76 ) ;
break;
case V_98 | V_92 | V_10 :
F_20 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x0F , 0xB6 ) ;
goto V_99;
case V_98 | V_92 | V_9 :
F_20 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x0F , 0xB7 ) ;
goto V_99;
case V_98 | V_92 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_22 ( F_14 ( 0x40 , V_27 , V_25 ) , 0x8B ) ;
else
F_19 ( 0x8B ) ;
goto V_99;
case V_98 | V_92 | V_11 :
F_22 ( F_14 ( 0x48 , V_27 , V_25 ) , 0x8B ) ;
V_99:
if ( F_3 ( V_37 -> V_76 ) )
F_22 ( F_16 ( 0x40 , V_27 , V_25 ) , V_37 -> V_76 ) ;
else
F_29 ( F_16 ( 0x80 , V_27 , V_25 ) ,
V_37 -> V_76 ) ;
break;
case V_94 | V_100 | V_8 :
if ( F_11 ( V_25 ) || F_11 ( V_27 ) )
F_20 ( 0xF0 , F_14 ( 0x40 , V_25 , V_27 ) , 0x01 ) ;
else
F_22 ( 0xF0 , 0x01 ) ;
goto V_101;
case V_94 | V_100 | V_11 :
F_20 ( 0xF0 , F_14 ( 0x48 , V_25 , V_27 ) , 0x01 ) ;
V_101: if ( F_3 ( V_37 -> V_76 ) )
F_22 ( F_16 ( 0x40 , V_25 , V_27 ) , V_37 -> V_76 ) ;
else
F_29 ( F_16 ( 0x80 , V_25 , V_27 ) ,
V_37 -> V_76 ) ;
break;
case V_102 | V_103 :
V_61 = ( T_1 * ) V_104 + V_53 ;
V_58 = V_61 - ( V_32 + V_31 [ V_45 ] ) ;
if ( V_40 ) {
F_22 ( 0x41 , 0x52 ) ;
F_22 ( 0x41 , 0x51 ) ;
V_58 += 4 ;
}
if ( ! V_53 || ! F_4 ( V_58 ) ) {
F_30 ( L_2 ,
V_53 , V_61 , V_32 ) ;
return - V_77 ;
}
F_29 ( 0xE8 , V_58 ) ;
if ( V_40 ) {
F_22 ( 0x41 , 0x59 ) ;
F_22 ( 0x41 , 0x5A ) ;
}
break;
case V_102 | V_105 | V_65 :
case V_102 | V_106 | V_65 :
case V_102 | V_107 | V_65 :
case V_102 | V_108 | V_65 :
case V_102 | V_109 | V_65 :
case V_102 | V_110 | V_65 :
F_20 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x39 ,
F_16 ( 0xC0 , V_25 , V_27 ) ) ;
goto V_111;
case V_102 | V_112 | V_65 :
F_20 ( F_14 ( 0x48 , V_25 , V_27 ) , 0x85 ,
F_16 ( 0xC0 , V_25 , V_27 ) ) ;
goto V_111;
case V_102 | V_112 | V_73 :
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
F_28 ( 0xF7 , F_15 ( 0xC0 , V_25 ) , V_53 ) ;
goto V_111;
case V_102 | V_105 | V_73 :
case V_102 | V_106 | V_73 :
case V_102 | V_107 | V_73 :
case V_102 | V_108 | V_73 :
case V_102 | V_109 | V_73 :
case V_102 | V_110 | V_73 :
F_19 ( F_13 ( 0x48 , V_25 ) ) ;
if ( F_3 ( V_53 ) )
F_20 ( 0x83 , F_15 ( 0xF8 , V_25 ) , V_53 ) ;
else
F_28 ( 0x81 , F_15 ( 0xF8 , V_25 ) , V_53 ) ;
V_111:
switch ( F_25 ( V_37 -> V_62 ) ) {
case V_105 :
V_59 = V_113 ;
break;
case V_112 :
case V_106 :
V_59 = V_81 ;
break;
case V_107 :
V_59 = V_114 ;
break;
case V_108 :
V_59 = V_115 ;
break;
case V_109 :
V_59 = V_116 ;
break;
case V_110 :
V_59 = V_117 ;
break;
default:
return - V_118 ;
}
V_58 = V_31 [ V_45 + V_37 -> V_76 ] - V_31 [ V_45 ] ;
if ( F_3 ( V_58 ) ) {
F_22 ( V_59 , V_58 ) ;
} else if ( F_4 ( V_58 ) ) {
F_28 ( 0x0F , V_59 + 0x10 , V_58 ) ;
} else {
F_30 ( L_3 , V_58 ) ;
return - V_118 ;
}
break;
case V_102 | V_119 :
V_58 = V_31 [ V_45 + V_37 -> V_76 ] - V_31 [ V_45 ] ;
if ( ! V_58 )
break;
V_120:
if ( F_3 ( V_58 ) ) {
F_22 ( 0xEB , V_58 ) ;
} else if ( F_4 ( V_58 ) ) {
F_29 ( 0xE9 , V_58 ) ;
} else {
F_30 ( L_4 , V_58 ) ;
return - V_118 ;
}
break;
case V_74 | V_121 | V_8 :
V_61 = V_122 ;
goto V_123;
case V_74 | V_124 | V_8 :
V_61 = F_34 ( V_53 , V_122 ) ;
V_123:
V_35 -> V_40 = V_40 = true ;
V_58 = V_61 - ( V_32 + V_31 [ V_45 ] ) ;
if ( ! V_61 || ! F_4 ( V_58 ) ) {
F_30 ( L_2 ,
V_53 , V_61 , V_32 ) ;
return - V_77 ;
}
if ( F_35 ( V_37 -> V_62 ) == V_124 ) {
F_29 ( 0xBE , V_53 ) ;
} else {
F_27 ( V_96 , V_27 ) ;
if ( V_53 ) {
if ( F_3 ( V_53 ) )
F_20 ( 0x83 , 0xC6 , V_53 ) ;
else
F_28 ( 0x81 , 0xC6 , V_53 ) ;
}
}
F_29 ( 0xE8 , V_58 ) ;
break;
case V_74 | V_121 | V_9 :
V_61 = V_125 ;
goto V_123;
case V_74 | V_124 | V_9 :
V_61 = F_34 ( V_53 , V_125 ) ;
goto V_123;
case V_74 | V_121 | V_10 :
V_61 = V_126 ;
goto V_123;
case V_74 | V_124 | V_10 :
V_61 = F_34 ( V_53 , V_126 ) ;
goto V_123;
case V_102 | V_127 :
if ( V_41 ) {
V_58 = V_35 -> V_82 - V_31 [ V_45 ] ;
goto V_120;
}
V_41 = true ;
V_35 -> V_82 = V_46 ;
F_21 ( 0x48 , 0x8B , 0x9D , - V_48 ) ;
F_21 ( 0x4C , 0x8B , 0xAD , - V_48 + 8 ) ;
F_21 ( 0x4C , 0x8B , 0xB5 , - V_48 + 16 ) ;
F_21 ( 0x4C , 0x8B , 0xBD , - V_48 + 24 ) ;
F_19 ( 0xC9 ) ;
F_19 ( 0xC3 ) ;
break;
default:
F_30 ( L_5 , V_37 -> V_62 ) ;
return - V_77 ;
}
V_60 = V_47 - V_42 ;
if ( V_60 > V_43 ) {
F_30 ( L_6 ) ;
return - V_118 ;
}
if ( V_32 ) {
if ( F_36 ( V_46 + V_60 > V_33 ) ) {
F_30 ( L_7 ) ;
return - V_118 ;
}
memcpy ( V_32 + V_46 , V_42 , V_60 ) ;
}
V_46 += V_60 ;
V_31 [ V_45 ] = V_46 ;
V_47 = V_42 ;
}
return V_46 ;
}
void F_37 ( struct V_30 * V_47 )
{
}
void F_38 ( struct V_30 * V_47 )
{
struct V_128 * V_129 = NULL ;
int V_46 , V_33 = 0 ;
struct V_34 V_35 = {} ;
T_1 * V_32 = NULL ;
int * V_31 ;
int V_130 ;
int V_45 ;
if ( ! V_131 )
return;
if ( ! V_47 || ! V_47 -> V_3 )
return;
V_31 = F_39 ( V_47 -> V_3 * sizeof( * V_31 ) , V_132 ) ;
if ( ! V_31 )
return;
for ( V_46 = 0 , V_45 = 0 ; V_45 < V_47 -> V_3 ; V_45 ++ ) {
V_46 += 64 ;
V_31 [ V_45 ] = V_46 ;
}
V_35 . V_82 = V_46 ;
for ( V_130 = 0 ; V_130 < 10 || V_32 ; V_130 ++ ) {
V_46 = F_18 ( V_47 , V_31 , V_32 , V_33 , & V_35 ) ;
if ( V_46 <= 0 ) {
V_32 = NULL ;
if ( V_129 )
F_40 ( V_129 ) ;
goto V_133;
}
if ( V_32 ) {
if ( V_46 != V_33 ) {
F_30 ( L_8 ,
V_46 , V_33 ) ;
goto V_133;
}
break;
}
if ( V_46 == V_33 ) {
V_129 = F_41 ( V_46 , & V_32 ,
1 , F_17 ) ;
if ( ! V_129 )
goto V_133;
}
V_33 = V_46 ;
}
if ( V_131 > 1 )
F_42 ( V_47 -> V_3 , V_46 , 0 , V_32 ) ;
if ( V_32 ) {
F_6 ( V_129 , V_32 + V_46 ) ;
F_43 ( ( unsigned long ) V_129 , V_129 -> V_134 ) ;
V_47 -> V_135 = ( void * ) V_32 ;
V_47 -> V_136 = true ;
}
V_133:
F_44 ( V_31 ) ;
}
void F_45 ( struct V_30 * V_137 )
{
unsigned long V_138 = ( unsigned long ) V_137 -> V_135 & V_139 ;
struct V_128 * V_129 = ( void * ) V_138 ;
if ( ! V_137 -> V_136 )
goto V_140;
F_46 ( V_138 , V_129 -> V_134 ) ;
F_40 ( V_129 ) ;
V_140:
F_47 ( V_137 ) ;
}
