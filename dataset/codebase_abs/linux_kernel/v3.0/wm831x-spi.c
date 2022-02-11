static int F_1 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , void * V_4 )
{
T_1 V_5 ;
T_1 * V_6 = V_4 ;
int V_7 , V_8 ;
for ( V_7 = V_2 ; V_7 < V_2 + ( V_3 / 2 ) ; V_7 ++ ) {
V_5 = V_7 | 0x8000 ;
V_8 = F_2 ( V_1 -> V_9 ,
( V_10 * ) & V_5 , 2 , ( V_10 * ) V_6 , 2 ) ;
if ( V_8 != 0 )
return V_8 ;
* V_6 = F_3 ( * V_6 ) ;
V_6 ++ ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , void * V_11 )
{
struct V_12 * V_13 = V_1 -> V_9 ;
T_1 * V_14 = V_11 ;
T_1 V_15 [ 2 ] ;
int V_8 , V_7 ;
for ( V_7 = V_2 ; V_7 < V_2 + ( V_3 / 2 ) ; V_7 ++ ) {
V_15 [ 0 ] = V_7 ;
V_15 [ 1 ] = * V_14 ++ ;
V_8 = F_5 ( V_13 , ( char * ) & V_15 , sizeof( V_15 ) ) ;
if ( V_8 != 0 )
return V_8 ;
}
return 0 ;
}
static int T_2 F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_1 ;
enum V_16 type ;
if ( strcmp ( V_13 -> V_17 , L_1 ) == 0 )
type = V_18 ;
else if ( strcmp ( V_13 -> V_17 , L_2 ) == 0 )
type = V_19 ;
else if ( strcmp ( V_13 -> V_17 , L_3 ) == 0 )
type = V_20 ;
else if ( strcmp ( V_13 -> V_17 , L_4 ) == 0 )
type = V_21 ;
else if ( strcmp ( V_13 -> V_17 , L_5 ) == 0 )
type = V_22 ;
else if ( strcmp ( V_13 -> V_17 , L_6 ) == 0 )
type = V_23 ;
else if ( strcmp ( V_13 -> V_17 , L_7 ) == 0 )
type = V_24 ;
else {
F_7 ( & V_13 -> V_25 , L_8 ) ;
return - V_26 ;
}
V_1 = F_8 ( sizeof( struct V_1 ) , V_27 ) ;
if ( V_1 == NULL )
return - V_28 ;
V_13 -> V_29 = 16 ;
V_13 -> V_30 = V_31 ;
F_9 ( & V_13 -> V_25 , V_1 ) ;
V_1 -> V_25 = & V_13 -> V_25 ;
V_1 -> V_9 = V_13 ;
V_1 -> V_32 = F_1 ;
V_1 -> V_33 = F_4 ;
return F_10 ( V_1 , type , V_13 -> V_34 ) ;
}
static int T_3 F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_12 ( & V_13 -> V_25 ) ;
F_13 ( V_1 ) ;
return 0 ;
}
static int F_14 ( struct V_35 * V_25 )
{
struct V_1 * V_1 = F_12 ( V_25 ) ;
return F_15 ( V_1 ) ;
}
static int T_4 F_16 ( void )
{
int V_8 ;
V_8 = F_17 ( & V_36 ) ;
if ( V_8 != 0 )
F_18 ( L_9 , V_8 ) ;
V_8 = F_17 ( & V_37 ) ;
if ( V_8 != 0 )
F_18 ( L_10 , V_8 ) ;
V_8 = F_17 ( & V_38 ) ;
if ( V_8 != 0 )
F_18 ( L_11 , V_8 ) ;
V_8 = F_17 ( & V_39 ) ;
if ( V_8 != 0 )
F_18 ( L_12 , V_8 ) ;
V_8 = F_17 ( & V_40 ) ;
if ( V_8 != 0 )
F_18 ( L_13 , V_8 ) ;
V_8 = F_17 ( & V_41 ) ;
if ( V_8 != 0 )
F_18 ( L_14 , V_8 ) ;
V_8 = F_17 ( & V_42 ) ;
if ( V_8 != 0 )
F_18 ( L_15 , V_8 ) ;
return 0 ;
}
static void T_5 F_19 ( void )
{
F_20 ( & V_42 ) ;
F_20 ( & V_41 ) ;
F_20 ( & V_40 ) ;
F_20 ( & V_39 ) ;
F_20 ( & V_38 ) ;
F_20 ( & V_37 ) ;
F_20 ( & V_36 ) ;
}
