void F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 , unsigned int V_5 )
{
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_4 != V_2 -> V_8 ) {
F_3 ( ( unsigned short ) V_4 , F_4 ( V_2 ) ) ;
V_2 -> V_8 = V_4 ;
}
F_3 ( ( unsigned short ) V_5 , V_3 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
unsigned short F_6 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
unsigned short V_9 ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_4 != V_2 -> V_8 ) {
F_3 ( ( unsigned short ) V_4 , F_4 ( V_2 ) ) ;
V_2 -> V_8 = V_4 ;
}
V_9 = F_7 ( V_3 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
return V_9 ;
}
void F_8 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 , unsigned int V_5 )
{
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_4 != V_2 -> V_8 ) {
F_3 ( ( unsigned short ) V_4 , F_4 ( V_2 ) ) ;
V_2 -> V_8 = V_4 ;
}
F_3 ( ( unsigned short ) V_5 , V_3 ) ;
F_3 ( ( unsigned short ) ( V_5 >> 16 ) , V_3 + 2 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
unsigned int F_9 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
unsigned short V_10 ;
unsigned int V_9 ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_4 != V_2 -> V_8 ) {
F_3 ( ( unsigned short ) V_4 , F_4 ( V_2 ) ) ;
V_2 -> V_8 = V_4 ;
}
V_10 = F_7 ( V_3 ) ;
V_9 = V_10 + ( F_7 ( V_3 + 2 ) << 16 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
return V_9 ;
}
void
F_10 ( struct V_1 * V_2 , int V_11 , int V_12 )
{
unsigned V_13 = ( V_12 & V_14 ) ? 0x01000000 : 0 ;
V_12 &= V_15 ;
if ( V_12 == V_16 ) {
F_11 ( V_2 , V_11 , 0 ) ;
F_12 ( V_2 , V_11 , 0x807F ) ;
return;
}
F_12 ( V_2 , V_11 , 0x80 ) ;
F_13 ( V_2 , V_11 , 0 ) ;
F_14 ( V_2 , V_11 , 0 ) ;
F_15 ( V_2 , V_11 , 0x40000000 ) ;
F_16 ( V_2 , V_11 , 0x40000000 ) ;
F_17 ( V_2 , V_11 , 0 ) ;
F_18 ( V_2 , V_11 , 0 ) ;
if ( V_12 == V_17 )
F_11 ( V_2 , V_11 , 0x06000000 | V_13 ) ;
else
F_11 ( V_2 , V_11 , 0x04000000 | V_13 ) ;
}
static void
F_19 ( struct V_1 * V_2 )
{
while ( ( F_20 ( V_2 ) & 0x80000000 ) != 0 ) {
F_21 ( 1 ) ;
if ( F_22 ( V_18 ) )
break;
}
}
static void
F_23 ( struct V_1 * V_2 )
{
while ( ( F_24 ( V_2 ) & 0x80000000 ) != 0 ) {
F_21 ( 1 ) ;
if ( F_22 ( V_18 ) )
break;
}
}
static int
F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 , 0x0059 ) ;
F_27 ( V_2 , 0x0020 ) ;
F_28 ( V_2 , 0x0000 ) ;
if ( ( F_29 ( V_2 ) & 0x007e ) != 0x0058 )
return - V_19 ;
if ( ( F_30 ( V_2 ) & 0x0003 ) != 0x0003 )
return - V_19 ;
F_31 ( L_1 ,
V_2 -> V_20 ) ;
return 0 ;
}
static void
F_32 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_21 ; V_11 ++ )
F_12 ( V_2 , V_11 , 0x80 ) ;
for ( V_11 = 0 ; V_11 < V_21 ; V_11 ++ ) {
F_33 ( V_2 , V_11 , 0 ) ;
F_34 ( V_2 , V_11 , 0 ) ;
F_35 ( V_2 , V_11 , 0 ) ;
F_36 ( V_2 , V_11 , 0 ) ;
F_37 ( V_2 , V_11 , 0 ) ;
F_38 ( V_2 , V_11 , 0 ) ;
F_39 ( V_2 , V_11 , 0 ) ;
F_40 ( V_2 , V_11 , 0 ) ;
F_41 ( V_2 , V_11 , 0 ) ;
F_42 ( V_2 , V_11 , 0 ) ;
F_43 ( V_2 , V_11 , 0 ) ;
F_44 ( V_2 , V_11 , 0 ) ;
F_45 ( V_2 , V_11 , 0 ) ;
F_15 ( V_2 , V_11 , 0 ) ;
F_13 ( V_2 , V_11 , 0 ) ;
F_17 ( V_2 , V_11 , 0 ) ;
F_18 ( V_2 , V_11 , 0 ) ;
F_11 ( V_2 , V_11 , 0 ) ;
}
for ( V_11 = 0 ; V_11 < V_21 ; V_11 ++ ) {
F_16 ( V_2 , V_11 , 0 ) ;
F_14 ( V_2 , V_11 , 0 ) ;
}
}
static void
F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 , 0 ) ;
F_48 ( V_2 , 0 ) ;
F_49 ( V_2 , 0 ) ;
F_50 ( V_2 , 0 ) ;
}
static void
F_51 ( struct V_1 * V_2 , unsigned short * V_22 , int V_23 )
{
int V_24 ;
unsigned short * V_25 ;
V_25 = V_22 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ , V_25 ++ )
F_52 ( V_2 , V_24 , * V_25 ) ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ , V_25 ++ )
F_53 ( V_2 , V_24 , * V_25 ) ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ , V_25 ++ )
F_54 ( V_2 , V_24 , * V_25 ) ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ , V_25 ++ )
F_55 ( V_2 , V_24 , * V_25 ) ;
}
static void
F_56 ( struct V_1 * V_2 )
{
F_51 ( V_2 , V_26 , F_57 ( V_26 ) / 4 ) ;
F_58 ( ( 1024 * 1000 ) / 44100 ) ;
F_51 ( V_2 , V_27 , F_57 ( V_27 ) / 4 ) ;
F_51 ( V_2 , V_28 , F_57 ( V_28 ) / 4 ) ;
F_59 ( V_2 , 0 ) ;
F_60 ( V_2 , 0x83 ) ;
F_61 ( V_2 , 0x8000 ) ;
F_51 ( V_2 , V_29 , F_57 ( V_29 ) / 4 ) ;
}
static void
F_62 ( struct V_1 * V_2 )
{
int V_24 , V_23 , V_30 ;
if ( V_2 -> V_31 )
return;
V_23 = 0 ;
V_30 = 0 ;
F_10 ( V_2 , 0 , V_17 ) ;
F_10 ( V_2 , 1 , V_32 ) ;
F_49 ( V_2 , V_33 ) ;
F_63 ( V_2 , V_34 ) ;
F_64 ( V_2 ) ;
while ( V_23 < V_35 ) {
V_23 += 512 * 1024 ;
F_49 ( V_2 , V_33 + ( V_23 >> 1 ) ) ;
F_63 ( V_2 , V_36 ) ;
F_23 ( V_2 ) ;
F_47 ( V_2 , V_33 + ( V_23 >> 1 ) ) ;
F_65 ( V_2 ) ;
if ( F_65 ( V_2 ) != V_36 )
break;
F_19 ( V_2 ) ;
F_47 ( V_2 , V_33 ) ;
F_65 ( V_2 ) ;
if ( F_65 ( V_2 ) != V_34 )
break;
F_19 ( V_2 ) ;
V_30 = V_23 + 512 * 1024 ;
}
if ( V_30 == 0 ) {
F_19 ( V_2 ) ;
F_47 ( V_2 , V_33 ) ;
F_65 ( V_2 ) ;
if ( F_65 ( V_2 ) == V_34 )
V_30 = 512 * 1024 ;
}
for ( V_24 = 0 ; V_24 < 10000 ; V_24 ++ ) {
if ( ( F_24 ( V_2 ) & 0x80000000 ) == 0 )
break;
F_21 ( 1 ) ;
if ( F_22 ( V_18 ) )
break;
}
F_10 ( V_2 , 0 , V_16 ) ;
F_10 ( V_2 , 1 , V_16 ) ;
F_31 ( L_2 ,
V_2 -> V_20 , V_30 / 1024 ) ;
V_2 -> V_37 = V_30 ;
V_2 -> V_31 = 1 ;
}
void
F_64 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_12 ( V_2 , 30 , 0x80 ) ;
F_17 ( V_2 , 30 , 0xFFFFFFE0 ) ;
F_18 ( V_2 , 30 , 0x00FFFFE8 | ( V_2 -> V_38 << 24 ) ) ;
F_15 ( V_2 , 30 , ( V_2 -> V_39 << 8 ) ) ;
F_16 ( V_2 , 30 , 0 ) ;
F_11 ( V_2 , 30 , 0x00FFFFE3 ) ;
F_12 ( V_2 , 31 , 0x80 ) ;
F_17 ( V_2 , 31 , 0x00FFFFF0 ) ;
F_18 ( V_2 , 31 , 0x00FFFFF8 | ( V_2 -> V_38 << 24 ) ) ;
F_15 ( V_2 , 31 , ( V_2 -> V_39 << 8 ) ) ;
F_16 ( V_2 , 31 , 0x8000 ) ;
F_11 ( V_2 , 31 , 0x00FFFFF3 ) ;
F_1 ( ( V_2 ) , F_66 ( V_2 ) , F_67 ( 1 , ( 30 ) ) , 0 ) ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
while ( ! ( F_7 ( F_4 ( V_2 ) ) & 0x1000 ) )
;
while ( ( F_7 ( F_4 ( V_2 ) ) & 0x1000 ) )
;
F_5 ( & V_2 -> V_7 , V_6 ) ;
F_1 ( ( V_2 ) , F_66 ( V_2 ) , F_67 ( 1 , ( 30 ) ) , 0x4828 ) ;
F_68 ( 0x3C , F_4 ( V_2 ) ) ;
F_68 ( 0 , F_69 ( V_2 ) ) ;
F_13 ( V_2 , 30 , 0x8000FFFF ) ;
F_13 ( V_2 , 31 , 0x8000FFFF ) ;
}
static void
F_70 ( struct V_1 * V_2 )
{
int V_24 ;
V_2 -> V_8 = 0xffff ;
F_26 ( V_2 , 0x0059 ) ;
F_27 ( V_2 , 0x0020 ) ;
F_28 ( V_2 , 0 ) ;
F_32 ( V_2 ) ;
F_46 ( V_2 ) ;
F_56 ( V_2 ) ;
F_64 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_40 ; V_24 ++ )
F_12 ( V_2 , 0 , 0x807F ) ;
F_62 ( V_2 ) ;
F_28 ( V_2 , 0x4 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
}
void
F_71 ( struct V_1 * V_2 )
{
unsigned short V_41 ;
int V_42 = V_2 -> V_43 ;
int V_44 = V_2 -> V_45 ;
if ( V_42 < 0 || V_42 > 11 || V_44 < 0 || V_44 > 11 )
return;
F_55 ( V_2 , 0x01 , V_46 [ V_42 ] [ 0 ] ) ;
F_55 ( V_2 , 0x11 , V_46 [ V_42 ] [ 1 ] ) ;
F_54 ( V_2 , 0x11 , V_47 [ V_44 ] [ 0 ] ) ;
F_54 ( V_2 , 0x13 , V_47 [ V_44 ] [ 1 ] ) ;
F_54 ( V_2 , 0x1b , V_47 [ V_44 ] [ 2 ] ) ;
F_55 ( V_2 , 0x07 , V_47 [ V_44 ] [ 3 ] ) ;
F_55 ( V_2 , 0x0b , V_47 [ V_44 ] [ 4 ] ) ;
F_55 ( V_2 , 0x0d , V_47 [ V_44 ] [ 5 ] ) ;
F_55 ( V_2 , 0x17 , V_47 [ V_44 ] [ 6 ] ) ;
F_55 ( V_2 , 0x19 , V_47 [ V_44 ] [ 7 ] ) ;
V_41 = V_46 [ V_42 ] [ 2 ] + V_47 [ V_44 ] [ 8 ] ;
F_55 ( V_2 , 0x15 , ( unsigned short ) ( V_41 + 0x0262 ) ) ;
F_55 ( V_2 , 0x1d , ( unsigned short ) ( V_41 + 0x8362 ) ) ;
}
int
F_74 ( struct V_1 * V_2 , int V_12 , const void T_1 * V_48 , long V_49 )
{
struct V_50 V_51 ;
if ( V_12 < V_52 || V_12 >= V_53 ) {
F_75 ( V_54 L_3 , V_12 ) ;
return - V_55 ;
}
if ( V_49 < ( long ) sizeof( V_51 ) || F_76 ( & V_51 , V_48 , sizeof( V_51 ) ) )
return - V_56 ;
V_57 [ V_12 ] = V_51 ;
V_58 [ V_12 ] = 1 ;
return 0 ;
}
void
F_72 ( struct V_1 * V_2 )
{
int V_59 = V_2 -> V_60 ;
if ( V_59 < 0 || V_59 >= V_53 ||
( V_59 >= V_52 && ! V_58 [ V_59 ] ) )
return;
F_54 ( V_2 , 0x09 , V_57 [ V_59 ] . V_61 ) ;
F_54 ( V_2 , 0x0c , V_57 [ V_59 ] . V_62 ) ;
F_55 ( V_2 , 0x03 , V_57 [ V_59 ] . V_63 ) ;
F_59 ( V_2 , V_57 [ V_59 ] . V_64 ) ;
F_60 ( V_2 , V_57 [ V_59 ] . V_65 ) ;
F_61 ( V_2 , 0x8000 ) ;
F_77 ( V_2 , 0x0000 ) ;
}
int
F_78 ( struct V_1 * V_2 , int V_12 , const void T_1 * V_48 , long V_49 )
{
struct V_66 V_51 ;
if ( V_12 < V_67 || V_12 >= V_68 ) {
F_75 ( V_54 L_4 , V_12 ) ;
return - V_55 ;
}
if ( V_49 < ( long ) sizeof( V_51 ) || F_76 ( & V_51 , V_48 , sizeof( V_51 ) ) )
return - V_56 ;
V_69 [ V_12 ] = V_51 ;
V_70 [ V_12 ] = 1 ;
return 0 ;
}
void
F_73 ( struct V_1 * V_2 )
{
int V_59 = V_2 -> V_71 ;
int V_24 ;
if ( V_59 < 0 || V_59 >= V_68 ||
( V_59 >= V_67 && ! V_70 [ V_59 ] ) )
return;
for ( V_24 = 0 ; V_24 < 28 ; V_24 ++ ) {
int V_3 ;
if ( V_72 [ V_24 ] . V_3 == V_73 )
V_3 = F_69 ( V_2 ) ;
else
V_3 = F_79 ( V_2 ) ;
F_1 ( V_2 , V_3 , V_72 [ V_24 ] . V_74 , V_69 [ V_59 ] . V_75 [ V_24 ] ) ;
}
}
static int F_80 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
V_79 -> type = V_80 ;
V_79 -> V_81 = 1 ;
V_79 -> V_82 . integer . V_83 = 0 ;
V_79 -> V_82 . integer . V_84 = 11 ;
return 0 ;
}
static int F_81 ( struct V_76 * V_77 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_82 ( V_77 ) ;
V_86 -> V_82 . integer . V_82 [ 0 ] = V_77 -> V_87 ? V_2 -> V_45 : V_2 -> V_43 ;
return 0 ;
}
static int F_83 ( struct V_76 * V_77 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_82 ( V_77 ) ;
unsigned long V_6 ;
int V_88 ;
unsigned short V_89 ;
V_89 = V_86 -> V_82 . integer . V_82 [ 0 ] % 12 ;
F_2 ( & V_2 -> V_90 , V_6 ) ;
if ( V_77 -> V_87 ) {
V_88 = V_89 != V_2 -> V_45 ;
V_2 -> V_45 = V_89 ;
} else {
V_88 = V_89 != V_2 -> V_43 ;
V_2 -> V_43 = V_89 ;
}
F_5 ( & V_2 -> V_90 , V_6 ) ;
F_71 ( V_2 ) ;
return V_88 ;
}
static int F_84 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
V_79 -> type = V_80 ;
V_79 -> V_81 = 1 ;
V_79 -> V_82 . integer . V_83 = 0 ;
V_79 -> V_82 . integer . V_84 = V_77 -> V_87 ? ( V_53 - 1 ) : ( V_68 - 1 ) ;
return 0 ;
}
static int F_85 ( struct V_76 * V_77 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_82 ( V_77 ) ;
V_86 -> V_82 . integer . V_82 [ 0 ] = V_77 -> V_87 ? V_2 -> V_60 : V_2 -> V_71 ;
return 0 ;
}
static int F_86 ( struct V_76 * V_77 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_82 ( V_77 ) ;
unsigned long V_6 ;
int V_88 ;
unsigned short V_89 ;
F_2 ( & V_2 -> V_90 , V_6 ) ;
if ( V_77 -> V_87 ) {
V_89 = V_86 -> V_82 . integer . V_82 [ 0 ] % V_53 ;
V_88 = V_89 != V_2 -> V_60 ;
V_2 -> V_60 = V_89 ;
} else {
V_89 = V_86 -> V_82 . integer . V_82 [ 0 ] % V_68 ;
V_88 = V_89 != V_2 -> V_71 ;
V_2 -> V_71 = V_89 ;
}
F_5 ( & V_2 -> V_90 , V_6 ) ;
if ( V_88 ) {
if ( V_77 -> V_87 )
F_72 ( V_2 ) ;
else
F_73 ( V_2 ) ;
}
return V_88 ;
}
static int F_87 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
V_79 -> type = V_80 ;
V_79 -> V_81 = 1 ;
V_79 -> V_82 . integer . V_83 = 0 ;
V_79 -> V_82 . integer . V_84 = 255 ;
return 0 ;
}
static int F_88 ( struct V_76 * V_77 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_82 ( V_77 ) ;
V_86 -> V_82 . integer . V_82 [ 0 ] = V_77 -> V_87 ? V_2 -> V_38 : V_2 -> V_39 ;
return 0 ;
}
static int F_89 ( struct V_76 * V_77 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_82 ( V_77 ) ;
unsigned long V_6 ;
int V_88 ;
unsigned short V_89 ;
V_89 = V_86 -> V_82 . integer . V_82 [ 0 ] % 256 ;
F_2 ( & V_2 -> V_90 , V_6 ) ;
if ( V_77 -> V_87 ) {
V_88 = V_89 != V_2 -> V_38 ;
V_2 -> V_38 = V_89 ;
} else {
V_88 = V_89 != V_2 -> V_39 ;
V_2 -> V_39 = V_89 ;
}
F_5 ( & V_2 -> V_90 , V_6 ) ;
if ( V_88 )
F_64 ( V_2 ) ;
return V_88 ;
}
static int
F_90 ( struct V_91 * V_92 , struct V_1 * V_2 )
{
int V_24 , V_93 = 0 ;
if ( F_91 ( ! V_2 || ! V_92 ) )
return - V_55 ;
F_92 ( & V_2 -> V_90 ) ;
memset ( V_2 -> V_94 , 0 , sizeof( V_2 -> V_94 ) ) ;
for ( V_24 = 0 ; V_24 < V_95 ; V_24 ++ ) {
if ( ( V_93 = F_93 ( V_92 , V_2 -> V_94 [ V_24 ] = F_94 ( V_96 [ V_24 ] , V_2 ) ) ) < 0 )
goto V_97;
}
return 0 ;
V_97:
for ( V_24 = 0 ; V_24 < V_95 ; V_24 ++ ) {
F_95 ( & V_92 -> V_98 ) ;
if ( V_2 -> V_94 [ V_24 ] )
F_96 ( V_92 , V_2 -> V_94 [ V_24 ] ) ;
F_97 ( & V_92 -> V_98 ) ;
}
return V_93 ;
}
static int F_98 ( struct V_1 * V_99 )
{
F_99 ( V_99 -> V_100 ) ;
F_99 ( V_99 -> V_101 ) ;
F_99 ( V_99 -> V_102 ) ;
F_100 ( V_99 ) ;
return 0 ;
}
static int F_101 ( struct V_103 * V_104 )
{
struct V_1 * V_99 = V_104 -> V_105 ;
return F_98 ( V_99 ) ;
}
int
F_102 ( struct V_91 * V_92 , int V_106 , long V_3 , int V_107 ,
struct V_108 * * V_109 )
{
struct V_108 * V_110 ;
struct V_1 * V_99 ;
int V_93 ;
static struct V_111 V_112 = {
. V_113 = F_101 ,
} ;
if ( V_109 )
* V_109 = NULL ;
if ( V_107 <= 0 )
return 0 ;
V_99 = F_103 ( sizeof( * V_99 ) , V_114 ) ;
if ( V_99 == NULL )
return - V_115 ;
F_92 ( & V_99 -> V_7 ) ;
V_99 -> V_106 = V_106 ;
V_99 -> V_20 = V_3 ;
V_99 -> V_116 = V_3 + 0x400 ;
V_99 -> V_117 = V_3 + 0x800 ;
if ( ! ( V_99 -> V_100 = F_104 ( V_99 -> V_20 , 4 , L_5 ) ) ||
! ( V_99 -> V_101 = F_104 ( V_99 -> V_116 , 4 , L_6 ) ) ||
! ( V_99 -> V_102 = F_104 ( V_99 -> V_117 , 4 , L_7 ) ) ) {
F_75 ( V_118 L_8 , V_99 -> V_20 , V_99 -> V_116 , V_99 -> V_117 ) ;
F_98 ( V_99 ) ;
return - V_119 ;
}
V_99 -> V_37 = 0 ;
V_99 -> V_92 = V_92 ;
V_99 -> V_107 = V_107 ;
V_99 -> V_43 = 5 ;
V_99 -> V_45 = 9 ;
V_99 -> V_60 = 2 ;
V_99 -> V_71 = 4 ;
V_99 -> V_38 = 0 ;
V_99 -> V_39 = 0 ;
if ( F_25 ( V_99 ) < 0 ) {
F_98 ( V_99 ) ;
return - V_19 ;
}
F_70 ( V_99 ) ;
if ( ( V_93 = F_90 ( V_92 , V_99 ) ) < 0 ) {
F_98 ( V_99 ) ;
return V_93 ;
}
if ( ( V_93 = F_105 ( V_92 , V_120 , V_99 , & V_112 ) ) < 0 ) {
F_98 ( V_99 ) ;
return V_93 ;
}
#if F_106 ( V_121 ) || ( F_106 ( V_122 ) && F_106 ( V_123 ) )
if ( F_107 ( V_92 , V_106 , V_124 ,
sizeof( struct V_1 * ) , & V_110 ) >= 0 ) {
strcpy ( V_110 -> V_125 , L_9 ) ;
* (struct V_1 * * ) F_108 ( V_110 ) = V_99 ;
}
#else
V_110 = NULL ;
#endif
if ( V_109 )
* V_109 = V_110 ;
return 0 ;
}
