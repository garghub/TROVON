static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = F_4 ( V_2 ) ;
unsigned int V_9 ;
int V_10 ;
F_5 ( V_8 , F_6 ( V_4 ) ) ;
F_7 ( V_8 , V_2 -> V_11 . V_12 . V_13 &
~ V_14 ,
V_2 -> V_11 . V_12 . V_15 ,
V_2 -> V_11 . V_12 . V_16 ) ;
F_8 ( V_8 , V_2 -> V_11 . V_17 , V_2 -> V_11 . V_18 ,
V_2 -> V_11 . V_19 , V_2 -> V_11 . V_20 ) ;
F_9 ( & V_6 -> V_21 ) ;
V_9 = F_10 ( V_4 ) ;
memcpy ( V_2 -> V_22 , V_6 -> V_23 , V_9 ) ;
memcpy ( V_8 -> V_20 , V_6 -> V_23 , V_9 ) ;
V_10 = F_11 ( V_8 ) ;
if ( V_10 )
goto V_24;
memcpy ( V_6 -> V_23 , V_8 -> V_20 , V_9 ) ;
V_24:
F_12 ( & V_6 -> V_21 ) ;
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_10 = 0 ;
F_9 ( & V_6 -> V_21 ) ;
if ( F_14 ( V_4 ) -> V_25 !=
F_13 )
goto V_24;
F_14 ( V_4 ) -> V_25 = F_1 ;
V_10 = F_15 ( V_26 , V_6 -> V_23 ,
F_10 ( V_4 ) ) ;
V_24:
F_12 ( & V_6 -> V_21 ) ;
if ( V_10 )
return V_10 ;
return F_1 ( V_2 ) ;
}
static int F_16 ( struct V_27 * V_28 )
{
V_28 -> V_29 . V_30 = sizeof( struct V_7 ) ;
return F_17 ( V_28 ) ;
}
static int F_18 ( struct V_27 * V_28 )
{
struct V_5 * V_6 = F_19 ( V_28 ) ;
F_20 ( & V_6 -> V_21 ) ;
return F_16 ( V_28 ) ;
}
static int F_21 ( struct V_31 * V_6 )
{
int V_32 ;
int V_10 = V_6 -> V_10 ;
if ( ! V_6 -> V_33 . V_34 ) {
F_22 () ;
F_23 ( V_35 , & V_6 -> V_36 ) ;
if ( ! V_6 -> V_33 . V_34 ||
F_24 ( V_35 , & V_6 -> V_36 ) )
goto V_37;
}
V_32 = F_25 ( V_38 , & V_6 -> V_39 ) ;
F_26 ( ! V_32 ) ;
V_37:
return V_10 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_6 = F_3 ( V_4 ) ;
int V_10 ;
F_9 ( & V_6 -> V_21 ) ;
V_10 = F_28 ( & V_6 -> V_33 , V_2 ) ;
F_12 ( & V_6 -> V_21 ) ;
if ( F_24 ( V_35 , & V_6 -> V_36 ) )
return V_10 ;
V_6 -> V_10 = V_10 ;
return F_21 ( V_6 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = F_4 ( V_2 ) ;
unsigned int V_9 = F_10 ( V_4 ) ;
memcpy ( V_2 -> V_22 , V_6 -> V_23 , V_9 ) ;
memcpy ( V_8 -> V_20 , V_6 -> V_23 , V_9 ) ;
V_6 -> V_10 = F_11 ( V_8 ) ;
if ( V_6 -> V_10 )
goto V_37;
memcpy ( V_6 -> V_23 , V_8 -> V_20 , V_9 ) ;
V_37:
return F_21 ( V_6 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = F_4 ( V_2 ) ;
F_5 ( V_8 , F_6 ( V_4 ) ) ;
F_7 ( V_8 , V_2 -> V_11 . V_12 . V_13 ,
V_2 -> V_11 . V_12 . V_15 ,
V_2 -> V_11 . V_12 . V_16 ) ;
F_8 ( V_8 , V_2 -> V_11 . V_17 , V_2 -> V_11 . V_18 ,
V_2 -> V_11 . V_19 , V_2 -> V_11 . V_20 ) ;
if ( F_24 ( V_35 , & V_6 -> V_36 ) )
goto V_40;
if ( V_6 -> V_33 . V_34 ) {
F_23 ( V_35 , & V_6 -> V_36 ) ;
goto V_40;
}
return F_29 ( V_2 ) ;
V_40:
return F_27 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_6 = F_3 ( V_4 ) ;
int V_10 = 0 ;
if ( F_24 ( V_35 , & V_6 -> V_36 ) )
goto V_37;
if ( F_14 ( V_4 ) -> V_25 !=
F_31 )
goto V_24;
F_14 ( V_4 ) -> V_25 = F_30 ;
V_10 = F_15 ( V_26 , V_6 -> V_23 ,
F_10 ( V_4 ) ) ;
V_24:
F_23 ( V_35 , & V_6 -> V_36 ) ;
if ( V_10 )
return V_10 ;
V_37:
return F_30 ( V_2 ) ;
}
static void F_32 ( struct V_41 * V_42 )
{
struct V_31 * V_6 = F_33 ( V_42 ,
struct V_31 ,
V_39 ) ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_10 ;
F_9 ( & V_6 -> V_21 ) ;
V_2 = F_34 ( & V_6 -> V_33 ) ;
F_12 ( & V_6 -> V_21 ) ;
if ( ! V_2 ) {
F_21 ( V_6 ) ;
return;
}
V_8 = F_4 ( V_2 ) ;
V_8 -> V_12 . V_13 |= V_14 ;
V_10 = F_29 ( V_2 ) ;
F_35 () ;
F_36 ( V_2 , V_10 ) ;
F_37 () ;
}
static int F_38 ( struct V_27 * V_28 )
{
struct V_31 * V_6 = F_19 ( V_28 ) ;
F_20 ( & V_6 -> V_21 ) ;
F_39 ( & V_6 -> V_33 , 100 ) ;
F_40 ( & V_6 -> V_39 , F_32 ) ;
return F_16 ( V_28 ) ;
}
static void F_41 ( struct V_27 * V_28 )
{
struct V_31 * V_6 = F_19 ( V_28 ) ;
F_26 ( F_42 ( V_35 , & V_6 -> V_36 ) || V_6 -> V_33 . V_34 ) ;
F_43 ( V_28 ) ;
}
static struct V_43 * F_44 ( struct V_44 * * V_45 )
{
struct V_46 * V_47 ;
struct V_43 * V_48 ;
int V_10 ;
V_47 = F_45 ( V_45 ) ;
V_10 = F_46 ( V_47 ) ;
if ( F_47 ( V_47 ) )
return F_48 ( V_10 ) ;
V_10 = F_49 () ;
if ( V_10 )
return F_48 ( V_10 ) ;
V_48 = F_50 ( & V_49 , V_45 , 0 , 0 ) ;
if ( F_47 ( V_48 ) )
goto V_50;
V_48 -> V_51 . V_52 . V_25 = F_13 ;
V_48 -> V_51 . V_53 = F_18 ;
V_48 -> V_51 . V_54 = F_43 ;
V_48 -> V_51 . V_55 = sizeof( struct V_5 ) ;
if ( ! F_51 ( V_47 -> type , V_47 -> V_56 ) ) {
V_48 -> V_51 . V_57 |= V_58 ;
V_48 -> V_51 . V_52 . V_25 =
F_31 ;
V_48 -> V_51 . V_53 = F_38 ;
V_48 -> V_51 . V_54 = F_41 ;
V_48 -> V_51 . V_55 = sizeof( struct V_31 ) ;
}
V_48 -> V_51 . V_55 += V_48 -> V_51 . V_52 . V_9 ;
V_37:
return V_48 ;
V_50:
F_52 () ;
goto V_37;
}
static void F_53 ( struct V_43 * V_48 )
{
F_54 ( V_48 ) ;
F_52 () ;
}
static int T_1 F_55 ( void )
{
return F_56 ( & V_49 ) ;
}
static void F_57 ( void )
{
F_58 ( & V_49 ) ;
}
