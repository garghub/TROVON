static T_1 F_1 ( T_1 V_1 ) {
if ( ( V_1 & V_2 ) != 0 )
return 0 ;
else if ( ( V_1 & V_3 ) != 0 )
return 1 ;
else if ( ( V_1 & V_4 ) != 0 )
return 2 ;
else if ( ( V_1 & V_5 ) != 0 )
return 3 ;
else if ( ( V_1 & V_6 ) != 0 )
return 4 ;
else if ( ( V_1 & V_7 ) != 0 )
return 5 ;
else if ( ( V_1 & V_8 ) != 0 )
return 6 ;
else if ( ( V_1 & V_9 ) != 0 )
return 7 ;
else if ( ( V_1 & V_10 ) != 0 )
return 8 ;
else if ( ( V_1 & V_11 ) != 0 )
return 9 ;
else if ( ( V_1 & V_12 ) != 0 )
return 10 ;
else if ( ( V_1 & V_13 ) != 0 )
return 11 ;
return - 1 ;
}
static void
F_2 ( T_2 * V_14 , T_3 * T_4 V_15 , T_5 * V_16 ) {
T_6 * V_17 = NULL ;
T_5 * V_18 ;
T_7 V_19 = 0 ;
T_8 V_20 = F_3 ( V_14 ) ;
if ( V_20 >= V_21 )
{
if ( V_16 )
{
T_1 V_22 ;
V_17 = F_4 ( V_16 , V_23 , V_14 , 0 , V_21 , V_24 ) ;
V_18 = F_5 ( V_17 , V_25 ) ;
V_19 += 6 ;
V_22 = F_6 ( V_14 , V_19 ) ;
F_7 ( V_18 , V_26 , V_14 , V_19 , 2 , F_1 ( V_22 ) ) ;
F_4 ( V_18 , V_27 , V_14 , V_19 , 2 , V_28 ) ;
F_4 ( V_18 , V_29 , V_14 , V_19 , 2 , V_28 ) ;
V_19 += 2 ;
F_4 ( V_18 , V_30 , V_14 , V_19 , 8 , V_28 ) ;
}
}
}
T_9 F_8 ( T_2 * V_14 , T_7 V_19 )
{
return F_9 ( V_14 , V_19 ) == 0x01 &&
F_9 ( V_14 , V_19 + 1 ) == 0x01 &&
F_9 ( V_14 , V_19 + 2 ) == 0x05 &&
( F_9 ( V_14 , V_19 + 3 ) == 0x10 || F_9 ( V_14 , V_19 + 3 ) == 0x11 ) &&
F_9 ( V_14 , V_19 + 4 ) == 0x00 &&
F_9 ( V_14 , V_19 + 5 ) == 0x00 ;
}
void F_10 ( T_2 * V_14 , T_7 V_19 , T_3 * T_4 )
{
if ( V_31 . V_32 == NULL )
{
V_31 . V_33 = F_11 ( V_14 , V_19 + 8 ) ;
V_31 . V_32 = T_4 -> V_32 ;
V_31 . V_34 = T_4 -> V_32 -> V_34 ;
V_31 . V_35 = T_4 -> V_32 -> V_35 ;
}
else if ( ! T_4 -> V_32 -> V_22 . V_36 )
{
T_10 V_37 = F_11 ( V_14 , V_19 + 8 ) - V_31 . V_33 ;
T_10 V_38 = V_37 / 1000000000 ;
T_11 V_39 ;
T_11 V_40 ;
V_39 . V_37 = V_31 . V_35 . V_37 + ( int ) ( V_37 - ( V_38 * 1000000000 ) ) ;
if ( V_39 . V_37 > 1000000000 )
{
V_39 . V_37 -= 1000000000 ;
V_38 ++ ;
}
V_39 . V_38 = V_31 . V_35 . V_38 + ( int ) V_38 ;
F_12 ( & V_40 , & V_39 , & T_4 -> V_32 -> V_35 ) ;
T_4 -> V_32 -> V_35 = V_39 ;
F_13 ( & T_4 -> V_32 -> V_41 , & V_40 ) ;
F_13 ( & T_4 -> V_32 -> V_42 , & V_40 ) ;
F_13 ( & T_4 -> V_32 -> V_43 , & V_40 ) ;
}
}
static T_9
F_14 ( T_2 * V_14 , T_3 * T_4 , T_5 * V_16 )
{
static T_9 V_44 = FALSE ;
T_9 V_45 ;
T_2 * V_46 ;
T_8 V_20 = F_15 ( V_14 ) ;
if ( V_44 )
return FALSE ;
V_44 = TRUE ;
{
if ( V_31 . V_32 != NULL && ! T_4 -> V_32 -> V_22 . V_36 && T_4 -> V_32 -> V_34 <= V_31 . V_34 )
V_31 . V_32 = NULL ;
if ( F_15 ( V_14 ) < V_21 )
return FALSE ;
if ( F_8 ( V_14 , 0 ) )
{
F_2 ( V_14 , T_4 , V_16 ) ;
if ( V_47 != NULL )
{
V_46 = F_16 ( V_14 , V_21 ) ;
F_17 ( V_47 , V_46 , T_4 , V_16 ) ;
}
F_10 ( V_14 , 0 , T_4 ) ;
V_45 = TRUE ;
}
else if ( F_8 ( V_14 , V_20 - V_21 ) )
{
if ( V_47 != NULL )
{
V_46 = F_18 ( V_14 , 0 , V_20 - V_21 , V_20 - V_21 ) ;
F_17 ( V_47 , V_46 , T_4 , V_16 ) ;
}
V_46 = F_18 ( V_14 , V_20 - V_21 , V_21 , V_21 ) ;
F_2 ( V_46 , T_4 , V_16 ) ;
F_10 ( V_14 , V_20 - V_21 , T_4 ) ;
V_45 = TRUE ;
}
else
{
V_45 = FALSE ;
}
}
V_44 = FALSE ;
return V_45 ;
}
void
F_19 ( void ) {
static T_12 V_48 [] = {
{ & V_26 ,
{ L_1 , L_2 ,
V_49 , V_50 , NULL , 0x00 ,
NULL , V_51 }
} ,
{ & V_27 ,
{ L_3 , L_4 ,
V_52 , 16 , F_20 ( & V_53 ) , V_54 ,
NULL , V_51 }
} ,
{ & V_29 ,
{ L_5 , L_6 ,
V_52 , 16 , F_20 ( & V_53 ) , V_55 ,
NULL , V_51 }
} ,
{ & V_30 ,
{ L_7 , L_8 ,
V_56 , V_57 , NULL , 0x0 ,
NULL , V_51 }
} ,
} ;
static T_7 * V_58 [] = {
& V_25 ,
} ;
T_13 * V_59 ;
V_23 = F_21 ( L_9 ,
L_10 , L_11 ) ;
V_59 = F_22 ( V_23 , V_60 ) ;
F_23 ( V_59 , L_12 , L_13 ,
L_14 ,
& V_61 ) ;
F_24 ( V_23 , V_48 , F_25 ( V_48 ) ) ;
F_26 ( V_58 , F_25 ( V_58 ) ) ;
F_27 ( L_11 , F_2 , V_23 ) ;
}
void
V_60 ( void ) {
static T_9 V_62 = FALSE ;
if ( ! V_62 ) {
V_47 = F_28 ( L_15 ) ;
F_29 ( L_16 , F_14 , V_23 ) ;
V_62 = TRUE ;
}
F_30 ( V_23 , V_61 ) ;
}
