static int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 [ V_3 ] ;
static const T_1 V_4 [ V_3 ] = { 0x00 , 0x00 , 0x10 , 0x00 ,
0x80 , 0xc0 , 0xc0 , 0xf8 ,
0xe0 , 0x00 , 0x00 , 0x40 ,
0x40 , 0x78 , 0x00 , 0x00 ,
0xf8 , 0x00 , 0x88 , 0x00 } ;
int V_5 , V_6 ;
V_5 = F_2 ( V_1 , 0 , V_2 , V_3 ) ;
if ( V_5 )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_3 ; ++ V_6 ) {
if ( V_2 [ V_6 ] & V_4 [ V_6 ] )
return - V_7 ;
}
return 0 ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_5 ;
V_5 = F_5 ( V_11 -> V_1 , V_12 ,
V_13 , 0 ) ;
if ( V_5 )
F_6 ( V_9 , L_1 , V_14 , V_5 ) ;
return V_5 ;
}
static int F_7 ( struct V_8 * V_9 , bool V_15 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_5 ;
V_5 = F_5 ( V_11 -> V_1 , V_16 ,
V_17 ,
V_15 ? V_17 : 0 ) ;
if ( V_5 )
F_6 ( V_9 , L_2 ,
V_14 , V_5 ) ;
return V_5 ;
}
static int F_8 ( struct V_8 * V_9 , bool V_15 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_5 ;
V_5 = F_5 ( V_11 -> V_1 , V_12 ,
V_18 ,
V_15 ? V_18 : 0 ) ;
if ( V_5 )
F_6 ( V_9 , L_3 ,
V_14 , V_5 ) ;
return V_5 ;
}
static int F_9 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_2 [ V_21 + V_22 ] ;
int V_5 ;
V_5 = F_2 ( V_11 -> V_1 , V_16 , V_2 ,
sizeof( V_2 ) ) ;
if ( V_5 ) {
F_6 ( V_9 , L_4 ,
V_14 , V_5 ) ;
goto V_23;
}
if ( V_2 [ V_21 ] & V_24 ) {
V_5 = - V_25 ;
goto V_23;
}
V_20 -> V_26 = F_10 ( V_2 [ V_21 ] & 0x7F ) ;
V_20 -> V_27 = F_10 ( V_2 [ V_28 ] ) ;
if ( V_2 [ V_16 ] & V_29 ) {
V_20 -> V_30 = F_10 ( V_2 [ V_31 ] & 0x1f ) ;
if ( V_2 [ V_31 ] & V_32 )
V_20 -> V_30 += 12 ;
} else {
V_20 -> V_30 = F_10 ( V_2 [ V_31 ] ) ;
}
V_20 -> V_33 = F_10 ( V_2 [ V_34 ] ) ;
V_20 -> V_35 = F_10 ( V_2 [ V_36 ] ) ;
V_20 -> V_37 = F_10 ( V_2 [ V_38 ] ) - 1 ;
V_20 -> V_39 = F_10 ( V_2 [ V_40 ] ) + 100 ;
V_5 = F_11 ( V_20 ) ;
V_23:
return V_5 ;
}
static int F_12 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_2 [ V_21 + V_22 ] ;
int V_5 ;
if ( V_20 -> V_39 < 100 )
return - V_41 ;
V_2 [ V_21 ] = F_13 ( V_20 -> V_26 ) ;
V_2 [ V_28 ] = F_13 ( V_20 -> V_27 ) ;
V_2 [ V_31 ] = F_13 ( V_20 -> V_30 ) ;
V_2 [ V_34 ] = F_13 ( V_20 -> V_33 ) ;
V_2 [ V_36 ] = F_13 ( V_20 -> V_35 ) ;
V_2 [ V_38 ] = F_13 ( V_20 -> V_37 + 1 ) ;
V_2 [ V_40 ] = F_13 ( V_20 -> V_39 - 100 ) ;
F_14 ( & V_11 -> V_42 ) ;
V_5 = F_15 ( V_11 -> V_1 , V_21 ,
V_2 + V_21 ,
V_22 ) ;
F_16 ( & V_11 -> V_42 ) ;
return V_5 ;
}
static inline void F_17 ( T_1 V_43 , T_1 * V_44 , T_1 * V_45 )
{
* V_44 = V_46 ;
* V_45 = V_43 ;
}
static inline int F_18 ( T_1 * V_43 , T_1 V_44 , T_1 V_45 )
{
if ( V_44 != V_46 )
return - V_41 ;
* V_43 = V_45 ;
return 0 ;
}
static int F_19 ( struct V_8 * V_9 ,
struct V_47 * V_48 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_19 V_49 , * V_50 = & V_48 -> time ;
T_1 V_2 [ V_51 + 1 ] ;
unsigned long V_52 ;
unsigned int V_53 ;
T_1 V_54 ;
int V_5 ;
V_5 = F_2 ( V_11 -> V_1 , V_55 , V_2 ,
V_51 + 1 ) ;
if ( V_5 ) {
F_6 ( V_9 , L_5 ,
V_14 , V_5 ) ;
goto V_23;
}
V_5 = F_9 ( V_9 , & V_49 ) ;
if ( V_5 )
goto V_23;
V_5 = F_20 ( & V_49 , & V_52 ) ;
if ( V_5 )
goto V_23;
V_5 = F_18 ( & V_54 , V_2 [ 1 ] , V_2 [ 2 ] ) ;
if ( V_5 )
goto V_23;
F_21 ( V_52 + V_54 , V_50 ) ;
V_5 = F_22 ( V_11 -> V_1 , V_12 , & V_53 ) ;
if ( V_5 ) {
F_6 ( V_9 , L_6 ,
V_14 , V_5 ) ;
goto V_23;
}
V_48 -> V_56 = ! ! ( V_53 & V_18 ) ;
V_23:
return V_5 ;
}
static int F_23 ( struct V_8 * V_9 ,
struct V_47 * V_48 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_19 V_49 , * V_50 = & V_48 -> time ;
unsigned long V_52 , V_57 ;
T_1 V_2 [ V_58 ] ;
unsigned int V_53 ;
int V_5 ;
V_5 = F_2 ( V_11 -> V_1 , V_59 , V_2 ,
V_58 ) ;
if ( V_5 ) {
F_6 ( V_9 , L_7 ,
V_14 , V_5 ) ;
goto V_23;
}
V_50 -> V_26 = 0 ;
V_50 -> V_27 = F_10 ( V_2 [ 0 ] & 0x7f ) ;
V_50 -> V_30 = F_10 ( V_2 [ 1 ] & 0x3f ) ;
V_50 -> V_33 = F_10 ( V_2 [ 2 ] & 0x3f ) ;
V_50 -> V_35 = - 1 ;
V_5 = F_9 ( V_9 , & V_49 ) ;
if ( V_5 )
goto V_23;
V_50 -> V_39 = V_49 . V_39 ;
V_50 -> V_37 = V_49 . V_37 ;
V_5 = F_20 ( & V_49 , & V_52 ) ;
if ( V_5 )
goto V_23;
V_5 = F_20 ( V_50 , & V_57 ) ;
if ( V_5 )
goto V_23;
if ( V_57 < V_52 ) {
if ( V_50 -> V_37 == 11 ) {
V_50 -> V_37 = 0 ;
V_50 -> V_39 += 1 ;
} else {
V_50 -> V_37 += 1 ;
}
}
V_5 = F_22 ( V_11 -> V_1 , V_16 , & V_53 ) ;
if ( V_5 ) {
F_6 ( V_9 , L_6 ,
V_14 , V_5 ) ;
goto V_23;
}
V_48 -> V_56 = ! ! ( V_53 & V_17 ) ;
V_23:
return V_5 ;
}
static int F_24 ( struct V_8 * V_9 , struct V_47 * V_48 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_5 ;
F_14 ( & V_11 -> V_42 ) ;
if ( V_11 -> V_60 )
V_5 = F_19 ( V_9 , V_48 ) ;
else
V_5 = F_23 ( V_9 , V_48 ) ;
F_16 ( & V_11 -> V_42 ) ;
return V_5 ;
}
static int F_25 ( struct V_8 * V_9 , struct V_47 * V_48 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_19 * V_50 = & V_48 -> time ;
unsigned long V_52 , V_57 ;
T_1 V_2 [ V_58 ] ;
struct V_19 V_49 ;
int V_5 , V_15 = 1 ;
V_5 = F_9 ( V_9 , & V_49 ) ;
if ( V_5 )
goto V_23;
V_5 = F_20 ( & V_49 , & V_52 ) ;
if ( V_5 )
goto V_23;
V_5 = F_20 ( V_50 , & V_57 ) ;
if ( V_5 )
goto V_23;
if ( ! V_48 -> V_56 || V_57 <= V_52 ) {
V_15 = 0 ;
} else {
if ( V_49 . V_37 == 11 ) {
V_49 . V_37 = 0 ;
V_49 . V_39 += 1 ;
} else {
V_49 . V_37 += 1 ;
}
V_5 = F_20 ( & V_49 , & V_52 ) ;
if ( V_5 )
goto V_23;
if ( V_57 > V_52 ) {
F_6 ( V_9 , L_8
L_9 , V_14 , V_5 ) ;
V_5 = - V_41 ;
goto V_23;
}
}
V_2 [ 0 ] = F_13 ( V_50 -> V_27 ) & 0x7f ;
V_2 [ 1 ] = F_13 ( V_50 -> V_30 ) & 0x3f ;
V_2 [ 2 ] = F_13 ( V_50 -> V_33 ) & 0x3f ;
V_2 [ 3 ] = V_61 ;
V_5 = F_15 ( V_11 -> V_1 , V_59 , V_2 ,
V_58 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_10 ,
V_14 , V_5 ) ;
goto V_23;
}
V_11 -> V_60 = 0 ;
V_5 = F_7 ( V_9 , V_15 ) ;
V_23:
return V_5 ;
}
static int F_26 ( struct V_8 * V_9 , struct V_47 * V_48 ,
T_1 V_43 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_2 [ V_51 ] ;
T_1 V_4 = V_62 | V_63 ;
int V_5 = 0 ;
F_17 ( V_43 , & V_2 [ 0 ] , & V_2 [ 1 ] ) ;
V_5 = F_15 ( V_11 -> V_1 , V_64 , V_2 ,
V_51 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_11 , V_14 ) ;
goto V_23;
}
V_5 = F_5 ( V_11 -> V_1 , V_55 ,
V_4 , V_63 ) ;
if ( V_5 )
F_6 ( V_9 , L_12 , V_14 ) ;
V_11 -> V_60 = 1 ;
V_5 = F_8 ( V_9 , V_48 -> V_56 ) ;
V_23:
return V_5 ;
}
static int F_27 ( struct V_8 * V_9 , struct V_47 * V_48 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_19 * V_50 = & V_48 -> time ;
unsigned long V_52 , V_57 ;
struct V_19 V_49 ;
int V_5 ;
F_14 ( & V_11 -> V_42 ) ;
V_5 = F_9 ( V_9 , & V_49 ) ;
if ( V_5 )
goto V_23;
V_5 = F_20 ( & V_49 , & V_52 ) ;
if ( V_5 )
goto V_23;
V_5 = F_20 ( V_50 , & V_57 ) ;
if ( V_5 )
goto V_23;
V_5 = F_7 ( V_9 , false ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_13 , V_14 ,
V_5 ) ;
goto V_23;
}
V_5 = F_8 ( V_9 , false ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_14 , V_14 ,
V_5 ) ;
goto V_23;
}
V_11 -> V_60 = 0 ;
if ( ( V_57 > V_52 ) && ( ( V_57 - V_52 ) <= 240 ) )
V_5 = F_26 ( V_9 , V_48 ,
V_57 - V_52 ) ;
else
V_5 = F_25 ( V_9 , V_48 ) ;
V_23:
F_16 ( & V_11 -> V_42 ) ;
if ( V_5 )
F_6 ( V_9 , L_15 , V_14 ,
V_5 ) ;
return V_5 ;
}
static inline int F_28 ( struct V_1 * V_1 ,
bool V_15 )
{
return F_5 ( V_1 , V_65 ,
V_66 ,
V_15 ? V_66 : 0 ) ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_1 * V_1 = V_11 -> V_1 ;
unsigned int V_53 ;
int V_5 ;
T_1 V_4 ;
V_4 = ( V_67 | V_62 |
V_63 | V_68 |
V_69 | V_70 |
V_71 | V_72 ) ;
V_5 = F_5 ( V_1 , V_55 , V_4 ,
V_68 | V_69 |
V_70 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_16 ,
V_14 , V_5 ) ;
return V_5 ;
}
V_4 = ( V_73 | V_74 |
V_75 | V_61 ) ;
V_5 = F_5 ( V_1 , V_12 , V_4 , V_4 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_17 ,
V_14 , V_5 ) ;
return V_5 ;
}
V_4 = ( V_76 | V_17 |
V_77 | V_29 |
V_78 | V_79 ) ;
V_5 = F_5 ( V_1 , V_16 , V_4 , 0 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_18 ,
V_14 , V_5 ) ;
return V_5 ;
}
V_4 = ( V_80 | V_81 |
V_18 | V_13 |
V_82 | V_83 |
V_84 ) ;
V_5 = F_5 ( V_1 , V_12 , V_4 , 0 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_19 ,
V_14 , V_5 ) ;
return V_5 ;
}
V_4 = ( V_85 | V_86 |
V_87 | V_66 |
V_88 | V_89 ) ;
V_5 = F_5 ( V_1 , V_65 , V_4 , 0 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_20 ,
V_14 , V_5 ) ;
return V_5 ;
}
V_5 = F_22 ( V_1 , V_21 , & V_53 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_21 ,
V_14 , V_5 ) ;
return V_5 ;
}
if ( V_53 & V_24 ) {
F_6 ( V_9 , L_22
L_23 ) ;
F_6 ( V_9 , L_24
L_25 ) ;
}
V_5 = F_22 ( V_1 , V_65 , & V_53 ) ;
if ( V_5 < 0 ) {
F_6 ( V_9 , L_26 ,
V_14 , V_5 ) ;
return V_5 ;
}
V_11 -> V_90 = V_53 & V_91 ;
if ( V_11 -> V_90 ) {
F_6 ( V_9 , L_27
L_28 ) ;
V_5 = F_28 ( V_1 , false ) ;
if ( V_5 )
F_6 ( V_9 , L_29
L_30 , V_14 , V_5 ) ;
}
return V_5 ;
}
static int F_30 ( struct V_8 * V_9 ,
unsigned int V_15 )
{
struct V_10 * V_92 = F_4 ( V_9 ) ;
int V_5 = 0 ;
if ( V_92 -> V_93 ) {
F_14 ( & V_92 -> V_42 ) ;
if ( V_92 -> V_60 )
V_5 = F_8 ( V_9 , V_15 ) ;
else
V_5 = F_7 ( V_9 , V_15 ) ;
F_16 ( & V_92 -> V_42 ) ;
}
return V_5 ;
}
static T_2 F_31 ( int V_93 , void * V_11 )
{
struct V_94 * V_95 = V_11 ;
struct V_8 * V_9 = & V_95 -> V_9 ;
struct V_10 * V_92 = F_4 ( V_9 ) ;
struct V_96 * V_97 = V_92 -> V_97 ;
T_1 V_2 [ V_98 ] ;
int V_5 , V_99 = V_100 ;
V_5 = F_2 ( V_92 -> V_1 , 0 , V_2 ,
V_98 ) ;
if ( V_5 ) {
F_6 ( V_9 , L_31 ,
V_14 , V_5 ) ;
return V_99 ;
}
if ( V_2 [ V_65 ] & V_91 ) {
F_6 ( V_9 , L_32 ) ;
F_28 ( V_92 -> V_1 , false ) ;
V_99 = V_101 ;
}
if ( V_2 [ V_12 ] & V_13 ) {
F_32 ( V_9 , L_33 ) ;
F_33 ( V_97 , 1 , V_102 | V_103 ) ;
F_3 ( V_9 ) ;
F_7 ( V_9 , 0 ) ;
V_99 = V_101 ;
}
if ( V_2 [ V_12 ] & V_104 ) {
F_32 ( V_9 , L_34 ) ;
F_33 ( V_97 , 1 , V_102 | V_103 ) ;
F_8 ( V_9 , 0 ) ;
V_92 -> V_60 = 0 ;
V_99 = V_101 ;
}
return V_99 ;
}
static int F_34 ( struct V_94 * V_95 ,
const struct V_105 * V_106 )
{
struct V_10 * V_11 = NULL ;
struct V_8 * V_9 = & V_95 -> V_9 ;
struct V_1 * V_1 ;
int V_5 ;
if ( ! F_35 ( V_95 -> V_107 , V_108 |
V_109 |
V_110 ) ) {
V_5 = - V_7 ;
goto V_23;
}
V_1 = F_36 ( V_95 , & V_111 ) ;
if ( F_37 ( V_1 ) ) {
V_5 = F_38 ( V_1 ) ;
F_6 ( V_9 , L_35 ,
V_14 , V_5 ) ;
goto V_23;
}
V_5 = F_1 ( V_1 ) ;
if ( V_5 )
goto V_23;
V_11 = F_39 ( V_9 , sizeof( * V_11 ) , V_112 ) ;
if ( ! V_11 ) {
V_5 = - V_113 ;
goto V_23;
}
F_40 ( & V_11 -> V_42 ) ;
V_11 -> V_1 = V_1 ;
F_41 ( V_9 , V_11 ) ;
V_5 = F_29 ( V_9 ) ;
if ( V_5 )
goto V_23;
if ( V_95 -> V_93 > 0 ) {
V_5 = F_42 ( V_9 , V_95 -> V_93 , NULL ,
F_31 ,
V_114 | V_115 ,
V_116 , V_95 ) ;
if ( ! V_5 ) {
F_43 ( V_9 , true ) ;
V_11 -> V_93 = V_95 -> V_93 ;
F_32 ( V_9 , L_36 , V_14 ,
V_95 -> V_93 ) ;
} else {
F_6 ( V_9 , L_37 ,
V_14 , V_95 -> V_93 , V_5 ) ;
goto V_23;
}
}
V_11 -> V_97 = F_44 ( V_9 , V_116 , & V_117 ,
V_118 ) ;
V_5 = F_45 ( V_11 -> V_97 ) ;
if ( V_5 ) {
F_6 ( V_9 , L_38 ,
V_14 , V_5 ) ;
goto V_23;
}
if ( ! V_11 -> V_90 && V_11 -> V_93 ) {
V_5 = F_28 ( V_1 , true ) ;
if ( V_5 ) {
F_6 ( V_9 , L_39
L_30 , V_14 , V_5 ) ;
goto V_23;
}
}
V_23:
if ( V_5 && V_11 && V_11 -> V_93 )
F_43 ( V_9 , false ) ;
return V_5 ;
}
static int F_46 ( struct V_94 * V_95 )
{
struct V_10 * V_92 = F_4 ( & V_95 -> V_9 ) ;
if ( V_92 -> V_93 > 0 )
F_43 ( & V_95 -> V_9 , false ) ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 )
{
struct V_10 * V_92 = F_4 ( V_9 ) ;
if ( F_48 ( V_9 ) )
return F_49 ( V_92 -> V_93 ) ;
return 0 ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_10 * V_92 = F_4 ( V_9 ) ;
if ( F_48 ( V_9 ) )
return F_51 ( V_92 -> V_93 ) ;
return 0 ;
}
