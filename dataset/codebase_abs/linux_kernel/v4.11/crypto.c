void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( V_2 -> V_3 & V_4 && V_2 -> V_5 . V_6 ) {
F_2 ( V_2 -> V_5 . V_6 , V_7 ) ;
V_2 -> V_5 . V_6 = NULL ;
}
V_2 -> V_5 . V_8 = NULL ;
if ( V_2 -> V_3 & V_9 ) {
F_3 ( V_10 , V_2 ) ;
} else {
F_4 ( & V_11 , V_3 ) ;
F_5 ( & V_2 -> V_12 , & V_13 ) ;
F_6 ( & V_11 , V_3 ) ;
}
}
struct V_1 * F_7 ( const struct V_14 * V_14 , T_1 V_15 )
{
struct V_1 * V_2 = NULL ;
struct V_16 * V_17 = V_14 -> V_18 ;
unsigned long V_3 ;
if ( V_17 == NULL )
return F_8 ( - V_19 ) ;
F_4 ( & V_11 , V_3 ) ;
V_2 = F_9 ( & V_13 ,
struct V_1 , V_12 ) ;
if ( V_2 )
F_10 ( & V_2 -> V_12 ) ;
F_6 ( & V_11 , V_3 ) ;
if ( ! V_2 ) {
V_2 = F_11 ( V_10 , V_15 ) ;
if ( ! V_2 )
return F_8 ( - V_20 ) ;
V_2 -> V_3 |= V_9 ;
} else {
V_2 -> V_3 &= ~ V_9 ;
}
V_2 -> V_3 &= ~ V_4 ;
return V_2 ;
}
static void F_12 ( struct V_21 * V_22 , int V_23 )
{
struct V_24 * V_25 = V_22 -> V_26 ;
if ( V_23 == - V_27 )
return;
V_25 -> V_23 = V_23 ;
F_13 ( & V_25 -> V_28 ) ;
}
int F_14 ( const struct V_14 * V_14 , T_2 V_29 ,
T_3 V_30 , struct V_31 * V_32 ,
struct V_31 * V_33 , unsigned int V_34 ,
unsigned int V_35 , T_1 V_15 )
{
struct {
T_4 V_36 ;
T_5 V_37 [ V_38 - sizeof( T_4 ) ] ;
} V_39 ;
struct V_40 * V_22 = NULL ;
F_15 ( V_25 ) ;
struct V_41 V_42 , V_43 ;
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_44 * V_45 = V_17 -> V_46 ;
int V_23 = 0 ;
F_16 ( V_34 == 0 ) ;
V_22 = F_17 ( V_45 , V_15 ) ;
if ( ! V_22 ) {
F_18 ( V_47
L_1 ,
V_48 ) ;
return - V_20 ;
}
F_19 (
V_22 , V_49 | V_50 ,
F_12 , & V_25 ) ;
F_20 ( sizeof( V_39 ) != V_38 ) ;
V_39 . V_36 = F_21 ( V_30 ) ;
memset ( V_39 . V_37 , 0 , sizeof( V_39 . V_37 ) ) ;
F_22 ( & V_42 , 1 ) ;
F_23 ( & V_42 , V_33 , V_34 , V_35 ) ;
F_22 ( & V_43 , 1 ) ;
F_23 ( & V_43 , V_32 , V_34 , V_35 ) ;
F_24 ( V_22 , & V_43 , & V_42 , V_34 , & V_39 ) ;
if ( V_29 == V_51 )
V_23 = F_25 ( V_22 ) ;
else
V_23 = F_26 ( V_22 ) ;
if ( V_23 == - V_27 || V_23 == - V_52 ) {
F_16 ( V_22 -> V_53 . V_26 != & V_25 ) ;
F_27 ( & V_25 . V_28 ) ;
V_23 = V_25 . V_23 ;
}
F_28 ( V_22 ) ;
if ( V_23 ) {
F_18 ( V_47
L_2 ,
V_48 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
struct V_31 * F_29 ( struct V_1 * V_2 ,
T_1 V_15 )
{
V_2 -> V_5 . V_6 = F_30 ( V_7 , V_15 ) ;
if ( V_2 -> V_5 . V_6 == NULL )
return F_8 ( - V_20 ) ;
V_2 -> V_3 |= V_4 ;
return V_2 -> V_5 . V_6 ;
}
struct V_31 * F_31 ( const struct V_14 * V_14 ,
struct V_31 * V_31 ,
unsigned int V_34 ,
unsigned int V_35 ,
T_3 V_30 , T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_31 * V_54 = V_31 ;
int V_55 ;
F_16 ( V_34 % V_56 != 0 ) ;
if ( V_14 -> V_57 -> V_58 -> V_3 & V_59 ) {
V_55 = F_14 ( V_14 , V_60 , V_30 , V_31 ,
V_54 , V_34 , V_35 ,
V_15 ) ;
if ( V_55 )
return F_8 ( V_55 ) ;
return V_54 ;
}
F_16 ( ! F_32 ( V_31 ) ) ;
V_2 = F_7 ( V_14 , V_15 ) ;
if ( F_33 ( V_2 ) )
return (struct V_31 * ) V_2 ;
V_54 = F_29 ( V_2 , V_15 ) ;
if ( F_33 ( V_54 ) )
goto V_61;
V_2 -> V_5 . V_8 = V_31 ;
V_55 = F_14 ( V_14 , V_60 , V_30 ,
V_31 , V_54 , V_34 , V_35 ,
V_15 ) ;
if ( V_55 ) {
V_54 = F_8 ( V_55 ) ;
goto V_61;
}
F_34 ( V_54 ) ;
F_35 ( V_54 , ( unsigned long ) V_2 ) ;
F_36 ( V_54 ) ;
return V_54 ;
V_61:
F_1 ( V_2 ) ;
return V_54 ;
}
int F_37 ( const struct V_14 * V_14 , struct V_31 * V_31 ,
unsigned int V_34 , unsigned int V_35 , T_3 V_30 )
{
if ( ! ( V_14 -> V_57 -> V_58 -> V_3 & V_59 ) )
F_16 ( ! F_32 ( V_31 ) ) ;
return F_14 ( V_14 , V_51 , V_30 , V_31 , V_31 ,
V_34 , V_35 , V_62 ) ;
}
static int F_38 ( struct V_63 * V_63 , unsigned int V_3 )
{
struct V_63 * V_64 ;
int V_65 , V_66 ;
if ( V_3 & V_67 )
return - V_68 ;
V_64 = F_39 ( V_63 ) ;
if ( ! F_40 ( V_64 ) -> V_57 -> V_58 -> V_69 ( F_40 ( V_64 ) ) ) {
F_41 ( V_64 ) ;
return 0 ;
}
F_42 ( & V_63 -> V_70 ) ;
V_66 = V_63 -> V_71 & V_72 ;
F_43 ( & V_63 -> V_70 ) ;
V_65 = ( F_40 ( V_64 ) -> V_18 != NULL ) ;
F_41 ( V_64 ) ;
if ( ( ! V_66 && F_44 ( V_63 ) ) ||
( ! V_66 && V_65 ) ||
( V_66 && ! V_65 ) )
return 0 ;
return 1 ;
}
void F_45 ( struct V_31 * V_31 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_46 ( V_31 ) ;
F_35 ( V_31 , ( unsigned long ) NULL ) ;
F_47 ( V_31 ) ;
F_48 ( V_31 ) ;
F_1 ( V_2 ) ;
}
static void F_49 ( void )
{
struct V_1 * V_73 , * V_74 ;
F_50 (pos, n, &fscrypt_free_ctxs, free_list)
F_3 ( V_10 , V_73 ) ;
F_51 ( & V_13 ) ;
F_52 ( V_7 ) ;
V_7 = NULL ;
}
int F_53 ( unsigned int V_75 )
{
int V_76 , V_23 = - V_20 ;
if ( V_75 & V_59 || V_7 )
return 0 ;
F_54 ( & V_77 ) ;
if ( V_7 )
goto V_78;
for ( V_76 = 0 ; V_76 < V_79 ; V_76 ++ ) {
struct V_1 * V_2 ;
V_2 = F_11 ( V_10 , V_62 ) ;
if ( ! V_2 )
goto V_80;
F_5 ( & V_2 -> V_12 , & V_13 ) ;
}
V_7 =
F_55 ( V_81 , 0 ) ;
if ( ! V_7 )
goto V_80;
V_78:
F_56 ( & V_77 ) ;
return 0 ;
V_80:
F_49 () ;
F_56 ( & V_77 ) ;
return V_23 ;
}
static int T_6 F_57 ( void )
{
V_82 = F_58 ( L_3 ,
V_83 , 0 ) ;
if ( ! V_82 )
goto V_80;
V_10 = F_59 ( V_1 , V_84 ) ;
if ( ! V_10 )
goto V_85;
V_86 = F_59 ( V_16 , V_84 ) ;
if ( ! V_86 )
goto V_87;
return 0 ;
V_87:
F_60 ( V_10 ) ;
V_85:
F_61 ( V_82 ) ;
V_80:
return - V_20 ;
}
static void T_7 F_62 ( void )
{
F_49 () ;
if ( V_82 )
F_61 ( V_82 ) ;
F_60 ( V_10 ) ;
F_60 ( V_86 ) ;
}
