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
V_10 = F_11 ( V_12 ) ;
V_10 &= V_13 ;
F_12 ( & V_6 -> V_11 ) ;
return V_10 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_14 ;
V_14 = ( F_9 ( V_6 ) ) ? 1 : 0 ;
return V_14 ;
}
static void F_14 ( struct V_2 * V_3 , unsigned int V_15 ,
int V_16 , int V_17 )
{
register struct V_18 * V_4 = F_3 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_15 == V_19 ) {
V_16 += V_3 -> V_20 ;
V_15 = V_21 ;
}
F_15 ( V_6 , V_15 & 0xff ) ;
if ( V_16 != - 1 || V_17 != - 1 ) {
if ( V_16 != - 1 ) {
if ( V_4 -> V_22 & V_23 &&
! F_16 ( V_15 ) )
V_16 >>= 1 ;
F_17 ( V_6 , V_16 ) ;
F_17 ( V_6 , V_16 >> 8 | V_24 ) ;
}
if ( V_17 != - 1 ) {
F_17 ( V_6 , V_17 ) ;
if ( V_4 -> V_25 > ( 128 << 20 ) ) {
F_17 ( V_6 , V_17 >> 8 ) ;
F_17 ( V_6 , V_17 >> 16 | V_24 ) ;
} else {
F_17 ( V_6 , V_17 >> 8 | V_24 ) ;
}
}
}
switch ( V_15 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return;
case V_33 :
if ( V_4 -> V_34 )
break;
F_18 ( V_4 -> V_35 ) ;
F_15 ( V_6 , V_32 ) ;
F_15 ( V_6 , V_15 ) ;
while ( ! F_9 ( V_6 ) )
;
return;
case V_36 :
F_15 ( V_6 , V_37 ) ;
return;
case V_21 :
F_15 ( V_6 , V_38 ) ;
default:
if ( ! V_4 -> V_34 ) {
F_18 ( V_4 -> V_35 ) ;
return;
}
}
F_19 ( 100 ) ;
while ( ! V_4 -> V_34 ( V_3 ) )
;
}
static void F_20 ( struct V_1 * V_6 )
{
unsigned int V_10 ;
F_10 ( & V_6 -> V_11 ) ;
F_21 ( V_39 , ( V_6 -> V_40 + V_41 ) ) ;
V_10 = F_11 ( V_6 -> V_40 + V_41 ) ;
if ( ! ( V_10 & V_42 ) )
F_21 ( V_10 | V_42 , V_6 -> V_40 + V_41 ) ;
V_10 = F_11 ( V_6 -> V_40 + V_43 ) ;
V_10 &= ~ ( V_44 | V_45 | V_46 | V_47 | V_48 | V_49 ) ;
V_10 |= V_50 ;
F_21 ( V_10 , V_6 -> V_40 + V_43 ) ;
F_12 ( & V_6 -> V_11 ) ;
}
static int F_22 ( struct V_51 * V_52 )
{
struct V_1 * V_1 ;
struct V_18 * V_4 ;
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
V_4 -> V_34 = F_13 ;
V_4 -> V_62 = F_4 ;
V_4 -> V_63 = F_7 ;
V_4 -> V_64 = F_6 ;
V_4 -> V_35 = 50 ;
V_4 -> V_22 = 0 ;
V_4 -> V_65 . V_66 = V_67 ;
V_54 = F_29 ( V_52 , V_68 , 0 ) ;
V_1 -> V_40 = F_30 ( & V_52 -> V_55 , V_54 ) ;
if ( F_27 ( V_1 -> V_40 ) )
return F_31 ( V_1 -> V_40 ) ;
F_20 ( V_1 ) ;
if ( F_32 ( V_3 , 1 ) )
return - V_69 ;
F_33 ( V_3 , V_70 , F_34 ( V_70 ) ) ;
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
