static inline void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( L_1 , V_2 -> V_4 , V_3 ) ;
if ( V_2 -> type & V_5 )
F_3 ( V_2 , V_6 , ( V_3 << 4 ) | 0xE ) ;
else
F_3 ( V_2 , V_7 , ( V_3 << 2 ) | 3 ) ;
}
static void
F_4 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 ) {
case ( V_9 ) :
case ( V_10 ) :
F_1 ( V_2 , V_11 ) ;
}
F_5 ( & V_2 -> V_12 , V_13 ) ;
}
static void
F_6 ( struct V_14 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 , struct V_1 , V_12 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
case V_10 :
V_12 -> V_8 = 0 ;
F_8 ( V_12 -> V_15 , V_16 ) ;
break;
case V_17 :
V_12 -> V_8 = 3 ;
F_8 ( V_12 -> V_15 , V_18 ) ;
break;
case V_19 :
case V_20 :
V_12 -> V_8 = 3 ;
F_8 ( V_12 -> V_15 , V_21 ) ;
break;
case V_22 :
V_12 -> V_8 = 4 ;
F_8 ( V_12 -> V_15 , V_23 ) ;
break;
case V_24 :
if ( V_12 -> V_8 <= 5 ) {
V_12 -> V_8 = 5 ;
F_8 ( V_12 -> V_15 , V_25 ) ;
} else {
V_12 -> V_8 = 8 ;
F_8 ( V_12 -> V_15 , V_26 ) ;
}
break;
case V_27 :
V_12 -> V_8 = 6 ;
F_8 ( V_12 -> V_15 , V_28 ) ;
break;
case V_29 :
V_12 -> V_8 = 7 ;
F_8 ( V_12 -> V_15 , V_30 ) ;
break;
case V_31 :
V_12 -> V_8 = 7 ;
F_8 ( V_12 -> V_15 , V_32 ) ;
break;
}
F_2 ( L_2 , V_2 -> V_4 , V_12 -> V_8 ) ;
}
static void
F_9 ( struct V_1 * V_2 , int V_33 )
{
T_1 * V_34 ;
F_2 ( L_3 , V_2 -> V_4 , V_35 , V_33 ) ;
if ( ! V_2 -> V_12 . V_36 ) {
V_2 -> V_12 . V_36 = F_10 ( V_2 -> V_12 . V_37 , V_38 ) ;
if ( ! V_2 -> V_12 . V_36 ) {
F_11 ( L_4 , V_2 -> V_4 ) ;
F_3 ( V_2 , V_39 , 0x80 ) ;
return;
}
}
if ( ( V_2 -> V_12 . V_36 -> V_40 + V_33 ) >= V_2 -> V_12 . V_37 ) {
F_2 ( L_5 , V_2 -> V_4 , V_35 ,
V_2 -> V_12 . V_36 -> V_40 + V_33 ) ;
F_3 ( V_2 , V_39 , 0x80 ) ;
return;
}
V_34 = F_12 ( V_2 -> V_12 . V_36 , V_33 ) ;
V_2 -> V_41 ( V_2 -> V_12 . V_42 , V_2 -> V_43 , V_34 , V_33 ) ;
F_3 ( V_2 , V_39 , 0x80 ) ;
if ( V_2 -> V_12 . V_44 & V_45 ) {
char V_46 [ V_47 + 16 ] ;
snprintf ( V_46 , V_47 + 15 , L_6 ,
V_2 -> V_4 , V_33 ) ;
F_13 ( V_46 , V_48 , V_34 , V_33 ) ;
}
}
static void
F_14 ( struct V_1 * V_2 )
{
int V_33 , V_49 ;
T_1 * V_34 ;
if ( ! V_2 -> V_12 . V_50 )
return;
V_33 = V_2 -> V_12 . V_50 -> V_40 - V_2 -> V_12 . V_51 ;
if ( V_33 <= 0 )
return;
V_49 = 0 ;
if ( V_33 > 32 ) {
V_49 = ! 0 ;
V_33 = 32 ;
}
F_2 ( L_3 , V_2 -> V_4 , V_35 , V_33 ) ;
V_34 = V_2 -> V_12 . V_50 -> V_52 + V_2 -> V_12 . V_51 ;
V_2 -> V_12 . V_51 += V_33 ;
V_2 -> V_53 ( V_2 -> V_12 . V_42 , V_2 -> V_43 , V_34 , V_33 ) ;
F_3 ( V_2 , V_39 , V_49 ? 0x8 : 0xa ) ;
if ( F_15 ( V_54 , & V_2 -> V_12 . V_55 ) ) {
F_2 ( L_7 , V_2 -> V_4 , V_35 ) ;
F_16 ( & V_2 -> V_12 . V_56 ) ;
}
F_17 ( & V_2 -> V_12 . V_56 ) ;
V_2 -> V_12 . V_56 . V_57 = V_58 + ( ( V_59 * V_60 ) / 1000 ) ;
F_18 ( & V_2 -> V_12 . V_56 ) ;
if ( V_2 -> V_12 . V_44 & V_45 ) {
char V_46 [ V_47 + 16 ] ;
snprintf ( V_46 , V_47 + 15 , L_8 ,
V_2 -> V_4 , V_33 ) ;
F_13 ( V_46 , V_48 , V_34 , V_33 ) ;
}
}
static void
F_19 ( struct V_1 * V_2 )
{
T_1 V_61 , V_33 ;
V_61 = F_20 ( V_2 , V_62 ) ;
if ( ( V_61 & 0x70 ) != 0x20 ) {
if ( V_61 & 0x40 ) {
F_2 ( L_9 , V_2 -> V_4 ) ;
#ifdef F_21
V_2 -> V_12 . V_63 ++ ;
#endif
}
if ( ! ( V_61 & 0x20 ) ) {
F_2 ( L_10 , V_2 -> V_4 ) ;
#ifdef F_21
V_2 -> V_12 . V_64 ++ ;
#endif
}
F_3 ( V_2 , V_39 , 0x80 ) ;
if ( V_2 -> V_12 . V_36 )
F_22 ( V_2 -> V_12 . V_36 ) ;
V_2 -> V_12 . V_36 = NULL ;
} else {
V_33 = F_20 ( V_2 , V_65 ) & 0x1f ;
if ( V_33 == 0 )
V_33 = 32 ;
F_9 ( V_2 , V_33 ) ;
F_23 ( & V_2 -> V_12 ) ;
}
}
static void
F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_54 , & V_2 -> V_12 . V_55 ) )
F_16 ( & V_2 -> V_12 . V_56 ) ;
if ( V_2 -> V_12 . V_50 && V_2 -> V_12 . V_51 < V_2 -> V_12 . V_50 -> V_40 ) {
F_14 ( V_2 ) ;
} else {
if ( V_2 -> V_12 . V_50 )
F_22 ( V_2 -> V_12 . V_50 ) ;
if ( F_26 ( & V_2 -> V_12 ) )
F_14 ( V_2 ) ;
}
}
static void
F_27 ( struct V_1 * V_2 )
{
if ( F_25 ( V_54 , & V_2 -> V_12 . V_55 ) )
F_16 ( & V_2 -> V_12 . V_56 ) ;
if ( F_28 ( V_66 , & V_2 -> V_12 . V_55 ) ) {
V_2 -> V_12 . V_51 = 0 ;
F_14 ( V_2 ) ;
} else if ( V_2 -> V_12 . V_50 ) {
F_11 ( L_11 , V_2 -> V_4 ) ;
F_15 ( V_66 , & V_2 -> V_12 . V_55 ) ;
V_2 -> V_12 . V_51 = 0 ;
F_14 ( V_2 ) ;
} else {
F_11 ( L_12 , V_2 -> V_4 ) ;
if ( F_26 ( & V_2 -> V_12 ) )
F_14 ( V_2 ) ;
}
}
static void
F_29 ( struct V_1 * V_2 )
{
T_1 V_61 ;
int V_67 ;
V_61 = F_20 ( V_2 , V_68 ) ;
F_2 ( L_13 , V_2 -> V_4 , V_61 ) ;
#if V_69
if ( V_61 & 0x08 ) {
if ( ! V_2 -> V_70 ) {
V_2 -> V_70 = F_30 ( V_71 , V_38 ) ;
if ( ! V_2 -> V_70 ) {
F_11 ( L_14 ,
V_2 -> V_4 ) ;
V_2 -> V_72 &= 0xf0 ;
V_2 -> V_72 |= 0x0a ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
goto V_74;
} else
V_2 -> V_75 = 0 ;
}
if ( V_2 -> V_75 >= V_71 ) {
V_2 -> V_72 &= 0xf0 ;
V_2 -> V_72 |= 0x0a ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
V_2 -> V_75 = 0 ;
F_2 ( L_15 , V_2 -> V_4 ) ;
goto V_74;
}
V_2 -> V_70 [ V_2 -> V_75 ++ ] = F_20 ( V_2 , V_76 ) ;
F_2 ( L_16 , V_2 -> V_4 ,
V_2 -> V_70 [ V_2 -> V_75 - 1 ] ) ;
if ( V_2 -> V_75 == 1 ) {
V_2 -> V_72 |= 0x04 ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
}
}
V_74:
if ( V_61 & 0x80 ) {
if ( ! V_2 -> V_70 ) {
V_2 -> V_70 = F_30 ( V_71 , V_38 ) ;
if ( ! V_2 -> V_70 ) {
F_11 ( L_14 ,
V_2 -> V_4 ) ;
V_2 -> V_72 &= 0x0f ;
V_2 -> V_72 |= 0xa0 ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
goto V_77;
} else
V_2 -> V_75 = 0 ;
}
if ( V_2 -> V_75 >= V_71 ) {
V_2 -> V_72 &= 0x0f ;
V_2 -> V_72 |= 0xa0 ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
V_2 -> V_75 = 0 ;
F_2 ( L_15 , V_2 -> V_4 ) ;
goto V_77;
}
V_2 -> V_70 [ V_2 -> V_75 ++ ] = F_20 ( V_2 , V_78 ) ;
F_2 ( L_17 , V_2 -> V_4 ,
V_2 -> V_70 [ V_2 -> V_75 - 1 ] ) ;
V_2 -> V_72 |= 0x40 ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
}
V_77:
if ( V_61 & 0x04 ) {
V_2 -> V_72 &= 0xf0 ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
V_2 -> V_72 |= 0x0a ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
if ( V_2 -> V_79 ) {
V_67 = V_2 -> V_79 ( V_2 -> V_12 . V_42 , V_80 ,
V_2 -> V_70 , V_2 -> V_75 ) ;
if ( V_67 )
F_31 ( V_2 -> V_70 ) ;
} else {
F_11 ( L_18 ,
V_2 -> V_4 , V_2 -> V_75 ) ;
F_31 ( V_2 -> V_70 ) ;
}
V_2 -> V_70 = NULL ;
V_2 -> V_75 = 0 ;
}
if ( V_61 & 0x40 ) {
V_2 -> V_72 &= 0x0f ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
V_2 -> V_72 |= 0xa0 ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
if ( V_2 -> V_79 ) {
V_67 = V_2 -> V_79 ( V_2 -> V_12 . V_42 , V_81 ,
V_2 -> V_70 , V_2 -> V_75 ) ;
if ( V_67 )
F_31 ( V_2 -> V_70 ) ;
} else {
F_11 ( L_19 ,
V_2 -> V_4 , V_2 -> V_75 ) ;
F_31 ( V_2 -> V_70 ) ;
}
V_2 -> V_70 = NULL ;
V_2 -> V_75 = 0 ;
}
if ( V_61 & 0x02 ) {
if ( ( ! V_2 -> V_82 ) || ( V_2 -> V_83 &&
( V_2 -> V_84 >= V_2 -> V_83 ) && ! ( V_61 & 0x08 ) ) ) {
V_2 -> V_72 &= 0xf0 ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
V_2 -> V_72 |= 0x0a ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
if ( V_2 -> V_83 && ( V_2 -> V_84 >= V_2 -> V_83 ) ) {
if ( V_2 -> V_79 )
V_67 = V_2 -> V_79 ( V_2 -> V_12 . V_42 ,
V_85 , NULL , 0 ) ;
}
F_31 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
V_2 -> V_83 = 0 ;
V_2 -> V_84 = 0 ;
goto V_86;
}
if ( V_2 -> V_83 && ( V_2 -> V_84 >= V_2 -> V_83 ) ) {
if ( V_2 -> V_79 )
V_67 = V_2 -> V_79 ( V_2 -> V_12 . V_42 ,
V_85 , NULL , 0 ) ;
F_31 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
V_2 -> V_83 = 0 ;
V_2 -> V_84 = 0 ;
goto V_86;
}
F_3 ( V_2 , V_87 , V_2 -> V_82 [ V_2 -> V_84 ++ ] ) ;
F_2 ( L_20 , V_2 -> V_4 ,
V_2 -> V_82 [ V_2 -> V_84 - 1 ] ) ;
}
V_86:
if ( V_61 & 0x20 ) {
if ( ( ! V_2 -> V_82 ) || ( V_2 -> V_83 &&
( V_2 -> V_84 >= V_2 -> V_83 ) && ! ( V_61 & 0x80 ) ) ) {
V_2 -> V_72 &= 0x0f ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
V_2 -> V_72 |= 0xa0 ;
F_3 ( V_2 , V_73 , V_2 -> V_72 ) ;
if ( V_2 -> V_83 && ( V_2 -> V_84 >= V_2 -> V_83 ) ) {
if ( V_2 -> V_79 )
V_67 = V_2 -> V_79 ( V_2 -> V_12 . V_42 ,
V_88 , NULL , 0 ) ;
}
F_31 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
V_2 -> V_83 = 0 ;
V_2 -> V_84 = 0 ;
goto V_89;
}
if ( V_2 -> V_83 && ( V_2 -> V_84 >= V_2 -> V_83 ) ) {
if ( V_2 -> V_79 )
V_67 = V_2 -> V_79 ( V_2 -> V_12 . V_42 ,
V_88 , NULL , 0 ) ;
F_31 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
V_2 -> V_83 = 0 ;
V_2 -> V_84 = 0 ;
goto V_89;
}
F_3 ( V_2 , V_90 , V_2 -> V_82 [ V_2 -> V_84 ++ ] ) ;
F_2 ( L_21 , V_2 -> V_4 ,
V_2 -> V_82 [ V_2 -> V_84 - 1 ] ) ;
}
V_89:
V_61 = 0 ;
#endif
}
static void
F_32 ( struct V_1 * V_2 ) {
T_1 V_61 ;
V_61 = F_20 ( V_2 , V_91 ) ;
F_2 ( L_22 , V_2 -> V_4 , V_61 ) ;
if ( V_61 & 2 ) {
F_2 ( L_23 , V_2 -> V_4 ,
V_2 -> V_8 , ( V_61 >> 2 ) & 0xf ) ;
V_2 -> V_8 = ( V_61 >> 2 ) & 0xf ;
F_4 ( V_2 ) ;
}
if ( V_61 & 1 ) {
V_61 = F_20 ( V_2 , V_92 ) ;
F_2 ( L_24 , V_2 -> V_4 , V_61 ) ;
}
}
static void
F_33 ( struct V_1 * V_2 )
{
T_1 V_61 ;
V_61 = F_20 ( V_2 , V_93 ) ;
F_2 ( L_25 , V_2 -> V_4 , V_61 ) ;
if ( V_61 & V_94 ) {
F_2 ( L_23 , V_2 -> V_4 ,
V_2 -> V_8 , V_61 >> 4 ) ;
V_2 -> V_8 = V_61 >> 4 ;
F_4 ( V_2 ) ;
}
}
static void
F_34 ( struct V_1 * V_2 )
{
int V_33 ;
T_1 V_61 ;
V_61 = F_20 ( V_2 , V_95 ) ;
if ( ( V_61 & ( V_96 |
V_97 |
V_98 |
V_99 ) )
!= ( V_96 | V_98 ) ) {
F_2 ( L_26 , V_2 -> V_4 , V_61 ) ;
#ifdef F_21
if ( V_61 & V_98 )
V_2 -> V_12 . V_63 ++ ;
else
V_2 -> V_12 . V_64 ++ ;
#endif
F_3 ( V_2 , V_100 , V_101 ) ;
if ( V_2 -> V_12 . V_36 )
F_22 ( V_2 -> V_12 . V_36 ) ;
V_2 -> V_12 . V_36 = NULL ;
} else {
V_33 = F_20 ( V_2 , V_102 ) & 0x1f ;
if ( V_33 == 0 )
V_33 = 32 ;
F_9 ( V_2 , V_33 ) ;
if ( V_2 -> V_12 . V_36 ) {
F_35 ( V_2 -> V_12 . V_36 , V_2 -> V_12 . V_36 -> V_40 - 1 ) ;
F_2 ( L_27 , V_2 -> V_4 ,
V_2 -> V_12 . V_36 -> V_40 ) ;
F_23 ( & V_2 -> V_12 ) ;
}
}
}
T_2
F_36 ( struct V_1 * V_2 , T_1 V_61 )
{
if ( F_37 ( ! V_61 ) )
return V_103 ;
F_2 ( L_28 , V_2 -> V_4 , V_61 ) ;
if ( V_2 -> type & V_5 ) {
if ( V_61 & V_104 )
F_33 ( V_2 ) ;
if ( V_61 & V_105 ) {
V_61 = F_20 ( V_2 , V_106 ) ;
F_2 ( L_29 , V_2 -> V_4 , V_61 ) ;
if ( V_61 & V_107 ) {
F_2 ( L_30 , V_2 -> V_4 ) ;
#ifdef F_21
V_2 -> V_12 . V_108 ++ ;
#endif
F_27 ( V_2 ) ;
}
if ( V_61 & V_109 ) {
F_2 ( L_31 , V_2 -> V_4 ) ;
#ifdef F_21
V_2 -> V_12 . V_108 ++ ;
#endif
F_27 ( V_2 ) ;
}
if ( V_61 & V_110 )
F_24 ( V_2 ) ;
if ( V_61 & V_111 ) {
F_2 ( L_32 , V_2 -> V_4 ) ;
F_3 ( V_2 , V_100 , V_101 ) ;
}
if ( V_61 & V_112 )
F_34 ( V_2 ) ;
if ( V_61 & V_113 )
F_9 ( V_2 , 0x20 ) ;
}
} else {
if ( V_61 & 0x80 )
F_19 ( V_2 ) ;
if ( V_61 & 0x40 )
F_9 ( V_2 , 32 ) ;
if ( V_61 & 0x10 )
F_24 ( V_2 ) ;
if ( V_61 & 0x04 )
F_32 ( V_2 ) ;
if ( V_61 & 0x20 )
F_2 ( L_33 , V_2 -> V_4 ) ;
if ( V_61 & 0x02 )
F_2 ( L_34 , V_2 -> V_4 ) ;
if ( V_61 & 0x01 ) {
V_61 = F_20 ( V_2 , V_114 ) ;
F_2 ( L_35 , V_2 -> V_4 , V_61 ) ;
if ( V_61 & 0x80 )
F_2 ( L_31 , V_2 -> V_4 ) ;
if ( V_61 & 0x40 ) {
F_2 ( L_30 , V_2 -> V_4 ) ;
#ifdef F_21
V_2 -> V_12 . V_108 ++ ;
#endif
F_27 ( V_2 ) ;
}
if ( V_61 & 0x04 )
F_29 ( V_2 ) ;
}
}
return V_115 ;
}
static int
F_38 ( struct V_116 * V_117 , struct V_118 * V_119 )
{
struct V_120 * V_121 = F_7 ( V_117 , struct V_120 , V_122 ) ;
struct V_14 * V_12 = F_7 ( V_121 , struct V_14 , V_121 ) ;
struct V_1 * V_2 = F_7 ( V_12 , struct V_1 , V_12 ) ;
int V_67 = - V_123 ;
struct V_124 * V_125 = F_39 ( V_119 ) ;
T_3 V_126 ;
T_4 V_127 ;
switch ( V_125 -> V_128 ) {
case V_129 :
F_40 ( V_2 -> V_130 , V_127 ) ;
V_67 = F_41 ( V_12 , V_119 ) ;
if ( V_67 > 0 ) {
V_126 = V_125 -> V_126 ;
F_14 ( V_2 ) ;
V_67 = 0 ;
F_42 ( V_2 -> V_130 , V_127 ) ;
F_43 ( V_117 , V_131 , V_126 , NULL ) ;
} else
F_42 ( V_2 -> V_130 , V_127 ) ;
return V_67 ;
case V_132 :
V_67 = F_8 ( V_12 -> V_15 , V_125 -> V_128 ) ;
break;
case V_133 :
F_25 ( V_134 , & V_12 -> V_55 ) ;
V_67 = F_8 ( V_12 -> V_15 , V_125 -> V_128 ) ;
break;
}
if ( ! V_67 )
F_22 ( V_119 ) ;
return V_67 ;
}
static int
F_44 ( struct V_1 * V_2 , T_3 V_135 , unsigned long V_136 )
{
T_1 V_137 = 0 ;
unsigned long V_127 ;
int V_67 = 0 ;
switch ( V_135 ) {
case V_138 :
F_40 ( V_2 -> V_130 , V_127 ) ;
if ( ! ( V_2 -> type & V_5 ) ) {
if ( V_136 & 1 )
V_137 |= 0x0c ;
else if ( V_136 & 2 )
V_137 |= 0x3 ;
F_3 ( V_2 , V_139 , V_137 ) ;
if ( V_137 )
F_3 ( V_2 , V_140 , 0x8 ) ;
else
F_3 ( V_2 , V_140 , 0x0 ) ;
}
F_42 ( V_2 -> V_130 , V_127 ) ;
break;
case V_141 :
V_67 = F_8 ( V_2 -> V_12 . V_15 , V_141 | ( V_136 & 0xff ) ) ;
break;
default:
F_2 ( L_36 , V_2 -> V_4 ,
V_35 , V_135 , V_136 ) ;
V_67 = - 1 ;
}
return V_67 ;
}
static int
F_45 ( struct V_14 * V_12 , T_3 V_135 )
{
struct V_1 * V_2 = F_7 ( V_12 , struct V_1 , V_12 ) ;
T_4 V_127 ;
F_2 ( L_37 , V_2 -> V_4 , V_135 , V_2 -> V_8 ) ;
switch ( V_135 ) {
case V_142 :
F_40 ( V_2 -> V_130 , V_127 ) ;
F_1 ( V_2 , V_143 ) ;
F_42 ( V_2 -> V_130 , V_127 ) ;
break;
case V_144 :
F_40 ( V_2 -> V_130 , V_127 ) ;
F_1 ( V_2 , V_145 ) ;
F_42 ( V_2 -> V_130 , V_127 ) ;
break;
case V_146 :
F_40 ( V_2 -> V_130 , V_127 ) ;
if ( ( V_2 -> V_8 == V_10 ) ||
( V_2 -> V_8 == V_19 ) ||
( V_2 -> V_8 == V_20 ) ||
( V_2 -> V_8 == V_9 ) )
F_1 ( V_2 , V_147 ) ;
else
F_1 ( V_2 , V_148 ) ;
F_42 ( V_2 -> V_130 , V_127 ) ;
break;
case V_149 :
F_46 ( & V_12 -> V_150 ) ;
if ( V_12 -> V_50 ) {
F_22 ( V_12 -> V_50 ) ;
V_12 -> V_50 = NULL ;
}
V_12 -> V_51 = 0 ;
if ( V_12 -> V_36 ) {
F_22 ( V_12 -> V_36 ) ;
V_12 -> V_36 = NULL ;
}
F_25 ( V_66 , & V_12 -> V_55 ) ;
if ( F_25 ( V_54 , & V_12 -> V_55 ) )
F_16 ( & V_12 -> V_56 ) ;
break;
case V_151 :
F_40 ( V_2 -> V_130 , V_127 ) ;
F_1 ( V_2 , V_147 ) ;
F_42 ( V_2 -> V_130 , V_127 ) ;
break;
case V_152 :
F_15 ( V_153 , & V_12 -> V_55 ) ;
F_47 ( & V_12 -> V_121 . V_122 , V_135 , V_154 , 0 , NULL ,
V_38 ) ;
break;
case V_155 :
F_25 ( V_153 , & V_12 -> V_55 ) ;
F_47 ( & V_12 -> V_121 . V_122 , V_135 , V_154 , 0 , NULL ,
V_38 ) ;
break;
default:
F_2 ( L_38 , V_2 -> V_4 ,
V_35 , V_135 ) ;
return - 1 ;
}
return 0 ;
}
static void
F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> type & V_5 )
F_3 ( V_2 , V_156 , 0xff ) ;
else
F_3 ( V_2 , V_157 , 0xff ) ;
if ( V_2 -> V_12 . V_56 . V_158 != NULL ) {
F_16 ( & V_2 -> V_12 . V_56 ) ;
V_2 -> V_12 . V_56 . V_158 = NULL ;
}
F_31 ( V_2 -> V_70 ) ;
V_2 -> V_70 = NULL ;
F_31 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
if ( V_2 -> V_12 . V_15 )
F_8 ( V_2 -> V_12 . V_15 , V_159 ) ;
F_49 ( & V_2 -> V_12 ) ;
}
static void
F_50 ( struct V_1 * V_2 )
{
int V_160 , V_161 ;
T_4 V_127 ;
if ( F_28 ( V_54 , & V_2 -> V_12 . V_55 ) ) {
F_40 ( V_2 -> V_130 , V_127 ) ;
V_160 = F_20 ( V_2 , V_162 ) ;
V_161 = F_20 ( V_2 , V_163 ) ;
F_2 ( L_39 ,
V_2 -> V_4 , V_160 , V_161 ) ;
if ( V_160 & V_164 )
F_15 ( V_165 , & V_2 -> V_12 . V_55 ) ;
else {
F_25 ( V_54 , & V_2 -> V_12 . V_55 ) ;
if ( V_2 -> V_12 . V_51 )
V_2 -> V_12 . V_51 = 0 ;
else
F_11 ( L_40 ,
V_2 -> V_4 ) ;
F_3 ( V_2 , V_39 , 0x01 ) ;
}
F_42 ( V_2 -> V_130 , V_127 ) ;
}
}
static int
F_51 ( struct V_1 * V_2 , struct V_166 * V_167 , void * V_168 )
{
F_2 ( L_41 , V_2 -> V_4 , V_35 ,
V_2 -> V_12 . V_121 . V_126 , V_168 ) ;
if ( V_167 -> V_169 != V_170 )
return - V_123 ;
if ( V_167 -> V_171 . V_172 == 1 )
return - V_123 ;
V_167 -> V_117 = & V_2 -> V_12 . V_121 . V_122 ;
V_167 -> V_117 -> V_169 = V_167 -> V_169 ;
if ( V_2 -> V_12 . V_8 == 7 )
F_47 ( V_167 -> V_117 , V_152 , V_154 ,
0 , NULL , V_173 ) ;
return 0 ;
}
static int
F_52 ( struct V_1 * V_2 , struct V_166 * V_167 )
{
return F_51 ( V_2 , V_167 , F_53 ( 0 ) ) ;
}
static int
F_54 ( struct V_1 * V_2 )
{
T_1 V_61 ;
int V_174 = 0 ;
if ( ! V_2 -> V_12 . V_15 ) {
V_174 = F_55 ( & V_2 -> V_12 , F_45 ) ;
if ( V_174 )
return V_174 ;
}
V_2 -> V_82 = NULL ;
V_2 -> V_70 = NULL ;
V_2 -> V_12 . V_56 . V_158 = ( void * ) F_50 ;
V_2 -> V_12 . V_56 . V_52 = ( long ) V_2 ;
F_17 ( & V_2 -> V_12 . V_56 ) ;
V_2 -> V_72 = 0xaa ;
if ( V_2 -> type & V_5 ) {
F_3 ( V_2 , V_156 , 0xff ) ;
V_61 = F_20 ( V_2 , V_175 ) ;
F_2 ( L_42 , V_2 -> V_4 , V_61 ) ;
V_61 = F_20 ( V_2 , V_106 ) ;
F_2 ( L_43 , V_2 -> V_4 , V_61 ) ;
V_61 = F_20 ( V_2 , V_176 ) ;
F_2 ( L_44 , V_2 -> V_4 , V_61 ) ;
F_3 ( V_2 , V_177 , 0x00 ) ;
F_3 ( V_2 , V_178 , 0x00 ) ;
F_3 ( V_2 , V_179 , 0xc9 ) ;
V_61 = F_20 ( V_2 , V_180 ) ;
if ( V_2 -> V_12 . V_44 & V_181 )
F_56 ( L_45 ,
V_2 -> V_4 , V_61 & 0x3f ) ;
V_61 = F_20 ( V_2 , V_93 ) ;
F_2 ( L_25 , V_2 -> V_4 , V_61 ) ;
V_2 -> V_8 = V_61 >> 4 ;
F_4 ( V_2 ) ;
F_1 ( V_2 , V_148 ) ;
F_3 ( V_2 , V_156 , V_182 ) ;
F_3 ( V_2 , V_183 , 0x00 ) ;
} else {
F_3 ( V_2 , V_157 , 0xff ) ;
V_61 = F_20 ( V_2 , V_163 ) ;
F_2 ( L_46 , V_2 -> V_4 , V_61 ) ;
V_61 = F_20 ( V_2 , V_184 ) ;
F_2 ( L_47 , V_2 -> V_4 , V_61 ) ;
V_61 = F_20 ( V_2 , V_185 ) ;
F_2 ( L_48 , V_2 -> V_4 , V_61 ) ;
V_61 = F_20 ( V_2 , V_186 ) ;
F_2 ( L_49 , V_2 -> V_4 , V_61 ) ;
if ( V_61 & 0x01 ) {
V_61 = F_20 ( V_2 , V_114 ) ;
F_2 ( L_50 , V_2 -> V_4 , V_61 ) ;
}
V_61 = F_20 ( V_2 , V_162 ) ;
if ( V_2 -> V_12 . V_44 & V_181 )
F_56 ( L_51 , V_2 -> V_4 ,
V_61 , V_187 [ ( V_61 >> 5 ) & 3 ] ) ;
V_2 -> type |= ( ( V_61 >> 5 ) & 3 ) ;
if ( ! V_2 -> V_188 )
V_2 -> V_188 = 0x80 ;
if ( ! ( V_2 -> V_188 & 0x80 ) ) {
F_11 ( L_52 ,
V_2 -> V_4 , V_2 -> V_188 ) ;
F_48 ( V_2 ) ;
return - V_123 ;
}
F_3 ( V_2 , V_185 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_189 , 0x2f ) ;
F_3 ( V_2 , V_139 , 0x00 ) ;
F_3 ( V_2 , V_190 , 0x70 ) ;
F_3 ( V_2 , V_184 , 0xc9 ) ;
F_3 ( V_2 , V_191 , 0x00 ) ;
F_3 ( V_2 , V_140 , 0x00 ) ;
V_61 = F_20 ( V_2 , V_91 ) ;
F_2 ( L_53 , V_2 -> V_4 , V_61 ) ;
V_2 -> V_8 = ( V_61 >> 2 ) & 0xf ;
F_4 ( V_2 ) ;
F_1 ( V_2 , V_148 ) ;
F_3 ( V_2 , V_157 , 0 ) ;
}
return V_174 ;
}
int
F_57 ( struct V_1 * V_2 , void * V_42 )
{
F_58 ( & V_2 -> V_12 , V_192 , F_6 ) ;
V_2 -> V_12 . V_42 = V_42 ;
V_2 -> V_12 . V_121 . V_122 . V_193 = F_38 ;
V_2 -> V_194 = F_54 ;
V_2 -> V_195 = F_48 ;
V_2 -> V_196 = F_44 ;
V_2 -> V_197 = F_52 ;
V_2 -> V_12 . V_121 . V_198 = ( 1 << V_170 ) ;
V_2 -> V_12 . V_121 . V_199 = 2 ;
return 0 ;
}
static void
F_59 ( struct V_200 * V_201 )
{
T_1 V_202 , V_203 = 50 ;
while ( V_203 ) {
V_202 = F_60 ( V_201 , V_204 ) ;
if ( ! ( V_202 & 0x04 ) )
break;
F_61 ( 1 ) ;
V_203 -- ;
}
if ( V_203 < 50 )
F_2 ( L_54 , V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 ,
50 - V_203 ) ;
if ( ! V_203 )
F_11 ( L_55 , V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 ) ;
}
static void
F_62 ( struct V_200 * V_201 )
{
T_1 V_202 , V_203 = 50 ;
while ( V_203 ) {
V_202 = F_60 ( V_201 , V_204 ) ;
if ( ( V_202 & 0x44 ) == 0x40 )
break;
F_61 ( 1 ) ;
V_203 -- ;
}
if ( V_203 < 50 )
F_2 ( L_56 , V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 ,
50 - V_203 ) ;
if ( ! V_203 )
F_11 ( L_57 , V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 ) ;
}
static void
F_63 ( struct V_200 * V_201 , T_1 V_135 )
{
if ( V_201 -> V_205 -> type & V_208 )
F_64 ( V_201 , V_209 , V_135 ) ;
else {
F_59 ( V_201 ) ;
F_64 ( V_201 , V_210 , V_135 ) ;
}
}
static void
F_65 ( struct V_200 * V_211 , T_1 V_33 )
{
T_1 * V_212 ;
int V_37 ;
F_2 ( L_58 , V_211 -> V_205 -> V_4 , V_211 -> V_206 . V_207 , V_33 ) ;
if ( F_28 ( V_213 , & V_211 -> V_206 . V_55 ) ) {
V_211 -> V_206 . V_214 += V_33 ;
F_63 ( V_211 , 0x80 ) ;
return;
}
V_37 = F_66 ( & V_211 -> V_206 , V_33 ) ;
if ( V_37 < 0 ) {
F_63 ( V_211 , 0x80 ) ;
if ( V_211 -> V_206 . V_36 )
F_35 ( V_211 -> V_206 . V_36 , 0 ) ;
F_67 ( L_59 ,
V_211 -> V_205 -> V_4 , V_211 -> V_206 . V_207 , V_33 ) ;
return;
}
V_212 = F_12 ( V_211 -> V_206 . V_36 , V_33 ) ;
if ( V_211 -> V_205 -> type & V_208 )
V_211 -> V_205 -> V_41 ( V_211 -> V_205 -> V_42 ,
V_211 -> V_43 + V_215 , V_212 , V_33 ) ;
else
V_211 -> V_205 -> V_41 ( V_211 -> V_205 -> V_42 ,
V_211 -> V_43 , V_212 , V_33 ) ;
F_63 ( V_211 , 0x80 ) ;
if ( V_211 -> V_206 . V_44 & V_216 ) {
snprintf ( V_211 -> log , 64 , L_60 ,
V_211 -> V_206 . V_207 , V_211 -> V_205 -> V_4 , V_33 ) ;
F_13 ( V_211 -> log , V_48 , V_212 , V_33 ) ;
}
}
static void
F_68 ( struct V_200 * V_211 )
{
int V_33 , V_49 ;
T_1 * V_212 ;
if ( ! V_211 -> V_206 . V_50 ) {
if ( ! F_28 ( V_217 , & V_211 -> V_206 . V_55 ) )
return;
V_33 = V_211 -> V_218 ;
V_49 = 1 ;
V_212 = V_211 -> log ;
memset ( V_212 , V_211 -> V_206 . V_219 [ 0 ] , V_33 ) ;
} else {
V_33 = V_211 -> V_206 . V_50 -> V_40 - V_211 -> V_206 . V_51 ;
if ( V_33 <= 0 )
return;
V_212 = V_211 -> V_206 . V_50 -> V_52 + V_211 -> V_206 . V_51 ;
V_49 = F_28 ( V_220 , & V_211 -> V_206 . V_55 ) ? 1 : 0 ;
if ( V_33 > V_211 -> V_218 ) {
V_33 = V_211 -> V_218 ;
V_49 = 1 ;
}
F_2 ( L_61 , V_211 -> V_205 -> V_4 , V_211 -> V_206 . V_207 ,
V_33 , V_211 -> V_206 . V_51 , V_211 -> V_206 . V_50 -> V_40 ) ;
V_211 -> V_206 . V_51 += V_33 ;
}
if ( V_211 -> V_205 -> type & V_208 )
V_211 -> V_205 -> V_53 ( V_211 -> V_205 -> V_42 ,
V_211 -> V_43 + V_221 , V_212 , V_33 ) ;
else {
F_62 ( V_211 ) ;
V_211 -> V_205 -> V_53 ( V_211 -> V_205 -> V_42 ,
V_211 -> V_43 , V_212 , V_33 ) ;
}
F_63 ( V_211 , V_49 ? 0x08 : 0x0a ) ;
if ( V_211 -> V_206 . V_50 && ( V_211 -> V_206 . V_44 & V_216 ) ) {
snprintf ( V_211 -> log , 64 , L_62 ,
V_211 -> V_206 . V_207 , V_211 -> V_205 -> V_4 , V_33 ) ;
F_13 ( V_211 -> log , V_48 , V_212 , V_33 ) ;
}
}
static void
F_69 ( struct V_200 * V_201 )
{
if ( V_201 -> V_206 . V_50 && V_201 -> V_206 . V_51 < V_201 -> V_206 . V_50 -> V_40 ) {
F_68 ( V_201 ) ;
} else {
if ( V_201 -> V_206 . V_50 )
F_22 ( V_201 -> V_206 . V_50 ) ;
if ( F_70 ( & V_201 -> V_206 ) ) {
F_68 ( V_201 ) ;
F_25 ( V_217 , & V_201 -> V_206 . V_55 ) ;
} else if ( F_28 ( V_217 , & V_201 -> V_206 . V_55 ) ) {
F_68 ( V_201 ) ;
}
}
}
static void
F_71 ( struct V_200 * V_201 )
{
int V_33 ;
T_1 V_222 ;
if ( V_201 -> V_205 -> type & V_208 )
V_222 = F_60 ( V_201 , V_223 ) ;
else
V_222 = F_60 ( V_201 , V_224 ) ;
F_2 ( L_63 , V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 , V_222 ) ;
if ( ( V_222 & 0xf0 ) != 0xa0 ) {
if ( ! ( V_222 & 0x80 ) ) {
if ( V_201 -> V_206 . V_44 & V_225 )
F_56 ( L_64 ,
V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 ) ;
}
if ( V_222 & 0x40 ) {
if ( V_201 -> V_206 . V_44 & V_225 )
F_56 ( L_65 ,
V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 ,
V_201 -> V_206 . V_8 ) ;
}
if ( ! ( V_222 & 0x20 ) ) {
if ( V_201 -> V_206 . V_44 & V_225 )
F_56 ( L_66 ,
V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 ) ;
}
F_63 ( V_201 , 0x80 ) ;
return;
}
if ( V_201 -> V_205 -> type & V_208 )
V_33 = F_60 ( V_201 , V_226 ) ;
else
V_33 = F_60 ( V_201 , V_227 ) ;
V_33 &= ( V_201 -> V_218 - 1 ) ;
if ( V_33 == 0 )
V_33 = V_201 -> V_218 ;
F_65 ( V_201 , V_33 ) ;
if ( ! V_201 -> V_206 . V_36 )
return;
if ( V_201 -> V_206 . V_36 -> V_40 < 2 ) {
F_2 ( L_67 ,
V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 , V_201 -> V_206 . V_36 -> V_40 ) ;
F_35 ( V_201 -> V_206 . V_36 , 0 ) ;
} else {
F_35 ( V_201 -> V_206 . V_36 , V_201 -> V_206 . V_36 -> V_40 - 1 ) ;
F_72 ( & V_201 -> V_206 , 0 , false ) ;
}
}
static void
F_73 ( struct V_200 * V_201 , T_1 V_228 )
{
T_1 V_229 , V_230 , V_231 = 0 ;
if ( V_201 -> V_205 -> type & V_208 )
V_229 = F_60 ( V_201 , V_232 ) ;
else if ( V_201 -> V_205 -> type & V_233 ) {
V_229 = F_60 ( V_201 , V_234 ) ;
V_230 = ( V_201 -> V_206 . V_207 & 1 ) ? V_235 : V_236 ;
if ( V_230 & V_228 ) {
V_231 = F_60 ( V_201 , V_237 ) ;
F_2 ( L_68 , V_201 -> V_205 -> V_4 ,
V_201 -> V_206 . V_207 , V_231 ) ;
}
} else if ( V_201 -> V_206 . V_207 & 2 ) {
if ( V_228 & ( V_238 | V_239 ) )
F_73 ( & V_201 -> V_205 -> V_211 [ 0 ] , V_228 ) ;
if ( V_228 & V_240 ) {
V_231 = F_60 ( V_201 , V_237 ) ;
F_2 ( L_68 , V_201 -> V_205 -> V_4 ,
V_201 -> V_206 . V_207 , V_231 ) ;
}
V_229 = V_228 & 0xF8 ;
} else {
V_229 = F_60 ( V_201 , V_234 ) ;
if ( V_228 & V_238 ) {
V_231 = F_60 ( V_201 , V_237 ) ;
F_2 ( L_68 , V_201 -> V_205 -> V_4 ,
V_201 -> V_206 . V_207 , V_231 ) ;
}
V_229 = V_229 & 0xF8 ;
}
if ( V_231 & V_241 )
V_229 |= V_242 ;
if ( V_231 & V_243 )
V_229 |= V_244 ;
F_2 ( L_69 , V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 , V_229 ) ;
if ( ! F_28 ( V_153 , & V_201 -> V_206 . V_55 ) )
return;
if ( V_229 & V_245 )
F_71 ( V_201 ) ;
if ( V_229 & V_246 ) {
F_65 ( V_201 , V_201 -> V_218 ) ;
if ( F_28 ( V_220 , & V_201 -> V_206 . V_55 ) )
F_72 ( & V_201 -> V_206 , 0 , false ) ;
}
if ( V_229 & V_244 ) {
F_2 ( L_70 , V_201 -> V_205 -> V_4 , V_201 -> V_206 . V_207 ) ;
F_63 ( V_201 , 0x40 ) ;
}
if ( V_229 & V_247 )
F_69 ( V_201 ) ;
if ( V_229 & V_242 ) {
if ( F_28 ( V_220 , & V_201 -> V_206 . V_55 ) ) {
if ( F_28 ( V_248 , & V_201 -> V_206 . V_55 ) )
F_15 ( V_217 , & V_201 -> V_206 . V_55 ) ;
F_69 ( V_201 ) ;
return;
}
F_2 ( L_71 , V_201 -> V_205 -> V_4 ,
V_201 -> V_206 . V_207 , V_201 -> V_206 . V_51 ) ;
V_201 -> V_206 . V_51 = 0 ;
F_63 ( V_201 , 0x01 ) ;
}
}
T_2
F_74 ( struct V_249 * V_250 , int V_251 )
{
int V_252 = V_251 + 1 ;
T_1 V_228 , V_253 ;
struct V_1 * V_2 = & V_250 -> V_2 ;
if ( V_250 -> type & V_208 ) {
V_228 = F_75 ( V_250 , V_176 ) ;
while ( V_228 && -- V_252 ) {
F_2 ( L_72 , V_250 -> V_4 , V_228 ) ;
if ( V_228 & V_254 )
F_73 ( & V_250 -> V_211 [ 0 ] , V_228 ) ;
if ( V_228 & V_255 )
F_73 ( & V_250 -> V_211 [ 1 ] , V_228 ) ;
if ( V_228 & ( V_105 | V_104 ) )
F_36 ( & V_250 -> V_2 , V_228 ) ;
V_228 = F_75 ( V_250 , V_176 ) ;
}
} else if ( V_250 -> type & V_233 ) {
V_228 = F_75 ( V_250 , V_256 ) ;
while ( V_228 && -- V_252 ) {
F_2 ( L_72 , V_250 -> V_4 , V_228 ) ;
if ( V_228 & ( V_257 | V_258 ) ) {
V_253 = F_20 ( V_2 , V_186 ) ;
F_2 ( L_29 , V_250 -> V_4 , V_253 ) ;
if ( V_253 & V_259 )
F_2 ( L_73 , V_250 -> V_4 ) ;
if ( V_228 & V_258 )
V_253 |= 1 ;
F_36 ( V_2 , V_253 ) ;
}
if ( V_228 & ( V_260 | V_235 ) )
F_73 ( & V_250 -> V_211 [ 0 ] , V_228 ) ;
if ( V_228 & ( V_261 | V_236 ) )
F_73 ( & V_250 -> V_211 [ 1 ] , V_228 ) ;
V_228 = F_75 ( V_250 , V_256 ) ;
}
} else if ( V_250 -> type & V_262 ) {
while ( -- V_252 ) {
V_228 = F_75 ( V_250 , V_234 + V_250 -> V_211 [ 1 ] . V_43 ) ;
F_2 ( L_74 , V_250 -> V_4 , V_228 ) ;
if ( V_228 )
F_73 ( & V_250 -> V_211 [ 1 ] , V_228 ) ;
V_253 = F_20 ( V_2 , V_186 ) ;
F_2 ( L_29 , V_250 -> V_4 , V_253 ) ;
if ( V_253 )
F_36 ( V_2 , V_253 ) ;
if ( 0 == ( V_228 | V_253 ) )
break;
}
}
if ( V_252 > V_251 )
return V_103 ;
if ( V_252 < V_251 )
F_2 ( L_75 , V_250 -> V_4 ,
V_251 - V_252 , F_76 () ) ;
if ( V_251 && ! V_252 )
F_56 ( L_76 , V_250 -> V_4 ,
V_251 , F_76 () ) ;
return V_115 ;
}
static int
F_77 ( struct V_200 * V_211 , T_3 V_263 )
{
F_2 ( L_77 , V_211 -> V_205 -> V_4 ,
'@' + V_211 -> V_206 . V_207 , V_211 -> V_206 . V_8 , V_263 , V_211 -> V_206 . V_207 ) ;
if ( V_211 -> V_205 -> type & V_208 ) {
if ( V_211 -> V_206 . V_207 & 1 ) {
F_78 ( V_211 -> V_205 , V_264 , 0x80 ) ;
F_78 ( V_211 -> V_205 , V_265 , 0x88 ) ;
} else {
F_78 ( V_211 -> V_205 , V_266 , 0x81 ) ;
F_78 ( V_211 -> V_205 , V_267 , 0x88 ) ;
}
switch ( V_263 ) {
case V_268 :
F_64 ( V_211 , V_269 , 0xC0 ) ;
F_64 ( V_211 , V_270 , 0x30 ) ;
F_64 ( V_211 , V_271 , 0xFF ) ;
F_63 ( V_211 , 0x41 ) ;
F_25 ( V_272 , & V_211 -> V_206 . V_55 ) ;
F_25 ( V_220 , & V_211 -> V_206 . V_55 ) ;
break;
case V_273 :
F_64 ( V_211 , V_269 , 0x88 ) ;
F_64 ( V_211 , V_270 , 0x00 ) ;
F_63 ( V_211 , 0x41 ) ;
F_64 ( V_211 , V_271 , V_274 ) ;
F_15 ( V_220 , & V_211 -> V_206 . V_55 ) ;
break;
case V_275 :
F_64 ( V_211 , V_269 , 0xC0 ) ;
F_64 ( V_211 , V_270 , 0x00 ) ;
F_63 ( V_211 , 0x41 ) ;
F_64 ( V_211 , V_271 , V_274 ) ;
F_15 ( V_272 , & V_211 -> V_206 . V_55 ) ;
break;
default:
F_11 ( L_78 , V_211 -> V_205 -> V_4 ,
V_263 ) ;
return - V_276 ;
}
} else if ( V_211 -> V_205 -> type & V_233 ) {
F_64 ( V_211 , V_277 , 0x82 ) ;
F_64 ( V_211 , V_278 , 0x30 ) ;
F_64 ( V_211 , V_279 , 0x07 ) ;
F_64 ( V_211 , V_280 , 0x07 ) ;
F_64 ( V_211 , V_281 , V_211 -> V_282 ) ;
F_64 ( V_211 , V_283 , V_211 -> V_282 ) ;
switch ( V_263 ) {
case V_268 :
F_64 ( V_211 , V_281 , 0x1F ) ;
F_64 ( V_211 , V_283 , 0x1F ) ;
F_64 ( V_211 , V_284 , 0x84 ) ;
F_64 ( V_211 , V_277 , 0x82 ) ;
F_64 ( V_211 , V_285 , 0xFF ) ;
F_25 ( V_272 , & V_211 -> V_206 . V_55 ) ;
F_25 ( V_220 , & V_211 -> V_206 . V_55 ) ;
break;
case V_273 :
F_64 ( V_211 , V_284 , 0xe4 ) ;
F_64 ( V_211 , V_277 , 0x82 ) ;
F_63 ( V_211 , 0x41 ) ;
F_64 ( V_211 , V_285 , 0 ) ;
F_15 ( V_220 , & V_211 -> V_206 . V_55 ) ;
break;
case V_275 :
F_64 ( V_211 , V_284 , 0x8c ) ;
F_64 ( V_211 , V_277 , 0x8a ) ;
F_63 ( V_211 , 0x41 ) ;
F_64 ( V_211 , V_285 , 0 ) ;
F_15 ( V_272 , & V_211 -> V_206 . V_55 ) ;
break;
default:
F_11 ( L_78 , V_211 -> V_205 -> V_4 ,
V_263 ) ;
return - V_276 ;
}
} else if ( V_211 -> V_205 -> type & V_262 ) {
F_64 ( V_211 , V_277 , 0x85 ) ;
F_64 ( V_211 , V_278 , 0x30 ) ;
F_64 ( V_211 , V_279 , 0x07 ) ;
F_64 ( V_211 , V_280 , 0x07 ) ;
F_64 ( V_211 , V_281 , V_211 -> V_282 ) ;
F_64 ( V_211 , V_283 , V_211 -> V_282 ) ;
switch ( V_263 ) {
case V_268 :
F_64 ( V_211 , V_281 , 0x1F ) ;
F_64 ( V_211 , V_283 , 0x1F ) ;
F_64 ( V_211 , V_284 , 0x84 ) ;
F_64 ( V_211 , V_277 , 0x85 ) ;
F_64 ( V_211 , V_285 , 0xFF ) ;
F_25 ( V_272 , & V_211 -> V_206 . V_55 ) ;
F_25 ( V_220 , & V_211 -> V_206 . V_55 ) ;
break;
case V_273 :
F_64 ( V_211 , V_284 , 0xe4 ) ;
F_64 ( V_211 , V_277 , 0x85 ) ;
F_63 ( V_211 , 0x41 ) ;
F_64 ( V_211 , V_285 , 0 ) ;
F_15 ( V_220 , & V_211 -> V_206 . V_55 ) ;
break;
case V_275 :
F_64 ( V_211 , V_284 , 0x8c ) ;
F_64 ( V_211 , V_277 , 0x8d ) ;
F_63 ( V_211 , 0x41 ) ;
F_64 ( V_211 , V_285 , 0 ) ;
F_15 ( V_272 , & V_211 -> V_206 . V_55 ) ;
break;
default:
F_11 ( L_78 , V_211 -> V_205 -> V_4 ,
V_263 ) ;
return - V_276 ;
}
} else
return - V_123 ;
V_211 -> V_206 . V_8 = V_263 ;
return 0 ;
}
static int
F_79 ( struct V_116 * V_117 , struct V_118 * V_119 )
{
struct V_286 * V_206 = F_7 ( V_117 , struct V_286 , V_117 ) ;
struct V_200 * V_201 = F_7 ( V_206 , struct V_200 , V_206 ) ;
int V_67 = - V_123 ;
struct V_124 * V_125 = F_39 ( V_119 ) ;
unsigned long V_127 ;
switch ( V_125 -> V_128 ) {
case V_129 :
F_40 ( V_201 -> V_205 -> V_130 , V_127 ) ;
V_67 = F_80 ( V_206 , V_119 ) ;
if ( V_67 > 0 ) {
V_67 = 0 ;
F_68 ( V_201 ) ;
}
F_42 ( V_201 -> V_205 -> V_130 , V_127 ) ;
return V_67 ;
case V_132 :
F_40 ( V_201 -> V_205 -> V_130 , V_127 ) ;
if ( ! F_15 ( V_153 , & V_206 -> V_55 ) )
V_67 = F_77 ( V_201 , V_117 -> V_169 ) ;
else
V_67 = 0 ;
F_42 ( V_201 -> V_205 -> V_130 , V_127 ) ;
if ( ! V_67 )
F_47 ( V_117 , V_152 , V_154 , 0 ,
NULL , V_173 ) ;
break;
case V_133 :
F_40 ( V_201 -> V_205 -> V_130 , V_127 ) ;
F_81 ( V_206 ) ;
F_77 ( V_201 , V_268 ) ;
F_42 ( V_201 -> V_205 -> V_130 , V_127 ) ;
F_47 ( V_117 , V_155 , V_154 , 0 ,
NULL , V_173 ) ;
V_67 = 0 ;
break;
default:
F_11 ( L_79 ,
V_201 -> V_205 -> V_4 , V_35 , V_125 -> V_128 , V_125 -> V_126 ) ;
V_67 = - V_123 ;
}
if ( ! V_67 )
F_22 ( V_119 ) ;
return V_67 ;
}
static int
F_82 ( struct V_286 * V_206 , struct V_287 * V_288 )
{
return F_83 ( V_206 , V_288 ) ;
}
static int
F_84 ( struct V_116 * V_117 , T_3 V_135 , void * V_289 )
{
struct V_286 * V_206 = F_7 ( V_117 , struct V_286 , V_117 ) ;
struct V_200 * V_201 = F_7 ( V_206 , struct V_200 , V_206 ) ;
int V_67 = - V_123 ;
T_4 V_127 ;
F_2 ( L_80 , V_201 -> V_205 -> V_4 , V_35 , V_135 , V_289 ) ;
switch ( V_135 ) {
case V_159 :
F_25 ( V_290 , & V_206 -> V_55 ) ;
F_85 ( & V_206 -> V_291 ) ;
F_40 ( V_201 -> V_205 -> V_130 , V_127 ) ;
F_81 ( V_206 ) ;
F_77 ( V_201 , V_268 ) ;
F_42 ( V_201 -> V_205 -> V_130 , V_127 ) ;
V_117 -> V_169 = V_268 ;
V_117 -> V_292 = NULL ;
F_86 ( V_201 -> V_205 -> V_293 ) ;
V_67 = 0 ;
break;
case V_294 :
V_67 = F_82 ( V_206 , V_289 ) ;
break;
default:
F_11 ( L_81 ,
V_201 -> V_205 -> V_4 , V_35 , V_135 ) ;
}
return V_67 ;
}
static void
F_87 ( struct V_249 * V_250 )
{
F_48 ( & V_250 -> V_2 ) ;
}
static void
F_88 ( struct V_200 * V_201 )
{
T_1 V_61 ;
F_64 ( V_201 , V_295 , 0xFF ) ;
F_64 ( V_201 , V_296 , 0x00 ) ;
F_64 ( V_201 , V_297 , 0x00 ) ;
if ( V_201 -> V_205 -> type & V_262 ) {
F_64 ( V_201 , V_277 , 0x85 ) ;
V_61 = F_60 ( V_201 , V_298 ) ;
F_2 ( L_82 , V_201 -> V_205 -> V_4 , V_61 ) ;
if ( V_201 -> V_206 . V_44 & V_181 )
F_56 ( L_83 , V_201 -> V_205 -> V_4 ,
V_299 [ V_61 & 0x0f ] ) ;
} else
F_64 ( V_201 , V_277 , 0x82 ) ;
F_64 ( V_201 , V_278 , 0x30 ) ;
F_64 ( V_201 , V_279 , 0x07 ) ;
F_64 ( V_201 , V_280 , 0x07 ) ;
}
static int
F_89 ( struct V_249 * V_250 )
{
T_1 V_61 ;
if ( V_250 -> type & V_262 ) {
F_88 ( & V_250 -> V_211 [ 0 ] ) ;
F_88 ( & V_250 -> V_211 [ 1 ] ) ;
V_61 = F_75 ( V_250 , V_300 ) ;
} else if ( V_250 -> type & V_233 ) {
F_88 ( & V_250 -> V_211 [ 0 ] ) ;
F_88 ( & V_250 -> V_211 [ 1 ] ) ;
F_78 ( V_250 , V_301 , V_302 ) ;
V_61 = F_75 ( V_250 , V_303 ) ;
F_2 ( L_84 , V_250 -> V_4 ,
V_61 , V_250 -> V_304 ) ;
F_78 ( V_250 , V_303 , V_250 -> V_304 ) ;
V_61 = F_75 ( V_250 , V_300 ) ;
if ( V_250 -> V_211 [ 0 ] . V_206 . V_44 & V_181 )
F_56 ( L_85 , V_250 -> V_4 , V_61 ) ;
}
return F_54 ( & V_250 -> V_2 ) ;
}
static int
F_90 ( struct V_249 * V_250 , struct V_166 * V_167 )
{
struct V_286 * V_206 ;
if ( V_167 -> V_171 . V_172 == 0 || V_167 -> V_171 . V_172 > 2 )
return - V_123 ;
if ( V_167 -> V_169 == V_268 )
return - V_123 ;
V_206 = & V_250 -> V_211 [ V_167 -> V_171 . V_172 - 1 ] . V_206 ;
if ( F_15 ( V_290 , & V_206 -> V_55 ) )
return - V_305 ;
F_25 ( V_248 , & V_206 -> V_55 ) ;
V_206 -> V_117 . V_169 = V_167 -> V_169 ;
V_167 -> V_117 = & V_206 -> V_117 ;
return 0 ;
}
static int
F_91 ( struct V_249 * V_250 , struct V_287 * V_288 )
{
int V_67 = 0 ;
switch ( V_288 -> V_306 ) {
case V_307 :
V_288 -> V_306 = V_308 | V_309 ;
break;
case V_308 :
if ( V_288 -> V_172 < 0 || V_288 -> V_172 > 3 ) {
V_67 = - V_123 ;
break;
}
V_67 = V_250 -> V_196 ( V_250 , V_138 , V_288 -> V_172 ) ;
break;
case V_309 :
V_67 = V_250 -> V_2 . V_196 ( & V_250 -> V_2 , V_141 , V_288 -> V_310 ) ;
break;
default:
F_11 ( L_86 , V_250 -> V_4 , V_288 -> V_306 ) ;
V_67 = - V_123 ;
break;
}
return V_67 ;
}
static int
F_92 ( struct V_116 * V_117 , T_3 V_135 , void * V_289 )
{
struct V_120 * V_121 = F_7 ( V_117 , struct V_120 , V_122 ) ;
struct V_14 * V_12 = F_7 ( V_121 , struct V_14 , V_121 ) ;
struct V_1 * V_2 = F_7 ( V_12 , struct V_1 , V_12 ) ;
struct V_249 * V_250 = F_7 ( V_2 , struct V_249 , V_2 ) ;
struct V_166 * V_167 ;
int V_174 = 0 ;
F_2 ( L_87 , V_250 -> V_4 , V_135 , V_289 ) ;
switch ( V_135 ) {
case V_311 :
V_167 = V_289 ;
if ( V_167 -> V_169 == V_170 )
V_174 = F_51 ( V_2 , V_167 , F_53 ( 0 ) ) ;
else
V_174 = F_90 ( V_250 , V_167 ) ;
if ( V_174 )
break;
if ( ! F_93 ( V_250 -> V_293 ) )
F_11 ( L_88 , V_250 -> V_4 ) ;
break;
case V_159 :
F_2 ( L_89 , V_250 -> V_4 ,
V_12 -> V_121 . V_126 , F_53 ( 0 ) ) ;
F_86 ( V_250 -> V_293 ) ;
break;
case V_294 :
V_174 = F_91 ( V_250 , V_289 ) ;
break;
default:
F_2 ( L_90 , V_250 -> V_4 , V_135 ) ;
return - V_123 ;
}
return V_174 ;
}
T_3
F_94 ( struct V_249 * V_250 , void * V_42 )
{
T_3 V_67 ;
T_1 V_312 ;
V_250 -> V_42 = V_42 ;
if ( V_250 -> V_2 . V_12 . V_44 & V_181 )
F_56 ( L_91 , V_250 -> V_4 , V_250 -> type ) ;
if ( V_250 -> type & V_262 ) {
V_250 -> V_2 . type = V_313 ;
V_250 -> V_211 [ 0 ] . V_43 = 0 ;
V_250 -> V_211 [ 1 ] . V_43 = 0x40 ;
V_250 -> V_211 [ 0 ] . V_218 = 32 ;
V_250 -> V_211 [ 1 ] . V_218 = 32 ;
} else if ( V_250 -> type & V_233 ) {
V_250 -> V_2 . type = V_233 | V_313 ;
V_250 -> V_211 [ 0 ] . V_43 = 0 ;
V_250 -> V_211 [ 1 ] . V_43 = 0x40 ;
V_250 -> V_211 [ 0 ] . V_218 = 64 ;
V_250 -> V_211 [ 1 ] . V_218 = 64 ;
} else if ( V_250 -> type & V_208 ) {
V_250 -> V_2 . type = V_208 | V_5 ;
V_250 -> V_211 [ 0 ] . V_43 = V_314 ;
V_250 -> V_211 [ 1 ] . V_43 = V_315 ;
V_250 -> V_211 [ 0 ] . V_218 = 64 ;
V_250 -> V_211 [ 1 ] . V_218 = 64 ;
} else
return 0 ;
F_57 ( & V_250 -> V_2 , V_42 ) ;
V_250 -> V_2 . V_12 . V_121 . V_122 . V_196 = F_92 ;
for ( V_312 = 0 ; V_312 < 2 ; V_312 ++ ) {
V_250 -> V_211 [ V_312 ] . V_206 . V_207 = V_312 + 1 ;
F_95 ( V_312 + 1 , V_250 -> V_2 . V_12 . V_121 . V_316 ) ;
F_96 ( & V_250 -> V_211 [ V_312 ] . V_206 . V_117 . V_317 ,
& V_250 -> V_2 . V_12 . V_121 . V_318 ) ;
F_97 ( & V_250 -> V_211 [ V_312 ] . V_206 , V_319 ,
V_250 -> V_211 [ V_312 ] . V_218 ) ;
V_250 -> V_211 [ V_312 ] . V_206 . V_117 . V_207 = V_312 + 1 ;
V_250 -> V_211 [ V_312 ] . V_206 . V_117 . V_193 = & F_79 ;
V_250 -> V_211 [ V_312 ] . V_206 . V_117 . V_196 = F_84 ;
V_250 -> V_211 [ V_312 ] . V_206 . V_42 = V_42 ;
V_250 -> V_211 [ V_312 ] . V_205 = V_250 ;
V_250 -> V_211 [ V_312 ] . V_282 = ( V_312 == 0 ) ? 0x2f : 0x03 ;
}
V_250 -> V_194 = F_89 ;
V_250 -> V_195 = F_87 ;
V_67 = ( 1 << ( V_273 & V_320 ) ) |
( 1 << ( V_275 & V_320 ) ) ;
return V_67 ;
}
static int T_5
F_98 ( void )
{
F_56 ( L_92 , V_321 ) ;
return 0 ;
}
static void T_6
F_99 ( void )
{
F_56 ( L_93 ) ;
}
