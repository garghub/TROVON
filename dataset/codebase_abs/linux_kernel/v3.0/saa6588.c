static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , unsigned char T_1 * V_5 )
{
int V_6 ;
if ( V_4 -> V_7 == V_4 -> V_8 ) {
if ( V_9 > 2 )
F_4 ( V_10 L_1 ) ;
return 0 ;
}
if ( V_9 > 2 ) {
F_4 ( V_10 L_2 ) ;
for ( V_6 = V_4 -> V_7 ; V_6 < V_4 -> V_7 + 3 ; V_6 ++ )
F_4 ( L_3 , V_4 -> V_11 [ V_6 ] ) ;
}
if ( F_5 ( V_5 , & V_4 -> V_11 [ V_4 -> V_7 ] , 3 ) )
return - V_12 ;
V_4 -> V_7 += 3 ;
if ( V_4 -> V_7 >= V_4 -> V_13 )
V_4 -> V_7 = 0 ;
V_4 -> V_14 -- ;
if ( V_9 > 2 )
F_4 ( L_4 , V_4 -> V_14 ) ;
return 1 ;
}
static void F_6 ( struct V_1 * V_4 , struct V_15 * V_16 )
{
unsigned long V_17 ;
unsigned char T_1 * V_18 = V_16 -> V_11 ;
unsigned int V_6 ;
unsigned int V_19 ;
V_16 -> V_20 = 0 ;
if ( ! V_16 -> V_11 )
return;
while ( ! V_4 -> V_21 ) {
int V_22 = F_7 ( V_4 -> V_23 ,
V_4 -> V_21 ) ;
if ( V_22 == - V_24 ) {
V_16 -> V_20 = - V_25 ;
return;
}
}
F_8 ( & V_4 -> V_26 , V_17 ) ;
V_19 = V_16 -> V_14 ;
if ( V_19 > V_4 -> V_14 )
V_19 = V_4 -> V_14 ;
if ( ! V_19 ) {
F_9 ( & V_4 -> V_26 , V_17 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
if ( F_3 ( V_4 , V_18 ) ) {
V_18 += 3 ;
V_16 -> V_20 ++ ;
} else
break;
}
V_16 -> V_20 *= 3 ;
V_4 -> V_21 = ( V_4 -> V_14 > 0 ) ;
F_9 ( & V_4 -> V_26 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_4 , unsigned char * V_27 )
{
unsigned int V_6 ;
if ( V_9 > 3 )
F_4 ( V_10 L_5 ) ;
for ( V_6 = 0 ; V_6 < 3 ; ++ V_6 ) {
if ( V_9 > 3 )
F_4 ( L_3 , V_27 [ V_6 ] ) ;
V_4 -> V_11 [ V_4 -> V_8 ] = V_27 [ V_6 ] ;
V_4 -> V_8 ++ ;
}
if ( V_4 -> V_8 >= V_4 -> V_13 )
V_4 -> V_8 = 0 ;
if ( V_4 -> V_8 == V_4 -> V_7 ) {
V_4 -> V_7 += 3 ;
if ( V_4 -> V_7 >= V_4 -> V_13 )
V_4 -> V_7 = 0 ;
} else
V_4 -> V_14 ++ ;
if ( V_9 > 3 )
F_4 ( L_4 , V_4 -> V_14 ) ;
}
static void F_11 ( struct V_1 * V_4 )
{
struct V_28 * V_29 = F_12 ( & V_4 -> V_3 ) ;
unsigned long V_17 ;
unsigned char V_30 [ 6 ] ;
unsigned char V_31 ;
unsigned char V_32 ;
if ( 6 != F_13 ( V_29 , & V_30 [ 0 ] , 6 ) ) {
if ( V_9 > 1 )
F_4 ( V_10 L_6 ) ;
return;
}
V_4 -> V_33 = V_30 [ 0 ] & 0x10 ;
if ( ! V_4 -> V_33 )
return;
V_31 = V_30 [ 0 ] >> 5 ;
if ( V_31 == V_4 -> V_34 ) {
if ( V_9 > 3 )
F_4 ( L_7 , V_31 ) ;
return;
}
V_4 -> V_34 = V_31 ;
V_32 = V_30 [ 2 ] ;
V_30 [ 2 ] = V_30 [ 0 ] ;
V_30 [ 0 ] = V_32 ;
if ( V_31 == 6 )
V_31 = V_35 ;
else if ( ! V_36 && V_31 == 5 )
V_31 = V_35 ;
V_32 = V_31 ;
V_32 |= V_31 << 3 ;
if ( ( V_30 [ 2 ] & 0x03 ) == 0x03 )
V_32 |= V_37 ;
else if ( ( V_30 [ 2 ] & 0x03 ) != 0x00 )
V_32 |= V_38 ;
V_30 [ 2 ] = V_32 ;
F_8 ( & V_4 -> V_26 , V_17 ) ;
F_10 ( V_4 , V_30 ) ;
F_9 ( & V_4 -> V_26 , V_17 ) ;
V_4 -> V_21 = 1 ;
F_14 ( & V_4 -> V_23 ) ;
}
static void F_15 ( struct V_39 * V_40 )
{
struct V_1 * V_4 = F_2 ( V_40 , struct V_1 , V_40 . V_40 ) ;
F_11 ( V_4 ) ;
F_16 ( & V_4 -> V_40 , F_17 ( 20 ) ) ;
}
static void F_18 ( struct V_1 * V_4 )
{
struct V_28 * V_29 = F_12 ( & V_4 -> V_3 ) ;
unsigned char V_41 [ 3 ] ;
int V_42 ;
V_41 [ 0 ] = V_43 ;
if ( V_36 )
V_41 [ 0 ] |= V_44 ;
V_41 [ 1 ] = V_45 ;
switch ( V_46 ) {
case 0 :
V_41 [ 1 ] |= V_47 ;
break;
case 1 :
V_41 [ 1 ] |= V_48 ;
break;
case 2 :
V_41 [ 1 ] |= V_49 ;
break;
case 3 :
V_41 [ 1 ] |= V_50 ;
break;
default:
break;
}
V_41 [ 2 ] = V_51 | V_52 ;
switch ( V_53 ) {
case 0 :
V_41 [ 2 ] |= V_54 ;
break;
case 1 :
V_41 [ 2 ] |= V_55 ;
break;
case 2 :
V_41 [ 2 ] |= V_56 ;
break;
case 3 :
V_41 [ 2 ] |= V_57 ;
break;
default:
break;
}
F_4 ( V_10 L_8 ,
V_41 [ 0 ] , V_41 [ 1 ] , V_41 [ 2 ] ) ;
V_42 = F_19 ( V_29 , V_41 , 3 ) ;
if ( V_42 != 3 )
F_20 ( V_10 L_9 , V_42 ) ;
}
static long F_21 ( struct V_2 * V_3 , unsigned int V_58 , void * V_59 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_59 ;
switch ( V_58 ) {
case V_60 :
V_16 -> V_20 = 0 ;
break;
case V_61 :
V_4 -> V_21 = 1 ;
F_14 ( & V_4 -> V_23 ) ;
V_16 -> V_20 = 0 ;
break;
case V_62 :
F_6 ( V_4 , V_16 ) ;
break;
case V_63 :
V_16 -> V_20 = 0 ;
if ( V_4 -> V_21 ) {
V_16 -> V_20 |= V_64 | V_65 ;
}
F_22 ( V_16 -> V_66 , & V_4 -> V_23 , V_16 -> V_67 ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_70 -> V_71 |= V_72 | V_73 ;
if ( V_4 -> V_33 )
V_70 -> V_74 |= V_75 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_76 * V_77 )
{
struct V_28 * V_29 = F_12 ( V_3 ) ;
return F_26 ( V_29 , V_77 , V_78 , 0 ) ;
}
static int F_27 ( struct V_28 * V_29 ,
const struct V_79 * V_80 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
F_28 ( V_29 , L_10 ,
V_29 -> V_81 << 1 , V_29 -> V_82 -> V_83 ) ;
V_4 = F_29 ( sizeof( * V_4 ) , V_84 ) ;
if ( V_4 == NULL )
return - V_85 ;
V_4 -> V_13 = V_86 * 3 ;
V_4 -> V_11 = F_30 ( V_4 -> V_13 , V_84 ) ;
if ( V_4 -> V_11 == NULL ) {
F_31 ( V_4 ) ;
return - V_85 ;
}
V_3 = & V_4 -> V_3 ;
F_32 ( V_3 , V_29 , & V_87 ) ;
F_33 ( & V_4 -> V_26 ) ;
V_4 -> V_14 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_34 = 0xff ;
F_34 ( & V_4 -> V_23 ) ;
V_4 -> V_21 = 0 ;
F_18 ( V_4 ) ;
F_35 ( & V_4 -> V_40 , F_15 ) ;
F_16 ( & V_4 -> V_40 , 0 ) ;
return 0 ;
}
static int F_36 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_37 ( V_29 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_38 ( V_3 ) ;
F_39 ( & V_4 -> V_40 ) ;
F_31 ( V_4 -> V_11 ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static T_2 int F_40 ( void )
{
return F_41 ( & V_88 ) ;
}
static T_3 void F_42 ( void )
{
F_43 ( & V_88 ) ;
}
