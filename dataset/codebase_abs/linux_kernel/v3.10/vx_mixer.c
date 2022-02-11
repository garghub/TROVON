static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
unsigned long V_5 ;
if ( F_2 ( ! V_2 -> V_6 -> V_7 ) )
return;
if ( V_2 -> V_8 & V_9 )
return;
F_3 ( & V_2 -> V_10 , V_5 ) ;
V_2 -> V_6 -> V_7 ( V_2 , V_3 , V_4 ) ;
F_4 ( & V_2 -> V_10 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_11 , int V_12 )
{
union V_13 V_4 ;
F_6 ( V_4 ) ;
F_7 ( V_4 , V_11 ) ;
F_8 ( V_4 , V_12 ) ;
F_1 ( V_2 , V_3 , V_4 . V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 , int V_15 , int V_16 )
{
V_15 = V_2 -> V_17 -> V_18 - V_15 ;
V_16 = V_2 -> V_17 -> V_18 - V_16 ;
if ( V_2 -> V_6 -> V_19 ) {
V_2 -> V_6 -> V_19 ( V_2 , V_20 , V_15 ) ;
V_2 -> V_6 -> V_19 ( V_2 , V_21 , V_16 ) ;
} else {
F_5 ( V_2 , V_3 , V_20 , V_15 ) ;
F_5 ( V_2 , V_3 , V_21 , V_16 ) ;
}
}
void F_10 ( struct V_1 * V_2 , int V_22 )
{
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_17 -> V_24 ; V_23 ++ ) {
if ( V_2 -> V_6 -> V_19 )
V_2 -> V_6 -> V_19 ( V_2 , V_25 , V_22 ) ;
else
F_5 ( V_2 , V_23 , V_25 ,
V_22 ? V_26 : V_27 ) ;
}
}
void F_11 ( struct V_1 * V_2 , int V_28 )
{
unsigned int V_23 ;
int V_29 = V_2 -> type >= V_30 ? 0x75 : 0x65 ;
V_2 -> V_6 -> V_31 ( V_2 ) ;
if ( ! V_2 -> V_6 -> V_19 ) {
for ( V_23 = 0 ; V_23 < V_2 -> V_17 -> V_24 ; V_23 ++ ) {
F_5 ( V_2 , V_23 , V_25 , V_26 ) ;
F_5 ( V_2 , V_23 , V_32 , 0x00 ) ;
F_5 ( V_2 , V_23 , V_33 , V_29 ) ;
F_5 ( V_2 , V_23 , V_34 , 0x00 ) ;
}
}
for ( V_23 = 0 ; V_23 < V_2 -> V_17 -> V_24 ; V_23 ++ ) {
V_2 -> V_35 [ V_23 ] [ 0 ] = 0 ;
V_2 -> V_35 [ V_23 ] [ 1 ] = 0 ;
F_9 ( V_2 , V_23 , 0 , 0 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_5 ;
if ( V_2 -> V_8 & V_9 )
return;
F_3 ( & V_2 -> V_10 , V_5 ) ;
V_2 -> V_6 -> V_37 ( V_2 , V_36 ) ;
F_4 ( & V_2 -> V_10 , V_5 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 == V_2 -> V_39 ||
V_2 -> V_40 )
return 0 ;
F_12 ( V_2 , V_2 -> V_38 ) ;
V_2 -> V_39 = V_2 -> V_38 ;
return 1 ;
}
static int F_14 ( struct V_1 * V_2 , int V_41 , int V_42 ,
struct V_43 * V_44 )
{
struct V_45 V_46 ;
if ( V_2 -> V_8 & V_9 )
return - V_47 ;
F_15 ( & V_46 , V_48 ) ;
if ( V_42 )
V_46 . V_49 [ 0 ] |= V_50 ;
V_46 . V_49 [ 1 ] = 1 << V_41 ;
V_46 . V_49 [ 2 ] = 0 ;
if ( V_44 -> V_51 ) {
V_46 . V_49 [ 0 ] |= V_52 ;
V_46 . V_49 [ 2 ] |= V_44 -> V_53 ;
}
if ( V_44 -> V_54 ) {
V_46 . V_49 [ 0 ] |= V_55 ;
V_46 . V_49 [ 2 ] |= ( ( unsigned int ) V_44 -> V_56 << 10 ) ;
}
if ( V_44 -> V_57 ) {
V_46 . V_49 [ 0 ] |= V_58 ;
if ( V_44 -> V_22 )
V_46 . V_49 [ 2 ] |= V_59 ;
}
if ( V_44 -> V_60 ) {
V_46 . V_49 [ 0 ] |= V_61 | V_62 ;
if ( V_44 -> V_63 )
V_46 . V_49 [ 2 ] |= V_64 ;
}
return F_16 ( V_2 , & V_46 ) ;
}
int F_17 ( struct V_1 * V_2 , int V_41 , int V_53 , int V_65 )
{
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_54 = 1 ;
V_44 . V_56 = V_53 ;
V_44 . V_60 = 1 ;
V_44 . V_63 = ! V_65 ;
V_2 -> V_66 [ V_41 ] = V_53 ;
V_2 -> V_67 [ V_41 ] = V_65 ;
return F_14 ( V_2 , V_41 , 0 , & V_44 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_41 , int V_65 )
{
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_57 = 1 ;
V_44 . V_22 = ! V_65 ;
V_2 -> V_68 [ V_41 ] = V_65 ;
return F_14 ( V_2 , V_41 , 0 , & V_44 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_41 , int V_42 , int V_53 )
{
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_51 = 1 ;
V_44 . V_53 = V_53 ;
V_2 -> V_69 [ V_42 ] [ V_41 ] = V_53 ;
return F_14 ( V_2 , V_41 , V_42 , & V_44 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned int V_23 , V_70 ;
struct V_43 V_44 ;
memset ( V_2 -> V_69 , 0 , sizeof( V_2 -> V_69 ) ) ;
memset ( V_2 -> V_68 , 0 , sizeof( V_2 -> V_68 ) ) ;
memset ( V_2 -> V_66 , 0 , sizeof( V_2 -> V_66 ) ) ;
memset ( V_2 -> V_67 , 0 , sizeof( V_2 -> V_67 ) ) ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
for ( V_23 = 0 ; V_23 < V_2 -> V_17 -> V_71 * 2 ; V_23 ++ ) {
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
if ( V_70 == 0 ) {
V_44 . V_54 = 1 ;
V_44 . V_57 = 1 ;
V_44 . V_60 = 1 ;
}
V_44 . V_51 = 1 ;
V_44 . V_53 = V_72 ;
F_14 ( V_2 , V_23 , V_70 , & V_44 ) ;
V_2 -> V_69 [ V_70 ] [ V_23 ] = V_72 ;
V_2 -> V_66 [ V_23 ] = V_72 ;
}
}
}
static int F_21 ( struct V_1 * V_2 , int V_41 , int V_42 , struct V_73 * V_44 )
{
struct V_45 V_46 ;
int V_23 , V_74 ;
if ( V_2 -> V_8 & V_9 )
return - V_47 ;
F_15 ( & V_46 , V_75 ) ;
V_46 . V_76 += 2 * V_77 ;
if ( V_42 )
V_46 . V_49 [ 0 ] |= V_50 ;
V_46 . V_49 [ 1 ] = 0 ;
for ( V_23 = 0 ; V_23 < V_77 ; V_23 ++ )
V_46 . V_49 [ 1 ] |= 1 << ( V_41 + V_23 ) ;
V_74 = F_16 ( V_2 , & V_46 ) ;
if ( V_74 < 0 )
return V_74 ;
for ( V_23 = 0 ; V_23 < 2 * V_77 ; V_23 += 2 ) {
V_44 -> V_78 = ( V_46 . V_79 [ 0 ] & ( 1 << ( V_41 + V_23 ) ) ) ? 1 : 0 ;
V_44 -> V_80 = V_46 . V_79 [ V_23 + 1 ] ;
V_44 -> V_81 = V_46 . V_79 [ V_23 + 2 ] ;
V_44 ++ ;
}
return 0 ;
}
static int F_22 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
V_85 -> type = V_86 ;
V_85 -> V_87 = 2 ;
V_85 -> V_88 . integer . V_89 = 0 ;
V_85 -> V_88 . integer . V_90 = V_2 -> V_17 -> V_18 ;
return 0 ;
}
static int F_24 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_3 = V_83 -> V_93 . V_94 ;
F_25 ( & V_2 -> V_95 ) ;
V_92 -> V_88 . integer . V_88 [ 0 ] = V_2 -> V_35 [ V_3 ] [ 0 ] ;
V_92 -> V_88 . integer . V_88 [ 1 ] = V_2 -> V_35 [ V_3 ] [ 1 ] ;
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_27 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_3 = V_83 -> V_93 . V_94 ;
unsigned int V_12 [ 2 ] , V_96 ;
V_96 = V_2 -> V_17 -> V_18 ;
V_12 [ 0 ] = V_92 -> V_88 . integer . V_88 [ 0 ] ;
V_12 [ 1 ] = V_92 -> V_88 . integer . V_88 [ 1 ] ;
if ( V_12 [ 0 ] > V_96 || V_12 [ 1 ] > V_96 )
return - V_97 ;
F_25 ( & V_2 -> V_95 ) ;
if ( V_12 [ 0 ] != V_2 -> V_35 [ V_3 ] [ 0 ] ||
V_12 [ 1 ] != V_2 -> V_35 [ V_3 ] [ 1 ] ) {
F_9 ( V_2 , V_3 , V_12 [ 0 ] , V_12 [ 1 ] ) ;
V_2 -> V_35 [ V_3 ] [ 0 ] = V_12 [ 0 ] ;
V_2 -> V_35 [ V_3 ] [ 1 ] = V_12 [ 1 ] ;
F_26 ( & V_2 -> V_95 ) ;
return 1 ;
}
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_28 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
static char * V_98 [ 3 ] = {
L_1 , L_2 , L_3
} ;
static char * V_99 [ 2 ] = {
L_1 , L_4
} ;
struct V_1 * V_2 = F_23 ( V_83 ) ;
V_85 -> type = V_100 ;
V_85 -> V_87 = 1 ;
if ( V_2 -> type >= V_30 ) {
V_85 -> V_88 . V_101 . V_102 = 3 ;
if ( V_85 -> V_88 . V_101 . V_103 > 2 )
V_85 -> V_88 . V_101 . V_103 = 2 ;
strcpy ( V_85 -> V_88 . V_101 . V_104 ,
V_98 [ V_85 -> V_88 . V_101 . V_103 ] ) ;
} else {
V_85 -> V_88 . V_101 . V_102 = 2 ;
if ( V_85 -> V_88 . V_101 . V_103 > 1 )
V_85 -> V_88 . V_101 . V_103 = 1 ;
strcpy ( V_85 -> V_88 . V_101 . V_104 ,
V_99 [ V_85 -> V_88 . V_101 . V_103 ] ) ;
}
return 0 ;
}
static int F_29 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
V_92 -> V_88 . V_101 . V_103 [ 0 ] = V_2 -> V_38 ;
return 0 ;
}
static int F_30 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
if ( V_2 -> type >= V_30 ) {
if ( V_92 -> V_88 . V_101 . V_103 [ 0 ] > 2 )
return - V_97 ;
} else {
if ( V_92 -> V_88 . V_101 . V_103 [ 0 ] > 1 )
return - V_97 ;
}
F_25 ( & V_2 -> V_95 ) ;
if ( V_2 -> V_38 != V_92 -> V_88 . V_101 . V_103 [ 0 ] ) {
V_2 -> V_38 = V_92 -> V_88 . V_101 . V_103 [ 0 ] ;
F_13 ( V_2 ) ;
F_26 ( & V_2 -> V_95 ) ;
return 1 ;
}
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_31 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
static char * V_105 [ 3 ] = {
L_5 , L_6 , L_7
} ;
V_85 -> type = V_100 ;
V_85 -> V_87 = 1 ;
V_85 -> V_88 . V_101 . V_102 = 3 ;
if ( V_85 -> V_88 . V_101 . V_103 > 2 )
V_85 -> V_88 . V_101 . V_103 = 2 ;
strcpy ( V_85 -> V_88 . V_101 . V_104 ,
V_105 [ V_85 -> V_88 . V_101 . V_103 ] ) ;
return 0 ;
}
static int F_32 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
V_92 -> V_88 . V_101 . V_103 [ 0 ] = V_2 -> V_106 ;
return 0 ;
}
static int F_33 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
if ( V_92 -> V_88 . V_101 . V_103 [ 0 ] > 2 )
return - V_97 ;
F_25 ( & V_2 -> V_95 ) ;
if ( V_2 -> V_106 != V_92 -> V_88 . V_101 . V_103 [ 0 ] ) {
V_2 -> V_106 = V_92 -> V_88 . V_101 . V_103 [ 0 ] ;
F_34 ( V_2 , V_2 -> V_107 ) ;
F_26 ( & V_2 -> V_95 ) ;
return 1 ;
}
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_35 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
V_85 -> type = V_86 ;
V_85 -> V_87 = 2 ;
V_85 -> V_88 . integer . V_89 = 0 ;
V_85 -> V_88 . integer . V_90 = V_108 ;
return 0 ;
}
static int F_36 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_41 = V_83 -> V_109 & 0xff ;
int V_42 = ( V_83 -> V_109 >> 8 ) & 1 ;
F_25 ( & V_2 -> V_95 ) ;
V_92 -> V_88 . integer . V_88 [ 0 ] = V_2 -> V_69 [ V_42 ] [ V_41 ] ;
V_92 -> V_88 . integer . V_88 [ 1 ] = V_2 -> V_69 [ V_42 ] [ V_41 + 1 ] ;
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_37 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_41 = V_83 -> V_109 & 0xff ;
int V_42 = ( V_83 -> V_109 >> 8 ) & 1 ;
unsigned int V_12 [ 2 ] ;
V_12 [ 0 ] = V_92 -> V_88 . integer . V_88 [ 0 ] ;
V_12 [ 1 ] = V_92 -> V_88 . integer . V_88 [ 1 ] ;
if ( V_12 [ 0 ] > V_108 || V_12 [ 1 ] > V_108 )
return - V_97 ;
F_25 ( & V_2 -> V_95 ) ;
if ( V_12 [ 0 ] != V_2 -> V_69 [ V_42 ] [ V_41 ] ||
V_12 [ 1 ] != V_2 -> V_69 [ V_42 ] [ V_41 + 1 ] ) {
F_19 ( V_2 , V_41 , V_42 , V_12 [ 0 ] ) ;
F_19 ( V_2 , V_41 + 1 , V_42 , V_12 [ 1 ] ) ;
F_26 ( & V_2 -> V_95 ) ;
return 1 ;
}
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_38 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_41 = V_83 -> V_109 & 0xff ;
F_25 ( & V_2 -> V_95 ) ;
V_92 -> V_88 . integer . V_88 [ 0 ] = V_2 -> V_66 [ V_41 ] ;
V_92 -> V_88 . integer . V_88 [ 1 ] = V_2 -> V_66 [ V_41 + 1 ] ;
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_39 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_41 = V_83 -> V_109 & 0xff ;
unsigned int V_12 [ 2 ] ;
V_12 [ 0 ] = V_92 -> V_88 . integer . V_88 [ 0 ] ;
V_12 [ 1 ] = V_92 -> V_88 . integer . V_88 [ 1 ] ;
if ( V_12 [ 0 ] > V_108 || V_12 [ 1 ] > V_108 )
return - V_97 ;
F_25 ( & V_2 -> V_95 ) ;
if ( V_12 [ 0 ] != V_2 -> V_66 [ V_41 ] ||
V_12 [ 1 ] != V_2 -> V_66 [ V_41 + 1 ] ) {
F_17 ( V_2 , V_41 , V_12 [ 0 ] ,
V_2 -> V_67 [ V_41 ] ) ;
F_17 ( V_2 , V_41 + 1 , V_12 [ 1 ] ,
V_2 -> V_67 [ V_41 + 1 ] ) ;
F_26 ( & V_2 -> V_95 ) ;
return 1 ;
}
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_40 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_41 = V_83 -> V_109 & 0xff ;
F_25 ( & V_2 -> V_95 ) ;
V_92 -> V_88 . integer . V_88 [ 0 ] = V_2 -> V_68 [ V_41 ] ;
V_92 -> V_88 . integer . V_88 [ 1 ] = V_2 -> V_68 [ V_41 + 1 ] ;
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_41 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_41 = V_83 -> V_109 & 0xff ;
F_25 ( & V_2 -> V_95 ) ;
if ( V_92 -> V_88 . integer . V_88 [ 0 ] != V_2 -> V_68 [ V_41 ] ||
V_92 -> V_88 . integer . V_88 [ 1 ] != V_2 -> V_68 [ V_41 + 1 ] ) {
F_18 ( V_2 , V_41 ,
! ! V_92 -> V_88 . integer . V_88 [ 0 ] ) ;
F_18 ( V_2 , V_41 + 1 ,
! ! V_92 -> V_88 . integer . V_88 [ 1 ] ) ;
F_26 ( & V_2 -> V_95 ) ;
return 1 ;
}
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_42 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_41 = V_83 -> V_109 & 0xff ;
F_25 ( & V_2 -> V_95 ) ;
V_92 -> V_88 . integer . V_88 [ 0 ] = V_2 -> V_67 [ V_41 ] ;
V_92 -> V_88 . integer . V_88 [ 1 ] = V_2 -> V_67 [ V_41 + 1 ] ;
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_43 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_41 = V_83 -> V_109 & 0xff ;
F_25 ( & V_2 -> V_95 ) ;
if ( V_92 -> V_88 . integer . V_88 [ 0 ] != V_2 -> V_67 [ V_41 ] ||
V_92 -> V_88 . integer . V_88 [ 1 ] != V_2 -> V_67 [ V_41 + 1 ] ) {
F_17 ( V_2 , V_41 , V_2 -> V_66 [ V_41 ] ,
! ! V_92 -> V_88 . integer . V_88 [ 0 ] ) ;
F_17 ( V_2 , V_41 + 1 , V_2 -> V_66 [ V_41 + 1 ] ,
! ! V_92 -> V_88 . integer . V_88 [ 1 ] ) ;
F_26 ( & V_2 -> V_95 ) ;
return 1 ;
}
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_44 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
V_85 -> type = V_110 ;
V_85 -> V_87 = 1 ;
return 0 ;
}
static int F_45 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
F_25 ( & V_2 -> V_95 ) ;
V_92 -> V_88 . V_111 . V_112 [ 0 ] = ( V_2 -> V_113 >> 0 ) & 0xff ;
V_92 -> V_88 . V_111 . V_112 [ 1 ] = ( V_2 -> V_113 >> 8 ) & 0xff ;
V_92 -> V_88 . V_111 . V_112 [ 2 ] = ( V_2 -> V_113 >> 16 ) & 0xff ;
V_92 -> V_88 . V_111 . V_112 [ 3 ] = ( V_2 -> V_113 >> 24 ) & 0xff ;
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_46 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
V_92 -> V_88 . V_111 . V_112 [ 0 ] = 0xff ;
V_92 -> V_88 . V_111 . V_112 [ 1 ] = 0xff ;
V_92 -> V_88 . V_111 . V_112 [ 2 ] = 0xff ;
V_92 -> V_88 . V_111 . V_112 [ 3 ] = 0xff ;
return 0 ;
}
static int F_47 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
unsigned int V_12 ;
V_12 = ( V_92 -> V_88 . V_111 . V_112 [ 0 ] << 0 ) |
( V_92 -> V_88 . V_111 . V_112 [ 1 ] << 8 ) |
( V_92 -> V_88 . V_111 . V_112 [ 2 ] << 16 ) |
( V_92 -> V_88 . V_111 . V_112 [ 3 ] << 24 ) ;
F_25 ( & V_2 -> V_95 ) ;
if ( V_2 -> V_113 != V_12 ) {
V_2 -> V_113 = V_12 ;
F_48 ( V_2 , V_12 ) ;
F_26 ( & V_2 -> V_95 ) ;
return 1 ;
}
F_26 ( & V_2 -> V_95 ) ;
return 0 ;
}
static int F_49 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
V_85 -> type = V_86 ;
V_85 -> V_87 = 2 ;
V_85 -> V_88 . integer . V_89 = 0 ;
V_85 -> V_88 . integer . V_90 = V_114 ;
return 0 ;
}
static int F_50 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
struct V_73 V_115 [ 2 ] ;
int V_41 = V_83 -> V_109 & 0xff ;
int V_42 = ( V_83 -> V_109 >> 8 ) & 1 ;
F_21 ( V_2 , V_41 , V_42 , V_115 ) ;
V_92 -> V_88 . integer . V_88 [ 0 ] = V_115 [ 0 ] . V_80 >> V_116 ;
V_92 -> V_88 . integer . V_88 [ 1 ] = V_115 [ 1 ] . V_80 >> V_116 ;
return 0 ;
}
static int F_51 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
struct V_73 V_115 [ 2 ] ;
int V_41 = V_83 -> V_109 & 0xff ;
int V_42 = ( V_83 -> V_109 >> 8 ) & 1 ;
F_21 ( V_2 , V_41 , V_42 , V_115 ) ;
V_92 -> V_88 . integer . V_88 [ 0 ] = V_115 [ 0 ] . V_81 >> V_116 ;
V_92 -> V_88 . integer . V_88 [ 1 ] = V_115 [ 1 ] . V_81 >> V_116 ;
return 0 ;
}
static int F_52 ( struct V_82 * V_83 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
struct V_73 V_115 [ 2 ] ;
int V_41 = V_83 -> V_109 & 0xff ;
F_21 ( V_2 , V_41 , 1 , V_115 ) ;
V_92 -> V_88 . integer . V_88 [ 0 ] = V_115 [ 0 ] . V_78 ;
V_92 -> V_88 . integer . V_88 [ 1 ] = V_115 [ 1 ] . V_78 ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
unsigned int V_23 , V_70 ;
int V_74 ;
struct V_117 V_118 ;
struct V_119 * V_120 = V_2 -> V_120 ;
char V_104 [ 32 ] ;
strcpy ( V_120 -> V_121 , V_120 -> V_122 ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_17 -> V_123 ; V_23 ++ ) {
V_118 = V_124 ;
V_118 . V_94 = V_23 ;
V_118 . V_125 . V_126 = V_2 -> V_17 -> V_127 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
}
for ( V_23 = 0 ; V_23 < V_2 -> V_17 -> V_123 ; V_23 ++ ) {
int V_12 = V_23 * 2 ;
V_118 = V_128 ;
V_118 . V_94 = V_23 ;
V_118 . V_104 = L_8 ;
V_118 . V_109 = V_12 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
V_118 = V_129 ;
V_118 . V_94 = V_23 ;
V_118 . V_109 = V_12 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
V_118 = V_130 ;
V_118 . V_94 = V_23 ;
V_118 . V_109 = V_12 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
V_118 = V_131 ;
V_118 . V_94 = V_23 ;
V_118 . V_109 = V_12 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
}
for ( V_23 = 0 ; V_23 < V_2 -> V_17 -> V_123 ; V_23 ++ ) {
V_118 = V_128 ;
V_118 . V_94 = V_23 ;
V_118 . V_104 = L_9 ;
V_118 . V_109 = ( V_23 * 2 ) | ( 1 << 8 ) ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
}
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_132 , V_2 ) ) ) < 0 )
return V_74 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_133 , V_2 ) ) ) < 0 )
return V_74 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_134 , V_2 ) ) ) < 0 )
return V_74 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_135 , V_2 ) ) ) < 0 )
return V_74 ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
static char * V_136 [ 2 ] = { L_10 , L_11 } ;
for ( V_23 = 0 ; V_23 < V_2 -> V_17 -> V_71 ; V_23 ++ ) {
int V_12 = ( V_23 * 2 ) | ( V_70 << 8 ) ;
if ( V_70 == 1 ) {
V_118 = V_137 ;
V_118 . V_94 = V_23 ;
V_118 . V_109 = V_12 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
}
sprintf ( V_104 , L_12 , V_136 [ V_70 ] ) ;
V_118 = V_138 ;
V_118 . V_94 = V_23 ;
V_118 . V_104 = V_104 ;
V_118 . V_109 = V_12 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
sprintf ( V_104 , L_13 , V_136 [ V_70 ] ) ;
V_118 = V_139 ;
V_118 . V_94 = V_23 ;
V_118 . V_104 = V_104 ;
V_118 . V_109 = V_12 ;
if ( ( V_74 = F_54 ( V_120 , F_55 ( & V_118 , V_2 ) ) ) < 0 )
return V_74 ;
}
}
F_20 ( V_2 ) ;
return 0 ;
}
