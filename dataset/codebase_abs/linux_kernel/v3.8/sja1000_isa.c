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
unsigned long V_6 = ( unsigned long ) V_2 -> V_4 ;
F_8 ( V_3 , V_6 ) ;
return F_6 ( V_6 + 1 ) ;
}
static void F_10 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
unsigned long V_6 = ( unsigned long ) V_2 -> V_4 ;
F_8 ( V_3 , V_6 ) ;
F_8 ( V_5 , V_6 + 1 ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
void T_2 * V_6 = NULL ;
int V_11 = V_12 ;
int V_13 = V_8 -> V_14 ;
int V_15 ;
F_12 ( & V_8 -> V_10 , L_1 ,
V_13 , V_16 [ V_13 ] , V_17 [ V_13 ] , V_18 [ V_13 ] ) ;
if ( V_17 [ V_13 ] ) {
if ( ! F_13 ( V_17 [ V_13 ] , V_11 , V_19 ) ) {
V_15 = - V_20 ;
goto exit;
}
V_6 = F_14 ( V_17 [ V_13 ] , V_11 ) ;
if ( ! V_6 ) {
V_15 = - V_21 ;
goto V_22;
}
} else {
if ( V_23 [ V_13 ] > 0 ||
( V_23 [ V_13 ] == - 1 && V_23 [ 0 ] > 0 ) )
V_11 = V_24 ;
if ( ! F_15 ( V_16 [ V_13 ] , V_11 , V_19 ) ) {
V_15 = - V_20 ;
goto exit;
}
}
V_10 = F_16 ( 0 ) ;
if ( ! V_10 ) {
V_15 = - V_21 ;
goto V_25;
}
V_2 = F_17 ( V_10 ) ;
V_10 -> V_18 = V_18 [ V_13 ] ;
V_2 -> V_26 = V_27 ;
if ( V_17 [ V_13 ] ) {
V_2 -> V_4 = V_6 ;
V_10 -> V_28 = V_17 [ V_13 ] ;
V_2 -> V_29 = F_1 ;
V_2 -> V_30 = F_3 ;
} else {
V_2 -> V_4 = ( void T_2 * ) V_16 [ V_13 ] ;
V_10 -> V_28 = V_16 [ V_13 ] ;
if ( V_11 == V_24 ) {
V_2 -> V_29 = F_9 ;
V_2 -> V_30 = F_10 ;
} else {
V_2 -> V_29 = F_5 ;
V_2 -> V_30 = F_7 ;
}
}
if ( V_31 [ V_13 ] )
V_2 -> V_32 . clock . V_33 = V_31 [ V_13 ] / 2 ;
else if ( V_31 [ 0 ] )
V_2 -> V_32 . clock . V_33 = V_31 [ 0 ] / 2 ;
else
V_2 -> V_32 . clock . V_33 = V_34 / 2 ;
if ( V_35 [ V_13 ] != 0xff )
V_2 -> V_35 = V_35 [ V_13 ] ;
else if ( V_35 [ 0 ] != 0xff )
V_2 -> V_35 = V_35 [ 0 ] ;
else
V_2 -> V_35 = V_36 ;
if ( V_37 [ V_13 ] != 0xff )
V_2 -> V_37 = V_37 [ V_13 ] ;
else if ( V_37 [ 0 ] != 0xff )
V_2 -> V_37 = V_37 [ 0 ] ;
else
V_2 -> V_37 = V_38 ;
F_18 ( & V_8 -> V_10 , V_10 ) ;
F_19 ( V_10 , & V_8 -> V_10 ) ;
V_15 = F_20 ( V_10 ) ;
if ( V_15 ) {
F_21 ( & V_8 -> V_10 , L_2 ,
V_19 , V_15 ) ;
goto V_25;
}
F_22 ( & V_8 -> V_10 , L_3 ,
V_19 , V_2 -> V_4 , V_10 -> V_18 ) ;
return 0 ;
V_25:
if ( V_17 [ V_13 ] )
F_23 ( V_6 ) ;
V_22:
if ( V_17 [ V_13 ] )
F_24 ( V_17 [ V_13 ] , V_11 ) ;
else
F_25 ( V_16 [ V_13 ] , V_11 ) ;
exit:
return V_15 ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_27 ( & V_8 -> V_10 ) ;
struct V_1 * V_2 = F_17 ( V_10 ) ;
int V_13 = V_8 -> V_14 ;
F_28 ( V_10 ) ;
F_18 ( & V_8 -> V_10 , NULL ) ;
if ( V_17 [ V_13 ] ) {
F_23 ( V_2 -> V_4 ) ;
F_24 ( V_17 [ V_13 ] , V_12 ) ;
} else {
if ( V_2 -> V_29 == F_9 )
F_25 ( V_16 [ V_13 ] , V_24 ) ;
else
F_25 ( V_16 [ V_13 ] , V_12 ) ;
}
F_29 ( V_10 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
int V_13 , V_15 ;
for ( V_13 = 0 ; V_13 < V_39 ; V_13 ++ ) {
if ( ( V_16 [ V_13 ] || V_17 [ V_13 ] ) && V_18 [ V_13 ] ) {
V_40 [ V_13 ] =
F_31 ( V_19 , V_13 ) ;
if ( ! V_40 [ V_13 ] ) {
V_15 = - V_21 ;
goto V_41;
}
V_15 = F_32 ( V_40 [ V_13 ] ) ;
if ( V_15 ) {
F_33 ( V_40 [ V_13 ] ) ;
goto V_41;
}
F_34 ( L_4
L_5 ,
V_19 , V_13 , V_16 [ V_13 ] , V_17 [ V_13 ] , V_18 [ V_13 ] ) ;
} else if ( V_13 == 0 || V_16 [ V_13 ] || V_17 [ V_13 ] ) {
F_35 ( L_6 ,
V_19 ) ;
V_15 = - V_42 ;
goto V_41;
}
}
V_15 = F_36 ( & V_43 ) ;
if ( V_15 )
goto V_41;
F_37 ( L_7 ,
V_19 , V_39 ) ;
return 0 ;
V_41:
while ( -- V_13 >= 0 ) {
if ( V_40 [ V_13 ] )
F_38 ( V_40 [ V_13 ] ) ;
}
return V_15 ;
}
static void T_4 F_39 ( void )
{
int V_13 ;
F_40 ( & V_43 ) ;
for ( V_13 = 0 ; V_13 < V_39 ; V_13 ++ ) {
if ( V_40 [ V_13 ] )
F_38 ( V_40 [ V_13 ] ) ;
}
}
