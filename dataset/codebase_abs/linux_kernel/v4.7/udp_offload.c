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
F_8 ( V_2 ) -> V_37 = F_12 ( V_2 -> V_35 , V_23 ) ;
V_9 = NULL ;
goto V_33;
}
V_26 = F_13 ( V_2 ) ;
V_28 = F_14 ( V_2 ) ;
V_26 -> V_38 = 0 ;
V_24 = F_15 ( V_2 , 0 , V_2 -> V_35 , 0 ) ;
V_26 -> V_38 = F_16 ( V_2 -> V_35 , V_28 -> V_39 , V_28 -> V_40 , V_24 ) ;
if ( V_26 -> V_38 == 0 )
V_26 -> V_38 = V_41 ;
V_2 -> V_42 = V_43 ;
if ( ! V_2 -> V_44 )
V_3 |= V_45 ;
V_9 = F_17 ( V_2 , V_3 ) ;
V_33:
return V_9 ;
}
struct V_1 * * F_18 ( struct V_1 * * V_46 , struct V_1 * V_2 ,
struct V_25 * V_26 , T_4 V_47 )
{
struct V_1 * V_48 , * * V_49 = NULL ;
struct V_25 * V_50 ;
unsigned int V_51 = F_19 ( V_2 ) ;
int V_52 = 1 ;
struct V_53 * V_54 ;
if ( F_20 ( V_2 ) -> V_55 ||
( V_2 -> V_42 != V_56 &&
F_20 ( V_2 ) -> V_57 == 0 &&
! F_20 ( V_2 ) -> V_58 ) )
goto V_33;
F_20 ( V_2 ) -> V_55 = 1 ;
F_3 () ;
V_54 = (* V_47)( V_2 , V_26 -> V_59 , V_26 -> V_60 ) ;
if ( V_54 && F_21 ( V_54 ) -> V_61 )
goto V_62;
goto V_22;
V_62:
V_52 = 0 ;
for ( V_48 = * V_46 ; V_48 ; V_48 = V_48 -> V_63 ) {
if ( ! F_20 ( V_48 ) -> V_64 )
continue;
V_50 = (struct V_25 * ) ( V_48 -> V_65 + V_51 ) ;
if ( ( * ( V_66 * ) & V_26 -> V_59 != * ( V_66 * ) & V_50 -> V_59 ) ||
( ! V_26 -> V_38 ^ ! V_50 -> V_38 ) ) {
F_20 ( V_48 ) -> V_64 = 0 ;
continue;
}
}
F_22 ( V_2 , sizeof( struct V_25 ) ) ;
F_23 ( V_2 , V_26 , sizeof( struct V_25 ) ) ;
V_49 = F_21 ( V_54 ) -> V_61 ( V_54 , V_46 , V_2 ) ;
V_22:
F_6 () ;
V_33:
F_20 ( V_2 ) -> V_52 |= V_52 ;
return V_49 ;
}
static struct V_1 * * F_24 ( struct V_1 * * V_46 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = F_25 ( V_2 ) ;
if ( F_10 ( ! V_26 ) )
goto V_52;
if ( F_20 ( V_2 ) -> V_52 )
goto V_67;
if ( F_26 ( V_2 , V_68 , V_26 -> V_38 ,
V_69 ) )
goto V_52;
else if ( V_26 -> V_38 )
F_27 ( V_2 , V_68 , V_26 -> V_38 ,
V_69 ) ;
V_67:
F_20 ( V_2 ) -> V_4 = 0 ;
return F_18 ( V_46 , V_2 , V_26 , V_70 ) ;
V_52:
F_20 ( V_2 ) -> V_52 = 1 ;
return NULL ;
}
int F_28 ( struct V_1 * V_2 , int V_71 ,
T_4 V_47 )
{
T_2 V_72 = F_29 ( V_2 -> V_35 - V_71 ) ;
struct V_25 * V_26 = (struct V_25 * ) ( V_2 -> V_65 + V_71 ) ;
int V_73 = - V_74 ;
struct V_53 * V_54 ;
V_26 -> V_35 = V_72 ;
V_2 -> V_29 = 1 ;
F_3 () ;
V_54 = (* V_47)( V_2 , V_26 -> V_59 , V_26 -> V_60 ) ;
if ( V_54 && F_21 ( V_54 ) -> V_75 )
V_73 = F_21 ( V_54 ) -> V_75 ( V_54 , V_2 ,
V_71 + sizeof( struct V_25 ) ) ;
F_6 () ;
if ( V_2 -> V_76 )
F_8 ( V_2 ) -> V_30 |= V_77 ;
return V_73 ;
}
static int F_30 ( struct V_1 * V_2 , int V_71 )
{
const struct V_27 * V_28 = F_14 ( V_2 ) ;
struct V_25 * V_26 = (struct V_25 * ) ( V_2 -> V_65 + V_71 ) ;
if ( V_26 -> V_38 ) {
F_8 ( V_2 ) -> V_30 |= V_32 ;
V_26 -> V_38 = ~ F_16 ( V_2 -> V_35 - V_71 , V_28 -> V_39 ,
V_28 -> V_40 , 0 ) ;
} else {
F_8 ( V_2 ) -> V_30 |= V_31 ;
}
return F_28 ( V_2 , V_71 , V_70 ) ;
}
int T_5 F_31 ( void )
{
return F_32 ( & V_78 , V_68 ) ;
}
