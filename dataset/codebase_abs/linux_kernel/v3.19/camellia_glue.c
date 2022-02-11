static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const T_2 * V_7 = ( const T_2 * ) V_3 ;
T_2 * V_8 = & V_2 -> V_9 ;
if ( V_4 != 16 && V_4 != 24 && V_4 != 32 ) {
* V_8 |= V_10 ;
return - V_11 ;
}
V_6 -> V_4 = V_4 ;
F_3 ( V_7 , & V_6 -> V_12 [ 0 ] ,
V_4 , & V_6 -> V_13 [ 0 ] ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_14 , const T_1 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( & V_6 -> V_12 [ 0 ] ,
( const T_2 * ) V_15 ,
( T_2 * ) V_14 , V_6 -> V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_14 , const T_1 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( & V_6 -> V_13 [ 0 ] ,
( const T_2 * ) V_15 ,
( T_2 * ) V_14 , V_6 -> V_4 ) ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 * V_14 , struct V_18 * V_15 ,
unsigned int V_19 , bool V_20 )
{
struct V_5 * V_6 = F_8 ( V_17 -> V_2 ) ;
struct V_21 V_22 ;
T_3 * V_23 ;
const T_4 * V_24 ;
int V_25 ;
V_23 = V_26 ;
if ( V_6 -> V_4 != 16 )
V_23 = V_27 ;
F_9 ( & V_22 , V_14 , V_15 , V_19 ) ;
V_25 = F_10 ( V_17 , & V_22 ) ;
V_17 -> V_8 &= ~ V_28 ;
if ( V_20 )
V_24 = & V_6 -> V_12 [ 0 ] ;
else
V_24 = & V_6 -> V_13 [ 0 ] ;
F_11 ( V_24 , V_6 -> V_4 ) ;
while ( ( V_19 = V_22 . V_19 ) ) {
unsigned int V_29 = V_19 & V_30 ;
if ( F_12 ( V_29 ) ) {
const T_4 * V_31 ;
T_4 * V_32 ;
V_31 = ( const T_4 * ) V_22 . V_15 . V_33 . V_34 ;
V_32 = ( T_4 * ) V_22 . V_14 . V_33 . V_34 ;
V_23 ( V_31 , V_32 , V_29 , V_24 ) ;
}
V_19 &= V_35 - 1 ;
V_25 = F_13 ( V_17 , & V_22 , V_19 ) ;
}
F_14 ( 0 ) ;
return V_25 ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_18 * V_14 , struct V_18 * V_15 ,
unsigned int V_19 )
{
return F_7 ( V_17 , V_14 , V_15 , V_19 , true ) ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_18 * V_14 , struct V_18 * V_15 ,
unsigned int V_19 )
{
return F_7 ( V_17 , V_14 , V_15 , V_19 , false ) ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_18 * V_14 , struct V_18 * V_15 ,
unsigned int V_19 )
{
struct V_5 * V_6 = F_8 ( V_17 -> V_2 ) ;
struct V_21 V_22 ;
T_5 * V_23 ;
const T_4 * V_24 ;
int V_25 ;
V_23 = V_36 ;
if ( V_6 -> V_4 != 16 )
V_23 = V_37 ;
F_9 ( & V_22 , V_14 , V_15 , V_19 ) ;
V_25 = F_10 ( V_17 , & V_22 ) ;
V_17 -> V_8 &= ~ V_28 ;
V_24 = & V_6 -> V_12 [ 0 ] ;
F_11 ( V_24 , V_6 -> V_4 ) ;
while ( ( V_19 = V_22 . V_19 ) ) {
unsigned int V_29 = V_19 & V_30 ;
if ( F_12 ( V_29 ) ) {
const T_4 * V_31 ;
T_4 * V_32 ;
V_31 = ( const T_4 * ) V_22 . V_15 . V_33 . V_34 ;
V_32 = ( T_4 * ) V_22 . V_14 . V_33 . V_34 ;
V_23 ( V_31 , V_32 , V_29 , V_24 ,
( T_4 * ) V_22 . V_38 ) ;
}
V_19 &= V_35 - 1 ;
V_25 = F_13 ( V_17 , & V_22 , V_19 ) ;
}
F_14 ( 0 ) ;
return V_25 ;
}
static int F_18 ( struct V_16 * V_17 ,
struct V_18 * V_14 , struct V_18 * V_15 ,
unsigned int V_19 )
{
struct V_5 * V_6 = F_8 ( V_17 -> V_2 ) ;
struct V_21 V_22 ;
T_5 * V_23 ;
const T_4 * V_24 ;
int V_25 ;
V_23 = V_39 ;
if ( V_6 -> V_4 != 16 )
V_23 = V_40 ;
F_9 ( & V_22 , V_14 , V_15 , V_19 ) ;
V_25 = F_10 ( V_17 , & V_22 ) ;
V_17 -> V_8 &= ~ V_28 ;
V_24 = & V_6 -> V_13 [ 0 ] ;
F_11 ( V_24 , V_6 -> V_4 ) ;
while ( ( V_19 = V_22 . V_19 ) ) {
unsigned int V_29 = V_19 & V_30 ;
if ( F_12 ( V_29 ) ) {
const T_4 * V_31 ;
T_4 * V_32 ;
V_31 = ( const T_4 * ) V_22 . V_15 . V_33 . V_34 ;
V_32 = ( T_4 * ) V_22 . V_14 . V_33 . V_34 ;
V_23 ( V_31 , V_32 , V_29 , V_24 ,
( T_4 * ) V_22 . V_38 ) ;
}
V_19 &= V_35 - 1 ;
V_25 = F_13 ( V_17 , & V_22 , V_19 ) ;
}
F_14 ( 0 ) ;
return V_25 ;
}
static bool T_6 F_19 ( void )
{
unsigned long V_41 ;
if ( ! ( V_42 & V_43 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_41 & V_44 ) )
return false ;
return true ;
}
static int T_6 F_20 ( void )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_21 ( V_46 ) ; V_45 ++ )
F_22 ( & V_46 [ V_45 ] . V_47 ) ;
if ( F_19 () ) {
F_23 ( L_1 ) ;
return F_24 ( V_46 , F_21 ( V_46 ) ) ;
}
F_23 ( L_2 ) ;
return - V_48 ;
}
static void T_7 F_25 ( void )
{
F_26 ( V_46 , F_21 ( V_46 ) ) ;
}
