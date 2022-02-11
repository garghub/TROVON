static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_8 V_9 ;
struct V_10 * exp ;
struct V_11 * V_12 ;
unsigned int V_13 , V_14 , V_15 , V_16 , V_17 ;
char V_18 [ sizeof( L_1 ) ] , * V_19 ;
T_1 V_20 ;
T_2 V_21 ;
int V_22 = V_23 ;
F_2 (nf_nat_amanda_hook) V_24 ;
if ( F_3 ( V_7 ) == V_25 )
return V_23 ;
F_4 ( V_5 , V_2 , V_26 * V_27 ) ;
V_13 = V_3 + sizeof( struct V_28 ) ;
if ( V_13 >= V_2 -> V_20 ) {
F_5 ( L_2 , V_2 -> V_20 ) ;
return V_23 ;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_14 = F_6 ( V_2 , V_13 , V_2 -> V_20 ,
V_29 [ V_30 ] . V_9 , & V_9 ) ;
if ( V_14 == V_31 )
goto V_32;
V_14 += V_13 + V_29 [ V_30 ] . V_20 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_15 = F_6 ( V_2 , V_14 , V_2 -> V_20 ,
V_29 [ V_33 ] . V_9 , & V_9 ) ;
if ( V_15 == V_31 )
goto V_32;
V_15 += V_14 ;
for ( V_17 = V_34 ; V_17 <= V_35 ; V_17 ++ ) {
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_16 = F_6 ( V_2 , V_14 , V_15 , V_29 [ V_17 ] . V_9 , & V_9 ) ;
if ( V_16 == V_31 )
continue;
V_16 += V_14 + V_29 [ V_17 ] . V_20 ;
V_20 = F_7 (unsigned int, sizeof(pbuf) - 1 , stop - off) ;
if ( F_8 ( V_2 , V_16 , V_18 , V_20 ) )
break;
V_18 [ V_20 ] = '\0' ;
V_21 = F_9 ( F_10 ( V_18 , & V_19 , 10 ) ) ;
V_20 = V_19 - V_18 ;
if ( V_21 == 0 || V_20 > 5 )
break;
exp = F_11 ( V_5 ) ;
if ( exp == NULL ) {
F_12 ( V_2 , V_5 , L_3 ) ;
V_22 = V_36 ;
goto V_32;
}
V_12 = & V_5 -> V_37 [ V_25 ] . V_12 ;
F_13 ( exp , V_38 ,
F_14 ( V_5 ) ,
& V_12 -> V_39 . V_40 , & V_12 -> V_41 . V_40 ,
V_42 , NULL , & V_21 ) ;
V_24 = F_15 ( V_43 ) ;
if ( V_24 && V_5 -> V_44 & V_45 )
V_22 = V_24 ( V_2 , V_7 , V_3 ,
V_16 - V_13 , V_20 , exp ) ;
else if ( F_16 ( exp ) != 0 ) {
F_12 ( V_2 , V_5 , L_4 ) ;
V_22 = V_36 ;
}
F_17 ( exp ) ;
}
V_32:
return V_22 ;
}
static void T_3 F_18 ( void )
{
int V_17 ;
F_19 ( & V_46 [ 0 ] ) ;
F_19 ( & V_46 [ 1 ] ) ;
for ( V_17 = 0 ; V_17 < F_20 ( V_29 ) ; V_17 ++ )
F_21 ( V_29 [ V_17 ] . V_9 ) ;
}
static int T_4 F_22 ( void )
{
int V_22 , V_17 ;
for ( V_17 = 0 ; V_17 < F_20 ( V_29 ) ; V_17 ++ ) {
V_29 [ V_17 ] . V_9 = F_23 ( V_47 , V_29 [ V_17 ] . string ,
V_29 [ V_17 ] . V_20 ,
V_48 , V_49 ) ;
if ( F_24 ( V_29 [ V_17 ] . V_9 ) ) {
V_22 = F_25 ( V_29 [ V_17 ] . V_9 ) ;
goto V_50;
}
}
V_22 = F_26 ( & V_46 [ 0 ] ) ;
if ( V_22 < 0 )
goto V_50;
V_22 = F_26 ( & V_46 [ 1 ] ) ;
if ( V_22 < 0 )
goto V_51;
return 0 ;
V_51:
F_19 ( & V_46 [ 0 ] ) ;
V_50:
while ( -- V_17 >= 0 )
F_21 ( V_29 [ V_17 ] . V_9 ) ;
return V_22 ;
}
