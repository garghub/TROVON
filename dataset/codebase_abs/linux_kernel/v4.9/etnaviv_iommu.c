static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
T_1 V_6 )
{
V_5 -> V_5 = F_4 ( NULL , V_6 , & V_5 -> V_7 , V_8 ) ;
if ( ! V_5 -> V_5 )
return - V_9 ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 ,
T_1 V_6 )
{
F_6 ( NULL , V_6 , V_5 -> V_5 , V_5 -> V_7 ) ;
}
static T_2 F_7 ( struct V_4 * V_5 ,
unsigned long V_10 )
{
unsigned int V_11 = ( V_10 - V_12 ) / V_13 ;
T_3 V_7 ;
V_7 = V_5 -> V_5 [ V_11 ] ;
return V_7 ;
}
static void F_8 ( struct V_4 * V_5 ,
unsigned long V_10 , T_3 V_7 )
{
unsigned int V_11 = ( V_10 - V_12 ) / V_13 ;
V_5 -> V_5 [ V_11 ] = V_7 ;
}
static int F_9 ( struct V_1 * V_14 )
{
T_2 * V_15 ;
int V_16 , V_17 ;
V_14 -> V_18 = F_4 ( V_14 -> V_19 ,
V_13 ,
& V_14 -> V_20 ,
V_8 ) ;
if ( ! V_14 -> V_18 )
return - V_9 ;
V_15 = V_14 -> V_18 ;
for ( V_17 = 0 ; V_17 < V_13 / 4 ; V_17 ++ )
* V_15 ++ = 0xdead55aa ;
V_16 = F_3 ( & V_14 -> V_5 , V_21 ) ;
if ( V_16 < 0 ) {
F_6 ( V_14 -> V_19 , V_13 ,
V_14 -> V_18 ,
V_14 -> V_20 ) ;
return V_16 ;
}
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ )
V_14 -> V_5 . V_5 [ V_17 ] =
V_14 -> V_20 ;
F_10 ( & V_14 -> V_23 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_5 ( & V_14 -> V_5 , V_21 ) ;
F_6 ( V_14 -> V_19 , V_13 ,
V_14 -> V_18 ,
V_14 -> V_20 ) ;
F_12 ( V_14 ) ;
}
static int F_13 ( struct V_2 * V_3 , unsigned long V_10 ,
T_3 V_7 , T_1 V_6 , int V_24 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_6 != V_13 )
return - V_25 ;
F_14 ( & V_14 -> V_23 ) ;
F_8 ( & V_14 -> V_5 , V_10 , V_7 ) ;
F_15 ( & V_14 -> V_23 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_2 * V_3 ,
unsigned long V_10 , T_1 V_6 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_6 != V_13 )
return - V_25 ;
F_14 ( & V_14 -> V_23 ) ;
F_8 ( & V_14 -> V_5 , V_10 ,
V_14 -> V_20 ) ;
F_15 ( & V_14 -> V_23 ) ;
return V_13 ;
}
static T_3 F_17 ( struct V_2 * V_3 ,
T_4 V_10 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
return F_7 ( & V_14 -> V_5 , V_10 ) ;
}
static T_1 F_18 ( struct V_2 * V_3 )
{
return V_21 ;
}
static void F_19 ( struct V_2 * V_3 , void * V_26 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
memcpy ( V_26 , V_14 -> V_5 . V_5 , V_21 ) ;
}
void F_20 ( struct V_27 * V_28 )
{
struct V_1 * V_14 =
F_1 ( V_28 -> V_29 -> V_3 ) ;
T_2 V_5 ;
F_21 ( V_28 , V_30 , V_28 -> V_31 ) ;
F_21 ( V_28 , V_32 , V_28 -> V_31 ) ;
F_21 ( V_28 , V_33 , V_28 -> V_31 ) ;
F_21 ( V_28 , V_34 , V_28 -> V_31 ) ;
F_21 ( V_28 , V_35 , V_28 -> V_31 ) ;
V_5 = ( T_2 ) V_14 -> V_5 . V_7 ;
F_21 ( V_28 , V_36 , V_5 ) ;
F_21 ( V_28 , V_37 , V_5 ) ;
F_21 ( V_28 , V_38 , V_5 ) ;
F_21 ( V_28 , V_39 , V_5 ) ;
F_21 ( V_28 , V_40 , V_5 ) ;
}
struct V_2 * F_22 ( struct V_27 * V_28 )
{
struct V_1 * V_14 ;
int V_16 ;
V_14 = F_23 ( sizeof( * V_14 ) , V_8 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_19 = V_28 -> V_19 ;
V_14 -> V_3 . type = V_41 ;
V_14 -> V_3 . V_42 = & V_43 . V_42 ;
V_14 -> V_3 . V_44 = V_13 ;
V_14 -> V_3 . V_45 . V_46 = V_12 ;
V_14 -> V_3 . V_45 . V_47 = V_12 + V_22 * V_13 - 1 ;
V_16 = F_9 ( V_14 ) ;
if ( V_16 )
goto V_48;
return & V_14 -> V_3 ;
V_48:
F_12 ( V_14 ) ;
return NULL ;
}
