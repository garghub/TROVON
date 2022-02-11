T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_4 = 0 ;
F_2 ( V_2 , V_5 , 0 , V_3 , & V_4 , 1 ) ;
F_3 ( 8 , L_1 , V_6 , V_3 , V_4 ) ;
return V_4 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_7 )
{
F_3 ( 8 , L_2 , V_6 , V_3 , V_7 ) ;
return F_5 ( V_2 , V_8 , V_7 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 )
{
int V_12 = - V_13 ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_7 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_15 | V_16 |
V_17 ,
V_10 , V_11 , NULL , 0 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( V_18 L_3 ,
V_6 , V_12 ) ;
}
}
return V_12 ;
}
static int F_2 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 , unsigned char * V_19 , T_2 V_20 )
{
int V_12 = - V_13 ;
F_10 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_11 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_22 | V_16 | V_17 ,
V_10 , V_11 ,
V_2 -> V_23 , V_20 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( V_18 L_4 ,
V_6 , V_12 ) ;
}
memcpy ( V_19 , V_2 -> V_23 , V_20 ) ;
}
F_12 ( & V_2 -> V_21 ) ;
return V_12 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static void F_16 ( struct V_24 * V_25 )
{
struct V_1 * V_2 =
F_17 ( V_25 , struct V_1 , V_25 ) ;
F_18 ( & V_2 -> V_26 ) ;
F_19 ( & V_2 -> V_25 ) ;
F_13 ( V_2 ) ;
}
static void F_20 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_21 ( V_28 ) ;
F_3 ( 1 , L_5 , V_6 ) ;
F_22 ( V_2 ) ;
F_23 ( V_28 , NULL ) ;
F_10 ( & V_2 -> V_21 ) ;
V_2 -> V_14 = NULL ;
F_12 ( & V_2 -> V_21 ) ;
#ifdef F_24
if ( F_25 ( 0 ) . type != V_29 ) {
F_26 ( V_2 ) ;
F_27 ( & V_2 -> V_25 ) ;
F_28 ( & V_2 -> V_25 ) ;
return;
}
#endif
F_13 ( V_2 ) ;
}
static int F_29 ( struct V_27 * V_28 ,
const struct V_30 * V_31 )
{
int V_32 ;
int V_33 = 0 ;
struct V_1 * V_2 ;
struct V_34 * V_14 = F_30 ( V_28 ) ;
V_32 = V_28 -> V_35 -> V_36 . V_37 ;
if ( V_32 != 0 )
return - V_13 ;
F_3 ( 1 , L_6 , V_6 ,
F_31 ( V_14 -> V_38 . V_39 ) ,
F_31 ( V_14 -> V_38 . V_40 ) ,
V_32 ) ;
if ( V_14 -> V_41 != V_42 && V_43 == 0 ) {
F_9 ( V_18 L_7 ) ;
F_9 ( V_18 L_8
L_9 ) ;
return - V_13 ;
}
V_2 = F_32 ( sizeof( * V_2 ) , V_44 ) ;
if ( V_2 == NULL ) {
F_9 ( V_18 L_10 , V_6 ) ;
return - V_45 ;
}
F_33 ( & V_2 -> V_46 ) ;
F_10 ( & V_2 -> V_46 ) ;
F_33 ( & V_2 -> V_21 ) ;
F_33 ( & V_2 -> V_47 . V_46 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_48 = V_31 -> V_49 ;
#ifdef F_24
V_2 -> V_25 . V_50 = F_16 ;
V_33 = F_34 ( & V_28 -> V_2 , & V_2 -> V_25 ) ;
if ( V_33 ) {
F_35 ( L_11 ,
V_6 ) ;
F_12 ( & V_2 -> V_46 ) ;
F_15 ( V_2 ) ;
return V_33 ;
}
V_33 = F_36 ( & V_2 -> V_26 , 4 ) ;
if ( V_33 ) {
F_35 ( L_12 ,
V_6 ) ;
F_12 ( & V_2 -> V_46 ) ;
F_15 ( V_2 ) ;
return V_33 ;
}
V_2 -> V_25 . V_51 = & V_2 -> V_26 ;
#endif
F_37 ( V_2 , V_52 , 1 << 4 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
#ifdef F_24
if ( F_25 ( 0 ) . type != V_29 )
F_41 ( V_2 , V_28 ) ;
#endif
V_33 = F_42 ( V_2 ) ;
if ( V_33 )
F_35 ( L_13 ,
V_6 ) ;
F_23 ( V_28 , V_2 ) ;
F_9 ( V_53 L_14 ,
V_2 -> V_54 . V_55 == NULL ? L_15 : V_2 -> V_54 . V_55 ) ;
F_12 ( & V_2 -> V_46 ) ;
return V_33 ;
}
static int T_4 F_43 ( void )
{
int V_56 ;
if ( V_57 & 1 )
F_9 ( V_53 L_16 , V_6 ) ;
if ( V_57 & 2 )
F_9 ( V_53 L_17 , V_6 ) ;
if ( V_57 & 4 )
F_9 ( V_53 L_18 , V_6 ) ;
if ( V_57 & 8 )
F_9 ( V_53 L_19 ,
V_6 ) ;
F_9 ( V_53 L_20 ) ;
V_56 = F_44 ( & V_58 ) ;
if ( V_56 )
F_9 ( V_18 L_21 , V_56 ) ;
return V_56 ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_58 ) ;
}
