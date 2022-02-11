int F_1 ( struct V_1 * V_2 ,
int (* F_2)( struct V_1 * V_2 ,
T_1 V_3 , void * V_4 ) , void * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , F_3 ( V_2 -> V_6 -> V_8 , V_2 -> V_9 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
if ( F_4 ( V_2 -> V_10 & V_11 ) ) {
V_7 = F_2 ( V_2 , F_3 ( V_2 -> V_6 -> V_8 ,
V_2 -> V_12 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
}
for ( V_6 = V_2 -> V_6 ; ! F_5 ( V_6 ) ; V_6 = V_6 -> V_13 ) {
struct V_1 * V_14 ;
if ( ! V_6 -> V_15 )
continue;
V_14 = V_6 -> V_15 ;
if ( F_6 ( V_14 ) ) {
switch ( F_7 ( V_14 ) ) {
case V_16 :
case V_17 :
case V_18 :
continue;
case V_19 :
V_7 = F_2 ( V_14 ,
F_3 ( V_14 -> V_20 -> V_8 ,
F_8 ( 0 , 0 ) ) , V_4 ) ;
if ( V_7 )
return V_7 ;
continue;
case V_21 :
V_7 = F_2 ( V_14 ,
F_3 ( V_14 -> V_6 -> V_8 ,
V_14 -> V_9 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
continue;
}
} else {
if ( V_14 -> V_10 & V_22 )
V_7 = F_2 ( V_14 ,
F_3 ( V_14 -> V_20 -> V_8 ,
F_8 ( 0 , 0 ) ) , V_4 ) ;
else
V_7 = F_2 ( V_14 ,
F_3 ( V_14 -> V_6 -> V_8 ,
V_14 -> V_9 ) , V_4 ) ;
if ( V_7 )
return V_7 ;
}
}
return V_7 ;
}
struct V_1 * F_9 ( struct V_1 * V_2 )
{
struct V_1 * V_14 = NULL ;
if ( F_6 ( V_2 ) )
return NULL ;
while ( 1 ) {
if ( F_5 ( V_2 -> V_6 ) )
break;
V_2 = V_2 -> V_6 -> V_15 ;
if ( ! F_6 ( V_2 ) ) {
V_14 = V_2 ;
continue;
}
if ( F_7 ( V_2 ) != V_19 ) {
F_10 ( 1 ) ;
return NULL ;
}
return V_2 ;
}
return V_14 ;
}
static struct V_5 * F_11 ( struct V_5 * V_6 , unsigned char V_23 )
{
struct V_5 * V_24 ;
struct V_5 * V_14 ;
if ( V_6 -> V_8 == V_23 )
return V_6 ;
F_12 (tmp, &bus->children, node) {
V_24 = F_11 ( V_14 , V_23 ) ;
if ( V_24 )
return V_24 ;
}
return NULL ;
}
struct V_5 * F_13 ( int V_25 , int V_23 )
{
struct V_5 * V_6 = NULL ;
struct V_5 * V_26 ;
while ( ( V_6 = F_14 ( V_6 ) ) != NULL ) {
if ( F_15 ( V_6 ) != V_25 )
continue;
V_26 = F_11 ( V_6 , V_23 ) ;
if ( V_26 )
return V_26 ;
}
return NULL ;
}
struct V_5 * F_14 ( const struct V_5 * V_27 )
{
struct V_28 * V_29 ;
struct V_5 * V_30 = NULL ;
F_16 ( F_17 () ) ;
F_18 ( & V_31 ) ;
V_29 = V_27 ? V_27 -> V_32 . V_33 : V_34 . V_33 ;
if ( V_29 != & V_34 )
V_30 = F_19 ( V_29 , struct V_5 , V_32 ) ;
F_20 ( & V_31 ) ;
return V_30 ;
}
struct V_1 * F_21 ( struct V_5 * V_6 , unsigned int V_9 )
{
struct V_1 * V_35 ;
F_16 ( F_17 () ) ;
F_18 ( & V_31 ) ;
F_12 (dev, &bus->devices, bus_list) {
if ( V_35 -> V_9 == V_9 )
goto V_36;
}
V_35 = NULL ;
V_36:
F_22 ( V_35 ) ;
F_20 ( & V_31 ) ;
return V_35 ;
}
struct V_1 * F_23 ( int V_25 , unsigned int V_6 ,
unsigned int V_9 )
{
struct V_1 * V_35 = NULL ;
F_24 (dev) {
if ( F_15 ( V_35 -> V_6 ) == V_25 &&
( V_35 -> V_6 -> V_8 == V_6 && V_35 -> V_9 == V_9 ) )
return V_35 ;
}
return NULL ;
}
static int F_25 ( struct V_37 * V_35 , void * V_4 )
{
struct V_1 * V_2 = F_26 ( V_35 ) ;
struct V_38 * V_39 = V_4 ;
if ( F_27 ( V_39 , V_2 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_28 ( const struct V_38 * V_39 ,
struct V_1 * V_27 )
{
struct V_37 * V_35 ;
struct V_37 * V_40 = NULL ;
struct V_1 * V_2 = NULL ;
F_16 ( F_17 () ) ;
if ( V_27 )
V_40 = & V_27 -> V_35 ;
V_35 = F_29 ( & V_41 , V_40 , ( void * ) V_39 ,
F_25 ) ;
if ( V_35 )
V_2 = F_26 ( V_35 ) ;
if ( V_27 )
F_30 ( V_27 ) ;
return V_2 ;
}
struct V_1 * F_31 ( unsigned int V_42 , unsigned int V_37 ,
unsigned int V_43 , unsigned int V_44 ,
struct V_1 * V_27 )
{
struct V_38 V_39 = {
. V_42 = V_42 ,
. V_37 = V_37 ,
. V_45 = V_43 ,
. V_46 = V_44 ,
} ;
return F_28 ( & V_39 , V_27 ) ;
}
struct V_1 * F_32 ( unsigned int V_42 , unsigned int V_37 ,
struct V_1 * V_27 )
{
return F_31 ( V_42 , V_37 , V_47 , V_47 , V_27 ) ;
}
struct V_1 * F_33 ( unsigned int V_48 , struct V_1 * V_27 )
{
struct V_38 V_39 = {
. V_42 = V_47 ,
. V_37 = V_47 ,
. V_45 = V_47 ,
. V_46 = V_47 ,
. V_49 = V_47 ,
. V_48 = V_48 ,
} ;
return F_28 ( & V_39 , V_27 ) ;
}
int F_34 ( const struct V_38 * V_50 )
{
struct V_1 * V_51 = NULL ;
F_16 ( F_17 () ) ;
while ( V_50 -> V_42 || V_50 -> V_45 || V_50 -> V_49 ) {
V_51 = F_28 ( V_50 , NULL ) ;
if ( V_51 ) {
F_30 ( V_51 ) ;
return 1 ;
}
V_50 ++ ;
}
return 0 ;
}
