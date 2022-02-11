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
if ( V_3 != V_20 )
F_6 ( & V_2 -> V_13 -> V_2 , L_1 ,
V_3 , V_11 ) ;
goto V_21;
}
if ( V_4 ) {
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ ) {
V_11 = F_4 ( V_13 , F_7 ( V_13 , V_18 ) ,
V_14 , V_15 , & V_9 ,
V_19 ) ;
if ( V_11 < 0 ) {
if ( V_3 != V_20 )
F_6 ( & V_2 -> V_13 -> V_2 ,
L_2 ,
V_11 ) ;
goto V_21;
}
if ( V_9 > 0 )
break;
}
if ( V_9 == 0 ) {
F_6 ( & V_2 -> V_13 -> V_2 , L_3 ,
V_3 ) ;
V_11 = - V_23 ;
goto V_21;
}
if ( V_14 [ 0 ] != V_3 ) {
F_6 ( & V_2 -> V_13 -> V_2 ,
L_4 ,
V_14 [ 0 ] , V_3 ) ;
V_11 = - V_23 ;
goto V_21;
}
if ( V_14 [ 1 ] != V_24 ) {
F_6 ( & V_2 -> V_13 -> V_2 , L_5 ,
V_3 , V_14 [ 1 ] ) ;
V_11 = - V_23 ;
goto V_21;
}
if ( V_7 )
memcpy ( V_7 , V_14 + 4 ,
F_3 ( int , V_8 , V_15 - 4 ) ) ;
}
V_21:
F_8 ( V_14 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_11 ;
char V_14 [ 15 ] ;
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_27 [ 3 ] ;
int V_28 = 50 ;
if ( F_10 ( V_13 , V_13 -> V_29 . V_30 , V_14 , sizeof( V_14 ) ) > 0
&& strcmp ( V_14 , L_6 ) ) {
F_11 ( & V_13 -> V_2 , L_7 ) ;
return - V_31 ;
}
V_11 = F_12 ( V_2 , V_26 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_32 -> V_33 = 0 ;
V_2 -> V_34 = V_35 + 2 ;
V_2 -> V_36 = 4096 ;
V_2 -> V_37 = ( unsigned long ) F_13 ( V_2 -> V_34 , V_16 ) ;
if ( ! V_2 -> V_37 )
return - V_17 ;
while ( -- V_28 ) {
V_11 = F_1 ( V_2 , V_20 , true , NULL , 0 ,
V_27 , sizeof( V_27 ) ) ;
if ( ! V_11 && V_27 [ 0 ] == 1 && V_27 [ 2 ] == 1 )
break;
F_14 ( 500 ) ;
}
if ( ! V_28 ) {
F_6 ( & V_13 -> V_2 , L_8 ) ;
return - V_38 ;
}
V_11 = F_1 ( V_2 , V_39 , true , L_9 , 1 , NULL , 0 ) ;
if ( V_11 ) {
F_6 ( & V_13 -> V_2 , L_10 ,
V_11 ) ;
goto V_40;
}
V_11 = F_1 ( V_2 , V_41 , true , NULL , 0 ,
V_2 -> V_32 -> V_42 , V_43 ) ;
if ( V_11 ) {
F_6 ( & V_13 -> V_2 , L_11 , V_11 ) ;
goto V_40;
}
V_11 = F_1 ( V_2 , V_44 , false , NULL , 0 , NULL , 0 ) ;
if ( V_11 )
goto V_40;
return 0 ;
V_40:
F_8 ( ( void * ) V_2 -> V_37 ) ;
return V_11 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
F_8 ( ( void * ) V_2 -> V_37 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
int V_47 ;
struct V_45 * V_48 ;
if ( V_2 -> V_49 ) {
V_47 = V_2 -> V_50 + V_2 -> V_49 ;
V_48 = F_17 ( V_47 , V_51 ) ;
if ( ! V_48 )
return 0 ;
F_18 ( V_48 , V_47 ) ;
memcpy ( V_48 -> V_52 , ( void * ) V_2 -> V_37 ,
V_2 -> V_50 ) ;
memcpy ( V_48 -> V_52 + V_2 -> V_50 , V_46 -> V_52 ,
V_2 -> V_49 ) ;
F_19 ( V_2 , V_48 ) ;
F_20 ( V_46 , ( V_2 -> V_49 + 1 ) & ~ 1 ) ;
V_2 -> V_49 = 0 ;
if ( V_46 -> V_47 < 2 )
return 1 ;
}
while ( V_46 -> V_47 > 1 ) {
V_47 = V_46 -> V_52 [ 0 ] | ( V_46 -> V_52 [ 1 ] << 8 ) ;
F_20 ( V_46 , 2 ) ;
if ( V_47 == V_46 -> V_47 || V_47 + 1 == V_46 -> V_47 ) {
F_21 ( V_46 , V_47 ) ;
break;
}
if ( V_47 > V_35 ) {
F_6 ( & V_2 -> V_13 -> V_2 , L_12 ,
V_47 ) ;
return 0 ;
}
if ( V_47 > V_46 -> V_47 ) {
V_2 -> V_50 = V_46 -> V_47 ;
V_2 -> V_49 = V_47 - V_46 -> V_47 ;
memcpy ( ( void * ) V_2 -> V_37 , V_46 -> V_52 ,
V_2 -> V_50 ) ;
F_20 ( V_46 , V_46 -> V_47 ) ;
break;
}
V_48 = F_17 ( V_47 , V_51 ) ;
if ( ! V_48 )
return 0 ;
F_18 ( V_48 , V_47 ) ;
memcpy ( V_48 -> V_52 , V_46 -> V_52 , V_47 ) ;
F_19 ( V_2 , V_48 ) ;
F_20 ( V_46 , ( V_47 + 1 ) & ~ 1 ) ;
}
return 1 ;
}
static struct V_45 * F_22 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_2 V_53 )
{
int V_47 = V_46 -> V_47 ;
if ( F_23 ( V_46 , 2 ) ) {
F_24 ( V_46 ) ;
return NULL ;
}
F_25 ( V_46 , 2 ) ;
V_46 -> V_52 [ 0 ] = V_47 ;
V_46 -> V_52 [ 1 ] = V_47 >> 8 ;
return V_46 ;
}
