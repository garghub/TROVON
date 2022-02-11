static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
F_3 ( V_5 , V_5 -> V_7 ) ;
F_4 ( V_3 -> V_8 ) ;
F_5 ( V_3 -> V_9 . V_10 ) ;
F_5 ( V_3 -> V_11 . V_10 ) ;
F_5 ( V_3 ) ;
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
V_17 = V_3 -> V_6 -> V_7 = V_12 ;
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
struct V_2 * V_3 = V_5 -> V_22 ;
F_6 ( V_3 ) ;
}
static int F_16 ( struct V_23 * V_24 , struct V_4 * V_6 )
{
T_1 V_25 = ( sizeof( struct V_26 ) * V_6 -> V_27 ) ;
F_17 ( ! V_6 -> V_27 ) ;
V_24 -> V_10 = F_18 ( V_25 , V_28 ) ;
if ( ! V_24 -> V_10 )
return - V_29 ;
F_19 ( V_24 -> V_10 , V_6 -> V_27 ) ;
F_11 ( V_6 ) -> V_21 = F_20 ( V_6 ) ;
V_24 -> V_30 = F_21 ( V_6 -> V_31 , V_6 , V_24 -> V_10 ) ;
V_24 -> V_32 = F_20 ( V_6 ) ;
return 0 ;
}
static int F_22 ( struct V_33 * V_8 , struct V_4 * V_6 )
{
struct V_4 * V_14 = V_6 -> V_15 ;
struct V_34 * V_31 = V_6 -> V_31 ;
struct V_16 * V_5 = F_11 ( V_6 ) ;
struct V_2 * V_3 ;
int V_35 ;
F_17 ( V_6 -> V_22 ) ;
V_3 = F_18 ( sizeof( struct V_2 ) + V_31 -> V_36 , V_28 ) ;
if ( ! V_3 )
return - V_29 ;
V_6 -> V_22 = V_3 ;
V_3 -> V_6 = V_6 ;
if ( V_31 -> V_36 )
V_3 -> V_37 = ( void * ) & V_3 [ 1 ] ;
V_3 -> V_4 = V_5 -> V_38 ;
V_3 -> V_39 = V_5 -> V_40 ;
V_3 -> V_41 = V_5 -> V_42 ;
V_3 -> V_20 = V_43 ;
if ( V_6 -> V_44 ) {
V_35 = F_16 ( & V_3 -> V_9 , V_6 ) ;
if ( V_35 )
goto V_45;
}
if ( V_14 && V_14 -> V_44 ) {
V_35 = F_16 ( & V_3 -> V_11 , V_14 ) ;
if ( V_35 )
goto V_46;
}
V_3 -> V_8 = V_8 ;
F_23 ( V_3 -> V_8 ) ;
F_24 ( & V_3 -> V_1 ) ;
return 0 ;
V_46:
F_5 ( V_3 -> V_9 . V_10 ) ;
V_45:
F_5 ( V_3 ) ;
return - V_29 ;
}
static void F_25 ( struct V_34 * V_31 )
__releases( V_31 -> V_47 )
__acquires( V_31 -> V_47 )
{
struct V_33 * V_8 = V_31 -> V_48 ;
struct V_4 * V_6 ;
struct V_2 * V_3 ;
int V_35 ;
if ( ! F_23 ( V_8 ) )
return;
while ( 1 ) {
V_6 = F_26 ( V_31 ) ;
if ( ! V_6 )
break;
F_27 ( V_31 -> V_47 ) ;
V_35 = F_22 ( V_8 , V_6 ) ;
if ( V_35 ) {
V_6 -> V_7 = V_35 ;
F_3 ( V_6 , V_35 ) ;
F_28 ( V_31 -> V_47 ) ;
continue;
}
V_3 = V_6 -> V_22 ;
V_35 = V_31 -> V_49 ( V_3 ) ;
F_28 ( V_31 -> V_47 ) ;
if ( V_35 )
break;
}
F_27 ( V_31 -> V_47 ) ;
F_4 ( V_8 ) ;
F_28 ( V_31 -> V_47 ) ;
}
struct V_34 * F_29 ( struct V_33 * V_8 , char * V_50 ,
V_49 * V_51 , int V_52 )
{
struct V_34 * V_31 ;
int V_35 ;
V_31 = F_30 ( V_28 ) ;
if ( ! V_31 )
return F_31 ( - V_29 ) ;
V_31 -> V_53 = sizeof( struct V_16 ) ;
V_31 -> V_54 = F_25 ;
V_35 = F_32 ( V_31 ) ;
if ( V_35 )
goto V_55;
V_31 -> V_48 = V_8 ;
V_31 -> V_36 = V_52 ;
V_31 -> V_49 = V_51 ;
F_33 ( V_56 , V_31 ) ;
F_34 ( V_31 , F_15 ) ;
F_35 ( V_31 , V_57 ) ;
V_35 = F_36 ( V_31 , V_8 , V_50 , NULL ) ;
if ( V_35 ) {
F_37 ( V_58 L_1
L_2 , V_8 -> V_59 . V_50 ) ;
goto V_55;
}
return V_31 ;
V_55:
F_38 ( V_31 ) ;
return F_31 ( V_35 ) ;
}
