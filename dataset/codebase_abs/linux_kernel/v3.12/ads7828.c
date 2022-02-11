static inline T_1 F_1 ( T_1 V_1 , int V_2 )
{
return V_1 | ( ( ( V_2 >> 1 ) | ( V_2 & 0x01 ) << 2 ) << 4 ) ;
}
static struct V_3 * F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_3 * V_8 = F_4 ( V_7 ) ;
F_5 ( & V_8 -> V_9 ) ;
if ( F_6 ( V_10 , V_8 -> V_11 + V_12 + V_12 / 2 )
|| ! V_8 -> V_13 ) {
unsigned int V_2 ;
F_7 ( & V_7 -> V_5 , L_1 ) ;
for ( V_2 = 0 ; V_2 < V_14 ; V_2 ++ ) {
T_1 V_1 = F_1 ( V_8 -> V_15 , V_2 ) ;
V_8 -> V_16 [ V_2 ] = V_8 -> V_17 ( V_7 , V_1 ) ;
}
V_8 -> V_11 = V_10 ;
V_8 -> V_13 = true ;
}
F_8 ( & V_8 -> V_9 ) ;
return V_8 ;
}
static T_2 F_9 ( struct V_4 * V_5 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_10 ( V_19 ) ;
struct V_3 * V_8 = F_2 ( V_5 ) ;
unsigned int V_23 = F_11 ( V_8 -> V_16 [ V_22 -> V_24 ] *
V_8 -> V_25 , 1000 ) ;
return sprintf ( V_20 , L_2 , V_23 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_3 * V_8 = F_4 ( V_7 ) ;
F_13 ( V_8 -> V_26 ) ;
F_14 ( & V_7 -> V_5 . V_27 , & V_28 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
const struct V_29 * V_30 )
{
struct V_31 * V_32 = F_16 ( & V_7 -> V_5 ) ;
struct V_3 * V_8 ;
int V_33 ;
V_8 = F_17 ( & V_7 -> V_5 , sizeof( struct V_3 ) ,
V_34 ) ;
if ( ! V_8 )
return - V_35 ;
if ( V_32 ) {
V_8 -> V_36 = V_32 -> V_36 ;
V_8 -> V_37 = V_32 -> V_37 ;
if ( V_8 -> V_37 )
V_8 -> V_38 = V_32 -> V_38 ;
}
if ( V_8 -> V_38 )
V_8 -> V_38 = F_18 ( V_8 -> V_38 ,
V_39 ,
V_40 ) ;
else
V_8 -> V_38 = V_41 ;
if ( V_30 -> V_42 == V_43 ) {
V_8 -> V_25 = F_11 ( V_8 -> V_38 * 1000 , 4096 ) ;
V_8 -> V_17 = V_44 ;
} else {
V_8 -> V_25 = F_11 ( V_8 -> V_38 * 1000 , 256 ) ;
V_8 -> V_17 = V_45 ;
}
V_8 -> V_15 = V_8 -> V_37 ? V_46 : V_47 ;
if ( ! V_8 -> V_36 )
V_8 -> V_15 |= V_48 ;
F_19 ( V_7 , V_8 ) ;
F_20 ( & V_8 -> V_9 ) ;
V_33 = F_21 ( & V_7 -> V_5 . V_27 , & V_28 ) ;
if ( V_33 )
return V_33 ;
V_8 -> V_26 = F_22 ( & V_7 -> V_5 ) ;
if ( F_23 ( V_8 -> V_26 ) ) {
V_33 = F_24 ( V_8 -> V_26 ) ;
goto error;
}
return 0 ;
error:
F_14 ( & V_7 -> V_5 . V_27 , & V_28 ) ;
return V_33 ;
}
