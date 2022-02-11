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
if ( ! V_2 -> V_50 )
V_3 |= V_51 ;
V_9 = F_17 ( V_2 , V_3 ) ;
V_33:
return V_9 ;
}
int F_18 ( struct V_52 * V_52 , struct V_53 * V_54 )
{
struct V_55 * V_56 = F_19 ( sizeof( * V_56 ) , V_57 ) ;
if ( ! V_56 )
return - V_58 ;
F_20 ( & V_56 -> V_52 , V_52 ) ;
V_56 -> V_59 = V_54 ;
F_21 ( & V_60 ) ;
V_56 -> V_61 = V_62 ;
F_22 ( V_62 , V_56 ) ;
F_23 ( & V_60 ) ;
return 0 ;
}
static void F_24 ( struct V_63 * V_64 )
{
struct V_55 * V_65 = F_25 ( V_64 , struct V_55 , V_66 ) ;
F_26 ( V_65 ) ;
}
void F_27 ( struct V_53 * V_54 )
{
struct V_55 T_4 * * V_64 = & V_62 ;
struct V_55 * V_67 ;
F_21 ( & V_60 ) ;
V_67 = F_28 ( * V_64 ) ;
for (; V_67 != NULL ;
V_67 = F_28 ( * V_64 ) ) {
if ( V_67 -> V_59 == V_54 ) {
F_22 ( * V_64 ,
F_28 ( V_67 -> V_61 ) ) ;
goto V_68;
}
V_64 = & V_67 -> V_61 ;
}
F_29 ( L_1 , F_30 ( V_54 -> V_69 ) ) ;
V_68:
F_23 ( & V_60 ) ;
if ( V_67 )
F_31 ( & V_67 -> V_66 , F_24 ) ;
}
struct V_1 * * F_32 ( struct V_1 * * V_64 , struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_55 * V_67 ;
struct V_1 * V_70 , * * V_71 = NULL ;
struct V_25 * V_72 ;
unsigned int V_73 = F_33 ( V_2 ) ;
int V_74 = 1 ;
if ( F_34 ( V_2 ) -> V_75 ||
( V_2 -> V_48 != V_76 &&
F_34 ( V_2 ) -> V_77 == 0 &&
! F_34 ( V_2 ) -> V_78 ) )
goto V_33;
F_34 ( V_2 ) -> V_75 = 1 ;
F_3 () ;
V_67 = F_4 ( V_62 ) ;
for (; V_67 != NULL ; V_67 = F_4 ( V_67 -> V_61 ) ) {
if ( F_35 ( F_36 ( & V_67 -> V_52 ) , F_37 ( V_2 -> V_79 ) ) &&
V_67 -> V_59 -> V_69 == V_26 -> V_80 &&
V_67 -> V_59 -> V_20 . V_81 )
goto V_82;
}
goto V_22;
V_82:
V_74 = 0 ;
for ( V_70 = * V_64 ; V_70 ; V_70 = V_70 -> V_61 ) {
if ( ! F_34 ( V_70 ) -> V_83 )
continue;
V_72 = (struct V_25 * ) ( V_70 -> V_84 + V_73 ) ;
if ( ( * ( V_85 * ) & V_26 -> V_86 != * ( V_85 * ) & V_72 -> V_86 ) ||
( ! V_26 -> V_44 ^ ! V_72 -> V_44 ) ) {
F_34 ( V_70 ) -> V_83 = 0 ;
continue;
}
}
F_38 ( V_2 , sizeof( struct V_25 ) ) ;
F_39 ( V_2 , V_26 , sizeof( struct V_25 ) ) ;
F_34 ( V_2 ) -> V_87 = V_67 -> V_59 -> V_88 ;
V_71 = V_67 -> V_59 -> V_20 . V_81 ( V_64 , V_2 ,
V_67 -> V_59 ) ;
V_22:
F_6 () ;
V_33:
F_34 ( V_2 ) -> V_74 |= V_74 ;
return V_71 ;
}
static struct V_1 * * F_40 ( struct V_1 * * V_64 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = F_41 ( V_2 ) ;
if ( F_10 ( ! V_26 ) )
goto V_74;
if ( F_34 ( V_2 ) -> V_74 )
goto V_89;
if ( F_42 ( V_2 , V_90 , V_26 -> V_44 ,
V_91 ) )
goto V_74;
else if ( V_26 -> V_44 )
F_43 ( V_2 , V_90 , V_26 -> V_44 ,
V_91 ) ;
V_89:
F_34 ( V_2 ) -> V_4 = 0 ;
return F_32 ( V_64 , V_2 , V_26 ) ;
V_74:
F_34 ( V_2 ) -> V_74 = 1 ;
return NULL ;
}
int F_44 ( struct V_1 * V_2 , int V_92 )
{
struct V_55 * V_67 ;
T_2 V_93 = F_45 ( V_2 -> V_35 - V_92 ) ;
struct V_25 * V_26 = (struct V_25 * ) ( V_2 -> V_84 + V_92 ) ;
int V_94 = - V_95 ;
V_26 -> V_35 = V_93 ;
V_2 -> V_29 = 1 ;
F_3 () ;
V_67 = F_4 ( V_62 ) ;
for (; V_67 != NULL ; V_67 = F_4 ( V_67 -> V_61 ) ) {
if ( F_35 ( F_36 ( & V_67 -> V_52 ) , F_37 ( V_2 -> V_79 ) ) &&
V_67 -> V_59 -> V_69 == V_26 -> V_80 &&
V_67 -> V_59 -> V_20 . V_96 )
break;
}
if ( V_67 ) {
F_34 ( V_2 ) -> V_87 = V_67 -> V_59 -> V_88 ;
V_94 = V_67 -> V_59 -> V_20 . V_96 ( V_2 ,
V_92 + sizeof( struct V_25 ) ,
V_67 -> V_59 ) ;
}
F_6 () ;
if ( V_2 -> V_97 )
F_8 ( V_2 ) -> V_30 |= V_39 ;
return V_94 ;
}
static int F_46 ( struct V_1 * V_2 , int V_92 )
{
const struct V_27 * V_28 = F_14 ( V_2 ) ;
struct V_25 * V_26 = (struct V_25 * ) ( V_2 -> V_84 + V_92 ) ;
if ( V_26 -> V_44 ) {
F_8 ( V_2 ) -> V_30 |= V_32 ;
V_26 -> V_44 = ~ F_16 ( V_2 -> V_35 - V_92 , V_28 -> V_45 ,
V_28 -> V_46 , 0 ) ;
} else {
F_8 ( V_2 ) -> V_30 |= V_31 ;
}
return F_44 ( V_2 , V_92 ) ;
}
int T_5 F_47 ( void )
{
return F_48 ( & V_98 , V_90 ) ;
}
