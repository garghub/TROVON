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
F_11 ( V_2 ) -> V_24 & V_25 ) {
V_20 = F_12 ( V_2 , V_19 ) ;
goto V_26;
}
V_21 = F_11 ( V_2 ) -> V_27 ;
if ( F_13 ( V_2 -> V_12 <= V_21 ) )
goto V_26;
if ( F_14 ( V_2 , V_19 | V_28 ) ) {
int type = F_11 ( V_2 ) -> V_24 ;
if ( F_13 ( type & ~ ( V_29 | V_30 |
V_25 |
V_31 |
V_32 | V_33 ) ||
! ( type & ( V_29 ) ) ) )
goto V_26;
F_11 ( V_2 ) -> V_34 = F_15 ( V_2 -> V_12 , V_21 ) ;
V_20 = NULL ;
goto V_26;
}
V_22 = F_16 ( V_2 ) ;
V_23 = F_17 ( V_2 , V_22 , V_2 -> V_12 - V_22 , 0 ) ;
V_22 += V_2 -> V_16 ;
* ( V_35 * ) ( V_2 -> V_36 + V_22 ) = F_18 ( V_23 ) ;
V_2 -> V_17 = V_37 ;
V_20 = F_19 ( V_2 , V_19 ) ;
V_26:
return V_20 ;
}
int F_20 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_21 ( sizeof( * V_41 ) , V_42 ) ;
if ( ! V_41 )
return - V_43 ;
V_41 -> V_44 = V_39 ;
F_22 ( & V_45 ) ;
V_41 -> V_46 = V_47 ;
F_23 ( V_47 , V_41 ) ;
F_24 ( & V_45 ) ;
return 0 ;
}
static void F_25 ( struct V_48 * V_15 )
{
struct V_40 * V_49 = F_26 ( V_15 , struct V_40 , V_50 ) ;
F_27 ( V_49 ) ;
}
void F_28 ( struct V_38 * V_39 )
{
struct V_40 T_3 * * V_15 = & V_47 ;
struct V_40 * V_51 ;
F_22 ( & V_45 ) ;
V_51 = F_29 ( * V_15 ) ;
for (; V_51 != NULL ;
V_51 = F_29 ( * V_15 ) ) {
if ( V_51 -> V_44 == V_39 ) {
F_23 ( * V_15 ,
F_29 ( V_51 -> V_46 ) ) ;
goto V_52;
}
V_15 = & V_51 -> V_46 ;
}
F_30 ( L_1 , F_31 ( V_39 -> V_53 ) ) ;
V_52:
F_24 ( & V_45 ) ;
if ( V_51 != NULL )
F_32 ( & V_51 -> V_50 , F_25 ) ;
}
static struct V_1 * * F_33 ( struct V_1 * * V_15 , struct V_1 * V_2 )
{
struct V_40 * V_51 ;
struct V_1 * V_54 , * * V_55 = NULL ;
struct V_3 * V_8 , * V_56 ;
unsigned int V_57 , V_58 ;
int V_59 = 1 ;
if ( F_34 ( V_2 ) -> V_60 ||
( ! V_2 -> V_5 && V_2 -> V_17 != V_61 ) )
goto V_26;
F_34 ( V_2 ) -> V_60 = 1 ;
V_58 = F_35 ( V_2 ) ;
V_57 = V_58 + sizeof( * V_8 ) ;
V_8 = F_36 ( V_2 , V_58 ) ;
if ( F_37 ( V_2 , V_57 ) ) {
V_8 = F_38 ( V_2 , V_57 , V_58 ) ;
if ( F_13 ( ! V_8 ) )
goto V_26;
}
F_39 () ;
V_51 = F_40 ( V_47 ) ;
for (; V_51 != NULL ; V_51 = F_40 ( V_51 -> V_46 ) ) {
if ( V_51 -> V_44 -> V_53 == V_8 -> V_62 &&
V_51 -> V_44 -> V_63 . V_64 )
goto V_65;
}
goto V_66;
V_65:
V_59 = 0 ;
for ( V_54 = * V_15 ; V_54 ; V_54 = V_54 -> V_46 ) {
if ( ! F_34 ( V_54 ) -> V_67 )
continue;
V_56 = (struct V_3 * ) ( V_54 -> V_36 + V_58 ) ;
if ( ( * ( V_68 * ) & V_8 -> V_69 != * ( V_68 * ) & V_56 -> V_69 ) ) {
F_34 ( V_54 ) -> V_67 = 0 ;
continue;
}
}
F_41 ( V_2 , sizeof( struct V_3 ) ) ;
V_55 = V_51 -> V_44 -> V_63 . V_64 ( V_15 , V_2 ) ;
V_66:
F_42 () ;
V_26:
F_34 ( V_2 ) -> V_59 |= V_59 ;
return V_55 ;
}
static int F_43 ( struct V_1 * V_2 , int V_70 )
{
struct V_40 * V_51 ;
T_4 V_71 = F_44 ( V_2 -> V_12 - V_70 ) ;
struct V_3 * V_8 = (struct V_3 * ) ( V_2 -> V_36 + V_70 ) ;
int V_72 = - V_73 ;
V_8 -> V_12 = V_71 ;
F_39 () ;
V_51 = F_40 ( V_47 ) ;
for (; V_51 != NULL ; V_51 = F_40 ( V_51 -> V_46 ) ) {
if ( V_51 -> V_44 -> V_53 == V_8 -> V_62 &&
V_51 -> V_44 -> V_63 . V_74 )
break;
}
if ( V_51 != NULL )
V_72 = V_51 -> V_44 -> V_63 . V_74 ( V_2 , V_70 + sizeof( struct V_3 ) ) ;
F_42 () ;
return V_72 ;
}
int T_5 F_45 ( void )
{
return F_46 ( & V_75 , V_13 ) ;
}
