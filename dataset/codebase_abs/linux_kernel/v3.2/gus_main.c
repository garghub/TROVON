int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 -> V_4 ) )
return 0 ;
return 1 ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 -> V_4 ) ;
}
static int F_5 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
V_8 -> type = V_9 ;
V_8 -> V_10 = 1 ;
V_8 -> V_11 . integer . V_12 = 0 ;
V_8 -> V_11 . integer . V_13 = 31 ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
V_15 -> V_11 . integer . V_11 [ 0 ] = V_2 -> V_16 & 31 ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned long V_17 ;
int V_18 ;
unsigned char V_19 ;
V_19 = V_15 -> V_11 . integer . V_11 [ 0 ] & 31 ;
F_9 ( & V_2 -> V_20 , V_17 ) ;
V_18 = V_2 -> V_16 != V_19 ;
V_2 -> V_16 = V_19 ;
F_10 ( V_2 , V_21 , V_2 -> V_16 ) ;
F_11 ( & V_2 -> V_20 , V_17 ) ;
return V_18 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 )
F_13 ( V_2 -> V_3 , F_14 ( & V_23 , V_2 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 . V_25 == NULL )
goto V_26;
F_16 ( V_2 ) ;
F_17 ( V_2 , 0 ) ;
V_26:
F_18 ( V_2 -> V_24 . V_27 ) ;
F_18 ( V_2 -> V_24 . V_25 ) ;
if ( V_2 -> V_24 . V_28 >= 0 )
F_19 ( V_2 -> V_24 . V_28 , ( void * ) V_2 ) ;
if ( V_2 -> V_24 . V_29 >= 0 ) {
F_20 ( V_2 -> V_24 . V_29 ) ;
F_21 ( V_2 -> V_24 . V_29 ) ;
}
if ( ! V_2 -> V_30 && V_2 -> V_24 . V_31 >= 0 ) {
F_20 ( V_2 -> V_24 . V_31 ) ;
F_21 ( V_2 -> V_24 . V_31 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
return F_15 ( V_2 ) ;
}
int F_24 ( struct V_35 * V_3 ,
unsigned long V_36 ,
int V_28 , int V_29 , int V_31 ,
int V_37 ,
int V_38 ,
int V_39 ,
int V_40 ,
struct V_1 * * V_41 )
{
struct V_1 * V_2 ;
int V_42 ;
static struct V_43 V_44 = {
. V_45 = F_23 ,
} ;
* V_41 = NULL ;
V_2 = F_25 ( sizeof( * V_2 ) , V_46 ) ;
if ( V_2 == NULL )
return - V_47 ;
F_26 ( & V_2 -> V_20 ) ;
F_26 ( & V_2 -> V_48 ) ;
F_26 ( & V_2 -> V_49 ) ;
F_26 ( & V_2 -> V_50 ) ;
F_26 ( & V_2 -> V_51 ) ;
F_26 ( & V_2 -> V_52 ) ;
F_26 ( & V_2 -> V_53 ) ;
F_27 ( & V_2 -> V_54 ) ;
V_2 -> V_24 . V_28 = - 1 ;
V_2 -> V_24 . V_29 = - 1 ;
V_2 -> V_24 . V_31 = - 1 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_24 . V_36 = V_36 ;
V_2 -> V_24 . V_55 = F_28 ( V_2 , V_56 ) ;
V_2 -> V_24 . V_57 = F_28 ( V_2 , V_58 ) ;
V_2 -> V_24 . V_59 = F_28 ( V_2 , V_60 ) ;
V_2 -> V_24 . V_61 = F_28 ( V_2 , V_62 ) ;
V_2 -> V_24 . V_63 = F_28 ( V_2 , V_64 ) ;
V_2 -> V_24 . V_65 = F_28 ( V_2 , V_66 ) ;
V_2 -> V_24 . V_67 = F_28 ( V_2 , V_68 ) ;
V_2 -> V_24 . V_69 = F_28 ( V_2 , V_70 ) ;
if ( ( V_2 -> V_24 . V_27 = F_29 ( V_36 , 16 , L_1 ) ) == NULL ) {
F_30 ( V_71 L_2 , V_36 ) ;
F_15 ( V_2 ) ;
return - V_72 ;
}
if ( ( V_2 -> V_24 . V_25 = F_29 ( V_36 + 0x100 , 12 , L_3 ) ) == NULL ) {
F_30 ( V_71 L_4 , V_36 + 0x100 ) ;
F_15 ( V_2 ) ;
return - V_72 ;
}
if ( V_28 >= 0 && F_31 ( V_28 , V_73 , 0 , L_5 , ( void * ) V_2 ) ) {
F_30 ( V_71 L_6 , V_28 ) ;
F_15 ( V_2 ) ;
return - V_72 ;
}
V_2 -> V_24 . V_28 = V_28 ;
if ( F_32 ( V_29 , L_7 ) ) {
F_30 ( V_71 L_8 , V_29 ) ;
F_15 ( V_2 ) ;
return - V_72 ;
}
V_2 -> V_24 . V_29 = V_29 ;
if ( V_31 >= 0 && V_29 != V_31 ) {
if ( F_32 ( V_31 , L_9 ) ) {
F_30 ( V_71 L_10 , V_31 ) ;
F_15 ( V_2 ) ;
return - V_72 ;
}
V_2 -> V_24 . V_31 = V_31 ;
} else {
V_2 -> V_24 . V_31 = V_2 -> V_24 . V_29 ;
V_2 -> V_30 = 1 ;
}
V_2 -> V_37 = V_37 ;
if ( V_38 < 14 )
V_38 = 14 ;
if ( V_38 > 32 )
V_38 = 32 ;
if ( V_39 < 0 )
V_39 = 0 ;
if ( V_39 > 8 )
V_39 = 8 ;
V_39 ++ ;
V_39 &= ~ 1 ;
V_2 -> V_24 . V_40 = V_40 ? 1 : 0 ;
V_2 -> V_24 . V_74 = V_38 ;
V_2 -> V_24 . V_39 = V_39 ;
V_2 -> V_24 . V_75 = 25 ;
V_2 -> V_24 . V_76 = 1 ;
if ( ( V_42 = F_33 ( V_3 , V_77 , V_2 , & V_44 ) ) < 0 ) {
F_15 ( V_2 ) ;
return V_42 ;
}
* V_41 = V_2 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_78 , V_79 , V_80 ;
unsigned char V_81 ;
F_35 ( V_2 , 0L , 0xaa ) ;
F_35 ( V_2 , 1L , 0x55 ) ;
if ( F_36 ( V_2 , 0L ) != 0xaa || F_36 ( V_2 , 1L ) != 0x55 ) {
F_30 ( V_71 L_11 , V_2 -> V_24 . V_36 ) ;
return - V_47 ;
}
for ( V_79 = 1 , V_81 = 0xab ; V_79 < 4 ; V_79 ++ , V_81 ++ ) {
V_80 = V_79 << 18 ;
F_35 ( V_2 , V_80 , V_81 ) ;
F_35 ( V_2 , V_80 + 1 , V_81 + 1 ) ;
if ( F_36 ( V_2 , V_80 ) != V_81 ||
F_36 ( V_2 , V_80 + 1 ) != V_81 + 1 ||
F_36 ( V_2 , 0L ) != 0xaa )
break;
}
#if 1
V_2 -> V_24 . V_82 = V_79 << 18 ;
#else
V_2 -> V_24 . V_82 = 256 * 1024 ;
#endif
for ( V_78 = 0 , V_80 = V_2 -> V_24 . V_82 ; V_78 < 4 ; V_78 ++ , V_80 -= 256 * 1024 ) {
V_2 -> V_24 . V_83 . V_84 [ V_78 ] . V_85 =
V_2 -> V_24 . V_83 . V_84 [ V_78 ] . V_86 = 0 ;
V_2 -> V_24 . V_83 . V_87 [ V_78 ] . V_85 = V_78 << 18 ;
V_2 -> V_24 . V_83 . V_87 [ V_78 ] . V_86 = V_80 > 0 ? 256 * 1024 : 0 ;
}
V_2 -> V_24 . V_83 . V_84 [ 0 ] . V_86 = V_2 -> V_24 . V_82 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_88 )
{
struct V_35 * V_3 ;
unsigned long V_17 ;
int V_28 , V_29 , V_31 ;
static unsigned char V_89 [ 16 ] =
{ 0 , 0 , 1 , 3 , 0 , 2 , 0 , 4 , 0 , 1 , 0 , 5 , 6 , 0 , 0 , 7 } ;
static unsigned char V_90 [ 8 ] =
{ 6 , 1 , 0 , 2 , 0 , 3 , 4 , 5 } ;
if ( F_37 ( ! V_2 ) )
return - V_91 ;
V_3 = V_2 -> V_3 ;
if ( F_37 ( ! V_3 ) )
return - V_91 ;
V_2 -> V_92 &= 0xf8 ;
V_2 -> V_92 |= 0x01 ;
if ( V_2 -> V_93 || V_2 -> V_94 ) {
V_2 -> V_92 &= ~ 1 ;
V_2 -> V_92 |= 4 ;
}
V_29 = V_2 -> V_24 . V_29 ;
V_29 = abs ( V_29 ) ;
V_29 = V_90 [ V_29 & 7 ] ;
V_31 = V_2 -> V_24 . V_31 ;
V_31 = abs ( V_31 ) ;
V_31 = V_90 [ V_31 & 7 ] ;
V_29 |= V_2 -> V_30 ? 0x40 : ( V_31 << 3 ) ;
if ( ( V_29 & 7 ) == 0 || ( V_31 & 7 ) == 0 ) {
F_30 ( V_71 L_12 ) ;
return - V_91 ;
}
V_28 = V_2 -> V_24 . V_28 ;
V_28 = abs ( V_28 ) ;
V_28 = V_89 [ V_28 & 0x0f ] ;
if ( V_28 == 0 ) {
F_30 ( V_71 L_13 ) ;
return - V_91 ;
}
V_28 |= 0x40 ;
#if 0
card->mixer.mix_ctrl_reg |= 0x10;
#endif
F_9 ( & V_2 -> V_20 , V_17 ) ;
F_38 ( 5 , F_28 ( V_2 , V_95 ) ) ;
F_38 ( V_2 -> V_92 , F_28 ( V_2 , V_96 ) ) ;
F_38 ( 0x00 , F_28 ( V_2 , V_97 ) ) ;
F_38 ( 0 , F_28 ( V_2 , V_95 ) ) ;
F_11 ( & V_2 -> V_20 , V_17 ) ;
F_39 ( 100 ) ;
F_9 ( & V_2 -> V_20 , V_17 ) ;
F_38 ( 0x00 | V_2 -> V_92 , F_28 ( V_2 , V_96 ) ) ;
F_38 ( V_29 , F_28 ( V_2 , V_97 ) ) ;
if ( V_88 ) {
F_38 ( 0x40 | V_2 -> V_92 , F_28 ( V_2 , V_96 ) ) ;
F_38 ( V_28 , F_28 ( V_2 , V_97 ) ) ;
}
F_11 ( & V_2 -> V_20 , V_17 ) ;
F_39 ( 100 ) ;
F_9 ( & V_2 -> V_20 , V_17 ) ;
F_38 ( 0x00 | V_2 -> V_92 , F_28 ( V_2 , V_96 ) ) ;
F_38 ( V_29 , F_28 ( V_2 , V_97 ) ) ;
if ( V_88 ) {
F_38 ( 0x40 | V_2 -> V_92 , F_28 ( V_2 , V_96 ) ) ;
F_38 ( V_28 , F_28 ( V_2 , V_97 ) ) ;
}
F_11 ( & V_2 -> V_20 , V_17 ) ;
F_40 ( V_2 ) ;
if ( V_88 )
V_2 -> V_92 |= 0x08 ;
else
V_2 -> V_92 &= ~ 0x08 ;
F_9 ( & V_2 -> V_20 , V_17 ) ;
F_38 ( V_2 -> V_92 , F_28 ( V_2 , V_96 ) ) ;
F_38 ( 0 , F_28 ( V_2 , V_56 ) ) ;
F_11 ( & V_2 -> V_20 , V_17 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
unsigned char V_98 , V_99 ;
struct V_35 * V_3 ;
V_3 = V_2 -> V_3 ;
F_9 ( & V_2 -> V_20 , V_17 ) ;
F_38 ( 0x20 , F_28 ( V_2 , V_95 ) ) ;
V_98 = F_42 ( F_28 ( V_2 , V_95 ) ) ;
V_99 = F_42 ( F_28 ( V_2 , V_100 ) ) ;
F_11 ( & V_2 -> V_20 , V_17 ) ;
F_43 ( L_14 , V_2 -> V_24 . V_36 , V_98 , V_99 ) ;
strcpy ( V_3 -> V_101 , L_15 ) ;
strcpy ( V_3 -> V_102 , L_16 ) ;
if ( ( V_98 != 255 && ( V_98 & 0x06 ) ) || ( V_99 >= 5 && V_99 != 255 ) ) {
if ( V_99 >= 5 && V_99 <= 9 ) {
V_2 -> V_103 = 1 ;
if ( V_99 == 5 )
V_2 -> V_104 = 1 ;
V_3 -> V_102 [ 27 ] = '3' ;
V_3 -> V_102 [ 29 ] = V_99 == 5 ? '5' : '7' ;
}
if ( V_99 >= 10 && V_99 != 255 ) {
if ( V_99 >= 10 && V_99 <= 11 ) {
strcpy ( V_3 -> V_101 , L_17 ) ;
strcpy ( V_3 -> V_102 , L_18 ) ;
V_2 -> V_105 = 1 ;
} else if ( V_99 == 0x30 ) {
strcpy ( V_3 -> V_101 , L_19 ) ;
strcpy ( V_3 -> V_102 , L_20 ) ;
V_2 -> V_22 = 1 ;
} else if ( V_99 == 0x50 ) {
strcpy ( V_3 -> V_101 , L_21 ) ;
strcpy ( V_3 -> V_102 , L_22 ) ;
V_2 -> V_94 = 1 ;
} else {
F_30 ( V_71 L_23 , V_2 -> V_24 . V_36 , V_99 , V_98 ) ;
F_30 ( V_71 L_24 ) ;
}
}
}
strcpy ( V_3 -> V_106 , V_3 -> V_102 ) ;
V_2 -> V_107 = 1 ;
F_12 ( V_2 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_42 ;
if ( ! V_2 -> V_108 ) {
if ( ( V_42 = F_41 ( V_2 ) ) < 0 ) {
F_30 ( V_71 L_25 ) ;
return V_42 ;
}
if ( ( V_42 = F_34 ( V_2 ) ) < 0 )
return V_42 ;
}
if ( ( V_42 = F_17 ( V_2 , 1 ) ) < 0 )
return V_42 ;
F_45 ( V_2 ) ;
V_2 -> V_109 = 1 ;
return 0 ;
}
static int T_1 F_46 ( void )
{
return 0 ;
}
static void T_2 F_47 ( void )
{
}
