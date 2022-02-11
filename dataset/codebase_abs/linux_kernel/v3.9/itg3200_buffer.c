static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 = 0x80 | V_5 ;
struct V_6 V_7 [ 2 ] = {
{
. V_8 = V_2 -> V_8 ,
. V_9 = V_2 -> V_9 ,
. V_10 = 1 ,
. V_3 = & V_4 ,
} ,
{
. V_8 = V_2 -> V_8 ,
. V_9 = V_2 -> V_9 | V_11 ,
. V_10 = V_12 * sizeof( V_13 ) ,
. V_3 = ( char * ) & V_3 ,
} ,
} ;
return F_2 ( V_2 -> V_14 , V_7 , 2 ) ;
}
static T_3 F_3 ( int V_15 , void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 = F_4 ( V_20 ) ;
T_1 V_3 [ V_12 + sizeof( V_23 ) / sizeof( V_24 ) ] ;
int V_25 = F_1 ( V_22 -> V_2 , V_3 ) ;
if ( V_25 < 0 )
goto V_26;
if ( V_20 -> V_27 )
memcpy ( V_3 + V_20 -> V_28 - sizeof( V_23 ) ,
& V_18 -> V_29 , sizeof( V_18 -> V_29 ) ) ;
F_5 ( V_20 , ( T_2 * ) V_3 ) ;
F_6 ( V_20 -> V_30 ) ;
V_26:
return V_31 ;
}
int F_7 ( struct V_19 * V_20 )
{
return F_8 ( V_20 , & V_32 ,
F_3 , NULL ) ;
}
void F_9 ( struct V_19 * V_20 )
{
F_10 ( V_20 ) ;
}
static int F_11 ( struct V_33 * V_30 ,
bool V_34 )
{
struct V_19 * V_20 = V_30 -> V_35 ;
int V_25 ;
T_2 V_36 ;
V_25 = F_12 ( V_20 , V_37 , & V_36 ) ;
if ( V_25 )
goto V_26;
if ( V_34 )
V_36 |= V_38 ;
else
V_36 &= ~ V_38 ;
V_25 = F_13 ( V_20 , V_37 , V_36 ) ;
if ( V_25 )
goto V_26;
V_26:
return V_25 ;
}
int F_14 ( struct V_19 * V_20 )
{
int V_25 ;
struct V_21 * V_22 = F_4 ( V_20 ) ;
V_22 -> V_30 = F_15 ( L_1 , V_20 -> V_39 ,
V_20 -> V_40 ) ;
if ( ! V_22 -> V_30 )
return - V_41 ;
V_25 = F_16 ( V_22 -> V_2 -> V_15 ,
& V_42 ,
V_43 ,
L_2 ,
V_22 -> V_30 ) ;
if ( V_25 )
goto V_44;
V_22 -> V_30 -> V_45 . V_46 = & V_22 -> V_2 -> V_45 ;
V_22 -> V_30 -> V_47 = & V_48 ;
V_22 -> V_30 -> V_35 = V_20 ;
V_25 = F_17 ( V_22 -> V_30 ) ;
if ( V_25 )
goto V_49;
V_20 -> V_30 = V_22 -> V_30 ;
return 0 ;
V_49:
F_18 ( V_22 -> V_2 -> V_15 , V_22 -> V_30 ) ;
V_44:
F_19 ( V_22 -> V_30 ) ;
return V_25 ;
}
void F_20 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_4 ( V_20 ) ;
F_21 ( V_22 -> V_30 ) ;
F_18 ( V_22 -> V_2 -> V_15 , V_22 -> V_30 ) ;
F_19 ( V_22 -> V_30 ) ;
}
