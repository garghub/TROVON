static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_9 -> V_10 [ V_7 -> V_11 ] ) ) ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_17 ;
T_2 V_18 ;
T_3 V_19 ;
if ( ! F_6 ( V_17 , V_20 ) )
return - V_21 ;
if ( ( F_7 ( V_13 , V_22 , 0 ) & 0x80 )
|| ( F_7 ( V_13 , V_23 , 0 ) & 0xFC ) ) {
F_8 ( & V_17 -> V_2 ,
L_2 ,
V_13 -> V_24 ) ;
return - V_21 ;
}
V_18 = ( F_7 ( V_13 , V_25 , 0 ) << 8 )
+ F_7 ( V_13 , V_26 , 0 ) ;
V_19 = F_7 ( V_13 , V_27 , 0 ) ;
if ( V_18 != 0x5CA3
|| V_19 != 0x70 ) {
F_8 ( & V_17 -> V_2 ,
L_3 ,
V_18 , V_19 ) ;
return - V_21 ;
}
F_9 ( V_15 -> type , L_4 , V_28 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 ,
const struct V_29 * V_30 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 = & V_13 -> V_2 ;
int V_31 ;
V_9 = F_11 ( V_2 , sizeof( struct V_8 ) , V_32 ) ;
if ( ! V_9 )
return - V_33 ;
F_12 ( V_13 , V_9 ) ;
V_9 -> V_34 = 0 ;
F_13 ( & V_9 -> V_35 ) ;
V_9 -> V_10 [ 1 ] = V_9 -> V_10 [ 0 ] = 0 ;
V_31 = F_14 ( V_2 , & V_36 . V_37 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_14 ( V_2 , & V_38 . V_37 ) ;
if ( V_31 )
goto V_39;
V_9 -> V_40 = F_15 ( V_2 ) ;
if ( F_16 ( V_9 -> V_40 ) ) {
V_31 = F_17 ( V_9 -> V_40 ) ;
goto V_39;
}
return 0 ;
V_39:
F_18 ( V_2 , & V_36 . V_37 ) ;
F_18 ( V_2 , & V_38 . V_37 ) ;
return V_31 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = F_20 ( V_13 ) ;
F_21 ( V_9 -> V_40 ) ;
F_18 ( & V_13 -> V_2 ,
& V_36 . V_37 ) ;
F_18 ( & V_13 -> V_2 ,
& V_38 . V_37 ) ;
return 0 ;
}
static T_3 F_7 ( struct V_12 * V_13 , T_3 V_41 , T_3 V_42 )
{
int V_43 , V_44 ;
struct V_1 * V_2 ;
const char * V_45 ;
if ( F_20 ( V_13 ) ) {
V_2 = & V_13 -> V_2 ;
V_45 = L_5 ;
} else {
V_2 = & V_13 -> V_17 -> V_2 ;
V_45 = L_6 ;
}
for ( V_44 = 1 ; V_44 <= V_46 ; V_44 ++ ) {
V_43 = F_22 ( V_13 , V_41 ) ;
if ( V_43 >= 0 ) {
F_8 ( V_2 , L_7 ,
V_45 , V_43 , V_41 ) ;
return V_43 ;
}
F_8 ( V_2 , L_8 , V_45 , V_44 ) ;
F_23 ( V_44 ) ;
}
F_24 ( V_2 , L_9 , V_45 ,
V_41 ) ;
return V_42 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_25 ( V_2 ) ;
struct V_8 * V_9 = F_20 ( V_13 ) ;
F_26 ( & V_9 -> V_35 ) ;
if ( ! V_9 -> V_34 || F_27 ( V_47 , V_9 -> V_48 + V_49 * 2 ) ) {
F_8 ( & V_13 -> V_2 , L_10 ) ;
V_9 -> V_10 [ 0 ] = F_7 ( V_13 ,
V_50 , V_9 -> V_10 [ 0 ] ) ;
V_9 -> V_10 [ 1 ] = F_7 ( V_13 ,
V_51 , V_9 -> V_10 [ 1 ] ) ;
V_9 -> V_48 = V_47 ;
V_9 -> V_34 = 1 ;
}
F_28 ( & V_9 -> V_35 ) ;
return V_9 ;
}
