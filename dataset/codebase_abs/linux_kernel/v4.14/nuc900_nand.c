static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static unsigned char F_4 ( struct V_2 * V_3 )
{
unsigned char V_5 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_5 = ( unsigned char ) F_5 ( V_6 ) ;
return V_5 ;
}
static void F_6 ( struct V_2 * V_3 ,
unsigned char * V_7 , int V_8 )
{
int V_9 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_7 [ V_9 ] = ( unsigned char ) F_5 ( V_6 ) ;
}
static void F_7 ( struct V_2 * V_3 ,
const unsigned char * V_7 , int V_8 )
{
int V_9 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_8 ( V_6 , V_7 [ V_9 ] ) ;
}
static int F_9 ( struct V_1 * V_6 )
{
unsigned int V_10 ;
F_10 ( & V_6 -> V_11 ) ;
V_10 = F_11 ( V_6 -> V_12 + V_13 ) ;
V_10 &= V_14 ;
F_12 ( & V_6 -> V_11 ) ;
return V_10 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_15 ;
V_15 = ( F_9 ( V_6 ) ) ? 1 : 0 ;
return V_15 ;
}
static void F_14 ( struct V_2 * V_3 , unsigned int V_16 ,
int V_17 , int V_18 )
{
register struct V_19 * V_4 = F_3 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_16 == V_20 ) {
V_17 += V_3 -> V_21 ;
V_16 = V_22 ;
}
F_15 ( V_6 , V_16 & 0xff ) ;
if ( V_17 != - 1 || V_18 != - 1 ) {
if ( V_17 != - 1 ) {
if ( V_4 -> V_23 & V_24 &&
! F_16 ( V_16 ) )
V_17 >>= 1 ;
F_17 ( V_6 , V_17 ) ;
F_17 ( V_6 , V_17 >> 8 | V_25 ) ;
}
if ( V_18 != - 1 ) {
F_17 ( V_6 , V_18 ) ;
if ( V_4 -> V_26 > ( 128 << 20 ) ) {
F_17 ( V_6 , V_18 >> 8 ) ;
F_17 ( V_6 , V_18 >> 16 | V_25 ) ;
} else {
F_17 ( V_6 , V_18 >> 8 | V_25 ) ;
}
}
}
switch ( V_16 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
return;
case V_34 :
if ( V_4 -> V_35 )
break;
F_18 ( V_4 -> V_36 ) ;
F_15 ( V_6 , V_33 ) ;
F_15 ( V_6 , V_16 ) ;
while ( ! F_9 ( V_6 ) )
;
return;
case V_37 :
F_15 ( V_6 , V_38 ) ;
return;
case V_22 :
F_15 ( V_6 , V_39 ) ;
default:
if ( ! V_4 -> V_35 ) {
F_18 ( V_4 -> V_36 ) ;
return;
}
}
F_19 ( 100 ) ;
while ( ! V_4 -> V_35 ( V_3 ) )
;
}
static void F_20 ( struct V_1 * V_6 )
{
unsigned int V_10 ;
F_10 ( & V_6 -> V_11 ) ;
F_21 ( V_40 , ( V_6 -> V_12 + V_41 ) ) ;
V_10 = F_11 ( V_6 -> V_12 + V_41 ) ;
if ( ! ( V_10 & V_42 ) )
F_21 ( V_10 | V_42 , V_6 -> V_12 + V_41 ) ;
V_10 = F_11 ( V_6 -> V_12 + V_43 ) ;
V_10 &= ~ ( V_44 | V_45 | V_46 | V_47 | V_48 | V_49 ) ;
V_10 |= V_50 ;
F_21 ( V_10 , V_6 -> V_12 + V_43 ) ;
F_12 ( & V_6 -> V_11 ) ;
}
static int F_22 ( struct V_51 * V_52 )
{
struct V_1 * V_1 ;
struct V_19 * V_4 ;
struct V_2 * V_3 ;
struct V_53 * V_54 ;
V_1 = F_23 ( & V_52 -> V_55 , sizeof( struct V_1 ) ,
V_56 ) ;
if ( ! V_1 )
return - V_57 ;
V_4 = & ( V_1 -> V_4 ) ;
V_3 = F_24 ( V_4 ) ;
V_3 -> V_55 . V_58 = & V_52 -> V_55 ;
F_25 ( & V_1 -> V_11 ) ;
V_1 -> V_59 = F_26 ( & V_52 -> V_55 , NULL ) ;
if ( F_27 ( V_1 -> V_59 ) )
return - V_60 ;
F_28 ( V_1 -> V_59 ) ;
V_4 -> V_61 = F_14 ;
V_4 -> V_35 = F_13 ;
V_4 -> V_62 = F_4 ;
V_4 -> V_63 = F_7 ;
V_4 -> V_64 = F_6 ;
V_4 -> V_36 = 50 ;
V_4 -> V_23 = 0 ;
V_4 -> V_65 . V_66 = V_67 ;
V_4 -> V_65 . V_68 = V_69 ;
V_54 = F_29 ( V_52 , V_70 , 0 ) ;
V_1 -> V_12 = F_30 ( & V_52 -> V_55 , V_54 ) ;
if ( F_27 ( V_1 -> V_12 ) )
return F_31 ( V_1 -> V_12 ) ;
F_20 ( V_1 ) ;
if ( F_32 ( V_3 , 1 ) )
return - V_71 ;
F_33 ( V_3 , V_72 , F_34 ( V_72 ) ) ;
F_35 ( V_52 , V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_37 ( V_52 ) ;
F_38 ( F_24 ( & V_1 -> V_4 ) ) ;
F_39 ( V_1 -> V_59 ) ;
return 0 ;
}
