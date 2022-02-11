static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 , V_6 , 0x7f , 0 ) ;
F_3 ( V_4 -> V_7 , 1 , V_8 | V_9 ) ;
return V_10 ;
}
static void F_4 ( T_2 * V_11 , struct V_12 * V_13 )
{
V_13 -> V_14 = F_5 ( V_11 [ V_15 ] ) * 100 +
F_5 ( V_11 [ V_16 ] ) - 1900 ;
V_13 -> V_17 = F_5 ( V_11 [ V_18 ] & 0x1f ) - 1 ;
V_13 -> V_19 = F_5 ( V_11 [ V_20 ] & 0x3f ) ;
V_13 -> V_21 = ( V_11 [ V_22 ] & 0x07 ) - 1 ;
if ( V_11 [ V_23 ] & V_24 ) {
V_13 -> V_25 = F_5 ( V_11 [ V_23 ] & 0x01f ) ;
if ( V_13 -> V_25 == 12 )
V_13 -> V_25 = 0 ;
if ( V_11 [ V_23 ] & V_26 )
V_13 -> V_25 += 12 ;
} else {
V_13 -> V_25 = F_5 ( V_11 [ V_23 ] & 0x03f ) ;
}
V_13 -> V_27 = F_5 ( V_11 [ V_28 ] & 0x7f ) ;
V_13 -> V_29 = F_5 ( V_11 [ V_30 ] & 0x7f ) ;
}
static void F_6 ( struct V_12 * V_13 , T_2 * V_11 )
{
T_2 V_31 , V_32 ;
V_31 = ( V_13 -> V_14 + 1900 ) / 100 ;
V_32 = V_13 -> V_14 % 100 ;
V_11 [ V_15 ] = F_7 ( V_31 ) ;
V_11 [ V_16 ] = F_7 ( V_32 ) ;
V_11 [ V_18 ] = F_7 ( V_13 -> V_17 + 1 ) ;
V_11 [ V_20 ] = F_7 ( V_13 -> V_19 ) ;
V_11 [ V_22 ] = V_13 -> V_21 + 1 ;
V_11 [ V_23 ] = F_7 ( V_13 -> V_25 ) ;
V_11 [ V_28 ] = F_7 ( V_13 -> V_27 ) ;
V_11 [ V_30 ] = F_7 ( V_13 -> V_29 ) ;
}
static int F_8 ( struct V_33 * V_34 , struct V_12 * V_13 )
{
struct V_3 * V_4 = F_9 ( V_34 ) ;
T_2 V_11 [ V_35 ] ;
int V_36 ;
V_36 = F_10 ( V_4 -> V_5 , V_37 , V_11 ,
V_35 ) ;
if ( V_36 < 0 )
return V_36 ;
F_4 ( V_11 , V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_33 * V_34 , struct V_12 * V_13 )
{
struct V_3 * V_4 = F_9 ( V_34 ) ;
T_2 V_11 [ V_35 ] ;
F_6 ( V_13 , V_11 ) ;
return F_12 ( V_4 -> V_5 , V_37 , V_11 ,
V_35 ) ;
}
static int F_13 ( struct V_33 * V_34 , struct V_38 * V_39 )
{
struct V_3 * V_4 = F_9 ( V_34 ) ;
T_2 V_11 [ V_35 ] ;
unsigned int V_40 ;
int V_36 ;
V_36 = F_10 ( V_4 -> V_5 , V_41 , V_11 ,
V_35 ) ;
if ( V_36 < 0 )
return V_36 ;
F_4 ( V_11 , & V_39 -> time ) ;
V_36 = F_14 ( V_4 -> V_5 , V_6 , & V_40 ) ;
if ( V_36 < 0 )
return V_36 ;
V_39 -> V_42 = ! ! ( V_40 & 0x7f ) ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 , struct V_38 * V_39 )
{
struct V_3 * V_4 = F_9 ( V_34 ) ;
T_2 V_11 [ V_35 ] ;
int V_36 ;
F_6 ( & V_39 -> time , V_11 ) ;
V_36 = F_2 ( V_4 -> V_5 , V_6 , 0x7f , 0 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_12 ( V_4 -> V_5 , V_41 , V_11 ,
V_35 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_39 -> V_42 )
V_36 = F_2 ( V_4 -> V_5 , V_6 ,
0x7f , 0x7f ) ;
return V_36 ;
}
static int F_16 ( struct V_43 * V_44 )
{
struct V_45 * V_45 = F_9 ( V_44 -> V_34 . V_46 ) ;
struct V_3 * V_4 ;
int V_36 ;
V_4 = F_17 ( & V_44 -> V_34 , sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
F_18 ( V_44 , V_4 ) ;
V_4 -> V_45 = V_45 ;
V_4 -> V_5 = V_45 -> V_49 ;
V_4 -> V_7 = F_19 ( L_1 , & V_44 -> V_34 ,
& V_50 , V_51 ) ;
if ( F_20 ( V_4 -> V_7 ) ) {
V_36 = F_21 ( V_4 -> V_7 ) ;
F_22 ( & V_44 -> V_34 , L_2 , V_36 ) ;
return V_36 ;
}
V_4 -> V_1 = F_23 ( V_45 -> V_52 ,
V_53 ) ;
if ( V_4 -> V_1 < 0 ) {
V_36 = V_4 -> V_1 ;
goto V_54;
}
V_36 = F_24 ( V_4 -> V_1 , NULL , F_1 ,
V_55 , L_3 , V_4 ) ;
if ( V_36 < 0 ) {
F_22 ( & V_44 -> V_34 , L_4 ,
V_4 -> V_1 , V_36 ) ;
goto V_54;
}
return 0 ;
V_54:
F_25 ( V_4 -> V_7 ) ;
return V_36 ;
}
static int F_26 ( struct V_43 * V_44 )
{
struct V_3 * V_4 = F_27 ( V_44 ) ;
F_28 ( V_4 -> V_1 , V_4 ) ;
F_25 ( V_4 -> V_7 ) ;
return 0 ;
}
