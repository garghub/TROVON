static void F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = F_2 ( V_1 [ V_5 ] ) ;
V_3 -> V_6 = F_2 ( V_1 [ V_7 ] ) ;
if ( V_1 [ V_8 ] & V_9 ) {
V_3 -> V_10 = F_2 ( V_1 [ V_8 ] & 0x1f ) ;
if ( V_1 [ V_8 ] & V_11 )
V_3 -> V_10 += 12 ;
} else
V_3 -> V_10 = F_2 ( V_1 [ V_8 ] & 0x3f ) ;
V_3 -> V_12 = V_1 [ V_13 ] & 0x07 ;
V_3 -> V_14 = F_2 ( V_1 [ V_15 ] ) ;
V_3 -> V_16 = F_2 ( V_1 [ V_17 ] ) ;
V_3 -> V_18 = F_2 ( V_1 [ V_19 ] ) + F_2 ( V_1 [ V_20 ] ) * 100 ;
V_3 -> V_18 -= 1900 ;
}
static void F_3 ( struct V_2 * V_3 , T_1 * V_1 )
{
V_1 [ V_5 ] = F_4 ( V_3 -> V_4 ) ;
V_1 [ V_7 ] = F_4 ( V_3 -> V_6 ) ;
V_1 [ V_8 ] = F_4 ( V_3 -> V_10 ) ;
V_1 [ V_13 ] = V_3 -> V_12 ;
V_1 [ V_15 ] = F_4 ( V_3 -> V_14 ) ;
V_1 [ V_17 ] = F_4 ( V_3 -> V_16 ) ;
V_1 [ V_19 ] = F_4 ( V_3 -> V_18 % 100 ) ;
V_1 [ V_20 ] = F_4 ( ( V_3 -> V_18 + 1900 ) / 100 ) ;
}
static int F_5 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_6 ( V_22 ) ;
T_1 V_1 [ 8 ] ;
int V_25 ;
V_25 = F_7 ( V_24 -> V_26 , V_27 , 8 , V_1 ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 , V_3 ) ;
return F_8 ( V_3 ) ;
}
static int F_9 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_6 ( V_22 ) ;
T_1 V_1 [ 8 ] ;
int V_25 ;
F_3 ( V_3 , V_1 ) ;
V_25 = F_10 ( V_24 -> V_26 , V_27 , 8 , V_1 ) ;
if ( V_24 -> V_28 )
F_11 ( 2000 ) ;
return V_25 ;
}
static int F_12 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
struct V_23 * V_24 = F_6 ( V_22 ) ;
T_1 V_1 [ 8 ] ;
T_1 V_31 ;
int V_25 ;
V_25 = F_7 ( V_24 -> V_26 , V_32 , 8 , V_1 ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 , & V_30 -> time ) ;
V_25 = F_13 ( V_24 -> V_26 , V_33 , & V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
V_30 -> V_34 = ! ! V_31 ;
V_25 = F_13 ( V_24 -> V_26 , V_35 , & V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_31 & V_36 )
V_30 -> V_37 = 1 ;
else
V_30 -> V_37 = 0 ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 )
{
int V_25 = F_15 ( V_24 -> V_26 , V_33 , 0 ) ;
if ( V_24 -> V_28 )
F_11 ( 2000 ) ;
return V_25 ;
}
static int F_16 ( struct V_23 * V_24 )
{
int V_25 ;
T_1 V_38 = 0x77 ;
if ( V_24 -> V_28 )
V_38 = 0x57 ;
V_25 = F_15 ( V_24 -> V_26 , V_33 , V_38 ) ;
if ( V_24 -> V_28 )
F_11 ( 2000 ) ;
return V_25 ;
}
static int F_17 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
struct V_23 * V_24 = F_6 ( V_22 ) ;
T_1 V_1 [ 8 ] ;
int V_25 ;
F_3 ( & V_30 -> time , V_1 ) ;
V_25 = F_14 ( V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_10 ( V_24 -> V_26 , V_32 , 8 , V_1 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_24 -> V_28 )
F_11 ( 2000 ) ;
if ( V_30 -> V_34 )
V_25 = F_16 ( V_24 ) ;
return V_25 ;
}
static int F_18 ( struct V_21 * V_22 ,
unsigned int V_34 )
{
struct V_23 * V_24 = F_6 ( V_22 ) ;
if ( V_34 )
return F_16 ( V_24 ) ;
else
return F_14 ( V_24 ) ;
}
static T_2 F_19 ( int V_39 , void * V_1 )
{
struct V_23 * V_24 = V_1 ;
F_20 ( V_24 -> V_40 , 1 , V_41 | V_42 ) ;
return V_43 ;
}
static int F_21 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_6 ( V_45 -> V_22 . V_48 ) ;
struct V_49 * V_50 = F_22 ( V_47 -> V_22 ) ;
struct V_23 * V_24 ;
int V_25 ;
V_24 = F_23 ( & V_45 -> V_22 , sizeof( struct V_23 ) ,
V_51 ) ;
if ( ! V_24 )
return - V_52 ;
V_24 -> V_22 = & V_45 -> V_22 ;
V_24 -> V_47 = V_47 ;
V_24 -> V_26 = V_47 -> V_26 ;
V_24 -> V_39 = V_47 -> V_53 + V_54 ;
F_24 ( V_45 , V_24 ) ;
V_24 -> V_40 = F_25 ( & V_45 -> V_22 , L_1 ,
& V_55 , V_56 ) ;
if ( F_26 ( V_24 -> V_40 ) ) {
V_25 = F_27 ( V_24 -> V_40 ) ;
F_28 ( & V_45 -> V_22 , L_2 , V_25 ) ;
goto V_57;
}
V_25 = F_29 ( & V_45 -> V_22 , V_24 -> V_39 , NULL ,
F_19 , 0 , L_3 , V_24 ) ;
if ( V_25 < 0 )
F_28 ( & V_45 -> V_22 , L_4 ,
V_24 -> V_39 , V_25 ) ;
F_30 ( & V_45 -> V_22 , L_5 , V_45 -> V_58 -> V_59 ) ;
if ( V_50 && V_50 -> V_60 ) {
V_24 -> V_28 = true ;
F_31 ( & V_45 -> V_22 , L_6
L_7 ) ;
}
return 0 ;
V_57:
F_24 ( V_45 , NULL ) ;
return V_25 ;
}
static int F_32 ( struct V_44 * V_45 )
{
return 0 ;
}
