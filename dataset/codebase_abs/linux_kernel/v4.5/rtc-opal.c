static void F_1 ( T_1 V_1 , T_2 V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = ( ( F_2 ( V_1 >> 24 ) * 100 ) +
F_2 ( ( V_1 >> 16 ) & 0xff ) ) - 1900 ;
V_4 -> V_6 = F_2 ( ( V_1 >> 8 ) & 0xff ) - 1 ;
V_4 -> V_7 = F_2 ( V_1 & 0xff ) ;
V_4 -> V_8 = F_2 ( ( V_2 >> 56 ) & 0xff ) ;
V_4 -> V_9 = F_2 ( ( V_2 >> 48 ) & 0xff ) ;
V_4 -> V_10 = F_2 ( ( V_2 >> 40 ) & 0xff ) ;
V_4 -> V_11 = - 1 ;
}
static void F_3 ( struct V_3 * V_4 , T_1 * V_1 , T_2 * V_2 )
{
* V_1 |= ( ( T_1 ) F_4 ( ( V_4 -> V_5 + 1900 ) / 100 ) ) << 24 ;
* V_1 |= ( ( T_1 ) F_4 ( ( V_4 -> V_5 + 1900 ) % 100 ) ) << 16 ;
* V_1 |= ( ( T_1 ) F_4 ( ( V_4 -> V_6 + 1 ) ) ) << 8 ;
* V_1 |= ( ( T_1 ) F_4 ( V_4 -> V_7 ) ) ;
* V_2 |= ( ( T_2 ) F_4 ( V_4 -> V_8 ) ) << 56 ;
* V_2 |= ( ( T_2 ) F_4 ( V_4 -> V_9 ) ) << 48 ;
* V_2 |= ( ( T_2 ) F_4 ( V_4 -> V_10 ) ) << 40 ;
}
static int F_5 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
long V_14 = V_15 ;
T_1 V_1 ;
T_2 V_2 ;
T_3 V_16 ;
T_4 V_17 ;
while ( V_14 == V_15 || V_14 == V_18 ) {
V_14 = F_6 ( & V_16 , & V_17 ) ;
if ( V_14 == V_18 )
F_7 ( NULL ) ;
else
F_8 ( 10 ) ;
}
if ( V_14 != V_19 )
return - V_20 ;
V_1 = F_9 ( V_16 ) ;
V_2 = F_10 ( V_17 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
long V_14 = V_15 ;
T_1 V_1 = 0 ;
T_2 V_2 = 0 ;
F_3 ( V_4 , & V_1 , & V_2 ) ;
while ( V_14 == V_15 || V_14 == V_18 ) {
V_14 = F_12 ( V_1 , V_2 ) ;
if ( V_14 == V_18 )
F_7 ( NULL ) ;
else
F_8 ( 10 ) ;
}
return V_14 == V_19 ? 0 : - V_20 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
T_3 V_16 , V_23 ;
struct V_24 V_25 ;
int V_14 , V_26 ;
T_2 V_2 ;
T_1 V_1 ;
V_26 = F_14 () ;
if ( V_26 < 0 ) {
if ( V_26 != - V_27 )
F_15 ( L_1 ) ;
return V_26 ;
}
V_14 = F_16 ( V_26 , & V_16 , & V_23 ) ;
if ( V_14 != V_28 ) {
V_14 = - V_20 ;
goto exit;
}
V_14 = F_17 ( V_26 , & V_25 ) ;
if ( V_14 ) {
V_14 = - V_20 ;
goto exit;
}
V_14 = F_10 ( V_25 . V_29 [ 1 ] ) ;
if ( V_14 != V_19 ) {
V_14 = - V_20 ;
goto exit;
}
V_1 = F_9 ( V_16 ) ;
V_2 = ( ( T_2 ) F_9 ( V_23 ) << 32 ) ;
F_1 ( V_1 , V_2 , & V_22 -> time ) ;
exit:
F_18 ( V_26 ) ;
return V_14 ;
}
static int F_19 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
T_2 V_2 = 0 ;
struct V_24 V_25 ;
T_1 V_1 = 0 ;
int V_26 , V_14 ;
F_3 ( & V_22 -> time , & V_1 , & V_2 ) ;
V_26 = F_14 () ;
if ( V_26 < 0 ) {
if ( V_26 != - V_27 )
F_15 ( L_1 ) ;
return V_26 ;
}
V_14 = F_20 ( V_26 , V_1 ,
( T_1 ) ( ( V_2 >> 32 ) & 0xffff0000 ) ) ;
if ( V_14 != V_28 ) {
V_14 = - V_20 ;
goto exit;
}
V_14 = F_17 ( V_26 , & V_25 ) ;
if ( V_14 ) {
V_14 = - V_20 ;
goto exit;
}
V_14 = F_10 ( V_25 . V_29 [ 1 ] ) ;
if ( V_14 != V_19 )
V_14 = - V_20 ;
exit:
F_18 ( V_26 ) ;
return V_14 ;
}
static int F_21 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
if ( V_31 -> V_13 . V_34 &&
( F_22 ( V_31 -> V_13 . V_34 , L_2 ) ||
F_22 ( V_31 -> V_13 . V_34 , L_3 ) ) ) {
F_23 ( & V_31 -> V_13 , true ) ;
V_35 . V_36 = F_13 ;
V_35 . V_37 = F_19 ;
}
V_33 = F_24 ( & V_31 -> V_13 , V_38 , & V_35 ,
V_39 ) ;
if ( F_25 ( V_33 ) )
return F_26 ( V_33 ) ;
V_33 -> V_40 = 1 ;
return 0 ;
}
static int T_5 F_27 ( void )
{
if ( ! F_28 ( V_41 ) )
return - V_42 ;
return F_29 ( & V_43 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_43 ) ;
}
