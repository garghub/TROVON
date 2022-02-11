bool T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
T_2 V_6 ;
T_3 V_7 ;
V_6 = ( V_4 -> V_8 . V_9 & 0xFF00 ) ;
if ( V_6 != 0x4700 &&
V_6 != 0x5300 )
return false ;
if ( V_4 -> V_10 . V_11 & V_12 ) {
F_2 ( V_4 , L_1 ) ;
return false ;
}
F_3 ( V_2 -> V_5 , 0 ) ;
return ! F_4 ( V_7 , V_2 -> V_5 -> V_13 ) ;
}
static T_3 F_5 ( struct V_1 * V_2 , T_3 V_14 )
{
F_6 ( V_2 , V_15 , V_14 ) ;
F_7 ( V_2 , V_15 ) ;
return F_7 ( V_2 , V_16 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_3 V_14 ,
T_3 V_17 )
{
F_6 ( V_2 , V_15 , V_14 ) ;
F_7 ( V_2 , V_15 ) ;
F_6 ( V_2 , V_16 , V_17 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 , unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 )
{
T_3 V_21 = 0 ;
if ( V_18 >= 2 || ! ( F_10 ( V_2 , V_22 )
& V_23 ) )
goto V_24;
F_6 ( V_2 , V_25 , V_26 ) ;
V_21 = V_2 -> V_27 -> V_28 ;
V_21 |= ( V_18 << V_29 ) ;
V_21 |= ( V_19 << V_30 ) ;
V_21 |= ( V_20 & ~ 3 ) ;
V_24:
return V_21 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 ,
void * V_31 , int V_32 )
{
int V_33 = - V_34 ;
T_3 V_21 , V_35 ;
void T_4 * V_36 = 0 ;
F_12 ( ! V_2 -> V_37 ) ;
if ( F_13 ( V_32 != 1 && V_32 != 2 && V_32 != 4 ) )
goto V_24;
if ( V_18 == 0 ) {
if ( V_19 > 1 )
return - V_34 ;
if ( V_20 >= V_38 ) {
V_21 = ( V_19 << 12 ) ;
V_21 |= ( V_20 & 0x0FFF ) ;
V_35 = F_5 ( V_2 , V_21 ) ;
} else {
V_21 = V_39 ;
V_21 |= ( V_19 << 8 ) ;
V_21 |= ( V_20 & 0xfc ) ;
V_35 = F_7 ( V_2 , V_21 ) ;
}
} else {
V_21 = F_9 ( V_2 , V_18 , V_19 , V_20 ) ;
if ( F_13 ( ! V_21 ) )
goto V_24;
V_33 = - V_40 ;
V_36 = F_14 ( V_21 , sizeof( V_35 ) ) ;
if ( ! V_36 )
goto V_24;
if ( F_4 ( V_35 , V_36 ) ) {
V_35 = 0xffffffff ;
goto V_41;
}
V_35 = F_15 ( V_36 ) ;
}
V_35 >>= ( 8 * ( V_20 & 3 ) ) ;
switch ( V_32 ) {
case 1 :
* ( ( V_42 * ) V_31 ) = ( V_42 ) V_35 ;
break;
case 2 :
* ( ( T_2 * ) V_31 ) = ( T_2 ) V_35 ;
break;
case 4 :
* ( ( T_3 * ) V_31 ) = ( T_3 ) V_35 ;
break;
}
V_33 = 0 ;
V_41:
if ( V_36 )
F_16 ( V_36 ) ;
V_24:
return V_33 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 ,
const void * V_31 , int V_32 )
{
int V_33 = - V_34 ;
T_3 V_21 = 0 , V_35 = 0 ;
void T_4 * V_36 = 0 ;
T_2 V_43 = V_2 -> V_5 -> V_4 -> V_8 . V_9 ;
F_12 ( ! V_2 -> V_37 ) ;
if ( F_13 ( V_32 != 1 && V_32 != 2 && V_32 != 4 ) )
goto V_24;
if ( V_18 == 0 ) {
if ( V_20 < V_38 ) {
V_21 = V_2 -> V_5 -> V_21 + V_39 ;
V_21 |= ( V_19 << 8 ) ;
V_21 |= ( V_20 & 0xfc ) ;
V_36 = F_14 ( V_21 , sizeof( V_35 ) ) ;
if ( ! V_36 )
goto V_24;
}
} else {
V_21 = F_9 ( V_2 , V_18 , V_19 , V_20 ) ;
if ( F_13 ( ! V_21 ) )
goto V_24;
V_33 = - V_40 ;
V_36 = F_14 ( V_21 , sizeof( V_35 ) ) ;
if ( ! V_36 )
goto V_24;
if ( F_4 ( V_35 , V_36 ) ) {
V_35 = 0xffffffff ;
goto V_41;
}
}
switch ( V_32 ) {
case 1 :
V_35 = F_15 ( V_36 ) ;
V_35 &= ~ ( 0xFF << ( 8 * ( V_20 & 3 ) ) ) ;
V_35 |= * ( ( const V_42 * ) V_31 ) << ( 8 * ( V_20 & 3 ) ) ;
break;
case 2 :
V_35 = F_15 ( V_36 ) ;
V_35 &= ~ ( 0xFFFF << ( 8 * ( V_20 & 3 ) ) ) ;
V_35 |= * ( ( const T_2 * ) V_31 ) << ( 8 * ( V_20 & 3 ) ) ;
break;
case 4 :
V_35 = * ( ( const T_3 * ) V_31 ) ;
break;
}
if ( V_18 == 0 && ! V_21 ) {
V_21 = ( V_19 << 12 ) ;
V_21 |= ( V_20 & 0x0FFF ) ;
F_8 ( V_2 , V_21 , V_35 ) ;
} else {
F_18 ( V_35 , V_36 ) ;
if ( V_43 == V_44 ||
V_43 == V_45 )
F_15 ( V_36 ) ;
}
V_33 = 0 ;
V_41:
if ( V_36 )
F_16 ( V_36 ) ;
V_24:
return V_33 ;
}
static int F_19 ( struct V_46 * V_4 ,
unsigned int V_47 ,
int V_48 , int V_49 , T_3 * V_35 )
{
unsigned long V_50 ;
int V_33 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
V_52 = F_20 ( V_4 -> V_53 , struct V_51 , V_54 ) ;
V_2 = V_52 -> V_55 ;
F_21 ( & V_52 -> V_56 , V_50 ) ;
V_33 = F_11 ( V_2 , F_22 ( V_47 ) ,
F_23 ( V_47 ) , V_48 , V_35 , V_49 ) ;
F_24 ( & V_52 -> V_56 , V_50 ) ;
return V_33 ? V_57 : V_58 ;
}
static int F_25 ( struct V_46 * V_4 ,
unsigned int V_47 ,
int V_48 , int V_49 , T_3 V_35 )
{
unsigned long V_50 ;
int V_33 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
V_52 = F_20 ( V_4 -> V_53 , struct V_51 , V_54 ) ;
V_2 = V_52 -> V_55 ;
F_21 ( & V_52 -> V_56 , V_50 ) ;
V_33 = F_17 ( V_2 , F_22 ( V_47 ) ,
F_23 ( V_47 ) , V_48 , & V_35 , V_49 ) ;
F_24 ( & V_52 -> V_56 , V_50 ) ;
return V_33 ? V_57 : V_58 ;
}
static V_42 T_1 F_26 ( struct V_1 * V_2 ,
unsigned int V_18 ,
unsigned int V_19 , V_42 V_59 ,
unsigned char * V_31 , T_3 * V_60 )
{
V_42 V_61 ;
V_42 V_62 = 0 ;
T_3 V_63 ;
V_42 V_64 ;
F_11 ( V_2 , V_18 , V_19 , V_65 , & V_64 ,
sizeof( V_42 ) ) ;
if ( ( V_64 & 0x7f ) != V_66 )
return V_62 ;
F_11 ( V_2 , V_18 , V_19 , V_67 , & V_64 ,
sizeof( V_42 ) ) ;
if ( ! ( V_64 & V_68 ) )
return V_62 ;
F_11 ( V_2 , V_18 , V_19 , V_69 , & V_62 ,
sizeof( V_42 ) ) ;
if ( V_62 == 0x00 )
return V_62 ;
F_11 ( V_2 , V_18 , V_19 , V_62 , & V_61 , sizeof( V_42 ) ) ;
while ( V_61 != V_59 ) {
F_11 ( V_2 , V_18 , V_19 , V_62 + 1 , & V_62 ,
sizeof( V_42 ) ) ;
if ( V_62 == 0x00 )
return V_62 ;
F_11 ( V_2 , V_18 , V_19 , V_62 , & V_61 ,
sizeof( V_42 ) ) ;
}
if ( ( V_31 != NULL ) && ( V_60 != NULL ) ) {
V_42 V_70 ;
V_63 = * V_60 ;
if ( ! V_63 )
return V_62 ;
* V_60 = 0 ;
V_70 = V_62 + 2 ;
if ( ( V_63 + V_70 ) > V_38 )
V_63 = V_38 - V_70 ;
* V_60 = V_63 ;
while ( V_63 -- ) {
F_11 ( V_2 , V_18 , V_19 , V_70 , V_31 ,
sizeof( V_42 ) ) ;
V_70 ++ ;
V_31 ++ ;
}
}
return V_62 ;
}
static void T_1 F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
V_42 V_62 , V_71 , V_72 , V_18 ;
T_2 V_73 ;
int V_74 ;
V_62 = F_26 ( V_2 , 0 , 0 , V_75 , NULL ,
NULL ) ;
V_72 = V_62 + V_76 ;
F_11 ( V_2 , 0 , 0 , V_72 , & V_73 , sizeof( T_2 ) ) ;
if ( V_73 & V_77 ) {
V_71 = V_62 + V_78 ;
V_73 = V_79 ;
F_11 ( V_2 , 0 , 0 , V_71 , & V_73 ,
sizeof( T_2 ) ) ;
for ( V_18 = 1 ; V_18 < V_80 ; V_18 ++ ) {
for ( V_74 = 0 ; V_74 < 100000 ; V_74 ++ ) {
F_11 ( V_2 , V_18 , 0 ,
V_81 , & V_73 ,
sizeof( V_73 ) ) ;
if ( V_73 != 0x1 )
break;
F_28 ( 10 ) ;
}
if ( V_73 == 0x1 )
F_29 ( V_4 , L_2 ,
V_18 ) ;
}
}
}
void T_1 F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_51 * V_52 ;
T_3 V_7 ;
T_3 V_82 ;
unsigned long V_83 ;
F_2 ( V_4 , L_3 ) ;
V_52 = F_31 ( sizeof( * V_52 ) , V_84 ) ;
if ( ! V_52 ) {
F_29 ( V_4 , L_4 ) ;
return;
}
V_2 -> V_27 = V_52 ;
V_52 -> V_85 . V_86 = & V_52 -> V_86 ;
V_52 -> V_85 . V_87 = & V_52 -> V_87 ;
V_52 -> V_85 . V_54 = & V_52 -> V_54 ;
V_52 -> V_55 = V_2 ;
V_82 = V_88 ;
V_52 -> V_28 = V_89 ;
V_52 -> V_54 . V_90 = F_19 ;
V_52 -> V_54 . V_91 = F_25 ;
V_52 -> V_87 . V_92 = L_5 ,
V_52 -> V_87 . V_93 = V_88 ;
V_52 -> V_87 . V_94 = V_88 + V_95 - 1 ;
V_52 -> V_87 . V_50 = V_96 | V_97 ;
V_52 -> V_86 . V_92 = L_6 ,
V_52 -> V_86 . V_93 = 0x100 ;
V_52 -> V_86 . V_94 = 0x7FF ;
V_52 -> V_86 . V_50 = V_98 | V_97 ;
F_28 ( 3000 ) ;
F_6 ( V_2 , V_99 , V_100 ) ;
F_28 ( 1000 ) ;
F_6 ( V_2 , V_99 , V_101 |
V_100 ) ;
if ( V_4 -> V_8 . V_9 == V_44 ||
V_4 -> V_8 . V_9 == V_45 ) {
V_52 -> V_87 . V_93 = V_102 ;
V_52 -> V_87 . V_94 = V_102 +
V_103 - 1 ;
F_6 ( V_2 , V_104 ,
V_105 | V_102 ) ;
} else if ( V_4 -> V_8 . V_9 == V_106 ) {
V_7 = V_105 ;
V_7 |= V_107 ;
V_7 |= V_108 ;
if ( V_2 -> V_5 -> V_109 == 0 ) {
V_52 -> V_87 . V_93 = V_102 ;
V_52 -> V_87 . V_94 = V_102 +
V_103 - 1 ;
V_82 = V_110 ;
F_6 ( V_2 , V_104 ,
V_7 | V_102 ) ;
} else if ( V_2 -> V_5 -> V_109 == 1 ) {
V_52 -> V_87 . V_93 = V_111 ;
V_52 -> V_87 . V_94 = V_111 +
V_103 - 1 ;
V_82 = V_112 ;
V_52 -> V_28 = V_113 ;
F_6 ( V_2 , V_104 ,
V_7 | V_111 ) ;
}
} else
F_6 ( V_2 , V_104 ,
V_114 ) ;
F_6 ( V_2 , V_25 , V_26 ) ;
F_6 ( V_2 , V_115 ,
V_105 | V_82 ) ;
F_28 ( 100000 ) ;
F_27 ( V_2 ) ;
V_7 = V_116 | V_117 ;
F_17 ( V_2 , 0 , 0 , V_118 , & V_7 , sizeof( V_7 ) ) ;
F_6 ( V_2 , V_119 , V_120 ) ;
V_83 = ( unsigned long ) F_14 ( V_52 -> V_87 . V_93 ,
F_32 ( & V_52 -> V_87 ) ) ;
V_52 -> V_85 . V_83 = V_83 ;
F_33 ( V_52 -> V_85 . V_83 ) ;
F_34 ( 10 ) ;
F_35 ( & V_52 -> V_85 ) ;
return;
}
static void F_36 ( struct V_121 * V_18 )
{
if ( V_18 -> V_4 -> V_53 -> V_90 != F_19 ) {
return;
}
if ( F_22 ( V_18 -> V_47 ) != 0 )
return;
F_37 ( L_7 , F_38 ( V_18 ) ) ;
F_39 ( V_18 ) ;
if ( F_40 ( V_18 , ~ 0 ) < 0 ) {
F_41 ( L_8 ) ;
return;
}
F_42 ( V_18 , V_122 , 3 ) ;
}
static void F_43 ( struct V_121 * V_18 )
{
struct V_123 * V_124 ;
int V_125 ;
if ( V_18 -> V_4 -> V_53 -> V_90 != F_19 ) {
return;
}
if ( F_22 ( V_18 -> V_47 ) == 0 )
return;
F_37 ( L_9 , F_38 ( V_18 ) ) ;
for ( V_125 = 0 ; V_125 < 6 ; V_125 ++ ) {
V_124 = & V_18 -> V_123 [ V_125 ] ;
if ( V_124 -> V_50 & ( V_98 | V_96 ) )
F_44 ( V_18 , V_125 ) ;
}
}
int F_45 ( struct V_121 * V_18 )
{
struct V_51 * V_52 ;
if ( V_18 -> V_4 -> V_53 -> V_90 != F_19 ) {
return - V_126 ;
}
V_52 = F_20 ( V_18 -> V_4 -> V_53 , struct V_51 ,
V_54 ) ;
F_37 ( L_10 , F_38 ( V_18 ) ) ;
V_18 -> V_127 = F_46 ( V_52 -> V_55 -> V_5 ) + 2 ;
F_47 ( V_18 , V_128 , V_18 -> V_127 ) ;
return 0 ;
}
int F_48 ( const struct V_121 * V_18 )
{
struct V_51 * V_52 ;
if ( V_18 -> V_4 -> V_53 -> V_90 != F_19 ) {
return - V_126 ;
}
V_52 = F_20 ( V_18 -> V_4 -> V_53 , struct V_51 ,
V_54 ) ;
return F_46 ( V_52 -> V_55 -> V_5 ) + 2 ;
}
