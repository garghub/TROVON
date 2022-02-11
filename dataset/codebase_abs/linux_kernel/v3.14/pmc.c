void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
F_3 () ;
}
int F_4 ( struct V_3 * V_4 , const char * V_5 ,
struct V_6 * V_7 )
{
T_1 V_8 , V_9 ;
int V_10 ;
V_10 = F_5 ( V_4 , V_5 , 0 , & V_8 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_5 ( V_4 , V_5 , 1 , & V_9 ) ;
if ( V_10 )
return V_10 ;
if ( V_7 ) {
V_7 -> V_8 = V_8 ;
V_7 -> V_9 = V_9 ;
}
return 0 ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
F_8 ( V_14 , V_15 , 1 << V_12 -> V_16 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
F_8 ( V_14 , V_17 , 1 << V_12 -> V_16 ) ;
}
static int F_10 ( struct V_11 * V_12 , unsigned type )
{
if ( type != V_18 ) {
F_11 ( L_1 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , unsigned int V_22 ,
T_2 V_23 )
{
struct V_13 * V_14 = V_21 -> V_24 ;
F_13 ( V_22 , & V_25 ) ;
F_14 ( V_22 , & V_26 ,
V_27 ) ;
F_15 ( V_22 , V_28 ) ;
F_16 ( V_22 , V_14 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_12 ,
struct V_3 * V_29 ,
const T_1 * V_30 , unsigned int V_31 ,
T_2 * V_32 ,
unsigned int * V_33 )
{
struct V_13 * V_14 = V_12 -> V_24 ;
const struct V_34 * V_35 = V_14 -> V_35 ;
if ( F_18 ( V_31 < 1 ) )
return - V_19 ;
* V_32 = V_30 [ 0 ] ;
if ( ! ( V_35 -> V_36 & ( 1 << * V_32 ) ) )
return - V_19 ;
* V_33 = V_18 ;
return 0 ;
}
static T_3 F_19 ( int V_37 , void * V_38 )
{
struct V_13 * V_14 = (struct V_13 * ) V_38 ;
unsigned long V_39 ;
int V_40 ;
V_39 = F_20 ( V_14 , V_41 ) & F_20 ( V_14 , V_42 ) ;
if ( ! V_39 )
return V_43 ;
F_21 (n, &sr, BITS_PER_LONG)
F_22 ( F_23 ( V_14 -> V_44 , V_40 ) ) ;
return V_45 ;
}
static struct V_13 * T_4 F_24 ( struct V_3 * V_4 ,
void T_5 * V_46 , int V_22 ,
const struct V_34 * V_35 )
{
struct V_13 * V_14 ;
if ( ! V_46 || ! V_22 || ! V_35 )
return NULL ;
V_47 = V_46 ;
V_14 = F_25 ( sizeof( * V_14 ) , V_48 ) ;
if ( ! V_14 )
return NULL ;
F_26 ( & V_14 -> V_49 ) ;
V_14 -> V_46 = V_46 ;
V_14 -> V_22 = V_22 ;
V_14 -> V_35 = V_35 ;
V_14 -> V_44 = F_27 ( V_4 , 32 , & V_50 , V_14 ) ;
if ( ! V_14 -> V_44 )
goto V_51;
F_8 ( V_14 , V_15 , 0xffffffff ) ;
if ( F_28 ( V_14 -> V_22 , F_19 , V_52 , L_2 , V_14 ) )
goto V_53;
return V_14 ;
V_53:
F_29 ( V_14 -> V_44 ) ;
V_51:
F_30 ( V_14 ) ;
return NULL ;
}
static void T_4 F_31 ( struct V_3 * V_4 ,
const struct V_34 * V_35 )
{
struct V_13 * V_14 ;
struct V_3 * V_54 ;
void (* F_32)( struct V_3 * , struct V_13 * );
const struct V_55 * V_56 ;
void T_5 * V_46 = F_33 ( V_4 , 0 ) ;
int V_22 ;
if ( ! V_46 )
return;
V_22 = F_34 ( V_4 , 0 ) ;
if ( ! V_22 )
return;
V_14 = F_24 ( V_4 , V_46 , V_22 , V_35 ) ;
if ( ! V_14 )
return;
F_35 (np, childnp) {
V_56 = F_36 ( V_57 , V_54 ) ;
if ( ! V_56 )
continue;
F_32 = V_56 -> V_38 ;
F_32 ( V_54 , V_14 ) ;
}
}
static void T_4 F_37 ( struct V_3 * V_4 )
{
F_31 ( V_4 , & V_58 ) ;
}
static void T_4 F_38 ( struct V_3 * V_4 )
{
F_31 ( V_4 , & V_59 ) ;
}
static void T_4 F_39 ( struct V_3 * V_4 )
{
F_31 ( V_4 , & V_60 ) ;
}
static void T_4 F_40 ( struct V_3 * V_4 )
{
F_31 ( V_4 , & V_61 ) ;
}
static void T_4 F_41 ( struct V_3 * V_4 )
{
F_31 ( V_4 , & V_62 ) ;
}
static void T_4 F_42 ( struct V_3 * V_4 )
{
F_31 ( V_4 , & V_63 ) ;
}
