static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_4 ) ;
switch ( V_5 ) {
case V_6 :
memcpy ( V_2 -> V_7 , V_8 , V_5 ) ;
break;
case V_9 :
memcpy ( V_2 -> V_7 , V_10 , V_5 ) ;
break;
case V_11 :
memcpy ( V_2 -> V_7 , V_12 , V_5 ) ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static void F_4 ( struct V_14 * V_15 , int V_16 )
{
if ( V_15 -> V_17 )
V_15 -> V_17 ( V_15 , V_16 ) ;
}
static void F_5 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_6 ( V_19 -> V_20 ) ;
struct V_21 * V_22 = F_7 ( V_2 ) ;
int V_23 = 0 ;
V_23 = F_8 ( V_19 , V_24 ) |
V_25 | F_9 ( 0xffff , 16 ) ;
F_10 ( V_19 , V_24 , V_23 ) ;
V_23 = F_8 ( V_19 , V_24 ) ;
V_23 &= ( ~ V_25 ) ;
V_23 |= F_9 ( 0xffff , 16 ) ;
F_10 ( V_19 , V_24 , V_23 ) ;
F_11 ( V_19 -> V_26 + V_27 , 0 , 32 ) ;
F_10 ( V_19 , V_28 , V_29 |
V_30 ) ;
F_10 ( V_19 , V_31 , V_32 |
V_33 ) ;
F_10 ( V_19 , V_34 , V_22 -> V_35 |
V_36 ) ;
F_10 ( V_19 , V_37 , V_38 |
V_39 |
V_40 ) ;
F_10 ( V_19 , V_41 , V_19 -> V_42 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_44 = F_13 ( V_4 ) ;
F_14 ( & V_22 -> V_45 , V_44 -> V_46 ) ;
V_22 -> V_45 . V_15 . V_47 = V_2 -> V_15 . V_47 &
V_48 ;
return F_15 ( & V_22 -> V_45 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_44 = F_13 ( V_4 ) ;
F_14 ( & V_22 -> V_45 , V_44 -> V_46 ) ;
V_22 -> V_45 . V_15 . V_47 = V_2 -> V_15 . V_47 &
V_48 ;
V_22 -> V_45 . V_49 = V_2 -> V_49 ;
V_22 -> V_45 . V_50 = V_2 -> V_50 ;
return F_17 ( & V_22 -> V_45 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_44 = F_13 ( V_4 ) ;
F_14 ( & V_22 -> V_45 , V_44 -> V_46 ) ;
V_22 -> V_45 . V_15 . V_47 = V_2 -> V_15 . V_47 &
V_48 ;
V_22 -> V_45 . V_7 = V_2 -> V_7 ;
return F_19 ( & V_22 -> V_45 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_44 = F_13 ( V_4 ) ;
F_14 ( & V_22 -> V_45 , V_44 -> V_46 ) ;
V_22 -> V_45 . V_15 . V_47 = V_2 -> V_15 . V_47 &
V_48 ;
V_22 -> V_45 . V_49 = V_2 -> V_49 ;
V_22 -> V_45 . V_50 = V_2 -> V_50 ;
V_22 -> V_45 . V_7 = V_2 -> V_7 ;
return F_21 ( & V_22 -> V_45 ) ;
}
static int F_22 ( struct V_1 * V_2 , const void * V_51 )
{
struct V_21 * V_22 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_44 = F_13 ( V_4 ) ;
F_14 ( & V_22 -> V_45 , V_44 -> V_46 ) ;
V_22 -> V_45 . V_15 . V_47 = V_2 -> V_15 . V_47 &
V_48 ;
return F_23 ( & V_22 -> V_45 , V_51 ) ;
}
static int F_24 ( struct V_1 * V_2 , void * V_52 )
{
struct V_21 * V_22 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_44 = F_13 ( V_4 ) ;
F_14 ( & V_22 -> V_45 , V_44 -> V_46 ) ;
V_22 -> V_45 . V_15 . V_47 = V_2 -> V_15 . V_47 &
V_48 ;
return F_25 ( & V_22 -> V_45 , V_52 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_43 * V_53 = F_27 ( V_2 -> V_15 . V_4 ) ;
struct V_18 * V_19 = V_53 -> V_19 ;
if ( ! V_2 -> V_49 )
return F_1 ( V_2 ) ;
else
return V_19 -> V_54 ( V_19 , & V_2 -> V_15 ) ;
}
static void F_28 ( struct V_18 * V_19 )
{
F_10 ( V_19 , V_55 , V_19 -> V_56 ) ;
F_10 ( V_19 , V_57 , ( V_19 -> V_58 + 3 ) / 4 ) ;
F_10 ( V_19 , V_24 , V_59 |
( V_59 << 16 ) ) ;
}
static int F_29 ( struct V_18 * V_19 )
{
int V_16 ;
V_16 = V_19 -> V_60 ( V_19 , V_19 -> V_61 , NULL ) ;
if ( ! V_16 )
F_28 ( V_19 ) ;
return V_16 ;
}
static int F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_6 ( V_19 -> V_20 ) ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
V_19 -> V_42 = V_2 -> V_49 ;
V_19 -> V_62 = V_2 -> V_49 ;
V_19 -> V_63 = 0 ;
V_19 -> V_64 = 4 ;
V_19 -> V_65 = NULL ;
V_19 -> V_61 = V_2 -> V_50 ;
V_19 -> V_66 = V_2 -> V_50 ;
V_19 -> V_67 = F_31 ( V_2 -> V_50 ) ;
V_22 = F_7 ( V_2 ) ;
V_22 -> V_35 = 0 ;
V_4 = F_2 ( V_2 ) ;
switch ( F_3 ( V_4 ) ) {
case V_6 :
V_22 -> V_35 = V_68 ;
break;
case V_9 :
V_22 -> V_35 = V_69 ;
break;
case V_11 :
V_22 -> V_35 = V_70 ;
break;
default:
return - V_13 ;
}
F_5 ( V_19 ) ;
return F_29 ( V_19 ) ;
}
static int F_32 ( struct V_18 * V_19 )
{
int V_16 = 0 ;
struct V_1 * V_2 = F_6 ( V_19 -> V_20 ) ;
struct V_3 * V_4 ;
V_19 -> V_71 ( V_19 ) ;
if ( V_19 -> V_62 ) {
if ( V_19 -> V_63 ) {
if ( F_33 ( V_19 -> V_61 ) ) {
F_34 ( V_19 -> V_19 , L_1 ,
V_72 , __LINE__ ) ;
V_16 = - V_73 ;
goto V_74;
}
V_19 -> V_61 = F_35 ( V_19 -> V_61 ) ;
}
V_16 = F_29 ( V_19 ) ;
} else {
while ( ! F_8 ( V_19 , V_75 ) )
F_36 ( 10 ) ;
V_4 = F_2 ( V_2 ) ;
F_37 ( V_2 -> V_7 , V_19 -> V_26 + V_27 ,
F_3 ( V_4 ) ) ;
V_19 -> V_17 ( V_19 -> V_20 , 0 ) ;
F_38 ( & V_19 -> V_76 ) ;
}
V_74:
return V_16 ;
}
static int F_39 ( struct V_77 * V_4 )
{
struct V_43 * V_53 = F_27 ( V_4 ) ;
struct V_78 * V_79 ;
struct V_80 * V_81 = F_40 ( V_4 -> V_82 ) ;
const char * V_83 = F_41 ( V_4 ) ;
V_79 = F_42 ( V_81 , struct V_78 , V_81 . V_84 ) ;
V_53 -> V_19 = V_79 -> V_19 ;
V_53 -> V_19 -> V_85 = ( void * ) F_43 ( V_86 ) ;
if ( ! V_53 -> V_19 -> V_85 ) {
F_44 ( V_53 -> V_19 -> V_19 , L_2 ) ;
return - V_73 ;
}
V_53 -> V_19 -> V_87 = F_30 ;
V_53 -> V_19 -> V_88 = F_32 ;
V_53 -> V_19 -> V_17 = F_4 ;
V_53 -> V_46 = F_45 ( V_83 , 0 ,
V_89 ) ;
if ( F_46 ( V_53 -> V_46 ) ) {
F_44 ( V_53 -> V_19 -> V_19 , L_3 ) ;
return F_47 ( V_53 -> V_46 ) ;
}
F_48 ( F_49 ( V_4 ) ,
sizeof( struct V_21 ) +
F_50 ( V_53 -> V_46 ) ) ;
return V_53 -> V_19 -> V_90 ( V_53 -> V_19 ) ;
}
static void F_51 ( struct V_77 * V_4 )
{
struct V_43 * V_53 = F_27 ( V_4 ) ;
F_52 ( ( unsigned long ) V_53 -> V_19 -> V_85 ) ;
return V_53 -> V_19 -> V_91 ( V_53 -> V_19 ) ;
}
