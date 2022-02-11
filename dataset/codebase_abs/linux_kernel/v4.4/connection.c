struct V_1 *
F_1 ( T_1 V_2 , T_2 V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 , * V_7 ;
V_6 = F_2 ( V_8 , & V_2 ) ;
if ( V_6 )
goto V_9;
V_6 = F_3 ( sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_11 = V_2 ;
V_6 -> V_12 = V_3 ;
F_4 ( & V_6 -> V_13 ) ;
F_5 ( & V_6 -> V_14 , 1 ) ;
if ( V_5 )
F_6 ( & V_6 -> V_15 , V_5 -> V_5 ) ;
V_7 = F_7 ( V_8 , & V_2 , & V_6 -> V_13 ) ;
if ( V_6 != V_7 ) {
F_8 ( V_6 ) ;
V_6 = V_7 ;
}
V_9:
F_9 ( V_16 , L_1 ,
V_6 , F_10 ( & V_6 -> V_14 ) ,
F_11 ( V_6 -> V_11 . V_17 ) ) ;
return V_6 ;
}
int F_12 ( struct V_1 * V_6 )
{
int V_18 = 0 ;
if ( ! V_6 )
return V_18 ;
F_13 ( F_10 ( & V_6 -> V_14 ) > 1 ) ;
if ( F_14 ( & V_6 -> V_14 ) == 1 )
V_18 = 1 ;
F_9 ( V_16 , L_2 ,
V_6 , F_10 ( & V_6 -> V_14 ) ,
F_11 ( V_6 -> V_11 . V_17 ) ) ;
return V_18 ;
}
struct V_1 *
F_15 ( struct V_1 * V_6 )
{
F_16 ( & V_6 -> V_14 ) ;
F_9 ( V_16 , L_1 ,
V_6 , F_10 ( & V_6 -> V_14 ) ,
F_11 ( V_6 -> V_11 . V_17 ) ) ;
return V_6 ;
}
int F_17 ( void )
{
V_8 = F_18 ( L_3 ,
V_19 ,
V_20 ,
V_21 , 0 ,
V_22 ,
V_23 ,
& V_24 , V_25 ) ;
if ( ! V_8 )
return - V_26 ;
return 0 ;
}
void F_19 ( void )
{
F_20 ( V_8 ) ;
}
static unsigned
F_21 ( struct V_27 * V_28 , const void * V_29 , unsigned V_30 )
{
return F_22 ( V_29 , sizeof( T_1 ) , V_30 ) ;
}
static int
F_23 ( const void * V_29 , struct V_31 * V_32 )
{
struct V_1 * V_6 ;
const T_1 * V_33 ;
F_13 ( V_29 != NULL ) ;
V_33 = V_29 ;
V_6 = F_24 ( V_32 , struct V_1 , V_13 ) ;
return V_33 -> V_17 == V_6 -> V_11 . V_17 &&
V_33 -> V_34 == V_6 -> V_11 . V_34 ;
}
static void *
V_33 ( struct V_31 * V_32 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( V_32 , struct V_1 , V_13 ) ;
return & V_6 -> V_11 ;
}
static void *
F_25 ( struct V_31 * V_32 )
{
return F_24 ( V_32 , struct V_1 , V_13 ) ;
}
static void
F_26 ( struct V_27 * V_28 , struct V_31 * V_32 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( V_32 , struct V_1 , V_13 ) ;
F_16 ( & V_6 -> V_14 ) ;
}
static void
F_27 ( struct V_27 * V_28 , struct V_31 * V_32 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( V_32 , struct V_1 , V_13 ) ;
F_28 ( & V_6 -> V_14 ) ;
}
static void
F_29 ( struct V_27 * V_28 , struct V_31 * V_32 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( V_32 , struct V_1 , V_13 ) ;
F_30 ( F_10 ( & V_6 -> V_14 ) == 0 ,
L_4 ,
F_10 ( & V_6 -> V_14 ) ) ;
F_8 ( V_6 ) ;
}
