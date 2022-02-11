static int F_1 ( int V_1 )
{
unsigned char V_2 , div ;
V_2 = ( V_1 >> 8 ) & 0xff ;
div = V_1 & 0xff ;
if ( div > 0 )
return V_3 * V_2 / div ;
return 0 ;
}
static int F_2 ( unsigned int V_4 )
{
unsigned char V_5 , V_6 ;
unsigned char V_2 = 0 , div = 0 ;
int V_7 = 0 ;
while ( ( ( V_2 == 0 ) || ( div == 0 ) ) && ( V_7 <= 3 ) ) {
for ( V_6 = 2 ; V_6 <= 0x80 ; V_6 ++ )
for ( V_5 = 1 ; V_5 <= 0xfe ; V_5 ++ )
if ( F_1 ( F_3 ( V_5 , V_6 ) ) ==
V_4 + V_7 ) {
V_2 = V_5 ;
div = V_6 ;
}
V_7 ++ ;
}
if ( ( V_2 == 0 ) || ( div == 0 ) )
return - 1 ;
return F_3 ( V_2 , div ) ;
}
static void F_4 ( int V_1 )
{
int V_8 ;
F_5 ( V_9 , V_10 , 0 ) ;
for ( V_8 = 0 ; V_8 <= 0x3f ; V_8 ++ )
F_5 ( V_9 , V_11 , V_1 ) ;
return;
}
static unsigned int F_6 ( int V_12 )
{
struct V_13 * V_14 ;
T_1 V_4 , V_8 = 0 ;
V_14 = F_7 ( V_15 , 0x01EF ,
V_16 , V_16 , NULL ) ;
if ( ! V_14 )
return 0 ;
F_8 ( V_14 , V_17 , & V_4 ) ;
V_4 /= 1000000 ;
F_9 ( V_9 , V_18 , ( V_19 * ) & V_8 ) ;
if ( V_12 || ! V_8 )
return V_4 ;
F_8 ( V_9 , V_11 , & V_8 ) ;
V_4 = F_1 ( V_8 ) ;
return V_4 ;
}
static int F_10 ( unsigned int V_4 )
{
T_1 V_8 = 0 ;
unsigned int V_20 ;
int V_21 ;
int V_1 = 0 ;
if ( ( V_4 > V_22 ) || ( V_4 < V_23 ) ) {
F_11 ( L_1 , V_4 ) ;
return - V_24 ;
}
V_20 = F_6 ( 0 ) ;
if ( ! V_20 ) {
F_11 ( L_2 ) ;
return - V_24 ;
}
F_9 ( V_9 , V_18 , ( V_19 * ) & V_8 ) ;
if ( ! V_8 ) {
V_1 = F_2 ( V_20 ) ;
if ( V_1 < 0 )
return - V_24 ;
F_4 ( V_1 ) ;
}
V_8 = 0x01 ;
F_12 ( V_9 , V_18 , ( V_19 ) V_8 ) ;
V_21 = V_20 - V_4 ;
if ( ! V_21 )
return 0 ;
while ( ( V_20 != V_4 ) && ( V_20 <= V_22 ) && ( V_20 >= V_25 ) ) {
if ( V_21 < 0 )
V_20 ++ ;
else
V_20 -- ;
V_1 = F_2 ( V_20 ) ;
if ( V_1 == - 1 )
return - V_24 ;
F_4 ( V_1 ) ;
#ifdef F_13
F_14 ( F_13 ) ;
#endif
}
V_8 = 0x40 ;
F_12 ( V_9 , V_10 , ( V_19 ) V_8 ) ;
return 0 ;
}
static unsigned int F_15 ( unsigned int V_26 )
{
if ( V_26 )
return 0 ;
return F_6 ( 0 ) * V_27 * 100 ;
}
static int F_16 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_32 V_33 ;
unsigned int V_34 ;
if ( ( V_30 > V_29 -> V_35 ) || ( V_30 < V_29 -> V_36 ) )
return - V_24 ;
V_34 = V_30 / ( V_27 * 100 ) ;
V_33 . V_37 = F_15 ( V_29 -> V_26 ) ;
V_33 . V_38 = V_34 * V_27 * 100 ;
if ( V_33 . V_37 == V_33 . V_38 )
return 0 ;
F_17 ( L_3 ,
V_33 . V_37 , V_33 . V_38 ) ;
F_18 ( V_29 , & V_33 ) ;
if ( F_10 ( V_34 ) < 0 )
F_11 ( L_4 , V_34 ) ;
else
F_17 ( L_5 ,
V_34 ) ;
F_19 ( V_29 , & V_33 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_28 * V_29 )
{
unsigned int V_39 ;
V_39 = V_29 -> V_35 / ( V_27 * 100 ) ;
if ( V_29 -> V_36 < ( V_39 * V_27 * 100 ) )
V_29 -> V_35 = ( V_39 + 1 ) * V_27 * 100 ;
F_21 ( V_29 ) ;
return 0 ;
}
static int F_22 ( struct V_28 * V_29 )
{
unsigned int V_4 ;
unsigned int V_40 ;
if ( V_29 -> V_26 != 0 )
return - V_41 ;
V_4 = F_6 ( 0 ) ;
if ( ! V_4 )
return - V_42 ;
if ( ! V_27 ) {
if ( ! V_43 ) {
F_23 ( L_6 ) ;
return - V_41 ;
}
V_27 = V_43 / ( V_4 * 100 ) ;
V_40 = V_27 % 5 ;
if ( V_40 ) {
if ( V_40 > 2 )
V_27 += 5 - V_40 ;
else
V_27 -= V_40 ;
}
}
F_24 ( L_7 ,
V_4 , V_27 / 10 , V_27 % 10 ) ;
V_22 = F_6 ( 1 ) ;
if ( ! V_22 )
return - V_42 ;
if ( ! V_25 )
V_25 = V_22 - V_44 ;
if ( V_25 < V_23 )
V_25 = V_23 ;
V_29 -> V_36 = V_29 -> V_45 . V_46 = V_25 * V_27 * 100 ;
V_29 -> V_35 = V_29 -> V_45 . V_47 = V_22 * V_27 * 100 ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 )
{
return 0 ;
}
static int F_26 ( void )
{
V_9 = F_7 ( V_15 ,
V_48 ,
V_16 , V_16 , NULL ) ;
if ( V_9 == NULL )
return - V_41 ;
F_24 ( L_8 ,
V_9 -> V_49 ) ;
F_24 ( L_9 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
if ( F_26 () ) {
F_24 ( L_10 ) ;
return - V_41 ;
}
return F_28 ( & V_50 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_50 ) ;
}
