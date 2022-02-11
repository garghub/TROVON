static int
F_1 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 )
{
union {
struct V_5 V_6 ;
} * args = V_3 ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
int V_9 ;
F_2 ( V_2 , L_1 , V_4 ) ;
if ( F_3 ( args -> V_6 , 0 , 0 , false ) ) {
F_2 ( V_2 , L_2 ,
args -> V_6 . V_10 ) ;
} else
return V_9 ;
if ( V_8 ) {
args -> V_6 . V_11 = V_8 -> V_12 ;
args -> V_6 . V_13 = V_8 -> V_13 ;
args -> V_6 . V_14 = V_8 -> V_14 ;
args -> V_6 . V_15 = V_8 -> V_15 ;
args -> V_6 . V_16 = V_8 -> V_16 ;
} else {
args -> V_6 . V_11 = 0 ;
args -> V_6 . V_13 = V_17 ;
args -> V_6 . V_14 = V_17 ;
args -> V_6 . V_15 = - V_18 ;
args -> V_6 . V_16 = V_19 ;
}
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 )
{
union {
struct V_20 V_6 ;
} * args = V_3 ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_21 * V_22 ;
struct V_23 * V_16 ;
struct V_24 * V_25 ;
int V_26 = 0 , V_27 = - 1 ;
T_1 V_28 , V_29 ;
int V_9 ;
F_2 ( V_2 , L_3 , V_4 ) ;
if ( F_3 ( args -> V_6 , 0 , 0 , false ) ) {
F_2 ( V_2 , L_4
L_5 ,
args -> V_6 . V_10 , args -> V_6 . V_30 , args -> V_6 . V_31 ) ;
if ( ! V_8 )
return - V_32 ;
if ( args -> V_6 . V_30 < V_33 )
return - V_34 ;
if ( args -> V_6 . V_30 >= V_8 -> V_12 )
return - V_34 ;
} else
return V_9 ;
V_22 = V_8 -> V_35 ;
while ( V_22 -> V_36 != V_37 ) {
if ( V_22 -> V_38 && ++ V_27 == args -> V_6 . V_31 )
break;
V_22 ++ ;
}
if ( V_22 -> V_36 == V_37 )
return - V_34 ;
if ( args -> V_6 . V_30 != V_33 ) {
F_5 (pstate, &clk->states, head) {
if ( V_26 ++ == args -> V_6 . V_30 )
break;
}
V_28 = V_16 -> V_39 . V_22 [ V_22 -> V_36 ] ;
V_29 = V_28 ;
F_5 (cstate, &pstate->list, head) {
V_28 = F_6 ( V_28 , V_25 -> V_22 [ V_22 -> V_36 ] ) ;
V_29 = F_7 ( V_29 , V_25 -> V_22 [ V_22 -> V_36 ] ) ;
}
args -> V_6 . V_30 = V_16 -> V_16 ;
} else {
V_28 = F_7 ( V_8 -> V_40 ( V_8 , V_22 -> V_36 ) , 0 ) ;
V_29 = V_28 ;
}
snprintf ( args -> V_6 . V_36 , sizeof( args -> V_6 . V_36 ) , L_6 , V_22 -> V_38 ) ;
snprintf ( args -> V_6 . V_41 , sizeof( args -> V_6 . V_41 ) , L_7 ) ;
args -> V_6 . F_6 = V_28 / V_22 -> V_42 ;
args -> V_6 . F_7 = V_29 / V_22 -> V_42 ;
args -> V_6 . V_31 = 0 ;
while ( ( ++ V_22 ) -> V_36 != V_37 ) {
if ( V_22 -> V_38 ) {
args -> V_6 . V_31 = ++ V_27 ;
break;
}
}
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 )
{
union {
struct V_43 V_6 ;
} * args = V_3 ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
int V_9 ;
F_2 ( V_2 , L_8 , V_4 ) ;
if ( F_3 ( args -> V_6 , 0 , 0 , false ) ) {
F_2 ( V_2 , L_9
L_10 , args -> V_6 . V_10 ,
args -> V_6 . V_44 , args -> V_6 . V_15 ) ;
if ( ! V_8 )
return - V_32 ;
} else
return V_9 ;
if ( args -> V_6 . V_15 >= 0 ) {
V_9 |= F_9 ( V_8 , args -> V_6 . V_44 , args -> V_6 . V_15 ) ;
} else {
V_9 |= F_9 ( V_8 , args -> V_6 . V_44 , 0 ) ;
V_9 |= F_9 ( V_8 , args -> V_6 . V_44 , 1 ) ;
}
return V_9 ;
}
static int
F_10 ( struct V_1 * V_2 , T_1 V_45 ,
void * V_3 , T_1 V_4 )
{
switch ( V_45 ) {
case V_46 :
return F_1 ( V_2 , V_3 , V_4 ) ;
case V_47 :
return F_4 ( V_2 , V_3 , V_4 ) ;
case V_48 :
return F_8 ( V_2 , V_3 , V_4 ) ;
default:
break;
}
return - V_34 ;
}
