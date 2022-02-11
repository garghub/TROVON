static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_7 ) ;
struct V_11 * V_12 = F_3 ( V_10 ) ;
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ ) {
if ( V_2 == & V_12 -> V_14 [ V_5 ] )
break;
}
if ( V_5 < V_13 ) {
V_12 -> V_15 [ V_5 ] = V_4 ;
F_4 ( & V_12 -> V_16 ) ;
}
}
static T_1 F_5 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
char * V_19 )
{
T_2 V_20 ;
struct V_9 * V_10 = F_2 ( V_7 -> V_8 ) ;
struct V_11 * V_12 = F_3 ( V_10 ) ;
if ( V_12 -> V_21 == V_22 )
V_20 = 0 ;
else if ( V_12 -> V_21 == V_23 )
V_20 = 1 ;
else
V_20 = 2 ;
return F_6 ( V_19 , V_24 , L_1 , V_20 ) ;
}
static T_1 F_7 ( struct V_6 * V_7 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_25 )
{
T_2 V_20 ;
struct V_9 * V_10 = F_2 ( V_7 -> V_8 ) ;
struct V_11 * V_12 = F_3 ( V_10 ) ;
if ( F_8 ( V_19 , 10 , & V_20 ) || V_20 > 2 )
return - V_26 ;
F_9 ( & V_12 -> V_27 ) ;
if ( V_20 == 0 )
V_12 -> V_21 = V_22 ;
else if ( V_20 == 1 )
V_12 -> V_21 = V_23 ;
else
V_12 -> V_21 = V_28 ;
F_10 ( & V_12 -> V_27 ) ;
F_4 ( & V_12 -> V_16 ) ;
return V_25 ;
}
static int F_11 ( struct V_11 * V_12 , T_2 * V_29 )
{
int V_30 ;
V_30 = F_12 ( V_12 -> V_10 , V_29 [ 0 ] , V_29 , V_31 ,
V_32 , V_33 ) ;
if ( V_30 != V_31 ) {
F_13 ( V_12 -> V_10 ,
L_2 , V_30 ) ;
if ( V_30 < 0 )
return V_30 ;
return - V_34 ;
}
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , T_2 V_35 )
{
int V_30 ;
T_2 * V_36 ;
V_36 = F_15 ( V_31 , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_36 [ 0 ] = 0x01 ;
V_36 [ 1 ] = 0x02 ;
V_36 [ 2 ] = 0x30 ;
V_36 [ 3 ] = V_35 ;
V_30 = F_11 ( V_12 , V_36 ) ;
F_16 ( V_36 ) ;
return V_30 ;
}
static int F_17 ( struct V_11 * V_12 , T_2 V_21 )
{
int V_30 ;
T_2 * V_36 ;
V_36 = F_15 ( V_31 , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_36 [ 0 ] = 0x01 ;
V_36 [ 1 ] = 0x02 ;
V_36 [ 2 ] = 0x20 ;
V_36 [ 3 ] = V_21 ;
V_36 [ 4 ] = 0x01 ;
V_30 = F_11 ( V_12 , V_36 ) ;
F_16 ( V_36 ) ;
return V_30 ;
}
static void F_18 ( struct V_39 * V_16 )
{
int V_5 ;
T_2 V_35 = 0 ;
T_2 V_21 ;
struct V_11 * V_12 = F_19 ( V_16 , struct V_11 , V_16 ) ;
F_9 ( & V_12 -> V_27 ) ;
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ ) {
if ( V_12 -> V_15 [ V_5 ] )
V_35 |= F_20 ( V_5 ) ;
}
if ( F_14 ( V_12 , V_35 ) )
goto V_40;
if ( V_35 )
V_21 = V_12 -> V_21 ;
else
V_21 = V_41 ;
F_17 ( V_12 , V_21 ) ;
V_40:
F_10 ( & V_12 -> V_27 ) ;
}
static int F_21 ( struct V_9 * V_10 ,
const struct V_42 * V_43 )
{
int V_5 ;
int V_30 ;
int V_44 ;
char * V_45 ;
struct V_11 * V_12 ;
V_12 = F_22 ( & V_10 -> V_7 , sizeof( * V_12 ) , V_37 ) ;
if ( ! V_12 )
return - V_38 ;
F_23 ( & V_12 -> V_27 ) ;
F_24 ( & V_12 -> V_16 , F_18 ) ;
V_12 -> V_21 = V_22 ;
V_12 -> V_10 = V_10 ;
F_25 ( V_10 , V_12 ) ;
V_30 = F_26 ( V_10 ) ;
if ( V_30 ) {
F_13 ( V_10 , L_3 ) ;
return V_30 ;
}
V_30 = F_27 ( V_10 , V_46 ) ;
if ( V_30 ) {
F_13 ( V_10 , L_4 ) ;
return V_30 ;
}
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ ) {
V_44 = strlen ( F_28 ( & V_10 -> V_7 ) ) +
strlen ( V_47 [ V_5 ] ) + 3 ;
V_45 = F_22 ( & V_10 -> V_7 , V_44 , V_37 ) ;
if ( ! V_45 ) {
V_30 = - V_38 ;
goto V_40;
}
snprintf ( V_45 , V_44 , L_5 ,
F_28 ( & V_10 -> V_7 ) , V_47 [ V_5 ] ) ;
V_12 -> V_14 [ V_5 ] . V_45 = V_45 ;
V_12 -> V_14 [ V_5 ] . V_48 = 1 ;
V_12 -> V_14 [ V_5 ] . V_49 = F_1 ;
V_12 -> V_14 [ V_5 ] . V_50 = V_51 ;
V_30 = F_29 ( & V_10 -> V_7 , & V_12 -> V_14 [ V_5 ] ) ;
if ( V_30 ) {
F_13 ( V_10 , L_6 ) ;
goto V_40;
}
}
return 0 ;
V_40:
for ( V_5 = V_5 - 1 ; V_5 >= 0 ; V_5 -- )
F_30 ( & V_12 -> V_14 [ V_5 ] ) ;
F_31 ( V_10 ) ;
return V_30 ;
}
static void F_32 ( struct V_9 * V_10 )
{
int V_5 ;
struct V_11 * V_12 = F_3 ( V_10 ) ;
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ )
F_30 ( & V_12 -> V_14 [ V_5 ] ) ;
F_33 ( & V_12 -> V_16 ) ;
F_31 ( V_10 ) ;
}
