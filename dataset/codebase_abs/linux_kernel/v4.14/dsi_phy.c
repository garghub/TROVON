static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 ,
T_1 V_4 , bool V_5 )
{
T_1 V_6 ;
V_6 = ( V_1 - V_2 ) * V_3 ;
V_6 = F_2 ( V_6 , 100 ) + V_2 ;
if ( V_5 && ( V_6 & 0x1 ) )
return F_3 ( T_1 , V_4 , V_6 - 1 ) ;
else
return F_3 ( T_1 , V_4 , V_6 ) ;
}
static void F_4 ( struct V_7 * V_8 ,
T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
T_1 V_1 , V_2 , V_12 ;
T_1 V_13 ;
V_13 = 300 * V_10 - ( ( V_8 -> V_14 >> 1 ) + 1 ) * 2 * V_9 ;
V_2 = F_2 ( V_13 , V_9 ) - 2 ;
if ( V_2 > 255 ) {
V_1 = 511 ;
V_12 = F_1 ( 2 * V_2 , V_2 , V_11 , 0 , true ) ;
} else {
V_1 = 255 ;
V_12 = F_1 ( V_1 , V_2 , V_11 , 0 , true ) ;
}
V_13 = ( V_8 -> V_15 + V_8 -> V_14 + V_12 ) & 0x7 ;
V_8 -> V_16 = V_12 + 8 - V_13 ;
}
int F_5 ( struct V_7 * V_8 ,
struct V_17 * V_18 )
{
const unsigned long V_19 = V_18 -> V_20 ;
const unsigned long V_21 = V_18 -> V_22 ;
T_1 V_9 , V_23 ;
T_1 V_1 , V_2 ;
T_1 V_24 = 10 ;
T_1 V_25 = ( V_19 > 1200000000 ) ? 15 : 10 ;
T_1 V_26 = 10 ;
T_1 V_27 = ( V_19 > 180000000 ) ? 10 : 40 ;
T_1 V_10 = 1000 ;
T_1 V_13 ;
if ( ! V_19 || ! V_21 )
return - V_28 ;
V_9 = F_6 ( V_29 , V_10 , V_19 / 1000 ) ;
V_23 = F_6 ( V_29 , V_10 , V_21 / 1000 ) ;
V_1 = F_2 ( 95 * V_10 , V_9 ) - 2 ;
V_2 = F_2 ( 38 * V_10 , V_9 ) - 2 ;
V_8 -> V_14 = F_1 ( V_1 , V_2 , V_24 , 0 , true ) ;
V_13 = V_23 / V_9 ;
if ( V_13 & 0x1 )
V_8 -> V_15 = V_13 ;
else
V_8 -> V_15 = F_3 ( T_1 , 0 , V_13 - 2 ) ;
F_4 ( V_8 , V_9 , V_10 , V_26 ) ;
V_13 = 105 * V_10 + 12 * V_9 - 20 * V_10 ;
V_1 = F_2 ( V_13 , V_9 ) - 2 ;
V_2 = F_2 ( 60 * V_10 , V_9 ) - 2 ;
V_8 -> V_30 = F_1 ( V_1 , V_2 , V_27 , 0 , true ) ;
V_13 = 85 * V_10 + 6 * V_9 ;
V_1 = F_2 ( V_13 , V_9 ) - 2 ;
V_13 = 40 * V_10 + 4 * V_9 ;
V_2 = F_2 ( V_13 , V_9 ) - 2 ;
V_8 -> V_31 = F_1 ( V_1 , V_2 , V_25 , 0 , true ) ;
V_1 = 255 ;
V_13 = ( ( V_8 -> V_31 >> 1 ) + 1 ) * 2 * V_9 + 2 * V_9 ;
V_13 = 145 * V_10 + 10 * V_9 - V_13 ;
V_2 = F_2 ( V_13 , V_9 ) - 2 ;
V_8 -> V_32 = F_1 ( V_1 , V_2 , V_26 , 24 , true ) ;
V_13 = 105 * V_10 + 12 * V_9 - 20 * V_10 ;
V_1 = F_2 ( V_13 , V_9 ) - 2 ;
V_13 = 60 * V_10 + 4 * V_9 ;
V_2 = F_7 ( V_13 , V_9 ) - 2 ;
V_8 -> V_33 = F_1 ( V_1 , V_2 , V_27 , 0 , true ) ;
V_1 = 255 ;
V_2 = F_2 ( 100 * V_10 , V_9 ) - 2 ;
V_8 -> V_34 = F_1 ( V_1 , V_2 , V_26 , 0 , true ) ;
V_1 = 63 ;
V_13 = ( ( V_8 -> V_34 >> 1 ) + 1 ) * 2 * V_9 ;
V_13 = 60 * V_10 + 52 * V_9 - 24 * V_9 - V_13 ;
V_2 = F_2 ( V_13 , 8 * V_9 ) - 1 ;
V_8 -> V_35 . V_36 = F_1 ( V_1 , V_2 , V_26 , 0 ,
false ) ;
V_1 = 63 ;
V_13 = ( ( V_8 -> V_14 >> 1 ) + 1 ) * 2 * V_9 ;
V_13 += ( ( V_8 -> V_16 >> 1 ) + 1 ) * 2 * V_9 ;
V_13 += 8 * V_9 + V_23 ;
V_2 = F_2 ( V_13 , 8 * V_9 ) - 1 ;
if ( V_2 > V_1 ) {
V_13 = F_1 ( 2 * V_1 , V_2 , V_26 , 0 , false ) ;
V_8 -> V_35 . V_37 = V_13 >> 1 ;
V_8 -> V_35 . V_38 = true ;
} else {
V_8 -> V_35 . V_37 =
F_1 ( V_1 , V_2 , V_26 , 0 , false ) ;
V_8 -> V_35 . V_38 = false ;
}
V_8 -> V_39 = 3 ;
V_8 -> V_40 = 0 ;
V_8 -> V_41 = 4 ;
F_8 ( L_1 ,
V_8 -> V_35 . V_37 , V_8 -> V_35 . V_36 ,
V_8 -> V_35 . V_38 , V_8 -> V_16 ,
V_8 -> V_30 , V_8 -> V_14 , V_8 -> V_34 ,
V_8 -> V_32 , V_8 -> V_31 , V_8 -> V_33 ,
V_8 -> V_15 ) ;
return 0 ;
}
int F_9 ( struct V_7 * V_8 ,
struct V_17 * V_18 )
{
const unsigned long V_19 = V_18 -> V_20 ;
const unsigned long V_21 = V_18 -> V_22 ;
T_1 V_9 , V_42 , V_23 ;
T_1 V_1 , V_2 ;
T_1 V_24 = 50 ;
T_1 V_25 = 50 ;
T_1 V_26 = 10 ;
T_1 V_27 = 30 ;
T_1 V_43 = 10 ;
T_1 V_44 = 2 ;
T_1 V_10 = 1000 ;
T_1 V_45 , V_46 , V_47 , V_48 ;
T_1 V_49 , V_50 ;
T_1 V_13 ;
if ( ! V_19 || ! V_21 )
return - V_28 ;
V_8 -> V_51 = 0 ;
V_45 = 0 ;
V_8 -> V_52 = 0 ;
V_46 = 0 ;
V_8 -> V_53 = ( V_19 > 100000000 ) ? 0 : 3 ;
V_47 = V_8 -> V_53 ;
V_8 -> V_54 = ( V_19 > 120000000 ) ? 0 : 1 ;
V_48 = V_8 -> V_54 ;
V_49 = ( V_45 << 2 ) + ( V_48 << 1 ) ;
V_50 = ( V_46 << 2 ) + ( V_47 << 1 ) ;
V_9 = F_6 ( V_29 , V_10 , V_19 / 1000 ) ;
V_42 = V_9 << 3 ;
V_23 = F_6 ( V_29 , V_10 , V_21 / 1000 ) ;
V_13 = F_2 ( 38 * V_10 - V_50 * V_9 , V_42 ) ;
V_2 = F_3 ( T_1 , V_13 , 0 ) ;
V_13 = ( 95 * V_10 - V_50 * V_9 ) / V_42 ;
V_1 = F_3 ( T_1 , V_13 , 0 ) ;
V_8 -> V_14 = F_1 ( V_1 , V_2 , V_24 , 0 , false ) ;
V_13 = 300 * V_10 - ( ( V_8 -> V_14 << 3 ) + V_50 ) * V_9 ;
V_2 = F_2 ( V_13 - 11 * V_9 , V_42 ) - 3 ;
V_1 = ( V_2 > 255 ) ? 511 : 255 ;
V_8 -> V_16 = F_1 ( V_1 , V_2 , V_44 , 0 , false ) ;
V_2 = F_7 ( 60 * V_10 + 3 * V_9 , V_42 ) ;
V_13 = 105 * V_10 + 12 * V_9 - 20 * V_10 ;
V_1 = ( V_13 + 3 * V_9 ) / V_42 ;
V_8 -> V_30 = F_1 ( V_1 , V_2 , V_27 , 0 , false ) ;
V_13 = F_2 ( 40 * V_10 + 4 * V_9 - V_49 * V_9 , V_42 ) ;
V_2 = F_3 ( T_1 , V_13 , 0 ) ;
V_13 = ( 85 * V_10 + 6 * V_9 - V_49 * V_9 ) / V_42 ;
V_1 = F_3 ( T_1 , V_13 , 0 ) ;
V_8 -> V_31 = F_1 ( V_1 , V_2 , V_25 , 0 , false ) ;
V_13 = 145 * V_10 + 10 * V_9 - ( ( V_8 -> V_31 << 3 ) + V_49 ) * V_9 ;
V_2 = F_2 ( V_13 - 11 * V_9 , V_42 ) - 3 ;
V_1 = 255 ;
V_8 -> V_32 = F_1 ( V_1 , V_2 , V_43 , 0 , false ) ;
V_2 = F_7 ( 60 * V_10 + 4 * V_9 + 3 * V_9 , V_42 ) ;
V_13 = 105 * V_10 + 12 * V_9 - 20 * V_10 ;
V_1 = ( V_13 + 3 * V_9 ) / V_42 ;
V_8 -> V_33 = F_1 ( V_1 , V_2 , V_27 , 0 , false ) ;
V_13 = 50 * V_10 + ( ( V_45 << 2 ) - 8 ) * V_9 ;
V_8 -> V_15 = F_2 ( V_13 , V_42 ) ;
V_2 = F_7 ( 100 * V_10 , V_42 ) - 1 ;
V_1 = 255 ;
V_8 -> V_34 = F_1 ( V_1 , V_2 , V_26 , 0 , false ) ;
V_13 = 50 * V_10 + ( ( V_46 << 2 ) - 8 ) * V_9 ;
V_8 -> V_55 = F_2 ( V_13 , V_42 ) ;
V_13 = 60 * V_10 + 52 * V_9 - 43 * V_9 ;
V_2 = F_7 ( V_13 , V_42 ) - 1 ;
V_1 = 63 ;
V_8 -> V_35 . V_36 =
F_1 ( V_1 , V_2 , V_26 , 0 , false ) ;
V_13 = 8 * V_9 + ( ( V_8 -> V_14 << 3 ) + V_50 ) * V_9 ;
V_13 += ( ( ( V_8 -> V_16 + 3 ) << 3 ) + 11 - ( V_47 << 1 ) ) * V_9 ;
V_13 += V_46 ? ( ( ( V_8 -> V_55 << 3 ) + 4 ) * V_9 ) :
( ( ( V_8 -> V_55 << 3 ) + 8 ) * V_9 ) ;
V_2 = F_2 ( V_13 , V_42 ) - 1 ;
V_1 = 63 ;
if ( V_2 > V_1 ) {
V_13 = F_1 ( V_1 << 1 , V_2 , V_26 , 0 , false ) ;
V_8 -> V_35 . V_37 = V_13 >> 1 ;
V_8 -> V_35 . V_38 = 1 ;
} else {
V_8 -> V_35 . V_37 =
F_1 ( V_1 , V_2 , V_26 , 0 , false ) ;
V_8 -> V_35 . V_38 = 0 ;
}
V_8 -> V_39 = 3 ;
V_8 -> V_40 = 0 ;
V_8 -> V_41 = 4 ;
F_8 ( L_2 ,
V_8 -> V_35 . V_37 , V_8 -> V_35 . V_36 ,
V_8 -> V_35 . V_38 , V_8 -> V_16 ,
V_8 -> V_30 , V_8 -> V_14 , V_8 -> V_34 ,
V_8 -> V_32 , V_8 -> V_31 , V_8 -> V_33 ,
V_8 -> V_15 , V_8 -> V_55 , V_8 -> V_51 ,
V_8 -> V_52 , V_8 -> V_54 ,
V_8 -> V_53 ) ;
return 0 ;
}
void F_10 ( struct V_56 * V_57 , int V_58 , T_2 V_59 ,
T_2 V_60 )
{
int V_61 = V_57 -> V_62 ;
T_2 V_49 ;
if ( ( V_61 >= V_63 ) || ( V_58 >= V_63 ) )
return;
V_49 = F_11 ( V_57 -> V_64 + V_59 ) ;
if ( V_57 -> V_65 -> V_66 [ V_61 ] [ V_58 ] )
F_12 ( V_57 -> V_64 + V_59 , V_49 | V_60 ) ;
else
F_12 ( V_57 -> V_64 + V_59 , V_49 & ( ~ V_60 ) ) ;
}
static int F_13 ( struct V_56 * V_57 )
{
struct V_67 * V_68 = V_57 -> V_69 ;
const struct V_70 * V_71 = V_57 -> V_65 -> V_72 . V_71 ;
struct V_73 * V_74 = & V_57 -> V_75 -> V_74 ;
int V_76 = V_57 -> V_65 -> V_72 . V_76 ;
int V_77 , V_78 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
V_68 [ V_77 ] . V_79 = V_71 [ V_77 ] . V_80 ;
V_78 = F_14 ( V_74 , V_76 , V_68 ) ;
if ( V_78 < 0 ) {
F_15 ( V_74 , L_3 ,
V_81 , V_78 ) ;
return V_78 ;
}
return 0 ;
}
static void F_16 ( struct V_56 * V_57 )
{
struct V_67 * V_68 = V_57 -> V_69 ;
const struct V_70 * V_71 = V_57 -> V_65 -> V_72 . V_71 ;
int V_76 = V_57 -> V_65 -> V_72 . V_76 ;
int V_77 ;
F_8 ( L_4 ) ;
for ( V_77 = V_76 - 1 ; V_77 >= 0 ; V_77 -- )
if ( V_71 [ V_77 ] . V_82 >= 0 )
F_17 ( V_68 [ V_77 ] . V_83 , V_71 [ V_77 ] . V_82 ) ;
F_18 ( V_76 , V_68 ) ;
}
static int F_19 ( struct V_56 * V_57 )
{
struct V_67 * V_68 = V_57 -> V_69 ;
const struct V_70 * V_71 = V_57 -> V_65 -> V_72 . V_71 ;
struct V_73 * V_74 = & V_57 -> V_75 -> V_74 ;
int V_76 = V_57 -> V_65 -> V_72 . V_76 ;
int V_78 , V_77 ;
F_8 ( L_4 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
if ( V_71 [ V_77 ] . V_84 >= 0 ) {
V_78 = F_17 ( V_68 [ V_77 ] . V_83 ,
V_71 [ V_77 ] . V_84 ) ;
if ( V_78 < 0 ) {
F_15 ( V_74 ,
L_5 ,
V_77 , V_78 ) ;
goto V_85;
}
}
}
V_78 = F_20 ( V_76 , V_68 ) ;
if ( V_78 < 0 ) {
F_15 ( V_74 , L_6 , V_78 ) ;
goto V_85;
}
return 0 ;
V_85:
for ( V_77 -- ; V_77 >= 0 ; V_77 -- )
F_17 ( V_68 [ V_77 ] . V_83 , V_71 [ V_77 ] . V_82 ) ;
return V_78 ;
}
static int F_21 ( struct V_56 * V_57 )
{
struct V_73 * V_74 = & V_57 -> V_75 -> V_74 ;
int V_78 ;
F_22 ( V_74 ) ;
V_78 = F_23 ( V_57 -> V_86 ) ;
if ( V_78 ) {
F_15 ( V_74 , L_7 , V_81 , V_78 ) ;
F_24 ( V_74 ) ;
}
return V_78 ;
}
static void F_25 ( struct V_56 * V_57 )
{
F_26 ( V_57 -> V_86 ) ;
F_27 ( & V_57 -> V_75 -> V_74 ) ;
}
static int F_28 ( struct V_56 * V_57 )
{
struct V_87 * V_75 = V_57 -> V_75 ;
const struct V_88 * V_65 = V_57 -> V_65 ;
struct V_89 * V_90 ;
int V_77 ;
V_90 = F_29 ( V_75 , V_91 , L_8 ) ;
if ( ! V_90 )
return - V_28 ;
for ( V_77 = 0 ; V_77 < V_65 -> V_92 ; V_77 ++ ) {
if ( V_65 -> V_93 [ V_77 ] == V_90 -> V_94 )
return V_77 ;
}
return - V_28 ;
}
int F_30 ( struct V_56 * V_57 )
{
struct V_87 * V_75 = V_57 -> V_75 ;
int V_78 = 0 ;
V_57 -> V_95 = F_31 ( V_75 , L_9 ,
L_10 ) ;
if ( F_32 ( V_57 -> V_95 ) ) {
F_15 ( & V_75 -> V_74 , L_11 ,
V_81 ) ;
V_78 = - V_96 ;
goto V_85;
}
V_85:
return V_78 ;
}
static int F_33 ( struct V_87 * V_75 )
{
struct V_56 * V_57 ;
struct V_73 * V_74 = & V_75 -> V_74 ;
const struct V_97 * V_98 ;
int V_78 ;
V_57 = F_34 ( V_74 , sizeof( * V_57 ) , V_99 ) ;
if ( ! V_57 )
return - V_96 ;
V_98 = F_35 ( V_100 , V_74 -> V_101 ) ;
if ( ! V_98 )
return - V_102 ;
V_57 -> V_65 = V_98 -> V_103 ;
V_57 -> V_75 = V_75 ;
V_57 -> V_62 = F_28 ( V_57 ) ;
if ( V_57 -> V_62 < 0 ) {
V_78 = V_57 -> V_62 ;
F_15 ( V_74 , L_12 ,
V_81 , V_78 ) ;
goto V_85;
}
V_57 -> V_104 = F_36 ( V_74 -> V_101 ,
L_13 ) ;
V_57 -> V_64 = F_31 ( V_75 , L_8 , L_14 ) ;
if ( F_32 ( V_57 -> V_64 ) ) {
F_15 ( V_74 , L_15 , V_81 ) ;
V_78 = - V_96 ;
goto V_85;
}
V_78 = F_13 ( V_57 ) ;
if ( V_78 ) {
F_15 ( V_74 , L_16 , V_81 ) ;
goto V_85;
}
V_57 -> V_86 = F_37 ( V_74 , L_17 ) ;
if ( F_32 ( V_57 -> V_86 ) ) {
F_15 ( V_74 , L_18 , V_81 ) ;
V_78 = F_38 ( V_57 -> V_86 ) ;
goto V_85;
}
if ( V_57 -> V_65 -> V_105 . V_106 ) {
V_78 = V_57 -> V_65 -> V_105 . V_106 ( V_57 ) ;
if ( V_78 )
goto V_85;
}
V_78 = F_21 ( V_57 ) ;
if ( V_78 )
goto V_85;
V_57 -> V_107 = F_39 ( V_75 , V_57 -> V_65 -> type , V_57 -> V_62 ) ;
if ( ! V_57 -> V_107 )
F_40 ( V_74 ,
L_19 ,
V_81 ) ;
F_25 ( V_57 ) ;
F_41 ( V_75 , V_57 ) ;
return 0 ;
V_85:
return V_78 ;
}
static int F_42 ( struct V_87 * V_75 )
{
struct V_56 * V_57 = F_43 ( V_75 ) ;
if ( V_57 && V_57 -> V_107 ) {
F_44 ( V_57 -> V_107 ) ;
V_57 -> V_107 = NULL ;
}
F_41 ( V_75 , NULL ) ;
return 0 ;
}
void T_3 F_45 ( void )
{
F_46 ( & V_108 ) ;
}
void T_4 F_47 ( void )
{
F_48 ( & V_108 ) ;
}
int F_49 ( struct V_56 * V_57 , int V_109 ,
struct V_17 * V_18 )
{
struct V_73 * V_74 = & V_57 -> V_75 -> V_74 ;
int V_78 ;
if ( ! V_57 || ! V_57 -> V_65 -> V_105 . V_110 )
return - V_28 ;
V_78 = F_21 ( V_57 ) ;
if ( V_78 ) {
F_15 ( V_74 , L_20 ,
V_81 , V_78 ) ;
goto V_111;
}
V_78 = F_19 ( V_57 ) ;
if ( V_78 ) {
F_15 ( V_74 , L_21 ,
V_81 , V_78 ) ;
goto V_112;
}
V_78 = V_57 -> V_65 -> V_105 . V_110 ( V_57 , V_109 , V_18 ) ;
if ( V_78 ) {
F_15 ( V_74 , L_22 , V_81 , V_78 ) ;
goto V_113;
}
if ( V_57 -> V_114 != V_115 ) {
V_78 = F_50 ( V_57 -> V_107 ) ;
if ( V_78 ) {
F_15 ( V_74 , L_23 ,
V_81 , V_78 ) ;
goto V_116;
}
}
return 0 ;
V_116:
if ( V_57 -> V_65 -> V_105 . V_117 )
V_57 -> V_65 -> V_105 . V_117 ( V_57 ) ;
V_113:
F_16 ( V_57 ) ;
V_112:
F_25 ( V_57 ) ;
V_111:
return V_78 ;
}
void F_51 ( struct V_56 * V_57 )
{
if ( ! V_57 || ! V_57 -> V_65 -> V_105 . V_117 )
return;
if ( V_57 -> V_114 != V_115 )
F_52 ( V_57 -> V_107 ) ;
V_57 -> V_65 -> V_105 . V_117 ( V_57 ) ;
F_16 ( V_57 ) ;
F_25 ( V_57 ) ;
}
void F_53 ( struct V_56 * V_57 ,
struct V_118 * V_35 )
{
memcpy ( V_35 , & V_57 -> V_8 . V_35 ,
sizeof( * V_35 ) ) ;
}
struct V_119 * F_54 ( struct V_56 * V_57 )
{
if ( ! V_57 )
return NULL ;
return V_57 -> V_107 ;
}
void F_55 ( struct V_56 * V_57 ,
enum V_120 V_121 )
{
if ( V_57 )
V_57 -> V_114 = V_121 ;
}
