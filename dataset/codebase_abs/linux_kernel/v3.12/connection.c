struct V_1 *
F_1 ( T_1 V_2 , T_2 V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 , * V_7 ;
V_6 = F_2 ( V_8 , & V_2 ) ;
if ( V_6 )
GOTO ( V_9 , V_6 ) ;
F_3 ( V_6 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_10 = V_2 ;
V_6 -> V_11 = V_3 ;
F_4 ( & V_6 -> V_12 ) ;
F_5 ( & V_6 -> V_13 , 1 ) ;
if ( V_5 )
F_6 ( & V_6 -> V_14 , V_5 -> V_5 ) ;
V_7 = F_7 ( V_8 , & V_2 , & V_6 -> V_12 ) ;
if ( V_6 != V_7 ) {
F_8 ( V_6 ) ;
V_6 = V_7 ;
}
V_9:
F_9 ( V_15 , L_1 ,
V_6 , F_10 ( & V_6 -> V_13 ) ,
F_11 ( V_6 -> V_10 . V_16 ) ) ;
return V_6 ;
}
int F_12 ( struct V_1 * V_6 )
{
int V_17 = 0 ;
if ( ! V_6 )
return V_17 ;
F_13 ( F_10 ( & V_6 -> V_13 ) > 1 ) ;
if ( F_14 ( & V_6 -> V_13 ) == 1 )
V_17 = 1 ;
F_9 ( V_15 , L_2 ,
V_6 , F_10 ( & V_6 -> V_13 ) ,
F_11 ( V_6 -> V_10 . V_16 ) ) ;
return V_17 ;
}
struct V_1 *
F_15 ( struct V_1 * V_6 )
{
F_16 ( & V_6 -> V_13 ) ;
F_9 ( V_15 , L_1 ,
V_6 , F_10 ( & V_6 -> V_13 ) ,
F_11 ( V_6 -> V_10 . V_16 ) ) ;
return V_6 ;
}
int F_17 ( void )
{
V_8 = F_18 ( L_3 ,
V_18 ,
V_19 ,
V_20 , 0 ,
V_21 ,
V_22 ,
& V_23 , V_24 ) ;
if ( ! V_8 )
return - V_25 ;
return 0 ;
}
void F_19 ( void )
{
F_20 ( V_8 ) ;
}
static unsigned
F_21 ( T_3 * V_26 , const void * V_27 , unsigned V_28 )
{
return F_22 ( V_27 , sizeof( T_1 ) , V_28 ) ;
}
static int
F_23 ( const void * V_27 , struct V_29 * V_30 )
{
struct V_1 * V_6 ;
const T_1 * V_31 ;
F_13 ( V_27 != NULL ) ;
V_31 = ( T_1 * ) V_27 ;
V_6 = F_24 ( V_30 , struct V_1 , V_12 ) ;
return V_31 -> V_16 == V_6 -> V_10 . V_16 &&
V_31 -> V_32 == V_6 -> V_10 . V_32 ;
}
static void *
V_31 ( struct V_29 * V_30 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( V_30 , struct V_1 , V_12 ) ;
return & V_6 -> V_10 ;
}
static void *
F_25 ( struct V_29 * V_30 )
{
return F_24 ( V_30 , struct V_1 , V_12 ) ;
}
static void
F_26 ( T_3 * V_26 , struct V_29 * V_30 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( V_30 , struct V_1 , V_12 ) ;
F_16 ( & V_6 -> V_13 ) ;
}
static void
F_27 ( T_3 * V_26 , struct V_29 * V_30 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( V_30 , struct V_1 , V_12 ) ;
F_28 ( & V_6 -> V_13 ) ;
}
static void
F_29 ( T_3 * V_26 , struct V_29 * V_30 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( V_30 , struct V_1 , V_12 ) ;
F_30 ( F_10 ( & V_6 -> V_13 ) == 0 ,
L_4 ,
F_10 ( & V_6 -> V_13 ) ) ;
F_8 ( V_6 ) ;
}
