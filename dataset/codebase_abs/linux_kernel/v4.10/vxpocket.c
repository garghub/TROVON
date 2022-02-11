static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
F_3 ( V_2 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
F_5 ( V_8 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 , int V_12 ,
struct V_1 * V_2 ,
struct V_13 * * V_14 )
{
struct V_7 * V_8 ;
struct V_13 * V_15 ;
static struct V_16 V_17 = {
. V_18 = F_4 ,
} ;
int V_19 ;
V_8 = F_8 ( V_11 , & V_20 , & V_21 ,
sizeof( struct V_13 ) - sizeof( struct V_7 ) ) ;
if ( ! V_8 )
return - V_22 ;
V_19 = F_9 ( V_11 , V_23 , V_8 , & V_17 ) ;
if ( V_19 < 0 ) {
F_6 ( V_8 ) ;
return V_19 ;
}
V_8 -> V_12 . V_24 = V_12 ;
V_15 = (struct V_13 * ) V_8 ;
V_15 -> V_25 = V_2 ;
V_2 -> V_4 = V_8 ;
V_2 -> V_26 [ 0 ] -> V_27 |= V_28 ;
V_2 -> V_26 [ 0 ] -> V_29 = 16 ;
V_2 -> V_30 |= V_31 ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = V_34 ;
* V_14 = V_15 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 , int V_35 , int V_3 )
{
int V_19 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_13 * V_15 = (struct V_13 * ) V_8 ;
F_11 ( V_36 L_1 , V_35 , V_3 ) ;
V_15 -> V_35 = V_35 ;
sprintf ( V_11 -> V_37 , L_2 , V_11 -> V_38 ) ;
sprintf ( V_11 -> V_39 , L_3 ,
V_11 -> V_37 , V_35 , V_3 ) ;
V_8 -> V_3 = V_3 ;
if ( ( V_19 = F_12 ( V_8 ) ) < 0 )
return V_19 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
int V_40 ;
F_11 ( V_36 L_4 ) ;
if ( ! strcmp ( V_2 -> V_41 [ 1 ] , L_5 ) ) {
F_11 ( L_6 ) ;
} else {
F_11 ( L_7 ) ;
V_8 -> V_42 = & V_43 ;
V_8 -> type = V_43 . type ;
strcpy ( V_8 -> V_11 -> V_38 , V_43 . V_44 ) ;
}
V_40 = F_14 ( V_2 ) ;
if ( V_40 )
goto V_45;
V_40 = F_15 ( V_2 -> V_3 , V_46 ,
V_47 ,
V_48 , V_2 -> V_49 , V_2 -> V_4 ) ;
if ( V_40 )
goto V_45;
V_40 = F_16 ( V_2 ) ;
if ( V_40 )
goto V_50;
V_8 -> V_51 = & V_2 -> V_51 ;
if ( F_10 ( V_8 , V_2 -> V_26 [ 0 ] -> V_52 ,
V_2 -> V_3 ) < 0 )
goto V_50;
return 0 ;
V_50:
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
V_45:
F_3 ( V_2 ) ;
return - V_53 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
F_11 ( V_36 L_8 ) ;
if ( V_8 ) {
F_11 ( V_36 L_9 ) ;
F_18 ( V_8 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
F_11 ( V_36 L_10 ) ;
if ( F_20 ( V_2 ) ) {
if ( V_8 ) {
F_11 ( V_36 L_11 ) ;
F_21 ( V_8 ) ;
}
}
F_11 ( V_36 L_12 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_25 )
{
struct V_10 * V_11 ;
struct V_13 * V_15 ;
int V_54 , V_19 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
if ( ! ( V_56 & ( 1 << V_54 ) ) )
break;
}
if ( V_54 >= V_55 ) {
F_23 ( V_57 L_13 ) ;
return - V_58 ;
}
if ( ! V_59 [ V_54 ] )
return - V_53 ;
V_19 = F_24 ( & V_25 -> V_51 , V_60 [ V_54 ] , V_61 [ V_54 ] , V_62 ,
0 , & V_11 ) ;
if ( V_19 < 0 ) {
F_23 ( V_57 L_14 ) ;
return V_19 ;
}
V_19 = F_7 ( V_11 , V_12 [ V_54 ] , V_25 , & V_15 ) ;
if ( V_19 < 0 ) {
F_25 ( V_11 ) ;
return V_19 ;
}
V_11 -> V_63 = V_15 ;
V_15 -> V_60 = V_54 ;
V_56 |= 1 << V_54 ;
V_15 -> V_25 = V_25 ;
return F_13 ( V_25 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_13 * V_15 ;
struct V_7 * V_8 ;
if ( ! V_2 )
return;
V_15 = V_2 -> V_4 ;
V_8 = (struct V_7 * ) V_15 ;
V_56 &= ~ ( 1 << V_15 -> V_60 ) ;
V_8 -> V_64 |= V_65 ;
F_27 ( V_8 -> V_11 ) ;
F_1 ( V_2 ) ;
F_28 ( V_8 -> V_11 ) ;
}
