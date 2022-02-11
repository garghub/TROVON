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
static int F_10 ( struct V_12 * V_29 ,
const struct V_30 * V_31 )
{
struct V_8 * V_9 ;
int V_32 = 0 ;
V_9 = F_11 ( sizeof( struct V_8 ) , V_33 ) ;
if ( ! V_9 ) {
V_32 = - V_34 ;
goto exit;
}
F_12 ( V_29 , V_9 ) ;
V_9 -> V_35 = 0 ;
F_13 ( & V_9 -> V_36 ) ;
V_9 -> V_10 [ 1 ] = V_9 -> V_10 [ 0 ] = 0 ;
V_32 = F_14 ( & V_29 -> V_2 ,
& V_37 . V_38 ) ;
if ( V_32 )
goto V_39;
V_32 = F_14 ( & V_29 -> V_2 ,
& V_40 . V_38 ) ;
if ( V_32 )
goto V_39;
V_9 -> V_41 = F_15 ( & V_29 -> V_2 ) ;
if ( F_16 ( V_9 -> V_41 ) ) {
V_32 = F_17 ( V_9 -> V_41 ) ;
goto V_39;
}
return 0 ;
V_39:
F_18 ( & V_29 -> V_2 ,
& V_37 . V_38 ) ;
F_18 ( & V_29 -> V_2 ,
& V_40 . V_38 ) ;
F_19 ( V_9 ) ;
exit:
return V_32 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = F_21 ( V_13 ) ;
F_22 ( V_9 -> V_41 ) ;
F_18 ( & V_13 -> V_2 ,
& V_37 . V_38 ) ;
F_18 ( & V_13 -> V_2 ,
& V_40 . V_38 ) ;
F_19 ( V_9 ) ;
return 0 ;
}
static T_3 F_7 ( struct V_12 * V_13 , T_3 V_42 , T_3 V_43 )
{
int V_44 , V_45 ;
struct V_1 * V_2 ;
const char * V_46 ;
if ( F_21 ( V_13 ) ) {
V_2 = & V_13 -> V_2 ;
V_46 = L_5 ;
} else {
V_2 = & V_13 -> V_17 -> V_2 ;
V_46 = L_6 ;
}
for ( V_45 = 1 ; V_45 <= V_47 ; V_45 ++ ) {
V_44 = F_23 ( V_13 , V_42 ) ;
if ( V_44 >= 0 ) {
F_8 ( V_2 , L_7 ,
V_46 , V_44 , V_42 ) ;
return V_44 ;
}
F_8 ( V_2 , L_8 , V_46 , V_45 ) ;
F_24 ( V_45 ) ;
}
F_25 ( V_2 , L_9 , V_46 ,
V_42 ) ;
return V_43 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_26 ( V_2 ) ;
struct V_8 * V_9 = F_21 ( V_13 ) ;
F_27 ( & V_9 -> V_36 ) ;
if ( ! V_9 -> V_35 || F_28 ( V_48 , V_9 -> V_49 + V_50 * 2 ) ) {
F_8 ( & V_13 -> V_2 , L_10 ) ;
V_9 -> V_10 [ 0 ] = F_7 ( V_13 ,
V_51 , V_9 -> V_10 [ 0 ] ) ;
V_9 -> V_10 [ 1 ] = F_7 ( V_13 ,
V_52 , V_9 -> V_10 [ 1 ] ) ;
V_9 -> V_49 = V_48 ;
V_9 -> V_35 = 1 ;
}
F_29 ( & V_9 -> V_36 ) ;
return V_9 ;
}
