static int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
int V_3 , V_4 ;
T_2 * V_5 ;
V_4 = F_2 ( V_1 , V_6 , & V_2 ) ;
if ( V_4 < 0 )
return - V_7 ;
if ( ( V_2 >> 8 ) == 0x64 ) {
V_5 = F_3 (
F_4 ( V_8 ) * sizeof( T_2 ) ,
V_9 ) ;
if ( ! V_5 )
return - V_10 ;
F_5 ( L_1 ) ;
V_1 -> V_11 . V_12 . V_13 = V_14 ;
V_1 -> V_11 . V_12 . V_15 = F_4 ( V_14 ) ;
V_1 -> V_16 . V_17 = V_8 ;
V_1 -> V_16 . V_18 = F_4 ( V_8 ) ;
for ( V_3 = 0 ; V_3 < V_1 -> V_16 . V_18 ; V_3 ++ )
V_5 [ V_3 ] = V_8 [ V_3 ] . V_19 . V_20 ;
V_1 -> V_21 = V_5 ;
return 0 ;
}
return - V_7 ;
}
static int F_6 ( struct V_1 * V_1 )
{
int V_4 , V_22 , V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_12 * V_12 = & V_1 -> V_11 . V_12 ;
T_2 * V_5 = V_1 -> V_21 ;
T_3 V_28 = V_12 -> V_13 [ V_1 -> V_11 . V_29 ] . V_30 ;
V_27 = F_7 ( V_1 -> V_11 . V_31 , V_1 -> V_11 . V_32 ) ;
V_25 = F_8 ( V_27 , V_1 -> V_11 . V_25 ) ;
if ( ! V_25 )
return - V_7 ;
V_22 = F_9 ( V_25 -> V_33 [ 0 ] . V_16 . V_34 ) ;
V_23 = V_1 -> V_2 -> V_23 [ V_1 -> V_11 . V_29 ] ;
if ( V_22 < V_23 )
F_10 ( V_1 , V_35 , F_11 ( 4 ) | F_11 ( 3 ) | F_11 ( 1 ) ) ;
else
F_10 ( V_1 , V_35 , F_11 ( 5 ) | F_11 ( 3 ) | F_11 ( 1 ) ) ;
if ( V_28 & V_36 ) {
F_10 ( V_1 , V_37 , 30 ) ;
F_10 ( V_1 , V_38 , 20 ) ;
F_10 ( V_1 , V_39 , 240 - 1 ) ;
F_10 ( V_1 , V_40 , 320 - 1 ) ;
} else {
F_10 ( V_1 , V_37 , 8 ) ;
F_10 ( V_1 , V_38 , 4 ) ;
F_10 ( V_1 , V_39 , 288 - 1 ) ;
F_10 ( V_1 , V_40 , 352 - 1 ) ;
}
if ( V_28 & V_41 ) {
F_12 ( V_1 , V_42 , 0x02 ) ;
F_12 ( V_1 , V_43 , 0x06 ) ;
F_12 ( V_1 , V_44 , 0x10 ) ;
} else {
F_12 ( V_1 , V_42 , 0x01 ) ;
F_12 ( V_1 , V_43 , 0x0a ) ;
F_12 ( V_1 , V_44 , 0x20 ) ;
}
F_13 ( & V_1 -> V_11 , V_5 [ V_45 ] ) ;
F_14 ( & V_1 -> V_11 , V_5 [ V_46 ] ) ;
F_15 ( & V_1 -> V_11 ,
V_5 [ V_47 ] ) ;
F_16 ( & V_1 -> V_11 , V_5 [ V_48 ] ) ;
V_4 = F_10 ( V_1 , V_49 , F_11 ( 5 ) | F_11 ( 3 ) | F_11 ( 1 ) ) ;
F_17 ( V_50 , L_2 , V_4 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
int V_4 ;
V_4 = F_10 ( V_1 , V_51 , 1 ) ;
if ( V_4 < 0 )
goto V_52;
V_4 = F_10 ( V_1 , V_49 , F_11 ( 5 ) | F_11 ( 3 ) ) ;
F_17 ( V_50 , L_3 ) ;
V_52:
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
V_1 -> V_2 = NULL ;
F_20 ( V_1 -> V_21 ) ;
}
static int F_21 ( struct V_1 * V_1 )
{
F_12 ( V_1 , V_53 , 1 ) ;
F_12 ( V_1 , V_44 , 0 ) ;
F_10 ( V_1 , V_54 , 1 ) ;
F_10 ( V_1 , V_54 , 0 ) ;
F_10 ( V_1 , V_49 , F_11 ( 5 ) | F_11 ( 3 ) ) ;
F_10 ( V_1 , V_55 , F_11 ( 12 ) | F_11 ( 10 ) | F_11 ( 6 ) ) ;
F_10 ( V_1 , V_56 , 12 ) ;
F_10 ( V_1 , V_57 , 12 ) ;
F_10 ( V_1 , V_58 , 180 ) ;
F_10 ( V_1 , V_59 , 12 ) ;
F_10 ( V_1 , V_60 , 3 ) ;
F_10 ( V_1 , V_61 , 0 ) ;
F_10 ( V_1 , V_62 , 1 ) ;
F_10 ( V_1 , V_63 , 800 ) ;
F_10 ( V_1 , V_64 , 10 ) ;
F_10 ( V_1 , V_65 , 0 ) ;
F_10 ( V_1 , V_66 , 0 ) ;
F_10 ( V_1 , V_67 , 11 ) ;
F_10 ( V_1 , V_68 , 0 ) ;
F_12 ( V_1 , V_53 , 0x11 ) ;
F_12 ( V_1 , V_69 , 0x45 ) ;
F_12 ( V_1 , V_70 , 0x07 ) ;
F_10 ( V_1 , V_35 , F_11 ( 4 ) | F_11 ( 3 ) | F_11 ( 1 ) ) ;
F_10 ( V_1 , V_71 , 14 ) ;
F_10 ( V_1 , V_72 , 0 ) ;
F_10 ( V_1 , V_73 , 0 ) ;
F_10 ( V_1 , V_74 , 123 ) ;
F_12 ( V_1 , V_75 , 0xc2 ) ;
F_12 ( V_1 , V_76 , 0xb0 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_23 ( struct V_11 * V_11 , T_4 * V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_77 = V_5 [ V_45 ] ;
return 0 ;
}
static int F_13 ( struct V_11 * V_11 , T_4 V_77 )
{
int V_4 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
if ( V_5 [ V_48 ] )
return - V_78 ;
V_5 [ V_45 ] = V_77 ;
V_4 = F_10 ( V_1 , V_79 , V_77 ) ;
if ( ! V_4 )
V_4 = F_10 ( V_1 , V_80 , V_77 ) ;
F_17 ( V_81 , L_4 , V_77 , V_4 ) ;
if ( ! V_4 )
V_4 = F_24 ( V_11 ,
V_5 [ V_82 ] ) ;
if ( ! V_4 )
V_4 = F_25 ( V_11 ,
V_5 [ V_83 ] ) ;
return V_4 ;
}
static int F_26 ( struct V_11 * V_11 , T_4 * V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_77 = V_5 [ V_82 ] ;
return 0 ;
}
static int F_24 ( struct V_11 * V_11 , T_4 V_77 )
{
int V_4 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
if ( V_5 [ V_48 ] )
return - V_78 ;
V_5 [ V_82 ] = V_77 ;
V_77 += V_5 [ V_45 ] ;
if ( V_77 < 0 )
V_77 = 0 ;
else if ( V_77 > 255 )
V_77 = 255 ;
V_4 = F_10 ( V_1 , V_84 , V_77 ) ;
F_17 ( V_81 , L_5 , V_77 , V_4 ) ;
return V_4 ;
}
static int F_27 ( struct V_11 * V_11 , T_4 * V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_77 = V_5 [ V_83 ] ;
return 0 ;
}
static int F_25 ( struct V_11 * V_11 , T_4 V_77 )
{
int V_4 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
if ( V_5 [ V_48 ] )
return - V_78 ;
V_5 [ V_83 ] = V_77 ;
V_77 += V_5 [ V_45 ] ;
if ( V_77 < 0 )
V_77 = 0 ;
else if ( V_77 > 255 )
V_77 = 255 ;
V_4 = F_10 ( V_1 , V_85 , V_77 ) ;
F_17 ( V_81 , L_6 , V_77 , V_4 ) ;
return V_4 ;
}
static int F_28 ( struct V_11 * V_11 , T_4 * V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_77 = V_5 [ V_46 ] ;
return 0 ;
}
static int F_14 ( struct V_11 * V_11 , T_4 V_77 )
{
int V_4 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
if ( V_5 [ V_48 ] )
return - V_78 ;
V_5 [ V_46 ] = V_77 ;
V_4 = F_10 ( V_1 , V_74 , V_77 ) ;
F_17 ( V_81 , L_7 , V_77 , V_4 ) ;
return V_4 ;
}
static int F_29 ( struct V_11 * V_11 , T_4 * V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_77 = V_5 [ V_48 ] ;
return 0 ;
}
static int F_16 ( struct V_11 * V_11 , T_4 V_77 )
{
int V_4 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_48 ] = V_77 ;
if ( V_5 [ V_48 ] ) {
if ( V_5 [ V_86 ] )
V_77 = F_11 ( 6 ) | F_11 ( 4 ) | F_11 ( 0 ) ;
else
V_77 = F_11 ( 4 ) | F_11 ( 0 ) ;
} else
V_77 = 0 ;
V_4 = F_10 ( V_1 , V_65 , V_77 ) ;
F_17 ( V_81 , L_8 ,
V_5 [ V_48 ] , V_5 [ V_86 ] ,
V_4 ) ;
return V_4 ;
}
static int F_30 ( struct V_11 * V_11 , T_4 * V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_77 = V_5 [ V_47 ] ;
return 0 ;
}
static int F_15 ( struct V_11 * V_11 , T_4 V_77 )
{
int V_4 , V_87 , V_88 , V_89 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_47 ] = V_77 ;
V_87 = V_11 -> V_90 * V_11 -> V_91 ;
V_87 = V_87 / ( 8 * 8 ) + V_87 / ( 64 * 64 ) ;
V_88 = ( V_87 * V_77 ) >> 8 ;
V_89 = V_87 - V_88 ;
V_4 = F_10 ( V_1 , V_92 , V_88 ) ;
if ( ! V_4 )
V_4 = F_10 ( V_1 , V_93 , V_89 ) ;
F_17 ( V_81 , L_9 , V_77 , V_4 ) ;
return V_4 ;
}
static int F_31 ( struct V_11 * V_11 , T_4 * V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_77 = V_5 [ V_86 ] ;
return 0 ;
}
static int F_32 ( struct V_11 * V_11 , T_4 V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_86 ] = V_77 ;
return F_16 ( V_11 , V_5 [ V_48 ] ) ;
}
