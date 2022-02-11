static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_2 * V_6 , T_1 V_7 , T_2 V_8 )
{
T_1 V_9 = F_1 ( V_2 , V_7 ) ;
memcpy ( V_6 , & V_9 , ( V_8 & 3 ) + 1 ) ;
}
static void
F_6 ( struct V_1 * V_2 , const T_2 * V_6 , T_1 V_7 , T_2 V_8 )
{
T_1 V_9 = 0 ;
memcpy ( & V_9 , V_6 , ( V_8 & 3 ) + 1 ) ;
F_3 ( V_2 , V_7 , V_9 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_1 V_12 = 0 ;
T_1 V_13 = V_14 ;
T_1 V_3 = F_9 ( V_2 -> V_15 ) ;
while ( V_13 -- ) {
V_12 = F_1 ( V_2 , V_3 ) ;
if ( V_12 & V_16 ) {
if ( V_12 & V_17 ) {
F_10 ( & V_11 -> V_2 ,
L_1 ,
V_18 , V_12 ) ;
return - V_19 ;
}
if ( V_12 & V_20 ) {
F_10 ( & V_11 -> V_2 ,
L_2 ,
V_18 , V_12 ) ;
return - V_21 ;
}
if ( V_12 & V_22 ) {
F_10 ( & V_11 -> V_2 ,
L_3 ,
V_18 , V_12 ) ;
return - V_21 ;
}
return 0 ;
}
F_11 ( 1 ) ;
}
F_10 ( & V_11 -> V_2 ,
L_4 ,
V_18 , V_12 ) ;
return - V_23 ;
}
static int F_12 ( struct V_10 * V_11 , T_2 V_24 , T_2 V_25 )
{
struct V_1 * V_26 = F_8 ( V_11 ) ;
unsigned long V_27 ;
T_1 V_28 ;
int V_29 ;
if ( V_24 < V_30 || V_24 > V_31 )
return - V_32 ;
V_28 = ( ( V_24 | 0x40 ) << 27 ) | ( ( V_25 & 0xf ) << 20 ) ;
F_13 ( & V_26 -> V_33 , V_27 ) ;
F_3 ( V_26 , F_14 ( V_26 -> V_15 ) , V_28 ) ;
V_29 = F_7 ( V_11 ) ;
F_15 ( & V_26 -> V_33 , V_27 ) ;
return V_29 ;
}
static int F_16 ( struct V_10 * V_11 , T_2 V_24 , T_2 V_25 ,
T_3 V_34 , T_2 * V_6 , T_4 V_35 )
{
struct V_1 * V_26 = F_8 ( V_11 ) ;
unsigned long V_27 ;
T_2 V_8 = V_35 - 1 ;
T_1 V_28 ;
int V_29 ;
if ( V_8 >= V_36 ) {
F_10 ( & V_11 -> V_2 ,
L_5 ,
V_36 , V_35 ) ;
return - V_32 ;
}
if ( V_24 >= 0x60 && V_24 <= 0x7F )
V_24 = V_37 ;
else if ( V_24 >= 0x20 && V_24 <= 0x2F )
V_24 = V_38 ;
else if ( V_24 >= 0x38 && V_24 <= 0x3F )
V_24 = V_39 ;
else
return - V_32 ;
V_28 = ( V_24 << 27 ) | ( ( V_25 & 0xf ) << 20 ) | ( V_34 << 4 ) | ( V_8 & 0x7 ) ;
F_13 ( & V_26 -> V_33 , V_27 ) ;
F_3 ( V_26 , F_14 ( V_26 -> V_15 ) , V_28 ) ;
V_29 = F_7 ( V_11 ) ;
if ( V_29 )
goto V_40;
F_5 ( V_26 , V_6 , F_17 ( V_26 -> V_15 ) ,
F_18 ( T_2 , V_8 , 3 ) ) ;
if ( V_8 > 3 )
F_5 ( V_26 , V_6 + 4 ,
F_19 ( V_26 -> V_15 ) , V_8 - 4 ) ;
V_40:
F_15 ( & V_26 -> V_33 , V_27 ) ;
return V_29 ;
}
static int F_20 ( struct V_10 * V_11 , T_2 V_24 , T_2 V_25 ,
T_3 V_34 , const T_2 * V_6 , T_4 V_35 )
{
struct V_1 * V_26 = F_8 ( V_11 ) ;
unsigned long V_27 ;
T_2 V_8 = V_35 - 1 ;
T_1 V_28 ;
int V_29 ;
if ( V_8 >= V_36 ) {
F_10 ( & V_11 -> V_2 ,
L_6 ,
V_36 , V_35 ) ;
return - V_32 ;
}
if ( V_24 >= 0x40 && V_24 <= 0x5F )
V_24 = V_41 ;
else if ( V_24 >= 0x00 && V_24 <= 0x0F )
V_24 = V_42 ;
else if ( V_24 >= 0x30 && V_24 <= 0x37 )
V_24 = V_43 ;
else if ( V_24 >= 0x80 && V_24 <= 0xFF )
V_24 = V_44 ;
else
return - V_32 ;
V_28 = ( V_24 << 27 ) | ( ( V_25 & 0xf ) << 20 ) | ( V_34 << 4 ) | ( V_8 & 0x7 ) ;
F_13 ( & V_26 -> V_33 , V_27 ) ;
F_6 ( V_26 , V_6 , F_21 ( V_26 -> V_15 )
, F_18 ( T_2 , V_8 , 3 ) ) ;
if ( V_8 > 3 )
F_6 ( V_26 , V_6 + 4 ,
F_22 ( V_26 -> V_15 ) , V_8 - 4 ) ;
F_3 ( V_26 , F_14 ( V_26 -> V_15 ) , V_28 ) ;
V_29 = F_7 ( V_11 ) ;
F_15 ( & V_26 -> V_33 , V_27 ) ;
return V_29 ;
}
static void F_23 ( struct V_45 * V_46 , T_2 V_7 , void * V_6 ,
T_4 V_35 )
{
struct V_1 * V_47 = F_24 ( V_46 ) ;
T_2 V_25 = V_46 -> V_48 >> 24 ;
T_2 V_49 = V_46 -> V_48 >> 16 ;
if ( F_20 ( V_47 -> V_50 , V_51 , V_25 ,
( V_49 << 8 ) + V_7 , V_6 , V_35 ) )
F_25 ( & V_47 -> V_50 -> V_2 ,
L_7 ,
V_46 -> V_52 ) ;
}
static void F_26 ( struct V_45 * V_46 , T_2 V_7 , void * V_6 , T_4 V_35 )
{
struct V_1 * V_47 = F_24 ( V_46 ) ;
T_2 V_25 = V_46 -> V_48 >> 24 ;
T_2 V_49 = V_46 -> V_48 >> 16 ;
if ( F_16 ( V_47 -> V_50 , V_53 , V_25 ,
( V_49 << 8 ) + V_7 , V_6 , V_35 ) )
F_25 ( & V_47 -> V_50 -> V_2 ,
L_7 ,
V_46 -> V_52 ) ;
}
static void F_27 ( struct V_1 * V_47 , T_2 V_54 )
{
unsigned int V_52 ;
T_1 V_12 ;
int V_55 ;
V_12 = F_2 ( V_47 -> V_56 + F_28 ( V_54 ) ) ;
while ( V_12 ) {
V_55 = F_29 ( V_12 ) - 1 ;
V_12 &= ~ ( 1 << V_55 ) ;
V_52 = F_30 ( V_47 -> V_57 ,
V_47 -> V_58 [ V_54 ] << 16
| V_55 << 8
| V_54 ) ;
F_31 ( V_52 ) ;
}
}
static void F_32 ( unsigned int V_52 , struct V_59 * V_60 )
{
struct V_1 * V_47 = F_33 ( V_52 ) ;
struct V_61 * V_62 = F_34 ( V_52 ) ;
void T_5 * V_56 = V_47 -> V_56 ;
int V_63 = V_47 -> V_64 >> 5 ;
int V_65 = V_47 -> V_66 >> 5 ;
T_1 V_12 ;
int V_67 , V_55 ;
F_35 ( V_62 , V_60 ) ;
for ( V_67 = V_63 ; V_67 <= V_65 ; ++ V_67 ) {
V_12 = F_2 ( V_56 +
F_36 ( V_47 -> V_68 , V_67 ) ) ;
while ( V_12 ) {
V_55 = F_29 ( V_12 ) - 1 ;
V_12 &= ~ ( 1 << V_55 ) ;
F_27 ( V_47 , V_55 + V_67 * 32 ) ;
}
}
F_37 ( V_62 , V_60 ) ;
}
static void F_38 ( struct V_45 * V_46 )
{
struct V_1 * V_47 = F_24 ( V_46 ) ;
T_2 V_52 = V_46 -> V_48 >> 8 ;
T_2 V_54 = V_46 -> V_48 ;
unsigned long V_27 ;
T_2 V_9 ;
F_13 ( & V_47 -> V_33 , V_27 ) ;
F_4 ( 1 << V_52 , V_47 -> V_56 + F_39 ( V_54 ) ) ;
F_15 ( & V_47 -> V_33 , V_27 ) ;
V_9 = 1 << V_52 ;
F_23 ( V_46 , V_69 , & V_9 , 1 ) ;
}
static void F_40 ( struct V_45 * V_46 )
{
struct V_1 * V_47 = F_24 ( V_46 ) ;
T_2 V_52 = V_46 -> V_48 >> 8 ;
T_2 V_54 = V_46 -> V_48 ;
unsigned long V_27 ;
T_1 V_12 ;
T_2 V_9 ;
F_13 ( & V_47 -> V_33 , V_27 ) ;
V_12 = F_2 ( V_47 -> V_56 + F_41 ( V_54 ) ) ;
if ( V_12 & V_70 ) {
V_12 = V_12 & ~ V_70 ;
F_4 ( V_12 , V_47 -> V_56 + F_41 ( V_54 ) ) ;
}
F_15 ( & V_47 -> V_33 , V_27 ) ;
V_9 = 1 << V_52 ;
F_23 ( V_46 , V_71 , & V_9 , 1 ) ;
}
static void F_42 ( struct V_45 * V_46 )
{
struct V_1 * V_47 = F_24 ( V_46 ) ;
T_2 V_52 = V_46 -> V_48 >> 8 ;
T_2 V_54 = V_46 -> V_48 ;
unsigned long V_27 ;
T_1 V_12 ;
T_2 V_9 ;
F_13 ( & V_47 -> V_33 , V_27 ) ;
V_12 = F_2 ( V_47 -> V_56 + F_41 ( V_54 ) ) ;
if ( ! ( V_12 & V_70 ) ) {
F_4 ( V_12 | V_70 ,
V_47 -> V_56 + F_41 ( V_54 ) ) ;
}
F_15 ( & V_47 -> V_33 , V_27 ) ;
V_9 = 1 << V_52 ;
F_23 ( V_46 , V_72 , & V_9 , 1 ) ;
}
static void F_43 ( struct V_45 * V_46 )
{
T_2 V_52 = V_46 -> V_48 >> 8 ;
T_2 V_9 ;
F_42 ( V_46 ) ;
V_9 = 1 << V_52 ;
F_23 ( V_46 , V_69 , & V_9 , 1 ) ;
}
static int F_44 ( struct V_45 * V_46 , unsigned int V_73 )
{
struct V_74 type ;
T_2 V_52 = V_46 -> V_48 >> 8 ;
F_26 ( V_46 , V_75 , & type , sizeof( type ) ) ;
if ( V_73 & ( V_76 | V_77 ) ) {
type . type |= 1 << V_52 ;
if ( V_73 & V_76 )
type . V_78 |= 1 << V_52 ;
if ( V_73 & V_77 )
type . V_79 |= 1 << V_52 ;
} else {
if ( ( V_73 & ( V_80 ) ) &&
( V_73 & ( V_81 ) ) )
return - V_32 ;
type . type &= ~ ( 1 << V_52 ) ;
if ( V_73 & V_80 )
type . V_78 |= 1 << V_52 ;
else
type . V_79 |= 1 << V_52 ;
}
F_23 ( V_46 , V_75 , & type , sizeof( type ) ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_47 ,
struct V_82 * V_83 ,
T_2 * V_54 )
{
T_3 V_84 = V_83 -> V_85 << 8 | V_83 -> V_49 ;
T_1 * V_86 = V_47 -> V_86 ;
int V_87 = 0 , V_67 ;
T_1 V_9 ;
for ( V_67 = 0 ; V_67 < V_88 ; ++ V_67 ) {
V_9 = V_86 [ V_87 ] ;
if ( V_84 & ( 1 << F_46 ( V_9 ) ) ) {
if ( F_47 ( V_9 ) ) {
V_87 = F_48 ( V_9 ) ;
} else {
* V_54 = F_48 ( V_9 ) ;
return 0 ;
}
} else {
if ( F_49 ( V_9 ) ) {
V_87 = F_50 ( V_9 ) ;
} else {
* V_54 = F_50 ( V_9 ) ;
return 0 ;
}
}
}
return - V_89 ;
}
static int F_51 ( struct V_90 * V_46 ,
struct V_91 * V_92 ,
const T_1 * V_93 ,
unsigned int V_94 ,
unsigned long * V_95 ,
unsigned int * V_96 )
{
struct V_1 * V_47 = V_46 -> V_97 ;
struct V_82 V_83 ;
int V_98 ;
T_2 V_54 ;
F_52 ( & V_47 -> V_50 -> V_2 ,
L_8 ,
V_93 [ 0 ] , V_93 [ 1 ] , V_93 [ 2 ] ) ;
if ( V_46 -> V_99 != V_92 )
return - V_32 ;
if ( V_94 != 4 )
return - V_32 ;
if ( V_93 [ 0 ] > 0xF || V_93 [ 1 ] > 0xFF || V_93 [ 2 ] > 0x7 )
return - V_32 ;
V_83 . V_85 = V_93 [ 0 ] ;
V_83 . V_49 = V_93 [ 1 ] ;
V_83 . V_52 = V_93 [ 2 ] ;
V_98 = F_45 ( V_47 , & V_83 , & V_54 ) ;
if ( V_98 )
return V_98 ;
V_47 -> V_58 [ V_54 ] = V_83 . V_85 << 8 | V_83 . V_49 ;
if ( V_54 > V_47 -> V_66 )
V_47 -> V_66 = V_54 ;
if ( V_54 < V_47 -> V_64 )
V_47 -> V_64 = V_54 ;
* V_95 = V_83 . V_85 << 24
| V_83 . V_49 << 16
| V_83 . V_52 << 8
| V_54 ;
* V_96 = V_93 [ 3 ] & V_100 ;
F_52 ( & V_47 -> V_50 -> V_2 , L_9 , * V_95 ) ;
return 0 ;
}
static int F_53 ( struct V_90 * V_46 ,
unsigned int V_101 ,
T_6 V_48 )
{
struct V_1 * V_47 = V_46 -> V_97 ;
F_52 ( & V_47 -> V_50 -> V_2 , L_10 , V_101 , V_48 ) ;
F_54 ( V_101 , & V_102 , V_103 ) ;
F_55 ( V_101 , V_46 -> V_97 ) ;
F_56 ( V_101 ) ;
return 0 ;
}
static int F_57 ( struct V_104 * V_105 )
{
struct V_1 * V_47 ;
struct V_10 * V_11 ;
struct V_106 * V_107 ;
T_1 V_15 , V_68 ;
int V_98 , V_67 ;
V_11 = F_58 ( & V_105 -> V_2 , sizeof( * V_47 ) ) ;
if ( ! V_11 )
return - V_108 ;
V_47 = F_8 ( V_11 ) ;
V_47 -> V_50 = V_11 ;
V_107 = F_59 ( V_105 , V_109 , L_11 ) ;
V_47 -> V_4 = F_60 ( & V_11 -> V_2 , V_107 ) ;
if ( F_61 ( V_47 -> V_4 ) ) {
V_98 = F_62 ( V_47 -> V_4 ) ;
goto V_110;
}
V_107 = F_59 ( V_105 , V_109 , L_12 ) ;
V_47 -> V_56 = F_60 ( & V_11 -> V_2 , V_107 ) ;
if ( F_61 ( V_47 -> V_56 ) ) {
V_98 = F_62 ( V_47 -> V_56 ) ;
goto V_110;
}
V_107 = F_59 ( V_105 , V_109 , L_13 ) ;
V_47 -> V_111 = F_60 ( & V_11 -> V_2 , V_107 ) ;
if ( F_61 ( V_47 -> V_111 ) ) {
V_98 = F_62 ( V_47 -> V_111 ) ;
goto V_110;
}
V_47 -> V_52 = F_63 ( V_105 , L_14 ) ;
if ( V_47 -> V_52 < 0 ) {
V_98 = V_47 -> V_52 ;
goto V_110;
}
V_98 = F_64 ( V_105 -> V_2 . V_99 , L_15 , & V_15 ) ;
if ( V_98 ) {
F_10 ( & V_105 -> V_2 , L_16 ) ;
goto V_110;
}
if ( V_15 > 5 ) {
F_10 ( & V_105 -> V_2 , L_17 ,
V_15 ) ;
goto V_110;
}
V_47 -> V_15 = V_15 ;
V_98 = F_64 ( V_105 -> V_2 . V_99 , L_18 , & V_68 ) ;
if ( V_98 ) {
F_10 ( & V_105 -> V_2 , L_19 ) ;
goto V_110;
}
if ( V_68 > 5 ) {
F_10 ( & V_105 -> V_2 , L_20 , V_68 ) ;
V_98 = - V_32 ;
goto V_110;
}
V_47 -> V_68 = V_68 ;
for ( V_67 = 0 ; V_67 < F_65 ( V_47 -> V_86 ) ; ++ V_67 )
V_47 -> V_86 [ V_67 ] = F_2 (
V_47 -> V_111 + F_66 ( V_67 ) ) ;
V_47 -> V_66 = 0 ;
V_47 -> V_64 = V_112 - 1 ;
F_67 ( V_105 , V_11 ) ;
F_68 ( & V_47 -> V_33 ) ;
V_11 -> V_28 = F_12 ;
V_11 -> V_113 = F_16 ;
V_11 -> V_114 = F_20 ;
F_52 ( & V_105 -> V_2 , L_21 ) ;
V_47 -> V_57 = F_69 ( V_105 -> V_2 . V_99 ,
& V_115 , V_47 ) ;
if ( ! V_47 -> V_57 ) {
F_10 ( & V_105 -> V_2 , L_22 ) ;
V_98 = - V_108 ;
goto V_110;
}
F_70 ( V_47 -> V_52 , V_47 ) ;
F_71 ( V_47 -> V_52 , F_32 ) ;
V_98 = F_72 ( V_11 ) ;
if ( V_98 )
goto V_116;
F_52 ( & V_11 -> V_2 , L_23 ,
F_1 ( V_47 , V_117 ) ) ;
return 0 ;
V_116:
F_71 ( V_47 -> V_52 , NULL ) ;
F_70 ( V_47 -> V_52 , NULL ) ;
F_73 ( V_47 -> V_57 ) ;
V_110:
F_74 ( V_11 ) ;
return V_98 ;
}
static int F_75 ( struct V_104 * V_105 )
{
struct V_10 * V_11 = F_76 ( V_105 ) ;
struct V_1 * V_47 = F_8 ( V_11 ) ;
F_77 ( V_11 ) ;
F_71 ( V_47 -> V_52 , NULL ) ;
F_70 ( V_47 -> V_52 , NULL ) ;
F_73 ( V_47 -> V_57 ) ;
F_74 ( V_11 ) ;
return 0 ;
}
