static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( F_2 ( ! V_1 ) ) {
F_3 ( V_3 ) ;
return;
}
V_3 = F_4 ( V_3 , V_4 ) ;
if ( F_2 ( ! V_3 ) )
return;
F_5 ( V_3 , V_5 ) ;
F_6 ( V_1 , V_3 ) ;
}
static T_1 F_7 ( struct V_2 * * V_6 )
{
struct V_2 * V_3 = * V_6 ;
struct V_1 * V_1 ;
if ( F_2 ( V_3 -> V_7 == V_8 ) )
return V_9 ;
V_1 = F_8 ( V_3 -> V_10 ) ;
F_1 ( V_1 , V_3 ) ;
return V_11 ;
}
static struct V_1 * F_9 ( const struct V_12 * V_13 )
{
struct V_1 * V_1 ;
struct V_14 * V_14 ;
int V_15 ;
V_1 = F_10 ( sizeof( struct V_14 ) ,
& V_16 , V_13 ) ;
if ( F_11 ( V_1 ) ) {
V_15 = F_12 ( V_1 ) ;
goto error;
}
V_14 = F_13 ( V_1 ) ;
V_14 -> V_10 = F_14 ( & V_17 , V_13 -> V_18 ) ;
if ( ! V_14 -> V_10 ) {
V_15 = - V_19 ;
goto V_20;
}
if ( V_14 -> V_10 -> V_21 & V_22 ||
V_14 -> V_10 -> type != V_23 ||
F_15 ( V_14 -> V_10 ) ) {
V_15 = - V_24 ;
goto V_25;
}
V_15 = F_16 ( V_14 -> V_10 , F_7 ,
V_1 ) ;
if ( V_15 )
goto V_25;
F_17 ( V_14 -> V_10 , 1 ) ;
V_14 -> V_10 -> V_26 |= V_27 ;
return V_1 ;
V_25:
F_18 ( V_14 -> V_10 ) ;
V_20:
F_19 ( V_1 ) ;
error:
return F_20 ( V_15 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_14 * V_14 = F_13 ( V_1 ) ;
V_14 -> V_10 -> V_26 &= ~ V_27 ;
F_22 ( V_14 -> V_10 ) ;
F_17 ( V_14 -> V_10 , - 1 ) ;
F_23 () ;
F_18 ( V_14 -> V_10 ) ;
F_19 ( V_1 ) ;
}
const char * F_24 ( const struct V_1 * V_1 )
{
const struct V_14 * V_14 = F_13 ( V_1 ) ;
return V_14 -> V_10 -> V_18 ;
}
int F_25 ( const struct V_1 * V_1 )
{
const struct V_14 * V_14 = F_13 ( V_1 ) ;
return V_14 -> V_10 -> V_28 ;
}
static unsigned int F_26 ( const struct V_2 * V_3 )
{
unsigned int V_29 = V_3 -> V_30 - V_5 ;
if ( V_3 -> V_31 == F_27 ( V_32 ) )
V_29 -= V_33 ;
return V_29 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_13 ( V_1 ) ;
int V_34 = V_14 -> V_10 -> V_34 ;
int V_30 ;
if ( F_2 ( F_26 ( V_3 ) > V_34 && ! F_29 ( V_3 ) ) ) {
F_30 ( L_1 ,
F_31 ( V_1 -> V_35 ) ,
F_26 ( V_3 ) , V_34 ) ;
goto error;
}
if ( F_2 ( F_32 ( V_3 ) ) )
goto error;
V_3 -> V_10 = V_14 -> V_10 ;
V_30 = V_3 -> V_30 ;
F_33 ( V_3 ) ;
return V_30 ;
error:
F_3 ( V_3 ) ;
F_34 ( V_1 , V_36 ) ;
return 0 ;
}
struct V_1 * F_8 ( struct V_37 * V_10 )
{
if ( F_35 ( V_10 -> V_26 & V_27 ) )
return (struct V_1 * )
F_36 ( V_10 -> V_38 ) ;
else
return NULL ;
}
