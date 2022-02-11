static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_8 * exp ;
struct V_9 * V_10 ;
unsigned int V_11 , V_12 , V_13 , V_14 , V_15 ;
char V_16 [ sizeof( L_1 ) ] , * V_17 ;
T_1 V_18 ;
T_2 V_19 ;
int V_20 = V_21 ;
F_2 (nf_nat_amanda_hook) V_22 ;
if ( F_3 ( V_7 ) == V_23 )
return V_21 ;
F_4 ( V_5 , V_2 , V_24 * V_25 ) ;
V_11 = V_3 + sizeof( struct V_26 ) ;
if ( V_11 >= V_2 -> V_18 ) {
F_5 ( L_2 , V_2 -> V_18 ) ;
return V_21 ;
}
V_12 = F_6 ( V_2 , V_11 , V_2 -> V_18 ,
V_27 [ V_28 ] . V_29 ) ;
if ( V_12 == V_30 )
goto V_31;
V_12 += V_11 + V_27 [ V_28 ] . V_18 ;
V_13 = F_6 ( V_2 , V_12 , V_2 -> V_18 ,
V_27 [ V_32 ] . V_29 ) ;
if ( V_13 == V_30 )
goto V_31;
V_13 += V_12 ;
for ( V_15 = V_33 ; V_15 <= V_34 ; V_15 ++ ) {
V_14 = F_6 ( V_2 , V_12 , V_13 , V_27 [ V_15 ] . V_29 ) ;
if ( V_14 == V_30 )
continue;
V_14 += V_12 + V_27 [ V_15 ] . V_18 ;
V_18 = F_7 (unsigned int, sizeof(pbuf) - 1 , stop - off) ;
if ( F_8 ( V_2 , V_14 , V_16 , V_18 ) )
break;
V_16 [ V_18 ] = '\0' ;
V_19 = F_9 ( F_10 ( V_16 , & V_17 , 10 ) ) ;
V_18 = V_17 - V_16 ;
if ( V_19 == 0 || V_18 > 5 )
break;
exp = F_11 ( V_5 ) ;
if ( exp == NULL ) {
F_12 ( V_2 , V_5 , L_3 ) ;
V_20 = V_35 ;
goto V_31;
}
V_10 = & V_5 -> V_36 [ V_23 ] . V_10 ;
F_13 ( exp , V_37 ,
F_14 ( V_5 ) ,
& V_10 -> V_38 . V_39 , & V_10 -> V_40 . V_39 ,
V_41 , NULL , & V_19 ) ;
V_22 = F_15 ( V_42 ) ;
if ( V_22 && V_5 -> V_43 & V_44 )
V_20 = V_22 ( V_2 , V_7 , V_3 ,
V_14 - V_11 , V_18 , exp ) ;
else if ( F_16 ( exp ) != 0 ) {
F_12 ( V_2 , V_5 , L_4 ) ;
V_20 = V_35 ;
}
F_17 ( exp ) ;
}
V_31:
return V_20 ;
}
static void T_3 F_18 ( void )
{
int V_15 ;
F_19 ( & V_45 [ 0 ] ) ;
F_19 ( & V_45 [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < F_20 ( V_27 ) ; V_15 ++ )
F_21 ( V_27 [ V_15 ] . V_29 ) ;
}
static int T_4 F_22 ( void )
{
int V_20 , V_15 ;
for ( V_15 = 0 ; V_15 < F_20 ( V_27 ) ; V_15 ++ ) {
V_27 [ V_15 ] . V_29 = F_23 ( V_46 , V_27 [ V_15 ] . string ,
V_27 [ V_15 ] . V_18 ,
V_47 , V_48 ) ;
if ( F_24 ( V_27 [ V_15 ] . V_29 ) ) {
V_20 = F_25 ( V_27 [ V_15 ] . V_29 ) ;
goto V_49;
}
}
V_20 = F_26 ( & V_45 [ 0 ] ) ;
if ( V_20 < 0 )
goto V_49;
V_20 = F_26 ( & V_45 [ 1 ] ) ;
if ( V_20 < 0 )
goto V_50;
return 0 ;
V_50:
F_19 ( & V_45 [ 0 ] ) ;
V_49:
while ( -- V_15 >= 0 )
F_21 ( V_27 [ V_15 ] . V_29 ) ;
return V_20 ;
}
