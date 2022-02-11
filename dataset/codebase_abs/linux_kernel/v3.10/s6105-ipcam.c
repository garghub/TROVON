static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 = 0 ;
V_11 = F_2 ( V_9 , V_12 |
V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_2 ( V_10 , V_13 |
V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_3 ( V_9 , 0 , V_15 ,
V_16 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_4 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
V_20 -> type = V_21 ;
V_20 -> V_22 = 1 ;
V_20 -> V_23 . V_24 . V_25 = 2 ;
if ( V_20 -> V_23 . V_24 . V_26 ) {
V_20 -> V_23 . V_24 . V_26 = 1 ;
strcpy ( V_20 -> V_23 . V_24 . V_27 , L_1 ) ;
} else {
strcpy ( V_20 -> V_23 . V_24 . V_27 , L_2 ) ;
}
return 0 ;
}
static int F_5 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
V_29 -> V_23 . V_24 . V_26 [ 0 ] = V_18 -> V_30 ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_31 * V_32 = V_18 -> V_7 ;
struct V_33 * V_34 = & V_32 -> V_34 ;
unsigned int V_35 = ( V_29 -> V_23 . V_24 . V_26 [ 0 ] != 0 ) ;
char * V_36 = L_3 ;
char * V_37 = L_4 ;
if ( V_18 -> V_30 == V_35 )
return 0 ;
V_18 -> V_30 = V_35 ;
F_7 ( V_34 , V_35 ? V_36 : V_37 ) ;
F_8 ( V_34 ) ;
F_9 ( V_34 , V_35 ? V_37 : V_36 ) ;
F_8 ( V_34 ) ;
return 1 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_31 * V_32 = V_6 -> V_32 ;
struct V_33 * V_34 = & V_32 -> V_34 ;
F_11 ( V_34 , V_38 ,
F_12 ( V_38 ) ) ;
F_13 ( V_34 , V_39 , F_12 ( V_39 ) ) ;
F_14 ( V_34 , L_5 ) ;
F_14 ( V_34 , L_6 ) ;
F_14 ( V_34 , L_7 ) ;
F_14 ( V_34 , L_8 ) ;
F_14 ( V_34 , L_9 ) ;
F_14 ( V_34 , L_10 ) ;
F_14 ( V_34 , L_11 ) ;
F_14 ( V_34 , L_12 ) ;
F_9 ( V_34 , L_13 ) ;
F_7 ( V_34 , L_3 ) ;
F_8 ( V_34 ) ;
F_9 ( V_34 , L_4 ) ;
F_8 ( V_34 ) ;
F_15 ( V_32 -> V_40 -> V_41 , F_16 ( & V_42 , V_32 ) ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
int V_11 ;
F_18 ( 0 , V_43 , F_12 ( V_43 ) ) ;
V_44 = F_19 ( L_14 , - 1 ) ;
if ( ! V_44 )
return - V_45 ;
F_20 ( V_44 , & V_46 ) ;
F_21 ( V_44 , & V_47 ,
sizeof( V_47 ) ) ;
V_11 = F_22 ( V_44 ) ;
if ( V_11 )
F_23 ( V_44 ) ;
return V_11 ;
}
static void T_2 F_24 ( void )
{
F_25 ( V_44 ) ;
}
