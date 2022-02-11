static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_11 = F_4 ( V_2 , & V_8 -> V_12 ) ;
unsigned long V_13 ;
if ( V_11 >= 3 )
return - V_14 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_8 -> V_16 . V_17 . V_18 [ 0 ] = ( V_10 -> V_19 [ V_11 ] >> 0 ) & 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 1 ] = ( V_10 -> V_19 [ V_11 ] >> 8 ) & 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 2 ] = ( V_10 -> V_19 [ V_11 ] >> 16 ) & 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 3 ] = ( V_10 -> V_19 [ V_11 ] >> 24 ) & 0xff ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_8 -> V_16 . V_17 . V_18 [ 0 ] = 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 1 ] = 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 2 ] = 0xff ;
V_8 -> V_16 . V_17 . V_18 [ 3 ] = 0xff ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
char * * V_20 ;
V_4 -> type = V_21 ;
V_4 -> V_6 = 1 ;
if ( V_10 -> V_22 -> V_23 == V_24 ) {
V_4 -> V_16 . V_25 . V_20 = 49 ;
V_20 = V_26 ;
} else {
V_4 -> V_16 . V_25 . V_20 = 53 ;
V_20 = V_27 ;
}
if ( V_4 -> V_16 . V_25 . V_28 >= V_4 -> V_16 . V_25 . V_20 )
V_4 -> V_16 . V_25 . V_28 =
V_4 -> V_16 . V_25 . V_20 - 1 ;
strcpy ( V_4 -> V_16 . V_25 . V_29 ,
V_20 [ V_4 -> V_16 . V_25 . V_28 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_30 ;
V_30 = ( V_2 -> V_31 ) & 0xff ;
if ( V_30 >= 24 ||
( V_10 -> V_22 -> V_23 == V_24 &&
V_30 >= 18 ) )
return - V_14 ;
V_8 -> V_16 . V_25 . V_28 [ 0 ] = V_10 -> V_32 . V_33 [ V_30 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_34 ;
unsigned int V_30 ;
V_34 = V_8 -> V_16 . V_25 . V_28 [ 0 ] ;
if ( V_34 >= 53 ||
( V_10 -> V_22 -> V_23 == V_24 &&
V_34 >= 49 ) )
return - V_14 ;
V_30 = ( V_2 -> V_31 ) & 0xff ;
if ( V_30 >= 24 ||
( V_10 -> V_22 -> V_23 == V_24 &&
V_30 >= 18 ) )
return - V_14 ;
if ( V_10 -> V_32 . V_33 [ V_30 ] == V_34 )
return 0 ;
V_10 -> V_32 . V_33 [ V_30 ] = V_34 ;
if ( V_10 -> V_22 -> V_23 == V_24 )
F_11 ( V_10 ,
V_35 [ V_30 ] , V_36 [ V_34 ] ) ;
else
F_11 ( V_10 ,
V_37 [ V_30 ] , V_38 [ V_34 ] ) ;
return 1 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_30 ;
V_30 = ( V_2 -> V_31 ) & 0xff ;
if ( V_30 >= 22 )
return - V_14 ;
V_8 -> V_16 . V_25 . V_28 [ 0 ] = V_10 -> V_32 . V_39 [ V_30 ] ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_34 ;
unsigned int V_30 ;
V_34 = V_8 -> V_16 . V_25 . V_28 [ 0 ] ;
if ( V_34 >= 53 ||
( V_10 -> V_22 -> V_23 == V_24 &&
V_34 >= 49 ) )
return - V_14 ;
V_30 = ( V_2 -> V_31 ) & 0xff ;
if ( V_30 >= 22 )
return - V_14 ;
if ( V_10 -> V_32 . V_39 [ V_30 ] == V_34 )
return 0 ;
V_10 -> V_32 . V_39 [ V_30 ] = V_34 ;
if ( V_10 -> V_22 -> V_23 == V_24 )
F_11 ( V_10 ,
V_40 [ V_30 ] , V_36 [ V_34 ] ) ;
else
F_11 ( V_10 ,
V_40 [ V_30 ] , V_38 [ V_34 ] ) ;
return 1 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_41 = V_2 -> V_31 & 0xff ;
V_8 -> V_16 . integer . V_16 [ 0 ] = ( V_10 -> V_32 . V_42 & V_41 ) ? 1 : 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_41 = V_2 -> V_31 & 0xff ;
unsigned int V_34 , V_43 ;
V_34 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
V_43 = V_10 -> V_32 . V_42 ;
if ( V_34 == 1 )
V_43 = V_43 | V_41 ;
else
V_43 = V_43 & ~ V_41 ;
if ( V_43 != V_10 -> V_32 . V_42 ) {
F_16 ( V_10 , V_44 , V_43 ) ;
V_10 -> V_32 . V_42 = V_43 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_41 = V_2 -> V_31 & 0xff ;
V_8 -> V_16 . integer . V_16 [ 0 ] = ( V_10 -> V_32 . V_45 & V_41 ) ? 1 : 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_41 = V_2 -> V_31 & 0xff ;
unsigned int V_34 , V_43 ;
V_34 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
V_43 = V_10 -> V_32 . V_45 ;
if ( V_34 == 1 )
V_43 = V_43 | V_41 ;
else
V_43 = V_43 & ~ V_41 ;
if ( V_43 != V_10 -> V_32 . V_45 ) {
F_16 ( V_10 , V_46 , V_43 ) ;
V_10 -> V_32 . V_45 = V_43 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static char * V_47 [ 4 ] = {
L_1 , L_2 , L_3 , L_4
} ;
V_4 -> type = V_21 ;
V_4 -> V_6 = 1 ;
V_4 -> V_16 . V_25 . V_20 = 4 ;
if ( V_4 -> V_16 . V_25 . V_28 >= V_4 -> V_16 . V_25 . V_20 )
V_4 -> V_16 . V_25 . V_28 = V_4 -> V_16 . V_25 . V_20 - 1 ;
strcpy ( V_4 -> V_16 . V_25 . V_29 , V_47 [ V_4 -> V_16 . V_25 . V_28 ] ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_8 -> V_16 . V_25 . V_28 [ 0 ] = V_10 -> V_32 . V_48 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_34 ;
int V_49 = 0 ;
V_34 = V_8 -> V_16 . V_25 . V_28 [ 0 ] ;
if ( V_34 >= 4 )
return - V_14 ;
V_49 = ( V_10 -> V_32 . V_48 != V_34 ) ;
if ( V_49 ) {
V_10 -> V_32 . V_48 = V_34 ;
switch ( V_34 ) {
case 0 :
F_16 ( V_10 , V_50 , V_51 ) ;
F_16 ( V_10 , V_52 , V_53 ) ;
F_16 ( V_10 , V_54 ,
V_55 | V_56 ) ;
F_16 ( V_10 , V_57 ,
V_58 | V_59 ) ;
F_22 ( 10 ) ;
F_16 ( V_10 , V_50 , V_60 ) ;
break;
case 1 :
F_16 ( V_10 , V_50 , V_51 ) ;
F_16 ( V_10 , V_52 , V_61 ) ;
F_16 ( V_10 , V_54 ,
V_62 | V_56 ) ;
F_16 ( V_10 , V_57 ,
V_63 | V_59 ) ;
F_22 ( 10 ) ;
F_16 ( V_10 , V_50 , V_60 ) ;
break;
case 2 :
F_16 ( V_10 , V_50 , V_51 ) ;
F_16 ( V_10 , V_52 , V_61 ) ;
F_16 ( V_10 , V_54 ,
V_64 | V_56 ) ;
F_16 ( V_10 , V_57 ,
V_65 | V_59 ) ;
F_22 ( 10 ) ;
F_16 ( V_10 , V_50 , V_60 ) ;
break;
case 3 :
F_16 ( V_10 , V_50 , V_51 ) ;
F_16 ( V_10 , V_52 , V_61 ) ;
F_16 ( V_10 , V_54 ,
V_66 | V_56 ) ;
F_16 ( V_10 , V_57 , V_65 | V_59 ) ;
F_22 ( 10 ) ;
F_16 ( V_10 , V_50 , V_60 ) ;
break;
}
}
return V_49 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#if 0
static char *texts[4] = {
"Unknown1", "Unknown2", "Mic", "Line"
};
#endif
static char * V_47 [ 2 ] = {
L_5 , L_6
} ;
V_4 -> type = V_21 ;
V_4 -> V_6 = 1 ;
V_4 -> V_16 . V_25 . V_20 = 2 ;
if ( V_4 -> V_16 . V_25 . V_28 > 1 )
V_4 -> V_16 . V_25 . V_28 = 1 ;
strcpy ( V_4 -> V_16 . V_25 . V_29 , V_47 [ V_4 -> V_16 . V_25 . V_28 ] ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_8 -> V_16 . V_25 . V_28 [ 0 ] = V_10 -> V_67 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_68 ;
unsigned int V_69 , V_70 ;
T_1 V_71 ;
int V_49 = 0 ;
unsigned long V_13 ;
T_1 V_72 ;
V_68 = V_8 -> V_16 . V_25 . V_28 [ 0 ] ;
if ( V_68 >= 2 )
return - V_14 ;
V_49 = ( V_10 -> V_67 != V_68 ) ;
if ( V_49 ) {
F_26 ( V_10 , V_73 , 0 ) ;
F_5 ( & V_10 -> V_74 , V_13 ) ;
V_71 = F_27 ( V_10 -> V_75 + V_76 ) ;
if ( V_68 == 0 )
F_28 ( V_71 | 0x4 , V_10 -> V_75 + V_76 ) ;
else
F_28 ( V_71 & ~ 0x4 , V_10 -> V_75 + V_76 ) ;
F_6 ( & V_10 -> V_74 , V_13 ) ;
V_69 = V_10 -> V_77 [ V_68 ] [ 0 ] ;
V_70 = V_10 -> V_77 [ V_10 -> V_67 ] [ 0 ] ;
if ( V_69 != V_70 )
F_26 ( V_10 , V_78 , ( ( V_69 ) & 0xff ) ) ;
V_69 = V_10 -> V_77 [ V_68 ] [ 1 ] ;
V_70 = V_10 -> V_77 [ V_10 -> V_67 ] [ 1 ] ;
if ( V_69 != V_70 )
F_26 ( V_10 , V_79 , ( ( V_69 ) & 0xff ) ) ;
V_72 = 1 << ( V_68 + 2 ) ;
F_26 ( V_10 , V_73 , V_72 ) ;
V_10 -> V_67 = V_68 ;
}
return V_49 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_80 ;
V_4 -> V_6 = 2 ;
V_4 -> V_16 . integer . V_81 = 0 ;
V_4 -> V_16 . integer . V_82 = 255 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_68 ;
V_68 = V_2 -> V_31 ;
if ( V_68 >= 2 )
return - V_14 ;
V_8 -> V_16 . integer . V_16 [ 0 ] = V_10 -> V_77 [ V_68 ] [ 0 ] ;
V_8 -> V_16 . integer . V_16 [ 1 ] = V_10 -> V_77 [ V_68 ] [ 1 ] ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_70 ;
unsigned int V_69 ;
unsigned int V_68 ;
int V_49 = 0 ;
V_68 = V_2 -> V_31 ;
if ( V_68 >= 2 )
return - V_14 ;
V_70 = V_10 -> V_77 [ V_68 ] [ 0 ] ;
V_69 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_69 > 0xff )
return 0 ;
if ( V_70 != V_69 ) {
if ( V_10 -> V_67 == V_68 )
F_26 ( V_10 , V_78 , ( ( V_69 ) & 0xff ) ) ;
V_10 -> V_77 [ V_68 ] [ 0 ] = V_69 ;
V_49 = 1 ;
}
V_70 = V_10 -> V_77 [ V_68 ] [ 1 ] ;
V_69 = V_8 -> V_16 . integer . V_16 [ 1 ] ;
if ( V_69 > 0xff )
return 0 ;
if ( V_70 != V_69 ) {
if ( V_10 -> V_67 == V_68 )
F_26 ( V_10 , V_79 , ( ( V_69 ) & 0xff ) ) ;
V_10 -> V_77 [ V_68 ] [ 1 ] = V_69 ;
V_49 = 1 ;
}
return V_49 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_11 = F_4 ( V_2 , & V_8 -> V_12 ) ;
int V_49 ;
unsigned int V_34 ;
unsigned long V_13 ;
if ( V_11 >= 3 )
return - V_14 ;
V_34 = ( V_8 -> V_16 . V_17 . V_18 [ 0 ] << 0 ) |
( V_8 -> V_16 . V_17 . V_18 [ 1 ] << 8 ) |
( V_8 -> V_16 . V_17 . V_18 [ 2 ] << 16 ) |
( V_8 -> V_16 . V_17 . V_18 [ 3 ] << 24 ) ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_49 = V_34 != V_10 -> V_19 [ V_11 ] ;
if ( V_49 ) {
F_33 ( V_10 , V_83 + V_11 , 0 , V_34 ) ;
V_10 -> V_19 [ V_11 ] = V_34 ;
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_49 ;
}
static void F_34 ( struct V_9 * V_10 , int V_84 , unsigned char * V_85 )
{
if ( V_10 -> V_86 ) {
F_33 ( V_10 , V_87 , V_84 ,
F_35 ( V_85 ) ) ;
F_33 ( V_10 , V_88 , V_84 ,
F_36 ( V_85 ) ) ;
} else {
F_33 ( V_10 , V_89 , V_84 ,
F_37 ( V_85 ) ) ;
}
}
static void F_38 ( struct V_9 * V_10 , int V_84 , unsigned char * V_90 )
{
F_33 ( V_10 , V_91 , V_84 , V_90 [ 0 ] ) ;
F_33 ( V_10 , V_92 , V_84 , V_90 [ 1 ] ) ;
F_33 ( V_10 , V_93 , V_84 , V_90 [ 2 ] ) ;
F_33 ( V_10 , V_94 , V_84 , V_90 [ 3 ] ) ;
if ( V_10 -> V_86 ) {
unsigned int V_34 = ( ( unsigned int ) V_90 [ 4 ] << 24 ) |
( ( unsigned int ) V_90 [ 5 ] << 16 ) |
( ( unsigned int ) V_90 [ 6 ] << 8 ) |
( unsigned int ) V_90 [ 7 ] ;
F_33 ( V_10 , V_95 , V_84 , V_34 ) ;
}
}
static int F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_80 ;
V_4 -> V_6 = V_10 -> V_86 ? 3 * 8 : 3 * 4 ;
V_4 -> V_16 . integer . V_81 = 0 ;
V_4 -> V_16 . integer . V_82 = V_10 -> V_86 ? 0x3f : 0x0f ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_98 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_84 , V_11 ;
int V_99 = V_10 -> V_86 ? 8 : 4 ;
int V_41 = V_10 -> V_86 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_84 = 0 ; V_84 < 3 ; V_84 ++ )
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ ( V_84 * V_99 ) + V_11 ] =
V_97 -> V_100 [ V_84 ] [ V_11 ] & V_41 ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_98 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_49 = 0 , V_84 , V_11 , V_34 ;
int V_99 = V_10 -> V_86 ? 8 : 4 ;
int V_41 = V_10 -> V_86 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_84 = 0 ; V_84 < 3 ; V_84 ++ )
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ ) {
V_34 = V_8 -> V_16 . integer . V_16 [ ( V_84 * V_99 ) + V_11 ] & V_41 ;
if ( V_97 -> V_100 [ V_84 ] [ V_11 ] != V_34 ) {
V_97 -> V_100 [ V_84 ] [ V_11 ] = V_34 ;
V_49 = 1 ;
}
}
if ( V_49 && V_97 -> V_101 ) {
if ( V_97 -> V_101 -> V_102 [ 0 ] && V_97 -> V_101 -> V_102 [ 1 ] ) {
F_34 ( V_10 , V_97 -> V_101 -> V_102 [ 0 ] -> V_103 ,
& V_97 -> V_100 [ 1 ] [ 0 ] ) ;
F_34 ( V_10 , V_97 -> V_101 -> V_102 [ 1 ] -> V_103 ,
& V_97 -> V_100 [ 2 ] [ 0 ] ) ;
} else if ( V_97 -> V_101 -> V_102 [ 0 ] ) {
F_34 ( V_10 , V_97 -> V_101 -> V_102 [ 0 ] -> V_103 ,
& V_97 -> V_100 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_49 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_80 ;
V_4 -> V_6 = V_10 -> V_86 ? 3 * 8 : 3 * 4 ;
V_4 -> V_16 . integer . V_81 = 0 ;
V_4 -> V_16 . integer . V_82 = 255 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_98 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_99 = V_10 -> V_86 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 * V_99 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_97 -> V_104 [ V_11 / V_99 ] [ V_11 % V_99 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_98 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_49 = 0 , V_11 , V_34 ;
int V_99 = V_10 -> V_86 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 * V_99 ; V_11 ++ ) {
V_34 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 255 ;
if ( V_97 -> V_104 [ V_11 / V_99 ] [ V_11 % V_99 ] != V_34 ) {
V_97 -> V_104 [ V_11 / V_99 ] [ V_11 % V_99 ] = V_34 ;
V_49 = 1 ;
}
}
if ( V_49 && V_97 -> V_101 ) {
if ( V_97 -> V_101 -> V_102 [ 0 ] && V_97 -> V_101 -> V_102 [ 1 ] ) {
F_38 ( V_10 , V_97 -> V_101 -> V_102 [ 0 ] -> V_103 ,
& V_97 -> V_104 [ 1 ] [ 0 ] ) ;
F_38 ( V_10 , V_97 -> V_101 -> V_102 [ 1 ] -> V_103 ,
& V_97 -> V_104 [ 2 ] [ 0 ] ) ;
} else if ( V_97 -> V_101 -> V_102 [ 0 ] ) {
F_38 ( V_10 , V_97 -> V_101 -> V_102 [ 0 ] -> V_103 ,
& V_97 -> V_104 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_49 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_80 ;
V_4 -> V_6 = 3 ;
V_4 -> V_16 . integer . V_81 = 0 ;
V_4 -> V_16 . integer . V_82 = 0xffff ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_98 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
unsigned long V_13 ;
int V_11 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_97 -> V_105 [ V_11 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_98 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_49 = 0 , V_11 , V_34 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_34 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 0xffff ;
if ( V_97 -> V_105 [ V_11 ] != V_34 ) {
V_97 -> V_105 [ V_11 ] = V_34 ;
V_49 = 1 ;
}
}
if ( V_49 && V_97 -> V_101 ) {
if ( V_97 -> V_101 -> V_102 [ 0 ] && V_97 -> V_101 -> V_102 [ 1 ] ) {
F_33 ( V_10 , V_106 , V_97 -> V_101 -> V_102 [ 0 ] -> V_103 , V_97 -> V_105 [ 1 ] ) ;
F_33 ( V_10 , V_106 , V_97 -> V_101 -> V_102 [ 1 ] -> V_103 , V_97 -> V_105 [ 2 ] ) ;
} else if ( V_97 -> V_101 -> V_102 [ 0 ] ) {
F_33 ( V_10 , V_106 , V_97 -> V_101 -> V_102 [ 0 ] -> V_103 , V_97 -> V_105 [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_49 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_80 ;
V_4 -> V_6 = V_10 -> V_86 ? 8 : 4 ;
V_4 -> V_16 . integer . V_81 = 0 ;
V_4 -> V_16 . integer . V_82 = V_10 -> V_86 ? 0x3f : 0x0f ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_107 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_99 = V_10 -> V_86 ? 8 : 4 ;
int V_41 = V_10 -> V_86 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] =
V_97 -> V_100 [ 0 ] [ V_11 ] & V_41 ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_108 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_96 * V_97 = & V_10 -> V_107 [ V_108 ] ;
int V_49 = 0 , V_11 , V_34 ;
int V_99 = V_10 -> V_86 ? 8 : 4 ;
int V_41 = V_10 -> V_86 ? 0x3f : 0x0f ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ ) {
V_34 = V_8 -> V_16 . integer . V_16 [ V_11 ] & V_41 ;
if ( V_97 -> V_100 [ 0 ] [ V_11 ] != V_34 ) {
V_97 -> V_100 [ 0 ] [ V_11 ] = V_34 ;
V_49 = 1 ;
}
}
if ( V_49 && V_97 -> V_101 ) {
if ( V_97 -> V_101 -> V_102 [ V_108 ] ) {
F_34 ( V_10 , V_97 -> V_101 -> V_102 [ V_108 ] -> V_103 ,
& V_97 -> V_100 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_49 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
V_4 -> type = V_80 ;
V_4 -> V_6 = V_10 -> V_86 ? 8 : 4 ;
V_4 -> V_16 . integer . V_81 = 0 ;
V_4 -> V_16 . integer . V_82 = 255 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_107 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
int V_11 ;
int V_99 = V_10 -> V_86 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ )
V_8 -> V_16 . integer . V_16 [ V_11 ] = V_97 -> V_104 [ 0 ] [ V_11 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_108 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_96 * V_97 = & V_10 -> V_107 [ V_108 ] ;
int V_49 = 0 , V_11 , V_34 ;
int V_99 = V_10 -> V_86 ? 8 : 4 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ ) {
V_34 = V_8 -> V_16 . integer . V_16 [ V_11 ] & 255 ;
if ( V_97 -> V_104 [ 0 ] [ V_11 ] != V_34 ) {
V_97 -> V_104 [ 0 ] [ V_11 ] = V_34 ;
V_49 = 1 ;
}
}
if ( V_49 && V_97 -> V_101 ) {
if ( V_97 -> V_101 -> V_102 [ V_108 ] ) {
F_38 ( V_10 , V_97 -> V_101 -> V_102 [ V_108 ] -> V_103 ,
& V_97 -> V_104 [ 0 ] [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_49 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_80 ;
V_4 -> V_6 = 1 ;
V_4 -> V_16 . integer . V_81 = 0 ;
V_4 -> V_16 . integer . V_82 = 0xffff ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_96 * V_97 =
& V_10 -> V_107 [ F_4 ( V_2 , & V_8 -> V_12 ) ] ;
unsigned long V_13 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_8 -> V_16 . integer . V_16 [ 0 ] = V_97 -> V_105 [ 0 ] ;
F_6 ( & V_10 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_108 = F_4 ( V_2 , & V_8 -> V_12 ) ;
struct V_96 * V_97 = & V_10 -> V_107 [ V_108 ] ;
int V_49 = 0 , V_34 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
V_34 = V_8 -> V_16 . integer . V_16 [ 0 ] & 0xffff ;
if ( V_97 -> V_105 [ 0 ] != V_34 ) {
V_97 -> V_105 [ 0 ] = V_34 ;
V_49 = 1 ;
}
if ( V_49 && V_97 -> V_101 ) {
if ( V_97 -> V_101 -> V_102 [ V_108 ] ) {
F_33 ( V_10 , V_106 , V_97 -> V_101 -> V_102 [ V_108 ] -> V_103 , V_97 -> V_105 [ 0 ] ) ;
}
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_49 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
if ( V_10 -> V_86 )
V_8 -> V_16 . integer . V_16 [ 0 ] = F_27 ( V_10 -> V_75 + V_76 ) & V_109 ? 1 : 0 ;
else
V_8 -> V_16 . integer . V_16 [ 0 ] = F_27 ( V_10 -> V_75 + V_110 ) & V_111 ? 1 : 0 ;
if ( V_10 -> V_22 -> V_112 )
V_8 -> V_16 . integer . V_16 [ 0 ] =
! V_8 -> V_16 . integer . V_16 [ 0 ] ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned long V_13 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_113 , V_34 , V_114 ;
int V_49 = 0 ;
V_114 = V_8 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_10 -> V_22 -> V_112 )
V_114 = ! V_114 ;
F_5 ( & V_10 -> V_15 , V_13 ) ;
if ( V_10 -> V_22 -> V_115 ) {
} else if ( V_10 -> V_86 ) {
V_113 = F_27 ( V_10 -> V_75 + V_76 ) ;
V_34 = V_114 ? V_109 : 0 ;
V_49 = ( V_113 & V_109 ) != V_34 ;
if ( V_49 ) {
V_113 &= ~ V_109 ;
V_113 |= V_34 ;
F_28 ( V_113 | V_34 , V_10 -> V_75 + V_76 ) ;
}
}
V_113 = F_27 ( V_10 -> V_75 + V_110 ) ;
V_34 = V_114 ? V_111 : 0 ;
V_49 |= ( V_113 & V_111 ) != V_34 ;
if ( V_49 ) {
V_113 &= ~ V_111 ;
V_113 |= V_34 ;
F_28 ( V_113 | V_34 , V_10 -> V_75 + V_110 ) ;
}
F_6 ( & V_10 -> V_15 , V_13 ) ;
return V_49 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_34 ;
V_34 = F_60 ( V_10 -> V_116 , V_117 ) ;
V_8 -> V_16 . integer . V_16 [ 0 ] = ! ! V_34 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_34 ;
if ( V_8 -> V_16 . integer . V_16 [ 0 ] )
V_34 = 0x0f0f ;
else
V_34 = 0 ;
return F_62 ( V_10 -> V_116 , V_117 , V_34 ) ;
}
static void F_63 ( struct V_118 * V_116 )
{
struct V_9 * V_10 = V_116 -> V_119 ;
V_10 -> V_116 = NULL ;
}
static int F_64 ( struct V_120 * V_121 , const char * V_29 )
{
struct V_122 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
strcpy ( V_12 . V_29 , V_29 ) ;
V_12 . V_123 = V_124 ;
return F_65 ( V_121 , & V_12 ) ;
}
static struct V_1 * F_66 ( struct V_120 * V_121 , const char * V_29 )
{
struct V_122 V_125 ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
strcpy ( V_125 . V_29 , V_29 ) ;
V_125 . V_123 = V_124 ;
return F_67 ( V_121 , & V_125 ) ;
}
static int F_68 ( struct V_120 * V_121 , const char * V_126 , const char * V_127 )
{
struct V_1 * V_128 = F_66 ( V_121 , V_126 ) ;
if ( V_128 ) {
strcpy ( V_128 -> V_12 . V_29 , V_127 ) ;
return 0 ;
}
return - V_129 ;
}
int T_2 F_69 ( struct V_9 * V_10 ,
int V_130 , int V_131 )
{
int V_132 , V_133 ;
struct V_1 * V_128 ;
struct V_120 * V_121 = V_10 -> V_121 ;
char * * V_134 ;
static char * V_135 [] = {
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
NULL
} ;
static char * V_136 [] = {
L_17 , L_12 ,
L_18 , L_14 ,
L_19 , L_16 ,
NULL
} ;
static char * V_137 [] = {
L_20 ,
L_21 ,
L_7 ,
L_8 ,
L_22 ,
L_23 ,
L_9 ,
L_10 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
NULL
} ;
static char * V_138 [] = {
L_32 , L_21 ,
L_33 , L_23 ,
L_34 , L_31 ,
NULL
} ;
static char * V_139 [] = {
L_35 , L_36 ,
L_32 , L_37 ,
L_33 , L_23 ,
L_34 , L_38 ,
L_39 , L_40 ,
NULL
} ;
static char * V_140 [] = {
L_41 ,
L_36 ,
L_42 ,
L_40 ,
NULL
} ;
static char * V_141 [] = {
L_20 ,
L_21 ,
L_7 ,
L_8 ,
L_24 ,
L_25 ,
L_26 ,
L_41 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
NULL
} ;
static char * V_142 [] = {
L_22 , L_50 ,
L_23 , L_51 ,
L_33 , L_23 ,
L_52 , L_53 ,
L_54 , L_55 ,
L_56 , L_57 ,
L_58 , L_59 ,
L_30 , L_60 ,
L_31 , L_41 ,
L_61 , L_62 ,
L_63 , L_35 ,
L_64 , L_65 ,
L_66 , L_39 ,
L_67 , L_68 ,
L_69 , L_42 ,
L_28 , L_70 ,
L_29 , L_71 ,
NULL
} ;
if ( V_10 -> V_22 -> V_143 ) {
struct V_144 * V_145 ;
struct V_146 V_116 ;
static struct V_147 V_148 = {
. V_149 = V_150 ,
. V_151 = V_152 ,
} ;
if ( ( V_132 = V_144 ( V_10 -> V_121 , 0 , & V_148 , NULL , & V_145 ) ) < 0 )
return V_132 ;
V_145 -> V_153 = 1 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_119 = V_10 ;
V_116 . V_154 = F_63 ;
V_116 . V_155 = V_156 ;
if ( ( V_132 = F_70 ( V_145 , & V_116 , & V_10 -> V_116 ) ) < 0 ) {
if ( V_10 -> V_22 -> V_143 == 1 )
return V_132 ;
F_71 ( V_157 L_72 ) ;
F_71 ( V_157 L_73 ) ;
F_72 ( V_10 -> V_121 , V_145 ) ;
goto V_158;
}
if ( V_10 -> V_86 ) {
F_73 ( V_10 -> V_116 , V_159 , 0x0000 ) ;
F_73 ( V_10 -> V_116 , V_160 , 0x0000 ) ;
if ( V_10 -> V_22 -> V_161 )
V_134 = V_141 ;
else
V_134 = V_137 ;
} else {
if ( V_10 -> V_116 -> V_12 == V_162 ) {
V_10 -> V_163 = 1 ;
F_33 ( V_10 , V_164 , 0 , V_165 | V_166 | V_167 | V_168 ) ;
F_73 ( V_10 -> V_116 , V_169 , 0x0202 ) ;
F_64 ( V_121 , L_74 ) ;
F_64 ( V_121 , L_75 ) ;
}
F_73 ( V_10 -> V_116 , V_170 , 0x0202 ) ;
F_73 ( V_10 -> V_116 , V_171 , 0x0202 ) ;
V_134 = V_135 ;
}
for (; * V_134 ; V_134 ++ )
F_64 ( V_121 , * V_134 ) ;
} else if ( V_10 -> V_22 -> V_115 ) {
V_134 = V_140 ;
for (; * V_134 ; V_134 ++ )
F_64 ( V_121 , * V_134 ) ;
} else {
V_158:
if ( V_10 -> V_22 -> V_172 )
strcpy ( V_10 -> V_121 -> V_173 , L_76 ) ;
else if ( V_10 -> V_86 )
strcpy ( V_10 -> V_121 -> V_173 , L_77 ) ;
else
strcpy ( V_10 -> V_121 -> V_173 , L_78 ) ;
}
if ( V_10 -> V_86 )
if ( V_10 -> V_22 -> V_161 )
V_134 = V_142 ;
else if ( V_10 -> V_22 -> V_115 )
V_134 = V_139 ;
else
V_134 = V_138 ;
else
V_134 = V_136 ;
for (; * V_134 ; V_134 += 2 )
F_68 ( V_121 , V_134 [ 0 ] , V_134 [ 1 ] ) ;
if ( V_10 -> V_22 -> V_174 == 0x80401102 ) {
F_64 ( V_121 , L_14 ) ;
F_64 ( V_121 , L_16 ) ;
F_64 ( V_121 , L_79 ) ;
F_64 ( V_121 , L_80 ) ;
}
if ( V_10 -> V_22 -> V_174 == 0x20071102 ) {
F_68 ( V_121 , L_49 , L_81 ) ;
F_68 ( V_121 , L_36 , L_49 ) ;
F_68 ( V_121 , L_82 , L_83 ) ;
F_68 ( V_121 , L_41 , L_84 ) ;
F_64 ( V_121 , L_43 ) ;
F_64 ( V_121 , L_44 ) ;
F_64 ( V_121 , L_45 ) ;
F_64 ( V_121 , L_46 ) ;
F_64 ( V_121 , L_47 ) ;
}
if ( ( V_128 = V_10 -> V_175 = F_74 ( & V_176 , V_10 ) ) == NULL )
return - V_177 ;
V_128 -> V_12 . V_178 = V_130 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
if ( ( V_128 = V_10 -> V_179 = F_74 ( & V_180 , V_10 ) ) == NULL )
return - V_177 ;
V_128 -> V_12 . V_178 = V_130 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
if ( ( V_128 = V_10 -> V_181 = F_74 ( & V_182 , V_10 ) ) == NULL )
return - V_177 ;
V_128 -> V_12 . V_178 = V_130 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
if ( ( V_128 = V_10 -> V_183 = F_74 ( & V_184 , V_10 ) ) == NULL )
return - V_177 ;
V_128 -> V_12 . V_178 = V_131 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
if ( ( V_128 = V_10 -> V_185 = F_74 ( & V_186 , V_10 ) ) == NULL )
return - V_177 ;
V_128 -> V_12 . V_178 = V_131 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
if ( ( V_128 = V_10 -> V_187 = F_74 ( & V_188 , V_10 ) ) == NULL )
return - V_177 ;
V_128 -> V_12 . V_178 = V_131 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
for ( V_133 = 0 ; V_133 < 32 ; V_133 ++ ) {
struct V_96 * V_97 ;
int V_189 ;
V_97 = & V_10 -> V_98 [ V_133 ] ;
V_97 -> V_101 = NULL ;
for ( V_189 = 0 ; V_189 < 4 ; V_189 ++ )
V_97 -> V_100 [ 0 ] [ V_189 ] =
V_97 -> V_100 [ 1 ] [ V_189 ] =
V_97 -> V_100 [ 2 ] [ V_189 ] = V_189 ;
memset ( & V_97 -> V_104 , 0 , sizeof( V_97 -> V_104 ) ) ;
V_97 -> V_104 [ 0 ] [ 0 ] = V_97 -> V_104 [ 0 ] [ 1 ] =
V_97 -> V_104 [ 1 ] [ 0 ] = V_97 -> V_104 [ 2 ] [ 1 ] = 255 ;
V_97 -> V_105 [ 0 ] = V_97 -> V_105 [ 1 ] = V_97 -> V_105 [ 2 ] = 0xffff ;
}
for ( V_133 = 0 ; V_133 < V_190 ; V_133 ++ ) {
struct V_96 * V_97 ;
int V_189 ;
V_97 = & V_10 -> V_107 [ V_133 ] ;
V_97 -> V_101 = NULL ;
V_97 -> V_100 [ 0 ] [ 0 ] = V_133 ;
V_97 -> V_100 [ 0 ] [ 1 ] = ( V_133 == 0 ) ? 1 : 0 ;
for ( V_189 = 0 ; V_189 < 2 ; V_189 ++ )
V_97 -> V_100 [ 0 ] [ 2 + V_189 ] = 13 + V_189 ;
if ( V_10 -> V_86 )
for ( V_189 = 0 ; V_189 < 4 ; V_189 ++ )
V_97 -> V_100 [ 0 ] [ 4 + V_189 ] = 60 + V_189 ;
memset ( & V_97 -> V_104 , 0 , sizeof( V_97 -> V_104 ) ) ;
V_97 -> V_104 [ 0 ] [ 0 ] = 255 ;
V_97 -> V_105 [ 0 ] = 0xffff ;
}
if ( ! V_10 -> V_22 -> V_172 ) {
if ( ( V_128 = F_74 ( & V_191 , V_10 ) ) == NULL )
return - V_177 ;
if ( ! V_10 -> V_86 )
V_128 -> V_12 . V_178 = V_10 -> V_192 -> V_178 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
if ( ( V_128 = F_74 ( & V_193 , V_10 ) ) == NULL )
return - V_177 ;
if ( ! V_10 -> V_86 )
V_128 -> V_12 . V_178 = V_10 -> V_192 -> V_178 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
}
if ( V_10 -> V_22 -> V_23 ) {
;
} else if ( V_10 -> V_86 ) {
if ( ( V_128 = F_74 ( & V_194 , V_10 ) ) == NULL )
return - V_177 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
#if 0
if ((kctl = snd_ctl_new1(&snd_audigy_spdif_output_rate, emu)) == NULL)
return -ENOMEM;
if ((err = snd_ctl_add(card, kctl)))
return err;
#endif
} else if ( ! V_10 -> V_22 -> V_172 ) {
if ( ( V_128 = F_74 ( & V_195 , V_10 ) ) == NULL )
return - V_177 ;
if ( ( V_132 = F_75 ( V_121 , V_128 ) ) )
return V_132 ;
}
if ( V_10 -> V_22 -> V_196 ) {
if ( ( V_132 = F_76 ( V_10 ) ) )
return V_132 ;
}
if ( V_10 -> V_22 -> V_23 == V_24 ) {
int V_197 ;
for ( V_197 = 0 ; V_197 < F_77 ( V_198 ) ; V_197 ++ ) {
V_132 = F_75 ( V_121 ,
F_74 ( & V_198 [ V_197 ] ,
V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
for ( V_197 = 0 ; V_197 < F_77 ( V_199 ) ; V_197 ++ ) {
V_132 = F_75 ( V_121 ,
F_74 ( & V_199 [ V_197 ] ,
V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
for ( V_197 = 0 ; V_197 < F_77 ( V_200 ) - 2 ; V_197 ++ ) {
V_132 = F_75 ( V_121 ,
F_74 ( & V_200 [ V_197 ] , V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
for ( V_197 = 0 ; V_197 < F_77 ( V_201 ) - 2 ; V_197 ++ ) {
V_132 = F_75 ( V_121 ,
F_74 ( & V_201 [ V_197 ] , V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
V_132 = F_75 ( V_121 ,
F_74 ( & V_202 , V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
} else if ( V_10 -> V_22 -> V_23 ) {
int V_197 ;
for ( V_197 = 0 ; V_197 < F_77 ( V_203 ) ; V_197 ++ ) {
V_132 = F_75 ( V_121 ,
F_74 ( & V_203 [ V_197 ] ,
V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
for ( V_197 = 0 ; V_197 < F_77 ( V_199 ) ; V_197 ++ ) {
V_132 = F_75 ( V_121 ,
F_74 ( & V_199 [ V_197 ] ,
V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
for ( V_197 = 0 ; V_197 < F_77 ( V_200 ) ; V_197 ++ ) {
V_132 = F_75 ( V_121 ,
F_74 ( & V_200 [ V_197 ] , V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
for ( V_197 = 0 ; V_197 < F_77 ( V_201 ) ; V_197 ++ ) {
V_132 = F_75 ( V_121 ,
F_74 ( & V_201 [ V_197 ] , V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
V_132 = F_75 ( V_121 ,
F_74 ( & V_202 , V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_10 -> V_22 -> V_115 ) {
int V_197 ;
V_132 = F_75 ( V_121 , F_74 ( & V_204 , V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
for ( V_197 = 0 ; V_197 < F_77 ( V_205 ) ; V_197 ++ ) {
V_132 = F_75 ( V_121 , F_74 ( & V_205 [ V_197 ] , V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
}
if ( V_10 -> V_22 -> V_143 && V_10 -> V_86 ) {
V_132 = F_75 ( V_121 , F_74 ( & V_206 ,
V_10 ) ) ;
if ( V_132 < 0 )
return V_132 ;
}
return 0 ;
}
