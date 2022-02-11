static int F_1 ( unsigned int V_1 )
{
int V_2 = 0 ;
if ( V_1 > 63 )
return - V_3 ;
if ( V_1 <= 24 )
V_2 = V_1 * 25000 + 900000 ;
else if ( V_1 <= 52 )
V_2 = ( V_1 - 24 ) * 50000 + 1500000 ;
else if ( V_1 < 56 )
V_2 = ( V_1 - 52 ) * 100000 + 2900000 ;
else
V_2 = 3300000 ;
return V_2 ;
}
static int F_2 ( int V_2 , unsigned int * V_1 )
{
if ( V_2 < 0 || V_2 > 3300000 )
return - V_3 ;
if ( V_2 <= 1500000 )
* V_1 = F_3 ( V_2 - 900000 , 25000 ) ;
else if ( V_2 <= 2900000 )
* V_1 = 24 + F_3 ( V_2 - 1500000 , 50000 ) ;
else if ( V_2 < 3300000 )
* V_1 = 52 + F_3 ( V_2 - 2900000 , 100000 ) ;
else
* V_1 = 56 ;
return 0 ;
}
static int F_4 ( unsigned int V_1 )
{
int V_2 = 0 ;
if ( V_1 > 31 )
return - V_3 ;
if ( V_1 <= 8 )
V_2 = V_1 * 50000 + 1500000 ;
else if ( V_1 <= 13 )
V_2 = ( V_1 - 8 ) * 100000 + 1900000 ;
else
V_2 = ( V_1 - 13 ) * 50000 + 2400000 ;
return V_2 ;
}
static int F_5 ( int V_2 , unsigned int * V_1 )
{
if ( V_2 < 0 || V_2 > 3300000 )
return - V_3 ;
if ( V_2 <= 1900000 )
* V_1 = F_3 ( V_2 - 1500000 , 50000 ) ;
else if ( V_2 <= 2400000 )
* V_1 = 8 + F_3 ( V_2 - 1900000 , 100000 ) ;
else
* V_1 = 13 + F_3 ( V_2 - 2400000 , 50000 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_7 ( V_5 ) ;
unsigned int V_8 = F_8 ( V_5 ) ;
if ( V_8 < V_9 || V_8 > V_10 )
return - V_3 ;
return F_9 ( V_7 , V_11 ,
V_5 -> V_12 -> V_13 , V_5 -> V_12 -> V_13 ,
V_14 ) ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_7 ( V_5 ) ;
unsigned int V_8 = F_8 ( V_5 ) ;
if ( V_8 < V_9 || V_8 > V_10 )
return - V_3 ;
return F_11 ( V_7 , V_11 ,
V_5 -> V_12 -> V_13 , V_14 ) ;
}
static int F_12 ( struct V_4 * V_5 ,
unsigned V_15 )
{
int V_16 ;
struct V_6 * V_7 = F_7 ( V_5 ) ;
unsigned int V_8 = F_8 ( V_5 ) ;
V_16 = F_9 ( V_7 , V_5 -> V_12 -> V_17 , V_5 -> V_12 -> V_18 ,
V_15 , V_19 ) ;
switch ( V_8 ) {
case V_9 ... V_20 :
V_16 = F_9 ( V_7 , V_21 ,
V_22 , V_22 ,
V_19 ) ;
break;
}
return V_16 ;
}
static int F_13 ( struct V_4 * V_5 ,
int V_23 , int V_24 )
{
struct V_6 * V_7 = F_7 ( V_5 ) ;
unsigned int V_25 , V_8 = F_8 ( V_5 ) ;
int V_16 ;
if ( V_8 == V_26 )
return - V_3 ;
if ( V_8 < V_9 || V_8 > V_10 )
return - V_3 ;
if ( V_23 < V_7 -> V_27 [ V_8 ] -> V_23 )
V_23 = V_7 -> V_27 [ V_8 ] -> V_23 ;
if ( V_24 < V_7 -> V_27 [ V_8 ] -> V_23 || V_23 > V_7 -> V_27 [ V_8 ] -> V_24 )
return - V_3 ;
V_16 = V_7 -> V_27 [ V_8 ] -> F_14 ( V_23 , & V_25 ) ;
if ( V_16 )
return V_16 ;
return V_25 ;
}
static int F_15 ( struct V_4 * V_5 ,
unsigned V_15 )
{
struct V_6 * V_7 = F_7 ( V_5 ) ;
unsigned int V_8 = F_8 ( V_5 ) ;
if ( V_8 < V_9 || V_8 > V_10 )
return - V_3 ;
if ( V_15 >= V_5 -> V_12 -> V_28 )
return - V_3 ;
return V_7 -> V_27 [ V_8 ] -> F_16 ( V_15 ) ;
}
static struct V_29 * F_17 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_18 ( V_31 -> V_5 . V_32 ) ;
struct V_33 * V_34 = V_7 -> V_5 -> V_35 ;
struct V_29 * V_36 ;
struct V_33 * V_37 ;
int V_38 , V_39 ;
V_37 = F_19 ( V_34 , L_1 ) ;
if ( ! V_37 )
return NULL ;
V_39 = F_20 ( V_31 -> V_5 . V_32 , V_37 ,
V_40 , V_41 ) ;
F_21 ( V_37 ) ;
if ( ( V_39 < 0 ) || ( V_39 > V_41 ) )
return NULL ;
V_36 = F_22 ( & V_31 -> V_5 , sizeof( * V_36 ) , V_42 ) ;
if ( ! V_36 )
return NULL ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
if ( ! V_40 [ V_38 ] . V_43 || ! V_40 [ V_38 ] . V_35 )
continue;
V_36 -> V_44 [ V_38 ] = V_40 [ V_38 ] . V_43 ;
V_36 -> V_35 [ V_38 ] = V_40 [ V_38 ] . V_35 ;
}
return V_36 ;
}
static struct V_29 * F_17 ( struct V_30 * V_31 )
{
return NULL ;
}
static int T_1 F_23 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_18 ( V_31 -> V_5 . V_32 ) ;
struct V_29 * V_36 = F_24 ( V_7 -> V_5 ) ;
struct V_45 * V_46 ;
struct V_4 * V_47 ;
struct V_48 V_49 = { } ;
int V_38 , V_16 ;
if ( V_7 -> V_5 -> V_35 )
V_36 = F_17 ( V_31 ) ;
if ( ! V_36 ) {
F_25 ( & V_31 -> V_5 , L_2 ) ;
return - V_3 ;
}
if ( F_26 ( V_7 ) != V_50 ) {
F_25 ( & V_31 -> V_5 , L_3 ) ;
return - V_51 ;
}
F_27 ( V_31 , V_7 ) ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ ) {
V_46 = V_36 -> V_44 [ V_38 ] ;
if ( ! V_46 )
continue;
V_7 -> V_27 [ V_38 ] = & V_52 [ V_38 ] ;
V_49 . V_5 = V_7 -> V_5 ;
V_49 . V_43 = V_46 ;
V_49 . V_53 = V_7 ;
V_49 . V_54 = V_7 -> V_54 ;
if ( V_7 -> V_5 -> V_35 )
V_49 . V_35 = V_36 -> V_35 [ V_38 ] ;
V_47 = F_28 ( & V_55 [ V_38 ] , & V_49 ) ;
if ( F_29 ( V_47 ) ) {
F_25 ( V_7 -> V_5 , L_4 ,
V_31 -> V_56 ) ;
V_16 = F_30 ( V_47 ) ;
goto V_57;
}
V_7 -> V_47 [ V_38 ] = V_47 ;
}
return 0 ;
V_57:
while ( -- V_38 >= 0 )
F_31 ( V_7 -> V_47 [ V_38 ] ) ;
return V_16 ;
}
static int T_2 F_32 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_33 ( V_31 ) ;
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ )
F_31 ( V_7 -> V_47 [ V_38 ] ) ;
F_27 ( V_31 , NULL ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_58 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_58 ) ;
}
