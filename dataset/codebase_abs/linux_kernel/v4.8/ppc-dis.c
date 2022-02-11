int
F_1 ( unsigned long V_1 , unsigned long V_2 )
{
const struct V_3 * V_4 ;
const struct V_3 * V_5 ;
unsigned long V_6 ;
int V_7 ;
V_7 = V_8 | V_9 | V_10
| V_11 | V_12 | V_13 ;
if ( F_2 ( V_14 ) )
V_7 |= V_15 ;
if ( F_2 ( V_16 ) )
V_7 |= V_17 | V_13 ;
if ( F_2 ( V_18 ) )
V_7 |= V_15 | V_19 | V_13 ;
V_6 = F_3 ( V_1 ) ;
V_5 = V_20 + V_21 ;
V_22:
for ( V_4 = V_20 ; V_4 < V_5 ; V_4 ++ )
{
unsigned long V_23 ;
const unsigned char * V_24 ;
const struct V_25 * V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
V_23 = F_3 ( V_4 -> V_4 ) ;
if ( V_6 < V_23 )
break;
if ( V_6 > V_23 )
continue;
if ( ( V_1 & V_4 -> V_30 ) != V_4 -> V_4
|| ( V_4 -> V_31 & V_7 ) == 0 )
continue;
V_27 = 0 ;
for ( V_24 = V_4 -> V_32 ; * V_24 != 0 ; V_24 ++ )
{
V_26 = V_33 + * V_24 ;
if ( V_26 -> V_34 )
(* V_26 -> V_34 ) ( V_1 , V_7 , & V_27 ) ;
}
if ( V_27 )
continue;
printf ( L_1 , V_4 -> V_35 ) ;
if ( V_4 -> V_32 [ 0 ] != 0 )
printf ( L_2 ) ;
V_28 = 0 ;
V_29 = 0 ;
for ( V_24 = V_4 -> V_32 ; * V_24 != 0 ; V_24 ++ )
{
long V_36 ;
V_26 = V_33 + * V_24 ;
if ( ( V_26 -> V_31 & V_37 ) != 0 )
continue;
if ( V_26 -> V_34 )
V_36 = (* V_26 -> V_34 ) ( V_1 , V_7 , & V_27 ) ;
else
{
V_36 = ( V_1 >> V_26 -> V_38 ) & ( ( 1 << V_26 -> V_39 ) - 1 ) ;
if ( ( V_26 -> V_31 & V_40 ) != 0
&& ( V_36 & ( 1 << ( V_26 -> V_39 - 1 ) ) ) != 0 )
V_36 -= 1 << V_26 -> V_39 ;
}
if ( ( V_26 -> V_31 & V_41 ) != 0
&& ( V_26 -> V_31 & V_42 ) == 0
&& V_36 == 0 )
continue;
if ( V_28 )
{
printf ( L_3 ) ;
V_28 = 0 ;
}
if ( ( V_26 -> V_31 & V_43 ) != 0
|| ( ( V_26 -> V_31 & V_44 ) != 0 && V_36 != 0 ) )
printf ( L_4 , V_36 ) ;
else if ( ( V_26 -> V_31 & V_45 ) != 0 )
printf ( L_5 , V_36 ) ;
else if ( ( V_26 -> V_31 & V_46 ) != 0 )
printf ( L_6 , V_36 ) ;
else if ( ( V_26 -> V_31 & V_47 ) != 0 )
F_4 ( V_2 + V_36 ) ;
else if ( ( V_26 -> V_31 & V_48 ) != 0 )
F_4 ( V_36 & 0xffffffff ) ;
else if ( ( V_26 -> V_31 & V_49 ) == 0
|| ( V_7 & V_8 ) == 0 )
printf ( L_7 , V_36 ) ;
else
{
if ( V_26 -> V_39 == 3 )
printf ( L_8 , V_36 ) ;
else
{
static const char * V_50 [ 4 ] = { L_9 , L_10 , L_11 , L_12 } ;
int V_51 ;
int V_52 ;
V_51 = V_36 >> 2 ;
if ( V_51 != 0 )
printf ( L_13 , V_51 ) ;
V_52 = V_36 & 3 ;
printf ( L_1 , V_50 [ V_52 ] ) ;
}
}
if ( V_29 )
{
printf ( L_14 ) ;
V_29 = 0 ;
}
if ( ( V_26 -> V_31 & V_53 ) == 0 )
V_28 = 1 ;
else
{
printf ( L_15 ) ;
V_29 = 1 ;
}
}
return 4 ;
}
if ( ( V_7 & V_54 ) != 0 )
{
V_7 = ~ V_54 ;
goto V_22;
}
printf ( L_16 , V_1 ) ;
return 4 ;
}
