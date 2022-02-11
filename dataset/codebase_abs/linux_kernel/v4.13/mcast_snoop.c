static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
unsigned int V_5 ;
unsigned int V_6 = F_2 ( V_2 ) + sizeof( * V_4 ) ;
if ( ! F_3 ( V_2 , V_6 ) )
return - V_7 ;
V_4 = F_4 ( V_2 ) ;
if ( V_4 -> V_8 != 6 )
return - V_7 ;
V_5 = V_6 + F_5 ( V_4 -> V_9 ) ;
if ( V_2 -> V_5 < V_5 || V_5 <= V_6 )
return - V_7 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
int V_6 ;
T_1 V_10 ;
T_2 V_11 ;
V_4 = F_4 ( V_2 ) ;
if ( V_4 -> V_10 != V_12 )
return - V_13 ;
V_10 = V_4 -> V_10 ;
V_6 = F_2 ( V_2 ) + sizeof( * V_4 ) ;
V_6 = F_7 ( V_2 , V_6 , & V_10 , & V_11 ) ;
if ( V_6 < 0 )
return - V_7 ;
if ( V_10 != V_14 )
return - V_13 ;
F_8 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_10 ( V_2 ) ;
V_5 += sizeof( struct V_15 ) ;
return F_3 ( V_2 , V_5 ) ? 0 : - V_7 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
unsigned int V_5 = F_10 ( V_2 ) ;
if ( ! ( F_12 ( & F_4 ( V_2 ) -> V_18 ) & V_19 ) )
return - V_7 ;
V_5 += sizeof( struct V_16 ) ;
if ( V_2 -> V_5 < V_5 )
return - V_7 ;
if ( V_2 -> V_5 != V_5 ) {
V_5 += sizeof( struct V_20 ) - sizeof( struct V_16 ) ;
if ( V_2 -> V_5 < V_5 || ! F_3 ( V_2 , V_5 ) )
return - V_7 ;
}
V_17 = (struct V_16 * ) F_13 ( V_2 ) ;
if ( F_14 ( & V_17 -> V_21 ) &&
! F_15 ( & F_4 ( V_2 ) -> V_22 ) )
return - V_7 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = (struct V_16 * ) F_13 ( V_2 ) ;
switch ( V_17 -> V_23 ) {
case V_24 :
case V_25 :
return 0 ;
case V_26 :
return F_9 ( V_2 ) ;
case V_27 :
return F_11 ( V_2 ) ;
default:
return - V_13 ;
}
}
static inline T_3 F_17 ( struct V_1 * V_2 )
{
return F_18 ( V_2 , V_14 , V_28 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_1 * * V_29 )
{
struct V_1 * V_30 = NULL ;
unsigned int V_31 ;
unsigned int V_5 = F_10 ( V_2 ) + sizeof( struct V_16 ) ;
int V_32 = - V_7 ;
V_31 = F_5 ( F_4 ( V_2 ) -> V_9 ) ;
V_31 -= F_10 ( V_2 ) - sizeof( struct V_3 ) ;
V_30 = F_20 ( V_2 , V_31 ,
F_17 ) ;
if ( ! V_30 )
goto V_33;
if ( ! F_3 ( V_30 , V_5 ) )
goto V_33;
V_32 = F_16 ( V_30 ) ;
if ( V_32 )
goto V_33;
if ( V_29 )
* V_29 = V_30 ;
else if ( V_30 != V_2 )
F_21 ( V_30 ) ;
V_32 = 0 ;
V_33:
if ( V_32 && V_30 && V_30 != V_2 )
F_21 ( V_30 ) ;
return V_32 ;
}
int F_22 ( struct V_1 * V_2 , struct V_1 * * V_29 )
{
int V_32 ;
V_32 = F_1 ( V_2 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_6 ( V_2 ) ;
if ( V_32 < 0 )
return V_32 ;
return F_19 ( V_2 , V_29 ) ;
}
