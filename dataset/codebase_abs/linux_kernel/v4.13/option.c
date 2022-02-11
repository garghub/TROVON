static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 =
& V_2 -> V_7 -> V_8 -> V_9 ;
struct V_10 * V_11 = & V_2 -> V_12 -> V_13 ;
const struct V_14 * V_15 ;
if ( V_6 -> V_16 == 0x08 )
return - V_17 ;
V_15 = ( void * ) V_4 -> V_18 ;
if ( V_15 && F_2 ( V_6 -> V_19 ,
& V_15 -> V_20 ) )
return - V_17 ;
if ( V_11 -> V_21 == F_3 ( V_22 ) &&
V_11 -> V_23 == F_3 ( V_24 ) &&
V_6 -> V_16 != V_25 )
return - V_17 ;
F_4 ( V_2 , ( void * ) V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
const struct V_14 * V_15 ;
struct V_26 * V_27 ;
V_27 = F_6 ( sizeof( struct V_26 ) , V_28 ) ;
if ( ! V_27 )
return - V_29 ;
V_15 = F_7 ( V_2 ) ;
V_6 = & V_2 -> V_7 -> V_8 -> V_9 ;
if ( ! V_15 || ! F_2 ( V_6 -> V_19 ,
& V_15 -> V_30 ) ) {
V_27 -> V_31 = 1 ;
}
F_8 ( & V_27 -> V_32 ) ;
F_4 ( V_2 , V_27 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_26 * V_33 = F_7 ( V_2 ) ;
F_10 ( V_33 ) ;
}
static void F_11 ( struct V_34 * V_34 )
{
int V_35 ;
int V_36 = V_34 -> V_36 ;
struct V_37 * V_38 = V_34 -> V_39 ;
struct V_40 * V_12 = & V_38 -> V_12 ;
struct V_41 * V_42 =
F_12 ( V_38 ) ;
F_13 ( V_12 , L_1 , V_43 , V_34 , V_38 , V_42 ) ;
if ( V_36 == 0 ) {
struct V_44 * V_45 =
(struct V_44 * ) V_34 -> V_46 ;
if ( ! V_45 ) {
F_13 ( V_12 , L_2 , V_43 ) ;
return;
}
if ( ( V_45 -> V_47 == 0xA1 ) &&
( V_45 -> V_48 == 0x20 ) ) {
int V_49 ;
unsigned char V_50 = * ( ( unsigned char * )
V_34 -> V_46 +
sizeof( struct V_44 ) ) ;
F_13 ( V_12 , L_3 , V_43 , V_50 ) ;
V_49 = V_42 -> V_51 ;
V_42 -> V_52 = 1 ;
V_42 -> V_51 = ( ( V_50 & 0x01 ) ? 1 : 0 ) ;
V_42 -> V_53 = ( ( V_50 & 0x02 ) ? 1 : 0 ) ;
V_42 -> V_54 = ( ( V_50 & 0x08 ) ? 1 : 0 ) ;
if ( V_49 && ! V_42 -> V_51 )
F_14 ( & V_38 -> V_38 , true ) ;
} else {
F_13 ( V_12 , L_4 , V_43 ,
V_45 -> V_47 , V_45 -> V_48 ) ;
}
} else if ( V_36 == - V_55 || V_36 == - V_56 ) {
F_13 ( V_12 , L_5 , V_43 , V_36 ) ;
} else
F_13 ( V_12 , L_6 , V_43 , V_36 ) ;
if ( V_36 != - V_56 && V_36 != - V_55 ) {
F_15 ( V_38 -> V_2 -> V_12 ) ;
V_35 = F_16 ( V_34 , V_57 ) ;
if ( V_35 )
F_13 ( V_12 , L_7 ,
V_43 , V_35 ) ;
}
}
