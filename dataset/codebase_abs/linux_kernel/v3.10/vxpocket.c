static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_4 ( V_6 ) ;
F_5 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 , int V_10 ,
struct V_1 * V_2 ,
struct V_11 * * V_12 )
{
struct V_5 * V_6 ;
struct V_11 * V_13 ;
static struct V_14 V_15 = {
. V_16 = F_3 ,
} ;
int V_17 ;
V_6 = F_7 ( V_9 , & V_18 , & V_19 ,
sizeof( struct V_11 ) - sizeof( struct V_5 ) ) ;
if ( ! V_6 )
return - V_20 ;
V_17 = F_8 ( V_9 , V_21 , V_6 , & V_15 ) ;
if ( V_17 < 0 ) {
F_5 ( V_6 ) ;
return V_17 ;
}
V_6 -> V_10 . V_22 = V_10 ;
V_13 = (struct V_11 * ) V_6 ;
V_13 -> V_23 = V_2 ;
V_2 -> V_24 = V_6 ;
V_2 -> V_25 [ 0 ] -> V_26 |= V_27 ;
V_2 -> V_25 [ 0 ] -> V_28 = 16 ;
V_2 -> V_29 |= V_30 ;
V_2 -> V_31 = 1 ;
V_2 -> V_32 = V_33 ;
* V_12 = V_13 ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , int V_34 , int V_35 )
{
int V_17 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_11 * V_13 = (struct V_11 * ) V_6 ;
F_10 ( V_36 L_1 , V_34 , V_35 ) ;
V_13 -> V_34 = V_34 ;
sprintf ( V_9 -> V_37 , L_2 , V_9 -> V_38 ) ;
sprintf ( V_9 -> V_39 , L_3 ,
V_9 -> V_37 , V_34 , V_35 ) ;
V_6 -> V_35 = V_35 ;
if ( ( V_17 = F_11 ( V_6 ) ) < 0 )
return V_17 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_24 ;
int V_40 ;
F_10 ( V_36 L_4 ) ;
if ( ! strcmp ( V_2 -> V_41 [ 1 ] , L_5 ) ) {
F_10 ( L_6 ) ;
} else {
F_10 ( L_7 ) ;
V_6 -> V_42 = & V_43 ;
V_6 -> type = V_43 . type ;
strcpy ( V_6 -> V_9 -> V_38 , V_43 . V_44 ) ;
}
V_40 = F_13 ( V_2 ) ;
if ( V_40 )
goto V_45;
V_40 = F_14 ( V_2 , V_46 ) ;
if ( V_40 )
goto V_45;
V_40 = F_15 ( V_2 ) ;
if ( V_40 )
goto V_45;
V_6 -> V_47 = & V_2 -> V_47 ;
F_16 ( V_6 -> V_9 , V_6 -> V_47 ) ;
if ( F_9 ( V_6 , V_2 -> V_25 [ 0 ] -> V_48 ,
V_2 -> V_35 ) < 0 )
goto V_45;
return 0 ;
V_45:
F_2 ( V_2 ) ;
return - V_49 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_24 ;
F_10 ( V_36 L_8 ) ;
if ( V_6 ) {
F_10 ( V_36 L_9 ) ;
F_18 ( V_6 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_24 ;
F_10 ( V_36 L_10 ) ;
if ( F_20 ( V_2 ) ) {
if ( V_6 ) {
F_10 ( V_36 L_11 ) ;
F_21 ( V_6 ) ;
}
}
F_10 ( V_36 L_12 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_23 )
{
struct V_8 * V_9 ;
struct V_11 * V_13 ;
int V_50 , V_17 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
if ( ! ( V_52 & ( 1 << V_50 ) ) )
break;
}
if ( V_50 >= V_51 ) {
F_23 ( V_53 L_13 ) ;
return - V_54 ;
}
if ( ! V_55 [ V_50 ] )
return - V_49 ;
V_17 = F_24 ( V_56 [ V_50 ] , V_57 [ V_50 ] , V_58 , 0 , & V_9 ) ;
if ( V_17 < 0 ) {
F_23 ( V_53 L_14 ) ;
return V_17 ;
}
V_17 = F_6 ( V_9 , V_10 [ V_50 ] , V_23 , & V_13 ) ;
if ( V_17 < 0 ) {
F_25 ( V_9 ) ;
return V_17 ;
}
V_9 -> V_59 = V_13 ;
V_13 -> V_56 = V_50 ;
V_52 |= 1 << V_50 ;
V_13 -> V_23 = V_23 ;
return F_12 ( V_23 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_13 ;
struct V_5 * V_6 ;
if ( ! V_2 )
return;
V_13 = V_2 -> V_24 ;
V_6 = (struct V_5 * ) V_13 ;
V_52 &= ~ ( 1 << V_13 -> V_56 ) ;
V_6 -> V_60 |= V_61 ;
F_27 ( V_6 -> V_9 ) ;
F_1 ( V_2 ) ;
F_28 ( V_6 -> V_9 ) ;
}
