static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
F_3 ( V_3 -> V_7 ) ;
F_4 ( V_3 -> V_8 . V_9 ) ;
F_4 ( V_3 -> V_10 . V_9 ) ;
F_5 ( V_5 , V_11 ) ;
}
void F_6 ( struct V_2 * V_3 )
{
F_7 ( & V_3 -> V_1 , F_1 ) ;
}
int F_8 ( struct V_2 * V_3 )
{
return F_9 ( & V_3 -> V_1 ) ;
}
void F_10 ( struct V_2 * V_3 , int V_12 ,
unsigned int V_13 )
{
struct V_4 * V_6 = V_3 -> V_6 ;
struct V_4 * V_14 = V_6 -> V_15 ;
struct V_16 * V_5 = F_11 ( V_6 ) ;
int V_17 ;
V_17 = F_11 ( V_3 -> V_6 ) -> V_12 = V_12 ;
if ( V_17 < 0 )
V_5 -> V_18 = sizeof( V_19 ) ;
else
V_5 -> V_18 = V_3 -> V_20 ;
V_5 -> V_21 = 0 ;
if ( V_14 ) {
F_12 ( V_13 > F_11 ( V_14 ) -> V_21 ) ;
F_11 ( V_14 ) -> V_21 -=
F_13 ( V_13 , F_11 ( V_14 ) -> V_21 ) ;
}
F_14 ( V_6 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_16 ( V_5 ) ;
F_6 ( V_3 ) ;
}
static int F_17 ( struct V_22 * V_23 , struct V_4 * V_6 )
{
T_1 V_24 = ( sizeof( struct V_25 ) * V_6 -> V_26 ) ;
F_18 ( ! V_6 -> V_26 ) ;
V_23 -> V_9 = F_19 ( V_24 , V_27 ) ;
if ( ! V_23 -> V_9 )
return - V_28 ;
F_20 ( V_23 -> V_9 , V_6 -> V_26 ) ;
F_11 ( V_6 ) -> V_21 = F_21 ( V_6 ) ;
V_23 -> V_29 = F_22 ( V_6 -> V_30 , V_6 , V_23 -> V_9 ) ;
V_23 -> V_31 = F_21 ( V_6 ) ;
return 0 ;
}
static int F_23 ( struct V_32 * V_7 , struct V_4 * V_6 )
{
struct V_4 * V_14 = V_6 -> V_15 ;
struct V_16 * V_5 = F_11 ( V_6 ) ;
struct V_2 * V_3 = F_16 ( V_6 ) ;
int V_33 ;
V_3 -> V_4 = V_5 -> V_34 ;
V_3 -> V_35 = V_5 -> V_36 ;
if ( V_6 -> V_37 ) {
V_33 = F_17 ( & V_3 -> V_8 , V_6 ) ;
if ( V_33 )
goto V_38;
}
if ( V_14 && V_14 -> V_37 ) {
V_33 = F_17 ( & V_3 -> V_10 , V_14 ) ;
if ( V_33 )
goto V_39;
}
V_3 -> V_7 = V_7 ;
F_24 ( V_3 -> V_7 ) ;
F_25 ( & V_3 -> V_1 ) ;
return 0 ;
V_39:
F_4 ( V_3 -> V_8 . V_9 ) ;
V_38:
return - V_28 ;
}
static void F_26 ( struct V_40 * V_30 )
__releases( V_30 -> V_41 )
__acquires( V_30 -> V_41 )
{
struct V_32 * V_7 = V_30 -> V_42 ;
struct V_4 * V_6 ;
int V_33 ;
if ( ! F_24 ( V_7 ) )
return;
while ( 1 ) {
V_6 = F_27 ( V_30 ) ;
if ( ! V_6 )
break;
F_28 ( V_30 -> V_41 ) ;
V_33 = F_23 ( V_7 , V_6 ) ;
if ( V_33 ) {
F_11 ( V_6 ) -> V_12 = V_33 ;
F_5 ( V_6 , V_11 ) ;
F_29 ( V_30 -> V_41 ) ;
continue;
}
V_33 = V_30 -> V_43 ( F_16 ( V_6 ) ) ;
F_29 ( V_30 -> V_41 ) ;
if ( V_33 )
break;
}
F_28 ( V_30 -> V_41 ) ;
F_3 ( V_7 ) ;
F_29 ( V_30 -> V_41 ) ;
}
static int F_30 ( struct V_40 * V_30 , struct V_4 * V_6 , T_2 V_44 )
{
struct V_2 * V_3 = F_16 ( V_6 ) ;
struct V_16 * V_45 = & V_3 -> V_45 ;
V_45 -> V_46 = F_19 ( V_47 , V_44 ) ;
if ( ! V_45 -> V_46 )
return - V_28 ;
return 0 ;
}
static void F_31 ( struct V_4 * V_6 )
{
struct V_2 * V_3 = F_16 ( V_6 ) ;
struct V_16 * V_45 = & V_3 -> V_45 ;
void * V_46 = V_45 -> V_46 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_32 ( V_45 ) ;
V_45 -> V_46 = V_46 ;
V_45 -> V_18 = V_47 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_48 = V_46 ;
V_3 -> V_20 = V_45 -> V_18 ;
V_3 -> V_49 = V_3 + 1 ;
}
static void F_33 ( struct V_40 * V_30 , struct V_4 * V_6 )
{
struct V_2 * V_3 = F_16 ( V_6 ) ;
struct V_16 * V_45 = & V_3 -> V_45 ;
F_4 ( V_45 -> V_46 ) ;
}
struct V_40 * F_34 ( struct V_32 * V_7 , const char * V_50 ,
V_43 * V_51 , int V_52 ,
void (* F_35)( struct V_32 * ) )
{
struct V_40 * V_30 ;
int V_33 ;
V_30 = F_36 ( V_27 ) ;
if ( ! V_30 )
return F_37 ( - V_28 ) ;
V_30 -> V_53 = sizeof( struct V_2 ) + V_52 ;
V_30 -> V_54 = F_30 ;
V_30 -> V_55 = F_33 ;
V_30 -> V_56 = F_31 ;
V_30 -> V_57 = F_26 ;
V_33 = F_38 ( V_30 ) ;
if ( V_33 )
goto V_58;
V_30 -> V_42 = V_7 ;
V_30 -> V_43 = V_51 ;
F_39 ( V_59 , V_30 ) ;
F_39 ( V_60 , V_30 ) ;
F_40 ( V_30 , F_15 ) ;
F_41 ( V_30 , V_61 ) ;
V_33 = F_42 ( V_30 , V_7 , V_50 , F_35 ) ;
if ( V_33 ) {
F_43 ( V_62 L_1
L_2 , V_7 -> V_63 . V_50 ) ;
goto V_58;
}
return V_30 ;
V_58:
F_44 ( V_30 ) ;
return F_37 ( V_33 ) ;
}
