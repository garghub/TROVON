struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
bool V_4 )
{
T_2 V_5 = V_2 -> V_5 ;
const struct V_6 * * V_7 ;
const struct V_6 * V_8 ;
struct V_1 * V_9 = F_2 ( - V_10 ) ;
struct V_1 * ( * V_11 ) ( struct V_1 * V_2 ,
T_1 V_3 ) ;
F_3 () ;
switch ( V_2 -> V_12 ) {
case V_13 :
V_5 = V_2 -> V_14 ;
V_11 = V_15 ;
break;
case V_16 :
V_7 = V_4 ? V_17 : V_18 ;
V_8 = F_4 ( V_7 [ V_2 -> V_19 ] ) ;
if ( ! V_8 || ! V_8 -> V_20 . V_21 )
goto V_22;
V_11 = V_8 -> V_20 . V_21 ;
break;
default:
goto V_22;
}
V_9 = F_5 ( V_2 , V_3 , V_11 ,
V_5 , V_4 ) ;
V_22:
F_6 () ;
return V_9 ;
}
static struct V_1 * F_7 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_1 * V_9 = F_2 ( - V_10 ) ;
unsigned int V_23 ;
T_3 V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
if ( V_2 -> V_29 &&
( F_8 ( V_2 ) -> V_30 &
( V_31 | V_32 ) ) ) {
V_9 = F_1 ( V_2 , V_3 , false ) ;
goto V_33;
}
if ( ! F_9 ( V_2 , sizeof( struct V_25 ) ) )
goto V_33;
V_23 = F_8 ( V_2 ) -> V_34 ;
if ( F_10 ( V_2 -> V_35 <= V_23 ) )
goto V_33;
if ( F_11 ( V_2 , V_3 | V_36 ) ) {
int type = F_8 ( V_2 ) -> V_30 ;
if ( F_10 ( type & ~ ( V_37 | V_38 |
V_31 |
V_32 |
V_39 |
V_40 |
V_41 | V_42 ) ||
! ( type & ( V_37 ) ) ) )
goto V_33;
F_8 ( V_2 ) -> V_43 = F_12 ( V_2 -> V_35 , V_23 ) ;
V_9 = NULL ;
goto V_33;
}
V_26 = F_13 ( V_2 ) ;
V_28 = F_14 ( V_2 ) ;
V_26 -> V_44 = 0 ;
V_24 = F_15 ( V_2 , 0 , V_2 -> V_35 , 0 ) ;
V_26 -> V_44 = F_16 ( V_2 -> V_35 , V_28 -> V_45 , V_28 -> V_46 , V_24 ) ;
if ( V_26 -> V_44 == 0 )
V_26 -> V_44 = V_47 ;
V_2 -> V_48 = V_49 ;
V_9 = F_17 ( V_2 , V_3 ) ;
V_33:
return V_9 ;
}
int F_18 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_19 ( sizeof( * V_53 ) , V_54 ) ;
if ( ! V_53 )
return - V_55 ;
V_53 -> V_56 = V_51 ;
F_20 ( & V_57 ) ;
V_53 -> V_58 = V_59 ;
F_21 ( V_59 , V_53 ) ;
F_22 ( & V_57 ) ;
return 0 ;
}
static void F_23 ( struct V_60 * V_61 )
{
struct V_52 * V_62 = F_24 ( V_61 , struct V_52 , V_63 ) ;
F_25 ( V_62 ) ;
}
void F_26 ( struct V_50 * V_51 )
{
struct V_52 T_4 * * V_61 = & V_59 ;
struct V_52 * V_64 ;
F_20 ( & V_57 ) ;
V_64 = F_27 ( * V_61 ) ;
for (; V_64 != NULL ;
V_64 = F_27 ( * V_61 ) ) {
if ( V_64 -> V_56 == V_51 ) {
F_21 ( * V_61 ,
F_27 ( V_64 -> V_58 ) ) ;
goto V_65;
}
V_61 = & V_64 -> V_58 ;
}
F_28 ( L_1 , F_29 ( V_51 -> V_66 ) ) ;
V_65:
F_22 ( & V_57 ) ;
if ( V_64 )
F_30 ( & V_64 -> V_63 , F_23 ) ;
}
struct V_1 * * F_31 ( struct V_1 * * V_61 , struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_52 * V_64 ;
struct V_1 * V_67 , * * V_68 = NULL ;
struct V_25 * V_69 ;
unsigned int V_70 = F_32 ( V_2 ) ;
int V_71 = 1 ;
if ( F_33 ( V_2 ) -> V_72 ||
( V_2 -> V_48 != V_73 &&
F_33 ( V_2 ) -> V_74 == 0 &&
! F_33 ( V_2 ) -> V_75 ) )
goto V_33;
F_33 ( V_2 ) -> V_72 = 1 ;
F_3 () ;
V_64 = F_4 ( V_59 ) ;
for (; V_64 != NULL ; V_64 = F_4 ( V_64 -> V_58 ) ) {
if ( V_64 -> V_56 -> V_66 == V_26 -> V_76 &&
V_64 -> V_56 -> V_20 . V_77 )
goto V_78;
}
goto V_22;
V_78:
V_71 = 0 ;
for ( V_67 = * V_61 ; V_67 ; V_67 = V_67 -> V_58 ) {
if ( ! F_33 ( V_67 ) -> V_79 )
continue;
V_69 = (struct V_25 * ) ( V_67 -> V_80 + V_70 ) ;
if ( ( * ( V_81 * ) & V_26 -> V_82 != * ( V_81 * ) & V_69 -> V_82 ) ||
( ! V_26 -> V_44 ^ ! V_69 -> V_44 ) ) {
F_33 ( V_67 ) -> V_79 = 0 ;
continue;
}
}
F_34 ( V_2 , sizeof( struct V_25 ) ) ;
F_35 ( V_2 , V_26 , sizeof( struct V_25 ) ) ;
F_33 ( V_2 ) -> V_83 = V_64 -> V_56 -> V_84 ;
V_68 = V_64 -> V_56 -> V_20 . V_77 ( V_61 , V_2 ,
V_64 -> V_56 ) ;
V_22:
F_6 () ;
V_33:
F_33 ( V_2 ) -> V_71 |= V_71 ;
return V_68 ;
}
static struct V_1 * * F_36 ( struct V_1 * * V_61 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = F_37 ( V_2 ) ;
if ( F_10 ( ! V_26 ) )
goto V_71;
if ( F_33 ( V_2 ) -> V_71 )
goto V_85;
if ( F_38 ( V_2 , V_86 , V_26 -> V_44 ,
V_87 ) )
goto V_71;
else if ( V_26 -> V_44 )
F_39 ( V_2 , V_86 , V_26 -> V_44 ,
V_87 ) ;
V_85:
F_33 ( V_2 ) -> V_4 = 0 ;
return F_31 ( V_61 , V_2 , V_26 ) ;
V_71:
F_33 ( V_2 ) -> V_71 = 1 ;
return NULL ;
}
int F_40 ( struct V_1 * V_2 , int V_88 )
{
struct V_52 * V_64 ;
T_2 V_89 = F_41 ( V_2 -> V_35 - V_88 ) ;
struct V_25 * V_26 = (struct V_25 * ) ( V_2 -> V_80 + V_88 ) ;
int V_90 = - V_91 ;
V_26 -> V_35 = V_89 ;
F_3 () ;
V_64 = F_4 ( V_59 ) ;
for (; V_64 != NULL ; V_64 = F_4 ( V_64 -> V_58 ) ) {
if ( V_64 -> V_56 -> V_66 == V_26 -> V_76 &&
V_64 -> V_56 -> V_20 . V_92 )
break;
}
if ( V_64 ) {
F_33 ( V_2 ) -> V_83 = V_64 -> V_56 -> V_84 ;
V_90 = V_64 -> V_56 -> V_20 . V_92 ( V_2 ,
V_88 + sizeof( struct V_25 ) ,
V_64 -> V_56 ) ;
}
F_6 () ;
if ( V_2 -> V_93 )
F_8 ( V_2 ) -> V_30 |= V_39 ;
V_2 -> V_29 = 1 ;
F_42 ( V_2 , V_88 + sizeof( struct V_25 ) ) ;
return V_90 ;
}
static int F_43 ( struct V_1 * V_2 , int V_88 )
{
const struct V_27 * V_28 = F_14 ( V_2 ) ;
struct V_25 * V_26 = (struct V_25 * ) ( V_2 -> V_80 + V_88 ) ;
if ( V_26 -> V_44 ) {
F_8 ( V_2 ) -> V_30 |= V_32 ;
V_26 -> V_44 = ~ F_16 ( V_2 -> V_35 - V_88 , V_28 -> V_45 ,
V_28 -> V_46 , 0 ) ;
} else {
F_8 ( V_2 ) -> V_30 |= V_31 ;
}
return F_40 ( V_2 , V_88 ) ;
}
int T_5 F_44 ( void )
{
return F_45 ( & V_94 , V_86 ) ;
}
