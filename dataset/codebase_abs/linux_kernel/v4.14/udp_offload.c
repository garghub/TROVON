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
if ( V_2 -> V_23 &&
( F_8 ( V_2 ) -> V_24 &
( V_25 | V_26 ) ) )
V_9 = F_1 ( V_2 , V_3 , false ) ;
return V_9 ;
}
struct V_1 * * F_9 ( struct V_1 * * V_27 , struct V_1 * V_2 ,
struct V_28 * V_29 , T_3 V_30 )
{
struct V_1 * V_31 , * * V_32 = NULL ;
struct V_28 * V_33 ;
unsigned int V_34 = F_10 ( V_2 ) ;
int V_35 = 1 ;
struct V_36 * V_37 ;
if ( F_11 ( V_2 ) -> V_38 ||
( V_2 -> V_39 != V_40 &&
F_11 ( V_2 ) -> V_41 == 0 &&
! F_11 ( V_2 ) -> V_42 ) )
goto V_43;
F_11 ( V_2 ) -> V_38 = 1 ;
F_3 () ;
V_37 = (* V_30)( V_2 , V_29 -> V_44 , V_29 -> V_45 ) ;
if ( V_37 && F_12 ( V_37 ) -> V_46 )
goto V_47;
goto V_22;
V_47:
V_35 = 0 ;
for ( V_31 = * V_27 ; V_31 ; V_31 = V_31 -> V_48 ) {
if ( ! F_11 ( V_31 ) -> V_49 )
continue;
V_33 = (struct V_28 * ) ( V_31 -> V_50 + V_34 ) ;
if ( ( * ( V_51 * ) & V_29 -> V_44 != * ( V_51 * ) & V_33 -> V_44 ) ||
( ! V_29 -> V_52 ^ ! V_33 -> V_52 ) ) {
F_11 ( V_31 ) -> V_49 = 0 ;
continue;
}
}
F_13 ( V_2 , sizeof( struct V_28 ) ) ;
F_14 ( V_2 , V_29 , sizeof( struct V_28 ) ) ;
V_32 = F_15 ( F_12 ( V_37 ) -> V_46 , V_37 , V_27 , V_2 ) ;
V_22:
F_6 () ;
V_43:
F_11 ( V_2 ) -> V_35 |= V_35 ;
return V_32 ;
}
static struct V_1 * * F_16 ( struct V_1 * * V_27 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = F_17 ( V_2 ) ;
if ( F_18 ( ! V_29 ) )
goto V_35;
if ( F_11 ( V_2 ) -> V_35 )
goto V_53;
if ( F_19 ( V_2 , V_54 , V_29 -> V_52 ,
V_55 ) )
goto V_35;
else if ( V_29 -> V_52 )
F_20 ( V_2 , V_54 , V_29 -> V_52 ,
V_55 ) ;
V_53:
F_11 ( V_2 ) -> V_4 = 0 ;
return F_9 ( V_27 , V_2 , V_29 , V_56 ) ;
V_35:
F_11 ( V_2 ) -> V_35 = 1 ;
return NULL ;
}
int F_21 ( struct V_1 * V_2 , int V_57 ,
T_3 V_30 )
{
T_2 V_58 = F_22 ( V_2 -> V_59 - V_57 ) ;
struct V_28 * V_29 = (struct V_28 * ) ( V_2 -> V_50 + V_57 ) ;
int V_60 = - V_61 ;
struct V_36 * V_37 ;
V_29 -> V_59 = V_58 ;
V_2 -> V_23 = 1 ;
F_3 () ;
V_37 = (* V_30)( V_2 , V_29 -> V_44 , V_29 -> V_45 ) ;
if ( V_37 && F_12 ( V_37 ) -> V_62 )
V_60 = F_12 ( V_37 ) -> V_62 ( V_37 , V_2 ,
V_57 + sizeof( struct V_28 ) ) ;
F_6 () ;
if ( V_2 -> V_63 )
F_8 ( V_2 ) -> V_24 |= V_64 ;
return V_60 ;
}
static int F_23 ( struct V_1 * V_2 , int V_57 )
{
const struct V_65 * V_66 = F_24 ( V_2 ) ;
struct V_28 * V_29 = (struct V_28 * ) ( V_2 -> V_50 + V_57 ) ;
if ( V_29 -> V_52 ) {
F_8 ( V_2 ) -> V_24 |= V_26 ;
V_29 -> V_52 = ~ F_25 ( V_2 -> V_59 - V_57 , V_66 -> V_67 ,
V_66 -> V_68 , 0 ) ;
} else {
F_8 ( V_2 ) -> V_24 |= V_25 ;
}
return F_21 ( V_2 , V_57 , V_56 ) ;
}
int T_4 F_26 ( void )
{
return F_27 ( & V_69 , V_54 ) ;
}
