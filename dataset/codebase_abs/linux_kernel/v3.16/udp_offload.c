static int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 , sizeof( struct V_3 ) ) )
return - V_4 ;
if ( F_3 ( ! V_2 -> V_5 ) ) {
const struct V_6 * V_7 ;
struct V_3 * V_8 ;
V_7 = F_4 ( V_2 ) ;
V_8 = F_5 ( V_2 ) ;
V_8 -> V_9 = ~ F_6 ( V_7 -> V_10 , V_7 -> V_11 , V_2 -> V_12 ,
V_13 , 0 ) ;
V_2 -> V_14 = F_7 ( V_2 ) - V_2 -> V_15 ;
V_2 -> V_16 = F_8 ( struct V_3 , V_9 ) ;
V_2 -> V_17 = V_18 ;
}
return 0 ;
}
static struct V_1 * F_9 ( struct V_1 * V_2 ,
T_1 V_19 )
{
struct V_1 * V_20 = F_10 ( - V_4 ) ;
unsigned int V_21 ;
int V_22 ;
T_2 V_23 ;
if ( V_2 -> V_5 &&
( F_11 ( V_2 ) -> V_24 &
( V_25 | V_26 ) ) ) {
V_20 = F_12 ( V_2 , V_19 ) ;
goto V_27;
}
V_21 = F_11 ( V_2 ) -> V_28 ;
if ( F_13 ( V_2 -> V_12 <= V_21 ) )
goto V_27;
if ( F_14 ( V_2 , V_19 | V_29 ) ) {
int type = F_11 ( V_2 ) -> V_24 ;
if ( F_13 ( type & ~ ( V_30 | V_31 |
V_25 |
V_26 |
V_32 |
V_33 | V_34 |
V_35 ) ||
! ( type & ( V_30 ) ) ) )
goto V_27;
F_11 ( V_2 ) -> V_36 = F_15 ( V_2 -> V_12 , V_21 ) ;
V_20 = NULL ;
goto V_27;
}
V_22 = F_16 ( V_2 ) ;
V_23 = F_17 ( V_2 , V_22 , V_2 -> V_12 - V_22 , 0 ) ;
V_22 += V_2 -> V_16 ;
* ( V_37 * ) ( V_2 -> V_38 + V_22 ) = F_18 ( V_23 ) ;
V_2 -> V_17 = V_39 ;
V_20 = F_19 ( V_2 , V_19 ) ;
V_27:
return V_20 ;
}
int F_20 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_21 ( sizeof( * V_43 ) , V_44 ) ;
if ( ! V_43 )
return - V_45 ;
V_43 -> V_46 = V_41 ;
F_22 ( & V_47 ) ;
V_43 -> V_48 = V_49 ;
F_23 ( V_49 , V_43 ) ;
F_24 ( & V_47 ) ;
return 0 ;
}
static void F_25 ( struct V_50 * V_15 )
{
struct V_42 * V_51 = F_26 ( V_15 , struct V_42 , V_52 ) ;
F_27 ( V_51 ) ;
}
void F_28 ( struct V_40 * V_41 )
{
struct V_42 T_3 * * V_15 = & V_49 ;
struct V_42 * V_53 ;
F_22 ( & V_47 ) ;
V_53 = F_29 ( * V_15 ) ;
for (; V_53 != NULL ;
V_53 = F_29 ( * V_15 ) ) {
if ( V_53 -> V_46 == V_41 ) {
F_23 ( * V_15 ,
F_29 ( V_53 -> V_48 ) ) ;
goto V_54;
}
V_15 = & V_53 -> V_48 ;
}
F_30 ( L_1 , F_31 ( V_41 -> V_55 ) ) ;
V_54:
F_24 ( & V_47 ) ;
if ( V_53 != NULL )
F_32 ( & V_53 -> V_52 , F_25 ) ;
}
static struct V_1 * * F_33 ( struct V_1 * * V_15 , struct V_1 * V_2 )
{
struct V_42 * V_53 ;
struct V_1 * V_56 , * * V_57 = NULL ;
struct V_3 * V_8 , * V_58 ;
unsigned int V_59 , V_60 ;
int V_61 = 1 ;
if ( F_34 ( V_2 ) -> V_62 ||
( ! V_2 -> V_5 && V_2 -> V_17 != V_63 ) )
goto V_27;
F_34 ( V_2 ) -> V_62 = 1 ;
V_60 = F_35 ( V_2 ) ;
V_59 = V_60 + sizeof( * V_8 ) ;
V_8 = F_36 ( V_2 , V_60 ) ;
if ( F_37 ( V_2 , V_59 ) ) {
V_8 = F_38 ( V_2 , V_59 , V_60 ) ;
if ( F_13 ( ! V_8 ) )
goto V_27;
}
F_39 () ;
V_53 = F_40 ( V_49 ) ;
for (; V_53 != NULL ; V_53 = F_40 ( V_53 -> V_48 ) ) {
if ( V_53 -> V_46 -> V_55 == V_8 -> V_64 &&
V_53 -> V_46 -> V_65 . V_66 )
goto V_67;
}
goto V_68;
V_67:
V_61 = 0 ;
for ( V_56 = * V_15 ; V_56 ; V_56 = V_56 -> V_48 ) {
if ( ! F_34 ( V_56 ) -> V_69 )
continue;
V_58 = (struct V_3 * ) ( V_56 -> V_38 + V_60 ) ;
if ( ( * ( V_70 * ) & V_8 -> V_71 != * ( V_70 * ) & V_58 -> V_71 ) ) {
F_34 ( V_56 ) -> V_69 = 0 ;
continue;
}
}
F_41 ( V_2 , sizeof( struct V_3 ) ) ;
F_42 ( V_2 , V_8 , sizeof( struct V_3 ) ) ;
V_57 = V_53 -> V_46 -> V_65 . V_66 ( V_15 , V_2 ) ;
V_68:
F_43 () ;
V_27:
F_34 ( V_2 ) -> V_61 |= V_61 ;
return V_57 ;
}
static int F_44 ( struct V_1 * V_2 , int V_72 )
{
struct V_42 * V_53 ;
T_4 V_73 = F_45 ( V_2 -> V_12 - V_72 ) ;
struct V_3 * V_8 = (struct V_3 * ) ( V_2 -> V_38 + V_72 ) ;
int V_74 = - V_75 ;
V_8 -> V_12 = V_73 ;
F_39 () ;
V_53 = F_40 ( V_49 ) ;
for (; V_53 != NULL ; V_53 = F_40 ( V_53 -> V_48 ) ) {
if ( V_53 -> V_46 -> V_55 == V_8 -> V_64 &&
V_53 -> V_46 -> V_65 . V_76 )
break;
}
if ( V_53 != NULL )
V_74 = V_53 -> V_46 -> V_65 . V_76 ( V_2 , V_72 + sizeof( struct V_3 ) ) ;
F_43 () ;
return V_74 ;
}
int T_5 F_46 ( void )
{
return F_47 ( & V_77 , V_13 ) ;
}
