static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 , V_7 = 10 ;
unsigned int V_8 ;
F_3 ( L_1 ) ;
F_4 ( V_5 , V_9 , 0x8d ) ;
F_4 ( V_5 , V_10 , 0x10 ) ;
F_4 ( V_5 , V_11 , 0x1a ) ;
F_5 ( 10 ) ;
F_4 ( V_5 , V_9 , 0x0d ) ;
V_8 = F_6 ( V_5 , V_12 ) ;
V_8 |= V_13 ;
F_4 ( V_5 , V_12 , V_8 ) ;
V_8 &= ~ V_13 ;
F_5 ( 10 ) ;
F_4 ( V_5 , V_12 , V_8 ) ;
F_4 ( V_5 , V_14 , 0x3f ) ;
V_8 = F_6 ( V_5 , V_12 ) ;
V_8 |= V_15 ;
F_4 ( V_5 , V_12 , V_8 ) ;
F_7 () ;
F_5 ( 10 ) ;
V_8 = F_6 ( V_5 , V_16 ) ;
V_8 |= V_17 ;
V_8 &= ~ V_18 ;
F_4 ( V_5 , V_16 , V_8 ) ;
F_4 ( V_5 , V_14 , 0x80 ) ;
V_6 = 1000 ;
while ( -- V_7 > 0 ) {
V_8 = F_6 ( V_5 , V_19 ) ;
if ( V_8 & V_20 )
break;
F_5 ( 1 ) ;
if ( -- V_6 > 0 )
continue;
F_4 ( V_5 , V_9 , 0x8d ) ;
F_5 ( 10 ) ;
F_4 ( V_5 , V_9 , 0x0d ) ;
F_5 ( 350 ) ;
V_6 = 1000 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
unsigned int V_8 ;
F_3 ( L_1 ) ;
V_8 = F_6 ( V_5 , V_12 ) ;
V_8 &= ~ V_15 ;
F_4 ( V_5 , V_12 , V_8 ) ;
V_8 = F_6 ( V_5 , V_16 ) ;
V_8 |= V_13 ;
V_8 &= ~ V_15 ;
F_4 ( V_5 , V_16 , V_8 ) ;
F_7 () ;
}
static const struct V_21 * F_9 ( unsigned long V_22 )
{
int V_23 ;
for ( V_23 = 1 ; V_23 < F_10 ( V_24 ) ; V_23 ++ )
if ( V_22 > V_24 [ V_23 ] . V_22 )
return & V_24 [ V_23 - 1 ] ;
return & V_24 [ V_23 - 1 ] ;
}
static unsigned long F_11 ( struct V_1 * V_2 ,
unsigned long V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_26 ;
}
static long F_12 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long * V_25 )
{
const struct V_21 * V_21 = F_9 ( V_22 ) ;
return V_21 -> V_22 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
const struct V_21 * V_21 = F_9 ( V_22 ) ;
int V_23 ;
F_3 ( L_2 , V_22 ) ;
for ( V_23 = 0 ; V_21 -> V_27 [ V_23 ] . V_28 ; V_23 ++ )
F_4 ( V_5 , V_21 -> V_27 [ V_23 ] . V_28 , V_21 -> V_27 [ V_23 ] . V_8 ) ;
V_4 -> V_26 = V_22 ;
return 0 ;
}
static void F_14 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_15 ( V_30 ) ;
F_16 ( V_4 ) ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_15 ( V_30 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
unsigned int V_8 ;
V_8 = F_6 ( V_5 , V_31 ) ;
if ( V_8 & V_32 ) {
F_4 ( V_5 , V_31 ,
V_8 & ~ V_33 ) ;
} else {
F_4 ( V_5 , V_31 ,
V_8 | V_33 ) ;
}
if ( V_8 & V_34 ) {
F_4 ( V_5 , V_31 ,
V_8 & ~ V_35 ) ;
} else {
F_4 ( V_5 , V_31 ,
V_8 | V_35 ) ;
}
F_18 ( 100 ) ;
if ( V_8 & V_32 ) {
F_4 ( V_5 , V_31 ,
V_8 | V_33 ) ;
} else {
F_4 ( V_5 , V_31 ,
V_8 & ~ V_33 ) ;
}
if ( V_8 & V_34 ) {
F_4 ( V_5 , V_31 ,
V_8 | V_35 ) ;
} else {
F_4 ( V_5 , V_31 ,
V_8 & ~ V_35 ) ;
}
}
static void F_19 ( struct V_29 * V_30 ,
unsigned long int V_36 )
{
struct V_3 * V_4 = F_15 ( V_30 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
F_3 ( L_3 , V_36 ) ;
F_4 ( V_5 , V_14 , 0x00 ) ;
F_4 ( V_5 , V_37 , 0x1b ) ;
F_4 ( V_5 , V_38 , 0xf2 ) ;
F_4 ( V_5 , V_39 , 0x00 ) ;
F_4 ( V_5 , V_40 , 0x00 ) ;
F_4 ( V_5 , V_41 , 0x00 ) ;
F_4 ( V_5 , V_42 , 0x00 ) ;
F_4 ( V_5 , V_43 , 0x00 ) ;
F_4 ( V_5 , V_44 , 0x00 ) ;
F_4 ( V_5 , V_45 , 0x00 ) ;
F_4 ( V_5 , V_46 , 0x00 ) ;
F_4 ( V_5 , V_47 , 0x20 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_15 ( V_30 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
F_3 ( L_1 ) ;
F_4 ( V_5 , V_14 , 0x7f ) ;
}
struct V_29 * F_21 ( struct V_5 * V_5 )
{
struct V_3 * V_4 ;
struct V_29 * V_30 = NULL ;
int V_48 ;
#ifdef F_22
int V_23 ;
for ( V_23 = 0 ; V_23 < ( F_10 ( V_24 ) - 1 ) ; V_23 ++ )
if ( F_23 ( V_24 [ V_23 ] . V_22 < V_24 [ V_23 + 1 ] . V_22 ) )
return F_24 ( - V_49 ) ;
#endif
V_4 = F_25 ( sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 ) {
V_48 = - V_51 ;
goto V_52;
}
V_30 = & V_4 -> V_53 ;
V_30 -> V_54 = & V_55 ;
V_4 -> V_5 = V_5 ;
#ifdef F_22
V_4 -> V_56 . V_57 = & V_58 ;
V_4 -> V_59 = F_26 ( V_5 -> V_60 -> V_60 , & V_4 -> V_56 ) ;
if ( F_27 ( V_4 -> V_59 ) ) {
V_48 = F_28 ( V_4 -> V_59 ) ;
V_4 -> V_59 = NULL ;
goto V_52;
}
#endif
return V_30 ;
V_52:
if ( V_30 )
F_14 ( V_30 ) ;
return F_24 ( V_48 ) ;
}
