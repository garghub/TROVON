struct V_1 *
F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = NULL ;
if ( F_2 ( V_2 ) )
return NULL ;
while ( 1 ) {
if ( F_3 ( V_2 -> V_4 ) )
break;
V_2 = V_2 -> V_4 -> V_5 ;
if ( ! F_2 ( V_2 ) ) {
V_3 = V_2 ;
continue;
}
if ( F_4 ( V_2 ) != V_6 ) {
F_5 ( 1 ) ;
return NULL ;
}
return V_2 ;
}
return V_3 ;
}
static struct V_7 * F_6 ( struct V_7 * V_4 , unsigned char V_8 )
{
struct V_7 * V_9 ;
struct V_10 * V_3 ;
if( V_4 -> V_11 == V_8 )
return V_4 ;
F_7 (tmp, &bus->children) {
V_9 = F_6 ( F_8 ( V_3 ) , V_8 ) ;
if( V_9 )
return V_9 ;
}
return NULL ;
}
struct V_7 * F_9 ( int V_12 , int V_8 )
{
struct V_7 * V_4 = NULL ;
struct V_7 * V_13 ;
while ( ( V_4 = F_10 ( V_4 ) ) != NULL ) {
if ( F_11 ( V_4 ) != V_12 )
continue;
V_13 = F_6 ( V_4 , V_8 ) ;
if ( V_13 )
return V_13 ;
}
return NULL ;
}
struct V_7 *
F_10 ( const struct V_7 * V_14 )
{
struct V_10 * V_15 ;
struct V_7 * V_16 = NULL ;
F_12 ( F_13 () ) ;
F_14 ( & V_17 ) ;
V_15 = V_14 ? V_14 -> V_18 . V_19 : V_20 . V_19 ;
if ( V_15 != & V_20 )
V_16 = F_8 ( V_15 ) ;
F_15 ( & V_17 ) ;
return V_16 ;
}
struct V_1 * F_16 ( struct V_7 * V_4 , unsigned int V_21 )
{
struct V_1 * V_22 ;
F_12 ( F_13 () ) ;
F_14 ( & V_17 ) ;
F_17 (dev, &bus->devices, bus_list) {
if ( V_22 -> V_21 == V_21 )
goto V_23;
}
V_22 = NULL ;
V_23:
F_18 ( V_22 ) ;
F_15 ( & V_17 ) ;
return V_22 ;
}
struct V_1 * F_19 ( int V_12 , unsigned int V_4 ,
unsigned int V_21 )
{
struct V_1 * V_22 = NULL ;
F_20 (dev) {
if ( F_11 ( V_22 -> V_4 ) == V_12 &&
( V_22 -> V_4 -> V_11 == V_4 && V_22 -> V_21 == V_21 ) )
return V_22 ;
}
return NULL ;
}
static int F_21 ( struct V_24 * V_22 , void * V_25 )
{
struct V_1 * V_2 = F_22 ( V_22 ) ;
struct V_26 * V_27 = V_25 ;
if ( F_23 ( V_27 , V_2 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_24 ( const struct V_26 * V_27 ,
struct V_1 * V_14 )
{
struct V_24 * V_22 ;
struct V_24 * V_28 = NULL ;
struct V_1 * V_2 = NULL ;
F_12 ( F_13 () ) ;
if ( V_14 )
V_28 = & V_14 -> V_22 ;
V_22 = F_25 ( & V_29 , V_28 , ( void * ) V_27 ,
F_21 ) ;
if ( V_22 )
V_2 = F_22 ( V_22 ) ;
if ( V_14 )
F_26 ( V_14 ) ;
return V_2 ;
}
struct V_1 * F_27 ( unsigned int V_30 , unsigned int V_24 ,
unsigned int V_31 , unsigned int V_32 ,
struct V_1 * V_14 )
{
struct V_26 V_27 = {
. V_30 = V_30 ,
. V_24 = V_24 ,
. V_33 = V_31 ,
. V_34 = V_32 ,
} ;
return F_24 ( & V_27 , V_14 ) ;
}
struct V_1 *
F_28 ( unsigned int V_30 , unsigned int V_24 , struct V_1 * V_14 )
{
return F_27 ( V_30 , V_24 , V_35 , V_35 , V_14 ) ;
}
struct V_1 * F_29 ( unsigned int V_36 , struct V_1 * V_14 )
{
struct V_26 V_27 = {
. V_30 = V_35 ,
. V_24 = V_35 ,
. V_33 = V_35 ,
. V_34 = V_35 ,
. V_37 = V_35 ,
. V_36 = V_36 ,
} ;
return F_24 ( & V_27 , V_14 ) ;
}
int F_30 ( const struct V_26 * V_38 )
{
struct V_1 * V_39 = NULL ;
F_12 ( F_13 () ) ;
while ( V_38 -> V_30 || V_38 -> V_33 || V_38 -> V_37 ) {
V_39 = F_24 ( V_38 , NULL ) ;
if ( V_39 ) {
F_26 ( V_39 ) ;
return 1 ;
}
V_38 ++ ;
}
return 0 ;
}
