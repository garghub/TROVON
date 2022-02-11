static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_1 * F_3 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
V_8 = F_6 ( V_8 ) ;
if ( ! V_8 )
return NULL ;
return F_7 ( V_8 ) ;
}
static enum V_9 F_8 ( unsigned long V_10 )
{
if ( V_10 >= V_11 )
return V_12 ;
else if ( V_10 >= V_13 )
return V_14 ;
return V_15 ;
}
static enum V_9 F_9 ( unsigned long V_16 ,
unsigned long V_17 )
{
unsigned long V_18 = V_16 + V_17 ;
unsigned long V_10 = 0 ;
if ( V_17 >= V_16 )
goto V_19;
V_10 = V_18 - ( V_17 * V_18 / V_16 ) ;
V_10 = V_10 * 100 / V_18 ;
V_19:
F_10 ( L_1 , V_20 , V_10 ,
V_16 , V_17 ) ;
return F_8 ( V_10 ) ;
}
static bool F_11 ( struct V_1 * V_4 ,
enum V_9 V_21 )
{
struct F_11 * V_22 ;
bool V_23 = false ;
F_12 ( & V_4 -> V_24 ) ;
F_13 (ev, &vmpr->events, node) {
if ( V_21 >= V_22 -> V_21 ) {
F_14 ( V_22 -> V_25 , 1 ) ;
V_23 = true ;
}
}
F_15 ( & V_4 -> V_24 ) ;
return V_23 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_16 ;
unsigned long V_17 ;
enum V_9 V_21 ;
F_17 ( & V_4 -> V_26 ) ;
V_16 = V_4 -> V_27 ;
if ( ! V_16 ) {
F_18 ( & V_4 -> V_26 ) ;
return;
}
V_17 = V_4 -> V_28 ;
V_4 -> V_27 = 0 ;
V_4 -> V_28 = 0 ;
F_18 ( & V_4 -> V_26 ) ;
V_21 = F_9 ( V_16 , V_17 ) ;
do {
if ( F_11 ( V_4 , V_21 ) )
break;
} while ( ( V_4 = F_3 ( V_4 ) ) );
}
void V_1 ( T_1 V_29 , struct V_7 * V_8 , bool V_30 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
if ( ! ( V_29 & ( V_31 | V_32 | V_33 | V_34 ) ) )
return;
if ( ! V_16 )
return;
if ( V_30 ) {
F_17 ( & V_4 -> V_26 ) ;
V_16 = V_4 -> V_27 += V_16 ;
V_4 -> V_28 += V_17 ;
F_18 ( & V_4 -> V_26 ) ;
if ( V_16 < V_35 )
return;
F_19 ( & V_4 -> V_3 ) ;
} else {
enum V_9 V_21 ;
if ( ! V_8 || V_8 == V_36 )
return;
F_17 ( & V_4 -> V_26 ) ;
V_16 = V_4 -> V_16 += V_16 ;
V_17 = V_4 -> V_17 += V_17 ;
if ( V_16 < V_35 ) {
F_18 ( & V_4 -> V_26 ) ;
return;
}
V_4 -> V_16 = V_4 -> V_17 = 0 ;
F_18 ( & V_4 -> V_26 ) ;
V_21 = F_9 ( V_16 , V_17 ) ;
if ( V_21 > V_15 ) {
V_8 -> V_37 = V_38 + V_39 ;
}
}
}
void F_20 ( T_1 V_29 , struct V_7 * V_8 , int V_40 )
{
if ( V_40 > V_41 )
return;
V_1 ( V_29 , V_8 , true , V_35 , 0 ) ;
}
int F_21 ( struct V_7 * V_8 ,
struct V_42 * V_43 , const char * args )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
struct F_11 * V_22 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_44 ; V_21 ++ ) {
if ( ! strcmp ( V_45 [ V_21 ] , args ) )
break;
}
if ( V_21 >= V_44 )
return - V_46 ;
V_22 = F_22 ( sizeof( * V_22 ) , V_47 ) ;
if ( ! V_22 )
return - V_48 ;
V_22 -> V_25 = V_43 ;
V_22 -> V_21 = V_21 ;
F_12 ( & V_4 -> V_24 ) ;
F_23 ( & V_22 -> V_49 , & V_4 -> V_50 ) ;
F_15 ( & V_4 -> V_24 ) ;
return 0 ;
}
void F_24 ( struct V_7 * V_8 ,
struct V_42 * V_43 )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
struct F_11 * V_22 ;
F_12 ( & V_4 -> V_24 ) ;
F_13 (ev, &vmpr->events, node) {
if ( V_22 -> V_25 != V_43 )
continue;
F_25 ( & V_22 -> V_49 ) ;
F_26 ( V_22 ) ;
break;
}
F_15 ( & V_4 -> V_24 ) ;
}
void F_27 ( struct V_1 * V_4 )
{
F_28 ( & V_4 -> V_26 ) ;
F_29 ( & V_4 -> V_24 ) ;
F_30 ( & V_4 -> V_50 ) ;
F_31 ( & V_4 -> V_3 , F_16 ) ;
}
void F_32 ( struct V_1 * V_4 )
{
F_33 ( & V_4 -> V_3 ) ;
}
