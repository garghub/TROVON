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
if ( F_26 ( V_18 -> V_21 ) ) {
F_27 ( & V_18 -> V_25 ) ;
V_11 = F_5 ( & V_18 -> V_21 , V_7 , V_8 , V_9 ,
V_10 ) ;
F_28 ( & V_18 -> V_25 ) ;
}
return V_11 ;
}
int F_29 ( struct V_22 * V_18 ,
unsigned long V_7 , void * V_8 )
{
return F_25 ( V_18 , V_7 , V_8 , - 1 , NULL ) ;
}
int F_30 ( struct V_26 * V_18 ,
struct V_1 * V_3 )
{
return F_1 ( & V_18 -> V_21 , V_3 ) ;
}
int F_31 ( struct V_26 * V_18 ,
struct V_1 * V_3 )
{
return F_4 ( & V_18 -> V_21 , V_3 ) ;
}
int F_32 ( struct V_26 * V_18 ,
unsigned long V_7 , void * V_8 ,
int V_9 , int * V_10 )
{
return F_5 ( & V_18 -> V_21 , V_7 , V_8 , V_9 , V_10 ) ;
}
int F_33 ( struct V_26 * V_18 ,
unsigned long V_7 , void * V_8 )
{
return F_32 ( V_18 , V_7 , V_8 , - 1 , NULL ) ;
}
int F_34 ( struct V_27 * V_18 ,
struct V_1 * V_3 )
{
int V_11 ;
if ( F_8 ( V_23 == V_24 ) )
return F_1 ( & V_18 -> V_21 , V_3 ) ;
F_35 ( & V_18 -> V_28 ) ;
V_11 = F_1 ( & V_18 -> V_21 , V_3 ) ;
F_36 ( & V_18 -> V_28 ) ;
return V_11 ;
}
int F_37 ( struct V_27 * V_18 ,
struct V_1 * V_3 )
{
int V_11 ;
if ( F_8 ( V_23 == V_24 ) )
return F_4 ( & V_18 -> V_21 , V_3 ) ;
F_35 ( & V_18 -> V_28 ) ;
V_11 = F_4 ( & V_18 -> V_21 , V_3 ) ;
F_36 ( & V_18 -> V_28 ) ;
F_38 ( & V_18 -> V_29 ) ;
return V_11 ;
}
int F_39 ( struct V_27 * V_18 ,
unsigned long V_7 , void * V_8 ,
int V_9 , int * V_10 )
{
int V_11 ;
int V_30 ;
V_30 = F_40 ( & V_18 -> V_29 ) ;
V_11 = F_5 ( & V_18 -> V_21 , V_7 , V_8 , V_9 , V_10 ) ;
F_41 ( & V_18 -> V_29 , V_30 ) ;
return V_11 ;
}
int F_42 ( struct V_27 * V_18 ,
unsigned long V_7 , void * V_8 )
{
return F_39 ( V_18 , V_7 , V_8 , - 1 , NULL ) ;
}
void F_43 ( struct V_27 * V_18 )
{
F_44 ( & V_18 -> V_28 ) ;
if ( F_45 ( & V_18 -> V_29 ) < 0 )
F_46 () ;
V_18 -> V_21 = NULL ;
}
int T_2 T_1 F_47 ( enum V_31 V_7 , const char * V_32 ,
struct V_33 * V_34 , long V_35 , int V_36 , int V_37 )
{
struct V_38 args = {
. V_34 = V_34 ,
. V_32 = V_32 ,
. V_35 = V_35 ,
. V_39 = V_36 ,
. V_40 = V_37 ,
} ;
return F_19 ( & V_41 , V_7 , & args ) ;
}
int F_48 ( struct V_1 * V_13 )
{
F_49 () ;
return F_11 ( & V_41 , V_13 ) ;
}
int F_50 ( struct V_1 * V_13 )
{
return F_14 ( & V_41 , V_13 ) ;
}
