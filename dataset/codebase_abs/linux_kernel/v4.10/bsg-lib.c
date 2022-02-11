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
int V_16 ;
V_16 = V_3 -> V_6 -> V_7 = V_12 ;
if ( V_16 < 0 )
V_3 -> V_6 -> V_17 = sizeof( V_18 ) ;
else
V_3 -> V_6 -> V_17 = V_3 -> V_19 ;
V_6 -> V_20 = 0 ;
if ( V_14 ) {
F_11 ( V_13 > V_14 -> V_20 ) ;
V_14 -> V_20 -= F_12 ( V_13 , V_14 -> V_20 ) ;
}
F_13 ( V_6 ) ;
}
static void F_14 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_21 ;
F_6 ( V_3 ) ;
}
static int F_15 ( struct V_22 * V_23 , struct V_4 * V_6 )
{
T_1 V_24 = ( sizeof( struct V_25 ) * V_6 -> V_26 ) ;
F_16 ( ! V_6 -> V_26 ) ;
V_23 -> V_10 = F_17 ( V_24 , V_27 ) ;
if ( ! V_23 -> V_10 )
return - V_28 ;
F_18 ( V_23 -> V_10 , V_6 -> V_26 ) ;
V_23 -> V_29 = F_19 ( V_6 -> V_30 , V_6 , V_23 -> V_10 ) ;
V_23 -> V_31 = F_20 ( V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_32 * V_8 , struct V_4 * V_6 )
{
struct V_4 * V_14 = V_6 -> V_15 ;
struct V_33 * V_30 = V_6 -> V_30 ;
struct V_2 * V_3 ;
int V_34 ;
F_16 ( V_6 -> V_21 ) ;
V_3 = F_17 ( sizeof( struct V_2 ) + V_30 -> V_35 , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
V_6 -> V_21 = V_3 ;
V_3 -> V_6 = V_6 ;
if ( V_30 -> V_35 )
V_3 -> V_36 = ( void * ) & V_3 [ 1 ] ;
V_3 -> V_4 = V_6 -> V_37 ;
V_3 -> V_38 = V_6 -> V_39 ;
V_3 -> V_40 = V_6 -> V_41 ;
V_3 -> V_19 = V_42 ;
if ( V_6 -> V_43 ) {
V_34 = F_15 ( & V_3 -> V_9 , V_6 ) ;
if ( V_34 )
goto V_44;
}
if ( V_14 && V_14 -> V_43 ) {
V_34 = F_15 ( & V_3 -> V_11 , V_14 ) ;
if ( V_34 )
goto V_45;
}
V_3 -> V_8 = V_8 ;
F_22 ( V_3 -> V_8 ) ;
F_23 ( & V_3 -> V_1 ) ;
return 0 ;
V_45:
F_5 ( V_3 -> V_9 . V_10 ) ;
V_44:
F_5 ( V_3 ) ;
return - V_28 ;
}
void F_24 ( struct V_33 * V_30 )
__releases( V_30 -> V_46 )
__acquires( V_30 -> V_46 )
{
struct V_32 * V_8 = V_30 -> V_47 ;
struct V_4 * V_6 ;
struct V_2 * V_3 ;
int V_34 ;
if ( ! F_22 ( V_8 ) )
return;
while ( 1 ) {
V_6 = F_25 ( V_30 ) ;
if ( ! V_6 )
break;
F_26 ( V_30 -> V_46 ) ;
V_34 = F_21 ( V_8 , V_6 ) ;
if ( V_34 ) {
V_6 -> V_7 = V_34 ;
F_3 ( V_6 , V_34 ) ;
F_27 ( V_30 -> V_46 ) ;
continue;
}
V_3 = V_6 -> V_21 ;
V_34 = V_30 -> V_48 ( V_3 ) ;
F_27 ( V_30 -> V_46 ) ;
if ( V_34 )
break;
}
F_26 ( V_30 -> V_46 ) ;
F_4 ( V_8 ) ;
F_27 ( V_30 -> V_46 ) ;
}
int F_28 ( struct V_32 * V_8 , struct V_33 * V_30 ,
char * V_49 , V_48 * V_50 , int V_51 )
{
int V_34 ;
V_30 -> V_47 = V_8 ;
V_30 -> V_35 = V_51 ;
V_30 -> V_48 = V_50 ;
F_29 ( V_52 , V_30 ) ;
F_30 ( V_30 , F_14 ) ;
F_31 ( V_30 , V_53 ) ;
V_34 = F_32 ( V_30 , V_8 , V_49 , NULL ) ;
if ( V_34 ) {
F_33 ( V_54 L_1
L_2 , V_8 -> V_55 . V_49 ) ;
return V_34 ;
}
return 0 ;
}
