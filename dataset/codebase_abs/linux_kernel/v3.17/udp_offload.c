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
struct V_1 * F_9 ( struct V_1 * V_2 ,
T_1 V_19 )
{
struct V_1 * V_20 = F_10 ( - V_4 ) ;
T_2 V_21 = V_2 -> V_22 ;
int V_23 = V_2 -> V_23 ;
int V_24 = F_11 ( V_2 ) - F_7 ( V_2 ) ;
T_3 V_25 = V_2 -> V_25 ;
T_1 V_26 ;
int V_27 , V_28 ;
unsigned int V_29 ;
bool V_30 ;
V_29 = ( T_2 ) ~ V_2 -> V_12 ;
if ( F_12 ( ! F_2 ( V_2 , V_24 ) ) )
goto V_31;
V_2 -> V_5 = 0 ;
F_13 ( V_2 , V_24 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 , F_16 ( V_2 ) ) ;
V_2 -> V_23 = F_16 ( V_2 ) ;
V_2 -> V_25 = F_17 ( V_32 ) ;
V_30 = ! ! ( F_18 ( V_2 ) -> V_33 & V_34 ) ;
if ( V_30 )
V_2 -> V_35 = 1 ;
V_26 = V_2 -> V_36 -> V_37 & F_19 ( V_2 ) ;
V_20 = F_20 ( V_2 , V_26 ) ;
if ( F_21 ( V_20 ) ) {
F_22 ( V_2 , V_25 , V_24 , V_21 ,
V_23 ) ;
goto V_31;
}
V_28 = F_23 ( V_2 ) ;
V_27 = V_28 - V_24 ;
V_2 = V_20 ;
do {
struct V_3 * V_8 ;
int V_12 ;
F_24 ( V_2 ) ;
V_2 -> V_5 = 1 ;
V_2 -> V_23 = V_23 ;
F_25 ( V_2 , V_28 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 , V_23 ) ;
F_26 ( V_2 , V_27 ) ;
V_12 = V_2 -> V_12 - V_27 ;
V_8 = F_5 ( V_2 ) ;
V_8 -> V_12 = F_17 ( V_12 ) ;
if ( V_30 ) {
T_4 V_38 = F_27 ( V_29 + V_12 ) ;
V_8 -> V_9 = ~ F_28 ( ( V_39 V_40 )
( ( V_39 V_41 ) V_8 -> V_9 +
( V_39 V_41 ) V_38 ) ) ;
V_8 -> V_9 = F_29 ( V_2 , ~ V_8 -> V_9 ) ;
if ( V_8 -> V_9 == 0 )
V_8 -> V_9 = V_42 ;
}
V_2 -> V_25 = V_25 ;
} while ( ( V_2 = V_2 -> V_43 ) );
V_31:
return V_20 ;
}
static struct V_1 * F_30 ( struct V_1 * V_2 ,
T_1 V_19 )
{
struct V_1 * V_20 = F_10 ( - V_4 ) ;
unsigned int V_44 ;
int V_45 ;
V_40 V_46 ;
if ( V_2 -> V_5 &&
( F_18 ( V_2 ) -> V_33 &
( V_47 | V_34 ) ) ) {
V_20 = F_9 ( V_2 , V_19 ) ;
goto V_31;
}
V_44 = F_18 ( V_2 ) -> V_48 ;
if ( F_12 ( V_2 -> V_12 <= V_44 ) )
goto V_31;
if ( F_31 ( V_2 , V_19 | V_49 ) ) {
int type = F_18 ( V_2 ) -> V_33 ;
if ( F_12 ( type & ~ ( V_50 | V_51 |
V_47 |
V_34 |
V_52 |
V_53 | V_54 |
V_55 ) ||
! ( type & ( V_50 ) ) ) )
goto V_31;
F_18 ( V_2 ) -> V_56 = F_32 ( V_2 -> V_12 , V_44 ) ;
V_20 = NULL ;
goto V_31;
}
V_45 = F_33 ( V_2 ) ;
V_46 = F_34 ( V_2 , V_45 , V_2 -> V_12 - V_45 , 0 ) ;
V_45 += V_2 -> V_16 ;
* ( V_57 * ) ( V_2 -> V_58 + V_45 ) = F_28 ( V_46 ) ;
V_2 -> V_17 = V_59 ;
V_20 = F_35 ( V_2 , V_19 ) ;
V_31:
return V_20 ;
}
int F_36 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = F_37 ( sizeof( * V_63 ) , V_64 ) ;
if ( ! V_63 )
return - V_65 ;
V_63 -> V_66 = V_61 ;
F_38 ( & V_67 ) ;
V_63 -> V_43 = V_68 ;
F_39 ( V_68 , V_63 ) ;
F_40 ( & V_67 ) ;
return 0 ;
}
static void F_41 ( struct V_69 * V_15 )
{
struct V_62 * V_70 = F_42 ( V_15 , struct V_62 , V_71 ) ;
F_43 ( V_70 ) ;
}
void F_44 ( struct V_60 * V_61 )
{
struct V_62 T_5 * * V_15 = & V_68 ;
struct V_62 * V_72 ;
F_38 ( & V_67 ) ;
V_72 = F_45 ( * V_15 ) ;
for (; V_72 != NULL ;
V_72 = F_45 ( * V_15 ) ) {
if ( V_72 -> V_66 == V_61 ) {
F_39 ( * V_15 ,
F_45 ( V_72 -> V_43 ) ) ;
goto V_73;
}
V_15 = & V_72 -> V_43 ;
}
F_46 ( L_1 , F_47 ( V_61 -> V_74 ) ) ;
V_73:
F_40 ( & V_67 ) ;
if ( V_72 != NULL )
F_48 ( & V_72 -> V_71 , F_41 ) ;
}
static struct V_1 * * F_49 ( struct V_1 * * V_15 , struct V_1 * V_2 )
{
struct V_62 * V_72 ;
struct V_1 * V_75 , * * V_76 = NULL ;
struct V_3 * V_8 , * V_77 ;
unsigned int V_78 , V_79 ;
int V_80 = 1 ;
if ( F_50 ( V_2 ) -> V_81 ||
( ! V_2 -> V_5 && V_2 -> V_17 != V_82 ) )
goto V_31;
F_50 ( V_2 ) -> V_81 = 1 ;
V_79 = F_51 ( V_2 ) ;
V_78 = V_79 + sizeof( * V_8 ) ;
V_8 = F_52 ( V_2 , V_79 ) ;
if ( F_53 ( V_2 , V_78 ) ) {
V_8 = F_54 ( V_2 , V_78 , V_79 ) ;
if ( F_12 ( ! V_8 ) )
goto V_31;
}
F_55 () ;
V_72 = F_56 ( V_68 ) ;
for (; V_72 != NULL ; V_72 = F_56 ( V_72 -> V_43 ) ) {
if ( V_72 -> V_66 -> V_74 == V_8 -> V_83 &&
V_72 -> V_66 -> V_84 . V_85 )
goto V_86;
}
goto V_87;
V_86:
V_80 = 0 ;
for ( V_75 = * V_15 ; V_75 ; V_75 = V_75 -> V_43 ) {
if ( ! F_50 ( V_75 ) -> V_88 )
continue;
V_77 = (struct V_3 * ) ( V_75 -> V_58 + V_79 ) ;
if ( ( * ( V_41 * ) & V_8 -> V_89 != * ( V_41 * ) & V_77 -> V_89 ) ) {
F_50 ( V_75 ) -> V_88 = 0 ;
continue;
}
}
F_57 ( V_2 , sizeof( struct V_3 ) ) ;
F_58 ( V_2 , V_8 , sizeof( struct V_3 ) ) ;
V_76 = V_72 -> V_66 -> V_84 . V_85 ( V_15 , V_2 ) ;
V_87:
F_59 () ;
V_31:
F_50 ( V_2 ) -> V_80 |= V_80 ;
return V_76 ;
}
static int F_60 ( struct V_1 * V_2 , int V_90 )
{
struct V_62 * V_72 ;
T_3 V_91 = F_17 ( V_2 -> V_12 - V_90 ) ;
struct V_3 * V_8 = (struct V_3 * ) ( V_2 -> V_58 + V_90 ) ;
int V_92 = - V_93 ;
V_8 -> V_12 = V_91 ;
F_55 () ;
V_72 = F_56 ( V_68 ) ;
for (; V_72 != NULL ; V_72 = F_56 ( V_72 -> V_43 ) ) {
if ( V_72 -> V_66 -> V_74 == V_8 -> V_83 &&
V_72 -> V_66 -> V_84 . V_94 )
break;
}
if ( V_72 != NULL )
V_92 = V_72 -> V_66 -> V_84 . V_94 ( V_2 , V_90 + sizeof( struct V_3 ) ) ;
F_59 () ;
return V_92 ;
}
int T_6 F_61 ( void )
{
return F_62 ( & V_95 , V_13 ) ;
}
