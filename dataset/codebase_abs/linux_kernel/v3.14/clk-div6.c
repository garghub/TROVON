static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
F_3 ( F_4 ( clock -> div - 1 ) , clock -> V_4 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
F_3 ( V_5 | F_4 ( V_6 ) ,
clock -> V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
return ! ( F_7 ( clock -> V_4 ) & V_5 ) ;
}
static unsigned long F_8 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int div = ( F_7 ( clock -> V_4 ) & V_6 ) + 1 ;
return V_7 / div ;
}
static unsigned int F_9 ( unsigned long V_8 ,
unsigned long V_7 )
{
unsigned int div ;
div = F_10 ( V_7 , V_8 ) ;
return F_11 (unsigned int, div, 1 , 64 ) ;
}
static long F_12 ( struct V_1 * V_2 , unsigned long V_8 ,
unsigned long * V_7 )
{
unsigned int div = F_9 ( V_8 , * V_7 ) ;
return * V_7 / div ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_8 ,
unsigned long V_7 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int div = F_9 ( V_8 , V_7 ) ;
clock -> div = div ;
if ( ! ( F_7 ( clock -> V_4 ) & V_5 ) )
F_3 ( F_4 ( clock -> div - 1 ) , clock -> V_4 ) ;
return 0 ;
}
static void T_1 F_14 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
struct V_3 * clock ;
const char * V_13 ;
const char * V_14 ;
struct V_15 * V_15 ;
int V_16 ;
clock = F_15 ( sizeof( * clock ) , V_17 ) ;
if ( ! clock ) {
F_16 ( L_1 ,
V_18 , V_10 -> V_14 ) ;
return;
}
clock -> V_4 = F_17 ( V_10 , 0 ) ;
if ( clock -> V_4 == NULL ) {
F_16 ( L_2 ,
V_18 , V_10 -> V_14 ) ;
goto error;
}
clock -> div = ( F_7 ( clock -> V_4 ) & V_6 ) + 1 ;
V_16 = F_18 ( V_10 , L_3 , & V_14 ) ;
if ( V_16 < 0 ) {
F_16 ( L_4 ,
V_18 , V_10 -> V_14 ) ;
goto error;
}
V_13 = F_19 ( V_10 , 0 ) ;
if ( V_13 == NULL ) {
F_16 ( L_5 ,
V_18 , V_10 -> V_14 ) ;
goto error;
}
V_12 . V_14 = V_14 ;
V_12 . V_19 = & V_20 ;
V_12 . V_21 = V_22 ;
V_12 . V_23 = & V_13 ;
V_12 . V_24 = 1 ;
clock -> V_2 . V_12 = & V_12 ;
V_15 = F_20 ( NULL , & clock -> V_2 ) ;
if ( F_21 ( V_15 ) ) {
F_16 ( L_6 ,
V_18 , V_10 -> V_14 , F_22 ( V_15 ) ) ;
goto error;
}
F_23 ( V_10 , V_25 , V_15 ) ;
return;
error:
if ( clock -> V_4 )
F_24 ( clock -> V_4 ) ;
F_25 ( clock ) ;
}
