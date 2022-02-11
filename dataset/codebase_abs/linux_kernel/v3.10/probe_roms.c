struct V_1 * F_1 ( struct V_2 * V_3 )
{
void T_1 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = NULL ;
T_2 V_6 , V_7 ;
int V_8 ;
char V_9 [ 4 ] ;
struct V_10 V_11 ;
T_3 * V_12 , V_13 ;
if ( ! V_4 )
return NULL ;
V_6 = F_3 ( V_3 ) ;
V_5 = F_4 ( & V_3 -> V_14 , sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 ) {
F_5 ( & V_3 -> V_14 ,
L_1 ) ;
return NULL ;
}
for ( V_7 = 0 ; V_7 < V_6 && V_5 ; V_7 += V_16 ) {
F_6 ( V_9 , V_4 + V_7 , V_16 ) ;
if ( memcmp ( V_9 , V_17 , V_16 ) == 0 ) {
T_2 V_18 ;
F_6 ( & V_11 , V_4 + V_7 , sizeof( V_11 ) ) ;
V_18 = F_7 ( V_11 . V_6 - sizeof( V_11 ) ,
sizeof( * V_5 ) ) ;
F_6 ( V_5 ,
V_4 + V_7 + sizeof( V_11 ) ,
V_18 ) ;
V_12 = ( T_3 * ) & V_11 ;
for ( V_8 = 0 , V_13 = 0 ; V_8 < sizeof( V_11 ) ; V_8 ++ , V_12 ++ )
V_13 += * V_12 ;
V_12 = ( T_3 * ) V_5 ;
for ( V_8 = 0 ; V_8 < sizeof( * V_5 ) ; V_8 ++ , V_12 ++ )
V_13 += * V_12 ;
if ( V_13 != 0 ) {
F_5 ( & V_3 -> V_14 ,
L_2 ) ;
continue;
}
if ( memcmp ( V_5 -> V_19 . V_20 ,
V_21 ,
V_22 ) != 0 )
continue;
F_8 ( & V_3 -> V_14 ,
L_3 ) ;
break;
}
}
if ( V_7 >= V_6 ) {
F_9 ( & V_3 -> V_14 , L_4 ) ;
V_5 = NULL ;
}
F_10 ( V_4 ) ;
return V_5 ;
}
struct V_1 * F_11 ( struct V_2 * V_3 , const struct V_23 * V_24 )
{
struct V_1 * V_25 = NULL , * V_26 ;
int V_7 , V_8 ;
if ( F_12 ( & V_24 , V_27 , & V_3 -> V_14 ) != 0 )
return NULL ;
if ( V_24 -> V_28 < sizeof( * V_25 ) )
goto V_29;
V_26 = (struct V_1 * ) V_24 -> V_26 ;
if ( strncmp ( V_21 , V_26 -> V_19 . V_20 ,
strlen ( V_21 ) ) != 0 )
goto V_29;
V_25 = F_4 ( & V_3 -> V_14 , V_24 -> V_28 , V_15 ) ;
if ( ! V_25 )
goto V_29;
memcpy ( V_25 , V_24 -> V_26 , V_24 -> V_28 ) ;
if ( F_13 ( V_3 ) || F_14 ( V_3 ) )
goto V_29;
for ( V_7 = 0 ; V_7 < F_15 ( V_25 -> V_30 ) ; V_7 ++ )
for ( V_8 = 0 ; V_8 < F_15 ( V_25 -> V_30 [ V_7 ] . V_31 ) ; V_8 ++ ) {
V_25 -> V_30 [ V_7 ] . V_31 [ V_8 ] . V_32 = 0xe7c03 ;
V_25 -> V_30 [ V_7 ] . V_31 [ V_8 ] . V_33 = 0xe7c03 ;
V_25 -> V_30 [ V_7 ] . V_31 [ V_8 ] . V_34 = 0xe7c03 ;
V_25 -> V_30 [ V_7 ] . V_31 [ V_8 ] . V_35 = 0xe7c03 ;
}
V_29:
F_16 ( V_24 ) ;
return V_25 ;
}
static struct V_36 * F_17 ( void )
{
#ifdef F_18
return & V_36 ;
#else
return NULL ;
#endif
}
struct V_1 * F_19 ( struct V_2 * V_3 )
{
T_4 V_37 ;
struct V_1 * V_5 ;
struct V_10 * V_11 ;
T_3 * V_12 , V_13 ;
int V_8 ;
unsigned long V_38 ;
T_3 * V_39 ;
T_5 V_40 = 0 ;
V_38 = 1024 ;
V_39 = F_4 ( & V_3 -> V_14 , V_38 , V_15 ) ;
if ( ! V_39 ) {
F_5 ( & V_3 -> V_14 ,
L_5 ) ;
return NULL ;
}
V_5 = (struct V_1 * ) ( V_39 + sizeof( struct V_10 ) ) ;
if ( F_17 () )
V_37 = F_17 () -> F_20 ( V_41 ,
& V_42 ,
& V_40 ,
& V_38 ,
V_39 ) ;
else
V_37 = V_43 ;
if ( V_37 != V_44 ) {
F_5 ( & V_3 -> V_14 ,
L_6 ) ;
return NULL ;
}
V_11 = (struct V_10 * ) V_39 ;
if ( memcmp ( V_11 -> V_45 , V_17 , V_16 ) != 0 ) {
F_5 ( & V_3 -> V_14 ,
L_7 ) ;
return NULL ;
}
V_12 = ( T_3 * ) V_39 ;
for ( V_8 = 0 , V_13 = 0 ; V_8 < ( sizeof( * V_11 ) + sizeof( * V_5 ) ) ; V_8 ++ , V_12 ++ )
V_13 += * V_12 ;
if ( V_13 != 0 ) {
F_5 ( & V_3 -> V_14 ,
L_2 ) ;
return NULL ;
}
if ( memcmp ( V_5 -> V_19 . V_20 ,
V_21 ,
V_22 ) != 0 ) {
F_5 ( & V_3 -> V_14 ,
L_8 ) ;
return NULL ;
}
return V_5 ;
}
