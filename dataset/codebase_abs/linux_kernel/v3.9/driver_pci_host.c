bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
T_1 V_6 ;
T_2 V_7 ;
V_6 = ( V_4 -> V_8 . V_9 & 0xFF00 ) ;
if ( V_6 != 0x4700 &&
V_6 != 0x5300 )
return false ;
F_2 ( V_2 -> V_5 , 0 ) ;
return ! F_3 ( V_7 , V_2 -> V_5 -> V_10 ) ;
}
static T_2 F_4 ( struct V_1 * V_2 , T_2 V_11 )
{
F_5 ( V_2 , V_12 , V_11 ) ;
F_6 ( V_2 , V_12 ) ;
return F_6 ( V_2 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_11 ,
T_2 V_14 )
{
F_5 ( V_2 , V_12 , V_11 ) ;
F_6 ( V_2 , V_12 ) ;
F_5 ( V_2 , V_13 , V_14 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 , unsigned int V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
T_2 V_18 = 0 ;
if ( V_15 >= 2 || ! ( F_9 ( V_2 , V_19 )
& V_20 ) )
goto V_21;
F_5 ( V_2 , V_22 , V_23 ) ;
V_18 = V_2 -> V_24 -> V_25 ;
V_18 |= ( V_15 << V_26 ) ;
V_18 |= ( V_16 << V_27 ) ;
V_18 |= ( V_17 & ~ 3 ) ;
V_21:
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_15 ,
unsigned int V_16 , unsigned int V_17 ,
void * V_28 , int V_29 )
{
int V_30 = - V_31 ;
T_2 V_18 , V_32 ;
void T_3 * V_33 = 0 ;
F_11 ( ! V_2 -> V_34 ) ;
if ( F_12 ( V_29 != 1 && V_29 != 2 && V_29 != 4 ) )
goto V_21;
if ( V_15 == 0 ) {
if ( V_16 > 1 )
goto V_21;
if ( V_17 >= V_35 ) {
V_18 = ( V_16 << 12 ) ;
V_18 |= ( V_17 & 0x0FFC ) ;
V_32 = F_4 ( V_2 , V_18 ) ;
} else {
V_18 = V_36 ;
V_18 |= ( V_16 << 8 ) ;
V_18 |= ( V_17 & 0xFC ) ;
V_32 = F_6 ( V_2 , V_18 ) ;
}
} else {
V_18 = F_8 ( V_2 , V_15 , V_16 , V_17 ) ;
if ( F_12 ( ! V_18 ) )
goto V_21;
V_30 = - V_37 ;
V_33 = F_13 ( V_18 , sizeof( V_32 ) ) ;
if ( ! V_33 )
goto V_21;
if ( F_3 ( V_32 , V_33 ) ) {
V_32 = 0xFFFFFFFF ;
goto V_38;
}
}
V_32 >>= ( 8 * ( V_17 & 3 ) ) ;
switch ( V_29 ) {
case 1 :
* ( ( V_39 * ) V_28 ) = ( V_39 ) V_32 ;
break;
case 2 :
* ( ( T_1 * ) V_28 ) = ( T_1 ) V_32 ;
break;
case 4 :
* ( ( T_2 * ) V_28 ) = ( T_2 ) V_32 ;
break;
}
V_30 = 0 ;
V_38:
if ( V_33 )
F_14 ( V_33 ) ;
V_21:
return V_30 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_15 ,
unsigned int V_16 , unsigned int V_17 ,
const void * V_28 , int V_29 )
{
int V_30 = - V_31 ;
T_2 V_18 , V_32 ;
void T_3 * V_33 = 0 ;
T_1 V_40 = V_2 -> V_5 -> V_4 -> V_8 . V_9 ;
F_11 ( ! V_2 -> V_34 ) ;
if ( F_12 ( V_29 != 1 && V_29 != 2 && V_29 != 4 ) )
goto V_21;
if ( V_15 == 0 ) {
if ( V_16 > 1 )
goto V_21;
if ( V_17 >= V_35 ) {
V_18 = ( V_16 << 12 ) ;
V_18 |= ( V_17 & 0x0FFC ) ;
V_32 = F_4 ( V_2 , V_18 ) ;
} else {
V_18 = V_36 ;
V_18 |= ( V_16 << 8 ) ;
V_18 |= ( V_17 & 0xFC ) ;
V_32 = F_6 ( V_2 , V_18 ) ;
}
} else {
V_18 = F_8 ( V_2 , V_15 , V_16 , V_17 ) ;
if ( F_12 ( ! V_18 ) )
goto V_21;
V_30 = - V_37 ;
V_33 = F_13 ( V_18 , sizeof( V_32 ) ) ;
if ( ! V_33 )
goto V_21;
if ( F_3 ( V_32 , V_33 ) ) {
V_32 = 0xFFFFFFFF ;
goto V_38;
}
}
switch ( V_29 ) {
case 1 :
V_32 &= ~ ( 0xFF << ( 8 * ( V_17 & 3 ) ) ) ;
V_32 |= * ( ( const V_39 * ) V_28 ) << ( 8 * ( V_17 & 3 ) ) ;
break;
case 2 :
V_32 &= ~ ( 0xFFFF << ( 8 * ( V_17 & 3 ) ) ) ;
V_32 |= * ( ( const T_1 * ) V_28 ) << ( 8 * ( V_17 & 3 ) ) ;
break;
case 4 :
V_32 = * ( ( const T_2 * ) V_28 ) ;
break;
}
if ( V_15 == 0 ) {
if ( V_17 >= V_35 )
F_7 ( V_2 , V_18 , V_32 ) ;
else
F_5 ( V_2 , V_18 , V_32 ) ;
} else {
F_16 ( V_32 , V_33 ) ;
if ( V_40 == V_41 ||
V_40 == V_42 )
F_17 ( V_33 ) ;
}
V_30 = 0 ;
V_38:
if ( V_33 )
F_14 ( V_33 ) ;
V_21:
return V_30 ;
}
static int F_18 ( struct V_43 * V_4 ,
unsigned int V_44 ,
int V_45 , int V_46 , T_2 * V_32 )
{
unsigned long V_47 ;
int V_30 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
V_49 = F_19 ( V_4 -> V_50 , struct V_48 , V_51 ) ;
V_2 = V_49 -> V_52 ;
F_20 ( & V_49 -> V_53 , V_47 ) ;
V_30 = F_10 ( V_2 , F_21 ( V_44 ) ,
F_22 ( V_44 ) , V_45 , V_32 , V_46 ) ;
F_23 ( & V_49 -> V_53 , V_47 ) ;
return V_30 ? V_54 : V_55 ;
}
static int F_24 ( struct V_43 * V_4 ,
unsigned int V_44 ,
int V_45 , int V_46 , T_2 V_32 )
{
unsigned long V_47 ;
int V_30 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
V_49 = F_19 ( V_4 -> V_50 , struct V_48 , V_51 ) ;
V_2 = V_49 -> V_52 ;
F_20 ( & V_49 -> V_53 , V_47 ) ;
V_30 = F_15 ( V_2 , F_21 ( V_44 ) ,
F_22 ( V_44 ) , V_45 , & V_32 , V_46 ) ;
F_23 ( & V_49 -> V_53 , V_47 ) ;
return V_30 ? V_54 : V_55 ;
}
static V_39 F_25 ( struct V_1 * V_2 , unsigned int V_15 ,
unsigned int V_16 , V_39 V_56 ,
unsigned char * V_28 , T_2 * V_57 )
{
V_39 V_58 ;
V_39 V_59 = 0 ;
T_2 V_60 ;
V_39 V_61 ;
F_10 ( V_2 , V_15 , V_16 , V_62 , & V_61 ,
sizeof( V_39 ) ) ;
if ( ( V_61 & 0x7F ) != V_63 )
return V_59 ;
F_10 ( V_2 , V_15 , V_16 , V_64 , & V_61 ,
sizeof( V_39 ) ) ;
if ( ! ( V_61 & V_65 ) )
return V_59 ;
F_10 ( V_2 , V_15 , V_16 , V_66 , & V_59 ,
sizeof( V_39 ) ) ;
if ( V_59 == 0x00 )
return V_59 ;
F_10 ( V_2 , V_15 , V_16 , V_59 , & V_58 , sizeof( V_39 ) ) ;
while ( V_58 != V_56 ) {
F_10 ( V_2 , V_15 , V_16 , V_59 + 1 , & V_59 ,
sizeof( V_39 ) ) ;
if ( V_59 == 0x00 )
return V_59 ;
F_10 ( V_2 , V_15 , V_16 , V_59 , & V_58 ,
sizeof( V_39 ) ) ;
}
if ( ( V_28 != NULL ) && ( V_57 != NULL ) ) {
V_39 V_67 ;
V_60 = * V_57 ;
if ( ! V_60 )
return V_59 ;
* V_57 = 0 ;
V_67 = V_59 + 2 ;
if ( ( V_60 + V_67 ) > V_35 )
V_60 = V_35 - V_67 ;
* V_57 = V_60 ;
while ( V_60 -- ) {
F_10 ( V_2 , V_15 , V_16 , V_67 , V_28 ,
sizeof( V_39 ) ) ;
V_67 ++ ;
V_28 ++ ;
}
}
return V_59 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
V_39 V_59 , V_68 , V_69 , V_15 ;
T_1 V_70 ;
int V_71 ;
V_59 = F_25 ( V_2 , 0 , 0 , V_72 , NULL ,
NULL ) ;
V_69 = V_59 + V_73 ;
F_10 ( V_2 , 0 , 0 , V_69 , & V_70 , sizeof( T_1 ) ) ;
if ( V_70 & V_74 ) {
V_68 = V_59 + V_75 ;
V_70 = V_76 ;
F_10 ( V_2 , 0 , 0 , V_68 , & V_70 ,
sizeof( T_1 ) ) ;
for ( V_15 = 1 ; V_15 < V_77 ; V_15 ++ ) {
for ( V_71 = 0 ; V_71 < 100000 ; V_71 ++ ) {
F_10 ( V_2 , V_15 , 0 ,
V_78 , & V_70 ,
sizeof( V_70 ) ) ;
if ( V_70 != 0x1 )
break;
F_27 ( 10 ) ;
}
if ( V_70 == 0x1 )
F_28 ( V_4 , L_1 ,
V_15 ) ;
}
}
}
void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_48 * V_49 ;
T_2 V_7 ;
T_2 V_79 ;
unsigned long V_80 ;
F_30 ( V_4 , L_2 ) ;
if ( V_4 -> V_81 . V_82 & V_83 ) {
F_30 ( V_4 , L_3 ) ;
return;
}
V_49 = F_31 ( sizeof( * V_49 ) , V_84 ) ;
if ( ! V_49 ) {
F_28 ( V_4 , L_4 ) ;
return;
}
F_32 ( & V_49 -> V_53 ) ;
V_2 -> V_24 = V_49 ;
V_49 -> V_85 . V_86 = & V_49 -> V_86 ;
V_49 -> V_85 . V_87 = & V_49 -> V_87 ;
V_49 -> V_85 . V_51 = & V_49 -> V_51 ;
V_49 -> V_52 = V_2 ;
V_79 = V_88 ;
V_49 -> V_25 = V_89 ;
V_49 -> V_51 . V_90 = F_18 ;
V_49 -> V_51 . V_91 = F_24 ;
V_49 -> V_87 . V_92 = L_5 ,
V_49 -> V_87 . V_93 = V_88 ;
V_49 -> V_87 . V_94 = V_88 + V_95 - 1 ;
V_49 -> V_87 . V_47 = V_96 | V_97 ;
V_49 -> V_86 . V_92 = L_6 ,
V_49 -> V_86 . V_93 = 0x100 ;
V_49 -> V_86 . V_94 = 0x7FF ;
V_49 -> V_86 . V_47 = V_98 | V_97 ;
F_33 ( 3000 , 5000 ) ;
F_5 ( V_2 , V_99 , V_100 ) ;
F_34 ( 50 ) ;
F_5 ( V_2 , V_99 , V_101 |
V_100 ) ;
if ( V_4 -> V_8 . V_9 == V_41 ||
V_4 -> V_8 . V_9 == V_42 ) {
V_49 -> V_87 . V_93 = V_102 ;
V_49 -> V_87 . V_94 = V_102 +
V_103 - 1 ;
F_5 ( V_2 , V_104 ,
V_105 | V_102 ) ;
} else if ( V_4 -> V_8 . V_9 == V_106 ) {
V_7 = V_105 ;
V_7 |= V_107 ;
V_7 |= V_108 ;
if ( V_2 -> V_5 -> V_109 == 0 ) {
V_49 -> V_87 . V_93 = V_102 ;
V_49 -> V_87 . V_94 = V_102 +
V_103 - 1 ;
V_49 -> V_86 . V_93 = 0x100 ;
V_49 -> V_86 . V_94 = 0x47F ;
V_79 = V_110 ;
F_5 ( V_2 , V_104 ,
V_7 | V_102 ) ;
} else if ( V_2 -> V_5 -> V_109 == 1 ) {
V_49 -> V_87 . V_93 = V_111 ;
V_49 -> V_87 . V_94 = V_111 +
V_103 - 1 ;
V_49 -> V_86 . V_93 = 0x480 ;
V_49 -> V_86 . V_94 = 0x7FF ;
V_79 = V_112 ;
V_49 -> V_25 = V_113 ;
F_5 ( V_2 , V_104 ,
V_7 | V_111 ) ;
}
} else
F_5 ( V_2 , V_104 ,
V_114 ) ;
F_5 ( V_2 , V_22 , V_23 ) ;
F_5 ( V_2 , V_115 ,
V_105 | V_79 ) ;
F_34 ( 100 ) ;
F_26 ( V_2 ) ;
if ( V_4 -> V_8 . V_9 == V_106 ||
V_4 -> V_8 . V_9 == V_41 ) {
T_1 V_70 ;
F_10 ( V_2 , 0 , 0 , V_116 ,
& V_70 , sizeof( V_70 ) ) ;
V_70 |= ( 2 << 5 ) ;
V_70 |= ( 2 << 12 ) ;
F_15 ( V_2 , 0 , 0 , V_116 ,
& V_70 , sizeof( V_70 ) ) ;
}
V_7 = V_117 | V_118 ;
F_15 ( V_2 , 0 , 0 , V_119 , & V_7 , sizeof( V_7 ) ) ;
F_5 ( V_2 , V_120 , V_121 ) ;
V_80 = ( unsigned long ) F_13 ( V_49 -> V_87 . V_93 ,
F_35 ( & V_49 -> V_87 ) ) ;
V_49 -> V_85 . V_80 = V_80 ;
F_36 ( V_49 -> V_85 . V_80 ) ;
F_33 ( 10000 , 15000 ) ;
F_37 ( & V_49 -> V_85 ) ;
return;
}
static void F_38 ( struct V_122 * V_15 )
{
if ( V_15 -> V_4 -> V_50 -> V_90 != F_18 ) {
return;
}
if ( F_21 ( V_15 -> V_44 ) != 0 )
return;
F_39 ( L_7 , F_40 ( V_15 ) ) ;
F_41 ( V_15 ) ;
if ( F_42 ( V_15 , ~ 0 ) < 0 ) {
F_43 ( L_8 ) ;
return;
}
F_44 ( V_15 , V_123 , 3 ) ;
}
static void F_45 ( struct V_122 * V_15 )
{
struct V_124 * V_125 ;
int V_126 , V_30 ;
if ( V_15 -> V_4 -> V_50 -> V_90 != F_18 ) {
return;
}
if ( F_21 ( V_15 -> V_44 ) == 0 )
return;
F_39 ( L_9 , F_40 ( V_15 ) ) ;
for ( V_126 = 0 ; V_126 < 6 ; V_126 ++ ) {
V_125 = & V_15 -> V_124 [ V_126 ] ;
if ( V_125 -> V_47 & ( V_98 | V_96 ) ) {
V_30 = F_46 ( V_15 , V_126 ) ;
if ( V_30 )
F_43 ( L_10 ,
F_40 ( V_15 ) ) ;
}
}
}
int F_47 ( struct V_122 * V_15 )
{
struct V_48 * V_49 ;
if ( V_15 -> V_4 -> V_50 -> V_90 != F_18 ) {
return - V_127 ;
}
V_49 = F_19 ( V_15 -> V_4 -> V_50 , struct V_48 ,
V_51 ) ;
F_39 ( L_11 , F_40 ( V_15 ) ) ;
V_15 -> V_128 = F_48 ( V_49 -> V_52 -> V_5 ) ;
F_49 ( V_15 , V_129 , V_15 -> V_128 ) ;
return 0 ;
}
int F_50 ( const struct V_122 * V_15 )
{
struct V_48 * V_49 ;
if ( V_15 -> V_4 -> V_50 -> V_90 != F_18 ) {
return - V_127 ;
}
V_49 = F_19 ( V_15 -> V_4 -> V_50 , struct V_48 ,
V_51 ) ;
return F_48 ( V_49 -> V_52 -> V_5 ) ;
}
