static int F_1 ( const T_1 * V_1 , char * V_2 , T_2 V_3 ,
T_2 V_4 )
{
int V_5 , V_6 = 0 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_6 += snprintf ( V_2 + V_6 , V_3 - V_6 - 1 ,
L_1 , F_2 ( V_1 [ V_5 ] ) & 0xFFFF ) ;
V_6 += snprintf ( V_2 + V_6 , V_3 - V_6 - 1 , L_2 ) ;
return V_6 + 1 ;
}
static int F_3 ( T_1 * V_1 , const char * V_7 , T_2 V_8 ,
T_2 V_4 )
{
char V_9 , V_10 [ 5 ] = { 0 } ;
int V_11 , V_12 = 0 ;
unsigned long V_13 ;
while ( V_8 ) {
V_9 = V_7 [ V_8 - 1 ] ;
if ( ! isspace ( V_9 ) && V_9 != '\0' )
break;
V_8 -- ;
}
if ( V_8 != V_4 * 4 )
return - V_14 ;
while ( V_12 < V_4 ) {
memcpy ( V_10 , V_7 , 4 ) ;
V_7 += 4 ;
V_11 = F_4 ( V_10 , 16 , & V_13 ) ;
if ( V_11 )
return V_11 ;
V_1 [ V_12 ++ ] = F_2 ( ( T_1 ) V_13 ) ;
}
return 0 ;
}
T_3 F_5 ( struct V_15 * V_16 , char * V_2 ,
int (* F_6)( struct V_15 * V_16 , T_1 * V_1 ) )
{
T_1 * V_1 ;
int V_11 = - V_17 ;
T_3 V_18 = 0 ;
T_2 V_4 = V_16 -> V_19 ;
V_1 = F_7 ( V_4 , sizeof( T_1 ) , V_20 ) ;
if ( ! V_1 )
goto V_21;
V_11 = - V_22 ;
if ( F_8 ( & V_16 -> V_23 ) )
goto V_24;
V_11 = F_6 ( V_16 , V_1 ) ;
F_9 ( & V_16 -> V_23 ) ;
if ( ! V_11 )
V_18 = F_1 ( V_1 , V_2 , V_25 , V_4 ) ;
V_24:
F_10 ( V_1 ) ;
V_21:
return V_11 ? V_11 : V_18 ;
}
T_3 F_11 ( struct V_15 * V_16 ,
const char * V_2 , T_2 V_18 ,
int (* F_12)( const T_1 * V_1 , T_2 V_26 ) ,
int (* F_13)( struct V_15 * V_16 , const T_1 * V_1 ) )
{
T_1 * V_1 ;
int V_27 = 0 , V_11 = - V_17 ;
T_2 V_4 = V_16 -> V_19 ;
struct V_28 V_29 ;
V_1 = F_7 ( V_16 -> V_19 , sizeof( T_1 ) , V_20 ) ;
if ( ! V_1 )
goto V_21;
V_11 = F_3 ( V_1 , V_2 , V_18 , V_4 ) ;
if ( V_11 ) {
V_11 = - V_14 ;
goto V_24;
}
V_11 = F_12 ( V_1 , V_4 ) ;
if ( V_11 ) {
V_11 = - V_14 ;
goto V_24;
}
V_11 = - V_22 ;
if ( F_8 ( & V_16 -> V_23 ) )
goto V_24;
V_11 = F_14 ( V_16 , & V_29 ) ;
if ( V_11 ) {
F_15 ( L_3 ) ;
goto V_30;
}
V_27 = F_13 ( V_16 , V_1 ) ;
V_11 = F_16 ( & V_29 ) ;
if ( V_11 )
F_15 ( L_4 ) ;
V_30:
F_9 ( & V_16 -> V_23 ) ;
V_24:
F_10 ( V_1 ) ;
V_21:
if ( V_27 )
return V_27 ;
return V_11 ? V_11 : V_18 ;
}
int F_17 ( int (* F_18)( struct V_15 * V_16 ,
struct V_31 * V_21 ) )
{
if ( V_32 )
return - V_33 ;
V_32 = F_18 ;
return 0 ;
}
int F_19 ( struct V_15 * V_16 , struct V_31 * V_21 )
{
if ( ! V_32 )
return - V_34 ;
return V_32 ( V_16 , V_21 ) ;
}
bool F_20 ( struct V_15 * V_16 )
{
if ( V_16 -> V_35 == V_36 &&
V_16 -> V_37 . V_38 &&
V_16 -> V_37 . V_38 -> V_39 . V_40 >= 31 )
return V_16 -> V_37 . V_41 & V_42 ;
return true ;
}
