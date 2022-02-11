static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_3 ( V_8 , V_10 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_10 ) ;
V_9 = F_6 ( V_8 , V_3 , V_4 ) ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_11 ) ;
return V_9 ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_14 * V_16 ,
unsigned int V_17 ,
unsigned int V_18 )
{
int V_19 = F_10 ( V_13 -> V_20 ) ;
T_1 V_21 [ V_19 ] , V_22 [ V_19 ] ;
struct V_12 V_23 ;
struct V_14 V_24 [ 1 ] , V_25 [ 1 ] ;
int V_26 = V_18 - V_19 ;
T_1 V_27 [ V_19 ] ;
T_1 V_28 [ V_19 * 2 ] , V_29 [ V_19 * 2 ] ;
int V_9 ;
if ( V_26 < 0 )
return - V_30 ;
F_11 ( V_24 , 1 ) ;
F_11 ( V_25 , 1 ) ;
memset ( V_28 , 0 , sizeof( V_28 ) ) ;
F_12 ( V_28 , V_16 , V_17 , V_18 , 0 ) ;
memcpy ( V_27 , V_13 -> V_31 , V_19 ) ;
V_23 . V_20 = V_6 -> V_8 ;
V_23 . V_31 = V_27 ;
V_23 . V_32 = V_13 -> V_32 ;
F_13 ( & V_24 [ 0 ] , V_28 , V_19 ) ;
F_13 ( & V_25 [ 0 ] , V_21 , V_19 ) ;
V_9 = F_14 ( & V_23 , V_25 , V_24 , V_19 ) ;
memcpy ( V_29 + V_19 , V_21 , V_26 ) ;
V_23 . V_31 = V_21 ;
F_13 ( & V_24 [ 0 ] , V_28 + V_19 , V_19 ) ;
F_13 ( & V_25 [ 0 ] , V_22 , V_19 ) ;
V_9 = F_14 ( & V_23 , V_25 , V_24 , V_19 ) ;
memcpy ( V_29 , V_22 , V_19 ) ;
F_12 ( V_29 , V_15 , V_17 , V_18 , 1 ) ;
memcpy ( V_13 -> V_31 , V_22 , V_19 ) ;
return V_9 ;
}
static int F_15 ( struct V_12 * V_13 ,
struct V_14 * V_15 , struct V_14 * V_16 ,
unsigned int V_18 )
{
struct V_5 * V_6 = F_16 ( V_13 -> V_20 ) ;
int V_19 = F_10 ( V_13 -> V_20 ) ;
int V_33 = ( V_18 + V_19 - 1 ) / V_19 ;
int V_34 = V_33 > 2 ? V_33 - 2 : 0 ;
struct V_12 V_23 ;
int V_9 ;
V_23 . V_20 = V_6 -> V_8 ;
V_23 . V_31 = V_13 -> V_31 ;
V_23 . V_32 = V_13 -> V_32 ;
if ( V_33 == 1 ) {
V_9 = F_14 ( & V_23 , V_15 , V_16 , V_19 ) ;
} else if ( V_18 <= V_19 * 2 ) {
V_9 = F_9 ( V_6 , V_13 , V_15 , V_16 , 0 , V_18 ) ;
} else {
V_9 = F_14 ( & V_23 , V_15 , V_16 ,
V_34 * V_19 ) ;
if ( V_9 == 0 ) {
V_9 = F_9 ( V_6 , V_13 , V_15 , V_16 ,
V_34 * V_19 ,
V_18 - ( V_34 * V_19 ) ) ;
}
}
return V_9 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_14 * V_16 ,
unsigned int V_17 ,
unsigned int V_18 )
{
int V_19 = F_10 ( V_13 -> V_20 ) ;
T_1 V_21 [ V_19 ] ;
struct V_12 V_23 ;
struct V_14 V_24 [ 1 ] , V_25 [ 1 ] ;
int V_26 = V_18 - V_19 ;
T_1 V_27 [ V_19 ] ;
T_1 V_28 [ V_19 * 2 ] , V_29 [ V_19 * 2 ] ;
int V_9 ;
if ( V_26 < 0 )
return - V_30 ;
F_11 ( V_24 , 1 ) ;
F_11 ( V_25 , 1 ) ;
F_12 ( V_28 , V_16 , V_17 , V_18 , 0 ) ;
V_23 . V_20 = V_6 -> V_8 ;
V_23 . V_31 = V_27 ;
V_23 . V_32 = V_13 -> V_32 ;
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
F_13 ( & V_24 [ 0 ] , V_28 , V_19 ) ;
F_13 ( & V_25 [ 0 ] , V_21 , V_19 ) ;
V_9 = F_18 ( & V_23 , V_25 , V_24 , V_19 ) ;
if ( V_9 )
return V_9 ;
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
memcpy ( V_27 , V_28 + V_19 , V_26 ) ;
F_19 ( V_21 , V_27 , V_19 ) ;
memcpy ( V_29 + V_19 , V_21 , V_26 ) ;
memcpy ( V_28 + V_19 + V_26 , V_21 + V_26 , V_19 - V_26 ) ;
F_20 ( V_27 , sizeof( V_27 ) ) ;
F_13 ( & V_24 [ 0 ] , V_28 + V_19 , V_19 ) ;
F_13 ( & V_25 [ 0 ] , V_29 , V_19 ) ;
V_9 = F_18 ( & V_23 , V_25 , V_24 , V_19 ) ;
F_19 ( V_29 , V_13 -> V_31 , V_19 ) ;
F_12 ( V_29 , V_15 , V_17 , V_18 , 1 ) ;
memcpy ( V_13 -> V_31 , V_28 , V_19 ) ;
return V_9 ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_14 * V_15 , struct V_14 * V_16 ,
unsigned int V_18 )
{
struct V_5 * V_6 = F_16 ( V_13 -> V_20 ) ;
int V_19 = F_10 ( V_13 -> V_20 ) ;
int V_33 = ( V_18 + V_19 - 1 ) / V_19 ;
int V_34 = V_33 > 2 ? V_33 - 2 : 0 ;
struct V_12 V_23 ;
int V_9 ;
V_23 . V_20 = V_6 -> V_8 ;
V_23 . V_31 = V_13 -> V_31 ;
V_23 . V_32 = V_13 -> V_32 ;
if ( V_33 == 1 ) {
V_9 = F_18 ( & V_23 , V_15 , V_16 , V_19 ) ;
} else if ( V_18 <= V_19 * 2 ) {
V_9 = F_17 ( V_6 , V_13 , V_15 , V_16 , 0 , V_18 ) ;
} else {
V_9 = F_18 ( & V_23 , V_15 , V_16 ,
V_34 * V_19 ) ;
if ( V_9 == 0 ) {
V_9 = F_17 ( V_6 , V_13 , V_15 , V_16 ,
V_34 * V_19 ,
V_18 - ( V_34 * V_19 ) ) ;
}
}
return V_9 ;
}
static int F_22 ( struct V_1 * V_20 )
{
struct V_35 * V_36 = ( void * ) V_20 -> V_37 ;
struct V_38 * V_39 = F_23 ( V_36 ) ;
struct V_5 * V_6 = F_2 ( V_20 ) ;
struct V_7 * V_40 ;
V_40 = F_24 ( V_39 ) ;
if ( F_25 ( V_40 ) )
return F_26 ( V_40 ) ;
V_6 -> V_8 = V_40 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_20 ) ;
F_28 ( V_6 -> V_8 ) ;
}
static struct V_35 * F_29 ( struct V_41 * * V_42 )
{
struct V_35 * V_36 ;
struct V_43 * V_44 ;
int V_9 ;
V_9 = F_30 ( V_42 , V_45 ) ;
if ( V_9 )
return F_31 ( V_9 ) ;
V_44 = F_32 ( V_42 [ 1 ] , V_45 ,
V_46 ) ;
if ( F_25 ( V_44 ) )
return F_33 ( V_44 ) ;
V_36 = F_31 ( - V_30 ) ;
if ( ! F_34 ( V_44 -> V_47 ) )
goto V_48;
V_36 = F_35 ( L_1 , V_44 ) ;
if ( F_25 ( V_36 ) )
goto V_48;
V_36 -> V_44 . V_49 = V_45 ;
V_36 -> V_44 . V_50 = V_44 -> V_50 ;
V_36 -> V_44 . V_47 = V_44 -> V_47 ;
V_36 -> V_44 . V_51 = V_44 -> V_51 ;
V_36 -> V_44 . V_52 = & V_53 ;
V_36 -> V_44 . V_51 |= F_36 ( V_54 ) - 1 ;
V_36 -> V_44 . V_55 . V_56 = V_44 -> V_47 ;
V_36 -> V_44 . V_55 . V_57 = V_44 -> V_55 . V_57 ;
V_36 -> V_44 . V_55 . V_58 = V_44 -> V_55 . V_58 ;
V_36 -> V_44 . V_55 . V_59 = L_2 ;
V_36 -> V_44 . V_60 = sizeof( struct V_5 ) ;
V_36 -> V_44 . V_61 = F_22 ;
V_36 -> V_44 . V_62 = F_27 ;
V_36 -> V_44 . V_55 . V_63 = F_1 ;
V_36 -> V_44 . V_55 . V_64 = F_15 ;
V_36 -> V_44 . V_55 . V_65 = F_21 ;
V_48:
F_37 ( V_44 ) ;
return V_36 ;
}
static void F_38 ( struct V_35 * V_36 )
{
F_39 ( F_23 ( V_36 ) ) ;
F_40 ( V_36 ) ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_66 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_66 ) ;
}
