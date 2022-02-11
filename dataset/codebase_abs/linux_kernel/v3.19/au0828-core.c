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
F_9 ( L_3 ,
V_6 , V_12 ) ;
}
}
return V_12 ;
}
static int F_2 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 , unsigned char * V_18 , T_2 V_19 )
{
int V_12 = - V_13 ;
F_10 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_11 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_21 | V_16 | V_17 ,
V_10 , V_11 ,
V_2 -> V_22 , V_19 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( L_4 ,
V_6 , V_12 ) ;
}
memcpy ( V_18 , V_2 -> V_22 , V_19 ) ;
}
F_12 ( & V_2 -> V_20 ) ;
return V_12 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 =
F_17 ( V_24 , struct V_1 , V_24 ) ;
F_18 ( & V_2 -> V_25 ) ;
F_19 ( & V_2 -> V_24 ) ;
F_13 ( V_2 ) ;
}
static void F_20 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_21 ( V_27 ) ;
F_3 ( 1 , L_5 , V_6 ) ;
V_2 -> V_28 = V_29 ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_27 , NULL ) ;
F_10 ( & V_2 -> V_20 ) ;
V_2 -> V_14 = NULL ;
F_12 ( & V_2 -> V_20 ) ;
#ifdef F_25
if ( F_26 ( 0 ) . type != V_30 ) {
F_27 ( V_2 ) ;
F_28 ( & V_2 -> V_24 ) ;
F_29 ( & V_2 -> V_24 ) ;
return;
}
#endif
F_13 ( V_2 ) ;
}
static int F_30 ( struct V_26 * V_27 ,
const struct V_31 * V_32 )
{
int V_33 ;
int V_34 = 0 ;
struct V_1 * V_2 ;
struct V_35 * V_14 = F_31 ( V_27 ) ;
V_33 = V_27 -> V_36 -> V_37 . V_38 ;
if ( V_33 != 0 )
return - V_13 ;
F_3 ( 1 , L_6 , V_6 ,
F_32 ( V_14 -> V_39 . V_40 ) ,
F_32 ( V_14 -> V_39 . V_41 ) ,
V_33 ) ;
if ( V_14 -> V_42 != V_43 && V_44 == 0 ) {
F_9 ( L_7 ) ;
F_9 ( L_8 ) ;
return - V_13 ;
}
V_2 = F_33 ( sizeof( * V_2 ) , V_45 ) ;
if ( V_2 == NULL ) {
F_9 ( L_9 , V_6 ) ;
return - V_46 ;
}
F_34 ( & V_2 -> V_47 ) ;
F_10 ( & V_2 -> V_47 ) ;
F_34 ( & V_2 -> V_20 ) ;
F_34 ( & V_2 -> V_48 . V_47 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_49 = V_32 -> V_50 ;
#ifdef F_25
V_2 -> V_24 . V_51 = F_16 ;
V_34 = F_35 ( & V_27 -> V_2 , & V_2 -> V_24 ) ;
if ( V_34 ) {
F_9 ( L_10 ,
V_6 ) ;
F_12 ( & V_2 -> V_47 ) ;
F_15 ( V_2 ) ;
return V_34 ;
}
V_34 = F_36 ( & V_2 -> V_25 , 4 ) ;
if ( V_34 ) {
F_9 ( L_11 ,
V_6 ) ;
F_12 ( & V_2 -> V_47 ) ;
F_15 ( V_2 ) ;
return V_34 ;
}
V_2 -> V_24 . V_52 = & V_2 -> V_25 ;
#endif
F_37 ( V_2 , V_53 , 1 << 4 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
#ifdef F_25
if ( F_26 ( 0 ) . type != V_30 )
F_41 ( V_2 , V_27 ) ;
#endif
V_34 = F_42 ( V_2 ) ;
if ( V_34 )
F_9 ( L_12 ,
V_6 ) ;
F_43 ( V_2 ) ;
F_24 ( V_27 , V_2 ) ;
F_44 ( L_13 ,
V_2 -> V_54 . V_55 == NULL ? L_14 : V_2 -> V_54 . V_55 ) ;
F_12 ( & V_2 -> V_47 ) ;
return V_34 ;
}
static int F_45 ( struct V_26 * V_27 ,
T_4 V_56 )
{
struct V_1 * V_2 = F_21 ( V_27 ) ;
if ( ! V_2 )
return 0 ;
F_44 ( L_15 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_21 ( V_27 ) ;
if ( ! V_2 )
return 0 ;
F_44 ( L_16 ) ;
F_37 ( V_2 , V_53 , 1 << 4 ) ;
F_38 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
static int T_5 F_53 ( void )
{
int V_57 ;
if ( V_58 & 1 )
F_44 ( L_17 , V_6 ) ;
if ( V_58 & 2 )
F_44 ( L_18 , V_6 ) ;
if ( V_58 & 4 )
F_44 ( L_19 , V_6 ) ;
if ( V_58 & 8 )
F_44 ( L_20 ,
V_6 ) ;
if ( V_58 & 16 )
F_44 ( L_21 ,
V_6 ) ;
F_44 ( L_22 ) ;
V_57 = F_54 ( & V_59 ) ;
if ( V_57 )
F_9 ( L_23 , V_57 ) ;
return V_57 ;
}
static void T_6 F_55 ( void )
{
F_56 ( & V_59 ) ;
}
