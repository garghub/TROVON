static inline int F_1 ( int V_1 )
{
return V_1 == V_2 ||
V_1 == V_3 ||
V_1 == V_4 ||
V_1 == V_5 ||
V_1 == V_6 ;
}
static inline const char * F_2 ( int V_7 )
{
switch ( V_7 ) {
case V_4 :
return L_1 ;
case V_5 :
return L_2 ;
case V_2 :
return L_3 ;
case V_3 :
return L_4 ;
case V_6 :
return L_5 ;
default:
F_3 () ;
}
}
static inline T_1 F_4 ( int V_7 , int V_8 )
{
switch ( V_7 ) {
case V_4 :
return F_5 ( V_8 ) ;
case V_5 :
return F_6 ( V_8 ) ;
case V_2 :
return F_7 ( V_8 ) ;
case V_3 :
return F_8 ( V_8 ) ;
case V_6 :
return F_9 ( V_8 ) ;
default:
F_3 () ;
}
}
int F_10 ( struct V_9 * V_10 , int V_8 , int V_7 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 = V_12 -> V_15 ;
F_12 ( V_12 , L_6 V_16 , V_8 ) ;
if ( V_8 < 0 || ! F_1 ( V_7 ) ) {
F_13 ( V_17 L_7 ,
V_10 -> V_12 . V_18 ) ;
return - V_19 ;
}
F_14 ( & V_12 -> V_20 ) ;
F_15 ( & V_14 -> V_21 , F_16 ( & V_14 -> V_21 ) | F_4 ( V_7 , V_8 ) ) ;
F_13 ( V_22 L_8 ,
V_10 -> V_12 . V_18 , V_8 , F_2 ( V_7 ) ) ;
++ V_12 -> V_23 ;
F_17 ( & V_12 -> V_20 ) ;
return 0 ;
}
void F_18 ( struct V_9 * V_10 , int V_8 , int V_24 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 = V_12 -> V_15 ;
T_1 V_25 ;
F_14 ( & V_12 -> V_20 ) ;
V_25 = F_16 ( & V_14 -> V_25 ) & ~ F_19 ( V_8 ) ;
F_12 ( V_12 , L_9 V_16 , V_8 , V_24 ) ;
if ( V_24 == V_26 )
V_25 |= F_20 ( V_8 ) ;
else if ( V_24 == V_27 )
V_25 |= F_21 ( V_8 ) ;
else if ( V_24 == V_28 )
V_25 |= F_22 ( V_8 ) ;
F_15 ( & V_14 -> V_25 , V_25 ) ;
F_17 ( & V_12 -> V_20 ) ;
}
void F_23 ( struct V_9 * V_10 , int V_8 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 = V_12 -> V_15 ;
T_1 V_21 ;
F_24 ( V_12 , L_10 V_16 , V_8 ) ;
if ( ! ( V_12 -> V_29 & V_30 ) )
return;
F_14 ( & V_12 -> V_20 ) ;
V_21 = F_16 ( & V_14 -> V_21 ) ;
V_21 |= 0x00080000u >> V_8 ;
F_15 ( & V_14 -> V_21 , V_21 ) ;
( void ) F_16 ( & V_14 -> V_21 ) ;
F_25 ( V_12 , L_11 , V_21 ) ;
}
void F_26 ( struct V_9 * V_10 , int V_8 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 = V_12 -> V_15 ;
T_1 V_21 ;
F_24 ( V_12 , L_12 V_16 , V_8 ) ;
if ( ! ( V_12 -> V_29 & V_30 ) )
return;
V_21 = F_16 ( & V_14 -> V_21 ) ;
V_21 &= ~ ( 0x00080000u >> V_8 ) ;
F_15 ( & V_14 -> V_21 , V_21 ) ;
( void ) F_16 ( & V_14 -> V_21 ) ;
F_25 ( V_12 , L_11 , V_21 ) ;
F_17 ( & V_12 -> V_20 ) ;
}
void F_27 ( struct V_9 * V_10 , int V_8 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 ;
F_28 ( ! V_12 || V_12 -> V_23 == 0 ) ;
V_14 = V_12 -> V_15 ;
F_14 ( & V_12 -> V_20 ) ;
F_12 ( V_12 , L_13 V_16 , V_8 ) ;
F_15 ( & V_14 -> V_21 , F_16 ( & V_14 -> V_21 ) & ~ F_29 ( V_8 ) ) ;
-- V_12 -> V_23 ;
F_17 ( & V_12 -> V_20 ) ;
}
int F_30 ( struct V_9 * V_10 )
{
return sizeof( struct V_31 ) +
sizeof( struct V_13 ) ;
}
void * F_31 ( struct V_9 * V_10 , void * V_32 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_31 * V_33 = V_32 ;
struct V_13 * V_34 = (struct V_13 * ) ( V_33 + 1 ) ;
V_33 -> V_35 = 0 ;
V_33 -> V_36 = 0 ;
F_32 ( V_34 , V_12 -> V_15 , sizeof( struct V_13 ) ) ;
return V_34 + 1 ;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_37 * V_38 = V_10 -> V_12 . V_18 ;
struct V_11 * V_12 ;
struct V_39 V_34 ;
int V_40 ;
V_40 = - V_41 ;
V_12 = F_34 ( sizeof( struct V_11 ) , V_42 ) ;
if ( V_12 == NULL )
goto V_43;
F_35 ( & V_12 -> V_20 ) ;
V_12 -> V_10 = V_10 ;
V_40 = - V_44 ;
if ( F_36 ( V_38 , 0 , & V_34 ) ) {
F_13 ( V_17 L_14 , V_38 ) ;
goto V_45;
}
V_40 = - V_41 ;
V_12 -> V_15 = (struct V_13 T_2 * ) F_37 ( V_34 . V_46 ,
sizeof( struct V_13 ) ) ;
if ( V_12 -> V_15 == NULL ) {
F_13 ( V_17 L_15 , V_38 ) ;
goto V_45;
}
if ( F_38 ( V_10 -> V_12 . V_18 , L_16 , NULL ) )
V_12 -> V_29 |= V_30 ;
if ( F_39 ( V_10 -> V_12 . V_18 , L_17 ) )
V_12 -> V_29 |= V_30 ;
F_25 ( V_12 , L_18 ,
F_16 ( & V_12 -> V_15 -> V_21 ) , F_16 ( & V_12 -> V_15 -> V_25 ) ) ;
F_15 ( & V_12 -> V_15 -> V_21 , 0 ) ;
F_13 ( V_47
L_19 ,
V_10 -> V_12 . V_18 ,
( V_12 -> V_29 & V_30 ) ? L_20 : L_21 ) ;
F_40 () ;
F_41 ( V_10 , V_12 ) ;
return 0 ;
V_45:
F_42 ( V_12 ) ;
V_43:
return V_40 ;
}
static int F_43 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
F_44 ( V_12 -> V_23 != 0 ) ;
F_45 ( V_12 -> V_15 ) ;
F_42 ( V_12 ) ;
return 0 ;
}
int T_3 F_46 ( void )
{
return F_47 ( & V_48 ) ;
}
void F_48 ( void )
{
F_49 ( & V_48 ) ;
}
