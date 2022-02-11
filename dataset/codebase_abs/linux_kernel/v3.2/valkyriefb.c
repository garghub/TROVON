static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
volatile struct V_5 T_1 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( ( V_10 = F_2 ( & V_2 -> V_11 , V_7 , V_2 ) ) )
return V_10 ;
F_3 ( V_7 , & V_2 -> V_12 ) ;
F_4 ( & V_5 -> V_13 . V_14 , 0 ) ;
F_5 ( 100 ) ;
V_9 = V_7 -> V_9 ;
F_4 ( & V_5 -> V_15 . V_14 , V_9 -> V_15 | 0x80 ) ;
F_4 ( & V_5 -> V_16 . V_14 , V_7 -> V_17 + 3 ) ;
F_6 ( V_9 -> V_18 ) ;
F_5 ( 100 ) ;
F_4 ( & V_5 -> V_15 . V_14 , V_9 -> V_15 ) ;
return 0 ;
}
static inline int F_7 ( struct V_6 * V_7 ,
struct V_19 * V_11 )
{
return F_8 ( V_7 -> V_20 , V_7 -> V_17 , V_11 ) ;
}
static int
F_9 ( struct V_19 * V_11 , struct V_1 * V_2 )
{
int V_10 ;
struct V_6 V_7 ;
if ( ( V_10 = F_2 ( V_11 , & V_7 , V_2 ) ) )
return V_10 ;
F_7 ( & V_7 , V_11 ) ;
return 0 ;
}
static int F_10 ( int V_21 , struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 == NULL )
return 1 ;
switch ( V_21 ) {
case V_22 :
F_4 ( & V_4 -> V_5 -> V_15 . V_14 , V_9 -> V_15 ) ;
break;
case V_23 :
return 1 ;
case V_24 :
case V_25 :
F_4 ( & V_4 -> V_5 -> V_15 . V_14 , V_9 -> V_15 | 0x40 ) ;
break;
case V_26 :
F_4 ( & V_4 -> V_5 -> V_15 . V_14 , 0x66 ) ;
break;
}
return 0 ;
}
static int F_11 ( T_2 V_27 , T_2 V_28 , T_2 V_29 , T_2 V_30 ,
T_2 V_31 , struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
volatile struct V_32 T_1 * V_32 = V_4 -> V_32 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_27 > 255 )
return 1 ;
V_28 >>= 8 ;
V_29 >>= 8 ;
V_30 >>= 8 ;
F_4 ( & V_4 -> V_32 -> V_33 , V_27 ) ;
F_5 ( 1 ) ;
F_4 ( & V_32 -> V_34 , V_28 ) ;
F_4 ( & V_32 -> V_34 , V_29 ) ;
F_4 ( & V_32 -> V_34 , V_30 ) ;
if ( V_27 < 16 && V_7 -> V_17 == V_35 )
( ( V_36 * ) V_2 -> V_37 ) [ V_27 ] =
( V_27 << 10 ) | ( V_27 << 5 ) | V_27 ;
return 0 ;
}
static inline int F_12 ( int V_38 , int V_39 )
{
int V_40 ;
struct V_8 * V_9 = V_41 [ V_38 - 1 ] ;
if ( ( V_40 = V_9 -> V_40 [ V_39 ] ) == 0 )
V_40 = 2 * V_9 -> V_40 [ 0 ] ;
return V_9 -> V_42 * V_40 ;
}
static void F_6 ( unsigned char * V_43 )
{
struct V_44 V_45 ;
int V_46 ;
#ifdef F_13
for ( V_46 = 0 ; V_46 < 3 ; ++ V_46 ) {
F_14 ( & V_45 , NULL , 5 , V_47 , V_48 ,
0x50 , V_46 + 1 , V_43 [ V_46 ] ) ;
while ( ! V_45 . V_49 )
F_15 () ;
}
#endif
}
static void T_3 F_16 ( struct V_3 * V_4 )
{
V_4 -> V_50 = F_17 ( V_4 ) ;
F_18 ( V_51 L_1 , V_4 -> V_50 ) ;
#if ! F_19 ( V_52 ) && F_19 ( V_53 )
if ( V_54 == V_55 ) {
V_54 = F_20 ( V_56 ) ;
if ( V_54 <= 0
|| V_54 > V_57
|| ! V_41 [ V_54 - 1 ] )
V_54 = V_58 ;
}
#endif
if ( V_54 == V_58 )
V_54 = F_21 ( V_4 -> V_50 ) ;
if ( ! V_41 [ V_54 - 1 ] )
V_54 = V_59 ;
#if ! F_19 ( V_52 ) && F_19 ( V_53 )
if ( V_60 == V_61 )
V_60 = F_20 ( V_62 ) ;
#endif
if ( V_60 < V_63 || V_60 > V_35
|| V_41 [ V_54 - 1 ] -> V_40 [ V_60 ] == 0
|| F_12 ( V_54 , V_60 ) > V_4 -> V_64 )
V_60 = V_63 ;
F_18 ( V_51 L_2 ,
V_54 , V_60 ) ;
}
int T_3 F_22 ( void )
{
struct V_3 * V_4 ;
unsigned long V_65 , V_66 , V_67 ;
int V_10 ;
char * V_68 = NULL ;
if ( F_23 ( L_3 , & V_68 ) )
return - V_69 ;
F_24 ( V_68 ) ;
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
V_77 = F_25 ( NULL , L_4 ) ;
if ( V_77 == 0 )
return 0 ;
if ( F_26 ( V_77 , 0 , & V_14 ) ) {
F_18 ( V_79 L_5 ) ;
return 0 ;
}
V_65 = V_14 . V_80 ;
V_66 = V_14 . V_80 + 0x304000 ;
V_67 = V_81 ;
}
#endif
V_4 = F_27 ( sizeof( * V_4 ) , V_82 ) ;
if ( V_4 == 0 )
return - V_83 ;
if ( ! F_28 ( V_65 , 0x100000 , L_3 ) ) {
F_29 ( V_4 ) ;
return 0 ;
}
V_4 -> V_64 = 0x100000 ;
V_4 -> V_65 = V_65 ;
V_4 -> V_84 = F_30 ( V_65 , V_4 -> V_64 , V_67 ) ;
V_4 -> V_66 = V_66 ;
V_4 -> V_32 = F_31 ( V_4 -> V_66 , 0x1000 ) ;
V_4 -> V_85 = V_66 + 0x6000 ;
V_4 -> V_5 = F_31 ( V_4 -> V_85 , 0x1000 ) ;
V_10 = - V_83 ;
if ( V_4 -> V_84 == NULL || V_4 -> V_32 == NULL
|| V_4 -> V_5 == NULL ) {
F_18 ( V_79 L_6 ) ;
goto V_86;
}
F_16 ( V_4 ) ;
F_8 ( V_54 , V_60 , & V_4 -> V_2 . V_11 ) ;
V_10 = F_32 ( & V_4 -> V_2 , V_4 ) ;
if ( V_10 < 0 )
goto V_86;
F_33 ( & V_4 -> V_2 . V_12 , V_4 ) ;
if ( F_1 ( & V_4 -> V_2 ) )
F_18 ( V_79 L_7 ) ;
if ( ( V_10 = F_34 ( & V_4 -> V_2 ) ) != 0 )
goto V_87;
F_18 ( V_51 L_8 , V_4 -> V_2 . V_88 ) ;
return 0 ;
V_87:
F_35 ( & V_4 -> V_2 . V_89 ) ;
V_86:
if ( V_4 -> V_84 )
F_36 ( V_4 -> V_84 ) ;
if ( V_4 -> V_32 )
F_36 ( V_4 -> V_32 ) ;
if ( V_4 -> V_5 )
F_36 ( V_4 -> V_5 ) ;
F_29 ( V_4 ) ;
return V_10 ;
}
static int F_17 ( struct V_3 * V_4 )
{
int V_50 , V_90 ;
F_4 ( & V_4 -> V_5 -> V_91 . V_14 , 0 ) ;
F_37 ( 20000 ) ;
V_50 = ( ( V_90 = F_38 ( & V_4 -> V_5 -> V_91 . V_14 ) ) & 0x70 ) << 4 ;
F_4 ( & V_4 -> V_5 -> V_91 . V_14 , 4 ) ;
F_37 ( 20000 ) ;
V_50 |= ( ( V_90 = F_38 ( & V_4 -> V_5 -> V_91 . V_14 ) ) & 0x30 ) ;
F_4 ( & V_4 -> V_5 -> V_91 . V_14 , 2 ) ;
F_37 ( 20000 ) ;
V_50 |= ( ( V_90 = F_38 ( & V_4 -> V_5 -> V_91 . V_14 ) ) & 0x40 ) >> 3 ;
V_50 |= ( V_90 & 0x10 ) >> 2 ;
F_4 ( & V_4 -> V_5 -> V_91 . V_14 , 1 ) ;
F_37 ( 20000 ) ;
V_50 |= ( ( V_90 = F_38 ( & V_4 -> V_5 -> V_91 . V_14 ) ) & 0x60 ) >> 5 ;
F_4 ( & V_4 -> V_5 -> V_91 . V_14 , 7 ) ;
return V_50 ;
}
static int F_2 ( struct V_19 * V_11 ,
struct V_6 * V_7 , const struct V_1 * V_1 )
{
int V_20 , V_17 ;
struct V_8 * V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
if ( F_39 ( V_11 , & V_20 , & V_17 ) != 0 ) {
F_18 ( V_79 L_9 ,
V_11 -> V_92 , V_11 -> V_93 , V_11 -> V_94 ) ;
return - V_95 ;
}
if ( V_20 < 1 || V_20 > V_57 || ! V_41 [ V_20 - 1 ] ) {
F_18 ( V_79 L_10 , V_20 ) ;
return - V_95 ;
}
if ( V_17 != V_63 && V_17 != V_35 ) {
F_18 ( V_79 L_11 , V_17 ) ;
return - V_95 ;
}
if ( V_11 -> V_96 > V_11 -> V_92 || V_11 -> V_97 > V_11 -> V_93
|| V_11 -> V_98 != 0 || V_11 -> V_99 != 0 ) {
return - V_95 ;
}
V_9 = V_41 [ V_20 - 1 ] ;
if ( V_9 -> V_40 [ V_17 ] == 0 ) {
F_18 ( V_79 L_12
L_13 , V_20 , V_17 ) ;
return - V_95 ;
}
if ( F_12 ( V_20 , V_17 ) > V_4 -> V_64 ) {
F_18 ( V_79 L_14
L_13 , V_20 , V_17 ) ;
return - V_95 ;
}
V_7 -> V_20 = V_20 ;
V_7 -> V_17 = V_17 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_92 = V_11 -> V_92 ;
V_7 -> V_93 = V_11 -> V_93 ;
V_7 -> V_100 = V_7 -> V_92 ;
V_7 -> V_101 = V_7 -> V_93 ;
return 0 ;
}
static void F_33 ( struct V_102 * V_12 , struct V_3 * V_4 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
strcpy ( V_12 -> V_72 , L_4 ) ;
V_12 -> V_103 = V_4 -> V_85 ;
V_12 -> V_104 = sizeof( struct V_5 ) ;
V_12 -> type = V_105 ;
V_12 -> V_106 = V_4 -> V_65 + 0x1000 ;
V_12 -> V_107 = V_4 -> V_64 ;
V_12 -> V_108 = 0 ;
V_12 -> V_109 = 0 ;
V_12 -> V_110 = 0 ;
V_12 -> V_111 = 0 ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_102 * V_12 )
{
V_12 -> V_107 = F_12 ( V_7 -> V_20 , V_7 -> V_17 ) ;
V_12 -> V_112 = ( V_7 -> V_17 == V_63 ) ?
V_113 : V_114 ;
V_12 -> V_115 = V_7 -> V_100 << V_7 -> V_17 ;
}
static int T_3 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_116 = & V_117 ;
V_2 -> V_118 = V_4 -> V_84 + 0x1000 ;
V_2 -> V_67 = V_119 ;
V_2 -> V_37 = V_4 -> V_37 ;
V_2 -> V_7 = & V_4 -> V_7 ;
return F_40 ( & V_2 -> V_89 , 256 , 0 ) ;
}
int T_3 F_24 ( char * V_120 )
{
char * V_121 ;
if ( ! V_120 || ! * V_120 )
return 0 ;
while ( ( V_121 = F_41 ( & V_120 , L_15 ) ) != NULL ) {
if ( ! strncmp ( V_121 , L_16 , 6 ) ) {
int V_20 = F_42 ( V_121 + 6 , NULL , 0 ) ;
if ( V_20 > 0 && V_20 <= V_57 )
V_54 = V_20 ;
}
else if ( ! strncmp ( V_121 , L_17 , 6 ) ) {
int V_16 = F_42 ( V_121 + 6 , NULL , 0 ) ;
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
