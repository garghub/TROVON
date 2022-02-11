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
static int T_2 F_11 ( struct V_7 * V_8 , unsigned int V_9 )
{
if ( V_10 [ V_9 ] || V_11 [ V_9 ] ) {
if ( V_12 [ V_9 ] )
return 1 ;
} else if ( V_9 )
return 0 ;
F_12 ( V_8 , L_1 ) ;
return 0 ;
}
static int T_2 F_13 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
void T_3 * V_6 = NULL ;
int V_15 = V_16 ;
int V_17 ;
if ( V_11 [ V_9 ] ) {
if ( ! F_14 ( V_11 [ V_9 ] , V_15 , V_18 ) ) {
V_17 = - V_19 ;
goto exit;
}
V_6 = F_15 ( V_11 [ V_9 ] , V_15 ) ;
if ( ! V_6 ) {
V_17 = - V_20 ;
goto V_21;
}
} else {
if ( V_22 [ V_9 ] > 0 ||
( V_22 [ V_9 ] == - 1 && V_22 [ 0 ] > 0 ) )
V_15 = V_23 ;
if ( ! F_16 ( V_10 [ V_9 ] , V_15 , V_18 ) ) {
V_17 = - V_19 ;
goto exit;
}
}
V_14 = F_17 ( 0 ) ;
if ( ! V_14 ) {
V_17 = - V_20 ;
goto V_24;
}
V_2 = F_18 ( V_14 ) ;
V_14 -> V_12 = V_12 [ V_9 ] ;
V_2 -> V_25 = V_26 ;
if ( V_11 [ V_9 ] ) {
V_2 -> V_4 = V_6 ;
V_14 -> V_27 = V_11 [ V_9 ] ;
V_2 -> V_28 = F_1 ;
V_2 -> V_29 = F_3 ;
} else {
V_2 -> V_4 = ( void T_3 * ) V_10 [ V_9 ] ;
V_14 -> V_27 = V_10 [ V_9 ] ;
if ( V_15 == V_23 ) {
V_2 -> V_28 = F_9 ;
V_2 -> V_29 = F_10 ;
} else {
V_2 -> V_28 = F_5 ;
V_2 -> V_29 = F_7 ;
}
}
if ( V_30 [ V_9 ] )
V_2 -> V_31 . clock . V_32 = V_30 [ V_9 ] / 2 ;
else if ( V_30 [ 0 ] )
V_2 -> V_31 . clock . V_32 = V_30 [ 0 ] / 2 ;
else
V_2 -> V_31 . clock . V_32 = V_33 / 2 ;
if ( V_34 [ V_9 ] != - 1 )
V_2 -> V_34 = V_34 [ V_9 ] & 0xff ;
else if ( V_34 [ 0 ] != - 1 )
V_2 -> V_34 = V_34 [ 0 ] & 0xff ;
else
V_2 -> V_34 = V_35 ;
if ( V_36 [ V_9 ] != - 1 )
V_2 -> V_36 = V_36 [ V_9 ] & 0xff ;
else if ( V_36 [ 0 ] != - 1 )
V_2 -> V_36 = V_36 [ 0 ] & 0xff ;
else
V_2 -> V_36 = V_37 ;
F_19 ( V_8 , V_14 ) ;
F_20 ( V_14 , V_8 ) ;
V_17 = F_21 ( V_14 ) ;
if ( V_17 ) {
F_12 ( V_8 , L_2 ,
V_18 , V_17 ) ;
goto V_24;
}
F_22 ( V_8 , L_3 ,
V_18 , V_2 -> V_4 , V_14 -> V_12 ) ;
return 0 ;
V_24:
if ( V_11 [ V_9 ] )
F_23 ( V_6 ) ;
V_21:
if ( V_11 [ V_9 ] )
F_24 ( V_11 [ V_9 ] , V_15 ) ;
else
F_25 ( V_10 [ V_9 ] , V_15 ) ;
exit:
return V_17 ;
}
static int T_4 F_26 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_13 * V_14 = F_27 ( V_8 ) ;
struct V_1 * V_2 = F_18 ( V_14 ) ;
F_28 ( V_14 ) ;
F_19 ( V_8 , NULL ) ;
if ( V_11 [ V_9 ] ) {
F_23 ( V_2 -> V_4 ) ;
F_24 ( V_11 [ V_9 ] , V_16 ) ;
} else {
if ( V_2 -> V_28 == F_9 )
F_25 ( V_10 [ V_9 ] , V_23 ) ;
else
F_25 ( V_10 [ V_9 ] , V_16 ) ;
}
F_29 ( V_14 ) ;
return 0 ;
}
static int T_5 F_30 ( void )
{
int V_17 = F_31 ( & V_38 , V_39 ) ;
if ( ! V_17 )
F_32 ( V_40
L_4 ,
V_18 , V_39 ) ;
return V_17 ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_38 ) ;
}
