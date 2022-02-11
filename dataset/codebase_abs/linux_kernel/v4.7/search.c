int F_1 ( struct V_1 * V_2 ,
int (* F_2)( struct V_1 * V_2 ,
T_1 V_3 , void * V_4 ) , void * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , F_3 ( V_2 -> V_6 -> V_8 , V_2 -> V_9 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
if ( F_4 ( V_2 -> V_10 ) ) {
T_2 V_9 ;
F_5 (devfn, pdev->dma_alias_mask, U8_MAX) {
V_7 = F_2 ( V_2 , F_3 ( V_2 -> V_6 -> V_8 , V_9 ) ,
V_4 ) ;
if ( V_7 )
return V_7 ;
}
}
for ( V_6 = V_2 -> V_6 ; ! F_6 ( V_6 ) ; V_6 = V_6 -> V_11 ) {
struct V_1 * V_12 ;
if ( ! V_6 -> V_13 )
continue;
V_12 = V_6 -> V_13 ;
if ( F_7 ( V_12 ) ) {
switch ( F_8 ( V_12 ) ) {
case V_14 :
case V_15 :
case V_16 :
continue;
case V_17 :
V_7 = F_2 ( V_12 ,
F_3 ( V_12 -> V_18 -> V_8 ,
F_9 ( 0 , 0 ) ) , V_4 ) ;
if ( V_7 )
return V_7 ;
continue;
case V_19 :
V_7 = F_2 ( V_12 ,
F_3 ( V_12 -> V_6 -> V_8 ,
V_12 -> V_9 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
continue;
}
} else {
if ( V_12 -> V_20 & V_21 )
V_7 = F_2 ( V_12 ,
F_3 ( V_12 -> V_18 -> V_8 ,
F_9 ( 0 , 0 ) ) , V_4 ) ;
else
V_7 = F_2 ( V_12 ,
F_3 ( V_12 -> V_6 -> V_8 ,
V_12 -> V_9 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
}
}
return V_7 ;
}
static struct V_5 * F_10 ( struct V_5 * V_6 , unsigned char V_22 )
{
struct V_5 * V_23 ;
struct V_5 * V_12 ;
if ( V_6 -> V_8 == V_22 )
return V_6 ;
F_11 (tmp, &bus->children, node) {
V_23 = F_10 ( V_12 , V_22 ) ;
if ( V_23 )
return V_23 ;
}
return NULL ;
}
struct V_5 * F_12 ( int V_24 , int V_22 )
{
struct V_5 * V_6 = NULL ;
struct V_5 * V_25 ;
while ( ( V_6 = F_13 ( V_6 ) ) != NULL ) {
if ( F_14 ( V_6 ) != V_24 )
continue;
V_25 = F_10 ( V_6 , V_22 ) ;
if ( V_25 )
return V_25 ;
}
return NULL ;
}
struct V_5 * F_13 ( const struct V_5 * V_26 )
{
struct V_27 * V_28 ;
struct V_5 * V_29 = NULL ;
F_15 ( F_16 () ) ;
F_17 ( & V_30 ) ;
V_28 = V_26 ? V_26 -> V_31 . V_32 : V_33 . V_32 ;
if ( V_28 != & V_33 )
V_29 = F_18 ( V_28 , struct V_5 , V_31 ) ;
F_19 ( & V_30 ) ;
return V_29 ;
}
struct V_1 * F_20 ( struct V_5 * V_6 , unsigned int V_9 )
{
struct V_1 * V_34 ;
F_15 ( F_16 () ) ;
F_17 ( & V_30 ) ;
F_11 (dev, &bus->devices, bus_list) {
if ( V_34 -> V_9 == V_9 )
goto V_35;
}
V_34 = NULL ;
V_35:
F_21 ( V_34 ) ;
F_19 ( & V_30 ) ;
return V_34 ;
}
struct V_1 * F_22 ( int V_24 , unsigned int V_6 ,
unsigned int V_9 )
{
struct V_1 * V_34 = NULL ;
F_23 (dev) {
if ( F_14 ( V_34 -> V_6 ) == V_24 &&
( V_34 -> V_6 -> V_8 == V_6 && V_34 -> V_9 == V_9 ) )
return V_34 ;
}
return NULL ;
}
static int F_24 ( struct V_36 * V_34 , void * V_4 )
{
struct V_1 * V_2 = F_25 ( V_34 ) ;
struct V_37 * V_38 = V_4 ;
if ( F_26 ( V_38 , V_2 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_27 ( const struct V_37 * V_38 ,
struct V_1 * V_26 )
{
struct V_36 * V_34 ;
struct V_36 * V_39 = NULL ;
struct V_1 * V_2 = NULL ;
F_15 ( F_16 () ) ;
if ( V_26 )
V_39 = & V_26 -> V_34 ;
V_34 = F_28 ( & V_40 , V_39 , ( void * ) V_38 ,
F_24 ) ;
if ( V_34 )
V_2 = F_25 ( V_34 ) ;
F_29 ( V_26 ) ;
return V_2 ;
}
struct V_1 * F_30 ( unsigned int V_41 , unsigned int V_36 ,
unsigned int V_42 , unsigned int V_43 ,
struct V_1 * V_26 )
{
struct V_37 V_38 = {
. V_41 = V_41 ,
. V_36 = V_36 ,
. V_44 = V_42 ,
. V_45 = V_43 ,
} ;
return F_27 ( & V_38 , V_26 ) ;
}
struct V_1 * F_31 ( unsigned int V_41 , unsigned int V_36 ,
struct V_1 * V_26 )
{
return F_30 ( V_41 , V_36 , V_46 , V_46 , V_26 ) ;
}
struct V_1 * F_32 ( unsigned int V_47 , struct V_1 * V_26 )
{
struct V_37 V_38 = {
. V_41 = V_46 ,
. V_36 = V_46 ,
. V_44 = V_46 ,
. V_45 = V_46 ,
. V_48 = V_46 ,
. V_47 = V_47 ,
} ;
return F_27 ( & V_38 , V_26 ) ;
}
int F_33 ( const struct V_37 * V_49 )
{
struct V_1 * V_50 = NULL ;
F_15 ( F_16 () ) ;
while ( V_49 -> V_41 || V_49 -> V_44 || V_49 -> V_48 ) {
V_50 = F_27 ( V_49 , NULL ) ;
if ( V_50 ) {
F_29 ( V_50 ) ;
return 1 ;
}
V_49 ++ ;
}
return 0 ;
}
