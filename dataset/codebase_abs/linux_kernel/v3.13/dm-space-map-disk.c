static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
return F_5 ( & V_4 -> V_6 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
* V_7 = V_4 -> V_8 . V_9 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
* V_7 = ( V_4 -> V_8 . V_9 - V_4 -> V_8 . V_10 ) - V_4 -> V_11 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_12 ,
T_2 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
return F_9 ( & V_4 -> V_6 , V_12 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_12 ,
int * V_13 )
{
int V_14 ;
T_2 V_7 ;
V_14 = F_8 ( V_2 , V_12 , & V_7 ) ;
if ( V_14 )
return V_14 ;
return V_7 > 1 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_12 ,
T_2 V_7 )
{
int V_14 ;
T_2 V_15 ;
enum V_16 V_17 ;
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_14 = F_12 ( & V_4 -> V_6 , V_12 , V_7 , & V_17 ) ;
if ( ! V_14 ) {
switch ( V_17 ) {
case V_18 :
break;
case V_19 :
V_4 -> V_11 ++ ;
break;
case V_20 :
V_14 = F_9 ( & V_4 -> V_8 , V_12 , & V_15 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_15 )
V_4 -> V_11 -- ;
break;
}
}
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_12 )
{
int V_14 ;
enum V_16 V_17 ;
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_14 = F_14 ( & V_4 -> V_6 , V_12 , & V_17 ) ;
if ( ! V_14 && ( V_17 == V_19 ) )
V_4 -> V_11 ++ ;
return V_14 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_12 )
{
enum V_16 V_17 ;
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
return F_16 ( & V_4 -> V_6 , V_12 , & V_17 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 * V_12 )
{
int V_14 ;
enum V_16 V_17 ;
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_14 = F_18 ( & V_4 -> V_8 , V_4 -> V_21 , V_4 -> V_8 . V_9 , V_12 ) ;
if ( V_14 )
return V_14 ;
V_4 -> V_21 = * V_12 + 1 ;
V_14 = F_14 ( & V_4 -> V_6 , * V_12 , & V_17 ) ;
if ( ! V_14 ) {
F_19 ( V_17 != V_19 ) ;
V_4 -> V_11 ++ ;
}
return V_14 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_14 ;
T_1 V_22 ;
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_14 = F_7 ( V_2 , & V_22 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_21 ( & V_4 -> V_6 ) ;
if ( V_14 )
return V_14 ;
memcpy ( & V_4 -> V_8 , & V_4 -> V_6 , sizeof( V_4 -> V_8 ) ) ;
V_4 -> V_21 = 0 ;
V_4 -> V_11 = 0 ;
V_14 = F_7 ( V_2 , & V_22 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_3 * V_13 )
{
* V_13 = sizeof( struct V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_24 , T_3 V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_23 V_26 ;
V_26 . V_9 = F_24 ( V_4 -> V_6 . V_9 ) ;
V_26 . V_10 = F_24 ( V_4 -> V_6 . V_10 ) ;
V_26 . V_27 = F_24 ( V_4 -> V_6 . V_27 ) ;
V_26 . V_28 = F_24 ( V_4 -> V_6 . V_28 ) ;
if ( V_25 < sizeof( V_26 ) )
return - V_29 ;
memcpy ( V_24 , & V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
struct V_1 * F_25 ( struct V_30 * V_31 ,
T_1 V_9 )
{
int V_14 ;
struct V_3 * V_4 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return F_27 ( - V_33 ) ;
V_4 -> V_21 = 0 ;
V_4 -> V_11 = 0 ;
memcpy ( & V_4 -> V_2 , & V_34 , sizeof( V_4 -> V_2 ) ) ;
V_14 = F_28 ( & V_4 -> V_6 , V_31 ) ;
if ( V_14 )
goto V_35;
V_14 = F_5 ( & V_4 -> V_6 , V_9 ) ;
if ( V_14 )
goto V_35;
V_14 = F_20 ( & V_4 -> V_2 ) ;
if ( V_14 )
goto V_35;
return & V_4 -> V_2 ;
V_35:
F_3 ( V_4 ) ;
return F_27 ( V_14 ) ;
}
struct V_1 * F_29 ( struct V_30 * V_31 ,
void * V_26 , T_3 V_36 )
{
int V_14 ;
struct V_3 * V_4 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return F_27 ( - V_33 ) ;
V_4 -> V_21 = 0 ;
V_4 -> V_11 = 0 ;
memcpy ( & V_4 -> V_2 , & V_34 , sizeof( V_4 -> V_2 ) ) ;
V_14 = F_30 ( & V_4 -> V_6 , V_31 , V_26 , V_36 ) ;
if ( V_14 )
goto V_35;
V_14 = F_20 ( & V_4 -> V_2 ) ;
if ( V_14 )
goto V_35;
return & V_4 -> V_2 ;
V_35:
F_3 ( V_4 ) ;
return F_27 ( V_14 ) ;
}
