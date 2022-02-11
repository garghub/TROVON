static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
F_3 ( V_5 , F_4 ( V_5 ) -> V_7 ) ;
F_5 ( V_3 -> V_8 ) ;
F_6 ( V_3 -> V_9 . V_10 ) ;
F_6 ( V_3 -> V_11 . V_10 ) ;
F_6 ( V_3 ) ;
}
void F_7 ( struct V_2 * V_3 )
{
F_8 ( & V_3 -> V_1 , F_1 ) ;
}
int F_9 ( struct V_2 * V_3 )
{
return F_10 ( & V_3 -> V_1 ) ;
}
void F_11 ( struct V_2 * V_3 , int V_7 ,
unsigned int V_12 )
{
struct V_4 * V_6 = V_3 -> V_6 ;
struct V_4 * V_13 = V_6 -> V_14 ;
struct V_15 * V_5 = F_4 ( V_6 ) ;
int V_16 ;
V_16 = F_4 ( V_3 -> V_6 ) -> V_7 = V_7 ;
if ( V_16 < 0 )
V_5 -> V_17 = sizeof( V_18 ) ;
else
V_5 -> V_17 = V_3 -> V_19 ;
V_5 -> V_20 = 0 ;
if ( V_13 ) {
F_12 ( V_12 > F_4 ( V_13 ) -> V_20 ) ;
F_4 ( V_13 ) -> V_20 -=
F_13 ( V_12 , F_4 ( V_13 ) -> V_20 ) ;
}
F_14 ( V_6 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_21 ;
F_7 ( V_3 ) ;
}
static int F_16 ( struct V_22 * V_23 , struct V_4 * V_6 )
{
T_1 V_24 = ( sizeof( struct V_25 ) * V_6 -> V_26 ) ;
F_17 ( ! V_6 -> V_26 ) ;
V_23 -> V_10 = F_18 ( V_24 , V_27 ) ;
if ( ! V_23 -> V_10 )
return - V_28 ;
F_19 ( V_23 -> V_10 , V_6 -> V_26 ) ;
F_4 ( V_6 ) -> V_20 = F_20 ( V_6 ) ;
V_23 -> V_29 = F_21 ( V_6 -> V_30 , V_6 , V_23 -> V_10 ) ;
V_23 -> V_31 = F_20 ( V_6 ) ;
return 0 ;
}
static int F_22 ( struct V_32 * V_8 , struct V_4 * V_6 )
{
struct V_4 * V_13 = V_6 -> V_14 ;
struct V_33 * V_30 = V_6 -> V_30 ;
struct V_15 * V_5 = F_4 ( V_6 ) ;
struct V_2 * V_3 ;
int V_34 ;
F_17 ( V_6 -> V_21 ) ;
V_3 = F_18 ( sizeof( struct V_2 ) + V_30 -> V_35 , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
V_6 -> V_21 = V_3 ;
V_3 -> V_6 = V_6 ;
if ( V_30 -> V_35 )
V_3 -> V_36 = ( void * ) & V_3 [ 1 ] ;
V_3 -> V_4 = V_5 -> V_37 ;
V_3 -> V_38 = V_5 -> V_39 ;
V_3 -> V_40 = V_5 -> V_41 ;
V_3 -> V_19 = V_42 ;
if ( V_6 -> V_43 ) {
V_34 = F_16 ( & V_3 -> V_9 , V_6 ) ;
if ( V_34 )
goto V_44;
}
if ( V_13 && V_13 -> V_43 ) {
V_34 = F_16 ( & V_3 -> V_11 , V_13 ) ;
if ( V_34 )
goto V_45;
}
V_3 -> V_8 = V_8 ;
F_23 ( V_3 -> V_8 ) ;
F_24 ( & V_3 -> V_1 ) ;
return 0 ;
V_45:
F_6 ( V_3 -> V_9 . V_10 ) ;
V_44:
F_6 ( V_3 ) ;
return - V_28 ;
}
static void F_25 ( struct V_33 * V_30 )
__releases( V_30 -> V_46 )
__acquires( V_30 -> V_46 )
{
struct V_32 * V_8 = V_30 -> V_47 ;
struct V_4 * V_6 ;
struct V_2 * V_3 ;
int V_34 ;
if ( ! F_23 ( V_8 ) )
return;
while ( 1 ) {
V_6 = F_26 ( V_30 ) ;
if ( ! V_6 )
break;
F_27 ( V_30 -> V_46 ) ;
V_34 = F_22 ( V_8 , V_6 ) ;
if ( V_34 ) {
F_4 ( V_6 ) -> V_7 = V_34 ;
F_3 ( V_6 , V_34 ) ;
F_28 ( V_30 -> V_46 ) ;
continue;
}
V_3 = V_6 -> V_21 ;
V_34 = V_30 -> V_48 ( V_3 ) ;
F_28 ( V_30 -> V_46 ) ;
if ( V_34 )
break;
}
F_27 ( V_30 -> V_46 ) ;
F_5 ( V_8 ) ;
F_28 ( V_30 -> V_46 ) ;
}
struct V_33 * F_29 ( struct V_32 * V_8 , char * V_49 ,
V_48 * V_50 , int V_51 )
{
struct V_33 * V_30 ;
int V_34 ;
V_30 = F_30 ( V_27 ) ;
if ( ! V_30 )
return F_31 ( - V_28 ) ;
V_30 -> V_52 = sizeof( struct V_15 ) ;
V_30 -> V_53 = F_25 ;
V_34 = F_32 ( V_30 ) ;
if ( V_34 )
goto V_54;
V_30 -> V_47 = V_8 ;
V_30 -> V_35 = V_51 ;
V_30 -> V_48 = V_50 ;
F_33 ( V_55 , V_30 ) ;
F_34 ( V_30 , F_15 ) ;
F_35 ( V_30 , V_56 ) ;
V_34 = F_36 ( V_30 , V_8 , V_49 , NULL ) ;
if ( V_34 ) {
F_37 ( V_57 L_1
L_2 , V_8 -> V_58 . V_49 ) ;
goto V_54;
}
return V_30 ;
V_54:
F_38 ( V_30 ) ;
return F_31 ( V_34 ) ;
}
