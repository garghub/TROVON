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
static void F_15 ( struct V_2 * V_3 ,
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
if ( V_9 -> V_19 . type != V_43 ) {
if ( V_14 -> V_30 & V_44 )
V_24 |= V_45 ;
if ( V_14 -> V_30 & V_46 )
V_24 |= V_47 ;
}
V_21 = 0 ;
F_16 (connector, &dev->mode_config.connector_list, head) {
if ( V_18 -> V_3 == V_3 ) {
switch ( V_18 -> V_48 . V_49 ) {
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
if ( V_9 -> V_19 . type == V_50 ) {
V_25 += V_14 -> V_38 - V_14 -> V_36 ;
V_26 -= V_14 -> V_36 - V_14 -> V_35 ;
}
F_17 ( & V_9 -> V_51 , V_30 ) ;
F_18 ( V_1 , F_19 ( V_19 ) ,
F_20 ( V_14 -> V_37 - V_14 -> V_36 ) |
F_21 ( V_14 -> V_38 ) ) ;
F_18 ( V_1 , F_22 ( V_19 ) , V_22 ) ;
F_18 ( V_1 , F_23 ( V_19 ) , V_23 ) ;
F_18 ( V_1 , F_24 ( V_19 ) ,
F_25 ( V_27 ) |
F_26 ( V_28 ) ) ;
F_18 ( V_1 , F_27 ( V_19 ) , V_25 ) ;
F_18 ( V_1 , F_28 ( V_19 ) , V_26 ) ;
F_18 ( V_1 , F_29 ( V_19 ) , 0 ) ;
F_18 ( V_1 , F_30 ( V_19 ) , 0xff ) ;
F_18 ( V_1 , F_31 ( V_19 ) , V_21 ) ;
F_18 ( V_1 , F_32 ( V_19 ) , V_24 ) ;
F_18 ( V_1 , F_33 ( V_19 ) ,
F_34 ( 0 ) |
F_35 ( 0 ) ) ;
F_18 ( V_1 , F_36 ( V_19 ) , 0 ) ;
F_18 ( V_1 , F_37 ( V_19 ) , 0 ) ;
F_18 ( V_1 , F_38 ( V_19 ) , V_29 ) ;
F_18 ( V_1 , F_39 ( V_19 ) , 0x3 ) ;
F_40 ( & V_9 -> V_51 , V_30 ) ;
F_41 ( V_3 -> V_52 , & V_9 -> V_19 ,
V_9 -> V_53 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_54 * V_53 = V_9 -> V_53 ;
int V_55 = F_43 ( V_3 -> V_52 ) ;
struct V_56 * V_19 = & V_9 -> V_19 ;
int V_57 = V_9 -> V_19 . V_20 ;
unsigned long V_30 ;
if ( F_44 ( ! V_9 -> V_58 ) )
return;
F_45 ( V_53 , false ) ;
F_17 ( & V_9 -> V_51 , V_30 ) ;
F_18 ( V_1 , F_46 ( V_57 ) , 0 ) ;
F_40 ( & V_9 -> V_51 , V_30 ) ;
F_47 ( V_53 , F_48 ( V_19 ) ) ;
F_49 ( & V_1 -> V_31 , F_50 ( V_55 , V_19 ) ) ;
F_9 ( V_9 , 0 ) ;
V_9 -> V_58 = false ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_54 * V_53 = V_9 -> V_53 ;
struct V_56 * V_19 = & V_9 -> V_19 ;
int V_57 = V_9 -> V_19 . V_20 ;
unsigned long V_30 ;
if ( F_44 ( V_9 -> V_58 ) )
return;
F_9 ( V_9 , 1 ) ;
F_17 ( & V_9 -> V_51 , V_30 ) ;
F_18 ( V_1 , F_46 ( V_57 ) , 1 ) ;
F_40 ( & V_9 -> V_51 , V_30 ) ;
F_47 ( V_53 , F_48 ( V_19 ) ) ;
F_45 ( V_53 , true ) ;
V_9 -> V_58 = true ;
}
int F_52 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_19 = V_9 -> V_19 . V_20 ;
return F_53 ( V_1 , F_54 ( V_19 ) ) ;
}
T_2 F_55 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_19 = V_9 -> V_19 . V_20 ;
return F_53 ( V_1 , F_56 ( V_19 ) ) ;
}
int F_57 ( struct V_2 * V_3 ,
struct V_2 * V_59 )
{
struct V_9 * V_9 = F_12 ( V_3 ) ;
struct V_9 * V_60 = F_12 ( V_59 ) ;
struct V_1 * V_1 ;
int V_61 ;
T_2 V_62 = 0 ;
if ( ! V_3 || ! V_59 )
return - V_63 ;
V_1 = F_1 ( V_3 ) ;
V_61 = V_9 -> V_19 . V_20 ;
if ( V_61 == 1 )
V_62 |= V_64 ;
else if ( V_61 == 2 )
V_62 |= V_65 ;
else
return - V_63 ;
F_58 ( V_1 ) ;
F_18 ( V_1 , V_66 , 0 ) ;
F_18 ( V_1 , V_67 , V_62 ) ;
F_18 ( V_1 , V_68 , 1 ) ;
F_59 ( V_9 -> V_53 , V_60 -> V_53 , true ) ;
F_60 ( V_1 ) ;
return 0 ;
}
struct V_2 * F_61 ( struct V_16 * V_6 ,
struct V_56 * V_19 , struct V_54 * V_53 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_69 = ( V_19 -> type == V_43 ) ?
V_70 : V_71 ;
int V_72 ;
V_9 = F_62 ( sizeof( * V_9 ) , V_73 ) ;
if ( ! V_9 ) {
V_72 = - V_74 ;
goto V_75;
}
memcpy ( & V_9 -> V_19 , V_19 , sizeof( V_9 -> V_19 ) ) ;
V_3 = & V_9 -> V_31 ;
V_9 -> V_53 = V_53 ;
F_63 ( & V_9 -> V_51 ) ;
F_64 ( V_6 , V_3 , & V_76 , V_69 , NULL ) ;
F_65 ( V_3 , & V_77 ) ;
F_4 ( V_9 ) ;
return V_3 ;
V_75:
if ( V_3 )
F_11 ( V_3 ) ;
return F_66 ( V_72 ) ;
}
