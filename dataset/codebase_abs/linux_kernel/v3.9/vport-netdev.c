static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( F_2 ( ! V_1 ) )
goto error;
if ( F_2 ( F_3 ( V_3 ) ) )
goto error;
V_3 = F_4 ( V_3 , V_4 ) ;
if ( F_2 ( ! V_3 ) )
return;
F_5 ( V_3 , V_5 ) ;
F_6 ( V_1 , V_3 ) ;
return;
error:
F_7 ( V_3 ) ;
}
static T_1 F_8 ( struct V_2 * * V_6 )
{
struct V_2 * V_3 = * V_6 ;
struct V_1 * V_1 ;
if ( F_2 ( V_3 -> V_7 == V_8 ) )
return V_9 ;
V_1 = F_9 ( V_3 -> V_10 ) ;
F_1 ( V_1 , V_3 ) ;
return V_11 ;
}
static struct V_1 * F_10 ( const struct V_12 * V_13 )
{
struct V_1 * V_1 ;
struct V_14 * V_14 ;
int V_15 ;
V_1 = F_11 ( sizeof( struct V_14 ) ,
& V_16 , V_13 ) ;
if ( F_12 ( V_1 ) ) {
V_15 = F_13 ( V_1 ) ;
goto error;
}
V_14 = F_14 ( V_1 ) ;
V_14 -> V_10 = F_15 ( F_16 ( V_1 -> V_17 ) , V_13 -> V_18 ) ;
if ( ! V_14 -> V_10 ) {
V_15 = - V_19 ;
goto V_20;
}
if ( V_14 -> V_10 -> V_21 & V_22 ||
V_14 -> V_10 -> type != V_23 ||
F_17 ( V_14 -> V_10 ) ) {
V_15 = - V_24 ;
goto V_25;
}
V_15 = F_18 ( V_14 -> V_10 , F_8 ,
V_1 ) ;
if ( V_15 )
goto V_25;
F_19 ( V_14 -> V_10 , 1 ) ;
V_14 -> V_10 -> V_26 |= V_27 ;
return V_1 ;
V_25:
F_20 ( V_14 -> V_10 ) ;
V_20:
F_21 ( V_1 ) ;
error:
return F_22 ( V_15 ) ;
}
static void F_23 ( struct V_28 * V_29 )
{
struct V_14 * V_14 = F_24 ( V_29 ,
struct V_14 , V_29 ) ;
F_20 ( V_14 -> V_10 ) ;
F_21 ( F_25 ( V_14 ) ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_14 * V_14 = F_14 ( V_1 ) ;
V_14 -> V_10 -> V_26 &= ~ V_27 ;
F_27 ( V_14 -> V_10 ) ;
F_19 ( V_14 -> V_10 , - 1 ) ;
F_28 ( & V_14 -> V_29 , F_23 ) ;
}
const char * F_29 ( const struct V_1 * V_1 )
{
const struct V_14 * V_14 = F_14 ( V_1 ) ;
return V_14 -> V_10 -> V_18 ;
}
int F_30 ( const struct V_1 * V_1 )
{
const struct V_14 * V_14 = F_14 ( V_1 ) ;
return V_14 -> V_10 -> V_30 ;
}
static unsigned int F_31 ( const struct V_2 * V_3 )
{
unsigned int V_31 = V_3 -> V_32 - V_5 ;
if ( V_3 -> V_33 == F_32 ( V_34 ) )
V_31 -= V_35 ;
return V_31 ;
}
static int F_33 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_14 ( V_1 ) ;
int V_36 = V_14 -> V_10 -> V_36 ;
int V_32 ;
if ( F_2 ( F_31 ( V_3 ) > V_36 && ! F_34 ( V_3 ) ) ) {
F_35 ( L_1 ,
V_14 -> V_10 -> V_18 ,
F_31 ( V_3 ) , V_36 ) ;
goto error;
}
V_3 -> V_10 = V_14 -> V_10 ;
V_32 = V_3 -> V_32 ;
F_36 ( V_3 ) ;
return V_32 ;
error:
F_7 ( V_3 ) ;
F_37 ( V_1 , V_37 ) ;
return 0 ;
}
struct V_1 * F_9 ( struct V_38 * V_10 )
{
if ( F_38 ( V_10 -> V_26 & V_27 ) )
return (struct V_1 * )
F_39 ( V_10 -> V_39 ) ;
else
return NULL ;
}
