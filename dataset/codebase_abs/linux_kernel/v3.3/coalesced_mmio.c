static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_3 ,
T_1 V_4 , int V_5 )
{
if ( V_5 < 0 )
return 0 ;
if ( V_4 + V_5 < V_4 )
return 0 ;
if ( V_4 < V_3 -> V_6 . V_4 )
return 0 ;
if ( V_4 + V_5 > V_3 -> V_6 . V_4 + V_3 -> V_6 . V_7 )
return 0 ;
return 1 ;
}
static int F_4 ( struct V_1 * V_3 )
{
struct V_8 * V_9 ;
unsigned V_10 ;
V_9 = V_3 -> V_11 -> V_12 ;
V_10 = ( V_9 -> V_13 - V_9 -> V_14 - 1 ) % V_15 ;
if ( V_10 == 0 ) {
return 0 ;
}
return 1 ;
}
static int F_5 ( struct V_2 * V_16 ,
T_1 V_4 , int V_5 , const void * V_17 )
{
struct V_1 * V_3 = F_1 ( V_16 ) ;
struct V_8 * V_9 = V_3 -> V_11 -> V_12 ;
if ( ! F_3 ( V_3 , V_4 , V_5 ) )
return - V_18 ;
F_6 ( & V_3 -> V_11 -> V_19 ) ;
if ( ! F_4 ( V_3 ) ) {
F_7 ( & V_3 -> V_11 -> V_19 ) ;
return - V_18 ;
}
V_9 -> V_20 [ V_9 -> V_14 ] . V_21 = V_4 ;
V_9 -> V_20 [ V_9 -> V_14 ] . V_5 = V_5 ;
memcpy ( V_9 -> V_20 [ V_9 -> V_14 ] . V_22 , V_17 , V_5 ) ;
F_8 () ;
V_9 -> V_14 = ( V_9 -> V_14 + 1 ) % V_15 ;
F_7 ( & V_3 -> V_11 -> V_19 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_16 )
{
struct V_1 * V_3 = F_1 ( V_16 ) ;
F_10 ( & V_3 -> V_23 ) ;
F_11 ( V_3 ) ;
}
int F_12 ( struct V_11 * V_11 )
{
struct V_24 * V_24 ;
int V_25 ;
V_25 = - V_26 ;
V_24 = F_13 ( V_27 | V_28 ) ;
if ( ! V_24 )
goto V_29;
V_25 = 0 ;
V_11 -> V_12 = F_14 ( V_24 ) ;
F_15 ( & V_11 -> V_19 ) ;
F_16 ( & V_11 -> V_30 ) ;
V_29:
return V_25 ;
}
void F_17 ( struct V_11 * V_11 )
{
if ( V_11 -> V_12 )
F_18 ( ( unsigned long ) V_11 -> V_12 ) ;
}
int F_19 ( struct V_11 * V_11 ,
struct V_31 * V_6 )
{
int V_25 ;
struct V_1 * V_3 ;
V_3 = F_20 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_3 )
return - V_26 ;
F_21 ( & V_3 -> V_3 , & V_32 ) ;
V_3 -> V_11 = V_11 ;
V_3 -> V_6 = * V_6 ;
F_22 ( & V_11 -> V_33 ) ;
V_25 = F_23 ( V_11 , V_34 , V_6 -> V_4 ,
V_6 -> V_7 , & V_3 -> V_3 ) ;
if ( V_25 < 0 )
goto V_35;
F_24 ( & V_3 -> V_23 , & V_11 -> V_30 ) ;
F_25 ( & V_11 -> V_33 ) ;
return V_25 ;
V_35:
F_25 ( & V_11 -> V_33 ) ;
F_11 ( V_3 ) ;
if ( V_3 == NULL )
return - V_36 ;
return 0 ;
}
int F_26 ( struct V_11 * V_11 ,
struct V_31 * V_6 )
{
struct V_1 * V_3 , * V_37 ;
F_22 ( & V_11 -> V_33 ) ;
F_27 (dev, tmp, &kvm->coalesced_zones, list)
if ( F_3 ( V_3 , V_6 -> V_4 , V_6 -> V_7 ) ) {
F_28 ( V_11 , V_34 , & V_3 -> V_3 ) ;
F_29 ( & V_3 -> V_3 ) ;
}
F_25 ( & V_11 -> V_33 ) ;
return 0 ;
}
