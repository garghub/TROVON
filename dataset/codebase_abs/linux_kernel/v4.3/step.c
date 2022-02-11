unsigned long F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 , V_6 ;
V_5 = V_4 -> V_7 ;
V_6 = V_4 -> V_8 & 0xffff ;
if ( F_2 ( V_4 ) ) {
V_5 = ( V_5 & 0xffff ) + ( V_6 << 4 ) ;
return V_5 ;
}
#ifdef F_3
if ( ( V_6 & V_9 ) == V_10 ) {
struct V_11 * V_12 ;
unsigned long V_13 ;
V_6 >>= 3 ;
F_4 ( & V_2 -> V_14 -> V_15 . V_16 ) ;
if ( F_5 ( ! V_2 -> V_14 -> V_15 . V_17 ||
V_6 >= V_2 -> V_14 -> V_15 . V_17 -> V_18 ) )
V_5 = - 1L ;
else {
V_12 = & V_2 -> V_14 -> V_15 . V_17 -> V_19 [ V_6 ] ;
V_13 = F_6 ( V_12 ) ;
if ( ! V_12 -> V_20 )
V_5 &= 0xffff ;
V_5 += V_13 ;
}
F_7 ( & V_2 -> V_14 -> V_15 . V_16 ) ;
}
#endif
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_21 , V_22 ;
unsigned char V_23 [ 15 ] ;
unsigned long V_5 = F_1 ( V_2 , V_4 ) ;
V_22 = F_9 ( V_2 , V_5 , V_23 , sizeof( V_23 ) , 0 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
switch ( V_23 [ V_21 ] ) {
case 0x9d : case 0xcf :
return 1 ;
case 0x66 : case 0x67 :
continue;
case 0x26 : case 0x2e :
case 0x36 : case 0x3e :
case 0x64 : case 0x65 :
case 0xf0 : case 0xf2 : case 0xf3 :
continue;
#ifdef F_10
case 0x40 ... 0x4f :
if ( ! F_11 ( V_4 ) )
return 0 ;
continue;
#endif
case 0x9c :
default:
return 0 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_13 ( V_2 ) ;
unsigned long V_24 ;
if ( F_5 ( F_14 ( V_2 , V_25 ) ) )
V_4 -> V_26 |= V_27 ;
F_15 ( V_2 , V_25 ) ;
V_24 = V_4 -> V_26 ;
V_4 -> V_26 |= V_27 ;
if ( F_8 ( V_2 , V_4 ) ) {
F_16 ( V_2 , V_28 ) ;
return 0 ;
}
if ( V_24 & V_27 )
return F_14 ( V_2 , V_28 ) ;
F_15 ( V_2 , V_28 ) ;
return 1 ;
}
void F_17 ( struct V_1 * V_29 , bool V_30 )
{
unsigned long V_31 ;
F_18 () ;
V_31 = F_19 () ;
if ( V_30 ) {
V_31 |= V_32 ;
F_15 ( V_29 , V_33 ) ;
} else {
V_31 &= ~ V_32 ;
F_16 ( V_29 , V_33 ) ;
}
if ( V_29 == V_34 )
F_20 ( V_31 ) ;
F_21 () ;
}
static void F_22 ( struct V_1 * V_2 , bool V_35 )
{
if ( F_12 ( V_2 ) && V_35 )
F_17 ( V_2 , true ) ;
else if ( F_14 ( V_2 , V_33 ) )
F_17 ( V_2 , false ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 , 0 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_22 ( V_2 , 1 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( F_14 ( V_2 , V_33 ) )
F_17 ( V_2 , false ) ;
F_16 ( V_2 , V_25 ) ;
if ( F_26 ( V_2 , V_28 ) )
F_13 ( V_2 ) -> V_26 &= ~ V_27 ;
}
