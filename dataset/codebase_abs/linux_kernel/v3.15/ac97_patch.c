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
static int F_11 ( struct V_14 * V_28 , struct V_29 * V_30 ,
const char * * V_31 , unsigned int V_32 )
{
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = V_32 ;
if ( V_30 -> V_21 . V_34 . V_36 > V_32 - 1 )
V_30 -> V_21 . V_34 . V_36 = V_32 - 1 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * V_31 [] = { L_1 , L_2 } ;
return F_11 ( V_28 , V_30 , V_31 , 2 ) ;
}
static int F_13 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = V_2 -> V_39 ;
return 0 ;
}
static int F_15 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned char V_40 = ! ! V_38 -> V_21 . V_34 . V_36 [ 0 ] ;
if ( V_40 != V_2 -> V_39 ) {
V_2 -> V_39 = V_40 ;
if ( V_2 -> V_41 -> V_42 )
V_2 -> V_41 -> V_42 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_16 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static const char * V_31 [] = { L_3 , L_4 , L_5 , L_6 } ;
return F_11 ( V_28 , V_30 , V_31 ,
V_28 -> V_43 ) ;
}
static int F_17 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = V_2 -> V_44 ;
return 0 ;
}
static int F_18 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned char V_45 = V_38 -> V_21 . V_34 . V_36 [ 0 ] ;
if ( V_45 >= V_28 -> V_43 )
return - V_46 ;
if ( V_45 != V_2 -> V_44 ) {
V_2 -> V_44 = V_45 ;
if ( V_2 -> V_41 -> V_42 )
V_2 -> V_41 -> V_42 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_44 >= 1 ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_44 >= 2 ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return ! V_2 -> V_39 && F_19 ( V_2 ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return ! V_2 -> V_39 && F_20 ( V_2 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
return ! V_2 -> V_39 && ! F_19 ( V_2 ) ;
}
static inline int F_24 ( struct V_1 * V_2 )
{
return ! V_2 -> V_39 && ! F_20 ( V_2 ) ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
return F_19 ( V_2 ) ;
}
static int F_26 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static char * V_31 [ 3 ] = {
L_7 , L_8 , L_9
} ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 3 ;
if ( V_30 -> V_21 . V_34 . V_36 > 2 )
V_30 -> V_21 . V_34 . V_36 = 2 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_27 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_49 ] ;
V_47 = ( V_47 >> 10 ) & 3 ;
if ( V_47 > 0 )
V_47 -- ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = V_47 ;
return 0 ;
}
static int F_28 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] > 2 )
return - V_46 ;
V_47 = ( V_38 -> V_21 . V_34 . V_36 [ 0 ] + 1 ) << 10 ;
return F_29 ( V_2 , V_49 , V_47 ) ;
}
static int F_30 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static char * V_31 [ 2 ] = { L_10 , L_11 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 2 ;
if ( V_30 -> V_21 . V_34 . V_36 > 1 )
V_30 -> V_21 . V_34 . V_36 = 1 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_31 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_50 ] ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = ( V_47 >> 1 ) & 1 ;
return 0 ;
}
static int F_32 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] > 1 )
return - V_46 ;
V_47 = V_38 -> V_21 . V_34 . V_36 [ 0 ] << 1 ;
return F_9 ( V_2 , V_50 , 0x0002 , V_47 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_7 ;
V_15 = F_3 ( & V_51 [ 0 ] , V_2 ) ;
V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
strcpy ( V_15 -> V_52 . V_10 , L_12 ) ;
V_15 -> V_43 = F_34 ( V_53 , 9 , 7 , 0 ) ;
F_35 ( V_2 , V_53 , 0x0000 ) ;
V_7 = F_2 ( V_2 -> V_8 -> V_9 ,
F_3 ( & V_54 ,
V_2 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_49 , 0x0c00 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_1 ( V_2 , & V_55 [ 0 ] , 3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 ,
V_56 , 3 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_50 , 0xa201 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_57 ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_58 |= 0x04 << 10 ;
V_2 -> V_60 [ V_61 ] = V_62 ;
V_2 -> V_63 |= V_64 ;
return 0 ;
}
static int F_38 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_31 [ 3 ] = { L_13 , L_14 , L_15 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 3 ;
if ( V_30 -> V_21 . V_34 . V_36 > 2 )
V_30 -> V_21 . V_34 . V_36 = 2 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_39 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_50 ] ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = ( V_47 & 0x0008 ) ? 2 : ( V_47 & 0x0020 ) ? 1 : 0 ;
return 0 ;
}
static int F_40 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] > 2 )
return - V_46 ;
V_47 = ( V_38 -> V_21 . V_34 . V_36 [ 0 ] == 2 ) ? 0x0008 :
( V_38 -> V_21 . V_34 . V_36 [ 0 ] == 1 ) ? 0x0020 : 0 ;
return F_9 ( V_2 , V_50 , 0x0028 , V_47 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_65 , F_42 ( V_65 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_66 ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_58 |= 0x04 << 10 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_7 , V_67 ;
for ( V_67 = 0 ; V_67 < F_42 ( V_68 ) ; V_67 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_68 [ V_67 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
F_35 ( V_2 , V_69 , 0x0808 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_70 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_7 , V_67 ;
for ( V_67 = 0 ; V_67 < F_42 ( V_71 ) ; V_67 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_71 [ V_67 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
F_35 ( V_2 , V_72 , 0x0200 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_73 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_70 ;
#ifdef F_49
V_2 -> V_74 |= V_75 | V_76 ;
#endif
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_7 , V_67 ;
for ( V_67 = 0 ; V_67 < F_42 ( V_77 ) ; V_67 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_77 [ V_67 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
F_35 ( V_2 , V_78 , 0x0808 ) ;
F_35 ( V_2 , V_79 , 0x0808 ) ;
F_35 ( V_2 , V_80 , 0x0808 ) ;
F_35 ( V_2 , V_81 , 0x0808 ) ;
F_35 ( V_2 , V_82 , 0x0808 ) ;
F_35 ( V_2 , V_83 , 0x0000 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_84 ;
V_2 -> V_74 |= V_85 | V_86 | V_87 |
V_88 | V_75 | V_89 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_7 , V_67 ;
for ( V_67 = 0 ; V_67 < F_42 ( V_90 ) ; V_67 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_90 [ V_67 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_7 , V_67 ;
for ( V_67 = 0 ; V_67 < F_42 ( V_91 ) ; V_67 ++ ) {
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_3 ( & V_91 [ V_67 ] , V_2 ) ) ) < 0 )
return V_7 ;
}
F_35 ( V_2 , V_82 , 0x0808 ) ;
F_35 ( V_2 , V_92 , 0x0808 ) ;
F_35 ( V_2 , V_93 , 0x0808 ) ;
F_35 ( V_2 , V_94 , 0x00da ) ;
F_35 ( V_2 , V_83 , 0x0808 ) ;
F_35 ( V_2 , V_80 , 0xd612 ) ;
F_35 ( V_2 , V_95 , 0x1ba0 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_96 , 0xfeff ) ;
F_35 ( V_2 , V_97 , 0xffff ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_96 , 0xda00 ) ;
F_35 ( V_2 , V_97 , 0x3810 ) ;
F_35 ( V_2 , V_98 , 0x0 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_99 ;
V_2 -> V_74 |= V_85 | V_86 | V_100 |
V_88 | V_75 | V_89 | V_101 |
V_102 ;
V_2 -> V_103 &= ~ V_104 ;
F_35 ( V_2 , V_96 , 0xda00 ) ;
F_35 ( V_2 , V_97 , 0x3810 ) ;
F_35 ( V_2 , V_98 , 0x0 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
F_35 ( V_2 , 0x26 , 0x0300 ) ;
F_35 ( V_2 , 0x26 , 0x0000 ) ;
F_35 ( V_2 , V_105 , 0x0000 ) ;
F_35 ( V_2 , V_106 , 0x0000 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_7 ;
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 = F_3 ( & V_51 [ 0 ] , V_2 ) ) ) < 0 )
return V_7 ;
strcpy ( V_15 -> V_52 . V_10 , L_16 ) ;
V_15 -> V_43 = F_34 ( V_53 , 2 , 3 , 0 ) ;
F_35 ( V_2 , V_53 , 0x0000 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_7 ;
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 = F_3 ( & V_51 [ 0 ] , V_2 ) ) ) < 0 )
return V_7 ;
strcpy ( V_15 -> V_52 . V_10 , L_16 ) ;
V_15 -> V_43 = F_34 ( V_53 , 0 , 3 , 0 ) ;
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 = F_3 ( & V_51 [ 0 ] , V_2 ) ) ) < 0 )
return V_7 ;
strcpy ( V_15 -> V_52 . V_10 , L_17 ) ;
V_15 -> V_43 = F_34 ( V_53 , 2 , 3 , 0 ) ;
F_35 ( V_2 , V_53 , 0x0000 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_7 ;
F_35 ( V_2 , V_107 , F_8 ( V_2 , V_107 ) & ~ 0x0003 ) ;
if ( F_61 ( V_2 , V_107 , 1 ) )
if ( ( V_7 = F_1 ( V_2 , & V_108 [ 0 ] , 1 ) ) < 0 )
return V_7 ;
if ( F_61 ( V_2 , V_107 , 0 ) )
if ( ( V_7 = F_1 ( V_2 , & V_108 [ 1 ] , 1 ) ) < 0 )
return V_7 ;
if ( F_61 ( V_2 , V_109 , 2 ) )
if ( ( V_7 = F_1 ( V_2 , & V_110 , 1 ) ) < 0 )
return V_7 ;
if ( F_61 ( V_2 , V_109 , 3 ) )
if ( ( V_7 = F_1 ( V_2 , & V_111 , 1 ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_112 ;
return 0 ;
}
static int F_63 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_7 ;
F_7 ( & V_2 -> V_25 ) ;
F_64 ( V_2 , V_113 , 0xabba ) ;
V_7 = F_9 ( V_2 , V_114 , 0x0010 ,
( V_38 -> V_21 . integer . V_21 [ 0 ] & 1 ) << 4 ) ;
F_64 ( V_2 , V_113 , 0 ) ;
F_10 ( & V_2 -> V_25 ) ;
return V_7 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_7 ;
F_66 ( V_2 , L_18 , NULL ) ;
F_67 ( V_2 , L_19 , L_20 ) ;
if ( ( V_7 = F_1 ( V_2 , & V_115 , 1 ) ) < 0 )
return V_7 ;
return F_60 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
unsigned int V_116 , V_117 ;
V_2 -> V_41 = & V_118 ;
V_2 -> V_58 |= 0x10 ;
V_116 = F_8 ( V_2 , V_114 ) & 0x8000 ;
V_117 = F_8 ( V_2 , V_107 ) ;
if ( ( V_116 == 0 ) && ( V_117 == 0 ) ) {
F_35 ( V_2 , V_119 , 0xabba ) ;
F_35 ( V_2 , V_120 , 0x1000 ) ;
F_35 ( V_2 , V_113 , 0xabba ) ;
F_35 ( V_2 , V_114 , 0x0007 ) ;
} else if ( ( V_116 == 0x8000 ) && ( V_117 == 0 ) ) {
F_35 ( V_2 , V_119 , 0xabba ) ;
F_35 ( V_2 , V_120 , 0x1001 ) ;
F_35 ( V_2 , V_109 , 0x0008 ) ;
} else if ( ( V_116 == 0x8000 ) && ( V_117 == 0x0080 ) ) {
}
F_35 ( V_2 , V_121 , 0x0000 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_112 ;
if ( F_8 ( V_2 , V_107 ) == 0 ) {
F_35 ( V_2 , V_119 , 0xabba ) ;
F_35 ( V_2 , V_120 , 0x4000 ) ;
F_35 ( V_2 , V_113 , 0xabba ) ;
F_35 ( V_2 , V_114 , 0x0002 ) ;
}
F_35 ( V_2 , V_121 , 0x0000 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_112 ;
F_35 ( V_2 , V_119 , 0xabba ) ;
F_35 ( V_2 , V_120 , 0x0000 ) ;
F_35 ( V_2 , V_113 , 0xabba ) ;
F_35 ( V_2 , V_114 , 0x0002 ) ;
F_35 ( V_2 , V_121 , 0x0000 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_112 ;
F_35 ( V_2 , V_119 , 0xabba ) ;
F_35 ( V_2 , V_120 , 0x0000 ) ;
F_35 ( V_2 , V_113 , 0xabba ) ;
F_35 ( V_2 , V_114 , 0x0002 ) ;
F_35 ( V_2 , V_121 , 0x0000 ) ;
return 0 ;
}
static int F_72 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_31 [ 5 ] = { L_21 , L_22 ,
L_23 , L_24 , L_25 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 5 ;
if ( V_30 -> V_21 . V_34 . V_36 > 4 )
V_30 -> V_21 . V_34 . V_36 = 4 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_73 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_122 = V_28 -> V_43 ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_123 ] >> V_122 ;
if ( ! ( V_47 & 4 ) )
V_38 -> V_21 . V_34 . V_36 [ 0 ] = 0 ;
else
V_38 -> V_21 . V_34 . V_36 [ 0 ] = 1 + ( V_47 & 3 ) ;
return 0 ;
}
static int F_74 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_122 = V_28 -> V_43 ;
unsigned short V_47 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] > 4 )
return - V_46 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] == 0 )
V_47 = 0 ;
else
V_47 = 4 | ( V_38 -> V_21 . V_34 . V_36 [ 0 ] - 1 ) ;
return F_6 ( V_2 , V_123 ,
7 << V_122 , V_47 << V_122 , 0 ) ;
}
static int F_75 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_31 [ 7 ] = { L_26 , L_27 , L_28 ,
L_29 , L_30 , L_31 , L_32 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 7 ;
if ( V_30 -> V_21 . V_34 . V_36 > 6 )
V_30 -> V_21 . V_34 . V_36 = 6 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_76 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_122 = V_28 -> V_43 ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_124 ] ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = ( V_47 >> V_122 ) & 7 ;
return 0 ;
}
static int F_77 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_122 = V_28 -> V_43 ;
return F_6 ( V_2 , V_124 , 7 << V_122 ,
V_38 -> V_21 . V_34 . V_36 [ 0 ] << V_122 , 0 ) ;
}
static int F_78 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_31 [ 3 ] = { L_33 , L_29 , L_30 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 3 ;
if ( V_30 -> V_21 . V_34 . V_36 > 2 )
V_30 -> V_21 . V_34 . V_36 = 2 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_79 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = V_2 -> V_48 [ V_125 ] & 3 ;
return 0 ;
}
static int F_80 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_6 ( V_2 , V_125 , 3 ,
V_38 -> V_21 . V_34 . V_36 [ 0 ] , 0 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_60 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_126 ,
F_42 ( V_126 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_67 ( V_2 , L_19 , L_34 ) ;
F_67 ( V_2 , L_35 , L_36 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
static unsigned short V_48 [ 4 ] = {
V_123 ,
V_125 ,
V_124 ,
V_127
} ;
static unsigned short V_128 [ 4 ] = {
0xd794 ,
0x2001 ,
0x0201 ,
0x0040
} ;
static unsigned short V_129 [ 4 ] = {
0xfc70 ,
0x2102 ,
0x0203 ,
0x0041
} ;
unsigned short * V_130 = V_128 ;
int V_67 ;
if ( V_2 -> V_131 &&
V_2 -> V_132 == 0x107b &&
V_2 -> V_133 == 0x0601 )
V_130 = V_129 ;
V_2 -> V_41 = & V_134 ;
F_9 ( V_2 , V_26 , V_27 , V_135 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ )
F_35 ( V_2 , V_48 [ V_67 ] , V_130 [ V_67 ] ) ;
V_2 -> V_74 |= V_86 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_55 [ 0 ] , 3 ) ) < 0 )
return V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_136 [ 0 ] , 1 ) ) < 0 )
return V_7 ;
switch ( V_2 -> V_52 & V_137 ) {
case V_138 :
if ( ( V_7 = F_1 ( V_2 , & V_136 [ 1 ] , 1 ) ) < 0 )
return V_7 ;
break;
}
F_35 ( V_2 , V_139 , 0x0a20 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_140 ;
V_2 -> V_74 |= V_141 ;
V_2 -> V_60 [ V_61 ] &= ~ V_142 ;
V_2 -> V_63 |= V_64 ;
F_35 ( V_2 , V_143 , 0x0080 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
V_2 -> V_74 |= V_144 ;
return F_84 ( V_2 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_55 [ 0 ] , 3 ) ) < 0 )
return V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_145 [ 0 ] , 1 ) ) < 0 )
return V_7 ;
F_35 ( V_2 , V_146 ,
F_8 ( V_2 , V_146 ) & ~ ( V_147 | V_148 | V_149 ) ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_150 ;
V_2 -> V_74 |= V_151 ;
V_2 -> V_63 |= V_64 ;
V_2 -> V_60 [ V_61 ] = V_62 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0x5c , 0x01 , 0x01 ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
static unsigned short V_152 [] = {
V_153 , V_154 , V_155 ,
} ;
int V_67 , V_156 ;
for ( V_67 = 0 ; V_67 < ( int ) F_42 ( V_152 ) ; V_67 ++ ) {
unsigned short V_19 = V_152 [ V_67 ] ;
if ( F_90 ( V_19 , V_2 -> V_157 ) ) {
F_64 ( V_2 , V_19 , V_2 -> V_48 [ V_19 ] ) ;
F_8 ( V_2 , V_19 ) ;
}
}
if ( ! ( V_2 -> V_74 & V_158 ) )
F_91 ( V_2 ) ;
else {
for ( V_156 = 0 ; V_156 < 3 ; V_156 ++ ) {
if ( ! V_2 -> V_159 . V_160 . V_52 [ V_156 ] )
continue;
F_9 ( V_2 , V_154 , 0x7000 ,
V_2 -> V_159 . V_160 . V_161 [ V_156 ] | V_2 -> V_159 . V_160 . V_162 [ V_156 ] ) ;
V_2 -> V_8 -> V_163 -> V_164 ( V_2 , V_165 , V_2 -> V_159 . V_160 . V_166 [ V_156 ] ) ;
}
F_9 ( V_2 , V_154 , 0x7000 , 0x7000 ) ;
for ( V_67 = 2 ; V_67 < 0x7c ; V_67 += 2 ) {
if ( V_67 == V_98 || V_67 == V_167 )
continue;
if ( F_90 ( V_67 , V_2 -> V_157 ) ) {
if ( V_67 == V_168 ) {
for ( V_156 = 0 ; V_156 < 3 ; V_156 ++ ) {
if ( ! V_2 -> V_159 . V_160 . V_52 [ V_156 ] )
continue;
F_9 ( V_2 , V_154 , 0x7000 ,
V_2 -> V_159 . V_160 . V_161 [ V_156 ] | V_2 -> V_159 . V_160 . V_162 [ V_156 ] ) ;
V_2 -> V_8 -> V_163 -> V_164 ( V_2 , V_168 , V_2 -> V_159 . V_160 . V_169 [ V_156 ] ) ;
}
F_9 ( V_2 , V_154 , 0x7000 , 0x7000 ) ;
continue;
} else if ( V_67 == V_170 ||
V_67 == V_165 ||
V_67 == V_154 )
continue;
}
F_64 ( V_2 , V_67 , V_2 -> V_48 [ V_67 ] ) ;
F_8 ( V_2 , V_67 ) ;
}
}
F_92 ( V_2 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_89 ( V_2 ) ;
F_35 ( V_2 , V_78 , 0x8080 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
unsigned short V_171 ;
V_171 = F_8 ( V_2 , V_154 ) ;
F_35 ( V_2 , V_154 , V_171 | 0x7000 ) ;
V_2 -> V_172 = V_173 ;
return 0 ;
}
static unsigned short F_95 ( struct V_1 * V_2 , int V_6 , unsigned short V_20 )
{
unsigned short V_47 ;
F_9 ( V_2 , V_154 , 0x7000 , V_20 ) ;
F_35 ( V_2 , V_165 , 0x0000 ) ;
V_47 = F_8 ( V_2 , V_174 ) ;
if ( ( V_47 & 0xff40 ) != 0x5340 )
return 0 ;
V_2 -> V_159 . V_160 . V_161 [ V_6 ] = V_20 ;
V_2 -> V_159 . V_160 . V_52 [ V_6 ] = V_47 ;
V_2 -> V_159 . V_160 . V_166 [ V_6 ] = 0x0000 ;
return V_20 ;
}
static int F_96 ( struct V_1 * V_2 , int V_6 , unsigned short V_175 )
{
static int V_176 [ 3 ] = { 1 << 12 , 1 << 14 , 1 << 13 } ;
unsigned short V_47 ;
F_9 ( V_2 , V_154 , 0x7000 , V_176 [ V_6 ] ) ;
F_35 ( V_2 , V_165 , 0x0004 ) ;
V_47 = F_8 ( V_2 , V_174 ) ;
if ( ( V_47 & 0xff40 ) != 0x5340 )
return 0 ;
if ( V_175 )
F_35 ( V_2 , V_165 , V_175 ) ;
V_2 -> V_159 . V_160 . V_162 [ V_6 ] = V_176 [ V_6 ] ;
V_2 -> V_159 . V_160 . V_52 [ V_6 ] = V_47 ;
V_2 -> V_159 . V_160 . V_166 [ V_6 ] = V_175 ? V_175 : 0x0004 ;
return 1 ;
}
static void F_97 ( struct V_1 * V_2 , int V_177 , int V_178 , int V_179 )
{
if ( V_2 -> V_159 . V_160 . V_161 [ V_178 ] || V_2 -> V_159 . V_160 . V_162 [ V_178 ] )
V_178 = - 1 ;
if ( V_2 -> V_159 . V_160 . V_161 [ V_179 ] || V_2 -> V_159 . V_160 . V_162 [ V_179 ] )
V_179 = - 1 ;
if ( V_178 < 0 && V_179 < 0 )
return;
F_9 ( V_2 , V_154 , 0x7000 ,
V_2 -> V_159 . V_160 . V_161 [ V_177 ] ) ;
F_35 ( V_2 , V_165 , 0x0002 ) ;
V_2 -> V_159 . V_160 . V_166 [ V_177 ] = 0x0002 ;
if ( V_178 >= 0 ) {
if ( V_179 < 0 )
F_96 ( V_2 , V_178 , 0 ) ;
else if ( F_96 ( V_2 , V_178 , 0x0006 ) )
F_96 ( V_2 , V_179 , 0 ) ;
else if ( F_96 ( V_2 , V_179 , 0x0006 ) )
F_96 ( V_2 , V_178 , 0 ) ;
} else if ( V_179 >= 0 ) {
F_96 ( V_2 , V_179 , 0 ) ;
}
}
static int F_98 ( struct V_1 * V_2 )
{
static const char V_180 [ 3 ] [ 2 ] = {
{ 2 , 1 } ,
{ 0 , 2 } ,
{ 0 , 1 }
} ;
unsigned short V_181 [ 3 ] ;
unsigned short V_47 ;
int V_6 , V_182 ;
V_47 = F_8 ( V_2 , V_154 ) ;
F_35 ( V_2 , V_154 , V_47 ) ;
V_181 [ 0 ] = F_95 ( V_2 , 0 , ( 1 << 12 ) ) ;
V_181 [ 1 ] = F_95 ( V_2 , 1 , ( 1 << 14 ) ) ;
V_181 [ 2 ] = F_95 ( V_2 , 2 , ( 1 << 13 ) ) ;
if ( ! ( V_181 [ 0 ] || V_181 [ 1 ] || V_181 [ 2 ] ) )
goto V_183;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
if ( V_2 -> V_159 . V_160 . V_161 [ V_6 ] )
F_97 ( V_2 , V_6 , V_180 [ V_6 ] [ 0 ] , V_180 [ V_6 ] [ 1 ] ) ;
if ( V_2 -> V_159 . V_160 . V_52 [ 1 ] ) {
V_2 -> V_74 |= V_158 ;
V_2 -> V_103 |= V_184 ;
}
if ( V_2 -> V_159 . V_160 . V_52 [ 2 ] ) {
V_2 -> V_74 |= V_158 ;
V_2 -> V_103 |= V_185 ;
}
V_183:
F_9 ( V_2 , V_154 , 0x7000 , 0x7000 ) ;
for ( V_6 = V_182 = 0 ; V_6 < 3 ; V_6 ++ )
if ( V_2 -> V_159 . V_160 . V_52 [ V_6 ] )
V_182 ++ ;
if ( V_182 == 1 ) {
F_35 ( V_2 , V_165 , 0x0000 ) ;
V_2 -> V_159 . V_160 . V_166 [ 0 ] =
V_2 -> V_159 . V_160 . V_166 [ 1 ] =
V_2 -> V_159 . V_160 . V_166 [ 2 ] = 0x0000 ;
}
V_2 -> V_63 = F_8 ( V_2 , V_167 ) ;
if ( V_2 -> V_159 . V_160 . V_52 [ 0 ] ) {
V_2 -> V_52 &= 0xffff0000 ;
V_2 -> V_52 |= V_2 -> V_159 . V_160 . V_52 [ 0 ] ;
}
V_2 -> V_41 = & V_186 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_187 , F_42 ( V_187 ) ) ) < 0 )
return V_7 ;
F_4 ( V_2 , L_37 ,
V_188 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
F_35 ( V_2 , V_153 , 0x0404 ) ;
V_2 -> V_41 = & V_189 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
F_4 ( V_2 , L_37 ,
V_188 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
F_35 ( V_2 , V_155 , 0x0010 ) ;
V_2 -> V_41 = & V_190 ;
return 0 ;
}
static int F_103 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_31 [ 2 ] = { L_10 , L_11 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 2 ;
if ( V_30 -> V_21 . V_34 . V_36 > 1 )
V_30 -> V_21 . V_34 . V_36 = 1 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_104 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_154 ] ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = ( V_47 >> 2 ) & 1 ;
return 0 ;
}
static int F_105 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] > 1 )
return - V_46 ;
V_47 = V_38 -> V_21 . V_34 . V_36 [ 0 ] << 2 ;
return F_9 ( V_2 , V_154 , 0x0004 , V_47 ) ;
}
static int F_106 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , & V_191 , 1 ) ;
}
static int F_107 ( struct V_1 * V_2 , const unsigned int * V_192 )
{
T_1 V_193 = ( ( T_1 ) V_2 -> V_132 << 16 ) | V_2 -> V_133 ;
for (; * V_192 ; V_192 ++ )
if ( * V_192 == V_193 )
return 1 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 )
{
if ( F_107 ( V_2 , V_194 ) )
return 0 ;
return F_1 ( V_2 , V_195 ,
F_42 ( V_195 ) ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
if ( F_107 ( V_2 , V_196 ) )
F_9 ( V_2 , V_155 , 1 << 11 , 1 << 11 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
V_2 -> V_41 = & V_197 ;
F_9 ( V_2 , V_153 , V_198 , V_198 ) ;
V_2 -> V_74 |= V_86 ;
F_109 ( V_2 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_199 , 1 ) ) < 0 )
return V_7 ;
if ( F_107 ( V_2 , V_194 ) )
return 0 ;
return F_1 ( V_2 , V_195 ,
F_42 ( V_195 ) ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
V_2 -> V_41 = & V_200 ;
F_9 ( V_2 , V_153 , V_198 , V_198 ) ;
V_2 -> V_74 |= V_86 ;
F_109 ( V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_153 ] ;
V_38 -> V_21 . integer . V_21 [ 0 ] = ! ( V_47 & V_201 ) ;
if ( V_2 -> V_159 . V_160 . V_202 )
V_38 -> V_21 . integer . V_21 [ 0 ] =
! V_38 -> V_21 . integer . V_21 [ 0 ] ;
return 0 ;
}
static int F_114 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = ! V_38 -> V_21 . integer . V_21 [ 0 ] ;
if ( V_2 -> V_159 . V_160 . V_202 )
V_47 = ! V_47 ;
V_47 = V_47 ? ( V_201 | V_203 ) : 0 ;
return F_9 ( V_2 , V_153 ,
V_201 | V_203 , V_47 ) ;
}
static int F_115 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_31 [ 3 ] = { L_38 , L_39 , L_40 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 3 ;
if ( V_30 -> V_21 . V_34 . V_36 > 2 )
V_30 -> V_21 . V_34 . V_36 = 2 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_116 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_153 ] ;
if ( ! ( V_47 & V_204 ) )
V_38 -> V_21 . V_34 . V_36 [ 0 ] = 0 ;
else
V_38 -> V_21 . V_34 . V_36 [ 0 ] = 1 + ( ( V_47 >> 8 ) & 1 ) ;
return 0 ;
}
static int F_117 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] > 2 )
return - V_46 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] == 0 )
V_47 = 0 ;
else
V_47 = V_204 |
( ( V_38 -> V_21 . V_34 . V_36 [ 0 ] - 1 ) << 8 ) ;
return F_9 ( V_2 , V_153 ,
V_205 | V_204 , V_47 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
unsigned short V_47 = 0 ;
if ( ! V_2 -> V_159 . V_160 . V_202 && F_23 ( V_2 ) )
V_47 |= ( 1 << 12 ) ;
if ( F_24 ( V_2 ) )
V_47 |= ( 1 << 11 ) ;
F_9 ( V_2 , V_153 , ( 1 << 11 ) | ( 1 << 12 ) , V_47 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_159 . V_160 . V_202 ) {
F_67 ( V_2 , L_41 ,
L_42 ) ;
F_67 ( V_2 , L_19 ,
L_41 ) ;
}
return F_1 ( V_2 , V_206 , F_42 ( V_206 ) ) ;
}
static int F_120 ( struct V_1 * V_2 )
{
unsigned short V_207 ;
F_98 ( V_2 ) ;
V_2 -> V_41 = & V_208 ;
if ( V_2 -> V_132 == 0x1043 &&
V_2 -> V_133 == 0x1193 )
V_2 -> V_159 . V_160 . V_202 = 1 ;
V_207 = F_8 ( V_2 , V_153 ) ;
V_207 |= V_198 | V_209 ;
if ( ! V_2 -> V_159 . V_160 . V_202 )
V_207 |= V_201 | V_203 ;
F_35 ( V_2 , V_153 , V_207 ) ;
V_2 -> V_74 |= V_86 ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_119 ( V_2 ) ) < 0 )
return V_7 ;
return F_1 ( V_2 , & V_199 , 1 ) ;
}
static int F_122 ( struct V_1 * V_2 )
{
F_120 ( V_2 ) ;
V_2 -> V_41 = & V_210 ;
return 0 ;
}
static int F_123 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static char * V_31 [ 4 ] = { L_43 , L_44 , L_45 , L_46 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 4 ;
if ( V_30 -> V_21 . V_34 . V_36 > 3 )
V_30 -> V_21 . V_34 . V_36 = 3 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 ,
V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_124 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
static const int V_211 [ 4 ] = { 2 , 0 , 1 , 3 } ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = ( V_2 -> V_48 [ V_153 ] & V_212 )
>> V_213 ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = V_211 [ V_47 ] ;
return 0 ;
}
static int F_125 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
static const int V_214 [ 4 ] = { 1 , 2 , 0 , 3 } ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] > 3 )
return - V_46 ;
V_47 = V_214 [ V_38 -> V_21 . V_34 . V_36 [ 0 ] ]
<< V_213 ;
return F_9 ( V_2 , V_153 ,
V_212 , V_47 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
F_118 ( V_2 ) ;
F_9 ( V_2 , V_154 , 1 << 9 ,
F_24 ( V_2 ) ? 1 << 9 : 0 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_7 ;
F_67 ( V_2 , L_41 ,
L_42 ) ;
F_67 ( V_2 , L_19 , L_41 ) ;
if ( ( V_7 = F_1 ( V_2 , & V_199 , 1 ) ) < 0 )
return V_7 ;
return F_1 ( V_2 , V_215 ,
F_42 ( V_215 ) ) ;
}
static int F_128 ( struct V_1 * V_2 )
{
unsigned short V_207 ;
F_98 ( V_2 ) ;
V_2 -> V_41 = & V_216 ;
V_207 = F_8 ( V_2 , V_153 ) ;
F_35 ( V_2 , V_153 , V_207 |
V_201 |
V_203 |
V_198 |
V_209 ) ;
V_2 -> V_74 |= V_86 ;
F_126 ( V_2 ) ;
V_2 -> V_63 = ( V_2 -> V_63 & ~ V_217 ) | V_218 ;
return 0 ;
}
static int F_129 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_219 ] ;
V_38 -> V_21 . integer . V_21 [ 0 ] = ( V_47 & V_220 ) != 0 ;
return 0 ;
}
static int F_130 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_221 ;
int V_222 ;
int V_223 = ( V_2 -> V_48 [ V_153 ] & V_224 ) != 0 ;
V_221 = F_9 ( V_2 , V_219 , V_220 ,
V_38 -> V_21 . integer . V_21 [ 0 ] != 0
? V_220 : 0 ) ;
if ( V_221 < 0 )
return V_221 ;
V_222 = F_9 ( V_2 , V_153 , V_225 ,
( V_38 -> V_21 . integer . V_21 [ 0 ] != 0
|| V_223 )
? V_225 : 0 ) ;
if ( V_222 < 0 )
return V_222 ;
return ( V_221 > 0 || V_222 > 0 ) ? 1 : 0 ;
}
static int F_131 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_153 ] ;
V_38 -> V_21 . integer . V_21 [ 0 ] = ( V_47 & V_224 ) != 0 ;
return 0 ;
}
static int F_132 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
int V_221 ;
int V_222 ;
int V_223 = ( V_2 -> V_48 [ V_219 ] & V_220 ) != 0 ;
V_221 = F_9 ( V_2 , V_153 , V_224 ,
V_38 -> V_21 . integer . V_21 [ 0 ] != 0
? V_224 : 0 ) ;
if ( V_221 < 0 )
return V_221 ;
V_222 = F_9 ( V_2 , V_153 , V_225 ,
( V_38 -> V_21 . integer . V_21 [ 0 ] != 0
|| V_223 )
? V_225 : 0 ) ;
if ( V_222 < 0 )
return V_222 ;
return ( V_221 > 0 || V_222 > 0 ) ? 1 : 0 ;
}
static int F_133 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_38 -> V_21 . integer . V_21 [ 0 ] = V_2 -> V_159 . V_160 . V_226 ;
return 0 ;
}
static int F_134 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned char V_227 = V_38 -> V_21 . integer . V_21 [ 0 ] != 0 ;
if ( V_227 != V_2 -> V_159 . V_160 . V_226 ) {
V_2 -> V_159 . V_160 . V_226 = V_227 ;
if ( V_2 -> V_41 -> V_42 )
V_2 -> V_41 -> V_42 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_135 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
unsigned short V_19 = V_2 -> V_48 [ V_228 ] ;
if ( ( V_19 & V_229 ) != 0 )
V_47 = 2 ;
else if ( ( V_19 & V_230 ) != 0 )
V_47 = 3 ;
else if ( ( V_19 & V_231 ) != 0 )
V_47 = 1 ;
else
V_47 = 0 ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = V_47 ;
return 0 ;
}
static int F_136 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_232 ;
unsigned short V_233 ;
unsigned short V_234 ;
int V_235 ;
int V_236 ;
int V_237 ;
switch ( V_38 -> V_21 . V_34 . V_36 [ 0 ] )
{
case 0 :
V_232 = 0 ;
V_233 = 0 ;
V_234 = 0 ;
break;
case 1 :
V_232 = V_238 ;
V_233 = V_239 ;
V_234 = V_231 ;
break;
case 2 :
V_232 = V_240 ;
V_233 = V_241 ;
V_234 = V_229 ;
break;
case 3 :
V_232 = V_242 ;
V_233 = V_243 ;
V_234 = V_230 ;
break;
default:
return - V_46 ;
}
V_235 = F_9 ( V_2 , V_228 ,
V_244 , V_232 ) ;
if ( V_235 < 0 )
return V_235 ;
V_236 = F_9 ( V_2 , V_219 ,
V_245 , V_233 ) ;
if ( V_236 < 0 )
return V_236 ;
V_237 = F_9 ( V_2 , V_228 ,
V_246 , V_234 ) ;
if ( V_237 < 0 )
return V_237 ;
return ( V_235 > 0 || V_236 > 0 || V_237 > 0 ) ? 1 : 0 ;
}
static void F_137 ( struct V_1 * V_2 )
{
unsigned short V_247 = 0 ;
unsigned short V_248 ;
if ( ! F_19 ( V_2 ) )
V_247 |= V_249 ;
if ( ! F_20 ( V_2 ) )
V_247 |= V_250 ;
if ( F_23 ( V_2 ) )
V_247 |= V_251 ;
else if ( V_2 -> V_159 . V_160 . V_226 != 0 )
V_247 |= V_252 ;
F_9 ( V_2 , V_153 ,
V_249 | V_250 |
V_253 ,
V_247 ) ;
if ( F_24 ( V_2 ) )
V_248 = V_254 ;
else if ( V_2 -> V_159 . V_160 . V_226 != 0 )
V_248 = V_255 ;
else
V_248 = V_256 ;
F_9 ( V_2 , V_154 ,
V_257 ,
V_248 ) ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , & V_199 , 1 ) ) < 0 )
return V_7 ;
return F_1 ( V_2 , V_258 ,
F_42 ( V_215 ) ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
V_2 -> V_41 = & V_259 ;
V_2 -> V_74 |= V_86 ;
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
int V_260 ;
V_260 = F_21 ( V_2 ) ;
F_9 ( V_2 , V_261 , 1 << 9 ,
V_260 ? ( 1 << 9 ) : 0 ) ;
V_260 = F_22 ( V_2 ) ;
F_9 ( V_2 , V_262 , 1 << 12 ,
V_260 ? ( 1 << 12 ) : 0 ) ;
F_9 ( V_2 , V_261 , 1 << 10 ,
V_260 ? ( 1 << 10 ) : 0 ) ;
F_9 ( V_2 , V_263 , 0x100 ,
V_260 ? 0 : 0x100 ) ;
}
static int F_142 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
struct V_264 * V_265 = V_2 -> V_266 [ V_267 ] ;
if ( V_265 ) {
if ( V_38 -> V_21 . integer . V_21 [ 0 ] )
V_265 -> V_268 = V_269 ;
else
V_265 -> V_268 = V_270 ;
}
return F_143 ( V_28 , V_38 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_271 , F_42 ( V_271 ) ) ) < 0 )
return V_7 ;
if ( V_2 -> V_63 & V_64 ) {
if ( ( V_7 = F_1 ( V_2 , V_272 , F_42 ( V_272 ) ) ) < 0 )
return V_7 ;
}
if ( V_2 -> V_52 != V_273 )
F_4 ( V_2 , L_47 ,
V_274 ) ;
return 0 ;
}
static int F_145 ( struct V_1 * V_2 )
{
unsigned short V_47 ;
V_2 -> V_41 = & V_275 ;
V_47 = F_8 ( V_2 , V_276 ) & 0x3f ;
if ( V_47 < 3 )
V_2 -> V_52 = 0x414c4720 ;
else if ( V_47 < 0x10 )
V_2 -> V_52 = 0x414c4721 ;
else if ( V_47 < 0x20 )
V_2 -> V_52 = 0x414c4722 ;
else if ( V_47 < 0x30 )
V_2 -> V_52 = 0x414c4723 ;
V_2 -> V_159 . V_277 = ( V_2 -> V_52 == 0x414c4722 ||
V_2 -> V_52 == 0x414c4723 ) ;
F_35 ( V_2 , V_263 ,
F_8 ( V_2 , V_263 ) | 0x8000 ) ;
V_47 = F_8 ( V_2 , V_262 ) ;
if ( V_2 -> V_159 . V_277 &&
! ( V_2 -> V_132 == 0x1043 &&
V_2 -> V_133 == 0x1103 ) )
V_47 |= 0x03 ;
else
V_47 &= ~ 0x03 ;
F_35 ( V_2 , V_262 , V_47 ) ;
F_35 ( V_2 , V_261 , 0 ) ;
F_35 ( V_2 , V_278 ,
F_8 ( V_2 , V_278 ) | 0x01 ) ;
F_35 ( V_2 , V_263 ,
( F_8 ( V_2 , V_263 ) | 0x100 ) & ~ 0x10 ) ;
F_35 ( V_2 , V_279 , 0x0808 ) ;
F_35 ( V_2 , V_280 , 0x0808 ) ;
return 0 ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_260 ;
V_260 = F_21 ( V_2 ) ;
F_6 ( V_2 , V_261 , 1 << 9 ,
V_260 ? ( 1 << 9 ) : 0 , 0 ) ;
V_260 = F_22 ( V_2 ) ;
F_9 ( V_2 , V_262 , 1 << 12 ,
V_260 ? ( 1 << 12 ) : 0 ) ;
F_6 ( V_2 , V_261 , 1 << 10 ,
V_260 ? ( 1 << 10 ) : 0 , 0 ) ;
}
static int F_147 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_281 [ 3 ] = { L_48 , L_49 , L_50 } ;
static char * V_282 [ 4 ] = { L_48 , L_51 , L_52 , L_50 } ;
struct V_1 * V_2 = F_14 ( V_28 ) ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = V_2 -> V_159 . V_277 ? 4 : 3 ;
if ( V_30 -> V_21 . V_34 . V_36 >= V_30 -> V_21 . V_34 . V_35 )
V_30 -> V_21 . V_34 . V_36 = V_30 -> V_21 . V_34 . V_35 - 1 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 ,
V_2 -> V_159 . V_277 ?
V_282 [ V_30 -> V_21 . V_34 . V_36 ] :
V_281 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_148 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_261 ] ;
V_47 = ( V_47 >> 12 ) & 3 ;
if ( V_2 -> V_159 . V_277 && V_47 == 3 )
V_47 = 0 ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = V_47 ;
return 0 ;
}
static int F_149 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_6 ( V_2 , V_261 , 3 << 12 ,
( unsigned short ) V_38 -> V_21 . V_34 . V_36 [ 0 ] << 12 ,
0 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_283 , F_42 ( V_283 ) ) ) < 0 )
return V_7 ;
if ( V_2 -> V_63 & V_64 ) {
if ( ( V_7 = F_1 ( V_2 , V_284 , F_42 ( V_284 ) ) ) < 0 )
return V_7 ;
}
return 0 ;
}
static int F_151 ( struct V_1 * V_2 )
{
unsigned int V_47 ;
if ( V_2 -> V_52 == V_285 ) {
V_2 -> V_159 . V_277 = 1 ;
if ( ( F_8 ( V_2 , V_276 ) & 0x3f ) == 2 ) {
V_2 -> V_52 = V_286 ;
V_2 -> V_159 . V_277 = 2 ;
}
}
V_2 -> V_41 = & V_287 ;
F_9 ( V_2 , V_26 , V_27 , V_135 ) ;
V_47 = F_8 ( V_2 , 0x7a ) ;
if ( V_2 -> V_159 . V_277 )
V_47 &= ~ ( 1 << 1 ) ;
else {
if ( V_2 -> V_132 == 0x1462 &&
( V_2 -> V_133 == 0x0131 ||
V_2 -> V_133 == 0x0161 ||
V_2 -> V_133 == 0x0351 ||
V_2 -> V_133 == 0x0471 ||
V_2 -> V_133 == 0x0061 ) )
V_47 &= ~ ( 1 << 1 ) ;
else
V_47 |= ( 1 << 1 ) ;
V_2 -> V_63 |= V_64 ;
}
V_47 &= ~ ( 1 << 12 ) ;
F_35 ( V_2 , 0x7a , V_47 ) ;
F_35 ( V_2 , V_261 , 1 << 15 ) ;
F_35 ( V_2 , V_279 , 0x0808 ) ;
F_35 ( V_2 , V_280 , 0x0808 ) ;
if ( V_2 -> V_52 == V_286 )
F_9 ( V_2 , 0x74 , 0x0800 , 0x0800 ) ;
return 0 ;
}
static void F_152 ( struct V_1 * V_2 )
{
int V_260 ;
int V_288 ;
V_260 = F_21 ( V_2 ) ;
F_9 ( V_2 , V_289 , ( 1 << 4 ) | ( 1 << 5 ) ,
V_260 ? ( 1 << 5 ) : ( 1 << 4 ) ) ;
F_9 ( V_2 , V_290 , 7 << 12 ,
V_260 ? ( 2 << 12 ) : ( 0 << 12 ) ) ;
V_260 = F_22 ( V_2 ) ;
F_9 ( V_2 , V_289 , ( 1 << 12 ) | ( 1 << 13 ) ,
V_260 ? ( 1 << 12 ) : ( 1 << 13 ) ) ;
F_9 ( V_2 , V_290 , 7 << 4 ,
V_260 ? ( 5 << 4 ) : ( 1 << 4 ) ) ;
V_288 = F_25 ( V_2 ) ;
F_9 ( V_2 , V_291 , 1 << 10 ,
V_288 ? ( 1 << 10 ) : ( 0 << 10 ) ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_292 , F_42 ( V_292 ) ) ) < 0 )
return V_7 ;
if ( V_2 -> V_63 & V_64 ) {
if ( ( V_7 = F_1 ( V_2 , V_284 , F_42 ( V_284 ) ) ) < 0 )
return V_7 ;
}
return 0 ;
}
static int F_154 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_293 ;
V_2 -> V_159 . V_277 = 0 ;
V_2 -> V_74 |= V_294 ;
F_9 ( V_2 , V_26 , V_27 , V_135 ) ;
F_35 ( V_2 , V_261 , 1 << 15 ) ;
F_35 ( V_2 , 0x7a , ( 1 << 1 ) | ( 1 << 4 ) | ( 0 << 5 ) | ( 1 << 6 ) |
( 1 << 7 ) | ( 0 << 12 ) | ( 1 << 13 ) | ( 0 << 14 ) ) ;
F_35 ( V_2 , 0x76 , ( 0 << 0 ) | ( 0 << 2 ) | ( 1 << 4 ) | ( 1 << 7 ) | ( 2 << 8 ) |
( 1 << 11 ) | ( 0 << 12 ) | ( 1 << 15 ) ) ;
F_35 ( V_2 , V_279 , 0x0808 ) ;
F_35 ( V_2 , V_280 , 0x0808 ) ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 )
{
struct V_14 * V_295 =
F_156 ( V_2 , L_53 ) ;
struct V_14 * V_296 =
F_156 ( V_2 , L_54 ) ;
if ( V_295 ) {
V_295 -> V_43 =
F_34 ( V_53 , 1 , 0x07 , 0 ) ;
F_67 ( V_2 ,
L_53 , L_55
) ;
}
if ( V_296 )
V_296 -> V_43 =
F_34 ( V_53 , 8 , 0x03 , 0 ) ;
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
V_2 -> V_41 = & V_297 ;
return 0 ;
}
static void F_158 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_298 , 1 << 10 ,
F_21 ( V_2 ) ? ( 1 << 10 ) : 0 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_299 , F_42 ( V_299 ) ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_300 ;
V_2 -> V_74 |= V_301 ;
F_35 ( V_2 , V_168 , 0x8000 ) ;
return 0 ;
}
static int F_161 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_31 [] = { L_59 , L_60 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 2 ;
if ( V_30 -> V_21 . V_34 . V_36 > 1 )
V_30 -> V_21 . V_34 . V_36 = 1 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_162 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned short V_47 ;
V_47 = V_2 -> V_48 [ V_302 ] ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = ( V_47 >> 1 ) & 0x01 ;
return 0 ;
}
static int F_163 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
return F_9 ( V_2 , V_302 ,
0x01 << 1 ,
( V_38 -> V_21 . V_34 . V_36 [ 0 ] & 0x01 ) << 1 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_303 , 1 << 10 ,
F_21 ( V_2 ) ? ( 1 << 10 ) : 0 ) ;
F_9 ( V_2 , V_303 , 0x3000 ,
F_22 ( V_2 ) ? 0x1000 : 0x2000 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_304 , F_42 ( V_304 ) ) ;
}
static int F_166 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_305 , F_42 ( V_305 ) ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
unsigned short V_47 ;
V_2 -> V_41 = & V_306 ;
V_2 -> V_74 |= V_307 | V_301 ;
F_35 ( V_2 , V_308 , 0x8000 ) ;
F_35 ( V_2 , V_168 , 0x8000 ) ;
V_47 = F_8 ( V_2 , V_309 ) ;
if ( V_47 & V_310 ) {
F_35 ( V_2 , V_302 ,
F_8 ( V_2 , V_302 ) | 0x01 ) ;
V_2 -> V_60 [ V_61 ] = V_62 ;
} else {
V_2 -> V_63 &= ~ V_64 ;
V_2 -> V_60 [ V_61 ] = 0 ;
}
V_47 = F_8 ( V_2 , V_303 ) & ( 1 << 4 ) ;
V_47 |= ( 1 << 3 ) ;
V_47 |= ( 1 << 13 ) ;
if ( ! ( V_2 -> V_63 & V_64 ) )
V_47 |= ( 1 << 14 ) ;
F_35 ( V_2 , V_303 , V_47 ) ;
F_35 ( V_2 , 0x70 , 0x0100 ) ;
F_35 ( V_2 , 0x72 , 0x0020 ) ;
if ( V_2 -> V_131 &&
V_2 -> V_132 == 0x1043 &&
V_2 -> V_133 == 0x1843 ) {
F_35 ( V_2 , V_302 ,
F_8 ( V_2 , V_302 ) & ~ 0x01 ) ;
F_35 ( V_2 , V_303 ,
F_8 ( V_2 , V_303 ) | ( 1 << 14 ) ) ;
}
return 0 ;
}
static void F_168 ( struct V_1 * V_2 )
{
static unsigned short V_311 [ 3 ] [ 2 ] = {
{ 0x0008 , 0x0000 } ,
{ 0x0000 , 0x0008 } ,
{ 0x0000 , 0x0008 } ,
} ;
static unsigned short V_312 [ 3 ] [ 2 ] = {
{ 0x0000 , 0x1000 } ,
{ 0x1000 , 0x0000 } ,
{ 0x0000 , 0x1000 } ,
} ;
static unsigned short V_313 [ 3 ] [ 2 ] = {
{ 0x0000 , 0x0400 } ,
{ 0x0000 , 0x0400 } ,
{ 0x0000 , 0x0400 } ,
} ;
static unsigned short V_314 [ 3 ] [ 2 ] = {
{ 0x2000 , 0x0880 } ,
{ 0x0000 , 0x2880 } ,
{ 0x2000 , 0x0800 } ,
} ;
unsigned short V_47 = 0 ;
V_47 |= V_311 [ V_2 -> V_159 . V_277 ] [ F_19 ( V_2 ) ] ;
V_47 |= V_312 [ V_2 -> V_159 . V_277 ] [ F_20 ( V_2 ) ] ;
V_47 |= V_313 [ V_2 -> V_159 . V_277 ] [ F_21 ( V_2 ) ] ;
V_47 |= V_314 [ V_2 -> V_159 . V_277 ] [ F_22 ( V_2 ) ] ;
F_9 ( V_2 , V_315 , 0x3c88 , V_47 ) ;
}
static int F_169 ( struct V_14 * V_28 , struct V_29 * V_30 )
{
static char * V_31 [] = { L_10 , L_61 , L_62 } ;
V_30 -> type = V_33 ;
V_30 -> V_5 = 1 ;
V_30 -> V_21 . V_34 . V_35 = 3 ;
if ( V_30 -> V_21 . V_34 . V_36 > 2 )
V_30 -> V_21 . V_34 . V_36 = 2 ;
strcpy ( V_30 -> V_21 . V_34 . V_10 , V_31 [ V_30 -> V_21 . V_34 . V_36 ] ) ;
return 0 ;
}
static int F_170 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
if ( V_2 -> V_48 [ V_316 ] & 0x1 )
V_38 -> V_21 . V_34 . V_36 [ 0 ] = 2 ;
else if ( V_2 -> V_48 [ V_317 ] & 0x2 )
V_38 -> V_21 . V_34 . V_36 [ 0 ] = 1 ;
else
V_38 -> V_21 . V_34 . V_36 [ 0 ] = 0 ;
return 0 ;
}
static int F_171 ( struct V_14 * V_28 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
if ( V_38 -> V_21 . V_34 . V_36 [ 0 ] == 2 )
return F_9 ( V_2 , V_316 , 0x1 , 0x1 ) ;
F_9 ( V_2 , V_316 , 0x1 , 0 ) ;
return F_9 ( V_2 , V_317 , 0x2 ,
V_38 -> V_21 . V_34 . V_36 [ 0 ] == 1 ? 0x2 : 0 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_318 , F_42 ( V_318 ) ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_319 , F_42 ( V_319 ) ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
unsigned short V_47 ;
V_2 -> V_74 |= V_301 ;
F_35 ( V_2 , V_308 , 0x8808 ) ;
F_35 ( V_2 , V_168 , 0x8808 ) ;
V_2 -> V_159 . V_277 = 0 ;
if ( V_2 -> V_52 == V_320 ) {
unsigned short V_321 ;
V_47 = F_8 ( V_2 , V_26 ) ;
F_35 ( V_2 , V_26 , ( V_47 & ~ 0x0f ) | 0x01 ) ;
V_321 = F_8 ( V_2 , 0x60 ) ;
V_2 -> V_159 . V_277 = V_321 & 1 ;
F_35 ( V_2 , V_26 , V_47 ) ;
} else if ( V_2 -> V_52 == V_322 )
V_2 -> V_159 . V_277 = 2 ;
V_2 -> V_41 = & V_323 ;
V_2 -> V_63 |= V_64 ;
F_35 ( V_2 , V_309 , 0x05c0 ) ;
F_35 ( V_2 , V_317 , 0x0001 ) ;
V_2 -> V_60 [ V_61 ] = V_62 ;
#if 0
if (ac97->spec.dev_flags)
val = 0x0214;
else
val = 0x321c;
#endif
V_47 = F_8 ( V_2 , V_315 ) ;
V_47 |= ( 1 << 4 ) ;
F_35 ( V_2 , V_315 , V_47 ) ;
F_35 ( V_2 , 0x70 , 0x0100 ) ;
F_35 ( V_2 , 0x72 , 0x0020 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_324 , F_42 ( V_324 ) ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
unsigned short V_47 ;
V_2 -> V_41 = & V_325 ;
if ( V_2 -> V_63 & V_64 ) {
V_2 -> V_60 [ V_61 ] = V_62 ;
V_47 = F_8 ( V_2 , V_326 ) ;
V_47 |= 0x1 ;
F_35 ( V_2 , V_326 , V_47 ) ;
}
return 0 ;
}
static struct V_14 * F_156 ( struct V_1 * V_2 ,
const char * V_10 )
{
struct V_12 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_16 = V_17 ;
strcpy ( V_52 . V_10 , V_10 ) ;
return F_5 ( V_2 -> V_8 -> V_9 , & V_52 ) ;
}
static int F_177 ( struct V_1 * V_2 , char * V_10 ,
const unsigned int * V_11 , const char * * V_327 )
{
struct V_14 * V_15 ;
const char * * V_328 ;
int V_7 ;
V_15 = F_178 ( V_10 , V_11 ) ;
if ( ! V_15 )
return - V_329 ;
V_7 = F_2 ( V_2 -> V_8 -> V_9 , V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_328 = V_327 ; * V_328 ; V_328 ++ ) {
struct V_14 * V_330 ;
V_330 = F_156 ( V_2 , * V_328 ) ;
if ( ! V_330 ) {
F_179 ( V_2 -> V_8 -> V_9 -> V_331 ,
L_63 , * V_328 ) ;
continue;
}
V_7 = F_180 ( V_15 , V_330 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
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
return - V_46 ;
F_67 ( V_2 , L_41 , L_34 ) ;
V_7 = F_177 ( V_2 , L_47 ,
V_15 -> V_11 . V_18 , V_333 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_177 ( V_2 , L_64 ,
NULL , V_334 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_335 ;
return 0 ;
}
static int F_183 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static const char * V_31 [] = { L_65 , L_66 ,
L_67 , L_68 ,
L_69 , L_70 ,
L_71 , L_72 } ;
return F_11 ( V_28 , V_30 , V_31 , 8 ) ;
}
static int F_184 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
T_2 V_336 , V_337 ;
struct V_1 * V_338 ;
V_338 = F_14 ( V_28 ) ;
V_336 = F_8 ( V_338 , 0x7a ) >> 14 ;
V_337 = F_8 ( V_338 , 0x20 ) >> 8 ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = ( V_336 << 1 ) + V_337 ;
return 0 ;
}
static int F_185 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
T_2 V_336 , V_337 , V_339 ;
struct V_1 * V_338 ;
V_338 = F_14 ( V_28 ) ;
V_336 = V_38 -> V_21 . V_34 . V_36 [ 0 ] >> 1 ;
V_337 = V_38 -> V_21 . V_34 . V_36 [ 0 ] & 1 ;
V_339 = F_8 ( V_338 , 0x7a ) ;
F_35 ( V_338 , 0x7a , ( V_339 & 0x3FFF ) + ( V_336 << 14 ) ) ;
V_339 = F_8 ( V_338 , 0x20 ) ;
F_35 ( V_338 , 0x20 , ( V_339 & 0xFEFF ) + ( V_337 << 8 ) ) ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
int V_47 ;
V_7 = F_1 ( V_2 , & V_340 [ 0 ] ,
F_42 ( V_340 ) ) ;
V_47 = F_8 ( V_2 , 0x5c ) ;
if ( ! ( V_47 & 0x20 ) )
F_35 ( V_2 , 0x5c , 0x20 ) ;
V_2 -> V_63 |= V_64 ;
V_2 -> V_60 [ V_61 ] = V_341 | V_62 ;
V_2 -> V_41 = & V_335 ;
return V_7 ;
}
static int F_187 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
return F_11 ( V_28 , V_30 ,
V_342 [ V_28 -> V_43 ] . V_35 ,
4 ) ;
}
static int F_188 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
unsigned short V_343 , V_344 ;
struct V_1 * V_338 = F_14 ( V_28 ) ;
F_7 ( & V_338 -> V_25 ) ;
V_343 = F_8 ( V_338 , V_26 ) & V_27 ;
F_9 ( V_338 , V_26 , V_27 , 0 ) ;
V_344 = F_8 ( V_338 , 0x60 ) &
V_342 [ V_28 -> V_43 ] . V_20 ;
F_9 ( V_338 , V_26 , V_27 , V_343 ) ;
F_10 ( & V_338 -> V_25 ) ;
V_38 -> V_21 . V_34 . V_36 [ 0 ] = V_344 >>
V_342 [ V_28 -> V_43 ] . V_122 ;
return 0 ;
}
static int F_189 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
return F_6 ( F_14 ( V_28 ) , 0x60 ,
V_342 [ V_28 -> V_43 ] . V_20 ,
V_38 -> V_21 . V_34 . V_36 [ 0 ] <<
V_342 [ V_28 -> V_43 ] . V_122 ,
0 ) ;
}
static int F_190 ( struct V_14 * V_28 ,
struct V_29 * V_30 )
{
static const char * V_345 [] = { L_73 , L_74 } ;
return F_11 ( V_28 , V_30 , V_345 , 2 ) ;
}
static int F_191 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
V_38 -> V_21 . V_34 . V_36 [ 0 ] =
( F_8 ( F_14 ( V_28 ) , 0x5c ) & 0x0008 ) >> 3 ;
return 0 ;
}
static int F_192 ( struct V_14 * V_28 ,
struct V_37 * V_38 )
{
F_9 ( F_14 ( V_28 ) , 0x5c , 0x0008 ,
V_38 -> V_21 . V_34 . V_36 [ 0 ] << 3 ) ;
return F_9 ( F_14 ( V_28 ) , 0x76 , 0x0008 ,
V_38 -> V_21 . V_34 . V_36 [ 0 ] << 3 ) ;
}
static int F_193 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_346 ,
F_42 ( V_346 ) ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0x76 , 1 << 9 ,
F_21 ( V_2 ) ? ( 1 << 9 ) : 0 ) ;
F_9 ( V_2 , 0x76 , 1 << 10 ,
F_22 ( V_2 ) ? ( 1 << 10 ) : 0 ) ;
}
static int F_195 ( struct V_1 * V_2 )
{
int V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_347 , F_42 ( V_347 ) ) ) < 0 )
return V_7 ;
if ( ( V_7 = F_1 ( V_2 , V_348 , F_42 ( V_348 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_349 ;
F_35 ( V_2 , 0x5E , 0x0808 ) ;
F_35 ( V_2 , 0x7A , 0x0808 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < F_42 ( V_350 ) ; V_6 ++ )
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_198 ( & V_350 [ V_6 ] , V_2 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_351 ;
F_35 ( V_2 , 0x5c , 0xf210 ) ;
F_35 ( V_2 , 0x68 , 0 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 )
{
V_2 -> V_172 = V_352 ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < F_42 ( V_353 ) ; V_6 ++ )
if ( ( V_7 = F_2 ( V_2 -> V_8 -> V_9 , F_198 ( & V_353 [ V_6 ] , V_2 ) ) ) < 0 )
return V_7 ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 )
{
V_2 -> V_41 = & V_354 ;
F_35 ( V_2 , 0x6a , 0x0050 ) ;
F_35 ( V_2 , 0x6c , 0x0030 ) ;
return 0 ;
}
