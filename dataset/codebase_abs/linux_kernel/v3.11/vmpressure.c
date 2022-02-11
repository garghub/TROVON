static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_4 ( F_5 ( V_5 , V_6 ) ) ;
}
static struct V_1 * F_6 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = F_7 ( V_7 ) -> V_4 ;
struct V_8 * V_9 = F_8 ( V_5 ) ;
V_9 = F_9 ( V_9 ) ;
if ( ! V_9 )
return NULL ;
return F_10 ( V_9 ) ;
}
static enum V_10 F_11 ( unsigned long V_11 )
{
if ( V_11 >= V_12 )
return V_13 ;
else if ( V_11 >= V_14 )
return V_15 ;
return V_16 ;
}
static enum V_10 F_12 ( unsigned long V_17 ,
unsigned long V_18 )
{
unsigned long V_19 = V_17 + V_18 ;
unsigned long V_11 ;
V_11 = V_19 - ( V_18 * V_19 / V_17 ) ;
V_11 = V_11 * 100 / V_19 ;
F_13 ( L_1 , V_20 , V_11 ,
V_17 , V_18 ) ;
return F_11 ( V_11 ) ;
}
static bool F_14 ( struct V_1 * V_7 ,
unsigned long V_17 , unsigned long V_18 )
{
struct F_14 * V_21 ;
enum V_10 V_22 ;
bool V_23 = false ;
V_22 = F_12 ( V_17 , V_18 ) ;
F_15 ( & V_7 -> V_24 ) ;
F_16 (ev, &vmpr->events, node) {
if ( V_22 >= V_21 -> V_22 ) {
F_17 ( V_21 -> V_25 , 1 ) ;
V_23 = true ;
}
}
F_18 ( & V_7 -> V_24 ) ;
return V_23 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_17 ;
unsigned long V_18 ;
if ( ! V_7 -> V_17 )
return;
F_20 ( & V_7 -> V_26 ) ;
V_17 = V_7 -> V_17 ;
V_18 = V_7 -> V_18 ;
V_7 -> V_17 = 0 ;
V_7 -> V_18 = 0 ;
F_21 ( & V_7 -> V_26 ) ;
do {
if ( F_14 ( V_7 , V_17 , V_18 ) )
break;
} while ( ( V_7 = F_6 ( V_7 ) ) );
}
void V_1 ( T_1 V_27 , struct V_8 * V_9 ,
unsigned long V_17 , unsigned long V_18 )
{
struct V_1 * V_7 = F_10 ( V_9 ) ;
if ( ! ( V_27 & ( V_28 | V_29 | V_30 | V_31 ) ) )
return;
if ( ! V_17 )
return;
F_20 ( & V_7 -> V_26 ) ;
V_7 -> V_17 += V_17 ;
V_7 -> V_18 += V_18 ;
V_17 = V_7 -> V_17 ;
F_21 ( & V_7 -> V_26 ) ;
if ( V_17 < V_32 )
return;
F_22 ( & V_7 -> V_3 ) ;
}
void F_23 ( T_1 V_27 , struct V_8 * V_9 , int V_33 )
{
if ( V_33 > V_34 )
return;
V_1 ( V_27 , V_9 , V_32 , 0 ) ;
}
int F_24 ( struct V_4 * V_5 , struct V_35 * V_36 ,
struct V_37 * V_38 , const char * args )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct F_14 * V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_39 ; V_22 ++ ) {
if ( ! strcmp ( V_40 [ V_22 ] , args ) )
break;
}
if ( V_22 >= V_39 )
return - V_41 ;
V_21 = F_25 ( sizeof( * V_21 ) , V_42 ) ;
if ( ! V_21 )
return - V_43 ;
V_21 -> V_25 = V_38 ;
V_21 -> V_22 = V_22 ;
F_15 ( & V_7 -> V_24 ) ;
F_26 ( & V_21 -> V_44 , & V_7 -> V_45 ) ;
F_18 ( & V_7 -> V_24 ) ;
return 0 ;
}
void F_27 ( struct V_4 * V_5 , struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct F_14 * V_21 ;
F_15 ( & V_7 -> V_24 ) ;
F_16 (ev, &vmpr->events, node) {
if ( V_21 -> V_25 != V_38 )
continue;
F_28 ( & V_21 -> V_44 ) ;
F_29 ( V_21 ) ;
break;
}
F_18 ( & V_7 -> V_24 ) ;
}
void F_30 ( struct V_1 * V_7 )
{
F_31 ( & V_7 -> V_26 ) ;
F_32 ( & V_7 -> V_24 ) ;
F_33 ( & V_7 -> V_45 ) ;
F_34 ( & V_7 -> V_3 , F_19 ) ;
}
void F_35 ( struct V_1 * V_7 )
{
F_36 ( & V_7 -> V_3 ) ;
}
