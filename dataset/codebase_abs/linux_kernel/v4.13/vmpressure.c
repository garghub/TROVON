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
const enum V_9 V_21 ,
bool V_22 , bool V_23 )
{
struct F_11 * V_24 ;
bool V_25 = false ;
F_12 ( & V_4 -> V_26 ) ;
F_13 (ev, &vmpr->events, node) {
if ( V_22 && V_24 -> V_27 == V_28 )
continue;
if ( V_23 && V_24 -> V_27 == V_29 )
continue;
if ( V_21 < V_24 -> V_21 )
continue;
F_14 ( V_24 -> V_30 , 1 ) ;
V_25 = true ;
}
F_15 ( & V_4 -> V_26 ) ;
return V_25 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_16 ;
unsigned long V_17 ;
enum V_9 V_21 ;
bool V_22 = false ;
bool V_23 = false ;
F_17 ( & V_4 -> V_31 ) ;
V_16 = V_4 -> V_32 ;
if ( ! V_16 ) {
F_18 ( & V_4 -> V_31 ) ;
return;
}
V_17 = V_4 -> V_33 ;
V_4 -> V_32 = 0 ;
V_4 -> V_33 = 0 ;
F_18 ( & V_4 -> V_31 ) ;
V_21 = F_9 ( V_16 , V_17 ) ;
do {
if ( F_11 ( V_4 , V_21 , V_22 , V_23 ) )
V_23 = true ;
V_22 = true ;
} while ( ( V_4 = F_3 ( V_4 ) ) );
}
void V_1 ( T_1 V_34 , struct V_7 * V_8 , bool V_35 ,
unsigned long V_16 , unsigned long V_17 )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
if ( ! ( V_34 & ( V_36 | V_37 | V_38 | V_39 ) ) )
return;
if ( ! V_16 )
return;
if ( V_35 ) {
F_17 ( & V_4 -> V_31 ) ;
V_16 = V_4 -> V_32 += V_16 ;
V_4 -> V_33 += V_17 ;
F_18 ( & V_4 -> V_31 ) ;
if ( V_16 < V_40 )
return;
F_19 ( & V_4 -> V_3 ) ;
} else {
enum V_9 V_21 ;
if ( ! V_8 || V_8 == V_41 )
return;
F_17 ( & V_4 -> V_31 ) ;
V_16 = V_4 -> V_16 += V_16 ;
V_17 = V_4 -> V_17 += V_17 ;
if ( V_16 < V_40 ) {
F_18 ( & V_4 -> V_31 ) ;
return;
}
V_4 -> V_16 = V_4 -> V_17 = 0 ;
F_18 ( & V_4 -> V_31 ) ;
V_21 = F_9 ( V_16 , V_17 ) ;
if ( V_21 > V_15 ) {
V_8 -> V_42 = V_43 + V_44 ;
}
}
}
void F_20 ( T_1 V_34 , struct V_7 * V_8 , int V_45 )
{
if ( V_45 > V_46 )
return;
V_1 ( V_34 , V_8 , true , V_40 , 0 ) ;
}
static enum V_9 F_21 ( const char * V_47 )
{
enum V_9 V_21 ;
for ( V_21 = 0 ; V_21 < V_48 ; V_21 ++ )
if ( ! strcmp ( V_49 [ V_21 ] , V_47 ) )
return V_21 ;
return - 1 ;
}
static enum V_50 F_22 ( const char * V_47 )
{
enum V_50 V_27 ;
for ( V_27 = 0 ; V_27 < V_51 ; V_27 ++ )
if ( ! strcmp ( V_52 [ V_27 ] , V_47 ) )
return V_27 ;
return - 1 ;
}
int F_23 ( struct V_7 * V_8 ,
struct V_53 * V_54 , const char * args )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
struct F_11 * V_24 ;
enum V_50 V_27 = V_29 ;
enum V_9 V_21 = - 1 ;
char * V_55 , * V_56 ;
char * V_57 ;
int V_25 = 0 ;
V_56 = V_55 = F_24 ( V_58 + 1 , V_59 ) ;
if ( ! V_55 ) {
V_25 = - V_60 ;
goto V_19;
}
strncpy ( V_55 , args , V_58 ) ;
V_57 = F_25 ( & V_55 , L_2 ) ;
V_21 = F_21 ( V_57 ) ;
if ( V_21 == - 1 ) {
V_25 = - V_61 ;
goto V_19;
}
V_57 = F_25 ( & V_55 , L_2 ) ;
if ( V_57 ) {
V_27 = F_22 ( V_57 ) ;
if ( V_27 == - 1 ) {
V_25 = - V_61 ;
goto V_19;
}
}
V_24 = F_24 ( sizeof( * V_24 ) , V_59 ) ;
if ( ! V_24 ) {
V_25 = - V_60 ;
goto V_19;
}
V_24 -> V_30 = V_54 ;
V_24 -> V_21 = V_21 ;
V_24 -> V_27 = V_27 ;
F_12 ( & V_4 -> V_26 ) ;
F_26 ( & V_24 -> V_62 , & V_4 -> V_63 ) ;
F_15 ( & V_4 -> V_26 ) ;
V_19:
F_27 ( V_56 ) ;
return V_25 ;
}
void F_28 ( struct V_7 * V_8 ,
struct V_53 * V_54 )
{
struct V_1 * V_4 = F_7 ( V_8 ) ;
struct F_11 * V_24 ;
F_12 ( & V_4 -> V_26 ) ;
F_13 (ev, &vmpr->events, node) {
if ( V_24 -> V_30 != V_54 )
continue;
F_29 ( & V_24 -> V_62 ) ;
F_27 ( V_24 ) ;
break;
}
F_15 ( & V_4 -> V_26 ) ;
}
void F_30 ( struct V_1 * V_4 )
{
F_31 ( & V_4 -> V_31 ) ;
F_32 ( & V_4 -> V_26 ) ;
F_33 ( & V_4 -> V_63 ) ;
F_34 ( & V_4 -> V_3 , F_16 ) ;
}
void F_35 ( struct V_1 * V_4 )
{
F_36 ( & V_4 -> V_3 ) ;
}
