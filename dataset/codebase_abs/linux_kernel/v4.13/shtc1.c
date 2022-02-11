static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 , int V_6 )
{
int V_7 = F_2 ( V_2 , V_4 -> V_8 , V_9 ) ;
if ( V_7 != V_9 ) {
F_3 ( & V_2 -> V_10 , L_1 , V_7 ) ;
return V_7 < 0 ? V_7 : - V_11 ;
}
if ( ! V_4 -> V_12 . V_13 )
F_4 ( V_4 -> V_14 ,
V_4 -> V_14 + 1000 ) ;
V_7 = F_5 ( V_2 , V_5 , V_6 ) ;
if ( V_7 != V_6 ) {
F_3 ( & V_2 -> V_10 , L_2 , V_7 ) ;
return V_7 < 0 ? V_7 : - V_11 ;
}
return 0 ;
}
static struct V_3 * F_6 ( struct V_15 * V_10 )
{
struct V_3 * V_4 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned char V_5 [ V_16 ] ;
int V_17 ;
int V_7 = 0 ;
F_8 ( & V_4 -> V_18 ) ;
if ( F_9 ( V_19 , V_4 -> V_20 + V_21 / 10 ) || ! V_4 -> V_22 ) {
V_7 = F_1 ( V_2 , V_4 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 )
goto V_23;
V_17 = F_10 ( ( V_24 * ) V_5 ) ;
V_4 -> V_25 = ( ( 21875 * V_17 ) >> 13 ) - 45000 ;
V_17 = F_10 ( ( V_24 * ) ( V_5 + 3 ) ) ;
V_4 -> V_26 = ( ( 12500 * V_17 ) >> 13 ) ;
V_4 -> V_20 = V_19 ;
V_4 -> V_22 = true ;
}
V_23:
F_11 ( & V_4 -> V_18 ) ;
return V_7 == 0 ? V_4 : F_12 ( V_7 ) ;
}
static T_1 F_13 ( struct V_15 * V_10 ,
struct V_27 * V_28 ,
char * V_5 )
{
struct V_3 * V_4 = F_6 ( V_10 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_5 , L_3 , V_4 -> V_25 ) ;
}
static T_1 F_16 ( struct V_15 * V_10 ,
struct V_27 * V_28 , char * V_5 )
{
struct V_3 * V_4 = F_6 ( V_10 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_5 , L_3 , V_4 -> V_26 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
if ( V_4 -> V_12 . V_29 ) {
V_4 -> V_8 = V_4 -> V_12 . V_13 ?
V_30 :
V_31 ;
V_4 -> V_14 = V_32 ;
} else {
V_4 -> V_8 = V_4 -> V_12 . V_13 ?
V_33 :
V_34 ;
V_4 -> V_14 = V_35 ;
}
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_36 * V_37 )
{
int V_7 ;
char V_38 [ 2 ] ;
struct V_3 * V_4 ;
struct V_15 * V_39 ;
struct V_40 * V_41 = V_2 -> V_42 ;
struct V_15 * V_10 = & V_2 -> V_10 ;
if ( ! F_19 ( V_41 , V_43 ) ) {
F_3 ( V_10 , L_4 ) ;
return - V_44 ;
}
V_7 = F_2 ( V_2 , V_45 , V_9 ) ;
if ( V_7 != V_9 ) {
F_3 ( V_10 , L_5 , V_7 ) ;
return V_7 < 0 ? V_7 : - V_44 ;
}
V_7 = F_5 ( V_2 , V_38 , sizeof( V_38 ) ) ;
if ( V_7 != sizeof( V_38 ) ) {
F_3 ( V_10 , L_6 , V_7 ) ;
return - V_44 ;
}
if ( ( V_38 [ 1 ] & V_46 ) != V_47 ) {
F_3 ( V_10 , L_7 ) ;
return - V_44 ;
}
V_4 = F_20 ( V_10 , sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_4 -> V_12 . V_13 = false ;
V_4 -> V_12 . V_29 = true ;
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_10 . V_50 )
V_4 -> V_12 = * (struct V_51 * ) V_10 -> V_50 ;
F_17 ( V_4 ) ;
F_21 ( & V_4 -> V_18 ) ;
V_39 = F_22 ( V_10 ,
V_2 -> V_52 ,
V_4 ,
V_53 ) ;
if ( F_14 ( V_39 ) )
F_23 ( V_10 , L_8 ) ;
return F_24 ( V_39 ) ;
}
