void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_3 = V_3 ;
}
int F_3 ( struct V_1 * V_2 , unsigned long V_8 )
{
if ( V_2 -> V_9 + V_8 > V_2 -> V_5 ) {
V_2 -> V_10 ++ ;
return - V_11 ;
}
V_2 -> V_9 += V_8 ;
if ( V_2 -> V_9 > V_2 -> V_12 )
V_2 -> V_12 = V_2 -> V_9 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned long V_8 ,
struct V_1 * * V_13 )
{
int V_14 ;
unsigned long V_15 ;
struct V_1 * V_16 , * V_17 ;
* V_13 = NULL ;
F_5 ( V_15 ) ;
for ( V_16 = V_2 ; V_16 != NULL ; V_16 = V_16 -> V_3 ) {
F_6 ( & V_16 -> V_4 ) ;
V_14 = F_3 ( V_16 , V_8 ) ;
F_7 ( & V_16 -> V_4 ) ;
if ( V_14 < 0 ) {
* V_13 = V_16 ;
goto V_18;
}
}
V_14 = 0 ;
goto V_19;
V_18:
for ( V_17 = V_2 ; V_17 != V_16 ; V_17 = V_17 -> V_3 ) {
F_6 ( & V_17 -> V_4 ) ;
F_8 ( V_17 , V_8 ) ;
F_7 ( & V_17 -> V_4 ) ;
}
V_19:
F_9 ( V_15 ) ;
return V_14 ;
}
int F_10 ( struct V_1 * V_2 , unsigned long V_8 ,
struct V_1 * * V_13 )
{
int V_14 , V_20 ;
unsigned long V_15 ;
struct V_1 * V_16 ;
V_20 = V_14 = 0 ;
* V_13 = NULL ;
F_5 ( V_15 ) ;
for ( V_16 = V_2 ; V_16 != NULL ; V_16 = V_16 -> V_3 ) {
F_6 ( & V_16 -> V_4 ) ;
V_20 = F_3 ( V_16 , V_8 ) ;
if ( V_20 )
V_16 -> V_9 += V_8 ;
F_7 ( & V_16 -> V_4 ) ;
if ( V_20 < 0 && V_14 == 0 ) {
* V_13 = V_16 ;
V_14 = V_20 ;
}
}
F_9 ( V_15 ) ;
return V_14 ;
}
void F_8 ( struct V_1 * V_2 , unsigned long V_8 )
{
if ( F_11 ( V_2 -> V_9 < V_8 ) )
V_8 = V_2 -> V_9 ;
V_2 -> V_9 -= V_8 ;
}
void F_12 ( struct V_1 * V_2 , unsigned long V_8 )
{
unsigned long V_15 ;
struct V_1 * V_16 ;
F_5 ( V_15 ) ;
for ( V_16 = V_2 ; V_16 != NULL ; V_16 = V_16 -> V_3 ) {
F_6 ( & V_16 -> V_4 ) ;
F_8 ( V_16 , V_8 ) ;
F_7 ( & V_16 -> V_4 ) ;
}
F_9 ( V_15 ) ;
}
static inline unsigned long long *
F_13 ( struct V_1 * V_2 , int V_21 )
{
switch ( V_21 ) {
case V_22 :
return & V_2 -> V_9 ;
case V_23 :
return & V_2 -> V_12 ;
case V_24 :
return & V_2 -> V_5 ;
case V_25 :
return & V_2 -> V_10 ;
case V_26 :
return & V_2 -> V_7 ;
} ;
F_14 () ;
return NULL ;
}
T_1 F_15 ( struct V_1 * V_2 , int V_21 ,
const char T_2 * V_27 , T_3 V_28 , T_4 * V_29 ,
int (* F_16)( unsigned long long V_8 , char * V_30 ) )
{
unsigned long long * V_8 ;
char V_31 [ 64 ] , * V_32 ;
V_32 = V_31 ;
V_8 = F_13 ( V_2 , V_21 ) ;
if ( F_16 )
V_32 += F_16 ( * V_8 , V_32 ) ;
else
V_32 += sprintf ( V_32 , L_1 , * V_8 ) ;
return F_17 ( ( void T_2 * ) V_27 , V_28 ,
V_29 , V_31 , V_32 - V_31 ) ;
}
T_5 F_18 ( struct V_1 * V_2 , int V_21 )
{
unsigned long V_15 ;
T_5 V_14 ;
F_19 ( & V_2 -> V_4 , V_15 ) ;
V_14 = * F_13 ( V_2 , V_21 ) ;
F_20 ( & V_2 -> V_4 , V_15 ) ;
return V_14 ;
}
T_5 F_18 ( struct V_1 * V_2 , int V_21 )
{
return * F_13 ( V_2 , V_21 ) ;
}
int F_21 ( const char * V_31 ,
unsigned long long * V_33 )
{
char * V_34 ;
if ( * V_31 == '-' ) {
* V_33 = F_22 ( V_31 + 1 , & V_34 , 10 ) ;
if ( * V_33 != 1 || * V_34 != '\0' )
return - V_35 ;
* V_33 = V_6 ;
return 0 ;
}
* V_33 = F_23 ( V_31 , & V_34 ) ;
if ( * V_34 != '\0' )
return - V_35 ;
* V_33 = F_24 ( * V_33 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , int V_21 ,
const char * V_31 , T_6 V_36 )
{
char * V_34 ;
unsigned long V_15 ;
unsigned long long V_37 , * V_8 ;
if ( V_36 ) {
if ( V_36 ( V_31 , & V_37 ) )
return - V_35 ;
} else {
V_37 = F_22 ( V_31 , & V_34 , 10 ) ;
if ( * V_34 != '\0' )
return - V_35 ;
}
F_19 ( & V_2 -> V_4 , V_15 ) ;
V_8 = F_13 ( V_2 , V_21 ) ;
* V_8 = V_37 ;
F_20 ( & V_2 -> V_4 , V_15 ) ;
return 0 ;
}
