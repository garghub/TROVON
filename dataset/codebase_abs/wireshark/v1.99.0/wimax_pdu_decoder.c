static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_4 V_5 , V_6 ;
T_4 V_7 , V_8 ;
T_4 V_9 , V_10 ;
T_5 * V_11 = NULL ;
T_3 * V_12 = NULL ;
#ifndef F_2
F_3 () ;
F_4 () ;
#endif
for( V_4 = 0 ; V_4 < F_5 ( V_1 ) ; )
{
if ( V_4 == 0 )
{
V_13 = TRUE ;
}
else
{
V_13 = FALSE ;
}
V_8 = F_6 ( V_1 , V_4 ) ;
V_7 = F_7 ( V_1 , V_4 ) ;
if( V_7 == V_14 )
{
V_11 = F_8 ( V_3 , V_15 , V_1 , V_4 , V_8 , L_1 , V_8 ) ;
V_12 = F_9 ( V_11 , V_16 ) ;
F_10 ( V_12 , V_17 , V_1 , V_4 , V_8 , V_18 ) ;
break;
}
else if( ( V_7 & V_19 ) == V_20 )
{
V_8 = ( ( F_11 ( V_1 , V_4 ) & V_21 ) >> 2 ) ;
if ( V_8 == 0 )
{
V_8 = 3 ;
}
F_12 ( V_22 , F_13 ( V_1 , V_4 , V_8 ) , V_2 , V_3 ) ;
V_4 += V_8 ;
continue;
}
else if( ( V_7 & V_19 ) == V_23 )
{
if( F_14 ( V_2 ) )
{
if ( ( V_7 & V_24 ) == V_24 )
{
V_8 = F_15 ( V_1 , V_2 , V_3 ) ;
}
else
{
V_8 = F_16 ( V_1 , V_2 , V_3 ) ;
}
V_4 += V_8 ;
continue;
}
}
else if( ( V_7 & V_25 ) == V_25 )
{
F_17 ( V_2 -> V_26 , V_27 , NULL , L_2 ) ;
V_11 = F_8 ( V_3 , V_15 , V_1 , V_4 , V_8 , L_3 , V_8 ) ;
V_12 = F_9 ( V_11 , V_16 ) ;
F_10 ( V_12 , V_17 , V_1 , V_4 , V_8 , V_18 ) ;
break;
}
V_10 = F_18 ( F_19 ( V_1 , V_4 , V_28 ) , V_28 ) ;
V_9 = F_7 ( V_1 , V_4 + V_29 - 1 ) ;
if( V_9 != V_10 )
{
F_17 ( V_2 -> V_26 , V_27 , NULL , L_4 ) ;
V_11 = F_8 ( V_3 , V_15 , V_1 , V_4 , V_29 , L_5 , V_9 , V_10 ) ;
V_12 = F_9 ( V_11 , V_16 ) ;
F_10 ( V_12 , V_17 , V_1 , V_4 , V_8 , V_18 ) ;
break;
}
V_5 = ( ( V_7 & V_30 ) ? 1 : 0 ) ;
V_6 = ( ( V_7 & V_31 ) ? 1 : 0 ) ;
if( ! V_5 )
{
V_8 = ( F_7 ( V_1 , V_4 + 1 ) & V_32 ) ;
V_8 = ( ( V_8 << 8 ) | F_7 ( V_1 , V_4 + 2 ) ) ;
}
else
{
V_8 = V_29 ;
}
V_11 = F_8 ( V_3 , V_15 , V_1 , V_4 , V_8 , L_6 , V_8 ) ;
V_12 = F_9 ( V_11 , V_16 ) ;
if ( V_8 == 0 ) {
V_4 += 6 ;
continue;
}
if( V_5 )
{
if( V_6 )
{
F_20 ( V_11 , L_7 ) ;
F_12 ( V_33 , F_13 ( V_1 , V_4 , V_8 ) , V_2 , V_12 ) ;
}
else
{
F_20 ( V_11 , L_8 ) ;
F_12 ( V_34 , F_13 ( V_1 , V_4 , V_8 ) , V_2 , V_12 ) ;
}
}
else
{
F_12 ( V_35 , F_13 ( V_1 , V_4 , V_8 ) , V_2 , V_12 ) ;
}
V_4 += V_8 ;
}
}
void F_21 ( void )
{
static T_6 V_36 [] =
{
{
& V_17 ,
{
L_9 , L_10 ,
V_37 , V_38 , NULL , 0x0 ,
NULL , V_39
}
} ,
} ;
static T_7 * V_40 [] =
{
& V_16 ,
} ;
V_15 = V_41 ;
F_22 ( L_11 , F_1 , - 1 ) ;
F_23 ( V_15 , V_36 , F_24 ( V_36 ) ) ;
F_25 ( V_40 , F_24 ( V_40 ) ) ;
}
void
F_26 ( void )
{
V_35 = F_27 ( L_12 ) ;
V_34 = F_27 ( L_13 ) ;
V_33 = F_27 ( L_14 ) ;
V_22 = F_27 ( L_15 ) ;
}
