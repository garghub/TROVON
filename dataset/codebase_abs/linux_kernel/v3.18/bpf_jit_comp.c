static inline T_1 * F_1 ( T_1 * V_1 , T_2 V_2 , unsigned int V_3 )
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
static inline bool F_3 ( int V_5 )
{
return V_5 <= 127 && V_5 >= - 128 ;
}
static inline bool F_4 ( T_3 V_5 )
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
static inline void F_6 ( void * V_12 , void * V_13 )
{
T_4 V_14 = F_7 () ;
F_8 ( V_15 ) ;
F_9 () ;
F_10 ( ( unsigned long ) V_12 , ( unsigned long ) V_13 ) ;
F_8 ( V_14 ) ;
}
static inline bool F_11 ( T_2 V_16 )
{
if ( V_16 == V_17 || V_16 == V_18 ||
( V_16 >= V_19 && V_16 <= V_20 ) )
return true ;
else
return false ;
}
static inline T_1 F_12 ( T_1 V_21 , T_2 V_16 )
{
if ( F_11 ( V_16 ) )
V_21 |= 1 ;
return V_21 ;
}
static inline T_1 F_13 ( T_1 V_21 , T_2 V_22 , T_2 V_23 )
{
if ( F_11 ( V_22 ) )
V_21 |= 1 ;
if ( F_11 ( V_23 ) )
V_21 |= 4 ;
return V_21 ;
}
static inline T_1 F_14 ( T_1 V_21 , T_2 V_24 )
{
return V_21 + V_25 [ V_24 ] ;
}
static inline T_1 F_15 ( T_1 V_21 , T_2 V_24 , T_2 V_26 )
{
return V_21 + V_25 [ V_24 ] + ( V_25 [ V_26 ] << 3 ) ;
}
static void F_16 ( void * V_27 , unsigned int V_28 )
{
memset ( V_27 , 0xcc , V_28 ) ;
}
static int F_17 ( struct V_29 * V_29 , int * V_30 , T_1 * V_31 ,
int V_32 , struct V_33 * V_34 )
{
struct V_35 * V_36 = V_29 -> V_37 ;
int V_38 = V_29 -> V_3 ;
bool V_39 = V_34 -> V_39 | ( V_32 == 0 ) ;
T_1 V_40 [ V_41 + V_42 ] ;
int V_43 ;
int V_44 = 0 ;
T_1 * V_45 = V_40 ;
int V_46 = V_47 +
32 +
8 ;
F_18 ( 0x55 ) ;
F_19 ( 0x48 , 0x89 , 0xE5 ) ;
F_20 ( 0x48 , 0x81 , 0xEC , V_46 ) ;
F_20 ( 0x48 , 0x89 , 0x9D , - V_46 ) ;
F_20 ( 0x4C , 0x89 , 0xAD , - V_46 + 8 ) ;
F_20 ( 0x4C , 0x89 , 0xB5 , - V_46 + 16 ) ;
F_20 ( 0x4C , 0x89 , 0xBD , - V_46 + 24 ) ;
F_21 ( 0x31 , 0xc0 ) ;
F_19 ( 0x4D , 0x31 , 0xED ) ;
if ( V_39 ) {
if ( F_3 ( F_22 ( struct V_48 , V_3 ) ) )
F_23 ( 0x44 , 0x8b , 0x4f ,
F_22 ( struct V_48 , V_3 ) ) ;
else
F_20 ( 0x44 , 0x8b , 0x8f ,
F_22 ( struct V_48 , V_3 ) ) ;
if ( F_3 ( F_22 ( struct V_48 , V_49 ) ) )
F_23 ( 0x44 , 0x2b , 0x4f ,
F_22 ( struct V_48 , V_49 ) ) ;
else
F_20 ( 0x44 , 0x2b , 0x8f ,
F_22 ( struct V_48 , V_49 ) ) ;
if ( F_3 ( F_22 ( struct V_48 , V_50 ) ) )
F_23 ( 0x4c , 0x8b , 0x57 ,
F_22 ( struct V_48 , V_50 ) ) ;
else
F_20 ( 0x4c , 0x8b , 0x97 ,
F_22 ( struct V_48 , V_50 ) ) ;
}
for ( V_43 = 0 ; V_43 < V_38 ; V_43 ++ , V_36 ++ ) {
const V_6 V_51 = V_36 -> V_52 ;
T_2 V_24 = V_36 -> V_24 ;
T_2 V_26 = V_36 -> V_26 ;
T_1 V_53 = 0 , V_54 = 0 , V_55 = 0 ;
T_3 V_56 ;
T_1 V_57 ;
int V_58 ;
T_1 * V_59 ;
switch ( V_36 -> V_60 ) {
case V_61 | V_62 | V_63 :
case V_61 | V_64 | V_63 :
case V_61 | V_65 | V_63 :
case V_61 | V_66 | V_63 :
case V_61 | V_67 | V_63 :
case V_68 | V_62 | V_63 :
case V_68 | V_64 | V_63 :
case V_68 | V_65 | V_63 :
case V_68 | V_66 | V_63 :
case V_68 | V_67 | V_63 :
switch ( F_24 ( V_36 -> V_60 ) ) {
case V_62 : V_54 = 0x01 ; break;
case V_64 : V_54 = 0x29 ; break;
case V_65 : V_54 = 0x21 ; break;
case V_66 : V_54 = 0x09 ; break;
case V_67 : V_54 = 0x31 ; break;
}
if ( F_25 ( V_36 -> V_60 ) == V_68 )
F_18 ( F_13 ( 0x48 , V_24 , V_26 ) ) ;
else if ( F_11 ( V_24 ) || F_11 ( V_26 ) )
F_18 ( F_13 ( 0x40 , V_24 , V_26 ) ) ;
F_21 ( V_54 , F_15 ( 0xC0 , V_24 , V_26 ) ) ;
break;
case V_68 | V_69 | V_63 :
F_26 ( V_24 , V_26 ) ;
break;
case V_61 | V_69 | V_63 :
if ( F_11 ( V_24 ) || F_11 ( V_26 ) )
F_18 ( F_13 ( 0x40 , V_24 , V_26 ) ) ;
F_21 ( 0x89 , F_15 ( 0xC0 , V_24 , V_26 ) ) ;
break;
case V_61 | V_70 :
case V_68 | V_70 :
if ( F_25 ( V_36 -> V_60 ) == V_68 )
F_18 ( F_12 ( 0x48 , V_24 ) ) ;
else if ( F_11 ( V_24 ) )
F_18 ( F_12 ( 0x40 , V_24 ) ) ;
F_21 ( 0xF7 , F_14 ( 0xD8 , V_24 ) ) ;
break;
case V_61 | V_62 | V_71 :
case V_61 | V_64 | V_71 :
case V_61 | V_65 | V_71 :
case V_61 | V_66 | V_71 :
case V_61 | V_67 | V_71 :
case V_68 | V_62 | V_71 :
case V_68 | V_64 | V_71 :
case V_68 | V_65 | V_71 :
case V_68 | V_66 | V_71 :
case V_68 | V_67 | V_71 :
if ( F_25 ( V_36 -> V_60 ) == V_68 )
F_18 ( F_12 ( 0x48 , V_24 ) ) ;
else if ( F_11 ( V_24 ) )
F_18 ( F_12 ( 0x40 , V_24 ) ) ;
switch ( F_24 ( V_36 -> V_60 ) ) {
case V_62 : V_55 = 0xC0 ; break;
case V_64 : V_55 = 0xE8 ; break;
case V_65 : V_55 = 0xE0 ; break;
case V_66 : V_55 = 0xC8 ; break;
case V_67 : V_55 = 0xF0 ; break;
}
if ( F_3 ( V_51 ) )
F_19 ( 0x83 , F_14 ( V_55 , V_24 ) , V_51 ) ;
else
F_27 ( 0x81 , F_14 ( V_55 , V_24 ) , V_51 ) ;
break;
case V_68 | V_69 | V_71 :
if ( V_51 < 0 ) {
V_53 = F_12 ( 0x48 , V_24 ) ;
V_54 = 0xC7 ;
V_55 = 0xC0 ;
F_20 ( V_53 , V_54 , F_14 ( V_55 , V_24 ) , V_51 ) ;
break;
}
case V_61 | V_69 | V_71 :
if ( F_11 ( V_24 ) )
F_18 ( F_12 ( 0x40 , V_24 ) ) ;
F_28 ( F_14 ( 0xB8 , V_24 ) , V_51 ) ;
break;
case V_72 | V_73 | V_11 :
if ( V_36 [ 1 ] . V_60 != 0 || V_36 [ 1 ] . V_26 != 0 ||
V_36 [ 1 ] . V_24 != 0 || V_36 [ 1 ] . V_74 != 0 ) {
F_29 ( L_1 ) ;
return - V_75 ;
}
F_21 ( F_12 ( 0x48 , V_24 ) , F_14 ( 0xB8 , V_24 ) ) ;
F_30 ( V_36 [ 0 ] . V_52 , 4 ) ;
F_30 ( V_36 [ 1 ] . V_52 , 4 ) ;
V_36 ++ ;
V_43 ++ ;
break;
case V_61 | V_76 | V_63 :
case V_61 | V_77 | V_63 :
case V_61 | V_76 | V_71 :
case V_61 | V_77 | V_71 :
case V_68 | V_76 | V_63 :
case V_68 | V_77 | V_63 :
case V_68 | V_76 | V_71 :
case V_68 | V_77 | V_71 :
F_18 ( 0x50 ) ;
F_18 ( 0x52 ) ;
if ( F_31 ( V_36 -> V_60 ) == V_63 )
F_26 ( V_18 , V_26 ) ;
else
F_20 ( 0x49 , 0xC7 , 0xC3 , V_51 ) ;
F_26 ( V_78 , V_24 ) ;
F_21 ( 0x31 , 0xd2 ) ;
if ( F_31 ( V_36 -> V_60 ) == V_63 ) {
F_23 ( 0x49 , 0x83 , 0xFB , 0x00 ) ;
F_21 ( V_79 , 1 + 1 + 2 + 5 ) ;
F_18 ( 0x5A ) ;
F_18 ( 0x58 ) ;
F_21 ( 0x31 , 0xc0 ) ;
V_56 = V_34 -> V_80 - ( V_30 [ V_43 ] - 11 ) ;
F_28 ( 0xE9 , V_56 ) ;
}
if ( F_25 ( V_36 -> V_60 ) == V_68 )
F_19 ( 0x49 , 0xF7 , 0xF3 ) ;
else
F_19 ( 0x41 , 0xF7 , 0xF3 ) ;
if ( F_24 ( V_36 -> V_60 ) == V_76 )
F_19 ( 0x49 , 0x89 , 0xD3 ) ;
else
F_19 ( 0x49 , 0x89 , 0xC3 ) ;
F_18 ( 0x5A ) ;
F_18 ( 0x58 ) ;
F_26 ( V_24 , V_18 ) ;
break;
case V_61 | V_81 | V_71 :
case V_61 | V_81 | V_63 :
case V_68 | V_81 | V_71 :
case V_68 | V_81 | V_63 :
F_18 ( 0x50 ) ;
F_18 ( 0x52 ) ;
F_26 ( V_18 , V_24 ) ;
if ( F_31 ( V_36 -> V_60 ) == V_63 )
F_26 ( V_78 , V_26 ) ;
else
F_20 ( 0x48 , 0xC7 , 0xC0 , V_51 ) ;
if ( F_25 ( V_36 -> V_60 ) == V_68 )
F_18 ( F_12 ( 0x48 , V_18 ) ) ;
else if ( F_11 ( V_18 ) )
F_18 ( F_12 ( 0x40 , V_18 ) ) ;
F_21 ( 0xF7 , F_14 ( 0xE0 , V_18 ) ) ;
F_26 ( V_18 , V_78 ) ;
F_18 ( 0x5A ) ;
F_18 ( 0x58 ) ;
F_26 ( V_24 , V_18 ) ;
break;
case V_61 | V_82 | V_71 :
case V_61 | V_83 | V_71 :
case V_61 | V_84 | V_71 :
case V_68 | V_82 | V_71 :
case V_68 | V_83 | V_71 :
case V_68 | V_84 | V_71 :
if ( F_25 ( V_36 -> V_60 ) == V_68 )
F_18 ( F_12 ( 0x48 , V_24 ) ) ;
else if ( F_11 ( V_24 ) )
F_18 ( F_12 ( 0x40 , V_24 ) ) ;
switch ( F_24 ( V_36 -> V_60 ) ) {
case V_82 : V_55 = 0xE0 ; break;
case V_83 : V_55 = 0xE8 ; break;
case V_84 : V_55 = 0xF8 ; break;
}
F_19 ( 0xC1 , F_14 ( V_55 , V_24 ) , V_51 ) ;
break;
case V_61 | V_82 | V_63 :
case V_61 | V_83 | V_63 :
case V_61 | V_84 | V_63 :
case V_68 | V_82 | V_63 :
case V_68 | V_83 | V_63 :
case V_68 | V_84 | V_63 :
if ( V_24 == V_85 ) {
F_26 ( V_18 , V_24 ) ;
V_24 = V_18 ;
}
if ( V_26 != V_85 ) {
F_18 ( 0x51 ) ;
F_26 ( V_85 , V_26 ) ;
}
if ( F_25 ( V_36 -> V_60 ) == V_68 )
F_18 ( F_12 ( 0x48 , V_24 ) ) ;
else if ( F_11 ( V_24 ) )
F_18 ( F_12 ( 0x40 , V_24 ) ) ;
switch ( F_24 ( V_36 -> V_60 ) ) {
case V_82 : V_55 = 0xE0 ; break;
case V_83 : V_55 = 0xE8 ; break;
case V_84 : V_55 = 0xF8 ; break;
}
F_21 ( 0xD3 , F_14 ( V_55 , V_24 ) ) ;
if ( V_26 != V_85 )
F_18 ( 0x59 ) ;
if ( V_36 -> V_24 == V_85 )
F_26 ( V_36 -> V_24 , V_18 ) ;
break;
case V_61 | V_86 | V_87 :
switch ( V_51 ) {
case 16 :
F_18 ( 0x66 ) ;
if ( F_11 ( V_24 ) )
F_18 ( 0x41 ) ;
F_19 ( 0xC1 , F_14 ( 0xC8 , V_24 ) , 8 ) ;
break;
case 32 :
if ( F_11 ( V_24 ) )
F_21 ( 0x41 , 0x0F ) ;
else
F_18 ( 0x0F ) ;
F_18 ( F_14 ( 0xC8 , V_24 ) ) ;
break;
case 64 :
F_19 ( F_12 ( 0x48 , V_24 ) , 0x0F ,
F_14 ( 0xC8 , V_24 ) ) ;
break;
}
break;
case V_61 | V_86 | V_88 :
break;
case V_89 | V_90 | V_10 :
if ( F_11 ( V_24 ) )
F_21 ( 0x41 , 0xC6 ) ;
else
F_18 ( 0xC6 ) ;
goto V_91;
case V_89 | V_90 | V_9 :
if ( F_11 ( V_24 ) )
F_19 ( 0x66 , 0x41 , 0xC7 ) ;
else
F_21 ( 0x66 , 0xC7 ) ;
goto V_91;
case V_89 | V_90 | V_8 :
if ( F_11 ( V_24 ) )
F_21 ( 0x41 , 0xC7 ) ;
else
F_18 ( 0xC7 ) ;
goto V_91;
case V_89 | V_90 | V_11 :
F_21 ( F_12 ( 0x48 , V_24 ) , 0xC7 ) ;
V_91: if ( F_3 ( V_36 -> V_74 ) )
F_21 ( F_14 ( 0x40 , V_24 ) , V_36 -> V_74 ) ;
else
F_28 ( F_14 ( 0x80 , V_24 ) , V_36 -> V_74 ) ;
F_30 ( V_51 , F_5 ( F_32 ( V_36 -> V_60 ) ) ) ;
break;
case V_92 | V_90 | V_10 :
if ( F_11 ( V_24 ) || F_11 ( V_26 ) ||
V_26 == V_93 || V_26 == V_94 )
F_21 ( F_13 ( 0x40 , V_24 , V_26 ) , 0x88 ) ;
else
F_18 ( 0x88 ) ;
goto V_95;
case V_92 | V_90 | V_9 :
if ( F_11 ( V_24 ) || F_11 ( V_26 ) )
F_19 ( 0x66 , F_13 ( 0x40 , V_24 , V_26 ) , 0x89 ) ;
else
F_21 ( 0x66 , 0x89 ) ;
goto V_95;
case V_92 | V_90 | V_8 :
if ( F_11 ( V_24 ) || F_11 ( V_26 ) )
F_21 ( F_13 ( 0x40 , V_24 , V_26 ) , 0x89 ) ;
else
F_18 ( 0x89 ) ;
goto V_95;
case V_92 | V_90 | V_11 :
F_21 ( F_13 ( 0x48 , V_24 , V_26 ) , 0x89 ) ;
V_95: if ( F_3 ( V_36 -> V_74 ) )
F_21 ( F_15 ( 0x40 , V_24 , V_26 ) , V_36 -> V_74 ) ;
else
F_28 ( F_15 ( 0x80 , V_24 , V_26 ) ,
V_36 -> V_74 ) ;
break;
case V_96 | V_90 | V_10 :
F_19 ( F_13 ( 0x48 , V_26 , V_24 ) , 0x0F , 0xB6 ) ;
goto V_97;
case V_96 | V_90 | V_9 :
F_19 ( F_13 ( 0x48 , V_26 , V_24 ) , 0x0F , 0xB7 ) ;
goto V_97;
case V_96 | V_90 | V_8 :
if ( F_11 ( V_24 ) || F_11 ( V_26 ) )
F_21 ( F_13 ( 0x40 , V_26 , V_24 ) , 0x8B ) ;
else
F_18 ( 0x8B ) ;
goto V_97;
case V_96 | V_90 | V_11 :
F_21 ( F_13 ( 0x48 , V_26 , V_24 ) , 0x8B ) ;
V_97:
if ( F_3 ( V_36 -> V_74 ) )
F_21 ( F_15 ( 0x40 , V_26 , V_24 ) , V_36 -> V_74 ) ;
else
F_28 ( F_15 ( 0x80 , V_26 , V_24 ) ,
V_36 -> V_74 ) ;
break;
case V_92 | V_98 | V_8 :
if ( F_11 ( V_24 ) || F_11 ( V_26 ) )
F_19 ( 0xF0 , F_13 ( 0x40 , V_24 , V_26 ) , 0x01 ) ;
else
F_21 ( 0xF0 , 0x01 ) ;
goto V_99;
case V_92 | V_98 | V_11 :
F_19 ( 0xF0 , F_13 ( 0x48 , V_24 , V_26 ) , 0x01 ) ;
V_99: if ( F_3 ( V_36 -> V_74 ) )
F_21 ( F_15 ( 0x40 , V_24 , V_26 ) , V_36 -> V_74 ) ;
else
F_28 ( F_15 ( 0x80 , V_24 , V_26 ) ,
V_36 -> V_74 ) ;
break;
case V_100 | V_101 :
V_59 = ( T_1 * ) V_102 + V_51 ;
V_56 = V_59 - ( V_31 + V_30 [ V_43 ] ) ;
if ( V_39 ) {
F_21 ( 0x41 , 0x52 ) ;
F_21 ( 0x41 , 0x51 ) ;
V_56 += 4 ;
}
if ( ! V_51 || ! F_4 ( V_56 ) ) {
F_29 ( L_2 ,
V_51 , V_59 , V_31 ) ;
return - V_75 ;
}
F_28 ( 0xE8 , V_56 ) ;
if ( V_39 ) {
F_21 ( 0x41 , 0x59 ) ;
F_21 ( 0x41 , 0x5A ) ;
}
break;
case V_100 | V_103 | V_63 :
case V_100 | V_104 | V_63 :
case V_100 | V_105 | V_63 :
case V_100 | V_106 | V_63 :
case V_100 | V_107 | V_63 :
case V_100 | V_108 | V_63 :
F_19 ( F_13 ( 0x48 , V_24 , V_26 ) , 0x39 ,
F_15 ( 0xC0 , V_24 , V_26 ) ) ;
goto V_109;
case V_100 | V_110 | V_63 :
F_19 ( F_13 ( 0x48 , V_24 , V_26 ) , 0x85 ,
F_15 ( 0xC0 , V_24 , V_26 ) ) ;
goto V_109;
case V_100 | V_110 | V_71 :
F_18 ( F_12 ( 0x48 , V_24 ) ) ;
F_27 ( 0xF7 , F_14 ( 0xC0 , V_24 ) , V_51 ) ;
goto V_109;
case V_100 | V_103 | V_71 :
case V_100 | V_104 | V_71 :
case V_100 | V_105 | V_71 :
case V_100 | V_106 | V_71 :
case V_100 | V_107 | V_71 :
case V_100 | V_108 | V_71 :
F_18 ( F_12 ( 0x48 , V_24 ) ) ;
if ( F_3 ( V_51 ) )
F_19 ( 0x83 , F_14 ( 0xF8 , V_24 ) , V_51 ) ;
else
F_27 ( 0x81 , F_14 ( 0xF8 , V_24 ) , V_51 ) ;
V_109:
switch ( F_24 ( V_36 -> V_60 ) ) {
case V_103 :
V_57 = V_111 ;
break;
case V_110 :
case V_104 :
V_57 = V_79 ;
break;
case V_105 :
V_57 = V_112 ;
break;
case V_106 :
V_57 = V_113 ;
break;
case V_107 :
V_57 = V_114 ;
break;
case V_108 :
V_57 = V_115 ;
break;
default:
return - V_116 ;
}
V_56 = V_30 [ V_43 + V_36 -> V_74 ] - V_30 [ V_43 ] ;
if ( F_3 ( V_56 ) ) {
F_21 ( V_57 , V_56 ) ;
} else if ( F_4 ( V_56 ) ) {
F_27 ( 0x0F , V_57 + 0x10 , V_56 ) ;
} else {
F_29 ( L_3 , V_56 ) ;
return - V_116 ;
}
break;
case V_100 | V_117 :
V_56 = V_30 [ V_43 + V_36 -> V_74 ] - V_30 [ V_43 ] ;
if ( ! V_56 )
break;
V_118:
if ( F_3 ( V_56 ) ) {
F_21 ( 0xEB , V_56 ) ;
} else if ( F_4 ( V_56 ) ) {
F_28 ( 0xE9 , V_56 ) ;
} else {
F_29 ( L_4 , V_56 ) ;
return - V_116 ;
}
break;
case V_72 | V_119 | V_8 :
V_59 = V_120 ;
goto V_121;
case V_72 | V_122 | V_8 :
V_59 = F_33 ( V_51 , V_120 ) ;
V_121:
V_34 -> V_39 = V_39 = true ;
V_56 = V_59 - ( V_31 + V_30 [ V_43 ] ) ;
if ( ! V_59 || ! F_4 ( V_56 ) ) {
F_29 ( L_2 ,
V_51 , V_59 , V_31 ) ;
return - V_75 ;
}
if ( F_34 ( V_36 -> V_60 ) == V_122 ) {
F_28 ( 0xBE , V_51 ) ;
} else {
F_26 ( V_94 , V_26 ) ;
if ( V_51 ) {
if ( F_3 ( V_51 ) )
F_19 ( 0x83 , 0xC6 , V_51 ) ;
else
F_27 ( 0x81 , 0xC6 , V_51 ) ;
}
}
F_28 ( 0xE8 , V_56 ) ;
break;
case V_72 | V_119 | V_9 :
V_59 = V_123 ;
goto V_121;
case V_72 | V_122 | V_9 :
V_59 = F_33 ( V_51 , V_123 ) ;
goto V_121;
case V_72 | V_119 | V_10 :
V_59 = V_124 ;
goto V_121;
case V_72 | V_122 | V_10 :
V_59 = F_33 ( V_51 , V_124 ) ;
goto V_121;
case V_100 | V_125 :
if ( V_43 != V_38 - 1 ) {
V_56 = V_34 -> V_80 - V_30 [ V_43 ] ;
goto V_118;
}
V_34 -> V_80 = V_44 ;
F_20 ( 0x48 , 0x8B , 0x9D , - V_46 ) ;
F_20 ( 0x4C , 0x8B , 0xAD , - V_46 + 8 ) ;
F_20 ( 0x4C , 0x8B , 0xB5 , - V_46 + 16 ) ;
F_20 ( 0x4C , 0x8B , 0xBD , - V_46 + 24 ) ;
F_18 ( 0xC9 ) ;
F_18 ( 0xC3 ) ;
break;
default:
F_29 ( L_5 , V_36 -> V_60 ) ;
return - V_75 ;
}
V_58 = V_45 - V_40 ;
if ( V_58 > V_41 ) {
F_29 ( L_6 ) ;
return - V_116 ;
}
if ( V_31 ) {
if ( F_35 ( V_44 + V_58 > V_32 ) ) {
F_29 ( L_7 ) ;
return - V_116 ;
}
memcpy ( V_31 + V_44 , V_40 , V_58 ) ;
}
V_44 += V_58 ;
V_30 [ V_43 ] = V_44 ;
V_45 = V_40 ;
}
return V_44 ;
}
void F_36 ( struct V_29 * V_45 )
{
}
void F_37 ( struct V_29 * V_45 )
{
struct V_126 * V_127 = NULL ;
int V_44 , V_32 = 0 ;
struct V_33 V_34 = {} ;
T_1 * V_31 = NULL ;
int * V_30 ;
int V_128 ;
int V_43 ;
if ( ! V_129 )
return;
if ( ! V_45 || ! V_45 -> V_3 )
return;
V_30 = F_38 ( V_45 -> V_3 * sizeof( * V_30 ) , V_130 ) ;
if ( ! V_30 )
return;
for ( V_44 = 0 , V_43 = 0 ; V_43 < V_45 -> V_3 ; V_43 ++ ) {
V_44 += 64 ;
V_30 [ V_43 ] = V_44 ;
}
V_34 . V_80 = V_44 ;
for ( V_128 = 0 ; V_128 < 10 ; V_128 ++ ) {
V_44 = F_17 ( V_45 , V_30 , V_31 , V_32 , & V_34 ) ;
if ( V_44 <= 0 ) {
V_31 = NULL ;
if ( V_127 )
F_39 ( V_127 ) ;
goto V_131;
}
if ( V_31 ) {
if ( V_44 != V_32 ) {
F_29 ( L_8 ,
V_44 , V_32 ) ;
goto V_131;
}
break;
}
if ( V_44 == V_32 ) {
V_127 = F_40 ( V_44 , & V_31 ,
1 , F_16 ) ;
if ( ! V_127 )
goto V_131;
}
V_32 = V_44 ;
}
if ( V_129 > 1 )
F_41 ( V_45 -> V_3 , V_44 , 0 , V_31 ) ;
if ( V_31 ) {
F_6 ( V_127 , V_31 + V_44 ) ;
F_42 ( ( unsigned long ) V_127 , V_127 -> V_132 ) ;
V_45 -> V_133 = ( void * ) V_31 ;
V_45 -> V_134 = true ;
}
V_131:
F_43 ( V_30 ) ;
}
void F_44 ( struct V_29 * V_135 )
{
unsigned long V_136 = ( unsigned long ) V_135 -> V_133 & V_137 ;
struct V_126 * V_127 = ( void * ) V_136 ;
if ( ! V_135 -> V_134 )
goto V_138;
F_45 ( V_136 , V_127 -> V_132 ) ;
F_39 ( V_127 ) ;
V_138:
F_46 ( V_135 ) ;
}
