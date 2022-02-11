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
static int F_16 ( struct V_31 * V_31 , struct V_32 * V_33 ,
struct V_32 * V_34 , struct V_3 * V_4 ,
int V_35 , int V_18 )
{
struct V_32 * V_36 [ V_37 + 1 ] ;
struct V_28 * V_38 ;
struct V_7 * V_8 ;
struct V_39 * V_40 ;
char * V_24 ;
int V_19 = 0 , V_41 ;
if ( V_33 == NULL )
return - V_42 ;
V_41 = F_17 ( V_36 , V_37 , V_33 , V_43 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_36 [ V_44 ] == NULL )
return - V_42 ;
if ( V_36 [ V_45 ] == NULL )
return - V_42 ;
V_38 = F_18 ( V_36 [ V_44 ] ) ;
V_24 = F_18 ( V_36 [ V_45 ] ) ;
V_40 = F_19 ( V_38 -> V_46 , V_4 , V_18 , & V_23 ) ;
if ( ! V_40 ) {
V_40 = F_20 ( V_38 -> V_46 , V_34 , V_4 , sizeof( * V_8 ) , V_18 ,
& V_47 , & V_23 ) ;
if ( F_21 ( V_40 ) )
return F_22 ( V_40 ) ;
V_8 = F_23 ( V_40 ) ;
V_19 = F_9 ( V_8 , V_24 ) ;
if ( V_19 < 0 ) {
if ( V_34 )
F_24 ( & V_40 -> V_48 ,
& V_40 -> V_49 ) ;
F_25 ( V_40 , V_50 ) ;
return V_19 ;
}
V_8 -> V_17 = V_38 -> V_30 ;
V_19 = V_51 ;
} else {
V_8 = F_23 ( V_40 ) ;
if ( V_18 )
return 0 ;
F_6 ( V_8 , V_18 ) ;
if ( ! V_35 )
return - V_52 ;
F_13 ( V_8 , V_24 , V_38 ) ;
}
if ( V_19 == V_51 )
F_26 ( V_40 , & V_23 ) ;
return V_19 ;
}
static int F_27 ( struct V_3 * V_4 , int V_18 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_8 )
return F_6 ( V_8 , V_18 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_18 , int V_53 )
{
unsigned char * V_54 = F_29 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_28 V_55 = {
. V_46 = V_8 -> V_56 ,
. V_57 = V_8 -> V_21 - V_53 ,
. V_58 = V_8 -> V_20 - V_18 ,
. V_30 = V_8 -> V_17 ,
} ;
struct V_59 V_60 ;
if ( F_30 ( V_2 , V_44 , sizeof( V_55 ) , & V_55 ) ||
F_31 ( V_2 , V_45 , V_8 -> V_15 ) )
goto V_61;
V_60 . V_62 = F_32 ( V_13 - V_8 -> V_11 . V_62 ) ;
V_60 . V_12 = F_32 ( V_13 - V_8 -> V_11 . V_12 ) ;
V_60 . V_63 = F_32 ( V_8 -> V_11 . V_63 ) ;
if ( F_30 ( V_2 , V_64 , sizeof( V_60 ) , & V_60 ) )
goto V_61;
return V_2 -> V_65 ;
V_61:
F_33 ( V_2 , V_54 ) ;
return - 1 ;
}
static int T_1 F_34 ( void )
{
int V_19 = F_35 ( & V_66 ) ;
if ( ! V_19 )
F_4 ( L_2 ) ;
return V_19 ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_66 ) ;
}
