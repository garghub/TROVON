int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_8 != NULL )
if ( V_6 -> V_7 . V_8 ( V_2 -> V_9 [ 0 ] . V_10 , V_3 ) ) {
F_2 ( L_1 ) ;
return - V_11 ;
}
}
return 0 ;
}
int F_3 ( struct V_1 * V_2 , int V_12 , T_1 V_13 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_14 != NULL )
V_6 -> V_7 . V_14 ( V_2 -> V_9 [ 0 ] . V_10 ,
V_12 , V_13 , V_3 ) ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_15 != NULL )
if ( V_6 -> V_7 . V_15 ( V_2 -> V_9 [ 0 ] . V_10 , V_3 ) < 0 )
F_2 ( L_2 ) ;
}
return 0 ;
}
int F_5 ( struct V_16 * V_17 , int V_3 )
{
T_2 * V_18 ;
int V_19 ;
V_18 = F_6 ( 3 , V_20 ) ;
if ( ! V_18 )
return - V_21 ;
V_18 [ 0 ] = V_22 ;
V_18 [ 1 ] = V_23 ;
V_18 [ 2 ] = V_3 ? V_24 : V_25 ;
V_19 = F_7 ( V_17 , V_18 , 3 ) ;
F_8 ( V_18 ) ;
F_9 ( 10 ) ;
return V_19 ;
}
int F_10 ( struct V_1 * V_2 , int V_3 )
{
int V_19 ;
T_2 * V_18 ;
V_18 = F_6 ( 3 , V_20 ) ;
if ( ! V_18 )
return - V_21 ;
if ( ( V_19 = F_1 ( V_2 , V_3 ) ) < 0 )
goto V_19;
if ( V_3 ) {
V_18 [ 0 ] = V_26 ;
V_18 [ 1 ] = 0x00 ;
V_19 = F_7 ( V_2 -> V_27 , V_18 , 2 ) ;
if ( V_19 < 0 )
goto V_19;
}
V_18 [ 0 ] = V_22 ;
V_18 [ 1 ] = V_3 ? V_28 : V_29 ;
V_19 = F_7 ( V_2 -> V_27 , V_18 , 3 ) ;
V_19:
F_8 ( V_18 ) ;
return V_19 ;
}
int F_11 ( struct V_16 * V_17 , int V_3 )
{
T_2 * V_18 ;
int V_19 ;
if ( ! V_3 )
return 0 ;
V_18 = F_6 ( 3 , V_20 ) ;
if ( ! V_18 )
return - V_21 ;
V_18 [ 0 ] = V_22 ;
V_18 [ 1 ] = V_23 ;
V_18 [ 2 ] = V_24 ;
V_19 = F_7 ( V_17 , V_18 , 3 ) ;
F_8 ( V_18 ) ;
return V_19 ;
}
static int F_12 ( struct V_16 * V_17 , T_2 V_30 ,
T_2 * V_31 , T_1 V_32 , T_2 * V_33 , T_1 V_34 )
{
T_2 * V_35 ;
int V_19 , V_36 , V_37 ;
V_36 = ( V_33 == NULL || V_34 == 0 ) ;
V_37 = 2 + V_32 + ( V_36 ? 0 : 2 ) ;
V_35 = F_6 ( V_38 , V_20 ) ;
if ( ! V_35 )
return - V_21 ;
if ( 4 + V_32 > V_38 ) {
F_13 ( L_3 , V_32 ) ;
V_19 = - V_39 ;
goto V_19;
}
V_35 [ 0 ] = V_36 ? V_40 : V_41 ;
V_35 [ 1 ] = ( V_30 << 1 ) | ( V_36 ? 0 : 1 ) ;
memcpy ( & V_35 [ 2 ] , V_31 , V_32 ) ;
if ( ! V_36 ) {
V_35 [ V_32 + 2 ] = ( V_34 >> 8 ) & 0xff ;
V_35 [ V_32 + 3 ] = V_34 & 0xff ;
}
V_19 = F_14 ( V_17 , V_35 , V_37 , V_33 , V_34 , 0 ) ;
V_19:
F_8 ( V_35 ) ;
return V_19 ;
}
static int F_15 ( struct V_42 * V_2 , struct V_43 V_44 [] , int V_45 )
{
struct V_16 * V_17 = F_16 ( V_2 ) ;
int V_46 ;
if ( F_17 ( & V_17 -> V_47 ) < 0 )
return - V_48 ;
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ ) {
if ( V_46 + 1 < V_45 && ( V_44 [ V_46 ] . V_49 & V_50 ) == 0
&& ( V_44 [ V_46 + 1 ] . V_49 & V_50 ) ) {
if ( F_12 ( V_17 , V_44 [ V_46 ] . V_30 , V_44 [ V_46 ] . V_51 , V_44 [ V_46 ] . V_37 ,
V_44 [ V_46 + 1 ] . V_51 , V_44 [ V_46 + 1 ] . V_37 ) < 0 )
break;
V_46 ++ ;
} else if ( ( V_44 [ V_46 ] . V_49 & V_50 ) == 0 ) {
if ( F_12 ( V_17 , V_44 [ V_46 ] . V_30 , V_44 [ V_46 ] . V_51 , V_44 [ V_46 ] . V_37 , NULL , 0 ) < 0 )
break;
} else if ( V_44 [ V_46 ] . V_30 != 0x50 ) {
if ( F_12 ( V_17 , V_44 [ V_46 ] . V_30 , NULL , 0 , V_44 [ V_46 ] . V_51 , V_44 [ V_46 ] . V_37 ) < 0 )
break;
}
}
F_18 ( & V_17 -> V_47 ) ;
return V_46 ;
}
static T_3 F_19 ( struct V_42 * V_52 )
{
return V_53 ;
}
int F_20 ( struct V_16 * V_17 , T_2 V_54 , T_2 * V_55 )
{
T_2 V_31 [ 1 ] = { V_54 } ;
return F_12 ( V_17 , 0x50 , V_31 , 1 , V_55 , 1 ) ;
}
int F_21 ( struct V_16 * V_17 , T_3 * V_56 , int * V_57 )
{
T_2 * V_51 ;
int V_19 ;
V_51 = F_6 ( 5 , V_20 ) ;
if ( ! V_51 )
return - V_21 ;
V_51 [ 0 ] = V_58 ;
V_19 = F_14 ( V_17 , V_51 , 1 , V_51 , 5 , 0 ) ;
if ( V_19 < 0 )
goto V_19;
F_22 ( V_17 , V_51 , V_56 , V_57 ) ;
if ( V_51 [ 0 ] != 0 )
F_23 ( L_4 , 5 , V_51 ) ;
V_19:
F_8 ( V_51 ) ;
return V_19 ;
}
