unsigned long F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 , V_6 ;
V_5 = V_4 -> V_7 ;
V_6 = V_4 -> V_8 & 0xffff ;
if ( F_2 ( V_4 ) ) {
V_5 = ( V_5 & 0xffff ) + ( V_6 << 4 ) ;
return V_5 ;
}
if ( ( V_6 & V_9 ) == V_10 ) {
struct V_11 * V_12 ;
unsigned long V_13 ;
V_6 &= ~ 7UL ;
F_3 ( & V_2 -> V_14 -> V_15 . V_16 ) ;
if ( F_4 ( ( V_6 >> 3 ) >= V_2 -> V_14 -> V_15 . V_17 ) )
V_5 = - 1L ;
else {
V_12 = V_2 -> V_14 -> V_15 . V_18 + V_6 ;
V_13 = F_5 ( V_12 ) ;
if ( ! V_12 -> V_19 )
V_5 &= 0xffff ;
V_5 += V_13 ;
}
F_6 ( & V_2 -> V_14 -> V_15 . V_16 ) ;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_20 , V_21 ;
unsigned char V_22 [ 15 ] ;
unsigned long V_5 = F_1 ( V_2 , V_4 ) ;
V_21 = F_8 ( V_2 , V_5 , V_22 , sizeof( V_22 ) , 0 ) ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
switch ( V_22 [ V_20 ] ) {
case 0x9d : case 0xcf :
return 1 ;
case 0x66 : case 0x67 :
continue;
case 0x26 : case 0x2e :
case 0x36 : case 0x3e :
case 0x64 : case 0x65 :
case 0xf0 : case 0xf2 : case 0xf3 :
continue;
#ifdef F_9
case 0x40 ... 0x4f :
if ( ! F_10 ( V_4 ) )
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
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_12 ( V_2 ) ;
unsigned long V_23 ;
if ( F_4 ( F_13 ( V_2 , V_24 ) ) )
V_4 -> V_25 |= V_26 ;
F_14 ( V_2 , V_24 ) ;
V_23 = V_4 -> V_25 ;
V_4 -> V_25 |= V_26 ;
if ( F_7 ( V_2 , V_4 ) ) {
F_15 ( V_2 , V_27 ) ;
return 0 ;
}
if ( V_23 & V_26 )
return F_13 ( V_2 , V_27 ) ;
F_14 ( V_2 , V_27 ) ;
return 1 ;
}
void F_16 ( struct V_1 * V_28 , bool V_29 )
{
unsigned long V_30 ;
F_17 () ;
V_30 = F_18 () ;
if ( V_29 ) {
V_30 |= V_31 ;
F_14 ( V_28 , V_32 ) ;
} else {
V_30 &= ~ V_31 ;
F_15 ( V_28 , V_32 ) ;
}
if ( V_28 == V_33 )
F_19 ( V_30 ) ;
F_20 () ;
}
static void F_21 ( struct V_1 * V_2 , bool V_34 )
{
if ( F_11 ( V_2 ) && V_34 )
F_16 ( V_2 , true ) ;
else if ( F_13 ( V_2 , V_32 ) )
F_16 ( V_2 , false ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_21 ( V_2 , 0 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_21 ( V_2 , 1 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 , V_32 ) )
F_16 ( V_2 , false ) ;
F_15 ( V_2 , V_24 ) ;
if ( F_25 ( V_2 , V_27 ) )
F_12 ( V_2 ) -> V_25 &= ~ V_26 ;
}
