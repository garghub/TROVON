static int F_1 ( int V_1 )
{
int V_2 ;
int V_3 = F_2 ( V_1 ) ;
F_3 (i)
if ( F_2 ( V_2 ) == V_3 )
return V_2 ;
return 0 ;
}
static int F_4 ( unsigned int V_1 )
{
struct V_4 V_5 ;
if ( ! V_6 || F_5 ( & V_5 , V_1 ) )
return 0 ;
return 1 ;
}
static int F_6 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
struct V_4 * V_5 = V_10 ;
unsigned long V_11 = 0 ;
if ( V_9 != V_12 )
goto V_13;
V_11 = (
V_5 -> V_14 . V_11 *
( 100 - F_7 ( V_5 -> V_1 ) * 20 )
) / 100 ;
F_8 ( V_5 , 0 , V_11 ) ;
V_13:
return 0 ;
}
static int F_9 ( unsigned int V_1 )
{
if ( ! F_4 ( V_1 ) )
return 0 ;
return V_15 ;
}
static int F_10 ( unsigned int V_1 )
{
if ( ! F_4 ( V_1 ) )
return 0 ;
return F_7 ( V_1 ) ;
}
static int F_11 ( unsigned int V_1 , int V_16 )
{
int V_2 ;
if ( ! F_4 ( V_1 ) )
return 0 ;
F_7 ( V_1 ) = V_16 ;
F_3 (i) {
if ( F_2 ( V_2 ) ==
F_2 ( V_1 ) )
F_12 ( V_2 ) ;
}
return 0 ;
}
void F_13 ( void )
{
int V_2 ;
V_2 = F_14 ( & V_17 ,
V_18 ) ;
if ( ! V_2 )
V_6 = 1 ;
}
void F_15 ( void )
{
if ( V_6 )
F_16
( & V_17 ,
V_18 ) ;
V_6 = 0 ;
}
static int F_9 ( unsigned int V_1 )
{
return 0 ;
}
static int F_10 ( unsigned int V_1 )
{
return 0 ;
}
static int F_11 ( unsigned int V_1 , int V_16 )
{
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
int V_21 = 0 ;
V_21 += F_9 ( V_20 -> V_3 ) ;
if ( V_20 -> V_22 . V_23 )
V_21 += ( V_20 -> V_23 . V_24 - 1 ) ;
return V_21 ;
}
static int
F_18 ( struct V_25 * V_26 ,
unsigned long * V_16 )
{
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_19 * V_20 ;
if ( ! V_28 )
return - V_30 ;
V_20 = F_19 ( V_28 ) ;
if ( ! V_20 )
return - V_30 ;
* V_16 = F_17 ( V_20 ) ;
return 0 ;
}
static int
F_20 ( struct V_25 * V_26 ,
unsigned long * V_31 )
{
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_19 * V_20 ;
if ( ! V_28 )
return - V_30 ;
V_20 = F_19 ( V_28 ) ;
if ( ! V_20 )
return - V_30 ;
* V_31 = F_10 ( V_20 -> V_3 ) ;
if ( V_20 -> V_22 . V_23 )
* V_31 += V_20 -> V_23 . V_16 ;
return 0 ;
}
static int
F_21 ( struct V_25 * V_26 ,
unsigned long V_16 )
{
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_19 * V_20 ;
int V_32 = 0 ;
int V_33 ;
if ( ! V_28 )
return - V_30 ;
V_20 = F_19 ( V_28 ) ;
if ( ! V_20 )
return - V_30 ;
V_33 = F_9 ( V_20 -> V_3 ) ;
if ( V_16 > F_17 ( V_20 ) )
return - V_30 ;
if ( V_16 <= V_33 ) {
if ( V_20 -> V_22 . V_23 && V_20 -> V_23 . V_16 )
V_32 = F_22 ( V_20 , 0 , false ) ;
F_11 ( V_20 -> V_3 , V_16 ) ;
} else {
F_11 ( V_20 -> V_3 , V_33 ) ;
V_32 = F_22 ( V_20 ,
V_16 - V_33 , false ) ;
}
return V_32 ;
}
