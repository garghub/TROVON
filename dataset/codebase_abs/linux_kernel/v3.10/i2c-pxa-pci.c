static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
struct V_6 V_7 ;
struct V_8 V_9 [ 2 ] ;
struct V_10 * V_11 ;
static int V_12 ;
int V_13 ;
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 [ 0 ] . V_14 = V_15 ;
V_9 [ 0 ] . V_16 = F_2 ( V_3 , V_4 ) ;
V_9 [ 0 ] . V_17 = F_3 ( V_3 , V_4 ) ;
V_9 [ 1 ] . V_14 = V_18 ;
V_9 [ 1 ] . V_16 = V_3 -> V_19 ;
V_9 [ 1 ] . V_17 = V_3 -> V_19 ;
F_4 (dev->dev.of_node, child) {
const void * V_20 ;
struct V_8 V_21 ;
int V_13 ;
V_13 = F_5 ( V_11 , 0 , & V_21 ) ;
if ( V_13 < 0 )
continue;
if ( V_21 . V_16 != V_9 [ 0 ] . V_16 )
continue;
if ( V_21 . V_17 != V_9 [ 0 ] . V_17 )
continue;
if ( V_21 . V_14 != V_9 [ 0 ] . V_14 )
continue;
V_20 = F_6 ( V_11 , L_1 , NULL ) ;
if ( V_20 )
V_7 . V_22 = 1 ;
break;
}
if ( ! V_11 ) {
F_7 ( & V_3 -> V_3 , L_2 ,
V_4 ) ;
V_13 = - V_23 ;
goto V_24;
}
V_5 = F_8 ( L_3 , V_12 ) ;
if ( ! V_5 ) {
F_9 ( V_11 ) ;
V_13 = - V_25 ;
goto V_24;
}
V_5 -> V_3 . V_26 = & V_3 -> V_3 ;
V_5 -> V_3 . V_27 = V_11 ;
V_13 = F_10 ( V_5 , V_9 , F_11 ( V_9 ) ) ;
if ( V_13 )
goto V_28;
V_13 = F_12 ( V_5 , & V_7 , sizeof( V_7 ) ) ;
if ( V_13 )
goto V_28;
V_13 = F_13 ( V_5 ) ;
if ( V_13 )
goto V_28;
V_12 ++ ;
return V_5 ;
V_28:
F_14 ( V_5 ) ;
V_24:
return F_15 ( V_13 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_29 * V_30 )
{
int V_13 ;
int V_31 ;
struct V_32 * V_33 ;
V_13 = F_17 ( V_3 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_3 -> V_3 . V_27 ) {
F_7 ( & V_3 -> V_3 , L_4 ) ;
return - V_23 ;
}
V_33 = F_18 ( sizeof( * V_33 ) , V_34 ) ;
if ( ! V_33 ) {
V_13 = - V_25 ;
goto V_35;
}
for ( V_31 = 0 ; V_31 < F_11 ( V_33 -> V_5 ) ; V_31 ++ ) {
V_33 -> V_5 [ V_31 ] = F_1 ( V_3 , V_31 ) ;
if ( F_19 ( V_33 -> V_5 [ V_31 ] ) ) {
V_13 = F_20 ( V_33 -> V_5 [ V_31 ] ) ;
while ( -- V_31 >= 0 )
F_21 ( V_33 -> V_5 [ V_31 ] ) ;
goto V_36;
}
}
F_22 ( V_3 , V_33 ) ;
return 0 ;
V_36:
F_23 ( V_33 ) ;
V_35:
F_24 ( V_3 ) ;
return V_13 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
unsigned int V_31 ;
V_33 = F_26 ( V_3 ) ;
for ( V_31 = 0 ; V_31 < F_11 ( V_33 -> V_5 ) ; V_31 ++ )
F_21 ( V_33 -> V_5 [ V_31 ] ) ;
F_24 ( V_3 ) ;
F_23 ( V_33 ) ;
}
