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
int F_18 ( struct V_50 * V_50 , struct V_51 * V_52 )
{
struct V_53 * V_54 = F_19 ( sizeof( * V_54 ) , V_55 ) ;
if ( ! V_54 )
return - V_56 ;
F_20 ( & V_54 -> V_50 , V_50 ) ;
V_54 -> V_57 = V_52 ;
F_21 ( & V_58 ) ;
V_54 -> V_59 = V_60 ;
F_22 ( V_60 , V_54 ) ;
F_23 ( & V_58 ) ;
return 0 ;
}
static void F_24 ( struct V_61 * V_62 )
{
struct V_53 * V_63 = F_25 ( V_62 , struct V_53 , V_64 ) ;
F_26 ( V_63 ) ;
}
void F_27 ( struct V_51 * V_52 )
{
struct V_53 T_4 * * V_62 = & V_60 ;
struct V_53 * V_65 ;
F_21 ( & V_58 ) ;
V_65 = F_28 ( * V_62 ) ;
for (; V_65 != NULL ;
V_65 = F_28 ( * V_62 ) ) {
if ( V_65 -> V_57 == V_52 ) {
F_22 ( * V_62 ,
F_28 ( V_65 -> V_59 ) ) ;
goto V_66;
}
V_62 = & V_65 -> V_59 ;
}
F_29 ( L_1 , F_30 ( V_52 -> V_67 ) ) ;
V_66:
F_23 ( & V_58 ) ;
if ( V_65 )
F_31 ( & V_65 -> V_64 , F_24 ) ;
}
struct V_1 * * F_32 ( struct V_1 * * V_62 , struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_53 * V_65 ;
struct V_1 * V_68 , * * V_69 = NULL ;
struct V_25 * V_70 ;
unsigned int V_71 = F_33 ( V_2 ) ;
int V_72 = 1 ;
if ( F_34 ( V_2 ) -> V_73 ||
( V_2 -> V_48 != V_74 &&
F_34 ( V_2 ) -> V_75 == 0 &&
! F_34 ( V_2 ) -> V_76 ) )
goto V_33;
F_34 ( V_2 ) -> V_73 = 1 ;
F_3 () ;
V_65 = F_4 ( V_60 ) ;
for (; V_65 != NULL ; V_65 = F_4 ( V_65 -> V_59 ) ) {
if ( F_35 ( F_36 ( & V_65 -> V_50 ) , F_37 ( V_2 -> V_77 ) ) &&
V_65 -> V_57 -> V_67 == V_26 -> V_78 &&
V_65 -> V_57 -> V_20 . V_79 )
goto V_80;
}
goto V_22;
V_80:
V_72 = 0 ;
for ( V_68 = * V_62 ; V_68 ; V_68 = V_68 -> V_59 ) {
if ( ! F_34 ( V_68 ) -> V_81 )
continue;
V_70 = (struct V_25 * ) ( V_68 -> V_82 + V_71 ) ;
if ( ( * ( V_83 * ) & V_26 -> V_84 != * ( V_83 * ) & V_70 -> V_84 ) ||
( ! V_26 -> V_44 ^ ! V_70 -> V_44 ) ) {
F_34 ( V_68 ) -> V_81 = 0 ;
continue;
}
}
F_38 ( V_2 , sizeof( struct V_25 ) ) ;
F_39 ( V_2 , V_26 , sizeof( struct V_25 ) ) ;
F_34 ( V_2 ) -> V_85 = V_65 -> V_57 -> V_86 ;
V_69 = V_65 -> V_57 -> V_20 . V_79 ( V_62 , V_2 ,
V_65 -> V_57 ) ;
V_22:
F_6 () ;
V_33:
F_34 ( V_2 ) -> V_72 |= V_72 ;
return V_69 ;
}
static struct V_1 * * F_40 ( struct V_1 * * V_62 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = F_41 ( V_2 ) ;
if ( F_10 ( ! V_26 ) )
goto V_72;
if ( F_34 ( V_2 ) -> V_72 )
goto V_87;
if ( F_42 ( V_2 , V_88 , V_26 -> V_44 ,
V_89 ) )
goto V_72;
else if ( V_26 -> V_44 )
F_43 ( V_2 , V_88 , V_26 -> V_44 ,
V_89 ) ;
V_87:
F_34 ( V_2 ) -> V_4 = 0 ;
return F_32 ( V_62 , V_2 , V_26 ) ;
V_72:
F_34 ( V_2 ) -> V_72 = 1 ;
return NULL ;
}
int F_44 ( struct V_1 * V_2 , int V_90 )
{
struct V_53 * V_65 ;
T_2 V_91 = F_45 ( V_2 -> V_35 - V_90 ) ;
struct V_25 * V_26 = (struct V_25 * ) ( V_2 -> V_82 + V_90 ) ;
int V_92 = - V_93 ;
V_26 -> V_35 = V_91 ;
F_3 () ;
V_65 = F_4 ( V_60 ) ;
for (; V_65 != NULL ; V_65 = F_4 ( V_65 -> V_59 ) ) {
if ( F_35 ( F_36 ( & V_65 -> V_50 ) , F_37 ( V_2 -> V_77 ) ) &&
V_65 -> V_57 -> V_67 == V_26 -> V_78 &&
V_65 -> V_57 -> V_20 . V_94 )
break;
}
if ( V_65 ) {
F_34 ( V_2 ) -> V_85 = V_65 -> V_57 -> V_86 ;
V_92 = V_65 -> V_57 -> V_20 . V_94 ( V_2 ,
V_90 + sizeof( struct V_25 ) ,
V_65 -> V_57 ) ;
}
F_6 () ;
if ( V_2 -> V_95 )
F_8 ( V_2 ) -> V_30 |= V_39 ;
V_2 -> V_29 = 1 ;
F_46 ( V_2 , V_90 + sizeof( struct V_25 ) ) ;
return V_92 ;
}
static int F_47 ( struct V_1 * V_2 , int V_90 )
{
const struct V_27 * V_28 = F_14 ( V_2 ) ;
struct V_25 * V_26 = (struct V_25 * ) ( V_2 -> V_82 + V_90 ) ;
if ( V_26 -> V_44 ) {
F_8 ( V_2 ) -> V_30 |= V_32 ;
V_26 -> V_44 = ~ F_16 ( V_2 -> V_35 - V_90 , V_28 -> V_45 ,
V_28 -> V_46 , 0 ) ;
} else {
F_8 ( V_2 ) -> V_30 |= V_31 ;
}
return F_44 ( V_2 , V_90 ) ;
}
int T_5 F_48 ( void )
{
return F_49 ( & V_96 , V_88 ) ;
}
