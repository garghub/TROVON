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
V_10 -> V_12 . V_18 -> V_19 ) ;
return - V_20 ;
}
F_14 ( & V_12 -> V_21 ) ;
F_15 ( & V_14 -> V_22 , F_16 ( & V_14 -> V_22 ) | F_4 ( V_7 , V_8 ) ) ;
F_13 ( V_23 L_8 ,
V_10 -> V_12 . V_18 -> V_19 , V_8 , F_2 ( V_7 ) ) ;
++ V_12 -> V_24 ;
F_17 ( & V_12 -> V_21 ) ;
return 0 ;
}
void F_18 ( struct V_9 * V_10 , int V_8 , int V_25 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 = V_12 -> V_15 ;
T_1 V_26 ;
F_14 ( & V_12 -> V_21 ) ;
V_26 = F_16 ( & V_14 -> V_26 ) & ~ F_19 ( V_8 ) ;
F_12 ( V_12 , L_9 V_16 , V_8 , V_25 ) ;
if ( V_25 == V_27 )
V_26 |= F_20 ( V_8 ) ;
else if ( V_25 == V_28 )
V_26 |= F_21 ( V_8 ) ;
else if ( V_25 == V_29 )
V_26 |= F_22 ( V_8 ) ;
F_15 ( & V_14 -> V_26 , V_26 ) ;
F_17 ( & V_12 -> V_21 ) ;
}
void F_23 ( struct V_9 * V_10 , int V_8 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 = V_12 -> V_15 ;
T_1 V_22 ;
F_24 ( V_12 , L_10 V_16 , V_8 ) ;
if ( ! ( V_12 -> V_30 & V_31 ) )
return;
F_14 ( & V_12 -> V_21 ) ;
V_22 = F_16 ( & V_14 -> V_22 ) ;
V_22 |= 0x00080000u >> V_8 ;
F_15 ( & V_14 -> V_22 , V_22 ) ;
( void ) F_16 ( & V_14 -> V_22 ) ;
F_25 ( V_12 , L_11 , V_22 ) ;
}
void F_26 ( struct V_9 * V_10 , int V_8 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 = V_12 -> V_15 ;
T_1 V_22 ;
F_24 ( V_12 , L_12 V_16 , V_8 ) ;
if ( ! ( V_12 -> V_30 & V_31 ) )
return;
V_22 = F_16 ( & V_14 -> V_22 ) ;
V_22 &= ~ ( 0x00080000u >> V_8 ) ;
F_15 ( & V_14 -> V_22 , V_22 ) ;
( void ) F_16 ( & V_14 -> V_22 ) ;
F_25 ( V_12 , L_11 , V_22 ) ;
F_17 ( & V_12 -> V_21 ) ;
}
void F_27 ( struct V_9 * V_10 , int V_8 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_13 T_2 * V_14 ;
F_28 ( ! V_12 || V_12 -> V_24 == 0 ) ;
V_14 = V_12 -> V_15 ;
F_14 ( & V_12 -> V_21 ) ;
F_12 ( V_12 , L_13 V_16 , V_8 ) ;
F_15 ( & V_14 -> V_22 , F_16 ( & V_14 -> V_22 ) & ~ F_29 ( V_8 ) ) ;
-- V_12 -> V_24 ;
F_17 ( & V_12 -> V_21 ) ;
}
int F_30 ( struct V_9 * V_10 )
{
return sizeof( struct V_32 ) +
sizeof( struct V_13 ) ;
}
void * F_31 ( struct V_9 * V_10 , void * V_33 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
struct V_32 * V_34 = V_33 ;
struct V_13 * V_35 = (struct V_13 * ) ( V_34 + 1 ) ;
V_34 -> V_36 = 0 ;
V_34 -> V_37 = 0 ;
F_32 ( V_35 , V_12 -> V_15 , sizeof( struct V_13 ) ) ;
return V_35 + 1 ;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_38 * V_39 = V_10 -> V_12 . V_18 ;
struct V_11 * V_12 ;
struct V_40 V_35 ;
int V_41 ;
V_41 = - V_42 ;
V_12 = F_34 ( sizeof( struct V_11 ) , V_43 ) ;
if ( V_12 == NULL )
goto V_44;
F_35 ( & V_12 -> V_21 ) ;
V_12 -> V_10 = V_10 ;
V_41 = - V_45 ;
if ( F_36 ( V_39 , 0 , & V_35 ) ) {
F_13 ( V_17 L_14 ,
V_39 -> V_19 ) ;
goto V_46;
}
V_41 = - V_42 ;
V_12 -> V_15 = (struct V_13 T_2 * ) F_37 ( V_35 . V_47 ,
sizeof( struct V_13 ) ) ;
if ( V_12 -> V_15 == NULL ) {
F_13 ( V_17 L_15 ,
V_39 -> V_19 ) ;
goto V_46;
}
if ( F_38 ( V_10 -> V_12 . V_18 , L_16 , NULL ) )
V_12 -> V_30 |= V_31 ;
if ( F_39 ( V_10 -> V_12 . V_18 , L_17 ) )
V_12 -> V_30 |= V_31 ;
F_25 ( V_12 , L_18 ,
F_16 ( & V_12 -> V_15 -> V_22 ) , F_16 ( & V_12 -> V_15 -> V_26 ) ) ;
F_15 ( & V_12 -> V_15 -> V_22 , 0 ) ;
F_13 ( V_48
L_19 ,
V_10 -> V_12 . V_18 -> V_19 ,
( V_12 -> V_30 & V_31 ) ? L_20 : L_21 ) ;
F_40 () ;
F_41 ( V_10 , V_12 ) ;
return 0 ;
V_46:
F_42 ( V_12 ) ;
V_44:
return V_41 ;
}
static int F_43 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_11 ( V_10 ) ;
F_44 ( V_12 -> V_24 != 0 ) ;
F_45 ( V_12 -> V_15 ) ;
F_42 ( V_12 ) ;
return 0 ;
}
int T_3 F_46 ( void )
{
return F_47 ( & V_49 ) ;
}
void F_48 ( void )
{
F_49 ( & V_49 ) ;
}
