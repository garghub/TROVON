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
unsigned long V_10 ;
V_10 = V_18 - ( V_17 * V_18 / V_16 ) ;
V_10 = V_10 * 100 / V_18 ;
F_10 ( L_1 , V_19 , V_10 ,
V_16 , V_17 ) ;
return F_8 ( V_10 ) ;
}
static bool F_11 ( struct V_1 * V_4 ,
unsigned long V_16 , unsigned long V_17 )
{
struct F_11 * V_20 ;
enum V_9 V_21 ;
bool V_22 = false ;
V_21 = F_9 ( V_16 , V_17 ) ;
F_12 ( & V_4 -> V_23 ) ;
F_13 (ev, &vmpr->events, node) {
if ( V_21 >= V_20 -> V_21 ) {
F_14 ( V_20 -> V_24 , 1 ) ;
V_22 = true ;
}
}
F_15 ( & V_4 -> V_23 ) ;
return V_22 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_16 ;
unsigned long V_17 ;
F_17 ( & V_4 -> V_25 ) ;
V_16 = V_4 -> V_16 ;
if ( ! V_16 ) {
F_18 ( & V_4 -> V_25 ) ;
return;
}
V_17 = V_4 -> V_17 ;
V_4 -> V_16 = 0 ;
V_4 -> V_17 = 0 ;
F_18 ( & V_4 -> V_25 ) ;
do {
if ( F_11 ( V_4 , V_16 , V_17 ) )
break;
} while ( ( V_4 = F_3 ( V_4 ) ) );
}
void V_1 ( T_1 V_26 , struct V_7 * V_8 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
if ( ! ( V_26 & ( V_27 | V_28 | V_29 | V_30 ) ) )
return;
if ( ! V_16 )
return;
F_17 ( & V_4 -> V_25 ) ;
V_4 -> V_16 += V_16 ;
V_4 -> V_17 += V_17 ;
V_16 = V_4 -> V_16 ;
F_18 ( & V_4 -> V_25 ) ;
if ( V_16 < V_31 )
return;
F_19 ( & V_4 -> V_3 ) ;
}
void F_20 ( T_1 V_26 , struct V_7 * V_8 , int V_32 )
{
if ( V_32 > V_33 )
return;
V_1 ( V_26 , V_8 , V_31 , 0 ) ;
}
int F_21 ( struct V_7 * V_8 ,
struct V_34 * V_35 , const char * args )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
struct F_11 * V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ ) {
if ( ! strcmp ( V_37 [ V_21 ] , args ) )
break;
}
if ( V_21 >= V_36 )
return - V_38 ;
V_20 = F_22 ( sizeof( * V_20 ) , V_39 ) ;
if ( ! V_20 )
return - V_40 ;
V_20 -> V_24 = V_35 ;
V_20 -> V_21 = V_21 ;
F_12 ( & V_4 -> V_23 ) ;
F_23 ( & V_20 -> V_41 , & V_4 -> V_42 ) ;
F_15 ( & V_4 -> V_23 ) ;
return 0 ;
}
void F_24 ( struct V_7 * V_8 ,
struct V_34 * V_35 )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
struct F_11 * V_20 ;
F_12 ( & V_4 -> V_23 ) ;
F_13 (ev, &vmpr->events, node) {
if ( V_20 -> V_24 != V_35 )
continue;
F_25 ( & V_20 -> V_41 ) ;
F_26 ( V_20 ) ;
break;
}
F_15 ( & V_4 -> V_23 ) ;
}
void F_27 ( struct V_1 * V_4 )
{
F_28 ( & V_4 -> V_25 ) ;
F_29 ( & V_4 -> V_23 ) ;
F_30 ( & V_4 -> V_42 ) ;
F_31 ( & V_4 -> V_3 , F_16 ) ;
}
void F_32 ( struct V_1 * V_4 )
{
F_33 ( & V_4 -> V_3 ) ;
}
