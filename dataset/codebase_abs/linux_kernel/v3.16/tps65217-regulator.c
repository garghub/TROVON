static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 ( V_2 ) ;
if ( V_5 < V_6 || V_5 > V_7 )
return - V_8 ;
return F_4 ( V_4 , V_9 ,
V_2 -> V_10 -> V_11 , V_2 -> V_10 -> V_11 ,
V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 ( V_2 ) ;
if ( V_5 < V_6 || V_5 > V_7 )
return - V_8 ;
return F_6 ( V_4 , V_9 ,
V_2 -> V_10 -> V_11 , V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_13 )
{
int V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 ( V_2 ) ;
V_14 = F_4 ( V_4 , V_2 -> V_10 -> V_15 , V_2 -> V_10 -> V_16 ,
V_13 , V_17 ) ;
switch ( V_5 ) {
case V_6 ... V_18 :
V_14 = F_4 ( V_4 , V_19 ,
V_20 , V_20 ,
V_17 ) ;
break;
}
return V_14 ;
}
static struct V_21 * F_8 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_9 ( V_23 -> V_2 . V_24 ) ;
struct V_25 * V_26 = V_4 -> V_2 -> V_27 ;
struct V_21 * V_28 ;
struct V_25 * V_29 ;
int V_30 , V_31 ;
V_29 = F_10 ( V_26 , L_1 ) ;
if ( ! V_29 )
return NULL ;
V_31 = F_11 ( & V_23 -> V_2 , V_29 , V_32 ,
V_33 ) ;
F_12 ( V_29 ) ;
if ( ( V_31 < 0 ) || ( V_31 > V_33 ) )
return NULL ;
V_28 = F_13 ( & V_23 -> V_2 , sizeof( * V_28 ) , V_34 ) ;
if ( ! V_28 )
return NULL ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
if ( ! V_32 [ V_30 ] . V_27 )
continue;
V_28 -> V_35 [ V_30 ] = V_32 [ V_30 ] . V_36 ;
V_28 -> V_27 [ V_30 ] = V_32 [ V_30 ] . V_27 ;
}
return V_28 ;
}
static struct V_21 * F_8 ( struct V_22 * V_23 )
{
return NULL ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_9 ( V_23 -> V_2 . V_24 ) ;
struct V_21 * V_28 = F_15 ( V_4 -> V_2 ) ;
struct V_1 * V_37 ;
struct V_38 V_39 = { } ;
int V_30 ;
if ( V_4 -> V_2 -> V_27 )
V_28 = F_8 ( V_23 ) ;
if ( ! V_28 ) {
F_16 ( & V_23 -> V_2 , L_2 ) ;
return - V_8 ;
}
if ( F_17 ( V_4 ) != V_40 ) {
F_16 ( & V_23 -> V_2 , L_3 ) ;
return - V_41 ;
}
F_18 ( V_23 , V_4 ) ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
V_39 . V_2 = V_4 -> V_2 ;
V_39 . V_36 = V_28 -> V_35 [ V_30 ] ;
V_39 . V_42 = V_4 ;
V_39 . V_43 = V_4 -> V_43 ;
if ( V_4 -> V_2 -> V_27 )
V_39 . V_27 = V_28 -> V_27 [ V_30 ] ;
V_37 = F_19 ( & V_23 -> V_2 , & V_44 [ V_30 ] ,
& V_39 ) ;
if ( F_20 ( V_37 ) ) {
F_16 ( V_4 -> V_2 , L_4 ,
V_23 -> V_45 ) ;
return F_21 ( V_37 ) ;
}
}
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_46 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_46 ) ;
}
