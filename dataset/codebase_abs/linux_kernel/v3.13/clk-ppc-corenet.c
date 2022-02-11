static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = ( ( V_3 / V_7 ) << 2 ) + V_3 % V_7 ;
if ( V_5 -> V_8 & V_9 )
V_6 += 8 ;
V_6 = ( V_6 & 0xf ) << V_10 ;
F_3 ( V_6 , V_5 -> V_11 ) ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_5 ( V_5 -> V_11 ) ;
V_6 = ( V_6 >> V_10 ) & 0xf ;
if ( V_5 -> V_8 & V_9 )
V_6 -= 8 ;
V_6 = ( V_6 >> 2 ) * V_7 + V_6 % 4 ;
return V_6 ;
}
static void T_3 F_6 ( struct V_12 * V_13 )
{
struct V_5 * V_5 ;
struct V_14 V_15 ;
struct V_4 * V_4 ;
struct V_12 * V_16 ;
int V_17 , V_18 , V_19 ;
T_2 V_20 ;
const char * V_21 ;
const char * * V_22 ;
V_17 = F_7 ( V_13 , L_1 , & V_20 ) ;
if ( V_17 ) {
F_8 ( L_2 , V_13 -> V_23 ) ;
return;
}
V_18 = F_9 ( V_13 , L_3 ) ;
if ( V_18 < 0 ) {
F_8 ( L_4 , V_13 -> V_23 ) ;
return;
}
V_22 = F_10 ( ( sizeof( char * ) * V_18 ) , V_24 ) ;
if ( ! V_22 ) {
F_8 ( L_5 , V_25 ) ;
return;
}
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ )
V_22 [ V_19 ] = F_11 ( V_13 , V_19 ) ;
V_4 = F_10 ( sizeof( struct V_4 ) , V_24 ) ;
if ( ! V_4 ) {
F_8 ( L_6 , V_25 ) ;
goto V_26;
}
V_4 -> V_11 = V_27 + V_20 ;
V_16 = F_12 ( NULL , NULL , L_7 ) ;
if ( V_16 && ( V_20 >= 0x80 ) )
V_4 -> V_8 = V_9 ;
V_17 = F_13 ( V_13 , L_8 ,
0 , & V_21 ) ;
if ( V_17 ) {
F_8 ( L_9 , V_13 -> V_23 ) ;
goto V_28;
}
V_15 . V_23 = V_21 ;
V_15 . V_29 = & V_30 ;
V_15 . V_22 = V_22 ;
V_15 . V_31 = V_18 ;
V_15 . V_8 = 0 ;
V_4 -> V_2 . V_15 = & V_15 ;
V_5 = F_14 ( NULL , & V_4 -> V_2 ) ;
if ( F_15 ( V_5 ) ) {
F_8 ( L_10 , V_21 ) ;
goto V_28;
}
V_17 = F_16 ( V_13 , V_32 , V_5 ) ;
if ( V_17 ) {
F_8 ( L_11 ,
V_13 -> V_23 ) ;
goto V_28;
}
goto V_26;
V_28:
F_17 ( V_4 ) ;
V_26:
F_17 ( V_22 ) ;
}
static void T_3 F_18 ( struct V_12 * V_13 )
{
T_2 V_20 , V_33 ;
int V_19 , V_17 , V_18 ;
const char * V_21 , * V_34 ;
struct V_35 * V_36 ;
struct V_5 * * V_37 ;
V_17 = F_7 ( V_13 , L_1 , & V_20 ) ;
if ( V_17 ) {
F_8 ( L_2 , V_13 -> V_23 ) ;
return;
}
V_33 = F_5 ( V_27 + V_20 ) ;
if ( V_33 & V_38 ) {
F_19 ( L_12 , V_13 -> V_23 ) ;
return;
}
V_33 = ( V_33 >> 1 ) & 0x3f ;
V_34 = F_11 ( V_13 , 0 ) ;
if ( ! V_34 ) {
F_8 ( L_13 , V_13 -> V_23 ) ;
return;
}
V_18 = F_9 ( V_13 , L_8 ) ;
if ( V_18 < 0 || V_18 > 4 ) {
F_8 ( L_14 , V_13 -> V_23 ) ;
return;
}
V_7 = V_18 ;
V_37 = F_10 ( sizeof( struct V_5 * ) * V_18 , V_24 ) ;
if ( ! V_37 ) {
F_8 ( L_15 , V_25 ) ;
return;
}
V_36 = F_10 ( sizeof( struct V_35 ) , V_24 ) ;
if ( ! V_36 ) {
F_8 ( L_16 , V_25 ) ;
goto V_39;
}
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
V_17 = F_13 ( V_13 , L_8 ,
V_19 , & V_21 ) ;
if ( V_17 ) {
F_8 ( L_17 , V_13 -> V_23 ) ;
goto V_40;
}
if ( V_18 == 4 )
V_37 [ V_19 ] = F_20 ( NULL , V_21 ,
V_34 , 0 , V_33 , 1 + V_19 ) ;
else
V_37 [ V_19 ] = F_20 ( NULL , V_21 ,
V_34 , 0 , V_33 , 1 << V_19 ) ;
if ( F_15 ( V_37 [ V_19 ] ) ) {
F_8 ( L_10 , V_21 ) ;
goto V_40;
}
}
V_36 -> V_41 = V_37 ;
V_36 -> V_42 = V_18 ;
V_17 = F_16 ( V_13 , V_43 , V_36 ) ;
if ( V_17 ) {
F_8 ( L_18 ,
V_13 -> V_23 ) ;
goto V_40;
}
return;
V_40:
F_17 ( V_36 ) ;
V_39:
F_17 ( V_37 ) ;
}
static int T_3 F_21 ( struct V_44 * V_45 )
{
struct V_12 * V_13 ;
V_13 = V_45 -> V_46 . V_47 ;
V_27 = F_22 ( V_13 , 0 ) ;
if ( ! V_27 ) {
F_23 ( & V_45 -> V_46 , L_19 ) ;
return - V_48 ;
}
F_24 ( V_49 ) ;
return 0 ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_50 ) ;
}
