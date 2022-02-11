static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 )
return 0x01 ;
else if ( V_3 < V_2 -> V_4 )
return V_3 + 1 ;
else if ( V_3 < V_2 -> V_4 * 2 )
return V_3 - V_2 -> V_4 + 0x09 ;
else if ( V_3 == V_2 -> V_4 * 2 + V_5 )
return 0x11 ;
else if ( V_3 == V_2 -> V_4 + V_6 )
return 0x63 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_7 )
{
int V_8 ;
if ( V_7 <= 0x00 )
return V_2 -> V_4 + V_9 ;
else if ( V_7 <= 0x08 ) {
V_8 = V_7 - 1 ;
if ( V_8 >= V_2 -> V_4 )
V_8 = 0 ;
return V_8 ;
} else if ( V_7 <= 0x10 ) {
V_8 = V_7 - 0x09 + V_2 -> V_4 ;
if ( V_8 >= V_2 -> V_4 * 2 )
V_8 = V_2 -> V_4 ;
return V_8 ;
} else if ( V_7 == 0x11 )
return V_2 -> V_4 + V_5 ;
else
return V_2 -> V_4 + V_6 ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_2 V_10 )
{
T_1 V_11 = 0 ;
if ( V_10 == V_12 ) {
V_11 = F_4 ( V_2 -> V_13 + V_12 ) ;
V_11 = ( V_11 & 0xf8 ) ;
} else if ( V_10 == V_14 ) {
V_11 = F_4 ( V_2 -> V_13 + V_14 ) ;
V_11 = ( V_11 & 0x1c ) ;
}
return V_11 ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_10 , T_1 V_15 )
{
if ( V_10 == V_16 || V_10 == V_14 )
F_6 ( V_15 , V_2 -> V_13 + V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_17 = 10000 ;
T_1 V_18 ;
V_18 = F_3 ( V_2 , V_12 ) ;
while ( ! ( V_18 & V_19 ) && V_17 -- ) {
V_18 = F_3 ( V_2 , V_12 ) ;
F_8 ( 10 ) ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 V_20 )
{
T_1 V_21 ;
T_1 V_22 ;
T_1 V_23 ;
F_7 ( V_2 ) ;
V_21 = F_3 ( V_2 , V_14 ) ;
V_22 = V_21 & ( V_24 ^ 0xff ) ;
V_23 = V_21 | V_24 ;
F_5 ( V_2 , V_16 , V_20 ) ;
F_5 ( V_2 , V_14 , V_22 ) ;
F_5 ( V_2 , V_14 , V_23 ) ;
}
static void F_10 ( struct V_1 * V_25 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
T_1 V_30 ;
if ( F_11 ( V_29 , & V_30 , 1 ) != 1 )
return;
if ( V_27 -> V_7 != V_25 -> V_31 ) {
V_25 -> V_31 = V_27 -> V_7 ;
F_9 ( V_25 , 0xf5 ) ;
F_9 ( V_25 , V_27 -> V_7 ) ;
if ( ! ( V_30 & 0x80 ) && V_27 -> V_32 )
F_9 ( V_25 , V_27 -> V_32 ) ;
}
do {
if ( V_30 & 0x80 )
V_27 -> V_32 = V_30 ;
F_9 ( V_25 , V_30 ) ;
} while ( F_11 ( V_29 , & V_30 , 1 ) == 1 );
}
static void F_12 ( struct V_28 * V_29 )
{
struct V_1 * V_25 = V_29 -> V_33 -> V_34 ;
struct V_26 * V_27 = & V_25 -> V_35 [ V_29 -> V_36 ] ;
unsigned long V_37 ;
F_13 ( & V_25 -> V_38 , V_37 ) ;
F_10 ( V_25 , V_27 , V_29 ) ;
F_14 ( & V_25 -> V_38 , V_37 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
F_9 ( V_2 , 0xf5 ) ;
F_9 ( V_2 , V_8 ) ;
F_9 ( V_2 , 0xfe ) ;
}
}
static int F_16 ( struct V_28 * V_29 )
{
struct V_1 * V_25 = V_29 -> V_33 -> V_34 ;
struct V_26 * V_27 = & V_25 -> V_35 [ V_29 -> V_36 ] ;
unsigned long V_37 ;
F_13 ( & V_25 -> V_38 , V_37 ) ;
V_27 -> V_39 |= V_40 ;
V_27 -> V_41 = V_29 ;
if ( V_25 -> V_42 ++ == 0 )
F_5 ( V_25 , V_14 , ( V_43 | V_24 ) ) ;
F_14 ( & V_25 -> V_38 , V_37 ) ;
return 0 ;
}
static int F_17 ( struct V_28 * V_29 )
{
struct V_1 * V_25 = V_29 -> V_33 -> V_34 ;
struct V_26 * V_27 = & V_25 -> V_35 [ V_29 -> V_36 ] ;
unsigned long V_37 ;
F_13 ( & V_25 -> V_38 , V_37 ) ;
V_27 -> V_39 &= ~ V_40 ;
V_27 -> V_41 = NULL ;
if ( -- V_25 -> V_42 == 0 )
F_5 ( V_25 , V_14 , 0 ) ;
F_14 ( & V_25 -> V_38 , V_37 ) ;
return 0 ;
}
static void F_18 ( struct V_28 * V_29 , int V_44 )
{
struct V_1 * V_25 = V_29 -> V_33 -> V_34 ;
struct V_26 * V_27 = & V_25 -> V_35 [ V_29 -> V_36 ] ;
unsigned long V_37 ;
F_13 ( & V_25 -> V_38 , V_37 ) ;
if ( V_44 )
V_27 -> V_39 |= V_45 ;
else
V_27 -> V_39 &= ~ V_45 ;
F_14 ( & V_25 -> V_38 , V_37 ) ;
}
static void F_19 ( unsigned long V_46 )
{
unsigned long V_37 ;
struct V_1 * V_2 = (struct V_1 * ) V_46 ;
int V_8 ;
F_13 ( & V_2 -> V_38 , V_37 ) ;
V_2 -> V_47 . V_48 = 1 + V_49 ;
F_20 ( & V_2 -> V_47 ) ;
for ( V_8 = 0 ; V_8 <= V_2 -> V_4 * 2 + V_9 ; V_8 ++ ) {
struct V_26 * V_27 = & V_2 -> V_35 [ V_8 ] ;
if ( ( V_27 -> V_39 & V_50 ) && V_27 -> V_51 )
F_10 ( V_2 , V_27 , V_27 -> V_51 ) ;
}
F_14 ( & V_2 -> V_38 , V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_47 . V_48 = 1 + V_49 ;
F_20 ( & V_2 -> V_47 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_47 ) ;
}
static int F_24 ( struct V_28 * V_29 )
{
struct V_1 * V_25 = V_29 -> V_33 -> V_34 ;
struct V_26 * V_27 = & V_25 -> V_35 [ V_29 -> V_36 ] ;
unsigned long V_37 ;
F_13 ( & V_25 -> V_38 , V_37 ) ;
V_27 -> V_39 |= V_52 ;
V_27 -> V_51 = V_29 ;
F_14 ( & V_25 -> V_38 , V_37 ) ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 )
{
struct V_1 * V_25 = V_29 -> V_33 -> V_34 ;
struct V_26 * V_27 = & V_25 -> V_35 [ V_29 -> V_36 ] ;
unsigned long V_37 ;
F_13 ( & V_25 -> V_38 , V_37 ) ;
V_27 -> V_39 &= ~ V_52 ;
V_27 -> V_51 = NULL ;
F_14 ( & V_25 -> V_38 , V_37 ) ;
return 0 ;
}
static void F_26 ( struct V_28 * V_29 , int V_44 )
{
struct V_1 * V_25 = V_29 -> V_33 -> V_34 ;
struct V_26 * V_27 = & V_25 -> V_35 [ V_29 -> V_36 ] ;
unsigned long V_37 ;
F_13 ( & V_25 -> V_38 , V_37 ) ;
if ( V_44 ) {
if ( ! ( V_27 -> V_39 & V_50 ) ) {
if ( V_25 -> V_53 ++ == 0 )
F_21 ( V_25 ) ;
V_27 -> V_39 |= V_50 ;
}
} else {
V_27 -> V_39 &= ~ V_50 ;
if ( -- V_25 -> V_53 == 0 )
F_22 ( V_25 ) ;
}
F_14 ( & V_25 -> V_38 , V_37 ) ;
if ( V_44 )
F_12 ( V_29 ) ;
}
static void F_27 ( struct V_1 * V_54 , T_1 V_55 )
{
struct V_26 * V_27 ;
if ( ( int ) V_54 -> V_56 > V_54 -> V_4 * 2 + V_9 )
return;
V_27 = & V_54 -> V_35 [ V_54 -> V_56 ] ;
if ( V_27 -> V_39 & V_45 )
F_28 ( V_27 -> V_41 , & V_55 , 1 ) ;
}
static void F_29 ( struct V_1 * V_54 , T_1 V_55 )
{
if ( V_55 >= 0xf8 ) {
F_27 ( V_54 , V_55 ) ;
return;
}
if ( V_54 -> V_57 == 0 ) {
if ( V_55 == 0xf5 )
V_54 -> V_57 = 1 ;
else
F_27 ( V_54 , V_55 ) ;
} else if ( V_54 -> V_57 ) {
V_54 -> V_56 = F_2 ( V_54 , V_55 ) ;
V_54 -> V_57 = 0 ;
}
}
static void F_30 ( struct V_1 * V_54 )
{
T_1 V_58 , V_59 ;
T_1 V_60 ;
T_1 V_61 , V_62 ;
int V_63 ;
T_1 V_64 = F_3 ( V_54 , V_12 ) ;
if ( ! ( V_64 & V_65 ) )
return;
V_62 = F_3 ( V_54 , V_14 ) ;
V_58 = V_62 & ( V_66 ^ 0xff ) ;
V_59 = V_62 | V_66 ;
do {
V_60 = 0 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
F_5 ( V_54 , V_14 , V_59 ) ;
V_61 = F_3 ( V_54 , V_12 ) ;
F_5 ( V_54 , V_14 , V_58 ) ;
V_61 &= V_67 | V_68 ;
V_61 >>= 4 ;
V_60 |= V_61 << ( V_63 * 2 ) ;
}
F_29 ( V_54 , V_60 ) ;
V_64 = F_3 ( V_54 , V_12 ) ;
} while ( V_64 & V_65 );
}
static T_3 F_31 ( int V_69 , void * V_70 )
{
struct V_1 * V_71 = V_70 ;
F_32 ( & V_71 -> V_38 ) ;
F_30 ( V_71 ) ;
F_33 ( & V_71 -> V_38 ) ;
return V_72 ;
}
static int F_34 ( struct V_1 * V_71 )
{
if ( ( V_71 -> V_73 = F_35 ( V_13 , 3 , L_1 ) ) == NULL ) {
F_36 ( V_74 L_2 , V_13 ) ;
return - V_75 ;
}
V_71 -> V_13 = V_13 ;
if ( F_37 ( V_69 , F_31 , 0 , L_3 , V_71 ) ) {
F_36 ( V_74 L_4 , V_69 ) ;
return - V_75 ;
}
V_71 -> V_69 = V_69 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_36 >= 0 && V_29 -> V_36 < V_2 -> V_4 )
sprintf ( V_29 -> V_76 , L_5 , ( V_29 -> V_36 % V_2 -> V_4 ) + 1 ) ;
else if ( V_29 -> V_36 >= 8 && V_29 -> V_36 < V_2 -> V_4 * 2 )
sprintf ( V_29 -> V_76 , L_6 , ( V_29 -> V_36 % V_2 -> V_4 ) + 1 ) ;
else if ( V_29 -> V_36 == V_2 -> V_4 * 2 )
strcpy ( V_29 -> V_76 , L_7 ) ;
else if ( V_29 -> V_36 == V_2 -> V_4 * 2 + 1 )
strcpy ( V_29 -> V_76 , L_8 ) ;
else
strcpy ( V_29 -> V_76 , L_9 ) ;
}
static int F_39 ( struct V_1 * V_71 )
{
int V_11 ;
struct V_77 * V_78 ;
struct V_28 * V_29 ;
struct V_79 * V_80 ;
if ( V_81 < 1 )
V_81 = 1 ;
else if ( V_81 > 8 )
V_81 = 8 ;
V_71 -> V_4 = V_81 ;
if ( ( V_11 = F_40 ( V_71 -> V_82 , L_10 , 0 ,
V_71 -> V_4 * 2 + V_9 + 1 ,
V_71 -> V_4 * 2 + V_9 + 1 ,
& V_71 -> V_33 ) ) < 0 )
return V_11 ;
V_78 = V_71 -> V_33 ;
V_78 -> V_34 = V_71 ;
F_41 (list, &rawmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams) {
V_29 = F_42 ( V_80 , struct V_28 , V_80 ) ;
F_38 ( V_71 , V_29 ) ;
V_29 -> V_83 = & V_84 ;
}
F_41 (list, &rawmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams) {
V_29 = F_42 ( V_80 , struct V_28 , V_80 ) ;
F_38 ( V_71 , V_29 ) ;
V_29 -> V_83 = & V_85 ;
V_71 -> V_35 [ V_29 -> V_36 ] . V_7 = F_1 ( V_71 , V_29 -> V_36 ) ;
}
V_78 -> V_86 |= V_87 | V_88 |
V_89 ;
sprintf ( V_78 -> V_76 , L_11 ) ;
return 0 ;
}
static void F_43 ( struct V_90 * V_82 )
{
struct V_1 * V_91 = V_82 -> V_34 ;
unsigned long V_37 ;
F_13 ( & V_91 -> V_38 , V_37 ) ;
if ( V_91 -> V_53 > 0 )
F_22 ( V_91 ) ;
F_14 ( & V_91 -> V_38 , V_37 ) ;
if ( V_91 -> V_69 >= 0 )
F_44 ( V_91 -> V_69 , ( void * ) V_91 ) ;
F_45 ( V_91 -> V_73 ) ;
}
static int F_46 ( struct V_92 * V_93 )
{
struct V_90 * V_82 ;
int V_94 ;
struct V_1 * V_25 ;
V_94 = F_47 ( V_95 , V_96 , V_97 , sizeof( * V_25 ) , & V_82 ) ;
if ( V_94 < 0 )
return V_94 ;
V_25 = V_82 -> V_34 ;
F_48 ( & V_25 -> V_38 ) ;
F_49 ( & V_25 -> V_47 ) ;
V_25 -> V_82 = V_82 ;
V_25 -> V_69 = - 1 ;
V_25 -> V_42 = 0 ;
V_25 -> V_57 = 0 ;
V_25 -> V_31 = 0xffffffff ;
F_49 ( & V_25 -> V_47 ) ;
V_25 -> V_47 . V_98 = F_19 ;
V_25 -> V_47 . V_46 = ( unsigned long ) V_25 ;
V_82 -> V_99 = F_43 ;
V_94 = F_39 ( V_25 ) ;
if ( V_94 < 0 )
goto V_100;
V_25 -> V_56 = V_25 -> V_4 + V_9 ;
V_94 = F_34 ( V_25 ) ;
if ( V_94 < 0 )
goto V_100;
strcpy ( V_82 -> V_101 , L_12 ) ;
strcpy ( V_82 -> V_102 , L_13 ) ;
snprintf ( V_82 -> V_103 , sizeof( V_82 -> V_103 ) ,
L_14 , V_13 ) ;
F_15 ( V_25 ) ;
F_50 ( V_82 , & V_93 -> V_93 ) ;
V_94 = F_51 ( V_25 -> V_82 ) ;
if ( V_94 < 0 )
goto V_100;
F_52 ( V_93 , V_82 ) ;
F_53 ( V_104 L_15 , V_69 , V_13 ) ;
return 0 ;
V_100:
F_54 ( V_82 ) ;
return V_94 ;
}
static int F_55 ( struct V_92 * V_105 )
{
F_54 ( F_56 ( V_105 ) ) ;
return 0 ;
}
static int T_4 F_57 ( void )
{
int V_94 ;
if ( ( V_94 = F_58 ( & V_106 ) ) < 0 )
return V_94 ;
V_107 = F_59 ( V_108 , - 1 , NULL , 0 ) ;
if ( ! F_60 ( V_107 ) ) {
if ( F_56 ( V_107 ) )
return 0 ;
F_61 ( V_107 ) ;
V_94 = - V_109 ;
} else
V_94 = F_62 ( V_107 ) ;
F_63 ( & V_106 ) ;
return V_94 ;
}
static void T_5 F_64 ( void )
{
F_61 ( V_107 ) ;
F_63 ( & V_106 ) ;
}
