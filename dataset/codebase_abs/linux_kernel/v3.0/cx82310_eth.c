static int F_1 ( struct V_1 * V_2 , enum F_1 V_3 , bool V_4 ,
T_1 * V_5 , int V_6 , T_1 * V_7 , int V_8 )
{
int V_9 , V_10 , V_11 ;
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 * V_14 = F_2 ( V_15 , V_16 ) ;
if ( ! V_14 )
return - V_17 ;
V_14 [ 0 ] = V_3 ;
if ( V_5 )
memcpy ( V_14 + 4 , V_5 , F_3 ( int , V_6 , V_15 - 4 ) ) ;
V_11 = F_4 ( V_13 , F_5 ( V_13 , V_18 ) , V_14 ,
V_15 , & V_9 , V_19 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_2 -> V_13 -> V_2 , L_1 ,
V_3 , V_11 ) ;
goto V_20;
}
if ( V_4 ) {
for ( V_10 = 0 ; V_10 < V_21 ; V_10 ++ ) {
V_11 = F_4 ( V_13 , F_7 ( V_13 , V_18 ) ,
V_14 , V_15 , & V_9 ,
V_19 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_2 -> V_13 -> V_2 ,
L_2 , V_11 ) ;
goto V_20;
}
if ( V_9 > 0 )
break;
}
if ( V_9 == 0 ) {
F_6 ( & V_2 -> V_13 -> V_2 , L_3 ,
V_3 ) ;
V_11 = - V_22 ;
goto V_20;
}
if ( V_14 [ 0 ] != V_3 ) {
F_6 ( & V_2 -> V_13 -> V_2 ,
L_4 ,
V_14 [ 0 ] , V_3 ) ;
V_11 = - V_22 ;
goto V_20;
}
if ( V_14 [ 1 ] != V_23 ) {
F_6 ( & V_2 -> V_13 -> V_2 , L_5 ,
V_3 , V_14 [ 1 ] ) ;
V_11 = - V_22 ;
goto V_20;
}
if ( V_7 )
memcpy ( V_7 , V_14 + 4 ,
F_3 ( int , V_8 , V_15 - 4 ) ) ;
}
V_20:
F_8 ( V_14 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_11 ;
char V_14 [ 15 ] ;
struct V_12 * V_13 = V_2 -> V_13 ;
if ( F_10 ( V_13 , V_13 -> V_26 . V_27 , V_14 , sizeof( V_14 ) ) > 0
&& strcmp ( V_14 , L_6 ) ) {
F_11 ( & V_13 -> V_2 , L_7 ) ;
return - V_28 ;
}
V_11 = F_12 ( V_2 , V_25 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_29 -> V_30 = 0 ;
V_2 -> V_31 = V_32 + 2 ;
V_2 -> V_33 = 4096 ;
V_2 -> V_34 = ( unsigned long ) F_13 ( V_2 -> V_31 , V_16 ) ;
if ( ! V_2 -> V_34 )
return - V_17 ;
V_11 = F_1 ( V_2 , V_35 , true , L_8 , 1 , NULL , 0 ) ;
if ( V_11 ) {
F_6 ( & V_13 -> V_2 , L_9 ,
V_11 ) ;
goto V_36;
}
V_11 = F_1 ( V_2 , V_37 , true , NULL , 0 ,
V_2 -> V_29 -> V_38 , V_39 ) ;
if ( V_11 ) {
F_6 ( & V_13 -> V_2 , L_10 , V_11 ) ;
goto V_36;
}
V_11 = F_1 ( V_2 , V_40 , false , NULL , 0 , NULL , 0 ) ;
if ( V_11 )
goto V_36;
return 0 ;
V_36:
F_8 ( ( void * ) V_2 -> V_34 ) ;
return V_11 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
F_8 ( ( void * ) V_2 -> V_34 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_43 ;
struct V_41 * V_44 ;
if ( V_2 -> V_45 ) {
V_43 = V_2 -> V_46 + V_2 -> V_45 ;
V_44 = F_16 ( V_43 , V_47 ) ;
if ( ! V_44 )
return 0 ;
F_17 ( V_44 , V_43 ) ;
memcpy ( V_44 -> V_48 , ( void * ) V_2 -> V_34 ,
V_2 -> V_46 ) ;
memcpy ( V_44 -> V_48 + V_2 -> V_46 , V_42 -> V_48 ,
V_2 -> V_45 ) ;
F_18 ( V_2 , V_44 ) ;
F_19 ( V_42 , ( V_2 -> V_45 + 1 ) & ~ 1 ) ;
V_2 -> V_45 = 0 ;
if ( V_42 -> V_43 < 2 )
return 1 ;
}
while ( V_42 -> V_43 > 1 ) {
V_43 = V_42 -> V_48 [ 0 ] | ( V_42 -> V_48 [ 1 ] << 8 ) ;
F_19 ( V_42 , 2 ) ;
if ( V_43 == V_42 -> V_43 || V_43 + 1 == V_42 -> V_43 ) {
F_20 ( V_42 , V_43 ) ;
break;
}
if ( V_43 > V_32 ) {
F_6 ( & V_2 -> V_13 -> V_2 , L_11 ,
V_43 ) ;
return 0 ;
}
if ( V_43 > V_42 -> V_43 ) {
V_2 -> V_46 = V_42 -> V_43 ;
V_2 -> V_45 = V_43 - V_42 -> V_43 ;
memcpy ( ( void * ) V_2 -> V_34 , V_42 -> V_48 ,
V_2 -> V_46 ) ;
F_19 ( V_42 , V_42 -> V_43 ) ;
break;
}
V_44 = F_16 ( V_43 , V_47 ) ;
if ( ! V_44 )
return 0 ;
F_17 ( V_44 , V_43 ) ;
memcpy ( V_44 -> V_48 , V_42 -> V_48 , V_43 ) ;
F_18 ( V_2 , V_44 ) ;
F_19 ( V_42 , ( V_43 + 1 ) & ~ 1 ) ;
}
return 1 ;
}
static struct V_41 * F_21 ( struct V_1 * V_2 , struct V_41 * V_42 ,
T_2 V_49 )
{
int V_43 = V_42 -> V_43 ;
if ( F_22 ( V_42 ) < 2 ) {
struct V_41 * V_44 = F_23 ( V_42 , 2 , 0 , V_49 ) ;
F_24 ( V_42 ) ;
V_42 = V_44 ;
if ( ! V_42 )
return NULL ;
}
F_25 ( V_42 , 2 ) ;
V_42 -> V_48 [ 0 ] = V_43 ;
V_42 -> V_48 [ 1 ] = V_43 >> 8 ;
return V_42 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_50 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_50 ) ;
}
