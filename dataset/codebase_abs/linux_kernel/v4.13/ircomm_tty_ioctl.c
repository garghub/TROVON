static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 , V_6 ;
int V_7 ;
if ( ! V_2 -> V_8 )
return;
V_5 = V_4 -> V_9 . V_10 ;
switch ( V_5 & V_11 ) {
case V_12 : V_6 = V_13 ; break;
case V_14 : V_6 = V_15 ; break;
case V_16 : V_6 = V_17 ; break;
case V_18 : V_6 = V_19 ; break;
default: V_6 = V_13 ; break;
}
if ( V_5 & V_20 )
V_6 |= V_21 ;
if ( V_5 & V_22 )
V_6 |= V_23 ;
if ( ! ( V_5 & V_24 ) )
V_6 |= V_25 ;
V_7 = F_2 ( V_4 ) ;
if ( ! V_7 )
V_7 = 9600 ;
V_2 -> V_26 . V_27 = V_7 ;
F_3 ( V_2 , V_28 , FALSE ) ;
F_4 ( & V_2 -> V_29 , V_5 & V_30 ) ;
if ( V_5 & V_30 ) {
V_2 -> V_26 . V_31 |= V_32 ;
if ( V_2 -> V_33 == V_34 )
F_5 ( L_1 ,
V_35 ) ;
} else {
V_2 -> V_26 . V_31 &= ~ V_32 ;
}
F_6 ( & V_2 -> V_29 , ~ V_5 & V_36 ) ;
V_2 -> V_26 . V_37 = V_6 ;
F_3 ( V_2 , V_38 , FALSE ) ;
F_3 ( V_2 , V_39 , TRUE ) ;
}
void F_7 ( struct V_3 * V_4 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_42 ;
unsigned int V_5 = V_4 -> V_9 . V_10 ;
if ( ( V_5 == V_41 -> V_10 ) &&
( F_8 ( V_4 -> V_9 . V_43 ) ==
F_8 ( V_41 -> V_43 ) ) )
{
return;
}
F_1 ( V_2 , V_4 ) ;
if ( ( V_41 -> V_10 & V_44 ) && ! ( V_5 & V_44 ) ) {
V_2 -> V_26 . V_45 &= ~ ( V_46 | V_47 ) ;
F_3 ( V_2 , V_48 , TRUE ) ;
}
if ( ! ( V_41 -> V_10 & V_44 ) && ( V_5 & V_44 ) ) {
V_2 -> V_26 . V_45 |= V_46 ;
if ( ! F_9 ( V_4 ) || ! F_10 ( V_4 ) )
V_2 -> V_26 . V_45 |= V_47 ;
F_3 ( V_2 , V_48 , TRUE ) ;
}
if ( ( V_41 -> V_10 & V_30 ) && ! F_9 ( V_4 ) )
{
V_4 -> V_49 = 0 ;
F_11 ( V_4 ) ;
}
}
int F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_42 ;
unsigned int V_50 ;
if ( F_13 ( V_4 ) )
return - V_51 ;
V_50 = ( ( V_2 -> V_26 . V_45 & V_47 ) ? V_52 : 0 )
| ( ( V_2 -> V_26 . V_45 & V_46 ) ? V_53 : 0 )
| ( ( V_2 -> V_26 . V_54 & V_55 ) ? V_56 : 0 )
| ( ( V_2 -> V_26 . V_54 & V_57 ) ? V_58 : 0 )
| ( ( V_2 -> V_26 . V_54 & V_59 ) ? V_60 : 0 )
| ( ( V_2 -> V_26 . V_54 & V_61 ) ? V_62 : 0 ) ;
return V_50 ;
}
int F_14 ( struct V_3 * V_4 ,
unsigned int V_63 , unsigned int V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_42 ;
if ( F_13 ( V_4 ) )
return - V_51 ;
F_15 (self != NULL, return -1;) ;
F_15 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_63 & V_52 )
V_2 -> V_26 . V_45 |= V_47 ;
if ( V_63 & V_53 )
V_2 -> V_26 . V_45 |= V_46 ;
if ( V_64 & V_52 )
V_2 -> V_26 . V_45 &= ~ V_47 ;
if ( V_64 & V_53 )
V_2 -> V_26 . V_45 &= ~ V_46 ;
if ( ( V_63 | V_64 ) & V_52 )
V_2 -> V_26 . V_45 |= V_65 ;
if ( ( V_63 | V_64 ) & V_53 )
V_2 -> V_26 . V_45 |= V_66 ;
F_3 ( V_2 , V_48 , TRUE ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_67 T_1 * V_68 )
{
struct V_67 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . line = V_2 -> line ;
V_69 . V_70 = V_2 -> V_29 . V_70 ;
V_69 . V_71 = V_2 -> V_26 . V_27 ;
V_69 . V_72 = V_2 -> V_29 . V_72 ;
V_69 . V_73 = V_2 -> V_29 . V_73 ;
V_69 . type = V_74 ;
if ( F_17 ( V_68 , & V_69 , sizeof( * V_68 ) ) )
return - V_75 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_67 T_1 * V_76 )
{
return 0 ;
}
int F_19 ( struct V_3 * V_4 ,
unsigned int V_77 , unsigned long V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_42 ;
int V_79 = 0 ;
if ( ( V_77 != V_80 ) && ( V_77 != V_81 ) &&
( V_77 != V_82 ) && ( V_77 != V_83 ) &&
( V_77 != V_84 ) && ( V_77 != V_85 ) ) {
if ( F_13 ( V_4 ) )
return - V_51 ;
}
switch ( V_77 ) {
case V_80 :
V_79 = F_16 ( V_2 , (struct V_67 T_1 * ) V_78 ) ;
break;
case V_81 :
V_79 = F_18 ( V_2 , (struct V_67 T_1 * ) V_78 ) ;
break;
case V_84 :
F_20 ( L_2 ) ;
break;
case V_85 :
F_20 ( L_3 , V_35 ) ;
return 0 ;
default:
V_79 = - V_86 ;
}
return V_79 ;
}
