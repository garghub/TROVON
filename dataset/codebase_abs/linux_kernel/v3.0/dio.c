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
T_3 V_10 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
void * V_12 ;
unsigned long V_13 ;
if ( F_4 ( V_7 ) )
continue;
V_13 = F_5 ( V_7 ) ;
if ( ! V_13 )
continue;
if ( V_7 < V_14 )
V_12 = ( void * ) ( V_13 + V_15 ) ;
else
V_12 = F_6 ( V_13 , V_16 ) ;
V_10 = F_7 () ;
F_8 ( V_17 ) ;
if ( F_9 ( V_2 , ( unsigned char * ) V_12 + V_18 ) ) {
F_8 ( V_10 ) ;
if ( V_7 >= V_14 )
F_10 ( V_12 ) ;
continue;
}
F_8 ( V_10 ) ;
V_8 = F_11 ( V_12 ) ;
if ( F_12 ( V_8 ) ) {
V_9 = F_13 ( V_12 ) ;
V_1 = F_14 ( V_8 , V_9 ) ;
} else
V_1 = V_8 ;
if ( V_1 == V_6 ) {
if ( V_7 >= V_14 )
F_10 ( V_12 ) ;
return V_7 ;
}
}
return - 1 ;
}
static int T_1 F_15 ( void )
{
int V_7 ;
T_3 V_10 ;
int V_2 ;
struct V_19 * V_20 ;
int error ;
if ( ! V_21 )
return 0 ;
F_16 ( V_22 L_1 ) ;
F_17 ( & V_23 . V_24 ) ;
F_18 ( & V_23 . V_20 , L_2 ) ;
error = F_19 ( & V_23 . V_20 ) ;
if ( error ) {
F_20 ( L_3 ) ;
return error ;
}
V_23 . V_25 = ( V_26 == V_27 ? 1 : 2 ) ;
for ( V_2 = 0 ; V_2 < V_23 . V_25 ; V_2 ++ )
F_21 ( & V_28 , & V_23 . V_29 [ V_2 ] ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 )
{
T_2 V_8 , V_9 = 0 ;
T_2 * V_12 ;
unsigned long V_13 ;
if ( F_4 ( V_7 ) )
continue;
V_13 = F_5 ( V_7 ) ;
if ( ! V_13 )
continue;
if ( V_7 < V_14 )
V_12 = ( void * ) ( V_13 + V_15 ) ;
else
V_12 = F_6 ( V_13 , V_16 ) ;
V_10 = F_7 () ;
F_8 ( V_17 ) ;
if ( F_9 ( V_2 , ( unsigned char * ) V_12 + V_18 ) ) {
F_8 ( V_10 ) ;
if ( V_7 >= V_14 )
F_10 ( V_12 ) ;
continue;
}
F_8 ( V_10 ) ;
V_20 = F_22 ( sizeof( struct V_19 ) , V_30 ) ;
if ( ! V_20 )
return 0 ;
V_20 -> V_31 = & V_23 ;
V_20 -> V_20 . V_32 = & V_23 . V_20 ;
V_20 -> V_20 . V_31 = & V_33 ;
V_20 -> V_7 = V_7 ;
V_20 -> V_34 . V_35 = V_13 ;
V_20 -> V_34 . V_36 = V_13 + F_23 ( V_7 , V_12 ) ;
F_18 ( & V_20 -> V_20 , L_4 , V_7 ) ;
V_8 = F_11 ( V_12 ) ;
if ( F_12 ( V_8 ) ) {
V_9 = F_13 ( V_12 ) ;
V_20 -> V_1 = F_14 ( V_8 , V_9 ) ;
} else
V_20 -> V_1 = V_8 ;
V_20 -> V_37 = F_24 ( V_12 ) ;
strcpy ( V_20 -> V_4 , F_1 ( V_20 -> V_1 ) ) ;
F_16 ( V_22 L_5 , V_20 -> V_7 , V_20 -> V_37 , V_8 ) ;
if ( F_12 ( V_8 ) )
F_16 ( L_6 , V_9 ) ;
F_16 ( L_7 , V_20 -> V_4 ) ;
if ( V_7 >= V_14 )
F_10 ( V_12 ) ;
error = F_19 ( & V_20 -> V_20 ) ;
if ( error ) {
F_20 ( L_8 ,
V_20 -> V_4 ) ;
continue;
}
error = F_25 ( V_20 ) ;
if ( error )
F_26 ( & V_20 -> V_20 , L_9 ) ;
}
return 0 ;
}
unsigned long F_5 ( int V_7 )
{
if ( V_7 >= V_14 ) {
return ( V_38 + ( V_7 - 132 ) * V_39 ) ;
} else if ( V_7 > V_11 || V_7 < 0 )
return 0 ;
else if ( F_4 ( V_7 ) )
return 0 ;
return ( V_40 + V_7 * V_41 ) ;
}
