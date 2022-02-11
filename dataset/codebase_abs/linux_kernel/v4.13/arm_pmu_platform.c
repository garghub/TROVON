static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = F_2 () ;
unsigned int V_6 = F_3 () ;
int V_7 = - V_8 ;
F_4 ( L_1 , V_5 ) ;
for (; V_4 -> V_9 != NULL ; V_4 ++ ) {
if ( ( V_6 & V_4 -> V_10 ) != V_4 -> V_6 )
continue;
V_7 = V_4 -> V_9 ( V_2 ) ;
break;
}
F_5 () ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , int V_11 )
{
int V_5 , V_7 ;
struct V_12 T_1 * V_13 = V_2 -> V_13 ;
V_7 = F_7 ( V_11 , & V_2 -> V_14 ) ;
if ( V_7 )
return V_7 ;
F_8 (cpu, &pmu->supported_cpus)
F_9 ( V_13 -> V_11 , V_5 ) = V_11 ;
return 0 ;
}
static bool F_10 ( struct V_15 * V_16 )
{
return ! ! F_11 ( V_16 , L_2 , NULL ) ;
}
static int F_12 ( struct V_15 * V_16 , int V_17 )
{
struct V_15 * V_18 ;
int V_5 ;
if ( ! F_10 ( V_16 ) )
return V_17 ;
V_18 = F_13 ( V_16 , L_2 , V_17 ) ;
if ( ! V_18 ) {
F_14 ( L_3 ,
V_17 , V_16 -> V_19 ) ;
return - V_20 ;
}
F_15 (cpu) {
struct V_15 * V_21 ;
V_21 = F_16 ( V_5 ) ;
F_17 ( V_21 ) ;
if ( V_18 == V_21 )
break;
}
if ( V_5 >= V_22 ) {
F_14 ( L_4 , V_18 -> V_19 ) ;
}
F_17 ( V_18 ) ;
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_17 = 0 , V_23 ;
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_12 T_1 * V_13 = V_2 -> V_13 ;
V_23 = F_19 ( V_25 ) ;
if ( V_23 < 0 ) {
F_20 ( L_5 ) ;
return V_23 ;
}
if ( V_23 == 0 ) {
F_14 ( L_6 ) ;
V_2 -> V_2 . V_27 |= V_28 ;
F_21 ( & V_2 -> V_14 ) ;
return 0 ;
}
if ( V_23 == 1 ) {
int V_11 = F_22 ( V_25 , 0 ) ;
if ( V_11 && F_23 ( V_11 ) )
return F_6 ( V_2 , V_11 ) ;
}
if ( ! F_10 ( V_25 -> V_29 . V_30 ) ) {
F_14 ( L_7 ,
V_25 -> V_29 . V_30 ) ;
}
if ( F_24 ( & V_25 -> V_29 ) )
F_21 ( & V_2 -> V_14 ) ;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ ) {
int V_5 , V_11 ;
V_11 = F_22 ( V_25 , V_17 ) ;
if ( F_25 ( V_11 <= 0 ) )
continue;
if ( F_23 ( V_11 ) ) {
F_14 ( L_8 ) ;
return - V_20 ;
}
V_5 = F_12 ( V_25 -> V_29 . V_30 , V_17 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 >= V_22 )
continue;
if ( F_9 ( V_13 -> V_11 , V_5 ) ) {
F_14 ( L_9 ) ;
return - V_20 ;
}
F_9 ( V_13 -> V_11 , V_5 ) = V_11 ;
F_26 ( V_5 , & V_2 -> V_14 ) ;
}
return 0 ;
}
int F_27 ( struct V_24 * V_25 ,
const struct V_31 * V_32 ,
const struct V_3 * V_33 )
{
const struct V_31 * V_34 ;
T_2 V_35 ;
struct V_15 * V_16 = V_25 -> V_29 . V_30 ;
struct V_1 * V_2 ;
int V_7 = - V_8 ;
V_2 = F_28 () ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_26 = V_25 ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 )
goto V_37;
if ( V_16 && ( V_34 = F_29 ( V_32 , V_25 -> V_29 . V_30 ) ) ) {
V_35 = V_34 -> V_38 ;
V_2 -> V_39 = F_30 ( V_25 -> V_29 . V_30 ,
L_10 ) ;
if ( F_31 ( V_40 ) && V_2 -> V_39 ) {
F_14 ( L_11 ) ;
V_2 -> V_39 = false ;
}
V_7 = V_35 ( V_2 ) ;
} else if ( V_33 ) {
F_21 ( & V_2 -> V_14 ) ;
V_7 = F_1 ( V_2 , V_33 ) ;
}
if ( V_7 ) {
F_4 ( L_12 , V_16 ) ;
goto V_37;
}
V_7 = F_32 ( V_2 ) ;
if ( V_7 )
goto V_41;
V_7 = F_33 ( V_2 ) ;
if ( V_7 )
goto V_37;
return 0 ;
V_41:
F_34 ( V_2 ) ;
V_37:
F_4 ( L_13 , V_16 ) ;
F_35 ( V_2 ) ;
return V_7 ;
}
