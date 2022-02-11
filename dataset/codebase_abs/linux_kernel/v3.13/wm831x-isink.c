static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 ;
V_6 = F_3 ( V_5 , V_4 -> V_7 , V_8 ,
V_8 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_3 ( V_5 , V_4 -> V_7 , V_9 ,
V_9 ) ;
if ( V_6 != 0 )
F_3 ( V_5 , V_4 -> V_7 , V_8 , 0 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 ;
V_6 = F_3 ( V_5 , V_4 -> V_7 , V_9 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_5 , V_4 -> V_7 , V_8 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 ;
V_6 = F_6 ( V_5 , V_4 -> V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ( V_6 & ( V_8 | V_9 ) ) ==
( V_8 | V_9 ) )
return 1 ;
else
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_10 , int V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 , V_12 ;
for ( V_12 = 0 ; V_12 < F_8 ( V_13 ) ; V_12 ++ ) {
int V_14 = V_13 [ V_12 ] ;
if ( V_10 <= V_14 && V_14 <= V_11 ) {
V_6 = F_3 ( V_5 , V_4 -> V_7 ,
V_15 , V_12 ) ;
return V_6 ;
}
}
return - V_16 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 ;
V_6 = F_6 ( V_5 , V_4 -> V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 &= V_15 ;
if ( V_6 > V_17 )
V_6 = V_17 ;
return V_13 [ V_6 ] ;
}
static T_1 F_10 ( int V_18 , void * V_19 )
{
struct V_3 * V_4 = V_19 ;
F_11 ( V_4 -> V_20 ,
V_21 ,
NULL ) ;
return V_22 ;
}
static int F_12 ( struct V_23 * V_24 )
{
struct V_5 * V_5 = F_13 ( V_24 -> V_25 . V_26 ) ;
struct V_27 * V_28 = F_14 ( V_5 -> V_25 ) ;
struct V_3 * V_4 ;
int V_29 = V_24 -> V_29 % F_8 ( V_28 -> V_4 ) ;
struct V_30 V_31 = { } ;
struct V_32 * V_33 ;
int V_6 , V_18 ;
F_15 ( & V_24 -> V_25 , L_1 , V_29 + 1 ) ;
if ( V_28 == NULL || V_28 -> V_4 [ V_29 ] == NULL )
return - V_34 ;
V_4 = F_16 ( & V_24 -> V_25 , sizeof( struct V_3 ) ,
V_35 ) ;
if ( V_4 == NULL ) {
F_17 ( & V_24 -> V_25 , L_2 ) ;
return - V_36 ;
}
V_4 -> V_5 = V_5 ;
V_33 = F_18 ( V_24 , V_37 , 0 ) ;
if ( V_33 == NULL ) {
F_17 ( & V_24 -> V_25 , L_3 ) ;
V_6 = - V_16 ;
goto V_38;
}
V_4 -> V_7 = V_33 -> V_39 ;
snprintf ( V_4 -> V_40 , sizeof( V_4 -> V_40 ) , L_4 , V_29 + 1 ) ;
V_4 -> V_41 . V_40 = V_4 -> V_40 ;
V_4 -> V_41 . V_29 = V_29 ;
V_4 -> V_41 . V_42 = & V_43 ;
V_4 -> V_41 . type = V_44 ;
V_4 -> V_41 . V_45 = V_46 ;
V_31 . V_25 = V_24 -> V_25 . V_26 ;
V_31 . V_47 = V_28 -> V_4 [ V_29 ] ;
V_31 . V_48 = V_4 ;
V_4 -> V_20 = F_19 ( & V_24 -> V_25 , & V_4 -> V_41 ,
& V_31 ) ;
if ( F_20 ( V_4 -> V_20 ) ) {
V_6 = F_21 ( V_4 -> V_20 ) ;
F_17 ( V_5 -> V_25 , L_5 ,
V_29 + 1 , V_6 ) ;
goto V_38;
}
V_18 = F_22 ( V_5 , F_23 ( V_24 , 0 ) ) ;
V_6 = F_24 ( & V_24 -> V_25 , V_18 , NULL ,
F_10 ,
V_49 , V_4 -> V_40 ,
V_4 ) ;
if ( V_6 != 0 ) {
F_17 ( & V_24 -> V_25 , L_6 ,
V_18 , V_6 ) ;
goto V_38;
}
F_25 ( V_24 , V_4 ) ;
return 0 ;
V_38:
return V_6 ;
}
static int T_2 F_26 ( void )
{
int V_6 ;
V_6 = F_27 ( & V_50 ) ;
if ( V_6 != 0 )
F_28 ( L_7 , V_6 ) ;
return V_6 ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_50 ) ;
}
