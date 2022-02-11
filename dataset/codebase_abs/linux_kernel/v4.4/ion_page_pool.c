static void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 ) ;
if ( ! V_3 )
return NULL ;
F_3 ( NULL , V_3 , V_6 << V_2 -> V_5 ,
V_7 ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
F_5 ( V_3 , V_2 -> V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_7 ( & V_2 -> V_8 ) ;
if ( F_8 ( V_3 ) ) {
F_9 ( & V_3 -> V_9 , & V_2 -> V_10 ) ;
V_2 -> V_11 ++ ;
} else {
F_9 ( & V_3 -> V_9 , & V_2 -> V_12 ) ;
V_2 -> V_13 ++ ;
}
F_10 ( & V_2 -> V_8 ) ;
return 0 ;
}
static struct V_3 * F_11 ( struct V_1 * V_2 , bool V_14 )
{
struct V_3 * V_3 ;
if ( V_14 ) {
F_12 ( ! V_2 -> V_11 ) ;
V_3 = F_13 ( & V_2 -> V_10 , struct V_3 , V_9 ) ;
V_2 -> V_11 -- ;
} else {
F_12 ( ! V_2 -> V_13 ) ;
V_3 = F_13 ( & V_2 -> V_12 , struct V_3 , V_9 ) ;
V_2 -> V_13 -- ;
}
F_14 ( & V_3 -> V_9 ) ;
return V_3 ;
}
struct V_3 * F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = NULL ;
F_12 ( ! V_2 ) ;
F_7 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_11 )
V_3 = F_11 ( V_2 , true ) ;
else if ( V_2 -> V_13 )
V_3 = F_11 ( V_2 , false ) ;
F_10 ( & V_2 -> V_8 ) ;
if ( ! V_3 )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
void F_16 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
int V_15 ;
F_12 ( V_2 -> V_5 != F_17 ( V_3 ) ) ;
V_15 = F_6 ( V_2 , V_3 ) ;
if ( V_15 )
F_4 ( V_2 , V_3 ) ;
}
static int F_18 ( struct V_1 * V_2 , bool V_14 )
{
int V_16 = V_2 -> V_13 ;
if ( V_14 )
V_16 += V_2 -> V_11 ;
return V_16 << V_2 -> V_5 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_4 ,
int V_17 )
{
int V_18 = 0 ;
bool V_14 ;
if ( F_20 () )
V_14 = true ;
else
V_14 = ! ! ( V_4 & V_19 ) ;
if ( V_17 == 0 )
return F_18 ( V_2 , V_14 ) ;
while ( V_18 < V_17 ) {
struct V_3 * V_3 ;
F_7 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_13 ) {
V_3 = F_11 ( V_2 , false ) ;
} else if ( V_14 && V_2 -> V_11 ) {
V_3 = F_11 ( V_2 , true ) ;
} else {
F_10 ( & V_2 -> V_8 ) ;
break;
}
F_10 ( & V_2 -> V_8 ) ;
F_4 ( V_2 , V_3 ) ;
V_18 += ( 1 << V_2 -> V_5 ) ;
}
return V_18 ;
}
struct V_1 * F_21 ( T_1 V_4 , unsigned int V_5 )
{
struct V_1 * V_2 = F_22 ( sizeof( struct V_1 ) ,
V_20 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = 0 ;
V_2 -> V_13 = 0 ;
F_23 ( & V_2 -> V_12 ) ;
F_23 ( & V_2 -> V_10 ) ;
V_2 -> V_4 = V_4 | V_21 ;
V_2 -> V_5 = V_5 ;
F_24 ( & V_2 -> V_8 ) ;
F_25 ( & V_2 -> V_22 , V_5 ) ;
return V_2 ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
}
static int T_2 F_28 ( void )
{
return 0 ;
}
