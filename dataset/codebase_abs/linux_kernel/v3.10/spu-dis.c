static void
F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
{
int V_3 = V_4 [ V_1 ] . V_5 ;
if ( V_3 >= V_6 )
continue;
if ( V_7 [ V_3 ] == 0 )
V_7 [ V_3 ] = & V_4 [ V_1 ] ;
}
}
static const struct V_8 *
F_2 ( unsigned int V_9 )
{
const struct V_8 * V_10 ;
unsigned int V_5 = V_9 >> ( 32 - 11 ) ;
if ( V_7 [ 0 ] == 0 )
F_1 () ;
if ( ( V_10 = V_7 [ V_5 & 0x780 ] ) != 0
&& V_10 -> V_11 == V_12 )
return V_10 ;
if ( ( V_10 = V_7 [ V_5 & 0x7f0 ] ) != 0
&& ( V_10 -> V_11 == V_13 || V_10 -> V_11 == V_14 ) )
return V_10 ;
if ( ( V_10 = V_7 [ V_5 & 0x7f8 ] ) != 0
&& V_10 -> V_11 == V_15 )
return V_10 ;
if ( ( V_10 = V_7 [ V_5 & 0x7fc ] ) != 0
&& ( V_10 -> V_11 == V_16 ) )
return V_10 ;
if ( ( V_10 = V_7 [ V_5 & 0x7fe ] ) != 0
&& ( V_10 -> V_11 == V_17 ) )
return V_10 ;
if ( ( V_10 = V_7 [ V_5 & 0x7ff ] ) != 0 )
return V_10 ;
return NULL ;
}
int
F_3 ( unsigned long V_9 , unsigned long V_18 )
{
int V_19 ;
int V_20 ;
const struct V_8 * V_10 ;
enum V_21 V_22 ;
V_10 = F_2 ( V_9 ) ;
if ( V_10 == 0 )
{
printf ( L_1 , V_9 ) ;
}
else
{
int V_1 ;
int V_23 = 0 ;
V_22 = (enum V_21 ) ( V_10 - V_4 ) ;
printf ( L_2 , V_10 -> V_24 ) ;
if ( V_22 == V_25 || V_22 == V_26 || V_22 == V_27 || V_22 == V_28
|| V_22 == V_29 || V_22 == V_30 || V_22 == V_31 || V_22 == V_32
|| V_22 == V_33 || V_22 == V_34 )
{
int V_35 = ( V_9 >> ( 32 - 18 ) ) & 0x7f ;
if ( V_35 & 0x40 )
printf ( V_22 == V_33 ? L_3 : L_4 ) ;
if ( V_35 & 0x20 )
printf ( L_5 ) ;
if ( V_35 & 0x10 )
printf ( L_6 ) ;
}
if ( V_10 -> V_36 [ 0 ] != 0 )
printf ( L_7 ) ;
V_20 = 0 ;
for ( V_1 = 1 ; V_1 <= V_10 -> V_36 [ 0 ] ; V_1 ++ )
{
int V_36 = V_10 -> V_36 [ V_1 ] ;
if ( V_36 != V_37 && ! V_23 && V_1 > 1 )
printf ( L_8 ) ;
switch ( V_36 )
{
case V_38 :
printf ( L_9 ,
F_4 ( V_9 ) ) ;
break;
case V_39 :
printf ( L_9 ,
F_5 ( V_9 ) ) ;
break;
case V_40 :
printf ( L_9 ,
F_6 ( V_9 ) ) ;
break;
case V_41 :
printf ( L_9 ,
F_7 ( V_9 ) ) ;
break;
case V_42 :
printf ( L_10 ,
F_5 ( V_9 ) ) ;
break;
case V_43 :
printf ( L_11 ,
F_5 ( V_9 ) ) ;
break;
case V_37 :
V_23 ++ ;
printf ( L_12 ) ;
break;
case V_44 :
printf ( L_13 ,
173 - F_8 ( V_9 ) ) ;
break;
case V_45 :
printf ( L_13 ,
155 - F_8 ( V_9 ) ) ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_20 = F_9 ( V_9 ) ;
printf ( L_13 , V_20 ) ;
break;
case V_54 :
F_10 ( V_18 + F_11 ( V_9 ) * 4 ) ;
break;
case V_55 :
F_10 ( V_18 + F_12 ( V_9 ) * 4 ) ;
break;
case V_56 :
case V_57 :
V_20 = F_13 ( V_9 ) ;
printf ( L_13 , V_20 ) ;
break;
case V_58 :
V_20 = F_13 ( V_9 ) * 16 ;
printf ( L_13 , V_20 ) ;
break;
case V_59 :
V_20 = F_14 ( V_9 ) ;
printf ( L_13 , V_20 ) ;
break;
case V_60 :
V_20 = F_15 ( V_9 ) ;
printf ( L_14 , V_20 ) ;
break;
case V_61 :
V_19 = F_14 ( V_9 ) * 4 ;
if ( V_19 == 0 )
printf ( L_13 , V_19 ) ;
else
{
V_20 = V_18 + V_19 ;
F_10 ( V_20 & 0x3ffff ) ;
}
break;
case V_62 :
V_19 = F_15 ( V_9 ) * 4 ;
if ( V_19 == 0 )
printf ( L_13 , V_19 ) ;
else
F_10 ( V_19 ) ;
break;
case V_63 :
V_19 = F_16 ( V_9 ) ;
if ( V_19 == 0 || 1 )
{
V_20 = V_19 ;
printf ( L_14 , V_19 ) ;
}
else
F_10 ( V_19 ) ;
break;
case V_64 :
V_20 = F_17 ( V_9 ) ;
printf ( L_14 , V_20 ) ;
break;
}
if ( V_36 != V_37 && V_23 )
{
printf ( L_15 ) ;
V_23 -- ;
}
}
if ( V_20 > 16 )
printf ( L_16 , V_20 ) ;
}
return 4 ;
}
