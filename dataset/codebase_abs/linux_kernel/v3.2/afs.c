static T_1 F_1 ( void * V_1 , int V_2 )
{
T_1 * V_3 = V_1 ;
T_1 V_4 = 0 ;
while ( V_2 -- )
V_4 += * V_3 ++ ;
return V_4 ;
}
static int
F_2 ( struct V_5 * V_6 , T_2 * V_7 , T_2 * V_8 ,
T_2 V_9 , T_2 V_10 )
{
struct V_11 V_12 ;
T_2 V_13 = V_9 + V_6 -> V_14 - sizeof( V_12 ) ;
T_3 V_15 ;
int V_16 ;
V_16 = V_6 -> V_17 ( V_6 , V_13 , sizeof( V_12 ) , & V_15 , ( V_18 * ) & V_12 ) ;
if ( V_16 >= 0 && V_15 != sizeof( V_12 ) )
V_16 = - V_19 ;
if ( V_16 < 0 ) {
F_3 ( V_20 L_1 ,
V_13 , V_16 ) ;
return V_16 ;
}
V_16 = 1 ;
if ( V_12 . V_21 != 0xa0ffff9f )
V_16 = 0 ;
if ( F_1 ( & V_12 , sizeof( V_12 ) / sizeof( T_1 ) ) != 0xffffffff )
V_16 = 0 ;
if ( V_12 . type == 2 )
V_16 = 0 ;
* V_8 = V_12 . V_22 & V_10 ;
* V_7 = V_12 . V_23 & V_10 ;
if ( * V_8 >= V_13 )
V_16 = 0 ;
if ( * V_7 > V_9 )
V_16 = 0 ;
return V_16 ;
}
static int
F_4 ( struct V_5 * V_6 , struct V_24 * V_25 , T_2 V_13 )
{
T_3 V_15 ;
int V_16 , V_26 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_16 = V_6 -> V_17 ( V_6 , V_13 , sizeof( * V_25 ) , & V_15 , ( V_18 * ) V_25 ) ;
if ( V_16 < 0 )
goto V_27;
if ( V_15 != sizeof( * V_25 ) ) {
V_16 = - V_19 ;
goto V_27;
}
V_16 = 0 ;
for ( V_26 = 0 ; V_26 < sizeof( V_25 -> V_28 ) ; V_26 ++ )
if ( V_25 -> V_28 [ V_26 ] == '\0' )
break;
if ( V_26 < sizeof( V_25 -> V_28 ) )
V_16 = 1 ;
return V_16 ;
V_27:
F_3 ( V_20 L_1 ,
V_13 , V_16 ) ;
return V_16 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_29 * * V_30 ,
struct V_31 * V_32 )
{
struct V_29 * V_33 ;
T_2 V_10 , V_9 , V_34 , V_15 ;
int V_16 = 0 ;
char * V_35 ;
V_10 = V_6 -> V_36 - 1 ;
for ( V_34 = V_9 = V_15 = 0 ; V_9 < V_6 -> V_36 ; V_9 += V_6 -> V_14 ) {
struct V_24 V_25 ;
T_2 V_37 , V_38 ;
V_16 = F_2 ( V_6 , & V_38 , & V_37 , V_9 , V_10 ) ;
if ( V_16 < 0 )
break;
if ( V_16 == 0 )
continue;
V_16 = F_4 ( V_6 , & V_25 , V_37 ) ;
if ( V_16 < 0 )
break;
if ( V_16 == 0 )
continue;
V_15 += sizeof( struct V_29 ) ;
V_15 += strlen ( V_25 . V_28 ) + 1 ;
V_34 += 1 ;
}
if ( ! V_15 )
return V_16 ;
V_33 = F_6 ( V_15 , V_39 ) ;
if ( ! V_33 )
return - V_40 ;
V_35 = ( char * ) ( V_33 + V_34 ) ;
for ( V_34 = V_9 = 0 ; V_9 < V_6 -> V_36 ; V_9 += V_6 -> V_14 ) {
struct V_24 V_25 ;
T_2 V_37 , V_38 ;
V_16 = F_2 ( V_6 , & V_38 , & V_37 , V_9 , V_10 ) ;
if ( V_16 < 0 )
break;
if ( V_16 == 0 )
continue;
V_16 = F_4 ( V_6 , & V_25 , V_37 ) ;
if ( V_16 < 0 )
break;
if ( V_16 == 0 )
continue;
strcpy ( V_35 , V_25 . V_28 ) ;
V_33 [ V_34 ] . V_28 = V_35 ;
V_33 [ V_34 ] . V_36 = ( V_25 . V_41 + V_6 -> V_14 - 1 ) & ~ ( V_6 -> V_14 - 1 ) ;
V_33 [ V_34 ] . V_42 = V_38 ;
V_33 [ V_34 ] . V_43 = 0 ;
F_3 ( L_2 ,
V_34 , V_38 , V_33 [ V_34 ] . V_36 / 1024 ,
V_25 . V_44 , V_35 ) ;
V_34 += 1 ;
V_35 = V_35 + strlen ( V_25 . V_28 ) + 1 ;
}
if ( ! V_34 ) {
F_7 ( V_33 ) ;
V_33 = NULL ;
}
* V_30 = V_33 ;
return V_34 ? V_34 : V_16 ;
}
static int T_4 F_8 ( void )
{
return F_9 ( & V_45 ) ;
}
static void T_5 F_10 ( void )
{
F_11 ( & V_45 ) ;
}
