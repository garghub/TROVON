static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( const struct V_1 * V_2 , int V_3 )
{
return F_6 ( ( unsigned long ) V_2 -> V_4 + V_3 ) ;
}
static void F_7 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
F_8 ( V_5 , ( unsigned long ) V_2 -> V_4 + V_3 ) ;
}
static T_1 F_9 ( const struct V_1 * V_2 ,
int V_3 )
{
unsigned long V_6 , V_7 = ( unsigned long ) V_2 -> V_4 ;
T_1 V_8 ;
F_10 ( & V_9 [ V_2 -> V_10 -> V_11 ] , V_6 ) ;
F_8 ( V_3 , V_7 ) ;
V_8 = F_6 ( V_7 + 1 ) ;
F_11 ( & V_9 [ V_2 -> V_10 -> V_11 ] , V_6 ) ;
return V_8 ;
}
static void F_12 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
unsigned long V_6 , V_7 = ( unsigned long ) V_2 -> V_4 ;
F_10 ( & V_9 [ V_2 -> V_10 -> V_11 ] , V_6 ) ;
F_8 ( V_3 , V_7 ) ;
F_8 ( V_5 , V_7 + 1 ) ;
F_11 ( & V_9 [ V_2 -> V_10 -> V_11 ] , V_6 ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_14 * V_10 ;
struct V_1 * V_2 ;
void T_2 * V_7 = NULL ;
int V_15 = V_16 ;
int V_17 = V_13 -> V_18 ;
int V_19 ;
F_14 ( & V_13 -> V_10 , L_1 ,
V_17 , V_20 [ V_17 ] , V_21 [ V_17 ] , V_22 [ V_17 ] ) ;
if ( V_21 [ V_17 ] ) {
if ( ! F_15 ( V_21 [ V_17 ] , V_15 , V_23 ) ) {
V_19 = - V_24 ;
goto exit;
}
V_7 = F_16 ( V_21 [ V_17 ] , V_15 ) ;
if ( ! V_7 ) {
V_19 = - V_25 ;
goto V_26;
}
} else {
if ( V_27 [ V_17 ] > 0 ||
( V_27 [ V_17 ] == - 1 && V_27 [ 0 ] > 0 ) )
V_15 = V_28 ;
if ( ! F_17 ( V_20 [ V_17 ] , V_15 , V_23 ) ) {
V_19 = - V_24 ;
goto exit;
}
}
V_10 = F_18 ( 0 ) ;
if ( ! V_10 ) {
V_19 = - V_25 ;
goto V_29;
}
V_2 = F_19 ( V_10 ) ;
V_10 -> V_22 = V_22 [ V_17 ] ;
V_2 -> V_30 = V_31 ;
if ( V_21 [ V_17 ] ) {
V_2 -> V_4 = V_7 ;
V_10 -> V_32 = V_21 [ V_17 ] ;
V_2 -> V_33 = F_1 ;
V_2 -> V_34 = F_3 ;
} else {
V_2 -> V_4 = ( void T_2 * ) V_20 [ V_17 ] ;
V_10 -> V_32 = V_20 [ V_17 ] ;
if ( V_15 == V_28 ) {
V_2 -> V_33 = F_9 ;
V_2 -> V_34 = F_12 ;
F_20 ( & V_9 [ V_17 ] ) ;
} else {
V_2 -> V_33 = F_5 ;
V_2 -> V_34 = F_7 ;
}
}
if ( V_35 [ V_17 ] )
V_2 -> V_36 . clock . V_37 = V_35 [ V_17 ] / 2 ;
else if ( V_35 [ 0 ] )
V_2 -> V_36 . clock . V_37 = V_35 [ 0 ] / 2 ;
else
V_2 -> V_36 . clock . V_37 = V_38 / 2 ;
if ( V_39 [ V_17 ] != 0xff )
V_2 -> V_39 = V_39 [ V_17 ] ;
else if ( V_39 [ 0 ] != 0xff )
V_2 -> V_39 = V_39 [ 0 ] ;
else
V_2 -> V_39 = V_40 ;
if ( V_41 [ V_17 ] != 0xff )
V_2 -> V_41 = V_41 [ V_17 ] ;
else if ( V_41 [ 0 ] != 0xff )
V_2 -> V_41 = V_41 [ 0 ] ;
else
V_2 -> V_41 = V_42 ;
F_21 ( V_13 , V_10 ) ;
F_22 ( V_10 , & V_13 -> V_10 ) ;
V_10 -> V_11 = V_17 ;
V_19 = F_23 ( V_10 ) ;
if ( V_19 ) {
F_24 ( & V_13 -> V_10 , L_2 ,
V_23 , V_19 ) ;
goto V_29;
}
F_25 ( & V_13 -> V_10 , L_3 ,
V_23 , V_2 -> V_4 , V_10 -> V_22 ) ;
return 0 ;
V_29:
if ( V_21 [ V_17 ] )
F_26 ( V_7 ) ;
V_26:
if ( V_21 [ V_17 ] )
F_27 ( V_21 [ V_17 ] , V_15 ) ;
else
F_28 ( V_20 [ V_17 ] , V_15 ) ;
exit:
return V_19 ;
}
static int F_29 ( struct V_12 * V_13 )
{
struct V_14 * V_10 = F_30 ( V_13 ) ;
struct V_1 * V_2 = F_19 ( V_10 ) ;
int V_17 = V_13 -> V_18 ;
F_31 ( V_10 ) ;
if ( V_21 [ V_17 ] ) {
F_26 ( V_2 -> V_4 ) ;
F_27 ( V_21 [ V_17 ] , V_16 ) ;
} else {
if ( V_2 -> V_33 == F_9 )
F_28 ( V_20 [ V_17 ] , V_28 ) ;
else
F_28 ( V_20 [ V_17 ] , V_16 ) ;
}
F_32 ( V_10 ) ;
return 0 ;
}
static int T_3 F_33 ( void )
{
int V_17 , V_19 ;
for ( V_17 = 0 ; V_17 < V_43 ; V_17 ++ ) {
if ( ( V_20 [ V_17 ] || V_21 [ V_17 ] ) && V_22 [ V_17 ] ) {
V_44 [ V_17 ] =
F_34 ( V_23 , V_17 ) ;
if ( ! V_44 [ V_17 ] ) {
V_19 = - V_25 ;
goto V_45;
}
V_19 = F_35 ( V_44 [ V_17 ] ) ;
if ( V_19 ) {
F_36 ( V_44 [ V_17 ] ) ;
goto V_45;
}
F_37 ( L_4
L_5 ,
V_23 , V_17 , V_20 [ V_17 ] , V_21 [ V_17 ] , V_22 [ V_17 ] ) ;
} else if ( V_17 == 0 || V_20 [ V_17 ] || V_21 [ V_17 ] ) {
F_38 ( L_6 ,
V_23 ) ;
V_19 = - V_46 ;
goto V_45;
}
}
V_19 = F_39 ( & V_47 ) ;
if ( V_19 )
goto V_45;
F_40 ( L_7 ,
V_23 , V_43 ) ;
return 0 ;
V_45:
while ( -- V_17 >= 0 ) {
if ( V_44 [ V_17 ] )
F_41 ( V_44 [ V_17 ] ) ;
}
return V_19 ;
}
static void T_4 F_42 ( void )
{
int V_17 ;
F_43 ( & V_47 ) ;
for ( V_17 = 0 ; V_17 < V_43 ; V_17 ++ ) {
if ( V_44 [ V_17 ] )
F_41 ( V_44 [ V_17 ] ) ;
}
}
