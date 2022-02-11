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
void F_8 ( struct V_1 * V_2 , unsigned long V_8 )
{
if ( F_10 ( V_2 -> V_9 < V_8 ) )
V_8 = V_2 -> V_9 ;
V_2 -> V_9 -= V_8 ;
}
void F_11 ( struct V_1 * V_2 , unsigned long V_8 )
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
F_12 ( struct V_1 * V_2 , int V_20 )
{
switch ( V_20 ) {
case V_21 :
return & V_2 -> V_9 ;
case V_22 :
return & V_2 -> V_12 ;
case V_23 :
return & V_2 -> V_5 ;
case V_24 :
return & V_2 -> V_10 ;
case V_25 :
return & V_2 -> V_7 ;
} ;
F_13 () ;
return NULL ;
}
T_1 F_14 ( struct V_1 * V_2 , int V_20 ,
const char T_2 * V_26 , T_3 V_27 , T_4 * V_28 ,
int (* F_15)( unsigned long long V_8 , char * V_29 ) )
{
unsigned long long * V_8 ;
char V_30 [ 64 ] , * V_31 ;
V_31 = V_30 ;
V_8 = F_12 ( V_2 , V_20 ) ;
if ( F_15 )
V_31 += F_15 ( * V_8 , V_31 ) ;
else
V_31 += sprintf ( V_31 , L_1 , * V_8 ) ;
return F_16 ( ( void T_2 * ) V_26 , V_27 ,
V_28 , V_30 , V_31 - V_30 ) ;
}
T_5 F_17 ( struct V_1 * V_2 , int V_20 )
{
unsigned long V_15 ;
T_5 V_14 ;
F_18 ( & V_2 -> V_4 , V_15 ) ;
V_14 = * F_12 ( V_2 , V_20 ) ;
F_19 ( & V_2 -> V_4 , V_15 ) ;
return V_14 ;
}
T_5 F_17 ( struct V_1 * V_2 , int V_20 )
{
return * F_12 ( V_2 , V_20 ) ;
}
int F_20 ( const char * V_30 ,
unsigned long long * V_32 )
{
char * V_33 ;
if ( * V_30 == '-' ) {
* V_32 = F_21 ( V_30 + 1 , & V_33 , 10 ) ;
if ( * V_32 != 1 || * V_33 != '\0' )
return - V_34 ;
* V_32 = V_6 ;
return 0 ;
}
* V_32 = F_22 ( ( char * ) V_30 , & V_33 ) ;
if ( * V_33 != '\0' )
return - V_34 ;
* V_32 = F_23 ( * V_32 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , int V_20 ,
const char * V_30 , T_6 V_35 )
{
char * V_33 ;
unsigned long V_15 ;
unsigned long long V_36 , * V_8 ;
if ( V_35 ) {
if ( V_35 ( V_30 , & V_36 ) )
return - V_34 ;
} else {
V_36 = F_21 ( V_30 , & V_33 , 10 ) ;
if ( * V_33 != '\0' )
return - V_34 ;
}
F_18 ( & V_2 -> V_4 , V_15 ) ;
V_8 = F_12 ( V_2 , V_20 ) ;
* V_8 = V_36 ;
F_19 ( & V_2 -> V_4 , V_15 ) ;
return 0 ;
}
