static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 V_7 ;
int V_8 , V_9 ;
T_1 V_10 = 0 ;
F_3 ( & V_7 , V_2 -> V_5 -> V_11 ) ;
while ( F_4 ( & V_7 , & V_8 , & V_9 ) ) {
switch ( V_8 ) {
case V_12 :
V_10 = V_9 ;
break;
}
}
strcpy ( V_2 -> V_13 -> V_14 , L_1 ) ;
strcpy ( V_2 -> V_13 -> V_15 , V_2 -> V_16 -> V_17 ) ;
strcpy ( V_2 -> V_13 -> V_18 , V_2 -> V_16 -> V_17 ) ;
snprintf ( V_2 -> V_13 -> V_19 , sizeof( V_2 -> V_13 -> V_19 ) ,
L_2 ,
V_2 -> V_16 -> V_17 , V_10 ,
V_4 -> V_20 [ 3 ] , V_4 -> V_20 [ 4 ] ,
F_5 ( & V_2 -> V_5 -> V_21 ) , 100 << V_4 -> V_22 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_23 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_24 * V_13 )
{
F_6 ( V_13 -> V_25 ) ;
}
static void F_13 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_14 ( V_27 , struct V_1 , V_28 . V_27 ) ;
int V_29 ;
if ( V_2 -> V_30 )
return;
V_29 = F_15 ( & V_2 -> V_5 -> V_21 , - 1 , NULL , V_31 , 0 ,
& V_2 -> V_13 ) ;
if ( V_29 < 0 )
return;
F_1 ( V_2 ) ;
V_29 = F_16 ( V_2 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_17 ( V_2 ) ;
if ( V_29 < 0 )
goto error;
F_18 ( V_2 ) ;
V_29 = F_19 ( V_2 ) ;
if ( V_29 < 0 )
goto error;
if ( V_2 -> V_16 -> V_32 & V_33 ) {
V_29 = F_20 ( V_2 ) ;
if ( V_29 < 0 )
goto error;
}
V_29 = F_21 ( V_2 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_22 ( V_2 -> V_13 ) ;
if ( V_29 < 0 )
goto error;
V_2 -> V_13 -> V_34 = F_12 ;
V_2 -> V_13 -> V_25 = V_2 ;
V_2 -> V_30 = true ;
return;
error:
F_7 ( V_2 ) ;
F_23 ( V_2 -> V_13 ) ;
F_24 ( & V_2 -> V_5 -> V_21 ,
L_3 , V_29 ) ;
}
static int F_25 ( struct V_35 * V_5 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_38 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_2 -> V_16 = ( const struct V_40 * ) V_37 -> V_41 ;
V_2 -> V_5 = F_27 ( V_5 ) ;
F_28 ( & V_5 -> V_21 , V_2 ) ;
F_29 ( & V_2 -> V_23 ) ;
F_30 ( & V_2 -> V_42 ) ;
F_31 ( & V_2 -> V_43 ) ;
F_32 ( & V_2 -> V_28 , F_13 ) ;
F_33 ( V_5 , & V_2 -> V_28 ) ;
return 0 ;
}
static void F_34 ( struct V_35 * V_5 )
{
struct V_1 * V_2 = F_35 ( & V_5 -> V_21 ) ;
F_36 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_30 ) {
F_37 ( V_2 -> V_13 ) ;
} else {
F_6 ( V_2 ) ;
}
}
static void F_38 ( struct V_35 * V_5 )
{
struct V_1 * V_2 = F_35 ( & V_5 -> V_21 ) ;
if ( ! V_2 -> V_30 )
F_33 ( V_5 , & V_2 -> V_28 ) ;
F_39 ( V_2 ) ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_44 . V_14 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_44 . V_14 ) ;
}
