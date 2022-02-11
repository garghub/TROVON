static inline const struct V_1 * F_1 ( int V_2 )
{
return F_2 ( 0 ) ;
}
static void F_3 ( struct V_3 * V_4 ,
int V_5 )
{
int V_6 , V_7 ;
for ( V_6 = 1 ; V_6 < V_5 ; V_6 ++ ) {
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
if ( V_4 [ V_7 ] . V_8 == V_9 ||
V_4 [ V_7 ] . V_8 !=
V_4 [ V_6 ] . V_8 )
continue;
V_4 [ V_6 ] . V_8 = V_9 ;
break;
}
}
}
static void F_4 ( struct V_3 * V_4 ,
int V_5 )
{
int V_6 , V_7 , V_10 ;
unsigned int V_11 , V_12 ;
struct V_3 V_13 ;
for ( V_6 = 0 ; V_6 < V_5 - 1 ; V_6 ++ ) {
V_12 = V_4 [ V_6 ] . V_8 ;
V_10 = V_6 ;
for ( V_7 = V_6 + 1 ; V_7 < V_5 ; V_7 ++ ) {
V_11 = V_4 [ V_7 ] . V_8 ;
if ( V_11 == V_9 ||
V_11 <= V_12 )
continue;
V_10 = V_7 ;
V_12 = V_11 ;
}
if ( V_10 != V_6 ) {
V_13 . V_14 = V_4 [ V_6 ] . V_14 ;
V_13 . V_8 = V_4 [ V_6 ] . V_8 ;
V_4 [ V_6 ] . V_14 = V_4 [ V_10 ] . V_14 ;
V_4 [ V_6 ] . V_8 = V_4 [ V_10 ] . V_8 ;
V_4 [ V_10 ] . V_14 = V_13 . V_14 ;
V_4 [ V_10 ] . V_8 = V_13 . V_8 ;
}
}
}
static int F_5 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
int V_6 , V_5 , V_19 ;
T_1 V_11 , V_20 ;
struct V_21 * V_21 ;
struct V_3 * V_13 ;
struct V_22 * V_23 ;
unsigned int V_2 = V_16 -> V_2 ;
T_2 V_24 ;
V_18 = F_6 ( V_2 , NULL ) ;
if ( ! V_18 )
return - V_25 ;
V_23 = F_7 ( sizeof( * V_23 ) , V_26 ) ;
if ( ! V_23 ) {
F_8 ( L_1 , V_27 ) ;
goto V_28;
}
V_16 -> V_21 = F_9 ( V_18 , 0 ) ;
if ( F_10 ( V_16 -> V_21 ) ) {
F_8 ( L_2 , V_27 ) ;
goto V_29;
}
V_23 -> V_30 = F_11 ( V_18 , L_3 , 0 ) ;
if ( ! V_23 -> V_30 ) {
F_8 ( L_4 , V_27 ) ;
goto V_29;
}
V_5 = F_12 ( V_23 -> V_30 , L_5 ) ;
V_13 = F_13 ( V_5 + 1 , sizeof( * V_13 ) , V_26 ) ;
if ( ! V_13 ) {
F_8 ( L_1 , V_27 ) ;
goto V_31;
}
if ( V_32 )
V_20 = V_32 [ F_14 ( V_2 ) ] ;
else
V_20 = 0x0 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_21 = F_9 ( V_23 -> V_30 , V_6 ) ;
V_11 = F_15 ( V_21 ) ;
if ( V_11 < V_33 || ( V_20 & ( 1 << V_6 ) ) )
V_13 [ V_6 ] . V_8 = V_9 ;
else
V_13 [ V_6 ] . V_8 = V_11 / 1000 ;
V_13 [ V_6 ] . V_14 = V_6 ;
}
F_3 ( V_13 , V_5 ) ;
F_4 ( V_13 , V_5 ) ;
V_13 [ V_6 ] . V_8 = V_34 ;
V_19 = F_16 ( V_16 , V_13 ) ;
if ( V_19 ) {
F_8 ( L_6 , V_19 ) ;
goto V_35;
}
V_23 -> V_13 = V_13 ;
F_17 ( V_22 , V_2 ) = V_23 ;
F_18 ( V_16 -> V_36 , F_17 ( V_37 , V_2 ) ) ;
F_19 (i, per_cpu(cpu_mask, cpu))
F_17 ( V_22 , V_6 ) = V_23 ;
V_24 = 12ULL * V_38 ;
V_16 -> V_39 . V_40 =
F_20 ( V_24 , F_21 () ) ;
F_22 ( V_18 ) ;
return 0 ;
V_35:
F_23 ( V_13 ) ;
V_31:
F_22 ( V_23 -> V_30 ) ;
V_29:
F_17 ( V_22 , V_2 ) = NULL ;
F_23 ( V_23 ) ;
V_28:
F_22 ( V_18 ) ;
return - V_25 ;
}
static int T_3 F_24 ( struct V_15 * V_16 )
{
struct V_22 * V_23 = F_17 ( V_22 , V_16 -> V_2 ) ;
unsigned int V_2 ;
F_22 ( V_23 -> V_30 ) ;
F_23 ( V_23 -> V_13 ) ;
F_23 ( V_23 ) ;
F_19 (cpu, per_cpu(cpu_mask, policy->cpu))
F_17 ( V_22 , V_2 ) = NULL ;
return 0 ;
}
static int F_25 ( struct V_15 * V_16 ,
unsigned int V_41 )
{
struct V_21 * V_30 ;
struct V_22 * V_23 = F_17 ( V_22 , V_16 -> V_2 ) ;
V_30 = F_9 ( V_23 -> V_30 , V_23 -> V_13 [ V_41 ] . V_14 ) ;
return F_26 ( V_16 -> V_21 , V_30 ) ;
}
static int T_4 F_27 ( void )
{
int V_19 ;
struct V_17 * V_18 ;
const struct V_42 * V_43 ;
const struct V_44 * V_23 ;
unsigned int V_2 ;
V_18 = F_28 ( NULL , V_45 ) ;
if ( ! V_18 )
return - V_25 ;
F_29 (cpu) {
if ( ! F_30 ( & F_17 ( V_37 , V_2 ) , V_26 ) )
goto V_46;
F_18 ( F_17 ( V_37 , V_2 ) , F_1 ( V_2 ) ) ;
}
V_43 = F_31 ( V_45 , V_18 ) ;
V_23 = V_43 -> V_23 ;
if ( V_23 ) {
if ( V_23 -> V_47 )
V_32 = V_23 -> V_48 ;
V_33 = F_21 () ;
} else {
V_33 = F_21 () / 2 ;
}
F_22 ( V_18 ) ;
V_19 = F_32 ( & V_49 ) ;
if ( ! V_19 )
F_33 ( L_7 ) ;
return V_19 ;
V_46:
F_29 (cpu)
F_34 ( F_17 ( V_37 , V_2 ) ) ;
return - V_50 ;
}
static void T_3 F_35 ( void )
{
unsigned int V_2 ;
F_29 (cpu)
F_34 ( F_17 ( V_37 , V_2 ) ) ;
F_36 ( & V_49 ) ;
}
