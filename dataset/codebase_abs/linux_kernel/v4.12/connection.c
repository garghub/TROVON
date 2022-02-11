struct V_1 *
F_1 ( struct V_2 V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_7 , * V_8 ;
V_7 = F_2 ( V_9 , & V_3 ) ;
if ( V_7 )
goto V_10;
V_7 = F_3 ( sizeof( * V_7 ) , V_11 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_12 = V_3 ;
V_7 -> V_13 = V_4 ;
F_4 ( & V_7 -> V_14 ) ;
F_5 ( & V_7 -> V_15 , 1 ) ;
if ( V_6 )
F_6 ( & V_7 -> V_16 , V_6 -> V_6 ) ;
V_8 = F_7 ( V_9 , & V_3 , & V_7 -> V_14 ) ;
if ( V_7 != V_8 ) {
F_8 ( V_7 ) ;
V_7 = V_8 ;
}
V_10:
F_9 ( V_17 , L_1 ,
V_7 , F_10 ( & V_7 -> V_15 ) ,
F_11 ( V_7 -> V_12 . V_18 ) ) ;
return V_7 ;
}
int F_12 ( struct V_1 * V_7 )
{
int V_19 = 0 ;
if ( ! V_7 )
return V_19 ;
F_13 ( F_10 ( & V_7 -> V_15 ) > 1 ) ;
if ( F_14 ( & V_7 -> V_15 ) == 1 )
V_19 = 1 ;
F_9 ( V_17 , L_2 ,
V_7 , F_10 ( & V_7 -> V_15 ) ,
F_11 ( V_7 -> V_12 . V_18 ) ) ;
return V_19 ;
}
struct V_1 *
F_15 ( struct V_1 * V_7 )
{
F_16 ( & V_7 -> V_15 ) ;
F_9 ( V_17 , L_1 ,
V_7 , F_10 ( & V_7 -> V_15 ) ,
F_11 ( V_7 -> V_12 . V_18 ) ) ;
return V_7 ;
}
int F_17 ( void )
{
V_9 = F_18 ( L_3 ,
V_20 ,
V_21 ,
V_22 , 0 ,
V_23 ,
V_24 ,
& V_25 , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
return 0 ;
}
void F_19 ( void )
{
F_20 ( V_9 ) ;
}
static unsigned int
F_21 ( struct V_28 * V_29 , const void * V_30 , unsigned int V_31 )
{
return F_22 ( V_30 , sizeof( struct V_2 ) , V_31 ) ;
}
static int
F_23 ( const void * V_30 , struct V_32 * V_33 )
{
struct V_1 * V_7 ;
const struct V_2 * V_34 ;
F_13 ( V_30 ) ;
V_34 = V_30 ;
V_7 = F_24 ( V_33 , struct V_1 , V_14 ) ;
return V_34 -> V_18 == V_7 -> V_12 . V_18 &&
V_34 -> V_35 == V_7 -> V_12 . V_35 ;
}
static void *
V_34 ( struct V_32 * V_33 )
{
struct V_1 * V_7 ;
V_7 = F_24 ( V_33 , struct V_1 , V_14 ) ;
return & V_7 -> V_12 ;
}
static void *
F_25 ( struct V_32 * V_33 )
{
return F_24 ( V_33 , struct V_1 , V_14 ) ;
}
static void
F_26 ( struct V_28 * V_29 , struct V_32 * V_33 )
{
struct V_1 * V_7 ;
V_7 = F_24 ( V_33 , struct V_1 , V_14 ) ;
F_16 ( & V_7 -> V_15 ) ;
}
static void
F_27 ( struct V_28 * V_29 , struct V_32 * V_33 )
{
struct V_1 * V_7 ;
V_7 = F_24 ( V_33 , struct V_1 , V_14 ) ;
F_28 ( & V_7 -> V_15 ) ;
}
static void
F_29 ( struct V_28 * V_29 , struct V_32 * V_33 )
{
struct V_1 * V_7 ;
V_7 = F_24 ( V_33 , struct V_1 , V_14 ) ;
F_30 ( F_10 ( & V_7 -> V_15 ) == 0 ,
L_4 ,
F_10 ( & V_7 -> V_15 ) ) ;
F_8 ( V_7 ) ;
}
