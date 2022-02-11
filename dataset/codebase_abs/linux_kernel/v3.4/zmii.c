static inline int F_1 ( int V_1 )
{
return V_1 == V_2 ||
V_1 == V_3 ||
V_1 == V_4 ||
V_1 == V_5 ;
}
static inline const char * F_2 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
default:
F_3 () ;
}
}
static inline T_1 F_4 ( int V_1 , int V_6 )
{
switch ( V_1 ) {
case V_2 :
return F_5 ( V_6 ) ;
case V_3 :
return F_6 ( V_6 ) ;
case V_4 :
return F_7 ( V_6 ) ;
default:
return 0 ;
}
}
int T_2 F_8 ( struct V_7 * V_8 , int V_6 , int * V_1 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_10 ) ;
struct V_11 T_3 * V_12 = V_10 -> V_13 ;
F_10 ( V_10 , L_4 V_14 , V_6 , * V_1 ) ;
if ( ! F_1 ( * V_1 ) ) {
V_10 -> V_15 ++ ;
return 0 ;
}
F_11 ( & V_10 -> V_16 ) ;
if ( V_10 -> V_1 == V_5 ) {
if ( * V_1 == V_5 ) {
T_1 V_17 = V_10 -> V_18 ;
F_10 ( V_10 , L_5 V_14 , V_17 ) ;
if ( V_17 & ( F_5 ( 0 ) | F_5 ( 1 ) ) )
V_10 -> V_1 = V_2 ;
else if ( V_17 & ( F_6 ( 0 ) | F_6 ( 1 ) ) )
V_10 -> V_1 = V_3 ;
else
V_10 -> V_1 = V_4 ;
} else
V_10 -> V_1 = * V_1 ;
F_12 ( V_19 L_6 ,
V_8 -> V_10 . V_20 -> V_21 ,
F_2 ( V_10 -> V_1 ) ) ;
} else {
if ( * V_1 != V_5 && * V_1 != V_10 -> V_1 ) {
F_12 ( V_22
L_7 ,
V_8 -> V_10 . V_20 -> V_21 , * V_1 , V_6 ) ;
F_13 ( & V_10 -> V_16 ) ;
return - V_23 ;
}
}
* V_1 = V_10 -> V_1 ;
F_14 ( & V_12 -> V_24 , F_15 ( & V_12 -> V_24 ) | F_4 ( V_10 -> V_1 , V_6 ) ) ;
++ V_10 -> V_15 ;
F_13 ( & V_10 -> V_16 ) ;
return 0 ;
}
void F_16 ( struct V_7 * V_8 , int V_6 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_10 ) ;
T_1 V_24 ;
F_17 ( V_10 , L_8 V_14 , V_6 ) ;
F_11 ( & V_10 -> V_16 ) ;
V_24 = F_15 ( & V_10 -> V_13 -> V_24 ) & ~ V_25 ;
F_14 ( & V_10 -> V_13 -> V_24 , V_24 | F_18 ( V_6 ) ) ;
}
void F_19 ( struct V_7 * V_8 , int V_6 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_10 ) ;
F_17 ( V_10 , L_9 V_14 , V_6 ) ;
F_13 ( & V_10 -> V_16 ) ;
}
void F_20 ( struct V_7 * V_8 , int V_6 , int V_26 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_10 ) ;
T_1 V_27 ;
F_11 ( & V_10 -> V_16 ) ;
V_27 = F_15 ( & V_10 -> V_13 -> V_27 ) ;
F_10 ( V_10 , L_10 V_14 , V_6 , V_26 ) ;
if ( V_26 == V_28 )
V_27 |= F_21 ( V_6 ) ;
else
V_27 &= ~ F_21 ( V_6 ) ;
F_14 ( & V_10 -> V_13 -> V_27 , V_27 ) ;
F_13 ( & V_10 -> V_16 ) ;
}
void F_22 ( struct V_7 * V_8 , int V_6 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_10 ) ;
F_23 ( ! V_10 || V_10 -> V_15 == 0 ) ;
F_11 ( & V_10 -> V_16 ) ;
F_10 ( V_10 , L_11 V_14 , V_6 ) ;
F_14 ( & V_10 -> V_13 -> V_24 ,
F_15 ( & V_10 -> V_13 -> V_24 ) & ~ F_4 ( V_10 -> V_1 , V_6 ) ) ;
-- V_10 -> V_15 ;
F_13 ( & V_10 -> V_16 ) ;
}
int F_24 ( struct V_7 * V_8 )
{
return sizeof( struct V_29 ) +
sizeof( struct V_11 ) ;
}
void * F_25 ( struct V_7 * V_8 , void * V_30 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_10 ) ;
struct V_29 * V_31 = V_30 ;
struct V_11 * V_32 = (struct V_11 * ) ( V_31 + 1 ) ;
V_31 -> V_33 = 0 ;
V_31 -> V_34 = 0 ;
F_26 ( V_32 , V_10 -> V_13 , sizeof( struct V_11 ) ) ;
return V_32 + 1 ;
}
static int T_2 F_27 ( struct V_7 * V_8 )
{
struct V_35 * V_36 = V_8 -> V_10 . V_20 ;
struct V_9 * V_10 ;
struct V_37 V_32 ;
int V_38 ;
V_38 = - V_39 ;
V_10 = F_28 ( sizeof( struct V_9 ) , V_40 ) ;
if ( V_10 == NULL )
goto V_41;
F_29 ( & V_10 -> V_16 ) ;
V_10 -> V_8 = V_8 ;
V_10 -> V_1 = V_5 ;
V_38 = - V_42 ;
if ( F_30 ( V_36 , 0 , & V_32 ) ) {
F_12 ( V_22 L_12 ,
V_36 -> V_21 ) ;
goto V_43;
}
V_38 = - V_39 ;
V_10 -> V_13 = (struct V_11 T_3 * ) F_31 ( V_32 . V_44 ,
sizeof( struct V_11 ) ) ;
if ( V_10 -> V_13 == NULL ) {
F_12 ( V_22 L_13 ,
V_36 -> V_21 ) ;
goto V_43;
}
V_10 -> V_18 = F_15 ( & V_10 -> V_13 -> V_24 ) ;
F_14 ( & V_10 -> V_13 -> V_24 , 0 ) ;
F_12 ( V_45
L_14 , V_8 -> V_10 . V_20 -> V_21 ) ;
F_32 () ;
F_33 ( & V_8 -> V_10 , V_10 ) ;
return 0 ;
V_43:
F_34 ( V_10 ) ;
V_41:
return V_38 ;
}
static int T_4 F_35 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( & V_8 -> V_10 ) ;
F_33 ( & V_8 -> V_10 , NULL ) ;
F_36 ( V_10 -> V_15 != 0 ) ;
F_37 ( V_10 -> V_13 ) ;
F_34 ( V_10 ) ;
return 0 ;
}
int T_5 F_38 ( void )
{
return F_39 ( & V_46 ) ;
}
void F_40 ( void )
{
F_41 ( & V_46 ) ;
}
