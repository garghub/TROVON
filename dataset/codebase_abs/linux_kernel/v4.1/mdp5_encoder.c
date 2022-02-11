static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_9 * V_9 )
{
V_9 -> V_10 = F_5 (
& V_11 ) ;
F_6 ( L_1 , V_9 -> V_10 ) ;
}
static void F_7 ( struct V_9 * V_9 )
{
if ( V_9 -> V_10 ) {
F_8 ( V_9 -> V_10 ) ;
V_9 -> V_10 = 0 ;
}
}
static void F_9 ( struct V_9 * V_9 , int V_12 )
{
if ( V_9 -> V_10 ) {
F_6 ( L_2 , V_12 ) ;
V_12 = 1 ;
F_10 ( V_9 -> V_10 , V_12 ) ;
}
}
static void F_4 ( struct V_9 * V_9 ) {}
static void F_7 ( struct V_9 * V_9 ) {}
static void F_9 ( struct V_9 * V_9 , int V_12 ) {}
static void F_11 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
F_7 ( V_9 ) ;
F_13 ( V_3 ) ;
F_14 ( V_9 ) ;
}
static bool F_15 ( struct V_2 * V_3 ,
const struct V_13 * V_14 ,
struct V_13 * V_15 )
{
return true ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_13 * V_15 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_6 = V_3 -> V_6 ;
struct V_17 * V_18 ;
int V_19 = V_9 -> V_19 . V_20 ;
T_1 V_21 , V_22 , V_23 , V_24 ;
T_1 V_25 , V_26 ;
T_1 V_27 , V_28 ;
T_1 V_29 = 0x2100 ;
unsigned long V_30 ;
V_14 = V_15 ;
F_6 ( L_3 ,
V_14 -> V_31 . V_32 , V_14 -> V_33 ,
V_14 -> V_34 , V_14 -> clock ,
V_14 -> V_35 , V_14 -> V_36 ,
V_14 -> V_37 , V_14 -> V_38 ,
V_14 -> V_39 , V_14 -> V_40 ,
V_14 -> V_41 , V_14 -> V_42 ,
V_14 -> type , V_14 -> V_30 ) ;
V_24 = 0 ;
if ( V_14 -> V_30 & V_43 )
V_24 |= V_44 ;
if ( V_14 -> V_30 & V_45 )
V_24 |= V_46 ;
V_21 = 0 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( V_18 -> V_3 == V_3 ) {
switch ( V_18 -> V_47 . V_48 ) {
case 4 :
V_29 |= 0 ;
break;
case 5 :
V_29 |= 0x15 ;
break;
case 6 :
V_29 |= 0x2A ;
break;
case 8 :
default:
V_29 |= 0x3F ;
break;
}
break;
}
}
V_27 = ( V_14 -> V_38 - V_14 -> V_36 ) ;
V_28 = V_14 -> V_38 - ( V_14 -> V_36 - V_14 -> V_35 ) - 1 ;
V_22 = V_14 -> V_42 * V_14 -> V_38 ;
V_23 = ( V_14 -> V_41 - V_14 -> V_40 ) * V_14 -> V_38 ;
V_25 = ( V_14 -> V_42 - V_14 -> V_40 ) * V_14 -> V_38 + V_21 ;
V_26 = V_22 - ( ( V_14 -> V_40 - V_14 -> V_39 ) * V_14 -> V_38 ) + V_21 - 1 ;
if ( V_9 -> V_19 . type == V_49 ) {
V_25 += V_14 -> V_38 - V_14 -> V_36 ;
V_26 -= V_14 -> V_36 - V_14 -> V_35 ;
}
F_18 ( & V_9 -> V_50 , V_30 ) ;
F_19 ( V_1 , F_20 ( V_19 ) ,
F_21 ( V_14 -> V_37 - V_14 -> V_36 ) |
F_22 ( V_14 -> V_38 ) ) ;
F_19 ( V_1 , F_23 ( V_19 ) , V_22 ) ;
F_19 ( V_1 , F_24 ( V_19 ) , V_23 ) ;
F_19 ( V_1 , F_25 ( V_19 ) ,
F_26 ( V_27 ) |
F_27 ( V_28 ) ) ;
F_19 ( V_1 , F_28 ( V_19 ) , V_25 ) ;
F_19 ( V_1 , F_29 ( V_19 ) , V_26 ) ;
F_19 ( V_1 , F_30 ( V_19 ) , 0 ) ;
F_19 ( V_1 , F_31 ( V_19 ) , 0xff ) ;
F_19 ( V_1 , F_32 ( V_19 ) , V_21 ) ;
F_19 ( V_1 , F_33 ( V_19 ) , V_24 ) ;
F_19 ( V_1 , F_34 ( V_19 ) ,
F_35 ( 0 ) |
F_36 ( 0 ) ) ;
F_19 ( V_1 , F_37 ( V_19 ) , 0 ) ;
F_19 ( V_1 , F_38 ( V_19 ) , 0 ) ;
F_19 ( V_1 , F_39 ( V_19 ) , V_29 ) ;
F_19 ( V_1 , F_40 ( V_19 ) , 0x3 ) ;
F_41 ( & V_9 -> V_50 , V_30 ) ;
F_42 ( V_3 -> V_51 , & V_9 -> V_19 ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_52 * V_53 = F_44 ( V_3 -> V_51 ) ;
int V_54 = F_45 ( V_3 -> V_51 ) ;
struct V_55 * V_19 = & V_9 -> V_19 ;
int V_56 = V_9 -> V_19 . V_20 ;
unsigned long V_30 ;
if ( F_46 ( ! V_9 -> V_57 ) )
return;
F_47 ( V_53 , false ) ;
F_18 ( & V_9 -> V_50 , V_30 ) ;
F_19 ( V_1 , F_48 ( V_56 ) , 0 ) ;
F_41 ( & V_9 -> V_50 , V_30 ) ;
F_49 ( V_53 , F_50 ( V_19 ) ) ;
F_51 ( & V_1 -> V_31 , F_52 ( V_54 , V_19 ) ) ;
F_9 ( V_9 , 0 ) ;
V_9 -> V_57 = false ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_52 * V_53 = F_44 ( V_3 -> V_51 ) ;
struct V_55 * V_19 = & V_9 -> V_19 ;
int V_56 = V_9 -> V_19 . V_20 ;
unsigned long V_30 ;
if ( F_46 ( V_9 -> V_57 ) )
return;
F_9 ( V_9 , 1 ) ;
F_18 ( & V_9 -> V_50 , V_30 ) ;
F_19 ( V_1 , F_48 ( V_56 ) , 1 ) ;
F_41 ( & V_9 -> V_50 , V_30 ) ;
F_49 ( V_53 , F_50 ( V_19 ) ) ;
F_47 ( V_53 , true ) ;
V_9 -> V_57 = true ;
}
int F_54 ( struct V_2 * V_3 ,
struct V_2 * V_58 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 ;
int V_59 ;
T_2 V_60 = 0 ;
if ( ! V_3 || ! V_58 )
return - V_61 ;
V_1 = F_1 ( V_3 ) ;
V_59 = V_9 -> V_19 . V_20 ;
if ( V_59 == 1 )
V_60 |= V_62 ;
else if ( V_59 == 2 )
V_60 |= V_63 ;
else
return - V_61 ;
F_55 ( V_1 ) ;
F_19 ( V_1 , F_56 ( 0 ) ,
V_64 ) ;
F_19 ( V_1 , V_65 , 0 ) ;
F_19 ( V_1 , V_66 , V_60 ) ;
F_19 ( V_1 , V_67 , 1 ) ;
F_57 ( V_1 ) ;
return 0 ;
}
struct V_2 * F_58 ( struct V_16 * V_6 ,
struct V_55 * V_19 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_68 = ( V_19 -> type == V_69 ) ?
V_70 : V_71 ;
int V_72 ;
V_9 = F_59 ( sizeof( * V_9 ) , V_73 ) ;
if ( ! V_9 ) {
V_72 = - V_74 ;
goto V_75;
}
memcpy ( & V_9 -> V_19 , V_19 , sizeof( V_9 -> V_19 ) ) ;
V_3 = & V_9 -> V_31 ;
F_60 ( & V_9 -> V_50 ) ;
F_61 ( V_6 , V_3 , & V_76 , V_68 ) ;
F_62 ( V_3 , & V_77 ) ;
F_4 ( V_9 ) ;
return V_3 ;
V_75:
if ( V_3 )
F_11 ( V_3 ) ;
return F_63 ( V_72 ) ;
}
