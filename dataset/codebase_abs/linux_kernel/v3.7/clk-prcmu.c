static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 , true ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( V_4 -> V_5 , false ) )
F_5 ( L_1 , V_6 ,
V_2 -> V_7 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_9 = 1 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_9 = 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_9 ;
}
static unsigned long F_9 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_10 ( V_4 -> V_5 ) ;
}
static long F_11 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_12 ( V_4 -> V_5 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_14 ( V_4 -> V_5 , V_11 ) ;
}
static int F_15 ( bool V_12 )
{
static int V_13 ;
int V_14 = 0 ;
if ( V_12 ) {
if ( ! V_13 )
V_14 = F_16 ( V_15 ,
L_2 , 100 ) ;
if ( ! V_14 )
V_13 ++ ;
} else {
V_13 -- ;
if ( ! V_13 )
F_17 ( V_15 ,
L_2 ) ;
}
return V_14 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_14 = F_15 ( true ) ;
if ( V_14 ) {
F_5 ( L_3 ,
V_6 , V_2 -> V_7 -> V_8 ) ;
return V_14 ;
}
V_14 = F_3 ( V_4 -> V_5 , true ) ;
if ( V_14 )
F_15 ( false ) ;
return V_14 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( V_4 -> V_5 , false ) )
goto V_16;
if ( F_15 ( false ) )
goto V_16;
return;
V_16:
F_5 ( L_1 , V_6 ,
V_2 -> V_7 -> V_8 ) ;
}
static struct V_4 * F_20 ( const char * V_8 ,
const char * V_17 ,
T_1 V_5 ,
unsigned long V_11 ,
unsigned long V_18 ,
struct V_19 * V_20 )
{
struct V_3 * V_4 ;
struct V_21 V_22 ;
struct V_4 * V_23 ;
if ( ! V_8 ) {
F_5 ( L_4 , V_6 ) ;
return F_21 ( - V_24 ) ;
}
V_4 = F_22 ( sizeof( struct V_3 ) , V_25 ) ;
if ( ! V_4 ) {
F_5 ( L_5 , V_6 ) ;
return F_21 ( - V_26 ) ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_9 = 1 ;
if ( V_11 )
F_14 ( V_5 , V_11 ) ;
V_22 . V_8 = V_8 ;
V_22 . V_27 = V_20 ;
V_22 . V_18 = V_18 ;
V_22 . V_28 = ( V_17 ? & V_17 : NULL ) ;
V_22 . V_29 = ( V_17 ? 1 : 0 ) ;
V_4 -> V_2 . V_7 = & V_22 ;
V_23 = F_23 ( NULL , & V_4 -> V_2 ) ;
if ( F_24 ( V_23 ) )
goto V_30;
return V_23 ;
V_30:
F_25 ( V_4 ) ;
F_5 ( L_6 , V_6 ) ;
return F_21 ( - V_26 ) ;
}
struct V_4 * F_26 ( const char * V_8 ,
const char * V_17 ,
T_1 V_5 ,
unsigned long V_11 ,
unsigned long V_18 )
{
return F_20 ( V_8 , V_17 , V_5 , V_11 , V_18 ,
& V_31 ) ;
}
struct V_4 * F_27 ( const char * V_8 ,
const char * V_17 ,
T_1 V_5 ,
unsigned long V_18 )
{
return F_20 ( V_8 , V_17 , V_5 , 0 , V_18 ,
& V_32 ) ;
}
struct V_4 * F_28 ( const char * V_8 ,
const char * V_17 ,
T_1 V_5 ,
unsigned long V_18 )
{
return F_20 ( V_8 , V_17 , V_5 , 0 , V_18 ,
& V_33 ) ;
}
struct V_4 * F_29 ( const char * V_8 ,
const char * V_17 ,
T_1 V_5 ,
unsigned long V_18 )
{
return F_20 ( V_8 , V_17 , V_5 , 0 , V_18 ,
& V_34 ) ;
}
