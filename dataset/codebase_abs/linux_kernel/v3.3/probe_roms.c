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
F_10 ( & V_3 -> V_14 , V_5 ) ;
V_5 = NULL ;
}
F_11 ( V_4 ) ;
return V_5 ;
}
enum V_23 F_12 ( struct V_24 * V_25 ,
struct V_1 * V_26 , int V_27 )
{
if ( V_27 < 0 || V_27 >= V_28 ||
V_27 > V_26 -> V_19 . V_29 || ! V_25 )
return - V_30 ;
* V_25 = V_26 -> V_31 [ V_27 ] ;
return 0 ;
}
struct V_1 * F_13 ( struct V_2 * V_3 , const struct V_32 * V_33 )
{
struct V_1 * V_26 = NULL , * V_34 ;
int V_7 , V_8 ;
if ( F_14 ( & V_33 , V_35 , & V_3 -> V_14 ) != 0 )
return NULL ;
if ( V_33 -> V_36 < sizeof( * V_26 ) )
goto V_37;
V_34 = (struct V_1 * ) V_33 -> V_34 ;
if ( strncmp ( V_21 , V_34 -> V_19 . V_20 ,
strlen ( V_21 ) ) != 0 )
goto V_37;
V_26 = F_4 ( & V_3 -> V_14 , V_33 -> V_36 , V_15 ) ;
if ( ! V_26 )
goto V_37;
memcpy ( V_26 , V_33 -> V_34 , V_33 -> V_36 ) ;
if ( F_15 ( V_3 ) || F_16 ( V_3 ) )
goto V_37;
for ( V_7 = 0 ; V_7 < F_17 ( V_26 -> V_31 ) ; V_7 ++ )
for ( V_8 = 0 ; V_8 < F_17 ( V_26 -> V_31 [ V_7 ] . V_38 ) ; V_8 ++ ) {
V_26 -> V_31 [ V_7 ] . V_38 [ V_8 ] . V_39 = 0xe7c03 ;
V_26 -> V_31 [ V_7 ] . V_38 [ V_8 ] . V_40 = 0xe7c03 ;
V_26 -> V_31 [ V_7 ] . V_38 [ V_8 ] . V_41 = 0xe7c03 ;
V_26 -> V_31 [ V_7 ] . V_38 [ V_8 ] . V_42 = 0xe7c03 ;
}
V_37:
F_18 ( V_33 ) ;
return V_26 ;
}
static struct V_43 * F_19 ( void )
{
#ifdef F_20
return & V_43 ;
#else
return NULL ;
#endif
}
struct V_1 * F_21 ( struct V_2 * V_3 )
{
T_4 V_44 ;
struct V_1 * V_5 ;
struct V_10 * V_11 ;
T_3 * V_12 , V_13 ;
int V_8 ;
unsigned long V_45 ;
T_3 * V_46 ;
T_5 V_47 = 0 ;
V_45 = 1024 ;
V_46 = F_4 ( & V_3 -> V_14 , V_45 , V_15 ) ;
if ( ! V_46 ) {
F_5 ( & V_3 -> V_14 ,
L_5 ) ;
return NULL ;
}
V_5 = (struct V_1 * ) ( V_46 + sizeof( struct V_10 ) ) ;
if ( F_19 () )
V_44 = F_19 () -> F_22 ( V_48 ,
& V_49 ,
& V_47 ,
& V_45 ,
V_46 ) ;
else
V_44 = V_50 ;
if ( V_44 != V_51 ) {
F_5 ( & V_3 -> V_14 ,
L_6 ) ;
return NULL ;
}
V_11 = (struct V_10 * ) V_46 ;
if ( memcmp ( V_11 -> V_52 , V_17 , V_16 ) != 0 ) {
F_5 ( & V_3 -> V_14 ,
L_7 ) ;
return NULL ;
}
V_12 = ( T_3 * ) V_46 ;
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
