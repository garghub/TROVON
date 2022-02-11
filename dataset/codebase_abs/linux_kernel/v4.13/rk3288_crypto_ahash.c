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
if ( V_15 -> V_17 -> V_18 . V_19 )
V_15 -> V_17 -> V_18 . V_19 ( & V_15 -> V_17 -> V_18 , V_16 ) ;
}
static void F_5 ( struct V_14 * V_15 )
{
int V_20 = 0 ;
V_20 = F_6 ( V_15 , V_21 ) |
V_22 | F_7 ( 0xffff , 16 ) ;
F_8 ( V_15 , V_21 , V_20 ) ;
V_20 = F_6 ( V_15 , V_21 ) ;
V_20 &= ( ~ V_22 ) ;
V_20 |= F_7 ( 0xffff , 16 ) ;
F_8 ( V_15 , V_21 , V_20 ) ;
F_9 ( V_15 -> V_23 + V_24 , 0 , 32 ) ;
F_8 ( V_15 , V_25 , V_26 |
V_27 ) ;
F_8 ( V_15 , V_28 , V_29 |
V_30 ) ;
F_8 ( V_15 , V_31 , V_15 -> V_32 |
V_33 ) ;
F_8 ( V_15 , V_34 , V_35 |
V_36 |
V_37 ) ;
F_8 ( V_15 , V_38 , V_15 -> V_39 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_11 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 = F_12 ( V_4 ) ;
F_13 ( & V_41 -> V_44 , V_43 -> V_45 ) ;
V_41 -> V_44 . V_18 . V_46 = V_2 -> V_18 . V_46 &
V_47 ;
return F_14 ( & V_41 -> V_44 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_11 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 = F_12 ( V_4 ) ;
F_13 ( & V_41 -> V_44 , V_43 -> V_45 ) ;
V_41 -> V_44 . V_18 . V_46 = V_2 -> V_18 . V_46 &
V_47 ;
V_41 -> V_44 . V_48 = V_2 -> V_48 ;
V_41 -> V_44 . V_49 = V_2 -> V_49 ;
return F_16 ( & V_41 -> V_44 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_11 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 = F_12 ( V_4 ) ;
F_13 ( & V_41 -> V_44 , V_43 -> V_45 ) ;
V_41 -> V_44 . V_18 . V_46 = V_2 -> V_18 . V_46 &
V_47 ;
V_41 -> V_44 . V_7 = V_2 -> V_7 ;
return F_18 ( & V_41 -> V_44 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_11 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 = F_12 ( V_4 ) ;
F_13 ( & V_41 -> V_44 , V_43 -> V_45 ) ;
V_41 -> V_44 . V_18 . V_46 = V_2 -> V_18 . V_46 &
V_47 ;
V_41 -> V_44 . V_48 = V_2 -> V_48 ;
V_41 -> V_44 . V_49 = V_2 -> V_49 ;
V_41 -> V_44 . V_7 = V_2 -> V_7 ;
return F_20 ( & V_41 -> V_44 ) ;
}
static int F_21 ( struct V_1 * V_2 , const void * V_50 )
{
struct V_40 * V_41 = F_11 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 = F_12 ( V_4 ) ;
F_13 ( & V_41 -> V_44 , V_43 -> V_45 ) ;
V_41 -> V_44 . V_18 . V_46 = V_2 -> V_18 . V_46 &
V_47 ;
return F_22 ( & V_41 -> V_44 , V_50 ) ;
}
static int F_23 ( struct V_1 * V_2 , void * V_51 )
{
struct V_40 * V_41 = F_11 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 = F_12 ( V_4 ) ;
F_13 ( & V_41 -> V_44 , V_43 -> V_45 ) ;
V_41 -> V_44 . V_18 . V_46 = V_2 -> V_18 . V_46 &
V_47 ;
return F_24 ( & V_41 -> V_44 , V_51 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_52 = F_26 ( V_2 -> V_18 . V_4 ) ;
struct V_14 * V_15 = NULL ;
unsigned long V_46 ;
int V_53 ;
if ( ! V_2 -> V_48 )
return F_1 ( V_2 ) ;
V_15 = V_52 -> V_15 ;
V_15 -> V_39 = V_2 -> V_48 ;
V_15 -> V_54 = V_2 -> V_48 ;
V_15 -> V_55 = 0 ;
V_15 -> V_32 = 0 ;
V_15 -> V_56 = 4 ;
V_15 -> V_57 = NULL ;
V_15 -> V_58 = V_2 -> V_49 ;
V_15 -> V_59 = V_2 -> V_49 ;
V_15 -> V_60 = F_27 ( V_2 -> V_49 ) ;
switch ( F_3 ( V_4 ) ) {
case V_6 :
V_15 -> V_32 = V_61 ;
break;
case V_9 :
V_15 -> V_32 = V_62 ;
break;
case V_11 :
V_15 -> V_32 = V_63 ;
break;
default:
return - V_13 ;
}
F_5 ( V_15 ) ;
F_28 ( & V_15 -> V_64 , V_46 ) ;
V_53 = F_29 ( & V_15 -> V_65 , & V_2 -> V_18 ) ;
F_30 ( & V_15 -> V_64 , V_46 ) ;
F_31 ( & V_15 -> V_66 ) ;
while ( ! F_6 ( V_15 , V_67 ) )
F_32 ( 10 , 50 ) ;
F_33 ( V_2 -> V_7 , V_15 -> V_23 + V_24 ,
F_3 ( V_4 ) ) ;
return 0 ;
}
static void F_34 ( struct V_14 * V_15 )
{
F_8 ( V_15 , V_68 , V_15 -> V_69 ) ;
F_8 ( V_15 , V_70 , ( V_15 -> V_71 + 3 ) / 4 ) ;
F_8 ( V_15 , V_21 , V_72 |
( V_72 << 16 ) ) ;
}
static int F_35 ( struct V_14 * V_15 )
{
int V_16 ;
V_16 = V_15 -> V_73 ( V_15 , V_15 -> V_58 , NULL ) ;
if ( ! V_16 )
F_34 ( V_15 ) ;
return V_16 ;
}
static int F_36 ( struct V_14 * V_15 )
{
return F_35 ( V_15 ) ;
}
static int F_37 ( struct V_14 * V_15 )
{
int V_16 = 0 ;
V_15 -> V_74 ( V_15 ) ;
if ( V_15 -> V_54 ) {
if ( V_15 -> V_55 ) {
if ( F_38 ( V_15 -> V_58 ) ) {
F_39 ( V_15 -> V_15 , L_1 ,
V_75 , __LINE__ ) ;
V_16 = - V_76 ;
goto V_77;
}
V_15 -> V_58 = F_40 ( V_15 -> V_58 ) ;
}
V_16 = F_35 ( V_15 ) ;
} else {
V_15 -> V_19 ( V_15 , 0 ) ;
}
V_77:
return V_16 ;
}
static int F_41 ( struct V_78 * V_4 )
{
struct V_42 * V_52 = F_26 ( V_4 ) ;
struct V_79 * V_80 ;
struct V_81 * V_82 = F_42 ( V_4 -> V_83 ) ;
const char * V_84 = F_43 ( V_4 ) ;
V_80 = F_44 ( V_82 , struct V_79 , V_82 . V_85 ) ;
V_52 -> V_15 = V_80 -> V_15 ;
V_52 -> V_15 -> V_86 = ( void * ) F_45 ( V_87 ) ;
if ( ! V_52 -> V_15 -> V_86 ) {
F_46 ( V_52 -> V_15 -> V_15 , L_2 ) ;
return - V_76 ;
}
V_52 -> V_15 -> V_88 = F_36 ;
V_52 -> V_15 -> V_89 = F_37 ;
V_52 -> V_15 -> V_19 = F_4 ;
V_52 -> V_45 = F_47 ( V_84 , 0 ,
V_90 ) ;
if ( F_48 ( V_52 -> V_45 ) ) {
F_46 ( V_52 -> V_15 -> V_15 , L_3 ) ;
return F_49 ( V_52 -> V_45 ) ;
}
F_50 ( F_51 ( V_4 ) ,
sizeof( struct V_40 ) +
F_52 ( V_52 -> V_45 ) ) ;
return V_52 -> V_15 -> V_91 ( V_52 -> V_15 ) ;
}
static void F_53 ( struct V_78 * V_4 )
{
struct V_42 * V_52 = F_26 ( V_4 ) ;
F_54 ( ( unsigned long ) V_52 -> V_15 -> V_86 ) ;
return V_52 -> V_15 -> V_92 ( V_52 -> V_15 ) ;
}
