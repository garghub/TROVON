static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 , V_8 ;
V_9 [ V_10 ] . V_11 = V_6 -> V_12 ;
V_9 [ V_13 ] . V_11 = V_6 -> V_14 ;
V_9 [ V_15 ] . V_11 = V_6 -> V_16 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_9 ) ; V_7 ++ ) {
V_8 = F_3 ( V_9 [ V_7 ] . V_11 , V_9 [ V_7 ] . V_17 ) ;
if ( V_8 ) {
F_4 ( V_18 L_1 ,
V_9 [ V_7 ] . V_17 , V_8 ) ;
goto V_19;
}
if ( V_7 != V_15 )
F_5 ( V_9 [ V_7 ] . V_11 , 1 ) ;
}
V_2 -> V_11 = V_9 ;
return 0 ;
V_19:
while ( -- V_7 >= 0 )
F_6 ( V_9 [ V_7 ] . V_11 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_9 ) ; V_7 ++ )
F_6 ( V_9 [ V_7 ] . V_11 ) ;
}
static void F_8 ( struct V_20 * V_21 )
{
F_9 ( V_9 [ V_10 ] . V_11 , 0 ) ;
F_10 ( 1000 ) ;
F_9 ( V_9 [ V_10 ] . V_11 , 1 ) ;
F_9 ( V_9 [ V_13 ] . V_11 , 0 ) ;
F_5 ( V_9 [ V_15 ] . V_11 , 0 ) ;
F_10 ( 10 ) ;
}
static void F_11 ( struct V_20 * V_21 , T_1 V_22 )
{
int V_7 ;
F_5 ( V_9 [ V_15 ] . V_11 , 1 ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
F_9 ( V_9 [ V_15 ] . V_11 , V_22 & ( 1 << V_7 ) ) ;
F_10 ( 10 ) ;
F_9 ( V_9 [ V_13 ] . V_11 , 1 ) ;
F_10 ( 10 ) ;
F_9 ( V_9 [ V_13 ] . V_11 , 0 ) ;
F_10 ( 10 ) ;
}
}
static T_1 F_12 ( struct V_20 * V_21 )
{
int V_7 ;
T_1 V_23 = 0 ;
F_13 ( V_9 [ V_15 ] . V_11 ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
F_9 ( V_9 [ V_13 ] . V_11 , 0 ) ;
F_10 ( 10 ) ;
if ( F_14 ( V_9 [ V_15 ] . V_11 ) )
V_23 |= 1 << V_7 ;
F_9 ( V_9 [ V_13 ] . V_11 , 1 ) ;
F_10 ( 10 ) ;
}
return V_23 ;
}
static void F_15 ( struct V_20 * V_21 , T_2 V_24 ,
int V_25 , T_1 * V_26 )
{
F_8 ( V_21 ) ;
F_11 ( V_21 , V_27 ) ;
F_11 ( V_21 , V_24 & 0xff ) ;
F_11 ( V_21 , ( V_24 >> 8 ) & 0xff ) ;
while ( V_25 -- )
* V_26 ++ = F_12 ( V_21 ) ;
}
static void F_16 ( struct V_20 * V_21 , T_2 V_24 ,
int V_25 , T_1 * V_26 )
{
int V_7 ;
T_1 V_28 , V_29 , V_30 ;
F_8 ( V_21 ) ;
F_11 ( V_21 , V_31 ) ;
F_11 ( V_21 , V_24 & 0xff ) ;
F_11 ( V_21 , ( V_24 >> 8 ) & 0xff ) ;
for ( V_7 = 0 ; V_7 < V_25 ; V_7 ++ )
F_11 ( V_21 , V_26 [ V_7 ] ) ;
F_8 ( V_21 ) ;
F_11 ( V_21 , V_32 ) ;
V_28 = F_12 ( V_21 ) ;
V_29 = F_12 ( V_21 ) ;
V_30 = F_12 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_25 ; V_7 ++ ) {
if ( V_26 [ V_7 ] != F_12 ( V_21 ) ) {
F_4 ( V_18 L_2 ) ;
return;
}
}
F_8 ( V_21 ) ;
F_11 ( V_21 , V_33 ) ;
F_11 ( V_21 , V_28 ) ;
F_11 ( V_21 , V_29 ) ;
F_11 ( V_21 , V_30 ) ;
F_13 ( V_9 [ V_15 ] . V_11 ) ;
while ( F_14 ( V_9 [ V_15 ] . V_11 ) )
;
}
static void F_17 ( struct V_20 * V_21 )
{
T_1 V_34 [ 1 ] = { 0x10 } ;
F_16 ( V_21 , 0x201 , 1 , V_34 ) ;
}
static int F_18 ( struct V_20 * V_21 , struct V_35 * V_36 )
{
unsigned long time = 0 ;
F_15 ( V_21 , 0x203 , 4 , ( T_1 * ) & time ) ;
time = F_19 ( time ) ;
F_20 ( time , V_36 ) ;
return F_21 ( V_36 ) ;
}
static int F_22 ( struct V_20 * V_21 , unsigned long V_37 )
{
T_3 time = F_23 ( V_37 ) ;
F_16 ( V_21 , 0x203 , 4 , ( T_1 * ) & time ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_21 . V_38 ;
struct V_1 * V_2 ;
int V_39 = - V_40 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_43 = & V_44 ;
V_39 = V_2 -> V_43 -> V_45 ( V_2 , V_4 , V_6 ) ;
if ( V_39 )
goto V_46;
F_26 ( & V_4 -> V_21 , L_3 ,
V_2 -> V_11 [ V_10 ] . V_11 , V_2 -> V_11 [ V_13 ] . V_11 ,
V_2 -> V_11 [ V_15 ] . V_11 ) ;
F_27 ( V_4 , V_2 ) ;
V_2 -> V_47 = F_28 ( L_4 ,
& V_4 -> V_21 , & V_48 , V_49 ) ;
if ( F_29 ( V_2 -> V_47 ) ) {
V_39 = F_30 ( V_2 -> V_47 ) ;
goto V_50;
}
F_17 ( & V_4 -> V_21 ) ;
return 0 ;
V_50:
V_2 -> V_43 -> V_51 ( V_2 ) ;
V_46:
F_31 ( V_2 ) ;
return V_39 ;
}
static int F_32 ( struct V_3 * V_21 )
{
struct V_1 * V_2 = F_33 ( V_21 ) ;
struct V_52 * V_47 = V_2 -> V_47 ;
if ( V_47 )
F_34 ( V_47 ) ;
V_2 -> V_43 -> V_51 ( V_2 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static T_4 int F_35 ( void )
{
return F_36 ( & V_53 ) ;
}
static T_5 void F_37 ( void )
{
F_38 ( & V_53 ) ;
}
