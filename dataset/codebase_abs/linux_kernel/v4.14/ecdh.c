static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static unsigned int F_3 ( unsigned int V_4 )
{
switch ( V_4 ) {
case V_5 : return 3 ;
case V_6 : return 4 ;
default: return 0 ;
}
}
static int F_4 ( struct V_2 * V_3 , const void * V_7 ,
unsigned int V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_10 V_11 ;
unsigned int V_12 ;
if ( F_5 ( V_7 , V_8 , & V_11 ) < 0 )
return - V_13 ;
V_12 = F_3 ( V_11 . V_4 ) ;
if ( ! V_12 )
return - V_13 ;
V_9 -> V_4 = V_11 . V_4 ;
V_9 -> V_12 = V_12 ;
if ( ! V_11 . V_14 || ! V_11 . V_15 )
return F_6 ( V_9 -> V_4 , V_9 -> V_12 ,
V_9 -> V_16 ) ;
if ( F_7 ( V_9 -> V_4 , V_9 -> V_12 ,
( const V_17 * ) V_11 . V_14 , V_11 . V_15 ) < 0 )
return - V_13 ;
memcpy ( V_9 -> V_16 , V_11 . V_14 , V_11 . V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_9 ( V_19 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_17 * V_20 ;
V_17 * V_21 = NULL ;
void * V_7 ;
T_1 V_22 , V_23 , V_24 ;
int V_25 = - V_26 ;
V_23 = V_9 -> V_12 << V_27 ;
V_24 = 2 * V_23 ;
V_20 = F_10 ( V_24 , V_28 ) ;
if ( ! V_20 )
return - V_26 ;
if ( V_19 -> V_29 ) {
V_21 = F_10 ( V_23 , V_28 ) ;
if ( ! V_21 )
goto V_30;
V_22 = F_11 ( V_19 -> V_29 , 1 , V_20 ,
V_24 ) ;
if ( V_22 != V_24 ) {
V_25 = - V_13 ;
goto V_31;
}
V_25 = F_12 ( V_9 -> V_4 , V_9 -> V_12 ,
V_9 -> V_16 , V_20 ,
V_21 ) ;
V_7 = V_21 ;
} else {
V_25 = F_13 ( V_9 -> V_4 , V_9 -> V_12 ,
V_9 -> V_16 , V_20 ) ;
V_7 = V_20 ;
V_23 = V_24 ;
}
if ( V_25 < 0 )
goto V_31;
V_22 = F_14 ( V_19 -> V_32 , 1 , V_7 , V_23 ) ;
if ( V_22 != V_23 )
V_25 = - V_13 ;
V_31:
F_15 ( V_21 ) ;
V_30:
F_16 ( V_20 ) ;
return V_25 ;
}
static unsigned int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return V_9 -> V_12 << ( V_27 + 1 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
return;
}
static int F_19 ( void )
{
return F_20 ( & V_10 ) ;
}
static void F_21 ( void )
{
F_22 ( & V_10 ) ;
}
