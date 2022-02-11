static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 . V_5 ) ;
F_3 ( V_2 -> V_6 . V_5 ) ;
F_3 ( V_2 ) ;
}
void F_4 ( struct V_1 * V_2 , int V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_9 * V_11 = V_10 -> V_12 ;
int V_13 ;
V_13 = V_2 -> V_10 -> V_14 = V_7 ;
if ( V_13 < 0 )
V_2 -> V_10 -> V_15 = sizeof( V_16 ) ;
else
V_2 -> V_10 -> V_15 = V_2 -> V_17 ;
V_10 -> V_18 = 0 ;
if ( V_11 ) {
F_5 ( V_8 > V_11 -> V_18 ) ;
V_11 -> V_18 -= F_6 ( V_8 , V_11 -> V_18 ) ;
}
F_7 ( V_10 ) ;
}
static void F_8 ( struct V_9 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_9 ( V_19 , V_19 -> V_14 ) ;
F_1 ( V_2 ) ;
}
static int F_10 ( struct V_21 * V_22 , struct V_9 * V_10 )
{
T_1 V_23 = ( sizeof( struct V_24 ) * V_10 -> V_25 ) ;
F_11 ( ! V_10 -> V_25 ) ;
V_22 -> V_5 = F_12 ( V_23 , V_26 ) ;
if ( ! V_22 -> V_5 )
return - V_27 ;
F_13 ( V_22 -> V_5 , V_10 -> V_25 ) ;
V_22 -> V_28 = F_14 ( V_10 -> V_29 , V_10 , V_22 -> V_5 ) ;
V_22 -> V_30 = F_15 ( V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_31 * V_3 , struct V_9 * V_10 )
{
struct V_9 * V_11 = V_10 -> V_12 ;
struct V_32 * V_29 = V_10 -> V_29 ;
struct V_1 * V_2 ;
int V_33 ;
F_11 ( V_10 -> V_20 ) ;
V_2 = F_12 ( sizeof( struct V_1 ) + V_29 -> V_34 , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_10 -> V_20 = V_2 ;
V_2 -> V_10 = V_10 ;
if ( V_29 -> V_34 )
V_2 -> V_35 = ( void * ) & V_2 [ 1 ] ;
V_2 -> V_9 = V_10 -> V_36 ;
V_2 -> V_37 = V_10 -> V_38 ;
V_2 -> V_39 = V_10 -> V_40 ;
V_2 -> V_17 = V_41 ;
if ( V_10 -> V_42 ) {
V_33 = F_10 ( & V_2 -> V_4 , V_10 ) ;
if ( V_33 )
goto V_43;
}
if ( V_11 && V_11 -> V_42 ) {
V_33 = F_10 ( & V_2 -> V_6 , V_11 ) ;
if ( V_33 )
goto V_44;
}
V_2 -> V_3 = V_3 ;
F_17 ( V_2 -> V_3 ) ;
return 0 ;
V_44:
F_3 ( V_2 -> V_4 . V_5 ) ;
V_43:
F_3 ( V_2 ) ;
return - V_27 ;
}
void F_18 ( struct V_32 * V_29 )
{
if ( ! V_29 )
return;
F_19 ( V_29 ) ;
}
void F_20 ( struct V_32 * V_29 )
{
struct V_31 * V_3 = V_29 -> V_45 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
int V_33 ;
if ( ! F_17 ( V_3 ) )
return;
while ( 1 ) {
V_10 = F_21 ( V_29 ) ;
if ( ! V_10 )
break;
F_22 ( V_29 -> V_46 ) ;
V_33 = F_16 ( V_3 , V_10 ) ;
if ( V_33 ) {
V_10 -> V_14 = V_33 ;
F_9 ( V_10 , V_33 ) ;
F_23 ( V_29 -> V_46 ) ;
continue;
}
V_2 = V_10 -> V_20 ;
V_33 = V_29 -> V_47 ( V_2 ) ;
F_23 ( V_29 -> V_46 ) ;
if ( V_33 )
break;
}
F_22 ( V_29 -> V_46 ) ;
F_2 ( V_3 ) ;
F_23 ( V_29 -> V_46 ) ;
}
int F_24 ( struct V_31 * V_3 , struct V_32 * V_29 ,
char * V_48 , V_47 * V_49 , int V_50 )
{
int V_33 ;
V_29 -> V_45 = V_3 ;
V_29 -> V_34 = V_50 ;
V_29 -> V_47 = V_49 ;
F_25 ( V_51 , V_29 ) ;
F_26 ( V_29 , F_8 ) ;
F_27 ( V_29 , V_52 ) ;
V_33 = F_28 ( V_29 , V_3 , V_48 , NULL ) ;
if ( V_33 ) {
F_29 ( V_53 L_1
L_2 , V_3 -> V_54 . V_48 ) ;
return V_33 ;
}
return 0 ;
}
