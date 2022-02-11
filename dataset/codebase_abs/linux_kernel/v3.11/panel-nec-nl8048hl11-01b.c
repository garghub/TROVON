static inline struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( ! V_5 )
return - V_7 ;
V_3 -> V_8 . V_9 = V_10 ;
if ( F_3 ( V_5 -> V_11 ) ) {
V_6 = F_4 ( V_3 -> V_12 , V_5 -> V_11 ,
V_13 , L_1 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_3 ( V_5 -> V_14 ) ) {
V_6 = F_4 ( V_3 -> V_12 , V_5 -> V_14 ,
V_15 , L_2 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static void F_5 ( struct V_2 * V_3 )
{
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( V_3 -> V_16 == V_17 )
return 0 ;
F_7 ( V_3 , & V_3 -> V_8 . V_9 ) ;
F_8 ( V_3 , V_3 -> V_18 . V_19 . V_20 ) ;
V_6 = F_9 ( V_3 ) ;
if ( V_6 )
goto V_21;
if ( F_3 ( V_5 -> V_14 ) )
F_10 ( V_5 -> V_14 , 1 ) ;
return 0 ;
V_21:
return V_6 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_3 -> V_16 != V_17 )
return;
if ( F_3 ( V_5 -> V_14 ) )
F_10 ( V_5 -> V_14 , 0 ) ;
F_12 ( V_3 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_6 ;
V_6 = F_6 ( V_3 ) ;
if ( V_6 )
return V_6 ;
V_3 -> V_16 = V_17 ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
V_3 -> V_16 = V_22 ;
}
static int F_15 ( struct V_2 * V_3 )
{
return 16 ;
}
static int F_16 ( struct V_23 * V_24 , unsigned char V_25 ,
unsigned char V_26 )
{
int V_27 = 0 ;
unsigned int V_28 = 0 , V_4 = 0 ;
V_28 = 0x0000 | V_25 ;
V_4 = 0x0100 | V_26 ;
V_4 = ( V_28 << 16 ) | V_4 ;
V_27 = F_17 ( V_24 , ( unsigned char * ) & V_4 , 4 ) ;
if ( V_27 )
F_18 ( L_3 , V_4 ) ;
return V_27 ;
}
static int F_19 ( struct V_23 * V_24 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < ( F_20 ( V_30 ) - 1 ) ; V_29 ++ )
F_16 ( V_24 , V_30 [ V_29 ] . V_31 ,
V_30 [ V_29 ] . V_32 ) ;
F_21 ( 20 ) ;
F_16 ( V_24 , V_30 [ V_29 ] . V_31 ,
V_30 [ V_29 ] . V_32 ) ;
return 0 ;
}
static int F_22 ( struct V_23 * V_24 )
{
V_24 -> V_33 = V_34 ;
V_24 -> V_35 = 32 ;
F_23 ( V_24 ) ;
F_19 ( V_24 ) ;
return F_24 ( & V_36 ) ;
}
static int F_25 ( struct V_23 * V_24 )
{
F_26 ( & V_36 ) ;
return 0 ;
}
static int F_27 ( struct V_37 * V_12 )
{
struct V_23 * V_24 = F_28 ( V_12 ) ;
F_16 ( V_24 , 2 , 0x01 ) ;
F_29 ( 40 ) ;
return 0 ;
}
static int F_30 ( struct V_37 * V_12 )
{
struct V_23 * V_24 = F_28 ( V_12 ) ;
F_23 ( V_24 ) ;
F_16 ( V_24 , 2 , 0x00 ) ;
F_19 ( V_24 ) ;
return 0 ;
}
