static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
struct V_6 * V_7 ;
F_2 ( sizeof( struct V_6 ) !=
sizeof( unsigned long ) ) ;
V_5 = 0 ;
V_7 = (struct V_6 * ) & V_5 ;
V_7 -> V_8 = V_2 -> V_8 ;
V_7 -> V_9 = V_10 -> V_11 ;
V_7 -> V_12 = V_10 -> V_13 ;
V_7 -> V_14 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = V_2 -> V_18 ;
F_3 ( V_4 -> V_19 , V_4 -> V_20 , V_5 ) ;
}
static void F_4 ( struct V_21 * V_22 ) { }
static void F_5 ( struct V_21 * V_22 )
{
F_6 () ;
}
static int
F_7 ( struct V_21 * V_22 , const struct V_23 * V_16 ,
bool V_24 )
{
struct V_21 * V_25 = V_22 -> V_26 ;
struct V_1 * V_2 = F_8 ( V_22 ) ;
int V_27 ;
V_27 = V_25 -> V_28 -> V_29 ( V_25 , V_16 , V_24 ) ;
if ( V_27 >= 0 ) {
F_1 ( V_2 , V_22 -> V_30 ) ;
F_9 ( V_2 ) ;
}
return V_27 ;
}
static int F_10 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 , void * V_35 )
{
struct V_3 * V_30 ;
struct V_36 * V_4 = V_35 ;
struct V_21 * V_21 = F_11 ( V_32 , V_33 ) ;
int V_27 ;
if ( V_34 > 1 || ! V_4 || V_4 -> type != V_37 )
return - V_38 ;
V_30 = F_12 ( sizeof( * V_30 ) , V_39 ,
V_21 -> V_40 ) ;
if ( ! V_30 )
return - V_41 ;
V_27 = F_13 ( V_32 , V_33 , V_34 , V_35 ) ;
if ( V_27 >= 0 ) {
if ( V_4 -> V_42 == V_43 )
F_14 ( V_33 , V_44 ) ;
else
F_14 ( V_33 , V_45 ) ;
V_30 -> V_19 = F_15 ( V_4 -> V_46 ) ;
V_30 -> V_20 = V_4 -> V_47 ;
F_16 ( V_32 , V_33 , V_33 , & V_48 , V_30 ,
V_49 , NULL , V_4 -> V_50 ) ;
} else {
F_17 ( V_30 ) ;
}
return V_27 ;
}
static void F_18 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
struct V_21 * V_21 = F_11 ( V_32 , V_33 ) ;
F_19 ( V_34 != 1 ) ;
F_17 ( V_21 -> V_30 ) ;
F_20 ( V_33 , V_45 ) ;
F_20 ( V_33 , V_44 ) ;
F_21 ( V_32 , V_33 , V_34 ) ;
}
static void F_22 ( struct V_31 * V_32 ,
struct V_21 * V_21 )
{
F_1 ( F_8 ( V_21 ) , V_21 -> V_30 ) ;
}
static void F_23 ( struct V_31 * V_32 ,
struct V_21 * V_21 )
{
unsigned long V_5 ;
struct V_6 * V_7 ;
V_5 = 0 ;
V_7 = (struct V_6 * ) & V_5 ;
V_7 -> V_16 = 1 ;
F_1 ( F_8 ( V_21 ) , V_21 -> V_30 ) ;
}
static struct V_31 * F_24 ( void )
{
static struct V_31 * V_51 ;
static F_25 ( V_52 ) ;
F_26 ( & V_52 ) ;
if ( V_51 == NULL ) {
V_51 = F_27 ( NULL , & V_53 , NULL ) ;
if ( V_51 )
V_51 -> V_25 = V_54 ;
}
F_28 ( & V_52 ) ;
return V_51 ;
}
int F_29 ( char * V_55 , int V_56 , int V_57 ,
unsigned long V_58 , int V_59 )
{
struct V_36 V_4 ;
struct V_31 * V_32 = F_24 () ;
if ( ! V_32 )
return - V_41 ;
F_30 ( & V_4 , F_31 ( V_56 ) ) ;
V_4 . type = V_37 ;
V_4 . V_42 = V_59 ;
V_4 . V_46 = V_57 ;
V_4 . V_47 = V_58 ;
V_4 . V_50 = V_55 ;
return F_32 ( V_32 , 1 ,
F_33 ( V_57 ) , & V_4 ) ;
}
void F_34 ( unsigned int V_60 )
{
F_35 ( V_60 , 1 ) ;
}
