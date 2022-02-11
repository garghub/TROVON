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
if ( V_2 -> V_6 != V_7 ) {
F_4 ( 1 ) ;
return NULL ;
}
return V_2 ;
}
return V_3 ;
}
static struct V_8 * F_5 ( struct V_8 * V_4 , unsigned char V_9 )
{
struct V_8 * V_10 ;
struct V_11 * V_3 ;
if( V_4 -> V_12 == V_9 )
return V_4 ;
F_6 (tmp, &bus->children) {
V_10 = F_5 ( F_7 ( V_3 ) , V_9 ) ;
if( V_10 )
return V_10 ;
}
return NULL ;
}
struct V_8 * F_8 ( int V_13 , int V_9 )
{
struct V_8 * V_4 = NULL ;
struct V_8 * V_14 ;
while ( ( V_4 = F_9 ( V_4 ) ) != NULL ) {
if ( F_10 ( V_4 ) != V_13 )
continue;
V_14 = F_5 ( V_4 , V_9 ) ;
if ( V_14 )
return V_14 ;
}
return NULL ;
}
struct V_8 *
F_9 ( const struct V_8 * V_15 )
{
struct V_11 * V_16 ;
struct V_8 * V_17 = NULL ;
F_11 ( F_12 () ) ;
F_13 ( & V_18 ) ;
V_16 = V_15 ? V_15 -> V_19 . V_20 : V_21 . V_20 ;
if ( V_16 != & V_21 )
V_17 = F_7 ( V_16 ) ;
F_14 ( & V_18 ) ;
return V_17 ;
}
struct V_1 * F_15 ( struct V_8 * V_4 , unsigned int V_22 )
{
struct V_11 * V_3 ;
struct V_1 * V_23 ;
F_11 ( F_12 () ) ;
F_13 ( & V_18 ) ;
F_6 (tmp, &bus->devices) {
V_23 = F_16 ( V_3 ) ;
if ( V_23 -> V_22 == V_22 )
goto V_24;
}
V_23 = NULL ;
V_24:
F_17 ( V_23 ) ;
F_14 ( & V_18 ) ;
return V_23 ;
}
struct V_1 * F_18 ( int V_13 , unsigned int V_4 ,
unsigned int V_22 )
{
struct V_1 * V_23 = NULL ;
F_19 (dev) {
if ( F_10 ( V_23 -> V_4 ) == V_13 &&
( V_23 -> V_4 -> V_12 == V_4 && V_23 -> V_22 == V_22 ) )
return V_23 ;
}
return NULL ;
}
static int F_20 ( struct V_25 * V_23 , void * V_26 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
struct V_27 * V_28 = V_26 ;
if ( F_22 ( V_28 , V_2 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_23 ( const struct V_27 * V_28 ,
struct V_1 * V_15 )
{
struct V_25 * V_23 ;
struct V_25 * V_29 = NULL ;
struct V_1 * V_2 = NULL ;
F_11 ( F_12 () ) ;
if ( V_15 )
V_29 = & V_15 -> V_23 ;
V_23 = F_24 ( & V_30 , V_29 , ( void * ) V_28 ,
F_20 ) ;
if ( V_23 )
V_2 = F_21 ( V_23 ) ;
if ( V_15 )
F_25 ( V_15 ) ;
return V_2 ;
}
struct V_1 * F_26 ( unsigned int V_31 , unsigned int V_25 ,
unsigned int V_32 , unsigned int V_33 ,
struct V_1 * V_15 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 ;
if ( F_27 ( F_28 () ) )
return NULL ;
V_28 = F_29 ( sizeof( * V_28 ) , V_34 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_31 = V_31 ;
V_28 -> V_25 = V_25 ;
V_28 -> V_35 = V_32 ;
V_28 -> V_36 = V_33 ;
V_2 = F_23 ( V_28 , V_15 ) ;
F_30 ( V_28 ) ;
return V_2 ;
}
struct V_1 *
F_31 ( unsigned int V_31 , unsigned int V_25 , struct V_1 * V_15 )
{
return F_26 ( V_31 , V_25 , V_37 , V_37 , V_15 ) ;
}
struct V_1 * F_32 ( unsigned int V_38 , struct V_1 * V_15 )
{
struct V_1 * V_23 ;
struct V_27 * V_28 ;
V_28 = F_29 ( sizeof( * V_28 ) , V_34 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_31 = V_28 -> V_25 = V_28 -> V_35 = V_28 -> V_36 = V_37 ;
V_28 -> V_39 = V_37 ;
V_28 -> V_38 = V_38 ;
V_23 = F_23 ( V_28 , V_15 ) ;
F_30 ( V_28 ) ;
return V_23 ;
}
int F_33 ( const struct V_27 * V_40 )
{
struct V_1 * V_41 = NULL ;
F_11 ( F_12 () ) ;
while ( V_40 -> V_31 || V_40 -> V_35 || V_40 -> V_39 ) {
V_41 = F_23 ( V_40 , NULL ) ;
if ( V_41 )
goto exit;
V_40 ++ ;
}
exit:
if ( V_41 )
return 1 ;
return 0 ;
}
