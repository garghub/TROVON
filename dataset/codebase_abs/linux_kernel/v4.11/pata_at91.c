static int F_1 ( int * V_1 , struct V_2 * V_3 , int V_4 )
{
int V_5 = ( V_3 + V_4 - 1 ) -> V_6 ;
int V_7 ;
do {
if ( * V_1 < V_3 -> V_8 ) {
V_7 = V_3 -> V_8 - * V_1 ;
* V_1 = V_3 -> V_8 ;
return V_7 ;
} else if ( ( V_3 -> V_8 <= * V_1 ) && ( * V_1 <= V_3 -> V_6 ) )
return 0 ;
V_3 ++ ;
} while ( -- V_4 );
* V_1 = V_5 ;
return - 1 ;
}
static int F_2 ( struct V_9 * V_10 ,
int * V_11 , int * V_12 , int * V_13 , int * V_14 )
{
int V_15 ;
int V_16 = 0 ;
struct V_2 V_17 [] = {
{ . V_8 = 0 , . V_6 = 31 } ,
{ . V_8 = 128 , . V_6 = 159 }
} ;
struct V_2 V_18 [] = {
{ . V_8 = 0 , . V_6 = 63 } ,
{ . V_8 = 256 , . V_6 = 319 }
} ;
struct V_2 V_19 [] = {
{ . V_8 = 0 , . V_6 = 127 } ,
{ . V_8 = 256 , . V_6 = 383 } ,
{ . V_8 = 512 , . V_6 = 639 } ,
{ . V_8 = 768 , . V_6 = 895 }
} ;
V_15 = F_1 ( V_11 , V_17 , F_3 ( V_17 ) ) ;
if ( V_15 < 0 )
F_4 ( V_10 , L_1 ) ;
else
* V_13 += V_15 ;
V_15 = F_1 ( V_12 , V_18 , F_3 ( V_18 ) ) ;
if ( V_15 < 0 )
F_4 ( V_10 , L_2 ) ;
else
* V_13 += V_15 ;
V_15 = F_1 ( V_13 , V_19 , F_3 ( V_19 ) ) ;
if ( V_15 < 0 )
F_4 ( V_10 , L_3 ) ;
* V_14 = * V_13 ;
if ( * V_14 > V_20 ) {
F_5 ( V_10 , L_4 ) ;
return - V_21 ;
}
V_15 = F_1 ( V_14 , V_18 ,
F_3 ( V_18 ) ) ;
if ( V_15 < 0 ) {
F_4 ( V_10 , L_5 ) ;
} else if ( V_15 != 0 ) {
* V_13 = * V_14 ;
F_4 ( V_10 , L_6 ) ;
V_16 = - V_22 ;
}
return V_16 ;
}
static void F_6 ( int * V_11 , int * V_12 , int * V_13 , int * V_14 )
{
* V_11 = ( * V_11 & 0x1f ) | ( ( * V_11 & 0x80 ) >> 2 ) ;
* V_12 = ( * V_12 & 0x3f ) | ( ( * V_12 & 0x100 ) >> 2 ) ;
* V_13 = ( * V_13 & 0x7f ) | ( ( * V_13 & 0x300 ) >> 1 ) ;
* V_14 = ( * V_14 & 0x3f ) | ( ( * V_14 & 0x100 ) >> 2 ) ;
}
static unsigned long F_7 ( unsigned long V_23 , unsigned long V_24 )
{
unsigned long V_25 ;
V_25 = ( V_24 / 10000 ) << 16 ;
V_25 /= 100000 ;
return ( V_23 * V_25 + 65536 ) >> 16 ;
}
static void F_8 ( struct V_9 * V_10 , struct V_26 * V_27 ,
struct V_28 * V_29 , const struct V_30 * V_31 )
{
int V_32 = 0 ;
int V_33 ;
unsigned int V_34 ;
unsigned int V_13 ;
unsigned int V_11 ;
unsigned int V_12 ;
unsigned int V_14 ;
unsigned int V_35 ;
unsigned long V_24 ;
V_34 = ( V_31 -> V_36 < V_37 ) ? 30 : 20 ;
V_24 = F_9 ( V_29 -> V_38 ) ;
V_13 = F_7 ( V_31 -> V_39 , V_24 ) ;
V_11 = F_7 ( V_31 -> V_11 , V_24 ) ;
V_12 = F_7 ( V_31 -> V_40 , V_24 ) ;
V_35 = F_7 ( V_34 , V_24 ) ;
do {
V_32 = F_2 ( V_10 , & V_11 , & V_12 , & V_13 , & V_14 ) ;
} while ( V_32 == - V_22 );
if ( V_32 == - V_21 )
F_5 ( V_10 , L_7 ) ;
F_10 ( V_10 , L_8 ,
V_11 , V_12 , V_13 , V_14 ) ;
F_6 ( & V_11 , & V_12 , & V_13 , & V_14 ) ;
V_33 = F_11 ( V_27 ) ;
if ( V_33 )
V_29 -> V_36 |= V_41 ;
if ( V_35 > 15 ) {
V_35 = 15 ;
F_4 ( V_10 , L_9 ) ;
}
F_10 ( V_10 , L_10 , V_33 , V_35 ) ;
F_12 ( V_42 . V_11 , V_29 -> V_43 ,
F_13 ( V_11 ) |
F_14 ( V_11 ) |
F_15 ( 0 ) |
F_16 ( 0 ) ) ;
F_12 ( V_42 . V_12 , V_29 -> V_43 ,
F_17 ( V_12 ) |
F_18 ( V_12 ) |
F_19 ( V_14 ) |
F_20 ( V_14 ) ) ;
F_12 ( V_42 . V_13 , V_29 -> V_43 ,
F_21 ( V_13 ) |
F_22 ( V_13 ) ) ;
F_12 ( V_42 . V_36 , V_29 -> V_43 , V_29 -> V_36 |
F_23 ( V_35 ) ) ;
}
static void F_24 ( struct V_44 * V_45 , struct V_26 * V_27 )
{
struct V_28 * V_29 = V_45 -> V_46 -> V_47 ;
struct V_30 V_48 ;
int V_32 ;
V_32 = F_25 ( V_27 , V_27 -> V_49 , & V_48 , 1000 , 0 ) ;
if ( V_32 ) {
F_4 ( V_45 -> V_10 , L_11
L_12 , V_32 ) ;
V_48 = * F_26 ( V_50 ) ;
}
F_8 ( V_45 -> V_10 , V_27 , V_29 , & V_48 ) ;
}
static unsigned int F_27 ( struct V_51 * V_52 ,
unsigned char * V_53 , unsigned int V_54 , int V_55 )
{
struct V_28 * V_29 = V_52 -> V_10 -> V_56 -> V_45 -> V_46 -> V_47 ;
unsigned int V_57 ;
unsigned int V_36 ;
unsigned long V_58 ;
F_28 ( V_58 ) ;
F_29 ( V_42 . V_36 , V_29 -> V_43 , & V_36 ) ;
F_12 ( V_42 . V_36 , V_29 -> V_43 , ( V_36 & ~ V_59 ) |
V_60 ) ;
V_57 = F_30 ( V_52 , V_53 , V_54 , V_55 ) ;
F_12 ( V_42 . V_36 , V_29 -> V_43 , ( V_36 & ~ V_59 ) |
V_61 ) ;
F_31 ( V_58 ) ;
return V_57 ;
}
static int F_32 ( struct V_9 * V_10 )
{
struct V_62 V_63 = F_33 ( 0 , 0 , 31 ) ;
V_63 . V_64 = 8 ;
V_63 . V_65 = V_66 ;
V_63 . V_67 = F_34 ( V_68 ) ;
V_42 . V_11 = F_35 ( V_10 , V_69 , V_63 ) ;
if ( F_36 ( V_42 . V_11 ) )
return F_37 ( V_42 . V_11 ) ;
V_63 . V_67 = F_38 ( V_68 ) ;
V_42 . V_12 = F_35 ( V_10 , V_69 , V_63 ) ;
if ( F_36 ( V_42 . V_12 ) )
return F_37 ( V_42 . V_12 ) ;
V_63 . V_67 = F_39 ( V_68 ) ;
V_42 . V_13 = F_35 ( V_10 , V_69 , V_63 ) ;
if ( F_36 ( V_42 . V_13 ) )
return F_37 ( V_42 . V_13 ) ;
V_63 . V_67 = F_40 ( V_68 ) ;
V_42 . V_36 = F_35 ( V_10 , V_69 , V_63 ) ;
return F_41 ( V_42 . V_36 ) ;
}
static int F_42 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_43 ( & V_71 -> V_10 ) ;
struct V_9 * V_10 = & V_71 -> V_10 ;
struct V_28 * V_29 ;
struct V_74 * V_75 ;
struct V_76 * V_46 ;
struct V_44 * V_45 ;
int V_77 = 0 ;
int V_78 = 0 ;
int V_32 ;
if ( V_71 -> V_79 != 1 ) {
F_5 ( & V_71 -> V_10 , L_13 ) ;
return - V_80 ;
}
V_75 = F_44 ( V_71 , V_81 , 0 ) ;
if ( ! V_75 ) {
F_5 ( V_10 , L_14 ) ;
return - V_80 ;
}
V_78 = V_73 -> V_82 ;
V_69 = F_45 ( V_71 -> V_10 . V_83 , L_15 ) ;
if ( F_36 ( V_69 ) )
return F_37 ( V_69 ) ;
V_32 = F_32 ( V_10 ) ;
if ( V_32 < 0 )
return V_32 ;
V_46 = F_46 ( V_10 , 1 ) ;
if ( ! V_46 )
return - V_84 ;
V_45 = V_46 -> V_85 [ 0 ] ;
V_45 -> V_86 = & V_87 ;
V_45 -> V_58 |= V_88 ;
V_45 -> V_89 = V_90 ;
if ( ! F_47 ( V_78 ) ) {
V_45 -> V_58 |= V_91 ;
F_48 ( V_45 , L_16 ) ;
}
V_29 = F_49 ( V_10 , sizeof( * V_29 ) , V_92 ) ;
if ( ! V_29 ) {
F_5 ( V_10 , L_17 ) ;
return - V_84 ;
}
V_29 -> V_38 = F_50 ( NULL , L_18 ) ;
if ( F_36 ( V_29 -> V_38 ) ) {
F_5 ( V_10 , L_19 ) ;
return - V_93 ;
}
V_29 -> V_43 = V_73 -> V_94 ;
V_29 -> V_36 = V_95 | V_96 |
V_41 | V_97 |
V_61 | F_23 ( 0 ) ;
V_29 -> V_98 = F_51 ( V_10 ,
V_75 -> V_99 + V_100 , V_101 ) ;
if ( ! V_29 -> V_98 ) {
F_5 ( V_10 , L_20 ) ;
V_32 = - V_84 ;
goto V_102;
}
V_29 -> V_103 = F_51 ( V_10 ,
V_75 -> V_99 + V_104 , V_101 ) ;
if ( ! V_29 -> V_103 ) {
F_5 ( V_10 , L_21 ) ;
V_32 = - V_84 ;
goto V_102;
}
V_45 -> V_105 . V_106 = V_29 -> V_98 ;
V_45 -> V_105 . V_107 = V_29 -> V_103 + 0x06 ;
V_45 -> V_105 . V_108 = V_45 -> V_105 . V_107 ;
F_52 ( & V_45 -> V_105 ) ;
F_48 ( V_45 , L_22 ,
( unsigned long long ) V_75 -> V_99 + V_100 ,
( unsigned long long ) V_75 -> V_99 + V_104 ) ;
V_46 -> V_47 = V_29 ;
V_32 = F_53 ( V_46 , F_47 ( V_78 ) ? F_54 ( V_78 ) : 0 ,
F_47 ( V_78 ) ? V_109 : NULL ,
V_77 , & V_110 ) ;
if ( V_32 )
goto V_102;
return 0 ;
V_102:
F_55 ( V_29 -> V_38 ) ;
return V_32 ;
}
static int F_56 ( struct V_70 * V_71 )
{
struct V_76 * V_46 = F_57 ( V_71 ) ;
struct V_28 * V_29 ;
if ( ! V_46 )
return 0 ;
V_29 = V_46 -> V_47 ;
F_58 ( V_46 ) ;
if ( ! V_29 )
return 0 ;
F_55 ( V_29 -> V_38 ) ;
return 0 ;
}
