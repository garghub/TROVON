static inline void * F_1 ( void * V_1 , unsigned int V_2 )
{
return ( void * ) F_2 ( ( unsigned long ) V_1 , V_2 ) ;
}
static inline struct V_3 * V_3 ( struct V_4 * V_5 )
{
return F_1 ( F_3 ( V_5 ) +
F_4 ( V_5 ) * 2 ,
F_5 () ) ;
}
static int F_6 ( struct V_4 * V_6 ,
const T_1 * V_7 , unsigned int V_8 )
{
int V_9 = F_7 ( V_6 ) ;
int V_10 = F_8 ( V_6 ) ;
int V_11 = F_4 ( V_6 ) ;
char * V_12 = F_3 ( V_6 ) ;
char * V_13 = V_12 + V_11 ;
struct V_3 * V_14 = F_1 ( V_13 + V_11 ,
F_5 () ) ;
struct V_4 * V_15 = V_14 -> V_15 ;
struct {
struct V_16 V_17 ;
char V_14 [ F_9 ( V_15 ) ] ;
} V_18 ;
unsigned int V_19 ;
V_18 . V_17 . V_5 = V_15 ;
V_18 . V_17 . V_20 = F_10 ( V_6 ) &
V_21 ;
if ( V_8 > V_9 ) {
int V_22 ;
V_22 = F_11 ( & V_18 . V_17 , V_7 , V_8 , V_12 ) ;
if ( V_22 )
return V_22 ;
V_8 = V_10 ;
} else
memcpy ( V_12 , V_7 , V_8 ) ;
memset ( V_12 + V_8 , 0 , V_9 - V_8 ) ;
memcpy ( V_13 , V_12 , V_9 ) ;
for ( V_19 = 0 ; V_19 < V_9 ; V_19 ++ ) {
V_12 [ V_19 ] ^= 0x36 ;
V_13 [ V_19 ] ^= 0x5c ;
}
return F_12 ( & V_18 . V_17 ) ? :
F_13 ( & V_18 . V_17 , V_12 , V_9 ) ? :
F_14 ( & V_18 . V_17 , V_12 ) ? :
F_12 ( & V_18 . V_17 ) ? :
F_13 ( & V_18 . V_17 , V_13 , V_9 ) ? :
F_14 ( & V_18 . V_17 , V_13 ) ;
}
static int F_15 ( struct V_16 * V_23 , void * V_24 )
{
struct V_16 * V_18 = F_16 ( V_23 ) ;
V_18 -> V_20 = V_23 -> V_20 & V_21 ;
return F_14 ( V_18 , V_24 ) ;
}
static int F_17 ( struct V_16 * V_23 , const void * V_25 )
{
struct V_16 * V_18 = F_16 ( V_23 ) ;
struct V_3 * V_14 = V_3 ( V_23 -> V_5 ) ;
V_18 -> V_5 = V_14 -> V_15 ;
V_18 -> V_20 = V_23 -> V_20 & V_21 ;
return F_18 ( V_18 , V_25 ) ;
}
static int F_19 ( struct V_16 * V_23 )
{
return F_17 ( V_23 , F_3 ( V_23 -> V_5 ) ) ;
}
static int F_20 ( struct V_16 * V_23 ,
const T_1 * V_26 , unsigned int V_27 )
{
struct V_16 * V_18 = F_16 ( V_23 ) ;
V_18 -> V_20 = V_23 -> V_20 & V_21 ;
return F_13 ( V_18 , V_26 , V_27 ) ;
}
static int F_21 ( struct V_16 * V_23 , T_1 * V_24 )
{
struct V_4 * V_6 = V_23 -> V_5 ;
int V_10 = F_8 ( V_6 ) ;
int V_11 = F_4 ( V_6 ) ;
char * V_13 = F_3 ( V_6 ) + V_11 ;
struct V_16 * V_18 = F_16 ( V_23 ) ;
V_18 -> V_20 = V_23 -> V_20 & V_21 ;
return F_22 ( V_18 , V_24 ) ? :
F_18 ( V_18 , V_13 ) ? :
F_23 ( V_18 , V_24 , V_10 , V_24 ) ;
}
static int F_24 ( struct V_16 * V_23 , const T_1 * V_26 ,
unsigned int V_27 , T_1 * V_24 )
{
struct V_4 * V_6 = V_23 -> V_5 ;
int V_10 = F_8 ( V_6 ) ;
int V_11 = F_4 ( V_6 ) ;
char * V_13 = F_3 ( V_6 ) + V_11 ;
struct V_16 * V_18 = F_16 ( V_23 ) ;
V_18 -> V_20 = V_23 -> V_20 & V_21 ;
return F_23 ( V_18 , V_26 , V_27 , V_24 ) ? :
F_18 ( V_18 , V_13 ) ? :
F_23 ( V_18 , V_24 , V_10 , V_24 ) ;
}
static int F_25 ( struct V_28 * V_5 )
{
struct V_4 * V_6 = F_26 ( V_5 ) ;
struct V_4 * V_15 ;
struct V_29 * V_30 = ( void * ) V_5 -> V_31 ;
struct V_32 * V_33 = F_27 ( V_30 ) ;
struct V_3 * V_14 = V_3 ( V_6 ) ;
V_15 = F_28 ( V_33 ) ;
if ( F_29 ( V_15 ) )
return F_30 ( V_15 ) ;
V_6 -> V_34 = sizeof( struct V_16 ) +
F_9 ( V_15 ) ;
V_14 -> V_15 = V_15 ;
return 0 ;
}
static void F_31 ( struct V_28 * V_5 )
{
struct V_3 * V_14 = V_3 ( F_26 ( V_5 ) ) ;
F_32 ( V_14 -> V_15 ) ;
}
static int F_33 ( struct V_35 * V_36 , struct V_37 * * V_38 )
{
struct V_39 * V_30 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_22 ;
int V_10 ;
int V_11 ;
V_22 = F_34 ( V_38 , V_44 ) ;
if ( V_22 )
return V_22 ;
V_43 = F_35 ( V_38 [ 1 ] , 0 , 0 ) ;
if ( F_29 ( V_43 ) )
return F_30 ( V_43 ) ;
V_22 = - V_45 ;
V_10 = V_43 -> V_46 ;
V_11 = V_43 -> V_47 ;
V_41 = & V_43 -> V_48 ;
if ( V_10 > V_41 -> V_49 ||
V_11 < V_41 -> V_49 )
goto V_50;
V_30 = F_36 ( L_1 , V_41 ) ;
V_22 = F_30 ( V_30 ) ;
if ( F_29 ( V_30 ) )
goto V_50;
V_22 = F_37 ( F_38 ( V_30 ) , V_43 ,
F_39 ( V_30 ) ) ;
if ( V_22 )
goto V_51;
V_30 -> V_41 . V_48 . V_52 = V_41 -> V_52 ;
V_30 -> V_41 . V_48 . V_49 = V_41 -> V_49 ;
V_30 -> V_41 . V_48 . V_53 = V_41 -> V_53 ;
V_11 = F_2 ( V_11 , V_41 -> V_53 + 1 ) ;
V_30 -> V_41 . V_46 = V_10 ;
V_30 -> V_41 . V_47 = V_11 ;
V_30 -> V_41 . V_48 . V_54 = sizeof( struct V_3 ) +
F_2 ( V_11 * 2 , F_5 () ) ;
V_30 -> V_41 . V_48 . V_55 = F_25 ;
V_30 -> V_41 . V_48 . V_56 = F_31 ;
V_30 -> V_41 . V_57 = F_19 ;
V_30 -> V_41 . V_58 = F_20 ;
V_30 -> V_41 . V_59 = F_21 ;
V_30 -> V_41 . V_60 = F_24 ;
V_30 -> V_41 . V_61 = F_15 ;
V_30 -> V_41 . V_62 = F_17 ;
V_30 -> V_41 . V_63 = F_6 ;
V_22 = F_40 ( V_36 , V_30 ) ;
if ( V_22 ) {
V_51:
F_41 ( F_39 ( V_30 ) ) ;
}
V_50:
F_42 ( V_41 ) ;
return V_22 ;
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_64 ) ;
}
static void T_3 F_45 ( void )
{
F_46 ( & V_64 ) ;
}
