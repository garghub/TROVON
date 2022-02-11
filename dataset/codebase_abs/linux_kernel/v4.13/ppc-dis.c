static long
F_1 ( const struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_4 )
{
long V_5 ;
int V_6 ;
if ( V_2 -> V_7 )
V_5 = (* V_2 -> V_7 ) ( V_3 , V_4 , & V_6 ) ;
else
{
if ( V_2 -> V_8 >= 0 )
V_5 = ( V_3 >> V_2 -> V_8 ) & V_2 -> V_9 ;
else
V_5 = ( V_3 << - V_2 -> V_8 ) & V_2 -> V_9 ;
if ( ( V_2 -> V_10 & V_11 ) != 0 )
{
unsigned long V_12 = V_2 -> V_9 ;
V_12 |= ( V_12 & - V_12 ) - 1 ;
V_12 &= ~ ( V_12 >> 1 ) ;
V_5 = ( V_5 ^ V_12 ) - V_12 ;
}
}
return V_5 ;
}
static int
F_2 ( const unsigned char * V_13 ,
unsigned long V_3 , T_1 V_4 )
{
const struct V_1 * V_2 ;
for (; * V_13 != 0 ; V_13 ++ )
{
V_2 = & V_14 [ * V_13 ] ;
if ( ( V_2 -> V_10 & V_15 ) != 0
|| ( ( V_2 -> V_10 & V_16 ) != 0
&& F_1 ( V_2 , V_3 , V_4 ) !=
F_3 ( V_2 ) ) )
return 0 ;
}
return 1 ;
}
static const struct V_17 *
F_4 ( unsigned long V_3 , T_1 V_4 )
{
const struct V_17 * V_18 ;
const struct V_17 * V_19 ;
unsigned long V_20 ;
V_20 = F_5 ( V_3 ) ;
V_19 = V_21 + V_22 ;
for ( V_18 = V_21 ; V_18 < V_19 ; ++ V_18 )
{
const unsigned char * V_13 ;
const struct V_1 * V_2 ;
int V_6 ;
if ( ( V_3 & V_18 -> V_23 ) != V_18 -> V_18
|| ( V_4 != ( T_1 ) - 1
&& ( ( V_18 -> V_10 & V_4 ) == 0
|| ( V_18 -> V_24 & V_4 ) != 0 ) ) )
continue;
V_6 = 0 ;
for ( V_13 = V_18 -> V_25 ; * V_13 != 0 ; V_13 ++ )
{
V_2 = V_14 + * V_13 ;
if ( V_2 -> V_7 )
(* V_2 -> V_7 ) ( V_3 , V_4 , & V_6 ) ;
}
if ( V_6 )
continue;
return V_18 ;
}
return NULL ;
}
int F_6 ( unsigned long V_3 , unsigned long V_26 )
{
const struct V_17 * V_18 ;
bool V_27 ;
T_1 V_4 ;
V_4 = V_28 | V_29
| V_30 | V_31 | V_32 ;
if ( F_7 ( V_33 ) )
V_4 |= V_34 ;
if ( F_7 ( V_35 ) )
V_4 |= ( V_36 | V_32 ) ;
if ( F_7 ( V_37 ) )
V_4 |= ( V_34 | V_38 | V_32 ) ;
if ( F_7 ( V_39 ) )
V_4 |= ( V_34 | V_38 | V_40
| V_32 | V_41 ) ;
if ( F_7 ( V_42 ) )
V_4 |= ( V_34 | V_38 | V_40
| V_43 | V_44
| V_32 | V_45 | V_41 ) ;
if ( F_7 ( V_46 ) )
V_4 |= ( V_34 | V_38 | V_40
| V_43 | V_47 | V_44
| V_32 | V_45
| V_41 | V_48 ) ,
V_18 = NULL ;
V_27 = false ;
if ( V_18 == NULL )
V_18 = F_4 ( V_3 , V_4 ) ;
if ( V_18 == NULL && ( V_4 & V_49 ) != 0 )
V_18 = F_4 ( V_3 , ( T_1 ) - 1 ) ;
if ( V_18 != NULL )
{
const unsigned char * V_13 ;
const struct V_1 * V_2 ;
int V_50 ;
int V_51 ;
int V_52 ;
if ( V_18 -> V_25 [ 0 ] != 0 )
printf ( L_1 , V_18 -> V_53 ) ;
else
printf ( L_2 , V_18 -> V_53 ) ;
if ( V_27 )
V_3 >>= 16 ;
V_50 = 0 ;
V_51 = 0 ;
V_52 = - 1 ;
for ( V_13 = V_18 -> V_25 ; * V_13 != 0 ; V_13 ++ )
{
long V_5 ;
V_2 = V_14 + * V_13 ;
if ( ( V_2 -> V_10 & V_54 ) != 0 )
continue;
if ( ( V_2 -> V_10 & V_16 ) != 0 )
{
if ( V_52 < 0 )
V_52 = F_2 ( V_13 , V_3 ,
V_4 ) ;
if ( V_52 )
continue;
}
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_50 )
{
printf ( L_3 ) ;
V_50 = 0 ;
}
if ( ( V_2 -> V_10 & V_55 ) != 0
|| ( ( V_2 -> V_10 & V_56 ) != 0 && V_5 != 0 ) )
printf ( L_4 , V_5 ) ;
else if ( ( V_2 -> V_10 & V_57 ) != 0 )
printf ( L_5 , V_5 ) ;
else if ( ( V_2 -> V_10 & V_58 ) != 0 )
printf ( L_6 , V_5 ) ;
else if ( ( V_2 -> V_10 & V_59 ) != 0 )
printf ( L_7 , V_5 ) ;
else if ( ( V_2 -> V_10 & V_60 ) != 0 )
F_8 ( V_26 + V_5 ) ;
else if ( ( V_2 -> V_10 & V_61 ) != 0 )
F_8 ( V_5 & 0xffffffff ) ;
else if ( ( V_2 -> V_10 & V_62 ) != 0 )
printf ( L_8 , V_5 ) ;
else if ( ( V_2 -> V_10 & V_63 ) != 0 )
printf ( L_9 , V_5 ) ;
else if ( ( V_2 -> V_10 & V_64 ) != 0 )
printf ( L_10 , V_5 ) ;
else if ( ( V_2 -> V_10 & V_65 ) != 0
&& ( ( ( V_4 & V_28 ) != 0 )
|| ( ( V_4 & V_66 ) != 0 ) ) )
printf ( L_11 , V_5 ) ;
else if ( ( ( V_2 -> V_10 & V_67 ) != 0 )
&& ( ( ( V_4 & V_28 ) != 0 )
|| ( ( V_4 & V_66 ) != 0 ) ) )
{
static const char * V_68 [ 4 ] = { L_12 , L_13 , L_14 , L_15 } ;
int V_69 ;
int V_70 ;
V_69 = V_5 >> 2 ;
if ( V_69 != 0 )
printf ( L_16 , V_69 ) ;
V_70 = V_5 & 3 ;
printf ( L_2 , V_68 [ V_70 ] ) ;
}
else
printf ( L_17 , ( int ) V_5 ) ;
if ( V_51 )
{
printf ( L_18 ) ;
V_51 = 0 ;
}
if ( ( V_2 -> V_10 & V_71 ) == 0 )
V_50 = 1 ;
else
{
printf ( L_19 ) ;
V_51 = 1 ;
}
}
if ( V_27 )
{
V_26 += 2 ;
return 2 ;
}
else
return 4 ;
}
printf ( L_20 , V_3 ) ;
return 4 ;
}
