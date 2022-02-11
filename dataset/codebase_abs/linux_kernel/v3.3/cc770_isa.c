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
unsigned long V_7 ;
T_1 V_5 ;
F_10 ( & V_8 , V_7 ) ;
F_8 ( V_3 , V_6 ) ;
V_5 = F_6 ( V_6 + 1 ) ;
F_11 ( & V_8 , V_7 ) ;
return V_5 ;
}
static void F_12 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
unsigned long V_6 = ( unsigned long ) V_2 -> V_4 ;
unsigned long V_7 ;
F_10 ( & V_8 , V_7 ) ;
F_8 ( V_3 , V_6 ) ;
F_8 ( V_5 , V_6 + 1 ) ;
F_11 ( & V_8 , V_7 ) ;
}
static int T_2 F_13 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
void T_3 * V_6 = NULL ;
int V_13 = V_14 ;
int V_15 = V_10 -> V_16 ;
int V_17 ;
T_4 V_18 ;
F_14 ( & V_10 -> V_12 , L_1 ,
V_15 , V_19 [ V_15 ] , V_20 [ V_15 ] , V_21 [ V_15 ] ) ;
if ( V_20 [ V_15 ] ) {
if ( ! F_15 ( V_20 [ V_15 ] , V_13 , V_22 ) ) {
V_17 = - V_23 ;
goto exit;
}
V_6 = F_16 ( V_20 [ V_15 ] , V_13 ) ;
if ( ! V_6 ) {
V_17 = - V_24 ;
goto V_25;
}
} else {
if ( V_26 [ V_15 ] > 0 ||
( V_26 [ V_15 ] == - 1 && V_26 [ 0 ] > 0 ) )
V_13 = V_27 ;
if ( ! F_17 ( V_19 [ V_15 ] , V_13 , V_22 ) ) {
V_17 = - V_23 ;
goto exit;
}
}
V_12 = F_18 ( 0 ) ;
if ( ! V_12 ) {
V_17 = - V_24 ;
goto V_28;
}
V_2 = F_19 ( V_12 ) ;
V_12 -> V_21 = V_21 [ V_15 ] ;
V_2 -> V_29 = V_30 ;
if ( V_20 [ V_15 ] ) {
V_2 -> V_4 = V_6 ;
V_12 -> V_31 = V_20 [ V_15 ] ;
V_2 -> V_32 = F_1 ;
V_2 -> V_33 = F_3 ;
} else {
V_2 -> V_4 = ( void T_3 * ) V_19 [ V_15 ] ;
V_12 -> V_31 = V_19 [ V_15 ] ;
if ( V_13 == V_27 ) {
V_2 -> V_32 = F_9 ;
V_2 -> V_33 = F_12 ;
} else {
V_2 -> V_32 = F_5 ;
V_2 -> V_33 = F_7 ;
}
}
if ( V_34 [ V_15 ] )
V_18 = V_34 [ V_15 ] ;
else if ( V_34 [ 0 ] )
V_18 = V_34 [ 0 ] ;
else
V_18 = V_35 ;
V_2 -> V_36 . clock . V_37 = V_18 ;
if ( V_38 [ V_15 ] != 0xff ) {
V_2 -> V_39 = V_38 [ V_15 ] ;
} else if ( V_38 [ 0 ] != 0xff ) {
V_2 -> V_39 = V_38 [ 0 ] ;
} else {
if ( V_18 > 10000000 ) {
V_2 -> V_39 |= V_40 ;
V_18 /= 2 ;
}
if ( V_18 > 8000000 )
V_2 -> V_39 |= V_41 ;
}
if ( V_2 -> V_39 & V_40 )
V_2 -> V_36 . clock . V_37 /= 2 ;
if ( V_42 [ V_15 ] != 0xff )
V_2 -> V_43 = V_42 [ V_15 ] ;
else if ( V_42 [ 0 ] != 0xff )
V_2 -> V_43 = V_42 [ 0 ] ;
else
V_2 -> V_43 = V_44 ;
if ( V_45 [ V_15 ] != 0xff )
V_2 -> V_46 = V_45 [ V_15 ] ;
else if ( V_45 [ 0 ] != 0xff )
V_2 -> V_46 = V_45 [ 0 ] ;
else
V_2 -> V_46 = V_47 ;
F_20 ( & V_10 -> V_12 , V_12 ) ;
F_21 ( V_12 , & V_10 -> V_12 ) ;
V_17 = F_22 ( V_12 ) ;
if ( V_17 ) {
F_23 ( & V_10 -> V_12 ,
L_2 , V_17 ) ;
goto V_28;
}
F_24 ( & V_10 -> V_12 , L_3 ,
V_2 -> V_4 , V_12 -> V_21 ) ;
return 0 ;
V_28:
if ( V_20 [ V_15 ] )
F_25 ( V_6 ) ;
V_25:
if ( V_20 [ V_15 ] )
F_26 ( V_20 [ V_15 ] , V_13 ) ;
else
F_27 ( V_19 [ V_15 ] , V_13 ) ;
exit:
return V_17 ;
}
static int T_5 F_28 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_29 ( & V_10 -> V_12 ) ;
struct V_1 * V_2 = F_19 ( V_12 ) ;
int V_15 = V_10 -> V_16 ;
F_30 ( V_12 ) ;
F_20 ( & V_10 -> V_12 , NULL ) ;
if ( V_20 [ V_15 ] ) {
F_25 ( V_2 -> V_4 ) ;
F_26 ( V_20 [ V_15 ] , V_14 ) ;
} else {
if ( V_2 -> V_32 == F_9 )
F_27 ( V_19 [ V_15 ] , V_27 ) ;
else
F_27 ( V_19 [ V_15 ] , V_14 ) ;
}
F_31 ( V_12 ) ;
return 0 ;
}
static int T_6 F_32 ( void )
{
int V_15 , V_17 ;
for ( V_15 = 0 ; V_15 < F_33 ( V_48 ) ; V_15 ++ ) {
if ( ( V_19 [ V_15 ] || V_20 [ V_15 ] ) && V_21 [ V_15 ] ) {
V_48 [ V_15 ] =
F_34 ( V_22 , V_15 ) ;
if ( ! V_48 [ V_15 ] ) {
V_17 = - V_24 ;
goto V_49;
}
V_17 = F_35 ( V_48 [ V_15 ] ) ;
if ( V_17 ) {
F_36 ( V_48 [ V_15 ] ) ;
goto V_49;
}
F_37 ( L_4
L_5 ,
V_15 , V_19 [ V_15 ] , V_20 [ V_15 ] , V_21 [ V_15 ] ) ;
} else if ( V_15 == 0 || V_19 [ V_15 ] || V_20 [ V_15 ] ) {
F_38 ( L_6 ) ;
V_17 = - V_50 ;
goto V_49;
}
}
V_17 = F_39 ( & V_51 ) ;
if ( V_17 )
goto V_49;
F_40 ( L_7 , V_52 ) ;
return 0 ;
V_49:
while ( -- V_15 >= 0 ) {
if ( V_48 [ V_15 ] )
F_41 ( V_48 [ V_15 ] ) ;
}
return V_17 ;
}
static void T_7 F_42 ( void )
{
int V_15 ;
F_43 ( & V_51 ) ;
for ( V_15 = 0 ; V_15 < F_33 ( V_48 ) ; V_15 ++ ) {
if ( V_48 [ V_15 ] )
F_41 ( V_48 [ V_15 ] ) ;
}
}
