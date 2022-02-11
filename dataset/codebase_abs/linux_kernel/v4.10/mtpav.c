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
F_20 ( & V_2 -> V_47 , 1 + V_48 ) ;
for ( V_8 = 0 ; V_8 <= V_2 -> V_4 * 2 + V_9 ; V_8 ++ ) {
struct V_26 * V_27 = & V_2 -> V_35 [ V_8 ] ;
if ( ( V_27 -> V_39 & V_49 ) && V_27 -> V_50 )
F_10 ( V_2 , V_27 , V_27 -> V_50 ) ;
}
F_14 ( & V_2 -> V_38 , V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_47 , 1 + V_48 ) ;
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
V_27 -> V_39 |= V_51 ;
V_27 -> V_50 = V_29 ;
F_14 ( & V_25 -> V_38 , V_37 ) ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 )
{
struct V_1 * V_25 = V_29 -> V_33 -> V_34 ;
struct V_26 * V_27 = & V_25 -> V_35 [ V_29 -> V_36 ] ;
unsigned long V_37 ;
F_13 ( & V_25 -> V_38 , V_37 ) ;
V_27 -> V_39 &= ~ V_51 ;
V_27 -> V_50 = NULL ;
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
if ( ! ( V_27 -> V_39 & V_49 ) ) {
if ( V_25 -> V_52 ++ == 0 )
F_21 ( V_25 ) ;
V_27 -> V_39 |= V_49 ;
}
} else {
V_27 -> V_39 &= ~ V_49 ;
if ( -- V_25 -> V_52 == 0 )
F_22 ( V_25 ) ;
}
F_14 ( & V_25 -> V_38 , V_37 ) ;
if ( V_44 )
F_12 ( V_29 ) ;
}
static void F_27 ( struct V_1 * V_53 , T_1 V_54 )
{
struct V_26 * V_27 ;
if ( ( int ) V_53 -> V_55 > V_53 -> V_4 * 2 + V_9 )
return;
V_27 = & V_53 -> V_35 [ V_53 -> V_55 ] ;
if ( V_27 -> V_39 & V_45 )
F_28 ( V_27 -> V_41 , & V_54 , 1 ) ;
}
static void F_29 ( struct V_1 * V_53 , T_1 V_54 )
{
if ( V_54 >= 0xf8 ) {
F_27 ( V_53 , V_54 ) ;
return;
}
if ( V_53 -> V_56 == 0 ) {
if ( V_54 == 0xf5 )
V_53 -> V_56 = 1 ;
else
F_27 ( V_53 , V_54 ) ;
} else if ( V_53 -> V_56 ) {
V_53 -> V_55 = F_2 ( V_53 , V_54 ) ;
V_53 -> V_56 = 0 ;
}
}
static void F_30 ( struct V_1 * V_53 )
{
T_1 V_57 , V_58 ;
T_1 V_59 ;
T_1 V_60 , V_61 ;
int V_62 ;
T_1 V_63 = F_3 ( V_53 , V_12 ) ;
if ( ! ( V_63 & V_64 ) )
return;
V_61 = F_3 ( V_53 , V_14 ) ;
V_57 = V_61 & ( V_65 ^ 0xff ) ;
V_58 = V_61 | V_65 ;
do {
V_59 = 0 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
F_5 ( V_53 , V_14 , V_58 ) ;
V_60 = F_3 ( V_53 , V_12 ) ;
F_5 ( V_53 , V_14 , V_57 ) ;
V_60 &= V_66 | V_67 ;
V_60 >>= 4 ;
V_59 |= V_60 << ( V_62 * 2 ) ;
}
F_29 ( V_53 , V_59 ) ;
V_63 = F_3 ( V_53 , V_12 ) ;
} while ( V_63 & V_64 );
}
static T_3 F_31 ( int V_68 , void * V_69 )
{
struct V_1 * V_70 = V_69 ;
F_32 ( & V_70 -> V_38 ) ;
F_30 ( V_70 ) ;
F_33 ( & V_70 -> V_38 ) ;
return V_71 ;
}
static int F_34 ( struct V_1 * V_70 )
{
if ( ( V_70 -> V_72 = F_35 ( V_13 , 3 , L_1 ) ) == NULL ) {
F_36 ( V_73 L_2 , V_13 ) ;
return - V_74 ;
}
V_70 -> V_13 = V_13 ;
if ( F_37 ( V_68 , F_31 , 0 , L_3 , V_70 ) ) {
F_36 ( V_73 L_4 , V_68 ) ;
return - V_74 ;
}
V_70 -> V_68 = V_68 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_36 >= 0 && V_29 -> V_36 < V_2 -> V_4 )
sprintf ( V_29 -> V_75 , L_5 , ( V_29 -> V_36 % V_2 -> V_4 ) + 1 ) ;
else if ( V_29 -> V_36 >= 8 && V_29 -> V_36 < V_2 -> V_4 * 2 )
sprintf ( V_29 -> V_75 , L_6 , ( V_29 -> V_36 % V_2 -> V_4 ) + 1 ) ;
else if ( V_29 -> V_36 == V_2 -> V_4 * 2 )
strcpy ( V_29 -> V_75 , L_7 ) ;
else if ( V_29 -> V_36 == V_2 -> V_4 * 2 + 1 )
strcpy ( V_29 -> V_75 , L_8 ) ;
else
strcpy ( V_29 -> V_75 , L_9 ) ;
}
static int F_39 ( struct V_1 * V_70 )
{
int V_11 ;
struct V_76 * V_77 ;
struct V_28 * V_29 ;
struct V_78 * V_79 ;
if ( V_80 < 1 )
V_80 = 1 ;
else if ( V_80 > 8 )
V_80 = 8 ;
V_70 -> V_4 = V_80 ;
if ( ( V_11 = F_40 ( V_70 -> V_81 , L_10 , 0 ,
V_70 -> V_4 * 2 + V_9 + 1 ,
V_70 -> V_4 * 2 + V_9 + 1 ,
& V_70 -> V_33 ) ) < 0 )
return V_11 ;
V_77 = V_70 -> V_33 ;
V_77 -> V_34 = V_70 ;
F_41 (list, &rawmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams) {
V_29 = F_42 ( V_79 , struct V_28 , V_79 ) ;
F_38 ( V_70 , V_29 ) ;
V_29 -> V_82 = & V_83 ;
}
F_41 (list, &rawmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams) {
V_29 = F_42 ( V_79 , struct V_28 , V_79 ) ;
F_38 ( V_70 , V_29 ) ;
V_29 -> V_82 = & V_84 ;
V_70 -> V_35 [ V_29 -> V_36 ] . V_7 = F_1 ( V_70 , V_29 -> V_36 ) ;
}
V_77 -> V_85 |= V_86 | V_87 |
V_88 ;
sprintf ( V_77 -> V_75 , L_11 ) ;
return 0 ;
}
static void F_43 ( struct V_89 * V_81 )
{
struct V_1 * V_90 = V_81 -> V_34 ;
unsigned long V_37 ;
F_13 ( & V_90 -> V_38 , V_37 ) ;
if ( V_90 -> V_52 > 0 )
F_22 ( V_90 ) ;
F_14 ( & V_90 -> V_38 , V_37 ) ;
if ( V_90 -> V_68 >= 0 )
F_44 ( V_90 -> V_68 , ( void * ) V_90 ) ;
F_45 ( V_90 -> V_72 ) ;
}
static int F_46 ( struct V_91 * V_92 )
{
struct V_89 * V_81 ;
int V_93 ;
struct V_1 * V_25 ;
V_93 = F_47 ( & V_92 -> V_92 , V_94 , V_95 , V_96 ,
sizeof( * V_25 ) , & V_81 ) ;
if ( V_93 < 0 )
return V_93 ;
V_25 = V_81 -> V_34 ;
F_48 ( & V_25 -> V_38 ) ;
V_25 -> V_81 = V_81 ;
V_25 -> V_68 = - 1 ;
V_25 -> V_42 = 0 ;
V_25 -> V_56 = 0 ;
V_25 -> V_31 = 0xffffffff ;
F_49 ( & V_25 -> V_47 , F_19 ,
( unsigned long ) V_25 ) ;
V_81 -> V_97 = F_43 ;
V_93 = F_39 ( V_25 ) ;
if ( V_93 < 0 )
goto V_98;
V_25 -> V_55 = V_25 -> V_4 + V_9 ;
V_93 = F_34 ( V_25 ) ;
if ( V_93 < 0 )
goto V_98;
strcpy ( V_81 -> V_99 , L_12 ) ;
strcpy ( V_81 -> V_100 , L_13 ) ;
snprintf ( V_81 -> V_101 , sizeof( V_81 -> V_101 ) ,
L_14 , V_13 ) ;
F_15 ( V_25 ) ;
V_93 = F_50 ( V_25 -> V_81 ) ;
if ( V_93 < 0 )
goto V_98;
F_51 ( V_92 , V_81 ) ;
F_52 ( V_102 L_15 , V_68 , V_13 ) ;
return 0 ;
V_98:
F_53 ( V_81 ) ;
return V_93 ;
}
static int F_54 ( struct V_91 * V_103 )
{
F_53 ( F_55 ( V_103 ) ) ;
return 0 ;
}
static int T_4 F_56 ( void )
{
int V_93 ;
if ( ( V_93 = F_57 ( & V_104 ) ) < 0 )
return V_93 ;
V_105 = F_58 ( V_106 , - 1 , NULL , 0 ) ;
if ( ! F_59 ( V_105 ) ) {
if ( F_55 ( V_105 ) )
return 0 ;
F_60 ( V_105 ) ;
V_93 = - V_107 ;
} else
V_93 = F_61 ( V_105 ) ;
F_62 ( & V_104 ) ;
return V_93 ;
}
static void T_5 F_63 ( void )
{
F_60 ( V_105 ) ;
F_62 ( & V_104 ) ;
}
