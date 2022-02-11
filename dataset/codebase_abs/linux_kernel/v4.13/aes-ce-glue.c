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
#ifndef F_4
V_18 [ 0 ] = F_5 ( F_6 ( V_17 [ V_7 - 1 ] ) , 8 ) ;
V_18 [ 0 ] = V_18 [ 0 ] ^ V_17 [ 0 ] ^ V_6 [ V_11 ] ;
#else
V_18 [ 0 ] = F_7 ( F_6 ( V_17 [ V_7 - 1 ] ) , 8 ) ;
V_18 [ 0 ] = V_18 [ 0 ] ^ V_17 [ 0 ] ^ ( V_6 [ V_11 ] << 24 ) ;
#endif
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
V_18 [ 4 ] = F_6 ( V_18 [ 3 ] ) ^ V_17 [ 4 ] ;
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
F_8 ( V_10 + V_11 , V_9 + V_12 ) ;
V_10 [ V_11 ] = V_9 [ 0 ] ;
F_9 () ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 , const T_1 * V_4 ,
unsigned int V_5 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
int V_21 ;
V_21 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( ! V_21 )
return 0 ;
F_12 ( V_20 , V_22 ) ;
return - V_16 ;
}
static int F_13 ( struct V_19 * V_20 , const T_1 * V_4 ,
unsigned int V_5 )
{
struct V_23 * V_2 = F_11 ( V_20 ) ;
int V_21 ;
V_21 = F_14 ( V_20 , V_4 , V_5 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_2 ( & V_2 -> V_24 , V_4 , V_5 / 2 ) ;
if ( ! V_21 )
V_21 = F_2 ( & V_2 -> V_25 , & V_4 [ V_5 / 2 ] ,
V_5 / 2 ) ;
if ( ! V_21 )
return 0 ;
F_12 ( V_20 , V_22 ) ;
return - V_16 ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_16 ( V_27 ) ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
struct V_28 V_29 ;
unsigned int V_30 ;
int V_31 ;
V_31 = F_17 ( & V_29 , V_27 , true ) ;
F_3 () ;
while ( ( V_30 = ( V_29 . V_32 / V_33 ) ) ) {
F_18 ( V_29 . V_34 . V_35 . V_36 , V_29 . V_37 . V_35 . V_36 ,
( T_1 * ) V_2 -> V_9 , F_1 ( V_2 ) , V_30 ) ;
V_31 = F_19 ( & V_29 , V_29 . V_32 % V_33 ) ;
}
F_9 () ;
return V_31 ;
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_16 ( V_27 ) ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
struct V_28 V_29 ;
unsigned int V_30 ;
int V_31 ;
V_31 = F_17 ( & V_29 , V_27 , true ) ;
F_3 () ;
while ( ( V_30 = ( V_29 . V_32 / V_33 ) ) ) {
F_21 ( V_29 . V_34 . V_35 . V_36 , V_29 . V_37 . V_35 . V_36 ,
( T_1 * ) V_2 -> V_10 , F_1 ( V_2 ) , V_30 ) ;
V_31 = F_19 ( & V_29 , V_29 . V_32 % V_33 ) ;
}
F_9 () ;
return V_31 ;
}
static int F_22 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_16 ( V_27 ) ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
struct V_28 V_29 ;
unsigned int V_30 ;
int V_31 ;
V_31 = F_17 ( & V_29 , V_27 , true ) ;
F_3 () ;
while ( ( V_30 = ( V_29 . V_32 / V_33 ) ) ) {
F_23 ( V_29 . V_34 . V_35 . V_36 , V_29 . V_37 . V_35 . V_36 ,
( T_1 * ) V_2 -> V_9 , F_1 ( V_2 ) , V_30 ,
V_29 . V_38 ) ;
V_31 = F_19 ( & V_29 , V_29 . V_32 % V_33 ) ;
}
F_9 () ;
return V_31 ;
}
static int F_24 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_16 ( V_27 ) ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
struct V_28 V_29 ;
unsigned int V_30 ;
int V_31 ;
V_31 = F_17 ( & V_29 , V_27 , true ) ;
F_3 () ;
while ( ( V_30 = ( V_29 . V_32 / V_33 ) ) ) {
F_25 ( V_29 . V_34 . V_35 . V_36 , V_29 . V_37 . V_35 . V_36 ,
( T_1 * ) V_2 -> V_10 , F_1 ( V_2 ) , V_30 ,
V_29 . V_38 ) ;
V_31 = F_19 ( & V_29 , V_29 . V_32 % V_33 ) ;
}
F_9 () ;
return V_31 ;
}
static int F_26 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_16 ( V_27 ) ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
struct V_28 V_29 ;
int V_31 , V_30 ;
V_31 = F_17 ( & V_29 , V_27 , true ) ;
F_3 () ;
while ( ( V_30 = ( V_29 . V_32 / V_33 ) ) ) {
F_27 ( V_29 . V_34 . V_35 . V_36 , V_29 . V_37 . V_35 . V_36 ,
( T_1 * ) V_2 -> V_9 , F_1 ( V_2 ) , V_30 ,
V_29 . V_38 ) ;
V_31 = F_19 ( & V_29 , V_29 . V_32 % V_33 ) ;
}
if ( V_29 . V_32 ) {
T_1 V_39 ( 8 ) V_40 [ V_33 ] ;
unsigned int V_32 = V_29 . V_32 ;
T_1 * V_41 = V_29 . V_34 . V_35 . V_36 ;
T_1 * V_42 = V_29 . V_37 . V_35 . V_36 ;
V_30 = - 1 ;
F_27 ( V_40 , NULL , ( T_1 * ) V_2 -> V_9 ,
F_1 ( V_2 ) , V_30 , V_29 . V_38 ) ;
if ( V_41 != V_42 )
memcpy ( V_41 , V_42 , V_32 ) ;
F_28 ( V_41 , V_40 , V_32 ) ;
V_31 = F_19 ( & V_29 , 0 ) ;
}
F_9 () ;
return V_31 ;
}
static int F_29 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_16 ( V_27 ) ;
struct V_23 * V_2 = F_11 ( V_20 ) ;
int V_31 , V_43 , V_44 = F_1 ( & V_2 -> V_24 ) ;
struct V_28 V_29 ;
unsigned int V_30 ;
V_31 = F_17 ( & V_29 , V_27 , true ) ;
F_3 () ;
for ( V_43 = 1 ; ( V_30 = ( V_29 . V_32 / V_33 ) ) ; V_43 = 0 ) {
F_30 ( V_29 . V_34 . V_35 . V_36 , V_29 . V_37 . V_35 . V_36 ,
( T_1 * ) V_2 -> V_24 . V_9 , V_44 , V_30 ,
V_29 . V_38 , ( T_1 * ) V_2 -> V_25 . V_9 , V_43 ) ;
V_31 = F_19 ( & V_29 , V_29 . V_32 % V_33 ) ;
}
F_9 () ;
return V_31 ;
}
static int F_31 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_16 ( V_27 ) ;
struct V_23 * V_2 = F_11 ( V_20 ) ;
int V_31 , V_43 , V_44 = F_1 ( & V_2 -> V_24 ) ;
struct V_28 V_29 ;
unsigned int V_30 ;
V_31 = F_17 ( & V_29 , V_27 , true ) ;
F_3 () ;
for ( V_43 = 1 ; ( V_30 = ( V_29 . V_32 / V_33 ) ) ; V_43 = 0 ) {
F_32 ( V_29 . V_34 . V_35 . V_36 , V_29 . V_37 . V_35 . V_36 ,
( T_1 * ) V_2 -> V_24 . V_10 , V_44 , V_30 ,
V_29 . V_38 , ( T_1 * ) V_2 -> V_25 . V_9 , V_43 ) ;
V_31 = F_19 ( & V_29 , V_29 . V_32 % V_33 ) ;
}
F_9 () ;
return V_31 ;
}
static void F_33 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_34 ( V_45 ) && V_45 [ V_11 ] ; V_11 ++ )
F_35 ( V_45 [ V_11 ] ) ;
F_36 ( V_46 , F_34 ( V_46 ) ) ;
}
static int T_3 F_37 ( void )
{
struct V_47 * V_48 ;
const char * V_49 ;
const char * V_50 ;
const char * V_51 ;
int V_31 ;
int V_11 ;
V_31 = F_38 ( V_46 , F_34 ( V_46 ) ) ;
if ( V_31 )
return V_31 ;
for ( V_11 = 0 ; V_11 < F_34 ( V_46 ) ; V_11 ++ ) {
V_50 = V_46 [ V_11 ] . V_52 . V_53 + 2 ;
V_51 = V_46 [ V_11 ] . V_52 . V_54 + 2 ;
V_49 = V_46 [ V_11 ] . V_52 . V_54 ;
V_48 = F_39 ( V_50 , V_51 , V_49 ) ;
V_31 = F_40 ( V_48 ) ;
if ( F_41 ( V_48 ) )
goto V_55;
V_45 [ V_11 ] = V_48 ;
}
return 0 ;
V_55:
F_33 () ;
return V_31 ;
}
