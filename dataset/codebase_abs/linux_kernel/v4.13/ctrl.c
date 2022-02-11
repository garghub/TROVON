static int
F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
union {
struct V_5 V_6 ;
} * args = V_3 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
int V_10 = - V_11 ;
F_2 ( & V_2 -> V_12 , L_1 , V_4 ) ;
if ( ! ( V_10 = F_3 ( V_10 , & V_3 , & V_4 , args -> V_6 , 0 , 0 , false ) ) ) {
F_2 ( & V_2 -> V_12 , L_2 ,
args -> V_6 . V_13 ) ;
} else
return V_10 ;
if ( V_8 ) {
args -> V_6 . V_14 = V_8 -> V_15 ;
args -> V_6 . V_16 = V_8 -> V_16 ;
args -> V_6 . V_17 = V_8 -> V_17 ;
args -> V_6 . V_18 = V_8 -> V_18 ;
args -> V_6 . V_19 = V_8 -> V_19 ;
} else {
args -> V_6 . V_14 = 0 ;
args -> V_6 . V_16 = V_20 ;
args -> V_6 . V_17 = V_20 ;
args -> V_6 . V_18 = - V_11 ;
args -> V_6 . V_19 = V_21 ;
}
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
union {
struct V_22 V_6 ;
} * args = V_3 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
const struct V_23 * V_24 ;
struct V_25 * V_19 ;
struct V_26 * V_27 ;
int V_28 = 0 , V_29 = - 1 ;
T_1 V_30 , V_31 ;
int V_10 = - V_11 ;
F_2 ( & V_2 -> V_12 , L_3 , V_4 ) ;
if ( ! ( V_10 = F_3 ( V_10 , & V_3 , & V_4 , args -> V_6 , 0 , 0 , false ) ) ) {
F_2 ( & V_2 -> V_12 ,
L_4 ,
args -> V_6 . V_13 , args -> V_6 . V_32 , args -> V_6 . V_33 ) ;
if ( ! V_8 )
return - V_34 ;
if ( args -> V_6 . V_32 < V_35 )
return - V_36 ;
if ( args -> V_6 . V_32 >= V_8 -> V_15 )
return - V_36 ;
} else
return V_10 ;
V_24 = V_8 -> V_37 ;
while ( V_24 -> V_38 != V_39 ) {
if ( V_24 -> V_40 && ++ V_29 == args -> V_6 . V_33 )
break;
V_24 ++ ;
}
if ( V_24 -> V_38 == V_39 )
return - V_36 ;
if ( args -> V_6 . V_32 != V_35 ) {
F_5 (pstate, &clk->states, head) {
if ( V_28 ++ == args -> V_6 . V_32 )
break;
}
V_30 = V_19 -> V_41 . V_24 [ V_24 -> V_38 ] ;
V_31 = V_30 ;
F_5 (cstate, &pstate->list, head) {
V_30 = F_6 ( V_30 , V_27 -> V_24 [ V_24 -> V_38 ] ) ;
V_31 = F_7 ( V_31 , V_27 -> V_24 [ V_24 -> V_38 ] ) ;
}
args -> V_6 . V_32 = V_19 -> V_19 ;
} else {
V_30 = F_7 ( F_8 ( V_8 , V_24 -> V_38 ) , 0 ) ;
V_31 = V_30 ;
}
snprintf ( args -> V_6 . V_38 , sizeof( args -> V_6 . V_38 ) , L_5 , V_24 -> V_40 ) ;
snprintf ( args -> V_6 . V_42 , sizeof( args -> V_6 . V_42 ) , L_6 ) ;
args -> V_6 . F_6 = V_30 / V_24 -> V_43 ;
args -> V_6 . F_7 = V_31 / V_24 -> V_43 ;
args -> V_6 . V_33 = 0 ;
while ( ( ++ V_24 ) -> V_38 != V_39 ) {
if ( V_24 -> V_40 ) {
args -> V_6 . V_33 = ++ V_29 ;
break;
}
}
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
union {
struct V_44 V_6 ;
} * args = V_3 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
int V_10 = - V_11 ;
F_2 ( & V_2 -> V_12 , L_7 , V_4 ) ;
if ( ! ( V_10 = F_3 ( V_10 , & V_3 , & V_4 , args -> V_6 , 0 , 0 , false ) ) ) {
F_2 ( & V_2 -> V_12 ,
L_8 ,
args -> V_6 . V_13 , args -> V_6 . V_45 , args -> V_6 . V_18 ) ;
if ( ! V_8 )
return - V_34 ;
} else
return V_10 ;
if ( args -> V_6 . V_18 >= 0 ) {
V_10 |= F_10 ( V_8 , args -> V_6 . V_45 , args -> V_6 . V_18 ) ;
} else {
V_10 |= F_10 ( V_8 , args -> V_6 . V_45 , 0 ) ;
V_10 |= F_10 ( V_8 , args -> V_6 . V_45 , 1 ) ;
}
return V_10 ;
}
static int
F_11 ( struct V_46 * V_12 , T_1 V_47 , void * V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_1 ( V_12 ) ;
switch ( V_47 ) {
case V_48 :
return F_1 ( V_2 , V_3 , V_4 ) ;
case V_49 :
return F_4 ( V_2 , V_3 , V_4 ) ;
case V_50 :
return F_9 ( V_2 , V_3 , V_4 ) ;
default:
break;
}
return - V_36 ;
}
static int
F_12 ( struct V_51 * V_9 , const struct V_52 * V_53 ,
void * V_3 , T_1 V_4 , struct V_46 * * V_54 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = F_13 ( sizeof( * V_2 ) , V_55 ) ) )
return - V_56 ;
* V_54 = & V_2 -> V_12 ;
V_2 -> V_9 = V_9 ;
F_14 ( & V_1 , V_53 , & V_2 -> V_12 ) ;
return 0 ;
}
