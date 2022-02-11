int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned int V_5 , V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
if ( ! V_2 || ! F_2 ( V_2 ) ) {
F_3 ( L_1 ) ;
return - V_11 ;
}
if ( ! F_4 ( V_4 , V_12 ) ) {
F_3 ( L_2 ) ;
return - V_11 ;
}
V_5 = F_5 ( V_4 ) ;
if ( ! V_5 ) {
F_3 ( L_3 ) ;
return - V_11 ;
}
if ( F_6 ( V_2 ) ) {
V_5 = 1 ;
V_6 = 0 ;
} else {
unsigned int V_13 ;
V_6 = F_7 ( V_4 ) ;
V_13 = F_8 ( V_6 , V_4 ) ;
if ( V_13 < V_14 )
V_13 = F_9 ( V_13 , V_4 ) ;
if ( V_13 < V_14 ) {
F_3 ( L_4 ) ;
return - V_11 ;
}
}
V_9 = F_10 ( - 1 , V_5 , 0 , V_15 , NULL ) ;
if ( V_9 <= 0 ) {
F_3 ( L_5 ) ;
return - V_16 ;
}
V_9 = F_11 ( V_2 , V_9 , V_5 , V_15 ,
( void * ) V_4 , true , NULL ) ;
if ( V_9 <= 0 ) {
F_3 ( L_6 ) ;
goto V_17;
}
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
V_8 = F_12 ( V_9 + V_10 ) ;
F_13 ( V_8 -> V_18 -> V_19 , V_4 ) ;
V_8 -> V_18 -> V_20 = V_6 ;
F_14 ( V_9 + V_10 , V_21 ) ;
}
return V_9 ;
V_17:
F_15 ( V_9 , V_5 ) ;
return - V_22 ;
}
int F_16 ( unsigned int V_23 , const struct V_3 * V_4 )
{
struct V_7 * V_8 = F_12 ( V_23 ) ;
struct V_3 * V_24 = V_8 ? F_17 ( V_8 ) : NULL ;
struct V_1 * V_2 ;
unsigned int V_5 ;
if ( ! V_23 || ! V_8 || ! V_24 )
return - V_11 ;
V_2 = V_8 -> V_2 ;
if ( F_18 ( V_2 == NULL ) )
return - V_11 ;
if ( ! F_2 ( V_2 ) ) {
F_3 ( L_7 ) ;
return - V_11 ;
}
if ( F_18 ( ! F_4 ( V_4 , V_24 ) ) )
return - V_11 ;
if ( F_19 ( V_2 ) ) {
V_23 = V_23 + F_7 ( V_4 ) - V_8 -> V_18 -> V_20 ;
V_5 = F_5 ( V_4 ) ;
} else {
V_5 = 1 ;
}
F_20 ( V_23 , V_5 ) ;
return 0 ;
}
T_1 F_21 ( unsigned int V_23 , unsigned int V_25 )
{
struct V_7 * V_8 = F_12 ( V_23 ) ;
struct V_3 * V_24 = V_8 ? F_17 ( V_8 ) : NULL ;
if ( ! V_8 || ! V_24 || V_25 >= V_14 )
return V_26 ;
if ( ! F_22 ( V_25 , V_24 ) )
return V_26 ;
if ( F_19 ( V_8 -> V_2 ) )
V_8 = F_12 ( V_23 + V_25 - V_8 -> V_18 -> V_20 ) ;
return V_8 ? F_23 ( V_8 ) : V_26 ;
}
static int F_24 ( struct V_27 * V_28 , struct V_7 * V_8 ,
const struct V_3 * V_4 , unsigned int V_25 )
{
struct V_3 * V_24 = F_17 ( V_8 ) ;
if ( ! V_28 || ! V_24 )
return - V_11 ;
if ( ! V_28 -> V_29 && ! V_28 -> V_30 )
return - V_11 ;
if ( V_25 >= V_14 )
return - V_11 ;
if ( V_4 ) {
if ( ! F_4 ( V_4 , V_24 ) )
return - V_11 ;
} else {
if ( ! F_22 ( V_25 , V_24 ) )
return - V_11 ;
}
return 0 ;
}
int F_25 ( struct V_31 * V_32 , unsigned int V_25 )
{
struct V_7 * V_8 = F_26 ( V_32 ) ;
struct V_27 * V_28 = F_27 ( V_8 ) ;
#ifdef F_28
if ( F_29 ( F_24 ( V_28 , V_8 , NULL , V_25 ) ) )
return - V_11 ;
#endif
if ( ! V_28 -> V_29 ) {
V_28 -> V_30 ( V_8 , F_30 ( V_25 ) ) ;
return 0 ;
}
if ( F_19 ( V_8 -> V_2 ) &&
V_25 != V_8 -> V_18 -> V_20 ) {
unsigned V_23 = V_8 -> V_23 + V_25 - V_8 -> V_18 -> V_20 ;
V_8 = F_12 ( V_23 ) ;
}
V_28 -> V_29 ( V_8 , V_25 ) ;
return 0 ;
}
int F_31 ( struct V_31 * V_32 , const struct V_3 * V_4 )
{
struct V_7 * V_8 = F_26 ( V_32 ) ;
struct V_27 * V_28 = F_27 ( V_8 ) ;
unsigned int V_25 ;
#ifdef F_28
if ( F_29 ( F_24 ( V_28 , V_8 , V_4 , 0 ) ) )
return - V_11 ;
#endif
if ( V_28 -> V_30 ) {
V_28 -> V_30 ( V_8 , V_4 ) ;
return 0 ;
}
if ( F_19 ( V_8 -> V_2 ) ) {
unsigned int V_33 = V_8 -> V_23 ;
F_32 (cpu, dest) {
unsigned V_23 = V_33 + V_25 - V_8 -> V_18 -> V_20 ;
V_8 = F_12 ( V_23 ) ;
V_28 -> V_29 ( V_8 , V_25 ) ;
}
} else {
F_32 (cpu, dest)
V_28 -> V_29 ( V_8 , V_25 ) ;
}
return 0 ;
}
int V_29 ( unsigned int V_9 , unsigned int V_25 )
{
struct V_31 * V_32 = F_33 ( V_9 ) ;
struct V_7 * V_8 = V_32 ? F_26 ( V_32 ) : NULL ;
struct V_27 * V_28 = V_8 ? F_27 ( V_8 ) : NULL ;
if ( F_29 ( F_24 ( V_28 , V_8 , NULL , V_25 ) ) )
return - V_11 ;
return F_25 ( V_32 , V_25 ) ;
}
int V_30 ( unsigned int V_9 , const struct V_3 * V_4 )
{
struct V_31 * V_32 = F_33 ( V_9 ) ;
struct V_7 * V_8 = V_32 ? F_26 ( V_32 ) : NULL ;
struct V_27 * V_28 = V_8 ? F_27 ( V_8 ) : NULL ;
if ( F_29 ( F_24 ( V_28 , V_8 , V_4 , 0 ) ) )
return - V_11 ;
return F_31 ( V_32 , V_4 ) ;
}
