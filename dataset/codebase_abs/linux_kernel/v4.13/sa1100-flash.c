static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_6 ;
F_3 ( & V_7 , V_6 ) ;
if ( V_3 ) {
if ( ++ V_8 == 1 )
V_5 -> V_9 -> V_10 ( 1 ) ;
} else {
if ( -- V_8 == 0 )
V_5 -> V_9 -> V_10 ( 0 ) ;
}
F_4 ( & V_7 , V_6 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
if ( V_5 -> V_11 )
F_6 ( V_5 -> V_11 ) ;
if ( V_5 -> V_2 . V_12 )
F_7 ( V_5 -> V_2 . V_12 ) ;
F_8 ( V_5 -> V_2 . V_13 , V_5 -> V_2 . V_14 ) ;
}
static int F_9 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_13 ;
unsigned int V_14 ;
int V_17 ;
V_13 = V_16 -> V_18 ;
V_14 = V_16 -> V_19 - V_13 + 1 ;
switch ( V_13 ) {
default:
F_10 ( V_20 L_1
L_2 , V_13 ) ;
case V_21 :
V_5 -> V_2 . V_22 = ( V_23 & V_24 ) ? 2 : 4 ;
break;
case V_25 :
V_5 -> V_2 . V_22 = ( ( V_23 >> 16 ) & V_24 ) ? 2 : 4 ;
break;
}
if ( ! F_11 ( V_13 , V_14 , V_5 -> V_26 ) ) {
V_17 = - V_27 ;
goto V_28;
}
if ( V_5 -> V_9 -> V_10 )
V_5 -> V_2 . V_10 = F_1 ;
V_5 -> V_2 . V_13 = V_13 ;
V_5 -> V_2 . V_14 = V_14 ;
V_5 -> V_2 . V_12 = F_12 ( V_13 , V_14 ) ;
if ( ! V_5 -> V_2 . V_12 ) {
V_17 = - V_29 ;
goto V_30;
}
F_13 ( & V_5 -> V_2 ) ;
V_5 -> V_11 = F_14 ( V_5 -> V_9 -> V_31 , & V_5 -> V_2 ) ;
if ( V_5 -> V_11 == NULL ) {
V_17 = - V_32 ;
goto V_30;
}
F_10 ( V_33 L_3 ,
V_13 , ( unsigned ) ( V_5 -> V_11 -> V_14 >> 20 ) ,
V_5 -> V_2 . V_22 * 8 ) ;
return 0 ;
V_30:
F_5 ( V_5 ) ;
V_28:
return V_17 ;
}
static void F_15 ( struct V_34 * V_35 , struct V_36 * V_9 )
{
int V_37 ;
if ( V_35 -> V_11 ) {
F_16 ( V_35 -> V_11 ) ;
if ( V_35 -> V_11 != V_35 -> V_5 [ 0 ] . V_11 )
F_17 ( V_35 -> V_11 ) ;
}
for ( V_37 = V_35 -> V_38 - 1 ; V_37 >= 0 ; V_37 -- )
F_5 ( & V_35 -> V_5 [ V_37 ] ) ;
F_18 ( V_35 ) ;
if ( V_9 -> exit )
V_9 -> exit () ;
}
static struct V_34 * F_19 ( struct V_39 * V_40 ,
struct V_36 * V_9 )
{
struct V_34 * V_35 ;
int V_41 , V_14 , V_37 , V_17 = 0 ;
for ( V_41 = 0 ; ; V_41 ++ )
if ( ! F_20 ( V_40 , V_42 , V_41 ) )
break;
if ( V_41 == 0 ) {
V_17 = - V_43 ;
goto V_28;
}
V_14 = sizeof( struct V_34 ) + sizeof( struct V_4 ) * V_41 ;
V_35 = F_21 ( V_14 , V_44 ) ;
if ( ! V_35 ) {
V_17 = - V_29 ;
goto V_28;
}
if ( V_9 -> V_45 ) {
V_17 = V_9 -> V_45 () ;
if ( V_17 )
goto V_30;
}
for ( V_37 = 0 ; V_37 < V_41 ; V_37 ++ ) {
struct V_4 * V_5 = & V_35 -> V_5 [ V_37 ] ;
struct V_15 * V_16 ;
V_16 = F_20 ( V_40 , V_42 , V_37 ) ;
if ( ! V_16 )
break;
V_5 -> V_2 . V_26 = V_5 -> V_26 ;
sprintf ( V_5 -> V_26 , L_4 , V_9 -> V_26 , V_37 ) ;
V_5 -> V_9 = V_9 ;
V_17 = F_9 ( V_5 , V_16 ) ;
if ( V_17 )
break;
}
V_35 -> V_38 = V_37 ;
if ( V_17 != 0 && ! ( V_17 == - V_32 && V_35 -> V_38 > 0 ) )
goto V_30;
if ( V_35 -> V_38 == 1 ) {
strcpy ( V_35 -> V_5 [ 0 ] . V_26 , V_9 -> V_26 ) ;
V_35 -> V_11 = V_35 -> V_5 [ 0 ] . V_11 ;
V_17 = 0 ;
} else if ( V_35 -> V_38 > 1 ) {
struct V_46 * V_47 [ V_41 ] ;
for ( V_37 = 0 ; V_37 < V_35 -> V_38 ; V_37 ++ )
V_47 [ V_37 ] = V_35 -> V_5 [ V_37 ] . V_11 ;
V_35 -> V_11 = F_22 ( V_47 , V_35 -> V_38 ,
V_9 -> V_26 ) ;
if ( V_35 -> V_11 == NULL ) {
V_17 = - V_32 ;
goto V_30;
}
}
V_35 -> V_11 -> V_48 . V_49 = & V_40 -> V_48 ;
if ( V_17 == 0 )
return V_35 ;
V_30:
F_15 ( V_35 , V_9 ) ;
V_28:
return F_23 ( V_17 ) ;
}
static int F_24 ( struct V_39 * V_40 )
{
struct V_36 * V_9 = F_25 ( & V_40 -> V_48 ) ;
struct V_34 * V_35 ;
int V_30 ;
if ( ! V_9 )
return - V_43 ;
V_35 = F_19 ( V_40 , V_9 ) ;
if ( F_26 ( V_35 ) ) {
V_30 = F_27 ( V_35 ) ;
goto V_28;
}
F_28 ( V_35 -> V_11 , V_50 , NULL , V_9 -> V_51 ,
V_9 -> V_52 ) ;
F_29 ( V_40 , V_35 ) ;
V_30 = 0 ;
V_28:
return V_30 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_34 * V_35 = F_31 ( V_40 ) ;
struct V_36 * V_9 = F_25 ( & V_40 -> V_48 ) ;
F_15 ( V_35 , V_9 ) ;
return 0 ;
}
