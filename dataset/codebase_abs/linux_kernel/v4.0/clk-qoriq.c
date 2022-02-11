static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = ( ( V_3 / V_5 -> V_7 ) << 2 ) + V_3 % V_5 -> V_7 ;
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
V_6 = ( V_6 >> 2 ) * V_5 -> V_7 + V_6 % 4 ;
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
struct V_23 V_24 ;
V_17 = F_7 ( V_13 , L_1 , & V_20 ) ;
if ( V_17 ) {
F_8 ( L_2 , V_13 -> V_25 ) ;
return;
}
V_18 = F_9 ( V_13 , L_3 ) ;
if ( V_18 < 0 ) {
F_8 ( L_4 , V_13 -> V_25 ) ;
return;
}
V_22 = F_10 ( V_18 , sizeof( char * ) , V_26 ) ;
if ( ! V_22 )
return;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ )
V_22 [ V_19 ] = F_11 ( V_13 , V_19 ) ;
V_4 = F_12 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
goto V_27;
V_4 -> V_11 = F_13 ( V_13 , 0 ) ;
if ( ! V_4 -> V_11 ) {
F_8 ( L_5 , V_28 ) ;
goto V_29;
}
V_17 = F_14 ( V_13 , L_6 , L_7 , 0 ,
& V_24 ) ;
if ( V_17 ) {
F_8 ( L_8 , V_28 ) ;
goto V_29;
}
V_4 -> V_7 = F_9 ( V_24 . V_13 ,
L_9 ) ;
F_15 ( V_24 . V_13 ) ;
V_16 = F_16 ( NULL , NULL , L_10 ) ;
if ( V_16 && ( V_20 >= 0x80 ) )
V_4 -> V_8 = V_9 ;
V_17 = F_17 ( V_13 , L_9 ,
0 , & V_21 ) ;
if ( V_17 ) {
F_8 ( L_11 , V_13 -> V_25 ) ;
goto V_29;
}
V_15 . V_25 = V_21 ;
V_15 . V_30 = & V_31 ;
V_15 . V_22 = V_22 ;
V_15 . V_32 = V_18 ;
V_15 . V_8 = 0 ;
V_4 -> V_2 . V_15 = & V_15 ;
V_5 = F_18 ( NULL , & V_4 -> V_2 ) ;
if ( F_19 ( V_5 ) ) {
F_8 ( L_12 , V_21 ) ;
goto V_29;
}
V_17 = F_20 ( V_13 , V_33 , V_5 ) ;
if ( V_17 ) {
F_8 ( L_13 ,
V_13 -> V_25 ) ;
goto V_29;
}
goto V_27;
V_29:
F_21 ( V_4 ) ;
V_27:
F_21 ( V_22 ) ;
}
static void T_3 F_22 ( struct V_12 * V_13 )
{
T_2 V_34 ;
int V_19 , V_17 , V_18 ;
const char * V_21 , * V_35 ;
struct V_36 * V_37 ;
struct V_5 * * V_38 ;
void T_4 * V_39 ;
V_39 = F_13 ( V_13 , 0 ) ;
if ( ! V_39 ) {
F_8 ( L_14 ) ;
return;
}
V_34 = F_5 ( V_39 ) ;
if ( V_34 & V_40 ) {
F_23 ( L_15 , V_13 -> V_25 ) ;
goto V_41;
}
V_34 = ( V_34 >> 1 ) & 0x3f ;
V_35 = F_11 ( V_13 , 0 ) ;
if ( ! V_35 ) {
F_8 ( L_16 , V_13 -> V_25 ) ;
goto V_41;
}
V_18 = F_9 ( V_13 , L_9 ) ;
if ( V_18 < 0 || V_18 > 4 ) {
F_8 ( L_17 , V_13 -> V_25 ) ;
goto V_41;
}
V_38 = F_10 ( V_18 , sizeof( struct V_5 * ) , V_26 ) ;
if ( ! V_38 )
goto V_41;
V_37 = F_24 ( sizeof( * V_37 ) , V_26 ) ;
if ( ! V_37 )
goto V_42;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
V_17 = F_17 ( V_13 , L_9 ,
V_19 , & V_21 ) ;
if ( V_17 ) {
F_8 ( L_18 , V_13 -> V_25 ) ;
goto V_43;
}
if ( V_18 == 4 )
V_38 [ V_19 ] = F_25 ( NULL , V_21 ,
V_35 , 0 , V_34 , 1 + V_19 ) ;
else
V_38 [ V_19 ] = F_25 ( NULL , V_21 ,
V_35 , 0 , V_34 , 1 << V_19 ) ;
if ( F_19 ( V_38 [ V_19 ] ) ) {
F_8 ( L_12 , V_21 ) ;
goto V_43;
}
}
V_37 -> V_44 = V_38 ;
V_37 -> V_45 = V_18 ;
V_17 = F_20 ( V_13 , V_46 , V_37 ) ;
if ( V_17 ) {
F_8 ( L_19 ,
V_13 -> V_25 ) ;
goto V_43;
}
F_26 ( V_39 ) ;
return;
V_43:
F_21 ( V_37 ) ;
V_42:
F_21 ( V_38 ) ;
V_41:
F_26 ( V_39 ) ;
}
static void T_3 F_27 ( struct V_12 * V_16 )
{
struct V_5 * V_5 ;
const char * V_21 = V_16 -> V_25 ;
struct V_12 * V_13 = F_28 ( V_16 ) ;
T_2 V_47 ;
if ( ! V_13 ) {
F_8 ( L_20 ) ;
return;
}
if ( F_7 ( V_13 , L_21 , & V_47 ) ) {
F_15 ( V_16 ) ;
return;
}
F_29 ( V_13 , L_9 , & V_21 ) ;
V_5 = F_30 ( NULL , V_21 , NULL , V_48 , V_47 ) ;
if ( ! F_19 ( V_5 ) )
F_20 ( V_13 , V_33 , V_5 ) ;
}
static void T_3 F_31 ( struct V_12 * V_13 )
{
void T_4 * V_39 ;
T_5 V_34 ;
const char * V_35 , * V_21 ;
int V_19 , V_49 ;
struct V_36 * V_50 ;
V_39 = F_13 ( V_13 , 0 ) ;
if ( ! V_39 ) {
F_8 ( L_22 , V_28 , V_13 -> V_25 ) ;
return;
}
V_34 = F_5 ( V_39 ) ;
F_26 ( V_39 ) ;
if ( V_34 & V_40 ) {
F_23 ( L_23 , V_28 , V_13 -> V_25 ) ;
return;
}
V_34 = ( V_34 & F_32 ( 6 , 1 ) ) >> 1 ;
V_35 = F_11 ( V_13 , 0 ) ;
if ( ! V_35 ) {
F_8 ( L_24 ,
V_28 , V_13 -> V_25 ) ;
return;
}
V_19 = F_9 ( V_13 , L_9 ) ;
if ( V_19 < 0 ) {
F_8 ( L_25 ,
V_28 , V_13 -> V_25 , V_19 ) ;
return;
}
V_50 = F_24 ( sizeof( * V_50 ) + V_19 * sizeof( struct V_5 * ) , V_26 ) ;
if ( ! V_50 )
return;
V_50 -> V_44 = (struct V_5 * * ) ( V_50 + 1 ) ;
V_50 -> V_45 = V_19 ;
for ( V_19 = 0 ; V_19 < V_50 -> V_45 ; V_19 ++ ) {
V_49 = F_17 ( V_13 , L_9 ,
V_19 , & V_21 ) ;
if ( V_49 < 0 ) {
F_8 ( L_26 ,
V_28 , V_13 -> V_25 , V_49 ) ;
goto V_51;
}
V_50 -> V_44 [ V_19 ] = F_25 ( NULL , V_21 ,
V_35 , 0 , V_34 , 1 + V_19 ) ;
if ( F_19 ( V_50 -> V_44 [ V_19 ] ) ) {
F_8 ( L_27 ,
V_28 , V_13 -> V_25 ,
V_21 , F_33 ( V_50 -> V_44 [ V_19 ] ) ) ;
goto V_51;
}
}
V_49 = F_20 ( V_13 , V_46 , V_50 ) ;
if ( V_49 < 0 ) {
F_8 ( L_28 ,
V_28 , V_13 -> V_25 , V_49 ) ;
goto V_51;
}
return;
V_51:
while ( -- V_19 >= 0 )
F_34 ( V_50 -> V_44 [ V_19 ] ) ;
F_21 ( V_50 ) ;
}
