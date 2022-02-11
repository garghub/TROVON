static inline const struct V_1 * F_1 ( int V_2 )
{
return F_2 ( 0 ) ;
}
static unsigned int F_3 ( unsigned int V_2 )
{
struct V_3 * V_4 = F_4 ( V_3 , V_2 ) ;
return F_5 ( V_4 -> V_5 ) / 1000 ;
}
static void F_6 ( struct V_6 * V_7 ,
int V_8 )
{
int V_9 , V_10 ;
for ( V_9 = 1 ; V_9 < V_8 ; V_9 ++ ) {
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if ( V_7 [ V_10 ] . V_11 == V_12 ||
V_7 [ V_10 ] . V_11 !=
V_7 [ V_9 ] . V_11 )
continue;
V_7 [ V_9 ] . V_11 = V_12 ;
break;
}
}
}
static void F_7 ( struct V_6 * V_7 ,
int V_8 )
{
int V_9 , V_10 , V_13 ;
unsigned int V_14 , V_15 ;
struct V_6 V_16 ;
for ( V_9 = 0 ; V_9 < V_8 - 1 ; V_9 ++ ) {
V_15 = V_7 [ V_9 ] . V_11 ;
V_13 = V_9 ;
for ( V_10 = V_9 + 1 ; V_10 < V_8 ; V_10 ++ ) {
V_14 = V_7 [ V_10 ] . V_11 ;
if ( V_14 == V_12 ||
V_14 <= V_15 )
continue;
V_13 = V_10 ;
V_15 = V_14 ;
}
if ( V_13 != V_9 ) {
V_16 . V_17 = V_7 [ V_9 ] . V_17 ;
V_16 . V_11 = V_7 [ V_9 ] . V_11 ;
V_7 [ V_9 ] . V_17 = V_7 [ V_13 ] . V_17 ;
V_7 [ V_9 ] . V_11 = V_7 [ V_13 ] . V_11 ;
V_7 [ V_13 ] . V_17 = V_16 . V_17 ;
V_7 [ V_13 ] . V_11 = V_16 . V_11 ;
}
}
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
int V_9 , V_8 , V_22 ;
T_1 V_14 , V_23 ;
struct V_5 * V_5 ;
struct V_6 * V_16 ;
struct V_3 * V_4 ;
unsigned int V_2 = V_19 -> V_2 ;
V_21 = F_9 ( V_2 , NULL ) ;
if ( ! V_21 )
return - V_24 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 ) {
F_11 ( L_1 , V_26 ) ;
goto V_27;
}
V_4 -> V_5 = F_12 ( V_21 , 0 ) ;
if ( F_13 ( V_4 -> V_5 ) ) {
F_11 ( L_2 , V_26 ) ;
goto V_28;
}
V_4 -> V_29 = F_14 ( V_21 , L_3 , 0 ) ;
if ( ! V_4 -> V_29 ) {
F_11 ( L_4 , V_26 ) ;
goto V_28;
}
V_8 = F_15 ( V_4 -> V_29 , L_5 ) ;
V_16 = F_16 ( V_8 + 1 , sizeof( * V_16 ) , V_25 ) ;
if ( ! V_16 ) {
F_11 ( L_1 , V_26 ) ;
goto V_30;
}
if ( V_31 )
V_23 = V_31 [ F_17 ( V_2 ) ] ;
else
V_23 = 0x0 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_5 = F_12 ( V_4 -> V_29 , V_9 ) ;
V_14 = F_5 ( V_5 ) ;
if ( V_14 < V_32 || ( V_23 & ( 1 << V_9 ) ) )
V_16 [ V_9 ] . V_11 = V_12 ;
else
V_16 [ V_9 ] . V_11 = V_14 / 1000 ;
V_16 [ V_9 ] . V_17 = V_9 ;
}
F_6 ( V_16 , V_8 ) ;
F_7 ( V_16 , V_8 ) ;
V_16 [ V_9 ] . V_11 = V_33 ;
V_22 = F_18 ( V_19 , V_16 ) ;
if ( V_22 ) {
F_11 ( L_6 , V_22 ) ;
goto V_34;
}
V_4 -> V_16 = V_16 ;
F_4 ( V_3 , V_2 ) = V_4 ;
F_19 ( V_19 -> V_35 , F_4 ( V_36 , V_2 ) ) ;
F_20 (i, per_cpu(cpu_mask, cpu))
F_4 ( V_3 , V_9 ) = V_4 ;
V_19 -> V_37 . V_38 = V_39 ;
F_21 ( V_21 ) ;
return 0 ;
V_34:
F_22 ( V_16 ) ;
V_30:
F_21 ( V_4 -> V_29 ) ;
V_28:
F_4 ( V_3 , V_2 ) = NULL ;
F_22 ( V_4 ) ;
V_27:
F_21 ( V_21 ) ;
return - V_24 ;
}
static int T_2 F_23 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_4 ( V_3 , V_19 -> V_2 ) ;
unsigned int V_2 ;
F_24 ( V_19 -> V_2 ) ;
F_21 ( V_4 -> V_29 ) ;
F_22 ( V_4 -> V_16 ) ;
F_22 ( V_4 ) ;
F_20 (cpu, per_cpu(cpu_mask, policy->cpu))
F_4 ( V_3 , V_2 ) = NULL ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 ,
unsigned int V_40 )
{
struct V_5 * V_29 ;
struct V_3 * V_4 = F_4 ( V_3 , V_19 -> V_2 ) ;
V_29 = F_12 ( V_4 -> V_29 , V_4 -> V_16 [ V_40 ] . V_17 ) ;
return F_26 ( V_4 -> V_5 , V_29 ) ;
}
static int T_3 F_27 ( void )
{
int V_22 ;
struct V_20 * V_21 ;
const struct V_41 * V_42 ;
const struct V_43 * V_4 ;
unsigned int V_2 ;
V_21 = F_28 ( NULL , V_44 ) ;
if ( ! V_21 )
return - V_24 ;
F_29 (cpu) {
if ( ! F_30 ( & F_4 ( V_36 , V_2 ) , V_25 ) )
goto V_45;
F_19 ( F_4 ( V_36 , V_2 ) , F_1 ( V_2 ) ) ;
}
V_42 = F_31 ( V_44 , V_21 ) ;
V_4 = V_42 -> V_4 ;
if ( V_4 ) {
if ( V_4 -> V_46 )
V_31 = V_4 -> V_47 ;
V_32 = F_32 () ;
} else {
V_32 = F_32 () / 2 ;
}
F_21 ( V_21 ) ;
V_22 = F_33 ( & V_48 ) ;
if ( ! V_22 )
F_34 ( L_7 ) ;
return V_22 ;
V_45:
F_29 (cpu)
F_35 ( F_4 ( V_36 , V_2 ) ) ;
return - V_49 ;
}
static void T_2 F_36 ( void )
{
unsigned int V_2 ;
F_29 (cpu)
F_35 ( F_4 ( V_36 , V_2 ) ) ;
F_37 ( & V_48 ) ;
}
