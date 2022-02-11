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
struct V_16 * V_5 = F_9 ( V_2 ) ;
struct V_17 * V_7 ;
if ( V_3 == - V_8 )
return;
if ( V_3 )
goto V_9;
V_7 = F_10 ( V_2 ) ;
memcpy ( V_2 -> V_18 . V_19 , V_5 -> V_19 , F_11 ( V_7 ) ) ;
V_9:
F_5 ( V_5 -> V_19 ) ;
}
static void F_12 ( struct V_12 * V_13 , int V_3 )
{
struct V_15 * V_2 = V_13 -> V_14 ;
F_8 ( V_2 , V_3 ) ;
F_13 ( V_2 , V_3 ) ;
}
static void F_14 ( struct V_20 * V_21 , T_1 * V_11 , T_2 V_22 ,
unsigned int V_23 )
{
unsigned int V_24 = V_23 ;
if ( V_23 > sizeof( T_2 ) ) {
memset ( V_11 , 0 , V_23 - sizeof( T_2 ) ) ;
V_24 = sizeof( T_2 ) ;
}
V_22 = F_15 ( V_22 ) ;
memcpy ( V_11 + V_23 - V_24 , & V_22 , V_24 ) ;
F_16 ( V_11 , V_21 -> V_25 , V_23 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_20 * V_21 = F_18 ( V_7 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_26 ;
void * V_14 ;
T_1 * V_11 ;
unsigned int V_23 ;
int V_3 ;
F_19 ( V_5 , F_20 ( V_7 ) ) ;
V_26 = V_2 -> V_10 . V_13 . V_26 ;
V_14 = V_2 -> V_10 . V_13 . V_14 ;
V_11 = V_2 -> V_10 . V_11 ;
V_23 = F_4 ( V_7 ) ;
if ( F_21 ( ! F_22 ( ( unsigned long ) V_11 ,
F_23 ( V_7 ) + 1 ) ) ) {
V_11 = F_24 ( V_23 , V_2 -> V_10 . V_13 . V_27 &
V_28 ? V_29 :
V_30 ) ;
if ( ! V_11 )
return - V_31 ;
V_26 = F_6 ;
V_14 = V_2 ;
}
F_25 ( V_5 , V_2 -> V_10 . V_13 . V_27 , V_26 ,
V_14 ) ;
F_26 ( V_5 , V_2 -> V_10 . V_32 , V_2 -> V_10 . V_33 ,
V_2 -> V_10 . V_34 , V_11 ) ;
F_14 ( V_21 , V_11 , V_2 -> V_22 , V_23 ) ;
memcpy ( V_2 -> V_35 , V_11 , V_23 ) ;
V_3 = F_27 ( V_5 ) ;
if ( F_21 ( V_11 != V_2 -> V_10 . V_11 ) )
F_1 ( V_2 , V_3 ) ;
return V_3 ;
}
static int F_28 ( struct V_15 * V_2 )
{
struct V_17 * V_7 = F_10 ( V_2 ) ;
struct V_20 * V_21 = F_29 ( V_7 ) ;
struct V_16 * V_18 = & V_2 -> V_18 ;
struct V_16 * V_5 = F_9 ( V_2 ) ;
T_3 V_26 ;
void * V_14 ;
T_1 * V_11 ;
unsigned int V_23 ;
int V_3 ;
F_30 ( V_5 , F_31 ( V_7 ) ) ;
V_26 = V_18 -> V_13 . V_26 ;
V_14 = V_18 -> V_13 . V_14 ;
V_11 = V_18 -> V_19 ;
V_23 = F_11 ( V_7 ) ;
if ( F_21 ( ! F_22 ( ( unsigned long ) V_11 ,
F_32 ( V_7 ) + 1 ) ) ) {
V_11 = F_24 ( V_23 , V_18 -> V_13 . V_27 &
V_28 ? V_29 :
V_30 ) ;
if ( ! V_11 )
return - V_31 ;
V_26 = F_12 ;
V_14 = V_2 ;
}
F_33 ( V_5 , V_18 -> V_13 . V_27 , V_26 , V_14 ) ;
F_34 ( V_5 , V_18 -> V_32 , V_18 -> V_33 , V_18 -> V_36 ,
V_11 ) ;
F_35 ( V_5 , V_18 -> V_37 , V_18 -> V_38 ) ;
F_14 ( V_21 , V_11 , V_2 -> V_22 , V_23 ) ;
memcpy ( V_2 -> V_35 , V_11 , V_23 ) ;
V_3 = F_36 ( V_5 ) ;
if ( F_21 ( V_11 != V_18 -> V_19 ) )
F_8 ( V_2 , V_3 ) ;
return V_3 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_20 * V_21 = F_18 ( V_7 ) ;
int V_3 = 0 ;
F_38 ( & V_21 -> V_39 ) ;
if ( F_39 ( V_7 ) -> V_40 != F_37 )
goto V_41;
F_39 ( V_7 ) -> V_40 = F_17 ;
V_3 = F_40 ( V_42 , V_21 -> V_25 ,
F_4 ( V_7 ) ) ;
V_41:
F_41 ( & V_21 -> V_39 ) ;
if ( V_3 )
return V_3 ;
return F_17 ( V_2 ) ;
}
static int F_42 ( struct V_15 * V_2 )
{
struct V_17 * V_7 = F_10 ( V_2 ) ;
struct V_20 * V_21 = F_29 ( V_7 ) ;
int V_3 = 0 ;
F_38 ( & V_21 -> V_39 ) ;
if ( F_43 ( V_7 ) -> V_40 != F_42 )
goto V_41;
F_43 ( V_7 ) -> V_40 = F_28 ;
V_3 = F_40 ( V_42 , V_21 -> V_25 ,
F_11 ( V_7 ) ) ;
V_41:
F_41 ( & V_21 -> V_39 ) ;
if ( V_3 )
return V_3 ;
return F_28 ( V_2 ) ;
}
static int F_44 ( struct V_43 * V_44 )
{
struct V_6 * V_7 = F_45 ( V_44 ) ;
struct V_20 * V_21 = F_18 ( V_7 ) ;
F_46 ( & V_21 -> V_39 ) ;
V_44 -> V_45 . V_46 = sizeof( struct V_4 ) ;
return F_47 ( V_44 ) ;
}
static int F_48 ( struct V_43 * V_44 )
{
struct V_17 * V_7 = F_49 ( V_44 ) ;
struct V_20 * V_21 = F_29 ( V_7 ) ;
F_46 ( & V_21 -> V_39 ) ;
V_44 -> V_47 . V_46 = sizeof( struct V_16 ) ;
return F_50 ( V_44 ) ;
}
static struct V_48 * F_51 ( struct V_49 * * V_50 )
{
struct V_48 * V_51 ;
V_51 = F_52 ( & V_52 , V_50 , 0 , 0 ) ;
if ( F_53 ( V_51 ) )
goto V_9;
V_51 -> V_53 . V_54 . V_40 = F_37 ;
V_51 -> V_53 . V_55 = F_44 ;
V_51 -> V_53 . V_56 = V_57 ;
V_51 -> V_53 . V_58 += V_51 -> V_53 . V_54 . V_23 ;
V_9:
return V_51 ;
}
static struct V_48 * F_54 ( struct V_49 * * V_50 )
{
struct V_48 * V_51 ;
V_51 = F_55 ( & V_52 , V_50 , 0 , 0 ) ;
if ( F_53 ( V_51 ) )
goto V_9;
V_51 -> V_53 . V_59 . V_40 = F_42 ;
V_51 -> V_53 . V_55 = F_48 ;
V_51 -> V_53 . V_56 = V_60 ;
V_51 -> V_53 . V_58 = V_51 -> V_53 . V_59 . V_23 ;
V_9:
return V_51 ;
}
static struct V_48 * F_56 ( struct V_49 * * V_50 )
{
struct V_61 * V_62 ;
struct V_48 * V_51 ;
int V_3 ;
V_62 = F_57 ( V_50 ) ;
if ( F_53 ( V_62 ) )
return F_58 ( V_62 ) ;
V_3 = F_59 () ;
if ( V_3 )
return F_60 ( V_3 ) ;
if ( ( V_62 -> type ^ V_63 ) & V_64 )
V_51 = F_51 ( V_50 ) ;
else
V_51 = F_54 ( V_50 ) ;
if ( F_53 ( V_51 ) )
goto V_65;
V_51 -> V_53 . V_66 |= F_61 ( V_67 ) - 1 ;
V_51 -> V_53 . V_58 += sizeof( struct V_20 ) ;
V_9:
return V_51 ;
V_65:
F_62 () ;
goto V_9;
}
static void F_63 ( struct V_48 * V_51 )
{
if ( ( V_51 -> V_53 . V_68 ^ V_63 ) & V_64 )
F_64 ( V_51 ) ;
else
F_65 ( V_51 ) ;
F_62 () ;
}
static int T_4 F_66 ( void )
{
return F_67 ( & V_52 ) ;
}
static void T_5 F_68 ( void )
{
F_69 ( & V_52 ) ;
}
