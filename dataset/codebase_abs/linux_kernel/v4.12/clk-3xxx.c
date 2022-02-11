static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 ,
T_1 * V_6 )
{
memcpy ( V_4 , & V_2 -> V_7 , sizeof( * V_4 ) ) ;
V_4 -> V_8 &= ~ 0xf0 ;
V_4 -> V_8 |= 0x20 ;
* V_5 = V_9 ;
* V_6 = V_10 ;
}
static void
F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 , T_1 * V_6 )
{
memcpy ( V_4 , & V_2 -> V_7 , sizeof( * V_4 ) ) ;
V_4 -> V_8 &= ~ 0xf0 ;
V_4 -> V_8 |= 0x20 ;
* V_5 = V_11 ;
* V_6 = V_10 ;
}
static void
F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 ,
T_1 * V_6 )
{
memcpy ( V_4 , & V_2 -> V_7 , sizeof( * V_4 ) ) ;
V_4 -> V_8 &= ~ 0xf0 ;
V_4 -> V_8 |= 0x20 ;
* V_5 = V_12 ;
* V_6 = V_10 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 ,
T_1 * V_6 )
{
memcpy ( V_4 , & V_2 -> V_7 , sizeof( * V_4 ) ) ;
* V_5 = V_2 -> V_13 + V_14 ;
* V_6 = V_15 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_16 ,
T_1 * V_17 )
{
memcpy ( V_16 , & V_2 -> V_7 , sizeof( * V_16 ) ) ;
if ( V_2 -> V_13 & V_18 )
* V_17 = V_2 -> V_13 + V_19 ;
else
* V_17 = V_2 -> V_13 - V_19 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 ,
T_1 * V_6 )
{
memcpy ( V_4 , & V_2 -> V_7 , sizeof( * V_4 ) ) ;
V_4 -> V_8 &= ~ 0xf0 ;
V_4 -> V_8 |= 0x20 ;
* V_5 = V_20 ;
* V_6 = V_10 ;
}
void T_2 F_7 ( void )
{
struct V_2 * V_21 ;
struct V_2 * V_22 ;
V_21 = F_8 ( NULL , L_1 ) ;
F_9 ( V_21 , V_23 * 8 ) ;
F_10 ( V_21 ) ;
V_22 = F_8 ( NULL , L_2 ) ;
F_10 ( V_22 ) ;
F_9 ( V_22 , V_23 ) ;
F_11 ( V_22 ) ;
F_11 ( V_21 ) ;
}
static int T_2 F_12 ( int V_24 )
{
if ( V_24 == V_25 || V_24 == V_26 ||
V_24 == V_27 ||
V_24 == V_28 )
F_13 ( V_29 ) ;
if ( V_24 == V_25 )
F_13 ( V_30 ) ;
if ( V_24 == V_26 || V_24 == V_25 ||
V_24 == V_28 )
F_13 ( V_31 ) ;
if ( V_24 == V_27 )
F_13 ( V_32 ) ;
if ( V_24 == V_28 ||
V_24 == V_26 )
F_13 ( V_33 ) ;
if ( V_24 == V_27 ||
V_24 == V_28 ||
V_24 == V_26 )
F_13 ( V_34 ) ;
if ( V_24 == V_26 )
F_13 ( V_35 ) ;
F_14 () ;
F_15 ( V_36 ,
F_16 ( V_36 ) ) ;
F_17 ( L_3 ,
( F_18 ( F_19 ( NULL , L_4 ) ) / 1000000 ) ,
( F_18 ( F_19 ( NULL , L_4 ) ) / 100000 ) % 10 ,
( F_18 ( F_19 ( NULL , L_5 ) ) / 1000000 ) ,
( F_18 ( F_19 ( NULL , L_6 ) ) / 1000000 ) ) ;
if ( V_24 != V_27 )
F_7 () ;
return 0 ;
}
int T_2 F_20 ( void )
{
return F_12 ( V_28 ) ;
}
int T_2 F_21 ( void )
{
return F_12 ( V_26 ) ;
}
int T_2 F_22 ( void )
{
return F_12 ( V_25 ) ;
}
