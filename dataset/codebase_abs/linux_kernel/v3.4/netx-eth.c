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
F_20 ( V_26 L_1 ,
V_2 -> V_27 ) ;
V_2 -> V_13 . V_28 ++ ;
return;
}
V_8 = F_21 ( V_4 , V_9 ) ;
F_22 ( V_8 , V_6 -> V_11 + V_18 * 1560 , V_9 ) ;
F_7 ( F_23 ( V_6 -> V_12 ) ,
F_9 ( V_19 ) | F_10 ( V_18 ) ) ;
V_4 -> V_29 = F_24 ( V_4 , V_2 ) ;
F_25 ( V_4 ) ;
V_2 -> V_13 . V_30 ++ ;
V_2 -> V_13 . V_31 += V_9 ;
}
static T_1
F_26 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_34 ;
unsigned long V_35 ;
F_27 ( & V_6 -> V_10 , V_35 ) ;
V_34 = F_28 ( F_29 ( V_6 -> V_12 ) ) ;
while ( V_34 ) {
int V_36 ;
F_30 ( V_34 , F_29 ( V_6 -> V_12 ) ) ;
if ( ( V_34 & V_37 ) || ( V_34 & V_38 ) )
F_20 ( L_2 ,
V_39 , V_34 ) ;
V_36 =
F_28 ( F_31 ( F_17 ( V_6 -> V_12 ) ) ) ;
while ( V_36 -- )
F_15 ( V_2 ) ;
if ( V_34 & V_40 )
F_32 ( V_2 ) ;
if ( V_34 & V_41 )
F_33 ( & V_6 -> V_42 , F_34 ( V_6 ) , 1 ) ;
V_34 = F_28 ( F_29 ( V_6 -> V_12 ) ) ;
}
F_35 ( & V_6 -> V_10 , V_35 ) ;
return V_43 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( F_37
( V_2 -> V_32 , F_26 , V_44 , V_2 -> V_27 , V_2 ) )
return - V_45 ;
F_30 ( V_2 -> V_46 [ 0 ] |
V_2 -> V_46 [ 1 ] << 8 |
V_2 -> V_46 [ 2 ] << 16 |
V_2 -> V_46 [ 3 ] << 24 ,
V_6 -> V_47 + V_48 + V_49 ) ;
F_30 ( V_2 -> V_46 [ 4 ] |
V_2 -> V_46 [ 5 ] << 8 ,
V_6 -> V_47 + V_48 + V_50 ) ;
F_30 ( V_51 |
V_52 |
V_53 |
V_54 |
V_55 ,
V_6 -> V_47 + V_48 +
V_56 ) ;
F_33 ( & V_6 -> V_42 , F_34 ( V_6 ) , 1 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_12 ( V_2 ) ;
F_30 ( 0 ,
V_6 -> V_47 + V_48 + V_56 ) ;
F_40 ( V_2 -> V_32 , V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_57 ;
F_20 ( V_58 L_3 , V_2 -> V_27 ) ;
F_4 ( & V_6 -> V_10 ) ;
F_42 ( V_6 -> V_59 ) ;
F_43 ( V_6 -> V_59 ) ;
for ( V_57 = 2 ; V_57 <= 18 ; V_57 ++ )
F_7 ( F_23 ( V_6 -> V_12 ) ,
F_10 ( V_57 ) | F_9 ( V_6 -> V_12 ) ) ;
F_13 ( & V_6 -> V_10 ) ;
F_32 ( V_2 ) ;
}
static int
F_44 ( struct V_1 * V_2 , int V_60 , int V_61 )
{
unsigned int V_17 ;
V_17 = V_62 | V_63 | F_45 ( V_60 ) |
F_46 ( V_61 ) | V_64 ;
F_30 ( V_17 , V_65 ) ;
while ( F_28 ( V_65 ) & V_62 ) ;
return F_28 ( V_65 ) >> 16 ;
}
static void
F_47 ( struct V_1 * V_2 , int V_60 , int V_61 , int V_66 )
{
unsigned int V_17 ;
V_17 = V_62 | V_63 | F_45 ( V_60 ) |
F_46 ( V_61 ) | V_64 | V_67 |
F_48 ( V_66 ) ;
F_30 ( V_17 , V_65 ) ;
while ( F_28 ( V_65 ) & V_62 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned int V_68 , V_69 ;
int V_70 , V_57 ;
F_50 ( V_2 ) ;
V_2 -> V_71 = & V_72 ;
V_2 -> V_73 = F_51 ( 5000 ) ;
V_6 -> V_74 = V_75 ;
V_6 -> V_42 . V_76 = 0x1f ;
V_6 -> V_42 . V_77 = 0x1f ;
V_6 -> V_42 . V_78 = 0 ;
V_6 -> V_42 . V_79 = 0 ;
V_6 -> V_42 . V_80 = V_2 ;
V_6 -> V_42 . V_81 = F_44 ;
V_6 -> V_42 . V_82 = F_47 ;
V_6 -> V_42 . V_60 = V_83 + V_6 -> V_12 ;
V_70 = F_52 ( V_6 -> V_59 ) ;
F_53 ( V_6 -> V_59 ) ;
if ( V_70 ) {
V_68 = F_28 ( V_6 -> V_47 +
V_48 + V_49 ) ;
V_69 = F_28 ( V_6 -> V_47 +
V_48 + V_50 ) ;
V_2 -> V_46 [ 0 ] = V_68 & 0xff ;
V_2 -> V_46 [ 1 ] = ( V_68 >> 8 ) & 0xff ;
V_2 -> V_46 [ 2 ] = ( V_68 >> 16 ) & 0xff ;
V_2 -> V_46 [ 3 ] = ( V_68 >> 24 ) & 0xff ;
V_2 -> V_46 [ 4 ] = V_69 & 0xff ;
V_2 -> V_46 [ 5 ] = ( V_69 >> 8 ) & 0xff ;
} else {
if ( F_54 ( V_6 -> V_59 ) ) {
F_20 ( V_84 L_4 ) ;
return - V_85 ;
}
}
F_42 ( V_6 -> V_59 ) ;
F_43 ( V_6 -> V_59 ) ;
if ( ! F_55 ( V_2 -> V_46 ) )
F_20 ( L_5
L_6 , V_2 -> V_27 ) ;
for ( V_57 = 2 ; V_57 <= 18 ; V_57 ++ )
F_7 ( F_23 ( V_6 -> V_12 ) ,
F_10 ( V_57 ) | F_9 ( V_6 -> V_12 ) ) ;
return F_56 ( V_2 ) ;
}
static int F_57 ( struct V_86 * V_87 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_88 * V_89 ;
int V_90 ;
V_2 = F_58 ( sizeof ( struct V_5 ) ) ;
if ( ! V_2 ) {
V_90 = - V_91 ;
goto exit;
}
F_59 ( V_2 , & V_87 -> V_80 ) ;
F_60 ( V_87 , V_2 ) ;
V_6 = F_3 ( V_2 ) ;
V_89 = (struct V_88 * ) V_87 -> V_80 . V_92 ;
V_6 -> V_59 = F_61 ( V_89 -> V_93 , & V_87 -> V_80 ) ;
if ( ! V_6 -> V_59 ) {
F_62 ( & V_87 -> V_80 , L_7 ) ;
V_90 = - V_85 ;
goto V_94;
}
V_2 -> V_32 = V_6 -> V_59 -> V_32 ;
V_6 -> V_12 = V_87 -> V_12 ;
V_6 -> V_47 = V_6 -> V_59 -> V_47 ;
V_6 -> V_95 = V_6 -> V_59 -> V_95 ;
V_6 -> V_11 = V_6 -> V_59 -> V_11 ;
F_63 ( & V_6 -> V_10 ) ;
V_90 = F_64 ( F_65 ( V_6 -> V_12 ) ) ;
if ( V_90 ) {
F_20 ( L_8 ) ;
goto V_96;
}
V_90 = F_49 ( V_2 ) ;
if ( V_90 )
goto V_97;
return 0 ;
V_97:
F_66 ( F_65 ( V_6 -> V_12 ) ) ;
V_96:
F_67 ( V_6 -> V_59 ) ;
V_94:
F_60 ( V_87 , NULL ) ;
F_68 ( V_2 ) ;
exit:
return V_90 ;
}
static int F_69 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_70 ( & V_87 -> V_80 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_60 ( V_87 , NULL ) ;
F_71 ( V_2 ) ;
F_53 ( V_6 -> V_59 ) ;
F_67 ( V_6 -> V_59 ) ;
F_68 ( V_2 ) ;
F_66 ( F_65 ( V_6 -> V_12 ) ) ;
return 0 ;
}
static int F_72 ( struct V_86 * V_87 , T_2 V_98 )
{
F_62 ( & V_87 -> V_80 , L_9 ) ;
return 0 ;
}
static int F_73 ( struct V_86 * V_87 )
{
F_62 ( & V_87 -> V_80 , L_10 ) ;
return 0 ;
}
static int T_3 F_74 ( void )
{
unsigned int V_99 , V_17 ;
F_20 ( L_11 ) ;
V_99 = F_75 ( V_83 >> 1 ) |
F_76 ( V_100 ) |
V_101 |
V_102 |
F_77 ( V_100 ) |
V_103 |
V_104 |
V_105 ;
V_17 = F_28 ( V_106 ) ;
F_30 ( V_17 , V_106 ) ;
F_30 ( V_99 | V_107 , V_108 ) ;
F_78 ( 100 ) ;
V_17 = F_28 ( V_106 ) ;
F_30 ( V_17 , V_106 ) ;
F_30 ( V_99 , V_108 ) ;
return F_79 ( & V_109 ) ;
}
static void T_4 F_80 ( void )
{
F_81 ( & V_109 ) ;
}
