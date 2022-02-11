static int F_1 ( unsigned int V_1 )
{
struct V_2 V_3 ;
if ( ! V_4 || F_2 ( & V_3 , V_1 ) )
return 0 ;
return 1 ;
}
static int F_3 ( struct V_5 * V_6 ,
unsigned long V_7 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
unsigned long V_9 = 0 ;
if ( V_7 != V_10 )
goto V_11;
V_9 = (
V_3 -> V_12 . V_9 *
( 100 - F_4 ( V_13 , V_3 -> V_1 ) * 20 )
) / 100 ;
F_5 ( V_3 , 0 , V_9 ) ;
V_11:
return 0 ;
}
static int F_6 ( unsigned int V_1 )
{
if ( ! F_1 ( V_1 ) )
return 0 ;
return V_14 ;
}
static int F_7 ( unsigned int V_1 )
{
if ( ! F_1 ( V_1 ) )
return 0 ;
return F_4 ( V_13 , V_1 ) ;
}
static int F_8 ( unsigned int V_1 , int V_15 )
{
if ( ! F_1 ( V_1 ) )
return 0 ;
F_4 ( V_13 , V_1 ) = V_15 ;
F_9 ( V_1 ) ;
return 0 ;
}
void F_10 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( F_11 ( V_16 ) )
F_4 ( V_13 , V_16 ) = 0 ;
V_16 = F_12 ( & V_18 ,
V_19 ) ;
if ( ! V_16 )
V_4 = 1 ;
}
void F_13 ( void )
{
if ( V_4 )
F_14
( & V_18 ,
V_19 ) ;
V_4 = 0 ;
}
static int F_6 ( unsigned int V_1 )
{
return 0 ;
}
static int F_7 ( unsigned int V_1 )
{
return 0 ;
}
static int F_8 ( unsigned int V_1 , int V_15 )
{
return 0 ;
}
int F_15 ( struct V_20 * V_21 )
{
if ( ! V_21 )
return - V_22 ;
if ( V_21 -> V_23 . V_24 )
V_21 -> V_23 . V_25 = 1 ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 )
{
int V_26 = 0 ;
V_26 += F_6 ( V_21 -> V_27 ) ;
if ( V_21 -> V_23 . V_24 )
V_26 += ( V_21 -> V_24 . V_28 - 1 ) ;
return V_26 ;
}
static int
F_17 ( struct V_29 * V_30 ,
unsigned long * V_15 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_20 * V_21 = F_18 ( V_32 ) ;
if ( ! V_32 || ! V_21 )
return - V_22 ;
* V_15 = F_16 ( V_21 ) ;
return 0 ;
}
static int
F_19 ( struct V_29 * V_30 ,
unsigned long * V_34 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_20 * V_21 = F_18 ( V_32 ) ;
if ( ! V_32 || ! V_21 )
return - V_22 ;
* V_34 = F_7 ( V_21 -> V_27 ) ;
if ( V_21 -> V_23 . V_24 )
* V_34 += V_21 -> V_24 . V_15 ;
return 0 ;
}
static int
F_20 ( struct V_29 * V_30 ,
unsigned long V_15 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_20 * V_21 = F_18 ( V_32 ) ;
int V_35 = 0 ;
int V_36 ;
if ( ! V_32 || ! V_21 )
return - V_22 ;
V_36 = F_6 ( V_21 -> V_27 ) ;
if ( V_15 > F_16 ( V_21 ) )
return - V_22 ;
if ( V_15 <= V_36 ) {
if ( V_21 -> V_23 . V_24 && V_21 -> V_24 . V_15 )
V_35 = F_21 ( V_21 , 0 , false ) ;
F_8 ( V_21 -> V_27 , V_15 ) ;
} else {
F_8 ( V_21 -> V_27 , V_36 ) ;
V_35 = F_21 ( V_21 ,
V_15 - V_36 , false ) ;
}
return V_35 ;
}
