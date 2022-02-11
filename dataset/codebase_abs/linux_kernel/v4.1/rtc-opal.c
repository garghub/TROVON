static void F_1 ( T_1 V_1 , T_2 V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = ( ( F_2 ( V_1 >> 24 ) * 100 ) +
F_2 ( ( V_1 >> 16 ) & 0xff ) ) - 1900 ;
V_4 -> V_6 = F_2 ( ( V_1 >> 8 ) & 0xff ) - 1 ;
V_4 -> V_7 = F_2 ( V_1 & 0xff ) ;
V_4 -> V_8 = F_2 ( ( V_2 >> 56 ) & 0xff ) ;
V_4 -> V_9 = F_2 ( ( V_2 >> 48 ) & 0xff ) ;
V_4 -> V_10 = F_2 ( ( V_2 >> 40 ) & 0xff ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_3 * V_4 , T_1 * V_1 , T_2 * V_2 )
{
* V_1 |= ( ( T_1 ) F_5 ( ( V_4 -> V_5 + 1900 ) / 100 ) ) << 24 ;
* V_1 |= ( ( T_1 ) F_5 ( ( V_4 -> V_5 + 1900 ) % 100 ) ) << 16 ;
* V_1 |= ( ( T_1 ) F_5 ( ( V_4 -> V_6 + 1 ) ) ) << 8 ;
* V_1 |= ( ( T_1 ) F_5 ( V_4 -> V_7 ) ) ;
* V_2 |= ( ( T_2 ) F_5 ( V_4 -> V_8 ) ) << 56 ;
* V_2 |= ( ( T_2 ) F_5 ( V_4 -> V_9 ) ) << 48 ;
* V_2 |= ( ( T_2 ) F_5 ( V_4 -> V_10 ) ) << 40 ;
}
static int F_6 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
long V_13 = V_14 ;
T_1 V_1 ;
T_2 V_2 ;
T_3 V_15 ;
T_4 V_16 ;
while ( V_13 == V_14 || V_13 == V_17 ) {
V_13 = F_7 ( & V_15 , & V_16 ) ;
if ( V_13 == V_17 )
F_8 ( NULL ) ;
else
F_9 ( 10 ) ;
}
if ( V_13 != V_18 )
return - V_19 ;
V_1 = F_10 ( V_15 ) ;
V_2 = F_11 ( V_16 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
long V_13 = V_14 ;
T_1 V_1 = 0 ;
T_2 V_2 = 0 ;
F_4 ( V_4 , & V_1 , & V_2 ) ;
while ( V_13 == V_14 || V_13 == V_17 ) {
V_13 = F_13 ( V_1 , V_2 ) ;
if ( V_13 == V_17 )
F_8 ( NULL ) ;
else
F_9 ( 10 ) ;
}
return V_13 == V_18 ? 0 : - V_19 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
T_3 V_15 , V_22 ;
struct V_23 V_24 ;
int V_13 , V_25 ;
T_2 V_2 ;
T_1 V_1 ;
V_25 = F_15 () ;
if ( V_25 < 0 ) {
if ( V_25 != - V_26 )
F_16 ( L_1 ) ;
return V_25 ;
}
V_13 = F_17 ( V_25 , & V_15 , & V_22 ) ;
if ( V_13 != V_27 ) {
V_13 = - V_19 ;
goto exit;
}
V_13 = F_18 ( V_25 , & V_24 ) ;
if ( V_13 ) {
V_13 = - V_19 ;
goto exit;
}
V_13 = F_11 ( V_24 . V_28 [ 1 ] ) ;
if ( V_13 != V_18 ) {
V_13 = - V_19 ;
goto exit;
}
V_1 = F_10 ( V_15 ) ;
V_2 = ( ( T_2 ) F_10 ( V_22 ) << 32 ) ;
F_1 ( V_1 , V_2 , & V_21 -> time ) ;
exit:
F_19 ( V_25 ) ;
return V_13 ;
}
static int F_20 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
T_2 V_2 = 0 , V_25 ;
struct V_23 V_24 ;
T_1 V_1 = 0 ;
int V_13 ;
F_4 ( & V_21 -> time , & V_1 , & V_2 ) ;
V_25 = F_15 () ;
if ( V_25 < 0 ) {
if ( V_25 != - V_26 )
F_16 ( L_1 ) ;
return V_25 ;
}
V_13 = F_21 ( V_25 , V_1 ,
( T_1 ) ( ( V_2 >> 32 ) & 0xffff0000 ) ) ;
if ( V_13 != V_27 ) {
V_13 = - V_19 ;
goto exit;
}
V_13 = F_18 ( V_25 , & V_24 ) ;
if ( V_13 ) {
V_13 = - V_19 ;
goto exit;
}
V_13 = F_11 ( V_24 . V_28 [ 1 ] ) ;
if ( V_13 != V_18 )
V_13 = - V_19 ;
exit:
F_19 ( V_25 ) ;
return V_13 ;
}
static int F_22 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
if ( V_30 -> V_12 . V_33 && F_23 ( V_30 -> V_12 . V_33 , L_2 ,
NULL ) )
F_24 ( & V_30 -> V_12 , true ) ;
V_32 = F_25 ( & V_30 -> V_12 , V_34 , & V_35 ,
V_36 ) ;
if ( F_26 ( V_32 ) )
return F_27 ( V_32 ) ;
V_32 -> V_37 = 1 ;
return 0 ;
}
static int T_5 F_28 ( void )
{
if ( ! F_29 ( V_38 ) )
return - V_39 ;
return F_30 ( & V_40 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_40 ) ;
}
