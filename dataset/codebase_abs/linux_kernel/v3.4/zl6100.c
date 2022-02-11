static inline void F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
T_1 V_4 = F_2 ( F_3 () , V_2 -> V_5 ) ;
if ( V_4 < V_2 -> V_3 )
F_4 ( V_2 -> V_3 - V_4 ) ;
}
}
static int F_5 ( struct V_6 * V_7 , int V_8 , int V_9 )
{
const struct V_10 * V_11 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 ;
if ( V_8 || V_9 >= V_13 )
return - V_14 ;
if ( V_2 -> V_15 == V_16 ) {
switch ( V_9 ) {
case V_17 :
case V_18 :
case V_19 :
return - V_14 ;
}
}
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
T_2 V_20 )
{
const struct V_10 * V_11 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 ;
if ( V_8 || V_9 >= V_13 )
return - V_14 ;
F_1 ( V_2 ) ;
V_12 = F_12 ( V_7 , V_8 , V_9 , V_20 ) ;
V_2 -> V_5 = F_3 () ;
return V_12 ;
}
static int F_13 ( struct V_6 * V_7 , int V_8 , T_3 V_21 )
{
const struct V_10 * V_11 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_12 ;
if ( V_8 > 0 )
return - V_14 ;
F_1 ( V_2 ) ;
V_12 = F_14 ( V_7 , V_8 , V_21 ) ;
V_2 -> V_5 = F_3 () ;
return V_12 ;
}
static int F_15 ( struct V_6 * V_7 ,
const struct V_22 * V_15 )
{
int V_12 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
T_3 V_23 [ V_24 + 1 ] ;
const struct V_22 * V_25 ;
if ( ! F_16 ( V_7 -> V_26 ,
V_27
| V_28 ) )
return - V_29 ;
V_12 = F_17 ( V_7 , V_30 ,
V_23 ) ;
if ( V_12 < 0 ) {
F_18 ( & V_7 -> V_31 , L_1 ) ;
return V_12 ;
}
V_23 [ V_12 ] = '\0' ;
F_19 ( & V_7 -> V_31 , L_2 , V_23 ) ;
V_25 = NULL ;
for ( V_25 = V_32 ; V_25 -> V_33 [ 0 ] ; V_25 ++ ) {
if ( ! strncasecmp ( V_25 -> V_33 , V_23 , strlen ( V_25 -> V_33 ) ) )
break;
}
if ( ! V_25 -> V_33 [ 0 ] ) {
F_18 ( & V_7 -> V_31 , L_3 ) ;
return - V_29 ;
}
if ( V_15 -> V_34 != V_25 -> V_34 )
F_20 ( & V_7 -> V_31 ,
L_4 ,
V_15 -> V_33 , V_25 -> V_33 ) ;
V_2 = F_21 ( & V_7 -> V_31 , sizeof( struct V_1 ) ,
V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_15 = V_25 -> V_34 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = F_3 () ;
F_1 ( V_2 ) ;
V_11 = & V_2 -> V_11 ;
V_11 -> V_37 = 1 ;
V_11 -> V_38 [ 0 ] = V_39 | V_40
| V_41 | V_42
| V_43 | V_44
| V_45 | V_46 ;
V_12 = F_22 ( V_7 , V_47 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & V_48 )
V_11 -> V_38 [ 0 ] |= V_49 ;
V_2 -> V_5 = F_3 () ;
F_1 ( V_2 ) ;
V_11 -> V_50 = F_5 ;
V_11 -> V_51 = F_9 ;
V_11 -> V_52 = F_11 ;
V_11 -> V_53 = F_13 ;
return F_23 ( V_7 , V_25 , V_11 ) ;
}
