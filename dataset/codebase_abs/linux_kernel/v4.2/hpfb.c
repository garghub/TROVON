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
static int F_12 ( unsigned long V_55 , unsigned long V_56 )
{
unsigned long V_57 , V_58 , V_59 , V_60 ;
int V_61 ;
V_14 = V_56 ;
V_57 = ( F_8 ( V_14 + V_62 ) << 8 ) | F_8 ( V_14 + V_63 ) ;
V_6 . V_64 . V_65 = ( F_8 ( V_14 + V_57 ) << 16 ) ;
if ( V_55 >= V_66 ) {
V_6 . V_64 . V_65 += V_55 ;
}
if ( F_13 ( V_14 ) != V_67 ) {
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
V_58 = ( F_8 ( V_14 + V_68 ) << 8 ) | F_8 ( V_14 + V_69 ) ;
V_6 . V_64 . V_70 = V_58 ;
V_59 = ( F_8 ( V_14 + V_71 ) << 8 ) | F_8 ( V_14 + V_72 ) ;
V_6 . V_64 . V_73 = V_58 * V_59 ;
V_60 = ( unsigned long ) F_14 ( V_6 . V_64 . V_65 ,
V_6 . V_64 . V_73 ) ;
V_74 . V_75 = ( F_8 ( V_14 + V_76 ) << 8 ) | F_8 ( V_14 + V_77 ) ;
V_74 . V_78 = ( F_8 ( V_14 + V_79 ) << 8 ) | F_8 ( V_14 + V_80 ) ;
V_74 . V_81 = V_74 . V_75 ;
V_74 . V_82 = V_74 . V_78 ;
V_74 . V_83 = F_8 ( V_14 + V_84 ) ;
F_15 ( V_85 L_1 ,
V_6 . V_64 . V_65 , V_60 , V_6 . V_64 . V_73 / 1024 ) ;
F_15 ( V_85 L_2 ,
V_74 . V_75 , V_74 . V_78 , V_74 . V_83 , V_6 . V_64 . V_70 ) ;
F_6 ( V_14 + V_25 , 0xff ) ;
F_6 ( V_14 + V_54 , V_42 ) ;
F_6 ( V_14 + V_24 , 0xff ) ;
F_6 ( V_60 , 0xff ) ;
V_17 = F_8 ( V_60 ) ;
F_6 ( V_60 , 0 ) ;
F_6 ( V_14 + V_25 , V_17 ) ;
F_6 ( V_14 + V_54 , V_42 ) ;
F_6 ( V_14 + V_86 , V_17 ) ;
F_6 ( V_14 + V_24 , V_17 ) ;
F_7 ( 0 , 0 , 0 , 0 , V_58 , V_59 , V_52 ) ;
if ( F_13 ( V_14 ) == V_67 )
strcat ( V_6 . V_64 . V_87 , L_3 ) ;
else
strcat ( V_6 . V_64 . V_87 , L_4 ) ;
V_6 . V_88 = & V_89 ;
V_6 . V_90 = V_91 ;
V_6 . V_92 = V_74 ;
V_6 . V_93 = ( char * ) V_60 ;
V_61 = F_16 ( & V_6 . V_12 , 1 << V_74 . V_83 , 0 ) ;
if ( V_61 < 0 )
goto V_94;
V_61 = F_17 ( & V_6 ) ;
if ( V_61 < 0 )
goto V_95;
V_6 ( & V_6 , L_5 , V_6 . V_64 . V_87 ) ;
return 0 ;
V_95:
F_18 ( & V_6 . V_12 ) ;
V_94:
if ( V_6 . V_93 ) {
F_19 ( V_6 . V_93 ) ;
V_6 . V_93 = NULL ;
}
return V_61 ;
}
static int F_20 ( struct V_96 * V_97 , const struct V_98 * V_99 )
{
unsigned long V_100 , V_101 ;
V_100 = V_97 -> V_102 . V_103 ;
if ( ! F_21 ( V_97 -> V_102 . V_103 , F_22 ( & V_97 -> V_102 ) , V_97 -> V_104 ) )
return - V_105 ;
if ( V_97 -> V_106 >= V_107 ) {
V_101 = ( unsigned long ) F_23 ( V_100 , F_22 ( & V_97 -> V_102 ) ) ;
} else {
V_101 = V_100 + V_108 ;
}
F_15 ( V_85 L_6
L_7 , V_97 -> V_106 , ( V_97 -> V_87 >> 8 ) & 0xff ) ;
if ( F_12 ( V_100 , V_101 ) ) {
if ( V_97 -> V_106 >= V_107 )
F_19 ( ( void * ) V_101 ) ;
return - V_109 ;
}
return 0 ;
}
static void F_24 ( struct V_96 * V_97 )
{
F_25 ( & V_6 ) ;
if ( V_97 -> V_106 >= V_107 )
F_19 ( ( void * ) V_14 ) ;
F_26 ( V_97 -> V_102 . V_103 , F_22 ( & V_97 -> V_102 ) ) ;
F_18 ( & V_6 . V_12 ) ;
if ( V_6 . V_93 )
F_19 ( V_6 . V_93 ) ;
}
int T_2 F_27 ( void )
{
unsigned int V_110 ;
T_3 V_111 ;
unsigned char V_112 ;
int V_113 ;
#define F_28 0xf0560000
#define F_29 0x560000
if ( ! V_114 )
return - V_115 ;
if ( F_30 ( L_8 , NULL ) )
return - V_115 ;
V_113 = F_31 ( & V_116 ) ;
if ( V_113 )
return V_113 ;
V_111 = F_32 () ;
F_33 ( V_117 ) ;
V_113 = F_34 ( V_112 , ( unsigned char * ) F_28 + V_118 ) ;
F_33 ( V_111 ) ;
if ( ! V_113 && ( V_112 == V_119 ) && F_35 ( V_110 = F_13 ( F_28 ) ) ) {
if ( ! F_21 ( F_29 , V_120 , L_9 ) )
return - V_105 ;
F_15 ( V_85 L_10 , V_110 ) ;
if ( F_12 ( F_29 , F_28 ) ) {
return - V_109 ;
}
}
return 0 ;
}
void T_4 F_36 ( void )
{
F_37 ( & V_116 ) ;
}
