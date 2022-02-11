static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 , T_1 V_7 , T_1 V_8 ,
int V_9 )
{
void * V_10 ;
int V_11 ;
V_10 = F_2 ( V_2 , V_7 , V_8 , & V_12 , V_9 , V_6 ) ;
if ( ! V_10 )
return - V_13 ;
V_11 = F_3 ( V_2 , V_14 , V_4 -> V_15 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_3 ( V_2 , V_16 , V_4 -> V_17 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_3 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( V_11 < 0 )
goto error;
F_4 ( V_2 , V_10 ) ;
return 0 ;
error:
F_5 ( V_2 , V_10 ) ;
return - V_13 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_3 * V_4 ;
int V_21 = V_20 -> args [ 0 ] ;
int V_22 = 0 ;
int V_23 ;
F_7 ( & V_24 ) ;
F_8 (group, &psample_groups_list, list) {
if ( ! F_9 ( V_4 -> V_25 , F_10 ( V_2 -> V_26 ) ) )
continue;
if ( V_22 < V_21 ) {
V_22 ++ ;
continue;
}
V_23 = F_1 ( V_2 , V_4 , V_27 ,
F_11 ( V_20 -> V_28 ) . V_7 ,
V_20 -> V_29 -> V_30 , V_31 ) ;
if ( V_23 )
break;
V_22 ++ ;
}
F_12 ( & V_24 ) ;
V_20 -> args [ 0 ] = V_22 ;
return V_2 -> V_32 ;
}
static void F_13 ( struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_2 ;
int V_23 ;
V_2 = F_14 ( V_33 , V_34 ) ;
if ( ! V_2 )
return;
V_23 = F_1 ( V_2 , V_4 , V_6 , 0 , 0 , V_31 ) ;
if ( ! V_23 )
F_15 ( & V_12 , V_4 -> V_25 , V_2 , 0 ,
V_35 , V_34 ) ;
else
F_16 ( V_2 ) ;
}
static struct V_3 * F_17 ( struct V_25 * V_25 ,
T_1 V_15 )
{
struct V_3 * V_4 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_34 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_25 = V_25 ;
V_4 -> V_15 = V_15 ;
F_19 ( & V_4 -> V_36 , & V_37 ) ;
F_13 ( V_4 , V_27 ) ;
return V_4 ;
}
static void F_20 ( struct V_3 * V_4 )
{
F_13 ( V_4 , V_38 ) ;
F_21 ( & V_4 -> V_36 ) ;
F_22 ( V_4 ) ;
}
static struct V_3 *
F_23 ( struct V_25 * V_25 , T_1 V_15 )
{
struct V_3 * V_4 ;
F_8 (group, &psample_groups_list, list)
if ( ( V_4 -> V_15 == V_15 ) && ( V_4 -> V_25 == V_25 ) )
return V_4 ;
return NULL ;
}
struct V_3 * F_24 ( struct V_25 * V_25 , T_1 V_15 )
{
struct V_3 * V_4 ;
F_7 ( & V_24 ) ;
V_4 = F_23 ( V_25 , V_15 ) ;
if ( ! V_4 ) {
V_4 = F_17 ( V_25 , V_15 ) ;
if ( ! V_4 )
goto V_39;
}
V_4 -> V_17 ++ ;
V_39:
F_12 ( & V_24 ) ;
return V_4 ;
}
void F_25 ( struct V_3 * V_4 )
{
F_7 ( & V_24 ) ;
if ( -- V_4 -> V_17 == 0 )
F_20 ( V_4 ) ;
F_12 ( & V_24 ) ;
}
void F_26 ( struct V_3 * V_4 , struct V_1 * V_28 ,
T_1 V_40 , int V_41 , int V_42 ,
T_1 V_43 )
{
struct V_1 * V_44 ;
int V_45 ;
int V_46 ;
void * V_47 ;
int V_11 ;
V_46 = ( V_41 ? F_27 ( sizeof( V_48 ) ) : 0 ) +
( V_42 ? F_27 ( sizeof( V_48 ) ) : 0 ) +
F_27 ( sizeof( T_1 ) ) +
F_27 ( sizeof( T_1 ) ) +
F_27 ( sizeof( T_1 ) ) +
F_27 ( sizeof( T_1 ) ) ;
V_45 = F_28 ( V_28 -> V_32 , V_40 ) ;
if ( V_46 + F_27 ( V_45 ) > V_49 )
V_45 = V_49 - V_46 - V_50
- V_51 ;
V_44 = F_29 ( V_46 + V_45 , V_34 ) ;
if ( F_30 ( ! V_44 ) )
return;
V_47 = F_2 ( V_44 , 0 , 0 , & V_12 , 0 ,
V_52 ) ;
if ( F_30 ( ! V_47 ) )
goto error;
if ( V_41 ) {
V_11 = F_31 ( V_44 , V_53 , V_41 ) ;
if ( F_30 ( V_11 < 0 ) )
goto error;
}
if ( V_42 ) {
V_11 = F_31 ( V_44 , V_54 , V_42 ) ;
if ( F_30 ( V_11 < 0 ) )
goto error;
}
V_11 = F_3 ( V_44 , V_55 , V_43 ) ;
if ( F_30 ( V_11 < 0 ) )
goto error;
V_11 = F_3 ( V_44 , V_56 , V_28 -> V_32 ) ;
if ( F_30 ( V_11 < 0 ) )
goto error;
V_11 = F_3 ( V_44 , V_14 , V_4 -> V_15 ) ;
if ( F_30 ( V_11 < 0 ) )
goto error;
V_11 = F_3 ( V_44 , V_18 , V_4 -> V_8 ++ ) ;
if ( F_30 ( V_11 < 0 ) )
goto error;
if ( V_45 ) {
int V_57 = F_27 ( V_45 ) ;
struct V_58 * V_59 ;
V_59 = (struct V_58 * ) F_32 ( V_44 , V_57 ) ;
V_59 -> V_60 = V_61 ;
V_59 -> V_57 = F_33 ( V_45 ) ;
if ( F_34 ( V_28 , 0 , F_35 ( V_59 ) , V_45 ) )
goto error;
}
F_4 ( V_44 , V_47 ) ;
F_15 ( & V_12 , V_4 -> V_25 , V_44 , 0 ,
V_62 , V_34 ) ;
return;
error:
F_36 ( L_1 ) ;
F_16 ( V_44 ) ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_12 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_12 ) ;
}
