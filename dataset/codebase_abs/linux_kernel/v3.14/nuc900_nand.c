static unsigned char F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_3 = ( unsigned char ) F_3 ( V_5 ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned char * V_6 , int V_7 )
{
int V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_6 [ V_8 ] = ( unsigned char ) F_3 ( V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
const unsigned char * V_6 , int V_7 )
{
int V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_6 ( V_5 , V_6 [ V_8 ] ) ;
}
static int F_7 ( struct V_4 * V_5 )
{
unsigned int V_9 ;
F_8 ( & V_5 -> V_10 ) ;
V_9 = F_9 ( V_11 ) ;
V_9 &= V_12 ;
F_10 ( & V_5 -> V_10 ) ;
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_13 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_13 = ( F_7 ( V_5 ) ) ? 1 : 0 ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_14 ,
int V_15 , int V_16 )
{
register struct V_17 * V_18 = V_2 -> V_19 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_14 == V_20 ) {
V_15 += V_2 -> V_21 ;
V_14 = V_22 ;
}
F_13 ( V_5 , V_14 & 0xff ) ;
if ( V_15 != - 1 || V_16 != - 1 ) {
if ( V_15 != - 1 ) {
if ( V_18 -> V_23 & V_24 )
V_15 >>= 1 ;
F_14 ( V_5 , V_15 ) ;
F_14 ( V_5 , V_15 >> 8 | V_25 ) ;
}
if ( V_16 != - 1 ) {
F_14 ( V_5 , V_16 ) ;
if ( V_18 -> V_26 > ( 128 << 20 ) ) {
F_14 ( V_5 , V_16 >> 8 ) ;
F_14 ( V_5 , V_16 >> 16 | V_25 ) ;
} else {
F_14 ( V_5 , V_16 >> 8 | V_25 ) ;
}
}
}
switch ( V_14 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
return;
case V_34 :
if ( V_18 -> V_35 )
break;
F_15 ( V_18 -> V_36 ) ;
F_13 ( V_5 , V_33 ) ;
F_13 ( V_5 , V_14 ) ;
while ( ! F_7 ( V_5 ) )
;
return;
case V_37 :
F_13 ( V_5 , V_38 ) ;
return;
case V_22 :
F_13 ( V_5 , V_39 ) ;
default:
if ( ! V_18 -> V_35 ) {
F_15 ( V_18 -> V_36 ) ;
return;
}
}
F_16 ( 100 ) ;
while ( ! V_18 -> V_35 ( V_2 ) )
;
}
static void F_17 ( struct V_4 * V_5 )
{
unsigned int V_9 ;
F_8 ( & V_5 -> V_10 ) ;
F_18 ( V_40 , ( V_5 -> V_41 + V_42 ) ) ;
V_9 = F_9 ( V_5 -> V_41 + V_42 ) ;
if ( ! ( V_9 & V_43 ) )
F_18 ( V_9 | V_43 , V_42 ) ;
V_9 = F_9 ( V_5 -> V_41 + V_44 ) ;
V_9 &= ~ ( V_45 | V_46 | V_47 | V_48 | V_49 | V_50 ) ;
V_9 |= V_51 ;
F_18 ( V_9 , V_5 -> V_41 + V_44 ) ;
F_10 ( & V_5 -> V_10 ) ;
}
static int F_19 ( struct V_52 * V_53 )
{
struct V_4 * V_4 ;
struct V_17 * V_18 ;
struct V_54 * V_55 ;
V_4 = F_20 ( & V_53 -> V_56 , sizeof( struct V_4 ) ,
V_57 ) ;
if ( ! V_4 )
return - V_58 ;
V_18 = & ( V_4 -> V_18 ) ;
V_4 -> V_2 . V_19 = V_18 ;
V_4 -> V_2 . V_59 = V_60 ;
F_21 ( & V_4 -> V_10 ) ;
V_4 -> V_61 = F_22 ( & V_53 -> V_56 , NULL ) ;
if ( F_23 ( V_4 -> V_61 ) )
return - V_62 ;
F_24 ( V_4 -> V_61 ) ;
V_18 -> V_63 = F_12 ;
V_18 -> V_35 = F_11 ;
V_18 -> V_64 = F_1 ;
V_18 -> V_65 = F_5 ;
V_18 -> V_66 = F_4 ;
V_18 -> V_36 = 50 ;
V_18 -> V_23 = 0 ;
V_18 -> V_67 . V_68 = V_69 ;
V_55 = F_25 ( V_53 , V_70 , 0 ) ;
V_4 -> V_41 = F_26 ( & V_53 -> V_56 , V_55 ) ;
if ( F_23 ( V_4 -> V_41 ) )
return F_27 ( V_4 -> V_41 ) ;
F_17 ( V_4 ) ;
if ( F_28 ( & ( V_4 -> V_2 ) , 1 ) )
return - V_71 ;
F_29 ( & ( V_4 -> V_2 ) , V_72 ,
F_30 ( V_72 ) ) ;
F_31 ( V_53 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_52 * V_53 )
{
struct V_4 * V_4 = F_33 ( V_53 ) ;
F_34 ( & V_4 -> V_2 ) ;
F_35 ( V_4 -> V_61 ) ;
return 0 ;
}
