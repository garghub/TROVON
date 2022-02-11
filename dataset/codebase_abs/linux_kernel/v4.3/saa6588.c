static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static bool F_3 ( struct V_1 * V_4 , unsigned char * V_5 )
{
int V_6 ;
if ( V_4 -> V_7 == V_4 -> V_8 ) {
if ( V_9 > 2 )
F_4 ( V_10 L_1 ) ;
return false ;
}
if ( V_9 > 2 ) {
F_4 ( V_10 L_2 ) ;
for ( V_6 = V_4 -> V_7 ; V_6 < V_4 -> V_7 + 3 ; V_6 ++ )
F_4 ( L_3 , V_4 -> V_11 [ V_6 ] ) ;
}
memcpy ( V_5 , & V_4 -> V_11 [ V_4 -> V_7 ] , 3 ) ;
V_4 -> V_7 += 3 ;
if ( V_4 -> V_7 >= V_4 -> V_12 )
V_4 -> V_7 = 0 ;
V_4 -> V_13 -- ;
if ( V_9 > 2 )
F_4 ( L_4 , V_4 -> V_13 ) ;
return true ;
}
static void F_5 ( struct V_1 * V_4 , struct V_14 * V_15 )
{
unsigned char T_1 * V_16 = V_15 -> V_11 ;
unsigned char V_5 [ 3 ] ;
unsigned long V_17 ;
unsigned int V_18 ;
unsigned int V_6 ;
V_15 -> V_19 = 0 ;
if ( ! V_15 -> V_11 )
return;
while ( ! V_15 -> V_20 && ! V_4 -> V_21 ) {
int V_22 = F_6 ( V_4 -> V_23 ,
V_4 -> V_21 ) ;
if ( V_22 == - V_24 ) {
V_15 -> V_19 = - V_25 ;
return;
}
}
V_18 = V_15 -> V_13 ;
F_7 ( & V_4 -> V_26 , V_17 ) ;
if ( V_18 > V_4 -> V_13 )
V_18 = V_4 -> V_13 ;
F_8 ( & V_4 -> V_26 , V_17 ) ;
if ( ! V_18 )
return;
for ( V_6 = 0 ; V_6 < V_18 ; V_6 ++ ) {
bool V_27 ;
F_7 ( & V_4 -> V_26 , V_17 ) ;
V_27 = F_3 ( V_4 , V_5 ) ;
F_8 ( & V_4 -> V_26 , V_17 ) ;
if ( ! V_27 )
break;
if ( F_9 ( V_16 , V_5 , 3 ) ) {
V_15 -> V_19 = - V_28 ;
return;
}
V_16 += 3 ;
V_15 -> V_19 += 3 ;
}
F_7 ( & V_4 -> V_26 , V_17 ) ;
V_4 -> V_21 = ( V_4 -> V_13 > 0 ) ;
F_8 ( & V_4 -> V_26 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_4 , unsigned char * V_29 )
{
unsigned int V_6 ;
if ( V_9 > 3 )
F_4 ( V_10 L_5 ) ;
for ( V_6 = 0 ; V_6 < 3 ; ++ V_6 ) {
if ( V_9 > 3 )
F_4 ( L_3 , V_29 [ V_6 ] ) ;
V_4 -> V_11 [ V_4 -> V_8 ] = V_29 [ V_6 ] ;
V_4 -> V_8 ++ ;
}
if ( V_4 -> V_8 >= V_4 -> V_12 )
V_4 -> V_8 = 0 ;
if ( V_4 -> V_8 == V_4 -> V_7 ) {
V_4 -> V_7 += 3 ;
if ( V_4 -> V_7 >= V_4 -> V_12 )
V_4 -> V_7 = 0 ;
} else
V_4 -> V_13 ++ ;
if ( V_9 > 3 )
F_4 ( L_4 , V_4 -> V_13 ) ;
}
static void F_11 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_12 ( & V_4 -> V_3 ) ;
unsigned long V_17 ;
unsigned char V_32 [ 6 ] ;
unsigned char V_33 ;
unsigned char V_34 ;
if ( 6 != F_13 ( V_31 , & V_32 [ 0 ] , 6 ) ) {
if ( V_9 > 1 )
F_4 ( V_10 L_6 ) ;
return;
}
V_4 -> V_35 = V_32 [ 0 ] & 0x10 ;
if ( ! V_4 -> V_35 )
return;
V_33 = V_32 [ 0 ] >> 5 ;
if ( V_33 == V_4 -> V_36 ) {
if ( V_9 > 3 )
F_4 ( L_7 , V_33 ) ;
return;
}
V_4 -> V_36 = V_33 ;
F_14 ( V_32 [ 2 ] , V_32 [ 0 ] ) ;
if ( V_33 == 6 )
V_33 = V_37 ;
else if ( ! V_38 && V_33 == 5 )
V_33 = V_37 ;
V_34 = V_33 ;
V_34 |= V_33 << 3 ;
if ( ( V_32 [ 2 ] & 0x03 ) == 0x03 )
V_34 |= V_39 ;
else if ( ( V_32 [ 2 ] & 0x03 ) != 0x00 )
V_34 |= V_40 ;
V_32 [ 2 ] = V_34 ;
F_7 ( & V_4 -> V_26 , V_17 ) ;
F_10 ( V_4 , V_32 ) ;
F_8 ( & V_4 -> V_26 , V_17 ) ;
V_4 -> V_21 = 1 ;
F_15 ( & V_4 -> V_23 ) ;
}
static void F_16 ( struct V_41 * V_42 )
{
struct V_1 * V_4 = F_2 ( V_42 , struct V_1 , V_42 . V_42 ) ;
F_11 ( V_4 ) ;
F_17 ( & V_4 -> V_42 , F_18 ( 20 ) ) ;
}
static void F_19 ( struct V_1 * V_4 )
{
struct V_30 * V_31 = F_12 ( & V_4 -> V_3 ) ;
unsigned char V_5 [ 3 ] ;
int V_43 ;
V_5 [ 0 ] = V_44 ;
if ( V_38 )
V_5 [ 0 ] |= V_45 ;
V_5 [ 1 ] = V_46 ;
switch ( V_47 ) {
case 0 :
V_5 [ 1 ] |= V_48 ;
break;
case 1 :
V_5 [ 1 ] |= V_49 ;
break;
case 2 :
V_5 [ 1 ] |= V_50 ;
break;
case 3 :
V_5 [ 1 ] |= V_51 ;
break;
default:
break;
}
V_5 [ 2 ] = V_52 | V_53 ;
switch ( V_54 ) {
case 0 :
V_5 [ 2 ] |= V_55 ;
break;
case 1 :
V_5 [ 2 ] |= V_56 ;
break;
case 2 :
V_5 [ 2 ] |= V_57 ;
break;
case 3 :
V_5 [ 2 ] |= V_58 ;
break;
default:
break;
}
F_4 ( V_10 L_8 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ) ;
V_43 = F_20 ( V_31 , V_5 , 3 ) ;
if ( V_43 != 3 )
F_21 ( V_10 L_9 , V_43 ) ;
}
static long F_22 ( struct V_2 * V_3 , unsigned int V_59 , void * V_60 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_60 ;
switch ( V_59 ) {
case V_61 :
V_4 -> V_21 = 1 ;
F_15 ( & V_4 -> V_23 ) ;
V_4 -> V_21 = 0 ;
V_15 -> V_19 = 0 ;
break;
case V_62 :
F_5 ( V_4 , V_15 ) ;
break;
case V_63 :
V_15 -> V_19 = 0 ;
if ( V_4 -> V_21 )
V_15 -> V_19 |= V_64 | V_65 ;
F_23 ( V_15 -> V_66 , & V_4 -> V_23 , V_15 -> V_67 ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_70 -> V_71 |= V_72 | V_73 ;
if ( V_4 -> V_35 )
V_70 -> V_74 |= V_75 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , const struct V_69 * V_70 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_30 * V_31 ,
const struct V_76 * V_77 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
F_27 ( V_31 , L_10 ,
V_31 -> V_78 << 1 , V_31 -> V_79 -> V_80 ) ;
V_4 = F_28 ( & V_31 -> V_81 , sizeof( * V_4 ) , V_82 ) ;
if ( V_4 == NULL )
return - V_83 ;
V_4 -> V_12 = V_84 * 3 ;
V_4 -> V_11 = F_28 ( & V_31 -> V_81 , V_4 -> V_12 , V_82 ) ;
if ( V_4 -> V_11 == NULL )
return - V_83 ;
V_3 = & V_4 -> V_3 ;
F_29 ( V_3 , V_31 , & V_85 ) ;
F_30 ( & V_4 -> V_26 ) ;
V_4 -> V_13 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_36 = 0xff ;
F_31 ( & V_4 -> V_23 ) ;
V_4 -> V_21 = 0 ;
F_19 ( V_4 ) ;
F_32 ( & V_4 -> V_42 , F_16 ) ;
F_17 ( & V_4 -> V_42 , 0 ) ;
return 0 ;
}
static int F_33 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_34 ( V_31 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_35 ( V_3 ) ;
F_36 ( & V_4 -> V_42 ) ;
return 0 ;
}
