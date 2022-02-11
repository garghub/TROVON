static unsigned long F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 ? V_5 : V_6 ;
}
static unsigned long F_2 ( struct V_1 * V_2 , unsigned long V_7 )
{
if ( ! V_2 -> V_3 . V_4 )
return V_7 ;
if ( V_7 == V_8 )
V_7 = V_9 ;
else if ( V_7 == V_10 )
V_7 = V_11 ;
return V_7 ;
}
static unsigned long F_1 ( struct V_1 * V_2 )
{
return V_6 ;
}
static unsigned long F_2 ( struct V_1 * V_2 , unsigned long V_7 )
{
return V_7 ;
}
static unsigned long F_3 ( unsigned long V_12 , unsigned long V_7 ,
bool V_13 )
{
unsigned long V_14 , j1 , V_15 , V_16 , V_17 , V_18 , V_19 ;
unsigned long V_20 , V_21 ;
long V_22 ;
V_22 = ( long ) V_7 - ( long ) ( V_12 + 4 ) ;
if ( V_22 < - 16777216 || V_22 > 16777214 ) {
F_4 ( 1 ) ;
return 0 ;
}
V_14 = ( V_22 >> 24 ) & 0x1 ;
V_16 = ( V_22 >> 23 ) & 0x1 ;
V_17 = ( V_22 >> 22 ) & 0x1 ;
V_18 = ( V_22 >> 12 ) & 0x3ff ;
V_19 = ( V_22 >> 1 ) & 0x7ff ;
j1 = ( ! V_16 ) ^ V_14 ;
V_15 = ( ! V_17 ) ^ V_14 ;
V_20 = 0xf000 | ( V_14 << 10 ) | V_18 ;
V_21 = 0x9000 | ( j1 << 13 ) | ( V_15 << 11 ) | V_19 ;
if ( V_13 )
V_21 |= 1 << 14 ;
return ( V_21 << 16 ) | V_20 ;
}
static unsigned long F_3 ( unsigned long V_12 , unsigned long V_7 ,
bool V_13 )
{
unsigned long V_23 = 0xea000000 ;
long V_22 ;
if ( V_13 )
V_23 |= 1 << 24 ;
V_22 = ( long ) V_7 - ( long ) ( V_12 + 8 ) ;
if ( F_5 ( V_22 < - 33554432 || V_22 > 33554428 ) ) {
F_4 ( 1 ) ;
return 0 ;
}
V_22 = ( V_22 >> 2 ) & 0x00ffffff ;
return V_23 | V_22 ;
}
static unsigned long F_6 ( unsigned long V_12 , unsigned long V_7 )
{
return F_3 ( V_12 , V_7 , true ) ;
}
static int F_7 ( unsigned long V_12 , unsigned long V_24 ,
unsigned long V_25 )
{
unsigned long V_26 ;
if ( F_8 ( & V_26 , ( void * ) V_12 , V_27 ) )
return - V_28 ;
if ( V_26 != V_24 )
return - V_29 ;
if ( F_9 ( ( void * ) V_12 , & V_25 , V_27 ) )
return - V_30 ;
F_10 ( V_12 , V_12 + V_27 ) ;
return 0 ;
}
int F_11 ( T_1 V_31 )
{
unsigned long V_12 , V_24 ;
unsigned long V_25 ;
int V_32 ;
V_12 = ( unsigned long ) & V_33 ;
memcpy ( & V_24 , & V_33 , V_27 ) ;
V_25 = F_6 ( V_12 , ( unsigned long ) V_31 ) ;
V_32 = F_7 ( V_12 , V_24 , V_25 ) ;
#ifdef F_12
if ( ! V_32 ) {
V_12 = ( unsigned long ) & V_34 ;
memcpy ( & V_24 , & V_34 , V_27 ) ;
V_25 = F_6 ( V_12 , ( unsigned long ) V_31 ) ;
V_32 = F_7 ( V_12 , V_24 , V_25 ) ;
}
#endif
return V_32 ;
}
int F_13 ( struct V_1 * V_2 , unsigned long V_7 )
{
unsigned long V_25 , V_24 ;
unsigned long V_35 = V_2 -> V_35 ;
V_24 = F_1 ( V_2 ) ;
V_25 = F_6 ( V_35 , F_2 ( V_2 , V_7 ) ) ;
return F_7 ( V_2 -> V_35 , V_24 , V_25 ) ;
}
int F_14 ( struct V_36 * V_37 ,
struct V_1 * V_2 , unsigned long V_7 )
{
unsigned long V_35 = V_2 -> V_35 ;
unsigned long V_24 ;
unsigned long V_25 ;
int V_32 ;
V_24 = F_6 ( V_35 , F_2 ( V_2 , V_7 ) ) ;
V_25 = F_1 ( V_2 ) ;
V_32 = F_7 ( V_35 , V_24 , V_25 ) ;
#ifdef F_12
if ( V_32 == - V_29 && V_7 == V_8 ) {
V_2 -> V_3 . V_4 = true ;
V_24 = F_6 ( V_35 , F_2 ( V_2 , V_7 ) ) ;
V_25 = F_1 ( V_2 ) ;
V_32 = F_7 ( V_35 , V_24 , V_25 ) ;
}
#endif
return V_32 ;
}
int T_2 F_15 ( void * V_38 )
{
* ( unsigned long * ) V_38 = 0 ;
return 0 ;
}
void F_16 ( unsigned long * V_39 , unsigned long V_40 ,
unsigned long V_41 )
{
unsigned long V_42 = ( unsigned long ) & V_43 ;
struct V_44 V_45 ;
unsigned long V_24 ;
int V_46 ;
if ( F_5 ( F_17 ( & V_47 -> V_48 ) ) )
return;
V_24 = * V_39 ;
* V_39 = V_42 ;
V_46 = F_18 ( V_24 , V_40 , & V_45 . V_49 ,
V_41 ) ;
if ( V_46 == - V_50 ) {
* V_39 = V_24 ;
return;
}
V_45 . V_31 = V_40 ;
if ( ! F_19 ( & V_45 ) ) {
V_47 -> V_51 -- ;
* V_39 = V_24 ;
}
}
static int F_20 ( unsigned long * V_52 ,
void (* V_31) ( void ) , bool V_53 )
{
unsigned long V_54 = ( unsigned long ) V_31 ;
unsigned long V_12 = ( unsigned long ) V_52 ;
unsigned long V_55 = F_3 ( V_12 , V_54 , false ) ;
unsigned long V_56 = 0xe1a00000 ;
unsigned long V_24 = V_53 ? V_56 : V_55 ;
unsigned long V_25 = V_53 ? V_55 : V_56 ;
return F_7 ( V_12 , V_24 , V_25 ) ;
}
static int F_21 ( bool V_53 )
{
int V_32 ;
V_32 = F_20 ( & V_57 ,
V_58 ,
V_53 ) ;
#ifdef F_12
if ( ! V_32 )
V_32 = F_20 ( & V_59 ,
V_60 ,
V_53 ) ;
#endif
return V_32 ;
}
int F_22 ( void )
{
return F_21 ( true ) ;
}
int F_23 ( void )
{
return F_21 ( false ) ;
}
