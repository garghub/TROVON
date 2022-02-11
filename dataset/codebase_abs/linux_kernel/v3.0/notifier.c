static int F_1 ( struct V_1 * * V_2 ,
struct V_1 * V_3 )
{
while ( ( * V_2 ) != NULL ) {
if ( V_3 -> V_4 > ( * V_2 ) -> V_4 )
break;
V_2 = & ( ( * V_2 ) -> V_5 ) ;
}
V_3 -> V_5 = * V_2 ;
F_2 ( * V_2 , V_3 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * * V_2 ,
struct V_1 * V_3 )
{
while ( ( * V_2 ) != NULL ) {
if ( ( * V_2 ) == V_3 )
return 0 ;
if ( V_3 -> V_4 > ( * V_2 ) -> V_4 )
break;
V_2 = & ( ( * V_2 ) -> V_5 ) ;
}
V_3 -> V_5 = * V_2 ;
F_2 ( * V_2 , V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * * V_2 ,
struct V_1 * V_3 )
{
while ( ( * V_2 ) != NULL ) {
if ( ( * V_2 ) == V_3 ) {
F_2 ( * V_2 , V_3 -> V_5 ) ;
return 0 ;
}
V_2 = & ( ( * V_2 ) -> V_5 ) ;
}
return - V_6 ;
}
static int T_1 F_5 ( struct V_1 * * V_2 ,
unsigned long V_7 , void * V_8 ,
int V_9 , int * V_10 )
{
int V_11 = V_12 ;
struct V_1 * V_13 , * V_14 ;
V_13 = F_6 ( * V_2 ) ;
while ( V_13 && V_9 ) {
V_14 = F_6 ( V_13 -> V_5 ) ;
#ifdef F_7
if ( F_8 ( ! F_9 ( V_13 -> V_15 ) ) ) {
F_10 ( 1 , L_1 ) ;
V_13 = V_14 ;
continue;
}
#endif
V_11 = V_13 -> V_15 ( V_13 , V_7 , V_8 ) ;
if ( V_10 )
( * V_10 ) ++ ;
if ( ( V_11 & V_16 ) == V_16 )
break;
V_13 = V_14 ;
V_9 -- ;
}
return V_11 ;
}
int F_11 ( struct V_17 * V_18 ,
struct V_1 * V_3 )
{
unsigned long V_19 ;
int V_11 ;
F_12 ( & V_18 -> V_20 , V_19 ) ;
V_11 = F_1 ( & V_18 -> V_21 , V_3 ) ;
F_13 ( & V_18 -> V_20 , V_19 ) ;
return V_11 ;
}
int F_14 ( struct V_17 * V_18 ,
struct V_1 * V_3 )
{
unsigned long V_19 ;
int V_11 ;
F_12 ( & V_18 -> V_20 , V_19 ) ;
V_11 = F_4 ( & V_18 -> V_21 , V_3 ) ;
F_13 ( & V_18 -> V_20 , V_19 ) ;
F_15 () ;
return V_11 ;
}
int T_1 F_16 ( struct V_17 * V_18 ,
unsigned long V_7 , void * V_8 ,
int V_9 , int * V_10 )
{
int V_11 ;
F_17 () ;
V_11 = F_5 ( & V_18 -> V_21 , V_7 , V_8 , V_9 , V_10 ) ;
F_18 () ;
return V_11 ;
}
int T_1 F_19 ( struct V_17 * V_18 ,
unsigned long V_7 , void * V_8 )
{
return F_16 ( V_18 , V_7 , V_8 , - 1 , NULL ) ;
}
int F_20 ( struct V_22 * V_18 ,
struct V_1 * V_3 )
{
int V_11 ;
if ( F_8 ( V_23 == V_24 ) )
return F_1 ( & V_18 -> V_21 , V_3 ) ;
F_21 ( & V_18 -> V_25 ) ;
V_11 = F_1 ( & V_18 -> V_21 , V_3 ) ;
F_22 ( & V_18 -> V_25 ) ;
return V_11 ;
}
int F_23 ( struct V_22 * V_18 ,
struct V_1 * V_3 )
{
int V_11 ;
F_21 ( & V_18 -> V_25 ) ;
V_11 = F_3 ( & V_18 -> V_21 , V_3 ) ;
F_22 ( & V_18 -> V_25 ) ;
return V_11 ;
}
int F_24 ( struct V_22 * V_18 ,
struct V_1 * V_3 )
{
int V_11 ;
if ( F_8 ( V_23 == V_24 ) )
return F_4 ( & V_18 -> V_21 , V_3 ) ;
F_21 ( & V_18 -> V_25 ) ;
V_11 = F_4 ( & V_18 -> V_21 , V_3 ) ;
F_22 ( & V_18 -> V_25 ) ;
return V_11 ;
}
int F_25 ( struct V_22 * V_18 ,
unsigned long V_7 , void * V_8 ,
int V_9 , int * V_10 )
{
int V_11 = V_12 ;
if ( F_6 ( V_18 -> V_21 ) ) {
F_26 ( & V_18 -> V_25 ) ;
V_11 = F_5 ( & V_18 -> V_21 , V_7 , V_8 , V_9 ,
V_10 ) ;
F_27 ( & V_18 -> V_25 ) ;
}
return V_11 ;
}
int F_28 ( struct V_22 * V_18 ,
unsigned long V_7 , void * V_8 )
{
return F_25 ( V_18 , V_7 , V_8 , - 1 , NULL ) ;
}
int F_29 ( struct V_26 * V_18 ,
struct V_1 * V_3 )
{
return F_1 ( & V_18 -> V_21 , V_3 ) ;
}
int F_30 ( struct V_26 * V_18 ,
struct V_1 * V_3 )
{
return F_4 ( & V_18 -> V_21 , V_3 ) ;
}
int F_31 ( struct V_26 * V_18 ,
unsigned long V_7 , void * V_8 ,
int V_9 , int * V_10 )
{
return F_5 ( & V_18 -> V_21 , V_7 , V_8 , V_9 , V_10 ) ;
}
int F_32 ( struct V_26 * V_18 ,
unsigned long V_7 , void * V_8 )
{
return F_31 ( V_18 , V_7 , V_8 , - 1 , NULL ) ;
}
int F_33 ( struct V_27 * V_18 ,
struct V_1 * V_3 )
{
int V_11 ;
if ( F_8 ( V_23 == V_24 ) )
return F_1 ( & V_18 -> V_21 , V_3 ) ;
F_34 ( & V_18 -> V_28 ) ;
V_11 = F_1 ( & V_18 -> V_21 , V_3 ) ;
F_35 ( & V_18 -> V_28 ) ;
return V_11 ;
}
int F_36 ( struct V_27 * V_18 ,
struct V_1 * V_3 )
{
int V_11 ;
if ( F_8 ( V_23 == V_24 ) )
return F_4 ( & V_18 -> V_21 , V_3 ) ;
F_34 ( & V_18 -> V_28 ) ;
V_11 = F_4 ( & V_18 -> V_21 , V_3 ) ;
F_35 ( & V_18 -> V_28 ) ;
F_37 ( & V_18 -> V_29 ) ;
return V_11 ;
}
int F_38 ( struct V_27 * V_18 ,
unsigned long V_7 , void * V_8 ,
int V_9 , int * V_10 )
{
int V_11 ;
int V_30 ;
V_30 = F_39 ( & V_18 -> V_29 ) ;
V_11 = F_5 ( & V_18 -> V_21 , V_7 , V_8 , V_9 , V_10 ) ;
F_40 ( & V_18 -> V_29 , V_30 ) ;
return V_11 ;
}
int F_41 ( struct V_27 * V_18 ,
unsigned long V_7 , void * V_8 )
{
return F_38 ( V_18 , V_7 , V_8 , - 1 , NULL ) ;
}
void F_42 ( struct V_27 * V_18 )
{
F_43 ( & V_18 -> V_28 ) ;
if ( F_44 ( & V_18 -> V_29 ) < 0 )
F_45 () ;
V_18 -> V_21 = NULL ;
}
int F_46 ( struct V_1 * V_13 )
{
return F_20 ( & V_31 , V_13 ) ;
}
int F_47 ( struct V_1 * V_13 )
{
return F_24 ( & V_31 , V_13 ) ;
}
int T_2 T_1 F_48 ( enum V_32 V_7 , const char * V_33 ,
struct V_34 * V_35 , long V_36 , int V_37 , int V_38 )
{
struct V_39 args = {
. V_35 = V_35 ,
. V_33 = V_33 ,
. V_36 = V_36 ,
. V_40 = V_37 ,
. V_41 = V_38 ,
} ;
return F_19 ( & V_42 , V_7 , & args ) ;
}
int F_49 ( struct V_1 * V_13 )
{
F_50 () ;
return F_11 ( & V_42 , V_13 ) ;
}
int F_51 ( struct V_1 * V_13 )
{
return F_14 ( & V_42 , V_13 ) ;
}
