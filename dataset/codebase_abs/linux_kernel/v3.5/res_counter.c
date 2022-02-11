void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_3 = V_3 ;
}
int F_3 ( struct V_1 * V_2 , unsigned long V_8 ,
bool V_9 )
{
int V_10 = 0 ;
if ( V_2 -> V_11 + V_8 > V_2 -> V_5 ) {
V_2 -> V_12 ++ ;
V_10 = - V_13 ;
if ( ! V_9 )
return V_10 ;
}
V_2 -> V_11 += V_8 ;
if ( V_2 -> V_11 > V_2 -> V_14 )
V_2 -> V_14 = V_2 -> V_11 ;
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long V_8 ,
struct V_1 * * V_15 , bool V_9 )
{
int V_10 , V_16 ;
unsigned long V_17 ;
struct V_1 * V_18 , * V_19 ;
V_16 = V_10 = 0 ;
* V_15 = NULL ;
F_5 ( V_17 ) ;
for ( V_18 = V_2 ; V_18 != NULL ; V_18 = V_18 -> V_3 ) {
F_6 ( & V_18 -> V_4 ) ;
V_16 = F_3 ( V_18 , V_8 , V_9 ) ;
F_7 ( & V_18 -> V_4 ) ;
if ( V_16 < 0 && ! V_10 ) {
V_10 = V_16 ;
* V_15 = V_18 ;
if ( ! V_9 )
break;
}
}
if ( V_10 < 0 && ! V_9 ) {
for ( V_19 = V_2 ; V_19 != V_18 ; V_19 = V_19 -> V_3 ) {
F_6 ( & V_19 -> V_4 ) ;
F_8 ( V_19 , V_8 ) ;
F_7 ( & V_19 -> V_4 ) ;
}
}
F_9 ( V_17 ) ;
return V_10 ;
}
int F_10 ( struct V_1 * V_2 , unsigned long V_8 ,
struct V_1 * * V_15 )
{
return F_4 ( V_2 , V_8 , V_15 , false ) ;
}
int F_11 ( struct V_1 * V_2 , unsigned long V_8 ,
struct V_1 * * V_15 )
{
return F_4 ( V_2 , V_8 , V_15 , true ) ;
}
void F_8 ( struct V_1 * V_2 , unsigned long V_8 )
{
if ( F_12 ( V_2 -> V_11 < V_8 ) )
V_8 = V_2 -> V_11 ;
V_2 -> V_11 -= V_8 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_1 * V_20 ,
unsigned long V_8 )
{
unsigned long V_17 ;
struct V_1 * V_18 ;
F_5 ( V_17 ) ;
for ( V_18 = V_2 ; V_18 != V_20 ; V_18 = V_18 -> V_3 ) {
F_6 ( & V_18 -> V_4 ) ;
F_8 ( V_18 , V_8 ) ;
F_7 ( & V_18 -> V_4 ) ;
}
F_9 ( V_17 ) ;
}
void F_14 ( struct V_1 * V_2 , unsigned long V_8 )
{
F_13 ( V_2 , NULL , V_8 ) ;
}
static inline unsigned long long *
F_15 ( struct V_1 * V_2 , int V_21 )
{
switch ( V_21 ) {
case V_22 :
return & V_2 -> V_11 ;
case V_23 :
return & V_2 -> V_14 ;
case V_24 :
return & V_2 -> V_5 ;
case V_25 :
return & V_2 -> V_12 ;
case V_26 :
return & V_2 -> V_7 ;
} ;
F_16 () ;
return NULL ;
}
T_1 F_17 ( struct V_1 * V_2 , int V_21 ,
const char T_2 * V_27 , T_3 V_28 , T_4 * V_29 ,
int (* F_18)( unsigned long long V_8 , char * V_30 ) )
{
unsigned long long * V_8 ;
char V_31 [ 64 ] , * V_32 ;
V_32 = V_31 ;
V_8 = F_15 ( V_2 , V_21 ) ;
if ( F_18 )
V_32 += F_18 ( * V_8 , V_32 ) ;
else
V_32 += sprintf ( V_32 , L_1 , * V_8 ) ;
return F_19 ( ( void T_2 * ) V_27 , V_28 ,
V_29 , V_31 , V_32 - V_31 ) ;
}
T_5 F_20 ( struct V_1 * V_2 , int V_21 )
{
unsigned long V_17 ;
T_5 V_10 ;
F_21 ( & V_2 -> V_4 , V_17 ) ;
V_10 = * F_15 ( V_2 , V_21 ) ;
F_22 ( & V_2 -> V_4 , V_17 ) ;
return V_10 ;
}
T_5 F_20 ( struct V_1 * V_2 , int V_21 )
{
return * F_15 ( V_2 , V_21 ) ;
}
int F_23 ( const char * V_31 ,
unsigned long long * V_33 )
{
char * V_34 ;
if ( * V_31 == '-' ) {
* V_33 = F_24 ( V_31 + 1 , & V_34 , 10 ) ;
if ( * V_33 != 1 || * V_34 != '\0' )
return - V_35 ;
* V_33 = V_6 ;
return 0 ;
}
* V_33 = F_25 ( V_31 , & V_34 ) ;
if ( * V_34 != '\0' )
return - V_35 ;
* V_33 = F_26 ( * V_33 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , int V_21 ,
const char * V_31 , T_6 V_36 )
{
char * V_34 ;
unsigned long V_17 ;
unsigned long long V_37 , * V_8 ;
if ( V_36 ) {
if ( V_36 ( V_31 , & V_37 ) )
return - V_35 ;
} else {
V_37 = F_24 ( V_31 , & V_34 , 10 ) ;
if ( * V_34 != '\0' )
return - V_35 ;
}
F_21 ( & V_2 -> V_4 , V_17 ) ;
V_8 = F_15 ( V_2 , V_21 ) ;
* V_8 = V_37 ;
F_22 ( & V_2 -> V_4 , V_17 ) ;
return 0 ;
}
