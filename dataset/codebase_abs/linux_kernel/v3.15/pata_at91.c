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
struct V_34 V_35 ;
unsigned int V_36 ;
unsigned int V_13 ;
unsigned int V_11 ;
unsigned int V_12 ;
unsigned int V_14 ;
unsigned int V_37 ;
unsigned long V_24 ;
V_36 = ( V_31 -> V_38 < V_39 ) ? 30 : 20 ;
V_24 = F_9 ( V_29 -> V_40 ) ;
V_13 = F_7 ( V_31 -> V_41 , V_24 ) ;
V_11 = F_7 ( V_31 -> V_11 , V_24 ) ;
V_12 = F_7 ( V_31 -> V_42 , V_24 ) ;
V_37 = F_7 ( V_36 , V_24 ) ;
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
V_29 -> V_38 |= V_43 ;
if ( V_37 > 15 ) {
V_37 = 15 ;
F_4 ( V_10 , L_9 ) ;
}
F_10 ( V_10 , L_10 , V_33 , V_37 ) ;
V_35 . V_44 = V_35 . V_45 = V_11 ;
V_35 . V_46 = V_35 . V_47 = 0 ;
V_35 . V_48 = V_35 . V_49 = V_12 ;
V_35 . V_50 = V_35 . V_51 = V_14 ;
V_35 . V_52 = V_35 . V_53 = V_13 ;
V_35 . V_37 = V_37 ;
V_35 . V_38 = V_29 -> V_38 ;
F_12 ( 0 , V_29 -> V_54 , & V_35 ) ;
}
static void F_13 ( struct V_55 * V_56 , struct V_26 * V_27 )
{
struct V_28 * V_29 = V_56 -> V_57 -> V_58 ;
struct V_30 V_59 ;
int V_32 ;
V_32 = F_14 ( V_27 , V_27 -> V_60 , & V_59 , 1000 , 0 ) ;
if ( V_32 ) {
F_4 ( V_56 -> V_10 , L_11
L_12 , V_32 ) ;
V_59 = * F_15 ( V_61 ) ;
}
F_8 ( V_56 -> V_10 , V_27 , V_29 , & V_59 ) ;
}
static unsigned int F_16 ( struct V_26 * V_10 ,
unsigned char * V_62 , unsigned int V_63 , int V_64 )
{
struct V_28 * V_29 = V_10 -> V_65 -> V_56 -> V_57 -> V_58 ;
unsigned int V_66 ;
unsigned long V_67 ;
struct V_34 V_35 ;
F_17 ( V_67 ) ;
F_18 ( 0 , V_29 -> V_54 , & V_35 ) ;
V_35 . V_38 = ( V_35 . V_38 & ~ V_68 ) | V_69 ;
F_19 ( 0 , V_29 -> V_54 , & V_35 ) ;
V_66 = F_20 ( V_10 , V_62 , V_63 , V_64 ) ;
V_35 . V_38 = ( V_35 . V_38 & ~ V_68 ) | V_70 ;
F_19 ( 0 , V_29 -> V_54 , & V_35 ) ;
F_21 ( V_67 ) ;
return V_66 ;
}
static int F_22 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_23 ( & V_72 -> V_10 ) ;
struct V_9 * V_10 = & V_72 -> V_10 ;
struct V_28 * V_29 ;
struct V_75 * V_76 ;
struct V_77 * V_57 ;
struct V_55 * V_56 ;
int V_78 = 0 ;
int V_79 = 0 ;
int V_32 ;
if ( V_72 -> V_80 != 1 ) {
F_5 ( & V_72 -> V_10 , L_13 ) ;
return - V_81 ;
}
V_76 = F_24 ( V_72 , V_82 , 0 ) ;
if ( ! V_76 ) {
F_5 ( V_10 , L_14 ) ;
return - V_81 ;
}
V_79 = V_74 -> V_83 ;
V_57 = F_25 ( V_10 , 1 ) ;
if ( ! V_57 )
return - V_84 ;
V_56 = V_57 -> V_85 [ 0 ] ;
V_56 -> V_86 = & V_87 ;
V_56 -> V_67 |= V_88 ;
V_56 -> V_89 = V_90 ;
if ( ! F_26 ( V_79 ) ) {
V_56 -> V_67 |= V_91 ;
F_27 ( V_56 , L_15 ) ;
}
V_29 = F_28 ( V_10 , sizeof( * V_29 ) , V_92 ) ;
if ( ! V_29 ) {
F_5 ( V_10 , L_16 ) ;
return - V_84 ;
}
V_29 -> V_40 = F_29 ( NULL , L_17 ) ;
if ( F_30 ( V_29 -> V_40 ) ) {
F_5 ( V_10 , L_18 ) ;
return - V_93 ;
}
V_29 -> V_54 = V_74 -> V_94 ;
V_29 -> V_38 = V_95 | V_96 |
V_43 | V_97 |
V_70 | F_31 ( 0 ) ;
V_29 -> V_98 = F_32 ( V_10 ,
V_76 -> V_99 + V_100 , V_101 ) ;
if ( ! V_29 -> V_98 ) {
F_5 ( V_10 , L_19 ) ;
V_32 = - V_84 ;
goto V_102;
}
V_29 -> V_103 = F_32 ( V_10 ,
V_76 -> V_99 + V_104 , V_101 ) ;
if ( ! V_29 -> V_103 ) {
F_5 ( V_10 , L_20 ) ;
V_32 = - V_84 ;
goto V_102;
}
V_56 -> V_105 . V_106 = V_29 -> V_98 ;
V_56 -> V_105 . V_107 = V_29 -> V_103 + 0x06 ;
V_56 -> V_105 . V_108 = V_56 -> V_105 . V_107 ;
F_33 ( & V_56 -> V_105 ) ;
F_27 ( V_56 , L_21 ,
( unsigned long long ) V_76 -> V_99 + V_100 ,
( unsigned long long ) V_76 -> V_99 + V_104 ) ;
V_57 -> V_58 = V_29 ;
V_32 = F_34 ( V_57 , F_26 ( V_79 ) ? F_35 ( V_79 ) : 0 ,
F_26 ( V_79 ) ? V_109 : NULL ,
V_78 , & V_110 ) ;
if ( V_32 )
goto V_102;
return 0 ;
V_102:
F_36 ( V_29 -> V_40 ) ;
return V_32 ;
}
static int F_37 ( struct V_71 * V_72 )
{
struct V_77 * V_57 = F_38 ( V_72 ) ;
struct V_28 * V_29 ;
if ( ! V_57 )
return 0 ;
V_29 = V_57 -> V_58 ;
F_39 ( V_57 ) ;
if ( ! V_29 )
return 0 ;
F_36 ( V_29 -> V_40 ) ;
return 0 ;
}
