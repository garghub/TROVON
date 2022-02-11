static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_7 = & V_2 -> V_8 ;
switch ( V_4 ) {
case V_9 :
V_6 -> V_10 = 0xb0 ;
V_6 -> V_11 = & V_12 ;
break;
case V_13 :
V_6 -> V_10 = 0xd0 ;
V_6 -> V_11 = & V_14 ;
break;
case V_15 :
V_6 -> V_10 = 0xf0 ;
V_6 -> V_11 = & V_16 ;
break;
default:
* V_7 |= V_17 ;
return - V_18 ;
}
F_3 ( ( const T_2 * ) V_3 , & V_6 -> V_19 [ 0 ] , V_4 ) ;
V_6 -> V_20 = V_4 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_21 , const T_1 * V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_11 -> V_23 ( & V_6 -> V_19 [ 0 ] , ( const T_2 * ) V_22 , ( T_2 * ) V_21 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_21 , const T_1 * V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_11 -> V_24 ( & V_6 -> V_19 [ 0 ] , ( const T_2 * ) V_22 , ( T_2 * ) V_21 ) ;
}
static int F_6 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_7 ( V_26 -> V_2 ) ;
struct V_29 V_30 ;
int V_31 ;
F_8 ( & V_30 , V_21 , V_22 , V_28 ) ;
V_31 = F_9 ( V_26 , & V_30 ) ;
V_6 -> V_11 -> V_32 ( & V_6 -> V_19 [ 0 ] ) ;
while ( ( V_28 = V_30 . V_28 ) ) {
unsigned int V_33 = V_28 & V_34 ;
if ( F_10 ( V_33 ) ) {
V_6 -> V_11 -> F_6 ( & V_6 -> V_19 [ 0 ] ,
( const V_35 * ) V_30 . V_22 . V_36 . V_37 ,
( V_35 * ) V_30 . V_21 . V_36 . V_37 ,
V_33 ) ;
}
V_28 &= V_38 - 1 ;
V_31 = F_11 ( V_26 , & V_30 , V_28 ) ;
}
F_12 ( 0 ) ;
return V_31 ;
}
static int F_13 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_7 ( V_26 -> V_2 ) ;
struct V_29 V_30 ;
V_35 * V_39 ;
int V_31 ;
F_8 ( & V_30 , V_21 , V_22 , V_28 ) ;
V_31 = F_9 ( V_26 , & V_30 ) ;
V_6 -> V_11 -> V_40 ( & V_6 -> V_19 [ 0 ] ) ;
V_39 = & V_6 -> V_19 [ V_6 -> V_10 / sizeof( V_35 ) ] ;
while ( ( V_28 = V_30 . V_28 ) ) {
unsigned int V_33 = V_28 & V_34 ;
if ( F_10 ( V_33 ) ) {
V_6 -> V_11 -> F_13 ( V_39 ,
( const V_35 * ) V_30 . V_22 . V_36 . V_37 ,
( V_35 * ) V_30 . V_21 . V_36 . V_37 , V_33 ) ;
}
V_28 &= V_38 - 1 ;
V_31 = F_11 ( V_26 , & V_30 , V_28 ) ;
}
F_12 ( 0 ) ;
return V_31 ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_7 ( V_26 -> V_2 ) ;
struct V_29 V_30 ;
int V_31 ;
F_8 ( & V_30 , V_21 , V_22 , V_28 ) ;
V_31 = F_9 ( V_26 , & V_30 ) ;
V_6 -> V_11 -> V_32 ( & V_6 -> V_19 [ 0 ] ) ;
while ( ( V_28 = V_30 . V_28 ) ) {
unsigned int V_33 = V_28 & V_34 ;
if ( F_10 ( V_33 ) ) {
V_6 -> V_11 -> F_14 ( & V_6 -> V_19 [ 0 ] ,
( const V_35 * ) V_30 . V_22 . V_36 . V_37 ,
( V_35 * ) V_30 . V_21 . V_36 . V_37 ,
V_33 , ( V_35 * ) V_30 . V_41 ) ;
}
V_28 &= V_38 - 1 ;
V_31 = F_11 ( V_26 , & V_30 , V_28 ) ;
}
F_12 ( 0 ) ;
return V_31 ;
}
static int F_15 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_7 ( V_26 -> V_2 ) ;
struct V_29 V_30 ;
V_35 * V_39 ;
int V_31 ;
F_8 ( & V_30 , V_21 , V_22 , V_28 ) ;
V_31 = F_9 ( V_26 , & V_30 ) ;
V_6 -> V_11 -> V_40 ( & V_6 -> V_19 [ 0 ] ) ;
V_39 = & V_6 -> V_19 [ V_6 -> V_10 / sizeof( V_35 ) ] ;
while ( ( V_28 = V_30 . V_28 ) ) {
unsigned int V_33 = V_28 & V_34 ;
if ( F_10 ( V_33 ) ) {
V_6 -> V_11 -> F_15 ( V_39 ,
( const V_35 * ) V_30 . V_22 . V_36 . V_37 ,
( V_35 * ) V_30 . V_21 . V_36 . V_37 ,
V_33 , ( V_35 * ) V_30 . V_41 ) ;
}
V_28 &= V_38 - 1 ;
V_31 = F_11 ( V_26 , & V_30 , V_28 ) ;
}
F_12 ( 0 ) ;
return V_31 ;
}
static int F_16 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_7 ( V_26 -> V_2 ) ;
struct V_29 V_30 ;
int V_31 ;
F_8 ( & V_30 , V_21 , V_22 , V_28 ) ;
V_31 = F_9 ( V_26 , & V_30 ) ;
V_6 -> V_11 -> V_32 ( & V_6 -> V_19 [ 0 ] ) ;
while ( ( V_28 = V_30 . V_28 ) ) {
unsigned int V_33 = V_28 & V_34 ;
if ( F_10 ( V_33 ) ) {
V_6 -> V_11 -> F_16 ( & V_6 -> V_19 [ 0 ] ,
( const V_35 * ) V_30 . V_22 . V_36 . V_37 ,
( V_35 * ) V_30 . V_21 . V_36 . V_37 ,
V_33 , ( V_35 * ) V_30 . V_41 ) ;
}
V_28 &= V_38 - 1 ;
V_31 = F_11 ( V_26 , & V_30 , V_28 ) ;
}
F_12 ( 0 ) ;
return V_31 ;
}
static bool T_3 F_17 ( void )
{
unsigned long V_42 ;
if ( ! ( V_43 & V_44 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_42 & V_45 ) )
return false ;
return true ;
}
static int T_3 F_18 ( void )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < F_19 ( V_47 ) ; V_46 ++ )
F_20 ( & V_47 [ V_46 ] . V_48 ) ;
if ( F_17 () ) {
F_21 ( L_1 ) ;
return F_22 ( V_47 , F_19 ( V_47 ) ) ;
}
F_21 ( L_2 ) ;
return - V_49 ;
}
static void T_4 F_23 ( void )
{
F_24 ( V_47 , F_19 ( V_47 ) ) ;
}
