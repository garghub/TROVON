static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_1 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
if ( V_3 == - V_7 )
return;
if ( V_3 )
goto V_8;
V_6 = F_3 ( V_2 ) ;
memcpy ( V_2 -> V_9 , V_4 -> V_9 , F_4 ( V_6 ) ) ;
V_8:
F_5 ( V_4 -> V_9 ) ;
}
static void F_6 ( struct V_10 * V_11 ,
int V_3 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
F_1 ( V_2 , V_3 ) ;
F_7 ( V_2 , V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_13 * V_14 = F_9 ( V_6 ) ;
struct V_1 * V_4 = F_2 ( V_2 ) ;
T_1 V_15 ;
void * V_12 ;
T_2 * V_16 ;
unsigned int V_17 = 8 ;
int V_3 ;
if ( V_2 -> V_18 < V_17 )
return - V_19 ;
F_10 ( V_4 , V_14 -> V_20 ) ;
V_15 = V_2 -> V_11 . V_21 ;
V_12 = V_2 -> V_11 . V_12 ;
V_16 = V_2 -> V_9 ;
if ( V_2 -> V_22 != V_2 -> V_23 ) {
F_11 ( V_24 , V_14 -> V_25 ) ;
F_12 ( V_24 , V_14 -> V_25 ) ;
F_13 ( V_24 , V_2 -> V_11 . V_26 ,
NULL , NULL ) ;
F_14 ( V_24 , V_2 -> V_22 , V_2 -> V_23 ,
V_2 -> V_27 + V_2 -> V_18 ,
NULL ) ;
V_3 = F_15 ( V_24 ) ;
if ( V_3 )
return V_3 ;
}
if ( F_16 ( ! F_17 ( ( unsigned long ) V_16 ,
F_18 ( V_6 ) + 1 ) ) ) {
V_16 = F_19 ( V_17 , V_2 -> V_11 . V_26 &
V_28 ? V_29 :
V_30 ) ;
if ( ! V_16 )
return - V_31 ;
memcpy ( V_16 , V_2 -> V_9 , V_17 ) ;
V_15 = F_6 ;
V_12 = V_2 ;
}
F_20 ( V_4 , V_2 -> V_11 . V_26 , V_15 , V_12 ) ;
F_21 ( V_4 , V_2 -> V_23 , V_2 -> V_23 ,
V_2 -> V_18 - V_17 , V_16 ) ;
F_22 ( V_4 , V_2 -> V_27 + V_17 ) ;
F_23 ( V_16 , V_14 -> V_32 , V_17 ) ;
F_24 ( V_16 , V_2 -> V_23 , V_2 -> V_27 , V_17 , 1 ) ;
V_3 = F_25 ( V_4 ) ;
if ( F_16 ( V_16 != V_2 -> V_9 ) )
F_1 ( V_2 , V_3 ) ;
return V_3 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_13 * V_14 = F_9 ( V_6 ) ;
struct V_1 * V_4 = F_2 ( V_2 ) ;
T_1 V_15 ;
void * V_12 ;
unsigned int V_17 = 8 ;
if ( V_2 -> V_18 < V_17 + F_27 ( V_6 ) )
return - V_19 ;
F_10 ( V_4 , V_14 -> V_20 ) ;
V_15 = V_2 -> V_11 . V_21 ;
V_12 = V_2 -> V_11 . V_12 ;
F_20 ( V_4 , V_2 -> V_11 . V_26 , V_15 , V_12 ) ;
F_21 ( V_4 , V_2 -> V_22 , V_2 -> V_23 ,
V_2 -> V_18 - V_17 , V_2 -> V_9 ) ;
F_22 ( V_4 , V_2 -> V_27 + V_17 ) ;
F_24 ( V_2 -> V_9 , V_2 -> V_22 , V_2 -> V_27 , V_17 , 0 ) ;
return F_28 ( V_4 ) ;
}
static int F_29 ( struct V_33 * V_34 , struct V_35 * * V_36 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
int V_3 ;
V_38 = F_30 ( V_34 , V_36 , 0 , 0 ) ;
if ( F_31 ( V_38 ) )
return F_32 ( V_38 ) ;
V_38 -> V_42 . V_11 . V_43 |= F_33 ( V_44 ) - 1 ;
V_40 = F_34 ( V_38 ) ;
V_42 = F_35 ( V_40 ) ;
V_3 = - V_19 ;
if ( V_38 -> V_42 . V_17 != sizeof( V_45 ) )
goto V_46;
V_38 -> V_42 . V_47 = F_8 ;
V_38 -> V_42 . V_48 = F_26 ;
V_38 -> V_42 . V_49 = V_50 ;
V_38 -> V_42 . exit = V_51 ;
V_38 -> V_42 . V_11 . V_52 = sizeof( struct V_13 ) ;
V_38 -> V_42 . V_11 . V_52 += V_38 -> V_42 . V_17 ;
V_3 = F_36 ( V_34 , V_38 ) ;
if ( V_3 )
goto V_46;
V_8:
return V_3 ;
V_46:
F_37 ( V_38 ) ;
goto V_8;
}
static int F_38 ( struct V_33 * V_34 , struct V_35 * * V_36 )
{
struct V_53 * V_54 ;
V_54 = F_39 ( V_36 ) ;
if ( F_31 ( V_54 ) )
return F_32 ( V_54 ) ;
if ( ( V_54 -> type ^ V_55 ) & V_56 )
return - V_19 ;
return F_29 ( V_34 , V_36 ) ;
}
static void F_40 ( struct V_57 * V_38 )
{
F_37 ( V_37 ( V_38 ) ) ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_58 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_58 ) ;
}
