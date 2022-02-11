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
F_6 ( V_3 , V_3 -> V_6 , V_5 ) ;
F_7 ( V_1 , V_3 , NULL ) ;
return;
error:
F_8 ( V_3 ) ;
}
static T_1 F_9 ( struct V_2 * * V_7 )
{
struct V_2 * V_3 = * V_7 ;
struct V_1 * V_1 ;
if ( F_2 ( V_3 -> V_8 == V_9 ) )
return V_10 ;
V_1 = F_10 ( V_3 -> V_11 ) ;
F_1 ( V_1 , V_3 ) ;
return V_12 ;
}
static struct V_1 * F_11 ( const struct V_13 * V_14 )
{
struct V_1 * V_1 ;
struct V_15 * V_15 ;
int V_16 ;
V_1 = F_12 ( sizeof( struct V_15 ) ,
& V_17 , V_14 ) ;
if ( F_13 ( V_1 ) ) {
V_16 = F_14 ( V_1 ) ;
goto error;
}
V_15 = F_15 ( V_1 ) ;
V_15 -> V_11 = F_16 ( F_17 ( V_1 -> V_18 ) , V_14 -> V_19 ) ;
if ( ! V_15 -> V_11 ) {
V_16 = - V_20 ;
goto V_21;
}
if ( V_15 -> V_11 -> V_22 & V_23 ||
V_15 -> V_11 -> type != V_24 ||
F_18 ( V_15 -> V_11 ) ) {
V_16 = - V_25 ;
goto V_26;
}
F_19 () ;
V_16 = F_20 ( V_15 -> V_11 , F_9 ,
V_1 ) ;
if ( V_16 )
goto V_27;
F_21 ( V_15 -> V_11 , 1 ) ;
V_15 -> V_11 -> V_28 |= V_29 ;
F_22 () ;
return V_1 ;
V_27:
F_22 () ;
V_26:
F_23 ( V_15 -> V_11 ) ;
V_21:
F_24 ( V_1 ) ;
error:
return F_25 ( V_16 ) ;
}
static void F_26 ( struct V_30 * V_31 )
{
struct V_15 * V_15 = F_27 ( V_31 ,
struct V_15 , V_31 ) ;
F_23 ( V_15 -> V_11 ) ;
F_24 ( F_28 ( V_15 ) ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = F_15 ( V_1 ) ;
F_19 () ;
V_15 -> V_11 -> V_28 &= ~ V_29 ;
F_30 ( V_15 -> V_11 ) ;
F_21 ( V_15 -> V_11 , - 1 ) ;
F_22 () ;
F_31 ( & V_15 -> V_31 , F_26 ) ;
}
const char * F_32 ( const struct V_1 * V_1 )
{
const struct V_15 * V_15 = F_15 ( V_1 ) ;
return V_15 -> V_11 -> V_19 ;
}
static unsigned int F_33 ( const struct V_2 * V_3 )
{
unsigned int V_32 = V_3 -> V_33 - V_5 ;
if ( V_3 -> V_34 == F_34 ( V_35 ) )
V_32 -= V_36 ;
return V_32 ;
}
static int F_35 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_15 * V_15 = F_15 ( V_1 ) ;
int V_37 = V_15 -> V_11 -> V_37 ;
int V_33 ;
if ( F_2 ( F_33 ( V_3 ) > V_37 && ! F_36 ( V_3 ) ) ) {
F_37 ( L_1 ,
V_15 -> V_11 -> V_19 ,
F_33 ( V_3 ) , V_37 ) ;
goto V_38;
}
V_3 -> V_11 = V_15 -> V_11 ;
V_33 = V_3 -> V_33 ;
F_38 ( V_3 ) ;
return V_33 ;
V_38:
F_8 ( V_3 ) ;
return 0 ;
}
struct V_1 * F_10 ( struct V_39 * V_11 )
{
if ( F_39 ( V_11 -> V_28 & V_29 ) )
return (struct V_1 * )
F_40 ( V_11 -> V_40 ) ;
else
return NULL ;
}
