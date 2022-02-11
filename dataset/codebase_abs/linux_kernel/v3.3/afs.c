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
V_16 = F_3 ( V_6 , V_13 , sizeof( V_12 ) , & V_15 , ( V_17 * ) & V_12 ) ;
if ( V_16 >= 0 && V_15 != sizeof( V_12 ) )
V_16 = - V_18 ;
if ( V_16 < 0 ) {
F_4 ( V_19 L_1 ,
V_13 , V_16 ) ;
return V_16 ;
}
V_16 = 1 ;
if ( V_12 . V_20 != 0xa0ffff9f )
V_16 = 0 ;
if ( F_1 ( & V_12 , sizeof( V_12 ) / sizeof( T_1 ) ) != 0xffffffff )
V_16 = 0 ;
if ( V_12 . type == 2 )
V_16 = 0 ;
* V_8 = V_12 . V_21 & V_10 ;
* V_7 = V_12 . V_22 & V_10 ;
if ( * V_8 >= V_13 )
V_16 = 0 ;
if ( * V_7 > V_9 )
V_16 = 0 ;
return V_16 ;
}
static int
F_5 ( struct V_5 * V_6 , struct V_23 * V_24 , T_2 V_13 )
{
T_3 V_15 ;
int V_16 , V_25 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_16 = F_3 ( V_6 , V_13 , sizeof( * V_24 ) , & V_15 , ( V_17 * ) V_24 ) ;
if ( V_16 < 0 )
goto V_26;
if ( V_15 != sizeof( * V_24 ) ) {
V_16 = - V_18 ;
goto V_26;
}
V_16 = 0 ;
for ( V_25 = 0 ; V_25 < sizeof( V_24 -> V_27 ) ; V_25 ++ )
if ( V_24 -> V_27 [ V_25 ] == '\0' )
break;
if ( V_25 < sizeof( V_24 -> V_27 ) )
V_16 = 1 ;
return V_16 ;
V_26:
F_4 ( V_19 L_1 ,
V_13 , V_16 ) ;
return V_16 ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_28 * * V_29 ,
struct V_30 * V_31 )
{
struct V_28 * V_32 ;
T_2 V_10 , V_9 , V_33 , V_15 ;
int V_16 = 0 ;
char * V_34 ;
V_10 = V_6 -> V_35 - 1 ;
for ( V_33 = V_9 = V_15 = 0 ; V_9 < V_6 -> V_35 ; V_9 += V_6 -> V_14 ) {
struct V_23 V_24 ;
T_2 V_36 , V_37 ;
V_16 = F_2 ( V_6 , & V_37 , & V_36 , V_9 , V_10 ) ;
if ( V_16 < 0 )
break;
if ( V_16 == 0 )
continue;
V_16 = F_5 ( V_6 , & V_24 , V_36 ) ;
if ( V_16 < 0 )
break;
if ( V_16 == 0 )
continue;
V_15 += sizeof( struct V_28 ) ;
V_15 += strlen ( V_24 . V_27 ) + 1 ;
V_33 += 1 ;
}
if ( ! V_15 )
return V_16 ;
V_32 = F_7 ( V_15 , V_38 ) ;
if ( ! V_32 )
return - V_39 ;
V_34 = ( char * ) ( V_32 + V_33 ) ;
for ( V_33 = V_9 = 0 ; V_9 < V_6 -> V_35 ; V_9 += V_6 -> V_14 ) {
struct V_23 V_24 ;
T_2 V_36 , V_37 ;
V_16 = F_2 ( V_6 , & V_37 , & V_36 , V_9 , V_10 ) ;
if ( V_16 < 0 )
break;
if ( V_16 == 0 )
continue;
V_16 = F_5 ( V_6 , & V_24 , V_36 ) ;
if ( V_16 < 0 )
break;
if ( V_16 == 0 )
continue;
strcpy ( V_34 , V_24 . V_27 ) ;
V_32 [ V_33 ] . V_27 = V_34 ;
V_32 [ V_33 ] . V_35 = ( V_24 . V_40 + V_6 -> V_14 - 1 ) & ~ ( V_6 -> V_14 - 1 ) ;
V_32 [ V_33 ] . V_41 = V_37 ;
V_32 [ V_33 ] . V_42 = 0 ;
F_4 ( L_2 ,
V_33 , V_37 , V_32 [ V_33 ] . V_35 / 1024 ,
V_24 . V_43 , V_34 ) ;
V_33 += 1 ;
V_34 = V_34 + strlen ( V_24 . V_27 ) + 1 ;
}
if ( ! V_33 ) {
F_8 ( V_32 ) ;
V_32 = NULL ;
}
* V_29 = V_32 ;
return V_33 ? V_33 : V_16 ;
}
static int T_4 F_9 ( void )
{
return F_10 ( & V_44 ) ;
}
static void T_5 F_11 ( void )
{
F_12 ( & V_44 ) ;
}
