static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 ,
V_1 ) ;
T_1 V_7 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
F_3 ( & V_6 -> V_11 -> V_12 , V_10 ) ;
V_9 = V_6 -> V_13 [ V_3 ] ;
V_7 = F_4 ( V_14 , V_9 -> V_15 ) ;
V_7 |= 0x40 << V_9 -> V_16 ;
if ( V_4 )
V_7 |= 0x10 << V_9 -> V_16 ;
else
V_7 &= ~ ( 0x10 << V_9 -> V_16 ) ;
F_5 ( V_14 , V_9 -> V_15 , V_7 ) ;
F_6 ( & V_6 -> V_11 -> V_12 , V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
F_1 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 ,
V_1 ) ;
struct V_8 * V_9 ;
unsigned long V_10 ;
F_3 ( & V_6 -> V_11 -> V_12 , V_10 ) ;
V_9 = V_6 -> V_13 [ V_3 ] ;
F_9 ( V_14 , V_9 -> V_15 , 0 ,
0x40 << V_9 -> V_16 ) ;
F_6 ( & V_6 -> V_11 -> V_12 , V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 ,
V_1 ) ;
T_1 V_7 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
F_3 ( & V_6 -> V_11 -> V_12 , V_10 ) ;
V_9 = V_6 -> V_13 [ V_3 ] ;
V_7 = F_4 ( V_14 , V_9 -> V_15 ) ;
F_6 ( & V_6 -> V_11 -> V_12 , V_10 ) ;
return V_7 & ( 0x04 << V_9 -> V_16 ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
F_9 ( V_14 , V_9 -> V_15 , 0x02 , 0x02 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
F_9 ( V_14 , V_9 -> V_15 , 0 , 0x02 ) ;
}
static int F_13 ( void * V_17 )
{
return 0 ;
}
static int F_14 ( void * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 . V_1 . V_20 ; V_18 += 2 )
F_11 ( V_19 . V_13 [ V_18 ] ) ;
return 0 ;
}
int F_15 ( const char * V_21 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 . V_1 . V_20 ; V_18 ++ )
if ( ! strcmp ( V_21 , V_19 . V_13 [ V_18 ] -> V_22 ) )
return V_19 . V_1 . V_23 + V_18 ;
return - 1 ;
}
static int F_16 ( struct V_24 * V_25 )
{
struct V_26 * V_11 = V_25 -> V_27 . V_28 ;
struct V_29 * V_30 = V_11 -> V_30 ;
int V_18 , V_20 = 0 , V_31 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
for ( V_18 = 0 ; V_18 < V_32 ; V_18 ++ ) {
if ( V_30 [ V_18 ] . V_33 != V_34 )
continue;
for ( V_9 = V_35 ;
V_9 < V_35 + V_36 ; V_9 ++ )
if ( V_9 -> V_15 == V_30 [ V_18 ] . V_37 ) {
V_19 . V_13 [ V_20 ] = V_9 ;
V_19 . V_38 [ V_20 ] =
V_9 -> V_22 ;
V_20 ++ ;
}
}
V_19 . V_1 . V_20 = V_20 ;
V_19 . V_1 . V_39 = V_19 . V_38 ;
V_19 . V_11 = V_11 ;
if ( V_20 == 0 ) {
F_17 ( V_40 L_1 ) ;
return 0 ;
}
F_3 ( & V_19 . V_11 -> V_12 , V_10 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 += 2 )
F_11 ( V_19 . V_13 [ V_18 ] ) ;
F_6 ( & V_19 . V_11 -> V_12 , V_10 ) ;
V_19 . V_1 . V_23 = - 1 ;
V_31 = F_18 ( & V_19 . V_1 ) ;
if ( V_31 ) {
F_17 ( V_41 L_2 , V_31 ) ;
V_19 . V_1 . V_20 = 0 ;
}
#ifdef F_19
F_20 ( & V_42 ) ;
#endif
return V_31 ;
}
static int F_21 ( struct V_24 * V_25 )
{
unsigned long V_10 ;
int V_31 = 0 , V_18 ;
#ifdef F_19
F_22 ( & V_42 ) ;
#endif
if ( V_19 . V_1 . V_20 > 0 ) {
V_31 = F_23 ( & V_19 . V_1 ) ;
if ( V_31 ) {
F_17 ( V_41 L_3 ) ;
return V_31 ;
}
}
F_3 ( & V_19 . V_11 -> V_12 , V_10 ) ;
for ( V_18 = 0 ; V_18 < V_19 . V_1 . V_20 ; V_18 += 2 )
F_12 ( V_19 . V_13 [ V_18 ] ) ;
V_19 . V_1 . V_20 = 0 ;
F_6 ( & V_19 . V_11 -> V_12 , V_10 ) ;
return V_31 ;
}
int F_24 ( void )
{
return F_25 ( & V_43 ) ;
}
void F_26 ( void )
{
F_27 ( & V_43 ) ;
}
