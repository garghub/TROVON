static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
volatile struct V_5 T_1 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( ( V_10 = F_3 ( & V_2 -> V_11 , V_7 , V_2 ) ) )
return V_10 ;
F_4 ( V_7 , & V_2 -> V_12 ) ;
F_5 ( & V_5 -> V_13 . V_14 , 0 ) ;
F_6 ( 100 ) ;
V_9 = V_7 -> V_9 ;
F_5 ( & V_5 -> V_15 . V_14 , V_9 -> V_15 | 0x80 ) ;
F_5 ( & V_5 -> V_16 . V_14 , V_7 -> V_17 + 3 ) ;
F_7 ( V_9 -> V_18 ) ;
F_6 ( 100 ) ;
F_5 ( & V_5 -> V_15 . V_14 , V_9 -> V_15 ) ;
return 0 ;
}
static inline int F_8 ( struct V_6 * V_7 ,
struct V_19 * V_11 )
{
return F_9 ( V_7 -> V_20 , V_7 -> V_17 , V_11 ) ;
}
static int
F_10 ( struct V_19 * V_11 , struct V_1 * V_2 )
{
int V_10 ;
struct V_6 V_7 ;
if ( ( V_10 = F_3 ( V_11 , & V_7 , V_2 ) ) )
return V_10 ;
F_8 ( & V_7 , V_11 ) ;
return 0 ;
}
static int F_11 ( int V_21 , struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 == NULL )
return 1 ;
switch ( V_21 ) {
case V_22 :
F_5 ( & V_4 -> V_5 -> V_15 . V_14 , V_9 -> V_15 ) ;
break;
case V_23 :
return 1 ;
case V_24 :
case V_25 :
F_5 ( & V_4 -> V_5 -> V_15 . V_14 , V_9 -> V_15 | 0x40 ) ;
break;
case V_26 :
F_5 ( & V_4 -> V_5 -> V_15 . V_14 , 0x66 ) ;
break;
}
return 0 ;
}
static int F_12 ( T_2 V_27 , T_2 V_28 , T_2 V_29 , T_2 V_30 ,
T_2 V_31 , struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
volatile struct V_32 T_1 * V_32 = V_4 -> V_32 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_27 > 255 )
return 1 ;
V_28 >>= 8 ;
V_29 >>= 8 ;
V_30 >>= 8 ;
F_5 ( & V_4 -> V_32 -> V_33 , V_27 ) ;
F_6 ( 1 ) ;
F_5 ( & V_32 -> V_34 , V_28 ) ;
F_5 ( & V_32 -> V_34 , V_29 ) ;
F_5 ( & V_32 -> V_34 , V_30 ) ;
if ( V_27 < 16 && V_7 -> V_17 == V_35 )
( ( V_36 * ) V_2 -> V_37 ) [ V_27 ] =
( V_27 << 10 ) | ( V_27 << 5 ) | V_27 ;
return 0 ;
}
static inline int F_13 ( int V_38 , int V_39 )
{
int V_40 ;
struct V_8 * V_9 = V_41 [ V_38 - 1 ] ;
if ( ( V_40 = V_9 -> V_40 [ V_39 ] ) == 0 )
V_40 = 2 * V_9 -> V_40 [ 0 ] ;
return V_9 -> V_42 * V_40 ;
}
static void F_7 ( unsigned char * V_43 )
{
#ifdef F_14
struct V_44 V_45 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 3 ; ++ V_46 ) {
F_15 ( & V_45 , NULL , 5 , V_47 , V_48 ,
0x50 , V_46 + 1 , V_43 [ V_46 ] ) ;
while ( ! V_45 . V_49 )
F_16 () ;
}
#endif
}
static void T_3 F_17 ( struct V_3 * V_4 )
{
V_4 -> V_50 = F_18 ( V_4 ) ;
F_19 ( V_51 L_1 , V_4 -> V_50 ) ;
#if ! F_20 ( V_52 ) && F_20 ( V_53 )
if ( V_54 == V_55 ) {
V_54 = F_21 ( V_56 ) ;
if ( V_54 <= 0
|| V_54 > V_57
|| ! V_41 [ V_54 - 1 ] )
V_54 = V_58 ;
}
#endif
if ( V_54 == V_58 )
V_54 = F_22 ( V_4 -> V_50 ) ;
if ( ! V_41 [ V_54 - 1 ] )
V_54 = V_59 ;
#if ! F_20 ( V_52 ) && F_20 ( V_53 )
if ( V_60 == V_61 )
V_60 = F_21 ( V_62 ) ;
#endif
if ( V_60 < V_63 || V_60 > V_35
|| V_41 [ V_54 - 1 ] -> V_40 [ V_60 ] == 0
|| F_13 ( V_54 , V_60 ) > V_4 -> V_64 )
V_60 = V_63 ;
F_19 ( V_51 L_2 ,
V_54 , V_60 ) ;
}
int T_3 F_23 ( void )
{
struct V_3 * V_4 ;
unsigned long V_65 , V_66 , V_67 ;
int V_10 ;
char * V_68 = NULL ;
if ( F_24 ( L_3 , & V_68 ) )
return - V_69 ;
F_25 ( V_68 ) ;
#ifdef V_52
if ( ! V_70 )
return - V_69 ;
if ( ! ( V_71 . V_72 == V_73
|| V_71 . V_72 == V_74 ) )
return - V_69 ;
V_65 = 0xf9000000 ;
V_66 = 0x50f24000 ;
V_67 = V_75 ;
#else
{
struct V_76 * V_77 ;
struct V_78 V_14 ;
V_77 = F_26 ( NULL , L_4 ) ;
if ( V_77 == 0 )
return 0 ;
if ( F_27 ( V_77 , 0 , & V_14 ) ) {
F_19 ( V_79 L_5 ) ;
return 0 ;
}
V_65 = V_14 . V_80 ;
V_66 = V_14 . V_80 + 0x304000 ;
V_67 = V_81 ;
}
#endif
V_4 = F_28 ( sizeof( * V_4 ) , V_82 ) ;
if ( V_4 == 0 )
return - V_83 ;
if ( ! F_29 ( V_65 , 0x100000 , L_3 ) ) {
F_30 ( V_4 ) ;
return 0 ;
}
V_4 -> V_64 = 0x100000 ;
V_4 -> V_65 = V_65 ;
V_4 -> V_84 = F_31 ( V_65 , V_4 -> V_64 , V_67 ) ;
V_4 -> V_66 = V_66 ;
V_4 -> V_32 = F_32 ( V_4 -> V_66 , 0x1000 ) ;
V_4 -> V_85 = V_66 + 0x6000 ;
V_4 -> V_5 = F_32 ( V_4 -> V_85 , 0x1000 ) ;
V_10 = - V_83 ;
if ( V_4 -> V_84 == NULL || V_4 -> V_32 == NULL
|| V_4 -> V_5 == NULL ) {
F_19 ( V_79 L_6 ) ;
goto V_86;
}
F_17 ( V_4 ) ;
F_9 ( V_54 , V_60 , & V_4 -> V_2 . V_11 ) ;
V_10 = F_33 ( & V_4 -> V_2 , V_4 ) ;
if ( V_10 < 0 )
goto V_86;
F_34 ( & V_4 -> V_2 . V_12 , V_4 ) ;
if ( F_1 ( & V_4 -> V_2 ) )
F_19 ( V_79 L_7 ) ;
if ( ( V_10 = F_35 ( & V_4 -> V_2 ) ) != 0 )
goto V_87;
V_1 ( & V_4 -> V_2 , L_8 ) ;
return 0 ;
V_87:
F_36 ( & V_4 -> V_2 . V_88 ) ;
V_86:
if ( V_4 -> V_84 )
F_37 ( V_4 -> V_84 ) ;
if ( V_4 -> V_32 )
F_37 ( V_4 -> V_32 ) ;
if ( V_4 -> V_5 )
F_37 ( V_4 -> V_5 ) ;
F_30 ( V_4 ) ;
return V_10 ;
}
static int F_18 ( struct V_3 * V_4 )
{
int V_50 , V_89 ;
F_5 ( & V_4 -> V_5 -> V_90 . V_14 , 0 ) ;
F_38 ( 20000 ) ;
V_50 = ( ( V_89 = F_39 ( & V_4 -> V_5 -> V_90 . V_14 ) ) & 0x70 ) << 4 ;
F_5 ( & V_4 -> V_5 -> V_90 . V_14 , 4 ) ;
F_38 ( 20000 ) ;
V_50 |= ( ( V_89 = F_39 ( & V_4 -> V_5 -> V_90 . V_14 ) ) & 0x30 ) ;
F_5 ( & V_4 -> V_5 -> V_90 . V_14 , 2 ) ;
F_38 ( 20000 ) ;
V_50 |= ( ( V_89 = F_39 ( & V_4 -> V_5 -> V_90 . V_14 ) ) & 0x40 ) >> 3 ;
V_50 |= ( V_89 & 0x10 ) >> 2 ;
F_5 ( & V_4 -> V_5 -> V_90 . V_14 , 1 ) ;
F_38 ( 20000 ) ;
V_50 |= ( ( V_89 = F_39 ( & V_4 -> V_5 -> V_90 . V_14 ) ) & 0x60 ) >> 5 ;
F_5 ( & V_4 -> V_5 -> V_90 . V_14 , 7 ) ;
return V_50 ;
}
static int F_3 ( struct V_19 * V_11 ,
struct V_6 * V_7 , const struct V_1 * V_1 )
{
int V_20 , V_17 ;
struct V_8 * V_9 ;
struct V_3 * V_4 =
F_2 ( V_1 , struct V_3 , V_2 ) ;
if ( F_40 ( V_11 , & V_20 , & V_17 ) != 0 ) {
F_19 ( V_79 L_9 ,
V_11 -> V_91 , V_11 -> V_92 , V_11 -> V_93 ) ;
return - V_94 ;
}
if ( V_20 < 1 || V_20 > V_57 || ! V_41 [ V_20 - 1 ] ) {
F_19 ( V_79 L_10 , V_20 ) ;
return - V_94 ;
}
if ( V_17 != V_63 && V_17 != V_35 ) {
F_19 ( V_79 L_11 , V_17 ) ;
return - V_94 ;
}
if ( V_11 -> V_95 > V_11 -> V_91 || V_11 -> V_96 > V_11 -> V_92
|| V_11 -> V_97 != 0 || V_11 -> V_98 != 0 ) {
return - V_94 ;
}
V_9 = V_41 [ V_20 - 1 ] ;
if ( V_9 -> V_40 [ V_17 ] == 0 ) {
F_19 ( V_79 L_12
L_13 , V_20 , V_17 ) ;
return - V_94 ;
}
if ( F_13 ( V_20 , V_17 ) > V_4 -> V_64 ) {
F_19 ( V_79 L_14
L_13 , V_20 , V_17 ) ;
return - V_94 ;
}
V_7 -> V_20 = V_20 ;
V_7 -> V_17 = V_17 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_91 = V_11 -> V_91 ;
V_7 -> V_92 = V_11 -> V_92 ;
V_7 -> V_99 = V_7 -> V_91 ;
V_7 -> V_100 = V_7 -> V_92 ;
return 0 ;
}
static void F_34 ( struct V_101 * V_12 , struct V_3 * V_4 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
strcpy ( V_12 -> V_72 , L_4 ) ;
V_12 -> V_102 = V_4 -> V_85 ;
V_12 -> V_103 = sizeof( struct V_5 ) ;
V_12 -> type = V_104 ;
V_12 -> V_105 = V_4 -> V_65 + 0x1000 ;
V_12 -> V_106 = V_4 -> V_64 ;
V_12 -> V_107 = 0 ;
V_12 -> V_108 = 0 ;
V_12 -> V_109 = 0 ;
V_12 -> V_110 = 0 ;
}
static void F_4 ( struct V_6 * V_7 ,
struct V_101 * V_12 )
{
V_12 -> V_106 = F_13 ( V_7 -> V_20 , V_7 -> V_17 ) ;
V_12 -> V_111 = ( V_7 -> V_17 == V_63 ) ?
V_112 : V_113 ;
V_12 -> V_114 = V_7 -> V_99 << V_7 -> V_17 ;
}
static int T_3 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_115 = & V_116 ;
V_2 -> V_117 = V_4 -> V_84 + 0x1000 ;
V_2 -> V_67 = V_118 ;
V_2 -> V_37 = V_4 -> V_37 ;
V_2 -> V_7 = & V_4 -> V_7 ;
return F_41 ( & V_2 -> V_88 , 256 , 0 ) ;
}
int T_3 F_25 ( char * V_119 )
{
char * V_120 ;
if ( ! V_119 || ! * V_119 )
return 0 ;
while ( ( V_120 = F_42 ( & V_119 , L_15 ) ) != NULL ) {
if ( ! strncmp ( V_120 , L_16 , 6 ) ) {
int V_20 = F_43 ( V_120 + 6 , NULL , 0 ) ;
if ( V_20 > 0 && V_20 <= V_57 )
V_54 = V_20 ;
}
else if ( ! strncmp ( V_120 , L_17 , 6 ) ) {
int V_16 = F_43 ( V_120 + 6 , NULL , 0 ) ;
switch ( V_16 ) {
case 8 :
V_60 = V_63 ;
break;
case 15 :
case 16 :
V_60 = V_35 ;
break;
}
}
}
return 0 ;
}
