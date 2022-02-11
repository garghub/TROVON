static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ,
V_8 ) ;
struct V_6 * V_9 = F_2 ( V_4 ,
V_10 ) ;
V_7 -> V_11 = V_7 -> V_12 = 48000 ;
V_9 -> V_11 = V_9 -> V_12 = 2 ;
F_3 ( V_4 , V_13 ) ;
V_5 = F_4 ( V_2 -> V_14 ,
V_15 |
V_16 |
V_17 ) ;
if ( V_5 < 0 ) {
F_5 ( V_2 -> V_18 , L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_6 ( V_2 -> V_14 , 0x3 , 0x3 , 2 , 24 ) ;
if ( V_5 < 0 ) {
F_5 ( V_2 -> V_18 , L_2 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
return F_8 ( V_20 -> V_21 ,
V_8 , 48000 ) ;
}
static int F_9 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_5 ;
V_5 = F_10 ( V_24 , V_25 ,
19200000 , V_26 ) ;
if ( V_5 < 0 )
F_5 ( V_24 -> V_18 , L_3 ) ;
V_5 = F_11 ( V_24 , 0 ,
V_27 , 0 , V_28 ) ;
if ( V_5 < 0 ) {
F_5 ( V_24 -> V_18 , L_4 , V_5 ) ;
return - V_29 ;
}
return V_5 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_5 ;
V_5 = F_11 ( V_24 , 0 ,
V_30 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_5 ( V_24 -> V_18 , L_5 , V_5 ) ;
return - V_29 ;
}
return V_5 ;
}
static int F_13 ( struct V_31 * V_32 )
{
int V_33 = 0 ;
int V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
const char * V_39 = NULL ;
int V_40 = 0 ;
V_38 = ( & V_32 -> V_18 ) -> V_41 ;
V_36 = & V_42 ;
V_36 -> V_18 = & V_32 -> V_18 ;
V_40 = V_43 + 1 ;
for ( V_34 = 0 ; V_34 < F_14 ( V_44 ) ; V_34 ++ ) {
if ( ! strcmp ( V_44 [ V_34 ] . V_45 , L_6 ) ) {
V_40 = V_34 ;
break;
}
}
V_39 = F_15 ( V_38 -> V_46 ) ;
if ( V_39 != NULL ) {
snprintf ( V_45 , sizeof( V_45 ) ,
L_7 , L_8 , V_39 ) ;
V_44 [ V_40 ] . V_45 = V_45 ;
}
V_33 = F_16 ( & V_32 -> V_18 , V_36 ) ;
if ( V_33 ) {
F_5 ( & V_32 -> V_18 ,
L_9 , V_33 ) ;
return V_33 ;
}
F_17 ( V_32 , V_36 ) ;
return V_33 ;
}
