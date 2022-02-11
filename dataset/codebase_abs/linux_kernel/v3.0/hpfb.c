static int F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 ,
struct V_6 * V_7 )
{
unsigned char V_8 = V_2 >> 8 ;
unsigned char V_9 = V_3 >> 8 ;
unsigned char V_10 = V_4 >> 8 ;
unsigned char V_11 = V_1 ;
if ( V_1 >= V_7 -> V_12 . V_13 )
return 1 ;
while ( F_2 ( V_14 + 0x6002 ) & 0x4 ) F_3 ( 1 ) ;
F_4 ( V_14 + 0x60ba , 0xff ) ;
F_4 ( V_14 + 0x60b2 , V_8 ) ;
F_4 ( V_14 + 0x60b4 , V_9 ) ;
F_4 ( V_14 + 0x60b6 , V_10 ) ;
F_4 ( V_14 + 0x60b8 , ~ V_11 ) ;
F_4 ( V_14 + 0x60f0 , 0xff ) ;
F_3 ( 100 ) ;
while ( F_2 ( V_14 + 0x6002 ) & 0x4 ) F_3 ( 1 ) ;
F_4 ( V_14 + 0x60b2 , 0 ) ;
F_4 ( V_14 + 0x60b4 , 0 ) ;
F_4 ( V_14 + 0x60b6 , 0 ) ;
F_4 ( V_14 + 0x60b8 , 0 ) ;
return 0 ;
}
static int F_5 ( int V_15 , struct V_6 * V_7 )
{
F_6 ( V_14 + V_16 , ( V_15 ? 0x00 : V_17 ) ) ;
return 0 ;
}
static void F_7 ( int V_18 , int y0 , int V_19 , int y1 , int V_20 , int V_21 , int V_22 )
{
if ( V_22 >= 0 ) {
while ( F_8 ( V_14 + V_23 ) & V_17 )
;
}
F_6 ( V_14 + V_24 , V_17 ) ;
if ( V_22 >= 0 ) {
F_6 ( V_14 + V_25 , V_17 ) ;
F_6 ( V_14 + V_26 , V_22 ) ;
}
F_4 ( V_14 + V_27 , V_18 ) ;
F_4 ( V_14 + V_28 , y0 ) ;
F_4 ( V_14 + V_29 , V_19 ) ;
F_4 ( V_14 + V_30 , y1 ) ;
F_4 ( V_14 + V_31 , V_20 ) ;
F_4 ( V_14 + V_32 , V_21 ) ;
F_6 ( V_14 + V_33 , V_17 ) ;
}
static void F_9 ( struct V_6 * V_7 , const struct V_34 * V_35 )
{
F_7 ( V_35 -> V_36 , V_35 -> V_37 , V_35 -> V_38 , V_35 -> V_39 , V_35 -> V_40 , V_35 -> V_41 , V_42 ) ;
}
static void F_10 ( struct V_6 * V_43 , const struct V_44 * V_45 )
{
T_1 V_46 ;
V_46 = V_45 -> V_47 & 0xff ;
while ( F_8 ( V_14 + V_23 ) & V_17 )
;
F_6 ( V_14 + V_25 , V_17 & V_46 ) ;
F_6 ( V_14 + V_26 , ( V_45 -> V_48 == V_49 ? V_50 : V_51 ) ) ;
F_6 ( V_14 + V_25 , V_17 & ~ V_46 ) ;
F_6 ( V_14 + V_26 , ( V_45 -> V_48 == V_49 ? V_52 : V_53 ) ) ;
F_7 ( V_45 -> V_38 , V_45 -> V_39 , V_45 -> V_38 , V_45 -> V_39 , V_45 -> V_40 , V_45 -> V_41 , - 1 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
while ( F_8 ( V_14 + V_23 ) & V_17 )
;
F_6 ( V_14 + V_25 , V_17 ) ;
F_6 ( V_14 + V_54 , V_42 ) ;
F_6 ( V_14 + V_24 , V_17 ) ;
return 0 ;
}
static int T_2 F_12 ( unsigned long V_55 ,
unsigned long V_56 )
{
unsigned long V_57 , V_58 , V_59 , V_60 ;
V_14 = V_56 ;
V_57 = ( F_8 ( V_14 + V_61 ) << 8 ) | F_8 ( V_14 + V_62 ) ;
V_6 . V_63 . V_64 = ( F_8 ( V_14 + V_57 ) << 16 ) ;
if ( V_55 >= V_65 ) {
V_6 . V_63 . V_64 += V_55 ;
}
if ( F_13 ( V_14 ) != V_66 ) {
while ( F_2 ( V_14 + 0x4800 ) & 1 )
;
F_4 ( V_14 + 0x4800 , 0 ) ;
F_4 ( V_14 + 0x4510 , 0 ) ;
F_4 ( V_14 + 0x4512 , 0 ) ;
F_4 ( V_14 + 0x4514 , 0 ) ;
F_4 ( V_14 + 0x4516 , 0 ) ;
F_4 ( V_14 + 0x4206 , 0x90 ) ;
F_4 ( V_14 + 0x60a2 , 0 ) ;
F_4 ( V_14 + 0x60bc , 0 ) ;
}
V_58 = ( F_8 ( V_14 + V_67 ) << 8 ) | F_8 ( V_14 + V_68 ) ;
V_6 . V_63 . V_69 = V_58 ;
V_59 = ( F_8 ( V_14 + V_70 ) << 8 ) | F_8 ( V_14 + V_71 ) ;
V_6 . V_63 . V_72 = V_58 * V_59 ;
V_60 = ( unsigned long ) F_14 ( V_6 . V_63 . V_64 ,
V_6 . V_63 . V_72 ) ;
V_73 . V_74 = ( F_8 ( V_14 + V_75 ) << 8 ) | F_8 ( V_14 + V_76 ) ;
V_73 . V_77 = ( F_8 ( V_14 + V_78 ) << 8 ) | F_8 ( V_14 + V_79 ) ;
V_73 . V_80 = V_73 . V_74 ;
V_73 . V_81 = V_73 . V_77 ;
V_73 . V_82 = F_8 ( V_14 + V_83 ) ;
F_15 ( V_84 L_1 ,
V_6 . V_63 . V_64 , V_60 , V_6 . V_63 . V_72 / 1024 ) ;
F_15 ( V_84 L_2 ,
V_73 . V_74 , V_73 . V_77 , V_73 . V_82 , V_6 . V_63 . V_69 ) ;
F_6 ( V_14 + V_25 , 0xff ) ;
F_6 ( V_14 + V_54 , V_42 ) ;
F_6 ( V_14 + V_24 , 0xff ) ;
F_6 ( V_60 , 0xff ) ;
V_17 = F_8 ( V_60 ) ;
F_6 ( V_60 , 0 ) ;
F_6 ( V_14 + V_25 , V_17 ) ;
F_6 ( V_14 + V_54 , V_42 ) ;
F_6 ( V_14 + V_85 , V_17 ) ;
F_6 ( V_14 + V_24 , V_17 ) ;
F_7 ( 0 , 0 , 0 , 0 , V_58 , V_59 , V_52 ) ;
if ( F_13 ( V_14 ) == V_66 )
strcat ( V_6 . V_63 . V_86 , L_3 ) ;
else
strcat ( V_6 . V_63 . V_86 , L_4 ) ;
V_6 . V_87 = & V_88 ;
V_6 . V_89 = V_90 ;
V_6 . V_91 = V_73 ;
V_6 . V_92 = ( char * ) V_60 ;
F_16 ( & V_6 . V_12 , 1 << V_73 . V_82 , 0 ) ;
if ( F_17 ( & V_6 ) < 0 ) {
F_18 ( & V_6 . V_12 ) ;
F_19 ( V_6 . V_92 ) ;
V_6 . V_92 = NULL ;
return 1 ;
}
F_15 ( V_84 L_5 ,
V_6 . V_93 , V_6 . V_63 . V_86 ) ;
return 0 ;
}
static int T_2 F_20 ( struct V_94 * V_95 , const struct V_96 * V_97 )
{
unsigned long V_98 , V_99 ;
V_98 = V_95 -> V_100 . V_101 ;
if ( ! F_21 ( V_95 -> V_100 . V_101 , F_22 ( & V_95 -> V_100 ) , V_95 -> V_102 ) )
return - V_103 ;
if ( V_95 -> V_104 >= V_105 ) {
V_99 = ( unsigned long ) F_23 ( V_98 , F_22 ( & V_95 -> V_100 ) ) ;
} else {
V_99 = V_98 + V_106 ;
}
F_15 ( V_84 L_6
L_7 , V_95 -> V_104 , ( V_95 -> V_86 >> 8 ) & 0xff ) ;
if ( F_12 ( V_98 , V_99 ) ) {
if ( V_95 -> V_104 >= V_105 )
F_19 ( ( void * ) V_99 ) ;
return - V_107 ;
}
return 0 ;
}
static void T_3 F_24 ( struct V_94 * V_95 )
{
F_25 ( & V_6 ) ;
if ( V_95 -> V_104 >= V_105 )
F_19 ( ( void * ) V_14 ) ;
F_26 ( V_95 -> V_100 . V_101 , F_22 ( & V_95 -> V_100 ) ) ;
}
int T_4 F_27 ( void )
{
unsigned int V_108 ;
T_5 V_109 ;
unsigned char V_110 ;
int V_111 ;
#define F_28 0xf0560000
#define F_29 0x560000
if ( ! V_112 )
return - V_113 ;
if ( F_30 ( L_8 , NULL ) )
return - V_113 ;
V_111 = F_31 ( & V_114 ) ;
if ( V_111 )
return V_111 ;
V_109 = F_32 () ;
F_33 ( V_115 ) ;
V_111 = F_34 ( V_110 , ( unsigned char * ) F_28 + V_116 ) ;
F_33 ( V_109 ) ;
if ( ! V_111 && ( V_110 == V_117 ) && F_35 ( V_108 = F_13 ( F_28 ) ) ) {
if ( ! F_21 ( F_29 , V_118 , L_9 ) )
return - V_103 ;
F_15 ( V_84 L_10 , V_108 ) ;
if ( F_12 ( F_29 , F_28 ) ) {
return - V_107 ;
}
}
return 0 ;
}
void T_6 F_36 ( void )
{
F_37 ( & V_114 ) ;
}
