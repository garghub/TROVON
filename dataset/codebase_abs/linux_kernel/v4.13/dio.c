static const char * F_1 ( int V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] . V_1 == V_1 )
return V_3 [ V_2 ] . V_4 ;
return V_5 ;
}
int T_1 F_3 ( int V_6 )
{
int V_7 , V_1 ;
T_2 V_8 , V_9 , V_2 ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
void * V_11 ;
unsigned long V_12 ;
if ( F_4 ( V_7 ) )
continue;
V_12 = F_5 ( V_7 ) ;
if ( ! V_12 )
continue;
if ( V_7 < V_13 )
V_11 = ( void * ) ( V_12 + V_14 ) ;
else
V_11 = F_6 ( V_12 , V_15 ) ;
if ( F_7 ( & V_2 , ( unsigned char * ) V_11 + V_16 , 1 ) ) {
if ( V_7 >= V_13 )
F_8 ( V_11 ) ;
continue;
}
V_8 = F_9 ( V_11 ) ;
if ( F_10 ( V_8 ) ) {
V_9 = F_11 ( V_11 ) ;
V_1 = F_12 ( V_8 , V_9 ) ;
} else
V_1 = V_8 ;
if ( V_1 == V_6 ) {
if ( V_7 >= V_13 )
F_8 ( V_11 ) ;
return V_7 ;
}
}
return - 1 ;
}
static int T_1 F_13 ( void )
{
int V_7 ;
int V_2 ;
struct V_17 * V_18 ;
int error ;
if ( ! V_19 )
return 0 ;
F_14 ( V_20 L_1 ) ;
F_15 ( & V_21 . V_22 ) ;
F_16 ( & V_21 . V_18 , L_2 ) ;
error = F_17 ( & V_21 . V_18 ) ;
if ( error ) {
F_18 ( L_3 ) ;
return error ;
}
V_21 . V_23 = ( V_24 == V_25 ? 1 : 2 ) ;
for ( V_2 = 0 ; V_2 < V_21 . V_23 ; V_2 ++ )
F_19 ( & V_26 , & V_21 . V_27 [ V_2 ] ) ;
for ( V_7 = 0 ; V_7 < V_10 ; ++ V_7 )
{
T_2 V_8 , V_9 = 0 ;
T_2 * V_11 ;
unsigned long V_12 ;
if ( F_4 ( V_7 ) )
continue;
V_12 = F_5 ( V_7 ) ;
if ( ! V_12 )
continue;
if ( V_7 < V_13 )
V_11 = ( void * ) ( V_12 + V_14 ) ;
else
V_11 = F_6 ( V_12 , V_15 ) ;
if ( F_7 ( & V_2 , ( unsigned char * ) V_11 + V_16 , 1 ) ) {
if ( V_7 >= V_13 )
F_8 ( V_11 ) ;
continue;
}
V_18 = F_20 ( sizeof( struct V_17 ) , V_28 ) ;
if ( ! V_18 )
return 0 ;
V_18 -> V_29 = & V_21 ;
V_18 -> V_18 . V_30 = & V_21 . V_18 ;
V_18 -> V_18 . V_29 = & V_31 ;
V_18 -> V_7 = V_7 ;
V_18 -> V_32 . V_33 = V_12 ;
V_18 -> V_32 . V_34 = V_12 + F_21 ( V_7 , V_11 ) ;
F_16 ( & V_18 -> V_18 , L_4 , V_7 ) ;
V_8 = F_9 ( V_11 ) ;
if ( F_10 ( V_8 ) ) {
V_9 = F_11 ( V_11 ) ;
V_18 -> V_1 = F_12 ( V_8 , V_9 ) ;
} else
V_18 -> V_1 = V_8 ;
V_18 -> V_35 = F_22 ( V_11 ) ;
strcpy ( V_18 -> V_4 , F_1 ( V_18 -> V_1 ) ) ;
F_14 ( V_20 L_5 , V_18 -> V_7 , V_18 -> V_35 , V_8 ) ;
if ( F_10 ( V_8 ) )
F_14 ( L_6 , V_9 ) ;
F_14 ( L_7 , V_18 -> V_4 ) ;
if ( V_7 >= V_13 )
F_8 ( V_11 ) ;
error = F_17 ( & V_18 -> V_18 ) ;
if ( error ) {
F_18 ( L_8 ,
V_18 -> V_4 ) ;
continue;
}
error = F_23 ( V_18 ) ;
if ( error )
F_24 ( & V_18 -> V_18 , L_9 ) ;
}
return 0 ;
}
unsigned long F_5 ( int V_7 )
{
if ( V_7 >= V_13 ) {
return ( V_36 + ( V_7 - 132 ) * V_37 ) ;
} else if ( V_7 > V_10 || V_7 < 0 )
return 0 ;
else if ( F_4 ( V_7 ) )
return 0 ;
return ( V_38 + V_7 * V_39 ) ;
}
