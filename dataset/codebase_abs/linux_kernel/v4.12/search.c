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
if ( V_12 -> V_14 & V_15 )
return V_7 ;
if ( F_7 ( V_12 ) ) {
switch ( F_8 ( V_12 ) ) {
case V_16 :
case V_17 :
case V_18 :
continue;
case V_19 :
V_7 = F_2 ( V_12 ,
F_3 ( V_12 -> V_20 -> V_8 ,
F_9 ( 0 , 0 ) ) , V_4 ) ;
if ( V_7 )
return V_7 ;
continue;
case V_21 :
V_7 = F_2 ( V_12 ,
F_3 ( V_12 -> V_6 -> V_8 ,
V_12 -> V_9 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
continue;
}
} else {
if ( V_12 -> V_14 & V_22 )
V_7 = F_2 ( V_12 ,
F_3 ( V_12 -> V_20 -> V_8 ,
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
static struct V_5 * F_10 ( struct V_5 * V_6 , unsigned char V_23 )
{
struct V_5 * V_24 ;
struct V_5 * V_12 ;
if ( V_6 -> V_8 == V_23 )
return V_6 ;
F_11 (tmp, &bus->children, node) {
V_24 = F_10 ( V_12 , V_23 ) ;
if ( V_24 )
return V_24 ;
}
return NULL ;
}
struct V_5 * F_12 ( int V_25 , int V_23 )
{
struct V_5 * V_6 = NULL ;
struct V_5 * V_26 ;
while ( ( V_6 = F_13 ( V_6 ) ) != NULL ) {
if ( F_14 ( V_6 ) != V_25 )
continue;
V_26 = F_10 ( V_6 , V_23 ) ;
if ( V_26 )
return V_26 ;
}
return NULL ;
}
struct V_5 * F_13 ( const struct V_5 * V_27 )
{
struct V_28 * V_29 ;
struct V_5 * V_30 = NULL ;
F_15 ( F_16 () ) ;
F_17 ( & V_31 ) ;
V_29 = V_27 ? V_27 -> V_32 . V_33 : V_34 . V_33 ;
if ( V_29 != & V_34 )
V_30 = F_18 ( V_29 , struct V_5 , V_32 ) ;
F_19 ( & V_31 ) ;
return V_30 ;
}
struct V_1 * F_20 ( struct V_5 * V_6 , unsigned int V_9 )
{
struct V_1 * V_35 ;
F_15 ( F_16 () ) ;
F_17 ( & V_31 ) ;
F_11 (dev, &bus->devices, bus_list) {
if ( V_35 -> V_9 == V_9 )
goto V_36;
}
V_35 = NULL ;
V_36:
F_21 ( V_35 ) ;
F_19 ( & V_31 ) ;
return V_35 ;
}
struct V_1 * F_22 ( int V_25 , unsigned int V_6 ,
unsigned int V_9 )
{
struct V_1 * V_35 = NULL ;
F_23 (dev) {
if ( F_14 ( V_35 -> V_6 ) == V_25 &&
( V_35 -> V_6 -> V_8 == V_6 && V_35 -> V_9 == V_9 ) )
return V_35 ;
}
return NULL ;
}
static int F_24 ( struct V_37 * V_35 , void * V_4 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_38 * V_39 = V_4 ;
if ( F_26 ( V_39 , V_2 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_27 ( const struct V_38 * V_39 ,
struct V_1 * V_27 )
{
struct V_37 * V_35 ;
struct V_37 * V_40 = NULL ;
struct V_1 * V_2 = NULL ;
F_15 ( F_16 () ) ;
if ( V_27 )
V_40 = & V_27 -> V_35 ;
V_35 = F_28 ( & V_41 , V_40 , ( void * ) V_39 ,
F_24 ) ;
if ( V_35 )
V_2 = F_25 ( V_35 ) ;
F_29 ( V_27 ) ;
return V_2 ;
}
struct V_1 * F_30 ( unsigned int V_42 , unsigned int V_37 ,
unsigned int V_43 , unsigned int V_44 ,
struct V_1 * V_27 )
{
struct V_38 V_39 = {
. V_42 = V_42 ,
. V_37 = V_37 ,
. V_45 = V_43 ,
. V_46 = V_44 ,
} ;
return F_27 ( & V_39 , V_27 ) ;
}
struct V_1 * F_31 ( unsigned int V_42 , unsigned int V_37 ,
struct V_1 * V_27 )
{
return F_30 ( V_42 , V_37 , V_47 , V_47 , V_27 ) ;
}
struct V_1 * F_32 ( unsigned int V_48 , struct V_1 * V_27 )
{
struct V_38 V_39 = {
. V_42 = V_47 ,
. V_37 = V_47 ,
. V_45 = V_47 ,
. V_46 = V_47 ,
. V_49 = V_47 ,
. V_48 = V_48 ,
} ;
return F_27 ( & V_39 , V_27 ) ;
}
int F_33 ( const struct V_38 * V_50 )
{
struct V_1 * V_51 = NULL ;
F_15 ( F_16 () ) ;
while ( V_50 -> V_42 || V_50 -> V_45 || V_50 -> V_49 ) {
V_51 = F_27 ( V_50 , NULL ) ;
if ( V_51 ) {
F_29 ( V_51 ) ;
return 1 ;
}
V_50 ++ ;
}
return 0 ;
}
