static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
if ( V_3 == - V_8 )
return;
if ( V_3 )
goto V_9;
V_7 = F_3 ( V_2 ) ;
memcpy ( V_2 -> V_10 . V_11 , V_5 -> V_11 , F_4 ( V_7 ) ) ;
V_9:
F_5 ( V_5 -> V_11 ) ;
}
static void F_6 ( struct V_12 * V_13 , int V_3 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
F_1 ( V_2 , V_3 ) ;
F_7 ( V_2 , V_3 ) ;
}
static void F_8 ( struct V_15 * V_2 , int V_3 )
{
struct V_15 * V_5 = F_9 ( V_2 ) ;
struct V_16 * V_7 ;
if ( V_3 == - V_8 )
return;
if ( V_3 )
goto V_9;
V_7 = F_10 ( V_2 ) ;
memcpy ( V_2 -> V_17 , V_5 -> V_17 , F_11 ( V_7 ) ) ;
V_9:
F_12 ( V_5 -> V_17 ) ;
}
static void F_13 ( struct V_12 * V_13 ,
int V_3 )
{
struct V_15 * V_2 = V_13 -> V_14 ;
F_8 ( V_2 , V_3 ) ;
F_14 ( V_2 , V_3 ) ;
}
static void F_15 ( struct V_18 * V_19 , T_1 * V_11 , T_2 V_20 ,
unsigned int V_21 )
{
unsigned int V_22 = V_21 ;
if ( V_21 > sizeof( T_2 ) ) {
memset ( V_11 , 0 , V_21 - sizeof( T_2 ) ) ;
V_22 = sizeof( T_2 ) ;
}
V_20 = F_16 ( V_20 ) ;
memcpy ( V_11 + V_21 - V_22 , & V_20 , V_22 ) ;
F_17 ( V_11 , V_19 -> V_23 , V_21 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_18 * V_19 = F_19 ( V_7 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_24 ;
void * V_14 ;
T_1 * V_11 ;
unsigned int V_21 ;
int V_3 ;
F_20 ( V_5 , F_21 ( V_7 ) ) ;
V_24 = V_2 -> V_10 . V_13 . V_25 ;
V_14 = V_2 -> V_10 . V_13 . V_14 ;
V_11 = V_2 -> V_10 . V_11 ;
V_21 = F_4 ( V_7 ) ;
if ( F_22 ( ! F_23 ( ( unsigned long ) V_11 ,
F_24 ( V_7 ) + 1 ) ) ) {
V_11 = F_25 ( V_21 , V_2 -> V_10 . V_13 . V_26 &
V_27 ? V_28 :
V_29 ) ;
if ( ! V_11 )
return - V_30 ;
V_24 = F_6 ;
V_14 = V_2 ;
}
F_26 ( V_5 , V_2 -> V_10 . V_13 . V_26 , V_24 ,
V_14 ) ;
F_27 ( V_5 , V_2 -> V_10 . V_31 , V_2 -> V_10 . V_32 ,
V_2 -> V_10 . V_33 , V_11 ) ;
F_15 ( V_19 , V_11 , V_2 -> V_20 , V_21 ) ;
memcpy ( V_2 -> V_34 , V_11 , V_21 ) ;
V_3 = F_28 ( V_5 ) ;
if ( F_22 ( V_11 != V_2 -> V_10 . V_11 ) )
F_1 ( V_2 , V_3 ) ;
return V_3 ;
}
static int F_29 ( struct V_15 * V_2 )
{
struct V_16 * V_7 = F_10 ( V_2 ) ;
struct V_35 * V_19 = F_30 ( V_7 ) ;
struct V_15 * V_5 = F_9 ( V_2 ) ;
T_3 V_24 ;
void * V_14 ;
T_1 * V_11 ;
unsigned int V_21 = 8 ;
int V_3 ;
if ( V_2 -> V_36 < V_21 )
return - V_37 ;
F_31 ( V_5 , V_19 -> V_38 ) ;
V_24 = V_2 -> V_13 . V_25 ;
V_14 = V_2 -> V_13 . V_14 ;
V_11 = V_2 -> V_17 ;
if ( V_2 -> V_31 != V_2 -> V_32 ) {
struct V_39 V_40 = {
. V_41 = V_19 -> null ,
} ;
V_3 = F_32 ( & V_40 , V_2 -> V_32 , V_2 -> V_31 ,
V_2 -> V_42 + V_2 -> V_36 ) ;
if ( V_3 )
return V_3 ;
}
if ( F_22 ( ! F_23 ( ( unsigned long ) V_11 ,
F_33 ( V_7 ) + 1 ) ) ) {
V_11 = F_25 ( V_21 , V_2 -> V_13 . V_26 &
V_27 ? V_28 :
V_29 ) ;
if ( ! V_11 )
return - V_30 ;
memcpy ( V_11 , V_2 -> V_17 , V_21 ) ;
V_24 = F_13 ;
V_14 = V_2 ;
}
F_34 ( V_5 , V_2 -> V_13 . V_26 , V_24 , V_14 ) ;
F_35 ( V_5 , V_2 -> V_32 , V_2 -> V_32 ,
V_2 -> V_36 - V_21 , V_11 ) ;
F_36 ( V_5 , V_2 -> V_42 + V_21 ) ;
F_17 ( V_11 , V_19 -> V_23 , V_21 ) ;
F_37 ( V_11 , V_2 -> V_32 , V_2 -> V_42 , V_21 , 1 ) ;
V_3 = F_38 ( V_5 ) ;
if ( F_22 ( V_11 != V_2 -> V_17 ) )
F_8 ( V_2 , V_3 ) ;
return V_3 ;
}
static int F_39 ( struct V_15 * V_2 )
{
struct V_16 * V_7 = F_10 ( V_2 ) ;
struct V_35 * V_19 = F_30 ( V_7 ) ;
struct V_15 * V_5 = F_9 ( V_2 ) ;
T_3 V_24 ;
void * V_14 ;
unsigned int V_21 = 8 ;
if ( V_2 -> V_36 < V_21 + F_40 ( V_7 ) )
return - V_37 ;
F_31 ( V_5 , V_19 -> V_38 ) ;
V_24 = V_2 -> V_13 . V_25 ;
V_14 = V_2 -> V_13 . V_14 ;
F_34 ( V_5 , V_2 -> V_13 . V_26 , V_24 , V_14 ) ;
F_35 ( V_5 , V_2 -> V_31 , V_2 -> V_32 ,
V_2 -> V_36 - V_21 , V_2 -> V_17 ) ;
F_36 ( V_5 , V_2 -> V_42 + V_21 ) ;
F_37 ( V_2 -> V_17 , V_2 -> V_31 , V_2 -> V_42 , V_21 , 0 ) ;
return F_41 ( V_5 ) ;
}
static int F_42 ( struct V_43 * V_41 )
{
struct V_6 * V_7 = F_43 ( V_41 ) ;
struct V_18 * V_19 = F_19 ( V_7 ) ;
int V_3 ;
F_44 ( & V_19 -> V_44 ) ;
V_41 -> V_45 . V_46 = sizeof( struct V_4 ) ;
V_3 = 0 ;
if ( ! F_45 () ) {
F_46 ( V_7 ) -> V_47 = F_18 ;
V_3 = F_47 ( V_48 , V_19 -> V_23 ,
F_4 ( V_7 ) ) ;
F_48 () ;
}
return V_3 ? : F_49 ( V_41 ) ;
}
static int F_50 ( struct V_49 * V_50 ,
struct V_51 * * V_52 )
{
struct V_53 * V_54 ;
int V_3 ;
V_54 = F_51 ( V_50 , V_52 , 0 , 0 ) ;
if ( F_52 ( V_54 ) )
return F_53 ( V_54 ) ;
V_3 = - V_37 ;
if ( V_54 -> V_55 . V_56 . V_21 < sizeof( T_2 ) )
goto V_57;
V_54 -> V_55 . V_58 = F_42 ;
V_54 -> V_55 . V_59 = V_60 ;
V_54 -> V_55 . V_61 += V_54 -> V_55 . V_56 . V_21 ;
V_54 -> V_55 . V_61 += sizeof( struct V_18 ) ;
V_54 -> V_55 . V_62 |= F_54 ( V_63 ) - 1 ;
V_3 = F_55 ( V_50 , V_54 ) ;
if ( V_3 )
goto V_57;
V_9:
return V_3 ;
V_57:
F_56 ( V_54 ) ;
goto V_9;
}
static int F_57 ( struct V_49 * V_50 , struct V_51 * * V_52 )
{
struct V_64 * V_54 ;
struct V_65 * V_66 ;
struct V_67 * V_55 ;
int V_3 ;
V_54 = F_58 ( V_50 , V_52 , 0 , 0 ) ;
if ( F_52 ( V_54 ) )
return F_53 ( V_54 ) ;
V_54 -> V_55 . V_13 . V_62 |= F_54 ( V_63 ) - 1 ;
V_66 = F_59 ( V_54 ) ;
V_55 = F_60 ( V_66 ) ;
V_3 = - V_37 ;
if ( V_54 -> V_55 . V_21 != sizeof( T_2 ) )
goto V_57;
V_54 -> V_55 . V_68 = F_29 ;
V_54 -> V_55 . V_69 = F_39 ;
V_54 -> V_55 . V_70 = V_71 ;
V_54 -> V_55 . exit = V_72 ;
V_54 -> V_55 . V_13 . V_61 = sizeof( struct V_35 ) ;
V_54 -> V_55 . V_13 . V_61 += V_54 -> V_55 . V_21 ;
V_3 = F_61 ( V_50 , V_54 ) ;
if ( V_3 )
goto V_57;
V_9:
return V_3 ;
V_57:
F_62 ( V_54 ) ;
goto V_9;
}
static int F_63 ( struct V_49 * V_50 , struct V_51 * * V_52 )
{
struct V_73 * V_74 ;
int V_3 ;
V_74 = F_64 ( V_52 ) ;
if ( F_52 ( V_74 ) )
return F_53 ( V_74 ) ;
if ( ( V_74 -> type ^ V_75 ) & V_76 )
V_3 = F_50 ( V_50 , V_52 ) ;
else
V_3 = F_57 ( V_50 , V_52 ) ;
return V_3 ;
}
static void F_65 ( struct V_53 * V_54 )
{
if ( ( V_54 -> V_55 . V_77 ^ V_75 ) & V_76 )
F_56 ( V_54 ) ;
else
F_62 ( V_64 ( V_54 ) ) ;
}
static int T_4 F_66 ( void )
{
return F_67 ( & V_78 ) ;
}
static void T_5 F_68 ( void )
{
F_69 ( & V_78 ) ;
}
