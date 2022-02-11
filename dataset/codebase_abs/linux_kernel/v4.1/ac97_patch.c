static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_5 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_4 [ V_6 ] , V_2 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , const char * V_10 ,
const unsigned int * V_11 )
{
struct V_12 V_13 ;
struct V_14 * V_15 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
strcpy ( V_13 . V_10 , V_10 ) ;
V_13 . V_16 = V_17 ;
V_15 = F_5 ( V_2 -> V_8 -> V_9 , & V_13 ) ;
if ( V_15 && V_15 -> V_11 . V_18 )
V_15 -> V_11 . V_18 = V_11 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned short V_19 , unsigned short V_20 , unsigned short V_21 , unsigned short V_22 )
{
unsigned short V_23 ;
int V_24 ;
F_7 ( & V_2 -> V_25 ) ;
V_23 = F_8 ( V_2 , V_26 ) & V_27 ;
F_9 ( V_2 , V_26 , V_27 , V_22 ) ;
V_24 = F_9 ( V_2 , V_19 , V_20 , V_21 ) ;
F_9 ( V_2 , V_26 , V_27 , V_23 ) ;
F_10 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static int F_11 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [] = { L_1 , L_2 } ;
return F_12 ( V_30 , 1 , 2 , V_31 ) ;
}
static int F_13 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = V_2 -> V_36 ;
return 0 ;
}
static int F_15 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned char V_37 = ! ! V_33 -> V_21 . V_34 . V_35 [ 0 ] ;
if ( V_37 != V_2 -> V_36 ) {
V_2 -> V_36 = V_37 ;
if ( V_2 -> V_38 -> V_39 )
V_2 -> V_38 -> V_39 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_16 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [] = { L_3 , L_4 , L_5 , L_6 } ;
return F_12 ( V_30 , 1 , V_28 -> V_40 , V_31 ) ;
}
static int F_17 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = V_2 -> V_41 ;
return 0 ;
}
static int F_18 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned char V_42 = V_33 -> V_21 . V_34 . V_35 [ 0 ] ;
if ( V_42 >= V_28 -> V_40 )
return - V_43 ;
if ( V_42 != V_2 -> V_41 ) {
V_2 -> V_41 = V_42 ;
if ( V_2 -> V_38 -> V_39 )
V_2 -> V_38 -> V_39 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_41 >= 1 ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_41 >= 2 ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return ! V_2 -> V_36 && F_19 ( V_2 ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return ! V_2 -> V_36 && F_20 ( V_2 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
return ! V_2 -> V_36 && ! F_19 ( V_2 ) ;
}
static inline int F_24 ( struct V_1 * V_2 )
{
return ! V_2 -> V_36 && ! F_20 ( V_2 ) ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
return F_19 ( V_2 ) ;
}
static int F_26 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static const char * const V_31 [ 3 ] = {
L_7 , L_8 , L_9
} ;
return F_12 ( V_30 , 1 , 3 , V_31 ) ;
}
static int F_27 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_46 ] ;
V_44 = ( V_44 >> 10 ) & 3 ;
if ( V_44 > 0 )
V_44 -- ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = V_44 ;
return 0 ;
}
static int F_28 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] > 2 )
return - V_43 ;
V_44 = ( V_33 -> V_21 . V_34 . V_35 [ 0 ] + 1 ) << 10 ;
return F_29 ( V_2 , V_46 , V_44 ) ;
}
static int F_30 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static const char * const V_31 [ 2 ] = { L_10 , L_11 } ;
return F_12 ( V_30 , 1 , 2 , V_31 ) ;
}
static int F_31 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_47 ] ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = ( V_44 >> 1 ) & 1 ;
return 0 ;
}
static int F_32 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] > 1 )
return - V_43 ;
V_44 = V_33 -> V_21 . V_34 . V_35 [ 0 ] << 1 ;
return F_9 ( V_2 , V_47 , 0x0002 , V_44 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_7 ;
V_15 = F_3 ( & V_48 [ 0 ] , V_2 ) ;
V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
strcpy ( V_15 -> V_49 . V_10 , L_12 ) ;
V_15 -> V_40 = F_34 ( V_50 , 9 , 7 , 0 ) ;
F_35 ( V_2 , V_50 , 0x0000 ) ;
V_7 = F_2 ( V_2 -> V_8 -> V_9 ,
F_3 ( & V_51 ,
V_2 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_46 , 0x0c00 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_1 ( V_2 , & V_52 [ 0 ] , 3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 ,
V_53 , 3 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_47 , 0xa201 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_54 ;
V_2 -> V_55 |= V_56 ;
V_2 -> V_55 |= 0x04 << 10 ;
V_2 -> V_57 [ V_58 ] = V_59 ;
V_2 -> V_60 |= V_61 ;
return 0 ;
}
static int F_38 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [ 3 ] = { L_13 , L_14 , L_15 } ;
return F_12 ( V_30 , 1 , 3 , V_31 ) ;
}
static int F_39 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_47 ] ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = ( V_44 & 0x0008 ) ? 2 : ( V_44 & 0x0020 ) ? 1 : 0 ;
return 0 ;
}
static int F_40 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] > 2 )
return - V_43 ;
V_44 = ( V_33 -> V_21 . V_34 . V_35 [ 0 ] == 2 ) ? 0x0008 :
( V_33 -> V_21 . V_34 . V_35 [ 0 ] == 1 ) ? 0x0020 : 0 ;
return F_9 ( V_2 , V_47 , 0x0028 , V_44 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_62 , F_42 ( V_62 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_63 ;
V_2 -> V_55 |= V_56 ;
V_2 -> V_55 |= 0x04 << 10 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_7 , V_64 ;
for ( V_64 = 0 ; V_64 < F_42 ( V_65 ) ; V_64 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_65 [ V_64 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
F_35 ( V_2 , V_66 , 0x0808 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_67 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_7 , V_64 ;
for ( V_64 = 0 ; V_64 < F_42 ( V_68 ) ; V_64 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_68 [ V_64 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
F_35 ( V_2 , V_69 , 0x0200 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_70 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_67 ;
#ifdef F_49
V_2 -> V_71 |= V_72 | V_73 ;
#endif
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_7 , V_64 ;
for ( V_64 = 0 ; V_64 < F_42 ( V_74 ) ; V_64 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_74 [ V_64 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
F_35 ( V_2 , V_75 , 0x0808 ) ;
F_35 ( V_2 , V_76 , 0x0808 ) ;
F_35 ( V_2 , V_77 , 0x0808 ) ;
F_35 ( V_2 , V_78 , 0x0808 ) ;
F_35 ( V_2 , V_79 , 0x0808 ) ;
F_35 ( V_2 , V_80 , 0x0000 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_81 ;
V_2 -> V_71 |= V_82 | V_83 | V_84 |
V_85 | V_72 | V_86 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_7 , V_64 ;
for ( V_64 = 0 ; V_64 < F_42 ( V_87 ) ; V_64 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_87 [ V_64 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_7 , V_64 ;
for ( V_64 = 0 ; V_64 < F_42 ( V_88 ) ; V_64 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_88 [ V_64 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
F_35 ( V_2 , V_79 , 0x0808 ) ;
F_35 ( V_2 , V_89 , 0x0808 ) ;
F_35 ( V_2 , V_90 , 0x0808 ) ;
F_35 ( V_2 , V_91 , 0x00da ) ;
F_35 ( V_2 , V_80 , 0x0808 ) ;
F_35 ( V_2 , V_77 , 0xd612 ) ;
F_35 ( V_2 , V_92 , 0x1ba0 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_93 , 0xfeff ) ;
F_35 ( V_2 , V_94 , 0xffff ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_93 , 0xda00 ) ;
F_35 ( V_2 , V_94 , 0x3810 ) ;
F_35 ( V_2 , V_95 , 0x0 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_96 ;
V_2 -> V_71 |= V_82 | V_83 | V_97 |
V_85 | V_72 | V_86 | V_98 |
V_99 ;
V_2 -> V_100 &= ~ V_101 ;
F_35 ( V_2 , V_93 , 0xda00 ) ;
F_35 ( V_2 , V_94 , 0x3810 ) ;
F_35 ( V_2 , V_95 , 0x0 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
F_35 ( V_2 , 0x26 , 0x0300 ) ;
F_35 ( V_2 , 0x26 , 0x0000 ) ;
F_35 ( V_2 , V_102 , 0x0000 ) ;
F_35 ( V_2 , V_103 , 0x0000 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_7 ;
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 = F_3 ( & V_48 [ 0 ] , V_2 ) ) ) < 0 )
return V_7 ;
strcpy ( V_15 -> V_49 . V_10 , L_16 ) ;
V_15 -> V_40 = F_34 ( V_50 , 2 , 3 , 0 ) ;
F_35 ( V_2 , V_50 , 0x0000 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_7 ;
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 = F_3 ( & V_48 [ 0 ] , V_2 ) ) ) < 0 )
return V_7 ;
strcpy ( V_15 -> V_49 . V_10 , L_16 ) ;
V_15 -> V_40 = F_34 ( V_50 , 0 , 3 , 0 ) ;
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 = F_3 ( & V_48 [ 0 ] , V_2 ) ) ) < 0 )
return V_7 ;
strcpy ( V_15 -> V_49 . V_10 , L_17 ) ;
V_15 -> V_40 = F_34 ( V_50 , 2 , 3 , 0 ) ;
F_35 ( V_2 , V_50 , 0x0000 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_7 ;
F_35 ( V_2 , V_104 , F_8 ( V_2 , V_104 ) & ~ 0x0003 ) ;
if ( F_61 ( V_2 , V_104 , 1 ) )
if ( ( V_7 = F_1 ( V_2 , & V_105 [ 0 ] , 1 ) ) < 0 )
return V_7 ;
if ( F_61 ( V_2 , V_104 , 0 ) )
if ( ( V_7 = F_1 ( V_2 , & V_105 [ 1 ] , 1 ) ) < 0 )
return V_7 ;
if ( F_61 ( V_2 , V_106 , 2 ) )
if ( ( V_7 = F_1 ( V_2 , & V_107 , 1 ) ) < 0 )
return V_7 ;
if ( F_61 ( V_2 , V_106 , 3 ) )
if ( ( V_7 = F_1 ( V_2 , & V_108 , 1 ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_109 ;
return 0 ;
}
static int F_63 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_7 ;
F_7 ( & V_2 -> V_25 ) ;
F_64 ( V_2 , V_110 , 0xabba ) ;
V_7 = F_9 ( V_2 , V_111 , 0x0010 ,
( V_33 -> V_21 . integer . V_21 [ 0 ] & 1 ) << 4 ) ;
F_64 ( V_2 , V_110 , 0 ) ;
F_10 ( & V_2 -> V_25 ) ;
return V_7 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_7 ;
F_66 ( V_2 , L_18 , NULL ) ;
F_67 ( V_2 , L_19 , L_20 ) ;
if ( ( V_7 = F_1 ( V_2 , & V_112 , 1 ) ) < 0 )
return V_7 ;
return F_60 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
unsigned int V_113 , V_114 ;
V_2 -> V_38 = & V_115 ;
V_2 -> V_55 |= 0x10 ;
V_113 = F_8 ( V_2 , V_111 ) & 0x8000 ;
V_114 = F_8 ( V_2 , V_104 ) ;
if ( ( V_113 == 0 ) && ( V_114 == 0 ) ) {
F_35 ( V_2 , V_116 , 0xabba ) ;
F_35 ( V_2 , V_117 , 0x1000 ) ;
F_35 ( V_2 , V_110 , 0xabba ) ;
F_35 ( V_2 , V_111 , 0x0007 ) ;
} else if ( ( V_113 == 0x8000 ) && ( V_114 == 0 ) ) {
F_35 ( V_2 , V_116 , 0xabba ) ;
F_35 ( V_2 , V_117 , 0x1001 ) ;
F_35 ( V_2 , V_106 , 0x0008 ) ;
} else if ( ( V_113 == 0x8000 ) && ( V_114 == 0x0080 ) ) {
}
F_35 ( V_2 , V_118 , 0x0000 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_109 ;
if ( F_8 ( V_2 , V_104 ) == 0 ) {
F_35 ( V_2 , V_116 , 0xabba ) ;
F_35 ( V_2 , V_117 , 0x4000 ) ;
F_35 ( V_2 , V_110 , 0xabba ) ;
F_35 ( V_2 , V_111 , 0x0002 ) ;
}
F_35 ( V_2 , V_118 , 0x0000 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_109 ;
F_35 ( V_2 , V_116 , 0xabba ) ;
F_35 ( V_2 , V_117 , 0x0000 ) ;
F_35 ( V_2 , V_110 , 0xabba ) ;
F_35 ( V_2 , V_111 , 0x0002 ) ;
F_35 ( V_2 , V_118 , 0x0000 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_109 ;
F_35 ( V_2 , V_116 , 0xabba ) ;
F_35 ( V_2 , V_117 , 0x0000 ) ;
F_35 ( V_2 , V_110 , 0xabba ) ;
F_35 ( V_2 , V_111 , 0x0002 ) ;
F_35 ( V_2 , V_118 , 0x0000 ) ;
return 0 ;
}
static int F_72 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [ 5 ] = {
L_21 , L_22 ,
L_23 , L_24 , L_25 } ;
return F_12 ( V_30 , 1 , 5 , V_31 ) ;
}
static int F_73 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_119 = V_28 -> V_40 ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_120 ] >> V_119 ;
if ( ! ( V_44 & 4 ) )
V_33 -> V_21 . V_34 . V_35 [ 0 ] = 0 ;
else
V_33 -> V_21 . V_34 . V_35 [ 0 ] = 1 + ( V_44 & 3 ) ;
return 0 ;
}
static int F_74 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_119 = V_28 -> V_40 ;
unsigned short V_44 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] > 4 )
return - V_43 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] == 0 )
V_44 = 0 ;
else
V_44 = 4 | ( V_33 -> V_21 . V_34 . V_35 [ 0 ] - 1 ) ;
return F_6 ( V_2 , V_120 ,
7 << V_119 , V_44 << V_119 , 0 ) ;
}
static int F_75 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [ 7 ] = {
L_26 , L_27 , L_28 ,
L_29 , L_30 , L_31 , L_32 } ;
return F_12 ( V_30 , 1 , 7 , V_31 ) ;
}
static int F_76 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_119 = V_28 -> V_40 ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_121 ] ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = ( V_44 >> V_119 ) & 7 ;
return 0 ;
}
static int F_77 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_119 = V_28 -> V_40 ;
return F_6 ( V_2 , V_121 , 7 << V_119 ,
V_33 -> V_21 . V_34 . V_35 [ 0 ] << V_119 , 0 ) ;
}
static int F_78 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [ 3 ] = {
L_33 , L_29 , L_30
} ;
return F_12 ( V_30 , 1 , 3 , V_31 ) ;
}
static int F_79 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = V_2 -> V_45 [ V_122 ] & 3 ;
return 0 ;
}
static int F_80 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_6 ( V_2 , V_122 , 3 ,
V_33 -> V_21 . V_34 . V_35 [ 0 ] , 0 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_60 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_123 ,
F_42 ( V_123 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_67 ( V_2 , L_19 , L_34 ) ;
F_67 ( V_2 , L_35 , L_36 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
static unsigned short V_45 [ 4 ] = {
V_120 ,
V_122 ,
V_121 ,
V_124
} ;
static unsigned short V_125 [ 4 ] = {
0xd794 ,
0x2001 ,
0x0201 ,
0x0040
} ;
static unsigned short V_126 [ 4 ] = {
0xfc70 ,
0x2102 ,
0x0203 ,
0x0041
} ;
unsigned short * V_127 = V_125 ;
int V_64 ;
if ( V_2 -> V_128 &&
V_2 -> V_129 == 0x107b &&
V_2 -> V_130 == 0x0601 )
V_127 = V_126 ;
V_2 -> V_38 = & V_131 ;
F_9 ( V_2 , V_26 , V_27 , V_132 ) ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ )
F_35 ( V_2 , V_45 [ V_64 ] , V_127 [ V_64 ] ) ;
V_2 -> V_71 |= V_83 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_52 [ 0 ] , 3 ) ) < 0 )
return V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_133 [ 0 ] , 1 ) ) < 0 )
return V_7 ;
switch ( V_2 -> V_49 & V_134 ) {
case V_135 :
if ( ( V_7 = F_1 ( V_2 , & V_133 [ 1 ] , 1 ) ) < 0 )
return V_7 ;
break;
}
F_35 ( V_2 , V_136 , 0x0a20 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_137 ;
V_2 -> V_71 |= V_138 ;
V_2 -> V_57 [ V_58 ] &= ~ V_139 ;
V_2 -> V_60 |= V_61 ;
F_35 ( V_2 , V_140 , 0x0080 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
V_2 -> V_71 |= V_141 ;
return F_84 ( V_2 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_52 [ 0 ] , 3 ) ) < 0 )
return V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_142 [ 0 ] , 1 ) ) < 0 )
return V_7 ;
F_35 ( V_2 , V_143 ,
F_8 ( V_2 , V_143 ) & ~ ( V_144 | V_145 | V_146 ) ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_147 ;
V_2 -> V_71 |= V_148 ;
V_2 -> V_60 |= V_61 ;
V_2 -> V_57 [ V_58 ] = V_59 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0x5c , 0x01 , 0x01 ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
static unsigned short V_149 [] = {
V_150 , V_151 , V_152 ,
} ;
int V_64 , V_153 ;
for ( V_64 = 0 ; V_64 < ( int ) F_42 ( V_149 ) ; V_64 ++ ) {
unsigned short V_19 = V_149 [ V_64 ] ;
if ( F_90 ( V_19 , V_2 -> V_154 ) ) {
F_64 ( V_2 , V_19 , V_2 -> V_45 [ V_19 ] ) ;
F_8 ( V_2 , V_19 ) ;
}
}
if ( ! ( V_2 -> V_71 & V_155 ) )
F_91 ( V_2 ) ;
else {
for ( V_153 = 0 ; V_153 < 3 ; V_153 ++ ) {
if ( ! V_2 -> V_156 . V_157 . V_49 [ V_153 ] )
continue;
F_9 ( V_2 , V_151 , 0x7000 ,
V_2 -> V_156 . V_157 . V_158 [ V_153 ] | V_2 -> V_156 . V_157 . V_159 [ V_153 ] ) ;
V_2 -> V_8 -> V_160 -> V_161 ( V_2 , V_162 , V_2 -> V_156 . V_157 . V_163 [ V_153 ] ) ;
}
F_9 ( V_2 , V_151 , 0x7000 , 0x7000 ) ;
for ( V_64 = 2 ; V_64 < 0x7c ; V_64 += 2 ) {
if ( V_64 == V_95 || V_64 == V_164 )
continue;
if ( F_90 ( V_64 , V_2 -> V_154 ) ) {
if ( V_64 == V_165 ) {
for ( V_153 = 0 ; V_153 < 3 ; V_153 ++ ) {
if ( ! V_2 -> V_156 . V_157 . V_49 [ V_153 ] )
continue;
F_9 ( V_2 , V_151 , 0x7000 ,
V_2 -> V_156 . V_157 . V_158 [ V_153 ] | V_2 -> V_156 . V_157 . V_159 [ V_153 ] ) ;
V_2 -> V_8 -> V_160 -> V_161 ( V_2 , V_165 , V_2 -> V_156 . V_157 . V_166 [ V_153 ] ) ;
}
F_9 ( V_2 , V_151 , 0x7000 , 0x7000 ) ;
continue;
} else if ( V_64 == V_167 ||
V_64 == V_162 ||
V_64 == V_151 )
continue;
}
F_64 ( V_2 , V_64 , V_2 -> V_45 [ V_64 ] ) ;
F_8 ( V_2 , V_64 ) ;
}
}
F_92 ( V_2 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_89 ( V_2 ) ;
F_35 ( V_2 , V_75 , 0x8080 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
unsigned short V_168 ;
V_168 = F_8 ( V_2 , V_151 ) ;
F_35 ( V_2 , V_151 , V_168 | 0x7000 ) ;
V_2 -> V_169 = V_170 ;
return 0 ;
}
static unsigned short F_95 ( struct V_1 * V_2 , int V_6 , unsigned short V_20 )
{
unsigned short V_44 ;
F_9 ( V_2 , V_151 , 0x7000 , V_20 ) ;
F_35 ( V_2 , V_162 , 0x0000 ) ;
V_44 = F_8 ( V_2 , V_171 ) ;
if ( ( V_44 & 0xff40 ) != 0x5340 )
return 0 ;
V_2 -> V_156 . V_157 . V_158 [ V_6 ] = V_20 ;
V_2 -> V_156 . V_157 . V_49 [ V_6 ] = V_44 ;
V_2 -> V_156 . V_157 . V_163 [ V_6 ] = 0x0000 ;
return V_20 ;
}
static int F_96 ( struct V_1 * V_2 , int V_6 , unsigned short V_172 )
{
static int V_173 [ 3 ] = { 1 << 12 , 1 << 14 , 1 << 13 } ;
unsigned short V_44 ;
F_9 ( V_2 , V_151 , 0x7000 , V_173 [ V_6 ] ) ;
F_35 ( V_2 , V_162 , 0x0004 ) ;
V_44 = F_8 ( V_2 , V_171 ) ;
if ( ( V_44 & 0xff40 ) != 0x5340 )
return 0 ;
if ( V_172 )
F_35 ( V_2 , V_162 , V_172 ) ;
V_2 -> V_156 . V_157 . V_159 [ V_6 ] = V_173 [ V_6 ] ;
V_2 -> V_156 . V_157 . V_49 [ V_6 ] = V_44 ;
V_2 -> V_156 . V_157 . V_163 [ V_6 ] = V_172 ? V_172 : 0x0004 ;
return 1 ;
}
static void F_97 ( struct V_1 * V_2 , int V_174 , int V_175 , int V_176 )
{
if ( V_2 -> V_156 . V_157 . V_158 [ V_175 ] || V_2 -> V_156 . V_157 . V_159 [ V_175 ] )
V_175 = - 1 ;
if ( V_2 -> V_156 . V_157 . V_158 [ V_176 ] || V_2 -> V_156 . V_157 . V_159 [ V_176 ] )
V_176 = - 1 ;
if ( V_175 < 0 && V_176 < 0 )
return;
F_9 ( V_2 , V_151 , 0x7000 ,
V_2 -> V_156 . V_157 . V_158 [ V_174 ] ) ;
F_35 ( V_2 , V_162 , 0x0002 ) ;
V_2 -> V_156 . V_157 . V_163 [ V_174 ] = 0x0002 ;
if ( V_175 >= 0 ) {
if ( V_176 < 0 )
F_96 ( V_2 , V_175 , 0 ) ;
else if ( F_96 ( V_2 , V_175 , 0x0006 ) )
F_96 ( V_2 , V_176 , 0 ) ;
else if ( F_96 ( V_2 , V_176 , 0x0006 ) )
F_96 ( V_2 , V_175 , 0 ) ;
} else if ( V_176 >= 0 ) {
F_96 ( V_2 , V_176 , 0 ) ;
}
}
static int F_98 ( struct V_1 * V_2 )
{
static const char V_177 [ 3 ] [ 2 ] = {
{ 2 , 1 } ,
{ 0 , 2 } ,
{ 0 , 1 }
} ;
unsigned short V_178 [ 3 ] ;
unsigned short V_44 ;
int V_6 , V_179 ;
V_44 = F_8 ( V_2 , V_151 ) ;
F_35 ( V_2 , V_151 , V_44 ) ;
V_178 [ 0 ] = F_95 ( V_2 , 0 , ( 1 << 12 ) ) ;
V_178 [ 1 ] = F_95 ( V_2 , 1 , ( 1 << 14 ) ) ;
V_178 [ 2 ] = F_95 ( V_2 , 2 , ( 1 << 13 ) ) ;
if ( ! ( V_178 [ 0 ] || V_178 [ 1 ] || V_178 [ 2 ] ) )
goto V_180;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
if ( V_2 -> V_156 . V_157 . V_158 [ V_6 ] )
F_97 ( V_2 , V_6 , V_177 [ V_6 ] [ 0 ] , V_177 [ V_6 ] [ 1 ] ) ;
if ( V_2 -> V_156 . V_157 . V_49 [ 1 ] ) {
V_2 -> V_71 |= V_155 ;
V_2 -> V_100 |= V_181 ;
}
if ( V_2 -> V_156 . V_157 . V_49 [ 2 ] ) {
V_2 -> V_71 |= V_155 ;
V_2 -> V_100 |= V_182 ;
}
V_180:
F_9 ( V_2 , V_151 , 0x7000 , 0x7000 ) ;
for ( V_6 = V_179 = 0 ; V_6 < 3 ; V_6 ++ )
if ( V_2 -> V_156 . V_157 . V_49 [ V_6 ] )
V_179 ++ ;
if ( V_179 == 1 ) {
F_35 ( V_2 , V_162 , 0x0000 ) ;
V_2 -> V_156 . V_157 . V_163 [ 0 ] =
V_2 -> V_156 . V_157 . V_163 [ 1 ] =
V_2 -> V_156 . V_157 . V_163 [ 2 ] = 0x0000 ;
}
V_2 -> V_60 = F_8 ( V_2 , V_164 ) ;
if ( V_2 -> V_156 . V_157 . V_49 [ 0 ] ) {
V_2 -> V_49 &= 0xffff0000 ;
V_2 -> V_49 |= V_2 -> V_156 . V_157 . V_49 [ 0 ] ;
}
V_2 -> V_38 = & V_183 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_184 , F_42 ( V_184 ) ) ) < 0 )
return V_7 ;
F_4 ( V_2 , L_37 ,
V_185 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
F_35 ( V_2 , V_150 , 0x0404 ) ;
V_2 -> V_38 = & V_186 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
F_4 ( V_2 , L_37 ,
V_185 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
F_35 ( V_2 , V_152 , 0x0010 ) ;
V_2 -> V_38 = & V_187 ;
return 0 ;
}
static int F_103 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [ 2 ] = { L_10 , L_11 } ;
return F_12 ( V_30 , 1 , 2 , V_31 ) ;
}
static int F_104 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_151 ] ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = ( V_44 >> 2 ) & 1 ;
return 0 ;
}
static int F_105 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] > 1 )
return - V_43 ;
V_44 = V_33 -> V_21 . V_34 . V_35 [ 0 ] << 2 ;
return F_9 ( V_2 , V_151 , 0x0004 , V_44 ) ;
}
static int F_106 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , & V_188 , 1 ) ;
}
static int F_107 ( struct V_1 * V_2 , const unsigned int * V_189 )
{
T_1 V_190 = ( ( T_1 ) V_2 -> V_129 << 16 ) | V_2 -> V_130 ;
for (; * V_189 ; V_189 ++ )
if ( * V_189 == V_190 )
return 1 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 )
{
if ( F_107 ( V_2 , V_191 ) )
return 0 ;
return F_1 ( V_2 , V_192 ,
F_42 ( V_192 ) ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
if ( F_107 ( V_2 , V_193 ) )
F_9 ( V_2 , V_152 , 1 << 11 , 1 << 11 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
V_2 -> V_38 = & V_194 ;
F_9 ( V_2 , V_150 , V_195 , V_195 ) ;
V_2 -> V_71 |= V_83 ;
F_109 ( V_2 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_196 , 1 ) ) < 0 )
return V_7 ;
if ( F_107 ( V_2 , V_191 ) )
return 0 ;
return F_1 ( V_2 , V_192 ,
F_42 ( V_192 ) ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
V_2 -> V_38 = & V_197 ;
F_9 ( V_2 , V_150 , V_195 , V_195 ) ;
V_2 -> V_71 |= V_83 ;
F_109 ( V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_150 ] ;
V_33 -> V_21 . integer . V_21 [ 0 ] = ! ( V_44 & V_198 ) ;
if ( V_2 -> V_156 . V_157 . V_199 )
V_33 -> V_21 . integer . V_21 [ 0 ] =
! V_33 -> V_21 . integer . V_21 [ 0 ] ;
return 0 ;
}
static int F_114 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = ! V_33 -> V_21 . integer . V_21 [ 0 ] ;
if ( V_2 -> V_156 . V_157 . V_199 )
V_44 = ! V_44 ;
V_44 = V_44 ? ( V_198 | V_200 ) : 0 ;
return F_9 ( V_2 , V_150 ,
V_198 | V_200 , V_44 ) ;
}
static int F_115 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [ 3 ] = { L_38 , L_39 , L_40 } ;
return F_12 ( V_30 , 1 , 3 , V_31 ) ;
}
static int F_116 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_150 ] ;
if ( ! ( V_44 & V_201 ) )
V_33 -> V_21 . V_34 . V_35 [ 0 ] = 0 ;
else
V_33 -> V_21 . V_34 . V_35 [ 0 ] = 1 + ( ( V_44 >> 8 ) & 1 ) ;
return 0 ;
}
static int F_117 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] > 2 )
return - V_43 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] == 0 )
V_44 = 0 ;
else
V_44 = V_201 |
( ( V_33 -> V_21 . V_34 . V_35 [ 0 ] - 1 ) << 8 ) ;
return F_9 ( V_2 , V_150 ,
V_202 | V_201 , V_44 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
unsigned short V_44 = 0 ;
if ( ! V_2 -> V_156 . V_157 . V_199 && F_23 ( V_2 ) )
V_44 |= ( 1 << 12 ) ;
if ( F_24 ( V_2 ) )
V_44 |= ( 1 << 11 ) ;
F_9 ( V_2 , V_150 , ( 1 << 11 ) | ( 1 << 12 ) , V_44 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_156 . V_157 . V_199 ) {
F_67 ( V_2 , L_41 ,
L_42 ) ;
F_67 ( V_2 , L_19 ,
L_41 ) ;
}
return F_1 ( V_2 , V_203 , F_42 ( V_203 ) ) ;
}
static int F_120 ( struct V_1 * V_2 )
{
unsigned short V_204 ;
F_98 ( V_2 ) ;
V_2 -> V_38 = & V_205 ;
if ( V_2 -> V_129 == 0x1043 &&
V_2 -> V_130 == 0x1193 )
V_2 -> V_156 . V_157 . V_199 = 1 ;
V_204 = F_8 ( V_2 , V_150 ) ;
V_204 |= V_195 | V_206 ;
if ( ! V_2 -> V_156 . V_157 . V_199 )
V_204 |= V_198 | V_200 ;
F_35 ( V_2 , V_150 , V_204 ) ;
V_2 -> V_71 |= V_83 ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_119 ( V_2 ) ) < 0 )
return V_7 ;
return F_1 ( V_2 , & V_196 , 1 ) ;
}
static int F_122 ( struct V_1 * V_2 )
{
F_120 ( V_2 ) ;
V_2 -> V_38 = & V_207 ;
return 0 ;
}
static int F_123 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static const char * const V_31 [ 4 ] = {
L_43 , L_44 , L_45 , L_46
} ;
return F_12 ( V_30 , 1 , 4 , V_31 ) ;
}
static int F_124 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
static const int V_208 [ 4 ] = { 2 , 0 , 1 , 3 } ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = ( V_2 -> V_45 [ V_150 ] & V_209 )
>> V_210 ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = V_208 [ V_44 ] ;
return 0 ;
}
static int F_125 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
static const int V_211 [ 4 ] = { 1 , 2 , 0 , 3 } ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] > 3 )
return - V_43 ;
V_44 = V_211 [ V_33 -> V_21 . V_34 . V_35 [ 0 ] ]
<< V_210 ;
return F_9 ( V_2 , V_150 ,
V_209 , V_44 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
F_118 ( V_2 ) ;
F_9 ( V_2 , V_151 , 1 << 9 ,
F_24 ( V_2 ) ? 1 << 9 : 0 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_7 ;
F_67 ( V_2 , L_41 ,
L_42 ) ;
F_67 ( V_2 , L_19 , L_41 ) ;
if ( ( V_7 = F_1 ( V_2 , & V_196 , 1 ) ) < 0 )
return V_7 ;
return F_1 ( V_2 , V_212 ,
F_42 ( V_212 ) ) ;
}
static int F_128 ( struct V_1 * V_2 )
{
unsigned short V_204 ;
F_98 ( V_2 ) ;
V_2 -> V_38 = & V_213 ;
V_204 = F_8 ( V_2 , V_150 ) ;
F_35 ( V_2 , V_150 , V_204 |
V_198 |
V_200 |
V_195 |
V_206 ) ;
V_2 -> V_71 |= V_83 ;
F_126 ( V_2 ) ;
V_2 -> V_60 = ( V_2 -> V_60 & ~ V_214 ) | V_215 ;
return 0 ;
}
static int F_129 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_216 ] ;
V_33 -> V_21 . integer . V_21 [ 0 ] = ( V_44 & V_217 ) != 0 ;
return 0 ;
}
static int F_130 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_218 ;
int V_219 ;
int V_220 = ( V_2 -> V_45 [ V_150 ] & V_221 ) != 0 ;
V_218 = F_9 ( V_2 , V_216 , V_217 ,
V_33 -> V_21 . integer . V_21 [ 0 ] != 0
? V_217 : 0 ) ;
if ( V_218 < 0 )
return V_218 ;
V_219 = F_9 ( V_2 , V_150 , V_222 ,
( V_33 -> V_21 . integer . V_21 [ 0 ] != 0
|| V_220 )
? V_222 : 0 ) ;
if ( V_219 < 0 )
return V_219 ;
return ( V_218 > 0 || V_219 > 0 ) ? 1 : 0 ;
}
static int F_131 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_150 ] ;
V_33 -> V_21 . integer . V_21 [ 0 ] = ( V_44 & V_221 ) != 0 ;
return 0 ;
}
static int F_132 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_218 ;
int V_219 ;
int V_220 = ( V_2 -> V_45 [ V_216 ] & V_217 ) != 0 ;
V_218 = F_9 ( V_2 , V_150 , V_221 ,
V_33 -> V_21 . integer . V_21 [ 0 ] != 0
? V_221 : 0 ) ;
if ( V_218 < 0 )
return V_218 ;
V_219 = F_9 ( V_2 , V_150 , V_222 ,
( V_33 -> V_21 . integer . V_21 [ 0 ] != 0
|| V_220 )
? V_222 : 0 ) ;
if ( V_219 < 0 )
return V_219 ;
return ( V_218 > 0 || V_219 > 0 ) ? 1 : 0 ;
}
static int F_133 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_33 -> V_21 . integer . V_21 [ 0 ] = V_2 -> V_156 . V_157 . V_223 ;
return 0 ;
}
static int F_134 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned char V_224 = V_33 -> V_21 . integer . V_21 [ 0 ] != 0 ;
if ( V_224 != V_2 -> V_156 . V_157 . V_223 ) {
V_2 -> V_156 . V_157 . V_223 = V_224 ;
if ( V_2 -> V_38 -> V_39 )
V_2 -> V_38 -> V_39 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_135 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
unsigned short V_19 = V_2 -> V_45 [ V_225 ] ;
if ( ( V_19 & V_226 ) != 0 )
V_44 = 2 ;
else if ( ( V_19 & V_227 ) != 0 )
V_44 = 3 ;
else if ( ( V_19 & V_228 ) != 0 )
V_44 = 1 ;
else
V_44 = 0 ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = V_44 ;
return 0 ;
}
static int F_136 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_229 ;
unsigned short V_230 ;
unsigned short V_231 ;
int V_232 ;
int V_233 ;
int V_234 ;
switch ( V_33 -> V_21 . V_34 . V_35 [ 0 ] )
{
case 0 :
V_229 = 0 ;
V_230 = 0 ;
V_231 = 0 ;
break;
case 1 :
V_229 = V_235 ;
V_230 = V_236 ;
V_231 = V_228 ;
break;
case 2 :
V_229 = V_237 ;
V_230 = V_238 ;
V_231 = V_226 ;
break;
case 3 :
V_229 = V_239 ;
V_230 = V_240 ;
V_231 = V_227 ;
break;
default:
return - V_43 ;
}
V_232 = F_9 ( V_2 , V_225 ,
V_241 , V_229 ) ;
if ( V_232 < 0 )
return V_232 ;
V_233 = F_9 ( V_2 , V_216 ,
V_242 , V_230 ) ;
if ( V_233 < 0 )
return V_233 ;
V_234 = F_9 ( V_2 , V_225 ,
V_243 , V_231 ) ;
if ( V_234 < 0 )
return V_234 ;
return ( V_232 > 0 || V_233 > 0 || V_234 > 0 ) ? 1 : 0 ;
}
static void F_137 ( struct V_1 * V_2 )
{
unsigned short V_244 = 0 ;
unsigned short V_245 ;
if ( ! F_19 ( V_2 ) )
V_244 |= V_246 ;
if ( ! F_20 ( V_2 ) )
V_244 |= V_247 ;
if ( F_23 ( V_2 ) )
V_244 |= V_248 ;
else if ( V_2 -> V_156 . V_157 . V_223 != 0 )
V_244 |= V_249 ;
F_9 ( V_2 , V_150 ,
V_246 | V_247 |
V_250 ,
V_244 ) ;
if ( F_24 ( V_2 ) )
V_245 = V_251 ;
else if ( V_2 -> V_156 . V_157 . V_223 != 0 )
V_245 = V_252 ;
else
V_245 = V_253 ;
F_9 ( V_2 , V_151 ,
V_254 ,
V_245 ) ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_196 , 1 ) ) < 0 )
return V_7 ;
return F_1 ( V_2 , V_255 ,
F_42 ( V_212 ) ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
V_2 -> V_38 = & V_256 ;
V_2 -> V_71 |= V_83 ;
F_137 ( V_2 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0x7a , 0x400 , 0x400 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_257 ;
V_257 = F_21 ( V_2 ) ;
F_9 ( V_2 , V_258 , 1 << 9 ,
V_257 ? ( 1 << 9 ) : 0 ) ;
V_257 = F_22 ( V_2 ) ;
F_9 ( V_2 , V_259 , 1 << 12 ,
V_257 ? ( 1 << 12 ) : 0 ) ;
F_9 ( V_2 , V_258 , 1 << 10 ,
V_257 ? ( 1 << 10 ) : 0 ) ;
F_9 ( V_2 , V_260 , 0x100 ,
V_257 ? 0 : 0x100 ) ;
}
static int F_142 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_261 * V_262 = V_2 -> V_263 [ V_264 ] ;
if ( V_262 ) {
if ( V_33 -> V_21 . integer . V_21 [ 0 ] )
V_262 -> V_265 = V_266 ;
else
V_262 -> V_265 = V_267 ;
}
return F_143 ( V_28 , V_33 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_268 , F_42 ( V_268 ) ) ) < 0 )
return V_7 ;
if ( V_2 -> V_60 & V_61 ) {
if ( ( V_7 = F_1 ( V_2 , V_269 , F_42 ( V_269 ) ) ) < 0 )
return V_7 ;
}
if ( V_2 -> V_49 != V_270 )
F_4 ( V_2 , L_47 ,
V_271 ) ;
return 0 ;
}
static int F_145 ( struct V_1 * V_2 )
{
unsigned short V_44 ;
V_2 -> V_38 = & V_272 ;
V_44 = F_8 ( V_2 , V_273 ) & 0x3f ;
if ( V_44 < 3 )
V_2 -> V_49 = 0x414c4720 ;
else if ( V_44 < 0x10 )
V_2 -> V_49 = 0x414c4721 ;
else if ( V_44 < 0x20 )
V_2 -> V_49 = 0x414c4722 ;
else if ( V_44 < 0x30 )
V_2 -> V_49 = 0x414c4723 ;
V_2 -> V_156 . V_274 = ( V_2 -> V_49 == 0x414c4722 ||
V_2 -> V_49 == 0x414c4723 ) ;
F_35 ( V_2 , V_260 ,
F_8 ( V_2 , V_260 ) | 0x8000 ) ;
V_44 = F_8 ( V_2 , V_259 ) ;
if ( V_2 -> V_156 . V_274 &&
! ( V_2 -> V_129 == 0x1043 &&
V_2 -> V_130 == 0x1103 ) )
V_44 |= 0x03 ;
else
V_44 &= ~ 0x03 ;
F_35 ( V_2 , V_259 , V_44 ) ;
F_35 ( V_2 , V_258 , 0 ) ;
F_35 ( V_2 , V_275 ,
F_8 ( V_2 , V_275 ) | 0x01 ) ;
F_35 ( V_2 , V_260 ,
( F_8 ( V_2 , V_260 ) | 0x100 ) & ~ 0x10 ) ;
F_35 ( V_2 , V_276 , 0x0808 ) ;
F_35 ( V_2 , V_277 , 0x0808 ) ;
return 0 ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_257 ;
V_257 = F_21 ( V_2 ) ;
F_6 ( V_2 , V_258 , 1 << 9 ,
V_257 ? ( 1 << 9 ) : 0 , 0 ) ;
V_257 = F_22 ( V_2 ) ;
F_9 ( V_2 , V_259 , 1 << 12 ,
V_257 ? ( 1 << 12 ) : 0 ) ;
F_6 ( V_2 , V_258 , 1 << 10 ,
V_257 ? ( 1 << 10 ) : 0 , 0 ) ;
}
static int F_147 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_278 [ 3 ] = {
L_48 , L_49 , L_50
} ;
static const char * const V_279 [ 4 ] = {
L_48 , L_51 , L_52 , L_50
} ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
if ( V_2 -> V_156 . V_274 )
return F_12 ( V_30 , 1 , 4 , V_279 ) ;
else
return F_12 ( V_30 , 1 , 3 , V_278 ) ;
}
static int F_148 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_258 ] ;
V_44 = ( V_44 >> 12 ) & 3 ;
if ( V_2 -> V_156 . V_274 && V_44 == 3 )
V_44 = 0 ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = V_44 ;
return 0 ;
}
static int F_149 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_6 ( V_2 , V_258 , 3 << 12 ,
( unsigned short ) V_33 -> V_21 . V_34 . V_35 [ 0 ] << 12 ,
0 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_280 , F_42 ( V_280 ) ) ) < 0 )
return V_7 ;
if ( V_2 -> V_60 & V_61 ) {
if ( ( V_7 = F_1 ( V_2 , V_281 , F_42 ( V_281 ) ) ) < 0 )
return V_7 ;
}
return 0 ;
}
static int F_151 ( struct V_1 * V_2 )
{
unsigned int V_44 ;
if ( V_2 -> V_49 == V_282 ) {
V_2 -> V_156 . V_274 = 1 ;
if ( ( F_8 ( V_2 , V_273 ) & 0x3f ) == 2 ) {
V_2 -> V_49 = V_283 ;
V_2 -> V_156 . V_274 = 2 ;
}
}
V_2 -> V_38 = & V_284 ;
F_9 ( V_2 , V_26 , V_27 , V_132 ) ;
V_44 = F_8 ( V_2 , 0x7a ) ;
if ( V_2 -> V_156 . V_274 )
V_44 &= ~ ( 1 << 1 ) ;
else {
if ( V_2 -> V_129 == 0x1462 &&
( V_2 -> V_130 == 0x0131 ||
V_2 -> V_130 == 0x0161 ||
V_2 -> V_130 == 0x0351 ||
V_2 -> V_130 == 0x0471 ||
V_2 -> V_130 == 0x0061 ) )
V_44 &= ~ ( 1 << 1 ) ;
else
V_44 |= ( 1 << 1 ) ;
V_2 -> V_60 |= V_61 ;
}
V_44 &= ~ ( 1 << 12 ) ;
F_35 ( V_2 , 0x7a , V_44 ) ;
F_35 ( V_2 , V_258 , 1 << 15 ) ;
F_35 ( V_2 , V_276 , 0x0808 ) ;
F_35 ( V_2 , V_277 , 0x0808 ) ;
if ( V_2 -> V_49 == V_283 )
F_9 ( V_2 , 0x74 , 0x0800 , 0x0800 ) ;
return 0 ;
}
static void F_152 ( struct V_1 * V_2 )
{
int V_257 ;
int V_285 ;
V_257 = F_21 ( V_2 ) ;
F_9 ( V_2 , V_286 , ( 1 << 4 ) | ( 1 << 5 ) ,
V_257 ? ( 1 << 5 ) : ( 1 << 4 ) ) ;
F_9 ( V_2 , V_287 , 7 << 12 ,
V_257 ? ( 2 << 12 ) : ( 0 << 12 ) ) ;
V_257 = F_22 ( V_2 ) ;
F_9 ( V_2 , V_286 , ( 1 << 12 ) | ( 1 << 13 ) ,
V_257 ? ( 1 << 12 ) : ( 1 << 13 ) ) ;
F_9 ( V_2 , V_287 , 7 << 4 ,
V_257 ? ( 5 << 4 ) : ( 1 << 4 ) ) ;
V_285 = F_25 ( V_2 ) ;
F_9 ( V_2 , V_288 , 1 << 10 ,
V_285 ? ( 1 << 10 ) : ( 0 << 10 ) ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_289 , F_42 ( V_289 ) ) ) < 0 )
return V_7 ;
if ( V_2 -> V_60 & V_61 ) {
if ( ( V_7 = F_1 ( V_2 , V_281 , F_42 ( V_281 ) ) ) < 0 )
return V_7 ;
}
return 0 ;
}
static int F_154 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_290 ;
V_2 -> V_156 . V_274 = 0 ;
V_2 -> V_71 |= V_291 ;
F_9 ( V_2 , V_26 , V_27 , V_132 ) ;
F_35 ( V_2 , V_258 , 1 << 15 ) ;
F_35 ( V_2 , 0x7a , ( 1 << 1 ) | ( 1 << 4 ) | ( 0 << 5 ) | ( 1 << 6 ) |
( 1 << 7 ) | ( 0 << 12 ) | ( 1 << 13 ) | ( 0 << 14 ) ) ;
F_35 ( V_2 , 0x76 , ( 0 << 0 ) | ( 0 << 2 ) | ( 1 << 4 ) | ( 1 << 7 ) | ( 2 << 8 ) |
( 1 << 11 ) | ( 0 << 12 ) | ( 1 << 15 ) ) ;
F_35 ( V_2 , V_276 , 0x0808 ) ;
F_35 ( V_2 , V_277 , 0x0808 ) ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 )
{
struct V_14 * V_292 =
F_156 ( V_2 , L_53 ) ;
struct V_14 * V_293 =
F_156 ( V_2 , L_54 ) ;
if ( V_292 ) {
V_292 -> V_40 =
F_34 ( V_50 , 1 , 0x07 , 0 ) ;
F_67 ( V_2 ,
L_53 , L_55
) ;
}
if ( V_293 )
V_293 -> V_40 =
F_34 ( V_50 , 8 , 0x03 , 0 ) ;
F_67 ( V_2 ,
L_56 , L_57
) ;
F_67 ( V_2 ,
L_19 , L_58
) ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_294 ;
return 0 ;
}
static void F_158 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_295 , 1 << 10 ,
F_21 ( V_2 ) ? ( 1 << 10 ) : 0 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_296 , F_42 ( V_296 ) ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_297 ;
V_2 -> V_71 |= V_298 ;
F_35 ( V_2 , V_165 , 0x8000 ) ;
return 0 ;
}
static int F_161 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [] = { L_59 , L_60 } ;
return F_12 ( V_30 , 1 , 2 , V_31 ) ;
}
static int F_162 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_44 ;
V_44 = V_2 -> V_45 [ V_299 ] ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = ( V_44 >> 1 ) & 0x01 ;
return 0 ;
}
static int F_163 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_9 ( V_2 , V_299 ,
0x01 << 1 ,
( V_33 -> V_21 . V_34 . V_35 [ 0 ] & 0x01 ) << 1 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_300 , 1 << 10 ,
F_21 ( V_2 ) ? ( 1 << 10 ) : 0 ) ;
F_9 ( V_2 , V_300 , 0x3000 ,
F_22 ( V_2 ) ? 0x1000 : 0x2000 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_301 , F_42 ( V_301 ) ) ;
}
static int F_166 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_302 , F_42 ( V_302 ) ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
unsigned short V_44 ;
V_2 -> V_38 = & V_303 ;
V_2 -> V_71 |= V_304 | V_298 ;
F_35 ( V_2 , V_305 , 0x8000 ) ;
F_35 ( V_2 , V_165 , 0x8000 ) ;
V_44 = F_8 ( V_2 , V_306 ) ;
if ( V_44 & V_307 ) {
F_35 ( V_2 , V_299 ,
F_8 ( V_2 , V_299 ) | 0x01 ) ;
V_2 -> V_57 [ V_58 ] = V_59 ;
} else {
V_2 -> V_60 &= ~ V_61 ;
V_2 -> V_57 [ V_58 ] = 0 ;
}
V_44 = F_8 ( V_2 , V_300 ) & ( 1 << 4 ) ;
V_44 |= ( 1 << 3 ) ;
V_44 |= ( 1 << 13 ) ;
if ( ! ( V_2 -> V_60 & V_61 ) )
V_44 |= ( 1 << 14 ) ;
F_35 ( V_2 , V_300 , V_44 ) ;
F_35 ( V_2 , 0x70 , 0x0100 ) ;
F_35 ( V_2 , 0x72 , 0x0020 ) ;
if ( V_2 -> V_128 &&
V_2 -> V_129 == 0x1043 &&
V_2 -> V_130 == 0x1843 ) {
F_35 ( V_2 , V_299 ,
F_8 ( V_2 , V_299 ) & ~ 0x01 ) ;
F_35 ( V_2 , V_300 ,
F_8 ( V_2 , V_300 ) | ( 1 << 14 ) ) ;
}
return 0 ;
}
static void F_168 ( struct V_1 * V_2 )
{
static unsigned short V_308 [ 3 ] [ 2 ] = {
{ 0x0008 , 0x0000 } ,
{ 0x0000 , 0x0008 } ,
{ 0x0000 , 0x0008 } ,
} ;
static unsigned short V_309 [ 3 ] [ 2 ] = {
{ 0x0000 , 0x1000 } ,
{ 0x1000 , 0x0000 } ,
{ 0x0000 , 0x1000 } ,
} ;
static unsigned short V_310 [ 3 ] [ 2 ] = {
{ 0x0000 , 0x0400 } ,
{ 0x0000 , 0x0400 } ,
{ 0x0000 , 0x0400 } ,
} ;
static unsigned short V_311 [ 3 ] [ 2 ] = {
{ 0x2000 , 0x0880 } ,
{ 0x0000 , 0x2880 } ,
{ 0x2000 , 0x0800 } ,
} ;
unsigned short V_44 = 0 ;
V_44 |= V_308 [ V_2 -> V_156 . V_274 ] [ F_19 ( V_2 ) ] ;
V_44 |= V_309 [ V_2 -> V_156 . V_274 ] [ F_20 ( V_2 ) ] ;
V_44 |= V_310 [ V_2 -> V_156 . V_274 ] [ F_21 ( V_2 ) ] ;
V_44 |= V_311 [ V_2 -> V_156 . V_274 ] [ F_22 ( V_2 ) ] ;
F_9 ( V_2 , V_312 , 0x3c88 , V_44 ) ;
}
static int F_169 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * const V_31 [] = { L_10 , L_61 , L_62 } ;
return F_12 ( V_30 , 1 , 3 , V_31 ) ;
}
static int F_170 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
if ( V_2 -> V_45 [ V_313 ] & 0x1 )
V_33 -> V_21 . V_34 . V_35 [ 0 ] = 2 ;
else if ( V_2 -> V_45 [ V_314 ] & 0x2 )
V_33 -> V_21 . V_34 . V_35 [ 0 ] = 1 ;
else
V_33 -> V_21 . V_34 . V_35 [ 0 ] = 0 ;
return 0 ;
}
static int F_171 ( struct V_14 * V_28 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
if ( V_33 -> V_21 . V_34 . V_35 [ 0 ] == 2 )
return F_9 ( V_2 , V_313 , 0x1 , 0x1 ) ;
F_9 ( V_2 , V_313 , 0x1 , 0 ) ;
return F_9 ( V_2 , V_314 , 0x2 ,
V_33 -> V_21 . V_34 . V_35 [ 0 ] == 1 ? 0x2 : 0 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_315 , F_42 ( V_315 ) ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_316 , F_42 ( V_316 ) ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
unsigned short V_44 ;
V_2 -> V_71 |= V_298 ;
F_35 ( V_2 , V_305 , 0x8808 ) ;
F_35 ( V_2 , V_165 , 0x8808 ) ;
V_2 -> V_156 . V_274 = 0 ;
if ( V_2 -> V_49 == V_317 ) {
unsigned short V_318 ;
V_44 = F_8 ( V_2 , V_26 ) ;
F_35 ( V_2 , V_26 , ( V_44 & ~ 0x0f ) | 0x01 ) ;
V_318 = F_8 ( V_2 , 0x60 ) ;
V_2 -> V_156 . V_274 = V_318 & 1 ;
F_35 ( V_2 , V_26 , V_44 ) ;
} else if ( V_2 -> V_49 == V_319 )
V_2 -> V_156 . V_274 = 2 ;
V_2 -> V_38 = & V_320 ;
V_2 -> V_60 |= V_61 ;
F_35 ( V_2 , V_306 , 0x05c0 ) ;
F_35 ( V_2 , V_314 , 0x0001 ) ;
V_2 -> V_57 [ V_58 ] = V_59 ;
#if 0
if (ac97->spec.dev_flags)
val = 0x0214;
else
val = 0x321c;
#endif
V_44 = F_8 ( V_2 , V_312 ) ;
V_44 |= ( 1 << 4 ) ;
F_35 ( V_2 , V_312 , V_44 ) ;
F_35 ( V_2 , 0x70 , 0x0100 ) ;
F_35 ( V_2 , 0x72 , 0x0020 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_321 , F_42 ( V_321 ) ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
unsigned short V_44 ;
V_2 -> V_38 = & V_322 ;
if ( V_2 -> V_60 & V_61 ) {
V_2 -> V_57 [ V_58 ] = V_59 ;
V_44 = F_8 ( V_2 , V_323 ) ;
V_44 |= 0x1 ;
F_35 ( V_2 , V_323 , V_44 ) ;
}
return 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , & V_324 [ 0 ] ,
F_42 ( V_324 ) ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_325 ;
V_2 -> V_71 |= V_72 ;
V_2 -> V_55 |= V_326 ;
return 0 ;
}
static struct V_14 * F_156 ( struct V_1 * V_2 ,
const char * V_10 )
{
struct V_12 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_16 = V_17 ;
strcpy ( V_49 . V_10 , V_10 ) ;
return F_5 ( V_2 -> V_8 -> V_9 , & V_49 ) ;
}
static int F_179 ( struct V_1 * V_2 , char * V_10 ,
const unsigned int * V_11 ,
const char * const * V_327 )
{
struct V_14 * V_15 ;
const char * const * V_328 ;
int V_7 ;
V_15 = F_180 ( V_10 , V_11 ) ;
if ( ! V_15 )
return - V_329 ;
V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_328 = V_327 ; * V_328 ; V_328 ++ ) {
struct V_14 * V_330 ;
V_330 = F_156 ( V_2 , * V_328 ) ;
if ( ! V_330 ) {
F_181 ( V_2 -> V_8 -> V_9 -> V_331 ,
L_63 , * V_328 ) ;
continue;
}
V_7 = F_182 ( V_15 , V_330 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_7 ;
if ( F_61 ( V_2 , 0x5a , 9 ) )
if ( ( V_7 = F_1 ( V_2 , & V_332 [ 0 ] , 1 ) ) < 0 )
return V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_332 [ 1 ] , F_42 ( V_332 ) - 1 ) ) < 0 )
return V_7 ;
V_15 = F_156 ( V_2 , L_47 ) ;
if ( ! V_15 )
return - V_43 ;
F_67 ( V_2 , L_41 , L_34 ) ;
V_7 = F_179 ( V_2 , L_47 ,
V_15 -> V_11 . V_18 , V_333 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_179 ( V_2 , L_64 ,
NULL , V_334 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_184 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_335 ;
return 0 ;
}
static int F_185 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static const char * const V_31 [] = { L_65 , L_66 ,
L_67 , L_68 ,
L_69 , L_70 ,
L_71 , L_72 } ;
return F_12 ( V_30 , 1 , 8 , V_31 ) ;
}
static int F_186 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
T_2 V_336 , V_337 ;
struct V_1 * V_338 ;
V_338 = F_14 ( V_28 ) ;
V_336 = F_8 ( V_338 , 0x7a ) >> 14 ;
V_337 = F_8 ( V_338 , 0x20 ) >> 8 ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = ( V_336 << 1 ) + V_337 ;
return 0 ;
}
static int F_187 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
T_2 V_336 , V_337 , V_339 ;
struct V_1 * V_338 ;
V_338 = F_14 ( V_28 ) ;
V_336 = V_33 -> V_21 . V_34 . V_35 [ 0 ] >> 1 ;
V_337 = V_33 -> V_21 . V_34 . V_35 [ 0 ] & 1 ;
V_339 = F_8 ( V_338 , 0x7a ) ;
F_35 ( V_338 , 0x7a , ( V_339 & 0x3FFF ) + ( V_336 << 14 ) ) ;
V_339 = F_8 ( V_338 , 0x20 ) ;
F_35 ( V_338 , 0x20 , ( V_339 & 0xFEFF ) + ( V_337 << 8 ) ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
int V_44 ;
V_7 = F_1 ( V_2 , & V_340 [ 0 ] ,
F_42 ( V_340 ) ) ;
V_44 = F_8 ( V_2 , 0x5c ) ;
if ( ! ( V_44 & 0x20 ) )
F_35 ( V_2 , 0x5c , 0x20 ) ;
V_2 -> V_60 |= V_61 ;
V_2 -> V_57 [ V_58 ] = V_341 | V_59 ;
V_2 -> V_38 = & V_335 ;
return V_7 ;
}
static int F_189 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
return F_12 ( V_30 , 1 , 4 ,
V_342 [ V_28 -> V_40 ] . V_343 ) ;
}
static int F_190 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
unsigned short V_344 , V_345 ;
struct V_1 * V_338 = F_14 ( V_28 ) ;
F_7 ( & V_338 -> V_25 ) ;
V_344 = F_8 ( V_338 , V_26 ) & V_27 ;
F_9 ( V_338 , V_26 , V_27 , 0 ) ;
V_345 = F_8 ( V_338 , 0x60 ) &
V_342 [ V_28 -> V_40 ] . V_20 ;
F_9 ( V_338 , V_26 , V_27 , V_344 ) ;
F_10 ( & V_338 -> V_25 ) ;
V_33 -> V_21 . V_34 . V_35 [ 0 ] = V_345 >>
V_342 [ V_28 -> V_40 ] . V_119 ;
return 0 ;
}
static int F_191 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
return F_6 ( F_14 ( V_28 ) , 0x60 ,
V_342 [ V_28 -> V_40 ] . V_20 ,
V_33 -> V_21 . V_34 . V_35 [ 0 ] <<
V_342 [ V_28 -> V_40 ] . V_119 ,
0 ) ;
}
static int F_192 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static const char * const V_346 [] = { L_73 , L_74 } ;
return F_12 ( V_30 , 1 , 2 , V_346 ) ;
}
static int F_193 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
V_33 -> V_21 . V_34 . V_35 [ 0 ] =
( F_8 ( F_14 ( V_28 ) , 0x5c ) & 0x0008 ) >> 3 ;
return 0 ;
}
static int F_194 ( struct V_14 * V_28 ,
struct V_32 * V_33 )
{
F_9 ( F_14 ( V_28 ) , 0x5c , 0x0008 ,
V_33 -> V_21 . V_34 . V_35 [ 0 ] << 3 ) ;
return F_9 ( F_14 ( V_28 ) , 0x76 , 0x0008 ,
V_33 -> V_21 . V_34 . V_35 [ 0 ] << 3 ) ;
}
static int F_195 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_347 ,
F_42 ( V_347 ) ) ;
}
static void F_196 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0x76 , 1 << 9 ,
F_21 ( V_2 ) ? ( 1 << 9 ) : 0 ) ;
F_9 ( V_2 , 0x76 , 1 << 10 ,
F_22 ( V_2 ) ? ( 1 << 10 ) : 0 ) ;
}
static int F_197 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_348 , F_42 ( V_348 ) ) ) < 0 )
return V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_349 , F_42 ( V_349 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_350 ;
F_35 ( V_2 , 0x5E , 0x0808 ) ;
F_35 ( V_2 , 0x7A , 0x0808 ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < F_42 ( V_351 ) ; V_6 ++ )
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_200 ( & V_351 [ V_6 ] , V_2 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_352 ;
F_35 ( V_2 , 0x5c , 0xf210 ) ;
F_35 ( V_2 , 0x68 , 0 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 )
{
V_2 -> V_169 = V_353 ;
return 0 ;
}
static int F_203 ( struct V_1 * V_2 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < F_42 ( V_354 ) ; V_6 ++ )
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_200 ( & V_354 [ V_6 ] , V_2 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 )
{
V_2 -> V_38 = & V_355 ;
F_35 ( V_2 , 0x6a , 0x0050 ) ;
F_35 ( V_2 , 0x6c , 0x0030 ) ;
return 0 ;
}
