static void F_1 ( struct V_1 * V_2 )
{
}
static int
F_2 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned char * V_7 = V_4 -> V_8 ;
unsigned int V_9 = V_4 -> V_9 ;
F_4 ( & V_6 -> V_10 ) ;
F_5 ( V_6 -> V_11 + 1560 , ( void * ) V_7 , V_9 ) ;
if ( V_9 < 60 ) {
F_6 ( V_6 -> V_11 + 1560 + V_9 , 0 , 60 - V_9 ) ;
V_9 = 60 ;
}
F_7 ( F_8 ( V_6 -> V_12 ) ,
F_9 ( V_6 -> V_12 ) |
F_10 ( 1 ) |
F_11 ( V_9 ) ) ;
V_2 -> V_13 . V_14 ++ ;
V_2 -> V_13 . V_15 += V_4 -> V_9 ;
F_12 ( V_2 ) ;
F_13 ( & V_6 -> V_10 ) ;
F_14 ( V_4 ) ;
return V_16 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned int V_17 , V_18 , V_19 , V_9 ;
unsigned char * V_8 ;
struct V_3 * V_4 ;
V_17 = F_16 ( F_17 ( V_6 -> V_12 ) ) ;
V_18 = ( V_17 & V_20 ) >> V_21 ;
V_19 = ( V_17 & V_22 ) >> V_23 ;
V_9 = ( V_17 & V_24 ) >> V_25 ;
V_4 = F_18 ( V_2 , V_9 ) ;
if ( F_19 ( V_4 == NULL ) ) {
V_2 -> V_13 . V_26 ++ ;
return;
}
V_8 = F_20 ( V_4 , V_9 ) ;
F_21 ( V_8 , V_6 -> V_11 + V_18 * 1560 , V_9 ) ;
F_7 ( F_22 ( V_6 -> V_12 ) ,
F_9 ( V_19 ) | F_10 ( V_18 ) ) ;
V_4 -> V_27 = F_23 ( V_4 , V_2 ) ;
F_24 ( V_4 ) ;
V_2 -> V_13 . V_28 ++ ;
V_2 -> V_13 . V_29 += V_9 ;
}
static T_1
F_25 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_32 ;
unsigned long V_33 ;
F_26 ( & V_6 -> V_10 , V_33 ) ;
V_32 = F_27 ( F_28 ( V_6 -> V_12 ) ) ;
while ( V_32 ) {
int V_34 ;
F_29 ( V_32 , F_28 ( V_6 -> V_12 ) ) ;
if ( ( V_32 & V_35 ) || ( V_32 & V_36 ) )
F_30 ( L_1 ,
V_37 , V_32 ) ;
V_34 =
F_27 ( F_31 ( F_17 ( V_6 -> V_12 ) ) ) ;
while ( V_34 -- )
F_15 ( V_2 ) ;
if ( V_32 & V_38 )
F_32 ( V_2 ) ;
if ( V_32 & V_39 )
F_33 ( & V_6 -> V_40 , F_34 ( V_6 ) , 1 ) ;
V_32 = F_27 ( F_28 ( V_6 -> V_12 ) ) ;
}
F_35 ( & V_6 -> V_10 , V_33 ) ;
return V_41 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( F_37
( V_2 -> V_30 , F_25 , V_42 , V_2 -> V_43 , V_2 ) )
return - V_44 ;
F_29 ( V_2 -> V_45 [ 0 ] |
V_2 -> V_45 [ 1 ] << 8 |
V_2 -> V_45 [ 2 ] << 16 |
V_2 -> V_45 [ 3 ] << 24 ,
V_6 -> V_46 + V_47 + V_48 ) ;
F_29 ( V_2 -> V_45 [ 4 ] |
V_2 -> V_45 [ 5 ] << 8 ,
V_6 -> V_46 + V_47 + V_49 ) ;
F_29 ( V_50 |
V_51 |
V_52 |
V_53 |
V_54 ,
V_6 -> V_46 + V_47 +
V_55 ) ;
F_33 ( & V_6 -> V_40 , F_34 ( V_6 ) , 1 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_12 ( V_2 ) ;
F_29 ( 0 ,
V_6 -> V_46 + V_47 + V_55 ) ;
F_40 ( V_2 -> V_30 , V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_56 ;
F_30 ( V_57 L_2 , V_2 -> V_43 ) ;
F_4 ( & V_6 -> V_10 ) ;
F_42 ( V_6 -> V_58 ) ;
F_43 ( V_6 -> V_58 ) ;
for ( V_56 = 2 ; V_56 <= 18 ; V_56 ++ )
F_7 ( F_22 ( V_6 -> V_12 ) ,
F_10 ( V_56 ) | F_9 ( V_6 -> V_12 ) ) ;
F_13 ( & V_6 -> V_10 ) ;
F_32 ( V_2 ) ;
}
static int
F_44 ( struct V_1 * V_2 , int V_59 , int V_60 )
{
unsigned int V_17 ;
V_17 = V_61 | V_62 | F_45 ( V_59 ) |
F_46 ( V_60 ) | V_63 ;
F_29 ( V_17 , V_64 ) ;
while ( F_27 ( V_64 ) & V_61 ) ;
return F_27 ( V_64 ) >> 16 ;
}
static void
F_47 ( struct V_1 * V_2 , int V_59 , int V_60 , int V_65 )
{
unsigned int V_17 ;
V_17 = V_61 | V_62 | F_45 ( V_59 ) |
F_46 ( V_60 ) | V_63 | V_66 |
F_48 ( V_65 ) ;
F_29 ( V_17 , V_64 ) ;
while ( F_27 ( V_64 ) & V_61 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned int V_67 , V_68 ;
int V_69 , V_56 ;
F_50 ( V_2 ) ;
V_2 -> V_70 = & V_71 ;
V_2 -> V_72 = F_51 ( 5000 ) ;
V_6 -> V_73 = V_74 ;
V_6 -> V_40 . V_75 = 0x1f ;
V_6 -> V_40 . V_76 = 0x1f ;
V_6 -> V_40 . V_77 = 0 ;
V_6 -> V_40 . V_78 = 0 ;
V_6 -> V_40 . V_79 = V_2 ;
V_6 -> V_40 . V_80 = F_44 ;
V_6 -> V_40 . V_81 = F_47 ;
V_6 -> V_40 . V_59 = V_82 + V_6 -> V_12 ;
V_69 = F_52 ( V_6 -> V_58 ) ;
F_53 ( V_6 -> V_58 ) ;
if ( V_69 ) {
V_67 = F_27 ( V_6 -> V_46 +
V_47 + V_48 ) ;
V_68 = F_27 ( V_6 -> V_46 +
V_47 + V_49 ) ;
V_2 -> V_45 [ 0 ] = V_67 & 0xff ;
V_2 -> V_45 [ 1 ] = ( V_67 >> 8 ) & 0xff ;
V_2 -> V_45 [ 2 ] = ( V_67 >> 16 ) & 0xff ;
V_2 -> V_45 [ 3 ] = ( V_67 >> 24 ) & 0xff ;
V_2 -> V_45 [ 4 ] = V_68 & 0xff ;
V_2 -> V_45 [ 5 ] = ( V_68 >> 8 ) & 0xff ;
} else {
if ( F_54 ( V_6 -> V_58 ) ) {
F_30 ( V_83 L_3 ) ;
return - V_84 ;
}
}
F_42 ( V_6 -> V_58 ) ;
F_43 ( V_6 -> V_58 ) ;
if ( ! F_55 ( V_2 -> V_45 ) )
F_30 ( L_4
L_5 , V_2 -> V_43 ) ;
for ( V_56 = 2 ; V_56 <= 18 ; V_56 ++ )
F_7 ( F_22 ( V_6 -> V_12 ) ,
F_10 ( V_56 ) | F_9 ( V_6 -> V_12 ) ) ;
return F_56 ( V_2 ) ;
}
static int F_57 ( struct V_85 * V_86 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
int V_89 ;
V_2 = F_58 ( sizeof ( struct V_5 ) ) ;
if ( ! V_2 ) {
V_89 = - V_90 ;
goto exit;
}
F_59 ( V_2 , & V_86 -> V_79 ) ;
F_60 ( V_86 , V_2 ) ;
V_6 = F_3 ( V_2 ) ;
V_88 = (struct V_87 * ) V_86 -> V_79 . V_91 ;
V_6 -> V_58 = F_61 ( V_88 -> V_92 , & V_86 -> V_79 ) ;
if ( ! V_6 -> V_58 ) {
F_62 ( & V_86 -> V_79 , L_6 ) ;
V_89 = - V_84 ;
goto V_93;
}
V_2 -> V_30 = V_6 -> V_58 -> V_30 ;
V_6 -> V_12 = V_86 -> V_12 ;
V_6 -> V_46 = V_6 -> V_58 -> V_46 ;
V_6 -> V_94 = V_6 -> V_58 -> V_94 ;
V_6 -> V_11 = V_6 -> V_58 -> V_11 ;
F_63 ( & V_6 -> V_10 ) ;
V_89 = F_64 ( F_65 ( V_6 -> V_12 ) ) ;
if ( V_89 ) {
F_30 ( L_7 ) ;
goto V_95;
}
V_89 = F_49 ( V_2 ) ;
if ( V_89 )
goto V_96;
return 0 ;
V_96:
F_66 ( F_65 ( V_6 -> V_12 ) ) ;
V_95:
F_67 ( V_6 -> V_58 ) ;
V_93:
F_68 ( V_2 ) ;
exit:
return V_89 ;
}
static int F_69 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_70 ( V_86 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_71 ( V_2 ) ;
F_53 ( V_6 -> V_58 ) ;
F_67 ( V_6 -> V_58 ) ;
F_68 ( V_2 ) ;
F_66 ( F_65 ( V_6 -> V_12 ) ) ;
return 0 ;
}
static int F_72 ( struct V_85 * V_86 , T_2 V_97 )
{
F_62 ( & V_86 -> V_79 , L_8 ) ;
return 0 ;
}
static int F_73 ( struct V_85 * V_86 )
{
F_62 ( & V_86 -> V_79 , L_9 ) ;
return 0 ;
}
static int T_3 F_74 ( void )
{
unsigned int V_98 , V_17 ;
F_30 ( L_10 ) ;
V_98 = F_75 ( V_82 >> 1 ) |
F_76 ( V_99 ) |
V_100 |
V_101 |
F_77 ( V_99 ) |
V_102 |
V_103 |
V_104 ;
V_17 = F_27 ( V_105 ) ;
F_29 ( V_17 , V_105 ) ;
F_29 ( V_98 | V_106 , V_107 ) ;
F_78 ( 100 ) ;
V_17 = F_27 ( V_105 ) ;
F_29 ( V_17 , V_105 ) ;
F_29 ( V_98 , V_107 ) ;
return F_79 ( & V_108 ) ;
}
static void T_4 F_80 ( void )
{
F_81 ( & V_108 ) ;
}
