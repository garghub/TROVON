static void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 ) ;
if ( ! V_3 )
return NULL ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
F_4 ( V_3 , V_2 -> V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_6 ( & V_2 -> V_6 ) ;
if ( F_7 ( V_3 ) ) {
F_8 ( & V_3 -> V_7 , & V_2 -> V_8 ) ;
V_2 -> V_9 ++ ;
} else {
F_8 ( & V_3 -> V_7 , & V_2 -> V_10 ) ;
V_2 -> V_11 ++ ;
}
F_9 ( & V_2 -> V_6 ) ;
return 0 ;
}
static struct V_3 * F_10 ( struct V_1 * V_2 , bool V_12 )
{
struct V_3 * V_3 ;
if ( V_12 ) {
F_11 ( ! V_2 -> V_9 ) ;
V_3 = F_12 ( & V_2 -> V_8 , struct V_3 , V_7 ) ;
V_2 -> V_9 -- ;
} else {
F_11 ( ! V_2 -> V_11 ) ;
V_3 = F_12 ( & V_2 -> V_10 , struct V_3 , V_7 ) ;
V_2 -> V_11 -- ;
}
F_13 ( & V_3 -> V_7 ) ;
return V_3 ;
}
struct V_3 * F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = NULL ;
F_11 ( ! V_2 ) ;
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_9 )
V_3 = F_10 ( V_2 , true ) ;
else if ( V_2 -> V_11 )
V_3 = F_10 ( V_2 , false ) ;
F_9 ( & V_2 -> V_6 ) ;
if ( ! V_3 )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
void F_15 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
int V_13 ;
F_11 ( V_2 -> V_5 != F_16 ( V_3 ) ) ;
V_13 = F_5 ( V_2 , V_3 ) ;
if ( V_13 )
F_3 ( V_2 , V_3 ) ;
}
static int F_17 ( struct V_1 * V_2 , bool V_12 )
{
int V_14 = V_2 -> V_11 ;
if ( V_12 )
V_14 += V_2 -> V_9 ;
return V_14 << V_2 -> V_5 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_4 ,
int V_15 )
{
int V_16 = 0 ;
bool V_12 ;
if ( F_19 () )
V_12 = true ;
else
V_12 = ! ! ( V_4 & V_17 ) ;
if ( V_15 == 0 )
return F_17 ( V_2 , V_12 ) ;
while ( V_16 < V_15 ) {
struct V_3 * V_3 ;
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_11 ) {
V_3 = F_10 ( V_2 , false ) ;
} else if ( V_12 && V_2 -> V_9 ) {
V_3 = F_10 ( V_2 , true ) ;
} else {
F_9 ( & V_2 -> V_6 ) ;
break;
}
F_9 ( & V_2 -> V_6 ) ;
F_3 ( V_2 , V_3 ) ;
V_16 += ( 1 << V_2 -> V_5 ) ;
}
return V_16 ;
}
struct V_1 * F_20 ( T_1 V_4 , unsigned int V_5 ,
bool V_18 )
{
struct V_1 * V_2 = F_21 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_9 = 0 ;
V_2 -> V_11 = 0 ;
F_22 ( & V_2 -> V_10 ) ;
F_22 ( & V_2 -> V_8 ) ;
V_2 -> V_4 = V_4 | V_20 ;
V_2 -> V_5 = V_5 ;
F_23 ( & V_2 -> V_6 ) ;
F_24 ( & V_2 -> V_21 , V_5 ) ;
if ( V_18 )
V_2 -> V_18 = true ;
return V_2 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
}
static int T_2 F_27 ( void )
{
return 0 ;
}
