T_1 T_2 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , NULL , V_4 ) ;
}
T_1 T_2 F_3 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , NULL , V_5 ) ;
}
T_1 T_2 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , V_6 , V_4 ) ;
}
T_1 T_2 F_3 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , V_7 , V_5 ) ;
}
T_1 T_2 F_4 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_5 ( V_1 , V_2 , V_3 , NULL , V_8 ) ;
}
T_1 T_2 F_4 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_5 ( V_1 , V_2 , V_3 , V_9 , V_8 ) ;
}
static int T_4 F_6 ( void )
{
int V_10 ;
int V_11 = 0 ;
int V_12 = 0 ;
struct V_13 V_14 , V_15 ;
T_5 V_16 ;
unsigned long V_17 ;
static T_1 V_1 ;
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
V_12 += 2 * V_18 [ V_10 ] . V_19 ;
V_1 ^= F_3 ( V_18 [ V_10 ] . V_1 , V_20 +
V_18 [ V_10 ] . V_14 , V_18 [ V_10 ] . V_19 ) ;
}
F_7 ( V_17 ) ;
F_8 () ;
F_9 ( & V_14 ) ;
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
if ( V_18 [ V_10 ] . V_21 != F_3 ( V_18 [ V_10 ] . V_1 , V_20 +
V_18 [ V_10 ] . V_14 , V_18 [ V_10 ] . V_19 ) )
V_11 ++ ;
}
F_9 ( & V_15 ) ;
F_10 ( V_17 ) ;
F_11 () ;
V_16 = V_15 . V_22 - V_14 . V_22 +
1000000000 * ( V_15 . V_23 - V_14 . V_23 ) ;
F_12 ( L_1 , V_24 ) ;
if ( V_11 )
F_13 ( L_2 , V_11 ) ;
else {
F_12 ( L_3 ,
V_12 , V_16 ) ;
}
return 0 ;
}
static int T_4 F_14 ( void )
{
int V_10 ;
int V_11 = 0 ;
int V_12 = 0 ;
struct V_13 V_14 , V_15 ;
T_5 V_16 ;
unsigned long V_17 ;
static T_1 V_1 ;
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
V_12 += 2 * V_18 [ V_10 ] . V_19 ;
V_1 ^= F_1 ( V_18 [ V_10 ] . V_1 , V_20 +
V_18 [ V_10 ] . V_14 , V_18 [ V_10 ] . V_19 ) ;
V_1 ^= F_4 ( V_18 [ V_10 ] . V_1 , V_20 +
V_18 [ V_10 ] . V_14 , V_18 [ V_10 ] . V_19 ) ;
}
F_7 ( V_17 ) ;
F_8 () ;
F_9 ( & V_14 ) ;
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
if ( V_18 [ V_10 ] . V_25 != F_1 ( V_18 [ V_10 ] . V_1 , V_20 +
V_18 [ V_10 ] . V_14 , V_18 [ V_10 ] . V_19 ) )
V_11 ++ ;
if ( V_18 [ V_10 ] . V_26 != F_4 ( V_18 [ V_10 ] . V_1 , V_20 +
V_18 [ V_10 ] . V_14 , V_18 [ V_10 ] . V_19 ) )
V_11 ++ ;
}
F_9 ( & V_15 ) ;
F_10 ( V_17 ) ;
F_11 () ;
V_16 = V_15 . V_22 - V_14 . V_22 +
1000000000 * ( V_15 . V_23 - V_14 . V_23 ) ;
F_12 ( L_4 ,
V_24 , V_27 ) ;
if ( V_11 )
F_13 ( L_5 , V_11 ) ;
else {
F_12 ( L_6 ,
V_12 , V_16 ) ;
}
return 0 ;
}
static int T_4 F_15 ( void )
{
F_14 () ;
F_6 () ;
return 0 ;
}
static void T_6 F_16 ( void )
{
}
