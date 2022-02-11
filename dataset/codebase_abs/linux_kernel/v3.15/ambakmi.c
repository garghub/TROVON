static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned int V_5 = F_2 ( V_6 ) ;
int V_7 = V_8 ;
while ( V_5 & V_9 ) {
F_3 ( V_4 -> V_10 , F_2 ( V_11 ) , 0 ) ;
V_5 = F_2 ( V_6 ) ;
V_7 = V_12 ;
}
return V_7 ;
}
static int F_4 ( struct V_13 * V_10 , unsigned char V_14 )
{
struct V_3 * V_4 = V_10 -> V_15 ;
unsigned int V_16 = 10000 ;
while ( ( F_2 ( V_17 ) & V_18 ) == 0 && -- V_16 )
F_5 ( 10 ) ;
if ( V_16 )
F_6 ( V_14 , V_11 ) ;
return V_16 ? 0 : V_19 ;
}
static int F_7 ( struct V_13 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_15 ;
unsigned int V_20 ;
int V_21 ;
V_21 = F_8 ( V_4 -> V_22 ) ;
if ( V_21 )
goto V_23;
V_20 = F_9 ( V_4 -> V_22 ) / 8000000 - 1 ;
F_6 ( V_20 , V_24 ) ;
F_6 ( V_25 , V_26 ) ;
V_21 = F_10 ( V_4 -> V_1 , F_1 , V_27 , L_1 ,
V_4 ) ;
if ( V_21 ) {
F_11 ( V_28 L_2 , V_4 -> V_1 ) ;
F_6 ( 0 , V_26 ) ;
goto V_29;
}
F_6 ( V_25 | V_30 , V_26 ) ;
return 0 ;
V_29:
F_12 ( V_4 -> V_22 ) ;
V_23:
return V_21 ;
}
static void F_13 ( struct V_13 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_15 ;
F_6 ( 0 , V_26 ) ;
F_14 ( V_4 -> V_1 , V_4 ) ;
F_12 ( V_4 -> V_22 ) ;
}
static int F_15 ( struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_3 * V_4 ;
struct V_13 * V_10 ;
int V_21 ;
V_21 = F_16 ( V_32 , NULL ) ;
if ( V_21 )
return V_21 ;
V_4 = F_17 ( sizeof( struct V_3 ) , V_35 ) ;
V_10 = F_17 ( sizeof( struct V_13 ) , V_35 ) ;
if ( ! V_4 || ! V_10 ) {
V_21 = - V_36 ;
goto V_23;
}
V_10 -> V_34 . type = V_37 ;
V_10 -> V_38 = F_4 ;
V_10 -> V_39 = F_7 ;
V_10 -> V_40 = F_13 ;
F_18 ( V_10 -> V_41 , F_19 ( & V_32 -> V_32 ) , sizeof( V_10 -> V_41 ) ) ;
F_18 ( V_10 -> V_42 , F_19 ( & V_32 -> V_32 ) , sizeof( V_10 -> V_42 ) ) ;
V_10 -> V_15 = V_4 ;
V_10 -> V_32 . V_43 = & V_32 -> V_32 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_44 = F_20 ( V_32 -> V_45 . V_46 , F_21 ( & V_32 -> V_45 ) ) ;
if ( ! V_4 -> V_44 ) {
V_21 = - V_36 ;
goto V_23;
}
V_4 -> V_22 = F_22 ( & V_32 -> V_32 , L_3 ) ;
if ( F_23 ( V_4 -> V_22 ) ) {
V_21 = F_24 ( V_4 -> V_22 ) ;
goto V_47;
}
V_4 -> V_1 = V_32 -> V_1 [ 0 ] ;
F_25 ( V_32 , V_4 ) ;
F_26 ( V_4 -> V_10 ) ;
return 0 ;
V_47:
F_27 ( V_4 -> V_44 ) ;
V_23:
F_28 ( V_4 ) ;
F_28 ( V_10 ) ;
F_29 ( V_32 ) ;
return V_21 ;
}
static int F_30 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_31 ( V_32 ) ;
F_32 ( V_4 -> V_10 ) ;
F_33 ( V_4 -> V_22 ) ;
F_27 ( V_4 -> V_44 ) ;
F_28 ( V_4 ) ;
F_29 ( V_32 ) ;
return 0 ;
}
static int F_34 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_31 ( V_32 ) ;
F_35 ( V_4 -> V_10 ) ;
return 0 ;
}
