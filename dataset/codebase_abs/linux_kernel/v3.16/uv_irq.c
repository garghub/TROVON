static void F_1 ( struct V_1 * V_2 ) { }
static void F_2 ( struct V_1 * V_2 )
{
F_3 () ;
}
static int F_4 ( int V_3 , unsigned long V_4 , unsigned V_5 )
{
struct V_6 * * V_7 = & V_8 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_10 * V_11 ;
struct V_10 * V_12 ;
unsigned long V_13 ;
V_11 = F_5 ( sizeof( struct V_10 ) , V_14 ,
F_6 ( V_5 ) ) ;
if ( ! V_11 )
return - V_15 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_16 = F_7 ( V_5 ) ;
F_8 ( & V_17 , V_13 ) ;
while ( * V_7 ) {
V_9 = * V_7 ;
V_12 = F_9 ( V_9 , struct V_10 , V_18 ) ;
if ( F_10 ( V_3 == V_12 -> V_3 ) ) {
V_12 -> V_16 = F_7 ( V_5 ) ;
V_12 -> V_4 = V_4 ;
F_11 ( & V_17 , V_13 ) ;
F_12 ( V_11 ) ;
return 0 ;
}
if ( V_3 < V_12 -> V_3 )
V_7 = & ( * V_7 ) -> V_19 ;
else
V_7 = & ( * V_7 ) -> V_20 ;
}
F_13 ( & V_11 -> V_18 , V_9 , V_7 ) ;
F_14 ( & V_11 -> V_18 , & V_8 ) ;
F_11 ( & V_17 , V_13 ) ;
return 0 ;
}
int F_15 ( int V_3 , unsigned long * V_4 , int * V_16 )
{
struct V_10 * V_12 ;
struct V_6 * V_11 ;
unsigned long V_13 ;
F_8 ( & V_17 , V_13 ) ;
V_11 = V_8 . V_6 ;
while ( V_11 ) {
V_12 = F_9 ( V_11 , struct V_10 , V_18 ) ;
if ( V_12 -> V_3 == V_3 ) {
* V_4 = V_12 -> V_4 ;
* V_16 = V_12 -> V_16 ;
F_11 ( & V_17 , V_13 ) ;
return 0 ;
}
if ( V_3 < V_12 -> V_3 )
V_11 = V_11 -> V_19 ;
else
V_11 = V_11 -> V_20 ;
}
F_11 ( & V_17 , V_13 ) ;
return - 1 ;
}
static int
F_16 ( char * V_21 , unsigned int V_3 , int V_22 , int V_23 ,
unsigned long V_24 , int V_25 )
{
const struct V_26 * V_27 = F_17 ( V_22 ) ;
struct V_28 * V_29 = F_18 ( V_3 ) ;
unsigned long V_30 ;
struct V_31 * V_32 ;
int V_33 , V_34 ;
unsigned int V_35 ;
F_19 ( sizeof( struct V_31 ) !=
sizeof( unsigned long ) ) ;
V_34 = F_20 ( V_3 , V_29 , V_27 ) ;
if ( V_34 != 0 )
return V_34 ;
V_34 = V_36 -> V_37 ( V_27 , V_27 , & V_35 ) ;
if ( V_34 != 0 )
return V_34 ;
if ( V_25 == V_38 )
F_21 ( V_3 , V_39 ) ;
else
F_21 ( V_3 , V_40 ) ;
F_22 ( V_3 , & V_41 , V_42 ,
V_21 ) ;
V_30 = 0 ;
V_32 = (struct V_31 * ) & V_30 ;
V_32 -> V_43 = V_29 -> V_43 ;
V_32 -> V_44 = V_36 -> V_45 ;
V_32 -> V_46 = V_36 -> V_47 ;
V_32 -> V_48 = 0 ;
V_32 -> V_49 = 0 ;
V_32 -> V_50 = 0 ;
V_32 -> V_35 = V_35 ;
V_33 = F_7 ( V_23 ) ;
F_23 ( V_33 , V_24 , V_30 ) ;
if ( V_29 -> V_51 )
F_24 ( V_29 ) ;
return V_3 ;
}
static void F_25 ( int V_33 , unsigned long V_24 )
{
unsigned long V_30 ;
struct V_31 * V_32 ;
F_19 ( sizeof( struct V_31 ) !=
sizeof( unsigned long ) ) ;
V_30 = 0 ;
V_32 = (struct V_31 * ) & V_30 ;
V_32 -> V_50 = 1 ;
F_23 ( V_33 , V_24 , V_30 ) ;
}
static int
F_26 ( struct V_1 * V_2 , const struct V_26 * V_50 ,
bool V_52 )
{
struct V_28 * V_29 = V_2 -> V_53 ;
unsigned int V_35 ;
unsigned long V_30 , V_24 ;
struct V_31 * V_32 ;
int V_33 ;
if ( F_27 ( V_2 , V_50 , & V_35 ) )
return - 1 ;
V_30 = 0 ;
V_32 = (struct V_31 * ) & V_30 ;
V_32 -> V_43 = V_29 -> V_43 ;
V_32 -> V_44 = V_36 -> V_45 ;
V_32 -> V_46 = V_36 -> V_47 ;
V_32 -> V_48 = 0 ;
V_32 -> V_49 = 0 ;
V_32 -> V_50 = 0 ;
V_32 -> V_35 = V_35 ;
if ( F_15 ( V_2 -> V_3 , & V_24 , & V_33 ) )
return - 1 ;
F_23 ( V_33 , V_24 , V_30 ) ;
if ( V_29 -> V_51 )
F_24 ( V_29 ) ;
return V_54 ;
}
int F_28 ( char * V_21 , int V_22 , int V_23 ,
unsigned long V_24 , int V_25 )
{
int V_55 , V_3 = F_29 ( F_6 ( V_23 ) ) ;
if ( ! V_3 )
return - V_56 ;
V_55 = F_16 ( V_21 , V_3 , V_22 , V_23 , V_24 ,
V_25 ) ;
if ( V_55 == V_3 )
F_4 ( V_3 , V_24 , V_23 ) ;
else
F_30 ( V_3 ) ;
return V_55 ;
}
void F_31 ( unsigned int V_3 )
{
struct V_10 * V_12 ;
struct V_6 * V_11 ;
unsigned long V_13 ;
F_8 ( & V_17 , V_13 ) ;
V_11 = V_8 . V_6 ;
while ( V_11 ) {
V_12 = F_9 ( V_11 , struct V_10 , V_18 ) ;
if ( V_12 -> V_3 == V_3 ) {
F_25 ( V_12 -> V_16 , V_12 -> V_4 ) ;
F_32 ( V_11 , & V_8 ) ;
F_12 ( V_12 ) ;
break;
}
if ( V_3 < V_12 -> V_3 )
V_11 = V_11 -> V_19 ;
else
V_11 = V_11 -> V_20 ;
}
F_11 ( & V_17 , V_13 ) ;
F_30 ( V_3 ) ;
}
