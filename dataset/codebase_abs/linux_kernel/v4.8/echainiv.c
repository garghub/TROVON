static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_1 * V_7 = F_4 ( V_2 ) ;
T_1 V_8 ;
T_2 V_9 ;
T_3 * V_10 ;
unsigned int V_11 = F_5 ( V_4 ) ;
int V_12 ;
if ( V_2 -> V_13 < V_11 )
return - V_14 ;
F_6 ( V_7 , V_6 -> V_15 ) ;
V_10 = V_2 -> V_16 ;
if ( V_2 -> V_17 != V_2 -> V_18 ) {
F_7 ( V_19 , V_6 -> V_20 ) ;
F_8 ( V_19 , V_6 -> V_20 ) ;
F_9 ( V_19 , V_2 -> V_21 . V_22 ,
NULL , NULL ) ;
F_10 ( V_19 , V_2 -> V_17 , V_2 -> V_18 ,
V_2 -> V_23 + V_2 -> V_13 ,
NULL ) ;
V_12 = F_11 ( V_19 ) ;
if ( V_12 )
return V_12 ;
}
F_12 ( V_7 , V_2 -> V_21 . V_22 ,
V_2 -> V_21 . V_24 , V_2 -> V_21 . V_25 ) ;
F_13 ( V_7 , V_2 -> V_18 , V_2 -> V_18 ,
V_2 -> V_13 , V_10 ) ;
F_14 ( V_7 , V_2 -> V_23 ) ;
memcpy ( & V_8 , V_10 + V_11 - 8 , 8 ) ;
V_9 = F_15 ( V_8 ) ;
memset ( V_10 , 0 , V_11 ) ;
F_16 ( V_10 , V_2 -> V_18 , V_2 -> V_23 , V_11 , 1 ) ;
do {
T_2 V_26 ;
memcpy ( & V_26 , V_6 -> V_27 + V_11 - 8 , 8 ) ;
V_26 |= 1 ;
V_26 *= V_9 ;
memcpy ( V_10 + V_11 - 8 , & V_26 , 8 ) ;
} while ( ( V_11 -= 8 ) );
return F_17 ( V_7 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_1 * V_7 = F_4 ( V_2 ) ;
T_4 V_28 ;
void * V_25 ;
unsigned int V_11 = F_5 ( V_4 ) ;
if ( V_2 -> V_13 < V_11 )
return - V_14 ;
F_6 ( V_7 , V_6 -> V_15 ) ;
V_28 = V_2 -> V_21 . V_24 ;
V_25 = V_2 -> V_21 . V_25 ;
F_12 ( V_7 , V_2 -> V_21 . V_22 , V_28 , V_25 ) ;
F_13 ( V_7 , V_2 -> V_17 , V_2 -> V_18 ,
V_2 -> V_13 - V_11 , V_2 -> V_16 ) ;
F_14 ( V_7 , V_2 -> V_23 + V_11 ) ;
F_16 ( V_2 -> V_16 , V_2 -> V_17 , V_2 -> V_23 , V_11 , 0 ) ;
return F_19 ( V_7 ) ;
}
static int F_20 ( struct V_29 * V_30 ,
struct V_31 * * V_32 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
int V_12 ;
V_34 = F_21 ( V_30 , V_32 , 0 , 0 ) ;
if ( F_22 ( V_34 ) )
return F_23 ( V_34 ) ;
V_36 = F_24 ( V_34 ) ;
V_38 = F_25 ( V_36 ) ;
V_12 = - V_14 ;
if ( V_34 -> V_38 . V_11 & ( sizeof( T_2 ) - 1 ) || ! V_34 -> V_38 . V_11 )
goto V_39;
V_34 -> V_38 . V_40 = F_1 ;
V_34 -> V_38 . V_41 = F_18 ;
V_34 -> V_38 . V_42 = V_43 ;
V_34 -> V_38 . exit = V_44 ;
V_34 -> V_38 . V_21 . V_45 = sizeof( struct V_5 ) ;
V_34 -> V_38 . V_21 . V_45 += V_34 -> V_38 . V_11 ;
V_34 -> free = V_46 ;
V_12 = F_26 ( V_30 , V_34 ) ;
if ( V_12 )
goto V_39;
V_47:
return V_12 ;
V_39:
V_46 ( V_34 ) ;
goto V_47;
}
static void F_27 ( struct V_48 * V_34 )
{
V_46 ( V_33 ( V_34 ) ) ;
}
static int T_5 F_28 ( void )
{
return F_29 ( & V_49 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_49 ) ;
}
