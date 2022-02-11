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
F_2 ( L_1 ) ;
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
V_36 = F_14 ( V_21 , V_32 ) ;
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
V_36 = F_14 ( V_21 , V_32 ) ;
if ( ! V_36 )
goto V_24;
}
} else {
V_21 = F_9 ( V_2 , V_18 , V_19 , V_20 ) ;
if ( F_13 ( ! V_21 ) )
goto V_24;
V_33 = - V_40 ;
V_36 = F_14 ( V_21 , V_32 ) ;
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
if ( V_43 == 0x4716 || V_43 == 0x4748 )
F_15 ( V_36 ) ;
}
V_33 = 0 ;
V_41:
if ( V_36 )
F_16 ( V_36 ) ;
V_24:
return V_33 ;
}
static int F_19 ( struct V_44 * V_4 ,
unsigned int V_45 ,
int V_46 , int V_47 , T_3 * V_35 )
{
unsigned long V_48 ;
int V_33 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
V_50 = F_20 ( V_4 -> V_51 , struct V_49 , V_52 ) ;
V_2 = V_50 -> V_53 ;
F_21 ( & V_50 -> V_54 , V_48 ) ;
V_33 = F_11 ( V_2 , F_22 ( V_45 ) ,
F_23 ( V_45 ) , V_46 , V_35 , V_47 ) ;
F_24 ( & V_50 -> V_54 , V_48 ) ;
return V_33 ? V_55 : V_56 ;
}
static int F_25 ( struct V_44 * V_4 ,
unsigned int V_45 ,
int V_46 , int V_47 , T_3 V_35 )
{
unsigned long V_48 ;
int V_33 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
V_50 = F_20 ( V_4 -> V_51 , struct V_49 , V_52 ) ;
V_2 = V_50 -> V_53 ;
F_21 ( & V_50 -> V_54 , V_48 ) ;
V_33 = F_17 ( V_2 , F_22 ( V_45 ) ,
F_23 ( V_45 ) , V_46 , & V_35 , V_47 ) ;
F_24 ( & V_50 -> V_54 , V_48 ) ;
return V_33 ? V_55 : V_56 ;
}
static V_42 T_1 F_26 ( struct V_1 * V_2 ,
unsigned int V_18 ,
unsigned int V_19 , V_42 V_57 ,
unsigned char * V_31 , T_3 * V_58 )
{
V_42 V_59 ;
V_42 V_60 = 0 ;
T_3 V_61 ;
V_42 V_62 ;
F_11 ( V_2 , V_18 , V_19 , V_63 , & V_62 ,
sizeof( V_42 ) ) ;
if ( ( V_62 & 0x7f ) != V_64 )
return V_60 ;
F_11 ( V_2 , V_18 , V_19 , V_65 , & V_62 ,
sizeof( V_42 ) ) ;
if ( ! ( V_62 & V_66 ) )
return V_60 ;
F_11 ( V_2 , V_18 , V_19 , V_67 , & V_60 ,
sizeof( V_42 ) ) ;
if ( V_60 == 0x00 )
return V_60 ;
F_11 ( V_2 , V_18 , V_19 , V_60 , & V_59 , sizeof( V_42 ) ) ;
while ( V_59 != V_57 ) {
F_11 ( V_2 , V_18 , V_19 , V_60 + 1 , & V_60 ,
sizeof( V_42 ) ) ;
if ( V_60 == 0x00 )
return V_60 ;
F_11 ( V_2 , V_18 , V_19 , V_60 , & V_59 ,
sizeof( V_42 ) ) ;
}
if ( ( V_31 != NULL ) && ( V_58 != NULL ) ) {
V_42 V_68 ;
V_61 = * V_58 ;
if ( ! V_61 )
return V_60 ;
* V_58 = 0 ;
V_68 = V_60 + 2 ;
if ( ( V_61 + V_68 ) > V_38 )
V_61 = V_38 - V_68 ;
* V_58 = V_61 ;
while ( V_61 -- ) {
F_11 ( V_2 , V_18 , V_19 , V_68 , V_31 ,
sizeof( V_42 ) ) ;
V_68 ++ ;
V_31 ++ ;
}
}
return V_60 ;
}
static void T_1 F_27 ( struct V_1 * V_2 )
{
V_42 V_60 , V_69 , V_70 , V_18 ;
T_2 V_71 ;
int V_72 ;
V_60 = F_26 ( V_2 , 0 , 0 , V_73 , NULL ,
NULL ) ;
V_70 = V_60 + V_74 ;
F_11 ( V_2 , 0 , 0 , V_70 , & V_71 , sizeof( T_2 ) ) ;
if ( V_71 & V_75 ) {
V_69 = V_60 + V_76 ;
V_71 = V_77 ;
F_11 ( V_2 , 0 , 0 , V_69 , & V_71 ,
sizeof( T_2 ) ) ;
for ( V_18 = 1 ; V_18 < V_78 ; V_18 ++ ) {
for ( V_72 = 0 ; V_72 < 100000 ; V_72 ++ ) {
F_11 ( V_2 , V_18 , 0 ,
V_79 , & V_71 ,
sizeof( V_71 ) ) ;
if ( V_71 != 0x1 )
break;
F_28 ( 10 ) ;
}
if ( V_71 == 0x1 )
F_29 ( L_2 , V_18 ) ;
}
}
}
void T_1 F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_49 * V_50 ;
T_3 V_7 ;
T_3 V_80 ;
unsigned long V_81 ;
F_2 ( L_3 ) ;
V_50 = F_31 ( sizeof( * V_50 ) , V_82 ) ;
if ( ! V_50 ) {
F_29 ( L_4 ) ;
return;
}
V_2 -> V_27 = V_50 ;
V_50 -> V_83 . V_84 = & V_50 -> V_84 ;
V_50 -> V_83 . V_85 = & V_50 -> V_85 ;
V_50 -> V_83 . V_52 = & V_50 -> V_52 ;
V_50 -> V_53 = V_2 ;
V_80 = V_86 ;
V_50 -> V_28 = V_87 ;
V_50 -> V_52 . V_88 = F_19 ;
V_50 -> V_52 . V_89 = F_25 ;
V_50 -> V_85 . V_90 = L_5 ,
V_50 -> V_85 . V_91 = V_86 ;
V_50 -> V_85 . V_92 = V_86 + V_93 - 1 ;
V_50 -> V_85 . V_48 = V_94 | V_95 ;
V_50 -> V_84 . V_90 = L_6 ,
V_50 -> V_84 . V_91 = 0x100 ;
V_50 -> V_84 . V_92 = 0x7FF ;
V_50 -> V_84 . V_48 = V_96 | V_95 ;
F_28 ( 3000 ) ;
F_6 ( V_2 , V_97 , V_98 ) ;
F_28 ( 1000 ) ;
F_6 ( V_2 , V_97 , V_99 |
V_98 ) ;
if ( V_4 -> V_8 . V_9 == 0x4716 || V_4 -> V_8 . V_9 == 0x4748 ) {
V_50 -> V_85 . V_91 = V_100 ;
V_50 -> V_85 . V_92 = V_100 +
V_101 - 1 ;
F_6 ( V_2 , V_102 ,
V_103 | V_100 ) ;
} else if ( V_4 -> V_8 . V_9 == 0x5300 ) {
V_7 = V_103 ;
V_7 |= V_104 ;
V_7 |= V_105 ;
if ( V_2 -> V_5 -> V_106 == 0 ) {
V_50 -> V_85 . V_91 = V_100 ;
V_50 -> V_85 . V_92 = V_100 +
V_101 - 1 ;
V_80 = V_107 ;
F_6 ( V_2 , V_102 ,
V_7 | V_100 ) ;
} else if ( V_2 -> V_5 -> V_106 == 1 ) {
V_50 -> V_85 . V_91 = V_108 ;
V_50 -> V_85 . V_92 = V_108 +
V_101 - 1 ;
V_80 = V_109 ;
V_50 -> V_28 = V_110 ;
F_6 ( V_2 , V_102 ,
V_7 | V_108 ) ;
}
} else
F_6 ( V_2 , V_102 ,
V_111 ) ;
F_6 ( V_2 , V_25 , V_26 ) ;
F_6 ( V_2 , V_112 ,
V_103 | V_80 ) ;
F_28 ( 100000 ) ;
F_27 ( V_2 ) ;
V_7 = V_113 | V_114 ;
F_17 ( V_2 , 0 , 0 , V_115 , & V_7 , sizeof( V_7 ) ) ;
F_6 ( V_2 , V_116 , V_117 ) ;
V_81 = ( unsigned long ) F_14 ( V_100 ,
0x04000000 ) ;
V_50 -> V_83 . V_81 = V_81 ;
F_32 ( V_50 -> V_83 . V_81 ) ;
F_33 ( 10 ) ;
F_34 ( & V_50 -> V_83 ) ;
return;
}
static void F_35 ( struct V_118 * V_18 )
{
if ( V_18 -> V_4 -> V_51 -> V_88 != F_19 ) {
return;
}
if ( F_22 ( V_18 -> V_45 ) != 0 )
return;
F_2 ( L_7 , F_36 ( V_18 ) ) ;
F_37 ( V_18 ) ;
if ( F_38 ( V_18 , ~ 0 ) < 0 ) {
F_29 ( L_8 ) ;
return;
}
F_39 ( V_18 , V_119 , 3 ) ;
}
static void F_40 ( struct V_118 * V_18 )
{
struct V_120 * V_121 ;
int V_122 ;
if ( V_18 -> V_4 -> V_51 -> V_88 != F_19 ) {
return;
}
if ( F_22 ( V_18 -> V_45 ) == 0 )
return;
F_2 ( L_9 , F_36 ( V_18 ) ) ;
for ( V_122 = 0 ; V_122 < 6 ; V_122 ++ ) {
V_121 = & V_18 -> V_120 [ V_122 ] ;
if ( V_121 -> V_48 & ( V_96 | V_94 ) )
F_41 ( V_18 , V_122 ) ;
}
}
int F_42 ( struct V_118 * V_18 )
{
struct V_49 * V_50 ;
if ( V_18 -> V_4 -> V_51 -> V_88 != F_19 ) {
return - V_123 ;
}
V_50 = F_20 ( V_18 -> V_4 -> V_51 , struct V_49 ,
V_52 ) ;
F_2 ( L_10 , F_36 ( V_18 ) ) ;
V_18 -> V_124 = F_43 ( V_50 -> V_53 -> V_5 ) + 2 ;
F_44 ( V_18 , V_125 , V_18 -> V_124 ) ;
return 0 ;
}
int F_45 ( const struct V_118 * V_18 )
{
struct V_49 * V_50 ;
if ( V_18 -> V_4 -> V_51 -> V_88 != F_19 ) {
return - V_123 ;
}
V_50 = F_20 ( V_18 -> V_4 -> V_51 , struct V_49 ,
V_52 ) ;
return F_43 ( V_50 -> V_53 -> V_5 ) + 2 ;
}
