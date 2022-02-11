static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
F_2 ( & V_8 -> V_10 ) ;
V_8 -> V_11 . V_12 = V_13 ;
F_3 ( & V_8 -> V_14 , V_2 ) ;
F_4 ( L_1 ,
( char * ) V_8 -> V_15 , V_8 -> V_14 . V_16 ) ;
F_5 ( & V_8 -> V_10 ) ;
return V_8 -> V_17 ;
}
static int F_6 ( struct V_7 * V_8 , int V_18 )
{
int V_19 = 0 ;
if ( V_8 ) {
if ( V_18 )
V_8 -> V_20 -- ;
V_8 -> V_21 -- ;
if ( V_8 -> V_20 <= 0 && V_8 -> V_21 <= 0 ) {
F_7 ( V_8 -> V_15 ) ;
F_8 ( & V_8 -> V_22 , & V_23 ) ;
V_19 = 1 ;
}
}
return V_19 ;
}
static int F_9 ( struct V_7 * V_8 , char * V_24 )
{
V_8 -> V_15 = F_10 ( V_25 , V_26 ) ;
if ( F_11 ( ! V_8 -> V_15 ) )
return - V_27 ;
F_12 ( V_8 -> V_15 , V_24 , V_25 ) ;
return 0 ;
}
static void F_13 ( struct V_7 * V_8 , char * V_24 ,
struct V_28 * V_29 )
{
F_14 ( & V_8 -> V_10 ) ;
V_8 -> V_17 = V_29 -> V_30 ;
memset ( V_8 -> V_15 , 0 , V_25 ) ;
F_12 ( V_8 -> V_15 , V_24 , V_25 ) ;
F_15 ( & V_8 -> V_10 ) ;
}
static int F_16 ( struct V_31 * V_32 , struct V_31 * V_33 ,
struct V_3 * V_4 , int V_34 , int V_18 )
{
struct V_31 * V_35 [ V_36 + 1 ] ;
struct V_28 * V_37 ;
struct V_7 * V_8 ;
struct V_38 * V_39 ;
char * V_24 ;
int V_19 = 0 , V_40 ;
if ( V_32 == NULL )
return - V_41 ;
V_40 = F_17 ( V_35 , V_36 , V_32 , V_42 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_35 [ V_43 ] == NULL )
return - V_41 ;
if ( V_35 [ V_44 ] == NULL )
return - V_41 ;
V_37 = F_18 ( V_35 [ V_43 ] ) ;
V_24 = F_18 ( V_35 [ V_44 ] ) ;
V_39 = F_19 ( V_37 -> V_45 , V_4 , V_18 , & V_23 ) ;
if ( ! V_39 ) {
V_39 = F_20 ( V_37 -> V_45 , V_33 , V_4 , sizeof( * V_8 ) , V_18 ,
& V_46 , & V_23 ) ;
if ( F_21 ( V_39 ) )
return F_22 ( V_39 ) ;
V_8 = F_23 ( V_39 ) ;
V_19 = F_9 ( V_8 , V_24 ) ;
if ( V_19 < 0 ) {
F_7 ( V_39 ) ;
return V_19 ;
}
V_8 -> V_17 = V_37 -> V_30 ;
V_19 = V_47 ;
} else {
V_8 = F_23 ( V_39 ) ;
if ( ! V_34 ) {
F_6 ( V_8 , V_18 ) ;
return - V_48 ;
}
F_13 ( V_8 , V_24 , V_37 ) ;
}
if ( V_19 == V_47 )
F_24 ( V_39 , & V_23 ) ;
return V_19 ;
}
static int F_25 ( struct V_3 * V_4 , int V_18 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_8 )
return F_6 ( V_8 , V_18 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_18 , int V_49 )
{
unsigned char * V_50 = F_27 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_28 V_51 = {
. V_45 = V_8 -> V_52 ,
. V_53 = V_8 -> V_21 - V_49 ,
. V_54 = V_8 -> V_20 - V_18 ,
. V_30 = V_8 -> V_17 ,
} ;
struct V_55 V_56 ;
F_28 ( V_2 , V_43 , sizeof( V_51 ) , & V_51 ) ;
F_29 ( V_2 , V_44 , V_8 -> V_15 ) ;
V_56 . V_57 = F_30 ( V_13 - V_8 -> V_11 . V_57 ) ;
V_56 . V_12 = F_30 ( V_13 - V_8 -> V_11 . V_12 ) ;
V_56 . V_58 = F_30 ( V_8 -> V_11 . V_58 ) ;
F_28 ( V_2 , V_59 , sizeof( V_56 ) , & V_56 ) ;
return V_2 -> V_60 ;
V_61:
F_31 ( V_2 , V_50 ) ;
return - 1 ;
}
static int T_1 F_32 ( void )
{
int V_19 = F_33 ( & V_62 ) ;
if ( ! V_19 )
F_4 ( L_2 ) ;
return V_19 ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_62 ) ;
}
