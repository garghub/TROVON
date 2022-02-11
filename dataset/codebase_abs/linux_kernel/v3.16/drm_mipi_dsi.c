static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
F_5 ( V_2 -> V_7 ) ;
F_6 ( V_6 ) ;
}
static struct V_5 * F_7 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 )
return F_9 ( - V_11 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_2 . V_12 = & V_13 ;
V_6 -> V_2 . V_14 = V_9 -> V_2 ;
V_6 -> V_2 . type = & V_15 ;
F_10 ( & V_6 -> V_2 ) ;
return V_6 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
F_12 ( & V_6 -> V_2 , L_1 , F_13 ( V_9 -> V_2 ) , V_6 -> V_16 ) ;
return F_14 ( & V_6 -> V_2 ) ;
}
static struct V_5 *
F_15 ( struct V_8 * V_9 , struct V_17 * V_18 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_19 ;
T_1 V_20 ;
V_19 = F_16 ( V_18 , L_2 , & V_20 ) ;
if ( V_19 ) {
F_17 ( V_2 , L_3 ,
V_18 -> V_21 , V_19 ) ;
return F_9 ( - V_22 ) ;
}
if ( V_20 > 3 ) {
F_17 ( V_2 , L_4 ,
V_18 -> V_21 , V_20 ) ;
return F_9 ( - V_22 ) ;
}
V_6 = F_7 ( V_9 ) ;
if ( F_18 ( V_6 ) ) {
F_17 ( V_2 , L_5 ,
V_18 -> V_21 , F_19 ( V_6 ) ) ;
return V_6 ;
}
V_6 -> V_2 . V_7 = F_20 ( V_18 ) ;
V_6 -> V_16 = V_20 ;
V_19 = F_11 ( V_6 ) ;
if ( V_19 ) {
F_17 ( V_2 , L_6 ,
V_18 -> V_21 , V_19 ) ;
F_6 ( V_6 ) ;
return F_9 ( V_19 ) ;
}
return V_6 ;
}
int F_21 ( struct V_8 * V_9 )
{
struct V_17 * V_18 ;
F_22 (host->dev->of_node, node) {
if ( ! F_23 ( V_18 , L_2 , NULL ) )
continue;
F_15 ( V_9 , V_18 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void * V_23 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
F_25 ( & V_6 -> V_2 ) ;
return 0 ;
}
void F_26 ( struct V_8 * V_9 )
{
F_27 ( V_9 -> V_2 , NULL , F_24 ) ;
}
int F_28 ( struct V_5 * V_6 )
{
const struct V_24 * V_25 = V_6 -> V_9 -> V_25 ;
if ( ! V_25 || ! V_25 -> V_26 )
return - V_27 ;
return V_25 -> V_26 ( V_6 -> V_9 , V_6 ) ;
}
int F_29 ( struct V_5 * V_6 )
{
const struct V_24 * V_25 = V_6 -> V_9 -> V_25 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_27 ;
return V_25 -> V_28 ( V_6 -> V_9 , V_6 ) ;
}
int F_30 ( struct V_5 * V_6 , unsigned int V_16 ,
const void * V_29 , T_2 V_30 )
{
const struct V_24 * V_25 = V_6 -> V_9 -> V_25 ;
struct V_31 V_32 = {
. V_16 = V_16 ,
. V_33 = V_29 ,
. V_34 = V_30
} ;
if ( ! V_25 || ! V_25 -> V_35 )
return - V_27 ;
switch ( V_30 ) {
case 0 :
return - V_22 ;
case 1 :
V_32 . type = V_36 ;
break;
case 2 :
V_32 . type = V_37 ;
break;
default:
V_32 . type = V_38 ;
break;
}
return V_25 -> V_35 ( V_6 -> V_9 , & V_32 ) ;
}
T_3 F_31 ( struct V_5 * V_6 , unsigned int V_16 ,
T_4 V_39 , void * V_29 , T_2 V_30 )
{
const struct V_24 * V_25 = V_6 -> V_9 -> V_25 ;
struct V_31 V_32 = {
. V_16 = V_16 ,
. type = V_40 ,
. V_33 = & V_39 ,
. V_34 = 1 ,
. V_41 = V_29 ,
. V_42 = V_30
} ;
if ( ! V_25 || ! V_25 -> V_35 )
return - V_27 ;
return V_25 -> V_35 ( V_6 -> V_9 , & V_32 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_43 * V_4 = F_33 ( V_2 -> V_44 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
return V_4 -> V_45 ( V_6 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_43 * V_4 = F_33 ( V_2 -> V_44 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
return V_4 -> remove ( V_6 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_43 * V_4 = F_33 ( V_2 -> V_44 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
V_4 -> V_46 ( V_6 ) ;
}
int F_36 ( struct V_43 * V_4 )
{
V_4 -> V_44 . V_12 = & V_13 ;
if ( V_4 -> V_45 )
V_4 -> V_44 . V_45 = F_32 ;
if ( V_4 -> remove )
V_4 -> V_44 . remove = F_34 ;
if ( V_4 -> V_46 )
V_4 -> V_44 . V_46 = F_35 ;
return F_37 ( & V_4 -> V_44 ) ;
}
void F_38 ( struct V_43 * V_4 )
{
F_39 ( & V_4 -> V_44 ) ;
}
static int T_5 F_40 ( void )
{
return F_41 ( & V_13 ) ;
}
