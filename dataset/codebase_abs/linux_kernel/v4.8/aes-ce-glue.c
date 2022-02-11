static int F_1 ( struct V_1 * V_2 )
{
return 6 + V_2 -> V_3 / 4 ;
}
static int F_2 ( struct V_1 * V_2 , const T_1 * V_4 ,
unsigned int V_5 )
{
static T_1 const V_6 [] = {
0x01 , 0x02 , 0x04 , 0x08 , 0x10 , 0x20 , 0x40 , 0x80 , 0x1b , 0x36 ,
} ;
T_2 V_7 = V_5 / sizeof( T_2 ) ;
struct V_8 * V_9 , * V_10 ;
int V_11 , V_12 ;
if ( V_5 != V_13 &&
V_5 != V_14 &&
V_5 != V_15 )
return - V_16 ;
memcpy ( V_2 -> V_9 , V_4 , V_5 ) ;
V_2 -> V_3 = V_5 ;
F_3 () ;
for ( V_11 = 0 ; V_11 < sizeof( V_6 ) ; V_11 ++ ) {
T_2 * V_17 = V_2 -> V_9 + ( V_11 * V_7 ) ;
T_2 * V_18 = V_17 + V_7 ;
V_18 [ 0 ] = F_4 ( F_5 ( V_17 [ V_7 - 1 ] ) , 8 ) ;
V_18 [ 0 ] = V_18 [ 0 ] ^ V_17 [ 0 ] ^ V_6 [ V_11 ] ;
V_18 [ 1 ] = V_18 [ 0 ] ^ V_17 [ 1 ] ;
V_18 [ 2 ] = V_18 [ 1 ] ^ V_17 [ 2 ] ;
V_18 [ 3 ] = V_18 [ 2 ] ^ V_17 [ 3 ] ;
if ( V_5 == V_14 ) {
if ( V_11 >= 7 )
break;
V_18 [ 4 ] = V_18 [ 3 ] ^ V_17 [ 4 ] ;
V_18 [ 5 ] = V_18 [ 4 ] ^ V_17 [ 5 ] ;
} else if ( V_5 == V_15 ) {
if ( V_11 >= 6 )
break;
V_18 [ 4 ] = F_5 ( V_18 [ 3 ] ) ^ V_17 [ 4 ] ;
V_18 [ 5 ] = V_18 [ 4 ] ^ V_17 [ 5 ] ;
V_18 [ 6 ] = V_18 [ 5 ] ^ V_17 [ 6 ] ;
V_18 [ 7 ] = V_18 [ 6 ] ^ V_17 [ 7 ] ;
}
}
V_9 = (struct V_8 * ) V_2 -> V_9 ;
V_10 = (struct V_8 * ) V_2 -> V_10 ;
V_12 = F_1 ( V_2 ) ;
V_10 [ 0 ] = V_9 [ V_12 ] ;
for ( V_11 = 1 , V_12 -- ; V_12 > 0 ; V_11 ++ , V_12 -- )
F_6 ( V_10 + V_11 , V_9 + V_12 ) ;
V_10 [ V_11 ] = V_9 [ 0 ] ;
F_7 () ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 , const T_1 * V_4 ,
unsigned int V_5 )
{
struct V_1 * V_2 = F_9 ( V_20 ) ;
int V_21 ;
V_21 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( ! V_21 )
return 0 ;
V_20 -> V_22 |= V_23 ;
return - V_16 ;
}
static int F_10 ( struct V_19 * V_20 , const T_1 * V_4 ,
unsigned int V_5 )
{
struct V_24 * V_2 = F_9 ( V_20 ) ;
int V_21 ;
V_21 = F_11 ( V_20 , V_4 , V_5 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_2 ( & V_2 -> V_25 , V_4 , V_5 / 2 ) ;
if ( ! V_21 )
V_21 = F_2 ( & V_2 -> V_26 , & V_4 [ V_5 / 2 ] ,
V_5 / 2 ) ;
if ( ! V_21 )
return 0 ;
V_20 -> V_22 |= V_23 ;
return - V_16 ;
}
static int F_12 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_29 * V_31 , unsigned int V_32 )
{
struct V_1 * V_2 = F_13 ( V_28 -> V_20 ) ;
struct V_33 V_34 ;
unsigned int V_35 ;
int V_36 ;
V_28 -> V_37 &= ~ V_38 ;
F_14 ( & V_34 , V_30 , V_31 , V_32 ) ;
V_36 = F_15 ( V_28 , & V_34 ) ;
F_3 () ;
while ( ( V_35 = ( V_34 . V_32 / V_39 ) ) ) {
F_16 ( V_34 . V_30 . V_40 . V_41 , V_34 . V_31 . V_40 . V_41 ,
( T_1 * ) V_2 -> V_9 , F_1 ( V_2 ) , V_35 ) ;
V_36 = F_17 ( V_28 , & V_34 ,
V_34 . V_32 % V_39 ) ;
}
F_7 () ;
return V_36 ;
}
static int F_18 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_29 * V_31 , unsigned int V_32 )
{
struct V_1 * V_2 = F_13 ( V_28 -> V_20 ) ;
struct V_33 V_34 ;
unsigned int V_35 ;
int V_36 ;
V_28 -> V_37 &= ~ V_38 ;
F_14 ( & V_34 , V_30 , V_31 , V_32 ) ;
V_36 = F_15 ( V_28 , & V_34 ) ;
F_3 () ;
while ( ( V_35 = ( V_34 . V_32 / V_39 ) ) ) {
F_19 ( V_34 . V_30 . V_40 . V_41 , V_34 . V_31 . V_40 . V_41 ,
( T_1 * ) V_2 -> V_10 , F_1 ( V_2 ) , V_35 ) ;
V_36 = F_17 ( V_28 , & V_34 ,
V_34 . V_32 % V_39 ) ;
}
F_7 () ;
return V_36 ;
}
static int F_20 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_29 * V_31 , unsigned int V_32 )
{
struct V_1 * V_2 = F_13 ( V_28 -> V_20 ) ;
struct V_33 V_34 ;
unsigned int V_35 ;
int V_36 ;
V_28 -> V_37 &= ~ V_38 ;
F_14 ( & V_34 , V_30 , V_31 , V_32 ) ;
V_36 = F_15 ( V_28 , & V_34 ) ;
F_3 () ;
while ( ( V_35 = ( V_34 . V_32 / V_39 ) ) ) {
F_21 ( V_34 . V_30 . V_40 . V_41 , V_34 . V_31 . V_40 . V_41 ,
( T_1 * ) V_2 -> V_9 , F_1 ( V_2 ) , V_35 ,
V_34 . V_42 ) ;
V_36 = F_17 ( V_28 , & V_34 ,
V_34 . V_32 % V_39 ) ;
}
F_7 () ;
return V_36 ;
}
static int F_22 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_29 * V_31 , unsigned int V_32 )
{
struct V_1 * V_2 = F_13 ( V_28 -> V_20 ) ;
struct V_33 V_34 ;
unsigned int V_35 ;
int V_36 ;
V_28 -> V_37 &= ~ V_38 ;
F_14 ( & V_34 , V_30 , V_31 , V_32 ) ;
V_36 = F_15 ( V_28 , & V_34 ) ;
F_3 () ;
while ( ( V_35 = ( V_34 . V_32 / V_39 ) ) ) {
F_23 ( V_34 . V_30 . V_40 . V_41 , V_34 . V_31 . V_40 . V_41 ,
( T_1 * ) V_2 -> V_10 , F_1 ( V_2 ) , V_35 ,
V_34 . V_42 ) ;
V_36 = F_17 ( V_28 , & V_34 ,
V_34 . V_32 % V_39 ) ;
}
F_7 () ;
return V_36 ;
}
static int F_24 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_29 * V_31 , unsigned int V_32 )
{
struct V_1 * V_2 = F_13 ( V_28 -> V_20 ) ;
struct V_33 V_34 ;
int V_36 , V_35 ;
V_28 -> V_37 &= ~ V_38 ;
F_14 ( & V_34 , V_30 , V_31 , V_32 ) ;
V_36 = F_25 ( V_28 , & V_34 , V_39 ) ;
F_3 () ;
while ( ( V_35 = ( V_34 . V_32 / V_39 ) ) ) {
F_26 ( V_34 . V_30 . V_40 . V_41 , V_34 . V_31 . V_40 . V_41 ,
( T_1 * ) V_2 -> V_9 , F_1 ( V_2 ) , V_35 ,
V_34 . V_42 ) ;
V_32 -= V_35 * V_39 ;
if ( V_32 && V_32 == V_34 . V_32 % V_39 )
break;
V_36 = F_17 ( V_28 , & V_34 ,
V_34 . V_32 % V_39 ) ;
}
if ( V_34 . V_32 % V_39 ) {
T_1 * V_43 = V_34 . V_30 . V_40 . V_41 + V_35 * V_39 ;
T_1 * V_44 = V_34 . V_31 . V_40 . V_41 + V_35 * V_39 ;
T_1 V_45 ( 8 ) V_46 [ V_39 ] ;
V_35 = ( V_32 <= 8 ) ? - 1 : 1 ;
F_26 ( V_46 , V_44 , ( T_1 * ) V_2 -> V_9 ,
F_1 ( V_2 ) , V_35 , V_34 . V_42 ) ;
memcpy ( V_43 , V_46 , V_32 ) ;
V_36 = F_17 ( V_28 , & V_34 , 0 ) ;
}
F_7 () ;
return V_36 ;
}
static int F_27 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_29 * V_31 , unsigned int V_32 )
{
struct V_24 * V_2 = F_13 ( V_28 -> V_20 ) ;
int V_36 , V_47 , V_48 = F_1 ( & V_2 -> V_25 ) ;
struct V_33 V_34 ;
unsigned int V_35 ;
V_28 -> V_37 &= ~ V_38 ;
F_14 ( & V_34 , V_30 , V_31 , V_32 ) ;
V_36 = F_15 ( V_28 , & V_34 ) ;
F_3 () ;
for ( V_47 = 1 ; ( V_35 = ( V_34 . V_32 / V_39 ) ) ; V_47 = 0 ) {
F_28 ( V_34 . V_30 . V_40 . V_41 , V_34 . V_31 . V_40 . V_41 ,
( T_1 * ) V_2 -> V_25 . V_9 , V_48 , V_35 ,
V_34 . V_42 , ( T_1 * ) V_2 -> V_26 . V_9 , V_47 ) ;
V_36 = F_17 ( V_28 , & V_34 ,
V_34 . V_32 % V_39 ) ;
}
F_7 () ;
return V_36 ;
}
static int F_29 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_29 * V_31 , unsigned int V_32 )
{
struct V_24 * V_2 = F_13 ( V_28 -> V_20 ) ;
int V_36 , V_47 , V_48 = F_1 ( & V_2 -> V_25 ) ;
struct V_33 V_34 ;
unsigned int V_35 ;
V_28 -> V_37 &= ~ V_38 ;
F_14 ( & V_34 , V_30 , V_31 , V_32 ) ;
V_36 = F_15 ( V_28 , & V_34 ) ;
F_3 () ;
for ( V_47 = 1 ; ( V_35 = ( V_34 . V_32 / V_39 ) ) ; V_47 = 0 ) {
F_30 ( V_34 . V_30 . V_40 . V_41 , V_34 . V_31 . V_40 . V_41 ,
( T_1 * ) V_2 -> V_25 . V_10 , V_48 , V_35 ,
V_34 . V_42 , ( T_1 * ) V_2 -> V_26 . V_9 , V_47 ) ;
V_36 = F_17 ( V_28 , & V_34 ,
V_34 . V_32 % V_39 ) ;
}
F_7 () ;
return V_36 ;
}
static int T_3 F_31 ( void )
{
if ( ! ( V_49 & V_50 ) )
return - V_51 ;
return F_32 ( V_52 , F_33 ( V_52 ) ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( V_52 , F_33 ( V_52 ) ) ;
}
