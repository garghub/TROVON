static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_2 ( F_3 ( V_2 ) , V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 ;
V_7 = F_6 ( V_2 , V_3 , V_4 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( & V_6 -> V_8 , V_3 , V_4 / 2 ) ;
if ( ! V_7 )
V_7 = F_7 ( & V_6 -> V_9 , & V_3 [ V_4 / 2 ] ,
V_4 / 2 ) ;
if ( ! V_7 )
return 0 ;
F_8 ( V_2 , V_10 ) ;
return - V_11 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_13 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_28 , V_17 , V_21 , V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_17 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_29 , V_17 , V_21 , V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_19 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_28 , V_17 , V_21 , V_20 . V_30 ,
V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_21 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_29 , V_17 , V_21 , V_20 . V_30 ,
V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
V_16 = 1 ;
F_12 () ;
while ( ( V_21 = ( V_20 . V_22 / V_23 ) ) ) {
F_23 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_28 , V_17 , V_21 , V_20 . V_30 ,
V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
V_16 = 0 ;
}
if ( V_20 . V_22 ) {
T_1 V_31 ( 8 ) V_32 [ V_23 ] ;
unsigned int V_22 = V_20 . V_22 ;
T_1 * V_33 = V_20 . V_24 . V_25 . V_26 ;
T_1 * V_34 = V_20 . V_27 . V_25 . V_26 ;
V_21 = ( V_22 <= 8 ) ? - 1 : 1 ;
F_23 ( V_32 , V_34 , ( T_1 * ) V_6 -> V_28 , V_17 ,
V_21 , V_20 . V_30 , V_16 ) ;
memcpy ( V_33 , V_32 , V_22 ) ;
V_15 = F_14 ( & V_20 , 0 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_24 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_8 . V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_25 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_8 . V_28 , V_17 , V_21 ,
( T_1 * ) V_6 -> V_9 . V_28 , V_20 . V_30 , V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_26 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_8 . V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_27 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_8 . V_29 , V_17 , V_21 ,
( T_1 * ) V_6 -> V_9 . V_28 , V_20 . V_30 , V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static void F_28 ( void )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_29 ( V_36 ) && V_36 [ V_35 ] ; V_35 ++ )
F_30 ( V_36 [ V_35 ] ) ;
F_31 ( V_37 , F_29 ( V_37 ) ) ;
}
static int T_2 F_32 ( void )
{
struct V_38 * V_39 ;
const char * V_40 ;
const char * V_41 ;
const char * V_42 ;
int V_15 ;
int V_35 ;
V_15 = F_33 ( V_37 , F_29 ( V_37 ) ) ;
if ( V_15 )
return V_15 ;
for ( V_35 = 0 ; V_35 < F_29 ( V_37 ) ; V_35 ++ ) {
V_41 = V_37 [ V_35 ] . V_43 . V_44 + 2 ;
V_42 = V_37 [ V_35 ] . V_43 . V_45 + 2 ;
V_40 = V_37 [ V_35 ] . V_43 . V_45 ;
V_39 = F_34 ( V_41 , V_42 , V_40 ) ;
V_15 = F_35 ( V_39 ) ;
if ( F_36 ( V_39 ) )
goto V_46;
V_36 [ V_35 ] = V_39 ;
}
return 0 ;
V_46:
F_28 () ;
return V_15 ;
}
