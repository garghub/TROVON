static inline void F_1 ( const struct V_1 * V_2 )
{
if ( V_3 ) {
T_1 V_4 = F_2 ( F_3 () , V_2 -> V_5 ) ;
if ( V_4 < V_3 )
F_4 ( V_3 - V_4 ) ;
}
}
static int F_5 ( struct V_6 * V_7 , int V_8 , int V_9 )
{
const struct V_10 * V_11 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 ;
if ( V_8 || V_9 >= V_13 )
return - V_14 ;
F_1 ( V_2 ) ;
V_12 = F_8 ( V_7 , V_8 , V_9 ) ;
V_2 -> V_5 = F_3 () ;
return V_12 ;
}
static int F_9 ( struct V_6 * V_7 , int V_8 , int V_9 )
{
const struct V_10 * V_11 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 ;
if ( V_8 > 0 )
return - V_14 ;
F_1 ( V_2 ) ;
V_12 = F_10 ( V_7 , V_8 , V_9 ) ;
V_2 -> V_5 = F_3 () ;
return V_12 ;
}
static int F_11 ( struct V_6 * V_7 , int V_8 , int V_9 ,
T_2 V_15 )
{
const struct V_10 * V_11 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 ;
if ( V_8 || V_9 >= V_13 )
return - V_14 ;
F_1 ( V_2 ) ;
V_12 = F_12 ( V_7 , V_8 , V_9 , V_15 ) ;
V_2 -> V_5 = F_3 () ;
return V_12 ;
}
static int F_13 ( struct V_6 * V_7 , int V_8 , T_3 V_16 )
{
const struct V_10 * V_11 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 ;
if ( V_8 > 0 )
return - V_14 ;
F_1 ( V_2 ) ;
V_12 = F_14 ( V_7 , V_8 , V_16 ) ;
V_2 -> V_5 = F_3 () ;
return V_12 ;
}
static int F_15 ( struct V_6 * V_7 ,
const struct V_17 * V_18 )
{
int V_12 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
T_3 V_19 [ V_20 + 1 ] ;
const struct V_17 * V_21 ;
if ( ! F_16 ( V_7 -> V_22 ,
V_23
| V_24 ) )
return - V_25 ;
V_12 = F_17 ( V_7 , V_26 ,
V_19 ) ;
if ( V_12 < 0 ) {
F_18 ( & V_7 -> V_27 , L_1 ) ;
return V_12 ;
}
V_19 [ V_12 ] = '\0' ;
F_19 ( & V_7 -> V_27 , L_2 , V_19 ) ;
V_21 = NULL ;
for ( V_21 = V_28 ; V_21 -> V_29 [ 0 ] ; V_21 ++ ) {
if ( ! strncasecmp ( V_21 -> V_29 , V_19 , strlen ( V_21 -> V_29 ) ) )
break;
}
if ( ! V_21 -> V_29 [ 0 ] ) {
F_18 ( & V_7 -> V_27 , L_3 ) ;
return - V_25 ;
}
if ( V_18 -> V_30 != V_21 -> V_30 )
F_20 ( & V_7 -> V_27 ,
L_4 ,
V_18 -> V_29 , V_21 -> V_29 ) ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
V_2 -> V_18 = V_21 -> V_30 ;
if ( V_2 -> V_18 == V_33 || V_2 -> V_18 == V_34 )
V_3 = 0 ;
V_2 -> V_5 = F_3 () ;
F_1 ( V_2 ) ;
V_2 -> V_5 = F_3 () ;
V_11 = & V_2 -> V_11 ;
V_11 -> V_35 = 1 ;
V_11 -> V_36 [ 0 ] = V_37 | V_38
| V_39 | V_40
| V_41 | V_42
| V_43 | V_44 | V_45 ;
V_11 -> V_46 = F_5 ;
V_11 -> V_47 = F_9 ;
V_11 -> V_48 = F_11 ;
V_11 -> V_49 = F_13 ;
V_12 = F_22 ( V_7 , V_21 , V_11 ) ;
if ( V_12 )
goto V_50;
return 0 ;
V_50:
F_23 ( V_2 ) ;
return V_12 ;
}
static int F_24 ( struct V_6 * V_7 )
{
const struct V_10 * V_11 = F_6 ( V_7 ) ;
const struct V_1 * V_2 = F_7 ( V_11 ) ;
F_25 ( V_7 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int T_4 F_26 ( void )
{
return F_27 ( & V_51 ) ;
}
static void T_5 F_28 ( void )
{
F_29 ( & V_51 ) ;
}
