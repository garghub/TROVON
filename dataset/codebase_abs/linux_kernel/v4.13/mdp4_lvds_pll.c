static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static const struct V_9 * F_4 ( unsigned long V_10 )
{
int V_11 ;
for ( V_11 = 1 ; V_11 < F_5 ( V_12 ) ; V_11 ++ )
if ( V_10 > V_12 [ V_11 ] . V_10 )
return & V_12 [ V_11 - 1 ] ;
return & V_12 [ V_11 - 1 ] ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_2 * V_3 = F_7 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_9 * V_9 = F_4 ( V_3 -> V_15 ) ;
int V_11 ;
F_8 ( L_1 , V_3 -> V_15 , V_9 -> V_10 ) ;
if ( F_9 ( ! V_9 ) )
return - V_16 ;
F_10 ( V_1 , V_17 , 0x33 ) ;
for ( V_11 = 0 ; V_9 -> V_18 [ V_11 ] . V_19 ; V_11 ++ )
F_10 ( V_1 , V_9 -> V_18 [ V_11 ] . V_19 , V_9 -> V_18 [ V_11 ] . V_20 ) ;
F_10 ( V_1 , V_21 , 0x01 ) ;
while ( ! F_11 ( V_1 , V_22 ) )
F_12 () ;
return 0 ;
}
static void F_13 ( struct V_13 * V_14 )
{
struct V_2 * V_3 = F_7 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_8 ( L_2 ) ;
F_10 ( V_1 , V_23 , 0x0 ) ;
F_10 ( V_1 , V_21 , 0x0 ) ;
}
static unsigned long F_14 ( struct V_13 * V_14 ,
unsigned long V_24 )
{
struct V_2 * V_3 = F_7 ( V_14 ) ;
return V_3 -> V_15 ;
}
static long F_15 ( struct V_13 * V_14 , unsigned long V_10 ,
unsigned long * V_24 )
{
const struct V_9 * V_9 = F_4 ( V_10 ) ;
return V_9 -> V_10 ;
}
static int F_16 ( struct V_13 * V_14 , unsigned long V_10 ,
unsigned long V_24 )
{
struct V_2 * V_3 = F_7 ( V_14 ) ;
V_3 -> V_15 = V_10 ;
return 0 ;
}
struct V_25 * F_17 ( struct V_26 * V_6 )
{
struct V_2 * V_3 ;
struct V_25 * V_25 ;
int V_27 ;
V_3 = F_18 ( V_6 -> V_6 , sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 ) {
V_27 = - V_29 ;
goto V_30;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_31 . V_32 = & V_33 ;
V_25 = F_19 ( V_6 -> V_6 , & V_3 -> V_31 ) ;
if ( F_20 ( V_25 ) ) {
V_27 = F_21 ( V_25 ) ;
goto V_30;
}
return V_25 ;
V_30:
return F_22 ( V_27 ) ;
}
