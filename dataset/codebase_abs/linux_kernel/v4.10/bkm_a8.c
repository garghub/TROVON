static inline T_1
F_1 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 )
{
register T_1 V_4 ;
F_2 ( V_1 , V_3 ) ;
V_4 = F_3 ( V_2 ) & 0xFF ;
return ( V_4 ) ;
}
static inline void
F_4 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 , T_1 * V_5 , int V_6 )
{
int V_7 ;
F_2 ( V_1 , V_3 ) ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
V_5 [ V_7 ] = F_3 ( V_2 ) & 0xFF ;
}
static inline void
F_5 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 , T_1 V_5 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_5 ) ;
}
static inline void
F_6 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 , T_1 * V_5 , int V_6 )
{
int V_7 ;
F_2 ( V_1 , V_3 ) ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
F_2 ( V_2 , V_5 [ V_7 ] ) ;
}
static T_1
F_7 ( struct V_8 * V_9 , T_1 V_10 )
{
return ( F_1 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_10 | 0x80 ) ) ;
}
static void
F_8 ( struct V_8 * V_9 , T_1 V_10 , T_1 V_15 )
{
F_5 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_10 | 0x80 , V_15 ) ;
}
static void
F_9 ( struct V_8 * V_9 , T_1 * V_5 , int V_6 )
{
F_4 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , 0x80 , V_5 , V_6 ) ;
}
static void
F_10 ( struct V_8 * V_9 , T_1 * V_5 , int V_6 )
{
F_6 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , 0x80 , V_5 , V_6 ) ;
}
static T_1
F_11 ( struct V_8 * V_9 , int V_16 , T_1 V_10 )
{
return ( F_1 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_10 + ( V_16 ? 0x40 : 0 ) ) ) ;
}
static void
F_12 ( struct V_8 * V_9 , int V_16 , T_1 V_10 , T_1 V_15 )
{
F_5 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_10 + ( V_16 ? 0x40 : 0 ) , V_15 ) ;
}
static void
F_13 ( struct V_8 * V_9 , T_2 V_17 )
{
F_5 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_18 ,
V_17 ? 0xc0 : 0xff ) ;
}
static T_3
F_14 ( int V_19 , void * V_20 )
{
struct V_8 * V_9 = V_20 ;
T_1 V_21 , V_22 , V_23 = 5 ;
T_4 V_24 ;
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_21 = F_1 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_26 ) ;
if ( ! ( V_21 & 0x3f ) ) {
F_16 ( & V_9 -> V_25 , V_24 ) ;
return V_27 ;
}
V_28:
if ( V_9 -> V_29 & V_30 )
F_17 ( V_9 , L_1 , V_21 ) ;
if ( V_21 & 0x0f ) {
V_22 = F_1 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_31 + 0x40 ) ;
if ( V_21 & 0x01 )
V_22 |= 0x01 ;
if ( V_21 & 0x04 )
V_22 |= 0x02 ;
if ( V_21 & 0x08 )
V_22 |= 0x04 ;
if ( V_22 ) {
F_18 ( V_9 , V_22 ) ;
}
}
if ( V_21 & 0x20 ) {
V_22 = 0xfe & F_1 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_32 | 0x80 ) ;
if ( V_22 ) {
F_19 ( V_9 , V_22 ) ;
}
}
if ( V_21 & 0x10 ) {
V_22 = 0x01 ;
F_19 ( V_9 , V_22 ) ;
}
V_21 = F_1 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_26 ) ;
if ( ( V_21 & 0x3f ) && V_23 ) {
V_23 -- ;
goto V_28;
}
if ( ! V_23 )
F_20 ( V_33 L_2 ,
V_34 [ V_9 -> V_35 ] ) ;
F_5 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_18 , 0xFF ) ;
F_5 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_18 , 0xC0 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return V_36 ;
}
static void
F_21 ( struct V_8 * V_9 )
{
F_22 ( V_9 -> V_11 . V_12 . V_13 & 0xffffffc0 , 128 ) ;
if ( V_9 -> V_35 == V_37 )
F_22 ( V_9 -> V_11 . V_12 . V_38 , 64 ) ;
}
static void
F_23 ( struct V_8 * V_9 , unsigned V_39 )
{
if ( V_9 -> V_40 == V_41 ) {
if ( V_39 )
F_2 ( V_9 -> V_11 . V_12 . V_38 + 0x4C , ( F_3 ( V_9 -> V_11 . V_12 . V_38 + 0x4C ) | 0x41 ) ) ;
else
F_2 ( V_9 -> V_11 . V_12 . V_38 + 0x4C , ( F_3 ( V_9 -> V_11 . V_12 . V_38 + 0x4C ) & ~ 0x41 ) ) ;
}
}
static void
F_24 ( struct V_8 * V_9 )
{
if ( V_9 -> V_35 == V_37 ) {
F_2 ( V_9 -> V_11 . V_12 . V_38 + 0x50 , ( F_3 ( V_9 -> V_11 . V_12 . V_38 + 0x50 ) & ~ 4 ) ) ;
F_25 ( 10 ) ;
F_2 ( V_9 -> V_11 . V_12 . V_38 + 0x50 , ( F_3 ( V_9 -> V_11 . V_12 . V_38 + 0x50 ) | 4 ) ) ;
F_25 ( 10 ) ;
}
}
static int
F_26 ( struct V_8 * V_9 , int V_42 , void * V_43 )
{
T_4 V_24 ;
switch ( V_42 ) {
case V_44 :
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_13 ( V_9 , 0 ) ;
F_23 ( V_9 , 0 ) ;
F_24 ( V_9 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return ( 0 ) ;
case V_45 :
F_15 ( & V_9 -> V_25 , V_24 ) ;
F_13 ( V_9 , 0 ) ;
F_23 ( V_9 , 0 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
F_21 ( V_9 ) ;
return ( 0 ) ;
case V_46 :
F_15 ( & V_9 -> V_25 , V_24 ) ;
V_9 -> V_29 |= V_30 ;
F_13 ( V_9 , 1 ) ;
F_27 ( V_9 , 3 ) ;
F_23 ( V_9 , 1 ) ;
F_16 ( & V_9 -> V_25 , V_24 ) ;
return ( 0 ) ;
case V_47 :
return ( 0 ) ;
}
return ( 0 ) ;
}
static int F_28 ( T_2 V_2 , T_2 V_48 )
{
if ( ! F_29 ( V_2 , V_48 , L_3 ) ) {
F_20 ( V_33
L_4 ,
V_2 , V_2 + V_48 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
int F_30 ( struct V_49 * V_50 )
{
struct V_8 * V_9 = V_50 -> V_9 ;
char V_51 [ 64 ] ;
T_2 V_52 = 0 ;
T_2 V_53 , V_54 , V_55 , V_56 , V_57 ;
strcpy ( V_51 , V_58 ) ;
F_20 ( V_59 L_5 , F_31 ( V_51 ) ) ;
if ( V_9 -> V_40 == V_41 ) {
V_9 -> V_35 = V_37 ;
} else
return ( 0 ) ;
if ( V_50 -> V_60 [ 0 ] >= V_37 && V_50 -> V_60 [ 0 ] <= V_61 )
V_9 -> V_35 = V_50 -> V_60 [ 0 ] ;
else {
F_20 ( V_33 L_6
L_7 ) ;
return ( 0 ) ;
}
if ( ( V_9 -> V_35 != V_37 ) && ( ( V_62 != V_63 ) ||
( V_64 != V_65 ) ) )
return ( 0 ) ;
if ( V_9 -> V_35 == V_37 ) {
while ( ( V_66 = F_32 ( V_67 ,
V_68 , V_66 ) ) ) {
V_64 = V_66 -> V_69 ;
V_62 = V_66 -> V_70 ;
if ( ( V_62 == V_63 ) &&
( V_64 == V_65 ) ) {
if ( F_33 ( V_66 ) )
return ( 0 ) ;
V_53 = F_34 ( V_66 , 1 ) ;
V_71 = V_66 -> V_72 ;
V_73 = V_66 -> V_74 -> V_75 ;
V_76 = V_66 -> V_77 ;
V_52 = 1 ;
break;
}
}
if ( ! V_52 ) {
F_20 ( V_33 L_8
L_9 ,
V_34 [ V_9 -> V_35 ] ) ;
return ( 0 ) ;
}
#ifdef F_35
if ( ( V_53 & 0x80 ) && ( V_66 -> V_78 == 1 ) ) {
F_20 ( V_33 L_8
L_10 ,
V_34 [ V_9 -> V_35 ] ) ;
F_36 ( V_66 , V_79 , ( T_2 ) - 1 ) ;
V_53 += 0x80 ;
V_53 &= V_80 ;
F_36 ( V_66 , V_79 , V_53 ) ;
V_66 -> V_81 [ 1 ] . V_82 = V_53 ;
}
#endif
}
if ( ! V_71 ) {
F_20 ( V_33 L_11 ,
V_34 [ V_9 -> V_35 ] ) ;
return ( 0 ) ;
}
F_37 ( V_66 , V_79 , & V_53 ) ;
F_37 ( V_66 , V_83 , & V_54 ) ;
F_37 ( V_66 , V_84 , & V_55 ) ;
F_37 ( V_66 , V_85 , & V_56 ) ;
F_37 ( V_66 , V_86 , & V_57 ) ;
if ( ! V_53 || ! V_54 || ! V_55 || ! V_56 || ! V_57 ) {
F_20 ( V_33 L_8
L_12 ,
V_34 [ V_9 -> V_35 ] ) ;
return ( 0 ) ;
}
V_53 &= V_80 ;
V_54 &= V_80 ;
V_55 &= V_80 ;
V_56 &= V_80 ;
V_57 &= V_80 ;
V_9 -> V_72 = V_71 ;
V_9 -> V_87 |= V_88 ;
V_9 -> V_11 . V_12 . V_38 = V_53 ;
switch ( V_9 -> V_35 ) {
case 1 :
V_9 -> V_11 . V_12 . V_13 = V_57 + 0x00 ;
if ( F_28 ( V_53 , 128 ) )
return ( 0 ) ;
if ( F_28 ( V_57 , 64 ) )
return ( 0 ) ;
F_5 ( V_57 , V_57 + 4 ,
V_18 , 0xFF ) ;
F_5 ( V_56 + 0x08 , V_56 + 0x0c ,
V_18 , 0xFF ) ;
F_5 ( V_55 + 0x10 , V_55 + 0x14 ,
V_18 , 0xFF ) ;
F_5 ( V_54 + 0x20 , V_54 + 0x24 ,
V_18 , 0xFF ) ;
break;
case 2 :
V_9 -> V_11 . V_12 . V_13 = V_56 + 0x08 ;
if ( F_28 ( V_56 , 64 ) )
return ( 0 ) ;
break;
case 3 :
V_9 -> V_11 . V_12 . V_13 = V_55 + 0x10 ;
if ( F_28 ( V_55 , 64 ) )
return ( 0 ) ;
break;
case 4 :
V_9 -> V_11 . V_12 . V_13 = V_54 + 0x20 ;
if ( F_28 ( V_54 , 64 ) )
return ( 0 ) ;
break;
}
V_9 -> V_11 . V_12 . V_14 = V_9 -> V_11 . V_12 . V_13 + 4 ;
F_20 ( V_59 L_13
L_14 ,
V_34 [ V_9 -> V_35 ] ,
V_9 -> V_11 . V_12 . V_38 ,
V_9 -> V_11 . V_12 . V_13 ,
V_9 -> V_11 . V_12 . V_14 ,
V_9 -> V_72 ) ;
F_38 ( V_89 , & V_9 -> V_90 ) ;
V_9 -> V_91 = & F_7 ;
V_9 -> V_92 = & F_8 ;
V_9 -> V_93 = & F_9 ;
V_9 -> V_94 = & F_10 ;
V_9 -> V_95 = & F_11 ;
V_9 -> V_96 = & F_12 ;
V_9 -> V_97 = & V_98 ;
V_9 -> V_99 = & F_26 ;
V_9 -> V_100 = & F_14 ;
F_20 ( V_59 L_15 ,
V_34 [ V_9 -> V_35 ] ,
F_1 ( V_9 -> V_11 . V_12 . V_13 , V_9 -> V_11 . V_12 . V_14 , V_101 ) ) ;
return ( 1 ) ;
}
