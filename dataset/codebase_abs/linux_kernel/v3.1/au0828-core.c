T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
F_2 ( V_2 , V_4 , 0 , V_3 , V_2 -> V_5 , 1 ) ;
F_3 ( 8 , L_1 , V_6 , V_3 , V_2 -> V_5 [ 0 ] ) ;
return V_2 -> V_5 [ 0 ] ;
}
T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_7 )
{
F_3 ( 8 , L_2 , V_6 , V_3 , V_7 ) ;
return F_5 ( V_2 , V_8 , V_7 , V_3 ,
V_2 -> V_5 , 0 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < sizeof( V_2 -> V_5 ) ; V_9 += 16 )
F_3 ( 2 , L_3
L_4 ,
V_6 ,
V_2 -> V_5 [ V_9 + 0 ] , V_2 -> V_5 [ V_9 + 1 ] ,
V_2 -> V_5 [ V_9 + 2 ] , V_2 -> V_5 [ V_9 + 3 ] ,
V_2 -> V_5 [ V_9 + 4 ] , V_2 -> V_5 [ V_9 + 5 ] ,
V_2 -> V_5 [ V_9 + 6 ] , V_2 -> V_5 [ V_9 + 7 ] ,
V_2 -> V_5 [ V_9 + 8 ] , V_2 -> V_5 [ V_9 + 9 ] ,
V_2 -> V_5 [ V_9 + 10 ] , V_2 -> V_5 [ V_9 + 11 ] ,
V_2 -> V_5 [ V_9 + 12 ] , V_2 -> V_5 [ V_9 + 13 ] ,
V_2 -> V_5 [ V_9 + 14 ] , V_2 -> V_5 [ V_9 + 15 ] ) ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_10 , T_1 V_11 ,
T_2 V_12 , unsigned char * V_13 , T_2 V_14 )
{
int V_15 = - V_16 ;
F_7 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_18 ) {
V_15 = F_8 ( V_2 -> V_18 ,
F_9 ( V_2 -> V_18 , 0 ) ,
V_10 ,
V_19 | V_20 |
V_21 ,
V_11 , V_12 ,
V_13 , V_14 , 1000 ) ;
V_15 = F_10 ( V_15 , 0 ) ;
if ( V_15 < 0 ) {
F_11 ( V_22 L_5 ,
V_6 , V_15 ) ;
}
}
F_12 ( & V_2 -> V_17 ) ;
return V_15 ;
}
static int F_2 ( struct V_1 * V_2 , T_2 V_10 , T_1 V_11 ,
T_2 V_12 , unsigned char * V_13 , T_2 V_14 )
{
int V_15 = - V_16 ;
F_7 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_18 ) {
memset ( V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
V_15 = F_8 ( V_2 -> V_18 ,
F_13 ( V_2 -> V_18 , 0 ) ,
V_10 ,
V_23 | V_20 | V_21 ,
V_11 , V_12 ,
V_13 , V_14 , 1000 ) ;
V_15 = F_10 ( V_15 , 0 ) ;
if ( V_15 < 0 ) {
F_11 ( V_22 L_6 ,
V_6 , V_15 ) ;
} else
F_6 ( V_2 ) ;
}
F_12 ( & V_2 -> V_17 ) ;
return V_15 ;
}
static void F_14 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_15 ( V_25 ) ;
F_3 ( 1 , L_7 , V_6 ) ;
F_16 ( V_2 ) ;
if ( F_17 ( 0 ) . type != V_26 )
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( & V_2 -> V_27 ) ;
F_21 ( V_25 , NULL ) ;
F_7 ( & V_2 -> V_17 ) ;
V_2 -> V_18 = NULL ;
F_12 ( & V_2 -> V_17 ) ;
F_22 ( V_2 ) ;
}
static int F_23 ( struct V_24 * V_25 ,
const struct V_28 * V_29 )
{
int V_30 , V_31 ;
struct V_1 * V_2 ;
struct V_32 * V_18 = F_24 ( V_25 ) ;
V_30 = V_25 -> V_33 -> V_34 . V_35 ;
if ( V_30 != 0 )
return - V_16 ;
F_3 ( 1 , L_8 , V_6 ,
F_25 ( V_18 -> V_36 . V_37 ) ,
F_25 ( V_18 -> V_36 . V_38 ) ,
V_30 ) ;
if ( V_18 -> V_39 != V_40 && V_41 == 0 ) {
F_11 ( V_22 L_9 ) ;
F_11 ( V_22 L_10
L_11 ) ;
return - V_16 ;
}
V_2 = F_26 ( sizeof( * V_2 ) , V_42 ) ;
if ( V_2 == NULL ) {
F_11 ( V_22 L_12 , V_6 ) ;
return - V_43 ;
}
F_27 ( & V_2 -> V_17 ) ;
F_27 ( & V_2 -> V_44 . V_45 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_46 = V_29 -> V_47 ;
V_31 = F_28 ( & V_25 -> V_2 , & V_2 -> V_27 ) ;
if ( V_31 ) {
F_11 ( V_22 L_13 ,
V_6 ) ;
F_22 ( V_2 ) ;
return - V_48 ;
}
F_29 ( V_2 , V_49 , 1 << 4 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
if ( F_17 ( 0 ) . type != V_26 )
F_33 ( V_2 , V_25 ) ;
F_34 ( V_2 ) ;
F_21 ( V_25 , V_2 ) ;
F_11 ( V_50 L_14 ,
V_2 -> V_51 . V_52 == NULL ? L_15 : V_2 -> V_51 . V_52 ) ;
return 0 ;
}
static int T_3 F_35 ( void )
{
int V_53 ;
if ( V_54 & 1 )
F_11 ( V_50 L_16 , V_6 ) ;
if ( V_54 & 2 )
F_11 ( V_50 L_17 , V_6 ) ;
if ( V_54 & 4 )
F_11 ( V_50 L_18 , V_6 ) ;
if ( V_54 & 8 )
F_11 ( V_50 L_19 ,
V_6 ) ;
F_11 ( V_50 L_20 ) ;
V_53 = F_36 ( & V_55 ) ;
if ( V_53 )
F_11 ( V_22 L_21 , V_53 ) ;
return V_53 ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_55 ) ;
}
