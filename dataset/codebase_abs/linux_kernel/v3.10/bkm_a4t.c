static inline T_1
F_1 ( unsigned int V_1 , unsigned long V_2 , T_1 V_3 )
{
register T_2 V_4 ;
unsigned int * V_5 = ( unsigned int * ) V_2 ;
* V_5 = ( V_6 | V_7 | V_3 ) ;
F_2 ( V_5 ) ;
* V_5 = ( V_1 | V_8 ) ;
F_2 ( V_5 ) ;
V_4 = * V_5 ;
return ( ( unsigned char ) V_4 ) ;
}
static inline void
F_3 ( unsigned int V_1 , unsigned long V_2 , T_1 V_3 , T_1 * V_9 , int V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
* V_9 ++ = F_1 ( V_1 , V_2 , V_3 ) ;
}
static inline void
F_4 ( unsigned int V_1 , unsigned long V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned int * V_5 = ( unsigned int * ) V_2 ;
* V_5 = ( V_6 | V_7 | V_3 ) ;
F_2 ( V_5 ) ;
* V_5 = ( V_1 | V_7 | V_9 ) ;
F_2 ( V_5 ) ;
}
static inline void
F_5 ( unsigned int V_1 , unsigned long V_2 , T_1 V_3 , T_1 * V_9 , int V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_4 ( V_1 , V_2 , V_3 , * V_9 ++ ) ;
}
static T_1
F_6 ( struct V_12 * V_13 , T_1 V_14 )
{
return ( F_1 ( V_13 -> V_15 . V_16 . V_17 , V_13 -> V_15 . V_16 . V_18 , V_14 ) ) ;
}
static void
F_7 ( struct V_12 * V_13 , T_1 V_14 , T_1 V_19 )
{
F_4 ( V_13 -> V_15 . V_16 . V_17 , V_13 -> V_15 . V_16 . V_18 , V_14 , V_19 ) ;
}
static void
F_8 ( struct V_12 * V_13 , T_1 * V_9 , int V_10 )
{
F_3 ( V_13 -> V_15 . V_16 . V_17 , V_13 -> V_15 . V_16 . V_18 , 0 , V_9 , V_10 ) ;
}
static void
F_9 ( struct V_12 * V_13 , T_1 * V_9 , int V_10 )
{
F_5 ( V_13 -> V_15 . V_16 . V_17 , V_13 -> V_15 . V_16 . V_18 , 0 , V_9 , V_10 ) ;
}
static T_1
F_10 ( struct V_12 * V_13 , int V_20 , T_1 V_14 )
{
return ( F_1 ( V_13 -> V_15 . V_16 . V_21 , V_13 -> V_15 . V_16 . V_22 , V_14 + ( V_20 == - 1 ? 0 : ( V_20 ? 0xC0 : 0x80 ) ) ) ) ;
}
static void
F_11 ( struct V_12 * V_13 , int V_20 , T_1 V_14 , T_1 V_19 )
{
F_4 ( V_13 -> V_15 . V_16 . V_21 , V_13 -> V_15 . V_16 . V_22 , V_14 + ( V_20 == - 1 ? 0 : ( V_20 ? 0xC0 : 0x80 ) ) , V_19 ) ;
}
static T_3
F_12 ( int V_23 , void * V_24 )
{
struct V_12 * V_13 = V_24 ;
T_1 V_25 = 0 ;
T_4 V_26 ;
T_5 * V_27 ;
F_13 ( & V_13 -> V_28 , V_26 ) ;
V_27 = ( T_5 * ) ( V_13 -> V_15 . V_16 . V_29 ) ;
if ( V_27 -> V_30 & V_31 ) {
V_27 -> V_30 = V_31 ;
V_27 -> V_32 &= ~ V_31 ;
V_25 = F_1 ( V_13 -> V_15 . V_16 . V_21 , V_13 -> V_15 . V_16 . V_22 , V_33 + 0x80 ) ;
if ( V_25 ) {
F_14 ( V_13 , V_25 , 0 ) ;
}
V_25 = F_1 ( V_13 -> V_15 . V_16 . V_21 , V_13 -> V_15 . V_16 . V_22 , V_33 + 0xC0 ) ;
if ( V_25 ) {
F_14 ( V_13 , V_25 , 1 ) ;
}
V_25 = F_1 ( V_13 -> V_15 . V_16 . V_17 , V_13 -> V_15 . V_16 . V_18 , V_34 ) ;
if ( V_25 ) {
F_15 ( V_13 , V_25 ) ;
}
V_27 -> V_32 |= V_31 ;
F_16 ( & V_13 -> V_28 , V_26 ) ;
return V_35 ;
} else {
F_16 ( & V_13 -> V_28 , V_26 ) ;
return V_36 ;
}
}
static void
F_17 ( struct V_12 * V_13 )
{
if ( V_13 -> V_15 . V_16 . V_29 ) {
F_18 ( ( void * ) V_13 -> V_15 . V_16 . V_29 ) ;
V_13 -> V_15 . V_16 . V_29 = 0 ;
}
}
static void
F_19 ( struct V_12 * V_13 , unsigned V_37 )
{
if ( V_13 -> V_38 == V_39 ) {
T_5 * V_27 = ( T_5 * ) ( V_13 -> V_15 . V_16 . V_29 ) ;
if ( V_37 )
V_27 -> V_32 |= ( V_31 | V_40 ) ;
else
V_27 -> V_32 &= ~ ( V_31 | V_40 ) ;
}
}
static void
F_20 ( struct V_12 * V_13 )
{
if ( V_13 -> V_38 == V_39 ) {
T_5 * V_27 = ( T_5 * ) ( V_13 -> V_15 . V_16 . V_29 ) ;
V_27 -> V_41 = 0xFF ;
F_21 ( 10 ) ;
V_27 -> V_41 = V_42 | 0xFF ;
F_21 ( 10 ) ;
V_27 -> V_41 = V_42 | V_43 ;
V_27 -> V_44 = V_45 |
V_46 |
V_47 |
V_48 |
V_49 |
V_50 ;
F_21 ( 10 ) ;
V_27 -> V_44 &= ~ ( V_48 |
V_46 |
V_47 ) ;
F_21 ( 10 ) ;
}
}
static int
F_22 ( struct V_12 * V_13 , int V_51 , void * V_52 )
{
T_4 V_26 ;
switch ( V_51 ) {
case V_53 :
F_13 ( & V_13 -> V_28 , V_26 ) ;
F_19 ( V_13 , 0 ) ;
F_20 ( V_13 ) ;
F_16 ( & V_13 -> V_28 , V_26 ) ;
return ( 0 ) ;
case V_54 :
F_13 ( & V_13 -> V_28 , V_26 ) ;
F_19 ( V_13 , 0 ) ;
F_20 ( V_13 ) ;
F_16 ( & V_13 -> V_28 , V_26 ) ;
F_17 ( V_13 ) ;
return ( 0 ) ;
case V_55 :
F_13 ( & V_13 -> V_28 , V_26 ) ;
F_23 ( V_13 ) ;
F_24 ( V_13 ) ;
F_25 ( V_13 ) ;
F_26 ( V_13 ) ;
F_19 ( V_13 , 1 ) ;
F_16 ( & V_13 -> V_28 , V_26 ) ;
return ( 0 ) ;
case V_56 :
return ( 0 ) ;
}
return ( 0 ) ;
}
static int F_27 ( struct V_57 * V_58 , struct V_12 * V_13 ,
T_2 * V_59 , T_2 * V_60 )
{
T_6 V_61 ;
T_6 V_62 ;
V_62 = V_58 -> V_63 ;
V_61 = V_58 -> V_64 ;
if ( ( V_61 == V_65 ) && ( V_62 == V_66 ) ) {
if ( F_28 ( V_58 ) )
return ( 0 ) ;
* V_59 = 1 ;
* V_60 = F_29 ( V_58 , 0 ) ;
V_13 -> V_67 = V_58 -> V_67 ;
return ( 1 ) ;
}
return ( - 1 ) ;
}
static int F_30 ( struct V_68 * V_69 , struct V_12 * V_13 ,
T_2 V_60 )
{
T_5 * V_27 ;
if ( ! V_13 -> V_67 ) {
F_31 ( V_70 L_1 ) ;
return ( 0 ) ;
}
V_13 -> V_15 . V_16 . V_29 = ( long ) F_32 ( V_60 , 4096 ) ;
V_27 = ( T_5 * ) ( V_13 -> V_15 . V_16 . V_29 ) ;
if ( ( V_27 -> V_30 & 0x8EFFFFFF ) != 0 ) {
F_31 ( V_70 L_2
L_3 ,
V_13 -> V_15 . V_16 . V_29 , V_13 -> V_15 . V_16 . V_29 + 4096 ) ;
F_18 ( ( void * ) V_13 -> V_15 . V_16 . V_29 ) ;
V_13 -> V_15 . V_16 . V_29 = 0 ;
return ( 0 ) ;
}
V_13 -> V_15 . V_16 . V_18 = V_13 -> V_15 . V_16 . V_29 + V_71 ;
V_13 -> V_15 . V_16 . V_22 = V_13 -> V_15 . V_16 . V_29 + V_71 ;
V_13 -> V_15 . V_16 . V_17 = V_72 ;
V_13 -> V_15 . V_16 . V_21 = V_73 ;
F_31 ( V_74 L_4
L_5 ,
V_13 -> V_15 . V_16 . V_29 , V_13 -> V_67 ) ;
F_33 ( V_13 ) ;
V_13 -> V_75 = & F_6 ;
V_13 -> V_76 = & F_7 ;
V_13 -> V_77 = & F_8 ;
V_13 -> V_78 = & F_9 ;
V_13 -> V_79 = & F_10 ;
V_13 -> V_80 = & F_11 ;
V_13 -> V_81 = & V_82 ;
V_13 -> V_83 = & F_22 ;
V_13 -> V_84 = & F_12 ;
V_13 -> V_85 |= V_86 ;
F_34 ( V_13 , L_6 ) ;
F_35 ( V_13 , L_6 ) ;
return ( 1 ) ;
}
int F_36 ( struct V_68 * V_69 )
{
struct V_12 * V_13 = V_69 -> V_13 ;
char V_87 [ 64 ] ;
T_2 V_60 = 0 , V_59 = 0 ;
int V_4 ;
strcpy ( V_87 , V_88 ) ;
F_31 ( V_74 L_7 , F_37 ( V_87 ) ) ;
if ( V_13 -> V_38 == V_39 ) {
V_13 -> V_89 = V_90 ;
} else
return ( 0 ) ;
while ( ( V_58 = F_38 ( V_91 ,
V_92 , V_58 ) ) ) {
V_4 = F_27 ( V_58 , V_13 , & V_59 , & V_60 ) ;
if ( ! V_4 )
return ( 0 ) ;
if ( V_4 > 0 )
break;
}
if ( ! V_59 ) {
F_31 ( V_70 L_8 ) ;
return ( 0 ) ;
}
if ( ! V_60 ) {
F_31 ( V_70 L_9
L_10 ) ;
return ( 0 ) ;
}
return F_30 ( V_69 , V_13 , V_60 ) ;
}
